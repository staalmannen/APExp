#ifndef __TYPES_H
#define __TYPES_H

#include <_apetypes.h>
#include <stddef_arch.h>

#pragma lib "/$M/lib/ape/libap.a"

/* Also in <sys/time.h> and <sys/select.h>, under the same guard; see
   the note beside struct timeval for why it is long. */
#ifndef __suseconds_t_defined
#define __suseconds_t_defined
typedef long		suseconds_t;
#endif

typedef	unsigned short	ino_t;
typedef	unsigned short	dev_t;
typedef	long long		off_t;
typedef long long		off64_t;
typedef unsigned short	mode_t;
typedef short		uid_t;
typedef short		gid_t;
typedef short		nlink_t;
typedef int		pid_t;
typedef unsigned char	u_char;
typedef unsigned short	u_short;
typedef unsigned int	u_int;
typedef unsigned long	u_long;
typedef unsigned int	in_addr_t;
typedef long      blksize_t;   /* preferred I/O block size */
typedef long long blkcnt_t;    /* count of file system blocks */

/*
 * The rest of the POSIX <sys/types.h> set. These used to be in
 * <alltypes.h> alone, which is not a header anyone includes by name, so
 * portable code that spelled one of them could not find it. blksize_t
 * and blkcnt_t were in both -- the spellings happened to agree.
 */
typedef unsigned long long fsblkcnt_t;	/* file system block count */
typedef unsigned long long fsfilcnt_t;	/* file system inode count */
typedef unsigned	id_t;		/* uid_t or gid_t or pid_t */
typedef int		key_t;		/* System V IPC key */
typedef unsigned	useconds_t;	/* microseconds, for usleep */

#ifndef _SIZE_T
#define _SIZE_T
#ifdef _BITS64
typedef unsigned long long size_t;
#else
typedef unsigned long size_t;
#endif
#endif

#ifndef _SSIZE_T
#define _SSIZE_T
#ifdef _BITS64
typedef long long ssize_t;
#else
typedef long ssize_t;
#endif
#endif

#ifndef _TIME_T
#define _TIME_T
typedef long long time_t;
#endif

#ifndef _CLOCKID_T
#define _CLOCKID_T
typedef int clockid_t;
#endif


#ifndef _CADDR_T
#define _CADDR_T
typedef char * caddr_t;
#endif
#ifndef _FD_SET_T
#define _FD_SET_T
/* also cf <select.h> */
typedef struct fd_set {
	long fds_bits[3];
} fd_set;
#define FD_SET(n,p)	((p)->fds_bits[(n)>>5] |= (1 << ((n) &0x1f)))
#define FD_CLR(n,p)	((p)->fds_bits[(n)>>5] &= ~(1 << ((n) &0x1f)))
#define FD_ISSET(n,p)	((p)->fds_bits[(n)>>5] & (1 << ((n) &0x1f)))
#define FD_ZERO(p)	((p)->fds_bits[0] =0, (p)->fds_bits[1] =0, (p)->fds_bits[2] =0)
#ifndef FD_SETSIZE
#define FD_SETSIZE	96
#endif
#endif

#endif /* __TYPES_H */
