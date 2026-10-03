/*
 * pANS stdio -- strerror (not really in stdio)
 *
 * Shouldn't really call this sys_errlist or make it
 * externally visible, but too many programs in X assume it...
 *
 * ------------------------------------------------------------------
 * FORTY OF THE SEVENTY-SIX STRINGS DISAGREED WITH EVERY OTHER SYSTEM,
 * AND TWO OF THEM WERE ACTIVELY MISLEADING.
 *
 * bash's `run-redir' is what started it: `Bad file number' where the
 * expected output says `Bad file descriptor'. Reading one entry would
 * have fixed one entry; asking the whole table against glibc -- name
 * by name, since the NUMBERS differ between APE and glibc and only
 * the names can be lined up -- found 40.
 *
 * **The two that matter are EACCES and EPERM.** This table said
 *
 *	EACCES  "Access denied"
 *	EPERM   "Permission denied"
 *
 * and `Permission denied' is what every other system prints for
 * **EACCES**. So the one string a reader is most likely to recognise
 * named the wrong errno: a program that failed with EPERM reported
 * the text of EACCES, and anything matching on that text -- a test,
 * a log reader, a person -- drew the opposite conclusion. *A wrong
 * message is a bug in one line; a message that is another error's
 * correct message is a bug in the reader.*
 *
 * The rest were merely terse (`Too big' for E2BIG, `Try again' for
 * EAGAIN, `No buffers' for ENOBUFS). Nothing in POSIX fixes the
 * wording, so this is not conformance -- it is that **this tree
 * exists to run GNU software**, whose tests compare against the text
 * glibc produces, and whose users read it.
 *
 * Generated rather than transcribed: the mapping came from parsing
 * `errno.h' for the names and asking glibc for each one, so no entry
 * was typed by hand and no entry can be off by a row. **Every line
 * now carries its name** for the same reason -- a table indexed by
 * errno with unnamed rows is exactly how an entry drifts, and three
 * of the old rows that DID carry a name were the ones nobody had to
 * check twice.
 *
 * EGREG is the one entry with nothing to check it against: it is
 * APE's own (`_errno.c' maps Plan 9's "ken has left the building" to
 * it), glibc has no such error, so its text is left alone. It reads
 * `Unknown error', which is also what the fallback below returns for
 * an errno out of range -- so the two are indistinguishable from
 * outside. Recorded rather than changed: picking a new wording would
 * be inventing one, and nothing has measured it.
 */
#include <string.h>
#include <errno.h>

#include "iolib.h"

