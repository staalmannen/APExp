
# line 30 "gram.y"
#include "cfront.h"
#include "size.h"
#include "template.h"
#include <string.h>
#ifdef SVR42
#include <unistd.h>
#endif
// include tqueue.h after YYSTYPE is defined ...

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
//error('d',"save_state: in_typedef%t in_tag%n defer_check %d",in_typedef,in_tag,defer_check);
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
//error('d',"restore_state: in_typedef%t in_tag%n defer_check %d",in_typedef,in_tag,defer_check);
	if ( --px < 0 ) error('i',"parsing state stack underflow -- current table %s",Ctbl->whereami());
	in_typedef = pstate[px].intypedef;
	in_friend = pstate[px].infriend;
	defer_check = pstate[px].defercheck;
	in_tag = pstate[px].intag;
	classid = pstate[px].cid;
//error('d',"            -> in_typedef%t in_tag%n defer_check %d",in_typedef,in_tag,defer_check);
}


//SYM parsing symbol table management
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
	// table allocated in name::tname() to avoid problems with forward
	//     refs to class templates
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
// Although local member defs are illegal outside a local class, scopes
//    are stacked for error recovery / extensibility.
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
	if (ntb == 0) return 0;//error('i',"scope set to null table(n==%n)!",n);
	if ( scopex >= BLMAX ) error('i',"set scope %s: parsing scope stack overflow -- current table %s",ntb->whereami(),Ctbl->whereami());
	Pktab tt = Ctbl;
	if ( Ctbl->k_id == TEMPLATE ) {
		// parsing template member function
		//    template<...> PT<...>::f() {}
		// be sure template params are in scope when parsing f
		// -- extract template scope from current scope and put it
		//    in new scope
		Ctbl = Ctbl->k_next;
		tt->k_next = ntb->k_next;
		ntb->k_next = tt;
		scopestack[scopex].saved_template = 1;
	}
	else if ( Ctbl->k_id == ARG && Ctbl->k_next->k_id == TEMPLATE ) {
		// parsing static data member template with declarator ()'s.
		//    template<...> T (PT<...>::d) = v;
		// interpose PT's table between ARG table and its parent
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
	// restore surrounding template scope, if appropriate
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


// macros
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
static Pnlist scd[BLMAX]; // keep track of cd list outside of switch
static int scdp = -1;

static Pname memptr_pn;
static TOK memptr_tok;

static Pname err_name = 0;

// support for template friend declarations within a class
static Pcons templ_friends;

// fcts put into norm2.c just to get them out of gram.y
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
get_classname(char* s)
{
// error('d',"get_classname(%s)",s);
	char* r = new char[strlen(s)+1];
	sprintf(r,s);
	s = r;

	char* s1 = s;
	while (*s) {
		for ( ; s[0] && (s[0] != '_' || s[1] && s[1] != '_'); s++) s1++;;
		if (*s) {
			if (strncmp(s,"___pt__",7)==0) {
				*s1 = 0;
				return r;
			}
			if (strncmp(s,"__pt__",6)==0) { // parameterized class
				*s1 = '\0';
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
               // if (p == RPTR) error('w',"redundant `const' after &");
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
// error('d',"dobase(%k %n %k)", pr,n,v);

	Pbcl b = new basecl(0,0);
	b->ppp = pr;	// save protection indicator

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
                        // template <class B> class D : public B {};
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
//#define Ncopy(n)	(n->base==TNAME)?new name(n->string):n
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
#undef DO
#undef ELSE
#undef ENUM
#undef FOR
#undef FORTRAN
#undef FRIEND
#undef GOTO
#undef IF
#undef NEW
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

# line 479 "gram.y"
typedef union  {
	char*	s;
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
	PP	p;	// fudge: pointer to all class node objects
	Plist	pl;
	toknode* q;	// token queue
} YYSTYPE;

# line 499 "gram.y"
#include "tqueue.h"
extern YYSTYPE yylval, yyval;
extern int yyparse();

// in_typedef should allow for nested in_typedef
extern int	declTag;	 // !1: inline, virtual mod permitted
int		in_sizeof = 0;
int		in_new = 0;
Ptype 		in_typedef = 0;  // catch redefinition of TNAME
Pname		in_tag = 0;      // handle complex typedefs: int (*)()
extern int	defer_check;	 // redefinition typedef check delay

extern 	int must_be_id;	 // !0, TNAME => ID, i.e., int X
int	DECL_TYPE = 0; 	 // lalex() wants this set for global x(*fp)()
int	in_arg_list=0; 	 // !0 when parsing argument list, 1: in (), 2: in <>
static  int in_binit_list=0;
int	in_class_decl=0; // !0 when processing class definition
int	parsing_class_members=0; // !0 when parsing class def but not member function body
int	in_mem_fct=0;    // !0 when parsing member function definition
Ptempl_inst pti = 0; // explicit template class: class X<int> {};

#define yylex lalex
#define NEXTTOK() ( (yychar==-1) ? (yychar=yylex(),yychar) : yychar )
#define EXPECT_ID() must_be_id = 1
#define NOT_EXPECT_ID() must_be_id = 0

Pname syn()
{
ll:
	switch (yyparse()) {
	case 0:		return 0;	// EOF
	case 1:		goto ll;	// no action needed
	default:	return yyval.pn;
	}
}

# define EOFTOK 0
# define ASM 1
# define AUTO 2
# define BREAK 3
# define CASE 4
# define CONTINUE 7
# define DEFAULT 8
# define DELETE 9
# define DO 10
# define ELSE 12
# define ENUM 13
# define FOR 16
# define FORTRAN 17
# define FRIEND 18
# define GOTO 19
# define IF 20
# define NEW 23
# define OPERATOR 24
# define RETURN 28
# define SIZEOF 30
# define SWITCH 33
# define THIS 34
# define WHILE 39
# define LP 40
# define RP 41
# define LB 42
# define RB 43
# define REF 44
# define DOT 45
# define NOT 46
# define COMPL 47
# define MUL 50
# define AND 52
# define PLUS 54
# define MINUS 55
# define LT 58
# define GT 60
# define ER 64
# define OR 65
# define ANDAND 66
# define OROR 67
# define QUEST 68
# define COLON 69
# define ASSIGN 70
# define CM 71
# define SM 72
# define LC 73
# define RC 74
# define ID 80
# define STRING 81
# define ICON 82
# define FCON 83
# define CCON 84
# define NAME 85
# define ZERO 86
# define ASOP 90
# define RELOP 91
# define EQUOP 92
# define DIVOP 93
# define SHIFTOP 94
# define ICOP 95
# define TYPE 97
# define CATCH 98
# define THROW 99
# define TRY 100
# define TNAME 123
# define EMPTY 124
# define NO_ID 125
# define NO_EXPR 126
# define FDEF 127
# define ELLIPSIS 155
# define AGGR 156
# define MEM 160
# define MEMPTR 173
# define PR 175
# define MEMQ 176
# define TSCOPE 178
# define DECL_MARKER 179
# define REFMUL 180
# define LDOUBLE 181
# define LINKAGE 182
# define TEMPLATE 185
# define XVIRT 200
# define XNLIST 201
# define XILINE 202
# define XIA 203
# define SM_PARAM 207
# define PTNAME 209
# define NEW_INIT_KLUDGE 210
# define XDELETED_NODE 211
# define DUMMY_LAST_NODE 212
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern short yyerrflag;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
YYSTYPE yylval, yyval;
# define YYERRCODE 256

# line 3021 "gram.y"


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
	case VLONG:
		dt->tp2 = dt->tpdef = vlong_type;
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
short yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
-1, 48,
	71, 45,
	72, 45,
	-2, 44,
-1, 65,
	155, 398,
	-2, 319,
-1, 70,
	13, 393,
	97, 393,
	123, 393,
	155, 393,
	156, 393,
	160, 393,
	178, 393,
	179, 393,
	182, 393,
	-2, 319,
-1, 127,
	73, 116,
	-2, 110,
-1, 344,
	70, 105,
	-2, 104,
-1, 436,
	73, 116,
	-2, 111,
-1, 444,
	60, 17,
	71, 17,
	-2, 128,
-1, 445,
	60, 16,
	71, 16,
	-2, 127,
-1, 480,
	1, 223,
	3, 223,
	4, 223,
	7, 223,
	8, 223,
	9, 223,
	10, 223,
	13, 223,
	16, 223,
	19, 223,
	20, 223,
	23, 223,
	24, 223,
	28, 223,
	30, 223,
	33, 223,
	34, 223,
	39, 223,
	40, 223,
	46, 223,
	47, 223,
	50, 223,
	52, 223,
	54, 223,
	55, 223,
	72, 223,
	73, 223,
	80, 223,
	81, 223,
	82, 223,
	83, 223,
	84, 223,
	85, 223,
	86, 223,
	95, 223,
	97, 223,
	99, 223,
	100, 223,
	123, 223,
	156, 223,
	160, 223,
	178, 223,
	179, 223,
	182, 223,
	185, 223,
	209, 223,
	-2, 0,
	};
# define YYNPROD 413
# define YYLAST 3598
short yyact[]={

 163,  24, 596, 407, 479, 523, 343, 152,  10,  11,
 335, 181,   8, 229, 446,  58, 300, 165, 401,   9,
 396, 187,  58,  58, 307, 161, 349, 342, 208, 385,
 318, 520, 120, 322, 609, 217, 557, 207, 190,  18,
 120, 136, 624, 261,  40, 123, 124, 191,  89, 124,
 274, 123,  66, 463,  90,  31, 336, 697, 491, 303,
  74,  88,  83, 185,  57, 180, 194,  83, 464, 678,
  71,  36,  36, 185, 219, 162,  20, 615,  30,   7,
 288,  32,  32,  33,  33, 293, 194, 665, 194, 125,
  20, 609, 200, 122, 246, 607, 608,  20,  20,  44,
  59, 121, 288,  50,  44,  71, 353, 354, 177, 175,
  17,  56, 447, 203, 298, 299,  29,  43, 120, 409,
 139, 410,  43,  81,  52, 212, 595,  24,  51, 556,
  71,  77,  80,  71, 615, 225, 226, 252, 223, 194,
 625, 119, 185, 304,  58,  63, 224, 555,  42,  32,
  26,  33, 185,  42,  41, 344,  83, 438, 173, 273,
 498, 173, 547,  69, 624,  54, 194, 438, 286, 275,
 437, 149, 184, 480, 120, 196, 235, 406,  83, 530,
  36,  44, 184,  58, 458,  25, 333,  39, 287, 233,
  32,  44,  33,  44, 120, 196,  78, 196,  69,  43,
  53, 296, 228,  58,  35,  35, 222, 238, 240,  43,
  55,  43, 120, 521, 172,  44,  45, 172, 315,  20,
 447, 624, 291,  69, 261, 632,  69, 216, 292, 173,
  42, 120, 194,  43,  81, 554,  17,  78, 185, 430,
  42,  42,  42, 325, 347, 317, 330, 403, 196, 551,
  31, 184, 387,  80, 326, 143, 144,  32,  20,  33,
 466, 184, 173, 329,  42, 295, 346, 185, 332, 341,
 389, 389,  35,  30, 379, 196, 194, 120,  20, 552,
 548, 431, 305, 119, 381, 172, 497, 355, 604, 120,
 441, 120,  52, 394, 339, 383, 390, 395, 602,  29,
 392, 442, 388, 306, 185, 601,  75,  86,  42, 408,
 120, 338,  80,  35, 230, 404, 405, 380, 172, 262,
 194, 306, 272, 331, 277, 278, 279, 280, 281, 282,
 283, 284, 285,  54, 419, 420, 140,  41, 120, 120,
 340, 196, 412,  31,  54, 386, 393, 184, 424,  42,
  67, 120, 120, 414,  68, 205, 450, 427, 428,  62,
 415, 468,  54,  73, 214,  44,  30, 320,  53, 512,
 278, 279, 436, 440,  44, 426, 184, 131, 321,  53,
  35, 391, 194,  43,  73, 196, 306, 145, 120, 337,
 701, 681,  43, 591, 432, 434,  36,  53,  67, 204,
 306, 246,  68, 454, 173, 244, 245, 560, 141,  64,
 456,  67, 459, 184,  42,  68,  42, 465, 472, 467,
  41, 475, 476,  42, 509, 478, 417,  54, 483, 196,
 518,  67, 120, 477, 120,  68, 120, 377, 470, 142,
  83,  54, 492, 185, 252, 496, 127, 340, 340, 471,
 495, 173, 469, 416, 473, 505, 178,  44, 277, 120,
 172, 306,  53, 503, 504, 120, 173, 422, 425, 500,
 421, 185, 415, 415, 458,  43,  53,  44, 515, 411,
 426, 426, 120, 120, 581, 314, 301, 134, 517, 387,
 493, 196, 494, 474,  67,  43, 234, 236,  68, 501,
  24, 213,  54, 460, 186, 597,  42, 172, 535, 536,
 185, 533, 689, 120, 627, 599, 146, 540, 185, 534,
 550, 516, 172,  36, 197, 471,  42, 517, 473, 473,
 482, 261, 528, 553,  36, 703,  67,  53, 525, 388,
  68, 340, 210, 340, 210, 340, 549, 294,  21, 120,
 457, 293, 184, 120, 559,  46, 501, 501, 563, 194,
 541, 680, 266, 571, 131, 416, 416, 486, 487, 488,
 569, 545, 561, 425, 425,  20, 598, 669, 570, 484,
 184, 542,  36, 538,  67, 605, 403,  36,  68,  67,
 643, 340, 502,  68, 630, 210,  32, 603,  33, 641,
 634, 640,  44, 639, 600, 525,  28,  41, 266,  17,
  64,  70,  67,  67,  72,  22,  68,  68, 384, 184,
  43, 271, 289, 268, 507, 269, 270, 184, 638,  22,
  65, 593,  36, 489,  67, 592,  22,  22,  68,  64,
  60,  67,  61,  78,  44,  68, 128, 137, 626, 502,
 502,  42, 519, 265,  36, 485,  67, 429, 340,  15,
  68, 328,  43,  65, 544, 439, 218, 266, 196,  64,
 423,  67, 345, 232,  48,  68, 267, 211,  14, 239,
 539,  76,  79, 691, 242, 537, 481, 529, 210, 185,
 297,  65, 695,  42,  65, 352, 499, 120, 348, 356,
 357, 358, 359, 360, 361, 362, 363, 364, 365, 366,
 367, 368, 369, 370, 371, 372, 373, 374, 375,  35,
 376, 700, 237,  84,  34, 382, 635,  36, 637,  47,
 589, 526, 334, 687, 443, 398, 490,  32,  34,  33,
 182,  22, 309, 193, 302,  34,  34, 677, 644, 532,
 193, 319, 209, 415,  36,  42, 664, 131,  22, 628,
 324, 188, 631, 192,  32, 130,  33, 218, 671, 672,
 673, 674, 445, 676, 514,  32, 210,  33, 589, 589,
 589, 589, 589, 589, 589, 589, 589, 589, 589, 589,
 589, 589, 589, 589, 589, 589, 589,  22, 184, 684,
  41, 117, 667, 241,  14, 686, 306, 132, 310, 164,
  29,  78, 189, 565, 131,  41, 564,  22, 558, 182,
 546,  49, 215, 221,  37, 397, 323, 126,  38, 276,
 133,  16, 704,   1, 461, 453, 522,  44,   2, 402,
   0,  34, 241, 290, 524,   0, 416,  54,  41,  82,
  34, 589,  44,   0, 692,  43,  65,  41, 309, 309,
  35,   0, 316,   0,   0, 698,   0,  34,   0,   0,
  43, 129, 324, 324,   0, 339,  31,   0,   0,   0,
  29,   0,  53,  82, 339,  44,  42,  35,   0,  29,
 231,   0,  36,   0,  44, 137,  42, 131,  35,  30,
 448,  42,  32,  43,  33, 510,  34,   0, 506,   0,
   0, 513,  43, 135, 511, 351, 418,  34,  41,  85,
  87,  59,   0,  42, 310, 310,  34,  41,   0, 527,
   0,  65,  56, 138,  42,  34,   0,  29, 323, 323,
  41,   0, 327,  42, 276,  82, 397,   0, 131,   0,
   0, 402, 402, 290, 531,  44,   0, 444,   0, 543,
   0,  82,   0,   0,  44, 462, 449,   0,   0,   0,
 435,   0,   0,  43,   0,  41,   0,  44,   0, 151,
 173, 193,  43,   0,   0,   0, 160,   0,  82, 131,
 171,  41,   0,   0, 137,  43, 176, 448, 448, 562,
  34,   0, 157, 158,  42,  36, 399,   0,   0,   0,
  82,   0,  44,  42,  34,  32,   0,  33,   0,  82,
   0,  64, 206,  67, 594,  35,  42,  68,  44,   0,
  43,   0,  41,  34, 327,   0, 172, 169, 167, 168,
 170,  29, 166,   0,   0, 308,  43, 327, 327,   0,
   0, 159,   0, 174, 636,   0,   0,   0,   0, 290,
 642,  42,   0, 449, 449, 137,   0,   0,   0,  44,
   0, 137,   0, 130,   0,  34,   0,  42,   0,  41,
 131,   0,   0,   0,   0,   0, 666,  43,   0, 137,
   0, 645, 646, 647, 648, 649, 650, 651, 652, 653,
 654, 655, 656, 657, 658, 659, 660, 661, 662, 663,
   0,   0,   0,   0,  22,   0, 264,   0,  42, 137,
 351, 327,   0,  41,   0, 683, 327, 327, 685,   0,
   0,   0, 339,   0,  43,   0,   0,  29,  35, 151,
 173,   0,   0,   0,   0,   0, 160,   0, 276, 433,
 171, 699,   0,   0,   0,   0, 176,   0, 668, 137,
  44,   0, 157, 158, 690,  42, 153,   0, 154,   0,
 156, 155, 327, 327,  42,  41,   0,  14,  43, 129,
   0,   0,   0,   0,   0,   0,   0, 276,   0, 609,
   0,   0,   0, 607, 608, 290, 172, 169, 167, 168,
 170,  29, 166,   0,   0,   0,   0,   0,   0,  42,
   0, 159,  44, 174,  82,   0,   0,   0,   0, 586,
   0, 582, 578,  34,   0, 583, 579, 587, 585,   0,
  43,  40, 615, 613, 574,   0,  14, 584, 572,  41,
   0, 151, 173,   0,   0, 309, 567,   0, 160,   0,
   0, 575, 171,   0,   0,   0,   0, 573, 176,   0,
   0,  42,   0,   0, 157, 158,   0,   0, 153,   0,
 154,   0, 156, 155,   0,   0, 264,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
 566, 480, 246, 688,  43,  40, 244, 245, 576, 169,
 167, 168, 170,  29, 166,   0,   0, 113,   0,   0,
   0, 310,   0, 159,   0, 568,   0, 590, 580, 624,
   0, 112, 403,   0,   0,  42,   0,   0, 339,   0,
   0,   0,  32,  29,  33, 252, 250,   0, 105,   0,
 106, 577, 114,   0, 107, 108,   0,  36,  93,   0,
  94,   0,  91,  92,   0,   0, 101,  32, 102,  33,
   0,   0,  96,  95, 103, 104, 696,  29, 111, 115,
   0,  41,   0,   0,  39,   0,   0,   0, 588,  51,
   0,   0,   0,  29,   0,   0,   0, 308, 110, 100,
  98,  99,  97, 109,   0, 118,  43,  27, 147,   0,
 183,   0,  40,   0,  78,  41, 609,   0,  44,   0,
 607, 608, 151, 173, 618,   0, 617,   0,   0, 160,
  34,  41, 261, 171,   0,   0,  43,  42,   0, 176,
  41,   0,   0,   0,   0, 157, 158,   0,  39, 153,
   0, 154,  44, 156, 155,   0,   0, 616, 614, 615,
 613,   0,   0,   0,   0,  35,   0,  42,  44,   0,
  43,  55, 179,   0,   0,   0,   0,  44,   0, 172,
 169, 167, 168, 170,  29, 166,  43,   0, 116,   0,
  35,   0,   0,   0, 159,  43, 195,   0, 150, 147,
   0,  42,   0,  40,   0,   0,   0,   0,   0,   0,
   0,   0,   0, 151, 173,   0,   0,  42,   0,   0,
 160,   0,  41,   0, 171,   0,  42,   0,   0,   0,
 176,   0,   0,   0,   0,  31, 157, 158,   0,   0,
 153,  31, 154,   0, 156, 155, 624,   0,   0,   0,
   0,  36,   0,   0,   0,  39,   0,  36,  30, 148,
   0,  32,   0,  33,  30,   0,   0,  32,   0,  33,
 172, 169, 167, 168, 170,  29, 166,  43,  27,   0,
   0, 183,   0,   0,   0, 159,   0, 195,   0, 150,
 147,  19,   0,   0,   0,   0,  29,  19,   0,   0,
   0,   0,  29,   0, 151, 173,   0,   0,  42,   0,
   0, 160, 609,  41,  78, 171, 607, 608,   0,   0,
 618, 176, 617,   0,   0,   0,   0, 157, 158,   0,
   0, 153,   0, 154,  41, 156, 155,  40,   0,   0,
  41,   0,   0,   0,   0,   0,  39,   0,   0,   0,
 148,   0,   0, 616, 179, 615, 613,   0,   0,   0,
 147, 172, 169, 167, 168, 170,  29, 166,  43,  27,
   0,  44, 183,   0, 151, 173, 159,  44, 174,   0,
 150, 160,   0,   0,  35, 171,   0,   0,   0,  43,
  35, 176,   0,   0,   0,  43,   0, 157, 158,  42,
   0, 153,   0, 154,  41, 156, 155,   0,   0,  29,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  42,  23,   0,   0, 587,   0,  42,   0,   0,   0,
   0, 172, 169, 167, 168, 170,  29, 166, 151, 173,
   0, 148, 624,   0,   0, 160, 159,  41, 174, 171,
 150,   0,   0,   0,   0, 176,   0,   0,   0,  43,
   0, 157, 158,   0,   0, 153,   0, 154,   0, 156,
 155,  40,   0,   0,  41,   0,   0, 246,   0, 413,
  39, 244, 245,   0,  44, 254,   0, 255,   0,   0,
  42,   0,   0,   0,   0, 172, 169, 167, 168, 170,
  29, 166,  43,  27,   0,   0, 183,   0, 151, 173,
 159, 148, 174,   0, 590, 160,   0,   0, 253, 171,
 252, 250,   0,   0,   0, 176,   0, 629,   0,  43,
   0, 157, 158,  42,   0, 153,   0, 154,  41, 156,
 155,   0,   0,  29,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,  23,   0,   0,   0,   0,
  42,   0,   0,   0,   0, 172, 169, 167, 168, 170,
  29, 166, 151, 173,   0, 588,   0,   0,  40, 160,
 159,  41, 174, 171,   0,   0,   0,   0,   0, 176,
   0, 378,   0,  43,   0, 157, 158,   0,   0, 153,
   0, 154,   0, 156, 155, 176,   0, 261,  41,   0,
   0,   0,   0,   0,  39,   0,   0,   0,  44,   0,
   0,   0,   0,   0,  42,   0,   0,   0,   0, 172,
 169, 167, 168, 170,  29, 166,  43,  27,   0,   0,
 183,   0, 151, 173, 159, 264, 174,  40,   0, 160,
  29,   0,   0, 171,   0,   0,   0,   0,   0, 176,
   0, 263,  23,  43,   0, 157, 158,  42,   0, 153,
   0, 154,  41, 156, 155,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,  41,   0,
   0,   0, 147,   0,  42,   0,   0,   0,   0, 172,
 169, 167, 168, 170,  29, 166, 151, 173,   0, 264,
   0,   0,   0, 160, 159,   0, 174, 171,   0,  29,
   0,  39,   0, 176, 201,  44,   0,  43,   0, 157,
 158,  23,   0, 198,   0, 199,   0, 156, 155,   0,
   0,   0,  41,  43,  27,   0,   0, 183,   0,   0,
   0,   0,   0,   0,   0,   0, 179,  41,  42,   0,
   0,   0,   0, 172, 169, 167, 168, 170,  29, 166,
   0,   0,   0,   0,  42,   0, 151, 173, 159, 264,
   0,   0, 150, 160,   0,   0,   0, 171,   0,   0,
 350,   0,   0, 176,  44,   0,   0,  43,   0, 157,
 158,   0,   0, 153,   0, 154,   0, 156, 155,   0,
   0,   0,  43,  27,   0,   0, 183, 609,   0, 610,
   0, 607, 608,   0,   0, 618,   0, 617,  42,   0,
   0, 612, 611, 172, 169, 167, 168, 170,  29, 166,
 151, 173,   0,  42,   0,   0,   0, 160, 159,   0,
 174, 171,   0,   0,   0,   0, 202, 176, 616, 614,
 615, 613,   0, 157, 158,   0,   0, 153,   0, 154,
   0, 156, 155,   0,   0,   0,  41,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,  42,   0,   0,   0,   0, 313, 169, 167,
 168, 170,  29, 166,   0,   0,   4,  12,   0,   0,
 151, 173, 159, 264, 174,   0,   0, 160,   0,  40,
   0, 171,   0,   0,   0,   0,   0, 176,   0,   0,
  31,  43,   0, 157, 158,   0,   0, 153,   0, 154,
  41, 156, 155,   0,   0,   0,  36, 624,   0,   0,
   0,   0,   0,  30,   0,   0,  32,   0,  33,   0,
   0,   0,  42,   0,   0,  40,   0, 312, 169, 167,
 168, 170,  29, 166,   0,   0,  31, 264,   3,  40,
   6,   0, 159,   0, 174,   0,  19,   0,   0,   0,
  31,  29,  36,   0,   0,  43,   0,   0,   0,  30,
   0,   0,  32,  23,  33,   0,  36,   0,   0,   0,
  41,  40,   0,  30,   0,   0,  32,   0,  33,   0,
   0,   0,  40,   0,   0,   0,  42,   0,   0,  41,
   0,   0,  19,   0,   0,   0,   0,  29,  36,   0,
 220,   0,   0,   0,   0,   0,  19, 264,  32,  23,
  33,  29,   0,   0,   0,   0,   0,   0,   0,  32,
   0,  33,  39,  23,   0,  43,  44,   0,   0,   0,
   0,   0,   0,   0,   0,  41,   0,   0, 308,  35,
  40,   0,   0,  29,  43,  27,   0,   0,   5,  41,
   0,  13,   0,   0,  29,  51,  42,   0,   0,   0,
   0,  40,   0,   0,   0,   0,  51,  36,  39,   0,
   0,   0,  44,   0,   0,  42,   0,  32,   0,  33,
   0,  41,  39,   0,   0,  35,  44,   0,  36,   0,
  43,  27,  41,   0, 183,   0,   0,   0,  32,  35,
  33, 227,   0,   0,  43,  27,   0, 447, 183,   0,
   0,  13,  29,   0,  39,   0,   0,   0,  44,   0,
   0,  42,   0,   0,  51,  39,   0,   0,   0,  44,
   0,  35,   0,  29,   0,  42,  43,  55,   0,   0,
   0,   0,  35,   0,   0,  51,   0,  43,  55,   0,
  41, 246,   0, 247,   0, 244, 245,   0,   0, 254,
   0, 255,   0,   0,   0, 249, 248,  42,   0,   0,
   0,  41, 609,   0, 610,   0, 607, 608,  42,   0,
 618,   0, 617,  39,   0,   0, 612,  44,   0,   0,
   0,   0, 253, 251, 252, 250,   0,   0,   0,   0,
  35,   0,   0,   0,  39,  43,  55,   0,  44,   0,
   0,   0,   0, 616, 614, 615, 613,   0,   0,   0,
 702,  35,   0,   0,   0,   0,  43,  55,   0, 246,
   0, 247,   0, 244, 245,   0,  42, 254,   0, 255,
   0,   0,   0, 249, 248, 256, 257, 260,   0, 243,
 259,   0,   0,   0,   0,   0,   0,  42,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0, 258,
 253, 251, 252, 250, 246,   0, 247,   0, 244, 245,
   0, 261, 254,   0, 255,   0,   0,   0, 249, 248,
 256, 257, 260,   0, 243, 259, 694,   0,   0,   0,
   0,   0, 624,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0, 693, 258, 253, 251, 252, 250,   0,
 246,   0, 247,   0, 244, 245,   0,   0, 254,   0,
 255,   0,   0,   0, 249, 248, 256, 257, 260,   0,
 243, 259,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0, 682, 261,
 258, 253, 251, 252, 250, 246,   0, 247,   0, 244,
 245,   0,   0, 254,   0, 255,   0,   0,   0, 249,
 248, 256, 257, 260,   0, 243, 259,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0, 261, 258, 253, 251, 252, 250,
   0, 609,   0, 610,   0, 607, 608,   0,   0, 618,
   0, 617,   0,   0,   0, 612, 611, 619, 620, 623,
 679, 606, 622,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
 261, 621, 616, 614, 615, 613, 246,   0, 247,   0,
 244, 245,   0,   0, 254,   0, 255,   0,   0,   0,
 249, 248, 256, 257, 260, 675, 243, 259,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0, 670,   0, 261, 258, 253, 251, 252,
 250,   0, 246,   0, 247,   0, 244, 245,   0,   0,
 254,   0, 255,   0,   0,   0, 249, 248, 256, 257,
 260,   0, 243, 259,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0, 624, 258, 253, 251, 252, 250, 246,   0, 247,
   0, 244, 245,   0,   0, 254,   0, 255,   0,   0,
   0, 249, 248, 256, 257, 260,   0, 243, 259, 633,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0, 261, 258, 253, 251,
 252, 250, 508,   0,   0,   0,   0,   0,   0, 246,
   0, 247,   0, 244, 245,   0,   0, 254,   0, 255,
   0,   0,   0, 249, 248, 256, 257, 260,   0, 243,
 259,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0, 261,   0,   0,   0,   0, 455,   0, 258,
 253, 251, 252, 250, 246,   0, 247,   0, 244, 245,
   0,   0, 254,   0, 255,   0,   0,   0, 249, 248,
 256, 257, 260,   0, 243, 259,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0, 261,   0,   0,
   0,   0,   0, 452, 258, 253, 251, 252, 250,   0,
 246,   0, 247,   0, 244, 245,   0,   0, 254,   0,
 255,   0,   0,   0, 249, 248, 256, 257, 260,   0,
 243, 259,   0,   0,   0,   0,   0,   0, 609,   0,
 610,   0, 607, 608,   0,   0, 618,   0, 617, 261,
 258, 253, 251, 252, 250, 246,   0, 247,   0, 244,
 245,   0,   0, 254,   0, 255,   0,   0,   0, 249,
 248, 256, 257, 260, 451, 243, 259,   0,   0, 616,
 614, 615, 613,   0,   0,   0,   0,   0,   0,   0,
   0,   0, 400,   0, 261, 258, 253, 251, 252, 250,
   0, 246,   0, 247,   0, 244, 245,   0,   0, 254,
   0, 255,   0,   0,   0, 249, 248, 256, 257, 260,
   0, 243, 259,   0,   0,   0,   0,   0, 246,   0,
 247,   0, 244, 245,   0,   0, 254,   0, 255, 311,
 261, 258, 253, 251, 252, 250, 246,   0, 247,   0,
 244, 245,   0,   0, 254,   0, 255,   0,   0,   0,
 249, 248, 256, 257, 260,   0, 243, 259, 624, 253,
 251, 252, 250,   0, 246,   0,   0,   0, 244, 245,
   0,   0, 254,   0, 255, 261, 258, 253, 251, 252,
 250,   0, 609,   0, 610,   0, 607, 608,   0,   0,
 618,   0, 617,   0,   0,   0, 612, 611, 619, 620,
 623,   0, 606, 622,   0, 253, 251, 252, 250,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0, 261, 621, 616, 614, 615, 613, 609,   0, 610,
   0, 607, 608,   0,   0, 618,   0, 617,   0,   0,
   0, 612, 611, 619, 620, 623,   0, 606, 261,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0, 261, 621, 616, 614,
 615, 613,   0, 246,   0, 247,   0, 244, 245,   0,
   0, 254,   0, 255,   0,   0,   0, 249, 248, 256,
 257, 260,   0, 243, 261,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0, 624, 258, 253, 251, 252, 250, 246,   0,
 247,   0, 244, 245,   0,   0, 254,   0,   0,   0,
   0,   0, 249, 248, 256, 257, 260, 609, 243, 610,
   0, 607, 608,   0,   0, 618,   0, 617,   0,   0,
   0, 612, 611, 619, 620, 623,   0, 624, 258, 253,
 251, 252, 250,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0, 616, 614,
 615, 613, 246,   0, 247,   0, 244, 245,   0,   0,
 254,   0, 255,   0,   0,   0, 249, 248, 256, 257,
 260,   0, 609, 261, 610,   0, 607, 608,   0,   0,
 618,   0, 617,   0,   0,   0, 612, 611, 619,   0,
   0,   0,   0, 253, 251, 252, 250, 246,   0, 247,
   0, 244, 245,   0,   0, 254,   0, 255,   0,   0,
   0, 249,   0, 616, 614, 615, 613, 246, 261, 247,
   0, 244, 245,   0,   0, 254,   0, 255,   0,   0,
   0, 249, 248, 256,   0,   0,   0, 624, 253, 251,
 252, 250,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0, 253, 251,
 252, 250,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0, 261,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0, 624,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0, 261,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0, 261 };
short yypact[]={

2196,-1000,-1000,-1000,-1000, 143,-1000,-1000,-1000,-1000,
-1000,-1000, 515,-1000,  31, 570,-1000, 571,-1000, 339,
 226,1507,1501,-1000, -56,-1000,-1000,-1000, 249, 249,
 -62,1298,   4,  -4,-127,  -8,-1000,-1000,-1000,1000,
 734,-1000, 249,-1000,-1000,-1000,  39, 278, 369, 184,
-1000,-1000, 571,-1000,-1000,-1000, 318,-1000, -61,1641,
1571,-1000,1748,-1000, 463,1389,-1000,1641,-1000,-1000,
1973,-1000,1748, 319,-1000, 310, 599, 571,-1000, 981,
 571,-1000,-1000,-1000,-133,1480,-1000,1480,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000, 460, 321,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000, 725,-1000,-1000,
 -61,-1000,-1000,-1000, -23,-1000,2256, 245, 249,-1000,
-1000,-1000,-1000, 116,-1000,-1000, 317,-1000,1480, 456,
-1000,1748,-1000, 852,-1000,-1000,3243,1909, 644, 581,
2043,1855,2043,2043,2043,2043,2043,2043,2043,2043,
2043,-1000, 134,  33,-1000,1480,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,1298, 511, 507,-1000, 193,3243,1571,
 -10,-1000,  31,-1000,-1000, -56,-1000, 445, -12, 211,
-1000,-1000,-1000,2288,  55, 511, 507,3106,2177,2107,
 444,-1000,1501,-1000,-1000, 319,-1000, 307,-1000,-1000,
3288,2378, 307,-1000,-1000,-1000,-1000,-1000,  99,-1000,
-1000,-1000,-1000,-1000, 191, 174,-1000, 254, 226, 113,
 214,1480,  75,-1000,-1000, 307, 172,1924, -18,1571,
-1000, 369,1641,1641,1641,1641,1641,1641,1641,1641,
1641,1641,1641,1641,1641,1641,1641,1641,1641,1641,
1641,1641, 581,1641, 539,1839,1855,-1000,1641, 442,
 205,1571, 581,-1000,-1000,1389,2299, 581, 581, 581,
 581, 581, 581, 581, 581, 581, 956,-1000, 909,3061,
1282,-1000,-1000,1571,1571,-1000, 103, 240,-1000,-1000,
  22,-1000, 438,1614,-1000,1571,-1000, 356,-1000,1307,
 965,-1000, 429, 426,-1000,  22, 629,-1000,-1000,1480,
-1000,-1000, 547, 687, 714,-1000,-1000,-124,-1000,-1000,
-1000,-1000, 167,-1000, 210,-1000,-1000,1052, 795,-1000,
-1000, 307,  96,-1000,-1000,  75,-1000,-1000, 230,-1000,
 692,2357, 240,-1000,-1000,-1000,3243,3243,  44,  44,
-137,3134,3397,3088, 351,1717,-137,1242,1242,1242,
2431,3417,3243,3243,3015,-1000,2970, 581,1641,-1000,
-1000,1389,2924,-1000, 427,-1000, 380, 868,-107,  21,
-1000, 137,-1000, 238, 411, 397, 308,  99,-1000,-1000,
-1000, 452, 546, 207, 392, 384,-1000, 100,-1000,-1000,
 490,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000, 547,
 614, 483, 483, 483,-1000,-1000,-1000, 592, 547, -69,
-1000, 214,-1000,1248,-1000,1248, 245,-1000,  75, 216,
  86,-1000,1924,-1000, 249,-1000, 547,-1000, 140,  32,
 100,1641,2043,2879, 383,-1000,-1000,-1000, 817,-1000,
-1000,-1000,-1000, 322, 677,-1000,-1000,-1000,-1000,-1000,
1855,-1000, 308,-1000,-1000, 308, 389,-1000,-1000,-1000,
 -43, 804, 297,  22,1571,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000, 106,-1000,1641,-1000,2242,
-1000,-1000,-1000, 547, 542,-1000,3352, 581,2043,1855,
-1000,-1000, 484,-1000,-1000,-1000,-1000,1748, 547,-1000,
-1000,  88, 209,-1000,1571, 480, 208,-1000,-1000, 240,
-1000,3243,-1000,-1000,-1000,-1000,-1000, 163,-1000, 581,
-1000,-1000,-1000,-1000,-1000,-1000, -38,-1000, 804, 366,
1571,-1000, 297, 100,-1000,-1000,-1000,-1000,1218,-1000,
-1000, 352,-1000,-1000,-1000,-1000,-1000,1641,  45,-1000,
-1000,-1000, 465, 465, 475,-1000, 236, 229,-1000, 219,
 100,3152,-1000,-1000,  60,-1000, 474,1775, 585, 581,
2043,-1000,-1000, 153,2827, 100,-1000,1641,-1000,-1000,
 465,-1000,-1000,1641,-1000,-1000,1705,1705,1705,1705,
1705,1705,1705,1705,1705,1705,1705,1705,1705,1705,
1705,1705,1705,1705,1705,-1000,-1000,   6, 581,1641,
1116, 581,-1000,-1000,-1000, 565,2782,-1000,-1000,-1000,
-1000,-1000,2736,-1000, -29,3197, -16, -16,-138,1356,
2452,2998,  41,1552,-138,1139,1139,1139,2057,3372,
3197,3197,2691,-1000, 522, 350,2645, 581,1641,-1000,
-1000,1641,-1000,-1000,-1000,-1000,-1000,-1000, 472,1705,
 465,-1000,2043,2600,-1000,2554,-1000, 100,1748, -98,
3307,-1000, 581,2043,1641,-1000,2288, 349, 581,2509,
 494,-1000,-1000,-1000,-1000 };
short yypgo[]={

   0, 838,   9,   8,  19, 359,   3, 836,   5,  11,
 833,  52, 548, 677, 831, 150,  27,   6, 446,  56,
 830, 828, 185, 827, 823,  64, 821,  39, 659,  47,
 820, 129, 818,   4, 816, 813, 812,  21, 456, 484,
 171,  25, 809,  18,   7,  35,  54, 801,  24,  14,
  38, 763, 145, 761,  20,  50, 752,  33, 751,   2,
 824,   0,  29,  75, 606, 109, 723, 749, 748, 747,
  48, 744, 736, 734, 733,  13, 732,  10,  16, 614,
 731,  28,  37,  79, 729, 722, 698, 696,  65, 695,
 690, 687, 686, 684, 679, 890,  30, 673, 672,  26,
 665, 661, 657, 652, 648, 635, 631, 628, 604, 601,
 599, 597, 590,  17, 579 };
short yyr1[]={

   0,  10,  10,  10,  10,  10,  10,  84,  85,  87,
  83,  67,  67,  67,  67,  67,  73,  73,   1,   1,
   1,   1,   1,   2,   2,  89,   4,   4,   4,  90,
   3,   3,   3,  91,  72,  88,  92,   6,   6,   7,
   7,   8,   8,   5,   5,  25,  93,  25,  25,  94,
  25,  26,  26,   9,   9,  95,  96,  65,  65,  65,
  14,  14,  14,  14,  14,  14,  14,  13,  13,  13,
  13,  13,  13,  58,  82,  82,  57,  57,  57,  57,
  57,  56,  81,  81,  20,  20,  20,  97,  15,  98,
  15,  15,  16,  16,  86,  86,  86,  99,  99,  49,
  49,  49,  49,  49,  17, 100,  17,  17, 101,  22,
  22,  22,  22, 102, 102,  75,  75,  76,  76,  77,
  77,  77,  77,  77,  21,  21,  21,  18,  18,  19,
  19,  23,  23,  23,  24,  24,  24,  24,  24,  24,
  24,  24,  27,  27,  27,  27,  70,  70,  70,  70,
  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
  70,  70,  63,  61,  61,  64,  64,  78,  78,  78,
  80,  80,  28,  28,  28,  28,  28,  28,  28,  28,
  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,
  48,  48,  48,  48,  48,  48,  48,  54,  54,  54,
  43,  43,  43,  43,  43,  45,  45,  30,  30,  30,
  31,  32,  59, 103,  33,  33,  33,  35,  35,  35,
  35, 104,  35,  35, 106, 105,  34,  34,  34,  34,
  34,  34,  34,  34,  34,  34, 107,  34, 108,  34,
 109,  34, 110,  34, 111,  34, 112,  34,  34,  68,
  68,  69,  74,  74,  37,  36,  36,  29,  29,  39,
  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,
  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,
  39,  39,  39,  39,  38,  38,  38,  38,  38,  38,
  38,  38,  38,  38,  38,  38,  38,  38,  38,  38,
  38,  38,  38,  38,  38,  38,  38,  38,  38,  38,
  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,
  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,
  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,
  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,
  62,  62,  62,  62,  62,  62,  62,  62,  42,  42,
  42,  42,  42,  42,  42,  66,  60,  60,  60,  41,
  41,  41,  44, 113,  47,  47,  47,  47,  46,  55,
  51, 114,  51,  79,  52,  53,  53,  50,  50,  71,
  71,  71,  12,  12,  12,  12,  12,  12,  12,  12,
  12,  11,  11 };
short yyr2[]={

   0,   1,   1,   1,   2,   1,   1,   0,   0,   0,
   8,   1,   1,   1,   1,   2,   1,   1,   1,   1,
   1,   1,   5,   4,   2,   0,   7,   5,   5,   0,
   6,   4,   4,   0,   4,   0,   0,   3,   0,   1,
   3,   3,   4,   2,   0,   1,   0,   4,   2,   0,
   4,   1,   3,   3,   2,   1,   1,   1,   4,   4,
   1,   1,   1,   2,   1,   1,   1,   1,   2,   2,
   2,   2,   2,   1,   3,   1,   0,   3,   2,   2,
   2,   2,   1,   1,   1,   1,   2,   0,   5,   0,
   6,   2,   1,   3,   3,   1,   0,   2,   2,   1,
   2,   2,   2,   3,   1,   0,   4,   0,   0,   5,
   2,   5,   2,   0,   2,   2,   0,   1,   3,   1,
   2,   2,   3,   3,   2,   4,   7,   1,   1,   1,
   1,   2,   0,   2,   1,   2,   2,   1,   1,   1,
   2,   3,   1,   2,   2,   2,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   2,   2,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   2,   2,   1,   0,   2,   5,
   1,   3,   2,   4,   2,   4,   6,   6,   4,   4,
   6,   1,   3,   2,   4,   2,   2,   2,   2,   3,
   1,   2,   0,   2,   2,   2,   3,   0,   2,   2,
   0,   2,   2,   4,   4,   0,   2,   0,   2,   2,
   2,   0,   3,   0,   4,   2,   3,   1,   1,   1,
   2,   0,   5,   4,   0,   2,   2,   1,   3,   3,
   1,   1,   1,   3,   5,   3,   0,   9,   0,   4,
   0,   4,   0,   4,   0,   5,   0,   4,   3,   0,
   2,   3,   4,   3,   1,   1,   3,   1,   3,   3,
   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,
   3,   3,   3,   3,   3,   3,   5,   3,   2,   5,
   3,   6,   1,   2,   3,   3,   3,   3,   3,   3,
   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,
   3,   5,   3,   2,   5,   3,   6,   1,   2,   0,
   2,   2,   3,   3,   2,   2,   2,   2,   2,   2,
   2,   2,   2,   2,   2,   4,   3,   4,   4,   3,
   4,   4,   3,   4,   4,   3,   4,   4,   1,   2,
   3,   3,   1,   3,   1,   1,   1,   1,   1,   1,
   2,   3,   4,   2,   4,   3,   3,   3,   4,   4,
   5,   5,   6,   6,   4,   4,   1,   1,   2,   1,
   2,   2,   4,   1,   1,   1,   2,   2,   2,   2,
   2,   0,   5,   1,   5,   3,   1,   1,   0,   0,
   1,   2,   1,   1,   2,   2,   2,   2,   1,   3,
   2,   3,   1 };
short yychk[]={

-1000, -10,  -1,  72,   0, 182,  74, -83,  -9,  -4,
  -3,  -2,   1, 185, -13, -28, -14, -65, -27,  80,
 -63, -12, -79,  97, -61, -22, -15, 179, -64,  85,
  47,  24,  50,  52, -66, 173,  40, -60, -21, 156,
  13, 123, 209, 178, 160,  73,  40, -84, -28, -26,
  72,  97, -65, -22, -15, 179,  80, -25, -61,  69,
  70,  72,  -5, -52,  40, -79, -11,  42,  46, -52,
  40, -11, -79,  45, -27,  80, -28, -65,  97, -28,
 -65, 179, -60, 123, -66, -95,  58, -95, 123, -70,
 -46,  54,  55,  50,  52,  65,  64,  94,  92,  93,
  91,  58,  60,  66,  67,  40,  42,  46,  47,  95,
  90,  70,  23,   9,  44,  71, 180, -47,  97, -65,
 -61,  97,  97, 178, 173,  97, -23, -18, -64, 179,
  73,  80,  73, -20, -18, 179, -61, -64, -95,  81,
  58,  -5,  70,  71,  72,  69, -38,   9, 160, -40,
  99,  23, -44,  50,  52,  55,  54,  46,  47,  95,
  30, -41, -63, -61, -42,-113,  86,  82,  83,  81,
  84,  34,  80,  24,  97, -65,  40, -29, -38,  73,
 -88,  -9, -13, 182, -65, -61,  41, -37, -53, -36,
 -50, -29, -51, -13, -61,  97, -65, -38,  50,  52,
 -37,  41, 173, -27,  80,  45,  41, -82, -81, -56,
 -38, -13, -82,  41,  43,  97, -65, -45, -12,  97,
  74, -24, -83,  -9,  -4,  -3,  -2, 175, -63, -75,
  69, -95, -97,  73, 179, -82,  41, -85, -88, -94,
 -25, -28, -93,  70,  54,  55,  50,  52,  65,  64,
  94,  92,  93,  91,  58,  60,  66,  67,  90,  71,
  68, 180, -40,  42, 160,   9,  23,  95,  42,  44,
  45,  40, -40, -44, -55,-113, -13, -40, -40, -40,
 -40, -40, -40, -40, -40, -40, -44, -41,  47, -38,
 -13, -70, -46,  40,  40,  72, -37, -90, 124, 125,
 -78,  41, -71,  71, 155,  71, -65, -48,  80, -12,
 -79,  43,  80,  80,  41, -78, -28, -27, -96, -58,
  60,  71, -57, -79, -12, -96, -45, -66,-101,  72,
  72,  69, -27,  73, -76, -77, -19, 175,  97,  80,
 -65, -82, -16, -17,  80, -98, -96,  72, -86, -99,
 156, -13, -89, 124, 125, -29, -38, -38, -38, -38,
 -38, -38, -38, -38, -38, -38, -38, -38, -38, -38,
 -38, -38, -38, -38, -38, -38, -38, -40,  42, -44,
 -55,-113, -38, -41, 176, -62, -63,  47,  97, -61,
 -41, 176, -62, -63, -37, -37, -54, -12, -18,  97,
  41, -43, -12,  40, -37, -37,  74,  -6,  69,  97,
  99,  41, -50, 155, -29, -11, -52,  70, -64, -48,
 -48,  41,  41,  41, -81, -52, -11, -57, -57,-102,
  72,  71, -19,  97, -19, 175, -96,  74,  71,-100,
 -16,  60,  71, -73, -64,  80, -49,  80, -12, -79,
  -6,  69,  43, -38, -37,  43, -41, 123,  47, -41,
 123, -18,  97, 160,  47, -41, 123, -41, 123,  41,
  41, -11, -54, -11,  41, -43, -43,  41,  41, -33,
  73, -92,  40, -78,-114,  41, -52, -52, -52,  41,
 -72, 127, -77, -19, -19, -75, -17,  70,  74, -87,
 -99, -11, -52, -49, -49, -33, -38, -40,  43,  41,
 -18,  97,  47, -18,  97, -44, -55,-113,  41,-103,
  74, 256,  -7,  -8,  40, -19, -80, -18, -29, -91,
  73, -38, -67,  -9,  -4,  -3,  -2, -22,  41, -40,
 -44, -55,  97, -18, -52, -11, -30,  74,  71, -37,
  40,  41,  71,  -6,  72, 185, -31,  74, -32,  -8,
  41, -37, -18, -33, -34, -35,  72,  28,  97,  -9,
  -4, -33,  20,  39,  16,  33,  80, 123,   4,   8,
 100, -39,   3,   7,  19,  10,   1,   9, 160, -40,
  99,  41,-105,-106, -38,  81, -59,  40, -59,  40,
-108,  69,  69,-111,  69, -33,  70,  54,  55,  50,
  52,  65,  64,  94,  92,  93,  91,  60,  58,  66,
  67,  90,  71,  68, 180,  80,-104,  40, -40,  42,
   9, -40,  72,  72, -33, -31, -38, -31,-107, -59,
-109,-110, -38,-112, -68, -39, -39, -39, -39, -39,
 -39, -39, -39, -39, -39, -39, -39, -39, -39, -39,
 -39, -39, -39, -39, -31,  81, -38, -40,  42,  12,
  41, -31, -31, -31, -31,  69, -31, -69,  98,  69,
  39,  41,  43, -38, -31, -38, -31, -74, -79,  40,
 -39, -59, -40,  43,  72, -33, -13, 155, -40, -38,
 -48,  41,  41,  41, -31 };
short yydef[]={

   0,  -2,   1,   2,   3,  61,   5,   6,  18,  19,
  20,  21,   0,   7,   0,  44,  67,  62, 191, 142,
   0,   0,   0,  60, 172,  64,  65,  66,  57,   0,
   0,   0, 402, 403,   0, 408, 393, 173, 132,   0,
   0, 176,   0, 376, 377,   4,   0,   0,  -2,   0,
  54,  68,  69,  70,  71,  72, 142,  51, 172, 319,
 319,  24,  35, 182, 393,  -2, 198, 319, 412, 184,
  -2, 197, 398,   0, 193, 142, 195, 196, 405,   0,
   0,  63, 174, 175,   0, 319,  55, 319, 143, 144,
 145, 146, 147, 148, 149, 150, 151, 152, 153, 154,
 155, 156, 157, 158, 159,   0,   0, 162, 163, 164,
 165, 166, 167, 168, 169, 170, 171, 215, 384, 385,
   0, 404, 406, 378, 407, 410,   0,  -2, 128, 112,
 124, 127,  87,  91,  84,  85,   0, 128, 319,   0,
   8,  35,  49,   0,  53,  46,  48,   0, 377, 317,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0, 348,   0, 172, 352, 319, 354, 355, 356, 357,
 358, 359, 379,   0,   0,   0, 383,   0, 267, 319,
  29,  43,   0,  61,  62,   0, 177,   0, 399, 264,
 396, 265, 397, 202, 172,  60,  62,   0,   0,   0,
   0, 177,   0, 192, 142,   0, 199,   0,  75,  82,
  83,  76,   0, 160, 161, 386, 387, 388, 215, 409,
 108, 131, 133, 134, 138, 137, 139,   0,   0,   0,
   0, 319, 107,  89,  86,   0,   0,  96,  25, 319,
  52,  45, 319, 319, 319, 319, 319, 319, 319, 319,
 319, 319, 319, 319, 319, 319, 319, 319, 319, 319,
 319, 319, 313, 319, 377,   0,   0, 324, 319,   0,
   0, 319, 318, 320, 321, 319, 207, 325, 326, 327,
 328, 329, 330, 331, 332, 333, 334, 349,   0,   0,
 210, 380, 381, 319, 319,  23,   0,  38,  31,  32,
 183, 185,   0, 398, 400, 319,  69, 390, 200, 202,
 202, 411, 379, 379, 188, 189,   0, 194,  58, 319,
  56,  73,  81,  76,  76,  59, 216,   0, 113, 135,
 136, 140, 193, 125, 115, 117, 119,   0,   0, 129,
 130,   0,   0,  92,  -2, 107, 375,  22,   0,  95,
   0,   0,  38,  27,  28,  50,  47, 294, 295, 296,
 297, 298, 299, 300, 301, 302, 303, 304, 305, 306,
 307, 308, 309, 310,   0, 312,   0, 315, 319, 322,
 323, 319,   0, 336,   0, 339,   0,   0,   0, 172,
 342,   0, 345,   0,   0,   0, 389, 207, 350, 351,
 353,   0, 210, 210,   0,   0, 268,   0,  36, 178,
   0, 177, 395, 401, 266, 204, 205, 391, 201, 203,
   0,   0,   0,   0,  74,  79,  80,   0,  78, 109,
 141,   0, 120,   0, 121,   0,  -2,  88, 107,   0,
   0,   9,   0,  97,  -2,  -2,  98,  99,   0,   0,
   0, 319,   0,   0,   0, 335, 337, 338,   0, 340,
 341, 360, 363,   0,   0, 343, 344, 346, 347, 374,
   0, 209, 208, 212, 382, 211,   0, 368, 369,  30,
  -2,   0,   0, 394, 319, 206, 186, 187, 190,  77,
 114,  33, 118, 122, 123,   0,  93, 319,  90,   0,
  94, 101, 102, 100,   0,  26, 311, 314,   0,   0,
 361, 365,   0, 366, 367, 370, 371,   0,   0, 217,
 225,   0,  37,  39, 319,   0,   0, 180, 392,  38,
 126, 106,  10,  11,  12,  13,  14,  64, 103, 316,
 372, 373, 362, 364, 213, 214, 221, 226,   0,   0,
 319, 179,   0,   0,  15, 218, 219, 224,   0,  40,
  41,   0, 181,  34, 220, 234, 237, 319,  60, 240,
 241, 242,   0,   0,   0, 248, 379, 176, 254,   0,
   0, 227, 228, 229,   0, 231,   0,   0, 377, 292,
   0,  42, 236,   0,   0,   0, 221, 319, 221, 246,
   0, 250, 252, 319, 256, 259,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0, 230, 221,   0, 288, 319,
   0, 293, 235, 238, 239, 243,   0, 245, 221, 221,
 221, 221,   0, 221, 258, 269, 270, 271, 272, 273,
 274, 275, 276, 277, 278, 279, 280, 281, 282, 283,
 284, 285,   0, 287,   0,   0,   0, 290, 319, 221,
 222, 319, 249, 251, 253, 221, 257, 260,   0,   0,
   0, 233,   0,   0, 244,   0, 255,   0,   0, 393,
 286, 232, 289,   0, 319, 261, 202,   0, 291,   0,
   0, 263, 221, 262, 247 };
#define YYFLAG 		-1000
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define	yydebug		0

/*	parser for yacc output	*/

YYSTYPE yyv[YYMAXDEPTH]; 	/* where the values are stored */
int	yychar = -1; 		/* current input token number */
int	yynerrs = 0;		/* number of errors */
short	yyerrflag = 0;		/* error recovery flag */

char	*yytoknames[1];		/* for debugging */
char	*yystates[1];		/* for debugging */

int
yyparse(void)
{
	short yys[YYMAXDEPTH], *yyps, *yyxi;
	int yyj, yym, yystate, yyn;
	YYSTYPE *yypvt, *yypv;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyps = &yys[-1];
	yypv = &yyv[-1];

yystack:
	/* put a state and value onto the stack */
	if(yydebug >= 3)
		if(yychar < 0 || yytoknames[yychar] == 0)
			printf("char %d in %s", yychar, yystates[yystate]);
		else
			printf("%s in %s", yytoknames[yychar], yystates[yystate]);
	if(++yyps >= &yys[YYMAXDEPTH]) { 
		yyerror("yacc stack overflow"); 
		return 1; 
	}
	*yyps = yystate;
	++yypv;
	*yypv = yyval;

yynewstate:
	yyn = yypact[yystate];
	if(yyn <= YYFLAG)
		goto yydefault; /* simple state */
	if(yychar < 0) {
		yychar = yylex();
		if(yydebug >= 2) {
			if(yychar <= 0)
				printf("lex EOF\n");
			else
			if(yytoknames[yychar])
				printf("lex %s\n", yytoknames[yychar]);
			else
				printf("lex (%c)\n", yychar);
		}
		if(yychar < 0)
			yychar = 0;
	}
	if((yyn += yychar) < 0 || yyn >= YYLAST)
		goto yydefault;
	if(yychk[yyn=yyact[yyn]] == yychar) { /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if(yyerrflag > 0)
			--yyerrflag;
		goto yystack;
	}

yydefault:
	/* default state action */
	if((yyn=yydef[yystate]) == -2) {
		if(yychar < 0) {
			yychar = yylex();
			if(yydebug >= 2)
				if(yychar < 0)
					printf("lex EOF\n");
				else
					printf("lex %s\n", yytoknames[yychar]);
			if(yychar < 0)
				yychar = 0;
		}
		/* look through exception table */
		for(yyxi = yyexca; *yyxi != -1 || yyxi[1] != yystate; yyxi += 2)
			;
		while(*(yyxi+=2) >= 0)
			if(*yyxi == yychar)
				break;
		if((yyn = yyxi[1]) < 0)
			return 0;   /* accept */
	}
	if(yyn == 0) {
		/* error ... attempt to resume parsing */
		switch(yyerrflag) {
		case 0:   /* brand new error */
			yyerror("syntax error");
			if(yydebug) {
				printf("%s", yystates[yystate]);
				if(yytoknames[yychar])
					printf("saw %s\n", yytoknames[yychar]);
				else
				if(yychar >= ' ' && yychar < 0177)
					printf("saw `%c'\n", yychar);
				else
				if(yychar == 0)
					printf("saw EOF\n");
				else
					printf("saw char 0%o\n", yychar);
			}
			++yynerrs;

		case 1:
		case 2: /* incompletely recovered error ... try again */
			yyerrflag = 3;
			/* find a state where "error" is a legal shift action */
			while(yyps >= yys) {
				yyn = yypact[*yyps] + YYERRCODE;
				if(yyn>= 0 && yyn < YYLAST && yychk[yyact[yyn]] == YYERRCODE) {
					yystate = yyact[yyn];  /* simulate a shift of "error" */
					goto yystack;
				}
				/* the current yyps has no shift onn "error", pop stack */
				if(yydebug)
					printf("error recovery pops state %d, uncovers %d\n",
						*yyps, yyps[-1] );
				--yyps;
				--yypv;
			}
			/* there is no state on the stack with an error shift ... abort */
			return 1;

		case 3:  /* no shift yet; clobber input char */
			if(yydebug) {
				printf("error recovery discards ");
				if(yytoknames[yychar])
					printf("%s\n", yytoknames[yychar]);
				else
				if(yychar >= ' ' && yychar < 0177)
					printf("`%c'\n", yychar);
				else
				if(yychar == 0)
					printf("EOF\n");
				else
					printf("char 0%o\n", yychar);
			}
			if(yychar == 0)
				return 1; /* don't discard EOF, quit */
			yychar = -1;
			goto yynewstate;   /* try again in the same state */
		}
	}
	/* reduction by production yyn */
	if(yydebug) {
		char *s;

		printf("reduce %d in:\n\t", yyn);
		for(s = yystates[yystate]; *s; s++) {
			printf("%c", *s);
			if(*s == '\n' && *(s+1))
				printf("\t");
		}
	}
	yyps -= yyr2[yyn];
	yypvt = yypv;
	yypv -= yyr2[yyn];
	yyval = yypv[1];
	yym = yyn;

	/* consult goto table to find next state */
	yyn = yyr1[yyn];
	yyj = yypgo[yyn] + *yyps + 1;
	if(yyj >= YYLAST || yychk[yystate=yyact[yyj]] != -yyn)
		yystate = yyact[yypgo[yyn]];
	switch(yym) {
		
case 1:
# line 718 "gram.y"
{	YYCLEAN;return 2; } break;
case 2:
# line 719 "gram.y"
{	YYCLEAN;return 1; } break;
case 3:
# line 720 "gram.y"
{	YYCLEAN;return 0; } break;
case 4:
# line 722 "gram.y"
{
				set_linkage(yypvt[-1].s);
				bl_level--;
				YYCLEAN;return 1;
			} break;
case 5:
# line 728 "gram.y"
{
				set_linkage(0);
				bl_level++;
				YYCLEAN;return 1;
			} break;
case 6:
# line 733 "gram.y"
{  YYCLEAN;return 1; } break;
case 7:
# line 737 "gram.y"
{	
			PUSH_TEMPLATE_SCOPE();//SYM
// error('d',"template seen: in_class_decl %d", in_class_decl);
			if (in_class_decl) {
				must_be_friend = 1;
				if (templp->in_progress == true) // inside template
					templp->save_templ = new templ_state;
			}
			else must_be_friend = 0;
			templp->start() ;
			templp->formals_in_progress = true;
		 } break;
case 8:
# line 749 "gram.y"
{ in_arg_list = 2; } break;
case 9:
# line 750 "gram.y"
{
			templp->enter_parameters(); 
			templp->formals_in_progress = false;
			in_arg_list = 0;
		 } break;
case 10:
# line 756 "gram.y"
{
			templp->end(yypvt[-0].pn);
			POP_SCOPE(); //SYM
			if (in_class_decl && templp->save_templ) {
				delete templp->save_templ;
				templp->save_templ = 0;
			}
			else { 
				templp->in_progress = false;
				bound_expr_tbl->reinit();
			}
                  //SYM -- goto mod removed
                 } break;
case 12:
# line 772 "gram.y"
{ goto mod; } break;
case 13:
# line 773 "gram.y"
{ goto mod; } break;
case 15:
# line 776 "gram.y"
{ 
			Pname pn = yypvt[-1].pb->aggr();
			/* basetype:aggr() does not return the name for a forward 
		    	 * declaration, so extract it directly */
                    	yyval.p = (pn ? pn : yypvt[-1].pb->b_name);
                    	DECL_TYPE = 0;
		  } break;
case 17:
# line 787 "gram.y"
{ yyval.pn = Ncopy(yypvt[-0].pn) ;} break;
case 18:
# line 791 "gram.y"
{	
				//SYM -- tn stuff removed
				if (yypvt[-0].pn==0) yyval.i = 1; 
			} break;
case 19:
# line 795 "gram.y"
{ goto mod; } break;
case 20:
# line 797 "gram.y"
{ mod: //SYM -- tn stuff removed
				Pname n = yypvt[-0].pn;
				if ( n && n->n_qualifier ) {//SYM
					if ( n->n_qualifier->n_template_arg != template_type_formal )
						UNSET_SCOPE();
					if ( n->n_qualifier == sta_name )
						n->n_qualifier = 0;
				}
			} break;
case 22:
# line 808 "gram.y"
{	Pname n = new name(make_name('A'));
				n->tp = new basetype(ASM,0);
				Pbase(n->tp)->b_name = Pname(yypvt[-2].s);
				yyval.p = n;
			} break;
case 23:
# line 816 "gram.y"
{
				err_name = yypvt[-3].pn;
				if(err_name) err_name->n_initializer = yypvt[-1].pe;
				goto fix;
			} break;
case 24:
# line 822 "gram.y"
{
				Ptype t;
				err_name = yypvt[-1].pn;
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
			} break;
case 25:
# line 854 "gram.y"
{	if ( yychar == LC ) --bl_level;
				Pname n = Nfct(yypvt[-3].p,yypvt[-2].pn,dummy);
				Fargdcl(n->tp,name_unlist(yypvt[-1].nl),n);
				arg_redec( yypvt[-2].pn );
				yyval.pn = n;
			 	if ( yychar == LC ) ++bl_level;
				Ctbl->k_name = n;
			} break;
case 26:
# line 863 "gram.y"
{	Pname n = yypvt[-2].pn;//SYM
				if ( !in_typedef ) {
					Fbody(n->tp) = Pblock(yypvt[-0].p);//SYM
					Finit(n->tp) = yypvt[-1].pn;
				}
				yyval.p = n;
				NOT_EXPECT_ID();
			} break;
case 27:
# line 872 "gram.y"
{
				Pname n = Nfct(yypvt[-4].p,yypvt[-3].pn,dummy);
				Fargdcl(n->tp,name_unlist(yypvt[-2].nl),n);
				yypvt[-0].q->retval.pn = n;
				yyval.p = n;
				NOT_EXPECT_ID();
			} break;
case 28:
# line 880 "gram.y"
{
				if (!templp->in_progress)
					error(&yypvt[-3].pn->where,"syntax error -- did you forget a ';'?");
				Pname n = Nfct(yypvt[-4].p,yypvt[-3].pn,0);
				yyval.p = n;
				NOT_EXPECT_ID();
			} break;
case 29:
# line 890 "gram.y"
{	if ( yychar == LC ) --bl_level;
			 	Pname n = Nfct(defa_type,yypvt[-2].pn,dummy);
				Fargdcl(n->tp,name_unlist(yypvt[-1].nl),n);
				arg_redec( yypvt[-2].pn );
				yyval.pn = n;
			 	if ( yychar == LC ) ++bl_level;
				Ctbl->k_name = n;
			} break;
case 30:
# line 899 "gram.y"
{	Pname n = yypvt[-2].pn;//SYM
				Fbody(n->tp) = Pblock(yypvt[-0].p);//SYM
				if ( yypvt[-1].pn && yypvt[-1].pn->n_list && 
     					ccl && ccl->csu == UNION )  
						error( "multiple initializers in unionK %s::%n", yypvt[-5].pn->string, yypvt[-5].pn );
				Finit(n->tp) = yypvt[-1].pn;
				yyval.p = n;
				NOT_EXPECT_ID();
			} break;
case 31:
# line 909 "gram.y"
{
				Pname n = Nfct(defa_type,yypvt[-3].pn,dummy);
				Fargdcl(n->tp,name_unlist(yypvt[-2].nl),n);
				yypvt[-0].q->retval.pn = n;
				yyval.p = n;
				NOT_EXPECT_ID();
			} break;
case 32:
# line 917 "gram.y"
{
				if (explicit_template_definition  == 0 )
					error(&yypvt[-3].pn->where,"badD of%n -- did you forget a ';'?",yypvt[-3].pn);
				else {
			             Pname n = pti->get_tname();
				     if (yypvt[-3].pn->n_oper == DTOR)
					error('s',"explicitYZL for destructor of specializedYC%n -- please drop the parameter list",n);
				     else
					error('i',"specialializedYC%n: declaration problem: %s",n,yypvt[-3].pn->string);
				     error('i', "cannot recover from previous error" );
				}
				Pname n = Nfct(defa_type,yypvt[-3].pn,0);
				yyval.p = n;
				NOT_EXPECT_ID();
			} break;
case 33:
# line 935 "gram.y"
{	PUSH_ARG_SCOPE();//SYM
                        	arg_redec(yypvt[-0].pn);
                        	Ctbl->k_name = yypvt[-0].pn;
                   	} break;
case 34:
# line 940 "gram.y"
{
				Finit(yypvt[-3].pn->tp) = yypvt[-1].pn;
				Pfct(yypvt[-3].pn->tp)->body = Pblock(yypvt[-0].p);
				yyval.pn = yypvt[-3].pn;
				NOT_EXPECT_ID();
			} break;
case 35:
# line 950 "gram.y"
{
			// if parsing implicit inline def, save body
			//   of function for parsing after class def
			if ( Ctbl->k_id != ARG )
				error('i',"expectingA table in check_inline!");
			switch ( NEXTTOK() ) {
			case LC: case COLON:
				if ( in_class_decl ) {
					// mem or friend inline def
					// save text of mem_init & ftn
					la_backup(yychar,yylval);
					// yylval used as dummy...
					la_backup(FDEF, yylval);
					if ( yylval.q = save_text() ) {
						yychar = EMPTY;
						POP_SCOPE();//SYM
					} else { // syntax error
						// just parse in place
						yylex(); // FDEF
						yylex();
						yychar = NO_ID;
						hoist_al();//SYM
					}
				} // if in_class_decl
				//SYM -- else non-nested ftn def
				//SYM -- arg table will become block table
				break;
			default:
				la_backup(yychar,yylval);
				yychar = NO_ID; // 'graceful' recovery
				hoist_al();//SYM
				break;
			}
		   } break;
case 36:
# line 986 "gram.y"
{ ++in_binit_list; } break;
case 37:
# line 987 "gram.y"
{	
				yyval.p = yypvt[-0].p; 
				in_arg_list = 0;
				--in_binit_list;
			} break;
case 38:
# line 993 "gram.y"
{	yyval.p = 0; } break;
case 39:
# line 997 "gram.y"
{ yyval.p = yypvt[-0].p; } break;
case 40:
# line 999 "gram.y"
{ yyval.pn = yypvt[-0].pn;  yyval.pn->n_list = yypvt[-2].pn; } break;
case 41:
# line 1003 "gram.y"
{
				yyval.pn = new name;
				yyval.pn->n_initializer = yypvt[-1].pe;
			} break;
case 42:
# line 1008 "gram.y"
{
				Pname n = Ncopy(yypvt[-3].pn);
				n->base = yypvt[-3].pn->base;
				n->tp = yypvt[-3].pn->tp;
				n->n_initializer = yypvt[-1].pe;
				yyval.pn = n;
			} break;
case 43:
# line 1023 "gram.y"
{	if (yypvt[-0].pn == 0)
					error("badAD");
				else if (yypvt[-0].pn->tp->base == FCT)
					error("FD inAL (%n)",yypvt[-0].pn);
				else if (yypvt[-1].p)
                                        yypvt[-1].nl->add_list(yypvt[-0].pn);
				else
					yyval.nl = new nlist(yypvt[-0].pn);
			} break;
case 44:
# line 1033 "gram.y"
{
				PUSH_ARG_SCOPE();//SYM
                                yyval.p = 0; 
			} break;
case 46:
# line 1041 "gram.y"
{
                                if ( in_typedef ) {
                                        error("Tdef field");
                                        in_typedef = 0;
                                }
                        //      ENTER_NAME(yypvt[-1].pn);
                        } break;
case 47:
# line 1049 "gram.y"
{	yyval.p = yypvt[-3].pn;
				yyval.pn->tp = new basetype(FIELD,yypvt[-0].pn);
		 	} break;
case 48:
# line 1053 "gram.y"
{	yyval.p = new name;
				yyval.pn->tp = new basetype(FIELD,yypvt[-0].pn);
                                if ( in_typedef ) {
                                        error("Tdef field");
                                        in_typedef = 0;
                                }
			} break;
case 49:
# line 1061 "gram.y"
{
                        //      ENTER_NAME(yypvt[-1].pn);
                        } break;
case 50:
# line 1065 "gram.y"
{       Pexpr e = yypvt[-0].pe;
                                if (e == dummy) error("emptyIr");
                                yypvt[-3].pn->n_initializer = e;
                                init_seen = 0;
                        } break;
case 51:
# line 1073 "gram.y"
{	Pname n = yypvt[-0].pn;
				if (n) {
				    yyval.nl = new nlist(n);
				    if ( n->n_qualifier ) {//SYM
					if ( n->n_qualifier->n_template_arg != template_type_formal )
						UNSET_SCOPE();
					if ( n->n_qualifier == sta_name )
					    n->n_qualifier = 0;
				    }
				}
				if ( NEXTTOK() == CM && la_look() == TNAME ) 
					EXPECT_ID();
			} break;
case 52:
# line 1087 "gram.y"
{	Pname n = yypvt[-0].pn;
				if (yypvt[-2].p)
					if (n)
						yypvt[-2].nl->add(n);
					else
						error("DL syntax");
				else {
					if (n) yyval.nl = new nlist(n);
					error("DL syntax");
				}
				if ( n ) {
				    if ( n->n_qualifier ) {//SYM
					if ( n->n_qualifier->n_template_arg != template_type_formal )
						UNSET_SCOPE();
					if ( n->n_qualifier == sta_name )
					    n->n_qualifier = 0;
				    }
				}
				if ( NEXTTOK() == CM && la_look() == TNAME ) 
					EXPECT_ID();
			} break;
case 53:
# line 1111 "gram.y"
{ 
				extern int co_hack;
				co_hack = 1;
				/*$$ = Ndata($1,name_unlist($<nl>2));*/
				Pname n = Ndata(yypvt[-2].p,name_unlist(yypvt[-1].nl)); 
//error('d',"data_dcl:type decl_list sm: %n%t in_typedef%t in_tag%n",n,n->tp,in_typedef,in_tag);
				//SYM redef check removed
				in_typedef = 0;
				in_friend = 0;
				in_tag = 0;
				co_hack = 0;
				DECL_TYPE = 0; 
				yyval.p = n;
			} break;
case 54:
# line 1126 "gram.y"
{
				yyval.p = yypvt[-1].pb->aggr(); 
				in_typedef = 0;
				in_friend = 0;
				in_tag = 0;
				DECL_TYPE = 0; 
			} break;
case 55:
# line 1138 "gram.y"
{
			templp->parameters_in_progress++;
			in_arg_list = 2;
			check_decl();
		  } break;
case 56:
# line 1144 "gram.y"
{
			templp->parameters_in_progress--;
			if (!templp->parameters_in_progress)
				in_arg_list = 0;
		  } break;
case 57:
# line 1150 "gram.y"
{ yyval.pn = templp->check_tname(yypvt[-0].pn) ; } break;
case 58:
# line 1152 "gram.y"
{ 
			int sm = NEXTTOK()==SM;
			if (in_friend) in_friend += sm;
			bit flag=0;
			if (dtpt_opt && in_typedef &&  
				!templp->parameters_in_progress &&
				curloc.file == first_file)
				flag=1;
		    	yyval.pn = parametrized_typename(yypvt[-3].pn,
						  (expr_unlist(yypvt[-1].el)),in_friend) ; 
			if (flag)
				righttname=yyval.pn;
		  } break;
case 59:
# line 1166 "gram.y"
{ extern Pbase any_type;
		    error("%n was not aZizedT.", yyval.pn) ;
                    yyval.pn= yypvt[-3].pn->tdef() ;
                    yyval.pn->tp = any_type ; } break;
case 60:
# line 1175 "gram.y"
{ 
				yyval.p = new basetype(yypvt[-0].t,0); 
				if ( yypvt[-0].t == TYPEDEF ) {
					in_typedef = yyval.pt;
// error('d',"typedef: ccl %t ", ccl, yypvt[-0].pn);
				}
				else if ( yypvt[-0].t == FRIEND ) {
					in_friend = 1;
					must_be_friend = 0;
				}
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			} break;
case 61:
# line 1188 "gram.y"
{	yyval.p = new basetype(EXTERN,0);
				yyval.pb->b_linkage = yypvt[-0].s;
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			} break;
case 62:
# line 1193 "gram.y"
{
				yyval.p = new basetype(TYPE,yypvt[-0].pn); 
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			} break;
case 63:
# line 1198 "gram.y"
{ // modified tn_list TNAME
				yyval.p = new basetype(TYPE,yypvt[-0].pn);
				//xxx qualifier currently ignored...
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			} break;
case 66:
# line 1206 "gram.y"
{ 
				if (DECL_TYPE == TNAME)
					yyval.p = new basetype(TYPE,yypvt[-0].pn); 
		//	else if (DECL_TYPE == TSCOPE)
		//	yyval.p = 0;
				else
				if (DECL_TYPE == 0 &&
					yypvt[-0].p->base == TNAME)
						yyval.p = new basetype(TYPE,yypvt[-0].pn); 
				else
					yyval.p = new basetype(yypvt[-0].t,0); 
				DECL_TYPE = -1;
			} break;
case 68:
# line 1223 "gram.y"
{ 
				if ( DECL_TYPE != -1 ) {
					switch (yypvt[-1].pb->base) { 
					case COBJ: case EOBJ:
						Pbase bt;	
						bt = new basetype(0,0);
						*bt = *yypvt[-1].pb;
						DEL(yypvt[-1].pb);
						yypvt[-1].pb = bt;
					}
					yyval.p = yypvt[-1].pb->type_adj(yypvt[-0].t); 
				}
				DECL_TYPE = 0;
			} break;
case 69:
# line 1238 "gram.y"
{
//error('d',"decl_type: %d  $1: %t  $2: %n",DECL_TYPE,yypvt[-1].pb,yypvt[-0].pn);
				if ( DECL_TYPE != -1 ) 
			 		yyval.p = yypvt[-1].pb->name_adj(yypvt[-0].pn);
			/*XXX*/	else if(yypvt[-1].pb==0) yyval.p=new basetype(TYPE,yypvt[-0].pn);
				DECL_TYPE = 0;
			} break;
case 70:
# line 1245 "gram.y"
{ yyval.p = yypvt[-1].pb->base_adj(yypvt[-0].pb); } break;
case 71:
# line 1246 "gram.y"
{ yyval.p = yypvt[-1].pb->base_adj(yypvt[-0].pb); } break;
case 72:
# line 1248 "gram.y"
{ 
				if (DECL_TYPE == TYPE) {
					switch (yypvt[-1].pb->base) { 
					case COBJ: case EOBJ: 
						{
						Pbase bt;
						bt = new basetype(0,0);
						*bt = *yypvt[-1].pb;
						DEL(yypvt[-1].pb);
						yypvt[-1].pb = bt;
						}
					}
					yyval.p = yypvt[-1].pb->type_adj(yypvt[-0].t);  
				}
			/*XXX*/	else if (DECL_TYPE == TSCOPE) {
			/*XXX*/		error('i',"T decl_marker(tscope)");
			/*XXX*/	//	yyval.p = yypvt[-1].p;//ignore(?)
			/*XXX*/	}
				else
					yyval.p = yypvt[-1].pb->name_adj(yypvt[-0].pn); 
				DECL_TYPE = -1;
			} break;
case 73:
# line 1272 "gram.y"
{in_arg_list = 2; check_decl();} break;
case 74:
# line 1275 "gram.y"
{yypvt[-2].el->add(new expr(ELIST,yypvt[-0].pe,NULL)) ; } break;
case 75:
# line 1277 "gram.y"
{ in_arg_list=0; yyval.el = new elist(new expr(ELIST,yypvt[-0].pe,NULL)); } break;
case 76:
# line 1281 "gram.y"
{
				yyval.p = new name;
			} break;
case 77:
# line 1285 "gram.y"
{
				yyval.p = yypvt[-1].p;
				in_arg_list = 0;
				hoist_al();
			} break;
case 78:
# line 1291 "gram.y"
{
				Ptyp(yypvt[-1].p) = yypvt[-0].pn->tp;
				yypvt[-0].pn->tp = (Ptype)yypvt[-1].p;
				yyval.p = yypvt[-0].p;
				NOT_EXPECT_ID();
			} break;
case 79:
# line 1298 "gram.y"
{
				Freturns(yypvt[-0].p) = yypvt[-1].pn->tp;
				yypvt[-1].pn->tp = (Ptype)yypvt[-0].p;
			} break;
case 80:
# line 1303 "gram.y"
{
				Vtype(yypvt[-0].p) = yypvt[-1].pn->tp;
				yypvt[-1].pn->tp = (Ptype)yypvt[-0].p;
			} break;
case 81:
# line 1309 "gram.y"
{ yyval.p = Ncast(yypvt[-1].p,yypvt[-0].pn); } break;
case 82:
# line 1312 "gram.y"
{
				yypvt[-0].pn->n_template_arg = template_actual_arg_dummy;
				yyval.pe = yypvt[-0].pn; /* keep yacc happy */ 
			} break;
case 83:
# line 1317 "gram.y"
{ 
				if (yypvt[-0].pe == dummy) error("emptyYZL");
				yyval.pe = yypvt[-0].pe; 
			} break;
case 84:
# line 1325 "gram.y"
{ yyval.p = enumcheck( yypvt[-0].pn); } break;
case 85:
# line 1327 "gram.y"
{
			if ( DECL_TYPE != TNAME ) {
				error("syntax error -- enum%k",yypvt[-0].t);
				yyval.p = 0;
			} else 
				yyval.p = enumcheck( yypvt[-0].pn);
		} break;
case 86:
# line 1335 "gram.y"
{
			if ( DECL_TYPE != TNAME ) {
				error("enum declaration syntax");
				yyval.p = 0;
			} else 
				yyval.pn = enumcheck(yypvt[-0].pn);
			if (in_typedef && in_typedef->base == 0)
				in_typedef->defined = TNAME_SEEN;
			//xxx qualifier currently ignored...
		} break;
case 87:
# line 1347 "gram.y"
{ ++in_class_decl; } break;
case 88:
# line 1348 "gram.y"
{ --in_class_decl; yyval.p = end_enum(0,yypvt[-1].nl); } break;
case 89:
# line 1349 "gram.y"
{ ++in_class_decl; } break;
case 90:
# line 1350 "gram.y"
{ --in_class_decl; yyval.p = end_enum(yypvt[-4].pn,yypvt[-1].nl); } break;
case 91:
# line 1351 "gram.y"
{ yyval.pb = (Pbase)yypvt[-0].pn->tp; } break;
case 92:
# line 1355 "gram.y"
{	if (yypvt[-0].p) yyval.nl = new nlist(yypvt[-0].pn); } break;
case 93:
# line 1357 "gram.y"
{	if( yypvt[-0].p)
					if (yypvt[-2].p)
						yypvt[-2].nl->add(yypvt[-0].pn);
					else
						yyval.nl = new nlist(yypvt[-0].pn);
			} break;
case 96:
# line 1368 "gram.y"
{ 
				yyval.pn = NULL;
				error("emptyYZL");
			} break;
case 97:
# line 1377 "gram.y"
{ templp->collect(yypvt[-1].t, yypvt[-0].pn) ; } break;
case 98:
# line 1379 "gram.y"
{templp->collect(Ndata(yypvt[-1].p,yypvt[-0].pn)); } break;
case 99:
# line 1386 "gram.y"
{	yyval.p = yypvt[-0].pn; } break;
case 100:
# line 1388 "gram.y"
{	Ptyp(yypvt[-1].p) = yypvt[-0].pn->tp;
				yypvt[-0].pn->tp = (Ptype)yypvt[-1].p;
				yyval.p = yypvt[-0].p;
			} break;
case 101:
# line 1393 "gram.y"
{	Vtype(yypvt[-0].p) = yypvt[-1].pn->tp;
				yypvt[-1].pn->tp = (Ptype)yypvt[-0].p;
			} break;
case 102:
# line 1397 "gram.y"
{	Freturns(yypvt[-0].p) = yypvt[-1].pn->tp;
				yypvt[-1].pn->tp = (Ptype)yypvt[-0].p;
			} break;
case 103:
# line 1401 "gram.y"
{
				yyval.p = yypvt[-1].p;
				in_arg_list = 0;
				hoist_al();
			} break;
case 104:
# line 1410 "gram.y"
{
				if ( yypvt[-0].pn->n_oper != TNAME )
					insert_name(yypvt[-0].pn,Ctbl);
				yyval.p = yypvt[-0].pn;
				yyval.pn->tp = moe_type;
			} break;
case 105:
# line 1417 "gram.y"
{
				if ( yypvt[-0].pn->n_oper != TNAME )
					insert_name(yypvt[-0].pn,Ctbl);
			} break;
case 106:
# line 1422 "gram.y"
{	yyval.p = yypvt[-3].pn;
				yyval.pn->tp = moe_type;
				yyval.pn->n_initializer = yypvt[-0].pe;
			} break;
case 107:
# line 1427 "gram.y"
{	yyval.p = 0; } break;
case 108:
# line 1431 "gram.y"
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
				++bl_level; // scope weirdness!
				++in_mem_fct;
			} break;
case 109:
# line 1447 "gram.y"
{
				--in_mem_fct;
				--bl_level; // scope weirdness!
				if ( yychar == ID ) {
					// (yuk!) adjust lex level
					--yylval.pn->lex_level;
				}
				ccl->mem_list = name_unlist(yypvt[-3].nl);
// error('d',"ccl: %t templ_friends: %d", ccl, templ_friends);
				ccl->templ_friends = templ_friends; templ_friends = 0;
				if ( --in_class_decl )  // nested class
					// continue to parse enclosing class
					parsing_class_members = 1;
				//SYM -- tn stuff removed
                        	POP_SCOPE();//SYM
				if ( Ctbl->k_id == TEMPLATE ) {
					// remove intermediate template table
					//    from scope of class
					ccl->k_tbl->k_next = Ctbl->k_next;
				}

				if (pti) {
					pti->explicit_inst();
					Pname nnn = yyval.pt->bname();
// error('d',"ccl: %s nnn: %s", ccl->string, nnn->string);
					nnn->string = ccl->string;
					explicit_template_definition = 0;
					pti = 0;
				}

				end_cl();
				declTag = 1;
			} break;
case 110:
# line 1481 "gram.y"
{ aggrcheck:
				yyval.pb = (Pbase)yypvt[-0].pn->tp; 
				if ( yyval.p == 0 ) {
					if (templp->parameters_in_progress)
						error("TX for%n -- did you misdeclare aY?",yypvt[-0].pn);
					else error("TX for %n",yypvt[-0].pn);
					error('i', "cannot recover from previous error" );
				}

				if ( yyval.p->base == TYPE ) {
					Pname nx = yyval.pb->b_name;
					yyval.pb = (Pbase)nx->tp;
					if ( yyval.p->base != COBJ
					||   strcmp(nx->string,yypvt[-0].pn->string)
					)
						error("%n of type%t redeclared as%k.",yypvt[-0].pn,yyval.pb,yypvt[-1].t);
				} else if ( yyval.p->base != COBJ )
					error("%n of type%t redeclared as%k",yypvt[-0].pn,yyval.pb,yypvt[-1].t);
				check_tag();
			} break;
case 111:
# line 1502 "gram.y"
{ 
                    /* don't place the template on the instantiation list if it is
                     * a friend declaration or a foward declaration of a specialization
                     * friend class x<int> and struct x<int>; */

                    dont_instantiate = NEXTTOK()==SM;
		    Pexpr e=0;
		    if (dont_instantiate && in_friend == 0) {
			// *** this code could be used for forward declaration
			Ptempl t = templp->is_template(yypvt[-3].pn);

			// must have seen a definition of template class
			if (t == 0) {
				error("explicitC instance of a nonYC%n",yypvt[-3].pn);
				error('i', "cannot recover from previous error" );
			}

			// make sure the explicit arguments are ok
			e = expr_unlist(yypvt[-1].el);
			t->check_actual_args(e);

			// watch out for redefinition -- if exists,
			// use forward declaration or create instance
			pti = t->get_match(e,0,false);
			if ( pti ) { 
				if (pti->get_class()->class_base == INSTANTIATED)
					error("ZC%n multiply instantiated",yypvt[-3].pn);
			}
			else pti = new templ_inst(e,t,yypvt[-4].t);
			pti->inst_formals = t->get_formals();

			error('s',"forwardD of a specialized version ofY%n",yypvt[-3].pn);
			error('C',"\tclass %n",pti->get_tname()); 
			error('c'," -- did you mean a general forward declaration of theY?\n");
			error('C',"\tif so, use:  template <formal-parameters> class %n;\n",yypvt[-3].pn);
	            }

		    if (!e)
		    {
		        e = expr_unlist(yypvt[-1].el);
                    }
                    Pname p = parametrized_typename(yypvt[-3].pn, e, in_friend);
                    dont_instantiate = 0;
                    yyval.pb = (Pbase)p->tp;
                    check_tag();
                  } break;
case 112:
# line 1549 "gram.y"
{
				goto aggrcheck;
			} break;
case 115:
# line 1559 "gram.y"
{ yyval.pbc = yypvt[-0].pbc; } break;
case 116:
# line 1560 "gram.y"
{ yyval.pbc = 0; } break;
case 118:
# line 1565 "gram.y"
{	if (yypvt[-0].pbc) { yyval.pbc = yypvt[-0].pbc; yyval.pbc->next = yypvt[-2].pbc; } } break;
case 119:
# line 1568 "gram.y"
{ yyval.pbc = dobase(0,yypvt[-0].pn); } break;
case 120:
# line 1569 "gram.y"
{ yyval.pbc = dobase(yypvt[-1].t,yypvt[-0].pn); } break;
case 121:
# line 1570 "gram.y"
{ yyval.pbc = dobase(0,yypvt[-0].pn,yypvt[-1].t); } break;
case 122:
# line 1571 "gram.y"
{ yyval.pbc = dobase(yypvt[-2].t,yypvt[-0].pn,yypvt[-1].t); } break;
case 123:
# line 1572 "gram.y"
{ yyval.pbc = dobase(yypvt[-1].t,yypvt[-0].pn,yypvt[-2].t); } break;
case 124:
# line 1576 "gram.y"
{
				Pname n = start_cl(yypvt[-1].t,0,0);
				PUSH_CLASS_SCOPE(n);//SYM
				ccl->k_tbl = Ctbl;//SYM
				yyval.p = Pbase(n->tp);
				parsing_class_members = 1;
				//SYM -- tn stuff removed
				in_class_decl++;
				SAVE_STATE();
			} break;
case 125:
# line 1588 "gram.y"
{
				Pname n = start_cl(yypvt[-3].t,yypvt[-2].pn,yypvt[-1].pbc);
				PUSH_CLASS_SCOPE(n);//SYM
				ccl->k_tbl = Ctbl;//SYM
				yyval.p = Pbase(n->tp);
				parsing_class_members = 1;
				//SYM -- tn stuff removed
				in_class_decl++;
				SAVE_STATE();
			} break;
case 126:
# line 1599 "gram.y"
{
			// LC increments bl_level by 1
			if ( bl_level > 1 )
			     error('s', "specializedY%n not at global scope",yypvt[-5].pn);
			explicit_template_definition = 1;
			Ptempl t = templp->is_template(yypvt[-5].pn);

			// must have seen a definition of template class
			if (t == 0 || !t->defined) {
				error("YC%n must be defined prior to an explicitC instance",yypvt[-5].pn);
				error('i', "cannot recover from previous error" );
			}

			// make sure the explicit arguments are ok
			Pexpr e = expr_unlist(yypvt[-3].el);
			t->check_actual_args(e);

			// watch out for redefinition -- if exists,
			// use forward declaration or create instance
			pti = t->get_match(e,0,false);
			if ( pti ) { 
				if (pti->get_class()->class_base == INSTANTIATED)
					error("ZC%n multiply instantiated",yypvt[-5].pn);
			}
			else pti = new templ_inst(e,t,yypvt[-6].t);

			Pname n = start_cl(yypvt[-6].t,pti->get_tname(),yypvt[-1].pbc);
                        Pbase(n->tp)->b_name->n_redefined = 1;
			PUSH_CLASS_SCOPE(n);//SYM
			ccl->k_tbl = Ctbl;//SYM
			yyval.p = Pbase(n->tp);
			parsing_class_members = 1;
			in_class_decl++;
			SAVE_STATE();
			} break;
case 127:
# line 1636 "gram.y"
{ yyval.p = yypvt[-0].pn; } break;
case 128:
# line 1637 "gram.y"
{ yyval.p=yypvt[-0].p; } break;
case 129:
# line 1640 "gram.y"
{ yyval.p = yypvt[-0].pn; } break;
case 130:
# line 1641 "gram.y"
{ yyval.p=yypvt[-0].p; } break;
case 131:
# line 1645 "gram.y"
{
				if (yypvt[-0].p) {
					if (yypvt[-1].p)
						yypvt[-1].nl->add_list(yypvt[-0].pn);
					else
						yyval.nl = new nlist(yypvt[-0].pn);
				}
				in_friend = 0;
			} break;
case 132:
# line 1654 "gram.y"
{ yyval.p = 0; } break;
case 133:
# line 1656 "gram.y"
{
// error('d', "ZizedTD must be atG, notC scope" );
				if (must_be_friend) {
					error("non-friend ZizedTD must be atG, notC scope" );
					error('i', "cannot recover from previous error" );
				}
  				templ_friends = new cons(templp->parsed_template,templ_friends);
				templp->parsed_template = 0;
			} break;
case 135:
# line 1669 "gram.y"
{
				fct_friend1:
				if (in_friend &&
				    yypvt[-1].pn &&
				    yypvt[-1].pn->n_qualifier &&
				    yypvt[-1].pn->n_qualifier->n_template_arg != template_type_formal)
					UNSET_SCOPE();
			} break;
case 136:
# line 1678 "gram.y"
{
				goto fct_friend1;
			} break;
case 137:
# line 1682 "gram.y"
{
				fct_friend2:
				if (in_friend &&
				    yypvt[-0].pn &&
				    yypvt[-0].pn->n_qualifier &&
				    yypvt[-0].pn->n_qualifier->n_template_arg != template_type_formal)
					UNSET_SCOPE();
			} break;
case 138:
# line 1691 "gram.y"
{
				goto fct_friend2;
			} break;
case 140:
# line 1696 "gram.y"
{	yyval.p = new name;
				yyval.pn->base = yypvt[-1].t;
			} break;
case 141:
# line 1700 "gram.y"
{	Pname n = Ncopy(yypvt[-1].pn);
				if (n->n_oper == TYPE) {
					error('s',"visibilityD for conversion operator");
					// n->tp = Ptype(n->n_initializer);
					n->tp = Ptype(n->cond);
					n->cond = 0;
					// n->n_initializer = 0;
					n->n_oper = 0;
					sig_name(n);
				}
				n->n_qualifier = yypvt[-2].pn;
				n->base = PR;
				yyval.p = n;
				if ( yypvt[-2].pn && yypvt[-2].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();//SYM
			} break;
case 142:
# line 1730 "gram.y"
{ yyval.p = yypvt[-0].pn; } break;
case 143:
# line 1732 "gram.y"
{	yyval.p = Ncopy(yypvt[-0].pn);
				yyval.pn->n_oper = DTOR;
			} break;
case 144:
# line 1736 "gram.y"
{	yyval.p = new name(oper_name(yypvt[-0].t));
				yyval.pn->n_oper = yypvt[-0].t;
			} break;
case 145:
# line 1740 "gram.y"
{	Pname n = yypvt[-0].pn;
				n->string = "_type";
				n->n_oper = TYPE;
				n->cond = Pexpr(n->tp);
				// n->n_initializer = Pexpr(n->tp);
				n->tp = 0;
				yyval.p = n;
			} break;
case 160:
# line 1764 "gram.y"
{	yyval.t = CALL; } break;
case 161:
# line 1765 "gram.y"
{	yyval.t = DEREF; } break;
case 167:
# line 1771 "gram.y"
{	yyval.t = NEW; --in_new; } break;
case 168:
# line 1772 "gram.y"
{	yyval.t = DELETE; } break;
case 169:
# line 1773 "gram.y"
{	yyval.t = REF; } break;
case 170:
# line 1774 "gram.y"
{	yyval.t = CM; } break;
case 171:
# line 1775 "gram.y"
{	yyval.t = REFMUL;
					if (yypvt[-0].t == DOT) error(".* cannot be overloaded");
				} break;
case 172:
# line 1780 "gram.y"
{ yyval.pn = SET_SCOPE(yypvt[-0].pn); } break;
case 173:
# line 1784 "gram.y"
{   if ( yypvt[-0].pn != sta_name ) {
				Pname n = yypvt[-0].pn;
				char *str = 0, *str2 = 0, *s = n->string;
				if (n->n_template_arg != template_type_formal) {
				    n = n->tp->is_cl_obj();
				    if ( n ) str = s = get_classname(n->string);
				}
				if ( n && NEXTTOK() == TNAME
				&& strcmp(s,str2=get_classname(yylval.pn->string))==0){
					// ctor -- change to ID to avoid
					//    parsing as type spec
					yychar = ID;
					yylval.pn = Ncopy(yylval.pn);
					yylval.pn->n_oper = TNAME;
				}
				if ( str ) delete [] str;
				if ( str2 ) delete [] str2;
			    }
			    yyval.pn = yypvt[-0].pn;
			} break;
case 174:
# line 1805 "gram.y"
{//SYM
			   yyval.pn = yypvt[-0].pn;
			   if ( yypvt[-0].pn == sta_name ) {
			   	error("scope qualifier syntax");
			   } else {
// error('d',"tn_list: tn_list tscope: pn2: %s", yypvt[-0].pn->string);
				Pname cn = yypvt[-0].pn;
				char *str = 0, *str2 = 0, *s = cn->string;
				if (cn->n_template_arg != template_type_formal){
				    cn = yypvt[-0].pn->tp->is_cl_obj();
				    if (cn) str = s = get_classname(cn->string);
				}
				if ( cn && NEXTTOK() == TNAME
				&& strcmp(s,str2=get_classname(yylval.pn->string))==0){
					// ctor -- change to ID to avoid
					//    parsing as type spec
					yychar = ID;
					yylval.pn = Ncopy(yylval.pn);
					yylval.pn->n_oper = TNAME;
				}
				if ( str ) delete [] str;
				if ( str2 ) delete [] str2;
				if ( yypvt[-1].pn != sta_name
				&&   yypvt[-1].pn->n_template_arg != template_type_formal){
				    Pname cx = yypvt[-1].pn->tp->is_cl_obj();
				    if ( cx ) // cx::cn::
					if ( check_if_base(Pclass(cx->tp),Pclass(cn->tp)) )
						error("%n ::%n :: --%n not aM of%n",cx,cn,cn,cx);
				}
			    }
			} break;
case 175:
# line 1839 "gram.y"
{	
				yyval.pn = yypvt[-0].pn;
				if (in_typedef && in_typedef->base == 0)
					in_typedef->defined = TNAME_SEEN;
				//xxx qualifier currently ignored...
				// yyval.pn = Ncopy( yypvt[-0].pn );
				// yyval.pn->n_oper = TNAME;
				// yyval.pn->n_qualifier = yypvt[-1].pn;
			} break;
case 176:
# line 1849 "gram.y"
{	
				yyval.pn = yypvt[-0].pn;
				if (in_typedef && in_typedef->base == 0)
					in_typedef->defined = TNAME_SEEN;
			//	yyval.pn = Ncopy( yypvt[-0].pn );
			//	yyval.pn->n_oper = TNAME;
			} break;
case 177:
# line 1859 "gram.y"
{ yyval.i = 0; } break;
case 178:
# line 1861 "gram.y"
{ /* const/volatile function */
				switch ( yypvt[-0].t ) {
				case VOLATILE:
					error('s',"volatile functions");
					break;
				case CONST:
					yyval.i = (yypvt[-1].i | 1);
					break;
				default:
					if ( NEXTTOK() != SM
					&&   yychar != COLON
					&&   yychar != LC ) {
						la_backup(yychar,yylval);
						yylval.t = yypvt[-0].t;
						la_backup(TYPE,yylval);
						yylval.t = SM;
						yychar = SM;
						error("syntax error: unexpected%k (did you forget a `;'?)",yypvt[-0].t);
					} else error("FD syntax: unexpected%k",yypvt[-0].t);
					break;
				}
 			} break;
case 179:
# line 1884 "gram.y"
{ yyval.i = yypvt[-4].i; } break;
case 180:
# line 1887 "gram.y"
{ yyval.pl = 0; } break;
case 181:
# line 1889 "gram.y"
{ yyval.pl = 0; } break;
case 182:
# line 1893 "gram.y"
{	Freturns(yypvt[-0].p) = yypvt[-1].pn->tp;
				yypvt[-1].pn->tp = yypvt[-0].pt;
			} break;
case 183:
# line 1897 "gram.y"
{ /* function with no argument */
 				yypvt[-3].pn->tp = new fct(yypvt[-3].pn->tp,0,1);
 				Pfct(yypvt[-3].pn->tp)->f_const = (yypvt[-0].i & 1);
 			} break;
case 184:
# line 1902 "gram.y"
{	Pname n = yypvt[-1].pn;
				yyval.p = Ncopy(n);
				//??? what if tname is qualified ???
				//SYM -- change -- do not if ctor def...
				if ( !in_typedef
				&&  (ccl==0 || strcmp(n->string,ccl->string)) )
					n->hide();
				yyval.pn->n_oper = TNAME;
				Freturns(yypvt[-0].p) = yyval.pn->tp;
				yyval.pn->tp = yypvt[-0].pt;
			} break;
case 185:
# line 1918 "gram.y"
{	
				yypvt[-3].pn->tp = new fct(yypvt[-3].pn->tp,yypvt[-1].pn,1); 
 				in_arg_list = 0;
 				//SYM end_al(yypvt[-2].pl,0);
 				POP_SCOPE();//SYM
				//RESTORE_STATE();
			} break;
case 186:
# line 1926 "gram.y"
{
				Pptr p = new ptr( PTR, 0 );
				Ptyp(p) = new basetype(TYPE,yypvt[-5].pn);
				Freturns( yypvt[-0].p ) = Ptype(p);
				yypvt[-2].pn->tp = yypvt[-0].pt;
			//SYM -- insert in table if not done elsewhere...
				if ( yypvt[-2].pn->n_oper != TNAME && !in_typedef ) {
					insert_name(yypvt[-2].pn,Ctbl);
				}
				yyval.p = yypvt[-2].pn;
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			} break;
case 187:
# line 1939 "gram.y"
{
				Pptr p = new ptr( RPTR, 0 );
				Ptyp(p) = new basetype(TYPE,yypvt[-5].pn);
				Freturns( yypvt[-0].p ) = Ptype(p);
				yypvt[-2].pn->tp = yypvt[-0].pt;
			//SYM -- insert in table if not done elsewhere...
				if ( yypvt[-2].pn->n_oper != TNAME && !in_typedef ) {
					insert_name(yypvt[-2].pn,Ctbl);
				}
				yyval.p = yypvt[-2].pn;
				if (DECL_TYPE == -1) DECL_TYPE = 0;
			} break;
case 188:
# line 1952 "gram.y"
{	Pname n = yypvt[-3].pn;
				yyval.p = Ncopy(yypvt[-3].pn);
				//??? what about qualified tname?
				//SYM -- change -- do not if ctor def...
			//XXXXX defer until name::normalize()?
				if ( !in_typedef
				&&  (ccl==0 || strcmp(n->string,ccl->string)) )
					n->hide();
				yyval.pn->n_oper = TNAME;
				yyval.pn->tp = new fct(0,yypvt[-1].pn,1);
			} break;
case 189:
# line 1964 "gram.y"
{ /* function with no argument */
				Pname n = yypvt[-3].pn;
				yyval.p = Ncopy(yypvt[-3].pn);
				//SYM -- change -- do not if ctor def...
				if ( !in_typedef
				&&  (ccl==0 || strcmp(n->string,ccl->string)) )
					n->hide();
 				yyval.pn->n_oper = TNAME;
 				yyval.pn->tp = new fct(0,0,1);
 				Pfct(yyval.pn->tp)->f_const = (yypvt[-0].i & 1);
			} break;
case 190:
# line 1976 "gram.y"
{	memptrdcl(yypvt[-3].pn,yypvt[-5].pn,yypvt[-0].pt,yypvt[-2].pn);
				yyval.p = yypvt[-2].p;
			} break;
case 191:
# line 1980 "gram.y"
{//SYM -- insert in table if appropriate...
			 //SYM    n_oper == TNAME => tname already hidden
			 //SYM    other !=0 values of n_oper => op or dtor
			 //SYM -- enter non-oper names as well as TNAMEs
			 //SYM    in parsing table to handle "1.5 namespace"
			 //SYM    in all scopes, since dcl does not build
			 //SYM    the complete table until after functions
			 //SYM    / classdefs are parsed.
			 //SYM friends are processed in norm.c
			 //SYM    to handle 'friend x;' etc
				if ( yypvt[-0].pn->n_oper == 0
				&&  !in_typedef && !in_friend ) {
				    //SYM do not hide ctor name...
				    if ( ccl==0 || parsing_class_members==0
				    ||   strcmp(ccl->string,yypvt[-0].pn->string)) {
					Pname n = new name; *n = *yypvt[-0].pn;
					insert_name(n,Ctbl);
				    }
				}
			} break;
case 192:
# line 2001 "gram.y"
{	yyval.p = Ncopy(yypvt[-0].pn);
				//yyval.pn->n_qualifier = yypvt[-2].pn;
				error("`.' used for qualification; please use `::'");
			} break;
case 193:
# line 2006 "gram.y"
{	yyval.p = yypvt[-0].p;
				//SYM if ( yypvt[-1].pn != sta_name ) {
    				//SYM	set_scope(yypvt[-1].pn); 
					if ( yypvt[-1].pn == sta_name 
    					&&   yyval.pn->n_oper==DTOR )
						error("bad syntax for destructor ::%n",yyval.pn);
    					yyval.pn->n_qualifier = yypvt[-1].pn;
				//SYM }
			} break;
case 194:
# line 2016 "gram.y"
{	yyval.p = Ncopy(yypvt[-0].pn);
				//yyval.pn->n_qualifier = yypvt[-3].pn;//SYM yypvt[-2].pn;
				error("`.' used for qualification; please use `::'");
				error("non-type qualifier%n",yypvt[-2].pn);
				//if ( yypvt[-3].pn != sta_name ) {
    				//SYM	set_scope(yypvt[-3].pn); 
    				//	yypvt[-2].pn->n_qualifier = yypvt[-3].pn;
				//}
			} break;
case 195:
# line 2026 "gram.y"
{	Ptyp(yypvt[-1].p) = yypvt[-0].pn->tp;
				yypvt[-0].pn->tp = yypvt[-1].pt;
				yyval.p = yypvt[-0].p;
			} break;
case 196:
# line 2031 "gram.y"
{	yyval.p = Ncopy(yypvt[-0].pn);
				//??? what about qualified tnames?
				yyval.pn->n_oper = TNAME;
				// cannot evaluate at this point: defer until data_dcl
				if ( !in_typedef ) yypvt[-0].pn->hide();//SYM
				else in_tag = yypvt[-0].pn;//SYM???
				yyval.pn->tp = yypvt[-1].pt;
			} break;
case 197:
# line 2040 "gram.y"
{	yyval.p = Ncopy(yypvt[-1].pn);
				//??? what about qualified tnames?
				yyval.pn->n_oper = TNAME;
				if ( !in_typedef ) yypvt[-1].pn->hide();//SYM
				else in_tag = yypvt[-1].pn;//SYM???
				yyval.pn->tp = yypvt[-0].pt;
			} break;
case 198:
# line 2048 "gram.y"
{	Vtype(yypvt[-0].p) = yypvt[-1].pn->tp;
				yypvt[-1].pn->tp = yypvt[-0].pt;
			} break;
case 199:
# line 2065 "gram.y"
{ 
				yyval.p = yypvt[-1].p; 
				in_arg_list = 0;
				hoist_al();//SYM end_al(yypvt[-2].pl,0);
				//RESTORE_STATE();
			} break;
case 200:
# line 2074 "gram.y"
{//SYM -- insert in table if not done elsewhere...
				if ( yypvt[-0].pn->n_oper != TNAME ) {
					Pname n = new name; *n = *yypvt[-0].pn;
					insert_name(n,Ctbl);
				}
				yyval.p = yypvt[-0].pn;
			} break;
case 201:
# line 2082 "gram.y"
{	yyval.p = Ncopy(yypvt[-0].pn);
				yyval.pn->n_oper = TNAME;
				yypvt[-0].pn->hide();
				yyval.pn->tp = yypvt[-1].pt;
			} break;
case 202:
# line 2088 "gram.y"
{	
				yyval.p = new name; 
				NOT_EXPECT_ID();
			} break;
case 203:
# line 2093 "gram.y"
{	Ptyp(yypvt[-1].p) = yypvt[-0].pn->tp;
				yypvt[-0].pn->tp = (Ptype)yypvt[-1].p;
				yyval.p = yypvt[-0].p;
			} break;
case 204:
# line 2098 "gram.y"
{	Vtype(yypvt[-0].p) = yypvt[-1].pn->tp;
				yypvt[-1].pn->tp = (Ptype)yypvt[-0].p;
			} break;
case 205:
# line 2102 "gram.y"
{	Freturns(yypvt[-0].p) = yypvt[-1].pn->tp;
				yypvt[-1].pn->tp = (Ptype)yypvt[-0].p;
			} break;
case 206:
# line 2118 "gram.y"
{ 
// error('d', "arg_lp arg_decl rp in_arg_list: %d", in_arg_list );
				yyval.p = yypvt[-1].p; 
				in_arg_list = 0;
				hoist_al();//SYM end_al(yypvt[-2].pl,0);
				//RESTORE_STATE();
			} break;
case 207:
# line 2128 "gram.y"
{	yyval.p = new name; } break;
case 208:
# line 2130 "gram.y"
{	Ptyp(yypvt[-1].p) = yypvt[-0].pn->tp;
				yypvt[-0].pn->tp = (Ptype)yypvt[-1].p;
				yyval.p = yypvt[-0].p;
                                NOT_EXPECT_ID();
			} break;
case 209:
# line 2136 "gram.y"
{	Vtype(yypvt[-0].p) = yypvt[-1].pn->tp;
				yypvt[-1].pn->tp = (Ptype)yypvt[-0].p;
			} break;
case 210:
# line 2141 "gram.y"
{ yyval.p = new name; } break;
case 211:
# line 2143 "gram.y"
{	Ptyp(yypvt[-1].p) = yypvt[-0].pn->tp;
				yypvt[-0].pn->tp = (Ptype)yypvt[-1].p;
				yyval.p = yypvt[-0].p;
				NOT_EXPECT_ID();
			} break;
case 212:
# line 2149 "gram.y"
{	Vtype(yypvt[-0].p) = yypvt[-1].pn->tp;
				yypvt[-1].pn->tp = (Ptype)yypvt[-0].p;
			} break;
case 213:
# line 2153 "gram.y"
{	Freturns(yypvt[-0].p) = yypvt[-2].pn->tp;
				yypvt[-2].pn->tp = yypvt[-0].pt;
				yyval.p = yypvt[-2].p;
			} break;
case 214:
# line 2158 "gram.y"
{	Vtype(yypvt[-0].p) = yypvt[-2].pn->tp;
				yypvt[-2].pn->tp = yypvt[-0].pt;
				yyval.p = yypvt[-2].p;
			} break;
case 215:
# line 2165 "gram.y"
{	yyval.p = new name; } break;
case 216:
# line 2167 "gram.y"
{	Ptyp(yypvt[-1].p) = yypvt[-0].pn->tp;
				yypvt[-0].pn->tp = (Ptype)yypvt[-1].p;
				yyval.p = yypvt[-0].p;
			} break;
case 217:
# line 2177 "gram.y"
{
				yyval.p = 0; 
			} break;
case 218:
# line 2181 "gram.y"
{
				error( "ZizedTD must be atG, not local scope" );
				error('i', "cannot recover from previous error" );
			} break;
case 219:
# line 2186 "gram.y"
{	
				if (yypvt[-0].p)
					if (yypvt[-1].p)
						yypvt[-1].sl->add(yypvt[-0].ps);
					else {
						yyval.sl =  new slist(yypvt[-0].ps);
						stmt_seen = 1;
					}
			} break;
case 220:
# line 2197 "gram.y"
{
				yyval.p = yypvt[-0].p;
				if (yypvt[-0].p)	stmt_seen = 1;
			} break;
case 221:
# line 2204 "gram.y"
{
				yyval.p = 0;
				check_decl();
			} break;
case 222:
# line 2211 "gram.y"
{	yyval.p = yypvt[-1].p;
			/*	if ($<pe>$ == dummy) error("empty condition");*/
				stmt_seen = 1;
			} break;
case 223:
# line 2218 "gram.y"
{	PUSH_BLOCK_SCOPE();//SYM
				cd_vec[cdi] = cd;
				stmt_vec[cdi] = stmt_seen;
				++cdi;
				cd = 0;
				stmt_seen = 0;
				//SYM -- tn stuff removed
			} break;
case 224:
# line 2227 "gram.y"
{	Pname n = name_unlist(cd);
				Pstmt ss = stmt_unlist(yypvt[-1].sl);
				yyval.p = new block(yypvt[-3].l,n,ss,yypvt[-0].l);
				//SYM -- tn stuff removed
				cd = cd_vec[--cdi];
				stmt_seen = stmt_vec[cdi];
				if (cdi < 0) error('i',"block level(%d)",cdi);
				NOT_EXPECT_ID();
				yyval.ps->k_tbl = Ctbl;//SYM
                        	POP_SCOPE();//SYM
			} break;
case 225:
# line 2239 "gram.y"
{ yyval.p = new block(yypvt[-1].l,0,0,yypvt[-0].l); NOT_EXPECT_ID();
			  if ( Ctbl->k_id == ARG ) POP_SCOPE();//SYM
			} break;
case 226:
# line 2243 "gram.y"
{ yyval.p = new block(yypvt[-2].l,0,0,yypvt[-0].l); NOT_EXPECT_ID();
			  if ( Ctbl->k_id == ARG ) POP_SCOPE();//SYM
			} break;
case 227:
# line 2249 "gram.y"
{	yyval.p = new estmt(SM,curloc,yypvt[-0].pe,0);	} break;
case 228:
# line 2251 "gram.y"
{	yyval.p = new stmt(BREAK,yypvt[-0].l,0); } break;
case 229:
# line 2253 "gram.y"
{	yyval.p = new stmt(CONTINUE,yypvt[-0].l,0); } break;
case 230:
# line 2255 "gram.y"
{	yyval.p = new lstmt(GOTO,yypvt[-1].l,yypvt[-0].pn,0); } break;
case 231:
# line 2256 "gram.y"
{ stmt_seen=1; } break;
case 232:
# line 2257 "gram.y"
{	yyval.p = new estmt(DO,yypvt[-4].l,yypvt[-0].pe,yypvt[-2].ps); } break;
case 233:
# line 2259 "gram.y"
{	
				if (stmt_seen)
					yyval.p = new estmt(ASM,curloc,(Pexpr)yypvt[-1].s,0);
				else {
					Pname n = new name(make_name('A'));
					n->tp = new basetype(ASM,(Pname)yypvt[-1].s);
					if (cd)
						cd->add_list(n);
					else
						cd = new nlist(n);
					yyval.p = 0;
				}
			} break;
case 234:
# line 2274 "gram.y"
{
			if ( NEXTTOK() != SM ) {
				error("`;' missing afterS");
				la_backup(yychar,yylval);
				yychar = SM;
			}
		  } break;
case 237:
# line 2285 "gram.y"
{	yyval.p = new estmt(SM,curloc,dummy,0); } break;
case 238:
# line 2287 "gram.y"
{	yyval.p = new estmt(RETURN,yypvt[-2].l,yypvt[-1].pe,0); } break;
case 239:
# line 2289 "gram.y"
{
				error("local linkage specification");
				yyval.p = yypvt[-0].pn;
			} break;
case 240:
# line 2294 "gram.y"
{	Pname n = yypvt[-0].pn;
				if (n) {
//error('d',"adding local dcl of%n%t ll %d in_typedef%t",n,n->tp,n->lex_level,in_typedef);
					if (stmt_seen) {
						yyval.p = new block(n->where,n,0);
						yyval.ps->base = DCL;
						yyval.ps->k_tbl = Ctbl;//SYM
					}
					else {
						if (cd)
							cd->add_list(n);
						else
							cd = new nlist(n);
						yyval.p = 0;
					}
				} // if n
				else if (stmt_seen) {
					yyval.p = new block(curloc,0,0);
					yyval.ps->base = FDCL;
				}
			} break;
case 241:
# line 2316 "gram.y"
{
				Pname n = yypvt[-0].pn;
				if (!templp->in_progress)
					error(&n->where,"%n's definition is nested (did you forget a ``}''?)",n);
				if (cd)
					cd->add_list(n);
				else
					cd = new nlist(n);
				yyval.p = 0;
			} break;
case 243:
# line 2328 "gram.y"
{	yyval.p = new ifstmt(yypvt[-2].l,yypvt[-1].pe,yypvt[-0].ps,0); } break;
case 244:
# line 2330 "gram.y"
{	yyval.p = new ifstmt(yypvt[-4].l,yypvt[-3].pe,yypvt[-2].ps,yypvt[-0].ps); } break;
case 245:
# line 2332 "gram.y"
{	yyval.p = new estmt(WHILE,yypvt[-2].l,yypvt[-1].pe,yypvt[-0].ps); } break;
case 246:
# line 2333 "gram.y"
{ stmt_seen=1; } break;
case 247:
# line 2334 "gram.y"
{	yyval.p = new forstmt(yypvt[-8].l,yypvt[-5].ps,yypvt[-4].pe,yypvt[-2].pe,yypvt[-0].ps); } break;
case 248:
# line 2335 "gram.y"
{ scd[++scdp] = cd;} break;
case 249:
# line 2336 "gram.y"
{	
				--scdp;
				yyval.p = new estmt(SWITCH,yypvt[-3].l,yypvt[-1].pe,yypvt[-0].ps); 
			} break;
case 250:
# line 2340 "gram.y"
{ yyval.p = yypvt[-1].pn; stmt_seen=1; } break;
case 251:
# line 2341 "gram.y"
{	Pname n = yypvt[-1].pn;
				yyval.p = new lstmt(LABEL,n->where,n,yypvt[-0].ps);
			} break;
case 252:
# line 2344 "gram.y"
{ yyval.p = new name(yypvt[-1].pn->string); stmt_seen=1; } break;
case 253:
# line 2345 "gram.y"
{	Pname n = yypvt[-1].pn;
				yyval.p = new lstmt(LABEL,n->where,n,yypvt[-0].ps);
			} break;
case 254:
# line 2348 "gram.y"
{ stmt_seen=1; } break;
case 255:
# line 2349 "gram.y"
{	
				if (scdp>=0 && scd[scdp]!=cd && cd && decl_with_init(cd)) error("jump past initializer (did you forget a '{ }'?)");
				if (yypvt[-2].pe == dummy) error("empty case label");
				yyval.p = new estmt(CASE,yypvt[-4].l,yypvt[-2].pe,yypvt[-0].ps);
			} break;
case 256:
# line 2354 "gram.y"
{ stmt_seen=1; } break;
case 257:
# line 2355 "gram.y"
{	
				if (scdp>=0 && scd[scdp]!=cd && cd && yypvt[-1].pe && decl_with_init(cd)) error("jump past initializer (did you forget a '{ }'?)");
				yyval.p = new stmt(DEFAULT,yypvt[-3].l,yypvt[-0].ps); 
			} break;
case 258:
# line 2360 "gram.y"
{ yyval.p = new handler( yypvt[-1].ps, stmt_unlist(yypvt[-0].sl) ); } break;
case 259:
# line 2365 "gram.y"
{ yyval.sl = 0; } break;
case 260:
# line 2367 "gram.y"
{	
				if (yypvt[-0].ps)
					if (yypvt[-1].sl)
						yypvt[-1].sl->add(yypvt[-0].ps);
					else {
						yyval.sl =  new slist(yypvt[-0].ps);
						stmt_seen = 1;
					}
			} break;
case 261:
# line 2379 "gram.y"
{
			    if ( yypvt[-1].pn ) {
				yypvt[-1].pn->n_list = yypvt[-0].ps->d;
				yypvt[-0].ps->d = yypvt[-1].pn;
			    }
			    yyval.ps = yypvt[-0].ps;
			} break;
case 262:
# line 2390 "gram.y"
{	in_arg_list = 0;
				yyval.pn = Ndata(yypvt[-2].p,yypvt[-1].pn);
				if ( yyval.pn->string == 0 )
					yyval.pn = 0;
				else
					yyval.pn->base = CATCH;
			} break;
case 263:
# line 2398 "gram.y"
{ yyval.pn = 0; } break;
case 264:
# line 2405 "gram.y"
{	Pexpr e = expr_unlist(yypvt[-0].el);
				while (e && e->e1==dummy) {
					register Pexpr ee2 = e->e2;
					if (ee2) error("EX inEL");
					delete e;
					e = ee2;
				}
				yyval.p = e;
			} break;
case 265:
# line 2417 "gram.y"
{	yyval.el = new elist(new expr(ELIST,yypvt[-0].pe,0)); } break;
case 266:
# line 2419 "gram.y"
{	yypvt[-2].el->add(new expr(ELIST,yypvt[-0].pe,0)); } break;
case 268:
# line 2424 "gram.y"
{
  			  	if ( in_arg_list ) 
       			  		error( "syntax error: IrL not permitted in AL" );
				else if ( in_binit_list )
					error( "syntax error: IrL not permitted inMIr" );
  			  	else 
					init_seen = 1;
				Pexpr e;
				if (yypvt[-1].p)
					e = yypvt[-1].pe;
				else
					e = new expr(ELIST,dummy,0);
				yyval.p = new expr(ILIST,e,0);
			} break;
case 269:
# line 2441 "gram.y"
{	bbinop:	yyval.p = new expr(yypvt[-1].t,yypvt[-2].pe,yypvt[-0].pe); } break;
case 270:
# line 2442 "gram.y"
{	goto bbinop; } break;
case 271:
# line 2443 "gram.y"
{	goto bbinop; } break;
case 272:
# line 2444 "gram.y"
{	goto bbinop; } break;
case 273:
# line 2445 "gram.y"
{	goto bbinop; } break;
case 274:
# line 2446 "gram.y"
{	goto bbinop; } break;
case 275:
# line 2447 "gram.y"
{	goto bbinop; } break;
case 276:
# line 2448 "gram.y"
{ 	goto bbinop; } break;
case 277:
# line 2449 "gram.y"
{	goto bbinop; } break;
case 278:
# line 2450 "gram.y"
{	goto bbinop; } break;
case 279:
# line 2451 "gram.y"
{	goto bbinop; } break;
case 280:
# line 2452 "gram.y"
{	goto bbinop; } break;
case 281:
# line 2453 "gram.y"
{	goto bbinop; } break;
case 282:
# line 2454 "gram.y"
{	goto bbinop; } break;
case 283:
# line 2455 "gram.y"
{	goto bbinop; } break;
case 284:
# line 2456 "gram.y"
{	goto bbinop; } break;
case 285:
# line 2457 "gram.y"
{	goto bbinop; } break;
case 286:
# line 2459 "gram.y"
{	yyval.p = new qexpr(yypvt[-4].pe,yypvt[-2].pe,yypvt[-0].pe); } break;
case 287:
# line 2461 "gram.y"
{	yyval.p = new expr(yypvt[-1].t,yypvt[-2].pe,yypvt[-0].pe); } break;
case 288:
# line 2463 "gram.y"
{ yyval.p = new expr(DELETE,yypvt[-0].pe,0); } break;
case 289:
# line 2465 "gram.y"
{
				if(yypvt[-2].pe != dummy) {
					if ( warning_opt || strict_opt )
						error(strict_opt?0:'w',"v in `delete[v]' is redundant; use `delete[] instead (anachronism)");
				}
				yyval.p = new expr(DELETE,yypvt[-0].pe,yypvt[-2].pe);
			} break;
case 290:
# line 2473 "gram.y"
{	yyval.p = new expr(GDELETE,yypvt[-0].pe,0); } break;
case 291:
# line 2475 "gram.y"
{
				if(yypvt[-2].pe != dummy) { 
					if ( warning_opt || strict_opt )
						error(strict_opt?0:'w',"v in `::delete[v]' is redundant; use `::delete[] instead (anachronism)");
				}
				yyval.p = new expr(DELETE,yypvt[-0].pe,yypvt[-2].pe);
			} break;
case 293:
# line 2484 "gram.y"
{ yyval.p = dummy; } break;
case 294:
# line 2488 "gram.y"
{	binop:	yyval.p = new expr(yypvt[-1].t,yypvt[-2].pe,yypvt[-0].pe); } break;
case 295:
# line 2489 "gram.y"
{	goto binop; } break;
case 296:
# line 2490 "gram.y"
{	goto binop; } break;
case 297:
# line 2491 "gram.y"
{	goto binop; } break;
case 298:
# line 2492 "gram.y"
{	goto binop; } break;
case 299:
# line 2493 "gram.y"
{	goto binop; } break;
case 300:
# line 2494 "gram.y"
{	goto binop; } break;
case 301:
# line 2495 "gram.y"
{ 	goto binop; } break;
case 302:
# line 2496 "gram.y"
{	goto binop; } break;
case 303:
# line 2497 "gram.y"
{	goto binop; } break;
case 304:
# line 2498 "gram.y"
{	goto binop; } break;
case 305:
# line 2499 "gram.y"
{	goto binop; } break;
case 306:
# line 2500 "gram.y"
{	goto binop; } break;
case 307:
# line 2501 "gram.y"
{	goto binop; } break;
case 308:
# line 2502 "gram.y"
{	goto binop; } break;
case 309:
# line 2503 "gram.y"
{	goto binop; } break;
case 310:
# line 2504 "gram.y"
{	goto binop; } break;
case 311:
# line 2506 "gram.y"
{	yyval.p = new qexpr(yypvt[-4].pe,yypvt[-2].pe,yypvt[-0].pe); } break;
case 312:
# line 2508 "gram.y"
{	yyval.p = new expr(yypvt[-1].t,yypvt[-2].pe,yypvt[-0].pe); } break;
case 313:
# line 2510 "gram.y"
{	yyval.p = new expr(DELETE,yypvt[-0].pe,0); } break;
case 314:
# line 2512 "gram.y"
{
				if(yypvt[-2].pe != dummy) {
					if ( warning_opt || strict_opt )
						error(strict_opt?0:'w',"v in `delete[v]' is redundant; use `delete[] instead (anachronism)");
				}
				yyval.p = new expr(DELETE,yypvt[-0].pe,yypvt[-2].pe);
			} break;
case 315:
# line 2520 "gram.y"
{	yyval.p = new expr(GDELETE,yypvt[-0].pe,0); } break;
case 316:
# line 2522 "gram.y"
{
				if(yypvt[-2].pe != dummy) {
					if ( warning_opt || strict_opt )
						error(strict_opt?0:'w',"v in `::delete[v]' is redundant; use `::delete[] instead (anachronism)");
				}
				yyval.p = new expr(DELETE,yypvt[-0].pe,yypvt[-2].pe);
			} break;
case 317:
# line 2529 "gram.y"
{ 
			init_seen = 0; 
			} break;
case 318:
# line 2533 "gram.y"
{ yyval.p = dummy; } break;
case 319:
# line 2535 "gram.y"
{	yyval.p = dummy; } break;
case 320:
# line 2538 "gram.y"
{ goto new1; } break;
case 321:
# line 2540 "gram.y"
{	new1:
				Ptype t = yypvt[-0].pn->tp;
				yyval.p = new texpr(NEW,t,0);
				--in_new;
			} break;
case 322:
# line 2545 "gram.y"
{ goto new3; } break;
case 323:
# line 2547 "gram.y"
{	new3:
				Ptype t = yypvt[-0].pn->tp;
 				yyval.p = new texpr(GNEW,t,0);
				--in_new;
 			} break;
case 324:
# line 2553 "gram.y"
{	yyval.p = new expr(yypvt[-0].t,yypvt[-1].pe,0); } break;
case 325:
# line 2555 "gram.y"
{
				yyval.p = new texpr(CAST,yypvt[-1].pn->tp,yypvt[-0].pe);
			} break;
case 326:
# line 2559 "gram.y"
{	yyval.p = new expr(DEREF,yypvt[-0].pe,0); } break;
case 327:
# line 2561 "gram.y"
{	yyval.p = new expr(ADDROF,0,yypvt[-0].pe); } break;
case 328:
# line 2563 "gram.y"
{	yyval.p = new expr(UMINUS,0,yypvt[-0].pe); } break;
case 329:
# line 2565 "gram.y"
{	yyval.p = new expr(UPLUS,0,yypvt[-0].pe); } break;
case 330:
# line 2567 "gram.y"
{	yyval.p = new expr(NOT,0,yypvt[-0].pe); } break;
case 331:
# line 2569 "gram.y"
{	yyval.p = new expr(COMPL,0,yypvt[-0].pe); } break;
case 332:
# line 2571 "gram.y"
{	yyval.p = new expr(yypvt[-1].t,0,yypvt[-0].pe); } break;
case 333:
# line 2573 "gram.y"
{	
				yyval.p = new texpr(SIZEOF,0,yypvt[-0].pe); 
				--in_sizeof;
			} break;
case 334:
# line 2578 "gram.y"
{	
				yyval.p = new texpr(SIZEOF,yypvt[-0].pn->tp,0); 
				--in_sizeof;
			} break;
case 335:
# line 2583 "gram.y"
{	yyval.p = new expr(DEREF,yypvt[-3].pe,yypvt[-1].pe); } break;
case 336:
# line 2585 "gram.y"
{	yyval.p = new ref(REF,yypvt[-2].pe,yypvt[-0].pn); } break;
case 337:
# line 2587 "gram.y"
{
				yypvt[-0].pn->n_qualifier = yypvt[-1].pn;
				yyval.p = new ref(REF,yypvt[-3].pe,yypvt[-0].pn);
			} break;
case 338:
# line 2592 "gram.y"
{	yypvt[-0].pn = new name(yypvt[-0].pn->string);
				yypvt[-0].pn->n_qualifier = yypvt[-1].pn;
				yyval.p = new ref(REF,yypvt[-3].pe,yypvt[-0].pn);
			} break;
case 339:
# line 2597 "gram.y"
{	yyval.p = new ref(REF,yypvt[-2].pe,yypvt[-0].pn); } break;
case 340:
# line 2599 "gram.y"
{ // kluge to handle parameterized qualifiers, since
			  //    they are not included in MEMQ
				yypvt[-0].pn->n_qualifier = yypvt[-1].pn;
				yyval.p = new ref(REF,yypvt[-3].pe,yypvt[-0].pn);
				if ( yypvt[-1].pn && yypvt[-1].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();
			} break;
case 341:
# line 2607 "gram.y"
{ // kluge to handle parameterized qualifiers, since
			  //    they are not included in MEMQ
				yypvt[-0].pn = new name(yypvt[-0].pn->string);
				yypvt[-0].pn->n_qualifier = yypvt[-1].pn;
				yyval.p = new ref(REF,yypvt[-3].pe,yypvt[-0].pn);
				if ( yypvt[-1].pn && yypvt[-1].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();
			} break;
case 342:
# line 2616 "gram.y"
{	yyval.p = new ref(DOT,yypvt[-2].pe,yypvt[-0].pn); } break;
case 343:
# line 2618 "gram.y"
{
				yypvt[-0].pn->n_qualifier = yypvt[-1].pn;
				yyval.p = new ref(DOT,yypvt[-3].pe,yypvt[-0].pn);
			} break;
case 344:
# line 2623 "gram.y"
{	yypvt[-0].pn = new name(yypvt[-0].pn->string);
				yypvt[-0].pn->n_qualifier = yypvt[-1].pn;
				yyval.p = new ref(DOT,yypvt[-3].pe,yypvt[-0].pn);
			} break;
case 345:
# line 2628 "gram.y"
{	yyval.p = new ref(DOT,yypvt[-2].pe,yypvt[-0].pn); } break;
case 346:
# line 2630 "gram.y"
{ // kluge to handle parameterized qualifiers, since
			  //    they are not included in MEMQ
				yypvt[-0].pn->n_qualifier = yypvt[-1].pn;
				yyval.p = new ref(DOT,yypvt[-3].pe,yypvt[-0].pn);
				if ( yypvt[-1].pn && yypvt[-1].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();
			} break;
case 347:
# line 2638 "gram.y"
{ // kluge to handle parameterized qualifiers, since
			  //    they are not included in MEMQ
				yypvt[-0].pn = new name(yypvt[-0].pn->string);
				yypvt[-0].pn->n_qualifier = yypvt[-1].pn;
				yyval.p = new ref(DOT,yypvt[-3].pe,yypvt[-0].pn);
				if ( yypvt[-1].pn && yypvt[-1].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();
			} break;
case 349:
# line 2648 "gram.y"
{ // set scope to parse 'C::operator N' where N is in C
			  // still does not handle 'p->operator N'
			  //     (requires either fancier structures or 
			  //     on-the-fly type checking)
				yyval.p = Ncopy(yypvt[-0].pn);
				yyval.pn->n_qualifier = yypvt[-1].pn;
				if ( yypvt[-1].pn && yypvt[-1].pn->n_template_arg != template_type_formal )
					UNSET_SCOPE();
			} break;
case 350:
# line 2658 "gram.y"
{
				yyval.p = dummy_dtor();
				yyval.pn->n_qualifier = yypvt[-2].pn;
				yyval.pn->n_dtag = yypvt[-0].pn;
			} break;
case 351:
# line 2664 "gram.y"
{	
				yyval.p = dummy_dtor( yypvt[-0].t, yypvt[-0].t );
				yyval.pn->n_qualifier = yypvt[-2].pn;
			} break;
case 352:
# line 2669 "gram.y"
{
			if ( init_seen )
     				error( "syntax error:IrL illegal within ()");
			} break;
case 353:
# line 2675 "gram.y"
{
				if ( yypvt[-1].p == dummy )
					error("syntax error: nullE");
				yyval.p = yypvt[-1].p;
			} break;
case 354:
# line 2681 "gram.y"
{	yyval.p = zero; } break;
case 355:
# line 2683 "gram.y"
{	yyval.p = new expr(ICON,0,0);
				yyval.pe->string = copy_if_need_be(yypvt[-0].s);
			} break;
case 356:
# line 2687 "gram.y"
{	yyval.p = new expr(FCON,0,0);
				yyval.pe->string = copy_if_need_be(yypvt[-0].s);
			} break;
case 357:
# line 2691 "gram.y"
{	yyval.p = new expr(STRING,0,0);
				yyval.pe->string = copy_if_need_be(yypvt[-0].s);
			} break;
case 358:
# line 2695 "gram.y"
{	yyval.p = new expr(CCON,0,0);
				yyval.pe->string = copy_if_need_be(yypvt[-0].s);
			} break;
case 359:
# line 2699 "gram.y"
{	yyval.p = new expr(THIS,0,0); } break;
case 360:
# line 2703 "gram.y"
{	
				yyval.p = dummy_dtor();
				yyval.pn->n_dtag = yypvt[-0].pn; // checked later
			} break;
case 361:
# line 2708 "gram.y"
{	
				yyval.p = dummy_dtor();
				yyval.pn->n_qualifier = yypvt[-2].pn; // checked later
				yyval.pn->n_dtag = yypvt[-0].pn; // checked later
			} break;
case 362:
# line 2714 "gram.y"
{ yyval.p = dummy_dtor(yypvt[-3].t,yypvt[-0].t); } break;
case 363:
# line 2716 "gram.y"
{ yyval.p = dummy_dtor(yypvt[-0].t,yypvt[-0].t); } break;
case 364:
# line 2718 "gram.y"
{	
				yyval.p = dummy_dtor( yypvt[-3].t, yypvt[-3].t );
				yyval.pn->n_dtag = yypvt[-0].pn;
			} break;
case 365:
# line 2723 "gram.y"
{
				yyval.p = dummy_dtor( yypvt[-0].t, yypvt[-0].t );
				yyval.pn->n_qualifier = yypvt[-2].pn;
			} break;
case 366:
# line 2728 "gram.y"
{ // kluge to parse parameterized qualifiers after ./->
				yyval.p = dummy_dtor();
				yyval.pn->n_qualifier = yypvt[-2].pn;
				yyval.pn->n_dtag = yypvt[-0].pn;
			} break;
case 367:
# line 2734 "gram.y"
{ // kluge to parse parameterized qualifiers after ./->
				yyval.p = dummy_dtor( yypvt[-0].t, yypvt[-0].t );
				yyval.pn->n_qualifier = yypvt[-2].pn;
			} break;
case 368:
# line 2741 "gram.y"
{ 	yyval.p = new texpr(VALUE,tok_to_type(yypvt[-3].t),yypvt[-1].pe); } break;
case 369:
# line 2746 "gram.y"
{	
				yyval.p = new texpr(VALUE,yypvt[-3].pn->tp,yypvt[-1].pe); 
				if (yypvt[-3].pn->is_template_arg() && yypvt[-3].pn->tp->base == ANY) {
					yyval.pe->tp2 = new basetype(TYPE,yypvt[-3].pn);
				}
			} break;
case 370:
# line 2752 "gram.y"
{ goto new2; } break;
case 371:
# line 2754 "gram.y"
{	new2:
				Ptype t = yypvt[-0].pn->tp;
				yyval.p=new texpr(NEW,t,0);
				yyval.pe->e2 = yypvt[-2].pe;
				--in_new;
			} break;
case 372:
# line 2760 "gram.y"
{ goto new4; } break;
case 373:
# line 2762 "gram.y"
{	new4:
				Ptype t = yypvt[-0].pn->tp;
				yyval.p = new texpr(GNEW,t,0);
				yyval.pe->e2 = yypvt[-2].pe;
				--in_new;
			} break;
case 374:
# line 2769 "gram.y"
{	
				Pexpr ee = yypvt[-1].pe;
				Pexpr e = yypvt[-3].pe;
				if (e->base==NEW || e->base==GNEW)
					e->e1 = ee;
				else
					yyval.p = new call(e,ee);
			} break;
case 375:
# line 2781 "gram.y"
{
			yyval.pn = parametrized_typename(yypvt[-3].pn,(expr_unlist(yypvt[-1].el))); 
	 	 } break;
case 376:
# line 2786 "gram.y"
{ yyval.pn = yypvt[-0].pn; } break;
case 377:
# line 2787 "gram.y"
{ yyval.pn = sta_name; } break;
case 378:
# line 2788 "gram.y"
{ yyval.pn = yypvt[-1].pn; } break;
case 379:
# line 2793 "gram.y"
{
				if ( in_arg_list && !in_binit_list ) {
				    Pktab tb = Ctbl;
				    for (; tb && tb->k_id==ARG; tb=tb->k_next) {
					if ( tb->look(yypvt[-0].pn->string,0) ) {
						error("illegalR toA%n in defaultA",yypvt[-0].pn);
						yypvt[-0].pe = dummy;
						break;
					}
				    }
				}
				yyval.p = yypvt[-0].pn;
			} break;
case 380:
# line 2807 "gram.y"
{	yyval.p = new name(oper_name(yypvt[-0].t));
				yyval.pn->n_oper = yypvt[-0].t;
			} break;
case 381:
# line 2811 "gram.y"
{	yyval.p = yypvt[-0].p;
				sig_name(yyval.pn);
			} break;
case 382:
# line 2820 "gram.y"
{
				yyval.p = Ncast(yypvt[-2].p,yypvt[-1].pn);
			} break;
case 383:
# line 2825 "gram.y"
{ check_cast(); } break;
case 384:
# line 2829 "gram.y"
{
				TOK t = yypvt[-0].t;

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

			} break;
case 385:
# line 2848 "gram.y"
{ yyval.p = new basetype(TYPE,yypvt[-0].pn); } break;
case 386:
# line 2850 "gram.y"
{ 
				if ( DECL_TYPE != -1 ) {
					switch (yypvt[-1].pb->base) { 
					case COBJ: case EOBJ:
						{
						Pbase bt;
						bt = new basetype(0,0);
						*bt = *yypvt[-1].pb;
						DEL(yypvt[-1].pb);
						yypvt[-1].pb = bt;
						}
					}
					yyval.p = yypvt[-1].pb->type_adj(yypvt[-0].t); 
				}
				DECL_TYPE = 0;
			} break;
case 387:
# line 2867 "gram.y"
{ 
				if ( DECL_TYPE != -1 ) 
			 		yyval.p = yypvt[-1].pb->name_adj(yypvt[-0].pn);
				DECL_TYPE = 0;
			} break;
case 388:
# line 2874 "gram.y"
{ yyval.p = Ncast(yypvt[-1].p,yypvt[-0].pn); } break;
case 389:
# line 2877 "gram.y"
{ yyval.p = Ncast(yypvt[-1].p,yypvt[-0].pn); } break;
case 390:
# line 2880 "gram.y"
{	
                         //      ENTER_NAME(yypvt[-0].pn);
				yyval.p = Ndata(yypvt[-1].p,yypvt[-0].pn); 
			} break;
case 391:
# line 2885 "gram.y"
{
                        //      ENTER_NAME(yypvt[-1].pn);
                        } break;
case 392:
# line 2889 "gram.y"
{       
				yyval.p = Ndata(yypvt[-4].p,yypvt[-3].pn);
                                yyval.pn->n_initializer = yypvt[-0].pe;
                        } break;
case 393:
# line 2896 "gram.y"
{	PUSH_ARG_SCOPE();//SYM
				//SAVE_STATE();
				in_arg_list=1; 
				check_decl(); 
				yyval.pl = 0;
				//SYM -- tn stuff removed
			} break;
case 394:
# line 2906 "gram.y"
{
			yyval.p = new fct(0,name_unlist(yypvt[-3].nl),yypvt[-2].t); 
			if ( NEXTTOK() != COLON ) in_arg_list=0;
			//in_arg_list=0;
			Pfct(yyval.pt)->f_const = (yypvt[-0].i & 1);
			//SYM -- removed kluge
                        POP_SCOPE();//SYM
			//RESTORE_STATE();
		    } break;
case 395:
# line 2918 "gram.y"
{
				if (yypvt[-0].p)
					if (yypvt[-2].p)
						yypvt[-2].nl->add(yypvt[-0].pn);
					else {
						error("AD syntax");
						yyval.nl = new nlist(yypvt[-0].pn); 
					}
				else
					error("AD syntax");
			} break;
case 396:
# line 2930 "gram.y"
{
				if (yypvt[-0].p) yyval.nl = new nlist(yypvt[-0].pn); 
			} break;
case 398:
# line 2936 "gram.y"
{	yyval.p = 0; } break;
case 399:
# line 2940 "gram.y"
{	yyval.t = 1; } break;
case 400:
# line 2942 "gram.y"
{	yyval.t = ELLIPSIS; } break;
case 401:
# line 2944 "gram.y"
{	yyval.t = ELLIPSIS; } break;
case 402:
# line 2948 "gram.y"
{
			yyval.p = new ptr(PTR,0); 
			EXPECT_ID();
			} break;
case 403:
# line 2953 "gram.y"
{
			yyval.p = new ptr(RPTR,0); 
			EXPECT_ID();
			} break;
case 404:
# line 2958 "gram.y"
{	yyval.p = doptr(PTR,yypvt[-0].t); } break;
case 405:
# line 2960 "gram.y"
{	
				switch ( yypvt[-0].t ) {
				case CONST:
                                     yypvt[-1].pp->b_const = 1; break;
				case VOLATILE:
				     error('w',"\"volatile\" not implemented (ignored)");
				     break;
				default:
				    error( "syntax error: *%k", yypvt[-0].t );
				}
				yyval.p = yypvt[-1].pp; 
			} break;
case 406:
# line 2973 "gram.y"
{	yyval.p = doptr(RPTR,yypvt[-0].t); } break;
case 407:
# line 2975 "gram.y"
{	
				memptr_pn = yypvt[-1].pn;
				memptr_tok = 0;
				goto memptr1;
			} break;
case 408:
# line 2981 "gram.y"
{
			memptr_pn = yypvt[-0].pn;
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
			} break;
case 409:
# line 3004 "gram.y"
{	
				memptr_pn = yypvt[-2].pn;
				memptr_tok = yypvt[-0].t;
				goto memptr1;
			} break;
case 410:
# line 3010 "gram.y"
{	
				memptr_pn = yypvt[-1].pn;
				memptr_tok = yypvt[-0].t;
				goto memptr1;
			} break;
case 411:
# line 3017 "gram.y"
{ yyval.p = new vec(0,yypvt[-1].pe!=dummy?yypvt[-1].pe:0 ); } break;
case 412:
# line 3018 "gram.y"
{ yyval.p = new vec(0,0); } break;
	}
	goto yystack;  /* stack new state and value */
}
