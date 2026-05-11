/* chicken.h - General headerfile for compiler generated executables
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
; conditions are met:
;
;   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
;     disclaimer.
;   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
;     disclaimer in the documentation and/or other materials provided with the distribution.
;   Neither the name of the author nor the names of its contributors may be used to endorse or promote
;     products derived from this software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
; OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
; AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
; CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
; CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
; OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
; POSSIBILITY OF SUCH DAMAGE.
*/

/* Configuration: */

#ifndef ___CHICKEN
#define ___CHICKEN

#define C_MAJOR_VERSION   5
#define C_MINOR_VERSION   4

#ifndef _ISOC99_SOURCE
# define _ISOC99_SOURCE
#endif

#ifndef __C99FEATURES__
# define __C99FEATURES__
#endif

/*
 * N.B. This file MUST not rely upon "chicken-config.h"
 */
#if defined(HAVE_CHICKEN_CONFIG_H)
# include "chicken-config.h"
#endif

/* Some OSes really dislike feature macros for standard levels */
#ifdef C_USE_STD_FEATURE_MACROS

# ifndef _XOPEN_SOURCE
#  define _XOPEN_SOURCE 700
# endif

# ifndef _BSD_SOURCE
#  define _BSD_SOURCE
# endif

# ifndef _NETBSD_SOURCE
#  define _NETBSD_SOURCE
# endif

# ifndef _SVID_SOURCE
#  define _SVID_SOURCE
# endif

/*
 * glibc >= 2.20 synonym for _BSD_SOURCE & _SVID_SOURCE.
 */
# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

#endif /* C_USE_STD_FEATURE_MACROS */

/* Kind of platform */

#if defined(__LP64__) || defined(_LP64) || defined(__MINGW64__) || defined(_WIN64)
# define C_SIXTY_FOUR
#endif

#if defined(__APPLE__) && defined(__MACH__)
# define C_MACOSX
#endif

#if defined(C_MACOSX) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
# define C_XXXBSD
#endif

#if /*defined(__GNUC__) &&*/ (defined(__linux__) || defined(C_XXXBSD) || defined(__HAIKU__))
# define C_GNU_ENV
#endif

#if defined(__MINGW32__)
/*
 * XXX This should probably be renamed or changed because it's misleading.
 * For example, Haiku is not a Unix either, but this doesn't get defined there.
 */
# define C_NONUNIX
#endif

#if defined(__sun) && defined(__SVR4)
# define C_SOLARIS
#endif

#if defined(__MINGW64__) || defined(_WIN64)
# define C_LLP
#endif

/* Declare base Win32 version: we require Vista or later */

#ifdef __MINGW32__
# define _WIN32_WINNT 0x0600
#endif


/* Headers */

#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


/* Byteorder in machine word */

#if defined(__MINGW32__)
# include <sys/param.h>
#elif defined(__CYGWIN__)
# include <endian.h>
#elif defined(__linux__)
# include <endian.h>
#elif defined(C_XXXBSD)
# include <machine/endian.h>
#elif defined(__hpux__)
# include <arpa/nameser.h>
#elif defined(_AIX)
# include <sys/machine.h>
#elif defined(__sun)
# include <sys/isa_defs.h>
#elif defined(__SVR4)
# include <sys/byteorder.h>
#endif

#if defined(__MINGW32__)
# include <malloc.h>
#endif

/* Much better with stack allocation API */

#ifdef HAVE_ALLOCA_H
# include <alloca.h>
#elif !defined(alloca) /* predefined by HP cc +Olibcalls */
void *alloca ();
#endif


/* CHICKEN Core C API */

#if defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN
# define C_BIG_ENDIAN
#elif defined(BYTE_ORDER) && defined(BIG_ENDIAN) && BYTE_ORDER == BIG_ENDIAN
# define C_BIG_ENDIAN
#elif defined(__BIG_ENDIAN__)
# define C_BIG_ENDIAN
#elif defined(__MIPSEL__) || defined(__MIPSEL)
# define C_LITTLE_ENDIAN
#elif defined(__sparc__) || defined(__POWERPC__) || defined(__MC68K__) || defined(__mips__)
# define C_BIG_ENDIAN
#endif

#if defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && __BYTE_ORDER == __LITTLE_ENDIAN
# define C_LITTLE_ENDIAN
#elif defined(BYTE_ORDER) && defined(LITTLE_ENDIAN) && BYTE_ORDER == LITTLE_ENDIAN
# define C_LITTLE_ENDIAN
#elif defined(__LITTLE_ENDIAN__)
# define C_LITTLE_ENDIAN
#elif defined (__alpha__) || defined(_M_IX86) || defined(__i386__) || defined(__x86_64__) || defined(__ia64__)
# define C_LITTLE_ENDIAN
#endif

/* Make sure some common C identifiers are availble w/ Windows */

/* Could be used by C++ source */

#ifdef __cplusplus
# define C_extern                  extern "C"
# define C_BEGIN_C_DECLS           extern "C" {
# define C_END_C_DECLS             }
#else
# define C_extern                  extern
# define C_BEGIN_C_DECLS
# define C_END_C_DECLS
#endif


/* Function declaration modes */

/* Visibility */
#define C_varextern                C_extern
#define C_fctimport
#define C_fctexport
#define C_externimport             C_extern
#define C_externexport             C_extern
#if defined(PIC)
# if defined(__CYGWIN__) || defined(__MINGW32__)
#  ifndef C_BUILDING_LIBCHICKEN
#   undef  C_varextern
#   define C_varextern             C_extern __declspec(dllimport)
#  endif
# endif
#endif

/* Language specifics: */
#if defined(__GNUC__) || defined(__INTEL_COMPILER)
#define HAVE_STATEMENT_EXPRESSIONS 1
#endif

#if !defined(__clang__) && !defined(__has_attribute)
/* Define so it won't error on other compilers with keywords like "noreturn" */
#define __has_attribute(x)        0
#endif

#if defined(__GNUC__) || defined(__INTEL_COMPILER)
# define C_unlikely(x)             __builtin_expect((x), 0)
# define C_likely(x)               __builtin_expect((x), 1)
# ifndef __cplusplus
#  define C_cblock                ({
#  define C_cblockend             })
#  if defined(__clang__) && !__has_attribute(noreturn)
#   define C_noret
#  else
#   define C_noret                __attribute__ ((noreturn))
#  endif
#  define C_noret_decl(name)
#  define C_aligned               __attribute__ ((aligned))
# endif
# if defined(__i386__) && !defined(__clang__)
#  define C_regparm               __attribute__ ((regparm(3)))
# endif
#else
# define C_unlikely(x)             (x)
# define C_likely(x)               (x)
#endif

#ifndef C_cblock
# define C_cblock                 do{
# define C_cblockend              }while(0)
# define C_noret
# define C_noret_decl(name)
#endif

#ifndef C_regparm
# define C_regparm
#endif

#ifndef C_fcall
# define C_fcall
#endif

#ifndef C_ccall
# define C_ccall
#endif

#ifndef C_aligned
# define C_aligned
#endif

/* Thread Local Storage */
#ifdef C_ENABLE_TLS
# if defined(__GNUC__)
#  define C_TLS                    __thread
# endif
#endif

#ifndef C_TLS
# define C_TLS
#endif


/* Stack growth direction; used to compute stack addresses */
#ifndef C_STACK_GROWS_DOWNWARD
# ifdef __hppa__
#  define C_STACK_GROWS_DOWNWARD 0
# else
#  define C_STACK_GROWS_DOWNWARD 1
# endif
#endif

/* Have a GUI? */

#if defined(C_GUI) || defined(C_PRIVATE_REPOSITORY)
# ifdef _WIN32
#  include <windows.h>
#  ifndef WINAPI
#   define WINAPI
#  endif
# endif
#endif

/* Needed for pre-emptive threading */

#define C_TIMER_INTERRUPTS


/* Constants: */

#define C_STACK_RESERVE                   0x10000
#define C_DEFAULT_MAX_PENDING_FINALIZERS  2048

#define C_IMMEDIATE_MARK_BITS     0x00000003
#define C_IMMEDIATE_TYPE_BITS     0x0000000f

#define C_BOOLEAN_BITS            0x00000006
#define C_CHARACTER_BITS          0x0000000a
#define C_SPECIAL_BITS            0x0000000e

#define C_SCHEME_FALSE            ((C_word)(C_BOOLEAN_BITS | 0x00000000))
#define C_SCHEME_TRUE             ((C_word)(C_BOOLEAN_BITS | 0x00000010))

#define C_SCHEME_END_OF_LIST      ((C_word)(C_SPECIAL_BITS | 0x00000000))
#define C_SCHEME_UNDEFINED        ((C_word)(C_SPECIAL_BITS | 0x00000010))
#define C_SCHEME_UNBOUND          ((C_word)(C_SPECIAL_BITS | 0x00000020))
#define C_SCHEME_END_OF_FILE      ((C_word)(C_SPECIAL_BITS | 0x00000030))
#define C_SCHEME_BROKEN_WEAK_PTR  ((C_word)(C_SPECIAL_BITS | 0x00000040))

#define C_FIXNUM_BIT              0x00000001
#define C_FIXNUM_SHIFT            1

/* Character range is that of a UTF-8 codepoint, not representable range */
#define C_CHAR_BIT_MASK           0x1fffff
#define C_CHAR_SHIFT              8

#ifdef C_SIXTY_FOUR
# define C_MOST_POSITIVE_FIXNUM   0x3fffffffffffffffL
# define C_WORD_SIZE              64
# define C_HALF_WORD_SIZE         32
#else
# define C_MOST_POSITIVE_FIXNUM   0x3fffffff
# define C_WORD_SIZE              32
# define C_HALF_WORD_SIZE         16
#endif

/* Tunable performance-related constants */
#ifndef C_KARATSUBA_THRESHOLD
/* This defines when we'll switch from schoolbook to Karatsuba
 * multiplication.  The smallest of the two numbers determines the
 * switch.  It is pretty high right now because it generates a bit
 * more garbage and GC overhead dominates the algorithmic performance
 * gains.  If the GC is improved, this can be readjusted.
 */
# define C_KARATSUBA_THRESHOLD        70
#endif
#ifndef C_BURNIKEL_ZIEGLER_THRESHOLD
/* This defines when to switch from schoolbook to Burnikel-Ziegler
 * division.  It creates even more garbage than Karatsuba :(
 */
# define C_BURNIKEL_ZIEGLER_THRESHOLD 300
#endif
#ifndef C_RECURSIVE_TO_STRING_THRESHOLD
/* This threshold is in terms of the expected string length. */
# define C_RECURSIVE_TO_STRING_THRESHOLD 750
#endif

/* These might fit better in runtime.c? */
#define C_fitsinbignumhalfdigitp(n)     (C_BIGNUM_DIGIT_HI_HALF(n) == 0)
#define C_BIGNUM_DIGIT_LENGTH           C_WORD_SIZE
#define C_BIGNUM_HALF_DIGIT_LENGTH      C_HALF_WORD_SIZE
#define C_BIGNUM_BITS_TO_DIGITS(n) \
        (((n) + (C_BIGNUM_DIGIT_LENGTH - 1)) / C_BIGNUM_DIGIT_LENGTH)
#define C_BIGNUM_DIGIT_LO_HALF(d)       (C_uhword)(d)
#define C_BIGNUM_DIGIT_HI_HALF(d)       (C_uhword)((d) >> C_BIGNUM_HALF_DIGIT_LENGTH)
#define C_BIGNUM_DIGIT_COMBINE(h,l)     ((C_uword)(h) << C_BIGNUM_HALF_DIGIT_LENGTH|(C_uhword)(l))

#define C_MOST_POSITIVE_32_BIT_FIXNUM  0x3fffffff
#define C_MOST_NEGATIVE_FIXNUM    (-C_MOST_POSITIVE_FIXNUM - 1)

#ifdef C_SIXTY_FOUR
# define C_INT_SIGN_BIT           0x8000000000000000L
# define C_INT_TOP_BIT            0x4000000000000000L
# define C_HEADER_BITS_MASK       0xff00000000000000L
# define C_HEADER_TYPE_BITS       0x0f00000000000000L
# define C_HEADER_SIZE_MASK       0x00ffffffffffffffL
# define C_GC_FORWARDING_BIT      0x8000000000000000L   /* header contains forwarding pointer */
# define C_BYTEBLOCK_BIT          0x4000000000000000L   /* block contains bytes instead of slots */
# define C_SPECIALBLOCK_BIT       0x2000000000000000L   /* 1st item is a non-value */
# define C_8ALIGN_BIT             0x1000000000000000L   /* data is aligned to 8-byte boundary */

# define C_SYMBOL_TYPE            (0x0100000000000000L)
# define C_STRING_TYPE            (0x0200000000000000L | C_BYTEBLOCK_BIT)
# define C_PAIR_TYPE              (0x0300000000000000L)
# define C_CLOSURE_TYPE           (0x0400000000000000L | C_SPECIALBLOCK_BIT)
# define C_FLONUM_TYPE            (0x0500000000000000L | C_BYTEBLOCK_BIT | C_8ALIGN_BIT)
# define C_BIGNUM_TYPE            (0x0600000000000000L) /* Just the wrapper */
# define C_PORT_TYPE              (0x0700000000000000L | C_SPECIALBLOCK_BIT)
# define C_STRUCTURE_TYPE         (0x0800000000000000L)
# define C_POINTER_TYPE           (0x0900000000000000L | C_SPECIALBLOCK_BIT)
# define C_LOCATIVE_TYPE          (0x0a00000000000000L | C_SPECIALBLOCK_BIT)
# define C_TAGGED_POINTER_TYPE    (0x0b00000000000000L | C_SPECIALBLOCK_BIT)
# define C_RATNUM_TYPE            (0x0c00000000000000L)
# define C_LAMBDA_INFO_TYPE       (0x0d00000000000000L | C_BYTEBLOCK_BIT)
# define C_CPLXNUM_TYPE           (0x0e00000000000000L)
/*       unused                   (0x0f00000000000000L ...) */
#else
# define C_INT_SIGN_BIT           0x80000000
# define C_INT_TOP_BIT            0x40000000
# define C_HEADER_BITS_MASK       0xff000000
# define C_HEADER_TYPE_BITS       0x0f000000
# define C_HEADER_SIZE_MASK       0x00ffffff
# define C_GC_FORWARDING_BIT      0x80000000
# define C_BYTEBLOCK_BIT          0x40000000
# define C_SPECIALBLOCK_BIT       0x20000000
# define C_8ALIGN_BIT             0x10000000

# define C_SYMBOL_TYPE            (0x01000000)
# define C_STRING_TYPE            (0x02000000 | C_BYTEBLOCK_BIT)
# define C_PAIR_TYPE              (0x03000000)
# define C_CLOSURE_TYPE           (0x04000000 | C_SPECIALBLOCK_BIT)
# ifdef C_DOUBLE_IS_32_BITS
#  define C_FLONUM_TYPE           (0x05000000 | C_BYTEBLOCK_BIT)
# else
#  define C_FLONUM_TYPE           (0x05000000 | C_BYTEBLOCK_BIT | C_8ALIGN_BIT)
# endif
# define C_BIGNUM_TYPE            (0x06000000) /* Just the wrapper */
# define C_PORT_TYPE              (0x07000000 | C_SPECIALBLOCK_BIT)
# define C_STRUCTURE_TYPE         (0x08000000)
# define C_POINTER_TYPE           (0x09000000 | C_SPECIALBLOCK_BIT)
# define C_LOCATIVE_TYPE          (0x0a000000 | C_SPECIALBLOCK_BIT)
# define C_TAGGED_POINTER_TYPE    (0x0b000000 | C_SPECIALBLOCK_BIT)
# define C_RATNUM_TYPE            (0x0c000000)
# define C_LAMBDA_INFO_TYPE       (0x0d000000 | C_BYTEBLOCK_BIT)
# define C_CPLXNUM_TYPE           (0x0e000000)
/*       unused                   (0x0f000000 ...) */
#endif
#define C_VECTOR_TYPE             0x00000000
#define C_BYTEVECTOR_TYPE         (C_VECTOR_TYPE | C_BYTEBLOCK_BIT | C_8ALIGN_BIT)

#define C_SIZEOF_LIST(n)          ((n) * 3 + 1)
#define C_SIZEOF_PAIR             3
#define C_SIZEOF_STRING(n)        (C_bytestowords(n) + 2)
#define C_SIZEOF_SYMBOL           4
#define C_SIZEOF_INTERNED_SYMBOL(n) (C_SIZEOF_SYMBOL + C_SIZEOF_PAIR + C_SIZEOF_STRING(n))
#ifdef C_DOUBLE_IS_32_BITS
# define C_SIZEOF_FLONUM          2
#else
# define C_SIZEOF_FLONUM          4
#endif
#define C_SIZEOF_POINTER          2
#define C_SIZEOF_TAGGED_POINTER   3
#define C_SIZEOF_VECTOR(n)        ((n) + 1)
#define C_SIZEOF_LOCATIVE         5
#define C_SIZEOF_PORT             16
#define C_SIZEOF_RATNUM           3
#define C_SIZEOF_CPLXNUM          3
#define C_SIZEOF_STRUCTURE(n)     ((n)+1)
#define C_SIZEOF_CLOSURE(n)       ((n)+1)
#define C_SIZEOF_BYTEVECTOR       C_SIZEOF_STRING
#define C_SIZEOF_INTERNAL_BIGNUM_VECTOR(n) (C_SIZEOF_VECTOR((n)+1))
#define C_internal_bignum_vector(b)        (C_block_item(b,0))

/* This is for convenience and allows flexibility in representation */
#define C_SIZEOF_FIX_BIGNUM       C_SIZEOF_BIGNUM(1)
#define C_SIZEOF_BIGNUM_WRAPPER   2
#define C_SIZEOF_BIGNUM(n)        (C_SIZEOF_INTERNAL_BIGNUM_VECTOR(n)+C_SIZEOF_BIGNUM_WRAPPER)

/* Fixed size types have pre-computed header tags */
#define C_PAIR_TAG                (C_PAIR_TYPE | (C_SIZEOF_PAIR - 1))
#define C_WEAK_PAIR_TAG           (C_PAIR_TAG | C_SPECIALBLOCK_BIT)
#define C_POINTER_TAG             (C_POINTER_TYPE | (C_SIZEOF_POINTER - 1))
#define C_LOCATIVE_TAG            (C_LOCATIVE_TYPE | (C_SIZEOF_LOCATIVE - 1))
#define C_TAGGED_POINTER_TAG      (C_TAGGED_POINTER_TYPE | (C_SIZEOF_TAGGED_POINTER - 1))
#define C_SYMBOL_TAG              (C_SYMBOL_TYPE | (C_SIZEOF_SYMBOL - 1))
#define C_FLONUM_TAG              (C_FLONUM_TYPE | sizeof(double))
#define C_BIGNUM_TAG              (C_BIGNUM_TYPE | 1)
#define C_RATNUM_TAG              (C_RATNUM_TYPE | 2)
#define C_CPLXNUM_TAG             (C_CPLXNUM_TYPE | 2)

/* Locative subtypes */
#define C_SLOT_LOCATIVE           0
#define C_CHAR_LOCATIVE           1
#define C_U8_LOCATIVE             2
#define C_S8_LOCATIVE             3
#define C_U16_LOCATIVE            4
#define C_S16_LOCATIVE            5
#define C_U32_LOCATIVE            6
#define C_S32_LOCATIVE            7
#define C_U64_LOCATIVE            8
#define C_S64_LOCATIVE            9
#define C_F32_LOCATIVE            10
#define C_F64_LOCATIVE            11

#if defined (__MINGW32__)
# define C_s64                    __int64
# define C_u64                    unsigned __int64
#else
# define C_s64                    int64_t
# define C_u64                    uint64_t
#endif

#ifdef C_SIXTY_FOUR
# ifdef C_LLP
#  define C_word                  C_s64
#  define C_hword                 long
# else
#  define C_word                  long
#  define C_hword                 int
# endif
# define C_u32                    uint32_t
# define C_s32                    int32_t
#else
# define C_word                   int
# define C_hword                  short
# define C_u32                    unsigned int
# define C_s32                    int
#endif

#define C_char                    char
#define C_uchar                   unsigned C_char
#define C_byte                    char
#define C_uword                   unsigned C_word
#define C_uhword                  unsigned C_hword
#define C_header                  C_uword

/* if all else fails, use these:
 #define UINT64_MAX (18446744073709551615ULL)
 #define INT64_MAX  (9223372036854775807LL)
 #define INT64_MIN  (-INT64_MAX - 1)
 #define UINT32_MAX (4294967295U)
 #define INT32_MAX  (2147483647)
 #define INT32_MIN  (-INT32_MAX - 1)
 #define UINT16_MAX (65535U)
 #define INT16_MAX  (32767)
 #define INT16_MIN  (-INT16_MAX - 1)
 #define UINT8_MAX  (255)
 #define INT8_MAX   (127)
 #define INT8_MIN   (-INT8_MAX - 1)
*/

#define C_U64_MAX    UINT64_MAX
#define C_S64_MIN    INT64_MIN
#define C_S64_MAX    INT64_MAX

