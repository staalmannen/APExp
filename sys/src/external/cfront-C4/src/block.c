# 1 ""

/* <<AT&T C++ Language System <3.0.3> 05/05/94>> */

#pragma lib "ape/libap.a"

#pragma lib "c++/libC.a"

# 1 ""
void *__vec_new (void *, int , int , void *);

# 1 ""
void __vec_delete (void *, int , int , void *, int , int );
typedef int (*__vptp)(void);
struct __mptr {short d; short i; __vptp f; };

# 1 ""
extern struct __mptr* __ptbl_vec___[];

# 1 ""

# 20 "/home/claude/incl-linux32/generic.h"
typedef int (*GPT )(int , char *);

# 19 "/home/claude/cfront-3/src/typedef.h"
typedef unsigned char TOK ;
typedef unsigned char bit ;
struct node;
typedef struct node *PP ;
typedef int (*PFI )(void );
typedef void (*PFV )(void );
typedef struct node *Pnode ;
struct key;
typedef struct key *Pkey ;
struct name;
typedef struct name *Pname ;
struct basetype;
typedef struct basetype *Pbase ;
struct basecl;
typedef struct basecl *Pbcl ;
struct type;
typedef struct type *Ptype ;
struct fct;
typedef struct fct *Pfct ;
struct field;
typedef struct field *Pfield ;
struct expr;
typedef struct expr *Pexpr ;
struct qexpr;
typedef struct qexpr *Pqexpr ;
struct texpr;
typedef struct texpr *Ptexpr ;
struct classdef;
typedef struct classdef *Pclass ;
struct enumdef;
typedef struct enumdef *Penum ;
struct stmt;
typedef struct stmt *Pstmt ;
struct estmt;
typedef struct estmt *Pestmt ;
struct tstmt;
typedef struct tstmt *Ptstmt ;
struct vec;
typedef struct vec *Pvec ;
struct ptr;
typedef struct ptr *Pptr ;
struct block;
typedef struct block *Pblock ;
struct table;
typedef struct table *Ptable ;
struct ktable;
typedef struct ktable *Pktab ;
struct loc;
typedef struct loc Loc ;
struct call;
typedef struct call *Pcall ;
struct gen;
typedef struct gen *Pgen ;
struct ref;
typedef struct ref *Pref ;
struct name_list;
typedef struct name_list *Plist ;
struct iline;
typedef struct iline *Pin ;
struct ia;
typedef struct ia *Pia ;
struct nlist;
typedef struct nlist *Pnlist ;
struct slist;
typedef struct slist *Pslist ;
struct elist;
typedef struct elist *Pelist ;
struct virt;
typedef struct virt *Pvirt ;
typedef char *Pchar ;
typedef const char *CPchar ;

# 18 "/home/claude/incl-linux32/stddef.h"
typedef long ssize_t ;
typedef unsigned long size_t ;

# 14 "/home/claude/incl-linux32/stdio.h"
typedef char *va_list ;

# 125 "/home/claude/incl-linux32/stdio.h"
extern char *sys_errlist [];
extern int sys_nerr ;
extern unsigned char *_bufendtab [];

# 61 "/home/claude/cfront-3/src/token.h"
extern const char *keys [256];

# 26 "/home/claude/cfront-3/src/cfront.h"
extern const char *prog_name ;
extern int inline_restr ;

# 40 "/home/claude/cfront-3/src/cfront.h"
extern Pname dummy_fct ;

# 50 "/home/claude/cfront-3/src/cfront.h"
struct loc {	/* sizeof loc == 4 */
short file__3loc ;
short line__3loc ;
};

# 59 "/home/claude/cfront-3/src/cfront.h"
extern struct loc curloc ;
extern int curr_file ;

# 62 "/home/claude/cfront-3/src/cfront.h"
extern const char *src_file_name ;
extern struct loc noloc ;
extern bit binary_val ;
extern bit stmtno ;
extern Ptable tmp_tbl ;
extern Ptable bound_expr_tbl ;
struct ea;
union __Q2_2ea4__C1;

# 70 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_2ea4__C1 {	/* sizeof __Q2_2ea4__C1 == 8 */
const void *p ;
size_t i ;
};

# 69 "/home/claude/cfront-3/src/cfront.h"
struct ea {	/* sizeof ea == 8 */

# 73 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_2ea4__C1 __O1__2ea ;
};

# 1 ""
extern void *__nw__FUl (unsigned long );

# 80 "/home/claude/cfront-3/src/cfront.h"
extern struct ea *ea0 ;

# 88 "/home/claude/cfront-3/src/cfront.h"
extern char emode ;

# 90 "/home/claude/cfront-3/src/cfront.h"
extern int error_count ;
extern int vtbl_opt ;
extern int debug_opt ;
extern int warning_opt ;
extern int ansi_opt ;
extern int pt_opt ;
extern int perf_opt ;
extern int dtpt_opt ;
extern int se_opt ;
extern int strict_opt ;
extern void *out_file ;
extern void *in_file ;
extern void *pt_file ;
extern void *dtpt_file ;
extern char scan_started ;

# 106 "/home/claude/cfront-3/src/cfront.h"
extern int bl_level ;

# 109 "/home/claude/cfront-3/src/cfront.h"
extern Pktab Gtbl ;
extern Pktab Ctbl ;

# 118 "/home/claude/cfront-3/src/cfront.h"
extern Ptable gtbl ;
extern Ptable ptbl ;

# 123 "/home/claude/cfront-3/src/cfront.h"
extern Pname def_name ;
extern Pname pdef_name ;
extern Pclass ccl ;
extern Pbase defa_type ;
extern Pbase moe_type ;
extern Pbase mptr_type ;

# 131 "/home/claude/cfront-3/src/cfront.h"
extern Pstmt Cstmt ;
extern Pname Cdcl ;

# 134 "/home/claude/cfront-3/src/cfront.h"
extern int largest_int ;

# 137 "/home/claude/cfront-3/src/cfront.h"
extern Pbase any_type ;
extern Pbase int_type ;
extern Pbase char_type ;
extern Pbase short_type ;
extern Pbase long_type ;
extern Pbase llong_type ;
extern Pbase uint_type ;
extern Pbase float_type ;
extern Pbase double_type ;
extern Pbase ldouble_type ;
extern Pbase void_type ;

# 150 "/home/claude/cfront-3/src/cfront.h"
extern Pbase uchar_type ;
extern Pbase ushort_type ;
extern Pbase ulong_type ;
extern Pbase ullong_type ;
extern Ptype Pchar_type ;
extern Ptype Pint_type ;
extern Ptype Pvptr_type ;
extern Ptype Pfctvec_type ;
extern Ptype Pvoid_type ;
extern Pbase zero_type ;
extern Ptype size_t_type ;

# 162 "/home/claude/cfront-3/src/cfront.h"
extern int byte_offset ;
extern int bit_offset ;
extern int max_align ;
extern int const_save ;
extern bit const_problem ;

# 169 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr dummy ;
extern Pexpr zero ;
extern Pexpr one ;
extern Pname sta_name ;

# 178 "/home/claude/cfront-3/src/cfront.h"
struct node {	/* sizeof node == 3 */
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;
};

# 217 "/home/claude/cfront-3/src/cfront.h"
void *__nw__5tableSFUl (size_t );
void __dl__5tableSFPvUl (void *, size_t );

# 198 "/home/claude/cfront-3/src/cfront.h"
struct table {	/* sizeof table == 56 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 200 "/home/claude/cfront-3/src/cfront.h"
bit init_stat__5table ;

# 204 "/home/claude/cfront-3/src/cfront.h"
TOK t_realbase__5table ;
short size__5table ;
short hashsize__5table ;
short free_slot__5table ;
Pname *entries__5table ;
short *hashtbl__5table ;
Pstmt real_block__5table ;

# 213 "/home/claude/cfront-3/src/cfront.h"
Ptable next__5table ;
Pname t_name__5table ;
};
extern Ptable table_free__5table ;
union __Q2_6ktable4__C1;

# 244 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_6ktable4__C1 {	/* sizeof __Q2_6ktable4__C1 == 8 */
Ptable k_t ;
Pname k_n ;
};

# 257 "/home/claude/cfront-3/src/cfront.h"
void *__nw__6ktableSFUl (size_t );
void __dl__6ktableSFPvUl (void *, size_t );

# 271 "/home/claude/cfront-3/src/cfront.h"
extern bit Nold ;
extern bit vec_const ;

# 272 "/home/claude/cfront-3/src/cfront.h"
extern bit fct_const ;

# 278 "/home/claude/cfront-3/src/cfront.h"
extern Plist local_class ;

# 282 "/home/claude/cfront-3/src/cfront.h"
extern Pname curr_fct ;

# 291 "/home/claude/cfront-3/src/cfront.h"
extern bit new_type ;
extern Pname cl_obj_vec ;
extern Pname eobj ;
enum Templ_type { VANILLA = 0, FCT_TEMPLATE = 1, CL_TEMPLATE = 2, BOUND_TEMPLATE = 3, INSTANTIATED = 4, UNINSTANTIATED = 5} ;

# 187 "/home/claude/cfront-3/src/cfront.h"

