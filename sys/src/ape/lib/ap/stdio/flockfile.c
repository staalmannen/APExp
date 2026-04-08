#include "stdio_impl.h"

void flockfile(FILE *f) {
	if (f->lock < 0) return;
	__lockfile(f);
}

void funlockfile(FILE *f) {
	if (f->lock < 0) return;
	__unlockfile(f);
}

int ftrylockfile(FILE *f) {
	pthread_mutex_t *lock;
	if (f->lock < 0) return 0;
	lock = (pthread_mutex_t *)(intptr_t)f->lock;
	if (!lock) return 0;
	return pthread_mutex_trylock(lock) ? 1 : 0;
}
