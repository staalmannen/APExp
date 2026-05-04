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

#pragma lib "ape/libap.a"

# 20 "/home/claude/incl-linux32/generic.h"
typedef int (*GPT )(int , char *);

# 22 "/home/claude/cfront-3/src/Bits.h"
typedef size_t Bits_chunk ;

# 24 "/home/claude/cfront-3/src/Bits.h"

# 25 "/home/claude/cfront-3/src/Bits.h"
struct Block_Bits_chunk;

# 27 "/home/claude/cfront-3/src/Bits.h"
struct Block_Bits_chunk {	/* sizeof Block_Bits_chunk == 16 */

# 27 "/home/claude/cfront-3/src/Bits.h"
Bits_chunk *p__16Block_Bits_chunk ;

# 27 "/home/claude/cfront-3/src/Bits.h"
size_t n__16Block_Bits_chunk ;
};

# 27 "/home/claude/cfront-3/src/Bits.h"
void move__16Block_Bits_chunkFPUlUl (struct Block_Bits_chunk *__0this , Bits_chunk *, size_t );

# 27 "/home/claude/cfront-3/src/Bits.h"
void copy__16Block_Bits_chunkFRC16Block_Bits_chunk (struct Block_Bits_chunk *__0this , const struct Block_Bits_chunk *);

# 1 ""
extern void __dl__FPv (void *);

# 27 "/home/claude/cfront-3/src/Bits.h"
size_t grow__16Block_Bits_chunkFUl (struct Block_Bits_chunk *__0this , size_t );
struct Bits;

# 29 "/home/claude/cfront-3/src/Bits.h"
struct Bits {	/* sizeof Bits == 24 */

# 31 "/home/claude/cfront-3/src/Bits.h"
struct Block_Bits_chunk b__4Bits ;
size_t n__4Bits ;
};

# 27 "/home/claude/cfront-3/src/Bits.h"

# 40 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 40 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 121 "/home/claude/cfront-3/src/Bits.h"
size_t signif__4BitsCFv (const struct Bits *const __0this );

# 67 "/home/claude/cfront-3/src/Bits.h"
size_t size__4BitsFUl (struct Bits *__0this , size_t );

# 27 "/home/claude/cfront-3/src/Bits.h"

# 60 "/home/claude/cfront-3/src/Bits.h"
int compare__4BitsCFRC4Bits (const struct Bits *const __0this , const struct Bits *);
int equal__4BitsCFRC4Bits (const struct Bits *const __0this , const struct Bits *);

# 26 "/home/claude/cfront-3/src/overload.h"

# 27 "/home/claude/cfront-3/src/overload.h"

# 28 "/home/claude/cfront-3/src/overload.h"

# 29 "/home/claude/cfront-3/src/overload.h"

# 30 "/home/claude/cfront-3/src/overload.h"

# 31 "/home/claude/cfront-3/src/overload.h"

# 33 "/home/claude/cfront-3/src/overload.h"
extern int ambig ;
extern int no_const ;
extern int non_const ;
struct Block_Pname;

# 39 "/home/claude/cfront-3/src/overload.h"
struct Block_Pname {	/* sizeof Block_Pname == 16 */

# 39 "/home/claude/cfront-3/src/overload.h"
Pname *p__11Block_Pname ;

# 39 "/home/claude/cfront-3/src/overload.h"
size_t n__11Block_Pname ;
};

# 39 "/home/claude/cfront-3/src/overload.h"
void move__11Block_PnameFPP4nameUl (struct Block_Pname *__0this , Pname *, size_t );

# 39 "/home/claude/cfront-3/src/overload.h"
void copy__11Block_PnameFRC11Block_Pname (struct Block_Pname *__0this , const struct Block_Pname *);

# 39 "/home/claude/cfront-3/src/overload.h"
size_t grow__11Block_PnameFUl (struct Block_Pname *__0this , size_t );
typedef struct Block_Pname BlockPname ;
struct Block_BlockPname;
struct Block_BlockPname {	/* sizeof Block_BlockPname == 16 */

# 41 "/home/claude/cfront-3/src/overload.h"
BlockPname *p__16Block_BlockPname ;

# 41 "/home/claude/cfront-3/src/overload.h"
size_t n__16Block_BlockPname ;
};

# 41 "/home/claude/cfront-3/src/overload.h"
void move__16Block_BlockPnameFP11Block_PnameUl (struct Block_BlockPname *__0this , BlockPname *, size_t );

# 39 "/home/claude/cfront-3/src/overload.h"
static struct Block_Pname *__ct__11Block_PnameFv (struct Block_Pname *__0this );

# 41 "/home/claude/cfront-3/src/overload.h"
void copy__16Block_BlockPnameFRC16Block_BlockPname (struct Block_BlockPname *__0this , const struct Block_BlockPname *);

# 39 "/home/claude/cfront-3/src/overload.h"
static void __dt__11Block_PnameFv (struct Block_Pname *__0this , int __0__free );

# 41 "/home/claude/cfront-3/src/overload.h"
size_t grow__16Block_BlockPnameFUl (struct Block_BlockPname *__0this , size_t );
struct Block_int;
struct Block_int {	/* sizeof Block_int == 16 */

# 42 "/home/claude/cfront-3/src/overload.h"
int *p__9Block_int ;

# 42 "/home/claude/cfront-3/src/overload.h"
size_t n__9Block_int ;
};

# 42 "/home/claude/cfront-3/src/overload.h"
void move__9Block_intFPiUl (struct Block_int *__0this , int *, size_t );

# 42 "/home/claude/cfront-3/src/overload.h"
void copy__9Block_intFRC9Block_int (struct Block_int *__0this , const struct Block_int *);

# 42 "/home/claude/cfront-3/src/overload.h"
size_t grow__9Block_intFUl (struct Block_int *__0this , size_t );

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

# 27 "/home/claude/cfront-3/src/expr2.cpp"
static int const_obj1 ;

# 27 "/home/claude/cfront-3/src/expr2.cpp"
static int const_obj2 ;

# 44 "/home/claude/cfront-3/src/overload.h"
extern Pname hier_dominates__FP4nameT1 (Pname , Pname );

# 1288 "/home/claude/cfront-3/src/cfront.h"

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 342 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr__4typeFv (struct type *__0this );

# 33 "/home/claude/cfront-3/src/expr2.cpp"
Pname really_dominate__FP4nameT1Uc (Pname __1on1 , Pname __1on2 , bit __1tc )
# 34 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 36 "/home/claude/cfront-3/src/expr2.cpp"
Pname __1best ;

# 36 "/home/claude/cfront-3/src/expr2.cpp"
__1best = hier_dominates__FP4nameT1 ( __1on1 , __1on2 ) ;
if (__1best )return __1best ;

# 39 "/home/claude/cfront-3/src/expr2.cpp"
{ Pfct __1f1 ;
Pfct __1f2 ;

# 42 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __1t1 ;
Ptype __1t2 ;

# 39 "/home/claude/cfront-3/src/expr2.cpp"
__1f1 = ( ((__1on1 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1on1 -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__1on1 -> __O1__4expr.tp ))))->
# 39 "/home/claude/cfront-3/src/expr2.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;
__1f2 = ( ((__1on2 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1on2 -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__1on2 -> __O1__4expr.tp ))))->
# 40 "/home/claude/cfront-3/src/expr2.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;

# 42 "/home/claude/cfront-3/src/expr2.cpp"
__1t1 = skiptypedefs__4typeFv ( __1f1 -> returns__3fct ) ;
__1t2 = skiptypedefs__4typeFv ( __1f2 -> returns__3fct ) ;

# 45 "/home/claude/cfront-3/src/expr2.cpp"
if (is_ref__4typeFv ( __1t1 ) )__1t1 = (((struct ptr *)(((struct ptr *)__1t1 ))))-> typ__5pvtyp ;
if (is_ref__4typeFv ( __1t2 ) )__1t2 = (((struct ptr *)(((struct ptr *)__1t2 ))))-> typ__5pvtyp ;

# 48 "/home/claude/cfront-3/src/expr2.cpp"
if (((((! __1t1 )|| (! __1t2 ))|| (check__4typeFP4typeUcT2 ( __1t1 , __1t2 , (unsigned char )76 , (unsigned char )0 )
# 48 "/home/claude/cfront-3/src/expr2.cpp"
&& (! const_problem )))|| (((is_ref__4typeFv ( __1t1 ) && is_ref__4typeFv ( __1t2 ) )&& check__4typeFP4typeUcT2 ( (((struct ptr *)(((struct ptr *)__1t1 ))))-> typ__5pvtyp ,
# 48 "/home/claude/cfront-3/src/expr2.cpp"
(((struct ptr *)(((struct ptr *)__1t2 ))))-> typ__5pvtyp , (unsigned char )76 , (unsigned char )0 ) )&& (! const_problem )))|| (((is_ptr__4typeFv (
# 48 "/home/claude/cfront-3/src/expr2.cpp"
__1t1 ) && is_ptr__4typeFv ( __1t2 ) )&& check__4typeFP4typeUcT2 ( (((struct ptr *)(((struct ptr *)__1t1 ))))-> typ__5pvtyp , (((struct ptr *)(((struct ptr *)__1t2 ))))-> typ__5pvtyp ,
# 48 "/home/claude/cfront-3/src/expr2.cpp"
(unsigned char )76 , (unsigned char )0 ) )&& (! const_problem )))
# 61 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 62 "/home/claude/cfront-3/src/expr2.cpp"
return (struct name *)0 ;
}

# 66 "/home/claude/cfront-3/src/expr2.cpp"
{ int __1c1 ;
int __1c2 ;

# 66 "/home/claude/cfront-3/src/expr2.cpp"
__1c1 = __1f1 -> f_const__3fct ;
__1c2 = __1f2 -> f_const__3fct ;

# 69 "/home/claude/cfront-3/src/expr2.cpp"
if (__1c1 == __1c2 );
else if (__1c1 && (! __1c2 ))return (__1tc ?__1on1 :__1on2 );
else if (__1c2 && (! __1c1 ))return (__1tc ?__1on2 :__1on1 );

# 73 "/home/claude/cfront-3/src/expr2.cpp"
return (struct name *)0 ;

# 73 "/home/claude/cfront-3/src/expr2.cpp"
}

# 73 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/expr2.cpp"
void assign__4nameFv (register struct name *__0this )
# 77 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 78 "/home/claude/cfront-3/src/expr2.cpp"
if ((__0this -> n_assigned_to__4name ++ )== 0 ){ 
# 79 "/home/claude/cfront-3/src/expr2.cpp"
switch (__0this -> n_scope__4name ){ 
# 80 "/home/claude/cfront-3/src/expr2.cpp"
case 108 :
# 81 "/home/claude/cfront-3/src/expr2.cpp"
if
# 81 "/home/claude/cfront-3/src/expr2.cpp"
(__0this -> n_used__4name && (__0this -> n_addr_taken__4name == 0 )){ 
# 82 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __4t ;

# 82 "/home/claude/cfront-3/src/expr2.cpp"
__4t = skiptypedefs__4typeFv ( __0this -> __O1__4expr.tp ) ;
switch (__4t -> base__4node ){ 
# 84 "/home/claude/cfront-3/src/expr2.cpp"
case 110 :
# 85 "/home/claude/cfront-3/src/expr2.cpp"
break ;
default :
# 87 "/home/claude/cfront-3/src/expr2.cpp"
if (curr_loop )
# 88 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 88 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V46 ;

# 88 "/home/claude/cfront-3/src/expr2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __0this -> where__4name , (const char *)"%n may have been used before set", (const
# 88 "/home/claude/cfront-3/src/expr2.cpp"
struct ea *)( ((& __0__V46 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V46 )) , (const struct ea *)ea0 ,
# 88 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 90 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 90 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V47 ;

# 90 "/home/claude/cfront-3/src/expr2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __0this -> where__4name , (const char *)"%n used before set", (const
# 90 "/home/claude/cfront-3/src/expr2.cpp"
struct ea *)( ((& __0__V47 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V47 )) , (const struct ea *)ea0 ,
# 90 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
}
}
}

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 449 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8classdefFP4name (struct classdef *__0this , Pname );

# 97 "/home/claude/cfront-3/src/expr2.cpp"
void take_addr__4nameFv (register struct name *__0this )
# 98 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 98 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X16 ;

# 98 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1400qm5qkxojwcnm ;

# 98 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1500qm5qkxojwcnm ;

# 102 "/home/claude/cfront-3/src/expr2.cpp"
if ((((warning_opt && (! __0this -> n_addr_taken__4name ))&& __0this -> __O1__4expr.tp )&& (__0this -> __O1__4expr.tp -> base__4node == 108 ))&& ( ((__0this -> __O1__4expr.tp ->
# 102 "/home/claude/cfront-3/src/expr2.cpp"
base__4node == 108 )?(((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF",
# 102 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)( ((& __0__X__V1400qm5qkxojwcnm )-> __O1__2ea.p = ((const void *)__0this )), (& __0__X__V1400qm5qkxojwcnm )) , (const struct
# 102 "/home/claude/cfront-3/src/expr2.cpp"
ea *)( (__2__X16 = __0this -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qm5qkxojwcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (&
# 102 "/home/claude/cfront-3/src/expr2.cpp"
__0__X__V1500qm5qkxojwcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ->
# 102 "/home/claude/cfront-3/src/expr2.cpp"
f_inline__3fct )
# 103 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 103 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V48 ;

# 103 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V49 ;

# 103 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"can't take address of inlineF%n,%n not inlined", (const struct ea *)( ((&
# 103 "/home/claude/cfront-3/src/expr2.cpp"
__0__V48 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V48 )) , (const struct ea *)( ((& __0__V49 )-> __O1__2ea.p =
# 103 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__0this )), (& __0__V49 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __0this -> n_addr_taken__4name ++ ;
if ((__0this -> n_sto__4name == 14 )&& __0this -> __O1__4expr.tp ){ 
# 106 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __2t ;

# 106 "/home/claude/cfront-3/src/expr2.cpp"
__2t = skiptypedefs__4typeFv ( __0this -> __O1__4expr.tp ) ;
switch (__2t -> base__4node ){ 
# 108 "/home/claude/cfront-3/src/expr2.cpp"
case 119 :
# 109 "/home/claude/cfront-3/src/expr2.cpp"
__2t = (((struct basetype *)(((struct basetype *)__2t ))))-> b_name__8basetype -> __O1__4expr.tp ;
case 6 :{ 
# 111 "/home/claude/cfront-3/src/expr2.cpp"
Pclass __4cl ;

# 111 "/home/claude/cfront-3/src/expr2.cpp"
__4cl = (((struct classdef *)(((struct classdef *)__2t ))));
if (__4cl -> c_body__8classdef == 1 )
# 113 "/home/claude/cfront-3/src/expr2.cpp"
dcl_print__8classdefFP4name ( __4cl , (struct name *)0 ) ;
}
}
}
}

# 119 "/home/claude/cfront-3/src/expr2.cpp"
int ignore_const = 0 ;

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 120 "/home/claude/cfront-3/src/expr2.cpp"
static int is_dataMemPtr__FP4expr (Pexpr );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 122 "/home/claude/cfront-3/src/expr2.cpp"
int lval__4exprFUc (struct expr *__0this , TOK __1oper );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 828 "/home/claude/cfront-3/src/cfront.h"

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 122 "/home/claude/cfront-3/src/expr2.cpp"
int lval__4exprFUc (register struct expr *__0this , TOK __1oper )
# 123 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 124 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __1ee ;
Pname __1n ;
int __1deref ;
const char *__1es ;

# 124 "/home/claude/cfront-3/src/expr2.cpp"
__1ee = __0this ;

# 126 "/home/claude/cfront-3/src/expr2.cpp"
__1deref = 0 ;

# 131 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1oper ){ 
# 132 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 133 "/home/claude/cfront-3/src/expr2.cpp"
case 145 :__1es = (const char *)"address of";

# 133 "/home/claude/cfront-3/src/expr2.cpp"
break ;
case 111 :__1es = (const char *)"dereference of";

# 134 "/home/claude/cfront-3/src/expr2.cpp"
break ;
case 48 :__1es = (const char *)"increment of";

# 135 "/home/claude/cfront-3/src/expr2.cpp"
goto def ;
case 49 :__1es = (const char *)"decrement of";

# 136 "/home/claude/cfront-3/src/expr2.cpp"
goto def ;
default :__1es = (const char *)"assignment to";
def :
# 139 "/home/claude/cfront-3/src/expr2.cpp"
if ((ignore_const == 0 )&& tconst__4typeFv ( __0this -> __O1__4expr.tp ) ){ 
# 140 "/home/claude/cfront-3/src/expr2.cpp"
if (__1oper ){ 
# 141 "/home/claude/cfront-3/src/expr2.cpp"
const char *__4ms ;

# 141 "/home/claude/cfront-3/src/expr2.cpp"
__4ms = (const char *)(vec_const ?"array":(((char *)(fct_const ?"function":(((char *)"const type"))))));
# 141 "/home/claude/cfront-3/src/expr2.cpp"

# 142 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> base__4node == 85 ){ 
# 143 "/home/claude/cfront-3/src/expr2.cpp"
if (vec_const && ((((struct name *)(((struct name *)__0this ))))-> n_scope__4name == 136 ))break ;
{ 
# 144 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V50 ;

# 144 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V51 ;

# 144 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V52 ;

# 144 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s%s%n", (const struct ea *)( ((& __0__V50 )-> __O1__2ea.p =
# 144 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1es )), (& __0__V50 )) , (const struct ea *)( ((& __0__V51 )-> __O1__2ea.p = ((const void
# 144 "/home/claude/cfront-3/src/expr2.cpp"
*)__4ms )), (& __0__V51 )) , (const struct ea *)( ((& __0__V52 )-> __O1__2ea.p = ((const void *)__0this )), (&
# 144 "/home/claude/cfront-3/src/expr2.cpp"
__0__V52 )) , (const struct ea *)ea0 ) ;
} }
else 
# 147 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 147 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V53 ;

# 147 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V54 ;

# 147 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s%s", (const struct ea *)( ((& __0__V53 )-> __O1__2ea.p =
# 147 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1es )), (& __0__V53 )) , (const struct ea *)( ((& __0__V54 )-> __O1__2ea.p = ((const void
# 147 "/home/claude/cfront-3/src/expr2.cpp"
*)__4ms )), (& __0__V54 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
return 0 ;
}
}

# 153 "/home/claude/cfront-3/src/expr2.cpp"
for(;;) { 
# 155 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1ee -> base__4node ){ 
# 158 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 159 "/home/claude/cfront-3/src/expr2.cpp"
defa :
# 160 "/home/claude/cfront-3/src/expr2.cpp"
if (__1deref == 0 ){ 
# 160 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X78 ;

# 161 "/home/claude/cfront-3/src/expr2.cpp"
if (__1oper ){ 
# 161 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V55 ;

# 161 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V56 ;

# 161 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s%k (not an lvalue)", (const struct ea *)( ((& __0__V55 )-> __O1__2ea.p =
# 161 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1es )), (& __0__V55 )) , (const struct ea *)( (__2__X78 = __1ee -> base__4node ), ( ((
# 161 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V56 )-> __O1__2ea.i = __2__X78 ), 0 ) ), (& __0__V56 )) ) , (const struct ea *)ea0 , (const
# 161 "/home/claude/cfront-3/src/expr2.cpp"
struct ea *)ea0 ) ;
} return 0 ;
}
return 1 ;
case 86 :
# 166 "/home/claude/cfront-3/src/expr2.cpp"
case 84 :
# 167 "/home/claude/cfront-3/src/expr2.cpp"
case 82 :
# 168 "/home/claude/cfront-3/src/expr2.cpp"
case 83 :
# 169 "/home/claude/cfront-3/src/expr2.cpp"
if (__1oper ){ 
# 169 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V57 ;

# 169 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s numeric constant", (const struct ea *)( ((& __0__V57 )-> __O1__2ea.p =
# 169 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1es )), (& __0__V57 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 169 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
} return 0 ;
case 81 :
# 172 "/home/claude/cfront-3/src/expr2.cpp"
if (__1oper ){ 
# 172 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V58 ;

# 172 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%s string constant", (const struct ea *)( ((&
# 172 "/home/claude/cfront-3/src/expr2.cpp"
__0__V58 )-> __O1__2ea.p = ((const void *)__1es )), (& __0__V58 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 172 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 ) ;
} return 1 ;
case 113 :
# 175 "/home/claude/cfront-3/src/expr2.cpp"
case 191 :
# 176 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1oper ){ 
# 177 "/home/claude/cfront-3/src/expr2.cpp"
case 0 :
# 178 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 179 "/home/claude/cfront-3/src/expr2.cpp"
case 145 :
# 180 "/home/claude/cfront-3/src/expr2.cpp"
case 111 :
# 181 "/home/claude/cfront-3/src/expr2.cpp"
goto defa ;
default :
# 183 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1ee -> __O1__4expr.tp -> base__4node == 125 )&& is_dataMemPtr__FP4expr ( __1ee ) )
# 185 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 186 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __5te ;
__5te = __1ee -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O2__4expr.e1 ;
if (__5te -> base__4node == 145 )
# 189 "/home/claude/cfront-3/src/expr2.cpp"
__5te = __5te -> __O3__4expr.e2 ;
if (__5te -> base__4node == 85 ){ 
# 191 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __6pt ;

# 191 "/home/claude/cfront-3/src/expr2.cpp"
__6pt = __5te -> __O1__4expr.tp ;
if (__6pt -> base__4node == 125 )
# 193 "/home/claude/cfront-3/src/expr2.cpp"
__6pt = (((struct ptr *)(((struct ptr *)__6pt ))))-> typ__5pvtyp ;
if (tconst__4typeFv ( __6pt ) )
# 195 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 195 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V59 ;

# 195 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V60 ;

# 195 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%sCMP of const%n", (const struct ea *)( ((& __0__V59 )-> __O1__2ea.p =
# 195 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1es )), (& __0__V59 )) , (const struct ea *)( ((& __0__V60 )-> __O1__2ea.p = ((const void
# 195 "/home/claude/cfront-3/src/expr2.cpp"
*)__5te )), (& __0__V60 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} return 0 ;
}
}
goto defa ;
}

# 202 "/home/claude/cfront-3/src/expr2.cpp"
case 111 :
# 203 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 204 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __4ee1 ;

# 204 "/home/claude/cfront-3/src/expr2.cpp"
__4ee1 = __1ee -> __O2__4expr.e1 ;

# 206 "/home/claude/cfront-3/src/expr2.cpp"
switch (__4ee1 -> base__4node ){ 
# 207 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 208 "/home/claude/cfront-3/src/expr2.cpp"
return 1 ;
case 147 :
# 210 "/home/claude/cfront-3/src/expr2.cpp"
case 71 :
# 211 "/home/claude/cfront-3/src/expr2.cpp"
if ((__4ee1 -> __O3__4expr.e2 -> base__4node == 145 )|| (__4ee1 -> __O3__4expr.e2 -> base__4node == 112 ))
# 213 "/home/claude/cfront-3/src/expr2.cpp"
return 1 ;
goto defaa ;
case 68 :
# 216 "/home/claude/cfront-3/src/expr2.cpp"
if (((__4ee1 -> __O2__4expr.e1 -> base__4node == 145 )|| (__4ee1 -> __O2__4expr.e1 -> base__4node == 112 ))&& ((__4ee1 -> __O3__4expr.e2 -> base__4node == 145 )||
# 216 "/home/claude/cfront-3/src/expr2.cpp"
(__4ee1 -> __O3__4expr.e2 -> base__4node == 112 )))
# 220 "/home/claude/cfront-3/src/expr2.cpp"
return 1 ;

# 222 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 223 "/home/claude/cfront-3/src/expr2.cpp"
defaa :
# 224 "/home/claude/cfront-3/src/expr2.cpp"
__1ee = __4ee1 ;
__1deref = 1 ;
}
break ;
}

# 230 "/home/claude/cfront-3/src/expr2.cpp"
case 68 :
# 231 "/home/claude/cfront-3/src/expr2.cpp"
{ int __4x1 ;
int __4x2 ;

# 231 "/home/claude/cfront-3/src/expr2.cpp"
__4x1 = lval__4exprFUc ( __1ee -> __O2__4expr.e1 , (unsigned char )(__1deref ?0 :(((int )__1oper )))) ;
__4x2 = lval__4exprFUc ( __1ee -> __O3__4expr.e2 , (unsigned char )(__1deref ?0 :(((int )__1oper )))) ;
if (check__4typeFP4typeUcT2 ( __1ee -> __O2__4expr.e1 -> __O1__4expr.tp , __1ee -> __O3__4expr.e2 -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 )
# 233 "/home/claude/cfront-3/src/expr2.cpp"
)return 0 ;
if (__1deref )return 1 ;
return (__4x1 && __4x2 );
}

# 238 "/home/claude/cfront-3/src/expr2.cpp"
case 48 :
# 239 "/home/claude/cfront-3/src/expr2.cpp"
case 49 :
# 240 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> __O2__4expr.e1 )goto defa ;
case 70 :
# 242 "/home/claude/cfront-3/src/expr2.cpp"
case 126 :
# 243 "/home/claude/cfront-3/src/expr2.cpp"
case 127 :
# 244 "/home/claude/cfront-3/src/expr2.cpp"
case 128 :
# 245 "/home/claude/cfront-3/src/expr2.cpp"
case 129 :
# 246 "/home/claude/cfront-3/src/expr2.cpp"
case 130 :
# 247 "/home/claude/cfront-3/src/expr2.cpp"
case 131 :
# 248 "/home/claude/cfront-3/src/expr2.cpp"
case 132 :
# 249 "/home/claude/cfront-3/src/expr2.cpp"
case 133 :
# 250 "/home/claude/cfront-3/src/expr2.cpp"
case 134 :
# 251 "/home/claude/cfront-3/src/expr2.cpp"
case 135 :
# 252 "/home/claude/cfront-3/src/expr2.cpp"
return 1 ;

# 254 "/home/claude/cfront-3/src/expr2.cpp"
case 71 :
# 255 "/home/claude/cfront-3/src/expr2.cpp"
case 147 :
# 256 "/home/claude/cfront-3/src/expr2.cpp"
if (lval__4exprFUc ( __1ee -> __O3__4expr.e2 , (unsigned char )(__1deref ?0 :(((int )__1oper )))) == 0 )return __1deref ;
return 1 ;

# 259 "/home/claude/cfront-3/src/expr2.cpp"
case 173 :
# 260 "/home/claude/cfront-3/src/expr2.cpp"
__1ee = __1ee -> __O3__4expr.e2 ;
break ;

# 263 "/home/claude/cfront-3/src/expr2.cpp"
case 177 :
# 264 "/home/claude/cfront-3/src/expr2.cpp"
__1ee = __1ee -> __O4__4expr.mem ;
break ;

# 267 "/home/claude/cfront-3/src/expr2.cpp"
case 45 :
# 268 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 270 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __4e ;
int __4e_const ;

# 270 "/home/claude/cfront-3/src/expr2.cpp"
__4e = 0 ;
__4e_const = 0 ;

# 273 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1ee -> __O2__4expr.e1 -> base__4node ){ 
# 274 "/home/claude/cfront-3/src/expr2.cpp"
case 85 :
# 275 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1oper ){ 
# 276 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 277 "/home/claude/cfront-3/src/expr2.cpp"
case 145 :take_addr__4nameFv ( ((struct name *)(((struct name *)__1ee -> __O2__4expr.e1 ))))
# 277 "/home/claude/cfront-3/src/expr2.cpp"
;
case 0 :break ;
case 70 :(((struct name *)(((struct name *)__1ee -> __O2__4expr.e1 ))))-> n_used__4name -- ;
default :assign__4nameFv ( ((struct name *)(((struct name *)__1ee -> __O2__4expr.e1 )))) ;
}
break ;
case 45 :
# 284 "/home/claude/cfront-3/src/expr2.cpp"
__4e = __1ee -> __O2__4expr.e1 ;
do __4e = __4e -> __O2__4expr.e1 ;
while (__4e -> base__4node == 45 );

# 286 "/home/claude/cfront-3/src/expr2.cpp"
if (__4e -> base__4node == 85 ){ 
# 287 "/home/claude/cfront-3/src/expr2.cpp"
__4e_const = tconst__4typeFv ( __4e -> __O1__4expr.tp ) ;
switch (__1oper ){ 
# 289 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 290 "/home/claude/cfront-3/src/expr2.cpp"
case 145 :take_addr__4nameFv ( ((struct name *)(((struct name *)__4e )))) ;
case 0 :break ;
case 70 :(((struct name *)(((struct name *)__4e ))))-> n_used__4name -- ;
default :assign__4nameFv ( ((struct name *)(((struct name *)__4e )))) ;
}
}
}

# 298 "/home/claude/cfront-3/src/expr2.cpp"
__1n = (((struct name *)(((struct name *)__1ee -> __O4__4expr.mem ))));
while (__1n -> base__4node == 177 )__1n = (((struct name *)(((struct name *)(((struct ref *)(((struct ref *)__1n ))))-> __O4__4expr.mem ))));

# 301 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1deref == 0 )&& (tconst__4typeFv ( __1ee -> __O2__4expr.e1 -> __O1__4expr.tp ) || __4e_const ))
# 302 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 304 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1oper ){ 
# 305 "/home/claude/cfront-3/src/expr2.cpp"
case 0 :
# 306 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 307 "/home/claude/cfront-3/src/expr2.cpp"
case
# 307 "/home/claude/cfront-3/src/expr2.cpp"
145 :
# 308 "/home/claude/cfront-3/src/expr2.cpp"
case 111 :
# 309 "/home/claude/cfront-3/src/expr2.cpp"
break ;
default :
# 311 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 311 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V61 ;

# 311 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V62 ;

# 311 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V63 ;

# 311 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%sM%n of%t", (const struct ea *)( ((& __0__V61 )-> __O1__2ea.p =
# 311 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1es )), (& __0__V61 )) , (const struct ea *)( ((& __0__V62 )-> __O1__2ea.p = ((const void
# 311 "/home/claude/cfront-3/src/expr2.cpp"
*)__1n )), (& __0__V62 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V63 , (const void *)(__4e_const ?__4e -> __O1__4expr.tp :__1ee -> __O2__4expr.e1 ->
# 311 "/home/claude/cfront-3/src/expr2.cpp"
__O1__4expr.tp )) , (const struct ea *)ea0 ) ;
} }
return 0 ;
}
}
goto xx ;

# 318 "/home/claude/cfront-3/src/expr2.cpp"
case 44 :
# 319 "/home/claude/cfront-3/src/expr2.cpp"
__1n = (((struct name *)(((struct name *)__1ee -> __O4__4expr.mem ))));
while (__1n -> base__4node == 177 )__1n = (((struct name *)(((struct name *)(((struct ref *)(((struct ref *)__1n ))))-> __O4__4expr.mem ))));

# 322 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1deref == 0 )&& __1ee -> __O2__4expr.e1 ){ 
# 323 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __4p ;

# 323 "/home/claude/cfront-3/src/expr2.cpp"
__4p = skiptypedefs__4typeFv ( __1ee -> __O2__4expr.e1 -> __O1__4expr.tp ) ;

# 325 "/home/claude/cfront-3/src/expr2.cpp"
switch (__4p -> base__4node ){ 
# 326 "/home/claude/cfront-3/src/expr2.cpp"
case 125 :
# 327 "/home/claude/cfront-3/src/expr2.cpp"
case 110 :break ;
case 141 :return 0 ;
default :{ 
# 329 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V64 ;

# 329 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V65 ;

# 329 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"expr::lval%t ->%n", (const struct ea *)( ((&
# 329 "/home/claude/cfront-3/src/expr2.cpp"
__0__V64 )-> __O1__2ea.p = ((const void *)__4p )), (& __0__V64 )) , (const struct ea *)( ((& __0__V65 )-> __O1__2ea.p =
# 329 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n )), (& __0__V65 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
if ((ignore_const == 0 )&& tconst__4typeFv ( (((struct ptr *)(((struct ptr *)__4p ))))-> typ__5pvtyp ) ){ 
# 332 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1oper ){ 
# 333 "/home/claude/cfront-3/src/expr2.cpp"
case 0 :
# 334 "/home/claude/cfront-3/src/expr2.cpp"
case
# 334 "/home/claude/cfront-3/src/expr2.cpp"
112 :
# 335 "/home/claude/cfront-3/src/expr2.cpp"
case 145 :
# 336 "/home/claude/cfront-3/src/expr2.cpp"
case 111 :
# 337 "/home/claude/cfront-3/src/expr2.cpp"
break ;
default :
# 339 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 339 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V66 ;

# 339 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V67 ;

# 339 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V68 ;

# 339 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%sM%n of%t", (const struct ea *)( ((& __0__V66 )-> __O1__2ea.p =
# 339 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1es )), (& __0__V66 )) , (const struct ea *)( ((& __0__V67 )-> __O1__2ea.p = ((const void
# 339 "/home/claude/cfront-3/src/expr2.cpp"
*)__1n )), (& __0__V67 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V68 , (const void *)(((struct ptr *)(((struct ptr *)__4p ))))->
# 339 "/home/claude/cfront-3/src/expr2.cpp"
typ__5pvtyp ) , (const struct ea *)ea0 ) ;
} }
return 0 ;
}
}
goto xx ;

# 346 "/home/claude/cfront-3/src/expr2.cpp"
case 85 :
# 347 "/home/claude/cfront-3/src/expr2.cpp"
__1n = (((struct name *)(((struct name *)__1ee ))));
xx :
# 350 "/home/claude/cfront-3/src/expr2.cpp"
if (__1deref )return 1 ;
if (__1oper == 0 )return (__1n -> n_stclass__4name != 13 );

