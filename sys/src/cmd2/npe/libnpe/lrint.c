#include <math.h>

long
lrint(double d)
{
	long long l;

	*((double*)&l) = d + 6755399441055744.0;

	return l;
}
