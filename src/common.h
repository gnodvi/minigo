// -*-  mode: c    ; coding: koi8   -*- ----------------------------------------

/* emgena: gg_utils.h */

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

#ifndef _GG_UTILS_H_
#define _GG_UTILS_H_

/*-------------------------------------------------------*/
/* #include <stdarg.h> */

/* #ifdef HAVE_CONFIG_H */
/* #include <config.h> */
/* #endif */


/* #if TIME_WITH_SYS_TIME */
/* # include <sys/time.h> */
/* # include <time.h> */
/* #else */
/* # if HAVE_SYS_TIME_H */
/* #  include <sys/time.h> */
/* # else */
/* #  include <time.h> */
/* # endif */
/* #endif */


/*-------------------------------------------------------*/
/* #ifdef __MINGW32__ */
/* #include <windows.h> */
/* #include <winsock.h> */
/* #include <io.h> */
/* #endif */

/* #ifdef HAVE_VISUAL_C */
/* #include <winsock.h> */
/* #include <io.h> */
/* #endif  */
/*-------------------------------------------------------*/


void gg_init_color(void);
void write_color_char(int c, int x);
void write_color_string(int c, const char *str);

void gg_vsnprintf(char *dest, unsigned long len, const char *fmt,
		  va_list args);
void gg_snprintf(char *dest, unsigned long len, const char *fmt, ...);

int gg_gettimeofday2(struct timeval *tv, void *p);
double gg_gettimeofday(void);
double gg_cputime(void);

float gg_normalize_float(float x, float a);
int gg_normalize_float2int(float x, float a);
void gg_sort(void *base, size_t nel, size_t width,
	     int (*compar)(const void *, const void *));


const char *gg_version(void);

/* prototypes for basic reorientation functions */

void  rotate(int i, int j, int *ri, int *rj, int bs, int rot);
void  inv_rotate(int i, int j, int *ri, int *rj, int bs, int rot);

#endif /* _GG_UTILS_H_ */


/*
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 2
 * End:
 */
/* =========================================================================*/
/* emgena: gg-getopt.h */

/* Declarations for getopt.
   Copyright (C) 1989,90,91,92,93,94,96,97,98 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */


/* =========================================================================*/
#ifndef GG_GETOPT_H

#ifndef __need_getopt
# define GG_GETOPT_H 1
#endif

#ifdef	__cplusplus
extern "C" {
#endif

/* For communication from `getopt' to the caller.
   When `getopt' finds an option that takes an argument,
   the argument value is returned here.
   Also, when `ordering' is RETURN_IN_ORDER,
   each non-option ARGV-element is returned here.  */

extern char *gg_optarg;

/* Index in ARGV of the next element to be scanned.
   This is used for communication to and from the caller
   and for communication between successive calls to `getopt'.

   On entry to `getopt', zero means this is the first call; initialize.

   When `getopt' returns -1, this is the index of the first of the
   non-option elements that the caller should itself scan.

   Otherwise, `optind' communicates from one call to the next
   how much of ARGV has been scanned so far.  */

extern int gg_optind;

/* Callers store zero here to inhibit the error message `getopt' prints
   for unrecognized options.  */

extern int gg_opterr;

/* Set to an option character which was unrecognized.  */

extern int gg_optopt;

#ifndef __need_getopt
/* Describe the long-named options requested by the application.
   The LONG_OPTIONS argument to getopt_long or getopt_long_only is a vector
   of `struct option' terminated by an element containing a name which is
   zero.

   The field `has_arg' is:
   no_argument		(or 0) if the option does not take an argument,
   required_argument	(or 1) if the option requires an argument,
   optional_argument 	(or 2) if the option takes an optional argument.

   If the field `flag' is not NULL, it points to a variable that is set
   to the value given in the field `val' when the option is found, but
   left unchanged if the option is not found.

   To have a long-named option do something other than set an `int' to
   a compiled-in constant, such as set a value from `optarg', set the
   option's `flag' field to zero and its `val' field to a nonzero
   value (the equivalent single-letter option character, if there is
   one).  For long options that have a zero `flag' field, `getopt'
   returns the contents of the `val' field.  */

struct gg_option
{
# if defined __STDC__ && __STDC__
  const char *name;
# else
  char *name;
# endif
  /* has_arg can't be an enum because some compilers complain about
     type mismatches in all the code that assumes it is an int.  */
  int has_arg;
  int *flag;
  int val;
};

/* Names for the values of the `has_arg' field of `struct option'.  */

# define no_argument		0
# define required_argument	1
# define optional_argument	2
#endif	/* need getopt */


/* Get definitions and prototypes for functions to process the
   arguments in ARGV (ARGC of them, minus the program name) for
   options given in OPTS.

   Return the option character from OPTS just read.  Return -1 when
   there are no more options.  For unrecognized options, or options
   missing arguments, `optopt' is set to the option letter, and '?' is
   returned.

   The OPTS string is a list of characters which are recognized option
   letters, optionally followed by colons, specifying that that letter
   takes an argument, to be placed in `optarg'.

   If a letter in OPTS is followed by two colons, its argument is
   optional.  This behavior is specific to the GNU `getopt'.

   The argument `--' causes premature termination of argument
   scanning, explicitly telling `getopt' that there are no more
   options.

   If OPTS begins with `--', then non-option arguments are treated as
   arguments to the option '\0'.  This behavior is specific to the GNU
   `getopt'.  */

#if defined __STDC__ && __STDC__
# ifdef __GNU_LIBRARY__
/* Many other libraries have conflicting prototypes for getopt, with
   differences in the consts, in stdlib.h.  To avoid compilation
   errors, only prototype getopt for the GNU C library.  */
extern int gg_getopt (int argc, char *const *argv, const char *shortopts);
# else /* not __GNU_LIBRARY__ */
extern int gg_getopt (int argc, char *const *argv, const char *shortopts);
# endif /* __GNU_LIBRARY__ */

# ifndef __need_getopt
extern int gg_getopt_long (int argc, char *const *argv, const char *shortopts,
		        const struct gg_option *longopts, int *longind);
extern int gg_getopt_long_only (int argc, char *const *argv,
			     const char *shortopts,
		             const struct gg_option *longopts, int *longind);

/* Internal only.  Users should not call this directly.  */
extern int _getopt_internal (int argc, char *const *argv,
			     const char *shortopts,
		             const struct gg_option *longopts, int *longind,
			     int long_only);
# endif
#else /* not __STDC__ */
extern int gg_getopt ();
# ifndef __need_getopt
extern int gg_getopt_long ();
extern int gg_getopt_long_only ();

extern int _getopt_internal ();
# endif
#endif /* __STDC__ */

#ifdef	__cplusplus
}
#endif

