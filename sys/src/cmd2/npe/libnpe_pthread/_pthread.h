#include "pthread.h"

typedef struct npe_pthread_t npe_pthread_t;

struct pthread_attr_t {
	unsigned stack_size;
};

struct npe_pthread_t {
	void *waitchan;
	void *(*func)(void*);
	void *arg;
	int pid;
};
