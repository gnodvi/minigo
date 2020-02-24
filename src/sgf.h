// -*-  mode: c    ; coding: koi8   -*- ----------------------------------------

/* mgena: sgftree.h */

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

#ifndef _SGFTREE_H  
#define _SGFTREE_H 1

/* #include <stdio.h> */
 
/* ======================================================================= */
/* #include "sgf_properties.h" */
/* mgena: sgf_properties.h */

/* # */
/* # This document was taken from the SGF Specfication. See: */
/* # http://www.red-bean.com/sgf/ */
/* # */
/* # [SGF FF[4] - Smart Game Format] */
/* # */
/* # FF[4] property index */
/* # */
/* # This is an alphabetical index to all properties defined in FF[4]. */
/* # New properties are marked with '*', changed properties are marked with '!'. */
/* # */
/* #ID   Description     property type    property value */
/* #---- --------------- ---------------  -------------------------------------- */
     /*  Add Black       setup            list of stone */
#define SGFAB   16961
     /*  Add Empty       setup            list of point */
#define SGFAE   17729
     /*  Annotation      game-info        simpletext */
#define SGFAN   20033
     /*  Application     root             composed simpletext ':' simpletext */
#define SGFAP   20545
     /*  Arrow           -                list of composed point ':' point */
#define SGFAR   21057
     /*  Who adds stones - (LOA)          simpletext */
#define SGFAS   21313
     /*  Add White       setup            list of stone */
#define SGFAW   22337
     /*  Black           move             move */
#define SGFB     8258
     /*  Black time left move             real */
#define SGFBL   19522
     /*  Bad move        move             double */
#define SGFBM   19778
     /*  Black rank      game-info        simpletext */
#define SGFBR   21058
     /*  Black team      game-info        simpletext */
#define SGFBT   21570
     /*  Comment         -                text */
#define SGFC     8259
     /*  Charset         root             simpletext */
#define SGFCA   16707
     /*  Copyright       game-info        simpletext */
#define SGFCP   20547
     /*  Circle          -                list of point */
#define SGFCR   21059
     /*  Dim points      - (inherit)      elist of point */
#define SGFDD   17476
     /*  Even position   -                double */
#define SGFDM   19780
     /*  Doubtful        move             none */
#define SGFDO   20292
     /*  Date            game-info        simpletext */
#define SGFDT   21572
     /*  Event           game-info        simpletext */
#define SGFEV   22085
     /*  Fileformat      root             number (range: 1-4) */
#define SGFFF   17990
     /*  Figure          -                none | composed number ":" simpletext */
#define SGFFG   18246
     /*  Good for Black  -                double */
#define SGFGB   16967
     /*  Game comment    game-info        text */
#define SGFGC   17223
     /*  Game            root             number (range: 1-5,7-16) */
#define SGFGM   19783
     /*  Game name       game-info        simpletext */
#define SGFGN   20039
     /*  Good for White  -                double */
#define SGFGW   22343
     /*  Handicap        game-info (Go)   number */
#define SGFHA   16712
     /*  Hotspot         -                double */
#define SGFHO   20296
     /*  Initial pos.    game-info (LOA)  simpletext */
#define SGFIP   20553
     /*  Interesting     move             none */
#define SGFIT   21577
     /*  Invert Y-axis   game-info (LOA)  simpletext */
#define SGFIY   22857
     /*  Komi            game-info (Go)   real */
#define SGFKM   19787
     /*  Ko              move             none */
#define SGFKO   20299
     /*  Label           -                list of composed point ':' simpletext */
#define SGFLB   16972
     /*  Line            -                list of composed point ':' point */
#define SGFLN   20044
     /*  Mark            -                list of point */
#define SGFMA   16717
     /*  set move number move             number */
#define SGFMN   20045
     /*  Nodename        -                simpletext */
#define SGFN     8270
     /*  OtStones Black  move             number */
#define SGFOB   16975
     /*  Opening         game-info        text */
#define SGFON   20047
     /*  Overtime        game-info        simpletext */
#define SGFOT   21583
     /*  OtStones White  move             number */
#define SGFOW   22351
     /*  Player Black    game-info        simpletext */
#define SGFPB   16976
     /*  Place           game-info        simpletext */
#define SGFPC   17232
     /*  Player to play  setup            color */
#define SGFPL   19536
     /*  Print move mode - (inherit)      number */
#define SGFPM   19792
     /*  Player White    game-info        simpletext */