/* Make sure we later can get all the definitions and declarations.  */
#undef __need_getopt

#endif /* getopt.h */
/* =========================================================================*/
/* emgena: random.h */
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

#ifndef _RANDOM_H_
#define _RANDOM_H_

/* This random number generator produces 32 bit unsigned integers, no
 * more, no less. Internally in the algorithm and for storing the
 * state we need a type that is at least 32 bits wide. A longer type
 * doesn't hurt but means a waste of bits.
 *
 * ISO C guarantees that an unsigned long always is at least 32 bits.
 * It is not uncommon, however, that it is longer. An unsigned int is
 * not guaranteed to be more than 16 bits wide, but on modern
 * platforms we can be certain that this type too is 32 bits (or
 * more). Also the GNU Coding Standards explicitly state that the
 * possibility of ints shorter than 32 bits should be ignored.
 *
 * We could make a typedef here to choose exactly which type to use.
 * In order to avoid various complications in the interface to the
 * random number generator, however, we prefer to consistently use
 * unsigned int internally and we assume this type to be at least 32
 * bits wide.
 */

/* Internal state of the random number generator. */
struct gg_rand_state {
  unsigned int x[25];   /* Internal state. */
  int k;                /* Word counter. */
};

/* Seed the random number generator. If an unsigned int is larger than
 * 32 bits, only the 32 least significant bits are used for seeding.
 */
void gg_srand(unsigned int seed);

/* Obtain one random integer value in the interval [0, 2^31-1]. */
int gg_rand(void);

/* Obtain one random integer value in the interval [0, 2^32-1]. */
unsigned int gg_urand(void);

/* Obtain one random floating point value in the half open interval
 * [0.0, 1.0).
 *
 * If the value is converted to a floating point type with less than
 * 32 bits mantissa (or if the double type should happen to be
 * unusually short), the value 1.0 may be attained.
 */
double gg_drand(void);

/* Retrieve the internal state of the random generator. */
void gg_get_rand_state(struct gg_rand_state *state);

/* Set the internal state of the random number generator. */
void gg_set_rand_state(struct gg_rand_state *state);


#endif /* _RANDOM_H_ */

/* =========================================================================*/
/* emgena: clock.h */
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

#ifndef _CLOCK_H_
#define _CLOCK_H_

/* ============================================================= *\
 *                        Time handling                          *
 *                          for GNU Go                           *
 *                         __       __                           *
 *                        <  >     <  >                          *
 *                      +--++-------++--+                        *
 *                      |  .'11 12 1'.  |                        *
 *                      |  :10 \    2:  |                        *
 *                      |  :9   @-> 3:  |                        *
 *                      |  :8       4;  |                        *
 *                      |  '..7 6 5..'  |                        *
 *                      |_______________|                        *
 *                                                               *
\* ============================================================= */

/* #include <stdio.h> */
/* #ifdef HAVE_CONFIG_H */
/* #include "config.h" */
/* #endif */

/* #include "gnugo.h" */

/* #ifdef HAVE_VISUAL_C */
/* #include <winsock.h> */
/* #include <io.h> */
/* #include <time.h> */
/* #else */
/* #include <sys/time.h> */
/* #endif */

/* #ifdef __MINGW32__ */
/* #include <windows.h> */
/* #include <winsock.h> */
/* #include <io.h> */
/* #endif */

/* interface */
 
/* initialization and activation */
void clock_init(int time, int byo_time, int byo_stones);
void clock_enable(void);
 
void clock_init_autolevel(int min_level, int max_level);
void clock_enable_autolevel(void);

/* main access */
void clock_push_button(int color);
void clock_unpush_button(int color);

/* getting informations about clock */
int clock_is_byoyomi(int color);
int clock_is_time_over(int color);
double clock_get_timer(int color);
double clock_get_btimer(int color);
double clock_get_time_left(int color);
double clock_get_btime_left(int color, int *stones);

/* adaptative system */
void clock_adapt_level(int *p_level, int color);

/* output */
void clock_print(int color);
void clock_report_autolevel(FILE *f, int color);


#endif  /* _CLOCK_H_ */