# 309 "/home/claude/cfront-3/src/cfront.h"
struct type {	/* sizeof type == 64 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;
};

# 351 "/home/claude/cfront-3/src/cfront.h"
TOK kind__4typeFUcN21 (struct type *__0this , TOK , TOK , bit );

# 323 "/home/claude/cfront-3/src/cfront.h"

# 365 "/home/claude/cfront-3/src/cfront.h"
struct enumdef {	/* sizeof enumdef == 96 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 366 "/home/claude/cfront-3/src/cfront.h"
bit e_body__7enumdef ;
short no_of_enumerators__7enumdef ;
unsigned short e_strlen__7enumdef ;
const char *string__7enumdef ;
Pname mem__7enumdef ;
Pbase e_type__7enumdef ;
};
struct velem;

# 187 "/home/claude/cfront-3/src/cfront.h"

# 386 "/home/claude/cfront-3/src/cfront.h"
struct virt {	/* sizeof virt == 56 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 387 "/home/claude/cfront-3/src/cfront.h"
Pvirt next__4virt ;
int n_init__4virt ;
struct velem *virt_init__4virt ;
Pclass vclass__4virt ;
const char *string__4virt ;
bit is_vbase__4virt ;
bit printed__4virt ;
};
enum __E4 { C_VPTR = 1, C_XREF = 2, C_ASS = 4, C_VBASE = 8, C_REFM = 16} ;
struct cons;

# 401 "/home/claude/cfront-3/src/cfront.h"
typedef struct cons *Pcons ;
struct basic_template;
typedef struct basic_template *Ptempl_base ;
struct toknode;

# 404 "/home/claude/cfront-3/src/cfront.h"
struct classdef {	/* sizeof classdef == 240 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 405 "/home/claude/cfront-3/src/cfront.h"
int class_base__8classdef ;
bit c_body__8classdef ;
TOK csu__8classdef ;
bit obj_align__8classdef ;
bit c_xref__8classdef ;

# 416 "/home/claude/cfront-3/src/cfront.h"
short virt_count__8classdef ;

# 418 "/home/claude/cfront-3/src/cfront.h"
bit virt_merge__8classdef ;

# 420 "/home/claude/cfront-3/src/cfront.h"
bit has_vvtab__8classdef ;
unsigned short c_strlen__8classdef ;
Pbcl baselist__8classdef ;
const char *string__8classdef ;
Pname c_abstract__8classdef ;
Pname mem_list__8classdef ;
Ptable memtbl__8classdef ;
Pktab k_tbl__8classdef ;
Ptable c_context__8classdef ;
int obj_size__8classdef ;
int real_size__8classdef ;
Pcons templ_friends__8classdef ;
Plist friend_list__8classdef ;
Pname pubdef__8classdef ;
Ptype this_type__8classdef ;
Pvirt virt_list__8classdef ;
Pname c_ctor__8classdef ;
Pname c_dtor__8classdef ;
Pname c_itor__8classdef ;
Pname c_vtor__8classdef ;
Pname conv__8classdef ;
struct toknode *c_funqf__8classdef ;

# 441 "/home/claude/cfront-3/src/cfront.h"
struct toknode *c_funqr__8classdef ;
};

# 446 "/home/claude/cfront-3/src/cfront.h"
bit same_class__8classdefFP8classdefi (struct classdef *__0this , Pclass __1p , int );
struct clist;

# 503 "/home/claude/cfront-3/src/cfront.h"
struct clist {	/* sizeof clist == 16 */
Pclass cl__5clist ;
struct clist *next__5clist ;
};

# 512 "/home/claude/cfront-3/src/cfront.h"
extern struct clist *vcllist ;
struct vl;

# 514 "/home/claude/cfront-3/src/cfront.h"
struct vl {	/* sizeof vl == 24 */
struct vl *next__2vl ;
Pvirt vt__2vl ;
struct classdef *cl__2vl ;
};

# 523 "/home/claude/cfront-3/src/cfront.h"
extern struct vl *vlist ;

# 525 "/home/claude/cfront-3/src/cfront.h"
extern int nin ;
extern int Noffset ;
extern TOK Nvis ;
extern TOK Nvirt ;
extern Pexpr Nptr ;
extern Pbcl Nvbc_alloc ;
extern const char *Nalloc_base ;

# 540 "/home/claude/cfront-3/src/cfront.h"
extern int Vcheckerror ;
extern int ignore_const ;

# 543 "/home/claude/cfront-3/src/cfront.h"
extern int mex ;
extern Pclass mec ;
extern Pclass tcl ;
extern int processing_sizeof ;
union __Q2_8basetype4__C1;

# 574 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_8basetype4__C1 {	/* sizeof __Q2_8basetype4__C1 == 8 */
Ptype b_fieldtype ;
const char *b_linkage ;
};
enum Linkage { linkage_default = 0, linkage_C = 1, linkage_Cplusplus = 2} ;

# 595 "/home/claude/cfront-3/src/cfront.h"
extern int linkage ;

# 630 "/home/claude/cfront-3/src/cfront.h"
void *__nw__3fctSFUl (size_t );
void __dl__3fctSFPvUl (void *, size_t );

# 598 "/home/claude/cfront-3/src/cfront.h"
struct fct {	/* sizeof fct == 208 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 599 "/home/claude/cfront-3/src/cfront.h"
int fct_base__3fct ;
TOK nargs__3fct ;
TOK nargs_known__3fct ;
bit last_stmt__3fct ;
bit f_vdef__3fct ;

# 605 "/home/claude/cfront-3/src/cfront.h"
bit f_inline__3fct ;
bit f_is_inline__3fct ;

# 608 "/home/claude/cfront-3/src/cfront.h"
bit f_const__3fct ;

# 610 "/home/claude/cfront-3/src/cfront.h"
bit f_static__3fct ;
short f_virtual__3fct ;
short f_imeasure__3fct ;
Ptype returns__3fct ;
Pname argtype__3fct ;
Ptype s_returns__3fct ;
Pname f_this__3fct ;
Pclass memof__3fct ;
Pclass def_context__3fct ;
Pblock body__3fct ;
Pname f_init__3fct ;
Pexpr f_expr__3fct ;
Pexpr last_expanded__3fct ;
Pname nrv__3fct ;
Pname f_result__3fct ;
Pname f_args__3fct ;
int f_linkage__3fct ;
const char *f_signature__3fct ;
Plist local_class__3fct ;
};

# 629 "/home/claude/cfront-3/src/cfront.h"
extern Pfct fct_free__3fct ;
enum gen_types { no_templ = 0, some_templ = 1, all_templ = 2} ;

# 323 "/home/claude/cfront-3/src/cfront.h"

# 663 "/home/claude/cfront-3/src/cfront.h"
struct gen {	/* sizeof gen == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 664 "/home/claude/cfront-3/src/cfront.h"
Plist fct_list__3gen ;
int holds_templ__3gen ;
};
struct pvtyp;

# 323 "/home/claude/cfront-3/src/cfront.h"

# 679 "/home/claude/cfront-3/src/cfront.h"
struct pvtyp {	/* sizeof pvtyp == 72 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 680 "/home/claude/cfront-3/src/cfront.h"
Ptype typ__5pvtyp ;
};

# 690 "/home/claude/cfront-3/src/cfront.h"
void *__nw__3vecSFUl (size_t );
void __dl__3vecSFPvUl (void *, size_t );

# 681 "/home/claude/cfront-3/src/cfront.h"

# 685 "/home/claude/cfront-3/src/cfront.h"
struct vec {	/* sizeof vec == 88 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 680 "/home/claude/cfront-3/src/cfront.h"
Ptype typ__5pvtyp ;

# 686 "/home/claude/cfront-3/src/cfront.h"
Pexpr dim__3vec ;
int size__3vec ;
};
extern Pvec vec_free__3vec ;

# 705 "/home/claude/cfront-3/src/cfront.h"
void *__nw__3ptrSFUl (size_t );
void __dl__3ptrSFPvUl (void *, size_t );

# 681 "/home/claude/cfront-3/src/cfront.h"

# 700 "/home/claude/cfront-3/src/cfront.h"
struct ptr {	/* sizeof ptr == 88 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 680 "/home/claude/cfront-3/src/cfront.h"
Ptype typ__5pvtyp ;

# 701 "/home/claude/cfront-3/src/cfront.h"
Pclass memof__3ptr ;
Pname ptname__3ptr ;
};
extern Pptr ptr_free__3ptr ;

# 708 "/home/claude/cfront-3/src/cfront.h"

# 708 "/home/claude/cfront-3/src/cfront.h"
static struct ptr *__ct__3ptrFUcP4type (register struct ptr *__0this , TOK __2b , Ptype __2t ){ 
# 708 "/home/claude/cfront-3/src/cfront.h"
struct pvtyp *__0__X8 ;

# 708 "/home/claude/cfront-3/src/cfront.h"
struct type *__0__X6 ;

# 708 "/home/claude/cfront-3/src/cfront.h"
struct node *__0__X1 ;

# 708 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct ptr *)__nw__3ptrSFUl ( (unsigned long )(sizeof (struct ptr))) )){ __0this = (struct ptr *)( (__0__X8 =
# 708 "/home/claude/cfront-3/src/cfront.h"
(((struct pvtyp *)__0this ))), ( ((__0__X8 || (__0__X8 = (struct pvtyp *)__nw__FUl ( (unsigned long )(sizeof (struct pvtyp))) ))?(__0__X8 = (struct pvtyp *)(
# 708 "/home/claude/cfront-3/src/cfront.h"
(__0__X6 = (((struct type *)__0__X8 ))), ( ((__0__X6 || (__0__X6 = (struct type *)__nw__FUl ( (unsigned long )(sizeof (struct type))) ))?( (
# 708 "/home/claude/cfront-3/src/cfront.h"
( ( ( ( ( ( (__0__X6 = (struct type *)( (__0__X1 = (((struct node *)__0__X6 ))), ( ((__0__X1 ||
# 708 "/home/claude/cfront-3/src/cfront.h"
(__0__X1 = (struct node *)__nw__FUl ( (unsigned long )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 -> permanent__4node =
# 708 "/home/claude/cfront-3/src/cfront.h"
0 )) , (__0__X1 -> baseclass__4node = 0 )) :0 ), __0__X1 ) ) ), (__0__X6 -> defined__4type = 0 )) , (__0__X6 ->
# 708 "/home/claude/cfront-3/src/cfront.h"
lex_level__4type = 0 )) , (__0__X6 -> templ_base__4type = 0)) , (__0__X6 -> in_class__4type = 0 )) , (__0__X6 -> nested_sig__4type = 0 ))
# 708 "/home/claude/cfront-3/src/cfront.h"
, (__0__X6 -> local_sig__4type = 0 )) , (__0__X6 -> b_const__4type = 0 )) , (__0__X6 -> ansi_const__4type = 0 )) :0 ), __0__X6 )
# 708 "/home/claude/cfront-3/src/cfront.h"
) ):0 ), __0__X8 ) ) ;

# 708 "/home/claude/cfront-3/src/cfront.h"
__0this -> base__4node = __2b ;

# 708 "/home/claude/cfront-3/src/cfront.h"
__0this -> typ__5pvtyp = __2t ;

# 708 "/home/claude/cfront-3/src/cfront.h"
;
} 
# 708 "/home/claude/cfront-3/src/cfront.h"
return __0this ;

# 708 "/home/claude/cfront-3/src/cfront.h"
}

# 708 "/home/claude/cfront-3/src/cfront.h"

# 334 "/home/claude/cfront-3/src/cfront.h"
Ptype skiptypedefs__4typeFv (struct type *__0this );

# 743 "/home/claude/cfront-3/src/cfront.h"
extern int ref_initializer ;
extern int ntok ;
union __Q2_4expr4__C1;
union __Q2_4expr4__C2;
union __Q2_4expr4__C3;
union __Q2_4expr4__C4;

# 763 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 {	/* sizeof __Q2_4expr4__C1 == 8 */
Ptype tp ;
char *string4 ;
};
union  __Q2_4expr4__C2 {	/* sizeof __Q2_4expr4__C2 == 8 */
Pexpr e1 ;
long long i1 ;
const char *string ;
};
union  __Q2_4expr4__C3 {	/* sizeof __Q2_4expr4__C3 == 8 */
Pexpr e2 ;
int i2 ;
const char *string2 ;
Pexpr n_initializer ;
Ptype tpdef ;
};
union  __Q2_4expr4__C4 {	/* sizeof __Q2_4expr4__C4 == 8 */
Ptype tp2 ;
Pname fct_name ;
Pexpr cond ;
Pexpr mem ;
Ptype as_type ;
Ptable n_table ;
Pin il ;
Pname query_this ;
};

