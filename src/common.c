/* gg_utils.c */
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

/*emgena*/
/* #define TERMINFO 0 */

/* #define HAVE_TERM_H 1 */
/* #define HAVE_CURSES_H 1 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif


#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <limits.h>
/* #include "random.h" */

#ifdef HAVE_GLIB_H
#include <glib.h>
#endif

/*-------------------------------------------------------*/
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

/*-------------------------------------------------------*/
#ifdef __MINGW32__
#include <windows.h>
#include <winsock.h>
#include <io.h>
#endif

#ifdef HAVE_VISUAL_C
#include <winsock.h>
#include <io.h>
#endif 
/*-------------------------------------------------------*/

/* #include "gg_utils.h" */

/* for gg_cputime -----------*/
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_SYS_TIMES_H
#include <sys/times.h>

/* #elif defined(WIN32) */
#else

#include <windows.h>
#endif
/*---------------------------*/



#include "common.h"
/* #include "gg-getopt.h" */

/* #undef TERMINFO  */
/* emgena: done in config.h */

/* Avoid compiler warnings with unused parameters */

#define UNUSED(x)  (void)x

/* Define TERMINFO or ANSI_COLOR to enable coloring of pieces.
 * This is normally done in config.h.
 */

/* enabling color */

/* linux console :
 *  0=black
 *  1=red
 *  2=green
 *  3=yellow/brown
 *  4=blue
 *  5=magenta
 *  6=cyan
 *  7=white
 */

/* emgena */

#undef TERMINFO 
/* ------------------------------------------ */
/* #ifdef TERMINFO  */

/* #ifdef _AIX */
/* #define _TPARM_COMPAT */
/* #endif */

/* #if HAVE_CURSES_H */
/* #include <curses.h> */
/* #elif HAVE_NCURSES_CURSES_H */
/* #include <ncurses/curses.h> */
/* #else */
/* #endif */

/* #if HAVE_TERM_H */
/* #include <term.h> */
/* #elif HAVE_NCURSES_TERM_H */
/* #include <ncurses/term.h> */
/* #else */
/* #endif */

/* terminfo attributes */
/* terminfo string to set color */
/* terminfo max colour */

/* static char *setaf;		 */
/* static int   max_color;		 */
/* static int   init = 0; */

/* #endif  */
/* TERMINFO ----------------------------------------- */


/* for gg_cputime */

/* #ifdef HAVE_UNISTD_H */
/* #include <unistd.h> */
/* #endif */
/* #ifdef HAVE_SYS_TIMES_H */
/* #include <sys/times.h> */
/* #elif defined(WIN32) */
/* #include <windows.h> */
/* #endif */



void
gg_init_color()
{
/* #ifdef TERMINFO */

/* compiler is set to make string literals  const char *
 * But system header files dont prototype things correctly.
 * These are equivalent to a non-const string literals
 */

/*   static char setaf_literal[] = "setaf"; */
/*   static char colors_literal[] = "colors"; */
/*   static char empty_literal[] = ""; */

/*   if (init) */
/*     return; */
  
/*   init = 1; */

/*   setupterm(NULL, 2, NULL); */
/*   setaf = tigetstr(setaf_literal); */
/*   if (!setaf) */
/*     setaf = empty_literal; */
/*   max_color = tigetnum(colors_literal) - 1; */
/*   if (max_color < 1) */
/*     max_color = 1; */
/*   else if (max_color > 30) */
/*     max_color = 30; */
  
/* #endif  */
/* TERMINFO */
}


/*---------------------------------------------------------------*/
#ifdef WIN32
#ifdef VC
#include <crtdbg.h>

verifyW32(BOOL b)
{
  if (!b) {
    _ASSERTE(0 && "Win32 Error");
    fprintf(stderr, "Win32 Err: %ld\n", GetLastError());
  }
}

#else
/* mingw32 lacks crtdbg.h and _ASSERTE */
verifyW32(BOOL b)
{
  if (!b) {
    fprintf(stderr, "Win32 Err: %ld\n", GetLastError());
  }
}

#endif
#endif
/*---------------------------------------------------------------*/

void 
write_color_char_no_space(int c, int x)
{
/* #ifdef TERMINFO */

/*   fprintf(stderr, "%s%c", tparm(setaf, c, 0, 0, 0, 0, 0, 0, 0, 0), x); */
/*   fputs(tparm(setaf, max_color, 0, 0, 0, 0, 0, 0, 0, 0), stderr); */

/* #elif defined(ANSI_COLOR) */

/*   fprintf(stderr, "\033[%dm%c\033[0m", 30+c, x); */

/* #elif defined(WIN32) */
  
/*   static HANDLE hStdErr = 0; */
/*   DWORD iCharsWritten; */
/*   BOOL succeed32; */
/*   CONSOLE_SCREEN_BUFFER_INFO bufInfo; */
/*   if (!hStdErr) { */
/*     hStdErr = GetStdHandle(STD_ERROR_HANDLE); */
/*     if (hStdErr == INVALID_HANDLE_VALUE) { */
/*       fprintf(stderr, "Unable to open stderr.\n"); */
/*     } */
/*   } */

  /* Red & Blue are switched from what MS-Windows wants:
   *   FOREGROUND_BLUE      0x0001 // text color contains blue.
   *   FOREGROUND_GREEN     0x0002 // text color contains green.
   *   FOREGROUND_RED       0x0004 // text color contains red
   * This magic switches the bits back:
   */
/*   c = (c & 1) * 4 + (c & 2) + (c & 4) / 4; */
/*   c += FOREGROUND_INTENSITY; */
/*   succeed32 = GetConsoleScreenBufferInfo(hStdErr, &bufInfo); */
/*   if (!succeed32) {   */
/* Probably redirecting output, just give plain text. */
/*     fprintf(stderr, "%c", x); */
/*     return; */
/*   } */
/*   verifyW32(SetConsoleTextAttribute(hStdErr, (WORD) c)); */
/*   verifyW32(WriteConsole(hStdErr, &x, 1, &iCharsWritten, 0)); */
/*   verifyW32(SetConsoleTextAttribute(hStdErr, bufInfo.wAttributes)); */

/* #else */

  fprintf(stderr, "%c", x);

/* #endif */
}

void
write_color_string(int c, const char *str)
{
  while (*str)
    write_color_char_no_space(c, *str++);
}

void
write_color_char(int c, int x)
{
  fprintf(stderr, " ");
  write_color_char_no_space(c, x);
}

/*
 * A wrapper around vsnprintf.
 */