# 353 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1n -> __O1__4expr.tp -> base__4node == 114 )&& ((((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp ))))-> b_bits__8basetype == 0 )){ 
# 354 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 354 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V69 ;
# 354 "/home/claude/cfront-3/src/expr2.cpp"

# 354 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V70 ;

# 354 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s 0-length field%n", (const struct ea *)( ((& __0__V69 )-> __O1__2ea.p =
# 354 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1es )), (& __0__V69 )) , (const struct ea *)( ((& __0__V70 )-> __O1__2ea.p = ((const void
# 354 "/home/claude/cfront-3/src/expr2.cpp"
*)__1n )), (& __0__V70 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return 0 ;
} }

# 358 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1oper ){ 
# 359 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 360 "/home/claude/cfront-3/src/expr2.cpp"
case 145 :
# 361 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 362 "/home/claude/cfront-3/src/expr2.cpp"
if (__1n -> n_sto__4name == 27 ){ 
# 363 "/home/claude/cfront-3/src/expr2.cpp"
if (warning_opt ){ 
# 363 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V71 ;
# 363 "/home/claude/cfront-3/src/expr2.cpp"

# 363 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"& register%n", (const struct ea *)( ((&
# 363 "/home/claude/cfront-3/src/expr2.cpp"
__0__V71 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V71 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 363 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 ) ;
} 
# 365 "/home/claude/cfront-3/src/expr2.cpp"
__1n -> n_sto__4name = 0 ;
__1n -> n_stclass__4name = 2 ;
}

# 369 "/home/claude/cfront-3/src/expr2.cpp"
if (__1n -> __O1__4expr.tp == 0 ){ 
# 370 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 370 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V72 ;

# 370 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"& label%n", (const struct ea *)( ((& __0__V72 )-> __O1__2ea.p =
# 370 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n )), (& __0__V72 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 370 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
return 0 ;
} }

# 374 "/home/claude/cfront-3/src/expr2.cpp"
if (__1n -> n_stclass__4name == 13 ){ 
# 375 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 375 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V73 ;

# 375 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"& enumerator%n", (const struct ea *)( ((& __0__V73 )-> __O1__2ea.p =
# 375 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n )), (& __0__V73 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 375 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
return 0 ;
} }

# 379 "/home/claude/cfront-3/src/expr2.cpp"
if (__1n -> __O1__4expr.tp -> base__4node == 114 ){ 
# 380 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 380 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V74 ;

# 380 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"& field%n", (const struct ea *)( ((& __0__V74 )-> __O1__2ea.p =
# 380 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n )), (& __0__V74 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 380 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
return 0 ;
} }

# 384 "/home/claude/cfront-3/src/expr2.cpp"
__1n -> n_used__4name -- ;
if (__1n -> __O2__4name.n_qualifier ){ 
# 386 "/home/claude/cfront-3/src/expr2.cpp"
Pname __6tn ;

# 386 "/home/claude/cfront-3/src/expr2.cpp"
__6tn = look__5tableFPCcUc ( (((struct classdef *)(((struct classdef *)__1n -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))))-> memtbl__8classdef , __1n -> __O2__4expr.string , (unsigned char )0 )
# 386 "/home/claude/cfront-3/src/expr2.cpp"
;
__1n = (__6tn ?__6tn :__1n );
}
take_addr__4nameFv ( __1n ) ;

# 392 "/home/claude/cfront-3/src/expr2.cpp"
{ int __5statmem ;

# 392 "/home/claude/cfront-3/src/expr2.cpp"
__5statmem = (((__1n -> n_scope__4name == 0 )|| (__1n -> n_scope__4name == 25 ))|| (__1n -> n_scope__4name == 108 ));
if (__1n -> n_evaluated__4name && (__1n -> n_scope__4name != 136 )){ 
# 394 "/home/claude/cfront-3/src/expr2.cpp"
if ((__5statmem == 0 )&& (__1n -> n_dcl_printed__4name == 0 )){ 
# 394 "/home/claude/cfront-3/src/expr2.cpp"
struct ival *__0__X79 ;
# 394 "/home/claude/cfront-3/src/expr2.cpp"

# 394 "/home/claude/cfront-3/src/expr2.cpp"
long long __2__X80 ;

# 395 "/home/claude/cfront-3/src/expr2.cpp"
__1n -> __O3__4expr.n_initializer = (struct expr *)( (__0__X79 = 0 ), ( (__2__X80 = __1n -> n_val__4name ), ( ((__0__X79 || (__0__X79 = (struct
# 395 "/home/claude/cfront-3/src/expr2.cpp"
ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival))) ))?( (__0__X79 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X79 ), (unsigned char )150 ,
# 395 "/home/claude/cfront-3/src/expr2.cpp"
(struct expr *)0 , (struct expr *)0 ) ), (__0__X79 -> __O2__4expr.i1 = __2__X80 )) :0 ), __0__X79 ) ) ) ;
dcl_print__4nameFUc ( __1n , (unsigned char )0 ) ;
}
}
else if ((__1n -> __O1__4expr.tp -> base__4node == 108 )&& (__1n -> n_dcl_printed__4name == 0 )){ 
# 400 "/home/claude/cfront-3/src/expr2.cpp"
Pfct __6f ;

# 400 "/home/claude/cfront-3/src/expr2.cpp"
__6f = (((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))));
if (__6f -> fct_base__3fct == 4)
# 402 "/home/claude/cfront-3/src/expr2.cpp"
current_fct_instantiation = __6f ;
if ((! __6f -> fct_base__3fct )|| (__6f -> fct_base__3fct == 4))
# 404 "/home/claude/cfront-3/src/expr2.cpp"
dcl_print__4nameFUc ( __1n , (unsigned char )0 ) ;
if (__6f -> fct_base__3fct == 4)
# 406 "/home/claude/cfront-3/src/expr2.cpp"
current_fct_instantiation = 0 ;
}
break ;

# 408 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 411 "/home/claude/cfront-3/src/expr2.cpp"
case 70 :
# 413 "/home/claude/cfront-3/src/expr2.cpp"
__1n -> n_used__4name -- ;
assign__4nameFv ( __1n ) ;
break ;
case 48 :
# 417 "/home/claude/cfront-3/src/expr2.cpp"
case 49 :
# 418 "/home/claude/cfront-3/src/expr2.cpp"
if (skiptypedefs__4typeFv ( __1n -> __O1__4expr.tp ) -> base__4node == 121 ){ 
# 419 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 419 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V75 ;

# 419 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s enum", (const struct ea *)( ((& __0__V75 )-> __O1__2ea.p =
# 419 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1es )), (& __0__V75 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 419 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
return 0 ;
} }

# 423 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 424 "/home/claude/cfront-3/src/expr2.cpp"
if (cc -> tot__11dcl_context && (__1n == cc -> c_this__11dcl_context )){ 
# 425 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 425 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V76 ;

# 425 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V77 ;

# 425 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n%k", (const struct ea *)( ((& __0__V76 )-> __O1__2ea.p =
# 425 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n )), (& __0__V76 )) , (const struct ea *)( (( ((& __0__V77 )-> __O1__2ea.i = ((unsigned
# 425 "/home/claude/cfront-3/src/expr2.cpp"
long )__1oper )), 0 ) ), (& __0__V77 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 425 "/home/claude/cfront-3/src/expr2.cpp"

# 426 "/home/claude/cfront-3/src/expr2.cpp"
return 0 ;
} }
assign__4nameFv ( __1n ) ;
}
return 1 ;
}
}
}

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 435 "/home/claude/cfront-3/src/expr2.cpp"
int char_to_int__FPCc (const char *__1s )
# 444 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 445 "/home/claude/cfront-3/src/expr2.cpp"
int __1i ;
char __1c ;

# 446 "/home/claude/cfront-3/src/expr2.cpp"
char __1d ;

# 446 "/home/claude/cfront-3/src/expr2.cpp"
char __1e ;

# 445 "/home/claude/cfront-3/src/expr2.cpp"
__1i = 0 ;

# 448 "/home/claude/cfront-3/src/expr2.cpp"
switch ((*__1s )){ 
# 449 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 450 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCc ( (int )'i' , (const char *)"char constant store corrupted") ;
# 450 "/home/claude/cfront-3/src/expr2.cpp"

# 451 "/home/claude/cfront-3/src/expr2.cpp"
case '`' :
# 452 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCc ( (const char *)"bcd constant") ;
return 0 ;
case '\'' :
# 455 "/home/claude/cfront-3/src/expr2.cpp"
break ;
}

# 458 "/home/claude/cfront-3/src/expr2.cpp"
for(;;) 
# 459 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1c = ((*(++ __1s )))){ 
# 460 "/home/claude/cfront-3/src/expr2.cpp"
case '\'' :
# 461 "/home/claude/cfront-3/src/expr2.cpp"
return __1i ;
case '\\' :
# 463 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1c = ((*(++ __1s )))){ 
# 464 "/home/claude/cfront-3/src/expr2.cpp"
case '0' :case '1' :case '2' :case '3' :case '4' :
# 465 "/home/claude/cfront-3/src/expr2.cpp"
case '5' :case '6' :case '7' :
# 466 "/home/claude/cfront-3/src/expr2.cpp"
__1c -=
# 466 "/home/claude/cfront-3/src/expr2.cpp"
'0' ;
switch (__1d = ((*(++ __1s )))){ 
# 469 "/home/claude/cfront-3/src/expr2.cpp"
case '0' :case '1' :case '2' :case '3' :case '4' :
# 470 "/home/claude/cfront-3/src/expr2.cpp"
case '5' :case '6' :case '7' :
# 471 "/home/claude/cfront-3/src/expr2.cpp"
__1d -= '0' ;
# 471 "/home/claude/cfront-3/src/expr2.cpp"

# 472 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1e = ((*(++ __1s )))){ 
# 474 "/home/claude/cfront-3/src/expr2.cpp"
case '0' :case '1' :case '2' :case '3' :case '4' :
# 475 "/home/claude/cfront-3/src/expr2.cpp"
case '5' :case '6' :case '7' :
# 476 "/home/claude/cfront-3/src/expr2.cpp"
__1c = ((((__1c *
# 476 "/home/claude/cfront-3/src/expr2.cpp"
64 )+ (__1d * 8 ))+ __1e )- '0' );
break ;
default :
# 479 "/home/claude/cfront-3/src/expr2.cpp"
__1c = ((__1c * 8 )+ __1d );
__1s -- ;
}
break ;
default :
# 484 "/home/claude/cfront-3/src/expr2.cpp"
__1s -- ;
}
break ;
case 'a' :
# 488 "/home/claude/cfront-3/src/expr2.cpp"
__1c = '\a' ;
break ;
case 'b' :
# 491 "/home/claude/cfront-3/src/expr2.cpp"
__1c = '\b' ;
break ;
case 'f' :
# 494 "/home/claude/cfront-3/src/expr2.cpp"
__1c = '\f' ;
break ;
case 'n' :
# 497 "/home/claude/cfront-3/src/expr2.cpp"
__1c = '\n' ;
break ;
case 'r' :
# 500 "/home/claude/cfront-3/src/expr2.cpp"
__1c = '\r' ;
break ;
case 't' :
# 503 "/home/claude/cfront-3/src/expr2.cpp"
__1c = '\t' ;
break ;
case 'v' :
# 506 "/home/claude/cfront-3/src/expr2.cpp"
__1c = '\v' ;
break ;
case '\\' :
# 509 "/home/claude/cfront-3/src/expr2.cpp"
__1c = '\\' ;
break ;
case '\'' :
# 512 "/home/claude/cfront-3/src/expr2.cpp"
__1c = '\'' ;
break ;
}

# 516 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 517 "/home/claude/cfront-3/src/expr2.cpp"
if (__1i )__1i <<= BI_IN_BYTE ;
__1i += __1c ;
}
}

# 522 "/home/claude/cfront-3/src/expr2.cpp"

# 523 "/home/claude/cfront-3/src/expr2.cpp"

# 525 "/home/claude/cfront-3/src/expr2.cpp"
long long str_to_llong__FPCc (const char *__1p );

# 525 "/home/claude/cfront-3/src/expr2.cpp"
long long str_to_llong__FPCc (const char *__1p )
# 526 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 527 "/home/claude/cfront-3/src/expr2.cpp"
int __1c ;

# 527 "/home/claude/cfront-3/src/expr2.cpp"
int __1j ;
int __1dotflag ;
int __1dotcount ;
long long __1exp ;
unsigned long long __1i ;
const char *__1pp ;

# 528 "/home/claude/cfront-3/src/expr2.cpp"
__1dotflag = 0 ;
__1dotcount = 0 ;
__1exp = 0 ;
__1i = 0 ;
__1pp = __1p ;

# 536 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1c = ((*(__1p ++ ))))== '0' ){ 
# 537 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1c = ((*(__1p ++ )))){ 
# 538 "/home/claude/cfront-3/src/expr2.cpp"
case 0 :
# 539 "/home/claude/cfront-3/src/expr2.cpp"
return (long long )0 ;

# 541 "/home/claude/cfront-3/src/expr2.cpp"
case 'l' :
# 542 "/home/claude/cfront-3/src/expr2.cpp"
case 'L' :
# 543 "/home/claude/cfront-3/src/expr2.cpp"
return (long long )0 ;

# 545 "/home/claude/cfront-3/src/expr2.cpp"
case 'x' :
# 546 "/home/claude/cfront-3/src/expr2.cpp"
case 'X' :
# 547 "/home/claude/cfront-3/src/expr2.cpp"
while (__1c = ((*(__1p ++ )))){ 
# 548 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1c ){ 
# 549 "/home/claude/cfront-3/src/expr2.cpp"
case 'l' :
# 550 "/home/claude/cfront-3/src/expr2.cpp"
case 'L' :
# 551 "/home/claude/cfront-3/src/expr2.cpp"
case 'U' :
# 552 "/home/claude/cfront-3/src/expr2.cpp"
case 'u' :
# 553 "/home/claude/cfront-3/src/expr2.cpp"
return (long long
# 553 "/home/claude/cfront-3/src/expr2.cpp"
)__1i ;
case 'A' :
# 555 "/home/claude/cfront-3/src/expr2.cpp"
case 'B' :
# 556 "/home/claude/cfront-3/src/expr2.cpp"
case 'C' :
# 557 "/home/claude/cfront-3/src/expr2.cpp"
case 'D' :
# 558 "/home/claude/cfront-3/src/expr2.cpp"
case 'E' :
# 559 "/home/claude/cfront-3/src/expr2.cpp"
case 'F' :
# 560 "/home/claude/cfront-3/src/expr2.cpp"
__1i = (((__1i * 16 )+ __1c )- 55);
break ;
case 'a' :
# 563 "/home/claude/cfront-3/src/expr2.cpp"
case 'b' :
# 564 "/home/claude/cfront-3/src/expr2.cpp"
case 'c' :
# 565 "/home/claude/cfront-3/src/expr2.cpp"
case 'd' :
# 566 "/home/claude/cfront-3/src/expr2.cpp"
case 'e' :
# 567 "/home/claude/cfront-3/src/expr2.cpp"
case 'f' :
# 568 "/home/claude/cfront-3/src/expr2.cpp"
__1i = (((__1i * 16 )+ __1c )- 87);
break ;
default :
# 571 "/home/claude/cfront-3/src/expr2.cpp"
__1i = (((__1i * 16 )+ __1c )- '0' );
}
}
return (long long )__1i ;

# 576 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 577 "/home/claude/cfront-3/src/expr2.cpp"
do 
# 578 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1c ){ 
# 579 "/home/claude/cfront-3/src/expr2.cpp"
case 'l' :
# 580 "/home/claude/cfront-3/src/expr2.cpp"
case 'L' :
# 581 "/home/claude/cfront-3/src/expr2.cpp"
case 'U' :
# 582 "/home/claude/cfront-3/src/expr2.cpp"
case 'u' :
# 583 "/home/claude/cfront-3/src/expr2.cpp"
return (long long )__1i ;
default :
# 585 "/home/claude/cfront-3/src/expr2.cpp"
__1i = (((__1i * 8 )+ __1c )- '0' );
}
while (__1c = ((*(__1p ++ ))));
return (long long )__1i ;
}
}

# 592 "/home/claude/cfront-3/src/expr2.cpp"
__1i = (__1c - '0' );
while (__1c = ((*(__1p ++ ))))
# 594 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1c ){ 
# 595 "/home/claude/cfront-3/src/expr2.cpp"
case 'l' :
# 596 "/home/claude/cfront-3/src/expr2.cpp"
case 'L' :
# 597 "/home/claude/cfront-3/src/expr2.cpp"
case 'U' :
# 598 "/home/claude/cfront-3/src/expr2.cpp"
case 'u' :
# 599 "/home/claude/cfront-3/src/expr2.cpp"
return (long long )__1i ;
case '.' :
# 601 "/home/claude/cfront-3/src/expr2.cpp"
__1dotflag = 1 ;
break ;
case 'e' :
# 604 "/home/claude/cfront-3/src/expr2.cpp"
case 'E' :
# 605 "/home/claude/cfront-3/src/expr2.cpp"
{ int __3negative ;

# 605 "/home/claude/cfront-3/src/expr2.cpp"
__3negative = 1 ;
if ((((*__1p ))== '+' )|| (((*__1p ))== '-' ))
# 607 "/home/claude/cfront-3/src/expr2.cpp"
__3negative = ((((*(__1p ++ )))== '-' )?-1:1 );
__1exp = (str_to_llong__FPCc ( __1p ) * __3negative );
__1exp = (__1exp - __1dotcount );
if (__1exp >= 1 ){ 
# 611 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long long __4ii ;

# 611 "/home/claude/cfront-3/src/expr2.cpp"
__4ii = __1i ;
for(__1j = 0 ;__1exp > __1j ;( (__1j ++ ), (__4ii = __1i )) ) { 
# 613 "/home/claude/cfront-3/src/expr2.cpp"
__1i = (__1i * 10 );
if (__1i < __4ii ){ 
# 615 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 615 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V81 ;

# 615 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"integral conversion of %s is out of range", (const struct ea *)( ((&
# 615 "/home/claude/cfront-3/src/expr2.cpp"
__0__V81 )-> __O1__2ea.p = ((const void *)__1pp )), (& __0__V81 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 615 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 ) ;
return (long long )__1i ;
} }
}
}
else 
# 621 "/home/claude/cfront-3/src/expr2.cpp"
for(__1j = 0 ;__1exp < __1j ;__1j -- ) __1i /= 10 ;
return (long long )__1i ;
}
default :
# 625 "/home/claude/cfront-3/src/expr2.cpp"
{ unsigned long long __3ii ;

# 625 "/home/claude/cfront-3/src/expr2.cpp"
__3ii = __1i ;
__1i = (((__1i * 10 )+ __1c )- '0' );
if (__1dotflag )__1dotcount ++ ;
if (__1i < __3ii )goto bad ;
}
}
return (long long )__1i ;
bad :
# 633 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 633 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V82 ;

# 633 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"integer constant %s larger than the largest long long", (const struct ea *)( ((& __0__V82 )-> __O1__2ea.p =
# 633 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1pp )), (& __0__V82 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 633 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
return (long long )__1i ;
} }

# 80 "/home/claude/incl-linux32/stdio.h"
extern int sprintf (char *, const char *,...);

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 638 "/home/claude/cfront-3/src/expr2.cpp"
static void ftp_normalize__FRPc (char **__1str )
# 643 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 644 "/home/claude/cfront-3/src/expr2.cpp"
char *__1p ;
char *__1pp ;
char __1c ;
int __1adjust ;
int __1dotflag ;
int __1dotcnt ;

# 644 "/home/claude/cfront-3/src/expr2.cpp"
__1p = ((*__1str ));
__1pp = ((*__1str ));

# 647 "/home/claude/cfront-3/src/expr2.cpp"
__1adjust = 0 ;
__1dotflag = 0 ;
__1dotcnt = 0 ;

# 651 "/home/claude/cfront-3/src/expr2.cpp"
while (__1c = ((*__1p ))){ 
# 652 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1c ){ 
# 653 "/home/claude/cfront-3/src/expr2.cpp"
case '+' :
# 654 "/home/claude/cfront-3/src/expr2.cpp"
case '-' :
# 655 "/home/claude/cfront-3/src/expr2.cpp"
__1pp ++ ;
break ;
case '0' :
# 658 "/home/claude/cfront-3/src/expr2.cpp"
if (__1dotflag )__1dotcnt ++ ;
break ;
case '.' :
# 661 "/home/claude/cfront-3/src/expr2.cpp"
__1dotflag = 1 ;
break ;
default :{ 
# 664 "/home/claude/cfront-3/src/expr2.cpp"
if (__1p == __1pp )return ;
((*(__1pp ++ )))= ((*(__1p ++ )));
if (__1dotflag == 0 ){ 
# 667 "/home/claude/cfront-3/src/expr2.cpp"
while ((*__1p ))((*(__1pp ++ )))= ((*(__1p ++ )));
((*__1pp ))= 0 ;
return ;
}
else 
# 670 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 671 "/home/claude/cfront-3/src/expr2.cpp"
((*(__1pp ++ )))= '.' ;
while ((((*__1p ))!= 'E' )&& (((*__1p ))!= 'e' ))
# 673 "/home/claude/cfront-3/src/expr2.cpp"
if (((*__1p ))== '.' )__1p ++ ;
else ((*(__1pp ++ )))= ((*(__1p ++ )));
}
__1adjust = 1 ;
}
case 'E' :
# 679 "/home/claude/cfront-3/src/expr2.cpp"
case 'e' :{ 
# 680 "/home/claude/cfront-3/src/expr2.cpp"
if (__1adjust == 0 ){ 
# 681 "/home/claude/cfront-3/src/expr2.cpp"
((*(__1pp ++ )))= '0' ;
((*__1pp ))= 0 ;
return ;
}

# 686 "/home/claude/cfront-3/src/expr2.cpp"
((*(__1pp ++ )))= ((*(__1p ++ )));
{ int __4sign ;

# 687 "/home/claude/cfront-3/src/expr2.cpp"
__4sign = 1 ;
if ((((*__1p ))== '+' )|| (((*__1p ))== '-' ))
# 689 "/home/claude/cfront-3/src/expr2.cpp"
__4sign = ((((*(__1p ++ )))== '-' )?-1:1 );
{ long long __4i ;
char __4tmp [40];

# 690 "/home/claude/cfront-3/src/expr2.cpp"
__4i = (((__4sign * str_to_llong__FPCc ( (const char *)__1p ) )- __1dotcnt )- 1 );

# 692 "/home/claude/cfront-3/src/expr2.cpp"
sprintf ( (char *)__4tmp , (const char *)"%-lld", __4i ) ;
if ((strlen ( (const char *)__1p ) + (__1p - __1pp ))< strlen ( (const char *)__4tmp ) ){ 
# 694 "/home/claude/cfront-3/src/expr2.cpp"
char
# 694 "/home/claude/cfront-3/src/expr2.cpp"
*__5newstr ;

# 694 "/home/claude/cfront-3/src/expr2.cpp"
__5newstr = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* ((strlen ( (const char *)__4tmp ) + (__1pp -
# 694 "/home/claude/cfront-3/src/expr2.cpp"
((*__1str ))))+ 1 ))) ));

# 696 "/home/claude/cfront-3/src/expr2.cpp"
strcpy ( __5newstr , (const char *)((*__1str ))) ;
{ int __5offset ;

# 697 "/home/claude/cfront-3/src/expr2.cpp"
__5offset = (__1pp - ((*__1str )));
((*__1str ))= __5newstr ;
__1pp = (((*__1str ))+ __5offset );

# 699 "/home/claude/cfront-3/src/expr2.cpp"
}
}
sprintf ( __1pp , (const char *)"%-lld", __4i ) ;
return ;

# 702 "/home/claude/cfront-3/src/expr2.cpp"
}

# 702 "/home/claude/cfront-3/src/expr2.cpp"
}
}
}
__1p ++ ;
}
}

# 710 "/home/claude/cfront-3/src/expr2.cpp"
bit is_unsigned__4typeFv (register struct type *__0this )
# 711 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 712 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __1t ;

# 712 "/home/claude/cfront-3/src/expr2.cpp"
__1t = skiptypedefs__4typeFv ( __0this ) ;
if (__1t -> base__4node == 125 )return (unsigned char )0 ;
return (((struct basetype *)(((struct basetype *)__1t ))))-> b_unsigned__8basetype ;
}

# 717 "/home/claude/cfront-3/src/expr2.cpp"
const char *Neval = 0 ;
bit binary_val = 0 ;

# 799 "/home/claude/cfront-3/src/cfront.h"
long long eval__4exprFv (struct expr *__0this );

# 720 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long long ueval__4exprFmT1 (register struct expr *__0this , long long __1x1 , long long __1x2 )
# 721 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 722 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long long __1i1 ;
unsigned long long __1i2 ;

# 722 "/home/claude/cfront-3/src/expr2.cpp"
__1i1 = (((unsigned long long )__1x1 ));
__1i2 = (((unsigned long long )__1x2 ));

# 725 "/home/claude/cfront-3/src/expr2.cpp"
switch (__0this -> base__4node ){ 
# 726 "/home/claude/cfront-3/src/expr2.cpp"
case 107 :return (- __1i2 );
case 172 :return __1i2 ;
case 46 :return (unsigned long long )(! __1i2 );
case 47 :return (~ __1i2 );
case 113 :
# 731 "/home/claude/cfront-3/src/expr2.cpp"
case 191 :
# 732 "/home/claude/cfront-3/src/expr2.cpp"
return __1i1 ;
case 54 :return (__1i1 + __1i2 );
case 55 :return (__1i1 - __1i2 );
case 50 :return (__1i1 * __1i2 );
case 56 :return (__1i1 << __1i2 );
case 57 :return (__1i1 >> __1i2 );
case 63 :return (unsigned long long )(__1i1 != __1i2 );
case 62 :return (unsigned long long )(__1i1 == __1i2 );
case 58 :return (unsigned long long )(__1i1 < __1i2 );
case 59 :return (unsigned long long )(__1i1 <= __1i2 );
case 60 :return (unsigned long long )(__1i1 > __1i2 );
case 61 :return (unsigned long long )(__1i1 >= __1i2 );
case 52 :return (__1i1 & __1i2 );
case 66 :return (unsigned long long )(__1i1 && __1i2 );
case 65 :return (__1i1 | __1i2 );
case 67 :return (unsigned long long )(__1i1 || __1i2 );
case 64 :return (__1i1 ^ __1i2 );
case 53 :if (__1i2 == 0 ){ 
# 750 "/home/claude/cfront-3/src/expr2.cpp"
if (Neval == 0 ){ 
# 751 "/home/claude/cfront-3/src/expr2.cpp"
Neval = (const char *)"mod zero";
# 751 "/home/claude/cfront-3/src/expr2.cpp"

# 752 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCc ( (const char *)"mod zero") ;
}
return (unsigned long long )1 ;
}
return (__1i1 % __1i2 );
case 68 :return (eval__4exprFv ( __0this -> __O4__4expr.cond ) ?__1i1 :__1i2 );
case 51 :if (__1i2 == 0 ){ 
# 759 "/home/claude/cfront-3/src/expr2.cpp"
if (Neval == 0 ){ 
# 760 "/home/claude/cfront-3/src/expr2.cpp"
Neval = (const char *)"divide by zero";
# 760 "/home/claude/cfront-3/src/expr2.cpp"

# 761 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCc ( (const char *)"divide by zero") ;
}
return (unsigned long long )1 ;
}
return (__1i1 / __1i2 );
case 71 :
# 767 "/home/claude/cfront-3/src/expr2.cpp"
case 147 :
# 768 "/home/claude/cfront-3/src/expr2.cpp"
return __1i2 ;
}

# 771 "/home/claude/cfront-3/src/expr2.cpp"
Neval = (const char *)"unsigned expression";
return (unsigned long long )0 ;
}

# 355 "/home/claude/cfront-3/src/cfront.h"
bit vec_type__4typeFv (struct type *__0this );

# 346 "/home/claude/cfront-3/src/cfront.h"
int tsizeof__4typeFi (struct type *__0this , int );

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 19 "/home/claude/incl-linux32/string.h"
extern char *strdup (const char *);

# 15 "/home/claude/incl-linux32/string.h"
extern char *strchr (const char *, int );

# 775 "/home/claude/cfront-3/src/expr2.cpp"
long long eval__4exprFv (register struct expr *__0this )
# 776 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 779 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __1tt ;

# 777 "/home/claude/cfront-3/src/expr2.cpp"
if (Neval )return (long long )1 ;

# 779 "/home/claude/cfront-3/src/expr2.cpp"
;

# 781 "/home/claude/cfront-3/src/expr2.cpp"
switch (__0this -> base__4node ){ 
# 782 "/home/claude/cfront-3/src/expr2.cpp"
case 86 :return (long long )0 ;
case 150 :return __0this -> __O2__4expr.i1 ;
case 82 :return str_to_llong__FPCc ( __0this -> __O2__4expr.string ) ;
case 84 :return (long long )char_to_int__FPCc ( __0this -> __O2__4expr.string ) ;
case 83 :Neval = (const char *)"float in constant expression";

# 786 "/home/claude/cfront-3/src/expr2.cpp"
return (long long )1 ;
case 81 :Neval = (const char *)"string in constant expression";

# 787 "/home/claude/cfront-3/src/expr2.cpp"
return (long long )1 ;
case 121 :return (((struct name *)(((struct name *)__0this ))))-> n_val__4name ;
case 30 :
# 790 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 791 "/home/claude/cfront-3/src/expr2.cpp"
extern int no_sizeof ;
if (no_sizeof )Neval = (const char *)"sizeof";
{ const char *__3cese ;

# 793 "/home/claude/cfront-3/src/expr2.cpp"
__3cese = (const char *)"cannot evaluate sizeof expression";
if (! __0this -> __O4__4expr.tp2 ){ 
# 795 "/home/claude/cfront-3/src/expr2.cpp"
Neval = __3cese ;
return (long long )1 ;
}
else 
# 797 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 798 "/home/claude/cfront-3/src/expr2.cpp"
__1tt = __0this -> __O4__4expr.tp2 ;
while (__1tt && vec_type__4typeFv ( __1tt ) ){ 
# 800 "/home/claude/cfront-3/src/expr2.cpp"
__1tt = skiptypedefs__4typeFv ( __1tt ) ;
if (__1tt -> base__4node == 141 ){ 
# 802 "/home/claude/cfront-3/src/expr2.cpp"
Neval = __3cese ;
return (long long )1 ;
}

# 808 "/home/claude/cfront-3/src/expr2.cpp"
__1tt = ((__1tt -> base__4node == 110 )?(((struct vec *)(((struct vec *)__1tt ))))-> typ__5pvtyp :(((struct ptr *)(((struct ptr *)__1tt ))))-> typ__5pvtyp );
}
}
return (long long )tsizeof__4typeFi ( __0this -> __O4__4expr.tp2 , 0 ) ;

# 811 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 814 "/home/claude/cfront-3/src/expr2.cpp"
case 85 :
# 815 "/home/claude/cfront-3/src/expr2.cpp"
{ Pname __3n ;

# 815 "/home/claude/cfront-3/src/expr2.cpp"
__3n = (((struct name *)(((struct name *)__0this ))));

# 818 "/home/claude/cfront-3/src/expr2.cpp"
if (__3n -> n_evaluated__4name && (__3n -> n_scope__4name != 136 ))return __3n -> n_val__4name ;
if (binary_val && (strcmp ( __0this -> __O2__4expr.string , (const char *)"_result") == 0 ))return
# 819 "/home/claude/cfront-3/src/expr2.cpp"
(long long )8888 ;
Neval = (const char *)"cannot evaluate constant";
return (long long )1 ;
}
case 168 :
# 824 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> __O2__4expr.e1 ){ 
# 825 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O4__4expr.il -> i_next__5iline = curr_icall ;
curr_icall = __0this -> __O4__4expr.il ;
{ long long __3i ;

# 827 "/home/claude/cfront-3/src/expr2.cpp"
__3i = eval__4exprFv ( __0this -> __O2__4expr.e1 ) ;
curr_icall = __0this -> __O4__4expr.il -> i_next__5iline ;
return __3i ;

# 829 "/home/claude/cfront-3/src/expr2.cpp"
}
}
Neval = (const char *)"void inlineF";
return (long long )1 ;
case 169 :
# 834 "/home/claude/cfront-3/src/expr2.cpp"
{ Pname __3n ;

# 836 "/home/claude/cfront-3/src/expr2.cpp"
Pin __3il ;

# 834 "/home/claude/cfront-3/src/expr2.cpp"
__3n = (((struct name *)(((struct name *)__0this ))));

# 837 "/home/claude/cfront-3/src/expr2.cpp"
for(__3il = curr_icall ;__3il ;__3il = __3il -> i_next__5iline ) 
# 838 "/home/claude/cfront-3/src/expr2.cpp"
if (__3il -> i_table__5iline == __3n -> __O4__4expr.n_table )goto aok ;
goto bok ;
aok :
# 841 "/home/claude/cfront-3/src/expr2.cpp"
if ((__3il -> i_args__5iline [__3n -> argno__4name ]). local__2ia ){ 
# 842 "/home/claude/cfront-3/src/expr2.cpp"
bok :
# 843 "/home/claude/cfront-3/src/expr2.cpp"
Neval = (const char *)"inlineF call too complicated for constant expression";
return (long long )1 ;
}
{ Pexpr __3aa ;

# 846 "/home/claude/cfront-3/src/expr2.cpp"
__3aa = (__3il -> i_args__5iline [__3n -> argno__4name ]). arg__2ia ;
return eval__4exprFv ( __3aa ) ;

# 847 "/home/claude/cfront-3/src/expr2.cpp"
}
}
case 113 :
# 850 "/home/claude/cfront-3/src/expr2.cpp"
case 191 :
# 851 "/home/claude/cfront-3/src/expr2.cpp"
{ if (((__0this -> __O4__4expr.tp2 -> base__4node != 15 )&& (__0this -> __O4__4expr.tp2 -> base__4node != 11 ))&& ((__0this -> __O2__4expr.e1 ->
# 851 "/home/claude/cfront-3/src/expr2.cpp"
base__4node == 83 )|| (((__0this -> __O2__4expr.e1 -> base__4node == 107 )|| (__0this -> __O2__4expr.e1 -> base__4node == 172 ))&& (__0this -> __O2__4expr.e1 -> __O3__4expr.e2 -> base__4node ==
# 851 "/home/claude/cfront-3/src/expr2.cpp"
83 ))))
# 852 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 853 "/home/claude/cfront-3/src/expr2.cpp"
const char **__4str ;
const char *__4p ;

# 853 "/home/claude/cfront-3/src/expr2.cpp"
__4str = (const char **)((__0this -> __O2__4expr.e1 -> base__4node == 83 )?(& __0this -> __O2__4expr.e1 -> __O2__4expr.string ):(& __0this -> __O2__4expr.e1 -> __O3__4expr.e2 -> __O2__4expr.string ));
# 853 "/home/claude/cfront-3/src/expr2.cpp"

# 854 "/home/claude/cfront-3/src/expr2.cpp"
__4p = ((*__4str ));
while (((((*__4p ))&& (((*__4p ))!= '.' ))&& (((*__4p ))!= 'E' ))&& (((*__4p ))!= 'e' ))__4p ++ ;
if ((*__4p )){ 
# 857 "/home/claude/cfront-3/src/expr2.cpp"
char *__5str_tmp ;

# 857 "/home/claude/cfront-3/src/expr2.cpp"
__5str_tmp = strdup ( (*__4str )) ;
if ((strchr ( __4p , (int )'E' ) == 0 )&& (strchr ( __4p , (int )'e' ) == 0 )){ 
# 859 "/home/claude/cfront-3/src/expr2.cpp"
char
# 859 "/home/claude/cfront-3/src/expr2.cpp"
*__6p2 ;

# 859 "/home/claude/cfront-3/src/expr2.cpp"
__6p2 = (__5str_tmp + (__4p - ((*__4str ))));
if (__6p2 == __5str_tmp )((*(__6p2 ++ )))= '0' ;
((*__6p2 ))= 0 ;
}
else 
# 862 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 863 "/home/claude/cfront-3/src/expr2.cpp"
ftp_normalize__FRPc ( (char **)(& __5str_tmp )) ;
}

# 866 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> __O2__4expr.e1 -> base__4node == 83 )__0this -> __O2__4expr.e1 -> __O2__4expr.string = (const char *)__5str_tmp ;
else __0this -> __O2__4expr.e1 -> __O3__4expr.e2 -> __O2__4expr.string = (const char *)__5str_tmp ;
}
if (__0this -> __O2__4expr.e1 -> base__4node == 83 )
# 870 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O2__4expr.e1 -> base__4node = 82 ;
else 
# 872 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O2__4expr.e1 -> __O3__4expr.e2 -> base__4node = 82 ;
}
{ long long __3i ;

# 874 "/home/claude/cfront-3/src/expr2.cpp"
__3i = eval__4exprFv ( __0this -> __O2__4expr.e1 ) ;
__1tt = skiptypedefs__4typeFv ( __0this -> __O4__4expr.tp2 ) ;

# 877 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1tt -> base__4node ){ 
# 878 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 879 "/home/claude/cfront-3/src/expr2.cpp"
Neval = (const char *)"cast to non-integral type in constant expression";
break ;
case 13 :
# 882 "/home/claude/cfront-3/src/expr2.cpp"
case 121 :
# 883 "/home/claude/cfront-3/src/expr2.cpp"
case 22 :
# 884 "/home/claude/cfront-3/src/expr2.cpp"
case 122 :
# 885 "/home/claude/cfront-3/src/expr2.cpp"
case 21 :
# 886 "/home/claude/cfront-3/src/expr2.cpp"
case 5 :
# 887 "/home/claude/cfront-3/src/expr2.cpp"
case 29 :
# 888 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 889 "/home/claude/cfront-3/src/expr2.cpp"
long long __5j ;

# 889 "/home/claude/cfront-3/src/expr2.cpp"
__5j = (((~ (((unsigned long long )0 )))<< (BI_IN_BYTE * (tsizeof__4typeFi ( __0this -> __O4__4expr.tp2 , 0 ) - 1 )))<< BI_IN_BYTE );
__3i &= (~ __5j );
if (is_unsigned__4typeFv ( __1tt ) == 0 )
# 892 "/home/claude/cfront-3/src/expr2.cpp"
if ((((long long )(__3i << (BI_IN_BYTE * ((sizeof (long long ))- tsizeof__4typeFi ( __0this -> __O4__4expr.tp2 ,
# 892 "/home/claude/cfront-3/src/expr2.cpp"
0 ) )))))< 0 )
# 893 "/home/claude/cfront-3/src/expr2.cpp"
__3i |= __5j ;
break ;
}
}
return __3i ;

