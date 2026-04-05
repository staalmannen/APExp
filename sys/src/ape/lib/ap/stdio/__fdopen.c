#include <stdint.h>
#include "stdio_impl.h"
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

FILE *__fdopen(int fd, const char *mode)
{
	FILE *f;
	pthread_mutex_t *lock;

	/* Check for valid initial mode character */
	if (!strchr("rwa", *mode)) {
		errno = EINVAL;
		return NULL;
	}

	/* Allocate FILE+buffer */
	f = malloc(sizeof(struct _IO_FILE) + UNGET + BUFSIZ);
	if (!f) return NULL;

	/* Zero-fill the struct */
	memset(f, 0, sizeof(struct _IO_FILE));

	/* Impose mode restrictions */
	if (!strchr(mode, '+')) {
		f->flags = (*mode == 'r') ? F_NOWR : F_NORD;
	}

	/* Initialize fd and buffer */
	f->fd = fd;
	f->buf = (unsigned char *)f + sizeof(struct _IO_FILE) + UNGET;
	f->buf_size = BUFSIZ;

	/* Line buffering - simplified for Plan 9 (no TIOCGWINSZ) */
	f->lbf = EOF;
	/* Could add isatty() check here if needed for terminals */

	/* Initialize operation pointers */
	f->read = __stdio_read;
	f->write = __stdio_write;
	f->seek = __stdio_seek;
	f->close = __stdio_close;

	/* Initialize pthread mutex for the lock field */
	/* The lock field is interpreted as a pthread_mutex_t* when >= 0 */
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

	/* Store pointer as int (assumes pointer fits in int) */
	f->lock = (int)(intptr_t)lock;

	/* Add to open file list */
	return __ofl_add(f);
}

/* Compatibility alias */
FILE *fdopen(int fd, const char *mode)
{
	return __fdopen(fd, mode);
}

