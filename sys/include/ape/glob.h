#ifndef	_GLOB_H
#define	_GLOB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>
#include <alltypes.h>

struct stat;
struct dirent;

typedef struct {
	size_t gl_pathc;
	char **gl_pathv;
	size_t gl_offs;
	int gl_flags;
	void (*gl_closedir)(void *);
	struct dirent *(*gl_readdir)(void *);
	void *(*gl_opendir)(const char *);
	int (*gl_lstat)(const char *, struct stat *);
	int (*gl_stat)(const char *, struct stat *);
} glob_t;

int  glob(const char *__restrict, int, int (*)(const char *, int), glob_t *__restrict);
void globfree(glob_t *);

#define GLOB_ERR      0x01
#define GLOB_MARK     0x02
#define GLOB_NOSORT   0x04
#define GLOB_DOOFFS   0x08
#define GLOB_NOCHECK  0x10
#define GLOB_APPEND   0x20
#define GLOB_NOESCAPE 0x40
#define	GLOB_PERIOD   0x80

#define GLOB_MAGCHAR     0x0100
#define GLOB_ALTDIRFUNC  0x0200
#define GLOB_BRACE       0x0400
#define GLOB_NOMAGIC     0x0800
#define GLOB_TILDE       0x1000
#define GLOB_ONLYDIR     0x2000
#define GLOB_TILDE_CHECK 0x4000

#define GLOB_NOSPACE 1
#define GLOB_ABORTED 2
#define GLOB_NOMATCH 3
#define GLOB_NOSYS   4

#if defined(_LARGEFILE64_SOURCE)
#define glob64 glob
#define globfree64 globfree
#define glob64_t glob_t
#endif

#ifdef __cplusplus
}
#endif

#endif
