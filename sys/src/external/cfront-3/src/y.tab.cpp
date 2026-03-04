/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20210808

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 30 "gram.y"
#include "cfront.h"
#include "size.h"
#include "template.h"
#include <string.h>
#ifdef SVR42
#include <unistd.h>
#endif
/* include tqueue.h after YYSTYPE is defined ...*/

int		in_friend = 0;
int		must_be_friend = 0;
int		dont_instantiate = 0;
static int explicit_template_definition = 0;
Pname righttname=0;


static struct parstate {
	Ptype intypedef;
	int   infriend;
	int   defercheck;
	Pname intag;
	int cid;
} pstate[BLMAX];
static int px;
extern int classid;
static void
SAVE_STATE()
{
/*error('d',"save_state: in_typedef%t in_tag%n defer_check %d",in_typedef,in_tag,defer_check);*/
	if ( px >= BLMAX ) error('i',"parsing state stack overflow -- current table %s",Ctbl->whereami());
	pstate[px].intypedef = in_typedef;
	pstate[px].infriend = in_friend;
	in_typedef = 0;
	in_friend = 0;
	pstate[px].defercheck = defer_check;
	defer_check = 0;
	pstate[px].intag = in_tag;
	in_tag = 0;
	pstate[px].cid = classid;
	classid = 0;
	++px;
}
static void
RESTORE_STATE()
{
/*error('d',"restore_state: in_typedef%t in_tag%n defer_check %d",in_typedef,in_tag,defer_check);*/
	if ( --px < 0 ) error('i',"parsing state stack underflow -- current table %s",Ctbl->whereami());
	in_typedef = pstate[px].intypedef;
	in_friend = pstate[px].infriend;
	defer_check = pstate[px].defercheck;
	in_tag = pstate[px].intag;
	classid = pstate[px].cid;
/*error('d',"            -> in_typedef%t in_tag%n defer_check %d",in_typedef,in_tag,defer_check);*/
}


/*SYM parsing symbol table management*/
inline void
PUSH_ARG_SCOPE()
{
DB(if(Kdebug>=1)error('d',"push arg table; %ctbl %s",'C',Ctbl->whereami()););
	Ctbl = new ktable( 0, Ctbl, 0 );
	Ctbl->k_id = ARG;
}
inline void
PUSH_CLASS_SCOPE( Pname n )
{
DB(if(Kdebug>=1)error('d',"pushC table%n; %ctbl %s",n,'C',Ctbl->whereami()););
	/* table allocated in name::tname() to avoid problems with forward*/
	/*     refs to class templates*/
	Pclass cl = n->tp->classtype();
	cl->k_tbl->k_next = Ctbl;
	Ctbl = cl->k_tbl;
	Ctbl->expand(CTBLSIZE);
}
inline void
PUSH_BLOCK_SCOPE()
{
DB(if(Kdebug>=1)error('d',"push block tbl; %ctbl %s in %s",'C',Ctbl->whereami(),Ctbl->k_next->whereami()););
	if ( Ctbl->k_id == ARG )
		Ctbl->expand(TBLSIZE);
	else {
		Ctbl = new ktable(TBLSIZE, Ctbl, Ctbl->k_name );
	}
	Ctbl->k_id = BLOCK;
	if ( Ctbl->k_next == Gtbl
	||   Ctbl->k_next->k_id == BLOCK
	||   Ctbl->k_next->k_id == CLASS )
		Ctbl->k_t->next = Ctbl->k_next->k_t;
}
inline void
PUSH_TEMPLATE_SCOPE()
{
DB(if(Kdebug>=1)error('d',"push template tbl; %ctbl %s",'C',Ctbl->whereami()););
	Ctbl = new ktable( 0, Ctbl, 0 );
	Ctbl->k_id = TEMPLATE;
}
inline void
POP_SCOPE( int deallocate = 0 )
{
DB(if(Kdebug>=1)error('d',"pop tbl %s",Ctbl->whereami()););
	if ( Ctbl == Gtbl ) error('i', "bad parsing table");
	Pktab b = Ctbl;
	Ctbl = Ctbl->k_next;
	if ( b->k_id == ARG || deallocate ) delete b;
}


/*SYM -- replaces set_scope()/curr_scope for switching between scopes
 *       in member defs
 * Temporarily reset scope in member defs:
 *     int X::f( T t = a ) { ... }
 *     int X::s[10] =        ... ,  i = 3;
 *            |----scope of X----|
 * ??? What about exprs "p->operator T()", etc ???
 */
/* Although local member defs are illegal outside a local class, scopes*/
/*    are stacked for error recovery / extensibility.*/
struct pcontext {
	Pktab ktbl;
	int   saved_template;
};
static pcontext scopestack[BLMAX];
static int scopex = 0;
Pname
SET_SCOPE( Pname n )
{
	Pktab ntb;
	if ( n == 0 ) ntb = 0;
	else if ( n == sta_name ) ntb = Gtbl;
	else if ( n->n_template_arg == template_type_formal ) {
		DB(if(Kdebug>=1)error('d',"set scope%n -- template formal -- currently in %s next %s",n,Ctbl->whereami(),Ctbl->k_next->whereami()););
		return n;
	}
	else if ( n->tp ) {
		Ptype t = n->tp->skiptypedefs();
		if ( t->base==COBJ ) ntb = t->classtype()->k_tbl;
		else ntb = 0;
	} else ntb = 0;
	DB(if(Kdebug>=1)error('d',"set scope%n ntb %s next %s, currently in %s",n,ntb->whereami(),ntb?ntb->k_next->whereami():"<nil>",Ctbl->whereami()););
	if (ntb == 0) return 0;/*error('i',"scope set to null table(n==%n)!",n);*/
	if ( scopex >= BLMAX ) error('i',"set scope %s: parsing scope stack overflow -- current table %s",ntb->whereami(),Ctbl->whereami());
	Pktab tt = Ctbl;
	if ( Ctbl->k_id == TEMPLATE ) {
		/* parsing template member function*/
		/*    template<...> PT<...>::f() {}*/
		/* be sure template params are in scope when parsing f*/
		/* -- extract template scope from current scope and put it*/
		/*    in new scope*/
		Ctbl = Ctbl->k_next;
		tt->k_next = ntb->k_next;
		ntb->k_next = tt;
		scopestack[scopex].saved_template = 1;
	}
	else if ( Ctbl->k_id == ARG && Ctbl->k_next->k_id == TEMPLATE ) {
		/* parsing static data member template with declarator ()'s.*/
		/*    template<...> T (PT<...>::d) = v;*/
		/* interpose PT's table between ARG table and its parent*/
		Ctbl = Ctbl->k_next->k_next;
		tt->k_next->k_next = ntb->k_next;
		ntb->k_next = tt->k_next;
		tt->k_next = ntb;
		scopestack[scopex].saved_template = 1;
		ntb = tt;
	}
	scopestack[scopex++].ktbl = Ctbl;
	Ctbl = ntb;
	return n;
}
void
UNSET_SCOPE()
{
	/* restore surrounding template scope, if appropriate*/
	Pktab tt = 0;
	if ( --scopex < 0 ) error('i',"parsing scope stack underflow -- current scope %s",Ctbl->whereami());
	if ( scopestack[scopex].saved_template ) {
		scopestack[scopex].saved_template = 0;
		if ( Ctbl->k_next==0 || Ctbl->k_next->k_id != TEMPLATE )
			error('i',"set scope failed restoring template table -- current table %s",Ctbl->whereami());
		tt = Ctbl->k_next;
		Ctbl->k_next = tt->k_next;
	}
	DB(if(Kdebug>=1)error('d',"unset scope %s -> %s tt %s",Ctbl->whereami(),scopestack[scopex].ktbl->whereami(),tt?tt->whereami():"<nil>"););
	Ctbl = scopestack[scopex].ktbl;
	if ( tt ) { tt->k_next = Ctbl; Ctbl = tt; }
}
inline Pktab
GET_XSCOPE()
{
	if ( scopex-1 < 0 ) error('i',"parsing scope stack underflow -- current table %s",Ctbl->whereami());
	return scopestack[scopex-1].ktbl;
}
inline void
SET_XSCOPE( Pktab tb )
{
	if ( scopex-1 < 0 ) error('i',"parsing scope stack underflow -- current table %s",Ctbl->whereami());
	scopestack[scopex-1].ktbl = tb;
}


/* macros*/
#define copy_if_need_be(s)  ((templp->in_progress || templp->parameters_in_progress) ? strdup(s) : s)
#define YYMAXDEPTH 600

#if 0
#define YYCLEAN {free(yys); free(yyv);}
#else
#define YYCLEAN
#endif

#ifdef DBG
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#endif

static int init_seen = 0;
static int cdi = 0;
static Pnlist cd = 0, cd_vec[BLMAX];
static char stmt_seen = 0, stmt_vec[BLMAX];
static Pnlist scd[BLMAX]; /* keep track of cd list outside of switch*/
static int scdp = -1;

static Pname memptr_pn;
static TOK memptr_tok;

static Pname err_name = 0;

/* support for template friend declarations within a class*/
static Pcons templ_friends;

/* fcts put into norm2.c just to get them out of gram.y*/
void sig_name(Pname);
Ptype tok_to_type(TOK);
void memptrdcl(Pname, Pname, Ptype, Pname);

static bit decl_with_init(Pnlist cd)
/* do the declarations have an initializer
   or a class object with a constructor */
{
	for (Pname n=cd->head;n;n=n->n_list) {
		if (n->n_initializer) return 1;
		Pname cln=n->tp->is_cl_obj();
		if (cln && Pclass(cln->tp)->c_ctor)
			return 1;
	}
	return 0;
}


static char*
get_classname(const char* s)
{
/* error('d',"get_classname(%s)",s);*/
	char* r = new char[strlen(s)+1];
	sprintf(r,"%s", s);
	char *s2 = r;

	const char* s1 = s;
	while (*s) {
		for ( ; s[0] && (s[0] != '_' || (s[1] && s[1] != '_')); s++) s1++;;
		if (*s) {
			if (strncmp(s,"___pt__",7)==0) {
				*s2 = 0;
				return r;
			}
			if (strncmp(s,"__pt__",6)==0) { /* parameterized class*/
				*s2 = '\0';
				return r;
			}
		}
		return r;
	}
	return r;
}

static Pptr doptr(TOK p, TOK t)
{
	Pptr r = new ptr(p,0);
	switch (t) {
	case CONST:
		r->b_const = 1;
               /* if (p == RPTR) error('w',"redundant `const' after &");*/
		break;
	case VOLATILE:
		error('w',"\"volatile\" not implemented (ignored)");
		break;
	default:
		error("syntax error: *%k",t);
	}
	return r;
}

static Pbcl dobase(TOK pr, Pname n, TOK v = 0)
{
/* error('d',"dobase(%k %n %k)", pr,n,v);*/

	Pbcl b = new basecl(0,0);
	b->ppp = pr;	/* save protection indicator*/

	if (n) {
		if (n->base != TNAME) {
			Pname nn = k_find_name(n->string,Ctbl,HIDDEN);
			if ( nn == 0 ) {
				error("BN%n not aTN",n);
				return 0;
			} else
				n = nn;
		}

		Pbase bt = Pbase(n->tp);
		while (bt->base == TYPE) bt = Pbase(bt->b_name->tp);

                if (bt->base != COBJ) {
                        /* template <class B> class D : public B {};*/
                        if (templp->in_progress == true  && bt->base == ANY)
                            error('s',"formalTZ%n used asBC ofY",n);
                        else error("BN%n not aCN",n);
                        return 0;
                }

		if (v) {
			if (v != VIRTUAL) error("syntax error:%k inBCD",v);
			b->base = VIRTUAL;
		}
		else
			b->base = NAME;

		b->bclass = Pclass(bt->b_name->tp);
	}

	return b;
}


#define Ndata(a,b)	b->normalize(Pbase(a),0,0)
#define Ncast(a,b)	b->normalize(Pbase(a),0,1)
#define Nfct(a,b,c)	b->normalize(Pbase(a),Pblock(c),0)
/*#define Ncopy(n)	(n->base==TNAME)?new name(n->string):n*/
inline Pname Ncopy(Pname n)
{
	Pname nn;
	if (n->base!=TNAME) {
		nn = n;
	} else {
		nn = new name(n->string);
		nn->n_template_arg = n->n_template_arg;
	}
	return nn;
}

#define Finit(p)	Pfct(p)->f_init
#define Fargdcl(p,q,r)	Pfct(p)->argdcl(q,r)
#define Freturns(p)	Pfct(p)->returns
#define Fbody(p)	Pfct(p)->body /*SYM*/
#define Vtype(v)	Pvec(v)->typ
#define Ptyp(p)		Pptr(p)->typ

		/* avoid redefinitions */
#undef EOFTOK
#undef ASM
#undef BREAK
#undef CASE
#undef CONTINUE
#undef DEFAULT
#undef DELETE
#undef VEC_DELETE
#undef DO
#undef ELSE
#undef ENUM
#undef FOR
#undef FORTRAN
#undef FRIEND
#undef GOTO
#undef IF
#undef NEW
#undef VEC_NEW
#undef OPERATOR
#undef RETURN
#undef SIZEOF
#undef SWITCH
#undef THIS
#undef WHILE
#undef LP
#undef RP
#undef LB
#undef RB
#undef REF
#undef DOT
#undef NOT
#undef COMPL
#undef MUL
#undef AND
#undef PLUS
#undef MINUS
#undef ER
#undef OR
#undef ANDAND
#undef OROR
#undef QUEST
#undef COLON
#undef ASSIGN
#undef CM
#undef SM
#undef LC
#undef RC
#undef ID
#undef STRING
#undef ICON
#undef FCON
#undef CCON
#undef ZERO
#undef ASOP
#undef RELOP
#undef EQUOP
#undef DIVOP
#undef SHIFTOP
#undef ICOP
#undef TYPE

#undef CATCH
#undef THROW
#undef TRY

#undef TNAME
#undef EMPTY
#undef NO_ID
#undef NO_EXPR
#undef FDEF
#undef ELLIPSIS
#undef AGGR
#undef MEM
#undef MEMPTR
#undef PR
#undef MEMQ
#undef TSCOPE
#undef DECL_MARKER
#undef REFMUL
#undef LDOUBLE
#undef LINKAGE
#undef TEMPLATE

#undef XVIRT
#undef XNLIST
#undef XILINE
#undef XIA
#undef SM_PARAM
#undef PTNAME
#undef NEW_INIT_KLUDGE

