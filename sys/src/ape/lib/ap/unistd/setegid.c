#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int
setegid(gid_t egid)
{
	(void)egid;
	errno = EPERM;
	return -1;
}