void
gg_vsnprintf(char *dest, unsigned long len, const char *fmt, va_list args)
{
    
#ifdef HAVE_VSNPRINTF
  vsnprintf(dest, len, fmt, args);
#elif HAVE_G_VSNPRINTF
  g_vsnprintf(dest, len, fmt, args);
#elif HAVE_VISUAL_C
  _vsnprintf(dest, len, fmt, args);
#else
  UNUSED(len);
  vsprintf(dest, fmt, args);
#endif

}

/* gg_snprintf_emgena (char *dest, unsigned long len, const char *fmt, ...) */
void
gg_snprintf (char *dest, unsigned long len, const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  gg_vsnprintf(dest, len, fmt, args);
  va_end(args);
}

/* Get the time of day, calling gettimeofday from sys/time.h
 * if available, otherwise substituting a workaround for portability.
 */

int
gg_gettimeofday2(struct timeval *tv, void *p)
{
#ifdef HAVE_GETTIMEOFDAY
  return gettimeofday(tv, NULL);
#else
  if (tv != NULL) {
    tv->tv_sec  = time(NULL);
    tv->tv_usec = 0;
  }
  return 1;
#endif
}

double
gg_gettimeofday(void)
{
  struct timeval tv;
  gg_gettimeofday2(&tv, NULL);
  return tv.tv_sec + 1.e-6*tv.tv_usec;
}

const char *
gg_version(void)
{
  return VERSION;
}

/* return cputime used in secs */

double
gg_cputime(void)
{
#if HAVE_SYS_TIMES_H && HAVE_TIMES && HAVE_UNISTD_H
    struct tms t;
    times(&t);
    return (t.tms_utime + t.tms_stime + t.tms_cutime + t.tms_cstime)
            / ((double) sysconf(_SC_CLK_TCK));
#elif defined(WIN32)
    FILETIME creationTime, exitTime, kernelTime, userTime;
    ULARGE_INTEGER uKernelTime, uUserTime, uElapsedTime;
    GetProcessTimes(GetCurrentProcess(), &creationTime, &exitTime,
                    &kernelTime, &userTime);
    uKernelTime.LowPart = kernelTime.dwLowDateTime;
    uKernelTime.HighPart = kernelTime.dwHighDateTime;
    uUserTime.LowPart = userTime.dwLowDateTime;
    uUserTime.HighPart = userTime.dwHighDateTime;
    uElapsedTime.QuadPart = uKernelTime.QuadPart + uUserTime.QuadPart;
    /*_ASSERTE(0 && "Debug Times");*/
    /* convert from multiples of 100nanosecs to seconds: */
    return (signed __int64)(uElapsedTime.QuadPart) * 1.e-7;
#else
    static int warned = 0;
    if (!warned) {
      fprintf(stderr, "CPU timing unavailable - returning wall time.");
      warned = 1;
    }
    /* return wall clock seconds */
    return gg_gettimeofday();
#endif
}

/* Before we sort floating point values (or just compare them) we
 * may need to normalize them. This may sound cryptic but is
 * required to avoid an obscure platform dependency.
 *
 * The underlying problem is that most fractional decimal numbers
 * can't be represented exactly in a floating point number with base
 * two. The error may be small but it is there. When such numbers
 * are added or subtracted, the errors accumulate and even if the
 * result (counting exactly) should be a number which can be
 * represented exactly, this cannot be assumed to be the case.
 *
 * To give an example of this, the computation 0.3 + 0.05 - 0.35 may
 * sum to 0, a small negative value, or a small positive value.
 * Moreover, which case we encounter depends on the number of
 * mantissa bits in the floating point type used and the exact
 * details of the floating point arithmetic on the platform.
 *
 * In the context of sorting, assume that two values both should be
 * 0.35, but one has been computed as 0.3 + 0.05 and the other
 * directly assigned 0.35. Then it depends on the platform whether
 * they compare as equal or one of them is larger than the other.
 *
 * This code normalizes the values to avoid this problem. It is
 * assumed that all values encountered are integer multiples of a.
 */
float
gg_normalize_float(float x, float a)
{
  return a * ((int) (0.5 + x / a));
}

int
gg_normalize_float2int(float x, float a)
{
  return ((int) (0.5 + x / a));
}

/* A sorting algorithm, call-compatible with the libc qsort() function.
 *
 * The reason to prefer this to standard qsort() is that quicksort is
 * an unstable sorting algorithm, i.e. the relative ordering of
 * elements with the same comparison value may change. Exactly how the
 * ordering changes depends on implementation specific details like
 * the strategy for choosing the pivot element. Thus a list with
 * "equal" values may be sorted differently between platforms, which
 * potentially can lead to significant differences in the move
 * generation.
 *
 * This is an implementation of the combsort algorithm.
 *
 * Testing shows that it is faster than the GNU libc qsort() function
 * on small data sets and within a factor of two slower for large
 * random data sets. Its performance does not degenerate for common
 * special cases (i.e. sorted or reversed data) but it seems to be
 * susceptible to O(N^2) behavior for repetitive data with specific
 * cycle lengths.
 *
 * Like qsort() this algorithm is unstable, but since the same
 * implementation (this one) is used on all platforms, the reordering
 * of equal elements will be consistent.
 */
void
gg_sort(void *base, size_t nel, size_t width,
	int (*cmp)(const void *, const void *))
{
  int gap = nel;
  int swap_made;
  char *end = (char *) base + width * (nel - 1);
  do {
    char *a, *b;
    swap_made = 0;
    gap = (10 * gap + 3) / 13;
    for (a = base, b = a + gap * width; b <= end; a += width, b += width) {
      if (cmp((void *) a, (void *) b) > 0) {
	char *c = a;
	char *d = b;
	size_t size = width;
	while (size-- > 0) {
	  char tmp = *c;
	  *c++ = *d;
	  *d++ = tmp;
	}
	swap_made = 1;
      }
    }
  } while (gap > 1 || swap_made);
}


/* Reorientation of point (i, j) into (*ri, *rj) */
void
rotate(int i, int j, int *ri, int *rj, int bs, int rot)
{
  int bs1;
  assert(bs > 0);
  assert(ri != NULL && rj != NULL);
  assert(rot >= 0 && rot < 8);
  /* PASS case */
  if (i == -1 && j == -1) {
    *ri = i;
    *rj = j;
    return;
  }

  assert(i >= 0 && i < bs);
  assert(j >= 0 && j < bs);

  bs1 = bs - 1;
  if (rot == 0) {
    /* identity map */
    *ri = i;
    *rj = j;
  }
  else if (rot == 1) {
    /* rotation over 90 degrees */
    *ri = bs1 - j;
    *rj = i;
  }
  else if (rot == 2) {
    /* rotation over 180 degrees */
    *ri = bs1 - i;
    *rj = bs1 - j;
  }
  else if (rot == 3) {
    /* rotation over 270 degrees */
    *ri = j;
    *rj = bs1 - i;
  }
  else if (rot == 4) {
    /* flip along diagonal */
    *ri = j;
    *rj = i;
  }
  else if (rot == 5) {
    /* flip */
    *ri = bs1 - i;
    *rj = j;
  }
  else if (rot == 6) {
    /* flip along diagonal */
    *ri = bs1 - j;
    *rj = bs1 - i;
  }
  else if (rot == 7) {
    /* flip */
    *ri = i;
    *rj = bs1 - j;
  }
}

