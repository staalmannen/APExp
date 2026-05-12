#include "stdio_impl.h"

int fclose(FILE *f){
	FILE **head;
	int error;

	if(!f) return EOF;

	error = 0;

	/* Remove heap streams from the global open-file list before any
	 * flushing or close hooks run.  __stdio_exit() walks this list, so a
	 * closed stream must never remain linked if later cleanup allocates or
	 * frees memory.
	 */
	if (!(f->flags & F_PERM)) {
		head = __ofl_lock();
		if (*head == f)
			*head = f->next;
		if (f->prev)
			f->prev->next = f->next;
		if (f->next)
			f->next->prev = f->prev;
		f->prev = f->next = NULL;
		__ofl_unlock();
	}

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