#if defined(C_LLP)
# define C_wabs                   llabs
# define C_long                   C_s64
# ifndef LONG_LONG_MAX
#  define C_LONG_MAX              LLONG_MAX
#  define C_LONG_MIN              LLONG_MIN
# else
#  define C_LONG_MAX              LONG_LONG_MAX
#  define C_LONG_MIN              LONG_LONG_MIN
# endif
#else
# define C_wabs                   labs
# define C_long                   long
# define C_LONG_MAX               LONG_MAX
# define C_LONG_MIN               LONG_MIN
#endif

#define C_ulong                   unsigned C_long

#ifdef __cplusplus
# define C_text(x)                ((C_char *)(x))
#else
# define C_text(x)                (x)
#endif

#define C_TIMER_INTERRUPT_NUMBER  255

#define C_BAD_ARGUMENT_COUNT_ERROR                    1
#define C_BAD_MINIMUM_ARGUMENT_COUNT_ERROR            2
#define C_BAD_ARGUMENT_TYPE_ERROR                     3
#define C_UNBOUND_VARIABLE_ERROR                      4
#define C_BAD_ARGUMENT_TYPE_NO_KEYWORD_ERROR          5
#define C_OUT_OF_MEMORY_ERROR                         6
#define C_DIVISION_BY_ZERO_ERROR                      7
#define C_OUT_OF_RANGE_ERROR                          8
#define C_NOT_A_CLOSURE_ERROR                         9
#define C_CONTINUATION_CANT_RECEIVE_VALUES_ERROR      10
#define C_BAD_ARGUMENT_TYPE_CYCLIC_LIST_ERROR         11
#define C_TOO_DEEP_RECURSION_ERROR                    12
#define C_CANT_REPRESENT_INEXACT_ERROR                13
#define C_NOT_A_PROPER_LIST_ERROR                     14
#define C_BAD_ARGUMENT_TYPE_NO_FIXNUM_ERROR           15
#define C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR           16
#define C_BAD_ARGUMENT_TYPE_NO_STRING_ERROR           17
#define C_BAD_ARGUMENT_TYPE_NO_PAIR_ERROR             18
#define C_BAD_ARGUMENT_TYPE_NO_LIST_ERROR             19
#define C_BAD_ARGUMENT_TYPE_NO_CHAR_ERROR             20
#define C_BAD_ARGUMENT_TYPE_NO_VECTOR_ERROR           21
#define C_BAD_ARGUMENT_TYPE_NO_SYMBOL_ERROR           22
#define C_STACK_OVERFLOW_ERROR                        23
#define C_BAD_ARGUMENT_TYPE_BAD_STRUCT_ERROR          24
#define C_BAD_ARGUMENT_TYPE_NO_BYTEVECTOR_ERROR       25
#define C_LOST_LOCATIVE_ERROR                         26
#define C_BAD_ARGUMENT_TYPE_NO_BLOCK_ERROR            27
#define C_BAD_ARGUMENT_TYPE_NO_NUMBER_VECTOR_ERROR    28
#define C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR          29
#define C_BAD_ARGUMENT_TYPE_NO_UINTEGER_ERROR         30
#define C_BAD_ARGUMENT_TYPE_NO_POINTER_ERROR          31
#define C_BAD_ARGUMENT_TYPE_NO_TAGGED_POINTER_ERROR   32
#define C_BAD_ARGUMENT_TYPE_NO_FLONUM_ERROR           33
#define C_BAD_ARGUMENT_TYPE_NO_CLOSURE_ERROR          34
#define C_BAD_ARGUMENT_TYPE_BAD_BASE_ERROR            35
#define C_CIRCULAR_DATA_ERROR                         36
#define C_BAD_ARGUMENT_TYPE_NO_BOOLEAN_ERROR          37
#define C_BAD_ARGUMENT_TYPE_NO_LOCATIVE_ERROR         38
#define C_BAD_ARGUMENT_TYPE_NO_PORT_ERROR             39
#define C_BAD_ARGUMENT_TYPE_PORT_DIRECTION_ERROR      40
#define C_BAD_ARGUMENT_TYPE_PORT_NO_INPUT_ERROR       41
#define C_BAD_ARGUMENT_TYPE_PORT_NO_OUTPUT_ERROR      42
#define C_PORT_CLOSED_ERROR                           43
#define C_ASCIIZ_REPRESENTATION_ERROR                 44
#define C_MEMORY_VIOLATION_ERROR                      45
#define C_FLOATING_POINT_EXCEPTION_ERROR              46
#define C_ILLEGAL_INSTRUCTION_ERROR                   47
#define C_BUS_ERROR                                   48
#define C_BAD_ARGUMENT_TYPE_NO_EXACT_ERROR            49
#define C_BAD_ARGUMENT_TYPE_NO_INEXACT_ERROR          50
#define C_BAD_ARGUMENT_TYPE_NO_REAL_ERROR             51
#define C_BAD_ARGUMENT_TYPE_COMPLEX_NO_ORDERING_ERROR 52
#define C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR    53
#define C_BAD_ARGUMENT_TYPE_FOREIGN_LIMITATION        54
#define C_BAD_ARGUMENT_TYPE_COMPLEX_ABS               55
#define C_REST_ARG_OUT_OF_BOUNDS_ERROR                56

/* Platform information */
#if defined(C_BIG_ENDIAN)
# define C_MACHINE_BYTE_ORDER "big-endian"
#elif defined(C_LITTLE_ENDIAN)
# define C_MACHINE_BYTE_ORDER "little-endian"
#endif

#if defined(__alpha__)
# define C_MACHINE_TYPE "alpha"
#elif defined(__mips__)
# define C_MACHINE_TYPE "mips"
#elif defined(__hppa__)
# define C_MACHINE_TYPE "hppa"
#elif defined(__sparc_v9__) || defined(__sparcv9)
# define C_MACHINE_TYPE "ultrasparc"
#elif defined(__sparc__)
# define C_MACHINE_TYPE "sparc"
#elif defined(__powerpc64__) || defined(_ARCH_PPC64)
# define C_MACHINE_TYPE "ppc64"
#elif defined(__ppc__) || defined(__powerpc__) || defined(_ARCH_PPC)
# define C_MACHINE_TYPE "ppc"
#elif defined(_M_IX86) || defined(__i386__)
# define C_MACHINE_TYPE "x86"
#elif defined(__ia64__)
# define C_MACHINE_TYPE "ia64"
#elif defined(__x86_64__)
# define C_MACHINE_TYPE "x86-64"
#elif defined(__riscv)
# if defined(__LP64__) || defined(_LP64)
#  define C_MACHINE_TYPE "riscv64"
# else
#  define C_MACHINE_TYPE "riscv"
# endif
#elif defined(__arm64__) || defined(__aarch64__)
# define C_MACHINE_TYPE "arm64"
#elif defined(__arm__)
# define C_MACHINE_TYPE "arm"
#else
# define C_MACHINE_TYPE "unknown"
#endif

#if defined(__CYGWIN__) || defined(__MINGW32__) || defined(_WIN32) || defined(__WINNT__)
# define C_SOFTWARE_TYPE "windows"
#elif defined(__ANDROID__)
# define C_SOFTWARE_TYPE "android"
#elif defined(__unix__) || defined(C_XXXBSD) || defined(_AIX)
# define C_SOFTWARE_TYPE "unix"
#elif defined(ECOS)
# define C_SOFTWARE_TYPE "ecos"
#else
# define C_SOFTWARE_TYPE "unknown"
#endif

#if defined(__SUNPRO_C)
# define C_BUILD_PLATFORM "sun"
#elif defined(__clang__)
# define C_BUILD_PLATFORM "clang"
#elif defined(_AIX)
# define C_BUILD_PLATFORM "aix"
#elif defined(__GNUC__)
# define C_BUILD_PLATFORM "gnu"
#elif defined(__INTEL_COMPILER)
# define C_BUILD_PLATFORM "intel"
#else
# define C_BUILD_PLATFORM "unknown"
#endif

#if defined(__linux__)
# define C_SOFTWARE_VERSION "linux"
#elif defined(__FreeBSD__)
# define C_SOFTWARE_VERSION "freebsd"
#elif defined(__NetBSD__)
# define C_SOFTWARE_VERSION "netbsd"
#elif defined(__OpenBSD__)
# define C_SOFTWARE_VERSION "openbsd"
#elif defined(C_MACOSX)
# define C_SOFTWARE_VERSION "macosx"
#elif defined(__hpux__)
# define C_SOFTWARE_VERSION "hpux"
#elif defined(__DragonFly__)
# define C_SOFTWARE_VERSION "dragonfly"
#elif defined(__HAIKU__)
# define C_SOFTWARE_VERSION "haiku"
#elif defined(__sun)
# if defined(__SVR4)
#   define C_SOFTWARE_VERSION "solaris"
# else
#   define C_SOFTWARE_VERSION "sunos"
# endif
#elif defined(_AIX)
# define C_SOFTWARE_VERSION "aix"
#elif defined(__GNU__)
# define C_SOFTWARE_VERSION "hurd"
#elif defined(__CYGWIN__)
# define C_SOFTWARE_VERSION "cygwin"
#elif defined(__MINGW32__)
# define C_SOFTWARE_VERSION "mingw32"
#else
# define C_SOFTWARE_VERSION "unknown"
#endif

/* There is no PATH_MAX in The Hurd. */
#ifdef PATH_MAX
# define C_MAX_PATH PATH_MAX
#else
# define C_MAX_PATH 1024
#endif

#define C_RANDOM_STATE_SIZE               (16 * sizeof(C_uword))

/* Types: */

typedef struct C_block_struct
{
  C_header header;
  C_word data[];
} C_SCHEME_BLOCK;

typedef struct C_symbol_table_struct
{
  char *name;
  unsigned int size;
  unsigned int rand;
  C_word *table;
  struct C_symbol_table_struct *next;
} C_SYMBOL_TABLE;

typedef struct C_gc_root_struct
{
  C_word value;
  struct C_gc_root_struct *next, *prev;
  int finalizable;
} C_GC_ROOT;

typedef struct C_ptable_entry_struct
{
  C_char *id;
  void *ptr;
} C_PTABLE_ENTRY;

typedef void (C_ccall *C_proc)(C_word, C_word *) C_noret;


/* Macros: */

#define C_cpsproc(name)   C_ccall void name(C_word c, C_word *av) C_noret

#define CHICKEN_gc_root_ref(root)      (((C_GC_ROOT *)(root))->value)
#define CHICKEN_gc_root_set(root, x)   C_mutate(&((C_GC_ROOT *)(root))->value, (x))

#define CHICKEN_global_ref(root)       C_u_i_car(((C_GC_ROOT *)(root))->value)
#define CHICKEN_global_set(root, x)    C_mutate(&C_u_i_car(((C_GC_ROOT *)(root))->value), (x))

#define CHICKEN_default_toplevel       ((void *)C_default_5fstub_toplevel)

#define C__STR1(x)                 #x
#define C__STR2(x)                 C__STR1(x)

#define C_align4(n)                (((n) + 3) & ~3)
#define C_align8(n)                (((n) + 7) & ~7)
#define C_align16(n)               (((n) + 15) & ~15)

#define C_aligned8(n)              ((((C_word)(n)) & 7) == 0)

#define C_buf_end(b)               ((C_word *)((C_byte *)(b) + sizeof(b)))

/* This is word-size dependent: */
#ifdef C_SIXTY_FOUR
# define C_align(n)                C_align8(n)
# define C_wordstobytes(n)         ((C_uword)(n) << 3)
# define C_bytestowords(n)         (((n) + 7) >> 3)
# define C_wordsperdouble(n)       (n)
# define C_WORD_MIN                LONG_MIN
# define C_WORD_MAX                LONG_MAX
# define C_UWORD_MAX               ULONG_MAX
#else
# define C_align(n)                C_align4(n)
# define C_wordstobytes(n)         ((C_uword)(n) << 2)
# define C_bytestowords(n)         (((n) + 3) >> 2)
# define C_wordsperdouble(n)       ((C_uword)(n) << 1)
# define C_WORD_MIN                INT_MIN
# define C_WORD_MAX                INT_MAX
# define C_UWORD_MAX               UINT_MAX
#endif

/* Clang and G++ support statement expressions, but only in a limited way */
#if DEBUGBUILD && HAVE_STATEMENT_EXPRESSIONS && !defined(__clang__) && !defined(__cplusplus)
/* These are wrappers around the following idiom:
 *    assert(SOME_PRED(obj));
 *    do_something_with(obj);
 * This works around the fact obj may be an expression with side-effects.
 *
 * To make this work with nested expansions, we need semantics like
 * (let ((x 1)) (let ((x x)) x)) => 1, but in C, int x = x; results in
 * undefined behaviour because x refers to itself.  As a workaround,
 * we keep around a reference to the previous level (one scope up).
 * After initialisation, "previous" is redefined to mean "current".
 */
# define C_VAL1(x)                 C__PREV_TMPST.n1
# define C_VAL2(x)                 C__PREV_TMPST.n2
# define C__CHECK_panic(a,s,f,l)                                       \
  ((a) ? (void)0 :                                                     \
   C_panic_hook(C_text("Low-level type assertion " s " failed at " f ":" C__STR1(l))))
# define C__CHECK_core(v,a,s,x)                                         \
  ({ struct {                                                           \
      typeof(v) n1;                                                     \
  } C__TMPST = { .n1 = (v) };                                           \
    typeof(C__TMPST) C__PREV_TMPST=C__TMPST;                            \
    C__CHECK_panic(a,s,__FILE__,__LINE__);                              \
    x; })
# define C__CHECK2_core(v1,v2,a,s,x)                                    \
  ({ struct {                                                           \
      typeof(v1) n1;                                                    \
      typeof(v2) n2;                                                    \
  } C__TMPST = { .n1 = (v1), .n2 = (v2) };                              \
    typeof(C__TMPST) C__PREV_TMPST=C__TMPST;                            \
    C__CHECK_panic(a,s,__FILE__,__LINE__);                              \
    x; })
# define C_CHECK(v,a,x)            C__CHECK_core(v,a,#a,x)
# define C_CHECK2(v1,v2,a,x)       C__CHECK2_core(v1,v2,a,#a,x)
/*
 * Convenience for using Scheme-predicates.
 */
# define C_CHECKp(v,a,x)           C__CHECK_core(v,C_truep(a),#a"=#t",x)
# define C_CHECK2p(v1,v2,a,x)      C__CHECK2_core(v1,v2,C_truep(a),#a"=#t",x)
#else
# define C_VAL1(x)                 (x)
# define C_VAL2(x)                 (x)
# define C_CHECK(v,a,x)            (x)
# define C_CHECK2(v1,v2,a,x)       (x)
# define C_CHECKp(v,a,x)           (x)
# define C_CHECK2p(v1,v2,a,x)      (x)
#endif

#ifndef C_PROVIDE_LIBC_STUBS
# define C_FILEPTR                  FILE *

# define C_stdin                    stdin
# define C_stdout                   stdout
# define C_stderr                   stderr

# define C_memcpy                   memcpy
# define C_memcmp                   memcmp
# define C_strncpy                  strncpy
# define C_strcmp                   strcmp
# define C_strncmp                  strncmp
# define C_strlen                   strlen
# define C_memchr                   memchr
# define C_memset                   memset
# define C_memmove                  memmove
# define C_strncasecmp              strncasecmp
# define C_malloc                   malloc
# define C_calloc                   calloc
# define C_free                     free
# define C_strchr                   strchr
# define C_realloc                  realloc
# define C_strdup                   strdup
# define C_strtol                   strtol
# define C_strtoll                  strtoll
# define C_strtod                   strtod
# define C_strtoul                  strtoul
# define C_fopen                    fopen
# define C_fclose                   fclose
# define C_strpbrk                  strpbrk
# define C_strcspn                  strcspn
# define C_snprintf                 snprintf
# define C_printf                   printf
# define C_fprintf                  fprintf
# define C_vfprintf                 vfprintf
# define C_fflush                   fflush
# define C_getchar                  getchar
# define C_exit                     exit
# define C__exit                    _exit
# define C_dlopen                   dlopen
# define C_dlclose                  dlclose
# define C_dlsym                    dlsym
# define C_fwrite                   fwrite
# define C_fread                    fread
# define C_fputs                    fputs
# define C_fputc                    fputc
# define C_putchar                  putchar
# if (defined getc_unlocked || _POSIX_C_SOURCE >= 199506L) && !defined(__MINGW32__)
#  define C_getc                    getc_unlocked
# else
#  define C_getc                    getc
# endif
# define C_fgetc                    fgetc
# define C_fgets                    fgets
# define C_ungetc                   ungetc
# define C_system                   system
# define C_isatty                   isatty
# define C_fileno                   fileno
# define C_select                   select
# if defined(HAVE_SIGACTION)
# define C_sigaction                sigaction
# endif
# define C_signal                   signal
# define C_getrusage                getrusage
# define C_tolower                  tolower
# define C_toupper                  toupper
# define C_gettimeofday             gettimeofday
# define C_gmtime                   gmtime
# define C_localtime                localtime
/*
 * It is undefined whether regular setjmp/longjmp save/restore signal mask
 * so try to use versions that we know won't try to save & restore.
 */
# if defined(HAVE_SIGSETJMP)
#   define C_sigsetjmp              sigsetjmp
#   define C_siglongjmp             siglongjmp
# endif
# ifdef HAVE_SIGPROCMASK
#  define C_sigprocmask             sigprocmask
# endif
# define C_setjmp                   setjmp
# define C_longjmp                  longjmp
# define C_alloca                   alloca
# define C_strerror                 strerror
# define C_isalpha                  isalpha
# define C_isdigit                  isdigit
# define C_isspace                  isspace
# define C_islower                  islower
# define C_isupper                  isupper
# define C_sin                      sin
# define C_cos                      cos
# define C_tan                      tan
# define C_asin                     asin
# define C_acos                     acos
# define C_atan                     atan
# define C_sinh                     sinh
# define C_cosh                     cosh
# define C_tanh                     tanh
# define C_asinh                    asinh
# define C_acosh                    acosh
# define C_atanh                    atanh
# define C_atan2                    atan2
# define C_log                      log
# define C_exp                      exp
# define C_pow                      pow
# define C_sqrt                     sqrt
# define C_ceil                     ceil
# define C_floor                    floor
# define C_round                    round
# define C_trunc                    trunc
# define C_fabs                     fabs
# define C_modf                     modf
# define C_readlink                 readlink
# define C_getcwd                   getcwd
# define C_access                   access
# define C_getpid                   getpid
# define C_getenv                   getenv
# define C_fma                      fma
#else
/* provide this file and define C_PROVIDE_LIBC_STUBS if you want to use
   your own libc-replacements or -wrappers */
# include "chicken-libc-stubs.h"
#endif

#ifdef C_LLP
# define C_strtow                  C_strtoll
#else
# define C_strtow                  C_strtol
#endif

#define C_return(x)                return(x)
#define C_resize_stack(n)          C_do_resize_stack(n)
#define C_memcpy_slots(t, f, n)    C_memcpy((t), (f), (n) * sizeof(C_word))
/* Without check: initialisation of a newly allocated header */
#define C_block_header_init(x,h)   (((C_SCHEME_BLOCK *)(x))->header = (h))
/* These two must result in an lvalue, hence the (*foo(&bar)) faffery */
#define C_block_header(x)          (*C_CHECKp(x,C_blockp((C_word)C_VAL1(x)),&(((C_SCHEME_BLOCK *)(C_VAL1(x)))->header)))
#define C_block_item(x,i)          (*C_CHECK2(x,i,(C_header_size(C_VAL1(x))>(C_VAL2(i))),&(((C_SCHEME_BLOCK *)(C_VAL1(x)))->data [ C_VAL2(i) ])))
#define C_set_block_item(x,i,y)    (C_block_item(x, i) = (y))
#define C_header_bits(bh)          (C_block_header(bh) & C_HEADER_BITS_MASK)
#define C_header_type(bh)          (C_block_header(bh) & C_HEADER_TYPE_BITS)
#define C_header_size(bh)          (C_block_header(bh) & C_HEADER_SIZE_MASK)
#define C_bignum_size(b)           (C_bytestowords(C_header_size(C_internal_bignum_vector(b)))-1)
#define C_make_header(type, size)  ((C_header)(((type) & C_HEADER_BITS_MASK) | ((size) & C_HEADER_SIZE_MASK)))
#define C_symbol_value(x)          (C_block_item(x, 0))
#define C_symbol_name(x)           (C_block_item(x, 1))
#define C_symbol_plist(x)          (C_block_item(x, 2))
#define C_save(x)	           (*(--C_temporary_stack) = (C_word)(x))
#define C_rescue(x, i)             (C_temporary_stack[ i ] = (x))
#define C_restore                  (*(C_temporary_stack++))
#define C_heaptop                  ((C_word **)(&C_fromspace_top))
#define C_drop(n)                  (C_temporary_stack += (n))
#define C_alloc(n)                 ((C_word *)C_alloca((n) * sizeof(C_word)))
#if (defined (__llvm__) && defined (__GNUC__)) || defined (__TINYC__)
# if defined (__i386__)
#  define C_stack_pointer ({C_word *sp; __asm__ __volatile__("movl %%esp,%0":"=r"(sp):);sp;})
# elif defined (__x86_64__)
#  define C_stack_pointer ({C_word *sp; __asm__ __volatile__("movq %%rsp,%0":"=r"(sp):);sp;})
# else
/* Not alloca(0) because:
 * - LLVM allocates anyways
 * - TCC always returns NULL
 */
