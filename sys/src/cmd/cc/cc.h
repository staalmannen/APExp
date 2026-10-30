#include <u.h>
#include <libc.h>
#include <bio.h>
#include <ctype.h>

#pragma	lib	"../cc/cc.a$O"

#include "../cc/compat.h"

typedef	struct	Node	Node;
typedef	struct	Sym	Sym;
typedef	struct	Type	Type;
typedef	struct	Funct	Funct;
typedef	struct	Decl	Decl;
typedef	struct	Io	Io;
typedef	struct	Hist	Hist;
typedef	struct	Term	Term;
typedef	struct	Init	Init;
typedef	struct	Bits	Bits;
typedef	struct	Spec	Spec;

#define	NHUNK		50000L
#define	BUFSIZ		IOUNIT
#define	NSYMB		1500
#define	NHASH		1024
#define	STRINGSZ	200
#define	HISTSZ		20
#define YYMAXDEPTH	1500
#define	NTERM		10
#define	MAXALIGN	7
/*
 * Backported from 9front 9932a824a (2026-03-02), "cc: bump max include
 * directories limit".  Twenty was the limit since forever, and APExp
 * reaches it easily: `mount-include' binds four trees, gnulib packages
 * pass -I for the shared tree, the package tree and lib/, and EDG's
 * driver adds several more.  The twenty-first -I was a hard diag.
 *
 * `lex.c' bounds the array with nelem(include), so this is the only
 * line that has to move.
 */
#define	NINCLUDE	64

#define	SIGN(n)		(1ULL<<(n-1))
#define	MASK(n)		(SIGN(n)|(SIGN(n)-1))

#define	BITS	5
/*
 * NVAR is 32 bits per word and NOT sizeof(ulong)*8, because `bits.c'
 * hardcodes 32: `bsetc' is `c.b[n/32] = 1L << (n%32)' and `bset'/`bnum'
 * match it. The two agree only where `ulong' is 32 bits wide, which is
 * every kencc target -- so this was right by coincidence rather than by
 * construction, and a `ulong' of any other width makes NVAR claim
 * variables that `bits.c' cannot address. The register allocator then
 * reads bits nothing ever set.
 *
 * ***A LATENT OUT-OF-BOUNDS WRITE, NOT A BUG ANYTHING HAS OBSERVED.***
 * Found by reading, while building kencc with gcc
 * (`sys/lib/tests/hostkencc/'), where `ulong' is 64 bits: NVAR was
 * then 320 while `b[]' holds 5 words, so `bsetc(319)' writes `b[9]'
 * -- four words past the end of the struct. Nothing in the host build
 * reached it, because only a function with more than 160 register
 * candidates would, and on Plan 9 the value is unchanged
 * (5*4*8 == 5*32), so this is provably inert for every shipped
 * compiler.
 *
 * **It is NOT the explanation for anything the host build printed**,
 * and the thing it was first blamed for was not a fault at all:
 * `6c -S' on `int f(int x){return x;}' answers `MOVL BP,AX', which
 * looks like a parameter register-allocated with nothing loading it
 * and is in fact correct -- `6.out.h:811' is `REGARG = D_BP', so
 * kencc's amd64 convention passes the first word-sized argument in
 * BP and `pgen.c:57' spills it. *The output was called wrong before
 * the convention was looked up*, which is this tree's own rule about
 * reading what the code does rather than what it looks like.
 */
#define	NVAR	(BITS*32)
struct	Bits
{
	ulong	b[BITS];
};

/*
 * 9front a68335214: the two halves of a declaration specifier,
 * carried separately instead of OR'd into one long.
 */
struct	Spec
{
	ulong	type;
	ulong	class;
};

struct	Node
{
	Node*	left;
	Node*	right;
	void*	label;
	long	pc;
	int	reg;
	long	xoffset;
	double	fconst;		/* fp constant */
	vlong	vconst;		/* non fp const */
	char*	cstring;	/* character string */
	Rune*	rstring;	/* rune string */