# 897 "/home/claude/cfront-3/src/expr2.cpp"
}
}
case 107 :
# 900 "/home/claude/cfront-3/src/expr2.cpp"
case 172 :
# 901 "/home/claude/cfront-3/src/expr2.cpp"
case 46 :
# 902 "/home/claude/cfront-3/src/expr2.cpp"
case 47 :
# 903 "/home/claude/cfront-3/src/expr2.cpp"
case 54 :
# 904 "/home/claude/cfront-3/src/expr2.cpp"
case 55 :
# 905 "/home/claude/cfront-3/src/expr2.cpp"
case 50 :
# 906 "/home/claude/cfront-3/src/expr2.cpp"
case 56 :
# 907 "/home/claude/cfront-3/src/expr2.cpp"
case 57 :
# 908 "/home/claude/cfront-3/src/expr2.cpp"
case 63 :
# 909 "/home/claude/cfront-3/src/expr2.cpp"
case 58 :
# 910 "/home/claude/cfront-3/src/expr2.cpp"
case 59 :
# 911 "/home/claude/cfront-3/src/expr2.cpp"
case 60 :
# 912 "/home/claude/cfront-3/src/expr2.cpp"
case
# 912 "/home/claude/cfront-3/src/expr2.cpp"
61 :
# 913 "/home/claude/cfront-3/src/expr2.cpp"
case 52 :
# 914 "/home/claude/cfront-3/src/expr2.cpp"
case 65 :
# 915 "/home/claude/cfront-3/src/expr2.cpp"
case 64 :
# 916 "/home/claude/cfront-3/src/expr2.cpp"
case 51 :
# 917 "/home/claude/cfront-3/src/expr2.cpp"
case 53 :
# 918 "/home/claude/cfront-3/src/expr2.cpp"
case 68 :
# 919 "/home/claude/cfront-3/src/expr2.cpp"
case 62 :
# 920 "/home/claude/cfront-3/src/expr2.cpp"
case 66 :
# 921 "/home/claude/cfront-3/src/expr2.cpp"
break ;
case 67 :
# 923 "/home/claude/cfront-3/src/expr2.cpp"
if (binary_val ){ 
# 924 "/home/claude/cfront-3/src/expr2.cpp"
long long __3i1 ;

# 924 "/home/claude/cfront-3/src/expr2.cpp"
__3i1 = (__0this -> __O2__4expr.e1 ?eval__4exprFv ( __0this -> __O2__4expr.e1 ) :(((long long )0 )));
if (((Neval == 0 )&& __3i1 )&& (is_unsigned__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) == 0 ))return __3i1 ;
}
break ;
case 71 :
# 929 "/home/claude/cfront-3/src/expr2.cpp"
case 147 :
# 930 "/home/claude/cfront-3/src/expr2.cpp"
Neval = (const char *)"comma operator in constant expression";
return (long long )1 ;
case 145 :
# 933 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 934 "/home/claude/cfront-3/src/expr2.cpp"
if (binary_val ){ 
# 935 "/home/claude/cfront-3/src/expr2.cpp"
switch (__0this -> __O3__4expr.e2 -> base__4node ){ 
# 936 "/home/claude/cfront-3/src/expr2.cpp"
case 85 :
# 937 "/home/claude/cfront-3/src/expr2.cpp"
case 45 :
# 938 "/home/claude/cfront-3/src/expr2.cpp"
case 44 :return (long long )9999 ;
# 938 "/home/claude/cfront-3/src/expr2.cpp"

# 939 "/home/claude/cfront-3/src/expr2.cpp"
}
}
default :
# 942 "/home/claude/cfront-3/src/expr2.cpp"
Neval = (const char *)"bad operator in constant expression";
return (long long )1 ;
}

# 946 "/home/claude/cfront-3/src/expr2.cpp"
{ long long __1i1 ;
long long __1i2 ;

# 946 "/home/claude/cfront-3/src/expr2.cpp"
__1i1 = (__0this -> __O2__4expr.e1 ?eval__4exprFv ( __0this -> __O2__4expr.e1 ) :(((long long )0 )));
__1i2 = (__0this -> __O3__4expr.e2 ?eval__4exprFv ( __0this -> __O3__4expr.e2 ) :(((long long )0 )));

# 949 "/home/claude/cfront-3/src/expr2.cpp"
if ((binary_val && (__1i1 == 9999 ))&& (__1i2 == 9999 )){ 
# 950 "/home/claude/cfront-3/src/expr2.cpp"
Neval = (const char *)"";
# 950 "/home/claude/cfront-3/src/expr2.cpp"

# 951 "/home/claude/cfront-3/src/expr2.cpp"
return (long long )1 ;
}

# 954 "/home/claude/cfront-3/src/expr2.cpp"
if ((Neval == 0 )&& (((__0this -> __O2__4expr.e1 && __0this -> __O2__4expr.e1 -> __O1__4expr.tp )&& is_unsigned__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) )|| ((__0this ->
# 954 "/home/claude/cfront-3/src/expr2.cpp"
__O3__4expr.e2 && __0this -> __O3__4expr.e2 -> __O1__4expr.tp )&& is_unsigned__4typeFv ( __0this -> __O3__4expr.e2 -> __O1__4expr.tp ) )))
# 961 "/home/claude/cfront-3/src/expr2.cpp"
return (((long long )ueval__4exprFmT1 ( __0this , __1i1 , __1i2 )
# 961 "/home/claude/cfront-3/src/expr2.cpp"
));

# 963 "/home/claude/cfront-3/src/expr2.cpp"
switch (__0this -> base__4node ){ 
# 964 "/home/claude/cfront-3/src/expr2.cpp"
case 107 :return (- __1i2 );
case 172 :return __1i2 ;
case 46 :return (long long )(! __1i2 );
case 47 :return (~ __1i2 );
case 113 :
# 969 "/home/claude/cfront-3/src/expr2.cpp"
case 191 :
# 970 "/home/claude/cfront-3/src/expr2.cpp"
return __1i1 ;
case 54 :return (__1i1 + __1i2 );
case 55 :return (__1i1 - __1i2 );
case 50 :return (__1i1 * __1i2 );
case 56 :return (__1i1 << __1i2 );
case 57 :return (__1i1 >> __1i2 );
case 63 :return (long long )(__1i1 != __1i2 );
case 62 :return (long long )(__1i1 == __1i2 );
case 58 :return (long long )(__1i1 < __1i2 );
case 59 :return (long long )(__1i1 <= __1i2 );
case 60 :return (long long )(__1i1 > __1i2 );
case 61 :return (long long )(__1i1 >= __1i2 );
case 52 :return (__1i1 & __1i2 );
case 66 :return (long long )(__1i1 && __1i2 );
case 65 :return (__1i1 | __1i2 );
case 67 :return (long long )(__1i1 || __1i2 );
case 64 :return (__1i1 ^ __1i2 );
case 53 :if (__1i2 == 0 ){ 
# 988 "/home/claude/cfront-3/src/expr2.cpp"
if (Neval == 0 ){ 
# 989 "/home/claude/cfront-3/src/expr2.cpp"
Neval = (const char *)"mod zero";
# 989 "/home/claude/cfront-3/src/expr2.cpp"

# 990 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCc ( (const char *)"mod zero") ;
}
return (long long )1 ;
}
return (__1i1 % __1i2 );
case 68 :return (eval__4exprFv ( __0this -> __O4__4expr.cond ) ?__1i1 :__1i2 );
case 51 :if (__1i2 == 0 ){ 
# 997 "/home/claude/cfront-3/src/expr2.cpp"
if (Neval == 0 ){ 
# 998 "/home/claude/cfront-3/src/expr2.cpp"
Neval = (const char *)"divide by zero";
# 998 "/home/claude/cfront-3/src/expr2.cpp"

# 999 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCc ( (const char *)"divide by zero") ;
}
return (long long )1 ;
}
return (__1i1 / __1i2 );
case 71 :
# 1005 "/home/claude/cfront-3/src/expr2.cpp"
case 147 :
# 1006 "/home/claude/cfront-3/src/expr2.cpp"
return __1i2 ;
}

# 1009 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCc ( (int )'i' , (const char *)"fall off end of expr::eval()") ;
return (long long )0 ;

# 1010 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 463 "/home/claude/cfront-3/src/cfront.h"
Pclass is_base__8classdefFPCcPUci (struct classdef *__0this , const char *, TOK *, int __1level );

# 1032 "/home/claude/cfront-3/src/expr2.cpp"
bit baseof__8classdefFP8classdef (register struct classdef *__0this , Pclass __1cl )
# 1036 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1036 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X83 ;

# 1036 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X84 ;

# 1037 "/home/claude/cfront-3/src/expr2.cpp"
if (__1cl == 0 )return (unsigned char )0 ;
if (( (__1__X83 = __1cl ), ( (__1__X84 = __0this ), ( ((__1__X83 == __1__X84 )?1 :((__1__X83 && __1__X84 )?(((int )same_class__8classdefFP8classdefi ( __1__X83 , __1__X84 ,
# 1038 "/home/claude/cfront-3/src/expr2.cpp"
0 ) )):0 ))) ) ) )return (unsigned char )1 ;
ppbase = 25 ;
{ Pclass __1bcl ;

# 1040 "/home/claude/cfront-3/src/expr2.cpp"
__1bcl = is_base__8classdefFPCcPUci ( __0this , __1cl -> string__8classdef , (TOK *)0 , 0 ) ;
return (unsigned char )(__1bcl && (ppbase == 25 ));

# 1041 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 1044 "/home/claude/cfront-3/src/expr2.cpp"
static int mem_match__FP3fctT1 (Pfct __1f1 , Pfct __1f2 )
# 1050 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1050 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X85 ;

# 1050 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X86 ;

# 1054 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1f1 == 0 )|| (__1f2 == 0 ))return 0 ;
if ((__1f1 -> memof__3fct && __1f2 -> f_this__3fct )&& (! ( (__1__X85 = __1f2 -> memof__3fct ), ( (__1__X86 = __1f1 -> memof__3fct ),
# 1055 "/home/claude/cfront-3/src/expr2.cpp"
( ((__1__X85 == __1__X86 )?1 :((__1__X85 && __1__X86 )?(((int )same_class__8classdefFP8classdefi ( __1__X85 , __1__X86 , 0 ) )):0 ))) ) ) ))return 0 ;
if (__1f2 -> f_this__3fct )return 0 ;
if (__1f1 -> memof__3fct && __1f2 -> f_static__3fct )return 0 ;
if (check__4typeFP4typeUcT2 ( (struct type *)__1f1 , (struct type *)__1f2 , (unsigned char )70 , (unsigned char )0 ) )return 0 ;
# 1058 "/home/claude/cfront-3/src/expr2.cpp"

# 1059 "/home/claude/cfront-3/src/expr2.cpp"
return 1 ;
}

# 1062 "/home/claude/cfront-3/src/expr2.cpp"
int Pchecked = 0 ;

# 1065 "/home/claude/cfront-3/src/expr2.cpp"
static Pexpr return_elist__FP4name (Pname __1args )
# 1066 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1070 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __1head ;

# 1070 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __1tail ;

# 1070 "/home/claude/cfront-3/src/expr2.cpp"
__1head = 0 ;

# 1070 "/home/claude/cfront-3/src/expr2.cpp"
__1tail = 0 ;

# 1072 "/home/claude/cfront-3/src/expr2.cpp"
{ { Pname __1n ;

# 1072 "/home/claude/cfront-3/src/expr2.cpp"
__1n = __1args ;

# 1072 "/home/claude/cfront-3/src/expr2.cpp"
for(;__1n ;__1n = __1n -> __O1__4name.n_list ) 
# 1073 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1074 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __2e ;

# 1074 "/home/claude/cfront-3/src/expr2.cpp"
__2e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (struct expr *)__1n , (struct expr *)0 ) ;
if (__1head == 0 )
# 1076 "/home/claude/cfront-3/src/expr2.cpp"
__1head = __2e ;
if (__1tail )
# 1078 "/home/claude/cfront-3/src/expr2.cpp"
__1tail -> __O3__4expr.e2 = __2e ;
__1tail = __2e ;
}

# 1082 "/home/claude/cfront-3/src/expr2.cpp"
return __1head ;

# 1082 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1082 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1086 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr ptof__FP3fctP4exprP5table (Pfct __1ef , Pexpr __1e , Ptable __1tbl );

# 669 "/home/claude/cfront-3/src/cfront.h"
Pname find__3genFP3fctUc (struct gen *__0this , Pfct , bit );

# 952 "/home/claude/cfront-3/src/cfront.h"

# 239 "/home/claude/cfront-3/src/template.h"
extern Pname has_templ_instance__FP4nameP4exprUc (Pname , Pexpr , bit );

# 798 "/home/claude/cfront-3/src/cfront.h"
Pexpr typ__4exprFP5table (struct expr *__0this , Ptable );

# 952 "/home/claude/cfront-3/src/cfront.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 1086 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr ptof__FP3fctP4exprP5table (Pfct __1ef , Pexpr __1e , Ptable __1tbl )
# 1090 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1091 "/home/claude/cfront-3/src/expr2.cpp"
Pfct __1f ;
Pname __1n ;

# 1092 "/home/claude/cfront-3/src/expr2.cpp"
__1n = 0 ;
eee :
# 1095 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1e -> base__4node ){ 
# 1096 "/home/claude/cfront-3/src/expr2.cpp"
case 68 :
# 1097 "/home/claude/cfront-3/src/expr2.cpp"
__1e -> __O2__4expr.e1 = ptof__FP3fctP4exprP5table ( __1ef , __1e -> __O2__4expr.e1 , __1tbl ) ;
__1e -> __O3__4expr.e2 = ptof__FP3fctP4exprP5table ( __1ef , __1e -> __O3__4expr.e2 , __1tbl ) ;
return __1e ;
case 71 :
# 1101 "/home/claude/cfront-3/src/expr2.cpp"
case 147 :
# 1102 "/home/claude/cfront-3/src/expr2.cpp"
__1e -> __O3__4expr.e2 = ptof__FP3fctP4exprP5table ( __1ef , __1e -> __O3__4expr.e2 , __1tbl ) ;
if (__1e -> __O1__4expr.tp && (__1e -> __O1__4expr.tp -> base__4node == 108 ))__1e -> __O1__4expr.tp = __1e -> __O3__4expr.e2 -> __O1__4expr.tp ;
return __1e ;
case 85 :
# 1106 "/home/claude/cfront-3/src/expr2.cpp"
__1f = (((struct fct *)(((struct fct *)__1e -> __O1__4expr.tp ))));
__1n = (((struct name *)(((struct name *)__1e ))));

# 1109 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1f -> base__4node ){ 
# 1110 "/home/claude/cfront-3/src/expr2.cpp"
case 76 :
# 1111 "/home/claude/cfront-3/src/expr2.cpp"
__1e = (struct expr *)find__3genFP3fctUc ( ((struct gen *)(((struct gen *)__1f ))), __1ef , (unsigned char )0 )
# 1111 "/home/claude/cfront-3/src/expr2.cpp"
;

# 1113 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1e == 0 )&& ( __1n -> n_template_fct__4name ) ){ 
# 1114 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __4arg ;

# 1114 "/home/claude/cfront-3/src/expr2.cpp"
__4arg = return_elist__FP4name ( __1ef -> argtype__3fct ) ;
__1e = (struct expr *)has_templ_instance__FP4nameP4exprUc ( __1n , __4arg , (unsigned char )0 ) ;
}

# 1118 "/home/claude/cfront-3/src/expr2.cpp"
if (__1e == 0 ){ 
# 1119 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1119 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V87 ;

# 1119 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot deduceT for &overloaded%n", (const struct ea *)( ((& __0__V87 )-> __O1__2ea.p =
# 1119 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n )), (& __0__V87 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1119 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
return __1e ;
} }

# 1123 "/home/claude/cfront-3/src/expr2.cpp"
case 108 :
# 1125 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1f -> base__4node == 108 )&& (__1f -> fct_base__3fct == 1)){ 
# 1126 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __4arg ;

# 1126 "/home/claude/cfront-3/src/expr2.cpp"
__4arg = return_elist__FP4name ( __1ef -> argtype__3fct ) ;
__1e = (struct expr *)has_templ_instance__FP4nameP4exprUc ( __1n , __4arg , (unsigned char )0 ) ;
if (__1e == 0 )return __1e ;
}

# 1131 "/home/claude/cfront-3/src/expr2.cpp"
Pchecked = mem_match__FP3fctT1 ( __1ef , ((struct fct *)(((struct fct *)__1e -> __O1__4expr.tp )))) ;
__1e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __1e ) ;
return typ__4exprFP5table ( __1e , __1tbl ) ;

# 1135 "/home/claude/cfront-3/src/expr2.cpp"
}
goto ad ;

# 1138 "/home/claude/cfront-3/src/expr2.cpp"
case 86 :
# 1139 "/home/claude/cfront-3/src/expr2.cpp"
if (__1ef -> memof__3fct ){ 
# 1140 "/home/claude/cfront-3/src/expr2.cpp"
__1e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , zero ) ;
# 1140 "/home/claude/cfront-3/src/expr2.cpp"

# 1141 "/home/claude/cfront-3/src/expr2.cpp"
__1e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , __1e , zero ) ;
__1e -> __O1__4expr.tp = (struct type *)zero_type ;
return __1e ;
}
break ;

# 1147 "/home/claude/cfront-3/src/expr2.cpp"
case 177 :
# 1149 "/home/claude/cfront-3/src/expr2.cpp"
do __1e = __1e -> __O4__4expr.mem ;
while (__1e -> base__4node == 177 );

# 1150 "/home/claude/cfront-3/src/expr2.cpp"
goto eee ;

# 1152 "/home/claude/cfront-3/src/expr2.cpp"
case 45 :
# 1153 "/home/claude/cfront-3/src/expr2.cpp"
case 44 :
# 1154 "/home/claude/cfront-3/src/expr2.cpp"
__1f = (((struct fct *)(((struct fct *)__1e -> __O4__4expr.mem -> __O1__4expr.tp ))));

# 1156 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1f -> base__4node ){ 
# 1156 "/home/claude/cfront-3/src/expr2.cpp"
const void *__2__X90 ;

# 1157 "/home/claude/cfront-3/src/expr2.cpp"
case 76 :
# 1158 "/home/claude/cfront-3/src/expr2.cpp"
__1n = find__3genFP3fctUc ( ((struct gen *)(((struct gen *)__1f ))), __1ef , (unsigned char )0 ) ;
if (__1n == 0 ){ 
# 1159 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V88 ;

# 1159 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot deduceT for &overloaded%n", (const struct ea *)( (__2__X90 = (const void
# 1159 "/home/claude/cfront-3/src/expr2.cpp"
*)__1e -> __O4__4expr.mem ), ( ((& __0__V88 )-> __O1__2ea.p = __2__X90 ), (& __0__V88 )) ) , (const struct ea *)ea0 ,
# 1159 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else __1e = (struct expr *)__1n ;

# 1162 "/home/claude/cfront-3/src/expr2.cpp"
case 108 :
# 1163 "/home/claude/cfront-3/src/expr2.cpp"
Pchecked = mem_match__FP3fctT1 ( __1ef , ((struct fct *)(((struct fct *)__1e -> __O1__4expr.tp )))) ;
__1e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __1e ) ;
return typ__4exprFP5table ( __1e , __1tbl ) ;

# 1168 "/home/claude/cfront-3/src/expr2.cpp"
}
goto ad ;

# 1171 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 1172 "/home/claude/cfront-3/src/expr2.cpp"
case 145 :
# 1173 "/home/claude/cfront-3/src/expr2.cpp"
__1f = (((struct fct *)(((struct fct *)__1e -> __O3__4expr.e2 -> __O1__4expr.tp ))));
__1n = (((struct name *)(((struct name *)__1e -> __O3__4expr.e2 ))));

# 1176 "/home/claude/cfront-3/src/expr2.cpp"
ad :
# 1177 "/home/claude/cfront-3/src/expr2.cpp"
if (__1f -> base__4node == 76 ){ 
# 1178 "/home/claude/cfront-3/src/expr2.cpp"
Pname __3nn ;

# 1178 "/home/claude/cfront-3/src/expr2.cpp"
__3nn = find__3genFP3fctUc ( ((struct gen *)(((struct gen *)__1f ))), __1ef , (unsigned char )0 ) ;

# 1180 "/home/claude/cfront-3/src/expr2.cpp"
if ((__3nn == 0 )&& ( __1n -> n_template_fct__4name ) ){ 
# 1181 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __4arg ;

# 1181 "/home/claude/cfront-3/src/expr2.cpp"
__4arg = return_elist__FP4name ( __1ef -> argtype__3fct ) ;
__3nn = has_templ_instance__FP4nameP4exprUc ( __1n , __4arg , (unsigned char )0 ) ;
}

# 1185 "/home/claude/cfront-3/src/expr2.cpp"
if (__3nn == 0 ){ 
# 1185 "/home/claude/cfront-3/src/expr2.cpp"
const void *__2__X91 ;

# 1186 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1186 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V89 ;

# 1186 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot deduceT for &overloaded %s()", (const struct ea *)( (__2__X91 = (const void
# 1186 "/home/claude/cfront-3/src/expr2.cpp"
*)(((struct gen *)(((struct gen *)__1f ))))-> fct_list__3gen -> f__9name_list -> __O2__4expr.string ), ( ((& __0__V89 )-> __O1__2ea.p = __2__X91 ), (& __0__V89 )) )
# 1186 "/home/claude/cfront-3/src/expr2.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return (struct expr *)__3nn ;
} }

# 1190 "/home/claude/cfront-3/src/expr2.cpp"
__1n = __3nn ;
{ Pfct __3nf ;

# 1192 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X16 ;

# 1192 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1400qm5qkxojwcnm ;

# 1192 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1500qm5qkxojwcnm ;

# 1191 "/home/claude/cfront-3/src/expr2.cpp"
__3nf = ( ((__1n -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 1191 "/home/claude/cfront-3/src/expr2.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qm5qkxojwcnm )-> __O1__2ea.p = ((const void *)__1n )),
# 1191 "/home/claude/cfront-3/src/expr2.cpp"
(& __0__X__V1400qm5qkxojwcnm )) , (const struct ea *)( (__2__X16 = __1n -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qm5qkxojwcnm )->
# 1191 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qm5qkxojwcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 1191 "/home/claude/cfront-3/src/expr2.cpp"
, (((struct fct *)0 ))) )) ;
Pchecked = mem_match__FP3fctT1 ( __1ef , __3nf ) ;
if (__3nf -> f_static__3fct )__3nf -> memof__3fct = 0 ;
__1e -> __O3__4expr.e2 = (struct expr *)__1n ;
__1e -> __O1__4expr.tp = __1n -> __O1__4expr.tp ;

# 1195 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1199 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1f -> base__4node == 108 )&& (__1f -> fct_base__3fct == 1)){ 
# 1200 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __3arg ;
Pname __3nn ;

# 1202 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X16 ;

# 1202 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1400qm5qkxojwcnm ;

# 1202 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1500qm5qkxojwcnm ;

# 1200 "/home/claude/cfront-3/src/expr2.cpp"
__3arg = return_elist__FP4name ( __1ef -> argtype__3fct ) ;
__3nn = has_templ_instance__FP4nameP4exprUc ( __1n , __3arg , (unsigned char )0 ) ;
if (__3nn == 0 )return (struct expr *)__3nn ;
__1n = __3nn ;
Pchecked = mem_match__FP3fctT1 ( __1ef , ( ((__1n -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' ,
# 1204 "/home/claude/cfront-3/src/expr2.cpp"
(const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qm5qkxojwcnm )-> __O1__2ea.p = ((const
# 1204 "/home/claude/cfront-3/src/expr2.cpp"
void *)__1n )), (& __0__X__V1400qm5qkxojwcnm )) , (const struct ea *)( (__2__X16 = __1n -> __O1__4expr.tp -> base__4node ), ( ((
# 1204 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__X__V1500qm5qkxojwcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qm5qkxojwcnm )) ) , (const struct ea *)ea0 , (const
# 1204 "/home/claude/cfront-3/src/expr2.cpp"
struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) ;
__1e -> __O3__4expr.e2 = (struct expr *)__1n ;
__1e -> __O1__4expr.tp = __1n -> __O1__4expr.tp ;
}
if (__1n )lval__4exprFUc ( (struct expr *)__1n , (unsigned char )112 ) ;
break ;

# 1211 "/home/claude/cfront-3/src/expr2.cpp"
case 113 :
# 1212 "/home/claude/cfront-3/src/expr2.cpp"
case 191 :
# 1213 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1214 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __3te ;

# 1214 "/home/claude/cfront-3/src/expr2.cpp"
__3te = __1e -> __O2__4expr.e1 ;
if (__1e -> __O2__4expr.e1 -> base__4node == 145 )__3te = __1e -> __O2__4expr.e1 -> __O3__4expr.e2 ;
((void )ptof__FP3fctP4exprP5table ( __1ef , __3te , __1tbl ) );
}
}
return __1e ;
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 794 "/home/claude/cfront-3/src/cfront.h"
void del__4exprFv (struct expr *__0this );

# 1234 "/home/claude/cfront-3/src/cfront.h"
extern Pname make_tmp__FcP4typeP5table (char , Ptype , Ptable );

# 1249 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr mptr_assign__FP4exprT1 (Pexpr , Pexpr );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 509 "/home/claude/cfront-3/src/cfront.h"
void clear__5clistFv (struct clist *__0this );

# 1241 "/home/claude/cfront-3/src/cfront.h"
extern int is_unique_base__FP8classdefPCciT3T1 (Pclass , const char *, int , int , Pclass __0priSeen );

# 828 "/home/claude/cfront-3/src/cfront.h"

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );

# 1155 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr try_to_coerce__FP4typeP4exprPCcP5table (Ptype , Pexpr , const char *, Ptable );

# 1248 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr cast_cptr__FP8classdefP4exprP5tablei (Pclass __0ccl , Pexpr __0ee , Ptable __0tbl , int __0real_cast );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 1222 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr ptr_init__FP3ptrP4exprP5table (Pptr __1p , Pexpr __1init , Ptable __1tbl )
# 1229 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1232 "/home/claude/cfront-3/src/expr2.cpp"
Pchecked = 0 ;

# 1234 "/home/claude/cfront-3/src/expr2.cpp"
{ Ptype __1it ;

# 1234 "/home/claude/cfront-3/src/expr2.cpp"
__1it = skiptypedefs__4typeFv ( __1init -> __O1__4expr.tp ) ;

# 1236 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1it -> base__4node ){ 
# 1237 "/home/claude/cfront-3/src/expr2.cpp"
case 138 :
# 1238 "/home/claude/cfront-3/src/expr2.cpp"
break ;
case 121 :
# 1240 "/home/claude/cfront-3/src/expr2.cpp"
case 21 :
# 1241 "/home/claude/cfront-3/src/expr2.cpp"
case 5 :
# 1242 "/home/claude/cfront-3/src/expr2.cpp"
case 29 :
# 1243 "/home/claude/cfront-3/src/expr2.cpp"
case 22 :
# 1244 "/home/claude/cfront-3/src/expr2.cpp"
case 122 :
# 1245 "/home/claude/cfront-3/src/expr2.cpp"
{ Neval = 0 ;
{ long long __3i ;

# 1247 "/home/claude/cfront-3/src/expr2.cpp"
const void *__2__X106 ;

# 1246 "/home/claude/cfront-3/src/expr2.cpp"
__3i = eval__4exprFv ( __1init ) ;
if (Neval )
# 1248 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1248 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V92 ;

# 1248 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"badPIr: %s", (const struct ea *)( (__2__X106 = (const void
# 1248 "/home/claude/cfront-3/src/expr2.cpp"
*)Neval ), ( ((& __0__V92 )-> __O1__2ea.p = __2__X106 ), (& __0__V92 )) ) , (const struct ea *)ea0 , (const
# 1248 "/home/claude/cfront-3/src/expr2.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 1250 "/home/claude/cfront-3/src/expr2.cpp"
if (__3i )
# 1251 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1251 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V93 ;

# 1251 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"badPIr value %d", (const struct ea *)( (( ((& __0__V93 )->
# 1251 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.i = ((unsigned long )__3i )), 0 ) ), (& __0__V93 )) , (const struct ea *)ea0 , (const struct
# 1251 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 1253 "/home/claude/cfront-3/src/expr2.cpp"
if (__1init && (__1init -> permanent__4node == 0 ))del__4exprFv ( __1init ) ;
__1init = zero ;
}
break ;

# 1256 "/home/claude/cfront-3/src/expr2.cpp"
}
}
}

