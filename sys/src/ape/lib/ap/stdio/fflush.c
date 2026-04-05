#include "stdio_impl.h"

int fflush(FILE *f){
	if(f==NULL){
		int error = 0;
		/* Flush all open files via __ofl interface */
		FILE **flp = __ofl_lock();
		for (FILE *g = *flp; g; g = g->next_locked) {
			if (g->wpos > g->wbase) {
				if (__fwritex((unsigned char *)g->wbase, g->wpos - g->wbase, g)
					!= (size_t)(g->wpos - g->wbase)) {
					error = EOF;
				}
			}
		}
		__ofl_unlock();
		return error;
	}

	FLOCK(f);

	if (f->wpos > f->wbase) {
		if (f->write(f, (unsigned char *)f->wbase, f->wpos - f->wbase)
			!= (size_t)(f->wpos - f->wbase)) {
			f->flags |= F_ERR;
			FUNLOCK(f);
			return EOF;
		}
	}

	FUNLOCK(f);
	return 0;
}