	Sym*	sym;
	Type*	type;
	long	lineno;
	char	op;
	char	oldop;
	char xcast;
	char	class;
	char	etype;
	char	complex;
	char	addable;
	char	scale;
	char	garb;
};
#define	Z	((Node*)0)

struct	Sym
{
	Sym*	link;
	Type*	type;
	Type*	suetag;
	Type*	tenum;
	char*	macro;
	long	varlineno;
	long	offset;
	vlong	vconst;
	double	fconst;
	Node*	label;
	ushort	lexical;
	char	*name;
	ushort	block;
	ushort	sueblock;
	char	class;
	char	sym;
	char	aused;
	char	sig;
};
#define	S	((Sym*)0)

enum{
	SIGNONE = 0,
	SIGDONE = 1,
	SIGINTERN = 2,

	SIGNINTERN = 1729*325*1729,
};

struct	Decl
{
	Decl*	link;
	Sym*	sym;
	Type*	type;
	long	varlineno;
	long	offset;
	short	val;
	ushort	block;
	char	class;
	char	aused;
};
#define	D	((Decl*)0)

struct	Type
{
	Sym*	sym;
	Sym*	tag;
	Funct*	funct;
	Type*	link;
	Type*	down;
	long	width;
	long	offset;
	long	lineno;
	schar	shift;
	char	nbits;
	char	etype;
	char	garb;
	char	vla;		/* 1 = variable-length array */
	char	isbool;		/* declared bool/_Bool; see typebool */
	Node*	vlasizevar;	/* hidden auto holding runtime byte count (VLA only) */
	short	alignas_req;	/* _Alignas() override; 0 = use type's natural alignment */
	short	talign;		/* struct/union natural alignment; 0 = not computed. See -P. */
};

#define	T	((Type*)0)
#define	NODECL	((void(*)(int, Type*, Sym*))0)

struct	Init			/* general purpose initialization */
{
	int	code;
	ulong	value;
	char*	s;
};

EXTERN struct
{
	char*	p;
	int	c;
} fi;

#define	GETC()	((--fi.c < 0)? filbuf(): (*fi.p++ & 0xff))

struct	Io
{
	Io*	link;
	char*	p;
	char	b[BUFSIZ];
	short	c;
	short	f;
};
#define	I	((Io*)0)

struct	Hist
{
	Hist*	link;
	char*	name;
	long	line;
	long	offset;
};
#define	H	((Hist*)0)
EXTERN Hist*	hist;

struct	Term
{
	vlong	mult;
	Node	*node;
};

enum
{
	Axxx,
	Ael1,
	Ael2,
	Asu2,
	Aarg0,
	Aarg1,
	Aarg2,
	Aaut3,
	NALIGN,
};

enum
{
	DMARK,
	DAUTO,
	DSUE,
	DLABEL,
};
enum
{
	OXXX,
	OADD,
	OADDR,
	OAND,
	OANDAND,
	OARRAY,
	OAS,
	OASI,
	OASADD,
	OASAND,
	OASASHL,
	OASASHR,
	OASDIV,
	OASHL,
	OASHR,
	OASLDIV,
	OASLMOD,
	OASLMUL,
	OASLSHR,
	OASMOD,
	OASMUL,
	OASOR,
	OASSUB,
	OASXOR,
	OBIT,
	OBREAK,
	OCASE,
	OCAST,
	OCOMMA,
	OCOND,
	OCONST,
	OCONTINUE,
	ODIV,
	ODOT,
	ODOTDOT,
	ODWHILE,
	OENUM,
	OEQ,
	OFOR,
	OFUNC,
	OGE,
	OGOTO,
	OGT,
	OHI,
	OHS,
	OIF,
	OIND,
	OINDREG,
	OINIT,
	OLABEL,
	OLDIV,
	OLE,
	OLIST,
	OLMOD,
	OLMUL,
	OLO,
	OLS,
	OLSHR,
	OLT,
	OMOD,
	OMUL,
	ONAME,
	ONE,
	ONOT,
	OOR,
	OOROR,
	OPOSTDEC,
	OPOSTINC,
	OPREDEC,
	OPREINC,
	OPROTO,
	OREGISTER,
	ORETURN,
	OROL,
	OSET,
	OSIGN,
	OSIZE,
	OTYPEOF,	/* typeof(expr) / typeof(type) — C23/GCC extension */
	OTYPEOF_UNQUAL,	/* typeof_unqual(expr) — C23 extension */
	OALIGNOF,	/* _Alignof(type) / __alignof__(type) — C11/GCC */
	OSTRING,
	OLSTRING,
	OSTRUCT,
	OSUB,
	OSWITCH,
	OUNION,
	OUSED,
	OWHILE,
	OXOR,
	ONEG,
	OCOM,
	OPOS,
	OELEM,