/*Forward declarations*/
static void arg_redec( Pname fn );
static void hoist_al();
static Pname enumcheck( Pname n );
static void check_tag();
static bit check_if_base( Pclass c1, Pclass c2 );
static Pname dummy_dtor( TOK q, TOK d );
static Pname dummy_dtor();

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 491 "gram.y"
typedef union YYSTYPE {
	const char*	s;
	TOK	t;
	int	i;
	loc	l;
	Pname	pn;
	Ptype	pt;
	Pexpr	pe;
	Pstmt	ps;
	Pbase	pb;
	Pnlist	nl;
	Pslist	sl;
	Pelist	el;
	Pbcl	pbc;
	Pptr	pp;
	PP	p;	/* fudge: pointer to all class node objects*/
	Plist	pl;
	toknode* q;	/* token queue*/
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 511 "gram.y"
#include "tqueue.h"
extern YYSTYPE yylval, yyval;
extern int yyparse();

/* in_typedef should allow for nested in_typedef*/
extern int	declTag;	 /* !1: inline, virtual mod permitted*/
int		in_sizeof = 0;
int		in_new = 0;
Ptype 		in_typedef = 0;  /* catch redefinition of TNAME*/
Pname		in_tag = 0;      /* handle complex typedefs: int (*)()*/
extern int	defer_check;	 /* redefinition typedef check delay*/

extern 	int must_be_id;	 /* !0, TNAME => ID, i.e., int X*/
int	DECL_TYPE = 0; 	 /* lalex() wants this set for global x(*fp)()*/
int	in_arg_list=0; 	 /* !0 when parsing argument list, 1: in (), 2: in <>*/
static  int in_binit_list=0;
int	in_class_decl=0; /* !0 when processing class definition*/
int	parsing_class_members=0; /* !0 when parsing class def but not member function body*/
int	in_mem_fct=0;    /* !0 when parsing member function definition*/
Ptempl_inst pti = 0; /* explicit template class: class X<int> {};*/

#define yylex lalex
#define NEXTTOK() ( (yychar==-1) ? (yychar=yylex(),yychar) : yychar )
#define EXPECT_ID() must_be_id = 1
#define NOT_EXPECT_ID() must_be_id = 0

Pname syn()
{
ll:
	switch (yyparse()) {
	case 0:		return 0;	/* EOF*/
	case 1:		goto ll;	/* no action needed*/
	default:	return yyval.pn;
	}
}

#line 545 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define EOFTOK 0
#define ASM 1
#define AUTO 2
#define BREAK 3
#define CASE 4
#define CONTINUE 7
#define DEFAULT 8
#define DELETE 9
#define DO 10
#define ELSE 12
#define ENUM 13
#define FOR 16
#define FORTRAN 17
#define FRIEND 18
#define GOTO 19
#define IF 20
#define NEW 23
#define OPERATOR 24
#define RETURN 28
#define SIZEOF 30
#define SWITCH 33
#define THIS 34
#define WHILE 39
#define LP 40
#define RP 41
#define LB 42
#define RB 43
#define REF 44
#define DOT 45
#define NOT 46
#define COMPL 47
#define MUL 50
#define AND 52
#define PLUS 54
#define MINUS 55
#define LT 58
#define GT 60
#define ER 64
#define OR 65
#define ANDAND 66
#define OROR 67
#define QUEST 68
#define COLON 69
#define ASSIGN 70
#define CM 71
#define SM 72
#define LC 73
#define RC 74
#define ID 80
#define STRING 81
#define ICON 82
#define FCON 83
#define CCON 84
#define NAME 85
#define ZERO 86
#define ASOP 90
#define RELOP 91
#define EQUOP 92
#define DIVOP 93
#define SHIFTOP 94
#define ICOP 95
#define TYPE 97
#define CATCH 98
#define THROW 99
#define TRY 100
#define TNAME 123
#define EMPTY 124
#define NO_ID 125
#define NO_EXPR 126
#define FDEF 127
#define ELLIPSIS 155
#define AGGR 156
#define MEM 160
#define MEMPTR 173
#define PR 175
#define MEMQ 176
#define TSCOPE 178
#define DECL_MARKER 179
#define REFMUL 180
#define LDOUBLE 181
#define LINKAGE 182
#define TEMPLATE 185
#define XVIRT 200
#define XNLIST 201
#define XILINE 202
#define XIA 203
#define SM_PARAM 207
#define PTNAME 209
#define NEW_INIT_KLUDGE 210
#define XDELETED_NODE 211
#define VEC_DELETE 212
#define VEC_NEW 213
#define DUMMY_LAST_NODE 214
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,   83,   85,   86,   82,
   66,   66,   66,   66,   66,   72,   72,    1,    1,    1,
    1,    1,    2,    2,   88,    4,    4,    4,   89,    3,
    3,    3,   90,   71,   87,   91,    6,    6,    7,    7,
    8,    8,    5,    5,   24,   92,   24,   24,   93,   24,
   25,   25,    9,    9,   94,   95,   64,   64,   64,   13,
   13,   13,   13,   13,   13,   13,   12,   12,   12,   12,
   12,   12,   57,   81,   81,   56,   56,   56,   56,   56,
   55,   80,   80,   19,   19,   19,   96,   14,   97,   14,
   14,   15,   15,   84,   84,   84,   98,   98,   48,   48,
   48,   48,   48,   16,   99,   16,   16,  101,   21,   21,
   21,   21,  100,  100,   74,   74,   75,   75,   76,   76,
   76,   76,   76,   20,   20,   20,   17,   17,   18,   18,
   22,   22,   22,   23,   23,   23,   23,   23,   23,   23,
   23,   26,   26,   26,   26,   69,   69,   69,   69,   69,
   69,   69,   69,   69,   69,   69,   69,   69,   69,   69,
   69,   69,   69,   69,   69,   69,   69,   69,   69,   69,
   69,   69,   69,   62,   60,   60,   63,   63,   77,   77,
   77,   79,   79,   27,   27,   27,   27,   27,   27,   27,
   27,   27,   27,   27,   27,   27,   27,   27,   27,   27,
   27,   47,   47,   47,   47,   47,   47,   47,   53,   53,
   53,   42,   42,   42,   42,   42,   44,   44,   29,   29,
   29,   30,   31,   58,  102,   32,   32,   32,   34,   34,
   34,   34,  103,   34,   34,  105,  104,   33,   33,   33,
   33,   33,   33,   33,   33,   33,   33,  106,   33,  107,
   33,  108,   33,  109,   33,  110,   33,  111,   33,   33,
   67,   67,   68,   73,   73,   36,   35,   35,   28,   28,
   38,   38,   38,   38,   38,   38,   38,   38,   38,   38,
   38,   38,   38,   38,   38,   38,   38,   38,   38,   38,
   38,   38,   38,   38,   38,   37,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   37,   39,   39,   39,   39,   39,   39,   39,   39,   39,
   39,   39,   39,   39,   39,   39,   39,   39,   39,   39,
   39,   39,   39,   39,   39,   39,   39,   39,   39,   39,
   39,   39,   39,   39,   39,   39,   39,   39,   39,   39,
   39,   61,   61,   61,   61,   61,   61,   61,   61,   41,
   41,   41,   41,   41,   41,   41,   65,   59,   59,   59,
   40,   40,   40,   43,  112,   46,   46,   46,   46,   45,
   54,   50,  113,   50,   78,   51,   52,   52,   49,   49,
   70,   70,   70,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   10,   10,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    2,    1,    1,    0,    0,    0,    8,
    1,    1,    1,    1,    2,    1,    1,    1,    1,    1,
    1,    5,    4,    2,    0,    7,    5,    5,    0,    6,
    4,    4,    0,    4,    0,    0,    3,    0,    1,    3,
    3,    4,    2,    0,    1,    0,    4,    2,    0,    4,
    1,    3,    3,    2,    1,    1,    1,    4,    4,    1,
    1,    1,    2,    1,    1,    1,    1,    2,    2,    2,
    2,    2,    1,    3,    1,    0,    3,    2,    2,    2,
    2,    1,    1,    1,    1,    2,    0,    5,    0,    6,
    2,    1,    3,    3,    1,    0,    2,    2,    1,    2,
    2,    2,    3,    1,    0,    4,    0,    0,    5,    2,
    5,    2,    0,    2,    2,    0,    1,    3,    1,    2,
    2,    3,    3,    2,    4,    7,    1,    1,    1,    1,
    2,    0,    2,    1,    2,    2,    1,    1,    1,    2,
    3,    1,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    2,
    2,    1,    1,    1,    1,    1,    1,    3,    1,    3,
    1,    1,    1,    1,    1,    2,    2,    1,    0,    2,
    5,    1,    3,    2,    4,    2,    4,    6,    6,    4,
    4,    6,    1,    3,    2,    4,    2,    2,    2,    2,
    3,    1,    2,    0,    2,    2,    2,    3,    0,    2,
    2,    0,    2,    2,    4,    4,    0,    2,    0,    2,
    2,    2,    0,    3,    0,    4,    2,    3,    1,    1,
    1,    2,    0,    5,    4,    0,    2,    2,    1,    3,
    3,    1,    1,    1,    3,    5,    3,    0,    9,    0,
    4,    0,    4,    0,    4,    0,    5,    0,    4,    3,
    0,    2,    3,    4,    3,    1,    1,    3,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    5,    3,    2,
    5,    3,    6,    1,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    5,    3,    2,    5,    3,    6,    1,    2,
    0,    2,    2,    3,    3,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    4,    3,    4,    4,
    3,    4,    4,    3,    4,    4,    3,    4,    4,    1,
    2,    3,    3,    1,    3,    1,    1,    1,    1,    1,
    1,    2,    3,    4,    2,    4,    3,    3,    3,    4,
    4,    5,    5,    6,    6,    4,    4,    1,    1,    2,
    1,    2,    2,    4,    1,    1,    1,    2,    2,    2,
    2,    2,    0,    5,    1,    5,    3,    1,    1,    0,
    0,    1,    2,    1,    1,    2,    2,    2,    2,    1,
    3,    2,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    3,    0,    0,    0,  395,    0,    0,    0,    2,    5,
    0,    0,   60,  178,    0,  379,    0,  378,   66,    0,
    7,    0,    0,    1,   21,   20,   19,   18,    0,    0,
   67,   65,  132,   64,  193,    0,  175,    0,    0,    0,
    0,    0,    0,    6,    0,   87,  127,   85,   84,    0,
    0,  128,    0,    0,    0,    0,    0,  171,  162,  163,
  148,  149,  146,  147,  156,  157,  151,  150,  158,  159,
  166,  172,  165,  155,  153,  154,  152,  164,  386,  173,
  145,    0,    0,  387,  144,  143,  406,  408,    0,   55,
    0,  124,  112,    0,    0,  412,    4,    0,    0,  407,
    0,    0,    0,    0,   54,    0,   68,   72,   71,   70,
   51,    0,    0,    0,    0,    0,    0,  414,    0,   24,
    0,  200,  184,    0,  177,   63,  176,    0,  195,    0,
    0,  199,  186,    0,    0,  380,    0,    0,    0,    0,
   89,   86,    0,    0,  160,  161,  388,    0,  390,  389,
  142,  194,    0,    0,    0,    0,  361,  385,    0,    0,
    0,    0,    0,    0,  381,  359,  357,  358,  360,  356,
    0,    0,    0,    0,   61,    0,    0,    0,  350,  354,
    0,   82,    0,    0,    0,   75,    0,    0,    0,    0,
    0,    8,    0,    0,    0,    0,    0,   46,    0,   53,
   49,    0,  108,    0,  139,    0,    0,  134,  131,    0,
  133,  179,    0,    0,    0,    0,   43,    0,    0,   62,
    0,    0,  267,    0,    0,  398,  399,    0,    0,    0,
  179,    0,    0,    0,    0,  411,  201,    0,    0,    0,
   92,    0,  170,  168,  218,    0,    0,    0,    0,    0,
  322,  323,    0,  383,  382,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   69,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  326,    0,    0,  351,    0,
   56,   73,    0,   59,    0,    0,  129,    0,    0,  119,
  130,    0,  117,  125,    0,    0,  377,    0,   52,    0,
    0,    0,  113,  140,  136,  135,    0,    0,  413,    0,
   23,   31,   32,    0,  202,    0,    0,    0,    0,  187,
    0,  402,    0,  196,   58,    0,    0,    0,    0,  190,
   22,    0,    0,   88,    0,    0,    0,    0,    0,    0,
    0,    0,  324,  325,    0,    0,   80,   79,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  314,    0,    0,
    0,    0,    0,  338,    0,  341,    0,    0,  344,  347,
    0,  353,  352,    0,   74,    0,    0,    0,  355,    0,
  121,    0,  120,    0,    0,    0,    0,    0,   95,    0,
   50,   27,   28,    0,    0,  141,  180,    0,  270,   36,
    0,    0,  203,  393,  206,  207,    0,  268,  403,  397,
  179,    0,    0,    0,    0,   93,   90,    0,    0,  211,
    0,  370,    0,    0,   77,    0,  376,  337,  365,  362,
    0,    0,  340,  339,    0,  343,  342,  346,  345,  349,
  348,  371,    0,    0,  384,  214,  123,  122,  118,    0,
    0,    0,   97,   99,    0,    0,    0,    9,    0,    0,
   33,  114,    0,    0,    0,   30,    0,  208,    0,  188,
  189,  192,    0,    0,  372,  373,    0,    0,    0,    0,
    0,  367,  363,  369,  368,    0,  126,    0,  101,  102,
    0,    0,   94,   26,    0,  182,    0,    0,    0,   39,
    0,    0,  227,  219,  394,    0,  374,  375,  364,  366,
  216,  215,  103,   14,   13,   12,   11,    0,   10,    0,
  181,    0,    0,    0,    0,  228,    0,   15,   34,  183,
   41,   40,    0,  226,  220,  221,    0,   42,    0,  230,
  256,  231,    0,    0,  233,    0,    0,    0,    0,  250,
    0,  239,    0,    0,    0,    0,    0,    0,  243,  242,
  244,  222,  236,    0,    0,    0,    0,  258,    0,    0,
  223,  248,  232,    0,  223,    0,    0,  223,  252,    0,
    0,  261,  254,    0,  238,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  223,    0,    0,
  223,    0,    0,  240,  223,  247,  223,  241,    0,  223,
    0,    0,  237,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  289,  235,  223,  259,    0,    0,    0,  224,  223,
  251,  253,    0,  262,  255,    0,    0,  257,    0,  234,
    0,  246,    0,    0,    0,    0,    0,    0,    0,  263,
    0,    0,    0,  265,    0,  223,  264,  249,
};
static const YYINT yydgoto[] = {                         23,
   24,   25,   26,   27,  121,  431,  529,  530,  217,  122,
   29,  176,   31,   32,  240,  241,   94,  310,   50,   33,
   34,  115,  209,  111,  112,   35,   36,  223,  557,  566,
  567,  496,  592,  593,  224,  225,  216,  594,  178,  179,
  180,  408,  181,  149,   81,   82,  337,  486,  226,  227,
  123,  228,  358,  252,  182,  270,  303,  605,   37,  196,
  396,  184,   40,  197,   53,  549,  649,  684,   85,  343,
  492,  483,  694,  190,  312,  313,  328,  134,  527,  186,
  187,   44,   98,  418,  316,  522,  221,  424,  334,  525,
  494,  318,  321,  191,  304,  140,  242,  419,  352,  425,
  323,  534,  601,  615,  616,  641,  607,  647,  650,  597,
  638,  188,  497,
};
static const YYINT yysindex[] = {                       877,
    0,  -20,  735, 1925,    0,  -88,  -52,  -10,    0,    0,
   49,   94,    0,    0,  870,    0,   35,    0,    0,  114,
    0,   94,    0,    0,    0,    0,    0,    0,  929, 4059,
    0,    0,    0,    0,    0,  757,    0,  437,   67,   94,
  319,   77, 2036,    0,  141,    0,    0,    0,    0,  209,
  586,    0,  109,  269,  288,  284,  295,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1049,  433,    0,    0,    0,    0,    0,   71,    0,
 2015,    0,    0,  224,   94,    0,    0,  315, 2015,    0,
  593,  433,  319, 2176,    0,   37,    0,    0,    0,    0,
    0,  474,  630,  319, 3731,  305, 2176,    0, 2106,    0,
  808,    0,    0, 1103,    0,    0,    0,  360,    0, 2015,
 1210,    0,    0,  808,  278,    0,  436,  319,  379,  365,
    0,    0,  393,  407,    0,    0,    0,  -23,    0,    0,
    0,    0, 4634,  572, 1925, 4934,    0,    0, 4934, 4934,
 4934, 4934, 4934, 4934,    0,    0,    0,    0,    0,    0,
 4934,  424, 4934,  299,    0, 3925, 1782, 1135,    0,    0,
 4934,    0,  302,   84,  431,    0,   88, 2015,  731,  418,
 2015,    0,   88,  424, 7373,  119,  431,    0,  552,    0,
    0,  808,    0,  427,    0,  442,  454,    0,    0,   67,
    0,    0, 6538, 2106,  461, 7373,    0, 4059,  437,    0,
  505, 4421,    0,  464,  520,    0,    0,  -32,   71,   88,
    0, 5000, 5084, 2036,  530,    0,    0,  507,    0,  196,
    0,  365,    0,    0,    0,  432, 2176,  585, 1135, 1045,
    0,    0, 1103,    0,    0, 1135, 4532, 1135, 1135, 1135,
 1135, 1135, 1135, 1135, 2106, 1135, 4700,  572,  391,  720,
    0,    3, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176,
 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176, 2176,
 2176, 2106, 2176,   23,  710,    0, 1135,  987,    0, 2106,
    0,    0, 2015,    0, 4523, 4708,    0, 1039,  695,    0,
    0,  539,    0,    0,   88, 1093,    0, 2176,    0,  630,
 2106,  527,    0,    0,    0,    0,  554,  -28,    0,  564,
    0,    0,    0,  559,    0, 1828,  736,  354, 2106,    0,
  504,    0,  603,    0,    0,  -28,  612,  617,  457,    0,
    0,  611,  365,    0,  297, 6584,  -23,  301,  632,  648,
 2176, 1135,    0,    0, 1103,  720,    0,    0,  678,  521,
 1600,   46,   46,  -18,  -18, 1395, 2073, 3889, 2253, 7100,
 7373, 7373, 7373,  -18, 1446,  521,  103,    0,  669, 6630,
 1294,  556,  200,    0,   79,    0,    4,  289,    0,    0,
   62,    0,    0,  688,    0,    8,  544,   21,    0, 1738,
    0, 1738,    0,  731,  224,  930, 4463,  124,    0, 7373,
    0,    0,    0,  559,  604,    0,    0,  699,    0,    0,
  671,  720,    0,    0,    0,    0,  983,    0,    0,    0,
    0,  712,  712,  712, 2176,    0,    0, 4934,  301,    0,
  572,    0, 6676,  718,    0, 2176,    0,    0,    0,    0,
  716, 1863,    0,    0, 2118,    0,    0,    0,    0,    0,
    0,    0,  576,  301,    0,    0,    0,    0,    0,  697,
    0,   94,    0,    0,  343,  720,  404,    0, 1093,  671,
    0,    0,  369,  729,  -40,    0, 2106,    0,  -28,    0,
    0,    0, 7373, 1135,    0,    0,  808, 4934,  572, 2390,
 2293,    0,    0,    0,    0,  720,    0,  720,    0,    0,
 1196, 4233,    0,    0,  559,    0,   31, 2106,  706,    0,
  739,  714,    0,    0,    0, 1135,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  722,    0,  671,
    0,  369,  743,  729, 2106,    0,   -6,    0,    0,    0,
    0,    0,  755,    0,    0,    0, 1633,    0,  765,    0,
    0,    0,  754, 4784,    0,  809,  771,  813, 2176,    0,
  813,    0,  799,    9, 4934,  671,  803,  310,    0,    0,
    0,    0,    0, 7328, 1135,  800, 2176,    0, 2176, 1135,
    0,    0,    0, 2176,    0, 7146,  813,    0,    0,  671,
 1135,    0,    0, 4850,    0,  810, 2240, 2240, 2240, 2240,
 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240, 2240,
 2240, 2240, 2240, 2240, 2240,  844, 7191,    0, 6722,  848,
    0, 4858,  880,    0,    0,    0,    0,    0,  796,    0,
 2176, 1135,    0,  728, 1711,   51,   51,  569,  569, 2089,
 4645, 4911, 2684, 7237, 7419, 7419, 7419,  569, 2188,  728,
  285,    0,    0,    0,    0, 4934,  813, 2176,    0,    0,
    0,    0,  856,    0,    0, 6768, 2240,    0, 1135,    0,
 7282,    0,  756,  671,  808, 4934, 2566, 2176,  857,    0,
 4421, 1135, 5008,    0, 1227,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0, 2337, 2483,    0,    0,
 3689,    0,    0,    0,    0,    0, 2629,    0,    0, 4111,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1995,    0,  534,    0, 2775,
 4275,    0,    0,    0,    0,    0,    0,    0,    0, 3067,
    0,    0,    0, 3437, 3513,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 5205,    0,    0,    0,    0,    0,    0,    0,    0,
 7481,    0,    0, 3141, 3215,    0,    0,    0, 7481,    0,
 1388,  534, 2526, 2992,    0,  701,    0,    0,    0,    0,
    0,    0, 2964, 4290,    0, 1847, 6782,    0, 2992,    0,
  406,    0,    0, 6400,    0,    0,    0, 3689,    0, 7481,
 5254,    0,    0,  -15, 2921,    0,    0,    0,    0,  326,
    0,    0,    0,    0,    0,    0,    0, 5131,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 3777,    0,   81,    0,  479,  258, 5670,    0,    0,
    0,    0,  222,    0, 3629,    0,    0, 6492,    0,    0,
 7481,    0,    0,    0,  607,  222,    0,    0,    0,    0,
    0,  406,    0,    0,    0, 3845, 3877,    0,    0,    0,
    0,    0,    0, 7430,    0,  516,    0,    0,    0,    0,
  283, 1005,    0,   25,    0,    0,    0,  871,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  495,    0,
    0,  326,    0,    0,    0,    0, 6782,  125, 5724, 5328,
    0,    0, 6492,    0,    0, 5769, 5625, 5823, 5868, 5922,
 5967, 6021, 6066, 6120, 6492, 6165,    0,    0,  906,  291,
    0,  651, 2850, 2850, 2850, 2850, 2850, 2850, 2850, 2850,
 2850, 2850, 7467, 2850, 2850, 2850, 2850, 2850, 2850, 2850,
 2850, 6492, 6782,    0,    0,    0, 6219,    0,    0, 6492,
    0,    0, 7481,    0,  665,    0,    0,    0,    0,    0,
    0,  850,    0,    0,    0,  331,    0, 2992,    0,  627,
 2992,  364,    0,    0,    0,    0, 2727, 3918,    0,    0,
    0,    0,    0,  852,    0, 1005,   18,  874, 6437,    0,
   36,    0,    0,    0,    0, 3994, 5568, 5568,    0,    0,
    0,    0,  326,    0,    0,    0, 5328, 5385,    0,    0,
 6782, 6264,    0,    0, 6492,   74,    0,    0,    0, 7526,
 3812, 7628, 7671, 7741, 7776, 6501, 3000, 5461, 5574,    0,
  748,  828, 1436, 7811, 7843, 7572, 7706,    0,    0,    0,
    0,    0,    0,    0,  241,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  665,  665,    0,    0,    0,
    0,    0,    0,    0, 3289,    0,    0,    0,    0,  730,
    0,    0,    0,  852, 3363,    0,    0,    0,    0,    0,
    0,   97,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 7430,    0,    0,    0, 5451,    0,
    0,    0,    0,    0,    0, 2850,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  885,    0,    0,    0,    0,    0,    0,
 2291, 4119,    0,    0,    0,  397,    0,    0,    0,    0,
    0,    0,    0,    0,  988,    0, 6455,    0, 3587,    0,
    0,    0,  356, 6318,    0,    0,    0,    0,    0, 1051,
    0,    0,    0,    0,    0,    0,    0,  444,    0,    0,
    0,    0,    0,    0,  852,    0,    0, 6492,  859,    0,
    0,    0,    0,    0,    0, 6363,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 4352,    0,    0,
    0,    0,    0,    0, 6492,    0, 1744,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 2992,    0,
    0,    0, 5508, 4367,    0,    0, 4173,   81,    0,    0,
    0,    0,    0,  849, 6827,    0, 7467,    0, 6782, 6873,
    0,    0,    0, 6492,    0,    0,    0,    0,    0,    0,
 6918,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1522,    0,    0,    0,    0,    0, 1342,    0,
 6782, 6964,    0, 7909, 1672, 7998, 8039, 8109, 8138, 2408,
 2661, 1561, 1963,    0,   41,  596,  741, 8167, 2520, 7955,
 8074,    0,    0,    0,    0,    0,    0, 2992,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 7009,    0,
    0,    0, 1288,    0,    0,    0, 1122, 6492,    0,    0,
  874, 7055,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0, -115, -103, -106,  817, -382,    0,  383,    6,  217,
  298,   73,    0,   -7,  691,  588,    7, -301,    0,    0,
  -16,    0,    0,  740,    0,   -1,   11, -101,    0, 3716,
    0, -469,    0,    0,    0, -129,  557, 7319,  703, -120,
    0,  330, -139,  794,  790,    0, -325, -305,  605,    0,
   16,    0,  598, -243,    0,  250,    0, -204,   -5,    1,
  661,   50,  215,  233,   22,    0,    0,    0,  804,    0,
    0,    0,    0,  543,    0,  547, -228,  271,    0,  660,
  251,  858,    0,    0,    0,    0,  763,    0,    0,    0,
    0,    0,    0,  252, -169,    0,    0,  478,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -135,    0,
};
#define YYTABLESIZE 8259
static const YYINT yytable[] = {                        205,
   38,  235,  346,   51,   83,   28,  411,  413,  207,   49,
  432,  206,  437,  110,  251,   83,  257,  215,  253,   45,
  524,   42,  109,  317,  364,  400,    7,  155,    8,  102,
  102,  273,  127,  533,   86,  275,  276,  129,  341,  101,
  113,  490,    5,  102,   87,  127,  155,  406,  265,   39,
   42,   42,    7,  137,    8,  400,  133,    7,  392,    8,
  345,  475,  117,  299,   42,  266,  118,  564,  427,  391,
  428,  551,   30,  100,  289,  290,  400,  127,   39,   39,
  559,   89,   83,  165,  330,  155,   88,  152,  392,  610,
    4,  183,   39,   89,    4,  273,  127,  591,  266,  183,
  617,  552,  165,   42,  379,  198,  400,  155,  477,  271,
  478,  271,  271,    6,   78,   38,  612,    6,  133,  392,
  208,  219,  342,  359,  183,  465,  466,  379,  363,  133,
  183,   96,  365,   78,  219,  360,   42,  205,  289,  400,
  648,  165,  550,  633,   78,  415,  128,  301,  379,   17,
  151,   90,  273,  133,  219,   83,  275,  276,  302,  110,
  379,  291,  389,  165,  210,  298,  205,  205,  109,  246,
  404,  379,  392,  394,  399,   17,   83,  127,  565,  518,
   17,  521,   16,  488,  470,   22,   97,   30,  183,   83,
  127,  183,  531,  218,  489,  289,  222,   42,  393,  102,
   18,  110,  219,  379,  379,  110,  222,  506,  327,  320,
  109,   22,  499,  127,  109,  532,   22,   52,  102,  421,
   42,  139,   83,  155,  700,  291,  250,  344,  320,   95,
  635,   22,   41,  110,  102,  454,   84,  438,   16,   42,
  379,  125,  109,   42,  349,  174,  462,  379,   39,  135,
   83,  205,  531,  183,  136,   42,   18,  132,  379,  379,
  305,  103,  114,   91,  174,  538,  353,   39,  219,  354,
   43,   42,  464,   99,  218,  138,  467,  469,   16,  165,
  471,  141,  291,   39,  379,  368,  136,   22,  110,  379,
  246,  130,  189,  246,  395,  395,   18,  109,   83,   43,
   43,  174,  379,  183,  403,   83,  124,  267,   83,   83,
  143,  505,  155,   43,  150,  507,  219,   83,  614,  132,
  174,  268,  463,  185,  145,  305,   42,   22,   83,  144,
  132,  185,  268,  379,  617,  462,   83,  146,  619,  620,
  250,  219,  117,  397,  401,  212,  118,   41,  298,  193,
   81,   29,  436,  220,  132,   29,  185,   42,  131,  246,
  117,   81,  185,  174,  118,  183,  220,  353,  165,  537,
  447,  124,  192,  507,  236,  705,  608,  633,  246,  148,
  230,  368,    5,  124,  368,   43,  220,   84,  417,  127,
   96,   83,    7,    5,    8,  535,  107,  460,  553,  107,
  110,   96,  645,    7,  229,    8,  544,  124,  271,  109,
   83,  468,   83,  222,   83,  546,   83,   83,  545,  238,
  185,  311,  484,  185,  125,  563,  106,  246,  246,  106,
    5,  138,   25,  335,  220,  243,   25,  305,   42,  100,
    7,  315,    8,    5,  239,  148,  272,  436,   47,  244,
  114,  219,  436,    7,  271,    8,   98,  500,  501,  502,
  589,   16,   83,  265,  635,   83,  138,   98,  513,   43,
  300,  515,  690,  269,   35,  116,  237,  117,   35,   18,
  126,  118,  271,  484,  100,  185,  367,  100,   43,  219,
  314,   14,  338,   83,   83,  324,  116,  444,  117,  526,
  220,  520,  118,  100,   43,  548,  246,  219,  246,  219,
   22,   83,   52,  325,  100,   17,    3,  540,  366,  336,
   76,  369,   38,  250,   76,  326,   17,  547,   16,   35,
   35,  542,  331,  520,  339,  185,  520,  271,   76,  272,
  311,  311,  272,   42,  199,  200,   18,  357,  220,   76,
  433,   22,   83,  435,   83,  125,  269,  174,  560,  125,
  340,  417,   22,   17,  105,  104,  269,  183,  104,  269,
  350,   39,  590,  220,  450,    4,   17,   22,  351,  305,
  174,  250,  367,  406,    3,  367,  269,  269,   12,  269,
  124,    5,   16,    7,   30,    8,   16,  185,    6,   22,
   13,    7,  407,    8,  135,   52,  338,  268,  338,  414,
   18,  158,   22,  174,   18,  126,  516,  117,  617,  124,
  104,  118,  619,  620,  476,  426,   14,  430,  332,  333,
  482,  106,  116,  336,  117,  336,   12,  429,  118,   30,
  100,   22,  311,  441,  311,   22,  311,  177,  435,  271,
  422,  423,  442,  435,  357,  177,   12,  443,  439,   15,
  195,  633,  634,   16,  287,  450,  287,  287,   13,  116,
  269,  117,  451,  213,   14,  118,   52,   48,   48,   52,
  445,   18,   19,  220,  110,  175,  177,  487,  452,  476,
  476,   76,   76,  109,   14,  219,   76,   45,   45,  201,
  291,   83,  519,  407,  407,  212,  212,   52,  125,  457,
  212,   16,   22,  142,  485,  461,   17,    5,  455,  117,
  436,  220,   42,  118,   17,   52,  311,   15,  472,   18,
  491,   16,  541,  155,  519,  473,  474,  519,  493,  220,
  142,  220,  142,  495,  306,   16,  142,  177,  635,   18,
   19,    5,   22,  175,   41,  487,  391,  487,  509,    5,
   22,  117,  511,   18,  142,  118,   52,  701,  528,  517,
  142,  142,  142,  142,  307,    5,  554,  117,  555,   12,
   22,  118,  485,  561,  485,  142,  311,  556,  296,  165,
  296,  412,   43,  558,   22,  568,  116,  142,  117,  185,
   47,   47,  118,  356,  596,  434,  392,   46,  307,  286,
  307,  286,  286,   12,   47,   12,  296,   14,  296,  296,
    3,  296,  598,  142,  142,  142,  119,  308,  120,  370,
  371,  372,  373,  374,  375,  376,  377,  378,  379,  380,
  381,  382,  383,  384,  385,  386,  387,  388,  602,  390,
  603,   14,  604,   14,   16,  249,  142,   14,  256,  177,
  142,  258,  259,  260,  261,  262,  263,  609,  312,   16,
  312,  613,   18,  264,  420,  266,    1,    2,  142,  142,
  636,  653,  142,  297,  673,  398,  677,   18,   16,    3,
   16,  680,   12,  683,   16,  693,  312,  704,  312,  312,
    4,  312,  296,   22,   13,  309,   18,  635,   18,  142,
  699,  401,   18,   48,  204,  204,    5,  453,   22,  204,
  229,  435,  115,    6,   38,  213,    7,  220,    8,  202,
   14,   37,  355,  271,  260,  261,  562,   22,  319,   22,
  446,  245,   92,   22,  254,  440,   76,   76,    9,   47,
   10,   76,    4,  695,  449,  400,   11,  480,  255,  297,
  479,   12,  405,   15,  322,   76,  523,   16,    5,  362,
    0,  338,  211,   13,    0,    6,   76,    0,    7,    0,
    8,    0,  312,    0,    0,   18,   19,    0,  225,  175,
  225,  225,   14,    0,  225,  225,  225,  225,  336,   14,
  225,  503,   92,  225,    0,    0,  225,  225,   11,  481,
  225,  225,  510,   12,    0,  225,   22,  225,    0,    0,
  225,  225,    5,  498,  117,  100,  225,  225,  118,   16,
    0,    0,   15,  225,  225,    0,   16,  225,    0,  225,
    0,  225,  225,    0,    0,  204,  204,   18,   93,   17,
  204,   14,   14,    0,   18,   19,    0,    3,   20,  225,
  225,   21,    0,    0,    0,    0,   47,  225,  225,  225,
  225,  225,  225,  225,  204,  204,    0,    0,   22,    0,
    0,    0,  225,  402,  225,   22,  225,  225,   16,   16,
    0,  313,    0,  313,    7,    0,    8,    0,    7,    0,
    8,   17,    0,    0,    0,    3,   18,   18,   93,   14,
  225,  153,    0,    0,    0,    3,    0,    0,  307,  313,
  313,  313,  313,   12,  313,  154,  155,    0,    0,   12,
    0,    0,  156,   12,    0,  606,  157,   22,   22,    0,
  313,  107,  158,  225,    0,  147,   16,  225,  159,  160,
  504,    0,  161,  637,  162,  639,  163,  164,    0,  204,
  642,   14,    0,    0,   18,  225,  225,   14,    0,  225,
    0,   14,  225,    0,  292,  214,  293,   12,  294,  295,
    0,    0,  165,  166,  167,  168,  169,   12,  170,   13,
  288,  288,  288,  288,    0,   22,  225,  171,   16,  172,
   15,  173,    0,    0,   16,  313,    0,  686,   16,    0,
  536,  288,    0,  410,    0,   14,   18,   17,  153,    0,
    0,   17,   18,  108,    0,   14,   18,    0,    0,  296,
    0,    0,  154,  155,  691,    5,  543,  117,    0,  156,
    0,  118,    0,  157,    0,    0,    0,   22,  416,  158,
  231,    0,   16,   22,  703,  159,  160,   22,   15,  232,
    0,  233,  174,  163,  164,    0,    5,  707,  117,  595,
   18,   19,  118,    0,  175,    0,  600,    0,    0,    0,
   18,   19,  214,    0,  175,    0,    0,  611,    0,  165,
  166,  167,  168,  169,   12,  170,    0,    0,    0,    0,
  395,   22,    0,    0,  171,    0,    0,    0,  173,    0,
    0,   22,    0,    0,    0,    0,  652,    0,    0,  595,
  595,  595,  595,  595,  595,  595,  595,  595,  595,  595,
  595,  595,  595,  595,  595,  595,  595,  595,    0,    0,
    0,    0,  260,    0,  260,  260,    0,    0,  260,  260,
  260,  260,    0,  260,  260,    0,    0,  260,    0,    0,
  260,  260,    0,    0,  260,  260,    0,    0,    0,  260,
    0,  260,  395,   47,  260,  260,    0,    0,  689,    0,
  260,  260,  234,    0,  395,    0,    0,  260,  260,  595,
  459,  260,    0,  260,    0,  260,  260,    0,  702,  260,
  197,  260,    0,    0,    0,  260,  260,  260,  260,  260,
  395,  260,  260,  260,  260,  260,   14,    0,   22,    0,
    0,  260,  260,  260,  260,  260,  260,  260,  197,    0,
    0,  260,  260,  260,  260,  260,  260,    0,  260,    0,
  260,  260,    0,  395,  273,    0,  274,  395,  275,  276,
    0,    0,  277,   16,  278,    0,  197,  197,  197,  197,
  197,    0,    0,    0,  260,  395,  395,    0,    0,  395,
    0,   18,  197,    0,    0,    0,  311,    0,  311,    0,
    0,    0,    0,    0,  197,  287,  288,  289,  290,    0,
    0,    0,    0,    0,    0,  273,  395,  260,    0,  275,
  276,  260,   22,  277,  311,  278,  311,  311,    0,  311,
  197,  197,  197,    0,    0,    0,    0,    0,    0,  260,
  260,  260,  245,  260,  245,  245,  260,    0,  245,  245,
  245,  245,    0,    0,  245,    0,  287,  245,  289,  290,
  245,  245,    0,  197,  245,  245,    0,  197,    0,  245,
  260,  245,    0,    0,  245,  245,    0,    0,    0,    0,
  245,  245,    0,    0,    0,  197,  197,  245,  245,  197,
    0,  245,    0,  245,  291,  245,  245,    0,    0,  245,
    0,  245,    0,    0,    0,  245,  245,  245,  245,  245,
  311,  245,  245,  245,  245,  245,  197,    0,    0,    0,
    0,  245,  245,  245,  245,  245,  245,  245,    0,    0,
    0,  245,  245,  245,  245,  245,  245,    0,  245,    0,
  245,  245,    0,    0,    0,  291,  284,  284,  284,  284,
  284,  284,  284,  569,    0,  570,  571,    0,    0,  572,
  573,  574,  575,    0,  245,    3,    0,    0,  576,  273,
  284,  577,  578,  275,  276,  154,  155,  277,    0,  278,
  579,    0,  156,    0,    0,  580,  157,    0,    0,    0,
    0,  581,  158,    0,    0,    0,    0,  245,  159,  160,
    0,  245,  161,    0,  162,    0,  163,  164,    0,    0,
  287,  288,  289,  290,    0,    0,    0,    0,    0,  245,
  245,  245,    0,  245,  582,  495,  245,    0,    0,    0,
    0,    0,  583,  166,  167,  168,  169,   12,  170,    0,
    0,    0,    0,  275,    0,    0,    0,  171,    0,  584,
  245,  585,  586,    0,    0,  275,  275,  275,  275,  275,
  275,  275,  275,  275,  223,    0,  223,  223,    0,    0,
  223,  223,  223,  223,    0,  587,  223,    0,    0,  223,
  617,  275,  223,  223,  619,  620,  223,  223,  621,    0,
  622,  223,    0,  223,    0,    0,  223,  223,    0,  291,
    0,    0,  223,  223,    0,    0,    0,    0,   15,  223,
  223,    0,  588,  223,    0,  223,    0,  223,  223,    0,
    0,  631,  632,  633,  634,    0,    0,    0,    0,    0,
   18,   19,    0,    0,  175,  223,  223,  307,    0,    0,
    0,    0,   12,  223,  223,  223,  223,  223,  223,  223,
    0,  273,    0,  274,    0,  275,  276,    0,  223,  277,
  223,   22,  223,  223,    0,  279,  280,  281,  282,  283,
    0,  284,    0,    0,    0,  395,    0,    0,    0,  395,
   14,    0,    0,    0,    0,    0,  223,    5,    0,  395,
  395,  286,  287,  288,  289,  290,  395,    7,    0,    8,
  395,    0,    0,    0,    0,    0,  395,    0,    0,    0,
  635,    0,  395,  395,    0,    0,  395,   16,  395,  223,
  395,  395,    0,  223,  395,    0,  395,  335,    0,    0,
  395,  395,  395,  395,  395,   18,  395,  395,    0,  395,
    0,  223,  223,    0,  100,  223,  395,  395,  395,  395,
  395,  395,  395,   54,    0,    0,  395,  395,  395,  395,
  395,  395,   47,  395,    0,  395,   22,   55,    0,    0,
   14,    0,  223,    0,    0,    0,    0,    0,    0,  512,
    0,  291,    0,    0,   56,    0,   57,    0,   58,  395,
   59,   60,    0,    0,   61,    0,   62,    0,   63,   64,
    0,    0,   65,    0,   66,   14,    0,   16,   67,   68,
   69,   70,    0,    0,   71,   72,    0,    0,    0,    0,
   17,  395,  395,    0,    0,   18,  395,   44,    0,   12,
    0,    0,    0,    0,   73,   74,   75,   76,   77,   78,
    0,   79,   16,  153,  395,  395,  395,    3,  395,  285,
  285,  285,  285,  285,  285,    0,   22,  154,  155,    0,
   18,    0,    0,    0,  156,    0,    0,   14,  157,    0,
    0,    0,  285,    0,  158,  395,    0,    0,    0,    4,
  159,  160,    0,   44,  161,    0,  162,   44,  163,  164,
    0,   22,    0,    0,    0,    5,    0,    0,    0,   44,
    0,    0,    6,    0,   16,    7,    0,    8,    0,    0,
    0,   44,    0,    0,  165,  166,  167,  168,  169,   12,
  170,    0,   18,    0,   80,    0,    0,    0,    0,  171,
    0,  172,    0,  173,  153,   11,    0,   44,   44,   44,
   12,    0,  273,    0,  274,    0,  275,  276,  154,  155,
  277,    0,  278,   22,    0,  156,  279,   14,  617,  157,
  618,    0,  619,  620,    0,  158,  621,    0,  622,    0,
   44,  159,  160,    0,   44,  161,    0,  162,   14,  163,
  164,    0,    0,  287,  288,  289,  290,    0,    0,    0,
   15,    0,   44,   44,  174,    0,   44,    0,  214,  631,
  632,  633,  634,    0,  153,  165,  166,  167,  168,  169,
   12,  170,   18,   19,    0,   16,  175,   47,  154,  155,
  171,    0,  194,   44,  173,  156,    0,    0,   17,  157,
    0,    0,    0,   18,  514,  158,    0,    0,    0,    0,
    0,  159,  160,   22,    0,  161,    0,  162,   14,  163,
  164,    0,    0,    0,    0,    0,    0,  617,    0,    0,
   14,  619,  620,    0,   22,  621,    0,  622,  574,    0,
    0,    0,  291,    0,    0,  165,  166,  167,  168,  169,
   12,  170,  154,  155,    0,  174,    0,    0,  635,  156,
  171,    0,  194,  157,  173,    0,    0,   16,  631,  158,
  633,  634,    0,   18,    0,  159,  160,    0,    0,  161,
    0,  162,    0,  163,  164,   18,    0,    0,   14,    0,
    0,    0,  273,  127,  274,    0,  275,  276,    0,    0,
  277,    0,  278,    0,   22,    0,  279,  280,  281,  165,
  166,  167,  168,  169,   12,  170,   22,    0,    0,    0,
  127,    0,    0,    0,  171,  174,  194,    0,  585,    0,
  127,    0,  127,  287,  288,  289,  290,    0,    0,  404,
   16,    0,    0,   18,    0,    0,    0,    0,    0,  127,
  404,   16,   14,  127,    0,    0,    0,  635,    0,    0,
  127,    0,   47,    0,    0,  127,  404,  404,  404,  404,
  404,  404,  404,  404,   22,    0,  404,  127,  404,  539,
  404,  404,    0,    0,  404,    0,  404,    0,    0,  588,
  404,  404,  404,  404,  404,  404,  404,  404,  404,  404,
  404,    0,    0,  127,    0,   14,  404,   18,    0,    0,
    0,  404,    0,    0,    0,    0,  404,  404,  404,  404,
  404,  404,  291,    0,    0,    0,    0,    0,    0,  273,
    0,  274,    0,  275,  276,    0,  127,  277,   22,  278,
  127,    0,   16,  279,  280,  281,  282,  283,    0,  404,
  404,  404,    0,  127,    0,    0,    0,    0,  127,  127,
   18,  277,  277,  277,  277,  277,  277,  277,  277,  277,
  287,  288,  289,  290,    0,    0,    0,    0,    0,    0,
    0,  404,  404,    0,    0,  405,  404,  277,    0,  127,
    0,   22,    0,    0,    0,    0,  405,    0,    0,  404,
    0,    0,    0,    0,  404,  404,  404,    0,  404,    0,
    0,    0,  405,  405,  405,  405,  405,  405,  405,  405,
    0,    0,  405,    0,  405,    0,  405,  405,  198,    0,
  405,    0,  405,    0,    0,  404,  405,  405,  405,  405,
  405,  405,  405,  405,  405,  405,  405,    0,    0,    0,
    0,    0,  405,    0,    0,    0,  198,  405,    0,  291,
    0,  279,  405,  405,  405,  405,  405,  405,    0,    0,
    0,    0,    0,  279,  279,  279,  279,  279,  279,  279,
  279,  279,    0,    0,  198,  198,  198,  198,  198,    0,
    0,    0,    0,    0,    0,  405,  405,  405,    0,  279,
  198,  279,    0,    0,    0,  617,    0,  618,    0,  619,
  620,    0,  198,  621,    0,  622,    0,    0,    0,  623,
  624,  625,  626,  627,    0,    0,    0,  405,  405,    0,
    0,  410,  405,    0,    0,    0,    0,    0,  198,  198,
  198,    0,  410,    0,    0,  405,  631,  632,  633,  634,
  405,  405,  405,    0,  405,    0,    0,    0,  410,  410,
  410,  410,  410,  410,  410,  410,    0,    0,  410,    0,
  410,  198,  410,  410,    0,  198,  410,    0,  410,    0,
    0,  405,  410,  410,  410,  410,  410,  410,  410,  410,
  410,  410,  410,  198,  198,    0,    0,  198,  410,    0,
    0,    0,    0,  410,    0,    0,    0,    0,  410,  410,
  410,  410,  410,  410,    0,  276,  276,  276,  276,  276,
  276,  276,  276,  617,  198,  618,    0,  619,  620,  195,
    0,  621,    0,  622,    0,  635,    0,  623,  624,  625,
  276,  410,  410,  410,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  195,    0,  195,    0,
    0,    0,  195,    0,  631,  632,  633,  634,    0,    0,
    0,    0,    0,  410,  410,    0,    0,   57,  410,    0,
    0,    0,    0,    0,    0,  195,  195,    0,   57,  195,
    0,  410,    0,    0,    0,    0,  410,  410,  410,    0,
  410,  195,    0,    0,   57,   57,   57,   57,   57,   57,
   57,   57,    0,  195,   57,    0,   57,    0,   57,   57,
    0,    0,    0,    0,   57,    0,    0,  410,   57,   57,
   57,   57,   57,   57,   57,   57,   57,   57,   57,  195,
  195,  195,    0,    0,   57,    0,    0,    0,    0,   57,
    0,    0,    0,  635,   57,   57,   57,   57,   57,   57,
    0,   57,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  195,    0,    0,    0,  195,    0,    0,    0,
  321,    0,  321,    0,    0,    0,    0,   57,   57,   57,
    0,    0,    0,    0,  195,  195,    0,  321,  195,  321,
    0,    0,    0,  321,  321,  321,  321,  321,  321,  321,
  321,  321,    0,  321,    0,    0,    0,    0,    0,   57,
   57,    0,    0,  409,   57,  195,    0,    0,    0,  321,
  321,  321,  321,  321,  409,    0,    0,   57,    0,    0,
    0,    0,   57,   57,   57,    0,   57,    0,    0,    0,
  409,  409,  409,  409,  409,  409,  409,  409,    0,    0,
  409,    0,  409,    0,  409,  409,   44,    0,  409,    0,
  409,    0,    0,   57,  409,  409,  409,  409,  409,  409,
  409,  409,  409,  409,  409,    0,    0,    0,    0,    0,
  409,    0,    0,    0,  321,  409,    0,    0,    0,    0,
  409,  409,  409,  409,  409,  409,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  321,
    0,    0,   44,    0,   45,   45,   44,    0,    0,    0,
  301,    0,  301,  409,  409,  409,    0,    0,   44,  321,
    0,  321,    0,    0,    0,  321,  321,  321,  321,  321,
   44,  321,  321,  321,  301,  301,  301,  301,  301,  301,
  301,  301,    0,  301,    0,  409,  409,    0,    0,   91,
  409,  321,  321,  321,  321,  321,   44,   44,   44,  301,
   91,    0,    0,  409,    0,    0,    0,    0,  409,  409,
  409,    0,  409,    0,    0,    0,   91,   91,   91,   91,
   91,   91,   91,   91,    0,    0,   91,    0,   91,   44,
   91,   91,    0,   44,   91,    0,   91,    0,    0,  409,
   91,   91,   91,   91,   91,   91,   91,   91,   91,    0,
   91,   44,   44,    0,    0,   44,   91,    0,    0,    0,
    0,   91,    0,  110,  301,    0,   91,   91,   91,   91,
   91,   91,    0,   91,  110,    0,    0,    0,    0,    0,
    0,  321,   44,    0,    0,    0,    0,    0,    0,    0,
  110,  110,  110,  110,  110,  110,  110,  110,    0,   91,
  110,    0,  110,    0,  110,  110,    0,    0,  110,    0,
  110,    0,    0,    0,  110,  110,  110,  110,  110,    0,
  110,  110,  110,  116,  110,    0,    0,    0,    0,    0,
  110,   91,   91,    0,    0,  110,   91,  128,    0,    0,
  110,  110,  110,  110,  110,  110,    0,  110,  128,   91,
    0,    0,    0,    0,   91,   91,   91,    0,    0,    0,
    0,    0,    0,    0,  128,  128,  128,  128,  128,  128,
  128,  128,    0,  110,  128,    0,  128,    0,  128,  128,
    0,    0,    0,    0,  128,   91,    0,    0,  128,  128,
  128,  128,  128,  128,  128,  128,  128,  128,  128,    0,
    0,    0,    0,    0,  128,  110,  110,    0,    0,  128,
  110,  111,    0,    0,  128,  128,  128,  128,  128,  128,
    0,  128,  111,  110,    0,    0,    0,    0,  110,  110,
  110,    0,    0,    0,    0,    0,    0,    0,  111,  111,
  111,  111,  111,  111,  111,  111,    0,  128,  111,    0,
  111,    0,  111,  111,    0,    0,  111,    0,  111,  110,
    0,    0,  111,  111,  111,  111,  111,    0,  111,  111,
  111,  116,  111,    0,    0,    0,    0,    0,  111,  128,
  128,    0,    0,  111,  128,  109,    0,    0,  111,  111,
  111,  111,  111,  111,    0,  111,  109,  128,    0,    0,
    0,    0,  128,  128,  128,    0,    0,    0,    0,    0,
    0,    0,  109,  109,  109,  109,  109,  109,  109,  109,
    0,  111,  109,    0,  109,    0,  109,  109,    0,    0,
  109,    0,  109,  128,    0,    0,  109,  109,  109,  109,
  109,  109,  109,  109,  109,    0,  109,    0,    0,    0,
    0,    0,  109,  111,  111,    0,    0,  109,  111,  169,
    0,    0,  109,  109,  109,  109,  109,  109,    0,  109,
    0,  111,    0,    0,    0,    0,  111,  111,  111,    0,
    0,    0,    0,    0,    0,    0,  169,  169,    0,  169,
  169,  169,  169,    0,    0,  109,  169,    0,  169,    0,
  169,  169,    0,    0,  169,    0,  169,  111,    0,    0,
  169,  169,  169,  169,  169,  169,  169,  169,  169,  169,
  169,    0,    0,    0,    0,    0,    0,  109,  109,    0,
    0,  169,  109,    0,    0,  167,  169,  169,  169,  169,
  169,  169,    0,  169,    0,  109,    0,    0,    0,    0,
  109,  109,  109,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  167,  167,    0,  167,  167,  167,  167,  169,
  169,  169,  167,    0,  167,    0,  167,  167,    0,    0,
  167,  109,  167,    0,    0,    0,  167,  167,  167,  167,
  167,  167,  167,  167,  167,  167,  167,    0,    0,    0,
    0,  169,  169,    0,    0,    0,  169,  167,    0,  396,
    0,    0,  167,  167,  167,  167,  167,  167,    0,  167,
    0,    0,    0,    0,  169,  169,  169,    0,  169,    0,
    0,    0,    0,    0,    0,    0,  396,  396,  396,    0,
    0,    0,  396,    0,    0,  167,  167,  167,    0,    0,
    0,   62,    0,    0,    0,  169,  396,    0,    0,    0,
    0,    0,   62,    0,    0,  396,  396,  396,  396,  396,
    0,    0,    0,    0,    0,    0,    0,  167,  167,   62,
   62,  396,  167,    0,   62,   62,    0,    0,   62,    0,
   62,    0,    0,    0,    0,    0,    0,    0,   62,    0,
  167,  167,  167,    0,  167,    0,    0,   62,   62,   62,
   62,  142,    0,    0,    0,    0,    0,    0,   62,  396,
  396,  396,    0,   62,    0,    0,    0,    0,    0,    0,
    0,  167,    0,    0,    0,   62,    0,    0,  142,  142,
  142,    0,    0,    0,  142,    0,    0,    0,    0,    0,
    0,  396,  396,    3,    0,    0,  396,    0,    0,    0,
    0,   62,    0,    0,    4,    0,    0,  142,  142,  142,
  142,  142,    0,    0,  396,  396,    0,    0,  396,    0,
    5,    0,    0,  142,    0,    0,    0,    6,    0,    0,
    7,    0,    8,   62,   62,  142,    0,    0,   62,   60,
    0,    0,    0,    0,    0,  396,    0,    0,    0,    0,
    0,   62,    0,    0,  203,    0,   62,   62,    0,    0,
   11,  142,  142,  142,    0,   12,    0,   60,   60,    0,
    0,    0,   60,    0,    0,    0,   60,   13,   60,    0,
    0,    0,    0,    0,    0,    0,   60,   62,    0,    0,
    0,    0,    0,    0,  142,    0,   60,   60,  142,    0,
    0,    0,  300,   14,  300,    0,   60,  137,    0,    0,
    0,   60,    0,  300,    0,    0,  142,  142,  137,    0,
  142,    0,    0,   60,    0,  300,  300,  300,  300,  300,
  300,  300,  300,  300,  137,  300,   15,    0,    0,  138,
   16,  137,    0,    0,  137,    0,  137,  142,    0,   60,
  138,  300,    0,   17,    0,  204,    0,    0,   18,   19,
    0,    0,  175,    0,    0,   21,  138,    0,  137,    0,
    0,    0,    0,  138,  137,    0,  138,    0,  138,  137,
  185,   60,   60,    0,    0,    0,   60,    3,  273,   22,
  274,  137,  275,  276,    0,    0,  277,    0,  278,   60,
  138,    0,  279,  280,   60,   60,  138,  185,  185,  185,
    0,  138,    0,  185,    5,    0,  300,  137,    0,    0,
    0,    0,    0,  138,    7,    0,    8,    0,    0,  287,
  288,  289,  290,    0,    0,   60,  185,  185,  185,  185,
  185,    0,    0,    0,    0,    0,    0,    0,    0,  138,
  137,    0,  185,    0,  137,    0,  191,    0,    0,   12,
    0,    0,    0,    0,    0,    0,    0,  137,    0,  137,
    0,  107,  137,  137,    0,    0,  137,    0,    0,  137,
    0,    0,  138,  191,  191,  191,  138,    0,    0,  191,
  185,  185,  185,    0,    0,    0,    0,   14,    0,  138,
    0,  138,    0,  137,  138,  138,    0,    0,  138,    0,
    0,  138,  191,  191,  191,  191,  191,    0,  291,    0,
    0,    3,    0,  185,    0,    0,    0,  185,  191,    0,
   15,    0,    4,    0,   16,  138,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  185,  185,   17,    5,  185,
    0,    0,   18,  108,    0,    6,    0,    0,    7,    0,
    8,    0,    0,    0,    0,    0,  191,  191,  191,    0,
    0,    0,    0,   61,    0,    0,  185,  104,    0,    0,
  105,  128,    0,   22,   61,    0,    0,    0,  106,    0,
    0,    0,    0,   12,    0,    0,    0,    0,    0,  191,
   61,    0,    0,  191,    0,  107,    0,   61,  128,    0,
   61,    0,   61,    0,    0,    0,    0,    0,  128,    0,
  128,  191,  191,    0,    0,  191,    0,    0,   17,   61,
    0,   14,   61,    0,    0,  178,    0,  128,    0,   17,
   61,  128,    0,    0,    0,   61,  178,    0,  128,    0,
    0,    0,  191,  128,    0,    0,    0,   61,    0,    0,
    0,    0,  178,    0,   15,  128,    0,    0,   16,  178,
    0,    0,  178,    0,  178,    0,    0,    0,    0,    0,
  178,   17,    0,   61,    0,    0,   18,  108,    0,    0,
    0,  128,    0,    0,  178,    3,    0,    0,    0,    0,
    0,    0,  178,    0,    0,    0,    4,  178,    0,    0,
    0,    0,    0,    0,    0,    0,   61,   22,    0,  178,
   61,    0,    5,    0,  128,    0,    0,    0,  128,    6,
    0,    0,    7,   61,    8,    0,    0,   62,   61,   61,
    0,  128,    0,    0,    0,  178,  128,  128,   62,    0,
    0,    0,   69,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   11,   69,    0,    0,  640,   12,    0,   61,
  643,   62,    0,  646,   62,    0,   62,  128,  178,   13,
    0,    0,  178,    0,    0,    0,   69,    0,    0,   69,
    0,   69,    0,   62,    0,  178,   62,    0,    0,    0,
  178,  178,    0,  675,   62,   14,  678,    0,   69,   62,
  681,   69,  682,    0,   64,  685,    0,    0,    0,   69,
    0,   62,    0,    0,   69,   64,    0,    0,    0,   60,
    0,  178,    0,    0,    0,    0,   69,    0,   15,  688,
   60,   64,   16,    0,    0,  692,    0,   62,   64,    0,
    0,   64,    0,   64,    0,   17,    0,    0,    0,    0,
   18,   19,   69,   60,  175,    0,   60,    0,   60,    0,
   64,  708,    0,    0,    0,    0,    0,    0,    0,    0,
   62,   64,    0,    3,   62,   60,   64,    0,   60,    0,
    0,   22,    0,    0,    0,   69,   60,   62,   64,   69,
    0,   60,   62,   62,    0,    0,    0,    0,    0,    0,
    5,    0,   69,   60,    0,    0,    0,   69,   69,    0,
    7,    0,    8,    0,   64,    3,    0,    0,    0,    0,
    0,    0,    0,   62,    0,    0,    0,    0,    0,   60,
    0,    0,    0,    0,    0,    0,    0,    0,   69,    0,
  335,    0,    5,    0,    0,   12,    0,   64,    0,    0,
    0,   64,    7,    0,    8,    0,    0,  107,    0,    0,
    0,    0,   60,    0,   64,    0,   60,    0,    0,   64,
   64,    0,    0,    0,    0,    3,    0,    0,    0,   60,
    0,    0,  484,   14,   60,   60,    0,   12,    0,    0,
    0,    0,    0,    0,  154,  155,    0,    0,    0,  107,
   64,  156,  406,    0,    0,  157,    0,    0,    0,    0,
    0,  158,    7,    0,    8,   60,   15,  159,  160,    0,
   16,    0,    0,    0,    0,   14,    0,    0,    0,    0,
    0,    0,    0,   17,    0,    0,    0,    0,   18,  108,
    0,    0,    0,    0,    0,    0,    0,   12,    0,    0,
    0,  165,  166,  167,  168,  169,   12,  170,   15,  107,
    0,    0,   16,    0,    0,    0,  171,    0,  194,   22,
    0,    0,    0,    0,    0,   17,    0,    0,    0,    0,
   18,  108,    0,    0,    0,   14,    0,    0,    0,    0,
    0,    0,    0,    0,   14,    0,  154,  155,    0,    0,
    0,    0,    0,  156,    0,    0,    0,  157,    0,    0,
    0,   22,    0,  158,    0,  247,    0,    0,   15,  159,
  160,    0,   16,  161,    0,  162,    0,  163,  164,    0,
    0,  248,    0,    0,  617,   17,  618,    0,  619,  620,
   18,  108,  621,    0,  622,    0,    0,    0,  623,   18,
    0,    0,    0,  165,  166,  167,  168,  169,   12,  170,
    0,    0,  154,  155,    0,    0,    0,    0,  171,  156,
  194,   22,    0,  157,    0,  631,  632,  633,  634,  158,
   22,  361,    0,    0,    0,  159,  160,    0,  409,  161,
    0,  162,    0,  163,  164,    0,   14,  273,    0,  274,
    0,  275,  276,    0,    0,  277,    0,  278,    0,    0,
    0,  279,  280,  281,  282,  283,    0,  284,  285,  165,
  166,  167,  168,  169,   12,  170,    0,    0,    0,    0,
    0,    0,    0,  248,  171,    0,  194,  286,  287,  288,
  289,  290,    0,    0,    0,    0,  154,  155,    0,    0,
    0,   18,    0,  156,    0,    0,    0,  157,    0,    0,
    0,    0,   14,  158,  635,  599,    0,    0,    0,  159,
  160,    0,    0,  161,    0,  162,    0,  163,  164,    0,
    0,    0,   22,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  248,
    0,    0,    0,  165,  166,  167,  168,  169,   12,  170,
    0,    0,  154,  155,    0,    0,    0,   18,  171,  156,
  194,    0,    0,  157,    0,    0,    0,  291,    0,  158,
    0,  651,    0,    0,    0,  159,  160,    0,  679,  161,
    0,  162,    0,  163,  164,    0,   14,  273,   22,  274,
    0,  275,  276,    0,    0,  277,    0,  278,    0,    0,
    0,  279,  280,  281,  282,  283,    0,  284,  285,  165,
  166,  167,  168,  169,   12,  170,    0,    0,    0,    0,
    0,    0,    0,  248,  171,    0,  194,  286,  287,  288,
  289,  290,    0,    0,    0,    0,  154,  155,    0,    0,
  617,   18,  618,  156,  619,  620,    0,  157,  621,    0,
  622,    0,   14,  158,  623,  624,    0,    0,    0,  159,
  160,    0,    0,  161,    0,  162,    0,  163,  164,    0,
    0,    0,   22,    0,    0,    0,    0,    0,    0,    0,
    0,  631,  632,  633,  634,    0,    0,    0,    0,  248,
    0,    0,    0,  165,  166,  167,  168,  169,   12,  170,
    0,    0,  154,  155,    0,    0,    0,   18,  171,  156,
  194,    0,    0,  157,    0,    0,    0,  291,    0,  158,
    0,    0,    0,    0,    0,  159,  160,    0,  706,  161,
    0,  162,    0,  163,  164,    0,   14,  273,   22,  274,
    0,  275,  276,    0,    0,  277,    0,  278,    0,    0,
    0,  279,  280,  281,  282,  283,    0,  284,  285,  347,
  166,  167,  168,  169,   12,  170,    0,    0,    0,    0,
  635,    0,    0,  248,  171,    0,  194,  286,  287,  288,
  289,  290,    0,    0,    0,    0,  154,  155,    0,    0,
    0,   18,    0,  156,    0,    0,    0,  157,    0,    0,
    0,    0,   14,  158,    0,    0,    0,    0,    0,  159,
  160,    0,    0,  161,    0,  162,    0,  163,  164,    0,
    0,    0,   22,  217,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  248,
    0,    0,    0,  348,  166,  167,  168,  169,   12,  170,
  217,  217,  217,  217,  217,  217,  217,   18,  171,    0,
  194,    0,    0,    0,  217,  217,    0,  291,  217,    0,
  217,    0,    0,    0,  217,  217,  217,  217,  217,  217,
  217,  217,  217,  217,  217,    0,   14,    0,   22,    0,
    0,    0,    0,    0,    0,  217,    0,  217,    0,    0,
  217,  217,  217,  217,  217,  217,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  248,  217,  217,  217,  217,  217,  217,
  217,    0,    0,  217,  217,  217,    0,    0,  217,  217,
    0,   18,  217,    0,  217,    0,  395,    0,  217,  217,
  217,  217,  217,  217,  217,  217,  217,  217,  217,    0,
    0,    0,    0,    0,    0,  217,  217,    0,    0,    0,
  217,    0,   22,    0,  217,  217,  217,  217,  217,  217,
    0,    0,    0,    0,    0,    0,    0,    0,  217,  217,
  217,  321,  217,  321,    0,    0,    0,  321,  321,  321,
  321,  321,    0,  321,  321,    0,    0,    0,  217,  217,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  321,  321,  321,  321,  321,    0,    0,
  395,    0,    0,    0,    0,    0,    0,    0,    0,  217,
  217,    0,    0,    0,    0,    0,    0,  209,  209,  209,
  209,  209,  209,  209,    0,    0,  395,    0,    0,    0,
    0,  209,  209,  217,  217,  209,  217,  209,    0,    0,
    0,  209,  209,  209,  209,  209,  209,  209,  209,  209,
    0,  209,    0,    0,    0,    0,    0,    0,  395,  395,
    0,    0,    0,  395,    0,    0,    0,  209,  209,  209,
  209,  209,  209,    0,  391,  391,    0,  391,  391,  391,
    0,  395,  395,  321,  391,  395,  391,    0,  391,  391,
    0,    0,  391,    0,  391,    0,    0,    0,  391,  391,
  391,  391,  391,  391,  391,  391,  391,    0,  391,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  391,  391,  391,  391,  391,  391,
    0,    0,  209,    0,    0,    0,    0,    0,    0,    0,
  210,  210,    0,  210,  210,  210,    0,    0,    0,    0,
  210,  309,  210,  309,  210,  210,    0,  209,  210,    0,
  210,    0,    0,    0,  210,  210,  210,  210,  210,  210,
  210,  210,  210,    0,  210,    0,  309,  309,  309,  309,
  309,  309,  309,    0,  309,    0,    0,    0,    0,  391,
  210,  210,  210,  210,  210,  210,    0,  381,    0,  381,
  309,  381,  381,    0,    0,    0,    0,  381,    0,  381,
    0,  381,  381,    0,  391,  381,    0,  381,    0,    0,
    0,  381,  381,  381,  381,  381,    0,  381,  381,  381,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  381,  381,  381,
  381,  381,  381,    0,    0,  210,    0,  381,    0,  381,
    0,  381,  381,    0,  310,  309,  310,  381,    0,  381,
    0,  381,  381,    0,    0,  381,    0,  381,    0,    0,
  210,  381,  381,  381,  381,  381,    0,  381,  381,    0,
  310,  310,  310,  310,  310,  310,    0,  310,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  381,  381,  381,
  381,  381,  381,  310,    0,  336,  336,  336,  336,  336,
    0,    0,    0,    0,  336,    0,  336,    0,  336,  336,
    0,    0,  336,    0,  336,    0,    0,  381,  336,  336,
  336,  336,  336,  336,  336,  336,  336,    0,  336,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  319,    0,  319,    0,  336,  336,  336,  336,  336,  319,
    0,  319,    0,  319,  319,    0,    0,  319,  310,  319,
    0,    0,    0,  319,  319,  319,  319,  319,  319,  319,
  319,  319,    0,  319,    0,    0,    0,  381,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  319,
  319,  319,  319,  319,  315,    0,  315,    0,    0,    0,
    0,    0,    0,  315,    0,  315,    0,  315,  315,  336,
    0,  315,    0,  315,    0,    0,    0,  315,  315,  315,
  315,  315,  315,  315,  315,  315,    0,  315,    0,    0,
    0,    0,    0,    0,  336,    0,    0,    0,    0,  335,
    0,  335,    0,  315,  315,  315,  315,  315,  335,    0,
  335,    0,  335,  335,  319,    0,  335,    0,  335,    0,
    0,    0,  335,  335,  335,  335,  335,  335,  335,  335,
  335,    0,  335,    0,    0,    0,    0,    0,    0,  319,
    0,    0,    0,    0,    0,    0,    0,    0,  335,  335,
  335,  335,  335,  332,    0,  332,    0,    0,    0,    0,
    0,    0,  332,    0,  332,    0,  332,  332,  315,    0,
  332,    0,  332,    0,    0,    0,  332,  332,  332,  332,
  332,  332,  332,  332,  332,    0,  332,    0,    0,    0,
    0,    0,    0,  315,    0,    0,    0,    0,  333,    0,
  333,    0,  332,  332,  332,  332,  332,  333,    0,  333,
    0,  333,  333,  335,    0,  333,    0,  333,    0,    0,
    0,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    0,  333,    0,    0,    0,    0,    0,    0,  335,    0,
    0,    0,    0,    0,    0,    0,    0,  333,  333,  333,
  333,  333,  328,    0,  328,    0,    0,    0,    0,    0,
    0,  328,    0,  328,    0,  328,  328,  332,    0,  328,
    0,  328,    0,    0,    0,  328,  328,  328,  328,  328,
  328,  328,  328,  328,    0,  328,    0,    0,    0,    0,
    0,    0,  332,    0,    0,    0,    0,  329,    0,  329,
    0,  328,  328,  328,  328,  328,  329,    0,  329,    0,
  329,  329,  333,    0,  329,    0,  329,    0,    0,    0,
  329,  329,  329,  329,  329,  329,  329,  329,  329,    0,
  329,    0,    0,    0,    0,    0,    0,  333,    0,    0,
    0,    0,    0,    0,    0,    0,  329,  329,  329,  329,
  329,  331,    0,  331,    0,    0,    0,    0,    0,    0,
  331,    0,  331,    0,  331,  331,  328,    0,  331,    0,
  331,    0,    0,    0,  331,  331,  331,  331,  331,  331,
  331,  331,  331,    0,  331,    0,    0,    0,    0,    0,
    0,  328,    0,    0,    0,    0,  330,    0,  330,    0,
  331,  331,  331,  331,  331,  330,    0,  330,    0,  330,
  330,  329,    0,  330,    0,  330,    0,    0,    0,  330,
  330,  330,  330,  330,  330,  330,  330,  330,    0,  330,
    0,    0,    0,    0,    0,    0,  329,    0,    0,    0,
    0,    0,    0,    0,    0,  330,  330,  330,  330,  330,
  334,    0,  334,    0,    0,    0,    0,    0,    0,  334,
    0,  334,    0,  334,  334,  331,    0,  334,    0,  334,
    0,    0,    0,  334,  334,  334,  334,  334,  334,  334,
  334,  334,    0,  334,    0,    0,    0,    0,    0,    0,
  331,    0,    0,    0,    0,  320,    0,  320,    0,  334,
  334,  334,  334,  334,  320,    0,  320,    0,  320,  320,
  330,    0,  320,    0,  320,    0,    0,    0,  320,  320,
  320,  320,  320,  320,  320,  320,  320,    0,  320,    0,
    0,    0,    0,    0,    0,  330,    0,    0,    0,    0,
    0,    0,    0,    0,  320,  320,  320,  320,  320,  327,
    0,  327,    0,    0,    0,    0,    0,    0,  327,    0,
  327,    0,  327,  327,  334,    0,  327,    0,  327,    0,
    0,    0,  327,  327,  327,  327,  327,  327,  327,  327,
  327,    0,  327,    0,    0,    0,    0,    0,    0,  334,
    0,    0,    0,    0,  317,    0,  317,    0,  327,  327,
  327,  327,  327,  317,    0,  317,    0,  317,  317,  320,
    0,  317,    0,  317,    0,    0,    0,  317,  317,  317,
  317,  317,  317,  317,  317,  317,    0,  317,    0,    0,
    0,    0,    0,    0,  320,    0,    0,    0,    0,    0,
    0,    0,    0,  317,  317,  317,  317,  317,  316,    0,
  316,    0,    0,    0,    0,    0,    0,  316,    0,  316,
    0,  316,  316,  327,    0,  316,    0,  316,    0,    0,
    0,  316,  316,  316,  316,  316,  316,  316,  316,  316,
    0,  316,    0,    0,    0,    0,    0,    0,  327,    0,
    0,    0,    0,  318,    0,  318,    0,  316,  316,  316,
  316,  316,  318,    0,  318,    0,  318,  318,  317,    0,
  318,    0,  318,    0,    0,    0,  318,  318,  318,  318,
  318,  318,  318,  318,  318,    0,  318,    0,    0,    0,
  321,    0,    0,  317,    0,    0,    0,    0,    0,    0,
    0,    0,  318,  318,  318,  318,  318,  321,    0,  321,
    0,    0,    0,  321,  321,  321,  321,  321,    0,  321,
  321,    0,  316,    0,    0,    0,    0,  321,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  321,
  321,  321,  321,  321,  321,  321,  321,  316,    0,    0,
  321,  321,  321,  321,  321,    0,  321,  321,    0,    0,
  321,    0,  321,    0,  321,    0,    0,  318,  321,  321,
  321,  321,  321,    0,  321,  321,  321,  321,  321,  321,
  321,    0,  321,    0,    0,    0,    0,    0,    0,    0,
    0,  302,  318,  302,  321,  321,  321,  321,  321,  321,
    0,  321,    0,    0,  400,  321,  321,  321,  321,  321,
    0,  321,  321,    0,  302,  302,  302,  302,  302,  302,
  302,  302,  302,    0,  302,    0,    0,    0,    0,  321,
  329,  321,  321,  321,  321,  321,    0,  273,    0,  274,
  302,  275,  276,    0,    0,  277,    0,  278,    0,    0,
    0,  279,  280,  281,  282,  283,    0,  284,  285,  321,
    0,    0,    0,    0,    0,    0,  321,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  448,  286,  287,  288,
  289,  290,    0,  273,  321,  274,    0,  275,  276,    0,
    0,  277,    0,  278,    0,    0,    0,  279,  280,  281,
  282,  283,    0,  284,  285,  302,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  321,  458,  286,  287,  288,  289,  290,    0,  273,
    0,  274,    0,  275,  276,    0,    0,  277,    0,  278,
    0,    0,    0,  279,  280,  281,  282,  283,    0,  284,
  285,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  291,  508,  286,
  287,  288,  289,  290,    0,  273,    0,  274,    0,  275,
  276,    0,    0,  277,    0,  278,    0,    0,    0,  279,
  280,  281,  282,  283,    0,  284,  285,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  291,  676,  286,  287,  288,  289,  290,
    0,  273,    0,  274,    0,  275,  276,    0,    0,  277,
    0,  278,    0,    0,    0,  279,  280,  281,  282,  283,
    0,  284,  285,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  291,
  696,  286,  287,  288,  289,  290,    0,  273,    0,  274,
    0,  275,  276,    0,  321,  277,    0,  278,    0,    0,
    0,  279,  280,  281,  282,  283,    0,  284,  285,  321,
    0,  321,    0,    0,    0,  321,  321,  321,  321,  321,
    0,  321,  321,    0,    0,  291,    0,  286,  287,  288,
  289,  290,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  321,  321,  321,  321,  321,  294,    0,  294,    0,
  294,  294,    0,    0,  294,    0,  294,    0,    0,    0,
  294,  294,  294,  294,  294,  294,  294,  294,  294,    0,
    0,  291,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  294,  294,  294,  294,
  294,    0,  290,    0,  290,    0,  290,  290,    0,    0,
  290,    0,  290,    0,    0,    0,  290,  290,  290,  290,
  290,  290,  290,  290,  290,    0,    0,  291,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  321,  290,  290,  290,  290,  290,  295,    0,  295,
    0,  295,  295,    0,    0,  295,    0,  295,    0,    0,
    0,  295,  295,  295,  295,  295,  295,  295,  295,  295,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  294,  295,  295,  295,
  295,  295,    0,  292,    0,  292,    0,  292,  292,    0,
    0,  292,    0,  292,    0,    0,    0,  292,  292,  292,
  292,  292,  292,  292,  292,  292,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  290,  292,  292,  292,  292,  292,  291,    0,
  291,    0,  291,  291,    0,    0,  291,    0,  291,    0,
    0,    0,  291,  291,  291,  291,  291,  291,  291,  291,
  291,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  295,  291,  291,
  291,  291,  291,    0,  293,    0,  293,    0,  293,  293,
    0,    0,  293,    0,  293,    0,    0,    0,  293,  293,
  293,  293,  293,  293,  293,  293,  293,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  292,  293,  293,  293,  293,  293,  273,
    0,  274,    0,  275,  276,    0,    0,  277,    0,  278,
    0,    0,    0,  279,  280,  281,  282,  283,  456,  284,
  285,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  291,  286,
  287,  288,  289,  290,    0,  273,    0,  274,    0,  275,
  276,    0,    0,  277,    0,  278,    0,    0,    0,  279,
  280,  281,  282,  283,    0,  284,  285,  644,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  293,  286,  287,  288,  289,  290,
  273,    0,  274,    0,  275,  276,    0,    0,  277,    0,
  278,    0,    0,    0,  279,  280,  281,  282,  283,  674,
  284,  285,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  291,
  286,  287,  288,  289,  290,    0,  617,    0,  618,    0,
  619,  620,    0,    0,  621,    0,  622,    0,    0,    0,
  623,  624,  625,  626,  627,  687,  628,  629,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  291,  630,  631,  632,  633,
  634,  273,    0,  274,    0,  275,  276,    0,    0,  277,
    0,  278,    0,    0,    0,  279,  280,  281,  282,  283,
    0,  284,  285,  698,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  291,  286,  287,  288,  289,  290,    0,  617,    0,  618,
    0,  619,  620,    0,    0,  621,    0,  622,    0,    0,
    0,  623,  624,  625,  626,  627,    0,  628,  629,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  635,  630,  631,  632,
  633,  634,  273,    0,  274,    0,  275,  276,    0,    0,
  277,    0,  278,    0,    0,    0,  279,  280,  281,  282,
  283,    0,  284,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  291,  286,  287,  288,  289,  290,    0,  617,    0,
  618,    0,  619,  620,    0,    0,  621,    0,  622,    0,
    0,    0,  623,  624,  625,  626,  627,  321,  628,  321,
    0,    0,    0,  321,  321,  321,  321,  321,    0,  321,
  321,    0,    0,  321,    0,    0,    0,  635,  630,  631,
  632,  633,  634,    0,    0,    0,    0,    0,    0,  321,
  321,  321,  321,  321,  321,    0,  321,    0,    0,    0,
  321,  321,  321,  321,  321,  321,  321,  321,  321,    0,
  321,    0,    0,    0,  321,  321,  321,  321,  321,    0,
  321,  321,  291,    0,    0,    0,  321,  321,  321,  321,
  321,    0,    0,    0,    0,    0,  299,    0,  299,    0,
  321,  321,  321,  321,  321,  299,    0,  299,    0,  299,
  299,    0,    0,  299,    0,  299,    0,    0,    0,  299,
  299,  299,  299,  299,  299,  299,  299,  299,  635,  299,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  321,
    0,    0,  305,    0,  305,  299,  299,  299,  299,  299,
    0,  305,    0,  305,    0,  305,  305,    0,    0,  305,
    0,  305,    0,    0,    0,  305,  305,  305,  305,  305,
  305,  305,  305,  305,    0,  305,  321,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  321,  305,  305,  305,  305,  305,    0,    0,  297,    0,
  297,    0,    0,    0,    0,    0,    0,    0,    0,  297,
  299,  297,  297,    0,    0,  297,    0,  297,    0,    0,
    0,  297,  297,  297,  297,  297,  297,  297,  297,  297,
    0,  297,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  298,    0,  298,    0,    0,    0,  297,  297,  297,
    0,  297,  298,    0,  298,  298,  305,    0,  298,    0,
  298,    0,    0,    0,  298,  298,  298,  298,  298,  298,
  298,  298,  298,    0,  298,    0,  303,    0,  303,    0,
    0,    0,    0,    0,    0,    0,    0,  303,    0,    0,
  298,  298,  298,  303,  298,  303,    0,    0,    0,  303,
  303,  303,  303,  303,  303,  303,  303,  303,    0,  303,
    0,  307,  297,  307,    0,    0,    0,    0,    0,    0,
    0,    0,  307,    0,    0,  303,  303,  303,  307,  303,
  307,    0,    0,    0,  307,  307,  307,  307,  307,  307,
  307,  307,  307,    0,  307,    0,  308,    0,  308,    0,
    0,    0,    0,    0,    0,  298,    0,  308,    0,    0,
  307,  307,  307,  308,    0,  308,    0,    0,    0,  308,
  308,  308,  308,  308,  308,  308,  308,  308,    0,  308,
    0,  306,    0,  306,    0,    0,    0,    0,    0,    0,
  303,    0,  306,    0,    0,  308,  308,  308,  306,    0,
  306,    0,    0,    0,  306,  306,  306,  306,  306,  306,
  306,  306,  306,  304,  306,  304,    0,    0,    0,    0,
    0,    0,    0,    0,  304,  307,    0,    0,    0,    0,
  306,  306,  306,    0,    0,    0,  304,  304,  304,  304,
  304,  304,  304,  304,  304,    0,  304,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  308,    0,  304,    0,  304,  654,  655,  656,  657,  658,
  659,  660,  661,  662,  663,  664,  665,  666,  667,  668,
  669,  670,  671,  672,    0,    0,    0,    0,  274,    0,
  274,    0,  274,  274,    0,  306,  274,    0,  274,    0,
    0,    0,  274,  274,  274,  274,  274,  274,  274,  274,
  274,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  304,  274,  274,
  274,  274,  274,    0,  280,  697,  280,    0,  280,  280,
    0,    0,  280,    0,  280,    0,    0,    0,  280,  280,
  280,  280,  280,  280,  280,  280,  280,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  280,  280,  280,  280,  280,  272,
    0,  272,  272,    0,    0,  272,    0,  272,    0,    0,
    0,  272,  272,  272,  272,  272,  272,  272,  272,  272,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  272,  272,  272,
  273,  272,  273,  273,    0,    0,  273,    0,  273,    0,
    0,    0,  273,  273,  273,  273,  273,  273,  273,  273,
  273,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  278,    0,    0,  273,  273,
  273,  278,  273,  278,    0,    0,    0,  278,  278,  278,
  278,  278,  278,  278,  278,  278,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  283,    0,    0,  278,  278,  278,  283,  278,  283,    0,
    0,    0,  283,  283,  283,  283,  283,  283,  283,  283,
  283,    0,    0,    0,    0,    0,    0,    0,    0,  282,
    0,    0,    0,    0,    0,  282,    0,  282,  283,  283,
  283,  282,  282,  282,  282,  282,  282,  282,  282,  282,
    0,    0,    0,    0,    0,    0,    0,    0,  281,    0,
    0,    0,    0,    0,  281,    0,  281,  282,  282,  282,
  281,  281,  281,  281,  281,  281,  281,  281,  281,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  281,  281,  281,
};
static const YYINT yycheck[] = {                        115,
    0,  131,  231,    3,    4,    0,  308,  309,  115,    3,
  336,  115,  338,   30,  154,   15,  156,  119,  154,   40,
  490,    0,   30,  193,  268,   41,   50,   24,   52,   29,
   30,   50,   38,   74,  123,   54,   55,   39,   71,   29,
   30,  424,   40,   43,   97,   51,   24,   40,   40,    0,
   29,   30,   50,   43,   52,   71,   41,   50,   41,   52,
  230,   41,   42,  184,   43,   41,   46,   74,   97,   47,
   99,   41,    0,   97,   93,   94,   41,   83,   29,   30,
  550,   45,   82,   80,  214,   24,   97,   89,   71,   81,
   24,   91,   43,   45,   24,   50,  102,  567,   74,   99,
   50,   71,   80,   82,   24,   69,   71,   24,  410,   69,
  412,   71,   72,   47,   41,  115,  586,   47,  103,   97,
  115,  121,  155,  253,  124,   47,  123,   47,  268,  114,
  130,   97,  268,   60,  134,  265,  115,   41,   93,  155,
  610,   80,  525,   93,   71,  315,   80,   60,   24,  173,
   80,   58,   50,  138,  154,  155,   54,   55,   71,  176,
   80,  180,  292,   80,  115,   47,   70,   71,  176,  148,
  300,   47,  155,  294,  295,  173,  176,  183,  185,  485,
  173,  487,  160,   60,  123,  209,   73,  115,  188,  189,
  196,  191,  494,  121,   71,   93,  124,  176,  176,  199,
  178,  218,  202,  123,   80,  222,  134,  451,  210,  199,
  218,  209,  441,  219,  222,  256,  209,    3,  218,  321,
  199,   81,  222,   24,  694,  180,  154,  229,  218,   15,
  180,  209,    0,  250,  234,  365,    4,  339,  160,  218,
  160,  123,  250,  222,  234,   24,   47,  123,  199,  173,
  250,  155,  554,  253,  178,  234,  178,   41,  178,  179,
  188,   29,   30,   12,   24,  509,   71,  218,  268,   74,
    0,  250,  393,   22,  202,   43,  397,  398,  160,   80,
  401,   73,  180,  234,  160,  270,  178,  209,  305,  209,
  269,   40,   69,  272,  294,  295,  178,  305,  298,   29,
   30,   80,  178,  303,  298,  305,   36,    9,  308,  309,
   42,  451,   24,   43,   82,  451,  316,   60,    9,  103,
   80,   23,  123,   91,   41,  253,  305,  209,   71,   42,
  114,   99,   23,  209,   50,   47,  336,   43,   54,   55,
  268,  341,   42,  294,  295,   41,   46,  115,   47,   99,
   60,   69,  337,  121,  138,   73,  124,  336,   40,  338,
   42,   71,  130,  123,   46,  365,  134,   71,   80,  509,
   74,  101,   58,  509,   97,  701,  581,   93,  357,   82,
  130,  366,   40,  113,  369,  115,  154,  155,  316,  395,
   60,  391,   50,   40,   52,  497,   71,  391,  528,   74,
  417,   71,  607,   50,   45,   52,  522,  137,  176,  417,
  410,  123,  412,  341,  414,  522,  416,  417,  522,   41,
  188,  189,   80,  191,  123,  555,   71,  406,  407,   74,
   40,  199,   69,   80,  202,   43,   73,  365,  417,   97,
   50,  191,   52,   40,   80,  148,  176,  432,   80,   43,
  218,  451,  437,   50,  222,   52,   60,  442,  443,  444,
  567,  160,  462,   40,  180,  465,  234,   71,  462,  199,
   40,  465,  677,  176,   69,   40,   41,   42,   73,  178,
  179,   46,  250,   80,   41,  253,  270,   97,  218,  489,
   73,  123,  222,  493,  494,   69,   40,   41,   42,  493,
  268,  486,   46,   60,  234,  522,  485,  507,  487,  509,
  209,  511,  298,   72,   71,  173,   13,  511,  269,  222,
   42,  272,  522,  451,   46,   72,  173,  522,  160,  124,
  125,  516,   72,  518,   71,  303,  521,  305,   60,  269,
  308,  309,  272,  522,   71,   72,  178,  250,  316,   71,
  336,  209,  552,  337,  554,  123,   41,   24,  552,  123,
   41,  489,  209,  173,   70,   71,  269,  567,   74,  272,
   41,  522,  567,  341,  358,   24,  173,  209,   72,  507,
   47,  509,  366,   40,   13,  369,   71,   72,   85,   74,
  320,   40,  160,   50,  522,   52,  160,  365,   47,  209,
   97,   50,  305,   52,  173,  391,  336,   23,  338,   71,
  178,   40,  209,   80,  178,  179,   41,   42,   50,  349,
   69,   46,   54,   55,  408,   72,  123,   69,  124,  125,
  416,   80,   40,  336,   42,  338,   85,   74,   46,  567,
   97,  209,  410,   41,  412,  209,  414,   91,  432,  417,
  124,  125,   41,  437,  357,   99,   85,   41,  155,  156,
  104,   93,   94,  160,   69,  449,   71,   72,   97,   40,
  155,   42,   41,  117,  123,   46,  462,   71,   72,  465,
   70,  178,  179,  451,  701,  182,  130,  417,   41,  473,
  474,   41,   42,  701,  123,  695,   46,   71,   72,   70,
  180,  701,  486,  406,  407,   41,   42,  493,  123,   41,
   46,  160,  209,   13,  417,  160,  173,   40,   41,   42,
  705,  489,  701,   46,  173,  511,  494,  156,   41,  178,
  127,  160,  516,   24,  518,  406,  407,  521,   40,  507,
   40,  509,   42,   73,  188,  160,   46,  191,  180,  178,
  179,   40,  209,  182,  522,  485,   47,  487,   41,   40,
  209,   42,   47,  178,  179,   46,  552,  695,   40,   73,
   70,   71,   72,   73,   80,   40,   71,   42,   40,   85,
  209,   46,  485,   41,  487,   85,  554,   74,   41,   80,
   43,   97,  522,   72,  209,   41,   40,   97,   42,  567,
   71,   72,   46,  247,   40,   70,   97,   73,   80,   69,
   80,   71,   72,   85,   80,   85,   69,  123,   71,   72,
   13,   74,   69,  123,  124,  125,   70,   97,   72,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   40,  293,
   80,  123,   40,  123,  160,  153,  156,  123,  156,  303,
  160,  159,  160,  161,  162,  163,  164,   69,   41,  160,
   43,   69,  178,  171,  318,  173,    0,    1,  178,  179,
   81,   72,  182,  181,   41,  176,   39,  178,  160,   13,
  160,   12,   85,   98,  160,   40,   69,   41,   71,   72,
   24,   74,  155,  209,   97,  175,  178,  180,  178,  209,
  155,   41,  178,  179,   41,   42,   40,  361,  209,   46,
   72,  705,   73,   47,   73,   41,   50,  695,   52,  113,
  123,   73,  242,  701,  232,  233,  554,  209,  199,  209,
  353,  148,   73,  209,  155,  341,   41,   42,   72,   80,
   74,   46,   24,  683,  357,  295,   80,  415,  155,  257,
  414,   85,  303,  156,  202,   60,  489,  160,   40,  267,
   -1,  701,  115,   97,   -1,   47,   71,   -1,   50,   -1,
   52,   -1,  155,   -1,   -1,  178,  179,   -1,    1,  182,
    3,    4,  123,   -1,    7,    8,    9,   10,  701,  123,
   13,  445,   73,   16,   -1,   -1,   19,   20,   80,   80,
   23,   24,  456,   85,   -1,   28,  209,   30,   -1,   -1,
   33,   34,   40,   41,   42,   97,   39,   40,   46,  160,
   -1,   -1,  156,   46,   47,   -1,  160,   50,   -1,   52,
   -1,   54,   55,   -1,   -1,   41,   42,  178,  179,  173,
   46,  123,  123,   -1,  178,  179,   -1,   13,  182,   72,
   73,  185,   -1,   -1,   -1,   -1,   80,   80,   81,   82,
   83,   84,   85,   86,   70,   71,   -1,   -1,  209,   -1,
   -1,   -1,   95,   97,   97,  209,   99,  100,  160,  160,
   -1,   41,   -1,   43,   50,   -1,   52,   -1,   50,   -1,
   52,  173,   -1,   -1,   -1,   13,  178,  178,  179,  123,
  123,    9,   -1,   -1,   -1,   13,   -1,   -1,   80,   69,
   70,   71,   72,   85,   74,   23,   24,   -1,   -1,   85,
   -1,   -1,   30,   85,   -1,  579,   34,  209,  209,   -1,
   90,   97,   40,  156,   -1,   97,  160,  160,   46,   47,
  448,   -1,   50,  597,   52,  599,   54,   55,   -1,  155,
  604,  123,   -1,   -1,  178,  178,  179,  123,   -1,  182,
   -1,  123,  185,   -1,   40,   73,   42,   85,   44,   45,
   -1,   -1,   80,   81,   82,   83,   84,   85,   86,   97,
   69,   70,   71,   72,   -1,  209,  209,   95,  160,   97,
  156,   99,   -1,   -1,  160,  155,   -1,  651,  160,   -1,
  508,   90,   -1,  175,   -1,  123,  178,  173,    9,   -1,
   -1,  173,  178,  179,   -1,  123,  178,   -1,   -1,   95,
   -1,   -1,   23,   24,  678,   40,   41,   42,   -1,   30,
   -1,   46,   -1,   34,   -1,   -1,   -1,  209,  156,   40,
   41,   -1,  160,  209,  698,   46,   47,  209,  156,   50,
   -1,   52,  160,   54,   55,   -1,   40,   41,   42,  567,
  178,  179,   46,   -1,  182,   -1,  574,   -1,   -1,   -1,
  178,  179,   73,   -1,  182,   -1,   -1,  585,   -1,   80,
   81,   82,   83,   84,   85,   86,   -1,   -1,   -1,   -1,
   13,  209,   -1,   -1,   95,   -1,   -1,   -1,   99,   -1,
   -1,  209,   -1,   -1,   -1,   -1,  614,   -1,   -1,  617,
  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,
  628,  629,  630,  631,  632,  633,  634,  635,   -1,   -1,
   -1,   -1,    1,   -1,    3,    4,   -1,   -1,    7,    8,
    9,   10,   -1,   12,   13,   -1,   -1,   16,   -1,   -1,
   19,   20,   -1,   -1,   23,   24,   -1,   -1,   -1,   28,
   -1,   30,   85,   80,   33,   34,   -1,   -1,  676,   -1,
   39,   40,  173,   -1,   97,   -1,   -1,   46,   47,  687,
   97,   50,   -1,   52,   -1,   54,   55,   -1,  696,   58,
   13,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
  123,   70,   71,   72,   73,   74,  123,   -1,  209,   -1,
   -1,   80,   81,   82,   83,   84,   85,   86,   41,   -1,
   -1,   90,   91,   92,   93,   94,   95,   -1,   97,   -1,
   99,  100,   -1,  156,   50,   -1,   52,  160,   54,   55,
   -1,   -1,   58,  160,   60,   -1,   69,   70,   71,   72,
   73,   -1,   -1,   -1,  123,  178,  179,   -1,   -1,  182,
   -1,  178,   85,   -1,   -1,   -1,   41,   -1,   43,   -1,
   -1,   -1,   -1,   -1,   97,   91,   92,   93,   94,   -1,
   -1,   -1,   -1,   -1,   -1,   50,  209,  156,   -1,   54,
   55,  160,  209,   58,   69,   60,   71,   72,   -1,   74,
  123,  124,  125,   -1,   -1,   -1,   -1,   -1,   -1,  178,
  179,  180,    1,  182,    3,    4,  185,   -1,    7,    8,
    9,   10,   -1,   -1,   13,   -1,   91,   16,   93,   94,
   19,   20,   -1,  156,   23,   24,   -1,  160,   -1,   28,
  209,   30,   -1,   -1,   33,   34,   -1,   -1,   -1,   -1,
   39,   40,   -1,   -1,   -1,  178,  179,   46,   47,  182,
   -1,   50,   -1,   52,  180,   54,   55,   -1,   -1,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
  155,   70,   71,   72,   73,   74,  209,   -1,   -1,   -1,
   -1,   80,   81,   82,   83,   84,   85,   86,   -1,   -1,
   -1,   90,   91,   92,   93,   94,   95,   -1,   97,   -1,
   99,  100,   -1,   -1,   -1,  180,   66,   67,   68,   69,
   70,   71,   72,    1,   -1,    3,    4,   -1,   -1,    7,
    8,    9,   10,   -1,  123,   13,   -1,   -1,   16,   50,
   90,   19,   20,   54,   55,   23,   24,   58,   -1,   60,
   28,   -1,   30,   -1,   -1,   33,   34,   -1,   -1,   -1,
   -1,   39,   40,   -1,   -1,   -1,   -1,  156,   46,   47,
   -1,  160,   50,   -1,   52,   -1,   54,   55,   -1,   -1,
   91,   92,   93,   94,   -1,   -1,   -1,   -1,   -1,  178,
  179,  180,   -1,  182,   72,   73,  185,   -1,   -1,   -1,
   -1,   -1,   80,   81,   82,   83,   84,   85,   86,   -1,
   -1,   -1,   -1,   52,   -1,   -1,   -1,   95,   -1,   97,
  209,   99,  100,   -1,   -1,   64,   65,   66,   67,   68,
   69,   70,   71,   72,    1,   -1,    3,    4,   -1,   -1,
    7,    8,    9,   10,   -1,  123,   13,   -1,   -1,   16,
   50,   90,   19,   20,   54,   55,   23,   24,   58,   -1,
   60,   28,   -1,   30,   -1,   -1,   33,   34,   -1,  180,
   -1,   -1,   39,   40,   -1,   -1,   -1,   -1,  156,   46,
   47,   -1,  160,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,   91,   92,   93,   94,   -1,   -1,   -1,   -1,   -1,
  178,  179,   -1,   -1,  182,   72,   73,   80,   -1,   -1,
   -1,   -1,   85,   80,   81,   82,   83,   84,   85,   86,
   -1,   50,   -1,   52,   -1,   54,   55,   -1,   95,   58,
   97,  209,   99,  100,   -1,   64,   65,   66,   67,   68,
   -1,   70,   -1,   -1,   -1,    9,   -1,   -1,   -1,   13,
  123,   -1,   -1,   -1,   -1,   -1,  123,   40,   -1,   23,
   24,   90,   91,   92,   93,   94,   30,   50,   -1,   52,
   34,   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,   -1,
  180,   -1,   46,   47,   -1,   -1,   50,  160,   52,  156,
   54,   55,   -1,  160,   58,   -1,   60,   80,   -1,   -1,
   64,   65,   66,   67,   68,  178,   70,   71,   -1,   73,
   -1,  178,  179,   -1,   97,  182,   80,   81,   82,   83,
   84,   85,   86,    9,   -1,   -1,   90,   91,   92,   93,
   94,   95,   80,   97,   -1,   99,  209,   23,   -1,   -1,
  123,   -1,  209,   -1,   -1,   -1,   -1,   -1,   -1,   97,
   -1,  180,   -1,   -1,   40,   -1,   42,   -1,   44,  123,
   46,   47,   -1,   -1,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   58,   -1,   60,  123,   -1,  160,   64,   65,
   66,   67,   -1,   -1,   70,   71,   -1,   -1,   -1,   -1,
  173,  155,  156,   -1,   -1,  178,  160,   13,   -1,   85,
   -1,   -1,   -1,   -1,   90,   91,   92,   93,   94,   95,
   -1,   97,  160,    9,  178,  179,  180,   13,  182,   67,
   68,   69,   70,   71,   72,   -1,  209,   23,   24,   -1,
  178,   -1,   -1,   -1,   30,   -1,   -1,  123,   34,   -1,
   -1,   -1,   90,   -1,   40,  209,   -1,   -1,   -1,   24,
   46,   47,   -1,   69,   50,   -1,   52,   73,   54,   55,
   -1,  209,   -1,   -1,   -1,   40,   -1,   -1,   -1,   85,
   -1,   -1,   47,   -1,  160,   50,   -1,   52,   -1,   -1,
   -1,   97,   -1,   -1,   80,   81,   82,   83,   84,   85,
   86,   -1,  178,   -1,  180,   -1,   -1,   -1,   -1,   95,
   -1,   97,   -1,   99,    9,   80,   -1,  123,  124,  125,
   85,   -1,   50,   -1,   52,   -1,   54,   55,   23,   24,
   58,   -1,   60,  209,   -1,   30,   64,  123,   50,   34,
   52,   -1,   54,   55,   -1,   40,   58,   -1,   60,   -1,
  156,   46,   47,   -1,  160,   50,   -1,   52,  123,   54,
   55,   -1,   -1,   91,   92,   93,   94,   -1,   -1,   -1,
  156,   -1,  178,  179,  160,   -1,  182,   -1,   73,   91,
   92,   93,   94,   -1,    9,   80,   81,   82,   83,   84,
   85,   86,  178,  179,   -1,  160,  182,   80,   23,   24,
   95,   -1,   97,  209,   99,   30,   -1,   -1,  173,   34,
   -1,   -1,   -1,  178,   97,   40,   -1,   -1,   -1,   -1,
   -1,   46,   47,  209,   -1,   50,   -1,   52,  123,   54,
   55,   -1,   -1,   -1,   -1,   -1,   -1,   50,   -1,   -1,
  123,   54,   55,   -1,  209,   58,   -1,   60,    9,   -1,
   -1,   -1,  180,   -1,   -1,   80,   81,   82,   83,   84,
   85,   86,   23,   24,   -1,  160,   -1,   -1,  180,   30,
   95,   -1,   97,   34,   99,   -1,   -1,  160,   91,   40,
   93,   94,   -1,  178,   -1,   46,   47,   -1,   -1,   50,
   -1,   52,   -1,   54,   55,  178,   -1,   -1,  123,   -1,
   -1,   -1,   50,   13,   52,   -1,   54,   55,   -1,   -1,
   58,   -1,   60,   -1,  209,   -1,   64,   65,   66,   80,
   81,   82,   83,   84,   85,   86,  209,   -1,   -1,   -1,
   40,   -1,   -1,   -1,   95,  160,   97,   -1,   99,   -1,
   50,   -1,   52,   91,   92,   93,   94,   -1,   -1,   13,
   60,   -1,   -1,  178,   -1,   -1,   -1,   -1,   -1,   69,
   24,   71,  123,   73,   -1,   -1,   -1,  180,   -1,   -1,
   80,   -1,   80,   -1,   -1,   85,   40,   41,   42,   43,
   44,   45,   46,   47,  209,   -1,   50,   97,   52,   97,
   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,  160,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,
   74,   -1,   -1,  123,   -1,  123,   80,  178,   -1,   -1,
   -1,   85,   -1,   -1,   -1,   -1,   90,   91,   92,   93,
   94,   95,  180,   -1,   -1,   -1,   -1,   -1,   -1,   50,
   -1,   52,   -1,   54,   55,   -1,  156,   58,  209,   60,
  160,   -1,  160,   64,   65,   66,   67,   68,   -1,  123,
  124,  125,   -1,  173,   -1,   -1,   -1,   -1,  178,  179,
  178,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   91,   92,   93,   94,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  155,  156,   -1,   -1,   13,  160,   90,   -1,  209,
   -1,  209,   -1,   -1,   -1,   -1,   24,   -1,   -1,  173,
   -1,   -1,   -1,   -1,  178,  179,  180,   -1,  182,   -1,
   -1,   -1,   40,   41,   42,   43,   44,   45,   46,   47,
   -1,   -1,   50,   -1,   52,   -1,   54,   55,   13,   -1,
   58,   -1,   60,   -1,   -1,  209,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   73,   74,   -1,   -1,   -1,
   -1,   -1,   80,   -1,   -1,   -1,   41,   85,   -1,  180,
   -1,   52,   90,   91,   92,   93,   94,   95,   -1,   -1,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   -1,   69,   70,   71,   72,   73,   -1,
   -1,   -1,   -1,   -1,   -1,  123,  124,  125,   -1,   90,
   85,   92,   -1,   -1,   -1,   50,   -1,   52,   -1,   54,
   55,   -1,   97,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   -1,   -1,   -1,  155,  156,   -1,
   -1,   13,  160,   -1,   -1,   -1,   -1,   -1,  123,  124,
  125,   -1,   24,   -1,   -1,  173,   91,   92,   93,   94,
  178,  179,  180,   -1,  182,   -1,   -1,   -1,   40,   41,
   42,   43,   44,   45,   46,   47,   -1,   -1,   50,   -1,
   52,  156,   54,   55,   -1,  160,   58,   -1,   60,   -1,
   -1,  209,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   73,   74,  178,  179,   -1,   -1,  182,   80,   -1,
   -1,   -1,   -1,   85,   -1,   -1,   -1,   -1,   90,   91,
   92,   93,   94,   95,   -1,   65,   66,   67,   68,   69,
   70,   71,   72,   50,  209,   52,   -1,   54,   55,   13,
   -1,   58,   -1,   60,   -1,  180,   -1,   64,   65,   66,
   90,  123,  124,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,   42,   -1,
   -1,   -1,   46,   -1,   91,   92,   93,   94,   -1,   -1,
   -1,   -1,   -1,  155,  156,   -1,   -1,   13,  160,   -1,
   -1,   -1,   -1,   -1,   -1,   69,   70,   -1,   24,   73,
   -1,  173,   -1,   -1,   -1,   -1,  178,  179,  180,   -1,
  182,   85,   -1,   -1,   40,   41,   42,   43,   44,   45,
   46,   47,   -1,   97,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   -1,   -1,   60,   -1,   -1,  209,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   73,   74,  123,
  124,  125,   -1,   -1,   80,   -1,   -1,   -1,   -1,   85,
   -1,   -1,   -1,  180,   90,   91,   92,   93,   94,   95,
   -1,   97,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  156,   -1,   -1,   -1,  160,   -1,   -1,   -1,
   41,   -1,   43,   -1,   -1,   -1,   -1,  123,  124,  125,
   -1,   -1,   -1,   -1,  178,  179,   -1,   58,  182,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,  155,
  156,   -1,   -1,   13,  160,  209,   -1,   -1,   -1,   90,
   91,   92,   93,   94,   24,   -1,   -1,  173,   -1,   -1,
   -1,   -1,  178,  179,  180,   -1,  182,   -1,   -1,   -1,
   40,   41,   42,   43,   44,   45,   46,   47,   -1,   -1,
   50,   -1,   52,   -1,   54,   55,   13,   -1,   58,   -1,
   60,   -1,   -1,  209,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   73,   74,   -1,   -1,   -1,   -1,   -1,
   80,   -1,   -1,   -1,  155,   85,   -1,   -1,   -1,   -1,
   90,   91,   92,   93,   94,   95,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,
   -1,   -1,   69,   -1,   71,   72,   73,   -1,   -1,   -1,
   41,   -1,   43,  123,  124,  125,   -1,   -1,   85,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
   97,   70,   71,   72,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   74,   -1,  155,  156,   -1,   -1,   13,
  160,   90,   91,   92,   93,   94,  123,  124,  125,   90,
   24,   -1,   -1,  173,   -1,   -1,   -1,   -1,  178,  179,
  180,   -1,  182,   -1,   -1,   -1,   40,   41,   42,   43,
   44,   45,   46,   47,   -1,   -1,   50,   -1,   52,  156,
   54,   55,   -1,  160,   58,   -1,   60,   -1,   -1,  209,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   -1,
   74,  178,  179,   -1,   -1,  182,   80,   -1,   -1,   -1,
   -1,   85,   -1,   13,  155,   -1,   90,   91,   92,   93,
   94,   95,   -1,   97,   24,   -1,   -1,   -1,   -1,   -1,
   -1,  180,  209,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   40,   41,   42,   43,   44,   45,   46,   47,   -1,  123,
   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   -1,
   70,   71,   72,   73,   74,   -1,   -1,   -1,   -1,   -1,
   80,  155,  156,   -1,   -1,   85,  160,   13,   -1,   -1,
   90,   91,   92,   93,   94,   95,   -1,   97,   24,  173,
   -1,   -1,   -1,   -1,  178,  179,  180,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   40,   41,   42,   43,   44,   45,
   46,   47,   -1,  123,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   -1,   -1,   60,  209,   -1,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   73,   74,   -1,
   -1,   -1,   -1,   -1,   80,  155,  156,   -1,   -1,   85,
  160,   13,   -1,   -1,   90,   91,   92,   93,   94,   95,
   -1,   97,   24,  173,   -1,   -1,   -1,   -1,  178,  179,
  180,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,
   42,   43,   44,   45,   46,   47,   -1,  123,   50,   -1,
   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,  209,
   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,   71,
   72,   73,   74,   -1,   -1,   -1,   -1,   -1,   80,  155,
  156,   -1,   -1,   85,  160,   13,   -1,   -1,   90,   91,
   92,   93,   94,   95,   -1,   97,   24,  173,   -1,   -1,
   -1,   -1,  178,  179,  180,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   41,   42,   43,   44,   45,   46,   47,
   -1,  123,   50,   -1,   52,   -1,   54,   55,   -1,   -1,
   58,   -1,   60,  209,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,   -1,
   -1,   -1,   80,  155,  156,   -1,   -1,   85,  160,   13,
   -1,   -1,   90,   91,   92,   93,   94,   95,   -1,   97,
   -1,  173,   -1,   -1,   -1,   -1,  178,  179,  180,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   43,
   44,   45,   46,   -1,   -1,  123,   50,   -1,   52,   -1,
   54,   55,   -1,   -1,   58,   -1,   60,  209,   -1,   -1,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,
   74,   -1,   -1,   -1,   -1,   -1,   -1,  155,  156,   -1,
   -1,   85,  160,   -1,   -1,   13,   90,   91,   92,   93,
   94,   95,   -1,   97,   -1,  173,   -1,   -1,   -1,   -1,
  178,  179,  180,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   41,   -1,   43,   44,   45,   46,  123,
  124,  125,   50,   -1,   52,   -1,   54,   55,   -1,   -1,
   58,  209,   60,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   73,   74,   -1,   -1,   -1,
   -1,  155,  156,   -1,   -1,   -1,  160,   85,   -1,   13,
   -1,   -1,   90,   91,   92,   93,   94,   95,   -1,   97,
   -1,   -1,   -1,   -1,  178,  179,  180,   -1,  182,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   42,   -1,
   -1,   -1,   46,   -1,   -1,  123,  124,  125,   -1,   -1,
   -1,   13,   -1,   -1,   -1,  209,   60,   -1,   -1,   -1,
   -1,   -1,   24,   -1,   -1,   69,   70,   71,   72,   73,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  155,  156,   41,
   42,   85,  160,   -1,   46,   47,   -1,   -1,   50,   -1,
   52,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   -1,
  178,  179,  180,   -1,  182,   -1,   -1,   69,   70,   71,
   72,   13,   -1,   -1,   -1,   -1,   -1,   -1,   80,  123,
  124,  125,   -1,   85,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  209,   -1,   -1,   -1,   97,   -1,   -1,   40,   41,
   42,   -1,   -1,   -1,   46,   -1,   -1,   -1,   -1,   -1,
   -1,  155,  156,   13,   -1,   -1,  160,   -1,   -1,   -1,
   -1,  123,   -1,   -1,   24,   -1,   -1,   69,   70,   71,
   72,   73,   -1,   -1,  178,  179,   -1,   -1,  182,   -1,
   40,   -1,   -1,   85,   -1,   -1,   -1,   47,   -1,   -1,
   50,   -1,   52,  155,  156,   97,   -1,   -1,  160,   13,
   -1,   -1,   -1,   -1,   -1,  209,   -1,   -1,   -1,   -1,
   -1,  173,   -1,   -1,   74,   -1,  178,  179,   -1,   -1,
   80,  123,  124,  125,   -1,   85,   -1,   41,   42,   -1,
   -1,   -1,   46,   -1,   -1,   -1,   50,   97,   52,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   60,  209,   -1,   -1,
   -1,   -1,   -1,   -1,  156,   -1,   70,   71,  160,   -1,
   -1,   -1,   41,  123,   43,   -1,   80,   13,   -1,   -1,
   -1,   85,   -1,   52,   -1,   -1,  178,  179,   24,   -1,
  182,   -1,   -1,   97,   -1,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   40,   74,  156,   -1,   -1,   13,
  160,   47,   -1,   -1,   50,   -1,   52,  209,   -1,  123,
   24,   90,   -1,  173,   -1,  175,   -1,   -1,  178,  179,
   -1,   -1,  182,   -1,   -1,  185,   40,   -1,   74,   -1,
   -1,   -1,   -1,   47,   80,   -1,   50,   -1,   52,   85,
   13,  155,  156,   -1,   -1,   -1,  160,   13,   50,  209,
   52,   97,   54,   55,   -1,   -1,   58,   -1,   60,  173,
   74,   -1,   64,   65,  178,  179,   80,   40,   41,   42,
   -1,   85,   -1,   46,   40,   -1,  155,  123,   -1,   -1,
   -1,   -1,   -1,   97,   50,   -1,   52,   -1,   -1,   91,
   92,   93,   94,   -1,   -1,  209,   69,   70,   71,   72,
   73,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,
  156,   -1,   85,   -1,  160,   -1,   13,   -1,   -1,   85,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  173,   -1,  175,
   -1,   97,  178,  179,   -1,   -1,  182,   -1,   -1,  185,
   -1,   -1,  156,   40,   41,   42,  160,   -1,   -1,   46,
  123,  124,  125,   -1,   -1,   -1,   -1,  123,   -1,  173,
   -1,  175,   -1,  209,  178,  179,   -1,   -1,  182,   -1,
   -1,  185,   69,   70,   71,   72,   73,   -1,  180,   -1,
   -1,   13,   -1,  156,   -1,   -1,   -1,  160,   85,   -1,
  156,   -1,   24,   -1,  160,  209,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  178,  179,  173,   40,  182,
   -1,   -1,  178,  179,   -1,   47,   -1,   -1,   50,   -1,
   52,   -1,   -1,   -1,   -1,   -1,  123,  124,  125,   -1,
   -1,   -1,   -1,   13,   -1,   -1,  209,   69,   -1,   -1,
   72,   13,   -1,  209,   24,   -1,   -1,   -1,   80,   -1,
   -1,   -1,   -1,   85,   -1,   -1,   -1,   -1,   -1,  156,
   40,   -1,   -1,  160,   -1,   97,   -1,   47,   40,   -1,
   50,   -1,   52,   -1,   -1,   -1,   -1,   -1,   50,   -1,
   52,  178,  179,   -1,   -1,  182,   -1,   -1,   60,   69,
   -1,  123,   72,   -1,   -1,   13,   -1,   69,   -1,   71,
   80,   73,   -1,   -1,   -1,   85,   24,   -1,   80,   -1,
   -1,   -1,  209,   85,   -1,   -1,   -1,   97,   -1,   -1,
   -1,   -1,   40,   -1,  156,   97,   -1,   -1,  160,   47,
   -1,   -1,   50,   -1,   52,   -1,   -1,   -1,   -1,   -1,
   58,  173,   -1,  123,   -1,   -1,  178,  179,   -1,   -1,
   -1,  123,   -1,   -1,   72,   13,   -1,   -1,   -1,   -1,
   -1,   -1,   80,   -1,   -1,   -1,   24,   85,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  156,  209,   -1,   97,
  160,   -1,   40,   -1,  156,   -1,   -1,   -1,  160,   47,
   -1,   -1,   50,  173,   52,   -1,   -1,   13,  178,  179,
   -1,  173,   -1,   -1,   -1,  123,  178,  179,   24,   -1,
   -1,   -1,   13,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   80,   24,   -1,   -1,  601,   85,   -1,  209,
  605,   47,   -1,  608,   50,   -1,   52,  209,  156,   97,
   -1,   -1,  160,   -1,   -1,   -1,   47,   -1,   -1,   50,
   -1,   52,   -1,   69,   -1,  173,   72,   -1,   -1,   -1,
  178,  179,   -1,  638,   80,  123,  641,   -1,   69,   85,
  645,   72,  647,   -1,   13,  650,   -1,   -1,   -1,   80,
   -1,   97,   -1,   -1,   85,   24,   -1,   -1,   -1,   13,
   -1,  209,   -1,   -1,   -1,   -1,   97,   -1,  156,  674,
   24,   40,  160,   -1,   -1,  680,   -1,  123,   47,   -1,
   -1,   50,   -1,   52,   -1,  173,   -1,   -1,   -1,   -1,
  178,  179,  123,   47,  182,   -1,   50,   -1,   52,   -1,
   69,  706,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  156,   80,   -1,   13,  160,   69,   85,   -1,   72,   -1,
   -1,  209,   -1,   -1,   -1,  156,   80,  173,   97,  160,
   -1,   85,  178,  179,   -1,   -1,   -1,   -1,   -1,   -1,
   40,   -1,  173,   97,   -1,   -1,   -1,  178,  179,   -1,
   50,   -1,   52,   -1,  123,   13,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  209,   -1,   -1,   -1,   -1,   -1,  123,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  209,   -1,
   80,   -1,   40,   -1,   -1,   85,   -1,  156,   -1,   -1,
   -1,  160,   50,   -1,   52,   -1,   -1,   97,   -1,   -1,
   -1,   -1,  156,   -1,  173,   -1,  160,   -1,   -1,  178,
  179,   -1,   -1,   -1,   -1,   13,   -1,   -1,   -1,  173,
   -1,   -1,   80,  123,  178,  179,   -1,   85,   -1,   -1,
   -1,   -1,   -1,   -1,   23,   24,   -1,   -1,   -1,   97,
  209,   30,   40,   -1,   -1,   34,   -1,   -1,   -1,   -1,
   -1,   40,   50,   -1,   52,  209,  156,   46,   47,   -1,
  160,   -1,   -1,   -1,   -1,  123,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  173,   -1,   -1,   -1,   -1,  178,  179,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   85,   -1,   -1,
   -1,   80,   81,   82,   83,   84,   85,   86,  156,   97,
   -1,   -1,  160,   -1,   -1,   -1,   95,   -1,   97,  209,
   -1,   -1,   -1,   -1,   -1,  173,   -1,   -1,   -1,   -1,
  178,  179,   -1,   -1,   -1,  123,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,   23,   24,   -1,   -1,
   -1,   -1,   -1,   30,   -1,   -1,   -1,   34,   -1,   -1,
   -1,  209,   -1,   40,   -1,   42,   -1,   -1,  156,   46,
   47,   -1,  160,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,  160,   -1,   -1,   50,  173,   52,   -1,   54,   55,
  178,  179,   58,   -1,   60,   -1,   -1,   -1,   64,  178,
   -1,   -1,   -1,   80,   81,   82,   83,   84,   85,   86,
   -1,   -1,   23,   24,   -1,   -1,   -1,   -1,   95,   30,
   97,  209,   -1,   34,   -1,   91,   92,   93,   94,   40,
  209,   42,   -1,   -1,   -1,   46,   47,   -1,   41,   50,
   -1,   52,   -1,   54,   55,   -1,  123,   50,   -1,   52,
   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   -1,   70,   71,   80,
   81,   82,   83,   84,   85,   86,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  160,   95,   -1,   97,   90,   91,   92,
   93,   94,   -1,   -1,   -1,   -1,   23,   24,   -1,   -1,
   -1,  178,   -1,   30,   -1,   -1,   -1,   34,   -1,   -1,
   -1,   -1,  123,   40,  180,   42,   -1,   -1,   -1,   46,
   47,   -1,   -1,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,   -1,  209,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  160,
   -1,   -1,   -1,   80,   81,   82,   83,   84,   85,   86,
   -1,   -1,   23,   24,   -1,   -1,   -1,  178,   95,   30,
   97,   -1,   -1,   34,   -1,   -1,   -1,  180,   -1,   40,
   -1,   42,   -1,   -1,   -1,   46,   47,   -1,   41,   50,
   -1,   52,   -1,   54,   55,   -1,  123,   50,  209,   52,
   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   -1,   70,   71,   80,
   81,   82,   83,   84,   85,   86,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  160,   95,   -1,   97,   90,   91,   92,
   93,   94,   -1,   -1,   -1,   -1,   23,   24,   -1,   -1,
   50,  178,   52,   30,   54,   55,   -1,   34,   58,   -1,
   60,   -1,  123,   40,   64,   65,   -1,   -1,   -1,   46,
   47,   -1,   -1,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,   -1,  209,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   91,   92,   93,   94,   -1,   -1,   -1,   -1,  160,
   -1,   -1,   -1,   80,   81,   82,   83,   84,   85,   86,
   -1,   -1,   23,   24,   -1,   -1,   -1,  178,   95,   30,
   97,   -1,   -1,   34,   -1,   -1,   -1,  180,   -1,   40,
   -1,   -1,   -1,   -1,   -1,   46,   47,   -1,   41,   50,
   -1,   52,   -1,   54,   55,   -1,  123,   50,  209,   52,
   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   -1,   70,   71,   80,
   81,   82,   83,   84,   85,   86,   -1,   -1,   -1,   -1,
  180,   -1,   -1,  160,   95,   -1,   97,   90,   91,   92,
   93,   94,   -1,   -1,   -1,   -1,   23,   24,   -1,   -1,
   -1,  178,   -1,   30,   -1,   -1,   -1,   34,   -1,   -1,
   -1,   -1,  123,   40,   -1,   -1,   -1,   -1,   -1,   46,
   47,   -1,   -1,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,   -1,  209,   13,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  160,
   -1,   -1,   -1,   80,   81,   82,   83,   84,   85,   86,
   40,   41,   42,   43,   44,   45,   46,  178,   95,   -1,
   97,   -1,   -1,   -1,   54,   55,   -1,  180,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   73,   74,   -1,  123,   -1,  209,   -1,
   -1,   -1,   -1,   -1,   -1,   85,   -1,   13,   -1,   -1,
   90,   91,   92,   93,   94,   95,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  160,   40,   41,   42,   43,   44,   45,
   46,   -1,   -1,  123,  124,  125,   -1,   -1,   54,   55,
   -1,  178,   58,   -1,   60,   -1,   13,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   73,   74,   -1,
   -1,   -1,   -1,   -1,   -1,  155,  156,   -1,   -1,   -1,
  160,   -1,  209,   -1,   90,   91,   92,   93,   94,   95,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  178,  179,
  180,   58,  182,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   -1,   70,   71,   -1,   -1,   -1,  124,  125,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   90,   91,   92,   93,   94,   -1,   -1,
   97,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  155,
  156,   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   42,
   43,   44,   45,   46,   -1,   -1,  123,   -1,   -1,   -1,
   -1,   54,   55,  179,  180,   58,  182,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,  155,  156,
   -1,   -1,   -1,  160,   -1,   -1,   -1,   90,   91,   92,
   93,   94,   95,   -1,   40,   41,   -1,   43,   44,   45,
   -1,  178,  179,  180,   50,  182,   52,   -1,   54,   55,
   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   -1,   74,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   90,   91,   92,   93,   94,   95,
   -1,   -1,  155,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   40,   41,   -1,   43,   44,   45,   -1,   -1,   -1,   -1,
   50,   41,   52,   43,   54,   55,   -1,  180,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   -1,   74,   -1,   66,   67,   68,   69,
   70,   71,   72,   -1,   74,   -1,   -1,   -1,   -1,  155,
   90,   91,   92,   93,   94,   95,   -1,   40,   -1,   42,
   90,   44,   45,   -1,   -1,   -1,   -1,   50,   -1,   52,
   -1,   54,   55,   -1,  180,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   -1,   70,   71,   72,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,
   93,   94,   95,   -1,   -1,  155,   -1,   40,   -1,   42,
   -1,   44,   45,   -1,   41,  155,   43,   50,   -1,   52,
   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
  180,   64,   65,   66,   67,   68,   -1,   70,   71,   -1,
   67,   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,
   93,   94,   95,   90,   -1,   41,   42,   43,   44,   45,
   -1,   -1,   -1,   -1,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   58,   -1,   60,   -1,   -1,  180,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   -1,   74,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   41,   -1,   43,   -1,   90,   91,   92,   93,   94,   50,
   -1,   52,   -1,   54,   55,   -1,   -1,   58,  155,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   74,   -1,   -1,   -1,  180,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,
   91,   92,   93,   94,   41,   -1,   43,   -1,   -1,   -1,
   -1,   -1,   -1,   50,   -1,   52,   -1,   54,   55,  155,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,
   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,   -1,   41,
   -1,   43,   -1,   90,   91,   92,   93,   94,   50,   -1,
   52,   -1,   54,   55,  155,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,  180,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,
   92,   93,   94,   41,   -1,   43,   -1,   -1,   -1,   -1,
   -1,   -1,   50,   -1,   52,   -1,   54,   55,  155,   -1,
   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,   -1,
   -1,   -1,   -1,  180,   -1,   -1,   -1,   -1,   41,   -1,
   43,   -1,   90,   91,   92,   93,   94,   50,   -1,   52,
   -1,   54,   55,  155,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,
   93,   94,   41,   -1,   43,   -1,   -1,   -1,   -1,   -1,
   -1,   50,   -1,   52,   -1,   54,   55,  155,   -1,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   -1,   74,   -1,   -1,   -1,   -1,
   -1,   -1,  180,   -1,   -1,   -1,   -1,   41,   -1,   43,
   -1,   90,   91,   92,   93,   94,   50,   -1,   52,   -1,
   54,   55,  155,   -1,   58,   -1,   60,   -1,   -1,   -1,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   -1,
   74,   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,   93,
   94,   41,   -1,   43,   -1,   -1,   -1,   -1,   -1,   -1,
   50,   -1,   52,   -1,   54,   55,  155,   -1,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,
   -1,  180,   -1,   -1,   -1,   -1,   41,   -1,   43,   -1,
   90,   91,   92,   93,   94,   50,   -1,   52,   -1,   54,
   55,  155,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   69,   70,   71,   72,   -1,   74,
   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   90,   91,   92,   93,   94,
   41,   -1,   43,   -1,   -1,   -1,   -1,   -1,   -1,   50,
   -1,   52,   -1,   54,   55,  155,   -1,   58,   -1,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,
  180,   -1,   -1,   -1,   -1,   41,   -1,   43,   -1,   90,
   91,   92,   93,   94,   50,   -1,   52,   -1,   54,   55,
  155,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   -1,   74,   -1,
   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   90,   91,   92,   93,   94,   41,
   -1,   43,   -1,   -1,   -1,   -1,   -1,   -1,   50,   -1,
   52,   -1,   54,   55,  155,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,  180,
   -1,   -1,   -1,   -1,   41,   -1,   43,   -1,   90,   91,
   92,   93,   94,   50,   -1,   52,   -1,   54,   55,  155,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,
   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   90,   91,   92,   93,   94,   41,   -1,
   43,   -1,   -1,   -1,   -1,   -1,   -1,   50,   -1,   52,
   -1,   54,   55,  155,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,
   -1,   -1,   -1,   41,   -1,   43,   -1,   90,   91,   92,
   93,   94,   50,   -1,   52,   -1,   54,   55,  155,   -1,
   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,   -1,
   41,   -1,   -1,  180,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   90,   91,   92,   93,   94,   58,   -1,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,
   71,   -1,  155,   -1,   -1,   -1,   -1,   41,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,
   91,   92,   93,   94,   58,   41,   60,  180,   -1,   -1,
   64,   65,   66,   67,   68,   -1,   70,   71,   -1,   -1,
   74,   -1,   58,   -1,   60,   -1,   -1,  155,   64,   65,
   66,   67,   68,   -1,   70,   71,   90,   91,   92,   93,
   94,   -1,   41,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   41,  180,   43,   90,   91,   92,   93,   94,   58,
   -1,   60,   -1,   -1,  155,   64,   65,   66,   67,   68,
   -1,   70,   71,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   -1,   74,   -1,   -1,   -1,   -1,  180,
   43,   90,   91,   92,   93,   94,   -1,   50,   -1,   52,
   90,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   -1,   70,   71,  155,
   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   43,   90,   91,   92,
   93,   94,   -1,   50,  180,   52,   -1,   54,   55,   -1,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   -1,   70,   71,  155,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  180,   43,   90,   91,   92,   93,   94,   -1,   50,
   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,
   71,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,   43,   90,
   91,   92,   93,   94,   -1,   50,   -1,   52,   -1,   54,
   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   -1,   70,   71,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  180,   43,   90,   91,   92,   93,   94,
   -1,   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
   -1,   70,   71,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,
   43,   90,   91,   92,   93,   94,   -1,   50,   -1,   52,
   -1,   54,   55,   -1,   43,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   -1,   70,   71,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
   -1,   70,   71,   -1,   -1,  180,   -1,   90,   91,   92,
   93,   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   90,   91,   92,   93,   94,   50,   -1,   52,   -1,
   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   -1,
   -1,  180,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,   93,
   94,   -1,   50,   -1,   52,   -1,   54,   55,   -1,   -1,
   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   -1,   -1,  180,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  180,   90,   91,   92,   93,   94,   50,   -1,   52,
   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  180,   90,   91,   92,
   93,   94,   -1,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  180,   90,   91,   92,   93,   94,   50,   -1,
   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,   90,   91,
   92,   93,   94,   -1,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  180,   90,   91,   92,   93,   94,   50,
   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,   90,
   91,   92,   93,   94,   -1,   50,   -1,   52,   -1,   54,
   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   -1,   70,   71,   72,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  180,   90,   91,   92,   93,   94,
   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,
   90,   91,   92,   93,   94,   -1,   50,   -1,   52,   -1,
   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,
   64,   65,   66,   67,   68,   69,   70,   71,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  180,   90,   91,   92,   93,
   94,   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
   -1,   70,   71,   72,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  180,   90,   91,   92,   93,   94,   -1,   50,   -1,   52,
   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   -1,   70,   71,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  180,   90,   91,   92,
   93,   94,   50,   -1,   52,   -1,   54,   55,   -1,   -1,
   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   -1,   70,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  180,   90,   91,   92,   93,   94,   -1,   50,   -1,
   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   58,   70,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,
   71,   -1,   -1,   74,   -1,   -1,   -1,  180,   90,   91,
   92,   93,   94,   -1,   -1,   -1,   -1,   -1,   -1,   90,
   91,   92,   93,   94,   58,   -1,   60,   -1,   -1,   -1,
   64,   65,   66,   67,   68,   69,   70,   71,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   -1,
   70,   71,  180,   -1,   -1,   -1,   90,   91,   92,   93,
   94,   -1,   -1,   -1,   -1,   -1,   41,   -1,   43,   -1,
   90,   91,   92,   93,   94,   50,   -1,   52,   -1,   54,
   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   69,   70,   71,   72,  180,   74,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,
   -1,   -1,   41,   -1,   43,   90,   91,   92,   93,   94,
   -1,   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   -1,   74,  180,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  180,   90,   91,   92,   93,   94,   -1,   -1,   41,   -1,
   43,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   52,
  155,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   41,   -1,   43,   -1,   -1,   -1,   90,   91,   92,
   -1,   94,   52,   -1,   54,   55,  155,   -1,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   -1,   74,   -1,   41,   -1,   43,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   52,   -1,   -1,
   90,   91,   92,   58,   94,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   69,   70,   71,   72,   -1,   74,
   -1,   41,  155,   43,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   52,   -1,   -1,   90,   91,   92,   58,   94,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   -1,   74,   -1,   41,   -1,   43,   -1,
   -1,   -1,   -1,   -1,   -1,  155,   -1,   52,   -1,   -1,
   90,   91,   92,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   69,   70,   71,   72,   -1,   74,
   -1,   41,   -1,   43,   -1,   -1,   -1,   -1,   -1,   -1,
  155,   -1,   52,   -1,   -1,   90,   91,   92,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   41,   74,   43,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   52,  155,   -1,   -1,   -1,   -1,
   90,   91,   92,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  155,   -1,   90,   -1,   92,  617,  618,  619,  620,  621,
  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,
  632,  633,  634,  635,   -1,   -1,   -1,   -1,   50,   -1,
   52,   -1,   54,   55,   -1,  155,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  155,   90,   91,
   92,   93,   94,   -1,   50,  687,   52,   -1,   54,   55,
   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   90,   91,   92,   93,   94,   52,
   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,
   52,   94,   54,   55,   -1,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   52,   -1,   -1,   90,   91,
   92,   58,   94,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   52,   -1,   -1,   90,   91,   92,   58,   94,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   52,
   -1,   -1,   -1,   -1,   -1,   58,   -1,   60,   90,   91,
   92,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   52,   -1,
   -1,   -1,   -1,   -1,   58,   -1,   60,   90,   91,   92,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,
};
#define YYFINAL 23
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 256
#define YYUNDFTOKEN 372
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file","ASM","AUTO","BREAK","CASE",0,0,"CONTINUE","DEFAULT","DELETE",
"DO",0,"ELSE","ENUM",0,0,"FOR","FORTRAN","FRIEND","GOTO","IF",0,0,"NEW",
"OPERATOR",0,0,0,"RETURN",0,"SIZEOF",0,0,"SWITCH","THIS",0,0,0,0,"WHILE","LP",
"RP","LB","RB","REF","DOT","NOT","COMPL",0,0,"MUL",0,"AND",0,"PLUS","MINUS",0,0,
"LT",0,"GT",0,0,0,"ER","OR","ANDAND","OROR","QUEST","COLON","ASSIGN","CM","SM",
"LC","RC",0,0,0,0,0,"ID","STRING","ICON","FCON","CCON","NAME","ZERO",0,0,0,
"ASOP","RELOP","EQUOP","DIVOP","SHIFTOP","ICOP",0,"TYPE","CATCH","THROW","TRY",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TNAME","EMPTY","NO_ID","NO_EXPR",
"FDEF",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ELLIPSIS","AGGR",
0,0,0,"MEM",0,0,0,0,0,0,0,0,0,0,0,0,"MEMPTR",0,"PR","MEMQ",0,"TSCOPE",
"DECL_MARKER","REFMUL","LDOUBLE","LINKAGE",0,0,"TEMPLATE",0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"XVIRT","XNLIST","XILINE","XIA",0,0,0,"SM_PARAM",0,"PTNAME",
"NEW_INIT_KLUDGE","XDELETED_NODE","VEC_DELETE","VEC_NEW","DUMMY_LAST_NODE",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : ext_def",
"ext_def : external_def",
"ext_def : SM",
"ext_def : EOFTOK",
"ext_def : LINKAGE LC",
"ext_def : RC",
"ext_def : template",
"$$1 :",
"$$2 :",
"$$3 :",
"template : TEMPLATE $$1 LT $$2 template_parm_list GT $$3 template_def",
"template_def : data_dcl",
"template_def : att_fct_def",
"template_def : fct_def",
"template_def : fct_dcl",
"template_def : class_dcl SM",
"identifier : ID",
"identifier : qualified_tname",
"external_def : data_dcl",
"external_def : att_fct_def",
"external_def : fct_def",
"external_def : fct_dcl",
"external_def : ASM LP STRING RP SM",
"fct_dcl : decl ASSIGN initializer SM",
"fct_dcl : decl SM",
"$$4 :",
"att_fct_def : type decl arg_dcl_list check_inline $$4 base_init block",
"att_fct_def : type decl arg_dcl_list check_inline EMPTY",
"att_fct_def : type decl arg_dcl_list check_inline NO_ID",
"$$5 :",
"fct_def : decl arg_dcl_list check_inline $$5 base_init block",
"fct_def : decl arg_dcl_list check_inline EMPTY",
"fct_def : decl arg_dcl_list check_inline NO_ID",
"$$6 :",
"inline_fct_def : FDEF $$6 base_init block",
"check_inline :",
"$$7 :",
"base_init : COLON $$7 init_list",
"base_init :",
"init_list : binit",
"init_list : init_list CM binit",
"binit : LP elist RP",
"binit : ttag LP elist RP",
"arg_dcl_list : arg_dcl_list data_dcl",
"arg_dcl_list :",
"dl : decl",
"$$8 :",
"dl : ID COLON $$8 e",
"dl : COLON e",
"$$9 :",
"dl : decl ASSIGN $$9 initializer",
"decl_list : dl",
"decl_list : decl_list CM dl",
"data_dcl : type decl_list SM",
"data_dcl : type SM",
"lt : LT",
"gt : GT",
"tname : qualified_tname",
"tname : qualified_tname lt temp_inst_parms gt",
"tname : NAME lt temp_inst_parms gt",
"tp : TYPE",
"tp : LINKAGE",
"tp : tname",
"tp : tn_list DECL_MARKER",
"tp : class_dcl",
"tp : enum_dcl",
"tp : DECL_MARKER",
"type : tp",
"type : type TYPE",
"type : type tname",
"type : type class_dcl",
"type : type enum_dcl",
"type : type DECL_MARKER",
"cm : CM",
"temp_inst_parms : temp_inst_parms cm temp_inst_parm",
"temp_inst_parms : temp_inst_parm",
"new_decl2 :",
"new_decl2 : arg_lp new_decl2 RP",
"new_decl2 : ptr new_decl2",
"new_decl2 : new_decl2 arg_list",
"new_decl2 : new_decl2 vec",
"new_type2 : type new_decl2",
"temp_inst_parm : new_type2",
"temp_inst_parm : e",
"enumtag : tag",
"enumtag : DECL_MARKER",
"enumtag : tn_list DECL_MARKER",
"$$10 :",
"enum_dcl : ENUM LC $$10 moe_list RC",
"$$11 :",
"enum_dcl : ENUM enumtag LC $$11 moe_list RC",
"enum_dcl : ENUM enumtag",
"moe_list : moe",
"moe_list : moe_list CM moe",
"template_parm_list : template_parm_list CM template_parm",
"template_parm_list : template_parm",
"template_parm_list :",
"template_parm : AGGR identifier",
"template_parm : type formal_decl",
"formal_decl : ID",
"formal_decl : ptr formal_decl",
"formal_decl : formal_decl vec",
"formal_decl : formal_decl arg_list",
"formal_decl : arg_lp formal_decl RP",
"moe : ID",
"$$12 :",
"moe : ID $$12 ASSIGN e",
"moe :",
"$$13 :",
"class_dcl : class_head cl_mem_list RC $$13 inline_mem_defs",
"class_dcl : AGGR tag",
"class_dcl : AGGR qualified_tname lt temp_inst_parms gt",
"class_dcl : AGGR DECL_MARKER",
"inline_mem_defs :",
"inline_mem_defs : inline_mem_defs inline_fct_def",
"base_list : COLON base_unit_list",
"base_list :",
"base_unit_list : base_unit",
"base_unit_list : base_unit_list CM base_unit",
"base_unit : ttag",
"base_unit : PR ttag",
"base_unit : TYPE ttag",
"base_unit : PR TYPE ttag",
"base_unit : TYPE PR ttag",
"class_head : AGGR LC",
"class_head : AGGR tag base_list LC",
"class_head : AGGR qualified_tname lt temp_inst_parms gt base_list LC",
"tag : ID",
"tag : qualified_tname",
"ttag : ID",
"ttag : tname",
"cl_mem_list : cl_mem_list cl_mem",
"cl_mem_list :",
"cl_mem_list : cl_mem_list template",
"cl_mem : data_dcl",
"cl_mem : att_fct_def SM",
"cl_mem : fct_def SM",
"cl_mem : fct_def",
"cl_mem : att_fct_def",
"cl_mem : fct_dcl",
"cl_mem : PR COLON",
"cl_mem : scope_qualifiers fname SM",
"fname : ID",
"fname : COMPL TNAME",
"fname : OPERATOR oper",
"fname : OPERATOR c_type",
"oper : PLUS",
"oper : MINUS",
"oper : MUL",
"oper : AND",
"oper : OR",
"oper : ER",
"oper : SHIFTOP",
"oper : EQUOP",
"oper : DIVOP",
"oper : RELOP",
"oper : LT",
"oper : GT",
"oper : ANDAND",
"oper : OROR",
"oper : LP RP",
"oper : LB RB",
"oper : NOT",
"oper : COMPL",
"oper : ICOP",
"oper : ASOP",
"oper : ASSIGN",
"oper : NEW",
"oper : NEW LB RB",
"oper : DELETE",
"oper : DELETE LB RB",
"oper : REF",
"oper : CM",
"oper : REFMUL",
"scope_qualifiers : tn_list",
"tn_list : tscope",
"tn_list : tn_list tscope",
"qualified_tname : tn_list TNAME",
"qualified_tname : TNAME",
"fct_attributes :",
"fct_attributes : fct_attributes TYPE",
"fct_attributes : fct_attributes THROW LP type_list RP",
"type_list : tag",
"type_list : type_list CM tag",
"decl : decl arg_list",
"decl : decl LP RP fct_attributes",
"decl : tname arg_list",
"decl : decl arg_lp elist RP",
"decl : tname LP MUL ID RP arg_list",
"decl : tname LP AND ID RP arg_list",
"decl : tname LP elist RP",
"decl : tname LP RP fct_attributes",
"decl : tname LP MEMPTR decl RP arg_list",
"decl : fname",
"decl : ID DOT fname",
"decl : scope_qualifiers fname",
"decl : scope_qualifiers ID DOT fname",
"decl : ptr decl",
"decl : ptr tname",
"decl : tname vec",
"decl : decl vec",
"decl : arg_lp decl RP",
"arg_decl : ID",
"arg_decl : ptr qualified_tname",
"arg_decl :",
"arg_decl : ptr arg_decl",
"arg_decl : arg_decl vec",
"arg_decl : arg_decl arg_list",
"arg_decl : arg_lp arg_decl RP",
"new_decl :",
"new_decl : ptr new_decl",
"new_decl : new_decl vec",
"cast_decl :",
"cast_decl : ptr cast_decl",
"cast_decl : cast_decl vec",
"cast_decl : LP cast_decl RP arg_list",
"cast_decl : LP cast_decl RP vec",
"c_decl :",
"c_decl : ptr c_decl",
"stmt_list :",
"stmt_list : stmt_list TEMPLATE",
"stmt_list : stmt_list caselab_stmt",
"caselab_stmt : caselablist statement",
"caselablist :",
"condition : LP e RP",
"$$14 :",
"block : LC $$14 stmt_list RC",
"block : LC RC",
"block : LC error RC",
"simple : ee",
"simple : BREAK",
"simple : CONTINUE",
"simple : GOTO ID",
"$$15 :",
"simple : DO $$15 caselab_stmt WHILE condition",
"simple : ASM LP STRING RP",
"$$16 :",
"sm : $$16 SM",
"statement : simple sm",
"statement : SM",
"statement : RETURN e SM",
"statement : TYPE STRING block",
"statement : data_dcl",
"statement : att_fct_def",
"statement : block",
"statement : IF condition caselab_stmt",
"statement : IF condition caselab_stmt ELSE caselab_stmt",
"statement : WHILE condition caselab_stmt",
"$$17 :",
"statement : FOR LP $$17 caselab_stmt e SM e RP caselab_stmt",
"$$18 :",
"statement : SWITCH $$18 condition caselab_stmt",
"$$19 :",
"statement : ID COLON $$19 caselab_stmt",
"$$20 :",
"statement : TNAME COLON $$20 caselab_stmt",
"$$21 :",
"statement : CASE $$21 e COLON caselab_stmt",
"$$22 :",
"statement : DEFAULT COLON $$22 caselab_stmt",
"statement : TRY block handler_list",
"handler_list :",
"handler_list : handler_list handler",
"handler : CATCH exception_type block",
"exception_type : arg_lp type arg_decl RP",
"exception_type : LP ELLIPSIS RP",
"elist : ex_list",
"ex_list : initializer",
"ex_list : ex_list CM initializer",
"initializer : e",
"initializer : LC elist RC",
"ee : ee ASSIGN ee",
"ee : ee PLUS ee",
"ee : ee MINUS ee",
"ee : ee MUL ee",
"ee : ee AND ee",
"ee : ee OR ee",
"ee : ee ER ee",
"ee : ee SHIFTOP ee",
"ee : ee EQUOP ee",
"ee : ee DIVOP ee",
"ee : ee RELOP ee",
"ee : ee GT ee",
"ee : ee LT ee",
"ee : ee ANDAND ee",
"ee : ee OROR ee",
"ee : ee ASOP ee",
"ee : ee CM ee",
"ee : ee QUEST ee COLON ee",
"ee : ee REFMUL ee",
"ee : DELETE term",
"ee : DELETE LB e RB term",
"ee : MEM DELETE term",
"ee : MEM DELETE LB e RB term",
"ee : term",
"ee : THROW term",
"e : e ASSIGN e",
"e : e PLUS e",
"e : e MINUS e",
"e : e MUL e",
"e : e AND e",
"e : e OR e",
"e : e ER e",
"e : e SHIFTOP e",
"e : e EQUOP e",
"e : e DIVOP e",
"e : e RELOP e",
"e : e LT e",
"e : e GT e",
"e : e ANDAND e",
"e : e OROR e",
"e : e ASOP e",
"e : e CM e",
"e : e QUEST e COLON e",
"e : e REFMUL e",
"e : DELETE term",
"e : DELETE LB e RB term",
"e : MEM DELETE term",
"e : MEM DELETE LB e RB term",
"e : term",
"e : THROW term",
"e :",
"term : NEW cast_type",
"term : NEW new_type",
"term : MEM NEW cast_type",
"term : MEM NEW new_type",
"term : term ICOP",
"term : cast_type term",
"term : MUL term",
"term : AND term",
"term : MINUS term",
"term : PLUS term",
"term : NOT term",
"term : COMPL term",
"term : ICOP term",
"term : SIZEOF term",
"term : SIZEOF cast_type",
"term : term LB e RB",
"term : term REF prim",
"term : term REF MEMQ prim",
"term : term REF MEMQ TNAME",
"term : term REF dtorspec",
"term : term REF scope_qualifiers prim",
"term : term REF scope_qualifiers TNAME",
"term : term DOT prim",
"term : term DOT MEMQ prim",
"term : term DOT MEMQ TNAME",
"term : term DOT dtorspec",
"term : term DOT scope_qualifiers prim",
"term : term DOT scope_qualifiers TNAME",
"term : prim",
"term : scope_qualifiers prim",
"term : tn_list COMPL tag",
"term : tn_list COMPL TYPE",
"term : term_elist",
"term : term_lp e RP",
"term : ZERO",
"term : ICON",
"term : FCON",
"term : STRING",
"term : CCON",
"term : THIS",
"dtorspec : COMPL tag",
"dtorspec : MEMQ COMPL tag",
"dtorspec : TYPE MEM COMPL TYPE",
"dtorspec : COMPL TYPE",
"dtorspec : TYPE MEM COMPL tag",
"dtorspec : MEMQ COMPL TYPE",
"dtorspec : tn_list COMPL tag",
"dtorspec : tn_list COMPL TYPE",
"term_elist : TYPE LP elist RP",
"term_elist : tname LP elist RP",
"term_elist : NEW term_lp elist RP cast_type",
"term_elist : NEW term_lp elist RP new_type",
"term_elist : MEM NEW term_lp elist RP cast_type",
"term_elist : MEM NEW term_lp elist RP new_type",
"term_elist : term LP elist RP",
"ptname : PTNAME lt temp_inst_parms gt",
"tscope : TSCOPE",
"tscope : MEM",
"tscope : ptname TSCOPE",
"prim : ID",
"prim : OPERATOR oper",
"prim : OPERATOR c_type",
"cast_type : term_lp type cast_decl RP",
"term_lp : LP",
"c_tp : TYPE",
"c_tp : tname",
"c_tp : c_tp TYPE",
"c_tp : c_tp tname",
"c_type : c_tp c_decl",
"new_type : type new_decl",
"arg_type : type arg_decl",
"$$23 :",
"arg_type : type arg_decl ASSIGN $$23 initializer",
"arg_lp : LP",
"arg_list : arg_lp arg_type_list ellipsis_opt RP fct_attributes",
"arg_type_list : arg_type_list CM at",
"arg_type_list : at",
"at : arg_type",
"at :",
"ellipsis_opt :",
"ellipsis_opt : ELLIPSIS",
"ellipsis_opt : CM ELLIPSIS",
"ptr : MUL",
"ptr : AND",
"ptr : MUL TYPE",
"ptr : ptr TYPE",
"ptr : AND TYPE",
"ptr : ptname MEMPTR",
"ptr : MEMPTR",
"ptr : ptname MEMPTR TYPE",
"ptr : MEMPTR TYPE",
"vec : LB e RB",
"vec : NOT",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 3039 "gram.y"

