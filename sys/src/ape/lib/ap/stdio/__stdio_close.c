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

	/* Destroy and free the pthread mutex */
	if (f->lock > 0) {
		lock = (pthread_mutex_t *)(intptr_t)f->lock;
		pthread_mutex_destroy(lock);
		free(lock);
		f->lock = -1;
	}

	/*
	 * NOTE: do NOT free f->buf or free(f) here.
	 * fclose() owns that cleanup:
	 *   - it frees f->buf when F_SVB is set
	 *   - it frees the FILE struct itself for non-F_PERM files
	 */
	return ret;
}
