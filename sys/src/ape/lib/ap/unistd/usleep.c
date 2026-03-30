#include "../include/lib.h"
#include <unistd.h>
#include <time.h>
#include "../include/sys9.h"

int
usleep(unsigned int usec)
{
	int ms;

	/* round up to milliseconds - Plan9 _SLEEP granularity */
	ms = ((long)usec + 999) / 1000;
	if(_SLEEP(ms) < 0)
		return -1;
	return 0;
}
