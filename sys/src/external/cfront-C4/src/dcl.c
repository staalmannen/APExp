# 1 ""

/* <<AT&T C++ Language System <3.0.3> 05/05/94>> */

# 1 ""
void *__vec_new (void *, int , int , void *);

# 1 ""
void __vec_delete (void *, int , int , void *, int , int );
typedef int (*__vptp)(void);
struct __mptr {short d; short i; __vptp f; };

# 1 ""
extern struct __mptr* __ptbl_vec___[];

# 1 ""

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
extern void *__nw__FUl (size_t );

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
if (__0this || (__0this = (struct ptr *)__nw__3ptrSFUl ( (size_t )(sizeof (struct ptr))) )){ __0this = (struct ptr *)( (__0__X8 =
# 708 "/home/claude/cfront-3/src/cfront.h"
(((struct pvtyp *)__0this ))), ( ((__0__X8 || (__0__X8 = (struct pvtyp *)__nw__FUl ( (size_t )(sizeof (struct pvtyp))) ))?(__0__X8 = (struct pvtyp *)(
# 708 "/home/claude/cfront-3/src/cfront.h"
(__0__X6 = (((struct type *)__0__X8 ))), ( ((__0__X6 || (__0__X6 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type))) ))?( (
# 708 "/home/claude/cfront-3/src/cfront.h"
( ( ( ( ( ( (__0__X6 = (struct type *)( (__0__X1 = (((struct node *)__0__X6 ))), ( ((__0__X1 ||
# 708 "/home/claude/cfront-3/src/cfront.h"
(__0__X1 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 -> permanent__4node =
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

# 23 "/home/claude/cfront-3/src/size.h"
extern int BI_IN_WORD ;
extern int BI_IN_BYTE ;

# 26 "/home/claude/cfront-3/src/size.h"
extern int SZ_CHAR ;
extern int AL_CHAR ;

# 29 "/home/claude/cfront-3/src/size.h"
extern int SZ_SHORT ;
extern int AL_SHORT ;

# 32 "/home/claude/cfront-3/src/size.h"
extern int SZ_INT ;
extern int AL_INT ;

# 35 "/home/claude/cfront-3/src/size.h"
extern int SZ_LONG ;
extern int AL_LONG ;

# 38 "/home/claude/cfront-3/src/size.h"
extern int SZ_LLONG ;
extern int AL_LLONG ;

# 41 "/home/claude/cfront-3/src/size.h"
extern int SZ_FLOAT ;
extern int AL_FLOAT ;

# 44 "/home/claude/cfront-3/src/size.h"
extern int SZ_DOUBLE ;
extern int AL_DOUBLE ;

# 47 "/home/claude/cfront-3/src/size.h"
extern int SZ_LDOUBLE ;
extern int AL_LDOUBLE ;

# 50 "/home/claude/cfront-3/src/size.h"
extern int SZ_STRUCT ;
extern int AL_STRUCT ;

# 56 "/home/claude/cfront-3/src/size.h"
extern int SZ_WORD ;

# 58 "/home/claude/cfront-3/src/size.h"
extern int SZ_WPTR ;
extern int AL_WPTR ;

# 61 "/home/claude/cfront-3/src/size.h"
extern int SZ_BPTR ;
extern int AL_BPTR ;

# 67 "/home/claude/cfront-3/src/size.h"
extern const char *LARGEST_INT ;

# 67 "/home/claude/cfront-3/src/size.h"
extern const char *LARGEST_LONG ;

# 67 "/home/claude/cfront-3/src/size.h"
extern const char *LARGEST_LLONG ;
extern int F_SENSITIVE ;
extern int F_OPTIMIZED ;

# 82 "/home/claude/cfront-3/src/size.h"
enum bool { false = 0, true = 1} ;

# 26 "/home/claude/cfront-3/src/template.h"
extern Pclass current_instantiation ;
extern Pfct current_fct_instantiation ;
struct templ;

# 30 "/home/claude/cfront-3/src/template.h"
typedef struct templ *Ptempl ;
struct funct_inst;
typedef struct funct_inst *Pfunct_inst ;
struct templ_inst;
typedef struct templ_inst *Ptempl_inst ;
struct basic_inst;
typedef struct basic_inst *Pbase_inst ;
struct function_template;

# 35 "/home/claude/cfront-3/src/template.h"
typedef struct function_template *Pfunt ;
struct data_template;
typedef struct data_template *Pdata ;
struct templ_state;
typedef struct templ_state *Ptstate ;
struct templ_classdef;
typedef struct templ_classdef *Ptclass ;
struct templ_fct;
typedef struct templ_fct *Ptfct ;
struct Pslot;
typedef struct Pslot *Pbinding ;

# 43 "/home/claude/cfront-3/src/template.h"
struct cons {	/* sizeof cons == 16 */

# 48 "/home/claude/cfront-3/src/template.h"
void *car__4cons ;
struct cons *cdr__4cons ;
};
struct templ_compilation;

# 158 "/home/claude/cfront-3/src/template.h"
extern struct templ_compilation *templp ;

# 167 "/home/claude/cfront-3/src/template.h"
struct basic_template {	/* sizeof basic_template == 48 */

# 173 "/home/claude/cfront-3/src/template.h"
Plist formals__14basic_template ;
Pcons templ_refs__14basic_template ;

# 178 "/home/claude/cfront-3/src/template.h"
Pname Cdcl__14basic_template ;
Pstmt Cstmt__14basic_template ;

# 183 "/home/claude/cfront-3/src/template.h"
int open_instantiations__14basic_template ;
int extrapolated__14basic_template ;

# 196 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__14basic_template ;
};
struct templ {	/* sizeof templ == 128 */

# 173 "/home/claude/cfront-3/src/template.h"
Plist formals__14basic_template ;
Pcons templ_refs__14basic_template ;

# 178 "/home/claude/cfront-3/src/template.h"
Pname Cdcl__14basic_template ;
Pstmt Cstmt__14basic_template ;

# 183 "/home/claude/cfront-3/src/template.h"
int open_instantiations__14basic_template ;
int extrapolated__14basic_template ;

# 196 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__14basic_template ;

# 206 "/home/claude/cfront-3/src/template.h"
Ptempl_inst insts__5templ ;
Pbase basep__5templ ;
Pfunt fns__5templ ;
Pfunt fns_end__5templ ;
Pdata data__5templ ;
Pdata data_end__5templ ;

# 215 "/home/claude/cfront-3/src/template.h"
Ptempl next__5templ ;
Pname namep__5templ ;
int defined__5templ ;
Pname members__5templ ;
};

# 236 "/home/claude/cfront-3/src/template.h"
struct function_template {	/* sizeof function_template == 80 */

# 173 "/home/claude/cfront-3/src/template.h"
Plist formals__14basic_template ;
Pcons templ_refs__14basic_template ;

# 178 "/home/claude/cfront-3/src/template.h"
Pname Cdcl__14basic_template ;
Pstmt Cstmt__14basic_template ;

# 183 "/home/claude/cfront-3/src/template.h"
int open_instantiations__14basic_template ;
int extrapolated__14basic_template ;

# 196 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__14basic_template ;

# 247 "/home/claude/cfront-3/src/template.h"
Pname fn__17function_template ;
Pfunt next__17function_template ;
Pfunt gen_list__17function_template ;

# 251 "/home/claude/cfront-3/src/template.h"
Pfunct_inst insts__17function_template ;
};
struct state;

# 280 "/home/claude/cfront-3/src/template.h"
struct state {	/* sizeof state == 88 */

# 282 "/home/claude/cfront-3/src/template.h"
Pname Cdcl__5state ;
Pstmt Cstmt__5state ;
Pname dcl_list__5state ;
struct loc curloc__5state ;

# 287 "/home/claude/cfront-3/src/template.h"
int curr_file__5state ;
Pexpr curr_expr__5state ;
Pin curr_icall__5state ;
Pstmt curr_loop__5state ;
Pblock curr_block__5state ;
Pstmt curr_switch__5state ;

# 294 "/home/claude/cfront-3/src/template.h"
int bound__5state ;
int inline_restr__5state ;
struct loc last_line__5state ;
};
struct pointer_hash;
struct tree_copy_info;
enum inst_status { uninstantiated = 0, function_instantiated = 1, data_instantiated = 2, class_instantiated = 3, body_instantiated = 4} ;
struct template_instantiation;

# 318 "/home/claude/cfront-3/src/template.h"
struct basic_inst {	/* sizeof basic_inst == 168 */

# 332 "/home/claude/cfront-3/src/template.h"
Pexpr actuals__10basic_inst ;

# 335 "/home/claude/cfront-3/src/template.h"
Plist inst_formals__10basic_inst ;

# 338 "/home/claude/cfront-3/src/template.h"
TOK isa__10basic_inst ;
Pname tname__10basic_inst ;
Pname namep__10basic_inst ;
struct state context__10basic_inst ;
Plist hidden_globals__10basic_inst ;

# 344 "/home/claude/cfront-3/src/template.h"
int status__10basic_inst ;
Pbase_inst next_active__10basic_inst ;

# 352 "/home/claude/cfront-3/src/template.h"
struct pointer_hash *corr__10basic_inst ;

# 364 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__10basic_inst ;
};

# 336 "/home/claude/cfront-3/src/template.h"
extern Pbase_inst head__10basic_inst ;

# 298 "/home/claude/cfront-3/src/template.h"

# 393 "/home/claude/cfront-3/src/template.h"
struct templ_inst {	/* sizeof templ_inst == 200 */

# 332 "/home/claude/cfront-3/src/template.h"
Pexpr actuals__10basic_inst ;

# 335 "/home/claude/cfront-3/src/template.h"
Plist inst_formals__10basic_inst ;

# 338 "/home/claude/cfront-3/src/template.h"
TOK isa__10basic_inst ;
Pname tname__10basic_inst ;
Pname namep__10basic_inst ;
struct state context__10basic_inst ;
Plist hidden_globals__10basic_inst ;

# 344 "/home/claude/cfront-3/src/template.h"
int status__10basic_inst ;
Pbase_inst next_active__10basic_inst ;

# 352 "/home/claude/cfront-3/src/template.h"
struct pointer_hash *corr__10basic_inst ;

# 364 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__10basic_inst ;

# 400 "/home/claude/cfront-3/src/template.h"
Ptempl_inst next__10templ_inst ;
Ptempl_inst forward__10templ_inst ;

# 417 "/home/claude/cfront-3/src/template.h"
Ptempl def__10templ_inst ;

# 419 "/home/claude/cfront-3/src/template.h"
int refp__10templ_inst ;

# 422 "/home/claude/cfront-3/src/template.h"
int friend_refp__10templ_inst ;
};

# 456 "/home/claude/cfront-3/src/template.h"
extern int zdebug ;

# 463 "/home/claude/cfront-3/src/template.h"
struct templ_classdef {	/* sizeof templ_classdef == 248 */

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

# 467 "/home/claude/cfront-3/src/template.h"
Ptempl_inst inst__14templ_classdef ;
};

# 444 "/home/claude/cfront-3/src/cfront.h"
void __dt__8classdefFv (struct classdef *__0this , int );

# 1 ""
extern void __dl__FPv (void *);

# 478 "/home/claude/cfront-3/src/template.h"
void *__nw__9templ_fctSFUl (size_t );
void __dl__9templ_fctSFPvUl (void *, size_t );

# 473 "/home/claude/cfront-3/src/template.h"
struct templ_fct {	/* sizeof templ_fct == 216 */

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

# 475 "/home/claude/cfront-3/src/template.h"
Pfunct_inst inst__9templ_fct ;
};

# 480 "/home/claude/cfront-3/src/template.h"
extern Ptfct ptfct_free__9templ_fct ;

# 371 "/home/claude/cfront-3/src/template.h"
struct funct_inst {	/* sizeof funct_inst == 200 */

# 332 "/home/claude/cfront-3/src/template.h"
Pexpr actuals__10basic_inst ;

# 335 "/home/claude/cfront-3/src/template.h"
Plist inst_formals__10basic_inst ;

# 338 "/home/claude/cfront-3/src/template.h"
TOK isa__10basic_inst ;
Pname tname__10basic_inst ;
Pname namep__10basic_inst ;
struct state context__10basic_inst ;
Plist hidden_globals__10basic_inst ;

# 344 "/home/claude/cfront-3/src/template.h"
int status__10basic_inst ;
Pbase_inst next_active__10basic_inst ;

# 352 "/home/claude/cfront-3/src/template.h"
struct pointer_hash *corr__10basic_inst ;

# 364 "/home/claude/cfront-3/src/template.h"
struct __mptr *__vptr__10basic_inst ;

# 376 "/home/claude/cfront-3/src/template.h"
Pfunct_inst next__10funct_inst ;

# 386 "/home/claude/cfront-3/src/template.h"
Pfunt def__10funct_inst ;
int refp__10funct_inst ;
int friend_refp__10funct_inst ;
Pbinding binding__10funct_inst ;
};

# 652 "/home/claude/cfront-3/src/cfront.h"

#pragma lib "ape/libap.a"

#pragma lib "c++/libC.a"

# 20 "/home/claude/incl-linux32/generic.h"
typedef int (*GPT )(int , char *);
struct Block_CPchar;

# 491 "/home/claude/cfront-3/src/template.h"
struct Block_CPchar {	/* sizeof Block_CPchar == 16 */

# 491 "/home/claude/cfront-3/src/template.h"
CPchar *p__12Block_CPchar ;

# 491 "/home/claude/cfront-3/src/template.h"
size_t n__12Block_CPchar ;
};

# 491 "/home/claude/cfront-3/src/template.h"
void move__12Block_CPcharFPPCcUl (struct Block_CPchar *__0this , CPchar *, size_t );

# 491 "/home/claude/cfront-3/src/template.h"
void copy__12Block_CPcharFRC12Block_CPchar (struct Block_CPchar *__0this , const struct Block_CPchar *);

# 491 "/home/claude/cfront-3/src/template.h"
size_t grow__12Block_CPcharFUl (struct Block_CPchar *__0this , size_t );
struct Block_Pchar;
struct Block_Pchar {	/* sizeof Block_Pchar == 16 */

# 492 "/home/claude/cfront-3/src/template.h"
Pchar *p__11Block_Pchar ;

# 492 "/home/claude/cfront-3/src/template.h"
size_t n__11Block_Pchar ;
};

# 492 "/home/claude/cfront-3/src/template.h"
void move__11Block_PcharFPPcUl (struct Block_Pchar *__0this , Pchar *, size_t );

# 492 "/home/claude/cfront-3/src/template.h"
void copy__11Block_PcharFRC11Block_Pchar (struct Block_Pchar *__0this , const struct Block_Pchar *);

# 492 "/home/claude/cfront-3/src/template.h"
size_t grow__11Block_PcharFUl (struct Block_Pchar *__0this , size_t );
extern struct Block_Pchar instfct ;
extern int noinst ;
extern struct Block_Pchar instdata ;
extern int nodatainst ;
extern bit tempdcl ;
extern bit mk_zero_init_flag ;
extern int first_file ;
extern bit all_flag ;

# 500 "/home/claude/cfront-3/src/template.h"
extern bit alltc_flag ;

# 500 "/home/claude/cfront-3/src/template.h"
extern bit data_flag ;

# 500 "/home/claude/cfront-3/src/template.h"
extern bit ft_flag ;

# 500 "/home/claude/cfront-3/src/template.h"
extern bit none_flag ;

# 502 "/home/claude/cfront-3/src/template.h"
extern Pname righttname ;

# 32 "/home/claude/cfront-3/src/dcl.cpp"
struct dcl_context ccvec [100];

# 32 "/home/claude/cfront-3/src/dcl.cpp"
struct dcl_context *cc = (struct dcl_context *)ccvec ;
struct dcl_context *ccvec_end = (& (ccvec [100 ]));
int byte_offset = 0 ;
int bit_offset = 0 ;
int max_align = 0 ;
int friend_in_class = 0 ;
extern int no_const ;
static Pstmt itail ;

# 45 "/home/claude/cfront-3/src/dcl.cpp"
static bit check_static_pt__FP4name (Pname __1n )
# 46 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 47 "/home/claude/cfront-3/src/dcl.cpp"
if (! dtpt_opt )
# 48 "/home/claude/cfront-3/src/dcl.cpp"
return (unsigned char )1 ;
if (all_flag )
# 50 "/home/claude/cfront-3/src/dcl.cpp"
return (unsigned char )1 ;
if (none_flag )
# 52 "/home/claude/cfront-3/src/dcl.cpp"
return (unsigned char )1 ;
if ((__1n -> n_stclass__4name == 2 )|| (__1n -> n_stclass__4name == 27 ))
# 54 "/home/claude/cfront-3/src/dcl.cpp"
return (unsigned char )1 ;
if (__1n -> n_sto__4name == 31 )
# 56 "/home/claude/cfront-3/src/dcl.cpp"
return (unsigned char )1 ;
if (curloc . file__3loc != first_file )
# 58 "/home/claude/cfront-3/src/dcl.cpp"
return (unsigned char )0 ;

# 60 "/home/claude/cfront-3/src/dcl.cpp"
return (unsigned char )1 ;
}

# 230 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 63 "/home/claude/cfront-3/src/dcl.cpp"
static int is_empty__FP8classdefUc (Pclass __1cl , bit __1const_chk )
# 64 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 69 "/home/claude/cfront-3/src/dcl.cpp"
int __1mbr_cnt ;

# 70 "/home/claude/cfront-3/src/dcl.cpp"
struct table *__0__X29 ;

# 69 "/home/claude/cfront-3/src/dcl.cpp"
__1mbr_cnt = ( (__0__X29 = __1cl -> memtbl__8classdef ), ( (__0__X29 -> free_slot__5table - 1 )) ) ;

# 71 "/home/claude/cfront-3/src/dcl.cpp"
if (__1mbr_cnt == 0 )
# 72 "/home/claude/cfront-3/src/dcl.cpp"
return 1 ;
if ((__1cl -> baselist__8classdef == 0 )&& (__1cl -> real_size__8classdef != 1 ))
# 74 "/home/claude/cfront-3/src/dcl.cpp"
return 0 ;

# 77 "/home/claude/cfront-3/src/dcl.cpp"
if ((__1const_chk == 0 )&& ((__1cl -> baselist__8classdef != 0 )|| (__1mbr_cnt > 1 )))
# 82 "/home/claude/cfront-3/src/dcl.cpp"
return 0 ;

# 84 "/home/claude/cfront-3/src/dcl.cpp"
{ int __1i ;

# 84 "/home/claude/cfront-3/src/dcl.cpp"
__1i = 1 ;
{ { Pname __1nn ;

# 86 "/home/claude/cfront-3/src/dcl.cpp"
struct table *__0__X26 ;

# 86 "/home/claude/cfront-3/src/dcl.cpp"
int __2__X27 ;

# 86 "/home/claude/cfront-3/src/dcl.cpp"
struct table *__0__X28 ;

# 85 "/home/claude/cfront-3/src/dcl.cpp"
__1nn = ( (__0__X28 = __1cl -> memtbl__8classdef ), ( (((__1i <= 0 )|| (__0__X28 -> free_slot__5table <= __1i ))?(((struct name *)0 )):(__0__X28 -> entries__5table [__1i ]))) )
# 85 "/home/claude/cfront-3/src/dcl.cpp"
;

# 85 "/home/claude/cfront-3/src/dcl.cpp"
for(;__1nn ;__1nn = (__1nn -> n_tbl_list__4name ?__1nn -> n_tbl_list__4name :( (__0__X26 = __1cl -> memtbl__8classdef ), ( (__2__X27 = (++ __1i )), ( (((__2__X27 <= 0 )||
# 85 "/home/claude/cfront-3/src/dcl.cpp"
(__0__X26 -> free_slot__5table <= __2__X27 ))?(((struct name *)0 )):(__0__X26 -> entries__5table [__2__X27 ]))) ) ) )) { 
# 86 "/home/claude/cfront-3/src/dcl.cpp"
if ((((((((__1nn -> base__4node == 85 )&& (__1nn ->
# 86 "/home/claude/cfront-3/src/dcl.cpp"
n_anon__4name == 0 ))&& (__1nn -> __O1__4expr.tp -> base__4node != 108 ))&& (__1nn -> __O1__4expr.tp -> base__4node != 76 ))&& (__1nn -> __O1__4expr.tp -> base__4node != 6 ))&&
# 86 "/home/claude/cfront-3/src/dcl.cpp"
(__1nn -> __O1__4expr.tp -> base__4node != 13 ))&& (__1nn -> __O1__4expr.tp -> base__4node != 121 ))&& (__1nn -> n_stclass__4name != 31 ))
# 102 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 103 "/home/claude/cfront-3/src/dcl.cpp"
if ((((__1nn -> __O2__4expr.string [0 ])==
# 103 "/home/claude/cfront-3/src/dcl.cpp"
'_' )&& ((__1nn -> __O2__4expr.string [1 ])== '_' ))&& ((__1nn -> __O2__4expr.string [2 ])== 'W' ))
# 110 "/home/claude/cfront-3/src/dcl.cpp"
return 1 ;
else 
# 112 "/home/claude/cfront-3/src/dcl.cpp"
return 0 ;
}
}

# 116 "/home/claude/cfront-3/src/dcl.cpp"
return 1 ;

# 116 "/home/claude/cfront-3/src/dcl.cpp"
}

# 116 "/home/claude/cfront-3/src/dcl.cpp"
}

# 116 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 39 "/home/claude/cfront-3/src/cfront.h"
extern void make_dummy__Fv (void );

# 805 "/home/claude/cfront-3/src/cfront.h"
void simpl__4exprFv (struct expr *__0this );

# 119 "/home/claude/cfront-3/src/dcl.cpp"
void dosimpl__FP4exprP4name (Pexpr __1e , Pname __1n )
# 120 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 121 "/home/claude/cfront-3/src/dcl.cpp"
if (__1n == 0 ){ 
# 122 "/home/claude/cfront-3/src/dcl.cpp"
if (dummy_fct == 0 )
# 123 "/home/claude/cfront-3/src/dcl.cpp"
make_dummy__Fv ( ) ;
__1n = dummy_fct ;
}
{ Pname __1cf ;

# 126 "/home/claude/cfront-3/src/dcl.cpp"
__1cf = curr_fct ;
curr_fct = __1n ;
simpl__4exprFv ( __1e ) ;
curr_fct = __1cf ;

# 129 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 798 "/home/claude/cfront-3/src/cfront.h"
Pexpr typ__4exprFP5table (struct expr *__0this , Ptable );

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 470 "/home/claude/cfront-3/src/cfront.h"
Pname has_ictor__8classdefFv (struct classdef *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 132 "/home/claude/cfront-3/src/dcl.cpp"
static Pexpr co_array_init__FP4nameP5table (Pname __1n , Ptable __1tbl )
# 137 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 138 "/home/claude/cfront-3/src/dcl.cpp"
Pexpr __1init ;

# 138 "/home/claude/cfront-3/src/dcl.cpp"
__1init = __1n -> __O3__4expr.n_initializer ;

# 140 "/home/claude/cfront-3/src/dcl.cpp"
if (__1init -> base__4node != 124 ){ 
# 141 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 141 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V30 ;

# 141 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIr for array ofCOs%n", (const struct ea *)( ((& __0__V30 )-> __O1__2ea.p =
# 141 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__1n )), (& __0__V30 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 141 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
return (struct expr *)0 ;
} }

# 145 "/home/claude/cfront-3/src/dcl.cpp"
{ Pexpr __1el ;
Pvec __1v ;
Pname __1cn ;
Pclass __1cl ;
int __1i ;

# 151 "/home/claude/cfront-3/src/dcl.cpp"
int __1count ;
Pexpr __1il2 ;

# 145 "/home/claude/cfront-3/src/dcl.cpp"
__1el = 0 ;
__1v = (((struct vec *)(((struct vec *)skiptypedefs__4typeFv ( __1n -> __O1__4expr.tp ) ))));
__1cn = is_cl_obj__4typeFv ( __1v -> typ__5pvtyp ) ;
__1cl = (__1cn ?(((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp )))):(((struct classdef *)0 )));
__1i = __1v -> size__3vec ;

# 151 "/home/claude/cfront-3/src/dcl.cpp"
__1count = 0 ;

# 153 "/home/claude/cfront-3/src/dcl.cpp"
{ { Pexpr __1il ;

# 153 "/home/claude/cfront-3/src/dcl.cpp"
__1il = __1init -> __O2__4expr.e1 ;

# 153 "/home/claude/cfront-3/src/dcl.cpp"
for(;__1il ;__1il = __1il2 ) { 
# 157 "/home/claude/cfront-3/src/dcl.cpp"
Pexpr __2e ;

# 158 "/home/claude/cfront-3/src/dcl.cpp"
struct texpr *__0__X42 ;

# 158 "/home/claude/cfront-3/src/dcl.cpp"
struct ival *__0__X43 ;

# 158 "/home/claude/cfront-3/src/dcl.cpp"
long long __2__X44 ;

# 157 "/home/claude/cfront-3/src/dcl.cpp"
__2e = __1il -> __O2__4expr.e1 ;
__1il2 = __1il -> __O3__4expr.e2 ;
__1il -> __O3__4expr.e2 = 0 ;
if (__2e == dummy )
# 161 "/home/claude/cfront-3/src/dcl.cpp"
break ;
if (__2e -> base__4node == 157 ){ 
# 163 "/home/claude/cfront-3/src/dcl.cpp"
switch (__2e -> __O4__4expr.tp2 -> base__4node ){ 
# 163 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X36 ;

# 163 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X37 ;

# 163 "/home/claude/cfront-3/src/dcl.cpp"
struct texpr *__0__X38 ;

# 164 "/home/claude/cfront-3/src/dcl.cpp"
case 6 :
# 165 "/home/claude/cfront-3/src/dcl.cpp"
if (! ( (__1__X36 = (((struct classdef *)(((struct classdef *)__2e -> __O4__4expr.tp2 ))))), ( (__1__X37 = __1cl ), ( ((__1__X36 ==
# 165 "/home/claude/cfront-3/src/dcl.cpp"
__1__X37 )?1 :((__1__X36 && __1__X37 )?(((int )same_class__8classdefFP8classdefi ( __1__X36 , __1__X37 , 0 ) )):0 ))) ) ) )
# 166 "/home/claude/cfront-3/src/dcl.cpp"
__2e = (struct expr *)( (__0__X38 = 0 ),
# 166 "/home/claude/cfront-3/src/dcl.cpp"
( ((__0__X38 || (__0__X38 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X38 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct
# 166 "/home/claude/cfront-3/src/dcl.cpp"
expr *)__0__X38 ), ((unsigned char )157 ), __1il , (struct expr *)0 ) ), (__0__X38 -> __O4__4expr.tp2 = ((struct type *)__1cl ))) :0 ), __0__X38 )
# 166 "/home/claude/cfront-3/src/dcl.cpp"
) ;
break ;
default :
# 169 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 170 "/home/claude/cfront-3/src/dcl.cpp"
Pname __5n2 ;

# 171 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X39 ;

# 171 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X40 ;

# 171 "/home/claude/cfront-3/src/dcl.cpp"
struct texpr *__0__X41 ;

# 170 "/home/claude/cfront-3/src/dcl.cpp"
__5n2 = is_cl_obj__4typeFv ( __2e -> __O4__4expr.tp2 ) ;
if ((__5n2 == 0 )|| (! ( (__1__X39 = (((struct classdef *)(((struct classdef *)__5n2 -> __O1__4expr.tp ))))), ( (__1__X40 = __1cl ), (
# 171 "/home/claude/cfront-3/src/dcl.cpp"
((__1__X39 == __1__X40 )?1 :((__1__X39 && __1__X40 )?(((int )same_class__8classdefFP8classdefi ( __1__X39 , __1__X40 , 0 ) )):0 ))) ) ) ))
# 172 "/home/claude/cfront-3/src/dcl.cpp"
__2e = (struct expr *)( (__0__X41 =
# 172 "/home/claude/cfront-3/src/dcl.cpp"
0 ), ( ((__0__X41 || (__0__X41 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X41 = (struct texpr *)__ct__4exprFUcP4exprT2 (
# 172 "/home/claude/cfront-3/src/dcl.cpp"
((struct expr *)__0__X41 ), ((unsigned char )157 ), __1il , (struct expr *)0 ) ), (__0__X41 -> __O4__4expr.tp2 = ((struct type *)__1cl ))) :0 ),
# 172 "/home/claude/cfront-3/src/dcl.cpp"
__0__X41 ) ) ;
}
}
}
else 
# 177 "/home/claude/cfront-3/src/dcl.cpp"
__2e = (struct expr *)( (__0__X42 = 0 ), ( ((__0__X42 || (__0__X42 = (struct texpr *)__nw__4exprSFUl ( (size_t)(sizeof
# 177 "/home/claude/cfront-3/src/dcl.cpp"
(struct texpr))) ))?( (__0__X42 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X42 ), ((unsigned char )157 ), __1il , (struct expr *)0 ) ),
# 177 "/home/claude/cfront-3/src/dcl.cpp"
(__0__X42 -> __O4__4expr.tp2 = ((struct type *)__1cl ))) :0 ), __0__X42 ) ) ;
__2e -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , (struct expr *)__1n , (struct expr *)( (__0__X43 = 0 ),
# 178 "/home/claude/cfront-3/src/dcl.cpp"
( (__2__X44 = (__1count ++ )), ( ((__0__X43 || (__0__X43 = (struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival))) ))?(
# 178 "/home/claude/cfront-3/src/dcl.cpp"
(__0__X43 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X43 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 ) ), (__0__X43 ->
# 178 "/home/claude/cfront-3/src/dcl.cpp"
__O2__4expr.i1 = __2__X44 )) :0 ), __0__X43 ) ) ) ) ;
__2e = typ__4exprFP5table ( __2e , __1tbl ) ;
{ Ptable __2oscope ;

# 180 "/home/claude/cfront-3/src/dcl.cpp"
__2oscope = scope ;
scope = __1tbl ;
dosimpl__FP4exprP4name ( __2e , cc -> nof__11dcl_context ) ;
scope = __2oscope ;
if (sti_tbl == __1tbl ){ 
# 185 "/home/claude/cfront-3/src/dcl.cpp"
Pstmt __3ist ;

# 186 "/home/claude/cfront-3/src/dcl.cpp"
struct estmt *__0__X45 ;

# 186 "/home/claude/cfront-3/src/dcl.cpp"
struct loc __2__X46 ;

# 185 "/home/claude/cfront-3/src/dcl.cpp"
__3ist = (struct stmt *)( (__0__X45 = 0 ), ( (__2__X46 = no_where ), ( ((__0__X45 || (__0__X45 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 185 "/home/claude/cfront-3/src/dcl.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X45 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X45 ), ((unsigned char )72 ), __2__X46 , ((struct
# 185 "/home/claude/cfront-3/src/dcl.cpp"
stmt *)0 )) ), (__0__X45 -> __O2__4stmt.e = __2e )) :0 ), __0__X45 ) ) ) ;
if (st_ilist == 0 )
# 187 "/home/claude/cfront-3/src/dcl.cpp"
st_ilist = __3ist ;
else 
# 189 "/home/claude/cfront-3/src/dcl.cpp"
itail -> s_list__4stmt = __3ist ;
itail = __3ist ;
}
else { 
# 199 "/home/claude/cfront-3/src/dcl.cpp"
__1el = (__1el ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __1el , __2e ) :__2e );
}

# 200 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 203 "/home/claude/cfront-3/src/dcl.cpp"
if (__1i == 0 )
# 204 "/home/claude/cfront-3/src/dcl.cpp"
__1v -> size__3vec = __1count ;
else if (__1i < __1count ){ 
# 206 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 206 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V31 ;

# 206 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V32 ;

# 206 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"too manyIrs for%n (%d)", (const struct ea *)( ((& __0__V31 )-> __O1__2ea.p =
# 206 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__1n )), (& __0__V31 )) , (const struct ea *)( (( ((& __0__V32 )-> __O1__2ea.i = ((unsigned
# 206 "/home/claude/cfront-3/src/dcl.cpp"
long )__1count )), 0 ) ), (& __0__V32 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 206 "/home/claude/cfront-3/src/dcl.cpp"

# 207 "/home/claude/cfront-3/src/dcl.cpp"
return (struct expr *)0 ;
} }
else if (__1i > __1count ){ 
# 210 "/home/claude/cfront-3/src/dcl.cpp"
if (has_ictor__8classdefFv ( __1cl ) )
# 211 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 211 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V33 ;

# 211 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"too fewIrs for%n", (const struct ea *)( ((&
# 211 "/home/claude/cfront-3/src/dcl.cpp"
__0__V33 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V33 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 211 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 ) ;
} else 
# 213 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 213 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V34 ;

# 213 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V35 ;

# 213 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"too fewIrs for%n (C %srequires a defaultK)", (const struct ea *)( ((& __0__V34 )-> __O1__2ea.p =
# 213 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__1n )), (& __0__V34 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V35 , (const void *)__1cl ->
# 213 "/home/claude/cfront-3/src/dcl.cpp"
string__8classdef ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} return (struct expr *)0 ;
}
return __1el ;

# 216 "/home/claude/cfront-3/src/dcl.cpp"
}

