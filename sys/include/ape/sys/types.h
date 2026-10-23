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

/*
 * ino_t AND dev_t WERE `unsigned short' UNTIL 0.6, AND A PLAN 9 QID
 * PATH IS 64 BITS.  `_dirtostat' assigns `st_ino = d->qid.path', so
 * every inode was that path truncated to sixteen bits, and two
 * unrelated files became THE SAME FILE to anything that identifies one
 * by dev+ino -- which is `same_file' in diffutils (so `cmp' and `diff'),
 * `find's loop detection, `du's hard-link accounting, `fts', `tar', and
 * libap's own `_sock_listenpid.c', keyed on dev/ino precisely because a
 * descriptor NUMBER is retired by `dup2()'.
 *
 * **THE PIGEONHOLE IS 65536 AND THE APExp TREE IS 64799 FILES.** That
 * is not a bound being quoted at a hypothetical filesystem: the
 * repository is about one percent short of guaranteeing a collision
 * inside itself, and any file server holding it beside anything else is
 * already past.  *A field that cannot hold the value it is assigned is
 * not a narrow field, it is a wrong answer waiting for a big enough
 * directory.*
 *
 * dev_t widens WITH it rather than for its own sake: `st_rdev' is a
 * `dev_t' and now carries the qid of a character or block special, for
 * the reason `plan9/dirtostat.c' gives at length.
 *
 * THE COST IS AN ABI CHANGE: `struct stat' goes from 88 bytes to 104
 * and every field after `st_ino' moves, so every binary in the tree has
 * to be relinked.  `mk distclean' before `mk install', which 0.6
 * already required for `-J'.
 *
 * **AND IT FIXES `<sys/sysmacros.h>' ON THE WAY.** That file is musl's
 * and its `major'/`minor'/`makedev' already assume a 64-bit dev_t --
 * `(x)>>31>>1' and `<<32' -- so they have been nonsense for a 16-bit
 * one since the day they were imported, and become correct here
 * without being touched.
 */
typedef	unsigned long long	ino_t;
typedef	unsigned long long	dev_t;
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
#include <fdset_generic.h>

#endif /* __TYPES_H */
