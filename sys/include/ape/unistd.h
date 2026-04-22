#ifndef	__UNISTD_H
#define	__UNISTD_H

#include <sys/types.h>

#pragma lib "/$M/lib/ape/libap.a"

#define _POSIX_VERSION	199309L
#define _POSIX_ASYNC_IO -1
#define _POSIX_CHOWN_RESTRICTED 1
#define _POSIX_NO_TRUNC 1
#define _POSIX_PRIO_IO -1
#define _POSIX_SYNC_IO -1
#define _POSIX_VDISABLE -1

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;
#endif
#ifndef _SSIZE_T
#define _SSIZE_T
typedef long ssize_t;
#endif
#ifndef NULL
#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif
#endif

/* access */
#define	R_OK		4
#define	W_OK		2
#define	X_OK		1
#define	F_OK		0	/* test for existence */

/* lockf */
#define	F_ULOCK		0	/* unlock a previously locked region */
#define	F_LOCK		1	/* lock a region for exclusive use */
#define	F_TLOCK		2	/* test and lock a region for exclusive use */
#define	F_TEST		3	/* test a region for a previous lock */

/* lseek */
#ifndef SEEK_SET		/* also defined in stdio.h */
#define	SEEK_SET	0
#define	SEEK_CUR	1
#define	SEEK_END	2
#endif

/* sysconf argument */
#define	_SC_ARG_MAX		1	/* max chars in args to exec */
#define	_SC_CHILD_MAX		2	/* max child process per process */
#define	_SC_CLK_TCK		3	/* number of clock() units per second */
#define	_SC_NGROUPS_MAX		4	/* max supplementary groups per process */
#define	_SC_OPEN_MAX		5
#define _SC_STREAM_MAX		6
#define _SC_TZNAME_MAX		7
#define	_SC_JOB_CONTROL		8	/* posix job control */
#define	_SC_SAVED_IDS		9	/* saved suid/sgid per process */
#define	_SC_VERSION		10	/* this version */
#define _SC_LOGIN_NAME_MAX	11	/* max length of a login name */
#define _SC_PAGESIZE		12

/* pathconf argument */
#define _PC_LINK_MAX		1
#define _PC_MAX_CANON		2
#define _PC_MAX_INPUT		3
#define _PC_NAME_MAX		4
#define _PC_PATH_MAX		5
#define _PC_PIPE_BUF		6
#define _PC_CHOWN_RESTRICTED	7
#define _PC_NO_TRUNC		8
#define _PC_VDISABLE		9

/* standard filenos */
#define STDIN_FILENO		0
#define STDOUT_FILENO		1
#define STDERR_FILENO		2

#ifdef __cplusplus
extern "C" {
#endif

/* process primitives */
extern int execl(const char *, const char *, ...);
extern int execv(const char *, const char **);
extern int execle(const char *, const char *, const char *,  ...);
extern int execve(const char *, const char **, const char **);
extern int execlp(const char *, const char *, ...);
extern int execvp(const char *, const char **);
extern void _exit(int);
extern unsigned int alarm(unsigned int);
extern int pause(void);
extern unsigned int sleep(unsigned int);
extern pid_t fork(void);

/* process environment */
extern char *getlogin(void);
extern char *cuserid(char *);
extern char *ttyname(int);
extern int isatty(int);
extern long sysconf(int);
extern pid_t getpid(void);
extern pid_t getppid(void);
extern uid_t getuid(void);
extern uid_t geteuid(void);
extern gid_t getgid(void);
extern gid_t getegid(void);
extern int setuid(uid_t);
extern int setgid(gid_t);
extern int getgroups(int, gid_t *);
extern pid_t getpgrp(void);
extern int getpgid(pid_t);
extern int setpgid(pid_t, pid_t);
extern pid_t setsid(void);

/* files and directories */
extern int fsync(int);
extern int chdir(const char *);
extern int chroot(const char *);
extern int link(const char *, const char *);
extern char *getcwd(char *, size_t);
extern int unlink(const char *);
extern int rmdir(const char *);
extern int rename(const char *, const char *);
extern int access(const char *, int);
extern long pathconf(const char *, int);
extern long fpathconf(int, int);
extern int fchdir(int);
extern int chown(const char *, uid_t, gid_t);
#define lchown chown


/* input and output primitives */
extern int pipe(int *);
extern int dup(int);
extern int dup2(int, int);
extern int close(int);
extern ssize_t read(int, void *, size_t);
extern ssize_t write(int, const void *, size_t);
extern int ftruncate(int, off_t);
extern off_t lseek(int, off_t, int);

extern ssize_t pread(int, void *, size_t, off_t);
extern ssize_t pwrite(int, const void *, size_t, off_t);

/* device- and class-specific functions */
extern pid_t tcgetpgrp(int);
extern int tcsetpgrp(int, pid_t);

extern char *getlogin_r(char *, int);

/* berkeley specific functions */
#include <bsd.h>

extern int getpagesize(void);
extern int gethostname(char *, size_t);

/* musl */
extern int truncate(const char *, off_t);
extern int getdtablesize(void);

extern unsigned ualarm(unsigned, unsigned);

/* AT functions (require dirfd support): */
int openat(int dirfd, const char *path, int flags, ...); /* unistd/at_functions.c */
int fstatat(int dirfd, const char *path, struct stat *buf, int flags);
int unlinkat(int dirfd, const char *path, int flags);
int mkdirat(int dirfd, const char *path, mode_t mode);
int renameat(int olddirfd, const char *old, int newdirfd, const char *new);
int readlinkat(int dirfd, const char *path, char *buf, size_t n);
int symlinkat(const char *target, int dirfd, const char *linkpath);
int faccessat(int dirfd, const char *path, int mode, int flags);
int fchownat(int dirfd, const char *path, uid_t uid, gid_t gid, int flags);
int fchmodat(int dirfd, const char *path, mode_t mode, int flags);
int linkat(int old_dfd, const char *old, int new_dfd, const char *new, int flags);

/* GNU extensions */
extern int pipe2(int [2], int);
extern int dup3(int, int, int);
extern int execvpe(const char *, char *const [], char *const []);

/* stubs and hacks */
# include <sys/stat.h> /* readlink, mkdir, mkfifo */
# include <sys/uio.h> /* readv writev */
extern int symlink(const char *, const char *);
extern int usleep(unsigned int);
extern size_t confstr(int, char *, size_t);
extern char **environ;

#ifdef __cplusplus
}
#endif


#endif
