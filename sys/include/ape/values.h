#ifndef _APEXP_VALUES_H_
#define _APEXP_VALUES_H_

/*
 * <values.h> -- the SVR4/BSD legacy limits header, which this tree
 * wanted in fourteen places and did not have.
 *
 * It is NOT in any standard: POSIX and C both spell these
 * <limits.h> and <float.h>. It survives because a great deal of
 * pre-standard C and C++ includes it, and three files here use its
 * macros rather than merely naming the header:
 *
 *	external/perl/pp_sys.c                 MAXINT
 *	external/p2c/src/trans.h               MAXINT, MAXLONG
 *	external/perl/.../Devel-PPPort/limits  MAXINT, MAXLONG, MAXSHORT
 *
 * and `external/cfront-C4/lib/new/_arr_map.cpp' -- which is in
 * cmd/c++lib's OFILES -- includes it and uses NOTHING from it, so
 * the whole file failed to preprocess over a vestigial line.
 *
 * EVERY VALUE IS DERIVED, NOT TRANSCRIBED, and that is deliberate.
 * kencc's `long' is 32-bit while the host's is 64, and this tree has
 * already spent three rounds on constants that existed twice and
 * disagreed (PATH_MAX, NAME_MAX, NGROUPS_MAX/PIPE_BUF). A literal
 * here would be a fourth. Defining each name in terms of <limits.h>
 * and <float.h> makes that impossible by construction: there is one
 * definition, and it is somewhere else.
 *
 * The three marked (*) are the ones anything in this tree actually
 * reads. The rest are the historical header's full set, so that a
 * program including it finds what it expects rather than failing one
 * macro at a time.
 */

#include <limits.h>
#include <float.h>

/* bit counts */
#define BITSPERBYTE	CHAR_BIT
#define CHARBITS	((int)(sizeof(char) * CHAR_BIT))
#define SHORTBITS	((int)(sizeof(short) * CHAR_BIT))
#define INTBITS		((int)(sizeof(int) * CHAR_BIT))
#define LONGBITS	((int)(sizeof(long) * CHAR_BIT))
#define PTRBITS		((int)(sizeof(char *) * CHAR_BIT))

/* most negative value of each signed type, i.e. the sign bit alone */
#define HIBITS		SHRT_MIN
#define HIBITI		INT_MIN
#define HIBITL		LONG_MIN

/* largest value of each signed integer type */
#define MAXSHORT	SHRT_MAX	/* (*) */
#define MAXINT		INT_MAX		/* (*) */
#define MAXLONG		LONG_MAX	/* (*) */

/* floating point range */
#define MAXFLOAT	FLT_MAX
#define MAXDOUBLE	DBL_MAX
#define MINFLOAT	FLT_MIN
#define MINDOUBLE	DBL_MIN

/* significand width, in bits */
#define FSIGNIF		FLT_MANT_DIG
#define DSIGNIF		DBL_MANT_DIG

#endif /* _APEXP_VALUES_H_ */
