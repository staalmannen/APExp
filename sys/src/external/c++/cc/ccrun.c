#include <u.h>
#include <libc.h>

typedef struct Objtype {
	char	*name;
	char	*cc;
	char	*ld;
	char	*o;
	char	*oname;
} Objtype;

Objtype objtype[] = {
/*
 * table constructed by mk newmachine in ..
 */
#include "machines.h"
};

enum {
	Nobjs = (sizeof objtype)/(sizeof objtype[0]),
	Maxlist = 500,
};

typedef struct List {
	char	*strings[Maxlist];
	int	n;
} List;

List	cpp, cc, cfront;
int	verbose, passes;
char	*progname;

void	append(List *, char *);
char	*changeext(char *, char *);
int	doexec(char *, List *, int, int);
void	waitup(int);
void	fatal(char *);
Objtype	*findoty(void);
void	printlist(List *);
char	*smprint(char *, ...);
char	*rmfile;
void	usage(void);

void
usage(void)
{
	fprint(2, "usage: %s [-ABEFJNSTVadnvw] [-I dir] [-D name] [-o objfile] [-U name] [-x file] files\n", progname);
	exits("usage");
}

void
main(int argc, char *argv[])
{
	Objtype *ot;
	char *s, *ccpath;
	int i, cppn, ccn, cfrontn, docc, doobj, docfront, ansi, fd;

	/* we should be called by a shell script, dump first arg */
	argv++; argc--;
	progname = utfrrune(argv[0], L'/');
	if(progname)
		progname++;
	else
		progname = argv[0];
	ot = findoty();
	append(&cpp, "cpp");
	append(&cpp, "-D__cplusplus=1");/* c++ says so */
	append(&cpp, "-N");		/* turn off standard includes */
	append(&cpp, "-+");		/* turn on c++ comments */
	append(&cpp, "-D_POSIX_SOURCE");
	append(&cc, ot->cc);
	append(&cc, "-B");
	append(&cfront, "c++/cfront");
	append(&cfront, "+L");
	append(&cfront, smprint("+x/sys/lib/c++/%s.sz", ot->o));

	doobj = docc = docfront = 1;
	ansi = 0;
	ARGBEGIN {
	case 'A':
		ansi = 1;
		break;
	case 'B':
		ansi = 0;
		break;
	case 'J':
	case 'F':
	case 'N':
	case 'S':
	case 'V':
	case 'T':
	case 'a':
	case 'n':
	case 'w':
		append(&cc, smprint("-%c", ARGC()));
		break;
	case 'o':
		s = ARGF();
		if(!s)
			usage();
		doobj = 0;
		append(&cc, smprint("-%c%s", ARGC(), s));
		break;
	case 'x':
		s = ARGF();
		if(!s)
			usage();
		append(&cfront, smprint("+x%s", s));
		break;
	case 'd':
		append(&cfront, smprint("+%c", ARGC()));
		break;
	case 'D':
	case 'I':
	case 'U':
		s = ARGF();
		if(!s)
			usage();
		append(&cpp, smprint("-%c%s", ARGC(), s));
		break;
	case 'v':
		verbose++;
		break;
	case 'E':
		docfront = 0;
		docc = 0;
		break;
	case 'C':
		docc = 0;
		break;
	default:
		usage();
	} ARGEND
	if(argc == 0)
		usage();

	/*
	 * finish adding the standard arguments
	 */
	append(&cpp, smprint("-I/%s/include/c++", ot->name));
	append(&cpp, "-I/sys/include/c++");
	append(&cpp, smprint("-I/%s/include/ape", ot->name));
	append(&cpp, "-I/sys/include/ape");
	if(ansi){
		append(&cfront, "+a1");
		append(&cc, "-A");
	}else{
		append(&cfront, "+a0");
		append(&cc, "-B");
	}

	ccpath = smprint("/bin/%s", ot->cc);
	cppn = cpp.n;
	ccn = cc.n;
	cfrontn = cfront.n;
	for(i = 0; i < argc; i++) {
		append(&cpp, argv[i]);
		fd = doexec("/bin/cpp", &cpp, 0, docfront);
		if(docfront){
			append(&cfront, smprint("+f%s", argv[i]));
			fd = doexec("/bin/c++/cfront", &cfront, fd, docc);
		}
		if(docc && doobj){
			append(&cc, "-o");
			if((s = utfrrune(argv[i], L'.'))
			&& (strcmp(s, ".c") == 0 || strcmp(s, ".C") == 0))
				append(&cc, rmfile = changeext(argv[i], ot->o));
			else
				append(&cc, rmfile = smprint("%s.%s", argv[i], ot->o));
		}
		if(docc)
			doexec(ccpath, &cc, fd, 0);
		waitup(1 + docfront + docc);
		cpp.n = cppn;
		cc.n = ccn;
		cfront.n = cfrontn;
	}
	exits(0);
}

void
append(List *l, char *s)
{
	if(l->n >= Maxlist-1)
		fatal("too many arguments");
	l->strings[l->n++] = s;
	l->strings[l->n] = 0;
}

void
waitup(int n)
{
	Waitmsg *w;
	char msg[ERRMAX];
	int got;

	if(verbose)
		fprint(2, "\n");
	if(verbose > 1)
		return;

	msg[0] = '\0';
	for(got = 0; got < n; got++) {
		w = wait();
		if(w == nil)
			fatal("wait failed");
		if(w->msg[0]){
			strncpy(msg, w->msg, ERRMAX-1);
			msg[ERRMAX-1] = '\0';
		}
		free(w);
		if(msg[0])
			fatal(msg);
	}
}

int
doexec(char *c, List *a, int pipein, int pipeout)
{
	int fd[2];

	if(verbose) {
		printlist(a);
		if(pipeout)
			fprint(2, " | ");
	}
	if(verbose > 1)
		return 0;
	if(pipeout && pipe(fd) < 0)
		fatal("pipe failed");
	switch(fork()){
	case -1:
		fatal("fork failed");
	case 0:
		if(pipein >= 0){
			dup(pipein, 0);
			close(pipein);
		}
		if(pipeout){
			dup(fd[1], 1);
			close(fd[1]);
		}
		exec(c, a->strings);
		fatal("exec failed");
	}
	if(pipeout){
		close(fd[1]);
		return fd[0];
	}
	return -1;
}

Objtype *
findoty(void)
{
	Objtype *oty;

	for(oty = objtype; oty < &objtype[Nobjs]; oty++)
		if(strcmp(progname, oty->cc) == 0)
			return oty;
	fatal("unknown objtype");
	return 0;			/* not reached */
}

void
fatal(char *msg)
{
	if(rmfile)
		remove(rmfile);
	fprint(2, "%s: %s\n", progname, msg);
	exits(msg);
}

/* src ends in .something; return copy of basename with .ext added */
char *
changeext(char *src, char *ext)
{
	char *b, *e, *ans;

	b = utfrrune(src, '/');
	if(b)
		b++;
	else
		b = src;
	e = utfrrune(src, '.');
	if(!e)
		return 0;
	*e = 0;
	ans = smprint("%s.%s", b, ext);
	*e = '.';
	return ans;
}

void
printlist(List *l)
{
	int i;

	for(i = 0; i < l->n; i++) {
		fprint(2, "%s", l->strings[i]);
		if(i < l->n - 1)
			fprint(2, " ");
	}
}

