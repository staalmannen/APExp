#include "lib.h"
#include "sys9.h"
#include <string.h>
#include <errno.h>

/* make this global, so programs can look at it if errno is unilluminating */

/* see also: ../stdio/strerror.c, with errno-> string mapping */

extern char *_plan9err;

static struct errmap {
	int	num;
	char	*ename;
} map[] = {
	/* from /sys/src/9/port/errstr.h */
	{EINVAL,	"inconsistent mount"},
	{EINVAL,	"not mounted"},
	{EINVAL,	"not in union"},
	{EIO,		"mount rpc error"},
	{EIO,		"mounted device shut down"},
	{EPERM,	"mounted directory forbids creation"},
	{ENOENT,	"does not exist"},
	{ENXIO,	"unknown device in # filename"},
	{ENOTDIR,	"not a directory"},
	{EISDIR,	"file is a directory"},
	{EINVAL,	"bad character in file name"},
	{EINVAL,	"file name syntax"},
	/*
	 * EACCES, NOT EPERM. POSIX splits the two: EACCES is "the
	 * permission bits say no", EPERM is "you are not the owner and
	 * only the owner may do this". Plan 9's Eperm is raised by the
	 * ordinary file permission check, so it is the first of those.
	 *
	 * It was EPERM here, and Tcl's fCmd-4.11 and fCmd-6.6 are what
	 * found it: both make a directory mode 0, do something inside it,
	 * and compare the message exactly --
	 *
	 *	was:    can't create directory "td1/td2/td3": operation not permitted
	 *	wanted: can't create directory "td1/td2/td3": permission denied
	 *
	 * `wstat -- not owner' and `wstat -- not in group' below stay
	 * EPERM, which is exactly the case EPERM is for. Nothing in libap
	 * reads EPERM back out of this table -- every other use sets it
	 * directly -- so this changes a message and not a control flow;
	 * note that `bind()' gates its fallback on EPLAN9, not on this.
	 */
	{EACCES,	"permission denied"},
	{EPERM,	"inappropriate use of fd"},
	{EINVAL,	"bad arg in system call"},
	{EBUSY,	"device or object already in use"},
	{EIO,		"i/o error"},
	{EIO,		"read or write too large"},
	{EIO,		"read or write too small"},
	{EADDRINUSE,	"network port not available"},
	/*
	 * EPIPE, NOT ESHUTDOWN. These are what Plan 9 raises when the
	 * other end of a pipe or a network connection has gone away, and
	 * POSIX has one answer for all of it: a write with no reader left
	 * is EPIPE, on a pipe and on a socket alike -- Linux gives EPIPE
	 * after shutdown(SHUT_WR) too. ESHUTDOWN is a BSD name for a
	 * socket whose transport was shut down, and is not what a pipe
	 * write ever reports anywhere.
	 *
	 * The kernel posts "sys: write on closed pipe" beside this, which
	 * signal/signal.c maps to SIGPIPE, so the note half was already
	 * right and only the errno half was not.
	 *
	 * Nothing in libap reads ESHUTDOWN back out of this table, so this
	 * changes a message and not a control flow; bind()'s fallback is
	 * gated on EPLAN9, which neither errno is.
	 *
	 * Tcl's io-29.27/chan-io-29.27 are what named it: they spell the
	 * middle word of {posix epipe {broken pipe}} from errno and
	 * compare exactly. Unmeasured -- see sys/lib/tests/epipe-test.c,
	 * which asks the question without Tcl in the way.
	 */
	{EPIPE,	"write to hungup stream"},
	{EPIPE,	"i/o on hungup channel"},
	{EINVAL,	"bad process or channel control request"},
	{EBUSY,	"no free devices"},
	{ESRCH,		"process exited"},
	{ECHILD,	"no living children"},
	{EIO,		"i/o error in demand load"},
	{ENOMEM,	"virtual memory allocation failed"},
	{EBADF,	"fd out of range or not open"},
	{EMFILE,	"no free file descriptors"},
	{ESPIPE,	"seek on a stream"},
	{ENOEXEC,	"exec header invalid"},
	{ETIMEDOUT,	"connection timed out"},
	{ECONNREFUSED,	"connection refused"},
	{ECONNREFUSED,	"connection in use"},
	{EINTR,		"interrupted"},
	{ENOMEM,	"kernel allocate failed"},
	{EINVAL,	"segments overlap"},
	{EIO,		"i/o count too small"},
	{EGREG,	"ken has left the building"},
	{EINVAL,	"bad attach specifier"},

	/* from exhausted() calls in kernel */
	{ENFILE,	"no free file descriptors"},
	{EBUSY,	"no free mount devices"},
	{EBUSY,	"no free mount rpc buffer"},
	{EBUSY,		"no free segments"},
	{ENOMEM,	"no free memory"},
	{ENOBUFS,	"no free Blocks"},
	{EBUSY,	"no free routes"},

	/* from ken */
	{EINVAL,	"attach -- bad specifier"},
	{EBADF,		"unknown fid"},
	{EINVAL,	"bad character in directory name"},
	{EBADF,		"read/write -- on non open fid"},
	{EIO,		"read/write -- count too big"},
	{EIO,		"phase error -- directory entry not allocated"},
	{EIO,		"phase error -- qid does not match"},
	{EACCES,	"access permission denied"},
	{ENOENT,	"directory entry not found"},
	{EINVAL,	"open/create -- unknown mode"},
	{ENOTDIR,	"walk -- in a non-directory"},
	{ENOTDIR,	"create -- in a non-directory"},
	{EIO,		"phase error -- cannot happen"},
	{EEXIST,	"create -- file exists"},
	{EINVAL,	"create -- . and .. illegal names"},
	{ENOTEMPTY,	"directory not empty"},
	{EINVAL,	"attach -- privileged user"},
	{EPERM,		"wstat -- not owner"},
	{EPERM,		"wstat -- not in group"},
	{EINVAL,	"create/wstat -- bad character in file name"},
	{EBUSY,		"walk -- too many (system wide)"},
	{EROFS,		"file system read only"},
	{ENOSPC,	"file system full"},
	{EINVAL,	"read/write -- offset negative"},
	{EBUSY,		"open/create -- file is locked"},
	{EBUSY,		"close/read/write -- lock is broken"},

	/* from sockets */
	{ENOTSOCK,	"not a socket"},
	{EPROTONOSUPPORT,	"protocol not supported"},
	{ECONNREFUSED,	"connection refused"},
	{EAFNOSUPPORT,	"address family not supported"},
	{ENOBUFS,	"insufficient buffer space"},
	{EOPNOTSUPP,	"operation not supported"},
	{EADDRINUSE,	"address in use"},

	/*
	 * From the IP stack, and MEASURED rather than copied out of a
	 * header: sys/lib/tests/socket-server-test.c writes each spelling
	 * of an announce message to /net/tcp/clone and prints errstr for
	 * each. These two are what 9front answered.
	 *
	 * "not a local IP address" is the one that mattered. Without it
	 * the error fell through to EPLAN9 and bind.c turned that into
	 * EOPNOTSUPP, so Tcl reported "couldn't open socket: operation
	 * not supported" -- which reads as "this system has no sockets"
	 * and cost several rounds of believing exactly that. The sockets
	 * are fine; the ADDRESS was not local. EADDRNOTAVAIL is POSIX's
	 * "Cannot assign requested address" and says so.
	 *
	 * Putting them here rather than special-casing bind() is what
	 * makes connect(), sendto() and everything else report it too.
	 */
	{EADDRNOTAVAIL,	"not a local IP address"},
	{EINVAL,	"bad ip address syntax"},

	{EGREG,		"unnamed error message"},
};

#define NERRMAP	(sizeof(map)/sizeof(struct errmap))

/* convert last system call error to an errno */
void
_syserrno(void)
{
	char err[ERRMAX];
	int i;

	err[0] = 0;
	_ERRSTR(err, sizeof err);
	strncpy(_plan9err, err, sizeof err);
	_plan9err[sizeof err-1] = 0;
	errno = EPLAN9;
	for(i = 0; i < NERRMAP; i++){
		if(strstr(err, map[i].ename) != 0){
			errno = map[i].num;
			break;
		}
	}
	_ERRSTR(err, sizeof err);
}
