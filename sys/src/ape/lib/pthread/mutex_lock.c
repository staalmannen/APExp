#include <pthread.h>

int
pthread_mutex_lock(pthread_mutex_t *mutex)
{
	pthread_t pid;

	pid = pthread_self();
	lock(&mutex->mu);
	if(mutex->attr == PTHREAD_MUTEX_RECURSIVE && mutex->pid == pid){
		mutex->ref++;
		unlock(&mutex->mu);
		return 0;
	}
	unlock(&mutex->mu);

	qlock(&mutex->l);
	lock(&mutex->mu);
	mutex->pid = pid;
	mutex->ref++;
	unlock(&mutex->mu);
	return 0;
}