# 216 "/home/claude/cfront-3/src/dcl.cpp"
}

# 216 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 219 "/home/claude/cfront-3/src/dcl.cpp"
int need_sti__FP4exprP5tableUc (Pexpr __1e , Ptable __1tbl , bit __1accept_name );

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 799 "/home/claude/cfront-3/src/cfront.h"
long long eval__4exprFv (struct expr *__0this );

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 219 "/home/claude/cfront-3/src/dcl.cpp"
int need_sti__FP4exprP5tableUc (Pexpr __1e , Ptable __1tbl , bit __1accept_name )
# 224 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 225 "/home/claude/cfront-3/src/dcl.cpp"
if (__1e == 0 )
# 226 "/home/claude/cfront-3/src/dcl.cpp"
return 0 ;

# 228 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1e -> base__4node ){ 
# 229 "/home/claude/cfront-3/src/dcl.cpp"
case 68 :
# 230 "/home/claude/cfront-3/src/dcl.cpp"
if (need_sti__FP4exprP5tableUc ( __1e -> __O4__4expr.cond , __1tbl , (unsigned char )0 ) && (__1tbl ==
# 230 "/home/claude/cfront-3/src/dcl.cpp"
0 ))
# 231 "/home/claude/cfront-3/src/dcl.cpp"
return 1 ;
case 54 :
# 233 "/home/claude/cfront-3/src/dcl.cpp"
case 55 :
# 234 "/home/claude/cfront-3/src/dcl.cpp"
case 50 :
# 235 "/home/claude/cfront-3/src/dcl.cpp"
case 51 :
# 236 "/home/claude/cfront-3/src/dcl.cpp"
case 53 :
# 237 "/home/claude/cfront-3/src/dcl.cpp"
case 64 :
# 238 "/home/claude/cfront-3/src/dcl.cpp"
case 65 :
# 239 "/home/claude/cfront-3/src/dcl.cpp"
case 66 :
# 240 "/home/claude/cfront-3/src/dcl.cpp"
case 67 :
# 241 "/home/claude/cfront-3/src/dcl.cpp"
case 56 :
# 242 "/home/claude/cfront-3/src/dcl.cpp"
case 57 :
# 243 "/home/claude/cfront-3/src/dcl.cpp"
case 62 :
# 244 "/home/claude/cfront-3/src/dcl.cpp"
case 63 :
# 245 "/home/claude/cfront-3/src/dcl.cpp"
case
# 245 "/home/claude/cfront-3/src/dcl.cpp"
58 :
# 246 "/home/claude/cfront-3/src/dcl.cpp"
case 59 :
# 247 "/home/claude/cfront-3/src/dcl.cpp"
case 60 :
# 248 "/home/claude/cfront-3/src/dcl.cpp"
case 61 :
# 249 "/home/claude/cfront-3/src/dcl.cpp"
case 48 :
# 250 "/home/claude/cfront-3/src/dcl.cpp"
case 49 :
# 251 "/home/claude/cfront-3/src/dcl.cpp"
case 70 :
# 252 "/home/claude/cfront-3/src/dcl.cpp"
if (need_sti__FP4exprP5tableUc ( __1e -> __O2__4expr.e1 , __1tbl , __1accept_name ) && (__1tbl ==
# 252 "/home/claude/cfront-3/src/dcl.cpp"
0 ))
# 253 "/home/claude/cfront-3/src/dcl.cpp"
return 1 ;

# 256 "/home/claude/cfront-3/src/dcl.cpp"
case 107 :
# 257 "/home/claude/cfront-3/src/dcl.cpp"
case 172 :
# 258 "/home/claude/cfront-3/src/dcl.cpp"
case 46 :
# 259 "/home/claude/cfront-3/src/dcl.cpp"
case 47 :
# 260 "/home/claude/cfront-3/src/dcl.cpp"
if (need_sti__FP4exprP5tableUc ( __1e -> __O3__4expr.e2 , __1tbl , __1accept_name ) && (__1tbl == 0 ))
# 261 "/home/claude/cfront-3/src/dcl.cpp"
return 1 ;
# 261 "/home/claude/cfront-3/src/dcl.cpp"

# 264 "/home/claude/cfront-3/src/dcl.cpp"
case 30 :
# 265 "/home/claude/cfront-3/src/dcl.cpp"
default :
# 266 "/home/claude/cfront-3/src/dcl.cpp"
return 0 ;

# 268 "/home/claude/cfront-3/src/dcl.cpp"
case 113 :
# 269 "/home/claude/cfront-3/src/dcl.cpp"
case 191 :
# 270 "/home/claude/cfront-3/src/dcl.cpp"
return need_sti__FP4exprP5tableUc ( __1e -> __O2__4expr.e1 , __1tbl , __1accept_name ) ;

# 272 "/home/claude/cfront-3/src/dcl.cpp"
case 112 :
# 273 "/home/claude/cfront-3/src/dcl.cpp"
return need_sti__FP4exprP5tableUc ( __1e -> __O3__4expr.e2 , __1tbl , (unsigned char )1 ) ;

# 275 "/home/claude/cfront-3/src/dcl.cpp"
case 85 :
# 276 "/home/claude/cfront-3/src/dcl.cpp"
if (__1accept_name && ((((struct name *)(((struct name *)__1e ))))-> n_stclass__4name == 31 ))
# 277 "/home/claude/cfront-3/src/dcl.cpp"
return 0 ;

# 279 "/home/claude/cfront-3/src/dcl.cpp"
if (tconst__4typeFv ( __1e -> __O1__4expr.tp ) ){ 
# 280 "/home/claude/cfront-3/src/dcl.cpp"
if (vec_const || fct_const )
# 281 "/home/claude/cfront-3/src/dcl.cpp"
return 0 ;
Neval = 0 ;
eval__4exprFv ( __1e ) ;
if (Neval == 0 )
# 285 "/home/claude/cfront-3/src/dcl.cpp"
return 0 ;
}
return 1 ;

# 289 "/home/claude/cfront-3/src/dcl.cpp"
case 111 :
# 290 "/home/claude/cfront-3/src/dcl.cpp"
case 44 :
# 291 "/home/claude/cfront-3/src/dcl.cpp"
case 45 :
# 292 "/home/claude/cfront-3/src/dcl.cpp"
if (__1accept_name || (__1e -> __O1__4expr.tp && (__1e -> __O1__4expr.tp -> base__4node == 110 ))){ 
# 293 "/home/claude/cfront-3/src/dcl.cpp"
int __3x1 ;
int __3x2 ;

# 293 "/home/claude/cfront-3/src/dcl.cpp"
__3x1 = need_sti__FP4exprP5tableUc ( __1e -> __O2__4expr.e1 , __1tbl , (unsigned char )(__1e -> base__4node == 45 )) ;
__3x2 = need_sti__FP4exprP5tableUc ( __1e -> __O3__4expr.e2 , __1tbl , (unsigned char )0 ) ;
return (__3x1 || __3x2 );
}

# 299 "/home/claude/cfront-3/src/dcl.cpp"
case 140 :
# 300 "/home/claude/cfront-3/src/dcl.cpp"
case 147 :
# 301 "/home/claude/cfront-3/src/dcl.cpp"
case 71 :
# 302 "/home/claude/cfront-3/src/dcl.cpp"
if (__1e -> base__4node == 71 ){ 
# 303 "/home/claude/cfront-3/src/dcl.cpp"
if (need_sti__FP4exprP5tableUc ( __1e -> __O2__4expr.e1 , __1tbl , (unsigned char
# 303 "/home/claude/cfront-3/src/dcl.cpp"
)0 ) || need_sti__FP4exprP5tableUc ( __1e -> __O3__4expr.e2 , __1tbl , (unsigned char )0 ) )
# 304 "/home/claude/cfront-3/src/dcl.cpp"
return 1 ;
else 
# 306 "/home/claude/cfront-3/src/dcl.cpp"
return 0 ;
}

# 309 "/home/claude/cfront-3/src/dcl.cpp"
case 109 :
# 310 "/home/claude/cfront-3/src/dcl.cpp"
case 146 :
# 311 "/home/claude/cfront-3/src/dcl.cpp"
case 23 :
# 312 "/home/claude/cfront-3/src/dcl.cpp"
case 184 :
# 313 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 314 "/home/claude/cfront-3/src/dcl.cpp"
if (__1tbl ){ 
# 315 "/home/claude/cfront-3/src/dcl.cpp"
need_sti__FP4exprP5tableUc ( __1e -> __O2__4expr.e1 , __1tbl , __1accept_name ) ;
need_sti__FP4exprP5tableUc ( __1e -> __O3__4expr.e2 , __1tbl , __1accept_name ) ;
if (((__1e -> __O1__4expr.tp && (__1e -> __O1__4expr.tp -> base__4node == 110 ))&& (__1e -> base__4node == 23 ))|| (__1e -> base__4node == 184 ))
# 322 "/home/claude/cfront-3/src/dcl.cpp"
need_sti__FP4exprP5tableUc ( (((struct
# 322 "/home/claude/cfront-3/src/dcl.cpp"
vec *)(((struct vec *)__1e -> __O1__4expr.tp ))))-> dim__3vec , __1tbl , (unsigned char )0 ) ;
}
else if (__1e -> base__4node == 0 )
# 325 "/home/claude/cfront-3/src/dcl.cpp"
return 0 ;

# 327 "/home/claude/cfront-3/src/dcl.cpp"
case 168 :
# 328 "/home/claude/cfront-3/src/dcl.cpp"
return 1 ;
case 82 :
# 330 "/home/claude/cfront-3/src/dcl.cpp"
case 81 :
# 331 "/home/claude/cfront-3/src/dcl.cpp"
case 84 :
# 332 "/home/claude/cfront-3/src/dcl.cpp"
case 83 :
# 333 "/home/claude/cfront-3/src/dcl.cpp"
if (__1tbl ){ 
# 334 "/home/claude/cfront-3/src/dcl.cpp"
char *__3p ;

# 334 "/home/claude/cfront-3/src/dcl.cpp"
__3p = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* (strlen ( __1e -> __O2__4expr.string ) + 1 ))) ));
# 334 "/home/claude/cfront-3/src/dcl.cpp"

# 335 "/home/claude/cfront-3/src/dcl.cpp"
strcpy ( __3p , __1e -> __O2__4expr.string ) ;
__1e -> __O2__4expr.string = (const char *)__3p ;
}
return 0 ;
}
}

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 342 "/home/claude/cfront-3/src/dcl.cpp"
static void check_def_name__FP4namei (Pname __1nn , int __1scope )
# 343 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 344 "/home/claude/cfront-3/src/dcl.cpp"
Pfct __1f ;

# 344 "/home/claude/cfront-3/src/dcl.cpp"
__1f = (((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))));
if (((((((((def_name == 0 )&& (pdef_name == 0 ))&& (friend_in_class == 0 ))&& (__1scope == 14 ))&& (__1nn -> n_scope__4name != 31 ))&& (__1nn -> n_oper__4name !=
# 345 "/home/claude/cfront-3/src/dcl.cpp"
23 ))&& (__1nn -> n_oper__4name != 213 ))&& (__1nn -> n_oper__4name != 9 ))&& (__1nn -> n_oper__4name != 212 ))
# 363 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 364 "/home/claude/cfront-3/src/dcl.cpp"
if ((__1f -> body__3fct && (__1f ->
# 364 "/home/claude/cfront-3/src/dcl.cpp"
f_inline__3fct == 0 ))&& (__1f -> f_imeasure__3fct == 0 ))
# 370 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 371 "/home/claude/cfront-3/src/dcl.cpp"
pdef_name = (def_name = __1nn );
def_name = 0 ;
}
}

# 376 "/home/claude/cfront-3/src/dcl.cpp"
if (((strcmp ( __1nn -> __O2__4expr.string , (const char *)"main") == 0 )&& (__1nn ->
# 376 "/home/claude/cfront-3/src/dcl.cpp"
__O4__4expr.n_table == gtbl ))&& __1f -> f_inline__3fct )
# 382 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 384 "/home/claude/cfront-3/src/dcl.cpp"
pdef_name = (def_name = __1nn );
def_name = 0 ;
}
}

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 234 "/home/claude/cfront-3/src/cfront.h"

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 390 "/home/claude/cfront-3/src/dcl.cpp"
static void export_anon__FP4nameP8classdefP5table (Pname __1un , Pclass __1cl , Ptable __1tbl )
# 391 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 392 "/home/claude/cfront-3/src/dcl.cpp"
if (__1tbl == gtbl ){ 
# 393 "/home/claude/cfront-3/src/dcl.cpp"
if (__1un -> n_sto__4name != 31 )
# 394 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCc ( (const char
# 394 "/home/claude/cfront-3/src/dcl.cpp"
*)"extern anonymous union (declare as static)") ;
}
else if (__1tbl -> t_name__5table && (__1un -> n_sto__4name == 31 ))
# 397 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCc ( (int )'s' , (const char *)"staticM anonymous union")
# 397 "/home/claude/cfront-3/src/dcl.cpp"
;

