#ifndef _TGMATH_H
#define _TGMATH_H
#pragma lib "/$M/lib/ape/libap.a"

/*
 * <tgmath.h> — C11 §7.25 type-generic math
 *
 * Uses _Generic (kencc APExp extension) to dispatch to the correct
 * function variant based on argument type.
 *
 * Dispatch order:
 *   float _Complex      → c<fn>f
 *   double _Complex     → c<fn>
 *   long double _Complex→ c<fn>l
 *   float               → <fn>f
 *   long double         → <fn>l
 *   (default/double)    → <fn>
 *
 * NOTE: helper macro parameters use 'fn' (not 'f') to avoid token-paste
 * collision: f##f with param name 'f' would give "acosacos", not "acosf".
 * With param name 'fn': fn##f gives "acosf" as intended.
 */

#include <math.h>
#include <complex.h>

/* 6-way dispatch: real (f/d/l) + complex (cf/cd/cl) — 1 argument */
#define __TG_CPLX1(fn, x) _Generic((x),			\
	float _Complex:       c##fn##f,				\
	double _Complex:      c##fn,				\
	long double _Complex: c##fn##l,				\
	float:                fn##f,				\
	long double:          fn##l,				\
	default:              fn)(x)

/* 6-way dispatch — 2 arguments, type selected from first */
#define __TG_CPLX2(fn, x, y) _Generic((x),			\
	float _Complex:       c##fn##f,				\
	double _Complex:      c##fn,				\
	long double _Complex: c##fn##l,				\
	float:                fn##f,				\
	long double:          fn##l,				\
	default:              fn)((x),(y))

/* 3-way real dispatch — 1 argument */
#define __TG_REAL1(fn, x) _Generic((x),			\
	float:       fn##f,					\
	long double: fn##l,					\
	default:     fn)(x)

/* 3-way real dispatch — 2 arguments */
#define __TG_REAL2(fn, x, y) _Generic((x),			\
	float:       fn##f,					\
	long double: fn##l,					\
	default:     fn)((x),(y))

/* 3-way real dispatch — 3 arguments */
#define __TG_REAL3(fn, x, y, z) _Generic((x),			\
	float:       fn##f,					\
	long double: fn##l,					\
	default:     fn)((x),(y),(z))

/* ------------------------------------------------------------------ */
/* Trigonometric                                                        */
/* ------------------------------------------------------------------ */
#define acos(x)		__TG_CPLX1(acos, x)
#define asin(x)		__TG_CPLX1(asin, x)
#define atan(x)		__TG_CPLX1(atan, x)
#define atan2(y, x)	__TG_REAL2(atan2, y, x)
#define cos(x)		__TG_CPLX1(cos, x)
#define sin(x)		__TG_CPLX1(sin, x)
#define tan(x)		__TG_CPLX1(tan, x)

/* ------------------------------------------------------------------ */
/* Hyperbolic                                                           */
/* ------------------------------------------------------------------ */
#define acosh(x)	__TG_CPLX1(acosh, x)
#define asinh(x)	__TG_CPLX1(asinh, x)
#define atanh(x)	__TG_CPLX1(atanh, x)
#define cosh(x)		__TG_CPLX1(cosh, x)
#define sinh(x)		__TG_CPLX1(sinh, x)
#define tanh(x)		__TG_CPLX1(tanh, x)

/* ------------------------------------------------------------------ */
/* Exponential and logarithmic                                          */
/* ------------------------------------------------------------------ */
#define exp(x)		__TG_CPLX1(exp, x)
#define exp2(x)		__TG_REAL1(exp2, x)
#define expm1(x)	__TG_REAL1(expm1, x)
#define log(x)		__TG_CPLX1(log, x)
#define log10(x)	__TG_REAL1(log10, x)
#define log1p(x)	__TG_REAL1(log1p, x)
#define log2(x)		__TG_REAL1(log2, x)
#define logb(x)		__TG_REAL1(logb, x)

/* ------------------------------------------------------------------ */
/* Power and absolute-value                                             */
/* ------------------------------------------------------------------ */
#define pow(x, y)	__TG_CPLX2(pow, x, y)
#define sqrt(x)		__TG_CPLX1(sqrt, x)
#define cbrt(x)		__TG_REAL1(cbrt, x)
#define hypot(x, y)	__TG_REAL2(hypot, x, y)

/*
 * fabs: for complex arguments, C11 says fabs(z) = cabs(z).
 * Needs explicit complex associations since cabs/cabsf/cabsl
 * don't follow the c##fn naming pattern.
 */
