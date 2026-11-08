#include "_pthread.h"

static void
thread(void *x)
{
	npe_pthread_t *t;
	void *p;

	t = x;
	p = t->func(t->arg);
	send(t->waitchan, p);
	chanfree(t->waitchan);
	free(t);

	threadexits(nil);
}

int
pthread_create(pthread_t *pt, pthread_attr_t *attr, void *(*f)(void*), void *arg)
{
	npe_pthread_t *t;
	int stacksz;

	stacksz = attr == nil ? 0 : attr->stack_size;
	if(stacksz == 0)
		stacksz = mainstacksize;

	t = calloc(1, sizeof(npe_pthread_t));
	t->waitchan = chancreate(sizeof(void*), 0);
	t->func = f;
	t->arg = arg;
	t->pid = proccreate(thread, t, stacksz);
	*pt = (pthread_t)t;

	return 0;
}