#  define C_stack_pointer ((C_word *)C_alloca(1))
# endif
#else
# define C_stack_pointer ((C_word *)C_alloca(0))
#endif
#define C_stack_pointer_test       ((C_word *)C_alloca(1))
#define C_demand_2(n)              (((C_word *)C_fromspace_top + (n)) < (C_word *)C_fromspace_limit)
#define C_calculate_demand(n,c,m)  ((n) + (((c) > (m)) ? 0 : (m)))
#define C_fix(n)                   ((C_word)((C_uword)(n) << C_FIXNUM_SHIFT) | C_FIXNUM_BIT)
#define C_unfix(x)                 C_CHECKp(x,C_fixnump(C_VAL1(x)),((C_VAL1(x)) >> C_FIXNUM_SHIFT))
#define C_make_character(c)        (((((C_uword)(c)) & C_CHAR_BIT_MASK) << C_CHAR_SHIFT) | C_CHARACTER_BITS)
#define C_character_code(x)        C_CHECKp(x,C_charp(C_VAL1(x)),((C_word)(C_VAL1(x)) >> C_CHAR_SHIFT) & C_CHAR_BIT_MASK)
#define C_flonum_magnitude(x)      (*C_CHECKp(x,C_flonump(C_VAL1(x)),(double *)C_data_pointer(C_VAL1(x))))
/* XXX Sometimes this is (ab)used on bytevectors (ie, blob=? uses string_compare) */
#define C_c_string(x)              C_CHECK(x,(C_truep(C_stringp(C_VAL1(x))) || C_truep(C_bytevectorp(C_VAL1(x)))),(C_char *)C_data_pointer(C_VAL1(x)))

#define C_c_pointer(x)             ((void *)(x))
#define C_c_pointer_nn(x)          ((void *)C_block_item(x, 0))
#define C_truep(x)                 ((x) != C_SCHEME_FALSE)
#define C_immediatep(x)            ((x) & C_IMMEDIATE_MARK_BITS)
#define C_mk_bool(x)               ((x) ? C_SCHEME_TRUE : C_SCHEME_FALSE)
#define C_mk_nbool(x)              ((x) ? C_SCHEME_FALSE : C_SCHEME_TRUE)
#define C_port_file(p)             C_CHECKp(p,C_portp(C_VAL1(p)),(C_FILEPTR)C_block_item(C_VAL1(p), 0))
#define C_port_fileno(p)           C_fix(C_fileno(C_port_file(p)))
#define C_data_pointer(b)          C_CHECKp(b,C_blockp((C_word)C_VAL1(b)),(void *)(((C_SCHEME_BLOCK *)(C_VAL1(b)))->data))
#define C_bignum_negativep(b)      C_CHECKp(b,C_bignump(C_VAL1(b)),(C_block_item(C_internal_bignum_vector(C_VAL1(b)),0)!=0))
#define C_bignum_digits(b)         C_CHECKp(b,C_bignump(C_VAL1(b)),(((C_uword *)C_data_pointer(C_internal_bignum_vector(C_VAL1(b))))+1))
#define C_fitsinbignumhalfdigitp(n)(C_BIGNUM_DIGIT_HI_HALF(n) == 0)
#define C_bignum_negated_fitsinfixnump(b) (C_bignum_size(b) == 1 && (C_bignum_negativep(b) ? C_ufitsinfixnump(*C_bignum_digits(b)) : !(*C_bignum_digits(b) & C_INT_SIGN_BIT) && C_fitsinfixnump(-(C_word)*C_bignum_digits(b))))
#define C_bignum_mutate_size(b, s) (C_block_header(C_internal_bignum_vector(b)) = (C_STRING_TYPE | C_wordstobytes((s)+1)))
#define C_fitsinfixnump(n)         (((n) & C_INT_SIGN_BIT) == (((C_uword)(n) & C_INT_TOP_BIT) << 1))
#define C_ufitsinfixnump(n)        (((n) & (C_INT_SIGN_BIT | (C_INT_SIGN_BIT >> 1))) == 0)
#define C_and(x, y)                (C_truep(x) ? (y) : C_SCHEME_FALSE)
#define C_c_bytevector(x)          ((unsigned char *)C_data_pointer(x))
#define C_c_bytevector_or_null(x)  ((unsigned char *)C_data_pointer_or_null(x))
#define C_srfi_4_vector(x)         C_data_pointer(C_block_item(x,1))
#define C_c_u8vector(x)            ((unsigned char *)C_srfi_4_vector(x))
#define C_c_u8vector_or_null(x)    ((unsigned char *)C_srfi_4_vector_or_null(x))
#define C_c_s8vector(x)            ((signed char *)C_srfi_4_vector(x))
#define C_c_s8vector_or_null(x)    ((signed char *)C_srfi_4_vector_or_null(x))
#define C_c_u16vector(x)           ((unsigned short *)C_srfi_4_vector(x))
#define C_c_u16vector_or_null(x)   ((unsigned short *)C_srfi_4_vector_or_null(x))
#define C_c_s16vector(x)           ((short *)C_srfi_4_vector(x))
#define C_c_s16vector_or_null(x)   ((short *)C_srfi_4_vector_or_null(x))
#define C_c_u32vector(x)           ((C_u32 *)C_srfi_4_vector(x))
#define C_c_u32vector_or_null(x)   ((C_u32 *)C_srfi_4_vector_or_null(x))
#define C_c_s32vector(x)           ((C_s32 *)C_srfi_4_vector(x))
#define C_c_s32vector_or_null(x)   ((C_s32 *)C_srfi_4_vector_or_null(x))
#define C_c_u64vector(x)           ((C_u64 *)C_srfi_4_vector(x))
#define C_c_u64vector_or_null(x)   ((C_u64 *)C_srfi_4_vector_or_null(x))
#define C_c_s64vector(x)           ((C_s64 *)C_srfi_4_vector(x))
#define C_c_s64vector_or_null(x)   ((C_s64 *)C_srfi_4_vector_or_null(x))
#define C_c_f32vector(x)           ((float *)C_srfi_4_vector(x))
#define C_c_f32vector_or_null(x)   ((float *)C_srfi_4_vector_or_null(x))
#define C_c_f64vector(x)           ((double *)C_srfi_4_vector(x))
#define C_c_f64vector_or_null(x)   ((double *)C_srfi_4_vector_or_null(x))
#define C_c_pointer_vector(x)      ((void **)C_data_pointer(C_block_item((x), 2)))

#define C_isnan(f)                 isnan(f)
#define C_isinf(f)                 isinf(f)
#define C_isfinite(f)              isfinite(f)

#define C_stack_overflow_check    C_stack_check1(C_stack_overflow(NULL))

/* TODO: The C_scratch_usage checks should probably be moved.  Maybe
 * we should add a core#allocate_scratch_inline which will insert
 * C_demand/C_stack_probe-like checks to copy the result onto the
 * stack or reclaim, but in a clever way so it's only done at the
 * "end" of a C function.
 */
#if C_STACK_GROWS_DOWNWARD
# define C_demand(n)              ((C_word)(C_stack_pointer - C_stack_limit) > ((n)+C_scratch_usage))
# define C_stack_check1(err)      if(!C_disable_overflow_check) {	\
                                    do { C_byte *_sp = (C_byte*)(C_stack_pointer); \
				      if(_sp < (C_byte *)C_stack_hard_limit && \
					 ((C_byte *)C_stack_hard_limit - _sp) > C_STACK_RESERVE) \
					err; }				\
				    while(0);}

#else
# define C_demand(n)              ((C_word)(C_stack_limit - C_stack_pointer) > ((n)+C_scratch_usage))
# define C_stack_check1(err)      if(!C_disable_overflow_check) {	\
                                    do { C_byte *_sp = (C_byte*)(C_stack_pointer); \
				      if(_sp > (C_byte *)C_stack_hard_limit && \
					 (_sp - (C_byte *)C_stack_hard_limit) > C_STACK_RESERVE) \
					err; }				\
				    while(0);}

#endif

#define C_zero_length_p(x)        C_mk_bool(C_header_size(x) == 0)
#define C_boundp(x)               C_mk_bool(C_block_item(x, 0) != C_SCHEME_UNBOUND)
#define C_unboundvaluep(x)        C_mk_bool((x) == C_SCHEME_UNBOUND)
#define C_blockp(x)               C_mk_bool(!C_immediatep(x))
#define C_forwardedp(x)           C_mk_bool((C_block_header(x) & C_GC_FORWARDING_BIT) != 0)
#define C_immp(x)                 C_mk_bool(C_immediatep(x))
#define C_flonump(x)              C_mk_bool(C_block_header(x) == C_FLONUM_TAG)
#define C_bignump(x)              C_mk_bool(C_block_header(x) == C_BIGNUM_TAG)
#define C_stringp(x)              C_mk_bool(C_header_bits(x) == C_STRING_TYPE)
#define C_symbolp(x)              C_mk_bool(C_block_header(x) == C_SYMBOL_TAG)
#define C_pairp(x)                C_mk_bool(C_header_type(x) == C_PAIR_TYPE)
#define C_weak_pairp(x)           C_mk_bool(C_block_header(x) == C_WEAK_PAIR_TAG)
#define C_closurep(x)             C_mk_bool(C_header_bits(x) == C_CLOSURE_TYPE)
#define C_vectorp(x)              C_mk_bool(C_header_bits(x) == C_VECTOR_TYPE)
#define C_bytevectorp(x)          C_mk_bool(C_header_bits(x) == C_BYTEVECTOR_TYPE)
#define C_portp(x)                C_mk_bool(C_header_bits(x) == C_PORT_TYPE)
#define C_structurep(x)           C_mk_bool(C_header_bits(x) == C_STRUCTURE_TYPE)
#define C_locativep(x)            C_mk_bool(C_block_header(x) == C_LOCATIVE_TAG)
#define C_charp(x)                C_mk_bool(((x) & C_IMMEDIATE_TYPE_BITS) == C_CHARACTER_BITS)
#define C_booleanp(x)             C_mk_bool(((x) & C_IMMEDIATE_TYPE_BITS) == C_BOOLEAN_BITS)
#define C_eofp(x)                 C_mk_bool((x) == C_SCHEME_END_OF_FILE)
#define C_undefinedp(x)           C_mk_bool((x) == C_SCHEME_UNDEFINED)
#define C_bwpp(x)                 C_mk_bool((x) == C_SCHEME_BROKEN_WEAK_PTR)
#define C_fixnump(x)              C_mk_bool((x) & C_FIXNUM_BIT)
#define C_nfixnump(x)             C_mk_nbool((x) & C_FIXNUM_BIT)
#define C_pointerp(x)             C_mk_bool(C_block_header(x) == C_POINTER_TAG)
#define C_taggedpointerp(x)       C_mk_bool(C_block_header(x) == C_TAGGED_POINTER_TAG)
#define C_lambdainfop(x)          C_mk_bool(C_header_bits(x) == C_LAMBDA_INFO_TYPE)
#define C_anypointerp(x)          C_mk_bool(C_block_header(x) == C_POINTER_TAG || C_block_header(x) == C_TAGGED_POINTER_TAG)
#define C_specialp(x)             C_mk_bool(C_header_bits(x) & C_SPECIALBLOCK_BIT)
#define C_byteblockp(x)           C_mk_bool(C_header_bits(x) & C_BYTEBLOCK_BIT)
#define C_sametypep(x, y)         C_mk_bool(C_header_bits(x) == C_header_bits(y))
#define C_eqp(x, y)               C_mk_bool((x) == (y))
#define C_vemptyp(x)              C_mk_bool(C_header_size(x) == 0)
#define C_notvemptyp(x)           C_mk_bool(C_header_size(x) > 0)

#define C_port_typep(x, n)        C_mk_bool((C_block_item(x, 1) & n) == n)
#define C_input_portp(x)          C_and(C_portp(x), C_port_typep(x, 0x2))
#define C_output_portp(x)         C_and(C_portp(x), C_port_typep(x, 0x4))

#define C_port_openp(port, n)     C_mk_bool((C_block_item(port, 8) & n) == n)
#define C_input_port_openp(port)  C_port_openp(port, 0x2)
#define C_output_port_openp(port) C_port_openp(port, 0x4)

#define C_slot(x, i)              C_block_item(x, C_unfix(i))
#define C_subbyte(x, i)           C_fix(((C_byte *)C_data_pointer(x))[ C_unfix(i) ] & 0xff)
#define C_subchar(x, i)           C_make_character(((C_uchar *)C_data_pointer(x))[ C_unfix(i) ])
#define C_setbyte(x, i, n)        (((C_byte *)C_data_pointer(x))[ C_unfix(i) ] = C_unfix(n), C_SCHEME_UNDEFINED)
#define C_setsubchar(x, i, n)     (((C_char *)C_data_pointer(x))[ C_unfix(i) ] = C_character_code(n), C_SCHEME_UNDEFINED)
#define C_setsubbyte(x, i, n)     (((C_char *)C_data_pointer(x))[ C_unfix(i) ] = C_unfix(n), C_SCHEME_UNDEFINED)

#define C_fixnum_times(n1, n2)          (C_fix(C_unfix(n1) * C_unfix(n2)))
#define C_u_fixnum_plus(n1, n2)         (((n1) - C_FIXNUM_BIT) + (n2))
#define C_fixnum_plus(n1, n2)           (C_u_fixnum_plus(n1, n2) | C_FIXNUM_BIT)
#define C_u_fixnum_difference(n1, n2)   ((n1) - (n2) + C_FIXNUM_BIT)
#define C_fixnum_difference(n1, n2)     (C_u_fixnum_difference(n1, n2) | C_FIXNUM_BIT)
#define C_u_fixnum_divide(n1, n2)       (C_fix(C_unfix(n1) / C_unfix(n2)))
#define C_u_fixnum_and(n1, n2)          ((n1) & (n2))
#define C_fixnum_and(n1, n2)            (C_u_fixnum_and(n1, n2) | C_FIXNUM_BIT)
#define C_u_fixnum_or(n1, n2)           ((n1) | (n2))
#define C_fixnum_or(n1, n2)             C_u_fixnum_or(n1, n2)
#define C_fixnum_xor(n1, n2)            (((n1) ^ (n2)) | C_FIXNUM_BIT)
#define C_fixnum_not(n)                 ((~(n)) | C_FIXNUM_BIT)
#define C_fixnum_shift_left(n1, n2)     (C_fix(((C_uword)C_unfix(n1) << (C_uword)C_unfix(n2))))
#define C_fixnum_shift_right(n1, n2)    (((n1) >> (C_uword)C_unfix(n2)) | C_FIXNUM_BIT)
#define C_u_fixnum_negate(n)            (-(n) + 2 * C_FIXNUM_BIT)
#define C_fixnum_negate(n)              (C_u_fixnum_negate(n) | C_FIXNUM_BIT)
#define C_fixnum_greaterp(n1, n2)       (C_mk_bool((C_word)(n1) > (C_word)(n2)))
#define C_fixnum_lessp(n1, n2)          (C_mk_bool((C_word)(n1) < (C_word)(n2)))
#define C_fixnum_greater_or_equal_p(n1, n2) (C_mk_bool((C_word)(n1) >= (C_word)(n2)))
#define C_fixnum_less_or_equal_p(n1, n2)(C_mk_bool((C_word)(n1) <= (C_word)(n2)))
#define C_u_fixnum_increase(n)          ((n) + (1 << C_FIXNUM_SHIFT))
#define C_fixnum_increase(n)            (C_u_fixnum_increase(n) | C_FIXNUM_BIT)
#define C_u_fixnum_decrease(n)          ((n) - (1 << C_FIXNUM_SHIFT))
#define C_fixnum_decrease(n)            (C_u_fixnum_decrease(n) | C_FIXNUM_BIT)
/* XXX TODO: This should probably be renamed C_u_fixnum_abs or something */
#define C_fixnum_abs(n)                 C_fix(abs(C_unfix(n)))
#define C_a_i_fixnum_abs(ptr, n, x)     (((x) & C_INT_SIGN_BIT) ? C_a_i_fixnum_negate((ptr), (n), (x)) : (x))
#define C_i_fixnum_signum(x)            ((x) == C_fix(0) ? (x) : (((x) & C_INT_SIGN_BIT) ? C_fix(-1) : C_fix(1)))
#define C_i_fixnum_length(x)            C_fix(C_ilen(((x) & C_INT_SIGN_BIT) ? ~C_unfix(x) : C_unfix(x)))

#define C_flonum_equalp(n1, n2)         C_mk_bool(C_flonum_magnitude(n1) == C_flonum_magnitude(n2))
#define C_flonum_greaterp(n1, n2)       C_mk_bool(C_flonum_magnitude(n1) > C_flonum_magnitude(n2))
#define C_flonum_lessp(n1, n2)          C_mk_bool(C_flonum_magnitude(n1) < C_flonum_magnitude(n2))
#define C_flonum_greater_or_equal_p(n1, n2) C_mk_bool(C_flonum_magnitude(n1) >= C_flonum_magnitude(n2))
#define C_flonum_less_or_equal_p(n1, n2) C_mk_bool(C_flonum_magnitude(n1) <= C_flonum_magnitude(n2))

#define C_a_i_flonum_plus(ptr, c, n1, n2) C_flonum(ptr, C_flonum_magnitude(n1) + C_flonum_magnitude(n2))
#define C_a_i_flonum_difference(ptr, c, n1, n2) C_flonum(ptr, C_flonum_magnitude(n1) - C_flonum_magnitude(n2))
#define C_a_i_flonum_times(ptr, c, n1, n2) C_flonum(ptr, C_flonum_magnitude(n1) * C_flonum_magnitude(n2))
#define C_a_i_flonum_multiply_add(ptr, c, n1, n2, n3) C_flonum(ptr, fma(C_flonum_magnitude(n1), C_flonum_magnitude(n2), C_flonum_magnitude(n3)))
#define C_a_i_flonum_quotient(ptr, c, n1, n2) C_flonum(ptr, C_flonum_magnitude(n1) / C_flonum_magnitude(n2))
#define C_a_i_flonum_negate(ptr, c, n)  C_flonum(ptr, -C_flonum_magnitude(n))
#define C_a_u_i_flonum_signum(ptr, n, x) (C_flonum_magnitude(x) == 0.0 ? (x) : ((C_flonum_magnitude(x) < 0.0) ? C_flonum(ptr, -1.0) : C_flonum(ptr, 1.0)))

#define C_a_i_address_to_pointer(ptr, c, addr)  C_mpointer(ptr, (void *)C_num_to_unsigned_int(addr))
#define C_a_i_pointer_to_address(ptr, c, pptr)  C_unsigned_int_to_num(ptr, (unsigned int)C_c_pointer_nn(pptr))

#define C_display_fixnum(p, n)          (C_fprintf(C_port_file(p), C_text("%d"), C_unfix(n)), C_SCHEME_UNDEFINED)
#define C_display_char(p, c)            (C_fputc(C_character_code(c), C_port_file(p)), C_SCHEME_UNDEFINED)
#define C_display_string(p, s)          (C_fwrite(C_data_pointer(s), sizeof(C_char), C_header_size(s), \
                                         C_port_file(p)), C_SCHEME_UNDEFINED)
#define C_flush_output(port)            (C_fflush(C_port_file(port)), C_SCHEME_UNDEFINED)

#define C_fix_to_char(x)                (C_make_character(C_unfix(x)))
#define C_char_to_fix(x)                (C_fix(C_character_code(x)))
#define C_u_i_char_equalp(x, y)         C_mk_bool(C_character_code(x) == C_character_code(y))
#define C_u_i_char_greaterp(x, y)       C_mk_bool(C_character_code(x) > C_character_code(y))
#define C_u_i_char_lessp(x, y)          C_mk_bool(C_character_code(x) < C_character_code(y))
#define C_u_i_char_greater_or_equal_p(x, y) C_mk_bool(C_character_code(x) >= C_character_code(y))
#define C_u_i_char_less_or_equal_p(x, y) C_mk_bool(C_character_code(x) <= C_character_code(y))
#define C_substring_copy(s1, s2, start1, end1, start2) \
                                        (C_memmove((C_char *)C_data_pointer(s2) + C_unfix(start2), \
                                                   (C_char *)C_data_pointer(s1) + C_unfix(start1), \
                                                   C_unfix(end1) - C_unfix(start1) ), C_SCHEME_UNDEFINED)
#define C_substring_compare(s1, s2, start1, start2, len) \
                                        C_mk_bool(C_memcmp((C_char *)C_data_pointer(s1) + C_unfix(start1), \
                                                           (C_char *)C_data_pointer(s2) + C_unfix(start2), \
                                                           C_unfix(len) ) == 0)
#define C_substring_compare_case_insensitive(s1, s2, start1, start2, len) \
                                        C_mk_bool(C_memcasecmp((C_char *)C_data_pointer(s1) + C_unfix(start1), \
                                                                (C_char *)C_data_pointer(s2) + C_unfix(start2), \
                                                                C_unfix(len) ) == 0)