	OTST,		/* used in some compilers */
	OINDEX,
	OFAS,
	OREGPAIR,
	OEXREG,

	OALLOCA,	/* VLA: runtime stack allocation */
	OVLAVAR,	/* VLA: unspecified dimension [*] in prototype */

	OEND
};
enum
{
	TXXX,
	TCHAR,
	TUCHAR,
	TSHORT,
	TUSHORT,
	TINT,
	TUINT,
	TLONG,
	TULONG,
	TVLONG,
	TUVLONG,
	TFLOAT,
	TDOUBLE,
	TIND,
	TFUNC,
	TARRAY,
	TVOID,
	TSTRUCT,
	TUNION,
	TENUM,
	TDOT,
	NTYPE,

	/* C99 complex number types */
	TCFLOAT		= NTYPE,	/* float _Complex  (2 floats,  8 bytes) */
	TCDOUBLE,			/* double _Complex (2 doubles, 16 bytes) */
	NCTYPE,				/* total type codes including complex */

	/*
	 * 9front a68335214, "cc: untangle class and type specifiers".
	 *
	 * ***THE CLASS AND GARB CODES USED TO LIVE HERE, SHARING THIS
	 * NUMBERING WITH THE TYPES, AND THAT IS WHAT RAN OUT.*** Every
	 * `B...' below is `1L<<T...', so one `long' had to hold the
	 * types AND the storage classes AND the qualifiers; `BNORET'
	 * had reached `1L<<31' and `cc.y' carries a note about it.
	 * Upstream's fix is to number the classes separately (`CG...',
	 * from 0) and to pass the two halves as a `Spec' rather than
	 * one word.  **That is headroom APExp needs rather than
	 * upstream hygiene**: `_Complex', `_Alignas' and `_Generic'
	 * all want type codes.
	 *
	 * ***AND THE MERGE IS NOT UPSTREAM'S PATCH.*** Upstream puts
	 * `TUNSIGNED' at `NTYPE'. APExp already put `TCFLOAT' there,
	 * so before this commit `TCFLOAT' and `TAUTO' were THE SAME
	 * NUMBER, as were `TCDOUBLE' and `TEXTERN'. That was harmless
	 * only because the two never met: the complex codes are
	 * `etype' values indexing `[NCTYPE]' arrays and never enter
	 * the `B...' bit space -- `grep` for `BCFLOAT' finds nothing.
	 * *A collision that is harmless because of how the values
	 * happen to be used is one the next change can expose*, and
	 * this is that change. The pseudo-types now start at `NCTYPE',
	 * after the complex codes, so nothing aliases anything.
	 */
	TUNSIGNED = NCTYPE,
	TSIGNED,
	TOLD,
	NALLTYPES,

	/* Storage classes and qualifiers, in their OWN numbering. */
	CGXXX	= 0,
	CGAUTO,
	CGEXTERN,
	CGSTATIC,
	CGTYPEDEF,
	CGTYPESTR,
	CGREGISTER,
	CGCONSTNT,
	CGVOLATILE,
	CGNORET,
	NCGTYPE,

	TRUNE	= sizeof(Rune)==4? TUINT: TUSHORT,
};
enum
{
	CXXX,
	CAUTO,
	CEXTERN,
	CGLOBL,
	CSTATIC,
	CLOCAL,
	CTYPEDEF,
	CTYPESTR,
	CPARAM,
	CSELEM,
	CLABEL,
	CEXREG,
	NCTYPES,
};
enum
{
	GXXX		= 0,
	GCONSTNT	= 1<<0,
	GVOLATILE	= 1<<1,
	GNORET		= 1<<2,
	NGTYPES		= 1<<4,