#define fabs(x)		_Generic((x),				\
	float _Complex:       cabsf,				\
	double _Complex:      cabs,				\
	long double _Complex: cabsl,				\
	float:                fabsf,				\
	long double:          fabsl,				\
	default:              fabs)(x)

/* ------------------------------------------------------------------ */
/* Error and gamma                                                      */
/* ------------------------------------------------------------------ */
#define erf(x)		__TG_REAL1(erf, x)
#define erfc(x)		__TG_REAL1(erfc, x)
#define lgamma(x)	__TG_REAL1(lgamma, x)
#define tgamma(x)	__TG_REAL1(tgamma, x)

/* ------------------------------------------------------------------ */
/* Nearest integer                                                      */
/* ------------------------------------------------------------------ */
#define ceil(x)		__TG_REAL1(ceil, x)
#define floor(x)	__TG_REAL1(floor, x)
#define nearbyint(x)	__TG_REAL1(nearbyint, x)
#define rint(x)		__TG_REAL1(rint, x)
#define lrint(x)	__TG_REAL1(lrint, x)
#define llrint(x)	__TG_REAL1(llrint, x)
#define round(x)	__TG_REAL1(round, x)
#define lround(x)	__TG_REAL1(lround, x)
#define llround(x)	__TG_REAL1(llround, x)
#define trunc(x)	__TG_REAL1(trunc, x)

/* ------------------------------------------------------------------ */
/* Remainder                                                            */
/* ------------------------------------------------------------------ */
#define fmod(x, y)	__TG_REAL2(fmod, x, y)
#define remainder(x, y)	__TG_REAL2(remainder, x, y)
#define remquo(x, y, p)	__TG_REAL3(remquo, x, y, p)

/* ------------------------------------------------------------------ */
/* Manipulation                                                         */
/* ------------------------------------------------------------------ */
#define copysign(x, y)	__TG_REAL2(copysign, x, y)
#define nextafter(x, y)	__TG_REAL2(nextafter, x, y)
/*
 * nexttoward: second arg is always long double per C11 §7.12.11.4.
 * Only the first arg determines dispatch.
 */
#define nexttoward(x, y) _Generic((x),				\
	float:       nexttowardf,				\
	long double: nexttowardl,				\
	default:     nexttoward)((x),(long double)(y))

/* ------------------------------------------------------------------ */
/* Maximum, minimum, positive difference, and multiply-add             */
/* ------------------------------------------------------------------ */
#define fdim(x, y)	__TG_REAL2(fdim, x, y)
#define fmax(x, y)	__TG_REAL2(fmax, x, y)
#define fmin(x, y)	__TG_REAL2(fmin, x, y)
#define fma(x, y, z)	__TG_REAL3(fma, x, y, z)

/* ------------------------------------------------------------------ */
/* Scaling and decomposition                                            */
/* ------------------------------------------------------------------ */
#define scalbn(x, n)	__TG_REAL2(scalbn, x, n)
#define scalbln(x, n)	__TG_REAL2(scalbln, x, n)
#define ilogb(x)	__TG_REAL1(ilogb, x)
#define ldexp(x, n)	__TG_REAL2(ldexp, x, n)
#define frexp(x, p)	__TG_REAL2(frexp, x, p)
#define modf(x, p)	__TG_REAL2(modf, x, p)

/* ------------------------------------------------------------------ */
/* Complex-only (no real counterpart per C11 §7.25)                    */
/* ------------------------------------------------------------------ */
#define carg(x)		_Generic((x),				\
	float _Complex:       cargf,				\
	long double _Complex: cargl,				\
	default:              carg)(x)

#define conj(x)		_Generic((x),				\
	float _Complex:       conjf,				\
	long double _Complex: conjl,				\
	default:              conj)(x)

#define cproj(x)	_Generic((x),				\
	float _Complex:       cprojf,				\
	long double _Complex: cprojl,				\
	default:              cproj)(x)

/*
 * cimag and creal are already macros in <complex.h>; redefine them
 * here as type-generic versions per C11.
 */
#undef cimag
#define cimag(x)	_Generic((x),				\
	float _Complex:       cimagf,				\
	long double _Complex: cimagl,				\
	default:              cimag)(x)

#undef creal
#define creal(x)	_Generic((x),				\
	float _Complex:       crealf,				\
	long double _Complex: creall,				\
	default:              creal)(x)

#endif /* _TGMATH_H */
