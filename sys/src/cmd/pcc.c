#include <u.h>
#include <libc.h>

/*
   POSIX standard c89

   standard options: -c, -D name[=val], -E (preprocess to stdout),
       -g, -L dir, -o outfile, -O, -s, -U name
       (and operands can have -l lib interspersed)
   
    nonstandard but specified options: -S (assembly language left in .s),
       -Wx,arg1[,arg2...] (pass arg(s) to phase x, where x is p (cpp)
   			 0 (compiler), or l (loader)
    nonstandard options: -v (echo real commands to stdout as they execute)
	-A: turn on ANSI prototype warnings
 */

typedef struct Objtype {
	char	*name;
	char	*cc;
	char	*ld;
	char	*o;
} Objtype;

Objtype objtype[] = {
	{"68020",	"2c", "2l", "2"},
	{"arm",		"5c", "5l", "5"},
	{"arm64",	"7c", "7l", "7"},
	{"amd64",	"6c", "6l", "6"},
	{"386",		"8c", "8l", "8"},
	{"sparc",	"kc", "kl", "k"},
	{"power",	"qc", "ql", "q"},
	{"mips",	"vc", "vl", "v"},
	{"spim",	"0c", "0l", "0"},
};

enum {
	Nobjs = (sizeof objtype)/(sizeof objtype[0]),
	Maxlist = 2000,
};

typedef struct List {
	char	*strings[Maxlist];
	int	n;
} List;

List	srcs, objs, cpp, cc, ld, ldargs, srchlibs;
int	cflag, vflag, Eflag, Sflag, Aflag, gflag;
char	*allos = "2678kqv";

void	append(List *, char *);
char	*changeext(char *, char *);
void	doexec(char *, List *);
void	dopipe(char *, List *, char *, List *);
void	fatal(char *);
Objtype	*findoty(void);
void	printlist(List *);
char *searchlib(char *, char*);

