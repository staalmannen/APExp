#ifndef _SYS_STATVFS_H
#define _SYS_STATVFS_H
#pragma lib "/$M/lib/ape/libap.a"

/*
 * POSIX <sys/statvfs.h>.
 *
 * Plan 9 has no equivalent. A file server is reached through the
 * namespace, not through a mount table, and 9P has no operation that
 * reports block or inode counts for the file system behind a path --
 * only the per-file Dir that stat(2) returns.
 *
 * ***SO THE NUMBERS THESE REPORT ARE SYNTHETIC, AND THAT IS A
 * DELIBERATE CHOICE WITH A SWITCH.***  By default statvfs() and
 * fstatvfs() SUCCEED and report a large, recognisable amount of free
 * space (a round power of two repeated across the block fields), so
 * that the many POSIX programs which gate on free space before
 * writing continue to work.  `APEXP_STATVFS=strict' in the
 * environment restores the truthful answer, which is failure with
 * ENOSYS.
 *
 * **Neither answer is free** and `lib/ap/stat/statvfs.c' carries the
 * whole argument: ENOSYS is correct and becomes ZERO in any caller
 * that does not check -- which is how php's `disk_free_space()'
 * reported a full disk to the Phoronix Test Suite on an empty one --
 * while succeeding is a lie that costs a program checking before a
 * very large write, and that program fails at the `write' instead.
 * *Read that file before changing this behaviour.*
 *
 * The type still has to exist and be complete, because portable code
 * declares a "struct statvfs" on the stack before it ever calls
 * anything. coreutils' stat.c is the case in point: it uses statvfs
 * only for "stat -f", but the declaration and a static_assert on the
 * struct's alignment are compiled unconditionally --
 *
 *   stat.c:259 structure not fully declared statfs
 *   stat.c:880 _Alignof undefined type
 *
 * -- so without this header the whole program is lost, not just the one
 * option. With it, stat works and "stat -f" reports the error.
 *
 * f_type is not POSIX; it is here because it is the member coreutils
 * and gnulib use to identify a file system, and because a struct with
 * no way to say "unknown" is worse than one that can. It is always 0.
 */

#include <sys/types.h>	/* fsblkcnt_t, fsfilcnt_t */

struct statvfs {
	unsigned long	f_bsize;	/* file system block size */
	unsigned long	f_frsize;	/* fundamental block size */
	fsblkcnt_t	f_blocks;	/* blocks, in f_frsize units */
	fsblkcnt_t	f_bfree;	/* free blocks */
	fsblkcnt_t	f_bavail;	/* free blocks for unprivileged */
	fsfilcnt_t	f_files;	/* inodes */
	fsfilcnt_t	f_ffree;	/* free inodes */
	fsfilcnt_t	f_favail;	/* free inodes for unprivileged */
	unsigned long	f_fsid;		/* file system id */
	unsigned long	f_flag;		/* ST_* below */
	unsigned long	f_namemax;	/* maximum filename length */
	unsigned long	f_type;		/* not POSIX; always 0 here */
};

#define ST_RDONLY	1	/* read-only file system */
#define ST_NOSUID	2	/* setuid/setgid bits are ignored */

#ifdef __cplusplus
extern "C" {
#endif

extern int statvfs(const char *, struct statvfs *);
extern int fstatvfs(int, struct statvfs *);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_STATVFS_H */
