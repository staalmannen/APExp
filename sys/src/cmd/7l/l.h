#include	<u.h>
#include	<libc.h>
#include	<bio.h>
#include	"../7c/7.out.h"
#include	"../cc/compat.h"

#define	LIBNAMELEN	300

void	addlibpath(char*);
int	fileexists(char*);
int	find1(long, int);
char*	findlib(char*);

typedef	struct	Adr	Adr;
typedef	struct	Autom	Auto;
typedef	struct	Count	Count;
typedef	struct	Ieee	Ieee;
typedef	struct	Prog	Prog;
typedef	struct	Sym	Sym;
typedef	struct	Mask	Mask;
typedef	struct	Optab	Optab;
typedef	struct	Oprang	Oprang;
typedef	uchar	Opcross[32][2][32];

#define	P		((Prog*)0)
#define	S		((Sym*)0)
#define	TNAME		(curtext&&curtext->from.sym?curtext->from.sym->name:noname)

struct	Adr
{
	union
	{
		vlong	u0offset;
		char*	u0sval;
		Ieee*	u0ieee;
	} u0;
	union
	{
		Auto*	u1autom;
		Sym*	u1sym;
	} u1;
	char	type;
	char	reg;
	char	name;
	char	class;
};

#define	offset	u0.u0offset
#define	sval	u0.u0sval
#define	ieee	u0.u0ieee

#define	autom	u1.u1autom
#define	sym	u1.u1sym

struct	Prog
{
	Adr	from;
	Adr	from3;	/* third register operand */
	Adr	to;
	union
	{
		long	u0regused;
		Prog*	u0forwd;
	} u0;
	Prog*	cond;
	Prog*	link;
	vlong	pc;
	long	line;
	uchar	mark;
	ushort	optab;
	ushort	as;
	uchar	reg;
};
#define	regused	u0.u0regused
#define	forwd	u0.u0forwd

struct	Sym
{
	char	*name;
	short	type;
	short	version;
	short	become;
	short	frame;
	char	dupok;
	uchar	subtype;
	ushort	file;
	vlong	value;
	long	sig;
	Sym*	link;
};

#define SIGNINTERN	(1729*325*1729)	/* signature of internal functions such as _div */

struct	Autom
{
	Sym*	asym;
	Auto*	link;
	long	aoffset;
	short	type;
};

struct	Optab
{
	ushort	as;
	char	a1;
	char	a2;
	char	a3;
	char	type;
	char	size;
	char	param;
	char	flag;
};
struct	Oprang
{
	Optab*	start;
	Optab*	stop;
};
struct	Mask
{
	uchar	s;
	uchar	e;
	uchar	r;
	uvlong	v;
};

enum
{
	STEXT		= 1,
	SDATA,
	SBSS,
	SDATA1,
	SXREF,
	SLEAF,
	SFILE,
	SCONST,
	SSTRING,
	SUNDEF,

	SIMPORT,
	SEXPORT,

	LFROM		= 1<<0,
	LTO		= 1<<1,
	LPOOL		= 1<<2,

	C_NONE		= 0,
	C_REG,
	C_RSP,		/* D_REG or D_SP */
	C_SHIFT,		/* D_SHIFT: shift type, amount, value */
	C_EXTREG,	/* D_EXTREG: reg, ext type, shift */
	C_FREG,
	C_SPR,
	C_COND,

	C_ZCON,		/* 0 (matching C_REG, not C_RSP, allowing REGZERO) */
	C_ADDCON0,	/* 12-bit unsigned, unshifted */
	C_ADDCON,	/* 12-bit unsigned, shifted left by 0 or 12 */
	C_MOVCON,	/* generated by a 16-bit constant, optionally inverted and/or shifted by multiple of 16 */
	C_BITCON,	/* bimm32/bimm64 */
	C_BITCON32,	/* bimm32 */
	C_BITCON64,	/* bimm64 */
	C_ABCON,	/* could be C_ADDCON or C_BITCON */
	C_MBCON,	/* could be C_MOVCON or C_BITCON */
	C_LCON,		/* 32-bit constant */
	C_FCON,		/* floating-point constant */
	C_VCON,		/* 64-bit constant */

