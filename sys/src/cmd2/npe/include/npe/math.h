#ifndef _npe_math_h_
#define _npe_math_h_

#include <npe.h>

#define M_PI 3.14159265358979323846
#define HUGE_VAL 1.79769313486231e+308

float npe_infinity(void);
#define INFINITY (npe_infinity())

float npe_nan(void);
#define NAN (npe_nan())

#define isnan isNaN

#define acosf acos
#define asinf asin
#define atan2f atan2
#define atanf atan
#define cosf cos
#define sinf sin
#define tanf tan

#define ceilf ceil
#define expf exp
#define fabsf fabs
#define floorf floor
#define fmodf fmod
#define logf log
#define log10f log10
#define powf pow
#define sqrtf sqrt

double exp2(double);
#define exp2f exp2

double log2(double);
float log2f(float);

double round(double);
#define roundf round

double trunc(double);
#define truncf trunc

int lrintf(float f);
long lrint(double d);

int isinf(double d);
int isnormal(double d);

#define isfinite(x) (!isinf(x))
/* FIXME this is totally wrong */
#define signbit(x) (x == -0.0 || x < 0.0)

double acosh(double x);
double log1p(double x);
double fmax(double x, double y);
float ldexpf(float x, int n);
float hypotf(float x, float y);
float cbrtf(float x);

#endif
