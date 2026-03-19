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
 * CMPLX: construct a complex value from real and imaginary parts.
 *
 * We cannot use compound literals here (designated initialisers are
 * not supported).  Instead we write to the two halves of the value
 * via a hidden auto, using the component-access pointer trick.
 * This expands to a comma-expression that is valid in any expression
 * context including return statements.
 *
 * The __cmplx_tmp variable is declared inside the macro expansion;
 * each use gets its own unique scope via a statement-expression-like
 * trick using the fact that our creal/cimag macros work on lvalues.
 */
#define __CMPLX(x, y, t) \
	( creal( *(_Complex t*)&( (_Complex t){ (t)(x), (t)(y) } ) ) , \
	  *(_Complex t*)&( (_Complex t){ (t)(x), (t)(y) } ) )

/* Simpler form that works without compound literals or designated inits:
 * construct via real assignment. Since _Complex T z = re + im*I requires I,
 * and I requires _Complex_I, define them in terms of each other carefully. */

/*
 * __CMPLXD / __CMPLXF: implemented as inline functions to avoid
 * compound literal issues. Declared here; the compiler sees them as
 * ordinary function calls which return a complex value by hidden pointer.
 */
static inline double_complex __builtin_cmplx(double re, double im)
{
	double_complex z;
	*(double*)&z = re;
	*((double*)&z+1) = im;
	return z;
}
static inline float_complex __builtin_cmplxf(float re, float im)
{
	float_complex z;
	*(float*)&z = re;
	*((float*)&z+1) = im;
	return z;
}

#define CMPLX(x,y)	__builtin_cmplx((double)(x), (double)(y))
#define CMPLXF(x,y)	__builtin_cmplxf((float)(x), (float)(y))
#define CMPLXL(x,y)	__builtin_cmplx((double)(x), (double)(y))

/*
 * _Complex_I: the imaginary unit 0+1i, built via the same helper.
 * Must be defined AFTER __builtin_cmplx.
 */
#define	_Complex_I	__builtin_cmplx(0.0, 1.0)
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
