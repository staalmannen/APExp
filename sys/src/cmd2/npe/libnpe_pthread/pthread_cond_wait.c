#include "_pthread.h"

int
pthread_cond_wait(pthread_cond_t *const cond, pthread_mutex_t *const mutex)
{
	qlock(cond->l);
	qunlock(mutex);
	rsleep(cond);
	qunlock(cond->l);
	qlock(mutex);

	return 0;
}
