// -*-  mode: c    ; coding: koi8   -*- ----------------------------------------

/* emgena: play_test.c */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>
#include <ctype.h>
#include <signal.h>
#include <math.h>


#ifdef HAVE_UNISTD_H
#include <unistd.h>
#else
#include <io.h>
#endif    

#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif


#include "sgf.h"
#include "gtp.h"
#include "gmp.h"
#include "common.h"
#include "engine.h"
/* #include "move_reasons.h"  */
/* emgena */


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* ================================================================ */
/* #include "interface.h" */
/* ================================================================ */
/* emgena: interface.h */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * This is GNU GO, a Go program. Contact gnugo@gnu.org, or see       *
 * http://www.gnu.org/software/gnugo/ for more information.          *
 *                                                                   *
 * Copyright 1999, 2000, 2001, 2002 by the Free Software Foundation. *
 *                                                                   *
 * This program is free software; you can redistribute it and/or     *
 * modify it under the terms of the GNU General Public License as    *
 * published by the Free Software Foundation - version 2             *
 *                                                                   *
 * This program is distributed in the hope that it will be useful,   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of    *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     *
 * GNU General Public License in file COPYING for more details.      *
 *                                                                   *
 * You should have received a copy of the GNU General Public         *
 * License along with this program; if not, write to the Free        *
 * Software Foundation, Inc., 59 Temple Place - Suite 330,           *
 * Boston, MA 02111, USA.                                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*-------------------------------------------------------------------------
 * interface.h
 * 	This file contains all headers for interfaces
 *-------------------------------------------------------------------------*/

#ifndef _PLAY_INTERFACE_H
#define _PLAY_INTERFACE_H

/* #include "gnugo.h" */
/* #include "sgf.h" */

void play_ascii(SGFTree *tree, Gameinfo *gameinfo, 
		char *filename, char *until);
void play_ascii_emacs(SGFTree *tree, Gameinfo *gameinfo, 
		      char *filename, char *until);
void play_gtp(FILE *gtp_input, int gtp_initial_orientation);
void play_gmp(Gameinfo *gameinfo);
void play_solo(Gameinfo *gameinfo, int benchmark);
void play_replay(SGFNode *sgf_head, int color_to_test);

void load_and_analyze_sgf_file(Gameinfo *gameinfo, int benchmark);
void load_and_score_sgf_file(SGFTree *tree, Gameinfo *gameinfo,
			     const char *scoringmode);


#endif
/* ================================================================== */



static void replay_node(SGFNode *node, int color_to_test);


/* --------------------------------------------------------------*/
/* replay a game */
/* --------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
void
play_replay(SGFNode *sgf_head, int color_to_replay)
{
  Gameinfo  gameinfo;
  int tmpi;
  float tmpf;
  char *tmpc = NULL;

  SGFNode *node;

  /* Get the board size. */
  if (!sgfGetIntProperty(sgf_head, "SZ", &tmpi)) {
    fprintf(stderr, "Couldn't find the size (SZ) attribute!\n");
    exit(EXIT_FAILURE);
  }
  gameinfo_clear(&gameinfo, tmpi, 5.5);
   
  /* Get the number of handicap stones. */
  if (sgfGetIntProperty(sgf_head, "HA", &tmpi)) {
    /* Handicap stones should appear as AW,AB properties in the sgf file. */
    gameinfo.handicap = tmpi;
  }

  /* Get the komi. */
  if (sgfGetFloatProperty(sgf_head, "KM", &tmpf))
    komi = tmpf;

  if (!quiet) {
    if (sgfGetCharProperty(sgf_head, "RU", &tmpc))
      printf("Ruleset:      %s\n", tmpc);
    if (sgfGetCharProperty(sgf_head, "GN", &tmpc))
      printf("Game Name:    %s\n", tmpc);
    if (sgfGetCharProperty(sgf_head, "DT", &tmpc))
      printf("Game Date:    %s\n", tmpc);
    if (sgfGetCharProperty(sgf_head, "GC", &tmpc))
      printf("Game Comment: %s\n", tmpc);
    if (sgfGetCharProperty(sgf_head, "US", &tmpc))
      printf("Game User:    %s\n", tmpc);
    if (sgfGetCharProperty(sgf_head, "PB", &tmpc))
      printf("Black Player: %s\n", tmpc);
    if (sgfGetCharProperty(sgf_head, "PW", &tmpc))
      printf("White Player: %s\n", tmpc);

    gameinfo_print(&gameinfo);
  }

  sgffile_write_gameinfo(&gameinfo, "replay game");         
   
  /*
   * Now actually run through the file.  This is the interesting part.
   * We need to traverse the SGF tree, and every time we encounter a node
   * we need to check what move GNU Go would make, and see if it is OK. 
   */
  node = sgf_head;
  while (node) {
    replay_node(node, color_to_replay);
    node = node->child;
  }

   sgffile_close_file();
}



/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*
 * Handle this node.
 */

static void
replay_node(SGFNode *node, int color_to_replay)
{
  SGFProperty *sgf_prop;  /* iterate over properties of the node */
  SGFProperty *move_prop = NULL; /* remember if we see a move property */
  int color; /* color of move to be made at this node. */
  
  int boardsize = gnugo_get_boardsize();
  int m, n; /* Move from file. */
  int i, j; /* Move generated by GNU Go. */

  /* Handle any AB / AW properties, and note presence
   * of move properties.
   */

  for (sgf_prop = node->props; sgf_prop; sgf_prop = sgf_prop->next) {
    switch (sgf_prop->name) {
    case SGFAB:
      /* add black */
      gnugo_add_stone(get_moveX(sgf_prop, boardsize),
		      get_moveY(sgf_prop, boardsize), BLACK);
      sgffile_put_stone(get_moveX(sgf_prop, boardsize),
			get_moveY(sgf_prop, boardsize), BLACK);
      break;
    case SGFAW:
      /* add white */
      gnugo_add_stone(get_moveX(sgf_prop, boardsize),
		      get_moveY(sgf_prop, boardsize), WHITE);
      sgffile_put_stone(get_moveX(sgf_prop, boardsize),
			get_moveY(sgf_prop, boardsize), WHITE);
      break;
    case SGFB:
    case SGFW:
      move_prop = sgf_prop;  /* remember it for later */
      break;
    }
  }

  /* Only generate moves at move nodes. */
  if (!move_prop)
    return;

  m = get_moveX(move_prop, boardsize);
  n = get_moveY(move_prop, boardsize);
  color = (move_prop->name == SGFW) ? WHITE : BLACK;

  if (color == color_to_replay || color_to_replay == GRAY) {
    /* Get a move from the engine for color. */
    gnugo_genmove(&i, &j, color);
    /* Now report on how well the computer generated the move. */
    if (i != m || j != n || !quiet) {
      mprintf("Move %d (%C): ", movenum + 1, color);
    
      mprintf("GNU Go plays %m ", i, j);
      if (!gnugo_is_pass(i, j))
	printf("(%.2f) ", potential_moves[i][j]);
      mprintf("- Game move %m ", m, n);
      if (!gnugo_is_pass(m, n) && potential_moves[m][n] > 0.0)
	printf("(%.2f) ", potential_moves[m][n]);
      printf("\n");
    }
    if (i != m || j != n) {
      char buf[127];
      gg_snprintf(buf, 127, "GNU Go plays %s(%.2f) - Game move %s(%.2f)",
	location_to_string(POS(i,j)),
	gnugo_is_pass(i, j) ? 0 : potential_moves[i][j],
	location_to_string(POS(m,n)),
        gnugo_is_pass(m, n) && potential_moves[m][n] < 0.0 ? 0 : potential_moves[m][n]);
      sgffile_write_comment(buf);
      sgffile_write_circle_mark(i,j);
    }
  }

  /* Finally, do play the move from the file. */
  gnugo_play_move(m, n, color);
  sgffile_move_made(m, n, color, 0);
}


/*
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 2
 * End:
 */

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* play_solo.c */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
void
play_solo (Gameinfo *gameinfo, int moves)
{
  int passes = 0; /* num. consecutive passes */
  int move_val;
  double t1, t2;
  int save_moves = moves;
  int boardsize = gnugo_get_boardsize();

  struct stats_data totalstats;
  int total_owl_count = 0;

  /* It tends not to be very imaginative in the opening,
   * so we scatter a few stones randomly to start with.
   * We add two random numbers to reduce the probability
   * of playing stones near the edge.
   */
  
  int n = 6 + 2*gg_rand()%5;
  int i, j;

  sgffile_write_gameinfo(gameinfo, "solo");
 
  /* Generate some random moves. */
  if (boardsize > 6) {
    do {
      do {
	i = (gg_rand() % 4) + (gg_rand() % (boardsize - 4));
	j = (gg_rand() % 4) + (gg_rand() % (boardsize - 4));
      } while (!gnugo_is_legal(i, j, gameinfo->to_move));
      
      gameinfo_play_move(gameinfo, i, j, gameinfo->to_move);
    } while (--n > 0);
  }
  
  t1 = gg_cputime();
  memset(&totalstats, '\0', sizeof(totalstats));
 
 while (passes < 2 && --moves >= 0 && !time_to_die) {
    reset_owl_node_counter();
    move_val = gnugo_genmove (&i, &j, gameinfo->to_move);
    gameinfo_play_move (gameinfo, i, j, gameinfo->to_move);

    if (move_val < 0) {
      ++passes;
      printf("%s(%d): Pass\n", gameinfo->to_move == BLACK ? "Black" : "White",
	     movenum);
    }
    else {
      passes = 0;
      gprintf("%s(%d): %m\n", gameinfo->to_move == BLACK ? "Black" : "White",
	      movenum, i, j);
    }

    totalstats.nodes               += stats.nodes;
    totalstats.position_entered    += stats.position_entered;
    totalstats.position_hits       += stats.position_hits;
    totalstats.read_result_entered += stats.read_result_entered;
    totalstats.hash_collisions     += stats.hash_collisions;
    total_owl_count                += get_owl_node_counter();
  }
  t2 = gg_cputime();
  
  /* Two passes and it's over. (EMPTY == BOTH) */
  gnugo_who_wins (EMPTY, stdout);

#if 0
  if (t2 == t1)
    printf("%.3f moves played\n", (double) (save_moves-moves));
  else
    printf("%.3f moves/sec\n", (save_moves-moves)/(t2-t1));
#else
  printf("%10d moves played in %0.3f seconds\n", save_moves-moves, t2-t1);
  if (save_moves != moves)
    printf("%10.3f seconds/move\n", (t2-t1)/(save_moves-moves));
  printf("%10d nodes\n", totalstats.nodes);
  printf("%10d positions entered\n", totalstats.position_entered);
  printf("%10d position hits\n", totalstats.position_hits);
  printf("%10d read results entered\n", totalstats.read_result_entered);
  printf("%10d hash collisions\n", totalstats.hash_collisions);
  printf("%10d owl nodes\n", total_owl_count);
#endif
}


/* ================================================================ */


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* FIXME: This should be in a separate source file.
 */


/*
 * Load SGF file and run genmove().
 */

void 
load_and_analyze_sgf_file(Gameinfo *gameinfo, int benchmark)
{
  int i, j;
  int next;
  int r;
  
  next = gameinfo->to_move;
  gameinfo->computer_player = next;
  sgffile_write_gameinfo(gameinfo, "load and analyze");

  if (benchmark) {
    for (r = 0; r < benchmark; ++r) {
      genmove(&i, &j, next);
      next = OTHER_COLOR(next);
    }
  }
  else {
    genmove(&i, &j, next);
    
    if (is_pass(POS(i, j))) {
      gprintf("%s move: PASS!\n", next == WHITE ? "white (O)" : "black (X)");
      sgffile_move_made(i, j, next, 0);
    }
    else {
      gprintf("%s move %m\n", next == WHITE ? "white (O)" : "black (X)",
	      i, j);
      gnugo_play_move(i, j, next);
      sgffile_move_made(i, j, next, 0);
    }
  }
}


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*
 * Load SGF file and score the game
 * scoringmode:
 * estimate  - estimate territorial balance
 * finish    - finish the game by selfplaying and then count the score quickly
 * aftermath - like 'finish' but also play out the aftermath in order to
 *             get an accurate score
 */

void 
load_and_score_sgf_file(SGFTree *tree, Gameinfo *gameinfo, 
			const char *scoringmode)
{
  int i, j, move_val;
  int until;
  float result;
  char *tempc = NULL;
  char dummy;
  char text[250];
  char winner;
  int next;
  int pass = 0;
  SGFTree score_tree;
  SGFNode *node;
  
  sgftree_clear(&score_tree);
  node = sgftreeCreateHeaderNode(&score_tree, board_size, komi);
  sgftreeSetLastNode(&score_tree, node);
  sgftree_printboard(&score_tree);
  
  sgffile_write_gameinfo(gameinfo, "load and score");
  next = gameinfo->to_move;
  sgffile_printboard(next);
  doing_scoring = 1;
  reset_engine();
  
  if (!strcmp(scoringmode, "finish") || !strcmp(scoringmode, "aftermath")) {
    until = 9999;
    do {
      move_val = genmove_conservative(&i, &j, next);
      if (move_val >= 0) {
	pass = 0;
	gprintf("%d %s move %m\n", movenum,
		next == WHITE ? "white (O)" : "black (X)", i, j);
      }
      else {
	++pass;
	gprintf("%d %s move : PASS!\n", movenum, 
		next == WHITE ? "white (O)" : "black (X)");
      }
      play_move(POS(i, j), next);
      sgffile_move_made(i, j, next, move_val);
      sgftreeAddPlay(&score_tree, NULL, next, i, j);
      next = OTHER_COLOR(next);
    } while (movenum <= until && pass < 2);

    if (pass >= 2) {
      node = score_tree.lastnode;
      /* Calculate the score */
      if (!strcmp(scoringmode, "aftermath"))
	score = aftermath_compute_score(next, komi, &score_tree);
      else
	score = gnugo_estimate_score(&lower_bound, &upper_bound);

      if (score < 0.0) {
	sprintf(text, "Black wins by %1.1f points\n", -score);
	winner = 'B';
      }
      else if (score > 0.0) {
	sprintf(text, "White wins by %1.1f points\n", score);
	winner = 'W';
      }
      else {
	sprintf(text, "Jigo\n");
	winner = '0';
      }
      fputs(text, stdout);
      sgfAddComment(node, text);
      sgffile_write_comment(text);
      if (sgfGetCharProperty(tree->root, "RE", &tempc)) {
	if (sscanf(tempc, "%1c%f", &dummy, &result) == 2) {
	  fprintf(stdout, "Result from file: %1.1f\n", result);
	  fputs("GNU Go result and result from file are ", stdout);
	  if (result == fabs(score) && winner == dummy)
	    fputs("identical\n", stdout);
	  else
	    fputs("different\n", stdout);
	      
	}
	else {
	  if (tempc[2] == 'R') {
	    fprintf(stdout, "Result from file: Resign\n");
	    fputs("GNU Go result and result from file are ", stdout);
	    if (tempc[0] == winner)
	      fputs("identical\n", stdout);
	    else
	      fputs("different\n", stdout);
	  }
	}
      }
      sgfWriteResult(score_tree.root, score, 1);
    }
  }
  doing_scoring = 0;


  if (!strcmp(scoringmode, "aftermath")) {
    if (gameinfo->outfile)
      writesgf(score_tree.root, gameinfo->outfilename);
    return;
  }

  /* Before we call estimate_score() we must make sure that the dragon
   * status is computed. Therefore the call to examine_position().
   */
  examine_position(next, EXAMINE_ALL);
  score = estimate_score(NULL, NULL);

  fprintf(stdout, "\n%s seems to win by %1.1f points\n",
	  score < 0 ? "B" : "W",
	  score < 0 ? -score : score);
}


/*
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 2
 * End:
 */

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* play_gtp.c */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * This is GNU GO, a Go program. Contact gnugo@gnu.org, or see       *
 * http://www.gnu.org/software/gnugo/ for more information.          *
 *                                                                   *
 * Copyright 1999, 2000, 2001, 2002 by the Free Software Foundation. *
 *                                                                   *
 * This program is free software; you can redistribute it and/or     *
 * modify it under the terms of the GNU General Public License as    *
 * published by the Free Software Foundation - version 2             *
 *                                                                   *
 * This program is distributed in the hope that it will be useful,   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of    *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     *
 * GNU General Public License in file COPYING for more details.      *
 *                                                                   *
 * You should have received a copy of the GNU General Public         *
 * License along with this program; if not, write to the Free        *
 * Software Foundation, Inc., 59 Temple Place - Suite 330,           *
 * Boston, MA 02111, USA.                                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define HAVE_CONFIG_H 1


/* Internal state that's not part of the engine. */
int handicap;

static int report_uncertainty = 0;
static int gtp_orientation = 0;

static void
print_influence(float white_influence[BOARDMAX],
		float black_influence[BOARDMAX],
		int influence_regions[BOARDMAX]);
static void gtp_print_code(int c);
static void gtp_print_vertices2(int n, int *moves);
static void rotate_on_input(int ai, int aj, int *bi, int *bj);
static void rotate_on_output(int ai, int aj, int *bi, int *bj);


#define DECLARE(func) static int func(char *s, int id)

DECLARE(gtp_aa_confirm_safety);
DECLARE(gtp_all_legal);
DECLARE(gtp_attack);
DECLARE(gtp_combination_attack);
DECLARE(gtp_connect);
DECLARE(gtp_countlib);
DECLARE(gtp_cputime);
DECLARE(gtp_decrease_depths);
DECLARE(gtp_defend);
DECLARE(gtp_disconnect);
DECLARE(gtp_dragon_data);
DECLARE(gtp_dragon_status);
DECLARE(gtp_dragon_stones);
DECLARE(gtp_dump_stack);
DECLARE(gtp_echo);
DECLARE(gtp_echo_err);
DECLARE(gtp_eval_eye);
DECLARE(gtp_final_score);
DECLARE(gtp_final_status);
DECLARE(gtp_final_status_list);
DECLARE(gtp_findlib);
DECLARE(gtp_finish_sgftrace);
DECLARE(gtp_fixed_handicap);
DECLARE(gtp_get_handicap);
DECLARE(gtp_get_random_seed);
DECLARE(gtp_set_random_seed);
DECLARE(gtp_genmove);
DECLARE(gtp_genmove_black);
DECLARE(gtp_genmove_white);
DECLARE(gtp_get_connection_node_counter);
DECLARE(gtp_get_life_node_counter);
DECLARE(gtp_get_owl_node_counter);
DECLARE(gtp_get_reading_node_counter);
DECLARE(gtp_get_trymove_counter);
DECLARE(gtp_help);
DECLARE(gtp_increase_depths);
DECLARE(gtp_influence);
DECLARE(gtp_is_legal);
DECLARE(gtp_ladder_attack);
DECLARE(gtp_list_stones);
DECLARE(gtp_loadsgf);
DECLARE(gtp_name);
DECLARE(gtp_new_game);
DECLARE(gtp_estimate_score);
DECLARE(gtp_owl_analyze_semeai);
DECLARE(gtp_tactical_analyze_semeai);
DECLARE(gtp_owl_attack);
DECLARE(gtp_owl_connection_defends);
DECLARE(gtp_owl_defend);
DECLARE(gtp_owl_does_attack);
DECLARE(gtp_owl_does_defend);
DECLARE(gtp_owl_substantial);
DECLARE(gtp_owl_threaten_attack);
DECLARE(gtp_owl_threaten_defense);
DECLARE(gtp_playblack);
DECLARE(gtp_playwhite);
DECLARE(gtp_popgo);
DECLARE(gtp_captures);
DECLARE(gtp_protocol_version);
DECLARE(gtp_query_boardsize);
DECLARE(gtp_query_orientation);
DECLARE(gtp_quit);
DECLARE(gtp_report_uncertainty);
DECLARE(gtp_reset_connection_node_counter);
DECLARE(gtp_reset_life_node_counter);
DECLARE(gtp_reset_owl_node_counter);
DECLARE(gtp_reset_reading_node_counter);
DECLARE(gtp_reset_trymove_counter);
DECLARE(gtp_same_dragon);
DECLARE(gtp_set_boardsize);
DECLARE(gtp_set_orientation);
DECLARE(gtp_set_komi);
DECLARE(gtp_get_komi);
DECLARE(gtp_set_level);
DECLARE(gtp_showboard);
DECLARE(gtp_start_sgftrace);
DECLARE(gtp_test_eyeshape);
DECLARE(gtp_top_moves);
DECLARE(gtp_top_moves_white);
DECLARE(gtp_top_moves_black);
DECLARE(gtp_trymove);
DECLARE(gtp_tryko);
DECLARE(gtp_tune_move_ordering);
DECLARE(gtp_undo);
DECLARE(gtp_version);
DECLARE(gtp_what_color);
DECLARE(gtp_worm_cutstone);
DECLARE(gtp_worm_data);
DECLARE(gtp_worm_stones);

