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
 * Copyright (C) 1995-2004, 2008, 2009, 2011, 2016, 2018-2023,
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

/* for Plan9 by Jens Staal */
#ifdef PLAN9
#define DEFPATH "/sys/lib/ape/awk"
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
char * strsignal(int signal);
#endif /* ! HAVE_STRSIGNAL */
