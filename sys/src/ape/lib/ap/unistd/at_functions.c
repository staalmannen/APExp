#include "../include/lib.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/limits.h>
#include <errno.h>
#include "sys9.h"

/*
 * POSIX.1-2008 *at() family for APExp.
 *
 * Plan 9 has no relative-to-a-descriptor operations, so a real dirfd is
 * turned back into a path with fd2path(2) and the two are joined.  This
 * is not atomic the way openat(2) is -- the directory can be renamed
 * between the fd2path and the operation -- but it is the behaviour
 * callers expect, and the alternative was ENOSYS.
 *
 * That alternative is what used to be here: anything but AT_FDCWD (or an
 * absolute path, where dirfd is ignored anyway) failed with ENOSYS.  It
 * was fine while nothing passed a real descriptor, and coreutils passes
 * them everywhere -- cp opens its destination directory once and does
 * the whole copy through openat/fstatat/unlinkat on that fd.
 *
 * dirfd is not checked for being a directory: if it is not, fd2path
 * gives the file's own path, the join produces something that does not
 * exist, and the call fails with ENOENT where POSIX asks for ENOTDIR.
 * Wrong errno, right outcome, one syscall cheaper on a path that fts
 * walks for every entry.
 *
 * AT_SYMLINK_NOFOLLOW and AT_SYMLINK_FOLLOW are accepted and, except in
 * fstatat, ignored: libap has no symlinks yet (lstat is "return stat",
 * and nothing sets S_IFLNK).  fstatat routes through lstat regardless,
 * so it starts behaving the day that changes.
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

/*
 * Join dirfd and path into buf.  Returns 0, or -1 with errno set.
 * A leading '#' is Plan 9's device root and is as absolute as '/'.
 */
static int
atpath(int dirfd, const char *path, char *buf, int nbuf)
{
	int n, plen;

	if(path == NULL){
		errno = EINVAL;
		return -1;
	}
	plen = strlen(path);
	if(dirfd == AT_FDCWD || path[0] == '/' || path[0] == '#'){
		if(plen >= nbuf){
			errno = ENAMETOOLONG;
			return -1;
		}
		memcpy(buf, path, plen+1);
		return 0;
	}
	if(_FD2PATH(dirfd, buf, nbuf) < 0){
		_syserrno();
		return -1;
	}
	n = strlen(buf);
	/* fd2path can return "/" for the root; do not double the slash. */
	if(n > 0 && buf[n-1] == '/')
		n--;
	if(n + 1 + plen + 1 > nbuf){
		errno = ENAMETOOLONG;
		return -1;
	}
	buf[n++] = '/';
	memcpy(buf+n, path, plen+1);
	return 0;
}

int
openat(int dirfd, const char *path, int flags, ...)
{
	char buf[PATH_MAX];
	va_list va;
	int mode;

	if(atpath(dirfd, path, buf, sizeof buf) < 0)
		return -1;
	/* The mode argument was being dropped here, so openat with
	 * O_CREAT created files with whatever was in the register. */
	if(flags & O_CREAT){
		va_start(va, flags);
		mode = va_arg(va, int);
		va_end(va);
		return open(buf, flags, mode);
	}
	return open(buf, flags);
}

int
fstatat(int dirfd, const char *path, struct stat *st, int flags)
{
	char buf[PATH_MAX];

	if(atpath(dirfd, path, buf, sizeof buf) < 0)
		return -1;
	if(flags & AT_SYMLINK_NOFOLLOW)
		return lstat(buf, st);
	return stat(buf, st);
}

int
unlinkat(int dirfd, const char *path, int flags)
{
	char buf[PATH_MAX];

	if(atpath(dirfd, path, buf, sizeof buf) < 0)
		return -1;
	if(flags & AT_REMOVEDIR)
		return rmdir(buf);
	return unlink(buf);
}

int
mkdirat(int dirfd, const char *path, mode_t mode)
{
	char buf[PATH_MAX];

	if(atpath(dirfd, path, buf, sizeof buf) < 0)
		return -1;
	return mkdir(buf, mode);
}

int
renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath)
{
	char obuf[PATH_MAX], nbuf[PATH_MAX];

	if(atpath(olddirfd, oldpath, obuf, sizeof obuf) < 0)
		return -1;
	if(atpath(newdirfd, newpath, nbuf, sizeof nbuf) < 0)
		return -1;
	return rename(obuf, nbuf);
}

int
faccessat(int dirfd, const char *path, int mode, int flags)
{
	char buf[PATH_MAX];

	/* AT_EACCESS: APE has no separate real/effective ids to choose
	 * between, so access() answers both questions the same way. */
	(void)flags;
	if(atpath(dirfd, path, buf, sizeof buf) < 0)
		return -1;
	return access(buf, mode);
}

int
fchownat(int dirfd, const char *path, uid_t owner, gid_t group, int flags)
{
	char buf[PATH_MAX];

	(void)flags;
	if(atpath(dirfd, path, buf, sizeof buf) < 0)
		return -1;
	return chown(buf, owner, group);
}

int
fchmodat(int dirfd, const char *path, mode_t mode, int flags)
{
	char buf[PATH_MAX];

	(void)flags;
	if(atpath(dirfd, path, buf, sizeof buf) < 0)
		return -1;
	return chmod(buf, mode);
}

int
linkat(int olddirfd, const char *oldpath, int newdirfd,
       const char *newpath, int flags)
{
	char obuf[PATH_MAX], nbuf[PATH_MAX];

	(void)flags;
	if(atpath(olddirfd, oldpath, obuf, sizeof obuf) < 0)
		return -1;
	if(atpath(newdirfd, newpath, nbuf, sizeof nbuf) < 0)
		return -1;
	return link(obuf, nbuf);
}

/* POSIX.1-2008 gives readlinkat an ssize_t return, as readlink has.
   This said int, so on amd64 the callee wrote 4 bytes where an ssize_t
   caller read 8. gnulib's careadlinkat takes the function as a
   parameter and typechecks it:

     diff.c:1265 argument prototype mismatch
       "IND FUNC(INT, IND CONST CHAR, IND CHAR, UVLONG) INT" for
       "IND FUNC(INT, IND CONST CHAR, IND CHAR, UVLONG) VLONG" */
ssize_t
readlinkat(int dirfd, const char *path, char *buf, size_t bufsiz)
{
	char pbuf[PATH_MAX];

	if(atpath(dirfd, path, pbuf, sizeof pbuf) < 0)
		return -1;
	return readlink(pbuf, buf, bufsiz);
}

int
symlinkat(const char *target, int dirfd, const char *linkpath)
{
	char buf[PATH_MAX];

	if(atpath(dirfd, linkpath, buf, sizeof buf) < 0)
		return -1;
	return symlink(target, buf);
}

int
mknodat(int dirfd, const char *path, mode_t mode, dev_t dev)
{
	char buf[PATH_MAX];

	if(atpath(dirfd, path, buf, sizeof buf) < 0)
		return -1;
	return mknod(buf, mode, dev);
}