/* this does not use C_mutate: */
#define C_subvector_copy(v1, v2, start1, end1, start2) \
                                        (C_memcpy_slots((C_char *)C_data_pointer(v2) + C_unfix(start2), \
                                                  (C_char *)C_data_pointer(v1) + C_unfix(start1), \
						  C_unfix(end1) - C_unfix(start1) ), C_SCHEME_UNDEFINED)
#define C_words(n)                      C_fix(C_bytestowords(C_unfix(n)))
#define C_bytes(n)                      C_fix(C_wordstobytes(C_unfix(n)))
#define C_rand(n)                      C_fix((C_word)(((double)rand())/(RAND_MAX + 1.0) * C_unfix(n)))
#define C_block_size(x)                 C_fix(C_header_size(x))
#define C_u_i_bignum_size(b)            C_fix(C_bignum_size(b))
#define C_a_u_i_big_to_flo(p, n, b)     C_flonum(p, C_bignum_to_double(b))
#define C_u_i_ratnum_num(r)             C_block_item((r), 0)
#define C_u_i_ratnum_denom(r)           C_block_item((r), 1)
#define C_u_i_cplxnum_real(c)           C_block_item((c), 0)
#define C_u_i_cplxnum_imag(c)           C_block_item((c), 1)
#define C_pointer_address(x)            ((C_byte *)C_block_item((x), 0))
#define C_block_address(ptr, n, x)      C_a_unsigned_int_to_num(ptr, n, x)
#define C_offset_pointer(x, y)          (C_pointer_address(x) + (y))
#define C_do_apply(c, av)               ((C_proc)(void *)C_block_item((av)[0], 0))((c), (av))
#define C_kontinue(k, r)                do { C_word avk[ 2 ]; avk[ 0 ] = (k); avk[ 1 ] = (r); ((C_proc)(void *)C_block_item((k),0))(2, avk); } while(0)
#define C_get_rest_arg(c, n, av, ka, cl)((n) >= (c) ? (C_rest_arg_out_of_bounds_error_2(C_fix(c), C_fix(n), C_fix(ka), (cl)), C_SCHEME_UNDEFINED) : (av)[(n)])
#define C_rest_arg_out_of_bounds_error_value(c, n, ka) (C_rest_arg_out_of_bounds_error((c),(n),(ka)), C_SCHEME_UNDEFINED)
#define C_rest_nullp(c, n)              (C_mk_bool((n) >= (c)))
#define C_fetch_byte(x, p)              (((unsigned C_byte *)C_data_pointer(x))[ p ])
#define C_poke_integer(x, i, n)         (C_set_block_item(x, C_unfix(i), C_num_to_int(n)), C_SCHEME_UNDEFINED)
#define C_pointer_to_block(p, x)        (C_set_block_item(p, 0, (C_word)C_data_pointer(x)), C_SCHEME_UNDEFINED)
#define C_null_pointerp(x)              C_mk_bool((void *)C_block_item(x, 0) == NULL)
#define C_update_pointer(p, ptr)        (C_set_block_item(ptr, 0, C_num_to_unsigned_int(p)), C_SCHEME_UNDEFINED)
#define C_copy_pointer(from, to)        (C_set_block_item(to, 0, C_block_item(from, 0)), C_SCHEME_UNDEFINED)
#define C_pointer_to_object(ptr)        C_block_item(ptr, 0)

#ifdef C_SIXTY_FOUR
# define C_poke_integer_32(x, i, n)     (((C_s32 *)C_data_pointer(x))[ C_unfix(i) ] = C_unfix(n), C_SCHEME_UNDEFINED)
#else
# define C_poke_integer_32              C_poke_integer
#endif

#define C_copy_memory(to, from, n)      (C_memcpy(C_data_pointer(to), C_data_pointer(from), C_unfix(n)), C_SCHEME_UNDEFINED)
#define C_copy_ptr_memory(to, from, n, toff, foff) \
  (C_memmove(C_pointer_address(to) + C_unfix(toff), C_pointer_address(from) + C_unfix(foff), \
	     C_unfix(n)), C_SCHEME_UNDEFINED)
#define C_set_memory(to, c, n)          (C_memset(C_data_pointer(to), C_character_code(c), C_unfix(n)), C_SCHEME_UNDEFINED)
#define C_string_compare(to, from, n)   C_fix(C_memcmp(C_c_string(to), C_c_string(from), C_unfix(n)))
#define C_string_compare_case_insensitive(from, to, n) \
                                        C_fix(C_memcasecmp(C_c_string(from), C_c_string(to), C_unfix(n)))
#define C_poke_double(b, i, n)          (((double *)C_data_pointer(b))[ C_unfix(i) ] = C_c_double(n), C_SCHEME_UNDEFINED)
#define C_poke_c_string(b, i, from, s)  (C_strlcpy((char *)C_block_item(b, C_unfix(i)), C_data_pointer(from), s), C_SCHEME_UNDEFINED)
#define C_peek_fixnum(b, i)             C_fix(C_block_item(b, C_unfix(i)))
#define C_peek_byte(ptr, i)             C_fix(((unsigned char *)C_u_i_car(ptr))[ C_unfix(i) ])
#define C_dupstr(s)                     C_strdup(C_data_pointer(s))
#define C_poke_pointer(b, i, x)         (C_set_block_item(b, C_unfix(i), (C_word)C_data_pointer(x)), C_SCHEME_UNDEFINED)
#define C_poke_pointer_or_null(b, i, x) (C_set_block_item(b, C_unfix(i), (C_word)C_data_pointer_or_null(x)), C_SCHEME_UNDEFINED)
#define C_qfree(ptr)                    (C_free(C_c_pointer_nn(ptr)), C_SCHEME_UNDEFINED)

#define C_tty_portp(p)                  C_mk_bool(isatty(fileno(C_port_file(p))))

#define C_emit_trace_info(l, x, y, z)   C_emit_trace_info2(NULL, l, x, y, z)
#define C_emit_eval_trace_info(x, y, z) C_emit_trace_info2(C_text("<eval>"), C_SCHEME_FALSE, x, y, z)
#define C_emit_syntax_trace_info(x, y, z) C_emit_trace_info2(C_text("<syntax>"), C_SCHEME_FALSE, x, y, z)

/* These expect C_VECTOR_TYPE to be 0: */
#define C_vector_to_structure(v)        (C_block_header(v) |= C_STRUCTURE_TYPE, C_SCHEME_UNDEFINED)
#define C_vector_to_closure(v)          (C_block_header(v) |= C_CLOSURE_TYPE, C_SCHEME_UNDEFINED)
#define C_string_to_bytevector(s)       (C_block_header(s) = C_header_size(s) | C_BYTEVECTOR_TYPE, C_SCHEME_UNDEFINED)
#define C_string_to_lambdainfo(s)       (C_block_header(s) = C_header_size(s) | C_LAMBDA_INFO_TYPE, C_SCHEME_UNDEFINED)

#ifdef C_TIMER_INTERRUPTS
# define C_check_for_interrupt         if(--C_timer_interrupt_counter <= 0) C_raise_interrupt(C_TIMER_INTERRUPT_NUMBER)
#else
# define C_check_for_interrupt
#endif

#define C_set_initial_timer_interrupt_period(n) \
  (C_initial_timer_interrupt_period = C_unfix(n), C_SCHEME_UNDEFINED)


#ifdef HAVE_STATEMENT_EXPRESSIONS
# define C_a_i(a, n)                     ({C_word *tmp = *a; *a += (n); tmp;})
# define C_a_i_cons(a, n, car, cdr)      ({C_word tmp = (C_word)(*a); (*a)[0] = C_PAIR_TAG; *a += C_SIZEOF_PAIR; \
                                           C_set_block_item(tmp, 0, car); C_set_block_item(tmp, 1, cdr); tmp;})
# define C_a_i_weak_cons(a, n, car, cdr) ({C_word tmp = (C_word)(*a); (*a)[0] = C_WEAK_PAIR_TAG; *a += C_SIZEOF_PAIR; \
                                           C_set_block_item(tmp, 0, car); C_set_block_item(tmp, 1, cdr); tmp;})
#else
# define C_a_i_cons(a, n, car, cdr)      C_a_pair(a, car, cdr)
# define C_a_i_weak_cons(a, n, car, cdr) C_a_weak_pair(a, car, cdr)
#endif /* HAVE_STATEMENT_EXPRESSIONS */

#define C_a_i_flonum(ptr, c, n)         C_flonum(ptr, n)
#define C_a_i_ratnum(ptr, c, n, d)      C_ratnum(ptr, n, d)
#define C_a_i_cplxnum(ptr, c, r, i)     C_cplxnum(ptr, r, i)
#define C_a_i_data_mpointer(ptr, n, x)  C_mpointer(ptr, C_data_pointer(x))
#define C_a_i_fix_to_flo(p, n, f)       C_flonum(p, C_unfix(f))
#define C_cast_to_flonum(n)             ((double)(n))
#define C_a_i_mpointer(ptr, n, x)       C_mpointer(ptr, (x))
#define C_a_u_i_pointer_inc(ptr, n, p, i) C_mpointer(ptr, (C_char *)(p) + C_unfix(i))
#define C_pointer_eqp(x, y)             C_mk_bool(C_c_pointer_nn(x) == C_c_pointer_nn(y))
#define C_a_int_to_num(ptr, n, i)       C_int_to_num(ptr, i)
#define C_a_unsigned_int_to_num(ptr, n, i)  C_unsigned_int_to_num(ptr, i)
#define C_a_i_vector                    C_vector
#define C_list                          C_a_i_list
#define C_i_setslot(x, i, y)            (C_mutate(&C_block_item(x, C_unfix(i)), y), C_SCHEME_UNDEFINED)
#define C_i_set_i_slot(x, i, y)         (C_set_block_item(x, C_unfix(i), y), C_SCHEME_UNDEFINED)
#define C_u_i_set_car(p, x)             (C_mutate(&C_u_i_car(p), x), C_SCHEME_UNDEFINED)
#define C_u_i_set_cdr(p, x)             (C_mutate(&C_u_i_cdr(p), x), C_SCHEME_UNDEFINED)
#define C_a_i_putprop(p, c, x, y, z)    C_putprop(p, x, y, z)

#define C_i_not(x)                      (C_truep(x) ? C_SCHEME_FALSE : C_SCHEME_TRUE)
#define C_i_equalp(x, y)                C_mk_bool(C_equalp((x), (y)))
#define C_i_fixnumevenp(x)              C_mk_nbool((x) & 0x00000002)
#define C_i_fixnumoddp(x)               C_mk_bool((x) & 0x00000002)
#define C_i_fixnum_negativep(x)         C_mk_bool((x) & C_INT_SIGN_BIT)
#define C_i_fixnum_positivep(x)         C_mk_bool(!((x) & C_INT_SIGN_BIT) && (x) != C_fix(0))
#define C_i_nullp(x)                    C_mk_bool((x) == C_SCHEME_END_OF_LIST)
#define C_i_structurep(x, s)            C_mk_bool(!C_immediatep(x) && C_header_bits(x) == C_STRUCTURE_TYPE && C_block_item(x, 0) == (s))

#define C_u_i_char_alphabeticp(x)       C_mk_bool(C_character_code(x) < 0x100 && C_isalpha(C_character_code(x)))
#define C_u_i_char_numericp(x)          C_mk_bool(C_character_code(x) < 0x100 && C_isdigit(C_character_code(x)))
#define C_u_i_char_whitespacep(x)       C_mk_bool(C_character_code(x) < 0x100 && C_isspace(C_character_code(x)))
#define C_u_i_char_upper_casep(x)       C_mk_bool(C_character_code(x) < 0x100 && C_isupper(C_character_code(x)))
#define C_u_i_char_lower_casep(x)       C_mk_bool(C_character_code(x) < 0x100 && C_islower(C_character_code(x)))

#define C_u_i_char_upcase(x)            (C_character_code(x) < 0x100 ? C_make_character(C_toupper(C_character_code(x))) : (x))
#define C_u_i_char_downcase(x)          (C_character_code(x) < 0x100 ? C_make_character(C_tolower(C_character_code(x))) : (x))

#define C_i_list_ref(lst, i)            C_i_car(C_i_list_tail(lst, i))
#define C_u_i_list_ref(lst, i)          C_u_i_car(C_i_list_tail(lst, i))

#define C_u_i_car(x)                    (*C_CHECKp(x,C_pairp(C_VAL1(x)),&C_block_item(C_VAL1(x), 0)))
#define C_u_i_cdr(x)                    (*C_CHECKp(x,C_pairp(C_VAL1(x)),&C_block_item(C_VAL1(x), 1)))
#define C_u_i_caar(x)                   C_u_i_car( C_u_i_car( x ) )
#define C_u_i_cadr(x)                   C_u_i_car( C_u_i_cdr( x ) )
#define C_u_i_cdar(x)                   C_u_i_cdr( C_u_i_car( x ) )
#define C_u_i_cddr(x)                   C_u_i_cdr( C_u_i_cdr( x ) )
#define C_u_i_caaar(x)                  C_u_i_car( C_u_i_caar( x ) )
#define C_u_i_caadr(x)                  C_u_i_car( C_u_i_cadr( x ) )
#define C_u_i_cadar(x)                  C_u_i_car( C_u_i_cdar( x ) )
#define C_u_i_caddr(x)                  C_u_i_car( C_u_i_cddr( x ) )
#define C_u_i_cdaar(x)                  C_u_i_cdr( C_u_i_caar( x ) )
#define C_u_i_cdadr(x)                  C_u_i_cdr( C_u_i_cadr( x ) )
#define C_u_i_cddar(x)                  C_u_i_cdr( C_u_i_cdar( x ) )
#define C_u_i_cdddr(x)                  C_u_i_cdr( C_u_i_cddr( x ) )
#define C_u_i_caaaar(x)                 C_u_i_car( C_u_i_caaar( x ) )
#define C_u_i_caaadr(x)                 C_u_i_car( C_u_i_caadr( x ) )
#define C_u_i_caadar(x)                 C_u_i_car( C_u_i_cadar( x ) )
#define C_u_i_caaddr(x)                 C_u_i_car( C_u_i_caddr( x ) )
#define C_u_i_cadaar(x)                 C_u_i_car( C_u_i_cdaar( x ) )
#define C_u_i_cadadr(x)                 C_u_i_car( C_u_i_cdadr( x ) )
#define C_u_i_caddar(x)                 C_u_i_car( C_u_i_cddar( x ) )
#define C_u_i_cadddr(x)                 C_u_i_car( C_u_i_cdddr( x ) )
#define C_u_i_cdaaar(x)                 C_u_i_cdr( C_u_i_caaar( x ) )
#define C_u_i_cdaadr(x)                 C_u_i_cdr( C_u_i_caadr( x ) )
#define C_u_i_cdadar(x)                 C_u_i_cdr( C_u_i_cadar( x ) )
#define C_u_i_cdaddr(x)                 C_u_i_cdr( C_u_i_caddr( x ) )
#define C_u_i_cddaar(x)                 C_u_i_cdr( C_u_i_cdaar( x ) )
#define C_u_i_cddadr(x)                 C_u_i_cdr( C_u_i_cdadr( x ) )
#define C_u_i_cdddar(x)                 C_u_i_cdr( C_u_i_cddar( x ) )
#define C_u_i_cddddr(x)                 C_u_i_cdr( C_u_i_cdddr( x ) )

#ifdef HAVE_STATEMENT_EXPRESSIONS
# define C_i_not_pair_p(x)              ({C_word tmp = (x); C_mk_bool(C_immediatep(tmp) || C_header_type(tmp) != C_PAIR_TYPE);})
#else
# define C_i_not_pair_p                 C_i_not_pair_p_2
#endif

#define C_i_check_closure(x)            C_i_check_closure_2(x, C_SCHEME_FALSE)
#define C_i_check_exact(x)              C_i_check_exact_2(x, C_SCHEME_FALSE) /* DEPRECATED */
#define C_i_check_fixnum(x)             C_i_check_fixnum_2(x, C_SCHEME_FALSE)
#define C_i_check_inexact(x)            C_i_check_inexact_2(x, C_SCHEME_FALSE)
#define C_i_check_number(x)             C_i_check_number_2(x, C_SCHEME_FALSE)
#define C_i_check_string(x)             C_i_check_string_2(x, C_SCHEME_FALSE)
#define C_i_check_bytevector(x)         C_i_check_bytevector_2(x, C_SCHEME_FALSE)
#define C_i_check_keyword(x)            C_i_check_keyword_2(x, C_SCHEME_FALSE)
#define C_i_check_symbol(x)             C_i_check_symbol_2(x, C_SCHEME_FALSE)
#define C_i_check_list(x)               C_i_check_list_2(x, C_SCHEME_FALSE)
#define C_i_check_pair(x)               C_i_check_pair_2(x, C_SCHEME_FALSE)
#define C_i_check_locative(x)           C_i_check_locative_2(x, C_SCHEME_FALSE)
#define C_i_check_boolean(x)            C_i_check_boolean_2(x, C_SCHEME_FALSE)
#define C_i_check_vector(x)             C_i_check_vector_2(x, C_SCHEME_FALSE)
#define C_i_check_structure(x, st)      C_i_check_structure_2(x, (st), C_SCHEME_FALSE)
#define C_i_check_char(x)               C_i_check_char_2(x, C_SCHEME_FALSE)
#define C_i_check_port(x, in, op)       C_i_check_port_2(x, in, op, C_SCHEME_FALSE)

#define C_u_i_8vector_length(x)         C_fix(C_header_size(C_block_item(x, 1)))
#define C_u_i_16vector_length(x)        C_fix(C_header_size(C_block_item(x, 1)) >> 1)
#define C_u_i_32vector_length(x)        C_fix(C_header_size(C_block_item(x, 1)) >> 2)
#define C_u_i_64vector_length(x)        C_fix(C_header_size(C_block_item(x, 1)) >> 3)
#define C_u_i_u8vector_length           C_u_i_8vector_length
#define C_u_i_s8vector_length           C_u_i_8vector_length
#define C_u_i_u16vector_length          C_u_i_16vector_length
#define C_u_i_s16vector_length          C_u_i_16vector_length
#define C_u_i_u32vector_length          C_u_i_32vector_length
#define C_u_i_s32vector_length          C_u_i_32vector_length
#define C_u_i_u64vector_length          C_u_i_64vector_length
#define C_u_i_s64vector_length          C_u_i_64vector_length
#define C_u_i_f32vector_length          C_u_i_32vector_length
#define C_u_i_f64vector_length          C_u_i_64vector_length

#define C_u_i_u8vector_ref(x, i)        C_fix(((unsigned char *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ])
#define C_u_i_s8vector_ref(x, i)        C_fix(((signed char *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ])
#define C_u_i_u16vector_ref(x, i)       C_fix(((unsigned short *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ])
#define C_u_i_s16vector_ref(x, i)       C_fix(((short *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ])

/* these assume fixnum mode */
#define C_u_i_u32vector_ref(x, i)       C_fix(((C_u32 *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ])
#define C_u_i_s32vector_ref(x, i)       C_fix(((C_s32 *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ])

#define C_a_u_i_u32vector_ref(ptr, c, x, i)  C_unsigned_int_to_num(ptr, ((C_u32 *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ])
#define C_a_u_i_s32vector_ref(ptr, c, x, i)  C_int_to_num(ptr, ((C_s32 *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ])

#define C_a_u_i_u64vector_ref(ptr, c, x, i)  C_uint64_to_num(ptr, ((C_u64 *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ])
#define C_a_u_i_s64vector_ref(ptr, c, x, i)  C_int64_to_num(ptr, ((C_s64 *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ])

#define C_u_i_u8vector_set(x, i, v)     ((((unsigned char *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ] = C_unfix(v)), C_SCHEME_UNDEFINED)
#define C_u_i_s8vector_set(x, i, v)     ((((signed char *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ] = C_unfix(v)), C_SCHEME_UNDEFINED)
#define C_u_i_u16vector_set(x, i, v)    ((((unsigned short *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ] = C_unfix(v)), C_SCHEME_UNDEFINED)
#define C_u_i_s16vector_set(x, i, v)    ((((short *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ] = C_unfix(v)), C_SCHEME_UNDEFINED)
#define C_u_i_u32vector_set(x, i, v)    ((((C_u32 *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ] = C_num_to_unsigned_int(v)), C_SCHEME_UNDEFINED)
#define C_u_i_s32vector_set(x, i, v)    ((((C_s32 *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ] = C_num_to_int(v)), C_SCHEME_UNDEFINED)
#define C_u_i_u64vector_set(x, i, v)    ((((C_u64 *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ] = C_num_to_uint64(v)), C_SCHEME_UNDEFINED)
#define C_u_i_s64vector_set(x, i, v)    ((((C_s64 *)C_data_pointer(C_block_item((x), 1)))[ C_unfix(i) ] = C_num_to_int64(v)), C_SCHEME_UNDEFINED)

/* DEPRECATED */
#define C_u_i_bit_to_bool(x, i)         C_mk_bool((C_unfix(x) & (1 << C_unfix(i))) != 0)

