#include "libm.h"

int signbitf(float x)
{
	union {
		float f;
		uint32_t i;
	} y = { x };
	return y.i>>31;
}