/* inverse reorientation of reorientation rot */
void
inv_rotate(int i, int j, int *ri, int *rj, int bs, int rot)
{
  /* every reorientation is it's own inverse except rotations
     over 90 and 270 degrees */
  if (rot == 1)
    rotate(i, j, ri, rj, bs, 3);
  else if (rot == 3)
    rotate(i, j, ri, rj, bs, 1);
  else
    rotate(i, j, ri, rj, bs, rot);
}



/*
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 2
 * End:
 */

/*==========================================================================*/
/* emgena: getopt.c */
/*==========================================================================*/
/* Getopt for GNU.
   NOTE: getopt is now part of the C library, so if you don't know what
   "Keep this file name-space clean" means, talk to drepper@gnu.org
   before changing it!

   Copyright (C) 1987, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
   	Free Software Foundation, Inc.

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
/*  */

/* This tells Alpha OSF/1 not to define a getopt prototype in <stdio.h>.
   Ditto for AIX 3.2 and <stdlib.h>.  */
#ifndef _NO_PROTO
# define _NO_PROTO
#endif

#if !defined __STDC__ || !__STDC__
/* This is a separate conditional since some stdc systems
   reject `defined (const)'.  */
# ifndef const
#  define const
# endif
#endif

#include <stdio.h>

/* Comment out all this code if we are using the GNU C Library, and are not
   actually compiling the library itself.  This code is part of the GNU C
   Library, but also included in many other GNU distributions.  Compiling
   and linking in this code is a waste when using the GNU C library
   (especially if it is a shared library).  Rather than having every GNU
   program understand `configure --with-gnu-libc' and omit the object files,
   it is simpler to just do this in the source for each such file.  */

#define GETOPT_INTERFACE_VERSION 2
#if !defined _LIBC && defined __GLIBC__ && __GLIBC__ >= 2
# include <gnu-versions.h>
# if _GNU_GETOPT_INTERFACE_VERSION == GETOPT_INTERFACE_VERSION
/*#  define ELIDE_CODE*/
# endif
#endif

#ifndef ELIDE_CODE


/* This needs to come after some library #include
   to get __GNU_LIBRARY__ defined.  */
#ifdef	__GNU_LIBRARY__
/* Don't include stdlib.h for non-GNU C libraries because some of them
   contain conflicting prototypes for getopt.  */
# include <stdlib.h>
# include <unistd.h>
#endif	/* GNU C library.  */

#ifdef VMS
# include <unixlib.h>
# include <string.h>
#endif

#ifndef _
/* This is for other GNU distributions with internationalized messages.
   When compiling libc, the _ macro is predefined.  */
# ifdef HAVE_LIBINTL_H
#  include <libintl.h>
#  define _(msgid)	gettext (msgid)
# else
#  define _(msgid)	(msgid)
# endif
#endif

/* This version of `getopt' appears to the caller like standard Unix `getopt'
   but it behaves differently for the user, since it allows the user
   to intersperse the options with the other arguments.

   As `getopt' works, it permutes the elements of ARGV so that,
   when it is done, all the options precede everything else.  Thus
   all application programs are extended to handle flexible argument order.

   Setting the environment variable POSIXLY_CORRECT disables permutation.
   Then the behavior is completely standard.

   GNU application programs can use a third alternative mode in which
   they can distinguish the relative order of options and other arguments.  */

/* #include "gg_utils.h" */
/* #include "gg-getopt.h" */

/* For communication from `getopt' to the caller.
   When `getopt' finds an option that takes an argument,
   the argument value is returned here.
   Also, when `ordering' is RETURN_IN_ORDER,
   each non-option ARGV-element is returned here.  */

char *gg_optarg;

/* Index in ARGV of the next element to be scanned.
   This is used for communication to and from the caller
   and for communication between successive calls to `getopt'.

   On entry to `getopt', zero means this is the first call; initialize.

   When `getopt' returns -1, this is the index of the first of the
   non-option elements that the caller should itself scan.

   Otherwise, `optind' communicates from one call to the next
   how much of ARGV has been scanned so far.  */

/* 1003.2 says this must be 1 before any call.  */
int gg_optind = 1;

/* Formerly, initialization of getopt depended on optind==0, which
   causes problems with re-calling getopt as programs generally don't
   know that. */

int __getopt_initialized;

/* The next char to be scanned in the option-element
   in which the last option character we returned was found.
   This allows us to pick up the scan where we left off.

   If this is zero, or a null string, it means resume the scan
   by advancing to the next ARGV-element.  */

static char *nextchar;

/* Callers store zero here to inhibit the error message
   for unrecognized options.  */

int gg_opterr = 1;

/* Set to an option character which was unrecognized.
   This must be initialized on some systems to avoid linking in the
   system's own getopt implementation.  */

int gg_optopt = '?';

/* Describe how to deal with options that follow non-option ARGV-elements.

   If the caller did not specify anything,
   the default is REQUIRE_ORDER if the environment variable
   POSIXLY_CORRECT is defined, PERMUTE otherwise.

   REQUIRE_ORDER means don't recognize them as options;
   stop option processing when the first non-option is seen.
   This is what Unix does.
   This mode of operation is selected by either setting the environment
   variable POSIXLY_CORRECT, or using `+' as the first character
   of the list of option characters.

   PERMUTE is the default.  We permute the contents of ARGV as we scan,
   so that eventually all the non-options are at the end.  This allows options
   to be given in any order, even with programs that were not written to
   expect this.

   RETURN_IN_ORDER is an option available to programs that were written
   to expect options and other ARGV-elements in any order and that care about
   the ordering of the two.  We describe each non-option ARGV-element
   as if it were the argument of an option with character code 1.
   Using `-' as the first character of the list of option characters
   selects this mode of operation.

   The special argument `--' forces an end of option-scanning regardless
   of the value of `ordering'.  In the case of RETURN_IN_ORDER, only
   `--' can cause `getopt' to return -1 with `optind' != ARGC.  */

static enum
{
  REQUIRE_ORDER, PERMUTE, RETURN_IN_ORDER
} ordering;

/* Value of POSIXLY_CORRECT environment variable.  */
static char *posixly_correct;

