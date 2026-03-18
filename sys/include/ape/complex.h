/*
 * C99 <complex.h> for Plan9/9front.
 * The _Complex keyword is built into the compiler (6c, 8c, 5c, etc.)
 */
#pragma lib "m"

#define	complex		_Complex
#define	imaginary	_Imaginary

typedef _Complex float	float_complex;
typedef _Complex double	double_complex;

/*
 * Component access.
 * _Complex values are stored in memory as contiguous {re, im} pairs.
 */
#define	creal(z)	(*(double*)&(z))
#define	crealf(z)	(*(float*)&(z))
#define	cimag(z)	(*((double*)&(z)+1))
#define	cimagf(z)	(*((float*)&(z)+1))

/*
 * The imaginary unit: 0 + 1i
 * Usage:   double complex z = 3.0 + 4.0*I;
 */
#define	_Complex_I	((_Complex double){0.0, 1.0})
#define	I		_Complex_I

/* libm prototypes */
extern double		cabs(double_complex);
extern float		cabsf(float_complex);
extern double		carg(double_complex);
extern double_complex	conj(double_complex);
extern double_complex	cproj(double_complex);
extern double_complex	csqrt(double_complex);
extern double_complex	cexp(double_complex);
extern double_complex	clog(double_complex);
extern double_complex	cpow(double_complex, double_complex);
extern double_complex	csin(double_complex);
extern double_complex	ccos(double_complex);
extern double_complex	ctan(double_complex);
extern double_complex	casin(double_complex);
extern double_complex	cacos(double_complex);
extern double_complex	catan(double_complex);
extern double_complex	csinh(double_complex);
extern double_complex	ccosh(double_complex);
extern double_complex	ctanh(double_complex);