# 399 "/home/claude/cfront-3/src/dcl.cpp"
(((struct basetype *)(((struct basetype *)__1un -> __O1__4expr.tp ))))-> b_name__8basetype -> n_used__4name = 1 ;
(((struct basetype *)(((struct basetype *)__1un -> __O1__4expr.tp ))))-> b_name__8basetype -> n_assigned_to__4name = 1 ;
{ Ptable __1mtbl ;
Ptable __1realtbl ;
int __1i ;

# 401 "/home/claude/cfront-3/src/dcl.cpp"
__1mtbl = __1cl -> memtbl__8classdef ;
__1realtbl = (((__1tbl == gtbl )|| __1tbl -> t_name__5table )?__1tbl :curr_block -> memtbl__4stmt );

# 404 "/home/claude/cfront-3/src/dcl.cpp"
{ { Pname __1nn ;

# 405 "/home/claude/cfront-3/src/dcl.cpp"
int __2__X50 ;

# 405 "/home/claude/cfront-3/src/dcl.cpp"
int __2__X53 ;

# 404 "/home/claude/cfront-3/src/dcl.cpp"
__1nn = ( (__2__X53 = (__1i = 1 )), ( (((__2__X53 <= 0 )|| (__1mtbl -> free_slot__5table <= __2__X53 ))?(((struct name *)0 )):(__1mtbl -> entries__5table [__2__X53 ]))) )
# 404 "/home/claude/cfront-3/src/dcl.cpp"
;

# 404 "/home/claude/cfront-3/src/dcl.cpp"
for(;__1nn ;__1nn = (__1nn -> n_tbl_list__4name ?__1nn -> n_tbl_list__4name :( (__2__X50 = (++ __1i )), ( (((__2__X50 <= 0 )|| (__1mtbl -> free_slot__5table <= __2__X50 ))?(((struct name *)0 )):(__1mtbl ->
# 404 "/home/claude/cfront-3/src/dcl.cpp"
entries__5table [__2__X50 ]))) ) )) { 
# 405 "/home/claude/cfront-3/src/dcl.cpp"
if ((__1nn -> base__4node == 85 )&& (__1nn -> __O1__4expr.tp -> base__4node == 108 )){ 
# 406 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 406 "/home/claude/cfront-3/src/dcl.cpp"
struct
# 406 "/home/claude/cfront-3/src/dcl.cpp"
ea __0__V47 ;

# 406 "/home/claude/cfront-3/src/dcl.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"FM%n for anonymous union", (const struct ea *)(
# 406 "/home/claude/cfront-3/src/dcl.cpp"
((& __0__V47 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V47 )) , (const struct ea *)ea0 , (const struct
# 406 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
continue ;
} }
{ Ptable __2tb ;

# 409 "/home/claude/cfront-3/src/dcl.cpp"
__2tb = __1nn -> __O4__4expr.n_table ;
__1nn -> __O4__4expr.n_table = 0 ;
__1nn -> n_tbl_list__4name = 0 ;
__1nn -> n_scope__4name = (__1un -> n_protect__4name ?__1un -> n_protect__4name :__1un -> n_scope__4name );
if (__1nn -> n_key__4name == 159 )
# 414 "/home/claude/cfront-3/src/dcl.cpp"
continue ;
if ((((__1nn -> n_key__4name == 6 )&& ((__1nn -> __O2__4expr.string [0 ])== '_' ))&& ((__1nn -> __O2__4expr.string [1 ])== '_' ))&& ((__1nn -> __O2__4expr.string [2 ])== 'C' ))
# 419 "/home/claude/cfront-3/src/dcl.cpp"
continue ;
# 419 "/home/claude/cfront-3/src/dcl.cpp"

# 421 "/home/claude/cfront-3/src/dcl.cpp"
{ Pname __2n ;

# 421 "/home/claude/cfront-3/src/dcl.cpp"
__2n = look__5tableFPCcUc ( __1realtbl , __1nn -> __O2__4expr.string , (unsigned char )0 ) ;

# 424 "/home/claude/cfront-3/src/dcl.cpp"
if (__2n && (__2n -> __O4__4expr.n_table != __1tbl )){ 
# 425 "/home/claude/cfront-3/src/dcl.cpp"
if ((__1tbl == gtbl )|| __1tbl -> t_name__5table )
# 426 "/home/claude/cfront-3/src/dcl.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1nn ->
# 426 "/home/claude/cfront-3/src/dcl.cpp"
where__4name , (const char *)"table mismatch", (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 426 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
if ((__2n -> __O4__4expr.n_table -> real_block__5table != __1realtbl -> real_block__5table )|| (__2n -> lex_level__4name != __1nn -> lex_level__4name ))
# 430 "/home/claude/cfront-3/src/dcl.cpp"
__2n = 0 ;
}
if (__2n == 0 ){ 
# 433 "/home/claude/cfront-3/src/dcl.cpp"
adef :__2n = insert__5tableFP4nameUc ( __1tbl , __1nn , __1nn -> n_key__4name ) ;
if ((__1nn -> n_key__4name == 6 )&& Nold ){ 
# 437 "/home/claude/cfront-3/src/dcl.cpp"
continue ;
}
}
else 
# 439 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 439 "/home/claude/cfront-3/src/dcl.cpp"
const void *__2__X52 ;

# 441 "/home/claude/cfront-3/src/dcl.cpp"
if (__1nn -> n_key__4name == 6 ){ 
# 442 "/home/claude/cfront-3/src/dcl.cpp"
if (__2n -> base__4node == 123 ){ 
# 442 "/home/claude/cfront-3/src/dcl.cpp"
const void *__2__X51 ;

# 443 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 443 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V48 ;

# 443 "/home/claude/cfront-3/src/dcl.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"twoDs ofTN %s (one in anonymous union)", (const struct ea *)(
# 443 "/home/claude/cfront-3/src/dcl.cpp"
(__2__X51 = (const void *)__2n -> __O2__4expr.string ), ( ((& __0__V48 )-> __O1__2ea.p = __2__X51 ), (& __0__V48 )) ) ,
# 443 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
continue ;
} }
goto adef ;
}
if (((__2n -> base__4node != __1nn -> base__4node )|| (__1nn -> base__4node == 85 ))|| check__4typeFP4typeUcT2 ( __2n -> __O1__4expr.tp , __1nn -> __O1__4expr.tp , (unsigned
# 448 "/home/claude/cfront-3/src/dcl.cpp"
char )0 , (unsigned char )0 ) )
# 452 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 452 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V49 ;

# 452 "/home/claude/cfront-3/src/dcl.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"twoDs of %s (one in anonymous union)", (const struct ea *)(
# 452 "/home/claude/cfront-3/src/dcl.cpp"
(__2__X52 = (const void *)__2n -> __O2__4expr.string ), ( ((& __0__V49 )-> __O1__2ea.p = __2__X52 ), (& __0__V49 )) ) ,
# 452 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} continue ;
}

# 456 "/home/claude/cfront-3/src/dcl.cpp"
__2n -> n_anon__4name = __1un -> __O2__4expr.string ;
__1nn -> __O4__4expr.n_table = __2tb ;
if (((__1cl -> in_class__4type && (__1un -> n_sto__4name == 31 ))&& (__1nn -> base__4node != 123 ))&& (__1nn -> n_key__4name != 6 ))
# 461 "/home/claude/cfront-3/src/dcl.cpp"
__2n -> n_stclass__4name = 31 ;
# 461 "/home/claude/cfront-3/src/dcl.cpp"

# 461 "/home/claude/cfront-3/src/dcl.cpp"
}

# 461 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 462 "/home/claude/cfront-3/src/dcl.cpp"
}

# 462 "/home/claude/cfront-3/src/dcl.cpp"
}

# 462 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 242 "/home/claude/cfront-3/src/cfront.h"
struct ktable {	/* sizeof ktable == 40 */

# 179 "/home/claude/cfront-3/src/cfront.h"
TOK base__4node ;
bit permanent__4node ;
bit baseclass__4node ;

# 247 "/home/claude/cfront-3/src/cfront.h"
union  __Q2_6ktable4__C1 __O1__6ktable ;
short k_size__6ktable ;
bit k_tiny__6ktable ;
TOK k_id__6ktable ;

# 252 "/home/claude/cfront-3/src/cfront.h"
Pktab k_next__6ktable ;
Pname k_name__6ktable ;
};

# 256 "/home/claude/cfront-3/src/cfront.h"
extern Pktab table_free__6ktable ;

# 262 "/home/claude/cfront-3/src/cfront.h"
Pname find_cn__6ktableFPCc (struct ktable *__0this , const char *);

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1228 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr call_ctor__FP5tableP4exprN22iT2 (Ptable , Pexpr __0p , Pexpr __0ctor , Pexpr __0args , int __0d , Pexpr __0vb_args );

# 633 "/home/claude/cfront-3/src/cfront.h"
struct fct *__ct__3fctFP4typeP4nameUc (struct fct *__0this , Ptype , Pname , TOK );

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 940 "/home/claude/cfront-3/src/cfront.h"
Pname dcl__4nameFP5tableUc (struct name *__0this , Ptable , TOK );

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 946 "/home/claude/cfront-3/src/cfront.h"
void simpl__4nameFv (struct name *__0this );

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/dcl.cpp"
void make_vec_ctor__8classdefFP4name (register struct classdef *__0this , Pname __1default_ctor )
# 467 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 472 "/home/claude/cfront-3/src/dcl.cpp"
Pname __1tn ;

# 472 "/home/claude/cfront-3/src/dcl.cpp"
__1tn = (((struct fct *)(((struct fct *)__1default_ctor -> __O1__4expr.tp ))))-> f_this__3fct ;
if (__1tn -> base__4node == 169 ){ 
# 474 "/home/claude/cfront-3/src/dcl.cpp"
__1tn = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
((*__1tn ))= (*(((struct fct *)(((struct fct *)__1default_ctor -> __O1__4expr.tp ))))-> f_this__3fct );
__1tn -> base__4node = 85 ;
}

# 479 "/home/claude/cfront-3/src/dcl.cpp"
{ Pname __1cn ;

# 480 "/home/claude/cfront-3/src/dcl.cpp"
struct dcl_context *__0__X54 ;

# 479 "/home/claude/cfront-3/src/dcl.cpp"
__1cn = find_cn__6ktableFPCc ( __0this -> k_tbl__8classdef , __0this -> string__8classdef ) ;
if (__1cn )__1cn = (((struct basetype *)(((struct basetype *)__1cn -> __O1__4expr.tp ))))-> b_name__8basetype ;
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 481 "/home/claude/cfront-3/src/dcl.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;
cc -> not4__11dcl_context = __1cn ;
cc -> cot__11dcl_context = __0this ;
cc -> c_this__11dcl_context = __1tn ;

# 486 "/home/claude/cfront-3/src/dcl.cpp"
{ Pexpr __1th ;
Pstmt __1s ;
Pexpr __1e ;

# 489 "/home/claude/cfront-3/src/dcl.cpp"
struct estmt *__0__X59 ;

# 489 "/home/claude/cfront-3/src/dcl.cpp"
struct loc __2__X60 ;

# 486 "/home/claude/cfront-3/src/dcl.cpp"
__1th = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )34 , (struct expr *)0 , (struct expr *)0 ) ;
__1s = (struct stmt *)( (__0__X59 = 0 ), ( (__2__X60 = no_where ), ( ((__0__X59 || (__0__X59 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 487 "/home/claude/cfront-3/src/dcl.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X59 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X59 ), ((unsigned char )72 ), __2__X60 , ((struct
# 487 "/home/claude/cfront-3/src/dcl.cpp"
stmt *)0 )) ), (__0__X59 -> __O2__4stmt.e = ((struct expr *)0 ))) :0 ), __0__X59 ) ) ) ;
__1e = call_ctor__FP5tableP4exprN22iT2 ( __0this -> memtbl__8classdef , __1th , (struct expr *)__1default_ctor , (struct expr *)0 , 44 , (struct expr *)0 ) ;
__1s -> __O2__4stmt.e = __1e ;

