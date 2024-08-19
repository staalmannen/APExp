#include "label.h"
#include <assert.h>
#include 
typedef unsigned long ulong;
typedef	struct	Exec	Exec;
struct	Exec
{
	long	magic;		/* magic number */
	long	text;	 	/* size of text segment */
	long	data;	 	/* size of initialized data */
	long	bss;	  	/* size of uninitialized data */
	long	syms;	 	/* size of symbol table */
	long	entry;	 	/* entry point */
	long	spsz;		/* size of pc/sp offset table */
	long	pcsz;		/* size of pc/line number table */
};
#define BY2PG	(8*1024)

/*
 * the first 3 routines are portably across ken's compilers
 */

/* 
 * return stack location guaranteed to have args for m in it
 */
unsigned long *argbase(Label f) {
	f = upframe(upframe(f));
	return (ulong *)f.sp;
}

/*
 * adjust label to reflect a moved stack location
 */
Label movelabel(Label f, ulong sp) {
	f.sp = sp;
	return f;
}

/*
 * return the top of main's stack
 * main => _main => __task__init => setlabel(m)
 */
ulong *stackbase(Label m) {
	return (ulong *)upframe(upframe(upframe(m))).sp;
}

static	uchar	*spoff;			/* pc-sp state table */
static	uchar	*spoffend;		/* end of pc-sp offset table */
static	void	pcspread(void);
static	long	pcsp(void);

Frame
upframe(Frame f)
{
	f.sp += pc2sp(pc);
	f.pc = *(ulong *)f.sp;
	f.sp += sizeof(ulong);
	return f;
}
/*
 *	find the stack frame, given the pc
 */
long
pc2sp(ulong pc)
{
	uchar u, *c;
	ulong currpc;
	long currsp;

	currsp = 0;
	currpc = entry - PCSIZE;

	for(c = spoff; c < spoffend; c++){
		if(currpc >= pc)
			return currsp;
		u = *c;
		if(u == 0){
			currsp += (c[1]<<24)|(c[2]<<16)|(c[3]<<8)|c[4];
			c += 4;
		}else if (u < 65)
			currsp += 4*u;
		else if (u < 129)
			currsp -= 4*(u-64);
		else 
			currpc += PCSIZE*(u-129);
		currpc += PCSIZE;
	}
	return 0;
}

static void
pcspread(void)
{
	char me[3*NAMELEN], pid[32], *p;
	Exec *fp;
	int fd, n;

	/*
	 * first time, read in pc-offset table
	 */
	fp = BY2PG;
	if(!fp->sppcsz){
		write(2, "task init: no spoffset table\n");
		exit(0);
	}
	fd = _OPEN("#c/pid", 0);
	memset(pid, 0, sizeof pid);
	_READ(fd, pid, sizeof pid);
	_CLOSE(fd);
	for(p = pid; *p == ' '; p++)
		;
	for(q = p; *q && *q != ' '; q++)
		;
	*q = '\0';
	strcpy(me, "#p/");
	strcat(me, p);
	strcat(me, "/text");
	fd = _OPEN(me, 0);
	spoff = new char[fp->sppcsz];
	if(spoff == 0){
		print("out of pc-sp table memory\n");
		exit(0);
	}
	_SEEK(fd, fp->sppcoff, 0);
	n = _READ(fd, spoff, fp->sppcsz);
	_CLOSE(fd);
	if(n != fp->sppcsz){
		write(2, "task init: unable to read sp offset table\n");
		exit(0);
	}
	spoffend = spoff+fp->sppcsz;
}