# 791 "/home/claude/cfront-3/src/cfront.h"
void *__nw__4exprSFUl (size_t );
void __dl__4exprSFPvUl (void *, size_t );

# 762 "/home/claude/cfront-3/src/cfront.h"
struct expr {	/* sizeof expr == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};
extern Pexpr expr_free__4expr ;

# 793 "/home/claude/cfront-3/src/cfront.h"
struct expr *__ct__4exprFUcP4exprT2 (struct expr *__0this , TOK , Pexpr , Pexpr );

# 819 "/home/claude/cfront-3/src/cfront.h"
struct texpr {	/* sizeof texpr == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"
struct cast;

# 823 "/home/claude/cfront-3/src/cfront.h"
struct cast {	/* sizeof cast == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"
struct ival;

# 827 "/home/claude/cfront-3/src/cfront.h"
struct ival {	/* sizeof ival == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"

# 831 "/home/claude/cfront-3/src/cfront.h"
struct call {	/* sizeof call == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"

# 839 "/home/claude/cfront-3/src/cfront.h"
struct qexpr {	/* sizeof qexpr == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"

# 843 "/home/claude/cfront-3/src/cfront.h"
struct ref {	/* sizeof ref == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"
struct mdot;

# 847 "/home/claude/cfront-3/src/cfront.h"
struct mdot {	/* sizeof mdot == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"
struct text_expr;

# 851 "/home/claude/cfront-3/src/cfront.h"
struct text_expr {	/* sizeof text_expr == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;
};

# 817 "/home/claude/cfront-3/src/cfront.h"

# 187 "/home/claude/cfront-3/src/cfront.h"

# 858 "/home/claude/cfront-3/src/cfront.h"
struct basecl {	/* sizeof basecl == 48 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 860 "/home/claude/cfront-3/src/cfront.h"
TOK ppp__6basecl ;
bit allocated__6basecl ;
bit promoted__6basecl ;
Pclass bclass__6basecl ;
Pexpr init__6basecl ;
int ptr_offset__6basecl ;
int obj_offset__6basecl ;
Pname *virt_init__6basecl ;
struct basecl *next__6basecl ;
};
enum template_formal_types { template_type_formal = 1, template_expr_formal = 2, template_actual_arg_dummy = 3} ;

# 878 "/home/claude/cfront-3/src/cfront.h"
extern TOK ppbase ;
union __Q2_4name4__C1;
union __Q2_4name4__C2;

# 905 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4name4__C1 {	/* sizeof __Q2_4name4__C1 == 8 */
Pname n_list ;
Pname n_hidden ;
Pname n_dtag ;
};

# 914 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4name4__C2 {	/* sizeof __Q2_4name4__C2 == 8 */

# 921 "/home/claude/cfront-3/src/cfront.h"
Pname n_qualifier ;
Ptable n_realscope ;
int syn_class ;
};

# 931 "/home/claude/cfront-3/src/cfront.h"
void *__nw__4nameSFUl (size_t );
void __dl__4nameSFPvUl (void *, size_t );

# 880 "/home/claude/cfront-3/src/cfront.h"
struct name {	/* sizeof name == 144 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 766 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C1 __O1__4expr ;

# 771 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C2 __O2__4expr ;

# 778 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C3 __O3__4expr ;

# 788 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4expr4__C4 __O4__4expr ;

# 881 "/home/claude/cfront-3/src/cfront.h"
TOK n_oper__4name ;
TOK n_sto__4name ;
TOK n_stclass__4name ;
TOK n_scope__4name ;
TOK n_key__4name ;
bit n_evaluated__4name ;
bit n_xref__4name ;
unsigned char lex_level__4name ;
TOK n_protect__4name ;
bit n_dcl_printed__4name ;

# 895 "/home/claude/cfront-3/src/cfront.h"
char n_template_arg__4name ;
bit n_template_fct__4name ;
bit n_redefined__4name ;

# 899 "/home/claude/cfront-3/src/cfront.h"
short n_addr_taken__4name ;
short n_used__4name ;
short n_assigned_to__4name ;
struct loc where__4name ;
int n_offset__4name ;
const char *n_anon__4name ;

# 909 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4name4__C1 __O1__4name ;
Pname n_tbl_list__4name ;
const char *n_gen_fct_name__4name ;
char *n_template_arg_string__4name ;
Pktab n_ktable__4name ;

# 924 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4name4__C2 __O2__4name ;

# 927 "/home/claude/cfront-3/src/cfront.h"
long long n_val__4name ;

# 929 "/home/claude/cfront-3/src/cfront.h"
int argno__4name ;
};

# 930 "/home/claude/cfront-3/src/cfront.h"
extern Pname name_free__4name ;

# 817 "/home/claude/cfront-3/src/cfront.h"

# 964 "/home/claude/cfront-3/src/cfront.h"
extern int friend_in_class ;
extern int in_class_dcl ;

# 968 "/home/claude/cfront-3/src/cfront.h"
extern int in_class_decl ;
extern int parsing_class_members ;
extern int in_mem_fct ;
extern int in_arg_list ;
extern Ptype in_typedef ;
extern int defer_check ;
extern int declTag ;
extern Pname in_tag ;
extern int DECL_TYPE ;
union __Q2_4stmt4__C1;
union __Q2_4stmt4__C2;
union __Q2_4stmt4__C3;

# 986 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 {	/* sizeof __Q2_4stmt4__C1 == 8 */
Pname d ;
Pexpr e2 ;
Pstmt has_default ;
int case_value ;
Ptype ret_tp ;
};
union  __Q2_4stmt4__C2 {	/* sizeof __Q2_4stmt4__C2 == 8 */
Pexpr e ;
bit own_tbl ;
Pstmt s2 ;
};

# 1000 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 {	/* sizeof __Q2_4stmt4__C3 == 8 */
Pstmt for_init ;
Pstmt else_stmt ;
Pstmt case_list ;
struct loc where2 ;
};

# 1009 "/home/claude/cfront-3/src/cfront.h"
void *__nw__4stmtSFUl (size_t );
void __dl__4stmtSFPvUl (void *, size_t );

# 980 "/home/claude/cfront-3/src/cfront.h"
struct stmt {	/* sizeof stmt == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};
extern Pstmt stmt_free__4stmt ;

# 1028 "/home/claude/cfront-3/src/cfront.h"
extern const char *Neval ;
extern Ptable scope ;
extern Ptable expand_tbl ;
extern Pname expand_fn ;

# 1011 "/home/claude/cfront-3/src/cfront.h"
struct stmt *__ct__4stmtFUc3locP4stmt (struct stmt *__0this , TOK , struct loc , Pstmt );

# 1041 "/home/claude/cfront-3/src/cfront.h"
struct estmt {	/* sizeof estmt == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"
struct ifstmt;

# 1048 "/home/claude/cfront-3/src/cfront.h"
struct ifstmt {	/* sizeof ifstmt == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"
struct lstmt;

# 1058 "/home/claude/cfront-3/src/cfront.h"
struct lstmt {	/* sizeof lstmt == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"
struct forstmt;

# 1062 "/home/claude/cfront-3/src/cfront.h"
struct forstmt {	/* sizeof forstmt == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"

# 1067 "/home/claude/cfront-3/src/cfront.h"
struct block {	/* sizeof block == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"
struct handler;

# 1076 "/home/claude/cfront-3/src/cfront.h"
struct handler {	/* sizeof handler == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"
struct pair;

# 1082 "/home/claude/cfront-3/src/cfront.h"
struct pair {	/* sizeof pair == 80 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 982 "/home/claude/cfront-3/src/cfront.h"
Pstmt s__4stmt ;
Pstmt s_list__4stmt ;
Pstmt gt__4stmt ;
struct loc where__4stmt ;

# 992 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C1 __O1__4stmt ;

# 997 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C2 __O2__4stmt ;
Ptable memtbl__4stmt ;
Pktab k_tbl__4stmt ;

# 1006 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_4stmt4__C3 __O3__4stmt ;
};

# 1025 "/home/claude/cfront-3/src/cfront.h"

# 1087 "/home/claude/cfront-3/src/cfront.h"
struct nlist {	/* sizeof nlist == 16 */
Pname head__5nlist ;
Pname tail__5nlist ;
};

# 1097 "/home/claude/cfront-3/src/cfront.h"
struct slist {	/* sizeof slist == 16 */
Pstmt head__5slist ;
Pstmt tail__5slist ;
};

# 1106 "/home/claude/cfront-3/src/cfront.h"
struct elist {	/* sizeof elist == 16 */
Pexpr head__5elist ;
Pexpr tail__5elist ;
};
struct dcl_context;

# 1116 "/home/claude/cfront-3/src/cfront.h"
extern struct dcl_context *cc ;

# 1120 "/home/claude/cfront-3/src/cfront.h"
extern struct dcl_context *ccvec_end ;

# 1122 "/home/claude/cfront-3/src/cfront.h"
struct dcl_context {	/* sizeof dcl_context == 48 */
Pname c_this__11dcl_context ;
Ptype tot__11dcl_context ;
Pname not4__11dcl_context ;
Pclass cot__11dcl_context ;
Ptable ftbl__11dcl_context ;
Pname nof__11dcl_context ;
};

# 84 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiPCc (int , const char *);

# 1146 "/home/claude/cfront-3/src/cfront.h"
extern const char *line_format ;

