#ifndef __LIMITS
#define __LIMITS

/* _BITS64, for SSIZE_MAX below. Guarded and macro-only. */
#include <_apetypes.h>
/* 8 bit chars (signed), 16 bit shorts, 32 bit ints/longs */

#define CHAR_BIT	8
#ifndef MB_LEN_MAX
#define MB_LEN_MAX	4
#endif

#ifndef UCHAR_MAX
#define UCHAR_MAX	0xff
#endif

#define USHRT_MAX	0xffff
#define UINT_MAX	0xffffffffU
#define ULONG_MAX	0xffffffffUL
#define ULLONG_MAX	0xffffffffffffffffULL

#define CHAR_WIDTH	8
#define SCHAR_WIDTH	8
#define UCHAR_WIDTH	8
#define SHRT_WIDTH	16
#define USHRT_WIDTH	16
#define INT_WIDTH	32
#define UINT_WIDTH	32
#define LONG_WIDTH	32
#define ULONG_WIDTH	32
#define LLONG_WIDTH	64
#define ULLONG_WIDTH	64

#ifndef CHAR_MAX
#define CHAR_MAX	SCHAR_MAX
#endif
#define SCHAR_MAX	0x7f
#define SHRT_MAX	0x7fff
#define INT_MAX		0x7fffffff
#define LONG_MAX	0x7fffffffL
#define LLONG_MAX	0x7fffffffffffffffLL

#define CHAR_MIN	SCHAR_MIN
#define SCHAR_MIN	(-SCHAR_MAX-1)
#define SHRT_MIN	(-SHRT_MAX-1)
#define INT_MIN		(-INT_MAX-1)
#define LONG_MIN	(-LONG_MAX-1)
#define LLONG_MIN	(-LLONG_MAX-1)

#define _POSIX_AIO_LISTIO_MAX	2
#define _POSIX_AIO_MAX			1
#define _POSIX_ARG_MAX			4096
#define _POSIX_CHILD_MAX		6
#define	_POSIX_CLOCKRES_MIN		20000000
#define	_POSIX_DELAYTIMER_MAX	32
#define _POSIX_LINK_MAX			8
#define _POSIX_MAX_CANON		255
#define _POSIX_MAX_INPUT		255
#define _POSIX_MQ_OPEN_MAX		8
#define	_POSIX_MQ_PRIO_MAX		32
#define _POSIX_NAME_MAX			14
#define _POSIX_NGROUPS_MAX		0
#define _POSIX_OPEN_MAX			16
#define _POSIX_PATH_MAX			255
#define _POSIX_PIPE_BUF			512
#define	_POSIX_RTSIG_MAX		8
#define	_POSIX_SEM_NSEMS_MAX	256
#define	_POSIX_SEM_VALUE_MAX	32767
#define	_POSIX_SIGQUEUE_MAX		32
#define _POSIX_SSIZE_MAX		SSIZE_MAX
#define _POSIX_STREAM_MAX		8
#define	_POSIX_TIMER_MAX		32
#define _POSIX_TZNAME_MAX		3

