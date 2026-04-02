/* vms/stdint.h - Definitions for assisting GNULIB on OpenVMS

   Copyright (C) 2017-2026 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Written by John Malmberg */

#ifndef VMS_STDINT_H
#define VMS_STDINT_H

#include <vms/inttypes.h>
#include <vms/bitypes.h>

/* Undefine these to compensate for a previous possible hack */
#ifdef intmax_t
#undef intmax_t
#endif
#ifdef uintmax_t
#undef uintmax_t
#endif

#if (__DECC_VERSION <= 70390010)

typedef int int32_t;
typedef unsigned int uint32_t;
typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;

typedef signed short int_least16_t;
typedef unsigned short uint_least16_t;
typedef signed int int_fast16_t;
typedef unsigned int uint_fast16_t;

typedef signed int_least32_t;
typedef unsigned int uint_least32_t;
typedef signed int int_fast32_t;
typedef unsigned int uint_fast32_t;

#ifndef __VAX

#if (__CRTL_VER < 80500000)
 typedef __int64 intmax_t;
 typedef unsigned __int64 uintmax_t;
 typedef __int64 int_least64_t;
 typedef unsigned __int64 uint_least64_t;
 typedef __int64 int_fast64_t;
 typedef unsigned __int64 uint_fast64_t;
 typedef long long int64_t;
 typedef unsigned long long uint64_t;
 typedef signed long long intptr_t;
 typedef unsigned long long uintptr_t;
#endif /* (__CRTL_VER < 80500000) */

#else
 typedef int32_t intmax_t;
 typedef uint32_t uintmax_t;
 typedef signed long intptr_t;
 typedef unsigned long uintptr_t;
#endif /* __VAX */
#endif  /* (__DECC <= 70390010) */

#ifndef INTMAX_C
#define INTMAX_C(x) x ## L
#endif

#ifndef UINTMAX_C
#define UINTMAX_C(x) x ## UL
#endif

#ifndef INTN_C8
#define INTN_C8(x)
#endif

#ifndef UINTN_C8
#define UINTN_C8(x)
#endif

#ifndef __VAX
#ifndef INTN_C64
#define INTN_C64(x)
#endif

#ifndef UINTN_C64
#define UINTN_C64(x) x ## LL
#endif

#ifndef UINTMAX_C
#define UINTMAX_C(x) x ## ULL
#endif
#endif /* __VAX */


#ifndef PTRDIFF_MIN
#define PTRDIFF_MIN __INT32_MIN
#endif

#ifndef PTRDIFF_MAX
#define PTRDIFF_MAX __INT32_MAX
#endif

#ifndef SIG_ATOMIC_MIN
#define SIG_ATOMIC_MIN __INT32_MIN
#endif

#ifndef SIG_ATOMIC_MAX
#define SIG_ATOMIC_MAX __INT32_MAX
#endif

#ifndef SIZE_MAX
#define SIZE_MAX __UINT32_MAX
#endif

#ifndef WINT_MIN
#define WINT_MIN 0
#endif

#ifndef WINT_MAX
#define WINT_MAX __INT32_MAX
#endif

#ifndef INT8_MIN
#define INT8_MIN (-127-1)
#endif

#ifndef INT8_MAX
#define INT8_MAX (127)
#endif

#ifndef UINT8_MAX
#define UINT8_MAX (256)
#endif

#ifndef INT_LEAST8_MIN
#define INT_LEAST8_MIN INT8_MIN
#endif

#ifndef INT_LEAST8_MAX
#define INT_LEAST8_MAX INT8_MAX
#endif

#ifndef INT_LEAST8_UMAX
#define INT_LEAST8_UMAX UINT8_MAX
#endif

#ifndef INT_FAST8_MIN
#define INT_FAST8_MIN UNIT8_MAX
#endif

#ifndef INT16_MIN
#define INT16_MIN (-32767-1)
#endif

#ifndef INT16_MAX
#define INT16_MAX (32767)
#endif

#ifndef UINT16_MAX
#define UINT16_MAX (65535)
#endif

#ifndef INT_LEAST16_MIN
#define INT_LEAST16_MIN INT16_MIN
#endif

#ifndef INT_LEAST16_MAX
#define INT_LEAST16_MAX INT16_MAX
#endif

#ifndef INT_LEAST16_UMAX
#define INT_LEAST16_UMAX UINT16_MAX
#endif

#ifndef INT_FAST16_MAX
#define INT_FAST16_MAX UINT16_MAX
#endif

#ifndef INT32_MIN
#define INT32_MIN (-2147483647-1)
#endif

#ifndef INT32_MAX
#define INT32_MAX (2147483647)
#endif

#ifndef UINT32_MAX
#define UINT32_MAX (4294967295UL)
#endif

#ifndef INT_LEAST32_MIN
#define INT_LEAST32_MIN INT32_MIN
#endif

#ifndef INT_LEAST32_MAX
#define INT_LEAST32_MAX INT32_MAX
#endif

#ifndef INT_LEAST32_UMAX
#define INT_LEAST32_UMAX UINT32_MAX
#endif

#ifndef INT_FAST32_MAX
#define INT_FAST32_MAX UINT32_MAX
#endif

#ifndef __VAX

#ifndef INT64_MIN
#define INT64_MIN (-9223372036854775807LL-1)
#endif

#ifndef INT64_MAX
#define INT64_MAX (9223372036854775807LL)
#endif

#ifndef UINT64_MAX
#define UINT64_MAX (18446744073709551615ULL)
#endif

#ifndef INT_LEAST64_MIN
#define INT_LEAST64_MIN INT64_MIN
#endif

#ifndef INT_LEAST64_MAX
#define INT_LEAST64_MAX INT64_MAX
#endif

#ifndef INT_LEAST64_UMAX
#define INT_LEAST64_UMAX UINT64_MAX
#endif

#ifndef INT_FAST64_MAX
#define INT_FAST64_MAX UINT64_MAX
#endif

#ifndef INT_FAST64_UMAX
#define INT_FAST64_UMAX UNIT64_MAX
#endif

#endif /* __VAX */

#endif /* VMS_STDINT_H */
