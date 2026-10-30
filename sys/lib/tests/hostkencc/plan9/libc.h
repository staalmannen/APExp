/*
 * libc.h -- the companion to this directory's `u.h'. Same caveat: a
 * minimal stand-in for 9front's own, holding what the native probes
 * actually reference. See `u.h'.
 */
#define	nil	((void*)0)
#define	nelem(x)	(sizeof(x)/sizeof((x)[0]))
#define	USED(x)	if(x){}else{}
#define	SET(x)	((x)=0)

extern	int	print(char*, ...);
extern	void	exits(char*);
extern	int	sprint(char*, char*, ...);
extern	void*	malloc(ulong);
extern	void	free(void*);
extern	void*	memset(void*, int, ulong);
extern	void*	memmove(void*, void*, ulong);
extern	int	strcmp(char*, char*);
extern	long	strlen(char*);
