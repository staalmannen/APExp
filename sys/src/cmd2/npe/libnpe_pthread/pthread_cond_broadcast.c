#include "_pthread.h"

int
pthread_cond_broadcast(pthread_cond_t *const cond)
{
	qlock(cond->l);
	rwakeupall(cond);
	qunlock(cond->l);

	return 0;
}