#define SGFPW   22352
     /*  Result          game-info        simpletext */
#define SGFRE   17746
     /*  Round           game-info        simpletext */
#define SGFRO   20306
     /*  Rules           game-info        simpletext */
#define SGFRU   21842
     /*  Markup          - (LOA)          point */
#define SGFSE   17747
     /*  Selected        -                list of point */
#define SGFSL   19539
     /*  Source          game-info        simpletext */
#define SGFSO   20307
     /*  Square          -                list of point */
#define SGFSQ   20819
     /*  Style           root             number (range: 0-3) */
#define SGFST   21587
     /*  Setup type      game-info (LOA)  simpletext */
#define SGFSU   21843
     /*  Size            root             (number | composed number ':' number) */
#define SGFSZ   23123
     /*  Territory Black - (Go)           elist of point */
#define SGFTB   16980
     /*  Tesuji          move             double */
#define SGFTE   17748
     /*  Timelimit       game-info        real */
#define SGFTM   19796
     /*  Triangle        -                list of point */
#define SGFTR   21076
     /*  Territory White - (Go)           elist of point */
#define SGFTW   22356
     /*  Unclear pos     -                double */
#define SGFUC   17237
     /*  User            game-info        simpletext */
#define SGFUS   21333
     /*  Value           -                real */
#define SGFV     8278
     /*  View            - (inherit)      elist of point */
#define SGFVW   22358
     /*  White           move             move */
#define SGFW     8279
     /*  White time left move             real */
#define SGFWL   19543
     /*  White rank      game-info        simpletext */
#define SGFWR   21079
     /*  White team      game-info        simpletext */
#define SGFWT   21591
/* # */
/* # These are additions to the SGF spec- old commands and some others */
/* # */

/* # */
/* # outdated FF3 properties */
/* # */
#define SGFBS 21314
#define SGFWS 21335
#define SGFID 17481
#define SGFRG 18258
#define SGFSC 17235

/* # */
/* # some random ones used by CGoban */
/* # */
#define SGFSY 22867

/* # */
/* # nonstandard SGF property used by GNU Go to mark illegal moves */
/* # */
#define SGFIL 19529
/* ======================================================================= */


#ifndef _GNUGO_H_
/*
 * NOTE: These MUST coincide with the definitions for the engine that we
 *       are using. In this case they are defined in engine/gnugo.h.
 *
 * The reason that we put them here within the #ifndef clause is because
 * we want to decouple the GNU Go engine from SGF library, but we don't 
 * want to redefine these symbols if we include this file into gnugo.h.
 */

#define EMPTY 0
#define WHITE 1
#define BLACK 2
#endif


void *xalloc(unsigned int);

/*
 * A property of an SGF node.  An SGF node is described by a linked
 * list of these.
 */

typedef struct SGFProperty_t {
  struct SGFProperty_t *next;
  short name;           /* FIXME: should be char with enumed flags */
  char  *value;         /* FIXME: different types */
} SGFProperty;

    
typedef struct SGFNode_t {
  SGFProperty      *props;
  struct SGFNode_t *parent;
  struct SGFNode_t *child;
  struct SGFNode_t *next;
} SGFNode;


/* low level functions */
SGFNode *sgfPrev(SGFNode *node);
SGFNode *sgfRoot(SGFNode *node);
SGFNode *sgfNewNode(void);
void sgfFreeNode(SGFNode *node);

int sgfGetIntProperty(SGFNode *node, const char *name, int *value);
int sgfGetFloatProperty(SGFNode *node, const char *name, float *value);
int sgfGetCharProperty(SGFNode *node, const char *name, char **value);
void sgfAddProperty(SGFNode *node, const char *name, const char *value);
void sgfAddPropertyInt(SGFNode *node, const char *name, long val);
void sgfAddPropertyFloat(SGFNode *node, const char *name, float val);
void sgfOverwriteProperty(SGFNode *node, const char *name, const char *text);
void sgfOverwritePropertyFloat(SGFNode *node, const char *name, float val);
void sgfOverwritePropertyInt(SGFNode *node, const char *name, int val);
void * xrealloc(void *pt, unsigned int size);
SGFProperty *sgfMkProperty(const char *name, const  char *value,
			   SGFNode *node, SGFProperty *last);
void sgfFreeProperty(SGFProperty *prop);

