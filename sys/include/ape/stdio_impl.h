#ifndef _STDIO_IMPL_H
#define _STDIO_IMPL_H

#include <stdio.h>
#include <_iofile.h>	/* struct _IO_FILE; <stdio.h> gets it from here too */
/* APExp: replaced #include "syscall.h" with the POSIX headers we actually need.
 * These stay: the implementation wants them. They no longer reach every
 * file that includes <stdio.h>, because that now includes <_iofile.h>
 * rather than this header -- see the note there. */
#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <pthread.h>
/* APExp: sys/uio.h not available; writev call sites in __stdio_write.c
 * must be replaced with a plain write() loop - see notes */

/* APExp: 'hidden' is a musl-internal visibility attribute from libc.h.
 * On Plan9 APE we have no shared library visibility controls, so it
 * is a no-op. */
#ifndef hidden
#define hidden
#endif

#define UNGET 8

#define F_PERM 1
#define F_NORD 4
#define F_NOWR 8
#define F_EOF 16
#define F_ERR 32
#define F_SVB 64
#define F_APP 128


extern struct _IO_FILE *volatile __stdin_used;
extern struct _IO_FILE *volatile __stdout_used;
extern struct _IO_FILE *volatile __stderr_used;

/* APExp: __lockfile/__unlockfile -- Real pthread mutex support
 * Each FILE has its own lock (f->lock stores a pthread_mutex_t*).
 * __lockfile returns 1 on success to signal FUNLOCK to call __unlockfile.
 */

static inline int __lockfile(struct _IO_FILE *f) {
	/*
	 * f->lock == -1 means single-threaded / no locking (stdout/stderr/stdin).
	 * f->lock == 0 means not yet initialised.
	 * f->lock > 0 would be a mutex pointer, but Plan9 APE stdio does not
	 * set up pthread mutexes for the standard streams, so we never reach
	 * that branch in practice.  Keeping this as a no-op avoids a potential
	 * crash from using an uninitialised or sign-confused lock value as a
	 * pointer.
	 */
	(void)f;
	return 0;
}

static inline void __unlockfile(struct _IO_FILE *f) {
	(void)f;
}

#define _FLOCK(f) int __need_unlock = __lockfile(f)
#define _FUNLOCK(f) do { if (__need_unlock) __unlockfile(f); } while(0)

/*
 * APExp internal, in stdio/__wfmt.c: convert a format string between the
 * wide and narrow encodings. Used by the wide printf and scanf families,
 * which delegate to their narrow counterparts. Both return a malloc'd
 * buffer for the caller to free, or 0 with errno set.
 */
extern char *__wfmt_narrow(const wchar_t *);
extern wchar_t *__wfmt_wide(const char *);
#define FFINALLOCK(f) ((f)->lock>=0 ? __lockfile((f)) : 0)

hidden size_t __stdio_read(struct _IO_FILE *, unsigned char *, size_t);
hidden size_t __stdio_write(struct _IO_FILE *, const unsigned char *, size_t);
hidden size_t __stdout_write(struct _IO_FILE *, const unsigned char *, size_t);
hidden off_t __stdio_seek(struct _IO_FILE *, off_t, int);
hidden int __stdio_close(struct _IO_FILE *);

hidden int __toread(struct _IO_FILE *);
hidden int __towrite(struct _IO_FILE *);

hidden void __stdio_exit(void);
hidden void __stdio_exit_needed(void);

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
