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
enum discriminator_error { discrim_none_valid = 0, discrim_bad_index = -1, discrim_inconsistent_node = -2} ;
enum node_class { nc_unused = 0, nc_eof = 1, nc_virt = 2, nc_nlist = 3, nc_gen = 4, nc_vec = 5, nc_ptr = 6, nc_fct = 7, nc_table = 8, nc_basetype = 9, nc_name = 10, nc_expr = 11, nc_stmt = 12, nc_enumdef = 13,
# 226 "/home/claude/cfront-3/src/cfront.h"
nc_classdef = 14, nc_baseclass = 15, nc_iline = 16, nc_ia = 17, nc_tpdef = 18, nc_ktable = 19} ;
struct token_class;

# 63 "/home/claude/cfront-3/src/node_classes.h"
struct token_class {	/* sizeof token_class == 8 */
TOK token__11token_class ;
int nclass__11token_class ;
};

# 66 "/home/claude/cfront-3/src/node_classes.h"
struct token_class token_classes [179]= { { 0 , 1} , { 1 , 12} , { 2 , 9}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 3 , 12} , { 4 , 12} , { 5 , 9} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
6 , 14} , { 7 , 12} , { 8 , 12} , { 9 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 10 , 12} , { 11 , 9} , { 12 , 12} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
13 , 13} , { 14 , 9} , { 15 , 9} , { 16 , 12}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 17 , 0} , { 18 , 9} , { 19 , 12} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
20 , 12} , { 21 , 9} , { 22 , 9} , { 122 , 9}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 190 , 18} , { 23 , 11} , { 24 , 7} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
28 , 12} , { 25 , 10} , { 26 , 9} , { 27 , 9}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 28 , 12} , { 29 , 9} , { 30 , 11} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
31 , 9} , { 32 , 0} , { 33 , 12} , { 34 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 35 , 9} , { 36 , 0} , { 37 , 9} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
38 , 9} , { 39 , 12} , { 40 , 0} , { 41 , 0}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 42 , 0} , { 43 , 0} , { 44 , 11} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
45 , 11} , { 46 , 11} , { 47 , 11} , { 48 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 49 , 11} , { 50 , 11} , { 51 , 11} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
52 , 11} , { 53 , 11} , { 54 , 11} , { 55 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 56 , 11} , { 57 , 11} , { 58 , 11} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
59 , 11} , { 60 , 11} , { 61 , 11} , { 62 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 63 , 11} , { 64 , 11} , { 65 , 11} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
66 , 11} , { 67 , 11} , { 68 , 11} , { 69 , 0}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 70 , 11} , { 71 , 11} , { 72 , 12} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
207 , 12} , { 73 , 0} , { 74 , 0} , { 75 , 7}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 76 , 4} , { 77 , 7} , { 78 , 0} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
79 , 10} , { 80 , 0} , { 81 , 11} , { 82 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 83 , 11} , { 84 , 11} , { 85 , 10} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
86 , 11} , { 90 , 11} , { 91 , 11} , { 92 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 93 , 11} , { 94 , 11} , { 95 , 11} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
96 , 11} , { 97 , 9} , { 98 , 0} , { 99 , 0}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 100 , 0} , { 107 , 11} , { 108 , 7} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
109 , 11} , { 110 , 5} , { 111 , 11} , { 112 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 113 , 11} , { 114 , 9} , { 115 , 12} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
116 , 12} , { 118 , 12} , { 119 , 9} , { 121 , 9}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 123 , 10} , { 124 , 11} , { 125 , 6} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
126 , 11} , { 127 , 11} , { 128 , 11} , { 129 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 130 , 11} , { 131 , 11} , { 132 , 11} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
133 , 11} , { 134 , 11} , { 135 , 11} , { 136 , 9}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 138 , 9} , { 139 , 9} , { 140 , 11} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
141 , 9} , { 142 , 8} , { 149 , 19} , { 143 , 0}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 144 , 11} , { 145 , 11} , { 146 , 11} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
191 , 11} , { 147 , 11} , { 150 , 11} , { 155 , 0}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 156 , 0} , { 158 , 6} , { 159 , 0} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
160 , 11} , { 161 , 0} , { 162 , 10} , { 163 , 6}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 164 , 6} , { 165 , 11} , { 166 , 12} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
167 , 0} , { 168 , 11} , { 169 , 11} , { 170 , 9}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 171 , 9} , { 172 , 11} , { 173 , 0} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
174 , 10} , { 175 , 10} , { 176 , 10} , { 177 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 178 , 0} , { 179 , 0} , { 180 , 11} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
181 , 9} , { 182 , 0} , { 184 , 11} , { 185 , 0}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 186 , 0} , { 188 , 11} , { 200 , 2} , {
# 66 "/home/claude/cfront-3/src/node_classes.h"
201 , 3} , { 202 , 16} , { 203 , 17} , { 157 , 11}
# 66 "/home/claude/cfront-3/src/node_classes.h"
, { 211 , 0} } ;