static Pname
enumcheck( Pname n )
{
	Ptype tx = n->tp;
	if ( tx->base == TYPE ) {
		Pname bn = Pbase(tx)->b_name;
		tx = bn->tp;
		if ( tx->base != EOBJ
		||   strcmp(bn->string,n->string)
		)
			error("%n ofT%t redeclared as enum.",n,tx);
		n = bn;
	} else if ( tx->base != EOBJ )
		error("%n ofT%t redeclared as enum",n,tx);

// error('d',"enumtag: ccl %t tag: %n", ccl, n);
	return n;
}

static void
check_tag()
/*
        Allow the case of inline/virtual/overload as
        modifiers of return type of form struct/class/union x foo()
        SM, COLON, LC ==> real class declaration, not return type
*/
{
	switch ( NEXTTOK() ) {
	case SM: case COLON: case LC:
    		declTag = 1;
    		break;
	default:
    		declTag = 0;
    		break;
        }
}

static void
hoist_al()
/*SYM hoist names in arg table to next outer scope and pop scope
 * called upon discovering that an arg list isn't really being parsed
 *    -- i.e., 'arg_lp decl RP ...' -- arg_lp pushed an arg table
 */
{
	if ( Ctbl->k_id != ARG ) {
		// saw something like '( X::y )' while probably reduced
		//    as 'arg_lp decl RP' and pushed scope of X
		// no names should have been entered; discard table
		Pktab otbl = Ctbl;
		Ctbl = GET_XSCOPE();
		if ( Ctbl->k_id != ARG ) error('i',"hoist_al: noA table");
		POP_SCOPE();
		SET_XSCOPE(Ctbl);
		Ctbl = otbl;
		return;
	}
	if ( !in_typedef && !in_friend ) Ctbl->hoist();
	POP_SCOPE();
}
static void
arg_redec( Pname fn )
/* parsing restored member inline at end of class
 * redeclare args before entering function
 */
{
	if ( fn==0 || fn->tp->base != FCT )
		error('i',"bad inline rewrite! --%n %t",fn,fn?fn->tp:0);
	if ( Ctbl->k_id != ARG )
		error('i',"arg_redec(%n ) -- noA table",fn);
	//SYM -- reenter in arg table
	//SYM -- probably more efficient to keep arg table around...
	Pname al = Pfct(fn->tp)->argtype;
	Pname n = 0;
	for ( ;  al;  al = al->n_list ) {
		DB( if(Ydebug>=1)error('d',"arg_redec:  %n  %d",al,al->lex_level); );
		n = new name(al->string);
		insert_name(n,Ctbl);
		DB( if(Ydebug>=1)error('d',"   %n",n); );
	}
}

