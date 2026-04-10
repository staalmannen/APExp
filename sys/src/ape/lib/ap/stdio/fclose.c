#include "stdio_impl.h"

int fclose(FILE *f){
	if(!f) return EOF;

	int error = 0;

	/* Permanent streams (stdin/stdout/stderr have F_PERM): just flush,
	 * do not close the fd or free memory. */
	if (f->flags & F_PERM) {
		if (fflush(f) == EOF) error = EOF;
		return error;
	}

	if(fflush(f)==EOF) error=EOF;

	/* Free a setvbuf-allocated buffer */
	if(f->buf && (f->flags & F_SVB)){
		free(f->buf);
		f->buf = NULL;
	}

	/* Close the underlying fd (and destroy the mutex) */
	if(f->close && f->close(f) < 0)
		error = EOF;

	/* close(2) is done by __stdio_close; skip duplicate for fmemopen etc. */
	if(f->fd >= 0){
		if(close(f->fd) < 0) error = EOF;
		f->fd = -1;
	}

	f->flags = 0;

	/* Free the FILE struct itself (not F_PERM, so it was heap-allocated) */
	free(f);

	return error;
}
