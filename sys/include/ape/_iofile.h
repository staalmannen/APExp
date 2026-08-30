#ifndef _IOFILE_H
#define _IOFILE_H

/*
 * struct _IO_FILE -- the definition <stdio.h> needs and nothing more.
 *
 * <stdio.h> has to see this, because FILE is a typedef of it and
 * callers put FILE * in structures and pass it about. It used to get it
 * by including <stdio_impl.h>, which is musl's *internal* header, and
 * which in this tree opens with
 *
 *	#include <stdint.h>
 *	#include <stddef.h>
 *	#include <errno.h>
 *	#include <unistd.h>
 *	#include <fcntl.h>
 *	#include <sys/types.h>
 *	#include <pthread.h>
 *
 * because the implementation genuinely wants all of that. The effect
 * was that every translation unit including <stdio.h> -- which is
 * nearly all of them -- also got every O_ and F_ macro, all of unistd
 * and all of pthread.
 *
 * That is not merely untidy. Portable code guards its fallbacks on
 * whether a name exists, and a name that appears earlier or later than
 * the author expected changes the answer. libzip is the case that
 * prompted this: its compat.h does
 *
 *	#ifndef O_CLOEXEC
 *	#define O_CLOEXEC 0
 *	#endif
 *
 * for Windows' sake, having included neither <fcntl.h> nor anything
 * that leads to it -- but <zip.h> asks for stdio a little later, fcntl
 * arrives through the back door, and the two definitions disagree:
 *
 *	fcntl.h:21 ... zip.h:80 ... zipint.h:51 zip_add.c:36
 *	  Macro redefinition of O_CLOEXEC
 *
 * musl's own arrangement is the one restored here: the struct lives in
 * a header with only the types it needs, and both <stdio.h> and
 * stdio_impl.h include that. stdio_impl.h keeps its heavy includes, so
 * the 64 files in ap/stdio that use it are unaffected.
 *
 * Three includes, and each is used: size_t for the buffer sizes and the
 * read and write hooks, off_t for seek and the offsets, intptr_t for
 * the lock. struct __locale_struct is only ever a pointer here, so it
 * stays incomplete and needs no header.
 */

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

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

#endif /* _IOFILE_H */