static Pname
dummy_dtor( TOK q, TOK d )
{
	if ( q != d ) {
		error("syntax error: inconsistent destructor notation");
		q = d;
	}
	Pname dt = new name("type destructor");
	dt->base = DTOR;
	dt->tp = new fct(void_type,0,1);
	dt->n_dcl_printed = 1; // suppress any code generation
	switch ( d ) {
	default:
		error("syntax error: illegal destructor notation");
		dt->tp2 = any_type;
		break;
	case CHAR:
		dt->tp2 = dt->tpdef = char_type;
		break;
	case SHORT:
		dt->tp2 = dt->tpdef = short_type;
		break;
	case SIGNED:
	case INT:
		dt->tp2 = dt->tpdef = int_type;
		break;
	case UNSIGNED:
		dt->tp2 = dt->tpdef = uint_type;
		break;
	case LONG:
		dt->tp2 = dt->tpdef = long_type;
		break;
	case FLOAT:
		dt->tp2 = dt->tpdef = float_type;
		break;
	case DOUBLE:
		dt->tp2 = dt->tpdef = double_type;
		break;
	case VOID:
		dt->tp2 = dt->tpdef = void_type;
		break;
	}
	return dt;
}
static Pname
dummy_dtor()
{
	Pname dt = new name("type destructor");
	dt->base = DTOR;
	dt->tp = new fct(void_type,0,1);
	dt->n_dcl_printed = 1; // suppress any code generation
	dt->tp2 = 0;
	dt->tpdef = 0;
	return dt;
}

