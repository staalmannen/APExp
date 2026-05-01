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

struct	dirent {
	char	d_name[MAXNAMLEN + 1];
	struct stat d_stat;
};

/* d_ino compatibility macro: map to the inode field in d_stat */
#define d_ino d_stat.st_ino
/* d_type is not available on Plan9; define DT_ constants as stubs */
#define d_type d_stat.st_mode
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