	GINCOMPLETE	= 1<<3,
};
enum
{
	BCHAR		= 1L<<TCHAR,
	BUCHAR		= 1L<<TUCHAR,
	BSHORT		= 1L<<TSHORT,
	BUSHORT		= 1L<<TUSHORT,
	BINT		= 1L<<TINT,
	BUINT		= 1L<<TUINT,
	BLONG		= 1L<<TLONG,
	BULONG		= 1L<<TULONG,
	BVLONG		= 1L<<TVLONG,
	BUVLONG		= 1L<<TUVLONG,
	BFLOAT		= 1L<<TFLOAT,
	BDOUBLE		= 1L<<TDOUBLE,
	BIND		= 1L<<TIND,
	BFUNC		= 1L<<TFUNC,
	BARRAY		= 1L<<TARRAY,
	BVOID		= 1L<<TVOID,
	BSTRUCT		= 1L<<TSTRUCT,
	BUNION		= 1L<<TUNION,
	BENUM		= 1L<<TENUM,
	BDOT		= 1L<<TDOT,
	BUNSIGNED	= 1L<<TUNSIGNED,
	BSIGNED		= 1L<<TSIGNED,

	/*
	 * These live in `Spec.class', numbered from 0, and no longer
	 * compete with the types above for room in a 32-bit long.
	 * The comment that used to sit below BNUMBER -- "these can be
	 * overloaded with complex types" -- described the aliasing
	 * this commit removes, so it is gone with it.
	 */
	BAUTO		= 1L<<CGAUTO,
	BEXTERN		= 1L<<CGEXTERN,
	BSTATIC		= 1L<<CGSTATIC,
	BTYPEDEF	= 1L<<CGTYPEDEF,
	BTYPESTR	= 1L<<CGTYPESTR,
	BREGISTER	= 1L<<CGREGISTER,
	BCONSTNT	= 1L<<CGCONSTNT,
	BVOLATILE	= 1L<<CGVOLATILE,
	BNORET		= 1L<<CGNORET,

	BINTEGER	= BCHAR|BUCHAR|BSHORT|BUSHORT|BINT|BUINT|
				BLONG|BULONG|BVLONG|BUVLONG,
	BNUMBER		= BINTEGER|BFLOAT|BDOUBLE,

	BCLASS		= BAUTO|BEXTERN|BSTATIC|BTYPEDEF|BTYPESTR|BREGISTER,
	BGARB		= BCONSTNT|BVOLATILE|BNORET
};

struct	Funct
{
	Sym*	sym[OEND];
	Sym*	castto[NTYPE];
	Sym*	castfr[NTYPE];
};

EXTERN struct
{
	Type*	tenum;		/* type of entire enum */
	Type*	cenum;		/* type of current enum run */
	vlong	lastenum;	/* value of current enum */
	double	floatenum;	/* value of current enum */
} en;

