#include <unistd.h>
#include "../plan9/lib.h"

/*
 * getdtablesize - return maximum number of open file descriptors.
 * Plan9 does not have a hard per-process fd limit comparable to
 * OPEN_MAX; we return FOPEN_MAX from stdio.h as a reasonable bound.
 */
int
getdtablesize(void)
{
	return sysconf(_SC_OPEN_MAX);
}