SGFNode *sgfAddStone(SGFNode *node, int color, int movex, int movey);
SGFNode *sgfAddPlay(SGFNode *node, int who, int movex, int movey);
SGFNode *sgfAddPlayLast(SGFNode *node, int who, int movex, int movey);
int sgfPrintCharProperty(FILE *file, SGFNode *node, const char *name);
int sgfPrintCommentProperty(FILE *file, SGFNode *node, const char *name);
void sgfWriteResult(SGFNode *node, float score, int overwrite);

SGFNode *sgfCircle(SGFNode *node, int i, int j);
SGFNode *sgfSquare(SGFNode *node, int i, int j);
SGFNode *sgfTriangle(SGFNode *node, int i, int j);
SGFNode *sgfMark(SGFNode *node, int i, int j);
SGFNode *sgfAddComment(SGFNode *node, const char *comment);
SGFNode *sgfBoardText(SGFNode *node, int i, int j, const char *text);
SGFNode *sgfBoardChar(SGFNode *node, int i, int j, char c);
SGFNode *sgfBoardNumber(SGFNode *node, int i, int j, int number);
SGFNode *sgfStartVariant(SGFNode *node);
SGFNode *sgfStartVariantFirst(SGFNode *node);
SGFNode *sgfAddChild(SGFNode *node);

SGFNode *sgfCreateHeaderNode(int boardsize, float komi);

/* Read SGF tree from file. */
SGFNode *readsgffile(const char *filename);
/* Specific solution for fuseki */
SGFNode *readsgffilefuseki(const char *filename, int moves_per_game);

/* Write SGF tree to a file. */
void sgf_write_header(SGFNode *root, int overwrite, int seed, float komi,
		      int level);
int writesgf(SGFNode *root, const char *filename);


/* ---------------------------------------------------------------- */
/* ---                          SGFTree                         --- */
/* ---------------------------------------------------------------- */


typedef struct SGFTree_t {
  SGFNode *root;
  SGFNode *lastnode;
} SGFTree;


void sgftree_clear(SGFTree *tree);
int  sgftree_readfile(SGFTree *tree, const char *infilename);

SGFNode *sgftreeAddPlay(SGFTree *tree, SGFNode *node, int color,
			int movex, int movey);
SGFNode *sgftreeAddPlayLast(SGFTree *tree, SGFNode *node, int color,
			    int movex, int movey);
SGFNode *sgftreeAddStone(SGFTree *tree, SGFNode *node,
			 int color, int movex, int movey);
void     sgftreeWriteResult(SGFTree *tree, float score, int overwrite);
SGFNode *sgftreeNodeCheck(SGFTree *tree, SGFNode *node);
	 
SGFNode *sgftreeCircle  (SGFTree *tree, SGFNode *node, int i, int j);
SGFNode *sgftreeSquare  (SGFTree *tree, SGFNode *node, int i, int j);
SGFNode *sgftreeTriangle(SGFTree *tree, SGFNode *node, int i, int j);
SGFNode *sgftreeMark    (SGFTree *tree, SGFNode *node, int i, int j);
SGFNode *sgftreeAddComment(SGFTree *tree, SGFNode *node, const char *comment);
SGFNode *sgftreeBoardText(SGFTree *tree, SGFNode *node, int i, int j,
			  const char *text);
SGFNode *sgftreeBoardChar(SGFTree *tree, SGFNode *node, int i, int j, char c);
SGFNode *sgftreeBoardNumber(SGFTree *tree, SGFNode *node,
			    int i, int j, int number);
SGFNode *sgftreeStartVariant(SGFTree *tree, SGFNode *node);
SGFNode *sgftreeStartVariantFirst(SGFTree *tree, SGFNode *node);
SGFNode *sgftreeCreateHeaderNode(SGFTree *tree, int boardsize, float komi);
void     sgftreeSetLastNode(SGFTree *tree, SGFNode *lastnode);


/* ---------------------------------------------------------------- */
/* ---                         Utilities                        --- */
/* ---------------------------------------------------------------- */


int get_moveX(SGFProperty *property, int boardsize);
int get_moveY(SGFProperty *property, int boardsize);
int get_moveXY(SGFProperty *property, int *i, int *j, int boardsize);

int show_sgf_properties(SGFNode *node);
int show_sgf_tree(SGFNode *node);
int is_markup_node(SGFNode *node);
int is_move_node(SGFNode *node);
int is_pass_node(SGFNode *node, int boardsize);
int find_move(SGFNode *node);


#endif

/* =================================================================== */
