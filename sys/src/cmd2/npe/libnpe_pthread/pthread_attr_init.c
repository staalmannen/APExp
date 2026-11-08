#include "_pthread.h"

int
pthread_attr_init(pthread_attr_t *const attr)
{
	attr->stack_size = 0;
	return 0;
}