EXTERN	int	autobn;
EXTERN	long	autoffset;
EXTERN	int	blockno;
EXTERN	Decl*	dclstack;
EXTERN	char	debug[256];
EXTERN	Hist*	ehist;
EXTERN	long	firstbit;
EXTERN	Sym*	firstarg;
EXTERN	Type*	firstargtype;
EXTERN	Decl*	firstdcl;
EXTERN	int	fperror;
EXTERN	Sym*	hash[NHASH];
EXTERN	int	hasdoubled;
EXTERN	char*	include[NINCLUDE];
EXTERN	Io*	iofree;
EXTERN	Io*	ionext;
EXTERN	Io*	iostack;
EXTERN	long	lastbit;
EXTERN	char	lastclass;
EXTERN	Type*	lastdcl;
EXTERN	long	lastfield;
EXTERN	Type*	lasttype;
EXTERN	long	lineno;
EXTERN	long	nearln;
EXTERN	int	nerrors;
EXTERN	int	newflag;
EXTERN	int	ninclude;
EXTERN	Node*	nodproto;
EXTERN	Node*	nodcast;
EXTERN	Biobuf	outbuf;
EXTERN	Biobuf	diagbuf;
EXTERN	char*	outfile;
EXTERN	char*	pathname;
EXTERN	int	peekc;
EXTERN	long	stkoff;
EXTERN	Type*	strf;
EXTERN	Type*	strl;
EXTERN	char	symb[NSYMB];
EXTERN	Sym*	symstring;
EXTERN	int	taggen;
EXTERN	Type*	tfield;
EXTERN	Type*	tufield;
EXTERN	int	thechar;
EXTERN	char*	thestring;
EXTERN	Type*	thisfn;
EXTERN	Node*	thisfnnode;
EXTERN	Type*	types[NCTYPE];		/* extended to hold TCFLOAT, TCDOUBLE */
/*
 * bool/_Bool. Its representation is unsigned char -- there is no TBOOL
 * etype -- but it carries the isbool mark so that com.c can tell it
 * from a plain unsigned char and give conversions to it the semantics
 * C99 6.3.1.2 requires: a comparison against zero, not a truncation.
 *
 * The mark is a field rather than the identity of this one Type,
 * because a type is copied whenever it is used: copytyp() is a struct
 * copy, and dcl.c copies a parameter's type to chain it into a
 * prototype and copies again for const/volatile. Pointer identity
 * therefore survives a cast and a return, but not a declaration or a
 * parameter -- which is exactly the set of cases that used to fail.
 */
EXTERN	Type*	typebool;
EXTERN	Type*	fntypes[NTYPE];
EXTERN	Node*	initlist;
EXTERN	Term	term[NTERM];
EXTERN	int	nterm;
EXTERN	int	packflg;
/*
 * -J: lay structs out the way every other C compiler does -- tail
 * padding to the struct's OWN alignment rather than always 8, and a
 * nested struct member aligned to ITS own alignment rather than
 * always 8. Off by default, because the 9front ABI is the other rule
 * and everything native is already built to it.
 *
 * **It is NOT `-P', which the recorded plan named.** Every backend's
 * peep.c uses `debug['P']' for peephole tracing and reg.c reads it to
 * disable register allocation, so -P would have changed code
 * generation while claiming to change layout. *A flag one letter from
 * another flag is checked, not recalled* -- and the plan had argued
 * from `ARGBEGIN's default arm takes any unknown letter', which is
 * true and did not make P unknown. A named global rather than a
 * debug letter so the next reader cannot repeat it.
 *
 * **IT IS NOT A PER-PACKAGE FLAG, and that is the opposite of how it
 * is natural to reach for it.** -J changes the layout of EVERY struct
 * the translation unit sees, including the ones in <stdio.h> and
 * <sys/stat.h>. Build one package with it against a libap built
 * without it and the two disagree about `FILE', `struct stat' and
 * `DIR' -- silently, with no link error, because the symbols all
 * resolve. The unit it is safe over is a whole self-consistent world:
 * all of APE, after `mk distclean', or nothing.
 *
 * For a handful of on-disk structs in one package, `#pragma pack
 * on'/`off' is still the right tool and costs no rebuild -- that is
 * what tar.h carries, and tar is the reason this flag exists.
 */
EXTERN	int	conformalign;

