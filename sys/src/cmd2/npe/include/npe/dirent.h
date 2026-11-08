#ifndef _npe_dirent_h_
#define _npe_dirent_h_

#include <npe.h>

#ifndef _DIRENT_HAVE_D_TYPE
#define _DIRENT_HAVE_D_TYPE 1
#endif

enum {
	DT_UNKNOWN = 0,
	DT_FILE,
	DT_DIR,
	DT_LNK = DT_UNKNOWN,
	DT_BLK = DT_UNKNOWN,
	DT_CHR = DT_UNKNOWN,
	DT_FIFO = DT_UNKNOWN,
	DT_SOCK = DT_UNKNOWN,
};

struct dirent {
	int d_type;
	char *d_name;
};

typedef struct DIR DIR;
#pragma incomplete DIR

DIR *opendir(char *name);
int closedir(DIR *dirp);
struct dirent *readdir(DIR *dirp);
int dirfd(DIR *d);

#endif
