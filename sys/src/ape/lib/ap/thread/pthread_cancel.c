#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include "lib.h"

int
pthread_setcanceltype(int type, int *oldtype)
{
	Thread *priv;
	pthread_t pid;

	pid = pthread_self();
	priv = _pthreadnew(pid);
	if(priv == NULL)
		return ENOMEM;
	lock(&priv->l);
	if(oldtype)
		*oldtype = priv->canceltype;
	priv->canceltype = type;
	unlock(&priv->l);
	return 0;
}

int
pthread_cancel(pthread_t t)
{
	Thread *priv;

	priv = _pthreadget(t);
	if(priv == NULL)
		return ESRCH;
	lock(&priv->l);
	priv->cancelled = 1;
	if(priv->state == PTHREAD_CANCEL_ENABLE
	   && priv->canceltype == PTHREAD_CANCEL_ASYNCHRONOUS) {
		unlock(&priv->l);
		kill((pid_t)t, SIGTERM);
		return 0;
	}
	unlock(&priv->l);
	return 0;
}

void
pthread_testcancel(void)
{
	Thread *priv;
	pthread_t pid;

	pid = pthread_self();
	priv = _pthreadget(pid);
	if(priv == NULL)
		return;
	lock(&priv->l);
	if(priv->state == PTHREAD_CANCEL_ENABLE && priv->cancelled) {
		unlock(&priv->l);
		pthread_exit(PTHREAD_CANCELED);
	}
	unlock(&priv->l);
}
