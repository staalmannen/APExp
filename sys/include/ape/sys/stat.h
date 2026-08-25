#ifndef __STAT_H
#define __STAT_H

#include <sys/types.h>
#include <time.h>

#pragma lib "/$M/lib/ape/libap.a"

/*
 * stat structure, used by stat(2) and fstat(2)
 */
struct	stat {
	dev_t	st_dev;
	ino_t	st_ino;
	mode_t 	st_mode;
	nlink_t	st_nlink;
	uid_t 	st_uid;
	gid_t 	st_gid;
	dev_t	st_rdev;
	off_t	st_size;
	struct timespec	st_atim;
	struct timespec	st_mtim;
	struct timespec	st_ctim;
	blksize_t st_blksize;
	blkcnt_t  st_blocks;
};

#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec


#define	S__MASK		     0170000
#define S_ISLNK(m)	(((m)&S__MASK) == 0120000)
#define S_ISSOCK(m)	(((m)&S__MASK) == 0010000)
#define S_ISREG(m)	(((m)&S__MASK) == 0100000)
#define S_ISDIR(m)	(((m)&S__MASK) == 0040000)
#define S_ISCHR(m)	(((m)&S__MASK) == 0020000)
#define S_ISBLK(m)	(((m)&S__MASK) == 0060000)
#define S_ISFIFO(m)	(((m)&S__MASK) == 0010000)

#define	S_ISUID	04000		/* set user id on execution */
#define	S_ISGID	02000		/* set group id on execution */
#define	S_IRWXU	00700		/* read, write, execute: owner */
#define	S_IRUSR	00400		/* read permission: owner */
#define	S_IWUSR	00200		/* write permission: owner */
#define	S_IXUSR	00100		/* execute permission: owner */
#define	S_IRWXG	00070		/* read, write, execute: group */
#define	S_IRGRP	00040		/* read permission: group */
#define	S_IWGRP	00020		/* write permission: group */
#define	S_IXGRP	00010		/* execute permission: group */
#define	S_IRWXO	00007		/* read, write, execute: other */
#define	S_IROTH	00004		/* read permission: other */
#define	S_IWOTH	00002		/* write permission: other */
#define	S_IXOTH	00001		/* execute permission: other */
/*hack*/
#define S_ISVTX S_IWOTH

#define S_TYPEISSHM(st) 0
#define S_TYPEISTMO(st) 0

/*
 * File types Plan 9 does not have. Portable code tests these without
 * guarding them -- gnulib's c-file-type.c walks the whole list in one
 * run of unguarded ifs -- because gnulib's generated <sys/stat.h>
 * defines every one of them, to 0 on a system that lacks the type.
 * That wrapper is pruned here for shadowing this header, so define them
 * as gnulib would; undefined, each call is an implicit function and
 * turns up at link time instead:
 *
 *   compare_files: undefined: c_file_type in compare_files
 *
 * Each is guarded, so a port that grows a real one of these only has to
 * define it before including this header.
 */
#ifndef S_ISDOOR		/* Solaris 2.5 and up */
#define S_ISDOOR(m) 0
#endif
#ifndef S_ISCTG			/* contiguous file */
#define S_ISCTG(m) 0
#endif
#ifndef S_ISMPB			/* V7 multiplexed block special */
#define S_ISMPB(m) 0
#endif
#ifndef S_ISMPC			/* V7 multiplexed character special */
#define S_ISMPC(m) 0
#endif
#ifndef S_ISMPX			/* AIX */
#define S_ISMPX(m) 0
#endif
#ifndef S_ISNAM			/* Xenix */
#define S_ISNAM(m) 0
#endif
#ifndef S_ISNWK			/* HP-UX network special */
#define S_ISNWK(m) 0
#endif
#ifndef S_ISPORT		/* Solaris 10 and up */
#define S_ISPORT(m) 0
#endif
#ifndef S_ISWHT			/* BSD whiteout */
#define S_ISWHT(m) 0
#endif
#ifndef S_ISOFD			/* Cray migrated, offline with data */
#define S_ISOFD(m) 0
#endif
#ifndef S_ISOFL			/* Cray migrated, offline without data */
#define S_ISOFL(m) 0
#endif
#ifndef S_TYPEISMQ		/* takes a struct stat *, not a mode */
#define S_TYPEISMQ(st) 0
#endif
#ifndef S_TYPEISSEM
#define S_TYPEISSEM(st) 0
#endif

#define S_IFMT S__MASK
#define S_IFDIR 0040000
#define S_IFCHR 0020000
#define S_IFBLK 0060000
#define S_IFREG 0100000
#define S_IFIFO 0010000
#define S_IFLNK 0120000
#define S_IFSOCK S_IFIFO

#ifdef __cplusplus
extern "C" {
#endif

extern mode_t umask(mode_t);
extern int mkdir(const char *, mode_t);
extern int mkfifo(const char *, mode_t);
extern int mknod(const char *, mode_t, dev_t);
extern int stat(const char *, struct stat *);
extern int fstat(int, struct stat *);
extern int chmod(const char *, mode_t);
/* stubs */
extern int fchown (int fd, uid_t uid, gid_t gid);
extern int fchmod (int fd, mode_t mode);

extern int	lstat(char *, struct stat *);
extern int	symlink(const char *, const char *);
extern ssize_t readlink(const char *, char*, size_t);

/* POSIX.1-2008 timestamp functions */
#define UTIME_NOW  ((long)(1l << 30) - 1l)
#define UTIME_OMIT ((long)(1l << 30) - 2l)

extern int futimens(int, const struct timespec [2]);
extern int utimensat(int, const char *, const struct timespec [2], int);
extern int mknodat(int, const char *, mode_t, dev_t);

#ifdef __cplusplus
}
#endif

#endif
