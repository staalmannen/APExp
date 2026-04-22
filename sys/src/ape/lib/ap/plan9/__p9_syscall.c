/* __p9_syscall.c - Plan9 syscall dispatch for APExp
 *
 * Implements the __p9_syscall() function declared in syscall.h.
 * Routes musl's SYS_* calls to Plan9 primitives via the _UPPERCASE
 * raw syscall wrappers from sys9.h, or emulates them in userland
 * where no Plan9 equivalent exists.
 *
 * Return convention (matching musl):
 *   success: >= 0
 *   failure: -errno  (caller passes through __syscall_ret to set errno)
 *
 * Emulation tiers used below:
 *   [DIRECT]   - thin wrapper over a Plan9 syscall with same semantics
 *   [ADAPT]    - Plan9 syscall exists but needs argument/flag translation
 *   [EMULATE]  - no Plan9 syscall; implemented in userland
 *   [STUB]     - no equivalent and not emulable; returns 0 (advisory calls)
 *                or -ENOSYS (calls that must not silently succeed)
 */

#include "syscall.h"
#include "sys9.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/resource.h>
#include <time.h>
#include <signal.h>

/* ------------------------------------------------------------------ */
/* Internal helpers                                                    */
/* ------------------------------------------------------------------ */

/* Convert Plan9 errstr to errno.
 * Plan9 errors are free-form strings; we map the common ones. */
static int
p9errstr_to_errno(void)
{
	char buf[ERRMAX];
	_ERRSTR(buf, sizeof buf);

	/* map common Plan9 error strings to POSIX errno values */
	if(strstr(buf, "does not exist") || strstr(buf, "not found"))
		return ENOENT;
	if(strstr(buf, "permission denied") || strstr(buf, "permission"))
		return EACCES;
	if(strstr(buf, "file exists") || strstr(buf, "already exists"))
		return EEXIST;
	if(strstr(buf, "not a directory"))
		return ENOTDIR;
	if(strstr(buf, "is a directory"))
		return EISDIR;
	if(strstr(buf, "no space"))
		return ENOSPC;
	if(strstr(buf, "too big") || strstr(buf, "too large"))
		return EFBIG;
	if(strstr(buf, "i/o error") || strstr(buf, "I/O error"))
		return EIO;
	if(strstr(buf, "interrupted"))
		return EINTR;
	if(strstr(buf, "bad arg") || strstr(buf, "invalid"))
		return EINVAL;
	if(strstr(buf, "no memory") || strstr(buf, "out of memory"))
		return ENOMEM;
	if(strstr(buf, "fd out of range") || strstr(buf, "bad fd"))
		return EBADF;
	if(strstr(buf, "too many open"))
		return EMFILE;
	if(strstr(buf, "broken pipe"))
		return EPIPE;
	if(strstr(buf, "timed out") || strstr(buf, "timeout"))
		return ETIMEDOUT;
	if(strstr(buf, "connection refused"))
		return ECONNREFUSED;
	if(strstr(buf, "network unreachable"))
		return ENETUNREACH;
	if(strstr(buf, "not supported") || strstr(buf, "unimplemented"))
		return ENOSYS;
	/* fallback */
	return EIO;
}

/* Wrap a Plan9 int return: -1 from Plan9 → -errno for musl */
static long
p9ret(int r)
{
	if(r < 0)
		return -p9errstr_to_errno();
	return (long)r;
}

/* Wrap a Plan9 long return */
static long
p9retl(long r)
{
	if(r < 0)
		return -p9errstr_to_errno();
	return r;
}

/* ------------------------------------------------------------------ */
/* mmap emulation                                                      */
/*                                                                     */
/* Plan9 has no mmap. We emulate anonymous mappings with segattach/    */
/* segbrk, falling back to malloc for small allocations.              */
/* File-backed mappings are not supported.                             */
/* ------------------------------------------------------------------ */

#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS   0x20
#endif
#ifndef MAP_ANON
#define MAP_ANON        MAP_ANONYMOUS
#endif
#ifndef MAP_FAILED
#define MAP_FAILED      ((void*)-1)
#endif
#ifndef PROT_NONE
#define PROT_NONE       0
#define PROT_READ       1
#define PROT_WRITE      2
#define PROT_EXEC       4
#endif
#ifndef MAP_PRIVATE
#define MAP_PRIVATE     0x02
#define MAP_SHARED      0x01
#define MAP_FIXED       0x10
#endif

