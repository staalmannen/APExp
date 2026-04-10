#include "stdio_impl.h"

int fflush(FILE *f){
	if(f==NULL){
		int error = 0;
		/* Flush all open files via __ofl interface */
		FILE **flp = __ofl_lock();
		for (FILE *g = *flp; g; g = g->next_locked) {
			if (g->wpos > g->wbase) {
				/* Call write(f,0,0) — the musl flush-signal convention.
				 * The write function (e.g. __stdio_write, mwrite) flushes
				 * wbase..wpos internally. Passing wbase+count would double-write. */
				g->write(g, 0, 0);
				if (g->flags & F_ERR) error = EOF;
			}
		}
		__ofl_unlock();
		return error;
	}

	FLOCK(f);

	if (f->wpos > f->wbase) {
		/* Flush-signal: write function flushes pending wbase..wpos internally */
		f->write(f, 0, 0);
		if (f->flags & F_ERR) {
			FUNLOCK(f);
			return EOF;
		}
	}

	FUNLOCK(f);
	return 0;
}