# 31 "/home/claude/cfront-3/src/discrim.cpp"
int discriminator__8basetypeFi (struct basetype *__0this , int __1which_union )
# 32 "/home/claude/cfront-3/src/discrim.cpp"
{ 
# 33 "/home/claude/cfront-3/src/discrim.cpp"
switch (__1which_union )
# 34 "/home/claude/cfront-3/src/discrim.cpp"
{ 
# 35 "/home/claude/cfront-3/src/discrim.cpp"
case 0 :
# 36 "/home/claude/cfront-3/src/discrim.cpp"
switch (__0this -> base__4node ){ 
# 37 "/home/claude/cfront-3/src/discrim.cpp"
case 114 :return 1 ;
# 37 "/home/claude/cfront-3/src/discrim.cpp"

# 38 "/home/claude/cfront-3/src/discrim.cpp"
case 108 :return 2 ;
default :return (int )0;
}
default :
# 42 "/home/claude/cfront-3/src/discrim.cpp"
return (int )-1;
}
}

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 53 "/home/claude/cfront-3/src/discrim.cpp"
int discriminator__4exprFi (register struct expr *__0this , int __1which_union )
# 54 "/home/claude/cfront-3/src/discrim.cpp"
{ 
# 55 "/home/claude/cfront-3/src/discrim.cpp"
switch (__1which_union ){ 
# 56 "/home/claude/cfront-3/src/discrim.cpp"
case 0 :
# 57 "/home/claude/cfront-3/src/discrim.cpp"
return 1 ;
case 1 :
# 59 "/home/claude/cfront-3/src/discrim.cpp"
switch (__0this -> base__4node ){ 
# 60 "/home/claude/cfront-3/src/discrim.cpp"
case 111 :
# 61 "/home/claude/cfront-3/src/discrim.cpp"
case 168 :
# 62 "/home/claude/cfront-3/src/discrim.cpp"
case 44 :
# 63 "/home/claude/cfront-3/src/discrim.cpp"
case 45 :
# 64 "/home/claude/cfront-3/src/discrim.cpp"
case 157 :
# 65 "/home/claude/cfront-3/src/discrim.cpp"
case 30 :
# 66 "/home/claude/cfront-3/src/discrim.cpp"
case 23 :
# 67 "/home/claude/cfront-3/src/discrim.cpp"
case 213 :
# 68 "/home/claude/cfront-3/src/discrim.cpp"
case 184 :
# 69 "/home/claude/cfront-3/src/discrim.cpp"
case
# 69 "/home/claude/cfront-3/src/discrim.cpp"
9 :
# 70 "/home/claude/cfront-3/src/discrim.cpp"
case 212 :
# 71 "/home/claude/cfront-3/src/discrim.cpp"
case 113 :
# 72 "/home/claude/cfront-3/src/discrim.cpp"
case 191 :
# 73 "/home/claude/cfront-3/src/discrim.cpp"
case 109 :
# 74 "/home/claude/cfront-3/src/discrim.cpp"
case 146 :
# 75 "/home/claude/cfront-3/src/discrim.cpp"
case 70 :
# 76 "/home/claude/cfront-3/src/discrim.cpp"
case 62 :
# 77 "/home/claude/cfront-3/src/discrim.cpp"
case 63 :
# 78 "/home/claude/cfront-3/src/discrim.cpp"
case 60 :
# 79 "/home/claude/cfront-3/src/discrim.cpp"
case 61 :
# 80 "/home/claude/cfront-3/src/discrim.cpp"
case 59 :
# 81 "/home/claude/cfront-3/src/discrim.cpp"
case 58 :
# 82 "/home/claude/cfront-3/src/discrim.cpp"
case 140 :
# 83 "/home/claude/cfront-3/src/discrim.cpp"
case
# 83 "/home/claude/cfront-3/src/discrim.cpp"
124 :
# 84 "/home/claude/cfront-3/src/discrim.cpp"
case 68 :
# 85 "/home/claude/cfront-3/src/discrim.cpp"
case 71 :
# 86 "/home/claude/cfront-3/src/discrim.cpp"
case 147 :
# 87 "/home/claude/cfront-3/src/discrim.cpp"
case 54 :
# 88 "/home/claude/cfront-3/src/discrim.cpp"
case 55 :
# 89 "/home/claude/cfront-3/src/discrim.cpp"
case 50 :
# 90 "/home/claude/cfront-3/src/discrim.cpp"
case 51 :
# 91 "/home/claude/cfront-3/src/discrim.cpp"
case 53 :
# 92 "/home/claude/cfront-3/src/discrim.cpp"
case 56 :
# 93 "/home/claude/cfront-3/src/discrim.cpp"
case 57 :
# 94 "/home/claude/cfront-3/src/discrim.cpp"
case 52 :
# 95 "/home/claude/cfront-3/src/discrim.cpp"
case 65 :
# 96 "/home/claude/cfront-3/src/discrim.cpp"
case 64 :
# 97 "/home/claude/cfront-3/src/discrim.cpp"
case
# 97 "/home/claude/cfront-3/src/discrim.cpp"
66 :
# 98 "/home/claude/cfront-3/src/discrim.cpp"
case 67 :
# 99 "/home/claude/cfront-3/src/discrim.cpp"
case 132 :
# 100 "/home/claude/cfront-3/src/discrim.cpp"
case 133 :
# 101 "/home/claude/cfront-3/src/discrim.cpp"
case 131 :
# 102 "/home/claude/cfront-3/src/discrim.cpp"
case 126 :
# 103 "/home/claude/cfront-3/src/discrim.cpp"
case 127 :
# 104 "/home/claude/cfront-3/src/discrim.cpp"
case 128 :
# 105 "/home/claude/cfront-3/src/discrim.cpp"
case 130 :
# 106 "/home/claude/cfront-3/src/discrim.cpp"
case 129 :
# 107 "/home/claude/cfront-3/src/discrim.cpp"
case 134 :
# 108 "/home/claude/cfront-3/src/discrim.cpp"
case 135 :
# 109 "/home/claude/cfront-3/src/discrim.cpp"
case 49 :
# 110 "/home/claude/cfront-3/src/discrim.cpp"
case 48 :
# 111 "/home/claude/cfront-3/src/discrim.cpp"
return
# 111 "/home/claude/cfront-3/src/discrim.cpp"
1 ;
case 177 :
# 113 "/home/claude/cfront-3/src/discrim.cpp"
case 150 :
# 114 "/home/claude/cfront-3/src/discrim.cpp"
return 2 ;
case 123 :
# 116 "/home/claude/cfront-3/src/discrim.cpp"
case 85 :
# 117 "/home/claude/cfront-3/src/discrim.cpp"
case 82 :
# 118 "/home/claude/cfront-3/src/discrim.cpp"
case 83 :
# 119 "/home/claude/cfront-3/src/discrim.cpp"
case 84 :
# 120 "/home/claude/cfront-3/src/discrim.cpp"
case 80 :
# 121 "/home/claude/cfront-3/src/discrim.cpp"
case 81 :
# 122 "/home/claude/cfront-3/src/discrim.cpp"
case 165 :
# 123 "/home/claude/cfront-3/src/discrim.cpp"
return 3 ;
default :return (int )0;
}
case 2 :
# 131 "/home/claude/cfront-3/src/discrim.cpp"
if (__0this -> __O3__4expr.i2 == 1 )return 2 ;
switch (__0this -> base__4node ){ 
# 133 "/home/claude/cfront-3/src/discrim.cpp"
case 9 :
# 134 "/home/claude/cfront-3/src/discrim.cpp"
case 157 :
# 135 "/home/claude/cfront-3/src/discrim.cpp"
case 168 :
# 136 "/home/claude/cfront-3/src/discrim.cpp"
case 109 :
# 137 "/home/claude/cfront-3/src/discrim.cpp"
case 146 :
# 138 "/home/claude/cfront-3/src/discrim.cpp"
case 70 :
# 139 "/home/claude/cfront-3/src/discrim.cpp"
case 62 :
# 140 "/home/claude/cfront-3/src/discrim.cpp"
case 63 :
# 141 "/home/claude/cfront-3/src/discrim.cpp"
case 60 :
# 142 "/home/claude/cfront-3/src/discrim.cpp"
case 61 :
# 143 "/home/claude/cfront-3/src/discrim.cpp"
case
# 143 "/home/claude/cfront-3/src/discrim.cpp"
59 :
# 144 "/home/claude/cfront-3/src/discrim.cpp"
case 58 :
# 145 "/home/claude/cfront-3/src/discrim.cpp"
case 111 :
# 146 "/home/claude/cfront-3/src/discrim.cpp"
case 140 :
# 147 "/home/claude/cfront-3/src/discrim.cpp"
case 68 :
# 148 "/home/claude/cfront-3/src/discrim.cpp"
case 71 :
# 149 "/home/claude/cfront-3/src/discrim.cpp"
case 147 :
# 150 "/home/claude/cfront-3/src/discrim.cpp"
case 107 :
# 151 "/home/claude/cfront-3/src/discrim.cpp"
case 46 :
# 152 "/home/claude/cfront-3/src/discrim.cpp"
case 47 :
# 153 "/home/claude/cfront-3/src/discrim.cpp"
case 112 :
# 154 "/home/claude/cfront-3/src/discrim.cpp"
case 145 :
# 155 "/home/claude/cfront-3/src/discrim.cpp"
case 54 :
# 156 "/home/claude/cfront-3/src/discrim.cpp"
case 55 :
# 157 "/home/claude/cfront-3/src/discrim.cpp"
case
# 157 "/home/claude/cfront-3/src/discrim.cpp"
50 :
# 158 "/home/claude/cfront-3/src/discrim.cpp"
case 51 :
# 159 "/home/claude/cfront-3/src/discrim.cpp"
case 53 :
# 160 "/home/claude/cfront-3/src/discrim.cpp"
case 56 :
# 161 "/home/claude/cfront-3/src/discrim.cpp"
case 57 :
# 162 "/home/claude/cfront-3/src/discrim.cpp"
case 52 :
# 163 "/home/claude/cfront-3/src/discrim.cpp"
case 65 :
# 164 "/home/claude/cfront-3/src/discrim.cpp"
case 64 :
# 165 "/home/claude/cfront-3/src/discrim.cpp"
case 66 :
# 166 "/home/claude/cfront-3/src/discrim.cpp"
case 67 :
# 167 "/home/claude/cfront-3/src/discrim.cpp"
case 132 :
# 168 "/home/claude/cfront-3/src/discrim.cpp"
case 133 :
# 169 "/home/claude/cfront-3/src/discrim.cpp"
case 131 :
# 170 "/home/claude/cfront-3/src/discrim.cpp"
case 126 :
# 171 "/home/claude/cfront-3/src/discrim.cpp"
case
# 171 "/home/claude/cfront-3/src/discrim.cpp"
127 :
# 172 "/home/claude/cfront-3/src/discrim.cpp"
case 128 :
# 173 "/home/claude/cfront-3/src/discrim.cpp"
case 130 :
# 174 "/home/claude/cfront-3/src/discrim.cpp"
case 129 :
# 175 "/home/claude/cfront-3/src/discrim.cpp"
case 134 :
# 176 "/home/claude/cfront-3/src/discrim.cpp"
case 135 :
# 177 "/home/claude/cfront-3/src/discrim.cpp"
case 49 :
# 178 "/home/claude/cfront-3/src/discrim.cpp"
case 48 :
# 179 "/home/claude/cfront-3/src/discrim.cpp"
case 23 :
# 180 "/home/claude/cfront-3/src/discrim.cpp"
return 1 ;
case 165 :
# 182 "/home/claude/cfront-3/src/discrim.cpp"
return 3 ;
case 123 :
# 184 "/home/claude/cfront-3/src/discrim.cpp"
if ((__0this -> __O1__4expr.tp -> base__4node != 119 )&& (__0this -> __O1__4expr.tp -> base__4node != 121 ))
# 185 "/home/claude/cfront-3/src/discrim.cpp"
return 5 ;

# 187 "/home/claude/cfront-3/src/discrim.cpp"
case 85 :
# 191 "/home/claude/cfront-3/src/discrim.cpp"
return 4 ;
default :return (int )0;
}
case 3 :
# 195 "/home/claude/cfront-3/src/discrim.cpp"
switch (__0this -> base__4node ){ 
# 196 "/home/claude/cfront-3/src/discrim.cpp"
case 157 :
# 197 "/home/claude/cfront-3/src/discrim.cpp"
case 30 :
# 198 "/home/claude/cfront-3/src/discrim.cpp"
case 23 :
# 199 "/home/claude/cfront-3/src/discrim.cpp"
case 184 :
# 200 "/home/claude/cfront-3/src/discrim.cpp"
case 113 :
# 201 "/home/claude/cfront-3/src/discrim.cpp"
case 191 :
# 202 "/home/claude/cfront-3/src/discrim.cpp"
return 1 ;
case 109 :
# 204 "/home/claude/cfront-3/src/discrim.cpp"
case 146 :
# 205 "/home/claude/cfront-3/src/discrim.cpp"
return 2 ;
case 68 :
# 207 "/home/claude/cfront-3/src/discrim.cpp"
return 3 ;
case 44 :
# 209 "/home/claude/cfront-3/src/discrim.cpp"
case 45 :
# 210 "/home/claude/cfront-3/src/discrim.cpp"
case 177 :
# 211 "/home/claude/cfront-3/src/discrim.cpp"
return 4 ;
case 132 :
# 213 "/home/claude/cfront-3/src/discrim.cpp"
case 133 :
# 214 "/home/claude/cfront-3/src/discrim.cpp"
case 131 :
# 215 "/home/claude/cfront-3/src/discrim.cpp"
case 126 :
# 216 "/home/claude/cfront-3/src/discrim.cpp"
case 127 :
# 217 "/home/claude/cfront-3/src/discrim.cpp"
case 128 :
# 218 "/home/claude/cfront-3/src/discrim.cpp"
case 130 :
# 219 "/home/claude/cfront-3/src/discrim.cpp"
case 129 :
# 220 "/home/claude/cfront-3/src/discrim.cpp"
case 134 :
# 221 "/home/claude/cfront-3/src/discrim.cpp"
case 135 :
# 222 "/home/claude/cfront-3/src/discrim.cpp"
case 49 :
# 223 "/home/claude/cfront-3/src/discrim.cpp"
case 48 :
# 224 "/home/claude/cfront-3/src/discrim.cpp"
case 70 :
# 225 "/home/claude/cfront-3/src/discrim.cpp"
return
# 225 "/home/claude/cfront-3/src/discrim.cpp"
5 ;

# 227 "/home/claude/cfront-3/src/discrim.cpp"
case 85 :
# 228 "/home/claude/cfront-3/src/discrim.cpp"
case 123 :
# 229 "/home/claude/cfront-3/src/discrim.cpp"
if (((((struct name *)(((struct name *)__0this ))))-> n_oper__4name == 97 )&& (strcmp ( (((struct name *)(((struct name *)__0this ))))-> __O2__4expr.string , (const
# 229 "/home/claude/cfront-3/src/discrim.cpp"
char *)"_type") == 0 ))
# 231 "/home/claude/cfront-3/src/discrim.cpp"
{ 
# 233 "/home/claude/cfront-3/src/discrim.cpp"
return 3 ;
}
return 6 ;

# 237 "/home/claude/cfront-3/src/discrim.cpp"
case 168 :
# 238 "/home/claude/cfront-3/src/discrim.cpp"
case 169 :
# 239 "/home/claude/cfront-3/src/discrim.cpp"
return 7 ;

# 241 "/home/claude/cfront-3/src/discrim.cpp"
default :return (int )0;
}

# 244 "/home/claude/cfront-3/src/discrim.cpp"
default :
# 245 "/home/claude/cfront-3/src/discrim.cpp"
return (int )-1;
}
}