void
main(int argc, char *argv[])
{
	char *s, *suf, *ccpath, *lib, *prog;
	char *oname, *objext;
	int haveoname = 0;
	int i, cppn, ccn;
	int oldalign = 0;
	Objtype *ot;

	ot = findoty();
	prog = utfrrune(argv[0], '/');
	prog = prog ? prog+1 : argv[0];
	/* cc: POSIX mode (.o objects, a.out output, clean up intermediates)
	 * pcc: Plan9 native mode (.$O objects, $O.out output, keep objects) */
	objext = (strcmp(prog, "cc") == 0) ? "o" : ot->o;
	oname  = (strcmp(prog, "cc") == 0) ? "a.out" : smprint("%s.out", ot->o);
	append(&cpp, "cpp");
	append(&cpp, "-D__STDC__=1");	/* ANSI says so */
	append(&cpp, "-D_POSIX_SOURCE=");
	append(&cpp, "-N");		/* turn off standard includes */
	append(&cc, ot->cc);
	append(&ld, ot->ld);
	append(&srchlibs, smprint("/%s/lib/ape", ot->name));
	while(argc > 0) {
		ARGBEGIN {
		case 'c':
			cflag = 1;
			break;
		case 'l':
			lib = searchlib(ARGF(), ot->name);
			if(!lib)
				fprint(2, "cc: can't find library for -l\n");
			else
				append(&objs, lib);
			break;
		case 'o':
			oname = ARGF();
			haveoname = 1;
			if(!oname)
				fatal("cc: no -o argument");
			break;
		case 'D':
		case 'I':
		case 'U':
			append(&cpp, smprint("-%c%s", ARGC(), ARGF()));
			break;
		case 'E':
			Eflag = 1;
			cflag = 1;
			break;
		case 's':
			break;
		case 'g':
			gflag = 1;
			break;
		case 'L':
			lib = ARGF();
			if(!lib)
				fprint(2, "cc: no -L argument\n");
			else
				append(&srchlibs, lib);
			break;
		case 'N':
		case 'T':
		case 'w':
		case 'F':
			append(&cc, smprint("-%c", ARGC()));
			break;

		/*
		 * -J is conforming struct layout (cc/cc.h). It MUST be
		 * named here: this ARGBEGIN has no `default:', so a flag it
		 * does not name is silently dropped -- the build would look
		 * exactly right and the layout would not change, which for
		 * a layout flag is the worst way to fail.
		 *
		 * AND ITS MARKER BELONGS ON THE `cpp' LIST, which took two
		 * wrong guesses to find. There are THREE preprocessors in
		 * play and only one of them runs here: `cc' has a built-in
		 * one, `cc' can fork an external one from its own defs[],
		 * and `pcc' runs `/bin/cpp' ITSELF and pipes it into `cc'
		 * (the dopipe() below). The source therefore arrives at
		 * `cc' ALREADY PREPROCESSED, so neither dodefine() nor
		 * cc's defs[] can ever define a macro the source will see.
		 * *Name the preprocessor that runs, not the one with the
		 * right name* -- the shadowed-config.h lesson, a third
		 * time, and it cost two VM rounds.
		 *
		 * AND THE LETTER WAS ALREADY TAKEN -- BY THIS FILE.
		 * The `if(!Aflag)' block below used to append `-J' to cc
		 * unconditionally, commented `old/new decl mixture hack'.
		 * In stock kencc `cc' names no `-J' at all, so it fell to
		 * ARGBEGIN's default arm, set debug['J'], and **nothing in
		 * the tree has ever read debug['J']** -- it was a pure
		 * no-op, and the comment describes a hack that had stopped
		 * existing. Giving the letter a MEANING in cc therefore
		 * turned conforming layout ON for every APE compile that
		 * did not pass -A or -B, which is exactly the silent ABI
		 * split this flag was built to avoid. `cmd/cfront' passes
		 * -B, so cfront alone kept the old layout -- which is the
		 * whole of why `structalign-test' reported 0 failures in
		 * the run that was predicted to fail about twelve checks,
		 * while `cfrontsz-probe', built with cfront's own -B,
		 * disagreed on fourteen types in the same minute. *The two
		 * instruments were measuring two different layout rules and
		 * neither command said so.*
		 *
		 * *I checked `cc' for a collision and did not check the
		 * driver that calls it* -- `-P' over again, one level out.
		 *
		 * IT IS THE DEFAULT NOW, so this arm does nothing and is
		 * kept only so that a command line or mkfile carrying -J
		 * still works. The appends happen once, after ARGEND, for
		 * every compile -- see there for why it cannot be done
		 * through CFLAGS or CC.
		 */
		case 'J':
			break;
		/*
		 * -9 is the way BACK: lay structs out the 9front way, the
		 * rule every APE object was built with before conforming
		 * layout became the default.
		 *
		 * It exists for the instruments rather than for the build.
		 * `structalign-test' needs a run under the OLD rule or its
		 * control measures nothing -- *a check that cannot fail is
		 * not a check* -- and `apeabi-probe' is two compiles whose
		 * whole content is the difference between the two rules.
		 * With the flag on by default and no way to turn it off,
		 * neither could ever be taken again. *An irreversible
		 * default takes the measurement with it.*
		 *
		 * Nothing in the tree passes it and nothing should: an
		 * object built with -9 and linked against a libap built
		 * without it disagrees about `pthread_mutex_t' and
		 * `sockaddr_in' silently, with every symbol resolving.
		 */
		case '9':
			oldalign = 1;
			break;
		case 'B':
			append(&cc, "-B");
			Aflag = 1;
			break;
		/*
		 * -a and -Z make `cc' write acid definitions, or a pickle,
		 * to standard output instead of an object (lex.c:255 sets
		 * `outfile = 0' and rebinds outbuf to fd 1, so the `-o'
		 * appended below is simply overridden). It is the same
		 * mechanism `mkone's `%.acid' rule uses, and an acid dump
		 * is the only complete, compiler-authored list of struct
		 * SIZES and member OFFSETS available -- which is what
		 * `sys/lib/tests/apeabi-probe.c' is compiled twice to get.
		 *
		 * pcc did not name either letter, so `pcc -a x.c' answered
		 * `cc: flag -a ignored' and compiled normally: the probe
		 * could not be taken at all. *A driver that drops the flag
		 * for reading a layout, next to one that dropped the flag
		 * for changing it.*
		 */
		case 'a':
		case 'Z':
			append(&cc, smprint("-%c", ARGC()));
			break;
		case 'O':
			break;
		/*
		 * -p asks the compiler to preprocess with the ANSI cpp
		 * rather than its built-in one. That is already what we
		 * do -- see the dopipe() below, which runs /bin/cpp and
		 * feeds the compiler on stdin -- so the request is
		 * satisfied by accepting it and passing nothing on.
		 *
		 * Forwarding it was fatal. cc/lex.c under debug['p']
		 * calls myaccess(file) before forking its own cpp, and
		 * with input arriving on a pipe, file is the literal
		 * string "stdin":
		 *
		 *   <eof> stdin does not exist
		 *
		 * make, patch and diff all carry -p in CFLAGS.
		 */
		case 'p':
			break;
		case 'W':
			s = ARGF();
			if(s && s[1]==',') {
				switch (s[0]) {
				case 'p':
					append(&cpp, s+2);
					break;
				case '0':
					append(&cc, s+2);
					break;
				case 'l':
					append(&ldargs, s+2);
					break;
				default:
					fprint(2, "cc: pass letter after -W should be one of p0l; ignored\n");
				}
			} else
				fprint(2, "cc: bad option after -W; ignored\n");
			break;
		case 'v':
			vflag = 1;
			append(&ldargs, "-v");
			break;
		case 'A':
			Aflag = 1;
			break;
		case 'S':
			Sflag = 1;
			break;
		/*
		 * -V and -+ belong to cpp, not here: cpp/nlist.c has -V
		 * for verbose and -+ ignored for compatibility. Four
		 * mkfiles used to say "-FVp", which meant one
		 *
		 *   cc: flag -V ignored
		 *
		 * per source file and nothing else. Pass cpp flags with
		 * -Wp, if they are actually wanted.
		 */
		default:
			fprint(2, "cc: flag -%c ignored\n", ARGC());
			break;
		} ARGEND
		if(!Aflag) {
			/*
			 * `-J' USED TO BE APPENDED HERE and is not any more.
			 * It is safe to drop because it never did anything:
			 * stock `cc' names no -J, so it reached ARGBEGIN's
			 * default and set debug['J'], which no file in this
			 * tree reads. Now that -J means conforming struct
			 * layout, leaving it here would make that the
			 * DEFAULT for every APE compile without -A or -B --
			 * see the case 'J' arm above.
			 */
			append(&cc, "-B");		/* turn off non-prototype warnings */
			Aflag = 1;
		}
		if(argc > 0) {
			s = argv[0];
			suf = utfrrune(s, '.');
			if(suf) {
				suf++;
				/*
				 * .i is C that has already been through
				 * the preprocessor. gcc and clang both
				 * take it, and a driver that runs cpp
				 * itself and hands on the result relies
				 * on it: objc(1) writes cpp's output,
				 * feeds it to objc1, and gives what
				 * comes back to the C compiler as
				 * <name>.i. Without this that argument
				 * matched nothing here and was dropped
				 * without a word, leaving
				 *
				 *	cc: no files to compile or load
				 *
				 * 6c preprocesses it a second time,
				 * which costs a pass and changes
				 * nothing: what objc1 emits carries
				 * #line directives and no other
				 * directives at all.
				 */
				if(strcmp(suf, "c") == 0 ||
				   strcmp(suf, "i") == 0) {
					append(&srcs, s);
					append(&objs, changeext(s, objext));
				} else if(strcmp(suf, "o") == 0 ||
					  strcmp(suf, ot->o) == 0 ||
					  strcmp(suf, "a") == 0 ||
					  (suf[0] == 'a' && strcmp(suf+1, ot->o) == 0)) {
					append(&objs, s);
				} else if(utfrune(allos, suf[0]) != 0) {
					fprint(2, "cc: argument %s ignored: wrong architecture\n",
						s);
				}
			}
		}
	}
	/*
	 * CONFORMING STRUCT LAYOUT IS THE DEFAULT FOR EVERY APE COMPILE,
	 * and `pcc' is where it has to be switched on. Not CFLAGS: `-J'
	 * in `sys/src/ape/config' reaches 32 of 137 mkfiles, since the
	 * other 105 ASSIGN `CFLAGS=' rather than appending `$CFLAGS' --
	 * `cmd/cfront/mkfile:52' among them. Not CC either: 59 mkfiles
	 * reassign that. *Both of the two variables a build system offers
	 * for exactly this have holes*, and either would have left 32
	 * packages conforming and 105 not, linking cleanly, disagreeing
	 * about `pthread_mutex_t' and `sockaddr_in' in silence. Every one
	 * of those 59 still names `pcc', so this is the one place that
	 * reaches all of them.
	 *
	 * **Here rather than in the ARGBEGIN loop, and unconditional
	 * rather than under `if(!Aflag)'.** That block does not run when
	 * -A or -B was given, and `cmd/cfront' passes -B -- so putting it
	 * there would miss the one package this flag was built for. The
	 * loop runs once per file argument, which is why the appends are
	 * out here where they happen exactly once.
	 *
	 * Native `6c' is untouched and keeps the 9front rule, which is
	 * what `cmd2/vts' and `vtwin' need when they link the host's own
	 * `libc.a': `Lock' is one `int', 4 naturally and 8 under that
	 * rule, and it sits inside `QLock', `Ref' and `Rendez'.
	 *
	 * MEASURED BEFORE IT WAS TURNED ON, by `apeabi-probe' compiled
	 * twice and diffed: it moves SIXTEEN structs, the network address
	 * family (`sockaddr_in' 24 -> 16, which is what every other system
	 * says) and the lock/pthread family (`pthread_mutex_t' 56 -> 40),
	 * plus `termios'. **`FILE', `struct stat', `DIR', `jmp_buf',
	 * `fd_set', `tm', `dirent', `passwd', `regex_t' and `sigset_t' do
	 * not move at all** -- which is the result, since those are the
	 * types that made this all-or-nothing in the first place.
	 *
	 * IT NEEDS `mk distclean' BEFORE `mk install'. No mkfile here
	 * lists a system header as a dependency, and nothing about this
	 * change makes a link fail, so a half-rebuilt tree is quiet.
	 */
	if(!oldalign) {
		append(&cc, "-J");
		append(&cpp, "-D__APEXP_CONFORMALIGN__=1");
	}
	if(objs.n == 0)
		fatal("no files to compile or load");
	/*
	 * -g asks for debugging output, which now means ELF64 with DWARF
	 * straight from the linker. It used to mean something else: the
	 * compiler wrote a .dwtypes type-info sidecar per object and a
	 * post-link pass, dw2elf, folded a.out plus sidecars into ELF64.
	 * dw2elf was removed once the linkers could emit ELF themselves,
	 * but pcc kept exec'ing it, so -g failed outright.
	 *
	 * Only 6l reads -H5 as ELF64. Every other linker already had a
	 * meaning for that number -- ipaq on 5l, sgi elf on vl, blue gene
	 * on ql -- and each wants -T and -R values to go with it, so it
	 * cannot be passed blindly. 5l and 7l spell elf -H7. Say so
	 * rather than emitting a wrong-format binary.
	 */
	if(gflag && !cflag) {
		if(strcmp(ot->ld, "6l") == 0)
			append(&ldargs, "-H5");
		else
			fprint(2, "cc: -g: no ELF output for %s; "
				"linking normally\n", ot->name);
	}
	ccpath = smprint("/bin/%s", ot->cc);
	append(&cpp, smprint("-I/%s/include/ape", ot->name));
	append(&cpp, "-I/sys/include/ape");
	cppn = cpp.n;
	ccn = cc.n;
	/*
	 * _DWTYPES used to be set here and cleared after the loop. It told
	 * cc/dwtypes.c to write a .dwtypes type-info sidecar beside each
	 * object, which only dw2elf ever read. With dw2elf gone the
	 * sidecars had no reader, so setting it only littered the build
	 * directory. cc/dwtypes.c is left in place: reviving the sidecar
	 * means restoring these two putenv calls and a consumer.
	 */
	for(i = 0; i < srcs.n; i++) {
		append(&cpp, srcs.strings[i]);
		if(Eflag)
			doexec("/bin/cpp", &cpp);
		else {
			if(Sflag)
				append(&cc, "-S");
			else {
				append(&cc, "-o");
				if (haveoname && cflag)
					append(&cc, oname);
				else
					append(&cc, changeext(srcs.strings[i], objext));
			}
			dopipe("/bin/cpp", &cpp, ccpath, &cc);
		}
		cpp.n = cppn;
		cc.n = ccn;
	}
	if(!cflag) {
		append(&ld, "-o");
		append(&ld, oname);
		for(i = 0; i < ldargs.n; i++)
			append(&ld, ldargs.strings[i]);
		for(i = 0; i < objs.n; i++)
			append(&ld, objs.strings[i]);
		append(&ld, smprint("/%s/lib/ape/libap.a", ot->name));
		doexec(smprint("/bin/%s", ot->ld), &ld);
		if(objs.n == 1 && strcmp(objext, "o") == 0)
			remove(objs.strings[0]);	/* cc mode only: clean up .o intermediate */
	}

	exits(0);
}

