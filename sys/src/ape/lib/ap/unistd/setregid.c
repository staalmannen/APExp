#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int
setregid(gid_t rgid, gid_t egid)
{
	(void)rgid; (void)egid;
	errno = EPERM;
	return -1;
}
