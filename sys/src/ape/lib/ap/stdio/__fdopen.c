#include "stdio_impl.h"
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

FILE *__fdopen(int fd, const char *mode)
{
	FILE *f;
	pthread_mutex_t *lock;
	unsigned char *buf_start;
	size_t alloc_size;

	/* Check for valid initial mode character */
	if (!strchr("rwa", *mode)) {
		errno = EINVAL;
		return NULL;
	}

	/* Calculate allocation size: struct + UNGET + buffer */
	alloc_size = sizeof(struct _IO_FILE) + UNGET + BUFSIZ;

	/* Allocate FILE+buffer as one block */
	f = malloc(alloc_size);
	if (!f) return NULL;

	/* Zero-fill the entire block */
	memset(f, 0, alloc_size);

	/* Calculate buffer start address (UNGET bytes after struct) */
	buf_start = (unsigned char *)f + sizeof(struct _IO_FILE) + UNGET;

	/* Initialize FILE fields */
	f->flags = 0;  /* not permanent — fclose() will free this FILE */
	f->fd = fd;
	f->buf = buf_start;
	f->buf_size = BUFSIZ;

	/* Impose mode restrictions */
	if (!strchr(mode, '+')) {
		f->flags |= (*mode == 'r') ? F_NOWR : F_NORD;
	}

	/* Initialize read/write pointers.
	 * Read-only files leave write pointers NULL so any write attempt
	 * falls through to f->write() which fails on the read-only fd,
	 * properly setting F_ERR.  Write/append files get a ready buffer. */
	f->rpos = buf_start;
	f->rend = buf_start;
	if (f->flags & F_NOWR) {
		/* Read-only: no write buffer */
		f->wbase = NULL;
		f->wpos  = NULL;
		f->wend  = NULL;
	} else {
		f->wbase = buf_start;
		f->wpos  = buf_start;
		f->wend  = buf_start + BUFSIZ;
	}

	/* Line buffering */
	f->lbf = '\n';

	/* Initialize operation pointers */
	f->read = __stdio_read;
	f->write = __stdio_write;
	f->seek = __stdio_seek;
	f->close = __stdio_close;

	/* Initialize pthread mutex for the lock field */
	lock = malloc(sizeof(pthread_mutex_t));
	if (!lock) {
		free(f);
		errno = ENOMEM;
		return NULL;
	}

	{
		pthread_mutexattr_t attr;
		pthread_mutexattr_init(&attr);
		pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
		if (pthread_mutex_init(lock, &attr) != 0) {
			pthread_mutexattr_destroy(&attr);
			free(lock);
			free(f);
			errno = ENOMEM;
			return NULL;
		}
		pthread_mutexattr_destroy(&attr);
	}

	/* Store pointer as intptr_t */
	f->lock = (intptr_t)lock;

	/* Initialize other fields to sensible defaults */
	f->pipe_pid = 0;
	f->lockcount = 0;
	f->mode = 0;
	f->cookie = NULL;
	f->off = 0;
	f->getln_buf = NULL;
	f->prev = NULL;
	f->next = NULL;
	f->prev_locked = NULL;
	f->next_locked = NULL;
	f->locale = NULL;
	f->shend = NULL;
	f->shlim = 0;
	f->shcnt = 0;
	f->mustbezero_1 = NULL;
	f->mustbezero_2 = NULL;

	/* Add to open file list */
	return __ofl_add(f);
}

