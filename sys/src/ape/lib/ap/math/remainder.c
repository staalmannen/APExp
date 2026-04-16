#include <math.h>

double remainder(double x, double y)
{
	int q;
	return remquo(x, y, &q);
}

double drem(double x, double y)
{
	int q;
	return remquo(x, y, &q);
}


