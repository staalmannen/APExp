#ifndef _npe_unistd_h_
#define _npe_unistd_h_

#include <npe.h>

enum {
	F_OK = AEXIST,
	R_OK = AREAD,
	W_OK = AWRITE,
	X_OK = AEXEC,

	S_IFSOCK = -1,
	S_IFLNK = -1,
	S_IFBLK = -1,
	S_IFCHR = -1,
	S_IFIFO = -1,

	S_IFMT  = 0170000,
	S_IFREG = 0100000,
	S_IFDIR = 0040000,
	S_ISUID = 0004000,
	S_ISGID = 0002000,
	S_IRWXU = 0000700,
	S_IRUSR = 0000400,
	S_IWUSR = 0000200,
	S_IXUSR = 0000100,
	S_IRWXG = 0000070,
	S_IRGRP = 0000040,
	S_IWGRP = 0000020,
	S_IXGRP = 0000010,
	S_IRWXO = 0000007,
	S_IROTH = 0000004,
	S_IWOTH = 0000002,
	S_IXOTH = 0000001,
};

#define S_ISREG(x) (((x) & S_IFMT) == S_IFREG)
#define S_ISDIR(x) (((x) & S_IFMT) == S_IFDIR)

typedef unsigned useconds_t;

#define getcwd getwd
#define stat npe_stat
#define fstat npe_fstat

struct stat {
	uvlong st_size;
	int st_mode;
	long st_mtime;
	long st_atime;
};

int npe_stat(char *filename, struct stat *buf);
int npe_fstat(int fd, struct stat *buf);
int fstatat(int dirfd, char *path, struct stat *buf, int flags);
int unlink(char *path);
int access(char *name, int mode);
void usleep(useconds_t us);
int isatty(int fd);

int getopt(int argc, char *argv[], char *optstring);
extern char *optarg;
extern int optind, opterr, optopt;

#endif