static bit
check_if_base( Pclass c1, Pclass c2 )
{
	if ( same_class(c1,c2) ) return 1;
	for (Pbcl b = c1->baselist; b; b=b->next) {
		if ( same_class(b->bclass,c2) ) return 1;
		if (check_if_base(b->bclass,c2)) return 1;
	}
	return 0;
}
#line 3302 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    /* yym is set below */
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 732 "gram.y"
	{	YYCLEAN;return 2; }
#line 3504 "y.tab.c"
break;
case 2:
#line 733 "gram.y"
	{	YYCLEAN;return 1; }
#line 3509 "y.tab.c"
break;
case 3:
#line 734 "gram.y"
	{	YYCLEAN;return 0; }
#line 3514 "y.tab.c"
break;
case 4:
#line 736 "gram.y"
	{
				set_linkage(yystack.l_mark[-1].s);
				bl_level--;
				YYCLEAN;return 1;
			}
#line 3523 "y.tab.c"
break;
case 5:
#line 742 "gram.y"
	{
				set_linkage(0);
				bl_level++;
				YYCLEAN;return 1;
			}
#line 3532 "y.tab.c"
break;
case 6:
#line 747 "gram.y"
	{  YYCLEAN;return 1; }
#line 3537 "y.tab.c"
break;
case 7:
#line 751 "gram.y"
	{
			PUSH_TEMPLATE_SCOPE();/*SYM*/
/* error('d',"template seen: in_class_decl %d", in_class_decl);*/
			if (in_class_decl) {
				must_be_friend = 1;
				if (templp->in_progress == true) /* inside template*/
					templp->save_templ = new templ_state;
			}
			else must_be_friend = 0;
			templp->start() ;
			templp->formals_in_progress = true;
		 }
#line 3553 "y.tab.c"
break;
case 8:
#line 763 "gram.y"
	{ in_arg_list = 2; }
#line 3558 "y.tab.c"
break;
case 9:
#line 764 "gram.y"
	{
			templp->enter_parameters();
			templp->formals_in_progress = false;
			in_arg_list = 0;
		 }
#line 3567 "y.tab.c"
break;
case 10:
#line 770 "gram.y"
	{
			templp->end(yystack.l_mark[0].pn);
			POP_SCOPE(); /*SYM*/
			if (in_class_decl && templp->save_templ) {
				delete templp->save_templ;
				templp->save_templ = 0;
			}
			else {
				templp->in_progress = false;
				bound_expr_tbl->reinit();
			}
                  /*SYM -- goto mod removed*/
                 }
#line 3584 "y.tab.c"
break;
case 12:
#line 786 "gram.y"
	{ goto mod; }
#line 3589 "y.tab.c"
break;
case 13:
#line 787 "gram.y"
	{ goto mod; }
#line 3594 "y.tab.c"
break;
case 15:
#line 790 "gram.y"
	{
			Pname pn = yystack.l_mark[-1].pb->aggr();
			/* basetype:aggr() does not return the name for a forward
		    	 * declaration, so extract it directly */
                    	yyval.p = (pn ? pn : yystack.l_mark[-1].pb->b_name);
                    	DECL_TYPE = 0;
		  }
#line 3605 "y.tab.c"
break;
case 17:
#line 801 "gram.y"
	{ yyval.pn = Ncopy(yystack.l_mark[0].pn) ;}
#line 3610 "y.tab.c"
break;
case 18:
#line 805 "gram.y"
	{
				/*SYM -- tn stuff removed*/
				if (yystack.l_mark[0].pn==0) yyval.i = 1;
			}
#line 3618 "y.tab.c"
break;
case 19:
#line 809 "gram.y"
	{ goto mod; }
#line 3623 "y.tab.c"
break;
case 20:
#line 811 "gram.y"
	{ mod: /*SYM -- tn stuff removed*/
				Pname n = yystack.l_mark[0].pn;
				if ( n && n->n_qualifier ) {/*SYM*/
					if ( n->n_qualifier->n_template_arg != template_type_formal )
						UNSET_SCOPE();
					if ( n->n_qualifier == sta_name )
						n->n_qualifier = 0;
				}
			}
#line 3636 "y.tab.c"
break;
case 22:
#line 822 "gram.y"
	{	Pname n = new name(make_name('A'));
				n->tp = new basetype(ASM,0);
				Pbase(n->tp)->b_name = Pname(yystack.l_mark[-2].s);
				yyval.p = n;
			}
#line 3645 "y.tab.c"
break;
case 23:
#line 830 "gram.y"
	{
				err_name = yystack.l_mark[-3].pn;
				if(err_name) err_name->n_initializer = yystack.l_mark[-1].pe;
				goto fix;
			}
#line 3654 "y.tab.c"
break;
case 24:
#line 836 "gram.y"
	{
				Ptype t;
				err_name = yystack.l_mark[-1].pn;
			fix:
				if (err_name == 0) {
					error("syntax error:TX");
					yyval.p = Ndata(defa_type,err_name);
				}
				else if ((t=err_name->tp) == 0) {
					error("TX for%n",err_name);
					yyval.p = Ndata(defa_type,err_name);
				}
				else if (t->base==FCT) {
					if (Pfct(t)->returns==0)
						yyval.p = Nfct(defa_type,err_name,0);
					else
						yyval.p = Ndata(0,err_name);
				}
				else {
					error("syntax error:TX for%k%n",t->base,err_name);
					yyval.p = Ndata(defa_type,err_name);
				}
				if ( err_name && err_name->n_qualifier ) {
					if ( err_name->n_qualifier->n_template_arg != template_type_formal )
						UNSET_SCOPE();
					if ( err_name->n_qualifier == sta_name )
						err_name->n_qualifier = 0;
				}
			}
