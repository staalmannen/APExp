#ifndef __MATH
#define __MATH
#pragma lib "/$M/lib/ape/libap.a"

/* a HUGE_VAL appropriate for IEEE double-precision */
/* the correct value, 1.797693134862316e+308, causes a ken overflow */
#define HUGE_VAL 1.79769313486231e+308

#define INFINITY HUGE_VAL

#define double_t double
#define float_t float

#ifdef __cplusplus
extern "C" {
#endif

extern double acos(double);
extern double asin(double);
extern double atan(double);
extern double atan2(double, double);
extern double cos(double);
extern double hypot(double, double);
extern double sin(double);
extern double tan(double);
extern double cosh(double);
extern double sinh(double);
extern double tanh(double);
extern double exp(double);
extern double frexp(double, int *);
extern double ldexp(double, int);
extern double log(double);
extern double log2(double);
extern double log10(double);
extern double modf(double, double *);
extern double pow(double, double);
extern double sqrt(double);
extern double ceil(double);
extern double fabs(double);
extern double floor(double);
extern double fmod(double, double);
extern double NaN(void);
extern int isNaN(double);
extern double Inf(int);
extern int isInf(double, int);
extern double fmin(double, double);

#if defined(_RESEARCH_SOURCE) || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
/* does >> treat left operand as unsigned ? */
#define Unsigned_Shifts 1
#define	M_E		2.7182818284590452354	/* e */
#define	M_LOG2E		1.4426950408889634074	/* log 2e */
#define	M_LOG10E	0.43429448190325182765	/* log 10e */
#define	M_LN2		0.69314718055994530942	/* log e2 */
#define	M_LN10		2.30258509299404568402	/* log e10 */
#define	M_PI		3.14159265358979323846	/* pi */
#define	M_PI_2		1.57079632679489661923	/* pi/2 */
#define	M_PI_4		0.78539816339744830962	/* pi/4 */
#define	M_1_PI		0.31830988618379067154	/* 1/pi */
#define	M_2_PI		0.63661977236758134308	/* 2/pi */
#define	M_2_SQRTPI	1.12837916709551257390	/* 2/sqrt(pi) */
#define	M_SQRT2		1.41421356237309504880	/* sqrt(2) */
#define	M_SQRT1_2	0.70710678118654752440	/* 1/sqrt(2) */

extern double hypot(double, double);
extern double erf(double);
extern double erfc(double);
extern double j0(double);
extern double y0(double);
extern double j1(double);
extern double y1(double);
extern double jn(int, double);
extern double yn(int, double);

#endif


#ifdef __cplusplus
}
#endif

#define isnan(x) isNaN(x)
#define isinf(x) isInf(x, 0)

/* gnulib compatibility hacks */
#define isnanl(x) isnan(x)
#define isnand(x) isnan(x)
#define isnanf(x) isnan(x)

/* functions imported from musl math */

#define FP_ILOGBNAN (-1-0x7fffffff)
#define FP_ILOGB0 FP_ILOGBNAN

#define FP_NAN       0
#define FP_INFINITE  1
#define FP_ZERO      2
#define FP_SUBNORMAL 3
#define FP_NORMAL    4

int __fpclassify(double);
int __fpclassifyf(float);
int __fpclassifyl(long double);

static unsigned __FLOAT_BITS(float __f)
{
	union {float __f; unsigned __i;} __u;
	__u.__f = __f;
	return __u.__i;
}

static unsigned long long __DOUBLE_BITS(double __f)
{
	union {double __f; unsigned long long __i;} __u;
	__u.__f = __f;
	return __u.__i;
}

#define fpclassify(x) ( \
	sizeof(x) == sizeof(float) ? __fpclassifyf(x) : \
	sizeof(x) == sizeof(double) ? __fpclassify(x) : \
	__fpclassifyl(x) )

int __signbit(double);
int __signbitf(float);
int __signbitl(long double);


#define signbit(x) ( \
	sizeof(x) == sizeof(float) ? (int)(__FLOAT_BITS(x)>>31) : \
	sizeof(x) == sizeof(double) ? (int)(__DOUBLE_BITS(x)>>63) : \
	__signbitl(x) )

float       	acosf(float);
long double 	acosl(long double);

double      	acosh(double);
float       	acoshf(float);
long double 	acoshl(long double);

float       	asinf(float);
long double 	asinl(long double);

double      	asinh(double);
float       	asinhf(float);
long double 	asinhl(long double);

double      	atanh(double);
float       	atanhf(float);
long double 	atanhl(long double);

double      	cbrt(double);
float       	cbrtf(float);
long double 	cbrtl(long double);

double 			copysign(double, double);
float       	copysignf(float, float);
long double 	copysignl(long double, long double);

float       	cosf(float);
long double 	cosl(long double);

double      	cosh(double);
float       	coshf(float);
long double 	coshl(long double);

double      	drem(double, double);
float       	dremf(float, float);

