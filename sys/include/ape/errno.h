#ifndef __ERRNO
#define __ERRNO
#pragma lib "/$M/lib/ape/libap.a"

extern int *_errnoloc;
#define errno (*_errnoloc)

#define EDOM	1000
#define ERANGE	1001
#define EPLAN9	1002

#define E2BIG	1
#define EACCES	2
#define	EAGAIN	3
#define EWOULDBLOCK	3
#define EBADF	4
#define EBUSY	5
#define ECHILD	6
#define EDEADLK	7
#define EEXIST	8
#define EFAULT	9
#define EFBIG	10
#define EINTR	11
#define EINVAL	12
#define EIO	13
#define EISDIR	14
#define EMFILE	15
#define EMLINK	16
#define ENAMETOOLONG	17
#define ENFILE	18
#define ENODEV	19
#define ENOENT	20
#define ENOEXEC	21
#define ENOLCK	22
#define ENOMEM	23
#define ENOSPC	24
#define ENOSYS	25
#define ENOTDIR	26
#define ENOTEMPTY	27
#define ENOTTY	28
#define ENXIO	29
#define EPERM	30
#define EPIPE	31
#define EROFS	32
#define ESPIPE	33
#define ESRCH	34
#define EXDEV	35

/* bsd networking software */
#define ENOTSOCK	36
#define EPROTONOSUPPORT	37
#define EPROTOTYPE	37	/* two names for 37 */
#define ECONNREFUSED	38
#define EAFNOSUPPORT	39
#define ENOBUFS		40
#define EOPNOTSUPP	41
#define ENOTSUP EOPNOTSUPP   /* alias is acceptable */
#define EADDRINUSE	42
#define EDESTADDRREQ	43
#define EMSGSIZE	44
#define ENOPROTOOPT	45
#define ESOCKTNOSUPPORT	46
#define EPFNOSUPPORT	47
#define EADDRNOTAVAIL	48
#define ENETDOWN	49
#define ENETUNREACH	50
#define ENETRESET	51
#define ECONNABORTED	52
#define EISCONN		53
#define ENOTCONN	54
#define ESHUTDOWN	55
#define ETOOMANYREFS	56
#define ETIMEDOUT	57
#define EHOSTDOWN	58
#define EHOSTUNREACH	59
#define EGREG		60

/* temporary redefinitions */
#define ENOMSG ENOENT


/* These added in 1003.1b-1993 */
#define ECANCELED	61
#define EINPROGRESS	62

/* from research unix */
#define ETXTBSY	63

/* Added in more recent 1003.x versions */
#define EALREADY	64
#define ECONNRESET	65

#define EOVERFLOW	66
#define ELOOP		67

#define EILSEQ  68

#define ENOTRECOVERABLE 69
#define EOWNERDEAD      70

#define EBADMSG		71

/*
 * Nothing in APE ever sets this -- Plan 9 has no NFS client whose
 * handles can go stale.  It is here because POSIX requires the name and
 * portable code tests for it unguarded: gnulib's savewd.c has
 *
 *	bool try_fork = errno == EACCES || errno == ESTALE;
 *
 * with no #ifdef.  Defining it to a value errno never takes gives that
 * test the right answer.
 */
#define ESTALE		72

/*
 * Like ESTALE: no APE call sets these, but portable code tests for them
 * without an #ifdef and needs the names.  coreutils' copy.c and ln.c
 * classify link(2) and copy_file_range(2) failures with EDQUOT, and its
 * selinux.c, ls.c and chcon.c with ENODATA -- coreutils' own system.h
 * falls back to "#define ENODATA (-1)", which then aliases ENODATA onto
 * a value no errno ever has, in a different way, less visibly.
 */
#define EDQUOT		73
#define ENODATA		74

/* glibc spells EDEADLK this way too; coreutils' getlimits.c prints it
 * under "#if defined EDEADLOCK && EDEADLOCK == EDEADLK". */
#define EDEADLOCK	EDEADLK


#endif /* __ERRNO */
