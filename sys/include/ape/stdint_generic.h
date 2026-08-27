#ifndef _STDINT_GENERIC_H_
#define _STDINT_GENERIC_H_ 1

/*
 * The arch-independent half of <stdint.h>. Reached through the <stdint.h>
 * in this directory and in each architecture directory, never by that
 * name itself -- see the comment in either of them for why it cannot be
 * called stdint.h.
 */
#include <_apetypes.h>
#include <stdint_arch.h>

/*
 * Default for architectures that don't define width/types in stdint_arch.h
 */
#ifndef _STDINT_ARCH_H_
# ifndef INTPTR_WIDTH
#  define INTPTR_WIDTH 32
#  define UINTPTR_WIDTH 32
# endif
# if INTPTR_WIDTH == 64
typedef long long _intptr_t;
typedef unsigned long long _uintptr_t;
# else
typedef int _intptr_t;
typedef unsigned int _uintptr_t;
# endif
#endif

/*
 * INTPTR_WIDTH decides SIZE_MAX, UINTPTR_MAX and PTRDIFF_MAX below, and
 * it used to come only from <stdint_arch.h>, with a silent fall back to
 * 32 if that header had not been read. Silent is the problem: it is not
 * a conservative default but a wrong answer, and the failure it produces
 * is remote from its cause.
 *
 * It produced this. SIZE_MAX came out 0xffffffff on amd64 while size_t
 * stayed 8 bytes, so gnulib's
 *
 *	for (size_t i = 0;
 *	     ! (argsize == SIZE_MAX ? arg[i] == '\0' : i == argsize);
 *	     i++)
 *
 * -- with argsize passed as (size_t)-1 to mean "find the NUL" -- never
 * matched, never tested for the NUL, and counted towards 2**64 instead.
 * GNU ls faulted reading past the end of the heap, several thousand
 * bytes beyond a perfectly well-formed filename.
 *
 * _BITS64 is the signal the rest of this tree already uses: <alltypes.h>,
 * <stddef.h>, <unistd.h>, <bsd.h> and <pthread.h> all key off it, and it
 * is what makes size_t 64-bit in the first place. So it decides here
 * too, and overrides rather than defers: the stock arch stdint.h that
 * caused this shares stdint_arch.h's guard, which left INTPTR_WIDTH
 * undefined rather than wrong, and deferring to that is how the bug
 * survived. The #error below is only for the reverse -- a width of 64
 * where nothing said 64-bit -- which would mean the two headers had come
 * from different architectures.
 */
#ifdef _BITS64
# undef INTPTR_WIDTH
# undef UINTPTR_WIDTH
# define INTPTR_WIDTH 64
# define UINTPTR_WIDTH 64
#endif

#ifndef INTPTR_WIDTH
# define INTPTR_WIDTH 32
# define UINTPTR_WIDTH 32
#endif

#if !defined(_BITS64) && INTPTR_WIDTH == 64
# error "stdint_generic.h: INTPTR_WIDTH is 64 but _BITS64 is not set"
#endif

/*
 * There were u8/u16/u32/u64 and s8/s16/s32/s64 typedefs here. They are
 * neither C nor POSIX names, <stdint.h> is included by nearly everything,
 * and they are exactly the names a program picks for its own short
 * aliases -- so any file that defined its own met a redeclaration:
 *
 *	camellia.c:93 external redeclaration of: u32
 *	    TYPEDEF UINT   crypto/camellia/camellia.c:93
 *	    TYPEDEF ULONG  /sys/include/ape/stdint_generic.h:81
 *
 * They were also wrong: u32/s32 were spelled "unsigned long"/"long",
 * which is 32-bit only because kencc's long happens to be 32-bit on
 * amd64. Nothing in this tree used them -- libsec's aes.c, aesCFB.c and
 * aesOFB.c each declare their own -- so they are gone. Use uint32_t.
 */

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef long long intmax_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef unsigned long long uintmax_t;

typedef int8_t	int_fast8_t;
typedef int16_t	int_fast16_t;
typedef int32_t	int_fast32_t;
typedef int64_t	int_fast64_t;

