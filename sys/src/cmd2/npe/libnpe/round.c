#include <math.h>

/* taken from musl */

#define dbleps 2.2204460492503131e-16

static double toint = 1.0/dbleps;

double
round(double x)
{
	union {double f; u64int i;} u = {x};
	int e = u.i >> 52 & 0x7ff;
	double y;

	if(e >= 0x3ff+52)
		return x;
	if(u.i >> 63)
		x = -x;
	if(e < 0x3ff-1)
		return 0*u.f;
	y = x + toint - toint - x;
	if(y > 0.5)
		y = y + x - 1;
	else if(y <= -0.5)
		y = y + x + 1;
	else
		y = y + x;
	if(u.i >> 63)
		y = -y;

	return y;
}
