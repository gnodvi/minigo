/* config.h.  Generated automatically by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Connection module. Default standard. */
#define ALTERNATE_CONNECTIONS 1

/* Define to use ansi escape sequences for color debugging */
/* #undef ANSI_COLOR */

/* Ruleset. Default Japanese */
#define CHINESE_RULES 0

/* Define to use curses for color debugging */
#define CURSES 1

/* Default level (strength). Up to 10 supported */
#define DEFAULT_LEVEL 10

/* Default hash table size in megabytes */
#define DEFAULT_MEMORY 8

/* Semeai Variations. 250 default */
#define DEFAULT_SEMEAI_VARIATIONS 250

/* Connection module. Default standard. */
#define EXPERIMENTAL_CONNECTIONS 1

/* Influence module. Default experimental. */
#define EXPERIMENTAL_INFLUENCE 1

/* Experimental pattern based reading. Disabled by default. */
#define EXPERIMENTAL_READING 0

/* Semeai module. Default standard. */
#define EXPERIMENTAL_SEMEAI 0

/* Give the directory where gnugo was compiled */
#define GNUGO_PATH "/mnt/max3d1/s1233/MGENA/golife/gnugo-3.2"

/* The concatenation of the strings "GNU ", and PACKAGE. */
#define GNU_PACKAGE "GNU gnugo"

/* Define as 1 to use the grid optimisation, or 2 to run it in self-test mode
   */
#define GRID_OPT 1

/* Hashing scheme. Default scheme 2 (new). */
#define HASHING_SCHEME 2


/* Define if you have the `alarm' function. */
#define HAVE_ALARM 1

/* Define if the curses headers defines KEY_{UP,DOWN,LEFT,RIGHT} */
#define HAVE_CURSES_ARROWS 1

/* Define if you have the <curses.h> header file. */
#define HAVE_CURSES_H 1

/* Define if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the <glib.h> header file. */
/* #undef HAVE_GLIB_H */

/* Define if you have the `g_vsnprintf' function. */
/* #undef HAVE_G_VSNPRINTF */

/* Define if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define if you have the `keypad' function. */
#define HAVE_KEYPAD 1

/* Define if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define if you have the <ncurses/curses.h> header file. */
#define HAVE_NCURSES_CURSES_H 1

/* Define if you have the <ncurses/term.h> header file. */
#define HAVE_NCURSES_TERM_H 1

/* Define if you have the `setlinebuf' function. */
#define HAVE_SETLINEBUF 1

/* Define if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define if you have the <sys/times.h> header file. */
#define HAVE_SYS_TIMES_H 1

/* Define if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define if you have the <term.h> header file. */
#define HAVE_TERM_H 1

/* Define if you have the `times' function. */
#define HAVE_TIMES 1

/* Define if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define if you have the `usleep' function. */
#define HAVE_USLEEP 1

/* Define if #define can take a variable number of arguments */
#define HAVE_VARIADIC_DEFINE 1

/* Define if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF 1

/* Define if you have the `vwprintw' function. */
#define HAVE_VWPRINTW 1

/* Define if the preprocessor recognizes __FUNCTION__ */
#define HAVE___FUNCTION__ 1

/* Define if `major', `minor', and `makedev' are declared in <mkdev.h>. */
/* #undef MAJOR_IN_MKDEV */

/* Define if `major', `minor', and `makedev' are declared in <sysmacros.h>. */
/* #undef MAJOR_IN_SYSMACROS */

/* Owl Threats. 0 standard. */
#define OWL_THREATS 0

/* Name of package */
#define PACKAGE "gnugo"

/* The size of a `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of a `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* Define if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if termcap/terminfo is available. */
#define TERMINFO 0
/* emgena */
/* #define TERMINFO 1 */

/* Define if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Version number of package */
#define VERSION "3.2"

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */


#ifdef MYWINDOWS
/*==============================================*/
#undef HAVE_UNISTD_H
#undef TIME_WITH_SYS_TIME
#undef HAVE_SYS_TIME_H
#undef HAVE_VARIADIC_DEFINE
#undef HAVE_SYS_TIMES_H

#undef HAVE_GETTIMEOFDAY
#undef HAVE_ALARM
#undef HAVE_VSNPRINTF
/*==============================================*/
#endif