	C_AACON,	/* ADDCON offset in auto constant $a(FP) */
	C_LACON,	/* 32-bit offset in auto constant $a(FP) */

	C_AECON,	/* ADDCON offset in extern constant $e(SB) */

	C_SBRA,
	C_LBRA,

	C_NPAUTO,	/* -512 <= x < 0, 0 mod 8 */
	C_NSAUTO,	/* -256 <= x < 0 */
	C_PSAUTO,	/* 0 to 255 */
	C_PPAUTO,	/* 0 to 504, 0 mod 8 */
	C_UAUTO4K,	/* 0 to 4095 */
	C_UAUTO8K,	/* 0 to 8190, 0 mod 2 */
	C_UAUTO16K,	/* 0 to 16380, 0 mod 4 */
	C_UAUTO32K,	/* 0 to 32760, 0 mod 8 */
	C_UAUTO64K,	/* 0 to 65520, 0 mod 16 */
	C_LAUTO,		/* any other 32-bit constant */

	C_SEXT1,		/* 0 to 4095, direct */
	C_SEXT2,		/* 0 to 8190 */
	C_SEXT4,		/* 0 to 16380 */
	C_SEXT8,		/* 0 to 32760 */
	C_SEXT16,	/* 0 to 65520 */
	C_LEXT,

	C_NPOREG,	/* mirror NPAUTO etc, except for ZOREG */
	C_NSOREG,
	C_ZOREG,
	C_PSOREG,
	C_PPOREG,
	C_UOREG4K,
	C_UOREG8K,
	C_UOREG16K,
	C_UOREG32K,
	C_UOREG64K,
	C_LOREG,

	C_ADDR,		/* relocatable address for dynamic loading */
	C_ROFF,		/* register offset (inc register extended) */
	C_XPOST,
	C_XPRE,

	C_VREG,

	C_GOK,
	C_NCLASS,	/* must be last */

/* mark flags */
	FOLL		= 1<<0,
	LABEL	= 1<<1,
	LEAF		= 1<<2,
	FLOAT		= 1<<3,
	BRANCH		= 1<<4,
	LOAD		= 1<<5,
	SYNC		= 1<<6,
	NOSCHED		= 1<<7,

	MINSIZ		= 64,

	Roffset	= 22,		/* no. bits for offset in relocation address */
	Rindex	= 10,		/* no. bits for index in relocation address */

	STACKALIGN = 16,	/* alignment of stack */
	PCSZ=	8,	/* size of PC */
};

enum
{

	STRINGSZ	= 200,
	NHASH		= 10007,
	NHUNK		= 100000,
	MAXIO		= IOUNIT,
	MAXHIST		= 20,	/* limit of path elements for history symbols */
};

EXTERN struct
{
	uchar	obuf[MAXIO];			/* output buffer */
	uchar	ibuf[MAXIO];			/* input buffer */
} buf;

#define	cbuf	obuf
#define	xbuf	ibuf

EXTERN	long	HEADR;			/* length of header */
EXTERN	int	HEADTYPE;		/* type of header */
EXTERN	vlong	INITDAT;		/* data location */
EXTERN	long	INITRND;		/* data round above text location */
EXTERN	vlong	INITTEXT;		/* text location */
EXTERN	vlong	INITTEXTP;		/* text location (physical) */
EXTERN	char*	INITENTRY;		/* entry point */
EXTERN	long	autosize;
EXTERN	Biobuf	bso;
EXTERN	long	bsssize;
EXTERN	int	cbc;
EXTERN	uchar*	cbp;
EXTERN	int	cout;
EXTERN	Auto*	curauto;
EXTERN	Auto*	curhist;
EXTERN	Prog*	curp;
EXTERN	Prog*	curtext;
EXTERN	Prog*	datap;
EXTERN	long	datsize;
EXTERN	char	debug[128];
EXTERN	Prog*	etextp;
EXTERN	Prog*	firstp;

EXTERN	uchar	fnuxi4[4];
EXTERN	uchar	fnuxi8[8];
EXTERN	uchar	inuxi[9][8];

EXTERN	Sym*	hash[NHASH];
EXTERN	Sym*	histfrog[MAXHIST];
EXTERN	int	histfrogp;
EXTERN	int	histgen;

