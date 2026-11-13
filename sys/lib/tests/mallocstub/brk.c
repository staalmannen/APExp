/*
 * brk.c -- a fake Plan 9 break for the host build of libap's allocator.
 *
 * Compiled WITHOUT the -D renames, so the name it defines is spelled
 * `ap_sbrk' here, exactly as the renamed allocator will call it.
 *
 * ***IT MUST NOT BE CALLED `sbrk' AND IT MUST NOT USE `malloc'.***
 * A strong definition of `sbrk' would be taken by GLIBC's allocator as
 * well, which calls it; and reserving the arena with `malloc' would
 * have glibc's allocator call back into the very function being
 * defined.  Either way two allocators end up sharing one break, which
 * is a different experiment and one whose failures could not be
 * attributed to either.  A plain BSS array has neither problem: the
 * host commits it lazily, so 512MB of it costs nothing until touched.
 *
 * ***WHAT THIS FAKE CANNOT SAY***, stated where the fake is rather
 * than only in the cross-check's header: this break always succeeds,
 * is always contiguous, and is never moved by anyone else.  The real
 * one is a segment that can refuse, and `_malloc_growtop's whole
 * correctness rests on `sbrk(0)' telling the truth about a break
 * something else may have moved.  **So a clean run clears the
 * allocator's arithmetic and not the platform underneath it.**
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BRKSZ ((size_t)512 * 1024 * 1024)

static char arena[BRKSZ];

/*
 * Starts MISALIGNED by 8 deliberately.  `_malloc_brk' aligns the break
 * itself with `gap = (-cur) & 15', and a fake break that happened to
 * start 16-aligned would never exercise the gap -- a check that cannot
 * fail.
 */
static size_t used = 8;

void *
ap_sbrk(unsigned long n)
{
	char *p;

	if(used + n > BRKSZ)
		return (void *)-1;
	p = arena + used;
	used += n;
	return p;
}

void
ap_brk_reset(void)
{
	used = 8;
}

size_t
ap_brk_used(void)
{
	return used;
}

/*
 * malloc.c's watchdog calls these on the $APEXP_MALLOCMAX path only,
 * which this cross-check never arms.  They exist so the link succeeds;
 * if either is ever REACHED the run has gone somewhere the cross-check
 * does not model, so each says so loudly instead of pretending.
 */
void
_EXITS(char *s)
{
	fprintf(stderr, "brk.c: _EXITS(%s) reached -- the watchdog fired, "
		"which this cross-check does not model\n", s ? s : "nil");
	exit(3);
}

int
_SLEEP(long ms)
{
	fprintf(stderr, "brk.c: _SLEEP(%ld) reached -- the watchdog fired, "
		"which this cross-check does not model\n", ms);
	exit(3);
}
