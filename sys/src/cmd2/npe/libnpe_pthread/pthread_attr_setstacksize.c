#include "_pthread.h"

int
pthread_attr_setstacksize(pthread_attr_t *const attr, const int stack_size)
{
	attr->stack_size = stack_size;
	return 0;
}