#line 3687 "y.tab.c"
break;
case 25:
#line 868 "gram.y"
	{	if ( yychar == LC ) --bl_level;
				Pname n = Nfct(yystack.l_mark[-3].p,yystack.l_mark[-2].pn,dummy);
				Fargdcl(n->tp,name_unlist(yystack.l_mark[-1].nl),n);
				arg_redec( yystack.l_mark[-2].pn );
				yyval.pn = n;
			 	if ( yychar == LC ) ++bl_level;
				Ctbl->k_name = n;
			}
#line 3699 "y.tab.c"
break;
case 26:
#line 877 "gram.y"
	{	Pname n = yystack.l_mark[-2].pn;/*SYM*/
				if ( !in_typedef ) {
					Fbody(n->tp) = Pblock(yystack.l_mark[0].p);/*SYM*/
					Finit(n->tp) = yystack.l_mark[-1].pn;
				}
				yyval.p = n;
				NOT_EXPECT_ID();
			}
#line 3711 "y.tab.c"
break;
case 27:
#line 886 "gram.y"
	{
				Pname n = Nfct(yystack.l_mark[-4].p,yystack.l_mark[-3].pn,dummy);
				Fargdcl(n->tp,name_unlist(yystack.l_mark[-2].nl),n);
				yystack.l_mark[0].q->retval.pn = n;
				yyval.p = n;
				NOT_EXPECT_ID();
			}
#line 3722 "y.tab.c"
break;
case 28:
#line 894 "gram.y"
	{
				if (!templp->in_progress)
					error(&yystack.l_mark[-3].pn->where,"syntax error -- did you forget a ';'?");
				Pname n = Nfct(yystack.l_mark[-4].p,yystack.l_mark[-3].pn,0);
				yyval.p = n;
				NOT_EXPECT_ID();
			}
#line 3733 "y.tab.c"
break;
case 29:
#line 904 "gram.y"
	{	if ( yychar == LC ) --bl_level;
			 	Pname n = Nfct(defa_type,yystack.l_mark[-2].pn,dummy);
				Fargdcl(n->tp,name_unlist(yystack.l_mark[-1].nl),n);
				arg_redec( yystack.l_mark[-2].pn );
				yyval.pn = n;
			 	if ( yychar == LC ) ++bl_level;
				Ctbl->k_name = n;
			}
#line 3745 "y.tab.c"
break;
case 30:
#line 913 "gram.y"
	{	Pname n = yystack.l_mark[-2].pn;/*SYM*/
				Fbody(n->tp) = Pblock(yystack.l_mark[0].p);/*SYM*/
				if ( yystack.l_mark[-1].pn && yystack.l_mark[-1].pn->n_list &&
     					ccl && ccl->csu == UNION )
						error( "multiple initializers in unionK %s::%n", yystack.l_mark[-5].pn->string, yystack.l_mark[-5].pn );
				Finit(n->tp) = yystack.l_mark[-1].pn;
				yyval.p = n;
				NOT_EXPECT_ID();
			}
#line 3758 "y.tab.c"
break;
case 31:
#line 923 "gram.y"
	{
				Pname n = Nfct(defa_type,yystack.l_mark[-3].pn,dummy);
				Fargdcl(n->tp,name_unlist(yystack.l_mark[-2].nl),n);
				yystack.l_mark[0].q->retval.pn = n;
				yyval.p = n;
				NOT_EXPECT_ID();
			}
#line 3769 "y.tab.c"
break;
case 32:
#line 931 "gram.y"
	{
				if (explicit_template_definition  == 0 )
					error(&yystack.l_mark[-3].pn->where,"badD of%n -- did you forget a ';'?",yystack.l_mark[-3].pn);
				else {
			             Pname n = pti->get_tname();
				     if (yystack.l_mark[-3].pn->n_oper == DTOR)
					error('s',"explicitYZL for destructor of specializedYC%n -- please drop the parameter list",n);
				     else
					error('i',"specialializedYC%n: declaration problem: %s",n,yystack.l_mark[-3].pn->string);
				     error('i', "cannot recover from previous error" );
				}
				Pname n = Nfct(defa_type,yystack.l_mark[-3].pn,0);
				yyval.p = n;
				NOT_EXPECT_ID();
			}
#line 3788 "y.tab.c"
break;
case 33:
#line 949 "gram.y"
	{	PUSH_ARG_SCOPE();/*SYM*/
                        	arg_redec(yystack.l_mark[0].pn);
                        	Ctbl->k_name = yystack.l_mark[0].pn;
                   	}
#line 3796 "y.tab.c"
break;
case 34:
#line 954 "gram.y"
	{
				Finit(yystack.l_mark[-3].pn->tp) = yystack.l_mark[-1].pn;
				Pfct(yystack.l_mark[-3].pn->tp)->body = Pblock(yystack.l_mark[0].p);
				yyval.pn = yystack.l_mark[-3].pn;
				NOT_EXPECT_ID();
			}
#line 3806 "y.tab.c"
break;
case 35:
#line 964 "gram.y"
	{
			/* if parsing implicit inline def, save body*/
			/*   of function for parsing after class def*/
			if ( Ctbl->k_id != ARG )
				error('i',"expectingA table in check_inline!");
			switch ( NEXTTOK() ) {
			case LC: case COLON:
				if ( in_class_decl ) {
					/* mem or friend inline def*/
					/* save text of mem_init & ftn*/
					la_backup(yychar,yylval);
					/* yylval used as dummy...*/
					la_backup(FDEF, yylval);
					if ( (yylval.q = save_text()) ) {
						yychar = EMPTY;
						POP_SCOPE();/*SYM*/
					} else { /* syntax error*/
						/* just parse in place*/
						yylex(); /* FDEF*/
						yylex();
						yychar = NO_ID;
						hoist_al();/*SYM*/
					}
				} /* if in_class_decl*/
				/*SYM -- else non-nested ftn def*/
				/*SYM -- arg table will become block table*/
				break;
			default:
				la_backup(yychar,yylval);
				yychar = NO_ID; /* 'graceful' recovery*/
				hoist_al();/*SYM*/
				break;
			}
		   }
#line 3844 "y.tab.c"
break;
case 36:
#line 1000 "gram.y"
	{ ++in_binit_list; }
#line 3849 "y.tab.c"
break;
case 37:
#line 1001 "gram.y"
	{
				yyval.p = yystack.l_mark[0].p;
				in_arg_list = 0;
				--in_binit_list;
			}
#line 3858 "y.tab.c"
break;
case 38:
#line 1007 "gram.y"
	{	yyval.p = 0; }
#line 3863 "y.tab.c"
break;
case 39:
#line 1011 "gram.y"
	{ yyval.p = yystack.l_mark[0].p; }
#line 3868 "y.tab.c"
break;
case 40:
#line 1013 "gram.y"
	{ yyval.pn = yystack.l_mark[0].pn;  yyval.pn->n_list = yystack.l_mark[-2].pn; }
#line 3873 "y.tab.c"
break;
case 41:
#line 1017 "gram.y"
	{
				yyval.pn = new name;
				yyval.pn->n_initializer = yystack.l_mark[-1].pe;
			}
#line 3881 "y.tab.c"
break;
case 42:
#line 1022 "gram.y"
	{
				Pname n = Ncopy(yystack.l_mark[-3].pn);
				n->base = yystack.l_mark[-3].pn->base;
				n->tp = yystack.l_mark[-3].pn->tp;
				n->n_initializer = yystack.l_mark[-1].pe;
				yyval.pn = n;
			}
#line 3892 "y.tab.c"
break;
case 43:
#line 1037 "gram.y"
	{	if (yystack.l_mark[0].pn == 0)
					error("badAD");
				else if (yystack.l_mark[0].pn->tp->base == FCT)
					error("FD inAL (%n)",yystack.l_mark[0].pn);
				else if (yystack.l_mark[-1].p)
                                        yystack.l_mark[-1].nl->add_list(yystack.l_mark[0].pn);
				else
					yyval.nl = new nlist(yystack.l_mark[0].pn);
			}
#line 3905 "y.tab.c"
break;
case 44:
#line 1047 "gram.y"
	{
				PUSH_ARG_SCOPE();/*SYM*/
                                yyval.p = 0;
			}
#line 3913 "y.tab.c"
break;
case 46:
#line 1055 "gram.y"
	{
                                if ( in_typedef ) {
                                        error("Tdef field");
                                        in_typedef = 0;
                                }
                        /*      ENTER_NAME($<pn>1);*/
                        }
#line 3924 "y.tab.c"
break;
case 47:
#line 1063 "gram.y"
	{	yyval.p = yystack.l_mark[-3].pn;
				yyval.pn->tp = new basetype(FIELD,yystack.l_mark[0].pn);
		 	}
#line 3931 "y.tab.c"
break;
case 48:
#line 1067 "gram.y"
	{	yyval.p = new name;
				yyval.pn->tp = new basetype(FIELD,yystack.l_mark[0].pn);
                                if ( in_typedef ) {
                                        error("Tdef field");
                                        in_typedef = 0;
                                }
			}
#line 3942 "y.tab.c"
break;
case 49:
#line 1075 "gram.y"
	{
                        /*      ENTER_NAME($<pn>1);*/
                        }
#line 3949 "y.tab.c"
break;
case 50:
#line 1079 "gram.y"
	{       Pexpr e = yystack.l_mark[0].pe;
                                if (e == dummy) error("emptyIr");
                                yystack.l_mark[-3].pn->n_initializer = e;
                                init_seen = 0;
                        }
#line 3958 "y.tab.c"
break;
case 51:
#line 1087 "gram.y"
	{	Pname n = yystack.l_mark[0].pn;
				if (n) {
				    yyval.nl = new nlist(n);
				    if ( n->n_qualifier ) {/*SYM*/
					if ( n->n_qualifier->n_template_arg != template_type_formal )
						UNSET_SCOPE();
					if ( n->n_qualifier == sta_name )
					    n->n_qualifier = 0;
				    }
				}
				if ( NEXTTOK() == CM && la_look() == TNAME )
					EXPECT_ID();
			}
#line 3975 "y.tab.c"
break;
case 52:
#line 1101 "gram.y"
	{	Pname n = yystack.l_mark[0].pn;
				if (yystack.l_mark[-2].p)
					if (n)
						yystack.l_mark[-2].nl->add(n);
					else
						error("DL syntax");
				else {
					if (n) yyval.nl = new nlist(n);
					error("DL syntax");
				}
				if ( n ) {
				    if ( n->n_qualifier ) {/*SYM*/
					if ( n->n_qualifier->n_template_arg != template_type_formal )
						UNSET_SCOPE();
					if ( n->n_qualifier == sta_name )
					    n->n_qualifier = 0;
				    }
				}
				if ( NEXTTOK() == CM && la_look() == TNAME )
					EXPECT_ID();
			}
#line 4000 "y.tab.c"
break;
case 53:
#line 1125 "gram.y"
	{
				extern int co_hack;
				co_hack = 1;
				/*$$ = Ndata($1,name_unlist($<nl>2));*/
				Pname n = Ndata(yystack.l_mark[-2].p,name_unlist(yystack.l_mark[-1].nl));
/*error('d',"data_dcl:type decl_list sm: %n%t in_typedef%t in_tag%n",n,n->tp,in_typedef,in_tag);*/
				/*SYM redef check removed*/
				in_typedef = 0;
				in_friend = 0;
				in_tag = 0;
				co_hack = 0;
				DECL_TYPE = 0;
				yyval.p = n;
			}
#line 4018 "y.tab.c"
break;
case 54:
#line 1140 "gram.y"
	{
				yyval.p = yystack.l_mark[-1].pb->aggr();
				in_typedef = 0;
				in_friend = 0;
				in_tag = 0;
				DECL_TYPE = 0;
			}
#line 4029 "y.tab.c"
break;
case 55:
#line 1152 "gram.y"
	{
			templp->parameters_in_progress++;
			in_arg_list = 2;
			check_decl();
		  }
#line 4038 "y.tab.c"
break;
case 56:
#line 1158 "gram.y"
	{
			templp->parameters_in_progress--;
			if (!templp->parameters_in_progress)
				in_arg_list = 0;
		  }
#line 4047 "y.tab.c"
break;
case 57:
#line 1164 "gram.y"
	{ yyval.pn = templp->check_tname(yystack.l_mark[0].pn) ; }
#line 4052 "y.tab.c"
break;
case 58:
#line 1166 "gram.y"
	{
			int sm = NEXTTOK()==SM;
			if (in_friend) in_friend += sm;
			bit flag=0;
			if (dtpt_opt && in_typedef &&
				!templp->parameters_in_progress &&
				curloc.file == first_file)
				flag=1;
		    	yyval.pn = parametrized_typename(yystack.l_mark[-3].pn,
						  (expr_unlist(yystack.l_mark[-1].el)),in_friend) ;
			if (flag)
				righttname=yyval.pn;
		  }
#line 4069 "y.tab.c"
break;
case 59:
#line 1180 "gram.y"
	{ extern Pbase any_type;
		    error("%n was not aZizedT.", yyval.pn) ;
                    yyval.pn= yystack.l_mark[-3].pn->tdef() ;
                    yyval.pn->tp = any_type ; }
#line 4077 "y.tab.c"
break;
case 60:
#line 1189 "gram.y"
	{
				yyval.p = new basetype(yystack.l_mark[0].t,0);
				if ( yystack.l_mark[0].t == TYPEDEF ) {
					in_typedef = yyval.pt;
/* error('d',"typedef: ccl %t ", ccl, $<pn>1);*/
				}
				else if ( yystack.l_mark[0].t == FRIEND ) {
					in_friend = 1;
					must_be_friend = 0;
				}
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			}
#line 4093 "y.tab.c"
break;
case 61:
#line 1202 "gram.y"
	{	yyval.p = new basetype(EXTERN,0);
				yyval.pb->b_linkage = yystack.l_mark[0].s;
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			}
#line 4101 "y.tab.c"
break;
case 62:
#line 1207 "gram.y"
	{
				yyval.p = new basetype(TYPE,yystack.l_mark[0].pn);
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			}
#line 4109 "y.tab.c"
break;
case 63:
#line 1212 "gram.y"
	{ /* modified tn_list TNAME*/
				yyval.p = new basetype(TYPE,yystack.l_mark[0].pn);
				/*xxx qualifier currently ignored...*/
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			}
#line 4118 "y.tab.c"
break;
case 66:
#line 1220 "gram.y"
	{
				if (DECL_TYPE == TNAME)
					yyval.p = new basetype(TYPE,yystack.l_mark[0].pn);
		/*	else if (DECL_TYPE == TSCOPE)*/
		/*	$$ = 0;*/
				else
				if (DECL_TYPE == 0 &&
					yystack.l_mark[0].p->base == TNAME)
						yyval.p = new basetype(TYPE,yystack.l_mark[0].pn);
				else
					yyval.p = new basetype(yystack.l_mark[0].t,0);
				DECL_TYPE = -1;
			}
#line 4135 "y.tab.c"
break;
case 68:
#line 1237 "gram.y"
	{
				if ( DECL_TYPE != -1 ) {
					switch (yystack.l_mark[-1].pb->base) {
					case COBJ: case EOBJ:
						Pbase bt;
						bt = new basetype(0,0);
						*bt = *yystack.l_mark[-1].pb;
						DEL(yystack.l_mark[-1].pb);
						yystack.l_mark[-1].pb = bt;
					}
					yyval.p = yystack.l_mark[-1].pb->type_adj(yystack.l_mark[0].t);
				}
				DECL_TYPE = 0;
			}
#line 4153 "y.tab.c"
break;
case 69:
#line 1252 "gram.y"
	{
/*error('d',"decl_type: %d  $1: %t  $2: %n",DECL_TYPE,$<pb>1,$<pn>2);*/
				if ( DECL_TYPE != -1 )
			 		yyval.p = yystack.l_mark[-1].pb->name_adj(yystack.l_mark[0].pn);
			/*XXX*/	else if(yystack.l_mark[-1].pb==0) yyval.p=new basetype(TYPE,yystack.l_mark[0].pn);
				DECL_TYPE = 0;
			}
#line 4164 "y.tab.c"
break;
case 70:
#line 1259 "gram.y"
	{ yyval.p = yystack.l_mark[-1].pb->base_adj(yystack.l_mark[0].pb); }
#line 4169 "y.tab.c"
break;
case 71:
#line 1260 "gram.y"
	{ yyval.p = yystack.l_mark[-1].pb->base_adj(yystack.l_mark[0].pb); }
#line 4174 "y.tab.c"
break;
case 72:
#line 1262 "gram.y"
	{
				if (DECL_TYPE == TYPE) {
					switch (yystack.l_mark[-1].pb->base) {
					case COBJ: case EOBJ:
						{
						Pbase bt;
						bt = new basetype(0,0);
						*bt = *yystack.l_mark[-1].pb;
						DEL(yystack.l_mark[-1].pb);
						yystack.l_mark[-1].pb = bt;
						}
					}
					yyval.p = yystack.l_mark[-1].pb->type_adj(yystack.l_mark[0].t);
				}
			/*XXX*/	else if (DECL_TYPE == TSCOPE) {
			/*XXX*/		error('i',"T decl_marker(tscope)");
			/*XXX*/	/*	$$ = $1;//ignore(?)*/
			/*XXX*/	}
				else
					yyval.p = yystack.l_mark[-1].pb->name_adj(yystack.l_mark[0].pn);
				DECL_TYPE = -1;
			}
#line 4200 "y.tab.c"
break;
case 73:
#line 1286 "gram.y"
	{in_arg_list = 2; check_decl();}
#line 4205 "y.tab.c"
break;
case 74:
#line 1290 "gram.y"
	{yystack.l_mark[-2].el->add(new expr(ELIST,yystack.l_mark[0].pe,0)) ; }
#line 4210 "y.tab.c"
break;
case 75:
#line 1292 "gram.y"
	{ in_arg_list=0; yyval.el = new elist(new expr(ELIST,yystack.l_mark[0].pe,0)); }
#line 4215 "y.tab.c"
break;
case 76:
#line 1296 "gram.y"
	{
				yyval.p = new name;
			}
#line 4222 "y.tab.c"
break;
case 77:
#line 1300 "gram.y"
	{
				yyval.p = yystack.l_mark[-1].p;
				in_arg_list = 0;
				hoist_al();
			}
#line 4231 "y.tab.c"
break;
case 78:
#line 1306 "gram.y"
	{
				Ptyp(yystack.l_mark[-1].p) = yystack.l_mark[0].pn->tp;
				yystack.l_mark[0].pn->tp = (Ptype)yystack.l_mark[-1].p;
				yyval.p = yystack.l_mark[0].p;
				NOT_EXPECT_ID();
			}
#line 4241 "y.tab.c"
break;
case 79:
#line 1313 "gram.y"
	{
				Freturns(yystack.l_mark[0].p) = yystack.l_mark[-1].pn->tp;
				yystack.l_mark[-1].pn->tp = (Ptype)yystack.l_mark[0].p;
			}
#line 4249 "y.tab.c"
break;
case 80:
#line 1318 "gram.y"
	{
				Vtype(yystack.l_mark[0].p) = yystack.l_mark[-1].pn->tp;
				yystack.l_mark[-1].pn->tp = (Ptype)yystack.l_mark[0].p;
			}
#line 4257 "y.tab.c"
break;
case 81:
#line 1324 "gram.y"
	{ yyval.p = Ncast(yystack.l_mark[-1].p,yystack.l_mark[0].pn); }
#line 4262 "y.tab.c"
break;
case 82:
#line 1327 "gram.y"
	{
				yystack.l_mark[0].pn->n_template_arg = template_actual_arg_dummy;
				yyval.pe = yystack.l_mark[0].pn; /* keep yacc happy */
			}
#line 4270 "y.tab.c"
break;
case 83:
#line 1332 "gram.y"
	{
				if (yystack.l_mark[0].pe == dummy) error("emptyYZL");
				yyval.pe = yystack.l_mark[0].pe;
			}
#line 4278 "y.tab.c"
break;
case 84:
#line 1340 "gram.y"
	{ yyval.p = enumcheck( yystack.l_mark[0].pn); }
#line 4283 "y.tab.c"
break;
case 85:
#line 1342 "gram.y"
	{
			if ( DECL_TYPE != TNAME ) {
				error("syntax error -- enum%k",yystack.l_mark[0].t);
				yyval.p = 0;
			} else
				yyval.p = enumcheck( yystack.l_mark[0].pn);
		}
#line 4294 "y.tab.c"
break;
case 86:
#line 1350 "gram.y"
	{
			if ( DECL_TYPE != TNAME ) {
				error("enum declaration syntax");
				yyval.p = 0;
			} else
				yyval.pn = enumcheck(yystack.l_mark[0].pn);
			if (in_typedef && in_typedef->base == 0)
				in_typedef->defined = TNAME_SEEN;
			/*xxx qualifier currently ignored...*/
		}
#line 4308 "y.tab.c"
break;
case 87:
#line 1362 "gram.y"
	{ ++in_class_decl; }
#line 4313 "y.tab.c"
break;
case 88:
#line 1363 "gram.y"
	{ --in_class_decl; yyval.p = end_enum(0,yystack.l_mark[-1].nl); }
#line 4318 "y.tab.c"
break;
case 89:
#line 1364 "gram.y"
	{ ++in_class_decl; }
#line 4323 "y.tab.c"
break;
case 90:
#line 1365 "gram.y"
	{ --in_class_decl; yyval.p = end_enum(yystack.l_mark[-4].pn,yystack.l_mark[-1].nl); }
#line 4328 "y.tab.c"
break;
case 91:
#line 1366 "gram.y"
	{ yyval.pb = (Pbase)yystack.l_mark[0].pn->tp; }
#line 4333 "y.tab.c"
break;
case 92:
#line 1370 "gram.y"
	{	if (yystack.l_mark[0].p) yyval.nl = new nlist(yystack.l_mark[0].pn); }
#line 4338 "y.tab.c"
break;
case 93:
#line 1372 "gram.y"
	{	if( yystack.l_mark[0].p)
					if (yystack.l_mark[-2].p)
						yystack.l_mark[-2].nl->add(yystack.l_mark[0].pn);
					else
						yyval.nl = new nlist(yystack.l_mark[0].pn);
			}
#line 4348 "y.tab.c"
break;
case 96:
#line 1383 "gram.y"
	{
				yyval.pn = 0;
				error("emptyYZL");
			}
#line 4356 "y.tab.c"
break;
case 97:
#line 1392 "gram.y"
	{ templp->collect(yystack.l_mark[-1].t, yystack.l_mark[0].pn) ; }
#line 4361 "y.tab.c"
break;
case 98:
#line 1394 "gram.y"
	{templp->collect(Ndata(yystack.l_mark[-1].p,yystack.l_mark[0].pn)); }
#line 4366 "y.tab.c"
break;
case 99:
#line 1401 "gram.y"
	{	yyval.p = yystack.l_mark[0].pn; }
#line 4371 "y.tab.c"
break;
case 100:
#line 1403 "gram.y"
	{	Ptyp(yystack.l_mark[-1].p) = yystack.l_mark[0].pn->tp;
				yystack.l_mark[0].pn->tp = (Ptype)yystack.l_mark[-1].p;
				yyval.p = yystack.l_mark[0].p;
			}
#line 4379 "y.tab.c"
break;
case 101:
#line 1408 "gram.y"
	{	Vtype(yystack.l_mark[0].p) = yystack.l_mark[-1].pn->tp;
				yystack.l_mark[-1].pn->tp = (Ptype)yystack.l_mark[0].p;
			}
#line 4386 "y.tab.c"
break;
case 102:
#line 1412 "gram.y"
	{	Freturns(yystack.l_mark[0].p) = yystack.l_mark[-1].pn->tp;
				yystack.l_mark[-1].pn->tp = (Ptype)yystack.l_mark[0].p;
			}
#line 4393 "y.tab.c"
break;
case 103:
#line 1416 "gram.y"
	{
				yyval.p = yystack.l_mark[-1].p;
				in_arg_list = 0;
				hoist_al();
			}
#line 4402 "y.tab.c"
break;
case 104:
#line 1425 "gram.y"
	{
				if ( yystack.l_mark[0].pn->n_oper != TNAME )
					insert_name(yystack.l_mark[0].pn,Ctbl);
				yyval.p = yystack.l_mark[0].pn;
				yyval.pn->tp = moe_type;
			}
#line 4412 "y.tab.c"
break;
case 105:
#line 1432 "gram.y"
	{
				if ( yystack.l_mark[0].pn->n_oper != TNAME )
					insert_name(yystack.l_mark[0].pn,Ctbl);
			}
#line 4420 "y.tab.c"
break;
case 106:
#line 1437 "gram.y"
	{	yyval.p = yystack.l_mark[-3].pn;
				yyval.pn->tp = moe_type;
				yyval.pn->n_initializer = yystack.l_mark[0].pe;
			}
#line 4428 "y.tab.c"
break;
case 107:
#line 1442 "gram.y"
	{	yyval.p = 0; }
#line 4433 "y.tab.c"
break;
case 108:
#line 1446 "gram.y"
	{	parsing_class_members = 0;
				RESTORE_STATE();
				switch ( NEXTTOK() ) {
				case TYPE: case AGGR: case ENUM: case EOFTOK:
					error("`;' or declaratorX afterCD");
					la_backup(yychar,yylval);
					yychar = SM;
					break;
				}
				la_backup(yychar,yylval);
				yychar = -1;
				restore_text();
				++bl_level; /* scope weirdness!*/
				++in_mem_fct;
			}
#line 4452 "y.tab.c"
break;
case 109:
#line 1462 "gram.y"
	{
				--in_mem_fct;
				--bl_level; /* scope weirdness!*/
				if ( yychar == ID ) {
					/* (yuk!) adjust lex level*/
					--yylval.pn->lex_level;
				}
				ccl->mem_list = name_unlist(yystack.l_mark[-3].nl);
/* error('d',"ccl: %t templ_friends: %d", ccl, templ_friends);*/
				ccl->templ_friends = templ_friends; templ_friends = 0;
				if ( --in_class_decl )  /* nested class*/
					/* continue to parse enclosing class*/
					parsing_class_members = 1;
				/*SYM -- tn stuff removed*/
                        	POP_SCOPE();/*SYM*/
				if ( Ctbl->k_id == TEMPLATE ) {
					/* remove intermediate template table*/
					/*    from scope of class*/
					ccl->k_tbl->k_next = Ctbl->k_next;
				}

				if (pti) {
					pti->explicit_inst();
					Pname nnn = yyval.pt->bname();
/* error('d',"ccl: %s nnn: %s", ccl->string, nnn->string);*/
					nnn->string = ccl->string;
					explicit_template_definition = 0;
					pti = 0;
				}

				end_cl();
				declTag = 1;
			}
#line 4489 "y.tab.c"
break;
case 110:
#line 1496 "gram.y"
	{ aggrcheck:
				yyval.pb = (Pbase)yystack.l_mark[0].pn->tp;
				if ( yyval.p == 0 ) {
					if (templp->parameters_in_progress)
						error("TX for%n -- did you misdeclare aY?",yystack.l_mark[0].pn);
					else error("TX for %n",yystack.l_mark[0].pn);
					error('i', "cannot recover from previous error" );
				}

				if ( yyval.p->base == TYPE ) {
					Pname nx = yyval.pb->b_name;
					yyval.pb = (Pbase)nx->tp;
					if ( yyval.p->base != COBJ
					||   strcmp(nx->string,yystack.l_mark[0].pn->string)
					)
						error("%n of type%t redeclared as%k.",yystack.l_mark[0].pn,yyval.pb,yystack.l_mark[-1].t);
				} else if ( yyval.p->base != COBJ )
					error("%n of type%t redeclared as%k",yystack.l_mark[0].pn,yyval.pb,yystack.l_mark[-1].t);
				check_tag();
			}
#line 4513 "y.tab.c"
break;
case 111:
#line 1517 "gram.y"
	{
                    /* don't place the template on the instantiation list if it is
                     * a friend declaration or a foward declaration of a specialization
                     * friend class x<int> and struct x<int>; */

                    dont_instantiate = NEXTTOK()==SM;
		    Pexpr e=0;
		    if (dont_instantiate && in_friend == 0) {
			/* *** this code could be used for forward declaration*/
			Ptempl t = templp->is_template(yystack.l_mark[-3].pn);

			/* must have seen a definition of template class*/
			if (t == 0) {
				error("explicitC instance of a nonYC%n",yystack.l_mark[-3].pn);
				error('i', "cannot recover from previous error" );
			}

			/* make sure the explicit arguments are ok*/
			e = expr_unlist(yystack.l_mark[-1].el);
			t->check_actual_args(e);

			/* watch out for redefinition -- if exists,*/
			/* use forward declaration or create instance*/
			pti = t->get_match(e,0,false);
			if ( pti ) {
				if (pti->get_class()->class_base == INSTANTIATED)
					error("ZC%n multiply instantiated",yystack.l_mark[-3].pn);
			}
			else pti = new templ_inst(e,t,yystack.l_mark[-4].t);
			pti->inst_formals = t->get_formals();

			error('s',"forwardD of a specialized version ofY%n",yystack.l_mark[-3].pn);
			error('C',"\tclass %n",pti->get_tname());
			error('c'," -- did you mean a general forward declaration of theY?\n");
			error('C',"\tif so, use:  template <formal-parameters> class %n;\n",yystack.l_mark[-3].pn);
	            }

		    if (!e)
		    {
		        e = expr_unlist(yystack.l_mark[-1].el);
                    }
                    Pname p = parametrized_typename(yystack.l_mark[-3].pn, e, in_friend);
                    dont_instantiate = 0;
                    yyval.pb = (Pbase)p->tp;
                    check_tag();
                  }
#line 4563 "y.tab.c"
break;
case 112:
#line 1564 "gram.y"
	{
				goto aggrcheck;
			}
#line 4570 "y.tab.c"
break;
case 115:
#line 1574 "gram.y"
	{ yyval.pbc = yystack.l_mark[0].pbc; }
#line 4575 "y.tab.c"
break;
case 116:
#line 1575 "gram.y"
	{ yyval.pbc = 0; }
#line 4580 "y.tab.c"
break;
case 118:
#line 1580 "gram.y"
	{	if (yystack.l_mark[0].pbc) { yyval.pbc = yystack.l_mark[0].pbc; yyval.pbc->next = yystack.l_mark[-2].pbc; } }
#line 4585 "y.tab.c"
break;
case 119:
#line 1583 "gram.y"
	{ yyval.pbc = dobase(0,yystack.l_mark[0].pn); }
#line 4590 "y.tab.c"
break;
case 120:
#line 1584 "gram.y"
	{ yyval.pbc = dobase(yystack.l_mark[-1].t,yystack.l_mark[0].pn); }
#line 4595 "y.tab.c"
break;
case 121:
#line 1585 "gram.y"
	{ yyval.pbc = dobase(0,yystack.l_mark[0].pn,yystack.l_mark[-1].t); }
#line 4600 "y.tab.c"
break;
case 122:
#line 1586 "gram.y"
	{ yyval.pbc = dobase(yystack.l_mark[-2].t,yystack.l_mark[0].pn,yystack.l_mark[-1].t); }
#line 4605 "y.tab.c"
break;
case 123:
#line 1587 "gram.y"
	{ yyval.pbc = dobase(yystack.l_mark[-1].t,yystack.l_mark[0].pn,yystack.l_mark[-2].t); }
#line 4610 "y.tab.c"
break;
case 124:
#line 1591 "gram.y"
	{
				Pname n = start_cl(yystack.l_mark[-1].t,0,0);
				PUSH_CLASS_SCOPE(n);/*SYM*/
				ccl->k_tbl = Ctbl;/*SYM*/
				yyval.p = Pbase(n->tp);
				parsing_class_members = 1;
				/*SYM -- tn stuff removed*/
				in_class_decl++;
				SAVE_STATE();
			}
#line 4624 "y.tab.c"
break;
case 125:
#line 1603 "gram.y"
	{
				Pname n = start_cl(yystack.l_mark[-3].t,yystack.l_mark[-2].pn,yystack.l_mark[-1].pbc);
				PUSH_CLASS_SCOPE(n);/*SYM*/
				ccl->k_tbl = Ctbl;/*SYM*/
				yyval.p = Pbase(n->tp);
				parsing_class_members = 1;
				/*SYM -- tn stuff removed*/
				in_class_decl++;
				SAVE_STATE();
			}
#line 4638 "y.tab.c"
break;
case 126:
#line 1614 "gram.y"
	{
			/* LC increments bl_level by 1*/
			if ( bl_level > 1 )
			     error('s', "specializedY%n not at global scope",yystack.l_mark[-5].pn);
			explicit_template_definition = 1;
			Ptempl t = templp->is_template(yystack.l_mark[-5].pn);

			/* must have seen a definition of template class*/
			if (t == 0 || !t->defined) {
				error("YC%n must be defined prior to an explicitC instance",yystack.l_mark[-5].pn);
				error('i', "cannot recover from previous error" );
			}

			/* make sure the explicit arguments are ok*/
			Pexpr e = expr_unlist(yystack.l_mark[-3].el);
			t->check_actual_args(e);

			/* watch out for redefinition -- if exists,*/
			/* use forward declaration or create instance*/
			pti = t->get_match(e,0,false);
			if ( pti ) {
				if (pti->get_class()->class_base == INSTANTIATED)
					error("ZC%n multiply instantiated",yystack.l_mark[-5].pn);
			}
			else pti = new templ_inst(e,t,yystack.l_mark[-6].t);

			Pname n = start_cl(yystack.l_mark[-6].t,pti->get_tname(),yystack.l_mark[-1].pbc);
                        Pbase(n->tp)->b_name->n_redefined = 1;
			PUSH_CLASS_SCOPE(n);/*SYM*/
			ccl->k_tbl = Ctbl;/*SYM*/
			yyval.p = Pbase(n->tp);
			parsing_class_members = 1;
			in_class_decl++;
			SAVE_STATE();
			}
#line 4677 "y.tab.c"
break;
case 127:
#line 1651 "gram.y"
	{ yyval.p = yystack.l_mark[0].pn; }
