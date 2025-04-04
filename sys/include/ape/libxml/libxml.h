/* libxml2 - Library for parsing XML documents
 * Copyright (C) 2006-2019 Free Software Foundation, Inc.
 *
 * This file is not part of the GNU gettext program, but is used with
 * GNU gettext.
 *
 * The original copyright notice is as follows:
 */

/*
 * Copyright (C) 1998-2012 Daniel Veillard.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is fur-
 * nished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FIT-
 * NESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * Author: breese@users.sourceforge.net
 */

/*
 * libxml.h: internal header only used during the compilation of libxml
 */

#ifndef __XML_LIBXML_H__
#define __XML_LIBXML_H__

#ifndef NO_LARGEFILE_SOURCE
#ifndef _LARGEFILE_SOURCE
#define _LARGEFILE_SOURCE
#endif
#ifndef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#endif
#endif

#if defined(macintosh)
#include "config-mac.h"
#elif defined(_WIN32_WCE)
/*
 * Windows CE compatibility definitions and functions
 * This is needed to compile libxml2 for Windows CE.
 * At least I tested it with WinCE 5.0 for Emulator and WinCE 4.2/SH4 target
 */
#include <win32config.h>
#include <libxml/xmlversion.h>
#else
/*
 * Currently supported platforms use either autoconf or
 * copy to config.h own "preset" configuration file.
 * As result ifdef HAVE_CONFIG_H is omited here.
 */
#include "config.h"
#include <libxml/xmlversion.h>
#endif

#if defined(__Lynx__)
#include <stdio.h> /* pull definition of size_t */
#include <varargs.h>
int snprintf(char *, size_t, const char *, ...);
int vfprintf(FILE *, const char *, va_list);
#endif

#ifndef WITH_TRIO
#include <stdio.h>
#else
/**
 * TRIO_REPLACE_STDIO:
 *
 * This macro is defined if teh trio string formatting functions are to
 * be used instead of the default stdio ones.
 */
#define TRIO_REPLACE_STDIO
#include "trio.h"
#endif

#if defined(__clang__) || \
    (defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ >= 406))
#define XML_IGNORE_PEDANTIC_WARNINGS \
    _Pragma("GCC diagnostic push") \
    _Pragma("GCC diagnostic ignored \"-Wpedantic\"")
#define XML_POP_WARNINGS \
    _Pragma("GCC diagnostic pop")
#else
#define XML_IGNORE_PEDANTIC_WARNINGS
#define XML_POP_WARNINGS
#endif

#include <libxml/xmlstring.h>

/*
 * Internal variable indicating if a callback has been registered for
 * node creation/destruction. It avoids spending a lot of time in locking
 * function while checking if the callback exists.
 */
extern int __xmlRegisterCallbacks;
/*
 * internal error reporting routines, shared but not partof the API.
 */
void __xmlIOErr(int domain, int code, const char *extra);
void __xmlLoaderErr(void *ctx, const char *msg, const char *filename) LIBXML_ATTR_FORMAT(2,0);
#ifdef LIBXML_HTML_ENABLED
/*
 * internal function of HTML parser needed for xmlParseInNodeContext
 * but not part of the API
 */
void __htmlParseContent(void *ctx);
#endif

/*
 * internal global initialization critical section routines.
 */
void __xmlGlobalInitMutexLock(void);
void __xmlGlobalInitMutexUnlock(void);
void __xmlGlobalInitMutexDestroy(void);

int __xmlInitializeDict(void);

#if defined(HAVE_RAND) && defined(HAVE_SRAND) && defined(HAVE_TIME)
/*
 * internal thread safe random function
 */
int __xmlRandom(void);
#endif

XMLPUBFUN xmlChar * XMLCALL xmlEscapeFormatString(xmlChar **msg);
int xmlInputReadCallbackNop(void *context, char *buffer, int len);

#ifdef IN_LIBXML
#ifdef __GNUC__
#ifdef PIC
#ifdef __linux__
#endif
#endif
#endif
#endif
#if !defined(PIC) && !defined(NOLIBTOOL) && !defined(LIBXML_STATIC)
# define LIBXML_STATIC 1
#endif
#endif /* ! __XML_LIBXML_H__ */