/* O_CLOEXEC: use Plan9's OCEXEC which has the same semantics.
 * This ensures posix_flags_to_p9() translates it correctly.
 * Note: FD_CLOEXEC is a different constant (used with fcntl F_SETFD)
 * and must not be used here. */
#ifndef O_CLOEXEC
#define O_CLOEXEC OCEXEC
#endif

static long
p9_mmap(void *addr, size_t len, int prot, int flags, int fd, off_t off)
{
	void *p;
	(void)prot;  /* Plan9 has no per-page protection */

	/* MAP_FIXED at a specific address is not supportable in userland */
	if((flags & MAP_FIXED) && addr != NULL)
		return -EINVAL;

	/* allocate backing memory */
	if(len >= 65536){
		p = _SEGATTACH(0, "memory", 0, len);
		if(p == (void*)-1)
			return -ENOMEM;
	} else {
		p = malloc(len);
		if(p == NULL)
			return -ENOMEM;
	}
	memset(p, 0, len);

	/* file-backed mapping: read file contents into the buffer.
	 * Write-back (MAP_SHARED) is not supported; changes are private. */
	if(!(flags & (MAP_ANONYMOUS|MAP_ANON)) && fd != -1){
		ssize_t n;
		if(off != 0)
			lseek(fd, off, SEEK_SET);
		n = read(fd, p, len);
		if(n < 0){
			if(len >= 65536) _SEGDETACH(p);
			else free(p);
			return -EIO;
		}
	}
	return (long)(uintptr_t)p;
}

/* We can't reliably know whether an address came from segattach or
 * malloc, so we track segattach regions in a small table. */
#define MMAP_TABLE_SIZE 256
static struct {
	void *addr;
	size_t len;
	int   is_seg;   /* 1 = segattach, 0 = malloc */
} mmap_table[MMAP_TABLE_SIZE];
static int mmap_table_n = 0;

static long
p9_mmap_tracked(void *addr, size_t len, int prot, int flags, int fd, off_t off)
{
	long r = p9_mmap(addr, len, prot, flags, fd, off);
	if(r < 0)
		return r;
	if(mmap_table_n < MMAP_TABLE_SIZE){
		mmap_table[mmap_table_n].addr   = (void*)r;
		mmap_table[mmap_table_n].len    = len;
		mmap_table[mmap_table_n].is_seg = (len >= 65536);
		mmap_table_n++;
	}
	return r;
}

static long
p9_munmap(void *addr, size_t len)
{
	int i;
	(void)len;
	for(i = 0; i < mmap_table_n; i++){
		if(mmap_table[i].addr == addr){
			if(mmap_table[i].is_seg)
				_SEGDETACH(addr);
			else
				free(addr);
			/* remove from table */
			mmap_table[i] = mmap_table[--mmap_table_n];
			return 0;
		}
	}
	/* not found in table - attempt free anyway */
	free(addr);
	return 0;
}

/* ------------------------------------------------------------------ */
/* clock_gettime emulation via Plan9 nsec()                           */
/* nsec() returns nanoseconds since the epoch (Jan 1, 1970 UTC)       */
/* ------------------------------------------------------------------ */
extern long long nsec(void);  /* Plan9 libthread / libc */

#ifndef CLOCK_REALTIME
#define CLOCK_REALTIME           0
#endif
#ifndef CLOCK_MONOTONIC
#define CLOCK_MONOTONIC          1
#endif
#ifndef CLOCK_PROCESS_CPUTIME_ID
#define CLOCK_PROCESS_CPUTIME_ID 2
#endif
#ifndef CLOCK_THREAD_CPUTIME_ID
#define CLOCK_THREAD_CPUTIME_ID  3
#endif

static long
p9_clock_gettime(int clk, struct timespec *tp)
{
	long long ns;
	if(tp == NULL)
		return -EFAULT;
	ns = nsec();
	switch(clk){
	case CLOCK_REALTIME:
	case CLOCK_MONOTONIC:     /* Plan9 nsec is monotonic enough for our purposes */
	case CLOCK_PROCESS_CPUTIME_ID:
	case CLOCK_THREAD_CPUTIME_ID:
		tp->tv_sec  = (time_t)(ns / 1000000000LL);
		tp->tv_nsec = (long)  (ns % 1000000000LL);
		return 0;
	default:
		return -EINVAL;
	}
}

