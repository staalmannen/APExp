#include "../include/lib.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

/*
 * POSIX.1-2008 *at() family for APExp
 *
 * Plan9 has no openat()-style relative-fd operations. We implement
 * the common case: when dirfd == AT_FDCWD, the call is equivalent
 * to the non-at version and we delegate directly.
 *
 * When dirfd is a real fd and path is relative, we would need to
 * reconstruct the path via _FD2PATH and concatenation. For now
 * these cases return ENOSYS — they are rarely needed by ported
 * software that isn't explicitly using the *at interface.
 *
 * AT_FDCWD coverage is sufficient to satisfy configure probes and
 * the most common usage patterns.
 */

#ifndef AT_FDCWD
#define AT_FDCWD (-100)
#endif
#ifndef AT_SYMLINK_NOFOLLOW
#define AT_SYMLINK_NOFOLLOW 0x100
#endif
#ifndef AT_REMOVEDIR
#define AT_REMOVEDIR 0x200
#endif
#ifndef AT_EACCESS
#define AT_EACCESS 0x200
#endif

int
openat(int dirfd, const char *path, int flags, ...)
{
	if(dirfd == AT_FDCWD || (path != NULL && path[0] == '/'))
		return open(path, flags);
	errno = ENOSYS;
	return -1;
}

int
fstatat(int dirfd, const char *path, struct stat *st, int flags)
{
	(void)flags; /* AT_SYMLINK_NOFOLLOW: Plan9 has no symlinks anyway */
	if(dirfd == AT_FDCWD || (path != NULL && path[0] == '/'))
		return stat(path, st);
	errno = ENOSYS;
	return -1;
}

int
unlinkat(int dirfd, const char *path, int flags)
{
	if(dirfd == AT_FDCWD || (path != NULL && path[0] == '/')){
		if(flags & AT_REMOVEDIR)
			return rmdir(path);
		return unlink(path);
	}
	errno = ENOSYS;
	return -1;
}

int
mkdirat(int dirfd, const char *path, mode_t mode)
{
	if(dirfd == AT_FDCWD || (path != NULL && path[0] == '/'))
		return mkdir(path, mode);
	errno = ENOSYS;
	return -1;
}

int
renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath)
{
	if((olddirfd == AT_FDCWD || (oldpath != NULL && oldpath[0] == '/')) &&
	   (newdirfd == AT_FDCWD || (newpath != NULL && newpath[0] == '/')))
		return rename(oldpath, newpath);
	errno = ENOSYS;
	return -1;
}

int
faccessat(int dirfd, const char *path, int mode, int flags)
{
	(void)flags;
	if(dirfd == AT_FDCWD || (path != NULL && path[0] == '/'))
		return access(path, mode);
	errno = ENOSYS;
	return -1;
}

int
fchownat(int dirfd, const char *path, uid_t owner, gid_t group, int flags)
{
	(void)flags;
	if(dirfd == AT_FDCWD || (path != NULL && path[0] == '/'))
		return chown(path, owner, group);
	errno = ENOSYS;
	return -1;
}

int
fchmodat(int dirfd, const char *path, mode_t mode, int flags)
{
	(void)flags;
	if(dirfd == AT_FDCWD || (path != NULL && path[0] == '/'))
		return chmod(path, mode);
	errno = ENOSYS;
	return -1;
}

int
linkat(int olddirfd, const char *oldpath, int newdirfd,
       const char *newpath, int flags)
{
	(void)flags;
	if((olddirfd == AT_FDCWD || (oldpath != NULL && oldpath[0] == '/')) &&
	   (newdirfd == AT_FDCWD || (newpath != NULL && newpath[0] == '/')))
		return link(oldpath, newpath);
	errno = ENOSYS;
	return -1;
}

int
readlinkat(int dirfd, const char *path, char *buf, size_t bufsiz)
{
	/* Plan9 has no symlinks */
	(void)dirfd; (void)path; (void)buf; (void)bufsiz;
	errno = EINVAL;
	return -1;
}

int
symlinkat(const char *target, int dirfd, const char *linkpath)
{
	/* Plan9 has no symlinks */
	(void)target; (void)dirfd; (void)linkpath;
	errno = ENOSYS;
	return -1;
}