#ifdef	__GNU_LIBRARY__
/* We want to avoid inclusion of string.h with non-GNU libraries
   because there are many ways it can cause trouble.
   On some systems, it contains special magic macros that don't work
   in GCC.  */
# include <string.h>
# define my_index	strchr
#else

#include <string.h>

/* Avoid depending on library functions or files
   whose names are inconsistent.  */

#ifndef getenv
extern char *getenv ();
#endif

static char *
my_index (str, chr)
     const char *str;
     int chr;
{
  while (*str)
    {
      if (*str == chr)
	return (char *) str;
      str++;
    }
  return 0;
}

/* If using GCC, we can safely declare strlen this way.
   If not using GCC, it is ok not to declare it.  */
#ifdef __GNUC__
/* Note that Motorola Delta 68k R3V7 comes with GCC but not stddef.h.
   That was relevant to code that was here before.  */
# if (!defined __STDC__ || !__STDC__) && !defined strlen
/* gcc with -traditional declares the built-in strlen to return int,
   and has done so at least since version 2.4.5. -- rms.  */
extern int strlen (const char *);
# endif /* not __STDC__ */
#endif /* __GNUC__ */

#endif /* not __GNU_LIBRARY__ */

/* Handle permutation of arguments.  */

/* Describe the part of ARGV that contains non-options that have
   been skipped.  `first_nonopt' is the index in ARGV of the first of them;
   `last_nonopt' is the index after the last of them.  */

static int first_nonopt;
static int last_nonopt;

#ifdef _LIBC
/* Bash 2.0 gives us an environment variable containing flags
   indicating ARGV elements that should not be considered arguments.  */

/* Defined in getopt_init.c  */
extern char *__getopt_nonoption_flags;

static int nonoption_flags_max_len;
static int nonoption_flags_len;

static int original_argc;
static char *const *original_argv;

/* Make sure the environment variable bash 2.0 puts in the environment
   is valid for the getopt call we must make sure that the ARGV passed
   to getopt is that one passed to the process.  */
static void
__attribute__ ((unused))
store_args_and_env (int argc, char *const *argv)
{
  /* XXX This is no good solution.  We should rather copy the args so
     that we can compare them later.  But we must not use malloc(3).  */
  original_argc = argc;
  original_argv = argv;
}
# ifdef text_set_element
text_set_element (__libc_subinit, store_args_and_env);
# endif /* text_set_element */

# define SWAP_FLAGS(ch1, ch2) \
  if (nonoption_flags_len > 0)						      \
    {									      \
      char __tmp = __getopt_nonoption_flags[ch1];			      \
      __getopt_nonoption_flags[ch1] = __getopt_nonoption_flags[ch2];	      \
      __getopt_nonoption_flags[ch2] = __tmp;				      \
    }
#else	/* !_LIBC */
# define SWAP_FLAGS(ch1, ch2)
#endif	/* _LIBC */

/* Exchange two adjacent subsequences of ARGV.
   One subsequence is elements [first_nonopt,last_nonopt)
   which contains all the non-options that have been skipped so far.
   The other is elements [last_nonopt,optind), which contains all
   the options processed since those non-options were skipped.

   `first_nonopt' and `last_nonopt' are relocated so that they describe
   the new indices of the non-options in ARGV after they are moved.  */

#if defined __STDC__ && __STDC__
static void exchange (char **);
#endif

static void
exchange (argv)
     char **argv;
{
  int bottom = first_nonopt;
  int middle = last_nonopt;
  int top = gg_optind;
  char *tem;

  /* Exchange the shorter segment with the far end of the longer segment.
     That puts the shorter segment into the right place.
     It leaves the longer segment in the right place overall,
     but it consists of two parts that need to be swapped next.  */

#ifdef _LIBC
  /* First make sure the handling of the `__getopt_nonoption_flags'
     string can work normally.  Our top argument must be in the range
     of the string.  */
  if (nonoption_flags_len > 0 && top >= nonoption_flags_max_len)
    {
      /* We must extend the array.  The user plays games with us and
	 presents new arguments.  */
      char *new_str = malloc (top + 1);
      if (new_str == NULL)
	nonoption_flags_len = nonoption_flags_max_len = 0;
      else
	{
	  memset (__mempcpy (new_str, __getopt_nonoption_flags,
			     nonoption_flags_max_len),
		  '\0', top + 1 - nonoption_flags_max_len);
	  nonoption_flags_max_len = top + 1;
	  __getopt_nonoption_flags = new_str;
	}
    }
#endif

  while (top > middle && middle > bottom)
    {
      if (top - middle > middle - bottom)
	{
	  /* Bottom segment is the short one.  */
	  int len = middle - bottom;
	  register int i;

	  /* Swap it with the top part of the top segment.  */
	  for (i = 0; i < len; i++)
	    {
	      tem = argv[bottom + i];
	      argv[bottom + i] = argv[top - (middle - bottom) + i];
	      argv[top - (middle - bottom) + i] = tem;
	      SWAP_FLAGS (bottom + i, top - (middle - bottom) + i);
	    }
	  /* Exclude the moved bottom segment from further swapping.  */
	  top -= len;
	}
      else
	{
	  /* Top segment is the short one.  */
	  int len = top - middle;
	  register int i;

	  /* Swap it with the bottom part of the bottom segment.  */
	  for (i = 0; i < len; i++)
	    {
	      tem = argv[bottom + i];
	      argv[bottom + i] = argv[middle + i];
	      argv[middle + i] = tem;
	      SWAP_FLAGS (bottom + i, middle + i);
	    }
	  /* Exclude the moved top segment from further swapping.  */
	  bottom += len;
	}
    }

  /* Update records for the slots the non-options now occupy.  */

  first_nonopt += (gg_optind - last_nonopt);
  last_nonopt = gg_optind;
}

/* Initialize the internal data when the first call is made.  */

