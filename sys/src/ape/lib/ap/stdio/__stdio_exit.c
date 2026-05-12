#include "stdio_impl.h"
#include <stdio.h>

/* APExp: stdin/stdout/stderr are defined in stdin.c, stdout.c, stderr.c
 * These are just extern declarations, not definitions */

static void close_file(FILE *f)
{
	int locked;

	if (!f) return;

	/* Skip if already closed or invalid */
	if (f->fd < 0) return;

	/* Static streams use lock == -1; flush them without taking a lock. */
	locked = FFINALLOCK(f);
	if (f->wpos && f->wbase && f->wpos > f->wbase && f->write)
		f->write(f, 0, 0);
	if (locked)
		__unlockfile(f);
}

void __stdio_exit(void)
{
	FILE *f;
	FILE **head;

	/* Flush the static streams first (not in OFL list) */
	close_file(stdout);
	close_file(stderr);

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
