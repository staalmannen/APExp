#define	INS	32768		/* input buffer */
#define	OBS	4096		/* outbut buffer */
#define	NARG	64		/* Max number arguments to a macro */
#define	NINCLUDE 64		/* Max number of include directories (-I) */
#define	NONCE	256		/* Max number of #pragma once directives */
#define	NIF	32		/* depth of nesting of #if */
#ifndef EOF
#define	EOF	(-1)
#endif
#ifndef NULL
#define NULL	0
#endif

enum toktype { END, UNCLASS, NAME, NUMBER, STRING, CCON, NL, WS, DSHARP,
		EQ, NEQ, LEQ, GEQ, LSH, RSH, LAND, LOR, PPLUS, MMINUS,
		ARROW, SBRA, SKET, LP, RP, DOT, AND, STAR, PLUS, MINUS,
		TILDE, NOT, SLASH, PCT, LT, GT, CIRC, OR, QUEST,
		COLON, ASGN, COMMA, XCOMMA, SHARP, SEMIC, CBRA, CKET,
		ASPLUS, ASMINUS, ASSTAR, ASSLASH, ASPCT, ASCIRC, ASLSH,
		ASRSH, ASOR, ASAND, ELLIPS,
		DSHARP1, NAME1, DEFINED, UMINUS, MAXTOK};

enum kwtype { KIF, KIFDEF, KIFNDEF, KELIF, KELSE, KENDIF, KINCLUDE, KINCLUDE_NEXT,
		KDEFINE, KUNDEF, KLINE, KERROR, KWARNING, KPRAGMA, KDEFINED,
		KLINENO, KFILE, KDATE, KTIME, KSTDC, KEVAL };

#define	ISDEFINED	01	/* has #defined value */
#define	ISKW		02	/* is PP keyword */
#define	ISUNCHANGE	04	/* can't be #defined in PP */
#define	ISMAC		010	/* builtin macro, e.g. __LINE__ */
#define	ISVARMAC	020	/* variadic macro */

#define	EOFC	0xFD		/* sentinel for end of input file */
#define	XPWS	1		/* token flag: white space to assure token sep. */

enum { Notinmacro, Inmacro };

typedef struct token {
	unsigned char	type;
	unsigned char 	flag;
	unsigned short	hideset;
	unsigned int	wslen;
	unsigned int	len;
	uchar	*t;
} Token;

typedef struct tokenrow {
	Token	*tp;		/* current one to scan */
	Token	*bp;		/* base (allocated value) */
	Token	*lp;		/* last+1 token used */
	int	max;		/* number allocated */
} Tokenrow;

typedef struct source {
	char	*filename;	/* name of file of the source */
	int	line;		/* current line number */
	int	lineinc;	/* adjustment for \\n lines */
	uchar	*inb;		/* input buffer */
	uchar	*inp;		/* input pointer */
	uchar	*inl;		/* end of input */
	int	fd;		/* input source */
	int	ifdepth;	/* conditional nesting in include */
	struct	source *next;	/* stack for #include */
	int	pos;		/* next position for #include_next */
} Source;

typedef struct nlist {
	struct nlist *next;
	uchar	*name;
	int	len;
	Tokenrow *vp;		/* value as macro */
	Tokenrow *ap;		/* list of argument names, if any */
	char	val;		/* value as preprocessor name */
	char	flag;		/* is defined, is pp name */
} Nlist;

typedef	struct nonce {
	Qid qid;
	uint type;
	uint dev;
} Once;

typedef	struct	includelist {
	char	deleted;
	char	always;
	char	*file;
} Includelist;

#define	new(t)	(t *)domalloc(sizeof(t))
#define	quicklook(a,b)	(namebit[(a)&077] & (1<<((b)&037)))
#define	quickset(a,b)	namebit[(a)&077] |= (1<<((b)&037))
extern	unsigned long namebit[077+1];

enum errtype { WARNING, ERROR, FATAL };

void	expandlex(void);
void	setup(int, char **);
#define gettokens cpp_gettokens
int	gettokens(Tokenrow *, int);
int	comparetokens(Tokenrow *, Tokenrow *);
Source	*setsource(char *, int, char *);
void	unsetsource(void);
void	puttokens(Tokenrow *);
void	process(Tokenrow *);
void	*dorealloc(void *, int);
void	*domalloc(int);
void	dofree(void *);
void	error(enum errtype, char *, ...);
void	flushout(void);
int	foldline(Source *);
Nlist	*lookup(Token *, int);
void	control(Tokenrow *);
void	dodefine(Tokenrow *);
void	doadefine(Tokenrow *, int);
void	doinclude(Tokenrow *, int);
void	doif(Tokenrow *, enum kwtype);
void	expand(Tokenrow *, Nlist *);
void	builtin(Tokenrow *, int);
int	gatherargs(Tokenrow *, Tokenrow **, int, int *);
void	substargs(Nlist *, Tokenrow *, Tokenrow **, int);
void	expandrow(Tokenrow *, char *);
void	maketokenrow(int, Tokenrow *);
Tokenrow *copytokenrow(Tokenrow *, Tokenrow *);
Token	*growtokenrow(Tokenrow *);
Tokenrow *normtokenrow(Tokenrow *);
void	adjustrow(Tokenrow *, int);
void	movetokenrow(Tokenrow *, Tokenrow *);
void	insertrow(Tokenrow *, int, Tokenrow *);
void	peektokens(Tokenrow *, char *);
void	glue(Tokenrow *, Token *, Token *);
Tokenrow *stringify(Tokenrow *);
int	lookuparg(Nlist *, Token *);
vlong	eval(Tokenrow *, int);
void	genline(void);
void	setempty(Tokenrow *);
void	makespace(Tokenrow *);
char	*outnum(char *, int);
int	digit(int);
uchar	*newstring(uchar *, int, int);
int	checkhideset(int, Nlist *);
void	prhideset(int);
int	newhideset(int, Nlist *);
int	unionhideset(int, int);
void	iniths(void);
void	setobjname(char *);
void	clearwstab(void);
#define	rowlen(tokrow)	((tokrow)->lp - (tokrow)->bp)

extern	char *outp;
extern	Token	nltoken;
extern	Source *cursource;
extern	char *curtime;
extern	int incdepth;
extern	int ifdepth;
extern	int ifsatisfied[NIF];
extern	int Mflag;
extern	int nolineinfo;
extern	int skipping;
extern	int verbose;
extern	int Cplusplus;
extern	Nlist *kwdefined;
extern	Includelist includelist[NINCLUDE];
extern	Once incblocked[NONCE];
extern	int nblocked;
extern	char wd[];
