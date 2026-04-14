#include	<sys/types.h>
#include	<sys/stat.h>
#include	<errno.h>

int
mknod(char *, mode_t, dev_t)
{
#pragma ref path
#pragma ref mode
	errno = 0;
	return -1;
}
