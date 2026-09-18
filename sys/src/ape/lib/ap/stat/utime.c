#include "lib.h"
#include <sys/types.h>
#include <time.h>
#include <utime.h>
#include <errno.h>
#include <stdlib.h>
#include "sys9.h"
#include "dir.h"

int
utime(const char *path, const struct utimbuf *times)
{
	int n;
	Dir nd;
	time_t curt;

	_nulldir(&nd);
	if(times == 0) {
		curt = time(0);
		nd.atime = curt;
		nd.mtime = curt;
	} else {
		nd.atime = times->actime;
		nd.mtime = times->modtime;
	}
	n = _dirwstat(path, &nd);
	if(n < 0){
		_syserrno();
		return -1;
	}
	/*
	 * RETURN 0, NOT `n`. `_dirwstat`/`_dirfwstat` answer the NUMBER OF
	 * BYTES the wstat message took -- 49 for a timestamp change -- and
	 * POSIX says utime returns 0 on success and -1 on failure. This
	 * used to `return n`, so every caller that writes the ordinary
	 *
	 *	if (utime(path, &tval)) { ... it failed ... }
	 *
	 * was told a successful call had failed.
	 *
	 * Found by `ratrace` on Tcl's `file copy`, which showed
	 * `Wstat ... = 49 ""` -- a success -- followed immediately by the
	 * `Stat` and `Remove` of libap's own `unlink()`. That is
	 * CopyFileAtts in tclUnixFCmd.c:
	 *
	 *	if (utime(dst, &tval)) return TCL_ERROR;
	 *
	 * and TclUnixCopyFile then deletes the copy it had just made
	 * correctly. `file copy` therefore failed on every file in the
	 * tree, which aborted encoding.test, http.test and fCmd.test and
	 * hid eighty failures behind them.
	 *
	 * The error message named none of this: Tcl reports
	 * `Tcl_PosixError` at a common label, so it printed whatever errno
	 * held by then -- the ENOENT left over from stat'ing a destination
	 * that did not exist yet.
	 */
	return 0;
}