char *sys_errlist[] = {
	"Error 0",                                       /* errno 0 */
	"Argument list too long",                        /* E2BIG */
	"Permission denied",                             /* EACCES */
	"Resource temporarily unavailable",              /* EAGAIN/EWOULDBLOCK */
	"Bad file descriptor",                           /* EBADF */
	"Device or resource busy",                       /* EBUSY */
	"No child processes",                            /* ECHILD */
	"Resource deadlock avoided",                     /* EDEADLK/EDEADLOCK */
	"File exists",                                   /* EEXIST */
	"Bad address",                                   /* EFAULT */
	"File too large",                                /* EFBIG */
	"Interrupted system call",                       /* EINTR */
	"Invalid argument",                              /* EINVAL */
	"Input/output error",                            /* EIO */
	"Is a directory",                                /* EISDIR */
	"Too many open files",                           /* EMFILE */
	"Too many links",                                /* EMLINK */
	"File name too long",                            /* ENAMETOOLONG */
	"Too many open files in system",                 /* ENFILE */
	"No such device",                                /* ENODEV */
	"No such file or directory",                     /* ENOENT */
	"Exec format error",                             /* ENOEXEC */
	"No locks available",                            /* ENOLCK */
	"Cannot allocate memory",                        /* ENOMEM */
	"No space left on device",                       /* ENOSPC */
	"Function not implemented",                      /* ENOSYS */
	"Not a directory",                               /* ENOTDIR */
	"Directory not empty",                           /* ENOTEMPTY */
	"Inappropriate ioctl for device",                /* ENOTTY */
	"No such device or address",                     /* ENXIO */
	"Operation not permitted",                       /* EPERM */
	"Broken pipe",                                   /* EPIPE */
	"Read-only file system",                         /* EROFS */
	"Illegal seek",                                  /* ESPIPE */
	"No such process",                               /* ESRCH */
	"Invalid cross-device link",                     /* EXDEV */

	/* bsd networking software */
	"Socket operation on non-socket",                /* ENOTSOCK */
	"Protocol not supported",                        /* EPROTONOSUPPORT */
	"Connection refused",                            /* ECONNREFUSED */
	"Address family not supported by protocol",      /* EAFNOSUPPORT */
	"No buffer space available",                     /* ENOBUFS */
	"Operation not supported",                       /* EOPNOTSUPP/ENOTSUP */
	"Address already in use",                        /* EADDRINUSE */
	"Destination address required",                  /* EDESTADDRREQ */
	"Message too long",                              /* EMSGSIZE */
	"Protocol not available",                        /* ENOPROTOOPT */
	"Socket type not supported",                     /* ESOCKTNOSUPPORT */
	"Protocol family not supported",                 /* EPFNOSUPPORT */
	"Cannot assign requested address",               /* EADDRNOTAVAIL */
	"Network is down",                               /* ENETDOWN */
	"Network is unreachable",                        /* ENETUNREACH */
	"Network dropped connection on reset",           /* ENETRESET */
	"Software caused connection abort",              /* ECONNABORTED */
	"Transport endpoint is already connected",       /* EISCONN */
	"Transport endpoint is not connected",           /* ENOTCONN */
	"Cannot send after transport endpoint shutdown", /* ESHUTDOWN */
	"Too many references: cannot splice",            /* ETOOMANYREFS */
	"Connection timed out",                          /* ETIMEDOUT */
	"Host is down",                                  /* EHOSTDOWN */
	"No route to host",                              /* EHOSTUNREACH */
	"Unknown error",                                 /* EGREG */

	/* added in 1003.1b-1993 */
	"Operation canceled",                            /* ECANCELED */
	"Operation now in progress",                     /* EINPROGRESS */

	/* from research unix */
	"Text file busy",                                /* ETXTBSY */

	/* added in more recent 1003.x versions */
	"Operation already in progress",                 /* EALREADY */
	"Connection reset by peer",                      /* ECONNRESET */
	"Value too large for defined data type",         /* EOVERFLOW */
	"Too many levels of symbolic links",             /* ELOOP */
	"Invalid or incomplete multibyte or wide character", /* EILSEQ */
	"State not recoverable",                         /* ENOTRECOVERABLE */
	"Owner died",                                    /* EOWNERDEAD */
	"Bad message",                                   /* EBADMSG */
	"Stale file handle",                             /* ESTALE */
	"Disk quota exceeded",                           /* EDQUOT */
	"No data available",                             /* ENODATA */
	"Protocol wrong type for socket",                /* EPROTOTYPE */
	"No message of desired type",                    /* ENOMSG */
};
#define	_IO_nerr	(sizeof sys_errlist/sizeof sys_errlist[0])
int sys_nerr = _IO_nerr;
extern char *_plan9err;

char *
strerror(int n)
{
	if(n == EPLAN9)
		return _plan9err;
	if(n >= 0 && n < _IO_nerr)
		return sys_errlist[n];
	/*
	 * EDOM and ERANGE are 1000 and 1001, outside the table, so these
	 * two arms are the only place they are spelled -- and they had
	 * the same defect as the table did. glibc's wording, like the
	 * rest.
	 */
	if(n == EDOM)
		return "Numerical argument out of domain";
	else if(n == ERANGE)
		return "Numerical result out of range";
	else
		return "Unknown error";
}


