#include "stdio_impl.h"

int fflush(FILE *f){
	if(f==NULL){
		int error = 0;
		/* Flush stdout and stderr (static files, not in OFL list) */
		FILE *sfiles[] = { stdout, stderr, NULL };
		for (int i = 0; sfiles[i]; i++) {
			FILE *sf = sfiles[i];
			if (sf->wpos > sf->wbase) {
				sf->write(sf, 0, 0);
				if (sf->flags & F_ERR) error = EOF;
			}
		}
		/* Flush all dynamically opened files via OFL list */
		FILE **flp = __ofl_lock();
		for (FILE *g = *flp; g; g = g->next) {
			if (g->wpos > g->wbase) {
				g->write(g, 0, 0);
				if (g->flags & F_ERR) error = EOF;
			}
		}
		__ofl_unlock();
		return error;
	}

	_FLOCK(f);

	if (f->wpos > f->wbase) {
		/* Flush-signal: write function flushes pending wbase..wpos internally */
		f->write(f, 0, 0);
		if (f->flags & F_ERR) {
			_FUNLOCK(f);
			return EOF;
		}
	}

	_FUNLOCK(f);
	return 0;
}

