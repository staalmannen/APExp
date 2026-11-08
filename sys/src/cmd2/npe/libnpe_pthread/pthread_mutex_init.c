#include "_pthread.h"

int
pthread_mutex_init(pthread_mutex_t *const mutex, const void *const attr)
{
	USED(attr);
	memset(mutex, 0, sizeof(*mutex));

	return 0;
}
