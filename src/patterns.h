// -*-  mode: c    ; coding: koi8   -*- ----------------------------------------

/* patterns.c */
/* eyes.h */

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

/* This file describes the compiled form of the pattern database.
 * mkpat is used to compile various source files <name>.db into
 * intermediate files <name>.c which define data structures
 * describing the patterns.
 */

/* #ifdef HAVE_CONFIG_H */
/* #include <config.h> */
/* #endif */

#ifndef __PATTERN_H__
#define __PATTERN_H__

/* local versions of absolute value, min and max */

#define gg_abs(x) ((x) < 0 ? -(x) : (x))
#define gg_min(a, b) ((a)<(b) ? (a) : (b))
#define gg_max(a, b) ((a)<(b) ? (b) : (a))

/* This tells Alpha OSF/1 not to define a getopt prototype in <stdio.h>.
 * Ditto for AIX 3.2 and <stdlib.h>. 
 */
#ifndef _NO_PROTO
#define _NO_PROTO
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#define GRID_OPT 0
#endif

#ifndef GRID_OPT
#error GRID_OPT should be defined as 0, 1 or 2
#endif


/* Include support for pattern profiling. May be turned off in stable
 * releases to save some memory.
 *
 * FIXME: should probably be included in config.h
 */
#define PROFILE_PATTERNS 0

/* this trick forces a compile error if ints are not at least 32-bit */
struct _unused_patterns_h {
  int unused[sizeof(unsigned int) >= 4 ? 1 : -1];
};

/* transformation stuff */
extern const int transformations[8][2][2];

/*
 * a macro (inline) version of the transform function
 */

#define TRANSFORM(i, j, ti, tj, trans) \
do { \
  *ti = transformations[trans][0][0] * (i) + transformations[trans][0][1] * (j); \
  *tj = transformations[trans][1][0] * (i) + transformations[trans][1][1] * (j); \
} while (0)


/* The ordinary TRANSFORM plus translation with (m, n), returned as a
 * 1D coordinate.
 */
#define AFFINE_TRANSFORM(i, j, trans, m, n) \
  POS((m) + transformations[trans][0][0] * (i) \
          + transformations[trans][0][1] * (j), \
      (n) + transformations[trans][1][0] * (i) \
          + transformations[trans][1][1] * (j))


#define ATTACK_MACRO(pos) ((stackp==0) ? (worm[pos].attack_codes[0]) : attack(pos, NULL))
#define DEFEND_MACRO(pos) ((stackp==0) ? (worm[pos].defend_codes[0]) : find_defense(pos, NULL))
#define DRAGON_WEAK(pos) dragon_weak(pos)

struct pattern; /* forward reference to keep gcc happy */

/* this is the type of a function which the matcher can
 * call to evaluate the score of a move.
 * parameters:
 *   pattern and rotation are the current pattern being considered
 *   ti, tj: IN = posn of the 7, 8 or 9 marker
 *           OUT = recommended move
 * return value : weight of move, or 0 if match failed            
 */
 
typedef int (*pattern_helper_fn_ptr)(struct pattern *, int rotation,
				     int move, int color);

typedef int (*autohelper_fn_ptr)(struct pattern *, int rotation,
				 int move, int color, int action);


/* each pattern is compiled into a sequence of these elements.
 * Each describes a relative x, y from the pattern origin,
 * and a description of what should be there.
 * Current attributes are
 *  0 = .
 *  1 = X
 *  2 = O
 *  3 = x
 *  4 = o
 *  5 = ,  (barriers only)
 *  6 = a  (half-eye only, OBSOLETE)
 *  7 = !  (connection and barriers only)
 */

#define ATT_dot   0
#define ATT_X     1
#define ATT_O     2
#define ATT_x     3
#define ATT_o     4
#define ATT_comma 5
#define ATT_a     6
#define ATT_not   7

/* Pattern classes. The semantics of these varies between different
 * databases. The descriptions here mostly relate to patterns in
 * patterns.db and other databases which are handled by shapes.c.
 */
#define CLASS_O 0x0001   /* O stones must be alive or unknown */
#define CLASS_o 0x0002   /* O stones must be dead or unknown */
#define CLASS_X 0x0004   /* X stones must be alive or unknown */
#define CLASS_x 0x0008   /* X stones must be dead or unknown */
#define CLASS_s 0x0010   /* move is a sacrifice */
#define CLASS_n 0x0020   /* X could also make this move if we do not */
#define CLASS_D 0x0040   /* defense pattern */
#define CLASS_C 0x0080   /* move connects two worms */ 
#define CLASS_c 0x0100   /* move weakly connects two worms */ 
#define CLASS_B 0x0200   /* move breaks connection between enemy worms */
#define CLASS_A 0x0400   /* attack pattern */
#define CLASS_b 0x0800   /* move is intended to block opponent */
#define CLASS_e 0x1000   /* move is intended to expand territory */
#define CLASS_E 0x2000   /* move is intended to expand moyo */
#define CLASS_a 0x4000   /* strategical level attack */
#define CLASS_d 0x8000   /* strategical level defense */
#define CLASS_I 0x10000  /* invasions patterns (influence.db) */
#define CLASS_J 0x20000  /* joseki standard move */
#define CLASS_j 0x40000  /* joseki move, slightly less urgent */
#define CLASS_t 0x80000  /* minor joseki move (tenuki OK) */
#define CLASS_U 0x100000 /* very urgent joseki move */
#define CLASS_T 0x200000 /* joseki trick move */
#define CLASS_W 0x400000 /* worthwhile threat move */
#define CLASS_F 0x800000 /* for joseki moves: a fuseki pattern; for CLASS_Y
                          * patterns: pattern only for standard influence
                          * FIXME: This is ugly. */