typedef int8_t	int_least8_t;
typedef int16_t	int_least16_t;
typedef int32_t	int_least32_t;
typedef int64_t	int_least64_t;

typedef uint8_t		uint_fast8_t;
typedef uint16_t	uint_fast16_t;
typedef uint32_t	uint_fast32_t;
typedef uint64_t	uint_fast64_t;

typedef uint8_t		uint_least8_t;
typedef uint16_t	uint_least16_t;
typedef uint32_t	uint_least32_t;
typedef uint64_t	uint_least64_t;

typedef _intptr_t intptr_t;
typedef _uintptr_t uintptr_t;

/* C99 integer constant macros. Plan9 is LLP64: int=long=32-bit, long long=64-bit. */
#define INT8_C(c)    c
#define INT16_C(c)   c
#define INT32_C(c)   c##L
#define INT64_C(c)   c##LL
#define UINT8_C(c)   c##U
#define UINT16_C(c)  c##U
#define UINT32_C(c)  c##UL
#define UINT64_C(c)  c##ULL
#define INTMAX_C(c)  c##LL
#define UINTMAX_C(c) c##ULL

/*
 * C99 7.18: these macros must be usable in #if. A cast is not allowed
 * there -- the type name is not a macro, so cpp reads it as 0 and the
 * expression falls apart. They were spelled ((int64_t)0x8000...LL) and
 * so on, which cost GNU tar:
 *
 *   list.c:744 Syntax error in #if/#elif
 *
 * on "#if ! (INTMAX_MAX <= UINTMAX_MAX && - (INTMAX_MIN + 1) <= UINTMAX_MAX)".
 *
 * -MAX-1 is the usual spelling and is well defined besides: 0x80000000
 * has type unsigned int, since it does not fit in int, so casting it to
 * int32_t was implementation-defined where negating the maximum is not.
 */
#define INT8_MIN	(-INT8_MAX-1)
#define INT16_MIN	(-INT16_MAX-1)
#define INT32_MIN	(-INT32_MAX-1)
#define INT64_MIN	(-INT64_MAX-1)
#define INTMAX_MIN	INT64_MIN

#define UINT8_MIN	0
#define UINT16_MIN	0 
#define UINT32_MIN	0 
#define UINT64_MIN	0
#define UINTMAX_MIN	UINT64_MIN

#define INT_FAST8_MIN	INT8_MIN
#define INT_FAST16_MIN	INT16_MIN
#define INT_FAST32_MIN	INT32_MIN
#define INT_FAST64_MIN	INT64_MIN

#define UINT_FAST8_MIN	UINT8_MIN
#define UINT_FAST16_MIN	UINT16_MIN
#define UINT_FAST32_MIN	UINT32_MIN
#define UINT_FAST64_MIN	UINT64_MIN

#define INT_LEAST8_MIN	INT8_MIN
#define INT_LEAST16_MIN	INT16_MIN
#define INT_LEAST32_MIN	INT32_MIN
#define INT_LEAST64_MIN	INT64_MIN

#define UINT_LEAST8_MIN		UINT8_MIN
#define UINT_LEAST16_MIN	UINT16_MIN
#define UINT_LEAST32_MIN	UINT32_MIN
#define UINT_LEAST64_MIN	UINT64_MIN

#define INT8_MAX	0x7f
#define INT16_MAX	0x7fff
#define INT32_MAX	0x7fffffff
#define INT64_MAX	0x7fffffffffffffffLL
#define INTMAX_MAX	INT64_MAX

#define UINT8_MAX	0xff
#define UINT16_MAX	0xffff
#define UINT32_MAX	0xffffffffL
#define UINT64_MAX	0xffffffffffffffffULL
#define UINTMAX_MAX	UINT64_MAX

#define INT_FAST8_MAX	INT8_MAX
#define INT_FAST16_MAX	INT16_MAX
#define INT_FAST32_MAX	INT32_MAX
#define INT_FAST64_MAX	INT64_MAX

#define UINT_FAST8_MAX	UINT8_MAX
#define UINT_FAST16_MAX	UINT16_MAX
#define UINT_FAST32_MAX	UINT32_MAX
#define UINT_FAST64_MAX	UINT64_MAX

