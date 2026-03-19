/*
 * plan9_cmplx.c
 *
 * __plan9_cmplx / __plan9_cmplxf: construct a complex value from
 * real and imaginary parts.
 *
 * These are called by the CMPLX() / CMPLXF() / CMPLXL() macros defined
 * in <complex.h>.  We use the pointer-cast trick to write the two
 * components directly into the complex auto, avoiding compound literals
 * and designated initialisers which the Plan 9 compiler does not support.
 *
 * Add this file to the musl libm build (e.g. in src/math/).
 */
#include <complex.h>

double complex
__plan9_cmplx(double re, double im)
{
	double complex z;
	*(double*)&z = re;
	*((double*)&z+1) = im;
	return z;
}

float complex
__plan9_cmplxf(float re, float im)
{
	float complex z;
	*(float*)&z = re;
	*((float*)&z+1) = im;
	return z;
}
