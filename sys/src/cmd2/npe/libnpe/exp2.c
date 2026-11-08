#include <math.h>
#include "_npe.h"

double
exp2(double x)
{
	static double ln2c = 0.0;
	if(ln2c == 0.0)
		ln2c = log(2.0);
	return exp(x*ln2c);
}