# 1148 "/home/claude/cfront-3/src/cfront.h"
extern Plist stat_mem_list ;
extern Plist isf_list ;
extern Pstmt st_ilist ;
extern Pstmt st_dlist ;
extern Ptable sti_tbl ;
extern Ptable std_tbl ;

# 1158 "/home/claude/cfront-3/src/cfront.h"
extern bit enum_promote ;
extern int suppress_error ;

# 1163 "/home/claude/cfront-3/src/cfront.h"
extern Pname overFound ;
extern Pname Nover ;
extern Pname Ncoerce ;
extern int Nover_coerce ;

# 187 "/home/claude/cfront-3/src/cfront.h"

# 1167 "/home/claude/cfront-3/src/cfront.h"
struct ia {	/* sizeof ia == 32 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 1168 "/home/claude/cfront-3/src/cfront.h"
Pname local__2ia ;
Pexpr arg__2ia ;
Ptype tp__2ia ;
};

# 187 "/home/claude/cfront-3/src/cfront.h"

# 1174 "/home/claude/cfront-3/src/cfront.h"
struct iline {	/* sizeof iline == 48 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 1175 "/home/claude/cfront-3/src/cfront.h"
Pname fct_name__5iline ;
Pin i_next__5iline ;
Ptable i_table__5iline ;
int i_slots__5iline ;
Pia i_args__5iline ;
};
struct con_dtor;

# 1183 "/home/claude/cfront-3/src/cfront.h"
struct con_dtor {	/* sizeof con_dtor == 24 */
Pname tn__8con_dtor ;
Pexpr condition__8con_dtor ;
struct con_dtor *next__8con_dtor ;
};

# 1191 "/home/claude/cfront-3/src/cfront.h"
extern struct con_dtor *pdlist ;
extern Pexpr curr_expr ;
extern Pin curr_icall ;

# 1198 "/home/claude/cfront-3/src/cfront.h"
extern Pstmt curr_loop ;
extern Pblock curr_block ;
extern Pstmt curr_switch ;
extern struct loc last_line ;
extern int last_ll ;
extern bit Cast ;
extern bit TCast ;
extern bit simpl_friend ;
extern bit in_return ;
extern struct loc no_where ;

# 1214 "/home/claude/cfront-3/src/cfront.h"
extern Pname vec_new_fct ;
extern Pname new_fct ;
extern Pname del_fct ;
extern Pname vec_del_fct ;

# 1219 "/home/claude/cfront-3/src/cfront.h"
extern int Nstd ;

# 1221 "/home/claude/cfront-3/src/cfront.h"
extern int stcount ;

# 1226 "/home/claude/cfront-3/src/cfront.h"
extern int Pchecked ;

# 1236 "/home/claude/cfront-3/src/cfront.h"
extern Pname Ntmp ;
extern Pname Ntmp_refd ;
extern Pname Ntmp_flag ;
extern Pexpr Ntmp_dtor ;

# 1250 "/home/claude/cfront-3/src/cfront.h"
extern Pclass Mptr ;

# 1254 "/home/claude/cfront-3/src/cfront.h"
extern bit fake_sizeof ;

# 559 "/home/claude/cfront-3/src/cfront.h"
struct basetype {	/* sizeof basetype == 112 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 310 "/home/claude/cfront-3/src/cfront.h"
bit defined__4type ;

# 312 "/home/claude/cfront-3/src/cfront.h"
bit lex_level__4type ;
int templ_base__4type ;
Pclass in_class__4type ;
Pname in_fct__4type ;
char *nested_sig__4type ;
char *local_sig__4type ;
bit b_const__4type ;
bit ansi_const__4type ;

# 322 "/home/claude/cfront-3/src/cfront.h"
Ptype tlist__4type ;

# 560 "/home/claude/cfront-3/src/cfront.h"
bit b_unsigned__8basetype ;
bit b_signed__8basetype ;
bit b_volatile__8basetype ;
bit b_typedef__8basetype ;
bit b_inline__8basetype ;
bit b_virtual__8basetype ;
bit b_short__8basetype ;
bit b_long__8basetype ;
bit b_bits__8basetype ;
bit b_offset__8basetype ;
TOK b_sto__8basetype ;
Pname b_name__8basetype ;
Ptable b_table__8basetype ;
Pname b_xname__8basetype ;

# 577 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_8basetype4__C1 __O1__8basetype ;
};

# 85 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiPCcRC2eaN33 (int , const char *, const struct ea *, const struct ea *, const
# 85 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 654 "/home/claude/cfront-3/src/cfront.h"
struct name_list {	/* sizeof name_list == 24 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 655 "/home/claude/cfront-3/src/cfront.h"
Pname f__9name_list ;
Plist l__9name_list ;
};

# 933 "/home/claude/cfront-3/src/cfront.h"
struct name *__ct__4nameFPCc (struct name *__0this , const char *);

# 224 "/home/claude/cfront-3/src/cfront.h"
Pname insert__5tableFP4nameUc (struct table *__0this , Pname , TOK );
struct Block_Pname;

# 21 "/home/claude/cfront-3/src/block.cpp"
struct Block_Pname {	/* sizeof Block_Pname == 16 */

# 21 "/home/claude/cfront-3/src/block.cpp"
Pname *p__11Block_Pname ;

# 21 "/home/claude/cfront-3/src/block.cpp"
size_t n__11Block_Pname ;
};

# 21 "/home/claude/cfront-3/src/block.cpp"
void move__11Block_PnameFPP4nameUl (struct Block_Pname *__0this , Pname *, size_t );

# 21 "/home/claude/cfront-3/src/block.cpp"
void copy__11Block_PnameFRC11Block_Pname (struct Block_Pname *__0this , const struct Block_Pname *);

# 1 ""
extern void __dl__FPv (void *);

# 21 "/home/claude/cfront-3/src/block.cpp"
size_t grow__11Block_PnameFUl (struct Block_Pname *__0this , size_t );
typedef struct Block_Pname BlockPname ;
struct Block_BlockPname;
struct Block_BlockPname {	/* sizeof Block_BlockPname == 16 */

# 23 "/home/claude/cfront-3/src/block.cpp"
BlockPname *p__16Block_BlockPname ;

# 23 "/home/claude/cfront-3/src/block.cpp"
size_t n__16Block_BlockPname ;
};

# 23 "/home/claude/cfront-3/src/block.cpp"
void move__16Block_BlockPnameFP11Block_PnameUl (struct Block_BlockPname *__0this , BlockPname *, size_t );

# 21 "/home/claude/cfront-3/src/block.cpp"
static struct Block_Pname *__ct__11Block_PnameFv (struct Block_Pname *__0this );

# 23 "/home/claude/cfront-3/src/block.cpp"
void copy__16Block_BlockPnameFRC16Block_BlockPname (struct Block_BlockPname *__0this , const struct Block_BlockPname *);

# 21 "/home/claude/cfront-3/src/block.cpp"
static void __dt__11Block_PnameFv (struct Block_Pname *__0this , int __0__free );

# 23 "/home/claude/cfront-3/src/block.cpp"
size_t grow__16Block_BlockPnameFUl (struct Block_BlockPname *__0this , size_t );
struct Block_int;
struct Block_int {	/* sizeof Block_int == 16 */

# 24 "/home/claude/cfront-3/src/block.cpp"
int *p__9Block_int ;

# 24 "/home/claude/cfront-3/src/block.cpp"
size_t n__9Block_int ;
};

# 24 "/home/claude/cfront-3/src/block.cpp"
void move__9Block_intFPiUl (struct Block_int *__0this , int *, size_t );

# 24 "/home/claude/cfront-3/src/block.cpp"
void copy__9Block_intFRC9Block_int (struct Block_int *__0this , const struct Block_int *);

# 24 "/home/claude/cfront-3/src/block.cpp"
size_t grow__9Block_intFUl (struct Block_int *__0this , size_t );
struct Block_Pchar;
struct Block_Pchar {	/* sizeof Block_Pchar == 16 */

# 25 "/home/claude/cfront-3/src/block.cpp"
Pchar *p__11Block_Pchar ;

# 25 "/home/claude/cfront-3/src/block.cpp"
size_t n__11Block_Pchar ;
};

# 25 "/home/claude/cfront-3/src/block.cpp"
void move__11Block_PcharFPPcUl (struct Block_Pchar *__0this , Pchar *, size_t );

# 25 "/home/claude/cfront-3/src/block.cpp"
void copy__11Block_PcharFRC11Block_Pchar (struct Block_Pchar *__0this , const struct Block_Pchar *);

# 25 "/home/claude/cfront-3/src/block.cpp"
size_t grow__11Block_PcharFUl (struct Block_Pchar *__0this , size_t );
struct Block_CPchar;
struct Block_CPchar {	/* sizeof Block_CPchar == 16 */

# 26 "/home/claude/cfront-3/src/block.cpp"
CPchar *p__12Block_CPchar ;

# 26 "/home/claude/cfront-3/src/block.cpp"
size_t n__12Block_CPchar ;
};

# 26 "/home/claude/cfront-3/src/block.cpp"
void move__12Block_CPcharFPPCcUl (struct Block_CPchar *__0this , CPchar *, size_t );

# 26 "/home/claude/cfront-3/src/block.cpp"
void copy__12Block_CPcharFRC12Block_CPchar (struct Block_CPchar *__0this , const struct Block_CPchar *);

# 26 "/home/claude/cfront-3/src/block.cpp"
size_t grow__12Block_CPcharFUl (struct Block_CPchar *__0this , size_t );
struct Block_short;
struct Block_short {	/* sizeof Block_short == 16 */

# 27 "/home/claude/cfront-3/src/block.cpp"
short *p__11Block_short ;

# 27 "/home/claude/cfront-3/src/block.cpp"
size_t n__11Block_short ;
};

# 27 "/home/claude/cfront-3/src/block.cpp"
void move__11Block_shortFPsUl (struct Block_short *__0this , short *, size_t );

# 27 "/home/claude/cfront-3/src/block.cpp"
void copy__11Block_shortFRC11Block_short (struct Block_short *__0this , const struct Block_short *);

# 27 "/home/claude/cfront-3/src/block.cpp"
size_t grow__11Block_shortFUl (struct Block_short *__0this , size_t );

# 29 "/home/claude/cfront-3/src/block.cpp"
static Pname Block_Pname_def ;

