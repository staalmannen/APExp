#include <math.h>
#include "_npe.h"

int
isinf(double d)
{
	if(isInf(d, 0) == 0)
		return 0;

	return isInf(d, -1) ? -1 : 1;
}
