#include "_pthread.h"

int
pthread_cond_signal(pthread_cond_t *const cond)
{
	qlock(cond->l);
	rwakeup(cond);
	qunlock(cond->l);

	return 0;
}