# 491 "/home/claude/cfront-3/src/dcl.cpp"
{ Pname __1fn ;
Pfct __1f ;

# 493 "/home/claude/cfront-3/src/dcl.cpp"
register struct block *__0__X55 ;

# 493 "/home/claude/cfront-3/src/dcl.cpp"
struct loc __2__X56 ;

# 493 "/home/claude/cfront-3/src/dcl.cpp"
struct loc __2__X57 ;

# 491 "/home/claude/cfront-3/src/dcl.cpp"
__1fn = __ct__4nameFPCc ( (struct name *)0 , __0this -> string__8classdef ) ;
__1f = __ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)void_type , (struct name *)0 , (unsigned char )1 ) ;
__1fn -> __O1__4expr.tp = (struct type *)__1f ;
__1f -> body__3fct = ( (__0__X55 = 0 ), ( (__2__X56 = curloc ), ( (__2__X57 = noloc ), ( ((__0__X55 || (__0__X55 =
# 494 "/home/claude/cfront-3/src/dcl.cpp"
(struct block *)__nw__4stmtSFUl ( (size_t )(sizeof (struct block))) ))?(((void )( (__0__X55 = (struct block *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X55 ), (unsigned
# 494 "/home/claude/cfront-3/src/dcl.cpp"
char )116 , __2__X56 , __1s ) ), ( (__0__X55 -> __O1__4stmt.d = ((struct name *)0 )), (__0__X55 -> __O3__4stmt.where2 = __2__X57 )) )
# 494 "/home/claude/cfront-3/src/dcl.cpp"
)):(((void )0 ))), __0__X55 ) ) ) ) ;
{ Pname __1nn ;

# 496 "/home/claude/cfront-3/src/dcl.cpp"
struct dcl_context *__0__X58 ;

# 495 "/home/claude/cfront-3/src/dcl.cpp"
__1nn = dcl__4nameFP5tableUc ( __1fn , __0this -> memtbl__8classdef , (unsigned char )25 ) ;
__1nn -> n_sto__4name = 31 ;
( ( (cc -- ), (((void )0 ))) ) ;

# 499 "/home/claude/cfront-3/src/dcl.cpp"
simpl__4nameFv ( __1nn ) ;
dcl_print__4nameFUc ( __1nn , (unsigned char )0 ) ;
__0this -> c_vtor__8classdef = __1nn ;
( (__1fn ?(((void )(__1fn ?(((void )( ( ((((struct expr *)__1fn ))?(((void )((((struct expr *)__1fn ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 502 "/home/claude/cfront-3/src/dcl.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1fn , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 502 "/home/claude/cfront-3/src/dcl.cpp"
}

# 502 "/home/claude/cfront-3/src/dcl.cpp"
}

# 502 "/home/claude/cfront-3/src/dcl.cpp"
}

# 502 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 505 "/home/claude/cfront-3/src/dcl.cpp"
int stat_init = 0 ;

# 345 "/home/claude/cfront-3/src/cfront.h"
void dcl__4typeFP5table (struct type *__0this , Ptable );

# 38 "/home/claude/cfront-3/src/cfront.h"
extern char *make_nested_name__FPCcP8classdef (const char *, Pclass );

# 592 "/home/claude/cfront-3/src/dcl.cpp"
extern void typedef_check__FP4name (Pname );

# 945 "/home/claude/cfront-3/src/cfront.h"
void check_oper__4nameFP4name (struct name *__0this , Pname );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 449 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8classdefFP4name (struct classdef *__0this , Pname );

# 669 "/home/claude/cfront-3/src/cfront.h"
Pname find__3genFP3fctUc (struct gen *__0this , Pfct , bit );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 657 "/home/claude/cfront-3/src/cfront.h"
struct name_list *__ct__9name_listFP4nameP9name_list (struct name_list *__0this , Pname __1ff , Plist __1ll );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 943 "/home/claude/cfront-3/src/cfront.h"
void assign__4nameFv (struct name *__0this );

# 942 "/home/claude/cfront-3/src/cfront.h"

# 41 "/home/claude/cfront-3/src/dcl.cpp"
extern Pname dclass__FP4nameP5table (Pname , Ptable );
extern Pname denum__FP4nameP5table (Pname , Ptable );

# 950 "/home/claude/cfront-3/src/cfront.h"
Pname dofct__4nameFP5tableUc (struct name *__0this , Ptable , TOK );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 949 "/home/claude/cfront-3/src/cfront.h"
void field_align__4nameFv (struct name *__0this );

# 381 "/home/claude/cfront-3/src/cfront.h"
struct velem {	/* sizeof velem == 16 */
Pname n__5velem ;
int offset__5velem ;
};

# 76 "/home/claude/cfront-3/src/cfront.h"

# 346 "/home/claude/cfront-3/src/cfront.h"
int tsizeof__4typeFi (struct type *__0this , int );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 348 "/home/claude/cfront-3/src/cfront.h"
bit is_const_object__4typeFv (struct type *__0this );

# 350 "/home/claude/cfront-3/src/cfront.h"
int align__4typeFv (struct type *__0this );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 1230 "/home/claude/cfront-3/src/cfront.h"
extern void check_visibility__FP4nameT1P8classdefP5tableT1 (Pname , Pname , Pclass , Ptable , Pname );

# 220 "/home/claude/cfront-3/src/cfront.h"
struct table *__ct__5tableFsP5tableP4name (struct table *__0this , short , Ptable , Pname );

# 534 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr cdvec__FP4nameP4exprP8classdefT1iN22 (Pname , Pexpr , Pclass , Pname , int , Pexpr , Pexpr );

# 1229 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr call_dtor__FP4exprN21iT1 (Pexpr __0p , Pexpr __0dtor , Pexpr __0arg , int __0d , Pexpr __0vb_args );

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 804 "/home/claude/cfront-3/src/cfront.h"
Pexpr contents__4exprFv (struct expr *__0this );

# 942 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 469 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 803 "/home/claude/cfront-3/src/cfront.h"
Pexpr address__4exprFv (struct expr *__0this );

# 1223 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr replace_temp__FP4exprT1 (Pexpr , Pexpr );

# 739 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr class_init__FP4exprP4typeT1P5table (Pexpr , Ptype , Pexpr , Ptable );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 469 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 469 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 445 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 335 "/home/claude/cfront-3/src/cfront.h"
Ptype skiptypedefs__4typeFRUc (struct type *__0this , bit *__1isconst );

# 738 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ref_init__FP3ptrP4exprP5table (Pptr , Pexpr , Ptable );

# 736 "/home/claude/cfront-3/src/cfront.h"
extern void new_list__FP4expr (Pexpr );
extern void list_check__FP4nameP4typeP4exprP5table (Pname , Ptype , Pexpr , Ptable );

# 735 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr next_elem__Fv (void );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 1227 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ptr_init__FP3ptrP4exprP5table (Pptr , Pexpr , Ptable );

# 1155 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr try_to_coerce__FP4typeP4exprPCcP5table (Ptype , Pexpr , const char *, Ptable );

# 460 "/home/claude/cfront-3/src/cfront.h"
bit has_base__8classdefFP8classdefiT2 (struct classdef *__0this , Pclass __1cl , int __1level , int __1ccflag );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 718 "/home/claude/cfront-3/src/cfront.h"

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );

# 349 "/home/claude/cfront-3/src/cfront.h"
TOK set_const__4typeFUc (struct type *__0this , bit );

# 955 "/home/claude/cfront-3/src/cfront.h"
bit dinst_body__4nameFv (struct name *__0this );

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFUl (struct ea *__0this , size_t __2ii );

# 506 "/home/claude/cfront-3/src/dcl.cpp"
Pname dcl__4nameFP5tableUc (register struct name *__0this , Ptable __1tbl , TOK __1scope )
# 546 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 547 "/home/claude/cfront-3/src/dcl.cpp"
Pname __1nn ;
Pname __1odcl ;
int __1sti_vb ;

# 548 "/home/claude/cfront-3/src/dcl.cpp"
__1odcl = Cdcl ;
__1sti_vb = 0 ;

# 551 "/home/claude/cfront-3/src/dcl.cpp"
Cdcl = __0this ;
{ Ptype __1tx ;

# 553 "/home/claude/cfront-3/src/dcl.cpp"
unsigned long __2__X156 ;

# 552 "/home/claude/cfront-3/src/dcl.cpp"
__1tx = skiptypedefs__4typeFv ( __0this -> __O1__4expr.tp ) ;

# 556 "/home/claude/cfront-3/src/dcl.cpp"
switch (__0this -> base__4node ){ 
# 557 "/home/claude/cfront-3/src/dcl.cpp"
case 123 :
# 558 "/home/claude/cfront-3/src/dcl.cpp"
;
{ 
# 560 "/home/claude/cfront-3/src/dcl.cpp"
__1nn = look__5tableFPCcUc ( __1tbl , __0this -> __O2__4expr.string , (unsigned char )0 ) ;
dcl__4typeFP5table ( __0this -> __O1__4expr.tp , __1tbl ) ;

# 563 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O3__4expr.tpdef ){ 
# 564 "/home/claude/cfront-3/src/dcl.cpp"
Ptype __4tx ;

# 564 "/home/claude/cfront-3/src/dcl.cpp"
__4tx = __0this -> __O3__4expr.tpdef ;
if (__4tx -> in_class__4type && ((__4tx -> templ_base__4type == 3)|| (__4tx -> templ_base__4type == 2)))
# 566 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 567 "/home/claude/cfront-3/src/dcl.cpp"
__dl__FPv ( (void *)__4tx -> nested_sig__4type ) ;
# 567 "/home/claude/cfront-3/src/dcl.cpp"

# 568 "/home/claude/cfront-3/src/dcl.cpp"
__4tx -> nested_sig__4type = make_nested_name__FPCcP8classdef ( __0this -> __O2__4expr.string , __4tx -> in_class__4type ) ;
}
}

# 577 "/home/claude/cfront-3/src/dcl.cpp"
if (__1nn ){ 
# 578 "/home/claude/cfront-3/src/dcl.cpp"
Cdcl = __1odcl ;
return (struct name *)0 ;
}

# 582 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> __O1__4expr.tp -> permanent__4node = 1 ;
__1nn = __ct__4nameFPCc ( (struct name *)0 , __0this -> __O2__4expr.string ) ;
__1nn -> base__4node = 123 ;
__1nn -> where__4name = __0this -> where__4name ;
__1nn -> __O1__4expr.tp = __0this -> __O1__4expr.tp ;
__1nn -> lex_level__4name = __0this -> lex_level__4name ;
__1nn -> __O3__4expr.tpdef = __0this -> __O3__4expr.tpdef ;

# 590 "/home/claude/cfront-3/src/dcl.cpp"
{ Pname __3tn ;

# 590 "/home/claude/cfront-3/src/dcl.cpp"
__3tn = insert__5tableFP4nameUc ( __1tbl , __1nn , (unsigned char )0 ) ;
__3tn -> permanent__4node = 1 ;
;
typedef_check__FP4name ( __3tn ) ;
( (__1nn ?(((void )(__1nn ?(((void )( ( ((((struct expr *)__1nn ))?(((void )((((struct expr *)__1nn ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 594 "/home/claude/cfront-3/src/dcl.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1nn , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
Cdcl = __1odcl ;
return __0this ;

# 596 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 599 "/home/claude/cfront-3/src/dcl.cpp"
case 98 :
# 600 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> base__4node = 85 ;
__1scope = 136 ;

# 604 "/home/claude/cfront-3/src/dcl.cpp"
case 85 :
# 608 "/home/claude/cfront-3/src/dcl.cpp"
;
switch (__0this -> n_oper__4name ){ 
# 610 "/home/claude/cfront-3/src/dcl.cpp"
case 47 :
# 611 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O1__4expr.tp -> base__4node != 108 ){ 
# 611 "/home/claude/cfront-3/src/dcl.cpp"
const void *__2__X150 ;

# 612 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 612 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V61 ;

# 612 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"~%s notF", (const struct ea *)( (__2__X150 = (const void
# 612 "/home/claude/cfront-3/src/dcl.cpp"
*)__0this -> __O2__4expr.string ), ( ((& __0__V61 )-> __O1__2ea.p = __2__X150 ), (& __0__V61 )) ) , (const struct ea *)ea0 ,
# 612 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__0this -> n_oper__4name = 0 ;
} }
break ;
case 123 :
# 617 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O1__4expr.tp -> base__4node != 108 )
# 618 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_oper__4name = 0 ;
break ;
}
break ;
default :
# 623 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCc ( (int )'i' , (const char *)"NX inN::dcl()") ;
break ;
}

# 627 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O2__4name.n_qualifier ){ 
# 631 "/home/claude/cfront-3/src/dcl.cpp"
Pname __2cn ;

# 631 "/home/claude/cfront-3/src/dcl.cpp"
__2cn = __0this -> __O2__4name.n_qualifier ;
switch (__2cn -> base__4node ){ 
# 632 "/home/claude/cfront-3/src/dcl.cpp"
const void *__2__X151 ;

# 633 "/home/claude/cfront-3/src/dcl.cpp"
case 123 :
# 634 "/home/claude/cfront-3/src/dcl.cpp"
break ;
case 85 :
# 636 "/home/claude/cfront-3/src/dcl.cpp"
__2cn = look__5tableFPCcUc ( gtbl , __2cn -> __O2__4expr.string , (unsigned char )0 ) ;
if (__2cn && (__2cn -> base__4node == 123 ))
# 638 "/home/claude/cfront-3/src/dcl.cpp"
break ;
default :
# 640 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 640 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V62 ;

# 640 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V63 ;

# 640 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"badQr%n for%n", (const struct ea *)( (__2__X151 = (const void
# 640 "/home/claude/cfront-3/src/dcl.cpp"
*)__0this -> __O2__4name.n_qualifier ), ( ((& __0__V62 )-> __O1__2ea.p = __2__X151 ), (& __0__V62 )) ) , (const struct ea *)(
# 640 "/home/claude/cfront-3/src/dcl.cpp"
((& __0__V63 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V63 )) , (const struct ea *)ea0 , (const struct
# 640 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }

# 645 "/home/claude/cfront-3/src/dcl.cpp"
__2cn -> __O1__4expr.tp = skiptypedefs__4typeFv ( __2cn -> __O1__4expr.tp ) ;
if (__2cn -> __O1__4expr.tp -> base__4node != 119 ){ 
# 646 "/home/claude/cfront-3/src/dcl.cpp"
const void *__2__X152 ;

# 647 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 647 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V64 ;

# 647 "/home/claude/cfront-3/src/dcl.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"Qr%n not aCN", (const struct ea *)(
# 647 "/home/claude/cfront-3/src/dcl.cpp"
(__2__X152 = (const void *)__0this -> __O2__4name.n_qualifier ), ( ((& __0__V64 )-> __O1__2ea.p = __2__X152 ), (& __0__V64 )) ) ,
# 647 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }

# 652 "/home/claude/cfront-3/src/dcl.cpp"
__2cn = (((struct basetype *)(((struct basetype *)__2cn -> __O1__4expr.tp ))))-> b_name__8basetype ;
if (__0this -> n_oper__4name )
# 654 "/home/claude/cfront-3/src/dcl.cpp"
check_oper__4nameFP4name ( __0this , __2cn ) ;

# 656 "/home/claude/cfront-3/src/dcl.cpp"
{ Pclass __2cl ;

# 657 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X153 ;

# 657 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X154 ;

# 656 "/home/claude/cfront-3/src/dcl.cpp"
__2cl = (((struct classdef *)(((struct classdef *)__2cn -> __O1__4expr.tp ))));
if (( (__1__X153 = __2cl ), ( (__1__X154 = cc -> cot__11dcl_context ), ( ((__1__X153 == __1__X154 )?1 :((__1__X153 && __1__X154 )?(((int )same_class__8classdefFP8classdefi ( __1__X153 ,
# 657 "/home/claude/cfront-3/src/dcl.cpp"
__1__X154 , 0 ) )):0 ))) ) ) ){ 
# 658 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> __O2__4name.n_qualifier = 0 ;
goto xdr ;
}
else if ((__2cl -> defined__4type & 3)== 0 ){ 
# 662 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 662 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V65 ;

# 662 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"C%nU", (const struct ea *)( ((& __0__V65 )-> __O1__2ea.p =
# 662 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__2cn )), (& __0__V65 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 662 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }
else if (__2cl -> c_body__8classdef == 1 )
# 667 "/home/claude/cfront-3/src/dcl.cpp"
dcl_print__8classdefFP4name ( __2cl , (struct name *)0 ) ;

# 669 "/home/claude/cfront-3/src/dcl.cpp"
{ Ptable __2etbl ;
Pname __2x ;

# 669 "/home/claude/cfront-3/src/dcl.cpp"
__2etbl = __2cl -> memtbl__8classdef ;
__2x = look__5tableFPCcUc ( __2etbl , __0this -> __O2__4expr.string , (unsigned char )0 ) ;
if ((__2x == 0 )|| (__2x -> __O4__4expr.n_table != __2etbl )){ 
# 672 "/home/claude/cfront-3/src/dcl.cpp"
Ptable __3tt ;

# 672 "/home/claude/cfront-3/src/dcl.cpp"
__3tt = __0this -> __O4__4expr.n_table ;
__0this -> __O4__4expr.n_table = __2etbl ;
{ 
# 674 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V66 ;

# 674 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V67 ;

# 674 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n is not aM of%n", (const struct ea *)( ((& __0__V66 )-> __O1__2ea.p =
# 674 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V66 )) , (const struct ea *)( ((& __0__V67 )-> __O1__2ea.p = ((const void
# 674 "/home/claude/cfront-3/src/dcl.cpp"
*)__2cn )), (& __0__V67 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__0this -> __O4__4expr.n_table = __3tt ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }

# 680 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O1__4expr.tp -> base__4node == 108 ){ 
# 681 "/home/claude/cfront-3/src/dcl.cpp"
if (((friend_in_class == 0 )&& (__0this -> n_sto__4name != 18 ))&& ((((struct fct *)(((struct
# 681 "/home/claude/cfront-3/src/dcl.cpp"
fct *)__0this -> __O1__4expr.tp ))))-> body__3fct == 0 ))
# 687 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 688 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 688 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V68 ;

# 688 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"QdN%n inFD", (const struct ea *)( ((& __0__V68 )-> __O1__2ea.p =
# 688 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__2x )), (& __0__V68 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 688 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }

# 693 "/home/claude/cfront-3/src/dcl.cpp"
if ((((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> body__3fct == 0 ){ 
# 694 "/home/claude/cfront-3/src/dcl.cpp"
(((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> memof__3fct = __2cl ;
# 694 "/home/claude/cfront-3/src/dcl.cpp"

# 695 "/home/claude/cfront-3/src/dcl.cpp"
{ int __4xx ;
if (__2x -> __O1__4expr.tp -> base__4node == 76 )
# 697 "/home/claude/cfront-3/src/dcl.cpp"
__4xx = (find__3genFP3fctUc ( ((struct gen *)(((struct gen *)__2x -> __O1__4expr.tp ))), ((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))),
# 697 "/home/claude/cfront-3/src/dcl.cpp"
(unsigned char )0 ) == 0 );
else 
# 699 "/home/claude/cfront-3/src/dcl.cpp"
__4xx = check__4typeFP4typeUcT2 ( __2x -> __O1__4expr.tp , __0this -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) ;
# 699 "/home/claude/cfront-3/src/dcl.cpp"

# 701 "/home/claude/cfront-3/src/dcl.cpp"
if (__4xx ){ 
# 702 "/home/claude/cfront-3/src/dcl.cpp"
Ptable __5tt ;

# 702 "/home/claude/cfront-3/src/dcl.cpp"
__5tt = __0this -> __O4__4expr.n_table ;
__0this -> __O4__4expr.n_table = __2etbl ;
{ 
# 704 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V69 ;

# 704 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V70 ;

# 704 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V71 ;

# 704 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n ofT%t is not aM of%n", (const struct ea *)( ((& __0__V69 )-> __O1__2ea.p =
# 704 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V69 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V70 , (const void *)__0this ->
# 704 "/home/claude/cfront-3/src/dcl.cpp"
__O1__4expr.tp ) , (const struct ea *)( ((& __0__V71 )-> __O1__2ea.p = ((const void *)__2cn )), (& __0__V71 )) ,
# 704 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 ) ;
__0this -> __O4__4expr.n_table = __5tt ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }

# 708 "/home/claude/cfront-3/src/dcl.cpp"
}
}
}
else { 
# 712 "/home/claude/cfront-3/src/dcl.cpp"
if (__2x -> n_stclass__4name != 31 ){ 
# 713 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 713 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V72 ;

# 713 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"D of non staticCM%n", (const struct ea *)( ((& __0__V72 )-> __O1__2ea.p =
# 713 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V72 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 713 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }
if (__0this -> n_sto__4name ){ 
# 717 "/home/claude/cfront-3/src/dcl.cpp"
unsigned long __2__X155 ;

# 718 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 718 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V73 ;

# 718 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"staticCM declared%k", (const struct ea *)( (__2__X155 = __0this -> n_sto__4name ),
# 718 "/home/claude/cfront-3/src/dcl.cpp"
( (( ((& __0__V73 )-> __O1__2ea.i = __2__X155 ), 0 ) ), (& __0__V73 )) ) , (const struct
# 718 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }

# 723 "/home/claude/cfront-3/src/dcl.cpp"
if (__2cl -> class_base__8classdef == 4)__0this -> n_redefined__4name = 1 ;
__1tbl = __2etbl ;
}

# 725 "/home/claude/cfront-3/src/dcl.cpp"
}

# 725 "/home/claude/cfront-3/src/dcl.cpp"
}
}
xdr :
# 728 "/home/claude/cfront-3/src/dcl.cpp"
if ((__0this -> n_oper__4name && (__0this -> __O1__4expr.tp -> base__4node != 108 ))&& (__0this -> n_sto__4name != 76 ))
# 729 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 729 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V74 ;

# 729 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"operator%k not aF", (const struct ea *)( (__2__X156 = __0this -> n_oper__4name ),
# 729 "/home/claude/cfront-3/src/dcl.cpp"
( (( ((& __0__V74 )-> __O1__2ea.i = __2__X156 ), 0 ) ), (& __0__V74 )) ) , (const struct
# 729 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 738 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_stclass__4name = __0this -> n_sto__4name ;
__0this -> n_scope__4name = __1scope ;

# 741 "/home/claude/cfront-3/src/dcl.cpp"
switch (__0this -> n_sto__4name ){ 
# 741 "/home/claude/cfront-3/src/dcl.cpp"
unsigned long __2__X157 ;

# 742 "/home/claude/cfront-3/src/dcl.cpp"
default :
# 743 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 743 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V75 ;

# 743 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"unX %k", (const struct ea *)( (__2__X157 =
# 743 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_sto__4name ), ( (( ((& __0__V75 )-> __O1__2ea.i = __2__X157 ), 0 ) ), (& __0__V75 )) ) ,
# 743 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
case 18 :
# 745 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 746 "/home/claude/cfront-3/src/dcl.cpp"
Pclass __3cl ;

# 746 "/home/claude/cfront-3/src/dcl.cpp"
__3cl = cc -> cot__11dcl_context ;

# 748 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1scope ){ 
# 749 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 750 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 751 "/home/claude/cfront-3/src/dcl.cpp"
break ;
default :
# 753 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 753 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V76 ;

# 753 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V77 ;

# 753 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"friend%n not inCD(%k)", (const struct ea *)( ((& __0__V76 )-> __O1__2ea.p =
# 753 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V76 )) , (const struct ea *)( (( ((& __0__V77 )-> __O1__2ea.i = ((unsigned
# 753 "/home/claude/cfront-3/src/dcl.cpp"
long )__1scope )), 0 ) ), (& __0__V77 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 753 "/home/claude/cfront-3/src/dcl.cpp"

# 754 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> base__4node = 0 ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }

# 759 "/home/claude/cfront-3/src/dcl.cpp"
switch (__0this -> n_oper__4name ){ 
# 760 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 761 "/home/claude/cfront-3/src/dcl.cpp"
case 23 :
# 762 "/home/claude/cfront-3/src/dcl.cpp"
case 213 :
# 763 "/home/claude/cfront-3/src/dcl.cpp"
case 9 :
# 764 "/home/claude/cfront-3/src/dcl.cpp"
case 212 :
# 765 "/home/claude/cfront-3/src/dcl.cpp"
case 161 :
# 766 "/home/claude/cfront-3/src/dcl.cpp"
case 162 :
# 767 "/home/claude/cfront-3/src/dcl.cpp"
case 97 :
# 768 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_sto__4name =
# 768 "/home/claude/cfront-3/src/dcl.cpp"
0 ;
break ;
default :
# 771 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_sto__4name = 76 ;
}

# 776 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1tx -> base__4node ){ 
# 776 "/home/claude/cfront-3/src/dcl.cpp"
struct dcl_context *__0__X158 ;

# 776 "/home/claude/cfront-3/src/dcl.cpp"
struct dcl_context *__0__X159 ;

# 776 "/home/claude/cfront-3/src/dcl.cpp"
const void *__2__X160 ;

# 777 "/home/claude/cfront-3/src/dcl.cpp"
case 119 :
# 778 "/home/claude/cfront-3/src/dcl.cpp"
__1nn = (((struct basetype *)(((struct basetype *)__1tx ))))-> b_name__8basetype ;
break ;
case 6 :
# 781 "/home/claude/cfront-3/src/dcl.cpp"
__1nn = __0this ;
break ;
case 108 :
# 784 "/home/claude/cfront-3/src/dcl.cpp"
(((struct fct *)(((struct fct *)__1tx ))))-> def_context__3fct = cc -> cot__11dcl_context ;
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 785 "/home/claude/cfront-3/src/dcl.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;
cc -> not4__11dcl_context = 0 ;
cc -> tot__11dcl_context = 0 ;
cc -> cot__11dcl_context = 0 ;
friend_in_class ++ ;
__0this -> n_sto__4name = 0 ;

# 792 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> lex_level__4name = 0 ;
__1nn = dcl__4nameFP5tableUc ( __0this , gtbl , (unsigned char )14 ) ;
if (__1nn == 0 ){ 
# 795 "/home/claude/cfront-3/src/dcl.cpp"
Cdcl = __1odcl ;
return (struct name *)0 ;
}
friend_in_class -- ;
( ( (cc -- ), (((void )0 ))) ) ;
if (__1nn -> __O1__4expr.tp -> base__4node == 76 )
# 801 "/home/claude/cfront-3/src/dcl.cpp"
__1nn = find__3genFP3fctUc ( ((struct gen *)(((struct gen *)__1nn -> __O1__4expr.tp ))), ((struct fct *)(((struct fct *)__1tx ))), (unsigned
# 801 "/home/claude/cfront-3/src/dcl.cpp"
char )1 ) ;
break ;
default :
# 804 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 804 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V78 ;

# 804 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V79 ;

# 804 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"badT%t of friend%n", (const struct ea *)( (__2__X160 = (const void
# 804 "/home/claude/cfront-3/src/dcl.cpp"
*)__0this -> __O1__4expr.tp ), ( ((& __0__V78 )-> __O1__2ea.p = __2__X160 ), (& __0__V78 )) ) , (const struct ea *)(
# 804 "/home/claude/cfront-3/src/dcl.cpp"
((& __0__V79 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V79 )) , (const struct ea *)ea0 , (const struct
# 804 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }

# 809 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> permanent__4node = 1 ;
__3cl -> friend_list__8classdef = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __1nn , __3cl -> friend_list__8classdef ) ;
Cdcl = __1odcl ;
return __1nn ;
}

# 815 "/home/claude/cfront-3/src/dcl.cpp"
case 76 :
# 816 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCc ( strict_opt ?0 :119, (const char *)"`overload' used (anachronism)") ;
__0this -> n_sto__4name = 0 ;
switch (__0this -> __O1__4expr.tp -> base__4node ){ 
# 819 "/home/claude/cfront-3/src/dcl.cpp"
case 108 :
# 820 "/home/claude/cfront-3/src/dcl.cpp"
break ;
default :
# 822 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> base__4node = 0 ;
Cdcl = __1odcl ;
return __0this ;
}
break ;

# 828 "/home/claude/cfront-3/src/dcl.cpp"
case 27 :
# 829 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O1__4expr.tp -> base__4node == 108 ){ 
# 830 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 830 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V80 ;

# 830 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%n: register (ignored)", (const struct ea *)( ((&
# 830 "/home/claude/cfront-3/src/dcl.cpp"
__0__V80 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V80 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 830 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 ) ;
goto ddd ;
} }

# 834 "/home/claude/cfront-3/src/dcl.cpp"
case 2 :
# 835 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1scope ){ 
# 835 "/home/claude/cfront-3/src/dcl.cpp"
unsigned long __2__X161 ;

# 836 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 837 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 838 "/home/claude/cfront-3/src/dcl.cpp"
case 14 :
# 839 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 839 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V81 ;

# 839 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k not inF", (const struct ea *)( (__2__X161 = __0this -> n_sto__4name ),
# 839 "/home/claude/cfront-3/src/dcl.cpp"
( (( ((& __0__V81 )-> __O1__2ea.i = __2__X161 ), 0 ) ), (& __0__V81 )) ) , (const struct
# 839 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
goto ddd ;
} }
if (__0this -> n_sto__4name == 2 )
# 843 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_sto__4name = 0 ;
break ;

# 846 "/home/claude/cfront-3/src/dcl.cpp"
case 14 :
# 847 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1scope ){ 
# 848 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 849 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 851 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O1__4expr.tp -> base__4node != 108 )
# 852 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 852 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V82 ;

# 852 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"externM%n", (const struct ea *)( ((& __0__V82 )-> __O1__2ea.p =
# 852 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V82 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 852 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} 
# 854 "/home/claude/cfront-3/src/dcl.cpp"
case 136 :
# 855 "/home/claude/cfront-3/src/dcl.cpp"
goto ddd ;

# 857 "/home/claude/cfront-3/src/dcl.cpp"
case 108 :
# 858 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 859 "/home/claude/cfront-3/src/dcl.cpp"
Pname __4nn ;

# 859 "/home/claude/cfront-3/src/dcl.cpp"
__4nn = look__5tableFPCcUc ( gtbl , __0this -> __O2__4expr.string , (unsigned char )0 ) ;
dcl__4typeFP5table ( __0this -> __O1__4expr.tp , __1tbl ) ;
if ((__4nn && (__0this -> __O1__4expr.tp -> base__4node != 108 ))&& check__4typeFP4typeUcT2 ( __0this -> __O1__4expr.tp , __4nn -> __O1__4expr.tp , (unsigned char )0 ,
# 861 "/home/claude/cfront-3/src/dcl.cpp"
(unsigned char )0 ) )
# 867 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 868 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 868 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V83 ;

# 868 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V84 ;

# 868 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V85 ;

# 868 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of%n;Ts:%t and%t", (const struct ea *)( ((& __0__V83 )-> __O1__2ea.p =
# 868 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V83 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V84 , (const void *)__4nn ->
# 868 "/home/claude/cfront-3/src/dcl.cpp"
__O1__4expr.tp ) , (const struct ea *)__ct__2eaFPCv ( & __0__V85 , (const void *)__0this -> __O1__4expr.tp ) , (const struct
# 868 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }
}
}
__0this -> n_stclass__4name = 31 ;
__0this -> n_scope__4name = 14 ;
break ;

# 878 "/home/claude/cfront-3/src/dcl.cpp"
case 31 :
# 879 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1scope ){ 
# 880 "/home/claude/cfront-3/src/dcl.cpp"
case 136 :
# 881 "/home/claude/cfront-3/src/dcl.cpp"
goto ddd ;
case 0 :
# 883 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 884 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_stclass__4name = 31 ;
__0this -> n_scope__4name = __1scope ;
break ;
default :
# 888 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_scope__4name = 31 ;
}
break ;

# 892 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 893 "/home/claude/cfront-3/src/dcl.cpp"
ddd :
# 894 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1scope ){ 
# 895 "/home/claude/cfront-3/src/dcl.cpp"
case 14 :
# 896 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_scope__4name = 14 ;
__0this -> n_stclass__4name = 31 ;
break ;
case 108 :
# 900 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O1__4expr.tp -> base__4node == 108 ){ 
# 901 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_stclass__4name = 31 ;
__0this -> n_scope__4name = 14 ;
}
else 
# 905 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_stclass__4name = 2 ;
break ;
case 136 :
# 908 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_stclass__4name = 2 ;
break ;
case 0 :
# 911 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 912 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_stclass__4name = 0 ;
break ;
}
} }

# 925 "/home/claude/cfront-3/src/dcl.cpp"
{ static int __1warn_ldouble = 0 ;

# 927 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1tx -> base__4node ){ 
# 928 "/home/claude/cfront-3/src/dcl.cpp"
case 1 :
# 929 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 930 "/home/claude/cfront-3/src/dcl.cpp"
Pbase __3b ;
Pname __3n ;

# 930 "/home/claude/cfront-3/src/dcl.cpp"
__3b = (((struct basetype *)(((struct basetype *)__0this -> __O1__4expr.tp ))));
__3n = insert__5tableFP4nameUc ( __1tbl , __0this , (unsigned char )0 ) ;
assign__4nameFv ( __3n ) ;
( (__3n -> n_used__4name ++ ), (((void )0 ))) ;
{ char *__3s ;
int __3ll ;
char *__3s2 ;

# 934 "/home/claude/cfront-3/src/dcl.cpp"
__3s = (((char *)__3b -> b_name__8basetype ));
__3ll = strlen ( (const char *)__3s ) ;
__3s2 = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* (__3ll + 1 ))) ));
strcpy ( __3s2 , (const char *)__3s ) ;
__3b -> b_name__8basetype = (((struct name *)(((struct name *)__3s2 ))));
Cdcl = __1odcl ;
return __0this ;

# 940 "/home/claude/cfront-3/src/dcl.cpp"
}
}
case 6 :
# 943 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> n_key__4name == 44 ){ 
# 945 "/home/claude/cfront-3/src/dcl.cpp"
__1nn = insert__5tableFP4nameUc ( __1tbl , __0this , (unsigned char )6 ) ;
__0this -> n_key__4name = 44 ;

# 956 "/home/claude/cfront-3/src/dcl.cpp"
}
else 
# 958 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 959 "/home/claude/cfront-3/src/dcl.cpp"
if (__1tx -> in_class__4type && ((__1tx -> templ_base__4type == 3)|| (__1tx -> templ_base__4type == 2)))
# 960 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 961 "/home/claude/cfront-3/src/dcl.cpp"
__dl__FPv ( (void *)__1tx ->
# 961 "/home/claude/cfront-3/src/dcl.cpp"
nested_sig__4type ) ;
__1tx -> nested_sig__4type = make_nested_name__FPCcP8classdef ( (((struct classdef *)(((struct classdef *)__1tx ))))-> string__8classdef , __1tx -> in_class__4type ) ;
}
__0this -> __O1__4expr.tp = __1tx ;
__1nn = dclass__FP4nameP5table ( __0this , __1tbl ) ;
}
Cdcl = __1odcl ;
return __1nn ;
case 13 :
# 970 "/home/claude/cfront-3/src/dcl.cpp"
if (__1tx -> in_class__4type && ((__1tx -> templ_base__4type == 3)|| (__1tx -> templ_base__4type == 2)))
# 971 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 972 "/home/claude/cfront-3/src/dcl.cpp"
__dl__FPv ( (void *)__1tx -> nested_sig__4type )
# 972 "/home/claude/cfront-3/src/dcl.cpp"
;
__1tx -> nested_sig__4type = make_nested_name__FPCcP8classdef ( (((struct enumdef *)(((struct enumdef *)__1tx ))))-> string__7enumdef , __1tx -> in_class__4type ) ;
}
__0this -> __O1__4expr.tp = __1tx ;
__1nn = denum__FP4nameP5table ( __0this , __1tbl ) ;
Cdcl = __1odcl ;
return __1nn ;
case 108 :
# 980 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> __O1__4expr.tp = __1tx ;
__1nn = dofct__4nameFP5tableUc ( __0this , __1tbl , __1scope ) ;
if (__1nn == 0 ){ 
# 983 "/home/claude/cfront-3/src/dcl.cpp"
Cdcl = __1odcl ;
return (struct name *)0 ;
}

# 987 "/home/claude/cfront-3/src/dcl.cpp"
if (pdef_name == 0 )
# 988 "/home/claude/cfront-3/src/dcl.cpp"
check_def_name__FP4namei ( __1nn , (int )__1scope ) ;
break ;

# 991 "/home/claude/cfront-3/src/dcl.cpp"
case 114 :
# 992 "/home/claude/cfront-3/src/dcl.cpp"
switch (__0this -> n_stclass__4name ){ 
# 992 "/home/claude/cfront-3/src/dcl.cpp"
unsigned long __2__X162 ;

# 993 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 994 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 995 "/home/claude/cfront-3/src/dcl.cpp"
break ;
default :
# 997 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 997 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V86 ;

# 997 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k field", (const struct ea *)( (__2__X162 = __0this -> n_stclass__4name ),
# 997 "/home/claude/cfront-3/src/dcl.cpp"
( (( ((& __0__V86 )-> __O1__2ea.i = __2__X162 ), 0 ) ), (& __0__V86 )) ) , (const struct
# 997 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__0this -> n_stclass__4name = 0 ;
} }

# 1001 "/home/claude/cfront-3/src/dcl.cpp"
if (((cc -> not4__11dcl_context == 0 )|| ((cc -> cot__11dcl_context -> csu__8classdef == 36 )&& (! ansi_opt )))|| (cc -> cot__11dcl_context -> csu__8classdef ==
# 1001 "/home/claude/cfront-3/src/dcl.cpp"
167 ))
# 1007 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1008 "/home/claude/cfront-3/src/dcl.cpp"
if (cc -> not4__11dcl_context )
# 1009 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCc ( (int )'s' , (const char *)"bit-field as member of union") ;
# 1009 "/home/claude/cfront-3/src/dcl.cpp"
else 
# 1011 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCc ( (const char *)"bit-field not inC") ;
__0this -> __O1__4expr.tp -> permanent__4node = 1 ;
Cdcl = __1odcl ;
return __0this ;
}

# 1017 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O2__4expr.string ){ 
# 1018 "/home/claude/cfront-3/src/dcl.cpp"
__1nn = insert__5tableFP4nameUc ( __1tbl , __0this , (unsigned char )0 ) ;
__0this -> __O4__4expr.n_table = __1nn -> __O4__4expr.n_table ;
if (Nold )
# 1021 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1021 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V87 ;

# 1021 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of field%n", (const struct ea *)( ((& __0__V87 )-> __O1__2ea.p =
# 1021 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V87 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1021 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} }

# 1024 "/home/claude/cfront-3/src/dcl.cpp"
dcl__4typeFP5table ( __0this -> __O1__4expr.tp , __1tbl ) ;
field_align__4nameFv ( __0this ) ;
break ;

# 1028 "/home/claude/cfront-3/src/dcl.cpp"
case 119 :
# 1029 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1030 "/home/claude/cfront-3/src/dcl.cpp"
Pclass __3cl ;

# 1030 "/home/claude/cfront-3/src/dcl.cpp"
__3cl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1tx ))))-> b_name__8basetype -> __O1__4expr.tp ))));

# 1035 "/home/claude/cfront-3/src/dcl.cpp"
if (__3cl -> csu__8classdef == 167 )export_anon__FP4nameP8classdefP5table ( __0this , __3cl , __1tbl ) ;

