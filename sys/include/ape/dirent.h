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
