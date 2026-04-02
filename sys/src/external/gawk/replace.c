/*
 * replace.c -- Get replacement versions of functions.
 */

/*
 * Copyright (C) 1989, 1991-2014, 2018, 2022, 2026
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

/*
 * Do all necessary includes here, so that we don't have to worry about
 * overlapping includes in the files in missing.d.
 */
#include "awk.h"	/* includes config.h for us */

#if !defined(HAVE_STRNCASECMP) || !defined(HAVE_STRCASECMP)
#include "missing_d/strncasecmp.c"
#endif	/* HAVE_STRCASE */

#ifndef HAVE_STRFTIME
# ifdef __MINGW32__
/* Need to use underlying_strftime in replacement strftime.  */
#  define HAVE_STRFTIME 1
# endif
#include "missing_d/strftime.c"
# ifdef __MINGW32__
#  undef HAVE_STRFTIME
# endif
#endif  /* HAVE_STRFTIME */

#ifndef HAVE_TIMEGM
#include "missing_d/timegm.c"
#endif /* HAVE_TIMEGM */

#if defined(HAVE_SOCKETS) && ! defined(HAVE_GETADDRINFO)
#include "missing_d/getaddrinfo.c"
#endif

#ifndef HAVE_STRCOLL
#include "missing_d/strcoll.c"
#endif

#ifndef HAVE_STRSIGNAL
#include "missing_d/strsignal.c"
#endif

#if defined(__MINGW32__) && !defined(_UCRT)
/* We need to work around the MSVCRT bug when writing multibyte
   strings to the console.  */
# if !defined(__MINGW32_MAJOR_VERSION) || __MINGW32_MAJOR_VERSION < 5
   /* MinGW64 has vasprintf, mingw.org's MinGW doesn't. */
#  define HAVE_VASPRINTF 1
# endif
#include "missing_d/stdio-consolesafe.c"
#endif
