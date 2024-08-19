/* © Copyright		Steve Simon 	2008 */
/* mkmk.c - human readable mkfile generator for APE apps */

#include <u.h>
#include <libc.h>
#include <ctype.h>
#include <bio.h>
#include "mkmk.h"
#include "objtab.h"

int Debug = 0;				/* debug */
int Wrap = Defwrap;			/* word wrap collumn */
Biobuf *op;					/* output */
List *Incdir = nil;			/* -I args from command line */
char *Objname = nil;		/* $objtype from environment */
char Objletter;				/* Object letter */
int Autoconf = 0;			/* generate a config.h and fill with defines */

static int Slow = 0;		/* slow but accurate mode */
static int Apemode = 0;		/* to be used in ape environment only */
static Depend *Dep = nil;	/* dependency graph */
static char *Target = nil;	/* output target/library name */
static File *Files = nil;	/* file list */

static List *Cleanfiles = nil;	/* -C args from command line */
static List *Defs = nil;	/* -D args from command line */
static List *Undefs = nil;	/* -U args from command line */
static List *Cflags = nil;	/* -c args from command line */
static List *Exclude = nil;	/* -x args from command line */
static List *Ldflags = nil;	/* -h args from command line */
static List *Libs = nil;	/* -H args from command line */

static List *Cppinc = nil;	/* Cpp system include dirs */
static List *F77inc = nil;	/* f77 system include dirs */



static Lang Langtab[] = { 
	{ ".c",	   	Tsrc,	&Cppinc,	parse_cpp },
	{ ".s",	   	Tsrc,	&Cppinc,	parse_cpp },
	{ ".h",	   	Thdr,	&Cppinc,	parse_cpp },
	{ ".y",	   	Tyacc,	&Cppinc,	parse_cpp },
	{ ".l",	   	Tlex,	&Cppinc,	parse_cpp },

	{ ".1",		Tman1,	nil,		nil },
	{ ".man",	Tman1,	nil, 		nil },
	{ ".3",		Tman1,	nil, 		nil },

	{ ".f",	   	Tsrc,	&F77inc,	parse_f77 },
	{ ".f77",	Tsrc,	&F77inc,	parse_f77 },
	{ ".r",	   	Tsrc,	&F77inc,	parse_f77 },

//	{ ".H",	   	Thdr,	&Cppinc, 	parse_cpp },
//	{ ".C",	   	Tsrc,	&Cppinc, 	parse_cpp },
//	{ ".cpp",	Tsrc,	&Cppinc, 	parse_cpp },
//	{ ".hpp",	Thdr,	&Cppinc, 	parse_cpp },
//	{ ".c++",	Tsrc,	&Cppinc, 	parse_cpp },
//	{ ".h++",	Thdr,	&Cppinc, 	parse_cpp },

//	{ ".rat",	Tsrc,	&F77inc,	parse_rat },
//	{ ".rat4",	Tsrc,	&F77inc,	parse_rat },

//	{ ".f90",	Tsrc,	&F90inc,	parse_f90 },

//	{ ".p",	   	Tyacc,	&Pasinc,	parse_pas },
//	{ ".pas",	Tsrc,	&Pasinc,	parse_pas },

};

#pragma varargck type "t" char*

	
static void
dumpdeps(Biobuf *bp, Depend *dep, int depth)
{
	Depend *d;

	for(d = dep; d; d = d->next){
		Bprint(bp, "%*.s%-20s \n", depth, "", d->file->name);
		if(d->child)
			dumpdeps(bp, d->child, depth +4);
	}
}

static void
dumpfiles(Biobuf *bp)
{
	File *f;
	int len, n;
	char *Type[] = {
		[Tunk]	"unknown",
		[Thdr]	"header",
		[Tsrc]	"source",
		[Tyacc]	"yacc",
		[Tlex]	"lex",
		[Tman1]	"man1",
		[Tman3]	"man3",
		[Tdir]	"dir",
	};

	len = strlen("file");
	for(f = Files; f; f = f->next){
		n = strlen(f->name);
		if(n > len)
			len = n;
	}

	Bprint(bp, "%*s  %-6s %-6s %-10s %s\n",
		-len, "file", "refs", "reads", "type",  "is global");

	for(f = Files; f; f = f->next)
		Bprint(bp, "%*s  %-6d %-6d %-10s %s\n", 
			-len, f->name, f->ref, f->reads, Type[f->type], (f->global)? "y": "n");

}

