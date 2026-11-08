#include <math.h>
#include "_npe.h"

double
log2(double x)
{
	static double ln2c = 0.0;
	if(x == 0)
		return -hugeD;
	if(x < 0 || isNaN(x))
		return NaN();
	if(ln2c == 0.0)
		ln2c = log(2.0);

	return log(x)/ln2c;
}

float
log2f(float x)
{
	if(x == 0)
		return -hugeF;

	return log2(x);
}