# 1260 "/home/claude/cfront-3/src/expr2.cpp"
{ Pclass __1c1 ;

# 1260 "/home/claude/cfront-3/src/expr2.cpp"
__1c1 = __1p -> memof__3ptr ;

# 1262 "/home/claude/cfront-3/src/expr2.cpp"
if (__1c1 ){ 
# 1263 "/home/claude/cfront-3/src/expr2.cpp"
if (__1init == zero )
# 1264 "/home/claude/cfront-3/src/expr2.cpp"
;
else { 
# 1266 "/home/claude/cfront-3/src/expr2.cpp"
Pclass __3c2 ;

# 1267 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X107 ;

# 1267 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X108 ;

# 1268 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1it -> base__4node ){ 
# 1269 "/home/claude/cfront-3/src/expr2.cpp"
case 108 :
# 1270 "/home/claude/cfront-3/src/expr2.cpp"
__3c2 = (((struct fct *)(((struct fct *)__1it ))))-> memof__3fct ;
break ;
case 76 :
# 1273 "/home/claude/cfront-3/src/expr2.cpp"
__3c2 = (((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__1it ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ))))-> memof__3fct ;
break ;
case 125 :
# 1276 "/home/claude/cfront-3/src/expr2.cpp"
case 158 :
# 1277 "/home/claude/cfront-3/src/expr2.cpp"
__3c2 = (((struct ptr *)(((struct ptr *)__1it ))))-> memof__3ptr ;
break ;
default :
# 1280 "/home/claude/cfront-3/src/expr2.cpp"
__3c2 = 0 ;
if (__1init -> base__4node == 68 ){ 
# 1284 "/home/claude/cfront-3/src/expr2.cpp"
Pname __5temp ;

# 1284 "/home/claude/cfront-3/src/expr2.cpp"
__5temp = make_tmp__FcP4typeP5table ( 'A' , (struct type *)mptr_type , __1tbl ) ;

# 1286 "/home/claude/cfront-3/src/expr2.cpp"
__1init -> __O2__4expr.e1 = mptr_assign__FP4exprT1 ( (struct expr *)__5temp , __1init -> __O2__4expr.e1 ) ;
__1init -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __1init -> __O2__4expr.e1 , (struct expr *)__5temp ) ;
__1init -> __O2__4expr.e1 -> __O1__4expr.tp = __5temp -> __O1__4expr.tp ;

# 1290 "/home/claude/cfront-3/src/expr2.cpp"
__1init -> __O3__4expr.e2 = mptr_assign__FP4exprT1 ( (struct expr *)__5temp , __1init -> __O3__4expr.e2 ) ;
__1init -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __1init -> __O3__4expr.e2 , (struct expr *)__5temp ) ;
__1init -> __O1__4expr.tp = (struct type *)__1p ;
}
}

# 1296 "/home/claude/cfront-3/src/expr2.cpp"
if ((__3c2 != 0 )&& (! ( (__1__X107 = __1c1 ), ( (__1__X108 = __3c2 ), ( ((__1__X107 == __1__X108 )?1 :((__1__X107 && __1__X108 )?(((int
# 1296 "/home/claude/cfront-3/src/expr2.cpp"
)same_class__8classdefFP8classdefi ( __1__X107 , __1__X108 , 0 ) )):0 ))) ) ) )){ 
# 1297 "/home/claude/cfront-3/src/expr2.cpp"
Nptr = 0 ;
Noffset = 0 ;
clear__5clistFv ( vcllist ) ;
vcllist = 0 ;
{ int __4u1 ;

# 1301 "/home/claude/cfront-3/src/expr2.cpp"
__4u1 = is_unique_base__FP8classdefPCciT3T1 ( __1c1 , __3c2 -> string__8classdef , 0 , 0 , (struct classdef *)0 ) ;

# 1303 "/home/claude/cfront-3/src/expr2.cpp"
if (__4u1 && (Nptr || Noffset )){ 
# 1305 "/home/claude/cfront-3/src/expr2.cpp"
int __5bad ;

# 1306 "/home/claude/cfront-3/src/expr2.cpp"
const void *__2__X111 ;

# 1305 "/home/claude/cfront-3/src/expr2.cpp"
__5bad = 0 ;
if ((__4u1 == 1 )&& (! Nptr )){ 
# 1307 "/home/claude/cfront-3/src/expr2.cpp"
if (__1init -> base__4node == 124 ){ 
# 1309 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1init -> __O2__4expr.e1 -> __O2__4expr.e1 -> base__4node ){
# 1309 "/home/claude/cfront-3/src/expr2.cpp"

# 1309 "/home/claude/cfront-3/src/expr2.cpp"
struct ival *__0__X109 ;

# 1309 "/home/claude/cfront-3/src/expr2.cpp"
long long __2__X110 ;

# 1310 "/home/claude/cfront-3/src/expr2.cpp"
case 150 :
# 1311 "/home/claude/cfront-3/src/expr2.cpp"
__1init -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O2__4expr.i1 += Noffset ;
break ;
case 86 :
# 1314 "/home/claude/cfront-3/src/expr2.cpp"
__1init -> __O2__4expr.e1 -> __O2__4expr.e1 = (struct expr *)( (__0__X109 = 0 ), ( (__2__X110 = Noffset ), ( ((__0__X109 || (__0__X109 =
# 1314 "/home/claude/cfront-3/src/expr2.cpp"
(struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival))) ))?( (__0__X109 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X109 ), (unsigned char
# 1314 "/home/claude/cfront-3/src/expr2.cpp"
)150 , (struct expr *)0 , (struct expr *)0 ) ), (__0__X109 -> __O2__4expr.i1 = __2__X110 )) :0 ), __0__X109 ) ) ) ;
# 1314 "/home/claude/cfront-3/src/expr2.cpp"

# 1315 "/home/claude/cfront-3/src/expr2.cpp"
break ;
default :
# 1317 "/home/claude/cfront-3/src/expr2.cpp"
__5bad = 1 ;
}

# 1321 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1init -> __O2__4expr.e1 -> __O3__4expr.e2 -> base__4node ){ 
# 1322 "/home/claude/cfront-3/src/expr2.cpp"
case 150 :
# 1323 "/home/claude/cfront-3/src/expr2.cpp"
if (0 < __1init -> __O2__4expr.e1 -> __O3__4expr.e2 -> __O2__4expr.i1 ){ 
# 1327 "/home/claude/cfront-3/src/expr2.cpp"
}
else 
# 1329 "/home/claude/cfront-3/src/expr2.cpp"
break
# 1329 "/home/claude/cfront-3/src/expr2.cpp"
;
default :
# 1331 "/home/claude/cfront-3/src/expr2.cpp"
__5bad = 1 ;
}
}
else 
# 1335 "/home/claude/cfront-3/src/expr2.cpp"
__5bad = 1 ;
}
else 
# 1338 "/home/claude/cfront-3/src/expr2.cpp"
__5bad = 1 ;

# 1340 "/home/claude/cfront-3/src/expr2.cpp"
if (__5bad ){ 
# 1340 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V94 ;

# 1340 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V95 ;

# 1340 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"%t assigned to%t (too complicated)", (const struct ea *)( (__2__X111 =
# 1340 "/home/claude/cfront-3/src/expr2.cpp"
(const void *)__1init -> __O1__4expr.tp ), ( ((& __0__V94 )-> __O1__2ea.p = __2__X111 ), (& __0__V94 )) ) , (const
# 1340 "/home/claude/cfront-3/src/expr2.cpp"
struct ea *)( ((& __0__V95 )-> __O1__2ea.p = ((const void *)__1p )), (& __0__V95 )) , (const struct ea *)ea0 ,
# 1340 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 ) ;
} }

# 1343 "/home/claude/cfront-3/src/expr2.cpp"
Nptr = 0 ;
Noffset = 0 ;
clear__5clistFv ( vcllist ) ;
vcllist = 0 ;
{ int __4u2 ;

# 1347 "/home/claude/cfront-3/src/expr2.cpp"
__4u2 = is_unique_base__FP8classdefPCciT3T1 ( __3c2 , __1c1 -> string__8classdef , 0 , 0 , (struct classdef *)0 ) ;

# 1349 "/home/claude/cfront-3/src/expr2.cpp"
if (__4u2 && (Nptr || Noffset )){ 
# 1349 "/home/claude/cfront-3/src/expr2.cpp"
const void *__2__X112 ;

# 1351 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1351 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V96 ;

# 1351 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V97 ;

# 1351 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"%t assigned to%t", (const struct ea *)( (__2__X112 =
# 1351 "/home/claude/cfront-3/src/expr2.cpp"
(const void *)__1init -> __O1__4expr.tp ), ( ((& __0__V96 )-> __O1__2ea.p = __2__X112 ), (& __0__V96 )) ) , (const
# 1351 "/home/claude/cfront-3/src/expr2.cpp"
struct ea *)( ((& __0__V97 )-> __O1__2ea.p = ((const void *)__1p )), (& __0__V97 )) , (const struct ea *)ea0 ,
# 1351 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 ) ;
} }

# 1352 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1352 "/home/claude/cfront-3/src/expr2.cpp"
}
}
}
}

# 1357 "/home/claude/cfront-3/src/expr2.cpp"
{ Ptype __1pit ;

# 1357 "/home/claude/cfront-3/src/expr2.cpp"
__1pit = skiptypedefs__4typeFv ( __1p -> typ__5pvtyp ) ;

# 1359 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1pit -> base__4node ){ 
# 1360 "/home/claude/cfront-3/src/expr2.cpp"
case 108 :
# 1361 "/home/claude/cfront-3/src/expr2.cpp"
return ptof__FP3fctP4exprP5table ( ((struct fct *)(((struct fct *)__1pit ))), __1init , __1tbl ) ;
case 119 :
# 1363 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1364 "/home/claude/cfront-3/src/expr2.cpp"
Pptr __3r ;
Pexpr __3x ;
Pname __3old_Ncoerce ;

# 1364 "/home/claude/cfront-3/src/expr2.cpp"
__3r = is_ptr_or_ref__4typeFv ( __1it ) ;
__3x = 0 ;
__3old_Ncoerce = Ncoerce ;
Ncoerce = 0 ;
if (__3r == 0 ){ 
# 1369 "/home/claude/cfront-3/src/expr2.cpp"
suppress_error ++ ;
__3x = try_to_coerce__FP4typeP4exprPCcP5table ( (struct type *)__1p , __1init , (const char *)"initializer", __1tbl ) ;
# 1370 "/home/claude/cfront-3/src/expr2.cpp"
;
suppress_error -- ;
}

# 1375 "/home/claude/cfront-3/src/expr2.cpp"
if ((__3r != 0 )|| ((__3x && Ncoerce )&& (__3r = is_ptr_or_ref__4typeFv ( __3x -> __O1__4expr.tp ) )))
# 1376 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1377 "/home/claude/cfront-3/src/expr2.cpp"
if (__3x && Ncoerce )__1init = __3x ;
# 1377 "/home/claude/cfront-3/src/expr2.cpp"

# 1378 "/home/claude/cfront-3/src/expr2.cpp"
Pchecked = 1 ;
{ TOK __4b ;
TOK __4bb ;

# 1379 "/home/claude/cfront-3/src/expr2.cpp"
__4b = __1p -> base__4node ;
__4bb = __3r -> base__4node ;
if (__4b == 158 )__1p -> base__4node = 125 ;
if (__4bb == 158 )__3r -> base__4node = 125 ;
if (check__4typeFP4typeUcT2 ( (struct type *)__1p , (struct type *)__3r , (unsigned char )70 , (unsigned char )0 ) ){ 
# 1383 "/home/claude/cfront-3/src/expr2.cpp"
const
# 1383 "/home/claude/cfront-3/src/expr2.cpp"
void *__2__X113 ;

# 1384 "/home/claude/cfront-3/src/expr2.cpp"
if (((cc && cc -> nof__11dcl_context )&& (((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp ))))-> f_const__3fct )&& ((((struct expr *)cc -> c_this__11dcl_context ))== __1init ))
# 1387 "/home/claude/cfront-3/src/expr2.cpp"
{
# 1387 "/home/claude/cfront-3/src/expr2.cpp"

# 1387 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V98 ;

# 1387 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V99 ;

# 1387 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V100 ;

# 1387 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V101 ;

# 1387 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n const: assignment of%n (%t) to%t", (const struct ea *)( (__2__X113 = (const void
# 1387 "/home/claude/cfront-3/src/expr2.cpp"
*)cc -> nof__11dcl_context ), ( ((& __0__V98 )-> __O1__2ea.p = __2__X113 ), (& __0__V98 )) ) , (const struct ea *)(
# 1387 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V99 )-> __O1__2ea.p = ((const void *)__1init )), (& __0__V99 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V100 ,
# 1387 "/home/claude/cfront-3/src/expr2.cpp"
(const void *)__1init -> __O1__4expr.tp ) , (const struct ea *)( ((& __0__V101 )-> __O1__2ea.p = ((const void *)__1p )),
# 1387 "/home/claude/cfront-3/src/expr2.cpp"
(& __0__V101 )) ) ;
} else { 
# 1388 "/home/claude/cfront-3/src/expr2.cpp"
const void *__2__X114 ;

# 1388 "/home/claude/cfront-3/src/expr2.cpp"
const void *__2__X115 ;

# 1389 "/home/claude/cfront-3/src/expr2.cpp"
__1p -> base__4node = __4b ;
if (__1init -> base__4node == 145 )
# 1391 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1391 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V102 ;

# 1391 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V103 ;

# 1391 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"no standard conversion of%t to%t", (const struct ea *)( (__2__X114 = (const void
# 1391 "/home/claude/cfront-3/src/expr2.cpp"
*)__1init -> __O3__4expr.e2 -> __O1__4expr.tp ), ( ((& __0__V102 )-> __O1__2ea.p = __2__X114 ), (& __0__V102 )) ) , (const struct
# 1391 "/home/claude/cfront-3/src/expr2.cpp"
ea *)( ((& __0__V103 )-> __O1__2ea.p = ((const void *)__1p )), (& __0__V103 )) , (const struct ea *)ea0 , (const
# 1391 "/home/claude/cfront-3/src/expr2.cpp"
struct ea *)ea0 ) ;
} else 
# 1393 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1393 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V104 ;

# 1393 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V105 ;

# 1393 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"no standard conversion of%t to%t", (const struct ea *)( (__2__X115 = (const void
# 1393 "/home/claude/cfront-3/src/expr2.cpp"
*)__1init -> __O1__4expr.tp ), ( ((& __0__V104 )-> __O1__2ea.p = __2__X115 ), (& __0__V104 )) ) , (const struct ea *)(
# 1393 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V105 )-> __O1__2ea.p = ((const void *)__1p )), (& __0__V105 )) , (const struct ea *)ea0 , (const struct
# 1393 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
} }
}
__1p -> base__4node = __4b ;
__3r -> base__4node = __4bb ;
{ Pexpr __4cp ;

# 1398 "/home/claude/cfront-3/src/expr2.cpp"
__4cp = cast_cptr__FP8classdefP4exprP5tablei ( ((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1pit ))))-> b_name__8basetype -> __O1__4expr.tp ))), __1init , __1tbl , 0 ) ;
if (__4cp != __1init ){ 
# 1399 "/home/claude/cfront-3/src/expr2.cpp"
register struct cast *__0__X116 ;

# 1400 "/home/claude/cfront-3/src/expr2.cpp"
__1p -> permanent__4node = 1 ;
Ncoerce = __3old_Ncoerce ;
return (struct expr *)( (__0__X116 = 0 ), ( ((__0__X116 || (__0__X116 = (struct cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast)))
# 1402 "/home/claude/cfront-3/src/expr2.cpp"
))?( (__0__X116 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X116 ), (unsigned char )191 , __4cp , (struct expr *)0 ) ), (__0__X116 ->
# 1402 "/home/claude/cfront-3/src/expr2.cpp"
__O1__4expr.tp = (__0__X116 -> __O4__4expr.tp2 = ((struct type *)__1p )))) :0 ), __0__X116 ) ) ;
}

# 1403 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1403 "/home/claude/cfront-3/src/expr2.cpp"
}
}
Ncoerce = __3old_Ncoerce ;

# 1407 "/home/claude/cfront-3/src/expr2.cpp"
}
default :
# 1409 "/home/claude/cfront-3/src/expr2.cpp"
return __1init ;
}

# 1410 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1410 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1410 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1413 "/home/claude/cfront-3/src/expr2.cpp"
static Pname Lcoerce ;

# 1413 "/home/claude/cfront-3/src/expr2.cpp"
static Pname Rcoerce ;

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 1288 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 65 "/home/claude/cfront-3/src/Bits.h"
struct Bits *__ct__4BitsFUlT1 (struct Bits *__0this , Bits_chunk , size_t );

# 71 "/home/claude/cfront-3/src/Bits.h"
extern void __co__FRC4Bits (struct Bits *__0_result , const struct Bits *);

# 27 "/home/claude/cfront-3/src/Bits.h"

# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 47 "/home/claude/cfront-3/src/overload.h"
extern void best_conv__FRC11Block_PnameRiUc (struct Bits *__0_result , const struct Block_Pname *, int *, bit );

# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 113 "/home/claude/cfront-3/src/Bits.h"
size_t count__4BitsCFv (const struct Bits *const __0this );

# 103 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 1288 "/home/claude/cfront-3/src/cfront.h"

# 1157 "/home/claude/cfront-3/src/cfront.h"
extern Ptype np_promote__FUcN21P4typeT4N21 (TOK , TOK , TOK , Ptype , Ptype , TOK , bit );

# 39 "/home/claude/cfront-3/src/overload.h"

# 718 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 1288 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 30 "/home/claude/cfront-3/src/expr2.cpp"
extern int oper_okay__FP4typeUc (Ptype , TOK );

# 39 "/home/claude/cfront-3/src/overload.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 1415 "/home/claude/cfront-3/src/expr2.cpp"
int try_to_demote__FUcP4typeT2 (TOK __1oper , Ptype __1t1 , Ptype __1t2 )
# 1424 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1427 "/home/claude/cfront-3/src/expr2.cpp"
Pname __1n1 ;
Pclass __1c1 ;
Pname __1n2 ;
Pclass __1c2 ;

# 1432 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __1lt ;
Ptype __1rt ;
int __1not_const1 ;

# 1434 "/home/claude/cfront-3/src/expr2.cpp"
int __1not_const2 ;

# 1435 "/home/claude/cfront-3/src/expr2.cpp"
int __0_result ;

# 1427 "/home/claude/cfront-3/src/expr2.cpp"
__1n1 = (__1t1 ?is_cl_obj__4typeFv ( __1t1 ) :(((struct name *)0 )));
__1c1 = (__1n1 ?(((struct classdef *)(((struct classdef *)__1n1 -> __O1__4expr.tp )))):(((struct classdef *)0 )));
__1n2 = (__1t2 ?is_cl_obj__4typeFv ( __1t2 ) :(((struct name *)0 )));
__1c2 = (__1n2 ?(((struct classdef *)(((struct classdef *)__1n2 -> __O1__4expr.tp )))):(((struct classdef *)0 )));

# 1432 "/home/claude/cfront-3/src/expr2.cpp"
__1lt = __1t1 ;
__1rt = __1t2 ;

# 1436 "/home/claude/cfront-3/src/expr2.cpp"
Lcoerce = (Rcoerce = 0 );

# 1438 "/home/claude/cfront-3/src/expr2.cpp"
{ struct Block_Pname __1rconv ;
struct Block_Pname __1lconv ;
int __1rfound ;
int __1lfound ;

# 1438 "/home/claude/cfront-3/src/expr2.cpp"
( (( ((& __1rconv )-> n__11Block_Pname = 0 ), ((& __1rconv )-> p__11Block_Pname = 0 )) ), (& __1rconv )) ;
# 1438 "/home/claude/cfront-3/src/expr2.cpp"

# 1439 "/home/claude/cfront-3/src/expr2.cpp"
( (( ((& __1lconv )-> n__11Block_Pname = 0 ), ((& __1lconv )-> p__11Block_Pname = 0 )) ), (& __1lconv )) ;
# 1439 "/home/claude/cfront-3/src/expr2.cpp"

# 1440 "/home/claude/cfront-3/src/expr2.cpp"
__1rfound = 0 ;
__1lfound = 0 ;

# 1443 "/home/claude/cfront-3/src/expr2.cpp"
if (__1c1 )
# 1444 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1oper ){ 
# 1445 "/home/claude/cfront-3/src/expr2.cpp"
case 70 :
# 1446 "/home/claude/cfront-3/src/expr2.cpp"
case 126 :
# 1447 "/home/claude/cfront-3/src/expr2.cpp"
case 127 :
# 1448 "/home/claude/cfront-3/src/expr2.cpp"
case 128 :
# 1449 "/home/claude/cfront-3/src/expr2.cpp"
case 129 :
# 1450 "/home/claude/cfront-3/src/expr2.cpp"
case 130 :
# 1451 "/home/claude/cfront-3/src/expr2.cpp"
case 131 :
# 1452 "/home/claude/cfront-3/src/expr2.cpp"
case 132 :
# 1453 "/home/claude/cfront-3/src/expr2.cpp"
case 133 :
# 1454 "/home/claude/cfront-3/src/expr2.cpp"
case 134 :
# 1455 "/home/claude/cfront-3/src/expr2.cpp"
case
# 1455 "/home/claude/cfront-3/src/expr2.cpp"
135 :
# 1456 "/home/claude/cfront-3/src/expr2.cpp"
if (look__5tableFPCcUc ( __1c1 -> memtbl__8classdef , (const char *)"__as", (unsigned char )0 )
# 1456 "/home/claude/cfront-3/src/expr2.cpp"
){ { __0_result = 0 ;

# 1456 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1456 "/home/claude/cfront-3/src/expr2.cpp"

# 1456 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1456 "/home/claude/cfront-3/src/expr2.cpp"
} return __0_result ;
} }
else 
# 1459 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1oper ){ 
# 1460 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 1461 "/home/claude/cfront-3/src/expr2.cpp"
case 48 :
# 1462 "/home/claude/cfront-3/src/expr2.cpp"
case 49 :
# 1463 "/home/claude/cfront-3/src/expr2.cpp"
{ { __0_result = 0 ;

# 1463 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1463 "/home/claude/cfront-3/src/expr2.cpp"

# 1463 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1463 "/home/claude/cfront-3/src/expr2.cpp"
} return __0_result ;
} }

# 1466 "/home/claude/cfront-3/src/expr2.cpp"
if (__1c1 ){ 
# 1467 "/home/claude/cfront-3/src/expr2.cpp"
__1not_const1 = 0 ;

# 1469 "/home/claude/cfront-3/src/expr2.cpp"
{ { Pname __2on1 ;

# 1469 "/home/claude/cfront-3/src/expr2.cpp"
__2on1 = __1c1 -> conv__8classdef ;

# 1469 "/home/claude/cfront-3/src/expr2.cpp"
for(;__2on1 ;__2on1 = __2on1 -> __O1__4name.n_list ) { 
# 1470 "/home/claude/cfront-3/src/expr2.cpp"
Pfct __3f ;

# 1470 "/home/claude/cfront-3/src/expr2.cpp"
__3f = ( ((__2on1 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__2on1 -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__2on1 -> __O1__4expr.tp ))))->
# 1470 "/home/claude/cfront-3/src/expr2.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;
__1lt = __3f -> returns__3fct ;
if (is_cl_obj__4typeFv ( __1lt ) )continue ;
{ Pptr __3rn ;

# 1474 "/home/claude/cfront-3/src/expr2.cpp"
int __2__X124 ;

# 1473 "/home/claude/cfront-3/src/expr2.cpp"
__3rn = is_ref__4typeFv ( __1lt ) ;
if (__3rn && is_cl_obj__4typeFv ( __3rn -> typ__5pvtyp ) )continue ;

# 1477 "/home/claude/cfront-3/src/expr2.cpp"
if (((skiptypedefs__4typeFv ( __1lt ) -> base__4node == 121 )&& (__1oper >= 126 ))&& (__1oper <= 135 ))
# 1478 "/home/claude/cfront-3/src/expr2.cpp"
continue ;
if (tconst__4typeFv ( __1t1 ) && (! __3f -> f_const__3fct )){ 
# 1480 "/home/claude/cfront-3/src/expr2.cpp"
__1not_const1 = 1 ;
continue ;
}
( ((((unsigned long )(__1lfound + 1 ))< (& __1lconv )-> n__11Block_Pname )|| grow__11Block_PnameFUl ( (& __1lconv ), ((unsigned long )(__1lfound +
# 1483 "/home/claude/cfront-3/src/expr2.cpp"
1 ))) )) ;
((*( (__2__X124 = (__1lfound ++ )), ( (((Pname *)(& ((& __1lconv )-> p__11Block_Pname [__2__X124 ]))))) ) ))= __2on1 ;

# 1484 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1487 "/home/claude/cfront-3/src/expr2.cpp"
if (__1lfound == 0 ){ { __0_result = (__1not_const1 ?-1:0 );

# 1487 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1487 "/home/claude/cfront-3/src/expr2.cpp"

# 1487 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1487 "/home/claude/cfront-3/src/expr2.cpp"
} return __0_result ;
} 
# 1489 "/home/claude/cfront-3/src/expr2.cpp"
{ struct Bits __2b ;

# 1490 "/home/claude/cfront-3/src/expr2.cpp"
struct Block_Bits_chunk *__0__X36 ;

# 1490 "/home/claude/cfront-3/src/expr2.cpp"
const struct Bits *__1__X125 ;

# 1490 "/home/claude/cfront-3/src/expr2.cpp"
register struct Block_Bits_chunk *__0__X119 ;

# 1490 "/home/claude/cfront-3/src/expr2.cpp"
const struct Block_Bits_chunk *__2__X120 ;

# 1490 "/home/claude/cfront-3/src/expr2.cpp"
const struct Bits *__1__X126 ;

# 1489 "/home/claude/cfront-3/src/expr2.cpp"
__ct__4BitsFUlT1 ( & __2b , (unsigned long )0 , (unsigned long )__1lfound ) ;
if (__1lfound == 1 ){ { 
# 1490 "/home/claude/cfront-3/src/expr2.cpp"
struct Bits __0__R117 ;

# 1490 "/home/claude/cfront-3/src/expr2.cpp"
( (__1__X125 = (const struct Bits *)( __co__FRC4Bits ( & __0__R117 , (const struct Bits *)(& __2b )) , (&
# 1490 "/home/claude/cfront-3/src/expr2.cpp"
__0__R117 )) ), ( ( ( ((*( (__0__X119 = (& (& __2b )-> b__4Bits )), ( (__2__X120 = (const
# 1490 "/home/claude/cfront-3/src/expr2.cpp"
struct Block_Bits_chunk *)(& ((*__1__X125 )). b__4Bits )), ( __dl__FPv ( (void *)__0__X119 -> p__16Block_Bits_chunk ) , ( copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X119 , __2__X120 )
# 1490 "/home/claude/cfront-3/src/expr2.cpp"
, (((struct Block_Bits_chunk *)__0__X119 ))) ) ) ) )), ((& __2b )-> n__4Bits = ((*__1__X125 )). n__4Bits )) , ((*(&
# 1490 "/home/claude/cfront-3/src/expr2.cpp"
__2b )))) , (((struct Bits *)(& __2b )))) ) ;

# 1490 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __0__R117 )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv (
# 1490 "/home/claude/cfront-3/src/expr2.cpp"
(void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 1490 "/home/claude/cfront-3/src/expr2.cpp"
))))) ;
} } else { { 
# 1491 "/home/claude/cfront-3/src/expr2.cpp"
struct Bits __0__R121 ;

# 1491 "/home/claude/cfront-3/src/expr2.cpp"
( (__1__X126 = (const struct Bits *)( best_conv__FRC11Block_PnameRiUc ( & __0__R121 , (const struct Block_Pname *)(& __1lconv ), (int *)(&
# 1491 "/home/claude/cfront-3/src/expr2.cpp"
__1lfound ), (unsigned char )const_obj1 ) , (& __0__R121 )) ), ( ( ( ((*( (__0__X119 = (&
# 1491 "/home/claude/cfront-3/src/expr2.cpp"
(& __2b )-> b__4Bits )), ( (__2__X120 = (const struct Block_Bits_chunk *)(& ((*__1__X126 )). b__4Bits )), ( __dl__FPv ( (void *)__0__X119 ->
# 1491 "/home/claude/cfront-3/src/expr2.cpp"
p__16Block_Bits_chunk ) , ( copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X119 , __2__X120 ) , (((struct Block_Bits_chunk *)__0__X119 ))) ) ) ) )), ((&
# 1491 "/home/claude/cfront-3/src/expr2.cpp"
__2b )-> n__4Bits = ((*__1__X126 )). n__4Bits )) , ((*(& __2b )))) , (((struct Bits *)(& __2b )))) ) ;

# 1491 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __0__R121 )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv (
# 1491 "/home/claude/cfront-3/src/expr2.cpp"
(void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 1491 "/home/claude/cfront-3/src/expr2.cpp"
))))) ;
} } 
# 1494 "/home/claude/cfront-3/src/expr2.cpp"
while (count__4BitsCFv ( (const struct Bits *)(& __2b )) ){ 
# 1495 "/home/claude/cfront-3/src/expr2.cpp"
int __3i ;

# 1496 "/home/claude/cfront-3/src/expr2.cpp"
struct Block_Bits_chunk *__0__X32 ;

# 1496 "/home/claude/cfront-3/src/expr2.cpp"
int __2__X33 ;

# 1495 "/home/claude/cfront-3/src/expr2.cpp"
__3i = (signif__4BitsCFv ( (const struct Bits *)(& __2b )) - 1 );
( ((((unsigned long )__3i )< (& __2b )-> n__4Bits )?(((*( (__0__X32 = (& (& __2b )-> b__4Bits )), ( (__2__X33 =
# 1496 "/home/claude/cfront-3/src/expr2.cpp"
( (((unsigned long )__3i )>> 5)) ), ( (((Bits_chunk *)(& (__0__X32 -> p__16Block_Bits_chunk [__2__X33 ]))))) ) ) ))&= (~
# 1496 "/home/claude/cfront-3/src/expr2.cpp"
((((unsigned long )1 ))<< (((unsigned long )__3i )& 31)))):0 ), (((struct Bits *)(& __2b )))) ;
{ Pfct __3f ;

# 1498 "/home/claude/cfront-3/src/expr2.cpp"
register struct name *__0__X129 ;

# 1497 "/home/claude/cfront-3/src/expr2.cpp"
__3f = ( (__0__X129 = ((*( (((Pname *)(& ((& __1lconv )-> p__11Block_Pname [__3i ]))))) ))), ( ((__0__X129 -> __O1__4expr.tp -> base__4node == 108 )?(((struct
# 1497 "/home/claude/cfront-3/src/expr2.cpp"
fct *)(((struct fct *)__0__X129 -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__0__X129 -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ) ;
__1lt = __3f -> returns__3fct ;
{ Pptr __3rr ;

# 1499 "/home/claude/cfront-3/src/expr2.cpp"
__3rr = is_ref__4typeFv ( __1lt ) ;
if (__3rr )__1lt = __3rr -> typ__5pvtyp ;
if (__1lt -> base__4node == 76 )
# 1502 "/home/claude/cfront-3/src/expr2.cpp"
__1lt = (((struct gen *)(((struct gen *)__1lt ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ;
{ int __3r1 ;

# 1503 "/home/claude/cfront-3/src/expr2.cpp"
__3r1 = kind__4typeFUcN21 ( __1lt , __1oper , (unsigned char )0 , (unsigned char )0 ) ;

# 1505 "/home/claude/cfront-3/src/expr2.cpp"
if (__1c2 ){ 
# 1506 "/home/claude/cfront-3/src/expr2.cpp"
__1not_const2 = 0 ;
__1rfound = 0 ;
{ { Pname __4on2 ;

# 1508 "/home/claude/cfront-3/src/expr2.cpp"
__4on2 = __1c2 -> conv__8classdef ;

# 1508 "/home/claude/cfront-3/src/expr2.cpp"
for(;__4on2 ;__4on2 = __4on2 -> __O1__4name.n_list ) { 
# 1509 "/home/claude/cfront-3/src/expr2.cpp"
Pfct __5f ;

# 1509 "/home/claude/cfront-3/src/expr2.cpp"
__5f = ( ((__4on2 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__4on2 -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__4on2 -> __O1__4expr.tp ))))->
# 1509 "/home/claude/cfront-3/src/expr2.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;
__1rt = __5f -> returns__3fct ;
{ Pptr __5rn ;

# 1511 "/home/claude/cfront-3/src/expr2.cpp"
__5rn = is_ref__4typeFv ( __1rt ) ;
if (__5rn )__1rt = __5rn -> typ__5pvtyp ;
if (is_cl_obj__4typeFv ( __1rt ) )continue ;
if (__1rt -> base__4node == 76 )
# 1515 "/home/claude/cfront-3/src/expr2.cpp"
__1rt = (((struct gen *)(((struct gen *)__1rt ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ;
{ int __5r2 ;

# 1516 "/home/claude/cfront-3/src/expr2.cpp"
__5r2 = kind__4typeFUcN21 ( __1rt , __1oper , (unsigned char )0 , (unsigned char )0 ) ;
if (np_promote__FUcN21P4typeT4N21 ( __1oper , (unsigned char )__3r1 , (unsigned char )__5r2 , __1lt , __1rt , (unsigned char )1 ,
# 1517 "/home/claude/cfront-3/src/expr2.cpp"
(unsigned char )0 ) != (((struct type *)any_type )))
# 1520 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1520 "/home/claude/cfront-3/src/expr2.cpp"
int __2__X127 ;

# 1521 "/home/claude/cfront-3/src/expr2.cpp"
if (tconst__4typeFv ( __1t2 ) && (! __5f -> f_const__3fct )){ 
# 1522 "/home/claude/cfront-3/src/expr2.cpp"
__1not_const2 = 1 ;
continue ;
}
( ((((unsigned long )(__1rfound + 1 ))< (& __1rconv )-> n__11Block_Pname )|| grow__11Block_PnameFUl ( (& __1rconv ), ((unsigned long )(__1rfound +
# 1525 "/home/claude/cfront-3/src/expr2.cpp"
1 ))) )) ;
((*( (__2__X127 = (__1rfound ++ )), ( (((Pname *)(& ((& __1rconv )-> p__11Block_Pname [__2__X127 ]))))) ) ))= __4on2 ;
}

# 1527 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1527 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1530 "/home/claude/cfront-3/src/expr2.cpp"
if (__1rfound == 0 ){ 
# 1533 "/home/claude/cfront-3/src/expr2.cpp"
continue ;
}
if (__1rfound == 1 ){ 
# 1536 "/home/claude/cfront-3/src/expr2.cpp"
if (Lcoerce ){ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (&
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
__2b )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 ))))
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
)):(((void )0 )))) ) , (((void )0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
} 
# 1536 "/home/claude/cfront-3/src/expr2.cpp"
return 2 ;
} Lcoerce = ((*( (((Pname *)(& ((& __1lconv )-> p__11Block_Pname [__3i ]))))) ));

# 1537 "/home/claude/cfront-3/src/expr2.cpp"
Rcoerce = ((*( (((Pname *)(& ((& __1rconv )-> p__11Block_Pname [0 ]))))) ));
continue ;
}
{ struct Bits __4b2 ;

# 1541 "/home/claude/cfront-3/src/expr2.cpp"
struct Block_Bits_chunk *__0__X36 ;

# 1540 "/home/claude/cfront-3/src/expr2.cpp"
best_conv__FRC11Block_PnameRiUc ( & __4b2 , (const struct Block_Pname *)(& __1rconv ), (int *)(& __1rfound ), (unsigned char )const_obj2 ) ;
# 1540 "/home/claude/cfront-3/src/expr2.cpp"

# 1541 "/home/claude/cfront-3/src/expr2.cpp"
if (__1rfound == 1 ){ 
# 1541 "/home/claude/cfront-3/src/expr2.cpp"
int __2__X128 ;

# 1542 "/home/claude/cfront-3/src/expr2.cpp"
if (Lcoerce ){ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __4b2 )-> b__4Bits )), (
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
(__0__X36 ?(((void )( __dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) )
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
, (((void )0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __2b )-> b__4Bits )), ( (__0__X36 ?(((void )(
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
__dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
)0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
} } 
# 1542 "/home/claude/cfront-3/src/expr2.cpp"
return 2 ;
} Lcoerce = ((*( (((Pname *)(& ((& __1lconv )-> p__11Block_Pname [__3i ]))))) ));
Rcoerce = ((*( (__2__X128 = (signif__4BitsCFv ( (const struct Bits *)(& __4b2 )) - 1 )), ( (((Pname *)(& ((& __1rconv )->
# 1544 "/home/claude/cfront-3/src/expr2.cpp"
p__11Block_Pname [__2__X128 ]))))) ) ));
}
else 
# 1547 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1548 "/home/claude/cfront-3/src/expr2.cpp"
if (__1lfound > 1 ){ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (&
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
__4b2 )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 ))))
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
)):(((void )0 )))) ) , (((void )0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __2b )-> b__4Bits )), ( (__0__X36 ?(((void )(
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
__dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
)0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
} } 
# 1548 "/home/claude/cfront-3/src/expr2.cpp"
return 4 ;
} { 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __4b2 )-> b__4Bits )), (
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
(__0__X36 ?(((void )( __dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) )
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
, (((void )0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __2b )-> b__4Bits )), ( (__0__X36 ?(((void )(
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
__dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
)0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
} } 
# 1549 "/home/claude/cfront-3/src/expr2.cpp"
return 3 ;
} }

# 1550 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __4b2 )-> b__4Bits )), ( (__0__X36 ?(((void )(
# 1550 "/home/claude/cfront-3/src/expr2.cpp"
__dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 1550 "/home/claude/cfront-3/src/expr2.cpp"
)0 ))) ))))) ;