float       	erff(float);
long double 	erfl(long double);

double      	erfc(double);
float       	erfcf(float);
long double 	erfcl(long double);

double      	exp10(double);
float       	exp10f(float);
long double 	exp10l(long double);

float       	expf(float);
long double 	expl(long double);

double      	exp2(double);
float       	exp2f(float);
long double 	exp2l(long double);

double      	expm1(double);
float       	expm1f(float);
long double 	expm1l(long double);

float       	fabsf(float);
long double 	fabsl(long double);

double      	fdim(double, double);
float       	fdimf(float, float);
long double 	fdiml(long double, long double);

float       floorf(float);
long double floorl(long double);

double      	fma(double, double, double);
float       	fmaf(float, float, float);
long double 	fmal(long double, long double, long double);

double      	fmax(double, double);
float       	fmaxf(float, float);
long double 	fmaxl(long double, long double);

float       	fminf(float, float);
long double 	fminl(long double, long double);

float       	fmodf(float, float);
long double 	fmodl(long double, long double);

int 			finite(double);
int 			finitef(float);

double 			frexp(double, int *);
float 			frexpf(float, int *);
long double 	frexpl(long double, int *);

float       	hypotf(float, float);
long double 	hypotl(long double, long double);

int         	ilogb(double);
int         	ilogbf(float);
int         	ilogbl(long double);

double      	ldexp(double, int);
float       	ldexpf(float, int);
long double 	ldexpl(long double, int);

double      	lgamma(double);
float       	lgammaf(float);
long double 	lgammal(long double);

double      	lgamma_r(double, int*);
float       	lgammaf_r(float, int*);

long long   	llrint(double);
long long   	llrintf(float);
long long   	llrintl(long double);

long long   	llround(double);
long long   	llroundf(float);
long long   	llroundl(long double);

float       	logf(float);
long double 	logl(long double);

float       	log10f(float);
long double 	log10l(long double);

float       	log2f(float);
long double 	log2l(long double);

double      	logb(double);
float       	logbf(float);
long double 	logbl(long double);

long        	lrint(double);
long        	lrintf(float);
long        	lrintl(long double);

long        	lround(double);
long        	lroundf(float);
long        	lroundl(long double);

double      	log1p(double);
float       	log1pf(float);
long double 	log1pl(long double);

float 			modff(float, float *);
long double 	modfl(long double, long double *);

double      	nan(const char *);
float       	nanf(const char *);
long double 	nanl(const char *);

double      	nearbyint(double);
float       	nearbyintf(float);
long double 	nearbyintl(long double);

double      	nextafter(double, double);
float       	nextafterf(float, float);
long double 	nextafterl(long double, long double);

double      	nexttoward(double, long double);
float       	nexttowardf(float, long double);
long double 	nexttowardl(long double, long double);

float       	powf(float, float);
long double 	powl(long double, long double);

double      	pow10(double);
float       	pow10f(float);
long double 	pow10l(long double);

double      	remainder(double, double);
float       	remainderf(float, float);
long double 	remainderl(long double, long double);

double      	remquo(double, double, int *);
float       	remquof(float, float, int *);
long double 	remquol(long double, long double, int *);

double      	rint(double);
float       	rintf(float);
long double 	rintl(long double);

double      	round(double);
float       	roundf(float);
long double 	roundl(long double);

double 			scalbln(double, long);
float 			scalblnf(float, long);
long double 	scalblnl(long double, long);

double 			scalbn(double, int);
float 			scalbnf(float, int);
long double 	scalbnl(long double, int);

void        	sincos(double, double*, double*);
void        	sincosf(float, float*, float*);
void        	sincosl(long double, long double*, long double*);

float       	sinf(float);
long double 	sinl(long double);

double      	sinh(double);
float       	sinhf(float);
long double 	sinhl(long double);

double      	significand(double);
float       	significandf(float);

double      	sqrt(double);
float       	sqrtf(float);
long double 	sqrtl(long double);

float       	tanf(float);
long double 	tanl(long double);

float       	tanhf(float);
long double 	tanhl(long double);

double      	tgamma(double);
float       	tgammaf(float);
long double 	tgammal(long double);

double      	trunc(double);
float       	truncf(float);
long double 	truncl(long double);

#define isfinite(x) ( \
	sizeof(x) == sizeof(float) ? (__FLOAT_BITS(x) & 0x7fffffff) < 0x7f800000 : \
	sizeof(x) == sizeof(double) ? (__DOUBLE_BITS(x) & -1ULL>>1) < 0x7ffULL<<52 : \
	__fpclassifyl(x) > FP_INFINITE)

extern int signgam;

double      y0(double);
double      y1(double);
double      yn(int, double);

float       j0f(float);
float       j1f(float);
float       jnf(int, float);

float       y0f(float);
float       y1f(float);
float       ynf(int, float);

#endif /* __MATH */
