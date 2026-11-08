#include "_pthread.h"

int
pthread_cond_init(pthread_cond_t *const cond, const void *const attr)
{
	USED(attr);
	memset(cond, 0, sizeof(*cond));
	cond->l = &cond->lock;

	return 0;
}
