 /* fuseki9.c */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* #include <stdio.h>  */

/* #include "gnugo.h" */
/* #include "liberty.h" */
/* #include "patterns.h" */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sgf.h"
#include "engine.h"
#include "patterns.h"



static struct patval fuseki90[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki91[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki92[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki93[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki94[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki95[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki96[] = {
   {0,0,1}};

static struct patval fuseki97[] = {
   {0,0,1}};

static struct patval fuseki98[] = {
   {0,0,1}};

static struct patval fuseki99[] = {
   {0,0,1}};

static struct patval fuseki910[] = {
   {0,0,1}};

static struct patval fuseki911[] = {
   {2,-2,1}};

static struct patval fuseki912[] = {
   {-2,-2,1}};

static struct patval fuseki913[] = {
   {-2,2,1}};

static struct patval fuseki914[] = {
   {-2,-2,1}};

static struct patval fuseki915[] = {
   {2,-2,1}};

static struct patval fuseki916[] = {
   {-2,2,1}};

static struct patval fuseki917[] = {
   {2,-2,1}};

static struct patval fuseki918[] = {
   {2,-2,1}};

static struct patval fuseki919[] = {
   {2,-2,1}};

static struct patval fuseki920[] = {
   {2,-1,1}};

static struct patval fuseki921[] = {
   {-2,1,1}};

static struct patval fuseki922[] = {
   {1,-2,1}};

static struct patval fuseki923[] = {
   {1,2,1}};

static struct patval fuseki924[] = {
   {-1,-2,1}};

static struct patval fuseki925[] = {
   {-2,1,1}};

static struct patval fuseki926[] = {
   {-2,1,1}};

static struct patval fuseki927[] = {
   {-1,2,1}};

static struct patval fuseki928[] = {
   {2,-1,1}};

static struct patval fuseki929[] = {
   {1,-2,1}};

static struct patval fuseki930[] = {
   {1,-2,1}};

static struct patval fuseki931[] = {
   {1,-2,1}};

static struct patval fuseki932[] = {
   {-1,1,1}};

static struct patval fuseki933[] = {
   {1,1,1}};

static struct patval fuseki934[] = {
   {1,-1,1}};

static struct patval fuseki935[] = {
   {1,1,1}};

static struct patval fuseki936[] = {
   {-1,-1,1}};

static struct patval fuseki937[] = {
   {-1,-1,1}};

static struct patval fuseki938[] = {
   {-1,1,1}};

static struct patval fuseki939[] = {
   {-1,1,1}};

static struct patval fuseki940[] = {
   {1,1,1}};

static struct patval fuseki941[] = {
   {-1,1,1}};

static struct patval fuseki942[] = {
   {1,-2,1},
   {0,0,2}};

static struct patval fuseki943[] = {
   {-2,1,1},
   {0,0,2}};

static struct patval fuseki944[] = {
   {2,1,1},
   {0,0,2}};

static struct patval fuseki945[] = {
   {2,1,1},
   {0,0,2}};

static struct patval fuseki946[] = {
   {2,-1,1},
   {0,0,2}};

static struct patval fuseki947[] = {
   {1,2,1},
   {0,0,2}};

static struct patval fuseki948[] = {
   {1,-2,1},
   {0,0,2}};

static struct patval fuseki949[] = {
   {2,-1,1},
   {0,0,2}};

static struct patval fuseki950[] = {
   {2,1,1},
   {0,0,2}};

static struct patval fuseki951[] = {
   {-1,2,1},
   {0,0,2}};

static struct patval fuseki952[] = {
   {-2,2,1},
   {0,0,2}};

static struct patval fuseki953[] = {
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki954[] = {
   {2,2,1},
   {0,0,2}};

static struct patval fuseki955[] = {
   {-2,2,1},
   {0,0,2}};

static struct patval fuseki956[] = {
   {-2,2,1},
   {0,0,2}};

static struct patval fuseki957[] = {
   {-2,2,1},
   {2,-2,2}};

static struct patval fuseki958[] = {
   {2,-2,1},
   {-2,2,2}};

static struct patval fuseki959[] = {
   {-2,-2,1},
   {2,2,2}};

static struct patval fuseki960[] = {
   {0,2,1},
   {0,0,2}};

static struct patval fuseki961[] = {
   {0,-2,1},
   {0,0,2}};

static struct patval fuseki962[] = {
   {0,2,1},
   {0,0,2}};

static struct patval fuseki963[] = {
   {-2,0,1},
   {0,0,2}};

static struct patval fuseki964[] = {
   {-2,0,1},
   {0,0,2}};

static struct patval fuseki965[] = {
   {-2,0,1},
   {0,0,2}};

static struct patval fuseki966[] = {
   {-2,0,1},
   {0,0,2}};

static struct patval fuseki967[] = {
   {0,-2,1},
   {0,0,2}};

static struct patval fuseki968[] = {
   {0,2,1},
   {0,0,2}};

static struct patval fuseki969[] = {
   {2,-1,1},
   {-2,2,2}};

static struct patval fuseki970[] = {
   {1,-2,1},
   {-2,2,2}};

static struct patval fuseki971[] = {
   {-1,-2,1},
   {2,2,2}};

static struct patval fuseki972[] = {
   {1,-2,1},
   {-2,2,2}};

static struct patval fuseki973[] = {
   {-2,1,1},
   {2,-2,2}};

static struct patval fuseki974[] = {
   {2,1,1},
   {-2,-2,2}};

static struct patval fuseki975[] = {
   {1,-2,1},
   {-2,2,2}};

static struct patval fuseki976[] = {
   {1,-2,1},
   {-2,2,2}};

static struct patval fuseki977[] = {
   {2,1,1},
   {-2,-2,2}};

static struct patval fuseki978[] = {
   {-1,-2,1},
   {2,-1,2}};

static struct patval fuseki979[] = {
   {-1,2,1},
   {2,1,2}};

static struct patval fuseki980[] = {
   {-2,-1,1},
   {-1,2,2}};

static struct patval fuseki981[] = {
   {1,2,1},
   {-2,1,2}};

static struct patval fuseki982[] = {
   {-1,2,1},
   {2,1,2}};

static struct patval fuseki983[] = {
   {-1,2,1},
   {2,1,2}};

static struct patval fuseki984[] = {
   {1,2,1},
   {-2,1,2}};

static struct patval fuseki985[] = {
   {-1,-2,1},
   {2,-1,2}};

static struct patval fuseki986[] = {
   {1,-2,1},
   {-2,-1,2}};

static struct patval fuseki987[] = {
   {2,2,1},
   {-2,2,1},
   {-2,-2,2}};

static struct patval fuseki988[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,2}};

static struct patval fuseki989[] = {
   {-2,-2,1},
   {-2,2,2}};

static struct patval fuseki990[] = {
   {-2,-2,1},
   {-2,2,2}};

static struct patval fuseki991[] = {
   {-2,2,1},
   {2,2,2}};

static struct patval fuseki992[] = {
   {-2,2,1},
   {2,2,2}};

static struct patval fuseki993[] = {
   {-1,-1,1},
   {0,0,2}};

static struct patval fuseki994[] = {
   {-1,1,1},
   {0,0,2}};

static struct patval fuseki995[] = {
   {-1,-1,1},
   {0,0,2}};

static struct patval fuseki996[] = {
   {0,0,1},
   {-2,0,1},
   {-2,-2,2}};

static struct patval fuseki997[] = {
   {0,0,1},
   {2,0,1},
   {2,-2,2}};

static struct patval fuseki998[] = {
   {0,2,1},
   {0,0,1},
   {-2,2,2}};

static struct patval fuseki999[] = {
   {0,0,1},
   {0,2,1},
   {2,2,2}};

static struct patval fuseki9100[] = {
   {0,0,1},
   {2,0,1},
   {2,-2,2}};

static struct patval fuseki9101[] = {
   {0,0,1},
   {0,-2,1},
   {-2,-2,2}};

static struct patval fuseki9102[] = {
   {0,2,1},
   {0,0,1},
   {-2,2,2}};

static struct patval fuseki9103[] = {
   {-1,1,1},
   {2,-2,2}};

static struct patval fuseki9104[] = {
   {-1,1,1},
   {2,-2,2}};

static struct patval fuseki9105[] = {
   {1,-1,1},
   {-2,2,2}};

static struct patval fuseki9106[] = {
   {1,1,1},
   {-2,-2,2}};

static struct patval fuseki9107[] = {
   {1,1,1},
   {-2,-2,2}};

static struct patval fuseki9108[] = {
   {-1,-1,1},
   {2,2,2}};

static struct patval fuseki9109[] = {
   {-2,1,1},
   {-2,-2,2}};

static struct patval fuseki9110[] = {
   {2,-1,1},
   {2,2,2}};

static struct patval fuseki9111[] = {
   {1,2,1},
   {-2,2,2}};

static struct patval fuseki9112[] = {
   {1,2,1},
   {-2,2,2}};

static struct patval fuseki9113[] = {
   {1,2,1},
   {-2,2,2}};

static struct patval fuseki9114[] = {
   {2,1,1},
   {2,-2,2}};

static struct patval fuseki9115[] = {
   {1,2,1},
   {-2,2,2}};

static struct patval fuseki9116[] = {
   {0,0,1},
   {-2,1,2}};

static struct patval fuseki9117[] = {
   {0,0,1},
   {-2,-1,2}};

static struct patval fuseki9118[] = {
   {0,0,1},
   {2,-1,2}};

static struct patval fuseki9119[] = {
   {0,0,1},
   {2,-1,2}};

static struct patval fuseki9120[] = {
   {0,0,1},
   {-2,1,2}};

static struct patval fuseki9121[] = {
   {0,0,1},
   {-2,1,2}};

static struct patval fuseki9122[] = {
   {0,0,1},
   {1,-2,2}};

static struct patval fuseki9123[] = {
   {0,0,1},
   {2,-1,2}};

static struct patval fuseki9124[] = {
   {0,0,1},
   {1,-2,2}};

static struct patval fuseki9125[] = {
   {0,0,1},
   {1,-2,2}};

static struct patval fuseki9126[] = {
   {0,0,1},
   {-2,-2,2}};

static struct patval fuseki9127[] = {
   {0,0,1},
   {2,2,2}};

static struct patval fuseki9128[] = {
   {0,0,1},
   {-2,2,2}};

static struct patval fuseki9129[] = {
   {0,0,1},
   {2,-2,2}};

static struct patval fuseki9130[] = {
   {0,0,1},
   {-2,2,2}};

static struct patval fuseki9131[] = {
   {0,0,1},
   {2,-2,2}};

static struct patval fuseki9132[] = {
   {0,0,1},
   {2,-2,2}};

static struct patval fuseki9133[] = {
   {-1,-1,1},
   {2,-1,2}};

static struct patval fuseki9134[] = {
   {1,1,1},
   {1,-2,2}};

static struct patval fuseki9135[] = {
   {1,-1,1},
   {1,2,2}};

static struct patval fuseki9136[] = {
   {-1,-1,1},
   {2,-1,2}};

static struct patval fuseki9137[] = {
   {-1,1,1},
   {2,1,2}};

static struct patval fuseki9138[] = {
   {-1,-1,1},
   {2,-1,2}};

static struct patval fuseki9139[] = {
   {1,1,1},
   {-2,1,2}};

static struct patval fuseki9140[] = {
   {-1,-1,1},
   {-1,2,2}};

static struct patval fuseki9141[] = {
   {1,1,1},
   {-2,1,2}};

static struct patval fuseki9142[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki9143[] = {
   {2,2,1},
   {-2,2,1},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9144[] = {
   {2,2,1},
   {-2,2,1},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9145[] = {
   {2,2,1},
   {2,-2,1},
   {-2,2,2},
   {-2,-2,2}};

static struct patval fuseki9146[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki9147[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki9148[] = {
   {2,2,1},
   {-2,2,1},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9149[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki9150[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9151[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9152[] = {
   {-2,-2,1},
   {1,1,2}};

static struct patval fuseki9153[] = {
   {2,-2,1},
   {-1,1,2}};

static struct patval fuseki9154[] = {
   {-2,2,1},
   {1,-1,2}};

static struct patval fuseki9155[] = {
   {2,-2,1},
   {-1,1,2}};

static struct patval fuseki9156[] = {
   {-2,2,1},
   {1,-1,2}};

static struct patval fuseki9157[] = {
   {2,-2,1},
   {-1,1,2}};

static struct patval fuseki9158[] = {
   {2,-2,1},
   {-1,1,2}};

static struct patval fuseki9159[] = {
   {-1,-2,1},
   {0,0,1},
   {1,-2,2}};

static struct patval fuseki9160[] = {
   {0,0,1},
   {2,-1,1},
   {2,1,2}};

static struct patval fuseki9161[] = {
   {0,0,1},
   {2,-1,1},
   {2,1,2}};

static struct patval fuseki9162[] = {
   {-2,-1,1},
   {0,0,1},
   {-2,1,2}};

static struct patval fuseki9163[] = {
   {0,0,1},
   {2,1,1},
   {2,-1,2}};

static struct patval fuseki9164[] = {
   {-1,0,1},
   {0,0,2}};

static struct patval fuseki9165[] = {
   {0,1,1},
   {0,0,2}};

static struct patval fuseki9166[] = {
   {-1,-1,1},
   {-2,-2,2}};

static struct patval fuseki9167[] = {
   {1,1,1},
   {2,2,2}};

static struct patval fuseki9168[] = {
   {-1,1,1},
   {-2,2,2}};

static struct patval fuseki9169[] = {
   {0,1,1}};

static struct patval fuseki9170[] = {
   {0,1,1}};

static struct patval fuseki9171[] = {
   {-1,0,1}};

static struct patval fuseki9172[] = {
   {0,1,1}};

static struct patval fuseki9173[] = {
   {1,0,1}};

static struct patval fuseki9174[] = {
   {1,0,1}};

static struct patval fuseki9175[] = {
   {-1,2,1},
   {1,-1,2}};

static struct patval fuseki9176[] = {
   {-1,-2,1},
   {1,1,2}};

static struct patval fuseki9177[] = {
   {-1,-2,1},
   {1,1,2}};

static struct patval fuseki9178[] = {
   {2,1,1},
   {-1,-1,2}};

static struct patval fuseki9179[] = {
   {1,-2,1},
   {-1,1,2}};

static struct patval fuseki9180[] = {
   {2,-1,1},
   {-1,1,2}};

static struct patval fuseki9181[] = {
   {1,2,1},
   {-1,-1,2}};

static struct patval fuseki9182[] = {
   {2,-1,1},
   {-1,1,2}};

static struct patval fuseki9183[] = {
   {1,1,1},
   {-1,-1,2}};

static struct patval fuseki9184[] = {
   {1,1,1},
   {-1,-1,2}};

static struct patval fuseki9185[] = {
   {-1,-1,1},
   {1,1,2}};

static struct patval fuseki9186[] = {
   {-1,-1,1},
   {1,1,2}};

static struct patval fuseki9187[] = {
   {-1,1,1},
   {1,-1,2}};

static struct patval fuseki9188[] = {
   {-1,-1,1},
   {1,1,2}};

static struct patval fuseki9189[] = {
   {-1,-1,1},
   {1,1,2}};

static struct patval fuseki9190[] = {
   {-1,-1,1},
   {1,1,2}};

static struct patval fuseki9191[] = {
   {-1,0,1},
   {0,0,1},
   {-1,1,2}};

static struct patval fuseki9192[] = {
   {0,0,1},
   {0,-1,1},
   {-1,-1,2}};

static struct patval fuseki9193[] = {
   {0,0,1},
   {0,1,1},
   {1,1,2}};

static struct patval fuseki9194[] = {
   {0,0,1},
   {0,1,1},
   {1,1,2}};

static struct patval fuseki9195[] = {
   {0,0,1},
   {1,0,1},
   {1,1,2}};

static struct patval fuseki9196[] = {
   {0,0,1},
   {2,-1,1},
   {2,-2,2}};

static struct patval fuseki9197[] = {
   {0,0,1},
   {2,-1,1},
   {2,-2,2}};

static struct patval fuseki9198[] = {
   {0,0,1},
   {-2,-1,1},
   {-2,-2,2}};

static struct patval fuseki9199[] = {
   {0,0,1},
   {-1,2,1},
   {-2,2,2}};

static struct patval fuseki9200[] = {
   {-1,-1,1},
   {1,2,2}};

static struct patval fuseki9201[] = {
   {-1,1,1},
   {1,-2,2}};

static struct patval fuseki9202[] = {
   {-1,-1,1},
   {2,1,2}};

static struct patval fuseki9203[] = {
   {-1,-1,1},
   {1,2,2}};

static struct patval fuseki9204[] = {
   {0,2,1},
   {0,0,1},
   {-2,1,2}};

static struct patval fuseki9205[] = {
   {-2,0,1},
   {0,0,1},
   {-1,2,2}};

static struct patval fuseki9206[] = {
   {0,0,1},
   {0,2,1},
   {2,1,2}};

static struct patval fuseki9207[] = {
   {0,0,1},
   {2,0,1},
   {1,-2,2}};

static struct patval fuseki9208[] = {
   {0,0,1},
   {0,2,1},
   {2,1,2}};

static struct patval fuseki9209[] = {
   {2,1,1},
   {-1,2,1},
   {-2,-1,2}};

static struct patval fuseki9210[] = {
   {-2,1,1},
   {1,2,1},
   {2,-1,2}};

static struct patval fuseki9211[] = {
   {2,-1,1},
   {1,2,1},
   {-1,-2,2}};

static struct patval fuseki9212[] = {
   {-2,1,1},
   {1,2,1},
   {2,-1,2}};

static struct patval fuseki9213[] = {
   {2,1,1},
   {-1,2,1},
   {-2,-1,2}};

static struct patval fuseki9214[] = {
   {2,-1,1},
   {1,1,2}};

static struct patval fuseki9215[] = {
   {1,2,1},
   {-1,1,2}};

static struct patval fuseki9216[] = {
   {2,-1,1},
   {1,1,2}};

static struct patval fuseki9217[] = {
   {1,2,1},
   {-1,1,2}};

static struct patval fuseki9218[] = {
   {-1,2,1},
   {1,1,2}};

static struct patval fuseki9219[] = {
   {2,1,1},
   {1,-1,2}};

static struct patval fuseki9220[] = {
   {-2,-2,1},
   {-2,-1,1},
   {-1,-1,2}};

static struct patval fuseki9221[] = {
   {-2,2,1},
   {-1,2,1},
   {-1,1,2}};

static struct patval fuseki9222[] = {
   {-2,-1,1},
   {0,0,1},
   {-1,-2,2}};

static struct patval fuseki9223[] = {
   {-2,1,1},
   {0,0,1},
   {-1,2,2}};

static struct patval fuseki9224[] = {
   {0,0,1},
   {2,1,1},
   {1,2,2}};

static struct patval fuseki9225[] = {
   {0,0,1},
   {1,2,1},
   {2,1,2}};

static struct patval fuseki9226[] = {
   {-1,0,1},
   {-1,2,2}};

static struct patval fuseki9227[] = {
   {0,-1,1},
   {2,-1,2}};

static struct patval fuseki9228[] = {
   {0,1,1},
   {-2,1,2}};

static struct patval fuseki9229[] = {
   {0,-1,1},
   {2,-1,2}};

static struct patval fuseki9230[] = {
   {-1,0,1},
   {-1,-2,2}};

static struct patval fuseki9231[] = {
   {2,-2,1},
   {-2,1,2}};

static struct patval fuseki9232[] = {
   {-2,2,1},
   {1,-2,2}};

static struct patval fuseki9233[] = {
   {2,-2,1},
   {-2,1,2}};

static struct patval fuseki9234[] = {
   {-2,2,1},
   {1,-2,2}};

static struct patval fuseki9235[] = {
   {2,-2,1},
   {-1,2,2}};

static struct patval fuseki9236[] = {
   {2,-2,1},
   {-1,2,2}};

static struct patval fuseki9237[] = {
   {-2,2,1},
   {2,1,1},
   {1,-2,2}};

static struct patval fuseki9238[] = {
   {-2,1,1},
   {2,2,1},
   {-1,-2,2}};

static struct patval fuseki9239[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-1,2}};

static struct patval fuseki9240[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-1,2}};

static struct patval fuseki9241[] = {
   {-2,-1,1},
   {2,-2,1},
   {-1,2,2}};

static struct patval fuseki9242[] = {
   {0,0,1},
   {2,1,1},
   {2,-2,2}};

static struct patval fuseki9243[] = {
   {-1,2,1},
   {0,0,1},
   {2,2,2}};

static struct patval fuseki9244[] = {
   {2,2,1},
   {-2,1,2}};

static struct patval fuseki9245[] = {
   {2,2,1},
   {-2,1,2}};

static struct patval fuseki9246[] = {
   {2,2,1},
   {-2,1,2}};

static struct patval fuseki9247[] = {
   {2,-2,1},
   {1,2,2}};

static struct patval fuseki9248[] = {
   {0,0,1},
   {-1,1,1},
   {-1,0,2}};

static struct patval fuseki9249[] = {
   {0,0,1},
   {1,-1,1},
   {1,0,2}};

static struct patval fuseki9250[] = {
   {-2,2,1},
   {2,1,1},
   {2,-2,2}};

static struct patval fuseki9251[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-2,2}};

static struct patval fuseki9252[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-2,2}};

static struct patval fuseki9253[] = {
   {0,-2,1},
   {0,0,1},
   {0,2,2}};

static struct patval fuseki9254[] = {
   {0,-2,1},
   {0,0,1},
   {0,2,2}};

static struct patval fuseki9255[] = {
   {0,-2,1},
   {0,0,1},
   {0,2,2}};

static struct patval fuseki9256[] = {
   {0,-2,1},
   {0,0,1},
   {0,2,2}};

static struct patval fuseki9257[] = {
   {-1,-2,1},
   {2,-2,1},
   {0,0,2},
   {2,0,2}};

static struct patval fuseki9258[] = {
   {-2,-2,1},
   {1,-2,1},
   {0,0,2},
   {-2,0,2}};

static struct patval fuseki9259[] = {
   {-1,-2,1},
   {2,-2,1},
   {0,0,2},
   {2,0,2}};

static struct patval fuseki9260[] = {
   {-1,-2,1},
   {2,-2,1},
   {0,0,2},
   {2,0,2}};

static struct patval fuseki9261[] = {
   {2,1,1},
   {0,2,1},
   {2,-1,2},
   {0,0,2}};

static struct patval fuseki9262[] = {
   {2,1,1},
   {0,2,1},
   {2,-1,2},
   {0,0,2}};

static struct patval fuseki9263[] = {
   {2,0,1},
   {1,-2,1},
   {0,0,2},
   {-1,-2,2}};

static struct patval fuseki9264[] = {
   {2,1,1},
   {0,2,1},
   {2,-1,2},
   {0,0,2}};

static struct patval fuseki9265[] = {
   {2,0,1},
   {1,2,1},
   {0,0,2},
   {-1,2,2}};

static struct patval fuseki9266[] = {
   {-2,1,1},
   {1,-2,2}};

static struct patval fuseki9267[] = {
   {2,-1,1},
   {-1,2,2}};

static struct patval fuseki9268[] = {
   {-2,-1,1},
   {1,2,2}};

static struct patval fuseki9269[] = {
   {2,-1,1},
   {-1,2,2}};

static struct patval fuseki9270[] = {
   {-1,-2,1},
   {2,1,2}};

static struct patval fuseki9271[] = {
   {2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9272[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,2}};

static struct patval fuseki9273[] = {
   {2,1,1},
   {1,-2,1},
   {-1,1,2}};

static struct patval fuseki9274[] = {
   {0,0,1},
   {0,-2,1},
   {-1,-2,2}};

static struct patval fuseki9275[] = {
   {0,0,1},
   {2,0,1},
   {2,-1,2}};

static struct patval fuseki9276[] = {
   {0,-2,1},
   {0,0,1},
   {1,-2,2}};

static struct patval fuseki9277[] = {
   {2,-2,1},
   {0,0,1},
   {-2,2,2}};

static struct patval fuseki9278[] = {
   {2,-2,1},
   {0,0,1},
   {-2,2,2}};

static struct patval fuseki9279[] = {
   {-2,-2,1},
   {0,0,1},
   {2,2,2}};

static struct patval fuseki9280[] = {
   {2,-2,1},
   {0,0,1},
   {-2,2,2}};

static struct patval fuseki9281[] = {
   {-1,-2,1},
   {-1,1,1},
   {1,-2,2},
   {2,1,2}};

static struct patval fuseki9282[] = {
   {-1,-2,1},
   {-1,1,1},
   {1,-2,2},
   {2,1,2}};

static struct patval fuseki9283[] = {
   {1,1,1},
   {-2,1,1},
   {1,-2,2},
   {-2,-1,2}};

static struct patval fuseki9284[] = {
   {1,1,1},
   {1,-2,1},
   {-1,-2,2},
   {-2,1,2}};

static struct patval fuseki9285[] = {
   {-1,-1,1},
   {-1,2,1},
   {1,2,2},
   {2,-1,2}};

static struct patval fuseki9286[] = {
   {2,0,1},
   {1,-2,2}};

static struct patval fuseki9287[] = {
   {0,-2,1},
   {2,-1,2}};

static struct patval fuseki9288[] = {
   {0,-2,1},
   {2,-1,2}};

static struct patval fuseki9289[] = {
   {0,1,1},
   {1,1,1},
   {1,2,2},
   {2,2,2}};

static struct patval fuseki9290[] = {
   {0,1,1},
   {-1,1,1},
   {-1,2,2},
   {-2,2,2}};

static struct patval fuseki9291[] = {
   {1,-1,1},
   {1,0,1},
   {2,-2,2},
   {2,-1,2}};

static struct patval fuseki9292[] = {
   {0,0,1},
   {-1,-1,2}};

static struct patval fuseki9293[] = {
   {0,0,1},
   {-1,1,2}};

static struct patval fuseki9294[] = {
   {0,0,1},
   {1,-1,2}};

static struct patval fuseki9295[] = {
   {0,-2,1}};

static struct patval fuseki9296[] = {
   {-2,0,1}};

static struct patval fuseki9297[] = {
   {2,0,1}};

static struct patval fuseki9298[] = {
   {-3,2,1}};

static struct patval fuseki9299[] = {
   {-2,3,1}};

static struct patval fuseki9300[] = {
   {-2,-1,1},
   {2,-2,1},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki9301[] = {
   {2,1,1},
   {-2,2,1},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9302[] = {
   {2,-2,1},
   {1,2,1},
   {-2,2,2},
   {-2,-2,2}};

static struct patval fuseki9303[] = {
   {-2,-1,1},
   {2,-2,1},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki9304[] = {
   {-2,1,1},
   {-2,2,2}};

static struct patval fuseki9305[] = {
   {-1,2,1},
   {-2,2,2}};

static struct patval fuseki9306[] = {
   {-2,1,1},
   {-2,2,2}};

static struct patval fuseki9307[] = {
   {1,2,1},
   {2,2,2}};

static struct patval fuseki9308[] = {
   {-1,1,1},
   {1,1,2}};

static struct patval fuseki9309[] = {
   {-1,1,1},
   {1,1,2}};

static struct patval fuseki9310[] = {
   {1,-1,1},
   {-1,-1,2}};

static struct patval fuseki9311[] = {
   {1,-1,1},
   {1,1,2}};

static struct patval fuseki9312[] = {
   {2,-2,1},
   {1,1,2}};

static struct patval fuseki9313[] = {
   {-2,-2,1},
   {1,-1,2}};

static struct patval fuseki9314[] = {
   {2,2,1},
   {1,-1,2}};

static struct patval fuseki9315[] = {
   {1,-2,1},
   {-1,2,2}};

static struct patval fuseki9316[] = {
   {-1,2,1},
   {1,-2,2}};

static struct patval fuseki9317[] = {
   {-2,1,1},
   {2,-1,2}};

static struct patval fuseki9318[] = {
   {2,-1,1},
   {-2,1,2}};

static struct patval fuseki9319[] = {
   {0,0,1},
   {1,-1,1},
   {2,-1,2}};

static struct patval fuseki9320[] = {
   {0,0,1},
   {1,-1,1},
   {1,-2,2}};

static struct patval fuseki9321[] = {
   {-1,1,1},
   {0,0,1},
   {-1,2,2}};

static struct patval fuseki9322[] = {
   {0,0,1},
   {2,0,1},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9323[] = {
   {0,0,1},
   {2,0,1},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9324[] = {
   {0,2,1},
   {0,0,1},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki9325[] = {
   {0,0,1},
   {-2,0,1},
   {-2,2,2},
   {-2,-2,2}};

static struct patval fuseki9326[] = {
   {-3,1,1},
   {-2,2,1},
   {-2,1,2},
   {0,0,2}};

static struct patval fuseki9327[] = {
   {3,-1,1},
   {2,-2,1},
   {2,-1,2},
   {0,0,2}};

static struct patval fuseki9328[] = {
   {3,-1,1},
   {2,-2,1},
   {2,-1,2},
   {0,0,2}};

static struct patval fuseki9329[] = {
   {0,0,1},
   {2,1,1},
   {0,2,2}};

static struct patval fuseki9330[] = {
   {2,-1,1},
   {0,0,1},
   {0,-2,2}};

static struct patval fuseki9331[] = {
   {-2,-1,1},
   {0,0,1},
   {0,-2,2}};

static struct patval fuseki9332[] = {
   {-1,-2,1},
   {2,-2,1},
   {-1,1,2}};

static struct patval fuseki9333[] = {
   {-2,2,1},
   {1,2,1},
   {1,-1,2}};

static struct patval fuseki9334[] = {
   {-2,2,1},
   {1,2,1},
   {1,-1,2}};

static struct patval fuseki9335[] = {
   {2,1,1},
   {1,-2,1},
   {-2,2,2},
   {-2,-2,2}};

static struct patval fuseki9336[] = {
   {2,-1,1},
   {1,2,1},
   {-2,2,2},
   {-2,-2,2}};

static struct patval fuseki9337[] = {
   {-2,1,1},
   {-1,-2,1},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9338[] = {
   {2,1,1},
   {1,-2,1},
   {-1,2,2},
   {-2,-2,2}};

static struct patval fuseki9339[] = {
   {-2,-1,1},
   {1,-2,1},
   {-2,2,2},
   {2,1,2}};

static struct patval fuseki9340[] = {
   {-2,2,1},
   {0,0,1},
   {1,-2,2}};

static struct patval fuseki9341[] = {
   {2,-2,1},
   {0,0,1},
   {-2,1,2}};

static struct patval fuseki9342[] = {
   {2,-2,1},
   {0,0,1},
   {-2,1,2}};

static struct patval fuseki9343[] = {
   {2,-2,1},
   {0,0,1},
   {-1,2,2}};

static struct patval fuseki9344[] = {
   {-2,1,1},
   {0,2,1},
   {0,0,2}};

static struct patval fuseki9345[] = {
   {2,0,1},
   {1,2,1},
   {0,0,2}};

static struct patval fuseki9346[] = {
   {2,-2,1},
   {-2,2,1},
   {-2,-2,2}};

static struct patval fuseki9347[] = {
   {-2,-2,1},
   {2,2,1},
   {-2,2,2}};

static struct patval fuseki9348[] = {
   {1,1,1},
   {1,-2,1},
   {-2,-2,2}};

static struct patval fuseki9349[] = {
   {-1,1,1},
   {2,1,1},
   {2,-2,2}};

static struct patval fuseki9350[] = {
   {1,1,1},
   {1,-2,1},
   {-2,-2,2}};

static struct patval fuseki9351[] = {
   {1,2,1},
   {1,-1,1},
   {-2,2,2}};

static struct patval fuseki9352[] = {
   {-2,0,1},
   {0,0,1},
   {0,2,2}};

static struct patval fuseki9353[] = {
   {-2,0,1},
   {0,0,1},
   {0,-2,2}};

static struct patval fuseki9354[] = {
   {1,0,1},
   {-1,1,2}};

static struct patval fuseki9355[] = {
   {1,0,1},
   {-1,1,2}};

static struct patval fuseki9356[] = {
   {0,-1,1},
   {0,0,1},
   {1,0,2}};

static struct patval fuseki9357[] = {
   {0,0,1},
   {0,-1,1},
   {-1,0,2}};

static struct patval fuseki9358[] = {
   {-1,-2,1},
   {0,0,1},
   {1,2,2}};

static struct patval fuseki9359[] = {
   {-1,2,1},
   {0,0,1},
   {1,-2,2}};

static struct patval fuseki9360[] = {
   {-1,-1,1},
   {-1,0,1},
   {0,-1,2},
   {0,0,2}};

static struct patval fuseki9361[] = {
   {1,1,1},
   {1,0,1},
   {0,1,2},
   {0,0,2}};

static struct patval fuseki9362[] = {
   {1,1,1},
   {1,0,1},
   {0,1,2},
   {0,0,2}};

static struct patval fuseki9363[] = {
   {-2,-2,1},
   {0,0,1},
   {-2,2,2}};

static struct patval fuseki9364[] = {
   {-2,-2,1},
   {0,0,1},
   {2,-2,2}};

static struct patval fuseki9365[] = {
   {-2,-2,1},
   {0,0,1},
   {-2,2,2}};

static struct patval fuseki9366[] = {
   {-1,0,1},
   {0,1,1},
   {0,0,2},
   {-1,1,2}};

static struct patval fuseki9367[] = {
   {-1,0,1},
   {0,1,1},
   {0,0,2},
   {-1,1,2}};

static struct patval fuseki9368[] = {
   {-1,0,1},
   {0,1,1},
   {0,0,2},
   {-1,1,2}};

static struct patval fuseki9369[] = {
   {2,-1,1},
   {1,-1,1},
   {1,0,2},
   {0,0,2}};

static struct patval fuseki9370[] = {
   {-2,1,1},
   {-1,1,1},
   {-1,0,2},
   {0,0,2}};

static struct patval fuseki9371[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,-2,2}};

static struct patval fuseki9372[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,2,2}};

static struct patval fuseki9373[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,-2,2}};

static struct patval fuseki9374[] = {
   {2,-1,1},
   {1,1,1},
   {0,0,2}};

static struct patval fuseki9375[] = {
   {-2,-1,1},
   {-1,1,1},
   {0,0,2}};

static struct patval fuseki9376[] = {
   {2,1,1},
   {2,-2,1},
   {0,0,2},
   {-1,-2,2}};

static struct patval fuseki9377[] = {
   {2,1,1},
   {2,-2,1},
   {0,0,2},
   {-1,-2,2}};

static struct patval fuseki9378[] = {
   {-1,1,1},
   {-2,1,2}};

static struct patval fuseki9379[] = {
   {-1,1,1},
   {-1,2,2}};

static struct patval fuseki9380[] = {
   {-2,-2,1},
   {2,-1,1},
   {-2,1,2}};

static struct patval fuseki9381[] = {
   {-2,-1,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki9382[] = {
   {-1,-2,1},
   {-1,2,1},
   {1,-2,2},
   {2,1,2}};

static struct patval fuseki9383[] = {
   {-2,-1,1},
   {2,-1,1},
   {-1,2,2},
   {2,1,2}};

static struct patval fuseki9384[] = {
   {-2,-1,1},
   {2,1,1},
   {-1,2,2}};

static struct patval fuseki9385[] = {
   {1,-2,1},
   {-1,2,1},
   {-2,-1,2}};

static struct patval fuseki9386[] = {
   {1,-2,1},
   {-1,2,1},
   {-2,-1,2}};

static struct patval fuseki9387[] = {
   {-1,-1,1},
   {-2,2,2}};

static struct patval fuseki9388[] = {
   {1,-1,1},
   {2,2,2}};

static struct patval fuseki9389[] = {
   {-2,2,1},
   {2,2,1},
   {1,-2,2}};

static struct patval fuseki9390[] = {
   {2,2,1},
   {0,2,1},
   {2,0,2},
   {0,0,2}};

static struct patval fuseki9391[] = {
   {0,2,1},
   {-2,2,1},
   {0,0,2},
   {-2,0,2}};

static struct patval fuseki9392[] = {
   {0,-2,1},
   {2,-2,1},
   {0,0,2},
   {2,0,2}};

static struct patval fuseki9393[] = {
   {1,-1,1},
   {-1,-2,1},
   {0,0,2},
   {-2,-1,2}};

static struct patval fuseki9394[] = {
   {1,-1,1},
   {-1,-2,1},
   {0,0,2},
   {-2,-1,2}};

static struct patval fuseki9395[] = {
   {2,1,1},
   {0,2,1},
   {0,0,2},
   {0,-2,2}};

static struct patval fuseki9396[] = {
   {2,0,1},
   {1,-2,1},
   {0,0,2},
   {-2,0,2}};

static struct patval fuseki9397[] = {
   {2,0,1},
   {1,2,1},
   {0,0,2},
   {-2,0,2}};

static struct patval fuseki9398[] = {
   {-2,-2,1},
   {2,2,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9399[] = {
   {-2,-2,1},
   {2,2,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9400[] = {
   {2,-2,1},
   {-2,2,1},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki9401[] = {
   {2,1,1},
   {-2,2,1},
   {2,-2,2},
   {-2,-1,2}};

static struct patval fuseki9402[] = {
   {-2,-1,1},
   {2,-2,1},
   {-2,2,2},
   {2,1,2}};

static struct patval fuseki9403[] = {
   {-2,-2,1},
   {2,-2,1},
   {-1,1,2}};

static struct patval fuseki9404[] = {
   {2,2,1},
   {2,-2,1},
   {-1,-1,2}};

static struct patval fuseki9405[] = {
   {2,2,1},
   {-1,2,1},
   {-1,-2,2}};

static struct patval fuseki9406[] = {
   {2,2,1},
   {2,-1,1},
   {-2,-1,2}};

static struct patval fuseki9407[] = {
   {-2,2,1},
   {1,1,1},
   {1,-1,2}};

static struct patval fuseki9408[] = {
   {-2,1,1},
   {-1,-1,1},
   {0,0,2},
   {0,2,2}};

static struct patval fuseki9409[] = {
   {-2,1,1},
   {-1,-1,1},
   {0,0,2},
   {0,2,2}};

static struct patval fuseki9410[] = {
   {-1,2,1},
   {0,0,1},
   {0,2,2}};

static struct patval fuseki9411[] = {
   {1,-2,1},
   {0,0,1},
   {0,-2,2}};

static struct patval fuseki9412[] = {
   {1,2,1},
   {0,2,1},
   {1,1,2},
   {0,0,2}};

static struct patval fuseki9413[] = {
   {-2,-1,1},
   {-2,0,1},
   {-1,-1,2},
   {0,0,2}};

static struct patval fuseki9414[] = {
   {0,-2,1},
   {1,-2,1},
   {0,0,2},
   {1,-1,2}};

static struct patval fuseki9415[] = {
   {-1,0,1},
   {-1,1,1},
   {0,0,2}};

static struct patval fuseki9416[] = {
   {-1,-1,1},
   {0,-1,1},
   {0,0,2}};

static struct patval fuseki9417[] = {
   {2,-1,1},
   {-1,-2,1},
   {1,2,2},
   {-2,1,2}};

static struct patval fuseki9418[] = {
   {0,-1,1},
   {0,1,2}};

static struct patval fuseki9419[] = {
   {0,1,1},
   {0,-1,2}};

static struct patval fuseki9420[] = {
   {2,2,1},
   {1,2,1},
   {2,1,2},
   {0,0,2}};

static struct patval fuseki9421[] = {
   {2,2,1},
   {1,2,1},
   {2,1,2},
   {0,0,2}};

static struct patval fuseki9422[] = {
   {-2,-2,1},
   {2,2,1},
   {2,-1,2}};

static struct patval fuseki9423[] = {
   {-2,2,1},
   {2,-2,1},
   {-1,1,2}};

static struct patval fuseki9424[] = {
   {-2,2,1},
   {2,-2,1},
   {1,-1,2}};

static struct patval fuseki9425[] = {
   {-2,2,1},
   {2,-2,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki9426[] = {
   {-2,-2,1},
   {2,2,1},
   {2,0,2},
   {0,0,2}};

static struct patval fuseki9427[] = {
   {-2,-2,1},
   {2,2,1},
   {2,0,2},
   {0,0,2}};

static struct patval fuseki9428[] = {
   {2,2,1},
   {1,-2,1},
   {-2,2,2}};

static struct patval fuseki9429[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,2,2}};

static struct patval fuseki9430[] = {
   {-2,-2,1},
   {2,-1,1},
   {-2,2,2}};

static struct patval fuseki9431[] = {
   {2,1,1},
   {-1,2,1},
   {-2,-2,2}};

static struct patval fuseki9432[] = {
   {2,1,1},
   {1,-2,1},
   {-2,2,2}};

static struct patval fuseki9433[] = {
   {0,1,1},
   {1,-2,2}};

static struct patval fuseki9434[] = {
   {-2,-2,1},
   {2,2,1},
   {0,0,2},
   {-2,1,2}};

static struct patval fuseki9435[] = {
   {-2,-2,1},
   {2,2,1},
   {0,0,2},
   {-1,2,2}};

static struct patval fuseki9436[] = {
   {-2,-2,1},
   {2,2,1},
   {2,-1,2},
   {0,0,2}};

static struct patval fuseki9437[] = {
   {-2,1,1},
   {-1,-2,1},
   {2,2,1},
   {1,1,2},
   {1,-2,2}};

static struct patval fuseki9438[] = {
   {-2,-2,1},
   {2,1,1},
   {-1,2,1},
   {2,-1,2},
   {-1,-1,2}};

static struct patval fuseki9439[] = {
   {-2,-2,1},
   {2,-1,1},
   {1,2,1},
   {-1,2,2},
   {-1,-1,2}};

static struct patval fuseki9440[] = {
   {-2,2,1},
   {2,1,1},
   {1,-2,1},
   {-1,1,2},
   {-1,-2,2}};

static struct patval fuseki9441[] = {
   {1,1,1},
   {1,-1,1},
   {-1,-1,2}};

static struct patval fuseki9442[] = {
   {-1,1,1},
   {2,1,1},
   {1,-1,2}};

static struct patval fuseki9443[] = {
   {-1,-2,1},
   {-1,1,1},
   {1,-1,2}};

static struct patval fuseki9444[] = {
   {2,2,1},
   {-2,0,1},
   {-2,2,1},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9445[] = {
   {-1,2,1},
   {2,1,1},
   {2,-2,2}};

static struct patval fuseki9446[] = {
   {-2,1,1},
   {-1,-2,1},
   {2,-2,2}};

static struct patval fuseki9447[] = {
   {-1,-1,1},
   {2,-1,1},
   {-1,1,2},
   {2,2,2}};

static struct patval fuseki9448[] = {
   {-1,-1,1},
   {2,-1,1},
   {-1,1,2},
   {2,2,2}};

static struct patval fuseki9449[] = {
   {2,-1,1},
   {-1,-2,1},
   {1,1,2},
   {-2,1,2}};

static struct patval fuseki9450[] = {
   {-2,-1,1},
   {1,-2,1},
   {-1,1,2},
   {2,1,2}};

static struct patval fuseki9451[] = {
   {-2,-2,1},
   {1,-2,1},
   {-2,2,2},
   {2,1,2}};

static struct patval fuseki9452[] = {
   {-1,-1,1},
   {0,1,2}};

static struct patval fuseki9453[] = {
   {-2,2,1},
   {1,2,1},
   {2,-2,2}};

static struct patval fuseki9454[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,2}};

static struct patval fuseki9455[] = {
   {2,2,1},
   {-1,2,1},
   {-2,-2,2}};

static struct patval fuseki9456[] = {
   {2,-2,1},
   {1,1,1},
   {-2,1,2}};

static struct patval fuseki9457[] = {
   {-2,-2,1},
   {-1,1,1},
   {2,1,2}};

static struct patval fuseki9458[] = {
   {-1,1,1},
   {2,2,1},
   {2,-1,2}};

static struct patval fuseki9459[] = {
   {2,1,1},
   {1,-2,1},
   {-1,-1,2}};

static struct patval fuseki9460[] = {
   {1,2,1},
   {0,0,1},
   {-1,1,2}};

static struct patval fuseki9461[] = {
   {-2,-1,1},
   {0,0,1},
   {-1,1,2}};

static struct patval fuseki9462[] = {
   {1,0,1},
   {-1,1,1},
   {0,0,1},
   {0,1,2},
   {-1,0,2}};

static struct patval fuseki9463[] = {
   {0,-1,1},
   {0,0,1},
   {1,0,1},
   {1,-1,2},
   {2,-1,2}};

static struct patval fuseki9464[] = {
   {0,0,1},
   {0,-1,1},
   {-1,0,1},
   {-1,-1,2},
   {-2,-1,2}};

static struct patval fuseki9465[] = {
   {0,-1,1},
   {0,0,1},
   {1,0,1},
   {1,-1,2},
   {2,-1,2}};

static struct patval fuseki9466[] = {
   {1,0,1},
   {0,1,1},
   {1,-1,2},
   {0,0,2}};

static struct patval fuseki9467[] = {
   {1,0,1},
   {0,1,1},
   {0,0,2},
   {-1,1,2}};

static struct patval fuseki9468[] = {
   {0,0,1},
   {-1,-1,1},
   {-2,0,2}};

static struct patval fuseki9469[] = {
   {2,-1,1},
   {1,2,1},
   {0,-2,2}};

static struct patval fuseki9470[] = {
   {2,1,1},
   {2,-2,1},
   {0,0,2},
   {-2,2,2}};

static struct patval fuseki9471[] = {
   {-2,2,1},
   {2,-2,1},
   {1,-2,1},
   {1,-1,2},
   {0,-1,2}};

static struct patval fuseki9472[] = {
   {2,1,1},
   {-2,1,1},
   {2,-1,2},
   {-2,-2,2}};

static struct patval fuseki9473[] = {
   {1,2,1},
   {1,-2,1},
   {-1,-2,2},
   {-2,2,2}};

static struct patval fuseki9474[] = {
   {-2,2,1},
   {-1,-2,1},
   {1,-2,2}};

static struct patval fuseki9475[] = {
   {-1,-2,1},
   {-1,1,1},
   {2,-1,2}};

static struct patval fuseki9476[] = {
   {-2,1,1},
   {2,2,1},
   {0,2,2}};

static struct patval fuseki9477[] = {
   {-2,-1,1},
   {-1,-2,1},
   {1,-2,2}};

static struct patval fuseki9478[] = {
   {1,-2,1},
   {2,-1,1},
   {1,-1,2}};

static struct patval fuseki9479[] = {
   {1,-2,1},
   {0,-1,1},
   {0,0,2},
   {0,-2,2}};

static struct patval fuseki9480[] = {
   {-1,-2,1},
   {0,-1,1},
   {0,-2,2},
   {0,0,2}};

static struct patval fuseki9481[] = {
   {1,0,1},
   {2,-1,2}};

static struct patval fuseki9482[] = {
   {0,1,1},
   {1,2,2}};

static struct patval fuseki9483[] = {
   {-1,-1,1},
   {-1,2,1},
   {2,-2,2}};

static struct patval fuseki9484[] = {
   {2,1,1},
   {-1,1,1},
   {-2,-2,2}};

static struct patval fuseki9485[] = {
   {-1,2,1},
   {1,-2,1},
   {1,1,2}};

static struct patval fuseki9486[] = {
   {-1,-2,1},
   {2,-1,1},
   {-1,2,2},
   {2,2,2}};

static struct patval fuseki9487[] = {
   {2,2,1},
   {-1,2,1},
   {0,0,2},
   {-2,1,2}};

static struct patval fuseki9488[] = {
   {-1,-2,1},
   {1,-1,1},
   {-1,1,2}};

static struct patval fuseki9489[] = {
   {-2,0,1},
   {2,0,1},
   {0,0,1},
   {2,-2,2},
   {-1,-2,2}};

static struct patval fuseki9490[] = {
   {-2,-1,1},
   {-2,2,1},
   {1,2,2}};

static struct patval fuseki9491[] = {
   {-2,2,1},
   {0,0,1},
   {1,-1,2}};

static struct patval fuseki9492[] = {
   {-2,2,1},
   {0,0,1},
   {1,-1,2}};

static struct patval fuseki9493[] = {
   {2,1,1},
   {1,-2,1},
   {0,2,1},
   {-2,2,2},
   {-2,-2,2}};

static struct patval fuseki9494[] = {
   {2,0,1},
   {-2,1,1},
   {1,2,1},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9495[] = {
   {-1,2,1},
   {-2,1,2}};

static struct patval fuseki9496[] = {
   {-2,-2,1},
   {-2,1,1},
   {2,-2,1},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki9497[] = {
   {-2,1,1},
   {-1,2,1},
   {-1,1,2},
   {0,0,2}};

static struct patval fuseki9498[] = {
   {1,-1,1},
   {0,2,1},
   {-2,2,2}};

static struct patval fuseki9499[] = {
   {1,-1,1},
   {-1,1,1},
   {-2,2,2}};

static struct patval fuseki9500[] = {
   {1,-1,1},
   {-1,1,1},
   {-2,2,2}};

static struct patval fuseki9501[] = {
   {0,0,1},
   {0,-1,1},
   {-1,1,1},
   {-1,0,2},
   {-1,-1,2}};

static struct patval fuseki9502[] = {
   {-1,1,1},
   {0,0,1},
   {1,0,1},
   {0,1,2},
   {1,1,2}};

static struct patval fuseki9503[] = {
   {1,1,1},
   {0,0,1},
   {-1,-1,2}};

static struct patval fuseki9504[] = {
   {2,0,1},
   {1,-2,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki9505[] = {
   {2,1,1},
   {-1,1,1},
   {-1,-1,2}};

static struct patval fuseki9506[] = {
   {2,1,1},
   {-1,1,1},
   {-1,-1,2}};

static struct patval fuseki9507[] = {
   {-1,-2,1},
   {0,0,1},
   {0,2,1},
   {1,-2,2},
   {2,0,2}};

static struct patval fuseki9508[] = {
   {0,0,1},
   {2,2,1},
   {2,-1,2}};

static struct patval fuseki9509[] = {
   {-2,1,1},
   {1,-1,1},
   {1,2,2}};

static struct patval fuseki9510[] = {
   {-2,1,1},
   {1,-1,1},
   {1,2,2}};

static struct patval fuseki9511[] = {
   {2,-1,1},
   {-2,0,1},
   {0,0,1},
   {1,-2,2},
   {-2,-2,2}};

static struct patval fuseki9512[] = {
   {0,0,1},
   {2,0,1},
   {0,2,2},
   {2,1,2}};

static struct patval fuseki9513[] = {
   {-2,0,1},
   {0,0,1},
   {-2,1,2},
   {0,2,2}};

static struct patval fuseki9514[] = {
   {-1,0,1},
   {-2,-2,2}};

static struct patval fuseki9515[] = {
   {2,-1,1},
   {1,2,1},
   {0,0,2},
   {-2,1,2}};

static struct patval fuseki9516[] = {
   {1,2,1},
   {2,0,1},
   {2,-2,2}};

static struct patval fuseki9517[] = {
   {-2,1,1},
   {0,2,1},
   {2,2,2}};

static struct patval fuseki9518[] = {
   {2,-2,1},
   {1,-2,1},
   {1,-1,2},
   {0,0,2}};

static struct patval fuseki9519[] = {
   {-2,-2,1},
   {2,2,1},
   {2,1,2}};

static struct patval fuseki9520[] = {
   {2,1,1},
   {1,2,1},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki9521[] = {
   {-2,-2,1},
   {2,-1,1},
   {1,1,2}};

static struct patval fuseki9522[] = {
   {-1,-1,1},
   {0,1,1},
   {2,1,2}};

static struct patval fuseki9523[] = {
   {2,-2,1},
   {0,0,1},
   {-2,0,2}};

static struct patval fuseki9524[] = {
   {-2,0,1},
   {-2,2,1},
   {2,2,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki9525[] = {
   {-1,-1,1},
   {0,-2,1},
   {0,0,1},
   {0,-1,2},
   {1,-2,2}};

static struct patval fuseki9526[] = {
   {-2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9527[] = {
   {2,-1,1},
   {1,2,1},
   {-1,0,2}};

static struct patval fuseki9528[] = {
   {2,-2,1},
   {1,2,1},
   {-1,-2,2},
   {-2,1,2}};

static struct patval fuseki9529[] = {
   {-2,-2,1},
   {2,2,1},
   {1,3,1},
   {2,1,2},
   {1,2,2}};

static struct patval fuseki9530[] = {
   {0,0,1},
   {0,2,2}};

static struct patval fuseki9531[] = {
   {0,0,1},
   {0,2,2}};

static struct patval fuseki9532[] = {
   {-2,1,1},
   {0,0,1},
   {2,-1,1},
   {0,2,2},
   {2,1,2}};

static struct patval fuseki9533[] = {
   {0,0,1},
   {2,-2,1},
   {1,-1,2}};

static struct patval fuseki9534[] = {
   {1,2,1},
   {1,-1,1},
   {-1,0,2}};

static struct patval fuseki9535[] = {
   {-1,-2,1},
   {-1,1,1},
   {1,0,2}};

static struct patval fuseki9536[] = {
   {-1,2,1},
   {2,-1,1},
   {0,0,2}};

static struct patval fuseki9537[] = {
   {-2,1,1},
   {-1,1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9538[] = {
   {1,-1,1},
   {1,1,1},
   {2,-1,2}};

static struct patval fuseki9539[] = {
   {-2,-2,1},
   {0,0,1},
   {-2,0,2}};

static struct patval fuseki9540[] = {
   {-2,-2,1},
   {-2,1,1},
   {0,0,2}};

static struct patval fuseki9541[] = {
   {-2,2,1},
   {1,2,1},
   {0,0,2}};

static struct patval fuseki9542[] = {
   {-2,2,1},
   {-1,1,1},
   {-1,2,2},
   {0,0,2}};

static struct patval fuseki9543[] = {
   {2,1,1},
   {1,1,1},
   {2,0,2},
   {0,0,2}};

static struct patval fuseki9544[] = {
   {2,-1,1},
   {1,-1,1},
   {0,0,2},
   {2,0,2}};

static struct patval fuseki9545[] = {
   {2,-2,1},
   {-2,2,1},
   {-1,2,1},
   {-1,1,2},
   {-2,1,2}};

static struct patval fuseki9546[] = {
   {-1,2,1},
   {0,0,1},
   {2,1,1},
   {1,2,2},
   {2,2,2}};

static struct patval fuseki9547[] = {
   {1,1,1},
   {1,-2,1},
   {-2,1,2},
   {-2,-2,2}};

static struct patval fuseki9548[] = {
   {-2,0,1},
   {0,0,1},
   {-1,1,1},
   {-1,2,2},
   {-2,1,2}};

static struct patval fuseki9549[] = {
   {-2,-2,1},
   {1,-2,1},
   {2,1,2}};

static struct patval fuseki9550[] = {
   {-1,2,1},
   {0,0,1},
   {2,-1,2}};

static struct patval fuseki9551[] = {
   {-2,2,1},
   {-1,-2,1},
   {0,0,1},
   {2,-2,2},
   {2,1,2}};

static struct patval fuseki9552[] = {
   {-2,2,1},
   {0,2,1},
   {0,0,2},
   {2,-2,2}};

static struct patval fuseki9553[] = {
   {-2,2,1},
   {1,1,1},
   {-1,-1,2}};

static struct patval fuseki9554[] = {
   {2,-2,1},
   {1,1,1},
   {-1,-1,2}};

static struct patval fuseki9555[] = {
   {-2,1,1},
   {0,0,1},
   {-1,2,2},
   {2,-1,2}};

static struct patval fuseki9556[] = {
   {0,0,1},
   {0,-1,1},
   {-1,-1,2},
   {-2,1,2}};

static struct patval fuseki9557[] = {
   {-2,1,1},
   {-1,-1,1},
   {0,1,2}};

static struct patval fuseki9558[] = {
   {-2,1,1},
   {-1,-1,1},
   {0,1,2}};

static struct patval fuseki9559[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,2},
   {2,1,2}};

static struct patval fuseki9560[] = {
   {-2,2,1},
   {1,-2,1},
   {0,0,2},
   {-1,-2,2}};

static struct patval fuseki9561[] = {
   {-1,-1,1},
   {0,1,1},
   {0,-1,2}};

static struct patval fuseki9562[] = {
   {-1,-1,1},
   {0,1,1},
   {0,-1,2}};

static struct patval fuseki9563[] = {
   {0,0,1},
   {2,0,1},
   {1,-2,2},
   {2,2,2}};

static struct patval fuseki9564[] = {
   {-2,-2,1},
   {1,-2,1},
   {1,0,2}};

static struct patval fuseki9565[] = {
   {1,2,1},
   {1,-2,1},
   {-2,2,2},
   {-2,-2,2}};

static struct patval fuseki9566[] = {
   {-3,-3,1}};

static struct patval fuseki9567[] = {
   {0,1,1},
   {1,1,1},
   {1,2,2},
   {2,1,2}};

static struct patval fuseki9568[] = {
   {4,-1,1}};

static struct patval fuseki9569[] = {
   {-2,1,1},
   {1,1,1},
   {2,-1,2}};

static struct patval fuseki9570[] = {
   {-1,2,1},
   {2,1,1},
   {1,-2,2}};

static struct patval fuseki9571[] = {
   {-2,-1,1},
   {-1,2,1},
   {2,-1,2}};

static struct patval fuseki9572[] = {
   {-2,2,1},
   {1,1,1},
   {0,0,2}};

static struct patval fuseki9573[] = {
   {2,2,1},
   {1,1,2}};

static struct patval fuseki9574[] = {
   {2,1,1},
   {0,0,1},
   {0,-2,2}};

static struct patval fuseki9575[] = {
   {3,1,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,2},
   {-2,-2,2}};

static struct patval fuseki9576[] = {
   {-2,2,1},
   {2,2,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki9577[] = {
   {-2,1,1},
   {2,-2,1},
   {1,1,2}};

static struct patval fuseki9578[] = {
   {-1,-1,1},
   {2,2,1},
   {1,1,2},
   {0,0,2}};

static struct patval fuseki9579[] = {
   {0,0,1},
   {1,0,1},
   {2,1,1},
   {1,1,2},
   {2,2,2}};

static struct patval fuseki9580[] = {
   {-2,1,1},
   {0,-2,1},
   {0,0,1},
   {0,2,2},
   {2,1,2}};

static struct patval fuseki9581[] = {
   {-2,-1,1},
   {2,-2,1},
   {0,0,1},
   {-2,1,2},
   {2,1,2}};

static struct patval fuseki9582[] = {
   {0,0,1},
   {1,-1,1},
   {2,-2,2}};

static struct patval fuseki9583[] = {
   {0,-2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9584[] = {
   {-1,1,1},
   {-1,-1,1},
   {-2,-1,2},
   {-2,-2,2}};

static struct patval fuseki9585[] = {
   {-1,0,1},
   {0,0,1},
   {1,0,1},
   {0,1,2},
   {1,1,2}};

static struct patval fuseki9586[] = {
   {-2,2,1},
   {1,-2,1},
   {2,1,2}};

static struct patval fuseki9587[] = {
   {-1,1,1},
   {2,2,1},
   {1,-2,2}};

static struct patval fuseki9588[] = {
   {-1,-1,1},
   {2,-2,1},
   {1,2,2}};

static struct patval fuseki9589[] = {
   {-1,-2,1},
   {0,0,1},
   {1,2,1},
   {2,-2,2},
   {2,1,2}};

static struct patval fuseki9590[] = {
   {1,1,1},
   {0,2,1},
   {0,1,2},
   {0,0,2}};

static struct patval fuseki9591[] = {
   {1,1,1},
   {0,2,1},
   {0,1,2},
   {0,0,2}};

static struct patval fuseki9592[] = {
   {-2,1,1},
   {-2,2,1},
   {-1,1,2},
   {1,-1,2}};

static struct patval fuseki9593[] = {
   {-2,1,1},
   {-2,2,1},
   {-1,1,2},
   {1,-1,2}};

static struct patval fuseki9594[] = {
   {1,2,1},
   {1,-2,1},
   {-2,2,2}};

static struct patval fuseki9595[] = {
   {0,0,1},
   {-2,1,1},
   {-1,2,1},
   {-2,2,2},
   {-3,1,2}};

static struct patval fuseki9596[] = {
   {0,0,1},
   {1,-2,1},
   {2,-1,1},
   {2,-2,2},
   {3,-1,2}};

static struct patval fuseki9597[] = {
   {2,2,1},
   {1,-2,1},
   {-1,-2,2},
   {-2,2,2}};

static struct patval fuseki9598[] = {
   {-2,-2,1},
   {1,-2,1},
   {-2,2,2},
   {1,1,2}};

static struct patval fuseki9599[] = {
   {2,1,1},
   {2,-2,1},
   {-1,1,2},
   {-2,-2,2}};

static struct patval fuseki9600[] = {
   {-2,-1,1},
   {2,-1,1},
   {0,-1,2}};

static struct patval fuseki9601[] = {
   {-1,-2,1},
   {-1,2,1},
   {1,-1,2}};

static struct patval fuseki9602[] = {
   {-1,1,1},
   {0,-1,1},
   {0,0,1},
   {0,1,2},
   {1,0,2}};

static struct patval fuseki9603[] = {
   {-1,1,1},
   {1,-1,1},
   {0,0,2}};

static struct patval fuseki9604[] = {
   {-2,-2,1},
   {-2,2,1},
   {-1,2,1},
   {-1,1,2},
   {0,1,2}};

static struct patval fuseki9605[] = {
   {-2,-2,1},
   {2,-2,1},
   {1,-1,2}};

static struct patval fuseki9606[] = {
   {-2,-2,1},
   {-2,1,1},
   {2,-2,1},
   {-1,2,2},
   {2,1,2}};

static struct patval fuseki9607[] = {
   {-1,-1,1},
   {2,-1,1},
   {-1,1,2},
   {2,1,2}};

static struct patval fuseki9608[] = {
   {-1,-1,1},
   {-1,1,1},
   {1,1,2},
   {2,-1,2}};

static struct patval fuseki9609[] = {
   {2,1,1},
   {0,2,1},
   {1,2,1},
   {1,1,2},
   {0,1,2}};

static struct patval fuseki9610[] = {
   {1,2,1},
   {1,-2,1},
   {0,0,1},
   {-1,2,2},
   {-2,0,2}};

static struct patval fuseki9611[] = {
   {-1,1,1},
   {1,1,1},
   {0,-1,2}};

static struct patval fuseki9612[] = {
   {2,1,1},
   {2,-2,1},
   {0,0,2},
   {-2,-2,2}};

static struct patval fuseki9613[] = {
   {0,0,1},
   {0,1,1},
   {1,-2,1},
   {1,1,2},
   {2,-1,2}};

static struct patval fuseki9614[] = {
   {2,2,1},
   {1,2,1},
   {2,1,2},
   {1,1,2}};

static struct patval fuseki9615[] = {
   {-2,-1,1},
   {0,-2,1},
   {0,0,2},
   {2,1,2}};

static struct patval fuseki9616[] = {
   {-1,2,1},
   {1,-2,1},
   {0,0,2},
   {2,0,2}};

static struct patval fuseki9617[] = {
   {-1,1,1},
   {0,2,1},
   {1,2,2}};

static struct patval fuseki9618[] = {
   {-2,1,1},
   {0,0,1},
   {-1,1,1},
   {-1,0,2},
   {0,1,2}};

static struct patval fuseki9619[] = {
   {-2,2,1},
   {1,1,1},
   {-1,1,2}};

static struct patval fuseki9620[] = {
   {-2,0,1},
   {0,2,1},
   {0,0,1},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki9621[] = {
   {1,1,1},
   {2,1,1},
   {2,2,2}};

static struct patval fuseki9622[] = {
   {0,0,1},
   {3,0,1},
   {2,-1,1},
   {3,-1,2},
   {2,-2,2}};

static struct patval fuseki9623[] = {
   {-2,1,1},
   {-2,2,1},
   {0,0,1},
   {-1,2,2},
   {1,1,2}};

static struct patval fuseki9624[] = {
   {-2,1,1},
   {1,0,1},
   {1,2,2}};

static struct patval fuseki9625[] = {
   {-1,-1,1},
   {-2,-1,1},
   {-2,-2,2},
   {-1,1,2}};

static struct patval fuseki9626[] = {
   {-2,-1,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9627[] = {
   {-2,-1,1},
   {0,-2,1},
   {0,0,2},
   {2,-1,2}};

static struct patval fuseki9628[] = {
   {-2,1,1},
   {0,2,1},
   {0,0,2},
   {2,1,2}};

static struct patval fuseki9629[] = {
   {1,2,1},
   {1,-1,1},
   {-2,-1,2}};

static struct patval fuseki9630[] = {
   {1,-2,1},
   {2,2,2}};

static struct patval fuseki9631[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,-2,2},
   {2,1,2}};

static struct patval fuseki9632[] = {
   {1,0,1},
   {0,1,1},
   {0,0,2},
   {0,-1,2}};

static struct patval fuseki9633[] = {
   {-1,-1,1},
   {2,-2,1},
   {2,-1,2},
   {2,2,2}};

static struct patval fuseki9634[] = {
   {2,2,1},
   {-1,-1,1},
   {-2,-2,2}};

static struct patval fuseki9635[] = {
   {2,2,1},
   {2,-2,1},
   {0,-1,1},
   {-2,2,2},
   {-2,-2,2}};

static struct patval fuseki9636[] = {
   {1,2,1},
   {2,-1,2}};

static struct patval fuseki9637[] = {
   {1,2,1},
   {0,0,1},
   {-2,1,2}};

static struct patval fuseki9638[] = {
   {1,1,1},
   {0,0,1},
   {-1,2,2}};

static struct patval fuseki9639[] = {
   {-2,1,1},
   {0,0,1},
   {2,0,1},
   {2,-1,2},
   {1,2,2}};

static struct patval fuseki9640[] = {
   {2,1,1},
   {0,2,1},
   {1,-2,2},
   {0,0,2}};

static struct patval fuseki9641[] = {
   {-2,-2,1},
   {2,2,1},
   {0,0,2},
   {-2,2,2}};

static struct patval fuseki9642[] = {
   {-2,-2,1},
   {2,-2,1},
   {1,2,2},
   {2,0,2}};

static struct patval fuseki9643[] = {
   {1,1,1},
   {1,-2,1},
   {-2,-2,2},
   {2,-1,2}};

static struct patval fuseki9644[] = {
   {-2,-1,1},
   {0,2,1},
   {2,-1,2},
   {2,2,2}};

static struct patval fuseki9645[] = {
   {-2,-2,1},
   {2,2,1},
   {-1,1,1},
   {2,-1,2},
   {-1,-1,2}};

static struct patval fuseki9646[] = {
   {1,-1,1},
   {2,-1,1},
   {1,0,2}};

static struct patval fuseki9647[] = {
   {1,-1,1},
   {1,-2,1},
   {0,0,2},
   {2,-2,2}};

static struct patval fuseki9648[] = {
   {3,-1,1},
   {-2,2,1},
   {2,2,1},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9649[] = {
   {-1,-1,1},
   {1,-1,1},
   {2,2,2}};

static struct patval fuseki9650[] = {
   {-2,-2,1},
   {1,2,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9651[] = {
   {-1,1,1},
   {0,0,1},
   {1,-1,1},
   {0,1,2},
   {1,0,2}};

static struct patval fuseki9652[] = {
   {1,0,1},
   {0,-2,1},
   {0,0,2},
   {-2,0,2}};

static struct patval fuseki9653[] = {
   {2,1,1},
   {-2,2,1},
   {-1,0,1},
   {1,-2,2},
   {-2,-1,2}};

static struct patval fuseki9654[] = {
   {-2,-2,1},
   {-2,1,1},
   {0,2,1},
   {1,-2,2},
   {1,1,2}};

static struct patval fuseki9655[] = {
   {0,0,1},
   {1,0,1},
   {2,0,2}};

static struct patval fuseki9656[] = {
   {0,1,1},
   {-1,-1,1},
   {-2,1,2},
   {2,-1,2}};

static struct patval fuseki9657[] = {
   {-2,0,1},
   {1,1,1},
   {0,0,1},
   {1,0,2},
   {0,-2,2}};

static struct patval fuseki9658[] = {
   {-2,-2,1},
   {2,1,1},
   {1,-2,2},
   {-2,2,2}};

static struct patval fuseki9659[] = {
   {-2,-2,1},
   {2,-1,1},
   {-1,2,2},
   {2,1,2}};

static struct patval fuseki9660[] = {
   {-2,-1,1},
   {2,0,1},
   {1,-2,1},
   {1,1,2},
   {-2,1,2}};

static struct patval fuseki9661[] = {
   {1,2,1},
   {0,0,1},
   {-1,1,2},
   {-2,-1,2}};

static struct patval fuseki9662[] = {
   {1,-1,1},
   {-1,0,1},
   {-2,2,2}};

static struct patval fuseki9663[] = {
   {2,2,1},
   {0,1,2}};

static struct patval fuseki9664[] = {
   {2,1,1},
   {1,-2,1},
   {-1,2,1},
   {-1,1,2},
   {-1,-2,2}};

static struct patval fuseki9665[] = {
   {0,0,1},
   {1,-2,1},
   {1,-1,1},
   {2,-2,2},
   {2,-1,2}};

static struct patval fuseki9666[] = {
   {2,2,1},
   {2,-2,1},
   {0,-2,1},
   {-1,2,2},
   {-2,-2,2}};

static struct patval fuseki9667[] = {
   {1,1,1},
   {1,-2,1},
   {-1,-2,2},
   {-2,2,2}};

static struct patval fuseki9668[] = {
   {-2,-1,1},
   {2,-1,1},
   {1,1,1},
   {0,0,2},
   {-1,2,2}};

static struct patval fuseki9669[] = {
   {-2,-2,1},
   {-1,2,1},
   {2,2,1},
   {2,1,2},
   {1,-2,2}};

static struct patval fuseki9670[] = {
   {-1,0,1},
   {1,-1,1},
   {-1,1,2}};

static struct patval fuseki9671[] = {
   {0,-2,1},
   {0,0,1},
   {1,-1,1},
   {1,-2,2},
   {2,-2,2}};

static struct patval fuseki9672[] = {
   {-2,1,1},
   {-1,-1,1},
   {2,-2,1},
   {-1,1,2},
   {2,1,2}};

static struct patval fuseki9673[] = {
   {0,2,1},
   {-1,3,1},
   {0,0,2},
   {-1,2,2}};

static struct patval fuseki9674[] = {
   {1,1,1},
   {0,-2,1},
   {-2,1,2},
   {2,-2,2}};

static struct patval fuseki9675[] = {
   {-1,-2,1},
   {-1,2,1},
   {2,-1,2}};

static struct patval fuseki9676[] = {
   {-2,-2,1},
   {2,-1,1},
   {-1,-1,2}};

static struct patval fuseki9677[] = {
   {2,2,1},
   {1,-2,1},
   {2,-2,1},
   {2,-1,2},
   {-1,-1,2}};

static struct patval fuseki9678[] = {
   {1,-2,1},
   {1,1,1},
   {2,-1,2}};

static struct patval fuseki9679[] = {
   {-2,-2,1},
   {2,0,1},
   {2,-2,1},
   {-2,2,2},
   {2,1,2}};

static struct patval fuseki9680[] = {
   {-2,-2,1},
   {0,2,1},
   {2,1,2}};

static struct patval fuseki9681[] = {
   {2,1,1},
   {-2,0,1},
   {-1,2,1},
   {2,-1,2},
   {-2,-2,2}};

static struct patval fuseki9682[] = {
   {-2,-2,1},
   {1,1,1},
   {0,0,1},
   {-1,-1,2},
   {2,2,2}};

static struct patval fuseki9683[] = {
   {1,-2,1},
   {0,0,1},
   {0,2,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9684[] = {
   {-2,-2,1},
   {-2,1,1},
   {1,-2,1},
   {2,0,2},
   {2,2,2}};

static struct patval fuseki9685[] = {
   {0,0,1},
   {1,-2,1},
   {2,1,2}};

static struct patval fuseki9686[] = {
   {0,1,1},
   {1,0,2}};

static struct patval fuseki9687[] = {
   {2,1,1},
   {-1,2,1},
   {0,-2,1},
   {2,-1,2},
   {-2,-1,2}};

static struct patval fuseki9688[] = {
   {2,-1,1},
   {1,2,1},
   {-1,2,2},
   {-2,-1,2}};

static struct patval fuseki9689[] = {
   {-2,1,1},
   {1,-2,1},
   {2,2,2}};

static struct patval fuseki9690[] = {
   {0,0,1},
   {0,1,1},
   {2,-2,2}};

static struct patval fuseki9691[] = {
   {0,0,1},
   {2,0,1},
   {2,-1,1},
   {2,-2,2},
   {3,-1,2}};

static struct patval fuseki9692[] = {
   {3,0,1},
   {2,2,1},
   {-2,-2,2}};

static struct patval fuseki9693[] = {
   {-3,1,1},
   {-2,2,1},
   {-2,1,2}};

static struct patval fuseki9694[] = {
   {-2,2,1},
   {1,2,1},
   {-1,-1,2},
   {2,-2,2}};

static struct patval fuseki9695[] = {
   {-2,-1,1},
   {2,1,1},
   {1,-2,2},
   {-1,2,2}};

static struct patval fuseki9696[] = {
   {0,0,1},
   {-1,-2,1},
   {-2,2,2}};

static struct patval fuseki9697[] = {
   {-1,0,1},
   {-1,1,1},
   {0,0,2},
   {1,2,2}};

static struct patval fuseki9698[] = {
   {0,-3,1},
   {0,2,1},
   {0,0,2},
   {0,-2,2}};

static struct patval fuseki9699[] = {
   {2,2,1},
   {0,-2,1},
   {2,-1,1},
   {0,2,2},
   {-2,-1,2}};

static struct patval fuseki9700[] = {
   {-1,-1,1},
   {-2,0,1},
   {-2,-2,2},
   {0,0,2}};

static struct patval fuseki9701[] = {
   {-2,1,1},
   {-1,2,1},
   {-1,1,2},
   {1,1,2}};

static struct patval fuseki9702[] = {
   {-1,1,1},
   {-1,2,1},
   {0,0,1},
   {-1,3,2},
   {0,2,2}};

static struct patval fuseki9703[] = {
   {-2,1,1},
   {2,-1,1},
   {0,0,2}};

static struct patval fuseki9704[] = {
   {0,0,1},
   {0,-1,1},
   {-1,1,2},
   {-1,0,2}};

static struct patval fuseki9705[] = {
   {-1,-2,1},
   {0,0,1},
   {2,1,1},
   {2,0,2},
   {1,-2,2}};

static struct patval fuseki9706[] = {
   {-2,-2,1},
   {2,1,1},
   {1,-2,2},
   {-1,2,2}};

static struct patval fuseki9707[] = {
   {-2,2,1},
   {2,-1,1},
   {2,-2,2}};

static struct patval fuseki9708[] = {
   {1,-3,1},
   {0,-2,1},
   {0,0,1},
   {0,2,2},
   {0,-3,2}};

static struct patval fuseki9709[] = {
   {2,-1,1},
   {0,-2,1},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki9710[] = {
   {2,2,1},
   {2,0,1},
   {1,-2,2},
   {-2,1,2}};

static struct patval fuseki9711[] = {
   {2,1,1},
   {1,-2,1},
   {-1,-2,2}};

static struct patval fuseki9712[] = {
   {1,2,1},
   {1,-2,1},
   {-2,2,2},
   {-2,-1,2}};

static struct patval fuseki9713[] = {
   {2,-1,1},
   {1,2,1},
   {-1,1,2},
   {-1,-1,2}};

static struct patval fuseki9714[] = {
   {-2,-2,1},
   {1,-2,1},
   {0,0,2},
   {2,0,2}};

static struct patval fuseki9715[] = {
   {-2,-2,1},
   {-2,2,1},
   {-1,0,1},
   {1,-2,2},
   {1,2,2}};

static struct patval fuseki9716[] = {
   {0,2,1},
   {0,0,1},
   {0,-1,1},
   {-1,-1,2},
   {-2,1,2}};

static struct patval fuseki9717[] = {
   {2,2,1},
   {-1,2,1},
   {2,0,2},
   {-1,-1,2}};

static struct patval fuseki9718[] = {
   {-2,2,1},
   {2,1,1},
   {2,-2,2},
   {-1,-2,2}};

static struct patval fuseki9719[] = {
   {0,2,1},
   {0,0,1},
   {-2,-1,2}};

static struct patval fuseki9720[] = {
   {-2,-2,1},
   {1,-2,1},
   {-2,1,2},
   {1,1,2}};

static struct patval fuseki9721[] = {
   {-2,0,1},
   {0,0,1},
   {2,1,1},
   {2,0,2},
   {1,-2,2}};

static struct patval fuseki9722[] = {
   {2,-2,1},
   {0,1,1},
   {-1,-1,2},
   {-2,1,2}};

static struct patval fuseki9723[] = {
   {0,0,1},
   {1,0,2}};

static struct patval fuseki9724[] = {
   {2,1,1},
   {-1,2,1},
   {0,0,1},
   {2,-1,2},
   {-1,-2,2}};

static struct patval fuseki9725[] = {
   {-2,1,1},
   {2,-2,1},
   {-1,1,1},
   {-1,2,2},
   {-2,2,2}};

static struct patval fuseki9726[] = {
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {2,0,2},
   {0,0,2}};

static struct patval fuseki9727[] = {
   {2,1,1},
   {-1,1,1},
   {-1,2,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9728[] = {
   {-1,0,1},
   {-1,2,1},
   {1,2,2},
   {2,-1,2}};

static struct patval fuseki9729[] = {
   {2,0,1},
   {2,-1,1},
   {1,0,2},
   {0,0,2}};

static struct patval fuseki9730[] = {
   {2,-1,1},
   {1,1,1},
   {0,-2,1},
   {-1,1,2},
   {-1,-1,2}};

static struct patval fuseki9731[] = {
   {-2,1,1},
   {2,-2,1},
   {-1,2,2}};

static struct patval fuseki9732[] = {
   {3,-2,1},
   {-2,2,1},
   {2,1,1},
   {1,-2,2},
   {-2,-2,2}};

static struct patval fuseki9733[] = {
   {0,0,1},
   {-1,-1,1},
   {0,-2,1},
   {0,-1,2},
   {-1,-2,2}};

static struct patval fuseki9734[] = {
   {2,-1,1},
   {-2,1,1},
   {1,1,1},
   {1,-2,2},
   {-2,-2,2}};

static struct patval fuseki9735[] = {
   {2,1,1},
   {1,2,1},
   {1,0,2},
   {-2,1,2}};

static struct patval fuseki9736[] = {
   {-2,2,1},
   {2,-2,1},
   {-1,1,2},
   {2,1,2}};

static struct patval fuseki9737[] = {
   {-2,-2,1},
   {2,-2,1},
   {0,0,1},
   {-2,2,2},
   {3,0,2}};

static struct patval fuseki9738[] = {
   {-2,2,1},
   {0,0,1},
   {2,0,1},
   {2,-2,2},
   {2,1,2}};

static struct patval fuseki9739[] = {
   {-2,0,1},
   {-1,-1,1},
   {-2,2,2},
   {-1,0,2}};

static struct patval fuseki9740[] = {
   {-1,-1,1},
   {-1,1,1},
   {2,-1,2}};

static struct patval fuseki9741[] = {
   {-1,2,1},
   {0,1,1},
   {0,0,1},
   {0,-2,2},
   {0,2,2}};

static struct patval fuseki9742[] = {
   {-2,-2,1},
   {1,-2,1},
   {-1,2,2},
   {2,2,2}};

static struct patval fuseki9743[] = {
   {-2,1,1},
   {2,2,1},
   {1,1,1},
   {1,0,2},
   {0,2,2}};

static struct patval fuseki9744[] = {
   {1,2,1},
   {1,1,1},
   {0,0,2},
   {2,1,2}};

static struct patval fuseki9745[] = {
   {-2,1,1},
   {1,0,1},
   {1,1,2}};

static struct patval fuseki9746[] = {
   {-2,-2,1},
   {-2,-1,1},
   {-2,0,1},
   {-1,-1,2},
   {-1,1,2}};

static struct patval fuseki9747[] = {
   {-1,2,1},
   {0,0,1},
   {0,1,1},
   {0,2,2},
   {1,1,2}};

static struct patval fuseki9748[] = {
   {-2,1,1},
   {2,-2,1},
   {0,2,1},
   {1,1,2},
   {0,-2,2}};

static struct patval fuseki9749[] = {
   {1,1,1},
   {0,0,1},
   {1,-1,1},
   {1,-2,2},
   {-1,2,2}};

static struct patval fuseki9750[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,-3,1},
   {1,2,2},
   {2,-1,2}};

static struct patval fuseki9751[] = {
   {0,1,1},
   {0,-1,1},
   {0,0,1},
   {-1,-1,2},
   {1,1,2}};

static struct patval fuseki9752[] = {
   {2,-1,1},
   {-1,0,1},
   {-1,-2,2},
   {-2,2,2}};

static struct patval fuseki9753[] = {
   {-2,-2,1},
   {-2,1,1},
   {1,-2,2},
   {2,1,2}};

static struct patval fuseki9754[] = {
   {-1,-1,1},
   {1,1,1},
   {0,1,2},
   {0,0,2}};

static struct patval fuseki9755[] = {
   {2,-1,1},
   {4,-1,1},
   {3,-1,1},
   {3,0,2},
   {2,0,2}};

static struct patval fuseki9756[] = {
   {2,1,1},
   {-2,2,1},
   {0,0,1},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki9757[] = {
   {-1,0,1},
   {2,2,1},
   {1,2,2},
   {1,-1,2}};

static struct patval fuseki9758[] = {
   {3,-1,1},
   {-2,2,1},
   {1,-2,1},
   {2,1,2},
   {-2,-2,2}};

static struct patval fuseki9759[] = {
   {2,-1,1},
   {-1,-2,1},
   {0,0,1},
   {1,-2,2},
   {-2,2,2}};

static struct patval fuseki9760[] = {
   {-2,1,1},
   {-1,-2,1},
   {-1,3,1},
   {1,-2,2},
   {1,1,2}};

static struct patval fuseki9761[] = {
   {2,-1,1},
   {0,-2,1},
   {-1,-1,2}};

static struct patval fuseki9762[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,2,1},
   {1,-2,2},
   {-1,1,2}};

static struct patval fuseki9763[] = {
   {2,1,1},
   {-1,2,1},
   {0,-1,1},
   {2,-1,2},
   {-2,-1,2}};

static struct patval fuseki9764[] = {
   {1,0,1},
   {-2,1,1},
   {1,-2,2},
   {-2,-2,2}};

static struct patval fuseki9765[] = {
   {-1,-2,1},
   {-1,1,1},
   {-1,0,2}};

static struct patval fuseki9766[] = {
   {2,1,1},
   {1,-1,1},
   {1,2,1},
   {-1,0,2},
   {2,2,2}};

static struct patval fuseki9767[] = {
   {1,1,1},
   {-1,0,1},
   {-1,1,1},
   {-1,2,2},
   {-2,1,2}};

static struct patval fuseki9768[] = {
   {1,2,1},
   {-1,0,1},
   {-1,1,2},
   {-1,-2,2}};

static struct patval fuseki9769[] = {
   {-2,0,1},
   {0,0,1},
   {-1,1,1},
   {-1,0,2},
   {0,1,2}};

static struct patval fuseki9770[] = {
   {-1,2,1},
   {-2,2,1},
   {-2,1,2},
   {2,-2,2}};

static struct patval fuseki9771[] = {
   {2,-1,1},
   {1,-1,1},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9772[] = {
   {2,1,1},
   {0,1,1},
   {2,-1,2},
   {0,0,2}};

static struct patval fuseki9773[] = {
   {2,-2,1},
   {1,1,1},
   {1,-2,2},
   {-2,1,2}};

static struct patval fuseki9774[] = {
   {-2,1,1},
   {1,-2,1},
   {2,-1,1},
   {2,-2,2},
   {1,1,2}};

static struct patval fuseki9775[] = {
   {2,1,1},
   {2,-2,1},
   {0,0,1},
   {0,-2,2},
   {-2,-1,2}};

static struct patval fuseki9776[] = {
   {-2,-2,1},
   {-2,2,1},
   {-1,-1,2},
   {2,2,2}};

static struct patval fuseki9777[] = {
   {1,0,1},
   {0,2,1},
   {-2,1,2},
   {2,2,2}};

static struct patval fuseki9778[] = {
   {0,-2,1},
   {1,-1,1},
   {1,-2,2},
   {0,0,2}};

static struct patval fuseki9779[] = {
   {-2,2,1},
   {3,0,1},
   {2,-2,2},
   {0,0,2}};

static struct patval fuseki9780[] = {
   {2,-1,1},
   {-2,2,1},
   {-1,2,1},
   {0,0,2},
   {-2,1,2}};

static struct patval fuseki9781[] = {
   {-2,1,1},
   {1,-2,1},
   {1,1,2}};

static struct patval fuseki9782[] = {
   {1,2,1},
   {1,-2,1},
   {-1,-1,2},
   {-2,2,2}};

static struct patval fuseki9783[] = {
   {1,1,1},
   {1,-2,1},
   {-1,-2,2},
   {-2,-1,2}};

static struct patval fuseki9784[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,2},
   {2,2,2}};

static struct patval fuseki9785[] = {
   {-2,-2,1},
   {2,1,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki9786[] = {
   {-2,2,1},
   {2,-2,1},
   {1,-1,2},
   {-1,1,2}};

static struct patval fuseki9787[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,-2,1},
   {1,2,2},
   {2,-2,2}};

static struct patval fuseki9788[] = {
   {-2,0,1},
   {-1,2,1},
   {2,-2,2}};

static struct patval fuseki9789[] = {
   {-1,1,1},
   {0,0,1},
   {1,1,1},
   {1,0,2},
   {0,1,2}};

static struct patval fuseki9790[] = {
   {2,-2,1},
   {3,-1,1},
   {2,1,2}};

static struct patval fuseki9791[] = {
   {0,0,1},
   {0,1,1},
   {2,0,1},
   {1,1,2},
   {2,1,2}};

static struct patval fuseki9792[] = {
   {-2,1,1},
   {-1,-1,1},
   {2,0,1},
   {-1,2,2},
   {2,2,2}};

static struct patval fuseki9793[] = {
   {-2,0,1},
   {-1,-1,1},
   {-2,2,2},
   {1,1,2}};

static struct patval fuseki9794[] = {
   {-2,1,1},
   {1,-2,1},
   {0,0,2},
   {1,2,2}};

static struct patval fuseki9795[] = {
   {2,-1,1},
   {-2,2,1},
   {1,1,1},
   {1,-2,2},
   {-2,-2,2}};

static struct patval fuseki9796[] = {
   {-2,-2,1},
   {2,1,1},
   {1,1,2},
   {1,-2,2}};

static struct patval fuseki9797[] = {
   {0,0,1},
   {2,-1,1},
   {2,-2,1},
   {1,-1,2},
   {1,-2,2}};

static struct patval fuseki9798[] = {
   {-2,-2,1},
   {1,1,1},
   {-1,2,2}};

static struct patval fuseki9799[] = {
   {-2,2,1},
   {2,2,1},
   {0,3,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki9800[] = {
   {2,1,1},
   {-2,2,1},
   {1,-1,1},
   {2,-2,2},
   {-2,-1,2}};

static struct patval fuseki9801[] = {
   {1,1,1},
   {-2,2,1},
   {1,-1,1},
   {-1,-1,2},
   {-2,0,2}};

static struct patval fuseki9802[] = {
   {-1,-2,1},
   {0,1,1},
   {-1,1,1},
   {-1,0,2},
   {1,2,2}};

static struct patval fuseki9803[] = {
   {-1,-1,1},
   {1,0,1},
   {0,2,2},
   {-1,0,2}};

static struct patval fuseki9804[] = {
   {-2,-1,1},
   {0,0,1},
   {-1,-1,1},
   {-1,0,2},
   {-2,1,2}};

static struct patval fuseki9805[] = {
   {1,0,1},
   {-1,0,1},
   {-1,2,2},
   {-1,-2,2}};

static struct patval fuseki9806[] = {
   {1,-1,1},
   {-1,1,1},
   {1,-2,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9807[] = {
   {0,-1,1},
   {-1,0,1},
   {-1,-1,2},
   {0,1,2}};

static struct patval fuseki9808[] = {
   {-1,2,1},
   {1,-2,1},
   {0,0,2},
   {1,1,2}};

static struct patval fuseki9809[] = {
   {2,0,1},
   {1,2,1},
   {0,1,2}};

static struct patval fuseki9810[] = {
   {2,0,1},
   {0,-2,1},
   {0,0,1},
   {1,-2,2},
   {-2,-2,2}};

static struct patval fuseki9811[] = {
   {-1,0,1},
   {0,2,1},
   {1,0,2}};

static struct patval fuseki9812[] = {
   {-2,-2,1},
   {2,2,1},
   {2,0,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9813[] = {
   {2,-1,1},
   {2,-2,1},
   {1,1,2},
   {1,-2,2}};

static struct patval fuseki9814[] = {
   {0,0,1},
   {1,0,1},
   {2,1,1},
   {1,2,2},
   {1,1,2}};

static struct patval fuseki9815[] = {
   {-2,-2,1},
   {0,0,1},
   {-1,-2,1},
   {-1,-1,2},
   {-2,0,2}};

static struct patval fuseki9816[] = {
   {-2,1,1},
   {-1,-2,1},
   {2,0,1},
   {2,-2,2},
   {1,2,2}};

static struct patval fuseki9817[] = {
   {2,0,1},
   {0,0,1},
   {0,2,1},
   {2,-2,2},
   {-1,-2,2}};

static struct patval fuseki9818[] = {
   {-2,1,1},
   {0,0,1},
   {1,-2,1},
   {0,2,2},
   {2,1,2}};

static struct patval fuseki9819[] = {
   {1,1,1},
   {0,2,1},
   {1,0,2},
   {0,0,2}};

static struct patval fuseki9820[] = {
   {-1,0,1},
   {-2,1,1},
   {-2,-1,2},
   {0,0,2}};

static struct patval fuseki9821[] = {
   {-1,-1,1},
   {-2,-1,1},
   {-2,-2,2},
   {2,-1,2}};

static struct patval fuseki9822[] = {
   {-1,-2,1},
   {2,-1,1},
   {0,0,2},
   {-1,2,2}};

static struct patval fuseki9823[] = {
   {0,0,1},
   {3,-3,1},
   {2,-2,2}};

static struct patval fuseki9824[] = {
   {1,0,1},
   {1,-2,1},
   {0,0,2}};

static struct patval fuseki9825[] = {
   {-2,-2,1},
   {-1,1,1},
   {-2,2,1},
   {-2,0,2},
   {0,0,2}};

static struct patval fuseki9826[] = {
   {-2,0,1},
   {0,0,1},
   {-1,2,2},
   {2,1,2}};

static struct patval fuseki9827[] = {
   {-3,0,1},
   {0,2,1},
   {-2,1,1},
   {0,0,2},
   {-2,0,2}};

static struct patval fuseki9828[] = {
   {-1,1,1},
   {-1,2,1},
   {2,-1,1},
   {0,1,2},
   {0,0,2}};

static struct patval fuseki9829[] = {
   {-1,-2,1},
   {2,0,1},
   {0,0,1},
   {1,-2,2},
   {-1,2,2}};

static struct patval fuseki9830[] = {
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9831[] = {
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9832[] = {
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9833[] = {
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9834[] = {
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9835[] = {
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9836[] = {
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9837[] = {
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9838[] = {
   {0,0,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9839[] = {
   {0,0,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9840[] = {
   {0,0,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9841[] = {
   {0,0,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9842[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9843[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9844[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9845[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9846[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9847[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9848[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9849[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1}};

static struct patval fuseki9850[] = {
   {2,2,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9851[] = {
   {2,2,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9852[] = {
   {2,2,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9853[] = {
   {2,2,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9854[] = {
   {2,2,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9855[] = {
   {-2,-2,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9856[] = {
   {-2,-1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9857[] = {
   {2,1,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9858[] = {
   {-2,-1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9859[] = {
   {2,1,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9860[] = {
   {-2,-1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9861[] = {
   {2,1,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9862[] = {
   {2,1,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9863[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,1}};

static struct patval fuseki9864[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,1}};

static struct patval fuseki9865[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,1}};

static struct patval fuseki9866[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,1}};

static struct patval fuseki9867[] = {
   {-1,-1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9868[] = {
   {-1,-1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9869[] = {
   {-1,-1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9870[] = {
   {-1,-1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9871[] = {
   {1,1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9872[] = {
   {-2,2,1},
   {2,0,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9873[] = {
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9874[] = {
   {-2,2,1},
   {0,-2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9875[] = {
   {-2,2,1},
   {0,-2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9876[] = {
   {-2,2,1},
   {0,-2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9877[] = {
   {-2,2,1},
   {2,-2,1},
   {0,2,1},
   {0,0,2}};

static struct patval fuseki9878[] = {
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9879[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {2,2,1}};

static struct patval fuseki9880[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {2,2,1}};

static struct patval fuseki9881[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {2,2,1}};

static struct patval fuseki9882[] = {
   {-2,2,1},
   {2,-2,1},
   {1,2,1},
   {0,0,2}};

static struct patval fuseki9883[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9884[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9885[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9886[] = {
   {-2,2,1},
   {2,-2,1},
   {1,2,1},
   {0,0,2}};

static struct patval fuseki9887[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9888[] = {
   {2,2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9889[] = {
   {2,2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9890[] = {
   {2,2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9891[] = {
   {2,2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9892[] = {
   {2,2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9893[] = {
   {2,2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki9894[] = {
   {-2,2,1},
   {2,-2,1},
   {1,2,1},
   {-1,-1,2}};

static struct patval fuseki9895[] = {
   {-2,2,1},
   {2,-2,1},
   {1,2,1},
   {-1,-1,2}};

static struct patval fuseki9896[] = {
   {-2,2,1},
   {2,-2,1},
   {1,2,1},
   {-1,-1,2}};

static struct patval fuseki9897[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {1,1,2}};

static struct patval fuseki9898[] = {
   {2,0,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki9899[] = {
   {0,2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9900[] = {
   {-2,0,1},
   {-2,-2,2},
   {-2,2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9901[] = {
   {0,2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9902[] = {
   {-2,0,1},
   {-2,-2,2},
   {-2,2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9903[] = {
   {0,2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9904[] = {
   {2,0,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki9905[] = {
   {-2,2,1},
   {0,2,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki9906[] = {
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {-1,-2,2}};

static struct patval fuseki9907[] = {
   {-2,2,1},
   {2,0,1},
   {2,-2,1},
   {1,2,2}};

static struct patval fuseki9908[] = {
   {-2,2,1},
   {2,0,1},
   {2,-2,1},
   {1,2,2}};

static struct patval fuseki9909[] = {
   {-2,2,1},
   {0,2,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki9910[] = {
   {2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {-2,-1,2}};

static struct patval fuseki9911[] = {
   {-2,2,1},
   {2,0,1},
   {2,-2,1},
   {1,2,2}};

static struct patval fuseki9912[] = {
   {-2,2,1},
   {1,1,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9913[] = {
   {2,-2,1},
   {-2,2,1},
   {-1,-1,1},
   {-2,-2,2}};

static struct patval fuseki9914[] = {
   {2,-2,1},
   {-2,2,1},
   {-1,-1,1},
   {-2,-2,2}};

static struct patval fuseki9915[] = {
   {-2,2,1},
   {1,1,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9916[] = {
   {-2,2,1},
   {1,1,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9917[] = {
   {2,0,1},
   {-2,2,2},
   {0,0,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki9918[] = {
   {2,0,1},
   {-2,2,2},
   {0,0,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki9919[] = {
   {0,2,1},
   {-2,2,2},
   {0,0,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9920[] = {
   {0,2,1},
   {-2,2,2},
   {0,0,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9921[] = {
   {2,0,1},
   {-2,2,2},
   {0,0,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki9922[] = {
   {0,2,1},
   {-2,2,2},
   {0,0,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9923[] = {
   {-1,1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9924[] = {
   {2,0,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9925[] = {
   {2,0,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9926[] = {
   {0,2,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9927[] = {
   {0,-2,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9928[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9929[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9930[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9931[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9932[] = {
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9933[] = {
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9934[] = {
   {-2,2,1},
   {2,-1,1},
   {2,-2,1},
   {1,-1,2}};

static struct patval fuseki9935[] = {
   {-2,2,1},
   {1,-2,1},
   {2,-2,1},
   {1,-1,2}};

static struct patval fuseki9936[] = {
   {-2,2,1},
   {2,-2,1},
   {-1,2,1},
   {-1,1,2}};

static struct patval fuseki9937[] = {
   {0,0,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9938[] = {
   {2,0,1},
   {-1,-1,1},
   {1,2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9939[] = {
   {1,1,1},
   {0,-2,1},
   {-2,2,2},
   {-2,-1,2},
   {2,-2,2}};

static struct patval fuseki9940[] = {
   {1,1,1},
   {0,-2,1},
   {-2,2,2},
   {-2,-1,2},
   {2,-2,2}};

static struct patval fuseki9941[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9942[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9943[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9944[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9945[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9946[] = {
   {-2,0,1},
   {0,0,1},
   {0,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9947[] = {
   {0,0,1},
   {0,-2,1},
   {-2,2,2},
   {-2,0,2},
   {2,-2,2}};

static struct patval fuseki9948[] = {
   {0,2,1},
   {0,0,1},
   {-2,2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9949[] = {
   {0,0,1},
   {0,-2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki9950[] = {
   {0,0,1},
   {-2,0,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki9951[] = {
   {2,0,1},
   {0,0,1},
   {2,-2,2},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki9952[] = {
   {-2,1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9953[] = {
   {-1,2,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9954[] = {
   {2,-1,1},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9955[] = {
   {-2,2,1},
   {0,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9956[] = {
   {-2,2,1},
   {0,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki9957[] = {
   {2,-2,1},
   {-2,0,1},
   {-2,2,1},
   {-2,-2,2}};

static struct patval fuseki9958[] = {
   {-2,-2,1},
   {-2,0,1},
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9959[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {2,0,1},
   {0,0,2}};

static struct patval fuseki9960[] = {
   {2,2,1},
   {1,2,1},
   {1,1,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9961[] = {
   {2,2,1},
   {2,1,1},
   {2,-2,2},
   {1,1,2},
   {-2,2,2}};

static struct patval fuseki9962[] = {
   {0,0,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki9963[] = {
   {1,1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki9964[] = {
   {1,1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki9965[] = {
   {1,1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki9966[] = {
   {0,2,1},
   {-2,2,1},
   {0,-2,1},
   {2,-2,1},
   {-2,0,2},
   {0,0,2}};

static struct patval fuseki9967[] = {
   {1,1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9968[] = {
   {1,1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9969[] = {
   {1,1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki9970[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki9971[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {1,2,2}};

static struct patval fuseki9972[] = {
   {2,2,1},
   {-2,2,1},
   {2,-2,1},
   {-2,-1,2}};

static struct patval fuseki9973[] = {
   {0,-2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki9974[] = {
   {-2,0,1},
   {-2,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9975[] = {
   {0,-2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki9976[] = {
   {1,0,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9977[] = {
   {0,-1,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9978[] = {
   {-1,0,1},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9979[] = {
   {2,-2,1},
   {-2,2,1},
   {-1,-2,1},
   {-2,-1,2}};

static struct patval fuseki9980[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,2,1},
   {2,-2,1},
   {2,2,1},
   {2,0,2}};

static struct patval fuseki9981[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {2,0,1},
   {0,-2,2}};

static struct patval fuseki9982[] = {
   {2,0,1},
   {0,0,1},
   {1,2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki9983[] = {
   {0,2,1},
   {0,0,1},
   {-2,2,2},
   {2,-2,2},
   {2,1,2}};

static struct patval fuseki9984[] = {
   {0,2,1},
   {0,0,1},
   {-2,2,2},
   {2,-2,2},
   {2,1,2}};

static struct patval fuseki9985[] = {
   {1,-1,1},
   {0,-1,1},
   {1,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki9986[] = {
   {1,0,1},
   {1,-1,1},
   {-2,2,2},
   {2,-2,2},
   {2,-1,2}};

static struct patval fuseki9987[] = {
   {-2,-2,1},
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9988[] = {
   {-2,-2,1},
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki9989[] = {
   {-2,2,1},
   {0,1,1},
   {1,1,1},
   {2,-2,1},
   {1,2,2},
   {2,2,2}};

static struct patval fuseki9990[] = {
   {-2,2,1},
   {0,1,1},
   {1,1,1},
   {2,-2,1},
   {1,2,2},
   {2,2,2}};

static struct patval fuseki9991[] = {
   {-1,0,1},
   {2,-2,1},
   {-2,2,1},
   {-1,-1,1},
   {-2,-2,2},
   {-2,-1,2}};

static struct patval fuseki9992[] = {
   {-2,2,1},
   {2,-2,1},
   {-1,0,1},
   {-1,-2,2}};

static struct patval fuseki9993[] = {
   {-2,2,1},
   {2,-2,1},
   {-1,0,1},
   {-1,-2,2}};

static struct patval fuseki9994[] = {
   {-2,2,1},
   {1,0,1},
   {2,-2,1},
   {1,2,2}};

static struct patval fuseki9995[] = {
   {-2,2,1},
   {0,1,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki9996[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki9997[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki9998[] = {
   {-2,0,1},
   {1,2,1},
   {-2,2,2},
   {2,-2,2},
   {2,0,2}};

static struct patval fuseki9999[] = {
   {2,0,1},
   {-1,-2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,0,2}};

static struct patval fuseki91000[] = {
   {-2,0,1},
   {1,2,1},
   {-2,2,2},
   {2,-2,2},
   {2,0,2}};

static struct patval fuseki91001[] = {
   {-2,-1,1},
   {0,2,1},
   {0,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91002[] = {
   {-2,-2,1},
   {-2,-1,1},
   {-2,2,2},
   {-1,-2,2},
   {2,-2,2}};

static struct patval fuseki91003[] = {
   {2,2,1},
   {1,2,1},
   {2,-2,2},
   {2,1,2},
   {-2,2,2}};

static struct patval fuseki91004[] = {
   {1,2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91005[] = {
   {2,1,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki91006[] = {
   {-2,-2,1},
   {2,2,1},
   {-1,-1,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91007[] = {
   {-2,-2,1},
   {2,2,1},
   {-1,-1,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91008[] = {
   {0,0,1},
   {0,-2,1},
   {-2,2,2},
   {-2,-2,2},
   {0,2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91009[] = {
   {0,0,1},
   {-2,0,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,0,2},
   {2,2,2}};

static struct patval fuseki91010[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,3,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki91011[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,3,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki91012[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {3,1,1},
   {2,2,2}};

static struct patval fuseki91013[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {1,3,1},
   {2,-2,1},
   {0,2,2}};

static struct patval fuseki91014[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {1,3,1},
   {2,-2,1},
   {0,2,2}};

static struct patval fuseki91015[] = {
   {2,2,1},
   {-1,-1,1},
   {1,1,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91016[] = {
   {-2,0,1},
   {1,2,1},
   {0,0,1},
   {0,-2,2},
   {0,2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91017[] = {
   {0,0,1},
   {2,1,1},
   {0,-2,1},
   {-2,0,2},
   {2,-2,2},
   {2,0,2},
   {-2,2,2}};

static struct patval fuseki91018[] = {
   {-2,2,1},
   {2,1,1},
   {1,1,1},
   {2,-2,1},
   {-1,-1,2},
   {2,2,2}};

static struct patval fuseki91019[] = {
   {-2,2,1},
   {2,-2,1},
   {1,1,1},
   {1,2,1},
   {-1,-1,2},
   {2,2,2}};

static struct patval fuseki91020[] = {
   {-2,-2,1},
   {2,2,1},
   {0,2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91021[] = {
   {-2,-2,1},
   {2,2,1},
   {0,2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91022[] = {
   {-2,-2,1},
   {2,2,1},
   {0,2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91023[] = {
   {-2,2,1},
   {1,3,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki91024[] = {
   {2,1,1},
   {-1,-1,1},
   {1,2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91025[] = {
   {0,0,1},
   {-2,0,1},
   {0,-2,1},
   {-2,2,2},
   {-2,-2,2},
   {0,2,2},
   {2,-2,2},
   {2,0,2},
   {2,2,2}};

static struct patval fuseki91026[] = {
   {2,0,1},
   {0,2,1},
   {0,0,1},
   {0,-2,2},
   {-2,2,2},
   {-2,0,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki91027[] = {
   {2,-2,1},
   {-2,2,1},
   {0,0,1},
   {-2,-2,2}};

static struct patval fuseki91028[] = {
   {-2,2,1},
   {2,-2,1},
   {1,1,1},
   {0,0,2}};

static struct patval fuseki91029[] = {
   {-2,2,1},
   {2,-2,1},
   {1,1,1},
   {0,0,2}};

static struct patval fuseki91030[] = {
   {-2,2,1},
   {2,-2,1},
   {1,1,1},
   {0,0,2}};

static struct patval fuseki91031[] = {
   {-2,2,1},
   {0,-2,1},
   {2,-2,1},
   {1,-2,1},
   {1,-1,2},
   {0,-1,2}};

static struct patval fuseki91032[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {1,-3,1},
   {1,1,2},
   {0,-2,2}};

static struct patval fuseki91033[] = {
   {-2,2,1},
   {3,-1,1},
   {1,2,1},
   {2,-2,1},
   {2,0,2},
   {-1,-1,2}};

static struct patval fuseki91034[] = {
   {0,0,1},
   {0,-2,1},
   {-2,2,2},
   {-2,0,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91035[] = {
   {0,0,1},
   {-2,0,1},
   {-2,2,2},
   {0,-2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91036[] = {
   {1,-2,1},
   {0,0,1},
   {-2,2,2},
   {-2,0,2},
   {2,-2,2}};

static struct patval fuseki91037[] = {
   {0,0,1},
   {-1,2,1},
   {-2,2,2},
   {2,-2,2},
   {2,0,2}};

static struct patval fuseki91038[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {1,-1,1},
   {2,-2,1},
   {2,2,1},
   {2,0,2}};

static struct patval fuseki91039[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {1,1,1},
   {2,-2,1},
   {0,2,2}};

static struct patval fuseki91040[] = {
   {-3,0,1},
   {2,-2,1},
   {-2,2,1},
   {-1,-2,1},
   {1,1,2},
   {-2,-1,2}};

static struct patval fuseki91041[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {0,-3,1},
   {1,1,2},
   {-1,-2,2}};

static struct patval fuseki91042[] = {
   {-2,2,1},
   {3,0,1},
   {1,2,1},
   {2,-2,1},
   {2,1,2},
   {-1,-1,2}};

static struct patval fuseki91043[] = {
   {-2,2,1},
   {2,-2,1},
   {1,1,1},
   {-1,-1,2}};

static struct patval fuseki91044[] = {
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki91045[] = {
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki91046[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {2,2,1},
   {2,0,1},
   {2,-2,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki91047[] = {
   {-2,2,1},
   {0,1,1},
   {2,1,1},
   {2,-2,1},
   {1,2,2},
   {2,2,2}};

static struct patval fuseki91048[] = {
   {-1,0,1},
   {2,-2,1},
   {-2,2,1},
   {-1,-2,1},
   {-2,-2,2},
   {-2,-1,2}};

static struct patval fuseki91049[] = {
   {-2,-2,1},
   {-2,0,1},
   {-2,2,1},
   {2,0,1},
   {2,-2,1},
   {0,0,2},
   {0,-2,2}};

static struct patval fuseki91050[] = {
   {0,1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91051[] = {
   {0,1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91052[] = {
   {1,1,1},
   {1,-1,1},
   {1,0,1},
   {-2,2,2},
   {2,-2,2},
   {2,-1,2},
   {2,0,2}};

static struct patval fuseki91053[] = {
   {2,-2,1},
   {-2,2,1},
   {-1,-1,1},
   {0,2,1},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki91054[] = {
   {1,1,1},
   {-2,2,2},
   {0,0,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91055[] = {
   {1,1,1},
   {-2,2,2},
   {0,0,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91056[] = {
   {-2,2,1},
   {0,2,1},
   {2,-2,1},
   {2,0,2}};

static struct patval fuseki91057[] = {
   {-2,2,1},
   {0,2,1},
   {2,-2,1},
   {2,0,2}};

static struct patval fuseki91058[] = {
   {2,2,1},
   {-1,-2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-1,2}};

static struct patval fuseki91059[] = {
   {2,2,1},
   {-1,-2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-1,2}};

static struct patval fuseki91060[] = {
   {0,2,1},
   {0,0,1},
   {0,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91061[] = {
   {0,2,1},
   {0,0,1},
   {0,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91062[] = {
   {0,0,1},
   {2,1,1},
   {0,-2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,0,2},
   {-2,0,2}};

static struct patval fuseki91063[] = {
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {2,-3,1},
   {1,-2,2},
   {0,0,2}};

static struct patval fuseki91064[] = {
   {0,0,1},
   {0,-2,1},
   {-1,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91065[] = {
   {0,0,1},
   {0,-2,1},
   {-1,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91066[] = {
   {-2,2,1},
   {3,1,1},
   {1,2,1},
   {2,-2,1},
   {2,0,2},
   {0,0,2}};

static struct patval fuseki91067[] = {
   {1,-2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91068[] = {
   {-2,-1,1},
   {-2,-2,2},
   {-2,2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91069[] = {
   {1,2,1},
   {-1,-1,1},
   {2,2,1},
   {-2,2,2},
   {2,-2,2},
   {2,1,2},
   {1,1,2}};

static struct patval fuseki91070[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {1,1,2}};

static struct patval fuseki91071[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {1,1,2}};

static struct patval fuseki91072[] = {
   {1,-1,1},
   {0,-2,1},
   {1,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91073[] = {
   {-2,-2,1},
   {0,0,1},
   {-1,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91074[] = {
   {1,2,1},
   {2,2,1},
   {1,1,1},
   {-2,2,2},
   {2,-2,2},
   {2,1,2},
   {0,1,2}};

static struct patval fuseki91075[] = {
   {-2,-2,1},
   {-1,-1,1},
   {-1,-2,1},
   {-2,2,2},
   {-2,-1,2},
   {0,-1,2},
   {2,-2,2}};

static struct patval fuseki91076[] = {
   {-2,2,1},
   {2,-1,1},
   {1,0,1},
   {2,-2,1},
   {1,-1,2},
   {2,0,2}};

static struct patval fuseki91077[] = {
   {-1,0,1},
   {-2,1,1},
   {-2,2,1},
   {2,-2,1},
   {-1,1,2},
   {-2,0,2}};

static struct patval fuseki91078[] = {
   {0,0,1},
   {-1,-2,1},
   {0,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91079[] = {
   {0,0,1},
   {-1,-2,1},
   {0,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91080[] = {
   {-2,-3,1},
   {2,-2,1},
   {-2,2,1},
   {-1,-2,1},
   {0,0,2},
   {-2,-2,2}};

static struct patval fuseki91081[] = {
   {-3,-2,1},
   {2,-2,1},
   {-2,-1,1},
   {-2,2,1},
   {0,0,2},
   {-2,-2,2}};

static struct patval fuseki91082[] = {
   {1,-2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91083[] = {
   {-2,1,1},
   {-2,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91084[] = {
   {2,2,1},
   {0,-2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-1,2}};

static struct patval fuseki91085[] = {
   {-2,0,1},
   {2,2,1},
   {-1,-2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91086[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki91087[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,2,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki91088[] = {
   {2,0,1},
   {0,0,1},
   {-2,2,2},
   {0,2,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki91089[] = {
   {0,2,1},
   {0,0,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,0,2},
   {2,2,2}};

static struct patval fuseki91090[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {0,2,1},
   {-1,-2,2},
   {2,2,2}};

static struct patval fuseki91091[] = {
   {-2,1,1},
   {-1,1,1},
   {-2,2,2},
   {-1,2,2},
   {2,-2,2}};

static struct patval fuseki91092[] = {
   {2,-2,1},
   {-2,-1,1},
   {-2,2,1},
   {-1,-1,1},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki91093[] = {
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {-1,-1,2}};

static struct patval fuseki91094[] = {
   {2,2,1},
   {-1,-2,1},
   {1,1,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91095[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {2,1,1},
   {1,3,1},
   {2,-2,1},
   {1,1,2},
   {0,2,2}};

static struct patval fuseki91096[] = {
   {-2,1,1},
   {-2,-2,2},
   {-2,2,2},
   {0,0,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91097[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,-2,1},
   {1,0,2}};

static struct patval fuseki91098[] = {
   {-2,2,1},
   {2,-2,1},
   {1,2,1},
   {-1,0,2}};

static struct patval fuseki91099[] = {
   {1,-2,1},
   {2,0,1},
   {0,0,1},
   {-2,0,2},
   {2,-3,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91100[] = {
   {1,-2,1},
   {2,0,1},
   {0,0,1},
   {-2,0,2},
   {2,-3,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91101[] = {
   {-2,2,1},
   {-1,-1,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki91102[] = {
   {2,1,1},
   {0,2,1},
   {-1,-2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91103[] = {
   {2,0,1},
   {0,0,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-1,2}};

static struct patval fuseki91104[] = {
   {0,2,1},
   {0,0,1},
   {-1,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91105[] = {
   {1,1,1},
   {1,0,1},
   {0,2,1},
   {0,0,2},
   {-2,2,2},
   {-2,-2,2},
   {1,3,2},
   {2,-2,2},
   {2,1,2},
   {2,2,2}};

static struct patval fuseki91106[] = {
   {2,0,1},
   {1,1,1},
   {0,0,2},
   {1,-1,2},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki91107[] = {
   {2,0,1},
   {1,-1,1},
   {0,0,2},
   {-2,2,2},
   {1,1,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki91108[] = {
   {1,1,1},
   {0,2,1},
   {0,0,2},
   {-2,2,2},
   {-2,-2,2},
   {1,3,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91109[] = {
   {2,2,1},
   {-2,0,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki91110[] = {
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {2,0,2}};

static struct patval fuseki91111[] = {
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {2,0,2}};

static struct patval fuseki91112[] = {
   {-2,2,1},
   {-1,-3,1},
   {2,-2,1},
   {-1,-1,2}};

static struct patval fuseki91113[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,2,1},
   {2,2,1},
   {2,-2,1},
   {1,1,2}};

static struct patval fuseki91114[] = {
   {-2,-2,1},
   {2,2,1},
   {-1,-2,1},
   {-2,2,2},
   {0,2,2},
   {2,-2,2},
   {-2,-1,2}};

static struct patval fuseki91115[] = {
   {-3,1,1},
   {2,-2,1},
   {-2,2,1},
   {-2,1,2}};

static struct patval fuseki91116[] = {
   {2,1,1},
   {0,0,1},
   {1,2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91117[] = {
   {-2,-2,1},
   {3,-1,1},
   {2,2,1},
   {0,2,2},
   {2,-2,2},
   {-1,-1,2},
   {-2,2,2}};

static struct patval fuseki91118[] = {
   {-1,2,1},
   {-2,1,1},
   {-2,2,2},
   {-3,1,2},
   {2,-2,2}};

static struct patval fuseki91119[] = {
   {2,-1,1},
   {1,-2,1},
   {1,-3,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91120[] = {
   {-2,-2,1},
   {2,2,1},
   {-1,-2,1},
   {-1,-1,2},
   {0,-1,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91121[] = {
   {-2,-2,1},
   {2,1,1},
   {1,2,1},
   {0,2,2},
   {0,-1,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91122[] = {
   {1,1,1},
   {0,-2,1},
   {-2,2,2},
   {0,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91123[] = {
   {-2,-2,1},
   {0,0,1},
   {-2,2,2},
   {-2,0,2},
   {2,-2,2}};

static struct patval fuseki91124[] = {
   {-2,-2,1},
   {0,0,1},
   {0,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91125[] = {
   {0,0,1},
   {2,0,1},
   {0,-2,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {-2,0,2}};

static struct patval fuseki91126[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {1,2,2}};

static struct patval fuseki91127[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki91128[] = {
   {2,2,1},
   {1,2,1},
   {1,3,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91129[] = {
   {-2,-2,1},
   {-2,2,1},
   {-1,0,1},
   {2,-2,1},
   {0,1,2}};

static struct patval fuseki91130[] = {
   {2,-1,1},
   {0,0,1},
   {-2,2,2},
   {2,-2,2},
   {-2,0,2}};

static struct patval fuseki91131[] = {
   {-2,-2,1},
   {2,2,1},
   {-2,2,1},
   {-1,0,1},
   {2,-2,1},
   {-2,0,2}};

static struct patval fuseki91132[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,2,1},
   {0,3,1},
   {2,-2,1},
   {0,2,2}};

static struct patval fuseki91133[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {1,-1,1},
   {0,-2,2},
   {2,2,2}};

static struct patval fuseki91134[] = {
   {-3,-1,1},
   {-2,-2,1},
   {2,0,1},
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {-2,-1,2},
   {0,-2,2}};

static struct patval fuseki91135[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {2,2,1},
   {1,3,1},
   {2,-2,1},
   {2,0,2},
   {1,2,2}};

static struct patval fuseki91136[] = {
   {0,1,1},
   {-2,2,1},
   {2,-2,1},
   {-1,2,1},
   {-2,1,2},
   {-1,1,2}};

static struct patval fuseki91137[] = {
   {-2,2,1},
   {2,2,1},
   {2,0,1},
   {2,-2,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki91138[] = {
   {-2,-2,1},
   {-2,0,1},
   {-2,2,1},
   {0,-2,1},
   {0,2,1},
   {2,-2,1},
   {2,0,1},
   {2,2,1}};

static struct patval fuseki91139[] = {
   {3,0,1},
   {0,0,1},
   {2,0,1},
   {2,-2,2},
   {1,2,2},
   {-2,2,2},
   {3,1,2}};

static struct patval fuseki91140[] = {
   {1,2,1},
   {1,1,1},
   {-2,2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91141[] = {
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {1,1,2}};

static struct patval fuseki91142[] = {
   {2,0,1},
   {0,2,1},
   {0,0,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-1,2},
   {2,2,2}};

static struct patval fuseki91143[] = {
   {0,0,1},
   {-2,0,1},
   {0,-2,1},
   {-2,2,2},
   {-2,-2,2},
   {1,2,2},
   {2,-2,2}};

static struct patval fuseki91144[] = {
   {2,0,1},
   {-1,-1,1},
   {2,-2,2},
   {-2,2,2},
   {2,2,2}};

static struct patval fuseki91145[] = {
   {-1,1,1},
   {-2,0,2},
   {-2,2,2},
   {-2,-2,2},
   {0,-2,2},
   {0,2,2},
   {2,-2,2},
   {2,0,2},
   {2,2,2}};

static struct patval fuseki91146[] = {
   {-2,2,1},
   {1,-2,1},
   {2,-2,1},
   {2,-1,2}};

static struct patval fuseki91147[] = {
   {1,2,1},
   {2,2,1},
   {-2,-2,2},
   {1,3,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91148[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,3,1},
   {2,-2,1},
   {1,3,1},
   {1,2,2},
   {2,2,2}};

static struct patval fuseki91149[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {0,-1,1},
   {1,1,2},
   {0,-2,2}};

static struct patval fuseki91150[] = {
   {2,1,1},
   {-1,-2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,0,2}};

static struct patval fuseki91151[] = {
   {1,0,1},
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {-2,-1,2},
   {-1,-2,2}};

static struct patval fuseki91152[] = {
   {0,0,1},
   {-2,-2,1},
   {-2,-1,1},
   {-2,2,2},
   {-1,-2,2},
   {-2,-3,2},
   {2,-2,2}};

static struct patval fuseki91153[] = {
   {-2,-2,1},
   {-2,2,1},
   {1,1,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki91154[] = {
   {-2,-2,1},
   {0,-2,1},
   {-2,2,2},
   {-2,0,2},
   {2,-2,2}};

static struct patval fuseki91155[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,1},
   {0,2,1},
   {0,0,2},
   {-2,0,2}};

static struct patval fuseki91156[] = {
   {-2,-1,1},
   {-1,-2,1},
   {-2,2,2},
   {-2,0,2},
   {2,-2,2}};

static struct patval fuseki91157[] = {
   {-2,2,1},
   {-1,1,1},
   {2,-2,1},
   {0,0,2}};

static struct patval fuseki91158[] = {
   {0,-2,1},
   {-2,-1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,0,2},
   {2,2,2}};

static struct patval fuseki91159[] = {
   {0,-1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91160[] = {
   {1,1,1},
   {1,-1,1},
   {0,-2,1},
   {0,-1,2},
   {-2,2,2},
   {-2,-1,2},
   {2,-2,2}};

static struct patval fuseki91161[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {0,1,1},
   {2,2,1},
   {2,-2,1},
   {1,1,2}};

static struct patval fuseki91162[] = {
   {0,2,1},
   {-2,1,1},
   {-2,2,2},
   {0,0,2},
   {-2,-2,2},
   {1,3,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91163[] = {
   {-1,1,1},
   {-2,1,1},
   {-2,2,2},
   {-2,0,2},
   {2,-2,2}};

static struct patval fuseki91164[] = {
   {1,1,1},
   {2,2,1},
   {-2,-2,2},
   {1,2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91165[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,0,1},
   {2,-2,1},
   {1,1,2},
   {0,-2,2}};

static struct patval fuseki91166[] = {
   {0,-2,1},
   {-1,-3,1},
   {-2,2,2},
   {0,-3,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91167[] = {
   {1,0,1},
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {-2,-2,2},
   {0,-2,2}};

static struct patval fuseki91168[] = {
   {-1,2,1},
   {-2,1,1},
   {0,2,1},
   {-1,1,2},
   {-2,-2,2},
   {0,0,2},
   {-2,2,2},
   {1,1,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91169[] = {
   {-1,1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91170[] = {
   {-2,-2,1},
   {2,2,1},
   {0,0,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91171[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {2,-2,1},
   {2,0,1},
   {0,2,2}};

static struct patval fuseki91172[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {2,0,2},
   {0,0,2}};

static struct patval fuseki91173[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,-2,1},
   {0,2,1},
   {0,-2,2},
   {2,1,2}};

static struct patval fuseki91174[] = {
   {-2,-2,1},
   {-2,1,1},
   {-2,2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91175[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,2,1},
   {1,2,1},
   {2,-2,1},
   {1,1,2}};

static struct patval fuseki91176[] = {
   {0,2,1},
   {-1,-2,1},
   {-2,2,2},
   {2,-2,2},
   {2,1,2}};

static struct patval fuseki91177[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {0,-2,2}};

static struct patval fuseki91178[] = {
   {0,2,1},
   {1,3,1},
   {0,0,2},
   {-2,-2,2},
   {0,3,2},
   {-2,2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91179[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {0,2,1},
   {2,-2,1},
   {2,2,1}};

static struct patval fuseki91180[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,0,1},
   {2,-2,1},
   {0,-2,2}};

static struct patval fuseki91181[] = {
   {-2,2,1},
   {1,0,1},
   {2,-2,1},
   {2,1,2}};

static struct patval fuseki91182[] = {
   {1,2,1},
   {2,2,1},
   {0,2,1},
   {1,1,2},
   {-2,2,2},
   {2,-2,2},
   {0,1,2}};

static struct patval fuseki91183[] = {
   {-2,2,1},
   {-1,-2,1},
   {-1,0,1},
   {2,-2,1},
   {0,2,2},
   {2,1,2}};

static struct patval fuseki91184[] = {
   {-2,-2,1},
   {-2,2,1},
   {2,0,1},
   {0,2,1},
   {2,2,1},
   {2,-2,1},
   {0,-2,2},
   {1,1,2}};

static struct patval fuseki91185[] = {
   {-2,2,1},
   {-1,-3,1},
   {2,-2,1},
   {0,-2,1},
   {0,0,2},
   {-1,-2,2}};

static struct patval fuseki91186[] = {
   {0,3,1},
   {-1,-1,1},
   {0,2,1},
   {-1,3,2},
   {-2,2,2},
   {2,-2,2},
   {2,1,2}};

static struct patval fuseki91187[] = {
   {2,2,1},
   {-1,1,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2}};

static struct patval fuseki91188[] = {
   {2,0,1},
   {1,2,1},
   {0,2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91189[] = {
   {1,1,1},
   {-2,-1,1},
   {-1,-1,1},
   {-1,-2,2},
   {-2,2,2},
   {-3,0,2},
   {2,-2,2}};

static struct patval fuseki91190[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,1,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki91191[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,1,1},
   {2,-2,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki91192[] = {
   {0,2,1},
   {-2,1,1},
   {-2,2,2},
   {0,-2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91193[] = {
   {-2,-2,1},
   {1,2,1},
   {0,0,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91194[] = {
   {3,1,1},
   {1,2,1},
   {2,-2,2},
   {2,0,2},
   {-2,2,2}};

static struct patval fuseki91195[] = {
   {-2,-2,1},
   {2,2,1},
   {-1,-2,1},
   {-2,2,2},
   {-1,-1,2},
   {2,-2,2},
   {-2,-1,2}};

static struct patval fuseki91196[] = {
   {2,2,1},
   {-1,2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-1,2}};

static struct patval fuseki91197[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {2,-2,1},
   {1,1,2}};

static struct patval fuseki91198[] = {
   {-2,2,1},
   {0,2,1},
   {2,-2,1},
   {1,3,1},
   {1,2,2},
   {2,0,2}};

static struct patval fuseki91199[] = {
   {1,2,1},
   {2,2,1},
   {1,1,2},
   {-2,-2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91200[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {2,-2,1},
   {2,1,1},
   {1,1,2}};

static struct patval fuseki91201[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,1},
   {1,2,1},
   {0,0,2},
   {-2,0,2}};

static struct patval fuseki91202[] = {
   {1,1,1},
   {-2,-2,1},
   {-2,-1,1},
   {-2,2,2},
   {-1,-2,2},
   {-3,0,2},
   {2,-2,2}};

static struct patval fuseki91203[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {0,3,1},
   {2,-2,1},
   {0,2,2}};

static struct patval fuseki91204[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {2,1,1},
   {2,-2,1},
   {2,0,1},
   {1,1,2},
   {1,0,2}};

static struct patval fuseki91205[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {-2,0,2}};

static struct patval fuseki91206[] = {
   {1,1,1},
   {1,0,1},
   {0,0,2},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,1,2},
   {2,2,2}};

static struct patval fuseki91207[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {2,2,1},
   {2,-2,1},
   {0,2,2}};

static struct patval fuseki91208[] = {
   {0,2,1},
   {-2,1,1},
   {-2,2,2},
   {0,0,2},
   {-2,-2,2},
   {1,1,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91209[] = {
   {-2,-2,1},
   {0,0,1},
   {-2,2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91210[] = {
   {-3,1,1},
   {-2,-2,1},
   {2,2,1},
   {-2,2,1},
   {2,-2,1},
   {-2,1,2}};

static struct patval fuseki91211[] = {
   {-2,2,1},
   {-1,-1,1},
   {2,-2,1},
   {2,2,2}};

static struct patval fuseki91212[] = {
   {2,0,1},
   {0,0,1},
   {0,-2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-1,2},
   {2,2,2}};

static struct patval fuseki91213[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {2,-2,1},
   {2,-1,2},
   {1,-2,2}};

static struct patval fuseki91214[] = {
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {0,-2,1},
   {0,0,2},
   {-1,-2,2}};

static struct patval fuseki91215[] = {
   {1,2,1},
   {1,-1,1},
   {1,-2,1},
   {0,0,2},
   {0,-2,2},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91216[] = {
   {1,-2,1},
   {2,-1,1},
   {0,0,2},
   {-2,-2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91217[] = {
   {2,-2,1},
   {-2,2,1},
   {-1,-2,1},
   {-1,0,1},
   {-2,0,2},
   {2,2,2}};

static struct patval fuseki91218[] = {
   {-2,-2,1},
   {0,0,1},
   {-2,2,2},
   {1,2,2},
   {2,-2,2}};

static struct patval fuseki91219[] = {
   {-2,-1,1},
   {-2,0,1},
   {-1,1,1},
   {-2,2,2},
   {-1,0,2},
   {-2,1,2},
   {2,-2,2}};

static struct patval fuseki91220[] = {
   {0,-2,1},
   {-2,0,1},
   {2,1,1},
   {-2,-2,2},
   {0,2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91221[] = {
   {-2,-2,1},
   {2,0,1},
   {0,0,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91222[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,1,1},
   {2,-2,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki91223[] = {
   {2,2,1},
   {-1,-1,1},
   {-1,-3,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91224[] = {
   {-3,0,1},
   {-2,-2,1},
   {2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {0,0,2},
   {-2,0,2}};

static struct patval fuseki91225[] = {
   {-1,0,1},
   {-2,2,1},
   {-1,-2,1},
   {2,-2,1},
   {1,0,2},
   {-2,0,2}};

static struct patval fuseki91226[] = {
   {-2,-1,1},
   {-1,2,1},
   {-2,2,2},
   {0,-2,2},
   {2,-2,2}};

static struct patval fuseki91227[] = {
   {-2,-2,1},
   {2,2,1},
   {1,1,1},
   {0,2,2},
   {2,-2,2},
   {2,0,2},
   {-2,2,2}};

static struct patval fuseki91228[] = {
   {2,0,1},
   {1,2,1},
   {-1,2,1},
   {0,-2,2},
   {-2,2,2},
   {1,3,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki91229[] = {
   {0,0,1},
   {-2,-2,1},
   {-1,-1,1},
   {-2,2,2},
   {-2,-1,2},
   {-3,-2,2},
   {2,-2,2}};

static struct patval fuseki91230[] = {
   {2,-1,1},
   {1,2,1},
   {1,-2,1},
   {0,0,2},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki91231[] = {
   {-2,-2,1},
   {0,-1,1},
   {-2,2,2},
   {-2,0,2},
   {2,-2,2}};

static struct patval fuseki91232[] = {
   {0,0,1},
   {-3,1,1},
   {-2,0,1},
   {-2,-2,2},
   {-2,2,2},
   {-3,0,2},
   {2,-2,2},
   {2,0,2},
   {2,2,2}};

static struct patval fuseki91233[] = {
   {1,2,1},
   {-2,-1,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91234[] = {
   {-2,-2,1},
   {2,2,1},
   {-2,2,1},
   {2,-2,1},
   {0,0,1},
   {0,1,1},
   {-1,1,2},
   {-2,0,2}};

static struct patval fuseki91235[] = {
   {-2,2,1},
   {-1,-2,1},
   {2,1,1},
   {2,-2,1},
   {0,0,2},
   {0,-2,2}};

static struct patval fuseki91236[] = {
   {-3,1,1},
   {-2,0,1},
   {2,-2,1},
   {-2,2,1},
   {-1,1,2},
   {-2,1,2}};

static struct patval fuseki91237[] = {
   {-2,-2,1},
   {-2,2,1},
   {3,1,1},
   {2,-2,1},
   {2,1,1},
   {2,2,2},
   {1,-2,2}};

static struct patval fuseki91238[] = {
   {-2,0,1},
   {-2,2,1},
   {3,0,1},
   {2,-2,1},
   {2,1,2},
   {-1,-2,2}};

static struct patval fuseki91239[] = {
   {2,1,1},
   {0,1,1},
   {0,0,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91240[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {0,2,2},
   {-2,-1,2}};

static struct patval fuseki91241[] = {
   {-2,2,1},
   {-1,1,1},
   {2,0,1},
   {2,-2,1},
   {0,0,2},
   {-1,2,2}};

static struct patval fuseki91242[] = {
   {1,2,1},
   {2,2,1},
   {0,-2,1},
   {0,3,2},
   {-2,-2,2},
   {1,3,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91243[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {0,0,1},
   {2,2,1},
   {2,-2,1},
   {0,2,2}};

static struct patval fuseki91244[] = {
   {0,0,1},
   {0,-2,1},
   {-1,-1,1},
   {-1,-2,2},
   {-2,2,2},
   {2,-2,2},
   {2,1,2}};

static struct patval fuseki91245[] = {
   {-2,2,1},
   {2,2,1},
   {1,1,1},
   {2,-2,1},
   {2,0,2},
   {0,0,2}};

static struct patval fuseki91246[] = {
   {0,-3,1},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91247[] = {
   {-2,-2,1},
   {2,2,1},
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {1,1,1},
   {1,3,1},
   {0,2,2},
   {-2,1,2}};

static struct patval fuseki91248[] = {
   {2,2,1},
   {1,-2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-2,2},
   {3,1,2}};

static struct patval fuseki91249[] = {
   {-2,2,1},
   {-1,-1,1},
   {0,-2,1},
   {2,-2,1},
   {0,2,2},
   {0,0,2}};

static struct patval fuseki91250[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,2,1},
   {0,3,1},
   {1,2,1},
   {2,-2,1},
   {1,3,2},
   {0,2,2}};

static struct patval fuseki91251[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {0,2,1},
   {0,1,2},
   {-2,0,2}};

static struct patval fuseki91252[] = {
   {-2,-2,1},
   {2,2,1},
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {-2,0,2}};

static struct patval fuseki91253[] = {
   {-2,-2,1},
   {2,-2,1},
   {-2,2,1},
   {-1,1,1},
   {-2,1,2}};

static struct patval fuseki91254[] = {
   {-2,0,1},
   {-2,2,1},
   {3,-1,1},
   {2,-2,1},
   {2,-1,2},
   {0,0,2}};

static struct patval fuseki91255[] = {
   {-2,0,1},
   {1,0,1},
   {-1,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91256[] = {
   {-3,-2,1},
   {0,2,1},
   {-2,-1,1},
   {-2,2,2},
   {0,-2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91257[] = {
   {2,0,1},
   {0,-2,1},
   {-2,2,2},
   {2,-2,2},
   {-2,-1,2}};

static struct patval fuseki91258[] = {
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {-1,1,2}};

static struct patval fuseki91259[] = {
   {1,-1,1},
   {2,0,1},
   {0,-2,1},
   {0,-1,2},
   {-2,-1,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91260[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,-1,1},
   {0,0,1},
   {2,2,1},
   {1,1,1},
   {2,-2,1},
   {2,0,2},
   {1,-1,2}};

static struct patval fuseki91261[] = {
   {0,0,1},
   {-3,1,1},
   {-2,0,1},
   {-2,-2,2},
   {-2,2,2},
   {0,-2,2},
   {-3,0,2},
   {2,-2,2}};

static struct patval fuseki91262[] = {
   {-2,-2,1},
   {-2,-1,1},
   {-1,-2,1},
   {-2,2,2},
   {-1,-1,2},
   {-1,0,2},
   {2,-2,2}};

static struct patval fuseki91263[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,1,1},
   {2,-2,1},
   {0,2,2},
   {-1,-2,2}};

static struct patval fuseki91264[] = {
   {2,2,1},
   {1,1,1},
   {1,-2,1},
   {-2,2,2},
   {2,-2,2},
   {2,1,2},
   {-2,-2,2},
   {3,1,2}};

static struct patval fuseki91265[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {2,-2,1},
   {1,-2,2}};

static struct patval fuseki91266[] = {
   {-2,-2,1},
   {2,2,1},
   {-2,2,1},
   {-1,1,1},
   {0,0,1},
   {2,-2,1},
   {1,1,1},
   {0,2,2},
   {-2,1,2}};

static struct patval fuseki91267[] = {
   {2,0,1},
   {-1,-2,1},
   {-1,0,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91268[] = {
   {-2,-2,1},
   {2,2,1},
   {-2,2,1},
   {0,-2,1},
   {2,0,1},
   {2,-2,1},
   {0,2,2},
   {-2,1,2}};

static struct patval fuseki91269[] = {
   {-2,-2,1},
   {2,1,1},
   {0,1,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91270[] = {
   {2,2,1},
   {2,0,1},
   {2,-2,2},
   {1,1,2},
   {-2,2,2}};

static struct patval fuseki91271[] = {
   {1,-3,1},
   {-1,-1,1},
   {-2,2,2},
   {1,2,2},
   {2,-2,2}};

static struct patval fuseki91272[] = {
   {1,1,1},
   {1,-1,1},
   {2,0,1},
   {-2,2,2},
   {2,-2,2},
   {2,-1,2},
   {1,0,2}};

static struct patval fuseki91273[] = {
   {-2,-2,1},
   {-2,-1,1},
   {2,1,1},
   {-1,-2,2},
   {-1,0,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91274[] = {
   {-2,2,1},
   {3,1,1},
   {2,-1,1},
   {2,-2,1},
   {1,0,2},
   {1,-1,2}};

static struct patval fuseki91275[] = {
   {-2,-2,1},
   {0,-2,1},
   {-2,2,2},
   {0,0,2},
   {2,-2,2}};

static struct patval fuseki91276[] = {
   {2,-1,1},
   {1,-2,1},
   {0,0,1},
   {-2,2,2},
   {2,-2,2},
   {-2,0,2},
   {3,-1,2}};

static struct patval fuseki91277[] = {
   {-2,-1,1},
   {-2,2,1},
   {2,-2,1},
   {0,-1,1},
   {0,-2,2},
   {2,0,2}};

static struct patval fuseki91278[] = {
   {-1,1,1},
   {-2,0,1},
   {-2,2,2},
   {-2,-2,2},
   {0,0,2},
   {2,-2,2},
   {2,2,2}};

static struct patval fuseki91279[] = {
   {-2,2,1},
   {-1,1,1},
   {0,0,1},
   {2,-2,1},
   {0,1,2},
   {2,1,2}};

static struct patval fuseki91280[] = {
   {-2,-2,1},
   {2,2,1},
   {0,-2,1},
   {-2,2,2},
   {1,0,2},
   {2,-2,2},
   {-2,0,2}};

static struct patval fuseki91281[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,0,1},
   {1,-1,1},
   {1,0,1},
   {2,2,1},
   {2,-2,1},
   {2,0,2},
   {1,1,2}};

static struct patval fuseki91282[] = {
   {-3,0,1},
   {-2,-2,1},
   {2,0,1},
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {-2,0,2},
   {0,0,2}};

static struct patval fuseki91283[] = {
   {2,0,1},
   {-2,2,1},
   {0,2,1},
   {2,-2,1},
   {-2,-2,2},
   {2,2,2}};

static struct patval fuseki91284[] = {
   {0,0,1},
   {-1,-1,1},
   {-2,2,2},
   {-2,0,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91285[] = {
   {2,0,1},
   {-1,-1,1},
   {0,-3,1},
   {1,2,2},
   {2,-2,2},
   {-2,2,2},
   {3,-1,2}};

static struct patval fuseki91286[] = {
   {1,2,1},
   {1,-2,1},
   {0,0,2},
   {-2,2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91287[] = {
   {2,1,1},
   {3,-1,1},
   {0,2,1},
   {-1,0,2},
   {2,-2,2},
   {-2,2,2},
   {-1,-2,2}};

static struct patval fuseki91288[] = {
   {0,0,1},
   {-1,-1,1},
   {-1,-2,1},
   {-2,2,2},
   {0,-2,2},
   {-2,0,2},
   {2,-2,2}};

static struct patval fuseki91289[] = {
   {-2,-2,1},
   {-2,0,1},
   {-2,2,1},
   {2,-2,1},
   {0,1,2}};

static struct patval fuseki91290[] = {
   {0,2,1},
   {2,1,1},
   {0,1,1},
   {0,0,2},
   {-2,2,2},
   {2,-2,2},
   {-1,1,2}};

static struct patval fuseki91291[] = {
   {0,2,1},
   {2,0,1},
   {0,0,1},
   {0,-2,2},
   {-2,2,2},
   {2,-2,2},
   {-1,-1,2}};

static struct patval fuseki91292[] = {
   {2,0,1},
   {-2,2,1},
   {2,2,1},
   {2,-2,1},
   {-2,-2,2},
   {0,0,2}};

static struct patval fuseki91293[] = {
   {-1,2,1},
   {-1,1,1},
   {-2,1,1},
   {-2,2,2},
   {-2,0,2},
   {-3,1,2},
   {2,-2,2}};

static struct patval fuseki91294[] = {
   {-2,-2,1},
   {-2,0,1},
   {-2,2,1},
   {0,-2,1},
   {0,0,1},
   {0,2,1},
   {2,-2,1},
   {2,0,1},
   {2,2,1}};

static struct patval fuseki91295[] = {
   {-3,1,1},
   {-2,0,1},
   {2,-2,1},
   {-2,2,1},
   {-1,2,2},
   {-2,1,2}};

static struct patval fuseki91296[] = {
   {-2,0,1},
   {0,2,1},
   {0,0,1},
   {-1,-2,2},
   {-2,2,2},
   {2,-2,2},
   {2,1,2}};

static struct patval fuseki91297[] = {
   {-2,-2,1},
   {-2,2,1},
   {0,-2,1},
   {0,0,1},
   {2,-2,1},
   {1,2,2},
   {1,-2,2}};

static struct patval fuseki91298[] = {
   {-2,0,1},
   {2,2,1},
   {-1,1,1},
   {-1,0,2},
   {-1,-2,2},
   {2,-2,2},
   {-2,2,2}};

static struct patval fuseki91299[] = {
   {0,1,1},
   {-2,0,1},
   {-2,2,2},
   {0,-2,2},
   {-2,-2,2},
   {2,-2,2}};

static struct patval fuseki91300[] = {
   {-2,0,1},
   {1,0,1},
   {-1,1,1},
   {-1,0,2},
   {-1,-2,2},
   {-2,2,2},
   {2,-2,2}};

static struct patval fuseki91301[] = {
   {-2,2,1},
   {2,-2,1},
   {1,0,1},
   {0,0,2}};

static struct patval fuseki91302[] = {
   {-1,2,1},
   {-2,0,1},
   {-1,1,1},
   {-2,2,2},
   {-2,-2,2},
   {0,0,2},
   {0,1,2},
   {2,-2,2},
   {2,2,2}};


void
init_tree_fuseki9(void)
{
  /* nothing to do - tree option not compiled */
}

struct fullboard_pattern fuseki9[] = {
  {fuseki90,0,"Fuseki1", 0, 0,504.000000},
  {fuseki91,0,"Fuseki2",-2,-2,461.000000},
  {fuseki92,0,"Fuseki3", 1, 2,363.000000},
  {fuseki93,0,"Fuseki4",-1, 1,202.000000},
  {fuseki94,0,"Fuseki5", 0, 1,33.000000},
  {fuseki95,0,"Fuseki6", 2, 0,16.000000},
  {fuseki96,1,"Fuseki8", 1,-2,173.000000},
  {fuseki97,1,"Fuseki9",-2, 2,144.000000},
  {fuseki98,1,"Fuseki10", 0, 2,80.000000},
  {fuseki99,1,"Fuseki11",-1,-1,52.000000},
  {fuseki910,1,"Fuseki12",-1, 0,39.000000},
  {fuseki911,1,"Fuseki13",-2, 2,96.000000},
  {fuseki912,1,"Fuseki14", 2, 1,79.000000},
  {fuseki913,1,"Fuseki15",-2,-2,56.000000},
  {fuseki914,1,"Fuseki16",-2, 1,44.000000},
  {fuseki915,1,"Fuseki17",-1, 1,44.000000},
  {fuseki916,1,"Fuseki18", 0, 0,42.000000},
  {fuseki917,1,"Fuseki19", 1,-1,35.000000},
  {fuseki918,1,"Fuseki20", 2,-1,14.000000},
  {fuseki919,1,"Fuseki21", 1, 1,10.000000},
  {fuseki920,1,"Fuseki22",-1,-2,72.000000},
  {fuseki921,1,"Fuseki23", 0, 0,42.000000},
  {fuseki922,1,"Fuseki24", 1, 1,41.000000},
  {fuseki923,1,"Fuseki25",-1,-1,27.000000},
  {fuseki924,1,"Fuseki26",-1, 0,23.000000},
  {fuseki925,1,"Fuseki27", 2,-2,23.000000},
  {fuseki926,1,"Fuseki28", 2, 2,22.000000},
  {fuseki927,1,"Fuseki29", 2,-1,19.000000},
  {fuseki928,1,"Fuseki30", 0,-2,17.000000},
  {fuseki929,1,"Fuseki31",-1, 2,13.000000},
  {fuseki930,1,"Fuseki32", 1,-1,10.000000},
  {fuseki931,1,"Fuseki33", 0, 1,8.000000},
  {fuseki932,1,"Fuseki34", 2,-2,37.000000},
  {fuseki933,1,"Fuseki35",-1,-1,32.000000},
  {fuseki934,1,"Fuseki36",-1, 2,32.000000},
  {fuseki935,1,"Fuseki37",-1, 2,26.000000},
  {fuseki936,1,"Fuseki38", 0, 0,17.000000},
  {fuseki937,1,"Fuseki39", 1,-1,14.000000},
  {fuseki938,1,"Fuseki40",-2,-2,14.000000},
  {fuseki939,1,"Fuseki41", 1, 0,12.000000},
  {fuseki940,1,"Fuseki42", 2, 2,5.000000},
  {fuseki941,1,"Fuseki43",-1,-2,4.000000},
  {fuseki942,2,"Fuseki44",-1,-2,35.000000},
  {fuseki943,2,"Fuseki45", 0, 2,27.000000},
  {fuseki944,2,"Fuseki46", 1, 2,24.000000},
  {fuseki945,2,"Fuseki47", 2, 0,18.000000},
  {fuseki946,2,"Fuseki48", 1,-1,13.000000},
  {fuseki947,2,"Fuseki49",-1,-2,11.000000},
  {fuseki948,2,"Fuseki50",-2, 2,9.000000},
  {fuseki949,2,"Fuseki51", 2, 2,6.000000},
  {fuseki950,2,"Fuseki52",-1,-2,5.000000},
  {fuseki951,2,"Fuseki53",-2,-1,4.000000},
  {fuseki952,2,"Fuseki54", 0, 2,51.000000},
  {fuseki953,2,"Fuseki55", 2,-1,29.000000},
  {fuseki954,2,"Fuseki56",-1, 2,23.000000},
  {fuseki955,2,"Fuseki57", 2,-2,16.000000},
  {fuseki956,2,"Fuseki58",-2,-2,7.000000},
  {fuseki957,2,"Fuseki59", 2, 2,47.000000},
  {fuseki958,2,"Fuseki60",-1,-2,21.000000},
  {fuseki959,2,"Fuseki61",-1, 2,6.000000},
  {fuseki960,2,"Fuseki62", 0,-2,20.000000},
  {fuseki961,2,"Fuseki63", 2,-1,12.000000},
  {fuseki962,2,"Fuseki64", 2, 0,12.000000},
  {fuseki963,2,"Fuseki65",-2,-1,9.000000},
  {fuseki964,2,"Fuseki66",-1,-1,7.000000},
  {fuseki965,2,"Fuseki67", 2,-2,6.000000},
  {fuseki966,2,"Fuseki68",-2, 2,5.000000},
  {fuseki967,2,"Fuseki69", 2, 1,4.000000},
  {fuseki968,2,"Fuseki70", 0, 1,3.000000},
  {fuseki969,2,"Fuseki71",-1,-2,23.000000},
  {fuseki970,2,"Fuseki72", 2, 2,10.000000},
  {fuseki971,2,"Fuseki73",-1, 2,10.000000},
  {fuseki972,2,"Fuseki74",-1,-2,7.000000},
  {fuseki973,2,"Fuseki75", 1, 1,6.000000},
  {fuseki974,2,"Fuseki76", 2, 2,5.000000},
  {fuseki975,2,"Fuseki77",-2,-2,5.000000},
  {fuseki976,2,"Fuseki78", 0, 0,3.000000},
  {fuseki977,2,"Fuseki79", 0, 2,3.000000},
  {fuseki978,2,"Fuseki80", 1, 2,26.000000},
  {fuseki979,2,"Fuseki81",-2,-1,10.000000},
  {fuseki980,2,"Fuseki82",-2, 1,7.000000},
  {fuseki981,2,"Fuseki83", 1,-1,6.000000},
  {fuseki982,2,"Fuseki84",-2, 0,4.000000},
  {fuseki983,2,"Fuseki85", 2,-2,4.000000},
  {fuseki984,2,"Fuseki86", 1, 0,4.000000},
  {fuseki985,2,"Fuseki87",-2, 2,4.000000},
  {fuseki986,2,"Fuseki88", 0, 2,3.000000},
  {fuseki987,3,"Fuseki89", 2,-2,41.000000},
  {fuseki988,3,"Fuseki90", 2, 1,13.000000},
  {fuseki989,2,"Fuseki91", 2, 2,23.000000},
  {fuseki990,2,"Fuseki92", 2,-2,12.000000},
  {fuseki991,2,"Fuseki93", 1,-2,5.000000},
  {fuseki992,2,"Fuseki94", 0, 0,4.000000},
  {fuseki993,2,"Fuseki95", 0,-1,31.000000},
  {fuseki994,2,"Fuseki96", 1, 2,7.000000},
  {fuseki995,2,"Fuseki97", 2, 2,4.000000},
  {fuseki996,3,"Fuseki98", 1,-2,20.000000},
  {fuseki997,3,"Fuseki99", 0,-2,9.000000},
  {fuseki998,3,"Fuseki100", 2,-2,7.000000},
  {fuseki999,3,"Fuseki101",-2, 2,4.000000},
  {fuseki9100,3,"Fuseki102",-2, 0,2.000000},
  {fuseki9101,3,"Fuseki103", 1, 1,2.000000},
  {fuseki9102,3,"Fuseki104",-1,-1,2.000000},
  {fuseki9103,2,"Fuseki105",-1,-2,11.000000},
  {fuseki9104,2,"Fuseki106",-2,-2,8.000000},
  {fuseki9105,2,"Fuseki107",-1,-1,8.000000},
  {fuseki9106,2,"Fuseki108", 2, 2,5.000000},
  {fuseki9107,2,"Fuseki109", 2,-1,5.000000},
  {fuseki9108,2,"Fuseki110", 0, 0,2.000000},
  {fuseki9109,2,"Fuseki112", 2,-1,10.000000},
  {fuseki9110,2,"Fuseki113",-2,-2,7.000000},
  {fuseki9111,2,"Fuseki114",-2,-2,6.000000},
  {fuseki9112,2,"Fuseki115",-2,-1,5.000000},
  {fuseki9113,2,"Fuseki116",-1,-1,4.000000},
  {fuseki9114,2,"Fuseki117", 3,-1,2.000000},
  {fuseki9115,2,"Fuseki118", 1,-1,2.000000},
  {fuseki9116,2,"Fuseki119", 0, 2,10.000000},
  {fuseki9117,2,"Fuseki120",-1, 1,8.000000},
  {fuseki9118,2,"Fuseki121",-1, 2,5.000000},
  {fuseki9119,2,"Fuseki122",-2, 1,3.000000},
  {fuseki9120,2,"Fuseki123", 2,-2,2.000000},
  {fuseki9121,2,"Fuseki124",-2,-2,2.000000},
  {fuseki9122,2,"Fuseki125", 1, 0,2.000000},
  {fuseki9123,2,"Fuseki126", 1, 2,2.000000},
  {fuseki9124,2,"Fuseki127",-1,-2,2.000000},
  {fuseki9125,2,"Fuseki128", 0,-1,2.000000},
  {fuseki9126,2,"Fuseki129",-2, 2,20.000000},
  {fuseki9127,2,"Fuseki130", 1,-1,5.000000},
  {fuseki9128,2,"Fuseki131", 2,-2,5.000000},
  {fuseki9129,2,"Fuseki132",-2,-1,4.000000},
  {fuseki9130,2,"Fuseki133", 1, 2,3.000000},
  {fuseki9131,2,"Fuseki134", 0,-2,2.000000},
  {fuseki9132,2,"Fuseki135", 0,-1,2.000000},
  {fuseki9133,2,"Fuseki136", 1, 2,13.000000},
  {fuseki9134,2,"Fuseki137",-1, 2,6.000000},
  {fuseki9135,2,"Fuseki138",-2,-2,4.000000},
  {fuseki9136,2,"Fuseki139", 1, 1,3.000000},
  {fuseki9137,2,"Fuseki140",-2, 2,3.000000},
  {fuseki9138,2,"Fuseki141", 0,-2,2.000000},
  {fuseki9139,2,"Fuseki142", 1,-2,2.000000},
  {fuseki9140,2,"Fuseki143", 1,-1,2.000000},
  {fuseki9141,2,"Fuseki144", 1, 0,2.000000},
  {fuseki9142,4,"Fuseki145",-2, 0,8.000000},
  {fuseki9143,4,"Fuseki146",-2, 1,5.000000},
  {fuseki9144,4,"Fuseki147", 1, 0,4.000000},
  {fuseki9145,4,"Fuseki148", 0, 0,4.000000},
  {fuseki9146,4,"Fuseki149", 3,-1,3.000000},
  {fuseki9147,4,"Fuseki150", 1,-1,3.000000},
  {fuseki9148,4,"Fuseki151",-1, 2,2.000000},
  {fuseki9149,4,"Fuseki152", 0,-2,2.000000},
  {fuseki9150,4,"Fuseki153", 1, 0,2.000000},
  {fuseki9151,4,"Fuseki154", 0, 3,2.000000},
  {fuseki9152,2,"Fuseki155", 1,-2,11.000000},
  {fuseki9153,2,"Fuseki156", 2, 0,6.000000},
  {fuseki9154,2,"Fuseki157",-1, 1,6.000000},
  {fuseki9155,2,"Fuseki158",-2,-2,4.000000},
  {fuseki9156,2,"Fuseki159",-1, 0,3.000000},
  {fuseki9157,2,"Fuseki160", 1, 1,3.000000},
  {fuseki9158,2,"Fuseki161", 2,-1,2.000000},
  {fuseki9159,3,"Fuseki162", 2, 0,19.000000},
  {fuseki9160,3,"Fuseki163",-2,-2,5.000000},
  {fuseki9161,3,"Fuseki164", 0, 1,2.000000},
  {fuseki9162,3,"Fuseki165",-1, 0,2.000000},
  {fuseki9163,3,"Fuseki166",-1, 2,2.000000},
  {fuseki9164,2,"Fuseki167",-1, 1,20.000000},
  {fuseki9165,2,"Fuseki168", 1, 0,11.000000},
  {fuseki9166,2,"Fuseki169",-2,-1,23.000000},
  {fuseki9167,2,"Fuseki170", 2,-2,4.000000},
  {fuseki9168,2,"Fuseki171", 2,-2,3.000000},
  {fuseki9169,1,"Fuseki172", 0,-1,9.000000},
  {fuseki9170,1,"Fuseki173",-1,-1,7.000000},
  {fuseki9171,1,"Fuseki174", 1, 2,3.000000},
  {fuseki9172,1,"Fuseki175", 2, 2,3.000000},
  {fuseki9173,1,"Fuseki176", 0, 1,3.000000},
  {fuseki9174,1,"Fuseki177", 0, 0,2.000000},
  {fuseki9175,2,"Fuseki178",-2,-1,7.000000},
  {fuseki9176,2,"Fuseki179",-1, 0,5.000000},
  {fuseki9177,2,"Fuseki180", 1,-2,3.000000},
  {fuseki9178,2,"Fuseki181", 2,-2,3.000000},
  {fuseki9179,2,"Fuseki182", 2, 0,3.000000},
  {fuseki9180,2,"Fuseki183", 1, 0,3.000000},
  {fuseki9181,2,"Fuseki184", 2,-2,3.000000},
  {fuseki9182,2,"Fuseki185", 1, 1,2.000000},
  {fuseki9183,2,"Fuseki186", 2,-1,8.000000},
  {fuseki9184,2,"Fuseki187", 1,-1,6.000000},
  {fuseki9185,2,"Fuseki188", 0, 0,4.000000},
  {fuseki9186,2,"Fuseki189", 0,-1,3.000000},
  {fuseki9187,2,"Fuseki190",-1,-2,3.000000},
  {fuseki9188,2,"Fuseki191",-1,-2,2.000000},
  {fuseki9189,2,"Fuseki192", 2,-2,2.000000},
  {fuseki9190,2,"Fuseki193", 0,-2,2.000000},
  {fuseki9191,3,"Fuseki194",-2, 1,11.000000},
  {fuseki9192,3,"Fuseki195",-1, 0,11.000000},
  {fuseki9193,3,"Fuseki196", 0, 2,4.000000},
  {fuseki9194,3,"Fuseki197",-1,-1,2.000000},
  {fuseki9195,3,"Fuseki198", 0, 2,2.000000},
  {fuseki9196,3,"Fuseki199", 3,-1,13.000000},
  {fuseki9197,3,"Fuseki200", 1,-2,6.000000},
  {fuseki9198,3,"Fuseki201",-1,-1,5.000000},
  {fuseki9199,3,"Fuseki202", 2, 2,3.000000},
  {fuseki9200,2,"Fuseki203",-2, 1,7.000000},
  {fuseki9201,2,"Fuseki204", 2, 1,6.000000},
  {fuseki9202,2,"Fuseki205",-1, 1,6.000000},
  {fuseki9203,2,"Fuseki206", 1,-2,4.000000},
  {fuseki9204,3,"Fuseki207",-1,-1,9.000000},
  {fuseki9205,3,"Fuseki208", 1,-2,4.000000},
  {fuseki9206,3,"Fuseki209", 2,-1,3.000000},
  {fuseki9207,3,"Fuseki210",-2,-2,3.000000},
  {fuseki9208,3,"Fuseki211",-2,-2,2.000000},
  {fuseki9209,3,"Fuseki212", 2,-1,8.000000},
  {fuseki9210,3,"Fuseki213",-1,-2,6.000000},
  {fuseki9211,3,"Fuseki214",-2, 2,4.000000},
  {fuseki9212,3,"Fuseki215", 0,-2,2.000000},
  {fuseki9213,3,"Fuseki216", 1,-1,2.000000},
  {fuseki9214,2,"Fuseki217", 1,-1,5.000000},
  {fuseki9215,2,"Fuseki218", 0, 2,4.000000},
  {fuseki9216,2,"Fuseki219", 1,-2,3.000000},
  {fuseki9217,2,"Fuseki220",-1,-2,3.000000},
  {fuseki9218,2,"Fuseki221",-2,-2,2.000000},
  {fuseki9219,2,"Fuseki222", 0, 2,2.000000},
  {fuseki9220,3,"Fuseki223",-1, 0,17.000000},
  {fuseki9221,3,"Fuseki224", 1, 1,4.000000},
  {fuseki9222,3,"Fuseki226", 1,-1,10.000000},
  {fuseki9223,3,"Fuseki227", 2, 2,6.000000},
  {fuseki9224,3,"Fuseki228", 2, 2,3.000000},
  {fuseki9225,3,"Fuseki229", 2,-1,2.000000},
  {fuseki9226,2,"Fuseki230", 2, 2,5.000000},
  {fuseki9227,2,"Fuseki231",-2,-1,4.000000},
  {fuseki9228,2,"Fuseki232",-1,-1,4.000000},
  {fuseki9229,2,"Fuseki233", 1, 2,2.000000},
  {fuseki9230,2,"Fuseki234",-1, 1,2.000000},
  {fuseki9231,2,"Fuseki235",-1,-2,8.000000},
  {fuseki9232,2,"Fuseki236", 2, 1,3.000000},
  {fuseki9233,2,"Fuseki237", 1, 1,3.000000},
  {fuseki9234,2,"Fuseki238", 1, 2,3.000000},
  {fuseki9235,2,"Fuseki239",-2,-2,3.000000},
  {fuseki9236,2,"Fuseki240",-2, 0,2.000000},
  {fuseki9237,3,"Fuseki241",-2,-1,10.000000},
  {fuseki9238,3,"Fuseki242", 2,-2,7.000000},
  {fuseki9239,3,"Fuseki243",-1, 0,2.000000},
  {fuseki9240,3,"Fuseki244",-1,-1,2.000000},
  {fuseki9241,3,"Fuseki245", 0,-2,2.000000},
  {fuseki9242,3,"Fuseki246",-1,-2,10.000000},
  {fuseki9243,3,"Fuseki247",-2,-2,8.000000},
  {fuseki9244,2,"Fuseki248", 0, 2,6.000000},
  {fuseki9245,2,"Fuseki249",-1,-2,5.000000},
  {fuseki9246,2,"Fuseki250", 1,-2,3.000000},
  {fuseki9247,2,"Fuseki251",-2,-2,2.000000},
  {fuseki9248,3,"Fuseki252", 0, 1,11.000000},
  {fuseki9249,3,"Fuseki253", 0, 1,7.000000},
  {fuseki9250,3,"Fuseki254",-2,-1,10.000000},
  {fuseki9251,3,"Fuseki255", 2, 2,3.000000},
  {fuseki9252,3,"Fuseki256",-2, 0,3.000000},
  {fuseki9253,3,"Fuseki257",-2, 1,10.000000},
  {fuseki9254,3,"Fuseki258", 0,-3,3.000000},
  {fuseki9255,3,"Fuseki259",-1,-1,2.000000},
  {fuseki9256,3,"Fuseki260", 2,-1,2.000000},
  {fuseki9257,4,"Fuseki261",-2, 0,6.000000},
  {fuseki9258,4,"Fuseki262", 2,-1,6.000000},
  {fuseki9259,4,"Fuseki263",-2, 1,3.000000},
  {fuseki9260,4,"Fuseki264", 0, 2,2.000000},
  {fuseki9261,4,"Fuseki265",-2,-1,4.000000},
  {fuseki9262,4,"Fuseki266",-2, 0,4.000000},
  {fuseki9263,4,"Fuseki267", 2, 1,3.000000},
  {fuseki9264,4,"Fuseki268",-2, 1,3.000000},
  {fuseki9265,4,"Fuseki269",-2,-2,2.000000},
  {fuseki9266,2,"Fuseki270", 2, 1,5.000000},
  {fuseki9267,2,"Fuseki271",-1,-2,4.000000},
  {fuseki9268,2,"Fuseki272", 1,-1,3.000000},
  {fuseki9269,2,"Fuseki273", 0,-2,2.000000},
  {fuseki9270,2,"Fuseki274", 1,-2,2.000000},
  {fuseki9271,3,"Fuseki275", 2, 0,14.000000},
  {fuseki9272,3,"Fuseki276", 0, 2,2.000000},
  {fuseki9273,3,"Fuseki277",-1,-2,17.000000},
  {fuseki9274,3,"Fuseki278", 0,-1,7.000000},
  {fuseki9275,3,"Fuseki279", 1,-1,5.000000},
  {fuseki9276,3,"Fuseki280", 0,-3,2.000000},
  {fuseki9277,3,"Fuseki281", 1, 2,7.000000},
  {fuseki9278,3,"Fuseki282", 0, 2,5.000000},
  {fuseki9279,3,"Fuseki283",-2, 1,2.000000},
  {fuseki9280,3,"Fuseki284", 3, 0,2.000000},
  {fuseki9281,4,"Fuseki285",-2, 2,8.000000},
  {fuseki9282,4,"Fuseki286",-1, 2,3.000000},
  {fuseki9283,4,"Fuseki287", 2, 0,3.000000},
  {fuseki9284,4,"Fuseki288",-1, 3,2.000000},
  {fuseki9285,4,"Fuseki289", 1,-2,2.000000},
  {fuseki9286,2,"Fuseki290", 2, 2,7.000000},
  {fuseki9287,2,"Fuseki291", 1, 2,7.000000},
  {fuseki9288,2,"Fuseki292",-2, 1,2.000000},
  {fuseki9289,4,"Fuseki293",-2,-2,7.000000},
  {fuseki9290,4,"Fuseki294",-2,-2,4.000000},
  {fuseki9291,4,"Fuseki295", 2, 0,2.000000},
  {fuseki9292,2,"Fuseki296", 0,-1,9.000000},
  {fuseki9293,2,"Fuseki297", 1,-1,4.000000},
  {fuseki9294,2,"Fuseki298",-1,-2,3.000000},
  {fuseki9295,1,"Fuseki299", 0, 0,5.000000},
  {fuseki9296,1,"Fuseki300", 1,-2,3.000000},
  {fuseki9297,1,"Fuseki301",-2, 2,2.000000},
  {fuseki9298,1,"Fuseki302", 2, 2,5.000000},
  {fuseki9299,1,"Fuseki303", 2,-2,5.000000},
  {fuseki9300,4,"Fuseki304", 2, 0,3.000000},
  {fuseki9301,4,"Fuseki305", 2, 0,3.000000},
  {fuseki9302,4,"Fuseki306", 1,-2,2.000000},
  {fuseki9303,4,"Fuseki307", 0,-2,2.000000},
  {fuseki9304,2,"Fuseki308",-3, 1,3.000000},
  {fuseki9305,2,"Fuseki309",-2, 1,2.000000},
  {fuseki9306,2,"Fuseki310", 0, 0,2.000000},
  {fuseki9307,2,"Fuseki311", 0, 2,2.000000},
  {fuseki9308,2,"Fuseki312",-2, 2,4.000000},
  {fuseki9309,2,"Fuseki313", 0, 0,3.000000},
  {fuseki9310,2,"Fuseki314",-1, 1,2.000000},
  {fuseki9311,2,"Fuseki315", 0,-1,2.000000},
  {fuseki9312,2,"Fuseki316",-2, 1,3.000000},
  {fuseki9313,2,"Fuseki317",-1, 1,2.000000},
  {fuseki9314,2,"Fuseki318", 0, 1,2.000000},
  {fuseki9315,2,"Fuseki319", 2, 1,4.000000},
  {fuseki9316,2,"Fuseki320",-2,-2,3.000000},
  {fuseki9317,2,"Fuseki321",-2,-1,2.000000},
  {fuseki9318,2,"Fuseki322", 1, 1,2.000000},
  {fuseki9319,3,"Fuseki323", 1,-2,6.000000},
  {fuseki9320,3,"Fuseki324", 0,-2,3.000000},
  {fuseki9321,3,"Fuseki325",-2, 2,2.000000},
  {fuseki9322,4,"Fuseki326", 0,-2,5.000000},
  {fuseki9323,4,"Fuseki327",-2, 2,2.000000},
  {fuseki9324,4,"Fuseki328", 0, 3,2.000000},
  {fuseki9325,4,"Fuseki329",-1, 1,2.000000},
  {fuseki9326,4,"Fuseki330",-1, 2,4.000000},
  {fuseki9327,4,"Fuseki331", 3, 0,4.000000},
  {fuseki9328,4,"Fuseki332", 2, 0,3.000000},
  {fuseki9329,3,"Fuseki333", 0,-2,5.000000},
  {fuseki9330,3,"Fuseki334",-2,-1,4.000000},
  {fuseki9331,3,"Fuseki335", 1, 0,2.000000},
  {fuseki9332,3,"Fuseki336",-2,-2,4.000000},
  {fuseki9333,3,"Fuseki337",-2,-1,4.000000},
  {fuseki9334,3,"Fuseki338",-2, 0,2.000000},
  {fuseki9335,4,"Fuseki339", 1, 2,4.000000},
  {fuseki9336,4,"Fuseki340", 1,-3,2.000000},
  {fuseki9337,4,"Fuseki341", 0, 2,2.000000},
  {fuseki9338,4,"Fuseki342", 2, 2,3.000000},
  {fuseki9339,4,"Fuseki343",-1, 0,3.000000},
  {fuseki9340,3,"Fuseki344", 2, 0,3.000000},
  {fuseki9341,3,"Fuseki345", 2, 1,2.000000},
  {fuseki9342,3,"Fuseki346",-1,-1,2.000000},
  {fuseki9343,3,"Fuseki347", 2, 2,2.000000},
  {fuseki9344,3,"Fuseki348",-2, 0,6.000000},
  {fuseki9345,3,"Fuseki349", 2,-1,2.000000},
  {fuseki9346,3,"Fuseki350", 2, 2,10.000000},
  {fuseki9347,3,"Fuseki351", 2,-1,2.000000},
  {fuseki9348,3,"Fuseki352",-1, 2,2.000000},
  {fuseki9349,3,"Fuseki353",-2, 2,2.000000},
  {fuseki9350,3,"Fuseki354", 2, 1,2.000000},
  {fuseki9351,3,"Fuseki355",-2,-1,2.000000},
  {fuseki9352,3,"Fuseki356", 2, 1,6.000000},
  {fuseki9353,3,"Fuseki357", 1, 0,3.000000},
  {fuseki9354,2,"Fuseki358",-1,-2,4.000000},
  {fuseki9355,2,"Fuseki359",-1,-1,4.000000},
  {fuseki9356,3,"Fuseki360", 0, 1,6.000000},
  {fuseki9357,3,"Fuseki361",-1, 1,2.000000},
  {fuseki9358,3,"Fuseki362",-2, 1,6.000000},
  {fuseki9359,3,"Fuseki363", 2, 0,2.000000},
  {fuseki9360,4,"Fuseki364",-1, 1,5.000000},
  {fuseki9361,4,"Fuseki365", 0,-1,2.000000},
  {fuseki9362,4,"Fuseki366", 0, 2,2.000000},
  {fuseki9363,3,"Fuseki367", 2,-2,3.000000},
  {fuseki9364,3,"Fuseki368", 2, 1,2.000000},
  {fuseki9365,3,"Fuseki369", 0, 1,2.000000},
  {fuseki9366,4,"Fuseki370", 1, 0,5.000000},
  {fuseki9367,4,"Fuseki371",-2, 1,4.000000},
  {fuseki9368,4,"Fuseki372",-2, 0,2.000000},
  {fuseki9369,4,"Fuseki373", 0,-1,7.000000},
  {fuseki9370,4,"Fuseki374",-2, 0,2.000000},
  {fuseki9371,3,"Fuseki375", 1, 2,5.000000},
  {fuseki9372,3,"Fuseki376", 2,-1,4.000000},
  {fuseki9373,3,"Fuseki377", 2, 2,2.000000},
  {fuseki9374,3,"Fuseki378", 0, 1,5.000000},
  {fuseki9375,3,"Fuseki379", 1, 2,3.000000},
  {fuseki9376,4,"Fuseki380",-2, 2,4.000000},
  {fuseki9377,4,"Fuseki381", 1, 2,3.000000},
  {fuseki9378,2,"Fuseki382",-1, 2,7.000000},
  {fuseki9379,2,"Fuseki383",-2, 2,2.000000},
  {fuseki9380,3,"Fuseki384", 2, 1,6.000000},
  {fuseki9381,3,"Fuseki385",-1, 2,2.000000},
  {fuseki9382,4,"Fuseki386",-2, 0,3.000000},
  {fuseki9383,4,"Fuseki387", 0,-1,2.000000},
  {fuseki9384,3,"Fuseki388", 2,-2,3.000000},
  {fuseki9385,3,"Fuseki389", 2, 1,3.000000},
  {fuseki9386,3,"Fuseki390",-1,-2,2.000000},
  {fuseki9387,2,"Fuseki391", 1, 1,3.000000},
  {fuseki9388,2,"Fuseki392",-2, 2,2.000000},
  {fuseki9389,3,"Fuseki393",-2,-1,8.000000},
  {fuseki9390,4,"Fuseki394",-2, 0,3.000000},
  {fuseki9391,4,"Fuseki395", 2, 2,2.000000},
  {fuseki9392,4,"Fuseki396",-1,-1,2.000000},
  {fuseki9393,4,"Fuseki397",-2,-2,4.000000},
  {fuseki9394,4,"Fuseki398", 1, 0,4.000000},
  {fuseki9395,4,"Fuseki399",-2, 1,4.000000},
  {fuseki9396,4,"Fuseki400", 2, 1,2.000000},
  {fuseki9397,4,"Fuseki401",-1, 2,2.000000},
  {fuseki9398,4,"Fuseki402",-1,-3,4.000000},
  {fuseki9399,4,"Fuseki403",-2,-1,2.000000},
  {fuseki9400,4,"Fuseki404", 2, 0,2.000000},
  {fuseki9401,4,"Fuseki405", 0,-1,2.000000},
  {fuseki9402,4,"Fuseki406", 1,-1,2.000000},
  {fuseki9403,3,"Fuseki407", 0,-2,4.000000},
  {fuseki9404,3,"Fuseki408", 2,-1,2.000000},
  {fuseki9405,3,"Fuseki409", 2,-1,5.000000},
  {fuseki9406,3,"Fuseki410", 0, 2,3.000000},
  {fuseki9407,3,"Fuseki411",-2,-1,5.000000},
  {fuseki9408,4,"Fuseki414", 0,-1,3.000000},
  {fuseki9409,4,"Fuseki415", 2,-1,2.000000},
  {fuseki9410,3,"Fuseki416",-1, 3,3.000000},
  {fuseki9411,3,"Fuseki417", 1,-1,2.000000},
  {fuseki9412,4,"Fuseki418", 2, 1,3.000000},
  {fuseki9413,4,"Fuseki419",-2,-2,3.000000},
  {fuseki9414,4,"Fuseki420",-2, 0,2.000000},
  {fuseki9415,3,"Fuseki421", 0,-1,3.000000},
  {fuseki9416,3,"Fuseki422",-1, 0,2.000000},
  {fuseki9417,4,"Fuseki423", 3, 1,2.000000},
  {fuseki9418,2,"Fuseki424",-1,-1,5.000000},
  {fuseki9419,2,"Fuseki425", 1, 0,2.000000},
  {fuseki9420,4,"Fuseki426",-1, 2,5.000000},
  {fuseki9421,4,"Fuseki427", 3, 1,2.000000},
  {fuseki9422,3,"Fuseki428", 0,-2,3.000000},
  {fuseki9423,3,"Fuseki429",-2, 1,5.000000},
  {fuseki9424,3,"Fuseki430",-1, 1,2.000000},
  {fuseki9425,4,"Fuseki431", 1,-2,3.000000},
  {fuseki9426,4,"Fuseki432", 0,-2,2.000000},
  {fuseki9427,4,"Fuseki433", 0, 2,2.000000},
  {fuseki9428,3,"Fuseki434",-1,-2,3.000000},
  {fuseki9429,3,"Fuseki435",-2, 0,2.000000},
  {fuseki9430,3,"Fuseki436", 2, 2,2.000000},
  {fuseki9431,3,"Fuseki437", 2,-1,3.000000},
  {fuseki9432,3,"Fuseki438",-2,-2,2.000000},
  {fuseki9433,2,"Fuseki439",-2,-1,4.000000},
  {fuseki9434,4,"Fuseki440", 2,-2,2.000000},
  {fuseki9435,4,"Fuseki441", 0,-2,2.000000},
  {fuseki9436,4,"Fuseki442", 0,-2,2.000000},
  {fuseki9437,5,"Fuseki443",-2, 0,2.000000},
  {fuseki9438,5,"Fuseki444",-1,-2,2.000000},
  {fuseki9439,5,"Fuseki445", 1,-1,2.000000},
  {fuseki9440,5,"Fuseki446",-1, 2,2.000000},
  {fuseki9441,3,"Fuseki447",-1, 2,3.000000},
  {fuseki9442,3,"Fuseki448",-1,-1,2.000000},
  {fuseki9443,3,"Fuseki449", 1, 2,2.000000},
  {fuseki9444,5,"Fuseki450", 2, 0,5.000000},
  {fuseki9445,3,"Fuseki451",-1,-1,3.000000},
  {fuseki9446,3,"Fuseki452", 2, 2,2.000000},
  {fuseki9447,4,"Fuseki453",-2,-2,3.000000},
  {fuseki9448,4,"Fuseki454",-2,-1,3.000000},
  {fuseki9449,4,"Fuseki455", 2, 0,2.000000},
  {fuseki9450,4,"Fuseki456",-1,-1,2.000000},
  {fuseki9451,4,"Fuseki457", 3,-2,2.000000},
  {fuseki9452,2,"Fuseki458", 1, 0,2.000000},
  {fuseki9453,3,"Fuseki459",-2,-2,2.000000},
  {fuseki9454,3,"Fuseki460", 1, 2,2.000000},
  {fuseki9455,3,"Fuseki461", 1,-2,2.000000},
  {fuseki9456,3,"Fuseki462",-1,-2,3.000000},
  {fuseki9457,3,"Fuseki463", 2,-2,3.000000},
  {fuseki9458,3,"Fuseki464",-1,-1,3.000000},
  {fuseki9459,3,"Fuseki465", 1,-1,2.000000},
  {fuseki9460,3,"Fuseki466",-1, 0,3.000000},
  {fuseki9461,3,"Fuseki467", 2,-2,2.000000},
  {fuseki9462,5,"Fuseki468", 0, 2,5.000000},
  {fuseki9463,5,"Fuseki469", 2, 0,2.000000},
  {fuseki9464,5,"Fuseki470", 2, 2,2.000000},
  {fuseki9465,5,"Fuseki471",-1, 1,2.000000},
  {fuseki9466,4,"Fuseki472",-1, 1,3.000000},
  {fuseki9467,4,"Fuseki473", 1, 1,2.000000},
  {fuseki9468,3,"Fuseki474",-2,-1,6.000000},
  {fuseki9469,3,"Fuseki475",-1, 2,3.000000},
  {fuseki9470,4,"Fuseki476", 2, 0,2.000000},
  {fuseki9471,5,"Fuseki477", 2,-1,2.000000},
  {fuseki9472,4,"Fuseki478", 0, 0,3.000000},
  {fuseki9473,4,"Fuseki479", 1, 0,2.000000},
  {fuseki9474,3,"Fuseki480", 1, 1,2.000000},
  {fuseki9475,3,"Fuseki481", 1, 2,5.000000},
  {fuseki9476,3,"Fuseki482", 1, 0,2.000000},
  {fuseki9477,3,"Fuseki483", 1, 1,2.000000},
  {fuseki9478,3,"Fuseki484", 1, 0,5.000000},
  {fuseki9479,4,"Fuseki485",-1,-1,5.000000},
  {fuseki9480,4,"Fuseki486",-1,-1,2.000000},
  {fuseki9481,2,"Fuseki487", 1,-1,3.000000},
  {fuseki9482,2,"Fuseki488", 2, 0,2.000000},
  {fuseki9483,3,"Fuseki489", 2, 1,2.000000},
  {fuseki9484,3,"Fuseki490",-2, 2,2.000000},
  {fuseki9485,3,"Fuseki491",-1, 0,3.000000},
  {fuseki9486,4,"Fuseki492",-2, 0,2.000000},
  {fuseki9487,4,"Fuseki493",-2, 2,2.000000},
  {fuseki9488,3,"Fuseki494", 1, 1,4.000000},
  {fuseki9489,5,"Fuseki495", 0, 3,5.000000},
  {fuseki9490,3,"Fuseki496", 1,-2,2.000000},
  {fuseki9491,3,"Fuseki497",-1,-1,2.000000},
  {fuseki9492,3,"Fuseki498", 2, 1,2.000000},
  {fuseki9493,5,"Fuseki499", 1,-3,2.000000},
  {fuseki9494,5,"Fuseki500", 0, 0,2.000000},
  {fuseki9495,2,"Fuseki501",-1,-2,2.000000},
  {fuseki9496,5,"Fuseki502",-1, 1,6.000000},
  {fuseki9497,4,"Fuseki503",-2, 0,5.000000},
  {fuseki9498,3,"Fuseki504",-2,-1,3.000000},
  {fuseki9499,3,"Fuseki505",-2, 1,4.000000},
  {fuseki9500,3,"Fuseki506", 2,-2,2.000000},
  {fuseki9501,5,"Fuseki507", 0, 1,4.000000},
  {fuseki9502,5,"Fuseki508",-1, 2,2.000000},
  {fuseki9503,3,"Fuseki509", 2, 2,4.000000},
  {fuseki9504,4,"Fuseki510",-1,-2,2.000000},
  {fuseki9505,3,"Fuseki511", 2,-1,3.000000},
  {fuseki9506,3,"Fuseki512",-1, 2,2.000000},
  {fuseki9507,5,"Fuseki513",-2, 2,3.000000},
  {fuseki9508,3,"Fuseki514",-2, 2,3.000000},
  {fuseki9509,3,"Fuseki515",-1,-2,2.000000},
  {fuseki9510,3,"Fuseki516", 2, 0,2.000000},
  {fuseki9511,5,"Fuseki517", 2,-2,4.000000},
  {fuseki9512,4,"Fuseki518", 3, 1,2.000000},
  {fuseki9513,4,"Fuseki519",-3, 0,2.000000},
  {fuseki9514,2,"Fuseki520", 0,-2,2.000000},
  {fuseki9515,4,"Fuseki521", 2, 0,3.000000},
  {fuseki9516,3,"Fuseki522",-2,-2,3.000000},
  {fuseki9517,3,"Fuseki523",-2,-2,2.000000},
  {fuseki9518,4,"Fuseki524", 0,-2,3.000000},
  {fuseki9519,3,"Fuseki525", 1, 2,5.000000},
  {fuseki9520,4,"Fuseki526", 1, 3,5.000000},
  {fuseki9521,3,"Fuseki527", 1,-2,3.000000},
  {fuseki9522,3,"Fuseki528", 1,-2,3.000000},
  {fuseki9523,3,"Fuseki529", 2, 2,2.000000},
  {fuseki9524,5,"Fuseki530",-2,-1,2.000000},
  {fuseki9525,5,"Fuseki531", 1,-1,5.000000},
  {fuseki9526,3,"Fuseki532", 0, 2,2.000000},
  {fuseki9527,3,"Fuseki533",-1, 2,2.000000},
  {fuseki9528,4,"Fuseki534", 2, 0,2.000000},
  {fuseki9529,5,"Fuseki535", 1, 1,4.000000},
  {fuseki9530,2,"Fuseki536",-2, 1,2.000000},
  {fuseki9531,2,"Fuseki537",-2, 2,2.000000},
  {fuseki9532,5,"Fuseki538",-2,-2,3.000000},
  {fuseki9533,3,"Fuseki539", 1,-2,2.000000},
  {fuseki9534,3,"Fuseki540", 2, 2,2.000000},
  {fuseki9535,3,"Fuseki541",-2, 2,2.000000},
  {fuseki9536,3,"Fuseki542",-2, 1,5.000000},
  {fuseki9537,4,"Fuseki543",-1, 2,5.000000},
  {fuseki9538,3,"Fuseki544", 1,-2,3.000000},
  {fuseki9539,3,"Fuseki545",-1,-1,3.000000},
  {fuseki9540,3,"Fuseki546", 0,-2,2.000000},
  {fuseki9541,3,"Fuseki547", 0, 2,2.000000},
  {fuseki9542,4,"Fuseki548", 0, 1,4.000000},
  {fuseki9543,4,"Fuseki550", 0, 1,2.000000},
  {fuseki9544,4,"Fuseki551", 1, 0,2.000000},
  {fuseki9545,5,"Fuseki552", 0, 2,5.000000},
  {fuseki9546,5,"Fuseki553", 1, 1,2.000000},
  {fuseki9547,4,"Fuseki554", 0, 2,3.000000},
  {fuseki9548,5,"Fuseki556", 0, 1,5.000000},
  {fuseki9549,3,"Fuseki557",-1, 2,2.000000},
  {fuseki9550,3,"Fuseki558",-1,-2,2.000000},
  {fuseki9551,5,"Fuseki559", 0, 2,3.000000},
  {fuseki9552,4,"Fuseki560",-2, 0,2.000000},
  {fuseki9553,3,"Fuseki562",-2, 0,2.000000},
  {fuseki9554,3,"Fuseki563", 0, 2,2.000000},
  {fuseki9555,4,"Fuseki564",-2, 2,2.000000},
  {fuseki9556,4,"Fuseki566", 1, 2,3.000000},
  {fuseki9557,3,"Fuseki567", 0,-1,2.000000},
  {fuseki9558,3,"Fuseki568", 2,-2,2.000000},
  {fuseki9559,4,"Fuseki569",-2, 0,2.000000},
  {fuseki9560,4,"Fuseki570", 2,-1,2.000000},
  {fuseki9561,3,"Fuseki572",-1,-2,2.000000},
  {fuseki9562,3,"Fuseki573",-1, 0,2.000000},
  {fuseki9563,4,"Fuseki574", 0, 2,4.000000},
  {fuseki9564,3,"Fuseki575",-2, 1,2.000000},
  {fuseki9565,4,"Fuseki576",-1, 0,3.000000},
  {fuseki9566,1,"Fuseki577",-2,-2,2.000000},
  {fuseki9567,4,"Fuseki578", 0, 2,4.000000},
  {fuseki9568,1,"Fuseki579", 3, 0,2.000000},
  {fuseki9569,3,"Fuseki580",-1,-2,2.000000},
  {fuseki9570,3,"Fuseki581",-2,-1,3.000000},
  {fuseki9571,3,"Fuseki582", 1, 2,3.000000},
  {fuseki9572,3,"Fuseki584", 1, 0,2.000000},
  {fuseki9573,2,"Fuseki585", 2, 1,4.000000},
  {fuseki9574,3,"Fuseki586",-2,-1,2.000000},
  {fuseki9575,5,"Fuseki587", 2, 1,2.000000},
  {fuseki9576,4,"Fuseki588",-2, 0,4.000000},
  {fuseki9577,3,"Fuseki589", 0,-2,3.000000},
  {fuseki9578,4,"Fuseki590",-2,-2,3.000000},
  {fuseki9579,5,"Fuseki591", 1, 2,2.000000},
  {fuseki9580,5,"Fuseki592",-2,-2,2.000000},
  {fuseki9581,5,"Fuseki593", 0, 1,2.000000},
  {fuseki9582,3,"Fuseki594", 1,-2,3.000000},
  {fuseki9583,3,"Fuseki595", 2, 0,3.000000},
  {fuseki9584,4,"Fuseki596",-2, 0,2.000000},
  {fuseki9585,5,"Fuseki597", 2, 0,2.000000},
  {fuseki9586,3,"Fuseki598",-2,-2,3.000000},
  {fuseki9587,3,"Fuseki599",-2,-1,2.000000},
  {fuseki9588,3,"Fuseki600",-2, 2,2.000000},
  {fuseki9589,5,"Fuseki601",-2, 2,2.000000},
  {fuseki9590,4,"Fuseki602",-1, 2,2.000000},
  {fuseki9591,4,"Fuseki603", 1, 0,2.000000},
  {fuseki9592,4,"Fuseki604",-1, 0,2.000000},
  {fuseki9593,4,"Fuseki605",-1, 2,2.000000},
  {fuseki9594,3,"Fuseki606", 1, 0,2.000000},
  {fuseki9595,5,"Fuseki607",-2, 3,2.000000},
  {fuseki9596,5,"Fuseki608", 1,-3,2.000000},
  {fuseki9597,4,"Fuseki609", 0, 0,3.000000},
  {fuseki9598,4,"Fuseki610", 2,-1,2.000000},
  {fuseki9599,4,"Fuseki611", 2, 2,2.000000},
  {fuseki9600,3,"Fuseki612",-2, 0,2.000000},
  {fuseki9601,3,"Fuseki613",-1, 0,2.000000},
  {fuseki9602,5,"Fuseki614",-1, 2,2.000000},
  {fuseki9603,3,"Fuseki615", 0,-1,3.000000},
  {fuseki9604,5,"Fuseki616", 0, 2,2.000000},
  {fuseki9605,3,"Fuseki617", 2,-1,2.000000},
  {fuseki9606,5,"Fuseki618",-2, 2,3.000000},
  {fuseki9607,4,"Fuseki619",-2,-1,2.000000},
  {fuseki9608,4,"Fuseki620", 0,-2,2.000000},
  {fuseki9609,5,"Fuseki621", 2, 0,4.000000},
  {fuseki9610,5,"Fuseki622",-1,-2,2.000000},
  {fuseki9611,3,"Fuseki623", 2, 2,2.000000},
  {fuseki9612,4,"Fuseki624", 2, 0,3.000000},
  {fuseki9613,5,"Fuseki625", 1, 2,2.000000},
  {fuseki9614,4,"Fuseki626", 0, 2,3.000000},
  {fuseki9615,4,"Fuseki627", 2,-2,2.000000},
  {fuseki9616,4,"Fuseki628",-1,-2,2.000000},
  {fuseki9617,3,"Fuseki629", 1, 1,3.000000},
  {fuseki9618,5,"Fuseki630",-1,-1,3.000000},
  {fuseki9619,3,"Fuseki631",-1, 2,4.000000},
  {fuseki9620,5,"Fuseki632",-1, 1,2.000000},
  {fuseki9621,3,"Fuseki633", 1, 2,4.000000},
  {fuseki9622,5,"Fuseki634", 2, 0,2.000000},
  {fuseki9623,5,"Fuseki635", 0,-2,2.000000},
  {fuseki9624,3,"Fuseki636", 2, 1,2.000000},
  {fuseki9625,4,"Fuseki637",-1,-2,2.000000},
  {fuseki9626,3,"Fuseki638", 0,-2,4.000000},
  {fuseki9627,4,"Fuseki639",-2, 1,2.000000},
  {fuseki9628,4,"Fuseki640", 2,-2,2.000000},
  {fuseki9629,3,"Fuseki641",-1, 2,2.000000},
  {fuseki9630,2,"Fuseki642",-2,-2,2.000000},
  {fuseki9631,4,"Fuseki643", 0, 2,4.000000},
  {fuseki9632,4,"Fuseki644",-1, 1,3.000000},
  {fuseki9633,4,"Fuseki645", 1,-2,2.000000},
  {fuseki9634,3,"Fuseki646",-2, 2,2.000000},
  {fuseki9635,5,"Fuseki647", 0, 1,2.000000},
  {fuseki9636,2,"Fuseki648",-1, 2,2.000000},
  {fuseki9637,3,"Fuseki649", 1,-2,2.000000},
  {fuseki9638,3,"Fuseki650", 1,-2,2.000000},
  {fuseki9639,5,"Fuseki651", 2, 2,2.000000},
  {fuseki9640,4,"Fuseki652",-2, 1,2.000000},
  {fuseki9641,4,"Fuseki653", 2, 1,2.000000},
  {fuseki9642,4,"Fuseki654",-2, 1,2.000000},
  {fuseki9643,4,"Fuseki655", 2,-2,2.000000},
  {fuseki9644,4,"Fuseki656", 0,-2,3.000000},
  {fuseki9645,5,"Fuseki657",-2,-1,3.000000},
  {fuseki9646,3,"Fuseki658", 0, 0,2.000000},
  {fuseki9647,4,"Fuseki659", 2,-1,2.000000},
  {fuseki9648,5,"Fuseki660", 2,-1,2.000000},
  {fuseki9649,3,"Fuseki661",-1, 2,2.000000},
  {fuseki9650,4,"Fuseki662", 2, 2,2.000000},
  {fuseki9651,5,"Fuseki663", 1, 1,3.000000},
  {fuseki9652,4,"Fuseki664", 1, 1,3.000000},
  {fuseki9653,5,"Fuseki665", 3,-1,2.000000},
  {fuseki9654,5,"Fuseki666", 1, 2,3.000000},
  {fuseki9655,3,"Fuseki667", 2,-1,2.000000},
  {fuseki9656,4,"Fuseki668",-1, 2,2.000000},
  {fuseki9657,5,"Fuseki669", 2, 0,2.000000},
  {fuseki9658,4,"Fuseki670", 3,-1,2.000000},
  {fuseki9659,4,"Fuseki671",-2, 0,2.000000},
  {fuseki9660,5,"Fuseki672", 2, 1,3.000000},
  {fuseki9661,4,"Fuseki673", 2,-1,3.000000},
  {fuseki9662,3,"Fuseki674", 1, 2,2.000000},
  {fuseki9663,2,"Fuseki675", 1, 2,2.000000},
  {fuseki9664,5,"Fuseki676", 0, 2,3.000000},
  {fuseki9665,5,"Fuseki677",-1, 2,2.000000},
  {fuseki9666,5,"Fuseki678", 0, 0,2.000000},
  {fuseki9667,4,"Fuseki679", 2, 2,2.000000},
  {fuseki9668,5,"Fuseki680", 0,-2,2.000000},
  {fuseki9669,5,"Fuseki681", 1, 2,3.000000},
  {fuseki9670,3,"Fuseki682", 0, 0,2.000000},
  {fuseki9671,5,"Fuseki683", 0,-3,3.000000},
  {fuseki9672,5,"Fuseki684",-2, 0,2.000000},
  {fuseki9673,4,"Fuseki685",-1, 1,3.000000},
  {fuseki9674,4,"Fuseki686", 0, 2,2.000000},
  {fuseki9675,3,"Fuseki687",-2, 0,2.000000},
  {fuseki9676,3,"Fuseki688",-2,-1,2.000000},
  {fuseki9677,5,"Fuseki689", 1,-1,2.000000},
  {fuseki9678,3,"Fuseki690", 2,-2,2.000000},
  {fuseki9679,5,"Fuseki691", 1, 0,2.000000},
  {fuseki9680,3,"Fuseki692", 2,-2,2.000000},
  {fuseki9681,5,"Fuseki693", 0,-1,2.000000},
  {fuseki9682,5,"Fuseki694",-2,-1,3.000000},
  {fuseki9683,5,"Fuseki695", 1,-3,2.000000},
  {fuseki9684,5,"Fuseki696", 0, 2,3.000000},
  {fuseki9685,3,"Fuseki697", 0, 2,2.000000},
  {fuseki9686,2,"Fuseki698", 1, 1,2.000000},
  {fuseki9687,5,"Fuseki699", 0,-1,2.000000},
  {fuseki9688,4,"Fuseki700", 0,-2,2.000000},
  {fuseki9689,3,"Fuseki701", 2, 0,3.000000},
  {fuseki9690,3,"Fuseki703",-2, 2,2.000000},
  {fuseki9691,5,"Fuseki704", 1,-2,3.000000},
  {fuseki9692,3,"Fuseki705",-2, 2,3.000000},
  {fuseki9693,3,"Fuseki706",-1, 2,2.000000},
  {fuseki9694,4,"Fuseki707", 2, 1,2.000000},
  {fuseki9695,4,"Fuseki708", 1, 2,2.000000},
  {fuseki9696,3,"Fuseki709", 1, 2,2.000000},
  {fuseki9697,4,"Fuseki710", 0,-1,2.000000},
  {fuseki9698,4,"Fuseki712", 1,-3,3.000000},
  {fuseki9699,5,"Fuseki714", 2,-2,3.000000},
  {fuseki9700,4,"Fuseki715",-1,-2,2.000000},
  {fuseki9701,4,"Fuseki716",-1, 0,2.000000},
  {fuseki9702,5,"Fuseki717", 1, 3,2.000000},
  {fuseki9703,3,"Fuseki718", 0,-2,2.000000},
  {fuseki9704,4,"Fuseki719", 0, 1,3.000000},
  {fuseki9705,5,"Fuseki720", 3, 1,2.000000},
  {fuseki9706,4,"Fuseki721",-2, 0,2.000000},
  {fuseki9707,3,"Fuseki722", 1,-1,2.000000},
  {fuseki9708,5,"Fuseki723", 1,-2,2.000000},
  {fuseki9709,4,"Fuseki724",-2, 2,2.000000},
  {fuseki9710,4,"Fuseki725",-2,-2,3.000000},
  {fuseki9711,3,"Fuseki726",-1, 2,2.000000},
  {fuseki9712,4,"Fuseki727", 2, 0,2.000000},
  {fuseki9713,4,"Fuseki728", 1, 1,2.000000},
  {fuseki9714,4,"Fuseki729", 0,-2,2.000000},
  {fuseki9715,5,"Fuseki730", 1, 0,2.000000},
  {fuseki9716,5,"Fuseki731",-1,-2,3.000000},
  {fuseki9717,4,"Fuseki732",-2, 1,2.000000},
  {fuseki9718,4,"Fuseki733",-2, 0,2.000000},
  {fuseki9719,3,"Fuseki734",-1, 1,2.000000},
  {fuseki9720,4,"Fuseki735", 2,-1,2.000000},
  {fuseki9721,5,"Fuseki737", 1, 1,2.000000},
  {fuseki9722,4,"Fuseki738", 0,-2,2.000000},
  {fuseki9723,2,"Fuseki739", 0,-1,2.000000},
  {fuseki9724,5,"Fuseki740",-2, 0,2.000000},
  {fuseki9725,5,"Fuseki741", 0, 1,2.000000},
  {fuseki9726,5,"Fuseki742", 0, 2,2.000000},
  {fuseki9727,5,"Fuseki743",-2, 1,2.000000},
  {fuseki9728,4,"Fuseki744",-1,-2,2.000000},
  {fuseki9729,4,"Fuseki745", 2, 1,2.000000},
  {fuseki9730,5,"Fuseki746",-1,-2,2.000000},
  {fuseki9731,3,"Fuseki747",-2, 2,2.000000},
  {fuseki9732,5,"Fuseki748", 0, 2,2.000000},
  {fuseki9733,5,"Fuseki749", 1,-1,2.000000},
  {fuseki9734,5,"Fuseki750", 2,-2,2.000000},
  {fuseki9735,4,"Fuseki751", 2, 0,2.000000},
  {fuseki9736,4,"Fuseki752",-1, 2,2.000000},
  {fuseki9737,5,"Fuseki753", 2, 2,2.000000},
  {fuseki9738,5,"Fuseki754", 3, 0,2.000000},
  {fuseki9739,4,"Fuseki755",-1, 1,2.000000},
  {fuseki9740,3,"Fuseki756", 1, 2,2.000000},
  {fuseki9741,5,"Fuseki757", 1, 2,2.000000},
  {fuseki9742,4,"Fuseki758", 2,-1,2.000000},
  {fuseki9743,5,"Fuseki759", 0, 1,2.000000},
  {fuseki9744,4,"Fuseki760", 1, 0,2.000000},
  {fuseki9745,3,"Fuseki761", 2, 0,2.000000},
  {fuseki9746,5,"Fuseki762",-1, 0,2.000000},
  {fuseki9747,5,"Fuseki763", 1, 0,2.000000},
  {fuseki9748,5,"Fuseki764", 0, 1,2.000000},
  {fuseki9749,5,"Fuseki765", 0,-2,2.000000},
  {fuseki9750,5,"Fuseki766", 2,-3,2.000000},
  {fuseki9751,5,"Fuseki767",-1,-2,2.000000},
  {fuseki9752,4,"Fuseki768",-2, 0,2.000000},
  {fuseki9753,4,"Fuseki769", 0, 2,2.000000},
  {fuseki9754,4,"Fuseki770", 0,-1,2.000000},
  {fuseki9755,5,"Fuseki771", 1, 0,2.000000},
  {fuseki9756,5,"Fuseki772", 1, 2,2.000000},
  {fuseki9757,4,"Fuseki773", 2, 1,2.000000},
  {fuseki9758,5,"Fuseki774", 0, 2,2.000000},
  {fuseki9759,5,"Fuseki775", 2,-2,2.000000},
  {fuseki9760,5,"Fuseki776", 1, 3,2.000000},
  {fuseki9761,3,"Fuseki777",-1,-2,2.000000},
  {fuseki9762,5,"Fuseki778",-2, 1,2.000000},
  {fuseki9763,5,"Fuseki779", 1, 0,2.000000},
  {fuseki9764,4,"Fuseki780", 2, 2,2.000000},
  {fuseki9765,3,"Fuseki781", 1, 2,2.000000},
  {fuseki9766,5,"Fuseki782", 1, 3,2.000000},
  {fuseki9767,5,"Fuseki783", 0, 2,2.000000},
  {fuseki9768,4,"Fuseki784", 0, 1,2.000000},
  {fuseki9769,5,"Fuseki785",-1,-1,2.000000},
  {fuseki9770,4,"Fuseki786",-1, 1,2.000000},
  {fuseki9771,4,"Fuseki787", 1,-2,2.000000},
  {fuseki9772,4,"Fuseki788",-1, 1,2.000000},
  {fuseki9773,4,"Fuseki789", 2,-1,2.000000},
  {fuseki9774,5,"Fuseki790", 1,-1,2.000000},
  {fuseki9775,5,"Fuseki791",-1, 1,2.000000},
  {fuseki9776,4,"Fuseki792",-1,-2,2.000000},
  {fuseki9777,4,"Fuseki793", 1, 1,2.000000},
  {fuseki9778,4,"Fuseki794", 0,-1,2.000000},
  {fuseki9779,4,"Fuseki795",-2,-2,2.000000},
  {fuseki9780,5,"Fuseki796", 2, 0,2.000000},
  {fuseki9781,3,"Fuseki797", 2,-2,2.000000},
  {fuseki9782,4,"Fuseki799", 1, 0,2.000000},
  {fuseki9783,4,"Fuseki800", 2,-1,2.000000},
  {fuseki9784,4,"Fuseki801",-2, 0,2.000000},
  {fuseki9785,4,"Fuseki802", 2,-1,2.000000},
  {fuseki9786,4,"Fuseki803", 1,-2,2.000000},
  {fuseki9787,5,"Fuseki804", 1,-1,2.000000},
  {fuseki9788,3,"Fuseki805", 2, 2,2.000000},
  {fuseki9789,5,"Fuseki806", 0, 2,2.000000},
  {fuseki9790,3,"Fuseki807",-1,-2,2.000000},
  {fuseki9791,5,"Fuseki808", 1, 0,2.000000},
  {fuseki9792,5,"Fuseki809",-2, 2,2.000000},
  {fuseki9793,4,"Fuseki810", 1,-1,2.000000},
  {fuseki9794,4,"Fuseki811", 2,-1,2.000000},
  {fuseki9795,5,"Fuseki812", 2,-2,2.000000},
  {fuseki9796,4,"Fuseki813", 2, 2,2.000000},
  {fuseki9797,5,"Fuseki814", 1, 0,2.000000},
  {fuseki9798,3,"Fuseki815",-2, 0,2.000000},
  {fuseki9799,5,"Fuseki816",-1, 3,2.000000},
  {fuseki9800,5,"Fuseki817", 1,-2,2.000000},
  {fuseki9801,5,"Fuseki818", 0,-2,2.000000},
  {fuseki9802,5,"Fuseki819", 2, 0,2.000000},
  {fuseki9803,4,"Fuseki820",-2,-1,2.000000},
  {fuseki9804,5,"Fuseki821", 0, 1,2.000000},
  {fuseki9805,4,"Fuseki822", 2,-2,2.000000},
  {fuseki9806,5,"Fuseki823", 2,-1,2.000000},
  {fuseki9807,4,"Fuseki824", 0, 0,2.000000},
  {fuseki9808,4,"Fuseki825", 1,-1,2.000000},
  {fuseki9809,3,"Fuseki826", 0, 2,2.000000},
  {fuseki9810,5,"Fuseki827", 1,-1,2.000000},
  {fuseki9811,3,"Fuseki828",-1,-1,2.000000},
  {fuseki9812,5,"Fuseki829", 0,-2,2.000000},
  {fuseki9813,4,"Fuseki830", 1,-1,2.000000},
  {fuseki9814,5,"Fuseki831", 2, 2,2.000000},
  {fuseki9815,5,"Fuseki832", 0,-1,2.000000},
  {fuseki9816,5,"Fuseki834",-2, 2,2.000000},
  {fuseki9817,5,"Fuseki835",-2, 0,2.000000},
  {fuseki9818,5,"Fuseki836",-2,-2,2.000000},
  {fuseki9819,4,"Fuseki838",-1, 2,2.000000},
  {fuseki9820,4,"Fuseki839",-1,-1,2.000000},
  {fuseki9821,4,"Fuseki840",-1,-2,2.000000},
  {fuseki9822,4,"Fuseki841", 2, 1,2.000000},
  {fuseki9823,3,"Fuseki843", 0,-2,2.000000},
  {fuseki9824,3,"Fuseki844", 1, 1,2.000000},
  {fuseki9825,5,"Fuseki845",-1, 0,2.000000},
  {fuseki9826,4,"Fuseki846", 2,-1,2.000000},
  {fuseki9827,5,"Fuseki847",-1, 1,2.000000},
  {fuseki9828,5,"Fuseki848",-1, 0,2.000000},
  {fuseki9829,5,"Fuseki849", 3,-1,2.000000},
  {fuseki9830,2,"Fuseki1001", 0, 0,133.000000},
  {fuseki9831,2,"Fuseki1002", 2, 2,117.000000},
  {fuseki9832,2,"Fuseki1003", 2, 1,105.000000},
  {fuseki9833,2,"Fuseki1004",-1,-1,64.000000},
  {fuseki9834,2,"Fuseki1005",-1, 1,26.000000},
  {fuseki9835,2,"Fuseki1006", 0,-2,23.000000},
  {fuseki9836,2,"Fuseki1007",-1, 2,16.000000},
  {fuseki9837,2,"Fuseki1008", 1, 0,13.000000},
  {fuseki9838,3,"Fuseki1009", 0,-2,52.000000},
  {fuseki9839,3,"Fuseki1010", 1, 2,41.000000},
  {fuseki9840,3,"Fuseki1011",-2,-2,23.000000},
  {fuseki9841,3,"Fuseki1012", 1, 1,8.000000},
  {fuseki9842,3,"Fuseki1013", 2, 2,34.000000},
  {fuseki9843,3,"Fuseki1014", 0, 0,15.000000},
  {fuseki9844,3,"Fuseki1015", 0,-2,14.000000},
  {fuseki9845,3,"Fuseki1016", 1, 1,14.000000},
  {fuseki9846,3,"Fuseki1017", 2, 1,11.000000},
  {fuseki9847,3,"Fuseki1018",-2, 1,7.000000},
  {fuseki9848,3,"Fuseki1019", 0, 1,7.000000},
  {fuseki9849,3,"Fuseki1020", 0,-1,4.000000},
  {fuseki9850,3,"Fuseki1021", 1, 1,32.000000},
  {fuseki9851,3,"Fuseki1022",-1,-2,23.000000},
  {fuseki9852,3,"Fuseki1023",-2,-2,17.000000},
  {fuseki9853,3,"Fuseki1024", 2, 0,16.000000},
  {fuseki9854,3,"Fuseki1025", 1, 3,9.000000},
  {fuseki9855,3,"Fuseki1026", 0, 0,8.000000},
  {fuseki9856,3,"Fuseki1027", 0,-2,32.000000},
  {fuseki9857,3,"Fuseki1028",-2,-2,14.000000},
  {fuseki9858,3,"Fuseki1029",-1,-2,13.000000},
  {fuseki9859,3,"Fuseki1030",-1,-2,11.000000},
  {fuseki9860,3,"Fuseki1031", 0,-1,11.000000},
  {fuseki9861,3,"Fuseki1032", 0, 0,8.000000},
  {fuseki9862,3,"Fuseki1033",-1,-1,5.000000},
  {fuseki9863,4,"Fuseki1034",-2, 0,33.000000},
  {fuseki9864,4,"Fuseki1035", 0, 0,18.000000},
  {fuseki9865,4,"Fuseki1036", 1, 1,14.000000},
  {fuseki9866,4,"Fuseki1037", 1,-2,6.000000},
  {fuseki9867,3,"Fuseki1038", 1, 2,34.000000},
  {fuseki9868,3,"Fuseki1039", 1, 1,8.000000},
  {fuseki9869,3,"Fuseki1040", 2, 2,5.000000},
  {fuseki9870,3,"Fuseki1041",-1,-3,5.000000},
  {fuseki9871,3,"Fuseki1042", 2, 2,4.000000},
  {fuseki9872,4,"Fuseki1043", 0, 2,17.000000},
  {fuseki9873,4,"Fuseki1044", 1,-2,8.000000},
  {fuseki9874,4,"Fuseki1045", 0, 2,7.000000},
  {fuseki9875,4,"Fuseki1046",-1,-2,6.000000},
  {fuseki9876,4,"Fuseki1047",-2,-2,5.000000},
  {fuseki9877,4,"Fuseki1048", 1,-2,4.000000},
  {fuseki9878,4,"Fuseki1049", 0, 2,2.000000},
  {fuseki9879,5,"Fuseki1050", 2, 0,30.000000},
  {fuseki9880,5,"Fuseki1051", 1,-1,7.000000},
  {fuseki9881,5,"Fuseki1052", 2,-1,5.000000},
  {fuseki9882,4,"Fuseki1053", 2, 0,13.000000},
  {fuseki9883,4,"Fuseki1054", 0,-2,6.000000},
  {fuseki9884,4,"Fuseki1055",-2,-2,6.000000},
  {fuseki9885,4,"Fuseki1056", 2, 0,5.000000},
  {fuseki9886,4,"Fuseki1057", 2, 1,5.000000},
  {fuseki9887,4,"Fuseki1058", 2, 0,2.000000},
  {fuseki9888,4,"Fuseki1059", 1, 3,10.000000},
  {fuseki9889,4,"Fuseki1060", 1, 2,6.000000},
  {fuseki9890,4,"Fuseki1061",-2, 0,4.000000},
  {fuseki9891,4,"Fuseki1062", 0, 0,4.000000},
  {fuseki9892,4,"Fuseki1063", 1, 1,4.000000},
  {fuseki9893,4,"Fuseki1064", 0, 1,3.000000},
  {fuseki9894,4,"Fuseki1065", 2, 0,17.000000},
  {fuseki9895,4,"Fuseki1066", 2, 1,8.000000},
  {fuseki9896,4,"Fuseki1067", 1,-3,2.000000},
  {fuseki9897,4,"Fuseki1068", 1,-2,2.000000},
  {fuseki9898,5,"Fuseki1069", 0, 2,13.000000},
  {fuseki9899,5,"Fuseki1070", 0, 3,4.000000},
  {fuseki9900,5,"Fuseki1071",-1, 0,4.000000},
  {fuseki9901,5,"Fuseki1072", 0,-2,3.000000},
  {fuseki9902,5,"Fuseki1073", 0, 0,2.000000},
  {fuseki9903,5,"Fuseki1074", 1, 3,2.000000},
  {fuseki9904,5,"Fuseki1075", 1,-1,2.000000},
  {fuseki9905,4,"Fuseki1076", 0,-2,11.000000},
  {fuseki9906,4,"Fuseki1077",-2,-1,4.000000},
  {fuseki9907,4,"Fuseki1078",-2,-1,4.000000},
  {fuseki9908,4,"Fuseki1079", 3, 1,3.000000},
  {fuseki9909,4,"Fuseki1080",-2,-2,2.000000},
  {fuseki9910,4,"Fuseki1081",-1, 2,2.000000},
  {fuseki9911,4,"Fuseki1082",-1,-2,2.000000},
  {fuseki9912,4,"Fuseki1083", 1, 2,15.000000},
  {fuseki9913,4,"Fuseki1084", 2, 2,8.000000},
  {fuseki9914,4,"Fuseki1085", 1, 1,4.000000},
  {fuseki9915,4,"Fuseki1086",-1,-2,2.000000},
  {fuseki9916,4,"Fuseki1087", 2, 0,2.000000},
  {fuseki9917,6,"Fuseki1088", 3,-1,10.000000},
  {fuseki9918,6,"Fuseki1089", 1,-1,8.000000},
  {fuseki9919,6,"Fuseki1090", 0, 3,3.000000},
  {fuseki9920,6,"Fuseki1091",-2, 0,3.000000},
  {fuseki9921,6,"Fuseki1092", 1, 0,3.000000},
  {fuseki9922,6,"Fuseki1093", 0,-2,2.000000},
  {fuseki9923,3,"Fuseki1094",-1, 2,23.000000},
  {fuseki9924,3,"Fuseki1095", 0, 2,7.000000},
  {fuseki9925,3,"Fuseki1096", 0, 0,5.000000},
  {fuseki9926,3,"Fuseki1097", 2, 2,4.000000},
  {fuseki9927,3,"Fuseki1098",-2,-1,3.000000},
  {fuseki9928,4,"Fuseki1099",-1,-2,6.000000},
  {fuseki9929,4,"Fuseki1100",-2, 0,5.000000},
  {fuseki9930,4,"Fuseki1101",-1, 2,3.000000},
  {fuseki9931,4,"Fuseki1102",-2, 0,15.000000},
  {fuseki9932,4,"Fuseki1103",-2,-2,3.000000},
  {fuseki9933,4,"Fuseki1104",-1,-2,2.000000},
  {fuseki9934,4,"Fuseki1105", 1, 0,12.000000},
  {fuseki9935,4,"Fuseki1106", 0,-2,6.000000},
  {fuseki9936,4,"Fuseki1107",-2, 1,3.000000},
  {fuseki9937,5,"Fuseki1108", 2, 0,16.000000},
  {fuseki9938,5,"Fuseki1109", 3,-1,8.000000},
  {fuseki9939,5,"Fuseki1110", 0,-1,4.000000},
  {fuseki9940,5,"Fuseki1111", 2, 0,3.000000},
  {fuseki9941,4,"Fuseki1112", 0,-2,5.000000},
  {fuseki9942,4,"Fuseki1113",-1, 1,3.000000},
  {fuseki9943,4,"Fuseki1114", 2,-1,3.000000},
  {fuseki9944,4,"Fuseki1115", 0, 2,2.000000},
  {fuseki9945,4,"Fuseki1116",-2, 1,2.000000},
  {fuseki9946,5,"Fuseki1117", 0, 2,13.000000},
  {fuseki9947,5,"Fuseki1118", 1,-2,2.000000},
  {fuseki9948,5,"Fuseki1119", 2, 0,4.000000},
  {fuseki9949,5,"Fuseki1120", 2, 0,4.000000},
  {fuseki9950,5,"Fuseki1121", 1, 2,3.000000},
  {fuseki9951,5,"Fuseki1122", 1, 1,2.000000},
  {fuseki9952,3,"Fuseki1123",-3, 1,5.000000},
  {fuseki9953,3,"Fuseki1124",-1, 1,4.000000},
  {fuseki9954,3,"Fuseki1125", 1,-2,4.000000},
  {fuseki9955,4,"Fuseki1126",-2,-2,8.000000},
  {fuseki9956,4,"Fuseki1127", 2, 0,2.000000},
  {fuseki9957,4,"Fuseki1128", 0,-1,2.000000},
  {fuseki9958,6,"Fuseki1129", 2, 0,10.000000},
  {fuseki9959,6,"Fuseki1130", 0, 2,4.000000},
  {fuseki9960,5,"Fuseki1131", 0, 1,11.000000},
  {fuseki9961,5,"Fuseki1132",-1,-2,3.000000},
  {fuseki9962,4,"Fuseki1133",-2, 0,11.000000},
  {fuseki9963,4,"Fuseki1134", 0, 0,6.000000},
  {fuseki9964,4,"Fuseki1135",-2, 0,3.000000},
  {fuseki9965,4,"Fuseki1136",-1, 1,2.000000},
  {fuseki9966,6,"Fuseki1137", 1, 2,10.000000},
  {fuseki9967,5,"Fuseki1138", 0, 2,5.000000},
  {fuseki9968,5,"Fuseki1139", 0, 0,3.000000},
  {fuseki9969,5,"Fuseki1140", 1, 2,3.000000},
  {fuseki9970,4,"Fuseki1141", 0, 2,4.000000},
  {fuseki9971,4,"Fuseki1142",-2,-1,2.000000},
  {fuseki9972,4,"Fuseki1143",-1, 2,2.000000},
  {fuseki9973,4,"Fuseki1144", 2, 0,3.000000},
  {fuseki9974,4,"Fuseki1145", 0,-2,3.000000},
  {fuseki9975,4,"Fuseki1146", 1, 2,2.000000},
  {fuseki9976,3,"Fuseki1147",-1,-2,5.000000},
  {fuseki9977,3,"Fuseki1148", 1, 0,2.000000},
  {fuseki9978,3,"Fuseki1149", 1, 0,2.000000},
  {fuseki9979,4,"Fuseki1150",-2,-2,11.000000},
  {fuseki9980,6,"Fuseki1151", 0,-2,5.000000},
  {fuseki9981,6,"Fuseki1152",-2,-1,4.000000},
  {fuseki9982,5,"Fuseki1153", 3, 1,6.000000},
  {fuseki9983,5,"Fuseki1154",-2,-1,3.000000},
  {fuseki9984,5,"Fuseki1155",-2, 0,2.000000},
  {fuseki9985,5,"Fuseki1156", 0,-2,8.000000},
  {fuseki9986,5,"Fuseki1157", 3, 1,2.000000},
  {fuseki9987,5,"Fuseki1158", 0,-2,8.000000},
  {fuseki9988,5,"Fuseki1159",-1,-1,2.000000},
  {fuseki9989,6,"Fuseki1160",-2,-2,4.000000},
  {fuseki9990,6,"Fuseki1161", 0, 2,3.000000},
  {fuseki9991,6,"Fuseki1162",-1,-2,2.000000},
  {fuseki9992,4,"Fuseki1163",-2,-1,2.000000},
  {fuseki9993,4,"Fuseki1164", 2, 0,2.000000},
  {fuseki9994,4,"Fuseki1165", 2, 0,2.000000},
  {fuseki9995,4,"Fuseki1166",-2,-2,2.000000},
  {fuseki9996,4,"Fuseki1167", 0, 2,5.000000},
  {fuseki9997,4,"Fuseki1168",-2, 0,3.000000},
  {fuseki9998,5,"Fuseki1169",-2,-2,3.000000},
  {fuseki9999,5,"Fuseki1170", 3,-1,2.000000},
  {fuseki91000,5,"Fuseki1171", 0, 1,2.000000},
  {fuseki91001,5,"Fuseki1172",-2,-2,2.000000},
  {fuseki91002,5,"Fuseki1173",-1, 0,8.000000},
  {fuseki91003,5,"Fuseki1174", 1, 1,2.000000},
  {fuseki91004,4,"Fuseki1175", 0, 0,4.000000},
  {fuseki91005,4,"Fuseki1176", 3,-1,2.000000},
  {fuseki91006,5,"Fuseki1177",-2,-1,5.000000},
  {fuseki91007,5,"Fuseki1178", 0, 2,4.000000},
  {fuseki91008,7,"Fuseki1179", 2, 0,6.000000},
  {fuseki91009,7,"Fuseki1180",-3, 0,2.000000},
  {fuseki91010,5,"Fuseki1181", 1, 2,4.000000},
  {fuseki91011,5,"Fuseki1182",-2, 0,2.000000},
  {fuseki91012,5,"Fuseki1183", 1,-2,2.000000},
  {fuseki91013,7,"Fuseki1184", 1, 1,5.000000},
  {fuseki91014,7,"Fuseki1185",-2, 1,3.000000},
  {fuseki91015,5,"Fuseki1186", 2, 1,9.000000},
  {fuseki91016,7,"Fuseki1187", 1, 1,4.000000},
  {fuseki91017,7,"Fuseki1188", 3, 1,3.000000},
  {fuseki91018,6,"Fuseki1189", 1, 2,6.000000},
  {fuseki91019,6,"Fuseki1190", 1, 3,2.000000},
  {fuseki91020,5,"Fuseki1191",-1,-1,3.000000},
  {fuseki91021,5,"Fuseki1192", 1, 3,2.000000},
  {fuseki91022,5,"Fuseki1193", 2, 0,2.000000},
  {fuseki91023,4,"Fuseki1194", 1, 2,4.000000},
  {fuseki91024,5,"Fuseki1195", 3, 0,8.000000},
  {fuseki91025,9,"Fuseki1196",-3, 1,3.000000},
  {fuseki91026,9,"Fuseki1197", 3, 1,2.000000},
  {fuseki91027,4,"Fuseki1198", 2, 2,3.000000},
  {fuseki91028,4,"Fuseki1199", 1, 0,3.000000},
  {fuseki91029,4,"Fuseki1200",-2,-2,2.000000},
  {fuseki91030,4,"Fuseki1201", 2, 2,2.000000},
  {fuseki91031,6,"Fuseki1202",-1,-1,7.000000},
  {fuseki91032,6,"Fuseki1203", 0,-3,3.000000},
  {fuseki91033,6,"Fuseki1204", 0,-3,2.000000},
  {fuseki91034,6,"Fuseki1205", 2, 0,6.000000},
  {fuseki91035,6,"Fuseki1206",-3, 0,2.000000},
  {fuseki91036,5,"Fuseki1207", 2,-3,6.000000},
  {fuseki91037,5,"Fuseki1208",-1, 1,2.000000},
  {fuseki91038,7,"Fuseki1209", 1, 1,5.000000},
  {fuseki91039,7,"Fuseki1210",-2, 1,3.000000},
  {fuseki91040,6,"Fuseki1211",-1,-1,3.000000},
  {fuseki91041,6,"Fuseki1212",-2,-2,3.000000},
  {fuseki91042,6,"Fuseki1213", 3, 1,2.000000},
  {fuseki91043,4,"Fuseki1214", 2, 2,6.000000},
  {fuseki91044,4,"Fuseki1215",-2,-2,2.000000},
  {fuseki91045,4,"Fuseki1216", 0, 1,2.000000},
  {fuseki91046,8,"Fuseki1217",-2, 0,8.000000},
  {fuseki91047,6,"Fuseki1218", 1, 1,6.000000},
  {fuseki91048,6,"Fuseki1219", 2, 1,2.000000},
  {fuseki91049,7,"Fuseki1220", 2, 1,6.000000},
  {fuseki91050,4,"Fuseki1221",-1, 0,4.000000},
  {fuseki91051,4,"Fuseki1222",-2, 0,2.000000},
  {fuseki91052,7,"Fuseki1223", 2, 1,6.000000},
  {fuseki91053,6,"Fuseki1224", 3,-1,4.000000},
  {fuseki91054,6,"Fuseki1225", 0, 1,3.000000},
  {fuseki91055,6,"Fuseki1226", 2, 1,3.000000},
  {fuseki91056,4,"Fuseki1227", 1, 2,3.000000},
  {fuseki91057,4,"Fuseki1228", 2, 2,2.000000},
  {fuseki91058,5,"Fuseki1229", 0, 2,5.000000},
  {fuseki91059,5,"Fuseki1230",-2,-2,2.000000},
  {fuseki91060,5,"Fuseki1231",-1,-1,2.000000},
  {fuseki91061,5,"Fuseki1232",-2, 0,2.000000},
  {fuseki91062,8,"Fuseki1233", 3, 1,6.000000},
  {fuseki91063,6,"Fuseki1234", 2, 0,5.000000},
  {fuseki91064,5,"Fuseki1235", 2, 1,2.000000},
  {fuseki91065,5,"Fuseki1236", 0,-3,2.000000},
  {fuseki91066,6,"Fuseki1237", 3, 0,4.000000},
  {fuseki91067,5,"Fuseki1238", 1,-3,3.000000},
  {fuseki91068,5,"Fuseki1239",-1,-1,2.000000},
  {fuseki91069,7,"Fuseki1240", 0, 2,4.000000},
  {fuseki91070,5,"Fuseki1241",-1, 1,3.000000},
  {fuseki91071,5,"Fuseki1242", 0, 1,2.000000},
  {fuseki91072,5,"Fuseki1243", 0,-1,6.000000},
  {fuseki91073,5,"Fuseki1244",-2,-3,6.000000},
  {fuseki91074,7,"Fuseki1245",-1,-2,3.000000},
  {fuseki91075,7,"Fuseki1246",-1, 0,2.000000},
  {fuseki91076,6,"Fuseki1247", 1, 1,2.000000},
  {fuseki91077,6,"Fuseki1248",-2,-1,2.000000},
  {fuseki91078,5,"Fuseki1249",-1,-3,3.000000},
  {fuseki91079,5,"Fuseki1250",-2, 0,2.000000},
  {fuseki91080,6,"Fuseki1251",-2,-1,4.000000},
  {fuseki91081,6,"Fuseki1252",-1,-1,2.000000},
  {fuseki91082,4,"Fuseki1253", 0, 0,2.000000},
  {fuseki91083,4,"Fuseki1254",-1, 1,2.000000},
  {fuseki91084,5,"Fuseki1255", 1,-1,4.000000},
  {fuseki91085,5,"Fuseki1256",-1, 0,2.000000},
  {fuseki91086,5,"Fuseki1257", 1, 1,3.000000},
  {fuseki91087,5,"Fuseki1258", 1, 3,2.000000},
  {fuseki91088,7,"Fuseki1259", 0,-2,2.000000},
  {fuseki91089,7,"Fuseki1260", 0,-2,2.000000},
  {fuseki91090,6,"Fuseki1261",-2,-2,5.000000},
  {fuseki91091,5,"Fuseki1262", 0, 1,4.000000},
  {fuseki91092,6,"Fuseki1263",-1,-2,3.000000},
  {fuseki91093,4,"Fuseki1264", 2, 0,4.000000},
  {fuseki91094,5,"Fuseki1265", 2, 1,2.000000},
  {fuseki91095,9,"Fuseki1266", 1, 0,5.000000},
  {fuseki91096,6,"Fuseki1267",-1, 1,2.000000},
  {fuseki91097,4,"Fuseki1268",-2, 0,2.000000},
  {fuseki91098,4,"Fuseki1269", 0,-2,2.000000},
  {fuseki91099,7,"Fuseki1270", 3,-1,3.000000},
  {fuseki91100,7,"Fuseki1271", 1,-1,2.000000},
  {fuseki91101,4,"Fuseki1272",-2,-2,3.000000},
  {fuseki91102,5,"Fuseki1273",-1, 0,3.000000},
  {fuseki91103,5,"Fuseki1274", 2, 2,3.000000},
  {fuseki91104,5,"Fuseki1275", 2, 1,2.000000},
  {fuseki91105,10,"Fuseki1276", 2, 0,2.000000},
  {fuseki91106,8,"Fuseki1277", 1, 0,2.000000},
  {fuseki91107,8,"Fuseki1278", 0,-1,2.000000},
  {fuseki91108,8,"Fuseki1279", 2, 1,5.000000},
  {fuseki91109,5,"Fuseki1280", 0, 2,2.000000},
  {fuseki91110,4,"Fuseki1281",-2,-2,2.000000},
  {fuseki91111,4,"Fuseki1282", 1, 2,2.000000},
  {fuseki91112,4,"Fuseki1283", 2, 2,2.000000},
  {fuseki91113,6,"Fuseki1284", 0,-2,4.000000},
  {fuseki91114,7,"Fuseki1285", 1, 3,4.000000},
  {fuseki91115,4,"Fuseki1286",-1, 2,4.000000},
  {fuseki91116,5,"Fuseki1287", 2, 2,4.000000},
  {fuseki91117,7,"Fuseki1288",-1,-2,4.000000},
  {fuseki91118,5,"Fuseki1289",-2, 0,2.000000},
  {fuseki91119,5,"Fuseki1290", 3,-2,2.000000},
  {fuseki91120,7,"Fuseki1291",-2,-1,2.000000},
  {fuseki91121,7,"Fuseki1292",-3,-1,3.000000},
  {fuseki91122,7,"Fuseki1293", 2, 0,3.000000},
  {fuseki91123,5,"Fuseki1294", 2, 0,2.000000},
  {fuseki91124,5,"Fuseki1295",-2, 0,2.000000},
  {fuseki91125,7,"Fuseki1296", 0,-1,3.000000},
  {fuseki91126,5,"Fuseki1297", 1,-2,2.000000},
  {fuseki91127,5,"Fuseki1298",-1, 1,2.000000},
  {fuseki91128,5,"Fuseki1299", 0, 3,4.000000},
  {fuseki91129,5,"Fuseki1300",-2, 0,2.000000},
  {fuseki91130,5,"Fuseki1301", 3,-1,2.000000},
  {fuseki91131,6,"Fuseki1302",-1,-1,2.000000},
  {fuseki91132,6,"Fuseki1303", 1, 3,3.000000},
  {fuseki91133,6,"Fuseki1304", 0,-1,3.000000},
  {fuseki91134,8,"Fuseki1305",-3, 0,2.000000},
  {fuseki91135,8,"Fuseki1306",-1, 2,2.000000},
  {fuseki91136,6,"Fuseki1307",-2,-2,2.000000},
  {fuseki91137,6,"Fuseki1308",-2, 0,4.000000},
  {fuseki91138,8,"Fuseki1309",-1, 1,4.000000},
  {fuseki91139,7,"Fuseki1310",-1,-1,4.000000},
  {fuseki91140,5,"Fuseki1311", 2, 1,3.000000},
  {fuseki91141,4,"Fuseki1312", 1, 2,4.000000},
  {fuseki91142,7,"Fuseki1313", 1, 3,2.000000},
  {fuseki91143,7,"Fuseki1314",-1,-3,2.000000},
  {fuseki91144,5,"Fuseki1315", 3,-1,2.000000},
  {fuseki91145,9,"Fuseki1316",-1, 2,2.000000},
  {fuseki91146,4,"Fuseki1317", 1,-1,2.000000},
  {fuseki91147,6,"Fuseki1318", 0, 3,4.000000},
  {fuseki91148,7,"Fuseki1319", 0,-2,2.000000},
  {fuseki91149,6,"Fuseki1320", 1,-1,4.000000},
  {fuseki91150,5,"Fuseki1321", 3, 0,2.000000},
  {fuseki91151,6,"Fuseki1322", 2, 2,4.000000},
  {fuseki91152,7,"Fuseki1323", 2, 1,3.000000},
  {fuseki91153,5,"Fuseki1324", 1, 2,3.000000},
  {fuseki91154,5,"Fuseki1325", 1, 0,3.000000},
  {fuseki91155,6,"Fuseki1326", 0,-2,3.000000},
  {fuseki91156,5,"Fuseki1327", 1, 0,4.000000},
  {fuseki91157,4,"Fuseki1328", 2, 0,2.000000},
  {fuseki91158,7,"Fuseki1329",-3,-1,4.000000},
  {fuseki91159,4,"Fuseki1330", 2, 0,2.000000},
  {fuseki91160,7,"Fuseki1331", 1, 3,4.000000},
  {fuseki91161,7,"Fuseki1332", 1, 2,3.000000},
  {fuseki91162,8,"Fuseki1333", 1, 1,2.000000},
  {fuseki91163,5,"Fuseki1334",-3, 1,2.000000},
  {fuseki91164,6,"Fuseki1335", 0, 1,2.000000},
  {fuseki91165,6,"Fuseki1336", 2, 1,3.000000},
  {fuseki91166,7,"Fuseki1337",-1,-2,2.000000},
  {fuseki91167,6,"Fuseki1338", 2, 2,2.000000},
  {fuseki91168,10,"Fuseki1339",-2, 0,3.000000},
  {fuseki91169,4,"Fuseki1340",-2, 1,3.000000},
  {fuseki91170,5,"Fuseki1341", 0,-2,3.000000},
  {fuseki91171,7,"Fuseki1342",-1, 1,2.000000},
  {fuseki91172,6,"Fuseki1343", 0,-2,2.000000},
  {fuseki91173,6,"Fuseki1344",-2, 0,2.000000},
  {fuseki91174,5,"Fuseki1345",-1, 1,2.000000},
  {fuseki91175,6,"Fuseki1346", 0, 0,2.000000},
  {fuseki91176,5,"Fuseki1347",-2,-1,2.000000},
  {fuseki91177,4,"Fuseki1348", 2, 0,2.000000},
  {fuseki91178,8,"Fuseki1349", 1, 2,2.000000},
  {fuseki91179,6,"Fuseki1350",-2, 0,2.000000},
  {fuseki91180,5,"Fuseki1351", 2, 2,2.000000},
  {fuseki91181,4,"Fuseki1352", 0, 2,2.000000},
  {fuseki91182,7,"Fuseki1353",-2,-1,3.000000},
  {fuseki91183,6,"Fuseki1354", 3,-1,2.000000},
  {fuseki91184,8,"Fuseki1355", 1, 2,2.000000},
  {fuseki91185,6,"Fuseki1356",-2,-2,2.000000},
  {fuseki91186,7,"Fuseki1357", 0, 1,2.000000},
  {fuseki91187,5,"Fuseki1358",-2, 1,3.000000},
  {fuseki91188,5,"Fuseki1359", 1, 3,3.000000},
  {fuseki91189,7,"Fuseki1360",-3,-1,3.000000},
  {fuseki91190,5,"Fuseki1361", 0,-2,2.000000},
  {fuseki91191,6,"Fuseki1362", 0,-2,2.000000},
  {fuseki91192,7,"Fuseki1363", 2, 0,2.000000},
  {fuseki91193,5,"Fuseki1364", 0, 3,2.000000},
  {fuseki91194,5,"Fuseki1365", 0, 1,2.000000},
  {fuseki91195,7,"Fuseki1366", 0,-2,3.000000},
  {fuseki91196,5,"Fuseki1367",-2, 3,2.000000},
  {fuseki91197,6,"Fuseki1368", 1, 2,3.000000},
  {fuseki91198,6,"Fuseki1369", 2, 2,2.000000},
  {fuseki91199,6,"Fuseki1370", 2, 1,2.000000},
  {fuseki91200,7,"Fuseki1371", 1, 0,3.000000},
  {fuseki91201,6,"Fuseki1372", 0,-2,3.000000},
  {fuseki91202,7,"Fuseki1373", 1, 3,2.000000},
  {fuseki91203,7,"Fuseki1374", 1, 3,3.000000},
  {fuseki91204,9,"Fuseki1375", 1,-1,2.000000},
  {fuseki91205,5,"Fuseki1376", 0, 1,2.000000},
  {fuseki91206,8,"Fuseki1377", 2, 0,3.000000},
  {fuseki91207,6,"Fuseki1378",-2, 1,3.000000},
  {fuseki91208,8,"Fuseki1379",-1, 1,2.000000},
  {fuseki91209,5,"Fuseki1380", 2, 0,2.000000},
  {fuseki91210,6,"Fuseki1381",-1, 2,2.000000},
  {fuseki91211,4,"Fuseki1382",-2,-2,2.000000},
  {fuseki91212,7,"Fuseki1383",-1,-3,2.000000},
  {fuseki91213,7,"Fuseki1384", 1, 2,2.000000},
  {fuseki91214,6,"Fuseki1385",-1,-1,2.000000},
  {fuseki91215,8,"Fuseki1386", 1,-3,2.000000},
  {fuseki91216,6,"Fuseki1387", 2, 2,2.000000},
  {fuseki91217,6,"Fuseki1388",-1, 1,2.000000},
  {fuseki91218,5,"Fuseki1389", 1, 0,2.000000},
  {fuseki91219,7,"Fuseki1390",-1, 2,2.000000},
  {fuseki91220,7,"Fuseki1391",-1,-1,2.000000},
  {fuseki91221,5,"Fuseki1392", 1, 2,2.000000},
  {fuseki91222,6,"Fuseki1393",-2, 0,2.000000},
  {fuseki91223,5,"Fuseki1394", 0,-2,2.000000},
  {fuseki91224,7,"Fuseki1395",-3, 1,2.000000},
  {fuseki91225,6,"Fuseki1396",-1, 1,2.000000},
  {fuseki91226,5,"Fuseki1397",-1, 3,2.000000},
  {fuseki91227,7,"Fuseki1398", 0, 0,2.000000},
  {fuseki91228,9,"Fuseki1399",-1, 3,2.000000},
  {fuseki91229,7,"Fuseki1400",-3,-1,2.000000},
  {fuseki91230,8,"Fuseki1401", 2, 1,2.000000},
  {fuseki91231,5,"Fuseki1402", 1, 0,2.000000},
  {fuseki91232,9,"Fuseki1403",-2, 1,2.000000},
  {fuseki91233,5,"Fuseki1404", 0,-2,2.000000},
  {fuseki91234,8,"Fuseki1405",-1, 2,2.000000},
  {fuseki91235,6,"Fuseki1406",-1,-1,2.000000},
  {fuseki91236,6,"Fuseki1407",-3, 0,2.000000},
  {fuseki91237,7,"Fuseki1408", 1, 1,2.000000},
  {fuseki91238,6,"Fuseki1409", 3, 1,2.000000},
  {fuseki91239,5,"Fuseki1410",-1, 1,2.000000},
  {fuseki91240,6,"Fuseki1411",-3,-2,2.000000},
  {fuseki91241,6,"Fuseki1412", 0, 1,2.000000},
  {fuseki91242,8,"Fuseki1413", 0,-3,2.000000},
  {fuseki91243,7,"Fuseki1414",-2, 1,2.000000},
  {fuseki91244,7,"Fuseki1415",-2,-2,2.000000},
  {fuseki91245,6,"Fuseki1416", 1, 0,2.000000},
  {fuseki91246,5,"Fuseki1417", 0,-2,2.000000},
  {fuseki91247,9,"Fuseki1418",-1, 2,2.000000},
  {fuseki91248,6,"Fuseki1419", 2, 1,2.000000},
  {fuseki91249,6,"Fuseki1420", 2, 0,2.000000},
  {fuseki91250,9,"Fuseki1421",-1, 3,2.000000},
  {fuseki91251,7,"Fuseki1422", 1, 2,2.000000},
  {fuseki91252,6,"Fuseki1423",-1, 1,2.000000},
  {fuseki91253,5,"Fuseki1424",-1, 2,2.000000},
  {fuseki91254,6,"Fuseki1425", 1,-2,2.000000},
  {fuseki91255,5,"Fuseki1426",-1, 0,2.000000},
  {fuseki91256,7,"Fuseki1427",-1,-1,2.000000},
  {fuseki91257,5,"Fuseki1428", 0,-1,2.000000},
  {fuseki91258,4,"Fuseki1429",-2, 1,2.000000},
  {fuseki91259,7,"Fuseki1430", 1,-2,2.000000},
  {fuseki91260,9,"Fuseki1431", 1,-2,2.000000},
  {fuseki91261,8,"Fuseki1432",-3,-1,2.000000},
  {fuseki91262,7,"Fuseki1433", 0,-2,2.000000},
  {fuseki91263,6,"Fuseki1434",-2,-2,2.000000},
  {fuseki91264,8,"Fuseki1435", 1,-1,2.000000},
  {fuseki91265,5,"Fuseki1436", 2,-1,2.000000},
  {fuseki91266,9,"Fuseki1437",-1, 2,2.000000},
  {fuseki91267,5,"Fuseki1438", 1,-3,2.000000},
  {fuseki91268,8,"Fuseki1439",-3,-2,2.000000},
  {fuseki91269,5,"Fuseki1440", 0,-2,2.000000},
  {fuseki91270,5,"Fuseki1441", 1, 0,2.000000},
  {fuseki91271,5,"Fuseki1442", 1, 0,2.000000},
  {fuseki91272,7,"Fuseki1443", 0, 0,2.000000},
  {fuseki91273,7,"Fuseki1444", 0, 2,2.000000},
  {fuseki91274,6,"Fuseki1445", 2, 1,2.000000},
  {fuseki91275,5,"Fuseki1446", 2, 2,2.000000},
  {fuseki91276,7,"Fuseki1447", 2,-3,2.000000},
  {fuseki91277,6,"Fuseki1448", 1,-1,2.000000},
  {fuseki91278,7,"Fuseki1449", 0, 1,2.000000},
  {fuseki91279,6,"Fuseki1450", 0, 2,2.000000},
  {fuseki91280,7,"Fuseki1451", 1, 3,2.000000},
  {fuseki91281,9,"Fuseki1452", 2, 1,2.000000},
  {fuseki91282,8,"Fuseki1453",-3, 1,2.000000},
  {fuseki91283,6,"Fuseki1454", 1, 1,2.000000},
  {fuseki91284,6,"Fuseki1455", 0,-3,2.000000},
  {fuseki91285,7,"Fuseki1456", 3,-3,2.000000},
  {fuseki91286,6,"Fuseki1457", 0,-2,2.000000},
  {fuseki91287,7,"Fuseki1458",-1, 3,2.000000},
  {fuseki91288,7,"Fuseki1459", 1, 1,2.000000},
  {fuseki91289,5,"Fuseki1460", 0,-2,2.000000},
  {fuseki91290,7,"Fuseki1461", 1, 0,2.000000},
  {fuseki91291,7,"Fuseki1462", 3, 0,2.000000},
  {fuseki91292,6,"Fuseki1463", 0, 2,2.000000},
  {fuseki91293,7,"Fuseki1464", 0,-2,2.000000},
  {fuseki91294,9,"Fuseki1465",-1, 1,2.000000},
  {fuseki91295,6,"Fuseki1466",-1, 1,2.000000},
  {fuseki91296,7,"Fuseki1467",-3, 1,2.000000},
  {fuseki91297,7,"Fuseki1468", 1,-1,2.000000},
  {fuseki91298,7,"Fuseki1469",-2, 1,2.000000},
  {fuseki91299,6,"Fuseki1470", 0, 2,2.000000},
  {fuseki91300,7,"Fuseki1471",-2, 1,2.000000},
  {fuseki91301,4,"Fuseki1472", 1, 1,2.000000},
  {fuseki91302,9,"Fuseki1473",-1, 3,2.000000},
  {NULL,0,NULL,0,0,0.0}
};

/* mgena =================================================================*/

/* mgena - fuseki13.c */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* #include <stdio.h>  */

/* #include "gnugo.h" */
/* #include "liberty.h" */
/* #include "patterns.h" */


static struct patval fuseki130[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki131[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki132[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki133[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki134[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki135[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki136[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki137[] = {
   {3,-3,1}};

static struct patval fuseki138[] = {
   {-3,-3,1}};

static struct patval fuseki139[] = {
   {3,-3,1}};

static struct patval fuseki1310[] = {
   {-3,3,1}};

static struct patval fuseki1311[] = {
   {3,-3,1}};

static struct patval fuseki1312[] = {
   {3,-3,1}};

static struct patval fuseki1313[] = {
   {-3,3,1}};

static struct patval fuseki1314[] = {
   {3,-3,1}};

static struct patval fuseki1315[] = {
   {-3,3,1}};

static struct patval fuseki1316[] = {
   {3,-3,1}};

static struct patval fuseki1317[] = {
   {-4,3,1}};

static struct patval fuseki1318[] = {
   {-4,-3,1}};

static struct patval fuseki1319[] = {
   {3,-4,1}};

static struct patval fuseki1320[] = {
   {3,4,1}};

static struct patval fuseki1321[] = {
   {-4,-3,1}};

static struct patval fuseki1322[] = {
   {-3,4,1}};

static struct patval fuseki1323[] = {
   {4,3,1}};

static struct patval fuseki1324[] = {
   {4,-3,1}};

static struct patval fuseki1325[] = {
   {4,3,1}};

static struct patval fuseki1326[] = {
   {-3,4,1}};

static struct patval fuseki1327[] = {
   {3,-4,1}};

static struct patval fuseki1328[] = {
   {4,3,1}};

static struct patval fuseki1329[] = {
   {-3,4,1}};

static struct patval fuseki1330[] = {
   {-3,3,1},
   {3,-3,2}};

static struct patval fuseki1331[] = {
   {-3,3,1},
   {3,-3,2}};

static struct patval fuseki1332[] = {
   {-3,3,1},
   {3,-3,2}};

static struct patval fuseki1333[] = {
   {-3,-3,1},
   {3,3,2}};

static struct patval fuseki1334[] = {
   {-4,-4,1}};

static struct patval fuseki1335[] = {
   {-4,-4,1}};

static struct patval fuseki1336[] = {
   {-4,4,1}};

static struct patval fuseki1337[] = {
   {-4,-4,1}};

static struct patval fuseki1338[] = {
   {4,4,1}};

static struct patval fuseki1339[] = {
   {4,4,1}};

static struct patval fuseki1340[] = {
   {-4,4,1}};

static struct patval fuseki1341[] = {
   {-4,4,1}};

static struct patval fuseki1342[] = {
   {-3,4,1},
   {3,-3,2}};

static struct patval fuseki1343[] = {
   {-4,3,1},
   {3,-3,2}};

static struct patval fuseki1344[] = {
   {-4,-3,1},
   {3,3,2}};

static struct patval fuseki1345[] = {
   {-3,-4,1},
   {3,3,2}};

static struct patval fuseki1346[] = {
   {-4,3,1},
   {3,-3,2}};

static struct patval fuseki1347[] = {
   {-3,4,1},
   {3,-3,2}};

static struct patval fuseki1348[] = {
   {-4,3,1},
   {3,-3,2}};

static struct patval fuseki1349[] = {
   {3,4,1},
   {-3,-3,2}};

static struct patval fuseki1350[] = {
   {-3,-3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki1351[] = {
   {3,3,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki1352[] = {
   {-3,-3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki1353[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki1354[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,2}};

static struct patval fuseki1355[] = {
   {3,3,1},
   {3,-3,2}};

static struct patval fuseki1356[] = {
   {-3,-3,1},
   {-3,3,2}};

static struct patval fuseki1357[] = {
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki1358[] = {
   {-3,-3,1},
   {-3,3,2}};

static struct patval fuseki1359[] = {
   {3,3,1},
   {-3,3,2}};

static struct patval fuseki1360[] = {
   {3,-3,1},
   {-4,3,2}};

static struct patval fuseki1361[] = {
   {3,-3,1},
   {-3,4,2}};

static struct patval fuseki1362[] = {
   {3,3,1},
   {-4,-3,2}};

static struct patval fuseki1363[] = {
   {-3,3,1},
   {4,-3,2}};

static struct patval fuseki1364[] = {
   {-3,3,1},
   {3,-4,2}};

static struct patval fuseki1365[] = {
   {-3,-3,1},
   {3,4,2}};

static struct patval fuseki1366[] = {
   {-4,-4,1},
   {3,-3,2}};

static struct patval fuseki1367[] = {
   {-4,4,1},
   {-3,-3,2}};

static struct patval fuseki1368[] = {
   {-4,-4,1},
   {3,-3,2}};

static struct patval fuseki1369[] = {
   {4,4,1},
   {-3,3,2}};

static struct patval fuseki1370[] = {
   {-4,4,1},
   {3,3,2}};

static struct patval fuseki1371[] = {
   {4,-4,1},
   {-3,-3,2}};

static struct patval fuseki1372[] = {
   {4,-4,1},
   {3,3,2}};

static struct patval fuseki1373[] = {
   {4,4,1},
   {3,-3,2}};

static struct patval fuseki1374[] = {
   {4,4,1},
   {3,-3,2}};

static struct patval fuseki1375[] = {
   {4,-3,1},
   {3,3,2}};

static struct patval fuseki1376[] = {
   {-4,-3,1},
   {-3,3,2}};

static struct patval fuseki1377[] = {
   {-3,-4,1},
   {3,-3,2}};

static struct patval fuseki1378[] = {
   {-3,4,1},
   {3,3,2}};

static struct patval fuseki1379[] = {
   {4,-3,1},
   {3,3,2}};

static struct patval fuseki1380[] = {
   {3,4,1},
   {-3,3,2}};

static struct patval fuseki1381[] = {
   {4,-4,1},
   {-3,3,2}};

static struct patval fuseki1382[] = {
   {-4,4,1},
   {3,-3,2}};

static struct patval fuseki1383[] = {
   {-4,4,1},
   {3,-3,2}};

static struct patval fuseki1384[] = {
   {-4,4,1},
   {3,-3,2}};

static struct patval fuseki1385[] = {
   {4,-3,1},
   {3,4,1},
   {-3,3,2}};

static struct patval fuseki1386[] = {
   {4,-3,1},
   {3,4,1},
   {-3,3,2}};

static struct patval fuseki1387[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,3,2}};

static struct patval fuseki1388[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,-3,2}};

static struct patval fuseki1389[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,-3,2}};

static struct patval fuseki1390[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,3,2}};

static struct patval fuseki1391[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,3,2}};

static struct patval fuseki1392[] = {
   {-3,-4,1},
   {4,-3,1},
   {3,3,2}};

static struct patval fuseki1393[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,-3,2}};

static struct patval fuseki1394[] = {
   {-4,4,1},
   {-3,-4,2}};

static struct patval fuseki1395[] = {
   {-4,-4,1},
   {4,-3,2}};

static struct patval fuseki1396[] = {
   {-4,4,1},
   {-3,-4,2}};

static struct patval fuseki1397[] = {
   {-4,-4,1},
   {-3,4,2}};

static struct patval fuseki1398[] = {
   {-4,-4,1},
   {4,-3,2}};

static struct patval fuseki1399[] = {
   {4,4,1},
   {3,-4,2}};

static struct patval fuseki13100[] = {
   {4,-4,1},
   {-4,-3,2}};

static struct patval fuseki13101[] = {
   {4,-4,1},
   {3,4,2}};

static struct patval fuseki13102[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13103[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13104[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13105[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13106[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13107[] = {
   {3,3,1},
   {3,-3,1},
   {-3,4,2}};

static struct patval fuseki13108[] = {
   {-3,3,1},
   {3,3,1},
   {4,-3,2}};

static struct patval fuseki13109[] = {
   {-3,3,1},
   {3,3,1},
   {4,-3,2}};

static struct patval fuseki13110[] = {
   {3,3,1},
   {3,-3,1},
   {-3,4,2}};

static struct patval fuseki13111[] = {
   {-3,-3,1},
   {-3,4,2}};

static struct patval fuseki13112[] = {
   {3,3,1},
   {3,-4,2}};

static struct patval fuseki13113[] = {
   {-3,-3,1},
   {-3,4,2}};

static struct patval fuseki13114[] = {
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki13115[] = {
   {3,3,1},
   {3,-4,2}};

static struct patval fuseki13116[] = {
   {-3,-3,1},
   {-3,4,2}};

static struct patval fuseki13117[] = {
   {-3,3,1},
   {-3,-4,2}};

static struct patval fuseki13118[] = {
   {-3,3,1},
   {4,3,2}};

static struct patval fuseki13119[] = {
   {-3,-3,1},
   {-3,4,2}};

static struct patval fuseki13120[] = {
   {-4,-3,1},
   {4,3,2}};

static struct patval fuseki13121[] = {
   {-3,-4,1},
   {3,4,2}};

static struct patval fuseki13122[] = {
   {-3,-4,1},
   {3,4,2}};

static struct patval fuseki13123[] = {
   {3,4,1},
   {-3,-4,2}};

static struct patval fuseki13124[] = {
   {4,3,1},
   {-4,-3,2}};

static struct patval fuseki13125[] = {
   {-3,4,1},
   {3,-4,2}};

static struct patval fuseki13126[] = {
   {4,3,1},
   {-4,-3,2}};

static struct patval fuseki13127[] = {
   {-4,-3,1},
   {4,3,2}};

static struct patval fuseki13128[] = {
   {3,4,1},
   {-4,-3,2}};

static struct patval fuseki13129[] = {
   {-4,3,1},
   {3,-4,2}};

static struct patval fuseki13130[] = {
   {-3,-4,1},
   {4,3,2}};

static struct patval fuseki13131[] = {
   {4,-3,1},
   {-3,4,2}};

static struct patval fuseki13132[] = {
   {3,-4,1},
   {-4,3,2}};

static struct patval fuseki13133[] = {
   {-4,-3,1},
   {3,4,2}};

static struct patval fuseki13134[] = {
   {4,-3,1},
   {-3,4,2}};

static struct patval fuseki13135[] = {
   {-3,-4,1},
   {4,3,2}};

static struct patval fuseki13136[] = {
   {4,-4,1},
   {-3,4,2}};

static struct patval fuseki13137[] = {
   {-4,4,1},
   {3,-4,2}};

static struct patval fuseki13138[] = {
   {-4,4,1},
   {3,-4,2}};

static struct patval fuseki13139[] = {
   {-4,-4,1},
   {4,3,2}};

static struct patval fuseki13140[] = {
   {-4,4,1},
   {4,-3,2}};

static struct patval fuseki13141[] = {
   {4,4,1},
   {-4,-3,2}};

static struct patval fuseki13142[] = {
   {4,4,1},
   {-3,-4,2}};

static struct patval fuseki13143[] = {
   {4,4,1},
   {-4,-3,2}};

static struct patval fuseki13144[] = {
   {3,-3,1},
   {-3,-3,1},
   {-4,4,2}};

static struct patval fuseki13145[] = {
   {3,3,1},
   {3,-3,1},
   {-4,4,2}};

static struct patval fuseki13146[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-4,2}};

static struct patval fuseki13147[] = {
   {3,3,1},
   {3,-3,1},
   {-4,-4,2}};

static struct patval fuseki13148[] = {
   {-4,3,1},
   {-3,-4,2}};

static struct patval fuseki13149[] = {
   {-3,-4,1},
   {4,-3,2}};

static struct patval fuseki13150[] = {
   {3,4,1},
   {-4,3,2}};

static struct patval fuseki13151[] = {
   {-3,4,1},
   {4,3,2}};

static struct patval fuseki13152[] = {
   {-3,-3,1},
   {4,-3,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13153[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13154[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13155[] = {
   {3,4,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13156[] = {
   {-4,3,1},
   {3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13157[] = {
   {-3,-3,1},
   {-3,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13158[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13159[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13160[] = {
   {3,4,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13161[] = {
   {3,4,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13162[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13163[] = {
   {-3,-3,1},
   {4,-3,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13164[] = {
   {4,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13165[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13166[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13167[] = {
   {3,3,1},
   {3,-4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13168[] = {
   {3,3,1},
   {3,-4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13169[] = {
   {4,3,1},
   {-4,-4,2}};

static struct patval fuseki13170[] = {
   {-4,-3,1},
   {4,4,2}};

static struct patval fuseki13171[] = {
   {-3,-4,1},
   {4,4,2}};

static struct patval fuseki13172[] = {
   {-3,-4,1},
   {4,4,2}};

static struct patval fuseki13173[] = {
   {-4,-3,1},
   {4,4,2}};

static struct patval fuseki13174[] = {
   {4,1,1},
   {3,3,2}};

static struct patval fuseki13175[] = {
   {4,1,1},
   {3,3,2}};

static struct patval fuseki13176[] = {
   {-1,-4,1},
   {-3,-3,2}};

static struct patval fuseki13177[] = {
   {-1,-4,1},
   {-3,-3,2}};

static struct patval fuseki13178[] = {
   {-1,-4,1},
   {-3,-3,2}};

static struct patval fuseki13179[] = {
   {-1,-4,1},
   {-3,-3,2}};

static struct patval fuseki13180[] = {
   {3,4,1},
   {3,-3,2}};

static struct patval fuseki13181[] = {
   {-4,3,1},
   {3,3,2}};

static struct patval fuseki13182[] = {
   {-3,4,1},
   {-3,-3,2}};

static struct patval fuseki13183[] = {
   {-3,-4,1},
   {-3,3,2}};

static struct patval fuseki13184[] = {
   {3,4,1},
   {3,-3,2}};

static struct patval fuseki13185[] = {
   {-4,3,1},
   {3,3,2}};

static struct patval fuseki13186[] = {
   {-3,4,1},
   {-3,-3,2}};

static struct patval fuseki13187[] = {
   {4,-3,1},
   {-3,-3,2}};

static struct patval fuseki13188[] = {
   {3,4,1},
   {3,-3,2}};

static struct patval fuseki13189[] = {
   {-3,4,1},
   {-3,-3,2}};

static struct patval fuseki13190[] = {
   {4,-3,1},
   {-3,-3,2}};

static struct patval fuseki13191[] = {
   {3,4,1},
   {3,-3,2}};

static struct patval fuseki13192[] = {
   {-4,-3,1},
   {3,-3,2}};

static struct patval fuseki13193[] = {
   {-3,3,1},
   {3,3,1},
   {3,-4,2}};

static struct patval fuseki13194[] = {
   {3,3,1},
   {3,-3,1},
   {-4,3,2}};

static struct patval fuseki13195[] = {
   {-3,3,1},
   {3,3,1},
   {3,-4,2}};

static struct patval fuseki13196[] = {
   {-3,-3,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki13197[] = {
   {3,3,1},
   {3,-3,1},
   {-4,-3,2}};

static struct patval fuseki13198[] = {
   {3,3,1},
   {-4,-4,2}};

static struct patval fuseki13199[] = {
   {3,3,1},
   {-4,-4,2}};

static struct patval fuseki13200[] = {
   {3,3,1},
   {-4,-4,2}};

static struct patval fuseki13201[] = {
   {-4,-4,1},
   {4,-4,1},
   {4,4,2}};

static struct patval fuseki13202[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,4,2}};

static struct patval fuseki13203[] = {
   {3,3,1},
   {3,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13204[] = {
   {3,3,1},
   {-3,3,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki13205[] = {
   {3,3,1},
   {3,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13206[] = {
   {3,3,1},
   {-3,4,2}};

static struct patval fuseki13207[] = {
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki13208[] = {
   {-3,3,1},
   {3,4,2}};

static struct patval fuseki13209[] = {
   {4,2,1}};

static struct patval fuseki13210[] = {
   {-2,-4,1}};

static struct patval fuseki13211[] = {
   {2,4,1}};

static struct patval fuseki13212[] = {
   {-2,-4,1}};

static struct patval fuseki13213[] = {
   {-4,2,1}};

static struct patval fuseki13214[] = {
   {-2,-4,1}};

static struct patval fuseki13215[] = {
   {-2,-4,1}};

static struct patval fuseki13216[] = {
   {-2,4,1}};

static struct patval fuseki13217[] = {
   {4,3,1},
   {-3,4,1},
   {-3,-3,2}};

static struct patval fuseki13218[] = {
   {-4,-3,1},
   {3,-4,1},
   {3,3,2}};

static struct patval fuseki13219[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,3,2}};

static struct patval fuseki13220[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,3,2}};

static struct patval fuseki13221[] = {
   {4,3,1},
   {3,-4,1},
   {-3,3,2}};

static struct patval fuseki13222[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,3,2}};

static struct patval fuseki13223[] = {
   {-4,-3,1},
   {3,-4,1},
   {3,3,2}};

static struct patval fuseki13224[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,3,2}};

static struct patval fuseki13225[] = {
   {4,3,1},
   {-3,4,1},
   {-3,-3,2}};

static struct patval fuseki13226[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,3,2}};

static struct patval fuseki13227[] = {
   {-4,3,1},
   {3,4,1},
   {3,-4,2}};

static struct patval fuseki13228[] = {
   {4,3,1},
   {-3,4,1},
   {-3,-4,2}};

static struct patval fuseki13229[] = {
   {-4,3,1},
   {3,4,1},
   {3,-4,2}};

static struct patval fuseki13230[] = {
   {4,3,1},
   {-3,4,1},
   {-3,-4,2}};

static struct patval fuseki13231[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,3,2}};

static struct patval fuseki13232[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,3,2}};

static struct patval fuseki13233[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,3,2}};

static struct patval fuseki13234[] = {
   {-4,3,1},
   {3,4,1},
   {3,-4,2}};

static struct patval fuseki13235[] = {
   {2,3,1}};

static struct patval fuseki13236[] = {
   {-2,-3,1}};

static struct patval fuseki13237[] = {
   {-2,3,1}};

static struct patval fuseki13238[] = {
   {4,-4,1},
   {3,4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13239[] = {
   {4,-4,1},
   {3,4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13240[] = {
   {-4,3,1},
   {4,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13241[] = {
   {-4,-4,1},
   {4,-3,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13242[] = {
   {-4,3,1},
   {4,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13243[] = {
   {4,-4,1},
   {3,4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13244[] = {
   {4,-4,1},
   {3,4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13245[] = {
   {-4,3,1},
   {4,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13246[] = {
   {4,-4,1},
   {3,4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13247[] = {
   {4,4,1},
   {3,-4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13248[] = {
   {4,-4,1},
   {3,4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13249[] = {
   {-4,3,1},
   {4,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13250[] = {
   {-4,-3,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13251[] = {
   {-4,-4,1},
   {-3,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13252[] = {
   {-4,-3,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13253[] = {
   {4,4,1},
   {-4,-4,2}};

static struct patval fuseki13254[] = {
   {3,4,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki13255[] = {
   {3,3,1},
   {3,-4,1},
   {-3,-3,2}};

static struct patval fuseki13256[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,2}};

static struct patval fuseki13257[] = {
   {-3,3,1},
   {4,3,1},
   {3,-3,2}};

static struct patval fuseki13258[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki13259[] = {
   {-3,-3,1},
   {4,-3,1},
   {3,3,2}};

static struct patval fuseki13260[] = {
   {-4,3,1},
   {3,3,1},
   {-3,-3,2}};

static struct patval fuseki13261[] = {
   {3,4,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki13262[] = {
   {-3,3,1},
   {4,3,1},
   {3,-3,2}};

static struct patval fuseki13263[] = {
   {-4,-3,1},
   {3,-4,1},
   {4,3,2}};

static struct patval fuseki13264[] = {
   {4,-3,1},
   {-3,-4,1},
   {-4,3,2}};

static struct patval fuseki13265[] = {
   {4,3,1},
   {-3,4,1},
   {-4,-3,2}};

static struct patval fuseki13266[] = {
   {4,-3,1},
   {3,4,1},
   {-3,-4,2}};

static struct patval fuseki13267[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,4,2}};

static struct patval fuseki13268[] = {
   {-4,3,1},
   {3,4,1},
   {4,-3,2}};

static struct patval fuseki13269[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,4,2}};

static struct patval fuseki13270[] = {
   {-4,4,1},
   {4,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13271[] = {
   {-4,4,1},
   {4,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13272[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13273[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13274[] = {
   {-4,4,1},
   {4,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13275[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13276[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13277[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13278[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13279[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13280[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13281[] = {
   {-4,4,1},
   {4,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13282[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13283[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki13284[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki13285[] = {
   {-4,4,1},
   {4,4,1},
   {3,-4,2},
   {-3,-3,2}};

static struct patval fuseki13286[] = {
   {-4,4,1},
   {4,4,1},
   {3,-3,2},
   {-3,-4,2}};

static struct patval fuseki13287[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki13288[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki13289[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki13290[] = {
   {-4,4,1},
   {4,4,1},
   {3,-4,2},
   {-3,-3,2}};

static struct patval fuseki13291[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki13292[] = {
   {-4,4,1},
   {4,4,1},
   {3,-4,2},
   {-3,-3,2}};

static struct patval fuseki13293[] = {
   {-4,4,1},
   {4,4,1},
   {3,-4,2},
   {-3,-3,2}};

static struct patval fuseki13294[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki13295[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki13296[] = {
   {4,4,1},
   {4,-4,1},
   {-3,3,2}};

static struct patval fuseki13297[] = {
   {-4,4,1},
   {4,4,1},
   {3,-3,2}};

static struct patval fuseki13298[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-3,2}};

static struct patval fuseki13299[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,3,2}};

static struct patval fuseki13300[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-3,2}};

static struct patval fuseki13301[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-3,2}};

static struct patval fuseki13302[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-3,2}};

static struct patval fuseki13303[] = {
   {-4,1,1},
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13304[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13305[] = {
   {-4,1,1},
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13306[] = {
   {-4,-1,1},
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13307[] = {
   {3,3,1},
   {3,-3,1},
   {-1,4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13308[] = {
   {-4,-1,1},
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13309[] = {
   {4,-1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13310[] = {
   {-4,-1,1},
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13311[] = {
   {4,-1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13312[] = {
   {-4,-1,1},
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13313[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13314[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13315[] = {
   {-3,-3,1},
   {3,-4,1},
   {3,3,2}};

static struct patval fuseki13316[] = {
   {-3,3,1},
   {3,4,1},
   {3,-3,2}};

static struct patval fuseki13317[] = {
   {4,3,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki13318[] = {
   {4,3,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki13319[] = {
   {4,3,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki13320[] = {
   {-3,3,1},
   {3,4,1},
   {3,-3,2}};

static struct patval fuseki13321[] = {
   {-3,-4,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki13322[] = {
   {4,-3,1},
   {3,3,1},
   {-3,-3,2}};

static struct patval fuseki13323[] = {
   {4,4,1},
   {4,-4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki13324[] = {
   {-4,-4,1},
   {4,-4,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki13325[] = {
   {-4,-4,1},
   {4,-4,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki13326[] = {
   {4,4,1},
   {-4,4,1},
   {4,-4,2},
   {-4,-4,2}};

static struct patval fuseki13327[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki13328[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki13329[] = {
   {-4,-4,1},
   {4,-4,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki13330[] = {
   {4,4,1},
   {-4,4,1},
   {4,-4,2},
   {-4,-4,2}};

static struct patval fuseki13331[] = {
   {4,4,1},
   {-4,4,1},
   {4,-4,2},
   {-4,-4,2}};

static struct patval fuseki13332[] = {
   {0,0,1}};

static struct patval fuseki13333[] = {
   {0,0,1}};

static struct patval fuseki13334[] = {
   {0,0,1}};

static struct patval fuseki13335[] = {
   {0,0,1}};

static struct patval fuseki13336[] = {
   {0,0,1}};

static struct patval fuseki13337[] = {
   {0,0,1}};

static struct patval fuseki13338[] = {
   {-3,-4,1},
   {4,-3,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13339[] = {
   {-4,-3,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13340[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13341[] = {
   {4,3,1},
   {3,-4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13342[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13343[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13344[] = {
   {4,3,1},
   {3,-4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13345[] = {
   {-4,-3,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13346[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13347[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13348[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13349[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-4,2}};

static struct patval fuseki13350[] = {
   {3,3,1},
   {3,-4,1},
   {-3,-4,2}};

static struct patval fuseki13351[] = {
   {3,3,1},
   {3,-4,1},
   {-3,-4,2}};

static struct patval fuseki13352[] = {
   {3,3,1},
   {3,-4,1},
   {-3,-4,2}};

static struct patval fuseki13353[] = {
   {3,3,1},
   {3,-4,1},
   {-3,-4,2}};

static struct patval fuseki13354[] = {
   {-3,-3,1},
   {4,-3,1},
   {4,3,2}};

static struct patval fuseki13355[] = {
   {-3,3,1},
   {4,3,1},
   {4,-3,2}};

static struct patval fuseki13356[] = {
   {3,-3,1},
   {-3,3,1},
   {-3,-3,2}};

static struct patval fuseki13357[] = {
   {-3,-3,1},
   {3,3,1},
   {-3,3,2}};

static struct patval fuseki13358[] = {
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki13359[] = {
   {3,4,1},
   {3,-3,1},
   {-4,4,2}};

static struct patval fuseki13360[] = {
   {3,4,1},
   {3,-3,1},
   {-4,4,2}};

static struct patval fuseki13361[] = {
   {-3,3,1},
   {4,3,1},
   {4,-4,2}};

static struct patval fuseki13362[] = {
   {-3,3,1},
   {4,3,1},
   {4,-4,2}};

static struct patval fuseki13363[] = {
   {3,3,1},
   {3,-4,1},
   {-4,-4,2}};

static struct patval fuseki13364[] = {
   {-3,3,1},
   {4,3,1},
   {4,-4,2}};

static struct patval fuseki13365[] = {
   {3,-4,1},
   {-3,-3,1},
   {-4,4,2}};

static struct patval fuseki13366[] = {
   {4,3,1},
   {3,-3,1},
   {-4,-4,2}};

static struct patval fuseki13367[] = {
   {-3,4,1},
   {3,3,1},
   {4,-4,2}};

static struct patval fuseki13368[] = {
   {-3,3,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki13369[] = {
   {3,-3,1},
   {-3,3,1},
   {-4,-3,2}};

static struct patval fuseki13370[] = {
   {3,-3,1},
   {-3,3,1},
   {-3,-4,2}};

static struct patval fuseki13371[] = {
   {3,3,1},
   {-3,-3,1},
   {-4,3,2}};

static struct patval fuseki13372[] = {
   {-3,-3,1},
   {3,3,1},
   {3,-4,2}};

static struct patval fuseki13373[] = {
   {-3,-3,1},
   {3,3,1},
   {4,-3,2}};

static struct patval fuseki13374[] = {
   {-4,-3,1},
   {-3,4,1},
   {4,-4,2}};

static struct patval fuseki13375[] = {
   {-4,-3,1},
   {3,-4,1},
   {4,4,2}};

static struct patval fuseki13376[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,4,2}};

static struct patval fuseki13377[] = {
   {-3,4,1},
   {4,3,1},
   {3,-4,2}};

static struct patval fuseki13378[] = {
   {-3,4,1},
   {4,3,1},
   {3,-4,2}};

static struct patval fuseki13379[] = {
   {4,3,1},
   {3,-4,1},
   {-4,-3,2}};

static struct patval fuseki13380[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,-3,2}};

static struct patval fuseki13381[] = {
   {-4,3,1},
   {3,4,1},
   {-3,-4,2}};

static struct patval fuseki13382[] = {
   {-4,3,1},
   {3,4,1},
   {-3,-4,2}};

static struct patval fuseki13383[] = {
   {-4,3,1},
   {3,3,1},
   {-3,-4,2},
   {4,-3,2}};

static struct patval fuseki13384[] = {
   {-4,3,1},
   {3,3,1},
   {-3,-4,2},
   {4,-3,2}};

static struct patval fuseki13385[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13386[] = {
   {-4,3,1},
   {3,3,1},
   {-3,-4,2},
   {4,-3,2}};

static struct patval fuseki13387[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki13388[] = {
   {4,-3,1},
   {-3,-3,1},
   {3,4,2},
   {-4,3,2}};

static struct patval fuseki13389[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13390[] = {
   {3,3,1},
   {3,-4,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki13391[] = {
   {-3,4,1},
   {3,3,1},
   {3,-3,2}};

static struct patval fuseki13392[] = {
   {-3,4,1},
   {3,3,1},
   {3,-3,2}};

static struct patval fuseki13393[] = {
   {4,3,1},
   {3,-3,1},
   {-3,-3,2}};

static struct patval fuseki13394[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,3,2}};

static struct patval fuseki13395[] = {
   {-3,4,1},
   {3,3,1},
   {3,-3,2}};

static struct patval fuseki13396[] = {
   {3,4,1},
   {-3,3,1},
   {-3,-3,2}};

static struct patval fuseki13397[] = {
   {-4,3,1},
   {-3,-3,1},
   {3,-3,2}};

static struct patval fuseki13398[] = {
   {3,4,1},
   {-3,3,1},
   {-3,-3,2}};

static struct patval fuseki13399[] = {
   {-3,3,1},
   {4,3,1},
   {3,-4,2}};

static struct patval fuseki13400[] = {
   {-4,3,1},
   {3,3,1},
   {-3,-4,2}};

static struct patval fuseki13401[] = {
   {3,3,1},
   {3,-4,1},
   {-4,-3,2}};

static struct patval fuseki13402[] = {
   {-3,-4,1},
   {-3,3,1},
   {4,-3,2}};

static struct patval fuseki13403[] = {
   {3,4,1},
   {3,-3,1},
   {-4,3,2}};

static struct patval fuseki13404[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13405[] = {
   {-4,4,1},
   {3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13406[] = {
   {-3,-3,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13407[] = {
   {-4,-4,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13408[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13409[] = {
   {4,-4,1},
   {3,3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13410[] = {
   {4,-4,1},
   {3,3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13411[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13412[] = {
   {-4,4,1},
   {-3,-3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13413[] = {
   {4,4,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13414[] = {
   {-3,-3,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13415[] = {
   {-4,4,1},
   {-3,-3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13416[] = {
   {-2,4,1},
   {-4,3,2}};

static struct patval fuseki13417[] = {
   {-2,4,1},
   {-4,3,2}};

static struct patval fuseki13418[] = {
   {-2,-4,1},
   {-4,-3,2}};

static struct patval fuseki13419[] = {
   {-2,-4,1},
   {-4,-3,2}};

static struct patval fuseki13420[] = {
   {2,4,1},
   {4,3,2}};

static struct patval fuseki13421[] = {
   {2,4,1},
   {4,3,2}};

static struct patval fuseki13422[] = {
   {-2,-4,1},
   {-4,-3,2}};

static struct patval fuseki13423[] = {
   {-3,-4,1},
   {-3,3,1},
   {4,4,2}};

static struct patval fuseki13424[] = {
   {3,3,1},
   {3,-4,1},
   {-4,4,2}};

static struct patval fuseki13425[] = {
   {4,3,1},
   {-3,3,1},
   {-4,-4,2}};

static struct patval fuseki13426[] = {
   {-3,-4,1},
   {-3,3,1},
   {4,4,2}};

static struct patval fuseki13427[] = {
   {-4,3,1},
   {3,3,1},
   {4,-4,2}};

static struct patval fuseki13428[] = {
   {-3,-4,1},
   {-3,3,1},
   {4,4,2}};

static struct patval fuseki13429[] = {
   {-4,4,1},
   {-4,-4,2}};

static struct patval fuseki13430[] = {
   {4,-4,1},
   {4,4,2}};

static struct patval fuseki13431[] = {
   {4,-4,1},
   {4,4,2}};

static struct patval fuseki13432[] = {
   {-4,4,1},
   {4,4,2}};

static struct patval fuseki13433[] = {
   {-4,-4,1},
   {-4,4,2}};

static struct patval fuseki13434[] = {
   {4,-4,1},
   {4,4,2}};

static struct patval fuseki13435[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13436[] = {
   {-3,-4,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13437[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13438[] = {
   {-4,4,1},
   {3,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13439[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13440[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13441[] = {
   {-4,-3,1},
   {-4,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13442[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13443[] = {
   {-3,-4,1},
   {4,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13444[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13445[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13446[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13447[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13448[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13449[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,3,2}};

static struct patval fuseki13450[] = {
   {-4,4,1},
   {4,4,1},
   {3,-4,2}};

static struct patval fuseki13451[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-3,2}};

static struct patval fuseki13452[] = {
   {-4,4,1},
   {4,4,1},
   {3,-4,2}};

static struct patval fuseki13453[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-3,2}};

static struct patval fuseki13454[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-3,2}};

static struct patval fuseki13455[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13456[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13457[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13458[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13459[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13460[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13461[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13462[] = {
   {3,4,1},
   {-4,3,1},
   {-4,-4,2}};

static struct patval fuseki13463[] = {
   {4,3,1},
   {3,-4,1},
   {-4,-4,2}};

static struct patval fuseki13464[] = {
   {4,-3,1},
   {3,4,1},
   {-4,4,2}};

static struct patval fuseki13465[] = {
   {-3,4,1},
   {4,3,1},
   {4,-4,2}};

static struct patval fuseki13466[] = {
   {-3,4,1},
   {4,3,1},
   {4,-4,2}};

static struct patval fuseki13467[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,-4,2}};

static struct patval fuseki13468[] = {
   {-3,-4,1},
   {-3,4,2}};

static struct patval fuseki13469[] = {
   {4,-3,1},
   {-4,-3,2}};

static struct patval fuseki13470[] = {
   {3,4,1},
   {3,-4,2}};

static struct patval fuseki13471[] = {
   {4,3,1},
   {-4,3,2}};

static struct patval fuseki13472[] = {
   {3,4,1},
   {3,-4,2}};

static struct patval fuseki13473[] = {
   {2,2,1}};

static struct patval fuseki13474[] = {
   {2,-2,1}};

static struct patval fuseki13475[] = {
   {2,-2,1}};

static struct patval fuseki13476[] = {
   {-2,2,1}};

static struct patval fuseki13477[] = {
   {2,2,1}};

static struct patval fuseki13478[] = {
   {2,-2,1}};

static struct patval fuseki13479[] = {
   {-2,2,1}};

static struct patval fuseki13480[] = {
   {4,4,1},
   {4,-4,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki13481[] = {
   {-4,-4,1},
   {4,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13482[] = {
   {4,4,1},
   {4,-4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13483[] = {
   {4,4,1},
   {4,-4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13484[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki13485[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,4,2},
   {-4,3,2}};

static struct patval fuseki13486[] = {
   {-4,4,1},
   {4,4,1},
   {4,-3,2},
   {-3,-4,2}};

static struct patval fuseki13487[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-4,2},
   {4,3,2}};

static struct patval fuseki13488[] = {
   {4,4,1},
   {-4,4,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki13489[] = {
   {-4,4,1},
   {3,-2,2}};

static struct patval fuseki13490[] = {
   {-4,-4,1},
   {3,2,2}};

static struct patval fuseki13491[] = {
   {-4,-4,1},
   {3,2,2}};

static struct patval fuseki13492[] = {
   {-4,-4,1},
   {2,3,2}};

static struct patval fuseki13493[] = {
   {-4,4,1},
   {3,-2,2}};

static struct patval fuseki13494[] = {
   {4,4,1},
   {-2,-3,2}};

static struct patval fuseki13495[] = {
   {-4,-4,1},
   {3,2,2}};

static struct patval fuseki13496[] = {
   {-4,4,1},
   {3,-2,2}};

static struct patval fuseki13497[] = {
   {-4,-4,1},
   {3,2,2}};

static struct patval fuseki13498[] = {
   {-4,4,1},
   {3,-2,2}};

static struct patval fuseki13499[] = {
   {3,1,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki13500[] = {
   {3,1,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki13501[] = {
   {-3,4,1},
   {4,4,2}};

static struct patval fuseki13502[] = {
   {3,4,1},
   {-4,4,2}};

static struct patval fuseki13503[] = {
   {-4,-3,1},
   {-4,4,2}};

static struct patval fuseki13504[] = {
   {-4,-3,1},
   {-4,4,2}};

static struct patval fuseki13505[] = {
   {-4,3,1},
   {-4,-4,2}};

static struct patval fuseki13506[] = {
   {-3,4,1},
   {4,4,2}};

static struct patval fuseki13507[] = {
   {-3,3,1},
   {3,4,1},
   {4,-4,2}};

static struct patval fuseki13508[] = {
   {4,-3,1},
   {3,3,1},
   {-4,-4,2}};

static struct patval fuseki13509[] = {
   {3,-3,1},
   {-3,-4,1},
   {-4,4,2}};

static struct patval fuseki13510[] = {
   {-3,-3,1},
   {3,-4,1},
   {4,4,2}};

static struct patval fuseki13511[] = {
   {3,-3,1},
   {-3,3,1},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki13512[] = {
   {-3,-3,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13513[] = {
   {-3,-3,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13514[] = {
   {-3,-3,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13515[] = {
   {3,-3,1},
   {-3,3,1},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki13516[] = {
   {-3,-3,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13517[] = {
   {3,-3,1},
   {-3,3,1},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki13518[] = {
   {3,-3,1},
   {-3,3,1},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki13519[] = {
   {-3,-4,1},
   {3,-4,2}};

static struct patval fuseki13520[] = {
   {-4,3,1},
   {-4,-3,2}};

static struct patval fuseki13521[] = {
   {3,4,1},
   {-3,4,2}};

static struct patval fuseki13522[] = {
   {3,-4,1},
   {-3,-4,2}};

static struct patval fuseki13523[] = {
   {3,-4,1},
   {-3,-4,2}};

static struct patval fuseki13524[] = {
   {4,-3,1},
   {4,3,2}};

static struct patval fuseki13525[] = {
   {4,-3,1},
   {4,3,2}};

static struct patval fuseki13526[] = {
   {3,4,1},
   {-3,4,2}};

static struct patval fuseki13527[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13528[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13529[] = {
   {-4,4,1},
   {3,4,1},
   {-3,-3,2},
   {4,-3,2}};

static struct patval fuseki13530[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13531[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13532[] = {
   {-4,-3,1},
   {-4,4,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki13533[] = {
   {-4,3,1},
   {-3,-3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13534[] = {
   {-3,-3,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13535[] = {
   {-3,-3,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13536[] = {
   {-4,3,1},
   {-3,-3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13537[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13538[] = {
   {-3,-4,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13539[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13540[] = {
   {-3,-4,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13541[] = {
   {3,4,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13542[] = {
   {4,-3,1},
   {3,3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13543[] = {
   {-3,-3,1},
   {3,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13544[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki13545[] = {
   {3,3,1},
   {-3,3,1},
   {3,-4,2},
   {-3,-3,2}};

static struct patval fuseki13546[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-4,2}};

static struct patval fuseki13547[] = {
   {3,3,1},
   {-3,3,1},
   {3,-4,2},
   {-3,-3,2}};

static struct patval fuseki13548[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,4,2}};

static struct patval fuseki13549[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki13550[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,4,2}};

static struct patval fuseki13551[] = {
   {3,3,1},
   {3,-3,1},
   {-3,3,2},
   {-4,-3,2}};

static struct patval fuseki13552[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,4,2}};

static struct patval fuseki13553[] = {
   {4,3,1},
   {3,-3,1},
   {-3,-4,2}};

static struct patval fuseki13554[] = {
   {-4,3,1},
   {-3,-3,1},
   {3,-4,2}};

static struct patval fuseki13555[] = {
   {-3,-4,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki13556[] = {
   {4,-3,1},
   {3,3,1},
   {-3,4,2}};

static struct patval fuseki13557[] = {
   {-3,4,1},
   {3,3,1},
   {4,-3,2}};

static struct patval fuseki13558[] = {
   {-2,3,1},
   {-4,3,2}};

static struct patval fuseki13559[] = {
   {-2,3,1},
   {-4,3,2}};

static struct patval fuseki13560[] = {
   {-2,-3,1},
   {-4,-3,2}};

static struct patval fuseki13561[] = {
   {-3,2,1},
   {-3,4,2}};

static struct patval fuseki13562[] = {
   {-3,-2,1},
   {-3,-4,2}};

static struct patval fuseki13563[] = {
   {2,3,1},
   {4,3,2}};

static struct patval fuseki13564[] = {
   {3,4,1},
   {3,-4,1},
   {-4,4,2}};

static struct patval fuseki13565[] = {
   {-4,-3,1},
   {4,-3,1},
   {-4,4,2}};

static struct patval fuseki13566[] = {
   {-4,-3,1},
   {4,-3,1},
   {4,4,2}};

static struct patval fuseki13567[] = {
   {-4,3,1},
   {4,3,1},
   {4,-4,2}};

static struct patval fuseki13568[] = {
   {-3,-4,1},
   {-3,4,1},
   {4,-4,2}};

static struct patval fuseki13569[] = {
   {-4,-3,1},
   {4,-3,1},
   {4,4,2}};

static struct patval fuseki13570[] = {
   {-4,-3,1},
   {4,-3,1},
   {4,4,2}};

static struct patval fuseki13571[] = {
   {-4,-3,1},
   {4,-3,1},
   {4,4,2}};

static struct patval fuseki13572[] = {
   {4,3,1},
   {-3,4,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki13573[] = {
   {4,-3,1},
   {3,4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13574[] = {
   {-4,-3,1},
   {3,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13575[] = {
   {4,-3,1},
   {3,4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13576[] = {
   {-4,-3,1},
   {3,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13577[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki13578[] = {
   {3,-2,1},
   {-3,3,2}};

static struct patval fuseki13579[] = {
   {-2,3,1},
   {3,-3,2}};

static struct patval fuseki13580[] = {
   {2,-3,1},
   {-3,3,2}};

static struct patval fuseki13581[] = {
   {-2,-3,1},
   {3,3,2}};

static struct patval fuseki13582[] = {
   {2,-3,1},
   {-3,3,2}};

static struct patval fuseki13583[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13584[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13585[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13586[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki13587[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13588[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13589[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki13590[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13591[] = {
   {4,3,1},
   {-3,3,1},
   {-4,-3,2}};

static struct patval fuseki13592[] = {
   {-4,3,1},
   {3,3,1},
   {4,-3,2}};

static struct patval fuseki13593[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,4,2}};

static struct patval fuseki13594[] = {
   {-4,-3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki13595[] = {
   {3,3,1},
   {3,-4,1},
   {-3,4,2}};

static struct patval fuseki13596[] = {
   {3,-3,1},
   {-3,3,1},
   {-4,-4,2}};

static struct patval fuseki13597[] = {
   {-3,3,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki13598[] = {
   {3,3,1},
   {-3,-3,1},
   {-4,4,2}};

static struct patval fuseki13599[] = {
   {-4,3,1},
   {-3,-3,1},
   {3,4,2}};

static struct patval fuseki13600[] = {
   {-3,3,1},
   {3,4,1},
   {4,-3,2}};

static struct patval fuseki13601[] = {
   {3,-3,1},
   {-3,-4,1},
   {-4,3,2}};

static struct patval fuseki13602[] = {
   {3,3,1},
   {-3,4,1},
   {-4,-3,2}};

static struct patval fuseki13603[] = {
   {4,-3,1},
   {3,3,1},
   {-3,-4,2}};

static struct patval fuseki13604[] = {
   {4,-3,1},
   {3,3,1},
   {-3,-4,2}};

static struct patval fuseki13605[] = {
   {-3,-4,1},
   {-4,3,2}};

static struct patval fuseki13606[] = {
   {-3,4,1},
   {-4,-3,2}};

static struct patval fuseki13607[] = {
   {-3,-4,1},
   {-4,3,2}};

static struct patval fuseki13608[] = {
   {4,3,1},
   {-3,4,2}};

static struct patval fuseki13609[] = {
   {4,3,1},
   {-3,4,2}};

static struct patval fuseki13610[] = {
   {4,-3,1},
   {-3,-4,2}};

static struct patval fuseki13611[] = {
   {4,4,1},
   {2,-4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13612[] = {
   {-4,-4,1},
   {4,-2,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13613[] = {
   {-4,4,1},
   {4,2,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13614[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13615[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13616[] = {
   {-4,-4,1},
   {-2,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13617[] = {
   {-4,4,1},
   {-3,-3,1},
   {3,3,2}};

static struct patval fuseki13618[] = {
   {-4,4,1},
   {3,3,1},
   {-3,-3,2}};

static struct patval fuseki13619[] = {
   {-3,-3,1},
   {4,-4,1},
   {3,3,2}};

static struct patval fuseki13620[] = {
   {-4,4,1},
   {3,3,1},
   {-3,-3,2}};

static struct patval fuseki13621[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,4,2}};

static struct patval fuseki13622[] = {
   {-3,-3,1},
   {-3,4,1},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki13623[] = {
   {3,3,1},
   {3,-4,1},
   {-3,-3,2},
   {-4,3,2}};

static struct patval fuseki13624[] = {
   {-4,3,1},
   {3,3,1},
   {3,-4,2},
   {-3,-3,2}};

static struct patval fuseki13625[] = {
   {-3,-3,1},
   {4,-3,1},
   {3,3,2},
   {-3,4,2}};

static struct patval fuseki13626[] = {
   {4,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-4,2}};

static struct patval fuseki13627[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki13628[] = {
   {3,4,1},
   {3,-3,1},
   {-3,3,2},
   {-4,-3,2}};

static struct patval fuseki13629[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,4,2}};

static struct patval fuseki13630[] = {
   {-4,-2,1},
   {3,-3,2}};

static struct patval fuseki13631[] = {
   {4,2,1},
   {-3,3,2}};

static struct patval fuseki13632[] = {
   {-4,2,1},
   {3,3,2}};

static struct patval fuseki13633[] = {
   {4,2,1},
   {-3,3,2}};

static struct patval fuseki13634[] = {
   {-4,-2,1},
   {3,-3,2}};

static struct patval fuseki13635[] = {
   {-2,-4,1},
   {-3,3,2}};

static struct patval fuseki13636[] = {
   {2,4,1},
   {3,-3,2}};

static struct patval fuseki13637[] = {
   {4,3,1},
   {3,-3,1},
   {-4,3,2}};

static struct patval fuseki13638[] = {
   {3,3,1},
   {-3,4,1},
   {-3,-4,2}};

static struct patval fuseki13639[] = {
   {3,3,1},
   {-3,4,1},
   {-3,-4,2}};

static struct patval fuseki13640[] = {
   {-3,3,1},
   {3,4,1},
   {3,-4,2}};

static struct patval fuseki13641[] = {
   {4,3,1},
   {3,-3,1},
   {-4,3,2}};

static struct patval fuseki13642[] = {
   {4,3,1},
   {3,-3,1},
   {-4,-3,2}};

static struct patval fuseki13643[] = {
   {-3,4,1},
   {3,3,1},
   {3,-4,2}};

static struct patval fuseki13644[] = {
   {-4,3,1},
   {-3,-3,1},
   {4,-3,2}};

static struct patval fuseki13645[] = {
   {3,4,1},
   {-3,3,1},
   {-3,-4,2}};

static struct patval fuseki13646[] = {
   {-3,4,1},
   {3,3,1},
   {3,-4,2}};

static struct patval fuseki13647[] = {
   {-3,-4,1},
   {4,-3,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13648[] = {
   {4,-3,1},
   {3,4,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki13649[] = {
   {3,4,1},
   {-4,3,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki13650[] = {
   {4,3,1},
   {3,-4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13651[] = {
   {3,4,1},
   {-4,3,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki13652[] = {
   {-4,-3,1},
   {4,-3,1},
   {3,3,2}};

static struct patval fuseki13653[] = {
   {3,4,1},
   {3,-4,1},
   {-3,3,2}};

static struct patval fuseki13654[] = {
   {3,4,1},
   {3,-4,1},
   {-3,3,2}};

static struct patval fuseki13655[] = {
   {-4,3,1},
   {4,3,1},
   {3,-3,2}};

static struct patval fuseki13656[] = {
   {3,4,1},
   {3,-4,1},
   {-3,3,2}};

static struct patval fuseki13657[] = {
   {4,1,1},
   {3,2,1},
   {3,3,2},
   {3,1,2}};

static struct patval fuseki13658[] = {
   {4,1,1},
   {3,2,1},
   {3,3,2},
   {3,1,2}};

static struct patval fuseki13659[] = {
   {-4,-3,1},
   {-4,3,1},
   {-2,4,2}};

static struct patval fuseki13660[] = {
   {-4,-3,1},
   {-4,3,1},
   {-2,4,2}};

static struct patval fuseki13661[] = {
   {-4,-3,1},
   {-4,3,1},
   {-2,4,2}};

static struct patval fuseki13662[] = {
   {-3,3,1},
   {3,2,1},
   {3,-3,2}};

static struct patval fuseki13663[] = {
   {-3,-2,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki13664[] = {
   {-3,-3,1},
   {3,-2,1},
   {3,3,2}};

static struct patval fuseki13665[] = {
   {-3,-2,1},
   {3,-3,1},
   {-3,3,2}};

static struct patval fuseki13666[] = {
   {3,3,1},
   {-3,2,1},
   {-3,-3,2}};

static struct patval fuseki13667[] = {
   {3,-3,1},
   {2,3,1},
   {-3,3,2}};

static struct patval fuseki13668[] = {
   {4,3,1},
   {3,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13669[] = {
   {4,-3,1},
   {3,3,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki13670[] = {
   {-3,-4,1},
   {3,-3,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13671[] = {
   {4,-3,1},
   {3,3,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki13672[] = {
   {4,4,1},
   {3,-4,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki13673[] = {
   {4,4,1},
   {3,-4,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki13674[] = {
   {-4,-3,1},
   {4,-4,1},
   {3,3,2},
   {-4,3,2}};

static struct patval fuseki13675[] = {
   {4,-4,1},
   {3,4,1},
   {-3,4,2},
   {-3,-3,2}};

static struct patval fuseki13676[] = {
   {-4,-3,1},
   {4,-4,1},
   {3,3,2},
   {-4,3,2}};

static struct patval fuseki13677[] = {
   {4,4,1},
   {3,-4,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki13678[] = {
   {4,4,1},
   {-4,3,1},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki13679[] = {
   {0,3,1},
   {3,3,2}};

static struct patval fuseki13680[] = {
   {3,0,1},
   {3,3,2}};

static struct patval fuseki13681[] = {
   {0,-3,1},
   {-3,-3,2}};

static struct patval fuseki13682[] = {
   {0,3,1},
   {3,3,2}};

static struct patval fuseki13683[] = {
   {0,-3,1},
   {-3,-3,2}};

static struct patval fuseki13684[] = {
   {-4,4,1},
   {-4,-3,2}};

static struct patval fuseki13685[] = {
   {4,4,1},
   {4,-3,2}};

static struct patval fuseki13686[] = {
   {-4,-4,1},
   {-4,3,2}};

static struct patval fuseki13687[] = {
   {-4,4,1},
   {-4,-3,2}};

static struct patval fuseki13688[] = {
   {-4,-4,1},
   {-4,3,2}};

static struct patval fuseki13689[] = {
   {4,4,1},
   {-3,4,2}};

static struct patval fuseki13690[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,4,2}};

static struct patval fuseki13691[] = {
   {-4,-3,1},
   {3,-4,1},
   {-4,3,2}};

static struct patval fuseki13692[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,4,2}};

static struct patval fuseki13693[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,4,2}};

static struct patval fuseki13694[] = {
   {4,3,1},
   {3,-4,1},
   {-3,-4,2}};

static struct patval fuseki13695[] = {
   {-3,-3,1},
   {4,-2,1},
   {3,3,2}};

static struct patval fuseki13696[] = {
   {-3,3,1},
   {-2,-4,1},
   {3,-3,2}};

static struct patval fuseki13697[] = {
   {-3,-3,1},
   {-2,4,1},
   {3,3,2}};

static struct patval fuseki13698[] = {
   {3,3,1},
   {2,-4,1},
   {-3,-3,2}};

static struct patval fuseki13699[] = {
   {0,0,1},
   {3,-3,2}};

static struct patval fuseki13700[] = {
   {0,0,1},
   {-3,-3,2}};

static struct patval fuseki13701[] = {
   {0,0,1},
   {3,3,2}};

static struct patval fuseki13702[] = {
   {0,0,1},
   {3,-3,2}};

static struct patval fuseki13703[] = {
   {0,0,1},
   {-3,3,2}};

static struct patval fuseki13704[] = {
   {0,0,1},
   {-3,-3,2}};

static struct patval fuseki13705[] = {
   {3,-4,1},
   {-3,-4,1},
   {-4,4,2}};

static struct patval fuseki13706[] = {
   {4,3,1},
   {4,-3,1},
   {-4,4,2}};

static struct patval fuseki13707[] = {
   {3,-4,1},
   {-3,-4,1},
   {-4,4,2}};

static struct patval fuseki13708[] = {
   {-4,-4,1},
   {3,-3,1},
   {-4,4,2}};

static struct patval fuseki13709[] = {
   {4,4,1},
   {3,-3,1},
   {-4,4,2}};

static struct patval fuseki13710[] = {
   {-4,-4,1},
   {3,-3,1},
   {-4,4,2}};

static struct patval fuseki13711[] = {
   {-4,-2,1},
   {4,-3,1},
   {-3,-4,1},
   {3,3,2},
   {-4,3,2}};

static struct patval fuseki13712[] = {
   {-4,3,1},
   {4,2,1},
   {3,4,1},
   {4,-3,2},
   {-3,-3,2}};

static struct patval fuseki13713[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13714[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13715[] = {
   {-4,3,1},
   {4,2,1},
   {3,4,1},
   {4,-3,2},
   {-3,-3,2}};

static struct patval fuseki13716[] = {
   {-4,4,1},
   {4,-4,1},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki13717[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13718[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13719[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13720[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13721[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13722[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13723[] = {
   {2,2,1},
   {3,2,1},
   {3,3,2}};

static struct patval fuseki13724[] = {
   {2,2,1},
   {3,2,1},
   {3,3,2}};

static struct patval fuseki13725[] = {
   {3,2,1},
   {3,-3,2}};

static struct patval fuseki13726[] = {
   {3,2,1},
   {3,-3,2}};

static struct patval fuseki13727[] = {
   {3,2,1},
   {3,-3,2}};

static struct patval fuseki13728[] = {
   {3,-2,1},
   {3,3,2}};

static struct patval fuseki13729[] = {
   {-3,-2,1},
   {-3,3,2}};

static struct patval fuseki13730[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,3,2},
   {3,4,2}};

static struct patval fuseki13731[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,-4,2},
   {4,3,2}};

static struct patval fuseki13732[] = {
   {-4,-3,1},
   {-4,4,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki13733[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,-4,2},
   {4,3,2}};

static struct patval fuseki13734[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,3,2},
   {3,4,2}};

static struct patval fuseki13735[] = {
   {-4,-3,1},
   {-4,3,1},
   {3,-4,1},
   {-2,4,2},
   {-3,2,2}};

static struct patval fuseki13736[] = {
   {-4,-3,1},
   {-4,3,1},
   {3,-4,1},
   {-2,4,2},
   {-3,2,2}};

static struct patval fuseki13737[] = {
   {-4,-3,1},
   {-4,3,1},
   {3,-4,1},
   {-2,4,2},
   {-3,2,2}};

static struct patval fuseki13738[] = {
   {-4,-3,1},
   {-4,3,1},
   {3,-4,1},
   {-2,4,2},
   {-3,2,2}};

static struct patval fuseki13739[] = {
   {-4,-3,1},
   {-4,3,1},
   {3,-4,1},
   {-2,4,2},
   {-3,2,2}};

static struct patval fuseki13740[] = {
   {-4,-3,1},
   {3,-4,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki13741[] = {
   {4,3,1},
   {3,-4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki13742[] = {
   {-2,4,1},
   {-3,2,1},
   {-4,3,2},
   {-4,-3,2}};

static struct patval fuseki13743[] = {
   {-3,-3,1},
   {3,-3,1},
   {-2,3,2}};

static struct patval fuseki13744[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-2,2}};

static struct patval fuseki13745[] = {
   {-3,-3,1},
   {3,-3,1},
   {2,3,2}};

static struct patval fuseki13746[] = {
   {-3,3,1},
   {3,3,1},
   {2,-3,2}};

static struct patval fuseki13747[] = {
   {-3,3,1},
   {3,3,1},
   {2,-3,2}};

static struct patval fuseki13748[] = {
   {-3,-3,1},
   {3,-3,1},
   {2,3,2}};

static struct patval fuseki13749[] = {
   {3,3,1},
   {2,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13750[] = {
   {3,2,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13751[] = {
   {-3,-3,1},
   {-2,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13752[] = {
   {-3,-3,1},
   {-2,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13753[] = {
   {-3,-2,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13754[] = {
   {-3,-3,1},
   {3,-2,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13755[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki13756[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13757[] = {
   {4,4,1},
   {4,-4,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki13758[] = {
   {-4,4,1},
   {4,4,1},
   {4,-3,2},
   {-3,-3,2}};

static struct patval fuseki13759[] = {
   {-4,-4,1},
   {4,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13760[] = {
   {-4,-4,1},
   {4,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13761[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13762[] = {
   {-4,-4,1},
   {-2,4,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki13763[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13764[] = {
   {-4,2,1},
   {4,4,1},
   {4,-3,2},
   {-3,-3,2}};

static struct patval fuseki13765[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13766[] = {
   {-4,-4,1},
   {4,-2,1},
   {3,3,2},
   {-4,3,2}};

static struct patval fuseki13767[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13768[] = {
   {-3,3,1},
   {0,0,2}};

static struct patval fuseki13769[] = {
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki13770[] = {
   {3,3,1},
   {0,0,2}};

static struct patval fuseki13771[] = {
   {-3,3,1},
   {0,0,2}};

static struct patval fuseki13772[] = {
   {3,3,1},
   {0,0,2}};

static struct patval fuseki13773[] = {
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki13774[] = {
   {-4,-3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki13775[] = {
   {-4,-3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki13776[] = {
   {-3,-3,1},
   {4,-3,1},
   {-3,3,2}};

static struct patval fuseki13777[] = {
   {-3,-3,1},
   {4,-3,1},
   {-3,3,2}};

static struct patval fuseki13778[] = {
   {-3,-3,1},
   {4,-3,1},
   {-3,3,2}};

static struct patval fuseki13779[] = {
   {3,3,1},
   {2,2,2}};

static struct patval fuseki13780[] = {
   {-3,3,1},
   {-3,4,2}};

static struct patval fuseki13781[] = {
   {-3,3,1},
   {-3,4,2}};

static struct patval fuseki13782[] = {
   {2,2,1},
   {4,1,1},
   {3,2,1},
   {3,3,2},
   {3,1,2},
   {4,2,2}};

static struct patval fuseki13783[] = {
   {2,2,1},
   {4,1,1},
   {3,2,1},
   {3,3,2},
   {3,1,2},
   {4,2,2}};

static struct patval fuseki13784[] = {
   {4,3,1},
   {-3,3,1},
   {4,-2,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki13785[] = {
   {-4,-3,1},
   {-4,2,1},
   {3,-3,1},
   {-3,4,2},
   {4,4,2}};

static struct patval fuseki13786[] = {
   {4,3,1},
   {-3,3,1},
   {4,-2,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki13787[] = {
   {3,3,1},
   {3,-4,1},
   {-2,-4,1},
   {-4,4,2},
   {-4,-3,2}};

static struct patval fuseki13788[] = {
   {4,3,1},
   {-3,3,1},
   {4,-2,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki13789[] = {
   {4,3,1},
   {-4,4,1},
   {-4,-3,2}};

static struct patval fuseki13790[] = {
   {-4,-3,1},
   {4,-4,1},
   {4,3,2}};

static struct patval fuseki13791[] = {
   {4,4,1},
   {3,-4,1},
   {-3,4,2}};

static struct patval fuseki13792[] = {
   {4,3,1},
   {-4,4,1},
   {-4,-3,2}};

static struct patval fuseki13793[] = {
   {3,3,1},
   {-4,3,1},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki13794[] = {
   {-3,-3,1},
   {4,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13795[] = {
   {-4,-3,1},
   {3,-3,1},
   {-4,3,2},
   {3,3,2}};

static struct patval fuseki13796[] = {
   {3,4,1},
   {3,-3,1},
   {-3,4,2},
   {-3,-3,2}};

static struct patval fuseki13797[] = {
   {-4,-3,1},
   {3,-3,1},
   {-4,3,2},
   {3,3,2}};

static struct patval fuseki13798[] = {
   {3,4,1},
   {3,-3,1},
   {-3,4,2},
   {-3,-3,2}};

static struct patval fuseki13799[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,-4,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki13800[] = {
   {4,-2,1},
   {-3,3,1},
   {3,3,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki13801[] = {
   {-4,-2,1},
   {3,3,1},
   {-3,3,1},
   {-3,-4,2},
   {4,-3,2}};

static struct patval fuseki13802[] = {
   {4,2,1},
   {-3,-3,1},
   {3,-3,1},
   {3,4,2},
   {-4,3,2}};

static struct patval fuseki13803[] = {
   {-4,2,1},
   {-3,-3,1},
   {3,-3,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13804[] = {
   {-4,-2,1},
   {3,3,1},
   {-3,3,1},
   {-3,-4,2},
   {4,-3,2}};

static struct patval fuseki13805[] = {
   {3,1,1},
   {4,2,1},
   {3,3,1},
   {4,1,2},
   {3,2,2}};

static struct patval fuseki13806[] = {
   {-2,4,1},
   {3,-3,2}};

static struct patval fuseki13807[] = {
   {-4,-2,1},
   {3,3,2}};

static struct patval fuseki13808[] = {
   {4,-2,1},
   {-3,3,2}};

static struct patval fuseki13809[] = {
   {-2,-4,1},
   {3,3,2}};

static struct patval fuseki13810[] = {
   {-4,2,1},
   {3,-3,2}};

static struct patval fuseki13811[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-3,2},
   {4,3,2}};

static struct patval fuseki13812[] = {
   {-4,4,1},
   {4,4,1},
   {3,-4,2},
   {-3,-4,2}};

static struct patval fuseki13813[] = {
   {-4,4,1},
   {4,4,1},
   {3,-4,2},
   {-3,-4,2}};

static struct patval fuseki13814[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-3,2},
   {4,3,2}};

static struct patval fuseki13815[] = {
   {-3,3,1},
   {3,-4,1},
   {4,4,2}};

static struct patval fuseki13816[] = {
   {-3,-3,1},
   {3,4,1},
   {4,-4,2}};

static struct patval fuseki13817[] = {
   {3,-3,1},
   {-3,4,1},
   {-4,-4,2}};

static struct patval fuseki13818[] = {
   {-3,3,1},
   {3,-4,1},
   {4,4,2}};

static struct patval fuseki13819[] = {
   {-4,-1,1},
   {3,3,1},
   {-3,3,1},
   {-3,-3,2},
   {4,-3,2}};

static struct patval fuseki13820[] = {
   {4,-1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki13821[] = {
   {3,3,1},
   {3,-3,1},
   {-1,4,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki13822[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-4,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki13823[] = {
   {4,-1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki13824[] = {
   {-4,-2,1},
   {4,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13825[] = {
   {-4,-4,1},
   {4,-2,1},
   {3,4,2},
   {-4,3,2}};

static struct patval fuseki13826[] = {
   {-4,-2,1},
   {4,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13827[] = {
   {-4,2,1},
   {4,4,1},
   {4,-3,2},
   {-3,-4,2}};

static struct patval fuseki13828[] = {
   {3,-4,1},
   {-3,4,1},
   {-4,-4,2}};

static struct patval fuseki13829[] = {
   {-4,-3,1},
   {4,3,1},
   {4,-4,2}};

static struct patval fuseki13830[] = {
   {-4,-3,1},
   {4,3,1},
   {-4,4,2}};

static struct patval fuseki13831[] = {
   {-3,-3,1},
   {4,-4,1},
   {-3,4,2}};

static struct patval fuseki13832[] = {
   {4,4,1},
   {3,-3,1},
   {-4,-3,2}};

static struct patval fuseki13833[] = {
   {4,3,1},
   {-4,3,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki13834[] = {
   {3,4,1},
   {3,-4,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki13835[] = {
   {3,4,1},
   {3,-4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13836[] = {
   {-4,-3,1},
   {4,-3,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13837[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13838[] = {
   {4,4,1},
   {4,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13839[] = {
   {4,4,1},
   {-3,4,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki13840[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13841[] = {
   {4,4,1},
   {-4,4,1},
   {4,-2,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki13842[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,-4,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki13843[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,-4,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki13844[] = {
   {3,3,1},
   {-4,4,2}};

static struct patval fuseki13845[] = {
   {-3,-3,1},
   {-4,4,2}};

static struct patval fuseki13846[] = {
   {-3,3,1},
   {4,4,2}};

static struct patval fuseki13847[] = {
   {-4,-4,1},
   {-4,4,1},
   {0,-4,1},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki13848[] = {
   {-4,-4,1},
   {-4,4,1},
   {0,-4,1},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki13849[] = {
   {-4,-4,1},
   {-4,4,1},
   {0,-4,1},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki13850[] = {
   {-4,-4,1},
   {-4,4,1},
   {0,-4,1},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki13851[] = {
   {-4,-3,1},
   {4,2,1},
   {3,-4,1},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki13852[] = {
   {-4,3,1},
   {4,-2,1},
   {3,4,1},
   {3,-4,2},
   {-3,-3,2}};

static struct patval fuseki13853[] = {
   {-4,3,1},
   {4,-2,1},
   {3,4,1},
   {3,-4,2},
   {-3,-3,2}};

static struct patval fuseki13854[] = {
   {-4,3,1},
   {-3,-4,1},
   {2,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki13855[] = {
   {-4,3,1},
   {-3,-4,1},
   {2,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki13856[] = {
   {-4,3,1},
   {-3,-4,1},
   {2,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki13857[] = {
   {-4,3,1},
   {-3,-4,1},
   {2,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki13858[] = {
   {-4,3,1},
   {4,-3,1},
   {3,4,2}};

static struct patval fuseki13859[] = {
   {-3,4,1},
   {3,-4,1},
   {4,3,2}};

static struct patval fuseki13860[] = {
   {3,-4,1},
   {-3,4,1},
   {-4,-3,2}};

static struct patval fuseki13861[] = {
   {-4,-3,1},
   {4,3,1},
   {-3,4,2}};

static struct patval fuseki13862[] = {
   {-4,3,1},
   {4,-3,1},
   {3,4,2}};

static struct patval fuseki13863[] = {
   {-3,-3,1},
   {4,3,1},
   {-3,4,2}};

static struct patval fuseki13864[] = {
   {-3,3,1},
   {3,-4,1},
   {4,3,2}};

static struct patval fuseki13865[] = {
   {3,-3,1},
   {-3,4,1},
   {-4,-3,2}};

static struct patval fuseki13866[] = {
   {3,3,1},
   {-3,-4,1},
   {-4,3,2}};

static struct patval fuseki13867[] = {
   {-4,3,1},
   {-2,4,1},
   {3,-3,2}};

static struct patval fuseki13868[] = {
   {-4,2,1},
   {-3,4,1},
   {3,-3,2}};

static struct patval fuseki13869[] = {
   {4,-2,1},
   {3,-4,1},
   {-3,3,2}};

static struct patval fuseki13870[] = {
   {-4,-3,1},
   {-2,-4,1},
   {3,3,2}};

static struct patval fuseki13871[] = {
   {-4,-3,1},
   {4,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13872[] = {
   {-4,3,1},
   {4,4,1},
   {4,-3,2},
   {-3,-3,2}};

static struct patval fuseki13873[] = {
   {-4,-3,1},
   {4,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13874[] = {
   {-4,-3,1},
   {4,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13875[] = {
   {-4,-3,1},
   {4,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki13876[] = {
   {-4,-3,1},
   {4,-3,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13877[] = {
   {-4,-3,1},
   {4,-3,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13878[] = {
   {-3,-4,1},
   {-3,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki13879[] = {
   {3,4,1},
   {3,-4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13880[] = {
   {3,3,1},
   {3,-3,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki13881[] = {
   {3,3,1},
   {-3,3,1},
   {-4,-4,2},
   {4,-4,2}};

static struct patval fuseki13882[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki13883[] = {
   {-3,-4,1},
   {4,3,1},
   {4,-3,2},
   {-3,3,2}};

static struct patval fuseki13884[] = {
   {4,-3,1},
   {-3,4,1},
   {3,4,2},
   {-3,-3,2}};

static struct patval fuseki13885[] = {
   {4,-3,1},
   {-3,4,1},
   {-3,-3,2},
   {4,3,2}};

static struct patval fuseki13886[] = {
   {4,-3,1},
   {-3,4,1},
   {-3,-3,2},
   {4,3,2}};

static struct patval fuseki13887[] = {
   {-4,3,1},
   {3,-4,1},
   {-3,-4,2},
   {3,3,2}};

static struct patval fuseki13888[] = {
   {4,-3,1},
   {-3,-4,1},
   {3,3,2},
   {-4,3,2}};

static struct patval fuseki13889[] = {
   {4,-3,1},
   {3,4,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki13890[] = {
   {4,-3,1},
   {-3,-4,1},
   {3,3,2},
   {-4,3,2}};

static struct patval fuseki13891[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki13892[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,-4,1},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki13893[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki13894[] = {
   {1,3,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki13895[] = {
   {1,3,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki13896[] = {
   {1,3,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki13897[] = {
   {3,3,1},
   {3,1,1},
   {1,4,2}};

static struct patval fuseki13898[] = {
   {-3,-4,1},
   {3,-4,1},
   {3,3,2}};

static struct patval fuseki13899[] = {
   {-4,-3,1},
   {-4,3,1},
   {3,-3,2}};

static struct patval fuseki13900[] = {
   {4,2,1},
   {-3,-3,1},
   {3,-3,1},
   {-4,3,2},
   {4,4,2}};

static struct patval fuseki13901[] = {
   {3,3,1},
   {3,-3,1},
   {-2,-4,1},
   {-3,4,2},
   {-4,-4,2}};

static struct patval fuseki13902[] = {
   {4,2,1},
   {-3,-3,1},
   {3,-3,1},
   {-4,3,2},
   {4,4,2}};

static struct patval fuseki13903[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,-4,1},
   {3,4,2},
   {4,-4,2}};

static struct patval fuseki13904[] = {
   {3,4,1},
   {3,-3,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki13905[] = {
   {-4,-3,1},
   {3,-3,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki13906[] = {
   {4,3,1},
   {3,-3,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki13907[] = {
   {-3,4,1},
   {3,-4,1},
   {3,3,2}};

static struct patval fuseki13908[] = {
   {-4,-3,1},
   {4,3,1},
   {3,-3,2}};

static struct patval fuseki13909[] = {
   {-4,3,1},
   {4,-3,1},
   {3,3,2}};

static struct patval fuseki13910[] = {
   {3,3,1},
   {3,-4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13911[] = {
   {3,3,1},
   {3,-4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13912[] = {
   {-3,-3,1},
   {4,-3,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13913[] = {
   {3,3,1},
   {-4,3,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki13914[] = {
   {-3,-3,1},
   {4,3,1},
   {3,-4,2}};

static struct patval fuseki13915[] = {
   {-4,-3,1},
   {3,3,1},
   {-3,4,2}};

static struct patval fuseki13916[] = {
   {-3,-4,1},
   {3,3,1},
   {4,-3,2}};

static struct patval fuseki13917[] = {
   {-4,-3,1},
   {3,3,1},
   {-3,4,2}};

static struct patval fuseki13918[] = {
   {3,-3,1},
   {-4,3,1},
   {-4,-4,2}};

static struct patval fuseki13919[] = {
   {3,4,1},
   {-3,-3,1},
   {-4,4,2}};

static struct patval fuseki13920[] = {
   {-4,-3,1},
   {3,3,1},
   {-4,4,2}};

static struct patval fuseki13921[] = {
   {-3,3,1},
   {4,-3,1},
   {4,4,2}};

static struct patval fuseki13922[] = {
   {-3,-4,1},
   {3,3,1},
   {-3,3,2}};

static struct patval fuseki13923[] = {
   {-3,-4,1},
   {3,3,1},
   {-3,3,2}};

static struct patval fuseki13924[] = {
   {-4,-3,1},
   {3,3,1},
   {3,-3,2}};

static struct patval fuseki13925[] = {
   {-4,-3,1},
   {4,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13926[] = {
   {-4,-3,1},
   {4,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13927[] = {
   {-4,-3,1},
   {4,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki13928[] = {
   {-4,3,1},
   {4,4,1},
   {4,-3,2},
   {-3,-4,2}};

static struct patval fuseki13929[] = {
   {4,-4,1},
   {3,4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki13930[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-3,2},
   {-4,3,2}};

static struct patval fuseki13931[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-4,2},
   {-3,3,2}};

static struct patval fuseki13932[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-3,2},
   {-3,4,2}};

static struct patval fuseki13933[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-3,2},
   {-4,3,2}};

static struct patval fuseki13934[] = {
   {-4,-4,1},
   {4,4,1},
   {4,-3,2},
   {-3,3,2}};

static struct patval fuseki13935[] = {
   {-4,3,1},
   {4,3,1},
   {3,-4,2}};

static struct patval fuseki13936[] = {
   {-3,-4,1},
   {-3,4,1},
   {4,3,2}};

static struct patval fuseki13937[] = {
   {-4,-3,1},
   {4,-3,1},
   {3,4,2}};

static struct patval fuseki13938[] = {
   {-4,3,1},
   {4,3,1},
   {-3,-4,2}};

static struct patval fuseki13939[] = {
   {-4,-3,1},
   {4,-4,1},
   {3,3,2},
   {-3,4,2}};

static struct patval fuseki13940[] = {
   {4,-4,1},
   {3,4,1},
   {-3,-3,2},
   {-4,3,2}};

static struct patval fuseki13941[] = {
   {-4,-3,1},
   {4,-4,1},
   {3,3,2},
   {-3,4,2}};

static struct patval fuseki13942[] = {
   {4,-4,1},
   {3,4,1},
   {-3,-3,2},
   {-4,3,2}};

static struct patval fuseki13943[] = {
   {-4,-3,1},
   {4,-4,1},
   {3,3,2},
   {-3,4,2}};

static struct patval fuseki13944[] = {
   {4,-4,1},
   {3,4,1},
   {-3,-3,2},
   {-4,3,2}};

static struct patval fuseki13945[] = {
   {-2,4,1},
   {3,3,2}};

static struct patval fuseki13946[] = {
   {-4,-2,1},
   {-3,3,2}};

static struct patval fuseki13947[] = {
   {-2,4,1},
   {3,3,2}};

static struct patval fuseki13948[] = {
   {-4,2,1},
   {-3,-3,2}};

static struct patval fuseki13949[] = {
   {4,-2,1},
   {3,3,2}};

static struct patval fuseki13950[] = {
   {-4,-2,1},
   {-3,3,2}};

static struct patval fuseki13951[] = {
   {-3,3,1},
   {3,2,1},
   {3,-4,2}};

static struct patval fuseki13952[] = {
   {-3,-2,1},
   {3,-3,1},
   {-3,4,2}};

static struct patval fuseki13953[] = {
   {3,-3,1},
   {2,3,1},
   {-4,3,2}};

static struct patval fuseki13954[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,1,1},
   {3,3,2},
   {3,-3,2}};

static struct patval fuseki13955[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,1,1},
   {3,3,2},
   {3,-3,2}};

static struct patval fuseki13956[] = {
   {-4,-3,1},
   {3,-4,1},
   {1,4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13957[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,1,1},
   {3,3,2},
   {3,-3,2}};

static struct patval fuseki13958[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,1,1},
   {3,3,2},
   {3,-3,2}};

static struct patval fuseki13959[] = {
   {-4,2,1},
   {3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13960[] = {
   {-3,-3,1},
   {4,-2,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13961[] = {
   {-4,-2,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13962[] = {
   {3,3,1},
   {2,-4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13963[] = {
   {-4,-2,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13964[] = {
   {4,2,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13965[] = {
   {-4,-3,1},
   {-4,4,1},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki13966[] = {
   {4,4,1},
   {-3,4,1},
   {4,-4,2},
   {-3,-3,2}};

static struct patval fuseki13967[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,4,2},
   {3,3,2}};

static struct patval fuseki13968[] = {
   {-4,-3,1},
   {-4,4,1},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki13969[] = {
   {-4,-4,1},
   {3,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13970[] = {
   {-3,-4,1},
   {4,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki13971[] = {
   {-4,3,1},
   {4,-4,1},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki13972[] = {
   {-3,-3,1},
   {4,0,1},
   {3,-3,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki13973[] = {
   {4,0,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13974[] = {
   {3,3,1},
   {3,-3,1},
   {0,-4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13975[] = {
   {-4,0,1},
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13976[] = {
   {4,0,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13977[] = {
   {3,3,1},
   {3,-3,1},
   {0,-4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki13978[] = {
   {-4,4,1},
   {3,3,1},
   {4,-4,2}};

static struct patval fuseki13979[] = {
   {4,4,1},
   {-3,3,1},
   {-4,-4,2}};

static struct patval fuseki13980[] = {
   {-4,-4,1},
   {-3,3,1},
   {4,4,2}};

static struct patval fuseki13981[] = {
   {4,4,1},
   {3,-3,1},
   {-4,-4,2}};

static struct patval fuseki13982[] = {
   {-4,2,1},
   {4,4,1},
   {4,-4,2},
   {-3,-3,2}};

static struct patval fuseki13983[] = {
   {4,2,1},
   {-4,4,1},
   {3,-3,2},
   {-4,-4,2}};

static struct patval fuseki13984[] = {
   {4,2,1},
   {-4,4,1},
   {3,-3,2},
   {-4,-4,2}};

static struct patval fuseki13985[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki13986[] = {
   {4,4,1},
   {2,-4,1},
   {-3,-3,2},
   {-4,4,2}};

static struct patval fuseki13987[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki13988[] = {
   {2,2,1},
   {2,3,1},
   {3,2,1},
   {3,3,2},
   {4,3,2}};

static struct patval fuseki13989[] = {
   {-2,3,1},
   {-3,2,1},
   {-2,2,1},
   {-3,3,2},
   {-4,3,2}};

static struct patval fuseki13990[] = {
   {4,-3,1},
   {0,0,2}};

static struct patval fuseki13991[] = {
   {-3,4,1},
   {0,0,2}};

static struct patval fuseki13992[] = {
   {-4,3,1},
   {0,0,2}};

static struct patval fuseki13993[] = {
   {3,4,1},
   {0,0,2}};

static struct patval fuseki13994[] = {
   {4,4,1},
   {-3,4,1},
   {-3,-3,2}};

static struct patval fuseki13995[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,3,2}};

static struct patval fuseki13996[] = {
   {4,4,1},
   {4,-3,1},
   {-3,-3,2}};

static struct patval fuseki13997[] = {
   {-3,-3,1},
   {3,-3,1},
   {0,3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki13998[] = {
   {3,3,1},
   {-3,3,1},
   {0,-3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki13999[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,0,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131000[] = {
   {3,3,1},
   {-3,0,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131001[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-1,1},
   {3,4,2},
   {3,-3,2}};

static struct patval fuseki131002[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,1,1},
   {3,3,2},
   {3,-4,2}};

static struct patval fuseki131003[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-1,1},
   {3,4,2},
   {3,-3,2}};

static struct patval fuseki131004[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-3,2},
   {4,4,2}};

static struct patval fuseki131005[] = {
   {4,4,1},
   {-4,4,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki131006[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-3,2},
   {4,4,2}};

static struct patval fuseki131007[] = {
   {3,-4,1},
   {4,-2,1},
   {4,4,2}};

static struct patval fuseki131008[] = {
   {4,-3,1},
   {2,-4,1},
   {-4,-4,2}};

static struct patval fuseki131009[] = {
   {-4,3,1},
   {-2,4,1},
   {4,4,2}};

static struct patval fuseki131010[] = {
   {4,-4,1},
   {3,3,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131011[] = {
   {-4,2,1},
   {-3,4,1},
   {-3,-3,2}};

static struct patval fuseki131012[] = {
   {-4,2,1},
   {-3,4,1},
   {-3,-3,2}};

static struct patval fuseki131013[] = {
   {-4,-2,1},
   {-3,-4,1},
   {-3,3,2}};

static struct patval fuseki131014[] = {
   {4,4,1},
   {-3,3,1},
   {4,-3,2},
   {-3,-3,2}};

static struct patval fuseki131015[] = {
   {-4,-4,1},
   {3,-3,1},
   {-4,3,2},
   {3,3,2}};

static struct patval fuseki131016[] = {
   {-3,-3,1},
   {4,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131017[] = {
   {4,-4,1},
   {3,3,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki131018[] = {
   {-4,4,1},
   {-3,-3,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki131019[] = {
   {4,4,1},
   {3,-4,1},
   {-3,-3,2},
   {-4,3,2}};

static struct patval fuseki131020[] = {
   {-4,-4,1},
   {-3,4,1},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki131021[] = {
   {4,4,1},
   {3,-4,1},
   {-3,-3,2},
   {-4,3,2}};

static struct patval fuseki131022[] = {
   {4,-3,1},
   {-3,3,1},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki131023[] = {
   {-4,-3,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131024[] = {
   {3,-4,1},
   {-3,3,1},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki131025[] = {
   {-4,3,1},
   {3,-3,1},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki131026[] = {
   {-4,3,1},
   {3,-3,1},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki131027[] = {
   {-4,-3,1},
   {4,-3,1},
   {3,-4,1},
   {-4,4,2},
   {4,-2,2},
   {4,4,2}};

static struct patval fuseki131028[] = {
   {-4,-4,1},
   {-4,-1,1},
   {4,-4,1},
   {-3,-1,1},
   {-4,4,2},
   {-3,1,2},
   {-4,0,2},
   {4,4,2}};

static struct patval fuseki131029[] = {
   {-4,-4,1},
   {-4,-1,1},
   {4,-4,1},
   {-3,-1,1},
   {-4,4,2},
   {-3,1,2},
   {-4,0,2},
   {4,4,2}};

static struct patval fuseki131030[] = {
   {-4,-4,1},
   {-4,-1,1},
   {4,-4,1},
   {-3,-1,1},
   {-4,4,2},
   {-3,1,2},
   {-4,0,2},
   {4,4,2}};

static struct patval fuseki131031[] = {
   {-4,-4,1},
   {-4,-1,1},
   {4,-4,1},
   {-3,-1,1},
   {-4,4,2},
   {-3,1,2},
   {-4,0,2},
   {4,4,2}};

static struct patval fuseki131032[] = {
   {-4,-4,1},
   {-4,-1,1},
   {4,-4,1},
   {-3,-1,1},
   {-4,4,2},
   {-3,1,2},
   {-4,0,2},
   {4,4,2}};

static struct patval fuseki131033[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,1,1},
   {3,3,2},
   {3,-3,2}};

static struct patval fuseki131034[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,1,1},
   {3,3,2},
   {3,-3,2}};

static struct patval fuseki131035[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,1,1},
   {3,3,2},
   {3,-3,2}};

static struct patval fuseki131036[] = {
   {-4,4,1},
   {3,4,1},
   {3,-4,2}};

static struct patval fuseki131037[] = {
   {4,4,1},
   {4,-3,1},
   {-4,-3,2}};

static struct patval fuseki131038[] = {
   {4,4,1},
   {-3,4,1},
   {-3,-4,2}};

static struct patval fuseki131039[] = {
   {-4,-4,1},
   {0,0,2}};

static struct patval fuseki131040[] = {
   {4,-4,1},
   {0,0,2}};

static struct patval fuseki131041[] = {
   {4,-4,1},
   {0,0,2}};

static struct patval fuseki131042[] = {
   {4,-4,1},
   {0,0,2}};

static struct patval fuseki131043[] = {
   {4,-4,1},
   {0,0,2}};

static struct patval fuseki131044[] = {
   {-4,-2,1},
   {4,3,1},
   {-3,4,1},
   {4,-3,2},
   {-3,-4,2}};

static struct patval fuseki131045[] = {
   {-4,3,1},
   {-3,-4,1},
   {2,4,1},
   {3,-4,2},
   {4,3,2}};

static struct patval fuseki131046[] = {
   {-4,3,1},
   {-3,-4,1},
   {2,4,1},
   {3,-4,2},
   {4,3,2}};

static struct patval fuseki131047[] = {
   {4,-4,1},
   {3,3,1},
   {-4,-3,2}};

static struct patval fuseki131048[] = {
   {-3,-3,1},
   {4,-4,1},
   {3,4,2}};

static struct patval fuseki131049[] = {
   {-3,-3,1},
   {4,-4,1},
   {3,4,2}};

static struct patval fuseki131050[] = {
   {-4,-4,1},
   {3,-4,1},
   {4,4,2}};

static struct patval fuseki131051[] = {
   {3,-3,1},
   {-3,-4,1},
   {-4,3,2},
   {3,4,2}};

static struct patval fuseki131052[] = {
   {3,-3,1},
   {-3,-4,1},
   {-4,3,2},
   {3,4,2}};

static struct patval fuseki131053[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-4,2},
   {4,3,2}};

static struct patval fuseki131054[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-4,2},
   {4,3,2}};

static struct patval fuseki131055[] = {
   {3,3,1},
   {3,0,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131056[] = {
   {3,3,1},
   {3,0,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131057[] = {
   {3,3,1},
   {3,0,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131058[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,1,1},
   {4,-4,2},
   {3,3,2}};

static struct patval fuseki131059[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-1,1},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki131060[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-1,1},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki131061[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,1,1},
   {4,-4,2},
   {3,3,2}};

static struct patval fuseki131062[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,1,1},
   {4,-4,2},
   {3,3,2}};

static struct patval fuseki131063[] = {
   {-3,1,1},
   {4,4,1},
   {-4,0,1},
   {-4,4,1},
   {-4,-4,2},
   {4,-4,2},
   {-4,-1,2}};

static struct patval fuseki131064[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131065[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131066[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131067[] = {
   {4,4,1},
   {-4,2,1},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki131068[] = {
   {4,-2,1},
   {-4,4,1},
   {4,4,1},
   {3,-2,1},
   {4,-3,2},
   {-4,-3,2},
   {3,-4,2}};

static struct patval fuseki131069[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,-4,1},
   {2,-3,1},
   {3,-4,2},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki131070[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,-4,1},
   {2,-3,1},
   {3,-4,2},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki131071[] = {
   {4,-2,1},
   {-4,4,1},
   {4,4,1},
   {3,-2,1},
   {4,-3,2},
   {-4,-3,2},
   {3,-4,2}};

static struct patval fuseki131072[] = {
   {3,-3,1},
   {-3,-2,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131073[] = {
   {3,-3,1},
   {-3,-2,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131074[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,4,2},
   {3,4,2}};

static struct patval fuseki131075[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,4,2},
   {3,4,2}};

static struct patval fuseki131076[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-3,2},
   {4,3,2}};

static struct patval fuseki131077[] = {
   {3,3,1},
   {-3,3,1},
   {3,-4,2},
   {-3,-4,2}};

static struct patval fuseki131078[] = {
   {3,3,1},
   {-3,3,1},
   {3,-4,2},
   {-3,-4,2}};

static struct patval fuseki131079[] = {
   {3,2,1},
   {-3,3,1},
   {-4,-4,2}};

static struct patval fuseki131080[] = {
   {-3,-2,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki131081[] = {
   {3,-3,1},
   {2,3,1},
   {-4,-4,2}};

static struct patval fuseki131082[] = {
   {-3,-2,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki131083[] = {
   {3,3,1},
   {-3,3,1},
   {3,0,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131084[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131085[] = {
   {3,-4,1},
   {-3,3,1},
   {-3,-3,2}};

static struct patval fuseki131086[] = {
   {-4,-3,1},
   {3,3,1},
   {-3,3,2}};

static struct patval fuseki131087[] = {
   {-3,-4,1},
   {3,3,1},
   {3,-3,2}};

static struct patval fuseki131088[] = {
   {-4,3,1},
   {3,-3,1},
   {-3,-3,2}};

static struct patval fuseki131089[] = {
   {2,3,1},
   {4,2,2}};

static struct patval fuseki131090[] = {
   {-3,-2,1},
   {-2,-4,2}};

static struct patval fuseki131091[] = {
   {-2,-3,1},
   {-4,-2,2}};

static struct patval fuseki131092[] = {
   {2,3,1},
   {4,2,2}};

static struct patval fuseki131093[] = {
   {4,4,1},
   {-4,4,1},
   {-3,1,1},
   {4,-4,2},
   {-4,-4,2}};

static struct patval fuseki131094[] = {
   {-4,-4,1},
   {4,4,1},
   {-3,4,2}};

static struct patval fuseki131095[] = {
   {-4,4,1},
   {4,-4,1},
   {3,4,2}};

static struct patval fuseki131096[] = {
   {-4,4,1},
   {4,-4,1},
   {3,4,2}};

static struct patval fuseki131097[] = {
   {-4,-4,1},
   {4,4,1},
   {-3,4,2}};

static struct patval fuseki131098[] = {
   {4,3,1},
   {3,3,1},
   {3,2,2},
   {2,2,2}};

static struct patval fuseki131099[] = {
   {-3,-3,1},
   {3,3,1},
   {-1,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131100[] = {
   {-3,-3,1},
   {4,-1,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131101[] = {
   {-3,-3,1},
   {4,-1,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131102[] = {
   {4,4,1},
   {3,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131103[] = {
   {-4,4,1},
   {3,3,1},
   {-3,-4,2},
   {4,-3,2}};

static struct patval fuseki131104[] = {
   {4,-4,1},
   {3,3,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki131105[] = {
   {4,4,1},
   {3,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131106[] = {
   {-4,-4,1},
   {3,-3,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki131107[] = {
   {3,3,1},
   {2,3,1},
   {3,1,1},
   {4,2,1},
   {2,2,2},
   {4,1,2},
   {3,2,2}};

static struct patval fuseki131108[] = {
   {3,3,1},
   {2,3,1},
   {3,1,1},
   {4,2,1},
   {2,2,2},
   {4,1,2},
   {3,2,2}};

static struct patval fuseki131109[] = {
   {4,4,1},
   {3,4,1},
   {3,3,2}};

static struct patval fuseki131110[] = {
   {-4,4,1},
   {-3,4,1},
   {-3,3,2}};

static struct patval fuseki131111[] = {
   {-4,4,1},
   {-3,4,1},
   {-3,3,2}};

static struct patval fuseki131112[] = {
   {-4,-4,1},
   {-4,3,1},
   {2,3,2},
   {3,-3,2}};

static struct patval fuseki131113[] = {
   {-4,4,1},
   {3,4,1},
   {3,-2,2},
   {-3,-3,2}};

static struct patval fuseki131114[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,2,2}};

static struct patval fuseki131115[] = {
   {-4,-4,1},
   {-4,3,1},
   {2,3,2},
   {3,-3,2}};

static struct patval fuseki131116[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,2,2}};

static struct patval fuseki131117[] = {
   {-4,-3,1},
   {-4,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131118[] = {
   {-4,-3,1},
   {-4,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131119[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,4,2},
   {3,3,2}};

static struct patval fuseki131120[] = {
   {3,3,1},
   {3,0,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki131121[] = {
   {3,3,1},
   {-3,3,1},
   {0,3,1},
   {-3,-3,2},
   {4,-3,2}};

static struct patval fuseki131122[] = {
   {3,-3,1},
   {-3,-3,1},
   {0,-3,1},
   {-4,3,2},
   {3,3,2}};

static struct patval fuseki131123[] = {
   {3,3,1},
   {3,0,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki131124[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,3,2},
   {4,3,2}};

static struct patval fuseki131125[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,3,2},
   {4,3,2}};

static struct patval fuseki131126[] = {
   {3,4,1},
   {-4,4,1},
   {-4,-3,2},
   {4,-3,2}};

static struct patval fuseki131127[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,3,2},
   {4,3,2}};

static struct patval fuseki131128[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,3,2},
   {4,3,2}};

static struct patval fuseki131129[] = {
   {-4,-4,1},
   {-4,-1,1},
   {4,-4,1},
   {-3,1,2},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki131130[] = {
   {-4,-3,1},
   {4,-4,1},
   {3,3,2},
   {-3,2,2}};

static struct patval fuseki131131[] = {
   {4,4,1},
   {3,-4,1},
   {-2,-3,2},
   {-3,3,2}};

static struct patval fuseki131132[] = {
   {-4,3,1},
   {4,4,1},
   {3,-3,2},
   {-3,-2,2}};

static struct patval fuseki131133[] = {
   {-4,3,1},
   {4,4,1},
   {3,-3,2},
   {-3,-2,2}};

static struct patval fuseki131134[] = {
   {4,-4,1},
   {3,4,1},
   {-2,3,2},
   {-3,-3,2}};

static struct patval fuseki131135[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-4,2},
   {-3,4,2}};

static struct patval fuseki131136[] = {
   {-4,-4,1},
   {4,4,1},
   {4,-3,2},
   {-4,3,2}};

static struct patval fuseki131137[] = {
   {-4,-4,1},
   {4,4,1},
   {3,-4,2},
   {-3,4,2}};

static struct patval fuseki131138[] = {
   {-4,4,1},
   {4,-4,1},
   {3,4,2},
   {-3,-4,2}};

static struct patval fuseki131139[] = {
   {4,3,1},
   {3,-3,1},
   {2,4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131140[] = {
   {4,2,1},
   {-3,3,1},
   {3,4,1},
   {4,-4,2},
   {-4,-4,2}};

static struct patval fuseki131141[] = {
   {-4,4,1},
   {4,3,1},
   {4,-3,2},
   {-3,-4,2}};

static struct patval fuseki131142[] = {
   {4,-4,1},
   {3,4,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki131143[] = {
   {-4,-3,1},
   {4,-4,1},
   {3,4,2},
   {-4,3,2}};

static struct patval fuseki131144[] = {
   {-4,-4,1},
   {-4,3,1},
   {-2,3,2}};

static struct patval fuseki131145[] = {
   {-4,-4,1},
   {-4,3,1},
   {-2,3,2}};

static struct patval fuseki131146[] = {
   {-4,-4,1},
   {-4,3,1},
   {-2,3,2}};

static struct patval fuseki131147[] = {
   {-3,-3,1},
   {4,4,1},
   {4,-3,2},
   {-3,3,2}};

static struct patval fuseki131148[] = {
   {4,-4,1},
   {-3,3,1},
   {3,3,2},
   {-3,-4,2}};

static struct patval fuseki131149[] = {
   {-3,-3,1},
   {4,4,1},
   {3,-3,2},
   {-3,4,2}};

static struct patval fuseki131150[] = {
   {-3,-3,1},
   {4,4,1},
   {4,-3,2},
   {-3,3,2}};

static struct patval fuseki131151[] = {
   {2,-3,1},
   {-3,4,2}};

static struct patval fuseki131152[] = {
   {3,-2,1},
   {-4,3,2}};

static struct patval fuseki131153[] = {
   {-2,3,1},
   {3,-4,2}};

static struct patval fuseki131154[] = {
   {4,-4,1},
   {3,3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131155[] = {
   {-3,-3,1},
   {4,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki131156[] = {
   {-3,3,1},
   {-4,4,2}};

static struct patval fuseki131157[] = {
   {-3,3,1},
   {-4,4,2}};

static struct patval fuseki131158[] = {
   {3,-3,1},
   {3,3,1},
   {4,4,2}};

static struct patval fuseki131159[] = {
   {3,-3,1},
   {3,3,1},
   {4,-4,2}};

static struct patval fuseki131160[] = {
   {-3,3,1},
   {-3,-3,1},
   {-4,-4,2}};

static struct patval fuseki131161[] = {
   {4,-4,1},
   {3,3,1},
   {-3,-3,2},
   {-4,4,2}};

static struct patval fuseki131162[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki131163[] = {
   {-4,-3,1},
   {-3,4,1},
   {-2,-4,1},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki131164[] = {
   {-4,-3,1},
   {-3,4,1},
   {-2,-4,1},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki131165[] = {
   {3,3,1},
   {0,-4,1},
   {-4,-3,2},
   {4,-3,2}};

static struct patval fuseki131166[] = {
   {-3,3,1},
   {4,0,1},
   {3,4,2},
   {3,-4,2}};

static struct patval fuseki131167[] = {
   {3,3,1},
   {0,-4,1},
   {-4,-3,2},
   {4,-3,2}};

static struct patval fuseki131168[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,4,1},
   {3,-3,2},
   {-3,-2,2}};

static struct patval fuseki131169[] = {
   {4,3,1},
   {-3,4,1},
   {3,-4,1},
   {3,-2,2},
   {-3,-3,2}};

static struct patval fuseki131170[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,4,1},
   {3,-3,2},
   {-3,-2,2}};

static struct patval fuseki131171[] = {
   {3,0,1},
   {4,1,1},
   {3,3,2},
   {3,1,2}};

static struct patval fuseki131172[] = {
   {4,1,1},
   {4,2,1},
   {3,0,1},
   {3,2,1},
   {3,1,2},
   {3,3,2},
   {2,0,2},
   {2,1,2}};

static struct patval fuseki131173[] = {
   {4,-2,1},
   {3,3,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki131174[] = {
   {-4,-2,1},
   {-3,3,1},
   {-3,-4,2},
   {4,-3,2}};

static struct patval fuseki131175[] = {
   {3,-3,1},
   {-2,-4,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki131176[] = {
   {-3,3,1},
   {2,4,1},
   {3,-4,2},
   {4,3,2}};

static struct patval fuseki131177[] = {
   {-4,2,1},
   {-3,3,1},
   {-4,3,2},
   {-3,4,2}};

static struct patval fuseki131178[] = {
   {-4,2,1},
   {-3,3,1},
   {-4,3,2},
   {-3,4,2}};

static struct patval fuseki131179[] = {
   {-3,-3,1},
   {3,0,1},
   {3,-3,1},
   {-3,3,2},
   {-3,0,2},
   {3,3,2}};

static struct patval fuseki131180[] = {
   {3,-3,1},
   {3,3,1},
   {0,3,1},
   {0,-3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki131181[] = {
   {-3,-3,1},
   {-3,0,1},
   {3,-3,1},
   {-3,3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki131182[] = {
   {3,0,1},
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2},
   {-3,0,2}};

static struct patval fuseki131183[] = {
   {3,-3,1},
   {2,4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131184[] = {
   {3,-3,1},
   {2,4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131185[] = {
   {-4,-2,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki131186[] = {
   {-2,-4,1},
   {-3,3,1},
   {-4,-3,2},
   {3,-3,2}};

static struct patval fuseki131187[] = {
   {-2,4,1},
   {3,3,1},
   {-3,2,1},
   {-4,-3,2},
   {3,-4,2},
   {-4,3,2}};

static struct patval fuseki131188[] = {
   {-1,4,1}};

static struct patval fuseki131189[] = {
   {-1,4,1}};

static struct patval fuseki131190[] = {
   {4,1,1}};

static struct patval fuseki131191[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131192[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,4,2}};

static struct patval fuseki131193[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131194[] = {
   {-4,-3,1},
   {4,-3,1},
   {-4,3,2}};

static struct patval fuseki131195[] = {
   {4,3,1},
   {-4,3,1},
   {-4,-3,2}};

static struct patval fuseki131196[] = {
   {-4,-3,1},
   {4,-3,1},
   {4,3,2}};

static struct patval fuseki131197[] = {
   {3,-3,1},
   {2,3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131198[] = {
   {-3,3,1},
   {-2,-3,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki131199[] = {
   {-3,-2,1},
   {3,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131200[] = {
   {-3,-2,1},
   {3,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131201[] = {
   {-3,-3,1},
   {-2,3,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131202[] = {
   {3,3,1},
   {3,-3,1},
   {-3,-3,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131203[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki131204[] = {
   {4,-2,1},
   {-3,-3,1},
   {3,3,1},
   {3,-4,2},
   {-4,4,2}};

static struct patval fuseki131205[] = {
   {4,2,1},
   {-3,3,1},
   {3,-3,1},
   {3,4,2},
   {-4,-4,2}};

static struct patval fuseki131206[] = {
   {3,3,1},
   {-3,-3,1},
   {2,-4,1},
   {-4,4,2},
   {4,-3,2}};

static struct patval fuseki131207[] = {
   {3,-2,1},
   {-4,4,2}};

static struct patval fuseki131208[] = {
   {-3,2,1},
   {4,-4,2}};

static struct patval fuseki131209[] = {
   {3,-2,1},
   {-4,4,2}};

static struct patval fuseki131210[] = {
   {-4,-3,1},
   {-4,3,1},
   {3,-4,2}};

static struct patval fuseki131211[] = {
   {-3,-4,1},
   {3,-4,1},
   {4,3,2}};

static struct patval fuseki131212[] = {
   {3,-3,1},
   {3,3,1},
   {-3,-2,1},
   {-2,4,2},
   {-4,3,2},
   {-3,-4,2}};

static struct patval fuseki131213[] = {
   {3,-3,1},
   {3,3,1},
   {-3,-2,1},
   {-2,4,2},
   {-4,3,2},
   {-3,-4,2}};

static struct patval fuseki131214[] = {
   {4,3,1},
   {3,-3,1},
   {1,4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131215[] = {
   {4,-3,1},
   {3,3,1},
   {2,-4,1},
   {-4,3,2},
   {-4,-4,2}};

static struct patval fuseki131216[] = {
   {3,3,1},
   {-4,2,1},
   {-3,4,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki131217[] = {
   {-3,-4,1},
   {4,2,2}};

static struct patval fuseki131218[] = {
   {3,4,1},
   {-4,-2,2}};

static struct patval fuseki131219[] = {
   {-4,-3,1},
   {2,4,2}};

static struct patval fuseki131220[] = {
   {3,-4,1},
   {-4,2,2}};

static struct patval fuseki131221[] = {
   {-4,-3,1},
   {3,-4,1},
   {-3,4,2},
   {3,3,2}};

static struct patval fuseki131222[] = {
   {-4,-3,1},
   {3,-4,1},
   {-3,4,2},
   {3,3,2}};

static struct patval fuseki131223[] = {
   {4,3,1},
   {3,-4,1},
   {-3,3,2},
   {-4,-3,2}};

static struct patval fuseki131224[] = {
   {-4,3,1},
   {3,4,1},
   {3,-3,2},
   {-3,-4,2}};

static struct patval fuseki131225[] = {
   {3,3,1},
   {-2,-4,2}};

static struct patval fuseki131226[] = {
   {3,3,1},
   {-4,-2,2}};

static struct patval fuseki131227[] = {
   {3,-3,1},
   {-4,2,2}};

static struct patval fuseki131228[] = {
   {-3,3,1},
   {2,-4,2}};

static struct patval fuseki131229[] = {
   {3,2,1},
   {3,0,1},
   {4,1,1},
   {2,0,2},
   {3,3,2},
   {3,1,2}};

static struct patval fuseki131230[] = {
   {2,0,1},
   {2,1,1},
   {2,2,1},
   {3,3,1},
   {3,1,1},
   {3,2,2},
   {3,0,2},
   {4,1,2},
   {4,2,2}};

static struct patval fuseki131231[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki131232[] = {
   {-4,-2,1},
   {3,3,1},
   {3,-3,1},
   {-2,4,2},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131233[] = {
   {3,-3,1},
   {-3,-3,1},
   {-2,4,1},
   {-4,3,2},
   {3,4,2},
   {4,2,2}};

static struct patval fuseki131234[] = {
   {-4,-2,1},
   {-3,4,2}};

static struct patval fuseki131235[] = {
   {-4,-2,1},
   {-3,4,2}};

static struct patval fuseki131236[] = {
   {-4,-2,1},
   {-3,4,2}};

static struct patval fuseki131237[] = {
   {-4,3,1},
   {-3,4,1},
   {-3,3,2}};

static struct patval fuseki131238[] = {
   {3,3,1},
   {3,-3,1},
   {-4,-2,2}};

static struct patval fuseki131239[] = {
   {3,3,1},
   {3,-3,1},
   {-4,2,2}};

static struct patval fuseki131240[] = {
   {-3,3,1},
   {3,3,1},
   {2,-4,2}};

static struct patval fuseki131241[] = {
   {-4,4,1},
   {4,3,1},
   {3,-3,2}};

static struct patval fuseki131242[] = {
   {-4,4,1},
   {4,3,1},
   {3,-3,2}};

static struct patval fuseki131243[] = {
   {-4,-4,1},
   {4,-3,1},
   {3,3,2}};

static struct patval fuseki131244[] = {
   {3,-4,1},
   {-3,-3,1},
   {0,-3,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki131245[] = {
   {3,4,1},
   {-3,3,1},
   {0,3,1},
   {-4,-4,2},
   {4,-4,2}};

static struct patval fuseki131246[] = {
   {-5,-4,1},
   {-4,-2,1},
   {4,-4,1},
   {-3,4,2},
   {-3,-4,2},
   {4,3,2}};

static struct patval fuseki131247[] = {
   {-5,-4,1},
   {-4,-2,1},
   {4,-4,1},
   {-3,4,2},
   {-3,-4,2},
   {4,3,2}};

static struct patval fuseki131248[] = {
   {3,3,1},
   {3,-3,1},
   {-3,3,2},
   {-4,-4,2}};

static struct patval fuseki131249[] = {
   {3,-3,1},
   {-3,-3,1},
   {-4,4,2},
   {3,3,2}};

static struct patval fuseki131250[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki131251[] = {
   {3,3,1},
   {3,-3,1},
   {-3,3,2},
   {-4,-4,2}};

static struct patval fuseki131252[] = {
   {-3,-3,1},
   {3,4,1},
   {-3,4,2}};

static struct patval fuseki131253[] = {
   {-3,4,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki131254[] = {
   {3,-3,1},
   {-4,3,1},
   {-4,-3,2}};

static struct patval fuseki131255[] = {
   {-4,4,1},
   {-3,-3,1},
   {3,4,2}};

static struct patval fuseki131256[] = {
   {-4,4,1},
   {-3,-3,1},
   {3,4,2}};

static struct patval fuseki131257[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,-4,2}};

static struct patval fuseki131258[] = {
   {4,4,1},
   {3,-3,1},
   {-3,4,2}};

static struct patval fuseki131259[] = {
   {-3,3,1},
   {-4,2,1},
   {3,3,1},
   {-4,1,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131260[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {-1,-4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131261[] = {
   {-4,-2,1},
   {3,-3,1},
   {-3,-3,1},
   {-3,3,2},
   {-4,-1,2},
   {3,3,2}};

static struct patval fuseki131262[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,2,2}};

static struct patval fuseki131263[] = {
   {3,3,1},
   {3,-3,1},
   {-2,3,2},
   {-3,-3,2}};

static struct patval fuseki131264[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-2,2}};

static struct patval fuseki131265[] = {
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,2,2}};

static struct patval fuseki131266[] = {
   {-3,-3,1},
   {-3,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131267[] = {
   {3,4,1},
   {3,-3,1},
   {-3,-3,2},
   {-4,3,2}};

static struct patval fuseki131268[] = {
   {4,3,1},
   {-3,3,1},
   {3,-4,2},
   {-3,-3,2}};

static struct patval fuseki131269[] = {
   {4,3,1},
   {-3,-4,1},
   {-3,4,1},
   {4,-4,2},
   {-4,-2,2}};

static struct patval fuseki131270[] = {
   {-5,1,1},
   {-4,-3,1},
   {-4,3,1},
   {3,-4,1},
   {-2,4,2},
   {-3,2,2},
   {3,3,2}};

static struct patval fuseki131271[] = {
   {-5,1,1},
   {-4,-3,1},
   {-4,3,1},
   {3,-4,1},
   {-2,4,2},
   {-3,2,2},
   {3,3,2}};

static struct patval fuseki131272[] = {
   {-4,2,1},
   {-3,-3,1},
   {-3,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131273[] = {
   {4,3,1},
   {-3,3,1},
   {2,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131274[] = {
   {-3,-3,1},
   {4,-3,1},
   {2,-4,1},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki131275[] = {
   {-4,2,1},
   {-3,-3,1},
   {-3,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131276[] = {
   {-3,3,1},
   {3,3,1},
   {-3,1,1},
   {-4,1,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131277[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,-3,1},
   {-1,-4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131278[] = {
   {3,-3,1},
   {3,3,1},
   {1,3,1},
   {1,4,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki131279[] = {
   {-3,-2,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki131280[] = {
   {-3,3,1},
   {-2,-3,1},
   {3,3,2}};

static struct patval fuseki131281[] = {
   {3,-3,1},
   {2,3,1},
   {-3,-3,2}};

static struct patval fuseki131282[] = {
   {-3,-3,1},
   {-2,3,1},
   {3,-3,2}};

static struct patval fuseki131283[] = {
   {-3,3,1},
   {3,3,1},
   {0,3,2}};

static struct patval fuseki131284[] = {
   {-3,-4,1},
   {4,-3,1},
   {3,3,2},
   {-3,4,2}};

static struct patval fuseki131285[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131286[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki131287[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki131288[] = {
   {2,0,1},
   {2,1,1},
   {3,3,1},
   {3,1,1},
   {3,2,2},
   {3,0,2},
   {4,1,2}};

static struct patval fuseki131289[] = {
   {-3,-4,1},
   {-3,3,1},
   {2,4,2},
   {3,-3,2}};

static struct patval fuseki131290[] = {
   {4,3,1},
   {-3,3,1},
   {3,-3,2},
   {-4,-2,2}};

static struct patval fuseki131291[] = {
   {-4,3,1},
   {3,3,1},
   {-3,-3,2},
   {4,-2,2}};

static struct patval fuseki131292[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,3,2},
   {4,2,2}};

static struct patval fuseki131293[] = {
   {-3,-3,1},
   {-2,3,1},
   {3,4,2}};

static struct patval fuseki131294[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-4,2},
   {3,4,2}};

static struct patval fuseki131295[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-4,2},
   {3,4,2}};

static struct patval fuseki131296[] = {
   {-4,-3,1},
   {4,-2,1},
   {3,-4,1},
   {-4,3,2},
   {4,3,2}};

static struct patval fuseki131297[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-4,2},
   {3,4,2}};

static struct patval fuseki131298[] = {
   {-4,-3,1},
   {-4,3,1},
   {-2,3,2}};

static struct patval fuseki131299[] = {
   {-4,-3,1},
   {-4,3,1},
   {-2,3,2}};

static struct patval fuseki131300[] = {
   {-4,-3,1},
   {-4,3,1},
   {-2,3,2}};

static struct patval fuseki131301[] = {
   {-4,-3,1},
   {4,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131302[] = {
   {-3,-4,1},
   {3,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131303[] = {
   {2,3,1},
   {3,-3,2}};

static struct patval fuseki131304[] = {
   {3,2,1},
   {-3,3,2}};

static struct patval fuseki131305[] = {
   {-3,-2,1},
   {3,-3,2}};

static struct patval fuseki131306[] = {
   {-4,3,1},
   {-3,-3,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131307[] = {
   {4,-3,1},
   {3,3,1},
   {-3,3,2},
   {-4,-3,2}};

static struct patval fuseki131308[] = {
   {-3,-4,1},
   {3,-3,1},
   {-3,4,2},
   {3,3,2}};

static struct patval fuseki131309[] = {
   {4,-3,1},
   {3,3,1},
   {-3,3,2},
   {-4,-3,2}};

static struct patval fuseki131310[] = {
   {4,3,1},
   {-3,3,1},
   {4,-4,2},
   {-4,-3,2}};

static struct patval fuseki131311[] = {
   {-4,-3,1},
   {3,-3,1},
   {-4,4,2},
   {4,3,2}};

static struct patval fuseki131312[] = {
   {-4,-3,1},
   {3,-3,1},
   {-4,4,2},
   {4,3,2}};

static struct patval fuseki131313[] = {
   {-3,-3,1},
   {4,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131314[] = {
   {4,-4,1},
   {-3,3,1},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki131315[] = {
   {-4,-4,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131316[] = {
   {-4,-4,1},
   {-4,4,1},
   {1,-4,1},
   {1,4,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131317[] = {
   {-4,-4,1},
   {-4,4,1},
   {1,4,1},
   {1,-4,2},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki131318[] = {
   {-4,-4,1},
   {-4,4,1},
   {1,-4,1},
   {1,4,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131319[] = {
   {4,2,1},
   {3,-3,1},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki131320[] = {
   {-3,3,1},
   {2,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131321[] = {
   {4,2,1},
   {3,-3,1},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki131322[] = {
   {-3,3,1},
   {2,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131323[] = {
   {4,4,1},
   {3,-4,1},
   {-4,3,2},
   {-4,-3,2}};

static struct patval fuseki131324[] = {
   {-4,4,1},
   {4,3,1},
   {3,-4,2},
   {-3,-4,2}};

static struct patval fuseki131325[] = {
   {-4,-3,1},
   {-4,4,1},
   {4,-3,2},
   {4,4,2}};

static struct patval fuseki131326[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,4,2},
   {3,4,2}};

static struct patval fuseki131327[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,4,2},
   {3,4,2}};

static struct patval fuseki131328[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,4,2},
   {3,4,2}};

static struct patval fuseki131329[] = {
   {3,0,1},
   {0,3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki131330[] = {
   {0,-3,1},
   {-3,0,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131331[] = {
   {0,3,1},
   {3,0,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131332[] = {
   {0,-3,1},
   {-3,0,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131333[] = {
   {-4,3,1},
   {-3,-3,1},
   {-2,4,1},
   {3,-4,2},
   {4,4,2}};

static struct patval fuseki131334[] = {
   {-4,-2,1},
   {3,-3,1},
   {-3,-4,1},
   {-4,4,2},
   {4,3,2}};

static struct patval fuseki131335[] = {
   {4,3,1},
   {3,-3,1},
   {2,4,1},
   {-3,-4,2},
   {-4,4,2}};

static struct patval fuseki131336[] = {
   {3,-4,1},
   {-3,3,1},
   {-3,-3,2},
   {4,3,2}};

static struct patval fuseki131337[] = {
   {3,3,1},
   {-3,-4,1},
   {3,-3,2},
   {-4,3,2}};

static struct patval fuseki131338[] = {
   {4,-3,1},
   {-3,3,1},
   {3,3,2},
   {-3,-4,2}};

static struct patval fuseki131339[] = {
   {-3,-3,1},
   {4,3,1},
   {3,-3,2},
   {-3,4,2}};

static struct patval fuseki131340[] = {
   {2,0,1},
   {3,3,1},
   {3,1,1},
   {3,0,2},
   {4,1,2}};

static struct patval fuseki131341[] = {
   {-3,-4,1},
   {4,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131342[] = {
   {-3,-4,1},
   {4,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131343[] = {
   {-4,-3,1},
   {3,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131344[] = {
   {1,2,1},
   {2,2,1},
   {4,1,1},
   {3,2,1},
   {3,1,2},
   {3,3,2},
   {2,3,2},
   {4,2,2}};

static struct patval fuseki131345[] = {
   {1,2,1},
   {2,2,1},
   {4,1,1},
   {3,2,1},
   {3,1,2},
   {3,3,2},
   {2,3,2},
   {4,2,2}};

static struct patval fuseki131346[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki131347[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki131348[] = {
   {-3,-3,1},
   {3,0,1},
   {3,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131349[] = {
   {3,3,1},
   {3,-3,1},
   {0,-3,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki131350[] = {
   {3,-3,1},
   {-3,-3,1},
   {0,-4,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki131351[] = {
   {3,-3,1},
   {-3,-3,1},
   {0,-4,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki131352[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki131353[] = {
   {-4,-3,1},
   {4,-2,1},
   {3,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki131354[] = {
   {-4,-3,1},
   {4,-2,1},
   {3,-4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki131355[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-4,2},
   {3,4,2}};

static struct patval fuseki131356[] = {
   {3,-3,1},
   {-3,-4,1},
   {-4,3,2},
   {4,3,2}};

static struct patval fuseki131357[] = {
   {3,4,1},
   {-3,3,1},
   {-4,-3,2},
   {4,-3,2}};

static struct patval fuseki131358[] = {
   {3,-3,1},
   {-3,-4,1},
   {-4,3,2},
   {4,3,2}};

static struct patval fuseki131359[] = {
   {4,3,1},
   {5,1,1},
   {3,3,1},
   {3,2,2},
   {2,2,2},
   {2,3,2}};

static struct patval fuseki131360[] = {
   {4,3,1},
   {5,1,1},
   {3,3,1},
   {3,2,2},
   {2,2,2},
   {2,3,2}};

static struct patval fuseki131361[] = {
   {4,3,1},
   {5,1,1},
   {3,3,1},
   {3,2,2},
   {2,2,2},
   {2,3,2}};

static struct patval fuseki131362[] = {
   {3,1,1},
   {3,3,1},
   {3,-3,1},
   {1,4,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki131363[] = {
   {3,-3,1},
   {-3,-3,1},
   {-1,-3,1},
   {-3,3,2},
   {-4,-1,2},
   {3,3,2}};

static struct patval fuseki131364[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,-4,1},
   {4,-3,2},
   {4,4,2}};

static struct patval fuseki131365[] = {
   {4,4,1},
   {-4,4,1},
   {4,-2,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki131366[] = {
   {4,4,1},
   {-4,4,1},
   {4,-2,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki131367[] = {
   {3,-3,1},
   {3,3,1},
   {0,4,1},
   {-2,4,2},
   {-4,3,2},
   {-3,-4,2}};

static struct patval fuseki131368[] = {
   {4,0,1},
   {-3,-3,1},
   {3,-3,1},
   {3,4,2},
   {-4,3,2},
   {4,2,2}};

static struct patval fuseki131369[] = {
   {4,3,1},
   {-3,3,1},
   {-3,-4,2}};

static struct patval fuseki131370[] = {
   {3,4,1},
   {3,-3,1},
   {-4,-3,2}};

static struct patval fuseki131371[] = {
   {4,3,1},
   {-3,4,1},
   {3,-2,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki131372[] = {
   {4,-4,1},
   {4,4,1},
   {3,0,1},
   {0,-4,2},
   {-4,-4,2},
   {-4,4,2}};

static struct patval fuseki131373[] = {
   {3,-4,1},
   {-4,4,1},
   {-4,-4,2},
   {4,4,2}};

static struct patval fuseki131374[] = {
   {4,-4,1},
   {-3,4,1},
   {-4,-4,2},
   {4,4,2}};

static struct patval fuseki131375[] = {
   {5,6,1}};

static struct patval fuseki131376[] = {
   {5,-6,1}};

static struct patval fuseki131377[] = {
   {5,-6,1}};

static struct patval fuseki131378[] = {
   {3,1,1}};

static struct patval fuseki131379[] = {
   {4,-4,1},
   {3,4,1},
   {-4,-3,2}};

static struct patval fuseki131380[] = {
   {4,-4,1},
   {3,4,1},
   {-4,-3,2}};

static struct patval fuseki131381[] = {
   {4,4,1},
   {3,-3,1},
   {-3,4,2},
   {-4,2,2}};

static struct patval fuseki131382[] = {
   {-4,-4,1},
   {3,-3,1},
   {-2,4,2},
   {-4,3,2}};

static struct patval fuseki131383[] = {
   {0,0,1},
   {-3,4,2}};

static struct patval fuseki131384[] = {
   {0,0,1},
   {-3,4,2}};

static struct patval fuseki131385[] = {
   {0,0,1},
   {-3,4,2}};

static struct patval fuseki131386[] = {
   {2,2,1},
   {2,3,1},
   {3,0,1},
   {3,1,1},
   {3,3,1},
   {3,2,2},
   {4,1,2},
   {4,2,2},
   {4,3,2}};

static struct patval fuseki131387[] = {
   {-4,-4,1},
   {4,-4,1},
   {-3,3,2},
   {4,4,2}};

static struct patval fuseki131388[] = {
   {4,4,1},
   {-4,4,1},
   {3,-3,2},
   {-4,-4,2}};

static struct patval fuseki131389[] = {
   {-4,-4,1},
   {4,-4,1},
   {-3,3,2},
   {4,4,2}};

static struct patval fuseki131390[] = {
   {3,3,1},
   {4,-1,1},
   {4,1,2}};

static struct patval fuseki131391[] = {
   {-3,-3,1},
   {1,-4,1},
   {-1,-4,2}};

static struct patval fuseki131392[] = {
   {4,3,1},
   {3,-3,1},
   {-1,4,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131393[] = {
   {4,-1,1},
   {-3,3,1},
   {3,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131394[] = {
   {-4,-3,1},
   {3,-4,1},
   {1,-3,1},
   {-4,3,2},
   {3,4,2},
   {4,-2,2}};

static struct patval fuseki131395[] = {
   {4,-3,1},
   {-3,-4,1},
   {-1,-3,1},
   {-3,4,2},
   {-4,-2,2},
   {4,3,2}};

static struct patval fuseki131396[] = {
   {3,4,1},
   {-4,4,1},
   {-4,-3,2}};

static struct patval fuseki131397[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,-4,2}};

static struct patval fuseki131398[] = {
   {3,4,1},
   {-4,4,1},
   {-4,-3,2}};

static struct patval fuseki131399[] = {
   {-3,-4,1},
   {3,-4,1},
   {-3,4,2}};

static struct patval fuseki131400[] = {
   {-3,-4,1},
   {3,-4,1},
   {3,4,2}};

static struct patval fuseki131401[] = {
   {-4,-2,1},
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {-3,-2,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131402[] = {
   {-4,-2,1},
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {-3,-2,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131403[] = {
   {3,3,1},
   {-2,-4,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki131404[] = {
   {3,-3,1},
   {-2,4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131405[] = {
   {3,-3,1},
   {-2,4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131406[] = {
   {4,4,1},
   {-2,-4,2}};

static struct patval fuseki131407[] = {
   {4,-4,1},
   {-2,4,2}};

static struct patval fuseki131408[] = {
   {4,4,1},
   {-4,-2,2}};

static struct patval fuseki131409[] = {
   {-3,-3,1},
   {3,3,1},
   {3,-4,2},
   {-3,4,2}};

static struct patval fuseki131410[] = {
   {3,3,1},
   {-3,-3,1},
   {-4,3,2},
   {4,-3,2}};

static struct patval fuseki131411[] = {
   {3,-3,1},
   {-3,3,1},
   {-3,-4,2},
   {3,4,2}};

static struct patval fuseki131412[] = {
   {-3,3,1},
   {3,-3,1},
   {2,3,2}};

static struct patval fuseki131413[] = {
   {-3,3,1},
   {3,-3,1},
   {3,2,2}};

static struct patval fuseki131414[] = {
   {-3,3,1},
   {3,-3,1},
   {-2,-3,2}};

static struct patval fuseki131415[] = {
   {-4,-3,1},
   {4,-4,1},
   {-4,4,2},
   {4,3,2}};

static struct patval fuseki131416[] = {
   {-4,-3,1},
   {4,-4,1},
   {-4,4,2},
   {4,3,2}};

static struct patval fuseki131417[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {4,-1,1},
   {3,-3,2},
   {3,3,2},
   {0,4,2}};

static struct patval fuseki131418[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {4,-1,1},
   {3,-3,2},
   {3,3,2},
   {0,4,2}};

static struct patval fuseki131419[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131420[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131421[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,3,2},
   {4,-4,2}};

static struct patval fuseki131422[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,3,2},
   {4,-4,2}};

static struct patval fuseki131423[] = {
   {4,2,1},
   {-4,3,1},
   {3,4,1},
   {3,-3,2},
   {-4,-4,2}};

static struct patval fuseki131424[] = {
   {-3,2,1},
   {3,3,1},
   {-3,4,2}};

static struct patval fuseki131425[] = {
   {-3,3,1},
   {3,2,1},
   {3,4,2}};

static struct patval fuseki131426[] = {
   {-2,-3,1},
   {-3,3,1},
   {-4,-3,2}};

static struct patval fuseki131427[] = {
   {3,3,1},
   {-4,2,2}};

static struct patval fuseki131428[] = {
   {-3,3,1},
   {4,2,2}};

static struct patval fuseki131429[] = {
   {-3,3,1},
   {-2,-4,2}};

static struct patval fuseki131430[] = {
   {4,4,1},
   {4,-3,1},
   {2,-4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131431[] = {
   {-3,0,1}};

static struct patval fuseki131432[] = {
   {-3,0,1}};

static struct patval fuseki131433[] = {
   {4,3,1},
   {4,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131434[] = {
   {-4,-3,1},
   {-4,3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131435[] = {
   {3,4,1},
   {-3,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131436[] = {
   {-5,-4,1},
   {-4,-2,1},
   {4,-4,1},
   {2,3,1},
   {0,-4,2},
   {-3,4,2},
   {-3,-4,2},
   {4,3,2}};

static struct patval fuseki131437[] = {
   {-4,-5,1},
   {3,2,1},
   {-2,-4,1},
   {-4,4,1},
   {-4,0,2},
   {-4,-3,2},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki131438[] = {
   {-5,-4,1},
   {-4,-2,1},
   {4,-4,1},
   {2,3,1},
   {0,-4,2},
   {-3,4,2},
   {-3,-4,2},
   {4,3,2}};

static struct patval fuseki131439[] = {
   {-4,4,1},
   {4,4,1},
   {4,-1,1},
   {3,-3,2},
   {0,-4,2},
   {-3,-3,2}};

static struct patval fuseki131440[] = {
   {-4,-4,1},
   {-4,4,1},
   {1,-4,1},
   {3,-3,2},
   {3,3,2},
   {4,0,2}};

static struct patval fuseki131441[] = {
   {-4,-4,1},
   {-4,4,1},
   {1,-4,1},
   {3,-3,2},
   {3,3,2},
   {4,0,2}};

static struct patval fuseki131442[] = {
   {2,2,1},
   {3,1,1},
   {3,3,1},
   {3,2,2},
   {4,1,2}};

static struct patval fuseki131443[] = {
   {3,3,1},
   {3,-3,1},
   {-1,-3,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki131444[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131445[] = {
   {-3,3,1},
   {1,-4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131446[] = {
   {-3,3,1},
   {1,-4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131447[] = {
   {-4,-1,1},
   {3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131448[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,4,1},
   {3,-3,2},
   {3,0,2},
   {4,3,2}};

static struct patval fuseki131449[] = {
   {-4,4,1},
   {4,4,1},
   {4,-2,1},
   {3,-4,2},
   {0,-3,2},
   {-3,-3,2}};

static struct patval fuseki131450[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,4,2}};

static struct patval fuseki131451[] = {
   {4,4,1},
   {4,-4,1},
   {-3,4,2}};

static struct patval fuseki131452[] = {
   {-4,2,1},
   {3,3,1},
   {-3,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131453[] = {
   {-4,2,1},
   {3,3,1},
   {-3,4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131454[] = {
   {4,1,1},
   {-4,4,1},
   {4,4,1},
   {4,-2,2},
   {-4,-4,2},
   {3,-4,2}};

static struct patval fuseki131455[] = {
   {-4,-4,1},
   {-4,4,1},
   {-1,-4,1},
   {2,-4,2},
   {4,-3,2},
   {4,4,2}};

static struct patval fuseki131456[] = {
   {-4,-4,1},
   {-4,4,1},
   {-1,4,1},
   {2,4,2},
   {4,-4,2},
   {4,3,2}};

static struct patval fuseki131457[] = {
   {3,4,1},
   {-2,4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131458[] = {
   {-4,4,1},
   {4,2,1},
   {3,2,1},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki131459[] = {
   {2,-3,1},
   {4,4,1},
   {2,-4,1},
   {-3,-3,2},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki131460[] = {
   {-2,4,1},
   {-3,-3,1},
   {-4,3,2},
   {3,4,2}};

static struct patval fuseki131461[] = {
   {3,3,1},
   {2,-4,1},
   {-3,-4,2},
   {4,-3,2}};

static struct patval fuseki131462[] = {
   {-4,-4,1},
   {4,-1,1},
   {4,-4,1},
   {3,4,2},
   {-3,3,2},
   {4,2,2}};

static struct patval fuseki131463[] = {
   {-4,-4,1},
   {-4,4,1},
   {-1,4,1},
   {2,4,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131464[] = {
   {-4,-4,1},
   {-4,4,1},
   {-1,4,1},
   {2,4,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131465[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,4,1},
   {3,-4,2},
   {-2,4,2}};

static struct patval fuseki131466[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,4,1},
   {3,-4,2},
   {-2,4,2}};

static struct patval fuseki131467[] = {
   {-4,-4,1},
   {-4,3,1},
   {3,4,1},
   {3,-4,2},
   {-2,4,2}};

static struct patval fuseki131468[] = {
   {-4,-3,1},
   {-4,3,1},
   {-2,4,1},
   {3,-4,2},
   {4,4,2}};

static struct patval fuseki131469[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131470[] = {
   {-4,3,1},
   {-3,-4,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131471[] = {
   {-3,-4,1},
   {4,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131472[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki131473[] = {
   {4,-3,1},
   {-3,-3,1},
   {3,3,2},
   {-4,4,2}};

static struct patval fuseki131474[] = {
   {-4,3,1},
   {3,3,1},
   {-3,-3,2},
   {4,-4,2}};

static struct patval fuseki131475[] = {
   {4,-3,1},
   {-3,-3,1},
   {2,-4,1},
   {3,4,2},
   {-4,3,2}};

static struct patval fuseki131476[] = {
   {-4,3,1},
   {3,3,1},
   {-2,4,1},
   {-3,-4,2},
   {4,-3,2}};

static struct patval fuseki131477[] = {
   {-4,2,1},
   {-3,-3,1},
   {-3,4,1},
   {3,-4,2},
   {4,3,2}};

static struct patval fuseki131478[] = {
   {0,-3,1},
   {-3,3,2}};

static struct patval fuseki131479[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {2,-4,2},
   {4,4,2}};

static struct patval fuseki131480[] = {
   {3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {-4,-3,2},
   {4,3,2}};

static struct patval fuseki131481[] = {
   {4,2,1},
   {-3,3,1},
   {3,-3,1},
   {3,4,2},
   {-3,-4,2}};

static struct patval fuseki131482[] = {
   {3,-3,1},
   {-3,3,1},
   {2,4,1},
   {-4,-3,2},
   {4,3,2}};

static struct patval fuseki131483[] = {
   {-2,-3,1},
   {-3,-3,2}};

static struct patval fuseki131484[] = {
   {-3,-2,1},
   {-3,-3,2}};

static struct patval fuseki131485[] = {
   {-2,-3,1},
   {-3,-3,2}};

static struct patval fuseki131486[] = {
   {-4,3,1},
   {-3,-4,1},
   {2,-4,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki131487[] = {
   {4,-3,1},
   {3,4,1},
   {-2,4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131488[] = {
   {4,3,1},
   {-3,4,1},
   {4,-2,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki131489[] = {
   {-4,-4,1},
   {4,-2,1},
   {3,-4,1},
   {3,-2,2},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki131490[] = {
   {-4,-4,1},
   {4,-2,1},
   {3,-4,1},
   {3,-2,2},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki131491[] = {
   {3,4,1},
   {3,-2,1},
   {-4,4,2}};

static struct patval fuseki131492[] = {
   {3,2,1},
   {3,-4,1},
   {-4,-4,2}};

static struct patval fuseki131493[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,1,1},
   {3,1,1},
   {3,3,2},
   {3,-3,2},
   {4,2,2}};

static struct patval fuseki131494[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,1,1},
   {3,1,1},
   {3,3,2},
   {3,-3,2},
   {4,2,2}};

static struct patval fuseki131495[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,1,1},
   {3,1,1},
   {3,3,2},
   {3,-3,2},
   {4,2,2}};

static struct patval fuseki131496[] = {
   {-4,-4,1},
   {-4,4,1},
   {0,-4,1},
   {2,-4,1},
   {3,0,2},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki131497[] = {
   {-4,-4,1},
   {-4,4,1},
   {0,-4,1},
   {2,-4,1},
   {3,0,2},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki131498[] = {
   {3,4,1},
   {-4,3,1},
   {3,-2,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki131499[] = {
   {-2,4,1},
   {-4,0,1},
   {-4,3,1},
   {-3,-4,1},
   {-4,-2,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131500[] = {
   {-2,4,1},
   {-4,0,1},
   {-4,3,1},
   {-3,-4,1},
   {-4,-2,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131501[] = {
   {3,3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131502[] = {
   {3,3,1},
   {3,-3,1},
   {0,0,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131503[] = {
   {3,3,1},
   {3,-3,1},
   {0,0,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131504[] = {
   {3,-2,1},
   {-4,3,1},
   {2,-4,1},
   {3,4,1},
   {3,-3,1},
   {-4,-4,2},
   {3,-4,2},
   {4,-3,2},
   {4,-2,2}};

static struct patval fuseki131505[] = {
   {-1,1,1}};

static struct patval fuseki131506[] = {
   {-1,1,1}};

static struct patval fuseki131507[] = {
   {2,2,1},
   {2,3,1},
   {3,1,1},
   {3,3,1},
   {3,2,2},
   {4,1,2},
   {4,2,2}};

static struct patval fuseki131508[] = {
   {-4,-4,1},
   {-4,-3,1},
   {-4,4,1},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131509[] = {
   {4,-3,1},
   {4,4,1},
   {4,-4,1},
   {3,-3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki131510[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,-3,1},
   {3,4,2},
   {-2,4,2}};

static struct patval fuseki131511[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,-3,1},
   {3,4,2},
   {-2,4,2}};

static struct patval fuseki131512[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,-3,1},
   {3,4,2},
   {-2,4,2}};

static struct patval fuseki131513[] = {
   {1,3,1},
   {2,2,1},
   {3,2,1},
   {2,3,2},
   {3,3,2}};

static struct patval fuseki131514[] = {
   {1,3,1},
   {2,2,1},
   {3,2,1},
   {2,3,2},
   {3,3,2}};

static struct patval fuseki131515[] = {
   {4,4,1},
   {4,-4,1},
   {-2,4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131516[] = {
   {4,4,1},
   {-4,4,1},
   {4,-2,1},
   {4,-4,2},
   {-4,-4,2}};

static struct patval fuseki131517[] = {
   {-4,-4,1},
   {4,-3,1},
   {-4,4,2}};

static struct patval fuseki131518[] = {
   {-4,3,1},
   {4,4,1},
   {4,-4,2}};

static struct patval fuseki131519[] = {
   {4,-3,1},
   {-3,-3,1},
   {-2,3,1},
   {3,4,2},
   {-4,3,2},
   {4,2,2}};

static struct patval fuseki131520[] = {
   {3,3,1},
   {3,-3,1},
   {-2,-4,2},
   {-3,3,2}};

static struct patval fuseki131521[] = {
   {3,-3,1},
   {-3,-3,1},
   {-4,2,2},
   {3,3,2}};

static struct patval fuseki131522[] = {
   {3,-1,1},
   {3,-3,2}};

static struct patval fuseki131523[] = {
   {1,-3,1},
   {3,-3,2}};

static struct patval fuseki131524[] = {
   {1,-3,1},
   {3,-3,2}};

static struct patval fuseki131525[] = {
   {3,4,1},
   {4,-4,2}};

static struct patval fuseki131526[] = {
   {-4,3,1},
   {4,4,2}};

static struct patval fuseki131527[] = {
   {0,-4,1},
   {4,3,1},
   {-3,-4,1},
   {-3,4,1},
   {-5,-4,2},
   {4,-4,2},
   {-4,-2,2}};

static struct patval fuseki131528[] = {
   {2,3,1},
   {3,3,1},
   {3,4,2},
   {4,4,2}};

static struct patval fuseki131529[] = {
   {2,3,1},
   {3,3,1},
   {3,4,2},
   {4,4,2}};

static struct patval fuseki131530[] = {
   {-3,3,1},
   {-3,2,1},
   {-4,4,2},
   {-4,3,2}};

static struct patval fuseki131531[] = {
   {4,-4,1},
   {3,4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131532[] = {
   {4,4,1},
   {3,-4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131533[] = {
   {3,2,1},
   {-2,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131534[] = {
   {3,-2,1},
   {2,3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131535[] = {
   {-4,-3,1},
   {-4,4,1},
   {-2,-4,1},
   {2,4,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131536[] = {
   {-4,-4,1},
   {-4,3,1},
   {-2,4,1},
   {2,-4,2},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki131537[] = {
   {-4,-4,1},
   {-4,3,1},
   {-2,4,1},
   {2,-4,2},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki131538[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,3,2}};

static struct patval fuseki131539[] = {
   {-4,4,1},
   {-3,-3,1},
   {3,-3,2}};

static struct patval fuseki131540[] = {
   {-4,-4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki131541[] = {
   {-3,2,1},
   {3,3,1},
   {-4,2,1},
   {-2,4,1},
   {-5,1,2},
   {-4,3,2},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki131542[] = {
   {-2,4,1},
   {-3,3,2}};

static struct patval fuseki131543[] = {
   {-4,3,1},
   {4,2,1},
   {3,4,1},
   {-2,4,1},
   {-2,3,2},
   {4,-3,2},
   {-3,-3,2}};

static struct patval fuseki131544[] = {
   {-4,-2,1},
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {-3,-2,2},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki131545[] = {
   {3,3,1},
   {4,2,1},
   {3,-3,1},
   {-4,-4,2},
   {4,1,2},
   {-4,4,2}};

static struct patval fuseki131546[] = {
   {-3,-4,1},
   {4,-2,1},
   {-3,3,2}};

static struct patval fuseki131547[] = {
   {-4,-2,1},
   {3,-4,1},
   {3,3,2}};

static struct patval fuseki131548[] = {
   {-5,1,1},
   {-5,2,1},
   {-4,-3,1},
   {3,-4,1},
   {-4,3,1},
   {-3,2,2},
   {-2,4,2},
   {-4,2,2},
   {3,3,2}};

static struct patval fuseki131549[] = {
   {-5,1,1},
   {-5,2,1},
   {-4,-3,1},
   {3,-4,1},
   {-4,3,1},
   {-3,2,2},
   {-2,4,2},
   {-4,2,2},
   {3,3,2}};

static struct patval fuseki131550[] = {
   {-5,1,1},
   {-5,2,1},
   {-4,-3,1},
   {3,-4,1},
   {-4,3,1},
   {-3,2,2},
   {-2,4,2},
   {-4,2,2},
   {3,3,2}};

static struct patval fuseki131551[] = {
   {-4,-3,1},
   {-3,4,1},
   {3,3,2},
   {4,-4,2}};

static struct patval fuseki131552[] = {
   {-4,3,1},
   {3,4,1},
   {-3,-3,2},
   {4,-4,2}};

static struct patval fuseki131553[] = {
   {3,-4,1},
   {4,4,1},
   {-2,-4,1},
   {-2,4,2},
   {-4,-3,2},
   {-4,3,2}};

static struct patval fuseki131554[] = {
   {3,-4,1},
   {4,4,1},
   {-2,-4,1},
   {-2,4,2},
   {-4,-3,2},
   {-4,3,2}};

static struct patval fuseki131555[] = {
   {3,-4,1},
   {-2,4,1},
   {-4,3,2},
   {3,4,2}};

static struct patval fuseki131556[] = {
   {3,3,1},
   {3,-3,1},
   {-1,4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131557[] = {
   {4,-1,1},
   {-3,3,1},
   {3,3,1},
   {4,-4,2},
   {-4,-4,2}};

static struct patval fuseki131558[] = {
   {2,-3,1},
   {-4,3,2}};

static struct patval fuseki131559[] = {
   {2,-3,1},
   {-4,3,2}};

static struct patval fuseki131560[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,-1,1},
   {3,-3,2},
   {2,3,2}};

static struct patval fuseki131561[] = {
   {-4,3,1},
   {3,4,1},
   {-1,-4,1},
   {3,-2,2},
   {-3,-3,2}};

static struct patval fuseki131562[] = {
   {-3,3,1},
   {4,2,1},
   {3,-4,2}};

static struct patval fuseki131563[] = {
   {-4,2,1},
   {3,3,1},
   {-3,-4,2}};

static struct patval fuseki131564[] = {
   {-4,4,1},
   {3,4,1},
   {-1,-4,1},
   {-3,-3,2},
   {4,-3,2},
   {4,2,2}};

static struct patval fuseki131565[] = {
   {-4,-4,1},
   {3,-4,1},
   {-1,4,1},
   {-3,3,2},
   {4,-2,2},
   {4,3,2}};

static struct patval fuseki131566[] = {
   {-4,4,1},
   {-3,-3,1},
   {1,-4,1},
   {3,3,2},
   {4,-4,2}};

static struct patval fuseki131567[] = {
   {4,-4,1},
   {3,3,1},
   {-1,4,1},
   {-3,-3,2},
   {-4,4,2}};

static struct patval fuseki131568[] = {
   {-4,-3,1},
   {4,3,1},
   {4,-3,2}};

static struct patval fuseki131569[] = {
   {-4,-3,1},
   {4,3,1},
   {4,-3,2}};

static struct patval fuseki131570[] = {
   {-4,-3,1},
   {4,3,1},
   {4,-3,2}};

static struct patval fuseki131571[] = {
   {4,2,1},
   {4,3,1},
   {4,1,1},
   {3,2,1},
   {3,3,2},
   {3,1,2},
   {2,2,2},
   {2,3,2}};

static struct patval fuseki131572[] = {
   {-4,-3,1},
   {-4,4,1},
   {-2,-4,1},
   {0,4,2},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131573[] = {
   {-4,-4,1},
   {4,-2,1},
   {3,-4,1},
   {-3,3,2},
   {-4,0,2},
   {4,3,2}};

static struct patval fuseki131574[] = {
   {3,3,1},
   {-3,3,1},
   {-4,-2,2}};

static struct patval fuseki131575[] = {
   {3,3,1},
   {-3,3,1},
   {-4,-2,2}};

static struct patval fuseki131576[] = {
   {-4,-4,1},
   {3,3,1},
   {-3,3,2}};

static struct patval fuseki131577[] = {
   {-4,-4,1},
   {3,3,1},
   {3,-3,2}};

static struct patval fuseki131578[] = {
   {-4,-4,1},
   {3,3,1},
   {-3,3,2}};

static struct patval fuseki131579[] = {
   {-5,3,1},
   {-3,4,1},
   {-4,3,1},
   {-3,3,2},
   {-4,2,2}};

static struct patval fuseki131580[] = {
   {-5,3,1},
   {-3,4,1},
   {-4,3,1},
   {-3,3,2},
   {-4,2,2}};

static struct patval fuseki131581[] = {
   {-4,-4,1},
   {-2,-3,2}};

static struct patval fuseki131582[] = {
   {-4,-4,1},
   {-3,-2,2}};

static struct patval fuseki131583[] = {
   {-4,4,1},
   {-2,3,2}};

static struct patval fuseki131584[] = {
   {3,3,1},
   {3,-3,1},
   {0,4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131585[] = {
   {3,3,1},
   {3,-3,1},
   {0,-4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131586[] = {
   {-3,-3,1},
   {2,-4,1},
   {-1,-4,2}};

static struct patval fuseki131587[] = {
   {-3,3,1},
   {2,4,1},
   {-1,4,2}};

static struct patval fuseki131588[] = {
   {3,3,1},
   {4,-2,1},
   {4,1,2}};

static struct patval fuseki131589[] = {
   {-3,-3,1},
   {-2,3,1},
   {4,-3,2}};

static struct patval fuseki131590[] = {
   {-3,-2,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki131591[] = {
   {-3,-2,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki131592[] = {
   {-3,3,1},
   {3,3,1},
   {0,0,2}};

static struct patval fuseki131593[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,2}};

static struct patval fuseki131594[] = {
   {3,3,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki131595[] = {
   {-4,-3,1},
   {-2,-4,2}};

static struct patval fuseki131596[] = {
   {-4,3,1},
   {-2,4,2}};

static struct patval fuseki131597[] = {
   {-4,-4,1},
   {3,4,1},
   {-4,3,2},
   {4,-3,2}};

static struct patval fuseki131598[] = {
   {3,-4,1},
   {-4,4,1},
   {-4,-3,2},
   {4,3,2}};

static struct patval fuseki131599[] = {
   {3,-4,1},
   {-4,4,1},
   {-4,-3,2},
   {4,3,2}};

static struct patval fuseki131600[] = {
   {4,-4,1},
   {-3,3,1},
   {3,3,2},
   {-4,-3,2}};

static struct patval fuseki131601[] = {
   {4,-4,1},
   {-3,3,1},
   {3,4,2},
   {-3,-3,2}};

static struct patval fuseki131602[] = {
   {4,4,1},
   {-3,-3,1},
   {3,-3,2},
   {-4,3,2}};

static struct patval fuseki131603[] = {
   {-4,-4,1},
   {4,-2,1},
   {3,-4,1},
   {4,-3,1},
   {3,-2,2},
   {3,4,2},
   {3,-3,2},
   {-4,3,2}};

static struct patval fuseki131604[] = {
   {-4,-2,1},
   {-4,4,2}};

static struct patval fuseki131605[] = {
   {2,4,1},
   {-4,4,2}};

static struct patval fuseki131606[] = {
   {-2,-4,1},
   {4,-4,2}};

static struct patval fuseki131607[] = {
   {-4,-4,1},
   {4,-2,1},
   {3,-4,1},
   {3,-2,2},
   {3,4,2},
   {-4,3,2}};

static struct patval fuseki131608[] = {
   {4,1,1},
   {4,2,1},
   {3,2,1},
   {3,3,2},
   {2,2,2},
   {3,1,2}};

static struct patval fuseki131609[] = {
   {3,3,1},
   {2,3,1},
   {3,2,2},
   {2,2,2}};

static struct patval fuseki131610[] = {
   {3,4,1},
   {-4,3,1},
   {3,-2,1},
   {3,-3,1},
   {3,-4,2},
   {-4,-4,2},
   {4,-2,2}};

static struct patval fuseki131611[] = {
   {-4,3,1},
   {4,4,1},
   {-3,-4,2}};

static struct patval fuseki131612[] = {
   {-4,4,1},
   {4,3,1},
   {3,-4,2}};

static struct patval fuseki131613[] = {
   {4,4,1},
   {-3,4,1},
   {3,-3,2},
   {-4,-2,2}};

static struct patval fuseki131614[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {4,2,2}};

static struct patval fuseki131615[] = {
   {-4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {4,2,2}};

static struct patval fuseki131616[] = {
   {4,4,1},
   {3,-3,1},
   {-1,4,1},
   {-4,4,2},
   {-4,-3,2}};

static struct patval fuseki131617[] = {
   {-4,-4,1},
   {-4,1,1},
   {3,-3,1},
   {-4,4,2},
   {3,4,2}};

static struct patval fuseki131618[] = {
   {-4,-2,1},
   {3,4,1},
   {3,-3,1},
   {-2,4,2},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131619[] = {
   {3,3,1},
   {-4,3,1},
   {2,-4,1},
   {-3,-4,2},
   {-4,-2,2},
   {4,-3,2}};

static struct patval fuseki131620[] = {
   {4,3,1},
   {-4,4,1},
   {4,-3,2},
   {-4,-4,2}};

static struct patval fuseki131621[] = {
   {-4,-4,1},
   {4,-3,1},
   {-4,4,2},
   {4,3,2}};

static struct patval fuseki131622[] = {
   {-3,3,1},
   {4,-4,1},
   {0,-3,2}};

static struct patval fuseki131623[] = {
   {-3,3,1},
   {4,-4,1},
   {3,0,2}};

static struct patval fuseki131624[] = {
   {-4,-4,1},
   {4,4,1},
   {-4,4,2}};

static struct patval fuseki131625[] = {
   {-4,-4,1},
   {4,4,1},
   {4,-4,2}};

static struct patval fuseki131626[] = {
   {-4,-4,1},
   {4,4,1},
   {4,-4,2}};

static struct patval fuseki131627[] = {
   {4,4,1},
   {3,-4,1},
   {-3,3,2},
   {-4,-4,2}};

static struct patval fuseki131628[] = {
   {-4,-3,1},
   {4,-4,1},
   {3,3,2},
   {-4,4,2}};

static struct patval fuseki131629[] = {
   {4,-4,1},
   {3,4,1},
   {-3,-3,2},
   {-4,4,2}};

static struct patval fuseki131630[] = {
   {-4,-3,1},
   {4,-3,1},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki131631[] = {
   {-3,-4,1},
   {-3,4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131632[] = {
   {-3,-4,1},
   {4,3,1},
   {3,2,1},
   {3,-3,2},
   {2,4,2},
   {-3,3,2}};

static struct patval fuseki131633[] = {
   {-4,3,1},
   {3,-4,1},
   {2,-3,1},
   {-3,-3,2},
   {3,3,2},
   {4,-2,2}};

static struct patval fuseki131634[] = {
   {-3,3,1},
   {3,-4,1},
   {3,-3,2}};

static struct patval fuseki131635[] = {
   {-3,-3,1},
   {3,4,1},
   {3,3,2}};

static struct patval fuseki131636[] = {
   {-3,-3,1},
   {2,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki131637[] = {
   {3,2,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131638[] = {
   {-4,-3,1},
   {-3,3,1},
   {2,3,2},
   {3,-3,2}};

static struct patval fuseki131639[] = {
   {4,-3,1},
   {3,3,1},
   {-2,3,2},
   {-3,-3,2}};

static struct patval fuseki131640[] = {
   {4,2,1},
   {5,1,1},
   {2,3,1},
   {3,1,1},
   {3,3,1},
   {3,2,2},
   {4,1,2},
   {1,2,2},
   {2,2,2}};

static struct patval fuseki131641[] = {
   {4,2,1},
   {3,1,1},
   {4,3,1},
   {3,3,1},
   {4,1,2},
   {2,2,2},
   {3,2,2}};

static struct patval fuseki131642[] = {
   {-4,-3,1},
   {3,0,1},
   {3,-3,1},
   {-4,3,2},
   {3,3,2}};

static struct patval fuseki131643[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-3,2},
   {3,2,2}};

static struct patval fuseki131644[] = {
   {4,0,1},
   {4,3,1},
   {3,-3,1},
   {-1,2,1},
   {-1,4,1},
   {1,-4,2},
   {-3,3,2},
   {-3,-3,2},
   {-3,0,2}};

static struct patval fuseki131645[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,1,1},
   {4,-1,1},
   {3,1,1},
   {3,3,2},
   {3,-3,2},
   {1,3,2},
   {4,2,2}};

static struct patval fuseki131646[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,1,1},
   {4,-1,1},
   {3,1,1},
   {3,3,2},
   {3,-3,2},
   {1,3,2},
   {4,2,2}};

static struct patval fuseki131647[] = {
   {-4,-1,1},
   {3,-3,1},
   {-3,-3,1},
   {-4,3,2},
   {3,3,2}};

static struct patval fuseki131648[] = {
   {-4,-4,1},
   {4,-2,1},
   {3,-4,1},
   {3,4,2},
   {-3,3,2},
   {4,2,2}};

static struct patval fuseki131649[] = {
   {-4,-4,1},
   {-4,3,1},
   {-2,4,1},
   {2,4,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131650[] = {
   {2,1,1},
   {4,1,1},
   {4,-1,2},
   {3,3,2}};

static struct patval fuseki131651[] = {
   {4,3,1},
   {5,1,1},
   {3,1,1},
   {4,2,1},
   {3,3,1},
   {4,1,2},
   {3,2,2},
   {2,2,2},
   {3,0,2}};

static struct patval fuseki131652[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-4,2},
   {3,4,2}};

static struct patval fuseki131653[] = {
   {-4,-2,1},
   {4,-4,1},
   {-4,3,2},
   {4,3,2}};

static struct patval fuseki131654[] = {
   {3,3,1},
   {3,-3,1},
   {0,-3,1},
   {-3,4,2},
   {-3,-3,2}};

static struct patval fuseki131655[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131656[] = {
   {3,3,1},
   {-3,3,1},
   {4,-1,1},
   {3,-3,2},
   {-3,-3,2},
   {0,-3,2}};

static struct patval fuseki131657[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki131658[] = {
   {-4,-3,1},
   {-2,-3,1},
   {4,4,2}};

static struct patval fuseki131659[] = {
   {-4,-3,1},
   {-2,-3,1},
   {4,4,2}};

static struct patval fuseki131660[] = {
   {-4,-3,1},
   {-3,4,1},
   {-2,-4,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki131661[] = {
   {4,-3,1},
   {3,4,1},
   {2,-4,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki131662[] = {
   {-4,3,1},
   {-1,-4,1},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki131663[] = {
   {-4,3,1},
   {-1,-4,1},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki131664[] = {
   {3,-4,1},
   {-3,-4,1},
   {0,-4,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki131665[] = {
   {4,0,1},
   {-4,4,1},
   {1,-4,1},
   {0,-4,1},
   {4,3,1},
   {-2,-4,2},
   {4,-2,2},
   {-4,-3,2},
   {4,-4,2}};

static struct patval fuseki131666[] = {
   {-4,3,1},
   {4,2,1},
   {3,4,1},
   {-3,4,1},
   {-2,4,1},
   {-2,3,2},
   {-3,3,2},
   {4,-3,2},
   {-3,-3,2}};

static struct patval fuseki131667[] = {
   {3,3,1},
   {4,-2,1},
   {3,-4,1},
   {0,4,1},
   {-2,-4,2},
   {-4,-3,2},
   {-4,4,2}};

static struct patval fuseki131668[] = {
   {-4,-1,1},
   {4,3,1},
   {-3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131669[] = {
   {-3,-4,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131670[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-4,1},
   {-1,4,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131671[] = {
   {4,3,1},
   {3,-3,1},
   {-3,2,2}};

static struct patval fuseki131672[] = {
   {-3,-4,1},
   {3,-3,1},
   {-2,3,2}};

static struct patval fuseki131673[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-1,1},
   {4,-1,1},
   {0,4,2},
   {3,3,2},
   {4,-2,2},
   {3,-3,2}};

static struct patval fuseki131674[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-1,1},
   {4,-1,1},
   {0,4,2},
   {3,3,2},
   {4,-2,2},
   {3,-3,2}};

static struct patval fuseki131675[] = {
   {-3,4,1},
   {-2,-4,1},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki131676[] = {
   {3,-4,1},
   {2,4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131677[] = {
   {-3,-3,1},
   {3,3,1},
   {3,-4,2},
   {-3,3,2}};

static struct patval fuseki131678[] = {
   {-3,-3,1},
   {3,3,1},
   {3,-4,2},
   {-3,3,2}};

static struct patval fuseki131679[] = {
   {-4,-4,1},
   {-4,1,1},
   {-4,4,1},
   {-2,4,2},
   {4,-4,2},
   {4,4,2}};

static struct patval fuseki131680[] = {
   {-4,4,1},
   {-2,-4,1},
   {3,-2,2},
   {3,4,2}};

static struct patval fuseki131681[] = {
   {4,3,1},
   {-2,4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131682[] = {
   {-3,-3,1},
   {4,2,1},
   {3,4,1},
   {4,-3,2},
   {-3,4,2}};

static struct patval fuseki131683[] = {
   {-4,-3,1},
   {3,3,1},
   {-2,-4,1},
   {3,-4,2},
   {-4,3,2}};

static struct patval fuseki131684[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131685[] = {
   {-3,-3,1},
   {3,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131686[] = {
   {-4,3,1},
   {-2,-4,2}};

static struct patval fuseki131687[] = {
   {-3,4,1},
   {4,2,2}};

static struct patval fuseki131688[] = {
   {3,-2,1},
   {-3,4,1},
   {4,3,1},
   {3,-3,1},
   {-4,-4,2},
   {4,-2,2},
   {3,-4,2}};

static struct patval fuseki131689[] = {
   {-4,3,1},
   {-3,-5,1},
   {3,4,1},
   {-1,-4,1},
   {1,-4,2},
   {3,-2,2},
   {-3,-3,2}};

static struct patval fuseki131690[] = {
   {-4,3,1},
   {-3,-4,1},
   {5,-3,1},
   {4,-1,1},
   {3,-3,2},
   {4,1,2},
   {2,3,2}};

static struct patval fuseki131691[] = {
   {4,-3,1},
   {3,0,2}};

static struct patval fuseki131692[] = {
   {-4,-3,1},
   {-3,0,2}};

static struct patval fuseki131693[] = {
   {3,3,1},
   {-1,4,1},
   {-3,4,2}};

static struct patval fuseki131694[] = {
   {-4,1,1},
   {-3,-3,1},
   {-4,3,2}};

static struct patval fuseki131695[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki131696[] = {
   {-4,3,1},
   {4,2,1},
   {3,4,1},
   {3,-3,2},
   {-3,-4,2}};

static struct patval fuseki131697[] = {
   {4,-4,1},
   {3,3,1},
   {-2,-4,1},
   {-3,4,2},
   {-4,-3,2}};

static struct patval fuseki131698[] = {
   {-4,-4,1},
   {-3,3,1},
   {2,-4,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki131699[] = {
   {-3,-3,1},
   {4,-2,1},
   {4,3,2}};

static struct patval fuseki131700[] = {
   {-3,3,1},
   {-2,-4,1},
   {3,-4,2}};

static struct patval fuseki131701[] = {
   {3,-3,1},
   {-2,3,2}};

static struct patval fuseki131702[] = {
   {3,3,1},
   {-3,-2,2}};

static struct patval fuseki131703[] = {
   {-4,4,1},
   {3,2,1},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki131704[] = {
   {4,4,1},
   {2,-3,1},
   {4,-3,2},
   {-3,-4,2}};

static struct patval fuseki131705[] = {
   {-3,-3,1},
   {3,3,1},
   {-2,4,2}};

static struct patval fuseki131706[] = {
   {-3,3,1},
   {3,-3,1},
   {4,2,2}};

static struct patval fuseki131707[] = {
   {-3,-3,1},
   {3,3,1},
   {3,-3,1},
   {2,-2,2},
   {0,0,2},
   {-3,3,2}};

static struct patval fuseki131708[] = {
   {-4,3,1},
   {3,2,1},
   {3,-3,2}};

static struct patval fuseki131709[] = {
   {-4,-3,1},
   {3,-2,1},
   {3,3,2}};

static struct patval fuseki131710[] = {
   {4,-1,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki131711[] = {
   {3,-3,1},
   {-3,3,1},
   {1,-4,1},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki131712[] = {
   {4,-4,1},
   {3,4,1},
   {-1,-4,1},
   {-4,4,2},
   {-4,-3,2}};

static struct patval fuseki131713[] = {
   {3,-3,1},
   {2,4,1},
   {-4,4,2}};

static struct patval fuseki131714[] = {
   {3,3,1},
   {-4,2,1},
   {-4,-4,2}};

static struct patval fuseki131715[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,-4,1},
   {3,4,2},
   {4,-3,2},
   {4,2,2}};

static struct patval fuseki131716[] = {
   {-4,-4,1},
   {-4,2,1},
   {4,-4,1},
   {2,4,2},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki131717[] = {
   {4,-2,1},
   {3,3,1},
   {3,-4,1},
   {-4,4,2},
   {-4,-4,2},
   {4,1,2}};

static struct patval fuseki131718[] = {
   {4,-1,1},
   {-3,3,1},
   {3,3,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki131719[] = {
   {-4,-2,1},
   {3,3,1},
   {3,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131720[] = {
   {-3,-3,1},
   {3,-3,1},
   {2,4,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki131721[] = {
   {4,-3,1},
   {3,4,1},
   {-2,-3,2},
   {-3,3,2}};

static struct patval fuseki131722[] = {
   {-4,-3,1},
   {3,-4,1},
   {-3,3,2},
   {3,2,2}};

static struct patval fuseki131723[] = {
   {-4,4,1},
   {-3,2,1},
   {-2,-4,1},
   {2,-4,2},
   {3,-2,2},
   {3,4,2}};

static struct patval fuseki131724[] = {
   {-4,4,1},
   {-3,2,1},
   {-2,-4,1},
   {2,-4,2},
   {3,-2,2},
   {3,4,2}};

static struct patval fuseki131725[] = {
   {3,-3,1},
   {3,3,1},
   {-1,-2,1},
   {-1,-4,1},
   {-3,3,2},
   {-3,-4,2},
   {-3,-2,2}};

static struct patval fuseki131726[] = {
   {3,3,1},
   {-3,3,1},
   {4,-1,1},
   {2,-1,1},
   {-3,-3,2},
   {4,-3,2},
   {2,-3,2}};

static struct patval fuseki131727[] = {
   {0,-4,1},
   {4,-1,1},
   {3,3,1},
   {-2,-3,1},
   {-4,-3,2},
   {-3,4,2},
   {4,-3,2},
   {-3,-1,2}};

static struct patval fuseki131728[] = {
   {3,-3,1},
   {-2,3,1},
   {-4,3,2}};

static struct patval fuseki131729[] = {
   {-3,3,1},
   {3,-2,1},
   {3,-4,2}};

static struct patval fuseki131730[] = {
   {2,-2,1},
   {-3,3,1},
   {0,0,1},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki131731[] = {
   {-4,0,1},
   {4,-3,1},
   {-3,-4,1},
   {-3,4,2},
   {-4,2,2},
   {4,4,2}};

static struct patval fuseki131732[] = {
   {-4,-3,1},
   {4,0,1},
   {3,-4,1},
   {3,4,2},
   {-4,4,2},
   {4,2,2}};

static struct patval fuseki131733[] = {
   {-4,-4,1},
   {-4,4,1},
   {5,-3,1},
   {4,-1,1},
   {3,4,2},
   {3,-3,2},
   {0,-4,2}};

static struct patval fuseki131734[] = {
   {-4,-3,1},
   {-2,4,1},
   {-4,3,1},
   {-3,-4,1},
   {-4,-2,2},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki131735[] = {
   {3,4,1},
   {-4,2,1},
   {-3,4,1},
   {4,3,1},
   {3,-3,2},
   {-4,-3,2},
   {2,4,2}};

static struct patval fuseki131736[] = {
   {-4,-2,1},
   {4,-3,1},
   {-3,-4,1},
   {-4,4,2},
   {4,3,2}};

static struct patval fuseki131737[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-4,2},
   {4,4,2}};

static struct patval fuseki131738[] = {
   {-4,1,1},
   {-3,-3,1},
   {-3,0,1},
   {3,-3,1},
   {-3,3,2},
   {-3,1,2},
   {3,3,2}};

static struct patval fuseki131739[] = {
   {-4,-4,1},
   {3,3,1},
   {-4,4,2}};

static struct patval fuseki131740[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,-4,1},
   {2,4,2},
   {4,-3,2},
   {4,3,2}};

static struct patval fuseki131741[] = {
   {-4,-4,1},
   {4,2,1},
   {4,-4,1},
   {3,4,2},
   {-3,4,2},
   {-4,2,2}};

static struct patval fuseki131742[] = {
   {4,2,1},
   {3,-3,1},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131743[] = {
   {3,-3,1},
   {-2,-4,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki131744[] = {
   {3,4,1},
   {3,-3,1},
   {-2,-3,2},
   {-3,3,2}};

static struct patval fuseki131745[] = {
   {-4,3,1},
   {3,3,1},
   {3,-2,2},
   {-3,-3,2}};

static struct patval fuseki131746[] = {
   {4,2,1},
   {-3,3,1},
   {4,-3,2},
   {-3,-3,2}};

static struct patval fuseki131747[] = {
   {3,3,1},
   {2,-4,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki131748[] = {
   {-4,-3,1},
   {4,-3,1},
   {1,-3,1},
   {3,-4,1},
   {3,-2,2},
   {-4,4,2},
   {4,-2,2},
   {4,4,2}};

static struct patval fuseki131749[] = {
   {3,3,1},
   {3,-3,1},
   {-1,4,1},
   {-3,-3,2},
   {-4,4,2}};

static struct patval fuseki131750[] = {
   {4,-1,1},
   {-3,3,1},
   {3,3,1},
   {4,-4,2},
   {-3,-3,2}};

static struct patval fuseki131751[] = {
   {-4,-3,1},
   {-4,4,1},
   {2,3,1},
   {-1,4,2},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki131752[] = {
   {-4,-3,1},
   {4,-2,1},
   {3,-3,1},
   {3,3,2},
   {-3,3,2},
   {4,-1,2}};

static struct patval fuseki131753[] = {
   {-3,-3,1},
   {3,-2,1},
   {2,0,1},
   {-3,4,2},
   {4,0,2},
   {4,4,2}};

static struct patval fuseki131754[] = {
   {-3,-3,1},
   {3,-2,1},
   {2,0,1},
   {-3,4,2},
   {4,0,2},
   {4,4,2}};

static struct patval fuseki131755[] = {
   {3,4,1},
   {4,-4,1},
   {3,0,1},
   {-1,-4,1},
   {0,-4,1},
   {1,-4,2},
   {-3,-4,2},
   {-4,-3,2},
   {-4,4,2}};

static struct patval fuseki131756[] = {
   {-3,3,1},
   {-4,2,1},
   {-2,4,1},
   {-5,3,2},
   {-3,4,2},
   {-4,3,2}};

static struct patval fuseki131757[] = {
   {-3,3,1},
   {-4,2,1},
   {-2,4,1},
   {-5,3,2},
   {-3,4,2},
   {-4,3,2}};

static struct patval fuseki131758[] = {
   {-4,-3,1},
   {-3,4,1},
   {4,-3,1},
   {3,3,2},
   {0,-4,2}};

static struct patval fuseki131759[] = {
   {4,-1,1},
   {-3,3,1},
   {4,3,1},
   {4,-4,2},
   {-4,-3,2},
   {0,-4,2}};

static struct patval fuseki131760[] = {
   {-4,-3,1},
   {-4,1,1},
   {3,-3,1},
   {0,4,2},
   {-4,4,2},
   {4,3,2}};

static struct patval fuseki131761[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,3,2}};

static struct patval fuseki131762[] = {
   {-3,-3,1},
   {3,-3,1},
   {3,2,2}};

static struct patval fuseki131763[] = {
   {4,-3,1},
   {-3,-4,1},
   {1,4,1},
   {3,3,2},
   {-4,3,2}};

static struct patval fuseki131764[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,-1,1},
   {3,4,2},
   {3,-3,2}};

static struct patval fuseki131765[] = {
   {-4,-3,1},
   {-3,-4,1},
   {-4,0,1},
   {-4,3,1},
   {4,-3,1},
   {-2,-2,2},
   {-2,4,2},
   {-4,-2,2},
   {4,3,2}};

static struct patval fuseki131766[] = {
   {-4,3,1},
   {-3,-4,1},
   {-3,4,1},
   {3,4,1},
   {0,4,1},
   {-2,4,2},
   {3,-4,2},
   {-2,2,2},
   {4,2,2}};

static struct patval fuseki131767[] = {
   {4,4,1},
   {-3,4,1},
   {4,0,1},
   {3,-2,2},
   {-3,-3,2}};

static struct patval fuseki131768[] = {
   {3,3,1},
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {-4,-4,2}};

static struct patval fuseki131769[] = {
   {3,3,1},
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {-4,-4,2}};

static struct patval fuseki131770[] = {
   {-4,-4,1},
   {-4,4,1},
   {2,-4,1},
   {1,4,2},
   {4,-3,2},
   {4,3,2}};

static struct patval fuseki131771[] = {
   {-4,-2,1},
   {-4,4,1},
   {4,4,1},
   {3,-4,2},
   {4,-1,2},
   {-3,-4,2}};

static struct patval fuseki131772[] = {
   {-3,-3,1},
   {3,0,1},
   {-3,3,2}};

static struct patval fuseki131773[] = {
   {-3,0,1},
   {3,3,1},
   {3,-3,2}};

static struct patval fuseki131774[] = {
   {-3,-3,1},
   {3,3,1},
   {-1,-4,2}};

static struct patval fuseki131775[] = {
   {3,-3,1},
   {-3,3,1},
   {-4,1,2}};

static struct patval fuseki131776[] = {
   {3,-1,1},
   {-3,3,1},
   {0,4,1},
   {4,-1,1},
   {3,3,1},
   {-4,-3,2},
   {3,-3,2},
   {4,-2,2},
   {1,-4,2}};

static struct patval fuseki131777[] = {
   {3,2,1},
   {3,-3,1},
   {2,4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131778[] = {
   {3,-3,1},
   {2,4,1},
   {-3,3,2},
   {-4,-3,2}};

static struct patval fuseki131779[] = {
   {-3,3,1},
   {-2,-4,1},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131780[] = {
   {-4,-3,1},
   {-4,4,1},
   {-2,-4,1},
   {2,4,1},
   {0,4,2},
   {3,-4,2},
   {3,3,2},
   {4,-2,2}};

static struct patval fuseki131781[] = {
   {0,3,1},
   {-3,3,1},
   {-3,0,2}};

static struct patval fuseki131782[] = {
   {0,3,1},
   {3,3,1},
   {3,0,2}};

static struct patval fuseki131783[] = {
   {-4,2,1},
   {-4,4,1},
   {-3,4,2}};

static struct patval fuseki131784[] = {
   {-4,-4,1},
   {-2,-4,1},
   {-4,-3,2}};

static struct patval fuseki131785[] = {
   {3,-3,1},
   {-3,4,1},
   {-2,-3,1},
   {-4,-3,2},
   {3,3,2}};

static struct patval fuseki131786[] = {
   {-3,-4,1},
   {4,4,1},
   {4,-2,1},
   {4,2,2},
   {-3,3,2}};

static struct patval fuseki131787[] = {
   {-3,-4,1},
   {4,4,1},
   {4,-2,1},
   {4,2,2},
   {-3,3,2}};

static struct patval fuseki131788[] = {
   {-1,3,1},
   {3,3,1},
   {1,3,1},
   {2,-1,1},
   {4,-1,1},
   {0,1,2},
   {4,-3,2},
   {2,1,2},
   {4,1,2}};

static struct patval fuseki131789[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki131790[] = {
   {3,3,1},
   {-3,3,1},
   {-2,-4,1},
   {3,-3,2},
   {-3,-2,2}};

static struct patval fuseki131791[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-2,1},
   {3,3,2},
   {2,-3,2}};

static struct patval fuseki131792[] = {
   {-4,3,1},
   {2,-4,1},
   {4,-3,2}};

static struct patval fuseki131793[] = {
   {4,3,1},
   {-2,-4,1},
   {-4,-3,2}};

static struct patval fuseki131794[] = {
   {-4,-2,1},
   {2,4,1},
   {-3,3,1},
   {4,-3,1},
   {1,4,1},
   {-3,-4,2},
   {3,2,2},
   {1,3,2},
   {4,3,2}};

static struct patval fuseki131795[] = {
   {-4,-2,1},
   {2,4,1},
   {-3,3,1},
   {4,-3,1},
   {1,4,1},
   {-3,-4,2},
   {3,2,2},
   {1,3,2},
   {4,3,2}};

static struct patval fuseki131796[] = {
   {3,-3,1},
   {-4,-4,1},
   {-1,-3,1},
   {-3,-3,1},
   {-3,3,2},
   {-4,-1,2},
   {-5,-3,2},
   {3,3,2}};

static struct patval fuseki131797[] = {
   {4,-3,1},
   {2,1,1},
   {4,1,1},
   {1,3,2},
   {4,-1,2},
   {3,3,2}};

static struct patval fuseki131798[] = {
   {3,4,1},
   {-3,-2,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki131799[] = {
   {4,-3,1},
   {-2,3,1},
   {3,3,2},
   {-4,3,2}};

static struct patval fuseki131800[] = {
   {-4,-1,1},
   {-3,-3,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki131801[] = {
   {4,1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131802[] = {
   {3,3,1},
   {2,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131803[] = {
   {3,3,1},
   {2,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131804[] = {
   {4,1,1},
   {3,-4,1},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki131805[] = {
   {4,-3,1},
   {-1,-4,1},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki131806[] = {
   {-3,-3,1},
   {-3,3,1},
   {-3,4,1},
   {-1,4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131807[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,-3,1},
   {-3,3,2},
   {-4,-1,2},
   {3,3,2}};

static struct patval fuseki131808[] = {
   {-4,-2,1},
   {4,3,1},
   {-3,3,1},
   {4,-4,2},
   {-3,-4,2}};

static struct patval fuseki131809[] = {
   {-4,-2,1},
   {4,3,1},
   {-3,3,1},
   {4,-4,2},
   {-3,-4,2}};

static struct patval fuseki131810[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,4,2},
   {-4,2,2}};

static struct patval fuseki131811[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,4,2},
   {-4,2,2}};

static struct patval fuseki131812[] = {
   {4,3,1},
   {-4,4,1},
   {4,0,1},
   {4,-4,2},
   {-4,-3,2}};

static struct patval fuseki131813[] = {
   {3,-3,1},
   {-3,3,1},
   {0,0,1},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki131814[] = {
   {3,-3,1},
   {-3,3,1},
   {0,0,1},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki131815[] = {
   {-3,-3,1},
   {3,-3,1},
   {0,3,1},
   {-3,3,2},
   {3,3,2},
   {4,-1,2}};

static struct patval fuseki131816[] = {
   {3,-3,1},
   {-3,-3,1},
   {0,3,1},
   {-3,3,2},
   {-4,-1,2},
   {3,3,2}};

static struct patval fuseki131817[] = {
   {-4,-3,1},
   {4,-4,1},
   {-2,-4,1},
   {0,-4,2},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki131818[] = {
   {3,-3,1},
   {-3,-3,1},
   {0,-3,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki131819[] = {
   {-4,-3,1},
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {-2,-4,2},
   {3,-4,2},
   {4,4,2}};

static struct patval fuseki131820[] = {
   {3,3,1},
   {0,4,1},
   {-3,4,2}};

static struct patval fuseki131821[] = {
   {3,3,1},
   {4,0,1},
   {4,-3,2}};

static struct patval fuseki131822[] = {
   {-3,4,1},
   {4,-3,1},
   {4,3,2}};

static struct patval fuseki131823[] = {
   {-3,-4,1},
   {4,3,1},
   {4,-3,2}};

static struct patval fuseki131824[] = {
   {2,-4,1},
   {2,-3,1},
   {3,-5,2}};

static struct patval fuseki131825[] = {
   {2,3,1},
   {1,4,1},
   {3,3,1},
   {1,3,2},
   {3,2,2},
   {2,2,2}};

static struct patval fuseki131826[] = {
   {4,-2,1},
   {3,3,1},
   {3,-3,1},
   {0,4,1},
   {-2,4,2},
   {-3,-4,2},
   {-4,3,2},
   {4,-1,2}};

static struct patval fuseki131827[] = {
   {4,4,1},
   {-3,3,1},
   {4,-3,2},
   {-4,-3,2}};

static struct patval fuseki131828[] = {
   {4,-4,1},
   {3,3,1},
   {-3,4,2},
   {-3,-4,2}};

static struct patval fuseki131829[] = {
   {4,-5,1},
   {0,-3,1},
   {3,-4,1},
   {-3,3,2},
   {4,-4,2},
   {4,-3,2}};

static struct patval fuseki131830[] = {
   {4,-5,1},
   {0,-3,1},
   {3,-4,1},
   {-3,3,2},
   {4,-4,2},
   {4,-3,2}};

static struct patval fuseki131831[] = {
   {3,3,1},
   {3,-3,1},
   {-2,-4,1},
   {-4,3,2},
   {-4,-4,2}};

static struct patval fuseki131832[] = {
   {4,-2,1},
   {-3,3,1},
   {3,3,1},
   {4,-4,2},
   {-3,-4,2}};

static struct patval fuseki131833[] = {
   {3,-3,1},
   {4,1,1},
   {2,3,1},
   {-4,3,2},
   {4,-1,2},
   {-3,-4,2}};

static struct patval fuseki131834[] = {
   {3,-3,1},
   {-3,-3,1},
   {2,4,1},
   {-4,3,2},
   {4,3,2}};

static struct patval fuseki131835[] = {
   {3,3,1},
   {-3,3,1},
   {2,-4,1},
   {-4,-3,2},
   {4,-3,2}};

static struct patval fuseki131836[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {3,4,2},
   {4,-4,2}};

static struct patval fuseki131837[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {3,-4,2},
   {4,4,2}};

static struct patval fuseki131838[] = {
   {4,-2,1},
   {-3,3,1},
   {2,4,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki131839[] = {
   {4,-2,1},
   {-3,3,1},
   {2,4,1},
   {3,-4,2},
   {-4,-4,2}};

static struct patval fuseki131840[] = {
   {3,-2,1},
   {-3,4,1},
   {2,-4,1},
   {4,3,1},
   {3,-3,1},
   {-4,-4,2},
   {4,-3,2},
   {4,-2,2},
   {3,-4,2}};

static struct patval fuseki131841[] = {
   {4,-3,1},
   {-3,3,1},
   {2,4,1},
   {-3,-4,2},
   {4,3,2}};

static struct patval fuseki131842[] = {
   {4,4,1},
   {4,-2,1},
   {3,-4,1},
   {3,3,1},
   {-4,4,2},
   {4,1,2},
   {-4,-4,2},
   {5,3,2}};

static struct patval fuseki131843[] = {
   {4,-3,1},
   {4,-4,1},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131844[] = {
   {4,4,1},
   {3,4,1},
   {3,3,2},
   {3,-3,2}};

static struct patval fuseki131845[] = {
   {3,-3,1},
   {-3,-3,1},
   {4,0,1},
   {-4,2,2},
   {3,3,2},
   {-3,4,2}};

static struct patval fuseki131846[] = {
   {-4,0,1},
   {3,3,1},
   {-3,3,1},
   {3,-4,2},
   {-3,-3,2},
   {4,-2,2}};

static struct patval fuseki131847[] = {
   {3,4,1},
   {-3,3,1},
   {0,3,1},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki131848[] = {
   {4,-3,1},
   {3,3,1},
   {3,0,1},
   {-3,4,2},
   {-3,-3,2}};

static struct patval fuseki131849[] = {
   {-4,-3,1},
   {4,-4,1},
   {0,-4,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131850[] = {
   {-4,-3,1},
   {4,-3,1},
   {4,-4,1},
   {3,3,2},
   {3,-3,2},
   {-4,3,2}};

static struct patval fuseki131851[] = {
   {3,4,1},
   {4,-4,1},
   {3,-4,1},
   {3,-3,2},
   {-3,-3,2},
   {-3,4,2}};

static struct patval fuseki131852[] = {
   {3,3,1},
   {0,-4,1},
   {-2,-3,1},
   {-3,4,2},
   {-4,-3,2},
   {4,-3,2}};

static struct patval fuseki131853[] = {
   {3,2,1},
   {3,-4,2}};

static struct patval fuseki131854[] = {
   {3,-2,1},
   {3,4,2}};

static struct patval fuseki131855[] = {
   {-3,-3,1},
   {3,-3,1},
   {0,-3,1},
   {-3,4,2},
   {4,3,2}};

static struct patval fuseki131856[] = {
   {3,3,1},
   {3,0,1},
   {3,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131857[] = {
   {-3,4,1},
   {-2,-3,1},
   {4,-3,2}};

static struct patval fuseki131858[] = {
   {-4,3,1},
   {3,2,1},
   {3,-4,2}};

static struct patval fuseki131859[] = {
   {-4,-3,1},
   {-4,4,1},
   {3,4,2},
   {4,-4,2}};

static struct patval fuseki131860[] = {
   {3,2,1},
   {-3,3,1},
   {0,0,1},
   {2,-2,1},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki131861[] = {
   {3,-5,1},
   {2,-4,2}};

static struct patval fuseki131862[] = {
   {-4,-2,1},
   {4,4,1},
   {4,-4,1},
   {-2,4,2},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131863[] = {
   {4,-4,1},
   {-4,2,1},
   {4,4,1},
   {-2,-4,2},
   {-4,-3,2},
   {-3,4,2}};

static struct patval fuseki131864[] = {
   {4,4,1},
   {-4,4,1},
   {4,-3,2},
   {-4,-3,2}};

static struct patval fuseki131865[] = {
   {-4,-4,1},
   {-4,4,1},
   {3,-4,2},
   {3,4,2}};

static struct patval fuseki131866[] = {
   {4,-2,1},
   {-4,4,1},
   {3,1,1},
   {4,4,1},
   {3,-2,1},
   {1,-3,2},
   {4,-3,2},
   {-4,-3,2},
   {3,-4,2}};

static struct patval fuseki131867[] = {
   {-4,-4,1},
   {-4,4,1},
   {-1,-3,1},
   {2,-4,1},
   {2,-3,1},
   {3,-4,2},
   {3,-1,2},
   {3,4,2},
   {4,-3,2}};

static struct patval fuseki131868[] = {
   {-3,-4,1},
   {-3,3,1},
   {0,4,1},
   {3,-4,2},
   {4,4,2}};

static struct patval fuseki131869[] = {
   {-3,-3,1},
   {-3,4,1},
   {0,-4,1},
   {3,4,2},
   {4,-4,2}};

static struct patval fuseki131870[] = {
   {3,2,1},
   {3,-3,1},
   {-4,-4,2}};

static struct patval fuseki131871[] = {
   {4,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-2,3,1},
   {-2,4,2},
   {3,4,2},
   {-4,3,2},
   {4,2,2}};

static struct patval fuseki131872[] = {
   {4,0,1},
   {-3,-3,1},
   {3,-3,1},
   {-4,3,2},
   {4,4,2}};

static struct patval fuseki131873[] = {
   {4,-3,1},
   {-4,0,1},
   {-4,3,1},
   {-3,-4,1},
   {-2,4,2},
   {-4,-2,2},
   {4,3,2}};

static struct patval fuseki131874[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,-4,1},
   {2,-3,2},
   {2,-4,2},
   {4,4,2}};

static struct patval fuseki131875[] = {
   {3,3,1},
   {-3,-3,1},
   {3,-3,1},
   {4,3,1},
   {-4,4,2},
   {4,2,2},
   {3,2,2}};

static struct patval fuseki131876[] = {
   {-4,2,1},
   {-4,-3,2}};

static struct patval fuseki131877[] = {
   {2,-4,1},
   {-3,-4,2}};

static struct patval fuseki131878[] = {
   {-4,-4,1},
   {5,-4,1},
   {4,-2,1},
   {3,3,2},
   {3,-4,2},
   {-4,3,2}};

static struct patval fuseki131879[] = {
   {-4,-5,1},
   {-2,-4,1},
   {-4,4,1},
   {-4,-3,2},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki131880[] = {
   {3,3,1},
   {-3,-3,1},
   {4,-3,1},
   {3,-3,1},
   {-4,4,2},
   {4,-4,2},
   {3,-4,2}};

static struct patval fuseki131881[] = {
   {3,4,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {-4,-4,2},
   {4,3,2},
   {4,4,2}};

static struct patval fuseki131882[] = {
   {-4,3,1},
   {4,-3,1},
   {3,4,1},
   {-2,4,2},
   {-3,-3,2}};

static struct patval fuseki131883[] = {
   {-4,3,1},
   {4,-3,1},
   {3,4,1},
   {-2,4,2},
   {-3,-3,2}};

static struct patval fuseki131884[] = {
   {-4,-1,1},
   {-4,3,1},
   {-3,-4,1},
   {0,4,1},
   {3,-3,2},
   {4,4,2},
   {5,-1,2}};

static struct patval fuseki131885[] = {
   {-2,3,1},
   {-4,2,1},
   {-4,3,2},
   {-4,-3,2}};

static struct patval fuseki131886[] = {
   {-4,-2,1},
   {-3,-4,1},
   {3,-3,1},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131887[] = {
   {-4,-2,1},
   {3,-2,1},
   {-3,-4,2},
   {-4,4,2}};

static struct patval fuseki131888[] = {
   {-4,-2,1},
   {3,-2,1},
   {-3,-4,2},
   {-4,4,2}};

static struct patval fuseki131889[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {1,-4,1},
   {-1,4,2},
   {-1,2,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki131890[] = {
   {4,0,1},
   {-3,3,1},
   {3,3,1},
   {4,-2,2},
   {-4,-4,2}};

static struct patval fuseki131891[] = {
   {-4,-2,1},
   {4,4,1},
   {4,-3,1},
   {-2,4,2},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131892[] = {
   {-4,-3,1},
   {-4,4,1},
   {4,-2,1},
   {3,-4,2},
   {2,4,2},
   {4,3,2}};

static struct patval fuseki131893[] = {
   {-4,-3,1},
   {-4,4,1},
   {-3,-4,1},
   {-1,-4,2},
   {3,4,2},
   {4,-4,2}};

static struct patval fuseki131894[] = {
   {-4,4,1},
   {3,-3,1},
   {-3,-4,2}};

static struct patval fuseki131895[] = {
   {-4,-4,1},
   {3,3,1},
   {-3,4,2}};

static struct patval fuseki131896[] = {
   {-4,-3,1},
   {-4,2,1},
   {4,-4,1},
   {-3,2,1},
   {-3,4,2},
   {3,4,2},
   {-4,3,2},
   {4,2,2}};

static struct patval fuseki131897[] = {
   {3,-4,1},
   {4,4,1},
   {-2,-3,1},
   {-2,-4,1},
   {-3,-4,2},
   {-2,4,2},
   {-4,-3,2},
   {-4,3,2}};

static struct patval fuseki131898[] = {
   {4,-4,1},
   {-4,4,1},
   {3,3,2},
   {-4,-4,2}};

static struct patval fuseki131899[] = {
   {-4,4,1},
   {4,-4,1},
   {-3,-3,2},
   {4,4,2}};

static struct patval fuseki131900[] = {
   {-4,-3,1},
   {3,-3,1},
   {2,3,1},
   {-4,4,2},
   {4,3,2}};

static struct patval fuseki131901[] = {
   {4,-3,1},
   {-3,-3,1},
   {-2,3,1},
   {-4,3,2},
   {4,4,2}};

static struct patval fuseki131902[] = {
   {-4,-4,1},
   {4,4,1},
   {4,-2,2},
   {3,-4,2}};

static struct patval fuseki131903[] = {
   {3,-3,1},
   {4,4,1},
   {-1,4,1},
   {2,4,1},
   {2,3,2},
   {-4,-3,2},
   {-4,4,2}};

static struct patval fuseki131904[] = {
   {-4,-4,1},
   {4,3,1},
   {-3,3,2}};

static struct patval fuseki131905[] = {
   {-4,-4,1},
   {3,4,1},
   {3,-3,2}};

static struct patval fuseki131906[] = {
   {3,-3,1},
   {-4,-1,1},
   {-3,-2,1},
   {3,3,1},
   {-4,3,2},
   {-2,4,2},
   {-4,-2,2},
   {-3,-4,2}};

static struct patval fuseki131907[] = {
   {3,-3,1},
   {-4,-1,1},
   {-3,-2,1},
   {3,3,1},
   {-4,3,2},
   {-2,4,2},
   {-4,-2,2},
   {-3,-4,2}};

static struct patval fuseki131908[] = {
   {3,3,1},
   {0,0,1},
   {-3,3,2}};

static struct patval fuseki131909[] = {
   {-3,-3,1},
   {0,0,1},
   {-3,3,2}};

static struct patval fuseki131910[] = {
   {-4,3,1},
   {-3,-4,1},
   {0,4,1},
   {4,4,2},
   {5,-1,2}};

static struct patval fuseki131911[] = {
   {-4,-2,1},
   {2,5,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131912[] = {
   {-4,-2,1},
   {2,5,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131913[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131914[] = {
   {-4,3,1},
   {-3,-4,1},
   {-2,4,1},
   {3,-4,2},
   {3,3,2}};

static struct patval fuseki131915[] = {
   {-4,-3,1},
   {3,-3,1},
   {1,-3,1},
   {-3,3,2},
   {3,3,2},
   {4,-1,2}};

static struct patval fuseki131916[] = {
   {-1,-3,1},
   {-3,-3,1},
   {4,-3,1},
   {-4,-1,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki131917[] = {
   {2,2,1},
   {3,0,1},
   {4,1,1},
   {3,2,1},
   {3,3,2},
   {3,1,2},
   {4,2,2},
   {4,3,2}};

static struct patval fuseki131918[] = {
   {4,-3,1},
   {-3,-3,1},
   {4,2,1},
   {1,-4,1},
   {3,4,2},
   {-4,4,2},
   {-1,-4,2}};

static struct patval fuseki131919[] = {
   {3,3,1},
   {3,-3,1},
   {-1,-4,1},
   {-3,3,2},
   {-3,-4,2}};

static struct patval fuseki131920[] = {
   {-4,-3,1},
   {3,3,1},
   {3,-3,2},
   {-3,4,2}};

static struct patval fuseki131921[] = {
   {4,-3,1},
   {-4,4,1},
   {-4,-3,2},
   {4,3,2}};

static struct patval fuseki131922[] = {
   {4,-4,1},
   {-4,3,1},
   {-4,-3,2},
   {4,3,2}};

static struct patval fuseki131923[] = {
   {-4,-4,1},
   {3,-4,1},
   {2,4,2},
   {-3,3,2}};

static struct patval fuseki131924[] = {
   {-4,-2,1},
   {-3,-4,1},
   {4,4,2}};

static struct patval fuseki131925[] = {
   {-4,2,1},
   {-3,4,1},
   {4,-4,2}};

static struct patval fuseki131926[] = {
   {-4,-3,1},
   {-4,4,1},
   {-3,-4,1},
   {1,-4,1},
   {-1,-4,2},
   {3,0,2},
   {3,4,2},
   {4,-4,2}};

static struct patval fuseki131927[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-4,1},
   {3,-4,2},
   {4,3,2}};

static struct patval fuseki131928[] = {
   {3,3,1},
   {3,-3,1},
   {0,-4,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131929[] = {
   {-4,-1,1},
   {3,-3,1},
   {-3,-3,1},
   {-4,4,2},
   {3,3,2}};

static struct patval fuseki131930[] = {
   {-4,-4,1},
   {3,-4,1},
   {-4,4,2},
   {4,3,2}};

static struct patval fuseki131931[] = {
   {4,-4,1},
   {-3,-4,1},
   {-4,3,2},
   {4,4,2}};

static struct patval fuseki131932[] = {
   {-5,-3,1},
   {-4,-1,1},
   {3,3,1},
   {-3,3,1},
   {-1,-3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131933[] = {
   {3,3,1},
   {4,2,1},
   {3,-3,1},
   {-4,3,2},
   {4,1,2},
   {-3,-4,2}};

static struct patval fuseki131934[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,2,1},
   {3,-4,2},
   {3,4,2}};

static struct patval fuseki131935[] = {
   {3,3,1},
   {-3,3,1},
   {2,-3,1},
   {-4,-3,2},
   {4,-3,2}};

static struct patval fuseki131936[] = {
   {-4,-4,1},
   {-4,4,1},
   {-3,0,1},
   {3,-4,2},
   {3,4,2}};

static struct patval fuseki131937[] = {
   {-4,-4,1},
   {-4,4,1},
   {-3,0,1},
   {3,-4,2},
   {3,4,2}};

static struct patval fuseki131938[] = {
   {-2,-4,1},
   {-4,3,1},
   {-4,-3,2},
   {4,-3,2}};

static struct patval fuseki131939[] = {
   {-4,-3,1},
   {-2,4,1},
   {-4,3,2},
   {4,3,2}};

static struct patval fuseki131940[] = {
   {4,-1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,2},
   {-4,-4,2}};

static struct patval fuseki131941[] = {
   {4,-1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,2},
   {-4,-4,2}};

static struct patval fuseki131942[] = {
   {-4,3,1},
   {-3,-4,1},
   {4,1,1},
   {3,1,1},
   {3,3,2},
   {3,-3,2},
   {4,2,2}};

static struct patval fuseki131943[] = {
   {-4,-3,1},
   {3,-3,1},
   {-3,-4,2},
   {-4,3,2}};

static struct patval fuseki131944[] = {
   {-4,-4,1},
   {-4,-3,1},
   {-4,4,1},
   {-3,-2,1},
   {-3,-3,2},
   {-3,-4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131945[] = {
   {-4,-4,1},
   {-4,3,1},
   {-4,4,1},
   {-3,2,1},
   {-3,3,2},
   {-3,4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131946[] = {
   {-3,-4,1},
   {-3,-2,1},
   {-3,3,1},
   {-1,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131947[] = {
   {-4,3,1},
   {3,3,1},
   {-2,3,1},
   {-3,1,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki131948[] = {
   {-4,-2,1},
   {4,3,1},
   {-2,4,1},
   {-3,-4,2},
   {4,-3,2},
   {-4,3,2}};

static struct patval fuseki131949[] = {
   {-3,-3,1},
   {3,-2,1},
   {-3,4,2},
   {4,4,2}};

static struct patval fuseki131950[] = {
   {4,4,1},
   {3,-3,1},
   {1,-4,1},
   {-3,-4,2},
   {-4,4,2}};

static struct patval fuseki131951[] = {
   {3,-3,1},
   {4,2,1},
   {1,3,1},
   {3,3,1},
   {3,1,2},
   {-4,3,2},
   {4,1,2},
   {-3,-4,2}};

static struct patval fuseki131952[] = {
   {2,-4,1},
   {2,-3,1},
   {2,-2,1},
   {2,-1,1},
   {3,-5,2},
   {3,-4,2},
   {3,-2,2}};

static struct patval fuseki131953[] = {
   {-3,-3,1},
   {2,2,1},
   {2,3,1},
   {3,2,1},
   {3,3,2},
   {4,3,2},
   {5,1,2}};

static struct patval fuseki131954[] = {
   {-3,-3,1},
   {3,3,1},
   {3,0,2},
   {3,-3,2}};

static struct patval fuseki131955[] = {
   {4,-2,1},
   {-3,4,1},
   {3,-4,1},
   {-4,-4,2},
   {4,4,2}};

static struct patval fuseki131956[] = {
   {-4,-2,1},
   {-4,4,1},
   {4,4,1},
   {3,-4,2},
   {4,0,2},
   {-3,-4,2}};

static struct patval fuseki131957[] = {
   {-4,-2,1},
   {-4,4,1},
   {4,4,1},
   {3,-4,2},
   {4,0,2},
   {-3,-4,2}};

static struct patval fuseki131958[] = {
   {3,2,1},
   {3,-3,1},
   {-4,4,2}};

static struct patval fuseki131959[] = {
   {3,3,1},
   {3,-2,1},
   {-4,-4,2}};

static struct patval fuseki131960[] = {
   {3,-2,1},
   {4,-2,1},
   {3,-4,1},
   {3,-5,1},
   {2,-1,2},
   {2,-2,2},
   {2,-4,2},
   {2,-3,2}};

static struct patval fuseki131961[] = {
   {3,-3,1},
   {4,3,1},
   {-2,4,1},
   {3,-5,1},
   {1,4,1},
   {1,-4,2},
   {-1,-3,2},
   {-4,-4,2},
   {-4,4,2}};

static struct patval fuseki131962[] = {
   {-4,3,1},
   {3,4,1},
   {3,2,1},
   {-3,-4,2},
   {4,-3,2}};

static struct patval fuseki131963[] = {
   {4,3,1},
   {-3,2,1},
   {-3,4,1},
   {3,-4,2},
   {-4,-3,2}};

static struct patval fuseki131964[] = {
   {4,3,1},
   {-4,4,1},
   {4,-3,2},
   {-4,-3,2}};

static struct patval fuseki131965[] = {
   {4,4,1},
   {-4,3,1},
   {4,-3,2},
   {-4,-3,2}};

static struct patval fuseki131966[] = {
   {4,-4,1},
   {-3,2,1},
   {4,4,1},
   {-2,-4,2},
   {-4,-3,2},
   {-3,4,2}};

static struct patval fuseki131967[] = {
   {4,-4,1},
   {4,4,1},
   {-3,-2,1},
   {-2,4,2},
   {-4,3,2},
   {-3,-4,2}};

static struct patval fuseki131968[] = {
   {-4,-3,1},
   {3,4,1},
   {3,-3,1},
   {-2,-4,2},
   {-4,4,2}};

static struct patval fuseki131969[] = {
   {-4,-1,1},
   {4,4,1},
   {3,-4,1},
   {0,4,2},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki131970[] = {
   {-4,3,1},
   {4,4,1},
   {-1,-4,1},
   {3,-3,2},
   {4,0,2},
   {-3,-3,2}};

static struct patval fuseki131971[] = {
   {-3,-3,1},
   {4,2,1},
   {3,-3,1},
   {3,2,1},
   {3,3,2},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki131972[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,3,1},
   {2,4,1},
   {3,-3,2},
   {3,3,2},
   {3,4,2}};

static struct patval fuseki131973[] = {
   {4,3,1},
   {3,-3,1},
   {-2,4,2}};

static struct patval fuseki131974[] = {
   {3,3,1},
   {-3,4,1},
   {-4,-2,2}};

static struct patval fuseki131975[] = {
   {-4,-2,1},
   {4,4,1},
   {3,-3,2},
   {-3,4,2}};

static struct patval fuseki131976[] = {
   {2,-4,1},
   {-4,4,1},
   {-4,-3,2},
   {3,3,2}};

static struct patval fuseki131977[] = {
   {-3,-3,1},
   {3,-3,1},
   {2,-2,2},
   {0,0,2}};

static struct patval fuseki131978[] = {
   {-4,-4,1},
   {-4,4,1},
   {-1,-3,1},
   {2,-4,1},
   {3,-1,2},
   {3,3,2},
   {4,-3,2}};

static struct patval fuseki131979[] = {
   {-4,-4,1},
   {-4,4,1},
   {-1,3,1},
   {2,4,1},
   {3,-3,2},
   {3,1,2},
   {4,3,2}};

static struct patval fuseki131980[] = {
   {-4,-4,1},
   {-4,4,1},
   {4,-1,1},
   {3,-3,2},
   {3,3,2},
   {0,4,2}};

static struct patval fuseki131981[] = {
   {-4,-4,1},
   {4,-4,1},
   {-4,3,2},
   {4,4,2}};

static struct patval fuseki131982[] = {
   {-4,-4,1},
   {4,-4,1},
   {-4,3,2},
   {4,4,2}};

static struct patval fuseki131983[] = {
   {4,2,1},
   {3,4,1},
   {2,3,2}};

static struct patval fuseki131984[] = {
   {4,2,1},
   {3,4,1},
   {2,3,2}};

static struct patval fuseki131985[] = {
   {3,-3,1},
   {3,3,1},
   {-3,-3,1},
   {-3,-4,1},
   {-4,4,2},
   {-4,-4,2},
   {-4,-3,2}};

static struct patval fuseki131986[] = {
   {3,4,1},
   {3,-3,1},
   {-1,4,1},
   {-3,3,2},
   {-4,-4,2}};

static struct patval fuseki131987[] = {
   {-3,-4,1},
   {-3,3,1},
   {1,-4,1},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki131988[] = {
   {-3,-3,1},
   {-3,1,1},
   {3,-3,1},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki131989[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki131990[] = {
   {-4,-3,1},
   {-4,4,1},
   {2,3,1},
   {1,4,1},
   {-1,4,2},
   {2,4,2},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki131991[] = {
   {-4,-3,1},
   {-4,4,1},
   {2,3,1},
   {1,4,1},
   {-1,4,2},
   {2,4,2},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki131992[] = {
   {3,3,1},
   {-4,3,1},
   {4,-1,1},
   {3,-3,2},
   {-4,-1,2},
   {-3,-3,2}};

static struct patval fuseki131993[] = {
   {-4,-4,1},
   {-4,1,1},
   {4,-4,1},
   {-4,4,2},
   {4,4,2}};

static struct patval fuseki131994[] = {
   {4,4,1},
   {4,-4,1},
   {-1,4,1},
   {-4,4,2},
   {-4,-4,2}};

static struct patval fuseki131995[] = {
   {3,4,1},
   {-4,3,1},
   {-3,-4,1},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki131996[] = {
   {3,4,1},
   {-4,3,1},
   {-3,-4,1},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki131997[] = {
   {-4,-4,1},
   {-4,4,1},
   {1,-4,1},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki131998[] = {
   {-4,4,1},
   {4,4,1},
   {4,-1,1},
   {3,-3,2},
   {0,-3,2},
   {-3,-3,2}};

static struct patval fuseki131999[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132000[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132001[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132002[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132003[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132004[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132005[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132006[] = {
   {4,1,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki132007[] = {
   {-1,4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132008[] = {
   {-4,-1,1},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132009[] = {
   {4,1,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki132010[] = {
   {1,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132011[] = {
   {1,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132012[] = {
   {-1,4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132013[] = {
   {-3,3,1},
   {3,-3,1}};

static struct patval fuseki132014[] = {
   {-3,3,1},
   {3,-3,1}};

static struct patval fuseki132015[] = {
   {-3,3,1},
   {3,-3,1}};

static struct patval fuseki132016[] = {
   {-3,3,1},
   {3,-3,1}};

static struct patval fuseki132017[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1}};

static struct patval fuseki132018[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1}};

static struct patval fuseki132019[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1}};

static struct patval fuseki132020[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1}};

static struct patval fuseki132021[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1}};

static struct patval fuseki132022[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1}};

static struct patval fuseki132023[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132024[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132025[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132026[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132027[] = {
   {-4,-1,1},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132028[] = {
   {-1,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132029[] = {
   {4,-1,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132030[] = {
   {-1,4,1},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132031[] = {
   {-4,1,1},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132032[] = {
   {4,-1,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132033[] = {
   {4,1,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132034[] = {
   {4,-1,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132035[] = {
   {4,1,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132036[] = {
   {-1,4,1},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132037[] = {
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132038[] = {
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132039[] = {
   {3,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132040[] = {
   {-3,-3,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132041[] = {
   {-3,-3,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132042[] = {
   {3,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132043[] = {
   {4,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132044[] = {
   {3,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132045[] = {
   {3,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132046[] = {
   {4,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132047[] = {
   {4,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132048[] = {
   {4,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132049[] = {
   {4,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132050[] = {
   {-4,-3,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132051[] = {
   {-3,-4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132052[] = {
   {-4,-3,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132053[] = {
   {4,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132054[] = {
   {-4,-3,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132055[] = {
   {4,3,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132056[] = {
   {3,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132057[] = {
   {3,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132058[] = {
   {3,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132059[] = {
   {3,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132060[] = {
   {3,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132061[] = {
   {0,3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132062[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,1},
   {4,1,2}};

static struct patval fuseki132063[] = {
   {-4,-1,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {-4,1,2}};

static struct patval fuseki132064[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,1},
   {4,1,2}};

static struct patval fuseki132065[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {3,-3,1},
   {3,3,1},
   {3,0,2}};

static struct patval fuseki132066[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {0,3,2}};

static struct patval fuseki132067[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {3,-3,1},
   {3,3,1},
   {3,0,2}};

static struct patval fuseki132068[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {3,-3,1},
   {3,3,1},
   {3,0,2}};

static struct patval fuseki132069[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {0,3,2}};

static struct patval fuseki132070[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {0,3,2}};

static struct patval fuseki132071[] = {
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-1,-3,1},
   {3,-3,1},
   {-3,0,2}};

static struct patval fuseki132072[] = {
   {0,4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132073[] = {
   {0,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132074[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132075[] = {
   {-1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132076[] = {
   {4,-1,1},
   {1,-4,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132077[] = {
   {1,4,1},
   {4,1,1},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {4,-1,2},
   {-3,3,2}};

static struct patval fuseki132078[] = {
   {4,-1,1},
   {1,-4,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132079[] = {
   {4,-1,1},
   {1,-4,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132080[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132081[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132082[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132083[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132084[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132085[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132086[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132087[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132088[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132089[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132090[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132091[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132092[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132093[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132094[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132095[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132096[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,1},
   {-3,-3,2}};

static struct patval fuseki132097[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132098[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132099[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132100[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,1},
   {-3,-3,2}};

static struct patval fuseki132101[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1}};

static struct patval fuseki132102[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1}};

static struct patval fuseki132103[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1}};

static struct patval fuseki132104[] = {
   {4,4,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132105[] = {
   {3,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132106[] = {
   {4,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132107[] = {
   {3,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132108[] = {
   {4,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132109[] = {
   {3,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132110[] = {
   {3,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132111[] = {
   {4,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132112[] = {
   {3,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132113[] = {
   {3,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132114[] = {
   {4,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132115[] = {
   {4,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132116[] = {
   {3,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132117[] = {
   {4,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132118[] = {
   {4,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132119[] = {
   {3,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132120[] = {
   {4,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132121[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132122[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132123[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132124[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132125[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,1,1},
   {3,3,2}};

static struct patval fuseki132126[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132127[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132128[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132129[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,1,1},
   {3,3,2}};

static struct patval fuseki132130[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,1,1},
   {3,3,2}};

static struct patval fuseki132131[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132132[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,1,1},
   {3,3,2}};

static struct patval fuseki132133[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132134[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2},
   {-1,3,2}};

static struct patval fuseki132135[] = {
   {3,-3,1},
   {-4,2,1},
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-1,3,1},
   {-4,1,2},
   {-3,1,2}};

static struct patval fuseki132136[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2},
   {-1,3,2}};

static struct patval fuseki132137[] = {
   {-3,-3,1},
   {-3,-1,1},
   {-3,3,1},
   {-2,-4,1},
   {3,3,1},
   {3,-3,1},
   {-1,-3,2},
   {-1,-4,2}};

static struct patval fuseki132138[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2},
   {-1,3,2}};

static struct patval fuseki132139[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-1,1},
   {3,3,1},
   {2,-4,1},
   {3,-3,1},
   {1,-4,2},
   {1,-3,2}};

static struct patval fuseki132140[] = {
   {-3,-3,1},
   {-3,-1,1},
   {-3,3,1},
   {-2,-4,1},
   {3,3,1},
   {3,-3,1},
   {-1,-3,2},
   {-1,-4,2}};

static struct patval fuseki132141[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {3,-3,1},
   {4,2,1},
   {3,3,1},
   {4,1,2},
   {3,1,2}};

static struct patval fuseki132142[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {3,-3,1},
   {4,-2,1},
   {3,3,1},
   {3,-1,2},
   {4,-1,2}};

static struct patval fuseki132143[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2},
   {-1,3,2}};

static struct patval fuseki132144[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-3,4,1},
   {0,0,1},
   {3,3,1},
   {-4,4,2}};

static struct patval fuseki132145[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {4,4,2}};

static struct patval fuseki132146[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {4,4,2}};

static struct patval fuseki132147[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki132148[] = {
   {4,4,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki132149[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {3,-1,1},
   {1,-4,2}};

static struct patval fuseki132150[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,3,1},
   {3,3,1},
   {-4,1,2}};

static struct patval fuseki132151[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,-3,1},
   {3,3,1},
   {-4,-1,2}};

static struct patval fuseki132152[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {3,1,1},
   {1,4,2}};

static struct patval fuseki132153[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132154[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,3,1},
   {3,3,1},
   {-4,1,2}};

static struct patval fuseki132155[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {3,-3,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki132156[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132157[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132158[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132159[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {3,-3,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki132160[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,-1,1},
   {-3,3,1},
   {3,3,1},
   {-4,-1,2}};

static struct patval fuseki132161[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {-1,-3,1},
   {3,-3,1},
   {-1,-4,2}};

static struct patval fuseki132162[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {-4,1,2}};

static struct patval fuseki132163[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {2,4,1},
   {3,-3,1},
   {0,4,2}};

static struct patval fuseki132164[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,-2,1},
   {4,0,2}};

static struct patval fuseki132165[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {0,4,2}};

static struct patval fuseki132166[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {0,4,2}};

static struct patval fuseki132167[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,-2,1},
   {4,0,2}};

static struct patval fuseki132168[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {3,3,1},
   {3,-3,1},
   {0,-4,2}};

static struct patval fuseki132169[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {2,4,1},
   {3,-3,1},
   {0,4,2}};

static struct patval fuseki132170[] = {
   {3,0,1},
   {3,4,1},
   {1,-3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132171[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {3,-3,1},
   {4,4,1},
   {3,3,1},
   {3,4,2},
   {3,0,2}};

static struct patval fuseki132172[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {4,-4,1},
   {3,-3,1},
   {3,3,1},
   {3,0,2},
   {3,-4,2}};

static struct patval fuseki132173[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132174[] = {
   {4,3,1},
   {-3,3,1},
   {3,-3,1},
   {-3,-3,2}};

static struct patval fuseki132175[] = {
   {3,4,1},
   {-3,3,1},
   {3,-3,1},
   {-3,-3,2}};

static struct patval fuseki132176[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132177[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132178[] = {
   {-4,-2,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {-4,-1,2}};

static struct patval fuseki132179[] = {
   {-4,-4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132180[] = {
   {-4,-4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132181[] = {
   {4,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132182[] = {
   {-4,-4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132183[] = {
   {4,4,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132184[] = {
   {-4,-4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132185[] = {
   {-4,-4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132186[] = {
   {-1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132187[] = {
   {-4,1,1},
   {-3,1,1},
   {-3,-3,2},
   {-4,2,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132188[] = {
   {-4,1,1},
   {-3,1,1},
   {-3,-3,2},
   {-4,2,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132189[] = {
   {-4,1,1},
   {-3,1,1},
   {-3,-3,2},
   {-4,2,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132190[] = {
   {-1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132191[] = {
   {4,1,1},
   {3,1,1},
   {0,0,2},
   {3,-3,2},
   {-3,3,2},
   {3,3,2},
   {-3,-3,2},
   {4,2,2}};

static struct patval fuseki132192[] = {
   {-1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132193[] = {
   {-3,-1,1},
   {-4,-1,1},
   {-3,-3,2},
   {-4,-2,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132194[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {4,4,2}};

static struct patval fuseki132195[] = {
   {-4,3,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {-4,4,2}};

static struct patval fuseki132196[] = {
   {3,4,1},
   {4,4,1},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,3,2},
   {-3,3,2}};

static struct patval fuseki132197[] = {
   {3,4,1},
   {4,4,1},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,3,2},
   {-3,3,2}};

static struct patval fuseki132198[] = {
   {4,-4,1},
   {3,-4,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,-3,2}};

static struct patval fuseki132199[] = {
   {4,-4,1},
   {4,-3,1},
   {3,-4,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132200[] = {
   {4,-4,1},
   {-3,0,2},
   {-3,-3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132201[] = {
   {-4,-4,1},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132202[] = {
   {-4,4,1},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132203[] = {
   {4,-4,1},
   {-3,0,2},
   {-3,-3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132204[] = {
   {4,4,1},
   {-3,0,2},
   {-3,-3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132205[] = {
   {-4,-4,1},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132206[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-4,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132207[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-4,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132208[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {3,3,1},
   {-4,1,2}};

static struct patval fuseki132209[] = {
   {-4,1,1},
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132210[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-1,1},
   {3,-3,1},
   {3,3,1},
   {1,-4,2}};

static struct patval fuseki132211[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-4,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132212[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-1,1},
   {3,-3,1},
   {3,3,1},
   {1,-4,2}};

static struct patval fuseki132213[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,1,1},
   {3,-3,1},
   {3,3,1},
   {1,4,2}};

static struct patval fuseki132214[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki132215[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,1,1},
   {3,-3,1},
   {3,3,1},
   {1,4,2}};

static struct patval fuseki132216[] = {
   {3,4,1},
   {3,0,1},
   {2,3,1},
   {1,-3,2},
   {3,-3,2},
   {-3,3,2},
   {3,3,2},
   {-3,-3,2},
   {4,4,2}};

static struct patval fuseki132217[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {4,1,1},
   {4,-1,2}};

static struct patval fuseki132218[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,1},
   {4,1,2}};

static struct patval fuseki132219[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,1},
   {4,1,2}};

static struct patval fuseki132220[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,-4,1},
   {0,0,1},
   {3,3,1},
   {3,-3,1},
   {1,-4,2}};

static struct patval fuseki132221[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,1},
   {4,1,2}};

static struct patval fuseki132222[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {0,0,1},
   {1,-4,1},
   {3,-3,1},
   {-1,-4,2}};

static struct patval fuseki132223[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {2,-1,1},
   {4,4,1},
   {3,-3,1},
   {4,3,1},
   {3,3,1},
   {3,2,2},
   {3,4,2},
   {3,0,2},
   {2,3,2}};

static struct patval fuseki132224[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {2,-1,1},
   {4,4,1},
   {3,-3,1},
   {4,3,1},
   {3,3,1},
   {3,2,2},
   {3,4,2},
   {3,0,2},
   {2,3,2}};

static struct patval fuseki132225[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132226[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132227[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132228[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132229[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132230[] = {
   {3,0,1},
   {3,4,1},
   {2,3,1},
   {3,2,1},
   {1,-3,2},
   {3,-3,2},
   {-3,-3,2},
   {2,-1,2},
   {3,3,2},
   {-3,3,2},
   {4,4,2}};

static struct patval fuseki132231[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132232[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132233[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132234[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132235[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132236[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132237[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1}};

static struct patval fuseki132238[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {2,-1,1},
   {4,4,1},
   {3,-3,1},
   {3,3,1},
   {3,0,2},
   {3,4,2},
   {2,3,2}};

static struct patval fuseki132239[] = {
   {0,3,1},
   {-1,4,1},
   {-1,3,2},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132240[] = {
   {-4,-1,1},
   {-3,0,1},
   {-3,-1,2},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132241[] = {
   {0,3,1},
   {-1,4,1},
   {-1,3,2},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132242[] = {
   {-4,3,1},
   {-4,4,1},
   {-3,-3,2},
   {-3,3,2},
   {-3,4,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132243[] = {
   {4,3,1},
   {4,4,1},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {3,4,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132244[] = {
   {-3,-1,1},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132245[] = {
   {-1,3,1},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132246[] = {
   {-3,1,1},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132247[] = {
   {-3,1,1},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132248[] = {
   {3,1,1},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132249[] = {
   {-3,-1,1},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132250[] = {
   {-1,-3,1},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132251[] = {
   {3,1,1},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132252[] = {
   {3,4,1},
   {3,2,1},
   {3,0,1},
   {2,4,1},
   {2,3,1},
   {2,-1,2},
   {3,-3,2},
   {1,-3,2},
   {-3,3,2},
   {3,3,2},
   {-3,-3,2},
   {4,3,2},
   {4,4,2}};

static struct patval fuseki132253[] = {
   {3,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132254[] = {
   {4,-3,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki132255[] = {
   {4,-3,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki132256[] = {
   {-3,-4,1},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132257[] = {
   {0,0,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132258[] = {
   {0,0,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132259[] = {
   {0,0,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132260[] = {
   {3,2,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132261[] = {
   {2,3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132262[] = {
   {3,2,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132263[] = {
   {3,2,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132264[] = {
   {2,3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132265[] = {
   {3,2,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132266[] = {
   {2,3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132267[] = {
   {2,3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132268[] = {
   {-4,2,1},
   {3,3,1},
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-3,4,1},
   {0,0,1},
   {-4,4,2},
   {-4,3,2}};

static struct patval fuseki132269[] = {
   {-4,2,1},
   {3,3,1},
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-3,4,1},
   {0,0,1},
   {-4,4,2},
   {-4,3,2}};

static struct patval fuseki132270[] = {
   {-4,3,1},
   {3,0,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1},
   {-4,4,2}};

static struct patval fuseki132271[] = {
   {3,-3,1},
   {-4,-3,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,3,1},
   {3,0,1},
   {-4,-4,2}};

static struct patval fuseki132272[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1},
   {4,-3,1},
   {4,-4,2}};

static struct patval fuseki132273[] = {
   {3,-3,1},
   {-3,-4,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,3,1},
   {3,0,1},
   {-4,-4,2}};

static struct patval fuseki132274[] = {
   {-3,1,1},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132275[] = {
   {3,1,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132276[] = {
   {-1,-3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132277[] = {
   {1,3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132278[] = {
   {1,-3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132279[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki132280[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132281[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132282[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki132283[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,1},
   {-3,-4,2}};

static struct patval fuseki132284[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132285[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132286[] = {
   {3,4,1},
   {-3,3,1},
   {3,-3,1},
   {-4,-3,2}};

static struct patval fuseki132287[] = {
   {3,4,1},
   {-3,3,1},
   {3,-3,1},
   {-4,-3,2}};

static struct patval fuseki132288[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki132289[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132290[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki132291[] = {
   {4,-1,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki132292[] = {
   {3,3,1},
   {-1,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132293[] = {
   {3,3,1},
   {-1,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132294[] = {
   {3,3,1},
   {-1,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132295[] = {
   {3,3,1},
   {-1,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132296[] = {
   {4,-1,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki132297[] = {
   {3,3,1},
   {-2,-4,1},
   {-3,3,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132298[] = {
   {3,3,1},
   {-2,-4,1},
   {-3,3,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132299[] = {
   {-3,-3,1},
   {4,2,1},
   {3,-3,2},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki132300[] = {
   {3,3,1},
   {-2,-4,1},
   {-3,3,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132301[] = {
   {-4,-2,1},
   {3,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-4,2}};

static struct patval fuseki132302[] = {
   {-4,0,1},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132303[] = {
   {4,0,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132304[] = {
   {4,0,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132305[] = {
   {4,0,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132306[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132307[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132308[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132309[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132310[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132311[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132312[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132313[] = {
   {-4,-2,1},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132314[] = {
   {-2,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132315[] = {
   {4,-2,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki132316[] = {
   {4,-2,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki132317[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {3,-1,1},
   {4,1,1},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132318[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {3,-1,1},
   {4,1,1},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132319[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {3,-1,1},
   {4,1,1},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132320[] = {
   {3,-3,1},
   {-3,-3,1},
   {-2,1,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {-4,1,2},
   {-3,0,2}};

static struct patval fuseki132321[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,2,1},
   {-1,3,1},
   {3,3,1},
   {3,-3,1},
   {0,3,2},
   {-1,4,2}};

static struct patval fuseki132322[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {1,2,1},
   {1,3,1},
   {3,3,1},
   {0,3,2},
   {1,4,2}};

static struct patval fuseki132323[] = {
   {-1,4,1},
   {1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {-3,1,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132324[] = {
   {-1,4,1},
   {1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {-3,1,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132325[] = {
   {1,-3,1},
   {1,-4,1},
   {-1,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {2,-4,2},
   {3,-3,2},
   {3,-1,2},
   {3,3,2}};

static struct patval fuseki132326[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-1,1},
   {2,2,1},
   {3,-3,1},
   {3,3,1},
   {1,4,2},
   {4,1,2}};

static struct patval fuseki132327[] = {
   {-3,2,1},
   {-4,3,1},
   {-4,4,1},
   {-3,-3,2},
   {-4,2,2},
   {-3,3,2},
   {-3,4,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132328[] = {
   {4,2,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132329[] = {
   {2,4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132330[] = {
   {4,2,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132331[] = {
   {4,2,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132332[] = {
   {2,4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132333[] = {
   {2,4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132334[] = {
   {4,2,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132335[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki132336[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132337[] = {
   {4,3,1},
   {-3,3,1},
   {3,-3,1},
   {-4,-3,2}};

static struct patval fuseki132338[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132339[] = {
   {4,-1,1},
   {1,-4,1},
   {0,0,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132340[] = {
   {4,-1,1},
   {1,-4,1},
   {0,0,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132341[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {0,-2,1},
   {3,-3,1},
   {0,-4,2}};

static struct patval fuseki132342[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,0,1},
   {3,-3,1},
   {3,3,1},
   {4,0,2}};

static struct patval fuseki132343[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,2,1},
   {3,3,1},
   {3,-3,1},
   {0,4,2}};

static struct patval fuseki132344[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,2,1},
   {3,3,1},
   {3,-3,1},
   {0,4,2}};

static struct patval fuseki132345[] = {
   {4,1,1},
   {4,4,1},
   {1,4,1},
   {2,2,2},
   {3,-3,2},
   {3,3,2},
   {4,-1,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132346[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,4,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {3,4,2},
   {4,4,2}};

static struct patval fuseki132347[] = {
   {-4,2,1},
   {3,3,1},
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-3,4,1},
   {-4,4,2},
   {-4,3,2}};

static struct patval fuseki132348[] = {
   {3,-3,1},
   {-4,-3,1},
   {-2,-4,1},
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {-4,-4,2},
   {-3,-4,2}};

static struct patval fuseki132349[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,1,1},
   {2,-2,1},
   {3,-3,1},
   {3,3,1},
   {4,-3,1},
   {4,-4,2},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132350[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-1,1},
   {2,2,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {4,1,2},
   {1,4,2},
   {4,4,2}};

static struct patval fuseki132351[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,3,1},
   {0,0,1},
   {3,3,1},
   {-4,1,2}};

static struct patval fuseki132352[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {1,-3,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132353[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {1,-3,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132354[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {0,0,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132355[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {0,0,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132356[] = {
   {-4,1,1},
   {-4,2,1},
   {3,3,1},
   {3,-3,1},
   {-3,-3,1},
   {0,0,1},
   {-3,3,1},
   {-3,4,1},
   {-3,2,2},
   {-4,4,2},
   {-4,3,2}};

static struct patval fuseki132357[] = {
   {0,0,1},
   {3,-3,1},
   {-4,-2,1},
   {-4,-1,1},
   {-3,-4,1},
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-4,-4,2},
   {-4,-3,2},
   {-3,-2,2}};

static struct patval fuseki132358[] = {
   {4,-1,1},
   {5,-3,1},
   {1,-4,1},
   {4,-4,1},
   {-3,3,2},
   {3,3,2},
   {2,-2,2},
   {4,-3,2},
   {-3,-3,2},
   {4,1,2},
   {3,-3,2}};

static struct patval fuseki132359[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki132360[] = {
   {4,4,1},
   {-3,3,1},
   {3,-3,1},
   {-3,-4,2}};

static struct patval fuseki132361[] = {
   {4,4,1},
   {-3,3,1},
   {3,-3,1},
   {-4,-3,2}};

static struct patval fuseki132362[] = {
   {4,4,1},
   {-3,3,1},
   {3,-3,1},
   {-4,-3,2}};

static struct patval fuseki132363[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki132364[] = {
   {3,-1,1},
   {4,-1,1},
   {1,-4,1},
   {0,0,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2},
   {4,-2,2},
   {-3,3,2},
   {4,1,2}};

static struct patval fuseki132365[] = {
   {-4,1,1},
   {-1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {1,4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132366[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {2,-2,1},
   {3,-4,1},
   {3,-3,1},
   {4,1,1},
   {4,-3,1},
   {4,-4,2},
   {4,-1,2},
   {1,-4,2},
   {5,-3,2}};

static struct patval fuseki132367[] = {
   {3,-5,1},
   {0,-4,1},
   {-2,-4,2},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132368[] = {
   {0,4,1},
   {-3,5,1},
   {-3,3,2},
   {-3,-3,2},
   {2,4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132369[] = {
   {4,-4,1},
   {5,-5,1},
   {1,-4,1},
   {5,-3,1},
   {4,-1,1},
   {2,-2,2},
   {3,3,2},
   {-3,-3,2},
   {4,-3,2},
   {3,-4,2},
   {4,1,2},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132370[] = {
   {4,2,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132371[] = {
   {2,4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132372[] = {
   {2,4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132373[] = {
   {2,4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132374[] = {
   {0,0,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132375[] = {
   {0,0,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132376[] = {
   {0,0,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132377[] = {
   {0,0,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132378[] = {
   {0,0,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132379[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,0,1},
   {3,3,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki132380[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,0,1},
   {3,3,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki132381[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {2,0,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki132382[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-2,1},
   {3,3,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki132383[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {0,2,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki132384[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-2,1},
   {3,3,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki132385[] = {
   {3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {-4,-3,2}};

static struct patval fuseki132386[] = {
   {3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {-4,-3,2}};

static struct patval fuseki132387[] = {
   {-3,3,1},
   {2,4,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132388[] = {
   {-3,3,1},
   {2,4,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132389[] = {
   {3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {-4,-3,2}};

static struct patval fuseki132390[] = {
   {-3,3,1},
   {2,4,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132391[] = {
   {2,5,1},
   {4,4,1},
   {3,4,1},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {2,4,2},
   {4,3,2},
   {-3,3,2}};

static struct patval fuseki132392[] = {
   {3,-5,1},
   {1,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,-1,2},
   {3,3,2}};

static struct patval fuseki132393[] = {
   {1,-3,1},
   {3,-1,1},
   {4,-1,1},
   {1,-4,1},
   {0,0,2},
   {-3,-3,2},
   {2,-4,2},
   {3,-3,2},
   {-3,3,2},
   {3,3,2},
   {4,-2,2},
   {-1,-4,2}};

static struct patval fuseki132394[] = {
   {3,-1,1},
   {4,-1,1},
   {1,-3,1},
   {1,-4,1},
   {0,0,2},
   {2,-4,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2},
   {4,-2,2},
   {-3,3,2},
   {4,1,2}};

static struct patval fuseki132395[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-4,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,1},
   {4,-2,1},
   {4,-3,2},
   {4,-4,2},
   {5,-2,2}};

static struct patval fuseki132396[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,4,1},
   {2,4,1},
   {4,3,1},
   {3,-3,1},
   {3,3,1},
   {3,4,2},
   {2,5,2},
   {4,4,2}};

static struct patval fuseki132397[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki132398[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki132399[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1},
   {4,-2,1},
   {4,0,2},
   {5,3,2}};

static struct patval fuseki132400[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {3,3,1},
   {3,0,1},
   {3,-3,1},
   {3,-5,2},
   {0,-4,2}};

static struct patval fuseki132401[] = {
   {4,-1,1},
   {-3,-3,2},
   {0,-3,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132402[] = {
   {4,1,1},
   {-3,-3,2},
   {0,-3,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132403[] = {
   {4,-1,1},
   {-3,-3,2},
   {0,-3,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132404[] = {
   {4,-1,1},
   {-3,-3,2},
   {0,-3,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132405[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {1,-3,1},
   {3,-3,1},
   {4,1,1},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132406[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {1,-3,1},
   {3,-3,1},
   {4,1,1},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132407[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,-4,1},
   {3,3,1},
   {3,-3,1},
   {3,-1,1},
   {1,-4,2},
   {4,-1,2}};

static struct patval fuseki132408[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132409[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {3,3,1},
   {3,-3,1},
   {1,-4,2}};

static struct patval fuseki132410[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,3,1},
   {-4,-1,2}};

static struct patval fuseki132411[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,3,1},
   {2,-4,1},
   {3,-3,1},
   {4,1,1},
   {4,-2,1},
   {1,-4,2},
   {4,-1,2},
   {3,-1,2}};

static struct patval fuseki132412[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {4,-4,1},
   {3,-3,1},
   {3,-1,1},
   {1,-4,2},
   {3,-5,2}};

static struct patval fuseki132413[] = {
   {-4,4,1},
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2},
   {-3,5,2}};

static struct patval fuseki132414[] = {
   {-4,-4,1},
   {3,3,1},
   {-3,-3,1},
   {-3,-1,1},
   {-3,3,1},
   {3,-3,1},
   {-1,-4,2},
   {-3,-5,2}};

static struct patval fuseki132415[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {3,-3,1},
   {3,3,1},
   {4,4,1},
   {4,1,2},
   {5,3,2}};

static struct patval fuseki132416[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {4,1,1},
   {3,-3,1},
   {3,3,1},
   {4,-2,1},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132417[] = {
   {3,4,1},
   {4,0,1},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,-2,2},
   {-3,3,2}};

static struct patval fuseki132418[] = {
   {4,0,1},
   {5,3,1},
   {0,-4,1},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {4,-2,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132419[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,-1,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132420[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,2,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132421[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,0,1},
   {3,-3,1},
   {3,3,1},
   {4,2,1},
   {4,-2,1},
   {4,0,2},
   {3,4,2},
   {4,4,2}};

static struct patval fuseki132422[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,0,1},
   {3,-3,1},
   {3,3,1},
   {4,2,1},
   {4,-2,1},
   {4,0,2},
   {3,4,2},
   {4,4,2}};

static struct patval fuseki132423[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,0,1},
   {4,-2,1},
   {3,-3,1},
   {3,3,1},
   {4,2,1},
   {3,-4,2},
   {4,0,2},
   {4,-4,2}};

static struct patval fuseki132424[] = {
   {3,-1,1},
   {4,-1,1},
   {1,-4,1},
   {5,0,1},
   {-3,-3,2},
   {3,3,2},
   {3,-3,2},
   {-3,3,2},
   {4,1,2},
   {5,-1,2},
   {4,-2,2}};

static struct patval fuseki132425[] = {
   {3,0,1},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132426[] = {
   {0,3,1},
   {-3,3,2},
   {0,0,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132427[] = {
   {0,-3,1},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132428[] = {
   {-3,0,1},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132429[] = {
   {-3,-3,1},
   {-3,3,1},
   {5,-2,1},
   {3,-3,1},
   {4,1,1},
   {3,3,1},
   {4,-2,1},
   {5,-1,1},
   {3,-1,2},
   {1,-4,2},
   {4,-1,2},
   {5,0,2}};

static struct patval fuseki132430[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {4,-5,1},
   {0,3,1},
   {4,-2,1},
   {3,-3,1},
   {3,3,1},
   {0,-4,2},
   {3,-5,2},
   {4,0,2},
   {5,3,2}};

static struct patval fuseki132431[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {4,-5,1},
   {0,3,1},
   {4,-2,1},
   {3,-3,1},
   {3,3,1},
   {0,-4,2},
   {3,-5,2},
   {4,0,2},
   {5,3,2}};

static struct patval fuseki132432[] = {
   {3,4,1},
   {4,4,1},
   {4,0,1},
   {3,3,2},
   {-3,-3,2},
   {4,-2,2},
   {3,-3,2},
   {4,2,2},
   {-3,3,2}};

static struct patval fuseki132433[] = {
   {3,0,1},
   {1,3,1},
   {1,-3,2},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132434[] = {
   {0,3,1},
   {-3,1,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,1,2},
   {3,3,2}};

static struct patval fuseki132435[] = {
   {3,1,1},
   {0,3,1},
   {-3,3,2},
   {-3,1,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132436[] = {
   {4,-1,1},
   {3,4,1},
   {3,-3,2},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki132437[] = {
   {4,3,1},
   {-1,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132438[] = {
   {-4,-3,1},
   {1,-4,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132439[] = {
   {4,-1,1},
   {3,4,1},
   {3,-3,2},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki132440[] = {
   {4,-1,1},
   {3,4,1},
   {3,-3,2},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki132441[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,2,1},
   {4,-2,1},
   {4,0,2},
   {3,4,2}};

static struct patval fuseki132442[] = {
   {-5,2,1},
   {-4,1,1},
   {-3,0,1},
   {-4,3,1},
   {-3,-3,2},
   {-4,2,2},
   {-3,1,2},
   {-3,3,2},
   {-2,1,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132443[] = {
   {-4,1,1},
   {-4,3,1},
   {-3,0,1},
   {-3,-3,2},
   {-3,1,2},
   {-3,3,2},
   {-2,1,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132444[] = {
   {-3,-3,1},
   {-3,2,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {0,0,1},
   {-1,4,2},
   {-1,3,2}};

static struct patval fuseki132445[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {2,3,1},
   {3,-3,1},
   {4,2,1},
   {3,3,1},
   {4,1,2},
   {3,1,2}};

static struct patval fuseki132446[] = {
   {-3,-3,1},
   {-3,2,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {0,0,1},
   {-1,4,2},
   {-1,3,2}};

static struct patval fuseki132447[] = {
   {4,-1,1},
   {3,-1,1},
   {1,-4,1},
   {3,-3,2},
   {-3,3,2},
   {3,3,2},
   {4,-2,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132448[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {2,4,1},
   {1,4,2},
   {-1,4,2},
   {-1,3,2}};

static struct patval fuseki132449[] = {
   {-4,-2,1},
   {3,-3,1},
   {3,3,1},
   {-4,2,1},
   {-3,-3,1},
   {-1,3,1},
   {-3,3,1},
   {-3,1,2},
   {-4,-1,2},
   {-4,1,2}};

static struct patval fuseki132450[] = {
   {-2,1,1},
   {-4,2,1},
   {3,3,1},
   {-3,-3,1},
   {3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {-4,1,2},
   {-3,0,2},
   {-4,3,2}};

static struct patval fuseki132451[] = {
   {-1,4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132452[] = {
   {1,-4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132453[] = {
   {-4,1,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132454[] = {
   {-1,4,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132455[] = {
   {-4,1,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132456[] = {
   {3,3,1}};

static struct patval fuseki132457[] = {
   {3,-3,1}};

static struct patval fuseki132458[] = {
   {-3,-3,1}};

static struct patval fuseki132459[] = {
   {-3,3,1}};

static struct patval fuseki132460[] = {
   {3,3,1}};

static struct patval fuseki132461[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-2,1},
   {3,-3,1},
   {3,3,1},
   {4,1,1},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132462[] = {
   {3,4,1},
   {2,5,1},
   {4,4,1},
   {1,5,1},
   {2,4,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,3,2},
   {1,4,2}};

static struct patval fuseki132463[] = {
   {4,-3,1},
   {5,-2,1},
   {5,-1,1},
   {4,-4,1},
   {3,3,2},
   {3,-3,2},
   {-3,-3,2},
   {4,-2,2},
   {4,-1,2},
   {-3,3,2},
   {3,-4,2}};

static struct patval fuseki132464[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {1,4,1},
   {3,-3,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki132465[] = {
   {-4,1,1},
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {0,0,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132466[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {1,-4,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132467[] = {
   {-4,1,1},
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {0,0,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132468[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {0,0,1},
   {3,3,1},
   {-4,1,2}};

static struct patval fuseki132469[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,1},
   {-4,-4,2}};

static struct patval fuseki132470[] = {
   {3,3,1},
   {-3,3,1},
   {3,-3,1},
   {-4,-4,2}};

static struct patval fuseki132471[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki132472[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {4,-2,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1},
   {0,-4,2},
   {4,0,2},
   {5,3,2}};

static struct patval fuseki132473[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki132474[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki132475[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki132476[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {3,-3,1},
   {3,3,1},
   {3,1,2}};

static struct patval fuseki132477[] = {
   {-3,-3,1},
   {-3,-1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {-1,-3,2}};

static struct patval fuseki132478[] = {
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-1,3,1},
   {3,-3,1},
   {-3,1,2}};

static struct patval fuseki132479[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {3,-3,1},
   {3,3,1},
   {3,1,2}};

static struct patval fuseki132480[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {3,1,1},
   {1,3,2}};

static struct patval fuseki132481[] = {
   {4,-1,1},
   {4,0,1},
   {1,-4,1},
   {5,0,1},
   {3,-1,1},
   {3,-3,2},
   {4,-2,2},
   {-3,-3,2},
   {-3,3,2},
   {4,1,2},
   {5,-2,2},
   {5,-1,2},
   {3,3,2}};

static struct patval fuseki132482[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {0,0,1},
   {3,3,1},
   {-4,1,2}};

static struct patval fuseki132483[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,1,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki132484[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {0,0,1},
   {3,3,1},
   {-4,1,2}};

static struct patval fuseki132485[] = {
   {-2,1,1},
   {3,-3,1},
   {-4,2,1},
   {-3,3,1},
   {-3,-3,1},
   {-3,2,1},
   {-3,1,1},
   {3,3,1},
   {-3,0,2},
   {-5,2,2},
   {-4,1,2},
   {-4,3,2}};

static struct patval fuseki132486[] = {
   {-4,-2,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {-4,0,2}};

static struct patval fuseki132487[] = {
   {-4,-2,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {-4,0,2}};

static struct patval fuseki132488[] = {
   {-4,-2,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {-4,0,2}};

static struct patval fuseki132489[] = {
   {-4,-2,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {-4,0,2}};

static struct patval fuseki132490[] = {
   {-3,-3,1},
   {-3,3,1},
   {5,-1,1},
   {3,-3,1},
   {4,1,1},
   {3,3,1},
   {4,-2,1},
   {4,-1,2},
   {3,-1,2},
   {1,-4,2}};

static struct patval fuseki132491[] = {
   {-5,0,1},
   {-5,2,1},
   {-4,1,1},
   {-3,0,1},
   {-4,3,1},
   {-3,-3,2},
   {-4,2,2},
   {-3,1,2},
   {-3,2,2},
   {-3,3,2},
   {-2,1,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132492[] = {
   {0,-4,1},
   {4,0,1},
   {5,3,1},
   {3,-5,1},
   {0,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {4,-2,2},
   {-3,3,2},
   {-2,-4,2}};

static struct patval fuseki132493[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,-3,1},
   {3,3,1},
   {3,-3,1},
   {3,-4,2}};

static struct patval fuseki132494[] = {
   {3,-4,1},
   {2,-4,1},
   {-3,3,2},
   {2,-3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132495[] = {
   {1,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2}};

static struct patval fuseki132496[] = {
   {-4,-4,1},
   {-4,-3,1},
   {-3,-2,1},
   {-3,-5,1},
   {-4,-1,2},
   {-3,-4,2},
   {-3,-3,2},
   {-4,-2,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132497[] = {
   {-3,-3,1},
   {-3,-1,1},
   {-3,3,1},
   {-2,-4,1},
   {3,3,1},
   {3,-1,1},
   {3,-3,1},
   {2,-4,1},
   {1,-3,2},
   {1,-4,2},
   {-1,-3,2},
   {-1,-4,2}};

static struct patval fuseki132498[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,1,1},
   {3,-3,1},
   {2,4,1},
   {1,4,2},
   {1,3,2},
   {-1,4,2},
   {-1,3,2}};

static struct patval fuseki132499[] = {
   {4,-1,1},
   {1,-4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2},
   {4,3,2}};

static struct patval fuseki132500[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {1,-3,1},
   {3,-4,1},
   {3,-3,1},
   {4,1,1},
   {4,-3,1},
   {4,-4,2},
   {4,-1,2},
   {1,-4,2},
   {5,-3,2}};

static struct patval fuseki132501[] = {
   {4,-1,1},
   {3,0,1},
   {1,-4,1},
   {2,-2,1},
   {3,-2,1},
   {3,-3,2},
   {2,-1,2},
   {3,-1,2},
   {-3,3,2},
   {3,3,2},
   {-3,-3,2},
   {4,0,2},
   {4,1,2}};

static struct patval fuseki132502[] = {
   {4,-1,1},
   {3,0,1},
   {1,-4,1},
   {2,-2,1},
   {3,-2,1},
   {3,-3,2},
   {2,-1,2},
   {3,-1,2},
   {-3,3,2},
   {3,3,2},
   {-3,-3,2},
   {4,0,2},
   {4,1,2}};

static struct patval fuseki132503[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,1,1},
   {2,-1,1},
   {3,-3,1},
   {4,0,1},
   {3,-1,1},
   {3,3,1},
   {3,0,2},
   {4,-1,2},
   {3,-2,2},
   {1,-4,2}};

static struct patval fuseki132504[] = {
   {1,3,1},
   {1,4,1},
   {-1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {-3,1,2},
   {2,4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132505[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,0,1},
   {3,3,2}};

static struct patval fuseki132506[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,0,1},
   {3,3,2}};

static struct patval fuseki132507[] = {
   {-3,2,1},
   {-2,2,1},
   {-4,3,1},
   {-4,4,1},
   {-3,-3,2},
   {-4,1,2},
   {-3,3,2},
   {-3,4,2},
   {-4,2,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132508[] = {
   {-4,-4,1},
   {-4,-3,1},
   {-3,-2,1},
   {-2,-2,1},
   {-3,-4,2},
   {-3,-3,2},
   {-4,-2,2},
   {-3,3,2},
   {-4,-1,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132509[] = {
   {4,-4,1},
   {-4,4,1},
   {-4,3,2},
   {-3,0,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki132510[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,3,1},
   {3,-3,1},
   {1,-4,2}};

static struct patval fuseki132511[] = {
   {4,-1,1},
   {4,-4,1},
   {1,-4,1},
   {1,-3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132512[] = {
   {-5,3,1},
   {-4,1,1},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132513[] = {
   {-5,3,1},
   {-4,1,1},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132514[] = {
   {4,-1,1},
   {5,-3,1},
   {3,-3,2},
   {3,0,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132515[] = {
   {-5,3,1},
   {-4,1,1},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132516[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,4,1},
   {1,4,1},
   {3,3,1},
   {2,4,1},
   {4,3,1},
   {3,-3,1},
   {1,5,2},
   {3,4,2},
   {2,5,2},
   {4,4,2}};

static struct patval fuseki132517[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-4,1},
   {3,-3,1},
   {1,-4,1},
   {3,3,1},
   {2,-4,1},
   {4,-3,1},
   {1,-5,2},
   {2,-5,2},
   {4,-4,2},
   {3,-4,2}};

static struct patval fuseki132518[] = {
   {-4,3,1},
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {-2,4,1},
   {0,4,1},
   {-1,4,1},
   {-1,5,2},
   {-2,5,2},
   {-4,4,2},
   {-3,4,2}};

static struct patval fuseki132519[] = {
   {4,-1,1},
   {5,-3,1},
   {1,-4,1},
   {4,-4,1},
   {-3,3,2},
   {3,3,2},
   {1,-3,2},
   {4,-3,2},
   {-3,-3,2},
   {4,1,2},
   {3,-3,2}};

static struct patval fuseki132520[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,3,1},
   {2,-2,1},
   {3,-3,1},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132521[] = {
   {-4,-4,1},
   {4,-4,1},
   {-4,4,1},
   {-3,-3,2},
   {-3,0,2},
   {-4,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-4,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132522[] = {
   {-4,-4,1},
   {4,-4,1},
   {-4,4,1},
   {-3,-3,2},
   {-3,0,2},
   {-4,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-4,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132523[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki132524[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,-1,1},
   {4,4,2}};

static struct patval fuseki132525[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132526[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132527[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {3,3,1},
   {3,-3,1},
   {1,-4,2}};

static struct patval fuseki132528[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki132529[] = {
   {-5,3,1},
   {-4,1,1},
   {-4,-1,2},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132530[] = {
   {-5,3,1},
   {-4,1,1},
   {-4,-1,2},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132531[] = {
   {-5,3,1},
   {-4,1,1},
   {-4,-1,2},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132532[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {1,-4,1},
   {-2,-4,2},
   {3,3,2}};

static struct patval fuseki132533[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {1,-4,1},
   {-2,-4,2},
   {3,3,2}};

static struct patval fuseki132534[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {1,-4,1},
   {-2,-4,2},
   {3,3,2}};

static struct patval fuseki132535[] = {
   {3,-3,1},
   {-4,2,1},
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-1,3,1},
   {0,0,1},
   {-4,1,2},
   {-3,1,2}};

static struct patval fuseki132536[] = {
   {3,-3,1},
   {-4,2,1},
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-1,3,1},
   {0,0,1},
   {-4,1,2},
   {-3,1,2}};

static struct patval fuseki132537[] = {
   {3,-3,1},
   {-4,2,1},
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-1,3,1},
   {0,0,1},
   {-4,1,2},
   {-3,1,2}};

static struct patval fuseki132538[] = {
   {2,3,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132539[] = {
   {3,2,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132540[] = {
   {2,3,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132541[] = {
   {3,2,1},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132542[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,1,1},
   {1,-3,1},
   {3,-3,1},
   {3,3,1},
   {4,-3,1},
   {4,-4,2},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132543[] = {
   {3,1,1},
   {4,-1,1},
   {2,-1,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132544[] = {
   {0,0,1},
   {3,-3,1},
   {-4,-2,1},
   {-4,-1,1},
   {-1,-5,1},
   {-3,-4,1},
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-3,-5,2},
   {-4,-4,2},
   {-4,-3,2},
   {-3,-2,2}};

static struct patval fuseki132545[] = {
   {0,0,1},
   {3,-3,1},
   {-4,-2,1},
   {-4,-1,1},
   {-1,-5,1},
   {-3,-4,1},
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-3,-5,2},
   {-4,-4,2},
   {-4,-3,2},
   {-3,-2,2}};

static struct patval fuseki132546[] = {
   {-4,-3,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {-4,-2,2}};

static struct patval fuseki132547[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,4,1},
   {3,-3,1},
   {3,3,1},
   {2,4,2}};

static struct patval fuseki132548[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {4,2,2}};

static struct patval fuseki132549[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-3,1},
   {2,-2,1},
   {3,-3,1},
   {4,3,1},
   {1,-4,2},
   {4,-1,2},
   {4,-4,2}};

static struct patval fuseki132550[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-3,1},
   {2,-2,1},
   {3,-3,1},
   {4,3,1},
   {1,-4,2},
   {4,-1,2},
   {4,-4,2}};

static struct patval fuseki132551[] = {
   {4,-1,1},
   {3,-2,1},
   {1,-4,1},
   {3,0,1},
   {-3,3,2},
   {3,-1,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,0,2},
   {4,1,2}};

static struct patval fuseki132552[] = {
   {4,-1,1},
   {3,0,1},
   {1,-4,1},
   {3,-3,2},
   {3,-1,2},
   {-3,3,2},
   {3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132553[] = {
   {-4,3,1},
   {3,3,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-4,1},
   {3,-3,1},
   {3,0,1},
   {-4,4,2},
   {4,-4,2}};

static struct patval fuseki132554[] = {
   {4,-1,1},
   {4,-4,1},
   {1,-4,1},
   {2,-2,2},
   {3,-3,2},
   {-3,3,2},
   {-3,-3,2},
   {4,3,2}};

static struct patval fuseki132555[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,1,1},
   {3,-3,1},
   {3,-1,1},
   {4,0,1},
   {3,3,1},
   {4,-1,2},
   {3,0,2},
   {1,-4,2}};

static struct patval fuseki132556[] = {
   {-4,-1,1},
   {3,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132557[] = {
   {-4,-1,1},
   {3,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132558[] = {
   {-3,-3,1},
   {1,4,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132559[] = {
   {4,-1,1},
   {-3,-3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132560[] = {
   {-4,1,1},
   {-3,-3,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132561[] = {
   {4,-1,1},
   {-3,-3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132562[] = {
   {4,-4,1},
   {5,-5,1},
   {1,-4,1},
   {5,-3,1},
   {4,-1,1},
   {1,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,-3,2},
   {3,-4,2},
   {4,1,2},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132563[] = {
   {3,0,1},
   {4,-3,1},
   {3,-4,1},
   {1,3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2},
   {4,-4,2},
   {-3,3,2}};

static struct patval fuseki132564[] = {
   {0,-3,1},
   {-4,-3,1},
   {-3,-4,1},
   {-3,-3,2},
   {-3,3,2},
   {-4,-4,2},
   {3,-3,2},
   {3,-1,2},
   {3,3,2}};

static struct patval fuseki132565[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,1,1},
   {2,-1,1},
   {3,-3,1},
   {3,3,1},
   {3,1,2},
   {4,-1,2}};

static struct patval fuseki132566[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,1,1},
   {2,-1,1},
   {3,-3,1},
   {3,3,1},
   {3,1,2},
   {4,-1,2}};

static struct patval fuseki132567[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {3,3,1},
   {2,-3,1},
   {3,-3,1},
   {3,-4,2},
   {2,-4,2}};

static struct patval fuseki132568[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {2,3,1},
   {3,3,1},
   {3,-3,1},
   {2,4,2},
   {3,4,2}};

static struct patval fuseki132569[] = {
   {0,0,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132570[] = {
   {0,0,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132571[] = {
   {0,0,1},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132572[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {3,0,1},
   {1,-4,2}};

static struct patval fuseki132573[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki132574[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {3,3,1},
   {-4,1,2}};

static struct patval fuseki132575[] = {
   {-4,-4,1},
   {-3,-3,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132576[] = {
   {-4,4,1},
   {-3,-3,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132577[] = {
   {-4,-4,1},
   {-3,-3,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132578[] = {
   {4,4,1},
   {-3,-3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132579[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,2,1},
   {3,4,2}};

static struct patval fuseki132580[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,2,1},
   {3,4,2}};

static struct patval fuseki132581[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,2,1},
   {3,4,2}};

static struct patval fuseki132582[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,2,1},
   {3,4,2}};

static struct patval fuseki132583[] = {
   {4,3,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132584[] = {
   {-4,3,1},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132585[] = {
   {3,4,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132586[] = {
   {-4,3,1},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132587[] = {
   {-1,4,1},
   {3,3,1},
   {-1,3,1},
   {-2,4,2},
   {-3,-3,2},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132588[] = {
   {-1,4,1},
   {3,3,1},
   {-1,3,1},
   {-2,4,2},
   {-3,-3,2},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132589[] = {
   {3,3,1},
   {4,-1,1},
   {3,-1,1},
   {3,-3,2},
   {-3,-3,2},
   {4,-2,2},
   {-3,3,2}};

static struct patval fuseki132590[] = {
   {-1,2,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132591[] = {
   {2,-1,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132592[] = {
   {-4,1,1},
   {-1,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {-1,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132593[] = {
   {-4,1,1},
   {-1,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {-1,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132594[] = {
   {3,3,1},
   {4,0,1},
   {1,4,2},
   {3,-3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132595[] = {
   {1,5,1},
   {4,4,1},
   {0,0,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {4,3,2},
   {-3,3,2}};

static struct patval fuseki132596[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,3,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {3,4,2},
   {4,4,2}};

static struct patval fuseki132597[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,3,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {3,4,2},
   {4,4,2}};

static struct patval fuseki132598[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,-4,1},
   {3,3,1},
   {-4,-1,2}};

static struct patval fuseki132599[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,-4,1},
   {3,3,1},
   {-4,-1,2}};

static struct patval fuseki132600[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,4,1},
   {3,-3,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki132601[] = {
   {4,3,1},
   {4,4,1},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132602[] = {
   {3,4,1},
   {4,4,1},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132603[] = {
   {3,4,1},
   {4,4,1},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132604[] = {
   {4,-2,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132605[] = {
   {4,-2,1},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132606[] = {
   {4,-3,1},
   {3,0,1},
   {5,-3,1},
   {3,-4,1},
   {3,-3,2},
   {-3,3,2},
   {3,3,2},
   {4,-4,2},
   {-3,-3,2},
   {4,-2,2},
   {1,3,2}};

static struct patval fuseki132607[] = {
   {3,-3,1},
   {-3,3,1},
   {2,4,1},
   {-3,-3,2}};

static struct patval fuseki132608[] = {
   {-4,-2,1},
   {3,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-4,2}};

static struct patval fuseki132609[] = {
   {-4,-2,1},
   {3,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-4,2}};

static struct patval fuseki132610[] = {
   {4,3,1},
   {-2,-4,1},
   {-3,3,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132611[] = {
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,4,2}};

static struct patval fuseki132612[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-4,-4,2}};

static struct patval fuseki132613[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-4,-4,2}};

static struct patval fuseki132614[] = {
   {2,1,1},
   {4,1,1},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {4,-1,2},
   {-3,3,2}};

static struct patval fuseki132615[] = {
   {-1,4,1},
   {-1,2,1},
   {-3,3,2},
   {-3,-3,2},
   {1,4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132616[] = {
   {0,3,1},
   {-4,-3,1},
   {3,0,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,3,1},
   {-2,-4,1},
   {-1,-5,1},
   {0,-3,1},
   {0,0,1},
   {3,-3,1},
   {-4,-4,2},
   {-3,-4,2},
   {-2,-5,2}};

static struct patval fuseki132617[] = {
   {0,3,1},
   {-5,-1,1},
   {3,0,1},
   {3,3,1},
   {-4,-2,1},
   {-3,-4,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {3,-3,1},
   {-5,-2,2},
   {-4,-4,2},
   {-4,-3,2}};

static struct patval fuseki132618[] = {
   {3,-4,1},
   {4,-1,1},
   {1,-4,1},
   {4,-4,1},
   {-3,-3,2},
   {3,-1,2},
   {3,3,2},
   {3,-3,2},
   {4,-2,2},
   {-3,3,2},
   {4,1,2}};

static struct patval fuseki132619[] = {
   {-1,4,1},
   {0,3,1},
   {-2,4,1},
   {-1,2,2},
   {-1,3,2},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132620[] = {
   {0,3,1},
   {4,1,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {-3,1,2}};

static struct patval fuseki132621[] = {
   {3,0,1},
   {1,4,1},
   {1,-3,2},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132622[] = {
   {0,3,1},
   {4,1,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {-3,1,2}};

static struct patval fuseki132623[] = {
   {2,-4,1},
   {3,-4,1},
   {1,-4,1},
   {1,-3,2},
   {-3,-3,2},
   {2,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132624[] = {
   {1,-4,1},
   {1,-3,1},
   {4,-1,1},
   {0,-5,1},
   {3,-1,1},
   {1,-5,2},
   {-3,-3,2},
   {-3,3,2},
   {2,-4,2},
   {3,-3,2},
   {0,0,2},
   {3,3,2},
   {4,-2,2},
   {-1,-4,2}};

static struct patval fuseki132625[] = {
   {-4,1,1},
   {-1,-3,1},
   {-3,1,1},
   {-3,-3,2},
   {-3,3,2},
   {-4,2,2},
   {-1,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132626[] = {
   {-4,-4,1},
   {-2,-5,1},
   {-3,-4,1},
   {-4,-3,2},
   {-3,0,2},
   {-3,3,2},
   {-3,-3,2},
   {-2,-4,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132627[] = {
   {-4,0,1},
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132628[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132629[] = {
   {-1,3,1},
   {-4,2,1},
   {-3,-3,1},
   {-3,-1,1},
   {3,3,1},
   {-3,3,1},
   {3,-3,1},
   {-4,1,2},
   {-1,-3,2},
   {-3,1,2}};

static struct patval fuseki132630[] = {
   {-3,-3,1},
   {3,-1,1},
   {-3,3,1},
   {-1,-3,1},
   {3,3,1},
   {3,-3,1},
   {2,-4,1},
   {1,-3,2},
   {-3,-1,2},
   {1,-4,2}};

static struct patval fuseki132631[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,-4,1},
   {0,0,1},
   {1,-5,1},
   {3,3,1},
   {4,-2,1},
   {2,-4,1},
   {3,-3,1},
   {3,-1,2},
   {1,-4,2},
   {1,-3,2},
   {4,-1,2}};

static struct patval fuseki132632[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,-3,1},
   {3,2,2}};

static struct patval fuseki132633[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,-3,1},
   {3,2,2}};

static struct patval fuseki132634[] = {
   {4,3,1},
   {-3,3,1},
   {3,-3,1},
   {-4,-4,2}};

static struct patval fuseki132635[] = {
   {-3,-4,1},
   {-3,3,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki132636[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki132637[] = {
   {-4,1,1},
   {-4,2,1},
   {3,3,1},
   {0,0,1},
   {-3,-3,1},
   {-1,3,1},
   {-3,3,1},
   {-3,4,1},
   {3,-3,1},
   {-3,2,2},
   {-4,4,2},
   {-2,2,2},
   {-4,3,2}};

static struct patval fuseki132638[] = {
   {-4,-4,1},
   {-4,-3,1},
   {-3,-5,1},
   {-2,-4,1},
   {-3,-2,1},
   {-4,-2,2},
   {-3,-3,2},
   {-3,-4,2},
   {-3,3,2},
   {-4,-1,2},
   {-1,-5,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132639[] = {
   {3,-3,1},
   {-4,3,1},
   {3,3,1},
   {-3,-4,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-4,1},
   {3,0,1},
   {-4,-4,2},
   {-4,4,2},
   {4,-4,2}};

static struct patval fuseki132640[] = {
   {3,3,1},
   {-3,-4,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-4,1},
   {3,-3,1},
   {3,0,1},
   {4,3,1},
   {4,-4,2},
   {-4,-4,2},
   {4,4,2}};

static struct patval fuseki132641[] = {
   {3,-3,1},
   {-4,3,1},
   {3,3,1},
   {-3,-4,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-4,1},
   {3,0,1},
   {-4,-4,2},
   {-4,4,2},
   {4,-4,2}};

static struct patval fuseki132642[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,-4,1},
   {3,3,1},
   {4,1,1},
   {3,-3,1},
   {3,-1,1},
   {4,-2,1},
   {4,-4,2},
   {1,-4,2},
   {4,-1,2},
   {3,-4,2}};

static struct patval fuseki132643[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,-4,1},
   {3,3,1},
   {4,1,1},
   {3,-3,1},
   {3,-1,1},
   {4,-2,1},
   {4,-4,2},
   {1,-4,2},
   {4,-1,2},
   {3,-4,2}};

static struct patval fuseki132644[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-3,1},
   {1,-3,1},
   {3,3,1},
   {2,-3,1},
   {3,-3,1},
   {3,-4,2},
   {2,-4,2},
   {1,-4,2}};

static struct patval fuseki132645[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-3,1},
   {1,-3,1},
   {3,3,1},
   {2,-3,1},
   {3,-3,1},
   {3,-4,2},
   {2,-4,2},
   {1,-4,2}};

static struct patval fuseki132646[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1}};

static struct patval fuseki132647[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1}};

static struct patval fuseki132648[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1}};

static struct patval fuseki132649[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,-4,1},
   {3,3,1},
   {3,-3,1},
   {3,-4,2}};

static struct patval fuseki132650[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,-2,1},
   {4,-3,2}};

static struct patval fuseki132651[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,5,1},
   {3,3,1},
   {0,0,1},
   {1,3,1},
   {4,3,1},
   {3,-3,1},
   {5,4,1},
   {1,5,2},
   {4,4,2},
   {4,5,2},
   {-1,4,2}};

static struct patval fuseki132652[] = {
   {2,-2,1},
   {3,-2,1},
   {0,-4,1},
   {0,-2,2},
   {-3,-3,2},
   {3,-3,2},
   {-3,3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132653[] = {
   {2,-2,1},
   {3,-2,1},
   {0,-4,1},
   {0,-2,2},
   {-3,-3,2},
   {3,-3,2},
   {-3,3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132654[] = {
   {3,-2,1},
   {3,0,1},
   {5,-3,1},
   {3,-4,1},
   {4,-3,1},
   {-3,-3,2},
   {-3,3,2},
   {3,3,2},
   {4,-4,2},
   {3,-3,2},
   {4,-2,2},
   {5,-4,2},
   {1,3,2}};

static struct patval fuseki132655[] = {
   {2,-5,1},
   {4,0,1},
   {5,3,1},
   {0,-4,1},
   {3,-5,1},
   {-3,-3,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {4,-5,2},
   {4,-2,2},
   {-3,3,2},
   {-2,-4,2}};

static struct patval fuseki132656[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2},
   {4,-1,2}};

static struct patval fuseki132657[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2},
   {4,-1,2}};

static struct patval fuseki132658[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2},
   {4,-1,2}};

static struct patval fuseki132659[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {4,-2,1},
   {3,3,1},
   {2,-5,1},
   {2,-4,1},
   {3,-3,1},
   {4,1,1},
   {1,-3,2},
   {1,-4,2},
   {4,-1,2},
   {3,-1,2}};

static struct patval fuseki132660[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {4,-2,1},
   {3,3,1},
   {2,-5,1},
   {2,-4,1},
   {3,-3,1},
   {4,1,1},
   {1,-3,2},
   {1,-4,2},
   {4,-1,2},
   {3,-1,2}};

static struct patval fuseki132661[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {1,1,1},
   {2,-1,1},
   {3,3,1},
   {3,-3,1},
   {3,1,2},
   {2,2,2},
   {4,-1,2}};

static struct patval fuseki132662[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {1,1,1},
   {2,-1,1},
   {3,3,1},
   {3,-3,1},
   {3,1,2},
   {2,2,2},
   {4,-1,2}};

static struct patval fuseki132663[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {3,4,1},
   {4,3,1},
   {4,4,2},
   {5,3,2}};

static struct patval fuseki132664[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {3,4,1},
   {4,3,1},
   {4,4,2},
   {5,3,2}};

static struct patval fuseki132665[] = {
   {4,4,1},
   {4,5,1},
   {-1,4,1},
   {1,5,1},
   {1,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {4,3,2},
   {-3,-3,2},
   {-3,3,2},
   {5,4,2}};

static struct patval fuseki132666[] = {
   {-4,1,1},
   {4,4,1},
   {-3,3,2},
   {0,-3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132667[] = {
   {-4,1,1},
   {4,4,1},
   {-3,3,2},
   {0,-3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132668[] = {
   {-4,1,1},
   {4,4,1},
   {-3,3,2},
   {0,-3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132669[] = {
   {3,3,1},
   {-1,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132670[] = {
   {3,3,1},
   {-1,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132671[] = {
   {3,3,1},
   {-1,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132672[] = {
   {3,0,1},
   {4,3,1},
   {1,-3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132673[] = {
   {-3,-4,1},
   {0,-3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,-1,2},
   {3,3,2}};

static struct patval fuseki132674[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,4,2}};

static struct patval fuseki132675[] = {
   {3,-3,1},
   {-4,-3,1},
   {3,3,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {-2,-4,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,0,1},
   {-4,-4,2},
   {-3,-4,2}};

static struct patval fuseki132676[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {4,-4,1},
   {3,-3,1},
   {4,-2,1},
   {3,3,1},
   {3,-4,2},
   {4,-3,2},
   {3,0,2}};

static struct patval fuseki132677[] = {
   {-3,-3,1},
   {-3,3,1},
   {5,-3,1},
   {1,-3,1},
   {3,3,1},
   {2,-3,1},
   {4,-3,1},
   {3,-3,1},
   {2,-4,2},
   {4,-4,2},
   {3,-4,2},
   {1,-4,2}};

static struct patval fuseki132678[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {3,3,1},
   {2,3,1},
   {4,3,1},
   {3,-3,1},
   {5,3,1},
   {3,4,2},
   {2,4,2},
   {4,4,2},
   {1,4,2}};

static struct patval fuseki132679[] = {
   {-3,-3,1},
   {-3,3,1},
   {5,-3,1},
   {1,-3,1},
   {3,3,1},
   {2,-3,1},
   {4,-3,1},
   {3,-3,1},
   {2,-4,2},
   {4,-4,2},
   {3,-4,2},
   {1,-4,2}};

static struct patval fuseki132680[] = {
   {2,-2,1},
   {0,-4,1},
   {-3,3,2},
   {0,-2,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132681[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,0,1},
   {0,-2,1},
   {3,3,1},
   {3,-3,1},
   {0,-4,2},
   {2,-2,2}};

static struct patval fuseki132682[] = {
   {-4,-4,1},
   {-3,-4,1},
   {-4,-3,2},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132683[] = {
   {3,3,1},
   {4,-1,1},
   {1,4,2},
   {3,-3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132684[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-4,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki132685[] = {
   {-4,0,1},
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132686[] = {
   {4,4,1},
   {5,3,1},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {4,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132687[] = {
   {4,4,1},
   {4,5,1},
   {1,5,1},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {4,3,2},
   {-3,-3,2},
   {-3,3,2},
   {5,4,2}};

static struct patval fuseki132688[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132689[] = {
   {4,4,1},
   {-3,3,1},
   {3,-3,1},
   {-3,-3,2}};

static struct patval fuseki132690[] = {
   {-4,-4,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132691[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,0,1},
   {4,4,2}};

static struct patval fuseki132692[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,0,1},
   {4,4,2}};

static struct patval fuseki132693[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,0,1},
   {4,4,2}};

static struct patval fuseki132694[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132695[] = {
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132696[] = {
   {-4,1,1},
   {4,-1,1},
   {-3,3,2},
   {1,-4,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2}};

static struct patval fuseki132697[] = {
   {1,-4,1},
   {-1,4,1},
   {-3,3,2},
   {-3,-3,2},
   {-4,1,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132698[] = {
   {-3,-3,1},
   {-3,3,1},
   {-3,4,1},
   {3,-3,1},
   {-1,2,1},
   {-1,3,1},
   {3,3,1},
   {0,3,2},
   {-2,4,2},
   {-1,4,2}};

static struct patval fuseki132699[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,1,1},
   {3,-3,1},
   {4,3,1},
   {3,1,1},
   {3,3,1},
   {4,1,2},
   {4,2,2},
   {3,0,2}};

static struct patval fuseki132700[] = {
   {-3,-3,1},
   {-3,3,1},
   {-3,4,1},
   {3,-3,1},
   {-1,2,1},
   {-1,3,1},
   {3,3,1},
   {0,3,2},
   {-2,4,2},
   {-1,4,2}};

static struct patval fuseki132701[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2},
   {4,0,2}};

static struct patval fuseki132702[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2},
   {4,0,2}};

static struct patval fuseki132703[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2},
   {4,0,2}};

static struct patval fuseki132704[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,1,1},
   {3,-3,1},
   {3,-1,1},
   {3,3,1},
   {4,-2,1},
   {4,-4,2},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132705[] = {
   {-3,3,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132706[] = {
   {-3,3,1},
   {3,-3,1},
   {4,1,1},
   {3,3,2}};

static struct patval fuseki132707[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {2,-1,1},
   {3,-3,1},
   {3,3,1},
   {3,-1,2}};

static struct patval fuseki132708[] = {
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-2,-1,1},
   {0,0,1},
   {3,-3,1},
   {-3,-1,2}};

static struct patval fuseki132709[] = {
   {2,2,1},
   {4,-1,1},
   {3,1,1},
   {2,-1,2},
   {-3,-3,2},
   {3,-3,2},
   {1,1,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132710[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {5,4,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {4,4,2},
   {1,5,2}};

static struct patval fuseki132711[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,3,1},
   {5,-4,1},
   {3,-3,1},
   {4,-2,1},
   {3,3,1},
   {4,-4,1},
   {4,-3,2},
   {3,0,2},
   {3,-4,2},
   {5,-3,2}};

static struct patval fuseki132712[] = {
   {-4,4,1},
   {4,5,1},
   {-1,4,1},
   {4,4,1},
   {1,5,1},
   {-3,3,2},
   {1,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {4,3,2},
   {-2,5,2},
   {-3,-3,2},
   {5,4,2}};

static struct patval fuseki132713[] = {
   {3,0,1},
   {0,3,1},
   {-3,3,2},
   {1,-3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132714[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {1,3,1},
   {5,4,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {4,4,2},
   {4,5,2},
   {1,5,2}};

static struct patval fuseki132715[] = {
   {-3,-3,1},
   {4,-1,1},
   {3,-3,2},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki132716[] = {
   {3,3,1},
   {1,-4,1},
   {-3,3,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132717[] = {
   {-3,-3,1},
   {-1,4,1},
   {-3,3,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki132718[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {1,-3,1},
   {3,-3,1},
   {3,0,2},
   {0,3,2}};

static struct patval fuseki132719[] = {
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {-1,-3,1},
   {3,1,1},
   {3,-3,1},
   {0,3,2},
   {-3,0,2}};

static struct patval fuseki132720[] = {
   {-3,-3,1},
   {-3,-1,1},
   {-3,3,1},
   {3,3,1},
   {1,3,1},
   {3,-3,1},
   {3,0,2},
   {0,-3,2}};

static struct patval fuseki132721[] = {
   {3,3,1},
   {-1,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2},
   {4,0,2}};

static struct patval fuseki132722[] = {
   {3,3,1},
   {-1,4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2},
   {4,0,2}};

static struct patval fuseki132723[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,2,2}};

static struct patval fuseki132724[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,2,2}};

static struct patval fuseki132725[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {2,4,2}};

static struct patval fuseki132726[] = {
   {-2,2,1},
   {-2,3,1},
   {-4,3,1},
   {-4,4,1},
   {-3,2,1},
   {-3,-3,2},
   {-3,3,2},
   {-3,4,2},
   {-4,1,2},
   {-4,2,2},
   {-1,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132727[] = {
   {3,-4,1},
   {4,-4,1},
   {1,-4,1},
   {2,-4,1},
   {1,-3,2},
   {2,-3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2},
   {4,-3,2}};

static struct patval fuseki132728[] = {
   {4,-1,1},
   {4,-4,1},
   {1,-4,1},
   {3,-3,2},
   {3,-1,2},
   {3,3,2},
   {-3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132729[] = {
   {-4,-3,1},
   {1,-4,1},
   {-3,3,2},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki132730[] = {
   {-4,-3,1},
   {1,-4,1},
   {-3,3,2},
   {3,-3,2},
   {4,4,2}};

static struct patval fuseki132731[] = {
   {4,-1,1},
   {3,4,1},
   {3,-3,2},
   {-3,3,2},
   {-4,-4,2}};

static struct patval fuseki132732[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,-2,1},
   {3,3,2},
   {4,-1,2}};

static struct patval fuseki132733[] = {
   {2,4,1},
   {-1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,2,2},
   {0,0,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132734[] = {
   {4,-2,1},
   {4,1,1},
   {3,1,1},
   {2,3,2},
   {3,-3,2},
   {0,0,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2},
   {4,2,2}};

static struct patval fuseki132735[] = {
   {4,-1,1},
   {5,-3,1},
   {1,-4,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132736[] = {
   {-1,4,1},
   {-3,5,1},
   {-3,3,2},
   {-3,-3,2},
   {-4,1,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132737[] = {
   {3,5,1},
   {1,4,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132738[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {0,3,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki132739[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {3,0,1},
   {0,0,2}};

static struct patval fuseki132740[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {0,3,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki132741[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki132742[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {0,0,2}};

static struct patval fuseki132743[] = {
   {4,-4,1},
   {5,-3,1},
   {-3,0,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2},
   {-3,-3,2},
   {4,-3,2},
   {-3,3,2}};

static struct patval fuseki132744[] = {
   {-5,3,1},
   {-4,4,1},
   {-4,3,2},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132745[] = {
   {-4,1,1},
   {-4,2,1},
   {-2,3,1},
   {-2,4,1},
   {-3,2,1},
   {-3,1,2},
   {-3,3,2},
   {-2,2,2},
   {-4,3,2},
   {-3,-3,2},
   {-1,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132746[] = {
   {-3,-3,1},
   {-3,3,1},
   {5,-3,1},
   {3,-3,1},
   {3,3,1},
   {5,-4,1},
   {4,-3,1},
   {5,-5,2},
   {4,-4,2},
   {3,-4,2}};

static struct patval fuseki132747[] = {
   {-3,-3,1},
   {-3,3,1},
   {5,-3,1},
   {3,-3,1},
   {3,3,1},
   {5,-4,1},
   {4,-3,1},
   {5,-5,2},
   {4,-4,2},
   {3,-4,2}};

static struct patval fuseki132748[] = {
   {-2,2,1},
   {-3,3,2},
   {-3,-3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132749[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {2,-1,1},
   {3,-3,1},
   {4,1,1},
   {3,0,1},
   {3,3,1},
   {4,-2,1},
   {4,-1,2},
   {4,0,2},
   {3,-1,2}};

static struct patval fuseki132750[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {2,-1,1},
   {3,-3,1},
   {4,1,1},
   {3,0,1},
   {3,3,1},
   {4,-2,1},
   {4,-1,2},
   {4,0,2},
   {3,-1,2}};

static struct patval fuseki132751[] = {
   {-4,-4,1},
   {3,3,1},
   {-3,3,2},
   {-1,4,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132752[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {1,3,1},
   {3,-3,1},
   {4,-2,1},
   {3,3,1},
   {3,1,2},
   {3,-1,2},
   {4,-1,2}};

static struct patval fuseki132753[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,1,1},
   {3,-3,1},
   {1,3,2},
   {-1,4,2},
   {-1,3,2}};

static struct patval fuseki132754[] = {
   {0,3,1},
   {3,3,1},
   {0,2,1},
   {-3,-3,2},
   {1,3,2},
   {1,4,2},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132755[] = {
   {4,2,1},
   {3,4,1},
   {3,-3,2},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki132756[] = {
   {4,2,1},
   {3,4,1},
   {3,-3,2},
   {-3,3,2},
   {-3,-3,2}};

static struct patval fuseki132757[] = {
   {0,3,1},
   {-4,-3,1},
   {3,0,1},
   {3,3,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,-3,1},
   {-2,-4,1},
   {-1,-5,1},
   {-1,-3,1},
   {0,-3,1},
   {0,0,1},
   {-4,-4,2},
   {-2,-5,2},
   {-3,-5,2},
   {-3,-4,2}};

static struct patval fuseki132758[] = {
   {-4,-4,1},
   {3,3,1},
   {-3,3,2},
   {1,4,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132759[] = {
   {-4,-3,1},
   {-3,3,1},
   {0,4,1},
   {3,-3,1},
   {3,4,2},
   {4,2,2}};

static struct patval fuseki132760[] = {
   {-3,-4,1},
   {-3,3,1},
   {4,0,1},
   {3,-3,1},
   {2,4,2},
   {4,3,2}};

static struct patval fuseki132761[] = {
   {-4,-4,1},
   {3,3,1},
   {-3,-4,1},
   {-2,-5,1},
   {-3,3,2},
   {-3,-3,2},
   {-2,-4,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132762[] = {
   {-4,-4,1},
   {3,3,1},
   {-3,-4,1},
   {-2,-5,1},
   {-3,3,2},
   {-3,-3,2},
   {-2,-4,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132763[] = {
   {0,4,1},
   {-1,2,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132764[] = {
   {-4,-3,1},
   {-4,1,1},
   {-3,-1,1},
   {-2,-4,1},
   {-3,3,2},
   {-3,2,2},
   {1,2,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki132765[] = {
   {-4,1,1},
   {-3,0,1},
   {-3,-3,2},
   {-3,1,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132766[] = {
   {3,0,1},
   {4,1,1},
   {0,0,2},
   {3,-3,2},
   {-3,-3,2},
   {3,1,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132767[] = {
   {4,-1,1},
   {4,0,1},
   {3,-1,1},
   {-3,3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {0,-3,2},
   {3,0,2},
   {3,3,2},
   {4,-2,2},
   {-3,-3,2},
   {-3,0,2},
   {4,1,2}};

static struct patval fuseki132768[] = {
   {-3,-3,1},
   {3,2,1},
   {2,4,2},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132769[] = {
   {-4,1,1},
   {-1,-3,1},
   {-3,1,1},
   {-3,-3,2},
   {-3,3,2},
   {-4,2,2},
   {-1,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132770[] = {
   {-1,4,1},
   {3,1,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {-3,1,2},
   {3,3,2}};

static struct patval fuseki132771[] = {
   {-3,3,1},
   {-4,-3,1},
   {-3,-1,1},
   {3,-3,1},
   {-3,-3,1},
   {-3,-2,1},
   {-4,-2,2},
   {-4,-4,2},
   {-4,-1,2},
   {3,3,2}};

static struct patval fuseki132772[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki132773[] = {
   {-3,-3,1},
   {3,0,1},
   {3,-3,2},
   {-3,3,2},
   {3,3,2}};

static struct patval fuseki132774[] = {
   {3,3,1},
   {-3,0,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132775[] = {
   {-4,1,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {3,-3,1},
   {1,4,2},
   {4,4,2}};

static struct patval fuseki132776[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {1,-3,1},
   {3,-3,1},
   {3,3,1},
   {3,0,2}};

static struct patval fuseki132777[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {1,3,1},
   {3,-3,1},
   {3,3,1},
   {3,0,2}};

static struct patval fuseki132778[] = {
   {-4,-1,1},
   {1,-3,1},
   {-3,3,2},
   {-1,-3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132779[] = {
   {4,-2,1},
   {4,-1,1},
   {1,-4,1},
   {2,-2,1},
   {3,-2,1},
   {3,-3,2},
   {3,-4,2},
   {3,-1,2},
   {3,3,2},
   {4,-3,2},
   {-3,-3,2},
   {-3,3,2},
   {4,1,2}};

static struct patval fuseki132780[] = {
   {-3,-5,1},
   {-1,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {-1,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132781[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1},
   {4,4,2}};

static struct patval fuseki132782[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,0,1},
   {3,3,1},
   {4,-4,2}};

static struct patval fuseki132783[] = {
   {-4,-4,1},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2}};

static struct patval fuseki132784[] = {
   {-4,1,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {4,-1,1},
   {3,-3,1},
   {1,4,2},
   {1,-4,2},
   {4,4,2}};

static struct patval fuseki132785[] = {
   {-4,-1,1},
   {-4,1,1},
   {-3,-3,2},
   {-3,3,2},
   {-1,4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132786[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {0,4,1},
   {1,-3,1},
   {3,-3,1},
   {3,3,1},
   {3,4,1},
   {4,5,1},
   {4,-1,2},
   {4,3,2},
   {4,4,2},
   {4,-3,2}};

static struct patval fuseki132787[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1},
   {4,1,2}};

static struct patval fuseki132788[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,2}};

static struct patval fuseki132789[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,5,1},
   {3,3,1},
   {0,0,1},
   {3,-3,1},
   {-1,3,2}};

static struct patval fuseki132790[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,5,1},
   {3,3,1},
   {0,0,1},
   {3,-3,1},
   {-1,3,2}};

static struct patval fuseki132791[] = {
   {-4,1,1},
   {-4,2,1},
   {-3,2,1},
   {-2,3,1},
   {-3,1,2},
   {-4,3,2},
   {-3,3,2},
   {-2,2,2},
   {-3,-3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132792[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,-3,1},
   {-1,4,2},
   {3,3,2}};

static struct patval fuseki132793[] = {
   {-5,2,1},
   {-4,4,1},
   {-4,3,1},
   {-4,2,2},
   {-3,-3,2},
   {-3,3,2},
   {-3,4,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132794[] = {
   {-5,-2,1},
   {-4,-4,1},
   {-4,-3,1},
   {-4,-2,2},
   {-3,-4,2},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132795[] = {
   {3,-3,1},
   {-4,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {-4,-4,2},
   {3,3,2}};

static struct patval fuseki132796[] = {
   {3,0,1},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132797[] = {
   {3,0,1},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132798[] = {
   {-3,-3,1},
   {-4,3,1},
   {-4,4,1},
   {-3,5,1},
   {-3,3,2},
   {-3,4,2},
   {-4,2,2},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki132799[] = {
   {-5,3,1},
   {3,3,1},
   {-3,4,1},
   {-4,4,1},
   {-3,3,2},
   {-4,3,2},
   {-2,4,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132800[] = {
   {-2,-4,1},
   {-4,-3,1},
   {-4,1,1},
   {-3,-1,1},
   {4,-4,1},
   {-3,2,2},
   {-5,3,2},
   {1,2,2},
   {3,-3,2},
   {-3,3,2},
   {4,3,2}};

static struct patval fuseki132801[] = {
   {-4,2,1},
   {3,4,1},
   {3,-3,1},
   {-3,4,1},
   {-3,3,1},
   {-3,-3,2},
   {-4,4,2},
   {-4,3,2}};

static struct patval fuseki132802[] = {
   {0,3,1},
   {3,3,1},
   {-3,-3,2},
   {1,4,2},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132803[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-3,1},
   {3,-3,1},
   {3,3,1},
   {4,1,1},
   {4,-1,2},
   {1,-3,2}};

static struct patval fuseki132804[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,0,1},
   {3,-3,1},
   {3,3,1},
   {4,4,1},
   {4,0,2},
   {3,4,2}};

static struct patval fuseki132805[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,0,1},
   {3,-3,1},
   {3,3,1},
   {4,4,1},
   {4,0,2},
   {3,4,2}};

static struct patval fuseki132806[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {1,3,1},
   {2,-2,1},
   {3,3,1},
   {3,0,2},
   {1,-3,2}};

static struct patval fuseki132807[] = {
   {-3,-3,1},
   {-3,3,1},
   {1,-3,1},
   {3,3,1},
   {2,2,1},
   {3,-3,1},
   {3,0,2},
   {1,3,2}};

static struct patval fuseki132808[] = {
   {-4,-4,1},
   {-3,-5,1},
   {3,3,1},
   {-1,-4,1},
   {-2,-4,1},
   {-3,3,2},
   {-2,-3,2},
   {-3,-3,2},
   {-1,-3,2},
   {3,-3,2},
   {-3,-4,2}};

static struct patval fuseki132809[] = {
   {-5,-3,1},
   {-4,-4,1},
   {3,3,1},
   {-4,-2,1},
   {-4,-1,1},
   {-3,-3,2},
   {-3,-2,2},
   {-3,-1,2},
   {-3,3,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132810[] = {
   {-4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {-2,-2,1},
   {-2,-4,2},
   {3,3,2}};

static struct patval fuseki132811[] = {
   {-4,-2,1},
   {3,3,1},
   {-4,3,1},
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {-4,4,2},
   {-4,0,2}};

static struct patval fuseki132812[] = {
   {-5,-1,1},
   {-4,-3,1},
   {-4,1,1},
   {3,-3,1},
   {-3,3,1},
   {1,-4,1},
   {-1,4,2},
   {-2,-4,2},
   {-3,-2,2},
   {3,3,2}};

static struct patval fuseki132813[] = {
   {-4,-4,1},
   {4,-1,1},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132814[] = {
   {4,4,1},
   {1,-4,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132815[] = {
   {3,3,1},
   {2,2,1},
   {0,2,1},
   {0,3,1},
   {-3,-3,2},
   {1,4,2},
   {-3,3,2},
   {3,-3,2},
   {3,1,2},
   {1,3,2}};

static struct patval fuseki132816[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {1,-3,1},
   {3,-3,1},
   {3,3,1},
   {4,-4,1},
   {4,-3,2},
   {4,-1,2}};

static struct patval fuseki132817[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {1,-3,1},
   {3,-3,1},
   {3,3,1},
   {4,-4,1},
   {4,-3,2},
   {4,-1,2}};

static struct patval fuseki132818[] = {
   {3,-3,1},
   {-3,3,1},
   {2,1,1},
   {2,4,1},
   {5,2,1},
   {3,2,2},
   {4,-1,2},
   {-3,-3,2}};

static struct patval fuseki132819[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,0,1},
   {4,3,2}};

static struct patval fuseki132820[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,4,1},
   {3,-3,1},
   {3,4,2}};

static struct patval fuseki132821[] = {
   {3,3,1},
   {1,3,1},
   {5,3,1},
   {-1,4,1},
   {2,3,1},
   {-3,1,2},
   {1,4,2},
   {0,3,2},
   {3,-3,2},
   {-3,-3,2},
   {4,0,2},
   {-3,3,2}};

static struct patval fuseki132822[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,3,1},
   {3,-3,1},
   {2,4,2}};

static struct patval fuseki132823[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,4,1},
   {4,2,2}};

static struct patval fuseki132824[] = {
   {0,0,1},
   {3,-3,1},
   {-4,3,1},
   {-3,-3,1},
   {-3,1,1},
   {-2,2,1},
   {-3,3,1},
   {3,3,1},
   {-3,2,2},
   {-4,2,2},
   {-4,1,2}};

static struct patval fuseki132825[] = {
   {3,-3,1},
   {-4,-3,1},
   {-1,4,1},
   {-3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {-3,-4,2},
   {-4,-4,2},
   {3,3,2}};

static struct patval fuseki132826[] = {
   {4,1,1},
   {-3,3,1},
   {2,1,1},
   {2,4,1},
   {3,-3,1},
   {5,2,1},
   {4,-1,2},
   {-3,-3,2},
   {4,2,2},
   {3,2,2}};

static struct patval fuseki132827[] = {
   {3,-3,1},
   {-3,3,1},
   {2,4,1},
   {-3,-4,2}};

static struct patval fuseki132828[] = {
   {-4,-2,1},
   {-3,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132829[] = {
   {4,-1,1},
   {1,-3,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132830[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,-4,1},
   {4,1,1},
   {4,-1,2},
   {4,-3,2}};

static struct patval fuseki132831[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,-4,1},
   {4,1,1},
   {4,-1,2},
   {4,-3,2}};

static struct patval fuseki132832[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-3,1},
   {0,-2,1},
   {3,3,1},
   {3,-3,1},
   {3,0,1},
   {3,-2,2},
   {2,-2,2},
   {0,-4,2}};

static struct patval fuseki132833[] = {
   {3,4,1},
   {3,2,1},
   {3,0,1},
   {2,5,1},
   {2,3,1},
   {2,-1,2},
   {3,-3,2},
   {1,-3,2},
   {-3,3,2},
   {3,3,2},
   {-3,-3,2},
   {4,3,2},
   {4,4,2}};

static struct patval fuseki132834[] = {
   {4,4,1},
   {4,-1,1},
   {5,5,1},
   {4,-3,1},
   {4,3,1},
   {0,4,2},
   {3,3,2},
   {3,4,2},
   {3,-3,2},
   {-3,3,2},
   {1,-3,2},
   {-3,-3,2},
   {4,5,2},
   {0,0,2}};

static struct patval fuseki132835[] = {
   {1,-3,1},
   {-3,0,1},
   {-3,3,2},
   {-1,-3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132836[] = {
   {3,0,1},
   {-1,3,1},
   {-3,3,2},
   {1,3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2}};

static struct patval fuseki132837[] = {
   {4,-3,1},
   {4,-2,1},
   {4,-4,1},
   {3,-3,2},
   {3,-2,2},
   {3,3,2},
   {3,-4,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132838[] = {
   {2,4,1},
   {4,4,1},
   {3,4,1},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {2,3,2},
   {4,3,2},
   {-3,3,2}};

static struct patval fuseki132839[] = {
   {-4,-4,1},
   {4,-4,1},
   {3,-4,1},
   {3,-3,2},
   {-3,3,2},
   {4,-3,2},
   {4,4,2}};

static struct patval fuseki132840[] = {
   {1,-4,1},
   {3,3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {-3,0,2}};

static struct patval fuseki132841[] = {
   {1,-4,1},
   {3,3,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {-3,0,2}};

static struct patval fuseki132842[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,0,1},
   {3,-3,1},
   {-1,4,2},
   {-1,2,2}};

static struct patval fuseki132843[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,0,1},
   {3,-3,1},
   {-1,4,2},
   {-1,2,2}};

static struct patval fuseki132844[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-1,1},
   {1,-4,1},
   {3,-3,1},
   {-1,-4,2},
   {4,4,2}};

static struct patval fuseki132845[] = {
   {-4,-4,1},
   {-3,-4,1},
   {-3,-5,1},
   {-2,-5,1},
   {-4,-3,2},
   {-3,0,2},
   {-3,3,2},
   {-3,-3,2},
   {-2,-4,2},
   {-1,-5,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132846[] = {
   {0,-4,1},
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {-2,-4,1},
   {3,3,1},
   {-1,-3,1},
   {-3,-5,2},
   {-2,-5,2},
   {-1,-4,2}};

static struct patval fuseki132847[] = {
   {2,-1,1},
   {4,-1,1},
   {-2,-4,1},
   {-2,-3,1},
   {1,-3,1},
   {-1,-3,2},
   {-1,-4,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {4,-3,2},
   {-3,3,2},
   {4,1,2}};

static struct patval fuseki132848[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,1,1},
   {3,-4,1},
   {3,-3,1},
   {4,-3,1},
   {3,-1,1},
   {3,3,1},
   {3,-2,2},
   {4,-2,2},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132849[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {1,3,1},
   {3,-3,1},
   {-1,3,2},
   {4,1,2}};

static struct patval fuseki132850[] = {
   {3,-1,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,-3,1},
   {3,3,1},
   {3,-3,1},
   {-4,-1,2},
   {1,-3,2}};

static struct patval fuseki132851[] = {
   {3,-3,1},
   {-3,3,1},
   {-3,-3,1},
   {-3,-2,1},
   {-3,-1,1},
   {-4,-1,2},
   {-4,-2,2},
   {3,3,2}};

static struct patval fuseki132852[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {3,-4,1},
   {3,-3,1},
   {3,3,1},
   {4,-4,2},
   {4,-3,2}};

static struct patval fuseki132853[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1},
   {3,4,1},
   {4,3,2},
   {4,4,2}};

static struct patval fuseki132854[] = {
   {-4,4,1},
   {-3,-3,1},
   {-3,3,2},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki132855[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,2,1},
   {4,4,2}};

static struct patval fuseki132856[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,4,1},
   {3,-3,1},
   {4,4,2}};

static struct patval fuseki132857[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {4,1,1},
   {3,-4,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132858[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {4,1,1},
   {3,-4,1},
   {3,-3,1},
   {3,3,1},
   {4,-1,2},
   {1,-4,2}};

static struct patval fuseki132859[] = {
   {5,-5,1},
   {4,-4,1},
   {3,-4,1},
   {3,-3,2},
   {3,3,2},
   {-3,3,2},
   {4,-3,2},
   {-3,-3,2},
   {5,-4,2}};

static struct patval fuseki132860[] = {
   {-3,3,1},
   {2,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132861[] = {
   {-3,3,1},
   {2,3,1},
   {3,-3,1},
   {4,3,2}};

static struct patval fuseki132862[] = {
   {3,-1,1},
   {4,-1,1},
   {4,-4,1},
   {1,-4,1},
   {1,-3,1},
   {2,-5,2},
   {2,-4,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2},
   {0,0,2},
   {4,-2,2},
   {-3,3,2},
   {4,1,2}};

static struct patval fuseki132863[] = {
   {3,-2,1},
   {2,-2,1},
   {0,-4,1},
   {4,-2,1},
   {-3,3,2},
   {3,-3,2},
   {0,-2,2},
   {3,0,2},
   {3,3,2},
   {4,-3,2},
   {-3,-3,2}};

static struct patval fuseki132864[] = {
   {-4,4,1},
   {-4,0,1},
   {-4,-2,2},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132865[] = {
   {-5,3,1},
   {-4,4,1},
   {-4,3,2},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132866[] = {
   {-4,-1,1},
   {3,1,1},
   {4,-1,1},
   {2,2,1},
   {-3,-3,2},
   {2,-1,2},
   {0,3,2},
   {3,-3,2},
   {1,1,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132867[] = {
   {4,0,1},
   {-3,-3,2},
   {0,-3,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132868[] = {
   {4,0,1},
   {-3,-3,2},
   {0,-3,2},
   {0,3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132869[] = {
   {-4,-4,1},
   {3,3,1},
   {-3,-4,1},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132870[] = {
   {-4,2,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {3,-3,1},
   {3,3,1},
   {4,-3,2},
   {4,-2,2}};

static struct patval fuseki132871[] = {
   {-1,4,1},
   {1,4,1},
   {-3,5,1},
   {-3,3,2},
   {-3,1,2},
   {-4,4,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132872[] = {
   {-1,4,1},
   {1,4,1},
   {-3,5,1},
   {-3,3,2},
   {-3,1,2},
   {-4,4,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132873[] = {
   {-1,4,1},
   {3,3,1},
   {-3,4,1},
   {-3,3,2},
   {-3,-3,2},
   {3,-3,2},
   {-3,1,2}};

static struct patval fuseki132874[] = {
   {-3,-3,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {1,4,1},
   {-1,4,2},
   {-1,3,2}};

static struct patval fuseki132875[] = {
   {-4,-1,1},
   {3,3,1},
   {-4,2,1},
   {-3,-3,1},
   {3,-3,1},
   {-3,3,1},
   {-3,1,2},
   {-4,1,2}};

static struct patval fuseki132876[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {-1,2,2}};

static struct patval fuseki132877[] = {
   {4,0,1},
   {-4,-3,1},
   {4,4,1},
   {-3,-2,1},
   {3,4,1},
   {2,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2},
   {4,-2,2},
   {-4,-4,2},
   {4,2,2},
   {-3,-3,2}};

static struct patval fuseki132878[] = {
   {1,-4,1},
   {4,4,1},
   {1,4,1},
   {-1,4,2},
   {-4,1,2},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132879[] = {
   {4,0,1},
   {4,3,1},
   {2,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132880[] = {
   {0,4,1},
   {3,4,1},
   {0,2,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132881[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {2,-2,1},
   {3,-4,1},
   {4,-3,1},
   {4,3,1},
   {1,-4,2},
   {4,-1,2},
   {4,-4,2},
   {5,-3,2}};

static struct patval fuseki132882[] = {
   {-4,1,1},
   {-1,-4,1},
   {0,-3,1},
   {-2,-4,1},
   {-3,-3,2},
   {-1,-3,2},
   {-1,-2,2},
   {-1,3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132883[] = {
   {4,-3,1},
   {4,-1,1},
   {4,3,1},
   {0,4,2},
   {1,-3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2}};

static struct patval fuseki132884[] = {
   {-5,-2,1},
   {-4,-2,1},
   {-4,-3,2},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132885[] = {
   {-4,-2,1},
   {4,3,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-4,2}};

static struct patval fuseki132886[] = {
   {-4,-3,1},
   {4,2,1},
   {3,-3,2},
   {3,4,2},
   {-3,3,2}};

static struct patval fuseki132887[] = {
   {4,-1,1},
   {3,3,1},
   {3,-3,2},
   {1,4,2},
   {-3,3,2}};

static struct patval fuseki132888[] = {
   {4,-1,1},
   {3,3,1},
   {3,-3,2},
   {1,4,2},
   {-3,3,2}};

static struct patval fuseki132889[] = {
   {-4,-1,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {-4,1,2}};

static struct patval fuseki132890[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1},
   {4,1,1},
   {4,-1,2}};

static struct patval fuseki132891[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {4,0,1},
   {1,4,1},
   {3,-3,1},
   {3,3,2},
   {-1,4,2},
   {5,3,2}};

static struct patval fuseki132892[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-4,1},
   {3,-3,1},
   {3,3,1},
   {4,-3,2}};

static struct patval fuseki132893[] = {
   {-3,-3,1},
   {4,2,1},
   {3,2,1},
   {4,-1,1},
   {3,1,1},
   {3,-3,2},
   {2,1,2},
   {2,4,2},
   {4,1,2},
   {-3,3,2},
   {5,2,2}};

static struct patval fuseki132894[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {-3,5,1},
   {3,3,1},
   {0,0,1},
   {1,4,1},
   {-3,4,2},
   {-1,4,2}};

static struct patval fuseki132895[] = {
   {3,-3,1},
   {-3,3,1},
   {2,1,1},
   {2,4,1},
   {-3,-3,2},
   {3,2,2}};

static struct patval fuseki132896[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {5,2,1},
   {4,1,2}};

static struct patval fuseki132897[] = {
   {-5,2,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {-4,1,2}};

static struct patval fuseki132898[] = {
   {-1,-2,1},
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {-1,-3,1},
   {3,3,1},
   {-1,3,1},
   {0,-3,2},
   {-1,-4,2},
   {-4,1,2}};

static struct patval fuseki132899[] = {
   {-4,4,1},
   {-1,4,1},
   {-3,4,1},
   {-3,3,2},
   {-3,5,2},
   {-3,-3,2},
   {0,0,2},
   {1,4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132900[] = {
   {3,-3,1},
   {-2,-5,1},
   {-4,-2,1},
   {-3,3,1},
   {-3,-4,1},
   {-3,-3,1},
   {4,-1,1},
   {-3,-5,2},
   {-4,-4,2},
   {3,3,2},
   {-4,-3,2}};

static struct patval fuseki132901[] = {
   {-1,4,1},
   {-5,-2,1},
   {-3,3,1},
   {-4,-3,1},
   {-2,-4,1},
   {-3,-3,1},
   {3,-3,1},
   {-3,-4,2},
   {-5,-3,2},
   {-4,-4,2},
   {3,3,2}};

static struct patval fuseki132902[] = {
   {-3,-3,1},
   {-3,3,1},
   {2,1,1},
   {3,-3,1},
   {4,1,1},
   {4,-1,2},
   {3,3,2}};

static struct patval fuseki132903[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {1,2,1},
   {1,4,1},
   {-1,4,2},
   {3,3,2}};

static struct patval fuseki132904[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,1},
   {3,4,1},
   {4,3,1},
   {5,2,1},
   {4,5,2},
   {4,4,2},
   {5,3,2}};

static struct patval fuseki132905[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {1,4,1},
   {-4,-4,2},
   {3,3,2}};

static struct patval fuseki132906[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {1,4,1},
   {-4,-4,2},
   {3,3,2}};

static struct patval fuseki132907[] = {
   {-4,0,1},
   {-4,1,1},
   {-3,-3,2},
   {-3,1,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132908[] = {
   {-4,0,1},
   {-4,1,1},
   {-3,-3,2},
   {-3,1,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132909[] = {
   {-5,-3,1},
   {-4,-4,1},
   {3,3,1},
   {-3,-4,1},
   {-3,-3,2},
   {-3,3,2},
   {-2,-4,2},
   {-1,4,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132910[] = {
   {-3,-4,1},
   {-4,-3,1},
   {-4,-4,2},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132911[] = {
   {-4,3,1},
   {-3,4,1},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {-4,4,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132912[] = {
   {-3,-4,1},
   {4,0,1},
   {4,4,1},
   {3,4,1},
   {-3,-3,2},
   {3,3,2},
   {2,0,2},
   {4,-2,2},
   {3,-3,2},
   {4,2,2},
   {-3,3,2}};

static struct patval fuseki132913[] = {
   {-4,-3,1},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132914[] = {
   {0,0,1},
   {0,-4,1},
   {-3,3,2},
   {0,-2,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132915[] = {
   {-4,0,1},
   {0,0,1},
   {-3,3,2},
   {-2,0,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132916[] = {
   {-1,4,1},
   {3,3,1},
   {4,0,1},
   {-3,-2,1},
   {-2,-4,1},
   {-3,3,2},
   {-5,-1,2},
   {1,-4,2},
   {3,-3,2},
   {-4,-3,2},
   {-4,1,2}};

static struct patval fuseki132917[] = {
   {-1,4,1},
   {1,3,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {-3,1,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132918[] = {
   {-4,1,1},
   {-4,2,1},
   {-3,-3,2},
   {-3,1,2},
   {-3,3,2},
   {0,0,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132919[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {4,0,1},
   {3,-3,1},
   {3,2,2},
   {1,3,2}};

static struct patval fuseki132920[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {4,0,1},
   {3,-3,1},
   {3,2,2},
   {1,3,2}};

static struct patval fuseki132921[] = {
   {4,0,1},
   {4,3,1},
   {0,0,2},
   {3,-3,2},
   {3,-1,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132922[] = {
   {3,-3,1},
   {-4,1,1},
   {-3,-3,1},
   {-3,-1,1},
   {-3,3,1},
   {3,3,1},
   {-4,-1,2},
   {-2,-1,2}};

static struct patval fuseki132923[] = {
   {-3,-3,1},
   {-3,3,1},
   {4,-1,1},
   {3,-3,1},
   {3,1,1},
   {3,3,1},
   {2,1,2},
   {4,1,2}};

static struct patval fuseki132924[] = {
   {-5,-4,1},
   {-4,-4,1},
   {-2,-5,1},
   {-3,-5,1},
   {-3,-4,1},
   {-3,-3,2},
   {-3,0,2},
   {-3,3,2},
   {-4,-3,2},
   {-2,-4,2},
   {-1,-5,2},
   {-1,-3,2},
   {0,-3,2},
   {0,0,2},
   {0,3,2},
   {3,-3,2},
   {3,0,2},
   {3,3,2}};

static struct patval fuseki132925[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,0,1},
   {3,-3,1},
   {3,3,2}};

static struct patval fuseki132926[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,1,1},
   {1,2,1},
   {1,3,1},
   {1,4,1},
   {2,2,2},
   {0,2,2},
   {0,3,2},
   {3,3,2}};

static struct patval fuseki132927[] = {
   {4,-3,1},
   {4,-1,1},
   {0,0,2},
   {1,-3,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132928[] = {
   {-4,-2,1},
   {-4,-1,1},
   {3,3,1},
   {-3,-1,2},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2}};

static struct patval fuseki132929[] = {
   {-3,-3,1},
   {-3,0,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {3,0,2}};

static struct patval fuseki132930[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {0,3,1},
   {3,-3,1},
   {0,-3,2}};

static struct patval fuseki132931[] = {
   {4,-1,1},
   {3,-4,1},
   {5,-3,1},
   {1,-4,1},
   {4,-4,1},
   {-3,3,2},
   {3,-3,2},
   {2,-2,2},
   {4,-3,2},
   {-3,-3,2},
   {4,3,2},
   {0,-2,2}};

static struct patval fuseki132932[] = {
   {-4,4,1},
   {-5,-2,1},
   {-4,-2,1},
   {-4,-3,2},
   {-5,-3,2},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132933[] = {
   {-4,4,1},
   {-5,-2,1},
   {-4,-2,1},
   {-4,-3,2},
   {-5,-3,2},
   {-3,-3,2},
   {-3,3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132934[] = {
   {3,3,1},
   {4,-1,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2},
   {-3,0,2}};

static struct patval fuseki132935[] = {
   {3,3,1},
   {4,-1,1},
   {-3,3,2},
   {3,-3,2},
   {-3,-3,2},
   {-3,0,2}};

static struct patval fuseki132936[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {1,5,1},
   {3,-3,1},
   {1,4,2}};

static struct patval fuseki132937[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {1,5,1},
   {3,-3,1},
   {1,4,2}};

static struct patval fuseki132938[] = {
   {-1,4,1},
   {-4,4,1},
   {-2,3,1},
   {-3,4,1},
   {-3,3,2},
   {-3,5,2},
   {-3,-3,2},
   {-4,3,2},
   {0,0,2},
   {1,4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132939[] = {
   {1,-3,1},
   {4,-1,1},
   {-2,-4,1},
   {2,-1,1},
   {-3,-3,2},
   {-1,-3,2},
   {3,-3,2},
   {3,3,2},
   {4,-3,2},
   {-3,3,2},
   {4,1,2}};

static struct patval fuseki132940[] = {
   {3,-4,1},
   {4,-4,1},
   {2,-4,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132941[] = {
   {3,-2,1},
   {4,-2,1},
   {0,0,2},
   {3,-3,2},
   {-3,-3,2},
   {3,3,2},
   {4,-3,2},
   {-3,3,2}};

static struct patval fuseki132942[] = {
   {1,4,1},
   {3,-5,1},
   {4,4,1},
   {1,-4,1},
   {-1,4,2},
   {-4,1,2},
   {-3,-3,2},
   {3,-3,2},
   {4,-1,2},
   {-3,3,2}};

static struct patval fuseki132943[] = {
   {1,-4,1},
   {1,-3,1},
   {0,-1,1},
   {-1,-3,1},
   {-1,-4,1},
   {-2,-4,2},
   {-3,3,2},
   {-3,-3,2},
   {-3,-1,2},
   {2,-4,2},
   {3,-3,2},
   {3,-1,2},
   {3,3,2}};

static struct patval fuseki132944[] = {
   {-3,-1,1},
   {-4,-1,1},
   {4,4,1},
   {-4,-2,2},
   {-3,-3,2},
   {0,3,2},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132945[] = {
   {-3,-1,1},
   {-4,-1,1},
   {4,4,1},
   {-4,-2,2},
   {-3,-3,2},
   {0,3,2},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132946[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {1,3,1},
   {0,4,1},
   {0,1,2},
   {-1,4,2},
   {3,1,2},
   {-1,3,2}};

static struct patval fuseki132947[] = {
   {-4,0,1},
   {3,-3,1},
   {-4,2,1},
   {-3,-3,1},
   {-3,-1,1},
   {-1,3,1},
   {-3,3,1},
   {3,3,1},
   {-1,0,2},
   {-3,1,2},
   {-4,1,2},
   {-1,-3,2}};

static struct patval fuseki132948[] = {
   {-4,-4,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {-3,-4,2}};

static struct patval fuseki132949[] = {
   {-4,4,1},
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {3,-3,1},
   {-3,4,2}};

static struct patval fuseki132950[] = {
   {-3,-3,1},
   {-3,3,1},
   {-3,5,1},
   {3,3,1},
   {0,0,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132951[] = {
   {1,5,1},
   {4,4,1},
   {5,3,1},
   {2,5,1},
   {3,4,1},
   {-3,-3,2},
   {1,4,2},
   {3,-3,2},
   {3,3,2},
   {2,4,2},
   {4,3,2},
   {-3,3,2},
   {0,4,2}};

static struct patval fuseki132952[] = {
   {-4,-3,1},
   {-2,-4,1},
   {-3,3,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki132953[] = {
   {-5,-1,1},
   {-4,-3,1},
   {3,-3,1},
   {-3,3,1},
   {1,-4,1},
   {-2,-4,2},
   {-3,-2,2},
   {3,3,2}};

static struct patval fuseki132954[] = {
   {-3,-3,1},
   {4,-1,1},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132955[] = {
   {4,-1,1},
   {2,-1,1},
   {1,-3,1},
   {-3,3,2},
   {3,-3,2},
   {3,3,2},
   {4,-3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132956[] = {
   {1,3,1},
   {1,4,1},
   {0,0,1},
   {-1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {-3,1,2},
   {2,4,2},
   {3,-3,2},
   {3,1,2},
   {3,3,2}};

static struct patval fuseki132957[] = {
   {1,3,1},
   {1,4,1},
   {0,0,1},
   {-1,4,1},
   {-1,3,1},
   {-2,4,2},
   {-3,3,2},
   {-3,-3,2},
   {-3,1,2},
   {2,4,2},
   {3,-3,2},
   {3,1,2},
   {3,3,2}};

static struct patval fuseki132958[] = {
   {-3,-5,1},
   {-1,-4,1},
   {-3,3,2},
   {-3,-3,2},
   {0,0,2},
   {1,-4,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132959[] = {
   {4,1,1},
   {5,3,1},
   {0,0,2},
   {3,-3,2},
   {3,3,2},
   {4,-1,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132960[] = {
   {-4,1,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {4,-4,1},
   {4,-1,1},
   {3,-3,1},
   {3,-5,2},
   {1,-4,2},
   {1,4,2},
   {4,4,2}};

static struct patval fuseki132961[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,1,1},
   {3,3,2}};

static struct patval fuseki132962[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,1,1},
   {3,3,2}};

static struct patval fuseki132963[] = {
   {1,4,1},
   {4,4,1},
   {-1,4,2},
   {-3,-3,2},
   {3,-3,2},
   {-3,3,2}};

static struct patval fuseki132964[] = {
   {3,-3,1},
   {3,3,1},
   {-4,3,1},
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {0,0,1},
   {-4,1,2},
   {-4,2,2}};

static struct patval fuseki132965[] = {
   {4,-3,1},
   {-3,3,1},
   {3,-3,1},
   {4,4,1},
   {-4,-4,2},
   {4,-4,2}};

static struct patval fuseki132966[] = {
   {-4,-1,1},
   {-4,1,1},
   {4,1,1},
   {-3,-3,2},
   {-1,-4,2},
   {-1,4,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132967[] = {
   {-4,-1,1},
   {-4,1,1},
   {4,1,1},
   {-3,-3,2},
   {-1,-4,2},
   {-1,4,2},
   {3,-3,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132968[] = {
   {-3,-5,1},
   {-1,-4,1},
   {-2,-5,1},
   {-3,3,2},
   {-2,-4,2},
   {-3,-3,2},
   {-1,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132969[] = {
   {-5,2,1},
   {3,3,1},
   {-4,3,1},
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-4,4,2},
   {-5,3,2}};

static struct patval fuseki132970[] = {
   {3,-3,1},
   {-5,-2,1},
   {-3,3,1},
   {-4,-3,1},
   {-3,-3,1},
   {3,3,1},
   {-5,-3,2},
   {-4,-4,2}};

static struct patval fuseki132971[] = {
   {3,-3,1},
   {-4,-1,1},
   {-3,3,1},
   {-4,4,1},
   {-3,-3,1},
   {3,3,1},
   {-5,3,2},
   {-4,1,2}};

static struct patval fuseki132972[] = {
   {4,4,1},
   {-3,3,1},
   {3,-3,1},
   {-4,-4,2}};

static struct patval fuseki132973[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {-2,4,1},
   {3,3,1},
   {3,-3,1},
   {3,1,2},
   {0,3,2}};

static struct patval fuseki132974[] = {
   {-3,-3,1},
   {3,3,1},
   {-3,3,1},
   {3,1,1},
   {2,4,1},
   {3,-3,1},
   {0,3,2},
   {-3,1,2}};

static struct patval fuseki132975[] = {
   {-4,3,1},
   {-4,4,1},
   {-3,-3,1},
   {-3,3,2},
   {-3,4,2},
   {3,-3,2},
   {3,4,2}};

static struct patval fuseki132976[] = {
   {-4,-3,1},
   {-4,1,1},
   {-2,-4,1},
   {-3,3,2},
   {1,2,2},
   {3,-3,2},
   {4,3,2}};

static struct patval fuseki132977[] = {
   {-3,-3,1},
   {-3,1,1},
   {-3,3,1},
   {3,3,1},
   {0,0,1},
   {1,-4,1},
   {3,-3,1},
   {-1,4,2},
   {4,-1,2}};

static struct patval fuseki132978[] = {
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,3,1},
   {0,0,1},
   {4,-1,1},
   {3,-3,1},
   {-4,1,2},
   {1,-4,2}};

static struct patval fuseki132979[] = {
   {-3,-3,1},
   {4,-1,1},
   {3,2,1},
   {2,4,2},
   {3,-3,2},
   {2,1,2},
   {-3,3,2}};

static struct patval fuseki132980[] = {
   {-3,3,1},
   {3,-3,1},
   {3,2,1},
   {4,3,2}};

static struct patval fuseki132981[] = {
   {3,-3,1},
   {-3,3,1},
   {-2,-3,1},
   {-3,-4,2}};

static struct patval fuseki132982[] = {
   {3,4,1},
   {4,0,1},
   {2,0,2},
   {3,-3,2},
   {3,3,2},
   {-3,-3,2},
   {-3,3,2}};

static struct patval fuseki132983[] = {
   {2,-4,1},
   {-3,3,1},
   {1,-4,1},
   {4,-3,1},
   {3,-3,1},
   {4,4,1},
   {-4,-4,2},
   {4,-4,2},
   {2,-5,2},
   {3,-4,2}};

static struct patval fuseki132984[] = {
   {3,0,1},
   {4,1,1},
   {0,-3,2},
   {0,3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,1,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132985[] = {
   {3,0,1},
   {4,1,1},
   {0,-3,2},
   {0,3,2},
   {3,-3,2},
   {-3,-3,2},
   {3,1,2},
   {3,3,2},
   {-3,3,2}};

static struct patval fuseki132986[] = {
   {4,-1,1},
   {4,3,1},
   {4,4,1},
   {4,-3,1},
   {1,-3,2},
   {3,-3,2},
   {3,3,2},
   {3,4,2},
   {0,4,2},
   {-3,-3,2},
   {-3,3,2},
   {0,0,2}};

static struct patval fuseki132987[] = {
   {-4,1,1},
   {0,-3,1},
   {-1,-4,1},
   {-3,3,2},
   {-1,-3,2},
   {-1,3,2},
   {-3,-3,2},
   {3,-3,2},
   {3,3,2}};

static struct patval fuseki132988[] = {
   {-4,3,1},
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {3,3,1},
   {-3,5,1},
   {1,4,1},
   {0,0,1},
   {-1,4,2},
   {-4,4,2},
   {-3,4,2}};

static struct patval fuseki132989[] = {
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,4,1},
   {1,-4,1},
   {3,-3,1},
   {-4,1,2},
   {4,-1,2}};

static struct patval fuseki132990[] = {
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {-1,-4,1},
   {1,4,1},
   {3,-3,1},
   {-4,-1,2},
   {4,1,2}};

static struct patval fuseki132991[] = {
   {-1,4,1},
   {3,3,1},
   {-3,-2,1},
   {-2,-4,1},
   {-3,3,2},
   {-5,-1,2},
   {1,-4,2},
   {3,-3,2},
   {-4,-3,2}};

static struct patval fuseki132992[] = {
   {4,-1,1},
   {3,3,1},
   {3,-3,2},
   {-3,3,2},
   {-3,-3,2},
   {4,1,2}};

static struct patval fuseki132993[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {1,3,1},
   {1,4,1},
   {0,3,2},
   {3,3,2}};

static struct patval fuseki132994[] = {
   {-3,-3,1},
   {-3,3,1},
   {-3,4,1},
   {3,3,1},
   {3,-3,1},
   {-1,4,2}};

static struct patval fuseki132995[] = {
   {-3,-3,1},
   {-3,3,1},
   {3,-3,1},
   {3,3,1},
   {4,3,1},
   {4,1,2}};

static struct patval fuseki132996[] = {
   {3,-3,1},
   {-3,-3,1},
   {-3,3,1},
   {-2,-4,1},
   {3,3,1},
   {-1,-3,1},
   {-3,-5,2},
   {-1,-4,2}};

static struct patval fuseki132997[] = {
   {-4,-3,1},
   {3,3,1},
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {-4,-1,2}};

static struct patval fuseki132998[] = {
   {-3,-3,1},
   {-3,3,1},
   {0,-3,1},
   {0,0,1},
   {0,3,1},
   {3,-3,1},
   {3,3,1},
   {4,-3,1},
   {4,-1,2}};


void
init_tree_fuseki13(void)
{
  /* nothing to do - tree option not compiled */
}

struct fullboard_pattern fuseki13[] = {
  {fuseki130,0,"Fuseki1", 3,-3,799.000000},
  {fuseki131,0,"Fuseki2",-4, 3,534.000000},
  {fuseki132,0,"Fuseki3", 4, 4,144.000000},
  {fuseki133,0,"Fuseki4", 4, 2,28.000000},
  {fuseki134,0,"Fuseki5", 2, 3,27.000000},
  {fuseki135,0,"Fuseki6", 0, 0,21.000000},
  {fuseki136,0,"Fuseki7", 2,-2,15.000000},
  {fuseki137,1,"Fuseki8",-3, 3,174.000000},
  {fuseki138,1,"Fuseki9", 3, 4,138.000000},
  {fuseki139,1,"Fuseki10", 3, 3,95.000000},
  {fuseki1310,1,"Fuseki11", 4, 4,86.000000},
  {fuseki1311,1,"Fuseki12",-3,-4,79.000000},
  {fuseki1312,1,"Fuseki13",-4, 4,65.000000},
  {fuseki1313,1,"Fuseki14",-4, 1,33.000000},
  {fuseki1314,1,"Fuseki15", 3, 4,32.000000},
  {fuseki1315,1,"Fuseki16", 3,-2,11.000000},
  {fuseki1316,1,"Fuseki17",-4,-2,10.000000},
  {fuseki1317,1,"Fuseki18", 3,-3,95.000000},
  {fuseki1318,1,"Fuseki19", 4,-4,57.000000},
  {fuseki1319,1,"Fuseki20", 3, 3,54.000000},
  {fuseki1320,1,"Fuseki21",-3,-4,52.000000},
  {fuseki1321,1,"Fuseki22", 3, 4,48.000000},
  {fuseki1322,1,"Fuseki23", 4,-4,45.000000},
  {fuseki1323,1,"Fuseki24",-3, 4,38.000000},
  {fuseki1324,1,"Fuseki25", 3, 3,28.000000},
  {fuseki1325,1,"Fuseki26", 2, 4,16.000000},
  {fuseki1326,1,"Fuseki27",-3,-4,15.000000},
  {fuseki1327,1,"Fuseki28",-3,-4,13.000000},
  {fuseki1328,1,"Fuseki29", 2, 3,12.000000},
  {fuseki1329,1,"Fuseki30", 4, 3,10.000000},
  {fuseki1330,2,"Fuseki31", 3, 3,94.000000},
  {fuseki1331,2,"Fuseki32", 3, 4,21.000000},
  {fuseki1332,2,"Fuseki33",-3,-4,17.000000},
  {fuseki1333,2,"Fuseki34",-3, 2,10.000000},
  {fuseki1334,1,"Fuseki35", 4, 3,33.000000},
  {fuseki1335,1,"Fuseki36", 3, 3,29.000000},
  {fuseki1336,1,"Fuseki37", 4,-4,26.000000},
  {fuseki1337,1,"Fuseki38",-4, 4,16.000000},
  {fuseki1338,1,"Fuseki39",-3, 4,14.000000},
  {fuseki1339,1,"Fuseki40",-3, 3,7.000000},
  {fuseki1340,1,"Fuseki41", 3,-2,4.000000},
  {fuseki1341,1,"Fuseki42",-3, 3,4.000000},
  {fuseki1342,2,"Fuseki43", 3, 3,32.000000},
  {fuseki1343,2,"Fuseki44", 3, 3,22.000000},
  {fuseki1344,2,"Fuseki45", 3,-4,17.000000},
  {fuseki1345,2,"Fuseki46", 3,-4,16.000000},
  {fuseki1346,2,"Fuseki47", 4, 3,10.000000},
  {fuseki1347,2,"Fuseki48",-3,-2,6.000000},
  {fuseki1348,2,"Fuseki49",-3,-4,5.000000},
  {fuseki1349,2,"Fuseki50",-2, 3,4.000000},
  {fuseki1350,3,"Fuseki51",-3, 3,56.000000},
  {fuseki1351,3,"Fuseki52",-3,-4,26.000000},
  {fuseki1352,3,"Fuseki53",-4, 4,13.000000},
  {fuseki1353,3,"Fuseki54", 3, 2,8.000000},
  {fuseki1354,3,"Fuseki55", 4,-3,8.000000},
  {fuseki1355,2,"Fuseki56",-3,-3,35.000000},
  {fuseki1356,2,"Fuseki57", 3,-3,20.000000},
  {fuseki1357,2,"Fuseki58",-3, 4,7.000000},
  {fuseki1358,2,"Fuseki59", 3,-4,4.000000},
  {fuseki1359,2,"Fuseki60",-2,-3,4.000000},
  {fuseki1360,2,"Fuseki61",-3,-4,47.000000},
  {fuseki1361,2,"Fuseki62", 3, 3,10.000000},
  {fuseki1362,2,"Fuseki63", 3,-4,8.000000},
  {fuseki1363,2,"Fuseki64",-4,-3,7.000000},
  {fuseki1364,2,"Fuseki65", 4,-2,6.000000},
  {fuseki1365,2,"Fuseki66", 3,-3,5.000000},
  {fuseki1366,2,"Fuseki67", 3, 3,23.000000},
  {fuseki1367,2,"Fuseki68", 3,-4,16.000000},
  {fuseki1368,2,"Fuseki69",-3, 3,11.000000},
  {fuseki1369,2,"Fuseki70",-3,-4,10.000000},
  {fuseki1370,2,"Fuseki71",-4,-3,5.000000},
  {fuseki1371,2,"Fuseki72", 3, 4,4.000000},
  {fuseki1372,2,"Fuseki73",-4, 4,4.000000},
  {fuseki1373,2,"Fuseki74", 3, 3,4.000000},
  {fuseki1374,2,"Fuseki75",-3,-2,3.000000},
  {fuseki1375,2,"Fuseki76",-3, 3,24.000000},
  {fuseki1376,2,"Fuseki77", 3,-3,13.000000},
  {fuseki1377,2,"Fuseki78", 4, 3,8.000000},
  {fuseki1378,2,"Fuseki79",-4,-3,6.000000},
  {fuseki1379,2,"Fuseki80",-4, 3,5.000000},
  {fuseki1380,2,"Fuseki81", 3, 2,3.000000},
  {fuseki1381,2,"Fuseki82",-3,-3,21.000000},
  {fuseki1382,2,"Fuseki83", 3, 4,18.000000},
  {fuseki1383,2,"Fuseki84",-4,-4,9.000000},
  {fuseki1384,2,"Fuseki85",-3,-4,6.000000},
  {fuseki1385,3,"Fuseki86",-3,-3,19.000000},
  {fuseki1386,3,"Fuseki87",-3,-4,12.000000},
  {fuseki1387,3,"Fuseki88", 4,-3,7.000000},
  {fuseki1388,3,"Fuseki89",-3,-2,5.000000},
  {fuseki1389,3,"Fuseki90", 2, 3,4.000000},
  {fuseki1390,3,"Fuseki91", 4,-4,4.000000},
  {fuseki1391,3,"Fuseki92",-2,-4,3.000000},
  {fuseki1392,3,"Fuseki93", 2,-4,3.000000},
  {fuseki1393,3,"Fuseki94",-4,-3,2.000000},
  {fuseki1394,2,"Fuseki95", 4,-3,16.000000},
  {fuseki1395,2,"Fuseki96", 3, 3,8.000000},
  {fuseki1396,2,"Fuseki97", 3,-4,7.000000},
  {fuseki1397,2,"Fuseki98", 3,-4,6.000000},
  {fuseki1398,2,"Fuseki99", 2,-4,5.000000},
  {fuseki1399,2,"Fuseki100",-4,-4,5.000000},
  {fuseki13100,2,"Fuseki101", 3, 3,3.000000},
  {fuseki13101,2,"Fuseki102",-4, 2,2.000000},
  {fuseki13102,4,"Fuseki103",-4, 1,23.000000},
  {fuseki13103,4,"Fuseki104", 4, 0,6.000000},
  {fuseki13104,4,"Fuseki105", 3, 0,5.000000},
  {fuseki13105,4,"Fuseki106", 0, 3,5.000000},
  {fuseki13106,4,"Fuseki107", 3, 0,4.000000},
  {fuseki13107,3,"Fuseki108",-4,-4,22.000000},
  {fuseki13108,3,"Fuseki109",-3,-4,14.000000},
  {fuseki13109,3,"Fuseki110",-3,-3,9.000000},
  {fuseki13110,3,"Fuseki111",-3,-4,7.000000},
  {fuseki13111,2,"Fuseki112", 4, 3,20.000000},
  {fuseki13112,2,"Fuseki113",-3,-3,6.000000},
  {fuseki13113,2,"Fuseki114",-4, 2,5.000000},
  {fuseki13114,2,"Fuseki115",-3,-4,5.000000},
  {fuseki13115,2,"Fuseki116",-3,-4,4.000000},
  {fuseki13116,2,"Fuseki117", 3,-3,3.000000},
  {fuseki13117,2,"Fuseki118", 4,-2,3.000000},
  {fuseki13118,2,"Fuseki119",-4,-4,2.000000},
  {fuseki13119,2,"Fuseki120", 4, 4,2.000000},
  {fuseki13120,2,"Fuseki121", 3,-4,14.000000},
  {fuseki13121,2,"Fuseki122", 4,-3,10.000000},
  {fuseki13122,2,"Fuseki123",-3, 3,9.000000},
  {fuseki13123,2,"Fuseki124",-3, 3,6.000000},
  {fuseki13124,2,"Fuseki125", 4,-4,5.000000},
  {fuseki13125,2,"Fuseki126",-3,-4,2.000000},
  {fuseki13126,2,"Fuseki127", 4,-3,2.000000},
  {fuseki13127,2,"Fuseki128",-2,-4,2.000000},
  {fuseki13128,2,"Fuseki129", 3,-4,18.000000},
  {fuseki13129,2,"Fuseki130",-4,-3,7.000000},
  {fuseki13130,2,"Fuseki131",-4, 3,5.000000},
  {fuseki13131,2,"Fuseki132", 3, 3,4.000000},
  {fuseki13132,2,"Fuseki133",-4,-3,3.000000},
  {fuseki13133,2,"Fuseki134", 4,-4,3.000000},
  {fuseki13134,2,"Fuseki135",-2,-3,2.000000},
  {fuseki13135,2,"Fuseki136",-3, 3,2.000000},
  {fuseki13136,2,"Fuseki137", 4, 3,13.000000},
  {fuseki13137,2,"Fuseki138", 3, 4,10.000000},
  {fuseki13138,2,"Fuseki139", 3, 3,6.000000},
  {fuseki13139,2,"Fuseki140", 3,-3,3.000000},
  {fuseki13140,2,"Fuseki141", 4, 3,2.000000},
  {fuseki13141,2,"Fuseki142", 3,-4,2.000000},
  {fuseki13142,2,"Fuseki143",-4,-2,2.000000},
  {fuseki13143,2,"Fuseki144",-2,-3,2.000000},
  {fuseki13144,3,"Fuseki145", 4, 4,24.000000},
  {fuseki13145,3,"Fuseki146",-2,-4,9.000000},
  {fuseki13146,3,"Fuseki147", 3, 4,4.000000},
  {fuseki13147,3,"Fuseki148",-3, 3,4.000000},
  {fuseki13148,2,"Fuseki149", 4,-3,15.000000},
  {fuseki13149,2,"Fuseki150", 3, 3,6.000000},
  {fuseki13150,2,"Fuseki151", 4,-3,5.000000},
  {fuseki13151,2,"Fuseki152",-3,-3,3.000000},
  {fuseki13152,4,"Fuseki153",-4,-1,7.000000},
  {fuseki13153,4,"Fuseki154", 3, 0,5.000000},
  {fuseki13154,4,"Fuseki155",-1,-3,3.000000},
  {fuseki13155,4,"Fuseki156", 0, 3,3.000000},
  {fuseki13156,4,"Fuseki157",-4,-1,2.000000},
  {fuseki13157,4,"Fuseki158", 0,-3,2.000000},
  {fuseki13158,4,"Fuseki159",-1,-4,2.000000},
  {fuseki13159,4,"Fuseki160", 4, 0,2.000000},
  {fuseki13160,4,"Fuseki161", 4, 3,1.000000},
  {fuseki13161,4,"Fuseki162", 2, 4,1.000000},
  {fuseki13162,4,"Fuseki163",-2, 4,1.000000},
  {fuseki13163,4,"Fuseki164",-4, 0,1.000000},
  {fuseki13164,4,"Fuseki165", 4, 0,1.000000},
  {fuseki13165,4,"Fuseki166", 1,-3,1.000000},
  {fuseki13166,4,"Fuseki167",-2,-3,1.000000},
  {fuseki13167,4,"Fuseki168",-3,-1,1.000000},
  {fuseki13168,4,"Fuseki169", 4, 4,1.000000},
  {fuseki13169,2,"Fuseki170",-4, 4,16.000000},
  {fuseki13170,2,"Fuseki171", 3,-3,6.000000},
  {fuseki13171,2,"Fuseki172",-3, 4,5.000000},
  {fuseki13172,2,"Fuseki173",-4, 3,3.000000},
  {fuseki13173,2,"Fuseki174",-2,-4,2.000000},
  {fuseki13174,2,"Fuseki175", 3, 1,14.000000},
  {fuseki13175,2,"Fuseki176", 1, 3,6.000000},
  {fuseki13176,2,"Fuseki177", 1,-4,3.000000},
  {fuseki13177,2,"Fuseki178", 2,-4,3.000000},
  {fuseki13178,2,"Fuseki179", 3, 3,2.000000},
  {fuseki13179,2,"Fuseki180", 3,-3,2.000000},
  {fuseki13180,2,"Fuseki181",-3,-3,8.000000},
  {fuseki13181,2,"Fuseki182",-3,-3,6.000000},
  {fuseki13182,2,"Fuseki183", 3, 4,4.000000},
  {fuseki13183,2,"Fuseki184", 4,-3,4.000000},
  {fuseki13184,2,"Fuseki185",-3,-2,2.000000},
  {fuseki13185,2,"Fuseki186",-2,-4,1.000000},
  {fuseki13186,2,"Fuseki187", 4,-4,1.000000},
  {fuseki13187,2,"Fuseki188", 2,-3,1.000000},
  {fuseki13188,2,"Fuseki189", 4, 2,1.000000},
  {fuseki13189,2,"Fuseki190",-3, 3,1.000000},
  {fuseki13190,2,"Fuseki191",-4, 3,1.000000},
  {fuseki13191,2,"Fuseki192",-2, 4,1.000000},
  {fuseki13192,2,"Fuseki193", 3, 4,1.000000},
  {fuseki13193,3,"Fuseki194",-4,-4,14.000000},
  {fuseki13194,3,"Fuseki195",-3,-4,7.000000},
  {fuseki13195,3,"Fuseki196",-3,-3,4.000000},
  {fuseki13196,3,"Fuseki197",-3, 4,3.000000},
  {fuseki13197,3,"Fuseki198",-3, 2,2.000000},
  {fuseki13198,2,"Fuseki199",-4, 4,20.000000},
  {fuseki13199,2,"Fuseki200", 4,-3,4.000000},
  {fuseki13200,2,"Fuseki201",-4, 3,3.000000},
  {fuseki13201,3,"Fuseki202",-4, 4,22.000000},
  {fuseki13202,3,"Fuseki203", 3,-4,3.000000},
  {fuseki13203,4,"Fuseki204",-2, 4,16.000000},
  {fuseki13204,4,"Fuseki205", 1, 4,6.000000},
  {fuseki13205,4,"Fuseki206", 1, 4,2.000000},
  {fuseki13206,2,"Fuseki207",-4,-3,17.000000},
  {fuseki13207,2,"Fuseki208",-3, 3,4.000000},
  {fuseki13208,2,"Fuseki209", 3,-4,3.000000},
  {fuseki13209,1,"Fuseki210", 2, 3,5.000000},
  {fuseki13210,1,"Fuseki211", 3, 3,4.000000},
  {fuseki13211,1,"Fuseki212",-4,-3,4.000000},
  {fuseki13212,1,"Fuseki213", 4, 4,3.000000},
  {fuseki13213,1,"Fuseki214", 3, 3,3.000000},
  {fuseki13214,1,"Fuseki215",-4,-3,3.000000},
  {fuseki13215,1,"Fuseki217",-4, 3,2.000000},
  {fuseki13216,1,"Fuseki218",-2, 3,1.000000},
  {fuseki13217,3,"Fuseki219", 3,-3,10.000000},
  {fuseki13218,3,"Fuseki220", 4,-2,4.000000},
  {fuseki13219,3,"Fuseki221", 3,-4,4.000000},
  {fuseki13220,3,"Fuseki222", 4,-4,3.000000},
  {fuseki13221,3,"Fuseki223",-4,-3,2.000000},
  {fuseki13222,3,"Fuseki224", 2,-3,1.000000},
  {fuseki13223,3,"Fuseki225", 3,-2,1.000000},
  {fuseki13224,3,"Fuseki226",-3,-2,1.000000},
  {fuseki13225,3,"Fuseki227", 2, 4,1.000000},
  {fuseki13226,3,"Fuseki228",-3,-3,1.000000},
  {fuseki13227,3,"Fuseki229",-4,-4,8.000000},
  {fuseki13228,3,"Fuseki230", 4,-3,8.000000},
  {fuseki13229,3,"Fuseki231",-2, 4,3.000000},
  {fuseki13230,3,"Fuseki232", 3,-3,3.000000},
  {fuseki13231,3,"Fuseki233",-2, 4,2.000000},
  {fuseki13232,3,"Fuseki234",-2, 3,1.000000},
  {fuseki13233,3,"Fuseki235", 4,-3,1.000000},
  {fuseki13234,3,"Fuseki236", 4,-2,1.000000},
  {fuseki13235,1,"Fuseki237",-4,-4,14.000000},
  {fuseki13236,1,"Fuseki238",-4,-4,3.000000},
  {fuseki13237,1,"Fuseki239", 3,-3,2.000000},
  {fuseki13238,4,"Fuseki240", 2,-4,6.000000},
  {fuseki13239,4,"Fuseki241", 0, 4,2.000000},
  {fuseki13240,4,"Fuseki242", 0,-3,2.000000},
  {fuseki13241,4,"Fuseki243", 4, 1,2.000000},
  {fuseki13242,4,"Fuseki244", 4, 0,2.000000},
  {fuseki13243,4,"Fuseki245", 0,-3,2.000000},
  {fuseki13244,4,"Fuseki246",-2, 0,1.000000},
  {fuseki13245,4,"Fuseki247", 0,-4,1.000000},
  {fuseki13246,4,"Fuseki248", 2,-3,1.000000},
  {fuseki13247,4,"Fuseki249", 4, 0,1.000000},
  {fuseki13248,4,"Fuseki250",-4,-1,1.000000},
  {fuseki13249,4,"Fuseki251", 4, 1,1.000000},
  {fuseki13250,4,"Fuseki252", 3,-3,1.000000},
  {fuseki13251,4,"Fuseki253",-3, 0,1.000000},
  {fuseki13252,4,"Fuseki254",-2,-4,1.000000},
  {fuseki13253,2,"Fuseki255", 4,-4,21.000000},
  {fuseki13254,3,"Fuseki256",-3,-3,9.000000},
  {fuseki13255,3,"Fuseki257",-2, 3,4.000000},
  {fuseki13256,3,"Fuseki258",-4,-2,4.000000},
  {fuseki13257,3,"Fuseki259",-4,-3,3.000000},
  {fuseki13258,3,"Fuseki260",-2,-3,1.000000},
  {fuseki13259,3,"Fuseki261",-3, 4,1.000000},
  {fuseki13260,3,"Fuseki262",-1, 3,1.000000},
  {fuseki13261,3,"Fuseki263",-4,-4,1.000000},
  {fuseki13262,3,"Fuseki264",-4,-2,1.000000},
  {fuseki13263,3,"Fuseki265",-4, 3,6.000000},
  {fuseki13264,3,"Fuseki266", 3, 3,5.000000},
  {fuseki13265,3,"Fuseki267", 4,-4,5.000000},
  {fuseki13266,3,"Fuseki268",-4, 3,4.000000},
  {fuseki13267,3,"Fuseki269",-2, 4,3.000000},
  {fuseki13268,3,"Fuseki270",-3,-2,1.000000},
  {fuseki13269,3,"Fuseki271",-2, 3,1.000000},
  {fuseki13270,4,"Fuseki272", 0,-4,4.000000},
  {fuseki13271,4,"Fuseki273",-3, 3,4.000000},
  {fuseki13272,4,"Fuseki274", 0, 4,3.000000},
  {fuseki13273,4,"Fuseki275", 4,-1,3.000000},
  {fuseki13274,4,"Fuseki276", 0,-3,2.000000},
  {fuseki13275,4,"Fuseki277", 0,-4,1.000000},
  {fuseki13276,4,"Fuseki278",-2,-4,1.000000},
  {fuseki13277,4,"Fuseki279", 4, 1,1.000000},
  {fuseki13278,4,"Fuseki280", 4,-3,1.000000},
  {fuseki13279,4,"Fuseki281",-2,-3,1.000000},
  {fuseki13280,4,"Fuseki282", 3,-1,1.000000},
  {fuseki13281,4,"Fuseki283",-1,-4,1.000000},
  {fuseki13282,4,"Fuseki284", 3,-4,1.000000},
  {fuseki13283,4,"Fuseki285", 1, 4,4.000000},
  {fuseki13284,4,"Fuseki286", 4, 2,4.000000},
  {fuseki13285,4,"Fuseki287", 0,-3,4.000000},
  {fuseki13286,4,"Fuseki288",-3, 2,2.000000},
  {fuseki13287,4,"Fuseki289", 1, 3,2.000000},
  {fuseki13288,4,"Fuseki290", 1, 4,1.000000},
  {fuseki13289,4,"Fuseki291", 0, 4,1.000000},
  {fuseki13290,4,"Fuseki292", 0, 0,1.000000},
  {fuseki13291,4,"Fuseki293",-4, 0,1.000000},
  {fuseki13292,4,"Fuseki294",-3, 2,1.000000},
  {fuseki13293,4,"Fuseki295", 3, 3,1.000000},
  {fuseki13294,4,"Fuseki296",-4,-1,1.000000},
  {fuseki13295,4,"Fuseki297",-1, 4,1.000000},
  {fuseki13296,3,"Fuseki298",-3,-3,7.000000},
  {fuseki13297,3,"Fuseki299",-4,-3,6.000000},
  {fuseki13298,3,"Fuseki300", 4, 3,5.000000},
  {fuseki13299,3,"Fuseki301", 4,-4,3.000000},
  {fuseki13300,3,"Fuseki302", 2, 3,1.000000},
  {fuseki13301,3,"Fuseki303", 2, 4,1.000000},
  {fuseki13302,3,"Fuseki304",-3,-3,1.000000},
  {fuseki13303,5,"Fuseki305",-3, 1,4.000000},
  {fuseki13304,5,"Fuseki306", 3, 1,4.000000},
  {fuseki13305,5,"Fuseki307",-4, 2,4.000000},
  {fuseki13306,5,"Fuseki308", 0, 3,2.000000},
  {fuseki13307,5,"Fuseki309",-3, 4,2.000000},
  {fuseki13308,5,"Fuseki310", 0,-3,1.000000},
  {fuseki13309,5,"Fuseki311", 1,-4,1.000000},
  {fuseki13310,5,"Fuseki312", 4, 4,1.000000},
  {fuseki13311,5,"Fuseki313",-3, 0,1.000000},
  {fuseki13312,5,"Fuseki314",-4, 4,1.000000},
  {fuseki13313,5,"Fuseki315",-1, 4,1.000000},
  {fuseki13314,5,"Fuseki316", 1, 2,1.000000},
  {fuseki13315,3,"Fuseki317",-3, 3,7.000000},
  {fuseki13316,3,"Fuseki318",-4,-3,5.000000},
  {fuseki13317,3,"Fuseki319", 2, 4,4.000000},
  {fuseki13318,3,"Fuseki320",-4,-4,2.000000},
  {fuseki13319,3,"Fuseki321",-2,-4,2.000000},
  {fuseki13320,3,"Fuseki322",-2,-4,1.000000},
  {fuseki13321,3,"Fuseki323",-3,-2,1.000000},
  {fuseki13322,3,"Fuseki324",-2, 3,1.000000},
  {fuseki13323,4,"Fuseki325", 0,-4,7.000000},
  {fuseki13324,4,"Fuseki326",-3, 1,5.000000},
  {fuseki13325,4,"Fuseki327", 4,-2,3.000000},
  {fuseki13326,4,"Fuseki328",-4, 1,2.000000},
  {fuseki13327,4,"Fuseki329", 3,-1,1.000000},
  {fuseki13328,4,"Fuseki330",-3, 3,1.000000},
  {fuseki13329,4,"Fuseki331",-2, 3,1.000000},
  {fuseki13330,4,"Fuseki332", 1, 2,1.000000},
  {fuseki13331,4,"Fuseki333", 0, 4,1.000000},
  {fuseki13332,1,"Fuseki334", 3, 3,8.000000},
  {fuseki13333,1,"Fuseki335", 4,-3,5.000000},
  {fuseki13334,1,"Fuseki336", 4,-4,5.000000},
  {fuseki13335,1,"Fuseki337", 4, 2,1.000000},
  {fuseki13336,1,"Fuseki338",-1, 0,1.000000},
  {fuseki13337,1,"Fuseki339", 1, 1,1.000000},
  {fuseki13338,4,"Fuseki340",-4,-2,7.000000},
  {fuseki13339,4,"Fuseki341", 4,-1,2.000000},
  {fuseki13340,4,"Fuseki342", 3, 0,2.000000},
  {fuseki13341,4,"Fuseki343", 0,-4,2.000000},
  {fuseki13342,4,"Fuseki344",-4,-2,2.000000},
  {fuseki13343,4,"Fuseki345", 0, 4,1.000000},
  {fuseki13344,4,"Fuseki346",-1, 4,1.000000},
  {fuseki13345,4,"Fuseki347", 4, 3,1.000000},
  {fuseki13346,4,"Fuseki348", 2,-4,1.000000},
  {fuseki13347,4,"Fuseki349",-3, 2,1.000000},
  {fuseki13348,4,"Fuseki350",-2, 3,1.000000},
  {fuseki13349,3,"Fuseki351", 4, 4,9.000000},
  {fuseki13350,3,"Fuseki352",-3, 3,5.000000},
  {fuseki13351,3,"Fuseki353",-3, 4,2.000000},
  {fuseki13352,3,"Fuseki354",-3, 2,1.000000},
  {fuseki13353,3,"Fuseki355",-4, 3,1.000000},
  {fuseki13354,3,"Fuseki356", 2,-2,1.000000},
  {fuseki13355,3,"Fuseki357", 2,-4,1.000000},
  {fuseki13356,3,"Fuseki358", 3, 3,14.000000},
  {fuseki13357,3,"Fuseki359", 4,-3,2.000000},
  {fuseki13358,3,"Fuseki360",-4,-4,2.000000},
  {fuseki13359,3,"Fuseki361",-2,-4,8.000000},
  {fuseki13360,3,"Fuseki362",-3,-3,4.000000},
  {fuseki13361,3,"Fuseki363",-4,-3,3.000000},
  {fuseki13362,3,"Fuseki364",-3,-4,2.000000},
  {fuseki13363,3,"Fuseki365",-4, 4,2.000000},
  {fuseki13364,3,"Fuseki366",-2,-3,1.000000},
  {fuseki13365,3,"Fuseki367", 4, 4,15.000000},
  {fuseki13366,3,"Fuseki368",-2, 4,2.000000},
  {fuseki13367,3,"Fuseki369",-4,-3,2.000000},
  {fuseki13368,3,"Fuseki370",-4,-4,6.000000},
  {fuseki13369,3,"Fuseki371", 4, 3,4.000000},
  {fuseki13370,3,"Fuseki372", 4, 3,4.000000},
  {fuseki13371,3,"Fuseki373", 3,-3,3.000000},
  {fuseki13372,3,"Fuseki374", 4, 1,1.000000},
  {fuseki13373,3,"Fuseki375", 4, 1,1.000000},
  {fuseki13374,3,"Fuseki376", 4, 4,11.000000},
  {fuseki13375,3,"Fuseki377",-3, 4,2.000000},
  {fuseki13376,3,"Fuseki378", 5,-1,2.000000},
  {fuseki13377,3,"Fuseki379",-4,-3,7.000000},
  {fuseki13378,3,"Fuseki380",-4,-4,5.000000},
  {fuseki13379,3,"Fuseki381",-3, 3,3.000000},
  {fuseki13380,3,"Fuseki382", 1, 3,1.000000},
  {fuseki13381,3,"Fuseki383", 4, 2,1.000000},
  {fuseki13382,3,"Fuseki384",-4,-2,1.000000},
  {fuseki13383,4,"Fuseki385",-4,-2,9.000000},
  {fuseki13384,4,"Fuseki386", 1, 4,2.000000},
  {fuseki13385,4,"Fuseki387", 4,-2,1.000000},
  {fuseki13386,4,"Fuseki388",-3,-2,1.000000},
  {fuseki13387,4,"Fuseki389", 0,-4,1.000000},
  {fuseki13388,4,"Fuseki390", 4,-1,1.000000},
  {fuseki13389,4,"Fuseki391", 4,-4,1.000000},
  {fuseki13390,4,"Fuseki392",-1,-4,1.000000},
  {fuseki13391,3,"Fuseki393",-3,-3,5.000000},
  {fuseki13392,3,"Fuseki394",-3,-4,3.000000},
  {fuseki13393,3,"Fuseki395",-3, 4,3.000000},
  {fuseki13394,3,"Fuseki396",-2,-4,2.000000},
  {fuseki13395,3,"Fuseki397",-3,-2,1.000000},
  {fuseki13396,3,"Fuseki398", 2,-3,1.000000},
  {fuseki13397,3,"Fuseki399",-2, 3,1.000000},
  {fuseki13398,3,"Fuseki400", 3, 0,1.000000},
  {fuseki13399,3,"Fuseki401",-4,-4,10.000000},
  {fuseki13400,3,"Fuseki402", 4,-3,3.000000},
  {fuseki13401,3,"Fuseki403",-3, 3,2.000000},
  {fuseki13402,3,"Fuseki404", 4, 3,1.000000},
  {fuseki13403,3,"Fuseki405", 4, 2,1.000000},
  {fuseki13404,4,"Fuseki406",-3,-3,2.000000},
  {fuseki13405,4,"Fuseki407",-4,-1,2.000000},
  {fuseki13406,4,"Fuseki408", 4,-1,2.000000},
  {fuseki13407,4,"Fuseki409", 4,-1,2.000000},
  {fuseki13408,4,"Fuseki410", 3, 0,2.000000},
  {fuseki13409,4,"Fuseki411", 2,-4,1.000000},
  {fuseki13410,4,"Fuseki412",-1, 0,1.000000},
  {fuseki13411,4,"Fuseki413",-3,-2,1.000000},
  {fuseki13412,4,"Fuseki414", 4,-1,1.000000},
  {fuseki13413,4,"Fuseki415", 4, 0,1.000000},
  {fuseki13414,4,"Fuseki416", 0,-3,1.000000},
  {fuseki13415,4,"Fuseki417", 0,-4,1.000000},
  {fuseki13416,2,"Fuseki418",-4,-3,10.000000},
  {fuseki13417,2,"Fuseki419",-3, 4,1.000000},
  {fuseki13418,2,"Fuseki420",-4, 2,1.000000},
  {fuseki13419,2,"Fuseki421", 3,-4,1.000000},
  {fuseki13420,2,"Fuseki422", 3, 1,1.000000},
  {fuseki13421,2,"Fuseki423",-4,-4,1.000000},
  {fuseki13422,2,"Fuseki424",-4,-1,1.000000},
  {fuseki13423,3,"Fuseki425", 4,-4,6.000000},
  {fuseki13424,3,"Fuseki426",-2,-4,5.000000},
  {fuseki13425,3,"Fuseki427", 3,-4,2.000000},
  {fuseki13426,3,"Fuseki428",-3,-2,1.000000},
  {fuseki13427,3,"Fuseki429",-4,-3,1.000000},
  {fuseki13428,3,"Fuseki430", 3,-3,1.000000},
  {fuseki13429,2,"Fuseki431", 4,-4,8.000000},
  {fuseki13430,2,"Fuseki432",-4,-4,3.000000},
  {fuseki13431,2,"Fuseki433",-4, 3,2.000000},
  {fuseki13432,2,"Fuseki434", 4,-3,1.000000},
  {fuseki13433,2,"Fuseki435", 3,-2,1.000000},
  {fuseki13434,2,"Fuseki436",-3,-3,1.000000},
  {fuseki13435,4,"Fuseki437", 4,-2,2.000000},
  {fuseki13436,4,"Fuseki438", 4,-2,2.000000},
  {fuseki13437,4,"Fuseki439",-3,-2,1.000000},
  {fuseki13438,4,"Fuseki440",-4,-1,1.000000},
  {fuseki13439,4,"Fuseki441", 2,-1,1.000000},
  {fuseki13440,4,"Fuseki442", 4, 0,1.000000},
  {fuseki13441,4,"Fuseki443", 4, 0,1.000000},
  {fuseki13442,4,"Fuseki444", 3,-2,1.000000},
  {fuseki13443,4,"Fuseki445", 2,-4,1.000000},
  {fuseki13444,4,"Fuseki446", 0,-3,1.000000},
  {fuseki13445,4,"Fuseki447",-4, 0,1.000000},
  {fuseki13446,4,"Fuseki448", 0, 3,1.000000},
  {fuseki13447,4,"Fuseki449", 3, 5,1.000000},
  {fuseki13448,4,"Fuseki450", 4,-1,1.000000},
  {fuseki13449,3,"Fuseki451", 3,-4,8.000000},
  {fuseki13450,3,"Fuseki452",-4,-4,3.000000},
  {fuseki13451,3,"Fuseki453", 4, 3,2.000000},
  {fuseki13452,3,"Fuseki454", 4,-1,1.000000},
  {fuseki13453,3,"Fuseki455", 3, 3,1.000000},
  {fuseki13454,3,"Fuseki456",-1,-4,1.000000},
  {fuseki13455,5,"Fuseki457",-3,-2,4.000000},
  {fuseki13456,5,"Fuseki458",-4,-2,4.000000},
  {fuseki13457,5,"Fuseki459", 0, 4,4.000000},
  {fuseki13458,5,"Fuseki460",-1,-3,1.000000},
  {fuseki13459,5,"Fuseki461", 3, 0,1.000000},
  {fuseki13460,5,"Fuseki462",-1,-4,1.000000},
  {fuseki13461,5,"Fuseki463",-3,-1,1.000000},
  {fuseki13462,3,"Fuseki464", 4,-2,7.000000},
  {fuseki13463,3,"Fuseki465",-4, 4,3.000000},
  {fuseki13464,3,"Fuseki466", 3, 2,2.000000},
  {fuseki13465,3,"Fuseki467",-3,-3,1.000000},
  {fuseki13466,3,"Fuseki468", 3, 4,1.000000},
  {fuseki13467,3,"Fuseki469", 3, 4,1.000000},
  {fuseki13468,2,"Fuseki470", 4, 3,9.000000},
  {fuseki13469,2,"Fuseki471", 4, 3,3.000000},
  {fuseki13470,2,"Fuseki472",-3,-4,1.000000},
  {fuseki13471,2,"Fuseki473", 2, 3,1.000000},
  {fuseki13472,2,"Fuseki474", 4, 2,1.000000},
  {fuseki13473,1,"Fuseki475", 3, 3,8.000000},
  {fuseki13474,1,"Fuseki476",-4, 4,2.000000},
  {fuseki13475,1,"Fuseki477", 3, 4,1.000000},
  {fuseki13476,1,"Fuseki478", 3,-3,1.000000},
  {fuseki13477,1,"Fuseki479",-3, 4,1.000000},
  {fuseki13478,1,"Fuseki480",-3, 2,1.000000},
  {fuseki13479,1,"Fuseki481", 3,-4,1.000000},
  {fuseki13480,4,"Fuseki482",-2,-4,4.000000},
  {fuseki13481,4,"Fuseki483", 2, 4,2.000000},
  {fuseki13482,4,"Fuseki484", 0, 3,2.000000},
  {fuseki13483,4,"Fuseki485", 0, 4,1.000000},
  {fuseki13484,4,"Fuseki486",-3,-3,1.000000},
  {fuseki13485,4,"Fuseki487",-4,-2,1.000000},
  {fuseki13486,4,"Fuseki488",-4,-1,1.000000},
  {fuseki13487,4,"Fuseki489",-2, 3,1.000000},
  {fuseki13488,4,"Fuseki490",-2,-3,1.000000},
  {fuseki13489,2,"Fuseki491", 3, 4,3.000000},
  {fuseki13490,2,"Fuseki492",-3, 3,2.000000},
  {fuseki13491,2,"Fuseki493", 3,-3,2.000000},
  {fuseki13492,2,"Fuseki494", 0, 0,1.000000},
  {fuseki13493,2,"Fuseki495", 2, 3,1.000000},
  {fuseki13494,2,"Fuseki496", 2, 2,1.000000},
  {fuseki13495,2,"Fuseki497", 4,-3,1.000000},
  {fuseki13496,2,"Fuseki498", 2, 4,1.000000},
  {fuseki13497,2,"Fuseki499", 4,-4,1.000000},
  {fuseki13498,2,"Fuseki500",-2, 3,1.000000},
  {fuseki13499,3,"Fuseki501", 3, 2,10.000000},
  {fuseki13500,3,"Fuseki502", 3, 0,4.000000},
  {fuseki13501,2,"Fuseki503",-4,-4,5.000000},
  {fuseki13502,2,"Fuseki504",-4,-4,3.000000},
  {fuseki13503,2,"Fuseki505", 4, 3,2.000000},
  {fuseki13504,2,"Fuseki506", 3, 4,2.000000},
  {fuseki13505,2,"Fuseki507", 3,-2,1.000000},
  {fuseki13506,2,"Fuseki508", 3,-3,1.000000},
  {fuseki13507,3,"Fuseki509",-4,-4,9.000000},
  {fuseki13508,3,"Fuseki510",-3, 4,2.000000},
  {fuseki13509,3,"Fuseki511", 4, 2,2.000000},
  {fuseki13510,3,"Fuseki512",-3, 3,1.000000},
  {fuseki13511,4,"Fuseki513",-1, 4,5.000000},
  {fuseki13512,4,"Fuseki514", 1,-4,2.000000},
  {fuseki13513,4,"Fuseki515", 0, 0,2.000000},
  {fuseki13514,4,"Fuseki516",-4, 2,1.000000},
  {fuseki13515,4,"Fuseki517", 0, 3,1.000000},
  {fuseki13516,4,"Fuseki518", 1, 0,1.000000},
  {fuseki13517,4,"Fuseki519", 0, 4,1.000000},
  {fuseki13518,4,"Fuseki520", 2, 0,1.000000},
  {fuseki13519,2,"Fuseki521", 3, 3,4.000000},
  {fuseki13520,2,"Fuseki522", 4,-3,2.000000},
  {fuseki13521,2,"Fuseki523",-4,-3,2.000000},
  {fuseki13522,2,"Fuseki524", 2,-3,1.000000},
  {fuseki13523,2,"Fuseki525", 2,-2,1.000000},
  {fuseki13524,2,"Fuseki526",-3,-4,1.000000},
  {fuseki13525,2,"Fuseki527",-4, 4,1.000000},
  {fuseki13526,2,"Fuseki528",-4, 1,1.000000},
  {fuseki13527,4,"Fuseki529", 4,-2,7.000000},
  {fuseki13528,4,"Fuseki530", 3,-2,1.000000},
  {fuseki13529,4,"Fuseki531",-3, 3,1.000000},
  {fuseki13530,4,"Fuseki532",-3,-2,1.000000},
  {fuseki13531,4,"Fuseki533",-4, 0,1.000000},
  {fuseki13532,4,"Fuseki534",-1, 4,1.000000},
  {fuseki13533,4,"Fuseki535",-2, 4,2.000000},
  {fuseki13534,4,"Fuseki536", 3, 0,1.000000},
  {fuseki13535,4,"Fuseki537", 0, 0,1.000000},
  {fuseki13536,4,"Fuseki538",-1,-4,1.000000},
  {fuseki13537,4,"Fuseki539", 4, 0,1.000000},
  {fuseki13538,4,"Fuseki540", 4, 0,1.000000},
  {fuseki13539,4,"Fuseki541",-4,-1,1.000000},
  {fuseki13540,4,"Fuseki542", 0, 3,1.000000},
  {fuseki13541,4,"Fuseki543", 3, 1,1.000000},
  {fuseki13542,4,"Fuseki544", 3,-3,1.000000},
  {fuseki13543,4,"Fuseki545", 3,-2,1.000000},
  {fuseki13544,4,"Fuseki546",-1, 4,3.000000},
  {fuseki13545,4,"Fuseki547", 4,-2,2.000000},
  {fuseki13546,4,"Fuseki548", 3, 1,1.000000},
  {fuseki13547,4,"Fuseki549",-4,-1,1.000000},
  {fuseki13548,4,"Fuseki550",-4,-1,1.000000},
  {fuseki13549,4,"Fuseki551", 2, 3,1.000000},
  {fuseki13550,4,"Fuseki552", 0, 3,1.000000},
  {fuseki13551,4,"Fuseki553", 0,-3,1.000000},
  {fuseki13552,4,"Fuseki554", 4, 1,1.000000},
  {fuseki13553,3,"Fuseki555",-3, 3,5.000000},
  {fuseki13554,3,"Fuseki556", 4, 4,3.000000},
  {fuseki13555,3,"Fuseki557",-3,-2,1.000000},
  {fuseki13556,3,"Fuseki558",-4,-3,1.000000},
  {fuseki13557,3,"Fuseki559", 4, 4,1.000000},
  {fuseki13558,2,"Fuseki560",-4,-4,4.000000},
  {fuseki13559,2,"Fuseki561",-4,-3,4.000000},
  {fuseki13560,2,"Fuseki562",-3,-1,1.000000},
  {fuseki13561,2,"Fuseki563",-3, 0,1.000000},
  {fuseki13562,2,"Fuseki564", 3,-3,1.000000},
  {fuseki13563,2,"Fuseki565", 3,-4,1.000000},
  {fuseki13564,3,"Fuseki566",-4,-4,2.000000},
  {fuseki13565,3,"Fuseki567", 3, 4,2.000000},
  {fuseki13566,3,"Fuseki568",-3, 3,2.000000},
  {fuseki13567,3,"Fuseki569",-4,-2,2.000000},
  {fuseki13568,3,"Fuseki570",-4, 2,1.000000},
  {fuseki13569,3,"Fuseki571", 0,-4,1.000000},
  {fuseki13570,3,"Fuseki572",-4, 3,1.000000},
  {fuseki13571,3,"Fuseki573",-2, 3,1.000000},
  {fuseki13572,4,"Fuseki574", 4,-2,4.000000},
  {fuseki13573,4,"Fuseki575", 2,-4,3.000000},
  {fuseki13574,4,"Fuseki576",-4, 1,1.000000},
  {fuseki13575,4,"Fuseki577", 4, 2,1.000000},
  {fuseki13576,4,"Fuseki578",-3, 2,1.000000},
  {fuseki13577,4,"Fuseki579", 4, 1,1.000000},
  {fuseki13578,2,"Fuseki580",-3,-3,6.000000},
  {fuseki13579,2,"Fuseki581",-3,-4,2.000000},
  {fuseki13580,2,"Fuseki582",-4, 1,1.000000},
  {fuseki13581,2,"Fuseki583",-4,-3,1.000000},
  {fuseki13582,2,"Fuseki584",-3,-4,1.000000},
  {fuseki13583,4,"Fuseki585",-4,-1,2.000000},
  {fuseki13584,4,"Fuseki586", 2, 4,2.000000},
  {fuseki13585,4,"Fuseki587",-1, 4,2.000000},
  {fuseki13586,4,"Fuseki588", 4,-1,1.000000},
  {fuseki13587,4,"Fuseki589", 0,-3,1.000000},
  {fuseki13588,4,"Fuseki590", 0, 3,1.000000},
  {fuseki13589,4,"Fuseki591", 0, 1,1.000000},
  {fuseki13590,4,"Fuseki592",-4, 0,1.000000},
  {fuseki13591,3,"Fuseki593", 4,-4,4.000000},
  {fuseki13592,3,"Fuseki594",-3,-4,3.000000},
  {fuseki13593,3,"Fuseki595",-3,-2,2.000000},
  {fuseki13594,3,"Fuseki596",-2,-4,1.000000},
  {fuseki13595,3,"Fuseki597",-2,-4,1.000000},
  {fuseki13596,3,"Fuseki598", 4, 4,8.000000},
  {fuseki13597,3,"Fuseki599",-3,-3,2.000000},
  {fuseki13598,3,"Fuseki600",-1, 4,1.000000},
  {fuseki13599,3,"Fuseki601", 4,-4,4.000000},
  {fuseki13600,3,"Fuseki602",-4,-3,2.000000},
  {fuseki13601,3,"Fuseki603", 3, 4,2.000000},
  {fuseki13602,3,"Fuseki604", 1, 4,1.000000},
  {fuseki13603,3,"Fuseki605",-3, 3,1.000000},
  {fuseki13604,3,"Fuseki606", 4, 4,1.000000},
  {fuseki13605,2,"Fuseki607", 3, 4,4.000000},
  {fuseki13606,2,"Fuseki608", 4, 3,2.000000},
  {fuseki13607,2,"Fuseki609", 4,-4,1.000000},
  {fuseki13608,2,"Fuseki610",-3,-4,1.000000},
  {fuseki13609,2,"Fuseki611", 4,-3,1.000000},
  {fuseki13610,2,"Fuseki612",-4,-2,1.000000},
  {fuseki13611,4,"Fuseki613", 3,-3,3.000000},
  {fuseki13612,4,"Fuseki614", 4, 0,2.000000},
  {fuseki13613,4,"Fuseki615",-4, 0,2.000000},
  {fuseki13614,4,"Fuseki616",-3,-2,1.000000},
  {fuseki13615,4,"Fuseki617",-4,-2,1.000000},
  {fuseki13616,4,"Fuseki618",-1,-4,1.000000},
  {fuseki13617,3,"Fuseki619", 4,-4,3.000000},
  {fuseki13618,3,"Fuseki620", 3,-3,3.000000},
  {fuseki13619,3,"Fuseki621",-4, 3,3.000000},
  {fuseki13620,3,"Fuseki622",-4, 2,1.000000},
  {fuseki13621,4,"Fuseki623", 0, 3,2.000000},
  {fuseki13622,4,"Fuseki624", 0, 4,1.000000},
  {fuseki13623,4,"Fuseki625", 3,-1,1.000000},
  {fuseki13624,4,"Fuseki626", 0, 3,1.000000},
  {fuseki13625,4,"Fuseki627",-4, 2,1.000000},
  {fuseki13626,4,"Fuseki628",-3,-2,1.000000},
  {fuseki13627,4,"Fuseki629", 0, 3,1.000000},
  {fuseki13628,4,"Fuseki630", 4, 2,1.000000},
  {fuseki13629,4,"Fuseki631", 4, 1,1.000000},
  {fuseki13630,2,"Fuseki632", 3, 3,4.000000},
  {fuseki13631,2,"Fuseki633",-4,-4,1.000000},
  {fuseki13632,2,"Fuseki634",-3, 4,1.000000},
  {fuseki13633,2,"Fuseki635", 3,-3,1.000000},
  {fuseki13634,2,"Fuseki636",-4, 3,1.000000},
  {fuseki13635,2,"Fuseki637", 4, 3,1.000000},
  {fuseki13636,2,"Fuseki638",-3,-2,1.000000},
  {fuseki13637,3,"Fuseki639",-4,-4,4.000000},
  {fuseki13638,3,"Fuseki640", 4,-3,3.000000},
  {fuseki13639,3,"Fuseki641", 3,-4,1.000000},
  {fuseki13640,3,"Fuseki642", 4,-2,1.000000},
  {fuseki13641,3,"Fuseki643",-3,-3,1.000000},
  {fuseki13642,3,"Fuseki644",-4, 4,5.000000},
  {fuseki13643,3,"Fuseki645",-4,-3,2.000000},
  {fuseki13644,3,"Fuseki646",-1,-4,1.000000},
  {fuseki13645,3,"Fuseki647", 3,-4,1.000000},
  {fuseki13646,3,"Fuseki648",-3, 2,1.000000},
  {fuseki13647,4,"Fuseki649",-4,-2,5.000000},
  {fuseki13648,4,"Fuseki650",-2,-4,2.000000},
  {fuseki13649,4,"Fuseki651", 4,-1,1.000000},
  {fuseki13650,4,"Fuseki652", 2, 3,1.000000},
  {fuseki13651,4,"Fuseki653",-1,-4,1.000000},
  {fuseki13652,3,"Fuseki654", 0,-4,4.000000},
  {fuseki13653,3,"Fuseki655",-4,-3,3.000000},
  {fuseki13654,3,"Fuseki656", 3, 2,1.000000},
  {fuseki13655,3,"Fuseki657",-3,-2,1.000000},
  {fuseki13656,3,"Fuseki658",-4,-2,1.000000},
  {fuseki13657,4,"Fuseki659", 4, 2,7.000000},
  {fuseki13658,4,"Fuseki660", 2, 2,3.000000},
  {fuseki13659,3,"Fuseki661",-3, 2,8.000000},
  {fuseki13660,3,"Fuseki662",-4,-4,1.000000},
  {fuseki13661,3,"Fuseki663", 3,-4,1.000000},
  {fuseki13662,3,"Fuseki664",-3,-3,3.000000},
  {fuseki13663,3,"Fuseki665", 4, 4,2.000000},
  {fuseki13664,3,"Fuseki666",-4, 3,2.000000},
  {fuseki13665,3,"Fuseki667", 2, 2,1.000000},
  {fuseki13666,3,"Fuseki668", 4,-2,1.000000},
  {fuseki13667,3,"Fuseki669",-4,-3,1.000000},
  {fuseki13668,4,"Fuseki670", 2, 4,6.000000},
  {fuseki13669,4,"Fuseki671",-2,-4,2.000000},
  {fuseki13670,4,"Fuseki672", 2, 4,1.000000},
  {fuseki13671,4,"Fuseki673",-1,-4,1.000000},
  {fuseki13672,4,"Fuseki674", 0, 4,2.000000},
  {fuseki13673,4,"Fuseki675",-4,-2,2.000000},
  {fuseki13674,4,"Fuseki676", 3,-3,2.000000},
  {fuseki13675,4,"Fuseki677",-1,-3,1.000000},
  {fuseki13676,4,"Fuseki678",-3, 4,1.000000},
  {fuseki13677,4,"Fuseki679", 2, 4,1.000000},
  {fuseki13678,4,"Fuseki680", 2, 4,1.000000},
  {fuseki13679,2,"Fuseki681",-3, 3,4.000000},
  {fuseki13680,2,"Fuseki682", 0, 3,2.000000},
  {fuseki13681,2,"Fuseki683",-1,-4,1.000000},
  {fuseki13682,2,"Fuseki684", 1, 1,1.000000},
  {fuseki13683,2,"Fuseki685",-3, 3,1.000000},
  {fuseki13684,2,"Fuseki686", 4,-3,2.000000},
  {fuseki13685,2,"Fuseki687",-3,-4,2.000000},
  {fuseki13686,2,"Fuseki688", 3, 3,2.000000},
  {fuseki13687,2,"Fuseki689", 4, 3,1.000000},
  {fuseki13688,2,"Fuseki690",-4,-2,1.000000},
  {fuseki13689,2,"Fuseki691", 3,-3,1.000000},
  {fuseki13690,3,"Fuseki692", 4,-4,3.000000},
  {fuseki13691,3,"Fuseki693", 3, 3,2.000000},
  {fuseki13692,3,"Fuseki694", 4,-3,2.000000},
  {fuseki13693,3,"Fuseki695", 3,-4,1.000000},
  {fuseki13694,3,"Fuseki696",-2, 3,1.000000},
  {fuseki13695,3,"Fuseki697",-4, 3,4.000000},
  {fuseki13696,3,"Fuseki698", 3, 3,3.000000},
  {fuseki13697,3,"Fuseki699", 2,-4,1.000000},
  {fuseki13698,3,"Fuseki700",-2, 2,1.000000},
  {fuseki13699,2,"Fuseki701", 3, 3,3.000000},
  {fuseki13700,2,"Fuseki702", 3, 3,2.000000},
  {fuseki13701,2,"Fuseki703",-4,-3,1.000000},
  {fuseki13702,2,"Fuseki704", 2, 2,1.000000},
  {fuseki13703,2,"Fuseki705", 4,-4,1.000000},
  {fuseki13704,2,"Fuseki706", 3,-4,1.000000},
  {fuseki13705,3,"Fuseki707", 4, 4,7.000000},
  {fuseki13706,3,"Fuseki708", 2, 4,1.000000},
  {fuseki13707,3,"Fuseki709", 4, 3,1.000000},
  {fuseki13708,3,"Fuseki710", 4, 2,6.000000},
  {fuseki13709,3,"Fuseki711",-3,-4,2.000000},
  {fuseki13710,3,"Fuseki712", 4, 4,1.000000},
  {fuseki13711,5,"Fuseki713", 2,-4,3.000000},
  {fuseki13712,5,"Fuseki714",-2, 3,3.000000},
  {fuseki13713,5,"Fuseki715",-3, 0,1.000000},
  {fuseki13714,5,"Fuseki716", 3, 2,1.000000},
  {fuseki13715,5,"Fuseki717", 2,-4,1.000000},
  {fuseki13716,4,"Fuseki718", 3,-3,2.000000},
  {fuseki13717,4,"Fuseki719", 2, 2,1.000000},
  {fuseki13718,4,"Fuseki720",-4, 0,1.000000},
  {fuseki13719,4,"Fuseki721", 2, 4,1.000000},
  {fuseki13720,4,"Fuseki722",-1, 4,1.000000},
  {fuseki13721,4,"Fuseki723", 0, 0,1.000000},
  {fuseki13722,4,"Fuseki724", 4, 1,1.000000},
  {fuseki13723,3,"Fuseki725", 4, 3,5.000000},
  {fuseki13724,3,"Fuseki726", 2, 3,3.000000},
  {fuseki13725,2,"Fuseki727",-3, 3,3.000000},
  {fuseki13726,2,"Fuseki728",-3,-3,2.000000},
  {fuseki13727,2,"Fuseki729",-4,-3,1.000000},
  {fuseki13728,2,"Fuseki730",-3, 4,1.000000},
  {fuseki13729,2,"Fuseki731",-4,-1,1.000000},
  {fuseki13730,4,"Fuseki732", 3,-2,3.000000},
  {fuseki13731,4,"Fuseki733", 2, 4,2.000000},
  {fuseki13732,4,"Fuseki734", 1,-3,1.000000},
  {fuseki13733,4,"Fuseki735", 2, 0,1.000000},
  {fuseki13734,4,"Fuseki736", 4,-2,1.000000},
  {fuseki13735,5,"Fuseki737", 3, 3,4.000000},
  {fuseki13736,5,"Fuseki738",-4, 2,1.000000},
  {fuseki13737,5,"Fuseki739", 3, 2,1.000000},
  {fuseki13738,5,"Fuseki740", 4, 3,1.000000},
  {fuseki13739,5,"Fuseki741", 3,-2,1.000000},
  {fuseki13740,4,"Fuseki742", 4,-2,7.000000},
  {fuseki13741,4,"Fuseki743", 4, 0,1.000000},
  {fuseki13742,4,"Fuseki744", 3,-4,8.000000},
  {fuseki13743,3,"Fuseki745", 3, 2,3.000000},
  {fuseki13744,3,"Fuseki746", 2,-4,1.000000},
  {fuseki13745,3,"Fuseki747",-4, 2,1.000000},
  {fuseki13746,3,"Fuseki748",-3,-3,1.000000},
  {fuseki13747,3,"Fuseki749",-4,-3,1.000000},
  {fuseki13748,3,"Fuseki750",-4,-1,1.000000},
  {fuseki13749,4,"Fuseki751", 4,-2,2.000000},
  {fuseki13750,4,"Fuseki752",-4, 1,2.000000},
  {fuseki13751,4,"Fuseki753",-3, 0,1.000000},
  {fuseki13752,4,"Fuseki754",-4, 4,1.000000},
  {fuseki13753,4,"Fuseki755", 1,-4,1.000000},
  {fuseki13754,4,"Fuseki756", 2, 0,1.000000},
  {fuseki13755,4,"Fuseki757",-2, 3,2.000000},
  {fuseki13756,4,"Fuseki758",-3,-3,2.000000},
  {fuseki13757,4,"Fuseki759",-4,-1,1.000000},
  {fuseki13758,4,"Fuseki760", 4, 2,1.000000},
  {fuseki13759,4,"Fuseki761", 2, 3,1.000000},
  {fuseki13760,4,"Fuseki762",-4, 0,1.000000},
  {fuseki13761,4,"Fuseki763",-4,-3,2.000000},
  {fuseki13762,4,"Fuseki764",-3, 3,1.000000},
  {fuseki13763,4,"Fuseki765",-1, 4,1.000000},
  {fuseki13764,4,"Fuseki766", 2,-3,1.000000},
  {fuseki13765,4,"Fuseki767",-4, 0,1.000000},
  {fuseki13766,4,"Fuseki768", 4,-4,1.000000},
  {fuseki13767,4,"Fuseki769", 1,-4,1.000000},
  {fuseki13768,2,"Fuseki770", 3, 3,2.000000},
  {fuseki13769,2,"Fuseki771", 2,-2,2.000000},
  {fuseki13770,2,"Fuseki772", 3, 1,1.000000},
  {fuseki13771,2,"Fuseki773", 3,-3,1.000000},
  {fuseki13772,2,"Fuseki774", 4, 1,1.000000},
  {fuseki13773,2,"Fuseki775",-2, 4,1.000000},
  {fuseki13774,3,"Fuseki776",-3, 3,3.000000},
  {fuseki13775,3,"Fuseki777",-4, 3,2.000000},
  {fuseki13776,3,"Fuseki778", 4, 2,1.000000},
  {fuseki13777,3,"Fuseki779", 4, 4,1.000000},
  {fuseki13778,3,"Fuseki780", 2,-3,1.000000},
  {fuseki13779,2,"Fuseki781", 3, 2,8.000000},
  {fuseki13780,2,"Fuseki782",-4, 3,4.000000},
  {fuseki13781,2,"Fuseki783",-4, 4,2.000000},
  {fuseki13782,6,"Fuseki784", 2, 3,5.000000},
  {fuseki13783,6,"Fuseki785", 4, 3,2.000000},
  {fuseki13784,5,"Fuseki786",-1, 4,3.000000},
  {fuseki13785,5,"Fuseki787",-4, 3,1.000000},
  {fuseki13786,5,"Fuseki788",-1,-3,1.000000},
  {fuseki13787,5,"Fuseki789", 0,-4,1.000000},
  {fuseki13788,5,"Fuseki790", 2,-3,1.000000},
  {fuseki13789,3,"Fuseki791", 4,-4,3.000000},
  {fuseki13790,3,"Fuseki792",-3, 3,2.000000},
  {fuseki13791,3,"Fuseki793", 2, 4,1.000000},
  {fuseki13792,3,"Fuseki794", 4,-3,1.000000},
  {fuseki13793,4,"Fuseki795", 3, 0,2.000000},
  {fuseki13794,4,"Fuseki796", 1, 3,1.000000},
  {fuseki13795,4,"Fuseki797", 4,-2,1.000000},
  {fuseki13796,4,"Fuseki798",-1,-4,1.000000},
  {fuseki13797,4,"Fuseki799", 4,-1,1.000000},
  {fuseki13798,4,"Fuseki800", 4, 2,1.000000},
  {fuseki13799,5,"Fuseki801", 0,-4,2.000000},
  {fuseki13800,5,"Fuseki802", 4, 1,1.000000},
  {fuseki13801,5,"Fuseki803",-2,-2,1.000000},
  {fuseki13802,5,"Fuseki804", 3, 2,1.000000},
  {fuseki13803,5,"Fuseki805",-1, 4,1.000000},
  {fuseki13804,5,"Fuseki806",-2,-3,1.000000},
  {fuseki13805,5,"Fuseki807", 2, 2,7.000000},
  {fuseki13806,2,"Fuseki808", 4, 3,2.000000},
  {fuseki13807,2,"Fuseki809",-3, 3,2.000000},
  {fuseki13808,2,"Fuseki810", 4,-4,1.000000},
  {fuseki13809,2,"Fuseki811",-4,-3,1.000000},
  {fuseki13810,2,"Fuseki812", 1,-1,1.000000},
  {fuseki13811,4,"Fuseki813", 1, 4,2.000000},
  {fuseki13812,4,"Fuseki814", 4, 0,2.000000},
  {fuseki13813,4,"Fuseki815", 0,-4,2.000000},
  {fuseki13814,4,"Fuseki816",-3,-3,1.000000},
  {fuseki13815,3,"Fuseki817",-4,-4,3.000000},
  {fuseki13816,3,"Fuseki818",-3, 3,2.000000},
  {fuseki13817,3,"Fuseki819", 2, 4,1.000000},
  {fuseki13818,3,"Fuseki820", 4,-2,1.000000},
  {fuseki13819,5,"Fuseki821",-1,-3,2.000000},
  {fuseki13820,5,"Fuseki822", 4,-2,2.000000},
  {fuseki13821,5,"Fuseki823", 1, 4,1.000000},
  {fuseki13822,5,"Fuseki824",-1, 4,1.000000},
  {fuseki13823,5,"Fuseki825",-1,-4,1.000000},
  {fuseki13824,4,"Fuseki826",-3,-4,4.000000},
  {fuseki13825,4,"Fuseki827", 4, 0,1.000000},
  {fuseki13826,4,"Fuseki828",-4, 3,1.000000},
  {fuseki13827,4,"Fuseki829",-4, 4,1.000000},
  {fuseki13828,3,"Fuseki830", 4, 4,5.000000},
  {fuseki13829,3,"Fuseki831",-4, 3,1.000000},
  {fuseki13830,3,"Fuseki832",-2,-4,1.000000},
  {fuseki13831,3,"Fuseki833", 4, 4,6.000000},
  {fuseki13832,3,"Fuseki834",-3, 4,1.000000},
  {fuseki13833,4,"Fuseki835", 4,-2,4.000000},
  {fuseki13834,4,"Fuseki836",-3, 1,1.000000},
  {fuseki13835,4,"Fuseki837",-1, 4,1.000000},
  {fuseki13836,4,"Fuseki838", 2,-3,1.000000},
  {fuseki13837,4,"Fuseki839", 3,-2,3.000000},
  {fuseki13838,4,"Fuseki840",-2, 4,2.000000},
  {fuseki13839,4,"Fuseki841", 4,-1,1.000000},
  {fuseki13840,4,"Fuseki842",-3,-3,1.000000},
  {fuseki13841,5,"Fuseki843", 4,-3,5.000000},
  {fuseki13842,5,"Fuseki844", 0,-4,1.000000},
  {fuseki13843,5,"Fuseki845", 4, 2,1.000000},
  {fuseki13844,2,"Fuseki846",-4,-4,4.000000},
  {fuseki13845,2,"Fuseki847", 3, 3,2.000000},
  {fuseki13846,2,"Fuseki848",-4,-4,1.000000},
  {fuseki13847,5,"Fuseki849", 3, 0,3.000000},
  {fuseki13848,5,"Fuseki850", 2,-4,2.000000},
  {fuseki13849,5,"Fuseki851",-4, 0,1.000000},
  {fuseki13850,5,"Fuseki852", 0, 4,1.000000},
  {fuseki13851,5,"Fuseki853",-3,-3,1.000000},
  {fuseki13852,5,"Fuseki854", 3,-2,1.000000},
  {fuseki13853,5,"Fuseki855", 3, 0,1.000000},
  {fuseki13854,5,"Fuseki856", 4, 0,1.000000},
  {fuseki13855,5,"Fuseki857", 2, 2,1.000000},
  {fuseki13856,5,"Fuseki858", 0, 4,1.000000},
  {fuseki13857,5,"Fuseki859", 3, 4,1.000000},
  {fuseki13858,3,"Fuseki860",-4,-4,3.000000},
  {fuseki13859,3,"Fuseki861",-3,-4,1.000000},
  {fuseki13860,3,"Fuseki862", 3,-2,1.000000},
  {fuseki13861,3,"Fuseki863", 3,-3,1.000000},
  {fuseki13862,3,"Fuseki864",-3,-4,1.000000},
  {fuseki13863,3,"Fuseki865", 4,-3,4.000000},
  {fuseki13864,3,"Fuseki866", 3,-2,1.000000},
  {fuseki13865,3,"Fuseki867", 3, 3,1.000000},
  {fuseki13866,3,"Fuseki868",-4,-2,1.000000},
  {fuseki13867,3,"Fuseki869",-4,-4,3.000000},
  {fuseki13868,3,"Fuseki870", 3, 3,2.000000},
  {fuseki13869,3,"Fuseki871",-2,-3,1.000000},
  {fuseki13870,3,"Fuseki872",-4, 3,1.000000},
  {fuseki13871,4,"Fuseki873", 4,-2,2.000000},
  {fuseki13872,4,"Fuseki874",-2, 3,2.000000},
  {fuseki13873,4,"Fuseki875", 2, 2,1.000000},
  {fuseki13874,4,"Fuseki876", 3,-2,1.000000},
  {fuseki13875,4,"Fuseki877", 3,-3,1.000000},
  {fuseki13876,4,"Fuseki878", 2,-4,2.000000},
  {fuseki13877,4,"Fuseki879", 2,-3,2.000000},
  {fuseki13878,4,"Fuseki880", 3, 0,2.000000},
  {fuseki13879,4,"Fuseki881", 0, 3,1.000000},
  {fuseki13880,4,"Fuseki882", 4, 1,5.000000},
  {fuseki13881,4,"Fuseki883", 0,-3,1.000000},
  {fuseki13882,4,"Fuseki884", 4, 0,1.000000},
  {fuseki13883,4,"Fuseki885", 2, 4,2.000000},
  {fuseki13884,4,"Fuseki886", 4, 2,1.000000},
  {fuseki13885,4,"Fuseki887", 1, 4,1.000000},
  {fuseki13886,4,"Fuseki888", 1, 3,1.000000},
  {fuseki13887,4,"Fuseki889",-2, 4,1.000000},
  {fuseki13888,4,"Fuseki890",-2, 4,3.000000},
  {fuseki13889,4,"Fuseki891", 2,-4,2.000000},
  {fuseki13890,4,"Fuseki892", 0,-4,1.000000},
  {fuseki13891,5,"Fuseki893", 2, 3,2.000000},
  {fuseki13892,5,"Fuseki894", 3,-4,2.000000},
  {fuseki13893,5,"Fuseki895", 3, 1,2.000000},
  {fuseki13894,3,"Fuseki896", 3,-3,2.000000},
  {fuseki13895,3,"Fuseki897", 5, 3,2.000000},
  {fuseki13896,3,"Fuseki898", 4, 4,1.000000},
  {fuseki13897,3,"Fuseki899", 4,-1,1.000000},
  {fuseki13898,3,"Fuseki900",-3, 3,5.000000},
  {fuseki13899,3,"Fuseki901", 4, 3,1.000000},
  {fuseki13900,5,"Fuseki902",-1,-4,2.000000},
  {fuseki13901,5,"Fuseki903", 0,-4,2.000000},
  {fuseki13902,5,"Fuseki904", 4,-1,1.000000},
  {fuseki13903,5,"Fuseki905", 3,-2,1.000000},
  {fuseki13904,4,"Fuseki906", 4,-1,5.000000},
  {fuseki13905,4,"Fuseki907",-2,-4,1.000000},
  {fuseki13906,4,"Fuseki908", 2, 4,6.000000},
  {fuseki13907,3,"Fuseki909",-3,-3,3.000000},
  {fuseki13908,3,"Fuseki910",-2,-4,2.000000},
  {fuseki13909,3,"Fuseki911",-4,-3,1.000000},
  {fuseki13910,4,"Fuseki912", 4, 1,2.000000},
  {fuseki13911,4,"Fuseki913",-2, 4,2.000000},
  {fuseki13912,4,"Fuseki914", 1, 4,1.000000},
  {fuseki13913,4,"Fuseki915", 4,-1,1.000000},
  {fuseki13914,3,"Fuseki916",-3, 3,2.000000},
  {fuseki13915,3,"Fuseki917", 4,-3,2.000000},
  {fuseki13916,3,"Fuseki918",-4, 3,1.000000},
  {fuseki13917,3,"Fuseki919", 4,-4,1.000000},
  {fuseki13918,3,"Fuseki920", 4, 4,3.000000},
  {fuseki13919,3,"Fuseki921", 4, 2,1.000000},
  {fuseki13920,3,"Fuseki922", 2,-4,1.000000},
  {fuseki13921,3,"Fuseki923",-3,-3,1.000000},
  {fuseki13922,3,"Fuseki924", 4,-4,3.000000},
  {fuseki13923,3,"Fuseki925", 4,-3,2.000000},
  {fuseki13924,3,"Fuseki926",-2,-4,1.000000},
  {fuseki13925,4,"Fuseki927", 0,-4,2.000000},
  {fuseki13926,4,"Fuseki928", 4,-2,1.000000},
  {fuseki13927,4,"Fuseki929",-4, 2,1.000000},
  {fuseki13928,4,"Fuseki930", 1,-4,1.000000},
  {fuseki13929,4,"Fuseki931", 4, 3,1.000000},
  {fuseki13930,4,"Fuseki932", 4, 2,2.000000},
  {fuseki13931,4,"Fuseki933", 4,-1,1.000000},
  {fuseki13932,4,"Fuseki934",-3,-3,1.000000},
  {fuseki13933,4,"Fuseki935", 2, 3,1.000000},
  {fuseki13934,4,"Fuseki936", 1, 4,1.000000},
  {fuseki13935,3,"Fuseki937",-4,-4,3.000000},
  {fuseki13936,3,"Fuseki938", 4,-3,1.000000},
  {fuseki13937,3,"Fuseki939", 0,-4,1.000000},
  {fuseki13938,3,"Fuseki940", 3,-3,1.000000},
  {fuseki13939,4,"Fuseki941",-2,-4,1.000000},
  {fuseki13940,4,"Fuseki942", 1, 3,1.000000},
  {fuseki13941,4,"Fuseki943", 4, 1,1.000000},
  {fuseki13942,4,"Fuseki944", 0,-4,1.000000},
  {fuseki13943,4,"Fuseki945",-4, 2,1.000000},
  {fuseki13944,4,"Fuseki946",-3, 0,1.000000},
  {fuseki13945,2,"Fuseki947",-3,-3,1.000000},
  {fuseki13946,2,"Fuseki948", 3, 3,1.000000},
  {fuseki13947,2,"Fuseki949",-4, 3,1.000000},
  {fuseki13948,2,"Fuseki950", 3,-4,1.000000},
  {fuseki13949,2,"Fuseki951",-3,-2,1.000000},
  {fuseki13950,2,"Fuseki952",-3, 0,1.000000},
  {fuseki13951,3,"Fuseki953",-4,-4,4.000000},
  {fuseki13952,3,"Fuseki954", 3, 4,1.000000},
  {fuseki13953,3,"Fuseki955",-3,-3,1.000000},
  {fuseki13954,5,"Fuseki956", 4, 2,2.000000},
  {fuseki13955,5,"Fuseki957", 1, 3,1.000000},
  {fuseki13956,5,"Fuseki958", 1, 3,1.000000},
  {fuseki13957,5,"Fuseki959", 4,-1,1.000000},
  {fuseki13958,5,"Fuseki960",-2, 3,1.000000},
  {fuseki13959,4,"Fuseki961",-4, 0,1.000000},
  {fuseki13960,4,"Fuseki962", 3, 0,1.000000},
  {fuseki13961,4,"Fuseki963",-2,-3,1.000000},
  {fuseki13962,4,"Fuseki964",-3, 0,1.000000},
  {fuseki13963,4,"Fuseki965", 0,-3,1.000000},
  {fuseki13964,4,"Fuseki966",-4, 1,1.000000},
  {fuseki13965,4,"Fuseki967",-1, 4,3.000000},
  {fuseki13966,4,"Fuseki968", 2, 3,1.000000},
  {fuseki13967,4,"Fuseki969",-1, 3,1.000000},
  {fuseki13968,4,"Fuseki970", 0,-4,1.000000},
  {fuseki13969,4,"Fuseki971", 4, 2,4.000000},
  {fuseki13970,4,"Fuseki972",-3,-2,1.000000},
  {fuseki13971,4,"Fuseki973", 3, 0,1.000000},
  {fuseki13972,5,"Fuseki974", 4, 1,1.000000},
  {fuseki13973,5,"Fuseki975", 0, 0,1.000000},
  {fuseki13974,5,"Fuseki976",-2, 0,1.000000},
  {fuseki13975,5,"Fuseki977",-4, 3,1.000000},
  {fuseki13976,5,"Fuseki978", 3,-1,1.000000},
  {fuseki13977,5,"Fuseki979", 2, 4,1.000000},
  {fuseki13978,3,"Fuseki980",-4,-3,2.000000},
  {fuseki13979,3,"Fuseki981", 4,-4,2.000000},
  {fuseki13980,3,"Fuseki982", 2,-4,1.000000},
  {fuseki13981,3,"Fuseki983",-3, 3,1.000000},
  {fuseki13982,4,"Fuseki984", 0, 3,1.000000},
  {fuseki13983,4,"Fuseki985", 4,-1,1.000000},
  {fuseki13984,4,"Fuseki986", 4, 1,1.000000},
  {fuseki13985,4,"Fuseki987",-4,-3,1.000000},
  {fuseki13986,4,"Fuseki988", 4,-4,1.000000},
  {fuseki13987,4,"Fuseki989",-1,-3,1.000000},
  {fuseki13988,5,"Fuseki990", 5, 1,4.000000},
  {fuseki13989,5,"Fuseki991",-2, 4,1.000000},
  {fuseki13990,2,"Fuseki992",-4,-4,2.000000},
  {fuseki13991,2,"Fuseki993", 3,-4,1.000000},
  {fuseki13992,2,"Fuseki994",-3,-3,1.000000},
  {fuseki13993,2,"Fuseki995", 3, 2,1.000000},
  {fuseki13994,3,"Fuseki996", 3,-2,2.000000},
  {fuseki13995,3,"Fuseki997", 3,-3,2.000000},
  {fuseki13996,3,"Fuseki998",-2, 4,1.000000},
  {fuseki13997,5,"Fuseki999", 0,-3,2.000000},
  {fuseki13998,5,"Fuseki1000",-4, 1,1.000000},
  {fuseki13999,5,"Fuseki1001", 2,-1,1.000000},
  {fuseki131000,5,"Fuseki1002",-4,-1,1.000000},
  {fuseki131001,5,"Fuseki1003", 0,-4,2.000000},
  {fuseki131002,5,"Fuseki1004", 4,-2,2.000000},
  {fuseki131003,5,"Fuseki1005", 4, 1,1.000000},
  {fuseki131004,4,"Fuseki1006", 2,-4,3.000000},
  {fuseki131005,4,"Fuseki1007", 0,-4,1.000000},
  {fuseki131006,4,"Fuseki1008", 1,-4,1.000000},
  {fuseki131007,3,"Fuseki1009",-4,-4,2.000000},
  {fuseki131008,3,"Fuseki1010",-4, 3,2.000000},
  {fuseki131009,3,"Fuseki1011", 3,-4,1.000000},
  {fuseki131010,4,"Fuseki1012", 4, 1,5.000000},
  {fuseki131011,3,"Fuseki1013", 3, 3,2.000000},
  {fuseki131012,3,"Fuseki1014", 3,-3,2.000000},
  {fuseki131013,3,"Fuseki1015", 4, 3,1.000000},
  {fuseki131014,4,"Fuseki1016", 2,-3,1.000000},
  {fuseki131015,4,"Fuseki1017",-4,-2,1.000000},
  {fuseki131016,4,"Fuseki1018",-1,-4,1.000000},
  {fuseki131017,4,"Fuseki1019", 3,-4,1.000000},
  {fuseki131018,4,"Fuseki1020", 1,-4,1.000000},
  {fuseki131019,4,"Fuseki1021",-2, 4,3.000000},
  {fuseki131020,4,"Fuseki1022", 1, 5,1.000000},
  {fuseki131021,4,"Fuseki1023", 3, 3,1.000000},
  {fuseki131022,4,"Fuseki1024", 0,-3,1.000000},
  {fuseki131023,4,"Fuseki1025", 4, 0,1.000000},
  {fuseki131024,4,"Fuseki1026",-1, 4,1.000000},
  {fuseki131025,4,"Fuseki1027", 2,-2,1.000000},
  {fuseki131026,4,"Fuseki1028", 1, 3,1.000000},
  {fuseki131027,6,"Fuseki1029", 3,-2,5.000000},
  {fuseki131028,8,"Fuseki1030",-5, 0,1.000000},
  {fuseki131029,8,"Fuseki1031",-3, 0,1.000000},
  {fuseki131030,8,"Fuseki1032",-1, 3,1.000000},
  {fuseki131031,8,"Fuseki1033",-5,-1,1.000000},
  {fuseki131032,8,"Fuseki1034",-6, 0,1.000000},
  {fuseki131033,5,"Fuseki1035", 4, 2,3.000000},
  {fuseki131034,5,"Fuseki1036", 0, 4,1.000000},
  {fuseki131035,5,"Fuseki1037", 4,-1,1.000000},
  {fuseki131036,3,"Fuseki1038",-4,-4,3.000000},
  {fuseki131037,3,"Fuseki1039", 2,-4,1.000000},
  {fuseki131038,3,"Fuseki1040", 4,-3,1.000000},
  {fuseki131039,2,"Fuseki1041", 4, 4,1.000000},
  {fuseki131040,2,"Fuseki1042", 4,-3,1.000000},
  {fuseki131041,2,"Fuseki1043",-3, 4,1.000000},
  {fuseki131042,2,"Fuseki1044", 4,-2,1.000000},
  {fuseki131043,2,"Fuseki1045",-3, 3,1.000000},
  {fuseki131044,5,"Fuseki1046",-1,-3,3.000000},
  {fuseki131045,5,"Fuseki1047", 3, 2,1.000000},
  {fuseki131046,5,"Fuseki1048", 0, 4,1.000000},
  {fuseki131047,3,"Fuseki1049",-3, 4,3.000000},
  {fuseki131048,3,"Fuseki1050",-3, 3,1.000000},
  {fuseki131049,3,"Fuseki1051",-4, 2,1.000000},
  {fuseki131050,3,"Fuseki1052",-4, 4,5.000000},
  {fuseki131051,4,"Fuseki1053", 4, 2,2.000000},
  {fuseki131052,4,"Fuseki1054",-4,-2,1.000000},
  {fuseki131053,4,"Fuseki1055",-1, 4,1.000000},
  {fuseki131054,4,"Fuseki1056", 3, 0,1.000000},
  {fuseki131055,5,"Fuseki1057", 1, 4,2.000000},
  {fuseki131056,5,"Fuseki1058", 1,-3,2.000000},
  {fuseki131057,5,"Fuseki1059",-3, 0,1.000000},
  {fuseki131058,5,"Fuseki1060", 2, 1,1.000000},
  {fuseki131059,5,"Fuseki1061", 4, 1,1.000000},
  {fuseki131060,5,"Fuseki1062", 5,-3,1.000000},
  {fuseki131061,5,"Fuseki1063", 4, 2,1.000000},
  {fuseki131062,5,"Fuseki1064", 0, 4,1.000000},
  {fuseki131063,7,"Fuseki1065",-3,-1,5.000000},
  {fuseki131064,4,"Fuseki1066", 0, 4,2.000000},
  {fuseki131065,4,"Fuseki1067",-1, 3,1.000000},
  {fuseki131066,4,"Fuseki1068",-4, 0,1.000000},
  {fuseki131067,4,"Fuseki1069",-2,-3,1.000000},
  {fuseki131068,7,"Fuseki1070", 1,-3,2.000000},
  {fuseki131069,7,"Fuseki1071", 3, 0,1.000000},
  {fuseki131070,7,"Fuseki1072", 4,-1,1.000000},
  {fuseki131071,7,"Fuseki1073", 4, 1,1.000000},
  {fuseki131072,4,"Fuseki1074", 3, 4,4.000000},
  {fuseki131073,4,"Fuseki1075", 4, 4,1.000000},
  {fuseki131074,4,"Fuseki1076",-4,-1,1.000000},
  {fuseki131075,4,"Fuseki1077",-4, 2,1.000000},
  {fuseki131076,4,"Fuseki1078", 2, 3,1.000000},
  {fuseki131077,4,"Fuseki1079", 0,-4,1.000000},
  {fuseki131078,4,"Fuseki1080",-4,-1,1.000000},
  {fuseki131079,3,"Fuseki1081", 3,-2,2.000000},
  {fuseki131080,3,"Fuseki1082",-4, 3,1.000000},
  {fuseki131081,3,"Fuseki1083",-4, 3,1.000000},
  {fuseki131082,3,"Fuseki1084",-2, 4,1.000000},
  {fuseki131083,5,"Fuseki1085",-3, 0,4.000000},
  {fuseki131084,5,"Fuseki1086",-4, 4,1.000000},
  {fuseki131085,3,"Fuseki1087", 3, 3,2.000000},
  {fuseki131086,3,"Fuseki1088", 3,-4,1.000000},
  {fuseki131087,3,"Fuseki1089", 4, 1,1.000000},
  {fuseki131088,3,"Fuseki1090", 4, 4,1.000000},
  {fuseki131089,2,"Fuseki1091", 3, 4,2.000000},
  {fuseki131090,2,"Fuseki1092",-4, 4,1.000000},
  {fuseki131091,2,"Fuseki1093", 2, 4,1.000000},
  {fuseki131092,2,"Fuseki1094",-3,-2,1.000000},
  {fuseki131093,5,"Fuseki1095",-4,-1,5.000000},
  {fuseki131094,3,"Fuseki1096", 4,-4,2.000000},
  {fuseki131095,3,"Fuseki1097", 4,-1,1.000000},
  {fuseki131096,3,"Fuseki1098",-3,-3,1.000000},
  {fuseki131097,3,"Fuseki1099", 3,-4,1.000000},
  {fuseki131098,4,"Fuseki1100", 2, 3,5.000000},
  {fuseki131099,5,"Fuseki1101",-4, 0,2.000000},
  {fuseki131100,5,"Fuseki1102",-1,-4,2.000000},
  {fuseki131101,5,"Fuseki1103", 4,-2,1.000000},
  {fuseki131102,4,"Fuseki1104", 0, 3,1.000000},
  {fuseki131103,4,"Fuseki1105", 5, 0,1.000000},
  {fuseki131104,4,"Fuseki1106",-3, 1,1.000000},
  {fuseki131105,4,"Fuseki1107",-2, 4,1.000000},
  {fuseki131106,4,"Fuseki1108", 1,-4,1.000000},
  {fuseki131107,7,"Fuseki1109", 1, 2,4.000000},
  {fuseki131108,7,"Fuseki1110", 4, 3,1.000000},
  {fuseki131109,3,"Fuseki1111", 2, 3,3.000000},
  {fuseki131110,3,"Fuseki1112",-2, 4,1.000000},
  {fuseki131111,3,"Fuseki1113",-4, 3,1.000000},
  {fuseki131112,4,"Fuseki1114",-1, 3,1.000000},
  {fuseki131113,4,"Fuseki1115",-4, 2,1.000000},
  {fuseki131114,4,"Fuseki1116",-3,-2,1.000000},
  {fuseki131115,4,"Fuseki1117", 3, 0,1.000000},
  {fuseki131116,4,"Fuseki1118",-4, 0,1.000000},
  {fuseki131117,4,"Fuseki1119", 2, 4,3.000000},
  {fuseki131118,4,"Fuseki1120",-3, 3,1.000000},
  {fuseki131119,4,"Fuseki1121",-2, 3,1.000000},
  {fuseki131120,5,"Fuseki1122",-4, 0,2.000000},
  {fuseki131121,5,"Fuseki1123", 0,-3,1.000000},
  {fuseki131122,5,"Fuseki1124", 4,-1,1.000000},
  {fuseki131123,5,"Fuseki1125", 1,-4,1.000000},
  {fuseki131124,4,"Fuseki1126",-1,-4,1.000000},
  {fuseki131125,4,"Fuseki1127", 0, 3,1.000000},
  {fuseki131126,4,"Fuseki1128", 2,-4,1.000000},
  {fuseki131127,4,"Fuseki1129", 4,-2,1.000000},
  {fuseki131128,4,"Fuseki1130", 0, 4,1.000000},
  {fuseki131129,6,"Fuseki1131",-4, 0,5.000000},
  {fuseki131130,4,"Fuseki1132", 3,-2,1.000000},
  {fuseki131131,4,"Fuseki1133", 4, 2,1.000000},
  {fuseki131132,4,"Fuseki1134", 1,-2,1.000000},
  {fuseki131133,4,"Fuseki1135", 2, 3,1.000000},
  {fuseki131134,4,"Fuseki1136", 2,-4,1.000000},
  {fuseki131135,4,"Fuseki1137", 4,-2,2.000000},
  {fuseki131136,4,"Fuseki1138",-4,-2,1.000000},
  {fuseki131137,4,"Fuseki1139", 4,-1,1.000000},
  {fuseki131138,4,"Fuseki1140",-4, 2,1.000000},
  {fuseki131139,5,"Fuseki1141",-1, 4,3.000000},
  {fuseki131140,5,"Fuseki1142",-2,-3,1.000000},
  {fuseki131141,4,"Fuseki1143",-4,-2,2.000000},
  {fuseki131142,4,"Fuseki1144", 4,-2,1.000000},
  {fuseki131143,4,"Fuseki1145", 0, 3,1.000000},
  {fuseki131144,3,"Fuseki1146",-4,-2,2.000000},
  {fuseki131145,3,"Fuseki1147",-3,-3,1.000000},
  {fuseki131146,3,"Fuseki1148", 3,-4,1.000000},
  {fuseki131147,4,"Fuseki1149",-4,-2,1.000000},
  {fuseki131148,4,"Fuseki1150",-4, 1,1.000000},
  {fuseki131149,4,"Fuseki1151",-4, 2,1.000000},
  {fuseki131150,4,"Fuseki1152", 0,-3,1.000000},
  {fuseki131151,2,"Fuseki1153", 4, 3,2.000000},
  {fuseki131152,2,"Fuseki1154", 4, 3,1.000000},
  {fuseki131153,2,"Fuseki1155",-3,-3,1.000000},
  {fuseki131154,4,"Fuseki1156",-2, 4,3.000000},
  {fuseki131155,4,"Fuseki1157",-3, 2,1.000000},
  {fuseki131156,2,"Fuseki1158",-3, 4,3.000000},
  {fuseki131157,2,"Fuseki1159", 4, 4,1.000000},
  {fuseki131158,3,"Fuseki1160", 3, 4,2.000000},
  {fuseki131159,3,"Fuseki1161",-3, 3,1.000000},
  {fuseki131160,3,"Fuseki1162", 3,-3,1.000000},
  {fuseki131161,4,"Fuseki1163", 1,-4,3.000000},
  {fuseki131162,4,"Fuseki1164",-1, 4,1.000000},
  {fuseki131163,5,"Fuseki1165",-3, 2,2.000000},
  {fuseki131164,5,"Fuseki1166",-4, 2,2.000000},
  {fuseki131165,4,"Fuseki1167",-3, 4,2.000000},
  {fuseki131166,4,"Fuseki1168", 3, 1,1.000000},
  {fuseki131167,4,"Fuseki1169",-4, 3,1.000000},
  {fuseki131168,5,"Fuseki1170", 4, 2,2.000000},
  {fuseki131169,5,"Fuseki1171", 2, 3,1.000000},
  {fuseki131170,5,"Fuseki1172", 3, 2,1.000000},
  {fuseki131171,4,"Fuseki1173", 2, 0,4.000000},
  {fuseki131172,8,"Fuseki1174", 2, 2,4.000000},
  {fuseki131173,4,"Fuseki1175",-4, 3,1.000000},
  {fuseki131174,4,"Fuseki1176",-1,-3,1.000000},
  {fuseki131175,4,"Fuseki1177",-3,-2,1.000000},
  {fuseki131176,4,"Fuseki1178",-4,-3,1.000000},
  {fuseki131177,4,"Fuseki1179",-5, 3,3.000000},
  {fuseki131178,4,"Fuseki1180",-2, 3,1.000000},
  {fuseki131179,6,"Fuseki1181", 0, 3,1.000000},
  {fuseki131180,6,"Fuseki1182", 0, 0,1.000000},
  {fuseki131181,6,"Fuseki1183", 0,-3,1.000000},
  {fuseki131182,6,"Fuseki1184",-4, 2,1.000000},
  {fuseki131183,4,"Fuseki1185", 3, 4,1.000000},
  {fuseki131184,4,"Fuseki1186", 2, 3,1.000000},
  {fuseki131185,4,"Fuseki1187", 1,-4,1.000000},
  {fuseki131186,4,"Fuseki1188", 0,-3,1.000000},
  {fuseki131187,6,"Fuseki1189",-5, 1,4.000000},
  {fuseki131188,1,"Fuseki1190",-2, 4,1.000000},
  {fuseki131189,1,"Fuseki1191",-3,-3,1.000000},
  {fuseki131190,1,"Fuseki1192", 3, 4,1.000000},
  {fuseki131191,4,"Fuseki1193", 2, 4,2.000000},
  {fuseki131192,4,"Fuseki1194", 3,-2,1.000000},
  {fuseki131193,4,"Fuseki1195",-1, 4,1.000000},
  {fuseki131194,3,"Fuseki1196",-2,-4,2.000000},
  {fuseki131195,3,"Fuseki1197", 3,-3,1.000000},
  {fuseki131196,3,"Fuseki1198",-4, 4,1.000000},
  {fuseki131197,4,"Fuseki1199", 4,-1,3.000000},
  {fuseki131198,4,"Fuseki1200", 2,-4,1.000000},
  {fuseki131199,4,"Fuseki1201", 4,-1,1.000000},
  {fuseki131200,4,"Fuseki1202",-4,-4,1.000000},
  {fuseki131201,4,"Fuseki1203", 0,-4,1.000000},
  {fuseki131202,5,"Fuseki1204",-4,-3,3.000000},
  {fuseki131203,5,"Fuseki1205",-4, 3,1.000000},
  {fuseki131204,5,"Fuseki1206",-1,-4,2.000000},
  {fuseki131205,5,"Fuseki1207", 3, 2,1.000000},
  {fuseki131206,5,"Fuseki1208", 3,-2,1.000000},
  {fuseki131207,2,"Fuseki1209",-3,-4,2.000000},
  {fuseki131208,2,"Fuseki1210", 4, 4,1.000000},
  {fuseki131209,2,"Fuseki1211",-3,-3,1.000000},
  {fuseki131210,3,"Fuseki1212", 4, 4,3.000000},
  {fuseki131211,3,"Fuseki1213",-4, 3,1.000000},
  {fuseki131212,6,"Fuseki1214",-4,-2,3.000000},
  {fuseki131213,6,"Fuseki1215",-1,-3,1.000000},
  {fuseki131214,5,"Fuseki1216", 1,-4,4.000000},
  {fuseki131215,5,"Fuseki1217",-2, 4,3.000000},
  {fuseki131216,5,"Fuseki1218", 1, 4,1.000000},
  {fuseki131217,2,"Fuseki1219", 3,-4,1.000000},
  {fuseki131218,2,"Fuseki1220", 4, 2,1.000000},
  {fuseki131219,2,"Fuseki1221", 4,-2,1.000000},
  {fuseki131220,2,"Fuseki1222", 3, 4,1.000000},
  {fuseki131221,4,"Fuseki1223", 4, 0,1.000000},
  {fuseki131222,4,"Fuseki1224", 4,-2,1.000000},
  {fuseki131223,4,"Fuseki1225", 3, 4,1.000000},
  {fuseki131224,4,"Fuseki1226", 3, 1,1.000000},
  {fuseki131225,2,"Fuseki1227", 4, 1,1.000000},
  {fuseki131226,2,"Fuseki1228",-2, 3,1.000000},
  {fuseki131227,2,"Fuseki1229",-3, 4,1.000000},
  {fuseki131228,2,"Fuseki1230",-3,-3,1.000000},
  {fuseki131229,6,"Fuseki1231", 2, 1,4.000000},
  {fuseki131230,9,"Fuseki1232", 4, 3,4.000000},
  {fuseki131231,4,"Fuseki1233", 4,-2,4.000000},
  {fuseki131232,6,"Fuseki1234",-4, 0,3.000000},
  {fuseki131233,6,"Fuseki1235",-3, 5,1.000000},
  {fuseki131234,2,"Fuseki1236", 4, 3,2.000000},
  {fuseki131235,2,"Fuseki1237",-4,-4,1.000000},
  {fuseki131236,2,"Fuseki1238", 3,-3,1.000000},
  {fuseki131237,3,"Fuseki1239",-4, 2,4.000000},
  {fuseki131238,3,"Fuseki1240", 2, 5,2.000000},
  {fuseki131239,3,"Fuseki1241",-2,-4,1.000000},
  {fuseki131240,3,"Fuseki1242",-2,-3,1.000000},
  {fuseki131241,3,"Fuseki1243",-4,-3,2.000000},
  {fuseki131242,3,"Fuseki1244", 4,-3,1.000000},
  {fuseki131243,3,"Fuseki1245",-3, 2,1.000000},
  {fuseki131244,5,"Fuseki1246", 4,-2,3.000000},
  {fuseki131245,5,"Fuseki1247", 4,-1,1.000000},
  {fuseki131246,6,"Fuseki1248", 0,-4,3.000000},
  {fuseki131247,6,"Fuseki1249",-3,-2,1.000000},
  {fuseki131248,4,"Fuseki1250",-3,-3,1.000000},
  {fuseki131249,4,"Fuseki1251", 4,-4,1.000000},
  {fuseki131250,4,"Fuseki1252",-1,-4,1.000000},
  {fuseki131251,4,"Fuseki1253", 3, 1,1.000000},
  {fuseki131252,3,"Fuseki1254", 4,-3,2.000000},
  {fuseki131253,3,"Fuseki1255",-4,-4,1.000000},
  {fuseki131254,3,"Fuseki1256", 4, 3,1.000000},
  {fuseki131255,3,"Fuseki1257", 3,-3,1.000000},
  {fuseki131256,3,"Fuseki1258", 4,-4,1.000000},
  {fuseki131257,3,"Fuseki1259", 3, 4,1.000000},
  {fuseki131258,3,"Fuseki1260",-4,-2,1.000000},
  {fuseki131259,6,"Fuseki1261", 4, 1,2.000000},
  {fuseki131260,6,"Fuseki1262",-2,-3,1.000000},
  {fuseki131261,6,"Fuseki1263",-3,-1,1.000000},
  {fuseki131262,4,"Fuseki1264", 0,-3,1.000000},
  {fuseki131263,4,"Fuseki1265", 3, 1,1.000000},
  {fuseki131264,4,"Fuseki1266", 4, 0,1.000000},
  {fuseki131265,4,"Fuseki1267",-3,-1,1.000000},
  {fuseki131266,4,"Fuseki1268", 3, 0,2.000000},
  {fuseki131267,4,"Fuseki1269", 2,-4,1.000000},
  {fuseki131268,4,"Fuseki1270", 4, 0,1.000000},
  {fuseki131269,5,"Fuseki1271",-5,-4,4.000000},
  {fuseki131270,7,"Fuseki1272",-4, 2,3.000000},
  {fuseki131271,7,"Fuseki1273", 4,-2,1.000000},
  {fuseki131272,5,"Fuseki1274",-1,-4,1.000000},
  {fuseki131273,5,"Fuseki1275", 0, 0,1.000000},
  {fuseki131274,5,"Fuseki1276",-4,-4,1.000000},
  {fuseki131275,5,"Fuseki1277", 0,-4,1.000000},
  {fuseki131276,6,"Fuseki1278",-3, 0,2.000000},
  {fuseki131277,6,"Fuseki1279", 1,-3,1.000000},
  {fuseki131278,6,"Fuseki1280", 3, 0,1.000000},
  {fuseki131279,3,"Fuseki1281",-3, 3,1.000000},
  {fuseki131280,3,"Fuseki1282", 4,-4,1.000000},
  {fuseki131281,3,"Fuseki1283", 4, 3,1.000000},
  {fuseki131282,3,"Fuseki1284", 2, 4,1.000000},
  {fuseki131283,3,"Fuseki1285", 3, 0,4.000000},
  {fuseki131284,4,"Fuseki1286",-4, 0,1.000000},
  {fuseki131285,4,"Fuseki1287", 0, 3,1.000000},
  {fuseki131286,4,"Fuseki1288", 1,-4,1.000000},
  {fuseki131287,4,"Fuseki1289", 0, 4,1.000000},
  {fuseki131288,7,"Fuseki1290", 4, 2,4.000000},
  {fuseki131289,4,"Fuseki1291", 3, 0,1.000000},
  {fuseki131290,4,"Fuseki1292",-4, 2,1.000000},
  {fuseki131291,4,"Fuseki1293", 0,-4,1.000000},
  {fuseki131292,4,"Fuseki1294", 4,-1,1.000000},
  {fuseki131293,3,"Fuseki1295", 4,-4,4.000000},
  {fuseki131294,5,"Fuseki1296", 4, 1,1.000000},
  {fuseki131295,5,"Fuseki1297",-3,-2,1.000000},
  {fuseki131296,5,"Fuseki1298", 2,-2,1.000000},
  {fuseki131297,5,"Fuseki1299",-4,-1,1.000000},
  {fuseki131298,3,"Fuseki1300",-4, 2,2.000000},
  {fuseki131299,3,"Fuseki1301",-3, 4,1.000000},
  {fuseki131300,3,"Fuseki1302",-2,-3,1.000000},
  {fuseki131301,4,"Fuseki1303", 2, 4,3.000000},
  {fuseki131302,4,"Fuseki1304", 3, 2,1.000000},
  {fuseki131303,2,"Fuseki1305",-3,-3,2.000000},
  {fuseki131304,2,"Fuseki1306",-3,-2,1.000000},
  {fuseki131305,2,"Fuseki1307", 2, 3,1.000000},
  {fuseki131306,4,"Fuseki1308", 0, 3,1.000000},
  {fuseki131307,4,"Fuseki1309",-1,-4,1.000000},
  {fuseki131308,4,"Fuseki1310", 1, 4,1.000000},
  {fuseki131309,4,"Fuseki1311",-2,-4,1.000000},
  {fuseki131310,4,"Fuseki1312", 0,-4,2.000000},
  {fuseki131311,4,"Fuseki1313", 0, 1,1.000000},
  {fuseki131312,4,"Fuseki1314", 2, 4,1.000000},
  {fuseki131313,4,"Fuseki1315", 4, 0,2.000000},
  {fuseki131314,4,"Fuseki1316",-1, 4,1.000000},
  {fuseki131315,4,"Fuseki1317",-3,-2,1.000000},
  {fuseki131316,6,"Fuseki1318", 3,-5,2.000000},
  {fuseki131317,6,"Fuseki1319", 4, 1,1.000000},
  {fuseki131318,6,"Fuseki1320", 3,-4,1.000000},
  {fuseki131319,4,"Fuseki1321", 0, 3,1.000000},
  {fuseki131320,4,"Fuseki1322", 4, 1,1.000000},
  {fuseki131321,4,"Fuseki1323", 4, 3,1.000000},
  {fuseki131322,4,"Fuseki1324", 3, 5,1.000000},
  {fuseki131323,4,"Fuseki1325",-2, 4,3.000000},
  {fuseki131324,4,"Fuseki1326", 0,-4,1.000000},
  {fuseki131325,4,"Fuseki1327",-2,-3,1.000000},
  {fuseki131326,4,"Fuseki1328", 4, 2,1.000000},
  {fuseki131327,4,"Fuseki1329", 0, 4,1.000000},
  {fuseki131328,4,"Fuseki1330",-1, 4,1.000000},
  {fuseki131329,4,"Fuseki1331", 3,-3,1.000000},
  {fuseki131330,4,"Fuseki1332",-2,-1,1.000000},
  {fuseki131331,4,"Fuseki1333", 2, 2,1.000000},
  {fuseki131332,4,"Fuseki1334", 3, 3,1.000000},
  {fuseki131333,5,"Fuseki1335", 4,-2,2.000000},
  {fuseki131334,5,"Fuseki1336", 4,-4,1.000000},
  {fuseki131335,5,"Fuseki1337", 1,-4,1.000000},
  {fuseki131336,4,"Fuseki1338", 4,-2,1.000000},
  {fuseki131337,4,"Fuseki1339",-3,-2,1.000000},
  {fuseki131338,4,"Fuseki1340",-4, 1,1.000000},
  {fuseki131339,4,"Fuseki1341", 4,-1,1.000000},
  {fuseki131340,5,"Fuseki1342", 3, 2,4.000000},
  {fuseki131341,4,"Fuseki1343", 2, 4,2.000000},
  {fuseki131342,4,"Fuseki1344",-1,-4,1.000000},
  {fuseki131343,4,"Fuseki1345",-3, 0,1.000000},
  {fuseki131344,8,"Fuseki1346", 1, 3,2.000000},
  {fuseki131345,8,"Fuseki1347", 5, 1,2.000000},
  {fuseki131346,5,"Fuseki1348", 2,-4,1.000000},
  {fuseki131347,5,"Fuseki1349", 4, 1,1.000000},
  {fuseki131348,5,"Fuseki1350",-4,-1,1.000000},
  {fuseki131349,5,"Fuseki1351",-3,-2,1.000000},
  {fuseki131350,5,"Fuseki1352", 4,-1,3.000000},
  {fuseki131351,5,"Fuseki1353", 4, 0,1.000000},
  {fuseki131352,5,"Fuseki1354",-4,-2,2.000000},
  {fuseki131353,5,"Fuseki1355",-3, 2,1.000000},
  {fuseki131354,5,"Fuseki1356",-4, 2,1.000000},
  {fuseki131355,4,"Fuseki1357",-2, 4,1.000000},
  {fuseki131356,4,"Fuseki1358",-4,-2,1.000000},
  {fuseki131357,4,"Fuseki1359", 1,-4,1.000000},
  {fuseki131358,4,"Fuseki1360", 4,-4,1.000000},
  {fuseki131359,6,"Fuseki1361",-3,-3,2.000000},
  {fuseki131360,6,"Fuseki1362",-3, 3,1.000000},
  {fuseki131361,6,"Fuseki1363",-3, 4,1.000000},
  {fuseki131362,6,"Fuseki1364",-3, 0,2.000000},
  {fuseki131363,6,"Fuseki1365",-5,-3,2.000000},
  {fuseki131364,5,"Fuseki1366", 3,-4,2.000000},
  {fuseki131365,5,"Fuseki1367",-4, 0,1.000000},
  {fuseki131366,5,"Fuseki1368", 3,-2,1.000000},
  {fuseki131367,6,"Fuseki1369", 4,-1,3.000000},
  {fuseki131368,6,"Fuseki1370",-2, 4,1.000000},
  {fuseki131369,3,"Fuseki1371", 4,-3,2.000000},
  {fuseki131370,3,"Fuseki1372",-4, 0,1.000000},
  {fuseki131371,5,"Fuseki1373", 4,-2,3.000000},
  {fuseki131372,6,"Fuseki1374", 2,-4,3.000000},
  {fuseki131373,4,"Fuseki1375", 4,-2,2.000000},
  {fuseki131374,4,"Fuseki1376",-2,-3,1.000000},
  {fuseki131375,1,"Fuseki1377", 4, 5,1.000000},
  {fuseki131376,1,"Fuseki1378",-5,-5,1.000000},
  {fuseki131377,1,"Fuseki1379", 6,-3,1.000000},
  {fuseki131378,1,"Fuseki1380",-4,-4,2.000000},
  {fuseki131379,3,"Fuseki1381",-4, 4,2.000000},
  {fuseki131380,3,"Fuseki1382",-3, 3,1.000000},
  {fuseki131381,4,"Fuseki1383",-2,-3,2.000000},
  {fuseki131382,4,"Fuseki1384", 3, 3,1.000000},
  {fuseki131383,2,"Fuseki1385", 4, 4,1.000000},
  {fuseki131384,2,"Fuseki1386", 3, 3,1.000000},
  {fuseki131385,2,"Fuseki1387", 4, 3,1.000000},
  {fuseki131386,9,"Fuseki1388", 3, 4,3.000000},
  {fuseki131387,4,"Fuseki1389", 4,-1,1.000000},
  {fuseki131388,4,"Fuseki1390",-4,-1,1.000000},
  {fuseki131389,4,"Fuseki1391",-4, 0,1.000000},
  {fuseki131390,3,"Fuseki1392", 2, 1,2.000000},
  {fuseki131391,3,"Fuseki1393",-4,-4,1.000000},
  {fuseki131392,5,"Fuseki1394", 1,-4,2.000000},
  {fuseki131393,5,"Fuseki1395", 3, 2,1.000000},
  {fuseki131394,6,"Fuseki1396", 4, 2,2.000000},
  {fuseki131395,6,"Fuseki1397",-2,-1,1.000000},
  {fuseki131396,3,"Fuseki1398", 3,-4,1.000000},
  {fuseki131397,3,"Fuseki1399", 4, 4,1.000000},
  {fuseki131398,3,"Fuseki1400", 3,-3,1.000000},
  {fuseki131399,3,"Fuseki1401", 3, 4,2.000000},
  {fuseki131400,3,"Fuseki1402",-4, 3,1.000000},
  {fuseki131401,7,"Fuseki1403",-4,-1,2.000000},
  {fuseki131402,7,"Fuseki1404",-3,-3,1.000000},
  {fuseki131403,4,"Fuseki1405", 3,-3,1.000000},
  {fuseki131404,4,"Fuseki1406", 4, 3,1.000000},
  {fuseki131405,4,"Fuseki1407", 4, 4,1.000000},
  {fuseki131406,2,"Fuseki1408",-3, 2,1.000000},
  {fuseki131407,2,"Fuseki1409",-2,-3,1.000000},
  {fuseki131408,2,"Fuseki1410", 3,-3,1.000000},
  {fuseki131409,4,"Fuseki1411", 4,-2,1.000000},
  {fuseki131410,4,"Fuseki1412",-4,-1,1.000000},
  {fuseki131411,4,"Fuseki1413",-4,-1,1.000000},
  {fuseki131412,3,"Fuseki1414",-3,-3,1.000000},
  {fuseki131413,3,"Fuseki1415",-1, 4,1.000000},
  {fuseki131414,3,"Fuseki1416", 2, 3,1.000000},
  {fuseki131415,4,"Fuseki1417", 4, 0,2.000000},
  {fuseki131416,4,"Fuseki1418", 4,-1,1.000000},
  {fuseki131417,7,"Fuseki1419", 4,-2,2.000000},
  {fuseki131418,7,"Fuseki1420", 4, 1,1.000000},
  {fuseki131419,4,"Fuseki1421", 0, 0,1.000000},
  {fuseki131420,4,"Fuseki1422", 1,-4,1.000000},
  {fuseki131421,5,"Fuseki1423",-1,-4,1.000000},
  {fuseki131422,5,"Fuseki1424",-1,-3,1.000000},
  {fuseki131423,5,"Fuseki1425", 4,-1,1.000000},
  {fuseki131424,3,"Fuseki1426", 3,-4,1.000000},
  {fuseki131425,3,"Fuseki1427", 4, 3,1.000000},
  {fuseki131426,3,"Fuseki1428",-3, 0,1.000000},
  {fuseki131427,2,"Fuseki1429",-2,-4,1.000000},
  {fuseki131428,2,"Fuseki1430",-3,-4,1.000000},
  {fuseki131429,2,"Fuseki1431", 3,-3,1.000000},
  {fuseki131430,5,"Fuseki1432",-1,-4,3.000000},
  {fuseki131431,1,"Fuseki1433",-4,-3,2.000000},
  {fuseki131432,1,"Fuseki1434", 4, 3,1.000000},
  {fuseki131433,4,"Fuseki1435", 0, 3,1.000000},
  {fuseki131434,4,"Fuseki1436", 1,-3,1.000000},
  {fuseki131435,4,"Fuseki1437",-4, 2,1.000000},
  {fuseki131436,8,"Fuseki1438", 3, 4,1.000000},
  {fuseki131437,8,"Fuseki1439", 3, 0,1.000000},
  {fuseki131438,8,"Fuseki1440", 0, 4,1.000000},
  {fuseki131439,6,"Fuseki1441", 5,-3,1.000000},
  {fuseki131440,6,"Fuseki1442", 2,-4,1.000000},
  {fuseki131441,6,"Fuseki1443", 3,-4,1.000000},
  {fuseki131442,5,"Fuseki1444", 4, 2,3.000000},
  {fuseki131443,5,"Fuseki1445",-3,-2,2.000000},
  {fuseki131444,5,"Fuseki1446",-4,-4,1.000000},
  {fuseki131445,4,"Fuseki1447",-1,-4,1.000000},
  {fuseki131446,4,"Fuseki1448", 1,-3,1.000000},
  {fuseki131447,4,"Fuseki1449",-4,-2,1.000000},
  {fuseki131448,6,"Fuseki1450", 4, 4,2.000000},
  {fuseki131449,6,"Fuseki1451",-3, 3,1.000000},
  {fuseki131450,3,"Fuseki1452", 3,-4,2.000000},
  {fuseki131451,3,"Fuseki1453",-2,-4,1.000000},
  {fuseki131452,5,"Fuseki1454", 4, 0,2.000000},
  {fuseki131453,5,"Fuseki1455", 4, 1,1.000000},
  {fuseki131454,6,"Fuseki1456",-1,-4,1.000000},
  {fuseki131455,6,"Fuseki1457", 3, 0,1.000000},
  {fuseki131456,6,"Fuseki1458",-3, 3,1.000000},
  {fuseki131457,4,"Fuseki1459", 4,-3,3.000000},
  {fuseki131458,6,"Fuseki1460", 4, 3,2.000000},
  {fuseki131459,6,"Fuseki1461", 3, 3,1.000000},
  {fuseki131460,4,"Fuseki1462", 4,-3,2.000000},
  {fuseki131461,4,"Fuseki1463", 3, 0,1.000000},
  {fuseki131462,6,"Fuseki1464",-4, 1,1.000000},
  {fuseki131463,6,"Fuseki1465",-4, 0,1.000000},
  {fuseki131464,6,"Fuseki1466", 4,-1,1.000000},
  {fuseki131465,5,"Fuseki1467", 4, 2,1.000000},
  {fuseki131466,5,"Fuseki1468",-3, 2,1.000000},
  {fuseki131467,5,"Fuseki1469",-4, 4,1.000000},
  {fuseki131468,5,"Fuseki1470",-2,-4,3.000000},
  {fuseki131469,4,"Fuseki1471", 0,-4,1.000000},
  {fuseki131470,4,"Fuseki1472",-2, 3,1.000000},
  {fuseki131471,4,"Fuseki1473",-3,-1,1.000000},
  {fuseki131472,4,"Fuseki1474",-4,-2,1.000000},
  {fuseki131473,4,"Fuseki1475",-3, 2,1.000000},
  {fuseki131474,4,"Fuseki1476", 4, 1,1.000000},
  {fuseki131475,5,"Fuseki1477",-4, 0,1.000000},
  {fuseki131476,5,"Fuseki1478",-4, 0,1.000000},
  {fuseki131477,5,"Fuseki1479",-1,-3,1.000000},
  {fuseki131478,2,"Fuseki1480", 4,-4,3.000000},
  {fuseki131479,5,"Fuseki1481", 2,-3,3.000000},
  {fuseki131480,5,"Fuseki1482", 1,-4,1.000000},
  {fuseki131481,5,"Fuseki1483", 4, 3,1.000000},
  {fuseki131482,5,"Fuseki1484", 0, 4,1.000000},
  {fuseki131483,2,"Fuseki1485", 4, 4,1.000000},
  {fuseki131484,2,"Fuseki1486", 3,-2,1.000000},
  {fuseki131485,2,"Fuseki1487",-3,-4,1.000000},
  {fuseki131486,5,"Fuseki1488", 2,-3,1.000000},
  {fuseki131487,5,"Fuseki1489", 2,-4,1.000000},
  {fuseki131488,5,"Fuseki1490", 1,-3,1.000000},
  {fuseki131489,6,"Fuseki1491", 3,-3,2.000000},
  {fuseki131490,6,"Fuseki1492", 4,-1,1.000000},
  {fuseki131491,3,"Fuseki1493",-2,-4,2.000000},
  {fuseki131492,3,"Fuseki1494",-4, 4,1.000000},
  {fuseki131493,7,"Fuseki1495",-4, 0,1.000000},
  {fuseki131494,7,"Fuseki1496", 1, 4,1.000000},
  {fuseki131495,7,"Fuseki1497", 1, 3,1.000000},
  {fuseki131496,7,"Fuseki1498", 3,-2,2.000000},
  {fuseki131497,7,"Fuseki1499", 3,-3,1.000000},
  {fuseki131498,5,"Fuseki1500", 4,-2,3.000000},
  {fuseki131499,7,"Fuseki1501",-2,-2,2.000000},
  {fuseki131500,7,"Fuseki1502",-2,-4,1.000000},
  {fuseki131501,5,"Fuseki1503",-4, 0,1.000000},
  {fuseki131502,5,"Fuseki1504", 4, 0,1.000000},
  {fuseki131503,5,"Fuseki1505",-1, 0,1.000000},
  {fuseki131504,9,"Fuseki1506", 4,-4,3.000000},
  {fuseki131505,1,"Fuseki1507",-4,-3,2.000000},
  {fuseki131506,1,"Fuseki1508", 4,-4,1.000000},
  {fuseki131507,7,"Fuseki1509", 4, 3,3.000000},
  {fuseki131508,6,"Fuseki1510",-3,-4,2.000000},
  {fuseki131509,6,"Fuseki1511", 3,-2,1.000000},
  {fuseki131510,5,"Fuseki1512",-3,-2,1.000000},
  {fuseki131511,5,"Fuseki1513", 3, 0,1.000000},
  {fuseki131512,5,"Fuseki1514",-4, 1,1.000000},
  {fuseki131513,5,"Fuseki1515", 1, 4,2.000000},
  {fuseki131514,5,"Fuseki1516", 4, 2,1.000000},
  {fuseki131515,5,"Fuseki1517",-4, 1,2.000000},
  {fuseki131516,5,"Fuseki1518", 3, 1,1.000000},
  {fuseki131517,3,"Fuseki1519", 4, 3,2.000000},
  {fuseki131518,3,"Fuseki1520",-4,-4,1.000000},
  {fuseki131519,6,"Fuseki1521",-2, 4,3.000000},
  {fuseki131520,4,"Fuseki1522", 4, 1,2.000000},
  {fuseki131521,4,"Fuseki1523",-4,-2,1.000000},
  {fuseki131522,2,"Fuseki1524", 4,-2,1.000000},
  {fuseki131523,2,"Fuseki1525", 0, 0,1.000000},
  {fuseki131524,2,"Fuseki1526", 2,-1,1.000000},
  {fuseki131525,2,"Fuseki1527",-3,-3,2.000000},
  {fuseki131526,2,"Fuseki1528", 4,-3,1.000000},
  {fuseki131527,7,"Fuseki1529", 2, 3,3.000000},
  {fuseki131528,4,"Fuseki1530", 5, 2,1.000000},
  {fuseki131529,4,"Fuseki1531", 4, 3,1.000000},
  {fuseki131530,4,"Fuseki1532",-4, 5,1.000000},
  {fuseki131531,4,"Fuseki1533",-3, 1,2.000000},
  {fuseki131532,4,"Fuseki1534",-3, 1,1.000000},
  {fuseki131533,4,"Fuseki1535", 0,-3,2.000000},
  {fuseki131534,4,"Fuseki1536", 4, 3,1.000000},
  {fuseki131535,6,"Fuseki1537", 1,-4,1.000000},
  {fuseki131536,6,"Fuseki1538",-3,-3,1.000000},
  {fuseki131537,6,"Fuseki1539", 0, 4,1.000000},
  {fuseki131538,3,"Fuseki1540", 3,-3,1.000000},
  {fuseki131539,3,"Fuseki1541",-1,-4,1.000000},
  {fuseki131540,3,"Fuseki1542",-4, 4,1.000000},
  {fuseki131541,8,"Fuseki1543",-5, 2,3.000000},
  {fuseki131542,2,"Fuseki1544",-2, 3,2.000000},
  {fuseki131543,7,"Fuseki1545",-3, 3,2.000000},
  {fuseki131544,7,"Fuseki1546",-4,-1,1.000000},
  {fuseki131545,6,"Fuseki1547", 3, 1,3.000000},
  {fuseki131546,3,"Fuseki1548", 4, 2,2.000000},
  {fuseki131547,3,"Fuseki1549",-4, 4,1.000000},
  {fuseki131548,9,"Fuseki1550",-4, 4,1.000000},
  {fuseki131549,9,"Fuseki1551", 4,-2,1.000000},
  {fuseki131550,9,"Fuseki1552", 3,-2,1.000000},
  {fuseki131551,4,"Fuseki1553",-2,-4,2.000000},
  {fuseki131552,4,"Fuseki1554",-4, 0,1.000000},
  {fuseki131553,6,"Fuseki1555",-3,-4,2.000000},
  {fuseki131554,6,"Fuseki1556", 0,-3,1.000000},
  {fuseki131555,4,"Fuseki1557",-4,-4,3.000000},
  {fuseki131556,5,"Fuseki1558", 4, 1,2.000000},
  {fuseki131557,5,"Fuseki1559",-4, 1,1.000000},
  {fuseki131558,2,"Fuseki1560",-3,-4,2.000000},
  {fuseki131559,2,"Fuseki1561", 3, 3,1.000000},
  {fuseki131560,5,"Fuseki1562", 4, 1,2.000000},
  {fuseki131561,5,"Fuseki1563", 2,-4,1.000000},
  {fuseki131562,3,"Fuseki1564",-4,-4,2.000000},
  {fuseki131563,3,"Fuseki1565", 3,-3,1.000000},
  {fuseki131564,6,"Fuseki1566", 1,-4,2.000000},
  {fuseki131565,6,"Fuseki1567",-2, 4,1.000000},
  {fuseki131566,5,"Fuseki1568", 3,-2,2.000000},
  {fuseki131567,5,"Fuseki1569", 1,-4,1.000000},
  {fuseki131568,3,"Fuseki1570", 2, 4,1.000000},
  {fuseki131569,3,"Fuseki1571",-2,-4,1.000000},
  {fuseki131570,3,"Fuseki1572",-4, 4,1.000000},
  {fuseki131571,8,"Fuseki1573", 3, 0,3.000000},
  {fuseki131572,6,"Fuseki1574", 4,-2,2.000000},
  {fuseki131573,6,"Fuseki1575", 4, 0,1.000000},
  {fuseki131574,3,"Fuseki1576", 3,-3,2.000000},
  {fuseki131575,3,"Fuseki1577", 4,-4,1.000000},
  {fuseki131576,3,"Fuseki1578", 4,-4,1.000000},
  {fuseki131577,3,"Fuseki1579", 4, 1,1.000000},
  {fuseki131578,3,"Fuseki1580", 3,-4,1.000000},
  {fuseki131579,5,"Fuseki1581",-2, 4,2.000000},
  {fuseki131580,5,"Fuseki1582",-3, 2,1.000000},
  {fuseki131581,2,"Fuseki1583",-4, 3,1.000000},
  {fuseki131582,2,"Fuseki1584",-3, 3,1.000000},
  {fuseki131583,2,"Fuseki1585",-4, 3,1.000000},
  {fuseki131584,5,"Fuseki1586", 4,-1,2.000000},
  {fuseki131585,5,"Fuseki1587", 1, 4,1.000000},
  {fuseki131586,3,"Fuseki1588",-3, 4,1.000000},
  {fuseki131587,3,"Fuseki1589",-3, 4,1.000000},
  {fuseki131588,3,"Fuseki1590", 4, 4,1.000000},
  {fuseki131589,3,"Fuseki1591", 3, 3,1.000000},
  {fuseki131590,3,"Fuseki1592",-4, 4,1.000000},
  {fuseki131591,3,"Fuseki1593",-4, 3,1.000000},
  {fuseki131592,3,"Fuseki1594", 0, 4,1.000000},
  {fuseki131593,3,"Fuseki1595",-3, 0,1.000000},
  {fuseki131594,3,"Fuseki1596",-2, 2,1.000000},
  {fuseki131595,2,"Fuseki1597",-4,-4,2.000000},
  {fuseki131596,2,"Fuseki1598",-3, 2,1.000000},
  {fuseki131597,4,"Fuseki1599",-3,-3,1.000000},
  {fuseki131598,4,"Fuseki1600", 2, 4,1.000000},
  {fuseki131599,4,"Fuseki1601", 4,-2,1.000000},
  {fuseki131600,4,"Fuseki1602",-1, 4,1.000000},
  {fuseki131601,4,"Fuseki1603", 1,-4,1.000000},
  {fuseki131602,4,"Fuseki1604", 4, 2,1.000000},
  {fuseki131603,8,"Fuseki1605", 2,-4,3.000000},
  {fuseki131604,2,"Fuseki1606", 2, 4,1.000000},
  {fuseki131605,2,"Fuseki1607",-4,-4,1.000000},
  {fuseki131606,2,"Fuseki1608",-4, 3,1.000000},
  {fuseki131607,6,"Fuseki1609", 3,-3,3.000000},
  {fuseki131608,6,"Fuseki1610", 2, 3,3.000000},
  {fuseki131609,4,"Fuseki1611", 1, 3,3.000000},
  {fuseki131610,7,"Fuseki1612", 4,-3,3.000000},
  {fuseki131611,3,"Fuseki1613", 4,-4,2.000000},
  {fuseki131612,3,"Fuseki1614",-4,-3,1.000000},
  {fuseki131613,4,"Fuseki1615",-3, 1,1.000000},
  {fuseki131614,4,"Fuseki1616",-4,-2,1.000000},
  {fuseki131615,4,"Fuseki1617",-3,-2,1.000000},
  {fuseki131616,5,"Fuseki1618", 2, 3,2.000000},
  {fuseki131617,5,"Fuseki1619", 4, 2,1.000000},
  {fuseki131618,6,"Fuseki1620",-4,-3,2.000000},
  {fuseki131619,6,"Fuseki1621", 4, 1,1.000000},
  {fuseki131620,4,"Fuseki1622",-5, 1,1.000000},
  {fuseki131621,4,"Fuseki1623",-4,-2,1.000000},
  {fuseki131622,3,"Fuseki1624", 3,-4,2.000000},
  {fuseki131623,3,"Fuseki1625", 3,-4,1.000000},
  {fuseki131624,3,"Fuseki1626", 3,-4,1.000000},
  {fuseki131625,3,"Fuseki1627",-4, 4,1.000000},
  {fuseki131626,3,"Fuseki1628", 4,-1,1.000000},
  {fuseki131627,4,"Fuseki1629",-1, 4,1.000000},
  {fuseki131628,4,"Fuseki1630", 4,-2,1.000000},
  {fuseki131629,4,"Fuseki1631", 4, 2,1.000000},
  {fuseki131630,4,"Fuseki1632",-4, 1,1.000000},
  {fuseki131631,4,"Fuseki1633",-4, 0,1.000000},
  {fuseki131632,6,"Fuseki1634", 0, 3,1.000000},
  {fuseki131633,6,"Fuseki1635",-4, 0,1.000000},
  {fuseki131634,3,"Fuseki1636", 4,-4,1.000000},
  {fuseki131635,3,"Fuseki1637", 2, 4,1.000000},
  {fuseki131636,4,"Fuseki1638", 3,-1,1.000000},
  {fuseki131637,4,"Fuseki1639", 3, 3,1.000000},
  {fuseki131638,4,"Fuseki1640", 1, 5,1.000000},
  {fuseki131639,4,"Fuseki1641",-4, 0,1.000000},
  {fuseki131640,9,"Fuseki1642", 4, 0,2.000000},
  {fuseki131641,7,"Fuseki1643", 3, 0,2.000000},
  {fuseki131642,5,"Fuseki1644", 1, 3,2.000000},
  {fuseki131643,4,"Fuseki1645", 2, 4,2.000000},
  {fuseki131644,9,"Fuseki1646", 4, 4,2.000000},
  {fuseki131645,9,"Fuseki1647", 5,-3,1.000000},
  {fuseki131646,9,"Fuseki1648", 4,-2,1.000000},
  {fuseki131647,5,"Fuseki1649", 4,-1,2.000000},
  {fuseki131648,6,"Fuseki1650",-3,-1,1.000000},
  {fuseki131649,6,"Fuseki1651",-2,-4,1.000000},
  {fuseki131650,4,"Fuseki1652", 1, 3,2.000000},
  {fuseki131651,9,"Fuseki1653", 2, 1,2.000000},
  {fuseki131652,4,"Fuseki1654",-4,-1,1.000000},
  {fuseki131653,4,"Fuseki1655",-2, 4,1.000000},
  {fuseki131654,5,"Fuseki1656", 1, 3,1.000000},
  {fuseki131655,5,"Fuseki1657", 0,-3,1.000000},
  {fuseki131656,6,"Fuseki1658", 4,-2,1.000000},
  {fuseki131657,6,"Fuseki1659", 0,-3,1.000000},
  {fuseki131658,3,"Fuseki1660",-3, 3,1.000000},
  {fuseki131659,3,"Fuseki1661", 2,-3,1.000000},
  {fuseki131660,5,"Fuseki1662",-4, 2,1.000000},
  {fuseki131661,5,"Fuseki1663",-4, 2,1.000000},
  {fuseki131662,4,"Fuseki1664",-3, 3,1.000000},
  {fuseki131663,4,"Fuseki1665",-3, 4,1.000000},
  {fuseki131664,5,"Fuseki1666",-4,-2,2.000000},
  {fuseki131665,9,"Fuseki1667", 2,-3,2.000000},
  {fuseki131666,9,"Fuseki1668",-4, 2,2.000000},
  {fuseki131667,7,"Fuseki1669", 2, 4,2.000000},
  {fuseki131668,5,"Fuseki1670",-3,-1,1.000000},
  {fuseki131669,5,"Fuseki1671",-4,-2,1.000000},
  {fuseki131670,6,"Fuseki1672",-1, 2,2.000000},
  {fuseki131671,3,"Fuseki1673", 4, 0,1.000000},
  {fuseki131672,3,"Fuseki1674", 3, 4,1.000000},
  {fuseki131673,8,"Fuseki1675", 2,-2,1.000000},
  {fuseki131674,8,"Fuseki1676",-3, 3,1.000000},
  {fuseki131675,4,"Fuseki1677",-4,-4,1.000000},
  {fuseki131676,4,"Fuseki1678", 3, 0,1.000000},
  {fuseki131677,4,"Fuseki1679",-4,-1,1.000000},
  {fuseki131678,4,"Fuseki1680", 4, 1,1.000000},
  {fuseki131679,6,"Fuseki1681", 1, 4,2.000000},
  {fuseki131680,4,"Fuseki1682", 2,-4,2.000000},
  {fuseki131681,4,"Fuseki1683", 4,-3,2.000000},
  {fuseki131682,5,"Fuseki1684",-4, 1,1.000000},
  {fuseki131683,5,"Fuseki1685", 1, 4,1.000000},
  {fuseki131684,4,"Fuseki1686",-1, 4,1.000000},
  {fuseki131685,4,"Fuseki1687", 4,-2,1.000000},
  {fuseki131686,2,"Fuseki1688",-4,-3,1.000000},
  {fuseki131687,2,"Fuseki1689",-2,-4,1.000000},
  {fuseki131688,7,"Fuseki1690", 4,-3,2.000000},
  {fuseki131689,7,"Fuseki1691",-1,-2,1.000000},
  {fuseki131690,7,"Fuseki1692", 4,-4,1.000000},
  {fuseki131691,2,"Fuseki1693", 3,-3,1.000000},
  {fuseki131692,2,"Fuseki1694", 0,-3,1.000000},
  {fuseki131693,3,"Fuseki1695",-4,-4,1.000000},
  {fuseki131694,3,"Fuseki1696",-2, 4,1.000000},
  {fuseki131695,5,"Fuseki1697",-4,-2,1.000000},
  {fuseki131696,5,"Fuseki1698",-2, 3,1.000000},
  {fuseki131697,5,"Fuseki1699",-2,-2,1.000000},
  {fuseki131698,5,"Fuseki1700", 3,-4,1.000000},
  {fuseki131699,3,"Fuseki1701",-3, 3,1.000000},
  {fuseki131700,3,"Fuseki1702", 4, 4,1.000000},
  {fuseki131701,2,"Fuseki1703", 3, 2,1.000000},
  {fuseki131702,2,"Fuseki1704",-2, 4,1.000000},
  {fuseki131703,4,"Fuseki1705", 4, 0,1.000000},
  {fuseki131704,4,"Fuseki1706", 3,-1,1.000000},
  {fuseki131705,3,"Fuseki1707", 3,-4,1.000000},
  {fuseki131706,3,"Fuseki1708",-4,-4,1.000000},
  {fuseki131707,6,"Fuseki1709", 3, 2,2.000000},
  {fuseki131708,3,"Fuseki1710",-4,-2,1.000000},
  {fuseki131709,3,"Fuseki1711",-3, 4,1.000000},
  {fuseki131710,5,"Fuseki1712",-4, 1,1.000000},
  {fuseki131711,5,"Fuseki1713",-3, 2,1.000000},
  {fuseki131712,5,"Fuseki1714",-3,-4,2.000000},
  {fuseki131713,3,"Fuseki1715",-2,-4,1.000000},
  {fuseki131714,3,"Fuseki1716", 4,-3,1.000000},
  {fuseki131715,6,"Fuseki1717", 3,-1,1.000000},
  {fuseki131716,6,"Fuseki1718",-1, 4,1.000000},
  {fuseki131717,6,"Fuseki1719", 5, 3,2.000000},
  {fuseki131718,5,"Fuseki1720", 4,-3,2.000000},
  {fuseki131719,5,"Fuseki1721",-2, 4,1.000000},
  {fuseki131720,5,"Fuseki1722", 4,-1,1.000000},
  {fuseki131721,4,"Fuseki1723", 2,-3,1.000000},
  {fuseki131722,4,"Fuseki1724", 4, 4,1.000000},
  {fuseki131723,6,"Fuseki1725", 4, 2,1.000000},
  {fuseki131724,6,"Fuseki1726", 5,-1,1.000000},
  {fuseki131725,7,"Fuseki1727", 4,-4,1.000000},
  {fuseki131726,7,"Fuseki1728",-4, 1,1.000000},
  {fuseki131727,8,"Fuseki1729", 2,-4,2.000000},
  {fuseki131728,3,"Fuseki1730",-4,-3,1.000000},
  {fuseki131729,3,"Fuseki1731",-4,-3,1.000000},
  {fuseki131730,5,"Fuseki1732", 3, 3,2.000000},
  {fuseki131731,6,"Fuseki1733",-6, 1,1.000000},
  {fuseki131732,6,"Fuseki1734", 4, 1,1.000000},
  {fuseki131733,7,"Fuseki1735", 4, 1,2.000000},
  {fuseki131734,7,"Fuseki1736",-4, 1,1.000000},
  {fuseki131735,7,"Fuseki1737", 2, 3,1.000000},
  {fuseki131736,5,"Fuseki1738", 2, 4,1.000000},
  {fuseki131737,5,"Fuseki1739",-4,-2,1.000000},
  {fuseki131738,7,"Fuseki1740",-2, 1,2.000000},
  {fuseki131739,3,"Fuseki1741", 4,-4,2.000000},
  {fuseki131740,6,"Fuseki1742", 4,-5,1.000000},
  {fuseki131741,6,"Fuseki1743", 1, 4,1.000000},
  {fuseki131742,4,"Fuseki1744", 2, 3,1.000000},
  {fuseki131743,4,"Fuseki1745",-3,-3,1.000000},
  {fuseki131744,4,"Fuseki1746", 3, 0,1.000000},
  {fuseki131745,4,"Fuseki1747",-4,-1,1.000000},
  {fuseki131746,4,"Fuseki1748", 3, 4,1.000000},
  {fuseki131747,4,"Fuseki1749",-1, 4,1.000000},
  {fuseki131748,8,"Fuseki1750", 3, 1,2.000000},
  {fuseki131749,5,"Fuseki1751", 4, 4,1.000000},
  {fuseki131750,5,"Fuseki1752",-4, 1,1.000000},
  {fuseki131751,6,"Fuseki1753", 2, 4,2.000000},
  {fuseki131752,6,"Fuseki1754", 3,-1,2.000000},
  {fuseki131753,6,"Fuseki1755", 2, 2,1.000000},
  {fuseki131754,6,"Fuseki1756",-3,-1,1.000000},
  {fuseki131755,9,"Fuseki1757", 1,-5,2.000000},
  {fuseki131756,6,"Fuseki1758",-5, 2,1.000000},
  {fuseki131757,6,"Fuseki1759",-3, 2,1.000000},
  {fuseki131758,5,"Fuseki1760",-2,-3,2.000000},
  {fuseki131759,6,"Fuseki1761", 4,-2,1.000000},
  {fuseki131760,6,"Fuseki1762", 3, 0,1.000000},
  {fuseki131761,3,"Fuseki1763",-2,-3,1.000000},
  {fuseki131762,3,"Fuseki1764",-3, 4,1.000000},
  {fuseki131763,5,"Fuseki1765", 3, 1,1.000000},
  {fuseki131764,5,"Fuseki1766", 1,-4,1.000000},
  {fuseki131765,9,"Fuseki1767", 1, 4,1.000000},
  {fuseki131766,9,"Fuseki1768",-1, 4,1.000000},
  {fuseki131767,5,"Fuseki1769", 2, 0,2.000000},
  {fuseki131768,5,"Fuseki1770",-4,-3,1.000000},
  {fuseki131769,5,"Fuseki1771",-3,-4,1.000000},
  {fuseki131770,6,"Fuseki1772",-4,-2,1.000000},
  {fuseki131771,6,"Fuseki1773", 4, 2,1.000000},
  {fuseki131772,3,"Fuseki1774", 3, 3,1.000000},
  {fuseki131773,3,"Fuseki1775",-3, 3,1.000000},
  {fuseki131774,3,"Fuseki1776", 4,-3,1.000000},
  {fuseki131775,3,"Fuseki1777", 1,-3,1.000000},
  {fuseki131776,9,"Fuseki1778", 4, 4,2.000000},
  {fuseki131777,5,"Fuseki1779", 0, 4,2.000000},
  {fuseki131778,4,"Fuseki1780", 0,-3,1.000000},
  {fuseki131779,4,"Fuseki1781",-3,-2,1.000000},
  {fuseki131780,8,"Fuseki1782", 2, 3,2.000000},
  {fuseki131781,3,"Fuseki1783",-3,-3,1.000000},
  {fuseki131782,3,"Fuseki1784",-3,-4,1.000000},
  {fuseki131783,3,"Fuseki1785",-4,-4,1.000000},
  {fuseki131784,3,"Fuseki1786",-5,-4,1.000000},
  {fuseki131785,5,"Fuseki1787",-4, 2,2.000000},
  {fuseki131786,5,"Fuseki1788", 4,-3,1.000000},
  {fuseki131787,5,"Fuseki1789", 3, 4,1.000000},
  {fuseki131788,9,"Fuseki1790", 2,-3,2.000000},
  {fuseki131789,4,"Fuseki1791",-1, 4,2.000000},
  {fuseki131790,5,"Fuseki1792",-2,-3,1.000000},
  {fuseki131791,5,"Fuseki1793", 4,-3,1.000000},
  {fuseki131792,3,"Fuseki1794", 0,-4,1.000000},
  {fuseki131793,3,"Fuseki1795",-2,-2,1.000000},
  {fuseki131794,9,"Fuseki1796", 0, 3,1.000000},
  {fuseki131795,9,"Fuseki1797",-2,-3,1.000000},
  {fuseki131796,8,"Fuseki1798", 0, 3,2.000000},
  {fuseki131797,6,"Fuseki1799", 2,-1,2.000000},
  {fuseki131798,4,"Fuseki1800",-4,-2,1.000000},
  {fuseki131799,4,"Fuseki1801",-4,-4,1.000000},
  {fuseki131800,5,"Fuseki1802", 4, 1,1.000000},
  {fuseki131801,5,"Fuseki1803", 1, 4,1.000000},
  {fuseki131802,4,"Fuseki1804",-4, 0,1.000000},
  {fuseki131803,4,"Fuseki1805", 4, 1,1.000000},
  {fuseki131804,4,"Fuseki1806", 4,-2,1.000000},
  {fuseki131805,4,"Fuseki1807",-3, 3,1.000000},
  {fuseki131806,6,"Fuseki1808",-3, 1,1.000000},
  {fuseki131807,6,"Fuseki1809",-1,-4,1.000000},
  {fuseki131808,5,"Fuseki1810", 2, 4,1.000000},
  {fuseki131809,5,"Fuseki1811",-2,-2,1.000000},
  {fuseki131810,4,"Fuseki1812", 3, 3,1.000000},
  {fuseki131811,4,"Fuseki1813", 2, 3,1.000000},
  {fuseki131812,5,"Fuseki1814", 4,-2,2.000000},
  {fuseki131813,5,"Fuseki1815", 0, 3,1.000000},
  {fuseki131814,5,"Fuseki1816",-4, 1,1.000000},
  {fuseki131815,6,"Fuseki1817", 1, 4,1.000000},
  {fuseki131816,6,"Fuseki1818", 3, 1,1.000000},
  {fuseki131817,6,"Fuseki1819", 2,-4,2.000000},
  {fuseki131818,5,"Fuseki1820", 4,-1,2.000000},
  {fuseki131819,7,"Fuseki1821",-2,-3,2.000000},
  {fuseki131820,3,"Fuseki1822",-3,-2,1.000000},
  {fuseki131821,3,"Fuseki1823",-3,-4,1.000000},
  {fuseki131822,3,"Fuseki1824",-2,-3,1.000000},
  {fuseki131823,3,"Fuseki1825",-4, 4,1.000000},
  {fuseki131824,3,"Fuseki1826", 3,-4,2.000000},
  {fuseki131825,6,"Fuseki1827", 0, 4,2.000000},
  {fuseki131826,8,"Fuseki1828", 3,-1,2.000000},
  {fuseki131827,4,"Fuseki1829",-4, 1,1.000000},
  {fuseki131828,4,"Fuseki1830", 1,-3,1.000000},
  {fuseki131829,6,"Fuseki1831", 3,-2,1.000000},
  {fuseki131830,6,"Fuseki1832", 5,-5,1.000000},
  {fuseki131831,5,"Fuseki1833",-4,-2,1.000000},
  {fuseki131832,5,"Fuseki1834", 2,-3,1.000000},
  {fuseki131833,6,"Fuseki1835", 5,-3,2.000000},
  {fuseki131834,5,"Fuseki1836", 3, 2,1.000000},
  {fuseki131835,5,"Fuseki1837", 4, 0,1.000000},
  {fuseki131836,5,"Fuseki1838",-4, 1,1.000000},
  {fuseki131837,5,"Fuseki1839", 3, 2,1.000000},
  {fuseki131838,5,"Fuseki1840",-1,-3,1.000000},
  {fuseki131839,5,"Fuseki1841", 0,-3,1.000000},
  {fuseki131840,9,"Fuseki1842", 3,-1,2.000000},
  {fuseki131841,5,"Fuseki1843", 3, 2,2.000000},
  {fuseki131842,8,"Fuseki1844", 2, 1,2.000000},
  {fuseki131843,4,"Fuseki1845", 4,-2,1.000000},
  {fuseki131844,4,"Fuseki1846", 4, 3,1.000000},
  {fuseki131845,6,"Fuseki1847", 5, 2,1.000000},
  {fuseki131846,6,"Fuseki1848",-4,-1,1.000000},
  {fuseki131847,5,"Fuseki1849",-4, 1,1.000000},
  {fuseki131848,5,"Fuseki1850", 2,-4,1.000000},
  {fuseki131849,5,"Fuseki1851", 4,-1,2.000000},
  {fuseki131850,6,"Fuseki1852", 3,-4,1.000000},
  {fuseki131851,6,"Fuseki1853", 2,-4,1.000000},
  {fuseki131852,6,"Fuseki1854",-3,-1,2.000000},
  {fuseki131853,2,"Fuseki1855",-3, 3,1.000000},
  {fuseki131854,2,"Fuseki1856",-4, 3,1.000000},
  {fuseki131855,5,"Fuseki1857", 4,-4,1.000000},
  {fuseki131856,5,"Fuseki1858",-2, 3,1.000000},
  {fuseki131857,3,"Fuseki1859",-4, 2,1.000000},
  {fuseki131858,3,"Fuseki1860",-3,-3,1.000000},
  {fuseki131859,4,"Fuseki1861",-1,-4,2.000000},
  {fuseki131860,7,"Fuseki1862", 2,-3,2.000000},
  {fuseki131861,2,"Fuseki1863", 2,-3,2.000000},
  {fuseki131862,6,"Fuseki1864",-4, 0,1.000000},
  {fuseki131863,6,"Fuseki1865",-4, 3,1.000000},
  {fuseki131864,4,"Fuseki1866", 4, 1,1.000000},
  {fuseki131865,4,"Fuseki1867", 0, 4,1.000000},
  {fuseki131866,9,"Fuseki1868",-4, 0,1.000000},
  {fuseki131867,9,"Fuseki1869",-2, 4,1.000000},
  {fuseki131868,5,"Fuseki1870",-4, 1,1.000000},
  {fuseki131869,5,"Fuseki1871",-4, 2,1.000000},
  {fuseki131870,3,"Fuseki1872",-4, 4,2.000000},
  {fuseki131871,8,"Fuseki1873",-3, 4,2.000000},
  {fuseki131872,5,"Fuseki1874",-1,-4,2.000000},
  {fuseki131873,7,"Fuseki1875",-2,-2,2.000000},
  {fuseki131874,7,"Fuseki1876", 2,-2,1.000000},
  {fuseki131875,7,"Fuseki1877", 5, 3,1.000000},
  {fuseki131876,2,"Fuseki1878", 3,-2,1.000000},
  {fuseki131877,2,"Fuseki1879",-3, 3,1.000000},
  {fuseki131878,6,"Fuseki1880", 0,-4,1.000000},
  {fuseki131879,6,"Fuseki1881",-3,-1,1.000000},
  {fuseki131880,7,"Fuseki1882",-1, 4,1.000000},
  {fuseki131881,7,"Fuseki1883", 3, 2,1.000000},
  {fuseki131882,5,"Fuseki1884",-2, 2,1.000000},
  {fuseki131883,5,"Fuseki1885", 3, 2,1.000000},
  {fuseki131884,7,"Fuseki1886", 1, 0,2.000000},
  {fuseki131885,4,"Fuseki1887", 3,-4,2.000000},
  {fuseki131886,5,"Fuseki1888", 4,-1,2.000000},
  {fuseki131887,4,"Fuseki1889", 3,-4,1.000000},
  {fuseki131888,4,"Fuseki1890", 4, 3,1.000000},
  {fuseki131889,8,"Fuseki1891", 4, 0,2.000000},
  {fuseki131890,5,"Fuseki1892",-4, 1,2.000000},
  {fuseki131891,6,"Fuseki1893",-4, 0,1.000000},
  {fuseki131892,6,"Fuseki1894", 4,-3,1.000000},
  {fuseki131893,6,"Fuseki1895", 3, 0,2.000000},
  {fuseki131894,3,"Fuseki1896", 1,-4,1.000000},
  {fuseki131895,3,"Fuseki1897", 3,-2,1.000000},
  {fuseki131896,8,"Fuseki1898", 0, 3,1.000000},
  {fuseki131897,8,"Fuseki1899", 2, 4,1.000000},
  {fuseki131898,4,"Fuseki1900", 4,-1,1.000000},
  {fuseki131899,4,"Fuseki1901", 2,-4,1.000000},
  {fuseki131900,5,"Fuseki1902",-1, 3,1.000000},
  {fuseki131901,5,"Fuseki1903",-2, 4,1.000000},
  {fuseki131902,4,"Fuseki1904",-4, 4,2.000000},
  {fuseki131903,7,"Fuseki1905", 1, 4,2.000000},
  {fuseki131904,3,"Fuseki1906", 4,-3,1.000000},
  {fuseki131905,3,"Fuseki1907",-3, 3,1.000000},
  {fuseki131906,8,"Fuseki1908",-1,-4,1.000000},
  {fuseki131907,8,"Fuseki1909", 0,-4,1.000000},
  {fuseki131908,3,"Fuseki1910", 4,-3,1.000000},
  {fuseki131909,3,"Fuseki1911", 4, 3,1.000000},
  {fuseki131910,5,"Fuseki1912", 3,-3,2.000000},
  {fuseki131911,4,"Fuseki1913", 4, 5,1.000000},
  {fuseki131912,4,"Fuseki1914",-4, 3,1.000000},
  {fuseki131913,5,"Fuseki1915",-1,-4,1.000000},
  {fuseki131914,5,"Fuseki1916",-3,-2,1.000000},
  {fuseki131915,6,"Fuseki1917", 1,-1,1.000000},
  {fuseki131916,6,"Fuseki1918", 3,-1,1.000000},
  {fuseki131917,8,"Fuseki1919", 5, 1,2.000000},
  {fuseki131918,7,"Fuseki1920",-3,-5,2.000000},
  {fuseki131919,5,"Fuseki1921",-3,-2,2.000000},
  {fuseki131920,4,"Fuseki1922",-2,-3,2.000000},
  {fuseki131921,4,"Fuseki1923", 1, 4,1.000000},
  {fuseki131922,4,"Fuseki1924",-2, 3,1.000000},
  {fuseki131923,4,"Fuseki1925", 4,-2,2.000000},
  {fuseki131924,3,"Fuseki1926", 2,-4,1.000000},
  {fuseki131925,3,"Fuseki1927", 4, 4,1.000000},
  {fuseki131926,8,"Fuseki1928", 0,-4,2.000000},
  {fuseki131927,5,"Fuseki1929", 4,-2,1.000000},
  {fuseki131928,5,"Fuseki1930", 1, 4,1.000000},
  {fuseki131929,5,"Fuseki1931",-4, 1,2.000000},
  {fuseki131930,4,"Fuseki1932", 0, 3,1.000000},
  {fuseki131931,4,"Fuseki1933",-3,-2,1.000000},
  {fuseki131932,7,"Fuseki1934",-4,-4,2.000000},
  {fuseki131933,6,"Fuseki1935", 3, 1,2.000000},
  {fuseki131934,5,"Fuseki1936",-3, 4,1.000000},
  {fuseki131935,5,"Fuseki1937", 0,-4,1.000000},
  {fuseki131936,5,"Fuseki1938",-3,-3,1.000000},
  {fuseki131937,5,"Fuseki1939",-2, 4,1.000000},
  {fuseki131938,4,"Fuseki1940",-3,-1,1.000000},
  {fuseki131939,4,"Fuseki1941",-3, 4,1.000000},
  {fuseki131940,5,"Fuseki1942", 3,-1,1.000000},
  {fuseki131941,5,"Fuseki1943", 4,-3,1.000000},
  {fuseki131942,7,"Fuseki1944", 1, 3,2.000000},
  {fuseki131943,4,"Fuseki1945", 3, 4,2.000000},
  {fuseki131944,8,"Fuseki1946",-2,-2,1.000000},
  {fuseki131945,8,"Fuseki1947",-1, 3,1.000000},
  {fuseki131946,6,"Fuseki1948",-1, 3,1.000000},
  {fuseki131947,6,"Fuseki1949", 3, 0,1.000000},
  {fuseki131948,6,"Fuseki1950",-4, 0,2.000000},
  {fuseki131949,4,"Fuseki1951", 4, 0,2.000000},
  {fuseki131950,5,"Fuseki1952", 1, 3,2.000000},
  {fuseki131951,8,"Fuseki1953", 4,-1,2.000000},
  {fuseki131952,7,"Fuseki1954", 4,-2,2.000000},
  {fuseki131953,7,"Fuseki1955",-4, 3,2.000000},
  {fuseki131954,4,"Fuseki1956", 0,-3,2.000000},
  {fuseki131955,5,"Fuseki1957",-4, 2,2.000000},
  {fuseki131956,6,"Fuseki1958",-4, 0,1.000000},
  {fuseki131957,6,"Fuseki1959", 2, 3,1.000000},
  {fuseki131958,3,"Fuseki1960",-2,-4,1.000000},
  {fuseki131959,3,"Fuseki1961",-4, 3,1.000000},
  {fuseki131960,8,"Fuseki1962", 3,-1,2.000000},
  {fuseki131961,9,"Fuseki1963", 4,-1,2.000000},
  {fuseki131962,5,"Fuseki1964",-2, 4,1.000000},
  {fuseki131963,5,"Fuseki1965", 3,-2,1.000000},
  {fuseki131964,4,"Fuseki1966",-1,-3,1.000000},
  {fuseki131965,4,"Fuseki1967", 1, 3,1.000000},
  {fuseki131966,6,"Fuseki1968", 0, 4,1.000000},
  {fuseki131967,6,"Fuseki1969",-4,-2,1.000000},
  {fuseki131968,5,"Fuseki1970",-4,-5,2.000000},
  {fuseki131969,6,"Fuseki1971",-3,-1,1.000000},
  {fuseki131970,6,"Fuseki1972",-2,-4,1.000000},
  {fuseki131971,7,"Fuseki1973", 5, 3,1.000000},
  {fuseki131972,7,"Fuseki1974", 2, 2,1.000000},
  {fuseki131973,3,"Fuseki1975",-3,-3,1.000000},
  {fuseki131974,3,"Fuseki1976",-3,-4,1.000000},
  {fuseki131975,4,"Fuseki1977",-3,-4,1.000000},
  {fuseki131976,4,"Fuseki1978", 4,-4,1.000000},
  {fuseki131977,4,"Fuseki1979",-3, 3,2.000000},
  {fuseki131978,7,"Fuseki1980",-1, 4,1.000000},
  {fuseki131979,7,"Fuseki1981",-1,-3,1.000000},
  {fuseki131980,6,"Fuseki1982", 4,-2,2.000000},
  {fuseki131981,4,"Fuseki1983",-2, 3,1.000000},
  {fuseki131982,4,"Fuseki1984", 3, 1,1.000000},
  {fuseki131983,3,"Fuseki1985",-3,-4,1.000000},
  {fuseki131984,3,"Fuseki1986",-4,-3,1.000000},
  {fuseki131985,7,"Fuseki1987",-3,-2,2.000000},
  {fuseki131986,5,"Fuseki1988",-4, 1,1.000000},
  {fuseki131987,5,"Fuseki1989", 3,-5,1.000000},
  {fuseki131988,5,"Fuseki1990", 0, 0,1.000000},
  {fuseki131989,5,"Fuseki1991",-1, 3,1.000000},
  {fuseki131990,8,"Fuseki1992", 3, 3,1.000000},
  {fuseki131991,8,"Fuseki1993", 1, 3,1.000000},
  {fuseki131992,6,"Fuseki1994", 4,-2,2.000000},
  {fuseki131993,5,"Fuseki1995",-3,-1,1.000000},
  {fuseki131994,5,"Fuseki1996", 2, 3,1.000000},
  {fuseki131995,5,"Fuseki1997",-3,-3,1.000000},
  {fuseki131996,5,"Fuseki1998",-2, 4,1.000000},
  {fuseki131997,6,"Fuseki1999", 0, 4,1.000000},
  {fuseki131998,6,"Fuseki2000", 4,-2,1.000000},
  {fuseki131999,4,"Fuseki2001", 4, 1,158.000000},
  {fuseki132000,4,"Fuseki2002", 3, 0,51.000000},
  {fuseki132001,4,"Fuseki2003", 0,-4,31.000000},
  {fuseki132002,4,"Fuseki2004", 4, 4,19.000000},
  {fuseki132003,4,"Fuseki2005", 0, 0,11.000000},
  {fuseki132004,4,"Fuseki2006", 4,-3,11.000000},
  {fuseki132005,4,"Fuseki2007",-3, 1,10.000000},
  {fuseki132006,5,"Fuseki2008", 4,-1,43.000000},
  {fuseki132007,5,"Fuseki2009",-2, 4,30.000000},
  {fuseki132008,5,"Fuseki2010",-3,-1,19.000000},
  {fuseki132009,5,"Fuseki2011", 1, 3,19.000000},
  {fuseki132010,5,"Fuseki2012", 4,-1,15.000000},
  {fuseki132011,5,"Fuseki2013", 0,-3,6.000000},
  {fuseki132012,5,"Fuseki2014",-1, 2,5.000000},
  {fuseki132013,2,"Fuseki2015", 3, 3,55.000000},
  {fuseki132014,2,"Fuseki2016",-3,-4,51.000000},
  {fuseki132015,2,"Fuseki2017",-4,-4,16.000000},
  {fuseki132016,2,"Fuseki2018", 4, 2,7.000000},
  {fuseki132017,3,"Fuseki2019", 3, 3,51.000000},
  {fuseki132018,3,"Fuseki2020", 4, 4,25.000000},
  {fuseki132019,3,"Fuseki2021", 4, 3,22.000000},
  {fuseki132020,3,"Fuseki2022", 3, 2,11.000000},
  {fuseki132021,3,"Fuseki2023", 4, 2,8.000000},
  {fuseki132022,3,"Fuseki2024", 0, 0,7.000000},
  {fuseki132023,5,"Fuseki2025",-4,-1,67.000000},
  {fuseki132024,5,"Fuseki2026", 4, 4,22.000000},
  {fuseki132025,5,"Fuseki2027",-3, 1,12.000000},
  {fuseki132026,5,"Fuseki2028", 4, 0,9.000000},
  {fuseki132027,6,"Fuseki2029",-4,-2,16.000000},
  {fuseki132028,6,"Fuseki2030", 1,-4,14.000000},
  {fuseki132029,6,"Fuseki2031", 1,-3,8.000000},
  {fuseki132030,6,"Fuseki2032",-4, 1,5.000000},
  {fuseki132031,6,"Fuseki2033",-3, 1,5.000000},
  {fuseki132032,6,"Fuseki2034", 3, 0,4.000000},
  {fuseki132033,6,"Fuseki2035", 5, 2,2.000000},
  {fuseki132034,6,"Fuseki2036", 0,-3,2.000000},
  {fuseki132035,6,"Fuseki2037",-4, 0,2.000000},
  {fuseki132036,6,"Fuseki2038",-3, 5,2.000000},
  {fuseki132037,3,"Fuseki2039",-3,-3,24.000000},
  {fuseki132038,3,"Fuseki2040",-3,-4,16.000000},
  {fuseki132039,3,"Fuseki2041", 1, 4,3.000000},
  {fuseki132040,3,"Fuseki2042", 2, 4,3.000000},
  {fuseki132041,3,"Fuseki2043", 4, 4,3.000000},
  {fuseki132042,3,"Fuseki2044",-4,-3,9.000000},
  {fuseki132043,3,"Fuseki2045",-3,-3,9.000000},
  {fuseki132044,3,"Fuseki2046",-3,-4,8.000000},
  {fuseki132045,3,"Fuseki2047",-4,-4,7.000000},
  {fuseki132046,3,"Fuseki2048", 2, 4,6.000000},
  {fuseki132047,3,"Fuseki2049", 2, 3,2.000000},
  {fuseki132048,3,"Fuseki2050",-4,-2,2.000000},
  {fuseki132049,3,"Fuseki2051", 3, 2,2.000000},
  {fuseki132050,3,"Fuseki2052", 3, 0,1.000000},
  {fuseki132051,3,"Fuseki2053", 4, 2,1.000000},
  {fuseki132052,3,"Fuseki2054", 3, 2,1.000000},
  {fuseki132053,3,"Fuseki2055",-3, 1,1.000000},
  {fuseki132054,3,"Fuseki2056",-1, 4,1.000000},
  {fuseki132055,3,"Fuseki2057", 4,-1,1.000000},
  {fuseki132056,4,"Fuseki2058", 4, 1,22.000000},
  {fuseki132057,4,"Fuseki2059", 0,-3,9.000000},
  {fuseki132058,4,"Fuseki2060", 4, 0,4.000000},
  {fuseki132059,4,"Fuseki2061",-4, 0,3.000000},
  {fuseki132060,4,"Fuseki2062",-1, 4,3.000000},
  {fuseki132061,5,"Fuseki2063",-3, 1,42.000000},
  {fuseki132062,6,"Fuseki2064", 1, 4,28.000000},
  {fuseki132063,6,"Fuseki2065",-5, 3,4.000000},
  {fuseki132064,6,"Fuseki2066", 2, 1,3.000000},
  {fuseki132065,6,"Fuseki2067", 3, 4,17.000000},
  {fuseki132066,6,"Fuseki2068", 3, 1,5.000000},
  {fuseki132067,6,"Fuseki2069", 0, 3,3.000000},
  {fuseki132068,6,"Fuseki2070", 4, 3,3.000000},
  {fuseki132069,6,"Fuseki2071", 4, 1,3.000000},
  {fuseki132070,6,"Fuseki2072",-4,-1,2.000000},
  {fuseki132071,6,"Fuseki2073", 1,-3,2.000000},
  {fuseki132072,5,"Fuseki2074",-2, 4,18.000000},
  {fuseki132073,5,"Fuseki2075", 0,-2,8.000000},
  {fuseki132074,6,"Fuseki2076",-1, 3,28.000000},
  {fuseki132075,7,"Fuseki2077",-3, 1,21.000000},
  {fuseki132076,7,"Fuseki2078", 3,-1,9.000000},
  {fuseki132077,7,"Fuseki2079", 2, 2,8.000000},
  {fuseki132078,7,"Fuseki2080", 1,-3,6.000000},
  {fuseki132079,7,"Fuseki2081", 4,-2,5.000000},
  {fuseki132080,4,"Fuseki2082", 0,-3,5.000000},
  {fuseki132081,4,"Fuseki2083",-1, 4,4.000000},
  {fuseki132082,4,"Fuseki2084", 3, 3,3.000000},
  {fuseki132083,4,"Fuseki2085", 4, 0,3.000000},
  {fuseki132084,4,"Fuseki2086", 2, 4,2.000000},
  {fuseki132085,4,"Fuseki2087", 0, 3,2.000000},
  {fuseki132086,4,"Fuseki2088", 3, 6,1.000000},
  {fuseki132087,4,"Fuseki2089",-2,-1,1.000000},
  {fuseki132088,4,"Fuseki2090", 1, 4,1.000000},
  {fuseki132089,4,"Fuseki2091",-4, 0,1.000000},
  {fuseki132090,4,"Fuseki2092", 3, 4,1.000000},
  {fuseki132091,4,"Fuseki2093", 4,-2,1.000000},
  {fuseki132092,4,"Fuseki2094", 4,-1,9.000000},
  {fuseki132093,4,"Fuseki2095",-4,-1,4.000000},
  {fuseki132094,4,"Fuseki2096",-1, 3,3.000000},
  {fuseki132095,4,"Fuseki2097",-3, 0,2.000000},
  {fuseki132096,4,"Fuseki2098", 4,-1,2.000000},
  {fuseki132097,4,"Fuseki2099",-4,-4,1.000000},
  {fuseki132098,4,"Fuseki2100", 4,-4,1.000000},
  {fuseki132099,4,"Fuseki2101", 3, 0,1.000000},
  {fuseki132100,4,"Fuseki2102", 3, 1,1.000000},
  {fuseki132101,9,"Fuseki2103", 4,-4,15.000000},
  {fuseki132102,9,"Fuseki2104",-2,-2,2.000000},
  {fuseki132103,9,"Fuseki2105",-4,-3,2.000000},
  {fuseki132104,6,"Fuseki2106", 4, 3,20.000000},
  {fuseki132105,4,"Fuseki2107", 4, 2,4.000000},
  {fuseki132106,4,"Fuseki2108",-4, 0,3.000000},
  {fuseki132107,4,"Fuseki2109", 0, 4,2.000000},
  {fuseki132108,4,"Fuseki2110",-1,-3,1.000000},
  {fuseki132109,4,"Fuseki2111", 0,-3,1.000000},
  {fuseki132110,4,"Fuseki2112",-3, 0,1.000000},
  {fuseki132111,4,"Fuseki2113", 1, 4,1.000000},
  {fuseki132112,4,"Fuseki2114", 5,-2,1.000000},
  {fuseki132113,4,"Fuseki2115",-2, 5,1.000000},
  {fuseki132114,4,"Fuseki2116", 1, 3,1.000000},
  {fuseki132115,4,"Fuseki2117", 0, 0,1.000000},
  {fuseki132116,4,"Fuseki2118", 1, 1,1.000000},
  {fuseki132117,4,"Fuseki2119", 3, 3,1.000000},
  {fuseki132118,4,"Fuseki2120", 4,-1,1.000000},
  {fuseki132119,4,"Fuseki2121", 3, 2,1.000000},
  {fuseki132120,4,"Fuseki2122", 0, 4,1.000000},
  {fuseki132121,5,"Fuseki2123", 4, 0,3.000000},
  {fuseki132122,5,"Fuseki2124", 4,-1,3.000000},
  {fuseki132123,5,"Fuseki2125", 0, 3,2.000000},
  {fuseki132124,5,"Fuseki2126", 1, 2,2.000000},
  {fuseki132125,5,"Fuseki2127", 4,-1,2.000000},
  {fuseki132126,5,"Fuseki2128",-4,-4,2.000000},
  {fuseki132127,5,"Fuseki2129", 3, 0,2.000000},
  {fuseki132128,5,"Fuseki2130",-4, 0,1.000000},
  {fuseki132129,5,"Fuseki2131",-4, 0,1.000000},
  {fuseki132130,5,"Fuseki2132",-4,-1,1.000000},
  {fuseki132131,5,"Fuseki2133", 1,-4,1.000000},
  {fuseki132132,5,"Fuseki2134", 4, 2,1.000000},
  {fuseki132133,5,"Fuseki2135", 1, 3,1.000000},
  {fuseki132134,8,"Fuseki2136", 1, 4,8.000000},
  {fuseki132135,8,"Fuseki2137",-1,-3,3.000000},
  {fuseki132136,8,"Fuseki2138", 1, 3,2.000000},
  {fuseki132137,8,"Fuseki2139",-1,-1,2.000000},
  {fuseki132138,8,"Fuseki2140", 3, 4,1.000000},
  {fuseki132139,8,"Fuseki2141",-4,-4,1.000000},
  {fuseki132140,8,"Fuseki2142", 0, 0,1.000000},
  {fuseki132141,8,"Fuseki2143",-3, 0,1.000000},
  {fuseki132142,8,"Fuseki2144", 4, 2,1.000000},
  {fuseki132143,8,"Fuseki2145", 4, 1,1.000000},
  {fuseki132144,7,"Fuseki2146",-4, 3,11.000000},
  {fuseki132145,7,"Fuseki2147", 1, 5,3.000000},
  {fuseki132146,7,"Fuseki2148", 5, 3,3.000000},
  {fuseki132147,5,"Fuseki2149", 4, 3,15.000000},
  {fuseki132148,5,"Fuseki2150", 0, 3,2.000000},
  {fuseki132149,6,"Fuseki2151", 3,-5,6.000000},
  {fuseki132150,6,"Fuseki2152",-1,-4,3.000000},
  {fuseki132151,6,"Fuseki2153", 1,-3,2.000000},
  {fuseki132152,6,"Fuseki2154", 4, 4,1.000000},
  {fuseki132153,6,"Fuseki2155", 1, 3,1.000000},
  {fuseki132154,6,"Fuseki2156", 3, 0,1.000000},
  {fuseki132155,6,"Fuseki2157", 5, 4,1.000000},
  {fuseki132156,6,"Fuseki2158",-4,-1,1.000000},
  {fuseki132157,6,"Fuseki2159", 2, 4,1.000000},
  {fuseki132158,6,"Fuseki2160", 3, 1,1.000000},
  {fuseki132159,6,"Fuseki2161", 4, 3,1.000000},
  {fuseki132160,6,"Fuseki2162",-3, 0,12.000000},
  {fuseki132161,6,"Fuseki2163",-3,-5,2.000000},
  {fuseki132162,6,"Fuseki2164",-4, 0,2.000000},
  {fuseki132163,6,"Fuseki2165",-3, 5,7.000000},
  {fuseki132164,6,"Fuseki2166", 3, 4,5.000000},
  {fuseki132165,6,"Fuseki2167",-1, 2,2.000000},
  {fuseki132166,6,"Fuseki2168", 3, 4,1.000000},
  {fuseki132167,6,"Fuseki2169", 1, 4,1.000000},
  {fuseki132168,6,"Fuseki2170", 2,-5,1.000000},
  {fuseki132169,6,"Fuseki2171", 0, 2,1.000000},
  {fuseki132170,7,"Fuseki2172", 4, 4,17.000000},
  {fuseki132171,8,"Fuseki2173", 2, 3,14.000000},
  {fuseki132172,8,"Fuseki2174", 4,-3,3.000000},
  {fuseki132173,4,"Fuseki2175",-4,-2,9.000000},
  {fuseki132174,4,"Fuseki2176",-1, 4,3.000000},
  {fuseki132175,4,"Fuseki2177",-4, 4,2.000000},
  {fuseki132176,4,"Fuseki2178",-3,-4,1.000000},
  {fuseki132177,4,"Fuseki2179",-3,-2,1.000000},
  {fuseki132178,7,"Fuseki2180",-3,-1,14.000000},
  {fuseki132179,3,"Fuseki2181", 3, 3,5.000000},
  {fuseki132180,3,"Fuseki2182", 4, 3,3.000000},
  {fuseki132181,3,"Fuseki2183", 3, 3,3.000000},
  {fuseki132182,3,"Fuseki2184", 4, 4,2.000000},
  {fuseki132183,3,"Fuseki2185", 0, 0,1.000000},
  {fuseki132184,3,"Fuseki2186",-2,-4,1.000000},
  {fuseki132185,3,"Fuseki2187", 4,-1,1.000000},
  {fuseki132186,8,"Fuseki2188",-3, 2,5.000000},
  {fuseki132187,8,"Fuseki2189",-1, 3,4.000000},
  {fuseki132188,8,"Fuseki2190",-5, 1,1.000000},
  {fuseki132189,8,"Fuseki2191",-2, 2,1.000000},
  {fuseki132190,8,"Fuseki2192",-2, 5,1.000000},
  {fuseki132191,8,"Fuseki2193", 3, 0,1.000000},
  {fuseki132192,8,"Fuseki2194", 1, 4,1.000000},
  {fuseki132193,8,"Fuseki2195",-1,-2,1.000000},
  {fuseki132194,6,"Fuseki2196", 3, 4,13.000000},
  {fuseki132195,6,"Fuseki2197",-5, 3,2.000000},
  {fuseki132196,7,"Fuseki2198", 2, 4,8.000000},
  {fuseki132197,7,"Fuseki2199", 2, 3,3.000000},
  {fuseki132198,7,"Fuseki2200", 5,-4,2.000000},
  {fuseki132199,7,"Fuseki2201", 0,-3,2.000000},
  {fuseki132200,10,"Fuseki2202", 4,-3,10.000000},
  {fuseki132201,10,"Fuseki2203",-5,-3,1.000000},
  {fuseki132202,10,"Fuseki2204",-2, 5,1.000000},
  {fuseki132203,10,"Fuseki2205", 2,-4,1.000000},
  {fuseki132204,10,"Fuseki2206", 2, 2,1.000000},
  {fuseki132205,10,"Fuseki2207", 0,-5,1.000000},
  {fuseki132206,6,"Fuseki2208", 5,-3,3.000000},
  {fuseki132207,6,"Fuseki2209",-4, 1,3.000000},
  {fuseki132208,6,"Fuseki2210",-4,-1,2.000000},
  {fuseki132209,6,"Fuseki2211", 4, 1,1.000000},
  {fuseki132210,6,"Fuseki2212", 4, 1,1.000000},
  {fuseki132211,6,"Fuseki2213", 4,-4,1.000000},
  {fuseki132212,6,"Fuseki2214", 1, 4,1.000000},
  {fuseki132213,6,"Fuseki2215",-2, 4,1.000000},
  {fuseki132214,6,"Fuseki2216", 0, 2,1.000000},
  {fuseki132215,6,"Fuseki2217", 3,-1,1.000000},
  {fuseki132216,9,"Fuseki2218", 2,-1,13.000000},
  {fuseki132217,7,"Fuseki2219", 1,-4,8.000000},
  {fuseki132218,7,"Fuseki2220", 5, 3,2.000000},
  {fuseki132219,7,"Fuseki2221", 4, 4,1.000000},
  {fuseki132220,7,"Fuseki2222", 3,-1,1.000000},
  {fuseki132221,7,"Fuseki2223", 2, 1,1.000000},
  {fuseki132222,7,"Fuseki2224",-3, 1,1.000000},
  {fuseki132223,12,"Fuseki2225", 2, 4,11.000000},
  {fuseki132224,12,"Fuseki2226", 2, 5,2.000000},
  {fuseki132225,7,"Fuseki2227", 4,-1,4.000000},
  {fuseki132226,7,"Fuseki2228", 4, 4,4.000000},
  {fuseki132227,7,"Fuseki2229", 3, 0,2.000000},
  {fuseki132228,7,"Fuseki2230",-2, 2,2.000000},
  {fuseki132229,7,"Fuseki2231",-3,-4,1.000000},
  {fuseki132230,11,"Fuseki2232", 4, 3,13.000000},
  {fuseki132231,6,"Fuseki2233", 4,-1,6.000000},
  {fuseki132232,6,"Fuseki2234", 4, 0,2.000000},
  {fuseki132233,6,"Fuseki2235", 4, 4,1.000000},
  {fuseki132234,6,"Fuseki2236", 3, 2,1.000000},
  {fuseki132235,6,"Fuseki2237", 3, 0,1.000000},
  {fuseki132236,6,"Fuseki2238", 4, 3,1.000000},
  {fuseki132237,6,"Fuseki2239", 3, 1,1.000000},
  {fuseki132238,10,"Fuseki2240", 3, 2,13.000000},
  {fuseki132239,7,"Fuseki2241",-1, 2,9.000000},
  {fuseki132240,7,"Fuseki2242",-3,-2,1.000000},
  {fuseki132241,7,"Fuseki2243",-2, 4,1.000000},
  {fuseki132242,8,"Fuseki2244",-4, 2,10.000000},
  {fuseki132243,8,"Fuseki2245", 4, 5,1.000000},
  {fuseki132244,6,"Fuseki2246",-2,-1,3.000000},
  {fuseki132245,6,"Fuseki2247",-2, 5,2.000000},
  {fuseki132246,6,"Fuseki2248", 0, 3,1.000000},
  {fuseki132247,6,"Fuseki2249",-4,-1,1.000000},
  {fuseki132248,6,"Fuseki2250", 5, 1,1.000000},
  {fuseki132249,6,"Fuseki2251",-2,-2,1.000000},
  {fuseki132250,6,"Fuseki2252",-3,-1,1.000000},
  {fuseki132251,6,"Fuseki2253", 4, 2,1.000000},
  {fuseki132252,13,"Fuseki2254", 0, 4,11.000000},
  {fuseki132253,5,"Fuseki2255", 2,-3,4.000000},
  {fuseki132254,5,"Fuseki2256", 4,-2,3.000000},
  {fuseki132255,5,"Fuseki2257", 3,-4,2.000000},
  {fuseki132256,5,"Fuseki2258",-4,-4,2.000000},
  {fuseki132257,5,"Fuseki2259",-2, 0,7.000000},
  {fuseki132258,5,"Fuseki2260", 0, 3,3.000000},
  {fuseki132259,5,"Fuseki2261",-4, 1,1.000000},
  {fuseki132260,4,"Fuseki2262",-3, 0,3.000000},
  {fuseki132261,4,"Fuseki2263", 4, 3,2.000000},
  {fuseki132262,4,"Fuseki2264", 2, 4,1.000000},
  {fuseki132263,4,"Fuseki2265", 4, 0,1.000000},
  {fuseki132264,4,"Fuseki2266", 0, 0,1.000000},
  {fuseki132265,4,"Fuseki2267",-1, 4,1.000000},
  {fuseki132266,4,"Fuseki2268", 4, 0,1.000000},
  {fuseki132267,4,"Fuseki2269", 2, 4,1.000000},
  {fuseki132268,9,"Fuseki2270",-3, 2,8.000000},
  {fuseki132269,9,"Fuseki2271",-5, 2,2.000000},
  {fuseki132270,11,"Fuseki2272", 4,-4,4.000000},
  {fuseki132271,11,"Fuseki2273",-3,-4,3.000000},
  {fuseki132272,11,"Fuseki2274", 5,-3,2.000000},
  {fuseki132273,11,"Fuseki2275",-5,-3,1.000000},
  {fuseki132274,5,"Fuseki2276",-1, 3,5.000000},
  {fuseki132275,5,"Fuseki2277", 0, 3,1.000000},
  {fuseki132276,5,"Fuseki2278", 4, 0,1.000000},
  {fuseki132277,5,"Fuseki2279", 2, 5,1.000000},
  {fuseki132278,5,"Fuseki2280", 1,-4,1.000000},
  {fuseki132279,4,"Fuseki2281", 4,-1,5.000000},
  {fuseki132280,4,"Fuseki2282", 1, 4,1.000000},
  {fuseki132281,4,"Fuseki2283", 1,-3,1.000000},
  {fuseki132282,4,"Fuseki2284", 4, 2,1.000000},
  {fuseki132283,4,"Fuseki2285", 4, 0,1.000000},
  {fuseki132284,4,"Fuseki2286", 2, 4,2.000000},
  {fuseki132285,4,"Fuseki2287",-4,-2,2.000000},
  {fuseki132286,4,"Fuseki2288", 3, 2,1.000000},
  {fuseki132287,4,"Fuseki2289", 4,-1,1.000000},
  {fuseki132288,4,"Fuseki2290", 0, 3,1.000000},
  {fuseki132289,4,"Fuseki2291", 4,-1,1.000000},
  {fuseki132290,4,"Fuseki2292", 4, 1,1.000000},
  {fuseki132291,5,"Fuseki2293", 4,-2,3.000000},
  {fuseki132292,5,"Fuseki2294",-3, 1,2.000000},
  {fuseki132293,5,"Fuseki2295", 4, 1,1.000000},
  {fuseki132294,5,"Fuseki2296",-1, 3,1.000000},
  {fuseki132295,5,"Fuseki2297", 5,-1,1.000000},
  {fuseki132296,5,"Fuseki2298", 5,-2,1.000000},
  {fuseki132297,5,"Fuseki2299", 1,-4,4.000000},
  {fuseki132298,5,"Fuseki2300",-2,-2,2.000000},
  {fuseki132299,5,"Fuseki2301", 4, 3,1.000000},
  {fuseki132300,5,"Fuseki2302",-3, 0,1.000000},
  {fuseki132301,5,"Fuseki2303", 0,-4,1.000000},
  {fuseki132302,6,"Fuseki2304",-4,-2,5.000000},
  {fuseki132303,6,"Fuseki2305", 3,-1,2.000000},
  {fuseki132304,6,"Fuseki2306", 4,-1,1.000000},
  {fuseki132305,6,"Fuseki2307", 0, 3,1.000000},
  {fuseki132306,5,"Fuseki2308", 1,-4,2.000000},
  {fuseki132307,5,"Fuseki2309", 4,-1,2.000000},
  {fuseki132308,5,"Fuseki2310", 4, 0,1.000000},
  {fuseki132309,5,"Fuseki2311",-1,-4,1.000000},
  {fuseki132310,5,"Fuseki2312",-1, 4,1.000000},
  {fuseki132311,5,"Fuseki2313",-4, 4,1.000000},
  {fuseki132312,5,"Fuseki2314",-4,-4,1.000000},
  {fuseki132313,5,"Fuseki2315",-4,-3,4.000000},
  {fuseki132314,5,"Fuseki2316",-1, 4,2.000000},
  {fuseki132315,5,"Fuseki2317",-1, 4,2.000000},
  {fuseki132316,5,"Fuseki2318", 4, 1,1.000000},
  {fuseki132317,8,"Fuseki2319", 3, 0,4.000000},
  {fuseki132318,8,"Fuseki2320", 4,-4,3.000000},
  {fuseki132319,8,"Fuseki2321", 4,-2,2.000000},
  {fuseki132320,8,"Fuseki2322",-4, 3,5.000000},
  {fuseki132321,8,"Fuseki2323",-2, 4,3.000000},
  {fuseki132322,8,"Fuseki2324", 4, 4,1.000000},
  {fuseki132323,9,"Fuseki2325", 2, 4,5.000000},
  {fuseki132324,9,"Fuseki2326", 3, 1,2.000000},
  {fuseki132325,9,"Fuseki2327",-2,-5,1.000000},
  {fuseki132326,8,"Fuseki2328", 4, 4,8.000000},
  {fuseki132327,10,"Fuseki2329",-4, 1,8.000000},
  {fuseki132328,4,"Fuseki2330", 3, 4,2.000000},
  {fuseki132329,4,"Fuseki2331",-4, 1,1.000000},
  {fuseki132330,4,"Fuseki2332", 2, 3,1.000000},
  {fuseki132331,4,"Fuseki2333",-3, 0,1.000000},
  {fuseki132332,4,"Fuseki2334", 2, 2,1.000000},
  {fuseki132333,4,"Fuseki2335",-4,-1,1.000000},
  {fuseki132334,4,"Fuseki2336", 4, 0,1.000000},
  {fuseki132335,4,"Fuseki2337",-4,-2,3.000000},
  {fuseki132336,4,"Fuseki2338", 1,-4,2.000000},
  {fuseki132337,4,"Fuseki2339",-2,-4,2.000000},
  {fuseki132338,4,"Fuseki2340",-1, 4,1.000000},
  {fuseki132339,8,"Fuseki2341", 4,-2,6.000000},
  {fuseki132340,8,"Fuseki2342", 3,-4,2.000000},
  {fuseki132341,6,"Fuseki2343", 2,-2,3.000000},
  {fuseki132342,6,"Fuseki2344", 3, 4,2.000000},
  {fuseki132343,6,"Fuseki2345", 3, 4,2.000000},
  {fuseki132344,6,"Fuseki2346",-3, 5,1.000000},
  {fuseki132345,9,"Fuseki2347", 4, 3,8.000000},
  {fuseki132346,8,"Fuseki2348", 2, 5,6.000000},
  {fuseki132347,8,"Fuseki2349",-3, 5,1.000000},
  {fuseki132348,8,"Fuseki2350",-2,-3,1.000000},
  {fuseki132349,10,"Fuseki2351", 5,-3,7.000000},
  {fuseki132350,10,"Fuseki2352", 3, 4,1.000000},
  {fuseki132351,7,"Fuseki2353", 1,-4,2.000000},
  {fuseki132352,7,"Fuseki2354", 4,-3,2.000000},
  {fuseki132353,7,"Fuseki2355", 4, 3,2.000000},
  {fuseki132354,7,"Fuseki2356",-4, 4,1.000000},
  {fuseki132355,7,"Fuseki2357", 3, 0,1.000000},
  {fuseki132356,11,"Fuseki2358",-2, 2,4.000000},
  {fuseki132357,11,"Fuseki2359",-3,-5,4.000000},
  {fuseki132358,11,"Fuseki2360", 3,-4,7.000000},
  {fuseki132359,4,"Fuseki2361", 4,-1,3.000000},
  {fuseki132360,4,"Fuseki2362", 3, 3,1.000000},
  {fuseki132361,4,"Fuseki2363",-1, 4,1.000000},
  {fuseki132362,4,"Fuseki2364",-2,-4,1.000000},
  {fuseki132363,4,"Fuseki2365", 1,-4,1.000000},
  {fuseki132364,10,"Fuseki2366", 2,-4,6.000000},
  {fuseki132365,10,"Fuseki2367",-5, 3,1.000000},
  {fuseki132366,12,"Fuseki2368", 5,-5,7.000000},
  {fuseki132367,7,"Fuseki2369", 3, 0,6.000000},
  {fuseki132368,7,"Fuseki2370",-4, 0,1.000000},
  {fuseki132369,13,"Fuseki2371", 0,-2,7.000000},
  {fuseki132370,3,"Fuseki2372",-3,-3,3.000000},
  {fuseki132371,3,"Fuseki2373",-4,-4,2.000000},
  {fuseki132372,3,"Fuseki2374",-4,-3,1.000000},
  {fuseki132373,3,"Fuseki2375", 4, 2,1.000000},
  {fuseki132374,4,"Fuseki2376", 3, 3,3.000000},
  {fuseki132375,4,"Fuseki2377", 0,-3,1.000000},
  {fuseki132376,4,"Fuseki2378", 0, 3,1.000000},
  {fuseki132377,4,"Fuseki2379", 3, 4,1.000000},
  {fuseki132378,4,"Fuseki2380",-1,-1,1.000000},
  {fuseki132379,6,"Fuseki2381",-4, 0,2.000000},
  {fuseki132380,6,"Fuseki2382",-4,-4,1.000000},
  {fuseki132381,6,"Fuseki2383",-1, 4,1.000000},
  {fuseki132382,6,"Fuseki2384", 3, 1,1.000000},
  {fuseki132383,6,"Fuseki2385",-4,-2,1.000000},
  {fuseki132384,6,"Fuseki2386", 0, 3,1.000000},
  {fuseki132385,4,"Fuseki2387",-2,-3,1.000000},
  {fuseki132386,4,"Fuseki2388", 4, 4,1.000000},
  {fuseki132387,4,"Fuseki2389",-3,-3,1.000000},
  {fuseki132388,4,"Fuseki2390", 3, 0,1.000000},
  {fuseki132389,4,"Fuseki2391",-3,-4,1.000000},
  {fuseki132390,4,"Fuseki2392",-1, 4,1.000000},
  {fuseki132391,9,"Fuseki2393", 1, 4,6.000000},
  {fuseki132392,7,"Fuseki2394", 4,-4,6.000000},
  {fuseki132393,12,"Fuseki2395", 1,-5,3.000000},
  {fuseki132394,12,"Fuseki2396", 2,-5,3.000000},
  {fuseki132395,10,"Fuseki2397", 5,-1,5.000000},
  {fuseki132396,10,"Fuseki2398", 5, 3,1.000000},
  {fuseki132397,0,"Fuseki2399", 3,-3,5.000000},
  {fuseki132398,0,"Fuseki2400", 4, 4,1.000000},
  {fuseki132399,8,"Fuseki2401", 0,-4,5.000000},
  {fuseki132400,8,"Fuseki2402", 4,-4,1.000000},
  {fuseki132401,7,"Fuseki2403", 4, 1,2.000000},
  {fuseki132402,7,"Fuseki2404", 3, 1,2.000000},
  {fuseki132403,7,"Fuseki2405", 3, 0,1.000000},
  {fuseki132404,7,"Fuseki2406",-4, 4,1.000000},
  {fuseki132405,8,"Fuseki2407", 4,-4,4.000000},
  {fuseki132406,8,"Fuseki2408", 2,-3,1.000000},
  {fuseki132407,8,"Fuseki2409", 3, 0,1.000000},
  {fuseki132408,6,"Fuseki2410", 5,-3,4.000000},
  {fuseki132409,6,"Fuseki2411", 1,-3,1.000000},
  {fuseki132410,6,"Fuseki2412",-4, 0,1.000000},
  {fuseki132411,11,"Fuseki2413", 1,-3,6.000000},
  {fuseki132412,8,"Fuseki2414",-2,-4,2.000000},
  {fuseki132413,8,"Fuseki2415", 1, 4,2.000000},
  {fuseki132414,8,"Fuseki2416", 4, 0,1.000000},
  {fuseki132415,8,"Fuseki2417", 1,-3,1.000000},
  {fuseki132416,9,"Fuseki2418", 3,-1,6.000000},
  {fuseki132417,7,"Fuseki2419", 4, 2,5.000000},
  {fuseki132418,9,"Fuseki2420",-2,-4,5.000000},
  {fuseki132419,6,"Fuseki2421", 3, 1,4.000000},
  {fuseki132420,6,"Fuseki2422",-3, 5,1.000000},
  {fuseki132421,10,"Fuseki2423",-4,-3,2.000000},
  {fuseki132422,10,"Fuseki2424",-3,-4,2.000000},
  {fuseki132423,10,"Fuseki2425",-4,-3,1.000000},
  {fuseki132424,11,"Fuseki2426", 5,-2,5.000000},
  {fuseki132425,6,"Fuseki2427", 1, 3,2.000000},
  {fuseki132426,6,"Fuseki2428",-4, 1,1.000000},
  {fuseki132427,6,"Fuseki2429", 0, 3,1.000000},
  {fuseki132428,6,"Fuseki2430",-4, 2,1.000000},
  {fuseki132429,12,"Fuseki2431", 4, 0,5.000000},
  {fuseki132430,12,"Fuseki2432", 2,-5,3.000000},
  {fuseki132431,12,"Fuseki2433", 3,-4,2.000000},
  {fuseki132432,9,"Fuseki2434", 2, 0,5.000000},
  {fuseki132433,7,"Fuseki2435", 2, 2,2.000000},
  {fuseki132434,7,"Fuseki2436", 2, 4,2.000000},
  {fuseki132435,7,"Fuseki2437", 4, 2,1.000000},
  {fuseki132436,5,"Fuseki2438", 4,-3,1.000000},
  {fuseki132437,5,"Fuseki2439",-2, 4,1.000000},
  {fuseki132438,5,"Fuseki2440", 3, 0,1.000000},
  {fuseki132439,5,"Fuseki2441",-1,-3,1.000000},
  {fuseki132440,5,"Fuseki2442", 0, 4,1.000000},
  {fuseki132441,8,"Fuseki2443", 4, 4,5.000000},
  {fuseki132442,11,"Fuseki2444",-3, 2,5.000000},
  {fuseki132443,9,"Fuseki2445",-4, 2,5.000000},
  {fuseki132444,9,"Fuseki2446", 2, 4,3.000000},
  {fuseki132445,9,"Fuseki2447", 1, 4,1.000000},
  {fuseki132446,9,"Fuseki2448", 4, 4,1.000000},
  {fuseki132447,9,"Fuseki2449", 5,-1,5.000000},
  {fuseki132448,10,"Fuseki2450", 1, 3,4.000000},
  {fuseki132449,10,"Fuseki2451",-1, 1,1.000000},
  {fuseki132450,10,"Fuseki2452",-5, 2,5.000000},
  {fuseki132451,3,"Fuseki2453", 4, 2,1.000000},
  {fuseki132452,3,"Fuseki2454", 3, 4,1.000000},
  {fuseki132453,3,"Fuseki2455",-4,-1,1.000000},
  {fuseki132454,3,"Fuseki2456",-2, 4,1.000000},
  {fuseki132455,3,"Fuseki2457",-1, 3,1.000000},
  {fuseki132456,1,"Fuseki2458", 4,-3,1.000000},
  {fuseki132457,1,"Fuseki2459", 4,-4,1.000000},
  {fuseki132458,1,"Fuseki2460", 3, 3,1.000000},
  {fuseki132459,1,"Fuseki2461", 3,-2,1.000000},
  {fuseki132460,1,"Fuseki2462",-4,-4,1.000000},
  {fuseki132461,8,"Fuseki2463", 3,-1,5.000000},
  {fuseki132462,11,"Fuseki2464", 0, 4,4.000000},
  {fuseki132463,11,"Fuseki2465", 5, 0,1.000000},
  {fuseki132464,7,"Fuseki2466", 5, 3,1.000000},
  {fuseki132465,7,"Fuseki2467",-4,-1,1.000000},
  {fuseki132466,7,"Fuseki2468",-1, 4,1.000000},
  {fuseki132467,7,"Fuseki2469", 3, 0,1.000000},
  {fuseki132468,7,"Fuseki2470",-4,-1,1.000000},
  {fuseki132469,4,"Fuseki2471", 4,-1,2.000000},
  {fuseki132470,4,"Fuseki2472",-4, 1,2.000000},
  {fuseki132471,4,"Fuseki2473",-3,-4,1.000000},
  {fuseki132472,10,"Fuseki2474", 3,-5,5.000000},
  {fuseki132473,5,"Fuseki2475",-4, 1,3.000000},
  {fuseki132474,5,"Fuseki2476",-1, 4,1.000000},
  {fuseki132475,5,"Fuseki2477",-4,-1,1.000000},
  {fuseki132476,6,"Fuseki2478", 4, 4,1.000000},
  {fuseki132477,6,"Fuseki2479",-1, 3,1.000000},
  {fuseki132478,6,"Fuseki2480", 1, 3,1.000000},
  {fuseki132479,6,"Fuseki2481",-1, 4,1.000000},
  {fuseki132480,6,"Fuseki2482",-2, 4,1.000000},
  {fuseki132481,13,"Fuseki2483", 5, 1,5.000000},
  {fuseki132482,7,"Fuseki2484",-4, 2,2.000000},
  {fuseki132483,7,"Fuseki2485", 3, 0,2.000000},
  {fuseki132484,7,"Fuseki2486",-4, 0,1.000000},
  {fuseki132485,12,"Fuseki2487",-5, 0,5.000000},
  {fuseki132486,7,"Fuseki2488",-4, 4,2.000000},
  {fuseki132487,7,"Fuseki2489", 0,-4,1.000000},
  {fuseki132488,7,"Fuseki2490",-4, 3,1.000000},
  {fuseki132489,7,"Fuseki2491",-5, 3,1.000000},
  {fuseki132490,10,"Fuseki2492", 5, 0,5.000000},
  {fuseki132491,13,"Fuseki2493",-4, 4,5.000000},
  {fuseki132492,11,"Fuseki2494", 4,-5,5.000000},
  {fuseki132493,6,"Fuseki2495", 2,-4,4.000000},
  {fuseki132494,7,"Fuseki2496", 1,-3,4.000000},
  {fuseki132495,4,"Fuseki2497", 4, 3,4.000000},
  {fuseki132496,12,"Fuseki2498",-1,-5,4.000000},
  {fuseki132497,12,"Fuseki2499", 0,-1,2.000000},
  {fuseki132498,12,"Fuseki2500", 0, 0,2.000000},
  {fuseki132499,6,"Fuseki2501", 2,-2,4.000000},
  {fuseki132500,12,"Fuseki2502", 5,-5,4.000000},
  {fuseki132501,13,"Fuseki2503", 4,-2,3.000000},
  {fuseki132502,13,"Fuseki2504", 2,-3,1.000000},
  {fuseki132503,12,"Fuseki2505", 2,-2,4.000000},
  {fuseki132504,11,"Fuseki2506", 3, 1,4.000000},
  {fuseki132505,5,"Fuseki2507",-1, 4,3.000000},
  {fuseki132506,5,"Fuseki2508",-4,-2,1.000000},
  {fuseki132507,12,"Fuseki2509",-1, 3,3.000000},
  {fuseki132508,12,"Fuseki2510",-3, 0,1.000000},
  {fuseki132509,12,"Fuseki2511", 3,-4,4.000000},
  {fuseki132510,5,"Fuseki2512", 4,-1,4.000000},
  {fuseki132511,9,"Fuseki2513", 4,-3,4.000000},
  {fuseki132512,7,"Fuseki2514", 0, 3,1.000000},
  {fuseki132513,7,"Fuseki2515",-4, 4,1.000000},
  {fuseki132514,7,"Fuseki2516", 5,-4,1.000000},
  {fuseki132515,7,"Fuseki2517",-2, 2,1.000000},
  {fuseki132516,12,"Fuseki2518", 5, 3,2.000000},
  {fuseki132517,12,"Fuseki2519", 4, 4,1.000000},
  {fuseki132518,12,"Fuseki2520",-4,-3,1.000000},
  {fuseki132519,11,"Fuseki2521", 3,-4,4.000000},
  {fuseki132520,7,"Fuseki2522", 4,-4,4.000000},
  {fuseki132521,14,"Fuseki2523",-3,-4,3.000000},
  {fuseki132522,14,"Fuseki2524", 4,-3,1.000000},
  {fuseki132523,5,"Fuseki2525", 1, 4,2.000000},
  {fuseki132524,5,"Fuseki2526",-1,-4,2.000000},
  {fuseki132525,7,"Fuseki2527", 3,-1,1.000000},
  {fuseki132526,7,"Fuseki2528", 5, 1,1.000000},
  {fuseki132527,7,"Fuseki2529",-4, 1,1.000000},
  {fuseki132528,7,"Fuseki2530",-4, 1,1.000000},
  {fuseki132529,7,"Fuseki2531",-4, 4,2.000000},
  {fuseki132530,7,"Fuseki2532",-1,-4,1.000000},
  {fuseki132531,7,"Fuseki2533",-4, 5,1.000000},
  {fuseki132532,6,"Fuseki2534",-3,-2,2.000000},
  {fuseki132533,6,"Fuseki2535",-2,-2,1.000000},
  {fuseki132534,6,"Fuseki2536",-4, 1,1.000000},
  {fuseki132535,9,"Fuseki2537",-1,-3,2.000000},
  {fuseki132536,9,"Fuseki2538",-1,-4,1.000000},
  {fuseki132537,9,"Fuseki2539", 0, 1,1.000000},
  {fuseki132538,3,"Fuseki2540",-4,-3,1.000000},
  {fuseki132539,3,"Fuseki2541", 0, 4,1.000000},
  {fuseki132540,3,"Fuseki2542",-3,-2,1.000000},
  {fuseki132541,3,"Fuseki2543",-4,-3,1.000000},
  {fuseki132542,10,"Fuseki2544", 5,-3,4.000000},
  {fuseki132543,7,"Fuseki2545", 1, 1,4.000000},
  {fuseki132544,13,"Fuseki2546",-2,-4,3.000000},
  {fuseki132545,13,"Fuseki2547",-2,-5,1.000000},
  {fuseki132546,6,"Fuseki2548",-5,-2,2.000000},
  {fuseki132547,6,"Fuseki2549", 2, 3,1.000000},
  {fuseki132548,6,"Fuseki2550", 3, 1,1.000000},
  {fuseki132549,9,"Fuseki2551", 3,-4,2.000000},
  {fuseki132550,9,"Fuseki2552", 5,-3,2.000000},
  {fuseki132551,11,"Fuseki2553", 2,-1,4.000000},
  {fuseki132552,9,"Fuseki2554", 4, 0,4.000000},
  {fuseki132553,13,"Fuseki2555",-4,-4,4.000000},
  {fuseki132554,8,"Fuseki2556", 4,-3,4.000000},
  {fuseki132555,10,"Fuseki2557", 3,-2,4.000000},
  {fuseki132556,5,"Fuseki2558",-3,-1,2.000000},
  {fuseki132557,5,"Fuseki2559",-1,-3,1.000000},
  {fuseki132558,5,"Fuseki2560", 4, 4,1.000000},
  {fuseki132559,8,"Fuseki2561", 4,-3,2.000000},
  {fuseki132560,8,"Fuseki2562",-4, 0,1.000000},
  {fuseki132561,8,"Fuseki2563", 3,-1,1.000000},
  {fuseki132562,13,"Fuseki2564", 0,-4,4.000000},
  {fuseki132563,9,"Fuseki2565", 4,-2,3.000000},
  {fuseki132564,9,"Fuseki2566",-3,-2,1.000000},
  {fuseki132565,8,"Fuseki2567", 2, 2,3.000000},
  {fuseki132566,8,"Fuseki2568",-4, 1,1.000000},
  {fuseki132567,8,"Fuseki2569", 1,-4,3.000000},
  {fuseki132568,8,"Fuseki2570", 4, 3,1.000000},
  {fuseki132569,3,"Fuseki2571",-4,-3,2.000000},
  {fuseki132570,3,"Fuseki2572", 0,-3,1.000000},
  {fuseki132571,3,"Fuseki2573",-3,-3,1.000000},
  {fuseki132572,6,"Fuseki2574", 4,-4,2.000000},
  {fuseki132573,6,"Fuseki2575", 1,-4,1.000000},
  {fuseki132574,6,"Fuseki2576",-5, 3,1.000000},
  {fuseki132575,8,"Fuseki2577",-4,-3,1.000000},
  {fuseki132576,8,"Fuseki2578",-3, 4,1.000000},
  {fuseki132577,8,"Fuseki2579",-4,-1,1.000000},
  {fuseki132578,8,"Fuseki2580", 3, 0,1.000000},
  {fuseki132579,5,"Fuseki2581",-1, 4,1.000000},
  {fuseki132580,5,"Fuseki2582", 1,-4,1.000000},
  {fuseki132581,5,"Fuseki2583", 4, 3,1.000000},
  {fuseki132582,5,"Fuseki2584", 3, 0,1.000000},
  {fuseki132583,6,"Fuseki2585", 3, 2,1.000000},
  {fuseki132584,6,"Fuseki2586",-4, 0,1.000000},
  {fuseki132585,6,"Fuseki2587", 2, 4,1.000000},
  {fuseki132586,6,"Fuseki2588",-4, 4,1.000000},
  {fuseki132587,7,"Fuseki2589",-3, 1,1.000000},
  {fuseki132588,7,"Fuseki2590",-2, 3,1.000000},
  {fuseki132589,7,"Fuseki2591", 5,-1,1.000000},
  {fuseki132590,5,"Fuseki2592",-3, 1,2.000000},
  {fuseki132591,5,"Fuseki2593",-2,-2,1.000000},
  {fuseki132592,7,"Fuseki2594",-1,-3,2.000000},
  {fuseki132593,7,"Fuseki2595",-2,-4,1.000000},
  {fuseki132594,6,"Fuseki2596", 0,-3,3.000000},
  {fuseki132595,8,"Fuseki2597", 5, 4,3.000000},
  {fuseki132596,8,"Fuseki2598", 2, 4,2.000000},
  {fuseki132597,8,"Fuseki2599", 1, 5,1.000000},
  {fuseki132598,6,"Fuseki2600",-1, 4,1.000000},
  {fuseki132599,6,"Fuseki2601",-4, 2,1.000000},
  {fuseki132600,6,"Fuseki2602", 4,-3,1.000000},
  {fuseki132601,6,"Fuseki2603", 3, 0,1.000000},
  {fuseki132602,6,"Fuseki2604", 0,-3,1.000000},
  {fuseki132603,6,"Fuseki2605", 2, 3,1.000000},
  {fuseki132604,6,"Fuseki2606", 4,-3,2.000000},
  {fuseki132605,6,"Fuseki2607", 4,-4,1.000000},
  {fuseki132606,11,"Fuseki2608", 5,-4,3.000000},
  {fuseki132607,4,"Fuseki2609", 3, 2,2.000000},
  {fuseki132608,5,"Fuseki2610",-2,-3,1.000000},
  {fuseki132609,5,"Fuseki2611",-3,-1,1.000000},
  {fuseki132610,5,"Fuseki2612",-3, 0,1.000000},
  {fuseki132611,4,"Fuseki2613", 3, 4,1.000000},
  {fuseki132612,4,"Fuseki2614", 4, 3,1.000000},
  {fuseki132613,4,"Fuseki2615", 4, 4,1.000000},
  {fuseki132614,7,"Fuseki2616", 3, 1,2.000000},
  {fuseki132615,7,"Fuseki2617",-3, 0,1.000000},
  {fuseki132616,15,"Fuseki2618",-3,-5,2.000000},
  {fuseki132617,15,"Fuseki2619",-6,-3,1.000000},
  {fuseki132618,11,"Fuseki2620",-1,-4,3.000000},
  {fuseki132619,9,"Fuseki2621",-3, 4,3.000000},
  {fuseki132620,7,"Fuseki2622",-2, 4,1.000000},
  {fuseki132621,7,"Fuseki2623",-3, 0,1.000000},
  {fuseki132622,7,"Fuseki2624", 4,-1,1.000000},
  {fuseki132623,9,"Fuseki2625", 4,-3,3.000000},
  {fuseki132624,14,"Fuseki2626", 2,-5,3.000000},
  {fuseki132625,9,"Fuseki2627",-3,-1,3.000000},
  {fuseki132626,14,"Fuseki2628",-1,-5,3.000000},
  {fuseki132627,5,"Fuseki2629", 4,-1,2.000000},
  {fuseki132628,5,"Fuseki2630",-4, 1,1.000000},
  {fuseki132629,10,"Fuseki2631",-1, 0,2.000000},
  {fuseki132630,10,"Fuseki2632", 1,-1,1.000000},
  {fuseki132631,13,"Fuseki2633", 0,-5,3.000000},
  {fuseki132632,5,"Fuseki2634", 1, 3,2.000000},
  {fuseki132633,5,"Fuseki2635",-1, 4,1.000000},
  {fuseki132634,4,"Fuseki2636", 4,-4,1.000000},
  {fuseki132635,4,"Fuseki2637",-4,-2,1.000000},
  {fuseki132636,4,"Fuseki2638", 4,-4,1.000000},
  {fuseki132637,13,"Fuseki2639",-2, 3,3.000000},
  {fuseki132638,14,"Fuseki2640", 0,-3,3.000000},
  {fuseki132639,15,"Fuseki2641",-4,-3,1.000000},
  {fuseki132640,15,"Fuseki2642",-4,-3,1.000000},
  {fuseki132641,15,"Fuseki2643",-3, 4,1.000000},
  {fuseki132642,12,"Fuseki2644",-5,-3,2.000000},
  {fuseki132643,12,"Fuseki2645",-4,-1,1.000000},
  {fuseki132644,10,"Fuseki2646", 4,-4,2.000000},
  {fuseki132645,10,"Fuseki2647",-1,-4,1.000000},
  {fuseki132646,8,"Fuseki2648", 3,-4,1.000000},
  {fuseki132647,8,"Fuseki2649",-4,-4,1.000000},
  {fuseki132648,8,"Fuseki2650", 2, 3,1.000000},
  {fuseki132649,6,"Fuseki2651", 4,-4,2.000000},
  {fuseki132650,6,"Fuseki2652", 3,-2,1.000000},
  {fuseki132651,13,"Fuseki2653",-4, 4,3.000000},
  {fuseki132652,9,"Fuseki2654", 4,-3,2.000000},
  {fuseki132653,9,"Fuseki2655", 2,-3,1.000000},
  {fuseki132654,13,"Fuseki2656", 5,-2,3.000000},
  {fuseki132655,13,"Fuseki2657", 4,-4,3.000000},
  {fuseki132656,7,"Fuseki2658",-1, 4,1.000000},
  {fuseki132657,7,"Fuseki2659",-4,-1,1.000000},
  {fuseki132658,7,"Fuseki2660",-4,-4,1.000000},
  {fuseki132659,13,"Fuseki2661", 4,-4,2.000000},
  {fuseki132660,13,"Fuseki2662", 5,-2,1.000000},
  {fuseki132661,10,"Fuseki2663",-4,-1,2.000000},
  {fuseki132662,10,"Fuseki2664",-4, 1,1.000000},
  {fuseki132663,9,"Fuseki2665", 4, 5,2.000000},
  {fuseki132664,9,"Fuseki2666", 3, 5,1.000000},
  {fuseki132665,12,"Fuseki2667",-2, 5,3.000000},
  {fuseki132666,6,"Fuseki2668",-1, 4,1.000000},
  {fuseki132667,6,"Fuseki2669",-4, 3,1.000000},
  {fuseki132668,6,"Fuseki2670",-4, 2,1.000000},
  {fuseki132669,5,"Fuseki2671",-1, 4,1.000000},
  {fuseki132670,5,"Fuseki2672", 0,-3,1.000000},
  {fuseki132671,5,"Fuseki2673",-3, 1,1.000000},
  {fuseki132672,7,"Fuseki2674", 0, 3,2.000000},
  {fuseki132673,7,"Fuseki2675",-4,-4,1.000000},
  {fuseki132674,5,"Fuseki2676", 3, 4,3.000000},
  {fuseki132675,13,"Fuseki2677",-2,-5,3.000000},
  {fuseki132676,10,"Fuseki2678", 5,-3,3.000000},
  {fuseki132677,12,"Fuseki2679",-1,-4,1.000000},
  {fuseki132678,12,"Fuseki2680", 0, 3,1.000000},
  {fuseki132679,12,"Fuseki2681", 0,-4,1.000000},
  {fuseki132680,7,"Fuseki2682", 3, 0,3.000000},
  {fuseki132681,8,"Fuseki2683", 3,-2,3.000000},
  {fuseki132682,12,"Fuseki2684",-2,-4,3.000000},
  {fuseki132683,6,"Fuseki2685", 0,-3,3.000000},
  {fuseki132684,5,"Fuseki2686", 4, 2,2.000000},
  {fuseki132685,5,"Fuseki2687",-1, 4,1.000000},
  {fuseki132686,8,"Fuseki2688", 3, 4,3.000000},
  {fuseki132687,10,"Fuseki2689", 1, 3,3.000000},
  {fuseki132688,4,"Fuseki2690",-4, 1,1.000000},
  {fuseki132689,4,"Fuseki2691", 3,-4,1.000000},
  {fuseki132690,4,"Fuseki2692",-1,-3,1.000000},
  {fuseki132691,5,"Fuseki2693",-4, 1,1.000000},
  {fuseki132692,5,"Fuseki2694",-1,-4,1.000000},
  {fuseki132693,5,"Fuseki2695",-4, 0,1.000000},
  {fuseki132694,5,"Fuseki2696",-4,-4,2.000000},
  {fuseki132695,5,"Fuseki2697", 4,-1,1.000000},
  {fuseki132696,7,"Fuseki2698",-1, 4,2.000000},
  {fuseki132697,7,"Fuseki2699", 3,-1,1.000000},
  {fuseki132698,10,"Fuseki2700", 1, 4,1.000000},
  {fuseki132699,10,"Fuseki2701", 4,-2,1.000000},
  {fuseki132700,10,"Fuseki2702", 0, 2,1.000000},
  {fuseki132701,7,"Fuseki2703",-1, 4,1.000000},
  {fuseki132702,7,"Fuseki2704",-4, 1,1.000000},
  {fuseki132703,7,"Fuseki2705",-4,-4,1.000000},
  {fuseki132704,10,"Fuseki2706", 3,-4,3.000000},
  {fuseki132705,4,"Fuseki2707", 4,-1,2.000000},
  {fuseki132706,4,"Fuseki2708",-4,-3,1.000000},
  {fuseki132707,7,"Fuseki2709", 1,-3,2.000000},
  {fuseki132708,7,"Fuseki2710",-4,-3,1.000000},
  {fuseki132709,9,"Fuseki2711", 0, 3,3.000000},
  {fuseki132710,9,"Fuseki2712", 4, 5,3.000000},
  {fuseki132711,12,"Fuseki2713", 3,-2,3.000000},
  {fuseki132712,14,"Fuseki2714",-4, 3,3.000000},
  {fuseki132713,7,"Fuseki2715",-3, 1,3.000000},
  {fuseki132714,11,"Fuseki2716",-1, 4,3.000000},
  {fuseki132715,5,"Fuseki2717", 4,-2,1.000000},
  {fuseki132716,5,"Fuseki2718",-1,-4,1.000000},
  {fuseki132717,5,"Fuseki2719",-4,-1,1.000000},
  {fuseki132718,8,"Fuseki2720", 2, 4,1.000000},
  {fuseki132719,8,"Fuseki2721", 4,-4,1.000000},
  {fuseki132720,8,"Fuseki2722",-1, 3,1.000000},
  {fuseki132721,6,"Fuseki2723",-3, 1,2.000000},
  {fuseki132722,6,"Fuseki2724",-3, 4,1.000000},
  {fuseki132723,4,"Fuseki2725", 3, 4,1.000000},
  {fuseki132724,4,"Fuseki2726",-1, 4,1.000000},
  {fuseki132725,4,"Fuseki2727",-1,-3,1.000000},
  {fuseki132726,14,"Fuseki2728",-2, 4,3.000000},
  {fuseki132727,11,"Fuseki2729", 5,-3,3.000000},
  {fuseki132728,9,"Fuseki2730", 4,-2,3.000000},
  {fuseki132729,5,"Fuseki2731", 4, 0,1.000000},
  {fuseki132730,5,"Fuseki2732", 4, 1,1.000000},
  {fuseki132731,5,"Fuseki2733", 5,-3,1.000000},
  {fuseki132732,6,"Fuseki2734", 3,-1,3.000000},
  {fuseki132733,10,"Fuseki2735", 3, 4,2.000000},
  {fuseki132734,10,"Fuseki2736", 3,-2,1.000000},
  {fuseki132735,7,"Fuseki2737", 2,-1,1.000000},
  {fuseki132736,7,"Fuseki2738",-4, 4,1.000000},
  {fuseki132737,7,"Fuseki2739", 4, 5,1.000000},
  {fuseki132738,6,"Fuseki2740",-2,-4,1.000000},
  {fuseki132739,6,"Fuseki2741",-3, 0,1.000000},
  {fuseki132740,6,"Fuseki2742", 1, 2,1.000000},
  {fuseki132741,5,"Fuseki2743", 0, 3,2.000000},
  {fuseki132742,5,"Fuseki2744",-1, 3,1.000000},
  {fuseki132743,12,"Fuseki2745", 3,-4,1.000000},
  {fuseki132744,12,"Fuseki2746",-5, 4,1.000000},
  {fuseki132745,14,"Fuseki2747",-2, 5,2.000000},
  {fuseki132746,10,"Fuseki2748", 2,-4,1.000000},
  {fuseki132747,10,"Fuseki2749", 1,-4,1.000000},
  {fuseki132748,8,"Fuseki2750",-4, 4,2.000000},
  {fuseki132749,15,"Fuseki2751", 3, 1,1.000000},
  {fuseki132750,15,"Fuseki2752", 2, 0,1.000000},
  {fuseki132751,6,"Fuseki2753",-4,-3,2.000000},
  {fuseki132752,10,"Fuseki2754", 4, 4,1.000000},
  {fuseki132753,10,"Fuseki2755", 3, 4,1.000000},
  {fuseki132754,8,"Fuseki2756", 3, 1,2.000000},
  {fuseki132755,5,"Fuseki2757", 0, 3,1.000000},
  {fuseki132756,5,"Fuseki2758", 0, 4,1.000000},
  {fuseki132757,17,"Fuseki2759",-5,-4,2.000000},
  {fuseki132758,6,"Fuseki2760",-3, 0,2.000000},
  {fuseki132759,6,"Fuseki2761",-4, 4,1.000000},
  {fuseki132760,6,"Fuseki2762",-4,-2,1.000000},
  {fuseki132761,9,"Fuseki2763",-5,-4,1.000000},
  {fuseki132762,9,"Fuseki2764",-1,-4,1.000000},
  {fuseki132763,7,"Fuseki2765", 2, 4,2.000000},
  {fuseki132764,9,"Fuseki2766",-5, 3,2.000000},
  {fuseki132765,8,"Fuseki2767",-4, 0,1.000000},
  {fuseki132766,8,"Fuseki2768", 4, 2,1.000000},
  {fuseki132767,14,"Fuseki2769", 2,-1,2.000000},
  {fuseki132768,5,"Fuseki2770", 2, 1,2.000000},
  {fuseki132769,10,"Fuseki2771",-4,-1,1.000000},
  {fuseki132770,10,"Fuseki2772", 4, 3,1.000000},
  {fuseki132771,10,"Fuseki2773",-5,-3,2.000000},
  {fuseki132772,5,"Fuseki2774",-4,-1,2.000000},
  {fuseki132773,5,"Fuseki2775", 0, 3,1.000000},
  {fuseki132774,5,"Fuseki2776", 0,-2,1.000000},
  {fuseki132775,7,"Fuseki2777", 1,-4,2.000000},
  {fuseki132776,7,"Fuseki2778", 1, 3,1.000000},
  {fuseki132777,7,"Fuseki2779", 0,-3,1.000000},
  {fuseki132778,7,"Fuseki2780", 3,-1,2.000000},
  {fuseki132779,13,"Fuseki2781",-1,-4,2.000000},
  {fuseki132780,7,"Fuseki2782",-2,-4,2.000000},
  {fuseki132781,6,"Fuseki2783",-4, 4,1.000000},
  {fuseki132782,6,"Fuseki2784", 4,-2,1.000000},
  {fuseki132783,4,"Fuseki2785", 3, 4,2.000000},
  {fuseki132784,9,"Fuseki2786", 3,-5,2.000000},
  {fuseki132785,7,"Fuseki2787",-1,-4,2.000000},
  {fuseki132786,13,"Fuseki2788", 5, 5,2.000000},
  {fuseki132787,7,"Fuseki2789", 3, 4,1.000000},
  {fuseki132788,7,"Fuseki2790",-4, 1,1.000000},
  {fuseki132789,7,"Fuseki2791", 2, 4,1.000000},
  {fuseki132790,7,"Fuseki2792",-4, 4,1.000000},
  {fuseki132791,12,"Fuseki2793",-1, 3,2.000000},
  {fuseki132792,6,"Fuseki2794",-3, 4,2.000000},
  {fuseki132793,10,"Fuseki2795",-4, 1,1.000000},
  {fuseki132794,10,"Fuseki2796", 4, 0,1.000000},
  {fuseki132795,7,"Fuseki2797",-3,-4,2.000000},
  {fuseki132796,8,"Fuseki2798", 4,-1,1.000000},
  {fuseki132797,8,"Fuseki2799", 5,-1,1.000000},
  {fuseki132798,9,"Fuseki2800",-2, 5,1.000000},
  {fuseki132799,9,"Fuseki2801",-3, 5,1.000000},
  {fuseki132800,11,"Fuseki2802", 3,-4,2.000000},
  {fuseki132801,8,"Fuseki2803",-3, 5,2.000000},
  {fuseki132802,6,"Fuseki2804", 1, 3,2.000000},
  {fuseki132803,8,"Fuseki2805", 2,-1,2.000000},
  {fuseki132804,8,"Fuseki2806", 4, 3,1.000000},
  {fuseki132805,8,"Fuseki2807", 2, 3,1.000000},
  {fuseki132806,8,"Fuseki2808", 0, 0,1.000000},
  {fuseki132807,8,"Fuseki2809", 1, 2,1.000000},
  {fuseki132808,11,"Fuseki2810",-4,-5,1.000000},
  {fuseki132809,11,"Fuseki2811",-4, 0,1.000000},
  {fuseki132810,6,"Fuseki2812", 1,-4,2.000000},
  {fuseki132811,9,"Fuseki2813",-3, 4,2.000000},
  {fuseki132812,10,"Fuseki2814", 4, 0,2.000000},
  {fuseki132813,5,"Fuseki2815", 4, 0,1.000000},
  {fuseki132814,5,"Fuseki2816",-1,-4,1.000000},
  {fuseki132815,10,"Fuseki2817", 1, 2,2.000000},
  {fuseki132816,9,"Fuseki2818", 3,-2,1.000000},
  {fuseki132817,9,"Fuseki2819", 5,-3,1.000000},
  {fuseki132818,8,"Fuseki2820", 4, 2,2.000000},
  {fuseki132819,5,"Fuseki2821",-4, 4,1.000000},
  {fuseki132820,5,"Fuseki2822",-4, 1,1.000000},
  {fuseki132821,12,"Fuseki2823",-1, 3,2.000000},
  {fuseki132822,5,"Fuseki2824", 3, 0,1.000000},
  {fuseki132823,5,"Fuseki2825", 4,-1,1.000000},
  {fuseki132824,11,"Fuseki2826",-2, 3,2.000000},
  {fuseki132825,9,"Fuseki2827",-5,-3,2.000000},
  {fuseki132826,10,"Fuseki2828", 3, 1,2.000000},
  {fuseki132827,4,"Fuseki2829", 1,-4,1.000000},
  {fuseki132828,4,"Fuseki2830",-2,-3,1.000000},
  {fuseki132829,7,"Fuseki2831", 4,-3,2.000000},
  {fuseki132830,8,"Fuseki2832", 5,-3,1.000000},
  {fuseki132831,8,"Fuseki2833", 3,-2,1.000000},
  {fuseki132832,10,"Fuseki2834", 4,-2,2.000000},
  {fuseki132833,13,"Fuseki2835", 2, 2,2.000000},
  {fuseki132834,14,"Fuseki2836", 3, 2,2.000000},
  {fuseki132835,7,"Fuseki2837",-1, 3,1.000000},
  {fuseki132836,7,"Fuseki2838", 1, 1,1.000000},
  {fuseki132837,9,"Fuseki2839", 0,-3,1.000000},
  {fuseki132838,9,"Fuseki2840", 1, 3,1.000000},
  {fuseki132839,7,"Fuseki2841", 2,-4,2.000000},
  {fuseki132840,6,"Fuseki2842",-1,-4,1.000000},
  {fuseki132841,6,"Fuseki2843", 2,-4,1.000000},
  {fuseki132842,8,"Fuseki2844", 2, 4,1.000000},
  {fuseki132843,8,"Fuseki2845", 0, 0,1.000000},
  {fuseki132844,7,"Fuseki2846",-3,-5,2.000000},
  {fuseki132845,16,"Fuseki2847",-1,-3,2.000000},
  {fuseki132846,10,"Fuseki2848",-1,-5,2.000000},
  {fuseki132847,13,"Fuseki2849", 1,-4,2.000000},
  {fuseki132848,12,"Fuseki2850", 2,-2,2.000000},
  {fuseki132849,8,"Fuseki2851", 2, 4,1.000000},
  {fuseki132850,8,"Fuseki2852",-4,-4,1.000000},
  {fuseki132851,8,"Fuseki2853",-4,-4,2.000000},
  {fuseki132852,8,"Fuseki2854", 3,-1,1.000000},
  {fuseki132853,8,"Fuseki2855",-3, 5,1.000000},
  {fuseki132854,5,"Fuseki2856",-3, 4,2.000000},
  {fuseki132855,5,"Fuseki2857", 4,-1,1.000000},
  {fuseki132856,5,"Fuseki2858", 0, 4,1.000000},
  {fuseki132857,9,"Fuseki2859", 2,-2,1.000000},
  {fuseki132858,9,"Fuseki2860", 5,-3,1.000000},
  {fuseki132859,9,"Fuseki2861", 5,-3,2.000000},
  {fuseki132860,4,"Fuseki2862", 3, 1,1.000000},
  {fuseki132861,4,"Fuseki2863",-3,-4,1.000000},
  {fuseki132862,14,"Fuseki2864", 4,-5,2.000000},
  {fuseki132863,11,"Fuseki2865", 5,-1,2.000000},
  {fuseki132864,8,"Fuseki2866",-4, 3,2.000000},
  {fuseki132865,7,"Fuseki2867",-5, 2,2.000000},
  {fuseki132866,11,"Fuseki2868",-2,-1,2.000000},
  {fuseki132867,7,"Fuseki2869",-4,-4,1.000000},
  {fuseki132868,7,"Fuseki2870",-1, 4,1.000000},
  {fuseki132869,7,"Fuseki2871",-2,-4,2.000000},
  {fuseki132870,8,"Fuseki2872", 2, 4,2.000000},
  {fuseki132871,9,"Fuseki2873", 3, 0,1.000000},
  {fuseki132872,9,"Fuseki2874", 1, 3,1.000000},
  {fuseki132873,7,"Fuseki2875",-4, 4,2.000000},
  {fuseki132874,8,"Fuseki2876", 1, 3,1.000000},
  {fuseki132875,8,"Fuseki2877",-1, 1,1.000000},
  {fuseki132876,6,"Fuseki2878",-1, 4,2.000000},
  {fuseki132877,13,"Fuseki2879",-2,-3,2.000000},
  {fuseki132878,8,"Fuseki2880", 4,-1,2.000000},
  {fuseki132879,7,"Fuseki2881", 4, 4,1.000000},
  {fuseki132880,7,"Fuseki2882", 2, 4,1.000000},
  {fuseki132881,11,"Fuseki2883", 5,-5,2.000000},
  {fuseki132882,11,"Fuseki2884",-3,-4,2.000000},
  {fuseki132883,10,"Fuseki2885", 3, 4,2.000000},
  {fuseki132884,7,"Fuseki2886",-5,-3,2.000000},
  {fuseki132885,5,"Fuseki2887",-4, 0,1.000000},
  {fuseki132886,5,"Fuseki2888", 4, 3,1.000000},
  {fuseki132887,5,"Fuseki2889",-4,-4,1.000000},
  {fuseki132888,5,"Fuseki2890", 3, 5,1.000000},
  {fuseki132889,8,"Fuseki2891",-5, 3,1.000000},
  {fuseki132890,8,"Fuseki2892", 2,-1,1.000000},
  {fuseki132891,9,"Fuseki2893", 1, 3,2.000000},
  {fuseki132892,6,"Fuseki2894", 4,-4,2.000000},
  {fuseki132893,11,"Fuseki2895", 3,-1,2.000000},
  {fuseki132894,9,"Fuseki2896",-4, 4,2.000000},
  {fuseki132895,6,"Fuseki2897", 4,-1,2.000000},
  {fuseki132896,7,"Fuseki2898", 1, 3,1.000000},
  {fuseki132897,7,"Fuseki2899",-2, 1,1.000000},
  {fuseki132898,10,"Fuseki2900",-2,-4,2.000000},
  {fuseki132899,10,"Fuseki2901",-4, 3,2.000000},
  {fuseki132900,11,"Fuseki2902",-5,-5,1.000000},
  {fuseki132901,11,"Fuseki2903",-2,-5,1.000000},
  {fuseki132902,7,"Fuseki2904", 2,-1,1.000000},
  {fuseki132903,7,"Fuseki2905",-4, 4,1.000000},
  {fuseki132904,11,"Fuseki2906", 6, 3,1.000000},
  {fuseki132905,7,"Fuseki2907",-3,-4,1.000000},
  {fuseki132906,7,"Fuseki2908",-5,-2,1.000000},
  {fuseki132907,7,"Fuseki2909",-2, 2,1.000000},
  {fuseki132908,7,"Fuseki2910",-4,-1,1.000000},
  {fuseki132909,10,"Fuseki2911",-5,-2,2.000000},
  {fuseki132910,12,"Fuseki2912",-3,-5,1.000000},
  {fuseki132911,12,"Fuseki2913",-4, 5,1.000000},
  {fuseki132912,11,"Fuseki2914",-4,-4,2.000000},
  {fuseki132913,10,"Fuseki2915",-4,-4,2.000000},
  {fuseki132914,7,"Fuseki2916",-4, 0,1.000000},
  {fuseki132915,7,"Fuseki2917", 2, 0,1.000000},
  {fuseki132916,11,"Fuseki2918", 4,-2,2.000000},
  {fuseki132917,9,"Fuseki2919", 3, 1,2.000000},
  {fuseki132918,8,"Fuseki2920",-4, 3,2.000000},
  {fuseki132919,7,"Fuseki2921", 0,-4,1.000000},
  {fuseki132920,7,"Fuseki2922",-1, 4,1.000000},
  {fuseki132921,8,"Fuseki2923", 4, 4,2.000000},
  {fuseki132922,8,"Fuseki2924",-3, 0,1.000000},
  {fuseki132923,8,"Fuseki2925", 4,-4,1.000000},
  {fuseki132924,18,"Fuseki2926",-5,-3,2.000000},
  {fuseki132925,5,"Fuseki2927", 0, 3,2.000000},
  {fuseki132926,11,"Fuseki2928", 2, 1,2.000000},
  {fuseki132927,8,"Fuseki2929", 4,-4,2.000000},
  {fuseki132928,7,"Fuseki2930",-3,-2,2.000000},
  {fuseki132929,6,"Fuseki2931", 1,-3,1.000000},
  {fuseki132930,6,"Fuseki2932", 4,-1,1.000000},
  {fuseki132931,12,"Fuseki2933", 5,-2,2.000000},
  {fuseki132932,9,"Fuseki2934",-4, 3,1.000000},
  {fuseki132933,9,"Fuseki2935",-3, 4,1.000000},
  {fuseki132934,6,"Fuseki2936", 4,-2,1.000000},
  {fuseki132935,6,"Fuseki2937", 4, 1,1.000000},
  {fuseki132936,6,"Fuseki2938", 2, 5,1.000000},
  {fuseki132937,6,"Fuseki2939", 2, 4,1.000000},
  {fuseki132938,12,"Fuseki2940",-5, 4,2.000000},
  {fuseki132939,11,"Fuseki2941",-1,-4,2.000000},
  {fuseki132940,7,"Fuseki2942", 2,-3,2.000000},
  {fuseki132941,8,"Fuseki2943", 2,-2,2.000000},
  {fuseki132942,10,"Fuseki2944", 4,-4,2.000000},
  {fuseki132943,13,"Fuseki2945", 2, 1,2.000000},
  {fuseki132944,8,"Fuseki2946",-2,-2,1.000000},
  {fuseki132945,8,"Fuseki2947",-4, 1,1.000000},
  {fuseki132946,12,"Fuseki2948", 0, 5,1.000000},
  {fuseki132947,12,"Fuseki2949",-5, 2,1.000000},
  {fuseki132948,6,"Fuseki2950",-2,-4,1.000000},
  {fuseki132949,6,"Fuseki2951",-4, 3,1.000000},
  {fuseki132950,7,"Fuseki2952",-3, 4,2.000000},
  {fuseki132951,13,"Fuseki2953", 5, 2,2.000000},
  {fuseki132952,5,"Fuseki2954", 1, 2,2.000000},
  {fuseki132953,8,"Fuseki2955",-1, 4,2.000000},
  {fuseki132954,5,"Fuseki2956", 4,-2,2.000000},
  {fuseki132955,9,"Fuseki2957",-1,-3,2.000000},
  {fuseki132956,13,"Fuseki2958",-1,-4,1.000000},
  {fuseki132957,13,"Fuseki2959",-1, 5,1.000000},
  {fuseki132958,8,"Fuseki2960",-3, 0,1.000000},
  {fuseki132959,8,"Fuseki2961", 2, 0,1.000000},
  {fuseki132960,11,"Fuseki2962",-1,-4,2.000000},
  {fuseki132961,5,"Fuseki2963",-3, 0,1.000000},
  {fuseki132962,5,"Fuseki2964", 1, 3,1.000000},
  {fuseki132963,6,"Fuseki2965",-4, 1,2.000000},
  {fuseki132964,9,"Fuseki2966",-3, 2,2.000000},
  {fuseki132965,6,"Fuseki2967", 3,-4,2.000000},
  {fuseki132966,9,"Fuseki2968", 1, 4,1.000000},
  {fuseki132967,9,"Fuseki2969", 4,-1,1.000000},
  {fuseki132968,9,"Fuseki2970", 0,-4,2.000000},
  {fuseki132969,8,"Fuseki2971",-5, 5,1.000000},
  {fuseki132970,8,"Fuseki2972",-5,-4,1.000000},
  {fuseki132971,8,"Fuseki2973",-2, 1,2.000000},
  {fuseki132972,4,"Fuseki2974", 4,-4,2.000000},
  {fuseki132973,8,"Fuseki2975",-1, 4,1.000000},
  {fuseki132974,8,"Fuseki2976",-1,-4,1.000000},
  {fuseki132975,7,"Fuseki2977",-4, 2,2.000000},
  {fuseki132976,7,"Fuseki2978",-3, 2,2.000000},
  {fuseki132977,9,"Fuseki2979", 1, 3,1.000000},
  {fuseki132978,9,"Fuseki2980", 4, 4,1.000000},
  {fuseki132979,7,"Fuseki2981", 5, 2,2.000000},
  {fuseki132980,4,"Fuseki2982", 3, 3,1.000000},
  {fuseki132981,4,"Fuseki2983", 3, 4,1.000000},
  {fuseki132982,7,"Fuseki2984", 4, 4,2.000000},
  {fuseki132983,10,"Fuseki2985", 1,-5,2.000000},
  {fuseki132984,9,"Fuseki2986", 1, 0,1.000000},
  {fuseki132985,9,"Fuseki2987", 4,-1,1.000000},
  {fuseki132986,12,"Fuseki2988", 4, 5,2.000000},
  {fuseki132987,9,"Fuseki2989",-1,-2,2.000000},
  {fuseki132988,11,"Fuseki2990",-2, 3,2.000000},
  {fuseki132989,8,"Fuseki2991", 4,-3,1.000000},
  {fuseki132990,8,"Fuseki2992",-1, 3,1.000000},
  {fuseki132991,9,"Fuseki2993",-4, 1,2.000000},
  {fuseki132992,6,"Fuseki2994", 2, 1,2.000000},
  {fuseki132993,7,"Fuseki2995", 0, 2,2.000000},
  {fuseki132994,6,"Fuseki2996",-3,-1,1.000000},
  {fuseki132995,6,"Fuseki2997", 2, 1,1.000000},
  {fuseki132996,8,"Fuseki2998",-2,-5,2.000000},
  {fuseki132997,9,"Fuseki2999",-4, 2,1.000000},
  {fuseki132998,9,"Fuseki3000", 4, 3,1.000000},
  {NULL,0,NULL,0,0,0.0}
};


/* mgena ===========================================================*/

/* mgena - fuseki19.c */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* #include <stdio.h>  */

/* #include "gnugo.h" */
/* #include "liberty.h" */
/* #include "patterns.h" */


static struct patval fuseki190[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki191[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki192[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki193[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki194[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki195[] = {
    {0,0,-1}}; /* Dummy element, not used. */

static struct patval fuseki196[] = {
   {-6,6,1}};

static struct patval fuseki197[] = {
   {6,-6,1}};

static struct patval fuseki198[] = {
   {6,-6,1}};

static struct patval fuseki199[] = {
   {-6,6,1}};

static struct patval fuseki1910[] = {
   {-6,6,1}};

static struct patval fuseki1911[] = {
   {-6,6,1}};

static struct patval fuseki1912[] = {
   {-6,6,1}};

static struct patval fuseki1913[] = {
   {-6,6,1}};

static struct patval fuseki1914[] = {
   {-6,6,1}};

static struct patval fuseki1915[] = {
   {-6,6,1}};

static struct patval fuseki1916[] = {
   {6,6,1}};

static struct patval fuseki1917[] = {
   {6,-6,1}};

static struct patval fuseki1918[] = {
   {-6,6,1}};

static struct patval fuseki1919[] = {
   {-6,6,1}};

static struct patval fuseki1920[] = {
   {-6,6,1}};

static struct patval fuseki1921[] = {
   {6,-6,1},
   {-6,6,2}};

static struct patval fuseki1922[] = {
   {6,-6,1},
   {-6,6,2}};

static struct patval fuseki1923[] = {
   {6,-6,1},
   {-6,6,2}};

static struct patval fuseki1924[] = {
   {6,-6,1},
   {-6,6,2}};

static struct patval fuseki1925[] = {
   {-6,6,1},
   {6,-6,2}};

static struct patval fuseki1926[] = {
   {6,-6,1},
   {-6,6,2}};

static struct patval fuseki1927[] = {
   {6,-6,1},
   {-6,6,2}};

static struct patval fuseki1928[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,2}};

static struct patval fuseki1929[] = {
   {6,6,1},
   {-6,6,1},
   {-6,-6,2}};

static struct patval fuseki1930[] = {
   {-6,6,1},
   {6,6,1},
   {6,-6,2}};

static struct patval fuseki1931[] = {
   {-6,6,1},
   {6,6,1},
   {6,-6,2}};

static struct patval fuseki1932[] = {
   {-6,6,1},
   {6,6,1},
   {6,-6,2}};

static struct patval fuseki1933[] = {
   {6,6,1},
   {-6,6,2}};

static struct patval fuseki1934[] = {
   {-6,-6,1},
   {-6,6,2}};

static struct patval fuseki1935[] = {
   {6,6,1},
   {-6,6,2}};

static struct patval fuseki1936[] = {
   {-6,-6,1},
   {-6,6,2}};

static struct patval fuseki1937[] = {
   {6,6,1},
   {6,-6,2}};

static struct patval fuseki1938[] = {
   {-6,6,1},
   {6,6,2}};

static struct patval fuseki1939[] = {
   {6,6,1},
   {-6,6,2}};

static struct patval fuseki1940[] = {
   {6,6,1},
   {-6,6,2}};

static struct patval fuseki1941[] = {
   {-6,6,1},
   {7,6,1},
   {6,-6,2}};

static struct patval fuseki1942[] = {
   {-6,6,1},
   {7,6,1},
   {6,-6,2}};

static struct patval fuseki1943[] = {
   {-6,6,1},
   {7,6,1},
   {6,-6,2}};

static struct patval fuseki1944[] = {
   {-6,6,1},
   {7,6,1},
   {6,-6,2}};

static struct patval fuseki1945[] = {
   {-6,6,1},
   {7,6,1},
   {6,-6,2}};

static struct patval fuseki1946[] = {
   {-6,6,1},
   {7,6,1},
   {6,-6,2}};

static struct patval fuseki1947[] = {
   {-6,7,1}};

static struct patval fuseki1948[] = {
   {-6,7,1}};

static struct patval fuseki1949[] = {
   {-6,7,1}};

static struct patval fuseki1950[] = {
   {7,6,1}};

static struct patval fuseki1951[] = {
   {7,-6,1}};

static struct patval fuseki1952[] = {
   {-6,7,1}};

static struct patval fuseki1953[] = {
   {7,6,1}};

static struct patval fuseki1954[] = {
   {-7,-6,1}};

static struct patval fuseki1955[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki1956[] = {
   {-6,-6,1},
   {-6,7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki1957[] = {
   {7,6,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1958[] = {
   {6,6,1},
   {6,-7,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki1959[] = {
   {7,6,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1960[] = {
   {-6,-7,1},
   {-6,6,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki1961[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki1962[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki1963[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki1964[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,2},
   {6,7,2}};

static struct patval fuseki1965[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki1966[] = {
   {6,6,1},
   {6,-6,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki1967[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki1968[] = {
   {7,6,1},
   {6,-6,2}};

static struct patval fuseki1969[] = {
   {-7,-6,1},
   {-6,6,2}};

static struct patval fuseki1970[] = {
   {6,7,1},
   {-6,6,2}};

static struct patval fuseki1971[] = {
   {6,7,1},
   {-6,6,2}};

static struct patval fuseki1972[] = {
   {-7,-6,1},
   {-6,6,2}};

static struct patval fuseki1973[] = {
   {6,-7,1},
   {-6,-6,2}};

static struct patval fuseki1974[] = {
   {6,7,1},
   {-6,6,2}};

static struct patval fuseki1975[] = {
   {6,6,1},
   {6,-6,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki1976[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki1977[] = {
   {6,6,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1978[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki1979[] = {
   {6,6,1},
   {6,-6,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki1980[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1981[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1982[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1983[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1984[] = {
   {-6,-7,1},
   {-6,6,1},
   {4,-7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki1985[] = {
   {6,7,1},
   {6,-6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki1986[] = {
   {7,6,1},
   {-6,6,1},
   {-6,-6,2}};

static struct patval fuseki1987[] = {
   {-7,6,1},
   {6,6,1},
   {6,-6,2}};

static struct patval fuseki1988[] = {
   {7,6,1},
   {-6,6,1},
   {-6,-6,2}};

static struct patval fuseki1989[] = {
   {7,6,1},
   {-6,6,1},
   {-6,-6,2}};

static struct patval fuseki1990[] = {
   {7,6,1},
   {-6,6,1},
   {-6,-6,2}};

static struct patval fuseki1991[] = {
   {7,-4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1992[] = {
   {7,-4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1993[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1994[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki1995[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki1996[] = {
   {6,6,1},
   {6,-6,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki1997[] = {
   {-6,-6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki1998[] = {
   {6,6,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki1999[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,7,2}};

static struct patval fuseki19100[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-7,2}};

static struct patval fuseki19101[] = {
   {6,6,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19102[] = {
   {6,-6,1},
   {-6,7,2}};

static struct patval fuseki19103[] = {
   {6,-6,1},
   {-6,7,2}};

static struct patval fuseki19104[] = {
   {6,6,1},
   {-7,-6,2}};

static struct patval fuseki19105[] = {
   {6,-6,1},
   {-6,7,2}};

static struct patval fuseki19106[] = {
   {6,-6,1},
   {-7,6,2}};

static struct patval fuseki19107[] = {
   {6,-6,1},
   {-6,7,2}};

static struct patval fuseki19108[] = {
   {6,6,1},
   {-6,6,1},
   {0,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19109[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19110[] = {
   {6,6,1},
   {-6,6,1},
   {0,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19111[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19112[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19113[] = {
   {-6,-6,1},
   {-6,7,1},
   {6,-7,2},
   {6,6,2}};

static struct patval fuseki19114[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19115[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19116[] = {
   {-7,6,1},
   {6,6,1},
   {-6,-6,2},
   {7,-6,2}};

static struct patval fuseki19117[] = {
   {-6,6,1},
   {6,7,1},
   {6,-6,2}};

static struct patval fuseki19118[] = {
   {-6,6,1},
   {6,7,1},
   {6,-6,2}};

static struct patval fuseki19119[] = {
   {6,6,1},
   {-6,7,1},
   {-6,-6,2}};

static struct patval fuseki19120[] = {
   {-6,6,1},
   {6,7,1},
   {6,-6,2}};

static struct patval fuseki19121[] = {
   {6,6,1},
   {-6,6,1},
   {-5,-6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19122[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-5,1},
   {6,-7,2},
   {6,6,2}};

static struct patval fuseki19123[] = {
   {6,6,1},
   {-6,6,1},
   {5,-6,1},
   {-6,-6,2},
   {7,-6,2}};

static struct patval fuseki19124[] = {
   {6,6,1},
   {-6,6,1},
   {-5,-6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19125[] = {
   {6,6,1},
   {6,0,1},
   {6,-6,1},
   {-6,7,2},
   {-6,-6,2}};

static struct patval fuseki19126[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {6,-7,2},
   {6,6,2}};

static struct patval fuseki19127[] = {
   {-6,-6,1},
   {-6,7,2}};

static struct patval fuseki19128[] = {
   {-6,-6,1},
   {-6,7,2}};

static struct patval fuseki19129[] = {
   {6,6,1},
   {-7,6,2}};

static struct patval fuseki19130[] = {
   {-6,-6,1},
   {-6,7,2}};

static struct patval fuseki19131[] = {
   {-7,4,1},
   {-6,-6,1},
   {6,-6,1},
   {0,6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19132[] = {
   {-6,-6,1},
   {7,4,1},
   {6,-6,1},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19133[] = {
   {-6,-6,1},
   {7,4,1},
   {6,-6,1},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19134[] = {
   {6,-6,1},
   {6,6,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,0,2}};

static struct patval fuseki19135[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {6,7,2}};

static struct patval fuseki19136[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,7,2},
   {6,6,2}};

static struct patval fuseki19137[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {6,7,2}};

static struct patval fuseki19138[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,7,2},
   {6,6,2}};

static struct patval fuseki19139[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,7,2},
   {6,6,2}};

static struct patval fuseki19140[] = {
   {6,6,1},
   {6,-6,1},
   {-6,6,2},
   {-7,-6,2}};

static struct patval fuseki19141[] = {
   {7,6,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19142[] = {
   {-6,-6,1},
   {-6,7,1},
   {6,-7,2}};

static struct patval fuseki19143[] = {
   {-6,-7,1},
   {-6,6,1},
   {6,7,2}};

static struct patval fuseki19144[] = {
   {7,6,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19145[] = {
   {-7,-6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki19146[] = {
   {-7,-6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki19147[] = {
   {7,6,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19148[] = {
   {0,0,1}};

static struct patval fuseki19149[] = {
   {6,-7,1},
   {6,6,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,0,2}};

static struct patval fuseki19150[] = {
   {-6,-6,1},
   {-6,7,1},
   {4,7,1},
   {6,-6,2},
   {6,0,2},
   {6,6,2}};

static struct patval fuseki19151[] = {
   {-7,-6,1},
   {-7,4,1},
   {6,-6,1},
   {0,6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19152[] = {
   {-7,-6,1},
   {-7,4,1},
   {6,-6,1},
   {0,6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19153[] = {
   {-7,-6,1},
   {-7,4,1},
   {6,-6,1},
   {0,6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19154[] = {
   {6,-7,1},
   {-6,6,2}};

static struct patval fuseki19155[] = {
   {7,-6,1},
   {-6,6,2}};

static struct patval fuseki19156[] = {
   {7,-6,1},
   {-6,6,2}};

static struct patval fuseki19157[] = {
   {7,-6,1},
   {-6,6,2}};

static struct patval fuseki19158[] = {
   {7,-6,1},
   {-6,6,2}};

static struct patval fuseki19159[] = {
   {6,-7,1},
   {-6,6,2}};

static struct patval fuseki19160[] = {
   {-7,-6,1},
   {6,6,2}};

static struct patval fuseki19161[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,7,2},
   {7,6,2}};

static struct patval fuseki19162[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,7,2},
   {7,6,2}};

static struct patval fuseki19163[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,7,2},
   {7,6,2}};

static struct patval fuseki19164[] = {
   {6,6,1},
   {-6,6,1},
   {-6,-7,2},
   {7,-6,2}};

static struct patval fuseki19165[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,7,2},
   {7,6,2}};

static struct patval fuseki19166[] = {
   {-6,7,1},
   {7,6,1},
   {6,-6,2}};

static struct patval fuseki19167[] = {
   {-6,7,1},
   {7,6,1},
   {6,-6,2}};

static struct patval fuseki19168[] = {
   {-7,6,1},
   {-6,-7,1},
   {6,-6,2}};

static struct patval fuseki19169[] = {
   {-7,-5,1},
   {-6,6,2}};

static struct patval fuseki19170[] = {
   {-7,-5,1},
   {-6,6,2}};

static struct patval fuseki19171[] = {
   {-5,7,1},
   {6,6,2}};

static struct patval fuseki19172[] = {
   {-7,-5,1},
   {-6,6,2}};

static struct patval fuseki19173[] = {
   {-7,-5,1},
   {-6,6,2}};

static struct patval fuseki19174[] = {
   {-7,-5,1},
   {-6,6,2}};

static struct patval fuseki19175[] = {
   {-6,7,1},
   {6,6,1},
   {6,-6,2}};

static struct patval fuseki19176[] = {
   {-6,7,1},
   {6,6,1},
   {6,-6,2}};

static struct patval fuseki19177[] = {
   {-7,-6,1},
   {-6,6,1},
   {6,6,2}};

static struct patval fuseki19178[] = {
   {6,-5,1}};

static struct patval fuseki19179[] = {
   {-6,5,1}};

static struct patval fuseki19180[] = {
   {6,-5,1}};

static struct patval fuseki19181[] = {
   {7,6,1},
   {-6,6,1},
   {1,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19182[] = {
   {7,6,1},
   {-6,6,1},
   {1,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19183[] = {
   {7,-1,1},
   {6,6,1},
   {6,-7,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19184[] = {
   {7,-1,1},
   {6,6,1},
   {6,-7,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19185[] = {
   {7,6,1},
   {-6,6,1},
   {1,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19186[] = {
   {-7,6,1},
   {6,6,1},
   {-1,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19187[] = {
   {7,6,1},
   {-6,7,1},
   {-6,-6,2}};

static struct patval fuseki19188[] = {
   {7,6,1},
   {-6,7,1},
   {-6,-6,2}};

static struct patval fuseki19189[] = {
   {7,6,1},
   {-6,7,1},
   {-6,-6,2}};

static struct patval fuseki19190[] = {
   {-7,-6,1},
   {-6,7,1},
   {6,-6,2}};

static struct patval fuseki19191[] = {
   {-7,4,1},
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19192[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,6,1},
   {-6,-6,2},
   {7,-6,2}};

static struct patval fuseki19193[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,6,1},
   {-6,-6,2},
   {7,-6,2}};

static struct patval fuseki19194[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,6,1},
   {-6,-6,2},
   {7,-6,2}};

static struct patval fuseki19195[] = {
   {6,6,1},
   {6,-6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19196[] = {
   {-6,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki19197[] = {
   {6,-6,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19198[] = {
   {-6,6,1},
   {6,-6,1},
   {6,7,2}};

static struct patval fuseki19199[] = {
   {6,-6,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19200[] = {
   {-6,6,1},
   {6,-6,1},
   {6,7,2}};

static struct patval fuseki19201[] = {
   {6,-6,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19202[] = {
   {-6,6,1},
   {6,-6,1},
   {6,7,2}};

static struct patval fuseki19203[] = {
   {7,6,1},
   {-6,6,1},
   {1,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19204[] = {
   {7,6,1},
   {-6,6,1},
   {1,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19205[] = {
   {-6,-6,1},
   {-6,1,1},
   {-6,7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19206[] = {
   {6,7,1},
   {6,1,1},
   {6,-6,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19207[] = {
   {7,6,1},
   {-6,6,1},
   {1,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19208[] = {
   {7,6,1},
   {-6,6,1},
   {1,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19209[] = {
   {-7,-6,1},
   {6,-6,1},
   {-2,-6,1},
   {-5,-6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19210[] = {
   {-7,-6,1},
   {6,-6,1},
   {-2,-6,1},
   {-5,-6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19211[] = {
   {-7,-6,1},
   {6,-6,1},
   {-2,-6,1},
   {-5,-6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19212[] = {
   {-7,-6,1},
   {6,-6,1},
   {-2,-6,1},
   {-5,-6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19213[] = {
   {-6,6,1},
   {0,0,2}};

static struct patval fuseki19214[] = {
   {-6,-6,1},
   {0,0,2}};

static struct patval fuseki19215[] = {
   {-6,6,1},
   {0,0,2}};

static struct patval fuseki19216[] = {
   {6,-6,1},
   {0,0,2}};

static struct patval fuseki19217[] = {
   {-6,6,1},
   {0,0,2}};

static struct patval fuseki19218[] = {
   {6,6,1},
   {0,0,2}};

static struct patval fuseki19219[] = {
   {6,6,1},
   {0,0,2}};

static struct patval fuseki19220[] = {
   {-7,5,1}};

static struct patval fuseki19221[] = {
   {-5,7,1}};

static struct patval fuseki19222[] = {
   {-5,7,1}};

static struct patval fuseki19223[] = {
   {-7,5,1}};

static struct patval fuseki19224[] = {
   {-5,7,1}};

static struct patval fuseki19225[] = {
   {-7,2,1},
   {6,6,1},
   {0,6,1},
   {-6,6,1},
   {-6,-6,2},
   {6,-6,2},
   {-7,4,2}};

static struct patval fuseki19226[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {-2,-7,1},
   {-4,-7,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19227[] = {
   {7,2,1},
   {-6,6,1},
   {0,6,1},
   {6,6,1},
   {6,-6,2},
   {-6,-6,2},
   {7,4,2}};

static struct patval fuseki19228[] = {
   {-7,-6,1},
   {7,-6,1},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19229[] = {
   {-7,-6,1},
   {7,-6,1},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19230[] = {
   {-7,6,1},
   {7,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19231[] = {
   {6,-6,1},
   {5,7,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19232[] = {
   {-7,-5,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19233[] = {
   {-6,-6,1},
   {-5,7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19234[] = {
   {-7,-5,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19235[] = {
   {-6,-6,1},
   {-5,7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19236[] = {
   {-6,6,1},
   {-5,-7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19237[] = {
   {6,6,1},
   {6,-7,1},
   {-6,-6,2},
   {-7,6,2}};

static struct patval fuseki19238[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,6,2},
   {6,7,2}};

static struct patval fuseki19239[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,6,2},
   {6,7,2}};

static struct patval fuseki19240[] = {
   {-6,-6,1},
   {7,-6,1},
   {6,6,2},
   {-6,7,2}};

static struct patval fuseki19241[] = {
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki19242[] = {
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki19243[] = {
   {-6,-6,1},
   {6,-6,1},
   {4,-7,1},
   {-6,6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19244[] = {
   {6,-6,1},
   {-6,-6,1},
   {-4,-7,1},
   {-6,6,2},
   {-7,-4,2},
   {6,6,2}};

static struct patval fuseki19245[] = {
   {-6,-6,1},
   {6,-6,1},
   {4,-7,1},
   {-6,6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19246[] = {
   {-7,-6,1},
   {-6,7,2}};

static struct patval fuseki19247[] = {
   {6,-7,1},
   {-7,-6,2}};

static struct patval fuseki19248[] = {
   {6,7,1},
   {-7,6,2}};

static struct patval fuseki19249[] = {
   {6,7,1},
   {-7,6,2}};

static struct patval fuseki19250[] = {
   {-7,-6,1},
   {-6,7,2}};

static struct patval fuseki19251[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19252[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19253[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19254[] = {
   {6,7,1},
   {6,-6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19255[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19256[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19257[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19258[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19259[] = {
   {6,7,1},
   {6,-6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19260[] = {
   {-7,-6,1},
   {6,-7,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19261[] = {
   {-7,-6,1},
   {6,-7,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19262[] = {
   {7,6,1},
   {6,-7,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19263[] = {
   {7,-6,1},
   {6,7,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19264[] = {
   {-6,-6,1},
   {6,-6,1},
   {4,-7,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19265[] = {
   {6,6,1},
   {-6,6,1},
   {4,7,1},
   {-6,-6,2},
   {7,-6,2},
   {7,4,2}};

static struct patval fuseki19266[] = {
   {-6,-6,1},
   {6,-6,1},
   {4,-7,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19267[] = {
   {-6,-6,1},
   {7,-2,1},
   {6,-6,1},
   {6,6,2},
   {7,-4,2},
   {-6,6,2}};

static struct patval fuseki19268[] = {
   {6,-6,1},
   {-7,-2,1},
   {-6,-6,1},
   {-6,6,2},
   {-7,-4,2},
   {6,6,2}};

static struct patval fuseki19269[] = {
   {-6,-6,1},
   {7,-2,1},
   {6,-6,1},
   {6,6,2},
   {7,-4,2},
   {-6,6,2}};

static struct patval fuseki19270[] = {
   {7,5,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19271[] = {
   {7,5,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19272[] = {
   {7,5,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19273[] = {
   {-7,5,1},
   {7,6,1},
   {-6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19274[] = {
   {-7,5,1},
   {7,6,1},
   {-6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19275[] = {
   {-7,5,1},
   {7,6,1},
   {-6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19276[] = {
   {-7,6,1},
   {-6,-7,1},
   {-5,7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19277[] = {
   {-6,6,1},
   {6,6,1},
   {6,-7,2}};

static struct patval fuseki19278[] = {
   {6,6,1},
   {6,-6,1},
   {-7,6,2}};

static struct patval fuseki19279[] = {
   {7,7,1}};

static struct patval fuseki19280[] = {
   {-7,7,1}};

static struct patval fuseki19281[] = {
   {-7,7,1}};

static struct patval fuseki19282[] = {
   {7,-7,1}};

static struct patval fuseki19283[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {-2,-7,1},
   {-4,-7,2},
   {6,-7,2},
   {6,6,2}};

static struct patval fuseki19284[] = {
   {0,6,1},
   {-7,2,1},
   {6,6,1},
   {-6,6,1},
   {-7,-6,2},
   {6,-6,2},
   {-7,4,2}};

static struct patval fuseki19285[] = {
   {0,6,1},
   {-7,2,1},
   {6,6,1},
   {-6,6,1},
   {-7,-6,2},
   {6,-6,2},
   {-7,4,2}};

static struct patval fuseki19286[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {-2,7,1},
   {-4,7,2},
   {6,-6,2},
   {6,7,2}};

static struct patval fuseki19287[] = {
   {0,6,1},
   {-7,2,1},
   {6,6,1},
   {-6,6,1},
   {-7,-6,2},
   {6,-6,2},
   {-7,4,2}};

static struct patval fuseki19288[] = {
   {6,6,1},
   {7,-5,1},
   {6,-7,1},
   {6,-5,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki19289[] = {
   {-7,-6,1},
   {6,-6,1},
   {-5,-7,1},
   {-5,-6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19290[] = {
   {-7,6,1},
   {-6,-6,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19291[] = {
   {-6,-7,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19292[] = {
   {-7,-6,1},
   {-6,6,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19293[] = {
   {6,7,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19294[] = {
   {7,6,1},
   {-6,6,1},
   {-5,-6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19295[] = {
   {7,6,1},
   {-6,6,1},
   {-5,-6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19296[] = {
   {-7,-6,1},
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19297[] = {
   {7,6,1},
   {-6,6,1},
   {-5,-6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19298[] = {
   {-6,-7,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki19299[] = {
   {-7,-6,1},
   {-6,6,1},
   {6,7,2}};

static struct patval fuseki19300[] = {
   {-7,-6,1},
   {-6,6,1},
   {6,7,2}};

static struct patval fuseki19301[] = {
   {6,7,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19302[] = {
   {-7,-6,1},
   {-6,6,1},
   {6,7,2}};

static struct patval fuseki19303[] = {
   {6,-6,1},
   {-6,-6,1},
   {-4,-6,1},
   {-6,6,2},
   {-7,-4,2},
   {6,6,2}};

static struct patval fuseki19304[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {-4,7,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19305[] = {
   {6,-4,1},
   {6,6,1},
   {6,-6,1},
   {4,-7,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki19306[] = {
   {7,6,1},
   {-6,6,1},
   {5,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19307[] = {
   {7,6,1},
   {-6,6,1},
   {5,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19308[] = {
   {7,6,1},
   {-6,6,1},
   {5,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19309[] = {
   {7,6,1},
   {-6,6,1},
   {5,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19310[] = {
   {-6,-6,1},
   {6,-6,1},
   {4,-6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19311[] = {
   {-6,-6,1},
   {6,-6,1},
   {4,-6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19312[] = {
   {-6,-6,1},
   {6,-6,1},
   {4,-6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19313[] = {
   {5,6,1},
   {-6,6,2}};

static struct patval fuseki19314[] = {
   {5,6,1},
   {-6,6,2}};

static struct patval fuseki19315[] = {
   {5,6,1},
   {-6,6,2}};

static struct patval fuseki19316[] = {
   {5,6,1},
   {-6,6,2}};

static struct patval fuseki19317[] = {
   {6,-5,1},
   {6,6,2}};

static struct patval fuseki19318[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-5,1},
   {6,6,2},
   {7,-5,2},
   {6,-7,2}};

static struct patval fuseki19319[] = {
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki19320[] = {
   {6,6,1},
   {-6,7,2}};

static struct patval fuseki19321[] = {
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki19322[] = {
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19323[] = {
   {6,6,1},
   {-6,7,2}};

static struct patval fuseki19324[] = {
   {6,6,1},
   {-6,7,2}};

static struct patval fuseki19325[] = {
   {6,6,1},
   {-6,7,2}};

static struct patval fuseki19326[] = {
   {-6,-6,1},
   {-7,6,2}};

static struct patval fuseki19327[] = {
   {-7,-6,1},
   {-6,-7,1},
   {6,-6,1},
   {-5,-7,1},
   {-5,-6,2},
   {-4,-7,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19328[] = {
   {7,-5,1},
   {7,-6,1},
   {6,-7,1},
   {6,6,1},
   {6,-5,2},
   {-6,6,2},
   {-6,-6,2},
   {7,-4,2}};

static struct patval fuseki19329[] = {
   {-7,-6,1},
   {-6,-7,1},
   {6,-6,1},
   {-5,-7,1},
   {-5,-6,2},
   {-4,-7,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19330[] = {
   {-7,-6,1},
   {-6,-7,1},
   {6,-6,1},
   {-5,-7,1},
   {-5,-6,2},
   {-4,-7,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19331[] = {
   {6,-6,1},
   {-7,4,1},
   {-7,7,1},
   {-6,-6,1},
   {-6,6,2},
   {0,6,2},
   {-7,2,2},
   {6,6,2}};

static struct patval fuseki19332[] = {
   {-6,-6,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki19333[] = {
   {6,-6,1},
   {-6,6,1},
   {-6,-6,2},
   {6,6,2}};

static struct patval fuseki19334[] = {
   {7,-4,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19335[] = {
   {-7,-6,1},
   {-6,6,1},
   {4,-7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19336[] = {
   {7,-4,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19337[] = {
   {-7,-6,1},
   {-6,6,1},
   {4,-7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19338[] = {
   {7,-4,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19339[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19340[] = {
   {7,-4,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19341[] = {
   {7,-4,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19342[] = {
   {-7,2,1},
   {6,6,1},
   {0,6,1},
   {-6,7,1},
   {-6,6,1},
   {-6,-6,2},
   {-7,7,2},
   {6,-6,2},
   {-7,4,2}};

static struct patval fuseki19343[] = {
   {-6,-7,1},
   {-6,6,2}};

static struct patval fuseki19344[] = {
   {-6,-7,1},
   {-6,6,2}};

static struct patval fuseki19345[] = {
   {7,6,1},
   {-6,6,2}};

static struct patval fuseki19346[] = {
   {7,6,1},
   {-6,6,2}};

static struct patval fuseki19347[] = {
   {7,6,1},
   {-6,6,2}};

static struct patval fuseki19348[] = {
   {7,-7,1},
   {-6,6,2}};

static struct patval fuseki19349[] = {
   {-7,-7,1},
   {6,6,2}};

static struct patval fuseki19350[] = {
   {7,-7,1},
   {-6,6,2}};

static struct patval fuseki19351[] = {
   {-7,7,1},
   {6,-6,2}};

static struct patval fuseki19352[] = {
   {6,6,1},
   {-6,6,1},
   {-5,-7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19353[] = {
   {6,6,1},
   {-6,6,1},
   {-5,-7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19354[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,-5,1},
   {6,6,2},
   {6,-7,2}};

static struct patval fuseki19355[] = {
   {6,-6,1},
   {-6,-6,1},
   {-5,7,1},
   {-7,6,2},
   {6,6,2}};

static struct patval fuseki19356[] = {
   {6,6,1},
   {-6,6,1},
   {-5,-7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19357[] = {
   {6,6,1},
   {-6,6,1},
   {5,-7,1},
   {-6,-6,2},
   {7,-6,2}};

static struct patval fuseki19358[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,5,1},
   {6,7,2},
   {6,-6,2}};

static struct patval fuseki19359[] = {
   {-7,-6,1},
   {7,4,1},
   {6,-6,1},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19360[] = {
   {-7,-6,1},
   {7,4,1},
   {6,-6,1},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19361[] = {
   {6,-7,1},
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,0,2}};

static struct patval fuseki19362[] = {
   {6,-6,1},
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,0,2}};

static struct patval fuseki19363[] = {
   {-7,-6,1},
   {7,4,1},
   {6,-6,1},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19364[] = {
   {-7,-6,1},
   {7,4,1},
   {6,-6,1},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19365[] = {
   {6,-6,1},
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,0,2}};

static struct patval fuseki19366[] = {
   {-7,-6,1},
   {7,4,1},
   {6,-6,1},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19367[] = {
   {-7,4,1},
   {-6,-6,1},
   {7,-6,1},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19368[] = {
   {-6,-5,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19369[] = {
   {-6,-5,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19370[] = {
   {-6,-5,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19371[] = {
   {6,6,1},
   {5,-6,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19372[] = {
   {6,-6,1},
   {-5,6,2}};

static struct patval fuseki19373[] = {
   {6,-6,1},
   {-6,5,2}};

static struct patval fuseki19374[] = {
   {-6,6,1},
   {5,-6,2}};

static struct patval fuseki19375[] = {
   {6,-6,1},
   {-6,5,2}};

static struct patval fuseki19376[] = {
   {-6,6,1},
   {6,-5,2}};

static struct patval fuseki19377[] = {
   {6,-6,1},
   {-6,5,2}};

static struct patval fuseki19378[] = {
   {6,-6,1},
   {-6,5,2}};

static struct patval fuseki19379[] = {
   {-6,6,1},
   {6,-5,2}};

static struct patval fuseki19380[] = {
   {6,-6,1},
   {-5,6,2}};

static struct patval fuseki19381[] = {
   {6,-6,1},
   {-6,5,2}};

static struct patval fuseki19382[] = {
   {-6,-6,1},
   {6,-6,1},
   {0,7,1},
   {-6,6,2},
   {6,7,2},
   {7,5,2}};

static struct patval fuseki19383[] = {
   {-6,-6,1},
   {6,-6,1},
   {0,7,1},
   {-6,6,2},
   {6,7,2},
   {7,5,2}};

static struct patval fuseki19384[] = {
   {-6,-6,1},
   {6,-6,1},
   {0,7,1},
   {-6,6,2},
   {6,7,2},
   {7,5,2}};

static struct patval fuseki19385[] = {
   {-6,-6,1},
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19386[] = {
   {-6,-6,1},
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19387[] = {
   {-6,-6,1},
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19388[] = {
   {-6,-6,1},
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19389[] = {
   {-6,-6,1},
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19390[] = {
   {-6,-6,1},
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19391[] = {
   {-6,-7,1},
   {-6,7,1},
   {6,-6,2},
   {6,7,2}};

static struct patval fuseki19392[] = {
   {6,7,1},
   {6,-7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19393[] = {
   {-7,-6,1},
   {7,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19394[] = {
   {-7,-6,1},
   {7,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19395[] = {
   {6,7,1},
   {6,-7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19396[] = {
   {-7,-6,1},
   {7,-6,1},
   {6,6,2},
   {-7,6,2}};

static struct patval fuseki19397[] = {
   {6,7,1},
   {6,-7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19398[] = {
   {6,7,1},
   {6,-7,1},
   {-6,7,2},
   {-6,-6,2}};

static struct patval fuseki19399[] = {
   {-6,6,1},
   {7,5,1},
   {6,-6,2}};

static struct patval fuseki19400[] = {
   {-6,6,1},
   {7,5,1},
   {6,-6,2}};

static struct patval fuseki19401[] = {
   {-6,6,1},
   {7,5,1},
   {6,-6,2}};

static struct patval fuseki19402[] = {
   {7,6,1},
   {-6,6,1},
   {1,7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19403[] = {
   {-7,-6,1},
   {6,-6,1},
   {-1,-7,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19404[] = {
   {7,6,1},
   {-6,6,1},
   {1,7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19405[] = {
   {-6,6,1},
   {6,6,1},
   {7,-5,2}};

static struct patval fuseki19406[] = {
   {6,6,1},
   {-6,6,1},
   {-7,-5,2}};

static struct patval fuseki19407[] = {
   {6,6,1},
   {6,-6,1},
   {-5,-7,2}};

static struct patval fuseki19408[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,7,2}};

static struct patval fuseki19409[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,7,2}};

static struct patval fuseki19410[] = {
   {-6,-6,1},
   {7,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki19411[] = {
   {-7,-6,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki19412[] = {
   {-6,-6,1},
   {6,7,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki19413[] = {
   {-6,-6,1},
   {7,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki19414[] = {
   {-6,-6,1},
   {6,7,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki19415[] = {
   {7,-6,1},
   {6,7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19416[] = {
   {7,-6,1},
   {6,7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19417[] = {
   {-7,-6,1},
   {6,-7,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19418[] = {
   {-7,-6,1},
   {-6,7,1},
   {6,-7,2},
   {6,6,2}};

static struct patval fuseki19419[] = {
   {-5,-6,1},
   {-6,-3,1},
   {-6,6,1},
   {6,6,1},
   {-2,-6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19420[] = {
   {-5,-6,1},
   {-6,-3,1},
   {-6,6,1},
   {6,6,1},
   {-2,-6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19421[] = {
   {7,5,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19422[] = {
   {-7,6,1},
   {-6,-6,1},
   {-5,7,1},
   {6,-7,2},
   {6,6,2}};

static struct patval fuseki19423[] = {
   {6,-6,1},
   {-7,7,2}};

static struct patval fuseki19424[] = {
   {6,-6,1},
   {-7,7,2}};

static struct patval fuseki19425[] = {
   {6,6,1},
   {-7,-7,2}};

static struct patval fuseki19426[] = {
   {6,-6,1},
   {-7,7,2}};

static struct patval fuseki19427[] = {
   {6,-6,1},
   {-7,7,2}};

static struct patval fuseki19428[] = {
   {-6,-6,1},
   {7,7,2}};

static struct patval fuseki19429[] = {
   {6,-6,1},
   {-7,7,2}};

static struct patval fuseki19430[] = {
   {-7,-5,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19431[] = {
   {-7,-5,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19432[] = {
   {6,-6,1},
   {5,7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19433[] = {
   {6,-6,1},
   {5,7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19434[] = {
   {-7,-5,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19435[] = {
   {-7,-5,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19436[] = {
   {-7,-5,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19437[] = {
   {7,-4,1},
   {-6,6,1},
   {7,6,1},
   {6,0,1},
   {6,-6,2},
   {-6,-6,2},
   {4,-7,2}};

static struct patval fuseki19438[] = {
   {-6,-7,1},
   {-6,6,1},
   {0,-6,1},
   {4,-7,1},
   {6,-6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19439[] = {
   {-6,-7,1},
   {-6,6,1},
   {0,-6,1},
   {4,-7,1},
   {6,-6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19440[] = {
   {7,-4,1},
   {-6,6,1},
   {7,6,1},
   {6,0,1},
   {6,-6,2},
   {-6,-6,2},
   {4,-7,2}};

static struct patval fuseki19441[] = {
   {7,-4,1},
   {-6,6,1},
   {7,6,1},
   {6,0,1},
   {6,-6,2},
   {-6,-6,2},
   {4,-7,2}};

static struct patval fuseki19442[] = {
   {6,-7,1},
   {-6,6,1},
   {-6,-6,2}};

static struct patval fuseki19443[] = {
   {6,-7,1},
   {-6,6,1},
   {-6,-6,2}};

static struct patval fuseki19444[] = {
   {-6,6,1},
   {7,-6,1},
   {6,6,2}};

static struct patval fuseki19445[] = {
   {-6,6,1},
   {7,-6,1},
   {6,6,2}};

static struct patval fuseki19446[] = {
   {-6,6,1},
   {7,-6,1},
   {6,6,2}};

static struct patval fuseki19447[] = {
   {-6,-7,1},
   {6,6,1},
   {6,-6,2}};

static struct patval fuseki19448[] = {
   {-6,7,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki19449[] = {
   {7,6,1},
   {-6,6,1},
   {1,6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19450[] = {
   {7,6,1},
   {-6,6,1},
   {1,6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19451[] = {
   {7,6,1},
   {-6,6,1},
   {1,6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19452[] = {
   {-7,6,1},
   {6,6,1},
   {-1,6,1},
   {-6,-6,2},
   {7,-6,2}};

static struct patval fuseki19453[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,7,2},
   {7,6,2}};

static struct patval fuseki19454[] = {
   {6,7,1},
   {6,-6,1},
   {-6,-7,2},
   {-7,6,2}};

static struct patval fuseki19455[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,7,2},
   {7,6,2}};

static struct patval fuseki19456[] = {
   {7,6,1},
   {-6,6,1},
   {6,-7,2},
   {-7,-6,2}};

static struct patval fuseki19457[] = {
   {7,-4,1},
   {-6,6,1},
   {7,-7,1},
   {6,6,1},
   {6,-6,2},
   {-6,-6,2},
   {7,-2,2}};

static struct patval fuseki19458[] = {
   {7,-4,1},
   {-6,6,1},
   {7,-7,1},
   {6,6,1},
   {6,-6,2},
   {-6,-6,2},
   {7,-2,2}};

static struct patval fuseki19459[] = {
   {-6,-6,1},
   {-6,7,1},
   {0,6,1},
   {4,7,1},
   {6,-6,2},
   {6,4,2},
   {6,6,2}};

static struct patval fuseki19460[] = {
   {7,-4,1},
   {-6,6,1},
   {7,6,1},
   {6,0,1},
   {6,-6,2},
   {-6,-6,2},
   {4,-6,2}};

static struct patval fuseki19461[] = {
   {7,-4,1},
   {-6,6,1},
   {7,6,1},
   {6,0,1},
   {6,-6,2},
   {-6,-6,2},
   {4,-6,2}};

static struct patval fuseki19462[] = {
   {-7,-6,1},
   {-7,4,1},
   {-6,0,1},
   {6,-6,1},
   {-4,6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19463[] = {
   {-6,-7,1},
   {-6,6,1},
   {0,-6,1},
   {4,-7,1},
   {6,-6,2},
   {6,-4,2},
   {6,6,2}};

static struct patval fuseki19464[] = {
   {7,-4,1},
   {-6,6,1},
   {7,6,1},
   {6,0,1},
   {6,-6,2},
   {-6,-6,2},
   {4,-6,2}};

static struct patval fuseki19465[] = {
   {-6,-6,1},
   {6,6,1},
   {4,-7,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki19466[] = {
   {7,4,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2},
   {-6,-6,2}};

static struct patval fuseki19467[] = {
   {-6,-6,1},
   {7,-4,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki19468[] = {
   {7,4,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2},
   {-6,-6,2}};

static struct patval fuseki19469[] = {
   {6,-6,1},
   {-6,6,1},
   {-4,-7,1},
   {-6,-6,2},
   {6,6,2}};

static struct patval fuseki19470[] = {
   {7,4,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2},
   {-6,-6,2}};

static struct patval fuseki19471[] = {
   {-6,-6,1},
   {7,-2,1},
   {6,-6,1},
   {7,-4,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19472[] = {
   {-6,-6,1},
   {7,-2,1},
   {6,-6,1},
   {7,-4,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19473[] = {
   {6,-6,1},
   {6,6,1},
   {2,-7,1},
   {4,-7,2},
   {-6,-7,2},
   {-6,6,2}};

static struct patval fuseki19474[] = {
   {-6,-7,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19475[] = {
   {-7,-4,1},
   {7,6,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19476[] = {
   {-7,-6,1},
   {7,4,1},
   {6,-6,1},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19477[] = {
   {-7,-4,1},
   {7,6,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19478[] = {
   {-7,-4,1},
   {7,6,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19479[] = {
   {-7,-4,1},
   {7,6,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19480[] = {
   {-6,-7,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19481[] = {
   {-7,4,1},
   {-6,-6,1},
   {6,-6,1},
   {1,7,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19482[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,-7,1},
   {6,-6,2},
   {6,7,2},
   {7,1,2}};

static struct patval fuseki19483[] = {
   {6,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-6,2},
   {-1,-7,2}};

static struct patval fuseki19484[] = {
   {-7,4,1},
   {-6,-6,1},
   {6,-6,1},
   {1,7,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19485[] = {
   {7,6,1},
   {-6,7,1},
   {-7,-6,2}};

static struct patval fuseki19486[] = {
   {7,6,1},
   {-6,7,1},
   {-7,-6,2}};

static struct patval fuseki19487[] = {
   {7,6,1},
   {-6,7,1},
   {-7,-6,2}};

static struct patval fuseki19488[] = {
   {-7,6,1},
   {-6,-7,1},
   {6,7,2}};

static struct patval fuseki19489[] = {
   {7,-6,1},
   {6,7,1},
   {-6,-7,2}};

static struct patval fuseki19490[] = {
   {-7,6,1},
   {6,7,1},
   {7,-6,2}};

static struct patval fuseki19491[] = {
   {7,1,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19492[] = {
   {7,1,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19493[] = {
   {-7,1,1},
   {6,6,1},
   {-6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19494[] = {
   {-7,-6,1},
   {-6,6,1},
   {-1,-7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19495[] = {
   {-7,-6,1},
   {-6,6,1},
   {-1,-7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19496[] = {
   {0,0,1},
   {-6,6,2}};

static struct patval fuseki19497[] = {
   {0,0,1},
   {6,6,2}};

static struct patval fuseki19498[] = {
   {0,0,1},
   {-6,6,2}};

static struct patval fuseki19499[] = {
   {-7,-4,1},
   {7,6,1},
   {-6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19500[] = {
   {-7,-4,1},
   {7,6,1},
   {-6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19501[] = {
   {-7,-6,1},
   {-6,7,1},
   {4,-7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19502[] = {
   {-7,-6,1},
   {-6,7,1},
   {4,-7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19503[] = {
   {-7,-4,1},
   {7,6,1},
   {-6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19504[] = {
   {-7,-4,1},
   {7,6,1},
   {-6,7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19505[] = {
   {6,-6,1},
   {-6,-6,1},
   {5,6,1},
   {-6,7,2},
   {-7,5,2},
   {7,6,2}};

static struct patval fuseki19506[] = {
   {6,-6,1},
   {-6,-6,1},
   {-5,6,1},
   {-7,6,2},
   {6,7,2},
   {7,5,2}};

static struct patval fuseki19507[] = {
   {6,-6,1},
   {-6,-6,1},
   {5,6,1},
   {-6,7,2},
   {-7,5,2},
   {7,6,2}};

static struct patval fuseki19508[] = {
   {6,-6,1},
   {-6,-6,1},
   {5,6,1},
   {-6,7,2},
   {-7,5,2},
   {7,6,2}};

static struct patval fuseki19509[] = {
   {6,-5,1},
   {-6,6,2}};

static struct patval fuseki19510[] = {
   {6,-5,1},
   {-6,6,2}};

static struct patval fuseki19511[] = {
   {5,-6,1},
   {-6,6,2}};

static struct patval fuseki19512[] = {
   {5,-6,1},
   {-6,6,2}};

static struct patval fuseki19513[] = {
   {-6,-6,1},
   {6,-6,1},
   {-4,7,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19514[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,-4,1},
   {6,6,2},
   {6,-6,2}};

static struct patval fuseki19515[] = {
   {-7,4,1},
   {6,6,1},
   {6,-6,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19516[] = {
   {-6,-6,1},
   {6,-6,1},
   {-4,7,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19517[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,5,2}};

static struct patval fuseki19518[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {7,5,2}};

static struct patval fuseki19519[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,7,2},
   {6,-6,2}};

static struct patval fuseki19520[] = {
   {6,7,1},
   {6,-7,1},
   {-6,-6,2}};

static struct patval fuseki19521[] = {
   {-7,-6,1},
   {7,-6,1},
   {-6,6,2}};

static struct patval fuseki19522[] = {
   {-7,6,1},
   {7,6,1},
   {-6,-6,2}};

static struct patval fuseki19523[] = {
   {-6,-7,1},
   {-6,7,1},
   {6,6,2}};

static struct patval fuseki19524[] = {
   {-7,-6,1},
   {6,-6,1},
   {4,-7,1},
   {-6,6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19525[] = {
   {-4,7,1},
   {7,6,1},
   {-6,6,1},
   {-7,4,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19526[] = {
   {-4,-7,1},
   {-6,-6,1},
   {7,-6,1},
   {-7,-4,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19527[] = {
   {-4,-7,1},
   {-6,-6,1},
   {7,-6,1},
   {-7,-4,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19528[] = {
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19529[] = {
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19530[] = {
   {-5,-6,1},
   {-6,6,1},
   {-7,-6,2},
   {6,-6,2}};

static struct patval fuseki19531[] = {
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19532[] = {
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19533[] = {
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19534[] = {
   {6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19535[] = {
   {7,-4,1},
   {-6,6,1},
   {8,-6,1},
   {6,6,1},
   {6,-6,2},
   {-6,-6,2},
   {4,-7,2}};

static struct patval fuseki19536[] = {
   {-8,-6,1},
   {-7,-4,1},
   {6,6,1},
   {-6,6,1},
   {-4,-7,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19537[] = {
   {6,6,1},
   {-6,6,1},
   {6,-5,1},
   {6,-7,2},
   {-7,-6,2}};

static struct patval fuseki19538[] = {
   {6,6,1},
   {-6,6,1},
   {6,-5,1},
   {6,-7,2},
   {-7,-6,2}};

static struct patval fuseki19539[] = {
   {6,6,1},
   {-6,-5,1},
   {-6,6,1},
   {-6,-7,2},
   {7,-6,2}};

static struct patval fuseki19540[] = {
   {6,6,1},
   {6,-6,1},
   {-5,-6,1},
   {-6,7,2},
   {-7,-6,2}};

static struct patval fuseki19541[] = {
   {-6,-6,1},
   {7,-2,1},
   {6,-6,1},
   {7,-6,1},
   {7,-7,2},
   {6,6,2},
   {7,-4,2},
   {-6,6,2}};

static struct patval fuseki19542[] = {
   {7,-4,1},
   {-6,6,1},
   {6,-7,1},
   {7,-7,1},
   {6,6,1},
   {6,-6,2},
   {7,-6,2},
   {-6,-6,2},
   {7,-2,2}};

static struct patval fuseki19543[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-5,1},
   {6,-7,2},
   {6,7,2}};

static struct patval fuseki19544[] = {
   {6,6,1},
   {-6,6,1},
   {-5,-6,1},
   {-7,-6,2},
   {7,-6,2}};

static struct patval fuseki19545[] = {
   {6,-6,1},
   {-6,-6,1},
   {-5,6,1},
   {-7,6,2},
   {7,6,2}};

static struct patval fuseki19546[] = {
   {6,6,1},
   {-6,6,1},
   {-5,-6,1},
   {-7,-6,2},
   {7,-6,2}};

static struct patval fuseki19547[] = {
   {-7,-6,1},
   {6,-6,1},
   {0,7,1},
   {-6,6,2},
   {6,7,2},
   {7,5,2}};

static struct patval fuseki19548[] = {
   {-7,6,1},
   {6,6,1},
   {0,-7,1},
   {6,-7,2},
   {-6,-6,2},
   {7,-5,2}};

static struct patval fuseki19549[] = {
   {0,7,1},
   {-6,-6,1},
   {7,-6,1},
   {-7,5,2},
   {6,6,2},
   {-6,7,2}};

static struct patval fuseki19550[] = {
   {-7,-6,1},
   {6,-6,1},
   {0,7,1},
   {-6,6,2},
   {6,7,2},
   {7,5,2}};

static struct patval fuseki19551[] = {
   {-6,-7,1},
   {-6,6,1},
   {7,0,1},
   {6,-6,2},
   {5,7,2},
   {7,6,2}};

static struct patval fuseki19552[] = {
   {0,7,1},
   {-6,-6,1},
   {7,-6,1},
   {-7,5,2},
   {6,6,2},
   {-6,7,2}};

static struct patval fuseki19553[] = {
   {-6,6,1},
   {6,6,1},
   {7,-7,2}};

static struct patval fuseki19554[] = {
   {-6,6,1},
   {6,6,1},
   {7,-7,2}};

static struct patval fuseki19555[] = {
   {6,-6,1},
   {-6,-6,1},
   {-7,7,2}};

static struct patval fuseki19556[] = {
   {6,5,1},
   {6,-6,1},
   {-6,6,2},
   {6,7,2}};

static struct patval fuseki19557[] = {
   {6,5,1},
   {6,-6,1},
   {-6,6,2},
   {6,7,2}};

static struct patval fuseki19558[] = {
   {6,5,1},
   {6,-6,1},
   {-6,6,2},
   {6,7,2}};

static struct patval fuseki19559[] = {
   {6,-6,1},
   {-5,-6,1},
   {-6,6,2},
   {-7,-6,2}};

static struct patval fuseki19560[] = {
   {-6,-6,1},
   {-6,5,1},
   {-6,7,2},
   {6,6,2}};

static struct patval fuseki19561[] = {
   {6,-6,1},
   {-5,7,2}};

static struct patval fuseki19562[] = {
   {6,-6,1},
   {-5,7,2}};

static struct patval fuseki19563[] = {
   {-6,6,1},
   {5,-7,2}};

static struct patval fuseki19564[] = {
   {6,-6,1},
   {-5,7,2}};

static struct patval fuseki19565[] = {
   {6,-6,1},
   {-7,5,2}};

static struct patval fuseki19566[] = {
   {6,-6,1},
   {6,6,1},
   {1,-6,1},
   {4,-7,2},
   {-6,-7,2},
   {-6,6,2}};

static struct patval fuseki19567[] = {
   {6,-6,1},
   {6,6,1},
   {1,-6,1},
   {4,-7,2},
   {-6,-7,2},
   {-6,6,2}};

static struct patval fuseki19568[] = {
   {-6,-6,1},
   {6,-1,1},
   {6,-6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19569[] = {
   {6,-7,1},
   {5,7,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19570[] = {
   {-7,-5,1},
   {7,-6,1},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19571[] = {
   {-7,-6,1},
   {7,-5,1},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19572[] = {
   {-7,-6,1},
   {7,-5,1},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19573[] = {
   {-7,5,1},
   {7,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19574[] = {
   {-7,5,1},
   {7,6,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19575[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,0,1},
   {-6,6,1},
   {-4,-7,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19576[] = {
   {6,-6,1},
   {6,6,1},
   {0,6,1},
   {-4,7,1},
   {-6,6,2},
   {-7,4,2},
   {-6,-6,2}};

static struct patval fuseki19577[] = {
   {6,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,0,1},
   {6,-6,2},
   {-6,-6,2},
   {4,-7,2}};

static struct patval fuseki19578[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,6,1},
   {4,7,1},
   {6,-6,2},
   {6,6,2},
   {7,4,2}};

static struct patval fuseki19579[] = {
   {6,-6,1},
   {-6,6,1},
   {-7,-6,2},
   {6,6,2}};

static struct patval fuseki19580[] = {
   {6,-6,1},
   {-6,6,1},
   {-6,-6,2},
   {7,6,2}};

static struct patval fuseki19581[] = {
   {6,-6,1},
   {-6,6,1},
   {-6,-7,2},
   {6,6,2}};

static struct patval fuseki19582[] = {
   {6,-6,1},
   {-6,6,1},
   {-6,-6,2},
   {7,6,2}};

static struct patval fuseki19583[] = {
   {6,6,1},
   {-6,6,1},
   {0,6,1},
   {-7,-6,2},
   {7,-6,2}};

static struct patval fuseki19584[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {6,-7,2},
   {6,7,2}};

static struct patval fuseki19585[] = {
   {-7,6,1},
   {7,-6,1},
   {6,6,2}};

static struct patval fuseki19586[] = {
   {6,-7,1},
   {-6,7,1},
   {-6,-6,2}};

static struct patval fuseki19587[] = {
   {-7,6,1},
   {7,-6,1},
   {6,6,2}};

static struct patval fuseki19588[] = {
   {-7,-6,1},
   {-2,-6,1},
   {6,-6,1},
   {-5,-5,1},
   {-5,-6,2},
   {-6,-3,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19589[] = {
   {6,7,1},
   {6,-6,1},
   {-6,-6,2},
   {-7,6,2}};

static struct patval fuseki19590[] = {
   {6,6,1},
   {6,-7,1},
   {-6,6,2},
   {-7,-6,2}};

static struct patval fuseki19591[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,7,2},
   {6,6,2}};

static struct patval fuseki19592[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,7,2},
   {6,6,2}};

static struct patval fuseki19593[] = {
   {-7,-6,1},
   {6,-6,1},
   {-6,7,2},
   {6,6,2}};

static struct patval fuseki19594[] = {
   {-6,-6,1},
   {6,3,1},
   {6,-6,1},
   {1,6,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19595[] = {
   {-6,-6,1},
   {6,3,1},
   {6,-6,1},
   {1,6,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19596[] = {
   {-6,-6,1},
   {6,3,1},
   {6,-6,1},
   {1,6,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19597[] = {
   {-6,6,1},
   {6,6,1},
   {6,-5,2}};

static struct patval fuseki19598[] = {
   {-6,6,1},
   {6,6,1},
   {6,-5,2}};

static struct patval fuseki19599[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,6,2}};

static struct patval fuseki19600[] = {
   {-6,6,1},
   {6,6,1},
   {6,-5,2}};

static struct patval fuseki19601[] = {
   {6,6,1},
   {-6,6,1},
   {-6,-5,2}};

static struct patval fuseki19602[] = {
   {-7,4,1},
   {-6,-6,1},
   {6,-6,1},
   {1,6,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19603[] = {
   {-7,4,1},
   {-6,-6,1},
   {6,-6,1},
   {1,6,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19604[] = {
   {-7,4,1},
   {-6,-6,1},
   {6,-6,1},
   {1,6,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19605[] = {
   {6,-6,1},
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-7,2},
   {-6,-1,2}};

static struct patval fuseki19606[] = {
   {6,-6,1},
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-7,2},
   {-6,-1,2}};

static struct patval fuseki19607[] = {
   {-4,-5,1},
   {-6,-3,1},
   {-6,6,1},
   {-5,-6,1},
   {6,6,1},
   {-7,-6,2},
   {-2,-6,2},
   {6,-6,2},
   {-5,-5,2}};

static struct patval fuseki19608[] = {
   {6,0,1},
   {6,6,1},
   {6,-6,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,0,2}};

static struct patval fuseki19609[] = {
   {6,0,1},
   {6,6,1},
   {6,-6,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,0,2}};

static struct patval fuseki19610[] = {
   {-6,-7,1},
   {-6,6,1},
   {3,-6,1},
   {4,-7,1},
   {4,-6,2},
   {6,-6,2},
   {6,0,2},
   {6,6,2}};

static struct patval fuseki19611[] = {
   {-6,-6,1},
   {7,-6,1},
   {6,-4,1},
   {5,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19612[] = {
   {-7,-6,1},
   {-6,-4,1},
   {6,-6,1},
   {-5,-6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19613[] = {
   {-7,-6,1},
   {-6,-4,1},
   {6,-6,1},
   {-5,-6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19614[] = {
   {6,-6,1},
   {6,7,1},
   {4,6,1},
   {-6,-6,2},
   {6,5,2},
   {-6,6,2}};

static struct patval fuseki19615[] = {
   {-4,-6,1},
   {-6,-6,1},
   {7,-6,1},
   {-7,-4,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19616[] = {
   {-7,-6,1},
   {6,-6,1},
   {4,-6,1},
   {-6,6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19617[] = {
   {-4,-6,1},
   {-6,-6,1},
   {7,-6,1},
   {-7,-4,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19618[] = {
   {-6,-6,1},
   {7,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19619[] = {
   {6,6,1},
   {-7,6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19620[] = {
   {-7,-6,1},
   {6,-6,1},
   {-7,6,2},
   {6,6,2}};

static struct patval fuseki19621[] = {
   {6,6,1},
   {6,-7,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19622[] = {
   {6,6,1},
   {-7,6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19623[] = {
   {-6,-6,1},
   {7,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19624[] = {
   {-7,-7,1},
   {6,-6,2}};

static struct patval fuseki19625[] = {
   {7,7,1},
   {-6,6,2}};

static struct patval fuseki19626[] = {
   {-7,-7,1},
   {-6,6,2}};

static struct patval fuseki19627[] = {
   {7,-5,1},
   {-6,6,2}};

static struct patval fuseki19628[] = {
   {5,-7,1},
   {-6,6,2}};

static struct patval fuseki19629[] = {
   {-5,-7,1},
   {6,6,2}};

static struct patval fuseki19630[] = {
   {5,-7,1},
   {-6,6,2}};

static struct patval fuseki19631[] = {
   {-5,7,1},
   {6,-6,2}};

static struct patval fuseki19632[] = {
   {7,-5,1},
   {-6,6,2}};

static struct patval fuseki19633[] = {
   {6,0,1},
   {6,6,1},
   {4,6,1},
   {6,-6,1},
   {4,7,2},
   {-6,-6,2},
   {-6,7,2}};

static struct patval fuseki19634[] = {
   {-7,-7,1},
   {6,6,1},
   {6,-7,1},
   {-4,-7,1},
   {-6,6,2},
   {-2,-7,2},
   {-6,0,2},
   {-6,-6,2}};

static struct patval fuseki19635[] = {
   {-7,-6,1},
   {-7,7,1},
   {-7,4,1},
   {6,-6,1},
   {-7,2,2},
   {0,6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19636[] = {
   {6,6,1},
   {-6,5,2}};

static struct patval fuseki19637[] = {
   {6,6,1},
   {-6,5,2}};

static struct patval fuseki19638[] = {
   {6,6,1},
   {-6,5,2}};

static struct patval fuseki19639[] = {
   {-6,-6,1},
   {-5,6,2}};

static struct patval fuseki19640[] = {
   {-6,-6,1},
   {-5,6,2}};

static struct patval fuseki19641[] = {
   {6,6,1},
   {-6,6,1},
   {0,6,1},
   {6,4,1},
   {6,-6,2},
   {-6,-6,2},
   {7,4,2}};

static struct patval fuseki19642[] = {
   {-6,-5,1},
   {6,-6,1},
   {-6,6,2}};

static struct patval fuseki19643[] = {
   {-6,6,1},
   {6,5,1},
   {6,-6,2}};

static struct patval fuseki19644[] = {
   {6,6,1},
   {-6,5,1},
   {-6,-6,2}};

static struct patval fuseki19645[] = {
   {6,-6,1},
   {5,6,1},
   {-6,6,2}};

static struct patval fuseki19646[] = {
   {-6,6,1},
   {6,5,1},
   {6,-6,2}};

static struct patval fuseki19647[] = {
   {6,6,1},
   {-6,6,1},
   {4,-7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19648[] = {
   {-6,-6,1},
   {6,-6,1},
   {-4,7,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19649[] = {
   {-6,-6,1},
   {6,-6,1},
   {-4,7,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19650[] = {
   {-6,-6,1},
   {6,-6,1},
   {-4,7,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19651[] = {
   {6,-7,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19652[] = {
   {-6,6,1},
   {7,-6,1},
   {6,7,2}};

static struct patval fuseki19653[] = {
   {6,-7,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19654[] = {
   {-6,6,1},
   {7,-6,1},
   {6,7,2}};

static struct patval fuseki19655[] = {
   {6,-7,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19656[] = {
   {-7,-4,1},
   {6,6,1},
   {-5,-4,1},
   {-6,6,1},
   {-6,-6,2},
   {6,-6,2},
   {-7,-2,2}};

static struct patval fuseki19657[] = {
   {7,-4,1},
   {-6,6,1},
   {5,-4,1},
   {6,6,1},
   {6,-6,2},
   {-6,-6,2},
   {7,-2,2}};

static struct patval fuseki19658[] = {
   {-4,7,1},
   {-6,6,2}};

static struct patval fuseki19659[] = {
   {-4,7,1},
   {-6,6,2}};

static struct patval fuseki19660[] = {
   {-4,7,1},
   {-6,6,2}};

static struct patval fuseki19661[] = {
   {-4,7,1},
   {-6,6,2}};

static struct patval fuseki19662[] = {
   {-7,4,1},
   {-6,6,2}};

static struct patval fuseki19663[] = {
   {7,4,1},
   {6,6,2}};

static struct patval fuseki19664[] = {
   {6,-6,1},
   {-6,6,1},
   {-7,-5,2}};

static struct patval fuseki19665[] = {
   {-6,6,1},
   {6,-6,1},
   {5,7,2}};

static struct patval fuseki19666[] = {
   {6,-6,1},
   {-6,6,1},
   {-7,-5,2}};

static struct patval fuseki19667[] = {
   {6,-6,1},
   {-6,6,1},
   {-7,-5,2}};

static struct patval fuseki19668[] = {
   {-6,-6,1},
   {6,6,1},
   {-5,7,2}};

static struct patval fuseki19669[] = {
   {6,-6,1},
   {-6,6,1},
   {-7,-5,2}};

static struct patval fuseki19670[] = {
   {-6,6,1},
   {6,-6,1},
   {7,5,2}};

static struct patval fuseki19671[] = {
   {6,6,1},
   {6,-7,1},
   {-7,-6,2}};

static struct patval fuseki19672[] = {
   {-6,-7,1},
   {-6,6,1},
   {7,-6,2}};

static struct patval fuseki19673[] = {
   {-6,-7,1},
   {-6,6,1},
   {7,-6,2}};

static struct patval fuseki19674[] = {
   {-7,-6,1},
   {6,-6,1},
   {-2,-6,1},
   {-5,-6,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19675[] = {
   {6,2,1},
   {6,7,1},
   {6,-6,1},
   {-6,-7,2},
   {6,5,2},
   {-6,6,2}};

static struct patval fuseki19676[] = {
   {6,2,1},
   {6,7,1},
   {6,-6,1},
   {-6,-7,2},
   {6,5,2},
   {-6,6,2}};

static struct patval fuseki19677[] = {
   {-6,-6,1},
   {6,3,1},
   {6,-6,1},
   {1,7,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19678[] = {
   {-6,-6,1},
   {6,3,1},
   {6,-6,1},
   {1,7,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19679[] = {
   {-6,-6,1},
   {6,3,1},
   {6,-6,1},
   {1,7,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19680[] = {
   {6,-6,1},
   {-6,7,1},
   {-6,-6,2}};

static struct patval fuseki19681[] = {
   {6,-6,1},
   {-6,7,1},
   {-6,-6,2}};

static struct patval fuseki19682[] = {
   {6,-6,1},
   {-6,7,1},
   {-6,-6,2}};

static struct patval fuseki19683[] = {
   {-6,6,1},
   {6,-7,1},
   {6,6,2}};

static struct patval fuseki19684[] = {
   {-7,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki19685[] = {
   {6,6,1},
   {-6,6,1},
   {0,6,1},
   {4,6,1},
   {6,-6,2},
   {-6,-6,2},
   {7,4,2}};

static struct patval fuseki19686[] = {
   {6,6,1},
   {-6,6,1},
   {0,6,1},
   {4,6,1},
   {6,-6,2},
   {-6,-6,2},
   {7,4,2}};

static struct patval fuseki19687[] = {
   {6,6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19688[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19689[] = {
   {-6,-6,1},
   {6,-6,1},
   {0,0,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19690[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19691[] = {
   {6,6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19692[] = {
   {6,6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19693[] = {
   {6,7,1},
   {-6,6,1},
   {7,5,1},
   {2,7,1},
   {6,-6,2},
   {-6,-6,2},
   {0,7,2}};

static struct patval fuseki19694[] = {
   {6,7,1},
   {-6,6,1},
   {7,5,1},
   {2,7,1},
   {6,-6,2},
   {-6,-6,2},
   {0,7,2}};

static struct patval fuseki19695[] = {
   {-6,6,1},
   {-7,-6,1},
   {-6,-6,1},
   {-6,0,1},
   {-2,-7,1},
   {-4,-7,2},
   {-7,-7,2},
   {6,-7,2},
   {6,6,2}};

static struct patval fuseki19696[] = {
   {7,6,1},
   {-6,6,1},
   {-7,-5,2}};

static struct patval fuseki19697[] = {
   {7,6,1},
   {-6,6,1},
   {-7,-5,2}};

static struct patval fuseki19698[] = {
   {-6,-7,1},
   {-6,6,1},
   {5,7,2}};

static struct patval fuseki19699[] = {
   {-7,-6,1},
   {6,-6,1},
   {7,5,2}};

static struct patval fuseki19700[] = {
   {7,6,1},
   {-6,6,1},
   {-7,-5,2}};

static struct patval fuseki19701[] = {
   {-6,-7,1},
   {-6,6,1},
   {5,7,2}};

static struct patval fuseki19702[] = {
   {7,6,1},
   {-6,6,1},
   {-7,-5,2}};

static struct patval fuseki19703[] = {
   {6,0,1},
   {6,6,1},
   {3,5,1},
   {6,-6,1},
   {4,6,1},
   {4,7,2},
   {3,6,2},
   {-6,-6,2},
   {-6,7,2}};

static struct patval fuseki19704[] = {
   {6,0,1},
   {6,6,1},
   {3,5,1},
   {6,-6,1},
   {4,6,1},
   {4,7,2},
   {3,6,2},
   {-6,-6,2},
   {-6,7,2}};

static struct patval fuseki19705[] = {
   {6,-6,1},
   {0,-6,1},
   {-6,-6,1},
   {-6,-4,1},
   {-5,-3,1},
   {-6,-3,2},
   {-7,6,2},
   {-7,-4,2},
   {6,6,2}};

static struct patval fuseki19706[] = {
   {-7,-6,1},
   {7,-7,1},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19707[] = {
   {-7,-6,1},
   {7,-7,1},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19708[] = {
   {-7,-7,1},
   {7,-6,1},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19709[] = {
   {-6,-6,1},
   {6,0,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19710[] = {
   {6,-6,1},
   {6,6,1},
   {0,6,1},
   {4,7,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki19711[] = {
   {-6,-6,1},
   {6,0,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19712[] = {
   {6,-6,1},
   {6,6,1},
   {0,6,1},
   {4,7,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki19713[] = {
   {6,-6,1},
   {6,6,1},
   {0,6,1},
   {4,7,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki19714[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {-4,6,1},
   {-3,5,1},
   {-4,7,2},
   {-3,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19715[] = {
   {6,6,1},
   {-6,6,1},
   {0,6,1},
   {5,3,1},
   {6,4,1},
   {6,3,2},
   {6,-6,2},
   {-6,-6,2},
   {7,4,2}};

static struct patval fuseki19716[] = {
   {6,0,1},
   {6,6,1},
   {6,-6,1},
   {3,-5,1},
   {4,-6,1},
   {4,-7,2},
   {3,-6,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki19717[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {-4,6,1},
   {-3,5,1},
   {-4,7,2},
   {-3,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19718[] = {
   {6,6,1},
   {-5,7,1},
   {-6,-7,2},
   {-7,6,2}};

static struct patval fuseki19719[] = {
   {-7,5,1},
   {-6,-6,1},
   {-6,7,2},
   {7,6,2}};

static struct patval fuseki19720[] = {
   {-4,-7,1},
   {6,6,1},
   {-6,6,1},
   {-4,-6,1},
   {-5,-6,1},
   {-7,-6,2},
   {-5,-7,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki19721[] = {
   {-6,-6,1},
   {-5,7,2}};

static struct patval fuseki19722[] = {
   {-6,-6,1},
   {-5,7,2}};

static struct patval fuseki19723[] = {
   {6,6,1},
   {-7,5,2}};

static struct patval fuseki19724[] = {
   {6,6,1},
   {-7,5,2}};

static struct patval fuseki19725[] = {
   {7,6,1},
   {-6,6,1},
   {6,-5,1},
   {6,-7,2},
   {-7,-6,2}};

static struct patval fuseki19726[] = {
   {-6,-7,1},
   {-6,6,1},
   {5,-6,1},
   {6,7,2},
   {7,-6,2}};

static struct patval fuseki19727[] = {
   {7,6,1},
   {-6,6,1},
   {6,-5,1},
   {6,-7,2},
   {-7,-6,2}};

static struct patval fuseki19728[] = {
   {-6,-7,1},
   {-6,6,1},
   {5,-6,1},
   {6,7,2},
   {7,-6,2}};

static struct patval fuseki19729[] = {
   {7,6,1},
   {-6,6,1},
   {6,-5,1},
   {6,-7,2},
   {-7,-6,2}};

static struct patval fuseki19730[] = {
   {-7,-6,1},
   {6,-6,1},
   {-3,-7,1},
   {-5,-6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19731[] = {
   {6,7,1},
   {7,3,1},
   {6,-6,1},
   {6,5,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki19732[] = {
   {-6,-6,1},
   {8,6,1},
   {7,4,1},
   {6,-6,1},
   {6,6,2},
   {4,6,2},
   {-6,6,2}};

static struct patval fuseki19733[] = {
   {-8,6,1},
   {-7,4,1},
   {-6,-6,1},
   {6,-6,1},
   {-4,6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19734[] = {
   {7,-4,1},
   {-6,6,1},
   {8,-6,1},
   {6,6,1},
   {6,-6,2},
   {-6,-6,2},
   {4,-6,2}};

static struct patval fuseki19735[] = {
   {-8,-6,1},
   {-7,-4,1},
   {6,6,1},
   {-6,6,1},
   {-4,-6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19736[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,8,1},
   {6,4,2},
   {6,6,2},
   {6,-6,2}};

static struct patval fuseki19737[] = {
   {-6,-6,1},
   {6,-7,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19738[] = {
   {7,-6,1},
   {6,6,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19739[] = {
   {-6,-6,1},
   {6,-7,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19740[] = {
   {7,-4,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19741[] = {
   {7,-4,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19742[] = {
   {7,-4,1},
   {-6,6,1},
   {6,7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19743[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {5,7,2},
   {6,-6,2}};

static struct patval fuseki19744[] = {
   {6,6,1},
   {-6,6,1},
   {0,6,1},
   {6,-6,2},
   {-7,-5,2}};

static struct patval fuseki19745[] = {
   {6,6,1},
   {-6,6,1},
   {0,6,1},
   {-6,-6,2},
   {7,-5,2}};

static struct patval fuseki19746[] = {
   {6,6,1},
   {6,0,1},
   {6,-6,1},
   {-5,7,2},
   {-6,-6,2}};

static struct patval fuseki19747[] = {
   {-6,-6,1},
   {6,-6,1},
   {-6,6,2},
   {6,5,2}};

static struct patval fuseki19748[] = {
   {6,6,1},
   {-6,6,1},
   {6,-6,2},
   {-6,-5,2}};

static struct patval fuseki19749[] = {
   {-7,-6,1},
   {-7,4,1},
   {7,-6,1},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19750[] = {
   {-7,-6,1},
   {-7,4,1},
   {7,-6,1},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19751[] = {
   {-7,-4,1},
   {-7,6,1},
   {7,6,1},
   {0,-6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19752[] = {
   {6,-7,1},
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,0,2}};

static struct patval fuseki19753[] = {
   {-7,-6,1},
   {-7,4,1},
   {6,-6,1},
   {1,7,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19754[] = {
   {-6,-7,1},
   {-6,6,1},
   {4,-7,1},
   {6,-6,2},
   {6,7,2},
   {7,1,2}};

static struct patval fuseki19755[] = {
   {6,6,1},
   {-6,-7,1},
   {-6,6,1},
   {6,-6,2},
   {-7,-5,2}};

static struct patval fuseki19756[] = {
   {6,6,1},
   {-6,-7,1},
   {-6,6,1},
   {6,-6,2},
   {-7,-5,2}};

static struct patval fuseki19757[] = {
   {6,6,1},
   {-6,-7,1},
   {-6,6,1},
   {6,-6,2},
   {-7,-5,2}};

static struct patval fuseki19758[] = {
   {6,6,1},
   {-6,6,1},
   {6,-7,1},
   {-6,-6,2},
   {7,-5,2}};

static struct patval fuseki19759[] = {
   {6,6,1},
   {-6,-7,1},
   {-6,6,1},
   {6,-6,2},
   {-7,-5,2}};

static struct patval fuseki19760[] = {
   {6,6,1},
   {6,-6,1},
   {-5,6,1},
   {-6,-6,2},
   {-7,6,2}};

static struct patval fuseki19761[] = {
   {6,6,1},
   {6,-6,1},
   {-5,-6,1},
   {-6,6,2},
   {-7,-6,2}};

static struct patval fuseki19762[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,-6,1},
   {6,6,2},
   {7,-6,2}};

static struct patval fuseki19763[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,-6,1},
   {6,6,2},
   {7,-6,2}};

static struct patval fuseki19764[] = {
   {6,6,1},
   {6,-6,1},
   {-5,6,1},
   {-6,-6,2},
   {-7,6,2}};

static struct patval fuseki19765[] = {
   {0,6,1},
   {0,0,1},
   {-6,6,2}};

static struct patval fuseki19766[] = {
   {0,6,1},
   {0,0,1},
   {-6,6,2}};

static struct patval fuseki19767[] = {
   {0,6,1},
   {0,0,1},
   {-6,6,2}};

static struct patval fuseki19768[] = {
   {0,0,1},
   {0,6,1},
   {6,6,2}};

static struct patval fuseki19769[] = {
   {-6,-6,1},
   {6,0,1},
   {6,-6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19770[] = {
   {-6,6,1},
   {6,6,1},
   {-6,0,1},
   {-7,-6,2},
   {6,-6,2},
   {-7,4,2}};

static struct patval fuseki19771[] = {
   {-6,-6,1},
   {6,0,1},
   {6,-6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19772[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,6,1},
   {-4,7,2},
   {6,-6,2},
   {6,7,2}};

static struct patval fuseki19773[] = {
   {-6,-6,1},
   {7,1,1},
   {6,-6,1},
   {5,7,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19774[] = {
   {-6,-6,1},
   {7,1,1},
   {6,-6,1},
   {5,7,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19775[] = {
   {-6,-6,1},
   {7,1,1},
   {6,-6,1},
   {5,7,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19776[] = {
   {-6,-6,1},
   {6,5,1},
   {6,-6,2},
   {6,7,2}};

static struct patval fuseki19777[] = {
   {6,6,1},
   {-6,-5,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19778[] = {
   {-6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19779[] = {
   {-6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19780[] = {
   {6,6,1},
   {-6,-5,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19781[] = {
   {-6,-6,1},
   {5,6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19782[] = {
   {-6,6,1},
   {7,-4,1},
   {6,-6,2}};

static struct patval fuseki19783[] = {
   {-6,6,1},
   {7,-4,1},
   {6,-6,2}};

static struct patval fuseki19784[] = {
   {-6,6,1},
   {7,-4,1},
   {6,-6,2}};

static struct patval fuseki19785[] = {
   {-6,6,1},
   {7,-4,1},
   {6,-6,2}};

static struct patval fuseki19786[] = {
   {-6,6,1},
   {7,-4,1},
   {6,-6,2}};

static struct patval fuseki19787[] = {
   {-6,6,1},
   {7,-4,1},
   {6,-6,2}};

static struct patval fuseki19788[] = {
   {-6,6,1},
   {7,-4,1},
   {6,-6,2}};

static struct patval fuseki19789[] = {
   {7,6,1},
   {-7,5,1},
   {-6,7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19790[] = {
   {7,6,1},
   {-7,5,1},
   {-6,7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19791[] = {
   {7,6,1},
   {-7,5,1},
   {-6,7,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19792[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,0,1},
   {-6,6,1},
   {-4,-6,2},
   {-6,-6,2},
   {7,-6,2}};

static struct patval fuseki19793[] = {
   {6,-6,1},
   {6,6,1},
   {0,6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-7,2},
   {-6,4,2}};

static struct patval fuseki19794[] = {
   {-6,6,1},
   {0,0,1},
   {6,-6,2}};

static struct patval fuseki19795[] = {
   {6,6,1},
   {0,0,1},
   {-6,-6,2}};

static struct patval fuseki19796[] = {
   {7,-1,1},
   {-6,6,1},
   {7,-4,1},
   {8,-6,1},
   {6,6,1},
   {7,-7,2},
   {4,-7,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki19797[] = {
   {6,-6,1},
   {6,6,1},
   {-1,7,1},
   {-4,7,1},
   {-6,8,1},
   {-6,6,2},
   {-6,-6,2},
   {-7,4,2},
   {-7,7,2}};

static struct patval fuseki19798[] = {
   {7,-1,1},
   {-6,6,1},
   {7,-4,1},
   {8,-6,1},
   {6,6,1},
   {7,-7,2},
   {4,-7,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki19799[] = {
   {-6,-6,1},
   {7,-7,1},
   {4,-7,1},
   {6,-6,1},
   {6,6,2},
   {-6,6,2},
   {7,-4,2},
   {8,-6,2}};

static struct patval fuseki19800[] = {
   {6,6,1},
   {-6,-6,1},
   {-7,6,2},
   {7,-6,2}};

static struct patval fuseki19801[] = {
   {6,6,1},
   {-6,-6,1},
   {-7,6,2},
   {7,-6,2}};

static struct patval fuseki19802[] = {
   {-6,-6,1},
   {6,6,1},
   {6,-7,2},
   {-6,7,2}};

static struct patval fuseki19803[] = {
   {-7,6,1},
   {7,5,1},
   {6,7,1},
   {-5,7,1},
   {6,-6,2},
   {-5,6,2},
   {-6,-6,2}};

static struct patval fuseki19804[] = {
   {-7,5,1},
   {7,6,1},
   {-6,7,1},
   {5,7,1},
   {5,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19805[] = {
   {-6,-6,1},
   {6,-5,1},
   {6,-7,2}};

static struct patval fuseki19806[] = {
   {-5,-6,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19807[] = {
   {-6,6,1},
   {6,5,1},
   {6,7,2}};

static struct patval fuseki19808[] = {
   {5,-6,1},
   {6,6,1},
   {7,-6,2}};

static struct patval fuseki19809[] = {
   {-7,-6,1},
   {7,6,2}};

static struct patval fuseki19810[] = {
   {-7,6,1},
   {7,-6,2}};

static struct patval fuseki19811[] = {
   {7,-6,1},
   {-7,6,2}};

static struct patval fuseki19812[] = {
   {-7,6,1},
   {7,-6,2}};

static struct patval fuseki19813[] = {
   {-6,-6,1},
   {8,-7,1},
   {7,-6,1},
   {6,-4,1},
   {6,6,2},
   {7,-7,2},
   {5,-6,2},
   {-6,6,2}};

static struct patval fuseki19814[] = {
   {6,6,1},
   {-6,6,1},
   {5,-6,1},
   {6,-7,1},
   {7,-7,1},
   {-6,-6,2},
   {6,-4,2},
   {7,-6,2},
   {8,-7,2}};

static struct patval fuseki19815[] = {
   {-6,6,1},
   {-7,-7,1},
   {-5,-6,1},
   {-6,-7,1},
   {6,6,1},
   {-8,-7,2},
   {-7,-6,2},
   {6,-6,2},
   {-6,-4,2}};

static struct patval fuseki19816[] = {
   {-7,6,1},
   {-6,-7,1},
   {7,-6,1},
   {6,6,2},
   {-5,7,2}};

static struct patval fuseki19817[] = {
   {7,6,1},
   {6,-7,1},
   {-6,7,1},
   {-6,-6,2},
   {-7,5,2}};

static struct patval fuseki19818[] = {
   {7,6,1},
   {6,-7,1},
   {-6,7,1},
   {-6,-6,2},
   {-7,5,2}};

static struct patval fuseki19819[] = {
   {7,6,1},
   {6,-7,1},
   {-6,7,1},
   {-6,-6,2},
   {-7,5,2}};

static struct patval fuseki19820[] = {
   {7,-7,1},
   {-6,6,1},
   {5,-6,1},
   {6,6,1},
   {6,-4,2},
   {-6,-6,2},
   {7,-6,2}};

static struct patval fuseki19821[] = {
   {6,-6,1},
   {6,6,1},
   {0,6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,4,2}};

static struct patval fuseki19822[] = {
   {6,-6,1},
   {6,6,1},
   {0,6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,4,2}};

static struct patval fuseki19823[] = {
   {6,-6,1},
   {6,6,1},
   {0,-6,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,-4,2}};

static struct patval fuseki19824[] = {
   {6,-6,1},
   {6,6,1},
   {0,6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {-6,4,2}};

static struct patval fuseki19825[] = {
   {5,7,1},
   {-5,7,1},
   {-6,-6,2}};

static struct patval fuseki19826[] = {
   {-5,7,1},
   {5,7,1},
   {6,-6,2}};

static struct patval fuseki19827[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,-1,1},
   {-6,6,2},
   {-7,-4,2},
   {6,6,2}};

static struct patval fuseki19828[] = {
   {-6,-6,1},
   {6,-1,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19829[] = {
   {-6,-6,1},
   {6,-1,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19830[] = {
   {6,6,1},
   {-6,6,1},
   {0,0,2},
   {-6,-6,2}};

static struct patval fuseki19831[] = {
   {-6,6,1},
   {6,6,1},
   {6,-6,2},
   {0,0,2}};

static struct patval fuseki19832[] = {
   {6,6,1},
   {6,-6,1},
   {0,0,2},
   {-6,6,2}};

static struct patval fuseki19833[] = {
   {-6,-5,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19834[] = {
   {6,5,1},
   {-6,6,1},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19835[] = {
   {-6,-5,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19836[] = {
   {-7,-6,1},
   {7,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki19837[] = {
   {-7,-6,1},
   {7,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki19838[] = {
   {7,6,1},
   {-6,6,1},
   {4,-7,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19839[] = {
   {-6,-7,1},
   {-6,6,1},
   {7,-4,1},
   {6,6,2},
   {6,-6,2}};

static struct patval fuseki19840[] = {
   {-6,6,1},
   {-5,-6,1},
   {6,6,2}};

static struct patval fuseki19841[] = {
   {-6,-6,1},
   {-5,6,1},
   {6,-6,2}};

static struct patval fuseki19842[] = {
   {6,6,1},
   {5,-6,1},
   {-6,6,2}};

static struct patval fuseki19843[] = {
   {7,2,1},
   {-6,6,1},
   {0,6,1},
   {6,6,1},
   {6,-6,2},
   {-7,-6,2},
   {7,4,2}};

static struct patval fuseki19844[] = {
   {7,2,1},
   {-6,6,1},
   {0,6,1},
   {6,6,1},
   {6,-6,2},
   {-7,-6,2},
   {7,4,2}};

static struct patval fuseki19845[] = {
   {7,2,1},
   {-6,6,1},
   {0,6,1},
   {6,6,1},
   {6,-6,2},
   {-7,-6,2},
   {7,4,2}};

static struct patval fuseki19846[] = {
   {6,-6,1},
   {-6,6,1},
   {7,-4,1},
   {-6,-6,2},
   {6,6,2},
   {4,-7,2}};

static struct patval fuseki19847[] = {
   {-6,-6,1},
   {6,6,1},
   {4,7,1},
   {6,-6,2},
   {-6,6,2},
   {7,4,2}};

static struct patval fuseki19848[] = {
   {6,-6,1},
   {-6,6,1},
   {4,-7,1},
   {-6,-6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19849[] = {
   {6,6,1},
   {6,-6,1},
   {-6,7,2},
   {-6,-7,2}};

static struct patval fuseki19850[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-7,2},
   {6,7,2}};

static struct patval fuseki19851[] = {
   {-5,-4,1},
   {-6,6,1},
   {-5,-6,1},
   {6,6,1},
   {-2,-6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19852[] = {
   {-5,-4,1},
   {-6,6,1},
   {-5,-6,1},
   {6,6,1},
   {-2,-6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19853[] = {
   {-7,-6,1},
   {6,-6,1},
   {-2,-6,1},
   {-5,-7,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19854[] = {
   {-6,6,1},
   {-6,-7,1},
   {-6,-2,1},
   {-7,-5,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19855[] = {
   {-7,-6,1},
   {6,-6,1},
   {-2,-6,1},
   {-5,-7,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19856[] = {
   {-7,-6,1},
   {6,-6,1},
   {4,-7,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19857[] = {
   {-7,-6,1},
   {6,-6,1},
   {4,-7,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19858[] = {
   {-7,-6,1},
   {6,-6,1},
   {4,-7,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19859[] = {
   {-6,-6,1},
   {6,-6,1},
   {4,-7,1},
   {4,7,1},
   {-6,6,2},
   {6,0,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19860[] = {
   {-6,-6,1},
   {6,-6,1},
   {4,-7,1},
   {4,7,1},
   {-6,6,2},
   {6,0,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19861[] = {
   {-7,-6,1},
   {5,-7,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19862[] = {
   {-7,-6,1},
   {5,-7,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19863[] = {
   {-7,-6,1},
   {5,-7,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19864[] = {
   {-7,-6,1},
   {5,-7,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19865[] = {
   {6,6,1},
   {-6,6,1},
   {0,6,1},
   {6,-7,2},
   {-7,-6,2}};

static struct patval fuseki19866[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {6,7,2},
   {7,-6,2}};

static struct patval fuseki19867[] = {
   {-6,-6,1},
   {6,-6,1},
   {0,-6,1},
   {-6,7,2},
   {7,6,2}};

static struct patval fuseki19868[] = {
   {6,6,1},
   {6,0,1},
   {6,-6,1},
   {-6,7,2},
   {-7,-6,2}};

static struct patval fuseki19869[] = {
   {-6,6,1},
   {6,6,1},
   {0,0,2}};

static struct patval fuseki19870[] = {
   {-6,-6,1},
   {6,-6,1},
   {0,0,2}};

static struct patval fuseki19871[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,2}};

static struct patval fuseki19872[] = {
   {-6,6,1},
   {6,6,1},
   {0,0,2}};

static struct patval fuseki19873[] = {
   {-6,6,1},
   {6,6,1},
   {0,0,2}};

static struct patval fuseki19874[] = {
   {6,6,1},
   {6,-6,1},
   {0,0,2}};

static struct patval fuseki19875[] = {
   {-7,-6,1},
   {-7,4,1},
   {6,-6,1},
   {1,6,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19876[] = {
   {-7,-6,1},
   {-7,4,1},
   {6,-6,1},
   {1,6,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19877[] = {
   {-7,-6,1},
   {-7,4,1},
   {6,-6,1},
   {1,6,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19878[] = {
   {-6,-6,1},
   {7,4,1},
   {6,0,1},
   {6,-6,1},
   {4,6,2},
   {0,6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19879[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,6,1},
   {4,7,1},
   {6,-6,2},
   {6,0,2},
   {6,4,2},
   {6,6,2}};

static struct patval fuseki19880[] = {
   {6,-6,1},
   {6,6,1},
   {0,-6,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,0,2},
   {-6,-6,2},
   {-6,-4,2}};

static struct patval fuseki19881[] = {
   {7,-4,1},
   {-6,6,1},
   {7,6,1},
   {7,-7,1},
   {-6,-6,2},
   {7,-2,2},
   {6,-6,2}};

static struct patval fuseki19882[] = {
   {-6,-7,1},
   {-6,6,1},
   {7,-7,1},
   {4,-7,1},
   {6,-6,2},
   {6,6,2},
   {2,-7,2}};

static struct patval fuseki19883[] = {
   {-6,-6,1},
   {6,-6,1},
   {-4,7,1},
   {0,7,1},
   {2,7,2},
   {-6,6,2},
   {6,7,2},
   {7,5,2}};

static struct patval fuseki19884[] = {
   {-6,-6,1},
   {6,-6,1},
   {-4,7,1},
   {0,7,1},
   {2,7,2},
   {-6,6,2},
   {6,7,2},
   {7,5,2}};

static struct patval fuseki19885[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,0,1},
   {7,-4,1},
   {6,-6,2},
   {5,7,2},
   {7,2,2},
   {7,6,2}};

static struct patval fuseki19886[] = {
   {1,7,1},
   {7,6,1},
   {-6,6,1},
   {-4,6,1},
   {-7,4,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19887[] = {
   {-7,-1,1},
   {-6,-7,1},
   {-6,4,1},
   {-6,6,1},
   {-4,7,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19888[] = {
   {1,7,1},
   {7,6,1},
   {-6,6,1},
   {-4,6,1},
   {-7,4,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19889[] = {
   {7,5,1},
   {6,-6,1},
   {6,7,2},
   {-6,6,2}};

static struct patval fuseki19890[] = {
   {7,5,1},
   {6,-6,1},
   {6,7,2},
   {-6,6,2}};

static struct patval fuseki19891[] = {
   {7,5,1},
   {6,-6,1},
   {6,7,2},
   {-6,6,2}};

static struct patval fuseki19892[] = {
   {7,5,1},
   {6,-6,1},
   {6,7,2},
   {-6,6,2}};

static struct patval fuseki19893[] = {
   {5,6,1},
   {-6,6,1},
   {1,6,1},
   {7,6,1},
   {6,-6,2},
   {6,3,2},
   {-6,-6,2}};

static struct patval fuseki19894[] = {
   {-6,-6,1},
   {6,-6,1},
   {-5,6,2},
   {6,5,2}};

static struct patval fuseki19895[] = {
   {6,6,1},
   {6,-6,1},
   {-5,-6,2},
   {-6,5,2}};

static struct patval fuseki19896[] = {
   {0,6,1},
   {6,6,1},
   {-6,6,1},
   {-4,6,1},
   {-7,-6,2},
   {6,-6,2},
   {-7,4,2}};

static struct patval fuseki19897[] = {
   {0,6,1},
   {6,6,1},
   {-6,6,1},
   {-4,6,1},
   {-7,-6,2},
   {6,-6,2},
   {-7,4,2}};

static struct patval fuseki19898[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {0,-6,1},
   {6,-6,2},
   {6,0,2},
   {6,6,2}};

static struct patval fuseki19899[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {0,6,1},
   {6,-6,2},
   {6,0,2},
   {6,6,2}};

static struct patval fuseki19900[] = {
   {-6,-6,1},
   {6,0,1},
   {6,3,1},
   {6,-6,1},
   {5,6,2},
   {-6,6,2},
   {1,6,2},
   {7,6,2}};

static struct patval fuseki19901[] = {
   {-6,-6,1},
   {6,0,1},
   {6,3,1},
   {6,-6,1},
   {5,6,2},
   {-6,6,2},
   {1,6,2},
   {7,6,2}};

static struct patval fuseki19902[] = {
   {-5,-6,1},
   {-6,-3,1},
   {-6,6,1},
   {7,6,1},
   {-2,-6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19903[] = {
   {-6,-6,1},
   {7,4,1},
   {6,-6,1},
   {5,4,1},
   {0,6,2},
   {6,6,2},
   {7,2,2},
   {-6,6,2}};

static struct patval fuseki19904[] = {
   {-6,-6,1},
   {6,-6,1},
   {0,7,1},
   {-6,6,2},
   {6,7,2},
   {7,1,2}};

static struct patval fuseki19905[] = {
   {6,-6,1},
   {-7,0,1},
   {6,6,1},
   {-1,-7,2},
   {-7,-6,2},
   {-6,6,2}};

static struct patval fuseki19906[] = {
   {-6,-6,1},
   {6,-6,1},
   {0,7,1},
   {-6,6,2},
   {6,7,2},
   {7,1,2}};

static struct patval fuseki19907[] = {
   {-4,7,1},
   {-6,-6,1},
   {-6,6,1},
   {-7,4,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19908[] = {
   {-7,4,1},
   {6,6,1},
   {-6,6,1},
   {-4,7,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19909[] = {
   {-7,-6,1},
   {6,6,1},
   {7,-6,2}};

static struct patval fuseki19910[] = {
   {-7,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki19911[] = {
   {7,-6,1},
   {-6,6,1},
   {-7,-6,2}};

static struct patval fuseki19912[] = {
   {-6,6,1},
   {6,-7,1},
   {6,7,2}};

static struct patval fuseki19913[] = {
   {-6,-6,1},
   {-6,-4,1},
   {-6,6,1},
   {-2,-7,1},
   {-4,-5,2},
   {-4,-7,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19914[] = {
   {6,-6,1},
   {-7,-2,1},
   {-6,-6,1},
   {-4,-6,1},
   {-5,-4,2},
   {-6,6,2},
   {-7,-4,2},
   {6,6,2}};

static struct patval fuseki19915[] = {
   {6,4,1},
   {6,6,1},
   {2,7,1},
   {6,-6,1},
   {4,7,2},
   {4,5,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki19916[] = {
   {-7,-6,1},
   {7,-4,1},
   {6,-6,1},
   {4,-7,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19917[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-5,2}};

static struct patval fuseki19918[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-5,2}};

static struct patval fuseki19919[] = {
   {7,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-7,-5,2}};

static struct patval fuseki19920[] = {
   {-7,-6,1},
   {-2,-6,1},
   {6,-6,1},
   {-5,-5,1},
   {-5,-6,2},
   {-6,-3,2},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19921[] = {
   {1,7,1},
   {7,6,1},
   {-6,6,1},
   {-4,6,1},
   {-7,-6,2},
   {6,-6,2},
   {-7,4,2}};

static struct patval fuseki19922[] = {
   {-7,-6,1},
   {6,-6,1},
   {-1,-7,1},
   {4,-6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19923[] = {
   {-4,-5,1},
   {-6,-3,1},
   {-6,6,1},
   {-5,-6,1},
   {7,6,1},
   {-7,-6,2},
   {-2,-6,2},
   {6,-6,2},
   {-5,-5,2}};

static struct patval fuseki19924[] = {
   {5,6,1},
   {5,-6,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19925[] = {
   {5,6,1},
   {5,-6,1},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki19926[] = {
   {-6,-5,1},
   {6,-5,1},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19927[] = {
   {-7,-6,1},
   {-6,2,1},
   {-7,4,1},
   {6,-6,1},
   {-7,2,2},
   {0,6,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19928[] = {
   {6,-6,1},
   {-6,6,1},
   {5,6,1},
   {-6,-6,2},
   {7,6,2}};

static struct patval fuseki19929[] = {
   {6,5,1},
   {-6,6,1},
   {6,-6,1},
   {-6,-6,2},
   {6,7,2}};

static struct patval fuseki19930[] = {
   {6,-6,1},
   {-6,6,1},
   {-5,-6,1},
   {-7,-6,2},
   {6,6,2}};

static struct patval fuseki19931[] = {
   {6,5,1},
   {-6,6,1},
   {6,-6,1},
   {-6,-6,2},
   {6,7,2}};

static struct patval fuseki19932[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {5,-7,2},
   {6,6,2}};

static struct patval fuseki19933[] = {
   {7,-4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,2},
   {-7,-5,2}};

static struct patval fuseki19934[] = {
   {6,6,1},
   {6,-6,1},
   {-4,-7,1},
   {-5,7,2},
   {-6,-6,2}};

static struct patval fuseki19935[] = {
   {7,-4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,2},
   {-7,-5,2}};

static struct patval fuseki19936[] = {
   {6,6,1},
   {6,-6,1},
   {-4,-7,1},
   {-5,7,2},
   {-6,-6,2}};

static struct patval fuseki19937[] = {
   {6,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,0,1},
   {6,-6,2},
   {-7,-6,2},
   {4,-7,2}};

static struct patval fuseki19938[] = {
   {6,6,1},
   {-6,6,1},
   {7,-4,1},
   {6,0,1},
   {6,-6,2},
   {-7,-6,2},
   {4,-7,2}};

static struct patval fuseki19939[] = {
   {7,-7,1},
   {-6,6,1},
   {6,-7,1},
   {7,6,1},
   {7,-4,1},
   {7,-6,2},
   {-6,-6,2},
   {7,-2,2},
   {6,-6,2}};

static struct patval fuseki19940[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,7,1},
   {6,5,2},
   {6,-6,2}};

static struct patval fuseki19941[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,7,1},
   {6,5,2},
   {6,-6,2}};

static struct patval fuseki19942[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,7,1},
   {6,5,2},
   {6,-6,2}};

static struct patval fuseki19943[] = {
   {-7,-6,1},
   {6,-6,1},
   {4,-6,1},
   {-6,6,2},
   {7,-4,2},
   {7,6,2}};

static struct patval fuseki19944[] = {
   {6,-4,1},
   {6,7,1},
   {6,-6,1},
   {4,-7,2},
   {-6,-7,2},
   {-6,6,2}};

static struct patval fuseki19945[] = {
   {-6,7,1},
   {-5,-7,1},
   {6,-6,2}};

static struct patval fuseki19946[] = {
   {-7,6,1},
   {7,5,1},
   {6,-6,2}};

static struct patval fuseki19947[] = {
   {6,6,1},
   {-6,6,1},
   {4,-7,1},
   {6,-8,1},
   {6,-6,2},
   {-7,-6,2},
   {7,-4,2}};

static struct patval fuseki19948[] = {
   {-6,-1,1},
   {-6,-6,1},
   {7,-6,1},
   {-7,-4,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki19949[] = {
   {-6,-6,1},
   {-6,7,1},
   {-1,-6,1},
   {-4,-7,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19950[] = {
   {-7,-6,1},
   {6,-1,1},
   {6,-6,1},
   {-6,6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19951[] = {
   {7,5,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19952[] = {
   {7,5,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19953[] = {
   {7,5,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki19954[] = {
   {-6,6,1},
   {-5,-7,1},
   {4,-7,1},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19955[] = {
   {-6,-7,1},
   {6,-6,1},
   {-6,6,2},
   {7,6,2}};

static struct patval fuseki19956[] = {
   {7,6,1},
   {6,-6,1},
   {-6,6,2},
   {-6,-7,2}};

static struct patval fuseki19957[] = {
   {-7,6,1},
   {-6,-6,1},
   {6,-7,2},
   {6,6,2}};

static struct patval fuseki19958[] = {
   {6,-4,1},
   {-6,-5,1},
   {6,-6,1},
   {6,6,1},
   {4,-7,2},
   {-6,6,2},
   {-6,-7,2},
   {0,-6,2}};

static struct patval fuseki19959[] = {
   {6,4,1},
   {-6,5,1},
   {6,-6,1},
   {6,6,1},
   {4,7,2},
   {-6,7,2},
   {-6,-6,2},
   {0,6,2}};

static struct patval fuseki19960[] = {
   {5,6,1},
   {-6,6,1},
   {1,7,1},
   {7,6,1},
   {6,-6,2},
   {6,3,2},
   {-6,-6,2}};

static struct patval fuseki19961[] = {
   {-7,-6,1},
   {6,-2,1},
   {6,-7,1},
   {6,-5,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19962[] = {
   {-7,-6,1},
   {6,-2,1},
   {6,-7,1},
   {6,-5,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19963[] = {
   {-7,-6,1},
   {6,-2,1},
   {6,-7,1},
   {6,-5,2},
   {-6,6,2},
   {6,6,2}};

static struct patval fuseki19964[] = {
   {6,7,1},
   {6,-7,1},
   {-6,6,2},
   {-7,-6,2}};

static struct patval fuseki19965[] = {
   {6,7,1},
   {6,-7,1},
   {-6,6,2},
   {-7,-6,2}};

static struct patval fuseki19966[] = {
   {6,6,1},
   {0,0,1},
   {-6,6,2}};

static struct patval fuseki19967[] = {
   {0,0,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki19968[] = {
   {-6,-6,1},
   {0,0,1},
   {-6,6,2}};

static struct patval fuseki19969[] = {
   {-5,-6,1},
   {-7,-5,1},
   {-6,6,1},
   {6,6,1},
   {-2,-6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19970[] = {
   {-5,-6,1},
   {-7,-5,1},
   {-6,6,1},
   {6,6,1},
   {-2,-6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki19971[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,-7,1},
   {6,-5,1},
   {6,-7,2},
   {6,-2,2},
   {6,6,2}};

static struct patval fuseki19972[] = {
   {-6,6,1},
   {-7,2,1},
   {0,6,1},
   {-6,1,1},
   {6,6,1},
   {-7,-6,2},
   {-7,4,2},
   {6,-6,2},
   {-6,2,2}};

static struct patval fuseki19973[] = {
   {-6,5,1},
   {-6,7,2}};

static struct patval fuseki19974[] = {
   {7,2,1},
   {-6,6,1},
   {0,6,1},
   {4,6,1},
   {6,6,1},
   {6,-6,2},
   {5,4,2},
   {-6,-6,2},
   {7,4,2}};

static struct patval fuseki19975[] = {
   {6,-6,1},
   {-6,-6,1},
   {-4,7,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,0,2},
   {-7,-4,2},
   {6,6,2}};

static struct patval fuseki19976[] = {
   {-6,-6,1},
   {6,-6,1},
   {4,-7,1},
   {4,7,1},
   {-6,6,2},
   {6,0,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki19977[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {7,4,1},
   {0,6,2},
   {6,-6,2},
   {6,6,2},
   {-4,7,2}};

static struct patval fuseki19978[] = {
   {7,5,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,2},
   {-6,-6,2}};

static struct patval fuseki19979[] = {
   {7,5,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,2},
   {-6,-6,2}};

static struct patval fuseki19980[] = {
   {6,-6,1},
   {-6,6,1},
   {-5,-7,1},
   {-7,-6,2},
   {6,6,2}};

static struct patval fuseki19981[] = {
   {-7,-5,1},
   {6,-6,1},
   {-6,6,1},
   {-6,-7,2},
   {6,6,2}};

static struct patval fuseki19982[] = {
   {-6,-6,1},
   {7,-6,1},
   {6,-6,1},
   {7,-2,1},
   {-6,6,2},
   {7,-4,2},
   {7,-7,2},
   {7,6,2}};

static struct patval fuseki19983[] = {
   {7,-4,1},
   {-6,6,1},
   {5,-4,1},
   {7,6,1},
   {-6,-6,2},
   {7,-2,2},
   {6,-6,2}};

static struct patval fuseki19984[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {0,6,1},
   {-4,-7,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki19985[] = {
   {6,6,1},
   {-6,0,1},
   {-6,6,1},
   {0,6,1},
   {6,-6,2},
   {-6,-6,2},
   {7,4,2}};

static struct patval fuseki19986[] = {
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19987[] = {
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19988[] = {
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19989[] = {
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19990[] = {
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19991[] = {
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19992[] = {
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19993[] = {
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19994[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19995[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19996[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19997[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19998[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki19999[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki191000[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki191001[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki191002[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1}};

static struct patval fuseki191003[] = {
   {6,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191004[] = {
   {6,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191005[] = {
   {6,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191006[] = {
   {6,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191007[] = {
   {-6,-6,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191008[] = {
   {6,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191009[] = {
   {-6,-6,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191010[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191011[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191012[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191013[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191014[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191015[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191016[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191017[] = {
   {7,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191018[] = {
   {-7,-6,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191019[] = {
   {-7,-6,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191020[] = {
   {7,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191021[] = {
   {6,7,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191022[] = {
   {-7,-6,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191023[] = {
   {6,7,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191024[] = {
   {7,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191025[] = {
   {6,7,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191026[] = {
   {7,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191027[] = {
   {7,6,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191028[] = {
   {7,-4,1},
   {-6,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,-6,2}};

static struct patval fuseki191029[] = {
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191030[] = {
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191031[] = {
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191032[] = {
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191033[] = {
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191034[] = {
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191035[] = {
   {7,-4,1},
   {-6,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,-6,2}};

static struct patval fuseki191036[] = {
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191037[] = {
   {4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191038[] = {
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191039[] = {
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191040[] = {
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191041[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191042[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191043[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191044[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191045[] = {
   {6,6,1},
   {-6,6,1},
   {6,-6,1},
   {-6,-6,2}};

static struct patval fuseki191046[] = {
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191047[] = {
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191048[] = {
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191049[] = {
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191050[] = {
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191051[] = {
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191052[] = {
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191053[] = {
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191054[] = {
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191055[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191056[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191057[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191058[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191059[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191060[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191061[] = {
   {6,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191062[] = {
   {6,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191063[] = {
   {6,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191064[] = {
   {7,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191065[] = {
   {7,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191066[] = {
   {7,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191067[] = {
   {7,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191068[] = {
   {-7,-4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,0,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191069[] = {
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {0,0,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191070[] = {
   {-7,-4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,0,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191071[] = {
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {0,0,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191072[] = {
   {7,4,1},
   {-6,-6,2},
   {0,0,2},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191073[] = {
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {0,0,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191074[] = {
   {-7,4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,0,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191075[] = {
   {-7,4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,0,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191076[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191077[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,2}};

static struct patval fuseki191078[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191079[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191080[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191081[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191082[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,2}};

static struct patval fuseki191083[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191084[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191085[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191086[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191087[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191088[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191089[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191090[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191091[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191092[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191093[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191094[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191095[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191096[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191097[] = {
   {7,-4,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki191098[] = {
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191099[] = {
   {7,-4,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki191100[] = {
   {7,-4,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki191101[] = {
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191102[] = {
   {7,-4,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki191103[] = {
   {7,-4,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2},
   {-6,-6,2}};

static struct patval fuseki191104[] = {
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191105[] = {
   {-6,-6,1},
   {4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191106[] = {
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191107[] = {
   {-6,-7,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191108[] = {
   {6,7,1},
   {-6,6,1},
   {6,-6,1},
   {-6,-6,2}};

static struct patval fuseki191109[] = {
   {-6,-7,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191110[] = {
   {-7,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191111[] = {
   {-7,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191112[] = {
   {-6,-7,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191113[] = {
   {-6,-7,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191114[] = {
   {6,5,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191115[] = {
   {6,5,1},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191116[] = {
   {5,6,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191117[] = {
   {-6,-5,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191118[] = {
   {5,6,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191119[] = {
   {5,6,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191120[] = {
   {5,6,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191121[] = {
   {5,6,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191122[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {0,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191123[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {0,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191124[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {0,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191125[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {0,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191126[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {0,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191127[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {0,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191128[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,-6,1},
   {6,6,1},
   {-7,-4,2}};

static struct patval fuseki191129[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191130[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,-6,1},
   {6,6,1},
   {-7,-4,2}};

static struct patval fuseki191131[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,-6,1},
   {6,-6,1},
   {6,6,1},
   {7,-4,2}};

static struct patval fuseki191132[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191133[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,-6,1},
   {6,-6,1},
   {6,6,1},
   {7,-4,2}};

static struct patval fuseki191134[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,-6,1},
   {6,-6,1},
   {6,6,1},
   {7,-4,2}};

static struct patval fuseki191135[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,6,1},
   {6,6,1},
   {-7,4,2}};

static struct patval fuseki191136[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191137[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,-6,1},
   {6,-6,1},
   {6,6,1},
   {7,-4,2}};

static struct patval fuseki191138[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191139[] = {
   {5,6,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki191140[] = {
   {5,6,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki191141[] = {
   {5,6,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki191142[] = {
   {5,6,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki191143[] = {
   {5,6,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki191144[] = {
   {5,6,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki191145[] = {
   {6,5,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191146[] = {
   {5,6,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki191147[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,5,1},
   {6,7,2}};

static struct patval fuseki191148[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,5,1},
   {6,7,2}};

static struct patval fuseki191149[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,5,1},
   {6,7,2}};

static struct patval fuseki191150[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,5,1},
   {6,7,2}};

static struct patval fuseki191151[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191152[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,5,1},
   {6,7,2}};

static struct patval fuseki191153[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,5,1},
   {6,7,2}};

static struct patval fuseki191154[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191155[] = {
   {-7,-4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,-6,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191156[] = {
   {7,-4,1},
   {-6,-6,2},
   {0,-6,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191157[] = {
   {7,4,1},
   {-6,-6,2},
   {0,-6,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191158[] = {
   {7,-4,1},
   {-6,-6,2},
   {0,-6,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191159[] = {
   {-7,-4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,-6,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191160[] = {
   {7,4,1},
   {-6,-6,2},
   {0,-6,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191161[] = {
   {7,-4,1},
   {-6,-6,2},
   {0,-6,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191162[] = {
   {7,4,1},
   {-6,-6,2},
   {0,-6,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191163[] = {
   {7,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191164[] = {
   {-7,-6,1},
   {4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191165[] = {
   {7,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191166[] = {
   {-7,-6,1},
   {4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191167[] = {
   {7,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191168[] = {
   {7,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191169[] = {
   {-7,4,1},
   {-6,-7,1},
   {-6,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191170[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191171[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191172[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191173[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191174[] = {
   {-7,-4,1},
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191175[] = {
   {6,6,1},
   {-4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191176[] = {
   {6,6,1},
   {-4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191177[] = {
   {6,6,1},
   {-6,-5,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191178[] = {
   {6,6,1},
   {-5,-6,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191179[] = {
   {6,6,1},
   {-6,-5,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191180[] = {
   {6,6,1},
   {-5,-6,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191181[] = {
   {5,7,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191182[] = {
   {-5,-7,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191183[] = {
   {5,7,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191184[] = {
   {5,7,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191185[] = {
   {-5,-7,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191186[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,-4,1},
   {6,-6,1},
   {6,6,1},
   {4,-7,2}};

static struct patval fuseki191187[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,1},
   {7,4,2}};

static struct patval fuseki191188[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,1},
   {7,4,2}};

static struct patval fuseki191189[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191190[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,1},
   {7,4,2}};

static struct patval fuseki191191[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191192[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191193[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191194[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,4,1},
   {6,-6,1},
   {6,6,1},
   {4,7,2}};

static struct patval fuseki191195[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191196[] = {
   {7,5,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191197[] = {
   {5,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki191198[] = {
   {5,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2}};

static struct patval fuseki191199[] = {
   {7,5,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191200[] = {
   {7,5,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191201[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,-6,1},
   {0,0,1},
   {6,6,1},
   {-7,-4,2}};

static struct patval fuseki191202[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {4,6,1},
   {6,-6,1},
   {6,6,1},
   {7,4,2}};

static struct patval fuseki191203[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,6,1},
   {0,0,1},
   {6,6,1},
   {-7,4,2}};

static struct patval fuseki191204[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,6,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191205[] = {
   {-6,-6,1},
   {-6,-4,1},
   {-6,6,1},
   {6,6,1},
   {0,0,1},
   {6,-6,1},
   {-4,-7,2}};

static struct patval fuseki191206[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,6,1},
   {0,0,1},
   {6,6,1},
   {-7,4,2}};

static struct patval fuseki191207[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,6,1},
   {0,0,1},
   {6,6,1},
   {-7,4,2}};

static struct patval fuseki191208[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,6,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191209[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {4,6,1},
   {6,-6,1},
   {6,6,1},
   {7,4,2}};

static struct patval fuseki191210[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,6,1},
   {0,0,1},
   {6,6,1},
   {-7,4,2}};

static struct patval fuseki191211[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191212[] = {
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-5,-6,2}};

static struct patval fuseki191213[] = {
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-5,-6,2}};

static struct patval fuseki191214[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191215[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191216[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,5,2}};

static struct patval fuseki191217[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {-2,7,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191218[] = {
   {-6,-6,1},
   {-6,6,1},
   {2,7,1},
   {6,6,1},
   {6,-6,1},
   {4,7,2}};

static struct patval fuseki191219[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {-2,-7,1},
   {6,-6,1},
   {-4,-7,2}};

static struct patval fuseki191220[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,1},
   {7,2,1},
   {7,4,2}};

static struct patval fuseki191221[] = {
   {6,-6,1},
   {-6,6,1},
   {-5,-6,1},
   {-7,-6,2}};

static struct patval fuseki191222[] = {
   {6,-6,1},
   {-6,6,1},
   {-5,-6,1},
   {-7,-6,2}};

static struct patval fuseki191223[] = {
   {-6,6,1},
   {5,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191224[] = {
   {-6,6,1},
   {6,-6,1},
   {6,5,1},
   {6,7,2}};

static struct patval fuseki191225[] = {
   {-6,6,1},
   {6,-6,1},
   {6,5,1},
   {6,7,2}};

static struct patval fuseki191226[] = {
   {-6,6,1},
   {5,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191227[] = {
   {-6,6,1},
   {5,6,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191228[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,-6,1},
   {6,-6,1},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki191229[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,-6,1},
   {-4,7,2},
   {6,6,2}};

static struct patval fuseki191230[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,-6,1},
   {6,-6,1},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki191231[] = {
   {6,-4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-6,-6,2},
   {4,-7,2}};

static struct patval fuseki191232[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {0,0,1},
   {0,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191233[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {0,0,1},
   {0,6,1},
   {6,-6,1},
   {6,6,1}};

static struct patval fuseki191234[] = {
   {-6,-7,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,2}};

static struct patval fuseki191235[] = {
   {7,6,1},
   {-6,6,1},
   {6,-6,1},
   {-7,-6,2}};

static struct patval fuseki191236[] = {
   {-6,-7,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,2}};

static struct patval fuseki191237[] = {
   {7,6,1},
   {-6,6,1},
   {6,-6,1},
   {-7,-6,2}};

static struct patval fuseki191238[] = {
   {-7,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,2}};

static struct patval fuseki191239[] = {
   {6,7,1},
   {-6,6,1},
   {6,-6,1},
   {-7,-6,2}};

static struct patval fuseki191240[] = {
   {-7,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,2}};

static struct patval fuseki191241[] = {
   {6,7,1},
   {-6,6,1},
   {6,-6,1},
   {-7,-6,2}};

static struct patval fuseki191242[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {0,-6,1},
   {0,0,1},
   {0,6,1},
   {6,-6,1},
   {6,0,1},
   {6,6,1}};

static struct patval fuseki191243[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {0,-6,1},
   {0,0,1},
   {0,6,1},
   {6,-6,1},
   {6,0,1},
   {6,6,1}};

static struct patval fuseki191244[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191245[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191246[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191247[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,7,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191248[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,5,1},
   {6,7,2}};

static struct patval fuseki191249[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,5,1},
   {6,7,2}};

static struct patval fuseki191250[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,7,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191251[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,7,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191252[] = {
   {-6,-6,1},
   {-6,6,1},
   {5,7,1},
   {6,-6,1},
   {7,6,2}};

static struct patval fuseki191253[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {5,7,2}};

static struct patval fuseki191254[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {5,7,2}};

static struct patval fuseki191255[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {5,7,2}};

static struct patval fuseki191256[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {7,5,2}};

static struct patval fuseki191257[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {5,7,2}};

static struct patval fuseki191258[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {5,7,2}};

static struct patval fuseki191259[] = {
   {-7,4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191260[] = {
   {-7,-4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191261[] = {
   {7,-4,1},
   {-6,-6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191262[] = {
   {-7,-4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191263[] = {
   {7,-4,1},
   {-6,-6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191264[] = {
   {-7,4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191265[] = {
   {-7,-4,1},
   {-6,-6,2},
   {-6,6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191266[] = {
   {2,6,1},
   {7,6,1},
   {-6,-6,2},
   {5,6,2},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191267[] = {
   {2,6,1},
   {7,6,1},
   {-6,-6,2},
   {5,6,2},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191268[] = {
   {2,6,1},
   {7,6,1},
   {-6,-6,2},
   {5,6,2},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191269[] = {
   {6,2,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2},
   {6,5,2},
   {-6,6,2}};

static struct patval fuseki191270[] = {
   {6,2,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2},
   {6,5,2},
   {-6,6,2}};

static struct patval fuseki191271[] = {
   {6,2,1},
   {6,7,1},
   {6,-6,2},
   {-6,-6,2},
   {6,5,2},
   {-6,6,2}};

static struct patval fuseki191272[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,-6,1},
   {-4,7,2},
   {7,6,2}};

static struct patval fuseki191273[] = {
   {6,-4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-7,-6,2},
   {4,-7,2}};

static struct patval fuseki191274[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,-6,1},
   {-4,7,2},
   {7,6,2}};

static struct patval fuseki191275[] = {
   {6,-4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-7,-6,2},
   {4,-7,2}};

static struct patval fuseki191276[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,-6,1},
   {6,-6,1},
   {6,7,2},
   {7,-4,2}};

static struct patval fuseki191277[] = {
   {7,2,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2},
   {-6,-6,2},
   {7,4,2}};

static struct patval fuseki191278[] = {
   {7,2,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2},
   {-6,-6,2},
   {7,4,2}};

static struct patval fuseki191279[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191280[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191281[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,1},
   {6,5,2}};

static struct patval fuseki191282[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191283[] = {
   {-7,4,1},
   {-6,-6,2},
   {-6,0,2},
   {-6,6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,0,2},
   {6,6,2}};

static struct patval fuseki191284[] = {
   {-4,7,1},
   {-6,0,2},
   {-6,6,2},
   {-6,-6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,0,2},
   {6,6,2}};

static struct patval fuseki191285[] = {
   {7,4,1},
   {-6,0,2},
   {-6,-6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,0,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191286[] = {
   {-7,-4,1},
   {-6,-6,2},
   {-6,0,2},
   {-6,6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,0,2},
   {6,6,2}};

static struct patval fuseki191287[] = {
   {-4,7,1},
   {-6,0,2},
   {-6,6,2},
   {-6,-6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,0,2},
   {6,6,2}};

static struct patval fuseki191288[] = {
   {-4,7,1},
   {-6,0,2},
   {-6,6,2},
   {-6,-6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,0,2},
   {6,6,2}};

static struct patval fuseki191289[] = {
   {-4,7,1},
   {-6,0,2},
   {-6,6,2},
   {-6,-6,2},
   {0,-6,2},
   {0,0,2},
   {0,6,2},
   {6,-6,2},
   {6,0,2},
   {6,6,2}};

static struct patval fuseki191290[] = {
   {4,-7,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,-4,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191291[] = {
   {-7,-4,1},
   {-7,4,1},
   {-6,-6,2},
   {-6,6,2},
   {-4,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191292[] = {
   {7,-4,1},
   {7,4,1},
   {4,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191293[] = {
   {-7,-4,1},
   {-7,4,1},
   {-6,-6,2},
   {-6,6,2},
   {-4,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191294[] = {
   {7,-4,1},
   {7,4,1},
   {4,6,2},
   {6,-6,2},
   {6,6,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191295[] = {
   {4,7,1},
   {-4,7,1},
   {-6,6,2},
   {-6,4,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191296[] = {
   {7,-4,1},
   {7,4,1},
   {4,-6,2},
   {6,-6,2},
   {6,6,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191297[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {-4,7,2},
   {6,6,2}};

static struct patval fuseki191298[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,-7,1},
   {6,-6,1},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki191299[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {-4,7,2},
   {6,6,2}};

static struct patval fuseki191300[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,-7,1},
   {6,-6,1},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki191301[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191302[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191303[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191304[] = {
   {-7,-4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {0,0,1},
   {6,-6,1},
   {-4,-7,2}};

static struct patval fuseki191305[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191306[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191307[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {7,-4,1},
   {6,-6,1},
   {6,6,1},
   {4,-7,2}};

static struct patval fuseki191308[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {4,7,1},
   {6,-6,1},
   {6,6,1},
   {7,4,2}};

static struct patval fuseki191309[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,7,1},
   {0,0,1},
   {6,6,1},
   {-7,4,2}};

static struct patval fuseki191310[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,7,1},
   {0,0,1},
   {6,6,1},
   {-7,4,2}};

static struct patval fuseki191311[] = {
   {-7,-5,1},
   {-6,-7,1},
   {6,-6,1},
   {-6,6,1},
   {-6,-5,2},
   {6,6,2}};

static struct patval fuseki191312[] = {
   {-7,-5,1},
   {-6,-7,1},
   {6,-6,1},
   {-6,6,1},
   {-6,-5,2},
   {6,6,2}};

static struct patval fuseki191313[] = {
   {-4,7,1},
   {-4,5,1},
   {-6,6,2},
   {-6,-6,2},
   {-2,7,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191314[] = {
   {-5,4,1},
   {-7,4,1},
   {-6,-6,2},
   {-6,6,2},
   {-7,2,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191315[] = {
   {-6,-7,1},
   {-6,6,1},
   {6,-6,1},
   {6,5,2}};

static struct patval fuseki191316[] = {
   {-7,-6,1},
   {-6,6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191317[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,-6,1},
   {0,-6,1},
   {0,6,1},
   {6,6,1},
   {-7,-4,2}};

static struct patval fuseki191318[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {0,6,1},
   {4,6,1},
   {6,-6,1},
   {6,6,1},
   {7,4,2}};

static struct patval fuseki191319[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,6,1},
   {0,-6,1},
   {0,6,1},
   {6,6,1},
   {-7,4,2}};

static struct patval fuseki191320[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,6,1},
   {0,-6,1},
   {0,6,1},
   {6,6,1},
   {-7,4,2}};

static struct patval fuseki191321[] = {
   {6,-6,1},
   {-6,-6,1},
   {-6,6,1},
   {-4,6,1},
   {0,-6,1},
   {0,6,1},
   {6,6,1},
   {-7,4,2}};

static struct patval fuseki191322[] = {
   {-6,-5,1},
   {-7,-4,1},
   {6,6,1},
   {-7,-5,2},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191323[] = {
   {-7,-6,1},
   {-7,-5,1},
   {6,-6,1},
   {-6,-7,1},
   {-6,6,1},
   {-6,-5,2},
   {-7,-4,2},
   {6,6,2}};

static struct patval fuseki191324[] = {
   {-7,-6,1},
   {-6,-7,1},
   {-6,6,1},
   {-5,-7,1},
   {6,-6,1},
   {-4,-7,2},
   {-5,-6,2},
   {6,6,2}};

static struct patval fuseki191325[] = {
   {-7,-6,1},
   {-6,-7,1},
   {-6,6,1},
   {-5,-7,1},
   {6,-6,1},
   {-4,-7,2},
   {-5,-6,2},
   {6,6,2}};

static struct patval fuseki191326[] = {
   {7,5,1},
   {-6,6,1},
   {6,-6,1},
   {7,6,1},
   {6,7,1},
   {7,4,2},
   {-6,-6,2},
   {6,5,2}};

static struct patval fuseki191327[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,0,1},
   {-6,6,2},
   {-4,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191328[] = {
   {0,6,1},
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {-6,4,2}};

static struct patval fuseki191329[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,0,1},
   {-6,6,2},
   {-4,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191330[] = {
   {0,6,1},
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {-6,4,2}};

static struct patval fuseki191331[] = {
   {6,6,1},
   {7,-4,1},
   {6,0,1},
   {6,-6,2},
   {4,-6,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191332[] = {
   {6,7,1},
   {-5,-6,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191333[] = {
   {6,7,1},
   {-5,-6,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191334[] = {
   {6,7,1},
   {-5,-6,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191335[] = {
   {6,7,1},
   {-5,-6,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191336[] = {
   {-7,-6,1},
   {6,5,1},
   {6,-6,2},
   {-6,6,2},
   {6,7,2}};

static struct patval fuseki191337[] = {
   {6,6,1},
   {4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191338[] = {
   {-7,4,1},
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191339[] = {
   {6,6,1},
   {4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191340[] = {
   {6,6,1},
   {4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191341[] = {
   {-7,4,1},
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191342[] = {
   {6,6,1},
   {4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191343[] = {
   {-6,-6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191344[] = {
   {6,6,1},
   {4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191345[] = {
   {0,0,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191346[] = {
   {0,0,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191347[] = {
   {0,0,1},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191348[] = {
   {6,7,1},
   {7,3,1},
   {6,-6,2},
   {6,5,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191349[] = {
   {6,7,1},
   {7,3,1},
   {6,-6,2},
   {6,5,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191350[] = {
   {6,7,1},
   {7,3,1},
   {6,-6,2},
   {6,5,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191351[] = {
   {3,7,1},
   {7,6,1},
   {-6,-6,2},
   {5,6,2},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191352[] = {
   {3,7,1},
   {7,6,1},
   {-6,-6,2},
   {5,6,2},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191353[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,0,1},
   {6,6,1},
   {7,-4,2}};

static struct patval fuseki191354[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {0,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191355[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {0,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191356[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {0,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191357[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {6,6,1},
   {6,-6,1},
   {4,-7,2}};

static struct patval fuseki191358[] = {
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191359[] = {
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191360[] = {
   {6,-6,1},
   {-6,6,1},
   {-4,-7,1},
   {-6,-6,2}};

static struct patval fuseki191361[] = {
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191362[] = {
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191363[] = {
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191364[] = {
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191365[] = {
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191366[] = {
   {-6,6,1},
   {4,7,1},
   {6,-6,1},
   {6,6,2}};

static struct patval fuseki191367[] = {
   {-6,6,1},
   {6,-6,1},
   {7,4,1},
   {6,6,2}};

static struct patval fuseki191368[] = {
   {6,-6,1},
   {-7,-2,1},
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,6,1},
   {-7,-4,2}};

static struct patval fuseki191369[] = {
   {6,-6,1},
   {-7,-2,1},
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,6,1},
   {-7,-4,2}};

static struct patval fuseki191370[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {-2,7,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191371[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {-2,7,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191372[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {-2,7,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191373[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {-2,7,1},
   {0,0,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191374[] = {
   {-7,2,1},
   {6,6,1},
   {-6,-6,1},
   {-6,6,1},
   {0,0,1},
   {6,-6,1},
   {-7,4,2}};

static struct patval fuseki191375[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191376[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191377[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191378[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191379[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191380[] = {
   {-6,-6,1},
   {-6,6,1},
   {0,-6,1},
   {6,-6,1},
   {5,6,2}};

static struct patval fuseki191381[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {0,-6,1},
   {0,6,1},
   {6,-6,1},
   {6,0,1},
   {6,6,1}};

static struct patval fuseki191382[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {0,-6,1},
   {0,6,1},
   {6,-6,1},
   {6,0,1},
   {6,6,1}};

static struct patval fuseki191383[] = {
   {-6,-6,1},
   {-6,0,1},
   {-6,6,1},
   {0,-6,1},
   {0,6,1},
   {6,-6,1},
   {6,0,1},
   {6,6,1}};

static struct patval fuseki191384[] = {
   {-6,-6,1},
   {5,7,1},
   {-6,6,2},
   {6,-6,2},
   {7,6,2}};

static struct patval fuseki191385[] = {
   {6,6,1},
   {-5,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191386[] = {
   {6,6,1},
   {-5,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191387[] = {
   {-7,-5,1},
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191388[] = {
   {6,6,1},
   {-5,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191389[] = {
   {6,6,1},
   {-5,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191390[] = {
   {6,6,1},
   {-5,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191391[] = {
   {-7,-5,1},
   {6,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191392[] = {
   {6,6,1},
   {-5,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191393[] = {
   {6,6,1},
   {-5,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191394[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {-1,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191395[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,1,1},
   {6,6,1},
   {7,4,2}};

static struct patval fuseki191396[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {-1,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191397[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {-1,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191398[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,-1,1},
   {6,6,1},
   {7,-4,2}};

static struct patval fuseki191399[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,6,1},
   {-1,6,1},
   {6,-6,1},
   {-4,7,2}};

static struct patval fuseki191400[] = {
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191401[] = {
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191402[] = {
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191403[] = {
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191404[] = {
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191405[] = {
   {-7,-4,1},
   {7,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191406[] = {
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191407[] = {
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191408[] = {
   {-7,-6,1},
   {7,4,1},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191409[] = {
   {-6,-7,1},
   {4,7,1},
   {-6,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191410[] = {
   {6,7,1},
   {-4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191411[] = {
   {-7,-6,1},
   {7,4,1},
   {6,-6,2},
   {6,6,2},
   {-6,6,2}};

static struct patval fuseki191412[] = {
   {-6,-6,1},
   {-6,6,1},
   {2,-7,1},
   {6,6,1},
   {6,-4,1},
   {6,-6,1},
   {4,-5,2},
   {4,-7,2}};

static struct patval fuseki191413[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-2,7,1},
   {-4,7,2},
   {-4,5,2}};

static struct patval fuseki191414[] = {
   {-6,-6,1},
   {-6,4,1},
   {-6,6,1},
   {6,6,1},
   {6,-6,1},
   {-2,7,1},
   {-4,7,2},
   {-4,5,2}};

static struct patval fuseki191415[] = {
   {-7,2,1},
   {6,6,1},
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {-4,6,1},
   {-5,4,2},
   {-7,4,2}};

static struct patval fuseki191416[] = {
   {-7,2,1},
   {6,6,1},
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {-4,6,1},
   {-5,4,2},
   {-7,4,2}};

static struct patval fuseki191417[] = {
   {-6,-6,1},
   {-6,6,1},
   {4,6,1},
   {7,2,1},
   {6,-6,1},
   {6,6,1},
   {5,4,2},
   {7,4,2}};

static struct patval fuseki191418[] = {
   {7,-4,1},
   {7,4,1},
   {4,7,2},
   {6,-6,2},
   {6,6,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191419[] = {
   {4,7,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {-7,4,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191420[] = {
   {4,-7,1},
   {-4,-7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2},
   {7,-4,2}};

static struct patval fuseki191421[] = {
   {7,-4,1},
   {7,4,1},
   {4,7,2},
   {6,-6,2},
   {6,6,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191422[] = {
   {4,7,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {6,-6,2},
   {6,6,2},
   {7,4,2}};

static struct patval fuseki191423[] = {
   {4,7,1},
   {-4,7,1},
   {-6,6,2},
   {-6,-6,2},
   {-7,4,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191424[] = {
   {7,-4,1},
   {7,4,1},
   {4,-7,2},
   {6,-6,2},
   {6,6,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191425[] = {
   {-6,-6,1},
   {-6,-4,1},
   {-6,6,1},
   {6,-6,1},
   {-4,-7,2},
   {6,6,2}};

static struct patval fuseki191426[] = {
   {-6,-6,1},
   {-6,-4,1},
   {-6,6,1},
   {6,-6,1},
   {-4,-7,2},
   {6,6,2}};

static struct patval fuseki191427[] = {
   {-6,-6,1},
   {-6,-4,1},
   {-6,6,1},
   {6,-6,1},
   {-4,-7,2},
   {6,6,2}};

static struct patval fuseki191428[] = {
   {-6,-6,1},
   {-6,-4,1},
   {-6,6,1},
   {6,-6,1},
   {-4,-7,2},
   {6,6,2}};

static struct patval fuseki191429[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,1},
   {7,5,2}};

static struct patval fuseki191430[] = {
   {-6,-6,1},
   {-6,6,1},
   {7,6,1},
   {6,-6,1},
   {5,7,2}};

static struct patval fuseki191431[] = {
   {-6,-6,1},
   {-6,6,1},
   {6,-6,1},
   {6,7,1},
   {7,5,2}};

static struct patval fuseki191432[] = {
   {7,6,1},
   {-5,-6,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191433[] = {
   {7,6,1},
   {-5,-6,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191434[] = {
   {6,7,1},
   {-6,-5,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191435[] = {
   {6,7,1},
   {-6,-5,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191436[] = {
   {7,6,1},
   {-5,-6,1},
   {-6,6,2},
   {6,-6,2},
   {-7,-6,2}};

static struct patval fuseki191437[] = {
   {6,4,1},
   {6,6,1},
   {4,7,2},
   {6,-6,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191438[] = {
   {6,4,1},
   {6,6,1},
   {4,7,2},
   {6,-6,2},
   {-6,-6,2},
   {-6,6,2}};

static struct patval fuseki191439[] = {
   {6,6,1},
   {4,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2},
   {7,4,2}};

static struct patval fuseki191440[] = {
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191441[] = {
   {7,-4,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2},
   {-7,-6,2}};

static struct patval fuseki191442[] = {
   {-7,4,1},
   {-6,-6,1},
   {-6,6,2},
   {6,-6,2},
   {7,6,2}};

static struct patval fuseki191443[] = {
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191444[] = {
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191445[] = {
   {-6,-6,1},
   {4,-7,1},
   {-6,6,2},
   {6,-6,2},
   {6,7,2}};

static struct patval fuseki191446[] = {
   {7,-4,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2},
   {-7,-6,2}};

static struct patval fuseki191447[] = {
   {7,-4,1},
   {6,6,1},
   {6,-6,2},
   {-6,6,2},
   {-7,-6,2}};

static struct patval fuseki191448[] = {
   {6,6,1},
   {-4,7,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-7,2}};

static struct patval fuseki191449[] = {
   {7,-4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191450[] = {
   {7,-4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191451[] = {
   {7,-4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191452[] = {
   {7,-4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191453[] = {
   {-7,4,1},
   {-5,-6,1},
   {-6,6,2},
   {6,-6,2},
   {6,6,2}};

static struct patval fuseki191454[] = {
   {7,-4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191455[] = {
   {7,-4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191456[] = {
   {7,-4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2}};

static struct patval fuseki191457[] = {
   {6,4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2},
   {7,6,2}};

static struct patval fuseki191458[] = {
   {6,4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2},
   {7,6,2}};

static struct patval fuseki191459[] = {
   {6,4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2},
   {7,6,2}};

static struct patval fuseki191460[] = {
   {6,4,1},
   {5,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2},
   {7,6,2}};

static struct patval fuseki191461[] = {
   {6,5,1},
   {4,6,1},
   {-6,6,2},
   {6,-6,2},
   {-6,-6,2},
   {6,7,2}};

static struct patval fuseki191462[] = {
   {7,6,1},
   {2,6,1},
   {5,6,2},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191463[] = {
   {-7,-6,1},
   {-2,-6,1},
   {-5,-6,2},
   {-6,6,2},
   {6,-6,2}};

static struct patval fuseki191464[] = {
   {6,7,1},
   {6,2,1},
   {6,-6,2},
   {6,5,2},
   {-6,6,2}};

static struct patval fuseki191465[] = {
   {6,7,1},
   {6,2,1},
   {6,-6,2},
   {6,5,2},
   {-6,6,2}};

static struct patval fuseki191466[] = {
   {7,6,1},
   {2,6,1},
   {5,6,2},
   {6,-6,2},
   {-6,6,2}};

static struct patval fuseki191467[] = {
   {6,7,1},
   {6,2,1},
   {6,-6,2},
   {6,5,2},
   {-6,6,2}};

static struct patval fuseki191468[] = {
   {6,-6,1},
   {-6,6,1},
   {5,7,1},
   {-6,-6,2}};

static struct patval fuseki191469[] = {
   {-6,6,1},
   {-5,-7,1},
   {6,-6,1},
   {6,6,2}};


void
init_tree_fuseki19(void)
{
  /* nothing to do - tree option not compiled */
}

struct fullboard_pattern fuseki19[] = {
  {fuseki190,0,"Fuseki1",-6, 6,4924.000000},
  {fuseki191,0,"Fuseki2",-6, 7,760.000000},
  {fuseki192,0,"Fuseki3", 0, 0,152.000000},
  {fuseki193,0,"Fuseki4",-6, 5,119.000000},
  {fuseki194,0,"Fuseki5",-5, 7,91.000000},
  {fuseki195,0,"Fuseki6",-7, 7,69.000000},
  {fuseki196,1,"Fuseki9", 6,-6,2401.000000},
  {fuseki197,1,"Fuseki10", 6, 6,911.000000},
  {fuseki198,1,"Fuseki11", 7, 6,687.000000},
  {fuseki199,1,"Fuseki12", 7,-6,146.000000},
  {fuseki1910,1,"Fuseki13",-7,-5,122.000000},
  {fuseki1911,1,"Fuseki14", 5, 6,55.000000},
  {fuseki1912,1,"Fuseki15", 7,-7,50.000000},
  {fuseki1913,1,"Fuseki16",-6,-7,50.000000},
  {fuseki1914,1,"Fuseki17", 6,-5,37.000000},
  {fuseki1915,1,"Fuseki18", 0, 0,37.000000},
  {fuseki1916,1,"Fuseki19",-5,-7,29.000000},
  {fuseki1917,1,"Fuseki20",-7,-7,29.000000},
  {fuseki1918,1,"Fuseki21",-7, 4,27.000000},
  {fuseki1919,1,"Fuseki22", 6, 5,14.000000},
  {fuseki1920,1,"Fuseki23", 7, 5,11.000000},
  {fuseki1921,2,"Fuseki24", 6, 6,1193.000000},
  {fuseki1922,2,"Fuseki25", 7, 6,832.000000},
  {fuseki1923,2,"Fuseki26", 6, 7,221.000000},
  {fuseki1924,2,"Fuseki27", 7, 5,45.000000},
  {fuseki1925,2,"Fuseki28",-6,-5,26.000000},
  {fuseki1926,2,"Fuseki29", 7,-4,22.000000},
  {fuseki1927,2,"Fuseki30", 7, 7,12.000000},
  {fuseki1928,3,"Fuseki31", 6, 6,688.000000},
  {fuseki1929,3,"Fuseki32", 7,-6,637.000000},
  {fuseki1930,3,"Fuseki33",-7,-5,77.000000},
  {fuseki1931,3,"Fuseki34",-6,-5,45.000000},
  {fuseki1932,3,"Fuseki35",-6,-7,36.000000},
  {fuseki1933,2,"Fuseki36",-6,-6,360.000000},
  {fuseki1934,2,"Fuseki37", 7, 6,279.000000},
  {fuseki1935,2,"Fuseki38", 6,-6,85.000000},
  {fuseki1936,2,"Fuseki39", 6, 7,79.000000},
  {fuseki1937,2,"Fuseki40",-6, 7,33.000000},
  {fuseki1938,2,"Fuseki41", 5,-6,14.000000},
  {fuseki1939,2,"Fuseki42",-5,-7,12.000000},
  {fuseki1940,2,"Fuseki43", 6,-7,10.000000},
  {fuseki1941,3,"Fuseki44",-6,-6,497.000000},
  {fuseki1942,3,"Fuseki45",-7,-6,212.000000},
  {fuseki1943,3,"Fuseki46",-7,-5,37.000000},
  {fuseki1944,3,"Fuseki47", 5, 6,35.000000},
  {fuseki1945,3,"Fuseki48",-6,-5,19.000000},
  {fuseki1946,3,"Fuseki49",-6,-7,11.000000},
  {fuseki1947,1,"Fuseki50", 6,-6,279.000000},
  {fuseki1948,1,"Fuseki51",-6,-6,205.000000},
  {fuseki1949,1,"Fuseki52",-7,-6,76.000000},
  {fuseki1950,1,"Fuseki53", 6,-6,54.000000},
  {fuseki1951,1,"Fuseki54",-7, 6,20.000000},
  {fuseki1952,1,"Fuseki55",-6, 5,16.000000},
  {fuseki1953,1,"Fuseki56",-5, 7,14.000000},
  {fuseki1954,1,"Fuseki57",-7, 6,11.000000},
  {fuseki1955,4,"Fuseki58",-5,-6,238.000000},
  {fuseki1956,4,"Fuseki59", 6, 0,227.000000},
  {fuseki1957,4,"Fuseki60",-7, 4,109.000000},
  {fuseki1958,4,"Fuseki61", 7,-5,45.000000},
  {fuseki1959,4,"Fuseki62",-4, 7,28.000000},
  {fuseki1960,4,"Fuseki63", 7, 0,11.000000},
  {fuseki1961,4,"Fuseki64",-4,-7,10.000000},
  {fuseki1962,4,"Fuseki65", 7,-4,312.000000},
  {fuseki1963,4,"Fuseki66", 1, 7,114.000000},
  {fuseki1964,4,"Fuseki67", 6, 1,101.000000},
  {fuseki1965,4,"Fuseki68", 5, 7,55.000000},
  {fuseki1966,4,"Fuseki69", 4, 7,39.000000},
  {fuseki1967,4,"Fuseki70", 4,-7,17.000000},
  {fuseki1968,2,"Fuseki71",-6,-6,265.000000},
  {fuseki1969,2,"Fuseki72", 7, 6,169.000000},
  {fuseki1970,2,"Fuseki73", 6,-6,98.000000},
  {fuseki1971,2,"Fuseki74",-7,-6,56.000000},
  {fuseki1972,2,"Fuseki75", 6,-7,28.000000},
  {fuseki1973,2,"Fuseki76", 6,-5,20.000000},
  {fuseki1974,2,"Fuseki77", 6,-7,15.000000},
  {fuseki1975,4,"Fuseki78", 4, 7,304.000000},
  {fuseki1976,4,"Fuseki79", 0, 6,269.000000},
  {fuseki1977,4,"Fuseki80",-4, 7,34.000000},
  {fuseki1978,4,"Fuseki81", 0, 0,19.000000},
  {fuseki1979,4,"Fuseki82", 0, 6,12.000000},
  {fuseki1980,5,"Fuseki83", 4,-7,74.000000},
  {fuseki1981,5,"Fuseki84", 4,-6,56.000000},
  {fuseki1982,5,"Fuseki85", 5, 6,45.000000},
  {fuseki1983,5,"Fuseki86", 7,-2,39.000000},
  {fuseki1984,5,"Fuseki87", 1,-6,33.000000},
  {fuseki1985,5,"Fuseki88", 0, 6,22.000000},
  {fuseki1986,3,"Fuseki89", 6,-6,198.000000},
  {fuseki1987,3,"Fuseki90",-7,-6,28.000000},
  {fuseki1988,3,"Fuseki91", 5, 6,22.000000},
  {fuseki1989,3,"Fuseki92", 6,-7,18.000000},
  {fuseki1990,3,"Fuseki93", 4, 6,13.000000},
  {fuseki1991,5,"Fuseki94", 4,-7,82.000000},
  {fuseki1992,5,"Fuseki95", 7,-2,74.000000},
  {fuseki1993,5,"Fuseki96",-4,-6,57.000000},
  {fuseki1994,5,"Fuseki97", 0, 6,25.000000},
  {fuseki1995,5,"Fuseki98",-6,-1,20.000000},
  {fuseki1996,5,"Fuseki99",-1,-7,9.000000},
  {fuseki1997,3,"Fuseki100",-6, 6,101.000000},
  {fuseki1998,3,"Fuseki101", 7,-6,90.000000},
  {fuseki1999,3,"Fuseki102", 7,-6,36.000000},
  {fuseki19100,3,"Fuseki103", 5, 7,20.000000},
  {fuseki19101,3,"Fuseki104", 5,-7,16.000000},
  {fuseki19102,2,"Fuseki105", 7, 6,117.000000},
  {fuseki19103,2,"Fuseki106", 6, 6,40.000000},
  {fuseki19104,2,"Fuseki107", 6,-6,32.000000},
  {fuseki19105,2,"Fuseki108",-6,-7,28.000000},
  {fuseki19106,2,"Fuseki109", 6, 7,21.000000},
  {fuseki19107,2,"Fuseki110",-5,-7,13.000000},
  {fuseki19108,5,"Fuseki111",-7, 4,202.000000},
  {fuseki19109,5,"Fuseki112", 6, 0,30.000000},
  {fuseki19110,5,"Fuseki113",-6, 0,13.000000},
  {fuseki19111,4,"Fuseki114", 7,-4,75.000000},
  {fuseki19112,4,"Fuseki115",-5,-6,58.000000},
  {fuseki19113,4,"Fuseki116", 7,-1,45.000000},
  {fuseki19114,4,"Fuseki117", 1, 6,40.000000},
  {fuseki19115,4,"Fuseki118", 5, 7,13.000000},
  {fuseki19116,4,"Fuseki119",-5, 7,9.000000},
  {fuseki19117,3,"Fuseki120",-6,-6,120.000000},
  {fuseki19118,3,"Fuseki121",-7,-6,63.000000},
  {fuseki19119,3,"Fuseki122",-6, 5,33.000000},
  {fuseki19120,3,"Fuseki123", 7, 5,18.000000},
  {fuseki19121,5,"Fuseki124",-2,-6,93.000000},
  {fuseki19122,5,"Fuseki125", 7,-5,62.000000},
  {fuseki19123,5,"Fuseki126", 6,-4,29.000000},
  {fuseki19124,5,"Fuseki127",-3,-7,24.000000},
  {fuseki19125,5,"Fuseki128", 4, 7,149.000000},
  {fuseki19126,5,"Fuseki129",-4, 7,47.000000},
  {fuseki19127,2,"Fuseki130", 7, 6,92.000000},
  {fuseki19128,2,"Fuseki131", 6, 6,39.000000},
  {fuseki19129,2,"Fuseki132", 7,-6,29.000000},
  {fuseki19130,2,"Fuseki133", 6,-6,16.000000},
  {fuseki19131,6,"Fuseki134",-7, 2,91.000000},
  {fuseki19132,6,"Fuseki135", 6, 4,28.000000},
  {fuseki19133,6,"Fuseki136", 4, 6,26.000000},
  {fuseki19134,6,"Fuseki137", 0, 6,14.000000},
  {fuseki19135,4,"Fuseki138", 7, 5,63.000000},
  {fuseki19136,4,"Fuseki139",-7,-4,53.000000},
  {fuseki19137,4,"Fuseki140", 7, 1,37.000000},
  {fuseki19138,4,"Fuseki141",-6, 5,9.000000},
  {fuseki19139,4,"Fuseki142",-7, 4,9.000000},
  {fuseki19140,4,"Fuseki143", 4, 7,7.000000},
  {fuseki19141,3,"Fuseki144", 6,-6,49.000000},
  {fuseki19142,3,"Fuseki145", 6, 7,43.000000},
  {fuseki19143,3,"Fuseki146", 7,-6,30.000000},
  {fuseki19144,3,"Fuseki147", 5, 6,11.000000},
  {fuseki19145,3,"Fuseki148",-7, 5,10.000000},
  {fuseki19146,3,"Fuseki149",-5, 7,8.000000},
  {fuseki19147,3,"Fuseki150", 7,-7,6.000000},
  {fuseki19148,1,"Fuseki151", 6, 6,92.000000},
  {fuseki19149,6,"Fuseki152",-2,-7,64.000000},
  {fuseki19150,6,"Fuseki153", 4, 6,29.000000},
  {fuseki19151,6,"Fuseki154",-4, 6,17.000000},
  {fuseki19152,6,"Fuseki155", 6, 0,11.000000},
  {fuseki19153,6,"Fuseki156",-6, 1,10.000000},
  {fuseki19154,2,"Fuseki157", 6, 6,45.000000},
  {fuseki19155,2,"Fuseki158", 6, 6,30.000000},
  {fuseki19156,2,"Fuseki159",-6,-7,27.000000},
  {fuseki19157,2,"Fuseki160",-7,-6,8.000000},
  {fuseki19158,2,"Fuseki161", 7, 6,8.000000},
  {fuseki19159,2,"Fuseki162", 6,-5,6.000000},
  {fuseki19160,2,"Fuseki163", 5,-6,5.000000},
  {fuseki19161,4,"Fuseki164",-7, 5,68.000000},
  {fuseki19162,4,"Fuseki165",-7,-4,37.000000},
  {fuseki19163,4,"Fuseki166",-7, 4,8.000000},
  {fuseki19164,4,"Fuseki167",-6,-5,7.000000},
  {fuseki19165,4,"Fuseki168", 7,-4,7.000000},
  {fuseki19166,3,"Fuseki169",-6,-6,75.000000},
  {fuseki19167,3,"Fuseki170",-7,-6,32.000000},
  {fuseki19168,3,"Fuseki171",-5, 6,11.000000},
  {fuseki19169,2,"Fuseki172", 6, 6,40.000000},
  {fuseki19170,2,"Fuseki173", 7, 6,26.000000},
  {fuseki19171,2,"Fuseki174",-6,-6,25.000000},
  {fuseki19172,2,"Fuseki175", 6, 7,4.000000},
  {fuseki19173,2,"Fuseki176", 7, 5,4.000000},
  {fuseki19174,2,"Fuseki177", 6,-7,4.000000},
  {fuseki19175,3,"Fuseki178",-6,-6,69.000000},
  {fuseki19176,3,"Fuseki179",-7,-6,29.000000},
  {fuseki19177,3,"Fuseki180",-5,-6,12.000000},
  {fuseki19178,1,"Fuseki181",-6, 6,47.000000},
  {fuseki19179,1,"Fuseki182", 6, 6,28.000000},
  {fuseki19180,1,"Fuseki183", 6, 6,10.000000},
  {fuseki19181,5,"Fuseki184",-7, 4,39.000000},
  {fuseki19182,5,"Fuseki185", 6, 3,26.000000},
  {fuseki19183,5,"Fuseki186", 1,-7,12.000000},
  {fuseki19184,5,"Fuseki187", 0,-6,12.000000},
  {fuseki19185,5,"Fuseki188", 0,-6,9.000000},
  {fuseki19186,5,"Fuseki189",-7, 0,4.000000},
  {fuseki19187,3,"Fuseki190", 6,-6,59.000000},
  {fuseki19188,3,"Fuseki191",-7, 5,25.000000},
  {fuseki19189,3,"Fuseki192",-6, 5,12.000000},
  {fuseki19190,3,"Fuseki193", 6, 7,7.000000},
  {fuseki19191,5,"Fuseki194",-4, 7,36.000000},
  {fuseki19192,5,"Fuseki195",-4,-6,29.000000},
  {fuseki19193,5,"Fuseki196",-6,-1,15.000000},
  {fuseki19194,5,"Fuseki197",-6, 0,10.000000},
  {fuseki19195,5,"Fuseki198",-2, 7,8.000000},
  {fuseki19196,3,"Fuseki199",-6,-6,30.000000},
  {fuseki19197,3,"Fuseki200", 7, 6,19.000000},
  {fuseki19198,3,"Fuseki201",-7,-6,13.000000},
  {fuseki19199,3,"Fuseki202", 7, 5,10.000000},
  {fuseki19200,3,"Fuseki203",-7,-7,10.000000},
  {fuseki19201,3,"Fuseki204", 6, 5,6.000000},
  {fuseki19202,3,"Fuseki205", 7,-4,5.000000},
  {fuseki19203,5,"Fuseki206", 6, 3,30.000000},
  {fuseki19204,5,"Fuseki207",-7, 4,30.000000},
  {fuseki19205,5,"Fuseki208", 0, 6,11.000000},
  {fuseki19206,5,"Fuseki209",-6, 0,6.000000},
  {fuseki19207,5,"Fuseki210", 6, 1,4.000000},
  {fuseki19208,5,"Fuseki211", 7, 1,3.000000},
  {fuseki19209,6,"Fuseki212",-6,-3,43.000000},
  {fuseki19210,6,"Fuseki213",-5,-4,18.000000},
  {fuseki19211,6,"Fuseki214",-7,-5,15.000000},
  {fuseki19212,6,"Fuseki215",-7,-7,6.000000},
  {fuseki19213,2,"Fuseki216", 0, 6,22.000000},
  {fuseki19214,2,"Fuseki217", 6, 6,18.000000},
  {fuseki19215,2,"Fuseki218", 6, 6,14.000000},
  {fuseki19216,2,"Fuseki219",-7, 5,6.000000},
  {fuseki19217,2,"Fuseki220", 5, 7,4.000000},
  {fuseki19218,2,"Fuseki221",-7,-7,4.000000},
  {fuseki19219,2,"Fuseki223",-6,-5,3.000000},
  {fuseki19220,1,"Fuseki224", 6,-6,33.000000},
  {fuseki19221,1,"Fuseki225",-6,-6,25.000000},
  {fuseki19222,1,"Fuseki226",-7, 6,6.000000},
  {fuseki19223,1,"Fuseki227",-6,-6,4.000000},
  {fuseki19224,1,"Fuseki228",-7,-6,4.000000},
  {fuseki19225,7,"Fuseki229",-7, 7,53.000000},
  {fuseki19226,7,"Fuseki230",-4,-5,17.000000},
  {fuseki19227,7,"Fuseki231", 6, 2,14.000000},
  {fuseki19228,4,"Fuseki232",-5,-6,34.000000},
  {fuseki19229,4,"Fuseki233", 0, 6,31.000000},
  {fuseki19230,4,"Fuseki234", 5, 7,10.000000},
  {fuseki19231,4,"Fuseki235",-6, 0,24.000000},
  {fuseki19232,4,"Fuseki236",-6,-7,22.000000},
  {fuseki19233,4,"Fuseki237",-4,-7,16.000000},
  {fuseki19234,4,"Fuseki238",-5,-6,7.000000},
  {fuseki19235,4,"Fuseki239",-7,-4,6.000000},
  {fuseki19236,4,"Fuseki240",-7, 0,4.000000},
  {fuseki19237,4,"Fuseki241",-5, 7,38.000000},
  {fuseki19238,4,"Fuseki242", 7,-4,24.000000},
  {fuseki19239,4,"Fuseki243", 7, 1,11.000000},
  {fuseki19240,4,"Fuseki244", 5,-6,5.000000},
  {fuseki19241,3,"Fuseki245",-6,-6,53.000000},
  {fuseki19242,3,"Fuseki246",-7,-6,14.000000},
  {fuseki19243,6,"Fuseki247", 8,-6,35.000000},
  {fuseki19244,6,"Fuseki248",-6, 0,32.000000},
  {fuseki19245,6,"Fuseki249",-7,-4,5.000000},
  {fuseki19246,2,"Fuseki250", 7, 6,35.000000},
  {fuseki19247,2,"Fuseki251", 6, 6,11.000000},
  {fuseki19248,2,"Fuseki252", 7,-6,7.000000},
  {fuseki19249,2,"Fuseki253",-6,-6,5.000000},
  {fuseki19250,2,"Fuseki254", 7,-6,5.000000},
  {fuseki19251,5,"Fuseki255", 4,-7,18.000000},
  {fuseki19252,5,"Fuseki256", 4,-6,15.000000},
  {fuseki19253,5,"Fuseki257", 6,-1,12.000000},
  {fuseki19254,5,"Fuseki258", 6, 5,10.000000},
  {fuseki19255,5,"Fuseki259", 5, 7,7.000000},
  {fuseki19256,5,"Fuseki260", 7,-2,4.000000},
  {fuseki19257,5,"Fuseki261", 7,-1,3.000000},
  {fuseki19258,5,"Fuseki262", 6, 0,2.000000},
  {fuseki19259,5,"Fuseki263",-7, 3,2.000000},
  {fuseki19260,4,"Fuseki264", 6,-5,35.000000},
  {fuseki19261,4,"Fuseki265", 0, 6,18.000000},
  {fuseki19262,4,"Fuseki266", 5, 7,10.000000},
  {fuseki19263,4,"Fuseki267", 6, 5,5.000000},
  {fuseki19264,6,"Fuseki268", 6, 0,42.000000},
  {fuseki19265,6,"Fuseki269", 6, 1,14.000000},
  {fuseki19266,6,"Fuseki270", 8,-6,10.000000},
  {fuseki19267,6,"Fuseki271", 7,-7,40.000000},
  {fuseki19268,6,"Fuseki272",-5,-4,27.000000},
  {fuseki19269,6,"Fuseki273", 6,-2,4.000000},
  {fuseki19270,5,"Fuseki274", 0, 7,46.000000},
  {fuseki19271,5,"Fuseki275",-7, 4,8.000000},
  {fuseki19272,5,"Fuseki276", 0, 6,6.000000},
  {fuseki19273,5,"Fuseki277", 5, 6,37.000000},
  {fuseki19274,5,"Fuseki278", 0, 7,12.000000},
  {fuseki19275,5,"Fuseki279", 4, 7,7.000000},
  {fuseki19276,5,"Fuseki280",-7,-5,5.000000},
  {fuseki19277,3,"Fuseki281",-7,-6,39.000000},
  {fuseki19278,3,"Fuseki282",-6,-6,24.000000},
  {fuseki19279,1,"Fuseki283",-6,-6,42.000000},
  {fuseki19280,1,"Fuseki284", 6, 6,8.000000},
  {fuseki19281,1,"Fuseki285",-7,-6,5.000000},
  {fuseki19282,1,"Fuseki286",-6, 7,5.000000},
  {fuseki19283,7,"Fuseki287",-7,-7,29.000000},
  {fuseki19284,7,"Fuseki288",-6, 2,16.000000},
  {fuseki19285,7,"Fuseki289",-5, 4,10.000000},
  {fuseki19286,7,"Fuseki290",-7, 4,5.000000},
  {fuseki19287,7,"Fuseki291",-4, 6,3.000000},
  {fuseki19288,6,"Fuseki292", 7,-4,54.000000},
  {fuseki19289,6,"Fuseki293",-6,-6,8.000000},
  {fuseki19290,4,"Fuseki294",-5, 6,22.000000},
  {fuseki19291,4,"Fuseki295",-7,-5,13.000000},
  {fuseki19292,4,"Fuseki296", 6, 0,12.000000},
  {fuseki19293,4,"Fuseki297",-4, 7,4.000000},
  {fuseki19294,5,"Fuseki298",-2,-6,26.000000},
  {fuseki19295,5,"Fuseki299",-5,-7,14.000000},
  {fuseki19296,5,"Fuseki300", 3, 7,8.000000},
  {fuseki19297,5,"Fuseki301",-6,-4,5.000000},
  {fuseki19298,3,"Fuseki302",-6, 6,23.000000},
  {fuseki19299,3,"Fuseki303", 6,-7,13.000000},
  {fuseki19300,3,"Fuseki304",-5,-6,6.000000},
  {fuseki19301,3,"Fuseki305", 7,-5,4.000000},
  {fuseki19302,3,"Fuseki306",-4,-6,3.000000},
  {fuseki19303,6,"Fuseki307",-8,-6,24.000000},
  {fuseki19304,6,"Fuseki308", 0, 6,20.000000},
  {fuseki19305,6,"Fuseki309", 1,-6,6.000000},
  {fuseki19306,5,"Fuseki310", 7, 1,22.000000},
  {fuseki19307,5,"Fuseki311", 7, 0,14.000000},
  {fuseki19308,5,"Fuseki312", 6, 0,7.000000},
  {fuseki19309,5,"Fuseki313",-7, 4,6.000000},
  {fuseki19310,6,"Fuseki314", 6, 0,40.000000},
  {fuseki19311,6,"Fuseki315", 6,-1,11.000000},
  {fuseki19312,6,"Fuseki316", 8,-6,4.000000},
  {fuseki19313,2,"Fuseki317",-6,-6,23.000000},
  {fuseki19314,2,"Fuseki318",-6,-7,12.000000},
  {fuseki19315,2,"Fuseki319", 6,-6,9.000000},
  {fuseki19316,2,"Fuseki320",-5,-6,3.000000},
  {fuseki19317,2,"Fuseki321",-6,-7,3.000000},
  {fuseki19318,7,"Fuseki322", 7,-6,53.000000},
  {fuseki19319,2,"Fuseki323",-6, 7,17.000000},
  {fuseki19320,2,"Fuseki324",-6,-6,9.000000},
  {fuseki19321,2,"Fuseki325",-6,-6,8.000000},
  {fuseki19322,2,"Fuseki326", 7,-6,8.000000},
  {fuseki19323,2,"Fuseki327", 7,-6,3.000000},
  {fuseki19324,2,"Fuseki328", 7,-5,2.000000},
  {fuseki19325,2,"Fuseki329", 6,-7,2.000000},
  {fuseki19326,2,"Fuseki330",-5, 7,2.000000},
  {fuseki19327,8,"Fuseki331",-4,-6,25.000000},
  {fuseki19328,8,"Fuseki332", 6,-3,13.000000},
  {fuseki19329,8,"Fuseki333", 7,-4,9.000000},
  {fuseki19330,8,"Fuseki334", 4,-7,5.000000},
  {fuseki19331,8,"Fuseki335",-6, 7,51.000000},
  {fuseki19332,4,"Fuseki336", 7, 4,39.000000},
  {fuseki19333,4,"Fuseki337", 0, 0,5.000000},
  {fuseki19334,5,"Fuseki338", 4,-7,12.000000},
  {fuseki19335,5,"Fuseki339",-5,-6,10.000000},
  {fuseki19336,5,"Fuseki340", 4,-6,9.000000},
  {fuseki19337,5,"Fuseki341", 2,-7,7.000000},
  {fuseki19338,5,"Fuseki342", 6,-1,5.000000},
  {fuseki19339,5,"Fuseki343",-7, 5,3.000000},
  {fuseki19340,5,"Fuseki344", 6, 0,2.000000},
  {fuseki19341,5,"Fuseki345",-7, 4,2.000000},
  {fuseki19342,9,"Fuseki346",-7, 6,51.000000},
  {fuseki19343,2,"Fuseki347", 6, 6,26.000000},
  {fuseki19344,2,"Fuseki348", 7, 6,8.000000},
  {fuseki19345,2,"Fuseki349", 5, 6,3.000000},
  {fuseki19346,2,"Fuseki350",-7,-6,3.000000},
  {fuseki19347,2,"Fuseki351", 6,-6,3.000000},
  {fuseki19348,2,"Fuseki352", 6, 6,22.000000},
  {fuseki19349,2,"Fuseki353",-7, 6,11.000000},
  {fuseki19350,2,"Fuseki354", 6,-6,6.000000},
  {fuseki19351,2,"Fuseki355",-6,-7,5.000000},
  {fuseki19352,5,"Fuseki356",-2,-6,18.000000},
  {fuseki19353,5,"Fuseki357",-1,-7,7.000000},
  {fuseki19354,5,"Fuseki358", 7,-3,6.000000},
  {fuseki19355,5,"Fuseki359",-6, 7,4.000000},
  {fuseki19356,5,"Fuseki360",-2,-7,3.000000},
  {fuseki19357,5,"Fuseki361", 5,-6,2.000000},
  {fuseki19358,5,"Fuseki362", 5, 6,2.000000},
  {fuseki19359,6,"Fuseki363", 7, 2,19.000000},
  {fuseki19360,6,"Fuseki364", 4, 6,9.000000},
  {fuseki19361,6,"Fuseki365",-1, 6,4.000000},
  {fuseki19362,6,"Fuseki366",-4,-6,3.000000},
  {fuseki19363,6,"Fuseki367", 6, 0,2.000000},
  {fuseki19364,6,"Fuseki368",-5,-6,2.000000},
  {fuseki19365,6,"Fuseki369",-4,-5,2.000000},
  {fuseki19366,6,"Fuseki370",-6, 0,2.000000},
  {fuseki19367,6,"Fuseki371",-4, 7,2.000000},
  {fuseki19368,4,"Fuseki372",-6,-7,12.000000},
  {fuseki19369,4,"Fuseki373", 7,-4,11.000000},
  {fuseki19370,4,"Fuseki374", 0, 6,11.000000},
  {fuseki19371,4,"Fuseki375", 7,-7,2.000000},
  {fuseki19372,2,"Fuseki376", 6, 5,12.000000},
  {fuseki19373,2,"Fuseki377", 6, 6,5.000000},
  {fuseki19374,2,"Fuseki378", 6, 7,4.000000},
  {fuseki19375,2,"Fuseki379", 6, 5,4.000000},
  {fuseki19376,2,"Fuseki380", 6, 5,4.000000},
  {fuseki19377,2,"Fuseki381", 5, 6,3.000000},
  {fuseki19378,2,"Fuseki382", 7, 5,3.000000},
  {fuseki19379,2,"Fuseki383", 6, 6,2.000000},
  {fuseki19380,2,"Fuseki384", 6, 7,2.000000},
  {fuseki19381,2,"Fuseki385", 6, 7,2.000000},
  {fuseki19382,6,"Fuseki387", 2, 7,26.000000},
  {fuseki19383,6,"Fuseki388", 0,-7,6.000000},
  {fuseki19384,6,"Fuseki389",-3, 7,4.000000},
  {fuseki19385,6,"Fuseki390", 2, 6,13.000000},
  {fuseki19386,6,"Fuseki391", 4,-7,10.000000},
  {fuseki19387,6,"Fuseki392", 5, 5,7.000000},
  {fuseki19388,6,"Fuseki393", 6, 4,6.000000},
  {fuseki19389,6,"Fuseki394", 5, 7,5.000000},
  {fuseki19390,6,"Fuseki395", 3, 7,4.000000},
  {fuseki19391,4,"Fuseki396", 7, 1,11.000000},
  {fuseki19392,4,"Fuseki397", 6, 5,10.000000},
  {fuseki19393,4,"Fuseki398", 1, 6,6.000000},
  {fuseki19394,4,"Fuseki399", 5,-6,5.000000},
  {fuseki19395,4,"Fuseki400", 7, 0,3.000000},
  {fuseki19396,4,"Fuseki401", 5,-7,2.000000},
  {fuseki19397,4,"Fuseki402", 6, 0,2.000000},
  {fuseki19398,4,"Fuseki403", 7, 5,2.000000},
  {fuseki19399,3,"Fuseki404",-6,-6,28.000000},
  {fuseki19400,3,"Fuseki405",-7,-6,10.000000},
  {fuseki19401,3,"Fuseki406", 6, 7,3.000000},
  {fuseki19402,5,"Fuseki407",-7, 4,23.000000},
  {fuseki19403,5,"Fuseki408",-6,-1,7.000000},
  {fuseki19404,5,"Fuseki409", 7, 1,3.000000},
  {fuseki19405,3,"Fuseki410",-7,-6,12.000000},
  {fuseki19406,3,"Fuseki411", 7,-5,12.000000},
  {fuseki19407,3,"Fuseki412",-6, 6,12.000000},
  {fuseki19408,3,"Fuseki413", 5,-6,3.000000},
  {fuseki19409,3,"Fuseki414",-4, 7,2.000000},
  {fuseki19410,4,"Fuseki415", 5, 6,16.000000},
  {fuseki19411,4,"Fuseki416",-5,-7,15.000000},
  {fuseki19412,4,"Fuseki417",-4,-7,7.000000},
  {fuseki19413,4,"Fuseki418", 0, 0,2.000000},
  {fuseki19414,4,"Fuseki419", 7, 4,2.000000},
  {fuseki19415,4,"Fuseki420", 5,-6,25.000000},
  {fuseki19416,4,"Fuseki421", 5,-7,7.000000},
  {fuseki19417,4,"Fuseki422", 1, 7,4.000000},
  {fuseki19418,4,"Fuseki423", 6,-1,4.000000},
  {fuseki19419,7,"Fuseki424",-5,-5,31.000000},
  {fuseki19420,7,"Fuseki425",-5,-4,9.000000},
  {fuseki19421,5,"Fuseki426", 0, 7,33.000000},
  {fuseki19422,5,"Fuseki427",-7, 1,4.000000},
  {fuseki19423,2,"Fuseki428", 7, 6,12.000000},
  {fuseki19424,2,"Fuseki429", 7, 7,9.000000},
  {fuseki19425,2,"Fuseki430", 6,-6,7.000000},
  {fuseki19426,2,"Fuseki431", 7,-4,3.000000},
  {fuseki19427,2,"Fuseki432", 5, 7,3.000000},
  {fuseki19428,2,"Fuseki433",-7,-7,2.000000},
  {fuseki19429,2,"Fuseki434", 7, 5,2.000000},
  {fuseki19430,4,"Fuseki435", 7,-4,16.000000},
  {fuseki19431,4,"Fuseki436", 1, 6,6.000000},
  {fuseki19432,4,"Fuseki437",-7,-5,5.000000},
  {fuseki19433,4,"Fuseki438",-7,-1,4.000000},
  {fuseki19434,4,"Fuseki439",-6,-7,3.000000},
  {fuseki19435,4,"Fuseki440", 0,-7,2.000000},
  {fuseki19436,4,"Fuseki441",-5,-6,2.000000},
  {fuseki19437,7,"Fuseki442", 4, 7,18.000000},
  {fuseki19438,7,"Fuseki443",-6,-5,7.000000},
  {fuseki19439,7,"Fuseki444",-6,-4,6.000000},
  {fuseki19440,7,"Fuseki445", 5, 7,6.000000},
  {fuseki19441,7,"Fuseki446",-7, 4,2.000000},
  {fuseki19442,3,"Fuseki447", 6, 6,18.000000},
  {fuseki19443,3,"Fuseki448", 7, 6,8.000000},
  {fuseki19444,3,"Fuseki449",-7,-6,4.000000},
  {fuseki19445,3,"Fuseki450", 5,-6,3.000000},
  {fuseki19446,3,"Fuseki451", 5,-7,2.000000},
  {fuseki19447,3,"Fuseki452",-7, 5,2.000000},
  {fuseki19448,3,"Fuseki453",-7,-7,2.000000},
  {fuseki19449,5,"Fuseki454",-7, 4,18.000000},
  {fuseki19450,5,"Fuseki455", 7, 1,10.000000},
  {fuseki19451,5,"Fuseki456", 6, 3,3.000000},
  {fuseki19452,5,"Fuseki457",-7, 0,2.000000},
  {fuseki19453,4,"Fuseki458",-7, 5,22.000000},
  {fuseki19454,4,"Fuseki459", 7, 5,6.000000},
  {fuseki19455,4,"Fuseki460",-5,-6,4.000000},
  {fuseki19456,4,"Fuseki461", 6,-5,4.000000},
  {fuseki19457,7,"Fuseki462", 7,-6,34.000000},
  {fuseki19458,7,"Fuseki463", 6,-7,6.000000},
  {fuseki19459,7,"Fuseki464",-6, 5,15.000000},
  {fuseki19460,7,"Fuseki465",-7, 4,7.000000},
  {fuseki19461,7,"Fuseki466", 4, 6,4.000000},
  {fuseki19462,7,"Fuseki467",-4,-7,4.000000},
  {fuseki19463,7,"Fuseki468",-7,-5,4.000000},
  {fuseki19464,7,"Fuseki469",-4, 7,4.000000},
  {fuseki19465,5,"Fuseki470", 7,-4,19.000000},
  {fuseki19466,5,"Fuseki471", 3, 7,4.000000},
  {fuseki19467,5,"Fuseki472", 4,-6,4.000000},
  {fuseki19468,5,"Fuseki473", 7, 2,3.000000},
  {fuseki19469,5,"Fuseki474",-4,-6,2.000000},
  {fuseki19470,5,"Fuseki475", 6, 1,2.000000},
  {fuseki19471,6,"Fuseki476", 7,-7,18.000000},
  {fuseki19472,6,"Fuseki477", 5,-4,15.000000},
  {fuseki19473,6,"Fuseki478", 2,-6,4.000000},
  {fuseki19474,5,"Fuseki479", 7, 4,13.000000},
  {fuseki19475,5,"Fuseki480",-4,-6,7.000000},
  {fuseki19476,5,"Fuseki481", 6, 1,7.000000},
  {fuseki19477,5,"Fuseki482",-7,-2,5.000000},
  {fuseki19478,5,"Fuseki483",-7, 4,2.000000},
  {fuseki19479,5,"Fuseki484", 5, 7,2.000000},
  {fuseki19480,5,"Fuseki485", 0, 6,2.000000},
  {fuseki19481,6,"Fuseki486",-4, 6,18.000000},
  {fuseki19482,6,"Fuseki487", 1,-6,9.000000},
  {fuseki19483,6,"Fuseki488", 6,-4,6.000000},
  {fuseki19484,6,"Fuseki489",-7, 2,5.000000},
  {fuseki19485,3,"Fuseki490",-7, 5,12.000000},
  {fuseki19486,3,"Fuseki491", 6,-6,8.000000},
  {fuseki19487,3,"Fuseki492", 7,-6,8.000000},
  {fuseki19488,3,"Fuseki493", 7,-6,4.000000},
  {fuseki19489,3,"Fuseki494", 5,-6,2.000000},
  {fuseki19490,3,"Fuseki495",-7,-7,2.000000},
  {fuseki19491,5,"Fuseki496", 0, 7,17.000000},
  {fuseki19492,5,"Fuseki497",-7, 4,7.000000},
  {fuseki19493,5,"Fuseki498", 0,-6,5.000000},
  {fuseki19494,5,"Fuseki499",-7, 4,2.000000},
  {fuseki19495,5,"Fuseki500",-7,-1,2.000000},
  {fuseki19496,2,"Fuseki501", 6, 6,18.000000},
  {fuseki19497,2,"Fuseki502",-6,-6,10.000000},
  {fuseki19498,2,"Fuseki503", 0, 6,4.000000},
  {fuseki19499,5,"Fuseki504",-4,-7,12.000000},
  {fuseki19500,5,"Fuseki505",-6, 5,7.000000},
  {fuseki19501,5,"Fuseki506", 6,-4,6.000000},
  {fuseki19502,5,"Fuseki507", 1,-6,5.000000},
  {fuseki19503,5,"Fuseki508",-6, 4,3.000000},
  {fuseki19504,5,"Fuseki509",-7,-2,2.000000},
  {fuseki19505,6,"Fuseki510", 5, 7,20.000000},
  {fuseki19506,6,"Fuseki511",-2, 6,11.000000},
  {fuseki19507,6,"Fuseki512", 3, 7,2.000000},
  {fuseki19508,6,"Fuseki513", 1, 6,2.000000},
  {fuseki19509,2,"Fuseki514",-6,-6,8.000000},
  {fuseki19510,2,"Fuseki515", 6, 6,7.000000},
  {fuseki19511,2,"Fuseki516", 7, 6,7.000000},
  {fuseki19512,2,"Fuseki517",-6,-7,6.000000},
  {fuseki19513,5,"Fuseki518",-7, 4,17.000000},
  {fuseki19514,5,"Fuseki519", 4,-6,6.000000},
  {fuseki19515,5,"Fuseki520",-7, 2,4.000000},
  {fuseki19516,5,"Fuseki521", 0, 6,3.000000},
  {fuseki19517,4,"Fuseki522", 7,-4,15.000000},
  {fuseki19518,4,"Fuseki523", 6, 7,10.000000},
  {fuseki19519,4,"Fuseki524",-4,-7,3.000000},
  {fuseki19520,3,"Fuseki525",-6, 6,19.000000},
  {fuseki19521,3,"Fuseki526", 7, 6,9.000000},
  {fuseki19522,3,"Fuseki527", 6,-7,3.000000},
  {fuseki19523,3,"Fuseki528",-6,-4,3.000000},
  {fuseki19524,6,"Fuseki529", 6, 0,16.000000},
  {fuseki19525,6,"Fuseki530",-8, 6,14.000000},
  {fuseki19526,6,"Fuseki531", 5,-7,2.000000},
  {fuseki19527,6,"Fuseki532",-5,-4,2.000000},
  {fuseki19528,4,"Fuseki533", 2, 6,10.000000},
  {fuseki19529,4,"Fuseki534", 6, 4,7.000000},
  {fuseki19530,4,"Fuseki535",-5,-7,6.000000},
  {fuseki19531,4,"Fuseki536",-6,-7,4.000000},
  {fuseki19532,4,"Fuseki537",-6,-6,2.000000},
  {fuseki19533,4,"Fuseki538", 5, 5,2.000000},
  {fuseki19534,4,"Fuseki539", 6, 3,2.000000},
  {fuseki19535,7,"Fuseki540", 7,-7,21.000000},
  {fuseki19536,7,"Fuseki541",-4, 7,7.000000},
  {fuseki19537,5,"Fuseki542", 6,-2,15.000000},
  {fuseki19538,5,"Fuseki543", 7,-3,7.000000},
  {fuseki19539,5,"Fuseki544",-7,-5,6.000000},
  {fuseki19540,5,"Fuseki545", 4,-7,3.000000},
  {fuseki19541,8,"Fuseki546", 6,-7,34.000000},
  {fuseki19542,9,"Fuseki547", 5,-6,32.000000},
  {fuseki19543,5,"Fuseki548", 7,-5,14.000000},
  {fuseki19544,5,"Fuseki549",-2,-6,10.000000},
  {fuseki19545,5,"Fuseki550",-3, 6,4.000000},
  {fuseki19546,5,"Fuseki551",-6,-4,3.000000},
  {fuseki19547,6,"Fuseki552", 2, 7,13.000000},
  {fuseki19548,6,"Fuseki553",-5, 6,5.000000},
  {fuseki19549,6,"Fuseki554", 3, 7,4.000000},
  {fuseki19550,6,"Fuseki555",-4,-7,4.000000},
  {fuseki19551,6,"Fuseki556",-7,-5,3.000000},
  {fuseki19552,6,"Fuseki557",-4,-7,2.000000},
  {fuseki19553,3,"Fuseki558",-7,-6,18.000000},
  {fuseki19554,3,"Fuseki559",-7,-7,12.000000},
  {fuseki19555,3,"Fuseki560", 6, 6,2.000000},
  {fuseki19556,4,"Fuseki561",-6,-6,12.000000},
  {fuseki19557,4,"Fuseki562", 6, 2,6.000000},
  {fuseki19558,4,"Fuseki563", 7, 5,6.000000},
  {fuseki19559,4,"Fuseki564",-3,-7,3.000000},
  {fuseki19560,4,"Fuseki565", 6,-7,3.000000},
  {fuseki19561,2,"Fuseki566", 5, 7,12.000000},
  {fuseki19562,2,"Fuseki567", 5, 6,8.000000},
  {fuseki19563,2,"Fuseki568", 7, 6,3.000000},
  {fuseki19564,2,"Fuseki569", 7,-4,3.000000},
  {fuseki19565,2,"Fuseki570", 5, 7,2.000000},
  {fuseki19566,6,"Fuseki571", 7,-7,14.000000},
  {fuseki19567,6,"Fuseki572", 4,-5,13.000000},
  {fuseki19568,6,"Fuseki573", 4,-7,6.000000},
  {fuseki19569,4,"Fuseki574",-6, 0,9.000000},
  {fuseki19570,4,"Fuseki575", 5,-6,8.000000},
  {fuseki19571,4,"Fuseki576", 6,-7,5.000000},
  {fuseki19572,4,"Fuseki577", 5,-6,3.000000},
  {fuseki19573,4,"Fuseki578", 0, 6,2.000000},
  {fuseki19574,4,"Fuseki579", 5, 7,2.000000},
  {fuseki19575,7,"Fuseki580",-4, 7,15.000000},
  {fuseki19576,7,"Fuseki581", 7, 0,9.000000},
  {fuseki19577,7,"Fuseki582",-7, 4,4.000000},
  {fuseki19578,7,"Fuseki583",-7,-4,2.000000},
  {fuseki19579,4,"Fuseki584",-5,-7,13.000000},
  {fuseki19580,4,"Fuseki586", 7,-4,4.000000},
  {fuseki19581,4,"Fuseki587",-7, 4,3.000000},
  {fuseki19582,4,"Fuseki588", 0, 0,2.000000},
  {fuseki19583,5,"Fuseki589",-7, 4,23.000000},
  {fuseki19584,5,"Fuseki590", 0,-6,3.000000},
  {fuseki19585,3,"Fuseki591",-6,-6,20.000000},
  {fuseki19586,3,"Fuseki592", 7, 6,6.000000},
  {fuseki19587,3,"Fuseki593",-5, 6,2.000000},
  {fuseki19588,8,"Fuseki594",-4,-5,30.000000},
  {fuseki19589,4,"Fuseki595",-5, 7,13.000000},
  {fuseki19590,4,"Fuseki596", 6,-5,7.000000},
  {fuseki19591,4,"Fuseki597",-7, 4,4.000000},
  {fuseki19592,4,"Fuseki598",-4,-7,2.000000},
  {fuseki19593,4,"Fuseki599",-6, 5,2.000000},
  {fuseki19594,6,"Fuseki600", 5, 6,17.000000},
  {fuseki19595,6,"Fuseki601", 6, 0,4.000000},
  {fuseki19596,6,"Fuseki602", 6, 5,4.000000},
  {fuseki19597,3,"Fuseki603",-6,-5,16.000000},
  {fuseki19598,3,"Fuseki604",-5,-6,6.000000},
  {fuseki19599,3,"Fuseki605", 6,-6,2.000000},
  {fuseki19600,3,"Fuseki606",-7,-6,2.000000},
  {fuseki19601,3,"Fuseki607", 7,-5,2.000000},
  {fuseki19602,6,"Fuseki608",-4, 6,12.000000},
  {fuseki19603,6,"Fuseki609",-7, 2,6.000000},
  {fuseki19604,6,"Fuseki610",-7, 1,6.000000},
  {fuseki19605,6,"Fuseki611", 0,-6,3.000000},
  {fuseki19606,6,"Fuseki612",-2, 6,2.000000},
  {fuseki19607,9,"Fuseki613",-5,-4,29.000000},
  {fuseki19608,6,"Fuseki614", 0,-6,16.000000},
  {fuseki19609,6,"Fuseki615", 4,-7,11.000000},
  {fuseki19610,8,"Fuseki617", 4,-5,3.000000},
  {fuseki19611,6,"Fuseki618", 7,-7,20.000000},
  {fuseki19612,6,"Fuseki619",-2,-6,3.000000},
  {fuseki19613,6,"Fuseki620",-6,-2,2.000000},
  {fuseki19614,6,"Fuseki621", 2, 7,2.000000},
  {fuseki19615,6,"Fuseki622",-6, 0,22.000000},
  {fuseki19616,6,"Fuseki623", 8,-6,4.000000},
  {fuseki19617,6,"Fuseki624",-5,-4,3.000000},
  {fuseki19618,4,"Fuseki625", 5,-6,10.000000},
  {fuseki19619,4,"Fuseki626",-5,-7,5.000000},
  {fuseki19620,4,"Fuseki627",-1, 6,3.000000},
  {fuseki19621,4,"Fuseki628", 7,-5,2.000000},
  {fuseki19622,4,"Fuseki629",-6,-3,2.000000},
  {fuseki19623,4,"Fuseki630", 1, 7,2.000000},
  {fuseki19624,2,"Fuseki631", 6, 6,11.000000},
  {fuseki19625,2,"Fuseki632", 6,-6,6.000000},
  {fuseki19626,2,"Fuseki633", 7, 6,5.000000},
  {fuseki19627,2,"Fuseki634",-6,-6,7.000000},
  {fuseki19628,2,"Fuseki635", 7, 6,6.000000},
  {fuseki19629,2,"Fuseki636", 6,-6,5.000000},
  {fuseki19630,2,"Fuseki637", 6, 7,4.000000},
  {fuseki19631,2,"Fuseki638", 6, 7,3.000000},
  {fuseki19632,2,"Fuseki639",-5,-7,2.000000},
  {fuseki19633,7,"Fuseki640", 3, 6,29.000000},
  {fuseki19634,8,"Fuseki641",-7,-6,26.000000},
  {fuseki19635,8,"Fuseki642",-7, 6,3.000000},
  {fuseki19636,2,"Fuseki643",-5,-6,10.000000},
  {fuseki19637,2,"Fuseki644",-6,-5,5.000000},
  {fuseki19638,2,"Fuseki645",-6,-7,3.000000},
  {fuseki19639,2,"Fuseki646", 5, 7,3.000000},
  {fuseki19640,2,"Fuseki647", 6,-6,2.000000},
  {fuseki19641,7,"Fuseki648", 6, 3,28.000000},
  {fuseki19642,3,"Fuseki650", 7, 6,9.000000},
  {fuseki19643,3,"Fuseki651",-6,-6,9.000000},
  {fuseki19644,3,"Fuseki652", 7,-5,4.000000},
  {fuseki19645,3,"Fuseki653",-6,-5,2.000000},
  {fuseki19646,3,"Fuseki654",-6,-5,2.000000},
  {fuseki19647,5,"Fuseki655", 7,-4,17.000000},
  {fuseki19648,5,"Fuseki656",-2, 7,2.000000},
  {fuseki19649,5,"Fuseki657",-6, 4,2.000000},
  {fuseki19650,5,"Fuseki658",-4, 6,2.000000},
  {fuseki19651,3,"Fuseki659", 7, 6,9.000000},
  {fuseki19652,3,"Fuseki660",-6,-6,9.000000},
  {fuseki19653,3,"Fuseki661", 6, 7,3.000000},
  {fuseki19654,3,"Fuseki662",-5,-7,3.000000},
  {fuseki19655,3,"Fuseki663", 7, 7,2.000000},
  {fuseki19656,7,"Fuseki664",-4,-6,17.000000},
  {fuseki19657,7,"Fuseki665", 4,-7,10.000000},
  {fuseki19658,2,"Fuseki666",-6,-6,6.000000},
  {fuseki19659,2,"Fuseki667",-2, 7,3.000000},
  {fuseki19660,2,"Fuseki668", 6, 6,3.000000},
  {fuseki19661,2,"Fuseki669",-6, 4,3.000000},
  {fuseki19662,2,"Fuseki670",-4, 7,3.000000},
  {fuseki19663,2,"Fuseki672", 6, 4,2.000000},
  {fuseki19664,3,"Fuseki673", 6, 6,7.000000},
  {fuseki19665,3,"Fuseki674",-7,-6,4.000000},
  {fuseki19666,3,"Fuseki675", 7, 6,3.000000},
  {fuseki19667,3,"Fuseki676", 7, 5,3.000000},
  {fuseki19668,3,"Fuseki677", 7,-5,2.000000},
  {fuseki19669,3,"Fuseki678", 6, 5,2.000000},
  {fuseki19670,3,"Fuseki680",-5,-6,2.000000},
  {fuseki19671,3,"Fuseki681",-6, 7,14.000000},
  {fuseki19672,3,"Fuseki682", 6, 6,6.000000},
  {fuseki19673,3,"Fuseki683",-6,-5,4.000000},
  {fuseki19674,6,"Fuseki684",-6,-3,17.000000},
  {fuseki19675,6,"Fuseki685", 5, 7,4.000000},
  {fuseki19676,6,"Fuseki686", 4, 5,2.000000},
  {fuseki19677,6,"Fuseki687", 5, 6,15.000000},
  {fuseki19678,6,"Fuseki688", 6, 5,3.000000},
  {fuseki19679,6,"Fuseki689", 6, 0,3.000000},
  {fuseki19680,3,"Fuseki690", 6, 6,13.000000},
  {fuseki19681,3,"Fuseki691", 7, 6,5.000000},
  {fuseki19682,3,"Fuseki692", 6, 7,3.000000},
  {fuseki19683,3,"Fuseki693", 7,-5,2.000000},
  {fuseki19684,3,"Fuseki694",-5, 6,2.000000},
  {fuseki19685,7,"Fuseki695", 6, 0,18.000000},
  {fuseki19686,7,"Fuseki696", 8, 6,7.000000},
  {fuseki19687,5,"Fuseki697", 7, 4,7.000000},
  {fuseki19688,5,"Fuseki698", 0, 6,5.000000},
  {fuseki19689,5,"Fuseki699", 0,-7,4.000000},
  {fuseki19690,5,"Fuseki700",-2, 0,3.000000},
  {fuseki19691,5,"Fuseki701", 0, 6,2.000000},
  {fuseki19692,5,"Fuseki702", 0,-6,2.000000},
  {fuseki19693,7,"Fuseki703",-4, 7,18.000000},
  {fuseki19694,7,"Fuseki704",-3, 7,8.000000},
  {fuseki19695,9,"Fuseki705",-6,-7,26.000000},
  {fuseki19696,3,"Fuseki706", 7,-6,7.000000},
  {fuseki19697,3,"Fuseki707", 7,-5,5.000000},
  {fuseki19698,3,"Fuseki708", 6,-6,5.000000},
  {fuseki19699,3,"Fuseki709",-4,-6,3.000000},
  {fuseki19700,3,"Fuseki710", 5,-6,2.000000},
  {fuseki19701,3,"Fuseki711", 7,-5,2.000000},
  {fuseki19702,3,"Fuseki712", 5, 6,2.000000},
  {fuseki19703,9,"Fuseki713", 5, 6,16.000000},
  {fuseki19704,9,"Fuseki715", 7, 6,2.000000},
  {fuseki19705,9,"Fuseki716",-6,-2,2.000000},
  {fuseki19706,4,"Fuseki717", 0, 6,12.000000},
  {fuseki19707,4,"Fuseki718",-5,-6,7.000000},
  {fuseki19708,4,"Fuseki719",-6,-6,2.000000},
  {fuseki19709,6,"Fuseki720", 4,-7,8.000000},
  {fuseki19710,6,"Fuseki721", 7, 7,7.000000},
  {fuseki19711,6,"Fuseki722", 8,-6,4.000000},
  {fuseki19712,6,"Fuseki723", 4, 5,2.000000},
  {fuseki19713,6,"Fuseki724", 6, 4,2.000000},
  {fuseki19714,9,"Fuseki725",-5, 6,16.000000},
  {fuseki19715,9,"Fuseki726", 5, 2,5.000000},
  {fuseki19716,9,"Fuseki727", 3,-7,2.000000},
  {fuseki19717,9,"Fuseki728",-2, 6,2.000000},
  {fuseki19718,4,"Fuseki729", 7,-6,20.000000},
  {fuseki19719,4,"Fuseki730", 6,-6,3.000000},
  {fuseki19720,9,"Fuseki731",-7,-4,22.000000},
  {fuseki19721,2,"Fuseki732", 5, 7,8.000000},
  {fuseki19722,2,"Fuseki733", 5, 6,6.000000},
  {fuseki19723,2,"Fuseki734",-5,-6,3.000000},
  {fuseki19724,2,"Fuseki735", 7,-6,2.000000},
  {fuseki19725,5,"Fuseki736", 6,-2,7.000000},
  {fuseki19726,5,"Fuseki737", 5,-7,5.000000},
  {fuseki19727,5,"Fuseki738", 5, 7,4.000000},
  {fuseki19728,5,"Fuseki739", 6,-4,3.000000},
  {fuseki19729,5,"Fuseki740", 7,-3,3.000000},
  {fuseki19730,6,"Fuseki741",-4,-5,12.000000},
  {fuseki19731,6,"Fuseki742", 7, 7,10.000000},
  {fuseki19732,7,"Fuseki743", 7, 7,8.000000},
  {fuseki19733,7,"Fuseki744",-7, 3,5.000000},
  {fuseki19734,7,"Fuseki745", 7, 4,5.000000},
  {fuseki19735,7,"Fuseki746",-7,-2,2.000000},
  {fuseki19736,7,"Fuseki747",-7, 4,2.000000},
  {fuseki19737,4,"Fuseki748", 6,-5,13.000000},
  {fuseki19738,4,"Fuseki749", 5,-7,5.000000},
  {fuseki19739,4,"Fuseki750", 1, 7,3.000000},
  {fuseki19740,5,"Fuseki751", 6,-1,13.000000},
  {fuseki19741,5,"Fuseki752", 4,-7,3.000000},
  {fuseki19742,5,"Fuseki753", 6, 0,2.000000},
  {fuseki19743,5,"Fuseki754",-4, 7,10.000000},
  {fuseki19744,5,"Fuseki755", 7, 4,6.000000},
  {fuseki19745,5,"Fuseki756", 6,-7,4.000000},
  {fuseki19746,5,"Fuseki757", 1, 7,3.000000},
  {fuseki19747,4,"Fuseki758", 7,-4,13.000000},
  {fuseki19748,4,"Fuseki759", 7, 4,4.000000},
  {fuseki19749,6,"Fuseki760",-7, 2,6.000000},
  {fuseki19750,6,"Fuseki761",-4, 6,5.000000},
  {fuseki19751,6,"Fuseki762",-6,-4,5.000000},
  {fuseki19752,6,"Fuseki763", 0, 6,2.000000},
  {fuseki19753,6,"Fuseki764",-4, 6,16.000000},
  {fuseki19754,6,"Fuseki765", 2,-7,5.000000},
  {fuseki19755,5,"Fuseki766",-4,-6,6.000000},
  {fuseki19756,5,"Fuseki767",-7, 0,5.000000},
  {fuseki19757,5,"Fuseki768",-4,-7,4.000000},
  {fuseki19758,5,"Fuseki769", 5,-6,2.000000},
  {fuseki19759,5,"Fuseki770",-7, 4,2.000000},
  {fuseki19760,5,"Fuseki771",-2, 6,7.000000},
  {fuseki19761,5,"Fuseki772",-5,-7,4.000000},
  {fuseki19762,5,"Fuseki773", 3,-7,3.000000},
  {fuseki19763,5,"Fuseki774",-4,-7,2.000000},
  {fuseki19764,5,"Fuseki775",-5, 5,2.000000},
  {fuseki19765,3,"Fuseki776",-6,-6,8.000000},
  {fuseki19766,3,"Fuseki777", 6,-6,7.000000},
  {fuseki19767,3,"Fuseki778",-6, 0,3.000000},
  {fuseki19768,3,"Fuseki779",-6, 6,3.000000},
  {fuseki19769,6,"Fuseki780", 4,-7,7.000000},
  {fuseki19770,6,"Fuseki781",-7, 7,6.000000},
  {fuseki19771,6,"Fuseki782", 5,-4,5.000000},
  {fuseki19772,6,"Fuseki783",-2, 6,2.000000},
  {fuseki19773,6,"Fuseki784", 4,-7,8.000000},
  {fuseki19774,6,"Fuseki785", 7,-4,5.000000},
  {fuseki19775,6,"Fuseki786",-7,-4,5.000000},
  {fuseki19776,4,"Fuseki787", 7, 5,8.000000},
  {fuseki19777,4,"Fuseki788", 6,-6,4.000000},
  {fuseki19778,4,"Fuseki789", 2, 6,3.000000},
  {fuseki19779,4,"Fuseki790", 6,-7,2.000000},
  {fuseki19780,4,"Fuseki791",-7,-3,2.000000},
  {fuseki19781,4,"Fuseki792", 6, 4,2.000000},
  {fuseki19782,3,"Fuseki793", 6, 6,5.000000},
  {fuseki19783,3,"Fuseki794", 4,-6,4.000000},
  {fuseki19784,3,"Fuseki795", 6,-4,3.000000},
  {fuseki19785,3,"Fuseki796", 6,-1,2.000000},
  {fuseki19786,3,"Fuseki797", 7, 5,2.000000},
  {fuseki19787,3,"Fuseki798", 4,-7,2.000000},
  {fuseki19788,3,"Fuseki799", 7,-2,2.000000},
  {fuseki19789,5,"Fuseki800", 5, 6,13.000000},
  {fuseki19790,5,"Fuseki801", 0, 7,3.000000},
  {fuseki19791,5,"Fuseki802", 4, 7,2.000000},
  {fuseki19792,7,"Fuseki803",-4, 7,10.000000},
  {fuseki19793,7,"Fuseki804", 4,-7,7.000000},
  {fuseki19794,3,"Fuseki805",-6,-6,13.000000},
  {fuseki19795,3,"Fuseki806", 7,-6,4.000000},
  {fuseki19796,9,"Fuseki807", 4, 7,13.000000},
  {fuseki19797,9,"Fuseki808", 4,-7,5.000000},
  {fuseki19798,9,"Fuseki809",-4, 7,2.000000},
  {fuseki19799,8,"Fuseki810", 7,-1,21.000000},
  {fuseki19800,4,"Fuseki811",-5, 7,9.000000},
  {fuseki19801,4,"Fuseki812", 4, 7,8.000000},
  {fuseki19802,4,"Fuseki813", 4, 7,2.000000},
  {fuseki19803,7,"Fuseki814",-4, 7,14.000000},
  {fuseki19804,7,"Fuseki815", 6, 6,6.000000},
  {fuseki19805,3,"Fuseki816", 6,-2,7.000000},
  {fuseki19806,3,"Fuseki817", 6, 7,4.000000},
  {fuseki19807,3,"Fuseki818", 5, 5,2.000000},
  {fuseki19808,3,"Fuseki819",-6,-6,2.000000},
  {fuseki19809,2,"Fuseki820", 6,-7,10.000000},
  {fuseki19810,2,"Fuseki821", 6, 6,3.000000},
  {fuseki19811,2,"Fuseki822", 6, 7,3.000000},
  {fuseki19812,2,"Fuseki823",-7,-6,2.000000},
  {fuseki19813,8,"Fuseki824", 6,-7,20.000000},
  {fuseki19814,9,"Fuseki825", 8,-5,17.000000},
  {fuseki19815,9,"Fuseki826",-8,-8,2.000000},
  {fuseki19816,5,"Fuseki827",-6,-5,12.000000},
  {fuseki19817,5,"Fuseki828", 4, 6,2.000000},
  {fuseki19818,5,"Fuseki829", 5, 7,2.000000},
  {fuseki19819,5,"Fuseki830",-4, 6,2.000000},
  {fuseki19820,7,"Fuseki831", 8,-7,20.000000},
  {fuseki19821,7,"Fuseki832", 4,-7,7.000000},
  {fuseki19822,7,"Fuseki833", 7, 4,5.000000},
  {fuseki19823,7,"Fuseki834", 7, 0,3.000000},
  {fuseki19824,7,"Fuseki835",-6, 8,2.000000},
  {fuseki19825,3,"Fuseki836", 6,-6,11.000000},
  {fuseki19826,3,"Fuseki837",-7,-6,8.000000},
  {fuseki19827,6,"Fuseki838",-5,-4,9.000000},
  {fuseki19828,6,"Fuseki839", 7,-7,6.000000},
  {fuseki19829,6,"Fuseki840", 4,-7,4.000000},
  {fuseki19830,4,"Fuseki841", 6,-6,7.000000},
  {fuseki19831,4,"Fuseki842",-5,-7,4.000000},
  {fuseki19832,4,"Fuseki844", 6, 0,2.000000},
  {fuseki19833,4,"Fuseki845", 7,-4,12.000000},
  {fuseki19834,4,"Fuseki846",-1,-7,3.000000},
  {fuseki19835,4,"Fuseki847",-6,-7,2.000000},
  {fuseki19836,4,"Fuseki848",-5,-6,9.000000},
  {fuseki19837,4,"Fuseki849",-5,-7,9.000000},
  {fuseki19838,5,"Fuseki850", 7,-4,10.000000},
  {fuseki19839,5,"Fuseki851", 4,-6,6.000000},
  {fuseki19840,3,"Fuseki852", 6,-6,14.000000},
  {fuseki19841,3,"Fuseki853", 5, 7,2.000000},
  {fuseki19842,3,"Fuseki854",-6,-7,2.000000},
  {fuseki19843,7,"Fuseki855", 7, 7,12.000000},
  {fuseki19844,7,"Fuseki856", 4, 7,4.000000},
  {fuseki19845,7,"Fuseki857", 5, 4,2.000000},
  {fuseki19846,6,"Fuseki858", 6,-8,14.000000},
  {fuseki19847,6,"Fuseki859",-4,-7,2.000000},
  {fuseki19848,6,"Fuseki860", 6,-1,2.000000},
  {fuseki19849,4,"Fuseki861",-7,-5,10.000000},
  {fuseki19850,4,"Fuseki862",-4, 7,8.000000},
  {fuseki19851,7,"Fuseki863",-7,-4,14.000000},
  {fuseki19852,7,"Fuseki864",-7,-3,4.000000},
  {fuseki19853,6,"Fuseki865",-4,-6,11.000000},
  {fuseki19854,6,"Fuseki866",-4,-5,3.000000},
  {fuseki19855,6,"Fuseki867",-5,-5,2.000000},
  {fuseki19856,6,"Fuseki868", 6, 0,8.000000},
  {fuseki19857,6,"Fuseki869", 6,-1,5.000000},
  {fuseki19858,6,"Fuseki870", 1, 7,2.000000},
  {fuseki19859,8,"Fuseki871", 5, 6,10.000000},
  {fuseki19860,8,"Fuseki872", 6, 7,6.000000},
  {fuseki19861,4,"Fuseki873", 0, 6,7.000000},
  {fuseki19862,4,"Fuseki874",-5,-6,3.000000},
  {fuseki19863,4,"Fuseki875", 6,-5,2.000000},
  {fuseki19864,4,"Fuseki876", 7,-6,2.000000},
  {fuseki19865,5,"Fuseki877", 7, 4,6.000000},
  {fuseki19866,5,"Fuseki878",-4, 7,6.000000},
  {fuseki19867,5,"Fuseki879",-7, 5,2.000000},
  {fuseki19868,5,"Fuseki880", 0, 6,2.000000},
  {fuseki19869,3,"Fuseki881", 0, 6,5.000000},
  {fuseki19870,3,"Fuseki882", 0,-7,3.000000},
  {fuseki19871,3,"Fuseki883", 0,-6,2.000000},
  {fuseki19872,3,"Fuseki884", 7,-5,2.000000},
  {fuseki19873,3,"Fuseki885", 6,-5,2.000000},
  {fuseki19874,3,"Fuseki886",-6, 0,2.000000},
  {fuseki19875,6,"Fuseki887",-4, 6,8.000000},
  {fuseki19876,6,"Fuseki888",-7, 2,5.000000},
  {fuseki19877,6,"Fuseki889",-6, 1,2.000000},
  {fuseki19878,8,"Fuseki890",-6, 0,10.000000},
  {fuseki19879,8,"Fuseki891", 0,-7,3.000000},
  {fuseki19880,8,"Fuseki892", 4, 7,2.000000},
  {fuseki19881,7,"Fuseki893", 7,-6,15.000000},
  {fuseki19882,7,"Fuseki894", 7,-6,3.000000},
  {fuseki19883,8,"Fuseki895",-2, 7,9.000000},
  {fuseki19884,8,"Fuseki896",-6, 4,5.000000},
  {fuseki19885,8,"Fuseki897", 4,-7,3.000000},
  {fuseki19886,7,"Fuseki898",-8, 6,7.000000},
  {fuseki19887,7,"Fuseki899", 0, 6,7.000000},
  {fuseki19888,7,"Fuseki900",-6, 1,2.000000},
  {fuseki19889,4,"Fuseki901",-6,-6,5.000000},
  {fuseki19890,4,"Fuseki902",-6,-7,4.000000},
  {fuseki19891,4,"Fuseki903", 5, 6,2.000000},
  {fuseki19892,4,"Fuseki904", 7, 3,2.000000},
  {fuseki19893,7,"Fuseki905", 6, 0,17.000000},
  {fuseki19894,4,"Fuseki906", 7,-4,9.000000},
  {fuseki19895,4,"Fuseki907", 4, 7,3.000000},
  {fuseki19896,7,"Fuseki908",-6, 0,14.000000},
  {fuseki19897,7,"Fuseki909",-6, 1,3.000000},
  {fuseki19898,7,"Fuseki910", 0, 6,10.000000},
  {fuseki19899,7,"Fuseki911",-4,-7,5.000000},
  {fuseki19900,8,"Fuseki912",-7,-4,9.000000},
  {fuseki19901,8,"Fuseki913",-6, 0,6.000000},
  {fuseki19902,7,"Fuseki914",-5,-5,16.000000},
  {fuseki19903,8,"Fuseki915", 4, 6,15.000000},
  {fuseki19904,6,"Fuseki916",-3, 7,8.000000},
  {fuseki19905,6,"Fuseki917", 4,-7,7.000000},
  {fuseki19906,6,"Fuseki918",-2, 7,2.000000},
  {fuseki19907,6,"Fuseki919",-8, 6,12.000000},
  {fuseki19908,6,"Fuseki920", 4, 7,2.000000},
  {fuseki19909,3,"Fuseki921",-6, 7,5.000000},
  {fuseki19910,3,"Fuseki922",-6,-6,4.000000},
  {fuseki19911,3,"Fuseki923", 5,-6,2.000000},
  {fuseki19912,3,"Fuseki924",-7,-7,2.000000},
  {fuseki19913,8,"Fuseki925",-1,-6,10.000000},
  {fuseki19914,8,"Fuseki926",-3,-4,4.000000},
  {fuseki19915,8,"Fuseki927", 6, 8,2.000000},
  {fuseki19916,6,"Fuseki928", 6,-8,15.000000},
  {fuseki19917,5,"Fuseki929", 6, 0,6.000000},
  {fuseki19918,5,"Fuseki930", 4,-7,3.000000},
  {fuseki19919,5,"Fuseki931", 4,-6,3.000000},
  {fuseki19920,8,"Fuseki932",-4,-5,16.000000},
  {fuseki19921,7,"Fuseki933",-6, 0,12.000000},
  {fuseki19922,7,"Fuseki934", 8,-6,4.000000},
  {fuseki19923,9,"Fuseki935",-5,-4,16.000000},
  {fuseki19924,4,"Fuseki936",-6, 0,5.000000},
  {fuseki19925,4,"Fuseki937", 7, 0,3.000000},
  {fuseki19926,4,"Fuseki938",-6,-7,3.000000},
  {fuseki19927,8,"Fuseki939",-6, 1,15.000000},
  {fuseki19928,5,"Fuseki940", 2, 6,7.000000},
  {fuseki19929,5,"Fuseki941", 5, 5,3.000000},
  {fuseki19930,5,"Fuseki942",-5,-7,2.000000},
  {fuseki19931,5,"Fuseki943", 7, 3,2.000000},
  {fuseki19932,5,"Fuseki944", 6, 4,5.000000},
  {fuseki19933,5,"Fuseki945", 7,-2,4.000000},
  {fuseki19934,5,"Fuseki946",-7,-4,3.000000},
  {fuseki19935,5,"Fuseki947", 6, 0,2.000000},
  {fuseki19936,5,"Fuseki948",-1,-6,2.000000},
  {fuseki19937,7,"Fuseki949", 4, 7,9.000000},
  {fuseki19938,7,"Fuseki950", 0, 7,4.000000},
  {fuseki19939,9,"Fuseki951", 5,-6,15.000000},
  {fuseki19940,5,"Fuseki952", 4, 6,7.000000},
  {fuseki19941,5,"Fuseki953",-4,-7,5.000000},
  {fuseki19942,5,"Fuseki954", 5, 7,2.000000},
  {fuseki19943,6,"Fuseki955", 6, 0,12.000000},
  {fuseki19944,6,"Fuseki956", 6,-8,2.000000},
  {fuseki19945,3,"Fuseki957", 6, 6,10.000000},
  {fuseki19946,3,"Fuseki958",-7,-6,2.000000},
  {fuseki19947,7,"Fuseki959", 7,-7,13.000000},
  {fuseki19948,6,"Fuseki960",-7,-7,7.000000},
  {fuseki19949,6,"Fuseki961",-4,-5,4.000000},
  {fuseki19950,6,"Fuseki962", 4,-7,2.000000},
  {fuseki19951,5,"Fuseki963", 4,-7,6.000000},
  {fuseki19952,5,"Fuseki964", 6,-1,3.000000},
  {fuseki19953,5,"Fuseki965", 7,-2,2.000000},
  {fuseki19954,5,"Fuseki966", 6,-4,2.000000},
  {fuseki19955,4,"Fuseki967",-6,-5,7.000000},
  {fuseki19956,4,"Fuseki968",-7,-1,3.000000},
  {fuseki19957,4,"Fuseki969",-5, 7,2.000000},
  {fuseki19958,8,"Fuseki970",-6,-2,11.000000},
  {fuseki19959,8,"Fuseki971",-5, 5,2.000000},
  {fuseki19960,7,"Fuseki972", 6, 0,14.000000},
  {fuseki19961,6,"Fuseki973", 3,-6,6.000000},
  {fuseki19962,6,"Fuseki974", 4,-5,6.000000},
  {fuseki19963,6,"Fuseki975", 5,-7,2.000000},
  {fuseki19964,4,"Fuseki976",-5,-7,10.000000},
  {fuseki19965,4,"Fuseki977", 6,-5,2.000000},
  {fuseki19966,3,"Fuseki978",-6,-6,7.000000},
  {fuseki19967,3,"Fuseki979",-6,-6,6.000000},
  {fuseki19968,3,"Fuseki980", 6, 7,2.000000},
  {fuseki19969,7,"Fuseki981",-8,-5,6.000000},
  {fuseki19970,7,"Fuseki982",-6,-6,5.000000},
  {fuseki19971,7,"Fuseki983", 5,-6,4.000000},
  {fuseki19972,9,"Fuseki984",-5, 2,15.000000},
  {fuseki19973,2,"Fuseki985", 7, 6,4.000000},
  {fuseki19974,9,"Fuseki989", 6, 1,14.000000},
  {fuseki19975,8,"Fuseki990",-2, 7,5.000000},
  {fuseki19976,8,"Fuseki991", 1, 6,4.000000},
  {fuseki19977,8,"Fuseki992", 6, 4,3.000000},
  {fuseki19978,5,"Fuseki993", 7, 1,5.000000},
  {fuseki19979,5,"Fuseki994", 5, 6,3.000000},
  {fuseki19980,5,"Fuseki995",-2,-6,3.000000},
  {fuseki19981,5,"Fuseki996",-7,-3,2.000000},
  {fuseki19982,8,"Fuseki997", 6,-7,15.000000},
  {fuseki19983,7,"Fuseki998", 4,-6,13.000000},
  {fuseki19984,7,"Fuseki999",-7,-4,6.000000},
  {fuseki19985,7,"Fuseki1000", 5, 4,5.000000},
  {fuseki19986,2,"Fuseki1001", 6, 6,2005.000000},
  {fuseki19987,2,"Fuseki1002",-7,-6,1366.000000},
  {fuseki19988,2,"Fuseki1003", 6, 5,536.000000},
  {fuseki19989,2,"Fuseki1004", 5, 7,263.000000},
  {fuseki19990,2,"Fuseki1005", 0, 0,86.000000},
  {fuseki19991,2,"Fuseki1006", 4,-7,31.000000},
  {fuseki19992,2,"Fuseki1007", 7, 7,27.000000},
  {fuseki19993,2,"Fuseki1010", 6,-4,10.000000},
  {fuseki19994,3,"Fuseki1011", 6, 6,996.000000},
  {fuseki19995,3,"Fuseki1012", 6, 7,713.000000},
  {fuseki19996,3,"Fuseki1013", 5, 6,410.000000},
  {fuseki19997,3,"Fuseki1014", 5, 7,258.000000},
  {fuseki19998,3,"Fuseki1015", 0, 0,45.000000},
  {fuseki19999,3,"Fuseki1017", 7,-4,17.000000},
  {fuseki191000,3,"Fuseki1019", 7, 7,15.000000},
  {fuseki191001,3,"Fuseki1020", 4,-7,14.000000},
  {fuseki191002,3,"Fuseki1021",-4,-7,13.000000},
  {fuseki191003,3,"Fuseki1022",-6,-6,1088.000000},
  {fuseki191004,3,"Fuseki1023",-6,-7,571.000000},
  {fuseki191005,3,"Fuseki1024", 7, 4,82.000000},
  {fuseki191006,3,"Fuseki1025",-5,-7,67.000000},
  {fuseki191007,3,"Fuseki1026", 6, 5,56.000000},
  {fuseki191008,3,"Fuseki1027", 0, 0,56.000000},
  {fuseki191009,3,"Fuseki1028", 7, 7,51.000000},
  {fuseki191010,4,"Fuseki1029", 7,-4,1365.000000},
  {fuseki191011,4,"Fuseki1030", 0, 7,54.000000},
  {fuseki191012,4,"Fuseki1031", 0, 0,49.000000},
  {fuseki191013,4,"Fuseki1032",-3, 6,47.000000},
  {fuseki191014,4,"Fuseki1033",-3, 7,34.000000},
  {fuseki191015,4,"Fuseki1034", 6,-4,29.000000},
  {fuseki191016,4,"Fuseki1035", 0, 6,17.000000},
  {fuseki191017,3,"Fuseki1037",-6,-6,620.000000},
  {fuseki191018,3,"Fuseki1038",-5,-6,196.000000},
  {fuseki191019,3,"Fuseki1039", 7, 6,180.000000},
  {fuseki191020,3,"Fuseki1040",-6,-7,180.000000},
  {fuseki191021,3,"Fuseki1041", 7, 5,52.000000},
  {fuseki191022,3,"Fuseki1042", 7, 7,27.000000},
  {fuseki191023,3,"Fuseki1043", 0, 0,26.000000},
  {fuseki191024,3,"Fuseki1044",-5,-7,17.000000},
  {fuseki191025,3,"Fuseki1045",-6,-5,16.000000},
  {fuseki191026,3,"Fuseki1046",-7,-5,13.000000},
  {fuseki191027,3,"Fuseki1047", 4, 7,10.000000},
  {fuseki191028,5,"Fuseki1048", 4,-6,470.000000},
  {fuseki191029,5,"Fuseki1049",-7, 4,260.000000},
  {fuseki191030,5,"Fuseki1050",-2, 7,202.000000},
  {fuseki191031,5,"Fuseki1051", 0, 6,83.000000},
  {fuseki191032,5,"Fuseki1052",-1, 6,76.000000},
  {fuseki191033,5,"Fuseki1053",-4,-6,67.000000},
  {fuseki191034,5,"Fuseki1054",-7, 3,37.000000},
  {fuseki191035,5,"Fuseki1055", 7, 0,37.000000},
  {fuseki191036,5,"Fuseki1056",-5, 7,33.000000},
  {fuseki191037,5,"Fuseki1057", 0, 6,17.000000},
  {fuseki191038,5,"Fuseki1058",-6, 0,12.000000},
  {fuseki191039,5,"Fuseki1059", 0, 0,12.000000},
  {fuseki191040,5,"Fuseki1060", 6, 0,10.000000},
  {fuseki191041,4,"Fuseki1061",-4, 7,600.000000},
  {fuseki191042,4,"Fuseki1062",-7,-4,300.000000},
  {fuseki191043,4,"Fuseki1063", 4,-7,87.000000},
  {fuseki191044,4,"Fuseki1064",-7, 0,25.000000},
  {fuseki191045,4,"Fuseki1065",-6, 4,19.000000},
  {fuseki191046,4,"Fuseki1067", 4, 7,604.000000},
  {fuseki191047,4,"Fuseki1068", 0,-6,175.000000},
  {fuseki191048,4,"Fuseki1069", 0, 0,53.000000},
  {fuseki191049,4,"Fuseki1070", 0, 6,42.000000},
  {fuseki191050,4,"Fuseki1071", 7, 0,24.000000},
  {fuseki191051,4,"Fuseki1072", 6, 4,22.000000},
  {fuseki191052,4,"Fuseki1073",-7, 0,19.000000},
  {fuseki191053,4,"Fuseki1074", 7,-4,11.000000},
  {fuseki191054,4,"Fuseki1075", 7, 3,10.000000},
  {fuseki191055,5,"Fuseki1076",-7,-4,670.000000},
  {fuseki191056,5,"Fuseki1077",-7, 0,22.000000},
  {fuseki191057,5,"Fuseki1078", 6, 3,19.000000},
  {fuseki191058,5,"Fuseki1079",-7, 3,14.000000},
  {fuseki191059,5,"Fuseki1080", 0, 6,14.000000},
  {fuseki191060,5,"Fuseki1081", 6,-4,12.000000},
  {fuseki191061,4,"Fuseki1082", 6, 5,382.000000},
  {fuseki191062,4,"Fuseki1083", 7, 5,144.000000},
  {fuseki191063,4,"Fuseki1084", 0,-6,41.000000},
  {fuseki191064,4,"Fuseki1085", 4, 7,38.000000},
  {fuseki191065,4,"Fuseki1086", 0,-6,30.000000},
  {fuseki191066,4,"Fuseki1087", 4, 6,20.000000},
  {fuseki191067,4,"Fuseki1088", 0, 0,13.000000},
  {fuseki191068,6,"Fuseki1089",-4,-6,246.000000},
  {fuseki191069,6,"Fuseki1090",-7, 4,118.000000},
  {fuseki191070,6,"Fuseki1091",-7,-2,80.000000},
  {fuseki191071,6,"Fuseki1092", 0, 6,51.000000},
  {fuseki191072,6,"Fuseki1093", 6, 4,42.000000},
  {fuseki191073,6,"Fuseki1094",-1, 6,41.000000},
  {fuseki191074,6,"Fuseki1096",-7, 0,20.000000},
  {fuseki191075,6,"Fuseki1097",-7, 1,10.000000},
  {fuseki191076,4,"Fuseki1098",-4, 7,334.000000},
  {fuseki191077,4,"Fuseki1099",-4,-7,76.000000},
  {fuseki191078,4,"Fuseki1100", 7,-4,64.000000},
  {fuseki191079,4,"Fuseki1101",-4,-7,57.000000},
  {fuseki191080,4,"Fuseki1102", 5, 7,26.000000},
  {fuseki191081,4,"Fuseki1103", 4, 7,15.000000},
  {fuseki191082,4,"Fuseki1104", 4,-7,12.000000},
  {fuseki191083,5,"Fuseki1105", 7, 2,132.000000},
  {fuseki191084,5,"Fuseki1106", 6, 4,70.000000},
  {fuseki191085,5,"Fuseki1107", 1, 6,62.000000},
  {fuseki191086,5,"Fuseki1108", 4, 7,54.000000},
  {fuseki191087,5,"Fuseki1109", 6, 0,43.000000},
  {fuseki191088,5,"Fuseki1110",-4, 7,42.000000},
  {fuseki191089,5,"Fuseki1111", 1, 7,34.000000},
  {fuseki191090,5,"Fuseki1112",-4,-7,21.000000},
  {fuseki191091,5,"Fuseki1113", 6, 4,19.000000},
  {fuseki191092,5,"Fuseki1114",-4, 7,18.000000},
  {fuseki191093,5,"Fuseki1115", 3, 7,15.000000},
  {fuseki191094,5,"Fuseki1116", 0, 7,13.000000},
  {fuseki191095,5,"Fuseki1117",-7, 4,12.000000},
  {fuseki191096,5,"Fuseki1118", 4,-7,10.000000},
  {fuseki191097,5,"Fuseki1119", 4,-6,191.000000},
  {fuseki191098,5,"Fuseki1120",-7, 4,119.000000},
  {fuseki191099,5,"Fuseki1121", 7,-2,63.000000},
  {fuseki191100,5,"Fuseki1122", 6,-1,49.000000},
  {fuseki191101,5,"Fuseki1123", 7, 4,36.000000},
  {fuseki191102,5,"Fuseki1124", 6, 0,26.000000},
  {fuseki191103,5,"Fuseki1125", 6,-4,22.000000},
  {fuseki191104,5,"Fuseki1126",-7, 3,17.000000},
  {fuseki191105,5,"Fuseki1127", 0, 6,17.000000},
  {fuseki191106,5,"Fuseki1128",-1, 7,11.000000},
  {fuseki191107,4,"Fuseki1129",-6,-5,294.000000},
  {fuseki191108,4,"Fuseki1130", 7, 5,74.000000},
  {fuseki191109,4,"Fuseki1131",-4, 7,69.000000},
  {fuseki191110,4,"Fuseki1132",-4, 7,49.000000},
  {fuseki191111,4,"Fuseki1133",-4,-6,24.000000},
  {fuseki191112,4,"Fuseki1134",-7,-4,21.000000},
  {fuseki191113,4,"Fuseki1135",-7, 4,17.000000},
  {fuseki191114,3,"Fuseki1136",-6,-6,232.000000},
  {fuseki191115,3,"Fuseki1137",-6,-7,106.000000},
  {fuseki191116,3,"Fuseki1138",-6,-7,60.000000},
  {fuseki191117,3,"Fuseki1139",-6,-7,23.000000},
  {fuseki191118,3,"Fuseki1140",-5,-6,20.000000},
  {fuseki191119,3,"Fuseki1141",-7,-7,16.000000},
  {fuseki191120,3,"Fuseki1142",-5,-7,11.000000},
  {fuseki191121,3,"Fuseki1143",-6,-5,10.000000},
  {fuseki191122,6,"Fuseki1144", 7, 4,355.000000},
  {fuseki191123,6,"Fuseki1145",-4, 7,50.000000},
  {fuseki191124,6,"Fuseki1146",-7, 0,14.000000},
  {fuseki191125,6,"Fuseki1147", 6, 0,12.000000},
  {fuseki191126,6,"Fuseki1148",-6, 3,11.000000},
  {fuseki191127,6,"Fuseki1149",-3, 6,11.000000},
  {fuseki191128,6,"Fuseki1150",-7, 4,127.000000},
  {fuseki191129,6,"Fuseki1151", 3, 6,50.000000},
  {fuseki191130,6,"Fuseki1152",-6, 0,45.000000},
  {fuseki191131,6,"Fuseki1153", 8,-6,37.000000},
  {fuseki191132,6,"Fuseki1154", 4, 6,34.000000},
  {fuseki191133,6,"Fuseki1155", 2,-7,33.000000},
  {fuseki191134,6,"Fuseki1156", 4, 7,29.000000},
  {fuseki191135,6,"Fuseki1157",-7,-2,27.000000},
  {fuseki191136,6,"Fuseki1158", 1, 7,24.000000},
  {fuseki191137,6,"Fuseki1159",-4,-7,13.000000},
  {fuseki191138,6,"Fuseki1160", 4,-7,10.000000},
  {fuseki191139,4,"Fuseki1161", 7, 6,130.000000},
  {fuseki191140,4,"Fuseki1162", 0,-6,77.000000},
  {fuseki191141,4,"Fuseki1163", 7, 5,40.000000},
  {fuseki191142,4,"Fuseki1164",-6, 0,28.000000},
  {fuseki191143,4,"Fuseki1165", 6, 0,20.000000},
  {fuseki191144,4,"Fuseki1166", 6, 4,18.000000},
  {fuseki191145,4,"Fuseki1167", 0, 7,16.000000},
  {fuseki191146,4,"Fuseki1168", 0, 0,11.000000},
  {fuseki191147,5,"Fuseki1169", 6, 2,138.000000},
  {fuseki191148,5,"Fuseki1170", 7, 3,83.000000},
  {fuseki191149,5,"Fuseki1171", 7, 5,37.000000},
  {fuseki191150,5,"Fuseki1172", 5, 5,26.000000},
  {fuseki191151,5,"Fuseki1173", 6, 4,26.000000},
  {fuseki191152,5,"Fuseki1174", 7,-4,18.000000},
  {fuseki191153,5,"Fuseki1175", 6, 1,15.000000},
  {fuseki191154,5,"Fuseki1176",-4,-7,11.000000},
  {fuseki191155,7,"Fuseki1177",-4,-6,97.000000},
  {fuseki191156,7,"Fuseki1178", 7,-2,48.000000},
  {fuseki191157,7,"Fuseki1179", 6, 0,44.000000},
  {fuseki191158,7,"Fuseki1180", 4,-7,39.000000},
  {fuseki191159,7,"Fuseki1181",-6,-1,31.000000},
  {fuseki191160,7,"Fuseki1182", 6, 4,28.000000},
  {fuseki191161,7,"Fuseki1183", 7,-5,14.000000},
  {fuseki191162,7,"Fuseki1184", 7, 0,13.000000},
  {fuseki191163,5,"Fuseki1185",-6, 4,132.000000},
  {fuseki191164,5,"Fuseki1186", 7,-4,37.000000},
  {fuseki191165,5,"Fuseki1187",-1, 6,35.000000},
  {fuseki191166,5,"Fuseki1188", 2,-7,33.000000},
  {fuseki191167,5,"Fuseki1189", 5, 6,29.000000},
  {fuseki191168,5,"Fuseki1190", 0, 6,14.000000},
  {fuseki191169,5,"Fuseki1191",-7,-5,11.000000},
  {fuseki191170,5,"Fuseki1192",-4,-6,73.000000},
  {fuseki191171,5,"Fuseki1193",-4,-7,54.000000},
  {fuseki191172,5,"Fuseki1194",-7,-2,45.000000},
  {fuseki191173,5,"Fuseki1195",-6,-1,39.000000},
  {fuseki191174,5,"Fuseki1196",-6, 0,22.000000},
  {fuseki191175,5,"Fuseki1197",-4,-6,13.000000},
  {fuseki191176,5,"Fuseki1198",-5,-7,9.000000},
  {fuseki191177,5,"Fuseki1199",-7,-5,113.000000},
  {fuseki191178,5,"Fuseki1200",-6,-4,52.000000},
  {fuseki191179,5,"Fuseki1201",-6,-2,41.000000},
  {fuseki191180,5,"Fuseki1202",-3,-7,39.000000},
  {fuseki191181,3,"Fuseki1203",-6,-6,140.000000},
  {fuseki191182,3,"Fuseki1204", 7, 6,30.000000},
  {fuseki191183,3,"Fuseki1205",-6,-7,28.000000},
  {fuseki191184,3,"Fuseki1206", 7, 6,19.000000},
  {fuseki191185,3,"Fuseki1207", 5, 7,11.000000},
  {fuseki191186,6,"Fuseki1208",-4,-7,73.000000},
  {fuseki191187,6,"Fuseki1209", 6, 0,28.000000},
  {fuseki191188,6,"Fuseki1210", 8, 6,24.000000},
  {fuseki191189,6,"Fuseki1211", 7, 4,19.000000},
  {fuseki191190,6,"Fuseki1212", 6,-4,19.000000},
  {fuseki191191,6,"Fuseki1213", 3, 6,16.000000},
  {fuseki191192,6,"Fuseki1214", 2, 7,15.000000},
  {fuseki191193,6,"Fuseki1215", 1, 7,10.000000},
  {fuseki191194,6,"Fuseki1216", 7, 2,8.000000},
  {fuseki191195,6,"Fuseki1217", 7,-4,8.000000},
  {fuseki191196,4,"Fuseki1218", 6, 7,72.000000},
  {fuseki191197,4,"Fuseki1219", 6, 5,53.000000},
  {fuseki191198,4,"Fuseki1220", 0,-6,35.000000},
  {fuseki191199,4,"Fuseki1221", 0,-6,22.000000},
  {fuseki191200,4,"Fuseki1222", 0, 6,13.000000},
  {fuseki191201,7,"Fuseki1225",-7, 4,51.000000},
  {fuseki191202,7,"Fuseki1226", 6,-3,44.000000},
  {fuseki191203,7,"Fuseki1227",-2, 7,29.000000},
  {fuseki191204,7,"Fuseki1228", 0, 6,21.000000},
  {fuseki191205,7,"Fuseki1229", 4,-6,21.000000},
  {fuseki191206,7,"Fuseki1230",-7,-1,15.000000},
  {fuseki191207,7,"Fuseki1231",-7,-2,15.000000},
  {fuseki191208,7,"Fuseki1232", 7, 4,14.000000},
  {fuseki191209,7,"Fuseki1233",-7,-4,9.000000},
  {fuseki191210,7,"Fuseki1234", 4, 7,6.000000},
  {fuseki191211,4,"Fuseki1235", 7,-4,68.000000},
  {fuseki191212,4,"Fuseki1236", 4,-7,60.000000},
  {fuseki191213,4,"Fuseki1237", 4, 7,46.000000},
  {fuseki191214,4,"Fuseki1238",-7,-4,13.000000},
  {fuseki191215,4,"Fuseki1239", 4,-7,12.000000},
  {fuseki191216,4,"Fuseki1240",-7, 0,10.000000},
  {fuseki191217,6,"Fuseki1241",-4, 5,109.000000},
  {fuseki191218,6,"Fuseki1242", 7, 7,28.000000},
  {fuseki191219,6,"Fuseki1243",-2,-6,18.000000},
  {fuseki191220,6,"Fuseki1244", 4, 7,16.000000},
  {fuseki191221,4,"Fuseki1245",-2,-6,67.000000},
  {fuseki191222,4,"Fuseki1246",-3,-7,29.000000},
  {fuseki191223,4,"Fuseki1247", 5, 7,18.000000},
  {fuseki191224,4,"Fuseki1248",-6,-7,18.000000},
  {fuseki191225,4,"Fuseki1249", 4, 6,15.000000},
  {fuseki191226,4,"Fuseki1250",-6,-7,8.000000},
  {fuseki191227,4,"Fuseki1251", 5, 5,7.000000},
  {fuseki191228,6,"Fuseki1252", 6, 0,90.000000},
  {fuseki191229,6,"Fuseki1253",-6, 8,33.000000},
  {fuseki191230,6,"Fuseki1254",-4, 7,18.000000},
  {fuseki191231,6,"Fuseki1255", 7,-2,16.000000},
  {fuseki191232,7,"Fuseki1256",-7,-4,139.000000},
  {fuseki191233,7,"Fuseki1257",-4, 7,15.000000},
  {fuseki191234,4,"Fuseki1258",-6,-5,72.000000},
  {fuseki191235,4,"Fuseki1259", 5, 7,35.000000},
  {fuseki191236,4,"Fuseki1260", 7,-4,32.000000},
  {fuseki191237,4,"Fuseki1261",-7, 4,15.000000},
  {fuseki191238,4,"Fuseki1262",-5,-6,87.000000},
  {fuseki191239,4,"Fuseki1263", 7, 5,41.000000},
  {fuseki191240,4,"Fuseki1264", 7,-4,23.000000},
  {fuseki191241,4,"Fuseki1265",-7, 4,11.000000},
  {fuseki191242,9,"Fuseki1266",-4, 7,130.000000},
  {fuseki191243,9,"Fuseki1267", 6, 3,28.000000},
  {fuseki191244,5,"Fuseki1268", 7,-4,56.000000},
  {fuseki191245,5,"Fuseki1269", 7,-4,50.000000},
  {fuseki191246,5,"Fuseki1270",-7,-4,34.000000},
  {fuseki191247,5,"Fuseki1271", 2, 6,52.000000},
  {fuseki191248,5,"Fuseki1272", 7, 3,27.000000},
  {fuseki191249,5,"Fuseki1273", 7, 1,13.000000},
  {fuseki191250,5,"Fuseki1274", 1, 6,11.000000},
  {fuseki191251,5,"Fuseki1275", 3, 6,10.000000},
  {fuseki191252,5,"Fuseki1276", 2, 7,8.000000},
  {fuseki191253,4,"Fuseki1277",-4, 7,57.000000},
  {fuseki191254,4,"Fuseki1278", 7,-4,34.000000},
  {fuseki191255,4,"Fuseki1279",-4,-7,10.000000},
  {fuseki191256,4,"Fuseki1280",-7, 0,9.000000},
  {fuseki191257,4,"Fuseki1281",-7,-4,7.000000},
  {fuseki191258,4,"Fuseki1282", 4,-7,6.000000},
  {fuseki191259,8,"Fuseki1283",-4, 6,36.000000},
  {fuseki191260,8,"Fuseki1284",-7,-2,18.000000},
  {fuseki191261,8,"Fuseki1285", 4,-7,16.000000},
  {fuseki191262,8,"Fuseki1286",-6,-1,13.000000},
  {fuseki191263,8,"Fuseki1287", 7, 0,11.000000},
  {fuseki191264,8,"Fuseki1288",-6, 0,11.000000},
  {fuseki191265,8,"Fuseki1290",-7,-6,6.000000},
  {fuseki191266,6,"Fuseki1291", 5, 4,41.000000},
  {fuseki191267,6,"Fuseki1292", 6, 3,35.000000},
  {fuseki191268,6,"Fuseki1293", 7, 7,20.000000},
  {fuseki191269,6,"Fuseki1294", 4, 6,12.000000},
  {fuseki191270,6,"Fuseki1295", 5, 7,12.000000},
  {fuseki191271,6,"Fuseki1296", 3, 5,10.000000},
  {fuseki191272,6,"Fuseki1297", 1, 7,60.000000},
  {fuseki191273,6,"Fuseki1298", 0,-6,27.000000},
  {fuseki191274,6,"Fuseki1299", 1, 6,14.000000},
  {fuseki191275,6,"Fuseki1300", 6,-8,8.000000},
  {fuseki191276,6,"Fuseki1301", 6,-1,6.000000},
  {fuseki191277,6,"Fuseki1302", 7, 7,66.000000},
  {fuseki191278,6,"Fuseki1303", 5, 4,58.000000},
  {fuseki191279,5,"Fuseki1304", 6, 4,67.000000},
  {fuseki191280,5,"Fuseki1305", 6, 3,24.000000},
  {fuseki191281,5,"Fuseki1306", 5, 7,13.000000},
  {fuseki191282,5,"Fuseki1307",-4, 7,8.000000},
  {fuseki191283,10,"Fuseki1308",-4, 6,34.000000},
  {fuseki191284,10,"Fuseki1309",-5, 7,31.000000},
  {fuseki191285,10,"Fuseki1310", 4, 7,15.000000},
  {fuseki191286,10,"Fuseki1311",-6,-4,12.000000},
  {fuseki191287,10,"Fuseki1312",-2, 7,11.000000},
  {fuseki191288,10,"Fuseki1313",-6, 7,5.000000},
  {fuseki191289,10,"Fuseki1314",-4, 5,4.000000},
  {fuseki191290,7,"Fuseki1315", 6,-4,44.000000},
  {fuseki191291,7,"Fuseki1316",-6, 0,36.000000},
  {fuseki191292,7,"Fuseki1317", 7,-2,9.000000},
  {fuseki191293,7,"Fuseki1318",-6, 1,8.000000},
  {fuseki191294,7,"Fuseki1319", 4,-7,8.000000},
  {fuseki191295,7,"Fuseki1320", 0, 7,6.000000},
  {fuseki191296,7,"Fuseki1321", 7,-2,5.000000},
  {fuseki191297,6,"Fuseki1322", 0, 6,50.000000},
  {fuseki191298,6,"Fuseki1323", 8,-6,33.000000},
  {fuseki191299,6,"Fuseki1324", 7,-4,14.000000},
  {fuseki191300,6,"Fuseki1325",-7,-4,5.000000},
  {fuseki191301,7,"Fuseki1326", 4, 7,36.000000},
  {fuseki191302,7,"Fuseki1327", 7, 4,10.000000},
  {fuseki191303,7,"Fuseki1328", 0, 6,10.000000},
  {fuseki191304,7,"Fuseki1329",-6,-8,10.000000},
  {fuseki191305,7,"Fuseki1330", 3, 6,9.000000},
  {fuseki191306,7,"Fuseki1331", 4, 6,9.000000},
  {fuseki191307,7,"Fuseki1332",-1,-7,7.000000},
  {fuseki191308,7,"Fuseki1333", 7,-2,6.000000},
  {fuseki191309,7,"Fuseki1334",-2, 7,5.000000},
  {fuseki191310,7,"Fuseki1335", 7,-4,4.000000},
  {fuseki191311,6,"Fuseki1336",-7,-4,95.000000},
  {fuseki191312,6,"Fuseki1337",-6,-6,17.000000},
  {fuseki191313,7,"Fuseki1338",-6, 4,74.000000},
  {fuseki191314,7,"Fuseki1339",-4, 7,24.000000},
  {fuseki191315,4,"Fuseki1340",-6,-5,65.000000},
  {fuseki191316,4,"Fuseki1341",-5,-7,13.000000},
  {fuseki191317,8,"Fuseki1342",-7, 4,45.000000},
  {fuseki191318,8,"Fuseki1343", 6,-4,14.000000},
  {fuseki191319,8,"Fuseki1344",-6,-3,8.000000},
  {fuseki191320,8,"Fuseki1345",-7,-1,7.000000},
  {fuseki191321,8,"Fuseki1346", 7,-4,5.000000},
  {fuseki191322,7,"Fuseki1347",-7,-6,95.000000},
  {fuseki191323,8,"Fuseki1348",-6,-4,44.000000},
  {fuseki191324,8,"Fuseki1349",-3,-6,34.000000},
  {fuseki191325,8,"Fuseki1350", 7,-4,8.000000},
  {fuseki191326,8,"Fuseki1351", 7,-4,7.000000},
  {fuseki191327,7,"Fuseki1352", 6, 0,30.000000},
  {fuseki191328,7,"Fuseki1353", 7, 4,21.000000},
  {fuseki191329,7,"Fuseki1354", 0, 7,13.000000},
  {fuseki191330,7,"Fuseki1355", 6, 0,11.000000},
  {fuseki191331,7,"Fuseki1356", 0,-6,9.000000},
  {fuseki191332,5,"Fuseki1357",-5,-7,41.000000},
  {fuseki191333,5,"Fuseki1358",-6,-4,16.000000},
  {fuseki191334,5,"Fuseki1359",-2,-6,9.000000},
  {fuseki191335,5,"Fuseki1360",-3,-7,8.000000},
  {fuseki191336,5,"Fuseki1361",-5,-6,6.000000},
  {fuseki191337,5,"Fuseki1362", 7,-4,24.000000},
  {fuseki191338,5,"Fuseki1363",-7, 2,19.000000},
  {fuseki191339,5,"Fuseki1364", 6,-4,16.000000},
  {fuseki191340,5,"Fuseki1365", 7,-3,6.000000},
  {fuseki191341,5,"Fuseki1366",-6, 1,6.000000},
  {fuseki191342,5,"Fuseki1367",-6, 0,3.000000},
  {fuseki191343,5,"Fuseki1369",-4, 6,3.000000},
  {fuseki191344,5,"Fuseki1370", 0,-6,3.000000},
  {fuseki191345,3,"Fuseki1371", 6, 6,46.000000},
  {fuseki191346,3,"Fuseki1372", 7, 6,24.000000},
  {fuseki191347,3,"Fuseki1373", 7, 7,6.000000},
  {fuseki191348,6,"Fuseki1374", 7, 7,29.000000},
  {fuseki191349,6,"Fuseki1375", 5, 4,26.000000},
  {fuseki191350,6,"Fuseki1376", 5, 7,6.000000},
  {fuseki191351,6,"Fuseki1378", 5, 8,4.000000},
  {fuseki191352,6,"Fuseki1380", 6, 4,4.000000},
  {fuseki191353,6,"Fuseki1381", 4,-7,37.000000},
  {fuseki191354,6,"Fuseki1382",-6, 4,19.000000},
  {fuseki191355,6,"Fuseki1383",-4, 5,9.000000},
  {fuseki191356,6,"Fuseki1384", 3, 6,4.000000},
  {fuseki191357,6,"Fuseki1385", 6,-3,4.000000},
  {fuseki191358,4,"Fuseki1386",-6,-6,16.000000},
  {fuseki191359,4,"Fuseki1387", 7, 2,13.000000},
  {fuseki191360,4,"Fuseki1388",-1,-6,12.000000},
  {fuseki191361,4,"Fuseki1389", 4, 7,10.000000},
  {fuseki191362,4,"Fuseki1390", 4, 6,7.000000},
  {fuseki191363,4,"Fuseki1391", 6, 0,5.000000},
  {fuseki191364,4,"Fuseki1392", 7, 1,4.000000},
  {fuseki191365,4,"Fuseki1393",-7, 4,4.000000},
  {fuseki191366,4,"Fuseki1394",-6,-7,2.000000},
  {fuseki191367,4,"Fuseki1395", 6, 2,2.000000},
  {fuseki191368,7,"Fuseki1396",-5,-4,31.000000},
  {fuseki191369,7,"Fuseki1397",-7,-6,12.000000},
  {fuseki191370,7,"Fuseki1398",-7, 7,9.000000},
  {fuseki191371,7,"Fuseki1399",-6, 4,5.000000},
  {fuseki191372,7,"Fuseki1400",-2, 6,5.000000},
  {fuseki191373,7,"Fuseki1401",-7,-4,5.000000},
  {fuseki191374,7,"Fuseki1402",-4, 7,4.000000},
  {fuseki191375,5,"Fuseki1403",-4, 7,27.000000},
  {fuseki191376,5,"Fuseki1404", 7,-4,24.000000},
  {fuseki191377,5,"Fuseki1405",-7,-4,15.000000},
  {fuseki191378,5,"Fuseki1406",-3, 6,3.000000},
  {fuseki191379,5,"Fuseki1407",-7, 4,3.000000},
  {fuseki191380,5,"Fuseki1408",-7, 0,3.000000},
  {fuseki191381,8,"Fuseki1409",-7, 4,55.000000},
  {fuseki191382,8,"Fuseki1410",-3, 6,10.000000},
  {fuseki191383,8,"Fuseki1411", 0, 0,10.000000},
  {fuseki191384,5,"Fuseki1412", 2, 6,15.000000},
  {fuseki191385,5,"Fuseki1414",-6,-4,12.000000},
  {fuseki191386,5,"Fuseki1415",-5,-6,8.000000},
  {fuseki191387,5,"Fuseki1416",-5,-6,5.000000},
  {fuseki191388,5,"Fuseki1417",-3,-7,5.000000},
  {fuseki191389,5,"Fuseki1418",-3,-6,4.000000},
  {fuseki191390,5,"Fuseki1419",-1,-7,4.000000},
  {fuseki191391,5,"Fuseki1420",-7,-2,3.000000},
  {fuseki191392,5,"Fuseki1421",-6,-3,3.000000},
  {fuseki191393,5,"Fuseki1423",-7,-3,2.000000},
  {fuseki191394,6,"Fuseki1424",-4, 5,24.000000},
  {fuseki191395,6,"Fuseki1425", 4, 7,20.000000},
  {fuseki191396,6,"Fuseki1426",-6, 4,11.000000},
  {fuseki191397,6,"Fuseki1427",-7, 7,9.000000},
  {fuseki191398,6,"Fuseki1428", 7,-6,3.000000},
  {fuseki191399,6,"Fuseki1429",-2, 5,3.000000},
  {fuseki191400,5,"Fuseki1430",-7,-4,20.000000},
  {fuseki191401,5,"Fuseki1431",-2,-7,14.000000},
  {fuseki191402,5,"Fuseki1432",-6,-4,9.000000},
  {fuseki191403,5,"Fuseki1433",-1,-6,8.000000},
  {fuseki191404,5,"Fuseki1434",-2,-6,4.000000},
  {fuseki191405,5,"Fuseki1435",-7, 0,3.000000},
  {fuseki191406,5,"Fuseki1436", 0,-6,3.000000},
  {fuseki191407,5,"Fuseki1437",-4,-6,3.000000},
  {fuseki191408,5,"Fuseki1438",-5,-7,3.000000},
  {fuseki191409,5,"Fuseki1439", 7, 3,3.000000},
  {fuseki191410,5,"Fuseki1440",-6, 0,2.000000},
  {fuseki191411,5,"Fuseki1441", 7, 5,2.000000},
  {fuseki191412,8,"Fuseki1442", 1,-6,30.000000},
  {fuseki191413,8,"Fuseki1443", 4, 7,8.000000},
  {fuseki191414,8,"Fuseki1444", 0, 7,8.000000},
  {fuseki191415,8,"Fuseki1445",-2, 7,6.000000},
  {fuseki191416,8,"Fuseki1446",-3, 4,6.000000},
  {fuseki191417,8,"Fuseki1447", 6,-3,5.000000},
  {fuseki191418,7,"Fuseki1448", 4,-7,27.000000},
  {fuseki191419,7,"Fuseki1449", 0, 6,16.000000},
  {fuseki191420,7,"Fuseki1450",-2,-7,7.000000},
  {fuseki191421,7,"Fuseki1451", 7, 2,5.000000},
  {fuseki191422,7,"Fuseki1452", 0, 7,5.000000},
  {fuseki191423,7,"Fuseki1453", 1, 6,4.000000},
  {fuseki191424,7,"Fuseki1454", 4, 6,4.000000},
  {fuseki191425,6,"Fuseki1455",-6,-8,26.000000},
  {fuseki191426,6,"Fuseki1456", 0,-6,18.000000},
  {fuseki191427,6,"Fuseki1457",-7,-2,9.000000},
  {fuseki191428,6,"Fuseki1458", 4,-7,8.000000},
  {fuseki191429,5,"Fuseki1459", 4, 6,39.000000},
  {fuseki191430,5,"Fuseki1460",-4, 7,13.000000},
  {fuseki191431,5,"Fuseki1461", 5, 6,9.000000},
  {fuseki191432,5,"Fuseki1462",-5,-7,24.000000},
  {fuseki191433,5,"Fuseki1463",-2,-6,14.000000},
  {fuseki191434,5,"Fuseki1464",-7,-3,11.000000},
  {fuseki191435,5,"Fuseki1465",-4,-6,9.000000},
  {fuseki191436,5,"Fuseki1466", 5, 6,3.000000},
  {fuseki191437,6,"Fuseki1467", 6, 8,31.000000},
  {fuseki191438,6,"Fuseki1468", 0, 6,22.000000},
  {fuseki191439,6,"Fuseki1469", 6, 1,7.000000},
  {fuseki191440,5,"Fuseki1470",-6, 4,21.000000},
  {fuseki191441,5,"Fuseki1471", 4,-7,12.000000},
  {fuseki191442,5,"Fuseki1472",-6, 4,7.000000},
  {fuseki191443,5,"Fuseki1473",-1, 6,5.000000},
  {fuseki191444,5,"Fuseki1474",-2, 7,5.000000},
  {fuseki191445,5,"Fuseki1475", 0,-6,4.000000},
  {fuseki191446,5,"Fuseki1476",-5,-6,3.000000},
  {fuseki191447,5,"Fuseki1477", 4, 7,3.000000},
  {fuseki191448,5,"Fuseki1478",-2, 6,3.000000},
  {fuseki191449,5,"Fuseki1479", 4,-6,20.000000},
  {fuseki191450,5,"Fuseki1480", 7,-2,13.000000},
  {fuseki191451,5,"Fuseki1481", 4,-7,12.000000},
  {fuseki191452,5,"Fuseki1482", 6,-1,5.000000},
  {fuseki191453,5,"Fuseki1483",-6, 0,4.000000},
  {fuseki191454,5,"Fuseki1484", 5,-4,2.000000},
  {fuseki191455,5,"Fuseki1485", 0,-6,2.000000},
  {fuseki191456,5,"Fuseki1486", 6,-4,2.000000},
  {fuseki191457,6,"Fuseki1487", 5, 7,26.000000},
  {fuseki191458,6,"Fuseki1488", 7, 4,17.000000},
  {fuseki191459,6,"Fuseki1490", 6, 7,4.000000},
  {fuseki191460,6,"Fuseki1491", 8, 4,3.000000},
  {fuseki191461,6,"Fuseki1492",-3, 7,3.000000},
  {fuseki191462,5,"Fuseki1493", 5, 4,18.000000},
  {fuseki191463,5,"Fuseki1494",-7,-7,10.000000},
  {fuseki191464,5,"Fuseki1495", 5, 7,10.000000},
  {fuseki191465,5,"Fuseki1496", 3, 6,9.000000},
  {fuseki191466,5,"Fuseki1497", 6, 4,7.000000},
  {fuseki191467,5,"Fuseki1498", 3, 5,4.000000},
  {fuseki191468,4,"Fuseki1499", 7, 6,18.000000},
  {fuseki191469,4,"Fuseki1500",-4, 7,10.000000},
  {NULL,0,NULL,0,0,0.0}
};


/* mgena ============================================================*/

/* mgena - josekidb.c */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* #include <stdio.h>  */

/* #include "gnugo.h" */
/* #include "liberty.h" */
/* #include "patterns.h" */


static struct patval joseki0[] = {
   {0,0,1},
   {0,2,2},
   {-3,-1,0},
   {-3,1,0},
   {-3,-2,0},
   {-3,3,0},
   {-3,4,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-2,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {-3,2,0},
   {0,3,0},
   {0,4,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0}};

static struct patval joseki1[] = {
   {0,0,1},
   {1,2,1},
   {1,0,2},
   {-2,0,0},
   {-2,-2,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {-2,-1,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki2[] = {
   {1,1,1},
   {0,0,1},
   {1,3,2},
   {0,1,2},
   {-2,-1,0},
   {-2,2,0},
   {-2,5,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-1,0},
   {-2,3,0},
   {-2,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-1,0},
   {1,0,0},
   {-2,4,0},
   {1,2,0},
   {-2,0,0},
   {1,4,0},
   {1,5,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0}};

static struct patval joseki3[] = {
   {0,1,1},
   {0,2,1},
   {1,3,1},
   {0,0,2},
   {1,1,2},
   {-2,3,0},
   {-2,4,0},
   {-2,1,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-2,5,0},
   {-2,-2,0},
   {-2,-1,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {-2,0,0},
   {1,2,0},
   {-2,2,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0}};

static struct patval joseki4[] = {
   {1,1,1},
   {0,0,1},
   {1,0,1},
   {0,1,2},
   {1,3,2},
   {0,2,2},
   {-2,4,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,5,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-1,0},
   {-2,2,0},
   {-2,3,0},
   {1,2,0},
   {-2,-1,0},
   {1,4,0},
   {1,5,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0}};

static struct patval joseki5[] = {
   {0,1,1},
   {0,2,1},
   {1,3,1},
   {3,3,1},
   {0,0,2},
   {1,1,2},
   {1,0,2},
   {-2,-2,0},
   {-2,-4,0},
   {-2,4,0},
   {-2,5,0},
   {-1,-5,0},
   {-2,2,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {-2,3,0},
   {-2,-5,0},
   {1,2,0},
   {-2,-3,0},
   {1,4,0},
   {1,5,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {-1,-4,0},
   {3,4,0},
   {3,5,0}};

static struct patval joseki6[] = {
   {0,2,1},
   {0,1,1},
   {1,3,1},
   {0,0,2},
   {1,0,2},
   {1,1,2},
   {-2,2,0},
   {-2,5,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,4,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-2,0},
   {1,-1,0},
   {-2,0,0},
   {-2,1,0},
   {1,2,0},
   {-2,3,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki7[] = {
   {0,0,1},
   {2,3,1},
   {1,0,1},
   {1,1,1},
   {1,3,2},
   {0,1,2},
   {0,2,2},
   {-2,2,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-2,5,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,4,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-2,0},
   {1,-1,0},
   {-2,0,0},
   {-2,1,0},
   {1,2,0},
   {-1,1,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki8[] = {
   {2,4,1},
   {0,1,1},
   {0,2,1},
   {1,3,1},
   {2,3,2},
   {1,1,2},
   {0,0,2},
   {1,0,2},
   {-1,-2,0},
   {-2,2,0},
   {-1,0,0},
   {-2,5,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {-2,-1,0},
   {-1,-1,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-2,0},
   {1,-1,0},
   {-2,0,0},
   {-2,1,0},
   {1,2,0},
   {-1,1,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-2,3,0},
   {-2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki9[] = {
   {0,0,1},
   {2,3,1},
   {1,0,1},
   {1,1,1},
   {1,2,1},
   {0,1,2},
   {2,4,2},
   {1,3,2},
   {0,2,2},
   {-1,-2,0},
   {-1,0,0},
   {-2,5,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {-2,-1,0},
   {-1,-1,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-2,0},
   {1,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-1,1,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-2,3,0},
   {-2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki10[] = {
   {2,4,1},
   {0,1,1},
   {0,2,1},
   {1,3,1},
   {0,4,1},
   {1,1,2},
   {0,0,2},
   {2,3,2},
   {1,2,2},
   {1,0,2},
   {-1,0,0},
   {-2,5,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {-2,-1,0},
   {-1,-1,0},
   {0,3,0},
   {-1,-2,0},
   {0,5,0},
   {1,-2,0},
   {1,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-1,1,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-2,3,0},
   {-2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki11[] = {
   {0,0,1},
   {1,1,1},
   {1,0,1},
   {3,3,1},
   {1,2,1},
   {2,3,1},
   {2,4,2},
   {1,3,2},
   {0,4,2},
   {0,1,2},
   {0,2,2},
   {-2,5,0},
   {-1,0,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {-2,-1,0},
   {-1,2,0},
   {0,3,0},
   {-1,-2,0},
   {0,5,0},
   {1,-2,0},
   {1,-1,0},
   {-2,0,0},
   {-1,-1,0},
   {-2,2,0},
   {-1,1,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-2,3,0},
   {-2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {-2,1,0},
   {3,4,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki12[] = {
   {0,4,1},
   {0,1,1},
   {0,2,1},
   {2,4,1},
   {3,4,1},
   {1,3,1},
   {3,3,2},
   {2,3,2},
   {0,0,2},
   {1,1,2},
   {1,2,2},
   {1,0,2},
   {-2,5,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {-2,-1,0},
   {-1,2,0},
   {0,3,0},
   {-1,-2,0},
   {0,5,0},
   {1,-2,0},
   {1,-1,0},
   {-2,0,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-2,3,0},
   {-2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {-2,1,0},
   {-2,2,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki13[] = {
   {1,3,1},
   {0,1,1},
   {0,2,1},
   {0,0,2},
   {1,1,2},
   {-2,1,0},
   {-2,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-4,0},
   {-2,-3,0},
   {-2,-2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {-2,0,0},
   {1,2,0},
   {-2,2,0},
   {1,4,0},
   {1,5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0}};

static struct patval joseki14[] = {
   {1,1,1},
   {0,0,1},
   {1,-1,1},
   {0,2,2},
   {1,3,2},
   {0,1,2},
   {-2,5,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-1,0},
   {-2,0,0},
   {-2,4,0},
   {-2,2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {-2,1,0},
   {1,0,0},
   {-2,3,0},
   {1,2,0},
   {-2,-1,0},
   {1,4,0},
   {1,5,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0}};

static struct patval joseki15[] = {
   {0,2,1},
   {0,1,1},
   {3,3,1},
   {1,3,1},
   {0,0,2},
   {1,-1,2},
   {1,1,2},
   {-2,-4,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,4,0},
   {-2,5,0},
   {-1,-6,0},
   {-1,-5,0},
   {-2,2,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,-6,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-6,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {-2,3,0},
   {1,0,0},
   {-2,-5,0},
   {1,2,0},
   {-2,-3,0},
   {1,4,0},
   {1,5,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {-1,-4,0},
   {3,4,0},
   {3,5,0}};

static struct patval joseki16[] = {
   {1,2,1},
   {0,0,1},
   {1,0,2},
   {-2,1,0},
   {-2,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-2,0},
   {1,-1,0},
   {-2,2,0},
   {1,1,0},
   {-2,-2,0},
   {1,3,0},
   {1,4,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0}};

static struct patval joseki17[] = {
   {1,1,1},
   {1,0,1},
   {1,2,2},
   {0,0,2},
   {-2,1,0},
   {-2,4,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-1,0},
   {-2,0,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,-1,0},
   {1,3,0},
   {1,4,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0}};

static struct patval joseki18[] = {
   {0,1,1},
   {1,2,1},
   {0,0,1},
   {1,0,2},
   {1,1,2},
   {-2,3,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-1,0},
   {-2,4,0},
   {-2,-1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {1,3,0},
   {1,4,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki19[] = {
   {2,2,1},
   {1,0,1},
   {1,1,1},
   {0,1,2},
   {1,2,2},
   {0,0,2},
   {-1,-1,0},
   {-2,3,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-1,0},
   {-2,4,0},
   {-2,-1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-1,0,0},
   {1,3,0},
   {1,4,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki20[] = {
   {0,0,1},
   {0,1,1},
   {0,2,1},
   {1,2,1},
   {1,1,2},
   {2,2,2},
   {1,0,2},
   {-1,-2,0},
   {-1,-1,0},
   {-2,3,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,4,0},
   {0,3,0},
   {0,4,0},
   {1,-2,0},
   {1,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-1,0,0},
   {1,3,0},
   {1,4,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki21[] = {
   {2,2,1},
   {1,-1,1},
   {1,0,1},
   {1,1,1},
   {0,0,2},
   {0,2,2},
   {0,1,2},
   {1,2,2},
   {-2,2,0},
   {-1,-2,0},
   {-1,-3,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {-2,3,0},
   {-2,4,0},
   {0,3,0},
   {0,4,0},
   {1,-3,0},
   {1,-2,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-1,-1,0},
   {1,3,0},
   {1,4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-2,1,0},
   {2,3,0},
   {2,4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki22[] = {
   {0,2,1},
   {0,3,1},
   {0,4,1},
   {0,0,1},
   {1,4,1},
   {1,3,2},
   {1,1,2},
   {1,2,2},
   {2,4,2},
   {-2,4,0},
   {-1,-1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {0,-1,0},
   {-1,0,0},
   {0,1,0},
   {-2,-1,0},
   {-2,5,0},
   {-2,6,0},
   {0,5,0},
   {0,6,0},
   {1,-1,0},
   {1,0,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-1,1,0},
   {1,5,0},
   {1,6,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {-2,3,0},
   {2,5,0},
   {2,6,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0}};

static struct patval joseki23[] = {
   {0,0,1},
   {0,2,2},
   {-3,-3,0},
   {-3,0,0},
   {-3,1,0},
   {-3,2,0},
   {-3,-1,0},
   {-3,4,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-3,3,0},
   {0,1,0},
   {-3,-2,0},
   {0,3,0},
   {0,4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki24[] = {
   {2,1,1},
   {0,2,1},
   {0,0,2},
   {-3,0,0},
   {-3,1,0},
   {-3,2,0},
   {-3,-1,0},
   {-3,-3,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-3,3,0},
   {0,1,0},
   {-3,-2,0},
   {0,3,0},
   {0,4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-3,4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki25[] = {
   {0,0,1},
   {1,-2,1},
   {3,-1,2},
   {1,0,2},
   {-2,-1,0},
   {-2,0,0},
   {-2,-2,0},
   {-2,-3,0},
   {-1,-5,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-5,0},
   {0,1,0},
   {0,2,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {-2,1,0},
   {1,-1,0},
   {-2,-4,0},
   {1,1,0},
   {1,2,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {-2,2,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0}};

static struct patval joseki26[] = {
   {3,-1,1},
   {1,0,1},
   {0,1,1},
   {1,-2,2},
   {0,0,2},
   {-2,0,0},
   {-2,-1,0},
   {-2,-3,0},
   {-1,-5,0},
   {-1,-4,0},
   {-2,-2,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-5,0},
   {-1,-3,0},
   {0,2,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {-2,1,0},
   {1,-1,0},
   {-2,-4,0},
   {1,1,0},
   {1,2,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {-2,2,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0}};

static struct patval joseki27[] = {
   {0,1,1},
   {1,-1,1},
   {0,0,1},
   {0,2,2},
   {3,0,2},
   {1,1,2},
   {-2,1,0},
   {-2,-2,0},
   {-1,-4,0},
   {-1,-3,0},
   {-2,-1,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {-2,-4,0},
   {-1,-2,0},
   {0,3,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {-2,2,0},
   {1,0,0},
   {-2,-3,0},
   {1,2,0},
   {1,3,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {-2,3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0}};

static struct patval joseki28[] = {
   {1,1,1},
   {2,2,1},
   {3,0,1},
   {0,2,1},
   {0,1,2},
   {1,-1,2},
   {0,0,2},
   {-2,-1,0},
   {-2,-6,0},
   {-2,3,0},
   {-2,-5,0},
   {-1,-5,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {-2,-3,0},
   {-1,-6,0},
   {0,3,0},
   {1,-6,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {-2,-2,0},
   {1,0,0},
   {-2,0,0},
   {1,2,0},
   {1,3,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-2,1,0},
   {2,3,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {-2,-4,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0}};

static struct patval joseki29[] = {
   {3,0,1},
   {2,2,1},
   {0,2,1},
   {1,1,1},
   {0,1,2},
   {0,0,2},
   {1,-1,2},
   {-2,-1,0},
   {-2,-3,0},
   {-2,1,0},
   {-1,-4,0},
   {-2,-2,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {-2,-5,0},
   {-1,-3,0},
   {0,3,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {-2,2,0},
   {1,0,0},
   {-1,-5,0},
   {1,2,0},
   {1,3,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-2,-4,0},
   {2,3,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {-2,3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0}};

static struct patval joseki30[] = {
   {2,1,1},
   {0,2,1},
   {0,0,2},
   {-3,0,0},
   {-3,1,0},
   {-3,2,0},
   {-3,-1,0},
   {-3,-3,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-3,3,0},
   {0,1,0},
   {-3,-2,0},
   {0,3,0},
   {0,4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-3,4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki31[] = {
   {2,1,1},
   {0,2,1},
   {0,0,2},
   {-3,0,0},
   {-3,1,0},
   {-3,2,0},
   {-3,-1,0},
   {-3,-3,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-3,3,0},
   {0,1,0},
   {-3,-2,0},
   {0,3,0},
   {0,4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-3,4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki32[] = {
   {0,2,1},
   {1,0,1},
   {0,0,2},
   {-3,0,0},
   {-3,-2,0},
   {-3,2,0},
   {-3,3,0},
   {-3,4,0},
   {-3,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {0,1,0},
   {-3,1,0},
   {0,3,0},
   {0,4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {-3,-1,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0}};

static struct patval joseki33[] = {
   {0,0,1},
   {1,-1,1},
   {1,0,2},
   {0,2,2},
   {-3,0,0},
   {-3,2,0},
   {-3,3,0},
   {-3,4,0},
   {-3,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {0,1,0},
   {-3,1,0},
   {0,3,0},
   {0,4,0},
   {1,-3,0},
   {1,-2,0},
   {-3,-2,0},
   {-3,-1,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0}};

static struct patval joseki34[] = {
   {0,2,1},
   {1,1,1},
   {1,0,1},
   {1,-1,2},
   {0,0,2},
   {-3,-4,0},
   {-3,2,0},
   {-3,3,0},
   {-3,4,0},
   {-2,-4,0},
   {-3,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {0,1,0},
   {-3,1,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {-3,-2,0},
   {-3,-1,0},
   {-3,0,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0}};

static struct patval joseki35[] = {
   {0,2,1},
   {0,0,1},
   {1,1,1},
   {0,4,2},
   {1,3,2},
   {1,2,2},
   {-3,4,0},
   {-3,5,0},
   {-3,6,0},
   {-2,-2,0},
   {-3,-2,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {0,-2,0},
   {0,-1,0},
   {-3,-1,0},
   {0,1,0},
   {-2,-1,0},
   {0,3,0},
   {-3,3,0},
   {0,5,0},
   {0,6,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {-3,0,0},
   {-3,1,0},
   {-3,2,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0}};

static struct patval joseki36[] = {
   {1,2,1},
   {0,0,1},
   {2,1,1},
   {2,0,1},
   {2,-1,2},
   {1,0,2},
   {1,-2,2},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-2,-4,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {1,-3,0},
   {-2,-3,0},
   {1,-1,0},
   {-1,-3,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki37[] = {
   {0,2,1},
   {2,0,1},
   {1,0,1},
   {1,-1,2},
   {0,0,2},
   {-3,0,0},
   {-3,2,0},
   {-3,3,0},
   {-3,4,0},
   {-2,-4,0},
   {-3,-4,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {0,1,0},
   {-3,1,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {-3,-2,0},
   {-3,-1,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {-3,-3,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0}};

static struct patval joseki38[] = {
   {0,0,1},
   {1,1,1},
   {0,2,1},
   {2,2,2},
   {0,4,2},
   {1,2,2},
   {-3,2,0},
   {-3,6,0},
   {-3,4,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {0,-1,0},
   {-3,5,0},
   {0,1,0},
   {-2,-1,0},
   {0,3,0},
   {-3,3,0},
   {0,5,0},
   {0,6,0},
   {1,-1,0},
   {1,0,0},
   {-3,0,0},
   {-3,1,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-3,-1,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0}};

static struct patval joseki39[] = {
   {0,4,1},
   {2,2,1},
   {0,3,1},
   {1,2,1},
   {1,1,2},
   {0,2,2},
   {0,0,2},
   {-3,5,0},
   {-3,4,0},
   {-2,-2,0},
   {-3,-2,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {0,-2,0},
   {0,-1,0},
   {-3,6,0},
   {0,1,0},
   {-2,-1,0},
   {-3,2,0},
   {-3,3,0},
   {0,5,0},
   {0,6,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {-3,0,0},
   {-3,1,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-3,-1,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0}};

static struct patval joseki40[] = {
   {0,3,1},
   {0,0,1},
   {1,1,1},
   {1,0,2},
   {0,1,2},
   {-3,4,0},
   {-3,2,0},
   {-3,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-1,0},
   {-3,5,0},
   {-2,-1,0},
   {0,2,0},
   {-3,3,0},
   {0,4,0},
   {0,5,0},
   {1,-1,0},
   {-3,0,0},
   {-3,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0}};

static struct patval joseki41[] = {
   {1,1,1},
   {0,3,1},
   {2,1,1},
   {0,0,1},
   {1,0,2},
   {1,2,2},
   {0,1,2},
   {-3,-2,0},
   {-3,1,0},
   {-2,-1,0},
   {-2,0,0},
   {-3,0,0},
   {-2,2,0},
   {-3,2,0},
   {-2,4,0},
   {-2,5,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-3,3,0},
   {-2,1,0},
   {0,2,0},
   {-3,-1,0},
   {0,4,0},
   {0,5,0},
   {1,-2,0},
   {1,-1,0},
   {-2,3,0},
   {-3,5,0},
   {-2,-2,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-3,4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0}};

static struct patval joseki42[] = {
   {1,1,1},
   {0,3,1},
   {1,-1,1},
   {2,1,1},
   {0,0,1},
   {0,2,2},
   {0,1,2},
   {1,2,2},
   {1,0,2},
   {-3,2,0},
   {-2,-2,0},
   {-2,-1,0},
   {-3,0,0},
   {-3,-1,0},
   {-2,2,0},
   {-3,1,0},
   {-2,4,0},
   {-2,5,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-3,-3,0},
   {-3,-2,0},
   {0,4,0},
   {0,5,0},
   {1,-3,0},
   {1,-2,0},
   {-3,3,0},
   {-2,3,0},
   {-3,5,0},
   {-2,-3,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-3,4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0}};

static struct patval joseki43[] = {
   {2,-1,1},
   {1,3,1},
   {2,1,1},
   {3,1,1},
   {1,0,1},
   {3,0,1},
   {2,2,2},
   {0,0,2},
   {1,1,2},
   {1,2,2},
   {-2,2,0},
   {-1,-1,0},
   {-2,1,0},
   {-2,-1,0},
   {-1,-2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-2,-3,0},
   {-2,-2,0},
   {1,4,0},
   {1,5,0},
   {2,-3,0},
   {2,-2,0},
   {-1,2,0},
   {2,0,0},
   {-2,5,0},
   {-1,-3,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {-2,3,0},
   {-2,4,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0}};

static struct patval joseki44[] = {
   {2,1,1},
   {3,1,1},
   {1,0,1},
   {1,3,1},
   {1,-1,1},
   {2,-1,1},
   {0,0,2},
   {2,2,2},
   {2,0,2},
   {1,2,2},
   {1,1,2},
   {-1,1,0},
   {-1,2,0},
   {-2,4,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-2,0},
   {-2,5,0},
   {-1,-2,0},
   {-1,3,0},
   {-1,0,0},
   {-2,3,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {-1,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {-2,-1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki45[] = {
   {0,0,1},
   {0,2,2},
   {-3,-2,0},
   {-3,-1,0},
   {-3,-4,0},
   {-3,1,0},
   {-3,-3,0},
   {-3,3,0},
   {-3,4,0},
   {-2,-4,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {-3,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0}};

static struct patval joseki46[] = {
   {0,5,1},
   {0,0,1},
   {0,3,2},
   {-3,2,0},
   {-3,-1,0},
   {-3,4,0},
   {-3,1,0},
   {-3,6,0},
   {-3,7,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-3,3,0},
   {0,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki47[] = {
   {0,3,1},
   {2,3,1},
   {0,0,2},
   {0,5,2},
   {-3,-1,0},
   {-3,4,0},
   {-3,2,0},
   {-3,6,0},
   {-3,7,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-3,3,0},
   {0,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki48[] = {
   {2,5,1},
   {0,0,1},
   {0,5,1},
   {0,3,2},
   {2,3,2},
   {-3,4,0},
   {-3,-1,0},
   {-3,6,0},
   {-3,7,0},
   {-2,-1,0},
   {-3,2,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {0,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki49[] = {
   {4,3,1},
   {0,3,1},
   {2,3,1},
   {2,5,2},
   {0,0,2},
   {0,5,2},
   {-3,-1,0},
   {-3,6,0},
   {-3,7,0},
   {-2,-1,0},
   {-3,2,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {0,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {-3,4,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki50[] = {
   {0,5,1},
   {4,5,1},
   {0,0,1},
   {2,5,1},
   {2,3,2},
   {4,3,2},
   {0,3,2},
   {-3,1,0},
   {-3,5,0},
   {-3,3,0},
   {-3,7,0},
   {-2,-3,0},
   {-2,-2,0},
   {-3,-2,0},
   {-2,0,0},
   {-3,-3,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-3,-1,0},
   {0,1,0},
   {0,2,0},
   {-2,-1,0},
   {0,4,0},
   {-2,1,0},
   {0,6,0},
   {0,7,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,0,0},
   {2,4,0},
   {-3,2,0},
   {2,6,0},
   {2,7,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {-3,4,0},
   {4,4,0},
   {-3,6,0},
   {4,6,0},
   {4,7,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki51[] = {
   {0,5,1},
   {0,0,1},
   {0,3,2},
   {-3,2,0},
   {-3,-1,0},
   {-3,4,0},
   {-3,1,0},
   {-3,6,0},
   {-3,7,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-3,3,0},
   {0,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki52[] = {
   {3,4,1},
   {0,3,1},
   {0,5,2},
   {0,0,2},
   {-3,2,0},
   {-3,4,0},
   {-3,1,0},
   {-3,6,0},
   {-3,7,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-3,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-3,3,0},
   {0,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki53[] = {
   {1,3,1},
   {0,0,1},
   {0,5,1},
   {0,3,2},
   {3,4,2},
   {-3,4,0},
   {-3,1,0},
   {-3,6,0},
   {-3,7,0},
   {-2,-1,0},
   {-3,2,0},
   {-2,1,0},
   {-3,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {0,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {-3,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki54[] = {
   {3,4,1},
   {0,3,1},
   {1,2,1},
   {0,5,2},
   {0,0,2},
   {1,3,2},
   {-3,1,0},
   {-3,6,0},
   {-3,7,0},
   {-2,-1,0},
   {-3,4,0},
   {-2,1,0},
   {-3,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {0,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-3,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki55[] = {
   {1,3,1},
   {0,0,1},
   {2,3,1},
   {0,5,1},
   {3,4,2},
   {0,3,2},
   {1,2,2},
   {-3,6,0},
   {-3,7,0},
   {-2,-1,0},
   {-3,4,0},
   {-2,1,0},
   {-3,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {0,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-3,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki56[] = {
   {3,4,1},
   {0,4,1},
   {0,3,1},
   {1,2,1},
   {2,3,2},
   {0,0,2},
   {0,5,2},
   {1,3,2},
   {-3,7,0},
   {-2,-1,0},
   {-3,6,0},
   {-2,1,0},
   {-3,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-3,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-3,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki57[] = {
   {1,4,1},
   {0,0,1},
   {2,3,1},
   {0,5,1},
   {1,3,1},
   {3,4,2},
   {1,2,2},
   {0,4,2},
   {0,3,2},
   {-2,-1,0},
   {-3,7,0},
   {-3,6,0},
   {-3,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-2,1,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-3,3,0},
   {-3,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki58[] = {
   {4,-1,1},
   {0,0,1},
   {1,-1,1},
   {2,-3,1},
   {1,-2,1},
   {3,-2,2},
   {1,0,2},
   {2,-1,2},
   {1,-5,2},
   {2,-2,2},
   {-1,-6,0},
   {-2,1,0},
   {-2,-6,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {1,-6,0},
   {-2,-5,0},
   {1,-4,0},
   {1,-3,0},
   {-1,-5,0},
   {-1,-4,0},
   {-2,0,0},
   {1,1,0},
   {1,2,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-4,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-3,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0}};

static struct patval joseki59[] = {
   {1,0,1},
   {1,-5,1},
   {3,-2,1},
   {2,0,1},
   {2,-2,1},
   {2,-1,1},
   {2,-3,2},
   {1,-1,2},
   {0,0,2},
   {4,-1,2},
   {1,-2,2},
   {-2,1,0},
   {-1,-6,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-2,-6,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {1,-6,0},
   {-2,-5,0},
   {1,-4,0},
   {1,-3,0},
   {-1,-5,0},
   {-1,-4,0},
   {-1,2,0},
   {1,1,0},
   {1,2,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-4,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-3,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0}};

static struct patval joseki60[] = {
   {0,0,1},
   {0,3,1},
   {1,2,1},
   {2,0,1},
   {1,1,1},
   {4,2,1},
   {2,3,2},
   {3,1,2},
   {1,-2,2},
   {1,3,2},
   {2,1,2},
   {2,2,2},
   {-1,-3,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-2,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {0,1,0},
   {0,2,0},
   {-2,5,0},
   {0,4,0},
   {0,5,0},
   {1,-3,0},
   {-2,-2,0},
   {1,-1,0},
   {1,0,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,5,0},
   {1,4,0},
   {1,5,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {-2,-1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {-1,0,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki61[] = {
   {1,3,1},
   {1,-2,1},
   {3,1,1},
   {2,3,1},
   {2,1,1},
   {2,2,1},
   {0,4,1},
   {0,0,2},
   {0,3,2},
   {2,0,2},
   {1,1,2},
   {1,2,2},
   {4,2,2},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-2,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {0,1,0},
   {0,2,0},
   {-2,5,0},
   {-1,-3,0},
   {0,5,0},
   {1,-3,0},
   {-2,-2,0},
   {1,-1,0},
   {1,0,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,5,0},
   {1,4,0},
   {1,5,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {-2,-1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {-1,0,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki62[] = {
   {3,4,1},
   {0,4,1},
   {0,3,1},
   {1,2,1},
   {2,3,2},
   {0,0,2},
   {0,5,2},
   {1,3,2},
   {-3,7,0},
   {-2,-1,0},
   {-3,6,0},
   {-2,1,0},
   {-3,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-3,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-3,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki63[] = {
   {2,5,1},
   {0,0,1},
   {2,3,1},
   {0,5,1},
   {1,3,1},
   {0,4,2},
   {1,2,2},
   {0,3,2},
   {3,4,2},
   {-2,-1,0},
   {-3,6,0},
   {-2,1,0},
   {-3,-1,0},
   {-3,7,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-3,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-2,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki64[] = {
   {4,-1,1},
   {0,0,1},
   {1,-1,1},
   {2,-3,1},
   {1,-2,1},
   {3,-2,2},
   {1,0,2},
   {3,0,2},
   {1,-5,2},
   {2,-2,2},
   {-2,1,0},
   {-1,-4,0},
   {-2,-6,0},
   {-1,-6,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {1,-6,0},
   {-2,-5,0},
   {1,-4,0},
   {1,-3,0},
   {-1,-5,0},
   {-2,-1,0},
   {-2,0,0},
   {1,1,0},
   {1,2,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-2,-3,0},
   {-1,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-4,0},
   {3,-1,0},
   {-2,-2,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-3,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0}};

static struct patval joseki65[] = {
   {1,0,1},
   {1,-5,1},
   {3,-2,1},
   {2,0,1},
   {3,0,1},
   {2,-2,1},
   {2,-3,2},
   {1,-2,2},
   {1,-1,2},
   {0,0,2},
   {4,-1,2},
   {-1,-4,0},
   {-2,1,0},
   {-1,-6,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-2,-6,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {1,-6,0},
   {-2,-5,0},
   {1,-4,0},
   {1,-3,0},
   {-1,-5,0},
   {-2,-1,0},
   {-1,2,0},
   {1,1,0},
   {1,2,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-2,-3,0},
   {-1,-2,0},
   {2,-1,0},
   {-2,0,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-4,0},
   {3,-1,0},
   {-2,-2,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-3,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0}};

static struct patval joseki66[] = {
   {0,0,1},
   {0,3,1},
   {1,2,1},
   {2,0,1},
   {1,1,1},
   {4,2,1},
   {2,3,2},
   {3,1,2},
   {1,-2,2},
   {2,1,2},
   {3,3,2},
   {1,3,2},
   {-1,-1,0},
   {-1,-3,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-2,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {0,1,0},
   {0,2,0},
   {-2,5,0},
   {0,4,0},
   {0,5,0},
   {1,-3,0},
   {-2,-2,0},
   {1,-1,0},
   {1,0,0},
   {-1,-2,0},
   {-2,2,0},
   {-1,5,0},
   {1,4,0},
   {1,5,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {-2,0,0},
   {-1,1,0},
   {2,2,0},
   {-2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {-2,-1,0},
   {3,2,0},
   {-2,1,0},
   {3,4,0},
   {3,5,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {-1,0,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki67[] = {
   {1,3,1},
   {1,-2,1},
   {3,1,1},
   {2,3,1},
   {3,3,1},
   {0,4,1},
   {2,1,1},
   {0,0,2},
   {2,0,2},
   {1,2,2},
   {1,1,2},
   {0,3,2},
   {4,2,2},
   {-1,-1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-2,4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {0,1,0},
   {0,2,0},
   {-2,5,0},
   {-1,-3,0},
   {0,5,0},
   {1,-3,0},
   {-2,-2,0},
   {1,-1,0},
   {1,0,0},
   {-1,-2,0},
   {-2,2,0},
   {-1,5,0},
   {1,4,0},
   {1,5,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {-2,0,0},
   {-1,1,0},
   {2,2,0},
   {-2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {-2,-1,0},
   {3,2,0},
   {-2,1,0},
   {3,4,0},
   {3,5,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {-1,0,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki68[] = {
   {0,0,1},
   {5,-1,1},
   {1,-3,1},
   {2,-2,1},
   {1,0,1},
   {3,-3,1},
   {2,-1,1},
   {4,0,2},
   {3,0,2},
   {4,-2,2},
   {2,-5,2},
   {1,1,2},
   {3,-2,2},
   {2,0,2},
   {0,-6,0},
   {-1,-3,0},
   {0,1,0},
   {0,2,0},
   {0,-1,0},
   {1,-5,0},
   {1,-4,0},
   {-1,-6,0},
   {1,-2,0},
   {1,-1,0},
   {-1,-2,0},
   {0,-5,0},
   {1,2,0},
   {2,-6,0},
   {-1,-4,0},
   {2,-4,0},
   {2,-3,0},
   {0,-4,0},
   {0,-3,0},
   {1,-6,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {0,-2,0},
   {-1,0,0},
   {3,-1,0},
   {-1,2,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {-1,-1,0},
   {4,-1,0},
   {-1,1,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {-1,-5,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {7,-6,0},
   {7,-5,0},
   {7,-4,0},
   {7,-3,0},
   {7,-2,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0},
   {8,-6,0},
   {8,-5,0},
   {8,-4,0},
   {8,-3,0},
   {8,-2,0},
   {8,-1,0},
   {8,0,0},
   {8,1,0},
   {8,2,0},
   {9,-6,0},
   {9,-5,0},
   {9,-4,0},
   {9,-3,0},
   {9,-2,0},
   {9,-1,0},
   {9,0,0},
   {9,1,0},
   {9,2,0}};

static struct patval joseki69[] = {
   {1,-3,1},
   {5,-1,1},
   {3,-3,1},
   {2,-2,1},
   {2,-1,1},
   {1,0,1},
   {0,0,1},
   {2,-5,2},
   {3,0,2},
   {1,1,2},
   {3,-2,2},
   {4,0,2},
   {2,0,2},
   {4,-2,2},
   {0,-2,0},
   {-1,0,0},
   {0,1,0},
   {0,2,0},
   {1,-6,0},
   {-1,-5,0},
   {1,-4,0},
   {0,-1,0},
   {1,-2,0},
   {1,-1,0},
   {-1,2,0},
   {0,-6,0},
   {1,2,0},
   {2,-6,0},
   {-1,1,0},
   {2,-4,0},
   {2,-3,0},
   {1,-5,0},
   {-1,-2,0},
   {0,-3,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {0,-4,0},
   {-1,-3,0},
   {3,-1,0},
   {-1,-1,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {-1,-6,0},
   {4,-1,0},
   {-1,-4,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {0,-5,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {7,-6,0},
   {7,-5,0},
   {7,-4,0},
   {7,-3,0},
   {7,-2,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0},
   {8,-6,0},
   {8,-5,0},
   {8,-4,0},
   {8,-3,0},
   {8,-2,0},
   {8,-1,0},
   {8,0,0},
   {8,1,0},
   {8,2,0},
   {9,-6,0},
   {9,-5,0},
   {9,-4,0},
   {9,-3,0},
   {9,-2,0},
   {9,-1,0},
   {9,0,0},
   {9,1,0},
   {9,2,0},
   {10,-6,0},
   {10,-5,0},
   {10,-4,0},
   {10,-3,0},
   {10,-2,0},
   {10,-1,0},
   {10,0,0},
   {10,1,0},
   {10,2,0}};

static struct patval joseki70[] = {
   {2,-2,1},
   {2,-1,1},
   {1,0,1},
   {1,-3,1},
   {0,0,1},
   {3,-3,1},
   {5,-1,1},
   {1,1,2},
   {4,0,2},
   {3,-2,2},
   {2,0,2},
   {2,-5,2},
   {3,0,2},
   {4,-2,2},
   {0,-3,0},
   {0,-4,0},
   {0,1,0},
   {0,2,0},
   {1,-6,0},
   {1,-5,0},
   {1,-4,0},
   {-1,-1,0},
   {1,-2,0},
   {1,-1,0},
   {0,-2,0},
   {-1,1,0},
   {1,2,0},
   {2,-6,0},
   {-1,-2,0},
   {2,-4,0},
   {2,-3,0},
   {-1,-6,0},
   {0,-1,0},
   {-1,-4,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {-1,-3,0},
   {0,-6,0},
   {3,-1,0},
   {-1,-5,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {-1,2,0},
   {4,-1,0},
   {0,-5,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {-1,0,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {7,-6,0},
   {7,-5,0},
   {7,-4,0},
   {7,-3,0},
   {7,-2,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0},
   {8,-6,0},
   {8,-5,0},
   {8,-4,0},
   {8,-3,0},
   {8,-2,0},
   {8,-1,0},
   {8,0,0},
   {8,1,0},
   {8,2,0},
   {9,-6,0},
   {9,-5,0},
   {9,-4,0},
   {9,-3,0},
   {9,-2,0},
   {9,-1,0},
   {9,0,0},
   {9,1,0},
   {9,2,0},
   {10,-6,0},
   {10,-5,0},
   {10,-4,0},
   {10,-3,0},
   {10,-2,0},
   {10,-1,0},
   {10,0,0},
   {10,1,0},
   {10,2,0},
   {11,-6,0},
   {11,-5,0},
   {11,-4,0},
   {11,-3,0},
   {11,-2,0},
   {11,-1,0},
   {11,0,0},
   {11,1,0},
   {11,2,0}};

static struct patval joseki71[] = {
   {2,5,1},
   {0,0,1},
   {2,3,1},
   {0,5,1},
   {1,3,1},
   {0,4,2},
   {1,2,2},
   {0,3,2},
   {3,4,2},
   {-2,-1,0},
   {-3,6,0},
   {-2,1,0},
   {-3,-1,0},
   {-3,7,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-3,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-2,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki72[] = {
   {3,4,1},
   {2,2,1},
   {0,4,1},
   {1,2,1},
   {0,3,1},
   {2,3,2},
   {0,5,2},
   {0,0,2},
   {1,3,2},
   {2,5,2},
   {-2,-1,0},
   {-2,1,0},
   {-3,-1,0},
   {-3,7,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,6,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-3,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-2,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-3,0,0},
   {-3,1,0},
   {2,4,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki73[] = {
   {2,5,1},
   {0,0,1},
   {2,3,1},
   {0,5,1},
   {1,3,1},
   {3,3,1},
   {1,2,2},
   {0,4,2},
   {3,4,2},
   {2,2,2},
   {0,3,2},
   {-2,-1,0},
   {-3,-1,0},
   {-3,7,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,6,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-3,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-2,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-3,0,0},
   {-3,1,0},
   {2,4,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {-2,1,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki74[] = {
   {4,-1,1},
   {3,-3,1},
   {1,-1,1},
   {2,-3,1},
   {1,-2,1},
   {0,0,1},
   {1,0,2},
   {1,-5,2},
   {3,-2,2},
   {2,-2,2},
   {3,0,2},
   {4,-2,2},
   {-2,-6,0},
   {-1,-6,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {1,-6,0},
   {-2,1,0},
   {1,-4,0},
   {1,-3,0},
   {-1,-5,0},
   {-2,-1,0},
   {-2,0,0},
   {1,1,0},
   {1,2,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-2,-3,0},
   {-1,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {-2,-5,0},
   {-2,-4,0},
   {3,-1,0},
   {-2,-2,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {-1,-4,0},
   {-1,-3,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0}};

static struct patval joseki75[] = {
   {1,0,1},
   {1,-5,1},
   {3,-2,1},
   {2,0,1},
   {3,0,1},
   {2,-2,1},
   {4,-2,1},
   {2,-3,2},
   {1,-1,2},
   {0,0,2},
   {1,-2,2},
   {3,-3,2},
   {4,-1,2},
   {-1,-6,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-2,-6,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {1,-6,0},
   {-2,1,0},
   {1,-4,0},
   {1,-3,0},
   {-1,-5,0},
   {-2,-1,0},
   {-1,2,0},
   {1,1,0},
   {1,2,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-2,-3,0},
   {-1,-2,0},
   {2,-1,0},
   {-2,0,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {-2,-5,0},
   {-2,-4,0},
   {3,-1,0},
   {-2,-2,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {-1,-4,0},
   {-1,-3,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0}};

static struct patval joseki76[] = {
   {2,-1,1},
   {2,0,1},
   {1,1,1},
   {0,0,1},
   {3,-2,1},
   {4,-2,1},
   {5,0,1},
   {5,-1,2},
   {2,-4,2},
   {3,-1,2},
   {2,1,2},
   {4,-1,2},
   {3,1,2},
   {4,1,2},
   {-1,-2,0},
   {0,-3,0},
   {0,2,0},
   {0,3,0},
   {0,-2,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {0,-1,0},
   {1,2,0},
   {1,3,0},
   {2,-5,0},
   {-1,-1,0},
   {2,-3,0},
   {2,-2,0},
   {-1,-5,0},
   {1,-5,0},
   {-1,-3,0},
   {2,2,0},
   {2,3,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {0,1,0},
   {0,-5,0},
   {3,0,0},
   {-1,-4,0},
   {3,2,0},
   {3,3,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {-1,2,0},
   {-1,3,0},
   {4,0,0},
   {0,-4,0},
   {4,2,0},
   {4,3,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {-1,0,0},
   {-1,1,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {7,-5,0},
   {7,-4,0},
   {7,-3,0},
   {7,-2,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0},
   {7,3,0},
   {8,-5,0},
   {8,-4,0},
   {8,-3,0},
   {8,-2,0},
   {8,-1,0},
   {8,0,0},
   {8,1,0},
   {8,2,0},
   {8,3,0},
   {9,-5,0},
   {9,-4,0},
   {9,-3,0},
   {9,-2,0},
   {9,-1,0},
   {9,0,0},
   {9,1,0},
   {9,2,0},
   {9,3,0},
   {10,-5,0},
   {10,-4,0},
   {10,-3,0},
   {10,-2,0},
   {10,-1,0},
   {10,0,0},
   {10,1,0},
   {10,2,0},
   {10,3,0},
   {11,-5,0},
   {11,-4,0},
   {11,-3,0},
   {11,-2,0},
   {11,-1,0},
   {11,0,0},
   {11,1,0},
   {11,2,0},
   {11,3,0}};

static struct patval joseki77[] = {
   {0,0,1},
   {5,0,1},
   {3,-2,1},
   {2,-1,1},
   {2,0,1},
   {1,1,1},
   {4,-2,1},
   {2,-4,2},
   {4,-1,2},
   {5,-1,2},
   {3,-1,2},
   {4,1,2},
   {2,1,2},
   {3,1,2},
   {0,-1,0},
   {-1,-4,0},
   {0,2,0},
   {0,3,0},
   {-1,1,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {-1,3,0},
   {1,2,0},
   {1,3,0},
   {2,-5,0},
   {-1,2,0},
   {2,-3,0},
   {2,-2,0},
   {0,1,0},
   {-1,-1,0},
   {0,-2,0},
   {2,2,0},
   {2,3,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {1,-5,0},
   {-1,-2,0},
   {3,0,0},
   {-1,0,0},
   {3,2,0},
   {3,3,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {0,-3,0},
   {-1,-5,0},
   {4,0,0},
   {-1,-3,0},
   {4,2,0},
   {4,3,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {0,-5,0},
   {0,-4,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {7,-5,0},
   {7,-4,0},
   {7,-3,0},
   {7,-2,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0},
   {7,3,0},
   {8,-5,0},
   {8,-4,0},
   {8,-3,0},
   {8,-2,0},
   {8,-1,0},
   {8,0,0},
   {8,1,0},
   {8,2,0},
   {8,3,0},
   {9,-5,0},
   {9,-4,0},
   {9,-3,0},
   {9,-2,0},
   {9,-1,0},
   {9,0,0},
   {9,1,0},
   {9,2,0},
   {9,3,0},
   {10,-5,0},
   {10,-4,0},
   {10,-3,0},
   {10,-2,0},
   {10,-1,0},
   {10,0,0},
   {10,1,0},
   {10,2,0},
   {10,3,0}};

static struct patval joseki78[] = {
   {1,0,1},
   {1,-5,1},
   {3,-2,1},
   {2,0,1},
   {3,0,1},
   {2,-2,1},
   {4,-2,1},
   {2,-3,2},
   {1,-1,2},
   {0,0,2},
   {1,-2,2},
   {3,-3,2},
   {4,-1,2},
   {-1,-6,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-2,-6,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {1,-6,0},
   {-2,1,0},
   {1,-4,0},
   {1,-3,0},
   {-1,-5,0},
   {-2,-1,0},
   {-1,2,0},
   {1,1,0},
   {1,2,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-2,-3,0},
   {-1,-2,0},
   {2,-1,0},
   {-2,0,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {-2,-5,0},
   {-2,-4,0},
   {3,-1,0},
   {-2,-2,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {-1,-4,0},
   {-1,-3,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0}};

static struct patval joseki79[] = {
   {1,-2,1},
   {1,-1,1},
   {0,0,1},
   {0,1,1},
   {2,-3,1},
   {3,-3,1},
   {4,-1,1},
   {4,-2,2},
   {1,-5,2},
   {2,-2,2},
   {1,0,2},
   {2,0,2},
   {3,-2,2},
   {3,0,2},
   {-2,-3,0},
   {-1,-3,0},
   {-1,1,0},
   {-1,2,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-2,0},
   {-1,-4,0},
   {0,2,0},
   {1,-6,0},
   {-2,-2,0},
   {1,-4,0},
   {1,-3,0},
   {-2,-6,0},
   {-1,-1,0},
   {-2,-4,0},
   {1,1,0},
   {1,2,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-1,0,0},
   {-1,-6,0},
   {2,-1,0},
   {-2,-5,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {-2,1,0},
   {-2,2,0},
   {3,-1,0},
   {-1,-5,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {-2,-1,0},
   {-2,0,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {7,-6,0},
   {7,-5,0},
   {7,-4,0},
   {7,-3,0},
   {7,-2,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0}};

static struct patval joseki80[] = {
   {3,-2,1},
   {2,0,1},
   {1,0,1},
   {2,-2,1},
   {1,-5,1},
   {4,-2,1},
   {3,0,1},
   {6,-1,1},
   {3,-3,2},
   {1,-1,2},
   {4,-1,2},
   {0,1,2},
   {1,-2,2},
   {0,0,2},
   {2,-3,2},
   {-2,-3,0},
   {-1,1,0},
   {-1,2,0},
   {-1,-3,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-2,0},
   {-1,-4,0},
   {0,2,0},
   {1,-6,0},
   {-2,-2,0},
   {1,-4,0},
   {1,-3,0},
   {-2,-6,0},
   {-1,-1,0},
   {-2,-4,0},
   {1,1,0},
   {1,2,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-1,0,0},
   {-1,-6,0},
   {2,-1,0},
   {-2,-5,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {-2,1,0},
   {0,-6,0},
   {3,-1,0},
   {-1,-5,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {-2,-1,0},
   {-2,0,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {-2,2,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {7,-6,0},
   {7,-5,0},
   {7,-4,0},
   {7,-3,0},
   {7,-2,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0}};

static struct patval joseki81[] = {
   {2,5,1},
   {0,0,1},
   {2,3,1},
   {0,5,1},
   {1,3,1},
   {0,4,2},
   {1,2,2},
   {0,3,2},
   {3,4,2},
   {-2,-1,0},
   {-3,6,0},
   {-2,1,0},
   {-3,-1,0},
   {-3,7,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-3,4,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-2,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki82[] = {
   {3,4,1},
   {1,4,1},
   {0,4,1},
   {1,2,1},
   {0,3,1},
   {0,0,2},
   {0,5,2},
   {2,3,2},
   {1,3,2},
   {2,5,2},
   {-2,-1,0},
   {-3,6,0},
   {-3,-1,0},
   {-3,7,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-2,1,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-3,2,0},
   {-2,3,0},
   {-3,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {2,4,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki83[] = {
   {2,5,1},
   {0,0,1},
   {2,3,1},
   {2,4,1},
   {1,3,1},
   {0,5,1},
   {1,4,2},
   {0,4,2},
   {3,4,2},
   {1,2,2},
   {0,3,2},
   {-3,6,0},
   {-3,-1,0},
   {-3,7,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-2,7,0},
   {-2,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-2,1,0},
   {-3,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-1,-1,0},
   {-2,3,0},
   {-3,4,0},
   {1,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {-3,2,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki84[] = {
   {3,4,1},
   {1,5,1},
   {0,4,1},
   {1,2,1},
   {0,3,1},
   {1,4,1},
   {0,0,2},
   {2,3,2},
   {0,5,2},
   {2,4,2},
   {2,5,2},
   {1,3,2},
   {-3,-1,0},
   {-3,6,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-3,7,0},
   {-2,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {0,2,0},
   {-2,0,0},
   {-2,1,0},
   {-2,7,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-1,-1,0},
   {-2,3,0},
   {-3,4,0},
   {-3,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {-3,2,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki85[] = {
   {0,2,1},
   {0,0,1},
   {2,3,1},
   {2,4,1},
   {2,5,1},
   {1,3,1},
   {0,5,1},
   {0,4,2},
   {1,4,2},
   {3,4,2},
   {0,3,2},
   {1,2,2},
   {1,5,2},
   {-3,-1,0},
   {-3,6,0},
   {-2,5,0},
   {-2,6,0},
   {-3,7,0},
   {-2,4,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,7,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-1,-1,0},
   {-2,3,0},
   {-3,4,0},
   {-3,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {-3,2,0},
   {-3,3,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki86[] = {
   {3,4,1},
   {1,5,1},
   {1,4,1},
   {1,2,1},
   {0,3,1},
   {2,6,1},
   {0,4,1},
   {2,3,2},
   {0,5,2},
   {0,2,2},
   {2,5,2},
   {0,0,2},
   {2,4,2},
   {1,3,2},
   {-3,-1,0},
   {-2,5,0},
   {-2,6,0},
   {-3,7,0},
   {-3,6,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,7,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-1,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-3,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {-3,2,0},
   {-3,3,0},
   {-3,4,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki87[] = {
   {0,2,1},
   {0,0,1},
   {2,3,1},
   {2,4,1},
   {2,5,1},
   {3,6,1},
   {0,5,1},
   {1,3,1},
   {2,6,2},
   {3,4,2},
   {0,3,2},
   {0,4,2},
   {1,5,2},
   {1,4,2},
   {1,2,2},
   {-2,5,0},
   {-2,6,0},
   {-3,-1,0},
   {-3,6,0},
   {-1,0,0},
   {-3,7,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,7,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-1,-1,0},
   {-2,3,0},
   {-1,1,0},
   {-3,5,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {-3,2,0},
   {-3,3,0},
   {-3,4,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {-2,4,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki88[] = {
   {3,4,1},
   {1,5,1},
   {1,4,1},
   {1,2,1},
   {0,3,1},
   {2,6,1},
   {0,4,1},
   {1,6,1},
   {3,6,2},
   {0,2,2},
   {2,5,2},
   {0,0,2},
   {0,5,2},
   {1,3,2},
   {2,3,2},
   {2,4,2},
   {-2,6,0},
   {-3,-1,0},
   {-2,5,0},
   {-1,0,0},
   {-3,7,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,7,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-1,-1,0},
   {-2,3,0},
   {-1,1,0},
   {-3,5,0},
   {-3,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {-3,2,0},
   {-3,3,0},
   {-3,4,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {3,5,0},
   {-2,4,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki89[] = {
   {0,2,1},
   {0,0,1},
   {2,3,1},
   {2,4,1},
   {2,5,1},
   {3,6,1},
   {0,5,1},
   {1,3,1},
   {3,5,1},
   {3,4,2},
   {0,3,2},
   {0,4,2},
   {1,6,2},
   {1,4,2},
   {2,6,2},
   {1,2,2},
   {1,5,2},
   {-2,6,0},
   {-2,5,0},
   {-3,-1,0},
   {-3,7,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-3,0,0},
   {0,1,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,7,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-3,5,0},
   {-3,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-3,1,0},
   {-3,2,0},
   {-3,3,0},
   {-3,4,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0}};

static struct patval joseki90[] = {
   {0,0,1},
   {2,3,1},
   {2,2,1},
   {2,0,1},
   {1,1,1},
   {3,4,1},
   {1,2,1},
   {2,4,1},
   {4,2,1},
   {1,0,2},
   {3,3,2},
   {1,-2,2},
   {4,4,2},
   {4,3,2},
   {3,1,2},
   {2,1,2},
   {3,2,2},
   {1,3,2},
   {-1,4,0},
   {-1,3,0},
   {-2,5,0},
   {-2,-3,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-3,0},
   {-2,-2,0},
   {1,-1,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,5,0},
   {1,4,0},
   {1,5,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,3,0},
   {-2,4,0},
   {2,5,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {3,5,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {4,5,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0}};

static struct patval joseki91[] = {
   {0,0,1},
   {1,2,2},
   {-2,0,0},
   {-2,1,0},
   {-2,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,2,0},
   {1,3,0},
   {1,4,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki92[] = {
   {1,2,1},
   {2,1,1},
   {0,0,2},
   {-2,-1,0},
   {-2,-2,0},
   {-2,-4,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-3,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-2,0,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki93[] = {
   {0,0,1},
   {1,-2,1},
   {1,2,2},
   {2,1,2},
   {-2,-5,0},
   {-2,0,0},
   {-2,-3,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,-2,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-1,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {-2,1,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,-4,0},
   {1,3,0},
   {1,4,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-1,-5,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0}};

static struct patval joseki94[] = {
   {2,1,1},
   {1,2,1},
   {0,1,1},
   {0,0,2},
   {1,-2,2},
   {-2,-4,0},
   {-2,-2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,-1,0},
   {-1,-3,0},
   {-1,-2,0},
   {-2,2,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {-1,-1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {1,-3,0},
   {-2,1,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,-3,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-1,-4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0}};

static struct patval joseki95[] = {
   {2,1,1},
   {1,2,1},
   {0,0,2},
   {-2,-2,0},
   {-2,-4,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-5,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-1,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,-3,0},
   {1,3,0},
   {1,4,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-2,-5,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0}};

static struct patval joseki96[] = {
   {2,6,1},
   {0,0,1},
   {1,7,1},
   {0,2,2},
   {0,5,2},
   {-2,3,0},
   {-2,2,0},
   {-2,6,0},
   {-2,0,0},
   {-2,8,0},
   {-2,9,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {-1,8,0},
   {-1,9,0},
   {0,-1,0},
   {-2,5,0},
   {0,1,0},
   {-2,7,0},
   {0,3,0},
   {0,4,0},
   {-2,4,0},
   {0,6,0},
   {0,7,0},
   {0,8,0},
   {0,9,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {1,4,0},
   {1,5,0},
   {1,6,0},
   {-2,1,0},
   {1,8,0},
   {1,9,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {-2,-1,0},
   {2,7,0},
   {2,8,0},
   {2,9,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {3,8,0},
   {3,9,0}};

static struct patval joseki97[] = {
   {0,0,1},
   {1,2,2},
   {2,1,2},
   {-2,0,0},
   {-2,-1,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,2,0},
   {1,3,0},
   {1,4,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki98[] = {
   {1,-1,1},
   {1,2,1},
   {2,1,1},
   {0,0,2},
   {-2,-2,0},
   {-2,1,0},
   {-2,-4,0},
   {-2,3,0},
   {-2,4,0},
   {-2,-1,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {-2,2,0},
   {1,0,0},
   {1,1,0},
   {-2,-3,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {-1,-4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0}};

static struct patval joseki99[] = {
   {0,2,1},
   {0,0,1},
   {1,4,2},
   {2,3,2},
   {1,1,2},
   {-2,3,0},
   {-2,-2,0},
   {-2,5,0},
   {-2,6,0},
   {-2,1,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {0,1,0},
   {-2,2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {0,6,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {-2,4,0},
   {1,2,0},
   {1,3,0},
   {-2,-1,0},
   {1,5,0},
   {1,6,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-1,-2,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0}};

static struct patval joseki100[] = {
   {0,2,1},
   {0,1,1},
   {0,0,1},
   {1,4,2},
   {1,1,2},
   {0,3,2},
   {2,3,2},
   {-2,0,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {0,-1,0},
   {-2,5,0},
   {-2,6,0},
   {-2,3,0},
   {-2,4,0},
   {0,4,0},
   {0,5,0},
   {0,6,0},
   {1,-1,0},
   {1,0,0},
   {-2,-1,0},
   {1,2,0},
   {1,3,0},
   {-2,2,0},
   {1,5,0},
   {1,6,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {-2,1,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0},
   {6,6,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0},
   {7,3,0},
   {7,4,0},
   {7,5,0},
   {7,6,0},
   {8,-1,0},
   {8,0,0},
   {8,1,0},
   {8,2,0},
   {8,3,0},
   {8,4,0},
   {8,5,0},
   {8,6,0},
   {9,-1,0},
   {9,0,0},
   {9,1,0},
   {9,2,0},
   {9,3,0},
   {9,4,0},
   {9,5,0},
   {9,6,0}};

static struct patval joseki101[] = {
   {0,1,1},
   {0,0,1},
   {1,3,2},
   {1,0,2},
   {2,2,2},
   {-2,-2,0},
   {-2,4,0},
   {-2,5,0},
   {-2,2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {-2,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-2,0},
   {1,-1,0},
   {-2,3,0},
   {1,1,0},
   {1,2,0},
   {-2,-1,0},
   {1,4,0},
   {1,5,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-1,-2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0}};

static struct patval joseki102[] = {
   {1,0,1},
   {1,3,1},
   {1,-1,1},
   {2,2,1},
   {0,1,2},
   {0,0,2},
   {-2,-1,0},
   {-2,4,0},
   {-2,5,0},
   {-2,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {-2,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {1,-3,0},
   {1,-2,0},
   {-2,2,0},
   {-2,3,0},
   {1,1,0},
   {1,2,0},
   {-2,-2,0},
   {1,4,0},
   {1,5,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-1,-3,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0}};

static struct patval joseki103[] = {
   {0,0,1},
   {0,2,1},
   {0,3,1},
   {1,1,2},
   {1,2,2},
   {1,5,2},
   {2,4,2},
   {-2,5,0},
   {-2,-1,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-2,4,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {-1,7,0},
   {0,-1,0},
   {-2,7,0},
   {0,1,0},
   {-2,0,0},
   {-2,1,0},
   {0,4,0},
   {0,5,0},
   {0,6,0},
   {0,7,0},
   {1,-1,0},
   {1,0,0},
   {-2,2,0},
   {-2,3,0},
   {1,3,0},
   {1,4,0},
   {-1,3,0},
   {1,6,0},
   {1,7,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {-2,6,0},
   {2,5,0},
   {2,6,0},
   {2,7,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {3,7,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {4,7,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0},
   {5,7,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {6,5,0},
   {6,6,0},
   {6,7,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0},
   {7,3,0},
   {7,4,0},
   {7,5,0},
   {7,6,0},
   {7,7,0},
   {8,-1,0},
   {8,0,0},
   {8,1,0},
   {8,2,0},
   {8,3,0},
   {8,4,0},
   {8,5,0},
   {8,6,0},
   {8,7,0}};

static struct patval joseki104[] = {
   {0,0,1},
   {1,2,2},
   {-2,-6,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,-5,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-6,0},
   {-1,-5,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-4,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-6,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki105[] = {
   {1,2,1},
   {1,-3,1},
   {0,0,2},
   {-2,-4,0},
   {-2,0,0},
   {-2,1,0},
   {-2,-2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-2,-1,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-3,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {-2,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,2,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki106[] = {
   {3,0,1},
   {0,0,1},
   {1,-3,2},
   {1,2,2},
   {-2,0,0},
   {-2,1,0},
   {-2,-4,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-2,-1,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-3,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {-2,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,2,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {-2,-2,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki107[] = {
   {0,0,1},
   {3,0,1},
   {1,-3,2},
   {1,2,2},
   {-2,-3,0},
   {-2,-5,0},
   {-2,1,0},
   {-2,2,0},
   {-2,-2,0},
   {-2,4,0},
   {-1,-5,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-1,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-5,0},
   {1,-4,0},
   {-2,0,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,-4,0},
   {1,3,0},
   {1,4,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {-2,3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0}};

static struct patval joseki108[] = {
   {2,0,1},
   {1,-3,1},
   {1,2,1},
   {0,0,2},
   {3,0,2},
   {-2,1,0},
   {-2,-4,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-2,-1,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-3,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {-2,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,2,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {-2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {-2,-2,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki109[] = {
   {2,-1,1},
   {3,0,1},
   {0,0,1},
   {1,-3,2},
   {2,0,2},
   {1,2,2},
   {-2,0,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {-2,-4,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {-2,-2,0},
   {-2,-1,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {-2,-3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki110[] = {
   {2,0,1},
   {1,2,1},
   {1,-3,1},
   {2,1,1},
   {0,0,2},
   {3,0,2},
   {2,-1,2},
   {-2,-2,0},
   {-2,2,0},
   {-2,1,0},
   {-1,-3,0},
   {-2,-4,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-2,-1,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {-2,0,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,-3,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {-1,2,0},
   {-2,4,0},
   {-1,-4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {-2,3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0}};

static struct patval joseki111[] = {
   {1,-1,1},
   {2,-1,1},
   {0,0,1},
   {3,0,1},
   {2,0,2},
   {2,1,2},
   {1,2,2},
   {1,-3,2},
   {-2,-2,0},
   {-2,1,0},
   {-1,-3,0},
   {-2,-4,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-2,-1,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {-2,0,0},
   {1,-2,0},
   {-2,2,0},
   {1,0,0},
   {1,1,0},
   {-2,-3,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {-1,2,0},
   {-2,4,0},
   {-1,-4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {-2,3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0}};

static struct patval joseki112[] = {
   {1,-3,1},
   {3,-1,1},
   {1,2,1},
   {2,1,1},
   {2,0,1},
   {2,-1,2},
   {3,0,2},
   {1,-1,2},
   {0,0,2},
   {-2,-4,0},
   {-2,4,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-3,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {-2,3,0},
   {1,-2,0},
   {-1,-4,0},
   {1,0,0},
   {1,1,0},
   {-2,2,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {-2,-3,0},
   {-2,-2,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki113[] = {
   {3,-2,1},
   {0,0,1},
   {3,0,1},
   {2,-1,1},
   {1,-1,1},
   {2,1,2},
   {1,2,2},
   {3,-1,2},
   {1,-3,2},
   {2,0,2},
   {-2,4,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-5,0},
   {1,-4,0},
   {-2,3,0},
   {1,-2,0},
   {-1,-5,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-5,0},
   {-2,-4,0},
   {-2,-3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki114[] = {
   {4,-1,1},
   {3,-1,1},
   {1,-3,1},
   {1,2,1},
   {2,0,1},
   {2,1,1},
   {2,-1,2},
   {0,0,2},
   {3,0,2},
   {3,-2,2},
   {1,-1,2},
   {-2,4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-5,0},
   {1,-4,0},
   {-2,3,0},
   {1,-2,0},
   {-1,-5,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-5,0},
   {-2,-4,0},
   {-2,-3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-4,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki115[] = {
   {3,-2,1},
   {2,-3,1},
   {3,0,1},
   {2,-1,1},
   {1,-1,1},
   {0,0,1},
   {1,2,2},
   {2,1,2},
   {1,-3,2},
   {3,-1,2},
   {2,0,2},
   {4,-1,2},
   {-2,4,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,-3,0},
   {-1,4,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-5,0},
   {1,-4,0},
   {-2,3,0},
   {1,-2,0},
   {-1,-5,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-5,0},
   {2,-4,0},
   {-1,3,0},
   {2,-2,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-5,0},
   {-2,-4,0},
   {-2,-3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-4,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki116[] = {
   {4,-1,1},
   {3,-1,1},
   {1,-3,1},
   {1,2,1},
   {2,0,1},
   {2,1,1},
   {4,0,1},
   {0,0,2},
   {2,-1,2},
   {3,0,2},
   {1,-1,2},
   {3,-2,2},
   {2,-3,2},
   {-1,-2,0},
   {-2,4,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,-1,0},
   {-1,4,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-5,0},
   {1,-4,0},
   {-2,3,0},
   {1,-2,0},
   {-1,-5,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-5,0},
   {2,-4,0},
   {-1,3,0},
   {2,-2,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-5,0},
   {-2,-4,0},
   {-2,-3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-4,0},
   {-1,-3,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki117[] = {
   {2,-1,1},
   {3,-2,1},
   {1,-1,1},
   {3,0,1},
   {2,-3,1},
   {0,0,1},
   {4,-1,2},
   {2,1,2},
   {1,2,2},
   {3,-1,2},
   {1,-3,2},
   {2,0,2},
   {-2,-7,0},
   {-1,-6,0},
   {-2,-3,0},
   {-2,4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-2,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-7,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,3,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-7,0},
   {1,-6,0},
   {1,-5,0},
   {1,-4,0},
   {-1,-7,0},
   {1,-2,0},
   {-1,2,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-7,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-1,-4,0},
   {2,-2,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-7,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-6,0},
   {-2,-5,0},
   {-2,-4,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-7,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-5,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-7,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-7,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki118[] = {
   {1,-5,1},
   {2,1,1},
   {3,-1,1},
   {2,0,1},
   {1,2,1},
   {4,-1,1},
   {1,-3,1},
   {3,0,2},
   {0,0,2},
   {1,-1,2},
   {3,-2,2},
   {2,-3,2},
   {2,-1,2},
   {-1,-5,0},
   {-1,-3,0},
   {-1,-6,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-2,3,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-6,0},
   {-2,-6,0},
   {1,-4,0},
   {-2,4,0},
   {1,-2,0},
   {-2,-2,0},
   {1,0,0},
   {1,1,0},
   {-1,-2,0},
   {1,3,0},
   {1,4,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-1,4,0},
   {2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-5,0},
   {-2,-4,0},
   {-2,-3,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-4,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki119[] = {
   {3,-2,1},
   {2,-3,1},
   {3,0,1},
   {2,-1,1},
   {3,2,1},
   {0,0,1},
   {1,-1,1},
   {2,1,2},
   {1,-3,2},
   {1,-5,2},
   {1,2,2},
   {4,-1,2},
   {2,0,2},
   {3,-1,2},
   {-2,4,0},
   {-1,-2,0},
   {-1,1,0},
   {-1,2,0},
   {-1,0,0},
   {-1,4,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {-1,-3,0},
   {1,-4,0},
   {-2,3,0},
   {1,-2,0},
   {-1,-5,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-5,0},
   {2,-4,0},
   {-1,3,0},
   {2,-2,0},
   {-2,-2,0},
   {-1,-1,0},
   {-2,0,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-5,0},
   {-2,-4,0},
   {-2,-3,0},
   {3,1,0},
   {-2,-1,0},
   {3,3,0},
   {3,4,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-4,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki120[] = {
   {1,-5,1},
   {2,1,1},
   {3,-1,1},
   {2,0,1},
   {3,1,1},
   {4,-1,1},
   {1,2,1},
   {1,-3,1},
   {0,0,2},
   {3,0,2},
   {3,-2,2},
   {2,-3,2},
   {1,-1,2},
   {3,2,2},
   {2,-1,2},
   {-1,-6,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,-3,0},
   {-1,2,0},
   {-1,3,0},
   {-2,3,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {-1,1,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-6,0},
   {-2,-6,0},
   {1,-4,0},
   {-2,4,0},
   {1,-2,0},
   {-1,-5,0},
   {1,0,0},
   {1,1,0},
   {0,-2,0},
   {1,3,0},
   {1,4,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-1,4,0},
   {2,-2,0},
   {-1,-2,0},
   {-2,0,0},
   {-2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-5,0},
   {-2,-4,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {3,3,0},
   {3,4,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-4,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki121[] = {
   {2,-1,1},
   {3,-2,1},
   {0,0,1},
   {3,0,1},
   {1,-1,1},
   {3,2,1},
   {4,0,1},
   {2,-3,1},
   {3,-1,2},
   {1,-5,2},
   {1,-3,2},
   {4,-1,2},
   {3,1,2},
   {2,1,2},
   {2,0,2},
   {1,2,2},
   {-1,-1,0},
   {-1,0,0},
   {-1,-6,0},
   {-1,2,0},
   {-1,3,0},
   {-2,3,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {-1,1,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-6,0},
   {-2,-6,0},
   {1,-4,0},
   {-2,4,0},
   {1,-2,0},
   {-1,-5,0},
   {1,0,0},
   {1,1,0},
   {0,-2,0},
   {1,3,0},
   {1,4,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-1,4,0},
   {2,-2,0},
   {-1,-2,0},
   {-2,0,0},
   {-2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-5,0},
   {-2,-4,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {3,3,0},
   {3,4,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-4,0},
   {-1,-3,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki122[] = {
   {4,1,1},
   {2,0,1},
   {2,1,1},
   {1,-3,1},
   {1,2,1},
   {3,1,1},
   {1,-5,1},
   {4,-1,1},
   {3,-1,1},
   {2,-1,2},
   {3,-2,2},
   {1,-1,2},
   {3,0,2},
   {2,-3,2},
   {3,2,2},
   {4,0,2},
   {0,0,2},
   {-2,-1,0},
   {-1,1,0},
   {-2,-3,0},
   {-1,3,0},
   {-1,4,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-1,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-6,0},
   {-2,0,0},
   {1,-4,0},
   {-1,-2,0},
   {1,-2,0},
   {-1,0,0},
   {1,0,0},
   {1,1,0},
   {-2,-2,0},
   {1,3,0},
   {1,4,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-1,2,0},
   {2,-2,0},
   {-2,-6,0},
   {-2,-5,0},
   {-2,-4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,4,0},
   {-1,-6,0},
   {-1,-5,0},
   {-1,-4,0},
   {-1,-3,0},
   {3,3,0},
   {3,4,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {7,-6,0},
   {7,-5,0},
   {7,-4,0},
   {7,-3,0},
   {7,-2,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0},
   {7,3,0},
   {7,4,0}};

static struct patval joseki123[] = {
   {1,-1,1},
   {4,0,1},
   {2,-1,1},
   {3,2,1},
   {0,0,1},
   {3,-2,1},
   {2,-3,1},
   {3,0,1},
   {5,0,1},
   {1,-5,2},
   {2,1,2},
   {1,-3,2},
   {4,1,2},
   {2,0,2},
   {4,-1,2},
   {3,1,2},
   {3,-1,2},
   {1,2,2},
   {-1,-2,0},
   {-1,-4,0},
   {-1,3,0},
   {-1,4,0},
   {-1,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-6,0},
   {-2,-3,0},
   {1,-4,0},
   {0,-6,0},
   {1,-2,0},
   {-1,-3,0},
   {1,0,0},
   {1,1,0},
   {-1,0,0},
   {1,3,0},
   {1,4,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {-1,-1,0},
   {2,-2,0},
   {-1,1,0},
   {-1,2,0},
   {-2,4,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {3,3,0},
   {3,4,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-2,-6,0},
   {-2,-5,0},
   {-2,-4,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {-1,-5,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0},
   {7,-6,0},
   {7,-5,0},
   {7,-4,0},
   {7,-3,0},
   {7,-2,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0},
   {7,3,0},
   {7,4,0},
   {8,-6,0},
   {8,-5,0},
   {8,-4,0},
   {8,-3,0},
   {8,-2,0},
   {8,-1,0},
   {8,0,0},
   {8,1,0},
   {8,2,0},
   {8,3,0},
   {8,4,0}};

static struct patval joseki124[] = {
   {1,2,1},
   {1,-3,1},
   {0,0,2},
   {-2,-3,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,-5,0},
   {-2,-2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-5,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-5,0},
   {1,-4,0},
   {-2,-4,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki125[] = {
   {1,-1,1},
   {0,0,1},
   {1,2,2},
   {1,-3,2},
   {-2,0,0},
   {-2,-4,0},
   {-2,-2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-2,1,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-3,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {-2,-3,0},
   {1,-2,0},
   {-2,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,2,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki126[] = {
   {3,1,1},
   {1,-3,1},
   {1,2,1},
   {1,-1,2},
   {0,0,2},
   {-2,0,0},
   {-2,-2,0},
   {-2,3,0},
   {-2,4,0},
   {-2,-4,0},
   {-2,1,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-3,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {-2,-3,0},
   {1,-2,0},
   {-1,-4,0},
   {1,0,0},
   {1,1,0},
   {-2,2,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {-2,-1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {6,3,0},
   {6,4,0}};

static struct patval joseki127[] = {
   {0,0,1},
   {1,-2,1},
   {2,-3,1},
   {2,-5,2},
   {4,-1,2},
   {2,0,2},
   {-1,-2,0},
   {-1,1,0},
   {-1,2,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-1,-3,0},
   {0,1,0},
   {0,2,0},
   {1,-6,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {-1,0,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {2,-6,0},
   {-1,-6,0},
   {2,-4,0},
   {-1,-4,0},
   {2,-2,0},
   {2,-1,0},
   {-1,-1,0},
   {2,1,0},
   {2,2,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {-1,-5,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {5,-6,0},
   {5,-5,0},
   {5,-4,0},
   {5,-3,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {6,-6,0},
   {6,-5,0},
   {6,-4,0},
   {6,-3,0},
   {6,-2,0},
   {6,-1,0},
   {6,0,0},
   {6,1,0},
   {6,2,0},
   {7,-6,0},
   {7,-5,0},
   {7,-4,0},
   {7,-3,0},
   {7,-2,0},
   {7,-1,0},
   {7,0,0},
   {7,1,0},
   {7,2,0},
   {8,-6,0},
   {8,-5,0},
   {8,-4,0},
   {8,-3,0},
   {8,-2,0},
   {8,-1,0},
   {8,0,0},
   {8,1,0},
   {8,2,0},
   {9,-6,0},
   {9,-5,0},
   {9,-4,0},
   {9,-3,0},
   {9,-2,0},
   {9,-1,0},
   {9,0,0},
   {9,1,0},
   {9,2,0},
   {10,-6,0},
   {10,-5,0},
   {10,-4,0},
   {10,-3,0},
   {10,-2,0},
   {10,-1,0},
   {10,0,0},
   {10,1,0},
   {10,2,0}};

static struct patval joseki128[] = {
   {0,0,1},
   {1,2,2},
   {-2,-6,0},
   {-2,-3,0},
   {-2,-2,0},
   {-2,-1,0},
   {-2,0,0},
   {-2,-5,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-6,0},
   {-1,-5,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-6,0},
   {0,-5,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,-4,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-6,0},
   {1,-5,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,1,0},
   {1,3,0},
   {1,4,0},
   {2,-6,0},
   {2,-5,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-6,0},
   {3,-5,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {4,-6,0},
   {4,-5,0},
   {4,-4,0},
   {4,-3,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0}};

static struct patval joseki129[] = {
   {0,0,1},
   {1,2,2},
   {-2,-3,0},
   {-2,-1,0},
   {-2,-4,0},
   {-2,1,0},
   {-2,2,0},
   {-2,3,0},
   {-2,4,0},
   {-1,-4,0},
   {-1,-3,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {0,-4,0},
   {0,-3,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {0,1,0},
   {0,2,0},
   {0,3,0},
   {0,4,0},
   {1,-4,0},
   {1,-3,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {-2,-2,0},
   {1,3,0},
   {1,4,0},
   {2,-4,0},
   {2,-3,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {3,-4,0},
   {3,-3,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0}};

static struct patval joseki130[] = {
   {1,4,1},
   {0,0,1},
   {0,2,2},
   {-2,1,0},
   {-2,0,0},
   {-2,4,0},
   {-2,5,0},
   {-2,6,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {0,-1,0},
   {-2,2,0},
   {0,1,0},
   {-2,-1,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {0,6,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {-2,3,0},
   {1,5,0},
   {1,6,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {2,2,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0}};

static struct patval joseki131[] = {
   {2,2,1},
   {0,2,1},
   {0,0,2},
   {1,4,2},
   {-2,3,0},
   {-2,1,0},
   {-2,5,0},
   {-2,-1,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-1,5,0},
   {-1,6,0},
   {0,-1,0},
   {-2,4,0},
   {0,1,0},
   {-2,2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {0,6,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {-2,0,0},
   {1,5,0},
   {1,6,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-2,6,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {3,3,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},
   {5,3,0},
   {5,4,0},
   {5,5,0},
   {5,6,0}};

static struct patval joseki132[] = {
   {3,3,1},
   {1,4,1},
   {0,0,1},
   {2,2,2},
   {0,2,2},
   {-2,1,0},
   {-2,4,0},
   {-2,5,0},
   {-2,-2,0},
   {-1,-2,0},
   {-1,-1,0},
   {-1,0,0},
   {-1,1,0},
   {-1,2,0},
   {-1,3,0},
   {-1,4,0},
   {-2,3,0},
   {-1,6,0},
   {0,-2,0},
   {0,-1,0},
   {-2,0,0},
   {0,1,0},
   {-2,2,0},
   {0,3,0},
   {0,4,0},
   {0,5,0},
   {0,6,0},
   {1,-2,0},
   {1,-1,0},
   {1,0,0},
   {1,1,0},
   {1,2,0},
   {1,3,0},
   {-2,-1,0},
   {1,5,0},
   {1,6,0},
   {2,-2,0},
   {2,-1,0},
   {2,0,0},
   {2,1,0},
   {-1,5,0},
   {2,3,0},
   {2,4,0},
   {2,5,0},
   {2,6,0},
   {3,-2,0},
   {3,-1,0},
   {3,0,0},
   {3,1,0},
   {3,2,0},
   {-2,6,0},
   {3,4,0},
   {3,5,0},
   {3,6,0},
   {4,-2,0},
   {4,-1,0},
   {4,0,0},
   {4,1,0},
   {4,2,0},
   {4,3,0},
   {4,4,0},
   {4,5,0},
   {4,6,0},
   {5,-2,0},
   {5,-1,0},
   {5,0,0},
   {5,1,0},
   {5,2,0},




