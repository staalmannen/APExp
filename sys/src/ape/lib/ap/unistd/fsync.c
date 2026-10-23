#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include "lib.h"

/*
 * fsync -- IT USED TO BE `errno = EINVAL; return -1;', AND THAT IS THE
 * stub-answers-FAILURE BUG, which is the commonest one in this tree.
 *
 * A stub that says "I failed" is not a stub that says "there was
 * nothing to do", and here the difference destroyed files.
 *
 * WHAT IT COST.  `unxz /tmp/t.xz' decompressed correctly and then
 * printed
 *
 *	unxz: /tmp/t: Synchronizing the file failed: Invalid argument
 *
 * and **deleted the output it had just written**.  xz's
 * `io_sync_dest' (`src/xz/file_io.c:484') calls `fsync(pair->dest_fd)'
 * and turns any nonzero return into `success = false'
 * (`file_io.c:1207'); `io_close_dest(pair, false)' then REMOVES the
 * destination.  `opt_synchronous' is `true' by default
 * (`src/xz/args.c:24'), so this was every `xz'/`unxz' on a named file,
 * every time -- the data was correct, written, and thrown away on the
 * way out.  *The error message named the sync and the user lost the
 * file, which is as far apart as a symptom and a cause get.*
 *
 * THE RIGHT ANSWER WAS ALREADY WRITTEN DOWN IN libap, in a second
 * place that disagreed with this one: `plan9/__p9_syscall.c:594' reads
 *
 *	case SYS_fsync:	/ * [STUB] Plan9 writes are synchronous; no-op
 *			    is correct * /
 *		return 0;
 *
 * Plan 9 has no `fsync' because a write to a file server has already
 * been acknowledged by the server when `write' returns; there is no
 * local cache for the call to flush.  **Nothing to do is not the same
 * as cannot be done.**
 *
 * The fd check is read.c's, copied rather than reinvented, because
 * POSIX does require EBADF for a descriptor that is not open and a
 * function that cannot fail at all is its own kind of lie.  Everything
 * else returns 0: POSIX permits EINVAL only for a file that does not
 * SUPPORT synchronising, and on this system every file supports it by
 * already having done it.
 */
int
fsync(int d)
{
	if(d < 0 || d >= OPEN_MAX || !(_fdinfo[d].flags & FD_ISOPEN)){
		errno = EBADF;
		return -1;
	}
	return 0;
}

/*
 * Version marker for `fsync-test.c'.  `pcc -o x x.c' relinks against
 * the INSTALLED libap, so a test built from a fresh pull can run
 * days-old library code and report on it.  A test that calls this will
 * not LINK against a libap predating the fix above.  Eleventh use of
 * the idiom.
 */
int
_syncmark(void)
{
	return 1;
}
