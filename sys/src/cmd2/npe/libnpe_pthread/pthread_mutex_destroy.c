#include "_pthread.h"

int
pthread_mutex_destroy(pthread_mutex_t *const mutex)
{
	USED(mutex);
	return 0;
}