/*
 * -C: MARK EVERY TEXT AND GLOBL IN THIS TRANSLATION UNIT `DUPOK',
 * so the linker keeps the first definition of a symbol and silently
 * discards later ones.  That is COMDAT -- what C++ calls vague
 * linkage and what every other toolchain spells
 * `__attribute__((weak))' or a .section .gnu.linkonce.
 *
 * **THE LINKER ALREADY DOES ALL OF THIS AND NOTHING COULD ASK IT.**
 * `6l/obj.c:996' is `if(p->from.scale & DUPOK){ skip = 1; goto
 * casdef; }' on a duplicate ATEXT, and `6l/asm.c:548' uses
 * `sym->dupok' to suppress `multiple initialization' for duplicate
 * DATA.  `DUPOK' is `(1<<1)' in eight `*.out.h'.  The one missing
 * piece was a way for C to set the bit: `gpseudo()' wrote
 * `p->from.scale = (profileflg ? 0 : NOPROF)' and nothing ever OR'd
 * anything into it.  *The sixth time this tree has found a working
 * implementation of the thing it could not do sitting next to the
 * thing that could not do it.*
 *
 * WHY IT EXISTS: EDG's generated C.  A C++ front end lowered to C
 * emits inline members, template instantiations, vtables and typeinfo
 * into EVERY translation unit that uses them, because C has no way to
 * say "one of these, any of them".  Across `sys/src/external/edg/src'
 * that is **3,124 symbols defined in more than one of 75 objects and
 * 6,410 surplus definitions** -- `edg::skip_typerefs' alone is
 * emitted 41 times -- and `6l' answered `redefinition:' until it hit
 * `too many errors'.  EDG knows exactly which symbols these are and
 * already has a way to say so (it emits 26,712
 * `__attribute__((__weak__))' when its target is gcc); kencc had
 * nowhere to put the answer.
 *
 * IT IS PER TRANSLATION UNIT AND BLUNT, which is the honest
 * description.  It does not mark the vague-linkage entities, it marks
 * EVERYTHING, so two genuinely different functions with one name
 * become first-wins instead of a diagnostic.  That is safe for
 * generated C where every duplicate is the same entity by
 * construction, and it is not safe as a default -- so nothing in the
 * tree passes it but `sys/src/ape/cmd/edg'.  The precise version is
 * to teach `cc' `__attribute__((__weak__))' and set the bit per
 * symbol; this is the version that needs no re-translation.
 *
 * SEVEN TARGETS HONOUR IT, AND THE OTHER FOUR SAY SO RATHER THAN GO
 * QUIET.  `5l', `6l', `7l', `8l', `kl', `ql' and `vl' read `dupok';
 * **`9l' DECLARES THE FIELD IN `l.h' AND NEVER READS IT** -- a
 * pre-existing oversight found by this change and recorded, not fixed
 * -- and `1l'/`2l' have no such field at all.  On those four the
 * backend's `gpseudo()' diagnoses instead of setting a bit the linker
 * will ignore, because a flag that silently does nothing produces a
 * link failure that looks like something else entirely.
 */
EXTERN	int	dupokall;
EXTERN	int	alignasval;	/* pending _Alignas() requirement; 0 = none */
EXTERN	int	fproundflg;
EXTERN	int	profileflg;
EXTERN	int	ncontin;
EXTERN	int	newvlongcode;
EXTERN	int	canreach;
EXTERN	int	warnreach;
EXTERN	Bits	zbits;
EXTERN	int	vlanest;	/* depth of VLA scopes in current function */
EXTERN	long	vlaseq;		/* counter for unique _vla<N> hidden variable names */

extern	char	*onames[], *tnames[], *gnames[];
extern	char	*cnames[], *qtnames[], *qcnames[];
extern	char	*bnames[];
extern	char	tab[NTYPE][NTYPE];
extern	char	comrel[], invrel[], logrel[];
extern	long	ncast[], tadd[], tand[];
extern	long	targ[], tasadd[], tasign[], tcast[];
extern	long	tdot[], tfunct[], tindir[], tmul[];
extern	long	tnot[], trel[], tsub[];

extern	char	typeaf[];
extern	char	typefd[];
extern	char	typei[];
extern	char	typesu[];
extern	char	typesuv[];
extern	char	typesuc[];	/* typesu plus complex; see sub.c */
extern	char	typeu[];
extern	char	typev[];
extern	char	typec[];
extern	char	typeh[];
extern	char	typeil[];
extern	char	typeilp[];
extern	char	typechl[];
extern	char	typechlv[];
extern	char	typechlvp[];
extern	char	typechlp[];
extern	char	typechlpfd[];

