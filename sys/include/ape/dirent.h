#ifndef	__DIRENT_H
#define	__DIRENT_H
#pragma lib "/$M/lib/ape/libap.a"

#ifndef __STAT_H
#include <sys/stat.h>
#endif

/*
 * this must be a power of 2 and a multiple of all the ones in the system
 */
#define MAXNAMLEN 255

/*
 * d_ino and d_type are real members, filled in by readdir() from the
 * stat information Plan 9 returns. They used to be object-like macros:
 *
 *	#define d_ino  d_stat.st_ino
 *	#define d_type d_stat.st_mode
 *
 * which broke twice over.
 *
 * As macros they rewrote the names anywhere they appeared, not just
 * after a dot. gnulib's file-has-acl.c declares a local
 *
 *	unsigned char d_type = flags & UCHAR_MAX;
 *
 * which became "unsigned char d_stat.st_mode = ...":
 *
 *	file-has-acl.c:463 syntax error, last name: d_stat
 *
 * And st_mode is not what d_type holds. DT_DIR is 4 where S_IFDIR is
 * 0040000, so "dp->d_type == DT_DIR" was false for every directory.
 * libap's own misc/fts.c and regex/glob.c both test d_type against
 * these constants and were quietly getting the wrong answer.
 *
 * Placed after d_stat so the offsets of d_name and d_stat do not move.
 */
struct	dirent {
	char	d_name[MAXNAMLEN + 1];
	struct stat d_stat;
	ino_t	d_ino;
	unsigned char d_type;
};
#define DT_UNKNOWN 0
#define DT_FIFO    1
#define DT_CHR     2
#define DT_DIR     4
#define DT_BLK     6
#define DT_REG     8
#define DT_LNK     10
#define DT_SOCK    12

/*
 * BSD's conversions between a stat mode and a d_type value. Real
 * systems put these in <dirent.h>; gnulib carries its own in
 * dirent.in.h, which import.sh prunes for shadowing this header, so
 * without them a caller gets an implicit function:
 *
 *   file-has-acl.c:979  IFTODT (sb->st_mode)
 *
 * No DT_WHT arm: BSD whiteout entries do not exist here, and neither
 * DT_WHT nor S_IFWHT is defined, so an unknown mode simply reports
 * DT_UNKNOWN and an unknown type maps back through the same shift
 * gnulib uses.
 *
 * S_ISFIFO and S_ISSOCK are the same test in <sys/stat.h>, both mode
 * 0010000, so the FIFO arm is reached first and a socket cannot be
 * distinguished -- the same limitation readdir() has when it fills
 * d_type. DTTOIF has it in the other direction: S_IFSOCK is S_IFIFO.
 */
#ifndef IFTODT
#define IFTODT(mode) \
   (S_ISREG(mode) ? DT_REG : S_ISDIR(mode) ? DT_DIR \
    : S_ISLNK(mode) ? DT_LNK : S_ISBLK(mode) ? DT_BLK \
    : S_ISCHR(mode) ? DT_CHR : S_ISFIFO(mode) ? DT_FIFO \
    : S_ISSOCK(mode) ? DT_SOCK : DT_UNKNOWN)
#endif
#ifndef DTTOIF
#define DTTOIF(dirtype) \
   ((dirtype) == DT_REG ? S_IFREG : (dirtype) == DT_DIR ? S_IFDIR \
    : (dirtype) == DT_LNK ? S_IFLNK : (dirtype) == DT_BLK ? S_IFBLK \
    : (dirtype) == DT_CHR ? S_IFCHR : (dirtype) == DT_FIFO ? S_IFIFO \
    : (dirtype) == DT_SOCK ? S_IFSOCK \
    : (dirtype) << 12)
#endif

typedef struct _dirdesc {
	int	dd_fd;		/* file descriptor */
	long	dd_loc;		/* buf offset of entry from last readdir() */
	long	dd_size;	/* amount of valid data in buffer */
	char	*dd_buf;	/* directory data buffer */
	void *dirs;
	int	dirsize;
	int	dirloc;
	long	dd_seek;	/* entry count for telldir/seekdir */
} DIR;


#ifdef __cplusplus
extern "C" {
#endif

/*
 * functions defined on directories
 */
DIR		*opendir(const char *);
DIR		*fdopendir(int);
struct dirent	*readdir(DIR *);
void		rewinddir(DIR *);
int		closedir(DIR *);
int		dirfd(DIR *);
int		readdir_r(DIR *, struct dirent *, struct dirent **);
void		seekdir(DIR *, long);
long		telldir(DIR *);
int		scandir(const char *, struct dirent ***,
			int (*)(const struct dirent *),
			int (*)(const struct dirent **, const struct dirent **));
int		alphasort(const struct dirent **, const struct dirent **);
int		versionsort(const struct dirent **, const struct dirent **);

#ifdef __cplusplus
}
#endif

#endif