/* List of known commands. */
static struct gtp_command commands[] = {
  {"aa_confirm_safety",       gtp_aa_confirm_safety},
  {"all_legal",        	      gtp_all_legal},
  {"attack",           	      gtp_attack},
  {"black",            	      gtp_playblack},
  {"boardsize",        	      gtp_set_boardsize},
  {"captures",        	      gtp_captures},
  {"color",            	      gtp_what_color},
  {"combination_attack",      gtp_combination_attack},
  {"connect",         	      gtp_connect},
  {"countlib",         	      gtp_countlib},
  {"cputime",		      gtp_cputime},
  {"decrease_depths",  	      gtp_decrease_depths},
  {"defend",           	      gtp_defend},
  {"disconnect",       	      gtp_disconnect},
  {"dragon_data",             gtp_dragon_data},
  {"dragon_status",    	      gtp_dragon_status},
  {"dragon_stones",           gtp_dragon_stones},
  {"dump_stack",       	      gtp_dump_stack},
  {"echo" ,                   gtp_echo},
  {"echo_err" ,               gtp_echo_err},
  {"estimate_score",          gtp_estimate_score},
  {"eval_eye",         	      gtp_eval_eye},
  {"final_score",             gtp_final_score},
  {"final_status",            gtp_final_status},
  {"final_status_list",       gtp_final_status_list},
  {"findlib",          	      gtp_findlib},
  {"finish_sgftrace",  	      gtp_finish_sgftrace},
  {"fixed_handicap",   	      gtp_fixed_handicap},
  {"get_handicap",   	      gtp_get_handicap},
  {"get_random_seed",  	      gtp_get_random_seed},
  {"set_random_seed",  	      gtp_set_random_seed},
  {"genmove_black",           gtp_genmove_black},
  {"genmove_white",           gtp_genmove_white},
  {"get_connection_node_counter", gtp_get_connection_node_counter},
  {"get_life_node_counter",   gtp_get_life_node_counter},
  {"get_owl_node_counter",    gtp_get_owl_node_counter},
  {"get_reading_node_counter",gtp_get_reading_node_counter},
  {"get_trymove_counter",     gtp_get_trymove_counter},
  {"gg_genmove",              gtp_genmove},
  {"help",                    gtp_help},
  {"increase_depths",  	      gtp_increase_depths},
  {"influence",               gtp_influence},
  {"is_legal",         	      gtp_is_legal},
  {"komi",        	      gtp_set_komi},
  {"get_komi",        	      gtp_get_komi},
  {"ladder_attack",    	      gtp_ladder_attack},
  {"level",        	      gtp_set_level},
  {"list_stones",    	      gtp_list_stones},
  {"loadsgf",          	      gtp_loadsgf},
  {"name",                    gtp_name},
  {"new_game",                gtp_new_game},
  {"new_score",               gtp_estimate_score},
  {"owl_analyze_semeai",      gtp_owl_analyze_semeai},
  {"tactical_analyze_semeai", gtp_tactical_analyze_semeai},
  {"owl_attack",     	      gtp_owl_attack},
  {"owl_connection_defends",  gtp_owl_connection_defends},
  {"owl_defend",     	      gtp_owl_defend},
  {"owl_does_attack", 	      gtp_owl_does_attack},
  {"owl_does_defend", 	      gtp_owl_does_defend},
  {"owl_substantial", 	      gtp_owl_substantial},
  {"owl_threaten_attack",     gtp_owl_threaten_attack},
  {"owl_threaten_defense",    gtp_owl_threaten_defense},
  {"popgo",            	      gtp_popgo},
  {"orientation",     	      gtp_set_orientation},
  {"protocol_version",        gtp_protocol_version},
  {"query_boardsize",         gtp_query_boardsize},
  {"query_orientation",       gtp_query_orientation},
  {"quit",             	      gtp_quit},
  {"report_uncertainty",      gtp_report_uncertainty},
  {"reset_connection_node_counter", gtp_reset_connection_node_counter},
  {"reset_life_node_counter", gtp_reset_life_node_counter},
  {"reset_owl_node_counter",  gtp_reset_owl_node_counter},
  {"reset_reading_node_counter", gtp_reset_reading_node_counter},
  {"reset_trymove_counter",   gtp_reset_trymove_counter},
  {"same_dragon",    	      gtp_same_dragon},
  {"showboard",        	      gtp_showboard},
  {"start_sgftrace",  	      gtp_start_sgftrace},
  {"test_eyeshape",           gtp_test_eyeshape},
  {"top_moves",               gtp_top_moves},
  {"top_moves_black",         gtp_top_moves_black},
  {"top_moves_white",         gtp_top_moves_white},
  {"trymove",          	      gtp_trymove},
  {"tryko",          	      gtp_tryko},
  {"tune_move_ordering",      gtp_tune_move_ordering},
  {"undo",                    gtp_undo},
  {"version",                 gtp_version},
  {"white",            	      gtp_playwhite},
  {"worm_cutstone",           gtp_worm_cutstone},
  {"worm_data",               gtp_worm_data},
  {"worm_stones",             gtp_worm_stones},
  {NULL,                      NULL}
};


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Start playing using the Go Text Protocol. */
void
play_gtp (FILE *gtp_input, int gtp_initial_orientation)
{
/* emgena */
#undef HAVE_SETLINEBUF
/* emgena */

  /* Try to make sure that we have a useful level of buffering of stdout. */
#ifdef HAVE_SETLINEBUF
  setlinebuf(stdout);
#else
  setbuf(stdout, NULL);
#endif

  /* Inform the GTP utility functions about the board size. */
  gtp_internal_set_boardsize (board_size);
  gtp_orientation = gtp_initial_orientation;
  gtp_set_vertex_transform_hooks (rotate_on_input, rotate_on_output);
  
  /* Prepare pattern matcher and reading code. */
  reset_engine ();
  gtp_main_loop (commands, gtp_input);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/


/****************************
 * Administrative commands. *
 ****************************/


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Quit
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_quit(char *s, int id)
{
  UNUSED(s);
  gtp_success(id, "");

  return GTP_QUIT;
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Report protocol version.
 * Arguments: none
 * Fails:     never
 * Returns:   protocol version number
 */
static int
gtp_protocol_version(char *s, int id)
{
  UNUSED(s);

  return gtp_success(id, "1");
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Start a new game
 * Arguments: none
 * Fails:     always
 * Returns:   nothing
 */
static int
gtp_new_game(char *s, int id)
{
  UNUSED(s);

  return (gtp_failure (id, "not implemented"));
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/


/****************************
 * Program identity.        *
 ****************************/


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Report the name of the program.
 * Arguments: none
 * Fails:     never
 * Returns:   program name
 */
static int
gtp_name(char *s, int id)
{
  UNUSED(s);
  return gtp_success(id, "GNU Go");
}




/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Report the version number of the program.
 * Arguments: none
 * Fails:     never
 * Returns:   version number
 */
static int
gtp_version(char *s, int id)
{
  UNUSED(s);
  return gtp_success(id, VERSION);
}


/***************************
 * Setting the board size. *
 ***************************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Set the board size to NxN and clear the board.
 * Arguments: integer
 * Fails:     board size outside engine's limits
 * Returns:   nothing
 */
static int
gtp_set_boardsize(char *s, int id)
{
  int boardsize;
  int pos;

  if (sscanf(s, "%d", &boardsize) < 1)
    return gtp_failure(id, "boardsize not an integer");
  
  if (boardsize < MIN_BOARD || boardsize > MAX_BOARD)
    return gtp_failure(id, "unacceptable boardsize");

  /* If this is called with a non-empty board, we assume that a new
   * game will be started, for which we want a new random seed.
   */
  for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
    if (ON_BOARD(pos) && board[pos] != EMPTY) {
      update_random_seed();
      break;
    }
  }

  board_size = boardsize;
  clear_board();
  gtp_internal_set_boardsize(boardsize);
  reset_engine();
  return gtp_success(id, "");
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Find the current boardsize
 * Arguments: none
 * Fails:     never
 * Returns:   board_size
 */
static int
gtp_query_boardsize(char *s, int id)
{
  UNUSED(s);

  return gtp_success(id, "%d", board_size);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/****************************
 * Setting the orientation. *
 ****************************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Set the orienation to N and clear the board
 * Arguments: integer
 * Fails:     illegal orientation
 * Returns:   nothing
 */
static int
gtp_set_orientation(char *s, int id)
{
  int orientation;
  if (sscanf(s, "%d", &orientation) < 1)
    return gtp_failure(id, "orientation not an integer");
  
  if (orientation < 0 || orientation > 7)
    return gtp_failure(id, "unacceptable orientation");

  clear_board();
  gtp_orientation = orientation;
  gtp_set_vertex_transform_hooks(rotate_on_input, rotate_on_output);
  return gtp_success(id, "");
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Find the current orientation
 * Arguments: none
 * Fails:     never
 * Returns:   orientation
 */
static int
gtp_query_orientation(char *s, int id)
{
  UNUSED(s);

  return gtp_success(id, "%d", gtp_orientation);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/***************************
 * Setting komi.           *
 ***************************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Set the komi.
 * Arguments: float
 * Fails:     incorrect argument
 * Returns:   nothing
 */
static int
gtp_set_komi(char *s, int id)
{
  if (sscanf(s, "%f", &komi) < 1)
    return gtp_failure(id, "komi not a float");
  
  return gtp_success(id, "");
}


/***************************
 * Getting komi            *
 ***************************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Get the komi
 * Arguments: none
 * Fails:     never
 * Returns:   Komi 
 */
static int
gtp_get_komi(char *s, int id)
{
  UNUSED(s);
  return gtp_success(id, "%4.1f", komi);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/


/******************
 * Playing moves. *
 ******************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Play a black stone at the given vertex.
 * Arguments: vertex
 * Fails:     invalid vertex, illegal move
 * Returns:   nothing
 */
static int
gtp_playblack(char *s, int id)
{
  int i, j;
  char *c;

  for (c = s; *c; c++)
    *c = tolower((int)*c);

  if (strncmp(s, "pass", 4) == 0) {
    i = -1;
    j = -1;
  }
  else if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (!is_legal(POS(i, j), BLACK))
    return gtp_failure(id, "illegal move");

  play_move(POS(i, j), BLACK);
  return gtp_success(id, "");
}


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Play a white stone at the given vertex.
 * Arguments: vertex
 * Fails:     invalid vertex, illegal move
 * Returns:   nothing
 */
static int
gtp_playwhite(char *s, int id)
{
  int i, j;
  char *c;

  for (c = s; *c; c++)
    *c = tolower((int)*c);

  if (strncmp(s, "pass", 4) == 0) {
    i = -1;
    j = -1;
  }
  else if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");
  
  if (!is_legal(POS(i, j), WHITE))
    return gtp_failure(id, "illegal move");

  play_move(POS(i, j), WHITE);
  return gtp_success(id, "");
}


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Set up fixed placement handicap stones.
 * Arguments: number of handicap stones
 * Fails:     invalid number of stones for the current boardsize
 * Returns:   list of vertices with handicap stones
 */
static int
gtp_fixed_handicap (char *s, int id)
{
  int m, n;
  int first = 1;
  int handicap;
  if (sscanf(s, "%d", &handicap) < 1)
    return gtp_failure (id, "handicap not an integer");
  
  clear_board ();
  if (placehand (handicap) != handicap)
    return gtp_failure(id, "invalid handicap");

  gtp_printid (id, GTP_SUCCESS);

  for (m = 0; m < board_size; m++)
  for (n = 0; n < board_size; n++)
    if (BOARD(m, n) != EMPTY) {
      if (!first)
        gtp_printf (" ");
      else
        first = 0;
      gtp_mprintf ("%m", m, n);
    }
  
  return (gtp_finish_response());
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Get the handicap
 * Arguments: none
 * Fails:     never
 * Returns:   handicap
 */
static int
gtp_get_handicap (char *s, int id)
{
  UNUSED(s);
  return gtp_success(id, "%d", handicap);
}


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Load an sgf file, possibly up to a move number or the first
 *            occurence of a move.           
 * Arguments: filename + move number, vertex, or nothing
 * Fails:     missing filename or failure to open or parse file
 * Returns:   color to play
 */
static int
gtp_loadsgf(char *s, int id)
{
  char filename[GTP_BUFSIZE];
  char untilstring[GTP_BUFSIZE];
  SGFNode *sgf;
  Gameinfo gameinfo;
  int nread;
  int color_to_move;
  
  nread = sscanf(s, "%s %s", filename, untilstring);
  if (nread < 1)
    return gtp_failure(id, "missing filename");
  
  if ((sgf = readsgffile(filename)) == NULL)
    return gtp_failure(id, "cannot open or parse '%s'", filename);

  gameinfo_clear(&gameinfo, 19, 5.5); /* Probably unnecessary. */
  gameinfo_load_sgfheader(&gameinfo, sgf);

  if (nread == 1)
    color_to_move = gameinfo_play_sgftree_rot(&gameinfo, sgf, NULL,
					      gtp_orientation);
  else
    color_to_move = gameinfo_play_sgftree_rot(&gameinfo, sgf, untilstring,
                                              gtp_orientation);

  handicap = gameinfo.handicap;
  gtp_internal_set_boardsize(board_size);
  reset_engine();

  gtp_printid(id, GTP_SUCCESS);
  gtp_mprintf("%C", color_to_move);
  sgfFreeNode(sgf);
  return gtp_finish_response();
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/


/*****************
 * Board status. *
 *****************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Return the color at a vertex.
 * Arguments: vertex
 * Fails:     invalid vertex
 * Returns:   "black", "white", or "empty"
 */
static int
gtp_what_color (char *s, int id)
{
  int i, j;

  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");
  
  return gtp_success(id, color_to_string(BOARD(i, j)));
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  List vertices with either black or white stones.
 * Arguments: color
 * Fails:     invalid color
 * Returns:   list of vertices
 */
static int
gtp_list_stones (char *s, int id)
{
  int i, j;
  int color = EMPTY;
  int vertexi[MAX_BOARD * MAX_BOARD];
  int vertexj[MAX_BOARD * MAX_BOARD];
  int vertices = 0;
  
  if (!gtp_decode_color (s, &color))
    return gtp_failure(id, "invalid color");

  for (i = 0; i < board_size; i++)
  for (j = 0; j < board_size; j++)
    if (BOARD (i, j) == color) {
      vertexi[vertices] = i;
      vertexj[vertices++] = j;
    }

  gtp_printid (id, GTP_SUCCESS);
  gtp_print_vertices (vertices, vertexi, vertexj);

  return gtp_finish_response();
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Count number of liberties for the string at a vertex.
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   Number of liberties.
 */
static int
gtp_countlib(char *s, int id)
{
  int i, j;
  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  return gtp_success(id, "%d", countlib(POS(i, j)));
}


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Return the positions of the liberties for the string at a vertex.
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   Sorted space separated list of vertices.
 */
static int
gtp_findlib(char *s, int id)
{
  int i, j;
  int libs[MAXLIBS];
  int liberties;
  
  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  liberties = findlib(POS(i, j), MAXLIBS, libs);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_vertices2(liberties, libs);
  return gtp_finish_response();
}


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Tell whether a move is legal.
 * Arguments: move
 * Fails:     invalid move
 * Returns:   1 if the move is legal, 0 if it is not.
 */
static int
gtp_is_legal(char *s, int id)
{
  int i, j;
  int color;
  
  if (!gtp_decode_move(s, &color, &i, &j))
    return gtp_failure(id, "invalid color or coordinate");

  return gtp_success(id, "%d", is_legal(POS(i, j), color));
}


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  List all legal moves for either color.
 * Arguments: color
 * Fails:     invalid color
 * Returns:   Sorted space separated list of vertices.
 */
static int
gtp_all_legal(char *s, int id)
{
  int i, j;
  int color;
  int movei[MAX_BOARD * MAX_BOARD];
  int movej[MAX_BOARD * MAX_BOARD];
  int moves = 0;
  
  if (!gtp_decode_color(s, &color))
    return gtp_failure(id, "invalid color");

  for (i = 0; i < board_size; i++)
    for (j = 0; j < board_size; j++)
      if (BOARD(i, j) == EMPTY && is_legal(POS(i, j), color)) {
	movei[moves] = i;
	movej[moves++] = j;
      }

  gtp_printid(id, GTP_SUCCESS);
  gtp_print_vertices(moves, movei, movej);
  return gtp_finish_response();
}


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  List the number of captures taken by either color.
 * Arguments: color
 * Fails:     invalid color
 * Returns:   Number of captures.
 */
static int
gtp_captures(char *s, int id)
{
  int color;
  
  if (!gtp_decode_color(s, &color))
    return gtp_failure(id, "invalid color");

  if (color == BLACK)
    return gtp_success(id, "%d", white_captured);
  else
    return gtp_success(id, "%d", black_captured);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/


/**********************
 * Retractable moves. *
 **********************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Play a stone of the given color at the given vertex.
 * Arguments: move (color + vertex)
 * Fails:     invalid color, invalid vertex, illegal move
 * Returns:   nothing
 */
static int
gtp_trymove(char *s, int id)
{
  int i, j;
  int color;
  if (!gtp_decode_move(s, &color, &i, &j))
    return gtp_failure(id, "invalid color or coordinate");

  if (!trymove(POS(i, j), color, "gtp_trymove", NO_MOVE, EMPTY, NO_MOVE))
    return gtp_failure(id, "illegal move");

  return gtp_success(id, "");
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Play a stone of the given color at the given vertex, 
 *            allowing illegal ko capture.
 * Arguments: move (color + vertex)
 * Fails:     invalid color, invalid vertex, illegal move
 * Returns:   nothing
 */
static int
gtp_tryko(char *s, int id)
{
  int i, j;
  int color;
  if (!gtp_decode_move(s, &color, &i, &j))
    return gtp_failure(id, "invalid color or coordinate");

  if (!tryko(POS(i, j), color, "gtp_tryko", EMPTY, NO_MOVE))
    return gtp_failure(id, "illegal move");

  return gtp_success(id, "");
}


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Undo a trymove.
 * Arguments: none
 * Fails:     stack empty
 * Returns:   nothing
 */
static int
gtp_popgo(char *s, int id)
{
  UNUSED(s);

  if (stackp == 0)
    return gtp_failure(id, "Stack empty.\n");

  popgo();
  return gtp_success(id, "");
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/


/*********************
 * Tactical reading. *
 *********************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Try to attack a string.
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   attack code followed by attack point if attack code nonzero.
 */
static int
gtp_attack(char *s, int id)
{
  int i, j;
  int apos;
  int attack_code;
  
  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  attack_code = attack(POS(i, j), &apos);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(attack_code);
  if (attack_code > 0) {
    gtp_printf(" ");
    gtp_print_vertex(I(apos), J(apos));
  }

  return gtp_finish_response();
}  
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Try to defend a string.
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   defense code followed by defense point if defense code nonzero.
 */
static int
gtp_defend(char *s, int id)
{
  int i, j;
  int dpos;
  int defend_code;
  
  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  defend_code = find_defense(POS(i, j), &dpos);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(defend_code);
  if (defend_code > 0) {
    gtp_printf(" ");
    gtp_print_vertex(I(dpos), J(dpos));
  }

  return gtp_finish_response();
}  
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Try to attack a string strictly in a ladder.
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   attack code followed by attack point if attack code nonzero.
 */
static int
gtp_ladder_attack(char *s, int id)
{
  int i, j;
  int apos;
  int attack_code;
  
  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  if (countlib(POS(i, j)) != 2)
    return gtp_failure(id, "string must have exactly 2 liberties");

  attack_code = simple_ladder(POS(i, j), &apos);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(attack_code);
  if (attack_code > 0) {
    gtp_printf(" ");
    gtp_print_vertex(I(apos), J(apos));
  }

  return gtp_finish_response();
}  
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Increase depth values by one.
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_increase_depths(char *s, int id)
{
  UNUSED(s);
  increase_depth_values();

  return gtp_success(id, "");
}  
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Decrease depth values by one.
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_decrease_depths(char *s, int id)
{
  UNUSED(s);
  decrease_depth_values();
  return gtp_success(id, "");
}  
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/


/******************
 * owl reading. *
 ******************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Try to attack a dragon.
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   attack code followed by attack point if attack code nonzero.
 */
static int
gtp_owl_attack(char *s, int id)
{
  int i, j;
  int attack_point;
  int attack_code;
  int result_certain;

  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  silent_examine_position(BOARD(i, j), EXAMINE_DRAGONS_WITHOUT_OWL);
  
  /* to get the variations into the sgf file, clear the reading cache */
  if (sgf_dumptree)
    reading_cache_clear();
  
  attack_code = owl_attack(POS(i, j), &attack_point, &result_certain);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(attack_code);
  if (attack_code > 0) {
    gtp_printf(" ");
    gtp_print_vertex(I(attack_point), J(attack_point));
  }
  if (!result_certain && report_uncertainty)
    gtp_printf(" uncertain");

  return gtp_finish_response();
}  
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Try to defend a dragon.
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   defense code followed by defense point if defense code nonzero.
 */
static int
gtp_owl_defend(char *s, int id)
{
  int i, j;
  int defense_point;
  int defend_code;
  int result_certain;
  
  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  silent_examine_position(BOARD(i, j), EXAMINE_DRAGONS_WITHOUT_OWL);
  
  /* to get the variations into the sgf file, clear the reading cache */
  if (sgf_dumptree)
    reading_cache_clear();

  defend_code = owl_defend(POS(i, j), &defense_point, &result_certain);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(defend_code);
  if (defend_code > 0) {
    gtp_printf(" ");
    gtp_print_vertex(I(defense_point), J(defense_point));
  }
  if (!result_certain && report_uncertainty)
    gtp_printf(" uncertain");
  return gtp_finish_response();
}  

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Try to attack a dragon in 2 moves.
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   attack code followed by the two attack points if
 *            attack code nonzero.
 */
static int
gtp_owl_threaten_attack(char *s, int id)
{
  int i, j;
  int attack_point1;
  int attack_point2;
  int attack_code;

  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  silent_examine_position(BOARD(i, j), EXAMINE_DRAGONS_WITHOUT_OWL);
  
  /* to get the variations into the sgf file, clear the reading cache */
  if (sgf_dumptree)
    reading_cache_clear();
  
  attack_code = owl_threaten_attack(POS(i, j), &attack_point1, &attack_point2);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(attack_code);
  if (attack_code > 0) {
    gtp_printf(" ");
    gtp_print_vertex(I(attack_point1), J(attack_point1));
    gtp_printf(" ");
    gtp_print_vertex(I(attack_point2), J(attack_point2));
  }
  return gtp_finish_response();
}  


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Try to defend a dragon with 2 moves.
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   defense code followed by the 2 defense points if
 *            defense code nonzero.
 */
static int
gtp_owl_threaten_defense(char *s, int id)
{
  int i, j;
  int defense_point1;
  int defense_point2;
  int defend_code;
  
  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  silent_examine_position(BOARD(i, j), EXAMINE_DRAGONS_WITHOUT_OWL);
  
  /* to get the variations into the sgf file, clear the reading cache */
  if (sgf_dumptree)
    reading_cache_clear();

  defend_code = owl_threaten_defense(POS(i, j), &defense_point1,
				     &defense_point2);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(defend_code);
  if (defend_code > 0) {
    gtp_printf(" ");
    gtp_print_vertex(I(defense_point1), J(defense_point1));
    gtp_printf(" ");
    gtp_print_vertex(I(defense_point2), J(defense_point2));
  }
  return gtp_finish_response();
}  


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Examine whether a specific move attacks a dragon.
 * Arguments: vertex (move), vertex (dragon)
 * Fails:     invalid vertex, empty vertex
 * Returns:   attack code
 */
static int
gtp_owl_does_attack(char *s, int id)
{
  int i, j;
  int ti, tj;
  int attack_code;
  int n;

  n = gtp_decode_coord(s, &ti, &tj);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(ti, tj) != EMPTY)
    return gtp_failure(id, "move vertex must be empty");

  n = gtp_decode_coord(s + n, &i, &j);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "dragon vertex must not be empty");

  silent_examine_position(BOARD(i, j), EXAMINE_DRAGONS_WITHOUT_OWL);
  
  /* to get the variations into the sgf file, clear the reading cache */
  if (sgf_dumptree)
    reading_cache_clear();
  
  attack_code = owl_does_attack(POS(ti, tj), POS(i, j));
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(attack_code);
  return gtp_finish_response();
}  


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Examine whether a specific move defends a dragon.
 * Arguments: vertex (move), vertex (dragon)
 * Fails:     invalid vertex, empty vertex
 * Returns:   defense code
 */
static int
gtp_owl_does_defend(char *s, int id)
{
  int i, j;
  int ti, tj;
  int defense_code;
  int n;

  n = gtp_decode_coord(s, &ti, &tj);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(ti, tj) != EMPTY)
    return gtp_failure(id, "move vertex must be empty");

  n = gtp_decode_coord(s + n, &i, &j);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "dragon vertex must not be empty");

  silent_examine_position(BOARD(i, j), EXAMINE_DRAGONS_WITHOUT_OWL);
  
  /* to get the variations into the sgf file, clear the reading cache */
  if (sgf_dumptree)
    reading_cache_clear();
  
  defense_code = owl_does_defend(POS(ti, tj), POS(i, j));
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(defense_code);
  return gtp_finish_response();
}  


/* Function:  Examine whether a connection defends involved dragons.
 * Arguments: vertex (move), vertex (dragon1), vertex (dragon2)
 * Fails:     invalid vertex, empty vertex
 * Returns:   defense code
 */
static int
gtp_owl_connection_defends(char *s, int id)
{
  int ai, aj;
  int bi, bj;
  int ti, tj;
  int defense_code;
  int n;

  n = gtp_decode_coord(s, &ti, &tj);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(ti, tj) != EMPTY)
    return gtp_failure(id, "move vertex must be empty");

  s += n;
  n = gtp_decode_coord(s, &ai, &aj);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  s += n;
  n = gtp_decode_coord(s, &bi, &bj);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(ai, aj) == EMPTY || BOARD(bi, bj) == EMPTY)
    return gtp_failure(id, "dragon vertex must not be empty");

  if (BOARD(ai, aj) != BOARD(bi, bj))
    return gtp_failure(id, "dragon vertices must have the same color");

  silent_examine_position(BOARD(ai, aj), EXAMINE_DRAGONS_WITHOUT_OWL);
  
  /* to get the variations into the sgf file, clear the reading cache */
  if (sgf_dumptree)
    reading_cache_clear();
  
  defense_code = owl_connection_defends(POS(ti, tj), POS(ai, aj), POS(bi, bj));
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(defense_code);
  return gtp_finish_response();
}


/* Function:  Determine whether capturing a string gives a living dragon
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   1 if dragon can live, 0 otherwise
 */
static int
gtp_owl_substantial(char *s, int id)
{
  int i, j;
  int result;
  
  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  silent_examine_position(OTHER_COLOR(BOARD(i, j)),
			  EXAMINE_DRAGONS_WITHOUT_OWL);
  
  /* to get the variations into the sgf file, clear the reading cache */
  if (sgf_dumptree)
    reading_cache_clear();

  result = owl_substantial(POS(i, j));
  return gtp_success(id, "%d", result);
}  


/* Function:  Analyze a semeai
 * Arguments: dragona, dragonb
 * Fails:     invalid vertices, empty vertices
 * Returns:   status of dragona, dragonb assuming dragona moves first
 */
static int
gtp_owl_analyze_semeai(char *s, int id)
{
  int i, j;
  int k;
  int dragona, dragonb;
  int resulta, resultb, move;
  
  k = gtp_decode_coord(s, &i, &j);

  if (k == 0)
    return gtp_failure(id, "invalid coordinate");
  dragona = POS(i, j);
  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  if (!gtp_decode_coord(s+k, &i, &j))
    return gtp_failure(id, "invalid coordinate");
  dragonb = POS(i, j);
  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  silent_examine_position(BOARD(i, j), EXAMINE_DRAGONS_WITHOUT_OWL);
  /* to get the variations into the sgf file, clear the reading cache */
  if (sgf_dumptree)
      reading_cache_clear();

  owl_analyze_semeai(dragona, dragonb, &resulta, &resultb, &move, 1);
  gtp_printid(id, GTP_SUCCESS);
  gtp_mprintf("%s %s %m", 
	      safety_to_string(resulta),
	      safety_to_string(resultb),
	      I(move), J(move));

  return gtp_finish_response();
}  


/* Function:  Analyze a semeai, not using owl
 * Arguments: dragona, dragonb
 * Fails:     invalid vertices, empty vertices
 * Returns:   status of dragona, dragonb assuming dragona moves first
 */
static int
gtp_tactical_analyze_semeai(char *s, int id)
{
  int i, j;
  int k;
  int dragona, dragonb;
  int resulta, resultb, move;
  
  k = gtp_decode_coord(s, &i, &j);

  if (k == 0)
    return gtp_failure(id, "invalid coordinate");
  dragona = POS(i, j);
  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  if (!gtp_decode_coord(s+k, &i, &j))
    return gtp_failure(id, "invalid coordinate");
  dragonb = POS(i, j);
  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  silent_examine_position(BOARD(i, j), EXAMINE_DRAGONS_WITHOUT_OWL);
  /* to get the variations into the sgf file, clear the reading cache */
  if (sgf_dumptree)
    reading_cache_clear();

  owl_analyze_semeai(dragona, dragonb, &resulta, &resultb, &move, 0);
  gtp_printid(id, GTP_SUCCESS);
  gtp_mprintf("%s %s %m", 
	      safety_to_string(resulta),
	      safety_to_string(resultb),
	      I(move), J(move));

  return gtp_finish_response();
}  


/***********************
 * Connection reading. *
 ***********************/

/* Function:  Try to connect two strings.
 * Arguments: vertex, vertex
 * Fails:     invalid vertex, empty vertex, vertices of different colors
 * Returns:   connect result followed by connect point if successful.
 */
static int
gtp_connect(char *s, int id)
{
  int ai, aj;
  int bi, bj;
  int connect_move = PASS_MOVE;
  int result;
  int n;
  
  n = gtp_decode_coord(s, &ai, &aj);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  if (!gtp_decode_coord(s + n, &bi, &bj))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(ai, aj) == EMPTY || BOARD(bi, bj) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  if (BOARD(ai, aj) != BOARD(bi, bj))
    return gtp_failure(id, "vertices must have same color");

  result = string_connect(POS(ai, aj), POS(bi, bj), &connect_move);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(result);
  if (result != 0)
    gtp_mprintf(" %m", I(connect_move), J(connect_move));

  return gtp_finish_response();
}  


/* Function:  Try to disconnect two strings.
 * Arguments: vertex, vertex
 * Fails:     invalid vertex, empty vertex, vertices of different colors
 * Returns:   disconnect result followed by disconnect point if successful.
 */
static int
gtp_disconnect(char *s, int id)
{
  int ai, aj;
  int bi, bj;
  int disconnect_move = PASS_MOVE;
  int result;
  int n;
  
  n = gtp_decode_coord(s, &ai, &aj);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  if (!gtp_decode_coord(s + n, &bi, &bj))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(ai, aj) == EMPTY || BOARD(bi, bj) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  if (BOARD(ai, aj) != BOARD(bi, bj))
    return gtp_failure(id, "vertices must have same color");

  result = disconnect(POS(ai, aj), POS(bi, bj), &disconnect_move);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_code(result);
  if (result != 0)
    gtp_mprintf(" %m", I(disconnect_move), J(disconnect_move));

  return gtp_finish_response();
}  


/********
 * eyes *
 ********/

/* Function:  Evaluate an eye space
 * Arguments: vertex
 * Fails:     invalid vertex
 * Returns:   Minimum and maximum number of eyes. If these differ an
 *            attack and a defense point are additionally returned.
 *            If the vertex is not an eye space or not of unique color,
 *            a single -1 is returned.
 */

static int
gtp_eval_eye(char *s, int id)
{
  int m, n;
  int max, min;
  int attack_point;
  int defense_point;
  int pos;

  if (!gtp_decode_coord(s, &m, &n))
    return gtp_failure(id, "invalid coordinate");

  silent_examine_position(BLACK, EXAMINE_DRAGONS_WITHOUT_OWL);
  
  if (black_eye[POS(m, n)].color == BLACK_BORDER) {
    pos = black_eye[POS(m, n)].origin;
    compute_eyes(pos, &max, &min, &attack_point, &defense_point,
		 black_eye, half_eye, 0, EMPTY);
  }
  else if (white_eye[POS(m, n)].color == WHITE_BORDER) {
    pos = white_eye[POS(m, n)].origin;
    compute_eyes(pos, &max, &min, &attack_point, &defense_point,
		 white_eye, half_eye, 0, EMPTY);
  }
  else
    /* Not an eye or not of unique color. */
    return gtp_success(id, "-1");

  gtp_printid(id, GTP_SUCCESS);
  gtp_printf("%d %d", min, max);
  if (max != min) {
    gtp_printf(" ");
    gtp_print_vertex(I(attack_point), J(attack_point));
    gtp_printf(" ");
    gtp_print_vertex(I(defense_point), J(defense_point));
  }
  return gtp_finish_response();
}


/*****************
 * dragon status *
 *****************/

/* Function:  Determine status of a dragon.
 * Arguments: vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   status ("alive", "critical", "dead", or "unknown"),
 *            attack point, defense point. Points of attack and
 *            defense are only given if the status is critical and the
 *            owl code is enabled.
 *
 * FIXME: Should be able to distinguish between life in seki
 *        and life with territory. Should also be able to identify ko.
 */

static int
gtp_dragon_status(char *s, int id)
{
  int i, j;

  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  silent_examine_position(BLACK, EXAMINE_DRAGONS);
  
  /* FIXME: We should also call the semeai module. */

  if (dragon[POS(i, j)].owl_status == UNCHECKED) {
    if (dragon[POS(i, j)].status == ALIVE)
      return gtp_success(id, "alive");
  
    if (dragon[POS(i, j)].status == DEAD)
      return gtp_success(id, "dead");
  
    if (dragon[POS(i, j)].status == UNKNOWN)
      return gtp_success(id, "unknown");

    assert(dragon[POS(i, j)].status == CRITICAL); /* Only remaining possibility. */
    return gtp_success(id, "critical");
  }

  /* Owl code active. */
  if (dragon[POS(i, j)].owl_status == ALIVE)
    return gtp_success(id, "alive");
  
  if (dragon[POS(i, j)].owl_status == DEAD)
    return gtp_success(id, "dead");
  
  if (dragon[POS(i, j)].owl_status == UNKNOWN)
    return gtp_success(id, "unknown");
  
  assert(dragon[POS(i, j)].owl_status == CRITICAL);
  /* Status critical, need to return attack and defense point as well. */
  gtp_printid(id, GTP_SUCCESS);
  gtp_printf("critical ");
  gtp_print_vertex(I(dragon[POS(i, j)].owl_attack_point),
		   J(dragon[POS(i, j)].owl_attack_point));
  gtp_printf(" ");
  gtp_print_vertex(I(dragon[POS(i, j)].owl_defense_point),
		   J(dragon[POS(i, j)].owl_defense_point));
  return gtp_finish_response();
}


/* Function:  Determine whether two stones belong to the same dragon.
 * Arguments: vertex, vertex
 * Fails:     invalid vertex, empty vertex
 * Returns:   1 if the vertices belong to the same dragon, 0 otherwise
 */

static int
gtp_same_dragon(char *s, int id)
{
  int ai, aj;
  int bi, bj;
  int n;

  n = gtp_decode_coord(s, &ai, &aj);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  if (!gtp_decode_coord(s + n, &bi, &bj))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(ai, aj) == EMPTY || BOARD(bi, bj) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  silent_examine_position(BLACK, EXAMINE_DRAGONS_WITHOUT_OWL);
  
  return gtp_success(id, "%d", dragon[POS(ai, aj)].id == dragon[POS(bi, bj)].id);
}


/***********************
 * combination attacks *
 ***********************/

/* Function:  Find a move by color capturing something through a
 *            combination attack.
 * Arguments: color
 * Fails:     invalid color
 * Returns:   Recommended move, PASS if no move found
 */

static int
gtp_combination_attack(char *s, int id)
{
  int color;
  int attack_point;
  int n;

  n = gtp_decode_color(s, &color);
  if (!n)
    return gtp_failure(id, "invalid color");

  silent_examine_position(BLACK, EXAMINE_ALL);

  if (!atari_atari(color, &attack_point, NULL, verbose))
    attack_point = NO_MOVE;
  
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_vertex(I(attack_point), J(attack_point));
  return gtp_finish_response();
}

/* Function:  Run atari_atari_confirm_safety().
 * Arguments: move, optional int
 * Fails:     invalid move
 * Returns:   success code, if failure also defending move
 */

static int
gtp_aa_confirm_safety(char *s, int id)
{
  int color;
  int i, j;
  int n;
  int minsize = 0;
  int result;
  int defense_point = NO_MOVE;
  int saved_dragons[BOARDMAX];
  int saved_worms[BOARDMAX];

  n = gtp_decode_move(s, &color, &i, &j);
  if (n == 0)
    return gtp_failure(id, "invalid color or coordinate");

  sscanf(s + n, "%d", &minsize);

  genmove(NULL, NULL, color);
  get_saved_dragons(POS(i, j), saved_dragons);
  get_saved_worms(POS(i, j), saved_worms);
  
  result = atari_atari_confirm_safety(color, POS(i, j),
				      &defense_point, minsize,
				      saved_dragons, saved_worms);
  
  gtp_printid(id, GTP_SUCCESS);
  gtp_mprintf("%d", result);
  if (result == 0)
    gtp_mprintf(" %m", I(defense_point), J(defense_point));
  
  return gtp_finish_response();
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/


/********************
 * generating moves *
 ********************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Generate and play the supposedly best black move.
 * Arguments: none
 * Fails:     never
 * Returns:   a move coordinate (or "PASS")
 */
static int
gtp_genmove_black(char *s, int id)
{
  int i, j;
  UNUSED(s);

  if (stackp > 0)
    return gtp_failure(id, "genmove cannot be called when stackp > 0");

  if (genmove(&i, &j, BLACK) >= 0)
    play_move(POS(i, j), BLACK);
  else
    play_move(NO_MOVE, BLACK);

  gtp_printid(id, GTP_SUCCESS);
  gtp_print_vertex(i, j);
  return gtp_finish_response();
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Generate and play the supposedly best white move.
 * Arguments: none
 * Fails:     never
 * Returns:   a move coordinate (or "PASS")
 */
static int
gtp_genmove_white(char *s, int id)
{
  int i, j;
  UNUSED(s);

  if (stackp > 0)
    return gtp_failure(id, "genmove cannot be called when stackp > 0");

  if (genmove (&i, &j, WHITE) >= 0)
    play_move (POS(i, j), WHITE);
  else
    play_move (NO_MOVE, WHITE);

  gtp_printid (id, GTP_SUCCESS);
  gtp_print_vertex (i, j);

  return gtp_finish_response();
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Function:  Generate the supposedly best move for either color.
 * Arguments: color to move, optionally a random seed
 * Fails:     invalid color
 * Returns:   a move coordinate (or "PASS")
 */
static int
gtp_genmove (char *s, int id)
{
  int i, j;
  int color;
  int n;
  unsigned int seed;

  n = gtp_decode_color(s, &color);
  if (!n)
    return gtp_failure(id, "invalid color");

  if (stackp > 0)
    return gtp_failure(id, "genmove cannot be called when stackp > 0");

  /* This is intended for regression purposes and should therefore be
   * deterministic. The best way to ensure this is to reset the random
   * number generator before calling genmove(). By default it is
   * seeded with 0, but if an optional unsigned integer is given in
   * the command after the color, this is used as seed instead.
   */
  seed = 0;
  sscanf(s+n, "%u", &seed);
  random_seed = seed;
  
  genmove_conservative(&i, &j, color);
  gtp_printid(id, GTP_SUCCESS);
  gtp_print_vertex(i, j);

  return gtp_finish_response();
}

/* Function : Generate a list of the best moves in the previous genmove
 *            command (either of genmove_black, genmove_white, gg_genmove).
 *            If no previous genmove command has been issued, the result
 *            of this command will be meaningless.
 * Arguments: none
 * Fails:   : never
 * Returns  : list of moves with weights
 */

static int
gtp_top_moves(char *s, int id)
{
  int k;
  UNUSED(s);
  gtp_printid(id, GTP_SUCCESS);
  for (k = 0; k < 10; k++)
    if (best_move_values[k] > 0.0) {
      gtp_print_vertex(I(best_moves[k]), J(best_moves[k]));
      gtp_printf(" %.2f ", best_move_values[k]);
    }
  gtp_printf("\n\n");
  return GTP_OK;
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function : Generate a list of the best moves for White with weights
 * Arguments: none
 * Fails:   : never
 * Returns  : list of moves with weights
 */
static int
gtp_top_moves_white (char *s, int id)
{
  int i, j, k;
  UNUSED(s);
  genmove (&i, &j, WHITE);
  gtp_printid (id, GTP_SUCCESS);

  for (k = 0; k < 10; k++)
    if (best_move_values[k] > 0.0) {
      gtp_print_vertex (I(best_moves[k]), J(best_moves[k]));
      gtp_printf (" %.2f ", best_move_values[k]);
    }

  gtp_printf ("\n\n");
  return GTP_OK;
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
static int
gtp_top_moves_black (char *s, int id)
{
  int i, j, k;
  UNUSED(s);
  genmove (&i, &j, BLACK);
  gtp_printid (id, GTP_SUCCESS);
  for (k = 0; k < 10; k++)
    if (best_move_values[k] > 0.0) {
      gtp_print_vertex(I(best_moves[k]), J(best_moves[k]));
      gtp_printf(" %.2f ", best_move_values[k]);
    }

  gtp_printf("\n\n");
  return GTP_OK;
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Set the playing level.
 * Arguments: int
 * Fails:     incorrect argument
 * Returns:   nothing
 */
static int
gtp_set_level(char *s, int id)
{
  int new_level;
  if (sscanf(s, "%d", &new_level) < 1)
    return gtp_failure(id, "level not an integer");
  
  level = new_level;
  return gtp_success(id, "");
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Function:  Undo a number of moves
 * Arguments: optional int
 * Fails:     If move history is too short.
 * Returns:   nothing
 */

static int
gtp_undo(char *s, int id)
{
  int number_moves = 1;

  sscanf(s, "%d", &number_moves);

  if (number_moves < 0)
    return gtp_failure(id, "can't undo a negative number of moves");

  if (!undo_move(number_moves))
    return gtp_failure(id, "undo failed");
  
  return gtp_success(id, "");
}


/***********
 * scoring *
 ***********/

static float final_score;
static int final_status[MAX_BOARD][MAX_BOARD];
static int status_numbers[6] = {ALIVE, DEAD, ALIVE_IN_SEKI, WHITE_TERRITORY,
				BLACK_TERRITORY, DAME};
static const char *status_names[6] = {"alive", "dead", "seki",
				      "white_territory", "black_territory",
				      "dame"};

/* Helper function. */
static void
finish_and_score_game(int seed)
{
  int move_val;
  int i, j;
  int next;
  int pass = 0;
  int moves = 0;
  int saved_board[MAX_BOARD][MAX_BOARD];
  struct board_state saved_pos;
  static int current_board[MAX_BOARD][MAX_BOARD];
  static int current_seed = -1;
  int cached_board = 1;

  if (current_seed != seed) {
    current_seed = seed;
    cached_board = 0;
  }

  for (i = 0; i < board_size; i++)
    for (j = 0; j < board_size; j++)
      if (BOARD(i, j) != current_board[i][j]) {
	current_board[i][j] = BOARD(i, j);
	cached_board = 0;
      }

  /* If this is exactly the same position as the one we analyzed the
   * last time, the contents of final_score and final_status are up to date.
   */
  if (cached_board)
    return;

  doing_scoring = 1;
  store_board(&saved_pos);

  /* FIXME: Letting black always start is a preliminary solution. */
  next = BLACK;
  do {
    move_val = genmove_conservative(&i, &j, next);
    play_move(POS(i, j), next);
    if (move_val >= 0) {
      pass = 0;
      moves++;
    }
    else
      pass++;

    next = OTHER_COLOR(next);
  } while (pass < 2 && moves < board_size * board_size);

  final_score = aftermath_compute_score(next, komi, NULL);
  for (i = 0; i < board_size; i++)
    for (j = 0; j < board_size; j++) {
      final_status[i][j] = aftermath_final_status(next, POS(i, j));
      saved_board[i][j] = BOARD(i, j);
    }

  restore_board(&saved_pos);
  doing_scoring = 0;

  /* Update the status for vertices which were changed while finishing
   * the game, up to filling dame.
   */
  for (i = 0; i < board_size; i++)
    for (j = 0; j < board_size; j++) {
      if (BOARD(i, j) == saved_board[i][j])
	continue;

      if (BOARD(i, j) == EMPTY) {
	if (final_status[i][j] == ALIVE
	    || final_status[i][j] == ALIVE_IN_SEKI)
	  final_status[i][j] = DAME;
	else if (final_status[i][j] == DEAD) {
	  if (saved_board[i][j] == BLACK)
	    final_status[i][j] = WHITE_TERRITORY;
	  else
	    final_status[i][j] = BLACK_TERRITORY;
	}
      }
      else if (BOARD(i, j) == BLACK) {
	if (final_status[i][j] == WHITE_TERRITORY)
	  final_status[i][j] = DEAD;
	else if (final_status[i][j] == DAME)
	  final_status[i][j] = ALIVE_IN_SEKI;
	else if (final_status[i][j] == BLACK_TERRITORY)
	  final_status[i][j] = ALIVE;
	else
	  final_status[i][j] = DEAD;
      }
      else if (BOARD(i, j) == WHITE) {
	if (final_status[i][j] == BLACK_TERRITORY)
	  final_status[i][j] = DEAD;
	else if (final_status[i][j] == DAME)
	  final_status[i][j] = ALIVE_IN_SEKI;
	else if (final_status[i][j] == WHITE_TERRITORY)
	  final_status[i][j] = ALIVE;
	else
	  final_status[i][j] = DEAD;
      }
    }
}


/* Function:  Compute the score of a finished game.
 * Arguments: Optional random seed
 * Fails:     never
 * Returns:   Score in SGF format (RE property).
 */
static int
gtp_final_score(char *s, int id)
{
  int seed;
  /* This is intended for regression purposes and should therefore be
   * deterministic. The best way to ensure this is to reset the random
   * number generator before calling genmove(). By default it is
   * seeded with 0, but if an optional unsigned integer is given in
   * the command after the color, this is used as seed instead.
   */
  seed = 0;
  sscanf(s, "%u", &seed);
  random_seed = seed;

  finish_and_score_game(seed);

  gtp_printid(id, GTP_SUCCESS);
  if (final_score > 0.0)
    gtp_printf("W+%3.1f", final_score);
  else if (final_score < 0.0)
    gtp_printf("B+%3.1f", -final_score);
  else
    gtp_printf("0");
  return gtp_finish_response();
}


/* Function:  Report the final status of a vertex in a finished game.
 * Arguments: Vertex, optional random seed
 * Fails:     invalid vertex
 * Returns:   Status in the form of one of the strings "alive", "dead",
 *            "seki", "white_territory", "black_territory", or "dame".
 */
static int
gtp_final_status(char *s, int id)
{
  int seed;
  int n;
  int ai, aj;
  int k;
  const char *result = NULL;

  n = gtp_decode_coord(s, &ai, &aj);
  if (n == 0)
    return gtp_failure(id, "invalid coordinate");

  /* This is intended for regression purposes and should therefore be
   * deterministic. The best way to ensure this is to reset the random
   * number generator before calling genmove(). By default it is
   * seeded with 0, but if an optional unsigned integer is given in
   * the command after the color, this is used as seed instead.
   */
  seed = 0;
  sscanf(s + n, "%u", &seed);
  random_seed = seed;

  finish_and_score_game(seed);

  for (k = 0; k < 6; k++)
    if (final_status[ai][aj] == status_numbers[k]) {
      result = status_names[k];
      break;
    }
  assert(result != NULL);

  return gtp_success(id, result);
}


/* Function:  Report vertices with a specific final status in a finished game.
 * Arguments: Status in the form of one of the strings "alive", "dead",
 *            "seki", "white_territory", "black_territory", or "dame".
 *            An optional random seed can be added.
 * Fails:     missing or invalid status string
 * Returns:   Vertices having the specified status. These are split with
 *            one string on each line if the vertices are nonempty (i.e.
 *            for "alive", "dead", and "seki").
 */
static int
gtp_final_status_list(char *s, int id)
{
  int seed;
  int n;
  int i, j;
  int status = UNKNOWN;
  int k;
  char status_string[GTP_BUFSIZE];
  int first;

  if (sscanf(s, "%s %n", status_string, &n) != 1)
    return gtp_failure(id, "missing status");
  
  for (k = 0; k < 6; k++) {
    if (strcmp(status_string, status_names[k]) == 0)
      status = status_numbers[k];
  }

  if (status == UNKNOWN)
    return gtp_failure(id, "invalid status");

  /* This is intended for regression purposes and should therefore be
   * deterministic. The best way to ensure this is to reset the random
   * number generator before calling genmove(). By default it is
   * seeded with 0, but if an optional unsigned integer is given in
   * the command after the color, this is used as seed instead.
   */
  seed = 0;
  sscanf(s + n, "%u", &seed);
  random_seed = seed;

  finish_and_score_game(seed);

  gtp_printid(id, GTP_SUCCESS);

  first = 1;
  for (i = 0; i < board_size; i++)
    for (j = 0; j < board_size; j++) {
      if (final_status[i][j] != status)
	continue;
      if (BOARD(i, j) == EMPTY) {
	if (!first)
	  gtp_printf(" ");
	else
	  first = 0;
	gtp_print_vertex(i, j);
      }
      else {
	int num_stones;
	int stones[MAX_BOARD * MAX_BOARD];
	if (find_origin(POS(i, j)) != POS(i, j))
	  continue;
	if (!first)
	  gtp_printf("\n");
	else
	  first = 0;
	num_stones = findstones(POS(i, j), board_size * board_size, stones);
	gtp_print_vertices2(num_stones, stones);
      }
    }

  return gtp_finish_response();
}


static int
gtp_estimate_score(char *s, int id)
{
  UNUSED(s);

  silent_examine_position(WHITE, EXAMINE_DRAGONS);
  
  score = estimate_score(&upper_bound, &lower_bound);
  gtp_printid(id, GTP_SUCCESS);
  /* Traditionally W wins jigo */
  if (score >= 0.0) 
    gtp_printf("W+%3.1f (upper bound: %3.1f, lower: %3.1f)", 
	       score, upper_bound, lower_bound);
  else if (score < 0.0)
    gtp_printf("B+%3.1f (upper bound: %3.1f, lower: %3.1f)", 
	       -score, upper_bound, lower_bound);
  return gtp_finish_response();
}  


/**************
 * statistics *
 **************/

/* Function:  Reset the count of life nodes.
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_reset_life_node_counter(char *s, int id)
{
  UNUSED(s);
  reset_life_node_counter();
  return gtp_success(id, "");
}


/* Function:  Retrieve the count of life nodes.
 * Arguments: none
 * Fails:     never
 * Returns:   number of life nodes
 */
static int
gtp_get_life_node_counter(char *s, int id)
{
  int nodes = get_life_node_counter();
  UNUSED(s);
  return gtp_success(id, "%d", nodes);
}


/* Function:  Reset the count of owl nodes.
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_reset_owl_node_counter(char *s, int id)
{
  UNUSED(s);
  reset_owl_node_counter();
  return gtp_success(id, "");
}


/* Function:  Retrieve the count of owl nodes.
 * Arguments: none
 * Fails:     never
 * Returns:   number of owl nodes
 */
static int
gtp_get_owl_node_counter(char *s, int id)
{
  int nodes = get_owl_node_counter();
  UNUSED(s);
  return gtp_success(id, "%d", nodes);
}


/* Function:  Reset the count of reading nodes.
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_reset_reading_node_counter(char *s, int id)
{
  UNUSED(s);
  reset_reading_node_counter();
  return gtp_success(id, "");
}


/* Function:  Retrieve the count of reading nodes.
 * Arguments: none
 * Fails:     never
 * Returns:   number of reading nodes
 */
static int
gtp_get_reading_node_counter(char *s, int id)
{
  int nodes = get_reading_node_counter();
  UNUSED(s);
  return gtp_success(id, "%d", nodes);
}


/* Function:  Reset the count of trymoves/trykos.
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_reset_trymove_counter(char *s, int id)
{
  UNUSED(s);
  reset_trymove_counter();
  return gtp_success(id, "");
}


/* Function:  Retrieve the count of trymoves/trykos.
 * Arguments: none
 * Fails:     never
 * Returns:   number of trymoves/trykos
 */
static int
gtp_get_trymove_counter(char *s, int id)
{
  int nodes = get_trymove_counter();
  UNUSED(s);
  return gtp_success(id, "%d", nodes);
}


/* Function:  Reset the count of connection nodes.
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_reset_connection_node_counter(char *s, int id)
{
  UNUSED(s);
  reset_connection_node_counter();
  return gtp_success(id, "");
}


/* Function:  Retrieve the count of connection nodes.
 * Arguments: none
 * Fails:     never
 * Returns:   number of connection nodes
 */
static int
gtp_get_connection_node_counter(char *s, int id)
{
  int nodes = get_connection_node_counter();
  UNUSED(s);
  return gtp_success(id, "%d", nodes);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/



/*********
 * debug *
 *********/


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Test an eyeshape for inconsistent evaluations
 * Arguments: Eyeshape vertices
 * Fails:     Bad vertices
 * Returns:   Failure reports on stderr.
 */
static int
gtp_test_eyeshape(char *s, int id)
{
  int n;
  int i, j;
  int eye_vertices[MAX_BOARD * MAX_BOARD];
  int eyesize = 0;

  n = gtp_decode_coord(s, &i, &j);
  while (n > 0) {
    eye_vertices[eyesize] = POS(i, j);
    eyesize++;
    s += n;
    n = gtp_decode_coord(s, &i, &j);
  }
  
  if (eyesize == 0)
    return gtp_failure(id, "invalid coordinate");

  test_eyeshape(eyesize, eye_vertices);

  return gtp_success(id, "");
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Returns elapsed CPU time in seconds.
 * Arguments: none
 * Fails:     never
 * Returns:   Total elapsed (user + system) CPU time in seconds.
 */
static int
gtp_cputime(char *s, int id)
{
  UNUSED(s);
  return gtp_success(id, "%.3f", gg_cputime());
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Write the position to stderr.
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_showboard(char *s, int id)
{
  UNUSED(s);
  showboard (0);

  return gtp_success(id, "");
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Dump stack to stderr.
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_dump_stack(char *s, int id)
{
  UNUSED(s);
  dump_stack();
  return gtp_success(id, "");
}


/* Function:  Return information about the influence function.
 * Arguments: color to move
 * Fails:     never
 * Returns:   Influence data formatted like:
 *
 * white:
 *   0.51   1.34   3.20   6.60   9.09   8.06   1.96   0.00   0.00 
 *   0.45   1.65   4.92  12.19  17.47  15.92   4.03   0.00   0.00 
 *                   .
 *                   .
 *                   .
 *   0.00   0.00   0.00   0.00   0.00 100.00  75.53  41.47  23.41
 * black:
 *   1.57   2.51   4.10   3.10   3.60   4.54   8.32   4.15   2.71 
 *   2.96   4.62   9.18   5.47   5.89  10.88  20.54  10.19   4.08 
 *                   .
 *                   .
 *                   .
 * 100.00 139.39 100.00 139.39 100.00   0.00   0.00   0.00   0.00
 * regions:
 * -1  0  0  1  1  0 -1 -3 -3
 *              .
 *              .
 *              .
 * -3 -3 -3 -3 -3  3  3  3  3
 *
 * The encoding of the regions is as follows:
 *  3 white territory
 *  2 white moyo
 *  1 white area
 *  0 neutral
 * -1 black area
 * -2 black moyo
 * -3 black territory
 */
static int
gtp_influence(char *s, int id)
{
  int color;
  float white_influence[BOARDMAX];
  float black_influence[BOARDMAX];
  int influence_regions[BOARDMAX];
  
  if (!gtp_decode_color(s, &color))
    return gtp_failure(id, "invalid color");

  silent_examine_position(color, EXAMINE_ALL);

  gtp_printid(id, GTP_SUCCESS);
  get_initial_influence(color, 1, white_influence,
			black_influence, influence_regions);
  print_influence(white_influence, black_influence, influence_regions);
  /* We already have one newline and thus can't use gtp_finish_response(). */
  gtp_printf("\n");
  return GTP_OK;
}

static void
print_influence(float white_influence[BOARDMAX],
		float black_influence[BOARDMAX],
		int influence_regions[BOARDMAX])
{
  int m, n;
  gtp_printf("white:\n");
  for (m = 0; m < board_size; m++) {
    for (n = 0; n < board_size; n++) {
      gtp_printf("%6.2f ", white_influence[POS(m, n)]);
    }
    gtp_printf("\n");
  }

  gtp_printf("black:\n");
  for (m = 0; m < board_size; m++) {
    for (n = 0; n < board_size; n++) {
      gtp_printf("%6.2f ", black_influence[POS(m, n)]);
    }
    gtp_printf("\n");
  }

  gtp_printf("regions:\n");
  for (m = 0; m < board_size; m++) {
    for (n = 0; n < board_size; n++) {
      gtp_printf("%2d ", influence_regions[POS(m, n)]);
    }
    gtp_printf("\n");
  }
}


/* Function:  Return the information in the worm data structure.
 * Arguments: optional vertex
 * Fails:     never
 * Returns:   Worm data formatted like:
 *
 * A19:
 * color           black
 * size            10
 * effective_size  17.83
 * origin          A19
 * liberties       8
 * liberties2      15
 * liberties3      10
 * liberties4      8
 * attack          PASS
 * attack_code     0
 * lunch           B19
 * defend          PASS
 * defend_code     0
 * cutstone        2
 * cutstone2       0
 * genus           0
 * inessential     0
 * B19:
 * color           white
 * .
 * .
 * .
 * inessential     0
 * C19:
 * ...
 *
 * If an intersection is specified, only data for this one will be returned.
 */
static int
gtp_worm_data(char *s, int id)
{
  int i = -1;
  int j = -1;
  int m, n;

  if (sscanf(s, "%*c") >= 0 && !gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid color or coordinate");

  examine_position(EMPTY, EXAMINE_WORMS);

  gtp_printid(id, GTP_SUCCESS);
  
  for (m = 0; m < board_size; m++)
    for (n = 0; n < board_size; n++)
      if (i == -1 || (m == i && n == j)) {
	struct worm_data *w = &worm[POS(m, n)];
	gtp_print_vertex(m, n);
	gtp_printf(":\n");
	gtp_mprintf("color           %C\n",  w->color);
	gtp_printf("size            %d\n",   w->size);
	gtp_printf("effective_size  %.2f\n", w->effective_size);
	gtp_mprintf("origin          %m\n", 
		    I(w->origin), J(w->origin));
	gtp_printf("liberties       %d\n",   w->liberties);
	gtp_printf("liberties2      %d\n",   w->liberties2);
	gtp_printf("liberties3      %d\n",   w->liberties3);
	gtp_printf("liberties4      %d\n",   w->liberties4);
	gtp_mprintf("attack_point    %m\n",  
		    I(w->attack_points[0]), J(w->attack_points[0]));
	gtp_printf("attack_code     %d\n",   w->attack_codes[0]);
	gtp_mprintf("lunch           %m\n",  
		    I(w->lunch), J(w->lunch));
	gtp_mprintf("defense_point   %m\n",  
		    I(w->defense_points[0]), J(w->defense_points[0]));
	gtp_printf("defend_code     %d\n",   w->defend_codes[0]);
	gtp_printf("cutstone        %d\n",   w->cutstone);
	gtp_printf("cutstone2       %d\n",   w->cutstone2);
	gtp_printf("genus           %d\n",   w->genus);
	gtp_printf("inessential     %d\n",   w->inessential);
      }
  
  gtp_printf("\n");
  return GTP_OK;
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  List the stones of a worm
 * Arguments: the location, "BLACK" or "WHITE"
 * Fails:     if called on an empty or off-board location
 * Returns:   list of stones
 */
static int
gtp_worm_stones (char *s, int id)
{
  int i = -1;
  int j = -1;
  int color = EMPTY;
  int m, n;
  int u, v;
  int board_empty = 1;

  if (sscanf(s, "%*c") >= 0) {
    if (!gtp_decode_coord(s, &i, &j)
	&& !gtp_decode_color(s, &color))
      return gtp_failure(id, "invalid coordinate");
  }
    
  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "worm_stones called on an empty vertex");

  gtp_printid (id, GTP_SUCCESS);
  
  for (u = 0; u < board_size; u++)
  for (v = 0; v < board_size; v++) {
    if (BOARD(u, v) == EMPTY
        || (color != EMPTY && BOARD(u, v) != color))
      continue;

    board_empty = 0;
    if (find_origin (POS(u, v)) != POS(u, v))
      continue;

    if (ON_BOARD2 (i, j) && !same_string(POS(u, v), POS(i, j)))
      continue;
    for (m = 0; m < board_size; m++)
    for (n = 0; n < board_size; n++)
      if (BOARD(m, n) != EMPTY && same_string(POS(m, n), POS(u, v)))
        gtp_mprintf("%m ", m, n);

    gtp_printf("\n");
  }
  
  if (board_empty) 
    gtp_printf("\n"); /* in case no stones have been printed */

  gtp_printf("\n");

  return GTP_OK;
}



/* Function:  Return the cutstone field in the worm data structure.
 * Arguments: non-empty vertex
 * Fails:     never
 * Returns:   cutstone
 */
static int
gtp_worm_cutstone(char *s, int id)
{

  int i, j;
  if (!gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "vertex must not be empty");

  examine_position(EMPTY, EXAMINE_WORMS);

  return gtp_success(id, " %d", worm[POS(i, j)].cutstone);
}

/* Function:  Return the information in the dragon data structure.
 * Arguments: optional intersection
 * Fails:     never
 * Returns:   Dragon data formatted in the corresponding way to gtp_worm_data.
 */
static int
gtp_dragon_data(char *s, int id)
{
  int i = -1;
  int j = -1;
  int m, n;

  if (sscanf(s, "%*c") >= 0 && !gtp_decode_coord(s, &i, &j))
    return gtp_failure(id, "invalid coordinate");

  if (stackp > 0)
    return gtp_failure(id, "dragon data unavailable when stackp > 0");

  examine_position(EMPTY, EXAMINE_DRAGONS);

  gtp_printid(id, GTP_SUCCESS);

  if (ON_BOARD2(i, j) && BOARD(i, j) == EMPTY)
    gtp_mprintf("%m empty\n", i, j);
  else {
    for (m = 0; m < board_size; m++)
      for (n = 0; n < board_size; n++)
	if ((m == i && n == j)
	    || (i == -1
		&& BOARD(m, n) != EMPTY
		&& dragon[POS(m, n)].origin == POS(m, n))) {
	  int k, ti, tj;
	  struct dragon_data *d = &dragon[POS(m, n)];
	  struct dragon_data2 *d2 = &(dragon2[d->id]);
	  gtp_print_vertex(m, n);
	  gtp_printf(":\n");
	  gtp_printf("color                   %s\n",   
		     color_to_string(d->color));
	  gtp_mprintf("origin                  %m\n", 
		      I(d->origin), J(d->origin));
	  gtp_printf("size                    %d\n",   d->size);
	  gtp_printf("effective_size          %.2f\n", d->effective_size);
	  gtp_printf("heyes                   %d\n",   d2->heyes);
	  gtp_mprintf("heye                    %m\n", 
		      I(d2->heye), J(d2->heye));
	  gtp_printf("genus                   %d\n",   d2->genus);
	  gtp_printf("escape_route            %d\n",   d2->escape_route);
	  /* We would like to use the %1m format used in gprintf
	   * but this is not implemented in gtp_mprintf. Moreover adding this
	   * format would entail including liberty.h in gtp.c, which we
	   * don't want to do in order to maintain independence of the
	   * GNU Go internals. Therefore we use the I and J macros here.
	   */
	  gtp_mprintf("lunch                   %m\n", 
		      I(d2->lunch), J(d2->lunch));
	  gtp_printf("status                  %s\n",   
		     status_to_string(d->status));
	  gtp_printf("owl_status              %s\n",   
		     status_to_string(d->owl_status));
	  gtp_printf("matcher_status          %s\n",   
		     status_to_string(d->matcher_status));
	  gtp_printf("owl_threat_status       %s\n",   
		     status_to_string(d->owl_threat_status));
	  gtp_mprintf("owl_attack              %m\n", 
		      I(d->owl_attack_point), J(d->owl_attack_point));
	  gtp_printf("owl_attack_certain:     %s\n",   
		     (d->owl_attack_certain) ? "YES" : "NO");
	  gtp_mprintf("owl_2nd_attack          %m\n", 
		      I(d->owl_second_attack_point), 
		      J(d->owl_second_attack_point));
	  gtp_mprintf("owl_defend              %m\n", 
		      I(d->owl_defense_point), J(d->owl_defense_point));
	  gtp_printf("owl_defense_certain:     %s\n",   
		     (d->owl_defense_certain) ? "YES" : "NO");
	  gtp_mprintf("owl_2nd_defend          %m\n", 
		      I(d->owl_second_defense_point), 
		      J(d->owl_second_defense_point));
	  gtp_printf("semeai                  %d\n",   
		     d2->semeai);
	  gtp_printf("semeai_margin_of_safety %d\n",   
		     d2->semeai_margin_of_safety);
	  gtp_printf("neighbors:              ");
	  for (k = 0; k < DRAGON2(POS(m, n)).neighbors; k++)
	    gtp_mprintf("%m ", 
			I(DRAGON(DRAGON2(POS(m, n)).adjacent[k]).origin),
			J(DRAGON(DRAGON2(POS(m, n)).adjacent[k]).origin));
	  gtp_printf("\n");
	  gtp_printf("moyo:                   %d\n", DRAGON2(POS(m, n)).moyo);
	  gtp_printf("safety:                 %s\n", 
		     safety_to_string(DRAGON2(POS(m, n)).safety));
	  gtp_printf("strings: ");
	  for (ti = 0; ti < board_size; ti++)
	    for (tj = 0; tj < board_size; tj++)
	      if (worm[POS(ti, tj)].origin == POS(ti, tj)
		  && dragon[POS(ti, tj)].origin == dragon[POS(m, n)].origin)
		gtp_mprintf("%m ", ti, tj);
	  gtp_printf("\n");
	}
  }
  gtp_printf("\n");
  return GTP_OK;
}


/* Function:  List the stones of a dragon
 * Arguments: the location
 * Fails:     if called on an empty or off-board location
 * Returns:   list of stones
 */
static int
gtp_dragon_stones(char *s, int id)
{
  int i = -1;
  int j = -1;
  int color = EMPTY;
  int m, n;
  int u, v;

  if (sscanf(s, "%*c") >= 0) {
    if (!gtp_decode_coord(s, &i, &j)
	&& !gtp_decode_color(s, &color))
    return gtp_failure(id, "invalid coordinate");
  }

  if (BOARD(i, j) == EMPTY)
    return gtp_failure(id, "dragon_stones called on an empty vertex");

  examine_position(EMPTY, EXAMINE_DRAGONS);

  gtp_printid(id, GTP_SUCCESS);

  
  for (u = 0; u < board_size; u++)
    for (v = 0; v < board_size; v++) {
      if (BOARD(u, v) == EMPTY
	  || (color != EMPTY && BOARD(u, v) != color))
	continue;
      if (dragon[POS(u, v)].origin != POS(u, v))
	continue;
      if (ON_BOARD2(i, j) && dragon[POS(i, j)].origin != POS(u, v))
	continue;
      for (m = 0; m < board_size; m++)
	for (n = 0; n < board_size; n++)
	  if (dragon[POS(m, n)].origin == POS(u, v))
	    gtp_mprintf("%m ", m, n);
      gtp_printf("\n");
    }
  
  gtp_printf("\n");
  return GTP_OK;
}


static SGFTree gtp_sgftree;

/* Function:  Start storing moves executed during reading in an sgf
 *            tree in memory. 
 * Arguments: none
 * Fails:     never
 * Returns:   nothing
 *
 * Warning: You had better know what you're doing if you try to use this
 *          command.
 */
static int
gtp_start_sgftrace(char *s, int id)
{
  UNUSED(s);
  begin_sgftreedump(&gtp_sgftree);
  count_variations = 1;
  return gtp_success(id, "");
}


/* Function:  Finish storing moves in an sgf tree and write it to file. 
 * Arguments: filename
 * Fails:     never
 * Returns:   nothing
 *
 * Warning: You had better know what you're doing if you try to use this
 *          command.
 *
 * FIXME: We should free the memory from the sgf tree, now that we are
 *        done. This would be simpler if there were an sgftree
 *        function for this. (sgfFreeNode works on an sgfnode.)
 */
static int
gtp_finish_sgftrace(char *s, int id)
{
  char filename[GTP_BUFSIZE];
  int nread;
  
  nread = sscanf(s, "%s", filename);
  if (nread < 1)
    return gtp_failure(id, "missing filename");

  end_sgftreedump(filename);
  count_variations = 0;
  return gtp_success(id, "");
}


/* Function:  Tune the parameters for the move ordering in the tactical
 *            reading.
 * Arguments: MOVE_ORDERING_PARAMETERS integers
 * Fails:     incorrect arguments
 * Returns:   nothing
 */
static int
gtp_tune_move_ordering(char *s, int id)
{
  int params[MOVE_ORDERING_PARAMETERS];
  int k;
  int p;
  int n;

  for (k = 0; k < MOVE_ORDERING_PARAMETERS; k++) {
    if (sscanf(s, "%d%n", &p, &n) == 0)
      return gtp_failure(id, "incorrect arguments, expected %d integers",
			 MOVE_ORDERING_PARAMETERS);
    params[k] = p;
    s += n;
  }

  tune_move_ordering(params);
  return gtp_success(id, "");
}

/* Function:  Echo the parameter
 * Arguments: string
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_echo(char *s, int id)
{
  return gtp_success(id, "%s", s);
}


/* Function:  Echo the parameter to stdout AND stderr
 * Arguments: string
 * Fails:     never
 * Returns:   nothing
 */
static int
gtp_echo_err(char *s, int id)
{
  fprintf(stderr, "%s", s);
  fflush(stdout);
  fflush(stderr);
  return gtp_success(id, "%s", s);
}

/* Function:  List all known commands
 * Arguments: none
 * Fails:     never
 * Returns:   list of known commands, one per line
 */
static int
gtp_help(char *s, int id)
{
  int k;
  UNUSED(s);

  gtp_printid(id, GTP_SUCCESS);

  for (k = 0; commands[k].name != NULL; k++)
    gtp_printf("%s\n", commands[k].name);

  gtp_printf("\n");
  return GTP_OK;
}


/* Function:  Turn uncertainty reports from owl_attack
 *            and owl_defend on or off.
 * Arguments: "on" or "off"
 * Fails:     invalid argument
 * Returns:   nothing
 */
static int
gtp_report_uncertainty(char *s, int id)
{
  if (!strncmp(s, "on", 2)) {
    report_uncertainty = 1;
    return gtp_success(id, "");
  }
  if (!strncmp(s, "off", 3)) {
    report_uncertainty = 0;
    return gtp_success(id, "");
  }
  return gtp_failure(id, "invalid argument");
}
    

static void
gtp_print_code(int c)
{
  gtp_printf("%d", c ? 4-c : c);
}

static void
gtp_print_vertices2(int n, int *moves)
{
  int movei[MAX_BOARD * MAX_BOARD];
  int movej[MAX_BOARD * MAX_BOARD];
  int k;

  for (k = 0; k < n; k++) {
    movei[k] = I(moves[k]);
    movej[k] = J(moves[k]);
  }
  
  gtp_print_vertices(n, movei, movej);
}

/*************
 * transform *
 *************/

static void
rotate_on_input(int ai, int aj, int *bi, int *bj)
{
  rotate(ai, aj, bi, bj, board_size, gtp_orientation);
}

static void
rotate_on_output(int ai, int aj, int *bi, int *bj)
{
  inv_rotate(ai, aj, bi, bj, board_size, gtp_orientation);
}


/***************
 * random seed *
 ***************/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Get the random seed
 * Arguments: none
 * Fails:     never
 * Returns:   random seed
 */
static int
gtp_get_random_seed(char *s, int id)
{

  UNUSED(s);

  return gtp_success(id, "%d", random_seed);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Function:  Set the random seed
 * Arguments: integer
 * Fails:     invalid data
 * Returns:   nothing
 */
static int
gtp_set_random_seed (char *s, int id)
{
  int seed;
  if (sscanf(s, "%d", &seed) < 1)
    return gtp_failure (id, "invalid seed");
  
  random_seed = seed;
  return gtp_success (id, "");
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* emgena ==================================================================*/

/* emgena - play_gmp.c */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * This is GNU GO, a Go program. Contact gnugo@gnu.org, or see       *
 * http://www.gnu.org/software/gnugo/ for more information.          *
 *                                                                   *
 * Copyright 1999, 2000, 2001, 2002 by the Free Software Foundation. *
 *                                                                   *
 * This program is free software; you can redistribute it and/or     *
 * modify it under the terms of the GNU General Public License as    *
 * published by the Free Software Foundation - version 2             *
 *                                                                   *
 * This program is distributed in the hope that it will be useful,   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of    *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     *
 * GNU General Public License in file COPYING for more details.      *
 *                                                                   *
 * You should have received a copy of the GNU General Public         *
 * License along with this program; if not, write to the Free        *
 * Software Foundation, Inc., 59 Temple Place - Suite 330,           *
 * Boston, MA 02111, USA.                                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <assert.h> */

/* #include "sgftree.h" */
/* #include "gnugo.h" */
/* #include "liberty.h" */

/* #include "interface.h" */
/* #include "gmp.h" */

/* #include "sgftree.h" */

/* --------------------------------------------------------------*/
/* Play a game against a go-modem-protocol (GMP) client.         */
/* --------------------------------------------------------------*/
void
play_gmp(Gameinfo *gameinfo)
{
  SGFTree sgftree;

  Gmp *ge;
  GmpResult message;
  const char *error;
  
  int i, j;
  int moveval;
  int passes = 0; /* two passes and its over */
  int to_move;  /* who's turn is next ? */

  int mycolor;  /* who has which color */
  int yourcolor;
  SGFNode *curnode = NULL; /* current SGFNode */
  
  mycolor = gameinfo->computer_player;

  sgftree_clear (&sgftree);
  sgftreeCreateHeaderNode (&sgftree, gnugo_get_boardsize(), gnugo_get_komi());

  yourcolor = OTHER_COLOR(mycolor);

  ge = gmp_create(0, 1);
  TRACE("board size=%d\n", gnugo_get_boardsize());

  curnode = sgftree.root;
  
  /* Leave all the -1's so the client can negotiate the game parameters. */
  if (chinese_rules)
    gmp_startGame (ge, -1, -1, 5.5, -1, -1);
  else
    gmp_startGame (ge, -1, -1, 5.5, 0, -1);	

  do {
    message = gmp_check (ge, 1, NULL, NULL, &error);
  } while (!time_to_die
	   && (message == gmp_nothing || message == gmp_reset));
  
  if (message == gmp_err)  {
    fprintf(stderr, "gnugo-gmp: Error \"%s\" occurred.\n", error);
    exit(1);
  }
  else if (message != gmp_newGame)  {
    fprintf (stderr, "gnugo-gmp: Expecting a newGame, got %s\n",
	    gmp_resultString (message));
    exit(1);
  }

  gameinfo->handicap = gmp_handicap (ge);
  gnugo_clear_board (gmp_size(ge));
  /* 
   * The specification of the go modem protocol doesn't even discuss
   * komi. So we have to guess the komi. If the komi is set on the
   * command line, keep it. Otherwise, its value will be 0.0 and we
   * use 5.5 in an even game, 0.5 otherwise.
   */
  if (gnugo_get_komi() == 0.0) {
    if (gameinfo->handicap == 0)
      gnugo_set_komi(5.5);
    else
      gnugo_set_komi(0.5);
  }

  sgfOverwritePropertyInt (sgftree.root, "SZ", gnugo_get_boardsize());

  TRACE("size=%d, handicap=%d, komi=%f\n", gnugo_get_boardsize(),
	gameinfo->handicap, gnugo_get_komi());

  if (gameinfo->handicap)
    to_move = WHITE;
  else
    to_move = BLACK;

  if (gmp_iAmWhite (ge)) {
    mycolor = WHITE;     /* computer white */
    yourcolor = BLACK;   /* human black */
  }
  else {
    mycolor = BLACK;
    yourcolor = WHITE;
  }

  gameinfo->computer_player = mycolor;
  sgffile_write_gameinfo (gameinfo, "gmp");
  gameinfo->handicap = gnugo_sethand (gameinfo->handicap, sgftree.root);
  sgfOverwritePropertyInt(sgftree.root, "HA", gameinfo->handicap);

  /* main GMP loop */
  while (passes < 2 && !time_to_die) {

    if (to_move == yourcolor) {
      /* ======================================================== */
      moveval = 0;
      /* Get opponent's move from gmp client. */
      message = gmp_check (ge, 1, &j, &i, &error);

      if (message == gmp_err) {
	fprintf(stderr, "GNU Go: Sorry, error from gmp client\n");
	sgffile_close_file();
	return;
      }

      if (message == gmp_undo) {
	int k;
	assert(j > 0);
	
	for (k = 0; k < j; k++) {
	  if (!gnugo_undo_move(1)) {
	    fprintf(stderr, "GNU Go: play_gmp UNDO: can't undo %d moves\n",
		    j - k);
	    break;
	  }
	  sgffile_write_comment("undo");
	  curnode = curnode->parent;
	  to_move = OTHER_COLOR(to_move);
	}
	continue;
      }

      if (message == gmp_pass) {
	++passes;
        curnode = sgfAddPlay (curnode, to_move, -1, -1);
	gnugo_play_move (-1, -1, yourcolor);
	sgffile_move_made (-1, -1, to_move, moveval);
      }
      else {
	/* not pass */
	passes = 0;
        curnode = sgfAddPlay (curnode, to_move, i, j);
	TRACE("\nyour move: %m\n\n", i, j);
	gnugo_play_move (i, j, yourcolor);
	sgffile_move_made (i, j, to_move, moveval);
      }

    }
    else { 
      /*============== Generate my next move ==================== */
      moveval = gnugo_genmove(&i, &j, mycolor);
      gnugo_play_move(i, j, mycolor);
      
      if (moveval < 0) {
	/* pass */
        curnode = sgfAddPlay(curnode, to_move, -1, -1);
	gmp_sendPass(ge);
	sgffile_move_made(-1, -1, to_move, moveval);
	++passes;
      }
      else {
	/* not pass */
        curnode = sgfAddPlay(curnode, to_move, i, j);
	gmp_sendMove(ge, j, i);
	sgffile_move_made(i, j, to_move, moveval);
	passes = 0;
	TRACE("\nmy move: %m\n\n", i, j);
      }
    } /* ======================================================== */
    
    to_move = OTHER_COLOR (to_move);
  }
  
  /* two passes: game over */
  gmp_sendPass (ge);   
  
  /* We hang around here until cgoban asks us to go, since
   * sometimes cgoban crashes if we exit first.
   */
  
  if (!quiet)
    fprintf(stderr, "Game over - waiting for client to shut us down\n");

  sgffile_close_file ();
  who_wins (mycolor, stderr);
    
  /* play_gmp() does not return to main(), therefore the score
   * writing code is here.
   */
  score = gnugo_estimate_score (&lower_bound, &upper_bound);

  sgfWriteResult (sgftree.root, score, 1);
  
  while (!time_to_die) {
    message = gmp_check(ge, 1, &j, &i, &error);
    if (!quiet)
      fprintf(stderr, "Message %d from gmp\n", message);
    if (message == gmp_err)
      break;
  }
  if (!quiet)
    fprintf(stderr, "gnugo going down\n");
}
/* emgena ==================================================================*/
/* emgena - play_ascii.c */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * This is GNU GO, a Go program. Contact gnugo@gnu.org, or see       *
 * http://www.gnu.org/software/gnugo/ for more information.          *
 *                                                                   *
 * Copyright 1999, 2000, 2001, 2002 by the Free Software Foundation. *
 *                                                                   *
 * This program is free software; you can redistribute it and/or     *
 * modify it under the terms of the GNU General Public License as    *
 * published by the Free Software Foundation - version 2             *
 *                                                                   *
 * This program is distributed in the hope that it will be useful,   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of    *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     *
 * GNU General Public License in file COPYING for more details.      *
 *                                                                   *
 * You should have received a copy of the GNU General Public         *
 * License along with this program; if not, write to the Free        *
 * Software Foundation, Inc., 59 Temple Place - Suite 330,           *
 * Boston, MA 02111, USA.                                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <string.h> */
/* #include <assert.h> */
/* #include <ctype.h> */

/* #include "sgftree.h" */
/* #include "gnugo.h" */
/* #include "liberty.h" */

/* #include "interface.h" */


#define DEBUG_COMMANDS "\
capture <pos>    try to capture indicated group\n\
dead             Toggle display of dead stones\n\
defend <pos>     try to defend indicated group\n\
listdragons      print dragon info \n\
showarea         display area\n\
showdragons      display dragons\n\
showmoyo         display moyo\n\
showterri        display territory\n\
"

/* some options for the ascii interface */
static int opt_showboard = 1;
static int showdead = 0;
static int emacs = 0;
SGFTree sgftree;
SGFNode *curnode = 0;
static int last_move_i;      /* The position of the last move */
static int last_move_j;      /* -""-                          */

/* Unreasonable score used to detect missing information. */
#define NO_SCORE 4711
/* Keep track of the score estimated before the last computer move. */
static int current_score_estimate = NO_SCORE;

static void endgame(Gameinfo *gameinfo);
static void showcapture(char *line);
static void showdefense(char *line);
static void ascii_goto(Gameinfo *gameinfo, char *line);
static int ascii2pos(char *line, int *i, int *j);

/* If sgf game info is written can't reset parameters like handicap, etc. */
static int sgf_initialized = 0;

/*
 * Create letterbar for the top and bottom of the ASCII board.
 */

static void
make_letterbar(int boardsize, char *letterbar)
{
  int i, letteroffset;
  char spaces[64];
  char letter[64];

  if (boardsize <= 25)
    strcpy(spaces, " ");
  strcpy(letterbar, "   ");
  
  for (i = 0; i < boardsize; i++) {
    letteroffset = 'A';
    if (i+letteroffset >= 'I')
      letteroffset++;
    strcat(letterbar, spaces);
    sprintf(letter, "%c", i+letteroffset);
    strcat(letterbar, letter);
  }
}


/* This array contains +'s and -'s for the empty board positions.
 * hspot_size contains the board size that the grid has been
 * initialized to.
 */

static int hspot_size;
static char hspots[MAX_BOARD][MAX_BOARD];


/*
 * Mark the handicap spots on the board.
 */

static void
set_handicap_spots(int boardsize)
{
  if (hspot_size == boardsize)
    return;
  
  hspot_size = boardsize;
  
  memset(hspots, '.', sizeof(hspots));

  /* small sizes are easier to hardwire... */
  if (boardsize == 2 || boardsize == 4)
    return;
  if (boardsize == 3) {
    /* just the middle one */
    hspots[boardsize/2][boardsize/2] = '+';
    return;
  }
  if (boardsize == 5) {
    /* place the outer 4 */
    hspots[1][1] = '+';
    hspots[boardsize-2][1] = '+';
    hspots[1][boardsize-2] = '+';
    hspots[boardsize-2][boardsize-2] = '+';
    /* and the middle one */
    hspots[boardsize/2][boardsize/2] = '+';
    return;
  }

  if (!(boardsize%2)) {
    /* If the board size is even, no center handicap spots. */
    if (boardsize > 2 && boardsize < 12) {
      /* Place the outer 4 only. */
      hspots[2][2] = '+';
      hspots[boardsize-3][2] = '+';
      hspots[2][boardsize-3] = '+';
      hspots[boardsize-3][boardsize-3] = '+';
    }
    else {
      /* Place the outer 4 only. */
      hspots[3][3] = '+';
      hspots[boardsize-4][3] = '+';
      hspots[3][boardsize-4] = '+';
      hspots[boardsize-4][boardsize-4] = '+';
    }
  }
  else {
    /* Uneven board size */
    if (boardsize > 2 && boardsize < 12) {
      /* Place the outer 4... */
      hspots[2][2] = '+';
      hspots[boardsize-3][2] = '+';
      hspots[2][boardsize-3] = '+';
      hspots[boardsize-3][boardsize-3] = '+';

      /* ...and the middle one. */
      hspots[boardsize/2][boardsize/2] = '+';
    }
    else {
      /* Place the outer 4... */
      hspots[3][3] = '+';
      hspots[boardsize-4][3] = '+';
      hspots[3][boardsize-4] = '+';
      hspots[boardsize-4][boardsize-4] = '+';

      /* ...and the inner 4... */
      hspots[3][boardsize/2] = '+';
      hspots[boardsize/2][3] = '+';
      hspots[boardsize/2][boardsize-4] = '+';
      hspots[boardsize-4][boardsize/2] = '+';

      /* ...and the middle one. */
      hspots[boardsize/2][boardsize/2] = '+';
    }
  }

  return;
}


/*
 * Display the board position when playing in ASCII.
 */

static void
ascii_showboard(void)
{
  int i, j;
  char letterbar[64];
  int last_pos_was_move;
  int pos_is_move;
  int dead;
  
  make_letterbar(board_size, letterbar);
  set_handicap_spots(board_size);

  printf("\n");
  printf("    White has captured %d pieces\n", black_captured);
  printf("    Black has captured %d pieces\n", white_captured);
  if (showscore) {
    if (current_score_estimate == NO_SCORE)
      printf("    No score estimate is available yet.\n");
    else if (current_score_estimate < 0)
      printf("    Estimated score: Black is ahead by %d\n",
	     -current_score_estimate);
    else if (current_score_estimate > 0)
      printf("    Estimated score: White is ahead by %d\n",
	     current_score_estimate);
    else
      printf("    Estimated score: Even!\n");
  }
   
  printf("\n");

  fflush(stdout);
  printf("%s%s\n", (emacs ? "EMACS1\n" : ""), letterbar);
  fflush(stdout);
  
  for (i = 0; i < board_size; i++) {
    printf(" %2d", board_size - i);
    last_pos_was_move = 0;
    for (j = 0; j < board_size; j++) {
      if (last_move_i == i && last_move_j == j)
	pos_is_move = 128;
      else
	pos_is_move = 0;
      dead = (matcher_status(POS(i, j))==DEAD) && showdead;
      switch (BOARD(i, j) + pos_is_move + last_pos_was_move) {
	case EMPTY+128:
	case EMPTY:
	  printf(" %c", hspots[i][j]);
	  last_pos_was_move = 0;
	  break;
	case BLACK:
	  printf(" %c", dead ? 'x' : 'X');
	  last_pos_was_move = 0;
	  break;
	case WHITE:
	  printf(" %c", dead ? 'o' : 'O');
	  last_pos_was_move = 0;
	  break;
	case BLACK+128:
	  printf("(%c)", 'X');
	  last_pos_was_move = 256;
	  break;
	case WHITE+128:
	  printf("(%c)", 'O');
	  last_pos_was_move = 256;
	  break;
	case EMPTY+256:
	  printf("%c", hspots[i][j]);
	  last_pos_was_move = 0;
	  break;
	case BLACK+256:
	  printf("%c", dead ? 'x' : 'X');
	  last_pos_was_move = 0;
	  break;
	case WHITE+256:
	  printf("%c", dead ? 'o' : 'O');
	  last_pos_was_move = 0;
	  break;
	default: 
	  fprintf(stderr, "Illegal board value %d\n", BOARD(i, j));
	  exit(EXIT_FAILURE);
	  break;
      }
    }
    
    if (last_pos_was_move == 0) {
      if (board_size > 10)
	printf(" %2d", board_size - i);
      else
	printf(" %1d", board_size - i);
    }
    else {
      if (board_size > 10)
	printf("%2d", board_size - i);
      else
	printf("%1d", board_size - i);
    }
    printf("\n");
  }
  
  fflush(stdout);
  printf("%s\n\n", letterbar);
  fflush(stdout);
  
}  /* end ascii_showboard */

/*
 * command help
 */

static void
show_commands(void)
{
  printf("\nCommands:\n");
  printf(" back             Take back your last move\n");
  printf(" boardsize        Set boardsize (on move 1 only!)\n");
  printf(" comment          Write a comment to outputfile\n");
  printf(" depth <num>      Set depth for reading\n");
  printf(" display          Display game board\n");
  printf(" exit             Exit GNU Go\n");
  printf(" force <move>     Force a move for current color\n");
  printf(" forward          Go to next node in game tree\n");
  printf(" goto <movenum>   Go to movenum in game tree\n");
  printf(" level <amount>   Playing level (default = 10)\n");
  printf(" handicap         Set handicap (on move 1 only!)\n");
  printf(" help             Display this help menu\n");
  printf(" helpdebug        Display debug help menu\n");
  printf(" info             Display program settings\n");
  printf(" komi             Set komi (on move 1 only!)\n");
  printf(" last             Goto last node in game tree\n");
  printf(" pass             Pass on your move\n");
  printf(" play <num>       Play <num> moves\n");
  printf(" playblack        Play as Black (switch if White)\n");
  printf(" playwhite        Play as White (switch if Black)\n");
  printf(" quit             Exit GNU Go\n");
  printf(" resign           Resign the current game\n");
  printf(" save <file>      Save the current game\n");
  printf(" load <file>      Load a game from file\n");
  printf(" score            Toggle display of score On/Off\n");
  printf(" showboard        Toggle display of board On/Off\n");
  printf(" switch           Switch the color you are playing\n");
  printf(" undo             Take the last move back (same as back)\n");
  printf(" <move>           A move of the format <letter><number>");
  printf("\n");
}

enum commands {INVALID=-1, END, EXIT, QUIT, RESIGN, 
	       PASS, MOVE, FORCE, SWITCH,
	       PLAY, PLAYBLACK, PLAYWHITE,
	       SETHANDICAP, SETBOARDSIZE, SETKOMI,
	       SETDEPTH,
               INFO, DISPLAY, SHOWBOARD, HELP, UNDO, COMMENT, SCORE,
               CMD_DEAD, CMD_BACK, CMD_FORWARD, CMD_LAST,
               CMD_CAPTURE, CMD_DEFEND,
               CMD_HELPDEBUG, CMD_SHOWAREA, CMD_SHOWMOYO, CMD_SHOWTERRI,
               CMD_GOTO, CMD_SAVE, CMD_LOAD, CMD_SHOWDRAGONS, CMD_LISTDRAGONS,
	       SETHURRY, SETLEVEL, NEW, COUNT
};


/*
 * Check if we have a valid command.
 */

static int
get_command(char *command)
{
  char c;
  int d;

  /* Check to see if a move was input. */
  if (!((sscanf(command, "%c%d", &c, &d) != 2)
	|| ((c = toupper((int) c)) < 'A')
	|| ((c = toupper((int) c)) > 'Z')
	|| (c == 'I')))
    return MOVE;

  /* help shortcut */
  if (command[0] == '?')
    return HELP;

  /* Kill leading spaces. */
  while (command[0] == ' ')
    command++;

  if (!strncmp(command, "playblack", 9)) return PLAYBLACK;
  if (!strncmp(command, "playwhite", 9)) return PLAYWHITE;
  if (!strncmp(command, "showboard", 9)) return SHOWBOARD;
  if (!strncmp(command, "showdragons", 9)) return CMD_SHOWDRAGONS;
  if (!strncmp(command, "listdragons", 9)) return CMD_LISTDRAGONS;
  if (!strncmp(command, "boardsize", 9)) return SETBOARDSIZE;
  if (!strncmp(command, "handicap", 8)) return SETHANDICAP;
  if (!strncmp(command, "display", 7)) return DISPLAY;
  if (!strncmp(command, "helpdebug", 7)) return CMD_HELPDEBUG;
  if (!strncmp(command, "resign", 6)) return RESIGN;
  if (!strncmp(command, "showmoyo", 6)) return CMD_SHOWMOYO;
  if (!strncmp(command, "showterri", 6)) return CMD_SHOWTERRI;
  if (!strncmp(command, "showarea", 6)) return CMD_SHOWAREA;
  if (!strncmp(command, "depth", 5)) return SETDEPTH;
  if (!strncmp(command, "switch", 5)) return SWITCH;
  if (!strncmp(command, "komi", 4)) return SETKOMI;
  if (!strncmp(command, "play", 4)) return PLAY;
  if (!strncmp(command, "info", 4)) return INFO;
  if (!strncmp(command, "force", 4)) return FORCE;
  if (!strncmp(command, "hurry", 5)) return SETHURRY;
  if (!strncmp(command, "level", 5)) return SETLEVEL;
  if (!strncmp(command, "pass", 4)) return PASS;
  if (!strncmp(command, "save", 3)) return CMD_SAVE;
  if (!strncmp(command, "load", 3)) return CMD_LOAD;
  if (!strncmp(command, "end", 3)) return END;
  if (!strncmp(command, "move", 3)) return MOVE;
  if (!strncmp(command, "undo", 3)) return UNDO;
  if (!strncmp(command, "comment", 3)) return COMMENT;
  if (!strncmp(command, "score", 3)) return SCORE;
  if (!strncmp(command, "dead", 3)) return CMD_DEAD;
  if (!strncmp(command, "capture", 3)) return CMD_CAPTURE;
  if (!strncmp(command, "defend", 3)) return CMD_DEFEND;
  if (!strncmp(command, "exit", 4)) return EXIT;
  if (!strncmp(command, "quit", 4)) return QUIT;
  if (!strncmp(command, "help", 1)) return HELP;
  if (!strncmp(command, "back", 2)) return CMD_BACK;
  if (!strncmp(command, "forward", 2)) return CMD_FORWARD;
  if (!strncmp(command, "last", 2)) return CMD_LAST;
  if (!strncmp(command, "goto", 2)) return CMD_GOTO;
  if (!strncmp(command, "game", 2)) return NEW;
  if (!strncmp(command, "count", 2)) return COUNT;

  /* No valid command was found. */
  return INVALID;
}


/*
 * Write sgf root node. 
 */

static void
init_sgf(Gameinfo *ginfo, SGFNode *root)
{
  if (sgf_initialized)
    return;
  sgf_initialized = 1;

  sgffile_write_gameinfo(ginfo, "ascii");
  if (ginfo->handicap > 0)
    gnugo_recordboard(root);
  else
    ginfo->to_move = BLACK;
}


/*
 * Generate the computer move. 
 */

static void
computer_move (Gameinfo *gameinfo, int *passes)
{
  int i, j;
  int move_val;

  init_sgf(gameinfo, sgftree.root);
  
  /* Generate computer move. */
  move_val = gnugo_genmove(&i, &j, gameinfo->to_move);
  if (showscore) {
    gnugo_estimate_score(&lower_bound, &upper_bound);
    current_score_estimate = (int) ((lower_bound + upper_bound) / 2.0);
  }
    
  last_move_i = i;
  last_move_j = j;
  
  mprintf("%s(%d): %m\n", color_to_string(gameinfo->to_move), movenum+1, i, j);
  if (is_pass(POS(i, j)))
    (*passes)++;
  else
    *passes = 0;

  gnugo_play_move(i, j, gameinfo->to_move);
  curnode = sgfAddPlay(curnode, gameinfo->to_move, i, j);

  sgffile_move_made(i, j, gameinfo->to_move, move_val);
  
  gameinfo->to_move = OTHER_COLOR(gameinfo->to_move);
}


/*
 * Make a move.
 */

static void
do_move(Gameinfo *gameinfo, char *command, int *passes, int force)
{
  int i, j;

  if (!ascii2pos(command, &i, &j)) {
    printf("\nInvalid move: %s\n", command);
    return;
  }
  
  if (!gnugo_is_legal(i, j, gameinfo->to_move)) {
    printf("\nIllegal move: %s", command);
    return;
  }

  *passes = 0;
  TRACE("\nyour move: %m\n\n", i, j);
  gnugo_play_move(i, j, gameinfo->to_move);
  /* FIXME: This call to init_sgf should not be here. */
  init_sgf(gameinfo, sgftree.root);
  sgffile_move_made(i, j, gameinfo->to_move, 0);
  curnode = sgfAddPlay(curnode, gameinfo->to_move, i, j);

  last_move_i = i;
  last_move_j = j;
  
  if (opt_showboard && !emacs) {
    ascii_showboard();
    printf("GNU Go is thinking...\n");
  }
  if (force) {
    gameinfo->computer_player = OTHER_COLOR(gameinfo->computer_player);
    gameinfo->to_move = OTHER_COLOR(gameinfo->to_move);
    return;
  }
  gameinfo->to_move = OTHER_COLOR(gameinfo->to_move);
  computer_move(gameinfo, passes);
}


/*
 * Make a pass.
 */

static void
do_pass(Gameinfo *gameinfo, int *passes, int force)
{
  (*passes)++;
  gnugo_play_move(-1, -1, gameinfo->to_move);
  init_sgf(gameinfo, sgftree.root);
  sgffile_move_made(-1, -1, gameinfo->to_move, 0);
  curnode = sgfAddPlay(curnode, gameinfo->to_move, -1, -1);

  gameinfo->to_move = OTHER_COLOR(gameinfo->to_move);
  if (force) {
    gameinfo->computer_player = OTHER_COLOR(gameinfo->computer_player);
    return;
  }
  computer_move(gameinfo, passes);
}
/*----------------------------------------------------------------------------*/
/*   Play a game against an ascii client                                      */
/*----------------------------------------------------------------------------*/
void
play_ascii (SGFTree *tree, Gameinfo *gameinfo, char *filename, char *until)
{
  int   m, num;
  int   sz = 0;
  float fnum;
  int   passes = 0;  /* two passes and its over */
  int   tmp;
  char  line[80];
  char *line_ptr = line;
  char *command;
  char *tmpstring;
  int   state = 1;
  

/* emgena */
#undef HAVE_SETLINEBUF
/* emgena */
#ifdef HAVE_SETLINEBUF
  setlinebuf(stdout); /* Need at least line buffer gnugo-gnugo */
#else
  setbuf(stdout, NULL); /* else set it to completely UNBUFFERED */
#endif
  
  while (state == 1) {

    sgftree = *tree;
    
    /* No score is estimated yet. */
    current_score_estimate = NO_SCORE;
    
    if (filename) {
      gameinfo_load_sgfheader(gameinfo, sgftree.root);
      sgffile_write_gameinfo(gameinfo, "ascii");
      gameinfo->to_move = gameinfo_play_sgftree(gameinfo, sgftree.root, until);
      sgfOverwritePropertyInt(sgftree.root, "HA", gameinfo->handicap);
      sgf_initialized = 1;
      curnode = sgftreeNodeCheck(&sgftree, 0);
    }
    else {
      if (sz)
	sgfOverwritePropertyInt(sgftree.root, "SZ", sz);
      if (sgfGetIntProperty(sgftree.root, "SZ", &sz)) 
	gnugo_clear_board(sz);
      if (gameinfo->handicap == 0)
	gameinfo->to_move = BLACK;
      else {
	gameinfo->handicap = gnugo_placehand(gameinfo->handicap);
	sgfOverwritePropertyInt(sgftree.root, "HA", gameinfo->handicap);
	gameinfo->to_move = WHITE;
      }
      
      curnode = sgftree.root;
    }
    
    printf("\nBeginning ASCII mode game.\n\n");
    gameinfo_print (gameinfo);
    
    /* Does the computer play first?  If so, make a move. */
    if (gameinfo->computer_player == gameinfo->to_move)
      computer_move(gameinfo, &passes);
    
    /* main ASCII Play loop */
    while (passes < 2 && !time_to_die) {
      /* Display game board. */
      if (opt_showboard)
	ascii_showboard();
      
      /* Print the prompt */
      mprintf("%s(%d): ", color_to_string(gameinfo->to_move), movenum + 1);

      /* Read a line of input. */
      line_ptr = line;
      if (!fgets(line, 80, stdin)) {
	printf("\nThanks! for playing GNU Go.\n\n");
	return ;
      }      
      while (command = strtok (line_ptr, ";"), line_ptr = 0, command) {
	
	/* Get the command or move. */
	switch (get_command (command)) {
	case RESIGN:
	  printf("\nGNU Go wins by resignation.");
	  sgftreeWriteResult(&sgftree,
			     gameinfo->to_move == WHITE ? -1000.0 : 1000.0,
			     1);
	case END:
	case EXIT:
	case QUIT:
	  printf("\nThanks! for playing GNU Go.\n\n");
	  return ;
	  break;
	case HELP:
	  show_commands();
	  break;
	case CMD_HELPDEBUG:
	  printf(DEBUG_COMMANDS);
	  break;
	case SHOWBOARD:
	  opt_showboard = !opt_showboard;
	  break;
	case INFO:
	  printf("\n");
	  gameinfo_print(gameinfo);
	  break;
	case SETBOARDSIZE:
	  if (movenum > 0) {
	    printf("Boardsize can be modified on move 1 only!\n");
	    break;
	  }
	  if (sgf_initialized) {
	    printf("Boardsize cannot be changed after record is started!\n");
	    break;
	  }
	  command += 10;
	  if (sscanf(command, "%d", &num) != 1) {
	    printf("\nInvalid command syntax!\n");
	    break;
	  }
	  if (num < 2 || num > 25) {
	    printf("\nInvalid board size: %d\n", num);
	    break;
	  }
	  sz = num;
	  /* Init board. */
	  gnugo_clear_board(sz);
	  /* In case max handicap changes on smaller board. */
	  gameinfo->handicap = gnugo_placehand(gameinfo->handicap);
	  sgfOverwritePropertyInt(sgftree.root, "SZ", sz);
	  sgfOverwritePropertyInt(sgftree.root, "HA", gameinfo->handicap);
	  break;
	case SETHANDICAP:
	  if (movenum > 0) {
	    printf("Handicap can be modified on move 1 only!\n");
	    break;
	  }
	  if (sgf_initialized) {
	    printf("Handicap cannot be changed after game is started!\n");
	    break;
	  }
	  command += 9;
	  if (sscanf(command, "%d", &num) != 1) {
	    printf("\nInvalid command syntax!\n");
	    break;
	  }
	  if (num < 0 || num > MAX_HANDICAP) {
	    printf("\nInvalid handicap: %d\n", num);
	    break;
	  }
	  /* Init board. */
	  gnugo_clear_board(board_size);
	  /* Place stones on board but don't record sgf 
	   * in case we change more info. */
	  gameinfo->handicap = gnugo_placehand(num);
	  sgfOverwritePropertyInt(sgftree.root, "HA", gameinfo->handicap);
	  printf("\nSet handicap to %d\n", gameinfo->handicap);
	  gameinfo->to_move = WHITE;
	  break;
	case SETKOMI:
	  if (movenum > 0) {
	    printf("Komi can be modified on move 1 only!\n");
	    break;
	  }
	  if (sgf_initialized) {
	    printf("Komi cannot be modified after game record is started!\n");
	    break;
	  }
	  command += 5;
	  if (sscanf(command, "%f", &fnum) != 1) {
	    printf("\nInvalid command syntax!\n");
	    break;
	  }
	  komi = fnum;
	  printf("\nSet Komi to %.1f\n", komi);
	  break;
	case SETDEPTH:
	  {
	    command += 6;
	    if (sscanf(command, "%d", &num) != 1) {
	      printf("\nInvalid command syntax!\n");
	      break;
	    }
	    mandated_depth = num;
	    printf("\nSet depth to %d\n", mandated_depth);
	    break;
	  }
	case SETLEVEL:
	  {
	    command += 6;
	    if (sscanf(command, "%d", &num) != 1) {
	      printf("\nInvalid command syntax!\n");
	      break;
	    }
	    level = num;
	    printf("\nSet level to %d\n", level);
	    break;
	  }
	  /* Level replaces hurry as of 2.7.204. This option is retained
	   * for compatibility with gnugoclient. 
	   */
	case SETHURRY:
	  {
	    command += 6;
	    if (sscanf(command, "%d", &num) != 1) {
	      printf("\nInvalid command syntax!\n");
	      break;
	    }
	    level = 10 - num;
	    printf("\nSet hurry to %d\n", 10 - level);
	    break;
	  }
	case DISPLAY:
	  if (!opt_showboard)
	    ascii_showboard();
	  break;
	case FORCE:
	  command += 6; /* skip the force part... */
	  switch (get_command(command)) {
	  case MOVE:
	    do_move(gameinfo, command, &passes, 1);
	    break;
	  case PASS:
	    do_pass(gameinfo, &passes, 1);
	    break;
	  default:
	    printf("Illegal forced move: %s %d\n", command,
		   get_command(command));
	    break;
	  }
	  break;
	case MOVE:
	  do_move(gameinfo, command, &passes, 0);
	  break;
	case PASS:
	  do_pass(gameinfo, &passes, 0);
	  break;
	case PLAY:
	  command += 5;
	  if (sscanf(command, "%d", &num) != 1) {
	    printf("\nInvalid command syntax!\n");
	    break;
	  }
	  if (num >= 0)
	    for (m = 0; m < num; m++) {
	      gameinfo->computer_player 
		= OTHER_COLOR(gameinfo->computer_player);
	      computer_move(gameinfo, &passes);
	      if (passes >= 2)
		break;
	    }
	  else {
	    printf("\nInvalid number of moves specified: %d\n", num);
	    break;
	  }
	  break;
	case PLAYBLACK:
	  if (gameinfo->computer_player == WHITE)
	    gameinfo->computer_player = BLACK;
	  if (gameinfo->computer_player == gameinfo->to_move)
	    computer_move(gameinfo, &passes);
	  break;
	case PLAYWHITE:
	  if (gameinfo->computer_player == BLACK)
	    gameinfo->computer_player = WHITE;
	  if (gameinfo->computer_player == gameinfo->to_move)
	    computer_move(gameinfo, &passes);
	  break;
	case SWITCH:
	  gameinfo->computer_player = OTHER_COLOR(gameinfo->computer_player);
	  computer_move(gameinfo, &passes);
	  break;
	case UNDO:
	case CMD_BACK:
	  if (gnugo_undo_move(1)) {
	    sgffile_write_comment("undo");
	    curnode = curnode->parent;
	    gameinfo->to_move = OTHER_COLOR(gameinfo->to_move);
	  }
	  else
	    printf("\nCan't undo.\n");
	  break;
	case CMD_FORWARD:
	  if (curnode->child) {
	    gameinfo->to_move = gnugo_play_sgfnode(curnode->child,
						   gameinfo->to_move);
	    curnode = curnode->child;
	  }
	  else
	    printf("\nEnd of game tree.\n");
	  break;
	case CMD_LAST:
	  while (curnode->child) {
	    gameinfo->to_move = gnugo_play_sgfnode(curnode->child,
						   gameinfo->to_move);
	    curnode = curnode->child;
	  }
	  break;
	case COMMENT:
	  printf("\nEnter comment. Press ENTER when ready.\n");
	  fgets(line, 80, stdin);
	  sgfAddComment(curnode, line);
	  break;
	case SCORE:
	  showscore = !showscore;
	  if (!showscore)
	    current_score_estimate = NO_SCORE;
	  break;
	case CMD_DEAD:
	  showdead = !showdead;
	  break;
	case CMD_CAPTURE:
	  strtok(command, " ");
	  showcapture(strtok(NULL, " "));
	  break;
	case CMD_DEFEND:
	  strtok(command, " ");
	  showdefense(strtok(NULL, " "));
	  break;
	case CMD_SHOWMOYO:
	  tmp = printmoyo;
	  printmoyo = PRINTMOYO_MOYO;
	  examine_position(gameinfo->to_move, EXAMINE_DRAGONS);
	  print_moyo();
	  printmoyo = tmp;
	  break;
	case CMD_SHOWTERRI:
	  tmp = printmoyo;
	  printmoyo = PRINTMOYO_TERRITORY;
	  examine_position(gameinfo->to_move, EXAMINE_DRAGONS);
	  print_moyo();
	  printmoyo = tmp;
	  break;
	case CMD_SHOWAREA:
	  tmp = printmoyo;
	  printmoyo = PRINTMOYO_AREA;
	  examine_position(gameinfo->to_move, EXAMINE_DRAGONS);
	  print_moyo();
	  printmoyo = tmp;
	  break;
	case CMD_SHOWDRAGONS:
	  examine_position(gameinfo->to_move, EXAMINE_DRAGONS);
	  showboard(1);
	  break;
	case CMD_GOTO:
	  strtok(command, " ");
	  ascii_goto(gameinfo, strtok(NULL, " "));
	  break;
	case CMD_SAVE:
	  strtok(command, " ");
	  tmpstring = strtok(NULL, " ");
	  if (tmpstring) {
	    /* discard newline */
	    tmpstring[strlen(tmpstring)-1] = 0;
	    sgf_write_header(sgftree.root, 1, random_seed, komi, level);
	    writesgf(sgftree.root, tmpstring);
	    sgf_initialized = 0;
	    printf("You may resume the game");
	    printf(" with -l %s --mode ascii\n", tmpstring);
	    printf("or load %s\n", tmpstring);
	  }
	  else
	    printf("Please specify filename\n");
	  break;
	case CMD_LOAD:
	  strtok(command, " ");
	  tmpstring = strtok(NULL, " ");
	  if (tmpstring) {
	    /* discard newline */
	    tmpstring[strlen(tmpstring)-1] = 0;
	    if (!sgftree_readfile(&sgftree, tmpstring))
	      {
		fprintf(stderr, "Cannot open or parse '%s'\n", tmpstring);
		break;
	      }
	    sgf_initialized = 0;
	    gameinfo_play_sgftree(gameinfo, sgftree.root, NULL);
	    sgfOverwritePropertyInt(sgftree.root, "HA", gameinfo->handicap);
	  }
	  else
	    printf("Please specify a filename\n");
	  break;

	case CMD_LISTDRAGONS:
	  examine_position(gameinfo->to_move, EXAMINE_DRAGONS);
	  show_dragons();
	  break;
	case COUNT:
	case NEW:
	case INVALID:
	default:
	  printf("\nInvalid command: %s", command);
	  break;
	}
      }
    }
    
    /* two passes : game over */
    
    if (passes >= 2)
      gnugo_who_wins(gameinfo->computer_player, stdout);
    printf("\nIf you disagree, we may count the game together.\n");
    printf("You may optionally save the game as an SGF file.\n");
    state = 0;
    while (state == 0) {
      printf("\n\
Type \"save <filename>\" to save,\n\
     \"count\" to recount,\n\
     \"quit\" to quit\n\
 or  \"game\" to play again\n");
      line_ptr = line;
      if (!fgets(line, 80, stdin))
	break;
      command = strtok(line_ptr, "");
      switch (get_command(command)) {
      case CMD_SAVE:
	strtok(command, " ");
	tmpstring = strtok(NULL, " ");
	if (tmpstring) {
	  /* discard newline */
	  tmpstring[strlen(tmpstring)-1] = 0;
	  sgf_write_header(sgftree.root, 1, random_seed, komi, level);
	  writesgf(sgftree.root, tmpstring);
	    sgf_initialized = 0;
	}
	else
	  printf("Please specify filename\n");
	break;
	
      case NEW:
	state = 1;
	break;
	
      case COUNT:
	endgame(gameinfo);
	break;

      case QUIT:
	state = 2;
	break;
	
      default:
	state = 0;
      }
    }
    passes = 0;
    showdead = 0;
    sgf_initialized = 0;
    /* Play a different game next time. */
    update_random_seed();
  }
  printf("\nThanks for playing GNU Go.\n\n");
}

void
play_ascii_emacs(SGFTree *tree, Gameinfo *gameinfo,
		 char *filename, char *until)
{
  emacs = 1;
  play_ascii(tree, gameinfo, filename, until);
}
/*----------------------------------------------------------------------------*/
/*   endgame() scores the game                                                */
/*----------------------------------------------------------------------------*/
static void
endgame(Gameinfo *gameinfo)
{
  char line[12];
  int done = 0;
  int i, j;
  int xyzzy = 1;
  
  printf("\nGame over. Let's count!.\n");  
  showdead = 1;
  ascii_showboard();
  while (!done) {
    printf("Dead stones are marked with small letters (x,o).\n");
    printf("\nIf you don't agree, enter the location of a group\n\
to toggle its state or \"done\".\n");

    if (!fgets(line, 12, stdin))
      return; /* EOF or some error */
    
    for (i = 0; i < 12; i++)
      line[i] = (isupper ((int) line[i]) ? tolower ((int) line[i]) : line[i]);
    if (!strncmp(line, "done", 4))
      done = 1;
    else if (!strncmp(line, "quit", 4))
      return;
    else if (!strncmp(line, "xyzzy", 5)) {
      if (xyzzy) {
	printf("\nYou are in a debris room filled with stuff washed in from the\n");
	printf("surface.  A low wide passage with cobbles becomes plugged\n");
	printf("with mud and debris here, but an awkward canyon leads\n");
	printf("upward and west.  A note on the wall says:\n");
	printf("   Magic Word \"XYZZY\"\n\n");
	xyzzy = 0;
      }
      else {
	printf("You are inside a building, a well house for a large spring.\n\n");
	xyzzy = 1;
      }
    }
    else if (!strncmp(line, "help", 4)) {
      printf("\nIf there are dead stones on the board I will remove them.\n");
      printf("You must tell me where they are. Type the coordinates of a\n");
      printf("dead group, or type \"done\"\n");
    }      
    else if (!strncmp(line, "undo", 4)) {
      printf("UNDO not allowed anymore. The status of the stones now toggles after entering the location of it.\n");
      ascii_showboard();
    }
    else {
      if (!ascii2pos(line, &i, &j) || BOARD(i, j) == EMPTY)
	printf("\ninvalid!\n");
      else {
	int status = matcher_status(POS(i, j));
	status = (status == DEAD) ? ALIVE : DEAD;
	change_matcher_status(POS(i, j), status);
	ascii_showboard();
      }
    }
  }
  gnugo_who_wins(gameinfo->computer_player, stdout);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
static void
showcapture(char *line)
{
  int i, j, x, y;
  if (line)
    if (!ascii2pos(line, &i, &j) || BOARD(i, j) == EMPTY) {
      printf("\ninvalid point!\n");
      return;
    }
  if (gnugo_attack(i, j, &x, &y))
    mprintf("\nSuccessfull attack of %m at %m\n", i, j, x, y);
  else
    mprintf("\n%m cannot be attacked\n", i, j);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
static void
showdefense(char *line)
{
  int i, j, x, y;
  if (line)
    if (!ascii2pos(line, &i, &j) || BOARD(i, j) == EMPTY) {
      printf("\ninvalid point!\n");
      return;
    }

    if (gnugo_attack(i, j, &x, &y)) {
      if (gnugo_find_defense(i, j, &x, &y))
        mprintf("\nSuccessfull defense of %m at %m\n", i, j, x, y);
      else
        mprintf("\n%m cannot be defended\n", i, j);
    }
    else
      mprintf("\nThere is no need to defend %m\n", i, j);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
static void
ascii_goto(Gameinfo *gameinfo, char *line)
{
  int movenumber = 0;
  if (!line)
    return;
  if (!strncmp(line, "last", 4))
    movenumber = 9999;
  else {
    if (!strncmp(line, "first", 4))
      movenumber = 1;
    else
      sscanf(line, "%i", &movenumber);
  }
  printf("goto %i\n", movenumber);
  curnode = sgftree.root;
  gameinfo->to_move = gnugo_play_sgftree(curnode, &movenumber, &curnode);
  return;
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Convert a coordinate pair from ascii text to two integers.
 * FIXME: Check that this function is indeed equivalent to
 * string_to_location() and then replace it.
 */
static int
ascii2pos(char *line, int *i, int *j)
{
  int d;
  char c;
  if (sscanf(line, "%c%d", &c, &d) != 2)
    return 0;

  /* No 'I' in the coordinate system. */
  if (tolower((int) c) == 'i')
    return 0;
  
  *j = tolower((int) c) - 'a';
  if (tolower((int) c) > 'i')
    --*j;
  
  *i = board_size - d;

  if (*i < 0 || *i >= board_size || *j < 0 || *j >= board_size)
    return 0;
  
  return 1;
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* emgena - main.c */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
static void show_copyright(void);
static void show_version(void);
static void show_help(void);
static void show_debug_help(void);
static void show_debug_flags(void);

/* long options which have no short form */
enum {OPT_BOARDSIZE=127,
      OPT_HANDICAPSTONES,
      OPT_COLOR,
      OPT_KOMI,
      OPT_CLOCK_TIME,
      OPT_CLOCK_BYO_TIME,
      OPT_CLOCK_BYO_PERIOD,
      OPT_AUTOLEVEL,
      OPT_MODE,
      OPT_INFILE,
      OPT_OUTFILE, 
      OPT_QUIET,
      OPT_GTP_INPUT,
      OPT_GTP_INITIAL_ORIENTATION,
      OPT_SHOWCOPYRIGHT,
      OPT_REPLAY_GAME,
      OPT_DECIDE_STRING,
      OPT_DECIDE_CONNECTION,
      OPT_DECIDE_DRAGON,
      OPT_DECIDE_SEMEAI,
      OPT_DECIDE_TACTICAL_SEMEAI,
      OPT_EXPERIMENTAL_SEMEAI,
      OPT_SEMEAI_VARIATIONS,
      OPT_EXPERIMENTAL_CONNECTIONS,
      OPT_EXPERIMENTAL_INFLUENCE,
      OPT_ALTERNATE_CONNECTIONS,
      OPT_OPTIONS,
      OPT_STANDARD_SEMEAI,
      OPT_STANDARD_CONNECTIONS,
      OPT_STANDARD_INFLUENCE,
      OPT_DECIDE_POSITION,
      OPT_DECIDE_EYE,
      OPT_DECIDE_COMBINATION,
      OPT_BRANCH_DEPTH,
      OPT_BACKFILL2_DEPTH,
      OPT_SUPERSTRING_DEPTH,
      OPT_AA_DEPTH,
      OPT_DEBUG_FLAGS,
      OPT_OWL_DISTRUST,
      OPT_OWL_BRANCH,
      OPT_OWL_READING,
      OPT_OWL_NODE_LIMIT,
      OPT_LIFE,
      OPT_LIFE_EYESIZE,
      OPT_NOFUSEKIDB,
      OPT_NOFUSEKI,
      OPT_NOJOSEKIDB,
      OPT_LEVEL,
      OPT_SHOWTIME,
      OPT_SHOWSCORE,
      OPT_DEBUG_INFLUENCE,
      OPT_SCORE,
      OPT_PRINTSGF,
      OPT_PROFILE_PATTERNS,
      OPT_CHINESE_RULES,
      OPT_OWL_THREATS,
      OPT_NO_OWL_THREATS,
      OPT_JAPANESE_RULES,
      OPT_ALLOW_SUICIDE,
      OPT_CAPTURE_ALL_DEAD,
      OPT_PLAY_OUT_AFTERMATH,
      OPT_ATTACK_BY_PATTERN,
      OPT_DEFEND_BY_PATTERN
};

/* names of playing modes */

enum mode {
  MODE_UNKNOWN=0,
  MODE_ASCII,
  MODE_ASCII_EMACS,
  MODE_GTP,
  MODE_GMP,
  MODE_SGF,
  MODE_LOAD_AND_ANALYZE,
  MODE_LOAD_AND_SCORE,
  MODE_LOAD_AND_PRINT,
  MODE_SOLO,
  MODE_REPLAY,
  MODE_DECIDE_STRING,
  MODE_DECIDE_CONNECTION,
  MODE_DECIDE_DRAGON,
  MODE_DECIDE_SEMEAI,
  MODE_DECIDE_TACTICAL_SEMEAI,
  MODE_DECIDE_POSITION,
  MODE_DECIDE_EYE,
  MODE_DECIDE_COMBINATION
};


/* Definitions of the --long options. Final column is
 * either an OPT_ as defined in the enum above, or it
 * is the equivalent single-letter option.
 * It is useful to keep them in the same order as the
 * help string, for maintenance purposes only.
 */

static struct gg_option const long_options[] =
{
  {"mode",           required_argument, 0, OPT_MODE},
  {"replay",         required_argument, 0, OPT_REPLAY_GAME},
  {"quiet",          no_argument,       0, OPT_QUIET},
  {"silent",         no_argument,       0, OPT_QUIET},
  {"gtp-input",      required_argument, 0, OPT_GTP_INPUT},
  {"orientation",    required_argument, 0, OPT_GTP_INITIAL_ORIENTATION},
  {"gtp-initial-orientation",
  		     required_argument, 0, OPT_GTP_INITIAL_ORIENTATION},
  {"infile",         required_argument, 0, 'l'},
  {"until",          required_argument, 0, 'L'},
  {"outfile",        required_argument, 0, 'o'},
  {"boardsize",      required_argument, 0, OPT_BOARDSIZE},
  {"color",          required_argument, 0, OPT_COLOR},
  {"handicap",       required_argument, 0, OPT_HANDICAPSTONES},
  {"komi",           required_argument, 0, OPT_KOMI},
  {"help",           optional_argument, 0, 'h'},
  {"copyright",      no_argument,       0, OPT_SHOWCOPYRIGHT},
  {"version",        no_argument,       0, 'v'},
  {"allpats",        no_argument,       0, 'a'},
  {"printboard",     no_argument,       0, 'T'},
  {"debug",          required_argument, 0, 'd'},
  {"debug-flags",    no_argument,       0,  OPT_DEBUG_FLAGS},
  {"depth",          required_argument, 0, 'D'},
  {"backfill-depth", required_argument, 0, 'B'},
  {"branch-depth",   required_argument, 0, OPT_BRANCH_DEPTH},
  {"backfill2-depth",   required_argument, 0, OPT_BACKFILL2_DEPTH},
  {"superstring-depth", required_argument, 0, OPT_SUPERSTRING_DEPTH},
  {"fourlib-depth",  required_argument, 0, 'F'},
  {"ko-depth",       required_argument, 0, 'K'},
  {"aa-depth",       required_argument, 0, OPT_AA_DEPTH},
  {"owl-distrust",   required_argument, 0, OPT_OWL_DISTRUST},
  {"owl-branch",     required_argument, 0, OPT_OWL_BRANCH},
  {"owl-reading",    required_argument, 0, OPT_OWL_READING},
  {"owl-node-limit", required_argument, 0, OPT_OWL_NODE_LIMIT},
  {"level",          required_argument, 0, OPT_LEVEL},
  {"clock",          required_argument, 0, OPT_CLOCK_TIME},
  {"byo-time",       required_argument, 0, OPT_CLOCK_BYO_TIME},
  {"byo-period",     required_argument, 0, OPT_CLOCK_BYO_PERIOD},
  {"autolevel",      no_argument,       0, OPT_AUTOLEVEL},
  {"chinese-rules",  no_argument,       0, OPT_CHINESE_RULES},
  {"japanese-rules", no_argument,       0, OPT_JAPANESE_RULES},
  {"experimental-semeai",  no_argument, 0, OPT_EXPERIMENTAL_SEMEAI},
  {"semeai-variations",   required_argument, 0, OPT_SEMEAI_VARIATIONS},
  {"experimental-connections",  no_argument, 0, OPT_EXPERIMENTAL_CONNECTIONS},
  {"owl-threats",     no_argument,      0, OPT_OWL_THREATS},
  {"no-owl-threats",  no_argument,      0, OPT_NO_OWL_THREATS},
  {"experimental-influence",  no_argument, 0, OPT_EXPERIMENTAL_INFLUENCE},
  {"standard-influence",  no_argument, 0, OPT_STANDARD_INFLUENCE},
  {"standard-connections",  no_argument, 0, OPT_STANDARD_CONNECTIONS},
  {"standard_semeai", no_argument,      0, OPT_STANDARD_SEMEAI},
  {"alternate-connections",  no_argument, 0, OPT_ALTERNATE_CONNECTIONS},
  {"options",        no_argument, 0, OPT_OPTIONS},
  {"allow-suicide",  no_argument,       0, OPT_ALLOW_SUICIDE},
  {"capture-all-dead",   no_argument,   0, OPT_CAPTURE_ALL_DEAD},
  {"play-out-aftermath", no_argument,   0, OPT_PLAY_OUT_AFTERMATH},
  {"cache-size",     required_argument, 0, 'M'},
  {"hash",           required_argument, 0, 'H'},
  {"worms",          no_argument,       0, 'w'},
  {"moyo",           required_argument, 0, 'm'},
  {"benchmark",      required_argument, 0, 'b'},
  {"statistics",     no_argument,       0, 'S'},
  {"trace",          no_argument,       0, 't'},
  {"seed",           required_argument, 0, 'r'},
  {"decide-string",  required_argument, 0, OPT_DECIDE_STRING},
  {"decide-connection", required_argument, 0, OPT_DECIDE_CONNECTION},
  {"decide-dragon",  required_argument, 0, OPT_DECIDE_DRAGON},
  {"decide-semeai",  required_argument, 0, OPT_DECIDE_SEMEAI},
  {"decide-tactical-semeai", required_argument, 0, OPT_DECIDE_TACTICAL_SEMEAI},
  {"decide-position", no_argument,       0, OPT_DECIDE_POSITION},
  {"decide-eye",     required_argument, 0, OPT_DECIDE_EYE},
  {"decide-combination", no_argument,   0, OPT_DECIDE_COMBINATION},
  {"life",           no_argument,       0, OPT_LIFE},
  {"life-eyesize",   required_argument, 0, OPT_LIFE_EYESIZE},
  {"nofusekidb",     no_argument,       0, OPT_NOFUSEKIDB},
  {"nofuseki",       no_argument,         0, OPT_NOFUSEKI},
  {"nojosekidb",     no_argument,       0, OPT_NOJOSEKIDB},
  {"debug-influence", required_argument, 0, OPT_DEBUG_INFLUENCE},
  {"showtime",       no_argument,       0, OPT_SHOWTIME},
  {"showscore",      no_argument,       0, OPT_SHOWSCORE},
  {"score",          required_argument, 0, OPT_SCORE},
  {"printsgf",       required_argument, 0, OPT_PRINTSGF},
  {"profile-patterns", no_argument,     0, OPT_PROFILE_PATTERNS},
  {"attack-by-pattern", no_argument,    0, OPT_ATTACK_BY_PATTERN},
  {"defend-by-pattern", no_argument,    0, OPT_DEFEND_BY_PATTERN},
  {NULL, 0, NULL, 0}
};

float memory = (float) DEFAULT_MEMORY;	  /* Megabytes used for hash table. */

static void sigterm_handler(int);


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
int
main_gnugo (int argc, char *argv[])
{
  Gameinfo gameinfo;
  SGFTree sgftree;

  int i, umove;
  int mandated_color = EMPTY;
  enum mode playmode = MODE_UNKNOWN;
  int replay_color = EMPTY;
  
  char *infilename = NULL;
  char *untilstring = NULL;
  char *scoringmode = NULL;
  char *outfile = NULL;
  char *gtpfile = NULL;
  
  char *printsgffile = NULL;
  
  char decide_this[8];
  char *decide_that = NULL;
  char debuginfluence_move[4] = "\0";
  
  int benchmark = 0;  /* benchmarking mode (-b) */
  FILE *gtp_input_FILE;
  int orientation = 0;

  /* If seed is zero, GNU Go will play a different game each time. If
   * it is set using -r, GNU Go will play the same game each time.
   * (Change seed to get a different game).
   */
  int seed = 0;

  board_size = 19;
  komi = 0.0;
  
  /* Set SIGTERM handler. */
  signal(SIGTERM, sigterm_handler);

  level = DEFAULT_LEVEL;
  semeai_variations = DEFAULT_SEMEAI_VARIATIONS;

  mandated_depth               = -1;
  mandated_backfill_depth      = -1;
  mandated_backfill2_depth     = -1;
  mandated_superstring_depth   = -1;
  mandated_fourlib_depth       = -1;
  mandated_ko_depth            = -1;
  mandated_branch_depth        = -1;
  mandated_owl_distrust_depth  = -1;
  mandated_owl_branch_depth    = -1;
  mandated_owl_reading_depth   = -1;
  mandated_owl_node_limit      = -1;
  mandated_aa_depth            = -1;

  debug = 0;
  life  = 0;
  life_eyesize = LIFE_EYESIZE;

  fusekidb = 1;
  disable_fuseki = 0;
  josekidb = 1;

  if (CHINESE_RULES)  chinese_rules = 1;
  else                chinese_rules = 0;

  if (OWL_THREATS)    owl_threats = 1;
  else                owl_threats = 0;

  experimental_semeai      = EXPERIMENTAL_SEMEAI;
  experimental_connections = EXPERIMENTAL_CONNECTIONS;
  experimental_influence   = EXPERIMENTAL_INFLUENCE;

  allow_suicide = 0;
  capture_all_dead = 0;
  play_out_aftermath = 0;

  /* Default parameters for clock and auto level systems. */
  clock_init(3600, 0, 0);      /* One hour sudden death. */
  clock_init_autolevel(2, 10); /* 2 < level < 10 */

  sgftree_clear(&sgftree);
  gameinfo_clear(&gameinfo, board_size, komi);
  
  /* Set some standard options. */
  umove = BLACK;
  

  /* Now weed through all of the command line options. */
  while ((i = gg_getopt_long (argc, argv, 
			     "-ab:B:d:D:EF:gh::H:K:l:L:M:m:o:p:r:fsStTvw",
			     long_options, NULL)) != EOF)
    { 
      switch (i) {
      case 'T': printboard++; break;
      case 't': ++verbose; break;
      case 'a': allpats = 1; break;

      case  1 :
      case 'l': infilename = gg_optarg; 
	break;
	
      case 'b': benchmark = atoi(gg_optarg); playmode = MODE_SOLO; break;
      case 'r': seed = atoi(gg_optarg); break;
      case 'S': showstatistics = 1; break;
      case 'w': printworms = 1; break;
      case 'm': printmoyo = strtol(gg_optarg, NULL, 0);  /* allows 0x... */ break;
      case 'd': debug ^= strtol(gg_optarg, NULL, 0);  /* allows 0x... */ break;
      case 'D': mandated_depth = atoi(gg_optarg); break;

      case 'M': memory = atof(gg_optarg); break; /* floating point number */
      case 'H': hashflags = strtol(gg_optarg, NULL, 0);  /* allows 0x... */ break;

      case 'E': printboard = 2; break;
      case 'B': mandated_backfill_depth = atoi(gg_optarg); break;
      case 'F': mandated_fourlib_depth = atoi(gg_optarg); break;
      case 'K': mandated_ko_depth = atoi(gg_optarg); break;

      case 'L':
	untilstring = gg_optarg;
	break;
	
      case 'o':
	outfile = gg_optarg;
	strcpy(gameinfo.outfilename, gg_optarg);
	break;
	
      case OPT_QUIET:
	quiet = 1;
	break;
	
      case OPT_GTP_INPUT:
	gtpfile = gg_optarg;
	break;
	
      case OPT_GTP_INITIAL_ORIENTATION:
	orientation = atoi(gg_optarg);
	if (orientation < 0 || orientation > 7) {
	  fprintf(stderr, "Illegal orientation: %d.\n", orientation);
	  fprintf(stderr, "Try `gnugo --help' for more information.\n");
	  exit(EXIT_FAILURE);
	}
	break;
	
      case OPT_OPTIONS:
	if (EXPERIMENTAL_INFLUENCE)
	  fprintf(stderr,
		  "configure option enabled: experimental influence\n");
	if (EXPERIMENTAL_CONNECTIONS)
	  fprintf(stderr,
		  "configure option enabled: experimental connections\n");
	if (ALTERNATE_CONNECTIONS)
	  fprintf(stderr,
		  "configure option enabled: alternate connections\n");
	if (EXPERIMENTAL_SEMEAI)
	  fprintf(stderr,
		  "configure option enabled: experimental semeai\n");
	if (EXPERIMENTAL_READING)
	  fprintf(stderr,
		  "configure option enabled: experimental reading\n");
	if (HASHING_SCHEME != 2)
	  fprintf(stderr, "hash scheme %d\n", HASHING_SCHEME);
	if (OWL_THREATS)
	  fprintf(stderr,
		  "configure option enabled: owl threats\n");
	return EXIT_SUCCESS;
	break;

      case OPT_SHOWTIME:
	showtime = 1;
	break;
	
      case OPT_SHOWSCORE:
	showscore = 1;
	break;
	
      case OPT_HANDICAPSTONES:
	{
	  int handicap = atoi(gg_optarg);
	  
	  if (handicap < 0 || handicap > MAX_HANDICAP) {
	    fprintf(stderr, "Illegal handicap: %d.\n", handicap);
	    fprintf(stderr, "Try `gnugo --help' for more information.\n");
	    exit(EXIT_FAILURE);
	  }
	  gameinfo.handicap = handicap;
	}
        break;
      
      case OPT_BOARDSIZE:
        {
	  int boardsize = atoi(gg_optarg);
	  
	  if (boardsize < MIN_BOARD || boardsize > MAX_BOARD) {
	    fprintf(stderr, "Illegal board size: %d.\n", boardsize);
	    fprintf(stderr, "Try `gnugo --help' for more information.\n");
	    exit(EXIT_FAILURE);
	  }
	  gnugo_clear_board(boardsize);
	  break;
	}
	
      case OPT_KOMI: 
	if (sscanf(gg_optarg, "%f", &komi) != 1) {
	  fprintf(stderr, "Invalid komi selection: %s\n", gg_optarg);
	  fprintf(stderr, "Try `gnugo --help' for more information.\n");
	  exit(EXIT_FAILURE);
	}
	break;
	
      case OPT_CHINESE_RULES: 
	chinese_rules = 1;
	break;

      case OPT_OWL_THREATS: 
	owl_threats = 1;
	break;

      case OPT_NO_OWL_THREATS: 
	owl_threats = 0;
	break;

      case OPT_JAPANESE_RULES: 
	chinese_rules = 0;
	break;

      case OPT_EXPERIMENTAL_SEMEAI:
	experimental_semeai = 1;
	break;

      case OPT_SEMEAI_VARIATIONS:
	semeai_variations = atoi(gg_optarg);
	break;

      case OPT_STANDARD_SEMEAI: 
	experimental_semeai = 0;
	break;

      case OPT_EXPERIMENTAL_CONNECTIONS:
	experimental_connections = 1;
	break;

      case OPT_STANDARD_CONNECTIONS: 
	experimental_connections = 0;
	break;

      case OPT_ALTERNATE_CONNECTIONS: 
	alternate_connections = !alternate_connections;
	break;

      case OPT_EXPERIMENTAL_INFLUENCE:
	experimental_influence = 1;
	break;

      case OPT_STANDARD_INFLUENCE: 
	experimental_influence = 0;
	break;

      case OPT_ALLOW_SUICIDE:
	allow_suicide = 1;
	break;

      case OPT_CAPTURE_ALL_DEAD:
	capture_all_dead = 1;
	break;

      case OPT_PLAY_OUT_AFTERMATH:
	play_out_aftermath = 1;
	break;

      case OPT_MODE: 
	if (strcmp(gg_optarg, "ascii") == 0) 
	  playmode = MODE_ASCII;
	else if (strcmp(gg_optarg, "emacs") == 0)
	  playmode = MODE_ASCII_EMACS;
	else if (strcmp(gg_optarg, "gtp") == 0)
	  playmode = MODE_GTP;
	else if (strcmp(gg_optarg, "gmp") == 0)
	  playmode = MODE_GMP;
	else {
	  fprintf(stderr, "Invalid mode selection: %s\n", gg_optarg);
	  fprintf(stderr, "Try `gnugo --help' for more information.\n");
	  
	  exit(EXIT_FAILURE);
	}
	break;
	
      case OPT_DECIDE_STRING:
	if (strlen(gg_optarg) > 3) {
	  fprintf(stderr, "Invalid board coordinate: %s\n", gg_optarg);
	  exit(EXIT_FAILURE);
	}
	strcpy(decide_this, gg_optarg);
	playmode = MODE_DECIDE_STRING;
	break;
	
      case OPT_DECIDE_CONNECTION:
	if (strlen(gg_optarg) > 7) {
	  fprintf(stderr, 
		  "usage: --decide-connection [first string]/[second string]\n");
	  return EXIT_FAILURE;
	}
	strcpy(decide_this, gg_optarg);
	strtok(decide_this, "/");
	decide_that = strtok(NULL, "/");
	if (!decide_that) {
	  fprintf(stderr, 
		  "usage: --decide-connection [first string]/[second string]\n");
	  return EXIT_FAILURE;
	}

	playmode = MODE_DECIDE_CONNECTION;
	break;
	
      case OPT_DECIDE_DRAGON:
	if (strlen(gg_optarg) > 3) {
	  fprintf(stderr, "Invalid board coordinate: %s\n", gg_optarg);
	  exit(EXIT_FAILURE);
	}
	strcpy(decide_this, gg_optarg);
	playmode = MODE_DECIDE_DRAGON;
	break;
	
      case OPT_DECIDE_SEMEAI:
	if (strlen(gg_optarg) > 7) {
	  fprintf(stderr, 
		  "usage: --decide-semeai [first dragon]/[second dragon]\n");
	  return EXIT_FAILURE;
	}
	strcpy(decide_this, gg_optarg);
	strtok(decide_this, "/");
	decide_that = strtok(NULL, "/");
	if (!decide_that) {
	  fprintf(stderr, 
		  "usage: --decide-semeai [first dragon]/[second dragon]\n");
	  return EXIT_FAILURE;
	}

	playmode = MODE_DECIDE_SEMEAI;
	break;
	
      case OPT_DECIDE_TACTICAL_SEMEAI:
	if (strlen(gg_optarg) > 7) {
	  fprintf(stderr, 
		  "usage: --decide-tactical-semeai [first dragon]/[second dragon]\n");
	  return EXIT_FAILURE;
	}
	strcpy(decide_this, gg_optarg);
	strtok(decide_this, "/");
	decide_that = strtok(NULL, "/");
	if (!decide_that) {
	  fprintf(stderr, 
		  "usage: --decide-tactical-semeai [first dragon]/[second dragon]\n");
	  return EXIT_FAILURE;
	}

	playmode = MODE_DECIDE_TACTICAL_SEMEAI;
	break;
	
      case OPT_DECIDE_POSITION:
	playmode = MODE_DECIDE_POSITION;
	break;
	
      case OPT_DECIDE_EYE:
	if (strlen(gg_optarg) > 3) {
	  fprintf(stderr, "Invalid board coordinate: %s\n", gg_optarg);
	  exit(EXIT_FAILURE);
	}
	strcpy(decide_this, gg_optarg);
	playmode = MODE_DECIDE_EYE;
	break;
	
      case OPT_DECIDE_COMBINATION:
	playmode = MODE_DECIDE_COMBINATION;
	break;
	
      case OPT_BRANCH_DEPTH:
	mandated_branch_depth = atoi(gg_optarg);
	break;
	
      case OPT_BACKFILL2_DEPTH:
	mandated_backfill2_depth = atoi(gg_optarg);
	break;
	
      case OPT_SUPERSTRING_DEPTH:
	mandated_superstring_depth = atoi(gg_optarg);
	break;
	
      case OPT_AA_DEPTH:
	mandated_aa_depth = atoi(gg_optarg);

      case OPT_OWL_DISTRUST:
	mandated_owl_distrust_depth = atoi(gg_optarg);
	break;
	
      case OPT_OWL_BRANCH:
	mandated_owl_branch_depth = atoi(gg_optarg);
	break;
	
      case OPT_OWL_READING:
	mandated_owl_reading_depth = atoi(gg_optarg);
	break;
	
      case OPT_OWL_NODE_LIMIT:
	mandated_owl_node_limit = atoi(gg_optarg);
	break;
	
      case OPT_LIFE:
 	life = 1;
	break;

      case OPT_LIFE_EYESIZE:
	life = 1;
	life_eyesize = atoi(gg_optarg);
	break;
	
      case OPT_NOFUSEKIDB:
	fusekidb = 0;
	break;
	
      case OPT_NOFUSEKI:
	disable_fuseki = 1;
	break;
	
      case OPT_NOJOSEKIDB:
	josekidb = 0;
	break;
	
      case OPT_LEVEL:
	level = atoi(gg_optarg);
	break;

      case OPT_CLOCK_TIME:

	clock_init(atoi(gg_optarg), -1, -1);
	clock_enable();
	break;

      case OPT_CLOCK_BYO_TIME: 
	clock_init(-1, atoi(gg_optarg), -1);
	clock_enable();
	break;

      case OPT_CLOCK_BYO_PERIOD:
	clock_init(-1, -1, atoi(gg_optarg));
	clock_enable();
	break;

      case OPT_AUTOLEVEL:
	clock_init(-1, -1, -1);
	clock_enable();
	clock_enable_autolevel();
	break;
	
      case OPT_DEBUG_INFLUENCE:
	if (strlen(gg_optarg) > 3) {
	  fprintf(stderr, "Invalid board coordinate: %s\n", gg_optarg);
	  exit(EXIT_FAILURE);
	}
	strcpy(debuginfluence_move, gg_optarg);
        break;
	
      case OPT_REPLAY_GAME: 
	playmode = MODE_REPLAY;
	if (strcmp(gg_optarg, "white") == 0)
	  replay_color = WHITE;
	else if (strcmp(gg_optarg, "black") == 0)
	  replay_color = BLACK;
	else if (strcmp(gg_optarg, "both") == 0)
	  replay_color = GRAY;
	else {
	  fprintf(stderr, "Invalid replay color: %s\n", gg_optarg);
	  fprintf(stderr, "Try `gnugo --help' for more information.\n");
	  exit(EXIT_FAILURE);
	}
	break;
	
      case OPT_SCORE:
	scoringmode = gg_optarg;
	if (playmode == MODE_UNKNOWN)
	  playmode = MODE_LOAD_AND_SCORE;
	break;
	
      case OPT_PRINTSGF:
	playmode = MODE_LOAD_AND_PRINT;
	printsgffile = gg_optarg;
	break;
	
      case OPT_PROFILE_PATTERNS:
	profile_patterns = 1;
	prepare_pattern_profiling();
	break;
	
      case OPT_COLOR: 
	if (strcmp(gg_optarg, "white") == 0)
	  mandated_color = WHITE;
	else if (strcmp(gg_optarg, "black") == 0)
	  mandated_color = BLACK;
	else {
	  fprintf(stderr, "Invalid color selection: %s\n", gg_optarg);
	  fprintf(stderr, "Try `gnugo --help' for more information.\n");
	  exit(EXIT_FAILURE);
	}
	break;
	
      case OPT_SHOWCOPYRIGHT: 
	show_copyright();
	return EXIT_SUCCESS;
	break;
	
#if EXPERIMENTAL_READING

      case OPT_ATTACK_BY_PATTERN:
        attack_by_pattern = 1;
        break;

      case OPT_DEFEND_BY_PATTERN:
        defend_by_pattern = 1;
        break;

#endif

      case 'v':
	show_version();
	return EXIT_SUCCESS;
	break;
	
      case 'h': 
	show_version();
	if (gg_optarg) {
	  /* In the default behavior of getopt_long with optional args
	   * you need to type "-hdebug"
	   * I can't get long options "--helpdebug" to work at all
	   */
	  if (strncmp(gg_optarg, "debug", 5) == 0)
	    show_debug_help();
	}
	else {
	  /* This is the trick to get "--help debug" and "-h debug" to work*/
	  if (gg_optind < argc) {
	    if (strncmp(argv[gg_optind], "debug", 5) == 0)
	      show_debug_help();
	  }
	  else
	    show_help();
	}
	return EXIT_SUCCESS;
	break;
	
      case OPT_DEBUG_FLAGS:
	show_debug_flags();
	return EXIT_SUCCESS;
	break;

	/* NOTE: getopt returns '?' if an illegal option is supplied. */
      case '?':
      default:
	fprintf(stderr, "Try `gnugo --help' for more information.\n");
	exit(EXIT_FAILURE);
      }
    }
  /* ======================================================*/


  /* Display copyright message unless --quiet option used. */
  if (!quiet) {
    fprintf(stderr, "\n");
    show_version();
    show_copyright();
  }
  
  /* Start random number seed. */
  if (!seed)
    seed = time(0);
  gg_srand(seed);
  random_seed = seed;

  
  /* Initialize the GNU Go engine. */
  init_gnugo(memory);

  
  /* Read the infile if there is one. Also play up the position. */
  if (infilename) {
    if (!sgftree_readfile(&sgftree, infilename)) {
      fprintf(stderr, "Cannot open or parse '%s'\n", infilename);
      exit(EXIT_FAILURE);
    }
    
    gameinfo_play_sgftree_rot(&gameinfo, sgftree.root,
			      untilstring, orientation);
  }

  /* Initialize and empty sgf tree if there was no infile. */
  if (!sgftree.root)
    sgftreeCreateHeaderNode(&sgftree, board_size, komi);

  /* Set the game_record to be identical to the loaded one or the
   * newly created empty sgf tree.
   */
  gameinfo.game_record = sgftree;
  
  /* Notice that we need to know the board size before we can do this.
   */
  if (debuginfluence_move[0]) {
    int m, n;
    string_to_location(board_size, debuginfluence_move, &m, &n);
    debug_influence_move(m, n);
  }
  
  /* Figure out a default mode if there was no explicit one. */
  if (playmode == MODE_UNKNOWN) {
    if (infilename)
      playmode = MODE_LOAD_AND_ANALYZE;
    else
      playmode = (isatty(0)) ? MODE_ASCII : MODE_GMP;
  }
  
  if (outfile) {
    if (playmode != MODE_DECIDE_STRING
	&& playmode != MODE_DECIDE_CONNECTION
	&& playmode != MODE_DECIDE_DRAGON
	&& playmode != MODE_DECIDE_POSITION
	&& playmode != MODE_DECIDE_SEMEAI
	&& playmode != MODE_DECIDE_TACTICAL_SEMEAI
	&& playmode != MODE_DECIDE_EYE
	&& playmode != MODE_DECIDE_COMBINATION)
      if (!sgffile_open_file(outfile)) {
	fprintf(stderr, "Error: could not open '%s'\n", gg_optarg);
	exit(EXIT_FAILURE);
      }
  }
  
  switch (playmode) {
  case MODE_GMP:     
    play_gmp(&gameinfo);
    break;
    
  case MODE_SOLO:
    play_solo(&gameinfo, benchmark);
    break;
    
  case MODE_REPLAY:    
    if (!sgftree.root) {
      fprintf(stderr, "You must use -l infile with replay mode.\n");
      exit(EXIT_FAILURE);
    }
    play_replay(sgftree.root, replay_color);
    break;
    
  case MODE_LOAD_AND_ANALYZE:
    if (mandated_color != EMPTY)
      gameinfo.to_move = mandated_color;
    
    if (!sgftree.root) {
      fprintf(stderr, "You must use -l infile with load and analyze mode.\n");
      exit(EXIT_FAILURE);
    }
    load_and_analyze_sgf_file(&gameinfo, benchmark);
    break;
    
  case MODE_LOAD_AND_SCORE:
    if (!sgftree.root) {
      fprintf(stderr, "gnugo: --score must be used with -l\n");
      exit(EXIT_FAILURE);
    }
    load_and_score_sgf_file(&sgftree, &gameinfo, scoringmode);
    break;
    
  case MODE_LOAD_AND_PRINT:
    if (!sgftree.root) {
      fprintf(stderr, "gnugo: --printsgf must be used with -l\n");
      exit(EXIT_FAILURE);
    }
    else {
      sgffile_open_file(printsgffile);
      sgffile_write_gameinfo(&gameinfo, "load and print"); 
      sgffile_printboard(gameinfo.to_move);
    }
    break;
    
  case MODE_DECIDE_STRING:
    {
      int m, n;
      
      if (!infilename) {
	fprintf(stderr, "gnugo: --decide-string must be used with -l\n");
	return EXIT_FAILURE;
      }
      
      if (!string_to_location(board_size, decide_this, &m, &n)) {
	fprintf(stderr, "gnugo: --decide-string: strange coordinate \n");
	return EXIT_FAILURE;
      }

      rotate(m, n, &m, &n, board_size, orientation);
      decide_string(POS(m, n), outfile);
    }
    break;
  
  case MODE_DECIDE_CONNECTION:
    {
      int ai, aj, bi, bj;
      
      if (!infilename) {
	fprintf(stderr, "gnugo: --decide-connection must be used with -l\n");
	return EXIT_FAILURE;
      }
      
      if (!string_to_location(board_size, decide_this, &ai, &aj)) {
	fprintf(stderr, "usage: --decide-connection [first string]/[second string]\n");
	return EXIT_FAILURE;
      }
      
      if (!string_to_location(board_size, decide_that, &bi, &bj)) {
	fprintf(stderr, "usage: --decide-connection [first string]/[second string]\n");
	return EXIT_FAILURE;
      }

      rotate(ai, aj, &ai, &aj, board_size, orientation);
      rotate(bi, bj, &bi, &bj, board_size, orientation);
      decide_connection(POS(ai, aj), POS(bi, bj), outfile);
    }
  break;
  
  case MODE_DECIDE_DRAGON:
    {
      int m, n;
      
      if (!infilename) {
	fprintf(stderr, "gnugo: --decide-dragon must be used with -l\n");
	return EXIT_FAILURE;
      }
      
      if (!string_to_location(board_size, decide_this, &m, &n)) {
	fprintf(stderr, "gnugo: --decide-dragon: strange coordinate \n");
	return EXIT_FAILURE;
      }

      rotate(m, n, &m, &n, board_size, orientation);
      decide_dragon(POS(m, n), outfile);
    }
    break;
  
  case MODE_DECIDE_SEMEAI:
    {
      int ai, aj, bi, bj;
      
      if (!infilename) {
	fprintf(stderr, "gnugo: --decide-semeai must be used with -l\n");
	return EXIT_FAILURE;
      }
      
      if (!string_to_location(board_size, decide_this, &ai, &aj)) {
	fprintf(stderr, 
		"usage: --decide-semeai [first dragon]/[second dragon]\n");
	return EXIT_FAILURE;
      }
      
      if (!string_to_location(board_size, decide_that, &bi, &bj)) {
	fprintf(stderr, 
		"usage: --decide-semeai [first dragon]/[second dragon]\n");
	return EXIT_FAILURE;
      }

      rotate(ai, aj, &ai, &aj, board_size, orientation);
      rotate(bi, bj, &bi, &bj, board_size, orientation);
      decide_semeai(POS(ai, aj), POS(bi, bj), outfile);
    }
    break;
    

  case MODE_DECIDE_TACTICAL_SEMEAI:
    {
      int ai, aj, bi, bj;
      
      if (!infilename) {
	fprintf(stderr, "gnugo: --decide-tactical-semeai must be used with -l\n");
	return EXIT_FAILURE;
      }
      
      if (!string_to_location(board_size, decide_this, &ai, &aj)) {
	fprintf(stderr, 
		"usage: --decide-tactical-semeai [first dragon]/[second dragon]\n");
	return EXIT_FAILURE;
      }
      
      if (!string_to_location(board_size, decide_that, &bi, &bj)) {
	fprintf(stderr, 
		"usage: --decide-tactical-semeai [first dragon]/[second dragon]\n");
	return EXIT_FAILURE;
      }

      rotate(ai, aj, &ai, &aj, board_size, orientation);
      rotate(bi, bj, &bi, &bj, board_size, orientation);
      decide_tactical_semeai(POS(ai, aj), POS(bi, bj), outfile);
    }
    break;
    

  case MODE_DECIDE_POSITION:
    {
      int color;
      if (!infilename) {
	fprintf(stderr, "gnugo: --decide-position must be used with -l\n");
	return EXIT_FAILURE;
      }
      color = gameinfo.to_move;
      if (mandated_color != EMPTY)
	color = mandated_color;
      decide_position(color, outfile);
    }
    break;
    
  case MODE_DECIDE_EYE:
    {
      int m, n;
      
      if (!infilename) {
	fprintf(stderr, "gnugo: --decide-eye must be used with -l\n");
	return EXIT_FAILURE;
      }
      
      if (!string_to_location(board_size, decide_this, &m, &n)) {
	fprintf(stderr, "gnugo: --decide-eye: strange coordinate \n");
	return EXIT_FAILURE;
      }
      
      rotate(m, n, &m, &n, board_size, orientation);
      decide_eye(POS(m, n), outfile);
    }
    break;
  
  case MODE_DECIDE_COMBINATION:
    {
      int color;
      if (!infilename) {
	fprintf(stderr, "gnugo: --decide-combination must be used with -l\n");
	return EXIT_FAILURE;
      }
      color = gameinfo.to_move;
      if (mandated_color != EMPTY)
	color = mandated_color;
      decide_combination(color, outfile);
    }
    break;
    
  case MODE_GTP:  
    if (gtpfile != NULL) {
      gtp_input_FILE = fopen(gtpfile, "r");
      if (gtp_input_FILE == NULL) {
	fprintf(stderr, "gnugo: Cannot open file %s\n", gtpfile);
	return EXIT_FAILURE;
      } 
    }
    else
      gtp_input_FILE = stdin;

    play_gtp(gtp_input_FILE, orientation);
    break;

  case MODE_ASCII_EMACS:  
    if (mandated_color != EMPTY)
      umove = mandated_color;
    gameinfo.computer_player = OTHER_COLOR(umove);
    play_ascii_emacs(&sgftree, &gameinfo, infilename, untilstring);
    break;

  case MODE_ASCII:  
  default:     
    if (mandated_color != EMPTY)
      umove = mandated_color;
    gameinfo.computer_player = OTHER_COLOR(umove);
    play_ascii(&sgftree, &gameinfo, infilename, untilstring);
    break;
  }
  
  sgffile_close_file();
  
  if (profile_patterns)
    report_pattern_profiling();

  clock_report_autolevel(NULL, OTHER_COLOR(umove));
 
  return 0;
}  
/* end main */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* 
 * Cgoban sends us a sigterm when it wants us to die. But it doesn't
 * close the pipe, so we cannot rely on gmp to pick up an error.
 * 
 * We want to keep control so we can close the output sgf file
 * properly, so we trap the signal.
 */

volatile int time_to_die = 0;   /* set by signal handlers */

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
static void 
sigterm_handler(int sig)
{
  time_to_die = 1;
  if (!quiet)
    write(2, "*SIGTERM*\n", 10);  /* bad to use stdio in a signal handler */

  close(0);                  /* this forces gmp.c to return an gmp_err */

  /* I thought signal handlers were one-shot, yet on my linux box it is kept.
   * Restore the default behaviour so that a second signal has the
   * original effect - in case we really are stuck in a loop.
   */
  signal(sig, SIG_DFL);

  /* schedule a SIGALRM in 5 seconds, in case we haven't cleaned up by then
   * - cgoban sends the SIGTERM only once 
   */
#ifdef HAVE_ALARM
  alarm(5);
#endif
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
static void
show_version(void)
{
  fprintf(stderr, "GNU Go Version %s\n", VERSION);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Set the parameters which determine the depth to which
 * the reading and owl code carries its calculations.
 */


/* 
 * This string is modelled after the GNU tar --help output.
 * Since the maximum string length is 2048 bytes in VC++ we
 * split the help string.
 */

#define USAGE "\n\
Usage: gnugo [-opts]\n\
\n\
Main Options:\n\
       --mode <mode>     Force the playing mode ('ascii', 'gmp', or 'gtp').\n\
                         Default is ASCII.\n\
                         If no terminal is detected GMP (Go Modem Protocol)\n\
                         will be assumed.\n\
       --quiet           Don't print copyright and informational messages\n\
       --gtp-input <file>Read gtp commands from file instead of stdin\n\
   -l, --infile <file>   Load name sgf file\n\
   -L, --until <move>    Stop loading just before move is played. <move>\n\
                         can be the move number or location (eg L10).\n\
   -o, --outfile <file>  Write sgf output to file\n\
   --printsgf <file>     Write position as a diagram to file (use with -l)\n\
\n\
Options that affect strength (higher = stronger, slower):\n\
   -D, --depth <depth>          deep reading cutoff (default %d)\n\
   -B, --backfill-depth <depth> deep reading cutoff (default %d)\n\
   -F, --fourlib-depth <depth>  deep reading cutoff (default %d)\n\
   -K, --ko-depth <depth>       deep reading cutoff (default %d)\n\
   --branch-depth <depth>       deep reading cutoff (default %d)\n\
   --backfill2-depth <depth>    deep reading cutoff (default %d)\n\
   --superstring-depth <depth>  deep reading cutoff (default %d)\n\
   --aa-depth <depth>           deep reading cutoff (default %d)\n\
   --owl-distrust <depth>       owl distrust depth (default %d)\n\
   --owl-branch <depth>         owl branching depth (default %d)\n\
   --owl-reading <depth>        owl reading depth (default %d)\n\
   --owl-node-limit <limit>     max nodes for owl reading (default %d)\n\
   --level <amount>             strength (default %d, up to 10 supported)\n\
   --autolevel                  adapt gnugo level during game to respect\n\
                                the time specified by --clock <sec>.\n\
"

#define USAGE1 "\n\
Experimental options:\n\
   --life                  use life code\n\
   --life-eyesize <n>      use life code, life_eyesize=n (default %d)\n\
   --nofusekidb            turn off fuseki database\n\
   --nofuseki              turn off fuseki moves entirely\n\
   --nojosekidb            turn off joseki database\n\
Scoring:\n\
   --score estimate        estimate score at loaded position\n\
   --score finish          generate moves to finish game, then score\n\
   --score aftermath       generate moves to finish, use best algorithm\n\
   --score aftermath --capture-all-dead --chinese rules   Tromp-Taylor score\n\
\n\
Cache size (higher=more memory usage, faster unless swapping occurs):\n\
   -M, --cache-size <megabytes>  RAM cache for hashing (default %4.1f Mb)\n\
\n\
Game Options: (--mode ascii)\n\
       --boardsize num   Set the board size to use (%d--%d)\n\
       --color <color>   Choose your color ('black' or 'white')\n\
       --handicap <num>  Set the number of handicap stones (0--%d)\n\
       --komi <num>      Set the komi\n\
       --clock <sec>     Initialize the timer.\n\
       --byo-time <sec>  Initialize the byo-yomi timer.\n\
       --byo-period <stones>  Initialize the byo-yomi period.\n\n\
\n\
Informative Output:\n\
   -v, --version         Display the version of GNU Go\n\
   --options             Display configure options\n\
   -h, --help            Display this help message\n\
       --help debug      Display help about debugging options\n\
       --copyright       Display copyright notice\n\
\n\
"


#define COPYRIGHT "\n\n\
This is GNU GO, a Go program. Contact gnugo@gnu.org, or see\n\
http://www.gnu.org/software/gnugo/ for more information.\n\n\
Copyright 1999, 2000, 2001, 2002 by the Free Software Foundation.\n\n\
This program is free software; you can redistribute it and/or\n\
modify it under the terms of the GNU General Public License\n\
as published by the Free Software Foundation - version 2.\n\n\
This program is distributed in the hope that it will be\n\
useful, but WITHOUT ANY WARRANTY; without even the implied\n\
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR\n\
PURPOSE.  See the GNU General Public License in file COPYING\n\
for more details.\n\n\
You should have received a copy of the GNU General Public\n\
License along with this program; if not, write to the Free\n\
Software Foundation, Inc., 59 Temple Place - Suite 330,\n\
Boston, MA 02111, USA.\n\n\
"

/* USAGE_DEBUG Split in half because of VC limit on constant string 
 * length of 2048 characters!*/
#define USAGE_DEBUG "\n\
Debugging Options:\n\
\n\
       --replay <color> replay the moves in a game for color.\n\
                        (requires -l)\n\
                     white: replay only white moves\n\
                     black: replay only black moves\n\
                     both:  replay all moves\n\
   -a, --allpats                 test all patterns\n\
   -T, --printboard              colored display of dragons\n\
   -E                            colored display of eye spaces\n\
   -d, --debug <flags>           debugging output (see next item for bits)\n\
   --debug-flags                 print the debug flags for previous item\n\
   -H, --hash <level>            hash (see gnugo.h for bits)\n\
   -w, --worms                   print worm and dragon data and move reasons\n\
   -m, --moyo <level>            moyo debugging, show moyo board\n\
   -b, --benchmark num           benchmarking mode - can be used with -l\n\
   -S, --statistics              print statistics (for debugging purposes)\n\n\
   -t, --trace                   verbose tracing\n\
   --showtime                    print timing diagnostic\n\
   --replay <color>              replay game. Use with -o.\n\
   --showscore                   print estimated score\n\
   -r, --seed number             set random number seed\n\
"
#define USAGE_DEBUG2 "\
       --decide-string <string>  can this string live? (try with -o)\n\
       --decide-connection <str/str> can these strings connect? (try with -o)\n\
       --decide-dragon <dragon>  can this dragon live? (try with -o or -t)\n\
       --decide-position         evaluate all dragons (try with -o or -t)\n\
       --decide-eye <string>     evaluate the eye\n\
       --decide-combination      search for combination attack (try with -o)\n\
       --genmove <color>         generate a move for color\n\
       --life <eyesize>          use eye reading code\n\
       --nofusekidb              turn off fuseki database\n\
       --nofuseki                turn off fuseki moves entirely\n\
       --nojosekidb              turn off joseki database\n\
       --debuginfluence <move>   print influence map after making a move\n\
       --score <end|last|move>   count or estimate territory\n\
       --profile-patterns        print statistics for pattern usage\n\
       --attack-by-pattern       use pattern-based tactical reading for attack\n\
       --defend-by-pattern       use pattern-based tactical reading for defense\n\
"

#define DEBUG_FLAGS "\
DEBUG_INFLUENCE             0x0001\n\
DEBUG_EYES                  0x0002\n\
DEBUG_OWL                   0x0004\n\
DEBUG_ESCAPE                0x0008\n\
DEBUG_MATCHER               0x0010\n\
DEBUG_DRAGONS               0x0020\n\
DEBUG_SEMEAI                0x0040\n\
DEBUG_LOADSGF               0x0080\n\
DEBUG_HELPER                0x0100\n\
DEBUG_READING               0x0200\n\
DEBUG_WORMS                 0x0400\n\
DEBUG_MOVE_REASONS          0x0800\n\
DEBUG_OWL_PERFORMANCE       0x1000\n\
DEBUG_LIFE                  0x2000\n\
DEBUG_FILLLIB               0x4000\n\
DEBUG_READING_PERFORMANCE   0x8000\n\
DEBUG_SCORING               0x010000\n\
DEBUG_AFTERMATH             0x020000\n\
DEBUG_ATARI_ATARI           0x040000\n\
DEBUG_READING_CACHE         0x080000\n\
DEBUG_TERRITORY             0x100000\n\
DEBUG_OWL_PERSISTENT_CACHE  0x200000\n\
"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*
 * Since the maximum string length is 2048 bytes in VC++ we
 * split the help string.
 */
static void
show_help(void)
{
  set_depth_values(DEFAULT_LEVEL);
  fprintf(stderr, USAGE,
	  depth, backfill_depth, fourlib_depth, ko_depth, branch_depth,
	  backfill2_depth, superstring_depth, aa_depth, 
	  owl_distrust_depth, owl_branch_depth,
	  owl_reading_depth, owl_node_limit, DEFAULT_LEVEL);
  fprintf(stderr, USAGE1,
	   LIFE_EYESIZE,
	  (float) DEFAULT_MEMORY, MIN_BOARD, MAX_BOARD, MAX_HANDICAP);
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
static void
show_debug_help(void)
{
  fprintf(stderr, USAGE_DEBUG USAGE_DEBUG2);
}

static void 
show_debug_flags(void)
{
  fprintf(stderr, DEBUG_FLAGS);
}

static void
show_copyright(void)
{
  fputs(COPYRIGHT, stderr);
}

/*--------------------------------my_play_ascii-------------------------------*/
/*   Play a game against an ascii client                                      */
/*----------------------------------------------------------------------------*/
void
my_play_ascii (SGFTree *tree, Gameinfo *gameinfo, char *filename, char *until)
{
  int   m, num;
  int   passes = 0;  /* two passes and its over */
  int   tmp;
  char  line[80];
  char *line_ptr = line;
  char *command;
  

#ifdef HAVE_SETLINEBUF
  setlinebuf(stdout); /* Need at least line buffer gnugo-gnugo */
#else
  setbuf(stdout, NULL); /* else set it to completely UNBUFFERED */
#endif
  
  printf ("my_play_ascii \n");

  sgftree = *tree;
    
  /* No score is estimated yet. */
  current_score_estimate = NO_SCORE;
    
  if (gameinfo->handicap == 0)
    gameinfo->to_move = BLACK;
  else {
    gameinfo->handicap = gnugo_placehand (gameinfo->handicap);
    sgfOverwritePropertyInt(sgftree.root, "HA", gameinfo->handicap);
    gameinfo->to_move = WHITE;
  }
      
  curnode = sgftree.root;
    
  printf ("\nBeginning ASCII mode game.\n\n");
  gameinfo_print (gameinfo);
    
  /* Does the computer play first?  If so, make a move. */
  if (gameinfo->computer_player == gameinfo->to_move)
    computer_move (gameinfo, &passes);
    
    /* ====================== main ASCII Play loop ===================== */
  while (passes < 2) {
      
    ascii_showboard();      
    mprintf ("%s(%d): ", color_to_string (gameinfo->to_move), movenum + 1);

    line_ptr = line;
    if (!fgets(line, 80, stdin)) {
      printf ("\nThanks! for playing GNU Go.\n\n");
      return ;
    }  

    while (command = strtok (line_ptr, ";"), line_ptr = 0, command) {
      switch (get_command (command)) {
      case EXIT:
      case QUIT:
        printf("\nThanks! for playing GNU Go.\n\n");
        return ;
        break;
      case MOVE:
        do_move (gameinfo, command, &passes, 0);
        break;
      case PASS:
        do_pass (gameinfo, &passes, 0);
        break;
      default:
        printf("\nInvalid command: %s", command);
        break;
      }
    }
  }
  /*  =========== End main ASCII Play loop ==================== */

  gnugo_who_wins (gameinfo->computer_player, stdout);

  printf("\nThanks for playing GNU Go.\n\n");
  return;
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
int
main (int argc, char *argv[])
{
  Gameinfo gameinfo;
  SGFTree sgftree;
  int i, umove, seed;


  main_gnugo (argc, argv);
  return 0;
  /* ======================================================================*/

  /* Set SIGTERM handler. */
  signal (SIGTERM, sigterm_handler);

  board_size = 9;

  /* beg ==================== misc values */
  level = 1;  
  chinese_rules = 0;
  komi  = 0.0;
  semeai_variations = DEFAULT_SEMEAI_VARIATIONS;

/* Set the various reading depth parameters. If mandated_depth_value
 * is not -1 that value is used; otherwise the depth values are
 * set as a function of level. The parameter mandated_depth_value
 * can be set at the command line to force a particular value of
 * depth; normally it is -1.
 */
  mandated_depth               = -1;
  mandated_backfill_depth      = -1;
  mandated_backfill2_depth     = -1;
  mandated_superstring_depth   = -1;
  mandated_fourlib_depth       = -1;
  mandated_ko_depth            = -1;
  mandated_branch_depth        = -1;
  mandated_owl_distrust_depth  = -1;
  mandated_owl_branch_depth    = -1;
  mandated_owl_reading_depth   = -1;
  mandated_owl_node_limit      = -1;
  mandated_aa_depth            = -1;

  debug = 0;
  life  = 0;
  life_eyesize = LIFE_EYESIZE;

  fusekidb       = 0;
  disable_fuseki = 0;
  josekidb       = 0;

  if (OWL_THREATS)    owl_threats = 1;
  else                owl_threats = 0;

  experimental_semeai      = EXPERIMENTAL_SEMEAI;
  experimental_connections = EXPERIMENTAL_CONNECTIONS;
  experimental_influence   = EXPERIMENTAL_INFLUENCE;

  allow_suicide = 0;
  capture_all_dead = 0;
  play_out_aftermath = 0;

  sgftree_clear (&sgftree);
  gameinfo_clear (&gameinfo, board_size, komi);

  gameinfo.handicap = 3;
  umove = BLACK;
  
  /* Start random number seed. GNU Go will play a different game each time */
  seed = time(0);
  gg_srand (seed);
  random_seed = seed;
  
  /* Initialize the GNU Go engine. */
  init_gnugo(memory);
  
  /* Initialize and empty sgf tree if there was no infile. */
  sgftreeCreateHeaderNode(&sgftree, board_size, komi);
  gameinfo.game_record = sgftree;
    
  gameinfo.computer_player = OTHER_COLOR (umove);

  /*=================================*/
  my_play_ascii (&sgftree, &gameinfo, /* infilename */NULL, /* untilstring */NULL);
  /*=================================*/
  

  sgffile_close_file();
  
  return 0;
}  
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*----------------------------------------------------------------------------*/