# 1037 "/home/claude/cfront-3/src/dcl.cpp"
if (__3cl -> c_abstract__8classdef ){ 
# 1038 "/home/claude/cfront-3/src/dcl.cpp"
if ((((__3cl -> string__8classdef [0 ])== '_' )&& ((__3cl -> string__8classdef [1 ])== '_' ))&& ((__3cl -> string__8classdef [2 ])== 'C' ))
# 1040 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCc ( (int
# 1040 "/home/claude/cfront-3/src/dcl.cpp"
)'e' , (const char *)"D ofO of abstractC - pure virtual function(s) ") ;
else 
# 1042 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1042 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V88 ;

# 1042 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"D ofO of abstractC%t - pure virtual function(s) ", (const struct ea *)( ((&
# 1042 "/home/claude/cfront-3/src/dcl.cpp"
__0__V88 )-> __O1__2ea.p = ((const void *)__3cl )), (& __0__V88 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1042 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 ) ;
} { { Pbcl __4bcl ;

# 1043 "/home/claude/cfront-3/src/dcl.cpp"
__4bcl = __3cl -> baselist__8classdef ;

# 1043 "/home/claude/cfront-3/src/dcl.cpp"
for(;__4bcl ;__4bcl = __4bcl -> next__6basecl ) 
# 1044 "/home/claude/cfront-3/src/dcl.cpp"
{ { Pvirt __4n ;

# 1044 "/home/claude/cfront-3/src/dcl.cpp"
__4n = __4bcl -> bclass__6basecl -> virt_list__8classdef ;

# 1044 "/home/claude/cfront-3/src/dcl.cpp"
for(;__4n ;__4n = __4n -> next__4virt ) { 
# 1045 "/home/claude/cfront-3/src/dcl.cpp"
struct velem *__5ivec ;
Pname __5vn ;

# 1045 "/home/claude/cfront-3/src/dcl.cpp"
__5ivec = __4n -> virt_init__4virt ;

# 1047 "/home/claude/cfront-3/src/dcl.cpp"
{ { int __5i ;

# 1047 "/home/claude/cfront-3/src/dcl.cpp"
__5i = 0 ;

# 1047 "/home/claude/cfront-3/src/dcl.cpp"
for(;__5vn = (__5ivec [__5i ]). n__5velem ;__5i ++ ) { 
# 1048 "/home/claude/cfront-3/src/dcl.cpp"
Pname __6n ;

# 1048 "/home/claude/cfront-3/src/dcl.cpp"
__6n = look__5tableFPCcUc ( __3cl -> memtbl__8classdef , __5vn -> __O2__4expr.string , (unsigned char )0 ) ;
if (__5vn -> __O3__4expr.n_initializer && ((__6n == 0 )|| (__6n -> base__4node == 25 )))
# 1050 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1050 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V89 ;

# 1050 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"%n ", (const struct ea *)( ((&
# 1050 "/home/claude/cfront-3/src/dcl.cpp"
__0__V89 )-> __O1__2ea.p = ((const void *)__5vn )), (& __0__V89 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1050 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 ) ;
} }

# 1051 "/home/claude/cfront-3/src/dcl.cpp"
}

# 1051 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 1052 "/home/claude/cfront-3/src/dcl.cpp"
}

# 1052 "/home/claude/cfront-3/src/dcl.cpp"
}
error__FiPCc ( (int )'c' , (const char *)"have not been defined\n") ;

# 1053 "/home/claude/cfront-3/src/dcl.cpp"
}

# 1053 "/home/claude/cfront-3/src/dcl.cpp"
}
}
goto cde ;
}

# 1058 "/home/claude/cfront-3/src/dcl.cpp"
case 38 :
# 1059 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> n_scope__4name != 136 ){ 
# 1059 "/home/claude/cfront-3/src/dcl.cpp"
unsigned long __2__X163 ;

# 1060 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1060 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V90 ;

# 1060 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V91 ;

# 1060 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k%n", (const struct ea *)( (__2__X163 = __1tx -> base__4node ),
# 1060 "/home/claude/cfront-3/src/dcl.cpp"
( (( ((& __0__V90 )-> __O1__2ea.i = __2__X163 ), 0 ) ), (& __0__V90 )) ) , (const struct
# 1060 "/home/claude/cfront-3/src/dcl.cpp"
ea *)( ((& __0__V91 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V91 )) , (const struct ea *)ea0 , (const
# 1060 "/home/claude/cfront-3/src/dcl.cpp"
struct ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }
break ;

# 1066 "/home/claude/cfront-3/src/dcl.cpp"
case 181 :
# 1067 "/home/claude/cfront-3/src/dcl.cpp"
if ((__1warn_ldouble == 0 )&& (ansi_opt == 0 )){ 
# 1068 "/home/claude/cfront-3/src/dcl.cpp"
++ __1warn_ldouble ;
{ 
# 1069 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V92 ;

# 1069 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"long double supported under ``+a1'' option only, generating ``double%n''", (const struct ea *)( ((&
# 1069 "/home/claude/cfront-3/src/dcl.cpp"
__0__V92 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V92 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1069 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 ) ;
} }
goto cde ;

# 1073 "/home/claude/cfront-3/src/dcl.cpp"
case 125 :
# 1085 "/home/claude/cfront-3/src/dcl.cpp"
case 110 :
# 1086 "/home/claude/cfront-3/src/dcl.cpp"
case 158 :
# 1087 "/home/claude/cfront-3/src/dcl.cpp"
dcl__4typeFP5table ( __0this -> __O1__4expr.tp , __1tbl ) ;

# 1089 "/home/claude/cfront-3/src/dcl.cpp"
default :
# 1090 "/home/claude/cfront-3/src/dcl.cpp"
cde :
# 1091 "/home/claude/cfront-3/src/dcl.cpp"
__1nn = insert__5tableFP4nameUc ( __1tbl , __0this , (unsigned char )0 ) ;
__0this -> __O4__4expr.n_table = __1nn -> __O4__4expr.n_table ;
__1nn -> n_redefined__4name = __0this -> n_redefined__4name ;

# 1095 "/home/claude/cfront-3/src/dcl.cpp"
if (Nold ){ 
# 1096 "/home/claude/cfront-3/src/dcl.cpp"
if ((__1nn -> base__4node == 123 )&& (__0this -> base__4node == 85 )){ 
# 1096 "/home/claude/cfront-3/src/dcl.cpp"
const void *__2__X164 ;

# 1097 "/home/claude/cfront-3/src/dcl.cpp"
if ((__1nn -> __O3__4expr.tpdef && __1nn -> __O3__4expr.tpdef -> in_class__4type )&& (__1nn -> __O3__4expr.tpdef -> in_class__4type -> csu__8classdef == 167 ))
# 1098 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1098 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V93 ;

# 1098 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of %s (one in anonymous union)", (const struct ea *)( (__2__X164 = (const void
# 1098 "/home/claude/cfront-3/src/dcl.cpp"
*)__1nn -> __O2__4expr.string ), ( ((& __0__V93 )-> __O1__2ea.p = __2__X164 ), (& __0__V93 )) ) , (const struct ea *)ea0 ,
# 1098 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 1100 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1100 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V94 ;

# 1100 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n declared as identifier andTdef", (const struct ea *)( ((& __0__V94 )-> __O1__2ea.p =
# 1100 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__1nn )), (& __0__V94 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1100 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} 
# 1102 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> n_key__4name = 159 ;
__0this -> __O4__4expr.n_table = 0 ;
goto cde ;
}
if (__1nn -> base__4node == 25 ){ 
# 1107 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1107 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V95 ;

# 1107 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs ofCM%n", (const struct ea *)( ((& __0__V95 )-> __O1__2ea.p =
# 1107 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__1nn )), (& __0__V95 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1107 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }

# 1112 "/home/claude/cfront-3/src/dcl.cpp"
if (__1nn -> __O1__4expr.tp -> base__4node == 141 )
# 1113 "/home/claude/cfront-3/src/dcl.cpp"
goto zzz ;

# 1115 "/home/claude/cfront-3/src/dcl.cpp"
if (check__4typeFP4typeUcT2 ( __0this -> __O1__4expr.tp , __1nn -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) ){ 
# 1116 "/home/claude/cfront-3/src/dcl.cpp"
if
# 1116 "/home/claude/cfront-3/src/dcl.cpp"
(__1nn -> base__4node != 123 )
# 1117 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1117 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V96 ;

# 1117 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V97 ;

# 1117 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V98 ;

# 1117 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of%n;%t and%t", (const struct ea *)( ((& __0__V96 )-> __O1__2ea.p =
# 1117 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__1nn )), (& __0__V96 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V97 , (const void *)__1nn ->
# 1117 "/home/claude/cfront-3/src/dcl.cpp"
__O1__4expr.tp ) , (const struct ea *)__ct__2eaFPCv ( & __0__V98 , (const void *)__0this -> __O1__4expr.tp ) , (const struct
# 1117 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} Cdcl = __1odcl ;
return (struct name *)0 ;
}
if (__0this -> n_sto__4name && (__0this -> n_sto__4name != __1nn -> n_scope__4name )){ 
# 1121 "/home/claude/cfront-3/src/dcl.cpp"
unsigned long __2__X165 ;

# 1122 "/home/claude/cfront-3/src/dcl.cpp"
if ((__0this -> n_sto__4name == 14 )&& (__1nn -> n_scope__4name == 31 )){ 
# 1123 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1123 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V99 ;

# 1123 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%n declared extern after being declared static", (const struct ea *)( ((&
# 1123 "/home/claude/cfront-3/src/dcl.cpp"
__0__V99 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V99 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1123 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 ) ;
goto ext_fudge ;
} }
else 
# 1127 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1127 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V100 ;

# 1127 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V101 ;

# 1127 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V102 ;

# 1127 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n declared as both%k and%k", (const struct ea *)( ((& __0__V100 )-> __O1__2ea.p =
# 1127 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V100 )) , (const struct ea *)( (__2__X165 = __0this -> n_sto__4name ), ( ((
# 1127 "/home/claude/cfront-3/src/dcl.cpp"
((& __0__V101 )-> __O1__2ea.i = __2__X165 ), 0 ) ), (& __0__V101 )) ) , (const struct ea *)__ct__2eaFUl ( &
# 1127 "/home/claude/cfront-3/src/dcl.cpp"
__0__V102 , (unsigned long )(__1nn -> n_sto__4name ?(((unsigned int )__1nn -> n_sto__4name )):(((unsigned int )14 )))) , (const struct ea *)ea0 )
# 1127 "/home/claude/cfront-3/src/dcl.cpp"
;
} }
else if ((__1nn -> n_scope__4name == 31 )&& (__0this -> n_scope__4name == 14 )){ 
# 1130 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1130 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V103 ;

# 1130 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"static%n followed by definition", (const struct ea *)( ((&
# 1130 "/home/claude/cfront-3/src/dcl.cpp"
__0__V103 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V103 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1130 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 ) ;
ext_fudge :
# 1132 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O3__4expr.n_initializer ){ 
# 1133 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> __O3__4expr.n_initializer = 0 ;
}
__0this -> n_sto__4name = 14 ;
} }
else if ((__1nn -> n_sto__4name == 31 )&& (__0this -> n_sto__4name == 31 ))
# 1138 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1138 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V104 ;

# 1138 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"static%n declared twice", (const struct ea *)( ((& __0__V104 )-> __O1__2ea.p =
# 1138 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V104 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1138 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} else { 
# 1140 "/home/claude/cfront-3/src/dcl.cpp"
if ((((__0this -> n_sto__4name == 0 )&& (__1nn -> n_sto__4name == 14 ))&& __0this -> __O3__4expr.n_initializer )&& tconst__4typeFv ( __0this ->
# 1140 "/home/claude/cfront-3/src/dcl.cpp"
__O1__4expr.tp ) )
# 1149 "/home/claude/cfront-3/src/dcl.cpp"
if (vec_const == 0 )
# 1150 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_sto__4name = 14 ;

# 1152 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> n_scope__4name = __1nn -> n_scope__4name ;

# 1154 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1scope ){ 
# 1155 "/home/claude/cfront-3/src/dcl.cpp"
case 108 :
# 1156 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> n_sto__4name != 14 ){ 
# 1157 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1157 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V105 ;

# 1157 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of%n", (const struct ea *)( ((& __0__V105 )-> __O1__2ea.p =
# 1157 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V105 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1157 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
} }
break ;
case 136 :
# 1163 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1163 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V106 ;

# 1163 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoAs%n", (const struct ea *)( ((& __0__V106 )-> __O1__2ea.p =
# 1163 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V106 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1163 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
case 0 :
# 1167 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 1168 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1168 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V107 ;

# 1168 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs ofM%n", (const struct ea *)( ((& __0__V107 )-> __O1__2ea.p =
# 1168 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V107 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1168 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
case 14 :
# 1172 "/home/claude/cfront-3/src/dcl.cpp"
if ((__0this -> n_sto__4name == 0 )|| ((__0this -> n_sto__4name == 14 )&& __0this -> __O3__4expr.n_initializer ))
# 1173 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1174 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1nn -> n_sto__4name ){ 
# 1175 "/home/claude/cfront-3/src/dcl.cpp"
case
# 1175 "/home/claude/cfront-3/src/dcl.cpp"
0 :
# 1176 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1176 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V108 ;

# 1176 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"two definitions of%n", (const struct ea *)( ((& __0__V108 )-> __O1__2ea.p =
# 1176 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V108 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1176 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
return (struct name *)0 ;
case 14 :
# 1180 "/home/claude/cfront-3/src/dcl.cpp"
if ((__0this -> n_sto__4name == 0 )&& __1nn -> __O3__4expr.n_initializer )
# 1181 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1182 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1182 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V109 ;

# 1182 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"two definitions of%n", (const struct ea *)( ((& __0__V109 )-> __O1__2ea.p =
# 1182 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V109 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1182 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
Cdcl = __1odcl ;
} }
else 
# 1186 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> n_sto__4name = 0 ;

# 1188 "/home/claude/cfront-3/src/dcl.cpp"
if ((__1nn -> n_stclass__4name == 31 )&& ((__1nn -> n_scope__4name == 25 )|| (__1nn -> n_scope__4name == 0 )))
# 1190 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1191 "/home/claude/cfront-3/src/dcl.cpp"
if (skiptypedefs__4typeFv ( __0this -> __O1__4expr.tp )
# 1191 "/home/claude/cfront-3/src/dcl.cpp"
-> base__4node == 110 ){ 
# 1192 "/home/claude/cfront-3/src/dcl.cpp"
Ptype __9atp ;

# 1192 "/home/claude/cfront-3/src/dcl.cpp"
__9atp = skiptypedefs__4typeFv ( __1nn -> __O1__4expr.tp ) ;
if (__9atp && (__9atp -> base__4node == 110 ))
# 1194 "/home/claude/cfront-3/src/dcl.cpp"
tsizeof__4typeFi ( (((struct vec *)(((struct vec *)__9atp ))))-> typ__5pvtyp , 0 ) ;
}
else tsizeof__4typeFi ( __1nn -> __O1__4expr.tp , 0 ) ;
}
break ;
} }
}
break ;
} } }
}
__0this -> n_scope__4name = __1nn -> n_scope__4name ;

# 1206 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> __O3__4expr.n_initializer ){ 
# 1207 "/home/claude/cfront-3/src/dcl.cpp"
if (__1nn -> __O3__4expr.n_initializer || __1nn -> n_val__4name )
# 1208 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1208 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V110 ;

# 1208 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoIrs for%n", (const struct ea *)( ((& __0__V110 )-> __O1__2ea.p =
# 1208 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V110 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1208 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} __1nn -> __O3__4expr.n_initializer = __0this -> __O3__4expr.n_initializer ;
}
if (__0this -> __O1__4expr.tp -> base__4node == 110 ){ 
# 1213 "/home/claude/cfront-3/src/dcl.cpp"
Ptype __4ntp ;

# 1213 "/home/claude/cfront-3/src/dcl.cpp"
__4ntp = skiptypedefs__4typeFv ( __1nn -> __O1__4expr.tp ) ;

# 1215 "/home/claude/cfront-3/src/dcl.cpp"
if ((((struct vec *)(((struct vec *)__4ntp ))))-> dim__3vec == 0 )
# 1216 "/home/claude/cfront-3/src/dcl.cpp"
(((struct vec *)(((struct vec *)__4ntp ))))-> dim__3vec = (((struct vec *)(((struct vec *)__0this -> __O1__4expr.tp ))))-> dim__3vec ;
# 1216 "/home/claude/cfront-3/src/dcl.cpp"

# 1217 "/home/claude/cfront-3/src/dcl.cpp"
if ((((struct vec *)(((struct vec *)__4ntp ))))-> size__3vec ){ 
# 1217 "/home/claude/cfront-3/src/dcl.cpp"
unsigned long __2__X166 ;

# 1218 "/home/claude/cfront-3/src/dcl.cpp"
if ((((struct vec *)(((struct vec *)__0this -> __O1__4expr.tp ))))-> size__3vec && ((((struct vec *)(((struct vec *)__4ntp ))))-> size__3vec != (((struct vec *)(((struct vec *)__0this -> __O1__4expr.tp ))))->
# 1218 "/home/claude/cfront-3/src/dcl.cpp"
size__3vec ))
# 1219 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1219 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V111 ;

# 1219 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V112 ;

# 1219 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V113 ;

# 1219 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad array size for%n: %d %dX", (const struct ea *)( ((& __0__V111 )-> __O1__2ea.p =
# 1219 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V111 )) , (const struct ea *)( (__2__X166 = (((struct vec *)(((struct vec *)__0this -> __O1__4expr.tp ))))->
# 1219 "/home/claude/cfront-3/src/dcl.cpp"
size__3vec ), ( (( ((& __0__V112 )-> __O1__2ea.i = __2__X166 ), 0 ) ), (& __0__V112 )) ) , (const
# 1219 "/home/claude/cfront-3/src/dcl.cpp"
struct ea *)__ct__2eaFUl ( & __0__V113 , (unsigned long )(((struct vec *)(((struct vec *)__4ntp ))))-> size__3vec ) , (const struct ea *)ea0 )
# 1219 "/home/claude/cfront-3/src/dcl.cpp"
;
} }
else 
# 1222 "/home/claude/cfront-3/src/dcl.cpp"
(((struct vec *)(((struct vec *)__4ntp ))))-> size__3vec = (((struct vec *)(((struct vec *)__0this -> __O1__4expr.tp ))))-> size__3vec ;
}
}
else { 
# 1226 "/home/claude/cfront-3/src/dcl.cpp"
if ((((((__1scope != 136 )&& (__0this -> n_sto__4name != 14 ))&& ((__0this -> n_sto__4name != 31 )|| ((__1scope != 0 )&& (__1scope !=
# 1226 "/home/claude/cfront-3/src/dcl.cpp"
25 ))))&& (__0this -> __O3__4expr.n_initializer == 0 ))&& (skiptypedefs__4typeFv ( __0this -> __O1__4expr.tp ) -> base__4node == 110 ))&& ((((struct vec *)(((struct vec *)skiptypedefs__4typeFv ( __0this ->
# 1226 "/home/claude/cfront-3/src/dcl.cpp"
__O1__4expr.tp ) ))))-> size__3vec == 0 ))
# 1245 "/home/claude/cfront-3/src/dcl.cpp"
if ((((struct vec *)(((struct vec *)__0this -> __O1__4expr.tp ))))-> dim__3vec == 0 )
# 1246 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1246 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V114 ;

# 1246 "/home/claude/cfront-3/src/dcl.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"dimension missing for array%n", (const struct ea *)(
# 1246 "/home/claude/cfront-3/src/dcl.cpp"
((& __0__V114 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V114 )) , (const struct ea *)ea0 , (const struct
# 1246 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1248 "/home/claude/cfront-3/src/dcl.cpp"
if (((__1scope == 14 )&& (__0this -> n_sto__4name == 0 ))&& is_const_object__4typeFv ( __0this -> __O1__4expr.tp ) )
# 1255 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> n_sto__4name = (__0this -> n_sto__4name =
# 1255 "/home/claude/cfront-3/src/dcl.cpp"
31 );
}

# 1258 "/home/claude/cfront-3/src/dcl.cpp"
zzz :
# 1259 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> base__4node != 123 ){ 
# 1260 "/home/claude/cfront-3/src/dcl.cpp"
Ptype __3t ;

# 1260 "/home/claude/cfront-3/src/dcl.cpp"
__3t = __1nn -> __O1__4expr.tp ;

# 1262 "/home/claude/cfront-3/src/dcl.cpp"
if (__3t -> base__4node == 97 ){ 
# 1263 "/home/claude/cfront-3/src/dcl.cpp"
Ptype __4tt ;

# 1263 "/home/claude/cfront-3/src/dcl.cpp"
__4tt = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype -> __O1__4expr.tp ;
if (__4tt -> base__4node == 108 )
# 1265 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> __O1__4expr.tp = (__3t = __4tt );
}

# 1268 "/home/claude/cfront-3/src/dcl.cpp"
switch (__3t -> base__4node ){ 
# 1269 "/home/claude/cfront-3/src/dcl.cpp"
case 108 :
# 1270 "/home/claude/cfront-3/src/dcl.cpp"
case 76 :
# 1271 "/home/claude/cfront-3/src/dcl.cpp"
break ;
default :
# 1273 "/home/claude/cfront-3/src/dcl.cpp"
fake_sizeof = 1 ;
switch (__1nn -> n_stclass__4name ){ 
# 1275 "/home/claude/cfront-3/src/dcl.cpp"
default :
# 1276 "/home/claude/cfront-3/src/dcl.cpp"
if (__1nn -> n_scope__4name != 136 ){ 
# 1277 "/home/claude/cfront-3/src/dcl.cpp"
int __6x ;
int __6y ;

# 1277 "/home/claude/cfront-3/src/dcl.cpp"
__6x = align__4typeFv ( __3t ) ;
__6y = tsizeof__4typeFi ( __3t , 0 ) ;

# 1280 "/home/claude/cfront-3/src/dcl.cpp"
if (max_align < __6x )
# 1281 "/home/claude/cfront-3/src/dcl.cpp"
max_align = __6x ;

# 1283 "/home/claude/cfront-3/src/dcl.cpp"
while (0 < bit_offset ){ 
# 1284 "/home/claude/cfront-3/src/dcl.cpp"
byte_offset ++ ;
bit_offset -= BI_IN_BYTE ;
}
bit_offset = 0 ;

# 1289 "/home/claude/cfront-3/src/dcl.cpp"
if (byte_offset && (1 < __6x ))
# 1290 "/home/claude/cfront-3/src/dcl.cpp"
byte_offset = ((((byte_offset - 1 )/ __6x )* __6x )+ __6x );
__1nn -> n_offset__4name = byte_offset ;
byte_offset += __6y ;
}
break ;
case 31 :
# 1296 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> n_sto__4name != 14 ){ 
# 1296 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X167 ;

# 1296 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X168 ;

# 1297 "/home/claude/cfront-3/src/dcl.cpp"
if (__1nn -> n_scope__4name && (__1nn -> n_scope__4name != 25 ))
# 1299 "/home/claude/cfront-3/src/dcl.cpp"
tsizeof__4typeFi ( __3t , 0 ) ;
else 
# 1301 "/home/claude/cfront-3/src/dcl.cpp"
if (((__1tbl -> t_name__5table == 0 )|| (__1tbl == gtbl ))|| (! ( (__1__X167 = (((struct classdef *)(((struct classdef *)__1tbl -> t_name__5table ->
# 1301 "/home/claude/cfront-3/src/dcl.cpp"
__O1__4expr.tp ))))), ( (__1__X168 = (((struct classdef *)(((struct classdef *)__1nn -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))))), ( ((__1__X167 == __1__X168 )?1 :((__1__X167 && __1__X168 )?(((int )same_class__8classdefFP8classdefi (
# 1301 "/home/claude/cfront-3/src/dcl.cpp"
__1__X167 , __1__X168 , 0 ) )):0 ))) ) ) ))
# 1304 "/home/claude/cfront-3/src/dcl.cpp"
tsizeof__4typeFi ( __3t , 0 ) ;
}
}
fake_sizeof = 0 ;
}
}

