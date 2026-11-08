#ifndef _npe_fts_h_
#define _npe_fts_h_

#include <npe.h>
#include <unistd.h>

enum {
	FTS_D,
	FTS_DC,
	FTS_DEFAULT,
	FTS_DNR,
	FTS_DOT,
	FTS_DP,
	FTS_ERR,
	FTS_F,
	FTS_NS,
	FTS_NSOK,
	FTS_SL,
	FTS_SLNONE,

	FTS_COMFOLLOW = 1<<0,
	FTS_LOGICAL = 1<<1,
	FTS_NOCHDIR = 1<<2,
	FTS_NOSTAT = 1<<3,
	FTS_PHYSICAL = 1<<4,
	FTS_SEEDOT = 1<<5,
	FTS_XDEV = 1<<6,
};

typedef struct FTS FTS;
typedef struct FTSENT FTSENT;

#pragma incomplete FTS

struct FTSENT {
	char *fts_accpath;
	char *fts_path;
	char *fts_name;
	void *fts_pointer;
	FTSENT *fts_parent;
	FTSENT *fts_link;
	FTSENT *fts_cycle;
	struct stat *fts_statp;

	int fts_info;
	int fts_pathlen;
	int fts_namelen;
	int fts_level;
	int fts_errno;
	long fts_number;
};

FTS *fts_open(char * const *path, int opt, int (*compar)(const FTSENT **, const FTSENT **));
FTSENT *fts_read(FTS *f);
FTSENT *fts_children(FTS *f, int instr);
int fts_set(FTS *f, FTSENT *fe, int instr);
int fts_close(FTS *f);

#endif
