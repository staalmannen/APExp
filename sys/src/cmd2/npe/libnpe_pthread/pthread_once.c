#include <npe.h>
#include <pthread.h>
#include "_pthread.h"

enum {
	Done = 13666,
};

int
pthread_once(pthread_once_t *once, void (*init_routine)(void))
{
	if(once->done != Done){
		qlock(once);
		if(once->done != Done){
			once->done = Done;
			init_routine();
		}
		qunlock(once);
	}

	return 0;
}
