#include "_pthread.h"

int
pthread_mutex_lock(pthread_mutex_t *const mutex)
{
	qlock(mutex);
	return 0;
}