/* pedagogy: those that standard allows omitting are commented out */
/*#define AIO_LIST_MAX _POSIX_AIO_LIST_MAX */
/*#define AIO_MAX _POSIX_AIO_MAX */
/*#define AIO_PRIO_DELTA_MAX 0 */
/*#define ARG_MAX _POSIX_ARG_MAX */
/*#define CHILD_MAX _POSIX_CHILD_MAX */
/*#define DELAYTIMER_MAX _POSIX_DELAYTIMER_MAX */
/*#define LINK_MAX _POSIX_LINK_MAX */
/*#define MAX_CANON _POSIX_MAX_CANON */
/*#define MAX_INPUT _POSIX_MAX_INPUT */
/*#define MQ_OPEN_MAX _POSIX_MQ_OPEN_MAX */
/*#define MQ_PRIO_MAX _POSIX_MQ_PRIO_MAX */
/*
 * NAME_MAX AND PATH_MAX ARE THIS SYSTEM'S LIMITS, NOT THE STANDARD'S
 * MINIMA. `_POSIX_NAME_MAX` (14) and `_POSIX_PATH_MAX` (255) are what
 * POSIX guarantees every implementation supports *at least*; defining
 * the real names as those numbers claims this system can do no better,
 * and it can.
 *
 * 14 was already contradicted inside these headers: `<dirent.h>` sets
 * `MAXNAMLEN` to 255 and `struct dirent` is `char d_name[MAXNAMLEN+1]`,
 * so libap has always returned names far longer than `NAME_MAX` said
 * were possible.
 *
 * 255 for a path is worse, because it is a wall rather than a wrong
 * number. `realpath()` is musl's and declares `char stack[PATH_MAX+1]`
 * and `char output[PATH_MAX]`, refusing anything longer; Tcl's
 * `TclpObjNormalizePath` and its directory walker each declare
 * `char buf[MAXPATHLEN]`. Tcl's `fCmd.test` builds a tree about fifty
 * levels deep -- roughly 550 characters -- and could then neither
 * normalise nor traverse nor delete it, which aborted `unixFCmd.test`
 * and `winFCmd.test` outright with `invalid operation`, hjfs's way of
 * saying a directory still has something in it.
 *
 * Plan 9 has no inherent path limit: 9P walks one element at a time and
 * the protocol never carries a whole path. 4096 is Linux's value, which
 * is what portable code is tested against. It costs 8 KB of stack in
 * `realpath()`, which is what it costs on Linux too.
 *
 * `_POSIX_NAME_MAX` and `_POSIX_PATH_MAX` keep their standard values
 * above: they are the guarantee, and code does compare against them.
 */
/* 255, spelled out: MAXNAMLEN lives in <dirent.h> and a macro that
 * expanded to it would break every use of NAME_MAX without that
 * header. Keep the two in step by hand. */
#define NAME_MAX 255
#define NGROUPS_MAX 10
/*#define OPEN_MAX _POSIX_OPEN_MAX */
/*#define PAGESIZE 1 */
#define PASS_MAX 64
#define PATH_MAX 4096
#define MAXPATHLEN PATH_MAX
#define PIPE_BUF _POSIX_PIPE_BUF
/*#define RTSIG_MAX _POSIX_RTSIG_MAX */
/*#define SEM_NSEMS_MAX _POSIX_SEM_NSEMS_MAX */
/*#define SEM_VALUE_MAX _POSIX_SEM_VALUE_MAX */
/*#define SIGQUEUE_MAX _POSIX_SIGQUEUE_MAX */
/*
 * ssize_t, not long. These were LONG_MIN and LONG_MAX, which is the
 * same mistake SIZE_MAX had: kencc's long is 32-bit on amd64, while
 * <sys/types.h> and stddef_arch.h have made ssize_t "long long" since
 * the 2026-04 width fix. So SSIZE_MAX described half the type it names.
 *
 * _BITS64 is the signal the rest of the tree uses for this; see the
 * note in <stdint_generic.h>. Spelled out rather than written as
 * LLONG_MAX so that it does not depend on the order these headers are
 * read in.
 */
#ifdef _BITS64
#define SSIZE_MIN (-0x7fffffffffffffffLL - 1)
#define SSIZE_MAX 0x7fffffffffffffffLL
#else
#define SSIZE_MIN LONG_MIN
#define SSIZE_MAX LONG_MAX
#endif
/*#define STREAM_MAX _POSIX_STREAM_MAX */
/*#define TIMER_MAX _POSIX_TIMER_MAX */
#define TZNAME_MAX _POSIX_TZNAME_MAX

/* from musl */
#define CHARCLASS_NAME_MAX 14
#define RE_DUP_MAX 255
#define _POSIX_RE_DUP_MAX       255
#define _POSIX2_RE_DUP_MAX      255
#define _SC_RE_DUP_MAX	44
#define SYMLOOP_MAX 40


/* some things are just too big for pedagogy (X!) */
#include <sys/limits.h>

#endif /* __LIMITS */
