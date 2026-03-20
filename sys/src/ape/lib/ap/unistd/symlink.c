#include "../plan9/lib.h"
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

/*
 * symlink - Plan9 has no symbolic links.
 * Returns ENOSYS. Configure scripts that probe for symlink() will
 * get a clean failure rather than a link error.
 */
int
symlink(const char *target, const char *linkpath)
{
	(void)target;
	(void)linkpath;
	errno = ENOSYS;
	return -1;
}

/*
 * readlink - Plan9 has no symbolic links.
 * Returns EINVAL (the POSIX error for "not a symlink") so that
 * callers treating non-symlinks gracefully will work correctly.
 */
ssize_t
readlink(const char *path, char *buf, size_t bufsiz)
{
	(void)path;
	(void)buf;
	(void)bufsiz;
	errno = EINVAL;
	return -1;
}