char *
searchlib(char *s, char *objtype)
{
	char *l;
	int i;

	if(!s)
		return 0;
	for(i = srchlibs.n-1; i>=0; i--) {
		l = smprint("%s/lib%s.a", srchlibs.strings[i], s);
		if(access(l, 0) >= 0)
			return l;
	}
	if(s[1] == 0)
		switch(s[0]) {
		case 'c':
			l = smprint("/%s/lib/ape/libap.a", objtype);
			break;
		case 'm':
			l = smprint("/%s/lib/ape/libap.a", objtype);
			break;
		case 'l':
			l = smprint("/%s/lib/ape/libl.a", objtype);
			break;
		case 'y':
			l = smprint("/%s/lib/ape/liby.a", objtype);
			break;
		default:
			l = 0;
		}
	else
		l = 0;
	return l;
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
doexec(char *c, List *a)
{
	Waitmsg *w;

	if(vflag) {
		printlist(a);
		fprint(2, "\n");
	}
	switch(fork()) {
	case -1:
		fatal("fork failed");
	case 0:
		exec(c, a->strings);
		fatal("exec failed");
	}
	if((w = wait()) == nil)
		fatal("wait failed");
	if(w->msg[0])
		fatal(smprint("%s: %s", a->strings[0], w->msg));
	free(w);
}

void
dopipe(char *c1, List *a1, char *c2, List *a2)
{
	Waitmsg *w;
	int pid1, got;
	int fd[2];

	if(vflag) {
		printlist(a1);
		fprint(2, " | ");
		printlist(a2);
		fprint(2, "\n");
	}
	if(pipe(fd) < 0)
		fatal("pipe failed");
	switch((pid1 = fork())) {
	case -1:
		fatal("fork failed");
	case 0:
		dup(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		exec(c2, a2->strings);
		fatal("exec failed");
	}
	switch(fork()) {
	case -1:
		fatal("fork failed");
	case 0:
		close(0);
		dup(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		exec(c1, a1->strings);
		fatal("exec failed");
	}
	close(fd[0]);
	close(fd[1]);
	for(got = 0; got < 2; got++) {
		if((w = wait()) == nil)
			fatal("wait failed");
		if(w->msg[0])
			fatal(smprint("%s: %s", (w->pid == pid1) ? a1->strings[0] : a2->strings[0], w->msg));
		free(w);
	}
}

Objtype *
findoty(void)
{
	char *o;
	Objtype *oty;

	o = getenv("objtype");
	if(!o)
		fatal("no $objtype in environment");
	for(oty = objtype; oty < &objtype[Nobjs]; oty++)
		if(strcmp(o, oty->name) == 0)
			return oty;
	fatal("unknown $objtype");
	return 0;			/* shut compiler up */
}

void
fatal(char *msg)
{
	fprint(2, "cc: %s\n", msg);
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
