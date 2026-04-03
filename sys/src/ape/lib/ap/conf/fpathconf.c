#include	<unistd.h>
#include	<limits.h>
#include	<errno.h>
#include	<sys/limits.h>

long
fpathconf(int, int name)
{
	return pathconf(0, name);
}