#define C_u_i_pointer_u8_ref(ptr)         C_fix(*((unsigned char *)C_block_item(ptr, 0)))
#define C_u_i_pointer_s8_ref(ptr)         C_fix(*((signed char *)C_block_item(ptr, 0)))
#define C_u_i_pointer_u16_ref(ptr)        C_fix(*((unsigned short *)C_block_item(ptr, 0)))
#define C_u_i_pointer_s16_ref(ptr)        C_fix(*((short *)C_block_item(ptr, 0)))
#define C_a_u_i_pointer_u32_ref(ap, n, ptr)  \
  C_unsigned_int_to_num(ap, *((C_u32 *)C_block_item(ptr, 0)))
#define C_a_u_i_pointer_s32_ref(ap, n, ptr)  \
  C_int_to_num(ap, *((C_s32 *)C_block_item(ptr, 0)))
#define C_a_u_i_pointer_u64_ref(ap, n, ptr)  \
  C_uint64_to_num(ap, *((C_u64 *)C_block_item(ptr, 0)))
#define C_a_u_i_pointer_s64_ref(ap, n, ptr)  \
  C_int64_to_num(ap, *((C_s64 *)C_block_item(ptr, 0)))
#define C_a_u_i_pointer_f32_ref(ap, n, ptr)  C_flonum(ap, *((float *)C_block_item(ptr, 0)))
#define C_a_u_i_pointer_f64_ref(ap, n, ptr)  C_flonum(ap, *((double *)C_block_item(ptr, 0)))
#define C_u_i_pointer_u8_set(ptr, x)  \
  (*((unsigned char *)C_block_item(ptr, 0)) = C_unfix(x), C_SCHEME_UNDEFINED)
#define C_u_i_pointer_s8_set(ptr, x)  \
  (*((signed char *)C_block_item(ptr, 0)) = C_unfix(x), C_SCHEME_UNDEFINED)
#define C_u_i_pointer_u16_set(ptr, x)  \
  (*((unsigned short *)C_block_item(ptr, 0)) = C_unfix(x), C_SCHEME_UNDEFINED)
#define C_u_i_pointer_s16_set(ptr, x)  \
  (*((short *)C_block_item(ptr, 0)) = C_unfix(x), C_SCHEME_UNDEFINED)
#define C_u_i_pointer_u32_set(ptr, x)  \
  (*((C_u32 *)C_block_item(ptr, 0)) = C_num_to_unsigned_int(x), C_SCHEME_UNDEFINED)
#define C_u_i_pointer_s32_set(ptr, x)  \
  (*((C_s32 *)C_block_item(ptr, 0)) = C_num_to_int(x), C_SCHEME_UNDEFINED)
#define C_u_i_pointer_u64_set(ptr, x)  \
  (*((C_u64 *)C_block_item(ptr, 0)) = C_num_to_uint64(x), C_SCHEME_UNDEFINED)
#define C_u_i_pointer_s64_set(ptr, x)  \
  (*((C_s64 *)C_block_item(ptr, 0)) = C_num_to_int64(x), C_SCHEME_UNDEFINED)
#define C_u_i_pointer_f32_set(ptr, x)  \
  (*((float *)C_block_item(ptr, 0)) = C_flonum_magnitude(x), C_SCHEME_UNDEFINED)
#define C_u_i_pointer_f64_set(ptr, x)  \
  (*((double *)C_block_item(ptr, 0)) = C_flonum_magnitude(x), C_SCHEME_UNDEFINED)

#ifdef C_BIG_ENDIAN
# ifdef C_SIXTY_FOUR
#  define C_lihdr(x, y, z)              ((C_LAMBDA_INFO_TYPE >> 56) & 0xff), \
                                        0, 0, 0, 0, (x), (y), ((C_char)(z))
# else
#  define C_lihdr(x, y, z)              ((C_LAMBDA_INFO_TYPE >> 24) & 0xff), \
                                        (x), (y), ((C_char)(z))
# endif
#else
# ifdef C_SIXTY_FOUR
#  define C_lihdr(x, y, z)              ((C_char)(z)), (y), (x), 0, 0, 0, 0, \
                                        ((C_LAMBDA_INFO_TYPE >> 56) & 0xff)
# else
#  define C_lihdr(x, y, z)              ((C_char)(z)), (y), (x), \
                                        ((C_LAMBDA_INFO_TYPE >> 24) & 0xff)
# endif
#endif

#define C_ub_i_flonum_plus(x, y)        ((x) + (y))
#define C_ub_i_flonum_difference(x, y)  ((x) - (y))
#define C_ub_i_flonum_times(x, y)       ((x) * (y))
#define C_ub_i_flonum_quotient(x, y)    ((x) / (y))
#define C_ub_i_flonum_multiply_add(x, y, z)    C_fma((x), (y), (z))

#define C_ub_i_flonum_equalp(n1, n2)    C_mk_bool((n1) == (n2))
#define C_ub_i_flonum_greaterp(n1, n2)  C_mk_bool((n1) > (n2))
#define C_ub_i_flonum_lessp(n1, n2)     C_mk_bool((n1) < (n2))
#define C_ub_i_flonum_greater_or_equal_p(n1, n2)  C_mk_bool((n1) >= (n2))
#define C_ub_i_flonum_less_or_equal_p(n1, n2)  C_mk_bool((n1) <= (n2))

#define C_ub_i_flonum_nanp(x)            C_mk_bool(C_isnan(x))
#define C_ub_i_flonum_infinitep(x)       C_mk_bool(C_isinf(x))
#define C_ub_i_flonum_finitep(x)         C_mk_bool(C_isfinite(x))

#define C_ub_i_pointer_inc(p, n)        ((void *)((unsigned char *)(p) + (n)))
#define C_ub_i_pointer_eqp(p1, p2)      C_mk_bool((p1) == (p2))
#define C_ub_i_null_pointerp(p)         C_mk_bool((p) == NULL)

#define C_ub_i_pointer_u8_ref(p)        (*((unsigned char *)(p)))
#define C_ub_i_pointer_s8_ref(p)        (*((signed char *)(p)))
#define C_ub_i_pointer_u16_ref(p)       (*((unsigned short *)(p)))
#define C_ub_i_pointer_s16_ref(p)       (*((short *)(p)))
#define C_ub_i_pointer_u32_ref(p)       (*((C_u32 *)(p)))
#define C_ub_i_pointer_s32_ref(p)       (*((C_s32 *)(p)))
#define C_ub_i_pointer_u64_ref(p)       (*((C_u64 *)(p)))
#define C_ub_i_pointer_s64_ref(p)       (*((C_s64 *)(p)))
#define C_ub_i_pointer_f32_ref(p)       (*((float *)(p)))
#define C_ub_i_pointer_f64_ref(p)       (*((double *)(p)))
#define C_ub_i_pointer_u8_set(p, n)     (*((unsigned char *)(p)) = (n))
#define C_ub_i_pointer_s8_set(p, n)     (*((signed char *)(p)) = (n))
#define C_ub_i_pointer_u16_set(p, n)    (*((unsigned short *)(p)) = (n))
#define C_ub_i_pointer_s16_set(p, n)    (*((short *)(p)) = (n))
#define C_ub_i_pointer_u32_set(p, n)    (*((C_u32 *)(p)) = (n))
#define C_ub_i_pointer_s32_set(p, n)    (*((C_s32 *)(p)) = (n))
#define C_ub_i_pointer_u64_set(p, n)    (*((C_u64 *)(p)) = (n))
#define C_ub_i_pointer_s64_set(p, n)    (*((C_s64 *)(p)) = (n))
#define C_ub_i_pointer_f32_set(p, n)    (*((float *)(p)) = (n))
#define C_ub_i_pointer_f64_set(p, n)    (*((double *)(p)) = (n))

#ifdef C_PRIVATE_REPOSITORY
# define C_private_repository()         C_use_private_repository(C_executable_dirname())
#else
# define C_private_repository()
#endif

#ifdef C_GUI
# define C_set_gui_mode                 C_gui_mode = 1
#else
# define C_set_gui_mode
#endif

/**
 * SEARCH_EXE_PATH is defined on platforms on which we must search for
 * the current executable. Because this search is sensitive to things
 * like CWD, PATH, and so on, it's done once at startup and saved in
 * `C_main_exe`.
 *
 * On platforms where it's not defined, there's a simple way to
 * retrieve a path to the current executable (such as reading
 * "/proc/<pid>/exe" or some similar trick).
 */
#ifdef SEARCH_EXE_PATH
# define C_set_main_exe(fname)          C_main_exe = C_resolve_executable_pathname(fname)
#else
# define C_set_main_exe(fname)
#endif

#if !defined(C_EMBEDDED) && !defined(C_SHARED)
# if defined(C_GUI) && defined(_WIN32)
#  define C_main_entry_point            \
  int WINAPI WinMain(HINSTANCE me, HINSTANCE you, LPSTR cmdline, int show) \
  { \
    C_gui_mode = 1; \
    C_set_main_exe(argv[0]);				\
    C_private_repository();				\
    return CHICKEN_main(0, NULL, (void *)C_toplevel); \
  }
# else
#  define C_main_entry_point            \
  int main(int argc, char *argv[]) \
  { \
    C_set_gui_mode; \
    C_set_main_exe(argv[0]);				\
    C_private_repository();				\
    return CHICKEN_main(argc, argv, (void*)C_toplevel); \
  }
# endif
#else
# define C_main_entry_point
#endif

#define C_alloc_flonum                  C_word *___tmpflonum = C_alloc(WORDS_PER_FLONUM)
#define C_kontinue_flonum(k, n)         C_kontinue((k), C_flonum(&___tmpflonum, (n)))

#define C_a_i_flonum_truncate(ptr, n, x)  C_flonum(ptr, C_trunc(C_flonum_magnitude(x)))
#define C_a_i_flonum_ceiling(ptr, n, x)  C_flonum(ptr, C_ceil(C_flonum_magnitude(x)))
#define C_a_i_flonum_floor(ptr, n, x)   C_flonum(ptr, C_floor(C_flonum_magnitude(x)))
#define C_a_i_flonum_round(ptr, n, x)   C_flonum(ptr, C_round(C_flonum_magnitude(x)))

#define C_a_u_i_f32vector_ref(ptr, n, b, i)  C_flonum(ptr, ((float *)C_data_pointer(C_block_item((b), 1)))[ C_unfix(i) ])
#define C_a_u_i_f64vector_ref(ptr, n, b, i)  C_flonum(ptr, ((double *)C_data_pointer(C_block_item((b), 1)))[ C_unfix(i) ])
#define C_u_i_f32vector_set(v, i, x)    ((((float *)C_data_pointer(C_block_item((v), 1)))[ C_unfix(i) ] = C_flonum_magnitude(x)), C_SCHEME_UNDEFINED)
#define C_u_i_f64vector_set(v, i, x)    ((((double *)C_data_pointer(C_block_item((v), 1)))[ C_unfix(i) ] = C_flonum_magnitude(x)), C_SCHEME_UNDEFINED)

#define C_ub_i_f32vector_ref(b, i)      (((float *)C_data_pointer(C_block_item((b), 1)))[ C_unfix(i) ])
#define C_ub_i_f64vector_ref(b, i)      (((double *)C_data_pointer(C_block_item((b), 1)))[ C_unfix(i) ])
#define C_ub_i_f32vector_set(v, i, x)   ((((float *)C_data_pointer(C_block_item((v), 1)))[ C_unfix(i) ] = (x)), 0)
#define C_ub_i_f64vector_set(v, i, x)   ((((double *)C_data_pointer(C_block_item((v), 1)))[ C_unfix(i) ] = (x)), 0)

#define C_a_i_flonum_sin(ptr, c, x)     C_flonum(ptr, C_sin(C_flonum_magnitude(x)))
#define C_a_i_flonum_cos(ptr, c, x)     C_flonum(ptr, C_cos(C_flonum_magnitude(x)))
#define C_a_i_flonum_tan(ptr, c, x)     C_flonum(ptr, C_tan(C_flonum_magnitude(x)))
#define C_a_i_flonum_asin(ptr, c, x)    C_flonum(ptr, C_asin(C_flonum_magnitude(x)))
#define C_a_i_flonum_acos(ptr, c, x)    C_flonum(ptr, C_acos(C_flonum_magnitude(x)))
#define C_a_i_flonum_atan(ptr, c, x)    C_flonum(ptr, C_atan(C_flonum_magnitude(x)))
#define C_a_i_flonum_atan2(ptr, c, x, y)  C_flonum(ptr, C_atan2(C_flonum_magnitude(x), C_flonum_magnitude(y)))
#define C_a_i_flonum_sinh(ptr, c, x)     C_flonum(ptr, C_sinh(C_flonum_magnitude(x)))
#define C_a_i_flonum_cosh(ptr, c, x)     C_flonum(ptr, C_cosh(C_flonum_magnitude(x)))
#define C_a_i_flonum_tanh(ptr, c, x)     C_flonum(ptr, C_tanh(C_flonum_magnitude(x)))
#define C_a_i_flonum_asinh(ptr, c, x)    C_flonum(ptr, C_asinh(C_flonum_magnitude(x)))
#define C_a_i_flonum_acosh(ptr, c, x)    C_flonum(ptr, C_acosh(C_flonum_magnitude(x)))
#define C_a_i_flonum_atanh(ptr, c, x)    C_flonum(ptr, C_atanh(C_flonum_magnitude(x)))
#define C_a_i_flonum_exp(ptr, c, x)     C_flonum(ptr, C_exp(C_flonum_magnitude(x)))
#define C_a_i_flonum_expt(ptr, c, x, y)  C_flonum(ptr, C_pow(C_flonum_magnitude(x), C_flonum_magnitude(y)))
#define C_a_i_flonum_log(ptr, c, x)     C_flonum(ptr, C_log(C_flonum_magnitude(x)))
#define C_a_i_flonum_sqrt(ptr, c, x)    C_flonum(ptr, C_sqrt(C_flonum_magnitude(x)))
#define C_a_i_flonum_abs(ptr, c, x)     C_flonum(ptr, C_fabs(C_flonum_magnitude(x)))
#define C_u_i_flonum_nanp(x)            C_mk_bool(C_isnan(C_flonum_magnitude(x)))
#define C_u_i_flonum_infinitep(x)       C_mk_bool(C_isinf(C_flonum_magnitude(x)))
#define C_u_i_flonum_finitep(x)         C_mk_bool(C_isfinite(C_flonum_magnitude(x)))

/* DEPRECATED */
#define C_a_i_current_milliseconds(ptr, c, dummy) C_uint64_to_num(ptr, C_milliseconds())
#define C_a_i_current_process_milliseconds(ptr, c, dummy) C_uint64_to_num(ptr, C_current_process_milliseconds())

#define C_i_noop1(dummy)               ((dummy), C_SCHEME_UNDEFINED)
#define C_i_noop2(dummy1, dummy2)      ((dummy1), (dummy2), C_SCHEME_UNDEFINED)
#define C_i_noop3(dummy1, dummy2, dummy3)  ((dummy1), (dummy2), (dummy3), C_SCHEME_UNDEFINED)
#define C_i_true1(dummy)               ((dummy), C_SCHEME_TRUE)
#define C_i_true2(dummy1, dummy2)      ((dummy1), (dummy2), C_SCHEME_TRUE)
#define C_i_true3(dummy1, dummy2, dummy3)  ((dummy1), (dummy2), (dummy3), C_SCHEME_TRUE)

/* debug client interface */

typedef struct C_DEBUG_INFO {
  int event;
  int enabled;
  C_char *loc;
  C_char *val;
} C_DEBUG_INFO;

#define C_DEBUG_CALL                1
#define C_DEBUG_GLOBAL_ASSIGN       2
#define C_DEBUG_GC                  3
#define C_DEBUG_ENTRY               4
#define C_DEBUG_SIGNAL              5
#define C_DEBUG_CONNECT             6
#define C_DEBUG_LISTEN              7
#define C_DEBUG_INTERRUPTED         8

#define C_debugger(cell, c, av)     (C_debugger_hook != NULL ? C_debugger_hook(cell, c, av, C_text(__FILE__ ":" C__STR2(__LINE__))) : C_SCHEME_UNDEFINED)

/* Variables: */

C_varextern C_TLS time_t C_startup_time_seconds;
C_varextern C_TLS C_word
  *C_temporary_stack,
  *C_temporary_stack_bottom,
  *C_temporary_stack_limit,
  *C_stack_limit,
  *C_stack_hard_limit,
  *C_scratchspace_start,
  *C_scratchspace_top,
  *C_scratchspace_limit,
   C_scratch_usage;
C_varextern C_TLS C_long
  C_timer_interrupt_counter,
  C_initial_timer_interrupt_period;
C_varextern C_TLS C_byte
  *C_fromspace_top,
  *C_fromspace_limit;
#ifdef HAVE_SIGSETJMP
C_varextern C_TLS sigjmp_buf C_restart;
#else
C_varextern C_TLS jmp_buf C_restart;
#endif
C_varextern C_TLS void *C_restart_address;
C_varextern C_TLS int C_entry_point_status;
C_varextern C_TLS int C_gui_mode;

C_varextern C_TLS void *C_restart_trampoline;
C_varextern C_TLS void (*C_pre_gc_hook)(int mode);
C_varextern C_TLS void (*C_post_gc_hook)(int mode, C_long ms);
C_varextern C_TLS void (*C_panic_hook)(C_char *msg);
C_varextern C_TLS C_word (*C_debugger_hook)(C_DEBUG_INFO *cell, C_word c, C_word *av, char *cloc);

C_varextern C_TLS int
  C_abort_on_thread_exceptions,
  C_interrupts_enabled,
  C_disable_overflow_check,
  C_heap_size_is_fixed,
  C_max_pending_finalizers,
  C_trace_buffer_size,
  C_debugging,
  C_main_argc;
C_varextern C_TLS C_uword
  C_heap_growth,
  C_heap_shrinkage;
C_varextern C_TLS char
  **C_main_argv,
#ifdef SEARCH_EXE_PATH
  *C_main_exe,
#endif
  *C_dlerror;
C_varextern C_TLS C_uword C_maximal_heap_size;
C_varextern C_TLS int (*C_gc_mutation_hook)(C_word *slot, C_word val);
C_varextern C_TLS void (*C_gc_trace_hook)(C_word *var, int mode);
C_varextern C_TLS C_word (*C_get_unbound_variable_value_hook)(C_word sym);


/* Prototypes: */

C_BEGIN_C_DECLS

C_fctexport void C_register_debug_info(C_DEBUG_INFO *);
C_fctexport int CHICKEN_main(int argc, char *argv[], void *toplevel);
C_fctexport int CHICKEN_initialize(int heap, int stack, int symbols, void *toplevel);
C_fctexport C_word CHICKEN_run(void *toplevel);
C_fctexport C_word CHICKEN_continue(C_word k);
C_fctexport void *CHICKEN_new_gc_root();
C_fctexport void *CHICKEN_new_finalizable_gc_root();
C_fctexport void *CHICKEN_new_gc_root_2(int finalizable);
C_fctexport void CHICKEN_delete_gc_root(void *root);
C_fctexport void *CHICKEN_global_lookup(char *name);
C_fctexport int CHICKEN_is_running();
C_fctexport void CHICKEN_interrupt();

