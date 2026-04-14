#include "lib.h"
#include <unistd.h>
#include <errno.h>

int
dup(int oldd)
{
	return fcntl(oldd, F_DUPFD, 0);
}


