#ifndef __FCNTL_H
#define __FCNTL_H

#pragma lib "/$M/lib/ape/libap.a"

#include	<sys/types.h>

#define	O_RDONLY 0
#define	O_WRONLY 1
#define	O_RDWR	 2
#define O_ACCMODE	0x003
#define O_NONBLOCK	0x004
#define O_APPEND	0x008
#define O_CREAT		0x100
#define O_TRUNC		0x200
#define O_EXCL		0x400
#define O_NOCTTY	0x800
#define O_DSYNC		0x1000
#define	O_RSYNC		0x2000
#define O_SYNC		0x4000
#define O_CLOEXEC	02000000
#define O_NOFOLLOW 0

#define	F_DUPFD		0	/* Duplicate fildes */
#define	F_GETFD		1	/* Get fildes flags */
#define	F_SETFD		2	/* Set fildes flags */
#define	F_GETFL		3	/* Get file flags */
#define	F_SETFL		4	/* Set file flags */
#define	F_GETLK		5	/* Get file lock */
#define	F_SETLK		6	/* Set file lock */
#define	F_SETLKW	7	/* Set file lock and wait */

#define FD_CLOEXEC	1

struct flock {
	short	l_type;
	short	l_whence;
	off_t	l_start;
	off_t	l_len;
	pid_t	l_pid;
};

#define F_RDLCK		1	/* shared or read lock */
#define F_UNLCK		2	/* unlock */
#define F_WRLCK		3	/* exclusive or write lock */

#ifdef __cplusplus
extern "C" {
#endif

extern int fcntl(int, int, ...);
extern int open(const char *, int, ...);
extern int creat(const char *, mode_t);

/* POSIX extensions / portability */
#define O_SEARCH	O_RDONLY	/* open dir for search; no-op on Plan 9 */
#define O_BINARY	0		/* no CRLF translation (Windows); no-op */
#define O_TEXT		0		/* CRLF translation (Windows); no-op */
#define O_DIRECTORY	0		/* fail if not dir (Linux); no-op on Plan 9 */

/* F_DUPFD_CLOEXEC: dup fd to >= arg and set FD_CLOEXEC on result */
#define F_DUPFD_CLOEXEC	8

/* *at() family constants */
#define AT_FDCWD		-100	/* use cwd for relative paths (POSIX) */
#define AT_SYMLINK_NOFOLLOW	0x100
#define AT_SYMLINK_FOLLOW	0x400
#define AT_EACCESS		0x200	/* faccessat: use effective uid/gid */
#define AT_REMOVEDIR		0x200	/* unlinkat: remove directory */

#ifdef __cplusplus
}
#endif

#endif