#if defined __STDC__ && __STDC__
static const char *_getopt_initialize (int, char *const *, const char *);
#endif
static const char *
_getopt_initialize (argc, argv, optstring)
     int argc;
     char *const *argv;
     const char *optstring;
{
  /* Start processing options with ARGV-element 1 (since ARGV-element 0
     is the program name); the sequence of previously skipped
     non-option ARGV-elements is empty.  */

  first_nonopt = last_nonopt = gg_optind;

  nextchar = NULL;

  posixly_correct = getenv ("POSIXLY_CORRECT");

  /* Determine how to handle the ordering of options and nonoptions.  */

  if (optstring[0] == '-')
    {
      ordering = RETURN_IN_ORDER;
      ++optstring;
    }
  else if (optstring[0] == '+')
    {
      ordering = REQUIRE_ORDER;
      ++optstring;
    }
  else if (posixly_correct != NULL)
    ordering = REQUIRE_ORDER;
  else
    ordering = PERMUTE;

#ifdef _LIBC
  if (posixly_correct == NULL
      && argc == original_argc && argv == original_argv)
    {
      if (nonoption_flags_max_len == 0)
	{
	  if (__getopt_nonoption_flags == NULL
	      || __getopt_nonoption_flags[0] == '\0')
	    nonoption_flags_max_len = -1;
	  else
	    {
	      const char *orig_str = __getopt_nonoption_flags;
	      int len = nonoption_flags_max_len = strlen (orig_str);
	      if (nonoption_flags_max_len < argc)
		nonoption_flags_max_len = argc;
	      __getopt_nonoption_flags =
		(char *) malloc (nonoption_flags_max_len);
	      if (__getopt_nonoption_flags == NULL)
		nonoption_flags_max_len = -1;
	      else
		memset (__mempcpy (__getopt_nonoption_flags, orig_str, len),
			'\0', nonoption_flags_max_len - len);
	    }
	}
      nonoption_flags_len = nonoption_flags_max_len;
    }
  else
    nonoption_flags_len = 0;
#endif

  return optstring;
}

/* Scan elements of ARGV (whose length is ARGC) for option characters
   given in OPTSTRING.

   If an element of ARGV starts with '-', and is not exactly "-" or "--",
   then it is an option element.  The characters of this element
   (aside from the initial '-') are option characters.  If `getopt'
   is called repeatedly, it returns successively each of the option characters
   from each of the option elements.

   If `getopt' finds another option character, it returns that character,
   updating `optind' and `nextchar' so that the next call to `getopt' can
   resume the scan with the following option character or ARGV-element.

   If there are no more option characters, `getopt' returns -1.
   Then `optind' is the index in ARGV of the first ARGV-element
   that is not an option.  (The ARGV-elements have been permuted
   so that those that are not options now come last.)

   OPTSTRING is a string containing the legitimate option characters.
   If an option character is seen that is not listed in OPTSTRING,
   return '?' after printing an error message.  If you set `opterr' to
   zero, the error message is suppressed but we still return '?'.

   If a char in OPTSTRING is followed by a colon, that means it wants an arg,
   so the following text in the same ARGV-element, or the text of the following
   ARGV-element, is returned in `optarg'.  Two colons mean an option that
   wants an optional arg; if there is text in the current ARGV-element,
   it is returned in `optarg', otherwise `optarg' is set to zero.

   If OPTSTRING starts with `-' or `+', it requests different methods of
   handling the non-option ARGV-elements.
   See the comments about RETURN_IN_ORDER and REQUIRE_ORDER, above.

   Long-named options begin with `--' instead of `-'.
   Their names may be abbreviated as long as the abbreviation is unique
   or is an exact match for some defined option.  If they have an
   argument, it follows the option name in the same ARGV-element, separated
   from the option name by a `=', or else the in next ARGV-element.
   When `getopt' finds a long-named option, it returns 0 if that option's
   `flag' field is nonzero, the value of the option's `val' field
   if the `flag' field is zero.

   The elements of ARGV aren't really const, because we permute them.
   But we pretend they're const in the prototype to be compatible
   with other systems.

   LONGOPTS is a vector of `struct option' terminated by an
   element containing a name which is zero.

   LONGIND returns the index in LONGOPT of the long-named option found.
   It is only valid when a long-named option has been found by the most
   recent call.

   If LONG_ONLY is nonzero, '-' as well as '--' can introduce
   long-named options.  */

int
_getopt_internal (argc, argv, optstring, longopts, longind, long_only)
     int argc;
     char *const *argv;
     const char *optstring;
     const struct gg_option *longopts;
     int *longind;
     int long_only;
{
  gg_optarg = NULL;

  if (gg_optind == 0 || !__getopt_initialized)
    {
      if (gg_optind == 0)
	gg_optind = 1;	/* Don't scan ARGV[0], the program name.  */
      optstring = _getopt_initialize (argc, argv, optstring);
      __getopt_initialized = 1;
    }

  /* Test whether ARGV[optind] points to a non-option argument.
     Either it does not have option syntax, or there is an environment flag
     from the shell indicating it is not an option.  The later information
     is only used when the used in the GNU libc.  */
#ifdef _LIBC
# define NONOPTION_P (argv[gg_optind][0] != '-' || argv[gg_optind][1] == '\0'	      \
		      || (gg_optind < nonoption_flags_len			      \
			  && __getopt_nonoption_flags[gg_optind] == '1'))