C_fctexport void C_check_nursery_minimum(C_word size);
C_fctexport int C_fcall C_save_callback_continuation(C_word **ptr, C_word k);
C_fctexport C_word C_fcall C_restore_callback_continuation(void);
C_fctexport C_word C_fcall C_restore_callback_continuation2(int level);
C_fctexport C_word C_fcall C_callback(C_word closure, int argc);
C_fctexport C_word C_fcall C_callback_wrapper(void *proc, int argc);
C_fctexport void C_fcall C_callback_adjust_stack(C_word *base, int size);
C_fctexport void CHICKEN_parse_command_line(int argc, char *argv[], C_word *heap, C_word *stack, C_word *symbols);
C_fctexport void C_fcall C_toplevel_entry(C_char *name) C_regparm;
C_fctexport C_word C_fcall C_a_i_provide(C_word **a, int c, C_word id) C_regparm;
C_fctexport C_word C_fcall C_i_providedp(C_word id) C_regparm;
C_fctexport C_word C_fcall C_enable_interrupts(void) C_regparm;
C_fctexport C_word C_fcall C_disable_interrupts(void) C_regparm;
C_fctexport void C_set_or_change_heap_size(C_word heap, int reintern);
C_fctexport void C_do_resize_stack(C_word stack);
C_fctexport C_word C_resize_pending_finalizers(C_word size);
C_fctexport void C_initialize_lf(C_word *lf, int count);
C_fctexport void *C_register_lf(C_word *lf, int count);
C_fctexport void *C_register_lf2(C_word *lf, int count, C_PTABLE_ENTRY *ptable);
C_fctexport void C_unregister_lf(void *handle);
C_fctexport C_char *C_dump_trace(int start);
C_fctexport void C_fcall C_clear_trace_buffer(void) C_regparm;
C_fctexport C_word C_resize_trace_buffer(C_word size);
C_fctexport C_word C_fetch_trace(C_word start, C_word buffer);
C_fctexport C_word C_fcall C_string(C_word **ptr, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_static_string(C_word **ptr, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_static_bignum(C_word **ptr, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_static_bytevector(C_word **ptr, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_static_lambda_info(C_word **ptr, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_bytevector(C_word **ptr, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_pbytevector(int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_string_aligned8(C_word **ptr, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_string2(C_word **ptr, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_string2_safe(C_word **ptr, int max, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_intern(C_word **ptr, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_intern_kw(C_word **ptr, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_intern_in(C_word **ptr, int len, C_char *str, C_SYMBOL_TABLE *stable) C_regparm;
C_fctexport C_word C_fcall C_h_intern(C_word *slot, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_h_intern_kw(C_word *slot, int len, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_h_intern_in(C_word *slot, int len, C_char *str, C_SYMBOL_TABLE *stable) C_regparm;
C_fctexport C_word C_fcall C_intern2(C_word **ptr, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_intern3(C_word **ptr, C_char *str, C_word value) C_regparm;
C_fctexport C_word C_fcall C_build_rest(C_word **ptr, C_word c, C_word n, C_word *av) C_regparm;
C_fctexport void C_bad_memory(void) C_noret;
C_fctexport void C_bad_memory_2(void) C_noret;
C_fctexport void C_bad_argc(int c, int n) C_noret;
C_fctexport void C_bad_min_argc(int c, int n) C_noret;
C_fctexport void C_bad_argc_2(int c, int n, C_word closure) C_noret;
C_fctexport void C_bad_min_argc_2(int c, int n, C_word closure) C_noret;
C_fctexport void C_stack_overflow(C_char *loc) C_noret;
C_fctexport void C_unbound_error(C_word sym) C_noret;
C_fctexport void C_no_closure_error(C_word x) C_noret;
C_fctexport void C_div_by_zero_error(char *loc) C_noret;
C_fctexport void C_not_an_integer_error(char *loc, C_word x) C_noret;
C_fctexport void C_not_an_uinteger_error(char *loc, C_word x) C_noret;
C_fctexport void C_rest_arg_out_of_bounds_error(C_word c, C_word n, C_word ka) C_noret;
C_fctexport void C_rest_arg_out_of_bounds_error_2(C_word c, C_word n, C_word ka, C_word closure) C_noret;
C_fctexport C_word C_closure(C_word **ptr, int cells, C_word proc, ...);
C_fctexport C_word C_fcall C_pair(C_word **ptr, C_word car, C_word cdr) C_regparm;
C_fctexport C_word C_fcall C_number(C_word **ptr, double n) C_regparm;
C_fctexport C_word C_fcall C_mpointer(C_word **ptr, void *mp) C_regparm;
C_fctexport C_word C_fcall C_mpointer_or_false(C_word **ptr, void *mp) C_regparm;
C_fctexport C_word C_fcall C_taggedmpointer(C_word **ptr, C_word tag, void *mp) C_regparm;
C_fctexport C_word C_fcall C_taggedmpointer_or_false(C_word **ptr, C_word tag, void *mp) C_regparm;
C_fctexport C_word C_vector(C_word **ptr, int n, ...);
C_fctexport C_word C_structure(C_word **ptr, int n, ...);
C_fctexport C_word C_fcall C_mutate_slot(C_word *slot, C_word val) C_regparm;
C_fctexport C_word C_fcall C_scratch_alloc(C_uword size) C_regparm;
C_fctexport C_word C_fcall C_migrate_buffer_object(C_word **ptr, C_word *start, C_word *end, C_word obj) C_regparm;
C_fctexport void C_fcall C_reclaim(void *trampoline, C_word c) C_regparm C_noret;
C_fctexport void C_save_and_reclaim(void *trampoline, int n, C_word *av) C_noret;
C_fctexport void C_save_and_reclaim_args(void *trampoline, int n, ...) C_noret;
C_fctexport void C_fcall C_rereclaim2(C_uword size, int relative_resize) C_regparm;
C_fctexport void C_unbound_variable(C_word sym);
C_fctexport C_word C_fcall C_retrieve2(C_word val, char *name) C_regparm;
C_fctexport void *C_fcall C_retrieve2_symbol_proc(C_word val, char *name) C_regparm;
C_fctexport int C_in_stackp(C_word x) C_regparm;
C_fctexport int C_fcall C_in_heapp(C_word x) C_regparm;
C_fctexport int C_fcall C_in_fromspacep(C_word x) C_regparm;
C_fctexport int C_fcall C_in_scratchspacep(C_word x) C_regparm;
C_fctexport void C_fcall C_trace(C_char *name) C_regparm;
C_fctexport C_word C_fcall C_emit_trace_info2(char *raw, C_word l, C_word x, C_word y, C_word t) C_regparm;
C_fctexport C_word C_fcall C_u_i_string_hash(C_word str, C_word rnd) C_regparm;
C_fctexport C_word C_fcall C_u_i_string_ci_hash(C_word str, C_word rnd) C_regparm;
C_fctexport C_word C_halt(C_word msg);
C_fctexport C_word C_message(C_word msg);
C_fctexport C_word C_fcall C_equalp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_set_gc_report(C_word flag) C_regparm;
C_fctexport C_word C_fcall C_start_timer(void) C_regparm;
C_fctexport C_word C_exit_runtime(C_word code) C_noret;
C_fctexport C_word C_fcall C_set_print_precision(C_word n) C_regparm;
C_fctexport C_word C_fcall C_get_print_precision(void) C_regparm;
C_fctexport C_word C_fcall C_read_char(C_word port) C_regparm;
C_fctexport C_word C_fcall C_peek_char(C_word port) C_regparm;
C_fctexport C_word C_fcall C_execute_shell_command(C_word string) C_regparm;
C_fctexport int C_fcall C_check_fd_ready(int fd) C_regparm;
C_fctexport C_word C_fcall C_char_ready_p(C_word port) C_regparm;
C_fctexport void C_fcall C_raise_interrupt(int reason) C_regparm;
C_fctexport C_word C_fcall C_establish_signal_handler(C_word signum, C_word reason) C_regparm;
C_fctexport C_word C_fcall C_copy_block(C_word from, C_word to) C_regparm;
C_fctexport C_word C_fcall C_evict_block(C_word from, C_word ptr) C_regparm;
C_fctexport void C_fcall C_gc_protect(C_word **addr, int n) C_regparm;
C_fctexport void C_fcall C_gc_unprotect(int n) C_regparm;
C_fctexport C_SYMBOL_TABLE *C_new_symbol_table(char *name, unsigned int size) C_regparm;
C_fctexport C_SYMBOL_TABLE *C_find_symbol_table(char *name) C_regparm;
C_fctexport C_word C_find_symbol(C_word str, C_SYMBOL_TABLE *stable) C_regparm;
C_fctexport C_word C_find_keyword(C_word str, C_SYMBOL_TABLE *stable) C_regparm;
C_fctexport C_word C_fcall C_lookup_symbol(C_word sym) C_regparm;
C_fctexport void C_do_register_finalizer(C_word x, C_word proc);
C_fctexport int C_do_unregister_finalizer(C_word x);
C_fctexport C_word C_dbg_hook(C_word x);
C_fctexport void C_use_private_repository(C_char *path);
C_fctexport C_char *C_private_repository_path();
C_fctexport C_char *C_executable_dirname();
C_fctexport C_char *C_executable_pathname();
C_fctexport C_char *C_resolve_executable_pathname(C_char *fname);

C_fctimport C_cpsproc(C_toplevel) C_noret;
C_fctimport C_cpsproc(C_invalid_procedure) C_noret;
C_fctexport C_cpsproc(C_stop_timer) C_noret;
C_fctexport C_cpsproc(C_signum) C_noret;
C_fctexport C_cpsproc(C_apply) C_noret;
C_fctexport C_cpsproc(C_call_cc) C_noret;
C_fctexport C_cpsproc(C_continuation_graft) C_noret;
C_fctexport C_cpsproc(C_values) C_noret;
C_fctexport C_cpsproc(C_apply_values) C_noret;
C_fctexport C_cpsproc(C_call_with_values) C_noret;
C_fctexport C_cpsproc(C_u_call_with_values) C_noret;
C_fctexport C_cpsproc(C_times) C_noret;
C_fctexport C_cpsproc(C_plus) C_noret;
C_fctexport C_cpsproc(C_minus) C_noret;
C_fctexport C_cpsproc(C_quotient_and_remainder) C_noret;
C_fctexport C_cpsproc(C_u_integer_quotient_and_remainder) C_noret;
C_fctexport C_cpsproc(C_bitwise_and) C_noret;
C_fctexport C_cpsproc(C_bitwise_ior) C_noret;
C_fctexport C_cpsproc(C_bitwise_xor) C_noret;

C_fctexport C_cpsproc(C_nequalp) C_noret;
C_fctexport C_cpsproc(C_greaterp) C_noret;
C_fctexport C_cpsproc(C_lessp) C_noret;
C_fctexport C_cpsproc(C_greater_or_equal_p) C_noret;
C_fctexport C_cpsproc(C_less_or_equal_p) C_noret;
C_fctexport C_cpsproc(C_gc) C_noret;
C_fctexport C_cpsproc(C_open_file_port) C_noret;
C_fctexport C_cpsproc(C_allocate_vector) C_noret;
C_fctexport C_cpsproc(C_string_to_symbol) C_noret;
C_fctexport C_cpsproc(C_string_to_keyword) C_noret;
C_fctexport C_cpsproc(C_build_symbol) C_noret;
C_fctexport C_cpsproc(C_number_to_string) C_noret;
C_fctexport C_cpsproc(C_fixnum_to_string) C_noret;
C_fctexport C_cpsproc(C_flonum_to_string) C_noret;
C_fctexport C_cpsproc(C_integer_to_string) C_noret;
C_fctexport C_cpsproc(C_make_structure) C_noret;
C_fctexport C_cpsproc(C_make_symbol) C_noret;
C_fctexport C_cpsproc(C_make_pointer) C_noret;
C_fctexport C_cpsproc(C_make_tagged_pointer) C_noret;
C_fctexport C_cpsproc(C_ensure_heap_reserve) C_noret;
C_fctexport C_cpsproc(C_return_to_host) C_noret;
C_fctexport C_cpsproc(C_get_symbol_table_info) C_noret;
C_fctexport C_cpsproc(C_get_memory_info) C_noret;
C_fctexport C_cpsproc(C_context_switch) C_noret;
C_fctexport C_cpsproc(C_peek_signed_integer) C_noret;
C_fctexport C_cpsproc(C_peek_unsigned_integer) C_noret;
C_fctexport C_cpsproc(C_peek_int64) C_noret;
C_fctexport C_cpsproc(C_peek_uint64) C_noret;
C_fctexport C_cpsproc(C_decode_seconds) C_noret;
C_fctexport C_cpsproc(C_software_type) C_noret;
C_fctexport C_cpsproc(C_machine_type) C_noret;
C_fctexport C_cpsproc(C_machine_byte_order) C_noret;
C_fctexport C_cpsproc(C_software_version) C_noret;
C_fctexport C_cpsproc(C_build_platform) C_noret;
C_fctexport C_cpsproc(C_register_finalizer) C_noret;
C_fctexport C_cpsproc(C_set_dlopen_flags) C_noret;
C_fctexport C_cpsproc(C_dload) C_noret;
C_fctexport C_cpsproc(C_become) C_noret;
C_fctexport C_cpsproc(C_call_with_cthulhu) C_noret;
C_fctexport C_cpsproc(C_copy_closure) C_noret;
C_fctexport C_cpsproc(C_dump_heap_state) C_noret;
C_fctexport C_cpsproc(C_filter_heap_objects) C_noret;

C_fctexport time_t C_fcall C_seconds(C_long *ms) C_regparm;
C_fctexport C_word C_fcall C_bignum_simplify(C_word big) C_regparm;
C_fctexport C_word C_fcall C_allocate_scratch_bignum(C_word **ptr, C_word size, C_word negp, C_word initp) C_regparm;
C_fctexport C_word C_fcall C_bignum_rewrap(C_word **p, C_word big) C_regparm;
C_fctexport C_word C_i_dump_statistical_profile();
C_fctexport C_word C_a_i_list(C_word **a, int c, ...);
C_fctexport C_word C_a_i_string(C_word **a, int c, ...);
C_fctexport C_word C_a_i_record(C_word **a, int c, ...);
C_fctexport C_word C_a_i_port(C_word **a, int c);
C_fctexport C_word C_fcall C_a_i_bytevector(C_word **a, int c, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_listp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_u8vectorp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_s8vectorp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_u16vectorp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_s16vectorp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_u32vectorp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_s32vectorp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_u64vectorp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_s64vectorp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_f32vectorp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_f64vectorp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_string_equal_p(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_string_ci_equal_p(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_set_car(C_word p, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_set_cdr(C_word p, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_u8vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_s8vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_u16vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_s16vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_u32vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_s32vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_u64vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_s64vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_f32vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_f64vector_set(C_word v, C_word i, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_exactp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_inexactp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_nanp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_finitep(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_infinitep(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_zerop(C_word x) C_regparm;
C_fctexport C_word C_fcall C_u_i_zerop(C_word x) C_regparm;  /* DEPRECATED */
C_fctexport C_word C_fcall C_i_positivep(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_integer_positivep(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_negativep(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_integer_negativep(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_car(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_cdr(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_caar(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_cadr(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_cdar(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_cddr(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_caddr(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_cdddr(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_cadddr(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_cddddr(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_list_tail(C_word lst, C_word i) C_regparm;
C_fctexport C_word C_fcall C_i_evenp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_integer_evenp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_oddp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_integer_oddp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_vector_ref(C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_i_u8vector_ref(C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_i_s8vector_ref(C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_i_u16vector_ref(C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_i_s16vector_ref(C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_a_i_u32vector_ref(C_word **ptr, C_word c, C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_a_i_s32vector_ref(C_word **ptr, C_word c, C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_a_i_u64vector_ref(C_word **ptr, C_word c, C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_a_i_s64vector_ref(C_word **ptr, C_word c, C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_a_i_f32vector_ref(C_word **ptr, C_word c, C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_a_i_f64vector_ref(C_word **ptr, C_word c, C_word v, C_word i) C_regparm;
C_fctexport C_word C_fcall C_i_block_ref(C_word x, C_word i) C_regparm;
C_fctexport C_word C_fcall C_i_string_set(C_word s, C_word i, C_word c) C_regparm;
C_fctexport C_word C_fcall C_i_string_ref(C_word s, C_word i) C_regparm;
C_fctexport C_word C_fcall C_i_vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_u8vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_s8vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_u16vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_s16vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_u32vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_s32vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_u64vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_s64vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_f32vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_f64vector_length(C_word v) C_regparm;
C_fctexport C_word C_fcall C_i_string_length(C_word s) C_regparm;
C_fctexport C_word C_fcall C_i_assq(C_word x, C_word lst) C_regparm;
C_fctexport C_word C_fcall C_i_assv(C_word x, C_word lst) C_regparm;
C_fctexport C_word C_fcall C_i_assoc(C_word x, C_word lst) C_regparm;
C_fctexport C_word C_fcall C_i_memq(C_word x, C_word lst) C_regparm;
C_fctexport C_word C_fcall C_u_i_memq(C_word x, C_word lst) C_regparm;
C_fctexport C_word C_fcall C_i_memv(C_word x, C_word lst) C_regparm;
C_fctexport C_word C_fcall C_i_member(C_word x, C_word lst) C_regparm;
C_fctexport C_word C_fcall C_i_length(C_word lst) C_regparm;
C_fctexport C_word C_fcall C_u_i_length(C_word lst) C_regparm;
C_fctexport C_word C_fcall C_i_check_closure_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_fixnum_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_exact_2(C_word x, C_word loc) C_regparm; /* DEPRECATED */
C_fctexport C_word C_fcall C_i_check_inexact_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_number_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_string_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_bytevector_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_symbol_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_keyword_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_list_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_pair_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_boolean_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_locative_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_vector_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_structure_2(C_word x, C_word st, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_char_2(C_word x, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_check_port_2(C_word x, C_word in, C_word op, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_bignum_cmp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_nequalp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_integer_equalp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_greaterp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_integer_greaterp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_lessp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_integer_lessp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_greater_or_equalp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_integer_greater_or_equalp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_less_or_equalp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_integer_less_or_equalp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_not_pair_p_2(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_null_list_p(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_string_null_p(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_null_pointerp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_char_equalp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_char_greaterp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_char_lessp(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_char_greater_or_equal_p(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_char_less_or_equal_p(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_a_i_locative_ref(C_word **a, int c, C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_locative_set(C_word loc, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_locative_to_object(C_word loc) C_regparm;
C_fctexport C_word C_fcall C_i_locative_index(C_word loc) C_regparm;
C_fctexport C_word C_fcall C_a_i_make_locative(C_word **a, int c, C_word type, C_word object, C_word index, C_word weak) C_regparm;
C_fctexport C_word C_fcall C_i_bit_to_bool(C_word n, C_word i) C_regparm; /* DEPRECATED */
C_fctexport C_word C_fcall C_i_integer_length(C_word x) C_regparm;
C_fctexport C_word C_fcall C_a_i_exp(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_log(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_sin(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_cos(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_tan(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_asin(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_acos(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_atan(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_atan2(C_word **a, int c, C_word n1, C_word n2) C_regparm;
C_fctexport C_word C_fcall C_a_i_sinh(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_cosh(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_tanh(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_asinh(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_acosh(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_atanh(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_sqrt(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_i_o_fixnum_plus(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_o_fixnum_difference(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_o_fixnum_times(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_o_fixnum_quotient(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_o_fixnum_and(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_o_fixnum_ior(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_i_o_fixnum_xor(C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_a_i_flonum_round_proper(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_a_i_flonum_gcd(C_word **p, C_word n, C_word x, C_word y) C_regparm;

C_fctexport C_word C_fcall C_i_getprop(C_word sym, C_word prop, C_word def) C_regparm;
C_fctexport C_word C_fcall C_putprop(C_word **a, C_word sym, C_word prop, C_word val) C_regparm;
C_fctexport C_word C_fcall C_i_persist_symbol(C_word sym) C_regparm;
C_fctexport C_word C_fcall C_i_unpersist_symbol(C_word sym) C_regparm;
C_fctexport C_word C_fcall C_i_get_keyword(C_word key, C_word args, C_word def) C_regparm;
C_fctexport C_word C_fcall C_i_process_sleep(C_word n) C_regparm;
C_fctexport C_u64 C_fcall C_milliseconds(void) C_regparm; /* DEPRECATED */
C_fctexport C_u64 C_fcall C_current_process_milliseconds(void) C_regparm;
C_fctexport C_u64 C_fcall C_cpu_milliseconds(void) C_regparm;
C_fctexport double C_fcall C_bignum_to_double(C_word bignum) C_regparm;
C_fctexport C_word C_fcall C_i_debug_modep(void) C_regparm;
C_fctexport C_word C_fcall C_i_dump_heap_on_exitp(void) C_regparm;
C_fctexport C_word C_fcall C_i_accumulated_gc_time(void) C_regparm;
C_fctexport C_word C_fcall C_i_allocated_finalizer_count(void) C_regparm;
C_fctexport C_word C_fcall C_i_live_finalizer_count(void) C_regparm;
C_fctexport C_word C_fcall C_i_profilingp(void) C_regparm;
C_fctexport C_word C_fcall C_i_tty_forcedp(void) C_regparm;


C_fctexport C_word C_fcall C_a_i_cpu_time(C_word **a, int c, C_word buf) C_regparm;
C_fctexport C_word C_fcall C_a_i_exact_to_inexact(C_word **a, int c, C_word n) C_regparm;
C_fctexport C_word C_fcall C_i_file_exists_p(C_word name, C_word file, C_word dir) C_regparm;

C_fctexport C_word C_fcall C_s_a_i_abs(C_word **ptr, C_word n, C_word x) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_negate(C_word **ptr, C_word n, C_word x) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_minus(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_u_i_integer_negate(C_word **ptr, C_word n, C_word x) C_regparm;
C_fctexport C_word C_fcall C_s_a_u_i_integer_minus(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_plus(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_u_i_integer_plus(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_times(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_u_i_integer_times(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_arithmetic_shift(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_u_i_integer_gcd(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_quotient(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_u_i_integer_quotient(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_remainder(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_u_i_integer_remainder(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_modulo(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_u_i_integer_modulo(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_bitwise_and(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_bitwise_ior(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_bitwise_xor(C_word **ptr, C_word n, C_word x, C_word y) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_bitwise_not(C_word **ptr, C_word n, C_word x) C_regparm;
C_fctexport C_word C_fcall C_s_a_i_digits_to_integer(C_word **ptr, C_word n, C_word str, C_word start, C_word end, C_word radix, C_word negp) C_regparm;
C_fctexport C_word C_fcall C_s_a_u_i_flo_to_int(C_word **ptr, C_word n, C_word x) C_regparm;


C_fctexport C_word C_fcall C_i_foreign_char_argumentp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_fixnum_argumentp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_flonum_argumentp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_block_argumentp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_struct_wrapper_argumentp(C_word t, C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_string_argumentp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_symbol_argumentp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_tagged_pointer_argumentp(C_word x, C_word t) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_pointer_argumentp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_scheme_or_c_pointer_argumentp(C_word x) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_ranged_integer_argumentp(C_word x, C_word bits) C_regparm;
C_fctexport C_word C_fcall C_i_foreign_unsigned_ranged_integer_argumentp(C_word x, C_word bits) C_regparm;

C_fctexport C_char *C_lookup_procedure_id(void *ptr);
C_fctexport void *C_lookup_procedure_ptr(C_char *id);

C_fctexport C_word C_random_fixnum(C_word n) C_regparm;
C_fctexport C_word C_fcall C_s_a_u_i_random_int(C_word **ptr, C_word n, C_word rn) C_regparm;
C_fctexport C_word C_fcall C_a_i_random_real(C_word **ptr, C_word n) C_regparm;
C_fctexport C_word C_random_bytes(C_word buf, C_word size);
C_fctexport C_word C_set_random_seed(C_word buf, C_word n);

#ifdef C_SIXTY_FOUR
C_fctexport C_cpsproc(C_peek_signed_integer_32);
C_fctexport C_cpsproc(C_peek_unsigned_integer_32);
#else
# define C_peek_signed_integer_32    C_peek_signed_integer
# define C_peek_unsigned_integer_32  C_peek_unsigned_integer
#endif

C_fctexport C_word C_fcall C_decode_literal(C_word **ptr, C_char *str) C_regparm;
C_fctexport C_word C_fcall C_i_pending_interrupt(C_word dummy) C_regparm;

C_fctexport void *C_get_statistics(void);

/* defined in eval.scm: */
C_fctexport  void  CHICKEN_get_error_message(char *buf,int bufsize);
C_fctexport  int  CHICKEN_load(char * filename);
C_fctexport  int  CHICKEN_read(char * str,C_word *result);
C_fctexport  int  CHICKEN_apply_to_string(C_word func,C_word args,char *buf,int bufsize);
C_fctexport  int  CHICKEN_apply(C_word func,C_word args,C_word *result);
C_fctexport  int  CHICKEN_eval_string_to_string(char *str,char *buf,int bufsize);
C_fctexport  int  CHICKEN_eval_to_string(C_word exp,char *buf,int bufsize);
C_fctexport  int  CHICKEN_eval_string(char * str,C_word *result);
C_fctexport  int  CHICKEN_eval(C_word exp,C_word *result);
C_fctexport  int  CHICKEN_yield();

C_fctexport C_cpsproc(C_default_5fstub_toplevel);


/* Inline functions: */

#ifndef HAVE_STATEMENT_EXPRESSIONS

inline static C_word *C_a_i(C_word **a, int n)
{
  C_word *p = *a;
  
  *a += n;
  return p;
}

#endif

inline static C_word
C_mutate(C_word *slot, C_word val)
{
  if(!C_immediatep(val)) return C_mutate_slot(slot, val);
  else return *slot = val;
}

inline static C_word C_permanentp(C_word x)
{
  return C_mk_bool(!C_immediatep(x) &&
                   !C_in_stackp(x) &&
                   !C_in_heapp(x) &&
                   !C_in_scratchspacep(x));
}

inline static C_word C_u_i_namespaced_symbolp(C_word x)
{
  C_word s = C_symbol_name(x);
  return C_mk_bool(C_memchr(C_data_pointer(s), '#', C_header_size(s)));
}

inline static C_word C_flonum(C_word **ptr, double n)
{
  C_word 
    *p = *ptr,
    *p0;

#ifndef C_SIXTY_FOUR
#ifndef C_DOUBLE_IS_32_BITS
  /* Align double on 8-byte boundary: */
  if(C_aligned8(p)) ++p;
#endif
#endif

  p0 = p;
  *(p++) = C_FLONUM_TAG;
  *((double *)p) = n;
  *ptr = p + sizeof(double) / sizeof(C_word);
  return (C_word)p0;
}


inline static C_word C_fcall C_u_i_zerop2(C_word x)
{
  return C_mk_bool(x == C_fix(0) ||
                   (!C_immediatep(x) &&
                    C_block_header(x) == C_FLONUM_TAG &&
                    C_flonum_magnitude(x) == 0.0));
}


inline static C_word C_string_to_pbytevector(C_word s)
{
  return C_pbytevector(C_header_size(s), (C_char *)C_data_pointer(s));
}


inline static C_word C_a_i_record1(C_word **ptr, int n, C_word x1)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_STRUCTURE_TYPE | 1;
  *(p++) = x1;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_record2(C_word **ptr, int n, C_word x1, C_word x2)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_STRUCTURE_TYPE | 2;
  *(p++) = x1;
  *(p++) = x2;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_record3(C_word **ptr, int n, C_word x1, C_word x2, C_word x3)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_STRUCTURE_TYPE | 3;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_record4(C_word **ptr, int n, C_word x1, C_word x2, C_word x3, C_word x4)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_STRUCTURE_TYPE | 4;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *(p++) = x4;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_record5(C_word **ptr, int n, C_word x1, C_word x2, C_word x3, C_word x4,
				 C_word x5)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_STRUCTURE_TYPE | 5;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *(p++) = x4;
  *(p++) = x5;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_record6(C_word **ptr, int n, C_word x1, C_word x2, C_word x3, C_word x4,
				 C_word x5, C_word x6)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_STRUCTURE_TYPE | 6;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *(p++) = x4;
  *(p++) = x5;
  *(p++) = x6;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_record7(C_word **ptr, int n, C_word x1, C_word x2, C_word x3, C_word x4,
				 C_word x5, C_word x6, C_word x7)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_STRUCTURE_TYPE | 7;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *(p++) = x4;
  *(p++) = x5;
  *(p++) = x6;
  *(p++) = x7;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_record8(C_word **ptr, int n, C_word x1, C_word x2, C_word x3, C_word x4,
				 C_word x5, C_word x6, C_word x7, C_word x8)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_STRUCTURE_TYPE | 8;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *(p++) = x4;
  *(p++) = x5;
  *(p++) = x6;
  *(p++) = x7;
  *(p++) = x8;
  *ptr = p;
  return (C_word)p0;
}

inline static C_word C_cplxnum(C_word **ptr, C_word r, C_word i)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_CPLXNUM_TAG;
  *(p++) = r;
  *(p++) = i;
  *ptr = p;
  return (C_word)p0;
}

inline static C_word C_ratnum(C_word **ptr, C_word n, C_word d)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_RATNUM_TAG;
  *(p++) = n;
  *(p++) = d;
  *ptr = p;
  return (C_word)p0;
}

inline static C_word C_a_i_bignum_wrapper(C_word **ptr, C_word vec)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_BIGNUM_TAG;
  *(p++) = vec;
  *ptr = p;
  return (C_word)p0;
}

/* Silly (this is not normalized) but in some cases needed internally */
inline static C_word C_bignum0(C_word **ptr)
{
  C_word *p = *ptr, p0 = (C_word)p;

  *(p++) = C_STRING_TYPE | C_wordstobytes(1);
  *(p++) = 0; /* zero is always positive */
  *ptr = p;

  return C_a_i_bignum_wrapper(ptr, p0);
}

inline static C_word C_bignum1(C_word **ptr, int negp, C_uword d1)
{
  C_word *p = *ptr, p0 = (C_word)p;

  *(p++) = C_STRING_TYPE | C_wordstobytes(2);
  *(p++) = negp;
  *(p++) = d1;
  *ptr = p;

  return C_a_i_bignum_wrapper(ptr, p0);
}

/* Here d1, d2, ... are low to high (ie, little endian)! */
inline static C_word C_bignum2(C_word **ptr, int negp, C_uword d1, C_uword d2)
{
  C_word *p = *ptr, p0 = (C_word)p;

  *(p++) = C_STRING_TYPE | C_wordstobytes(3);
  *(p++) = negp;
  *(p++) = d1;
  *(p++) = d2;
  *ptr = p;

  return C_a_i_bignum_wrapper(ptr, p0);
}

inline static C_word C_i_bignump(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_block_header(x) == C_BIGNUM_TAG);
}


inline static double C_c_double(C_word x)
{
  if(x & C_FIXNUM_BIT) return (double)C_unfix(x);
  else return C_flonum_magnitude(x);
}

inline static C_word C_a_u_i_int_to_flo(C_word **ptr, int n, C_word x)
{
  if(x & C_FIXNUM_BIT) return C_a_i_fix_to_flo(ptr, n, x);
  else return C_a_u_i_big_to_flo(ptr, n, x);
}

inline static C_word C_num_to_int(C_word x)
{
  if(x & C_FIXNUM_BIT) {
    return C_unfix(x);
  } else {
#if DEBUGBUILD /* removes a warning with clang */
    C_CHECKp(x,C_bignump(C_VAL1(x)),0);
#endif
    if (C_bignum_negativep(x)) return -(C_word)C_bignum_digits(x)[0];
    else return (C_word)C_bignum_digits(x)[0];  /* should never be larger */
  }
}


inline static C_s64 C_num_to_int64(C_word x)
{
  if(x & C_FIXNUM_BIT) {
    return (C_s64)C_unfix(x);
  } else {
    C_s64 num = C_bignum_digits(x)[0];
#ifndef C_SIXTY_FOUR
    if (C_bignum_size(x) > 1) num |= (C_s64)(((C_u64)C_bignum_digits(x)[1]) << 32);
#endif
    if (C_bignum_negativep(x)) return -num;
    else return num;
  }
}


inline static C_u64 C_num_to_uint64(C_word x)
{
  if(x & C_FIXNUM_BIT) {
    return (C_u64)C_unfix(x);
  } else {
    C_s64 num = C_bignum_digits(x)[0];
#ifndef C_SIXTY_FOUR
    if (C_bignum_size(x) > 1) num |= ((C_u64)C_bignum_digits(x)[1]) << 32;
#endif
    return num;
  }
}


inline static C_uword C_num_to_unsigned_int(C_word x)
{
  if(x & C_FIXNUM_BIT) {
    return (C_uword)C_unfix(x);
  } else {
    return C_bignum_digits(x)[0]; /* should never be larger */
  }
}


inline static C_word C_int_to_num(C_word **ptr, C_word n)
{
  if(C_fitsinfixnump(n)) return C_fix(n);
  else return C_bignum1(ptr, n < 0, C_wabs(n));
}


inline static C_word C_unsigned_int_to_num(C_word **ptr, C_uword n)
{
  if(C_ufitsinfixnump(n)) return C_fix(n);
  else return C_bignum1(ptr, 0, n);
}

inline static C_word C_int64_to_num(C_word **ptr, C_s64 n)
{
#ifdef C_SIXTY_FOUR
  if(C_fitsinfixnump(n)) {
    return C_fix(n);
  } else {
    C_u64 un = n < 0 ? -n : n;
    return C_bignum1(ptr, n < 0, un);
  }
#else
  C_u64 un = n < 0 ? -n : n;
  C_word res = C_bignum2(ptr, n < 0, (C_uword)un, (C_uword)(un >> 32));
  return C_bignum_simplify(res);
#endif
}

inline static C_word C_uint64_to_num(C_word **ptr, C_u64 n)
{
  if(C_ufitsinfixnump(n)) {
    return C_fix(n);
  } else {
#ifdef C_SIXTY_FOUR
    return C_bignum1(ptr, 0, n);
#else
    C_word res = C_bignum2(ptr, 0, (C_uword)n, (C_uword)(n >> 32));
    return C_bignum_simplify(res);
#endif
  }
}

inline static C_word C_long_to_num(C_word **ptr, C_long n)
{
  if(C_fitsinfixnump(n)) {
    return C_fix(n);
  } else {
    return C_bignum1(ptr, n < 0, C_wabs(n));
  }
}

inline static C_word C_unsigned_long_to_num(C_word **ptr, C_ulong n)
{
  if(C_ufitsinfixnump(n)) {
    return C_fix(n);
  } else {
    return C_bignum1(ptr, 0, n);
  }
}


inline static char *C_string_or_null(C_word x)
{
  return C_truep(x) ? C_c_string(x) : NULL;
}


inline static void *C_data_pointer_or_null(C_word x)
{
  return C_truep(x) ? C_data_pointer(x) : NULL;
}


inline static void *C_srfi_4_vector_or_null(C_word x)
{
  return C_truep(x) ? C_srfi_4_vector(x) : NULL;
}


inline static void *C_c_pointer_vector_or_null(C_word x)
{
  return C_truep(x) ? C_data_pointer(C_block_item(x, 2)) : NULL;
}


inline static void *C_c_pointer_or_null(C_word x)
{
  return C_truep(x) ? (void *)C_block_item(x, 0) : NULL;
}


inline static void *C_scheme_or_c_pointer(C_word x)
{
  return C_anypointerp(x) ? (void *)C_block_item(x, 0) : C_data_pointer(x);
}


inline static C_long C_num_to_long(C_word x)
{
  if(x & C_FIXNUM_BIT) {
    return (C_long)C_unfix(x);
  } else {
    if (C_bignum_negativep(x)) return -(C_long)C_bignum_digits(x)[0];
    else return (C_long)C_bignum_digits(x)[0];
  }
}


inline static C_ulong C_num_to_unsigned_long(C_word x)
{
  if(x & C_FIXNUM_BIT) {
    return (C_ulong)C_unfix(x);
  } else {
    return (C_ulong)C_bignum_digits(x)[0];
  }
}


inline static C_word C_u_i_string_equal_p(C_word x, C_word y)
{
  C_uword n = C_header_size(x);
  return C_mk_bool(n == C_header_size(y)
         && !C_memcmp((char *)C_data_pointer(x), (char *)C_data_pointer(y), n));
}

/* Like memcmp but case insensitive (to strncasecmp as memcmp is to strncmp) */
inline static int C_memcasecmp(const char *x, const char *y, unsigned int len)
{
  const unsigned char *ux = (const unsigned char *)x;
  const unsigned char *uy = (const unsigned char *)y;

  while (len--) {
    if (tolower(*ux++) != tolower(*uy++))
      return (tolower(*--ux) - tolower(*--uy));
  }
  return 0;
}

inline static C_word C_ub_i_flonum_eqvp(double x, double y)
{
  /* This can distinguish between -0.0 and +0.0 */
  return x == y && signbit(x) == signbit(y);
}

inline static C_word basic_eqvp(C_word x, C_word y)
{
  return (x == y ||

          (!C_immediatep(x) && !C_immediatep(y) &&
           C_block_header(x) == C_block_header(y) &&

           ((C_block_header(x) == C_FLONUM_TAG &&
             C_ub_i_flonum_eqvp(C_flonum_magnitude(x),
                                C_flonum_magnitude(y))) ||

            (C_block_header(x) == C_BIGNUM_TAG &&
             C_block_header(y) == C_BIGNUM_TAG &&
             C_i_bignum_cmp(x, y) == C_fix(0)))));
}

inline static C_word C_i_eqvp(C_word x, C_word y)
{
   return C_mk_bool(basic_eqvp(x, y) ||
                    (!C_immediatep(x) && !C_immediatep(y) &&
                     C_block_header(x) == C_block_header(y) &&
                     (C_block_header(x) == C_RATNUM_TAG ||
                      C_block_header(x) == C_CPLXNUM_TAG) &&
                     basic_eqvp(C_block_item(x, 0), C_block_item(y, 0)) &&
                     basic_eqvp(C_block_item(x, 1), C_block_item(y, 1))));
}

inline static C_word C_i_symbolp(C_word x)
{
  return C_mk_bool(!C_immediatep(x) &&
                   C_block_header(x) == C_SYMBOL_TAG &&
                   C_symbol_plist(x) != C_SCHEME_FALSE);
}

inline static C_word C_i_keywordp(C_word x)
{
  return C_mk_bool(!C_immediatep(x) &&
                   C_block_header(x) == C_SYMBOL_TAG &&
                   C_symbol_plist(x) == C_SCHEME_FALSE);
}

inline static int C_persistable_symbol(C_word x)
{
  /* Symbol is bound, or has a non-empty plist (but is not a keyword) */
  return ((C_truep(C_boundp(x)) ||
           C_symbol_plist(x) != C_SCHEME_END_OF_LIST) &&
          C_symbol_plist(x) != C_SCHEME_FALSE);
}

inline static C_word C_i_pairp(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_header_type(x) == C_PAIR_TYPE);
}

inline static C_word C_i_weak_pairp(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_block_header(x) == C_WEAK_PAIR_TAG);
}

inline static C_word C_i_stringp(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_header_bits(x) == C_STRING_TYPE);
}


inline static C_word C_i_locativep(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_block_header(x) == C_LOCATIVE_TAG);
}


inline static C_word C_i_vectorp(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_header_bits(x) == C_VECTOR_TYPE);
}

inline static C_word C_i_srfi_4_vectorp(C_word x)
{
  return C_mk_bool(!C_immediatep(x) &&
                   C_header_bits(x) == C_STRUCTURE_TYPE &&
                   (C_truep(C_i_u8vectorp(x)) ||
                    C_truep(C_i_s8vectorp(x)) ||
                    C_truep(C_i_u16vectorp(x)) ||
                    C_truep(C_i_s16vectorp(x)) ||
                    C_truep(C_i_u32vectorp(x)) ||
                    C_truep(C_i_s32vectorp(x)) ||
                    C_truep(C_i_u64vectorp(x)) ||
                    C_truep(C_i_s64vectorp(x)) ||
                    C_truep(C_i_f32vectorp(x)) ||
                    C_truep(C_i_f64vectorp(x))));
}

inline static C_word C_i_portp(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_header_bits(x) == C_PORT_TYPE);
}


inline static C_word C_i_closurep(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_header_bits(x) == C_CLOSURE_TYPE);
}

inline static C_word C_i_numberp(C_word x)
{
  return C_mk_bool((x & C_FIXNUM_BIT) ||
                   (!C_immediatep(x) && 
                    (C_block_header(x) == C_FLONUM_TAG ||
                     C_block_header(x) == C_BIGNUM_TAG ||
                     C_block_header(x) == C_RATNUM_TAG ||
                     C_block_header(x) == C_CPLXNUM_TAG)));
}

/* All numbers are real, except for cplxnums */
inline static C_word C_i_realp(C_word x)
{
  return C_mk_bool((x & C_FIXNUM_BIT) ||
                   (!C_immediatep(x) && 
                    (C_block_header(x) == C_FLONUM_TAG ||
                     C_block_header(x) == C_BIGNUM_TAG ||
                     C_block_header(x) == C_RATNUM_TAG)));
}

/* All finite real numbers are rational */
inline static C_word C_i_rationalp(C_word x)
{
  if(x & C_FIXNUM_BIT) {
    return C_SCHEME_TRUE;
  } else if (C_immediatep(x)) {
    return C_SCHEME_FALSE;
  } else if(C_block_header(x) == C_FLONUM_TAG) {
    double n = C_flonum_magnitude(x);
    return C_mk_bool(!C_isinf(n) && !C_isnan(n));
  } else {
    return C_mk_bool(C_block_header(x) == C_BIGNUM_TAG ||
                     C_block_header(x) == C_RATNUM_TAG);
  }
}


inline static C_word C_u_i_fpintegerp(C_word x)
{
  double dummy, val;

  val = C_flonum_magnitude(x);

  if(C_isnan(val) || C_isinf(val)) return C_SCHEME_FALSE;

  return C_mk_bool(C_modf(val, &dummy) == 0.0);
}


inline static int C_ub_i_fpintegerp(double x)
{
  double dummy;

  return C_modf(x, &dummy) == 0.0;
}

inline static C_word C_i_exact_integerp(C_word x)
{
  return C_mk_bool((x) & C_FIXNUM_BIT || C_truep(C_i_bignump(x)));
}

inline static C_word C_u_i_exactp(C_word x)
{
  if (C_truep(C_i_exact_integerp(x))) {
    return C_SCHEME_TRUE;
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    return C_SCHEME_FALSE;
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    return C_SCHEME_TRUE;
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    x = C_u_i_cplxnum_real(x);
    /* r and i are always the same exactness, and we assume they
     * always store a number.
     */
    return C_mk_bool(C_immediatep(x) || (C_block_header(x) != C_FLONUM_TAG));
  } else {
    return C_SCHEME_FALSE;
  }
}

inline static C_word C_u_i_inexactp(C_word x)
{
  if (C_immediatep(x)) {
    return C_SCHEME_FALSE;
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    return C_SCHEME_TRUE;
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    x = C_u_i_cplxnum_real(x); /* r and i are always the same exactness */
    return C_mk_bool(!C_immediatep(x) && (C_block_header(x) == C_FLONUM_TAG));
  } else {
    return C_SCHEME_FALSE;
  }
}

inline static C_word C_i_integerp(C_word x)
{
  double dummy, val;

  if (x & C_FIXNUM_BIT || C_truep(C_i_bignump(x)))
    return C_SCHEME_TRUE;
  if (C_immediatep(x) || C_block_header(x) != C_FLONUM_TAG)
    return C_SCHEME_FALSE;

  val = C_flonum_magnitude(x);
  if(C_isnan(val) || C_isinf(val)) return C_SCHEME_FALSE;

  return C_mk_bool(C_modf(val, &dummy) == 0.0);
}


inline static C_word C_i_flonump(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_block_header(x) == C_FLONUM_TAG);
}

inline static C_word C_i_cplxnump(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_block_header(x) == C_CPLXNUM_TAG);
}

inline static C_word C_i_ratnump(C_word x)
{
  return C_mk_bool(!C_immediatep(x) && C_block_header(x) == C_RATNUM_TAG);
}

/* TODO: Is this correctly named?  Shouldn't it accept an argcount? */
inline static C_word C_a_u_i_fix_to_big(C_word **ptr, C_word x)
{
  x = C_unfix(x);
  if (x < 0)
    return C_bignum1(ptr, 1, -x);
  else if (x == 0)
    return C_bignum0(ptr);
  else
    return C_bignum1(ptr, 0, x);
}

inline static C_word C_i_fixnum_min(C_word x, C_word y)
{
  return ((C_word)x < (C_word)y) ? x : y;
}


inline static C_word C_i_fixnum_max(C_word x, C_word y)
{
  return ((C_word)x > (C_word)y) ? x : y;
}

inline static C_word C_i_fixnum_gcd(C_word x, C_word y)
{
   x = (x & C_INT_SIGN_BIT) ? -C_unfix(x) : C_unfix(x);
   y = (y & C_INT_SIGN_BIT) ? -C_unfix(y) : C_unfix(y);
   
   while(y != 0) {
     C_word r = x % y;
     x = y;
     y = r;
   }
   return C_fix(x);
}

inline static C_word C_fixnum_divide(C_word x, C_word y)
{
  if(y == C_fix(0)) C_div_by_zero_error(C_text("fx/"));
  return C_u_fixnum_divide(x, y);
}


inline static C_word C_u_fixnum_modulo(C_word x, C_word y)
{
  y = C_unfix(y);
  x = C_unfix(x) % y;
  if ((y < 0 && x > 0) || (y > 0 && x < 0)) x += y;
  return C_fix(x);
}


inline static C_word C_fixnum_modulo(C_word x, C_word y)
{
  if(y == C_fix(0)) {
    C_div_by_zero_error(C_text("fxmod"));
  } else {
    return C_u_fixnum_modulo(x,y);
  }
}

/* XXX: Naming convention is inconsistent!  There's C_fixnum_divide()
 * but also C_a_i_flonum_quotient_checked()
 */
inline static C_word
C_a_i_fixnum_quotient_checked(C_word **ptr, int c, C_word x, C_word y)
{
  if (y == C_fix(0)) {
    C_div_by_zero_error(C_text("fx/"));
  } else if (x == C_fix(C_MOST_NEGATIVE_FIXNUM) && y == C_fix(-1)) {
    return C_bignum1(ptr, 0, -C_MOST_NEGATIVE_FIXNUM); /* Special case */
  } else {
    return C_u_fixnum_divide(x, y); /* Inconsistent, too: missing _i_ */
  }
}

inline static C_word C_i_fixnum_remainder_checked(C_word x, C_word y)
{
  if (y == C_fix(0)) {
    C_div_by_zero_error(C_text("fxrem"));
  } else {
    x = C_unfix(x);
    y = C_unfix(y);
    return C_fix(x - ((x / y) * y));
  }
}

inline static C_word C_i_fixnum_arithmetic_shift(C_word n, C_word c)
{
  if(C_unfix(c) < 0) return C_fixnum_shift_right(n, C_u_fixnum_negate(c));
  else return C_fixnum_shift_left(n, c);
}

inline static C_word C_a_i_fixnum_negate(C_word **ptr, C_word n, C_word x)
{
  /* Exceptional situation: this will cause an overflow to itself */
  if (x == C_fix(C_MOST_NEGATIVE_FIXNUM)) /* C_fitsinfixnump(x) */
    return C_bignum1(ptr, 0, -C_MOST_NEGATIVE_FIXNUM);
  else
    return C_fix(-C_unfix(x));
}

inline static C_word C_s_a_u_i_integer_abs(C_word **ptr, C_word n, C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_a_i_fixnum_abs(ptr, 1, x);
  } else if (C_bignum_negativep(x)) {
    return C_s_a_u_i_integer_negate(ptr, n, x);
  } else {
    return x;
  }
}

/* DEPRECATED */
inline static C_word C_i_fixnum_bit_to_bool(C_word n, C_word i)
{
    if (i & C_INT_SIGN_BIT) {
      C_not_an_uinteger_error(C_text("bit->boolean"), i);
    } else {
      i = C_unfix(i);
      if (i >= C_WORD_SIZE) return C_mk_bool(n & C_INT_SIGN_BIT);
      else return C_mk_bool((C_unfix(n) & (C_word)((C_uword)1 << i)) != 0);
    }
}

inline static C_word C_a_i_fixnum_difference(C_word **ptr, C_word n, C_word x, C_word y)
{
  C_word z = C_unfix(x) - C_unfix(y);

  if(!C_fitsinfixnump(z)) {
    return C_bignum1(ptr, z < 0, C_wabs(z));
  } else {
    return C_fix(z);
  }
}

inline static C_word C_a_i_fixnum_plus(C_word **ptr, C_word n, C_word x, C_word y)
{
  C_word z = C_unfix(x) + C_unfix(y);

  if(!C_fitsinfixnump(z)) {
    return C_bignum1(ptr, z < 0, C_wabs(z));
  } else {
    return C_fix(z);
  }
}

inline static C_word C_a_i_fixnum_times(C_word **ptr, C_word n, C_word x, C_word y)
{
  C_uword negp, xhi, xlo, yhi, ylo, p, rhi, rlo;

  negp = ((x & C_INT_SIGN_BIT) ? !(y & C_INT_SIGN_BIT) : (y & C_INT_SIGN_BIT));
  x = (x & C_INT_SIGN_BIT) ? -C_unfix(x) : C_unfix(x);
  y = (y & C_INT_SIGN_BIT) ? -C_unfix(y) : C_unfix(y);

  xhi = C_BIGNUM_DIGIT_HI_HALF(x); xlo = C_BIGNUM_DIGIT_LO_HALF(x);
  yhi = C_BIGNUM_DIGIT_HI_HALF(y); ylo = C_BIGNUM_DIGIT_LO_HALF(y);
  
  /* This is simply bignum_digits_multiply unrolled for 2x2 halfdigits */
  p = xlo * ylo;
  rlo = C_BIGNUM_DIGIT_LO_HALF(p);

  p = xhi * ylo + C_BIGNUM_DIGIT_HI_HALF(p);
  rhi = C_BIGNUM_DIGIT_HI_HALF(p);

  p = xlo * yhi + C_BIGNUM_DIGIT_LO_HALF(p);
  rlo = C_BIGNUM_DIGIT_COMBINE(C_BIGNUM_DIGIT_LO_HALF(p), rlo);

  rhi = xhi * yhi + C_BIGNUM_DIGIT_HI_HALF(p) + rhi;

  if (rhi) {
    return C_bignum2(ptr, negp != 0, rlo, rhi);
  } else if (negp ?
             ((rlo & C_INT_SIGN_BIT) || !C_fitsinfixnump(-(C_word)rlo)) :
             !C_ufitsinfixnump(rlo)) {
    return C_bignum1(ptr, negp != 0, rlo);
  } else {
    return C_fix(negp ? -rlo : rlo);
  }
}

inline static C_word C_i_flonum_min(C_word x, C_word y)
{
  double 
    xf = C_flonum_magnitude(x),
    yf = C_flonum_magnitude(y);

  return xf < yf ? x : y;
}


inline static C_word C_i_flonum_max(C_word x, C_word y)
{
  double 
    xf = C_flonum_magnitude(x),
    yf = C_flonum_magnitude(y);

  return xf > yf ? x : y;
}

inline static C_word C_u_i_integer_signum(C_word x)
{
  if (x & C_FIXNUM_BIT) return C_i_fixnum_signum(x);
  else return (C_bignum_negativep(x) ? C_fix(-1) : C_fix(1));
}

inline static C_word
C_a_i_flonum_quotient_checked(C_word **ptr, int c, C_word n1, C_word n2)
{
  double n3 = C_flonum_magnitude(n2);

  if(n3 == 0.0) C_div_by_zero_error(C_text("fp/?"));
  return C_flonum(ptr, C_flonum_magnitude(n1) / n3);
}


inline static double
C_ub_i_flonum_quotient_checked(double n1, double n2)
{
  if(n2 == 0.0) C_div_by_zero_error(C_text("fp/?"));
  return n1 / n2;
}

/* More weirdness: the other flonum_quotient macros and inline functions
 * do not compute the quotient but the "plain" division!
 */
inline static C_word
C_a_i_flonum_actual_quotient_checked(C_word **ptr, int c, C_word x, C_word y)
{
  double dy = C_flonum_magnitude(y), r;

  if(dy == 0.0) {
    C_div_by_zero_error(C_text("quotient"));
  } else if (!C_truep(C_u_i_fpintegerp(x))) {
    C_not_an_integer_error(C_text("quotient"), x);
  } else if (!C_truep(C_u_i_fpintegerp(y))) {
    C_not_an_integer_error(C_text("quotient"), y);
  } else {
    modf(C_flonum_magnitude(x) / dy, &r);
    return C_flonum(ptr, r);
  }
}

inline static C_word
C_a_i_flonum_remainder_checked(C_word **ptr, int c, C_word x, C_word y)
{
  double dx = C_flonum_magnitude(x),
         dy = C_flonum_magnitude(y), r;

  if(dy == 0.0) {
    C_div_by_zero_error(C_text("remainder"));
  } else if (!C_truep(C_u_i_fpintegerp(x))) {
    C_not_an_integer_error(C_text("remainder"), x);
  } else if (!C_truep(C_u_i_fpintegerp(y))) {
    C_not_an_integer_error(C_text("remainder"), y);
  } else {
    modf(dx / dy, &r);
    return C_flonum(ptr, dx - r * dy);
  }
}

inline static C_word
C_a_i_flonum_modulo_checked(C_word **ptr, int c, C_word x, C_word y)
{
  double dx = C_flonum_magnitude(x),
         dy = C_flonum_magnitude(y), r;

  if(dy == 0.0) {
    C_div_by_zero_error(C_text("modulo"));
  } else if (!C_truep(C_u_i_fpintegerp(x))) {
    C_not_an_integer_error(C_text("modulo"), x);
  } else if (!C_truep(C_u_i_fpintegerp(y))) {
    C_not_an_integer_error(C_text("modulo"), y);
  } else {
    modf(dx / dy, &r);
    r = dx - r * dy;
    if ((dy < 0 && r > 0) || (dy > 0 && r < 0)) r += y;
    return C_flonum(ptr, r);
  }
}

inline static C_word C_i_safe_pointerp(C_word x)
{
  if(C_immediatep(x)) return C_SCHEME_FALSE;

  switch(C_block_header(x)) {
  case C_POINTER_TAG:
  case C_TAGGED_POINTER_TAG:
    return C_SCHEME_TRUE;
  }

  return C_SCHEME_FALSE;
}


inline static C_word C_u_i_assq(C_word x, C_word lst)
{
  C_word a;

  while(!C_immediatep(lst)) {
    a = C_u_i_car(lst);

    if(C_u_i_car(a) == x) return a;
    else lst = C_u_i_cdr(lst);
  }

  return C_SCHEME_FALSE;
}


inline static C_word
C_fast_retrieve(C_word sym)
{
  C_word val = C_block_item(sym, 0);

  if(val == C_SCHEME_UNBOUND)
    C_unbound_variable(sym);

  return val;
}

inline static void *
C_fast_retrieve_proc(C_word closure)
{
  if(C_immediatep(closure) || C_header_bits(closure) != C_CLOSURE_TYPE) 
    return (void *)C_invalid_procedure;
  else 
    return (void *)C_block_item(closure, 0);
}


inline static void *
C_fast_retrieve_symbol_proc(C_word sym)
{
  return C_fast_retrieve_proc(C_fast_retrieve(sym));
}


inline static C_word C_a_i_vector1(C_word **ptr, int n, C_word x1)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_VECTOR_TYPE | 1;
  *(p++) = x1;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_vector2(C_word **ptr, int n, C_word x1, C_word x2)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_VECTOR_TYPE | 2;
  *(p++) = x1;
  *(p++) = x2;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_vector3(C_word **ptr, int n, C_word x1, C_word x2, C_word x3)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_VECTOR_TYPE | 3;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_vector4(C_word **ptr, int n, C_word x1, C_word x2, C_word x3, C_word x4)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_VECTOR_TYPE | 4;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *(p++) = x4;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_vector5(C_word **ptr, int n, C_word x1, C_word x2, C_word x3, C_word x4,
			      C_word x5)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_VECTOR_TYPE | 5;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *(p++) = x4;
  *(p++) = x5;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_vector6(C_word **ptr, int n, C_word x1, C_word x2, C_word x3, C_word x4,
			      C_word x5, C_word x6)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_VECTOR_TYPE | 6;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *(p++) = x4;
  *(p++) = x5;
  *(p++) = x6;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_vector7(C_word **ptr, int n, C_word x1, C_word x2, C_word x3, C_word x4,
			      C_word x5, C_word x6, C_word x7)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_VECTOR_TYPE | 7;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *(p++) = x4;
  *(p++) = x5;
  *(p++) = x6;
  *(p++) = x7;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_vector8(C_word **ptr, int n, C_word x1, C_word x2, C_word x3, C_word x4,
			      C_word x5, C_word x6, C_word x7, C_word x8)
{
  C_word *p = *ptr, *p0 = p; 

  *(p++) = C_VECTOR_TYPE | 8;
  *(p++) = x1;
  *(p++) = x2;
  *(p++) = x3;
  *(p++) = x4;
  *(p++) = x5;
  *(p++) = x6;
  *(p++) = x7;
  *(p++) = x8;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_fcall C_a_pair(C_word **ptr, C_word car, C_word cdr)
{
  C_word *p = *ptr, *p0 = p;
 
  *(p++) = C_PAIR_TYPE | (C_SIZEOF_PAIR - 1);
  *(p++) = car;
  *(p++) = cdr;
  *ptr = p;
  return (C_word)p0;
}

inline static C_word C_fcall C_a_weak_pair(C_word **ptr, C_word head, C_word tail)
{
  C_word *p = *ptr, *p0 = p;

  *(p++) = C_WEAK_PAIR_TAG; /* Changes to strong if sym is persisted */
  *(p++) = head;
  *(p++) = tail;
  *ptr = p;
  return (C_word)p0;
}


inline static C_word C_a_i_list1(C_word **a, int n, C_word x1)
{
  return C_a_pair(a, x1, C_SCHEME_END_OF_LIST);
}


inline static C_word C_a_i_list2(C_word **a, int n, C_word x1, C_word x2)
{
  C_word x = C_a_pair(a, x2, C_SCHEME_END_OF_LIST);

  return C_a_pair(a, x1, x);
}


inline static C_word C_a_i_list3(C_word **a, int n, C_word x1, C_word x2, C_word x3)
{
  C_word x = C_a_pair(a, x3, C_SCHEME_END_OF_LIST);

  x = C_a_pair(a, x2, x);
  return C_a_pair(a, x1, x);
}


inline static C_word C_a_i_list4(C_word **a, int n, C_word x1, C_word x2, C_word x3, C_word x4)
{
  C_word x = C_a_pair(a, x4, C_SCHEME_END_OF_LIST);

  x = C_a_pair(a, x3, x);
  x = C_a_pair(a, x2, x);
  return C_a_pair(a, x1, x);
}


inline static C_word C_a_i_list5(C_word **a, int n, C_word x1, C_word x2, C_word x3, C_word x4,
			    C_word x5)
{
  C_word x = C_a_pair(a, x5, C_SCHEME_END_OF_LIST);

  x = C_a_pair(a, x4, x);
  x = C_a_pair(a, x3, x);
  x = C_a_pair(a, x2, x);
  return C_a_pair(a, x1, x);
}


inline static C_word C_a_i_list6(C_word **a, int n, C_word x1, C_word x2, C_word x3, C_word x4,
			    C_word x5, C_word x6)
{
  C_word x = C_a_pair(a, x6, C_SCHEME_END_OF_LIST);

  x = C_a_pair(a, x5, x);
  x = C_a_pair(a, x4, x);
  x = C_a_pair(a, x3, x);
  x = C_a_pair(a, x2, x);
  return C_a_pair(a, x1, x);
}


inline static C_word C_a_i_list7(C_word **a, int n, C_word x1, C_word x2, C_word x3, C_word x4,
			    C_word x5, C_word x6, C_word x7)
{
  C_word x = C_a_pair(a, x7, C_SCHEME_END_OF_LIST);

  x = C_a_pair(a, x6, x);
  x = C_a_pair(a, x5, x);
  x = C_a_pair(a, x4, x);
  x = C_a_pair(a, x3, x);
  x = C_a_pair(a, x2, x);
  return C_a_pair(a, x1, x);
}


inline static C_word C_a_i_list8(C_word **a, int n, C_word x1, C_word x2, C_word x3, C_word x4,
			    C_word x5, C_word x6, C_word x7, C_word x8)
{
  C_word x = C_a_pair(a, x8, C_SCHEME_END_OF_LIST);

  x = C_a_pair(a, x7, x);
  x = C_a_pair(a, x6, x);
  x = C_a_pair(a, x5, x);
  x = C_a_pair(a, x4, x);
  x = C_a_pair(a, x3, x);
  x = C_a_pair(a, x2, x);
  return C_a_pair(a, x1, x);
}


/*
 * From Hacker's Delight by Henry S. Warren
 * based on a modified nlz() from section 5-3 (fig. 5-7)
 */
inline static int C_ilen(C_uword x)
{
  C_uword y;
  C_word n = 0;

#ifdef C_SIXTY_FOUR
  y = x >> 32; if (y != 0) { n += 32; x = y; }
#endif
  y = x >> 16; if (y != 0) { n += 16; x = y; }
  y = x >>  8; if (y != 0) { n +=  8; x = y; }
  y = x >>  4; if (y != 0) { n +=  4; x = y; }
  y = x >>  2; if (y != 0) { n +=  2; x = y; }
  y = x >>  1; if (y != 0) return n + 2;
  return n + x;
}

/* These strl* functions are based on public domain code by C.B. Falconer */
#ifdef HAVE_STRLCPY
# define C_strlcpy                  strlcpy
#else
inline static size_t C_strlcpy(char *dst, const char *src, size_t sz)
{
   const char *start = src;

   if (sz--) {
      while ((*dst++ = *src))
         if (sz--) src++;
         else {
            *(--dst) = '\0';
            break;
         }
   }
   while (*src++) continue;
   return src - start - 1;
}
#endif

#ifdef HAVE_STRLCAT
# define C_strlcat                  strlcat
#else
inline static size_t C_strlcat(char *dst, const char *src, size_t sz)
{
   char  *start = dst;

   while (*dst++)    /* assumes sz >= strlen(dst) */
      if (sz) sz--;    /* i.e. well formed string */
   dst--;
   return dst - start + C_strlcpy(dst, src, sz);
}
#endif

/*
 * MinGW's stat() is less than ideal in a couple of ways, so we provide a
 * wrapper that:
 *
 *  1. Strips all trailing slashes and retries on failure, since stat() will
 *     yield ENOENT when given two (on MSYS) or more (on MinGW and MSYS2).
 *  2. Fails with ENOTDIR when given a path to a non-directory file that ends
 *     in a slash, since in this case MinGW's stat() will succeed but return a
 *     non-directory mode in buf.st_mode.
 */
#if defined(__MINGW32__)
inline static int C_stat(const char *path, struct stat *buf)
{
  size_t len = C_strlen(path);
  char slash = len && C_strchr("\\/", path[len - 1]), *str;

  if(stat(path, buf) == 0)
    goto dircheck;

  if(slash && errno == ENOENT) {
    C_strlcpy((str = (char *)C_alloca(len + 1)), path, len + 1);
    while(len > 1 && C_strchr("\\/", path[--len]))
      str[len] = '\0';
    if(stat(str, buf) == 0)
      goto dircheck;
  }

  return -1;

dircheck:
  if(slash && !S_ISDIR(buf->st_mode)) {
    errno = ENOTDIR;
    return -1;
  }

  return 0;
}
/*
 * Haiku's stat() has a similar issue, where it will gladly succeed
 * when given a path to a filename with a trailing slash.
 */
#elif defined(__HAIKU__)
inline static int C_stat(const char *path, struct stat *buf)
{
  size_t len = C_strlen(path);
  char slash = len && path[len - 1] == '/';

  if(stat(path, buf) != 0) {
    return -1;
  }

  if (slash && !S_ISDIR(buf->st_mode)) {
    errno = ENOTDIR;
    return -1;
  }

  return 0;
}
#else
# define C_stat stat
#endif

/* Safe realpath usage depends on a reliable PATH_MAX. */
#ifdef PATH_MAX
# define C_realpath realpath
#else
inline static char *C_realpath(const char *path, char *resolved)
{
# if _POSIX_C_SOURCE >= 200809L
  char *p;
  size_t n;
  if((p = realpath(path, NULL)) == NULL)
    return NULL;
  n = C_strlcpy(resolved, p, C_MAX_PATH);
  C_free(p);
  if(n < C_MAX_PATH)
    return resolved;
# endif
  return NULL;
}
#endif

C_END_C_DECLS

#endif /* ___CHICKEN */