# 1311 "/home/claude/cfront-3/src/dcl.cpp"
{ Ptype __3t ;
int __3const_old ;
bit __3vec_seen ;
Pexpr __3init ;

# 1316 "/home/claude/cfront-3/src/dcl.cpp"
bit __3td_const ;

# 1311 "/home/claude/cfront-3/src/dcl.cpp"
__3t = __1nn -> __O1__4expr.tp ;
__3const_old = const_save ;
__3vec_seen = 0 ;
__3init = __0this -> __O3__4expr.n_initializer ;

# 1316 "/home/claude/cfront-3/src/dcl.cpp"
__3td_const = 0 ;
lll :
# 1318 "/home/claude/cfront-3/src/dcl.cpp"
switch (__3t -> base__4node ){ 
# 1319 "/home/claude/cfront-3/src/dcl.cpp"
case 119 :
# 1320 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1321 "/home/claude/cfront-3/src/dcl.cpp"
Pname __5cn ;
Pclass __5cl ;
Pname __5ctor ;
Pname __5dtor ;
int __5stct ;

# 1321 "/home/claude/cfront-3/src/dcl.cpp"
__5cn = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype ;
__5cl = (((struct classdef *)(((struct classdef *)__5cn -> __O1__4expr.tp ))));
__5ctor = ( __5cl -> c_ctor__8classdef ) ;
__5dtor = ( __5cl -> c_dtor__8classdef ) ;
__5stct = 0 ;
if (__5dtor ){ 
# 1327 "/home/claude/cfront-3/src/dcl.cpp"
Pstmt __6dls ;

# 1329 "/home/claude/cfront-3/src/dcl.cpp"
if (! check_static_pt__FP4name ( __1nn ) ){ 
# 1330 "/home/claude/cfront-3/src/dcl.cpp"
assign__4nameFv ( __1nn ) ;
( (__1nn -> n_used__4name ++ ), (((void )0 ))) ;
goto ggg ;
}

# 1336 "/home/claude/cfront-3/src/dcl.cpp"
if (__5dtor -> n_scope__4name != 25 ){ 
# 1337 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1nn -> n_scope__4name ){ 
# 1338 "/home/claude/cfront-3/src/dcl.cpp"
case 136 :
# 1339 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 1340 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 1341 "/home/claude/cfront-3/src/dcl.cpp"
break ;
default :
# 1343 "/home/claude/cfront-3/src/dcl.cpp"
check_visibility__FP4nameT1P8classdefP5tableT1 ( __5dtor , (struct name *)0 , __5cl , __1tbl , cc -> nof__11dcl_context ) ;
}
}

# 1347 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1nn -> n_scope__4name ){ 
# 1348 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 1349 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 1350 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> n_stclass__4name == 31 ){ 
# 1351 "/home/claude/cfront-3/src/dcl.cpp"
Pclass __8cl ;

# 1351 "/home/claude/cfront-3/src/dcl.cpp"
__8cl = (((struct classdef *)(((struct classdef *)__1nn -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))));
if (__8cl -> defined__4type & 01 )
# 1353 "/home/claude/cfront-3/src/dcl.cpp"
goto dtdt ;
}
break ;
case 14 :
# 1357 "/home/claude/cfront-3/src/dcl.cpp"
if ((__3init == 0 )&& (__0this -> n_sto__4name == 14 ))
# 1358 "/home/claude/cfront-3/src/dcl.cpp"
break ;

# 1360 "/home/claude/cfront-3/src/dcl.cpp"
case 31 :
# 1361 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1362 "/home/claude/cfront-3/src/dcl.cpp"
Pexpr __8c ;
dtdt :
# 1366 "/home/claude/cfront-3/src/dcl.cpp"
if (stat_init && (__1scope == 137 )){ 
# 1367 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> n_scope__4name = 137 ;
goto ggg ;
}

# 1371 "/home/claude/cfront-3/src/dcl.cpp"
if (__1nn -> lex_level__4name && (__1nn -> n_sto__4name == 31 )){ 
# 1372 "/home/claude/cfront-3/src/dcl.cpp"
if (__5ctor == 0 )
# 1373 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1373 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V115 ;

# 1373 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V116 ;

# 1373 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V117 ;

# 1373 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V118 ;

# 1373 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"local static%n has%n but noK(add%n::%n())", (const struct ea *)( ((&
# 1373 "/home/claude/cfront-3/src/dcl.cpp"
__0__V115 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V115 )) , (const struct ea *)( ((& __0__V116 )-> __O1__2ea.p =
# 1373 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__5dtor )), (& __0__V116 )) , (const struct ea *)( ((& __0__V117 )-> __O1__2ea.p = ((const void
# 1373 "/home/claude/cfront-3/src/dcl.cpp"
*)__5cn )), (& __0__V117 )) , (const struct ea *)( ((& __0__V118 )-> __O1__2ea.p = ((const void *)__5cn )), (&
# 1373 "/home/claude/cfront-3/src/dcl.cpp"
__0__V118 )) ) ;
} goto static_init ;
}

# 1377 "/home/claude/cfront-3/src/dcl.cpp"
{ Ptable __8otbl ;

# 1378 "/home/claude/cfront-3/src/dcl.cpp"
struct estmt *__0__X169 ;

# 1378 "/home/claude/cfront-3/src/dcl.cpp"
struct loc __2__X170 ;

# 1377 "/home/claude/cfront-3/src/dcl.cpp"
__8otbl = __1tbl ;

# 1381 "/home/claude/cfront-3/src/dcl.cpp"
if (std_tbl == 0 )
# 1382 "/home/claude/cfront-3/src/dcl.cpp"
std_tbl = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )8 , gtbl , (struct name *)0 ) ;
__1tbl = std_tbl ;
if (__3vec_seen ){ 
# 1385 "/home/claude/cfront-3/src/dcl.cpp"
__8c = cdvec__FP4nameP4exprP8classdefT1iN22 ( vec_del_fct , (struct expr *)__1nn , __5cl , __5dtor , 0 , zero , (struct expr *)0 ) ;
# 1385 "/home/claude/cfront-3/src/dcl.cpp"

# 1386 "/home/claude/cfront-3/src/dcl.cpp"
}
else { 
# 1388 "/home/claude/cfront-3/src/dcl.cpp"
__8c = call_dtor__FP4exprN21iT1 ( (struct expr *)__1nn , (struct expr *)__5dtor , (struct expr *)0 , 45 , one ) ;
}
__8c -> __O1__4expr.tp = (struct type *)any_type ;
__6dls = (struct stmt *)( (__0__X169 = 0 ), ( (__2__X170 = __1nn -> where__4name ), ( ((__0__X169 || (__0__X169 = (struct estmt *)__nw__4stmtSFUl (
# 1391 "/home/claude/cfront-3/src/dcl.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X169 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X169 ), ((unsigned char )72 ), __2__X170 ,
# 1391 "/home/claude/cfront-3/src/dcl.cpp"
((struct stmt *)0 )) ), (__0__X169 -> __O2__4stmt.e = __8c )) :0 ), __0__X169 ) ) ) ;

# 1393 "/home/claude/cfront-3/src/dcl.cpp"
if (st_dlist )
# 1394 "/home/claude/cfront-3/src/dcl.cpp"
__6dls -> s_list__4stmt = st_dlist ;
st_dlist = __6dls ;
__1tbl = __8otbl ;

# 1396 "/home/claude/cfront-3/src/dcl.cpp"
}
}
}
}

# 1402 "/home/claude/cfront-3/src/dcl.cpp"
static_init :
# 1403 "/home/claude/cfront-3/src/dcl.cpp"
if (__5ctor ){ 
# 1404 "/home/claude/cfront-3/src/dcl.cpp"
Pexpr __6oo ;

# 1404 "/home/claude/cfront-3/src/dcl.cpp"
__6oo = (struct expr *)__1nn ;
{ { int __6vi ;

# 1405 "/home/claude/cfront-3/src/dcl.cpp"
__6vi = __3vec_seen ;

# 1405 "/home/claude/cfront-3/src/dcl.cpp"
for(;__6vi ;__6vi -- ) 
# 1406 "/home/claude/cfront-3/src/dcl.cpp"
__6oo = contents__4exprFv ( __6oo ) ;
{ int __6sti ;

# 1407 "/home/claude/cfront-3/src/dcl.cpp"
__6sti = 0 ;
if (! check_static_pt__FP4name ( __1nn ) ){ 
# 1409 "/home/claude/cfront-3/src/dcl.cpp"
assign__4nameFv ( __1nn ) ;
( (__1nn -> n_used__4name ++ ), (((void )0 ))) ;
goto ggg ;
}
switch (__1nn -> n_scope__4name ){ 
# 1414 "/home/claude/cfront-3/src/dcl.cpp"
case 14 :
# 1415 "/home/claude/cfront-3/src/dcl.cpp"
if ((__3init == 0 )&& (__0this -> n_sto__4name == 14 ))
# 1416 "/home/claude/cfront-3/src/dcl.cpp"
goto ggg ;
case 31 :
# 1418 "/home/claude/cfront-3/src/dcl.cpp"
if (__1tbl == gtbl )
# 1419 "/home/claude/cfront-3/src/dcl.cpp"
__6sti = 1 ;
else 
# 1421 "/home/claude/cfront-3/src/dcl.cpp"
__5stct = 1 ;
default :
# 1423 "/home/claude/cfront-3/src/dcl.cpp"
if (__3vec_seen && __3init ){ 
# 1424 "/home/claude/cfront-3/src/dcl.cpp"
if (1 < __3vec_seen )
# 1425 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1425 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V119 ;

# 1425 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V120 ;

# 1425 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"Ir for multi-dimensional array%n ofOs ofC%tWK", (const struct ea *)( ((&
# 1425 "/home/claude/cfront-3/src/dcl.cpp"
__0__V119 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V119 )) , (const struct ea *)( ((& __0__V120 )-> __O1__2ea.p =
# 1425 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__5cl )), (& __0__V120 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 1427 "/home/claude/cfront-3/src/dcl.cpp"
if (__6sti ){ 
# 1428 "/home/claude/cfront-3/src/dcl.cpp"
if (sti_tbl == 0 )
# 1429 "/home/claude/cfront-3/src/dcl.cpp"
sti_tbl = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )8 , gtbl ,
# 1429 "/home/claude/cfront-3/src/dcl.cpp"
(struct name *)0 ) ;
const_save = 1 ;
((void )co_array_init__FP4nameP5table ( __1nn , sti_tbl ) );

# 1433 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> __O1__4expr.tp = __1nn -> __O1__4expr.tp ;
const_save = 0 ;
__0this -> __O3__4expr.n_initializer = (__3init = 0 );
}
else { 
# 1438 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> __O3__4expr.n_initializer = (__3init = co_array_init__FP4nameP5table ( __1nn , __1tbl ) );

# 1440 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> __O1__4expr.tp = __1nn -> __O1__4expr.tp ;
if (__5stct )
# 1445 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = (__3init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )186 , __3init , (struct
# 1445 "/home/claude/cfront-3/src/dcl.cpp"
expr *)0 ) ));
}
}
goto ggg ;
}
break ;
case 25 :
# 1452 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 1453 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> n_stclass__4name == 31 ){ 
# 1454 "/home/claude/cfront-3/src/dcl.cpp"
if (__3vec_seen && __0this -> __O3__4expr.n_initializer ){ 
# 1455 "/home/claude/cfront-3/src/dcl.cpp"
if (1 < __3vec_seen )
# 1456 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1456 "/home/claude/cfront-3/src/dcl.cpp"
struct
# 1456 "/home/claude/cfront-3/src/dcl.cpp"
ea __0__V121 ;

# 1456 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V122 ;

# 1456 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"Ir for multi-dimensional array%n ofOs ofC%tWK", (const struct ea *)( ((&
# 1456 "/home/claude/cfront-3/src/dcl.cpp"
__0__V121 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V121 )) , (const struct ea *)( ((& __0__V122 )-> __O1__2ea.p =
# 1456 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__5cl )), (& __0__V122 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 1458 "/home/claude/cfront-3/src/dcl.cpp"
if (sti_tbl == 0 )
# 1459 "/home/claude/cfront-3/src/dcl.cpp"
sti_tbl = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )8 , gtbl , (struct name *)0 )
# 1459 "/home/claude/cfront-3/src/dcl.cpp"
;
const_save = 1 ;
((void )co_array_init__FP4nameP5table ( __1nn , sti_tbl ) );

# 1463 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> __O1__4expr.tp = __1nn -> __O1__4expr.tp ;
const_save = 0 ;
__0this -> __O3__4expr.n_initializer = (__3init = 0 );
}
}
else { 
# 1470 "/home/claude/cfront-3/src/dcl.cpp"
Pclass __9cl ;

# 1470 "/home/claude/cfront-3/src/dcl.cpp"
__9cl = (((struct classdef *)(((struct classdef *)__1nn -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))));
if (__9cl -> defined__4type & 01 ){ 
# 1472 "/home/claude/cfront-3/src/dcl.cpp"
__6sti = 1 ;
break ;
}
}
}

# 1478 "/home/claude/cfront-3/src/dcl.cpp"
if (__3vec_seen ){ 
# 1479 "/home/claude/cfront-3/src/dcl.cpp"
Pname __8c ;

# 1479 "/home/claude/cfront-3/src/dcl.cpp"
__8c = has_ictor__8classdefFv ( __5cl ) ;
if (__8c == 0 )
# 1481 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1481 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V123 ;

# 1481 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"array ofC%n that does not have aK taking noAs", (const struct ea *)( ((& __0__V123 )-> __O1__2ea.p =
# 1481 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__5cn )), (& __0__V123 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1481 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} else { 
# 1483 "/home/claude/cfront-3/src/dcl.cpp"
Pname __9ctor ;

# 1483 "/home/claude/cfront-3/src/dcl.cpp"
__9ctor = ( __5cl -> c_ctor__8classdef ) ;
if (__9ctor && (((! __1tbl -> t_name__5table )|| (! __1tbl -> t_name__5table -> __O1__4expr.tp ))|| (__1tbl -> t_name__5table -> __O1__4expr.tp -> base__4node != 6 ))){
# 1484 "/home/claude/cfront-3/src/dcl.cpp"

# 1485 "/home/claude/cfront-3/src/dcl.cpp"
Pexpr __10e ;

# 1485 "/home/claude/cfront-3/src/dcl.cpp"
__10e = call_ctor__FP5tableP4exprN22iT2 ( __1tbl , (struct expr *)0 , (struct expr *)__9ctor , (struct expr *)0 , 44 , (struct expr *)0 ) ;
}
if ((((struct fct *)(((struct fct *)__8c -> __O1__4expr.tp ))))-> nargs__3fct )
# 1488 "/home/claude/cfront-3/src/dcl.cpp"
{ if (! ( __5cl -> c_vtor__8classdef ) )make_vec_ctor__8classdefFP4name ( __5cl , __8c )
# 1488 "/home/claude/cfront-3/src/dcl.cpp"
;

# 1488 "/home/claude/cfront-3/src/dcl.cpp"
}
}
}

# 1492 "/home/claude/cfront-3/src/dcl.cpp"
case 136 :
# 1493 "/home/claude/cfront-3/src/dcl.cpp"
goto ggg ;
}

# 1496 "/home/claude/cfront-3/src/dcl.cpp"
const_save = 1 ;
assign__4nameFv ( __1nn ) ;
{ Ptable __6otbl ;

# 1498 "/home/claude/cfront-3/src/dcl.cpp"
__6otbl = __1tbl ;
if (__6sti ){ 
# 1502 "/home/claude/cfront-3/src/dcl.cpp"
if (sti_tbl == 0 )
# 1503 "/home/claude/cfront-3/src/dcl.cpp"
sti_tbl = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )8 , gtbl , (struct name *)0 ) ;
# 1503 "/home/claude/cfront-3/src/dcl.cpp"

# 1504 "/home/claude/cfront-3/src/dcl.cpp"
__1tbl = sti_tbl ;
if (__0this -> n_sto__4name == 14 )
# 1506 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> n_sto__4name = (__0this -> n_sto__4name = 0 );
}

# 1509 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init ){ 
# 1510 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init -> base__4node == 157 ){ 
# 1511 "/home/claude/cfront-3/src/dcl.cpp"
switch (__3init -> __O4__4expr.tp2 -> base__4node ){ 
# 1511 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X171 ;

# 1511 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X172 ;

# 1512 "/home/claude/cfront-3/src/dcl.cpp"
case 6 :
# 1513 "/home/claude/cfront-3/src/dcl.cpp"
if (! ( (__1__X171 = (((struct classdef *)(((struct classdef *)__3init -> __O4__4expr.tp2 ))))), ( (__1__X172 = __5cl ), ( ((__1__X171 ==
# 1513 "/home/claude/cfront-3/src/dcl.cpp"
__1__X172 )?1 :((__1__X171 && __1__X172 )?(((int )same_class__8classdefFP8classdefi ( __1__X171 , __1__X172 , 0 ) )):0 ))) ) ) )
# 1514 "/home/claude/cfront-3/src/dcl.cpp"
goto inin ;
break ;
default :
# 1517 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1518 "/home/claude/cfront-3/src/dcl.cpp"
Pname __10n2 ;

# 1519 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X173 ;

# 1519 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X174 ;

# 1518 "/home/claude/cfront-3/src/dcl.cpp"
__10n2 = is_cl_obj__4typeFv ( __3init -> __O4__4expr.tp2 ) ;
if ((__10n2 == 0 )|| (! ( (__1__X173 = (((struct classdef *)(((struct classdef *)__10n2 -> __O1__4expr.tp ))))), ( (__1__X174 = __5cl ), (
# 1519 "/home/claude/cfront-3/src/dcl.cpp"
((__1__X173 == __1__X174 )?1 :((__1__X173 && __1__X174 )?(((int )same_class__8classdefFP8classdefi ( __1__X173 , __1__X174 , 0 ) )):0 ))) ) ) ))
# 1520 "/home/claude/cfront-3/src/dcl.cpp"
goto inin ;
}
}

# 1524 "/home/claude/cfront-3/src/dcl.cpp"
{ Pexpr __8ee ;

# 1524 "/home/claude/cfront-3/src/dcl.cpp"
__8ee = __3init -> __O2__4expr.e1 ;
if (__8ee && (__3vec_seen == 0 )){ 
# 1526 "/home/claude/cfront-3/src/dcl.cpp"
switch (__8ee -> base__4node ){ 
# 1527 "/home/claude/cfront-3/src/dcl.cpp"
case 109 :
# 1528 "/home/claude/cfront-3/src/dcl.cpp"
__3init = __8ee ;
goto inin ;
case 140 :
# 1531 "/home/claude/cfront-3/src/dcl.cpp"
if ((__8ee -> __O2__4expr.e1 -> base__4node == 109 )&& (__8ee -> __O3__4expr.e2 == 0 ))
# 1535 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1536 "/home/claude/cfront-3/src/dcl.cpp"
__3init = __8ee -> __O2__4expr.e1 ;
goto inin ;
}
}
}

# 1542 "/home/claude/cfront-3/src/dcl.cpp"
__3init -> __O3__4expr.e2 = __6oo ;
__3init = typ__4exprFP5table ( __3init , __1tbl ) ;

# 1545 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init -> base__4node == 147 ){ 
# 1546 "/home/claude/cfront-3/src/dcl.cpp"
switch (__3init -> __O4__4expr.tp2 -> base__4node ){ 
# 1546 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X175 ;

# 1546 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X176 ;

# 1547 "/home/claude/cfront-3/src/dcl.cpp"
case 6 :
# 1548 "/home/claude/cfront-3/src/dcl.cpp"
if (! ( (__1__X175 = (((struct classdef *)(((struct classdef *)__3init -> __O4__4expr.tp2 ))))), ( (__1__X176 = __5cl ), ( ((__1__X175 ==
# 1548 "/home/claude/cfront-3/src/dcl.cpp"
__1__X176 )?1 :((__1__X175 && __1__X176 )?(((int )same_class__8classdefFP8classdefi ( __1__X175 , __1__X176 , 0 ) )):0 ))) ) ) )
# 1549 "/home/claude/cfront-3/src/dcl.cpp"
goto inin ;
break ;
default :
# 1552 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1553 "/home/claude/cfront-3/src/dcl.cpp"
Pname __11n2 ;

# 1554 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X177 ;

# 1554 "/home/claude/cfront-3/src/dcl.cpp"
struct classdef *__1__X178 ;

# 1553 "/home/claude/cfront-3/src/dcl.cpp"
__11n2 = is_cl_obj__4typeFv ( __3init -> __O4__4expr.tp2 ) ;
if ((__11n2 == 0 )|| (! ( (__1__X177 = (((struct classdef *)(((struct classdef *)__11n2 -> __O1__4expr.tp ))))), ( (__1__X178 = __5cl ), (
# 1554 "/home/claude/cfront-3/src/dcl.cpp"
((__1__X177 == __1__X178 )?1 :((__1__X177 && __1__X178 )?(((int )same_class__8classdefFP8classdefi ( __1__X177 , __1__X178 , 0 ) )):0 ))) ) ) ))
# 1555 "/home/claude/cfront-3/src/dcl.cpp"
goto inin ;
}
}
}

# 1558 "/home/claude/cfront-3/src/dcl.cpp"
}
}
else { 
# 1561 "/home/claude/cfront-3/src/dcl.cpp"
inin :
# 1562 "/home/claude/cfront-3/src/dcl.cpp"
__3init = typ__4exprFP5table ( __3init , __1tbl ) ;
if ((__3init -> base__4node == 147 )&& (check__4typeFP4typeUcT2 ( __1nn -> __O1__4expr.tp , __3init -> __O1__4expr.tp , (unsigned char )0 , (unsigned char
# 1563 "/home/claude/cfront-3/src/dcl.cpp"
)0 ) == 0 ))
# 1568 "/home/claude/cfront-3/src/dcl.cpp"
((void )replace_temp__FP4exprT1 ( __3init , address__4exprFv ( (struct expr *)__1nn ) ) );
else 
# 1570 "/home/claude/cfront-3/src/dcl.cpp"
__3init = class_init__FP4exprP4typeT1P5table ( (struct expr *)__1nn , __1nn -> __O1__4expr.tp , __3init , __1tbl ) ;
}
}
else if (__3vec_seen == 0 ){ 
# 1573 "/home/claude/cfront-3/src/dcl.cpp"
struct texpr *__0__X179 ;

# 1574 "/home/claude/cfront-3/src/dcl.cpp"
__3init = (struct expr *)( (__0__X179 = 0 ), ( ((__0__X179 || (__0__X179 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 1574 "/home/claude/cfront-3/src/dcl.cpp"
))?( (__0__X179 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X179 ), ((unsigned char )157 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 1574 "/home/claude/cfront-3/src/dcl.cpp"
(__0__X179 -> __O4__4expr.tp2 = ((struct type *)__5cl ))) :0 ), __0__X179 ) ) ;
__3init -> __O3__4expr.e2 = __6oo ;
__3init = typ__4exprFP5table ( __3init , __1tbl ) ;
}

# 1579 "/home/claude/cfront-3/src/dcl.cpp"
{ Pname __6c ;
if (__3vec_seen ){ 
# 1581 "/home/claude/cfront-3/src/dcl.cpp"
__6c = has_ictor__8classdefFv ( __5cl ) ;
if (__6c == 0 )
# 1583 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1583 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V124 ;

# 1583 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"array ofC%n that does not have aK taking noAs", (const struct ea *)( ((& __0__V124 )-> __O1__2ea.p =
# 1583 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__5cn )), (& __0__V124 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1583 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} else { 
# 1585 "/home/claude/cfront-3/src/dcl.cpp"
Pname __8ctor ;

# 1585 "/home/claude/cfront-3/src/dcl.cpp"
__8ctor = ( __5cl -> c_ctor__8classdef ) ;
if (__8ctor && (((! __1tbl -> t_name__5table )|| (! __1tbl -> t_name__5table -> __O1__4expr.tp ))|| (__1tbl -> t_name__5table -> __O1__4expr.tp -> base__4node != 6 ))){
# 1586 "/home/claude/cfront-3/src/dcl.cpp"

# 1587 "/home/claude/cfront-3/src/dcl.cpp"
Pexpr __9e ;

# 1587 "/home/claude/cfront-3/src/dcl.cpp"
__9e = call_ctor__FP5tableP4exprN22iT2 ( __1tbl , (struct expr *)0 , (struct expr *)__8ctor , (struct expr *)0 , 44 , (struct expr *)0 ) ;
}
if ((((struct fct *)(((struct fct *)__6c -> __O1__4expr.tp ))))-> nargs__3fct )
# 1590 "/home/claude/cfront-3/src/dcl.cpp"
{ if (! ( __5cl -> c_vtor__8classdef ) )make_vec_ctor__8classdefFP4name ( __5cl , __6c )
# 1590 "/home/claude/cfront-3/src/dcl.cpp"
;

# 1590 "/home/claude/cfront-3/src/dcl.cpp"
}
}
}

# 1594 "/home/claude/cfront-3/src/dcl.cpp"
if (__5stct ){ 
# 1595 "/home/claude/cfront-3/src/dcl.cpp"
if ((__1tbl != gtbl )&& (__1nn -> n_sto__4name == 14 )){ 
# 1596 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1596 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V125 ;

# 1596 "/home/claude/cfront-3/src/dcl.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"Id local extern%n", (const struct ea *)(
# 1596 "/home/claude/cfront-3/src/dcl.cpp"
((& __0__V125 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V125 )) , (const struct ea *)ea0 , (const struct
# 1596 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
__3init = 0 ;
} }
else if (__3init ){ 
# 1600 "/home/claude/cfront-3/src/dcl.cpp"
if ((__3init -> base__4node == 111 )&& (__3init -> __O2__4expr.e1 -> base__4node == 146 ))
# 1602 "/home/claude/cfront-3/src/dcl.cpp"
__3init -> base__4node = 186 ;
# 1602 "/home/claude/cfront-3/src/dcl.cpp"
else 
# 1603 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1604 "/home/claude/cfront-3/src/dcl.cpp"
__3init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1nn , __3init ) ;
__3init -> __O1__4expr.tp = __3init -> __O2__4expr.e1 -> __O1__4expr.tp ;
__3init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )186 , __3init , (struct expr *)0 ) ;
__3init -> __O1__4expr.tp = __3init -> __O2__4expr.e1 -> __O1__4expr.tp ;
}
}
else 
# 1609 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1610 "/home/claude/cfront-3/src/dcl.cpp"
if ((__0this -> __O1__4expr.tp -> base__4node == 110 )&& (((struct vec *)(((struct vec *)__0this -> __O1__4expr.tp ))))-> size__3vec ){ 
# 1611 "/home/claude/cfront-3/src/dcl.cpp"
if (1 <
# 1611 "/home/claude/cfront-3/src/dcl.cpp"
__3vec_seen )
# 1612 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1612 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V126 ;

# 1612 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"implicit staticIr for multi-dimensional array ofOs ofC%tWK", (const struct ea *)( ((&
# 1612 "/home/claude/cfront-3/src/dcl.cpp"
__0__V126 )-> __O1__2ea.p = ((const void *)__5cl )), (& __0__V126 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1612 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 ) ;
} else { 
# 1614 "/home/claude/cfront-3/src/dcl.cpp"
Pexpr __10ilist ;

# 1614 "/home/claude/cfront-3/src/dcl.cpp"
__10ilist = 0 ;
{ { int __10i ;

# 1615 "/home/claude/cfront-3/src/dcl.cpp"
__10i = (((struct vec *)(((struct vec *)__0this -> __O1__4expr.tp ))))-> size__3vec ;

# 1615 "/home/claude/cfront-3/src/dcl.cpp"
for(;__10i > 0 ;__10i -- ) { 
# 1616 "/home/claude/cfront-3/src/dcl.cpp"
Pexpr __11e ;

# 1617 "/home/claude/cfront-3/src/dcl.cpp"
struct texpr *__0__X180 ;

# 1616 "/home/claude/cfront-3/src/dcl.cpp"
__11e = (struct expr *)( (__0__X180 = 0 ), ( ((__0__X180 || (__0__X180 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 1616 "/home/claude/cfront-3/src/dcl.cpp"
))?( (__0__X180 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X180 ), ((unsigned char )157 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 1616 "/home/claude/cfront-3/src/dcl.cpp"
(__0__X180 -> __O4__4expr.tp2 = ((struct type *)__5cl ))) :0 ), __0__X180 ) ) ;
__10ilist = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __11e , __10ilist ) ;
}
__1nn -> __O3__4expr.n_initializer = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , __10ilist , (struct expr *)0 ) ;
__3init = co_array_init__FP4nameP5table ( __1nn , __1tbl ) ;

# 1622 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> __O1__4expr.tp = __1nn -> __O1__4expr.tp ;

# 1626 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = (__3init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )186 , __3init , (struct expr *)0 )
# 1626 "/home/claude/cfront-3/src/dcl.cpp"
));

