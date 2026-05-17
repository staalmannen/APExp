#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int
seteuid(uid_t euid)
{
	(void)euid;
	errno = EPERM;
	return -1;
}