# 29 "/home/claude/cfront-3/src/block.cpp"
void clear__11Block_PnameFPP4nameUl (struct Block_Pname *__0this , Pname *__1v , size_t __1k ){ Pname *__1p ;

# 29 "/home/claude/cfront-3/src/block.cpp"
Pname *__1lim ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__1p = __1v ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__1lim = (__1v + __1k );

# 29 "/home/claude/cfront-3/src/block.cpp"
while (__1p < __1lim )((*(__1p ++ )))= Block_Pname_def ;

# 29 "/home/claude/cfront-3/src/block.cpp"
}

# 21 "/home/claude/cfront-3/src/block.cpp"
void transfer__11Block_PnameFPP4nameUl (struct Block_Pname *__0this , Pname *, size_t );

# 29 "/home/claude/cfront-3/src/block.cpp"
void copy__11Block_PnameFRC11Block_Pname (register struct Block_Pname *__0this , const struct Block_Pname *__1b ){ __0this -> p__11Block_Pname = (((struct name **)__nw__FUl ( (unsigned long )((sizeof
# 29 "/home/claude/cfront-3/src/block.cpp"
(struct name *))* ((*__1b )). n__11Block_Pname )) ));

# 29 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> p__11Block_Pname ){ __0this -> n__11Block_Pname = ((*__1b )). n__11Block_Pname ;

# 29 "/home/claude/cfront-3/src/block.cpp"
transfer__11Block_PnameFPP4nameUl ( __0this , (Pname *)((*__1b )). p__11Block_Pname , __0this -> n__11Block_Pname ) ;

# 29 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 29 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__11Block_Pname = 0 ;

# 29 "/home/claude/cfront-3/src/block.cpp"
}

# 29 "/home/claude/cfront-3/src/block.cpp"
size_t grow__11Block_PnameFUl (register struct Block_Pname *__0this , size_t __1k ){ size_t __1nn ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__1nn = __0this -> n__11Block_Pname ;

# 29 "/home/claude/cfront-3/src/block.cpp"
if (__1nn == 0 )__1nn ++ ;

# 29 "/home/claude/cfront-3/src/block.cpp"
while (__1nn <= __1k )__1nn += ((__1nn >> 1 )+ 1 );

# 29 "/home/claude/cfront-3/src/block.cpp"
{ Pname *__1np ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__1np = (((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* __1nn )) ));

# 29 "/home/claude/cfront-3/src/block.cpp"
if (! __1np ){ __1nn = (__1k + 1 );

# 29 "/home/claude/cfront-3/src/block.cpp"
__1np = (((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* __1nn )) ));

# 29 "/home/claude/cfront-3/src/block.cpp"
}

# 29 "/home/claude/cfront-3/src/block.cpp"
move__11Block_PnameFPP4nameUl ( __0this , __1np , __1nn ) ;

# 29 "/home/claude/cfront-3/src/block.cpp"
return __0this -> n__11Block_Pname ;

# 29 "/home/claude/cfront-3/src/block.cpp"
}

# 29 "/home/claude/cfront-3/src/block.cpp"
}

# 29 "/home/claude/cfront-3/src/block.cpp"
void transfer__11Block_PnameFPP4nameUl (register struct Block_Pname *__0this , Pname *__1source , size_t __1len ){ Pname *__1plim ;

# 29 "/home/claude/cfront-3/src/block.cpp"
Pname *__1pp ;

# 29 "/home/claude/cfront-3/src/block.cpp"
Pname *__1q ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__1pp = __0this -> p__11Block_Pname ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__1q = __1source ;

# 29 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> n__11Block_Pname > __1len ){ __1plim = (__0this -> p__11Block_Pname + __1len );

# 29 "/home/claude/cfront-3/src/block.cpp"
clear__11Block_PnameFPP4nameUl ( __0this , __1plim , __0this -> n__11Block_Pname - __1len ) ;

# 29 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 29 "/home/claude/cfront-3/src/block.cpp"
__1plim = (__0this -> p__11Block_Pname + __0this -> n__11Block_Pname );

# 29 "/home/claude/cfront-3/src/block.cpp"
while (__1pp < __1plim )((*(__1pp ++ )))= ((*(__1q ++ )));

# 29 "/home/claude/cfront-3/src/block.cpp"
}

