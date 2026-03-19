#ifndef _COMPLEX_IMPL_H
#define _COMPLEX_IMPL_H

#include <complex.h>
#include "libm.h"

/*
 * Plan9/9front port: replace the union compound-literal form of __CMPLX
 * (which uses designated initialisers not supported by the Plan9 compiler)
 * with calls to the __builtin_cmplx helpers defined in <complex.h>.
 */
#undef __CMPLX
#undef CMPLX
#undef CMPLXF
#undef CMPLXL

#define CMPLX(x, y)  __builtin_cmplx((double)(x), (double)(y))
#define CMPLXF(x, y) __builtin_cmplxf((float)(x), (float)(y))
#define CMPLXL(x, y) __builtin_cmplx((double)(x), (double)(y))

double complex __ldexp_cexp(double complex,int);
float complex __ldexp_cexpf(float complex,int);

#endif