#line 4682 "y.tab.c"
break;
case 128:
#line 1652 "gram.y"
	{ yyval.p=yystack.l_mark[0].p; }
#line 4687 "y.tab.c"
break;
case 129:
#line 1655 "gram.y"
	{ yyval.p = yystack.l_mark[0].pn; }
#line 4692 "y.tab.c"
break;
case 130:
#line 1656 "gram.y"
	{ yyval.p=yystack.l_mark[0].p; }
#line 4697 "y.tab.c"
break;
case 131:
#line 1660 "gram.y"
	{
				if (yystack.l_mark[0].p) {
					if (yystack.l_mark[-1].p)
						yystack.l_mark[-1].nl->add_list(yystack.l_mark[0].pn);
					else
						yyval.nl = new nlist(yystack.l_mark[0].pn);
				}
				in_friend = 0;
			}
#line 4710 "y.tab.c"
break;
case 132:
#line 1669 "gram.y"
	{ yyval.p = 0; }
#line 4715 "y.tab.c"
break;
case 133:
#line 1671 "gram.y"
	{
/* error('d', "ZizedTD must be atG, notC scope" );*/
				if (must_be_friend) {
					error("non-friend ZizedTD must be atG, notC scope" );
					error('i', "cannot recover from previous error" );
				}
  				templ_friends = new cons(templp->parsed_template,templ_friends);
				templp->parsed_template = 0;
			}
#line 4728 "y.tab.c"
break;
case 135:
#line 1684 "gram.y"
	{
				fct_friend1:
				if (in_friend &&
				    yystack.l_mark[-1].pn &&
				    yystack.l_mark[-1].pn->n_qualifier &&
				    yystack.l_mark[-1].pn->n_qualifier->n_template_arg != template_type_formal)
					UNSET_SCOPE();
			}
#line 4740 "y.tab.c"
break;
case 136:
#line 1693 "gram.y"
	{
				goto fct_friend1;
			}
#line 4747 "y.tab.c"
break;
case 137:
#line 1697 "gram.y"
	{
				fct_friend2:
				if (in_friend &&
				    yystack.l_mark[0].pn &&
				    yystack.l_mark[0].pn->n_qualifier &&
				    yystack.l_mark[0].pn->n_qualifier->n_template_arg != template_type_formal)
					UNSET_SCOPE();
			}
#line 4759 "y.tab.c"
break;
case 138:
#line 1706 "gram.y"
	{
				goto fct_friend2;
			}
#line 4766 "y.tab.c"
break;
case 140:
#line 1711 "gram.y"
	{	yyval.p = new name;
				yyval.pn->base = yystack.l_mark[-1].t;
			}
