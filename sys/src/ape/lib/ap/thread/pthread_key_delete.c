#include <pthread.h>
#include <stdlib.h>
#include "lib.h"

int
pthread_key_delete(pthread_key_t key)
{
	/* before the free: the registry must not keep a key whose
	   arenas have gone, since pthread_exit walks it. */
	_pthreadkeyforget(key.arenas);
	free(key.arenas);
	return 0;
}