# 1550 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1550 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1550 "/home/claude/cfront-3/src/expr2.cpp"
}
}
else if (__1rt ){ 
# 1553 "/home/claude/cfront-3/src/expr2.cpp"
if (__1rt -> base__4node == 76 )
# 1554 "/home/claude/cfront-3/src/expr2.cpp"
__1rt = (((struct gen *)(((struct gen *)__1rt ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ;
{ int __4r2 ;

# 1555 "/home/claude/cfront-3/src/expr2.cpp"
__4r2 = kind__4typeFUcN21 ( __1rt , __1oper , (unsigned char )0 , (unsigned char )0 ) ;
if (np_promote__FUcN21P4typeT4N21 ( __1oper , (unsigned char )__3r1 , (unsigned char )__4r2 , __1lt , __1rt , (unsigned char )1 ,
# 1556 "/home/claude/cfront-3/src/expr2.cpp"
(unsigned char )0 ) != (((struct type *)any_type )))
# 1559 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1560 "/home/claude/cfront-3/src/expr2.cpp"
if (Lcoerce ){ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( (
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
(__0__X36 = (& (& __2b )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
)(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
} 
# 1560 "/home/claude/cfront-3/src/expr2.cpp"
return 2 ;
} Lcoerce = ((*( (((Pname *)(& ((& __1lconv )-> p__11Block_Pname [__3i ]))))) ));
if (count__4BitsCFv ( (const struct Bits *)(& __2b )) == 0 ){ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( (
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
(__0__X36 = (& (& __2b )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
)(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
} 
# 1562 "/home/claude/cfront-3/src/expr2.cpp"
return 1 ;
} }

# 1563 "/home/claude/cfront-3/src/expr2.cpp"
}
}
else { 
# 1565 "/home/claude/cfront-3/src/expr2.cpp"
struct type *__1__Xt00an55jxojwcog ;

# 1566 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1oper == 50 )&& (__3r1 != 'P' ))continue ;
if ((__1oper == 109 )&& (! ( (__1__Xt00an55jxojwcog = skiptypedefs__4typeFv ( __1lt ) ), ( ((__1__Xt00an55jxojwcog -> base__4node == 125 )?( (__1__Xt00an55jxojwcog =
# 1567 "/home/claude/cfront-3/src/expr2.cpp"
skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__1__Xt00an55jxojwcog ))))-> typ__5pvtyp ) ), 0 ) :0 ), (((unsigned char )((__1__Xt00an55jxojwcog -> base__4node == ((unsigned char
# 1567 "/home/claude/cfront-3/src/expr2.cpp"
)108 ))?1 :0 )))) ) ))
# 1568 "/home/claude/cfront-3/src/expr2.cpp"
continue ;
if ((skiptypedefs__4typeFv ( __1lt ) -> base__4node == 121 )&& ((__1oper == 48 )|| (__1oper == 49 )))
# 1573 "/home/claude/cfront-3/src/expr2.cpp"
continue ;

# 1575 "/home/claude/cfront-3/src/expr2.cpp"
if (Lcoerce ){ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __2b )-> b__4Bits )), (
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
(__0__X36 ?(((void )( __dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) )
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
, (((void )0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
} 
# 1575 "/home/claude/cfront-3/src/expr2.cpp"
return 2 ;
} Lcoerce = ((*( (((Pname *)(& ((& __1lconv )-> p__11Block_Pname [__3i ]))))) ));
if (count__4BitsCFv ( (const struct Bits *)(& __2b )) == 0 ){ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( (
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
(__0__X36 = (& (& __2b )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
)(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
} 
# 1577 "/home/claude/cfront-3/src/expr2.cpp"
return 1 ;
} }

# 1578 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1578 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1578 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1581 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __2b )-> b__4Bits )), (
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
(__0__X36 ?(((void )( __dl__FPv ( (void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) )
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
, (((void )0 ))) ))))) ;

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"

# 1626 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1626 "/home/claude/cfront-3/src/expr2.cpp"
} 
# 1581 "/home/claude/cfront-3/src/expr2.cpp"
return (Lcoerce || Rcoerce );
} 
# 1581 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1581 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1581 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1585 "/home/claude/cfront-3/src/expr2.cpp"
__1not_const2 = 0 ;
{ { Pname __1on ;

# 1586 "/home/claude/cfront-3/src/expr2.cpp"
__1on = __1c2 -> conv__8classdef ;

# 1586 "/home/claude/cfront-3/src/expr2.cpp"
for(;__1on ;__1on = __1on -> __O1__4name.n_list ) { 
# 1587 "/home/claude/cfront-3/src/expr2.cpp"
Pfct __2f ;

# 1587 "/home/claude/cfront-3/src/expr2.cpp"
__2f = ( ((__1on -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1on -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__1on -> __O1__4expr.tp ))))->
# 1587 "/home/claude/cfront-3/src/expr2.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;
__1rt = __2f -> returns__3fct ;
{ Pptr __2rn ;

# 1589 "/home/claude/cfront-3/src/expr2.cpp"
__2rn = is_ref__4typeFv ( __1rt ) ;
if (__2rn )__1rt = __2rn -> typ__5pvtyp ;
if (is_cl_obj__4typeFv ( __1rt ) )continue ;
if (tconst__4typeFv ( __1t2 ) && (! __2f -> f_const__3fct )){ 
# 1593 "/home/claude/cfront-3/src/expr2.cpp"
__1not_const2 = 1 ;
continue ;
}
if (__1rt -> base__4node == 76 )
# 1597 "/home/claude/cfront-3/src/expr2.cpp"
__1rt = (((struct gen *)(((struct gen *)__1rt ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ;
{ int __2r2 ;

# 1598 "/home/claude/cfront-3/src/expr2.cpp"
__2r2 = kind__4typeFUcN21 ( __1rt , __1oper , (unsigned char )0 , (unsigned char )0 ) ;

# 1600 "/home/claude/cfront-3/src/expr2.cpp"
if (__1lt ){ 
# 1601 "/home/claude/cfront-3/src/expr2.cpp"
if (__1lt -> base__4node == 76 )
# 1602 "/home/claude/cfront-3/src/expr2.cpp"
__1lt = (((struct gen *)(((struct gen *)__1lt ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ;
{ int __3r1 ;

# 1603 "/home/claude/cfront-3/src/expr2.cpp"
__3r1 = kind__4typeFUcN21 ( __1lt , __1oper , (unsigned char )0 , (unsigned char )0 ) ;

# 1605 "/home/claude/cfront-3/src/expr2.cpp"
if (np_promote__FUcN21P4typeT4N21 ( __1oper , (unsigned char )__3r1 , (unsigned char )__2r2 , __1lt , __1rt , (unsigned char )1 ,
# 1605 "/home/claude/cfront-3/src/expr2.cpp"
(unsigned char )0 ) != (((struct type *)any_type ))){ 
# 1605 "/home/claude/cfront-3/src/expr2.cpp"
int __2__X130 ;

# 1606 "/home/claude/cfront-3/src/expr2.cpp"
( ((((unsigned long )(__1rfound + 1 ))< (& __1rconv )-> n__11Block_Pname )|| grow__11Block_PnameFUl ( (& __1rconv ), ((unsigned long )(__1rfound +
# 1606 "/home/claude/cfront-3/src/expr2.cpp"
1 ))) )) ;
((*( (__2__X130 = (__1rfound ++ )), ( (((Pname *)(& ((& __1rconv )-> p__11Block_Pname [__2__X130 ]))))) ) ))= __1on ;
}

# 1608 "/home/claude/cfront-3/src/expr2.cpp"
}
}
else { 
# 1611 "/home/claude/cfront-3/src/expr2.cpp"
if (oper_okay__FP4typeUc ( __1rt , __1oper ) ){ 
# 1611 "/home/claude/cfront-3/src/expr2.cpp"
int __2__X131 ;

# 1612 "/home/claude/cfront-3/src/expr2.cpp"
( ((((unsigned long )(__1rfound + 1 ))< (& __1rconv )-> n__11Block_Pname )|| grow__11Block_PnameFUl ( (& __1rconv ), ((unsigned long )(__1rfound +
# 1612 "/home/claude/cfront-3/src/expr2.cpp"
1 ))) )) ;
((*( (__2__X131 = (__1rfound ++ )), ( (((Pname *)(& ((& __1rconv )-> p__11Block_Pname [__2__X131 ]))))) ) ))= __1on ;
}
}

# 1615 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1615 "/home/claude/cfront-3/src/expr2.cpp"
}
}
if ((__1rfound == 0 )&& __1not_const2 ){ 
# 1617 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void
# 1617 "/home/claude/cfront-3/src/expr2.cpp"
)(((void )0 ))))) ))) ;

# 1617 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1617 "/home/claude/cfront-3/src/expr2.cpp"
return -2;
} if (__1rfound == 1 )Rcoerce = ((*( (((Pname *)(& ((& __1rconv )-> p__11Block_Pname [0 ]))))) ));
if (__1rfound > 1 ){ 
# 1620 "/home/claude/cfront-3/src/expr2.cpp"
struct Bits __2b ;

# 1621 "/home/claude/cfront-3/src/expr2.cpp"
struct Block_Bits_chunk *__0__X36 ;

# 1621 "/home/claude/cfront-3/src/expr2.cpp"
int __2__X132 ;

# 1620 "/home/claude/cfront-3/src/expr2.cpp"
best_conv__FRC11Block_PnameRiUc ( & __2b , (const struct Block_Pname *)(& __1rconv ), (int *)(& __1rfound ), (unsigned char )const_obj2 ) ;
# 1620 "/home/claude/cfront-3/src/expr2.cpp"

# 1621 "/home/claude/cfront-3/src/expr2.cpp"
Rcoerce = ((*( (__2__X132 = (signif__4BitsCFv ( (const struct Bits *)(& __2b )) - 1 )), ( (((Pname *)(& ((& __1rconv )->
# 1621 "/home/claude/cfront-3/src/expr2.cpp"
p__11Block_Pname [__2__X132 ]))))) ) ));

# 1621 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __2b )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv (
# 1621 "/home/claude/cfront-3/src/expr2.cpp"
(void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 1621 "/home/claude/cfront-3/src/expr2.cpp"
))))) ;
}
if (__1rfound > 1 ){ 
# 1623 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void
# 1623 "/home/claude/cfront-3/src/expr2.cpp"
)0 ))))) ))) ;

# 1623 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1623 "/home/claude/cfront-3/src/expr2.cpp"
return 3 ;
} 
# 1625 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1625 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1lconv )-> p__11Block_Pname ) , (((void )(((void )0 )))))
# 1625 "/home/claude/cfront-3/src/expr2.cpp"
))) ;

# 1625 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rconv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 1625 "/home/claude/cfront-3/src/expr2.cpp"
return (Lcoerce || Rcoerce );
} 
# 1625 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1625 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1625 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 1628 "/home/claude/cfront-3/src/expr2.cpp"
static void opov_error__FP4typeT1Uc (Ptype __1t1 , Ptype __1t2 , TOK __1op )
# 1629 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1630 "/home/claude/cfront-3/src/expr2.cpp"
if (__1t1 && __1t2 ){ 
# 1631 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1631 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V133 ;

# 1631 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V134 ;

# 1631 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V135 ;

# 1631 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V136 ;

# 1631 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"ambiguous call of operator%k:%t%k%t", (const struct ea *)( ((
# 1631 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V133 )-> __O1__2ea.i = ((unsigned long )__1op )), 0 ) ), (& __0__V133 )) , (const struct ea *)(
# 1631 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V134 )-> __O1__2ea.p = ((const void *)__1t1 )), (& __0__V134 )) , (const struct ea *)( (( ((&
# 1631 "/home/claude/cfront-3/src/expr2.cpp"
__0__V135 )-> __O1__2ea.i = ((unsigned long )__1op )), 0 ) ), (& __0__V135 )) , (const struct ea *)( ((&
# 1631 "/home/claude/cfront-3/src/expr2.cpp"
__0__V136 )-> __O1__2ea.p = ((const void *)__1t2 )), (& __0__V136 )) ) ;
} }
else { 
# 1634 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __2tmp ;

# 1634 "/home/claude/cfront-3/src/expr2.cpp"
__2tmp = (__1t1 ?__1t1 :__1t2 );
{ 
# 1635 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V137 ;

# 1635 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V138 ;

# 1635 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V139 ;

# 1635 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"ambiguous call of operator%k:%k%t", (const struct ea *)( ((
# 1635 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V137 )-> __O1__2ea.i = ((unsigned long )__1op )), 0 ) ), (& __0__V137 )) , (const struct ea *)(
# 1635 "/home/claude/cfront-3/src/expr2.cpp"
(( ((& __0__V138 )-> __O1__2ea.i = ((unsigned long )__1op )), 0 ) ), (& __0__V138 )) , (const struct
# 1635 "/home/claude/cfront-3/src/expr2.cpp"
ea *)( ((& __0__V139 )-> __O1__2ea.p = ((const void *)__2tmp )), (& __0__V139 )) , (const struct ea *)ea0 ) ;
# 1635 "/home/claude/cfront-3/src/expr2.cpp"
} 
# 1636 "/home/claude/cfront-3/src/expr2.cpp"
}
{ 
# 1637 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V140 ;

# 1637 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)" (conflicts with built-in operator%k)\n", (const struct ea *)( ((
# 1637 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V140 )-> __O1__2ea.i = ((unsigned long )__1op )), 0 ) ), (& __0__V140 )) , (const struct ea *)ea0 ,
# 1637 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1640 "/home/claude/cfront-3/src/expr2.cpp"
int non_const = 0 ;

# 1156 "/home/claude/cfront-3/src/cfront.h"
extern bit can_coerce__FP4typeT1 (Ptype , Ptype );

# 1642 "/home/claude/cfront-3/src/expr2.cpp"
static int id_match__FP4exprP3fctP8classdefi (Pexpr __1th , Pfct __1f , Pclass __1cl , int __1anac )
# 1643 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1644 "/home/claude/cfront-3/src/expr2.cpp"
Pname __1n ;
int __1ok ;

# 1644 "/home/claude/cfront-3/src/expr2.cpp"
__1n = __1f -> argtype__3fct ;
__1ok = 0 ;

# 1647 "/home/claude/cfront-3/src/expr2.cpp"
if (((! __1anac )&& __1th -> __O2__4expr.e1 )&& (((__1cl && __1n )&& (! __1n -> __O1__4name.n_list ))|| (((! __1cl )&& __1n )&& __1n ->
# 1647 "/home/claude/cfront-3/src/expr2.cpp"
__O1__4name.n_list )))
# 1648 "/home/claude/cfront-3/src/expr2.cpp"
__1ok = 1 ;

# 1650 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1anac && __1th -> __O2__4expr.e1 )&& ((__1cl && (! __1n ))|| (((! __1cl )&& __1n )&& (! __1n -> __O1__4name.n_list ))))
# 1651 "/home/claude/cfront-3/src/expr2.cpp"
__1ok = 1 ;
# 1651 "/home/claude/cfront-3/src/expr2.cpp"

# 1653 "/home/claude/cfront-3/src/expr2.cpp"
if (__1th -> __O3__4expr.e2 && ((__1cl && (! __1n ))|| (((! __1cl )&& __1n )&& (! __1n -> __O1__4name.n_list ))))
# 1654 "/home/claude/cfront-3/src/expr2.cpp"
__1ok = 1 ;

# 1656 "/home/claude/cfront-3/src/expr2.cpp"
if (__1ok && (! __1cl )){ 
# 1657 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __2t ;
if (__1th -> __O2__4expr.e1 )
# 1659 "/home/claude/cfront-3/src/expr2.cpp"
__2t = __1th -> __O2__4expr.e1 -> __O1__4expr.tp ;
else if ((__1th -> __O3__4expr.e2 -> base__4node == 140 )&& (! __1th -> __O3__4expr.e2 -> __O1__4expr.tp ))
# 1661 "/home/claude/cfront-3/src/expr2.cpp"
__2t = __1th -> __O3__4expr.e2 -> __O2__4expr.e1 -> __O1__4expr.tp ;
# 1661 "/home/claude/cfront-3/src/expr2.cpp"
else 
# 1663 "/home/claude/cfront-3/src/expr2.cpp"
__2t = __1th -> __O3__4expr.e2 -> __O1__4expr.tp ;
__1ok = can_coerce__FP4typeT1 ( __1n -> __O1__4expr.tp , __2t ) ;
}

# 1667 "/home/claude/cfront-3/src/expr2.cpp"
return __1ok ;
}

# 120 "/home/claude/cfront-3/src/cfront.h"
extern const char *oper_name__FUc (TOK );

# 473 "/home/claude/cfront-3/src/cfront.h"
Pexpr find_name__8classdefFPCcP8classdefiT3 (struct classdef *__0this , const char *, Pclass , int , int );

# 1670 "/home/claude/cfront-3/src/expr2.cpp"
static Pexpr id_overload__FP4exprP8classdefi (Pexpr __1th , Pclass __1cl , int __1anac )
# 1671 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1672 "/home/claude/cfront-3/src/expr2.cpp"
const char *__1on ;
Pexpr __1e ;

# 1672 "/home/claude/cfront-3/src/expr2.cpp"
__1on = oper_name__FUc ( __1th -> base__4node ) ;

# 1675 "/home/claude/cfront-3/src/expr2.cpp"
if (__1cl )
# 1676 "/home/claude/cfront-3/src/expr2.cpp"
__1e = find_name__8classdefFPCcP8classdefiT3 ( __1cl , __1on , (struct classdef *)0 , 0 , 0 ) ;
else 
# 1678 "/home/claude/cfront-3/src/expr2.cpp"
__1e = (struct expr *)look__5tableFPCcUc ( gtbl , __1on , (unsigned char )0 ) ;

# 1680 "/home/claude/cfront-3/src/expr2.cpp"
if ((! __1e )|| (! __1e -> __O1__4expr.tp ))
# 1681 "/home/claude/cfront-3/src/expr2.cpp"
return (struct expr *)0 ;

# 1683 "/home/claude/cfront-3/src/expr2.cpp"
if (__1e -> __O1__4expr.tp -> base__4node == 108 ){ 
# 1684 "/home/claude/cfront-3/src/expr2.cpp"
if (id_match__FP4exprP3fctP8classdefi ( __1th , ((struct fct *)(((struct fct *)__1e -> __O1__4expr.tp ))), __1cl , __1anac )
# 1684 "/home/claude/cfront-3/src/expr2.cpp"
)
# 1685 "/home/claude/cfront-3/src/expr2.cpp"
return __1e ;
}
else { 
# 1688 "/home/claude/cfront-3/src/expr2.cpp"
{ { Plist __2gl ;

# 1688 "/home/claude/cfront-3/src/expr2.cpp"
__2gl = (((struct gen *)(((struct gen *)__1e -> __O1__4expr.tp ))))-> fct_list__3gen ;

# 1688 "/home/claude/cfront-3/src/expr2.cpp"
for(;__2gl ;__2gl = __2gl -> l__9name_list ) 
# 1689 "/home/claude/cfront-3/src/expr2.cpp"
if (id_match__FP4exprP3fctP8classdefi ( __1th , ((struct fct *)(((struct fct *)__2gl -> f__9name_list -> __O1__4expr.tp ))), __1cl , __1anac ) )
# 1690 "/home/claude/cfront-3/src/expr2.cpp"
return
# 1690 "/home/claude/cfront-3/src/expr2.cpp"
(struct expr *)__2gl -> f__9name_list ;

# 1690 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1690 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1693 "/home/claude/cfront-3/src/expr2.cpp"
return (struct expr *)0 ;
}

# 808 "/home/claude/cfront-3/src/cfront.h"
bit is_const_obj__4exprFv (struct expr *__0this );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 46 "/home/claude/cfront-3/src/overload.h"
extern int matchable__FP4nameP4expri (Pname , Pexpr , int );

# 673 "/home/claude/cfront-3/src/cfront.h"
Pname multArgMatch__3genFP4expri (struct gen *__0this , Pexpr , int );

# 672 "/home/claude/cfront-3/src/cfront.h"
Pname oneArgMatch__3genFP4expri (struct gen *__0this , Pexpr , int );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 460 "/home/claude/cfront-3/src/cfront.h"
bit has_base__8classdefFP8classdefiT2 (struct classdef *__0this , Pclass __1cl , int __1level , int __1ccflag );

# 1232 "/home/claude/cfront-3/src/cfront.h"
extern int make_assignment__FP4name (Pname );

# 1696 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr oper_overload__4exprFP5table (struct expr *__0this , Ptable __1tbl );

# 671 "/home/claude/cfront-3/src/cfront.h"
Pname exactMatch__3genFP4expri (struct gen *__0this , Pexpr , int );

# 674 "/home/claude/cfront-3/src/cfront.h"

# 952 "/home/claude/cfront-3/src/cfront.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 633 "/home/claude/cfront-3/src/cfront.h"
struct fct *__ct__3fctFP4typeP4nameUc (struct fct *__0this , Ptype , Pname , TOK );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 667 "/home/claude/cfront-3/src/cfront.h"
static struct gen *__ct__3genFv (struct gen *__0this ){ 
# 667 "/home/claude/cfront-3/src/cfront.h"
struct type *__0__X5 ;

# 667 "/home/claude/cfront-3/src/cfront.h"
struct node *__0__X1 ;

# 667 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct gen *)__nw__FUl ( (size_t )(sizeof (struct gen))) )){ ( ( (__0this = (struct
# 667 "/home/claude/cfront-3/src/cfront.h"
gen *)( (__0__X5 = (((struct type *)__0this ))), ( ((__0__X5 || (__0__X5 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type))) ))?(
# 667 "/home/claude/cfront-3/src/cfront.h"
( ( ( ( ( ( ( (__0__X5 = (struct type *)( (__0__X1 = (((struct node *)__0__X5 ))), (
# 667 "/home/claude/cfront-3/src/cfront.h"
((__0__X1 || (__0__X1 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 ->
# 667 "/home/claude/cfront-3/src/cfront.h"
permanent__4node = 0 )) , (__0__X1 -> baseclass__4node = 0 )) :0 ), __0__X1 ) ) ), (__0__X5 -> defined__4type = 0 )) ,
# 667 "/home/claude/cfront-3/src/cfront.h"
(__0__X5 -> lex_level__4type = 0 )) , (__0__X5 -> templ_base__4type = 0)) , (__0__X5 -> in_class__4type = 0 )) , (__0__X5 -> nested_sig__4type =
# 667 "/home/claude/cfront-3/src/cfront.h"
0 )) , (__0__X5 -> local_sig__4type = 0 )) , (__0__X5 -> b_const__4type = 0 )) , (__0__X5 -> ansi_const__4type = 0 )) :0 ),
# 667 "/home/claude/cfront-3/src/cfront.h"
__0__X5 ) ) ), (__0this -> fct_list__3gen = 0 )) , (__0this -> holds_templ__3gen = 0)) ;

# 667 "/home/claude/cfront-3/src/cfront.h"
__0this -> base__4node = 76 ;
} 
# 667 "/home/claude/cfront-3/src/cfront.h"
return __0this ;

# 667 "/home/claude/cfront-3/src/cfront.h"
}

# 657 "/home/claude/cfront-3/src/cfront.h"
struct name_list *__ct__9name_listFP4nameP9name_list (struct name_list *__0this , Pname __1ff , Plist __1ll );

# 362 "/home/claude/cfront-3/src/cfront.h"
void del__4typeFv (struct type *__0this );

# 29 "/home/claude/cfront-3/src/expr2.cpp"
static Pname compare_builtin__FP4typeT1P4nameN23i (Ptype , Ptype , Pname , Pname , Pname , int );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 674 "/home/claude/cfront-3/src/cfront.h"

# 952 "/home/claude/cfront-3/src/cfront.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 45 "/home/claude/cfront-3/src/overload.h"
extern Pname bestOfPair__FP4nameT1P4type (Pname , Pname , Ptype );

# 39 "/home/claude/cfront-3/src/overload.h"

# 49 "/home/claude/cfront-3/src/overload.h"
extern void fmError__FiRC11Block_PnameP4exprUc (int , const struct Block_Pname *, Pexpr , bit );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 674 "/home/claude/cfront-3/src/cfront.h"

# 952 "/home/claude/cfront-3/src/cfront.h"

# 740 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr check_cond__FP4exprUcP5table (Pexpr , TOK , Ptable );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 667 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 1696 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr oper_overload__4exprFP5table (register struct expr *__0this , Ptable __1tbl )
# 1697 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1698 "/home/claude/cfront-3/src/expr2.cpp"
Pname __1n1 ;
Ptype __1t1 ;