# 29 "/home/claude/cfront-3/src/block.cpp"
void move__11Block_PnameFPP4nameUl (register struct Block_Pname *__0this , Pname *__1np , size_t __1nn ){ Pname *__1oldp ;

# 29 "/home/claude/cfront-3/src/block.cpp"
size_t __1oldn ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__1oldp = __0this -> p__11Block_Pname ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__1oldn = __0this -> n__11Block_Pname ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__11Block_Pname = __1np ;

# 29 "/home/claude/cfront-3/src/block.cpp"
if (__1np ){ __0this -> n__11Block_Pname = __1nn ;

# 29 "/home/claude/cfront-3/src/block.cpp"
transfer__11Block_PnameFPP4nameUl ( __0this , __1oldp , __1oldn ) ;

# 29 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 29 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__11Block_Pname = 0 ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__dl__FPv ( (void *)__1oldp ) ;

# 29 "/home/claude/cfront-3/src/block.cpp"
}

# 29 "/home/claude/cfront-3/src/block.cpp"
void swap__11Block_PnameFR11Block_Pname (register struct Block_Pname *__0this , struct Block_Pname *__1b ){ Pname *__1bp ;

# 29 "/home/claude/cfront-3/src/block.cpp"
size_t __1bn ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__1bp = ((*__1b )). p__11Block_Pname ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__1bn = ((*__1b )). n__11Block_Pname ;

# 29 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). p__11Block_Pname = __0this -> p__11Block_Pname ;

# 29 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). n__11Block_Pname = __0this -> n__11Block_Pname ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__11Block_Pname = __1bp ;

# 29 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__11Block_Pname = __1bn ;

# 29 "/home/claude/cfront-3/src/block.cpp"
}
static int Block_int_def ;

# 30 "/home/claude/cfront-3/src/block.cpp"
void clear__9Block_intFPiUl (struct Block_int *__0this , int *__1v , size_t __1k ){ int *__1p ;

# 30 "/home/claude/cfront-3/src/block.cpp"
int *__1lim ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__1p = __1v ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__1lim = (__1v + __1k );

# 30 "/home/claude/cfront-3/src/block.cpp"
while (__1p < __1lim )((*(__1p ++ )))= Block_int_def ;

# 30 "/home/claude/cfront-3/src/block.cpp"
}

# 24 "/home/claude/cfront-3/src/block.cpp"
void transfer__9Block_intFPiUl (struct Block_int *__0this , int *, size_t );

# 30 "/home/claude/cfront-3/src/block.cpp"
void copy__9Block_intFRC9Block_int (register struct Block_int *__0this , const struct Block_int *__1b ){ __0this -> p__9Block_int = (((int *)__nw__FUl ( (unsigned long )((sizeof
# 30 "/home/claude/cfront-3/src/block.cpp"
(int ))* ((*__1b )). n__9Block_int )) ));

# 30 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> p__9Block_int ){ __0this -> n__9Block_int = ((*__1b )). n__9Block_int ;

# 30 "/home/claude/cfront-3/src/block.cpp"
transfer__9Block_intFPiUl ( __0this , (int *)((*__1b )). p__9Block_int , __0this -> n__9Block_int ) ;

# 30 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 30 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__9Block_int = 0 ;

# 30 "/home/claude/cfront-3/src/block.cpp"
}

# 30 "/home/claude/cfront-3/src/block.cpp"
size_t grow__9Block_intFUl (register struct Block_int *__0this , size_t __1k ){ size_t __1nn ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__1nn = __0this -> n__9Block_int ;

# 30 "/home/claude/cfront-3/src/block.cpp"
if (__1nn == 0 )__1nn ++ ;

# 30 "/home/claude/cfront-3/src/block.cpp"
while (__1nn <= __1k )__1nn += ((__1nn >> 1 )+ 1 );

# 30 "/home/claude/cfront-3/src/block.cpp"
{ int *__1np ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__1np = (((int *)__nw__FUl ( (unsigned long )((sizeof (int ))* __1nn )) ));

# 30 "/home/claude/cfront-3/src/block.cpp"
if (! __1np ){ __1nn = (__1k + 1 );

# 30 "/home/claude/cfront-3/src/block.cpp"
__1np = (((int *)__nw__FUl ( (unsigned long )((sizeof (int ))* __1nn )) ));

# 30 "/home/claude/cfront-3/src/block.cpp"
}

# 30 "/home/claude/cfront-3/src/block.cpp"
move__9Block_intFPiUl ( __0this , __1np , __1nn ) ;

# 30 "/home/claude/cfront-3/src/block.cpp"
return __0this -> n__9Block_int ;

# 30 "/home/claude/cfront-3/src/block.cpp"
}

# 30 "/home/claude/cfront-3/src/block.cpp"
}

# 30 "/home/claude/cfront-3/src/block.cpp"
void transfer__9Block_intFPiUl (register struct Block_int *__0this , int *__1source , size_t __1len ){ int *__1plim ;

# 30 "/home/claude/cfront-3/src/block.cpp"
int *__1pp ;

# 30 "/home/claude/cfront-3/src/block.cpp"
int *__1q ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__1pp = __0this -> p__9Block_int ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__1q = __1source ;

# 30 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> n__9Block_int > __1len ){ __1plim = (__0this -> p__9Block_int + __1len );

# 30 "/home/claude/cfront-3/src/block.cpp"
clear__9Block_intFPiUl ( __0this , __1plim , __0this -> n__9Block_int - __1len ) ;

# 30 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 30 "/home/claude/cfront-3/src/block.cpp"
__1plim = (__0this -> p__9Block_int + __0this -> n__9Block_int );

# 30 "/home/claude/cfront-3/src/block.cpp"
while (__1pp < __1plim )((*(__1pp ++ )))= ((*(__1q ++ )));

# 30 "/home/claude/cfront-3/src/block.cpp"
}

# 30 "/home/claude/cfront-3/src/block.cpp"
void move__9Block_intFPiUl (register struct Block_int *__0this , int *__1np , size_t __1nn ){ int *__1oldp ;

# 30 "/home/claude/cfront-3/src/block.cpp"
size_t __1oldn ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__1oldp = __0this -> p__9Block_int ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__1oldn = __0this -> n__9Block_int ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__9Block_int = __1np ;

# 30 "/home/claude/cfront-3/src/block.cpp"
if (__1np ){ __0this -> n__9Block_int = __1nn ;

# 30 "/home/claude/cfront-3/src/block.cpp"
transfer__9Block_intFPiUl ( __0this , __1oldp , __1oldn ) ;

# 30 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 30 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__9Block_int = 0 ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__dl__FPv ( (void *)__1oldp ) ;

# 30 "/home/claude/cfront-3/src/block.cpp"
}

# 30 "/home/claude/cfront-3/src/block.cpp"
void swap__9Block_intFR9Block_int (register struct Block_int *__0this , struct Block_int *__1b ){ int *__1bp ;

# 30 "/home/claude/cfront-3/src/block.cpp"
size_t __1bn ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__1bp = ((*__1b )). p__9Block_int ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__1bn = ((*__1b )). n__9Block_int ;

# 30 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). p__9Block_int = __0this -> p__9Block_int ;

# 30 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). n__9Block_int = __0this -> n__9Block_int ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__9Block_int = __1bp ;

# 30 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__9Block_int = __1bn ;

# 30 "/home/claude/cfront-3/src/block.cpp"
}
static BlockPname Block_BlockPname_def ;

# 21 "/home/claude/cfront-3/src/block.cpp"

# 31 "/home/claude/cfront-3/src/block.cpp"
void clear__16Block_BlockPnameFP11Block_PnameUl (struct Block_BlockPname *__0this , BlockPname *__1v , size_t __1k ){ BlockPname *__1p ;

# 31 "/home/claude/cfront-3/src/block.cpp"
BlockPname *__1lim ;

# 32 "/home/claude/cfront-3/src/block.cpp"
register struct Block_Pname *__0__X17 ;

# 32 "/home/claude/cfront-3/src/block.cpp"
const struct Block_Pname *__2__X18 ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__1p = __1v ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__1lim = (__1v + __1k );

# 31 "/home/claude/cfront-3/src/block.cpp"
while (__1p < __1lim )( (__0__X17 = (__1p ++ )), ( (__2__X18 = (const struct Block_Pname *)(& Block_BlockPname_def )), ( __dl__FPv (
# 31 "/home/claude/cfront-3/src/block.cpp"
(void *)__0__X17 -> p__11Block_Pname ) , ( copy__11Block_PnameFRC11Block_Pname ( __0__X17 , __2__X18 ) , (((struct Block_Pname *)__0__X17 ))) ) ) )
# 31 "/home/claude/cfront-3/src/block.cpp"
;

# 31 "/home/claude/cfront-3/src/block.cpp"
}

# 23 "/home/claude/cfront-3/src/block.cpp"
void transfer__16Block_BlockPnameFP11Block_PnameUl (struct Block_BlockPname *__0this , BlockPname *, size_t );

# 31 "/home/claude/cfront-3/src/block.cpp"
void copy__16Block_BlockPnameFRC16Block_BlockPname (register struct Block_BlockPname *__0this , const struct Block_BlockPname *__1b ){ __0this -> p__16Block_BlockPname = (((struct Block_Pname *)__vec_new ( ((void *)0 ), ((*__1b )).
# 31 "/home/claude/cfront-3/src/block.cpp"
n__16Block_BlockPname , sizeof (struct Block_Pname ), ((void *)__ct__11Block_PnameFv )) ));

# 31 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> p__16Block_BlockPname ){ __0this -> n__16Block_BlockPname = ((*__1b )). n__16Block_BlockPname ;

# 31 "/home/claude/cfront-3/src/block.cpp"
transfer__16Block_BlockPnameFP11Block_PnameUl ( __0this , (BlockPname *)((*__1b )). p__16Block_BlockPname , __0this -> n__16Block_BlockPname ) ;

# 31 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 31 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__16Block_BlockPname = 0 ;

# 31 "/home/claude/cfront-3/src/block.cpp"
}

# 31 "/home/claude/cfront-3/src/block.cpp"
size_t grow__16Block_BlockPnameFUl (register struct Block_BlockPname *__0this , size_t __1k ){ size_t __1nn ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__1nn = __0this -> n__16Block_BlockPname ;

# 31 "/home/claude/cfront-3/src/block.cpp"
if (__1nn == 0 )__1nn ++ ;

# 31 "/home/claude/cfront-3/src/block.cpp"
while (__1nn <= __1k )__1nn += ((__1nn >> 1 )+ 1 );

# 31 "/home/claude/cfront-3/src/block.cpp"
{ BlockPname *__1np ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__1np = (((struct Block_Pname *)__vec_new ( ((void *)0 ), __1nn , sizeof (struct Block_Pname ), ((void *)__ct__11Block_PnameFv )) ));

# 31 "/home/claude/cfront-3/src/block.cpp"
if (! __1np ){ __1nn = (__1k + 1 );

# 31 "/home/claude/cfront-3/src/block.cpp"
__1np = (((struct Block_Pname *)__vec_new ( ((void *)0 ), __1nn , sizeof (struct Block_Pname ), ((void *)__ct__11Block_PnameFv )) ));

# 31 "/home/claude/cfront-3/src/block.cpp"
}

# 31 "/home/claude/cfront-3/src/block.cpp"
move__16Block_BlockPnameFP11Block_PnameUl ( __0this , __1np , __1nn ) ;

# 31 "/home/claude/cfront-3/src/block.cpp"
return __0this -> n__16Block_BlockPname ;

# 31 "/home/claude/cfront-3/src/block.cpp"
}

# 31 "/home/claude/cfront-3/src/block.cpp"
}

# 21 "/home/claude/cfront-3/src/block.cpp"

# 31 "/home/claude/cfront-3/src/block.cpp"
void transfer__16Block_BlockPnameFP11Block_PnameUl (register struct Block_BlockPname *__0this , BlockPname *__1source , size_t __1len ){ BlockPname *__1plim ;

# 31 "/home/claude/cfront-3/src/block.cpp"
BlockPname *__1pp ;

# 31 "/home/claude/cfront-3/src/block.cpp"
BlockPname *__1q ;

# 32 "/home/claude/cfront-3/src/block.cpp"
register struct Block_Pname *__0__X19 ;

# 32 "/home/claude/cfront-3/src/block.cpp"
const struct Block_Pname *__2__X20 ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__1pp = __0this -> p__16Block_BlockPname ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__1q = __1source ;

# 31 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> n__16Block_BlockPname > __1len ){ __1plim = (__0this -> p__16Block_BlockPname + __1len );

# 31 "/home/claude/cfront-3/src/block.cpp"
clear__16Block_BlockPnameFP11Block_PnameUl ( __0this , __1plim , __0this -> n__16Block_BlockPname - __1len ) ;

# 31 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 31 "/home/claude/cfront-3/src/block.cpp"
__1plim = (__0this -> p__16Block_BlockPname + __0this -> n__16Block_BlockPname );

# 31 "/home/claude/cfront-3/src/block.cpp"
while (__1pp < __1plim )( (__0__X19 = (__1pp ++ )), ( (__2__X20 = (const struct Block_Pname *)(__1q ++ )), ( __dl__FPv (
# 31 "/home/claude/cfront-3/src/block.cpp"
(void *)__0__X19 -> p__11Block_Pname ) , ( copy__11Block_PnameFRC11Block_Pname ( __0__X19 , __2__X20 ) , (((struct Block_Pname *)__0__X19 ))) ) ) )
# 31 "/home/claude/cfront-3/src/block.cpp"
;

# 31 "/home/claude/cfront-3/src/block.cpp"
}

# 31 "/home/claude/cfront-3/src/block.cpp"
void move__16Block_BlockPnameFP11Block_PnameUl (register struct Block_BlockPname *__0this , BlockPname *__1np , size_t __1nn ){ BlockPname *__1oldp ;

# 31 "/home/claude/cfront-3/src/block.cpp"
size_t __1oldn ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__1oldp = __0this -> p__16Block_BlockPname ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__1oldn = __0this -> n__16Block_BlockPname ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__16Block_BlockPname = __1np ;

# 31 "/home/claude/cfront-3/src/block.cpp"
if (__1np ){ __0this -> n__16Block_BlockPname = __1nn ;

# 31 "/home/claude/cfront-3/src/block.cpp"
transfer__16Block_BlockPnameFP11Block_PnameUl ( __0this , __1oldp , __1oldn ) ;

# 31 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 31 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__16Block_BlockPname = 0 ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__vec_delete ( ((void *)__1oldp ), -1, sizeof (struct Block_Pname ), ((void *)__dt__11Block_PnameFv ), 1, 0) ;

# 31 "/home/claude/cfront-3/src/block.cpp"
}

# 31 "/home/claude/cfront-3/src/block.cpp"
void swap__16Block_BlockPnameFR16Block_BlockPname (register struct Block_BlockPname *__0this , struct Block_BlockPname *__1b ){ BlockPname *__1bp ;

# 31 "/home/claude/cfront-3/src/block.cpp"
size_t __1bn ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__1bp = ((*__1b )). p__16Block_BlockPname ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__1bn = ((*__1b )). n__16Block_BlockPname ;

# 31 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). p__16Block_BlockPname = __0this -> p__16Block_BlockPname ;

# 31 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). n__16Block_BlockPname = __0this -> n__16Block_BlockPname ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__16Block_BlockPname = __1bp ;

# 31 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__16Block_BlockPname = __1bn ;

# 31 "/home/claude/cfront-3/src/block.cpp"
}
static Pchar Block_Pchar_def ;

# 32 "/home/claude/cfront-3/src/block.cpp"
void clear__11Block_PcharFPPcUl (struct Block_Pchar *__0this , Pchar *__1v , size_t __1k ){ Pchar *__1p ;

# 32 "/home/claude/cfront-3/src/block.cpp"
Pchar *__1lim ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__1p = __1v ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__1lim = (__1v + __1k );

# 32 "/home/claude/cfront-3/src/block.cpp"
while (__1p < __1lim )((*(__1p ++ )))= Block_Pchar_def ;

# 32 "/home/claude/cfront-3/src/block.cpp"
}

# 25 "/home/claude/cfront-3/src/block.cpp"
void transfer__11Block_PcharFPPcUl (struct Block_Pchar *__0this , Pchar *, size_t );

# 32 "/home/claude/cfront-3/src/block.cpp"
void copy__11Block_PcharFRC11Block_Pchar (register struct Block_Pchar *__0this , const struct Block_Pchar *__1b ){ __0this -> p__11Block_Pchar = (((char **)__nw__FUl ( (unsigned long )((sizeof
# 32 "/home/claude/cfront-3/src/block.cpp"
(char *))* ((*__1b )). n__11Block_Pchar )) ));

# 32 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> p__11Block_Pchar ){ __0this -> n__11Block_Pchar = ((*__1b )). n__11Block_Pchar ;

# 32 "/home/claude/cfront-3/src/block.cpp"
transfer__11Block_PcharFPPcUl ( __0this , (Pchar *)((*__1b )). p__11Block_Pchar , __0this -> n__11Block_Pchar ) ;

# 32 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 32 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__11Block_Pchar = 0 ;

# 32 "/home/claude/cfront-3/src/block.cpp"
}

# 32 "/home/claude/cfront-3/src/block.cpp"
size_t grow__11Block_PcharFUl (register struct Block_Pchar *__0this , size_t __1k ){ size_t __1nn ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__1nn = __0this -> n__11Block_Pchar ;

# 32 "/home/claude/cfront-3/src/block.cpp"
if (__1nn == 0 )__1nn ++ ;

# 32 "/home/claude/cfront-3/src/block.cpp"
while (__1nn <= __1k )__1nn += ((__1nn >> 1 )+ 1 );

# 32 "/home/claude/cfront-3/src/block.cpp"
{ Pchar *__1np ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__1np = (((char **)__nw__FUl ( (unsigned long )((sizeof (char *))* __1nn )) ));

# 32 "/home/claude/cfront-3/src/block.cpp"
if (! __1np ){ __1nn = (__1k + 1 );

# 32 "/home/claude/cfront-3/src/block.cpp"
__1np = (((char **)__nw__FUl ( (unsigned long )((sizeof (char *))* __1nn )) ));

# 32 "/home/claude/cfront-3/src/block.cpp"
}

# 32 "/home/claude/cfront-3/src/block.cpp"
move__11Block_PcharFPPcUl ( __0this , __1np , __1nn ) ;

# 32 "/home/claude/cfront-3/src/block.cpp"
return __0this -> n__11Block_Pchar ;

# 32 "/home/claude/cfront-3/src/block.cpp"
}

# 32 "/home/claude/cfront-3/src/block.cpp"
}

# 32 "/home/claude/cfront-3/src/block.cpp"
void transfer__11Block_PcharFPPcUl (register struct Block_Pchar *__0this , Pchar *__1source , size_t __1len ){ Pchar *__1plim ;

# 32 "/home/claude/cfront-3/src/block.cpp"
Pchar *__1pp ;

# 32 "/home/claude/cfront-3/src/block.cpp"
Pchar *__1q ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__1pp = __0this -> p__11Block_Pchar ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__1q = __1source ;

# 32 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> n__11Block_Pchar > __1len ){ __1plim = (__0this -> p__11Block_Pchar + __1len );

# 32 "/home/claude/cfront-3/src/block.cpp"
clear__11Block_PcharFPPcUl ( __0this , __1plim , __0this -> n__11Block_Pchar - __1len ) ;

# 32 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 32 "/home/claude/cfront-3/src/block.cpp"
__1plim = (__0this -> p__11Block_Pchar + __0this -> n__11Block_Pchar );

# 32 "/home/claude/cfront-3/src/block.cpp"
while (__1pp < __1plim )((*(__1pp ++ )))= ((*(__1q ++ )));

# 32 "/home/claude/cfront-3/src/block.cpp"
}

# 32 "/home/claude/cfront-3/src/block.cpp"
void move__11Block_PcharFPPcUl (register struct Block_Pchar *__0this , Pchar *__1np , size_t __1nn ){ Pchar *__1oldp ;

# 32 "/home/claude/cfront-3/src/block.cpp"
size_t __1oldn ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__1oldp = __0this -> p__11Block_Pchar ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__1oldn = __0this -> n__11Block_Pchar ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__11Block_Pchar = __1np ;

# 32 "/home/claude/cfront-3/src/block.cpp"
if (__1np ){ __0this -> n__11Block_Pchar = __1nn ;

# 32 "/home/claude/cfront-3/src/block.cpp"
transfer__11Block_PcharFPPcUl ( __0this , __1oldp , __1oldn ) ;

# 32 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 32 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__11Block_Pchar = 0 ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__dl__FPv ( (void *)__1oldp ) ;

# 32 "/home/claude/cfront-3/src/block.cpp"
}

# 32 "/home/claude/cfront-3/src/block.cpp"
void swap__11Block_PcharFR11Block_Pchar (register struct Block_Pchar *__0this , struct Block_Pchar *__1b ){ Pchar *__1bp ;

# 32 "/home/claude/cfront-3/src/block.cpp"
size_t __1bn ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__1bp = ((*__1b )). p__11Block_Pchar ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__1bn = ((*__1b )). n__11Block_Pchar ;

# 32 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). p__11Block_Pchar = __0this -> p__11Block_Pchar ;

# 32 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). n__11Block_Pchar = __0this -> n__11Block_Pchar ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__11Block_Pchar = __1bp ;

# 32 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__11Block_Pchar = __1bn ;

# 32 "/home/claude/cfront-3/src/block.cpp"
}
static CPchar Block_CPchar_def ;

# 33 "/home/claude/cfront-3/src/block.cpp"
void clear__12Block_CPcharFPPCcUl (struct Block_CPchar *__0this , CPchar *__1v , size_t __1k ){ CPchar *__1p ;

# 33 "/home/claude/cfront-3/src/block.cpp"
CPchar *__1lim ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__1p = __1v ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__1lim = (__1v + __1k );

# 33 "/home/claude/cfront-3/src/block.cpp"
while (__1p < __1lim )((*(__1p ++ )))= Block_CPchar_def ;

# 33 "/home/claude/cfront-3/src/block.cpp"
}

# 26 "/home/claude/cfront-3/src/block.cpp"
void transfer__12Block_CPcharFPPCcUl (struct Block_CPchar *__0this , CPchar *, size_t );

# 33 "/home/claude/cfront-3/src/block.cpp"
void copy__12Block_CPcharFRC12Block_CPchar (register struct Block_CPchar *__0this , const struct Block_CPchar *__1b ){ __0this -> p__12Block_CPchar = (((const char **)__nw__FUl ( (unsigned long
# 33 "/home/claude/cfront-3/src/block.cpp"
)((sizeof (const char *))* ((*__1b )). n__12Block_CPchar )) ));

# 33 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> p__12Block_CPchar ){ __0this -> n__12Block_CPchar = ((*__1b )). n__12Block_CPchar ;

# 33 "/home/claude/cfront-3/src/block.cpp"
transfer__12Block_CPcharFPPCcUl ( __0this , (CPchar *)((*__1b )). p__12Block_CPchar , __0this -> n__12Block_CPchar ) ;

# 33 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 33 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__12Block_CPchar = 0 ;

# 33 "/home/claude/cfront-3/src/block.cpp"
}

# 33 "/home/claude/cfront-3/src/block.cpp"
size_t grow__12Block_CPcharFUl (register struct Block_CPchar *__0this , size_t __1k ){ size_t __1nn ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__1nn = __0this -> n__12Block_CPchar ;

# 33 "/home/claude/cfront-3/src/block.cpp"
if (__1nn == 0 )__1nn ++ ;

# 33 "/home/claude/cfront-3/src/block.cpp"
while (__1nn <= __1k )__1nn += ((__1nn >> 1 )+ 1 );

# 33 "/home/claude/cfront-3/src/block.cpp"
{ CPchar *__1np ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__1np = (((const char **)__nw__FUl ( (unsigned long )((sizeof (const char *))* __1nn )) ));

# 33 "/home/claude/cfront-3/src/block.cpp"
if (! __1np ){ __1nn = (__1k + 1 );

# 33 "/home/claude/cfront-3/src/block.cpp"
__1np = (((const char **)__nw__FUl ( (unsigned long )((sizeof (const char *))* __1nn )) ));

# 33 "/home/claude/cfront-3/src/block.cpp"
}

# 33 "/home/claude/cfront-3/src/block.cpp"
move__12Block_CPcharFPPCcUl ( __0this , __1np , __1nn ) ;

# 33 "/home/claude/cfront-3/src/block.cpp"
return __0this -> n__12Block_CPchar ;

# 33 "/home/claude/cfront-3/src/block.cpp"
}

# 33 "/home/claude/cfront-3/src/block.cpp"
}

# 33 "/home/claude/cfront-3/src/block.cpp"
void transfer__12Block_CPcharFPPCcUl (register struct Block_CPchar *__0this , CPchar *__1source , size_t __1len ){ CPchar *__1plim ;

# 33 "/home/claude/cfront-3/src/block.cpp"
CPchar *__1pp ;

# 33 "/home/claude/cfront-3/src/block.cpp"
CPchar *__1q ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__1pp = __0this -> p__12Block_CPchar ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__1q = __1source ;

# 33 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> n__12Block_CPchar > __1len ){ __1plim = (__0this -> p__12Block_CPchar + __1len );

# 33 "/home/claude/cfront-3/src/block.cpp"
clear__12Block_CPcharFPPCcUl ( __0this , __1plim , __0this -> n__12Block_CPchar - __1len ) ;

# 33 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 33 "/home/claude/cfront-3/src/block.cpp"
__1plim = (__0this -> p__12Block_CPchar + __0this -> n__12Block_CPchar );

# 33 "/home/claude/cfront-3/src/block.cpp"
while (__1pp < __1plim )((*(__1pp ++ )))= ((*(__1q ++ )));

# 33 "/home/claude/cfront-3/src/block.cpp"
}

# 33 "/home/claude/cfront-3/src/block.cpp"
void move__12Block_CPcharFPPCcUl (register struct Block_CPchar *__0this , CPchar *__1np , size_t __1nn ){ CPchar *__1oldp ;

# 33 "/home/claude/cfront-3/src/block.cpp"
size_t __1oldn ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__1oldp = __0this -> p__12Block_CPchar ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__1oldn = __0this -> n__12Block_CPchar ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__12Block_CPchar = __1np ;

# 33 "/home/claude/cfront-3/src/block.cpp"
if (__1np ){ __0this -> n__12Block_CPchar = __1nn ;

# 33 "/home/claude/cfront-3/src/block.cpp"
transfer__12Block_CPcharFPPCcUl ( __0this , __1oldp , __1oldn ) ;

# 33 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 33 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__12Block_CPchar = 0 ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__dl__FPv ( (void *)__1oldp ) ;

# 33 "/home/claude/cfront-3/src/block.cpp"
}

# 33 "/home/claude/cfront-3/src/block.cpp"
void swap__12Block_CPcharFR12Block_CPchar (register struct Block_CPchar *__0this , struct Block_CPchar *__1b ){ CPchar *__1bp ;

# 33 "/home/claude/cfront-3/src/block.cpp"
size_t __1bn ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__1bp = ((*__1b )). p__12Block_CPchar ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__1bn = ((*__1b )). n__12Block_CPchar ;

# 33 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). p__12Block_CPchar = __0this -> p__12Block_CPchar ;

# 33 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). n__12Block_CPchar = __0this -> n__12Block_CPchar ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__12Block_CPchar = __1bp ;

# 33 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__12Block_CPchar = __1bn ;

# 33 "/home/claude/cfront-3/src/block.cpp"
}
static short Block_short_def ;

# 34 "/home/claude/cfront-3/src/block.cpp"
void clear__11Block_shortFPsUl (struct Block_short *__0this , short *__1v , size_t __1k ){ short *__1p ;

# 34 "/home/claude/cfront-3/src/block.cpp"
short *__1lim ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__1p = __1v ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__1lim = (__1v + __1k );

# 34 "/home/claude/cfront-3/src/block.cpp"
while (__1p < __1lim )((*(__1p ++ )))= Block_short_def ;

# 34 "/home/claude/cfront-3/src/block.cpp"
}

# 27 "/home/claude/cfront-3/src/block.cpp"
void transfer__11Block_shortFPsUl (struct Block_short *__0this , short *, size_t );

# 34 "/home/claude/cfront-3/src/block.cpp"
void copy__11Block_shortFRC11Block_short (register struct Block_short *__0this , const struct Block_short *__1b ){ __0this -> p__11Block_short = (((short *)__nw__FUl ( (unsigned long )((sizeof
# 34 "/home/claude/cfront-3/src/block.cpp"
(short ))* ((*__1b )). n__11Block_short )) ));

# 34 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> p__11Block_short ){ __0this -> n__11Block_short = ((*__1b )). n__11Block_short ;

# 34 "/home/claude/cfront-3/src/block.cpp"
transfer__11Block_shortFPsUl ( __0this , (short *)((*__1b )). p__11Block_short , __0this -> n__11Block_short ) ;

# 34 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 34 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__11Block_short = 0 ;

# 34 "/home/claude/cfront-3/src/block.cpp"
}

# 34 "/home/claude/cfront-3/src/block.cpp"
size_t grow__11Block_shortFUl (register struct Block_short *__0this , size_t __1k ){ size_t __1nn ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__1nn = __0this -> n__11Block_short ;

# 34 "/home/claude/cfront-3/src/block.cpp"
if (__1nn == 0 )__1nn ++ ;

# 34 "/home/claude/cfront-3/src/block.cpp"
while (__1nn <= __1k )__1nn += ((__1nn >> 1 )+ 1 );

# 34 "/home/claude/cfront-3/src/block.cpp"
{ short *__1np ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__1np = (((short *)__nw__FUl ( (unsigned long )((sizeof (short ))* __1nn )) ));

# 34 "/home/claude/cfront-3/src/block.cpp"
if (! __1np ){ __1nn = (__1k + 1 );

# 34 "/home/claude/cfront-3/src/block.cpp"
__1np = (((short *)__nw__FUl ( (unsigned long )((sizeof (short ))* __1nn )) ));

# 34 "/home/claude/cfront-3/src/block.cpp"
}

# 34 "/home/claude/cfront-3/src/block.cpp"
move__11Block_shortFPsUl ( __0this , __1np , __1nn ) ;

# 34 "/home/claude/cfront-3/src/block.cpp"
return __0this -> n__11Block_short ;

# 34 "/home/claude/cfront-3/src/block.cpp"
}

# 34 "/home/claude/cfront-3/src/block.cpp"
}

# 34 "/home/claude/cfront-3/src/block.cpp"
void transfer__11Block_shortFPsUl (register struct Block_short *__0this , short *__1source , size_t __1len ){ short *__1plim ;

# 34 "/home/claude/cfront-3/src/block.cpp"
short *__1pp ;

# 34 "/home/claude/cfront-3/src/block.cpp"
short *__1q ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__1pp = __0this -> p__11Block_short ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__1q = __1source ;

# 34 "/home/claude/cfront-3/src/block.cpp"
if (__0this -> n__11Block_short > __1len ){ __1plim = (__0this -> p__11Block_short + __1len );

# 34 "/home/claude/cfront-3/src/block.cpp"
clear__11Block_shortFPsUl ( __0this , __1plim , __0this -> n__11Block_short - __1len ) ;

# 34 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 34 "/home/claude/cfront-3/src/block.cpp"
__1plim = (__0this -> p__11Block_short + __0this -> n__11Block_short );

# 34 "/home/claude/cfront-3/src/block.cpp"
while (__1pp < __1plim )((*(__1pp ++ )))= ((*(__1q ++ )));

# 34 "/home/claude/cfront-3/src/block.cpp"
}

# 34 "/home/claude/cfront-3/src/block.cpp"
void move__11Block_shortFPsUl (register struct Block_short *__0this , short *__1np , size_t __1nn ){ short *__1oldp ;

# 34 "/home/claude/cfront-3/src/block.cpp"
size_t __1oldn ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__1oldp = __0this -> p__11Block_short ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__1oldn = __0this -> n__11Block_short ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__11Block_short = __1np ;

# 34 "/home/claude/cfront-3/src/block.cpp"
if (__1np ){ __0this -> n__11Block_short = __1nn ;

# 34 "/home/claude/cfront-3/src/block.cpp"
transfer__11Block_shortFPsUl ( __0this , __1oldp , __1oldn ) ;

# 34 "/home/claude/cfront-3/src/block.cpp"
}
else 
# 34 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__11Block_short = 0 ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__dl__FPv ( (void *)__1oldp ) ;

# 34 "/home/claude/cfront-3/src/block.cpp"
}

# 34 "/home/claude/cfront-3/src/block.cpp"
void swap__11Block_shortFR11Block_short (register struct Block_short *__0this , struct Block_short *__1b ){ short *__1bp ;

# 34 "/home/claude/cfront-3/src/block.cpp"
size_t __1bn ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__1bp = ((*__1b )). p__11Block_short ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__1bn = ((*__1b )). n__11Block_short ;

# 34 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). p__11Block_short = __0this -> p__11Block_short ;

# 34 "/home/claude/cfront-3/src/block.cpp"
((*__1b )). n__11Block_short = __0this -> n__11Block_short ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__11Block_short = __1bp ;

# 34 "/home/claude/cfront-3/src/block.cpp"
__0this -> n__11Block_short = __1bn ;

# 34 "/home/claude/cfront-3/src/block.cpp"
}

# 34 "/home/claude/cfront-3/src/block.cpp"
void __sti___clear_ (void )
# 31 "/home/claude/cfront-3/src/block.cpp"
{ 
# 31 "/home/claude/cfront-3/src/block.cpp"
struct Block_Pname *__0__X21 ;

# 31 "/home/claude/cfront-3/src/block.cpp"
( (__0__X21 = (& Block_BlockPname_def )), ( ((__0__X21 || (__0__X21 = (struct Block_Pname *)__nw__FUl ( (unsigned long )(sizeof (struct Block_Pname))) ))?(
# 31 "/home/claude/cfront-3/src/block.cpp"
(__0__X21 -> n__11Block_Pname = 0 ), (__0__X21 -> p__11Block_Pname = 0 )) :0 ), __0__X21 ) ) ;

# 31 "/home/claude/cfront-3/src/block.cpp"
}

# 34 "/home/claude/cfront-3/src/block.cpp"
void __std___clear_ (void )
# 31 "/home/claude/cfront-3/src/block.cpp"
{ 
# 31 "/home/claude/cfront-3/src/block.cpp"
struct Block_Pname *__0__X22 ;

# 31 "/home/claude/cfront-3/src/block.cpp"
( (__0__X22 = (& Block_BlockPname_def )), ( (__0__X22 ?(((void )( __dl__FPv ( (void *)__0__X22 -> p__11Block_Pname ) , (__0__X22 ?(((void )(((void
# 31 "/home/claude/cfront-3/src/block.cpp"
)0 )))):(((void )0 )))) )):(((void )0 )))) ) ;

# 31 "/home/claude/cfront-3/src/block.cpp"
}

# 21 "/home/claude/cfront-3/src/block.cpp"
static void __dt__11Block_PnameFv (struct Block_Pname *__0this , 
# 21 "/home/claude/cfront-3/src/block.cpp"
int __0__free ){ 
# 21 "/home/claude/cfront-3/src/block.cpp"
if (__0this ){ __dl__FPv ( (void *)__0this -> p__11Block_Pname ) ;

# 21 "/home/claude/cfront-3/src/block.cpp"
if (__0this )if (__0__free & 1)__dl__FPv ( (void *)__0this ) ;
} 
# 21 "/home/claude/cfront-3/src/block.cpp"
}

# 21 "/home/claude/cfront-3/src/block.cpp"
static struct Block_Pname *__ct__11Block_PnameFv (struct Block_Pname *__0this ){ if (__0this || (__0this = (struct Block_Pname *)__nw__FUl ( (unsigned long )(sizeof (struct Block_Pname)))
# 21 "/home/claude/cfront-3/src/block.cpp"
)){ __0this -> n__11Block_Pname = 0 ;

# 21 "/home/claude/cfront-3/src/block.cpp"
__0this -> p__11Block_Pname = 0 ;
} 
# 21 "/home/claude/cfront-3/src/block.cpp"
return __0this ;

# 21 "/home/claude/cfront-3/src/block.cpp"
}

# 1008 "/home/claude/cfront-3/src/cfront.h"
extern Pstmt stmt_free__4stmt;

# 930 "/home/claude/cfront-3/src/cfront.h"
extern Pname name_free__4name;

# 790 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr expr_free__4expr;

# 704 "/home/claude/cfront-3/src/cfront.h"
extern Pptr ptr_free__3ptr;

# 689 "/home/claude/cfront-3/src/cfront.h"
extern Pvec vec_free__3vec;

# 629 "/home/claude/cfront-3/src/cfront.h"
extern Pfct fct_free__3fct;

# 256 "/home/claude/cfront-3/src/cfront.h"
extern Pktab table_free__6ktable;

# 216 "/home/claude/cfront-3/src/cfront.h"
extern Ptable table_free__5table;

# 34 "/home/claude/cfront-3/src/block.cpp"

/* the end */