static int
issrc(File *f)
{
	switch(f->type){
	case Tyacc: return 1;
	case Tlex: return 1;
	case Tsrc: return 1;
	}
	return 0;
}

static void
printdeps(Depend *root, int *colp)
{
	Depend *d;

	for(d = root; d; d = d->next){
		if(d->file->sysdir || d->file->global)
			continue;
		wrap(colp, "%s ", d->file->name);
//		printdeps2(d->child, colp);
	}
}

static int
havedeps(Depend *root)
{
	Depend *d;

	for(d = root; d; d = d->next){
		if(!d->file->sysdir && !d->file->global){
			if(d->child)
				return 1;
			if(havedeps(d->child) == 1)
				return 1;
		}
	}
	return 0;
}



static void
dependencies(void)
{
	int col;
	Depend *d;

	for(d = Dep; d; d = d->next){
		if(havedeps(d->child)){
			col = 0;
			if(issrc(d->file))
				wrap(&col, "%t.$O: ", d->file->name);
			else
				wrap(&col, "%s: ", d->file->name);
			printdeps(d->child, &col);
			Bprint(op, "\n\n");
		}
	}
}

static void
ofiles(void)
{
	int col;
	File *f;
	List *l;

	col = 0;
	wrap(&col, "OFILES=");
	for(f = Files; f; f = f->next){
		for(l = Exclude; l; l = l->next){
			if(strcmp(l->name, f->name) == 0)
				break;
		}
		if(l)
			continue;

		switch(f->type){
		case Tsrc:
			wrap(&col, "%t.$O ", f->name);
			f->ref++;
			break;
		case Tyacc:
			wrap(&col, "y.tab.$O ");
			f->ref++;
			break;
		case Tlex:
			wrap(&col, "lex.yy.$O ");
			f->ref++;
			break;
		default:
			break;
		}
	}
	Bprint(op, "\n");
}

static void
yacclex(char *name, int type)
{
	File *f;
	int col;

	for(f = Files; f; f = f->next)
		if(f->type == type)
			break;
	if(f == nil)
		return;

	col = 0;
	wrap(&col, "%s", name);
	for(f = Files; f; f = f->next)
		if(f->type == type){
			wrap(&col, "%s ", f->name);
			f->ref++;
		}
	Bprint(op, "\n");
}

static void
ldflags(void)
{
	List *l;
	int col;

	if(Ldflags){
		col = 0;
		wrap(&col, "LDFLAGS=");
		for (l = Ldflags; l; l = l->next)
			wrap(&col, "%s ", l->name);
		Bprint(op, "\n");
	}
	if(Libs){
		col = 0;
		wrap(&col, "LIB=");
		for (l = Libs; l; l = l->next)
			wrap(&col, "%s ", l->name);
		Bprint(op, "\n");
	}
}

	
static void
manpages(void)
{
	File *f;
	int sect;
	char *ape;

	/* any manpages to print ? */
	for(f = Files; f; f = f->next)
		if(f->type == Tman1 || f->type == Tman3)
			break;
	if(f == nil)
		return;

	ape = "";
	if(Apemode)
		ape = "ape";

	Bprint(op, "install:V:\n");
	for(f = Files; f; f = f->next){
		switch(f->type){
		case Tman1:
			sect = 1;
			break;
		case Tman3:
			sect = 2;
			break;
		default:
			continue;
		}
		Bprint(op, "\tcp %s /sys/man/%d%s/%t\n",
			f->name, sect, ape, f->name);
		f->ref++;
	}
	Bprint(op, "\n");
}


static void
hfiles(void)
{
	int col, found, num;
	File *f;

	col = 0;
	num = 0;
	found = 0;

	for(f = Files; f; f = f->next)
		if(!f->sysdir && f->ref > 0)
			num++;
	num = (num*PercentInc)/100;

	for(f = Files; f; f = f->next){
		if(Debug)
			fprint(2, "h %s %d/%d\n", f->name, f->ref, num);
		if(!f->sysdir && f->ref >= num || f->ref > NumberInc){
			found = 1;
			break;
		}
	}

	if(! found)
		return;

	wrap(&col, "HFILES=");
	for(f = Files; f; f = f->next)
		if(!f->sysdir && f->ref >= num){
			f->global = 1;
			wrap(&col, "%s ", f->name);
		}
	wrap(&col, "\n");
}		


