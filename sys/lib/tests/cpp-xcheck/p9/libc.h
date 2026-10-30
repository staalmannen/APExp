#ifndef _P9SHIM_LIBC_H
#define _P9SHIM_LIBC_H
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
typedef struct Qid Qid;
typedef struct Dir Dir;
struct Qid { uvlong path; ulong vers; uchar type; };
struct Dir { Qid qid; ulong type; ulong dev; };
static Dir *dirfstat(int fd) {
	struct stat st; Dir *d;
	if (fstat(fd, &st) < 0) return nil;
	d = (Dir*)malloc(sizeof(Dir));
	if (d == nil) return nil;
	d->qid.path = st.st_ino; d->qid.vers = 0; d->qid.type = 0;
	d->type = 0; d->dev = st.st_dev;
	return d;
}
extern int read(int, void*, unsigned long);
extern int write(int, const void*, unsigned long);
extern int close(int);
extern int fstat(int, struct stat *);
extern char *getcwd(char*, unsigned long);
extern int dup2(int,int);
static char *getwd(char *b, int n) { return getcwd(b, n); }
static int dup(int a, int b) { return dup2(a, b); }
#include <time.h>
static char *p9ctime(long t) { time_t tt = t; return ctime(&tt); }
#define ctime(x) p9ctime(x)
static void exits(char *s) { exit(s && *s ? 1 : 0); }
static int chartorune(Rune *r, char *s) { *r = (uchar)s[0]; return 1; }
#define ARGBEGIN	for((void)0,argv0||(argv0=*argv),argv++,argc--;\
				argv[0] && argv[0][0]=='-' && argv[0][1];\
				argc--, argv++) {\
			char *_args, *_argt;\
			char _argc;\
			_args = &argv[0][1];\
			if(_args[0]=='-' && _args[1]==0){\
				argc--; argv++; break;\
			}\
			_argc = 0;\
			while(*_args && (_argc = *_args++))\
			switch(_argc)
#define ARGC() _argc
#define ARGEND		(void)_argt;(void)_args;(void)_argc;}
#define ARGF()		(_argt=_args, _args="",\
				(*_argt? _argt: argv[1]? (argc--, *++argv): 0))
#define EARGF(x)	(_argt=_args, _args="",\
				(*_argt? _argt: argv[1]? (argc--, *++argv): ((x), (char*)0)))
extern char *argv0;
extern int create(char*,int,int);
#endif
