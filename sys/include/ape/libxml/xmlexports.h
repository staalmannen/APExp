/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
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
 * Author: Igor Zlatovic <igor@zlatkovic.com>
 */

/*
 * Summary: macros for marking symbols as exportable/importable.
 * Description: macros for marking symbols as exportable/importable.
 */

#ifndef __XML_EXPORTS_H__
#define __XML_EXPORTS_H__

#pragma lib "/$M/lib/ape/libxml.a"

/**
 * XMLPUBFUN, XMLPUBVAR, XMLCALL
 *
 * Macros which declare an exportable function, an exportable variable and
 * the calling convention used for functions.
 *
 * Please use an extra block for every platform/compiler combination when
 * modifying this, rather than overlong #ifdef lines. This helps
 * readability as well as the fact that different compilers on the same
 * platform might need different definitions.
 */

/**
 * XMLPUBFUN:
 *
 * Macros which declare an exportable function
 */
#define XMLPUBFUN
/**
 * XMLPUBVAR:
 *
 * Macros which declare an exportable variable
 */
#define XMLPUBVAR extern
/**
 * XMLCALL:
 *
 * Macros which declare the called convention for exported functions
 */
#define XMLCALL
/**
 * XMLCDECL:
 *
 * Macro which declares the calling convention for exported functions that
 * use '...'.
 */
#define XMLCDECL

/** DOC_DISABLE */

/* Windows platform with MS compiler */
#if defined(_WIN32) && defined(_MSC_VER)
  #undef XMLPUBFUN
  #undef XMLPUBVAR
  #undef XMLCALL
  #undef XMLCDECL
  #if defined(IN_LIBXML) && !defined(LIBXML_STATIC)
    #define XMLPUBFUN __declspec(dllexport)
    #define XMLPUBVAR __declspec(dllexport)
  #else
    #define XMLPUBFUN
    #if !defined(LIBXML_STATIC)
      #define XMLPUBVAR __declspec(dllimport) extern
    #else
      #define XMLPUBVAR extern
    #endif
  #endif
  #if defined(LIBXML_FASTCALL)
    #define XMLCALL __fastcall
  #else
    #define XMLCALL __cdecl
  #endif
  #define XMLCDECL __cdecl
  #if !defined _REENTRANT
    #define _REENTRANT
  #endif
#endif

/* Windows platform with Borland compiler */
#if defined(_WIN32) && defined(__BORLANDC__)
  #undef XMLPUBFUN
  #undef XMLPUBVAR
  #undef XMLCALL
  #undef XMLCDECL
  #if defined(IN_LIBXML) && !defined(LIBXML_STATIC)
    #define XMLPUBFUN __declspec(dllexport)
    #define XMLPUBVAR __declspec(dllexport) extern
  #else
    #define XMLPUBFUN
    #if !defined(LIBXML_STATIC)
      #define XMLPUBVAR __declspec(dllimport) extern
    #else
      #define XMLPUBVAR extern
    #endif
  #endif
  #define XMLCALL __cdecl
  #define XMLCDECL __cdecl
  #if !defined _REENTRANT
    #define _REENTRANT
  #endif
#endif

/* Windows platform with GNU compiler (Mingw) */
#if defined(_WIN32) && defined(__MINGW32__)
  #undef XMLPUBFUN
  #undef XMLPUBVAR
  #undef XMLCALL
  #undef XMLCDECL
  /*
   * if defined(IN_LIBXML) this raises problems on mingw with msys
   * _imp__xmlFree listed as missing. Try to workaround the problem
   * by also making that declaration when compiling client code.
   */
  #if defined(IN_LIBXML) && !defined(LIBXML_STATIC)
    #define XMLPUBFUN __declspec(dllexport)
    #define XMLPUBVAR __declspec(dllexport) extern
  #else
    #define XMLPUBFUN
    #if !defined(LIBXML_STATIC)
      #define XMLPUBVAR __declspec(dllimport) extern
    #else
      #define XMLPUBVAR extern
    #endif
  #endif
  #define XMLCALL __cdecl
  #define XMLCDECL __cdecl
  #if !defined _REENTRANT
    #define _REENTRANT
  #endif
#endif

/* Cygwin platform (does not define _WIN32), GNU compiler */
#if defined(__CYGWIN__)
  #undef XMLPUBFUN
  #undef XMLPUBVAR
  #undef XMLCALL
  #undef XMLCDECL
  #if defined(IN_LIBXML) && !defined(LIBXML_STATIC)
    #define XMLPUBFUN __declspec(dllexport)
    #define XMLPUBVAR __declspec(dllexport)
  #else
    #define XMLPUBFUN
    #if !defined(LIBXML_STATIC)
      #define XMLPUBVAR __declspec(dllimport) extern
    #else
      #define XMLPUBVAR extern
    #endif
  #endif
  #define XMLCALL __cdecl
  #define XMLCDECL __cdecl
#endif

/* Compatibility */
#if !defined(LIBXML_DLL_IMPORT)
#define LIBXML_DLL_IMPORT XMLPUBVAR
#endif

#endif /* __XML_EXPORTS_H__ */


