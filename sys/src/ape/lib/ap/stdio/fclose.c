#include "stdio_impl.h"
#include <stdlib.h>
#include <unistd.h>

/*
 * F_PERM says the FILE itself is static and must not be freed. It does
 * not mean the file stays open.
 *
 * This used to return early for a permanent stream:
 *
 *	if (f->flags & F_PERM) {
 *		if (fflush(f) == EOF) error = EOF;
 *		return error;
 *	}
 *
 * so fclose(stdout) flushed and left descriptor 1 open. C99 7.19.5.1
 * has no exemption for the standard streams: fclose "causes the stream
 * to be flushed and the associated file to be closed". musl calls the
 * close hook unconditionally and skips only the free.
 *
 * Closing stdout is how a program at the head of a pipeline says it is
 * done -- the reader gets end of file. flex's cleanup path is
 *
 *	fflush (stdout);
 *	fclose (stdout);
 *	while (wait (&child_status) > 0) ...
 *
 * and its output goes through a chain of filter processes, so with the
 * descriptor still open the first filter never saw end of file, nothing
 * downstream could finish, and flex waited for children that could not
 * exit. lex.yy.c was complete on disk and the build simply stopped:
 *
 *	flex  Await		(the parent, in wait())
 *	flex  Pread		(filter_tee_header)
 *	flex  Pread		(filter_fix_linedirs)
 */
int fclose(FILE *f){
	FILE **head;
	int error, perm;

	if(!f) return EOF;

	error = 0;
	perm = f->flags & F_PERM;

	/* Remove heap streams from the global open-file list before any
	 * flushing or close hooks run.  __stdio_exit() walks this list, so a
	 * closed stream must never remain linked if later cleanup allocates or
	 * frees memory.
	 */
	if(!perm){
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

	if(fflush(f) == EOF) error = EOF;

	/* Close the underlying fd (and destroy the mutex). __stdio_close
	 * sets f->fd to -1, so the fallback below does not double close;
	 * it is there for streams with no close hook. */
	if(f->close && f->close(f) < 0)
		error = EOF;

	if(f->fd >= 0){
		if(close(f->fd) < 0) error = EOF;
		f->fd = -1;
	}

	/* A permanent stream keeps its FILE -- it is static, and the
	 * standard stream pointers still refer to it. */
	if(perm)
		return error;

	/* Free a setvbuf-allocated buffer */
	if(f->buf && (f->flags & F_SVB)){
		free(f->buf);
		f->buf = NULL;
	}

	f->flags = 0;

	/* Free the FILE struct itself (not F_PERM, so it was heap-allocated) */
	free(f);

	return error;
}
