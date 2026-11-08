#include "_pthread.h"

int
pthread_join(pthread_t pt, void **res)
{
	npe_pthread_t *t;
	t = (npe_pthread_t*)pt;
	if(t->waitchan != nil)
		recv(t->waitchan, res);

	return 0;
}
