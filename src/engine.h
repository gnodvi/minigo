/* emgena - gnugo.h */
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

/* ---------------------------------------------------------------- *
 * gnugo.h
 *	This file contains the public interface to the GNU Go engine.
 * ---------------------------------------------------------------- */


#ifndef _GNUGO_H_
#define _GNUGO_H_
 

/* #ifdef HAVE_CONFIG_H */
/* #include "config.h" */
/* #endif */

/* #include <stdio.h> */

/* #include "sgftree.h" */
/* #include "clock.h" */

/* interface.c */
/* Initialize the whole thing. Should be called once. */
void init_gnugo(float memory);


/* ================================================================ */
/*                some public macros used everywhere                */
/* ================================================================ */


/* Colors */
#define EMPTY        0
#define WHITE        1
#define BLACK        2
#define GRAY         3
#define GRAY_BORDER  3
#define WHITE_BORDER 4
#define BLACK_BORDER 5
#define ANCHOR_COLOR 6
#define ANCHOR_OTHER 7


#define OTHER_COLOR(color)  (WHITE+BLACK-(color))
#define IS_STONE(arg)  ((arg) == WHITE || (arg) == BLACK)

/* Return codes for reading functions */

#define WIN  3
#define KO_A 2
#define KO_B 1
#define LOSE 0
#define CUT  2

/* Group statuses */
#define DEAD        0
#define ALIVE       1
#define CRITICAL    2 
#define UNKNOWN     3
#define UNCHECKED   4
#define MAX_DRAGON_STATUS 4	/* used to size an array in matchpat.c */

/* Dragon safety values. DEAD, ALIVE, and CRITICAL are reused. */
#define INESSENTIAL     3
#define TACTICALLY_DEAD 4
#define WEAK            5
#define WEAKLY_ALIVE    6
#define ALIVE_IN_SEKI   7
#define STRONGLY_ALIVE  8
#define INVINCIBLE      9
#define INSUBSTANTIAL   10
#define CAN_THREATEN_ATTACK  11
#define CAN_THREATEN_DEFENSE 12

/* Final statuses for empty vertices. */
#define BLACK_TERRITORY 13
#define WHITE_TERRITORY 14
#define DAME            15

/* Eye reading */
#define LIFE_EYESIZE         10

/* ================================================================ */
/*                        Board manipulation                        */
/* ================================================================ */


/* Board sizes */
#define MIN_BOARD          5	   /* Minimum supported board size.   */
#define MAX_BOARD         19       /* Maximum supported board size.   */
#define MAX_HANDICAP       9	   /* Maximum supported handicap.     */
#define MAX_MOVE_HISTORY 500       /* Max number of moves remembered. */

/* This type is used to store each intersection on the board.
 *
 * On a 486, char is best, since the time taken to push and pop
 * becomes significant otherwise. On other platforms, an int may
 * be better, e.g. if memcpy() is particularly fast, or if
 * character access is very slow.
 */

typedef unsigned char Intersection;


void gnugo_clear_board(int boardsize);
void gnugo_set_komi(float new_komi);
void gnugo_add_stone(int i, int j, int color);
void gnugo_remove_stone(int i, int j);
int  gnugo_is_pass(int i, int j);
void gnugo_play_move(int i, int j, int color);
int  gnugo_undo_move(int n);
int  gnugo_play_sgfnode(SGFNode *node, int to_move);
int  gnugo_play_sgftree(SGFNode *root, int *until, SGFNode **curnode);
int  gnugo_is_legal(int i, int j, int color);
int  gnugo_is_suicide(int i, int j, int color);

int  gnugo_placehand(int handicap);
int  gnugo_sethand(int handicap, SGFNode *root);
void gnugo_recordboard(SGFNode *node);

int  gnugo_genmove(int *i, int *j, int color);

int  gnugo_attack(int m, int n, int *i, int *j);
int  gnugo_find_defense(int m, int n, int *i, int *j);

void  gnugo_who_wins(int color, FILE *outfile);
float gnugo_estimate_score(float *upper, float *lower);
void  gnugo_examine_position(int color, int how_much);

int  gnugo_get_komi(void);
void gnugo_get_board(int b[MAX_BOARD][MAX_BOARD]);
int  gnugo_get_boardsize(void);
int  gnugo_get_move_number(void);

/* ================================================================ */
/*                           Game handling                          */
/* ================================================================ */


typedef struct {
  int       handicap;

  int       to_move;		/* whose move it currently is */
  SGFTree   game_record;	/* Game record in sgf format. */

  int       computer_player;	/* BLACK, WHITE, or EMPTY (used as BOTH) */

  char      outfilename[128];	/* Trickle file */
  FILE      *outfile;
} Gameinfo;

void gameinfo_clear(Gameinfo *ginfo, int boardsize, float komi);
void gameinfo_print(Gameinfo *ginfo);
void gameinfo_load_sgfheader(Gameinfo *gameinfo, SGFNode *head);
void gameinfo_play_move(Gameinfo *ginfo, int i, int j, int color);
int  gameinfo_play_sgftree_rot(Gameinfo *gameinfo, SGFNode *head,
			       const char *untilstr, int orientation);
int  gameinfo_play_sgftree(Gameinfo *gameinfo, SGFNode *head,
			   const char *untilstr);


/* ================================================================ */
/*                           global variables                       */
/* ================================================================ */

/* Random seed */
extern int random_seed;

/* Miscellaneous debug options. */
extern int quiet;		/* Minimal output. */
extern int verbose;		/* Bore the opponent. */
extern int allpats;		/* generate all patterns, even small ones */
extern int printworms;		/* print full data on each string */
extern int printmoyo;		/* print moyo board each move */
extern int printdragons;	/* print full data on each dragon */
extern int printboard;		/* print board each move */
extern int showstatistics;	/* print statistics */
extern int profile_patterns;	/* print statistics of pattern usage */

/* debug flag bits */
/* NOTE : can specify -d0x... */
#define DEBUG_INFLUENCE             0x0001
#define DEBUG_EYES                  0x0002
#define DEBUG_OWL                   0x0004
#define DEBUG_ESCAPE                0x0008
#define DEBUG_MATCHER               0x0010
#define DEBUG_DRAGONS               0x0020
#define DEBUG_SEMEAI                0x0040
#define DEBUG_LOADSGF               0x0080
#define DEBUG_HELPER                0x0100
#define DEBUG_READING               0x0200
#define DEBUG_WORMS                 0x0400
#define DEBUG_MOVE_REASONS          0x0800
#define DEBUG_OWL_PERFORMANCE       0x1000
#define DEBUG_LIFE                  0x2000
#define DEBUG_FILLLIB               0x4000
#define DEBUG_READING_PERFORMANCE   0x8000
#define DEBUG_SCORING               0x010000
#define DEBUG_AFTERMATH             0x020000
#define DEBUG_ATARI_ATARI           0x040000
#define DEBUG_READING_CACHE         0x080000
#define DEBUG_TERRITORY             0x100000
#define DEBUG_OWL_PERSISTENT_CACHE  0x200000
/* hash flag bits 
 *
 * Regarding HASH_DEFAULT:
 * Hashing all functions saves time, but wastes table space, which is
 * bad when the reading is complicated. HASH_DEFAULT is a compromise. 
 */

#define HASH_FIND_DEFENSE 0x0001  /* NOTE : can specify -d0x... */
#define HASH_DEFEND1      0x0002
#define HASH_DEFEND2      0x0004
#define HASH_DEFEND3      0x0008
#define HASH_DEFEND4      0x0010
#define HASH_ATTACK       0x0020
#define HASH_ATTACK2      0x0040
#define HASH_ATTACK3      0x0080
#define HASH_OWL_ATTACK   0x0100
#define HASH_OWL_DEFEND   0x0200
#define HASH_SEMEAI       0x0400
#define HASH_CONNECT      0x0800
#define HASH_DISCONNECT   0x1000
#define HASH_NOTHING      0
#define HASH_ALL          0xffff
#define HASH_DEFAULT      (HASH_ATTACK | HASH_FIND_DEFENSE\
			   | HASH_OWL_ATTACK | HASH_OWL_DEFEND | HASH_SEMEAI\
                           | HASH_CONNECT | HASH_DISCONNECT)

extern int debug;		/* debug flags */
extern int hashflags;		/* hash flags */
extern int life;                /* use "life" reading code */
extern int life_eyesize;        /* max eye size for life code */
extern int fusekidb;            /* use fuseki database */
extern int disable_fuseki;      /* do not generate fuseki moves */
extern int josekidb;            /* use joseki database */
extern int level;		/* controls depth of reading */
extern int semeai_variations;   /* max variations considered reading semeai */
extern int urgent;              /* urgent move on board */
extern int showtime;		/* print genmove time */
extern int showscore;		/* print score */
extern float score;
extern float lower_bound;
extern float upper_bound;
extern int chinese_rules;       /* use chinese (area) rules for counting */
extern int experimental_semeai;      /* use experimental semeai module */
extern int experimental_connections; /* use experimental connection module */
extern int alternate_connections;    /* use alternate connection module */
extern int owl_threats;              /* compute owl threats */
extern int experimental_influence;   /* use experimental influence module */
extern int allow_suicide;            /* allow opponent to make suicide moves */
extern int capture_all_dead;         /* capture all dead opponent stones */
extern int play_out_aftermath; /* make everything unconditionally settled */

#if EXPERIMENTAL_READING
extern int defend_by_pattern;  /* use patterns for tactical reading defense */
extern int attack_by_pattern;  /* use patterns for tactical reading attack */
#endif

/* Mandatory values of reading parameters. Normally -1, if set at 
 * these override the values derived from the level. */
extern int mandated_depth;
extern int mandated_backfill_depth;
extern int mandated_backfill2_depth;
extern int mandated_superstring_depth;
extern int mandated_fourlib_depth;
extern int mandated_ko_depth;
extern int mandated_branch_depth;
extern int mandated_aa_depth;
extern int mandated_aa_threat_depth;
extern int mandated_owl_distrust_depth;
extern int mandated_owl_branch_depth;
extern int mandated_owl_reading_depth;
extern int mandated_owl_node_limit; 

/* Keep this as 2D until we change the entire API. */
extern float potential_moves[MAX_BOARD][MAX_BOARD];

extern volatile int time_to_die;   /* set by signal handlers */

/* ================================================================ */
/*                 tracing and debugging functions                  */
/* ================================================================ */

