#ifndef _FLOAT_EXT_H
#define _FLOAT_EXT_H

/*
 * C99 and C11 additions to <float.h>.
 *
 * They live in their own arch-independent header because they are the
 * same on every target kencc has: every arch float header defines
 * LDBL_MANT_DIG as DBL_MANT_DIG, so long double is double throughout,
 * and the FLT and DBL values are IEEE 754 binary32 and binary64
 * everywhere. An architecture that ever grows a wider long double can
 * define its own first; each name below is guarded.
 *
 * Included from every <float.h> in the tree -- the per-architecture ones
 * as well as the generic one. pcc passes -I/$objtype/include/ape before
 * -I/sys/include/ape (pcc.c:234), and stock 9front APE keeps its float.h
 * in the architecture directory, so <float.h> resolves there first and a
 * generic header alone would never be read.
 *
 * gnulib's dtimespec-bound.h is what asked, for sleep, tail and timeout:
 *
 *   dtimespec-bound.h:61 name not declared: DBL_TRUE_MIN
 *
 * TRUE_MIN is the smallest positive subnormal, where MIN is the smallest
 * positive normal. Plan 9 amd64 does support subnormals -- main9.s sets
 * MXCSR to 0x1f80, which leaves both FTZ (bit 15) and DAZ (bit 6) clear
 * -- so HAS_SUBNORM is 1 rather than 0 or -1. Note that _RESEARCH_SOURCE
 * still sets Sudden_Underflow for the old dtoa, which is a separate and
 * older assumption.
 */

/* Spelled as hex floats: these are subnormal, and a decimal literal
   would have to be rounded into the subnormal range by the compiler's
   own strtod, where 0x1p-1074 is just an exponent. Decimal equivalents
   are 1.40129846e-45 and 4.9406564584124654e-324. */
#ifndef FLT_TRUE_MIN
#define FLT_TRUE_MIN	0x1p-149F	/* 2**-149 */
#endif
#ifndef DBL_TRUE_MIN
#define DBL_TRUE_MIN	0x1p-1074	/* 2**-1074 */
#endif
#ifndef LDBL_TRUE_MIN
#define LDBL_TRUE_MIN	DBL_TRUE_MIN
#endif

#ifndef FLT_HAS_SUBNORM
#define FLT_HAS_SUBNORM		1
#endif
#ifndef DBL_HAS_SUBNORM
#define DBL_HAS_SUBNORM		1
#endif
#ifndef LDBL_HAS_SUBNORM
#define LDBL_HAS_SUBNORM	1
#endif

/* Digits needed to round-trip through decimal and back. */
#ifndef FLT_DECIMAL_DIG
#define FLT_DECIMAL_DIG		9
#endif
#ifndef DBL_DECIMAL_DIG
#define DBL_DECIMAL_DIG		17
#endif
#ifndef LDBL_DECIMAL_DIG
#define LDBL_DECIMAL_DIG	DBL_DECIMAL_DIG
#endif
#ifndef DECIMAL_DIG
#define DECIMAL_DIG		LDBL_DECIMAL_DIG
#endif

/* 0: all operations and constants are evaluated in their own type.
   That is what kencc does, having no wider intermediate format. */
#ifndef FLT_EVAL_METHOD
#define FLT_EVAL_METHOD		0
#endif

#endif /* _FLOAT_EXT_H */
