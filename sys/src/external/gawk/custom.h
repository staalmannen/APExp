/*
 * custom.h
 *
 * This file is for use on systems where Autoconf isn't quite able to
 * get things right. It is appended to the bottom of config.h by configure,
 * in order to override definitions from Autoconf that are erroneous. See
 * the manual for more information.
 *
 * If you make additions to this file for your system, please send me
 * the information, to arnold@skeeve.com.
 */

/*
 * Copyright (C) 1995-2004, 2008, 2009, 2011, 2016, 2018-2023, 2025, 2026,
 * the Free Software Foundation, Inc.
 *
 * This file is part of GAWK, the GNU implementation of the
 * AWK Programming Language.
 *
 * GAWK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * GAWK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

/* OpenVMS has some definitions in fp.h that should be in math.h */
/* From John Malmberg, wb8tyw@qsl.net */
#ifdef __VMS
#include <fp.h>
/* isnan () macro is broken */
#undef isnan
/* VMS has POSIX confirming limits.h */
#ifndef _REGEX_INCLUDE_LIMITS_H
#define _REGEX_INCLUDE_LIMITS_H 1
#endif
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif /* _GNU_SOURCE */
#ifndef SIZE_MAX
#define SIZE_MAX (__UINT32_MAX)
#endif /* SIZE_MAX */
#define ULONG_WIDTH 32
#ifndef __VAX
#ifndef ULLONG_MAX
#define ULLONG_MAX __UINT64_MAX
#endif /* ULLONG_MAX */
#endif /* __VAX */
#ifndef HAVE_STDINT_H
typedef char int_least8_t;
typedef unsigned char uint_least8_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef unsigned long uint_fast32_t;
typedef long int_fast32_t;
#ifndef __VAX
typedef long long int_fast64_t;
typedef unsigned long long uint_fast64_t;
#endif /* __VAX */
#endif
/* All currently supported OpenVMS compilers appear to have HAVE_C_BOOL.
   The generic config_h.com is used instead of configure is not able to
   understand the extra code in config.h.in so it comments it out.
   This code is needed to activate the stdbool.h
*/
#if (defined(HAVE_C_BOOL) && defined(HAVE_STDBOOL_H))
#include <stdbool.h>
#endif
#endif /* __VMS */

#if defined(_AIX)
#define _XOPEN_SOURCE_EXTENDED 1
#endif

#ifdef __MVS__
#ifndef _REGEX_INCLUDE_LIMITS_H
#define _REGEX_INCLUDE_LIMITS_H 1
#endif
#endif

/* Junk for dfa.[ch] */
/* The __pure__ attribute was added in gcc 2.96.  */
#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 96)
# define _GL_ATTRIBUTE_PURE __attribute__ ((__pure__))
#else
# define _GL_ATTRIBUTE_PURE /* empty */
#endif
#define FLEXIBLE_ARRAY_MEMBER	1
#define xreallocarray xnrealloc
#define xizalloc xzalloc
#define xicalloc xcalloc
#define xirealloc xrealloc
#define ximalloc xmalloc

#ifdef USE_PERSISTENT_MALLOC
#include <stdlib.h>
#include "pma.h"
#define malloc	pma_malloc
#define calloc	pma_calloc
#define realloc	pma_realloc
#define free	pma_free
#else /* ! USE_PERSISTENT_MALLOC */
#define pma_init(verbose, file)	0
#define pma_get_root()	NULL
#define pma_set_root(rootptr)	/* nothing */
#define pma_errno 0
#endif /* ! USE_PERSISTENT_MALLOC */

#ifndef HAVE_STRSIGNAL
extern char *strsignal(int signal);
#endif /* ! HAVE_STRSIGNAL */

/* MinGW Gawk has its own implementation of some wide-character stuff.
   Doing this here ensures all the other sources, including those in
   support/, obey the redirection, because they all include
   config.h.  */
#ifdef __MINGW32__
#undef HAVE_UCHAR_H
#include "pc/mbc32.h"
#include <wctype.h>
#define towlower c32tolower
#define towupper c32toupper
#define iswupper c32isupper
#define iswlower c32islower
#define iswalnum c32isalnum
#define iswctype c32istype
#define iswalpha c32isalpha
#define iswcntrl c32iscntrl
#define iswdigit c32isdigit
#define iswgraph c32isgraph
#define iswprint c32isprint
#define iswpunct c32ispunct
#define iswspace c32isspace
#define iswxdigit c32isxdigit
int c32isalnum (char32_t);
int c32islower (char32_t);
int c32isupper (char32_t);
int c32isalpha (char32_t);
int c32iscntrl (char32_t);
int c32isdigit (char32_t);
int c32isgraph (char32_t);
int c32isprint (char32_t);
int c32ispunct (char32_t);
int c32isspace (char32_t);
int c32isxdigit (char32_t);
int c32istype (char32_t, wctype_t);
char32_t c32toupper (char32_t);
char32_t c32tolower (char32_t);
#ifndef _UCRT
  /* MSVCRT doesn't support "blank".  */
#define wctype   c32type
wctype_t c32type (const char *);
#endif
#define btowc mingw_btowc
wint_t mingw_btowc (int);
#define wctob c32tob
int c32tob (char32_t);

/* We need to override MB_CUR_MAX, so that it takes the console's
   output codepage into account, and allows us to use/support UTF-8 if
   the console output codepage is 65001, even if the current system
   locale is not something.UTF8.  */
#include <ctype.h>
#undef MB_CUR_MAX
#define MB_CUR_MAX (mingw_mb_cur_max())
int mingw_mb_cur_max (void);

#ifndef _UCRT
/* We need to replace stdio functions with console-safe versions from
   Gnulib, to work around a bug in MSVCRT. */
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
extern size_t gl_consolesafe_fwrite (const void *ptr, size_t size,
				     size_t nmemb, FILE *fp);
extern int gl_consolesafe_fprintf (FILE *restrict fp,
				   const char *restrict format, ...);
extern int gl_consolesafe_printf (const char *restrict format, ...);
extern int gl_consolesafe_vfprintf (FILE *restrict fp,
				    const char *restrict format, va_list args);
extern int gl_consolesafe_vprintf (const char *restrict format, va_list args);

#define fwrite gl_consolesafe_fwrite
#define fprintf gl_consolesafe_fprintf
#define printf gl_consolesafe_printf
#define vfprintf gl_consolesafe_vfprintf
#define vprintf gl_consolesafe_vprintf
#endif	/*!_UCRT  */
#endif
