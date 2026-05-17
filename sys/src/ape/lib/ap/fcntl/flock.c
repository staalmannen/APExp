#include <sys/file.h>
#include <errno.h>

/* Plan9 has no advisory file locking; stub always succeeds */
int
flock(int fd, int op)
{
	(void)fd; (void)op;
	return 0;
}
