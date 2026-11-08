#include <math.h>

/* taken from musl */

float
hypotf(float x, float y)
{
	union {float f; u32int i;} ux = {x}, uy = {y}, ut;
	float z;
	union {
		float f;
		u32int x;
	}oneP[] = {
		{.x = 0x6c800000},
		{.x = 0x12800000},
	};

	ux.i &= -1U>>1;
	uy.i &= -1U>>1;
	if (ux.i < uy.i) {
		ut = ux;
		ux = uy;
		uy = ut;
	}

	x = ux.f;
	y = uy.f;
	if (uy.i == 0xff<<23)
		return y;
	if (ux.i >= 0xff<<23 || uy.i == 0 || ux.i - uy.i >= 25<<23)
		return x + y;

	z = 1;
	if (ux.i >= (0x7f+60)<<23) {
		z = oneP[0].f;
		x *= oneP[1].f;
		y *= oneP[1].f;
	} else if (uy.i < (0x7f-60)<<23) {
		z = oneP[1].f;
		x *= oneP[0].f;
		y *= oneP[0].f;
	}
	return z*sqrtf((double)x*x + (double)y*y);
}