static void
dirs(void)
{
	File *f;
	int col, found;

	found = 0;
	for(f = Files; f; f = f->next)
		if(f->type == Tdir)
			found = 1;
	if(! found)
		return;

	col = 0;
	wrap(&col, "DIRS=");
	for(f = Files; f; f = f->next)
		if(f->type == Tdir)
			wrap(&col, "%s ", f->name);
	Bprint(op, "\n");
}

static void
unreferenced(void)
{
	File *f;

	for(f = Files; f; f = f->next)
		if((issrc(f) || f->type == Thdr) && !f->ref)
			fprint(2, "%s: %s not referenced\n", argv0, f->name);
}

static void
gnu_configh(void)
{
	List *l;
	char *p;
	Biobuf *bp;

	if((bp = Bopen("config.h", OWRITE)) == nil)
		sysfatal("config.h - cannot open\n");

	Bprint(bp, "/* Auto generated file, do not edit */\n\n");
	for (l = Lochints; l; l = l->next){
		if((p = strchr(l->name, '=')) != nil){
			*p = ' ';
			Bprint(bp, "#define %s\n", l->name);
		}
		else
			Bprint(bp, "#define %s 1\n", l->name);
	}
	Bterm(bp);
}

static void
cflags(void)
{
	int col;
	List *l;

	col = 0;
	wrap(&col, "CFLAGS=-c ");
	for (l = Incdir; l; l = l->next)
		wrap(&col, "-I%s ", l->name);
	for (l = Cflags; l; l = l->next)
		wrap(&col, "%s ", l->name);
	for (l = Defs; l; l = l->next)
		wrap(&col, "-D%s ", l->name);
	for (l = Undefs; l; l = l->next)
		wrap(&col, "-U%s ", l->name);
	for (l = Glbhints; l; l = l->next)
		wrap(&col, "-D%s ", l->name);

	if(Autoconf){
		gnu_configh();
		/*
		 * Sometimes autoconf appears self-doubting. Even though the
		 * code won't compile without config.h we need to set this
		 * define on the command line to tell it to use config.h.
		 */
	}
	else{
		for (l = Lochints; l; l = l->next)
			wrap(&col, "-D%s ", l->name);
	}

	Bprint(op, "\n");
	
}

static int
directories(void)
{
	File *f;
	int ndir, nsrc;

	ndir = nsrc = 0;
	for(f = Files; f; f = f->next){
		if(f->type == Tdir)
			ndir++;
		if(issrc(f))
			nsrc++;
	}
	if(! ndir)
		return -1;
	Bprint(op, "\n");

	Bprint(op, "all:V:\n");
	Bprint(op, "	for (i in $DIRS)\n");
	Bprint(op, "		@{ cd $i; mk }\n");
	Bprint(op, "\n");

	if(Libs){
		Bprint(op, "$LIB:V:\n");
		Bprint(op, "	for (i in $LIB)\n");
		Bprint(op, "		@{ cd `{echo $i|sed 's@^(.*)/.*$@\\1@'}; mk }\n");
		Bprint(op, "\n");
	}

	Bprint(op, "install:V:\n");
	Bprint(op, "	for (i in $DIRS)\n");
	Bprint(op, "		@{ cd $i; mk $target }\n");
	Bprint(op, "\n");

	Bprint(op, "clean:V:\n");
	Bprint(op, "	for (i in $DIRS)\n");
	Bprint(op, "		@{ cd $i; mk $target }\n");
	if(nsrc)
		Bprint(op, "	rm -f [$OS].* *.[$OS] $CLEANFILES\n");
	Bprint(op, "\n");

	Bprint(op, "nuke:V:\n");
	Bprint(op, "	for (i in $DIRS)\n");
	Bprint(op, "		@{ cd $i; mk $target }\n");
	if(nsrc)
		Bprint(op, "	rm -f *.[$OS] y.tab.? y.debug y.output [$OS].$TARG $TARG\n");
	Bprint(op, "\n");
	return 0;
}

static void
cleanfiles(void)
{
	List *l;
	int col;

	if(Cleanfiles == nil)
		return;

	col = 0;
	wrap(&col, "CLEANFILES=");
	for (l = Cleanfiles; l; l = l->next)
		wrap(&col, "%s ", l->name);
}

