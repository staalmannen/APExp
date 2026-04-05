#ifndef _STDIO_IMPL_H
#define _STDIO_IMPL_H

#include <stdio.h>
/* APExp: replaced #include "syscall.h" with the POSIX headers we actually need */
#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
/* APExp: sys/uio.h not available; writev call sites in __stdio_write.c
 * must be replaced with a plain write() loop - see notes */

/* APExp: 'hidden' is a musl-internal visibility attribute from libc.h.
 * On Plan9 APE we have no shared library visibility controls, so it
 * is a no-op. */
#ifndef hidden
#define hidden
#endif

#define UNGET 8

#define FFINALLOCK(f) ((f)->lock>=0 ? __lockfile((f)) : 0)
#define FLOCK(f) int __need_unlock = ((f)->lock>=0 ? __lockfile((f)) : 0)
#define FUNLOCK(f) do { if (__need_unlock) __unlockfile((f)); } while (0)

#define F_PERM 1
#define F_NORD 4
#define F_NOWR 8
#define F_EOF 16
#define F_ERR 32
#define F_SVB 64
#define F_APP 128

struct _IO_FILE {
	unsigned flags;
	unsigned char *rpos, *rend;
	int (*close)(struct _IO_FILE *);
	unsigned char *wend, *wpos;
	unsigned char *mustbezero_1;
	unsigned char *wbase;
	size_t (*read)(struct _IO_FILE *, unsigned char *, size_t);
	size_t (*write)(struct _IO_FILE *, const unsigned char *, size_t);
	off_t (*seek)(struct _IO_FILE *, off_t, int);
	unsigned char *buf;
	size_t buf_size;
	struct _IO_FILE *prev, *next;
	int fd;
	int pipe_pid;
	long lockcount;
	int mode;
	volatile intptr_t lock;
	int lbf;
	void *cookie;
	off_t off;
	char *getln_buf;
	void *mustbezero_2;
	unsigned char *shend;
	off_t shlim, shcnt;
	struct _IO_FILE *prev_locked, *next_locked;
	struct __locale_struct *locale;
};

extern hidden struct _IO_FILE *volatile __stdin_used;
extern hidden struct _IO_FILE *volatile __stdout_used;
extern hidden struct _IO_FILE *volatile __stderr_used;

/* APExp: __lockfile/__unlockfile -- APE has no thread support so these
 * are no-op stubs. The lock field is retained in the struct (layout must
 * match) but will never be contended.
 *
 * UPDATED: Now uses real pthread mutexes for proper thread safety.
 * Each FILE has its own lock (f->lock is a pthread_mutex_t).
 * __lockfile returns 1 on success to signal FUNLOCK to call __unlockfile.
 */

#include <pthread.h>

static inline int __lockfile(struct _IO_FILE *f) {
	if (f->lock < 0) return 0;
	if (pthread_mutex_lock((pthread_mutex_t *)&f->lock) != 0)
		return 0;
	return 1;
}

static inline void __unlockfile(struct _IO_FILE *f) {
	if (f->lock < 0) return;
	pthread_mutex_unlock((pthread_mutex_t *)&f->lock);
}

hidden size_t __stdio_read(struct _IO_FILE *, unsigned char *, size_t);
hidden size_t __stdio_write(struct _IO_FILE *, const unsigned char *, size_t);
hidden size_t __stdout_write(struct _IO_FILE *, const unsigned char *, size_t);
hidden off_t __stdio_seek(struct _IO_FILE *, off_t, int);
hidden int __stdio_close(struct _IO_FILE *);

hidden int __toread(struct _IO_FILE *);
hidden int __towrite(struct _IO_FILE *);

hidden void __stdio_exit(void);
hidden void __stdio_exit_needed(void);

#if defined(__PIC__) && (100*__GNUC__+__GNUC_MINOR__ >= 303)
__attribute__((visibility("protected")))
#endif
int __overflow(struct _IO_FILE *, int), __uflow(struct _IO_FILE *);

hidden int __fseeko(struct _IO_FILE *, off_t, int);
hidden int __fseeko_unlocked(struct _IO_FILE *, off_t, int);
hidden off_t __ftello(struct _IO_FILE *);
hidden off_t __ftello_unlocked(struct _IO_FILE *);
hidden size_t __fwritex(const unsigned char *, size_t, struct _IO_FILE *);
hidden int __putc_unlocked(int, struct _IO_FILE *);

hidden struct _IO_FILE *__fdopen(int, const char *);
hidden int __fmodeflags(const char *);

hidden struct _IO_FILE *__ofl_add(struct _IO_FILE *f);
hidden struct _IO_FILE **__ofl_lock(void);
hidden void __ofl_unlock(void);

/* APExp: pthread/locked-file tracking omitted -- no thread support in APE.
 * __register_locked_file, __unlist_locked_file, __do_orphaned_stdio_locks
 * and struct __pthread are all removed. Any .c file referencing these
 * will need those call sites stubbed or guarded with #ifndef APE_NO_THREADS. */

#define MAYBE_WAITERS 0x40000000

hidden void __getopt_msg(const char *, const char *, const char *, size_t);

#define getc_unlocked(f) \
	( ((f)->rpos != (f)->rend) ? *(f)->rpos++ : __uflow((f)) )

#define putc_unlocked(c, f) \
	( (((unsigned char)(c)!=(f)->lbf && (f)->wpos!=(f)->wend)) \
	? *(f)->wpos++ = (unsigned char)(c) \
	: __overflow((f),(unsigned char)(c)) )

/* Caller-allocated FILE * operations */
hidden struct _IO_FILE *__fopen_rb_ca(const char *, struct _IO_FILE *, unsigned char *, size_t);
hidden int __fclose_ca(struct _IO_FILE *);

/* missing helpers */
static inline int __shgetc(struct _IO_FILE *f) { return __uflow(f); }

#define f_reading(f)  (!((f)->flags & F_NORD))
#define f_writing(f)  (!((f)->flags & F_NOWR))

/* Whether musl needs FILE orientation (wide/narrow); can stub */
#define ORIENT(f,m) ((void)0)

/* required for scanf internals */
#ifndef feof_unlocked
#define feof_unlocked(f)  ((f)->flags & F_EOF)
#endif

#ifndef ferror_unlocked
#define ferror_unlocked(f) ((f)->flags & F_ERR)
#endif

#endif
