#include <unistd.h>
#include "_npe.h"

void
usleep(useconds_t us)
{
	npe_nsleep((uvlong)us*1000ULL);
}
