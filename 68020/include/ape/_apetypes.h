/*
 * Byte order. The constants are musl's and glibc's. This header is
 * per-architecture and is the thing that knows the answer, so it is
 * defined here rather than guessed in <endian.h>.
 *
 * Six of the eleven architectures carried a version of this that could
 * never fire:
 *
 *   #if !defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN)
 *   #define __BYTE_ORDER __LITTLE_ENDIAN
 *   #endif
 *
 * Nothing anywhere defined __LITTLE_ENDIAN, so the guard was always
 * false. The other five had nothing at all. Either way __BYTE_ORDER
 * stayed undefined, and every "#if __BYTE_ORDER == __LITTLE_ENDIAN" in
 * <endian.h> compared 0 to 0 and took the little-endian arm -- correct
 * here by accident, wrong on every big-endian architecture in the tree.
 * (The big-endian copies had a second bug of their own: the guard said
 * LITTLE and the body said BIG.)
 *
 * It surfaced as a compile error rather than as wrong bytes because
 * coreutils' od.c reads BYTE_ORDER and BIG_ENDIAN as ordinary C values,
 * not only in #if:
 *
 *   od.c:1798 name not declared: __BYTE_ORDER
 *   od.c:1798 name not declared: __BIG_ENDIAN
 */
#ifndef __LITTLE_ENDIAN
#define	__LITTLE_ENDIAN	1234
#endif
#ifndef __BIG_ENDIAN
#define	__BIG_ENDIAN	4321
#endif
#ifndef __PDP_ENDIAN
#define	__PDP_ENDIAN	3412
#endif
#ifndef __BYTE_ORDER
#define	__BYTE_ORDER	__BIG_ENDIAN
#endif

#ifndef LITTLE_ENDIAN
#define	LITTLE_ENDIAN	__LITTLE_ENDIAN
#endif
#ifndef BIG_ENDIAN
#define	BIG_ENDIAN	__BIG_ENDIAN
#endif
#ifndef PDP_ENDIAN
#define	PDP_ENDIAN	__PDP_ENDIAN
#endif
#ifndef BYTE_ORDER
#define	BYTE_ORDER	__BYTE_ORDER
#endif

#ifndef __m68k__
#define __m68k__ 1
#endif