EXTERN	char*	typeswitch;
EXTERN	char*	typeword;
EXTERN	char*	typecmplx;		/* points into typesuv; covers TCFLOAT/TCDOUBLE too */
EXTERN	char	typecmplxv[NCTYPE];	/* separate predicate: only TCFLOAT and TCDOUBLE */

#define	iscmplx(et)	((et) == TCFLOAT || (et) == TCDOUBLE)

/* C99 _Complex support — cmplx.c */
Type*	cplxbase(int);		/* TCFLOAT->types[TFLOAT], TCDOUBLE->types[TDOUBLE] */
Type*	mkcplxtype(int);	/* given real or complex etype, return complex type */
Node*	cplxre(Node*);		/* lvalue node for real component */
Node*	cplxim(Node*);		/* lvalue node for imaginary component */
Node*	cplxcast(Node*, Type*);	/* promote real node to complex, or recast */
void	cplxarith(Node*);	/* expand complex arithmetic node in-place */

extern	ulong	thash1;
extern	ulong	thash2;
extern	ulong	thash3;
extern	ulong	thash[];

/*
 *	parser
 */
int	yyparse(void);
int	mpatov(char*, vlong*);

/*
 *	lex.c
 */
void	cinit(void);
int	compile(char*, char**, int);
void	errorexit(void);
int	filbuf(void);
int	getc(void);
long	getr(void);
int	getnsc(void);
Sym*	lookup(void);
void	main(int, char*[]);
void	newfile(char*, int);
void	newio(void);
void	pushio(void);
long	escchar(long, int, int);
Sym*	slookup(char*);
void	syminit(Sym*);
void	unget(int);
long	yylex(void);
int	Lconv(Fmt*);
int	Tconv(Fmt*);
int	FNconv(Fmt*);
int	Oconv(Fmt*);
int	Qconv(Fmt*);
int	VBconv(Fmt*);
void	setinclude(char*);

/*
 * mac.c
 */
void	dodefine(char*);
void	domacro(void);
Sym*	getsym(void);
long	getnsn(void);
void	linehist(char*, int);
void	macdef(void);
void	macprag(void);
void	macend(void);
int	macexpand(Sym*, char*, int);
void	macif(int);
void	macinc(void);
void	maclin(void);
void	macund(void);

/*
 * dcl.c
 */
Node*	doinit(Sym*, Type*, long, Node*);
Type*	tcopy(Type*);
Node*	init1(Sym*, Type*, long, int);
Node*	newlist(Node*, Node*);
void	adecl(int, Type*, Sym*);
Node*	compoundlit(Type*, Node*);
int	anyproto(Node*);
void	argmark(Node*, int);
void	dbgdecl(Sym*);
Node*	dcllabel(Sym*, int);
Node*	dodecl(void(*)(int, Type*, Sym*), int, Type*, Node*);
Sym*	mkstatic(Sym*);
void	doenum(Sym*, Node*);
void	snap(Type*);
Type*	dotag(Sym*, int, int);
void	edecl(int, Type*, Sym*);
Type*	fnproto(Node*);
Type*	fnproto1(Node*);
void	fndecls(int);
void	markdcl(void);
Type*	paramconv(Type*, int);
void	pdecl(int, Type*, Sym*);
Decl*	push(void);
Decl*	push1(Sym*);
Node*	revertdcl(void);
long	round(long, int);
int	ptrsignonly(Type*, Type*);
int	rsametype(Type*, Type*, int, int);
int	sametype(Type*, Type*);
ulong	sign(Sym*);
ulong	signature(Type*);
void	sualign(Type*);
void	tmerge(Type*, Sym*);
void	walkparam(Node*, int);
void	xdecl(int, Type*, Sym*);
Node*	contig(Sym*, Node*, long);

/*
 * com.c
 */
void	ccom(Node*);
void	complex(Node*);
int	tcom(Node*);
int	tcoma(Node*, Node*, Type*, int);
int	tcomd(Node*);
int	tcomo(Node*, int);
int	tcomx(Node*);
int	tlvalue(Node*);
void	constas(Node*, Type*, Type*);
Node*	uncomma(Node*);
Node*	uncomargs(Node*);

/*
 * con.c
 */
