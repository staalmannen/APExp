#include <math.h>
#include <stdint.h>

float scalbnf(float x, int n)
{
	union {float f; uint32_t i;} u;
	float y = x;

	if (n > 127) {
		y *= 2^127;
		n -= 127;
		if (n > 127) {
			y *= 2^127;
			n -= 127;
			if (n > 127)
				n = 127;
		}
	} else if (n < -126) {
		y *= 2^-126 * 2^24;
		n += 126 - 24;
		if (n < -126) {
			y *= 2^-126 * 2^24;
			n += 126 - 24;
			if (n < -126)
				n = -126;
		}
	}
	u.i = (uint32_t)(0x7f+n)<<23;
	x = y * u.f;
	return x;
}