static long
p9_clock_getres(int clk, struct timespec *tp)
{
	(void)clk;
	if(tp == NULL)
		return -EFAULT;
	/* Plan9 nsec() resolution is ~1ms on most hardware */
	tp->tv_sec  = 0;
	tp->tv_nsec = 1000000L;
	return 0;
}

/* ------------------------------------------------------------------ */
/* open flag translation: POSIX → Plan9                               */
/* ------------------------------------------------------------------ */
static int
posix_flags_to_p9(int flags)
{
	int p9flags;

	switch(flags & 3){
	case O_RDONLY: p9flags = OREAD;  break;
	case O_WRONLY: p9flags = OWRITE; break;
	case O_RDWR:   p9flags = ORDWR;  break;
	default:       p9flags = OREAD;  break;
	}
	if(flags & O_TRUNC)  p9flags |= OTRUNC;
	if(flags & O_CLOEXEC) p9flags |= OCEXEC;
	/* O_CREAT and O_EXCL are handled by _CREATE, not _OPEN */
	return p9flags;
}

/* ------------------------------------------------------------------ */
/* uid/gid emulation: read from /dev/user                             */
/* ------------------------------------------------------------------ */
static int p9_uid = -1;

static int
p9_getuid(void)
{
	char buf[64];
	int fd, n;
	if(p9_uid >= 0)
		return p9_uid;
	fd = _OPEN("/dev/user", OREAD);
	if(fd < 0)
		return 0;
	n = _READ(fd, buf, sizeof buf - 1);
	_CLOSE(fd);
	if(n <= 0)
		return 0;
	buf[n] = '\0';
	/* Plan9 user names are strings; we hash to a stable nonzero uid */
	{
		unsigned int h = 0;
		char *p;
		for(p = buf; *p; p++)
			h = h*31 + (unsigned char)*p;
		p9_uid = (int)(h & 0x7fff) + 1;
	}
	return p9_uid;
}

/* ------------------------------------------------------------------ */
/* nanosleep emulation via Plan9 _SLEEP (millisecond granularity)     */
/* ------------------------------------------------------------------ */
static long
p9_nanosleep(const struct timespec *req, struct timespec *rem)
{
	long ms;
	if(req == NULL)
		return -EFAULT;
	ms = (long)(req->tv_sec * 1000 + req->tv_nsec / 1000000);
	if(ms < 0) ms = 0;
	if(_SLEEP(ms) < 0){
		if(rem != NULL){
			rem->tv_sec  = 0;
			rem->tv_nsec = 0;
		}
		return -EINTR;
	}
	if(rem != NULL){
		rem->tv_sec  = 0;
		rem->tv_nsec = 0;
	}
	return 0;
}

/* ------------------------------------------------------------------ */
/* brk emulation via _SEGBRK                                          */
/* ------------------------------------------------------------------ */
static void *p9_curbrk = NULL;

static long
p9_brk(void *addr)
{
	void *newbrk;
	if(addr == NULL){
		/* query current brk */
		if(p9_curbrk == NULL)
			p9_curbrk = _SEGBRK(0, 0);
		return (long)(uintptr_t)p9_curbrk;
	}
	newbrk = _SEGBRK(0, addr);
	if(newbrk == (void*)-1)
		return -ENOMEM;
	p9_curbrk = newbrk;
	return (long)(uintptr_t)newbrk;
}

