#ifndef _COMPLEX_H
#define _COMPLEX_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Plan9/9front port of C99 <complex.h>.
 * _Complex is a built-in keyword in the Plan9 compiler (6c, 8c, 5c).
 * We avoid compound literals, designated initialisers, and imaginary
 * literal suffixes (1.0fi) which the Plan9 compiler does not support.
 */

#define complex		_Complex
#define imaginary	_Imaginary

/*
 * Component access via pointer cast to the underlying pair layout.
 * _Complex T is stored as two consecutive T values: {re, im}.
 */
#define creal(z)	(*(double*)&(z))
#define crealf(z)	(*(float*)&(z))
#define creall(z)	((long double)creal(z))
#define cimag(z)	(*((double*)&(z)+1))
#define cimagf(z)	(*((float*)&(z)+1))
#define cimagl(z)	((long double)cimag(z))

/*
 * CMPLX: construct a complex value from real and imaginary parts.
 * Implemented as library functions to avoid compound literals.
 * See plan9_cmplx.c in the musl math library.
 */
extern double complex	__plan9_cmplx(double, double);
extern float complex	__plan9_cmplxf(float, float);

#define CMPLX(x, y)	__plan9_cmplx((double)(x), (double)(y))
#define CMPLXF(x, y)	__plan9_cmplxf((float)(x), (float)(y))
#define CMPLXL(x, y)	__plan9_cmplx((double)(x), (double)(y))

#define _Complex_I	__plan9_cmplx(0.0, 1.0)
#define I		_Complex_I

double complex cacos(double complex);
float complex cacosf(float complex);
long double complex cacosl(long double complex);

double complex casin(double complex);
float complex casinf(float complex);
long double complex casinl(long double complex);

double complex catan(double complex);
float complex catanf(float complex);
long double complex catanl(long double complex);

double complex ccos(double complex);
float complex ccosf(float complex);
long double complex ccosl(long double complex);

double complex csin(double complex);
float complex csinf(float complex);
long double complex csinl(long double complex);

double complex ctan(double complex);
float complex ctanf(float complex);
long double complex ctanl(long double complex);

double complex cacosh(double complex);
float complex cacoshf(float complex);
long double complex cacoshl(long double complex);

double complex casinh(double complex);
float complex casinhf(float complex);
long double complex casinhl(long double complex);

double complex catanh(double complex);
float complex catanhf(float complex);
long double complex catanhl(long double complex);

double complex ccosh(double complex);
float complex ccoshf(float complex);
long double complex ccoshl(long double complex);

double complex csinh(double complex);
float complex csinhf(float complex);
long double complex csinhl(long double complex);

double complex ctanh(double complex);
float complex ctanhf(float complex);
long double complex ctanhl(long double complex);

double complex cexp(double complex);
float complex cexpf(float complex);
long double complex cexpl(long double complex);

double complex clog(double complex);
float complex clogf(float complex);
long double complex clogl(long double complex);

double cabs(double complex);
float cabsf(float complex);
long double cabsl(long double complex);

double complex cpow(double complex, double complex);
float complex cpowf(float complex, float complex);
long double complex cpowl(long double complex, long double complex);

double complex csqrt(double complex);
float complex csqrtf(float complex);
long double complex csqrtl(long double complex);

double carg(double complex);
float cargf(float complex);
long double cargl(long double complex);

double complex conj(double complex);
float complex conjf(float complex);
long double complex conjl(long double complex);

double complex cproj(double complex);
float complex cprojf(float complex);
long double complex cprojl(long double complex);

#ifdef __cplusplus
}
#endif
#endif
