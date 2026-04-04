#ifndef _LIBC_H
#define _LIBC_H

/* Plan9 / APExp libc.h */
#define _LOCK_EXTENSION
#define _QLOCK_EXTENSION

#include <libnet.h>

#include <stdint.h>
#include <sys/types.h>
#include <lock.h>
#include <qlock.h>
#include <lib9.h>
#include <stdlib.h>
#include <string.h>
#include <bsd.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <utf.h>
#include <fmt.h>
#include <signal.h>
#include <time.h>

#define	nelem(x)	(sizeof(x)/sizeof((x)[0]))

typedef
struct Qid
{
	uvlong	path;
	ulong	vers;
	uchar	type;
} Qid;

typedef
struct Dir {
	/* system-modified data */
	ushort	type;	/* server type */
	uint	dev;	/* server subtype */
	/* file data */
	Qid	qid;	/* unique id from server */
	ulong	mode;	/* permissions */
	ulong	atime;	/* last read time */
	ulong	mtime;	/* last write time */
	vlong	length;	/* file length: see <u.h> */
	char	*name;	/* last element of path */
	char	*uid;	/* owner name */
	char	*gid;	/* group name */
	char	*muid;	/* last modifier name */
} Dir;

uint	_convM2D(uchar*, uint, Dir*, char*);
uint	_convD2M(Dir*, uchar*, uint);
Dir	*_dirstat(char*);
int	_dirwstat(char*, Dir*);
Dir	*_dirfstat(int);
int	_dirfwstat(int, Dir*);
long	_dirread(int, Dir**);
long _dirreadall(int, Dir**);
void _nulldir(Dir*);
uint _sizeD2M(Dir*);

#define convM2D	_convM2D
#define convD2M	_convD2M
#define dirstat _dirstat
#define dirwstat _dirwstat
#define dirfstat _dirfstat
#define dirfwstat _dirfwstat
#define dirread _dirread
#define dirreadall _dirreadall
#define nulldir _nulldir
#define sizeD2M _sizeD2M

typedef
struct Waitmsg
{
	int pid;	/* of loved one */
	unsigned long time[3];	/* of loved one & descendants */
	char	*msg;
} Waitmsg;

extern	int	_AWAIT(char*, int);
extern	int	_ALARM(unsigned long);
extern	int	_BIND(const char*, const char*, int);
extern	int	_CHDIR(const char*);
extern	int	_CLOSE(int);
extern	int	_CREATE(char*, int, unsigned long);
extern	int	_DUP(int, int);
extern	int	_ERRSTR(char*, unsigned int);
extern	int	_EXEC(char*, char*[]);
extern	void	_EXITS(char *);
extern	int	_FD2PATH(int, char*, int);
extern	int	_FAUTH(int, char*);
extern	int	_FSESSION(int, char*, int);
extern	int	_FSTAT(int, unsigned char*, int);
extern	int	_FWSTAT(int, unsigned char*, int);
extern	int	_MOUNT(int, int, const char*, int, const char*);
extern	int	_NOTED(int);
extern	int	_NOTIFY(int(*)(void*, char*));
extern	int	_OPEN(const char*, int);
extern	int	_PIPE(int*);
extern	long	_PREAD(int, void*, long, long long);
extern	long	_PWRITE(int, void*, long, long long);
extern	long	_READ(int, void*, long);
extern	int	_REMOVE(const char*);
extern	void*	_RENDEZVOUS(void*, void*);
extern	int	_RFORK(int);
extern	void*	_SEGATTACH(int, char*, void*, unsigned long);
extern	void*	_SEGBRK(void*, void*);
extern	int	_SEGDETACH(void*);
extern	int	_SEGFLUSH(void*, unsigned long);
extern	int	_SEGFREE(void*, unsigned long);
extern	long long	_SEEK(int, long long, int);
extern	int	_SLEEP(long);
extern	int	_STAT(const char*, unsigned char*, int);
extern	Waitmsg*	_WAIT(void);
extern	long	_WRITE(int, const void*, long);
extern	int	_WSTAT(const char*, unsigned char*, int);
extern 	void*	_MALLOCZ(int, int);
extern	int	_WERRSTR(char*, ...);
extern	long	_READN(int, void*, long);
extern	int	_IOUNIT(int);
extern	vlong	_NSEC(void);

#define OREAD 0
#define OWRITE 1
#define ORDWR 2
#define	OEXEC	3	/* execute, == read but check execute permission */
#define	OTRUNC	16	/* or'ed in (except for exec), truncate file first */
#define	OCEXEC	32	/* or'ed in, close on exec */
#define	ORCLOSE	64	/* or'ed in, remove on close */
#define	OEXCL	0x1000	/* or'ed in, exclusive use (create only) */

#define AREAD 4
#define AWRITE 2
#define AEXEC 1
#define AEXIST 0

#define _exits(s) _exit(s && *(char*)s ? 1 : 0)
#define exits(s) exit(s && *(char*)s ? 1 : 0)

#define create(file, omode, perm) open(file, (omode) |O_CREAT | O_TRUNC, perm)
#define seek(fd, off, dir) lseek(fd, off, dir)

#define fauth _FAUTH
#define wait _WAIT
#define readn _READN
#define pread _PREAD
#define pwrite _PWRITE
#define mallocz _MALLOCZ
#define nsec	_NSEC
#define iounit	_IOUNIT
#define sleep	_SLEEP

#define getwd(buf,len)	getcwd(buf,len)
#define postnote(who,pid,note)	kill(pid,SIGTERM)
#define atnotify(func,in)

#define ERRMAX 128