#line 4773 "y.tab.c"
break;
case 141:
#line 1715 "gram.y"
	{	Pname n = Ncopy(yystack.l_mark[-1].pn);
				if (n->n_oper == TYPE) {
					error('s',"visibilityD for conversion operator");
					/* n->tp = Ptype(n->n_initializer);*/
					n->tp = Ptype(n->cond);
					n->cond = 0;
					/* n->n_initializer = 0;*/
					n->n_oper = 0;
					sig_name(n);
				}
				n->n_qualifier = yystack.l_mark[-2].pn;
				n->base = PR;
				yyval.p = n;
				if ( yystack.l_mark[-2].pn && yystack.l_mark[-2].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();/*SYM*/
			}
#line 4793 "y.tab.c"
break;
case 142:
#line 1745 "gram.y"
	{ yyval.p = yystack.l_mark[0].pn; }
#line 4798 "y.tab.c"
break;
case 143:
#line 1747 "gram.y"
	{	yyval.p = Ncopy(yystack.l_mark[0].pn);
				yyval.pn->n_oper = DTOR;
			}
#line 4805 "y.tab.c"
break;
case 144:
#line 1751 "gram.y"
	{	yyval.p = new name(oper_name(yystack.l_mark[0].t));
				yyval.pn->n_oper = yystack.l_mark[0].t;
			}
#line 4812 "y.tab.c"
break;
case 145:
#line 1755 "gram.y"
	{	Pname n = yystack.l_mark[0].pn;
				n->string = "_type";
				n->n_oper = TYPE;
				n->cond = Pexpr(n->tp);
				/* n->n_initializer = Pexpr(n->tp);*/
				n->tp = 0;
				yyval.p = n;
			}
#line 4824 "y.tab.c"
break;
case 160:
#line 1779 "gram.y"
	{	yyval.t = CALL; }
#line 4829 "y.tab.c"
break;
case 161:
#line 1780 "gram.y"
	{	yyval.t = DEREF; }
#line 4834 "y.tab.c"
break;
case 167:
#line 1786 "gram.y"
	{	yyval.t = NEW; --in_new; }
#line 4839 "y.tab.c"
break;
case 168:
#line 1787 "gram.y"
	{	yyval.t = VEC_NEW; --in_new; }
#line 4844 "y.tab.c"
break;
case 169:
#line 1788 "gram.y"
	{	yyval.t = DELETE; }
#line 4849 "y.tab.c"
break;
case 170:
#line 1789 "gram.y"
	{	yyval.t = VEC_DELETE; }
#line 4854 "y.tab.c"
break;
case 171:
#line 1790 "gram.y"
	{	yyval.t = REF; }
#line 4859 "y.tab.c"
break;
case 172:
#line 1791 "gram.y"
	{	yyval.t = CM; }
#line 4864 "y.tab.c"
break;
case 173:
#line 1792 "gram.y"
	{	yyval.t = REFMUL;
					if (yystack.l_mark[0].t == DOT) error(".* cannot be overloaded");
				}
#line 4871 "y.tab.c"
break;
case 174:
#line 1797 "gram.y"
	{ yyval.pn = SET_SCOPE(yystack.l_mark[0].pn); }
#line 4876 "y.tab.c"
break;
case 175:
#line 1801 "gram.y"
	{   if ( yystack.l_mark[0].pn != sta_name ) {
				Pname n = yystack.l_mark[0].pn;
				const char *str = 0, *str2 = 0, *s = n->string;
				if (n->n_template_arg != template_type_formal) {
				    n = n->tp->is_cl_obj();
				    if ( n ) str = s = get_classname(n->string);
				}
				if ( n && NEXTTOK() == TNAME
				&& strcmp(s,str2=get_classname(yylval.pn->string))==0){
					/* ctor -- change to ID to avoid*/
					/*    parsing as type spec*/
					yychar = ID;
					yylval.pn = Ncopy(yylval.pn);
					yylval.pn->n_oper = TNAME;
				}
				if ( str ) delete[] (char*)str;
				if ( str2 ) delete[] (char*)str2;
			    }
			    yyval.pn = yystack.l_mark[0].pn;
			}
#line 4900 "y.tab.c"
break;
case 176:
#line 1822 "gram.y"
	{/*SYM*/
			   yyval.pn = yystack.l_mark[0].pn;
			   if ( yystack.l_mark[0].pn == sta_name ) {
			   	error("scope qualifier syntax");
			   } else {
/* error('d',"tn_list: tn_list tscope: pn2: %s", $<pn>2->string);*/
				Pname cn = yystack.l_mark[0].pn;
				const char *str = 0, *str2 = 0, *s = cn->string;
				if (cn->n_template_arg != template_type_formal){
				    cn = yystack.l_mark[0].pn->tp->is_cl_obj();
				    if (cn) str = s = get_classname(cn->string);
				}
				if ( cn && NEXTTOK() == TNAME
				&& strcmp(s,str2=get_classname(yylval.pn->string))==0){
					/* ctor -- change to ID to avoid*/
					/*    parsing as type spec*/
					yychar = ID;
					yylval.pn = Ncopy(yylval.pn);
					yylval.pn->n_oper = TNAME;
				}
				if ( str ) delete[] (char*)str;
				if ( str2 ) delete[] (char*)str2;
				if ( yystack.l_mark[-1].pn != sta_name
				&&   yystack.l_mark[-1].pn->n_template_arg != template_type_formal){
				    Pname cx = yystack.l_mark[-1].pn->tp->is_cl_obj();
				    if ( cx ) /* cx::cn::*/
					if ( check_if_base(Pclass(cx->tp),Pclass(cn->tp)) )
						error("%n ::%n :: --%n not aM of%n",cx,cn,cn,cx);
				}
			    }
			}
#line 4935 "y.tab.c"
break;
case 177:
#line 1856 "gram.y"
	{
				yyval.pn = yystack.l_mark[0].pn;
				if (in_typedef && in_typedef->base == 0)
					in_typedef->defined = TNAME_SEEN;
				/*xxx qualifier currently ignored...*/
				/* $<pn>$ = Ncopy( $<pn>2 );*/
				/* $<pn>$->n_oper = TNAME;*/
				/* $<pn>$->n_qualifier = $<pn>1;*/
			}
#line 4948 "y.tab.c"
break;
case 178:
#line 1866 "gram.y"
	{
				yyval.pn = yystack.l_mark[0].pn;
				if (in_typedef && in_typedef->base == 0)
					in_typedef->defined = TNAME_SEEN;
			/*	$<pn>$ = Ncopy( $<pn>1 );*/
			/*	$<pn>$->n_oper = TNAME;*/
			}
#line 4959 "y.tab.c"
break;
case 179:
#line 1876 "gram.y"
	{ yyval.i = 0; }
#line 4964 "y.tab.c"
break;
case 180:
#line 1878 "gram.y"
	{ /* const/volatile function */
				switch ( yystack.l_mark[0].t ) {
				case VOLATILE:
					error('s',"volatile functions");
					break;
				case CONST:
					yyval.i = (yystack.l_mark[-1].i | 1);
					break;
				default:
					if ( NEXTTOK() != SM
					&&   yychar != COLON
					&&   yychar != LC ) {
						la_backup(yychar,yylval);
						yylval.t = yystack.l_mark[0].t;
						la_backup(TYPE,yylval);
						yylval.t = SM;
						yychar = SM;
						error("syntax error: unexpected%k (did you forget a `;'?)",yystack.l_mark[0].t);
					} else error("FD syntax: unexpected%k",yystack.l_mark[0].t);
					break;
				}
 			}
#line 4990 "y.tab.c"
break;
case 181:
#line 1901 "gram.y"
	{ yyval.i = yystack.l_mark[-4].i; }
#line 4995 "y.tab.c"
break;
case 182:
#line 1904 "gram.y"
	{ yyval.pl = 0; }
#line 5000 "y.tab.c"
break;
case 183:
#line 1906 "gram.y"
	{ yyval.pl = 0; }
#line 5005 "y.tab.c"
break;
case 184:
#line 1910 "gram.y"
	{	Freturns(yystack.l_mark[0].p) = yystack.l_mark[-1].pn->tp;
				yystack.l_mark[-1].pn->tp = yystack.l_mark[0].pt;
			}
#line 5012 "y.tab.c"
break;
case 185:
#line 1914 "gram.y"
	{ /* function with no argument */
 				yystack.l_mark[-3].pn->tp = new fct(yystack.l_mark[-3].pn->tp,0,1);
 				Pfct(yystack.l_mark[-3].pn->tp)->f_const = (yystack.l_mark[0].i & 1);
 			}
#line 5020 "y.tab.c"
break;
case 186:
#line 1919 "gram.y"
	{	Pname n = yystack.l_mark[-1].pn;
				yyval.p = Ncopy(n);
				/*??? what if tname is qualified ???*/
				/*SYM -- change -- do not if ctor def...*/
				if ( !in_typedef
				&&  (ccl==0 || strcmp(n->string,ccl->string)) )
					n->hide();
				yyval.pn->n_oper = TNAME;
				Freturns(yystack.l_mark[0].p) = yyval.pn->tp;
				yyval.pn->tp = yystack.l_mark[0].pt;
			}
#line 5035 "y.tab.c"
break;
case 187:
#line 1935 "gram.y"
	{
				yystack.l_mark[-3].pn->tp = new fct(yystack.l_mark[-3].pn->tp,yystack.l_mark[-1].pn,1);
 				in_arg_list = 0;
 				/*SYM end_al($2,0);*/
 				POP_SCOPE();/*SYM*/
				/*RESTORE_STATE();*/
			}
#line 5046 "y.tab.c"
break;
case 188:
#line 1943 "gram.y"
	{
				Pptr p = new ptr( PTR, 0 );
				Ptyp(p) = new basetype(TYPE,yystack.l_mark[-5].pn);
				Freturns( yystack.l_mark[0].p ) = Ptype(p);
				yystack.l_mark[-2].pn->tp = yystack.l_mark[0].pt;
			/*SYM -- insert in table if not done elsewhere...*/
				if ( yystack.l_mark[-2].pn->n_oper != TNAME && !in_typedef ) {
					insert_name(yystack.l_mark[-2].pn,Ctbl);
				}
				yyval.p = yystack.l_mark[-2].pn;
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			}
#line 5062 "y.tab.c"
break;
case 189:
#line 1956 "gram.y"
	{
				Pptr p = new ptr( RPTR, 0 );
				Ptyp(p) = new basetype(TYPE,yystack.l_mark[-5].pn);
				Freturns( yystack.l_mark[0].p ) = Ptype(p);
				yystack.l_mark[-2].pn->tp = yystack.l_mark[0].pt;
			/*SYM -- insert in table if not done elsewhere...*/
				if ( yystack.l_mark[-2].pn->n_oper != TNAME && !in_typedef ) {
					insert_name(yystack.l_mark[-2].pn,Ctbl);
				}
				yyval.p = yystack.l_mark[-2].pn;
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			}
#line 5078 "y.tab.c"
break;
case 190:
#line 1969 "gram.y"
	{	Pname n = yystack.l_mark[-3].pn;
				yyval.p = Ncopy(yystack.l_mark[-3].pn);
				/*??? what about qualified tname?*/
				/*SYM -- change -- do not if ctor def...*/
			/*XXXXX defer until name::normalize()?*/
				if ( !in_typedef
				&&  (ccl==0 || strcmp(n->string,ccl->string)) )
					n->hide();
				yyval.pn->n_oper = TNAME;
				yyval.pn->tp = new fct(0,yystack.l_mark[-1].pn,1);
			}
#line 5093 "y.tab.c"
break;
case 191:
#line 1981 "gram.y"
	{ /* function with no argument */
				Pname n = yystack.l_mark[-3].pn;
				yyval.p = Ncopy(yystack.l_mark[-3].pn);
				/*SYM -- change -- do not if ctor def...*/
				if ( !in_typedef
				&&  (ccl==0 || strcmp(n->string,ccl->string)) )
					n->hide();
 				yyval.pn->n_oper = TNAME;
 				yyval.pn->tp = new fct(0,0,1);
 				Pfct(yyval.pn->tp)->f_const = (yystack.l_mark[0].i & 1);
			}
#line 5108 "y.tab.c"
break;
case 192:
#line 1993 "gram.y"
	{	memptrdcl(yystack.l_mark[-3].pn,yystack.l_mark[-5].pn,yystack.l_mark[0].pt,yystack.l_mark[-2].pn);
				yyval.p = yystack.l_mark[-2].p;
			}
#line 5115 "y.tab.c"
break;
case 193:
#line 1997 "gram.y"
	{/*SYM -- insert in table if appropriate...*/
			 /*SYM    n_oper == TNAME => tname already hidden*/
			 /*SYM    other !=0 values of n_oper => op or dtor*/
			 /*SYM -- enter non-oper names as well as TNAMEs*/
			 /*SYM    in parsing table to handle "1.5 namespace"*/
			 /*SYM    in all scopes, since dcl does not build*/
			 /*SYM    the complete table until after functions*/
			 /*SYM    / classdefs are parsed.*/
			 /*SYM friends are processed in norm.c*/
			 /*SYM    to handle 'friend x;' etc*/
				if ( yystack.l_mark[0].pn->n_oper == 0
				&&  !in_typedef && !in_friend ) {
				    /*SYM do not hide ctor name...*/
				    if ( ccl==0 || parsing_class_members==0
				    ||   strcmp(ccl->string,yystack.l_mark[0].pn->string)) {
					Pname n = new name; *n = *yystack.l_mark[0].pn;
					insert_name(n,Ctbl);
				    }
				}
			}
#line 5139 "y.tab.c"
break;
case 194:
#line 2018 "gram.y"
	{	yyval.p = Ncopy(yystack.l_mark[0].pn);
				/*$<pn>$->n_qualifier = $1;*/
				error("`.' used for qualification; please use `::'");
			}
#line 5147 "y.tab.c"
break;
case 195:
#line 2023 "gram.y"
	{	yyval.p = yystack.l_mark[0].p;
				/*SYM if ( $<pn>1 != sta_name ) {*/
    				/*SYM	set_scope($<pn>1);*/
					if ( yystack.l_mark[-1].pn == sta_name
    					&&   yyval.pn->n_oper==DTOR )
						error("bad syntax for destructor ::%n",yyval.pn);
    					yyval.pn->n_qualifier = yystack.l_mark[-1].pn;
				/*SYM }*/
			}
#line 5160 "y.tab.c"
break;
case 196:
#line 2033 "gram.y"
	{	yyval.p = Ncopy(yystack.l_mark[0].pn);
				/*$<pn>$->n_qualifier = $<pn>1;//SYM $2;*/
				error("`.' used for qualification; please use `::'");
				error("non-type qualifier%n",yystack.l_mark[-2].pn);
				/*if ( $<pn>1 != sta_name ) {*/
    				/*SYM	set_scope($<pn>1);*/
    				/*	$<pn>2->n_qualifier = $<pn>1;*/
				/*}*/
			}
#line 5173 "y.tab.c"
break;
case 197:
#line 2043 "gram.y"
	{	Ptyp(yystack.l_mark[-1].p) = yystack.l_mark[0].pn->tp;
				yystack.l_mark[0].pn->tp = yystack.l_mark[-1].pt;
				yyval.p = yystack.l_mark[0].p;
			}
#line 5181 "y.tab.c"
break;
case 198:
#line 2048 "gram.y"
	{	yyval.p = Ncopy(yystack.l_mark[0].pn);
				/*??? what about qualified tnames?*/
				yyval.pn->n_oper = TNAME;
				/* cannot evaluate at this point: defer until data_dcl*/
				if ( !in_typedef ) yystack.l_mark[0].pn->hide();/*SYM*/
				else in_tag = yystack.l_mark[0].pn;/*SYM???*/
				yyval.pn->tp = yystack.l_mark[-1].pt;
			}
#line 5193 "y.tab.c"
break;
case 199:
#line 2057 "gram.y"
	{	yyval.p = Ncopy(yystack.l_mark[-1].pn);
				/*??? what about qualified tnames?*/
				yyval.pn->n_oper = TNAME;
				if ( !in_typedef ) yystack.l_mark[-1].pn->hide();/*SYM*/
				else in_tag = yystack.l_mark[-1].pn;/*SYM???*/
				yyval.pn->tp = yystack.l_mark[0].pt;
			}
#line 5204 "y.tab.c"
break;
case 200:
#line 2065 "gram.y"
	{	Vtype(yystack.l_mark[0].p) = yystack.l_mark[-1].pn->tp;
				yystack.l_mark[-1].pn->tp = yystack.l_mark[0].pt;
			}
#line 5211 "y.tab.c"
break;
case 201:
#line 2082 "gram.y"
	{
				yyval.p = yystack.l_mark[-1].p;
				in_arg_list = 0;
				hoist_al();/*SYM end_al($1,0);*/
				/*RESTORE_STATE();*/
			}
#line 5221 "y.tab.c"
break;
case 202:
#line 2091 "gram.y"
	{/*SYM -- insert in table if not done elsewhere...*/
				if ( yystack.l_mark[0].pn->n_oper != TNAME ) {
					Pname n = new name; *n = *yystack.l_mark[0].pn;
					insert_name(n,Ctbl);
				}
				yyval.p = yystack.l_mark[0].pn;
			}
#line 5232 "y.tab.c"
break;
case 203:
#line 2099 "gram.y"
	{	yyval.p = Ncopy(yystack.l_mark[0].pn);
				yyval.pn->n_oper = TNAME;
				yystack.l_mark[0].pn->hide();
				yyval.pn->tp = yystack.l_mark[-1].pt;
			}
#line 5241 "y.tab.c"
break;
case 204:
#line 2105 "gram.y"
	{
				yyval.p = new name;
				NOT_EXPECT_ID();
			}
#line 5249 "y.tab.c"
break;
case 205:
#line 2110 "gram.y"
	{	Ptyp(yystack.l_mark[-1].p) = yystack.l_mark[0].pn->tp;
				yystack.l_mark[0].pn->tp = (Ptype)yystack.l_mark[-1].p;
				yyval.p = yystack.l_mark[0].p;
			}
#line 5257 "y.tab.c"
break;
case 206:
#line 2115 "gram.y"
	{	Vtype(yystack.l_mark[0].p) = yystack.l_mark[-1].pn->tp;
				yystack.l_mark[-1].pn->tp = (Ptype)yystack.l_mark[0].p;
			}
#line 5264 "y.tab.c"
break;
case 207:
#line 2119 "gram.y"
	{	Freturns(yystack.l_mark[0].p) = yystack.l_mark[-1].pn->tp;
				yystack.l_mark[-1].pn->tp = (Ptype)yystack.l_mark[0].p;
			}
#line 5271 "y.tab.c"
break;
case 208:
#line 2135 "gram.y"
	{
/* error('d', "arg_lp arg_decl rp in_arg_list: %d", in_arg_list );*/
				yyval.p = yystack.l_mark[-1].p;
				in_arg_list = 0;
				hoist_al();/*SYM end_al($1,0);*/
				/*RESTORE_STATE();*/
			}
#line 5282 "y.tab.c"
break;
case 209:
#line 2145 "gram.y"
	{	yyval.p = new name; }
#line 5287 "y.tab.c"
break;
case 210:
#line 2147 "gram.y"
	{	Ptyp(yystack.l_mark[-1].p) = yystack.l_mark[0].pn->tp;
				yystack.l_mark[0].pn->tp = (Ptype)yystack.l_mark[-1].p;
				yyval.p = yystack.l_mark[0].p;
                                NOT_EXPECT_ID();
			}
#line 5296 "y.tab.c"
break;
case 211:
#line 2153 "gram.y"
	{	Vtype(yystack.l_mark[0].p) = yystack.l_mark[-1].pn->tp;
				yystack.l_mark[-1].pn->tp = (Ptype)yystack.l_mark[0].p;
			}
#line 5303 "y.tab.c"
break;
case 212:
#line 2158 "gram.y"
	{ yyval.p = new name; }
#line 5308 "y.tab.c"
break;
case 213:
#line 2160 "gram.y"
	{	Ptyp(yystack.l_mark[-1].p) = yystack.l_mark[0].pn->tp;
				yystack.l_mark[0].pn->tp = (Ptype)yystack.l_mark[-1].p;
				yyval.p = yystack.l_mark[0].p;
				NOT_EXPECT_ID();
			}
#line 5317 "y.tab.c"
break;
case 214:
#line 2166 "gram.y"
	{	Vtype(yystack.l_mark[0].p) = yystack.l_mark[-1].pn->tp;
				yystack.l_mark[-1].pn->tp = (Ptype)yystack.l_mark[0].p;
			}
#line 5324 "y.tab.c"
break;
case 215:
#line 2170 "gram.y"
	{	Freturns(yystack.l_mark[0].p) = yystack.l_mark[-2].pn->tp;
				yystack.l_mark[-2].pn->tp = yystack.l_mark[0].pt;
				yyval.p = yystack.l_mark[-2].p;
			}
#line 5332 "y.tab.c"
break;
case 216:
#line 2175 "gram.y"
	{	Vtype(yystack.l_mark[0].p) = yystack.l_mark[-2].pn->tp;
				yystack.l_mark[-2].pn->tp = yystack.l_mark[0].pt;
				yyval.p = yystack.l_mark[-2].p;
			}
#line 5340 "y.tab.c"
break;
case 217:
#line 2182 "gram.y"
	{	yyval.p = new name; }
#line 5345 "y.tab.c"
break;
case 218:
#line 2184 "gram.y"
	{	Ptyp(yystack.l_mark[-1].p) = yystack.l_mark[0].pn->tp;
				yystack.l_mark[0].pn->tp = (Ptype)yystack.l_mark[-1].p;
				yyval.p = yystack.l_mark[0].p;
			}
#line 5353 "y.tab.c"
break;
case 219:
#line 2194 "gram.y"
	{
				yyval.p = 0;
			}
#line 5360 "y.tab.c"
break;
case 220:
#line 2198 "gram.y"
	{
				error( "ZizedTD must be atG, not local scope" );
				error('i', "cannot recover from previous error" );
			}
#line 5368 "y.tab.c"
break;
case 221:
#line 2203 "gram.y"
	{
				if (yystack.l_mark[0].p)
					if (yystack.l_mark[-1].p)
						yystack.l_mark[-1].sl->add(yystack.l_mark[0].ps);
					else {
						yyval.sl =  new slist(yystack.l_mark[0].ps);
						stmt_seen = 1;
					}
			}
#line 5381 "y.tab.c"
break;
case 222:
#line 2214 "gram.y"
	{
				yyval.p = yystack.l_mark[0].p;
				if (yystack.l_mark[0].p)	stmt_seen = 1;
			}
#line 5389 "y.tab.c"
break;
case 223:
#line 2221 "gram.y"
	{
				yyval.p = 0;
				check_decl();
			}
#line 5397 "y.tab.c"
break;
case 224:
#line 2228 "gram.y"
	{	yyval.p = yystack.l_mark[-1].p;
			/*	if ($<pe>$ == dummy) error("empty condition");*/
				stmt_seen = 1;
			}
#line 5405 "y.tab.c"
break;
case 225:
#line 2235 "gram.y"
	{	PUSH_BLOCK_SCOPE();/*SYM*/
				cd_vec[cdi] = cd;
				stmt_vec[cdi] = stmt_seen;
				++cdi;
				cd = 0;
				stmt_seen = 0;
				/*SYM -- tn stuff removed*/
			}
#line 5417 "y.tab.c"
break;
case 226:
#line 2244 "gram.y"
	{	Pname n = name_unlist(cd);
				Pstmt ss = stmt_unlist(yystack.l_mark[-1].sl);
				yyval.p = new block(yystack.l_mark[-3].l,n,ss,yystack.l_mark[0].l);
				/*SYM -- tn stuff removed*/
				cd = cd_vec[--cdi];
				stmt_seen = stmt_vec[cdi];
				if (cdi < 0) error('i',"block level(%d)",cdi);
				NOT_EXPECT_ID();
				yyval.ps->k_tbl = Ctbl;/*SYM*/
                        	POP_SCOPE();/*SYM*/
			}
#line 5432 "y.tab.c"
break;
case 227:
#line 2256 "gram.y"
	{ yyval.p = new block(yystack.l_mark[-1].l,0,0,yystack.l_mark[0].l); NOT_EXPECT_ID();
			  if ( Ctbl->k_id == ARG ) POP_SCOPE();/*SYM*/
			}
#line 5439 "y.tab.c"
break;
case 228:
#line 2260 "gram.y"
	{ yyval.p = new block(yystack.l_mark[-2].l,0,0,yystack.l_mark[0].l); NOT_EXPECT_ID();
			  if ( Ctbl->k_id == ARG ) POP_SCOPE();/*SYM*/
			}
#line 5446 "y.tab.c"
break;
case 229:
#line 2266 "gram.y"
	{	yyval.p = new estmt(SM,curloc,yystack.l_mark[0].pe,0);	}
#line 5451 "y.tab.c"
break;
case 230:
#line 2268 "gram.y"
	{	yyval.p = new stmt(BREAK,yystack.l_mark[0].l,0); }
#line 5456 "y.tab.c"
break;
case 231:
#line 2270 "gram.y"
	{	yyval.p = new stmt(CONTINUE,yystack.l_mark[0].l,0); }
#line 5461 "y.tab.c"
break;
case 232:
#line 2272 "gram.y"
	{	yyval.p = new lstmt(GOTO,yystack.l_mark[-1].l,yystack.l_mark[0].pn,0); }
#line 5466 "y.tab.c"
break;
case 233:
#line 2273 "gram.y"
	{ stmt_seen=1; }
#line 5471 "y.tab.c"
break;
case 234:
#line 2274 "gram.y"
	{	yyval.p = new estmt(DO,yystack.l_mark[-4].l,yystack.l_mark[0].pe,yystack.l_mark[-2].ps); }
#line 5476 "y.tab.c"
break;
case 235:
#line 2276 "gram.y"
	{
				if (stmt_seen)
					yyval.p = new estmt(ASM,curloc,(Pexpr)yystack.l_mark[-1].s,0);
				else {
					Pname n = new name(make_name('A'));
					n->tp = new basetype(ASM,(Pname)yystack.l_mark[-1].s);
					if (cd)
						cd->add_list(n);
					else
						cd = new nlist(n);
					yyval.p = 0;
				}
			}
#line 5493 "y.tab.c"
break;
case 236:
#line 2291 "gram.y"
	{
			if ( NEXTTOK() != SM ) {
				error("`;' missing afterS");
				la_backup(yychar,yylval);
				yychar = SM;
			}
		  }
#line 5504 "y.tab.c"
break;
case 239:
#line 2302 "gram.y"
	{	yyval.p = new estmt(SM,curloc,dummy,0); }
#line 5509 "y.tab.c"
break;
case 240:
#line 2304 "gram.y"
	{	yyval.p = new estmt(RETURN,yystack.l_mark[-2].l,yystack.l_mark[-1].pe,0); }
#line 5514 "y.tab.c"
break;
case 241:
#line 2306 "gram.y"
	{
				error("local linkage specification");
				yyval.p = yystack.l_mark[0].pn;
			}
#line 5522 "y.tab.c"
break;
case 242:
#line 2311 "gram.y"
	{	Pname n = yystack.l_mark[0].pn;
				if (n) {
/*error('d',"adding local dcl of%n%t ll %d in_typedef%t",n,n->tp,n->lex_level,in_typedef);*/
					if (stmt_seen) {
						yyval.p = new block(n->where,n,0);
						yyval.ps->base = DCL;
						yyval.ps->k_tbl = Ctbl;/*SYM*/
					}
					else {
						if (cd)
							cd->add_list(n);
						else
							cd = new nlist(n);
						yyval.p = 0;
					}
				} /* if n*/
				else if (stmt_seen) {
					yyval.p = new block(curloc,0,0);
					yyval.ps->base = FDCL;
				}
			}
#line 5547 "y.tab.c"
break;
case 243:
#line 2333 "gram.y"
	{
				Pname n = yystack.l_mark[0].pn;
				if (!templp->in_progress)
					error(&n->where,"%n's definition is nested (did you forget a ``}''?)",n);
				if (cd)
					cd->add_list(n);
				else
					cd = new nlist(n);
				yyval.p = 0;
			}
#line 5561 "y.tab.c"
break;
case 245:
#line 2345 "gram.y"
	{	yyval.p = new ifstmt(yystack.l_mark[-2].l,yystack.l_mark[-1].pe,yystack.l_mark[0].ps,0); }
#line 5566 "y.tab.c"
break;
case 246:
#line 2347 "gram.y"
	{	yyval.p = new ifstmt(yystack.l_mark[-4].l,yystack.l_mark[-3].pe,yystack.l_mark[-2].ps,yystack.l_mark[0].ps); }
#line 5571 "y.tab.c"
break;
case 247:
#line 2349 "gram.y"
	{	yyval.p = new estmt(WHILE,yystack.l_mark[-2].l,yystack.l_mark[-1].pe,yystack.l_mark[0].ps); }
#line 5576 "y.tab.c"
break;
case 248:
#line 2350 "gram.y"
	{ stmt_seen=1; }
#line 5581 "y.tab.c"
break;
case 249:
#line 2351 "gram.y"
	{	yyval.p = new forstmt(yystack.l_mark[-8].l,yystack.l_mark[-5].ps,yystack.l_mark[-4].pe,yystack.l_mark[-2].pe,yystack.l_mark[0].ps); }
#line 5586 "y.tab.c"
break;
case 250:
#line 2352 "gram.y"
	{ scd[++scdp] = cd;}
#line 5591 "y.tab.c"
break;
case 251:
#line 2353 "gram.y"
	{
				--scdp;
				yyval.p = new estmt(SWITCH,yystack.l_mark[-3].l,yystack.l_mark[-1].pe,yystack.l_mark[0].ps);
			}
#line 5599 "y.tab.c"
break;
case 252:
#line 2357 "gram.y"
	{ yyval.pn = yystack.l_mark[-1].pn; stmt_seen=1; }
#line 5604 "y.tab.c"
break;
case 253:
#line 2358 "gram.y"
	{	Pname n = yystack.l_mark[-1].pn;
				yyval.p = new lstmt(LABEL,n->where,n,yystack.l_mark[0].ps);
			}
#line 5611 "y.tab.c"
break;
case 254:
#line 2361 "gram.y"
	{ yyval.pn = new name(yystack.l_mark[-1].pn->string); stmt_seen=1; }
#line 5616 "y.tab.c"
break;
case 255:
#line 2362 "gram.y"
	{	Pname n = yystack.l_mark[-1].pn;
				yyval.p = new lstmt(LABEL,n->where,n,yystack.l_mark[0].ps);
			}
#line 5623 "y.tab.c"
break;
case 256:
#line 2365 "gram.y"
	{ stmt_seen=1; }
#line 5628 "y.tab.c"
break;
case 257:
#line 2366 "gram.y"
	{
				if (scdp>=0 && scd[scdp]!=cd && cd && decl_with_init(cd)) error("jump past initializer (did you forget a '{ }'?)");
				if (yystack.l_mark[-2].pe == dummy) error("empty case label");
				yyval.p = new estmt(CASE,yystack.l_mark[-4].l,yystack.l_mark[-2].pe,yystack.l_mark[0].ps);
			}
#line 5637 "y.tab.c"
break;
case 258:
#line 2371 "gram.y"
	{ stmt_seen=1; }
#line 5642 "y.tab.c"
break;
case 259:
#line 2372 "gram.y"
	{
				if (scdp>=0 && scd[scdp]!=cd && cd && yystack.l_mark[-1].pe && decl_with_init(cd)) error("jump past initializer (did you forget a '{ }'?)");
				yyval.p = new stmt(DEFAULT,yystack.l_mark[-3].l,yystack.l_mark[0].ps);
			}
#line 5650 "y.tab.c"
break;
case 260:
#line 2377 "gram.y"
	{ yyval.p = new handler( yystack.l_mark[-1].ps, stmt_unlist(yystack.l_mark[0].sl) ); }
#line 5655 "y.tab.c"
break;
case 261:
#line 2382 "gram.y"
	{ yyval.sl = 0; }
#line 5660 "y.tab.c"
break;
case 262:
#line 2384 "gram.y"
	{
				if (yystack.l_mark[0].ps)
					if (yystack.l_mark[-1].sl)
						yystack.l_mark[-1].sl->add(yystack.l_mark[0].ps);
					else {
						yyval.sl =  new slist(yystack.l_mark[0].ps);
						stmt_seen = 1;
					}
			}
#line 5673 "y.tab.c"
break;
case 263:
#line 2396 "gram.y"
	{
			    if ( yystack.l_mark[-1].pn ) {
				yystack.l_mark[-1].pn->n_list = yystack.l_mark[0].ps->d;
				yystack.l_mark[0].ps->d = yystack.l_mark[-1].pn;
			    }
			    yyval.ps = yystack.l_mark[0].ps;
			}
#line 5684 "y.tab.c"
break;
case 264:
#line 2407 "gram.y"
	{	in_arg_list = 0;
				yyval.pn = Ndata(yystack.l_mark[-2].p,yystack.l_mark[-1].pn);
				if ( yyval.pn->string == 0 )
					yyval.pn = 0;
				else
					yyval.pn->base = CATCH;
			}
#line 5695 "y.tab.c"
break;
case 265:
#line 2415 "gram.y"
	{ yyval.pn = 0; }
#line 5700 "y.tab.c"
break;
case 266:
#line 2422 "gram.y"
	{	Pexpr e = expr_unlist(yystack.l_mark[0].el);
				while (e && e->e1==dummy) {
					/*register*/ Pexpr ee2 = e->e2;
					if (ee2) error("EX inEL");
					delete e;
					e = ee2;
				}
				yyval.p = e;
			}
#line 5713 "y.tab.c"
break;
case 267:
#line 2434 "gram.y"
	{	yyval.el = new elist(new expr(ELIST,yystack.l_mark[0].pe,0)); }
#line 5718 "y.tab.c"
break;
case 268:
#line 2436 "gram.y"
	{	yystack.l_mark[-2].el->add(new expr(ELIST,yystack.l_mark[0].pe,0)); }
#line 5723 "y.tab.c"
break;
case 270:
#line 2441 "gram.y"
	{
  			  	if ( in_arg_list )
       			  		error( "syntax error: IrL not permitted in AL" );
				else if ( in_binit_list )
					error( "syntax error: IrL not permitted inMIr" );
  			  	else
					init_seen = 1;
				Pexpr e;
				if (yystack.l_mark[-1].p)
					e = yystack.l_mark[-1].pe;
				else
					e = new expr(ELIST,dummy,0);
				yyval.p = new expr(ILIST,e,0);
			}
#line 5741 "y.tab.c"
break;
case 271:
#line 2458 "gram.y"
	{	bbinop:	yyval.p = new expr(yystack.l_mark[-1].t,yystack.l_mark[-2].pe,yystack.l_mark[0].pe); }
#line 5746 "y.tab.c"
break;
case 272:
#line 2459 "gram.y"
	{	goto bbinop; }
#line 5751 "y.tab.c"
break;
case 273:
#line 2460 "gram.y"
	{	goto bbinop; }
#line 5756 "y.tab.c"
break;
case 274:
#line 2461 "gram.y"
	{	goto bbinop; }
#line 5761 "y.tab.c"
break;
case 275:
#line 2462 "gram.y"
	{	goto bbinop; }
#line 5766 "y.tab.c"
break;
case 276:
#line 2463 "gram.y"
	{	goto bbinop; }
#line 5771 "y.tab.c"
break;
case 277:
#line 2464 "gram.y"
	{	goto bbinop; }
#line 5776 "y.tab.c"
break;
case 278:
#line 2465 "gram.y"
	{ 	goto bbinop; }
#line 5781 "y.tab.c"
break;
case 279:
#line 2466 "gram.y"
	{	goto bbinop; }
#line 5786 "y.tab.c"
break;
case 280:
#line 2467 "gram.y"
	{	goto bbinop; }
#line 5791 "y.tab.c"
break;
case 281:
#line 2468 "gram.y"
	{	goto bbinop; }
#line 5796 "y.tab.c"
break;
case 282:
#line 2469 "gram.y"
	{	goto bbinop; }
#line 5801 "y.tab.c"
break;
case 283:
#line 2470 "gram.y"
	{	goto bbinop; }
#line 5806 "y.tab.c"
break;
case 284:
#line 2471 "gram.y"
	{	goto bbinop; }
#line 5811 "y.tab.c"
break;
case 285:
#line 2472 "gram.y"
	{	goto bbinop; }
#line 5816 "y.tab.c"
break;
case 286:
#line 2473 "gram.y"
	{	goto bbinop; }
#line 5821 "y.tab.c"
break;
case 287:
#line 2474 "gram.y"
	{	goto bbinop; }
#line 5826 "y.tab.c"
break;
case 288:
#line 2476 "gram.y"
	{	yyval.p = new qexpr(yystack.l_mark[-4].pe,yystack.l_mark[-2].pe,yystack.l_mark[0].pe); }
#line 5831 "y.tab.c"
break;
case 289:
#line 2478 "gram.y"
	{	yyval.p = new expr(yystack.l_mark[-1].t,yystack.l_mark[-2].pe,yystack.l_mark[0].pe); }
#line 5836 "y.tab.c"
break;
case 290:
#line 2480 "gram.y"
	{ yyval.p = new expr(DELETE,yystack.l_mark[0].pe,0); }
#line 5841 "y.tab.c"
break;
case 291:
#line 2482 "gram.y"
	{
				if(yystack.l_mark[-2].pe != dummy) {
					if ( warning_opt || strict_opt )
						error(strict_opt?0:'w',"v in `delete[v]' is redundant; use `delete[] instead (anachronism)");
				}
				yyval.p = new expr(DELETE,yystack.l_mark[0].pe,yystack.l_mark[-2].pe);
			}
#line 5852 "y.tab.c"
break;
case 292:
#line 2490 "gram.y"
	{	yyval.p = new expr(GDELETE,yystack.l_mark[0].pe,0); }
#line 5857 "y.tab.c"
break;
case 293:
#line 2492 "gram.y"
	{
				if(yystack.l_mark[-2].pe != dummy) {
					if ( warning_opt || strict_opt )
						error(strict_opt?0:'w',"v in `::delete[v]' is redundant; use `::delete[] instead (anachronism)");
				}
				yyval.p = new expr(DELETE,yystack.l_mark[0].pe,yystack.l_mark[-2].pe);
			}
#line 5868 "y.tab.c"
break;
case 295:
#line 2501 "gram.y"
	{ yyval.p = dummy; }
#line 5873 "y.tab.c"
break;
case 296:
#line 2505 "gram.y"
	{	binop:	yyval.p = new expr(yystack.l_mark[-1].t,yystack.l_mark[-2].pe,yystack.l_mark[0].pe); }
#line 5878 "y.tab.c"
break;
case 297:
#line 2506 "gram.y"
	{	goto binop; }
#line 5883 "y.tab.c"
break;
case 298:
#line 2507 "gram.y"
	{	goto binop; }
#line 5888 "y.tab.c"
break;
case 299:
#line 2508 "gram.y"
	{	goto binop; }
#line 5893 "y.tab.c"
break;
case 300:
#line 2509 "gram.y"
	{	goto binop; }
#line 5898 "y.tab.c"
break;
case 301:
#line 2510 "gram.y"
	{	goto binop; }
#line 5903 "y.tab.c"
break;
case 302:
#line 2511 "gram.y"
	{	goto binop; }
#line 5908 "y.tab.c"
break;
case 303:
#line 2512 "gram.y"
	{ 	goto binop; }
#line 5913 "y.tab.c"
break;
case 304:
#line 2513 "gram.y"
	{	goto binop; }
#line 5918 "y.tab.c"
break;
case 305:
#line 2514 "gram.y"
	{	goto binop; }
#line 5923 "y.tab.c"
break;
case 306:
#line 2515 "gram.y"
	{	goto binop; }
#line 5928 "y.tab.c"
break;
case 307:
#line 2516 "gram.y"
	{	goto binop; }
#line 5933 "y.tab.c"
break;
case 308:
#line 2517 "gram.y"
	{	goto binop; }
#line 5938 "y.tab.c"
break;
case 309:
#line 2518 "gram.y"
	{	goto binop; }
#line 5943 "y.tab.c"
break;
case 310:
#line 2519 "gram.y"
	{	goto binop; }
#line 5948 "y.tab.c"
break;
case 311:
#line 2520 "gram.y"
	{	goto binop; }
#line 5953 "y.tab.c"
break;
case 312:
#line 2521 "gram.y"
	{	goto binop; }
#line 5958 "y.tab.c"
break;
case 313:
#line 2523 "gram.y"
	{	yyval.p = new qexpr(yystack.l_mark[-4].pe,yystack.l_mark[-2].pe,yystack.l_mark[0].pe); }
#line 5963 "y.tab.c"
break;
case 314:
#line 2525 "gram.y"
	{	yyval.p = new expr(yystack.l_mark[-1].t,yystack.l_mark[-2].pe,yystack.l_mark[0].pe); }
#line 5968 "y.tab.c"
break;
case 315:
#line 2527 "gram.y"
	{	yyval.p = new expr(DELETE,yystack.l_mark[0].pe,0); }
#line 5973 "y.tab.c"
break;
case 316:
#line 2529 "gram.y"
	{
				if(yystack.l_mark[-2].pe != dummy) {
					if ( warning_opt || strict_opt )
						error(strict_opt?0:'w',"v in `delete[v]' is redundant; use `delete[] instead (anachronism)");
				}
				yyval.p = new expr(DELETE,yystack.l_mark[0].pe,yystack.l_mark[-2].pe);
			}
#line 5984 "y.tab.c"
break;
case 317:
#line 2537 "gram.y"
	{	yyval.p = new expr(GDELETE,yystack.l_mark[0].pe,0); }
#line 5989 "y.tab.c"
break;
case 318:
#line 2539 "gram.y"
	{
				if(yystack.l_mark[-2].pe != dummy) {
					if ( warning_opt || strict_opt )
						error(strict_opt?0:'w',"v in `::delete[v]' is redundant; use `::delete[] instead (anachronism)");
				}
				yyval.p = new expr(DELETE,yystack.l_mark[0].pe,yystack.l_mark[-2].pe);
			}
#line 6000 "y.tab.c"
break;
case 319:
#line 2546 "gram.y"
	{
			init_seen = 0;
			}
#line 6007 "y.tab.c"
break;
case 320:
#line 2550 "gram.y"
	{ yyval.p = dummy; }
#line 6012 "y.tab.c"
break;
case 321:
#line 2552 "gram.y"
	{	yyval.p = dummy; }
#line 6017 "y.tab.c"
break;
case 322:
#line 2555 "gram.y"
	{ goto new1; }
#line 6022 "y.tab.c"
break;
case 323:
#line 2557 "gram.y"
	{	new1:
				Ptype t = yystack.l_mark[0].pn->tp;
				yyval.p = new texpr(NEW,t,0);
				--in_new;
			}
#line 6031 "y.tab.c"
break;
case 324:
#line 2562 "gram.y"
	{ goto new3; }
#line 6036 "y.tab.c"
break;
case 325:
#line 2564 "gram.y"
	{	new3:
				Ptype t = yystack.l_mark[0].pn->tp;
 				yyval.p = new texpr(GNEW,t,0);
				--in_new;
 			}
#line 6045 "y.tab.c"
break;
case 326:
#line 2570 "gram.y"
	{	yyval.p = new expr(yystack.l_mark[0].t,yystack.l_mark[-1].pe,0); }
#line 6050 "y.tab.c"
break;
case 327:
#line 2572 "gram.y"
	{
				yyval.p = new texpr(CAST,yystack.l_mark[-1].pn->tp,yystack.l_mark[0].pe);
			}
#line 6057 "y.tab.c"
break;
case 328:
#line 2576 "gram.y"
	{	yyval.p = new expr(DEREF,yystack.l_mark[0].pe,0); }
#line 6062 "y.tab.c"
break;
case 329:
#line 2578 "gram.y"
	{	yyval.p = new expr(ADDROF,0,yystack.l_mark[0].pe); }
#line 6067 "y.tab.c"
break;
case 330:
#line 2580 "gram.y"
	{	yyval.p = new expr(UMINUS,0,yystack.l_mark[0].pe); }
#line 6072 "y.tab.c"
break;
case 331:
#line 2582 "gram.y"
	{	yyval.p = new expr(UPLUS,0,yystack.l_mark[0].pe); }
#line 6077 "y.tab.c"
break;
case 332:
#line 2584 "gram.y"
	{	yyval.p = new expr(NOT,0,yystack.l_mark[0].pe); }
#line 6082 "y.tab.c"
break;
case 333:
#line 2586 "gram.y"
	{	yyval.p = new expr(COMPL,0,yystack.l_mark[0].pe); }
#line 6087 "y.tab.c"
break;
case 334:
#line 2588 "gram.y"
	{	yyval.p = new expr(yystack.l_mark[-1].t,0,yystack.l_mark[0].pe); }
#line 6092 "y.tab.c"
break;
case 335:
#line 2590 "gram.y"
	{
				yyval.p = new texpr(SIZEOF,0,yystack.l_mark[0].pe);
				--in_sizeof;
			}
#line 6100 "y.tab.c"
break;
case 336:
#line 2595 "gram.y"
	{
				yyval.p = new texpr(SIZEOF,yystack.l_mark[0].pn->tp,0);
				--in_sizeof;
			}
#line 6108 "y.tab.c"
break;
case 337:
#line 2600 "gram.y"
	{	yyval.p = new expr(DEREF,yystack.l_mark[-3].pe,yystack.l_mark[-1].pe); }
#line 6113 "y.tab.c"
break;
case 338:
#line 2602 "gram.y"
	{	yyval.p = new ref(REF,yystack.l_mark[-2].pe,yystack.l_mark[0].pn); }
#line 6118 "y.tab.c"
break;
case 339:
#line 2604 "gram.y"
	{
				yystack.l_mark[0].pn->n_qualifier = yystack.l_mark[-1].pn;
				yyval.p = new ref(REF,yystack.l_mark[-3].pe,yystack.l_mark[0].pn);
			}
#line 6126 "y.tab.c"
break;
case 340:
#line 2609 "gram.y"
	{	yystack.l_mark[0].pn = new name(yystack.l_mark[0].pn->string);
				yystack.l_mark[0].pn->n_qualifier = yystack.l_mark[-1].pn;
				yyval.p = new ref(REF,yystack.l_mark[-3].pe,yystack.l_mark[0].pn);
			}
#line 6134 "y.tab.c"
break;
case 341:
#line 2614 "gram.y"
	{	yyval.p = new ref(REF,yystack.l_mark[-2].pe,yystack.l_mark[0].pn); }
#line 6139 "y.tab.c"
break;
case 342:
#line 2616 "gram.y"
	{ /* kluge to handle parameterized qualifiers, since*/
			  /*    they are not included in MEMQ*/
				yystack.l_mark[0].pn->n_qualifier = yystack.l_mark[-1].pn;
				yyval.p = new ref(REF,yystack.l_mark[-3].pe,yystack.l_mark[0].pn);
				if ( yystack.l_mark[-1].pn && yystack.l_mark[-1].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();
			}
#line 6150 "y.tab.c"
break;
case 343:
#line 2624 "gram.y"
	{ /* kluge to handle parameterized qualifiers, since*/
			  /*    they are not included in MEMQ*/
				yystack.l_mark[0].pn = new name(yystack.l_mark[0].pn->string);
				yystack.l_mark[0].pn->n_qualifier = yystack.l_mark[-1].pn;
				yyval.p = new ref(REF,yystack.l_mark[-3].pe,yystack.l_mark[0].pn);
				if ( yystack.l_mark[-1].pn && yystack.l_mark[-1].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();
			}
#line 6162 "y.tab.c"
break;
case 344:
#line 2633 "gram.y"
	{	yyval.p = new ref(DOT,yystack.l_mark[-2].pe,yystack.l_mark[0].pn); }
#line 6167 "y.tab.c"
break;
case 345:
#line 2635 "gram.y"
	{
				yystack.l_mark[0].pn->n_qualifier = yystack.l_mark[-1].pn;
				yyval.p = new ref(DOT,yystack.l_mark[-3].pe,yystack.l_mark[0].pn);
			}
#line 6175 "y.tab.c"
break;
case 346:
#line 2640 "gram.y"
	{	yystack.l_mark[0].pn = new name(yystack.l_mark[0].pn->string);
				yystack.l_mark[0].pn->n_qualifier = yystack.l_mark[-1].pn;
				yyval.p = new ref(DOT,yystack.l_mark[-3].pe,yystack.l_mark[0].pn);
			}
#line 6183 "y.tab.c"
break;
case 347:
#line 2645 "gram.y"
	{	yyval.p = new ref(DOT,yystack.l_mark[-2].pe,yystack.l_mark[0].pn); }
#line 6188 "y.tab.c"
break;
case 348:
#line 2647 "gram.y"
	{ /* kluge to handle parameterized qualifiers, since*/
			  /*    they are not included in MEMQ*/
				yystack.l_mark[0].pn->n_qualifier = yystack.l_mark[-1].pn;
				yyval.p = new ref(DOT,yystack.l_mark[-3].pe,yystack.l_mark[0].pn);
				if ( yystack.l_mark[-1].pn && yystack.l_mark[-1].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();
			}
#line 6199 "y.tab.c"
break;
case 349:
#line 2655 "gram.y"
	{ /* kluge to handle parameterized qualifiers, since*/
			  /*    they are not included in MEMQ*/
				yystack.l_mark[0].pn = new name(yystack.l_mark[0].pn->string);
				yystack.l_mark[0].pn->n_qualifier = yystack.l_mark[-1].pn;
				yyval.p = new ref(DOT,yystack.l_mark[-3].pe,yystack.l_mark[0].pn);
				if ( yystack.l_mark[-1].pn && yystack.l_mark[-1].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();
			}
#line 6211 "y.tab.c"
break;
case 351:
#line 2665 "gram.y"
	{ /* set scope to parse 'C::operator N' where N is in C*/
			  /* still does not handle 'p->operator N'*/
			  /*     (requires either fancier structures or*/
			  /*     on-the-fly type checking)*/
				yyval.p = Ncopy(yystack.l_mark[0].pn);
				yyval.pn->n_qualifier = yystack.l_mark[-1].pn;
				if ( yystack.l_mark[-1].pn && yystack.l_mark[-1].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();
			}
#line 6224 "y.tab.c"
break;
case 352:
#line 2675 "gram.y"
	{
				yyval.p = dummy_dtor();
				yyval.pn->n_qualifier = yystack.l_mark[-2].pn;
				yyval.pn->n_dtag = yystack.l_mark[0].pn;
			}
#line 6233 "y.tab.c"
break;
case 353:
#line 2681 "gram.y"
	{
				yyval.p = dummy_dtor( yystack.l_mark[0].t, yystack.l_mark[0].t );
				yyval.pn->n_qualifier = yystack.l_mark[-2].pn;
			}
#line 6241 "y.tab.c"
break;
case 354:
#line 2686 "gram.y"
	{
			if ( init_seen )
     				error( "syntax error:IrL illegal within ()");
			}
#line 6249 "y.tab.c"
break;
case 355:
#line 2692 "gram.y"
	{
				if ( yystack.l_mark[-1].p == dummy )
					error("syntax error: nullE");
				yyval.p = yystack.l_mark[-1].p;
			}
#line 6258 "y.tab.c"
break;
case 356:
#line 2698 "gram.y"
	{	yyval.p = zero; }
#line 6263 "y.tab.c"
break;
case 357:
#line 2700 "gram.y"
	{	yyval.p = new expr(ICON,0,0);
				yyval.pe->string = copy_if_need_be(yystack.l_mark[0].s);
			}
#line 6270 "y.tab.c"
break;
case 358:
#line 2704 "gram.y"
	{	yyval.p = new expr(FCON,0,0);
				yyval.pe->string = copy_if_need_be(yystack.l_mark[0].s);
			}
#line 6277 "y.tab.c"
break;
case 359:
#line 2708 "gram.y"
	{	yyval.p = new expr(STRING,0,0);
				yyval.pe->string = copy_if_need_be(yystack.l_mark[0].s);
			}
#line 6284 "y.tab.c"
break;
case 360:
#line 2712 "gram.y"
	{	yyval.p = new expr(CCON,0,0);
				yyval.pe->string = copy_if_need_be(yystack.l_mark[0].s);
			}
#line 6291 "y.tab.c"
break;
case 361:
#line 2716 "gram.y"
	{	yyval.p = new expr(THIS,0,0); }
#line 6296 "y.tab.c"
break;
case 362:
#line 2720 "gram.y"
	{
				yyval.p = dummy_dtor();
				yyval.pn->n_dtag = yystack.l_mark[0].pn; /* checked later*/
			}
#line 6304 "y.tab.c"
break;
case 363:
#line 2725 "gram.y"
	{
				yyval.p = dummy_dtor();
				yyval.pn->n_qualifier = yystack.l_mark[-2].pn; /* checked later*/
				yyval.pn->n_dtag = yystack.l_mark[0].pn; /* checked later*/
			}
#line 6313 "y.tab.c"
break;
case 364:
#line 2731 "gram.y"
	{ yyval.p = dummy_dtor(yystack.l_mark[-3].t,yystack.l_mark[0].t); }
#line 6318 "y.tab.c"
break;
case 365:
#line 2733 "gram.y"
	{ yyval.p = dummy_dtor(yystack.l_mark[0].t,yystack.l_mark[0].t); }
#line 6323 "y.tab.c"
break;
case 366:
#line 2735 "gram.y"
	{
				yyval.p = dummy_dtor( yystack.l_mark[-3].t, yystack.l_mark[-3].t );
				yyval.pn->n_dtag = yystack.l_mark[0].pn;
			}
#line 6331 "y.tab.c"
break;
case 367:
#line 2740 "gram.y"
	{
				yyval.p = dummy_dtor( yystack.l_mark[0].t, yystack.l_mark[0].t );
				yyval.pn->n_qualifier = yystack.l_mark[-2].pn;
			}
#line 6339 "y.tab.c"
break;
case 368:
#line 2745 "gram.y"
	{ /* kluge to parse parameterized qualifiers after ./->*/
				yyval.p = dummy_dtor();
				yyval.pn->n_qualifier = yystack.l_mark[-2].pn;
				yyval.pn->n_dtag = yystack.l_mark[0].pn;
			}
#line 6348 "y.tab.c"
break;
case 369:
#line 2751 "gram.y"
	{ /* kluge to parse parameterized qualifiers after ./->*/
				yyval.p = dummy_dtor( yystack.l_mark[0].t, yystack.l_mark[0].t );
				yyval.pn->n_qualifier = yystack.l_mark[-2].pn;
			}
#line 6356 "y.tab.c"
break;
case 370:
#line 2758 "gram.y"
	{ 	yyval.p = new texpr(VALUE,tok_to_type(yystack.l_mark[-3].t),yystack.l_mark[-1].pe); }
#line 6361 "y.tab.c"
break;
case 371:
#line 2763 "gram.y"
	{
				yyval.p = new texpr(VALUE,yystack.l_mark[-3].pn->tp,yystack.l_mark[-1].pe);
				if (yystack.l_mark[-3].pn->is_template_arg() && yystack.l_mark[-3].pn->tp->base == ANY) {
					yyval.pe->tp2 = new basetype(TYPE,yystack.l_mark[-3].pn);
				}
			}
#line 6371 "y.tab.c"
break;
case 372:
#line 2769 "gram.y"
	{ goto new2; }
#line 6376 "y.tab.c"
break;
case 373:
#line 2771 "gram.y"
	{	new2:
				Ptype t = yystack.l_mark[0].pn->tp;
				yyval.p=new texpr(NEW,t,0);
				yyval.pe->e2 = yystack.l_mark[-2].pe;
				--in_new;
			}
#line 6386 "y.tab.c"
break;
case 374:
#line 2777 "gram.y"
	{ goto new4; }
#line 6391 "y.tab.c"
break;
case 375:
#line 2779 "gram.y"
	{	new4:
				Ptype t = yystack.l_mark[0].pn->tp;
				yyval.p = new texpr(GNEW,t,0);
				yyval.pe->e2 = yystack.l_mark[-2].pe;
				--in_new;
			}
#line 6401 "y.tab.c"
break;
case 376:
#line 2786 "gram.y"
	{
				Pexpr ee = yystack.l_mark[-1].pe;
				Pexpr e = yystack.l_mark[-3].pe;
				if (e->base==NEW || e->base==GNEW)
					e->e1 = ee;
				else
					yyval.p = new call(e,ee);
			}
#line 6413 "y.tab.c"
break;
case 377:
#line 2798 "gram.y"
	{
			yyval.pn = parametrized_typename(yystack.l_mark[-3].pn,(expr_unlist(yystack.l_mark[-1].el)));
	 	 }
#line 6420 "y.tab.c"
break;
case 378:
#line 2803 "gram.y"
	{ yyval.pn = yystack.l_mark[0].pn; }
#line 6425 "y.tab.c"
break;
case 379:
#line 2804 "gram.y"
	{ yyval.pn = sta_name; }
#line 6430 "y.tab.c"
break;
case 380:
#line 2805 "gram.y"
	{ yyval.pn = yystack.l_mark[-1].pn; }
#line 6435 "y.tab.c"
break;
case 381:
#line 2810 "gram.y"
	{
				if ( in_arg_list && !in_binit_list ) {
				    Pktab tb = Ctbl;
				    for (; tb && tb->k_id==ARG; tb=tb->k_next) {
					if ( tb->look(yystack.l_mark[0].pn->string,0) ) {
						error("illegalR toA%n in defaultA",yystack.l_mark[0].pn);
						yystack.l_mark[0].pe = dummy;
						break;
					}
				    }
				}
				yyval.p = yystack.l_mark[0].pn;
			}
#line 6452 "y.tab.c"
break;
case 382:
#line 2824 "gram.y"
	{	yyval.p = new name(oper_name(yystack.l_mark[0].t));
				yyval.pn->n_oper = yystack.l_mark[0].t;
			}
#line 6459 "y.tab.c"
break;
case 383:
#line 2828 "gram.y"
	{	yyval.p = yystack.l_mark[0].p;
				sig_name(yyval.pn);
			}
#line 6466 "y.tab.c"
break;
case 384:
#line 2837 "gram.y"
	{
				yyval.p = Ncast(yystack.l_mark[-2].p,yystack.l_mark[-1].pn);
			}
#line 6473 "y.tab.c"
break;
case 385:
#line 2842 "gram.y"
	{ check_cast(); }
#line 6478 "y.tab.c"
break;
case 386:
#line 2846 "gram.y"
	{
				TOK t = yystack.l_mark[0].t;

				switch (t) {
				case FRIEND:
				case OVERLOAD:
				case REGISTER:
				case STATIC:
				case EXTERN:
				case AUTO:
				case VIRTUAL:
					error("%k in operatorT",t);
					t = INT;

				}

				yyval.p = new basetype(t,0);

			}
#line 6501 "y.tab.c"
break;
case 387:
#line 2865 "gram.y"
	{ yyval.p = new basetype(TYPE,yystack.l_mark[0].pn); }
#line 6506 "y.tab.c"
break;
case 388:
#line 2867 "gram.y"
	{
				if ( DECL_TYPE != -1 ) {
					switch (yystack.l_mark[-1].pb->base) {
					case COBJ: case EOBJ:
						{
						Pbase bt;
						bt = new basetype(0,0);
						*bt = *yystack.l_mark[-1].pb;
						DEL(yystack.l_mark[-1].pb);
						yystack.l_mark[-1].pb = bt;
						}
					}
					yyval.p = yystack.l_mark[-1].pb->type_adj(yystack.l_mark[0].t);
				}
				DECL_TYPE = 0;
			}
#line 6526 "y.tab.c"
break;
case 389:
#line 2884 "gram.y"
	{
				if ( DECL_TYPE != -1 )
			 		yyval.p = yystack.l_mark[-1].pb->name_adj(yystack.l_mark[0].pn);
				DECL_TYPE = 0;
			}
#line 6535 "y.tab.c"
break;
case 390:
#line 2891 "gram.y"
	{ yyval.p = Ncast(yystack.l_mark[-1].p,yystack.l_mark[0].pn); }
#line 6540 "y.tab.c"
break;
case 391:
#line 2894 "gram.y"
	{ yyval.p = Ncast(yystack.l_mark[-1].p,yystack.l_mark[0].pn); }
#line 6545 "y.tab.c"
break;
case 392:
#line 2897 "gram.y"
	{
                         /*      ENTER_NAME($<pn>2);*/
				yyval.p = Ndata(yystack.l_mark[-1].p,yystack.l_mark[0].pn);
			}
#line 6553 "y.tab.c"
break;
case 393:
#line 2902 "gram.y"
	{
                        /*      ENTER_NAME($<pn>2);*/
                        }
#line 6560 "y.tab.c"
break;
case 394:
#line 2906 "gram.y"
	{
				yyval.p = Ndata(yystack.l_mark[-4].p,yystack.l_mark[-3].pn);
                                yyval.pn->n_initializer = yystack.l_mark[0].pe;
                        }
#line 6568 "y.tab.c"
break;
case 395:
#line 2913 "gram.y"
	{	PUSH_ARG_SCOPE();/*SYM*/
				/*SAVE_STATE();*/
				in_arg_list=1;
				check_decl();
				yyval.pl = 0;
				/*SYM -- tn stuff removed*/
			}
#line 6579 "y.tab.c"
break;
case 396:
#line 2923 "gram.y"
	{
			yyval.p = new fct(0,name_unlist(yystack.l_mark[-3].nl),yystack.l_mark[-2].t);
			if ( NEXTTOK() != COLON ) in_arg_list=0;
			/*in_arg_list=0;*/
			Pfct(yyval.pt)->f_const = (yystack.l_mark[0].i & 1);
			/*SYM -- removed kluge*/
                        POP_SCOPE();/*SYM*/
			/*RESTORE_STATE();*/
		    }
#line 6592 "y.tab.c"
break;
case 397:
#line 2935 "gram.y"
	{
				if (yystack.l_mark[0].p)
					if (yystack.l_mark[-2].p)
						yystack.l_mark[-2].nl->add(yystack.l_mark[0].pn);
					else {
						error("AD syntax");
						yyval.nl = new nlist(yystack.l_mark[0].pn);
					}
				else
					error("AD syntax");
			}
#line 6607 "y.tab.c"
break;
case 398:
#line 2947 "gram.y"
	{
				if (yystack.l_mark[0].p) yyval.nl = new nlist(yystack.l_mark[0].pn);
			}
#line 6614 "y.tab.c"
break;
case 400:
#line 2953 "gram.y"
	{	yyval.p = 0; }
#line 6619 "y.tab.c"
break;
case 401:
#line 2957 "gram.y"
	{	yyval.t = 1; }
#line 6624 "y.tab.c"
break;
case 402:
#line 2959 "gram.y"
	{	yyval.t = ELLIPSIS; }
#line 6629 "y.tab.c"
break;
case 403:
#line 2961 "gram.y"
	{	yyval.t = ELLIPSIS; }
#line 6634 "y.tab.c"
break;
case 404:
#line 2965 "gram.y"
	{
			yyval.p = new ptr(PTR,0);
			EXPECT_ID();
			}
#line 6642 "y.tab.c"
break;
case 405:
#line 2970 "gram.y"
	{
			yyval.p = new ptr(RPTR,0);
			EXPECT_ID();
			}
#line 6650 "y.tab.c"
break;
case 406:
#line 2975 "gram.y"
	{	yyval.p = doptr(PTR,yystack.l_mark[0].t); }
#line 6655 "y.tab.c"
break;
case 407:
#line 2977 "gram.y"
	{
				switch ( yystack.l_mark[0].t ) {
				case CONST:
                                     yystack.l_mark[-1].pp->b_const = 1; break;
				case VOLATILE:
				     error('w',"\"volatile\" not implemented (ignored)");
				     break;
				default:
				    error( "syntax error: *%k", yystack.l_mark[0].t );
				}
				yyval.p = yystack.l_mark[-1].pp;
			}
#line 6671 "y.tab.c"
break;
case 408:
#line 2990 "gram.y"
	{	yyval.p = doptr(RPTR,yystack.l_mark[0].t); }
#line 6676 "y.tab.c"
break;
case 409:
#line 2992 "gram.y"
	{
				memptr_pn = yystack.l_mark[-1].pn;
				memptr_tok = 0;
				goto memptr1;
			}
#line 6685 "y.tab.c"
break;
case 410:
#line 2998 "gram.y"
	{
			memptr_pn = yystack.l_mark[0].pn;
			memptr_tok = 0;
			memptr1:
			if (memptr_tok)
				yyval.p = doptr(PTR,memptr_tok);
			else
				yyval.p = new ptr(PTR,0);
			Pname n = memptr_pn;
			if (n->is_template_arg()==0) {
				if(n->tp->skiptypedefs()->base != COBJ) {
				    yyval.pp->memof = 0;
				    error("P toM of nonCT");
				}
				else yyval.pp->memof = n->tp->skiptypedefs()->classtype();
			}
			else {
				yyval.pp->memof = 0;
				yyval.pp->ptname = n;
			}
			EXPECT_ID();
			}
#line 6711 "y.tab.c"
break;
case 411:
#line 3021 "gram.y"
	{
				memptr_pn = yystack.l_mark[-2].pn;
				memptr_tok = yystack.l_mark[0].t;
				goto memptr1;
			}
#line 6720 "y.tab.c"
break;
case 412:
#line 3027 "gram.y"
	{
				memptr_pn = yystack.l_mark[-1].pn;
				memptr_tok = yystack.l_mark[0].t;
				goto memptr1;
			}
#line 6729 "y.tab.c"
break;
case 413:
#line 3034 "gram.y"
	{ yyval.p = new vec(0,yystack.l_mark[-1].pe!=dummy?yystack.l_mark[-1].pe:0 ); }
#line 6734 "y.tab.c"
break;
case 414:
#line 3035 "gram.y"
	{ yyval.p = new vec(0,0); }
#line 6739 "y.tab.c"
break;
#line 6741 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
