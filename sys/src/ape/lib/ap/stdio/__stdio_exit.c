#include "stdio_impl.h"
#include <stdio.h>

/* APExp: stdin/stdout/stderr are defined in stdin.c, stdout.c, stderr.c
 * These are just extern declarations, not definitions */

static void close_file(FILE *f)
{
	if (!f) return;

	/* Skip if already closed or invalid */
	if (f->fd < 0) return;

	/* Try to lock and flush */
	if (FFINALLOCK(f)) {
		if (f->wpos > f->wbase) {
			f->write(f, (unsigned char *)f->wbase, f->wpos - f->wbase);
		}
		__unlockfile(f);
	}
}

void __stdio_exit(void)
{
	FILE *f;
	FILE **head;

	/* Safely lock and iterate open file list */
	head = __ofl_lock();
	if (!head) return;

	for (f = *head; f; f = f->next) {
		close_file(f);
	}

	__ofl_unlock();
}

/* Alias for compatibility */
void __stdio_exit_needed(void)
{
	__stdio_exit();
}

