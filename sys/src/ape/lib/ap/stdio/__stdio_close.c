#include "stdio_impl.h"
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

int __stdio_close(FILE *f)
{
	int ret;
	pthread_mutex_t *lock;

	if (f->fd < 0) return -1;

	/* Close the file descriptor */
	ret = close(f->fd);
	f->fd = -1;

	/* Destroy the pthread mutex if it exists */
	if (f->lock > 0) {
		lock = (pthread_mutex_t *)(intptr_t)f->lock;
		pthread_mutex_destroy(lock);
		free(lock);
		f->lock = -1;
	}

	/* Free any allocated buffer */
	if (f->flags & F_SVB) {
		free(f->buf);
		f->buf = NULL;
	}

	/* Free the FILE structure itself if it was malloc'd */
	free(f);

	return ret;
}