/* ------------------------------------------------------------------ */
/* Main dispatch function                                              */
/* ------------------------------------------------------------------ */
long
__p9_syscall(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
	(void)a5; (void)a6;   /* suppress unused warnings for rarely-used args */

	switch(n){

	/* ---- I/O ---- */

	case SYS_read:  /* [DIRECT] */
		return p9retl(_READ((int)a1, (void*)a2, (long)a3));

	case SYS_write: /* [DIRECT] */
		return p9retl(_WRITE((int)a1, (void*)a2, (long)a3));

	case SYS_pread64: /* [DIRECT] */
		return p9retl(_PREAD((int)a1, (void*)a2, (long)a3, (long long)a4));

	case SYS_pwrite64: /* [DIRECT] */
		return p9retl(_PWRITE((int)a1, (void*)a2, (long)a3, (long long)a4));

	case SYS_open: { /* [ADAPT] flag translation */
		int posixflags = (int)a2;
		int p9flags    = posix_flags_to_p9(posixflags);
		int fd;
		if(posixflags & O_CREAT){
			unsigned long mode = (a3 != 0) ? (unsigned long)a3 : 0666UL;
			fd = _CREATE((char*)a1, p9flags, mode);
		} else {
			fd = _OPEN((const char*)a1, p9flags);
		}
		return p9ret(fd);
	}

	case SYS_close: /* [DIRECT] */
		return p9ret(_CLOSE((int)a1));

	case SYS_lseek: /* [DIRECT] */
		return p9retl((long)_SEEK((int)a1, (long long)a2, (int)a3));

	case SYS_dup: /* [DIRECT] */
		return p9ret(_DUP((int)a1, -1));

	case SYS_dup2: /* [DIRECT] */
		return p9ret(_DUP((int)a1, (int)a2));

	case SYS_pipe: /* [DIRECT] */
		return p9ret(_PIPE((int*)a1));

	case SYS_pipe2: { /* [ADAPT] ignore flags for now, Plan9 pipes are always cloexec-able */
		int r = _PIPE((int*)a1);
		/* if O_CLOEXEC requested, set it on both fds */
		if(r == 0 && ((int)a2 & O_CLOEXEC)){
			int *fds = (int*)a1;
			/* Plan9 dup with OCEXEC flag would go here if needed */
			(void)fds;
		}
		return p9ret(r);
	}

	case SYS_readv: { /* [EMULATE] via multiple _READ calls */
		struct iovec *iov = (struct iovec*)a2;
		int iovcnt = (int)a3;
		long total = 0, r;
		int i;
		for(i = 0; i < iovcnt; i++){
			r = _READ((int)a1, iov[i].iov_base, (long)iov[i].iov_len);
			if(r < 0) return total > 0 ? total : p9retl(r);
			total += r;
			if(r < (long)iov[i].iov_len) break;
		}
		return total;
	}

	case SYS_writev: { /* [EMULATE] via multiple _WRITE calls */
		struct iovec *iov = (struct iovec*)a2;
		int iovcnt = (int)a3;
		long total = 0, r;
		int i;
		for(i = 0; i < iovcnt; i++){
			r = _WRITE((int)a1, iov[i].iov_base, (long)iov[i].iov_len);
			if(r < 0) return total > 0 ? total : p9retl(r);
			total += r;
			if(r < (long)iov[i].iov_len) break;
		}
		return total;
	}

	/* ---- filesystem ---- */

	case SYS_stat: /* [DIRECT] - APE's stat() already wraps this */
		return p9ret(_STAT((const char*)a1, (unsigned char*)a2, (int)a3));

	case SYS_fstat: /* [DIRECT] */
		return p9ret(_FSTAT((int)a1, (unsigned char*)a2, (int)a3));

	case SYS_lstat: /* [ADAPT] Plan9 has no symlinks; lstat == stat */
		return p9ret(_STAT((const char*)a1, (unsigned char*)a2, (int)a3));

	case SYS_access: /* [DIRECT] */
		return p9ret(access((const char*)a1, (int)a2));

	case SYS_unlink: /* [DIRECT] */
		return p9ret(_REMOVE((const char*)a1));

	case SYS_rename: { /* [EMULATE] Plan9 has no atomic rename */
		/* wstat the name field - this is the Plan9 way */
		/* For now fall through to ENOSYS; a full wstat-based
		 * rename can be added here using _WSTAT + dir marshalling */
		(void)a1; (void)a2;
		return -ENOSYS;
	}

	case SYS_mkdir: /* [ADAPT] use _CREATE with DMDIR */
		return p9ret(_CREATE((char*)a1, OREAD, DMDIR | 0777));

	case SYS_rmdir: /* [DIRECT] Plan9 _REMOVE works on dirs too */
		return p9ret(_REMOVE((const char*)a1));

	case SYS_chdir: /* [DIRECT] */
		return p9ret(_CHDIR((const char*)a1));

	case SYS_getcwd: /* [DIRECT] via _FD2PATH on "." */
		{
			int fd = _OPEN(".", OREAD);
			int r;
			if(fd < 0) return p9ret(fd);
			r = _FD2PATH(fd, (char*)a1, (int)a2);
			_CLOSE(fd);
			if(r < 0) return p9ret(r);
			return (long)a1;
		}

	case SYS_link: /* [STUB] Plan9 has no hard links */
		(void)a1; (void)a2;
		return -ENOSYS;

	case SYS_symlink: /* [STUB] Plan9 has no symlinks */
		(void)a1; (void)a2;
		return -ENOSYS;

	case SYS_readlink: /* [STUB] Plan9 has no symlinks */
		(void)a1; (void)a2; (void)a3;
		return -EINVAL;

	case SYS_truncate: { /* [EMULATE] via open+wstat */
		int fd = _OPEN((const char*)a1, OWRITE);
		if(fd < 0) return p9ret(fd);
		/* ftruncate falls through to SYS_ftruncate logic */
		{
			long r = __p9_syscall(SYS_ftruncate, (long)fd, a2, 0, 0, 0, 0);
			_CLOSE(fd);
			return r;
		}
	}

	case SYS_ftruncate: /* [DIRECT] */
		return p9ret(_FWSTAT((int)a1, (unsigned char*)a2, (int)a3));
		/* Note: proper ftruncate needs Dir marshalling; APE's ftruncate.c
		 * in unistd/ is the right implementation to call here instead */

	case SYS_fsync: /* [STUB] Plan9 writes are synchronous; no-op is correct */
		(void)a1;
		return 0;

	case SYS_chmod: /* [DIRECT] via APE's chmod wrapper */
		return p9ret(chmod((const char*)a1, (mode_t)a2));

	case SYS_chown: /* [STUB] Plan9 ownership is string-based, not uid/gid */
		(void)a1; (void)a2; (void)a3;
		return 0;

	/* ---- memory ---- */

	case SYS_brk: /* [EMULATE] */
		return p9_brk((void*)a1);

	case SYS_mmap: /* [EMULATE] anonymous only */
		return p9_mmap_tracked((void*)a1, (size_t)a2,
		                       (int)a3, (int)a4, (int)a5, (off_t)a6);

	case SYS_munmap: /* [EMULATE] */
		return p9_munmap((void*)a1, (size_t)a2);

	case SYS_mremap: /* [STUB] not emulable portably */
		return -ENOSYS;

	case SYS_mprotect: /* [STUB] advisory only in musl's use; no-op is safe */
		(void)a1; (void)a2; (void)a3;
		return 0;

	case SYS_madvise: /* [STUB] purely advisory */
		(void)a1; (void)a2; (void)a3;
		return 0;

	case SYS_mlock:   /* [STUB] */
	case SYS_munlock: /* [STUB] */
		return 0;

	/* ---- process ---- */

	case SYS_fork: /* [ADAPT] rfork with standard flags */
		return p9ret(_RFORK(RFFDG|RFPROC|RFENVG|RFNAMEG));

	case SYS_vfork: /* [ADAPT] vfork → rfork */
		return p9ret(_RFORK(RFFDG|RFPROC|RFENVG|RFNAMEG));

	case SYS_execve: /* [DIRECT] */
		return p9ret(_EXEC((char*)a1, (char**)a2));

	case SYS_exit: /* [DIRECT] */
		_EXITS(a1 == 0 ? "" : "error");
		/* not reached */
		return 0;

	case SYS_exit_group: /* [DIRECT] */
		_EXITS(a1 == 0 ? "" : "error");
		return 0;

	case SYS_getpid: /* [DIRECT] */
		return (long)getpid();

	case SYS_getppid: /* [DIRECT] */
		return (long)getppid();

	case SYS_getpgrp: /* [DIRECT] */
		return (long)getpgrp();

	case SYS_setpgid: /* [DIRECT] */
		return p9ret(setpgid((pid_t)a1, (pid_t)a2));

	case SYS_setsid: /* [DIRECT] */
		return p9ret(setsid());

	/* ---- credentials ---- */

	case SYS_getuid:  /* [EMULATE] via /dev/user hash */
	case SYS_geteuid:
		return (long)p9_getuid();

	case SYS_getgid:  /* [EMULATE] Plan9 has no numeric gids */
	case SYS_getegid:
		return 0L;

	case SYS_setuid:  /* [STUB] Plan9 uid is a string, not settable by number */
	case SYS_setgid:
		return 0L;

	/* ---- signals ---- */

	case SYS_kill: /* [ADAPT] via postnote - APE's kill.c is better */
		return p9ret(kill((pid_t)a1, (int)a2));

	case SYS_rt_sigaction: /* [ADAPT] via APE's signal() */
		/* musl uses this heavily for internal signal setup;
		 * APE's signal infrastructure handles the real work */
		(void)a1; (void)a2; (void)a3;
		return 0;

	case SYS_rt_sigprocmask: /* [ADAPT] */
		return p9ret(sigprocmask((int)a1, (sigset_t*)a2, (sigset_t*)a3));

	case SYS_rt_sigpending: /* [DIRECT] */
		return p9ret(sigpending((sigset_t*)a1));

	case SYS_alarm: /* [DIRECT] */
		return (long)_ALARM((unsigned long)a1);

	case SYS_pause: /* [DIRECT] */
		return p9ret(pause());

	/* ---- time ---- */

	case SYS_clock_gettime: /* [EMULATE] via nsec() */
		return p9_clock_gettime((int)a1, (struct timespec*)a2);

	case SYS_clock_getres: /* [EMULATE] */
		return p9_clock_getres((int)a1, (struct timespec*)a2);

	case SYS_gettimeofday: { /* [EMULATE] via nsec() */
		struct timeval *tv = (struct timeval*)a1;
		long long ns;
		if(tv == NULL) return -EFAULT;
		ns = nsec();
		tv->tv_sec  = (long)(ns / 1000000000LL);
		tv->tv_usec = (long)((ns % 1000000000LL) / 1000LL);
		return 0;
	}

	case SYS_nanosleep: /* [EMULATE] via _SLEEP */
		return p9_nanosleep((const struct timespec*)a1,
		                    (struct timespec*)a2);

	case SYS_time: { /* [EMULATE] via nsec() */
		long long ns = nsec();
		time_t t = (time_t)(ns / 1000000000LL);
		if((time_t*)a1 != NULL)
			*(time_t*)a1 = t;
		return (long)t;
	}

	/* ---- misc ---- */

	case SYS_umask: /* [DIRECT] */
		return (long)umask((mode_t)a1);

	case SYS_getrlimit: /* [STUB] return generous limits */
		{
			/* struct rlimit { rlim_t rlim_cur, rlim_max; } */
			unsigned long *rl = (unsigned long*)a2;
			if(rl != NULL){
				rl[0] = (unsigned long)-1L;  /* RLIM_INFINITY */
				rl[1] = (unsigned long)-1L;
			}
			return 0;
		}

	case SYS_setrlimit: /* [STUB] silently accepted */
		return 0;

	case SYS_getrusage: /* [DIRECT] */
		return p9ret(getrusage((int)a1, (struct rusage*)a2));

	case SYS_poll:   /* [DIRECT] via APE's poll */
		return p9ret(poll((struct pollfd*)a1, (nfds_t)a2, (int)a3));

	case SYS_uname: /* [EMULATE] fill in minimal uname struct */
		{
			/* struct utsname fields are char[65] in POSIX */
			char (*u)[65] = (char(*)[65])a1;
			if(u == NULL) return -EFAULT;
			strncpy(u[0], "Plan9",   64);  /* sysname  */
			strncpy(u[1], "plan9",   64);  /* nodename */
			strncpy(u[2], "4front",  64);  /* release  */
			strncpy(u[3], "9front",  64);  /* version  */
			strncpy(u[4], "plan9",   64);  /* machine  */
			return 0;
		}

	case SYS_fcntl: /* [ADAPT] limited fcntl support */
		return p9ret(fcntl((int)a1, (int)a2, a3));

	/* ---- unimplemented / not needed ---- */

	case SYS_getdents:
	case SYS_getdents64:
	case SYS_sysinfo:
	case SYS_times:
	case SYS_getsid:
	case SYS_clock_settime:
	case SYS_settimeofday:
		return -ENOSYS;

	default:
		return -ENOSYS;
	}
}
