#include <sys/statvfs.h>
#include <errno.h>

/*
 * statvfs / fstatvfs -- POSIX, and not answerable on Plan 9.
 *
 * A file server is reached through the namespace rather than a mount
 * table, and 9P has no operation that reports block or inode counts for
 * the file system behind a path: stat(2) returns a per-file Dir and
 * nothing more. There is no number to give, so these report that
 * plainly rather than filling the struct with zeros, which a caller
 * would read as "an empty file system".
 *
 * See <sys/statvfs.h> for why the type exists at all when the calls
 * cannot succeed.
 */

int
statvfs(const char *path, struct statvfs *buf)
{
	(void)path;
	(void)buf;
	errno = ENOSYS;
	return -1;
}

int
fstatvfs(int fd, struct statvfs *buf)
{
	(void)fd;
	(void)buf;
	errno = ENOSYS;
	return -1;
}