#define CLASS_Y 0x80000000 /* a pattern that should only be matched for 
                            * either standard or experimental influence
                            * (CLASS_F indicating which one). */

/* Collection of the classes inducing move reasons. */
#define CLASS_MOVE_REASONS (CLASS_C | CLASS_B | CLASS_b | \
                            CLASS_e | CLASS_E | CLASS_a | CLASS_d | \
			    CLASS_J | CLASS_j | CLASS_U | CLASS_T | CLASS_t | \
                            CLASS_W | CLASS_c | CLASS_F)

/* Values associated with patterns. Stored together with classes. */
#define VALUE_MINVAL       0x01000000 /* pattern has a minimum value */
#define VALUE_MAXVAL       0x02000000 /* pattern has a maximum value */
#define VALUE_MINTERRITORY 0x04000000 /* pattern has a min territorial value */
#define VALUE_MAXTERRITORY 0x08000000 /* pattern has a max territorial value */
#define VALUE_SHAPE        0x10000000 /* pattern has a shape value */
#define VALUE_FOLLOWUP     0x20000000 /* pattern has a followup value */
#define VALUE_REV_FOLLOWUP 0x40000000 /* pattern has a reverse followup value */

/* Collection of the classes inducing move values. */
#define CLASS_MOVE_VALUES (VALUE_MINVAL | VALUE_MAXVAL | VALUE_MINTERRITORY \
			   | VALUE_MAXTERRITORY | VALUE_SHAPE \
			   | VALUE_FOLLOWUP | VALUE_REV_FOLLOWUP)

/* directions for applying edge-constraints */
#define NORTH_EDGE 1
#define SOUTH_EDGE 2
#define EAST_EDGE  4
#define WEST_EDGE  8

/* different kinds of autohelpers */
#define HAVE_CONSTRAINT 1
#define HAVE_ACTION     2

/* Values of the action parameter to indicate where an influence autohelper
 * is called from.
 */
#define INFLUENCE_CALLBACK 1
#define FOLLOWUP_INFLUENCE_CALLBACK 2


typedef struct patval {
  int x;
  int y;
  int att;
} Patval;


/*
 * Each pattern as a whole is compiled to an instance of this structure.
 */

struct pattern {
  struct patval *patn;  /* array of elements */
  int patlen;           /* number of elements */
  int trfno;            /* number of transformations (rotations and reflections) */
  const char *name;     /* short description of pattern (optional) */

  int mini, minj;       /* min and max (relative to anchor) extent of ... */
  int maxi, maxj;       /* ...the pattern */
  int height, width;    /* differences between max and min extents */
  int edge_constraints; /* and combinations of NORTH, EAST etc. for edges */

  int movei, movej;     /* position of the suggested move (relative to anchor) */

#if GRID_OPT
  unsigned int and_mask[8]; /* for each rotation, masks for a */
  unsigned int val_mask[8]; /* 4x4 grid around anchor */
#endif

  unsigned int class;   /* classification of pattern */
  float value;          /* value for pattern, if matched */
  float maxvalue;
  float minterritory;
  float maxterritory;
  float shape;
  float followup;
  float reverse_followup;

  int autohelper_flag;  /* whether autohelper has constraint and/or action */
  pattern_helper_fn_ptr helper;  /* helper function, or NULL */
  autohelper_fn_ptr autohelper;  /* automatically generated helper */
                                 /* function, or NULL */

  int anchored_at_X;    /* 3 if the pattern has 'X' at the anchor posn */

  float constraint_cost; /* mkpat's estimate of the constraint complexity.*/

#if PROFILE_PATTERNS
  int hits;
  int dfa_hits;
  int reading_nodes;
#endif
};


#if EXPERIMENTAL_READING
struct tree_node_list;
#endif

struct pattern_db {
  int fixed_for_size;
  struct pattern *patterns;
  struct dfa *pdfa;
#if EXPERIMENTAL_READING
  struct tree_node_list *tnl; /* For tree-based pattern matching */
#endif
};


struct fullboard_pattern {
  struct patval *patn;  /* array of elements */
  int patlen;           /* number of elements */
  const char *name;     /* short description of pattern (optional) */
  int movei, movej;     /* position of the suggested move */
  float value;          /* value for pattern, if matched */
};