# 1698 "/home/claude/cfront-3/src/expr2.cpp"
__1n1 = 0 ;
__1t1 = 0 ;
const_obj1 = 0 ;
const_obj2 = 0 ;
{ int __1const_obj ;
bit __1already_ambig ;

# 1702 "/home/claude/cfront-3/src/expr2.cpp"
__1const_obj = 0 ;
__1already_ambig = 0 ;

# 1705 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> __O2__4expr.e1 ){ 
# 1706 "/home/claude/cfront-3/src/expr2.cpp"
__1t1 = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
{ Ptype __2tpx ;

# 1707 "/home/claude/cfront-3/src/expr2.cpp"
__2tpx = skiptypedefs__4typeFv ( __1t1 ) ;
__1n1 = is_cl_obj__4typeFv ( __2tpx ) ;
const_obj1 = (tconst__4typeFv ( __1t1 ) ?(((unsigned int )1 )):(((unsigned int )is_const_obj__4exprFv ( __0this -> __O2__4expr.e1 ) )));

# 1709 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1712 "/home/claude/cfront-3/src/expr2.cpp"
{ TOK __1bb ;

# 1712 "/home/claude/cfront-3/src/expr2.cpp"
__1bb = __0this -> base__4node ;
switch (__1bb ){ 
# 1714 "/home/claude/cfront-3/src/expr2.cpp"
case 111 :
# 1715 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> __O3__4expr.e2 == 0 )__1bb = 50 ;

# 1717 "/home/claude/cfront-3/src/expr2.cpp"
case 109 :
# 1718 "/home/claude/cfront-3/src/expr2.cpp"
case 146 :
# 1719 "/home/claude/cfront-3/src/expr2.cpp"
if (__1n1 == 0 )return (struct expr *)0 ;
}

# 1722 "/home/claude/cfront-3/src/expr2.cpp"
{ Pname __1n2 ;
Ptype __1t2 ;

# 1722 "/home/claude/cfront-3/src/expr2.cpp"
__1n2 = 0 ;
__1t2 = 0 ;

# 1725 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> __O3__4expr.e2 && (__0this -> __O3__4expr.e2 -> base__4node != 140 )){ 
# 1726 "/home/claude/cfront-3/src/expr2.cpp"
__1t2 = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;
{ Ptype __2tpx ;

# 1727 "/home/claude/cfront-3/src/expr2.cpp"
__2tpx = skiptypedefs__4typeFv ( __1t2 ) ;
__1n2 = is_cl_obj__4typeFv ( __2tpx ) ;
const_obj2 = (tconst__4typeFv ( __1t2 ) ?(((unsigned int )1 )):(((unsigned int )is_const_obj__4exprFv ( __0this -> __O3__4expr.e2 ) )));

# 1729 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1732 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1n1 == 0 )&& (__1n2 == 0 ))return (struct expr *)0 ;
if (__1n1 && (__1n1 -> __O1__4expr.tp == 0 ))return (struct expr *)0 ;

# 1735 "/home/claude/cfront-3/src/expr2.cpp"
{ Pname __1Ggn ;
Pexpr __1oe2 ;
Pexpr __1ee2 ;
Pexpr __1ee1 ;
const char *__1obb ;

# 1735 "/home/claude/cfront-3/src/expr2.cpp"
__1Ggn = 0 ;
__1oe2 = __0this -> __O3__4expr.e2 ;
__1ee2 = ((__0this -> __O3__4expr.e2 && (__0this -> __O3__4expr.e2 -> base__4node != 140 ))?(__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 ,
# 1737 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O3__4expr.e2 , (struct expr *)0 ) ):(((struct expr *)0 )));
__1ee1 = (__0this -> __O2__4expr.e1 ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __0this -> __O2__4expr.e1 , __0this -> __O3__4expr.e2 ) :__1ee2 );
__1obb = oper_name__FUc ( __1bb ) ;

# 1741 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1bb == 48 )|| (__1bb == 49 )){ 
# 1742 "/home/claude/cfront-3/src/expr2.cpp"
Pclass __2cl ;
const char *__2on ;
bit __2ismem ;
Pexpr __2e ;
Pexpr __2ee ;
bit __2anac ;

# 1742 "/home/claude/cfront-3/src/expr2.cpp"
__2cl = (((struct classdef *)(((struct classdef *)(__0this -> __O2__4expr.e1 ?__1n1 -> __O1__4expr.tp :__1n2 -> __O1__4expr.tp )))));
__2on = oper_name__FUc ( __1bb ) ;
__2ismem = 1 ;

# 1747 "/home/claude/cfront-3/src/expr2.cpp"
__2anac = 0 ;

# 1749 "/home/claude/cfront-3/src/expr2.cpp"
__2e = id_overload__FP4exprP8classdefi ( __0this , __2cl , 0 ) ;
__2ee = id_overload__FP4exprP8classdefi ( __0this , (struct classdef *)0 , 0 ) ;

# 1752 "/home/claude/cfront-3/src/expr2.cpp"
if (__2e && __2ee )
# 1753 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1753 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V141 ;

# 1753 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V142 ;

# 1753 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V143 ;

# 1753 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous call of operator%k: %a and %a", (const struct ea *)( (( ((& __0__V141 )->
# 1753 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.i = ((unsigned long )__1bb )), 0 ) ), (& __0__V141 )) , (const struct ea *)( ((& __0__V142 )->
# 1753 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.p = ((const void *)__2e )), (& __0__V142 )) , (const struct ea *)( ((& __0__V143 )-> __O1__2ea.p = ((const
# 1753 "/home/claude/cfront-3/src/expr2.cpp"
void *)__2ee )), (& __0__V143 )) , (const struct ea *)ea0 ) ;
} if ((((! __2e )&& (! __2ee ))&& __0this -> __O2__4expr.e1 )&& (! strict_opt )){ 
# 1755 "/home/claude/cfront-3/src/expr2.cpp"
__2e = id_overload__FP4exprP8classdefi ( __0this , __2cl ,
# 1755 "/home/claude/cfront-3/src/expr2.cpp"
1 ) ;
__2ee = id_overload__FP4exprP8classdefi ( __0this , (struct classdef *)0 , 1 ) ;
if (__2e || __2ee ){ 
# 1758 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCc ( (int )'w' , (const char *)"prefix ++/-- used as postfix (anachronism)") ;
# 1758 "/home/claude/cfront-3/src/expr2.cpp"

# 1759 "/home/claude/cfront-3/src/expr2.cpp"
__2anac = 1 ;
}
}
if (! __2e )
# 1763 "/home/claude/cfront-3/src/expr2.cpp"
( (__2ismem = 0 ), (__2e = __2ee )) ;
if (! __2e ){ 
# 1765 "/home/claude/cfront-3/src/expr2.cpp"
if (try_to_demote__FUcP4typeT2 ( __1bb , __1t1 ?__1t1 :__1t2 , (struct type *)0 ) == 1 ){ 
# 1766 "/home/claude/cfront-3/src/expr2.cpp"
Pname __4xx ;
Pref __4r ;

# 1768 "/home/claude/cfront-3/src/expr2.cpp"
struct ref *__0__X159 ;

# 1768 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X160 ;

# 1768 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X161 ;

# 1766 "/home/claude/cfront-3/src/expr2.cpp"
__4xx = __ct__4nameFPCc ( (struct name *)0 , Lcoerce -> __O2__4expr.string ) ;
__4r = ( (__0__X159 = 0 ), ( (__2__X160 = (__0this -> __O2__4expr.e1 ?__0this -> __O2__4expr.e1 :__1oe2 )), ( (__2__X161 = (struct expr *)__4xx ), (
# 1767 "/home/claude/cfront-3/src/expr2.cpp"
((__0__X159 || (__0__X159 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X159 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X159 ),
# 1767 "/home/claude/cfront-3/src/expr2.cpp"
((unsigned char )45 ), __2__X160 , (struct expr *)0 ) ), (__0__X159 -> __O4__4expr.mem = __2__X161 )) :0 ), __0__X159 ) ) )
# 1767 "/home/claude/cfront-3/src/expr2.cpp"
) ;
if (__0this -> __O2__4expr.e1 )
# 1769 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , (struct expr *)__4r , (struct expr *)0 )
# 1769 "/home/claude/cfront-3/src/expr2.cpp"
;
else 
# 1771 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , (struct expr *)__4r , (struct expr *)0 ) ;
# 1771 "/home/claude/cfront-3/src/expr2.cpp"

# 1772 "/home/claude/cfront-3/src/expr2.cpp"
return typ__4exprFP5table ( __0this , __1tbl ) ;
}
else { 
# 1775 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1775 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V144 ;

# 1775 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V145 ;

# 1775 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad operand for%k:%t", (const struct ea *)( (( ((& __0__V144 )->
# 1775 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.i = ((unsigned long )__1bb )), 0 ) ), (& __0__V144 )) , (const struct ea *)( ((& __0__V145 )->
# 1775 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.p = ((const void *)(__1t1 ?__1t1 :__1t2 ))), (& __0__V145 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 1775 "/home/claude/cfront-3/src/expr2.cpp"

# 1776 "/home/claude/cfront-3/src/expr2.cpp"
return __0this ;
} }
}
__0this -> base__4node = (__2ismem ?109 :146 );
if (! __2ismem ){ 
# 1781 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __3eee ;

# 1781 "/home/claude/cfront-3/src/expr2.cpp"
__3eee = 0 ;
if (__0this -> __O2__4expr.e1 && (! __2anac ))
# 1783 "/home/claude/cfront-3/src/expr2.cpp"
__3eee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , (struct expr *)0 )
# 1783 "/home/claude/cfront-3/src/expr2.cpp"
;
__3eee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __0this -> __O2__4expr.e1 ?__0this -> __O2__4expr.e1 :__1oe2 , __3eee ) ;
__0this -> __O2__4expr.e1 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __2on ) ;
(((struct name *)(((struct name *)__0this -> __O2__4expr.e1 ))))-> __O2__4name.n_qualifier = sta_name ;
__0this -> __O3__4expr.e2 = __3eee ;
}
else { 
# 1790 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __3eee ;

# 1791 "/home/claude/cfront-3/src/expr2.cpp"
struct ref *__0__X162 ;

# 1791 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X163 ;

# 1791 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X164 ;

# 1790 "/home/claude/cfront-3/src/expr2.cpp"
__3eee = __0this -> __O2__4expr.e1 ;
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X162 = 0 ), ( (__2__X163 = (__0this -> __O2__4expr.e1 ?__0this -> __O2__4expr.e1 :__1oe2 )), ( (__2__X164 = (struct
# 1791 "/home/claude/cfront-3/src/expr2.cpp"
expr *)__ct__4nameFPCc ( (struct name *)0 , __2on ) ), ( ((__0__X162 || (__0__X162 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref)))
# 1791 "/home/claude/cfront-3/src/expr2.cpp"
))?( (__0__X162 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X162 ), ((unsigned char )45 ), __2__X163 , (struct expr *)0 ) ), (__0__X162 ->
# 1791 "/home/claude/cfront-3/src/expr2.cpp"
__O4__4expr.mem = __2__X164 )) :0 ), __0__X162 ) ) ) ) ;
__0this -> __O3__4expr.e2 = ((__3eee && (! __2anac ))?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , (struct expr *)0 ) :(((struct
# 1792 "/home/claude/cfront-3/src/expr2.cpp"
expr *)0 )));

# 1792 "/home/claude/cfront-3/src/expr2.cpp"
;
}
__2e = typ__4exprFP5table ( __0this , __1tbl ) ;
if (! __2e )
# 1796 "/home/claude/cfront-3/src/expr2.cpp"
return __2e ;

# 1804 "/home/claude/cfront-3/src/expr2.cpp"
return __2e ;
}

# 1808 "/home/claude/cfront-3/src/expr2.cpp"
{ Pname __1gname ;
int __1go ;

# 1808 "/home/claude/cfront-3/src/expr2.cpp"
__1gname = look__5tableFPCcUc ( __1tbl , __1obb , (unsigned char )0 ) ;

# 1810 "/home/claude/cfront-3/src/expr2.cpp"
if (! __1gname )__1go = 0 ;
else if (__1gname -> __O1__4expr.tp -> base__4node == 108 )__1go = matchable__FP4nameP4expri ( __1gname , __1ee1 , 0 ) ;
else { 
# 1813 "/home/claude/cfront-3/src/expr2.cpp"
suppress_error ++ ;
__1Ggn = __1gname ;
{ Pgen __2g ;

# 1815 "/home/claude/cfront-3/src/expr2.cpp"
__2g = (((struct gen *)(((struct gen *)__1gname -> __O1__4expr.tp ))));

# 1817 "/home/claude/cfront-3/src/expr2.cpp"
__1gname = (__1ee1 -> __O3__4expr.e2 ?multArgMatch__3genFP4expri ( __2g , __1ee1 , 0 ) :oneArgMatch__3genFP4expri ( __2g , __1ee1 , 0 ) );
if (ambig )__1already_ambig = 1 ;
__1go = (__1gname ?matchable__FP4nameP4expri ( __1gname , __1ee1 , 0 ) :0 );
suppress_error -- ;

# 1820 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1823 "/home/claude/cfront-3/src/expr2.cpp"
non_const = 0 ;

# 1825 "/home/claude/cfront-3/src/expr2.cpp"
if (__1n1 ){ 
# 1826 "/home/claude/cfront-3/src/expr2.cpp"
if (__1bb == 70 ){ 
# 1827 "/home/claude/cfront-3/src/expr2.cpp"
Pclass __3c1 ;

# 1827 "/home/claude/cfront-3/src/expr2.cpp"
__3c1 = (((struct classdef *)(((struct classdef *)__1n1 -> __O1__4expr.tp ))));
if (look__5tableFPCcUc ( __3c1 -> memtbl__8classdef , __1obb , (unsigned char )0 ) == 0 ){ 
# 1829 "/home/claude/cfront-3/src/expr2.cpp"
Pclass __4bcl ;

# 1830 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X165 ;

# 1830 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X166 ;

# 1829 "/home/claude/cfront-3/src/expr2.cpp"
__4bcl = (__3c1 -> baselist__8classdef ?__3c1 -> baselist__8classdef -> bclass__6basecl :(((struct classdef *)0 )));

# 1831 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1n2 == 0 )|| ((! ( (__1__X165 = (((struct classdef *)(((struct classdef *)__1n2 -> __O1__4expr.tp ))))), ( (__1__X166 = __3c1 ), (
# 1831 "/home/claude/cfront-3/src/expr2.cpp"
((__1__X165 == __1__X166 )?1 :((__1__X165 && __1__X166 )?(((int )same_class__8classdefFP8classdefi ( __1__X165 , __1__X166 , 0 ) )):0 ))) ) ) )&& (has_base__8classdefFP8classdefiT2 ( ((struct classdef *)(((struct
# 1831 "/home/claude/cfront-3/src/expr2.cpp"
classdef *)__1n2 -> __O1__4expr.tp ))), __3c1 , 0 , 0 ) == 0 )))
# 1836 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1839 "/home/claude/cfront-3/src/expr2.cpp"
if (__3c1 -> c_xref__8classdef == 16)__3c1 -> c_xref__8classdef = 0 ;
if (__1go > 3)goto glob ;
return (struct expr *)0 ;
}

# 1846 "/home/claude/cfront-3/src/expr2.cpp"
if (((__4bcl && (__3c1 -> obj_size__8classdef != __4bcl -> obj_size__8classdef ))&& look__5tableFPCcUc ( __4bcl -> memtbl__8classdef , __1obb , (unsigned char )0 ) )||
# 1846 "/home/claude/cfront-3/src/expr2.cpp"
(__3c1 -> c_xref__8classdef & 29))
# 1851 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1854 "/home/claude/cfront-3/src/expr2.cpp"
if (__1go > 3)goto glob ;
return (make_assignment__FP4name ( __1n1 ) ?oper_overload__4exprFP5table ( __0this , __1tbl ) :(((struct expr *)0 )));

# 1857 "/home/claude/cfront-3/src/expr2.cpp"
}
return (struct expr *)0 ;
}

# 1861 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1863 "/home/claude/cfront-3/src/expr2.cpp"
{ Pclass __2ccl ;

# 1863 "/home/claude/cfront-3/src/expr2.cpp"
__2ccl = (((struct classdef *)(((struct classdef *)__1n1 -> __O1__4expr.tp ))));
if (strcmp ( __1obb , (const char *)"__as") ){ 
# 1865 "/home/claude/cfront-3/src/expr2.cpp"
tcl = __2ccl ;
}
{ Pexpr __2mn ;

# 1869 "/home/claude/cfront-3/src/expr2.cpp"
Pname __2mname ;

# 1867 "/home/claude/cfront-3/src/expr2.cpp"
__2mn = find_name__8classdefFPCcP8classdefiT3 ( __2ccl , __1obb , (struct classdef *)0 , 0 , 0 ) ;

# 1869 "/home/claude/cfront-3/src/expr2.cpp"
__2mname = (((struct name *)(((struct name *)__2mn ))));
if (__2mname == 0 )goto glob ;

# 1872 "/home/claude/cfront-3/src/expr2.cpp"
while ((__2mname -> base__4node == 44 )|| (__2mname -> base__4node == 177 )){ 
# 1873 "/home/claude/cfront-3/src/expr2.cpp"
__2mname = (((struct name *)(((struct name *)(((struct expr *)(((struct expr *)__2mname ))))-> __O4__4expr.mem ))));
# 1873 "/home/claude/cfront-3/src/expr2.cpp"

# 1874 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1876 "/home/claude/cfront-3/src/expr2.cpp"
{ int __2mo ;

# 1876 "/home/claude/cfront-3/src/expr2.cpp"
__2mo = 0 ;
if (const_obj1 )__1const_obj = 1 ;
if (__2mname -> __O1__4expr.tp -> base__4node == 108 )
# 1879 "/home/claude/cfront-3/src/expr2.cpp"
__2mo = matchable__FP4nameP4expri ( __2mname , __0this -> __O3__4expr.e2 , const_obj1 ) ;
else if (__2mname -> __O1__4expr.tp -> base__4node == 76 ){ 
# 1881 "/home/claude/cfront-3/src/expr2.cpp"
suppress_error ++ ;
{ Pgen __3g ;

# 1882 "/home/claude/cfront-3/src/expr2.cpp"
__3g = (((struct gen *)(((struct gen *)__2mname -> __O1__4expr.tp ))));
if (! __0this -> __O3__4expr.e2 ){ 
# 1884 "/home/claude/cfront-3/src/expr2.cpp"
__2mname = exactMatch__3genFP4expri ( __3g , (struct expr *)0 , const_obj1 ) ;
}
else if (__0this -> __O3__4expr.e2 -> __O3__4expr.e2 ){ 
# 1887 "/home/claude/cfront-3/src/expr2.cpp"
__2mname = multArgMatch__3genFP4expri ( __3g , __0this -> __O3__4expr.e2 , const_obj1 ) ;
}
else { 
# 1890 "/home/claude/cfront-3/src/expr2.cpp"
__2mname = oneArgMatch__3genFP4expri ( __3g , __0this -> __O3__4expr.e2 , const_obj1 ) ;
}
suppress_error -- ;
if (ambig )__1already_ambig += 2 ;
__2mo = (__2mname ?matchable__FP4nameP4expri ( __2mname , __0this -> __O3__4expr.e2 , const_obj1 ) :0 );

# 1894 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1897 "/home/claude/cfront-3/src/expr2.cpp"
if (__2mo == 0 )goto glob ;
if (((__2mo != 5)|| (look__5tableFPCcUc ( (((struct classdef *)(((struct classdef *)__1n1 -> __O1__4expr.tp ))))-> memtbl__8classdef , __1obb , (unsigned char )0 ) ==
# 1898 "/home/claude/cfront-3/src/expr2.cpp"
0 ))&& (__1go != 5))
# 1902 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1902 "/home/claude/cfront-3/src/expr2.cpp"
struct gen *__0__X167 ;

# 1903 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1Ggn && ( (__0__X167 = (((struct gen *)(((struct gen *)__1Ggn -> __O1__4expr.tp ))))), ( (__0__X167 -> holds_templ__3gen != 0)) ) )||
# 1903 "/home/claude/cfront-3/src/expr2.cpp"
(__1gname && ( __1gname -> n_template_fct__4name ) ))
# 1907 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1908 "/home/claude/cfront-3/src/expr2.cpp"
Pname __4f_inst ;

# 1908 "/home/claude/cfront-3/src/expr2.cpp"
__4f_inst = has_templ_instance__FP4nameP4exprUc ( __1Ggn ?__1Ggn :__1gname , __1ee1 , (unsigned char )1 ) ;
if (__4f_inst ){ 
# 1910 "/home/claude/cfront-3/src/expr2.cpp"
__1gname = __4f_inst ;
__1go = 5;
goto glob ;
}
}
}

# 1917 "/home/claude/cfront-3/src/expr2.cpp"
if (__2mo && __1go ){ 
# 1918 "/home/claude/cfront-3/src/expr2.cpp"
Pfct __3mfct ;
Ptype __3mt1 ;

# 1920 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X16 ;

# 1920 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1400qm5qkxojwcnm ;

# 1920 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1500qm5qkxojwcnm ;

# 1918 "/home/claude/cfront-3/src/expr2.cpp"
__3mfct = ( ((__2mname -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__2mname -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 1918 "/home/claude/cfront-3/src/expr2.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qm5qkxojwcnm )-> __O1__2ea.p = ((const void *)__2mname )),
# 1918 "/home/claude/cfront-3/src/expr2.cpp"
(& __0__X__V1400qm5qkxojwcnm )) , (const struct ea *)( (__2__X16 = __2mname -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qm5qkxojwcnm )->
# 1918 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qm5qkxojwcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 1918 "/home/claude/cfront-3/src/expr2.cpp"
, (((struct fct *)0 ))) )) ;
__3mt1 = __3mfct -> f_this__3fct -> __O1__4expr.tp ;
__3mt1 = (((struct ptr *)(((struct ptr *)__3mt1 ))))-> typ__5pvtyp ;
{ Ptype __3mt2 ;
Pname __3mm ;

# 1921 "/home/claude/cfront-3/src/expr2.cpp"
__3mt2 = __3mfct -> argtype__3fct -> __O1__4expr.tp ;
__3mm = __ct__4nameFPCc ( (struct name *)0 , __1gname -> __O2__4expr.string ) ;
__3mm -> n_oper__4name = __1gname -> n_oper__4name ;
{ Pname __3a1 ;

# 1924 "/home/claude/cfront-3/src/expr2.cpp"
__3a1 = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__3a1 -> __O1__4expr.tp = __3mt1 ;
{ Pname __3a2 ;

# 1926 "/home/claude/cfront-3/src/expr2.cpp"
__3a2 = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__3a2 -> __O1__4expr.tp = __3mt2 ;
__3a1 -> __O1__4name.n_list = __3a2 ;
__3mm -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , __3mfct -> returns__3fct , __3a1 , (unsigned char )2 ) ;

# 1931 "/home/claude/cfront-3/src/expr2.cpp"
{ Pname __3aa ;
Ptype __3savep ;
Pptr __3p ;

# 1934 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X16 ;

# 1934 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1400qm5qkxojwcnm ;

# 1934 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1500qm5qkxojwcnm ;

# 1931 "/home/claude/cfront-3/src/expr2.cpp"
__3aa = ( ((__1gname -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1gname -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 1931 "/home/claude/cfront-3/src/expr2.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qm5qkxojwcnm )-> __O1__2ea.p = ((const void *)__1gname )),
# 1931 "/home/claude/cfront-3/src/expr2.cpp"
(& __0__X__V1400qm5qkxojwcnm )) , (const struct ea *)( (__2__X16 = __1gname -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qm5qkxojwcnm )->
# 1931 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qm5qkxojwcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 1931 "/home/claude/cfront-3/src/expr2.cpp"
, (((struct fct *)0 ))) )) -> argtype__3fct ;
__3savep = 0 ;

# 1934 "/home/claude/cfront-3/src/expr2.cpp"
if (__3p = is_ref__4typeFv ( __3aa -> __O1__4expr.tp ) ){ 
# 1935 "/home/claude/cfront-3/src/expr2.cpp"
__3savep = (struct type *)__3p ;
__3aa -> __O1__4expr.tp = __3p -> typ__5pvtyp ;
}

# 1939 "/home/claude/cfront-3/src/expr2.cpp"
{ Pgen __3tgen ;
struct name_list __3nl ;

# 1939 "/home/claude/cfront-3/src/expr2.cpp"
__3tgen = __ct__3genFv ( (struct gen *)0 ) ;
__ct__9name_listFP4nameP9name_list ( & __3nl , __1gname , (struct name_list *)0 ) ;
__3tgen -> fct_list__3gen = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __3mm , & __3nl ) ;
{ Pname __3found ;

# 1942 "/home/claude/cfront-3/src/expr2.cpp"
__3found = multArgMatch__3genFP4expri ( __3tgen , __1ee1 , 0 ) ;
if (ambig )__1already_ambig = 1 ;

# 1945 "/home/claude/cfront-3/src/expr2.cpp"
if (__3savep )__3aa -> __O1__4expr.tp = (struct type *)__3p ;
( (__3a1 ?(((void )(__3a1 ?(((void )( ( ((((struct expr *)__3a1 ))?(((void )((((struct expr *)__3a1 ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 1946 "/home/claude/cfront-3/src/expr2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__3a1 , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 1946 "/home/claude/cfront-3/src/expr2.cpp"
( (__3a2 ?(((void )(__3a2 ?(((void )( ( ((((struct expr *)__3a2 ))?(((void )((((struct expr *)__3a2 ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 1946 "/home/claude/cfront-3/src/expr2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__3a2 , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
if (__3mm -> __O1__4expr.tp && (__3mm -> __O1__4expr.tp -> permanent__4node == 0 ))del__4typeFv ( __3mm -> __O1__4expr.tp ) ;

# 1949 "/home/claude/cfront-3/src/expr2.cpp"
__dl__FPv ( (void *)__3tgen ) ;
if (__3found != __3mm ){ 
# 1951 "/home/claude/cfront-3/src/expr2.cpp"
( (__3mm ?(((void )(__3mm ?(((void )( ( ((((struct expr *)__3mm ))?(((void )((((struct expr *)__3mm ))?(((void )(((void )0 )))):(((void
# 1951 "/home/claude/cfront-3/src/expr2.cpp"
)0 ))))):(((void )0 )))) , (((void )__dl__4nameSFPvUl ( (void *)__3mm , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void
# 1951 "/home/claude/cfront-3/src/expr2.cpp"
)0 )))) ;
if (__1already_ambig == 2 )__1already_ambig = 0 ;
goto glob ;
}

# 1957 "/home/claude/cfront-3/src/expr2.cpp"
if ((! ambig )&& (__1already_ambig == 1 ))__1already_ambig = 0 ;
( (__3mm ?(((void )(__3mm ?(((void )( ( ((((struct expr *)__3mm ))?(((void )((((struct expr *)__3mm ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 1958 "/home/claude/cfront-3/src/expr2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__3mm , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 1958 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1958 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1958 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1958 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1958 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1958 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1961 "/home/claude/cfront-3/src/expr2.cpp"
if (((((__2mo == 5)&& look__5tableFPCcUc ( (((struct classdef *)(((struct classdef *)__1n1 -> __O1__4expr.tp ))))-> memtbl__8classdef , __1obb , (unsigned char )0 ) )||
# 1961 "/home/claude/cfront-3/src/expr2.cpp"
(try_to_demote__FUcP4typeT2 ( __1bb , __1t1 , __1t2 ) <= 0 ))|| (__1already_ambig > 0 ))|| compare_builtin__FP4typeT1P4nameN23i ( __1t1 , __1t2 , __1n1 , __1n2 , __2mname ,
# 1961 "/home/claude/cfront-3/src/expr2.cpp"
__2mo ) )
# 1969 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 1970 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> base__4node = 146 ;
{ Pname __3xx ;

# 1972 "/home/claude/cfront-3/src/expr2.cpp"
struct ref *__0__X168 ;

# 1972 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X169 ;

# 1972 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X170 ;

# 1971 "/home/claude/cfront-3/src/expr2.cpp"
__3xx = __ct__4nameFPCc ( (struct name *)0 , __2mname -> __O2__4expr.string ) ;

# 1973 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X168 = 0 ), ( (__2__X169 = __0this -> __O2__4expr.e1 ), ( (__2__X170 = (struct expr *)__3xx ),
# 1973 "/home/claude/cfront-3/src/expr2.cpp"
( ((__0__X168 || (__0__X168 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X168 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct
# 1973 "/home/claude/cfront-3/src/expr2.cpp"
expr *)__0__X168 ), ((unsigned char )45 ), __2__X169 , (struct expr *)0 ) ), (__0__X168 -> __O4__4expr.mem = __2__X170 )) :0 ), __0__X168 ) )
# 1973 "/home/claude/cfront-3/src/expr2.cpp"
) ) ;
if (__1ee1 )( (__1ee1 ?(((void )(__1ee1 ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__1ee1 , (size_t )(sizeof (struct expr))) )))):(((void )0 ))))):(((void
# 1974 "/home/claude/cfront-3/src/expr2.cpp"
)0 )))) ;
return typ__4exprFP5table ( __0this , __1tbl ) ;

# 1975 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1976 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1976 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1976 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 1979 "/home/claude/cfront-3/src/expr2.cpp"
if (__1n2 && (__0this -> __O2__4expr.e1 == 0 )){ 
# 1980 "/home/claude/cfront-3/src/expr2.cpp"
if (const_obj2 )__1const_obj = 1 ;
suppress_error ++ ;
{ Pexpr __2mn ;

# 1982 "/home/claude/cfront-3/src/expr2.cpp"
__2mn = find_name__8classdefFPCcP8classdefiT3 ( ((struct classdef *)(((struct classdef *)__1n2 -> __O1__4expr.tp ))), __1obb , (struct classdef *)0 , 0 , 0 ) ;
suppress_error -- ;
{ Pname __2mname ;

# 1984 "/home/claude/cfront-3/src/expr2.cpp"
__2mname = (((struct name *)(((struct name *)__2mn ))));
if (__2mname == 0 )goto glob ;

# 1987 "/home/claude/cfront-3/src/expr2.cpp"
while ((__2mname -> base__4node == 44 )|| (__2mname -> base__4node == 177 )){ 
# 1988 "/home/claude/cfront-3/src/expr2.cpp"
__2mname = (((struct name *)(((struct name *)(((struct expr *)(((struct expr *)__2mname ))))-> __O4__4expr.mem ))));
# 1988 "/home/claude/cfront-3/src/expr2.cpp"

# 1989 "/home/claude/cfront-3/src/expr2.cpp"
}

# 1991 "/home/claude/cfront-3/src/expr2.cpp"
if ((__2mname -> n_scope__4name != 0 )&& (__2mname -> n_scope__4name != 25 )){ 
# 1992 "/home/claude/cfront-3/src/expr2.cpp"
goto glob ;
}

# 1995 "/home/claude/cfront-3/src/expr2.cpp"
{ int __2mo ;

# 1995 "/home/claude/cfront-3/src/expr2.cpp"
__2mo = 0 ;
if (__2mname -> __O1__4expr.tp -> base__4node == 108 )
# 1997 "/home/claude/cfront-3/src/expr2.cpp"
__2mo = matchable__FP4nameP4expri ( __2mname , (struct expr *)0 , const_obj2 ) ;
else if (__2mname -> __O1__4expr.tp -> base__4node == 76 ){ 
# 1999 "/home/claude/cfront-3/src/expr2.cpp"
suppress_error ++ ;
{ Pgen __3g ;

# 2000 "/home/claude/cfront-3/src/expr2.cpp"
__3g = (((struct gen *)(((struct gen *)__2mname -> __O1__4expr.tp ))));
__2mname = exactMatch__3genFP4expri ( __3g , (struct expr *)0 , const_obj2 ) ;
if (ambig )__1already_ambig += 2 ;
suppress_error -- ;
__2mo = (__2mname ?matchable__FP4nameP4expri ( __2mname , (struct expr *)0 , const_obj2 ) :0 );

# 2004 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 2007 "/home/claude/cfront-3/src/expr2.cpp"
if (__2mo == 0 ){ 
# 2008 "/home/claude/cfront-3/src/expr2.cpp"
goto glob ;
}
if (((__2mo != 5)|| (look__5tableFPCcUc ( (((struct classdef *)(((struct classdef *)__1n2 -> __O1__4expr.tp ))))-> memtbl__8classdef , __1obb , (unsigned char )0 ) ==
# 2010 "/home/claude/cfront-3/src/expr2.cpp"
0 ))&& (__1go != 5))
# 2014 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2014 "/home/claude/cfront-3/src/expr2.cpp"
struct gen *__0__X171 ;

# 2015 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1Ggn && ( (__0__X171 = (((struct gen *)(((struct gen *)__1Ggn -> __O1__4expr.tp ))))), ( (__0__X171 -> holds_templ__3gen != 0)) ) )||
# 2015 "/home/claude/cfront-3/src/expr2.cpp"
(__1gname && ( __1gname -> n_template_fct__4name ) ))
# 2019 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2020 "/home/claude/cfront-3/src/expr2.cpp"
Pname __4f_inst ;

# 2020 "/home/claude/cfront-3/src/expr2.cpp"
__4f_inst = has_templ_instance__FP4nameP4exprUc ( __1Ggn ?__1Ggn :__1gname , __1ee1 , (unsigned char )1 ) ;
if (__4f_inst ){ 
# 2022 "/home/claude/cfront-3/src/expr2.cpp"
__1gname = __4f_inst ;
__1go = 5;
goto glob ;
}
}
}
if (__2mo && __1go ){ 
# 2029 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __3mt1 ;

# 2030 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X16 ;

# 2030 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1400qm5qkxojwcnm ;

# 2030 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1500qm5qkxojwcnm ;

# 2029 "/home/claude/cfront-3/src/expr2.cpp"
__3mt1 = ( ((__2mname -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__2mname -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 2029 "/home/claude/cfront-3/src/expr2.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qm5qkxojwcnm )-> __O1__2ea.p = ((const void *)__2mname )),
# 2029 "/home/claude/cfront-3/src/expr2.cpp"
(& __0__X__V1400qm5qkxojwcnm )) , (const struct ea *)( (__2__X16 = __2mname -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qm5qkxojwcnm )->
# 2029 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qm5qkxojwcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 2029 "/home/claude/cfront-3/src/expr2.cpp"
, (((struct fct *)0 ))) )) -> f_this__3fct -> __O1__4expr.tp ;
__3mt1 = (((struct ptr *)(((struct ptr *)__3mt1 ))))-> typ__5pvtyp ;
{ Pname __3marg ;

# 2031 "/home/claude/cfront-3/src/expr2.cpp"
__3marg = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__3marg -> __O1__4expr.tp = __3mt1 ;
{ Pname __3garg ;
Pname __3nn ;

# 2035 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X16 ;

# 2035 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1400qm5qkxojwcnm ;

# 2035 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1500qm5qkxojwcnm ;

# 2033 "/home/claude/cfront-3/src/expr2.cpp"
__3garg = ( ((__1gname -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1gname -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 2033 "/home/claude/cfront-3/src/expr2.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qm5qkxojwcnm )-> __O1__2ea.p = ((const void *)__1gname )),
# 2033 "/home/claude/cfront-3/src/expr2.cpp"
(& __0__X__V1400qm5qkxojwcnm )) , (const struct ea *)( (__2__X16 = __1gname -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qm5qkxojwcnm )->
# 2033 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qm5qkxojwcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 2033 "/home/claude/cfront-3/src/expr2.cpp"
, (((struct fct *)0 ))) )) -> argtype__3fct ;
__3nn = bestOfPair__FP4nameT1P4type ( __3marg , __3garg , __0this -> __O3__4expr.e2 -> __O2__4expr.e1 -> __O1__4expr.tp ) ;

# 2036 "/home/claude/cfront-3/src/expr2.cpp"
if (__3nn == __3garg ){ 
# 2037 "/home/claude/cfront-3/src/expr2.cpp"
if (__1already_ambig == 2 )__1already_ambig = 0 ;
( (__3marg ?(((void )(__3marg ?(((void )( ( ((((struct expr *)__3marg ))?(((void )((((struct expr *)__3marg ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 2038 "/home/claude/cfront-3/src/expr2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__3marg , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
goto glob ;
}
else if (__3nn == __3marg ){ 
# 2042 "/home/claude/cfront-3/src/expr2.cpp"
if (__1already_ambig == 1 )__1already_ambig = 0 ;
}
else 
# 2045 "/home/claude/cfront-3/src/expr2.cpp"
if (! __3nn ){ 
# 2046 "/home/claude/cfront-3/src/expr2.cpp"
struct Block_Pname __4errblock ;

# 2046 "/home/claude/cfront-3/src/expr2.cpp"
( (( ((& __4errblock )-> n__11Block_Pname = 0 ), ( ((& __4errblock )-> p__11Block_Pname = 0 ), ( move__11Block_PnameFPP4nameUl ( (&
# 2046 "/home/claude/cfront-3/src/expr2.cpp"
__4errblock ), (Pname *)(((struct name **)__nw__FUl ( (size_t)((sizeof (struct name *))* ((unsigned long )3 ))) )), ((unsigned long
# 2046 "/home/claude/cfront-3/src/expr2.cpp"
)3 )) , (& __4errblock )-> n__11Block_Pname ) ) ) ), (& __4errblock )) ;
((*( (((Pname *)(& ((& __4errblock )-> p__11Block_Pname [0 ]))))) ))= __2mname ;
((*( (((Pname *)(& ((& __4errblock )-> p__11Block_Pname [1 ]))))) ))= __1gname ;
fmError__FiRC11Block_PnameP4exprUc ( 1 , (const struct Block_Pname *)(& __4errblock ), __0this -> __O3__4expr.e2 , (unsigned char )const_obj2 ) ;
__1already_ambig = 1 ;

# 2050 "/home/claude/cfront-3/src/expr2.cpp"
( (((void )( __dl__FPv ( (void *)(& __4errblock )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2050 "/home/claude/cfront-3/src/expr2.cpp"

# 2051 "/home/claude/cfront-3/src/expr2.cpp"
}
( (__3marg ?(((void )(__3marg ?(((void )( ( ((((struct expr *)__3marg ))?(((void )((((struct expr *)__3marg ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 2052 "/home/claude/cfront-3/src/expr2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__3marg , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 2052 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2052 "/home/claude/cfront-3/src/expr2.cpp"
}
}
__0this -> base__4node = 146 ;
{ Pname __2xx ;

# 2056 "/home/claude/cfront-3/src/expr2.cpp"
struct ref *__0__X172 ;

# 2056 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X173 ;

# 2056 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X174 ;

# 2055 "/home/claude/cfront-3/src/expr2.cpp"
__2xx = __ct__4nameFPCc ( (struct name *)0 , __2mname -> __O2__4expr.string ) ;

# 2057 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X172 = 0 ), ( (__2__X173 = __1oe2 ), ( (__2__X174 = (struct expr *)__2xx ), (
# 2057 "/home/claude/cfront-3/src/expr2.cpp"
((__0__X172 || (__0__X172 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X172 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X172 ),
# 2057 "/home/claude/cfront-3/src/expr2.cpp"
((unsigned char )45 ), __2__X173 , (struct expr *)0 ) ), (__0__X172 -> __O4__4expr.mem = __2__X174 )) :0 ), __0__X172 ) ) )
# 2057 "/home/claude/cfront-3/src/expr2.cpp"
) ;
__0this -> __O3__4expr.e2 = 0 ;
if (__1ee2 )( (__1ee2 ?(((void )(__1ee2 ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__1ee2 , (size_t )(sizeof (struct expr))) )))):(((void )0 ))))):(((void
# 2059 "/home/claude/cfront-3/src/expr2.cpp"
)0 )))) ;
if (__1ee1 && (__1ee1 != __1ee2 ))( (__1ee1 ?(((void )(__1ee1 ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__1ee1 , (size_t )(sizeof (struct expr)))
# 2060 "/home/claude/cfront-3/src/expr2.cpp"
)))):(((void )0 ))))):(((void )0 )))) ;
return typ__4exprFP5table ( __0this , __1tbl ) ;

# 2061 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2061 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2061 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2061 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 2064 "/home/claude/cfront-3/src/expr2.cpp"
glob :
# 2065 "/home/claude/cfront-3/src/expr2.cpp"
if (__1go != 5){ 
# 2065 "/home/claude/cfront-3/src/expr2.cpp"
struct gen *__0__X175 ;

# 2066 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1Ggn && ( (__0__X175 = (((struct gen *)(((struct gen *)__1Ggn -> __O1__4expr.tp ))))), ( (__0__X175 -> holds_templ__3gen != 0)) ) )||
# 2066 "/home/claude/cfront-3/src/expr2.cpp"
(__1gname && ( __1gname -> n_template_fct__4name ) ))
# 2070 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2071 "/home/claude/cfront-3/src/expr2.cpp"
Pname __3f_inst ;

# 2071 "/home/claude/cfront-3/src/expr2.cpp"
__3f_inst = has_templ_instance__FP4nameP4exprUc ( __1Ggn ?__1Ggn :__1gname , __1ee1 , (unsigned char )1 ) ;
if (__3f_inst ){ 
# 2073 "/home/claude/cfront-3/src/expr2.cpp"
__1gname = __3f_inst ;
__1go = 5;
}
}
}
if (__1go ){ 
# 2080 "/home/claude/cfront-3/src/expr2.cpp"
if ((((__1go == 5)|| (try_to_demote__FUcP4typeT2 ( __1bb , __1t1 , __1t2 ) <= 0 ))|| (__1already_ambig > 0 ))|| compare_builtin__FP4typeT1P4nameN23i (
# 2080 "/home/claude/cfront-3/src/expr2.cpp"
__1t1 , __1t2 , __1n1 , __1n2 , __1gname , __1go ) )
# 2088 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2089 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> base__4node = ((__1gname -> __O4__4expr.n_table == gtbl )?146 :109 );
__0this -> __O2__4expr.e1 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1gname -> __O2__4expr.string ) ;

# 2092 "/home/claude/cfront-3/src/expr2.cpp"
if (__1gname -> __O4__4expr.n_table == gtbl )
# 2093 "/home/claude/cfront-3/src/expr2.cpp"
(((struct name *)(((struct name *)__0this -> __O2__4expr.e1 ))))-> __O2__4name.n_qualifier = sta_name ;
__0this -> __O3__4expr.e2 = __1ee1 ;
return typ__4exprFP5table ( __0this , __1tbl ) ;
}
}

# 2099 "/home/claude/cfront-3/src/expr2.cpp"
if (__1ee2 )( (__1ee2 ?(((void )(__1ee2 ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__1ee2 , (size_t )(sizeof (struct expr))) )))):(((void )0 ))))):(((void
# 2099 "/home/claude/cfront-3/src/expr2.cpp"
)0 )))) ;
if (__1ee1 && (__1ee1 != __1ee2 ))( (__1ee1 ?(((void )(__1ee1 ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__1ee1 , (size_t )(sizeof (struct expr)))
# 2100 "/home/claude/cfront-3/src/expr2.cpp"
)))):(((void )0 ))))):(((void )0 )))) ;
__0this -> __O3__4expr.e2 = __1oe2 ;

# 2103 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1bb ){ 
# 2104 "/home/claude/cfront-3/src/expr2.cpp"
case 71 :
# 2105 "/home/claude/cfront-3/src/expr2.cpp"
case 147 :
# 2106 "/home/claude/cfront-3/src/expr2.cpp"
case 145 :
# 2107 "/home/claude/cfront-3/src/expr2.cpp"
return (struct expr *)0 ;
case 70 :
# 2109 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1n1 && __1n2 )&& ((__1n1 -> __O1__4expr.tp == __1n2 -> __O1__4expr.tp )|| has_base__8classdefFP8classdefiT2 ( ((struct classdef *)(((struct classdef *)__1n2 -> __O1__4expr.tp ))), ((struct
# 2109 "/home/claude/cfront-3/src/expr2.cpp"
classdef *)(((struct classdef *)__1n1 -> __O1__4expr.tp ))), 0 , 0 ) ))
# 2116 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2117 "/home/claude/cfront-3/src/expr2.cpp"
if ((! const_obj1 )&& make_assignment__FP4name ( __1n1 ) )
# 2118 "/home/claude/cfront-3/src/expr2.cpp"
return oper_overload__4exprFP5table ( __0this ,
# 2118 "/home/claude/cfront-3/src/expr2.cpp"
__1tbl ) ;
else 
# 2120 "/home/claude/cfront-3/src/expr2.cpp"
return (struct expr *)0 ;
}
case 111 :
# 2123 "/home/claude/cfront-3/src/expr2.cpp"
case 109 :
# 2124 "/home/claude/cfront-3/src/expr2.cpp"
if (__1n1 == 0 )break ;

# 2126 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 2127 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1n1 && (((struct classdef *)(((struct classdef *)__1n1 -> __O1__4expr.tp ))))-> conv__8classdef )&& ((__1bb == 66 )|| (__1bb == 67 )))
# 2132 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2133 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O2__4expr.e1 =
# 2133 "/home/claude/cfront-3/src/expr2.cpp"
check_cond__FP4exprUcP5table ( __0this -> __O2__4expr.e1 , __1bb , __1tbl ) ;
return (struct expr *)0 ;
}

# 2137 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1n2 && (((struct classdef *)(((struct classdef *)__1n2 -> __O1__4expr.tp ))))-> conv__8classdef )&& ((((((__1bb == 66 )|| (__1bb == 67 ))|| (__1bb == 46 ))|| (__1bb ==
# 2137 "/home/claude/cfront-3/src/expr2.cpp"
107 ))|| (__1bb == 172 ))|| (__1bb == 47 )))
# 2143 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2144 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __3te ;

# 2144 "/home/claude/cfront-3/src/expr2.cpp"
__3te = check_cond__FP4exprUcP5table ( __0this -> __O3__4expr.e2 , __1bb , __1tbl ) ;
if (__3te == __0this -> __O3__4expr.e2 ){ 
# 2146 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O1__4expr.tp = (struct type *)any_type ;
return __0this ;
}
__0this -> __O3__4expr.e2 = __3te ;
return (struct expr *)0 ;
}

# 2153 "/home/claude/cfront-3/src/expr2.cpp"
{ int __2ttd ;
switch (__2ttd = try_to_demote__FUcP4typeT2 ( __1bb , __1t1 , __1t2 ) ){ 
# 2155 "/home/claude/cfront-3/src/expr2.cpp"
case -2:
# 2156 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2156 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V146 ;

# 2156 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"no usable const conversion for%n", (const struct ea *)( ((& __0__V146 )-> __O1__2ea.p =
# 2156 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n2 )), (& __0__V146 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2156 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
break ;
case -1:
# 2159 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2159 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V147 ;

# 2159 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"no usable const conversion for%n", (const struct ea *)( ((& __0__V147 )-> __O1__2ea.p =
# 2159 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n1 )), (& __0__V147 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2159 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
break ;
case 0 :
# 2162 "/home/claude/cfront-3/src/expr2.cpp"
break ;
case 2 :
# 2164 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2164 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V148 ;

# 2164 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous conversion of%n", (const struct ea *)( ((& __0__V148 )-> __O1__2ea.p =
# 2164 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n1 )), (& __0__V148 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2164 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
break ;
case 3 :
# 2167 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2167 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V149 ;

# 2167 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous conversion of%n", (const struct ea *)( ((& __0__V149 )-> __O1__2ea.p =
# 2167 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n2 )), (& __0__V149 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2167 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
break ;
case 4 :
# 2170 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2170 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V150 ;

# 2170 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V151 ;

# 2170 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous conversion of%n and%n", (const struct ea *)( ((& __0__V150 )-> __O1__2ea.p =
# 2170 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1n1 )), (& __0__V150 )) , (const struct ea *)( ((& __0__V151 )-> __O1__2ea.p = ((const void
# 2170 "/home/claude/cfront-3/src/expr2.cpp"
*)__1n2 )), (& __0__V151 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
case 1 :
# 2173 "/home/claude/cfront-3/src/expr2.cpp"
if (Lcoerce ){ 
# 2174 "/home/claude/cfront-3/src/expr2.cpp"
Pname __4xx ;
Pref __4r ;

# 2176 "/home/claude/cfront-3/src/expr2.cpp"
struct ref *__0__X176 ;

# 2176 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X177 ;

# 2176 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X178 ;

# 2174 "/home/claude/cfront-3/src/expr2.cpp"
__4xx = __ct__4nameFPCc ( (struct name *)0 , Lcoerce -> __O2__4expr.string ) ;
__4r = ( (__0__X176 = 0 ), ( (__2__X177 = __0this -> __O2__4expr.e1 ), ( (__2__X178 = (struct expr *)__4xx ), ( ((__0__X176 ||
# 2175 "/home/claude/cfront-3/src/expr2.cpp"
(__0__X176 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X176 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X176 ), ((unsigned
# 2175 "/home/claude/cfront-3/src/expr2.cpp"
char )45 ), __2__X177 , (struct expr *)0 ) ), (__0__X176 -> __O4__4expr.mem = __2__X178 )) :0 ), __0__X176 ) ) ) )
# 2175 "/home/claude/cfront-3/src/expr2.cpp"
;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , (struct expr *)__4r , (struct expr *)0 ) ;
}

# 2179 "/home/claude/cfront-3/src/expr2.cpp"
if (Rcoerce ){ 
# 2180 "/home/claude/cfront-3/src/expr2.cpp"
Pname __4xx ;
Pref __4r ;

# 2182 "/home/claude/cfront-3/src/expr2.cpp"
struct ref *__0__X179 ;

# 2182 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X180 ;

# 2182 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X181 ;

# 2180 "/home/claude/cfront-3/src/expr2.cpp"
__4xx = __ct__4nameFPCc ( (struct name *)0 , Rcoerce -> __O2__4expr.string ) ;
__4r = ( (__0__X179 = 0 ), ( (__2__X180 = __0this -> __O3__4expr.e2 ), ( (__2__X181 = (struct expr *)__4xx ), ( ((__0__X179 ||
# 2181 "/home/claude/cfront-3/src/expr2.cpp"
(__0__X179 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X179 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X179 ), ((unsigned
# 2181 "/home/claude/cfront-3/src/expr2.cpp"
char )45 ), __2__X180 , (struct expr *)0 ) ), (__0__X179 -> __O4__4expr.mem = __2__X181 )) :0 ), __0__X179 ) ) ) )
# 2181 "/home/claude/cfront-3/src/expr2.cpp"
;
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , (struct expr *)__4r , (struct expr *)0 ) ;
}
return typ__4exprFP5table ( __0this , __1tbl ) ;
} } } } } }

# 2187 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1bb ){ 
# 2188 "/home/claude/cfront-3/src/expr2.cpp"
case 71 :
# 2189 "/home/claude/cfront-3/src/expr2.cpp"
case 112 :
# 2190 "/home/claude/cfront-3/src/expr2.cpp"
return (struct expr *)0 ;
}

# 2193 "/home/claude/cfront-3/src/expr2.cpp"
if (__1t1 && __1t2 )
# 2194 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2194 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V152 ;

# 2194 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V153 ;

# 2194 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V154 ;

# 2194 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V155 ;

# 2194 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"bad operands for%k:%t%k%t", (const struct ea *)( ((
# 2194 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V152 )-> __O1__2ea.i = ((unsigned long )__1bb )), 0 ) ), (& __0__V152 )) , (const struct ea *)(
# 2194 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V153 )-> __O1__2ea.p = ((const void *)__1t1 )), (& __0__V153 )) , (const struct ea *)( (( ((&
# 2194 "/home/claude/cfront-3/src/expr2.cpp"
__0__V154 )-> __O1__2ea.i = ((unsigned long )__1bb )), 0 ) ), (& __0__V154 )) , (const struct ea *)( ((&
# 2194 "/home/claude/cfront-3/src/expr2.cpp"
__0__V155 )-> __O1__2ea.p = ((const void *)__1t2 )), (& __0__V155 )) ) ;
} else 
# 2196 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2196 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V156 ;

# 2196 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V157 ;

# 2196 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"bad operand for%k:%t", (const struct ea *)( ((
# 2196 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V156 )-> __O1__2ea.i = ((unsigned long )__1bb )), 0 ) ), (& __0__V156 )) , (const struct ea *)(
# 2196 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V157 )-> __O1__2ea.p = ((const void *)(__1t1 ?__1t1 :__1t2 ))), (& __0__V157 )) , (const struct ea *)ea0 , (const struct
# 2196 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
} 
# 2198 "/home/claude/cfront-3/src/expr2.cpp"
if ((__1const_obj && (__2ttd <= 0 ))&& non_const )
# 2199 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2199 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V158 ;

# 2199 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)" (no usable const operator%k)\n", (const struct ea *)( ((
# 2199 "/home/claude/cfront-3/src/expr2.cpp"
((& __0__V158 )-> __O1__2ea.i = ((unsigned long )__1bb )), 0 ) ), (& __0__V158 )) , (const struct ea *)ea0 ,
# 2199 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else error__FiPCc ( (int )'c' , (const char *)"\n") ;

# 2202 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O1__4expr.tp = (struct type *)any_type ;
return __0this ;

# 2203 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 2206 "/home/claude/cfront-3/src/expr2.cpp"
return (struct expr *)0 ;

# 2206 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2206 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2206 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2206 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2206 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 807 "/home/claude/cfront-3/src/cfront.h"
bit not_simple__4exprFi (struct expr *__0this , int __1inflag );

# 35 "/home/claude/cfront-3/src/cfront.h"
extern Ptype unconst_type__FP4type (Ptype );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 532 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr rptr__FP4typeP4expri (Ptype , Pexpr , int );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 2209 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr cast_cptr__FP8classdefP4exprP5tablei (Pclass __1ccl , Pexpr __1ee , Ptable __1tbl , int __1real_cast )
# 2214 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2216 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __1etp ;

# 2216 "/home/claude/cfront-3/src/expr2.cpp"
__1etp = (struct type *)is_ptr_or_ref__4typeFv ( __1ee -> __O1__4expr.tp ) ;
if (__1etp == 0 )return __1ee ;

# 2219 "/home/claude/cfront-3/src/expr2.cpp"
{ Pname __1on ;

# 2219 "/home/claude/cfront-3/src/expr2.cpp"
__1on = is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)__1etp ))))-> typ__5pvtyp ) ;
if (__1on == 0 )return __1ee ;

# 2222 "/home/claude/cfront-3/src/expr2.cpp"
{ Pclass __1ocl ;

# 2223 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X200 ;

# 2223 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X201 ;

# 2222 "/home/claude/cfront-3/src/expr2.cpp"
__1ocl = (((struct classdef *)(((struct classdef *)__1on -> __O1__4expr.tp ))));
if (((__1ccl == 0 )|| (__1ocl == 0 ))|| ( (__1__X200 = __1ocl ), ( (__1__X201 = __1ccl ), ( ((__1__X200 == __1__X201 )?1 :((__1__X200 &&
# 2223 "/home/claude/cfront-3/src/expr2.cpp"
__1__X201 )?(((int )same_class__8classdefFP8classdefi ( __1__X200 , __1__X201 , 0 ) )):0 ))) ) ) )return __1ee ;

# 2226 "/home/claude/cfront-3/src/expr2.cpp"
{ int __1oo ;

# 2227 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X202 ;

# 2227 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X203 ;

# 2227 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X206 ;

# 2227 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X207 ;

# 2226 "/home/claude/cfront-3/src/expr2.cpp"
__1oo = 0 ;

# 2228 "/home/claude/cfront-3/src/expr2.cpp"
if (__1ocl -> baselist__8classdef && ((! ( (__1__X202 = __1ocl -> baselist__8classdef -> bclass__6basecl ), ( (__1__X203 = __1ccl ), ( ((__1__X202 ==
# 2228 "/home/claude/cfront-3/src/expr2.cpp"
__1__X203 )?1 :((__1__X202 && __1__X203 )?(((int )same_class__8classdefFP8classdefi ( __1__X202 , __1__X203 , 0 ) )):0 ))) ) ) )|| (__1ocl -> baselist__8classdef -> base__4node != 85 )))
# 2229 "/home/claude/cfront-3/src/expr2.cpp"
{
# 2229 "/home/claude/cfront-3/src/expr2.cpp"

# 2231 "/home/claude/cfront-3/src/expr2.cpp"
Nptr = 0 ;
Nvis = 0 ;
Nalloc_base = 0 ;
if (vcllist ){ 
# 2235 "/home/claude/cfront-3/src/expr2.cpp"
clear__5clistFv ( vcllist ) ;
vcllist = 0 ;
}
{ int __2x ;

# 2238 "/home/claude/cfront-3/src/expr2.cpp"
__2x = is_unique_base__FP8classdefPCciT3T1 ( __1ocl , __1ccl -> string__8classdef , 0 , 0 , (struct classdef *)0 ) ;
if (Nvis ){ 
# 2239 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X204 ;

# 2239 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X205 ;

# 2240 "/home/claude/cfront-3/src/expr2.cpp"
if (__1real_cast == 0 )
# 2241 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2241 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V182 ;

# 2241 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V183 ;

# 2241 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V184 ;

# 2241 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"cast:%n* ->B%t*;%kBC", (const struct ea *)( ((& __0__V182 )-> __O1__2ea.p =
# 2241 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1on )), (& __0__V182 )) , (const struct ea *)( ((& __0__V183 )-> __O1__2ea.p = ((const void
# 2241 "/home/claude/cfront-3/src/expr2.cpp"
*)__1ccl )), (& __0__V183 )) , (const struct ea *)( (__2__X204 = Nvis ), ( (( ((& __0__V184 )-> __O1__2ea.i =
# 2241 "/home/claude/cfront-3/src/expr2.cpp"
__2__X204 ), 0 ) ), (& __0__V184 )) ) , (const struct ea *)ea0 ) ;
} else if (warning_opt )
# 2243 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2243 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V185 ;

# 2243 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V186 ;

# 2243 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V187 ;

# 2243 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"cast:%n* ->B%t*;%kBC", (const struct ea *)( ((&
# 2243 "/home/claude/cfront-3/src/expr2.cpp"
__0__V185 )-> __O1__2ea.p = ((const void *)__1on )), (& __0__V185 )) , (const struct ea *)( ((& __0__V186 )-> __O1__2ea.p =
# 2243 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1ccl )), (& __0__V186 )) , (const struct ea *)( (__2__X205 = Nvis ), ( (( ((&
# 2243 "/home/claude/cfront-3/src/expr2.cpp"
__0__V187 )-> __O1__2ea.i = __2__X205 ), 0 ) ), (& __0__V187 )) ) , (const struct ea *)ea0 ) ;
} __1real_cast = 1 ;
Nvis = 0 ;

# 2247 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2249 "/home/claude/cfront-3/src/expr2.cpp"
switch (__2x ){ 
# 2250 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 2251 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2251 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V188 ;

# 2251 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V189 ;

# 2251 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V190 ;

# 2251 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"cast:%n* ->B%t*;%t isB more than once", (const struct ea *)( ((& __0__V188 )-> __O1__2ea.p =
# 2251 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1on )), (& __0__V188 )) , (const struct ea *)( ((& __0__V189 )-> __O1__2ea.p = ((const void
# 2251 "/home/claude/cfront-3/src/expr2.cpp"
*)__1ccl )), (& __0__V189 )) , (const struct ea *)( ((& __0__V190 )-> __O1__2ea.p = ((const void *)__1ccl )), (&
# 2251 "/home/claude/cfront-3/src/expr2.cpp"
__0__V190 )) , (const struct ea *)ea0 ) ;
case 0 :
# 2253 "/home/claude/cfront-3/src/expr2.cpp"
break ;
case 1 :
# 2255 "/home/claude/cfront-3/src/expr2.cpp"
__1oo = Noffset ;
break ;
} }

# 2259 "/home/claude/cfront-3/src/expr2.cpp"
if (Nptr ){ 
# 2271 "/home/claude/cfront-3/src/expr2.cpp"
extern Pexpr this_handler ;

# 2260 "/home/claude/cfront-3/src/expr2.cpp"
if (__1ocl -> c_body__8classdef == 1 )dcl_print__8classdefFP4name ( __1ocl , (struct name *)0 ) ;
Nptr -> __O4__4expr.mem = __1ee ;
if (Nalloc_base ){ 
# 2264 "/home/claude/cfront-3/src/expr2.cpp"
Nptr -> __O2__4expr.i1 = 5 ;
Nptr -> __O1__4expr.string4 = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* (strlen ( Nalloc_base ) + 1 ))) ));
# 2265 "/home/claude/cfront-3/src/expr2.cpp"

