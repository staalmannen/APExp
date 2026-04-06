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

	/* Check for valid initial mode character */
	if (!strchr("rwa", *mode)) {
		errno = EINVAL;
		return NULL;
	}

	/* Allocate FILE+buffer as one block */
	f = malloc(sizeof(struct _IO_FILE) + UNGET + BUFSIZ);
	if (!f) return NULL;

	/* Zero-fill the entire block */
	memset(f, 0, sizeof(struct _IO_FILE) + UNGET + BUFSIZ);

	/* Calculate buffer start address */
	buf_start = (unsigned char *)f + sizeof(struct _IO_FILE) + UNGET;

	/* Initialize all FILE fields */
	f->flags = F_PERM;
	f->fd = fd;
	f->buf = buf_start;
	f->buf_size = BUFSIZ;

	/* Initialize read/write pointers */
	f->rpos = f->buf;
	f->rend = f->buf;
	f->wbase = f->buf;
	f->wpos = f->buf;
	f->wend = f->buf + BUFSIZ;

	/* Impose mode restrictions */
	if (!strchr(mode, '+')) {
		f->flags |= (*mode == 'r') ? F_NOWR : F_NORD;
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

	if (pthread_mutex_init(lock, NULL) != 0) {
		free(lock);
		free(f);
		errno = ENOMEM;
		return NULL;
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