/* helper functions */

#define DECLARE(x) int x(struct pattern *pattern, int transformation, int move, int color)

DECLARE(basic_cut_helper);
DECLARE(jump_out_helper);
DECLARE(jump_out_far_helper);
DECLARE(high_handicap_helper);
DECLARE(reinforce_helper);
DECLARE(throw_in_atari_helper);
DECLARE(ugly_cutstone_helper);
DECLARE(cutstone2_helper);

/* autohelper fns */
int not_lunch_helper(int apos, int bpos);
int seki_helper(int str);
void threaten_to_save_helper(int move, int str);
void threaten_to_capture_helper(int move, int str);
void defend_against_atari_helper(int move, int str);
void amalgamate_most_valuable_helper(int apos, int bpos, int cpos);
int finish_ko_helper(int apos);
int squeeze_ko_helper(int apos);
int backfill_helper(int apos, int bpos, int cpos);
int owl_threatens_attack(int apos, int bpos);
int connect_and_cut_helper(int Apos, int bpos, int cpos);
int connect_and_cut_helper2(int Apos, int bpos, int cpos, int color);
int edge_double_sente_helper(int move, int apos, int bpos, int cpos);
int dragon_weak(int pos);
void set_value_helper(struct pattern *patt, int value);

/* FIXME: Can this be set up inside of the mkpat.c function helper list? */
#define set_value(x) set_value_helper(patt, x)


void init_tree_conn(void);
void init_tree_pat(void);
void init_tree_attpat(void);
void init_tree_defpat(void);
void init_tree_influencepat(void);
void init_tree_barrierspat(void);
void init_tree_endpat(void);
void init_tree_aa_attackpat(void);
void init_tree_owl_attackpat(void);
void init_tree_owl_vital_apat(void);
void init_tree_owl_defendpat(void);
void init_tree_fusekipat(void);
void init_tree_fuseki9(void);
void init_tree_fuseki13(void);
void init_tree_fuseki19(void);
void init_tree_joseki(void);
void init_tree_read_attack(void);
void init_tree_read_defend(void);

/* pattern arrays themselves */
extern struct pattern_db pat_db;
extern struct pattern_db joseki_db;
extern struct pattern_db aa_attackpat_db;
extern struct pattern_db owl_attackpat_db;
extern struct pattern_db owl_vital_apat_db;
extern struct pattern_db owl_defendpat_db;
extern struct pattern_db conn_db;
extern struct pattern_db attpat_db;
extern struct pattern_db defpat_db;
extern struct pattern_db endpat_db;
extern struct pattern_db influencepat_db;
extern struct pattern_db barrierspat_db;
extern struct pattern_db fusekipat_db;
extern struct fullboard_pattern fuseki19[];
extern struct fullboard_pattern fuseki13[];
extern struct fullboard_pattern fuseki9[];

#if EXPERIMENTAL_READING

/* Experimental reading */
extern struct pattern_db read_attack_db;
extern struct pattern_db read_defend_db;

#endif

/* Tree-based pattern matching structures*/

struct match_node;
struct tree_node_list;

struct match_node {
  int patnum;
  int orientation;
  struct match_node *next;
};


struct tree_node {
  struct match_node *matches;
  int att;
  int x;
  int y;
  struct tree_node_list *next_list;
};

struct tree_node_list {
  struct tree_node node;
  struct tree_node_list *next;
};


#endif
/* ====================================================================*/
/* emgena: eyes.h */
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

/*
 * The vertices of each eye is defined by an array of struct eye_vertex.
 */

struct eye_vertex {
  int i;                          /* coordinates of the vertex             */
  int j; 
  char type;                      /* . x or X                              */

  int neighbors;                  /* number of neighbors                   */
  int n1;                         /* first neighbor (position in array)    */
  int n2;                         /* second neighbor                       */
  int n3;                         /* third neighbor                        */
  int n4;                         /* fourth neighbor                       */
  int edge;                       /* 0=center, 1=edge, 2=corner            */
  /* A corner vertex may only be matched at the corner.
   * An edge vertex may be matched at the corner or on the edge.
   * A center vertex may be matched anywhere.
   */
};


/*
 * Each eye is described by one struct eye_graph and the vertices
 * in the struct eye_vertex array.
 */

struct eye_graph {
  struct eye_vertex *vertex;
  const char *patname;            /* Name of pattern                       */
  int esize;                      /* number of vertices                    */
  int msize;                      /* number of marginal vertices           */
  int ends;                       /* number of vertices with one neighbor  */
  int two_neighbors;              /* number of vertices with 2 neighbors   */
  int three_neighbors;            /* number of vertices with 3 neighbors   */
  int max;                        /* number of eyes if O plays first       */
  int min;                        /* number of eyes if X plays first       */
};

extern struct eye_graph graphs[];

/* ==================================================================*/
