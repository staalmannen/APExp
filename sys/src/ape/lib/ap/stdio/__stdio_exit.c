#include "stdio_impl.h"
#include <stdio.h>

/* APExp: Replace musl weak_alias with proper extern declarations and function aliases */
FILE *volatile __stdin_used = NULL;
FILE *volatile __stdout_used = NULL;
FILE *volatile __stderr_used = NULL;

static void close_file(FILE *f)
{
	if (!f) return;
	FFINALLOCK(f);
	if (f->wpos > f->wbase) {
		f->write(f, (unsigned char *)f->wbase, f->wpos - f->wbase);
	}
	if (f->rpos != f->rend) {
		f->seek(f, f->rpos - f->rend, SEEK_CUR);
	}
}

void __stdio_exit(void)
{
	FILE *f;
	FILE **head = __ofl_lock();

	/* Close all files in open file list */
	for (f = *head; f; f = f->next) {
		close_file(f);
	}

	__ofl_unlock();

	/* Close standard streams if they exist */
	close_file(__stdin_used);
	close_file(__stdout_used);
	close_file(__stderr_used);
}

/* Alias for compatibility */
void __stdio_exit_needed(void)
{
	__stdio_exit();
}

