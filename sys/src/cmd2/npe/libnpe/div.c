#include <stdlib.h>

div_t
div(int n, int d)
{
	return (div_t){n/d, n%d};
}
