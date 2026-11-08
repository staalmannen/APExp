#include <math.h>
/* taken from musl */

#define _sign(d) (*((u64int*)d) & (1ULL<<63))

double
fmax(double x, double y)
{
	if(isNaN(x))
		return y;
	if(isNaN(y))
		return x;
	if(_sign(&x) != _sign(&y))
		return _sign(&x) ? y : x;
	return x < y ? y : x;
}
