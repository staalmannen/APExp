#include "_pthread.h"

int
pthread_cond_destroy(pthread_cond_t *const cond)
{
	USED(cond);
	return 0;
}
