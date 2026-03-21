#include "lib.h"
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include "sys9.h"
#include "dir.h"

/*
 * telldir - return current position in directory stream
 *
 * Plan9 directories are not seekable in the traditional sense —
 * _SEEK on a directory fd is only reliable to position 0 (rewind).
 * We therefore track position as an entry count (ordinal) rather
 * than a byte offset, which is what POSIX actually requires
 * (seekdir/telldir values are opaque cookies, not byte offsets).
 *
 * The position is the total number of dirent entries returned so
 * far, maintained in d->dd_seek which we add to DIR for this purpose.
 * If your dirent.h does not have dd_seek, see note below.
 */
long
telldir(DIR *d)
{
	if(d == NULL){
		errno = EBADF;
		return -1;
	}
	return d->dd_seek;
}

/*
 * seekdir - set position in directory stream
 *
 * POSIX only guarantees that seekdir works with values previously
 * returned by telldir. We implement this by rewinding and replaying
 * readdir() calls up to the saved position, which is correct if
 * slightly expensive for large directories.
 *
 * This matches the behaviour of most BSD/musl implementations on
 * filesystems that don't support arbitrary directory seeks.
 */
void
seekdir(DIR *d, long pos)
{
	long i;

	if(d == NULL)
		return;

	/* rewind unconditionally */
	rewinddir(d);

	/* replay readdir() calls to reach saved position */
	for(i = 0; i < pos; i++){
		if(readdir(d) == NULL)
			break;
	}
	/* d->dd_seek is updated by readdir via the wrapper in opendir.c */
}