# 249 "/home/claude/cfront-3/src/discrim.cpp"
int discriminator__4nameFi (struct name *__0this , int __1which_union )
# 250 "/home/claude/cfront-3/src/discrim.cpp"
{ 
# 251 "/home/claude/cfront-3/src/discrim.cpp"
switch (__1which_union ){ 
# 252 "/home/claude/cfront-3/src/discrim.cpp"
case 0 :
# 253 "/home/claude/cfront-3/src/discrim.cpp"
if (__0this -> base__4node == 115 )return 2 ;
else return 1 ;
default :
# 256 "/home/claude/cfront-3/src/discrim.cpp"
return (int )-1;
}
}

# 260 "/home/claude/cfront-3/src/discrim.cpp"
int discriminator__4stmtFi (register struct stmt *__0this , int __1which_union )
# 261 "/home/claude/cfront-3/src/discrim.cpp"
{ 
# 262 "/home/claude/cfront-3/src/discrim.cpp"
switch (__1which_union ){ 
# 263 "/home/claude/cfront-3/src/discrim.cpp"
case 0 :
# 264 "/home/claude/cfront-3/src/discrim.cpp"
switch (__0this -> base__4node ){ 
# 265 "/home/claude/cfront-3/src/discrim.cpp"
case 116 :
# 266 "/home/claude/cfront-3/src/discrim.cpp"
case
# 266 "/home/claude/cfront-3/src/discrim.cpp"
19 :
# 267 "/home/claude/cfront-3/src/discrim.cpp"
case 115 :
# 268 "/home/claude/cfront-3/src/discrim.cpp"
case 118 :
# 269 "/home/claude/cfront-3/src/discrim.cpp"
return 1 ;
case 16 :
# 271 "/home/claude/cfront-3/src/discrim.cpp"
return 2 ;
case 33 :
# 273 "/home/claude/cfront-3/src/discrim.cpp"
return 3 ;
case 166 :
# 275 "/home/claude/cfront-3/src/discrim.cpp"
case 28 :
# 276 "/home/claude/cfront-3/src/discrim.cpp"
return 4 ;
default :return (int )0;
}
case 1 :
# 280 "/home/claude/cfront-3/src/discrim.cpp"
switch (__0this -> base__4node ){ 
# 281 "/home/claude/cfront-3/src/discrim.cpp"
case 16 :
# 282 "/home/claude/cfront-3/src/discrim.cpp"
case 20 :
# 283 "/home/claude/cfront-3/src/discrim.cpp"
case 39 :
# 284 "/home/claude/cfront-3/src/discrim.cpp"
case 10 :
# 285 "/home/claude/cfront-3/src/discrim.cpp"
case 28 :
# 286 "/home/claude/cfront-3/src/discrim.cpp"
case 33 :
# 287 "/home/claude/cfront-3/src/discrim.cpp"
case 72 :
# 288 "/home/claude/cfront-3/src/discrim.cpp"
case 207 :
# 289 "/home/claude/cfront-3/src/discrim.cpp"
case 4 :
# 290 "/home/claude/cfront-3/src/discrim.cpp"
return
# 290 "/home/claude/cfront-3/src/discrim.cpp"
1 ;
case 116 :
# 292 "/home/claude/cfront-3/src/discrim.cpp"
return 2 ;
case 166 :
# 294 "/home/claude/cfront-3/src/discrim.cpp"
return 3 ;
default :
# 296 "/home/claude/cfront-3/src/discrim.cpp"
return (int )0;
}
case 2 :
# 299 "/home/claude/cfront-3/src/discrim.cpp"
switch (__0this -> base__4node ){ 
# 300 "/home/claude/cfront-3/src/discrim.cpp"
case 16 :
# 301 "/home/claude/cfront-3/src/discrim.cpp"
return 1 ;
case 20 :
# 303 "/home/claude/cfront-3/src/discrim.cpp"
return 2 ;
case 33 :
# 305 "/home/claude/cfront-3/src/discrim.cpp"
case 4 :
# 306 "/home/claude/cfront-3/src/discrim.cpp"
return 3 ;
default :
# 308 "/home/claude/cfront-3/src/discrim.cpp"
return (int )0;
}
default :
# 311 "/home/claude/cfront-3/src/discrim.cpp"
return (int )-1;
}
}