void	acom(Node*);
void	acom1(vlong, Node*);
void	acom2(Node*, Type*);
int	acomcmp1(const void*, const void*);
int	acomcmp2(const void*, const void*);
int	addo(Node*);
void	evconst(Node*);

/*
 * funct.c
 */
int	isfunct(Node*);
void	dclfunct(Type*, Sym*);

/*
 * sub.c
 */
void	arith(Node*, int);
int	castucom(Node*);
int	deadheads(Node*);
Type*	dotsearch(Sym*, Type*, Node*, long*);
long	dotoffset(Type*, Type*, Node*);
Node*	invert(Node*);
int	bitno(long);
void	makedot(Node*, Type*, long);
int	mixedasop(Type*, Type*);
Node*	new(int, Node*, Node*);
Node*	new1(int, Node*, Node*);
int	nilcast(Type*, Type*);
int	nocast(Type*, Type*);
void	prtree(Node*, char*);
void	prtree1(Node*, int, int);
void	relcon(Node*, Node*);
int	relindex(int);
int	simpleg(Spec);
Type*	garbt(Type*, Spec);
int	simplec(Spec);
Type*	simplet(Spec);
int	stcompat(Node*, Type*, Type*, long[]);
int	tcompat(Node*, Type*, Type*, long[]);
void	tinit(void);
Type*	typ(int, Type*);
Type*	copytyp(Type*);
void	typeext(Type*, Node*);
void	typeext1(Type*, Node*);
int	side(Node*);
int	zpconst(Node*);
int	vconst(Node*);
int	log2(uvlong);
int	vlog(Node*);
int	topbit(ulong);
int	fpnegzero(double);
double	fpnegzeroval(void);
void	simplifyshift(Node*);
void	rolor(Node*);
Spec	typebitor(Spec, Spec);
void	diag(Node*, char*, ...);
void	warn(Node*, char*, ...);
void	yyerror(char*, ...);
void	fatal(Node*, char*, ...);

/*
 * acid.c
 */
void	acidtype(Type*);
void	acidvar(Sym*);

/*
 * pickle.c
 */
void	pickletype(Type*);

/*
 * bits.c
 */
Bits	bor(Bits, Bits);
Bits	band(Bits, Bits);
Bits	bnot(Bits);
int	bany(Bits*);
int	bnum(Bits);
Bits	blsh(uint);
int	beq(Bits, Bits);
int	bset(Bits, uint);

/*
 * dpchk.c
 */
void	dpcheck(Node*);
void	arginit(void);
void	pragvararg(void);
void	pragpack(void);
void	pragfpround(void);
void pragprofile(void);
void	pragincomplete(void);

/*
 * calls to machine depend part
 */
void	codgen(Node*, Node*);
void	gclean(void);
void	gextern(Sym*, Node*, long, long);
void	ginit(void);
long	outstring(char*, long);
long	outlstring(Rune*, long);
void	sextern(Sym*, Node*, long, long);
void	xcom(Node*);
long	exreg(Type*);
long	align(long, Type*, int);
long	maxround(long, long);
void	gvlalloc(Type*, Node*);	/* emit runtime stack alloc for a VLA */
void	gvla_prologue(void);	/* save frame pointer before first VLA */
void	gvla_epilogue(void);	/* restore SP from frame pointer */
void	gret(void);		/* emit RET, restoring VLA frame first */

extern	schar	ewidth[];

/*
 * com64
 */
int	com64(Node*);
void	com64init(void);
void	bool64(Node*);
double	convvtof(vlong);
vlong	convftov(double);
double	convftox(double, int);
vlong	convvtox(vlong, int);

/*
 * machcap
 */
int	machcap(Node*);

#pragma	varargck	argpos	warn	2
#pragma	varargck	argpos	diag	2
#pragma	varargck	argpos	yyerror	1

#pragma	varargck	type	"F"	Node*
#pragma	varargck	type	"L"	long
#pragma	varargck	type	"Q"	long
#pragma	varargck	type	"O"	int
#pragma	varargck	type	"T"	Type*
#pragma	varargck	type	"|"	int