EXTERN	char*	library[50];
EXTERN	char*	libraryobj[50];
EXTERN	int	libraryp;
EXTERN	Prog*	lastp;
EXTERN	long	lcsize;
EXTERN	char	literal[32];
EXTERN	int	nerrors;
EXTERN	char*	noname;
EXTERN	vlong	instoffset;
EXTERN	Opcross	opcross[8];
EXTERN	char*	outfile;
EXTERN	vlong	pc;
EXTERN	uchar	repop[ALAST];
EXTERN	long	symsize;
EXTERN	Prog*	textp;
EXTERN	vlong	textsize;
EXTERN	int	version;
EXTERN	char	xcmp[C_NCLASS][C_NCLASS];
EXTERN	int	xrefresolv;
EXTERN	Prog	zprg;
EXTERN	int	dtype;

EXTERN	int	doexp, dlm;
EXTERN	int	imports, nimports;
EXTERN	int	exports, nexports;
EXTERN	char*	EXPTAB;
EXTERN	Prog	undefp;

#define	UP	(&undefp)

extern	char*	anames[];
extern	char*	cnames[];
extern	Optab	optab[];

EXTERN	Prog*	blitrl;
EXTERN	Prog*	elitrl;

#pragma	varargck	argpos	diag 1

#pragma	varargck	type	"A"	int
#pragma	varargck	type	"A"	uint
#pragma	varargck	type	"C"	int
#pragma	varargck	type	"D"	Adr*
#pragma	varargck	type	"N"	Adr*
#pragma	varargck	type	"P"	Prog*
#pragma	varargck	type	"S"	char*


int	Aconv(Fmt*);
int	Cconv(Fmt*);
int	Dconv(Fmt*);
int	Nconv(Fmt*);
int	Pconv(Fmt*);
int	Rconv(Fmt*);
int	Sconv(Fmt*);
int	aclass(Adr*);
void	addpool(Prog*, Adr*);
vlong	atolwhex(char*);
void	asmb(void);
void	asmdyn(void);
void	asmlc(void);
void	asmout(Prog*, Optab*);
void	asmsym(void);
Prog*	brchain(Prog*);
Prog*	brloop(Prog*);
void	buildop(void);
void	buildrep(int, int);
void	cflush(void);
void	ckoff(Sym*, long);
int	chipfloat(Ieee*);
int	cmp(int, int);
int	compound(Prog*);
void	cput(int);
void	datfill(uchar*, long, uchar*, long);
void	diag(char*, ...);
void	dodata(void);
void	doprof1(void);
void	doprof2(void);
void	dynreloc(Sym*, long, int);
vlong	entryvalue(void);
void	errorexit(void);
void	export(void);
void	follow(void);
void	histtoauto(void);
int	isnop(Prog*);
double	ieeedtod(Ieee*);
long	ieeedtof(Ieee*);
void	import(void);
void	ldobj(int, long, char*);
void	listinit(void);
void	llput(vlong);
void	llputl(vlong);
void	loadlib(void);
Sym*	lookup(char*, int);
void	lput(long);
void	lputl(long);
void	mkfwd(void);
int	movcon(vlong);
void	names(void);
void	nocache(Prog*);
void	nuxiinit(void);
void	objfile(char*);
vlong	offsetshift(vlong, int);
Optab*	oplook(Prog*);
void	patch(void);
int	pseudo(Prog*);
void	prasm(Prog*);
Prog*	prg(void);
void	putsymb(char*, int, vlong, int);
void	readundefs(char*, int);
long	regoff(Adr*);
int	relinv(int);
vlong	rnd(vlong, long);
void	span(void);
void	undef(void);
void	wput(long);
void	wputl(long);
void	noops(void);
Mask*	findmask(uvlong);
void	xdefine(char*, int, long);
void	xfol(Prog*);
void	zerosig(char*);


#pragma	varargck	type	"R"	int

/* for ../ld */
#define	isbranch(a)	((a) == AB)
#define	iscall(a)	((a) == ABL)
#define	isreturn(a)	((a) == ARETURN || (a) == ARET || (a) == AERET)
#define	branchop()	AB
#define	canfollow(a)	((a) != ATEXT && (a) != ABCASE)