# 2266 "/home/claude/cfront-3/src/expr2.cpp"
strcpy ( Nptr -> __O1__4expr.string4 , Nalloc_base ) ;
Nalloc_base = 0 ;
}
else Nptr -> __O2__4expr.i1 = 3 ;

# 2271 "/home/claude/cfront-3/src/expr2.cpp"
;
if ((__1ee -> base__4node == 112 )|| (__1ee -> base__4node == 145 ))
# 2273 "/home/claude/cfront-3/src/expr2.cpp"
__1ee = Nptr ;
else if ((this_handler && (__1ee -> base__4node == 85 ))&& (strcmp ( __1ee -> __O2__4expr.string , (const char *)"this")
# 2274 "/home/claude/cfront-3/src/expr2.cpp"
== 0 ))
# 2276 "/home/claude/cfront-3/src/expr2.cpp"
__1ee = this_handler ;
else { 
# 2278 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __4p ;

# 2278 "/home/claude/cfront-3/src/expr2.cpp"
__4p = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , Nptr , zero ) ;
nin = 1 ;
if (not_simple__4exprFi ( __1ee , 0 ) ){ 
# 2281 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __5t ;
Pname __5pp ;

# 2281 "/home/claude/cfront-3/src/expr2.cpp"
__5t = unconst_type__FP4type ( __1ee -> __O1__4expr.tp ) ;
__5pp = make_tmp__FcP4typeP5table ( 'N' , __5t , __1tbl ) ;
(((struct name *)(((struct name *)__5pp ))))-> n_assigned_to__4name = 1 ;
__1ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__5pp , __1ee ) ;
__1ee -> __O1__4expr.tp = __5t ;
Nptr -> __O4__4expr.mem = (struct expr *)__5pp ;
}
nin = 0 ;
__4p -> __O4__4expr.cond = __1ee ;
__4p -> __O1__4expr.tp = __1ee -> __O1__4expr.tp ;
__1ee = __4p ;
}
}

# 2293 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 2296 "/home/claude/cfront-3/src/expr2.cpp"
if (__1ccl -> baselist__8classdef && ((! ( (__1__X206 = __1ccl -> baselist__8classdef -> bclass__6basecl ), ( (__1__X207 = __1ocl ), ( ((__1__X206 ==
# 2296 "/home/claude/cfront-3/src/expr2.cpp"
__1__X207 )?1 :((__1__X206 && __1__X207 )?(((int )same_class__8classdefFP8classdefi ( __1__X206 , __1__X207 , 0 ) )):0 ))) ) ) )|| (__1ccl -> baselist__8classdef -> base__4node != 85 )))
# 2297 "/home/claude/cfront-3/src/expr2.cpp"
{
# 2297 "/home/claude/cfront-3/src/expr2.cpp"

# 2299 "/home/claude/cfront-3/src/expr2.cpp"
Nptr = 0 ;
if (vcllist ){ 
# 2301 "/home/claude/cfront-3/src/expr2.cpp"
clear__5clistFv ( vcllist ) ;
vcllist = 0 ;
}
{ int __2x ;

# 2304 "/home/claude/cfront-3/src/expr2.cpp"
__2x = is_unique_base__FP8classdefPCciT3T1 ( __1ccl , __1ocl -> string__8classdef , 0 , 0 , (struct classdef *)0 ) ;
switch (__2x ){ 
# 2306 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 2307 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2307 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V191 ;

# 2307 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V192 ;

# 2307 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V193 ;

# 2307 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"cast:%n* ->derived%t*;%n isB more than once", (const struct ea *)( ((& __0__V191 )-> __O1__2ea.p =
# 2307 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1on )), (& __0__V191 )) , (const struct ea *)( ((& __0__V192 )-> __O1__2ea.p = ((const void
# 2307 "/home/claude/cfront-3/src/expr2.cpp"
*)__1ccl )), (& __0__V192 )) , (const struct ea *)( ((& __0__V193 )-> __O1__2ea.p = ((const void *)__1on )), (&
# 2307 "/home/claude/cfront-3/src/expr2.cpp"
__0__V193 )) , (const struct ea *)ea0 ) ;
case 0 :
# 2309 "/home/claude/cfront-3/src/expr2.cpp"
break ;
case 1 :
# 2311 "/home/claude/cfront-3/src/expr2.cpp"
__1oo = (- Noffset );
if (Nptr )
# 2313 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2313 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V194 ;

# 2313 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V195 ;

# 2313 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V196 ;

# 2313 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"cast:%n* ->derived%t*;%n is virtualB", (const struct ea *)( ((& __0__V194 )-> __O1__2ea.p =
# 2313 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1on )), (& __0__V194 )) , (const struct ea *)( ((& __0__V195 )-> __O1__2ea.p = ((const void
# 2313 "/home/claude/cfront-3/src/expr2.cpp"
*)__1ccl )), (& __0__V195 )) , (const struct ea *)( ((& __0__V196 )-> __O1__2ea.p = ((const void *)__1on )), (&
# 2313 "/home/claude/cfront-3/src/expr2.cpp"
__0__V196 )) , (const struct ea *)ea0 ) ;
} break ;
} }
Nvis = 0 ;

# 2316 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 2319 "/home/claude/cfront-3/src/expr2.cpp"
if (__1oo ){ 
# 2320 "/home/claude/cfront-3/src/expr2.cpp"
if (((__1ee -> base__4node == 112 )|| (__1ee -> base__4node == 145 ))|| ((__1ee -> base__4node == 85 )&& (__1ee -> __O1__4expr.tp ->
# 2320 "/home/claude/cfront-3/src/expr2.cpp"
base__4node == 158 )))
# 2321 "/home/claude/cfront-3/src/expr2.cpp"
__1ee = rptr__FP4typeP4expri ( __1ee -> __O1__4expr.tp , __1ee , __1oo ) ;
else { 
# 2323 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __3p ;
nin = 1 ;
if (not_simple__4exprFi ( __1ee , 0 ) ){ 
# 2326 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __4t ;
Pname __4pp ;

# 2326 "/home/claude/cfront-3/src/expr2.cpp"
__4t = ((__1ee -> base__4node == 177 )?__1ee -> __O4__4expr.mem -> __O1__4expr.tp :__1ee -> __O1__4expr.tp );
__4pp = make_tmp__FcP4typeP5table ( 'M' , __4t , __1tbl ) ;
if (__4pp -> __O1__4expr.tp -> base__4node == 110 )
# 2329 "/home/claude/cfront-3/src/expr2.cpp"
__4pp -> __O1__4expr.tp = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (((struct
# 2329 "/home/claude/cfront-3/src/expr2.cpp"
vec *)(((struct vec *)__4pp -> __O1__4expr.tp ))))-> typ__5pvtyp ) ;
(((struct name *)(((struct name *)__4pp ))))-> n_assigned_to__4name = 1 ;
__1ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__4pp , __1ee ) ;
__1ee -> __O1__4expr.tp = __4t ;
__3p = rptr__FP4typeP4expri ( __4t , (struct expr *)__4pp , __1oo ) ;
}
else 
# 2336 "/home/claude/cfront-3/src/expr2.cpp"
__3p = rptr__FP4typeP4expri ( (__1ee -> base__4node == 177 )?__1ee -> __O4__4expr.mem -> __O1__4expr.tp :__1ee -> __O1__4expr.tp , __1ee , __1oo ) ;
nin = 0 ;
{ Pexpr __3pp ;

# 2338 "/home/claude/cfront-3/src/expr2.cpp"
__3pp = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , __3p , zero ) ;
__3pp -> __O1__4expr.tp = __1ee -> __O1__4expr.tp ;
__3pp -> __O4__4expr.cond = __1ee ;
__1ee = __3pp ;

# 2341 "/home/claude/cfront-3/src/expr2.cpp"
}
}
}

# 2345 "/home/claude/cfront-3/src/expr2.cpp"
Nvis = 0 ;
if (has_base__8classdefFP8classdefiT2 ( __1ocl , __1ccl , 0 , 0 ) && Nvis ){ 
# 2346 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X208 ;

# 2347 "/home/claude/cfront-3/src/expr2.cpp"
if (__1real_cast == 0 )
# 2348 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2348 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V197 ;

# 2348 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V198 ;

# 2348 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V199 ;

# 2348 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"cast:%n* ->B%t*;%kBC", (const struct ea *)( ((& __0__V197 )-> __O1__2ea.p =
# 2348 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__1on )), (& __0__V197 )) , (const struct ea *)( ((& __0__V198 )-> __O1__2ea.p = ((const void
# 2348 "/home/claude/cfront-3/src/expr2.cpp"
*)__1ccl )), (& __0__V198 )) , (const struct ea *)( (__2__X208 = Nvis ), ( (( ((& __0__V199 )-> __O1__2ea.i =
# 2348 "/home/claude/cfront-3/src/expr2.cpp"
__2__X208 ), 0 ) ), (& __0__V199 )) ) , (const struct ea *)ea0 ) ;
} 
# 2352 "/home/claude/cfront-3/src/expr2.cpp"
Nvis = 0 ;
}

# 2356 "/home/claude/cfront-3/src/expr2.cpp"
return __1ee ;

# 2356 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2356 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2356 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 345 "/home/claude/cfront-3/src/cfront.h"
void dcl__4typeFP5table (struct type *__0this , Ptable );

# 466 "/home/claude/cfront-3/src/cfront.h"

# 470 "/home/claude/cfront-3/src/cfront.h"
Pname has_ictor__8classdefFv (struct classdef *__0this );

# 469 "/home/claude/cfront-3/src/cfront.h"

# 454 "/home/claude/cfront-3/src/cfront.h"
void make_vec_ctor__8classdefFP4name (struct classdef *__0this , Pname );

# 468 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 537 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr find_name__FP4nameP8classdefP5tableiT1 (Pname , Pclass , Ptable , int , Pname );

# 832 "/home/claude/cfront-3/src/cfront.h"

# 802 "/home/claude/cfront-3/src/cfront.h"
Ptype call_fct__4exprFP5table (struct expr *__0this , Ptable );

# 1230 "/home/claude/cfront-3/src/cfront.h"
extern void check_visibility__FP4nameT1P8classdefP5tableT1 (Pname , Pname , Pclass , Ptable , Pname );

# 1228 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr call_ctor__FP5tableP4exprN22iT2 (Ptable , Pexpr __0p , Pexpr __0ctor , Pexpr __0args , int __0d , Pexpr __0vb_args );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 2359 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr donew__4exprFP5table (register struct expr *__0this , Ptable __1tbl )
# 2360 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2361 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __1tt ;
Ptype __1tpx ;
bit __1v ;
bit __1old ;
int __1init ;

# 2361 "/home/claude/cfront-3/src/expr2.cpp"
__1tt = __0this -> __O4__4expr.tp2 ;
__1tpx = __1tt ;
__1v = 0 ;
__1old = new_type ;
__1init = 0 ;
new_type = 1 ;

# 2368 "/home/claude/cfront-3/src/expr2.cpp"
dcl__4typeFP5table ( __1tt , __1tbl ) ;
new_type = __1old ;

# 2371 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> __O2__4expr.e1 )__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
if (__0this -> __O3__4expr.e2 )__0this -> __O3__4expr.e2 = typ__4exprFP5table ( __0this -> __O3__4expr.e2 , __1tbl ) ;
ll :
# 2375 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1tt -> base__4node ){ 
# 2376 "/home/claude/cfront-3/src/expr2.cpp"
default :
# 2377 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> __O2__4expr.e1 ){ 
# 2378 "/home/claude/cfront-3/src/expr2.cpp"
if (__1v ){ 
# 2379 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCc ( (const char *)"Ir for array created using \"new\"")
# 2379 "/home/claude/cfront-3/src/expr2.cpp"
;
break ;
}
__1init = 1 ;
}

# 2388 "/home/claude/cfront-3/src/expr2.cpp"
break ;
case 110 :
# 2390 "/home/claude/cfront-3/src/expr2.cpp"
if (__1v && (((struct vec *)(((struct vec *)__1tt ))))-> dim__3vec )error__FPCc ( (const char *)"only 1st array dimension can be non-constant")
# 2390 "/home/claude/cfront-3/src/expr2.cpp"
;
if (((((struct vec *)(((struct vec *)__1tt ))))-> size__3vec == 0 )&& ((((struct vec *)(((struct vec *)__1tt ))))-> dim__3vec == 0 ))error__FPCc ( (const char *)"array dimension missing in `new'")
# 2391 "/home/claude/cfront-3/src/expr2.cpp"
;

