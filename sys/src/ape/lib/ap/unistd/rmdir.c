#include "lib.h"
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "sys9.h"

/*
 * POSIX requires ENOTEMPTY (or EEXIST) when a directory cannot be
 * removed because it still has something in it, and callers branch on
 * exactly that. Tcl's DoRemoveDirectory is the case that found this:
 *
 *	if (rmdir(path) == 0) return TCL_OK;
 *	if (errno == ENOTEMPTY) errno = EEXIST;
 *	if ((errno != EEXIST) || (recursive == 0)) goto end;
 *	... otherwise delete the contents and try again ...
 *
 * so an unrecognised errno is not a worse message, it is a `file delete
 * -force` that does not recurse at all.
 *
 * WHAT THIS MACHINE SAYS, measured by sys/lib/tests/rmdir-test.c rather
 * than assumed:
 *
 *	rmdir of a non-empty directory -> errno 1002 (invalid operation)
 *	                                  plan 9 says: invalid operation
 *
 * `invalid operation` is in no table in `_errno.c`, so `_syserrno()`
 * falls back to EPLAN9 and Tcl reported `POSIX {unknown error}`. It then
 * gave up instead of recursing, `fCmd-20.1` left its directory behind,
 * and the NEXT test's cleanup -- `while {[catch {file delete -force
 * tfa}]} {}`, upstream's own, unbounded and with no delay -- spun at
 * full CPU for ever and took the whole suite with it.
 *
 * DELIBERATELY NOT AN ENTRY IN `_errno.c`. `invalid operation` is a
 * generic 9P error with no single POSIX meaning: a write of a control
 * message a device does not accept reports it too, and answering
 * "Directory not empty" there would be a wrong answer in a confident
 * voice. It is also the case the errno table's own warning covers --
 * naming a string there changes control flow, because `bind()` gates
 * its announce fallback on `errno == EPLAN9`.
 *
 * So the question is asked where the answer is knowable: if the remove
 * failed and libap could not name the error, LOOK, and say ENOTEMPTY
 * only when the directory really does still have something in it. That
 * holds on any file server, whatever string it chooses.
 */
static int
notempty(const char *path)
{
	DIR *d;
	struct dirent *e;
	int n;

	if((d = opendir(path)) == 0)
		return 0;
	n = 0;
	while((e = readdir(d)) != 0){
		/* Plan 9 directories hold no . or .. , but skip them anyway */
		if(strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0)
			continue;
		n = 1;
		break;
	}
	closedir(d);
	return n;
}

int
rmdir(const char *path)
{
	int e;

	if(_REMOVE(path) >= 0)
		return 0;
	_syserrno();
	e = errno;
	if(e == EPLAN9 && notempty(path))
		e = ENOTEMPTY;
	errno = e;
	return -1;
}