# 1626 "/home/claude/cfront-3/src/dcl.cpp"
}

# 1626 "/home/claude/cfront-3/src/dcl.cpp"
}
}
}
else 
# 1630 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1630 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V127 ;

# 1630 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V128 ;

# 1630 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"local staticC%n (%t)", (const struct ea *)( ((&
# 1630 "/home/claude/cfront-3/src/dcl.cpp"
__0__V127 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V127 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V128 , (const
# 1630 "/home/claude/cfront-3/src/dcl.cpp"
void *)__0this -> __O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}

# 1634 "/home/claude/cfront-3/src/dcl.cpp"
if (__6sti ){ 
# 1635 "/home/claude/cfront-3/src/dcl.cpp"
if (__3vec_seen ){ 
# 1636 "/home/claude/cfront-3/src/dcl.cpp"
if ((__0this -> n_stclass__4name == 31 )&& __0this -> __O3__4expr.n_initializer ){ 
# 1637 "/home/claude/cfront-3/src/dcl.cpp"
const_save = 1 ;
((void )co_array_init__FP4nameP5table ( __1nn , sti_tbl ) );

# 1640 "/home/claude/cfront-3/src/dcl.cpp"
__0this -> __O1__4expr.tp = __1nn -> __O1__4expr.tp ;
const_save = 0 ;
__0this -> __O3__4expr.n_initializer = (__3init = 0 );
goto ggg ;
}

# 1646 "/home/claude/cfront-3/src/dcl.cpp"
{ Pname __8vctor ;

# 1646 "/home/claude/cfront-3/src/dcl.cpp"
__8vctor = ( __5cl -> c_vtor__8classdef ) ;
__3init = cdvec__FP4nameP4exprP8classdefT1iN22 ( vec_new_fct , (struct expr *)__1nn , __5cl , __8vctor ?__8vctor :__6c , -1, (struct expr *)0 , (struct expr *)0 ) ;
__3init -> __O1__4expr.tp = (struct type *)any_type ;

# 1648 "/home/claude/cfront-3/src/dcl.cpp"
}
}
else { 
# 1651 "/home/claude/cfront-3/src/dcl.cpp"
switch (__3init -> base__4node ){ 
# 1652 "/home/claude/cfront-3/src/dcl.cpp"
case 111 :
# 1653 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init -> __O2__4expr.e1 -> base__4node == 146 ){ 
# 1654 "/home/claude/cfront-3/src/dcl.cpp"
Pname __10fn ;

# 1654 "/home/claude/cfront-3/src/dcl.cpp"
__10fn = __3init -> __O2__4expr.e1 -> __O4__4expr.fct_name ;
if ((__10fn == 0 )|| (__10fn -> n_oper__4name != 161 ))
# 1656 "/home/claude/cfront-3/src/dcl.cpp"
goto as ;
__3init = __3init -> __O2__4expr.e1 ;
break ;
}
goto as ;
case 147 :
# 1662 "/home/claude/cfront-3/src/dcl.cpp"
__3init = __3init -> __O2__4expr.e1 ;

# 1664 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init -> __O1__4expr.tp == 0 )
# 1665 "/home/claude/cfront-3/src/dcl.cpp"
__3init -> __O1__4expr.tp = (struct type *)any_type ;
break ;
case 70 :
# 1668 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init -> __O2__4expr.e1 == (((struct expr *)__1nn )))
# 1669 "/home/claude/cfront-3/src/dcl.cpp"
break ;
as :
# 1671 "/home/claude/cfront-3/src/dcl.cpp"
default :
# 1672 "/home/claude/cfront-3/src/dcl.cpp"
__3init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1nn , __3init ) ;
}
}
{ Pstmt __7ist ;

# 1676 "/home/claude/cfront-3/src/dcl.cpp"
struct estmt *__0__X181 ;

# 1676 "/home/claude/cfront-3/src/dcl.cpp"
struct loc __2__X182 ;

# 1675 "/home/claude/cfront-3/src/dcl.cpp"
__7ist = (struct stmt *)( (__0__X181 = 0 ), ( (__2__X182 = __1nn -> where__4name ), ( ((__0__X181 || (__0__X181 = (struct estmt *)__nw__4stmtSFUl (
# 1675 "/home/claude/cfront-3/src/dcl.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X181 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X181 ), ((unsigned char )72 ), __2__X182 ,
# 1675 "/home/claude/cfront-3/src/dcl.cpp"
((struct stmt *)0 )) ), (__0__X181 -> __O2__4stmt.e = __3init )) :0 ), __0__X181 ) ) ) ;

# 1677 "/home/claude/cfront-3/src/dcl.cpp"
if (st_ilist == 0 )
# 1678 "/home/claude/cfront-3/src/dcl.cpp"
st_ilist = __7ist ;
else 
# 1680 "/home/claude/cfront-3/src/dcl.cpp"
itail -> s_list__4stmt = __7ist ;
itail = __7ist ;
__3init = 0 ;

# 1682 "/home/claude/cfront-3/src/dcl.cpp"
}
}
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = __3init );
const_save = __3const_old ;
__1tbl = __6otbl ;

# 1686 "/home/claude/cfront-3/src/dcl.cpp"
}

# 1686 "/home/claude/cfront-3/src/dcl.cpp"
}

# 1686 "/home/claude/cfront-3/src/dcl.cpp"
}

# 1686 "/home/claude/cfront-3/src/dcl.cpp"
}

# 1686 "/home/claude/cfront-3/src/dcl.cpp"
}
}
else if (__3init == 0 )
# 1689 "/home/claude/cfront-3/src/dcl.cpp"
goto str ;
else if (( (((unsigned char )((__5cl -> csu__8classdef == 6 )?0 :(((int )__5cl -> csu__8classdef )))))) && (__5cl -> csu__8classdef != 167 )){
# 1690 "/home/claude/cfront-3/src/dcl.cpp"

# 1691 "/home/claude/cfront-3/src/dcl.cpp"
__3init = typ__4exprFP5table ( __3init , __1tbl ) ;
if ((check__4typeFP4typeUcT2 ( __1nn -> __O1__4expr.tp , __3init -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) == 0 )&&
# 1692 "/home/claude/cfront-3/src/dcl.cpp"
(__3init -> base__4node == 147 ))
# 1697 "/home/claude/cfront-3/src/dcl.cpp"
((void )replace_temp__FP4exprT1 ( __3init , address__4exprFv ( (struct expr *)__1nn ) ) );
else goto str ;
}
else if (__3init -> base__4node == 124 ){ 
# 1701 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1701 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V129 ;

# 1701 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V130 ;

# 1701 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannotI%nWIrL because class %s has private or protected members", (const struct ea *)( ((& __0__V129 )-> __O1__2ea.p =
# 1701 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__1nn )), (& __0__V129 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V130 , (const void *)__5cl ->
# 1701 "/home/claude/cfront-3/src/dcl.cpp"
string__8classdef ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else { 
# 1705 "/home/claude/cfront-3/src/dcl.cpp"
__3init = typ__4exprFP5table ( __3init , __1tbl ) ;
if (check__4typeFP4typeUcT2 ( __1nn -> __O1__4expr.tp , __3init -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) == 0 ){
# 1706 "/home/claude/cfront-3/src/dcl.cpp"

# 1707 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init -> base__4node == 147 )
# 1708 "/home/claude/cfront-3/src/dcl.cpp"
((void )replace_temp__FP4exprT1 ( __3init , address__4exprFv ( (struct expr *)__1nn ) ) );
else 
# 1710 "/home/claude/cfront-3/src/dcl.cpp"
goto str ;
}
goto str ;
}
break ;
}

# 1717 "/home/claude/cfront-3/src/dcl.cpp"
case 110 :
# 1718 "/home/claude/cfront-3/src/dcl.cpp"
__3t = (((struct vec *)(((struct vec *)__3t ))))-> typ__5pvtyp ;
__3vec_seen ++ ;
assign__4nameFv ( __1nn ) ;
goto lll ;

# 1723 "/home/claude/cfront-3/src/dcl.cpp"
case 97 :
# 1724 "/home/claude/cfront-3/src/dcl.cpp"
if ((__3init == 0 )&& (((struct basetype *)(((struct basetype *)__3t ))))-> b_const__4type ){ 
# 1725 "/home/claude/cfront-3/src/dcl.cpp"
switch (__0this -> n_scope__4name ){ 
# 1726 "/home/claude/cfront-3/src/dcl.cpp"
case 136 :
# 1727 "/home/claude/cfront-3/src/dcl.cpp"
break ;
# 1727 "/home/claude/cfront-3/src/dcl.cpp"

# 1728 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 1729 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 1730 "/home/claude/cfront-3/src/dcl.cpp"
if (cc -> cot__11dcl_context )
# 1731 "/home/claude/cfront-3/src/dcl.cpp"
break ;
default :
# 1733 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1734 "/home/claude/cfront-3/src/dcl.cpp"
Pname __7n ;
Pclass __7cl ;

# 1734 "/home/claude/cfront-3/src/dcl.cpp"
__7n = is_cl_obj__4typeFv ( __3t ) ;

# 1736 "/home/claude/cfront-3/src/dcl.cpp"
if (__7n )
# 1737 "/home/claude/cfront-3/src/dcl.cpp"
__7cl = (((struct classdef *)(((struct classdef *)__7n -> __O1__4expr.tp ))));

# 1739 "/home/claude/cfront-3/src/dcl.cpp"
if ((__0this -> n_sto__4name != 14 )&& ((__7n == 0 )|| ((( __7cl -> c_ctor__8classdef ) == 0 )&& (is_empty__FP8classdefUc ( __7cl , (unsigned
# 1739 "/home/claude/cfront-3/src/dcl.cpp"
char )1 ) == 0 ))))
# 1750 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1750 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V131 ;

# 1750 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"uninitialized const%n", (const struct ea *)( ((& __0__V131 )-> __O1__2ea.p =
# 1750 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V131 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1750 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} }
}
}
__3t = skiptypedefs__4typeFRUc ( __3t , (bit *)(& __3td_const )) ;
goto lll ;

# 1757 "/home/claude/cfront-3/src/dcl.cpp"
case 158 :
# 1758 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init ){ 
# 1759 "/home/claude/cfront-3/src/dcl.cpp"
if (__1nn -> n_scope__4name == 136 )
# 1760 "/home/claude/cfront-3/src/dcl.cpp"
break ;
if ((((struct ptr *)(((struct ptr *)__1nn -> __O1__4expr.tp ))))-> memof__3ptr )
# 1762 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1762 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V132 ;

# 1762 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V133 ;

# 1762 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"R toCM%n ofT%t illegal", (const struct ea *)( ((& __0__V132 )-> __O1__2ea.p =
# 1762 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__1nn )), (& __0__V132 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V133 , (const void *)__1nn ->
# 1762 "/home/claude/cfront-3/src/dcl.cpp"
__O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} ref_initializer ++ ;
__3init = typ__4exprFP5table ( __3init , __1tbl ) ;
ref_initializer -- ;
Nvirt = 0 ;

# 1780 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = (__3init = ref_init__FP3ptrP4exprP5table ( ((struct ptr *)(((struct ptr *)__3t ))), __3init , __1tbl ) ));

# 1782 "/home/claude/cfront-3/src/dcl.cpp"
if (Nvirt == 77 )
# 1783 "/home/claude/cfront-3/src/dcl.cpp"
__1sti_vb = 1 ;
assign__4nameFv ( __1nn ) ;

# 1786 "/home/claude/cfront-3/src/dcl.cpp"
if ((__3init -> base__4node == 124 )&& (__3init -> __O3__4expr.e2 == 0 )){ 
# 1787 "/home/claude/cfront-3/src/dcl.cpp"
new_list__FP4expr ( __3init ) ;
list_check__FP4nameP4typeP4exprP5table ( __1nn , __1nn -> __O1__4expr.tp , (struct expr *)0 , __1tbl ) ;
if (next_elem__Fv ( ) )
# 1790 "/home/claude/cfront-3/src/dcl.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"IrL too long",
# 1790 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
}

# 1793 "/home/claude/cfront-3/src/dcl.cpp"
}
else { 
# 1795 "/home/claude/cfront-3/src/dcl.cpp"
switch (__1nn -> n_scope__4name ){ 
# 1796 "/home/claude/cfront-3/src/dcl.cpp"
default :
# 1797 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> n_sto__4name != 14 )
# 1798 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1798 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V134 ;

# 1798 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"uninitializedR%n", (const struct ea *)( ((& __0__V134 )-> __O1__2ea.p =
# 1798 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V134 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1798 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} case 136 :
# 1800 "/home/claude/cfront-3/src/dcl.cpp"
break ;
case 25 :
# 1802 "/home/claude/cfront-3/src/dcl.cpp"
case 0 :
# 1803 "/home/claude/cfront-3/src/dcl.cpp"
if (cc -> cot__11dcl_context == 0 )
# 1804 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1804 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V135 ;

# 1804 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"uninitializedR%n", (const struct ea *)( ((& __0__V135 )-> __O1__2ea.p =
# 1804 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V135 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1804 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} break ;
}
}
goto stgg ;
default :
# 1810 "/home/claude/cfront-3/src/dcl.cpp"
str :
# 1811 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init == 0 ){ 
# 1812 "/home/claude/cfront-3/src/dcl.cpp"
switch (__0this -> n_scope__4name ){ 
# 1813 "/home/claude/cfront-3/src/dcl.cpp"
case 136 :
# 1814 "/home/claude/cfront-3/src/dcl.cpp"
break ;
case 0 :
# 1816 "/home/claude/cfront-3/src/dcl.cpp"
case 25 :
# 1817 "/home/claude/cfront-3/src/dcl.cpp"
if (cc -> cot__11dcl_context )
# 1818 "/home/claude/cfront-3/src/dcl.cpp"
break ;
default :
# 1820 "/home/claude/cfront-3/src/dcl.cpp"
if ((__0this -> n_sto__4name != 14 )&& tconst__4typeFv ( __3t ) )
# 1821 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1821 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V136 ;

# 1821 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"uninitialized const%n", (const struct ea *)( ((& __0__V136 )-> __O1__2ea.p =
# 1821 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V136 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1821 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
} }

# 1824 "/home/claude/cfront-3/src/dcl.cpp"
break ;
}

# 1833 "/home/claude/cfront-3/src/dcl.cpp"
const_save = ((const_save || (__0this -> n_scope__4name == 136 ))|| (tconst__4typeFv ( __3t ) && (vec_const == 0 )));

# 1835 "/home/claude/cfront-3/src/dcl.cpp"
if (__0this -> n_sto__4name == 31 )
# 1836 "/home/claude/cfront-3/src/dcl.cpp"
stat_init ++ ;
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = (__3init = typ__4exprFP5table ( __3init , __1tbl ) ));
if (__0this -> n_sto__4name == 31 )
# 1839 "/home/claude/cfront-3/src/dcl.cpp"
stat_init -- ;

# 1841 "/home/claude/cfront-3/src/dcl.cpp"
if (const_save || __3td_const )
# 1842 "/home/claude/cfront-3/src/dcl.cpp"
__3init -> permanent__4node = 1 ;
assign__4nameFv ( __1nn ) ;
const_save = __3const_old ;
switch (__3init -> base__4node ){ 
# 1846 "/home/claude/cfront-3/src/dcl.cpp"
case 124 :
# 1847 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init -> __O3__4expr.e2 )
# 1848 "/home/claude/cfront-3/src/dcl.cpp"
goto dfdf ;
new_list__FP4expr ( __3init ) ;
list_check__FP4nameP4typeP4exprP5table ( __1nn , __1nn -> __O1__4expr.tp , (struct expr *)0 , __1tbl ) ;
if (next_elem__Fv ( ) )
# 1852 "/home/claude/cfront-3/src/dcl.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"IrL too long",
# 1852 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
case 81 :
# 1855 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1856 "/home/claude/cfront-3/src/dcl.cpp"
Ptype __6v ;

# 1856 "/home/claude/cfront-3/src/dcl.cpp"
__6v = skiptypedefs__4typeFv ( __1nn -> __O1__4expr.tp ) ;
if (__6v -> base__4node == 110 ){ 
# 1858 "/home/claude/cfront-3/src/dcl.cpp"
Ptype __7vv ;

# 1858 "/home/claude/cfront-3/src/dcl.cpp"
__7vv = skiptypedefs__4typeFv ( (((struct vec *)(((struct vec *)__6v ))))-> typ__5pvtyp ) ;
if (__7vv -> base__4node == 5 ){ 
# 1860 "/home/claude/cfront-3/src/dcl.cpp"
int __8sz ;
int __8isz ;

# 1860 "/home/claude/cfront-3/src/dcl.cpp"
__8sz = (((struct vec *)(((struct vec *)__6v ))))-> size__3vec ;
__8isz = (((struct vec *)(((struct vec *)__3init -> __O1__4expr.tp ))))-> size__3vec ;
if (__8sz == 0 )
# 1863 "/home/claude/cfront-3/src/dcl.cpp"
(((struct vec *)(((struct vec *)__6v ))))-> size__3vec = __8isz ;
else if (__8sz < __8isz )
# 1865 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1865 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V137 ;

# 1865 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V138 ;

# 1865 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V139 ;

# 1865 "/home/claude/cfront-3/src/dcl.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"Ir too long (%d characters) for%n[%d]", (const struct ea *)(
# 1865 "/home/claude/cfront-3/src/dcl.cpp"
(( ((& __0__V137 )-> __O1__2ea.i = ((unsigned long )__8isz )), 0 ) ), (& __0__V137 )) , (const struct
# 1865 "/home/claude/cfront-3/src/dcl.cpp"
ea *)( ((& __0__V138 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V138 )) , (const struct ea *)( ((
# 1865 "/home/claude/cfront-3/src/dcl.cpp"
((& __0__V139 )-> __O1__2ea.i = ((unsigned long )__8sz )), 0 ) ), (& __0__V139 )) , (const struct ea *)ea0 )
# 1865 "/home/claude/cfront-3/src/dcl.cpp"
;
} break ;
}
}

# 1870 "/home/claude/cfront-3/src/dcl.cpp"
}
default :
# 1872 "/home/claude/cfront-3/src/dcl.cpp"
dfdf :
# 1873 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1874 "/home/claude/cfront-3/src/dcl.cpp"
bit __6ntc ;
Ptype __6nt ;

# 1874 "/home/claude/cfront-3/src/dcl.cpp"
__6ntc = 0 ;
__6nt = skiptypedefs__4typeFRUc ( __1nn -> __O1__4expr.tp , (bit *)(& __6ntc )) ;

# 1877 "/home/claude/cfront-3/src/dcl.cpp"
if (__3vec_seen ){ 
# 1878 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1878 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V140 ;

# 1878 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIr for array%n", (const struct ea *)( ((& __0__V140 )-> __O1__2ea.p =
# 1878 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__1nn )), (& __0__V140 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1878 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 ) ;
break ;
} }

