#include <math.h>

/* taken from musl */

double
trunc(double x)
{
	union {double f; u64int i;} u = {x};
	int e = (int)(u.i >> 52 & 0x7ff) - 0x3ff + 12;
	u64int m;

	if(e >= 52 + 12)
		return x;
	if(e < 12)
		e = 1;
	m = -1ULL >> e;
	if((u.i & m) == 0)
		return x;
	u.i &= ~m;

	return u.f;
}
