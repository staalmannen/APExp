#include <math.h>

int
lrintf(float f)
{
	int i;

	*((float*)&i) = f + 12582912.0f;

	return (i & 0x7fffff) - 0x400000;
}