# 2396 "/home/claude/cfront-3/src/expr2.cpp"
__1v ++ ;
__1tt = (((struct vec *)(((struct vec *)__1tt ))))-> typ__5pvtyp ;
goto ll ;
case 97 :
# 2400 "/home/claude/cfront-3/src/expr2.cpp"
__1tt = (((struct basetype *)(((struct basetype *)__1tt ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto ll ;
case 38 :
# 2403 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCc ( (const char *)"badT for `new': void") ;
break ;
case 119 :
# 2406 "/home/claude/cfront-3/src/expr2.cpp"
{ Pname __3cn ;
Pclass __3cl ;
Pname __3icn ;

# 2406 "/home/claude/cfront-3/src/expr2.cpp"
__3cn = (((struct basetype *)(((struct basetype *)__1tt ))))-> b_name__8basetype ;
__3cl = (((struct classdef *)(((struct classdef *)__3cn -> __O1__4expr.tp ))));
__3icn = 0 ;

# 2410 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> __O2__4expr.e1 ){ 
# 2411 "/home/claude/cfront-3/src/expr2.cpp"
if ((__0this -> __O2__4expr.e1 -> __O3__4expr.e2 == 0 )&& (__0this -> __O2__4expr.e1 -> base__4node == 140 )){ 
# 2412 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O2__4expr.e1 =
# 2412 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O2__4expr.e1 -> __O2__4expr.e1 ;
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
}
__3icn = ((__0this -> __O2__4expr.e1 -> base__4node != 140 )?is_cl_obj__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) :(((struct name *)0 )));
}

# 2419 "/home/claude/cfront-3/src/expr2.cpp"
{ Pclass __3icl ;

# 2419 "/home/claude/cfront-3/src/expr2.cpp"
__3icl = (__3icn ?(((struct classdef *)(((struct classdef *)__3icn -> __O1__4expr.tp )))):(((struct classdef *)0 )));

# 2421 "/home/claude/cfront-3/src/expr2.cpp"
if (__3cl -> c_abstract__8classdef ){ 
# 2421 "/home/claude/cfront-3/src/expr2.cpp"
const void *__2__X219 ;

# 2422 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2422 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V209 ;

# 2422 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"`new' of abstractC%t", (const struct ea *)( ((& __0__V209 )-> __O1__2ea.p =
# 2422 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__3cl )), (& __0__V209 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2422 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
{ 
# 2423 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V210 ;

# 2423 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V211 ;

# 2423 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCcRC2eaN33 ( (int )'C' , (const char *)"%a is a pure virtualF ofC%t\n", (const struct ea *)( (__2__X219 =
# 2423 "/home/claude/cfront-3/src/expr2.cpp"
(const void *)__3cl -> c_abstract__8classdef ), ( ((& __0__V210 )-> __O1__2ea.p = __2__X219 ), (& __0__V210 )) ) , (const
# 2423 "/home/claude/cfront-3/src/expr2.cpp"
struct ea *)( ((& __0__V211 )-> __O1__2ea.p = ((const void *)__3cl )), (& __0__V211 )) , (const struct ea *)ea0 ,
# 2423 "/home/claude/cfront-3/src/expr2.cpp"
(const struct ea *)ea0 ) ;
break ;
} } }

# 2427 "/home/claude/cfront-3/src/expr2.cpp"
if (__1v && __0this -> __O2__4expr.e1 ){ 
# 2428 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCc ( (const char *)"Ir for array ofCO created using \"new\"")
# 2428 "/home/claude/cfront-3/src/expr2.cpp"
;
break ;
}

# 2432 "/home/claude/cfront-3/src/expr2.cpp"
if ((__3cl -> defined__4type & 3)== 0 ){ 
# 2433 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2433 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V212 ;

# 2433 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V213 ;

# 2433 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"new%n;%n isU", (const struct ea *)( ((& __0__V212 )-> __O1__2ea.p =
# 2433 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__3cn )), (& __0__V212 )) , (const struct ea *)( ((& __0__V213 )-> __O1__2ea.p = ((const void
# 2433 "/home/claude/cfront-3/src/expr2.cpp"
*)__3cn )), (& __0__V213 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
} }

# 2437 "/home/claude/cfront-3/src/expr2.cpp"
{ Pname __3ctor ;

# 2437 "/home/claude/cfront-3/src/expr2.cpp"
__3ctor = ( __3cl -> c_ctor__8classdef ) ;

# 2439 "/home/claude/cfront-3/src/expr2.cpp"
if (__3ctor ){ 
# 2439 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X220 ;

# 2439 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X221 ;

# 2440 "/home/claude/cfront-3/src/expr2.cpp"
if (__1v ){ 
# 2441 "/home/claude/cfront-3/src/expr2.cpp"
Pname __5ic ;
if ((__5ic = has_ictor__8classdefFv ( __3cl ) )== 0 ){ 
# 2443 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2443 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V214 ;

# 2443 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"array ofC%n that does not have aK taking noAs", (const struct ea *)( ((& __0__V214 )-> __O1__2ea.p =
# 2443 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__3cn )), (& __0__V214 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2443 "/home/claude/cfront-3/src/expr2.cpp"
ea *)ea0 ) ;
break ;
} }

# 2447 "/home/claude/cfront-3/src/expr2.cpp"
if ((((struct fct *)(((struct fct *)__5ic -> __O1__4expr.tp ))))-> nargs__3fct ){ 
# 2448 "/home/claude/cfront-3/src/expr2.cpp"
if (! ( __3cl -> c_vtor__8classdef ) )make_vec_ctor__8classdefFP4name ( __3cl ,
# 2448 "/home/claude/cfront-3/src/expr2.cpp"
__5ic ) ;
break ;
}
}

# 2453 "/home/claude/cfront-3/src/expr2.cpp"
if ((__3icl && (( __3cl -> c_itor__8classdef ) == 0 ))&& (( (__1__X220 = __3icl ), ( (__1__X221 = __3cl ), (
# 2453 "/home/claude/cfront-3/src/expr2.cpp"
((__1__X220 == __1__X221 )?1 :((__1__X220 && __1__X221 )?(((int )same_class__8classdefFP8classdefi ( __1__X220 , __1__X221 , 0 ) )):0 ))) ) ) || has_base__8classdefFP8classdefiT2 ( __3icl , __3cl ,
# 2453 "/home/claude/cfront-3/src/expr2.cpp"
0 , 0 ) ))
# 2457 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2458 "/home/claude/cfront-3/src/expr2.cpp"
__1init = 1 ;
break ;
}

# 2466 "/home/claude/cfront-3/src/expr2.cpp"
if (perf_opt && (! __1v )){ 
# 2475 "/home/claude/cfront-3/src/expr2.cpp"
extern int New_in_arg_list ;
if (New_in_arg_list )
# 2477 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCc ( (int )'s' , (const char *)"optimization option does not allow new as a default argument\n") ;

# 2480 "/home/claude/cfront-3/src/expr2.cpp"
{ Pexpr __5p ;
Pexpr __5args ;
Pexpr __5sz ;

# 2483 "/home/claude/cfront-3/src/expr2.cpp"
struct texpr *__0__X225 ;

# 2481 "/home/claude/cfront-3/src/expr2.cpp"
__5args = __0this -> __O3__4expr.e2 ;
__5sz = (struct expr *)( (__0__X225 = 0 ), ( ((__0__X225 || (__0__X225 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 2482 "/home/claude/cfront-3/src/expr2.cpp"
))?( (__0__X225 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X225 ), ((unsigned char )30 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 2482 "/home/claude/cfront-3/src/expr2.cpp"
(__0__X225 -> __O4__4expr.tp2 = __1tt )) :0 ), __0__X225 ) ) ;
((void )tsizeof__4typeFi ( __1tt , 0 ) );
__5sz -> __O1__4expr.tp = (struct type *)uint_type ;
{ Pexpr __5ee ;
const char *__5s ;
Pname __5n ;

# 2488 "/home/claude/cfront-3/src/expr2.cpp"
struct call *__0__X222 ;

# 2488 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X223 ;

# 2488 "/home/claude/cfront-3/src/expr2.cpp"
struct expr *__2__X224 ;

# 2485 "/home/claude/cfront-3/src/expr2.cpp"
__5ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __5sz , __5args ) ;
__5s = oper_name__FUc ( (unsigned char )23 ) ;
__5n = __ct__4nameFPCc ( (struct name *)0 , __5s ) ;
if (__0this -> base__4node == 184 )
# 2489 "/home/claude/cfront-3/src/expr2.cpp"
__5p = (struct expr *)look__5tableFPCcUc ( gtbl , __5s , (unsigned char )0 ) ;
else 
# 2491 "/home/claude/cfront-3/src/expr2.cpp"
__5p = find_name__FP4nameP8classdefP5tableiT1 ( __5n , __3cl , __3cl -> memtbl__8classdef , 109 , cc -> nof__11dcl_context ) ;
__5ee = (struct expr *)( (__0__X222 = 0 ), ( (__2__X223 = __5p ), ( (__2__X224 = __5ee ), ( ((__0__X222 || (__0__X222 =
# 2492 "/home/claude/cfront-3/src/expr2.cpp"
(struct call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X222 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X222 ), (unsigned char )109 ,
# 2492 "/home/claude/cfront-3/src/expr2.cpp"
__2__X223 , __2__X224 ) ):0 ), __0__X222 ) ) ) ) ;
overFound = 0 ;
((void )call_fct__4exprFP5table ( __5ee , __3cl -> memtbl__8classdef ) );
if ((overFound && (overFound -> n_scope__4name != 14 ))&& (overFound -> n_scope__4name != 31 ))
# 2497 "/home/claude/cfront-3/src/expr2.cpp"
check_visibility__FP4nameT1P8classdefP5tableT1 ( overFound , (struct name *)0 , (((struct fct *)(((struct fct *)overFound ->
# 2497 "/home/claude/cfront-3/src/expr2.cpp"
__O1__4expr.tp ))))-> memof__3fct , cc -> ftbl__11dcl_context , cc -> nof__11dcl_context ) ;
overFound = 0 ;
{ Ptype __5cobj_ptr ;
Pname __5cobj_tmp ;
Pname __5tn ;

# 2499 "/home/claude/cfront-3/src/expr2.cpp"
__5cobj_ptr = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __1tt ) ;

# 2501 "/home/claude/cfront-3/src/expr2.cpp"
__5tn = __1tbl -> t_name__5table ;

# 2505 "/home/claude/cfront-3/src/expr2.cpp"
if (__5tn && __5tn -> __O1__4expr.tp ){ 
# 2506 "/home/claude/cfront-3/src/expr2.cpp"
__5cobj_tmp = make_tmp__FcP4typeP5table ( 'B' , __5cobj_ptr , gtbl ) ;
}
else 
# 2509 "/home/claude/cfront-3/src/expr2.cpp"
__5cobj_tmp = make_tmp__FcP4typeP5table ( 'B' , __5cobj_ptr , __1tbl ) ;
__5cobj_tmp -> n_assigned_to__4name = 1 ;
__5cobj_tmp -> n_used__4name = 1 ;
{ Pexpr __5ctor_expr ;

# 2512 "/home/claude/cfront-3/src/expr2.cpp"
__5ctor_expr = call_ctor__FP5tableP4exprN22iT2 ( __1tbl , (struct expr *)__5cobj_tmp , (struct expr *)__3ctor , __0this -> __O2__4expr.e1 , 44 , (struct expr *)0 ) ;
__5ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__5cobj_tmp , __5ee ) ;
__5ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )66 , __5ee , __5ctor_expr ) ;
__5ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __5ee , (struct expr *)__5cobj_tmp ) ;
__0this -> __O2__4expr.e1 = __5ee ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = __5cobj_ptr ;
return __0this -> __O2__4expr.e1 ;

# 2518 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2518 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2518 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2518 "/home/claude/cfront-3/src/expr2.cpp"
}
}
else { 
# 2521 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O2__4expr.e1 = call_ctor__FP5tableP4exprN22iT2 ( __1tbl , (struct expr *)0 , (struct expr *)__3ctor , __0this -> __O2__4expr.e1 , 44 , (struct
# 2521 "/home/claude/cfront-3/src/expr2.cpp"
expr *)0 ) ;
}
}
else if (__0this -> __O2__4expr.e1 ){ 
# 2524 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X226 ;

# 2524 "/home/claude/cfront-3/src/expr2.cpp"
struct classdef *__1__X227 ;

# 2525 "/home/claude/cfront-3/src/expr2.cpp"
if (( (__1__X226 = __3icl ), ( (__1__X227 = __3cl ), ( ((__1__X226 == __1__X227 )?1 :((__1__X226 && __1__X227 )?(((int )same_class__8classdefFP8classdefi ( __1__X226 , __1__X227 ,
# 2525 "/home/claude/cfront-3/src/expr2.cpp"
0 ) )):0 ))) ) ) || has_base__8classdefFP8classdefiT2 ( __3icl , __3cl , 0 , 0 ) )
# 2526 "/home/claude/cfront-3/src/expr2.cpp"
__1init = 1 ;
else 
# 2528 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2528 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V215 ;

# 2528 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V216 ;

# 2528 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"new%n(As );%n does not have aK", (const struct ea *)( ((& __0__V215 )-> __O1__2ea.p =
# 2528 "/home/claude/cfront-3/src/expr2.cpp"
((const void *)__3cn )), (& __0__V215 )) , (const struct ea *)( ((& __0__V216 )-> __O1__2ea.p = ((const void
# 2528 "/home/claude/cfront-3/src/expr2.cpp"
*)__3cn )), (& __0__V216 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 2529 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2529 "/home/claude/cfront-3/src/expr2.cpp"
}
}
}

# 2533 "/home/claude/cfront-3/src/expr2.cpp"
if (__1init ){ 
# 2534 "/home/claude/cfront-3/src/expr2.cpp"
Pname __2tmp ;

# 2535 "/home/claude/cfront-3/src/expr2.cpp"
const void *__2__X228 ;

# 2534 "/home/claude/cfront-3/src/expr2.cpp"
__2tmp = make_tmp__FcP4typeP5table ( 'N' , (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __1tt ) ) ,
# 2534 "/home/claude/cfront-3/src/expr2.cpp"
__1tbl ) ;
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
if (check__4typeFP4typeUcT2 ( __1tt , __0this -> __O2__4expr.e1 -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) )
# 2537 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2537 "/home/claude/cfront-3/src/expr2.cpp"
struct
# 2537 "/home/claude/cfront-3/src/expr2.cpp"
ea __0__V217 ;

# 2537 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__V218 ;

# 2537 "/home/claude/cfront-3/src/expr2.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT%t for new operator (%t X)", (const struct ea *)( (__2__X228 = (const void
# 2537 "/home/claude/cfront-3/src/expr2.cpp"
*)__0this -> __O2__4expr.e1 -> __O1__4expr.tp ), ( ((& __0__V217 )-> __O1__2ea.p = __2__X228 ), (& __0__V217 )) ) , (const struct
# 2537 "/home/claude/cfront-3/src/expr2.cpp"
ea *)( ((& __0__V218 )-> __O1__2ea.p = ((const void *)__1tt )), (& __0__V218 )) , (const struct ea *)ea0 , (const
# 2537 "/home/claude/cfront-3/src/expr2.cpp"
struct ea *)ea0 ) ;
} if ((__0this -> __O2__4expr.e1 -> base__4node == 124 )|| (((__0this -> __O2__4expr.e1 -> base__4node == 140 )&& __0this -> __O2__4expr.e1 -> __O2__4expr.e1 )&& (__0this ->
# 2538 "/home/claude/cfront-3/src/expr2.cpp"
__O2__4expr.e1 -> __O2__4expr.e1 -> base__4node == 124 )))
# 2539 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2540 "/home/claude/cfront-3/src/expr2.cpp"
if (__0this -> __O2__4expr.e1 -> base__4node != 124 )
# 2541 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O2__4expr.e1 = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 ;
{ Pname __3tmp2 ;
Ptype __3t ;

# 2542 "/home/claude/cfront-3/src/expr2.cpp"
__3tmp2 = make_tmp__FcP4typeP5table ( 'A' , (struct type *)mptr_type , __1tbl ) ;
__3t = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
__0this -> __O2__4expr.e1 = mptr_assign__FP4exprT1 ( (struct expr *)__3tmp2 , __0this -> __O2__4expr.e1 ) ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __0this -> __O2__4expr.e1 , (struct expr *)__3tmp2 ) ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = __3t ;

# 2546 "/home/claude/cfront-3/src/expr2.cpp"
}
}
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )0 , (struct expr *)__2tmp , __0this -> __O2__4expr.e1 ) ;
assign__4nameFv ( __2tmp ) ;
if (ansi_opt && __2tmp -> __O1__4expr.tp ){ 
# 2551 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __3t ;

# 2551 "/home/claude/cfront-3/src/expr2.cpp"
__3t = __2tmp -> __O1__4expr.tp ;
if (is_ptr_or_ref__4typeFv ( __3t ) )
# 2553 "/home/claude/cfront-3/src/expr2.cpp"
__3t = (((struct ptr *)(((struct ptr *)__3t ))))-> typ__5pvtyp ;
__3t -> ansi_const__4type = 1 ;
}
}

# 2559 "/home/claude/cfront-3/src/expr2.cpp"
switch (__1v ){ 
# 2560 "/home/claude/cfront-3/src/expr2.cpp"
case 0 :
# 2561 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O1__4expr.tp = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __1tpx )
# 2561 "/home/claude/cfront-3/src/expr2.cpp"
) ;
break ;
case 1 :
# 2564 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O1__4expr.tp = __1tpx ;
break ;
default :
# 2567 "/home/claude/cfront-3/src/expr2.cpp"
__0this -> __O1__4expr.tp = __1tpx ;
}
return __0this ;
}

# 2572 "/home/claude/cfront-3/src/expr2.cpp"
static int is_dataMemPtr__FP4expr (Pexpr __1ee )
# 2577 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2578 "/home/claude/cfront-3/src/expr2.cpp"
Pexpr __1te ;

# 2578 "/home/claude/cfront-3/src/expr2.cpp"
__1te = __1ee -> __O2__4expr.e1 ;
if (__1te == 0 )return 0 ;
if (__1te -> base__4node != 54 )return 0 ;
if ((__1te = __1te -> __O3__4expr.e2 )== 0 )return 0 ;
if (__1te -> base__4node != 55 )return 0 ;
if ((__1te = __1te -> __O2__4expr.e1 )== 0 )return 0 ;
if ((__1te -> base__4node != 113 )&& (__1te -> base__4node != 191 ))return 0 ;
if ((__1te = __1te -> __O2__4expr.e1 )== 0 )return 0 ;
if (__1te -> __O1__4expr.tp -> base__4node != 125 )return 0 ;
if ((((struct ptr *)(((struct ptr *)__1te -> __O1__4expr.tp ))))-> memof__3ptr == 0 )return 0 ;
return 1 ;
}

# 42 "/home/claude/cfront-3/src/cfront.h"
extern int exact1__FP4nameP4type (Pname , Ptype );
extern int exact2__FP4nameP4type (Pname , Ptype );
extern int exact3__FP4nameP4type (Pname , Ptype );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 1288 "/home/claude/cfront-3/src/cfront.h"

# 2592 "/home/claude/cfront-3/src/expr2.cpp"

# 2600 "/home/claude/cfront-3/src/expr2.cpp"
static Pname compare_builtin__FP4typeT1P4nameN23i (Ptype __1t1 , Ptype __1t2 , Pname __1n1 , Pname __1n2 , Pname __1fname , int __1fo )
# 2606 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2607 "/home/claude/cfront-3/src/expr2.cpp"
if (__1fo == 5)return __1fname ;
{ bit __1binary ;
Pfct __1ff ;
TOK __1oper ;

# 2611 "/home/claude/cfront-3/src/expr2.cpp"
unsigned long __2__X16 ;

# 2611 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1400qm5qkxojwcnm ;

# 2611 "/home/claude/cfront-3/src/expr2.cpp"
struct ea __0__X__V1500qm5qkxojwcnm ;

# 2608 "/home/claude/cfront-3/src/expr2.cpp"
__1binary = ((__1t1 && __1t2 )?1 :0 );
__1ff = ( ((__1fname -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1fname -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 2609 "/home/claude/cfront-3/src/expr2.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qm5qkxojwcnm )-> __O1__2ea.p = ((const void *)__1fname )),
# 2609 "/home/claude/cfront-3/src/expr2.cpp"
(& __0__X__V1400qm5qkxojwcnm )) , (const struct ea *)( (__2__X16 = __1fname -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qm5qkxojwcnm )->
# 2609 "/home/claude/cfront-3/src/expr2.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qm5qkxojwcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 2609 "/home/claude/cfront-3/src/expr2.cpp"
, (((struct fct *)0 ))) )) ;
__1oper = __1fname -> n_oper__4name ;

# 2615 "/home/claude/cfront-3/src/expr2.cpp"
if ((((((((((((((__1oper == 111 )|| (__1oper == 109 ))|| (__1oper == 70 ))|| (__1oper == 44 ))|| (__1oper == 126 ))|| (__1oper == 127 ))|| (__1oper ==
# 2615 "/home/claude/cfront-3/src/expr2.cpp"
128 ))|| (__1oper == 129 ))|| (__1oper == 130 ))|| (__1oper == 131 ))|| (__1oper == 132 ))|| (__1oper == 133 ))|| (__1oper == 134 ))|| (__1oper ==
# 2615 "/home/claude/cfront-3/src/expr2.cpp"
135 ))
# 2630 "/home/claude/cfront-3/src/expr2.cpp"
return __1fname ;

# 2632 "/home/claude/cfront-3/src/expr2.cpp"
{ int __1t1eobj ;

# 2632 "/home/claude/cfront-3/src/expr2.cpp"
__1t1eobj = (__1t1 && (skiptypedefs__4typeFv ( __1t1 ) -> base__4node == 121 ));
if (__1t1eobj ){ 
# 2634 "/home/claude/cfront-3/src/expr2.cpp"
Pname __2n1 ;
Pclass __2c1 ;

# 2634 "/home/claude/cfront-3/src/expr2.cpp"
__2n1 = (__1t2 ?is_cl_obj__4typeFv ( __1t2 ) :(((struct name *)0 )));
__2c1 = (__2n1 ?(((struct classdef *)(((struct classdef *)__2n1 -> __O1__4expr.tp )))):(((struct classdef *)0 )));
if (__2c1 ){ 
# 2637 "/home/claude/cfront-3/src/expr2.cpp"
{ { Pname __3on1 ;

# 2637 "/home/claude/cfront-3/src/expr2.cpp"
__3on1 = __2c1 -> conv__8classdef ;

# 2637 "/home/claude/cfront-3/src/expr2.cpp"
for(;__3on1 ;__3on1 = __3on1 -> __O1__4name.n_list ) { 
# 2638 "/home/claude/cfront-3/src/expr2.cpp"
Pfct __4f ;
Ptype __4ret ;

# 2638 "/home/claude/cfront-3/src/expr2.cpp"
__4f = ( ((__3on1 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__3on1 -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__3on1 -> __O1__4expr.tp ))))->
# 2638 "/home/claude/cfront-3/src/expr2.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;
__4ret = (__4f ?__4f -> returns__3fct :(((struct type *)0 )));
if ((__4ret && (skiptypedefs__4typeFv ( __4ret ) -> base__4node == 121 ))&& (! check__4typeFP4typeUcT2 ( __4ret , skiptypedefs__4typeFv ( __1t1 ) , (unsigned
# 2640 "/home/claude/cfront-3/src/expr2.cpp"
char )70 , (unsigned char )0 ) ))
# 2641 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2642 "/home/claude/cfront-3/src/expr2.cpp"
__1t1eobj = 0 ;
break ;
}
}

# 2645 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2645 "/home/claude/cfront-3/src/expr2.cpp"
}
}
else { 
# 2648 "/home/claude/cfront-3/src/expr2.cpp"
__1t1eobj = 0 ;
}
}
{ int __1t2eobj ;

# 2651 "/home/claude/cfront-3/src/expr2.cpp"
__1t2eobj = (__1t2 && (skiptypedefs__4typeFv ( __1t2 ) -> base__4node == 121 ));
if (__1t2eobj ){ 
# 2653 "/home/claude/cfront-3/src/expr2.cpp"
Pname __2n1 ;
Pclass __2c1 ;

# 2653 "/home/claude/cfront-3/src/expr2.cpp"
__2n1 = (__1t1 ?is_cl_obj__4typeFv ( __1t1 ) :(((struct name *)0 )));
__2c1 = (__2n1 ?(((struct classdef *)(((struct classdef *)__2n1 -> __O1__4expr.tp )))):(((struct classdef *)0 )));
if (__2c1 ){ 
# 2656 "/home/claude/cfront-3/src/expr2.cpp"
{ { Pname __3on1 ;

# 2656 "/home/claude/cfront-3/src/expr2.cpp"
__3on1 = __2c1 -> conv__8classdef ;

# 2656 "/home/claude/cfront-3/src/expr2.cpp"
for(;__3on1 ;__3on1 = __3on1 -> __O1__4name.n_list ) { 
# 2657 "/home/claude/cfront-3/src/expr2.cpp"
Pfct __4f ;
Ptype __4ret ;

# 2657 "/home/claude/cfront-3/src/expr2.cpp"
__4f = ( ((__3on1 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__3on1 -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__3on1 -> __O1__4expr.tp ))))->
# 2657 "/home/claude/cfront-3/src/expr2.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;
__4ret = (__4f ?__4f -> returns__3fct :(((struct type *)0 )));
if ((__4ret && (skiptypedefs__4typeFv ( __4ret ) -> base__4node == 121 ))&& (! check__4typeFP4typeUcT2 ( __4ret , skiptypedefs__4typeFv ( __1t2 ) , (unsigned
# 2659 "/home/claude/cfront-3/src/expr2.cpp"
char )70 , (unsigned char )0 ) ))
# 2660 "/home/claude/cfront-3/src/expr2.cpp"
{ 
# 2661 "/home/claude/cfront-3/src/expr2.cpp"
__1t2eobj = 0 ;
break ;
}
}

# 2664 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2664 "/home/claude/cfront-3/src/expr2.cpp"
}
}
else { 
# 2667 "/home/claude/cfront-3/src/expr2.cpp"
__1t2eobj = 0 ;
}
}
{ int __1teobj ;

# 2670 "/home/claude/cfront-3/src/expr2.cpp"
__1teobj = (__1t1eobj || __1t2eobj );

# 2672 "/home/claude/cfront-3/src/expr2.cpp"
if (__1ff -> memof__3fct ){ 
# 2674 "/home/claude/cfront-3/src/expr2.cpp"
if ((! __1binary )|| __1n2 )return __1fname ;

# 2676 "/home/claude/cfront-3/src/expr2.cpp"
{ Pname __2nn ;

# 2676 "/home/claude/cfront-3/src/expr2.cpp"
__2nn = __1ff -> argtype__3fct ;

# 2678 "/home/claude/cfront-3/src/expr2.cpp"
if (((! __1teobj )&& exact1__FP4nameP4type ( __2nn , __1t2 ) )|| (__1teobj && exact2__FP4nameP4type ( __2nn , __1t2 ) ))
# 2679 "/home/claude/cfront-3/src/expr2.cpp"
return __1fname ;

# 2681 "/home/claude/cfront-3/src/expr2.cpp"
opov_error__FP4typeT1Uc ( __1t1 , __1t2 , __1oper ) ;
return __1fname ;

# 2682 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 2686 "/home/claude/cfront-3/src/expr2.cpp"
if (! __1binary ){ 
# 2687 "/home/claude/cfront-3/src/expr2.cpp"
if (__1fo == 2){ 
# 2688 "/home/claude/cfront-3/src/expr2.cpp"
opov_error__FP4typeT1Uc ( __1t1 , __1t2 , __1oper ) ;
return __1fname ;
}
}
else { 
# 2693 "/home/claude/cfront-3/src/expr2.cpp"
if (__1n1 && __1n2 ){ 
# 2694 "/home/claude/cfront-3/src/expr2.cpp"
if (__1fo < 2)return __1fname ;
{ Pname __3nn1 ;
Pname __3nn2 ;

# 2695 "/home/claude/cfront-3/src/expr2.cpp"
__3nn1 = __1ff -> argtype__3fct ;
__3nn2 = __3nn1 -> __O1__4name.n_list ;
if (( (((exact1__FP4nameP4type ( __3nn1 , __1t1 ) || exact2__FP4nameP4type ( __3nn1 , __1t1 ) )|| exact3__FP4nameP4type ( __3nn1 , __1t1 ) )?(((unsigned
# 2697 "/home/claude/cfront-3/src/expr2.cpp"
char )1 )):(((unsigned char )0 )))) || ( (((exact1__FP4nameP4type ( __3nn2 , __1t2 ) || exact2__FP4nameP4type ( __3nn2 , __1t2 ) )||
# 2697 "/home/claude/cfront-3/src/expr2.cpp"
exact3__FP4nameP4type ( __3nn2 , __1t2 ) )?(((unsigned char )1 )):(((unsigned char )0 )))) ){ 
# 2698 "/home/claude/cfront-3/src/expr2.cpp"
return __1fname ;
}
else { 
# 2701 "/home/claude/cfront-3/src/expr2.cpp"
opov_error__FP4typeT1Uc ( __1t1 , __1t2 , __1oper ) ;
return __1fname ;
}

# 2703 "/home/claude/cfront-3/src/expr2.cpp"
}
}
else { 
# 2706 "/home/claude/cfront-3/src/expr2.cpp"
Pname __3carg ;

# 2706 "/home/claude/cfront-3/src/expr2.cpp"
Pname __3oarg ;
Ptype __3ct ;

# 2707 "/home/claude/cfront-3/src/expr2.cpp"
Ptype __3ot ;
if (__1n1 ){ 
# 2709 "/home/claude/cfront-3/src/expr2.cpp"
__3carg = __1ff -> argtype__3fct ;
__3ct = __1t1 ;
__3oarg = __3carg -> __O1__4name.n_list ;
__3ot = __1t2 ;
}
else { 
# 2715 "/home/claude/cfront-3/src/expr2.cpp"
__3oarg = __1ff -> argtype__3fct ;
__3ot = __1t1 ;
__3carg = __3oarg -> __O1__4name.n_list ;
__3ct = __1t2 ;
}

# 2721 "/home/claude/cfront-3/src/expr2.cpp"
if (( (((exact1__FP4nameP4type ( __3carg , __3ct ) || exact2__FP4nameP4type ( __3carg , __3ct ) )|| exact3__FP4nameP4type ( __3carg , __3ct ) )?(((unsigned
# 2721 "/home/claude/cfront-3/src/expr2.cpp"
char )1 )):(((unsigned char )0 )))) ){ 
# 2722 "/home/claude/cfront-3/src/expr2.cpp"
if (((! __1teobj )&& (! exact1__FP4nameP4type ( __3oarg , __3ot ) ))|| (__1teobj &&
# 2722 "/home/claude/cfront-3/src/expr2.cpp"
(! exact2__FP4nameP4type ( __3oarg , __3ot ) )))
# 2724 "/home/claude/cfront-3/src/expr2.cpp"
opov_error__FP4typeT1Uc ( __1t1 , __1t2 , __1oper ) ;
return __1fname ;
}
else { 
# 2728 "/home/claude/cfront-3/src/expr2.cpp"
if (((! __1teobj )&& exact1__FP4nameP4type ( __3oarg , __3ot ) )|| (__1teobj && exact2__FP4nameP4type ( __3oarg , __3ot ) ))
# 2729 "/home/claude/cfront-3/src/expr2.cpp"
{
# 2729 "/home/claude/cfront-3/src/expr2.cpp"

# 2730 "/home/claude/cfront-3/src/expr2.cpp"
opov_error__FP4typeT1Uc ( __1t1 , __1t2 , __1oper ) ;
return __1fname ;
}
else return (struct name *)0 ;
}
}
}

# 2738 "/home/claude/cfront-3/src/expr2.cpp"
error__FiPCc ( (int )'i' , (const char *)"fall off end of compare_builtin()") ;
return (struct name *)0 ;

# 2739 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2739 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2739 "/home/claude/cfront-3/src/expr2.cpp"
}

# 2739 "/home/claude/cfront-3/src/expr2.cpp"
}
}

# 39 "/home/claude/cfront-3/src/overload.h"
static void __dt__11Block_PnameFv (struct Block_Pname *__0this , 
# 39 "/home/claude/cfront-3/src/overload.h"
int __0__free ){ 
# 39 "/home/claude/cfront-3/src/overload.h"
if (__0this ){ __dl__FPv ( (void *)__0this -> p__11Block_Pname ) ;

# 39 "/home/claude/cfront-3/src/overload.h"
if (__0this )if (__0__free & 1)__dl__FPv ( (void *)__0this ) ;
} 
# 39 "/home/claude/cfront-3/src/overload.h"
}

# 39 "/home/claude/cfront-3/src/overload.h"
static struct Block_Pname *__ct__11Block_PnameFv (struct Block_Pname *__0this ){ if (__0this || (__0this = (struct Block_Pname *)__nw__FUl ( (size_t )(sizeof (struct Block_Pname)))
# 39 "/home/claude/cfront-3/src/overload.h"
)){ __0this -> n__11Block_Pname = 0 ;

# 39 "/home/claude/cfront-3/src/overload.h"
__0this -> p__11Block_Pname = 0 ;
} 
# 39 "/home/claude/cfront-3/src/overload.h"
return __0this ;

# 39 "/home/claude/cfront-3/src/overload.h"
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
char __W37__17templ_compilation ;
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

# 2740 "/home/claude/cfront-3/src/expr2.cpp"

/* the end */
