#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int
setgroups(int n, const gid_t *gidset)
{
	(void)n; (void)gidset;
	errno = EPERM;
	return -1;
}