static void
manytarg(void)
{
	int col;
	File *f;

	col = 0;
	wrap(&col, "TARG=");
	for(f = Files; f; f = f->next)
		if(issrc(f)){
			wrap(&col, "$O.%t ", f->name);
			f->ref++;
		}
	Bprint(op, "\n");

}

static void
mkmany(void)
{
	manytarg();
	yacclex("LFILES=", Tlex);
	yacclex("YFILES=", Tyacc);
	ldflags();
	if(Apemode)
		Bprint(op, "BIN=/$objtype/bin/ape\n");
	else
		Bprint(op, "BIN=/$objtype/bin\n");
	hfiles();
	cleanfiles();

	Bprint(op, "\n");

	Bprint(op, "</sys/src/cmd/mkmany\n");

	Bprint(op, "\n");

	Bprint(op, "CC=pcc\n");
	Bprint(op, "LD=pcc\n");
	cflags();

	Bprint(op, "\n");

	dependencies();
}

static void
mkone(void)
{
	Bprint(op, "TARG=%s\n", Target);
	ofiles();
	yacclex("LFILES=", Tlex);
	yacclex("YFILES=", Tyacc);
	ldflags();
	if(Apemode)
		Bprint(op, "BIN=/$objtype/bin/ape\n");
	else
		Bprint(op, "BIN=/$objtype/bin\n");
	hfiles();
	cleanfiles();

	Bprint(op, "\n");

	Bprint(op, "</sys/src/cmd/mkone\n");
	Bprint(op, "\n");

	Bprint(op, "CC=pcc\n");
	Bprint(op, "LD=pcc\n");
	cflags();

	Bprint(op, "\n");

	dependencies();
}


static void
mklib(void)
{
	Bprint(op, "LIB=%s.a$O\n", Target);
	ofiles();
	yacclex("LFILES=", Tlex);
	yacclex("YFILES=", Tyacc);
	hfiles();
	cleanfiles();

	Bprint(op, "\n");

	Bprint(op, "</sys/src/cmd/mklib\n");

	Bprint(op, "\n");

	Bprint(op, "CC=pcc\n");
	Bprint(op, "LD=pcc\n");
	cflags();

	Bprint(op, "\n");

	dependencies();

	Bprint(op, "\n");

	Bprint(op, "nuke:V:\n");
	Bprint(op, "\tmk clean\n");
	Bprint(op, "\trm -f $LIB\n");
}

static void
mksyslib(void)
{
	if(Apemode)
		Bprint(op, "LIB=/$objtype/lib/ape/%s.a$O\n", Target);
	else
		Bprint(op, "LIB=/$objtype/lib/%s.a$O\n", Target);
	ofiles();
	yacclex("LFILES=", Tlex);
	yacclex("YFILES=", Tyacc);
	hfiles();
	cleanfiles();

	Bprint(op, "\n");

	Bprint(op, "</sys/src/cmd/mksyslib\n");

	Bprint(op, "\n");

	Bprint(op, "CC=pcc\n");
	Bprint(op, "LD=pcc\n");
	cflags();

	Bprint(op, "\n");

	dependencies();

	Bprint(op, "nuke:V:\n");
	Bprint(op, "\tmk clean\n");
	Bprint(op, "\trm -f $LIB\n");
}

static void
noptargets(void)
{
	Bprint(op, "default:VQ:\n");
	Bprint(op, "	;\n\n");
	Bprint(op, "install:VQ:\n");
	Bprint(op, "	;\n\n");
	Bprint(op, "clean:VQ:\n");
	Bprint(op, "	;\n\n");
	Bprint(op, "nuke:VQ:\n");
	Bprint(op, "	;\n\n");
}

/*
 * This is typically a huge efficency win, we check to see if we have
 * read a file and extracted its dependency list already, if so we don't
 * re-read it.
 *
 * It can lead to erronous results as silly games with #ifdef can result
 * to a header file pulling in different clild headers depending on what
 * #defines the parent source file has active.
 *
 * Because of these problems we give the user the -S (slow) option
 * which disables the optimisation.
 */ 