# 1882 "/home/claude/cfront-3/src/dcl.cpp"
{ Ptype __6it ;

# 1882 "/home/claude/cfront-3/src/dcl.cpp"
__6it = skiptypedefs__4typeFv ( __3init -> __O1__4expr.tp ) ;
switch (__6nt -> base__4node ){ 
# 1884 "/home/claude/cfront-3/src/dcl.cpp"
case 21 :
# 1885 "/home/claude/cfront-3/src/dcl.cpp"
case 5 :
# 1886 "/home/claude/cfront-3/src/dcl.cpp"
case 29 :
# 1887 "/home/claude/cfront-3/src/dcl.cpp"
case 121 :
# 1888 "/home/claude/cfront-3/src/dcl.cpp"
switch (__6it -> base__4node ){ 
# 1889 "/home/claude/cfront-3/src/dcl.cpp"
case 22 :
# 1890 "/home/claude/cfront-3/src/dcl.cpp"
case 122 :
# 1891 "/home/claude/cfront-3/src/dcl.cpp"
case 15 :
# 1892 "/home/claude/cfront-3/src/dcl.cpp"
case
# 1892 "/home/claude/cfront-3/src/dcl.cpp"
11 :
# 1893 "/home/claude/cfront-3/src/dcl.cpp"
case 181 :
# 1894 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1894 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V141 ;

# 1894 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V142 ;

# 1894 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%tIdW%t", (const struct ea *)( ((&
# 1894 "/home/claude/cfront-3/src/dcl.cpp"
__0__V141 )-> __O1__2ea.p = ((const void *)__6nt )), (& __0__V141 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V142 , (const
# 1894 "/home/claude/cfront-3/src/dcl.cpp"
void *)__3init -> __O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1897 "/home/claude/cfront-3/src/dcl.cpp"
case 22 :
# 1898 "/home/claude/cfront-3/src/dcl.cpp"
case 122 :
# 1899 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1900 "/home/claude/cfront-3/src/dcl.cpp"
if (((((struct basetype *)(((struct basetype *)__6nt ))))-> b_unsigned__8basetype && (__3init -> base__4node == 107 ))&& (__3init -> __O3__4expr.e2 ->
# 1900 "/home/claude/cfront-3/src/dcl.cpp"
base__4node == 82 ))
# 1907 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1907 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V143 ;

# 1907 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"negativeIr for unsigned%n", (const struct ea *)( ((&
# 1907 "/home/claude/cfront-3/src/dcl.cpp"
__0__V143 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V143 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1907 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 ) ;
} 
# 1909 "/home/claude/cfront-3/src/dcl.cpp"
if (__6nt -> base__4node != 121 ){ 
# 1910 "/home/claude/cfront-3/src/dcl.cpp"
switch (__6it -> base__4node ){ 
# 1910 "/home/claude/cfront-3/src/dcl.cpp"
struct texpr *__0__X183 ;

# 1911 "/home/claude/cfront-3/src/dcl.cpp"
case 29 :
# 1912 "/home/claude/cfront-3/src/dcl.cpp"
case 21 :
# 1913 "/home/claude/cfront-3/src/dcl.cpp"
case 22 :
# 1914 "/home/claude/cfront-3/src/dcl.cpp"
case 122 :
# 1915 "/home/claude/cfront-3/src/dcl.cpp"
if (tsizeof__4typeFi ( __6nt , 0 ) < tsizeof__4typeFi ( __6it , 0 ) )
# 1916 "/home/claude/cfront-3/src/dcl.cpp"
__3init = (struct
# 1916 "/home/claude/cfront-3/src/dcl.cpp"
expr *)( (__0__X183 = 0 ), ( ((__0__X183 || (__0__X183 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X183 =
# 1916 "/home/claude/cfront-3/src/dcl.cpp"
(struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X183 ), ((unsigned char )191 ), __3init , (struct expr *)0 ) ), (__0__X183 -> __O4__4expr.tp2 = __6nt ))
# 1916 "/home/claude/cfront-3/src/dcl.cpp"
:0 ), __0__X183 ) ) ;
__3init = typ__4exprFP5table ( __3init , __1tbl ) ;
}
}

# 1922 "/home/claude/cfront-3/src/dcl.cpp"
Neval = 0 ;
{ long long __8i ;

# 1923 "/home/claude/cfront-3/src/dcl.cpp"
__8i = eval__4exprFv ( __3init ) ;
if (((Neval == 0 )&& __6ntc )&& (__1scope != 136 )){ 
# 1925 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> n_evaluated__4name = (__0this -> n_evaluated__4name = 1 );
__1nn -> n_val__4name = (__0this -> n_val__4name = __8i );
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = 0 );
}
break ;

# 1929 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 1932 "/home/claude/cfront-3/src/dcl.cpp"
case 125 :
# 1933 "/home/claude/cfront-3/src/dcl.cpp"
Nvirt = 0 ;

# 1937 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = (__3init = ptr_init__FP3ptrP4exprP5table ( ((struct ptr *)(((struct ptr *)__6nt ))), __3init , __1tbl ) ));
if (Nvirt == 77 )
# 1939 "/home/claude/cfront-3/src/dcl.cpp"
__1sti_vb = 1 ;
if (Pchecked )
# 1941 "/home/claude/cfront-3/src/dcl.cpp"
goto stgg ;
}

# 1944 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1945 "/home/claude/cfront-3/src/dcl.cpp"
Pexpr __7x ;

# 1945 "/home/claude/cfront-3/src/dcl.cpp"
__7x = try_to_coerce__FP4typeP4exprPCcP5table ( __6nt , __3init , (const char *)"initializer", __1tbl ) ;
if (__7x ){ 
# 1947 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = (__3init = __7x ));
goto stgg ;
}
}
{ int __6ct ;
Pname __6c1 ;
Pname __6c2 ;

# 1954 "/home/claude/cfront-3/src/dcl.cpp"
register struct type *__0__X187 ;

# 1954 "/home/claude/cfront-3/src/dcl.cpp"
struct type *__1__Xt00anx4xs1bwcog ;

# 1951 "/home/claude/cfront-3/src/dcl.cpp"
__6ct = no_const ;
__6c1 = is_cl_obj__4typeFv ( __6nt ) ;
__6c2 = is_cl_obj__4typeFv ( __3init -> __O1__4expr.tp ) ;
if ((__6c1 && __6c2 )&& has_base__8classdefFP8classdefiT2 ( ((struct classdef *)(((struct classdef *)__6c2 -> __O1__4expr.tp ))), ((struct classdef *)(((struct classdef *)__6c1 -> __O1__4expr.tp ))), 0 , 0 )
# 1954 "/home/claude/cfront-3/src/dcl.cpp"
)
# 1960 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1960 "/home/claude/cfront-3/src/dcl.cpp"
struct texpr *__0__X184 ;

# 1960 "/home/claude/cfront-3/src/dcl.cpp"
struct type *__2__X185 ;

# 1960 "/home/claude/cfront-3/src/dcl.cpp"
struct expr *__2__X186 ;

# 1961 "/home/claude/cfront-3/src/dcl.cpp"
__3init = (struct expr *)( (__0__X184 = 0 ), ( (__2__X185 = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 ,
# 1961 "/home/claude/cfront-3/src/dcl.cpp"
__6nt ) ), ( (__2__X186 = address__4exprFv ( __3init ) ), ( ((__0__X184 || (__0__X184 = (struct texpr *)__nw__4exprSFUl ( (unsigned long
# 1961 "/home/claude/cfront-3/src/dcl.cpp"
)(sizeof (struct texpr))) ))?( (__0__X184 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X184 ), ((unsigned char )191 ), __2__X186 , (struct expr *)0 )
# 1961 "/home/claude/cfront-3/src/dcl.cpp"
), (__0__X184 -> __O4__4expr.tp2 = __2__X185 )) :0 ), __0__X184 ) ) ) ) ;
__3init = typ__4exprFP5table ( __3init , __1tbl ) ;

# 1966 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = (__3init = contents__4exprFv ( __3init ) ));
goto stgg ;
}

# 1970 "/home/claude/cfront-3/src/dcl.cpp"
if (( (__0__X187 = __3init -> __O1__4expr.tp ), ( (__1__Xt00anx4xs1bwcog = skiptypedefs__4typeFv ( __0__X187 ) ), ( ((__1__Xt00anx4xs1bwcog -> base__4node == 125 )?(
# 1970 "/home/claude/cfront-3/src/dcl.cpp"
(__1__Xt00anx4xs1bwcog = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__1__Xt00anx4xs1bwcog ))))-> typ__5pvtyp ) ), 0 ) :0 ), (((unsigned char )((__1__Xt00anx4xs1bwcog -> base__4node == ((unsigned
# 1970 "/home/claude/cfront-3/src/dcl.cpp"
char )76 ))?1 :0 )))) ) ) )
# 1971 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1971 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V144 ;

# 1971 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V145 ;

# 1971 "/home/claude/cfront-3/src/dcl.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT &overloaded function for%n (%tX)", (const struct ea *)( ((& __0__V144 )-> __O1__2ea.p =
# 1971 "/home/claude/cfront-3/src/dcl.cpp"
((const void *)__0this )), (& __0__V144 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V145 , (const void *)__1nn ->
# 1971 "/home/claude/cfront-3/src/dcl.cpp"
__O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (check__4typeFP4typeUcT2 ( __6nt , __3init -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) ){
# 1972 "/home/claude/cfront-3/src/dcl.cpp"

# 1972 "/home/claude/cfront-3/src/dcl.cpp"
const void *__2__X188 ;

# 1973 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 1973 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V146 ;

# 1973 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V147 ;

# 1973 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V148 ;

# 1973 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"badIrT%t for%n (%tX)", (const struct ea *)( (__2__X188 =
# 1973 "/home/claude/cfront-3/src/dcl.cpp"
(const void *)__3init -> __O1__4expr.tp ), ( ((& __0__V146 )-> __O1__2ea.p = __2__X188 ), (& __0__V146 )) ) , (const
# 1973 "/home/claude/cfront-3/src/dcl.cpp"
struct ea *)( ((& __0__V147 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V147 )) , (const struct ea *)__ct__2eaFPCv (
# 1973 "/home/claude/cfront-3/src/dcl.cpp"
& __0__V148 , (const void *)__1nn -> __O1__4expr.tp ) , (const struct ea *)ea0 ) ;
if (__6ct )error__FiPCc ( (int )'c' , (const char *)" (no usable const conversion)\n") ;
else error__FiPCc ( (int )'c' , (const char *)"\n") ;
break ;
} }

# 1977 "/home/claude/cfront-3/src/dcl.cpp"
}

# 1977 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 1980 "/home/claude/cfront-3/src/dcl.cpp"
stgg :
# 1982 "/home/claude/cfront-3/src/dcl.cpp"
if ((__3init && (__0this -> n_stclass__4name == 31 ))&& (__1sti_vb || (need_sti__FP4exprP5tableUc ( __3init , (struct table *)0 , (unsigned char )0 )
# 1982 "/home/claude/cfront-3/src/dcl.cpp"
&& check_static_pt__FP4name ( __1nn ) ))){ 
# 1984 "/home/claude/cfront-3/src/dcl.cpp"
int __6local ;

# 1984 "/home/claude/cfront-3/src/dcl.cpp"
__6local = (0 < __0this -> lex_level__4name );
if (__6local == 0 )
# 1986 "/home/claude/cfront-3/src/dcl.cpp"
need_sti__FP4exprP5tableUc ( __3init , __1tbl , (unsigned char )0 ) ;

# 1988 "/home/claude/cfront-3/src/dcl.cpp"
{ Pptr __6r ;

# 1988 "/home/claude/cfront-3/src/dcl.cpp"
__6r = is_ref__4typeFv ( __1nn -> __O1__4expr.tp ) ;

# 1990 "/home/claude/cfront-3/src/dcl.cpp"
if (__6r && (! is_ptr_or_ref__4typeFv ( __3init -> __O1__4expr.tp ) ))
# 1991 "/home/claude/cfront-3/src/dcl.cpp"
__3init = address__4exprFv ( __3init ) ;
__3init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1nn , __3init ) ;
if (__6r )
# 1994 "/home/claude/cfront-3/src/dcl.cpp"
__3init -> __O1__4expr.tp = __1nn -> __O1__4expr.tp ;
else if (__1nn -> __O1__4expr.tp != __3init -> __O1__4expr.tp ){ 
# 1996 "/home/claude/cfront-3/src/dcl.cpp"
TOK __7t ;

# 1996 "/home/claude/cfront-3/src/dcl.cpp"
__7t = set_const__4typeFUc ( __1nn -> __O1__4expr.tp , (unsigned char )0 ) ;
__3init = typ__4exprFP5table ( __3init , __1tbl ) ;
set_const__4typeFUc ( __1nn -> __O1__4expr.tp , __7t ) ;
}

# 2001 "/home/claude/cfront-3/src/dcl.cpp"
if (dtpt_opt && (dinst_body__4nameFv ( __1nn ) == 0 )){ 
# 2002 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = (__3init = 0 ));
break ;
}

# 2006 "/home/claude/cfront-3/src/dcl.cpp"
if (__6local ){ 
# 2007 "/home/claude/cfront-3/src/dcl.cpp"
if (__3init -> base__4node != 70 )
# 2008 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCc ( (int )'s' , (const char *)"Ir for local static too complicated")
# 2008 "/home/claude/cfront-3/src/dcl.cpp"
;
if (__1nn -> n_sto__4name == 14 ){ 
# 2010 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 2010 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V149 ;

# 2010 "/home/claude/cfront-3/src/dcl.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"Id local extern%n", (const struct ea *)(
# 2010 "/home/claude/cfront-3/src/dcl.cpp"
((& __0__V149 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V149 )) , (const struct ea *)ea0 , (const struct
# 2010 "/home/claude/cfront-3/src/dcl.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
__3init = 0 ;
} }
else 
# 2014 "/home/claude/cfront-3/src/dcl.cpp"
__3init -> base__4node = 186 ;
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = __3init );
}
else { 
# 2018 "/home/claude/cfront-3/src/dcl.cpp"
Pstmt __7ist ;

# 2019 "/home/claude/cfront-3/src/dcl.cpp"
struct estmt *__0__X189 ;

# 2019 "/home/claude/cfront-3/src/dcl.cpp"
struct loc __2__X190 ;

# 2018 "/home/claude/cfront-3/src/dcl.cpp"
__7ist = (struct stmt *)( (__0__X189 = 0 ), ( (__2__X190 = __1nn -> where__4name ), ( ((__0__X189 || (__0__X189 = (struct estmt *)__nw__4stmtSFUl (
# 2018 "/home/claude/cfront-3/src/dcl.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X189 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X189 ), ((unsigned char )72 ), __2__X190 ,
# 2018 "/home/claude/cfront-3/src/dcl.cpp"
((struct stmt *)0 )) ), (__0__X189 -> __O2__4stmt.e = __3init )) :0 ), __0__X189 ) ) ) ;

# 2021 "/home/claude/cfront-3/src/dcl.cpp"
if (st_ilist == 0 )
# 2022 "/home/claude/cfront-3/src/dcl.cpp"
st_ilist = __7ist ;
else 
# 2024 "/home/claude/cfront-3/src/dcl.cpp"
itail -> s_list__4stmt = __7ist ;
itail = __7ist ;

# 2029 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> __O3__4expr.n_initializer = (__0this -> __O3__4expr.n_initializer = (__3init = 0 ));
__1nn -> n_val__4name = (__0this -> n_val__4name = 1 );
}

# 2031 "/home/claude/cfront-3/src/dcl.cpp"
}
}
}
}
}

# 2037 "/home/claude/cfront-3/src/dcl.cpp"
}
ggg :
# 2039 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> permanent__4node = 1 ;
switch (__0this -> n_scope__4name ){ 
# 2041 "/home/claude/cfront-3/src/dcl.cpp"
case 108 :
# 2042 "/home/claude/cfront-3/src/dcl.cpp"
__1nn -> __O3__4expr.n_initializer = __0this -> __O3__4expr.n_initializer ;
break ;
default :
# 2045 "/home/claude/cfront-3/src/dcl.cpp"
{ Ptype __3t ;

# 2045 "/home/claude/cfront-3/src/dcl.cpp"
__3t = __1nn -> __O1__4expr.tp ;
px :
# 2047 "/home/claude/cfront-3/src/dcl.cpp"
__3t -> permanent__4node = 1 ;
switch (__3t -> base__4node ){ 
# 2049 "/home/claude/cfront-3/src/dcl.cpp"
case 125 :
# 2050 "/home/claude/cfront-3/src/dcl.cpp"
case 158 :
# 2051 "/home/claude/cfront-3/src/dcl.cpp"
case 110 :__3t = (((struct ptr *)(((struct ptr *)__3t ))))-> typ__5pvtyp ;

# 2051 "/home/claude/cfront-3/src/dcl.cpp"
goto px ;
case 97 :__3t = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype -> __O1__4expr.tp ;

# 2052 "/home/claude/cfront-3/src/dcl.cpp"
goto px ;
case 108 :__3t = (((struct fct *)(((struct fct *)__3t ))))-> returns__3fct ;

# 2053 "/home/claude/cfront-3/src/dcl.cpp"
goto px ;
}
}
}

# 2058 "/home/claude/cfront-3/src/dcl.cpp"
Cdcl = __1odcl ;
return __1nn ;

# 2059 "/home/claude/cfront-3/src/dcl.cpp"
}

# 2059 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 80 "/home/claude/incl-linux32/stdio.h"
extern int sprintf (char *, const char *,...);

# 2064 "/home/claude/cfront-3/src/dcl.cpp"
char *make_nested_name__FPCcP8classdef (const char *__1s , Pclass __1cl )
# 2065 "/home/claude/cfront-3/src/dcl.cpp"
{ 
# 2066 "/home/claude/cfront-3/src/dcl.cpp"

# 2067 "/home/claude/cfront-3/src/dcl.cpp"
const char *__1str_arr [9];
int __1size_arr [9];
int __1cnt ;
int __1size ;

# 2069 "/home/claude/cfront-3/src/dcl.cpp"
__1cnt = 1 ;
__1size = 4 ;

# 2072 "/home/claude/cfront-3/src/dcl.cpp"
(__1str_arr [0 ])= __1s ;
__1size += ((__1size_arr [0 ])= strlen ( __1s ) );

# 2075 "/home/claude/cfront-3/src/dcl.cpp"
{ { Pclass __1nc ;

# 2075 "/home/claude/cfront-3/src/dcl.cpp"
__1nc = __1cl ;

# 2075 "/home/claude/cfront-3/src/dcl.cpp"
for(;__1nc && (__1nc -> lex_level__4type == __1cl -> lex_level__4type );__1nc = __1nc -> in_class__4type ) { 
# 2076 "/home/claude/cfront-3/src/dcl.cpp"
if (__1cnt > 8){ 
# 2076 "/home/claude/cfront-3/src/dcl.cpp"
struct ea __0__V191 ;

# 2076 "/home/claude/cfront-3/src/dcl.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"nested depth class beyond %d unsupported", (const struct ea *)( ((
# 2076 "/home/claude/cfront-3/src/dcl.cpp"
((& __0__V191 )-> __O1__2ea.i = ((unsigned long )9)), 0 ) ), (& __0__V191 )) , (const struct ea *)ea0 ,
# 2076 "/home/claude/cfront-3/src/dcl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __1size += ((__1size_arr [__1cnt ])= __1nc -> c_strlen__8classdef );
(__1str_arr [__1cnt ])= (__1nc -> local_sig__4type ?(((const char *)__1nc -> local_sig__4type )):__1nc -> string__8classdef );
++ __1cnt ;
}

# 2082 "/home/claude/cfront-3/src/dcl.cpp"
{ int __1i ;

# 2082 "/home/claude/cfront-3/src/dcl.cpp"
__1i = 0 ;
for(__1i = 0 ;__1i < __1cnt ;__1i ++ ) 
# 2084 "/home/claude/cfront-3/src/dcl.cpp"
__1size += (((__1size_arr [__1i ])> 99 )?3 :(((__1size_arr [__1i ])< 10 )?1 :2 ));

# 2087 "/home/claude/cfront-3/src/dcl.cpp"
{ char *__1result ;

# 2087 "/home/claude/cfront-3/src/dcl.cpp"
__1result = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* __1size )) ));
sprintf ( __1result , (const char *)"Q%d_", __1cnt ) ;
__1size = 3 ;
for(__1i = __1cnt ;__1i ;__1i -- ) { 
# 2091 "/home/claude/cfront-3/src/dcl.cpp"
sprintf ( __1result + __1size , (const char *)"%d%s",
# 2091 "/home/claude/cfront-3/src/dcl.cpp"
__1size_arr [(__1i - 1 )], __1str_arr [(__1i - 1 )]) ;
__1size += ((__1size_arr [(__1i - 1 )])+ (((__1size_arr [(__1i - 1 )])> 99 )?3 :(((__1size_arr [(__1i - 1 )])< 10 )?1 :2 )));
}

# 2096 "/home/claude/cfront-3/src/dcl.cpp"
(__1result [__1size ])= '\0' ;

# 2098 "/home/claude/cfront-3/src/dcl.cpp"
return __1result ;

# 2098 "/home/claude/cfront-3/src/dcl.cpp"
}

# 2098 "/home/claude/cfront-3/src/dcl.cpp"
}

# 2098 "/home/claude/cfront-3/src/dcl.cpp"
}

# 2098 "/home/claude/cfront-3/src/dcl.cpp"
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFUl (struct ea *__0this , 
# 76 "/home/claude/cfront-3/src/cfront.h"
size_t __2ii ){ 
# 76 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct ea *)__nw__FUl ( (size_t )(sizeof (struct ea)))
# 76 "/home/claude/cfront-3/src/cfront.h"
))__0this -> __O1__2ea.i = __2ii ;

# 76 "/home/claude/cfront-3/src/cfront.h"
return __0this ;

# 76 "/home/claude/cfront-3/src/cfront.h"
}

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , 
# 75 "/home/claude/cfront-3/src/cfront.h"
const void *__2pp ){ 
# 75 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct ea *)__nw__FUl ( (unsigned long
# 75 "/home/claude/cfront-3/src/cfront.h"
)(sizeof (struct ea))) ))__0this -> __O1__2ea.p = __2pp ;

# 75 "/home/claude/cfront-3/src/cfront.h"
return __0this ;

# 75 "/home/claude/cfront-3/src/cfront.h"
}

# 480 "/home/claude/cfront-3/src/template.h"
extern Ptfct ptfct_free__9templ_fct;

# 404 "/home/claude/cfront-3/src/cfront.h"

# 198 "/home/claude/cfront-3/src/template.h"

# 236 "/home/claude/cfront-3/src/template.h"

# 336 "/home/claude/cfront-3/src/template.h"
extern Pbase_inst head__10basic_inst;

# 236 "/home/claude/cfront-3/src/template.h"

# 198 "/home/claude/cfront-3/src/template.h"

# 92 "/home/claude/cfront-3/src/template.h"
struct templ_compilation {	/* sizeof templ_compilation == 1 */

# 92 "/home/claude/cfront-3/src/template.h"
char __W17__17templ_compilation ;
};

# 98 "/home/claude/cfront-3/src/template.h"
extern Plist param_end__17templ_compilation ;
extern Ptempl list__17templ_compilation ;
extern Pfunt f_list__17templ_compilation ;
extern Pfunt f_owner__17templ_compilation ;
extern Ptempl owner__17templ_compilation ;
extern Ptempl_base parsed_template__17templ_compilation ;

# 105 "/home/claude/cfront-3/src/template.h"
extern Plist params__17templ_compilation ;
extern Pexpr actuals__17templ_compilation ;
extern Ptable templates__17templ_compilation ;

# 109 "/home/claude/cfront-3/src/template.h"
extern int in_progress__17templ_compilation ;
extern Ptstate save_templ__17templ_compilation ;

# 115 "/home/claude/cfront-3/src/template.h"
extern int parameters_in_progress__17templ_compilation ;
extern int formals_in_progress__17templ_compilation ;

# 119 "/home/claude/cfront-3/src/template.h"
extern Pcons templ_refs__17templ_compilation ;
extern Pcons friend_templ_refs__17templ_compilation ;
extern Pcons last_cons__17templ_compilation ;
extern Pcons last_friend_cons__17templ_compilation ;

# 404 "/home/claude/cfront-3/src/cfront.h"

# 92 "/home/claude/cfront-3/src/template.h"

# 122 "/home/claude/cfront-3/src/template.h"
extern Pcons last_friend_cons__17templ_compilation;

# 121 "/home/claude/cfront-3/src/template.h"
extern Pcons last_cons__17templ_compilation;

# 120 "/home/claude/cfront-3/src/template.h"
extern Pcons friend_templ_refs__17templ_compilation;

# 119 "/home/claude/cfront-3/src/template.h"
extern Pcons templ_refs__17templ_compilation;

# 116 "/home/claude/cfront-3/src/template.h"
extern int formals_in_progress__17templ_compilation;

# 115 "/home/claude/cfront-3/src/template.h"
extern int parameters_in_progress__17templ_compilation;

# 110 "/home/claude/cfront-3/src/template.h"
extern Ptstate save_templ__17templ_compilation;

# 109 "/home/claude/cfront-3/src/template.h"
extern int in_progress__17templ_compilation;

# 107 "/home/claude/cfront-3/src/template.h"
extern Ptable templates__17templ_compilation;

# 106 "/home/claude/cfront-3/src/template.h"
extern Pexpr actuals__17templ_compilation;

# 105 "/home/claude/cfront-3/src/template.h"
extern Plist params__17templ_compilation;

# 103 "/home/claude/cfront-3/src/template.h"
extern Ptempl_base parsed_template__17templ_compilation;

# 102 "/home/claude/cfront-3/src/template.h"
extern Ptempl owner__17templ_compilation;

# 101 "/home/claude/cfront-3/src/template.h"
extern Pfunt f_owner__17templ_compilation;

# 100 "/home/claude/cfront-3/src/template.h"
extern Pfunt f_list__17templ_compilation;

# 99 "/home/claude/cfront-3/src/template.h"
extern Ptempl list__17templ_compilation;

# 98 "/home/claude/cfront-3/src/template.h"
extern Plist param_end__17templ_compilation;

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

# 2099 "/home/claude/cfront-3/src/dcl.cpp"

/* the end */
