// copied by hand from debsources gnu cpio 2.11 bdfsg

#include <sys/types.h>
#include <errno.h>

int
fchown (int fd, uid_t uid, gid_t gid)
{
	errno = EPERM;
	return -1;
}


