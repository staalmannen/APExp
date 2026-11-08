#include <math.h>
#include "_npe.h"

int
isnormal(double d)
{
	return d == 0 || isNaN(d) || isInf(d, 0);
}