#else
# define NONOPTION_P (argv[gg_optind][0] != '-' || argv[gg_optind][1] == '\0')
#endif

  if (nextchar == NULL || *nextchar == '\0')
    {
      /* Advance to the next ARGV-element.  */

      /* Give FIRST_NONOPT & LAST_NONOPT rational values if OPTIND has been
	 moved back by the user (who may also have changed the arguments).  */
      if (last_nonopt > gg_optind)
	last_nonopt = gg_optind;
      if (first_nonopt > gg_optind)
	first_nonopt = gg_optind;

      if (ordering == PERMUTE)
	{
	  /* If we have just processed some options following some non-options,
	     exchange them so that the options come first.  */

	  if (first_nonopt != last_nonopt && last_nonopt != gg_optind)
	    exchange ((char **) argv);
	  else if (last_nonopt != gg_optind)
	    first_nonopt = gg_optind;

	  /* Skip any additional non-options
	     and extend the range of non-options previously skipped.  */

	  while (gg_optind < argc && NONOPTION_P)
	    gg_optind++;
	  last_nonopt = gg_optind;
	}

      /* The special ARGV-element `--' means premature end of options.
	 Skip it like a null option,
	 then exchange with previous non-options as if it were an option,
	 then skip everything else like a non-option.  */

      if (gg_optind != argc && !strcmp (argv[gg_optind], "--"))
	{
	  gg_optind++;

	  if (first_nonopt != last_nonopt && last_nonopt != gg_optind)
	    exchange ((char **) argv);
	  else if (first_nonopt == last_nonopt)
	    first_nonopt = gg_optind;
	  last_nonopt = argc;

	  gg_optind = argc;
	}

      /* If we have done all the ARGV-elements, stop the scan
	 and back over any non-options that we skipped and permuted.  */

      if (gg_optind == argc)
	{
	  /* Set the next-arg-index to point at the non-options
	     that we previously skipped, so the caller will digest them.  */
	  if (first_nonopt != last_nonopt)
	    gg_optind = first_nonopt;
	  return -1;
	}

      /* If we have come to a non-option and did not permute it,
	 either stop the scan or describe it to the caller and pass it by.  */

      if (NONOPTION_P)
	{
	  if (ordering == REQUIRE_ORDER)
	    return -1;
	  gg_optarg = argv[gg_optind++];
	  return 1;
	}

      /* We have found another option-ARGV-element.
	 Skip the initial punctuation.  */

      nextchar = (argv[gg_optind] + 1
		  + (longopts != NULL && argv[gg_optind][1] == '-'));
    }

  /* Decode the current option-ARGV-element.  */

  /* Check whether the ARGV-element is a long option.

     If long_only and the ARGV-element has the form "-f", where f is
     a valid short option, don't consider it an abbreviated form of
     a long option that starts with f.  Otherwise there would be no
     way to give the -f short option.

     On the other hand, if there's a long option "fubar" and
     the ARGV-element is "-fu", do consider that an abbreviation of
     the long option, just like "--fu", and not "-f" with arg "u".

     This distinction seems to be the most useful approach.  */

  if (longopts != NULL
      && (argv[gg_optind][1] == '-'
	  || (long_only && (argv[gg_optind][2] || !my_index (optstring, argv[gg_optind][1])))))
    {
      char *nameend;
      const struct gg_option *p;
      const struct gg_option *pfound = NULL;
      int exact = 0;
      int ambig = 0;
      int indfound = -1;
      int option_index;

      for (nameend = nextchar; *nameend && *nameend != '='; nameend++)
	/* Do nothing.  */ ;

      /* Test all long options for either exact match
	 or abbreviated matches.  */
      for (p = longopts, option_index = 0; p->name; p++, option_index++)
	if (!strncmp (p->name, nextchar, nameend - nextchar))
	  {
	    if ((unsigned int) (nameend - nextchar)
		== (unsigned int) strlen (p->name))
	      {
		/* Exact match found.  */
		pfound = p;
		indfound = option_index;
		exact = 1;
		break;
	      }
	    else if (pfound == NULL)
	      {
		/* First nonexact match found.  */
		pfound = p;
		indfound = option_index;
	      }
	    else
	      /* Second or later nonexact match found.  */
	      ambig = 1;
	  }

      if (ambig && !exact)
	{
	  if (gg_opterr)
	    fprintf (stderr, _("%s: option `%s' is ambiguous\n"),
		     argv[0], argv[gg_optind]);
	  nextchar += strlen (nextchar);
	  gg_optind++;
	  gg_optopt = 0;
	  return '?';
	}

      if (pfound != NULL)
	{
	  option_index = indfound;
	  gg_optind++;
	  if (*nameend)
	    {
	      /* Don't test has_arg with >, because some C compilers don't
		 allow it to be used on enums.  */
	      if (pfound->has_arg)
		gg_optarg = nameend + 1;
	      else
		{
		  if (gg_opterr)
		    {
		      if (argv[gg_optind - 1][1] == '-')
			/* --option */
			fprintf (stderr,
				 _("%s: option `--%s' doesn't allow an argument\n"),
				 argv[0], pfound->name);
		      else
			/* +option or -option */
			fprintf (stderr,
				 _("%s: option `%c%s' doesn't allow an argument\n"),
				 argv[0], argv[gg_optind - 1][0], pfound->name);
		    }

		  nextchar += strlen (nextchar);

		  gg_optopt = pfound->val;
		  return '?';
		}
	    }
	  else if (pfound->has_arg == 1)
	    {
	      if (gg_optind < argc)
		gg_optarg = argv[gg_optind++];
	      else
		{
		  if (gg_opterr)
		    fprintf (stderr,
			   _("%s: option `%s' requires an argument\n"),
			   argv[0], argv[gg_optind - 1]);
		  nextchar += strlen (nextchar);
		  gg_optopt = pfound->val;
		  return optstring[0] == ':' ? ':' : '?';
		}
	    }
	  nextchar += strlen (nextchar);
	  if (longind != NULL)
	    *longind = option_index;
	  if (pfound->flag)
	    {
	      *(pfound->flag) = pfound->val;
	      return 0;
	    }
	  return pfound->val;
	}

      /* Can't find it as a long option.  If this is not getopt_long_only,
	 or the option starts with '--' or is not a valid short
	 option, then it's an error.
	 Otherwise interpret it as a short option.  */
      if (!long_only || argv[gg_optind][1] == '-'
	  || my_index (optstring, *nextchar) == NULL)
	{
	  if (gg_opterr)
	    {
	      if (argv[gg_optind][1] == '-')
		/* --option */
		fprintf (stderr, _("%s: unrecognized option `--%s'\n"),
			 argv[0], nextchar);
	      else
		/* +option or -option */
		fprintf (stderr, _("%s: unrecognized option `%c%s'\n"),
			 argv[0], argv[gg_optind][0], nextchar);
	    }
	  nextchar = (char *) "";
	  gg_optind++;
	  gg_optopt = 0;
	  return '?';
	}
    }

  /* Look at and handle the next short option-character.  */

  {
    char c = *nextchar++;
    char *temp = my_index (optstring, c);

    /* Increment `optind' when we start to process its last character.  */
    if (*nextchar == '\0')
      ++gg_optind;

    if (temp == NULL || c == ':')
      {
	if (gg_opterr)
	  {
	    if (posixly_correct)
	      /* 1003.2 specifies the format of this message.  */
	      fprintf (stderr, _("%s: illegal option -- %c\n"),
		       argv[0], c);
	    else
	      fprintf (stderr, _("%s: invalid option -- %c\n"),
		       argv[0], c);
	  }
	gg_optopt = c;
	return '?';
      }
    /* Convenience. Treat POSIX -W foo same as long option --foo */
    if (temp[0] == 'W' && temp[1] == ';')
      {
	char *nameend;
	const struct gg_option *p;
	const struct gg_option *pfound = NULL;
	int exact = 0;
	int ambig = 0;
	int indfound = 0;
	int option_index;

	/* This is an option that requires an argument.  */
	if (*nextchar != '\0')
	  {
	    gg_optarg = nextchar;
	    /* If we end this ARGV-element by taking the rest as an arg,
	       we must advance to the next element now.  */
	    gg_optind++;
	  }
	else if (gg_optind == argc)
	  {
	    if (gg_opterr)
	      {
		/* 1003.2 specifies the format of this message.  */
		fprintf (stderr, _("%s: option requires an argument -- %c\n"),
			 argv[0], c);
	      }
	    gg_optopt = c;
	    if (optstring[0] == ':')
	      c = ':';
	    else
	      c = '?';
	    return c;
	  }
	else
	  /* We already incremented `optind' once;
	     increment it again when taking next ARGV-elt as argument.  */
	  gg_optarg = argv[gg_optind++];

	/* optarg is now the argument, see if it's in the
	   table of longopts.  */

	for (nextchar = nameend = gg_optarg; *nameend && *nameend != '='; nameend++)
	  /* Do nothing.  */ ;

	/* Test all long options for either exact match
	   or abbreviated matches.  */
	for (p = longopts, option_index = 0; p->name; p++, option_index++)
	  if (!strncmp (p->name, nextchar, nameend - nextchar))
	    {
	      if ((unsigned int) (nameend - nextchar) == strlen (p->name))
		{
		  /* Exact match found.  */
		  pfound = p;
		  indfound = option_index;
		  exact = 1;
		  break;
		}
	      else if (pfound == NULL)
		{
		  /* First nonexact match found.  */
		  pfound = p;
		  indfound = option_index;
		}
	      else
		/* Second or later nonexact match found.  */
		ambig = 1;
	    }
	if (ambig && !exact)
	  {
	    if (gg_opterr)
	      fprintf (stderr, _("%s: option `-W %s' is ambiguous\n"),
		       argv[0], argv[gg_optind]);
	    nextchar += strlen (nextchar);
	    gg_optind++;
	    return '?';
	  }
	if (pfound != NULL)
	  {
	    option_index = indfound;
	    if (*nameend)
	      {
		/* Don't test has_arg with >, because some C compilers don't
		   allow it to be used on enums.  */
		if (pfound->has_arg)
		  gg_optarg = nameend + 1;
		else
		  {
		    if (gg_opterr)
		      fprintf (stderr, _("\
%s: option `-W %s' doesn't allow an argument\n"),
			       argv[0], pfound->name);

		    nextchar += strlen (nextchar);
		    return '?';
		  }
	      }
	    else if (pfound->has_arg == 1)
	      {
		if (gg_optind < argc)
		  gg_optarg = argv[gg_optind++];
		else
		  {
		    if (gg_opterr)
		      fprintf (stderr,
			       _("%s: option `%s' requires an argument\n"),
			       argv[0], argv[gg_optind - 1]);
		    nextchar += strlen (nextchar);
		    return optstring[0] == ':' ? ':' : '?';
		  }
	      }
	    nextchar += strlen (nextchar);
	    if (longind != NULL)
	      *longind = option_index;
	    if (pfound->flag)
	      {
		*(pfound->flag) = pfound->val;
		return 0;
	      }
	    return pfound->val;
	  }
	  nextchar = NULL;
	  return 'W';	/* Let the application handle it.   */
      }
    if (temp[1] == ':')
      {
	if (temp[2] == ':')
	  {
	    /* This is an option that accepts an argument optionally.  */
	    if (*nextchar != '\0')
	      {
		gg_optarg = nextchar;
		gg_optind++;
	      }
	    else
	      gg_optarg = NULL;
	    nextchar = NULL;
	  }
	else
	  {
	    /* This is an option that requires an argument.  */
	    if (*nextchar != '\0')
	      {
		gg_optarg = nextchar;
		/* If we end this ARGV-element by taking the rest as an arg,
		   we must advance to the next element now.  */
		gg_optind++;
	      }
	    else if (gg_optind == argc)
	      {
		if (gg_opterr)
		  {
		    /* 1003.2 specifies the format of this message.  */
		    fprintf (stderr,
			   _("%s: option requires an argument -- %c\n"),
			   argv[0], c);
		  }
		gg_optopt = c;
		if (optstring[0] == ':')
		  c = ':';
		else
		  c = '?';
	      }
	    else
	      /* We already incremented `optind' once;
		 increment it again when taking next ARGV-elt as argument.  */
	      gg_optarg = argv[gg_optind++];
	    nextchar = NULL;
	  }
      }
    return c;
  }
}

