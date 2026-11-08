#include "_pthread.h"

int
pthread_mutex_unlock(pthread_mutex_t *const mutex)
{
	qunlock(mutex);
	return 0;
}
