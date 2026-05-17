#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int
setreuid(uid_t ruid, uid_t euid)
{
	(void)ruid; (void)euid;
	errno = EPERM;
	return -1;
}