static int
clonedep(Depend **dep, char *file)
{
	Depend *d, *c;

	if(Slow)
		return -1;

	for(d = Dep; d; d = d->next){
		for(c = d->child; c; c = c->next)
			if(strcmp(c->file->name, file) == 0 && c->child){
				*dep = c->child;
				return 0;
			}
	}
	return -1;
}

static int
doscan(Depend **dep, File *f, Lang *l, char *efile, int eline)
{
	State *s;
	char *buf, *path;
	static depth = 0;

	if(clonedep(dep, f->name) != -1)
		return 0;

	if(depth++ > Maxdepth){		/* catch circular dependencies */
		fprint(2, "%s: %s:%d - %s too many nested includes, skipping file\n",
			argv0, efile, eline, f->name);
		depth--;
		return -1;
	}

	*dep = nil;
	s = emallocz(sizeof(State), 1);
	if((s->bp = Bopen(f->name, OREAD)) == nil){
		depth--;
		return -1;
	}

	s->dep = dep;
	s->file = f->name;
	s->langincdirs = *l->incdirp;
	l->parser(s);
	f->reads++;
	Bterm(s->bp);
	free(s);
	depth--;
	return 0;
}


int
scanfile(Depend **dep, File *f, char *file, int line)
{
	int rc;
	Lang *l;
	char *p;
	Depend *d;

	if(f->type == Tdir)
		return 0;

	if((p = strrchr(f->name, '.')) == nil){
		if(Debug)
			fprint(2, "%s no extension, file ignored\n", f->name);
		return -1;
	}
	for(l = Langtab; l < &Langtab[nelem(Langtab)]; l++)
		if(strcmp(p, l->ext) == 0)
			break;
	if(l >= &Langtab[nelem(Langtab)]){
		if(Debug)
			fprint(2, "%s unknown type, ignored\n", f->name);
		return -1;
	}

	f->type = l->type;

	d = emallocz(sizeof(Depend), 1);
	d->file = f;

	if(line == -1 && !issrc(f))		/* only add headers if they are referenced by source */
		return 0;

	rc = 0;
	if(l->parser)
		if((rc = doscan(&d->child, f, l, file, line)) != -1)
			f->ref++;
	d->next = *dep;
	*dep = d;
	return rc;
}


File *
addfile(char *name, int sysdir)
{
	File **p, *f;

	cleanname(name);
	for(p = &Files, f = Files; f; p = &f->next, f = f->next)
		if(strcmp(name, f->name) == 0)
			return f;

	f = emallocz(sizeof(File)+strlen(name)+1, 1);
	f->name = (char *)&f[1];
	strcpy(f->name, name);
	f->sysdir = sysdir;
	*p = f;
	return f;
}


static int
scandir(char *path)
{
	List *l;
	File *f;
	int fd, n;
	Dir *dir, *d;

	if((fd = open(path, OREAD)) == -1)
		sysfatal("%s - cannot open %r\n", path);
	n = dirreadall(fd, &dir);
	close(fd);

	f = nil;
	for(d = dir; d < &dir[n]; d++){
		for(l = Exclude; l; l = l->next){
			if(strcmp(l->name, d->name) == 0)
				break;
		}
		if(l)
			continue;
		f = addfile(d->name, 0);
		if(d->mode & DMDIR)
			f->type = Tdir;
	}
	free(dir);

	return (f == nil)? -1: 0;
}


static void
usage(void)
{
	fprint(2, "usage: %s <opts> -m|-o|-l|-L [name]\n", argv0);
	fprint(2, "       -m many applications\n");
	fprint(2, "       -o <app> one application\n");
	fprint(2, "       -l <lib> a library\n");
	fprint(2, "       -s <syslib> a system library\n");
	fprint(2, "       -w <n> collumn for wordwrap\n");
	fprint(2, "       -S slow - disable include optimisation\n");
	fprint(2, "       -I <dir> include directory\n");
	fprint(2, "       -D <name>[=value] define preprocessor macro\n");
	fprint(2, "       -U <name> un-define preprocessor macro\n");
	fprint(2, "       -B add -B option to CFLAGS (a common case)\n");
	fprint(2, "       -c 'args' aditional CFLAGS (can appear multiple times)\n");
	fprint(2, "       -a APE mode - add /ape/ to destination directories\n");
	fprint(2, "       -x <file> exclude this source file (can appear multiple times)\n");
	fprint(2, "       -h <flags> LDFLAGS passed to linker (can appear multiple times)\n");
	fprint(2, "       -H <lib> libraries to link with\n");
	fprint(2, "       -C <file> add file to CLEANFILES\n");
	fprint(2, "       -A autoconf mode (put CFLAGS in config.h)\n");

	exits("usage");
}