int
gg_getopt (argc, argv, optstring)
     int argc;
     char *const *argv;
     const char *optstring;
{
  return _getopt_internal (argc, argv, optstring,
			   (const struct gg_option *) 0,
			   (int *) 0,
			   0);
}

#endif	/* Not ELIDE_CODE.  */

#ifdef TEST

/* Compile with -DTEST to make an executable for use in testing
   the above definition of `getopt'.  */

int
main (argc, argv)
     int argc;
     char **argv;
{
  int c;
  int digit_optind = 0;

  while (1)
    {
      int this_option_optind = gg_optind ? gg_optind : 1;

      c = gg_getopt (argc, argv, "abc:d:0123456789");
      if (c == -1)
	break;

      switch (c)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	  if (digit_optind != 0 && digit_optind != this_option_optind)
	    printf ("digits occur in two different argv-elements.\n");
	  digit_optind = this_option_optind;
	  printf ("option %c\n", c);
	  break;

	case 'a':
	  printf ("option a\n");
	  break;

	case 'b':
	  printf ("option b\n");
	  break;

	case 'c':
	  printf ("option c with value `%s'\n", gg_optarg);
	  break;

	case '?':
	  break;

	default:
	  printf ("?? getopt returned character code 0%o ??\n", c);
	}
    }

  if (gg_optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (gg_optind < argc)
	printf ("%s ", argv[gg_optind++]);
      printf ("\n");
    }

  exit (0);
}

#endif /* TEST */


/* ===================================================================== */
/* emgena: getopt1.c */
/* ===================================================================== */
/* getopt_long and getopt_long_only entry points for GNU getopt.
   Copyright (C) 1987,88,89,90,91,92,93,94,96,97,98
     Free Software Foundation, Inc.
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



/* #include "gg-getopt.h" */

#if !defined __STDC__ || !__STDC__
/* This is a separate conditional since some stdc systems
   reject `defined (const)'.  */
#ifndef const
#define const
#endif
#endif

#include <stdio.h>

/* Comment out all this code if we are using the GNU C Library, and are not
   actually compiling the library itself.  This code is part of the GNU C
   Library, but also included in many other GNU distributions.  Compiling
   and linking in this code is a waste when using the GNU C library
   (especially if it is a shared library).  Rather than having every GNU
   program understand `configure --with-gnu-libc' and omit the object files,
   it is simpler to just do this in the source for each such file.  */

#define GETOPT_INTERFACE_VERSION 2
#if !defined _LIBC && defined __GLIBC__ && __GLIBC__ >= 2
#include <gnu-versions.h>
#if _GNU_GETOPT_INTERFACE_VERSION == GETOPT_INTERFACE_VERSION
/*#define ELIDE_CODE*/
#endif
#endif

#ifndef ELIDE_CODE


/* This needs to come after some library #include
   to get __GNU_LIBRARY__ defined.  */
#ifdef __GNU_LIBRARY__
#include <stdlib.h>
#endif

#ifndef	NULL
#define NULL 0
#endif

