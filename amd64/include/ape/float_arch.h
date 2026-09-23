#ifndef __FLOAT
#define __FLOAT
/* IEEE, default rounding */

#define FLT_ROUNDS	1
#define FLT_RADIX	2

#define FLT_DIG		6
#define FLT_EPSILON	1.19209290e-07
#define FLT_MANT_DIG	24
#define FLT_MAX		3.40282347e+38
#define FLT_MAX_10_EXP	38
#define FLT_MAX_EXP	128
#define FLT_MIN		1.17549435e-38
#define FLT_MIN_10_EXP	-37
#define FLT_MIN_EXP	-125

#define DBL_DIG		15
#define DBL_EPSILON	2.2204460492503131e-16
#define DBL_MANT_DIG	53
#define DBL_MAX		1.797693134862315708145e+308
#define DBL_MAX_10_EXP	308
#define DBL_MAX_EXP	1024
#define DBL_MIN		2.225073858507201383090233e-308
#define DBL_MIN_10_EXP	-307
#define DBL_MIN_EXP	-1021
#define LDBL_MANT_DIG	DBL_MANT_DIG
#define LDBL_EPSILON	DBL_EPSILON
#define LDBL_DIG	DBL_DIG
#define LDBL_MIN_EXP	DBL_MIN_EXP
#define LDBL_MIN	DBL_MIN
#define LDBL_MIN_10_EXP	DBL_MIN_10_EXP
#define LDBL_MAX_EXP	DBL_MAX_EXP
#define LDBL_MAX	DBL_MAX
#define LDBL_MAX_10_EXP	DBL_MAX_10_EXP

typedef 	union FPdbleword FPdbleword;
union FPdbleword
{
	double	x;
	struct {	/* little endian */
		long lo;
		long hi;
	};
};

#ifdef _RESEARCH_SOURCE
/* define stuff needed for floating conversion */
#define IEEE_8087	1
/*
 * Sudden_Underflow is NOT defined, and used to be. It tells Gay's
 * conversion code that this machine FLUSHES denormals to zero, and
 * amd64 under APExp does not: fesetenv(FE_DFL_ENV) loads MXCSR 0x1f80
 * (arch/amd64/fenv.s) -- all exceptions masked, round to nearest, and
 * bit 15 FTZ and bit 6 DAZ both CLEAR. Underflow here is gradual.
 *
 * It matters because `_d2b' has two arms. Under Sudden_Underflow it
 * reports `*bits = P - k' for everything and has no denormal case at
 * all, so strtod's correction loop was being told that subnormal
 * inputs have 53 significand bits -- and _dtoa was printing them the
 * same way. The gradual arm is the one strtod-xcheck, strtof-xcheck
 * and dtoa-xcheck all measure on the build host, where no
 * float_arch.h is in sight and the macro was never defined.
 *
 * The claim is stock APE's, inherited from a Plan 9 that did flush.
 * SEVEN OTHER ARCHITECTURES still carry it, and none of them has been
 * checked: this is a statement about one machine's FP environment, so
 * it is a probe, not a library rule, and only the machine that was
 * looked at is changed.
 */
#endif
#ifdef _PLAN9_SOURCE
/* MXCSR */
/* fcr */
#define	FPFTZ	(1<<15)	/* amd64 */
#define	FPINEX	(1<<12)
#define	FPUNFL	(1<<11)
#define	FPOVFL	(1<<10)
#define	FPZDIV	(1<<9)
#define	FPDNRM	(1<<8)	/* amd64 */
#define	FPINVAL	(1<<7)
#define	FPDAZ	(1<<6)	/* amd64 */
#define	FPRNR	(0<<13)
#define	FPRZ	(3<<13)
#define	FPRPINF	(2<<13)
#define	FPRNINF	(1<<13)
#define	FPRMASK	(3<<13)
#define	FPPEXT	0
#define	FPPSGL	0
#define	FPPDBL	0
#define	FPPMASK	0
/* fsr */
#define	FPAINEX	(1<<5)
#define	FPAUNFL	(1<<4)
#define	FPAOVFL	(1<<3)
#define	FPAZDIV	(1<<2)
#define	FPADNRM	(1<<1)	/* not in plan 9 */
#define	FPAINVAL	(1<<0)
#endif
#endif /* __FLOAT */
