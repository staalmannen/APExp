#ifndef ALLTYPES_H
#define ALLTYPES_H

#include <machine/endian.h>

#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <bsd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <regex.h>
#include <wchar.h>
#include <pthread.h>
#include <langinfo.h>

typedef long register_t;
typedef uint64_t u_int64_t;

/*
 * suseconds_t, blksize_t, blkcnt_t, fsblkcnt_t, fsfilcnt_t, id_t, key_t
 * and useconds_t were all defined here. They are POSIX <sys/types.h>
 * types and are now defined there, and reach this file through the
 * include above.
 *
 * This file is not a header anyone includes by name, so a type that
 * lives only here cannot be found by portable code that spells it:
 *
 *   timediff.c:52 syntax error, last name: tv_usec
 *
 * from curl's "tv->tv_usec = (suseconds_t)tv_usec;". An unknown type
 * name turns the cast into a syntax error, which is why the complaint
 * names the operand rather than the type.
 *
 * blksize_t and blkcnt_t were defined in both places; the two spellings
 * agreed (int64_t is long long here), so it went unnoticed.
 */

typedef va_list __isoc_va_list;

#ifndef __struct_winsize_defined
#define __struct_winsize_defined
struct winsize { unsigned short ws_row, ws_col, ws_xpixel, ws_ypixel; };
#endif

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[12*sizeof(int)/sizeof(void*)]; } __u; } cnd_t;

#ifdef _BITS64
typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;
#else
typedef struct { union { int __i[6]; volatile int __vi[6]; volatile void *volatile __p[6]; } __u; } mtx_t;
#endif

#endif /* ALLTYPES_H */



