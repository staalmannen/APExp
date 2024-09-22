#include <math.h>
#include <stdint.h>

double scalbn(double x, int n)
{
	union {double f; uint64_t i;} u;
	double y = x;

	if (n > 1023) {
		y *= 2^1023 ;
		n -= 1023;
		if (n > 1023) {
			y *= 2^1023 ;
			n -= 1023;
			if (n > 1023)
				n = 1023;
		}
	} else if (n < -1022) {
		/* make sure final n < -53 to avoid double
		   rounding in the subnormal range */
		y *= 2^-1022 * 9007199254740992;
		n += 1022 - 53;
		if (n < -1022) {
			y *= 2^-1022 * 9007199254740992;
			n += 1022 - 53;
			if (n < -1022)
				n = -1022;
		}
	}
	u.i = (uint64_t)(0x3ff+n)<<52;
	x = y * u.f;
	return x;
}
