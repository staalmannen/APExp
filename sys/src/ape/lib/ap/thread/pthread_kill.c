#include <pthread.h>
#include <signal.h>
#include <errno.h>

/*
 * pthread_kill — send signal to a thread
 *
 * On Plan9, threads are processes; pthread_t is pid_t.
 * Delegating to kill() is the correct implementation.
 * sig==0 performs existence check without delivering a signal.
 */
int
pthread_kill(pthread_t t, int sig)
{
	if(kill((pid_t)t, sig) < 0)
		return errno;
	return 0;
}
