#include <pthread.h>
#include <assert.h>
#include "lib.h"

extern void	_EXITS(char *);

void
pthread_exit(void *retval)
{
	Thread *priv;
	pthread_t pid;

	/* POSIX: thread-specific data destructors run when a thread
	   exits, before it is finished with. This is the only place a
	   thread ends -- pthread_create's wrapper calls pthread_exit
	   when the start routine returns. */
	_pthreadkeydtors();

	pid = pthread_self();
	priv = _pthreadget(pid);
	assert(priv != NULL);
	lock(&priv->l);
	priv->exited = 1;
	priv->ret = retval;
	unlock(&priv->l);
	_EXITS(0);
}