# 315 "/home/claude/cfront-3/src/discrim.cpp"
static int token_to_class_map [214];
static char map_initialized ;

# 318 "/home/claude/cfront-3/src/discrim.cpp"
int classify_node__FP4nodeRi (Pnode __1node , int *__1error )
# 319 "/home/claude/cfront-3/src/discrim.cpp"
{ 
# 320 "/home/claude/cfront-3/src/discrim.cpp"
size_t __1ncx ;
int __1nclass ;

# 323 "/home/claude/cfront-3/src/discrim.cpp"
((*__1error ))= 0 ;

# 325 "/home/claude/cfront-3/src/discrim.cpp"
if (! map_initialized ){ 
# 326 "/home/claude/cfront-3/src/discrim.cpp"
map_initialized = 1 ;
for(__1ncx = 0 ;__1ncx < ((sizeof token_classes )/ (sizeof (struct token_class )));__1ncx ++ ) 
# 330 "/home/claude/cfront-3/src/discrim.cpp"
(token_to_class_map [(token_classes [__1ncx ]). token__11token_class ])= (token_classes [__1ncx ]). nclass__11token_class ;
}

# 333 "/home/claude/cfront-3/src/discrim.cpp"
if (! ((__1node -> base__4node > 0 )&& (__1node -> base__4node < 214 ))){ 
# 334 "/home/claude/cfront-3/src/discrim.cpp"
((*__1error ))= 1 ;
return (int )0;
}

# 338 "/home/claude/cfront-3/src/discrim.cpp"
__1nclass = (token_to_class_map [__1node -> base__4node ]);

# 340 "/home/claude/cfront-3/src/discrim.cpp"
switch (__1nclass ){ 
# 341 "/home/claude/cfront-3/src/discrim.cpp"
case 7:
# 342 "/home/claude/cfront-3/src/discrim.cpp"
case 10:
# 343 "/home/claude/cfront-3/src/discrim.cpp"
if (__1node -> baseclass__4node )__1nclass = 15;
}

# 346 "/home/claude/cfront-3/src/discrim.cpp"
return __1nclass ;
}

# 349 "/home/claude/cfront-3/src/discrim.cpp"
int classify_node__FP4node (Pnode __1node )
# 350 "/home/claude/cfront-3/src/discrim.cpp"
{ 
# 351 "/home/claude/cfront-3/src/discrim.cpp"
int __1err ;
int __1nclass ;

# 352 "/home/claude/cfront-3/src/discrim.cpp"
__1nclass = classify_node__FP4nodeRi ( __1node , (int *)(& __1err )) ;
if (__1err )error__FiPCc ( (int )'i' , (const char *)"failed to classify node.") ;
return __1nclass ;
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

# 355 "/home/claude/cfront-3/src/discrim.cpp"

/* the end */
