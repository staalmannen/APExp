#include <math.h>

/* taken from musl */

float ldexpf(float x, int n)
{
	union {float f; u32int i;} u;
	float y = x;
	union {
		float f;
		u32int x;
	}oneP[] = {
		{.x = 0x7f000000},
		{.x = 0x800000},
		{.x = 0x4b800000},
	};

	if (n > 127) {
		y *= oneP[0].f;
		n -= 127;
		if (n > 127) {
			y *= oneP[0].f;
			n -= 127;
			if (n > 127)
				n = 127;
		}
	} else if (n < -126) {
		y *= oneP[1].f * oneP[2].f;
		n += 126 - 24;
		if (n < -126) {
			y *= oneP[1].f * oneP[2].f;
			n += 126 - 24;
			if (n < -126)
				n = -126;
		}
	}
	u.i = (u32int)(0x7f+n)<<23;
	x = y * u.f;
	return x;
}
