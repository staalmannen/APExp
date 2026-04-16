#include <math.h>

float remainderf(float x, float y)
{
	int q;
	return remquof(x, y, &q);
}

float dremf(float x, float y)
{
	int q;
	return remquof(x, y, &q);
}