/* Colors. */
#define GG_COLOR_BLACK   0
#define GG_COLOR_RED     1
#define GG_COLOR_GREEN   2
#define GG_COLOR_YELLOW  3
#define GG_COLOR_BLUE    4
#define GG_COLOR_MAGENTA 5
#define GG_COLOR_CYAN    6
#define GG_COLOR_WHITE   7

/* showbord.c */
void start_draw_board(void);
void draw_color_char(int m, int n, int c, int color);
void draw_char(int m, int n, int c);
void end_draw_board(void);
void showboard(int xo);  /* ascii rep. of board to stdout */

/* printutils.c */
int gprintf(const char *fmt, ...);
void mprintf(const char *fmt, ...);
void gfprintf(FILE *outfile, const char *fmt, ...);
const char *color_to_string(int color);
const char *location_to_string(int pos);
void        location_to_buffer(int pos, char *buf);
const char *status_to_string(int status);
const char *safety_to_string(int status);
const char *result_to_string(int result);
const char *routine_to_string(int routine);
int string_to_location(int boardsize, char *str, int *m, int *n);
double gg_gettimeofday(void);


/* influence.c */
void debug_influence_move(int i, int j);

#ifdef HAVE_VARIADIC_DEFINE

/* gnuc allows variadic macros, so the tests can be done inline */
#define TRACE(fmt, args...) \
    do { if (verbose) gprintf(fmt, ##args); } while (0)
#define RTRACE(fmt, args...) \
    do { if (verbose >= 3) gprintf(fmt, ##args); } while (0)
#define VTRACE(fmt, args...) \
    do { if (verbose >= 4) gprintf(fmt, ##args); } while (0)
#define DEBUG(level, fmt, args...) \
    do { if ((debug & (level))) gprintf(fmt, ##args); } while (0)

#else /*HAVE_VARIADIC_DEFINE*/

/* Using these without assignment causes compiler warnings on some systems. */
extern int trace_dummy;
# ifdef HAVE_VISUAL_C
#  define TRACE_ASSIGN 
# else
#  define TRACE_ASSIGN trace_dummy =
# endif

#define TRACE  TRACE_ASSIGN (verbose) && gprintf
#define RTRACE TRACE_ASSIGN (verbose >= 3) && gprintf
#define VTRACE TRACE_ASSIGN (verbose >= 4) && gprintf
/* if debug == 0, then can skip the function call. */
#define DEBUG  TRACE_ASSIGN (debug) && DEBUG_func

int DEBUG_func(int level, const char *fmt, ...);

#endif  /*HAVE_VARIADIC_DEFINE*/


/* genmove.c */
#define EXAMINE_WORMS               1
#define EXAMINE_INITIAL_INFLUENCE   2
#define EXAMINE_DRAGONS_WITHOUT_OWL 3
#define EXAMINE_DRAGONS             4
#define EXAMINE_OWL_REASONS         5
#define EXAMINE_INITIAL_INFLUENCE2  6

#define EXAMINE_ALL                 99

void reset_engine(void);
void examine_position(int color, int how_much);
void silent_examine_position(int color, int how_much);


/* ================================================================ */
/*                         statistics functions                     */
/* ================================================================ */


/* These are mostly used for GTP examination. */
void reset_life_node_counter(void);
int get_life_node_counter(void);
void reset_owl_node_counter(void);
int get_owl_node_counter(void);
void reset_reading_node_counter(void);
int get_reading_node_counter(void);
void reset_trymove_counter(void);
int get_trymove_counter(void);
void reset_connection_node_counter(void);
int get_connection_node_counter(void);


/* ================================================================ */
/*                         Low level functions                      */
/* ================================================================ */


/* board.c */
/* General board handling. */
void clear_board(void);
int test_gray_border(void);
void setup_board(Intersection new_board[MAX_BOARD][MAX_BOARD], int ko_pos,
		 int *last, float new_komi, int w_captured, int b_captured);


/* Putting stones on the board.. */
void add_stone(int pos, int color);
void remove_stone(int pos);
void play_move(int pos, int color);
int undo_move(int n);
int get_last_move(void);
int get_last_opponent_move(int color);
int is_pass(int pos);
int is_legal(int pos, int color);
int is_suicide(int pos, int color);
int is_illegal_ko_capture(int pos, int color);
int trymove(int pos, int color, const char *message, int str, 
	    int komaster, int kom_pos);
int semeai_trymove(int pos, int color, const char *message, 
		   int str1, int str2, int owl_phase, int value);
int tryko(int pos, int color, const char *message, 
	  int komaster, int kom_pos);
void popgo(void);

/* utils.c */
void change_matcher_status(int dr, int status);
void who_wins(int color, FILE* outfile);

/* high-level routine to generate the best move for the given color */
int genmove(int *i, int *j, int color);
int genmove_conservative(int *i, int *j, int color);

/* Play through the aftermath. */
float aftermath_compute_score(int color, float komi, SGFTree *tree);
int aftermath_final_status(int color, int pos);

/* Basic information gathering. */
/* worm.c */
void make_worms(int save_verbose);

/* dragon.c */
void make_dragons(int color, int stop_before_owl, int save_verbose);
void initialize_dragon_data(void);
void show_dragons(void);
int dragon_status(int pos);
int matcher_status(int pos);
int same_dragon(int dr1, int dr2);

/* moyo functions */
void print_moyo(void);

/* debugging functions */
void prepare_pattern_profiling(void);
void report_pattern_profiling(void);

/* sgffile.c */
void sgffile_move_made(int i, int j, int color, int value);
void sgffile_put_stone(int i, int j, int color);

int sgffile_open_file(const char *);
int sgffile_close_file(void);
int sgffile_write_gameinfo(Gameinfo *gameinfo, const char *);
void sgffile_write_comment(const char *comment);
void sgffile_write_circle_mark(int i, int j);
void sgffile_printboard(int next);
void sgffile_recordboard(SGFNode *node);

/* sgfdecide.c */
void decide_string(int pos, const char *sgf_output);
void decide_connection(int apos, int bpos, const char *sgf_output);
void decide_dragon(int pos, const char *sgf_output);
void decide_semeai(int apos, int bpos, const char *sgf_output);
void decide_tactical_semeai(int apos, int bpos, const char *sgf_output);
void decide_position(int color, const char *sgf_output);
void decide_eye(int pos, const char *sgf_output);
void decide_combination(int color, const char *sgf_output);


#endif  /* _GNUGO_H_ */


/* ======================================================================== */

/* emgena: hash.h */
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
/* emgena */
/* #define HASHING_SCHEME 1  */

/* #include <stdio.h> */
/* #include <gnugo.h> */

/*
 * This file, together with engine/hash.c implements hashing of go positions
 * using a method known as Zobrist hashing.  See the Texinfo documentation
 * (Reading/Hashing) for more information.  
 */


#ifndef _HASH_H_
#define _HASH_H_

/* Hash values and the compact board representation should use the
 * longest integer type that the platform can handle efficiently.
 * Typically this would be a 32 bit integer on a 32 bit platform and a
 * 64 bit integer on a 64 bit platform.
 *
 * Our preliminary assumption is that unsigned long has this
 * characteristic. Should it turn out to be false for some platform
 * we'll add conditional code to choose some other type.
 *
 * At the few places in the code where the actual size of these types
 * matter, the code should use sizeof(type) to test for this. Notice
 * that ISO C guarantees a long to be at least 32 bits.
 *
 * On (future) platforms with word length 128 bits or more, it might
 * be a waste to use more than 64 bit hashvalues, since the decreased
 * risk for hash collisions probably isn't worth the increased storage
 * cost.
 */
typedef unsigned long Hashvalue;
typedef unsigned long Compacttype;

/* for testing: Enables a lot of checks. */
#define CHECK_HASHING 0

/* Old hashing. */
#if (HASHING_SCHEME==1)		
#define NUM_HASHVALUES 		1
#define FULL_POSITION_IN_HASH 	1
#endif

/* Proposed new hashing. */
#if (HASHING_SCHEME==2)

/* How many bits should be used at least for hashing? Set this to 32 for
 * some memory save and speedup, at the cost of occasional irreproducable
 * mistakes (and possibly assertion failures). 
 * With 64 bits, there should be less than one such mistake in 10^9 games.
 * Set this to 96 if this is not safe enough for you.
 */
#define MIN_HASHBITS 		64		

#define NUM_HASHVALUES 		(MIN_HASHBITS / ( 8 * SIZEOF_LONG))
#define FULL_POSITION_IN_HASH 	0	/* Set this to 1 for debugging. */
#endif

/* Use this for self-defined values. */
#if (HASHING_SCHEME==3)
#define NUM_HASHVALUES 		?
#define FULL_POSITION_IN_HASH 	?
#endif


/*
 * We define a special compact representation of the board for the 
 * positions, used if FULL_POSITION_IN_HASH is set. In this representation
 * each location is represented by 2 bits with 0 meaning EMPTY, 1 meaning
 * WHITE and 2 meaning BLACK as defined in gnugo.h.
 * COMPACT_BOARD_SIZE is the size of such a compact representation
 * for the maximum board size allowed.
 *
 * POINTSPERCOMPACT is the number of intersections that fits into a
 * Compacttype. COMPACT_BOARD_SIZE contains the number of Compacttype
 * that is needed to contain a board of size MAX_BOARD. We would like 
 * to have this as a variable instead of a macro since the macro could
 * waste one word, but it is used in the sizeing of Hashposition.
 *
 * A go position consists of the board, possibly a ko point but NOT the
 * player to move.  This will not let us handle the super ko rule, but
 * we deem this sufficient for now.
 *
 * The ko point is defined as the point where, on the last move, one
 * stone was captured.  It is illegal for the player to move to place
 * a stone on this point.  To do so would either be suicide, which is
 * illegal anyhow, or a violation of the ko rule.  If there is no ko
 * going on, ko_pos == -1;
 */

#define POINTSPERCOMPACT    ((int) sizeof(Compacttype) * 4)
#define COMPACT_BOARD_SIZE  ((MAX_BOARD) * (MAX_BOARD) / POINTSPERCOMPACT + 1)

#if FULL_POSITION_IN_HASH
typedef struct hashposition_t {
  Compacttype  board[COMPACT_BOARD_SIZE];
  int          ko_pos;
} Hashposition;
#endif


/*
 * This struct is maintained by the machinery that updates the board
 * to provide incremental hashing. Examples: trymove(), play_move(), ...
 */

typedef struct {
  Hashvalue     hashval[NUM_HASHVALUES];
#if FULL_POSITION_IN_HASH
  Hashposition  hashpos;
#endif
} Hash_data;


void hash_init(void);
#if FULL_POSITION_IN_HASH
int hashposition_compare(Hashposition *pos1, Hashposition *pos2);
void hashposition_dump(Hashposition *pos, FILE *outfile);
#endif

void hashdata_recalc(Hash_data *hd, Intersection *board, int ko_pos);
int hashdata_compare(Hash_data *hd1, Hash_data *hd2);
void hashdata_invert_ko(Hash_data *hd, int pos);
void hashdata_invert_stone(Hash_data *hd, int pos, int color);
void hashdata_set_tomove(Hash_data *hd, int to_move);

int hashdata_diff_dump(Hash_data *key1, Hash_data *key2);

#endif

/* =========================================================================*/

/*emgena: cache.h */
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

#include <stdio.h>

/*
 * This file, together with engine/hash.c implements hashing of go positions
 * using a method known as Zobrist hashing.  See the Texinfo documentation
 * (Reading/Hashing) for more information.  
 */

#ifndef _CACHE_H_
#define _CACHE_H_

/* Dump (almost) all read results. */
#define TRACE_READ_RESULTS 0

/*
 * This struct contains the attack / defense point and the result.
 * It is kept in a linked list, and each position has a list of 
 * these.
 *
 * When a new result node is created, 'status' is set to 1 'open'.
 * This is then set to 2 'closed' when the result is entered. The main
 * use for this is to identify open result nodes when the hashtable is
 * partially cleared. Another potential use for this field is to
 * identify repeated positions in the reading, in particular local
 * double or triple kos.
 *
 * The data1 field packs into 32 bits the following
 * fields:
 *
 * komaster:  3 bits (EMPTY, BLACK, WHITE, or GRAY)
 * kom_pos : 10 bits (allows MAX_BOARD up to 31)
 * routine :  4 bits (currently 10 different choices)
 * str1    : 10 bits
 * stackp  :  5 bits (actually remaining depth, depth - stackp)
 *
 * FIXME: Rename stackp to something like remaining_depth at some
 *        appropriate time.
 *
 * The data2 field packs into 32 bits the following
 * fields:
 *
 * status :   2 bits (0 free, 1 open, 2 closed)
 * result1:   4 bits
 * result2:   4 bits
 * move   :  10 bits
 * str2   :  10 bits
 */

typedef struct read_result_t {
  unsigned int data1;	
  unsigned int data2;

  struct read_result_t *next;
} Read_result;

/* Bit mask for the input bits in the data2 field. */
#define RR_INPUT_DATA2 0x3ff

/* Get parts of a Read_result identifying the input data. */
#define rr_get_komaster(rr)   (((rr).data1  >> 29) & 0x07)
#define rr_get_kom_pos(rr)    (((rr).data1  >> 19) & 0x3ff)
#define rr_get_routine(rr)    (((rr).data1  >> 15) & 0x0f)
#define rr_get_str1(rr)       (((rr).data1  >>  5) & 0x3ff)
#define rr_get_stackp(rr)     (((rr).data1  >>  0) & 0x1f)
#define rr_get_str2(rr)       (((rr).data2  >>  0) & 0x3ff)
#define rr_get_str(rr)        rr_get_str1(rr)

/* Set corresponding parts. */
#define rr_input_data1(routine, komaster, kom_pos, str1, stackp) \
	(((((((((komaster) << 10) | (kom_pos)) << 4) \
	  | (routine)) << 10) | (str1)) << 5) | (stackp));
#define rr_input_data2(str2) (str2) \

/* Set input data fields and at the same time set status to open. */
#define rr_set_input_data(rr, routine, komaster, kom_pos, str, stackp) \
       do { \
         (rr).data1 = rr_input_data1(routine, komaster, kom_pos, str, stackp);\
         (rr).data2 = (((rr).data2 & ~0x300003ff) | (1 << 28));\
       } while (0)

/* Variation for two distinct strings. */
#define rr_set_input_data2(rr, routine, komaster, kom_pos, str1, str2, stackp)\
       do { \
         (rr).data1 = rr_input_data1(routine, komaster, kom_pos, \
                                     str1, stackp); \
         (rr).data2 = (((rr).data2 & ~0x3ff) | (1 << 28) \
                       | rr_input_data2(str2)); \
       } while (0)

/* Get parts of a Read_result constituting the result of a search. */
#define rr_get_status(rr)      (((rr).data2 >> 28) & 0x03)
#define rr_get_result1(rr)     (((rr).data2 >> 24) & 0x0f)
#define rr_get_result2(rr)     (((rr).data2 >> 20) & 0x0f)
#define rr_get_move(rr)        (((rr).data2 >> 10) & 0x3ff)
#define rr_get_result(rr)      rr_get_result1(rr)

/* Set corresponding parts. */
#define rr_set_result_move(rr, result, move) \
	(rr).data2 = (((rr).data2 & 0x3ff) \
          | (2 << 28) | (((result) & 0x0f) << 24) | (((move) & 0x3ff) << 10))

/* Variation with two results. */
#define rr_set_result_move2(rr, result1, result2, move) \
	(rr).data2 = (((rr).data2 & 0x3ff) | (2 << 28) \
                      | (((result1) & 0x0f) << 24) \
                      | (((result2) & 0x0f) << 20) \
                      | (((move) & 0x3ff) << 10))

/*
 * The hash table consists of hash nodes.  Each hash node consists of
 * The hash value for the position it holds, the position itself and
 * the actual information which is purpose of the table from the start.
 *
 * There is also a pointer to another hash node which is used when
 * the nodes are sorted into hash buckets (see below).
 */

typedef struct hashnode_t {
  Hash_data            key;
  Read_result         *results;	/* The results of previous readings */

  struct hashnode_t   *next;
} Hashnode;


/*
 * The hash table consists of three parts:
 * - The hash table proper: a number of hash buckets with collisions
 *   being handled by a linked list.
 * - The hash nodes.  These are allocated at creation time and are 
 *   never removed or reallocated in the current implementation.
 * - The search results.  Since many different searches can
 *   be done in the same position, there should be more of these than
 *   hash nodes.
 */

typedef struct hashtable {
  int            hashtablesize;	/* Number of hash buckets */
  Hashnode     **hashtable;	/* Pointer to array of hashnode lists */

  int            num_nodes;	/* Total number of hash nodes */
  Hashnode      *all_nodes;	/* Pointer to all allocated hash nodes. */
  int            free_node;	/* Index to next free node. */

  int            num_results;	/* Total number of results */
  Read_result   *all_results;	/* Pointer to all allocated results. */
  int            free_result;	/* Index to next free result. */
} Hashtable;


void read_result_dump(Read_result *result, FILE *outfile);
void hashtable_dump(Hashtable *table, FILE *outfile);
void hashnode_dump(Hashnode *node, FILE *outfile);

/* ================================================================ */

/* Macros used from reading.c and owl.c to store and retrieve read
 * results.
 */

#if TRACE_READ_RESULTS

#define TRACE_CACHED_RESULT(rr) \
      gprintf("%o%s %1m %d %d %1m (cached) ", read_function_name, \
	      q, stackp, \
	      rr_get_result(rr), \
	      rr_get_move(rr)); \
      dump_stack();

#define TRACE_CACHED_RESULT2(rr) \
      gprintf("%o%s %1m %1m %d %d %d %1m (cached) ", read_function_name, \
	      q1, q2, stackp, \
	      rr_get_result1(rr), \
	      rr_get_result2(rr), \
	      rr_get_move(rr)); \
      dump_stack();

#define SETUP_TRACE_INFO(name, str) \
  const char *read_function_name = name; \
  int q = find_origin(str);

#define SETUP_TRACE_INFO2(name, str1, str2) \
  const char *read_function_name = name; \
  int q1 = find_origin(str1); \
  int q2 = find_origin(str2);

#else

#define TRACE_CACHED_RESULT(rr)
#define TRACE_CACHED_RESULT2(rr)

#define SETUP_TRACE_INFO(name, str) \
  const char *read_function_name = name; \
  int q = str;

#define SETUP_TRACE_INFO2(name, str1, str2) \
  const char *read_function_name = name; \
  int q1 = str1; \
  int q2 = str2;

#endif

/* Trace messages in decidestring/decidedragon sgf file. */
void sgf_trace(const char *func, int str, int move, int result,
	       const char *message);
/* Trace messages in decideconnection/decidesemeai sgf file. */
void sgf_trace2(const char *func, int str1, int str2, int move, int result,
		const char *message);

/* Macro to hide the call to sgf_trace(). Notice that a little black
 * magic is going on here. Before using this macro, SETUP_TRACE_INFO
 * must have been called to provide the variables read_function_name
 * and q. These must of course not be used for anything else in
 * the function.
 */
#define SGFTRACE(move, result, message) \
  if (sgf_dumptree) \
    sgf_trace(read_function_name, q, move, result, message)

/* Corresponding macro for use in connection or semeai reading, where
 * two groups are involved.
 */
#define SGFTRACE2(move, result, message) \
  if (sgf_dumptree) \
    sgf_trace2(read_function_name, q1, q2, move, result, message)


extern Hashtable *movehash;

int get_read_result(int routine, int komaster, int kom_pos,
		    int *str, Read_result **read_result);
int get_read_result2(int routine, int komaster, int kom_pos,
		     int *str1, int *str2, Read_result **read_result);

/* ================================================================ */

/*
 * These macros should be used in all the places where we want to
 * return a result from a reading function and where we want to
 * store the result in the hash table at the same time.
 */
#if !TRACE_READ_RESULTS

#define READ_RETURN0(read_result) \
  do { \
    if (read_result) { \
      rr_set_result_move(*(read_result), 0, 0); \
    } \
    return 0; \
  } while (0)

#define READ_RETURN(read_result, point, move, value) \
  do { \
    if ((value) != 0 && (point) != 0) *(point) = (move); \
    if (read_result) { \
      rr_set_result_move(*(read_result), (value), (move)); \
    } \
    return (value); \
  } while (0)

#define READ_RETURN_SEMEAI(read_result, point, move, value_a, value_b) \
  do { \
    if ((value_a) != 0 && (point) != 0) *(point) = (move); \
    if (read_result) { \
      rr_set_result_move2(*(read_result), (value_a), (value_b), (move)); \
    } \
    return; \
  } while (0)

#define READ_RETURN_CONN(read_result, point, move, value) \
  do { \
    if ((value) != 0 && (point) != 0) *(point) = (move); \
    if (read_result) { \
      rr_set_result_move(*(read_result), (value), (move)); \
    } \
    return (value); \
  } while (0)

#else

#define READ_RETURN0(read_result) \
  do { \
    if (read_result) { \
      rr_set_result_move(*(read_result), 0, 0); \
    } \
    gprintf("%o%s %1m %d 0 0 0 ", read_function_name, q, stackp); \
    dump_stack(); \
    return 0; \
  } while (0)

#define READ_RETURN(read_result, point, move, value) \
  do { \
    if ((value) != 0 && (point) != 0) *(point) = (move); \
    if (read_result) { \
      rr_set_result_move(*(read_result), (value), (move)); \
    } \
    gprintf("%o%s %1m %d %d %d ", read_function_name, q, stackp, \
	    (value), (move)); \
    dump_stack(); \
    return (value); \
  } while (0)
  
#define READ_RETURN_SEMEAI(read_result, point, move, value_a, value_b) \
  do { \
    if ((value_a) != 0 && (point) != 0) *(point) = (move); \
    if (read_result) { \
      rr_set_result_move2(*(read_result), (value_a), (value_b), (move)); \
    } \
    gprintf("%o%s %1m %1m %d %d %d %d ", read_function_name, q1, q2, stackp, \
	    (value_a), (value_b), (move)); \
    dump_stack(); \
    return; \
  } while (0)

#define READ_RETURN_CONN(read_result, point, move, value) \
  do { \
    if ((value) != 0 && (point) != 0) *(point) = (move); \
    if (read_result) { \
      rr_set_result_move(*(read_result), (value), (move)); \
    } \
    gprintf("%o%s %1m %1m %d %d %d ", read_function_name, q1, q2, stackp, \
	    (value), (move)); \
    dump_stack(); \
    return (value); \
  } while (0)

#endif

/* ================================================================ */
/* Routine numbers. */

#define FIND_DEFENSE    0
#define DEFEND1         1
#define DEFEND2         2
#define DEFEND3         3
#define DEFEND4         4

#define ATTACK          5
#define ATTACK2         6
#define ATTACK3         7

#define OWL_ATTACK      8
#define OWL_DEFEND      9
#define SEMEAI         10

#define CONNECT        11
#define DISCONNECT     12

#define MAX_ROUTINE     DISCONNECT
#define NUM_ROUTINES    (MAX_ROUTINE + 1)
  
#endif


/* ================================================================ */
/* This has actually nothing to do with caching, but is useful in
 * the same places where the caching is.
 */
  
/* Macro to use when saving ko results while continuing to look for an
 * unconditional result. It's assumed that we have tried the move at
 * (move) and then called an attack or defense function giving the
 * result passed in the code parameter.
 *
 * In general we prefer not to have to do the first ko threat. Thus a
 * savecode KO_A is always better than a savecode KO_B. Also we always
 * prefer to keep the old move if we get the same savecode once more,
 * on the assumption that the moves have been ordered with the
 * presumably best one first.
 *
 * Notice that the savecode may be either 0 (nothing found so far), KO_B
 * or KO_A. Occasionally savecode WIN is also used, indicating an effective
 * but not preferred move, typically because it's either a sacrifice
 * or a backfilling move. If possible, we prefer making non-sacrifice
 * and direct moves. Of course savecode WIN is better than KO_A or KO_B.
 */


#define UPDATE_SAVED_KO_RESULT(savecode, save, code, move) \
  if (code != 0 && (WIN - code) > savecode) { \
    save = move; \
    savecode = WIN - code; \
  } \

/* Same as above, except this should be used when there's no
 * intervening trymove(). Thus we shouldn't reverse the save code.
 */
#define UPDATE_SAVED_KO_RESULT_UNREVERSED(savecode, save, code, move) \
  if (code != WIN && code > savecode) { \
    save = move; \
    savecode = code; \
  }

/* ====================================================================== */

/* ============================================================================*/

/* emgena: liberty.h */
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

#ifndef _LIBERTY_H_
#define _LIBERTY_H_

/* #include "gnugo.h" */

/* local versions of absolute value, min and max */

#define gg_abs(x) ((x) < 0 ? -(x) : (x))
#define gg_min(a, b) ((a)<(b) ? (a) : (b))
#define gg_max(a, b) ((a)<(b) ? (b) : (a))

/* Avoid compiler warnings with unused parameters */
#define UNUSED(x)  (void)x


/* ================================================================ */
/*                           public variables                       */
/* ================================================================ */


/* A few variables below are of types defined in hash.h. */
/* #include "hash.h" */

/* Other modules get read-only access to this variable. */
extern Hash_data    hashdata;



/* ================================================================ */


#define FALSE_EYE          1
#define HALF_EYE           2
#define INHIBIT_CONNECTION 4


/* A string with n stones can have at most 2(n+1) liberties. From this
 * follows that an upper bound on the number of liberties of a string
 * on a board of size N^2 is 2/3 (N^2+1).
 */
#define MAXLIBS   (2*(MAX_BOARD*MAX_BOARD + 1)/3)
/* This is a smaller, practical number of liberties that we care to keep track of. */
#define MAX_LIBERTIES 20


/* This is an upper bound of the number of strings that can exist on
 * the board simultaneously.  
 * FIXME: This is not sufficiently large;  above stackp==0, the incremental 
 *   board code doesn't necessarily re-use all indices.  This is a problem
 *   only in very pathological cases, and is extremely unlikely to occur in
 *   practice.
 */
#define MAX_STRINGS (2 * MAX_BOARD * MAX_BOARD / 3)

/* Per gf: Unconditional_life() can get very close to filling the 
 * entire board under certain circumstances. This was discussed in 
 * the list around August 21, 2001, in a thread with the subject 
 * "gnugo bug logs".
 */
#define MAXSTACK  MAX_BOARD * MAX_BOARD
#define MAXCHAIN  160

/* 1D board macros.
 * Note that POS(-1, -1) == 0
 * DELTA() is defined so that POS(i+di, j+dj) = POS(i, j) + DELTA(di, dj).
 */
#define BOARDSIZE     ((MAX_BOARD + 2) * (MAX_BOARD + 1) + 1)
#define BOARDMIN      (MAX_BOARD + 2)
#define BOARDMAX      (MAX_BOARD + 1) * (MAX_BOARD + 1)
#define POS(i, j)     ((MAX_BOARD + 2) + (i) * (MAX_BOARD + 1) + (j))
#define DELTA(di, dj) ((di) * (MAX_BOARD + 1) + (dj))
#define I(pos)        ((pos) / (MAX_BOARD + 1) - 1)
#define J(pos)        ((pos) % (MAX_BOARD + 1) - 1)
#define PASS_MOVE     0
#define NO_MOVE       PASS_MOVE
#define NS            (MAX_BOARD + 1)
#define WE            1
#define SOUTH(pos)    ((pos) + NS)
#define WEST(pos)     ((pos) - 1)
#define NORTH(pos)    ((pos) - NS)
#define EAST(pos)     ((pos) + 1)
#define SW(pos)       ((pos) + NS - 1)
#define NW(pos)       ((pos) - NS - 1)
#define NE(pos)       ((pos) - NS + 1)
#define SE(pos)       ((pos) + NS + 1)
#define SS(pos)       ((pos) + 2 * NS)
#define WW(pos)       ((pos) - 2)
#define NN(pos)       ((pos) - 2 * NS)
#define EE(pos)       ((pos) + 2)
		      
#define BOARD(i, j)   board[POS(i, j)]


/* This struct holds the internal board state.
 */
struct board_state {
  int board_size;

  Intersection board[BOARDSIZE];
  int board_ko_pos;
  int black_captured;
  int white_captured;

  Intersection initial_board[BOARDSIZE];
  int initial_board_ko_pos;
  int initial_white_captured;
  int initial_black_captured;
  int move_history_color[MAX_MOVE_HISTORY];
  int move_history_pos[MAX_MOVE_HISTORY];
  int move_history_pointer;

  float komi;
  int move_number;
};


/* board utility functions */
int find_origin(int str);
int chainlinks(int str, int adj[MAXCHAIN]);
int chainlinks2(int str, int adj[MAXCHAIN], int lib);
int chainlinks3(int str, int adj[MAXCHAIN], int lib);


/* This is increased by one anytime a move is (permanently) played or
 * the board is cleared.
 */
extern int position_number;


/* Detect vertex on edge. */
int is_edge_vertex(int pos);


/* Count and/or find liberties at (pos). */
int countlib(int str);
int findlib(int str, int maxlib, int *libs);
int fastlib(int pos, int color, int ignore_capture);
int approxlib(int pos, int color, int maxlib, int *libs);
int count_common_libs(int str1, int str2);
int find_common_libs(int str1, int str2, int maxlib, int *libs);
int have_common_lib(int str1, int str2, int *lib);


void start_timer(int n);
double time_report(int n, const char *occupation, int move, double mintime);

void update_random_seed(void);


/* Play at (pos) and then count the liberties. */
int accurate_approxlib(int pos, int color, int maxlib, int *libs);

/* Check for self atari. */
int is_self_atari(int pos, int color);

/* Count the number of stones in a string. */
int countstones(int str);
int findstones(int str, int maxstones, int *stones);

/* Exported from incremental_board.c so that reading.c can use it. */
void incremental_order_moves(int move, int color, int string,
			     int *number_edges, int *number_same_string,
			     int *number_own, int *number_opponent,
			     int *captured_stones, int *threatened_stones,
			     int *saved_stones, int *number_open);

  
void dump_stack(void);
void report_worm(int m, int n);
void ascii_report_worm(char *string);
void report_dragon(int m, int n);
void ascii_report_dragon(char *string);
struct dragon_data2 * dragon2_func(int pos);

/* prototypes for reorientation functions */

void rotate2(int i, int j, int *ri, int *rj, int rot);
void inv_rotate2(int i, int j, int *ri, int *rj, int rot);
int rotate1(int pos, int rot);
int inv_rotate1(int pos, int rot);

/* Is this point inside the board? */
#if 0
#define ON_BOARD2(i, j) ((i)>=0 && (j)>=0 && (i)<board_size && (j)<board_size)
#else
/*
 * For the case when expr can only be slightly negative,
 *    if (expr < 0 || expr > something)
 * is equivalent to
 *    if ((unsigned) expr > something)
 *
 * (I think gcc knows this trick, but it does no harm to
 *  encode it explicitly since it saves typing !)
 */
#define ON_BOARD2(i, j) ((unsigned) (i) < (unsigned) board_size &&\
		         (unsigned) (j) < (unsigned) board_size)
#endif

#define ASSERT_ON_BOARD2(i, j) ASSERT2(ON_BOARD2((i), (j)), (i), (j))

#define ON_BOARD1(pos) (((unsigned) (pos) < BOARDSIZE) && board[pos] != GRAY)
#define ON_BOARD(pos) (board[pos] != GRAY)
#define ASSERT_ON_BOARD1(pos) ASSERT1(ON_BOARD1(pos), (pos))

/* Coordinates for the eight directions, ordered
 * south, west, north, east, southwest, northwest, northeast, southeast.
 * Defined in utils.c.
 */
extern int deltai[8]; /* = { 1,  0, -1,  0,  1, -1, -1, 1}; */
extern int deltaj[8]; /* = { 0, -1,  0,  1, -1, -1,  1, 1}; */
extern int delta[8];  /* = { NS, -1, -NS, 1, NS-1, -NS-1, -NS+1, NS+1}; */

void store_board(struct board_state *state);
void restore_board(struct board_state *state);

/* Forward struct declarations. */
struct pattern;
struct pattern_db;
struct fullboard_pattern;
struct half_eye_data;
struct movelist;
struct tree_node_list;
struct match_node;

/*
 * Try to match a pattern in the database to the board. Callback for
 * each match
 */
typedef void (*matchpat_callback_fn_ptr)(int m, int n, int color,
                                         struct pattern *, int rotation,
                                         void *data);
typedef void (*fullboard_matchpat_callback_fn_ptr)(int ti, int tj,
                                                   struct fullboard_pattern *,
                                                   int rotation);
void matchpat(matchpat_callback_fn_ptr callback, int color,
	      struct pattern_db *pdb, void *callback_data,
	      char goal[BOARDMAX]);
void matchpat_goal_anchor(matchpat_callback_fn_ptr callback, int color,
	      struct pattern_db *pdb, void *callback_data,
	      char goal[BOARDMAX], int anchor_in_goal);
void fullboard_matchpat(fullboard_matchpat_callback_fn_ptr callback,
			int color, struct fullboard_pattern *pattern);
void dfa_match_init(void);
void tree_match_init(void);
void tree_initialize_pointers(struct tree_node_list *tnl,
                              struct match_node *matches,
                              int tnl_size,
                              int matches_size);

void reading_cache_init(int bytes);
void reading_cache_clear(void);

/* reading.c */
int attack(int str, int *move);
int find_defense(int str, int *move);
int attack_and_defend(int str,
		      int *attack_code, int *attack_point,
		      int *defend_code, int *defense_point);
int attack_either(int astr, int bstr);
int defend_both(int astr, int bstr);
int break_through(int apos, int bpos, int cpos);
int attack_threats(int pos, int max_points, int moves[], int codes[]);

int restricted_defend1(int str, int *move, int komaster, int kom_pos,
		       int num_forbidden_moves, int *forbidden_moves);
int restricted_attack2(int str, int *move, int komaster, int kom_pos,
		       int num_forbidden_moves, int *forbidden_moves);

int simple_ladder(int str, int *move);
#define MOVE_ORDERING_PARAMETERS 67
void tune_move_ordering(int params[MOVE_ORDERING_PARAMETERS]);
void draw_reading_shadow(void);
void purge_persistent_reading_cache(void);
void reading_hotspots(float values[BOARDMAX]);

/* readconnect.c */
int string_connect(int str1, int str2, int *move);
int disconnect(int str1, int str2, int *move);
int non_transitivity(int str1, int str2, int str3, int *move);

int liberty_of_string(int pos, int str);
int second_order_liberty_of_string(int pos, int str);
int neighbor_of_string(int pos, int str);
int same_string(int str1, int str2);
int adjacent_strings(int str1, int str2);
int is_ko(int pos, int color, int *ko_pos);
int is_ko_point(int pos);
int komaster_trymove(int pos, int color,
		     const char *message, int str,
		     int komaster, int kom_pos,
		     int *new_komaster, int *new_kom_pos,
		     int *is_conditional_ko, int consider_conditional_ko);
int komaster_is_empty(int komaster, int kom_pos);
const char *komaster_to_string(int komaster, int kom_pos);
int does_capture_something(int pos, int color);
void mark_string(int str, char mx[BOARDMAX], char mark);
int move_in_stack(int pos, int cutoff);
void get_move_from_stack(int k, int *move, int *color);
int stones_on_board(int color);
int obvious_false_eye(int pos, int color);
int owl_topological_eye(int pos, int color);
int vital_chain(int pos);
int confirm_safety(int move, int color, int size, int *defense_point,
		   int saved_dragons[BOARDMAX], int saved_worms[BOARDMAX]);
void set_depth_values(int level);
void modify_depth_values(int n);
void increase_depth_values(void);
void decrease_depth_values(void);
void set_temporary_depth_values(int d, int b, int f, int k, 
				int br, int b2, int ss);
void restore_depth_values(void);
int safe_move(int move, int color);
void join_dragons(int d1, int d2);
int dragon_escape(char goal[BOARDMAX], int color, int escape_value[BOARDMAX]);
int is_same_dragon(int d1, int d2);
int are_neighbor_dragons(int d1, int d2);
int lively_dragon_exists(int color);
int is_same_worm(int w1, int w2);
int is_worm_origin(int w, int pos);
void propagate_worm(int pos);
void transform(int i, int j, int *ti, int *tj, int trans);
int offset(int i, int j, int basepos, int trans);
void find_cuts(void);
void find_connections(void);
void modify_eye_spaces(void);

/* movelist.c */
int movelist_move_known(int move, int max_points, int points[], int codes[]);
void movelist_change_point(int move, int code, int max_points, 
			   int points[], int codes[]);


/* functions to add (or remove) move reasons */
void clear_move_reasons(void);
void add_lunch(int eater, int food);
void remove_lunch(int eater, int food);
void add_attack_move(int pos, int ww, int code);
void add_defense_move(int pos, int ww, int code);
void add_attack_threat_move(int pos, int ww, int code);
void remove_attack_threat_move(int pos, int ww);
void add_defense_threat_move(int pos, int ww, int code);
void add_connection_move(int pos, int dr1, int dr2);
void add_cut_move(int pos, int dr1, int dr2);
void add_antisuji_move(int pos);
void add_semeai_move(int pos, int dr);
void add_semeai_threat(int pos, int dr);

void add_owl_attack_move(int pos, int dr, int code);
void add_owl_defense_move(int pos, int dr, int code);
void add_owl_attack_threat_move(int pos, int dr, int code);
void add_owl_defense_threat_move(int pos, int dr, int code);
void add_owl_prevent_threat_move(int pos, int dr);
void add_owl_uncertain_defense_move(int pos, int dr);
void add_owl_uncertain_attack_move(int pos, int dr);

void add_my_atari_atari_move(int pos, int size);
void add_your_atari_atari_move(int pos, int size);
void add_vital_eye_move(int pos, int eyespace, int color);
void add_block_territory_move(int pos);
void add_expand_territory_move(int pos);
void add_expand_moyo_move(int pos);
void add_strategical_attack_move(int pos, int dr);
void add_strategical_defense_move(int pos, int dr);
void add_worthwhile_threat_move(int pos);
void add_replacement_move(int from, int to);
int  set_minimum_move_value(int pos, float value);
void set_maximum_move_value(int pos, float value);
void set_minimum_territorial_value(int pos, float value);
void set_maximum_territorial_value(int pos, float value);
void add_shape_value(int pos, float value);
void add_followup_value(int pos, float value);
void add_reverse_followup_value(int pos, float value);

/* Parameters to add_either_move and add_all_move */
#define ATTACK_STRING  1
#define DEFEND_STRING  2
void add_either_move(int pos, int reason1, int target1,
		     int reason2, int target2);
void add_all_move(int pos, int reason1, int target1,
		  int reason2, int target2);


int get_attack_threats(int pos, int max_strings, int strings[]);
int get_defense_threats(int pos, int max_strings, int strings[]);
void get_saved_worms(int pos, int saved[BOARDMAX]);
void get_saved_dragons(int pos, int saved[BOARDMAX]);


int owl_lively(int pos);
int owl_escape_value(int pos);
int owl_goal_dragon(int pos);
int owl_eyespace(int apos, int bpos);
int owl_big_eyespace(int apos, int bpos);
int owl_proper_eye(int apos, int bpos);
void owl_reasons(int color);

void unconditional_life(int unconditional_territory[BOARDMAX], int color);
void find_superstring(int str, int *num_stones, int *stones);
void find_superstring_liberties(int str, int *liberties, int *libs,
                                int liberty_cap);
void find_proper_superstring_liberties(int str, int *liberties, int *libs, 
                                       int liberty_cap);
void find_superstring_stones_and_liberties(int str, int *num_stones,
					   int *stones, int *liberties,
					   int *libs, int liberty_cap);
void superstring_chainlinks(int str, int *num_adj, int adj[MAXCHAIN],
                            int liberty_cap);
void proper_superstring_chainlinks(int str, int *num_adj, 
                                   int adj[MAXCHAIN], int liberty_cap);

int placehand(int handicap);          /* place stones on board only */


/* Various different strategies for finding a move */
void fuseki(int color);
void semeai(int color);
void new_semeai(int color);
void small_semeai(int save_verbose);
void shapes(int color);
void endgame_shapes(int color);

void combinations(int color);
int atari_atari(int color, int *attack_move, int *defense_move,
		int save_verbose);
int atari_atari_confirm_safety(int color, int tpos, int *move,
			       int minsize, int saved_dragons[BOARDMAX],
			       int saved_worms[BOARDMAX]);

int review_move_reasons(int *move, float *val, int color,
			float pure_threat_value, float lower_bound);
int fill_liberty(int *move, int color);
int aftermath_genmove(int *aftermath_move, int color,
		      int under_control[BOARDMAX],
		      int do_capture_dead_stones);

int owl_attack(int target, int *attack_point, int *certain);
int owl_defend(int target, int *defense_point, int *certain);
int owl_threaten_attack(int target, int *attack1, int *attack2);
int owl_threaten_defense(int target, int *defend1, int *defend2);
int owl_does_defend(int move, int target);
int owl_confirm_safety(int move, int target, int *defense_point);
int owl_does_attack(int move, int target);
int owl_connection_defends(int move, int target1, int target2);
int owl_substantial(int str);
void owl_analyze_semeai(int apos, int bpos, 
			int *resulta, int *resultb, int *move,
			int owl);
void purge_persistent_owl_cache(void);
void owl_hotspots(float values[BOARDMAX]);

void change_attack(int str, int move, int acode);
void change_defense(int str, int move, int dcode);
void change_attack_threat(int str, int move, int acode);
void change_defense_threat(int str, int move, int dcode);
int attack_move_known(int move, int str);
int defense_move_known(int move, int str);
int attack_threat_move_known(int move, int str);
int defense_threat_move_known(int move, int str);
void worm_reasons(int color);

int does_attack(int move, int str);
int does_defend(int move, int str);
int double_atari(int move, int color);
int play_attack_defend_n(int color, int do_attack, int num_moves, ...);
int play_attack_defend2_n(int color, int do_attack, int num_moves, ...);
int play_break_through_n(int color, int num_moves, ...);
int play_connect_n(int color, int do_connect, int num_moves, ...);
int cut_possible(int pos, int color);
int defend_against(int move, int color, int apos);
int somewhere(int color, int num_moves, ...);

/* Printmoyo values, specified by -m flag. */
#define PRINTMOYO_TERRITORY         0x01
#define PRINTMOYO_MOYO              0x02
#define PRINTMOYO_AREA              0x04
/* The following have been borrowed by the influence functions below. */
#define PRINTMOYO_INITIAL_INFLUENCE 0x08
#define PRINTMOYO_PRINT_INFLUENCE   0x10
#define PRINTMOYO_NUMERIC_INFLUENCE 0x20
#define PRINTMOYO_PERMEABILITY      0x40
#define PRINTMOYO_STRENGTH          0x80
#define PRINTMOYO_ATTENUATION       0x100
#define PRINTMOYO_VALUE_TERRITORY   0x200

/* These values are used to communicate whether stones have been
 * saved, captured, or neither, when computing the influence effects
 * of a move.
 */
#define INFLUENCE_UNCHANGED_STONE 0
#define INFLUENCE_SAVED_STONE     1
#define INFLUENCE_CAPTURED_STONE  2

/* This format is used when exporting the moyo segmentation. */
#define MAX_MOYOS MAX_BOARD*MAX_BOARD

struct moyo_data
{
  int number; /* Number of moyos. */
  int segmentation[BOARDMAX]; /* Numbers the moyos. */
  int size[MAX_MOYOS];
  int owner[MAX_MOYOS];
};

/* Influence functions. */
void compute_initial_influence(int color, int dragons_known);
void resegment_initial_influence(void);
float influence_delta_territory(int pos, int color,
				char saved_stones[BOARDMAX],
                                float *followup_value);
int influence_territory_color(int pos);
int influence_moyo_color(int pos);
int influence_moyo_color_opposite(int pos);
int influence_area_color(int pos);
int influence_get_moyo_size(int pos, int color);
void influence_get_moyo_segmentation(int opposite, struct moyo_data *moyo);
float influence_estimate_score(float moyo_coeff, float area_coeff);
void influence_mark_non_territory(int pos, int color);
float influence_initial_territory(int pos, int color);

void  old_estimate_score(int color, float *lower_bound, float *upper_bound);
float estimate_score(float *upper, float *lower);

void print_initial_influence(int color, int dragons_known);
void print_move_influence(int pos, int color, char saved_stones[BOARDMAX]);
void get_initial_influence(int color, int dragons_known,
                           float white_influence[BOARDMAX],
                           float black_influence[BOARDMAX],
                           int influence_regions[BOARDMAX]);
void get_move_influence(int move, int color, char saved_stones[BOARDMAX],
                        float white_influence[BOARDMAX],
                        float black_influence[BOARDMAX],
                        int influence_regions[BOARDMAX]);
void compute_escape_influence(char goal[BOARDMAX], int color,
                              int escape_value[BOARDMAX], int dragons_known);

/* Eye space functions. */
int is_eye_space(int pos);
int is_proper_eye_space(int pos);
int is_marginal_eye_space(int pos);
int max_eye_value(int pos);
void test_eyeshape(int eyesize, int *eye_vertices);


/* debugging support */
void move_considered(int move, float value);


/* SGF routines for debugging purposes in sgffile.c */
int sgffile_write_line(const char *line, ...);
void sgffile_dragon_status(int i, int j, int status);
void goaldump(char goal[BOARDMAX]);
void sgftree_printboard(struct SGFTree_t *tree);
void begin_sgftreedump(struct SGFTree_t *tree);
void end_sgftreedump(const char *filename);



/* ================================================================ */
/*                         global variables                         */
/* ================================================================ */

/* The board and the other parameters deciding the current position. */
extern int          board_size;             /* board size (usually 19) */
extern Intersection board[BOARDSIZE];       /* go board */
extern int          board_ko_pos;
extern int          black_captured;   /* num. of black stones captured */
extern int          white_captured;

extern Intersection initial_board[BOARDSIZE];
extern int          initial_board_ko_pos;
extern int          initial_white_captured;
extern int          initial_black_captured;
extern int          move_history_color[MAX_MOVE_HISTORY];
extern int          move_history_pos[MAX_MOVE_HISTORY];
extern int          move_history_pointer;

extern float        komi;
extern int          movenum;      /* movenumber - used for debug output */
		    
extern Intersection shadow[BOARDMAX];      /* reading tree shadow */

		    
extern int          disable_threat_computation;
extern int          disable_endgame_patterns;
extern int          doing_scoring;

/* Reading parameters */
extern int depth;               /* deep reading cutoff */
extern int backfill_depth;      /* deep reading cutoff */
extern int backfill2_depth;     /* deep reading cutoff */
extern int superstring_depth;   /* deep reading cutoff */
extern int branch_depth;        /* deep reading cutoff */
extern int fourlib_depth;       /* deep reading cutoff */
extern int ko_depth;            /* deep ko reading cutoff */
extern int aa_depth;            /* deep global reading cutoff */
extern int aa_threat_depth;
extern int owl_distrust_depth;  /* below this owl trusts the optics code */
extern int owl_branch_depth;    /* below this owl tries only one variation */
extern int owl_reading_depth;   /* owl does not read below this depth */
extern int owl_node_limit;      /* maximum number of nodes considered */
extern int level;               /* controls the strength of play */
extern int semeai_variations;   /* max variations considered reading semeai */
extern float best_move_values[10];
extern int best_moves[10];

extern int chinese_rules;
extern int experimental_semeai;      /* use experimental semeai module */
extern int experimental_connections; /* use experimental connection module */
extern int alternate_connections;    /* use alternate connection module */
extern int owl_threats;              /* compute owl threats */
extern int experimental_influence;   /* use experimental influence module */

extern int thrashing_dragon; /* Dead opponent's dragon trying to live */

/* Experimental reading */
extern char *rgoal;
extern int goallib;

extern int stackp;                /* stack pointer */
extern int count_variations;      /* count (decidestring) */
extern SGFTree *sgf_dumptree;


struct stats_data {
  int nodes;                     /* Number of visited nodes while reading */
  int position_entered;          /* Number of Positions entered. */
  int position_hits;             /* Number of hits of Positions. */
  int read_result_entered;       /* Number of Read_results entered. */
  int read_result_hits;          /* Number of hits of Read_results. */
  int hash_collisions;           /* Number of hash collisions. */
};

extern struct stats_data stats;


struct half_eye_data {
  float value;      /* Topological eye value. */
  int type;         /* HALF_EYE or FALSE_EYE; */
  int num_attacks;  /* number of attacking points */
  int attack_point[4];  /* the move to attack a topological halfeye */
  int num_defends;      /* number of defending points */
  int defense_point[4]; /* the move to defend a topological halfeye */
};

/* array of half-eye data */
extern struct half_eye_data half_eye[BOARDMAX];

/*
 * data concerning a worm. A copy is kept at each vertex of the worm.
 */

#define MAX_TACTICAL_POINTS 10

struct worm_data {
  int color;         /* its color */
  int size;          /* its cardinality */
  float effective_size; /* stones and surrounding spaces */
  int origin;        /* the origin of the string. Two vertices are in */
                     /* the same worm iff they have same origin. */
  int liberties;     /* number of liberties */
  int liberties2;    /* number of second order liberties */
  int liberties3;    /* third order liberties (empty vertices at distance 3) */
  int liberties4;    /* fourth order liberties */
  int lunch;         /* if lunch != 0 then lunch points to a boundary */
                     /* worm which can be captured easily. */
  int cutstone;      /* 1=potential cutting stone; 2=cutting stone */
  int cutstone2;     /* Number of potential cuts involving the worm. */
  int genus;         /* number of connected components of the complement, less one */
  int inessential;   /* 1=inessential worm */
  int invincible;    /* 1=strongly unconditionally non-capturable */
  int unconditional_status; /* ALIVE, DEAD, WHITE_BORDER, BLACK_BORDER, UNKNOWN */

  /* The following arrays keeps track of up to MAX_TACTICAL_POINTS
   * different attack, defense, attack threat, and defense threat
   * points with corresponding result codes. (0 = loss, 1 = bad ko, 2
   * = good ko, 3 = win). The arrays are guaranteed to be sorted with
   * respect to the codes so that the first element contains the best
   * result.
   */
  int attack_points[MAX_TACTICAL_POINTS];
  int attack_codes[MAX_TACTICAL_POINTS];
  int defense_points[MAX_TACTICAL_POINTS];
  int defend_codes[MAX_TACTICAL_POINTS];
  int attack_threat_points[MAX_TACTICAL_POINTS];
  int attack_threat_codes[MAX_TACTICAL_POINTS]; 
  int defense_threat_points[MAX_TACTICAL_POINTS];
  int defense_threat_codes[MAX_TACTICAL_POINTS];
};

extern struct worm_data worm[BOARDMAX];


/*
 * data concerning a dragon. A copy is kept at each stone of the string.
 */

struct dragon_data {
  int color;    /* its color                                                 */
  int id;       /* the index into the dragon2 array                          */
  int origin;   /* the origin of the dragon. Two vertices are in the same    */
                /* dragon iff they have same origin.                         */
  int size;     /* size of the dragon                                        */
  float effective_size; /* stones and surrounding spaces                     */
  int status;   /* (ALIVE, DEAD, UNKNOWN, CRITICAL)                          */
  int owl_threat_status;   /* CAN_THREATEN_ATTACK or CAN_THREATEN_DEFENSE    */
  int owl_status;          /* (ALIVE, DEAD, UNKNOWN, CRITICAL, UNCHECKED)    */
  int owl_attack_point;    /* vital point for attack                         */
  int owl_attack_code;     /* ko result code                                 */
#if 0
  int owl_attack_points[MAX_TACTICAL_POINTS];
  int owl_attack_codes[MAX_TACTICAL_POINTS];
#endif
  int owl_attack_certain;  /* 0 if owl reading node limit is reached         */

  int owl_second_attack_point;/* if attacker gets both attack points, wins   */
  int owl_defense_point;   /* vital point for defense                        */
  int owl_defense_code;    /* ko result code                                 */
  int owl_defense_certain; /* 0 if owl reading node limit is reached         */
  int owl_second_defense_point;/* if defender gets both attack points, wins  */
  int matcher_status;  /* status used by pattern matching                    */
};

extern struct dragon_data dragon[BOARDMAX];

/* Supplementary data concerning a dragon. Only one copy is stored per
 * dragon in the dragon2 array.
 */

#define MAX_NEIGHBOR_DRAGONS 10

struct dragon_data2 {
  int origin;                         /* the origin of the dragon            */
  int adjacent[MAX_NEIGHBOR_DRAGONS]; /* adjacent dragons                    */
  int neighbors;                      /* number of adjacent dragons          */
  int hostile_neighbors;              /* neighbors of opposite color         */
  int moyo;                           /* size of surrounding influence moyo  */
  int safety;                         /* a more detailed status estimate     */
  int escape_route; /* a measurement of likelihood of escape                 */
  int genus;    /* the number of eyes (approximately)                        */
  int heyes;    /* the number of half eyes                                   */
  int heye;     /* coordinates of a half eye                                 */
  int lunch;    /* if lunch != 0 then lunch points to a boundary worm which  */
                /* can be captured easily.                                   */
  int semeai;          /* true if a dragon is part of a semeai               */
  int semeai_margin_of_safety; /* if small, the semeai is close              */
};

/* dragon2 is dynamically allocated */
extern int number_of_dragons;
extern struct dragon_data2 *dragon2;

/* Macros for accessing the dragon2 data with board coordinates and
 * the dragon data with a dragon id.
 */
#if 1 /* Trust DRAGON2 accesses */
#define DRAGON2(pos) dragon2[dragon[pos].id]
#else
struct dragon_data2 * dragon2_func(int pos);
#define DRAGON2(pos) (*dragon2_func(pos))
#endif

#define DRAGON(d) dragon[dragon2[d].origin]

struct aftermath_data {
  int white_captured;
  int black_captured;
  int white_prisoners;
  int black_prisoners;
  int white_territory;
  int black_territory;
  int white_area;
  int black_area;
  int white_control[BOARDMAX];
  int black_control[BOARDMAX];
  int final_status[BOARDMAX];
};

struct eye_data {
  int color;/* BLACK, WHITE, BLACK_BORDERED, WHITE_BORDERED or GRAY_BORDERED */
  int esize;         /* size of the eyespace                                 */
  int msize;         /* number of marginal vertices                          */
  int origin;        /* The origin                                           */
  int maxeye;        /* number of eyes if defender plays first               */
  int mineye;        /* number of eyes if attacker plays first               */
  int attack_point;  /* vital point for attack                               */
  int defense_point; /* vital point for defense                              */
  int dragon;        /* origin of the surrounding dragon                     */

  /* The above fields are constant on the whole eyespace. */
  /* ---------------------------------------------------------------- */
  /* The below fields are not. */

  int marginal;             /* This vertex is marginal                    */
  int type;                 /* Various characteristics of the eyespace    */
  int neighbors;            /* number of neighbors in eyespace            */
  int marginal_neighbors;   /* number of marginal neighbors               */
  int cut;                  /* Opponent can cut at vertex.                */
};

typedef struct eye_data row_of_eye_data[BOARDMAX];

extern struct eye_data white_eye[BOARDMAX];
extern struct eye_data black_eye[BOARDMAX];

/* The following declarations have to be postponed until after the
 * definition of struct eye_data or struct half_eye_data.
 */

void compute_eyes(int pos, int *max, int *min,
                  int *attack_point, int *defense_point,
                  struct eye_data eye[BOARDMAX],
                  struct half_eye_data heye[BOARDMAX],
                  int add_moves, int color);
void compute_eyes_pessimistic(int pos, int *max, int *min,
                              int *pessimistic_min,
                              int *attack_point, int *defense_point,
                              struct eye_data eye[BOARDMAX],
                              struct half_eye_data heye[BOARDMAX]);
int recognize_eye2(int pos, int *attack_point,
		   int *defense_point, int *max, int *min,
		   struct eye_data eye[BOARDMAX],
		   struct half_eye_data heye[BOARDMAX],
                    int add_moves, int color);
void propagate_eye(int pos, struct eye_data eye[BOARDMAX]);
float topological_eye(int pos, int color,
		      struct eye_data b_eye[BOARDMAX],
		      struct eye_data w_eye[BOARDMAX],
		      struct half_eye_data heye[BOARDMAX]);
void add_false_eye(int pos, struct eye_data eye[BOARDMAX], 
		   struct half_eye_data heye[BOARDMAX]);
void make_domains(struct eye_data b_eye[BOARDMAX],
                  struct eye_data w_eye[BOARDMAX],
		  int owl_call);

int is_halfeye(struct half_eye_data heye[BOARDMAX], int pos);

/* Our own abort() which prints board state on the way out.
 * (i, j) is a "relevant" board position for info. */
void abortgo(const char *file, int line, const char *msg, int i, int j);

#if GG_TURN_OFF_ASSERTS
#define ASSERT2(x, i, j)
#define ASSERT1(x, pos)
#else
/* avoid dangling else */
/* FIXME: Should probably re-write these using do {...} while (0) idiom. */
#define ASSERT2(x, i, j) if (x) ; else abortgo(__FILE__, __LINE__, #x, i, j)
#define ASSERT1(x, pos) if (x) ; else abortgo(__FILE__, __LINE__, #x, I(pos), J(pos))
#endif

#define gg_assert(x) ASSERT2(x, -1, -1);

#endif  /* _LIBERTY_H_ */
/* =========================================================================*/

/* =====================================================================*/
/* emgena: dfa.h */

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

#ifndef _DFA_H_
#define _DFA_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/********************************
 *         parameters           *
 ********************************/

/* #define DFA_TRACE define this to trace the program */
/* #define DFA_PARANOIAC define this to activate a lot of assert() */
#define DFA_MAX_BOARD 21
#define MAX_ORDER DFA_MAX_BOARD*DFA_MAX_BOARD*4
/* maximum pattern matched at one positions */
#define DFA_MAX_MATCHED 8*500
#define DFA_RESIZE_STEP 20000
#define DFA_INIT_SIZE 50000
#ifndef EMPTY
#define EMPTY     0		/* . */
#define WHITE     1		/* O */
#define BLACK     2		/* X */
#endif
#define OUT_BOARD 3		/* # */

/********************************
 *    data types definition     *
 ********************************/

/* intersections */

typedef unsigned short Intersection_t;

/* attribute list */

typedef struct attrib
{
  int val;
  int next;
}
attrib_t;


/* dfa state */

typedef struct state
{
  int att;
  int next[4];
}
state_t;


/* dfa */

typedef struct dfa
{
  /* file header */
  char name[80];
  
  /* transition graph */
  state_t *states;
  int maxStates;
  int lastState;

  /* attributes sets */
  attrib_t *indexes;
  int maxIndexes;
  int lastIndex;
}
dfa_t;


/* scan order */

#if 0
typedef struct
{
  int i;
  int j;
}
order_t;
#endif


/********************************
 *    functions declaration     *
 ********************************/

void dfa_init(void);	/* Every call to a fda function must be done */
void dfa_end(void);	/* between calls of those 2 functions. */
void buildSpiralOrder(int order[8][MAX_ORDER]); /* Needed by matchpat */

/* basic dfa manipulation */
void print_c_dfa(FILE* of, const char *name, dfa_t *pdfa);
void new_dfa(dfa_t *pdfa, const char *name);
void copy_dfa(dfa_t *p_to, dfa_t *p_from);
void kill_dfa(dfa_t *pdfa);
int dfa_size(dfa_t *pdfa);	/* in kB */
void save_dfa(const char *f_name, dfa_t *pdfa);
dfa_t *load_dfa(const char *f_path, const char *f_name, dfa_t **ppdfa);
void dump_dfa(FILE *f, dfa_t *pdfa);

struct pattern;

/* conversion between a gnugo pattern struct into a dfa string. */
void pattern_2_string(struct pattern *pat, char *str,
		      int trans, int ci, int cj);

/* add a string with attribute att_val into a dfa */
float dfa_add_string(dfa_t *pdfa, const char *str, int pattern_index);


/* conversion macros */

#define EXPECTED_COLOR(player_c, position_c) convert[player_c][position_c]

extern int dfa_asc2val[90];
extern char dfa_val2asc[4];
#define ASC2VAL(c) (c < 90 ? dfa_asc2val[(int)c] : 3)
#define VAL2ASC(n) (n < 4 ? dfa_val2asc[n] : '!')

/* incremental macro */

#define BASE DFA_MAX_BOARD * 2
#define DFA_POS(i, j)  (4 * DFA_MAX_BOARD * (i) + (j))
#define DFA_OFFSET DFA_POS(DFA_MAX_BOARD, DFA_MAX_BOARD)


/********************************
 *    global variables          *
 ********************************/

extern int dfa_verbose;		/* the verbose level */

#endif /* _DFA_H_ */
/* =====================================================================*/

/*====================================================================*/
/* emgena: move_reasons.h */

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

/* values for move_reason.type */
#define THREAT_BIT    1

#define ATTACK_MOVE              2
#define ATTACK_MOVE_GOOD_KO      4
#define ATTACK_MOVE_BAD_KO       6
#define ATTACK_THREAT           (ATTACK_MOVE | THREAT_BIT)
#define DEFEND_MOVE              8
#define DEFEND_MOVE_GOOD_KO     10
#define DEFEND_MOVE_BAD_KO      12
#define DEFEND_THREAT           (DEFEND_MOVE | THREAT_BIT)

#define CONNECT_MOVE            14
#define CUT_MOVE                16

#define SEMEAI_MOVE             18
#define SEMEAI_THREAT           (SEMEAI_MOVE | THREAT_BIT)

#define BLOCK_TERRITORY_MOVE    20
#define EXPAND_TERRITORY_MOVE   22
#define EXPAND_MOYO_MOVE        24

#define OWL_ATTACK_MOVE         26
#define OWL_ATTACK_MOVE_GOOD_KO 28
#define OWL_ATTACK_MOVE_BAD_KO  30
#define OWL_ATTACK_THREAT       (OWL_ATTACK_MOVE | THREAT_BIT)
#define OWL_DEFEND_MOVE         32
#define OWL_DEFEND_MOVE_GOOD_KO 34
#define OWL_DEFEND_MOVE_BAD_KO  36
#define OWL_DEFEND_THREAT       (OWL_DEFEND_MOVE | THREAT_BIT)
#define OWL_PREVENT_THREAT      38
#define UNCERTAIN_OWL_ATTACK    40
#define UNCERTAIN_OWL_DEFENSE   42
#define STRATEGIC_ATTACK_MOVE   44
#define STRATEGIC_DEFEND_MOVE   46

#define MY_ATARI_ATARI_MOVE     50
#define YOUR_ATARI_ATARI_MOVE   52
#define VITAL_EYE_MOVE          54

#define ANTISUJI_MOVE           70

#define EITHER_MOVE             100
#define ALL_MOVE                101


/* Bitmap values for move_reason.status */
#define ACTIVE                  0
#define TERRITORY_REDUNDANT     1
#define STRATEGICALLY_REDUNDANT 2
#define REDUNDANT               (TERRITORY_REDUNDANT | STRATEGICALLY_REDUNDANT)
#define SECONDARY               4

#define MAX_REASONS 40

#define MAX_TRACE_LENGTH  160

#define HUGE_MOVE_VALUE 10.0*MAX_BOARD*MAX_BOARD

struct move_reason {
  int type;   /* e.g. attack, defend, or connect */
  int what;   /* pointer into list of strings, list of pair of dragons,
		 or similar */
  int status; /* This is a bitmap to mark redundant or secondary
                 move reasons. */
};

struct move_data {
  float value;    /* total comparison value, computed at the very end */
  float final_value; /* value after point redistribution. */
  float additional_ko_value; /* Additional threat value if ko fight going on.*/

  float territorial_value; /* Value in terms of actual profit. */
  float strategical_value; /* Value with respect to strength, weakness, and
			      safety of all groups on the board. */

  float maxpos_shape;      /* Maximal positive contribution to shape */
  float maxneg_shape;      /* Maximal negative contribution to shape */
  int numpos_shape;        /* Number of positive contributions to shape */
  int numneg_shape;        /* Number of negative contributions to shape */

  float followup_value;    /* Value of followup move (our sente). */
  float influence_followup_value;  /* Followup value of move as reported by
                                      experimental influence. */
  float reverse_followup_value;	/* Value of opponents followup move
				   (reverse sente). */
  float secondary_value;   /* Secondary move value. */

  float min_value;         /* Minimum allowed value for the move. */
  float max_value;         /* Maximum allowed value for the move. */
  float min_territory;     /* Minimum territorial value. */
  float max_territory;     /* Maximum territorial value. */

  int reason[MAX_REASONS]; /* List of reasons for a move. */
  int move_safety;         /* Whether the move seems safe. */
  int worthwhile_threat;   /* Play this move as a pure threat. */
  float random_number;     /* Random number connected to this move. */
};


/*
 * Some sizes.  
 *
 * FIXME: Many of these could be optimized more for size (e.g. MAX_EYES)
 */

/* emgena */
#undef MAX_LUNCHES
#undef MAX_WORMS

#define MAX_MOVE_REASONS  1000
#define MAX_WORMS         2*MAX_BOARD*MAX_BOARD/3
#define MAX_DRAGONS       MAX_WORMS
#define MAX_CONNECTIONS   4*MAX_WORMS
#define MAX_WORM_PAIRS    MAX_WORMS
#define MAX_EYES          MAX_BOARD*MAX_BOARD/2
#define MAX_LUNCHES       MAX_WORMS
#define MAX_EITHER        100
#define MAX_ALL           100


float compute_shape_factor(int pos);

extern struct move_data move[BOARDMAX];
extern struct move_reason move_reasons[MAX_MOVE_REASONS];
extern int next_reason;

/* Worms */
extern int worms[MAX_WORMS];
extern int next_worm;

/* Dragons */
extern int dragons[MAX_DRAGONS];
extern int next_dragon;

/* Connections */
extern int conn_dragon1[MAX_CONNECTIONS];
extern int conn_dragon2[MAX_CONNECTIONS];
extern int next_connection;

/* Unordered worm pairs */
extern int worm_pair1[MAX_WORM_PAIRS];
extern int worm_pair2[MAX_WORM_PAIRS];
extern int next_worm_pair;

/* Unordered sets (currently pairs) of move reasons / targets */
typedef struct {
  int reason1;
  int what1;
  int reason2;
  int what2;
} Reason_set;

extern Reason_set either_data[MAX_EITHER];
extern int        next_either;

extern Reason_set all_data[MAX_ALL];
extern int        next_all;

/* Eye shapes */
extern int eyes[MAX_EYES];
extern int eyecolor[MAX_EYES];
extern int next_eye;

/* Lunches */
extern int lunch_dragon[MAX_LUNCHES]; /* eater */
extern int lunch_worm[MAX_LUNCHES];   /* food */
extern int next_lunch;

/* Point redistribution */
extern int replacement_map[BOARDMAX];



int  find_worm(int str);
int  find_dragon(int str);

int  move_reason_known(int pos, int type, int what);
int  attack_move_reason_known(int pos, int what);
int  defense_move_reason_known(int pos, int what);
int  owl_attack_move_reason_known(int pos, int what);
int  owl_defense_move_reason_known(int pos, int what);
int  get_biggest_owl_target(int pos);
int  is_antisuji_move(int pos);

int  move_connects_strings(int pos, int color);
int  move_reasons_confirm_safety(int move, int color, int minsize);

void discard_redundant_move_reasons(int pos);
void list_move_reasons(int color);


/* ====================================================================== */
/* emgena: influence.h */
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
/* #include <string.h> */

/* #include "liberty.h" */

/* default attenuation coefficient. */
#define DEFAULT_ATTENUATION 3.0
#define EXP_DEFAULT_ATTENUATION 2.4

/* Extra damping coefficient for spreading influence diagonally. */
#define DIAGONAL_DAMPING 2.0
#define EXP_DIAGONAL_DAMPING 1.7

/* Default strength of the influence from a stone. May be lowered if
 * it is unsafe.
 */
#define DEFAULT_STRENGTH 100.0

/* Smallest amount of influence that we care about distributing. */
/*#define INFLUENCE_CUTOFF 0.02*/
#define INFLUENCE_CUTOFF 0.02

/* Value in delta_territory_cache indicating that the value has not
 * been computed. Arbitrary but unattainable.
 */
#define NOT_COMPUTED (-2.0 * MAX_BOARD * MAX_BOARD)

/* Values for the float working area w when used only for marking. */
#define UNMARKED 0.0
#define MARKED 1.0

/* Territory, moyo, and area are segmented into connected components
 * and given a number from the same series. These values are used in
 * region_type[][].
 */
#define WHITE_REGION    0
#define BLACK_REGION    1
#define IS_TERRITORY    2
#define IS_MOYO         4
#define IS_AREA         8
#define WHITE_TERRI     (WHITE_REGION | IS_TERRITORY)
#define BLACK_TERRI     (BLACK_REGION | IS_TERRITORY)
#define WHITE_MOYO      (WHITE_REGION | IS_MOYO)
#define BLACK_MOYO      (BLACK_REGION | IS_MOYO)
#define WHITE_AREA      (WHITE_REGION | IS_AREA)
#define BLACK_AREA      (BLACK_REGION | IS_AREA)

/* Maximum number of regions allowed between territory, moyo, and area.
 * FIXME: This number is vastly exaggerated. Should be possible to
 * come up with a much better upper bound.
 */ 
#define MAX_REGIONS (3*MAX_BOARD*MAX_BOARD + 1)

#define MAX_INTRUSIONS (2 * MAX_BOARD * MAX_BOARD)

struct intrusion_data
{
  int source_pos; 	/* Stone from which intrusion originates.*/
  int strength_pos;     /* Position of the intrusion influence soure. */
  float strength;
  float attenuation;
};

struct influence_data
{
  float white_influence[MAX_BOARD][MAX_BOARD]; /* Accumulated influence. */
  float black_influence[MAX_BOARD][MAX_BOARD]; /* Accumulated influence. */
  int p[MAX_BOARD][MAX_BOARD];           /* Working copy of board array. */
  float white_strength[MAX_BOARD][MAX_BOARD];  /* Strength of influence source. */
  float black_strength[MAX_BOARD][MAX_BOARD];  /* Strength of influence source. */
  float white_attenuation[MAX_BOARD][MAX_BOARD]; /* Attenuation. */
  float black_attenuation[MAX_BOARD][MAX_BOARD]; /* Attenuation. */
  float white_permeability[MAX_BOARD][MAX_BOARD];
  float black_permeability[MAX_BOARD][MAX_BOARD];

  int territory_segmentation[MAX_BOARD][MAX_BOARD];
  int moyo_segmentation[MAX_BOARD][MAX_BOARD];
  int area_segmentation[MAX_BOARD][MAX_BOARD];
  int region_type[MAX_REGIONS];
  int region_size[MAX_REGIONS];
  int number_of_regions;

  float territory_value[MAX_BOARD][MAX_BOARD];
  int non_territory[MAX_BOARD][MAX_BOARD];

  int color_to_move; /* Which color is in turn to move. */
  
  float w[MAX_BOARD][MAX_BOARD];         /* Working area. */
  int queuei[MAX_BOARD * MAX_BOARD];     /* Points receiving influence. */
  int queuej[MAX_BOARD * MAX_BOARD];

  int intrusion_counter;
  struct intrusion_data intrusions[MAX_INTRUSIONS];
};

/* Typedef for pointer to either of the functions whose_territory(),
 * whose_moyo(), and whose_area().
 */
typedef int (*owner_function_ptr)(struct influence_data *q, int m, int n);

/* ===================================================================== */

 