int
gg_getopt_long (argc, argv, options, long_options, opt_index)
     int argc;
     char *const *argv;
     const char *options;
     const struct gg_option *long_options;
     int *opt_index;
{
  return _getopt_internal (argc, argv, options, long_options, opt_index, 0);
}

/* Like getopt_long, but '-' as well as '--' can indicate a long option.
   If an option that starts with '-' (not '--') doesn't match a long option,
   but does match a short option, it is parsed as a short option
   instead.  */

int
getopt_long_only (argc, argv, options, long_options, opt_index)
     int argc;
     char *const *argv;
     const char *options;
     const struct gg_option *long_options;
     int *opt_index;
{
  return _getopt_internal (argc, argv, options, long_options, opt_index, 1);
}


#endif	/* Not ELIDE_CODE.  */

#ifdef TEST

#include <stdio.h>

int
main (argc, argv)
     int argc;
     char **argv;
{
  int c;
  int digit_optind = 0;

  while (1)
    {
      int this_option_optind = gg_optind ? gg_optind : 1;
      int option_index = 0;
      static struct gg_option long_options[] =
      {
	{"add", 1, 0, 0},
	{"append", 0, 0, 0},
	{"delete", 1, 0, 0},
	{"verbose", 0, 0, 0},
	{"create", 0, 0, 0},
	{"file", 1, 0, 0},
	{0, 0, 0, 0}
      };

      c = gg_getopt_long (argc, argv, "abc:d:0123456789",
		       long_options, &option_index);
      if (c == -1)
	break;

      switch (c)
	{
	case 0:
	  printf ("option %s", long_options[option_index].name);
	  if (gg_optarg)
	    printf (" with arg %s", gg_optarg);
	  printf ("\n");
	  break;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	  if (digit_optind != 0 && digit_optind != this_option_optind)
	    printf ("digits occur in two different argv-elements.\n");
	  digit_optind = this_option_optind;
	  printf ("option %c\n", c);
	  break;

	case 'a':
	  printf ("option a\n");
	  break;

	case 'b':
	  printf ("option b\n");
	  break;

	case 'c':
	  printf ("option c with value `%s'\n", gg_optarg);
	  break;

	case 'd':
	  printf ("option d with value `%s'\n", gg_optarg);
	  break;

	case '?':
	  break;

	default:
	  printf ("?? getopt returned character code 0%o ??\n", c);
	}
    }

  if (gg_optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (gg_optind < argc)
	printf ("%s ", argv[gg_optind++]);
      printf ("\n");
    }

  exit (0);
}

#endif /* TEST */



/* random.c */
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

/* #include <limits.h> */
/* #include <assert.h> */

/* #include "random.h" */


/* This is an implementation of the TGFSR (twisted generalized
 * feedback shift register) random number generator TT800, which was
 * published in:
 *
 * Matsumoto, M. and Kurita, Y.: Twisted GFSR generators II.
 * ACM Transactions on Modeling and Computer Simulations,
 * Vol 4, No. 3, July 1994, pp 254--266
 *
 * The generator produces a pseudo-random sequence of 32 bit integers
 * with period 2^800 - 1 and is reported to have excellent
 * equidistribution properties, as well as being fast.
 */


/* Algorithm parameters. */
#define N 25
static const int m = 7;
static const int s = 7;
static const int t = 15;
static const unsigned int a = 0x8ebfd028U;
static const unsigned int b = 0x2b5b2500U;
static const unsigned int c = 0xdb8b0000U;


/* Global state for the random number generator. */
static unsigned int x[N];
static int k;


/* Set when properly seeded. */
static int rand_initialized = 0;

/* We use this to detect whether unsigned ints are bigger than 32
 * bits. If they are we need to clear higher order bits, otherwise we
 * can optimize by not doing the masking.
 */
#define BIG_UINT (UINT_MAX > 0xffffffffU)


/* Iterate the TGFSR once to get a new state which can be used to
 * produce another 25 random numbers.
 */

static void
iterate_tgfsr(void)
{
  int i;
  for (i=0; i<N-m; i++)
    x[i] = x[i+m]   ^  (x[i] >> 1)  ^  ((x[i] & 1) ? a : 0);
  for (; i<N; i++)
    x[i] = x[i+m-N] ^  (x[i] >> 1)  ^  ((x[i] & 1) ? a : 0);
}


/* Produce a random number from the next word of the internal state.
 */

static unsigned int
next_rand(void)
{
  int y;
  if (!rand_initialized) {
    assert(rand_initialized); /* Abort. */
    gg_srand(1);              /* Initialize silently if assertions disabled. */
  }
  if (++k == N) {
    iterate_tgfsr();
    k = 0;
  }
  y = x[k] ^ ((x[k] << s) & b);
  y ^= ((y << t) & c);
#if BIG_UINT
  y &= 0xffffffffU;
#endif
  return y;
}


/* Seed the random number generator. The first word of the internal
 * state is set by the (lower) 32 bits of seed. The remaining 24 words
 * are generated from the first one by a linear congruential pseudo
 * random generator.
 *
 * FIXME: The constants in this generator has not been checked, but
 * since they only are used to produce a very short sequence, which in
 * turn only is a seed to a stronger generator, it probably doesn't
 * matter much.
 */

void
gg_srand(unsigned int seed)
{
  int i;
  for (i = 0; i < N; i++) {
#if BIG_UINT
    seed &= 0xffffffffU;
#endif
    x[i] = seed;
    seed *= 1313;
    seed += 88897;
  }
  k = N-1; /* Force an immediate iteration of the TGFSR. */
  rand_initialized = 1;
}


/* Obtain one random integer value in the interval [0, 2^31-1].
 */

int
gg_rand(void)
{
  return (int) (next_rand() & 0x7fffffff);
}


/* Obtain one random integer value in the interval [0, 2^32-1].
 */

unsigned int
gg_urand(void)
{
  return next_rand();
}


/* Obtain one random floating point value in the half open interval
 * [0.0, 1.0).
 *
 * If the value is converted to a floating point type with less than
 * 32 bits mantissa (or if the double type should happen to be
 * unusually short), the value 1.0 may be attained.
 */

double
gg_drand(void)
{
  return next_rand() * 2.328306436538696e-10;
}


/* Retrieve the internal state of the random generator.
 */

void
gg_get_rand_state(struct gg_rand_state *state)
{
  int i;
  for (i = 0; i < N; i++)
    state->x[i] = x[i];
  state->k = k;
}


/* Set the internal state of the random number generator.
 */

void
gg_set_rand_state(struct gg_rand_state *state)
{
  int i;
  for (i = 0; i < N; i++)
    x[i] = state->x[i];
  k = state->k;
}
/*******************************************************************/


/*
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 2
 * End:
 */
/*******************************************************************/