void
main(int argc, char *argv[])
{
	Dir *d;
	File *f;
	List *l;
	int i, rc;
	Biobuf bout, berr;
	void (*func)(void);
	char tmp[128], *name, *val;

	if((Objname = getenv("objtype")) == nil)
		sysfatal("/env/objtype not set");
	for(i = 0; i < nelem(Objtab); i++)
		if(strcmp(Objtab[i].name, Objname) == 0){
			Objletter = Objtab[i].letter;
			break;
		}
	if(Objletter == 0)
		sysfatal("%s - unknown object type", Objname);
 
	op = &bout;
	Binit(&bout, OWRITE, 1);
	quotefmtinstall();
	fmtinstall('t', trimfmt);

	/* initialise our environment just as pcc(1) does */
	setsym("__STDC__", "1");
	snprint(tmp, sizeof(tmp), "/%s/include/ape", Objname);
	addlist(&Cppinc, tmp);
	addlist(&Cppinc, "/sys/include/ape");

	func = nil;
	Files = nil;
	ARGBEGIN{
	case 'd':
		Debug++;
		break;
	case 'o':
		func = mkone;
		Target = EARGF(usage());
		break;
	case 's':
		func = mksyslib;
		Target = EARGF(usage());
		break;
	case 'l':
		func = mklib;
		Target = EARGF(usage());
		break;
	case 'm':
		func = mkmany;
		break;
	case 'w':
		Wrap = atoi(EARGF(usage()));
		break;
	case 'B':
		addlist(&Cflags, "-B");
		break;
	case 'c':
		addlist(&Cflags, EARGF(usage()));
		break;
	case 'D':
		name = EARGF(usage());
		addlist(&Defs, name);
		if((val = strchr(name, '=')) != nil)
			*val++ = 0;
		else
			val = "1";
		setsym(name, val);
		break;
	case 'U':
		name = EARGF(usage());
		rmsym(name);
		addlist(&Undefs, name);
		break;
	case 'I':
		addlist(&Incdir, EARGF(usage()));
		break;
	case 'S':
		Slow = 1;
		break;
	case 'a':
		Apemode = 1;
		break;
	case 'A':
		Autoconf = 1;
		addlist(&Glbhints, "HAVE_CONFIG_H");
		break;
	case 'h':
		addlist(&Ldflags, EARGF(usage()));
		break;
	case 'H':
		addlist(&Libs, EARGF(usage()));
		break;
	case 'x':
		addlist(&Exclude, EARGF(usage()));
		break;
	case 'C':
		addlist(&Cleanfiles, EARGF(usage()));
		break;
	default:
		usage();
	}ARGEND;

	if(argc == 0)
		scandir(".");
	else
		for(i = 0; i < argc; i++){
			if((d = dirstat(argv[i])) == nil){
				fprint(2, "%s: %s - cannot stat %r\n",
					argv0, argv[i]);
				continue;
			}
			f = addfile(d->name, 0);
			if(d->mode & DMDIR)
				f->type = Tdir;
			free(d);
		}
	if(Files == nil){
		fprint(2, "%s: no files found\n", argv0);
		exits("no files");
	}

	Dep = nil;
	for(f = Files; f; f = f->next)
		scanfile(&Dep, f, "?", -1);

	if(Autoconf && access("config.h", 0) != -1)
		sysfatal("Autoconf mode but config.h already exists\n");

	if(Autoconf)
		gnu_pkgvers();

	Bprint(op, "</$objtype/mkfile\n");
	dirs();

	if(func){
		func();
		unreferenced();
	}

	rc = directories();
	if(! func && rc == -1)
		noptargets();

	manpages();

	if(Debug){
		Binit(&berr, 2, OWRITE);
		Bprint(&berr, "\n");
		dumpfiles(&berr);
		Bprint(&berr, "\n");
		dumpvars(&berr);
		Bprint(&berr, "\n");
		Bprint(&berr, "Dependencies\n");
		dumpdeps(&berr, Dep, 0);
		Bterm(&berr);
	}
	free(Objname);
	exits(0);
}