int errstr(char*, unsigned int);
void rerrstr(char*, unsigned int);
extern _Noreturn void sysfatal(char*, ...);

extern	void		setmalloctag(void*, uintptr_t);
extern	void		setrealloctag(void*, uintptr_t);
extern	uintptr_t	getcallerpc(void*);

extern int  dec16(uchar *, int, char *, int);
extern int  enc16(char *, int, uchar *, int);
extern int  dec32(uchar *, int, char *, int);
extern int  enc32(char *, int, uchar *, int);
extern int  dec64(uchar *, int, char *, int);
extern int  enc64(char *, int, uchar *, int);

extern	int	dec64chr(int);
extern	int	enc64chr(int);
extern	int	dec32chr(int);
extern	int	enc32chr(int);
extern	int	dec16chr(int);
extern	int	enc16chr(int);

extern	int	idn2utf(char *, char *, int);
extern	int	utf2idn(char *, char *, int);

extern int tokenize(char*, char**, int);
extern int getfields(char*, char**, int, int, char*);
extern int gettokens(char*, char**, int, char*);

extern ulong truerand(void); /* uses /dev/random */

extern int encrypt(void*, void*, int len);
extern int decrypt(void*, void*, int len);

typedef
struct Tm
{
	int	sec;
	int	min;
	int	hour;
	int	mday;
	int	mon;
	int	year;
	int	wday;
	int	yday;
	char	zone[4];
	int	tzoff;
} Tm;

Tm* _gmtime(time_t);
#define gmtime _gmtime

/* ============================================================
   Musl compatibility shims
   ============================================================ */

/*
 * These functions are required by musl libc internal files such as:
 *   pthread_impl.h
 *   futex.h
 *   cancellation.c
 *   thread list helpers
 *
 * They do NOT implement musl’s real behavior. These are lightweight
 * compatibility stubs that allow musl components to compile when
 * linked against your Plan 9–derived pthread and libc system.
 */

#include <pthread.h>

/* ------------------------------
   Thread self
   ------------------------------ */

static inline pthread_t __pthread_self(void)
{
    return pthread_self();
}

/* ------------------------------
   TLS (no real TLS used)
   ------------------------------ */

static inline int __init_tp(void *p)      { return 0; }
static inline void *__copy_tls(unsigned char *p) { return NULL; }
static inline void __reset_tls(void)      { }

/* ------------------------------
   Cancellation stubs
   ------------------------------ */

struct __ptcb { void *unused; };

static inline void __testcancel(void) { }
static inline void __do_cleanup_push(struct __ptcb *cb) { }
static inline void __do_cleanup_pop(struct __ptcb *cb) { }
static inline void __pthread_tsd_run_dtors(void) { }

/* ------------------------------
   Key deletion shim
   ------------------------------ */

static inline void __pthread_key_delete_synccall(void (*f)(void *), void *p) { }
static inline int __pthread_key_delete_impl(pthread_key_t k)
{
    return pthread_key_delete(k);
}

/* ------------------------------
   Thread list / global locks
   ------------------------------ */

static volatile int __thread_list_lock = 0;
static volatile int __abort_lock[1] = {0};

static inline void __tl_lock(void)  { }
static inline void __tl_unlock(void){ }
static inline void __tl_sync(pthread_t t) { }

/* ------------------------------
   Synchronization: wait/wake
   (portable futex emulation)
   ------------------------------ */

typedef struct {
    pthread_mutex_t m;
    pthread_cond_t  c;
} __shim_waiter_t;

static __shim_waiter_t __shim_waiter = {
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_COND_INITIALIZER
};

/* Wait while *addr == val */
static inline void __wait(volatile int *addr,
                          volatile int *cond,
                          int val,
                          int priv)
{
    (void)cond; (void)priv;

    pthread_mutex_lock(&__shim_waiter.m);
    while (*addr == val)
        pthread_cond_wait(&__shim_waiter.c, &__shim_waiter.m);
    pthread_mutex_unlock(&__shim_waiter.m);
}

/* Wake cnt waiters */
static inline void __wake(volatile void *addr,
                          int cnt,
                          int priv)
{
    (void)addr; (void)priv;

    pthread_mutex_lock(&__shim_waiter.m);
    if (cnt <= 1)
        pthread_cond_signal(&__shim_waiter.c);
    else
        pthread_cond_broadcast(&__shim_waiter.c);
    pthread_mutex_unlock(&__shim_waiter.m);
}

/* Timed wait (timeout ignored in this shim) */
static inline int __timedwait(volatile int *addr,
                              int val,
                              clockid_t clk,
                              const struct timespec *ts,
                              int priv)
{
    (void)clk; (void)ts; (void)priv;
    __wait(addr, NULL, val, priv);
    return 0;
}

static inline int __timedwait_cp(volatile int *addr,
                                 int val,
                                 clockid_t clk,
                                 const struct timespec *ts,
                                 int priv)
{
    return __timedwait(addr, val, clk, ts, priv);
}

/* ------------------------------
   Misc musl symbols
   ------------------------------ */

static inline void __membarrier_init(void) { }
static inline void __dl_thread_cleanup(void) { }

static inline void __unmapself(void *a, size_t s)
{
    /* unsupported — no-op */
}

static inline int __libc_sigaction(int s,
                                   const struct sigaction *a,
                                   struct sigaction *o)
{
    return sigaction(s, a, o);
}

/* Provide default (dummy) values */
static unsigned __default_stacksize = 1 << 20;
static unsigned __default_guardsize = 4096;

#define DEFAULT_STACK_SIZE  (__default_stacksize)
#define DEFAULT_GUARD_SIZE  (__default_guardsize)

#endif /* _LIBC_H */