#define INT_LEAST8_MAX	INT8_MAX
#define INT_LEAST16_MAX	INT16_MAX
#define INT_LEAST32_MAX	INT32_MAX
#define INT_LEAST64_MAX	INT64_MAX

#define UINT_LEAST8_MAX		UINT8_MAX
#define UINT_LEAST16_MAX	UINT16_MAX
#define UINT_LEAST32_MAX	UINT32_MAX
#define UINT_LEAST64_MAX	UINT64_MAX

#ifndef INTPTR_WIDTH
#define INTPTR_WIDTH 32
#define UINTPTR_WIDTH 32
#endif

#if INTPTR_WIDTH == 64
#define INTPTR_MIN	INT64_MIN
#define INTPTR_MAX	INT64_MAX
#define UINTPTR_MAX	UINT64_MAX
#define PTRDIFF_MAX	INT64_MAX
#define PTRDIFF_MIN	INT64_MIN
#define PTRDIFF_WIDTH	64
#else
#define INTPTR_MIN	INT32_MIN
#define INTPTR_MAX	INT32_MAX
#define UINTPTR_MAX	UINT32_MAX
#define PTRDIFF_MAX	INT32_MAX
#define PTRDIFF_MIN	INT32_MIN
#define PTRDIFF_WIDTH	32
#endif

#define INT8_WIDTH         8
#define UINT8_WIDTH        8
#define INT16_WIDTH        16
#define UINT16_WIDTH       16
#define INT32_WIDTH        32
#define UINT32_WIDTH       32
#define INT64_WIDTH        64
#define UINT64_WIDTH       64

#define INT_LEAST8_WIDTH   8
#define UINT_LEAST8_WIDTH  8
#define INT_LEAST16_WIDTH  16
#define UINT_LEAST16_WIDTH 16
#define INT_LEAST32_WIDTH  32
#define UINT_LEAST32_WIDTH 32
#define INT_LEAST64_WIDTH  64
#define UINT_LEAST64_WIDTH 64

#define INT_FAST8_WIDTH    8
#define UINT_FAST8_WIDTH   8
#define INT_FAST16_WIDTH   16
#define UINT_FAST16_WIDTH  16
#define INT_FAST32_WIDTH   32
#define UINT_FAST32_WIDTH  32
#define INT_FAST64_WIDTH   64
#define UINT_FAST64_WIDTH  64

#define INTMAX_WIDTH       64
#define UINTMAX_WIDTH      64

/*
 * size_t follows the pointer width. It has done since 2026-04; the
 * comment that used to sit here said the opposite -- "Right now, all of
 * our size_t types are 32 bit, even on 64 bit architectures" -- which
 * was the state of things when SIZE_MAX was written, and stopped being
 * true when amd64/include/ape/stddef_arch.h gained
 *
 *	typedef unsigned long long _size_t;
 *
 * A SIZE_MAX that does not match size_t is not a cosmetic mismatch: see
 * the note on INTPTR_WIDTH above.
 */
#ifndef SIZE_MIN
#define SIZE_MIN	0
#endif
#if INTPTR_WIDTH == 64
#define SIZE_MAX	UINT64_MAX
#define SIZE_WIDTH	64
#else
#define SIZE_MAX	UINT32_MAX
#define SIZE_WIDTH	32
#endif

/*
 * wchar_t is 32 bits and equals Rune; see the note in <stddef.h>. This
 * said 16 while <wchar.h> said WCHAR_MAX was Runemax, 0x10FFFF.
 *
 * C99 7.18.3 puts WCHAR_MIN and WCHAR_MAX in this header as well as in
 * <wchar.h>, and gnulib reads them from here. Spelled numerically because
 * Runemax comes from <utf.h>, which this header does not pull in; the
 * guards let the two headers agree in either include order.
 */
#define WCHAR_WIDTH	32
#ifndef WCHAR_MIN
#define WCHAR_MIN	0
#endif
#ifndef WCHAR_MAX
#define WCHAR_MAX	0x10FFFF
#endif
#define WINT_WIDTH	32
#define SIG_ATOMIC_WIDTH	32

#endif
