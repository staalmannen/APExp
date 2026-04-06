/* sys/src/ape/lib/ap/stdio/ofl.c */
#include "stdio_impl.h"
#include <pthread.h>

static FILE *ofl_head;
static pthread_mutex_t ofl_lock = PTHREAD_MUTEX_INITIALIZER;
volatile int *const __stdio_ofl_lockptr = (volatile int *)&ofl_lock;

FILE **__ofl_lock()
{
	pthread_mutex_lock(&ofl_lock);
	return &ofl_head;
}

void __ofl_unlock()
{
	pthread_mutex_unlock(&ofl_lock);
}

