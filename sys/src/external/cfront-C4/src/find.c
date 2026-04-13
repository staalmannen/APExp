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

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 633 "/home/claude/cfront-3/src/cfront.h"
struct fct *__ct__3fctFP4typeP4nameUc (struct fct *__0this , Ptype , Pname , TOK );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 25 "/home/claude/cfront-3/src/find.cpp"
Pname undef__FP4nameP5tableUc (Pname __1n , Ptable __1tbl , TOK __1f )
# 26 "/home/claude/cfront-3/src/find.cpp"
{ 
# 27 "/home/claude/cfront-3/src/find.cpp"
switch (__1f ){ 
# 27 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X31 ;

# 28 "/home/claude/cfront-3/src/find.cpp"
case 84 :
# 29 "/home/claude/cfront-3/src/find.cpp"
{ 
# 29 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V26 ;

# 29 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"illegalF call: explicit call ofK %s()", (const struct ea *)( (__2__X31 = (const void
# 29 "/home/claude/cfront-3/src/find.cpp"
*)__1n -> __O2__4expr.string ), ( ((& __0__V26 )-> __O1__2ea.p = __2__X31 ), (& __0__V26 )) ) , (const struct ea *)ea0 ,
# 29 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
case 0 :{ 
# 31 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V27 ;

# 31 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%nU", (const struct ea *)( ((& __0__V27 )-> __O1__2ea.p =
# 31 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1n )), (& __0__V27 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 31 "/home/claude/cfront-3/src/find.cpp"
ea *)ea0 ) ;

# 31 "/home/claude/cfront-3/src/find.cpp"
break ;
case 109 :{ 
# 32 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V28 ;

# 32 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"UF%n called", (const struct ea *)( ((& __0__V28 )-> __O1__2ea.p =
# 32 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1n )), (& __0__V28 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 32 "/home/claude/cfront-3/src/find.cpp"
ea *)ea0 ) ;

# 32 "/home/claude/cfront-3/src/find.cpp"
break ;
case 44 :
# 34 "/home/claude/cfront-3/src/find.cpp"
case 45 :{ 
# 34 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V29 ;

# 34 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"M%nU", (const struct ea *)( ((& __0__V29 )-> __O1__2ea.p =
# 34 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1n )), (& __0__V29 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 34 "/home/claude/cfront-3/src/find.cpp"
ea *)ea0 ) ;

# 34 "/home/claude/cfront-3/src/find.cpp"
break ;
case 112 :{ 
# 35 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V30 ;

# 35 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"address ofU%n", (const struct ea *)( ((& __0__V30 )-> __O1__2ea.p =
# 35 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1n )), (& __0__V30 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 35 "/home/claude/cfront-3/src/find.cpp"
ea *)ea0 ) ;

# 35 "/home/claude/cfront-3/src/find.cpp"
break ;
} } } } } }

# 38 "/home/claude/cfront-3/src/find.cpp"
if (__1tbl == gtbl ){ 
# 39 "/home/claude/cfront-3/src/find.cpp"
Pname __2nn ;

# 39 "/home/claude/cfront-3/src/find.cpp"
__2nn = insert__5tableFP4nameUc ( __1tbl , __1n , (unsigned char )0 ) ;
if (__1f == 109 ){ 
# 41 "/home/claude/cfront-3/src/find.cpp"
__2nn -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)defa_type , (struct name *)0 , (unsigned
# 41 "/home/claude/cfront-3/src/find.cpp"
char )0 ) ;
__2nn -> n_sto__4name = (__2nn -> n_scope__4name = 14 );
}
else 
# 45 "/home/claude/cfront-3/src/find.cpp"
__2nn -> __O1__4expr.tp = (struct type *)any_type ;
( (__1n ?(((void )(__1n ?(((void )( ( ((((struct expr *)__1n ))?(((void )((((struct expr *)__1n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 46 "/home/claude/cfront-3/src/find.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1n , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
return __2nn ;
}

# 50 "/home/claude/cfront-3/src/find.cpp"
__1n -> __O4__4expr.n_table = __1tbl ;
__1n -> __O1__4expr.tp = (struct type *)any_type ;
return __1n ;
}

# 57 "/home/claude/cfront-3/src/find.cpp"
static int mptr ;
static Pname me ;
static Pfct mef ;
Pclass tcl = 0 ;
Pclass mec = 0 ;
int mex = 0 ;

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 348 "/home/claude/cfront-3/src/cfront.h"
bit is_const_object__4typeFv (struct type *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 66 "/home/claude/cfront-3/src/find.cpp"
static void check_local_nested_ref__FP4nameUc3loc (Pname __1nn , TOK __1f , struct loc __1where )
# 68 "/home/claude/cfront-3/src/find.cpp"
{ 
# 69 "/home/claude/cfront-3/src/find.cpp"
if (processing_sizeof )return ;

# 72 "/home/claude/cfront-3/src/find.cpp"
switch (__1nn -> n_scope__4name ){ 
# 73 "/home/claude/cfront-3/src/find.cpp"
case 136 :
# 74 "/home/claude/cfront-3/src/find.cpp"
{ 
# 74 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V32 ;

# 74 "/home/claude/cfront-3/src/find.cpp"
error__FP3locPCcRC2eaN33 ( & __1where , (const char *)"automatic variable%n referenced in localC", (const struct ea *)( ((&
# 74 "/home/claude/cfront-3/src/find.cpp"
__0__V32 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V32 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 74 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 ) ;
break ;
case 108 :
# 77 "/home/claude/cfront-3/src/find.cpp"
if (((__1nn -> n_sto__4name != 31 )&& (__1nn -> n_sto__4name != 14 ))&& (__1nn -> n_stclass__4name != 13 ))
# 80 "/home/claude/cfront-3/src/find.cpp"
{ 
# 81 "/home/claude/cfront-3/src/find.cpp"
switch (skiptypedefs__4typeFv ( __1nn ->
# 81 "/home/claude/cfront-3/src/find.cpp"
__O1__4expr.tp ) -> base__4node ){ 
# 82 "/home/claude/cfront-3/src/find.cpp"
case 108 :case 76 :
# 83 "/home/claude/cfront-3/src/find.cpp"
break ;
default :
# 85 "/home/claude/cfront-3/src/find.cpp"
if (! is_const_object__4typeFv ( __1nn -> __O1__4expr.tp ) )
# 86 "/home/claude/cfront-3/src/find.cpp"
{ 
# 86 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V33 ;

# 86 "/home/claude/cfront-3/src/find.cpp"
error__FP3locPCcRC2eaN33 ( & __1where , (const char *)"automatic variable%n referenced in localC", (const struct ea *)( ((&
# 86 "/home/claude/cfront-3/src/find.cpp"
__0__V33 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V33 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 86 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 ) ;
} else if (__1f == 112 )
# 88 "/home/claude/cfront-3/src/find.cpp"
{ 
# 88 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V34 ;

# 88 "/home/claude/cfront-3/src/find.cpp"
error__FP3locPCcRC2eaN33 ( & __1where , (const char *)"address of local const%n in localC", (const struct ea *)( ((&
# 88 "/home/claude/cfront-3/src/find.cpp"
__0__V34 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V34 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 88 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 ) ;
} }
}
break ;
case 0 :case 25 :
# 95 "/home/claude/cfront-3/src/find.cpp"
break ;
} }
}

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 804 "/home/claude/cfront-3/src/cfront.h"
Pexpr contents__4exprFv (struct expr *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 463 "/home/claude/cfront-3/src/cfront.h"
Pclass is_base__8classdefFPCcPUci (struct classdef *__0this , const char *, TOK *, int __1level );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 473 "/home/claude/cfront-3/src/cfront.h"
Pexpr find_name__8classdefFPCcP8classdefiT3 (struct classdef *__0this , const char *, Pclass , int , int );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 959 "/home/claude/cfront-3/src/cfront.h"
void del__4nameFv (struct name *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 236 "/home/claude/cfront-3/src/cfront.h"
const char *whatami__5tableFv (struct table *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 99 "/home/claude/cfront-3/src/find.cpp"
Pexpr find_name__FP4nameP8classdefP5tableiT1 (Pname __1n , Pclass __1cl , Ptable __1tbl , int __1f , Pname __1m )
# 113 "/home/claude/cfront-3/src/find.cpp"
{ 
# 114 "/home/claude/cfront-3/src/find.cpp"
if (__1n == 0 )
# 115 "/home/claude/cfront-3/src/find.cpp"
{ 
# 115 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V35 ;

# 115 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V36 ;

# 115 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V37 ;

# 115 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V38 ;

# 115 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"find_name(n==0,cl==%t,tbl==%d,f==%k,m==%n)", (const struct ea *)( ((&
# 115 "/home/claude/cfront-3/src/find.cpp"
__0__V35 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V35 )) , (const struct ea *)( ((& __0__V36 )-> __O1__2ea.p =
# 115 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1tbl )), (& __0__V36 )) , (const struct ea *)( (( ((& __0__V37 )-> __O1__2ea.i = ((unsigned
# 115 "/home/claude/cfront-3/src/find.cpp"
long )__1f )), 0 ) ), (& __0__V37 )) , (const struct ea *)( ((& __0__V38 )-> __O1__2ea.p = ((const
# 115 "/home/claude/cfront-3/src/find.cpp"
void *)__1m )), (& __0__V38 )) ) ;
} { Pname __1q ;
const char *__1s ;
Pfct __1mf ;
Pname __1tnrv ;

# 131 "/home/claude/cfront-3/src/find.cpp"
Pexpr __1ee ;

# 132 "/home/claude/cfront-3/src/find.cpp"
unsigned long __2__X16 ;

# 132 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__X__V1400qm5kwanawcnm ;

# 132 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__X__V1500qm5kwanawcnm ;

# 116 "/home/claude/cfront-3/src/find.cpp"
__1q = __1n -> __O2__4name.n_qualifier ;
__1s = __1n -> __O2__4expr.string ;
__1mf = (__1m ?( ((__1m -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1m -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 118 "/home/claude/cfront-3/src/find.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qm5kwanawcnm )-> __O1__2ea.p = ((const void *)__1m )),
# 118 "/home/claude/cfront-3/src/find.cpp"
(& __0__X__V1400qm5kwanawcnm )) , (const struct ea *)( (__2__X16 = __1m -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qm5kwanawcnm )->
# 118 "/home/claude/cfront-3/src/find.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qm5kwanawcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 118 "/home/claude/cfront-3/src/find.cpp"
, (((struct fct *)0 ))) )) :(((struct fct *)0 )));

# 121 "/home/claude/cfront-3/src/find.cpp"
if ((((((__1mf && __1mf -> nrv__3fct )&& (! __1q ))&& (__1f != 45 ))&& (__1f != 44 ))&& (strcmp ( __1mf -> nrv__3fct -> __O2__4expr.string ,
# 121 "/home/claude/cfront-3/src/find.cpp"
__1s ) == 0 ))&& (((__1tnrv = look__5tableFPCcUc ( __1tbl , __1s , (unsigned char )0 ) )== 0 )|| (__1tnrv -> __O4__4expr.n_table ==
# 121 "/home/claude/cfront-3/src/find.cpp"
gtbl )))
# 129 "/home/claude/cfront-3/src/find.cpp"
return contents__4exprFv ( (struct expr *)__1mf -> f_result__3fct ) ;

# 131 "/home/claude/cfront-3/src/find.cpp"
;

# 136 "/home/claude/cfront-3/src/find.cpp"
;

# 138 "/home/claude/cfront-3/src/find.cpp"
tcl = __1cl ;

# 140 "/home/claude/cfront-3/src/find.cpp"
mex = 1 ;
if (me = __1m ){ 
# 141 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X76 ;

# 141 "/home/claude/cfront-3/src/find.cpp"
unsigned long __2__X77 ;

# 142 "/home/claude/cfront-3/src/find.cpp"
mef = (((struct fct *)(((struct fct *)me -> __O1__4expr.tp ))));
if (mef -> base__4node != 108 )
# 144 "/home/claude/cfront-3/src/find.cpp"
{ 
# 144 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V39 ;

# 144 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V40 ;

# 144 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"mef %d %k", (const struct ea *)( (__2__X76 =
# 144 "/home/claude/cfront-3/src/find.cpp"
(const void *)mef ), ( ((& __0__V39 )-> __O1__2ea.p = __2__X76 ), (& __0__V39 )) ) , (const struct
# 144 "/home/claude/cfront-3/src/find.cpp"
ea *)( (__2__X77 = mef -> base__4node ), ( (( ((& __0__V40 )-> __O1__2ea.i = __2__X77 ), 0 ) ), (& __0__V40 ))
# 144 "/home/claude/cfront-3/src/find.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (cc -> cot__11dcl_context && (cc -> cot__11dcl_context -> lex_level__4type > __1m -> lex_level__4name ))
# 147 "/home/claude/cfront-3/src/find.cpp"
mec = cc -> cot__11dcl_context ;
else mec = mef -> memof__3fct ;
}
else 
# 151 "/home/claude/cfront-3/src/find.cpp"
{ 
# 152 "/home/claude/cfront-3/src/find.cpp"
mef = 0 ;
if ((! __1tbl )&& ((__1f == 45 )|| (__1f == 44 )))
# 154 "/home/claude/cfront-3/src/find.cpp"
mec = cc -> cot__11dcl_context ;
else { 
# 156 "/home/claude/cfront-3/src/find.cpp"
if (((((__1q == 0 )&& (__1cl == 0 ))&& __1tbl )&& (__1tbl != gtbl ))&& __1tbl -> t_name__5table ){ 
# 164 "/home/claude/cfront-3/src/find.cpp"
__1cl = (((struct
# 164 "/home/claude/cfront-3/src/find.cpp"
classdef *)(((struct classdef *)__1tbl -> t_name__5table -> __O1__4expr.tp ))));
if (__1cl -> base__4node != 6 ){ 
# 165 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V41 ;

# 165 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V42 ;

# 165 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V43 ;

# 165 "/home/claude/cfront-3/src/find.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"find_name(%n, 0, %d,%k, 0 ) --CTX for table", (const
# 165 "/home/claude/cfront-3/src/find.cpp"
struct ea *)( ((& __0__V41 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V41 )) , (const struct ea *)(
# 165 "/home/claude/cfront-3/src/find.cpp"
((& __0__V42 )-> __O1__2ea.p = ((const void *)__1tbl )), (& __0__V42 )) , (const struct ea *)( (( ((&
# 165 "/home/claude/cfront-3/src/find.cpp"
__0__V43 )-> __O1__2ea.i = ((unsigned long )__1f )), 0 ) ), (& __0__V43 )) , (const struct ea *)ea0 ) ;
# 165 "/home/claude/cfront-3/src/find.cpp"
} 
# 166 "/home/claude/cfront-3/src/find.cpp"
}
mec = __1cl ;
}
}

# 171 "/home/claude/cfront-3/src/find.cpp"
if (__1n -> base__4node == 177 ){ 
# 171 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V44 ;

# 171 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"find (mdot%n)", (const struct ea *)( ((&
# 171 "/home/claude/cfront-3/src/find.cpp"
__0__V44 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V44 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 171 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 ) ;
} 
# 173 "/home/claude/cfront-3/src/find.cpp"
if (__1n -> __O4__4expr.n_table ){ me = 0 ;

# 173 "/home/claude/cfront-3/src/find.cpp"
return (struct expr *)__1n ;

# 173 "/home/claude/cfront-3/src/find.cpp"
}

# 175 "/home/claude/cfront-3/src/find.cpp"
if ((me == 0 )&& ((__1tbl == gtbl )|| (cc -> nof__11dcl_context == 0 )))
# 176 "/home/claude/cfront-3/src/find.cpp"
me = dummy_fct ;

# 179 "/home/claude/cfront-3/src/find.cpp"
if (__1q ){ 
# 181 "/home/claude/cfront-3/src/find.cpp"
if (__1q == sta_name ){ 
# 182 "/home/claude/cfront-3/src/find.cpp"
Pname __3nn ;

# 182 "/home/claude/cfront-3/src/find.cpp"
__3nn = look__5tableFPCcUc ( gtbl , __1s , (unsigned char )0 ) ;
if (__3nn == 0 ){ me = 0 ;

# 183 "/home/claude/cfront-3/src/find.cpp"
return (struct expr *)undef__FP4nameP5tableUc ( __1n , gtbl , (unsigned char )__1f ) ;

# 183 "/home/claude/cfront-3/src/find.cpp"
}
( (__3nn -> n_used__4name ++ ), (((void )0 ))) ;
( (__1n ?(((void )(__1n ?(((void )( ( ((((struct expr *)__1n ))?(((void )((((struct expr *)__1n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 185 "/home/claude/cfront-3/src/find.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1n , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
me = 0 ;
return (struct expr *)__3nn ;
}

# 190 "/home/claude/cfront-3/src/find.cpp"
{ 
# 191 "/home/claude/cfront-3/src/find.cpp"
Pname __3aq ;

# 191 "/home/claude/cfront-3/src/find.cpp"
__3aq = __1q ;
while (__3aq -> __O1__4expr.tp -> base__4node == 97 )__3aq = (((struct basetype *)(((struct basetype *)__3aq -> __O1__4expr.tp ))))-> b_name__8basetype ;
if (__3aq -> __O1__4expr.tp -> base__4node != 119 ){ 
# 194 "/home/claude/cfront-3/src/find.cpp"
if (__3aq -> n_template_arg__4name == 1)
# 195 "/home/claude/cfront-3/src/find.cpp"
{ 
# 195 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V45 ;

# 195 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V46 ;

# 195 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"use of %n::%sW formalYTZ", (const struct ea *)( ((&
# 195 "/home/claude/cfront-3/src/find.cpp"
__0__V45 )-> __O1__2ea.p = ((const void *)__3aq )), (& __0__V45 )) , (const struct ea *)( ((& __0__V46 )-> __O1__2ea.p =
# 195 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1s )), (& __0__V46 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 196 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V47 ;

# 196 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"Qr%n not aCN", (const struct ea *)( ((& __0__V47 )-> __O1__2ea.p =
# 196 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1q )), (& __0__V47 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 196 "/home/claude/cfront-3/src/find.cpp"
ea *)ea0 ) ;
} me = 0 ;
return (struct expr *)undef__FP4nameP5tableUc ( __1n , gtbl , (unsigned char )__1f ) ;
}
__1q = __3aq ;
}
{ Pclass __2qcl ;

# 204 "/home/claude/cfront-3/src/find.cpp"
Pclass __2bcl ;

# 205 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X82 ;

# 205 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X83 ;

# 205 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X84 ;

# 202 "/home/claude/cfront-3/src/find.cpp"
__2qcl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1q -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))));

# 204 "/home/claude/cfront-3/src/find.cpp"
__2bcl = __1cl ;

# 206 "/home/claude/cfront-3/src/find.cpp"
if ((__1cl == 0 )|| (__1f == 112 ))
# 207 "/home/claude/cfront-3/src/find.cpp"
__2bcl = (__1cl = __2qcl );
else { 
# 208 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X78 ;

# 208 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X79 ;

# 209 "/home/claude/cfront-3/src/find.cpp"
if (! ( (__1__X78 = __2qcl ), ( (__1__X79 = __1cl ), ( ((__1__X78 == __1__X79 )?1 :((__1__X78 && __1__X79 )?(((int )same_class__8classdefFP8classdefi ( __1__X78 ,
# 209 "/home/claude/cfront-3/src/find.cpp"
__1__X79 , 0 ) )):0 ))) ) ) ){ 
# 209 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X80 ;

# 209 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X81 ;

# 210 "/home/claude/cfront-3/src/find.cpp"
__2bcl = is_base__8classdefFPCcPUci ( __1cl , __2qcl -> string__8classdef , (TOK *)0 , 0 ) ;
if ((__2bcl == 0 )|| (! ( (__1__X80 = __2bcl ), ( (__1__X81 = __2qcl ), ( ((__1__X80 == __1__X81 )?1 :((__1__X80 && __1__X81 )?(((int
# 211 "/home/claude/cfront-3/src/find.cpp"
)same_class__8classdefFP8classdefi ( __1__X80 , __1__X81 , 0 ) )):0 ))) ) ) )){ 
# 212 "/home/claude/cfront-3/src/find.cpp"
if ((__1f == 44 )|| (__1f == 45 )){ 
# 213 "/home/claude/cfront-3/src/find.cpp"
{
# 213 "/home/claude/cfront-3/src/find.cpp"

# 213 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V48 ;

# 213 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V49 ;

# 213 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t is not aBC of%t", (const struct ea *)( ((& __0__V48 )-> __O1__2ea.p =
# 213 "/home/claude/cfront-3/src/find.cpp"
((const void *)__2qcl )), (& __0__V48 )) , (const struct ea *)( ((& __0__V49 )-> __O1__2ea.p = ((const void
# 213 "/home/claude/cfront-3/src/find.cpp"
*)__1cl )), (& __0__V49 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
me = 0 ;
return (struct expr *)undef__FP4nameP5tableUc ( __1n , __1cl -> memtbl__8classdef , (unsigned char )7 ) ;
} }
goto sss ;
}

# 220 "/home/claude/cfront-3/src/find.cpp"
}
}

# 223 "/home/claude/cfront-3/src/find.cpp"
if (__1f == 112 )mptr = 1 ;
__1ee = find_name__8classdefFPCcP8classdefiT3 ( __1cl , __1s , ( (__1__X82 = __2bcl ), ( (__1__X83 = __1cl ), ( ((__1__X82 == __1__X83 )?1 :((__1__X82 && __1__X83 )?(((int
# 224 "/home/claude/cfront-3/src/find.cpp"
)same_class__8classdefFP8classdefi ( __1__X82 , __1__X83 , 0 ) )):0 ))) ) ) ?(((struct classdef *)0 )):__2bcl , 0 , 0 ) ;

# 226 "/home/claude/cfront-3/src/find.cpp"
if (((__1ee && (__1ee -> base__4node == 85 ))&& ((((struct name *)(((struct name *)__1ee ))))-> n_stclass__4name != 31 ))&& is_ref__4typeFv ( __1ee -> __O1__4expr.tp ) )
# 230 "/home/claude/cfront-3/src/find.cpp"
{
# 230 "/home/claude/cfront-3/src/find.cpp"

# 230 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V50 ;

# 230 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V51 ;

# 230 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"P toRM: %s::%s", (const struct ea *)( (__2__X84 = (const void
# 230 "/home/claude/cfront-3/src/find.cpp"
*)__1cl -> string__8classdef ), ( ((& __0__V50 )-> __O1__2ea.p = __2__X84 ), (& __0__V50 )) ) , (const struct ea *)__ct__2eaFPCv (
# 230 "/home/claude/cfront-3/src/find.cpp"
& __0__V51 , (const void *)(((struct name *)(((struct name *)__1ee ))))-> __O2__4expr.string ) , (const struct ea *)ea0 , (const struct
# 230 "/home/claude/cfront-3/src/find.cpp"
ea *)ea0 ) ;
} 
# 232 "/home/claude/cfront-3/src/find.cpp"
mptr = 0 ;

# 234 "/home/claude/cfront-3/src/find.cpp"
if (__1ee == 0 ){ 
# 235 "/home/claude/cfront-3/src/find.cpp"
sss :
# 237 "/home/claude/cfront-3/src/find.cpp"
{ Pname __3nn ;

# 237 "/home/claude/cfront-3/src/find.cpp"
__3nn = look__5tableFPCcUc ( __2qcl -> memtbl__8classdef , __1s , (unsigned char )0 ) ;

# 239 "/home/claude/cfront-3/src/find.cpp"
if ((((__1f == 0 )&& ((((__3nn && __3nn -> __O1__4expr.tp )&& (__3nn -> __O1__4expr.tp -> base__4node != 121 ))&& (__3nn -> __O1__4expr.tp -> base__4node != 108 ))&&
# 239 "/home/claude/cfront-3/src/find.cpp"
(__3nn -> __O1__4expr.tp -> base__4node != 76 )))&& (__3nn -> n_stclass__4name != 31 ))&& (((__1q && __1q -> __O1__4expr.tp )&& (__1q -> __O1__4expr.tp -> base__4node != 108 ))&&
# 239 "/home/claude/cfront-3/src/find.cpp"
(__1q -> __O1__4expr.tp -> base__4node != 76 )))
# 240 "/home/claude/cfront-3/src/find.cpp"
{ 
# 241 "/home/claude/cfront-3/src/find.cpp"
{ 
# 241 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V52 ;

# 241 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"O missing for%n", (const struct ea *)( ((& __0__V52 )-> __O1__2ea.p =
# 241 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1q )), (& __0__V52 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 241 "/home/claude/cfront-3/src/find.cpp"
ea *)ea0 ) ;
if (__1n )( (__1n ?(((void )(__1n ?(((void )( ( ((((struct expr *)__1n ))?(((void )((((struct expr *)__1n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 ))))
# 242 "/home/claude/cfront-3/src/find.cpp"
, (((void )__dl__4nameSFPvUl ( (void *)__1n , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
# 242 "/home/claude/cfront-3/src/find.cpp"

# 243 "/home/claude/cfront-3/src/find.cpp"
me = 0 ;
return (struct expr *)__1q ;
} }

# 247 "/home/claude/cfront-3/src/find.cpp"
if ((__1f != 44 )&& (__1f != 45 )){ 
# 249 "/home/claude/cfront-3/src/find.cpp"
Pclass __4qcl ;

# 249 "/home/claude/cfront-3/src/find.cpp"
__4qcl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1q -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))));
mptr = 1 ;
if (__1cl && (__1cl -> csu__8classdef == 167 )){ 
# 252 "/home/claude/cfront-3/src/find.cpp"
mec = (cc - 1 )-> cot__11dcl_context ;
__1ee = find_name__8classdefFPCcP8classdefiT3 ( __4qcl , __1s , __4qcl , 0 , 0 ) ;
}
else __1ee = find_name__8classdefFPCcP8classdefiT3 ( __4qcl , __1s , __4qcl , 0 , 0 ) ;
mptr = 0 ;
if (__1ee && (__1ee -> base__4node == 85 )){ 
# 258 "/home/claude/cfront-3/src/find.cpp"
if (__1n && (__1n -> permanent__4node == 0 ))del__4nameFv ( __1n ) ;
me = 0 ;
return __1ee ;
}

# 269 "/home/claude/cfront-3/src/find.cpp"
if ((__1ee == 0 )&& (__4qcl -> class_base__8classdef == 2)){ 
# 270 "/home/claude/cfront-3/src/find.cpp"
{ 
# 270 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V53 ;

# 270 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V54 ;

# 270 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V55 ;

# 270 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V56 ;

# 270 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"YCM %t::%n requires %t<instance>::%n", (const struct ea *)( ((& __0__V53 )-> __O1__2ea.p =
# 270 "/home/claude/cfront-3/src/find.cpp"
((const void *)__4qcl )), (& __0__V53 )) , (const struct ea *)( ((& __0__V54 )-> __O1__2ea.p = ((const void
# 270 "/home/claude/cfront-3/src/find.cpp"
*)__1n )), (& __0__V54 )) , (const struct ea *)( ((& __0__V55 )-> __O1__2ea.p = ((const void *)__4qcl )), (&
# 270 "/home/claude/cfront-3/src/find.cpp"
__0__V55 )) , (const struct ea *)( ((& __0__V56 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V56 )) )
# 270 "/home/claude/cfront-3/src/find.cpp"
;
goto finishing_up ;
} }
}
{ 
# 274 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V57 ;

# 274 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V58 ;

# 274 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V59 ;

# 274 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"QdN%n::%n not found in %t", (const struct ea *)( ((& __0__V57 )-> __O1__2ea.p =
# 274 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1q )), (& __0__V57 )) , (const struct ea *)( ((& __0__V58 )-> __O1__2ea.p = ((const void
# 274 "/home/claude/cfront-3/src/find.cpp"
*)__1n )), (& __0__V58 )) , (const struct ea *)( ((& __0__V59 )-> __O1__2ea.p = ((const void *)__1cl )), (&
# 274 "/home/claude/cfront-3/src/find.cpp"
__0__V59 )) , (const struct ea *)ea0 ) ;
finishing_up :
# 276 "/home/claude/cfront-3/src/find.cpp"
me = 0 ;
return (struct expr *)undef__FP4nameP5tableUc ( __1n , __2bcl ?__2bcl -> memtbl__8classdef :__1cl -> memtbl__8classdef , (unsigned char )7 ) ;
} 
# 277 "/home/claude/cfront-3/src/find.cpp"
}
}

# 280 "/home/claude/cfront-3/src/find.cpp"
if ((__1ee -> base__4node == 44 )&& (__1ee -> __O2__4expr.e1 == 0 )){ 
# 282 "/home/claude/cfront-3/src/find.cpp"
switch (__1f ){ 
# 283 "/home/claude/cfront-3/src/find.cpp"
case 0 :
# 284 "/home/claude/cfront-3/src/find.cpp"
case 109 :
# 285 "/home/claude/cfront-3/src/find.cpp"
{ Pexpr __5mm ;
# 285 "/home/claude/cfront-3/src/find.cpp"
__5mm = __1ee -> __O4__4expr.mem ;
while ((__5mm -> base__4node == 44 )|| (__5mm -> base__4node == 177 ))__5mm = __5mm -> __O4__4expr.mem ;
if (__5mm -> base__4node == 85 )
# 288 "/home/claude/cfront-3/src/find.cpp"
switch (__5mm -> __O1__4expr.tp -> base__4node ){ 
# 289 "/home/claude/cfront-3/src/find.cpp"
case 108 :
# 290 "/home/claude/cfront-3/src/find.cpp"
case 76 :
# 291 "/home/claude/cfront-3/src/find.cpp"
goto addrof ;
default :
# 293 "/home/claude/cfront-3/src/find.cpp"
if ((((struct name *)(((struct name *)__5mm ))))-> n_stclass__4name == 31 )goto addrof ;
}
}
{ 
# 296 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V60 ;

# 296 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"O orOP missing forM%n", (const struct ea *)( ((& __0__V60 )-> __O1__2ea.p =
# 296 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1n )), (& __0__V60 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 296 "/home/claude/cfront-3/src/find.cpp"
ea *)ea0 ) ;

# 298 "/home/claude/cfront-3/src/find.cpp"
case 112 :
# 299 "/home/claude/cfront-3/src/find.cpp"
addrof :
# 300 "/home/claude/cfront-3/src/find.cpp"
{ 
# 301 "/home/claude/cfront-3/src/find.cpp"
Pexpr __5x ;

# 301 "/home/claude/cfront-3/src/find.cpp"
__5x = __1ee ;
__1ee = __1ee -> __O4__4expr.mem ;
( (__5x ?(((void )(__5x ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__5x , (size_t )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 303 "/home/claude/cfront-3/src/find.cpp"
;
}
case 44 :
# 306 "/home/claude/cfront-3/src/find.cpp"
case 45 :
# 307 "/home/claude/cfront-3/src/find.cpp"
break ;
default :
# 309 "/home/claude/cfront-3/src/find.cpp"
{ 
# 309 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V61 ;

# 309 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V62 ;

# 309 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"QdN%n::%n used in nonC context", (const struct ea *)( ((& __0__V61 )-> __O1__2ea.p =
# 309 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1q )), (& __0__V61 )) , (const struct ea *)( ((& __0__V62 )-> __O1__2ea.p = ((const void
# 309 "/home/claude/cfront-3/src/find.cpp"
*)__1n )), (& __0__V62 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} } }
}

# 313 "/home/claude/cfront-3/src/find.cpp"
( (__1n ?(((void )(__1n ?(((void )( ( ((((struct expr *)__1n ))?(((void )((((struct expr *)__1n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void
# 313 "/home/claude/cfront-3/src/find.cpp"
)0 )))) , (((void )__dl__4nameSFPvUl ( (void *)__1n , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 ))))
# 313 "/home/claude/cfront-3/src/find.cpp"
;
me = 0 ;
return __1ee ;

# 315 "/home/claude/cfront-3/src/find.cpp"
}
}

# 318 "/home/claude/cfront-3/src/find.cpp"
if ((__1f != 45 )&& (__1f != 44 )){ 
# 336 "/home/claude/cfront-3/src/find.cpp"
Pname __2save_this ;
Pname __2fn ;
Pfct __2ft ;
Pclass __2dc ;
Pname __2global_nn ;
int __2new_context ;

# 342 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X85 ;

# 342 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X86 ;

# 336 "/home/claude/cfront-3/src/find.cpp"
__2save_this = cc -> c_this__11dcl_context ;
__2fn = me ;
__2ft = mef ;
__2dc = (__2ft ?__2ft -> def_context__3fct :(((struct classdef *)0 )));
__2global_nn = 0 ;
__2new_context = 0 ;
if (__1cl && (! ( (__1__X85 = __1cl ), ( (__1__X86 = mec ), ( ((__1__X85 == __1__X86 )?1 :((__1__X85 && __1__X86 )?(((int )same_class__8classdefFP8classdefi (
# 342 "/home/claude/cfront-3/src/find.cpp"
__1__X85 , __1__X86 , 0 ) )):0 ))) ) ) )){ 
# 344 "/home/claude/cfront-3/src/find.cpp"
Pclass __3cx ;

# 344 "/home/claude/cfront-3/src/find.cpp"
__3cx = __1cl ;
for(;__3cx && (__3cx -> c_context__8classdef == 0 );__3cx = __3cx -> in_class__4type ) ;
if (__3cx ){ __2fn = __3cx -> in_fct__4type ;

# 346 "/home/claude/cfront-3/src/find.cpp"
__2ft = (((struct fct *)(((struct fct *)__2fn -> __O1__4expr.tp ))));

# 346 "/home/claude/cfront-3/src/find.cpp"
}
else { __2fn = 0 ;

# 347 "/home/claude/cfront-3/src/find.cpp"
__2ft = 0 ;

# 347 "/home/claude/cfront-3/src/find.cpp"
}
__1tbl = __1cl -> memtbl__8classdef ;
cc -> c_this__11dcl_context = 0 ;

# 351 "/home/claude/cfront-3/src/find.cpp"
}
while (mec && (mec -> csu__8classdef == 167 ))mec = mec -> in_class__4type ;
for(;;) { 
# 354 "/home/claude/cfront-3/src/find.cpp"
Pclass __3cx ;
Pname __3oth ;
Pexpr __3ee ;

# 355 "/home/claude/cfront-3/src/find.cpp"
__3oth = cc -> c_this__11dcl_context ;

# 357 "/home/claude/cfront-3/src/find.cpp"
if (__1cl ){ 
# 357 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X87 ;

# 357 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X88 ;

# 358 "/home/claude/cfront-3/src/find.cpp"
if (__1tbl == __1cl -> memtbl__8classdef ){ 
# 362 "/home/claude/cfront-3/src/find.cpp"
cc -> c_this__11dcl_context = 0 ;
}
else 
# 363 "/home/claude/cfront-3/src/find.cpp"
if ((__2ft == 0 )|| (! ( (__1__X87 = __1cl ), ( (__1__X88 = __2ft -> memof__3fct ), ( ((__1__X87 ==
# 363 "/home/claude/cfront-3/src/find.cpp"
__1__X88 )?1 :((__1__X87 && __1__X88 )?(((int )same_class__8classdefFP8classdefi ( __1__X87 , __1__X88 , 0 ) )):0 ))) ) ) )){ 
# 366 "/home/claude/cfront-3/src/find.cpp"
{ 
# 366 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V63 ;

# 366 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V64 ;

# 366 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V65 ;

# 366 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V66 ;

# 366 "/home/claude/cfront-3/src/find.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"find_name%n: confused context cl%t fn%n tbl %s", (const
# 366 "/home/claude/cfront-3/src/find.cpp"
struct ea *)( ((& __0__V63 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V63 )) , (const struct ea *)(
# 366 "/home/claude/cfront-3/src/find.cpp"
((& __0__V64 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V64 )) , (const struct ea *)( ((& __0__V65 )->
# 366 "/home/claude/cfront-3/src/find.cpp"
__O1__2ea.p = ((const void *)__2fn )), (& __0__V65 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V66 , (const void
# 366 "/home/claude/cfront-3/src/find.cpp"
*)whatami__5tableFv ( __1tbl ) ) ) ;
} }
else 
# 367 "/home/claude/cfront-3/src/find.cpp"
{ 
# 368 "/home/claude/cfront-3/src/find.cpp"
Pname __5nn ;

# 368 "/home/claude/cfront-3/src/find.cpp"
__5nn = look__5tableFPCcUc ( __1tbl , __1s , (unsigned char )0 ) ;
if (__5nn && (__5nn -> base__4node == 123 ))__5nn = 0 ;
if (__5nn ){ 
# 371 "/home/claude/cfront-3/src/find.cpp"
if (__5nn -> __O4__4expr.n_table != gtbl ){ 
# 372 "/home/claude/cfront-3/src/find.cpp"
if (__1m == 0 ){ 
# 372 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V67 ;

# 372 "/home/claude/cfront-3/src/find.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"find_name%n: local scope but missing m", (const
# 372 "/home/claude/cfront-3/src/find.cpp"
struct ea *)( ((& __0__V67 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V67 )) , (const struct ea *)ea0 ,
# 372 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 380 "/home/claude/cfront-3/src/find.cpp"
( (__5nn -> n_used__4name ++ ), (((void )0 ))) ;
if (__1n && (__1n -> permanent__4node == 0 ))del__4nameFv ( __1n ) ;
me = 0 ;
cc -> c_this__11dcl_context = __2save_this ;
return (struct expr *)__5nn ;
}

# 389 "/home/claude/cfront-3/src/find.cpp"
__2global_nn = __5nn ;
}
}
if (__2dc ){ 
# 396 "/home/claude/cfront-3/src/find.cpp"
cc -> c_this__11dcl_context = 0 ;
__3cx = __2dc ;
__3ee = find_name__8classdefFPCcP8classdefiT3 ( __2dc , __1s , (struct classdef *)0 , 0 , 0 ) ;
while (__3ee == 0 ){ 
# 399 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X89 ;

# 399 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X90 ;

# 400 "/home/claude/cfront-3/src/find.cpp"
if (__3cx -> c_context__8classdef )break ;
__3cx = __3cx -> in_class__4type ;
if (__3cx == 0 )break ;
if (( (__1__X89 = __3cx ), ( (__1__X90 = __1cl ), ( ((__1__X89 == __1__X90 )?1 :((__1__X89 && __1__X90 )?(((int )same_class__8classdefFP8classdefi ( __1__X89 , __1__X90 ,
# 403 "/home/claude/cfront-3/src/find.cpp"
0 ) )):0 ))) ) ) )break ;
__3ee = find_name__8classdefFPCcP8classdefiT3 ( __3cx , __1s , (struct classdef *)0 , 0 , 0 ) ;
}
cc -> c_this__11dcl_context = __3oth ;
__2dc = 0 ;
if (__3ee )goto eee ;
}
__3cx = __1cl ;
__3ee = find_name__8classdefFPCcP8classdefiT3 ( __1cl , __1s , (struct classdef *)0 , 0 , 0 ) ;
while (__3ee == 0 ){ 
# 413 "/home/claude/cfront-3/src/find.cpp"
if (__3cx -> c_context__8classdef )break ;
__3cx = __3cx -> in_class__4type ;
if (__3cx == 0 )break ;

# 419 "/home/claude/cfront-3/src/find.cpp"
cc -> c_this__11dcl_context = 0 ;
__3ee = find_name__8classdefFPCcP8classdefiT3 ( __3cx , __1s , (struct classdef *)0 , 0 , 0 ) ;
}
cc -> c_this__11dcl_context = __3oth ;
if (__3ee ){ 
# 424 "/home/claude/cfront-3/src/find.cpp"
eee :if (__2new_context ){ 
# 433 "/home/claude/cfront-3/src/find.cpp"
Pname __6nx ;
Pname __6nn ;

# 433 "/home/claude/cfront-3/src/find.cpp"
__6nx = (((struct name *)(((struct name *)__3ee ))));
__6nn = __2global_nn ;
if ((__6nn || ((__6nn = look__5tableFPCcUc ( gtbl , __1s , (unsigned char )0 ) )!= 0 ))&& __6nn -> n_oper__4name )
# 436 "/home/claude/cfront-3/src/find.cpp"
{ 
# 437 "/home/claude/cfront-3/src/find.cpp"
while
# 437 "/home/claude/cfront-3/src/find.cpp"
(__6nx -> base__4node == 44 )
# 438 "/home/claude/cfront-3/src/find.cpp"
__6nx = (((struct name *)(((struct name *)__6nx -> __O4__4expr.mem ))));
{ 
# 439 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V68 ;

# 439 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V69 ;

# 439 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V70 ;

# 439 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V71 ;

# 439 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%n andG%n are both visible within%t -- usingG%n", (const struct ea *)( ((&
# 439 "/home/claude/cfront-3/src/find.cpp"
__0__V68 )-> __O1__2ea.p = ((const void *)__6nx )), (& __0__V68 )) , (const struct ea *)( ((& __0__V69 )-> __O1__2ea.p =
# 439 "/home/claude/cfront-3/src/find.cpp"
((const void *)__6nn )), (& __0__V69 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V70 , (const void *)mec )
# 439 "/home/claude/cfront-3/src/find.cpp"
, (const struct ea *)( ((& __0__V71 )-> __O1__2ea.p = ((const void *)__6nn )), (& __0__V71 )) ) ;
# 439 "/home/claude/cfront-3/src/find.cpp"

# 440 "/home/claude/cfront-3/src/find.cpp"
( (__6nn -> n_used__4name ++ ), (((void )0 ))) ;
if (__1n && (__1n -> permanent__4node == 0 ))del__4nameFv ( __1n ) ;
me = 0 ;
cc -> c_this__11dcl_context = __2save_this ;
return (struct expr *)__6nn ;
} }
}
if ((__3ee -> base__4node == 44 )&& (__3ee -> __O2__4expr.e1 == 0 )){ 
# 448 "/home/claude/cfront-3/src/find.cpp"
Pexpr __6mm ;

# 448 "/home/claude/cfront-3/src/find.cpp"
__6mm = __3ee -> __O4__4expr.mem ;
while ((__6mm -> base__4node == 44 )|| (__6mm -> base__4node == 177 ))
# 450 "/home/claude/cfront-3/src/find.cpp"
__6mm = __6mm -> __O4__4expr.mem ;
if (__6mm -> base__4node == 85 )
# 452 "/home/claude/cfront-3/src/find.cpp"
switch (__6mm -> __O1__4expr.tp -> base__4node ){ 
# 453 "/home/claude/cfront-3/src/find.cpp"
default :
# 454 "/home/claude/cfront-3/src/find.cpp"
if ((((struct name *)(((struct name *)__6mm ))))-> n_stclass__4name != 31 )
# 455 "/home/claude/cfront-3/src/find.cpp"
{
# 455 "/home/claude/cfront-3/src/find.cpp"

# 455 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V72 ;

# 455 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"O orOP missing for%n", (const struct ea *)( ((& __0__V72 )-> __O1__2ea.p =
# 455 "/home/claude/cfront-3/src/find.cpp"
((const void *)__6mm )), (& __0__V72 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 455 "/home/claude/cfront-3/src/find.cpp"
ea *)ea0 ) ;
} case 108 :case 76 :
# 457 "/home/claude/cfront-3/src/find.cpp"
if (__1n && (__1n -> permanent__4node == 0 ))del__4nameFv ( __1n ) ;
me = 0 ;
cc -> c_this__11dcl_context = __2save_this ;
return __6mm ;
}
}
if (__1n && (__1n -> permanent__4node == 0 ))del__4nameFv ( __1n ) ;
me = 0 ;
cc -> c_this__11dcl_context = __2save_this ;
return __3ee ;
}

# 471 "/home/claude/cfront-3/src/find.cpp"
__1tbl = (__3cx ?__3cx -> c_context__8classdef :gtbl );

# 473 "/home/claude/cfront-3/src/find.cpp"
if (__1tbl == 0 ){ 
# 473 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V73 ;

# 473 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V74 ;

# 473 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"missing context table for cl%t/cx%t", (const struct ea *)( ((&
# 473 "/home/claude/cfront-3/src/find.cpp"
__0__V73 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V73 )) , (const struct ea *)( ((& __0__V74 )-> __O1__2ea.p =
# 473 "/home/claude/cfront-3/src/find.cpp"
((const void *)__3cx )), (& __0__V74 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (((__1tbl == gtbl )&& __2global_nn )&& (! __2dc )){ 
# 476 "/home/claude/cfront-3/src/find.cpp"
( (__2global_nn -> n_used__4name ++ ), (((void )0 ))) ;
# 476 "/home/claude/cfront-3/src/find.cpp"

# 477 "/home/claude/cfront-3/src/find.cpp"
if (__1n && (__1n -> permanent__4node == 0 ))del__4nameFv ( __1n ) ;
me = 0 ;
cc -> c_this__11dcl_context = __2save_this ;
return (struct expr *)__2global_nn ;
}
__2new_context = 1 ;
}

# 485 "/home/claude/cfront-3/src/find.cpp"
{ Pname __3nn ;

# 485 "/home/claude/cfront-3/src/find.cpp"
__3nn = look__5tableFPCcUc ( __1tbl , __1s , (unsigned char )0 ) ;
if (__3nn && (__3nn -> base__4node == 123 ))__3nn = 0 ;
if (__3nn ){ 
# 488 "/home/claude/cfront-3/src/find.cpp"
if (__3nn -> __O4__4expr.n_table != gtbl ){ 
# 489 "/home/claude/cfront-3/src/find.cpp"
if (__1m == 0 ){ 
# 489 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V75 ;

# 489 "/home/claude/cfront-3/src/find.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"find_name%n: local scope but missing m", (const
# 489 "/home/claude/cfront-3/src/find.cpp"
struct ea *)( ((& __0__V75 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V75 )) , (const struct ea *)ea0 ,
# 489 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__2new_context ){ 
# 495 "/home/claude/cfront-3/src/find.cpp"
check_local_nested_ref__FP4nameUc3loc ( __3nn , (unsigned char )__1f , __1n -> where__4name ) ;
}
}
else 
# 497 "/home/claude/cfront-3/src/find.cpp"
if (__2ft && (__2ft -> memof__3fct || __2dc )){ 
# 501 "/home/claude/cfront-3/src/find.cpp"
__2global_nn = __3nn ;
goto nxt ;
}
( (__3nn -> n_used__4name ++ ), (((void )0 ))) ;
if (__1n && (__1n -> permanent__4node == 0 ))del__4nameFv ( __1n ) ;
me = 0 ;
cc -> c_this__11dcl_context = __2save_this ;
return (struct expr *)__3nn ;
}
nxt :
# 511 "/home/claude/cfront-3/src/find.cpp"
if (__2dc ){ 
# 513 "/home/claude/cfront-3/src/find.cpp"
cc -> c_this__11dcl_context = 0 ;
__3cx = __2dc ;
__3ee = find_name__8classdefFPCcP8classdefiT3 ( __2dc , __1s , (struct classdef *)0 , 0 , 0 ) ;
while (__3ee == 0 ){ 
# 517 "/home/claude/cfront-3/src/find.cpp"
if (__3cx -> c_context__8classdef )break ;
__3cx = __3cx -> in_class__4type ;
if (__3cx == 0 )break ;
__3ee = find_name__8classdefFPCcP8classdefiT3 ( __3cx , __1s , (struct classdef *)0 , 0 , 0 ) ;
}
cc -> c_this__11dcl_context = __3oth ;
if (__3ee )goto eee ;
}
__2new_context = 1 ;
__1cl = (__2ft ?__2ft -> memof__3fct :(((struct classdef *)0 )));
if (__1cl == 0 ){ 
# 528 "/home/claude/cfront-3/src/find.cpp"
if (__2global_nn ){ 
# 529 "/home/claude/cfront-3/src/find.cpp"
( (__2global_nn -> n_used__4name ++ ), (((void )0 ))) ;
if (__1n && (__1n -> permanent__4node == 0 ))del__4nameFv ( __1n ) ;
me = 0 ;
cc -> c_this__11dcl_context = __2save_this ;
return (struct expr *)__2global_nn ;
}
break ;
}

# 538 "/home/claude/cfront-3/src/find.cpp"
__1tbl = __1cl -> memtbl__8classdef ;
__2fn = (__3cx ?__3cx -> in_fct__4type :(((struct name *)0 )));
if (__2fn ){ __2ft = (((struct fct *)(((struct fct *)__2fn -> __O1__4expr.tp ))));

# 540 "/home/claude/cfront-3/src/find.cpp"
cc -> c_this__11dcl_context = __2ft -> f_this__3fct ;

# 540 "/home/claude/cfront-3/src/find.cpp"
}
else { __2ft = 0 ;

# 541 "/home/claude/cfront-3/src/find.cpp"
cc -> c_this__11dcl_context = 0 ;

# 541 "/home/claude/cfront-3/src/find.cpp"
}
__2dc = (__2ft ?__2ft -> def_context__3fct :(((struct classdef *)0 )));

# 542 "/home/claude/cfront-3/src/find.cpp"
}
}
me = 0 ;
cc -> c_this__11dcl_context = __2save_this ;
return (struct expr *)undef__FP4nameP5tableUc ( __1n , gtbl , (unsigned char )__1f ) ;
}

# 549 "/home/claude/cfront-3/src/find.cpp"
if (__1ee = find_name__8classdefFPCcP8classdefiT3 ( __1cl , __1s , __1cl , 0 , 0 ) ){ 
# 550 "/home/claude/cfront-3/src/find.cpp"
if (__1n && (__1n -> permanent__4node == 0 ))del__4nameFv (
# 550 "/home/claude/cfront-3/src/find.cpp"
__1n ) ;
me = 0 ;
return __1ee ;
}

# 555 "/home/claude/cfront-3/src/find.cpp"
if (! strcmp ( __1s , __1cl -> string__8classdef ) ){ 
# 556 "/home/claude/cfront-3/src/find.cpp"
me = 0 ;
return (struct expr *)undef__FP4nameP5tableUc ( __1n , gtbl , (unsigned char )84 ) ;
}

# 560 "/home/claude/cfront-3/src/find.cpp"
me = 0 ;
return (struct expr *)undef__FP4nameP5tableUc ( __1n , gtbl , (unsigned char )__1f ) ;

# 561 "/home/claude/cfront-3/src/find.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 564 "/home/claude/cfront-3/src/find.cpp"
int check_dup__8classdefFP8classdefUc (struct classdef *__0this , Pclass __1cl , TOK __1bb );

# 564 "/home/claude/cfront-3/src/find.cpp"
int check_dup__8classdefFP8classdefUc (register struct classdef *__0this , Pclass __1cl , TOK __1bb )
# 568 "/home/claude/cfront-3/src/find.cpp"
{ 
# 569 "/home/claude/cfront-3/src/find.cpp"
{ { Pbcl __1b ;

# 569 "/home/claude/cfront-3/src/find.cpp"
__1b = __0this -> baselist__8classdef ;

# 569 "/home/claude/cfront-3/src/find.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 569 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X100 ;

# 569 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X101 ;

# 570 "/home/claude/cfront-3/src/find.cpp"
if (( (__1__X100 = __1cl ), ( (__1__X101 = __1b -> bclass__6basecl ), ( ((__1__X100 == __1__X101 )?1 :((__1__X100 && __1__X101 )?(((int )same_class__8classdefFP8classdefi ( __1__X100 ,
# 570 "/home/claude/cfront-3/src/find.cpp"
__1__X101 , 0 ) )):0 ))) ) ) ){ 
# 571 "/home/claude/cfront-3/src/find.cpp"
if (__1bb != 77 ){ 
# 572 "/home/claude/cfront-3/src/find.cpp"
if (__1b -> base__4node == 77 )
# 573 "/home/claude/cfront-3/src/find.cpp"
{ 
# 573 "/home/claude/cfront-3/src/find.cpp"
struct
# 573 "/home/claude/cfront-3/src/find.cpp"
ea __0__V91 ;

# 573 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V92 ;

# 573 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V93 ;

# 573 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%t inaccessible because of virtual%t in%t", (const struct ea *)( ((&
# 573 "/home/claude/cfront-3/src/find.cpp"
__0__V91 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V91 )) , (const struct ea *)( ((& __0__V92 )-> __O1__2ea.p =
# 573 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1cl )), (& __0__V92 )) , (const struct ea *)( ((& __0__V93 )-> __O1__2ea.p = ((const void
# 573 "/home/claude/cfront-3/src/find.cpp"
*)__0this )), (& __0__V93 )) , (const struct ea *)ea0 ) ;
} else 
# 575 "/home/claude/cfront-3/src/find.cpp"
{ 
# 575 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V94 ;

# 575 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V95 ;

# 575 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V96 ;

# 575 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%t inaccessible because of%t in%t", (const struct ea *)( ((&
# 575 "/home/claude/cfront-3/src/find.cpp"
__0__V94 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V94 )) , (const struct ea *)( ((& __0__V95 )-> __O1__2ea.p =
# 575 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1cl )), (& __0__V95 )) , (const struct ea *)( ((& __0__V96 )-> __O1__2ea.p = ((const void
# 575 "/home/claude/cfront-3/src/find.cpp"
*)__0this )), (& __0__V96 )) , (const struct ea *)ea0 ) ;
} return 1 ;
}
else if (__1b -> base__4node != 77 ){ 
# 579 "/home/claude/cfront-3/src/find.cpp"
{ 
# 579 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V97 ;

# 579 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V98 ;

# 579 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V99 ;

# 579 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"virtual %t inaccessible because of%t in%t", (const struct ea *)( ((&
# 579 "/home/claude/cfront-3/src/find.cpp"
__0__V97 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V97 )) , (const struct ea *)( ((& __0__V98 )-> __O1__2ea.p =
# 579 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1cl )), (& __0__V98 )) , (const struct ea *)( ((& __0__V99 )-> __O1__2ea.p = ((const void
# 579 "/home/claude/cfront-3/src/find.cpp"
*)__0this )), (& __0__V99 )) , (const struct ea *)ea0 ) ;
return 1 ;
} }
}
if (check_dup__8classdefFP8classdefUc ( __1b -> bclass__6basecl , __1cl , __1bb ) )return 1 ;
}
return 0 ;

# 585 "/home/claude/cfront-3/src/find.cpp"
}

# 585 "/home/claude/cfront-3/src/find.cpp"
}
}

# 589 "/home/claude/cfront-3/src/find.cpp"
TOK Nvis = 0 ;
TOK Nvirt = 0 ;
TOK ppbase = 0 ;

# 470 "/home/claude/cfront-3/src/template.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 458 "/home/claude/cfront-3/src/cfront.h"
bit has_friend__8classdefFP3fct (struct classdef *__0this , Pfct );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 593 "/home/claude/cfront-3/src/find.cpp"
Pclass is_base__8classdefFPCcPUci (register struct classdef *__0this , const char *__1s , TOK *__1pptr , int __1level )
# 597 "/home/claude/cfront-3/src/find.cpp"
{ 
# 599 "/home/claude/cfront-3/src/find.cpp"
TOK __1pp ;
TOK __1ppaccum ;

# 599 "/home/claude/cfront-3/src/find.cpp"
__1pp = ppbase ;

# 603 "/home/claude/cfront-3/src/find.cpp"
{ { Pbcl __1b ;

# 603 "/home/claude/cfront-3/src/find.cpp"
__1b = __0this -> baselist__8classdef ;

# 603 "/home/claude/cfront-3/src/find.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 604 "/home/claude/cfront-3/src/find.cpp"
if (__1b -> promoted__6basecl )
# 605 "/home/claude/cfront-3/src/find.cpp"
continue ;
{ const char *__2str ;

# 607 "/home/claude/cfront-3/src/find.cpp"
register struct templ_classdef *__0__X102 ;

# 606 "/home/claude/cfront-3/src/find.cpp"
__2str = 0 ;
if (__1b -> bclass__6basecl -> class_base__8classdef == 4)
# 608 "/home/claude/cfront-3/src/find.cpp"
__2str = ( (__0__X102 = (((struct templ_classdef *)(((struct templ_classdef *)__1b -> bclass__6basecl ))))), ( __0__X102 -> inst__14templ_classdef ->
# 608 "/home/claude/cfront-3/src/find.cpp"
def__10templ_inst -> namep__5templ ) ) -> __O2__4expr.string ;

# 611 "/home/claude/cfront-3/src/find.cpp"
if ((strcmp ( __1s , __1b -> bclass__6basecl -> string__8classdef ) == 0 )|| (__2str && (strcmp ( __1s , __2str ) == 0 )))
# 613 "/home/claude/cfront-3/src/find.cpp"
{
# 613 "/home/claude/cfront-3/src/find.cpp"

# 613 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X103 ;

# 613 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X104 ;

# 614 "/home/claude/cfront-3/src/find.cpp"
__1ppaccum = 25 ;
if (((__1b -> ppp__6basecl != 25 )&& (! ( (__1__X103 = cc -> cot__11dcl_context ), ( (__1__X104 = __0this ), ( ((__1__X103 ==
# 615 "/home/claude/cfront-3/src/find.cpp"
__1__X104 )?1 :((__1__X103 && __1__X104 )?(((int )same_class__8classdefFP8classdefi ( __1__X103 , __1__X104 , 0 ) )):0 ))) ) ) ))&& ((cc -> nof__11dcl_context == 0 )|| (has_friend__8classdefFP3fct (
# 615 "/home/claude/cfront-3/src/find.cpp"
__0this , ((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp )))) == 0 )))
# 618 "/home/claude/cfront-3/src/find.cpp"
__1ppaccum = __1b -> ppp__6basecl ;

# 621 "/home/claude/cfront-3/src/find.cpp"
Nvirt = __1b -> base__4node ;

# 625 "/home/claude/cfront-3/src/find.cpp"
if (__1pptr )
# 626 "/home/claude/cfront-3/src/find.cpp"
((*__1pptr ))= __1ppaccum ;
if (__1level == 0 )
# 628 "/home/claude/cfront-3/src/find.cpp"
ppbase = __1ppaccum ;
return __1b -> bclass__6basecl ;
}
else { 
# 636 "/home/claude/cfront-3/src/find.cpp"
TOK __3prot ;
Pclass __3bc ;

# 637 "/home/claude/cfront-3/src/find.cpp"
__3bc = is_base__8classdefFPCcPUci ( __1b -> bclass__6basecl , __1s , & __3prot , __1level + 1 ) ;
if (__3bc ){ 
# 638 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X105 ;

# 638 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X106 ;

# 639 "/home/claude/cfront-3/src/find.cpp"
__1ppaccum = __3prot ;
if (((__1b -> ppp__6basecl != 25 )&& (! ( (__1__X105 = cc -> cot__11dcl_context ), ( (__1__X106 = __0this ), ( ((__1__X105 ==
# 640 "/home/claude/cfront-3/src/find.cpp"
__1__X106 )?1 :((__1__X105 && __1__X106 )?(((int )same_class__8classdefFP8classdefi ( __1__X105 , __1__X106 , 0 ) )):0 ))) ) ) ))&& ((cc -> nof__11dcl_context == 0 )|| (has_friend__8classdefFP3fct (
# 640 "/home/claude/cfront-3/src/find.cpp"
__0this , ((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp )))) == 0 )))
# 643 "/home/claude/cfront-3/src/find.cpp"
__1ppaccum = ((__1b -> ppp__6basecl > __1ppaccum )?__1b -> ppp__6basecl :__1ppaccum );

# 647 "/home/claude/cfront-3/src/find.cpp"
if (__1ppaccum == 25 ){ 
# 648 "/home/claude/cfront-3/src/find.cpp"
if (__1pptr )
# 649 "/home/claude/cfront-3/src/find.cpp"
((*__1pptr ))= __1ppaccum ;
if (__1level == 0 )
# 651 "/home/claude/cfront-3/src/find.cpp"
ppbase = __1ppaccum ;
return __3bc ;
}

# 657 "/home/claude/cfront-3/src/find.cpp"
}
}

# 658 "/home/claude/cfront-3/src/find.cpp"
}
}
ppbase = __1pp ;
return (struct classdef *)0 ;

# 661 "/home/claude/cfront-3/src/find.cpp"
}

# 661 "/home/claude/cfront-3/src/find.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 457 "/home/claude/cfront-3/src/cfront.h"
bit has_friend__8classdefFP8classdef (struct classdef *__0this , Pclass );

# 664 "/home/claude/cfront-3/src/find.cpp"
bit has_base__8classdefFP8classdefiT2 (struct classdef *__0this , Pclass __1cl , int __1level , int __1ccflag );

# 664 "/home/claude/cfront-3/src/find.cpp"
bit has_base__8classdefFP8classdefiT2 (register struct classdef *__0this , Pclass __1cl , int __1level , int __1ccflag )
# 668 "/home/claude/cfront-3/src/find.cpp"
{ 
# 670 "/home/claude/cfront-3/src/find.cpp"
if (__0this == 0 )return (unsigned char )0 ;
# 670 "/home/claude/cfront-3/src/find.cpp"

# 671 "/home/claude/cfront-3/src/find.cpp"
{ static int __1found = 0 ;
if (__1level == 0 )__1found = 0 ;

# 674 "/home/claude/cfront-3/src/find.cpp"
{ { Pbcl __1b ;

# 674 "/home/claude/cfront-3/src/find.cpp"
__1b = __0this -> baselist__8classdef ;

# 674 "/home/claude/cfront-3/src/find.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 674 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X107 ;

# 674 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X108 ;

# 676 "/home/claude/cfront-3/src/find.cpp"
if (( (__1__X107 = __1b -> bclass__6basecl ), ( (__1__X108 = __1cl ), ( ((__1__X107 == __1__X108 )?1 :((__1__X107 && __1__X108 )?(((int )same_class__8classdefFP8classdefi ( __1__X107 ,
# 676 "/home/claude/cfront-3/src/find.cpp"
__1__X108 , 1 ) )):0 ))) ) ) ){ 
# 676 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X109 ;

# 676 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X110 ;

# 677 "/home/claude/cfront-3/src/find.cpp"
if ((((__1b -> ppp__6basecl != 25 )&& (__1ccflag || (! ( (__1__X109 = cc -> cot__11dcl_context ), ( (__1__X110 = __0this ), (
# 677 "/home/claude/cfront-3/src/find.cpp"
((__1__X109 == __1__X110 )?1 :((__1__X109 && __1__X110 )?(((int )same_class__8classdefFP8classdefi ( __1__X109 , __1__X110 , 0 ) )):0 ))) ) ) )))&& ((cc -> nof__11dcl_context == 0 )||
# 677 "/home/claude/cfront-3/src/find.cpp"
(has_friend__8classdefFP3fct ( __0this , ((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp )))) == 0 )))&& ((cc -> cot__11dcl_context == 0 )|| (has_friend__8classdefFP8classdef ( __0this ,
# 677 "/home/claude/cfront-3/src/find.cpp"
cc -> cot__11dcl_context ) == 0 )))
# 683 "/home/claude/cfront-3/src/find.cpp"
Nvis = __1b -> ppp__6basecl ;
Nvirt = __1b -> base__4node ;

# 686 "/home/claude/cfront-3/src/find.cpp"
if (((__1level == 0 )&& (__1b -> base__4node == 77 ))&& (__1found == 1 )){ 
# 688 "/home/claude/cfront-3/src/find.cpp"
if (__1b -> ppp__6basecl != Nvis )
# 689 "/home/claude/cfront-3/src/find.cpp"
Nvis = ((__1b -> ppp__6basecl ==
# 689 "/home/claude/cfront-3/src/find.cpp"
25 )?0 :(((int )__1b -> ppp__6basecl )));
}
return (unsigned char )1 ;
}
if (has_base__8classdefFP8classdefiT2 ( __1b -> bclass__6basecl , __1cl , __1level + 1 , __1ccflag ) ){ 
# 695 "/home/claude/cfront-3/src/find.cpp"
if ((__1level == 0 )&& (Nvirt == 77 )){
# 695 "/home/claude/cfront-3/src/find.cpp"

# 696 "/home/claude/cfront-3/src/find.cpp"
__1found = 1 ;

# 696 "/home/claude/cfront-3/src/find.cpp"
continue ;

# 696 "/home/claude/cfront-3/src/find.cpp"
}
return (unsigned char )1 ;
}
}
return (unsigned char )0 ;

# 700 "/home/claude/cfront-3/src/find.cpp"
}

# 700 "/home/claude/cfront-3/src/find.cpp"
}

# 700 "/home/claude/cfront-3/src/find.cpp"
}
}

# 703 "/home/claude/cfront-3/src/find.cpp"
int Noffset = 0 ;
Pexpr Nptr = 0 ;
const char *Nalloc_base = 0 ;
struct clist *vcllist = 0 ;

# 493 "/home/claude/cfront-3/src/cfront.h"

# 708 "/home/claude/cfront-3/src/find.cpp"
int onlist__5clistFP8classdef (register struct clist *__0this , Pclass __1c )
# 709 "/home/claude/cfront-3/src/find.cpp"
{ 
# 710 "/home/claude/cfront-3/src/find.cpp"
{ { struct clist *__1p ;

# 711 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X111 ;

# 711 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X112 ;

# 710 "/home/claude/cfront-3/src/find.cpp"
__1p = __0this ;

# 710 "/home/claude/cfront-3/src/find.cpp"
for(;__1p ;__1p = __1p -> next__5clist ) 
# 711 "/home/claude/cfront-3/src/find.cpp"
if (( (__1__X111 = __1p -> cl__5clist ), ( (__1__X112 = __1c ), ( ((__1__X111 == __1__X112 )?1 :((__1__X111 &&
# 711 "/home/claude/cfront-3/src/find.cpp"
__1__X112 )?(((int )same_class__8classdefFP8classdefi ( __1__X111 , __1__X112 , 0 ) )):0 ))) ) ) )return 1 ;
return 0 ;

# 712 "/home/claude/cfront-3/src/find.cpp"
}

# 712 "/home/claude/cfront-3/src/find.cpp"
}
}

# 715 "/home/claude/cfront-3/src/find.cpp"
void clear__5clistFv (register struct clist *__0this )
# 716 "/home/claude/cfront-3/src/find.cpp"
{ 
# 717 "/home/claude/cfront-3/src/find.cpp"
if (__0this == 0 )return ;
{ struct clist *__1p ;

# 718 "/home/claude/cfront-3/src/find.cpp"
__1p = __0this -> next__5clist ;
while (__1p ){ 
# 720 "/home/claude/cfront-3/src/find.cpp"
struct clist *__2q ;

# 720 "/home/claude/cfront-3/src/find.cpp"
__2q = __1p -> next__5clist ;
__dl__FPv ( (void *)__1p ) ;
__1p = __2q ;
}

# 723 "/home/claude/cfront-3/src/find.cpp"
;
__dl__FPv ( (void *)__0this ) ;

# 724 "/home/claude/cfront-3/src/find.cpp"
}
}

# 727 "/home/claude/cfront-3/src/find.cpp"
Pbcl Nvbc_alloc = 0 ;

# 493 "/home/claude/cfront-3/src/cfront.h"

# 848 "/home/claude/cfront-3/src/cfront.h"

# 482 "/home/claude/cfront-3/src/cfront.h"
const char *has_allocated_base__8classdefFPCc (struct classdef *__0this , const char *);

# 507 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 728 "/home/claude/cfront-3/src/find.cpp"
int is_unique_base__FP8classdefPCciT3T1 (Pclass __1cl , const char *__1s , int __1offset , int __1in_base , Pclass __1priSeen );

# 848 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"
static int same_class__FP8classdefT1i (Pclass __1c1 , Pclass __1c2 , int __1dummy );

# 728 "/home/claude/cfront-3/src/find.cpp"
int is_unique_base__FP8classdefPCciT3T1 (Pclass __1cl , const char *__1s , int __1offset , int __1in_base , 
# 729 "/home/claude/cfront-3/src/find.cpp"
Pclass __1priSeen )
# 733 "/home/claude/cfront-3/src/find.cpp"
{ 
# 734 "/home/claude/cfront-3/src/find.cpp"
int __1i ;

# 734 "/home/claude/cfront-3/src/find.cpp"
__1i = 0 ;

# 736 "/home/claude/cfront-3/src/find.cpp"
{ { Pbcl __1b ;

# 736 "/home/claude/cfront-3/src/find.cpp"
__1b = __1cl -> baselist__8classdef ;

# 736 "/home/claude/cfront-3/src/find.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 737 "/home/claude/cfront-3/src/find.cpp"
int __2no ;

# 737 "/home/claude/cfront-3/src/find.cpp"
__2no = 0 ;
if (__1b -> base__4node != 77 )
# 739 "/home/claude/cfront-3/src/find.cpp"
__2no = (__1offset + __1b -> obj_offset__6basecl );
else if (__1in_base )
# 741 "/home/claude/cfront-3/src/find.cpp"
continue ;
if (strcmp ( __1s , __1b -> bclass__6basecl -> string__8classdef ) == 0 ){ 
# 742 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X113 ;

# 742 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X114 ;

# 743 "/home/claude/cfront-3/src/find.cpp"
Noffset = __2no ;
__1i ++ ;
if (((((__1b -> ppp__6basecl != 25 )|| __1priSeen )&& ((! ( (__1__X113 = cc -> cot__11dcl_context ), ( (__1__X114 = __1cl ), (
# 745 "/home/claude/cfront-3/src/find.cpp"
((__1__X113 == __1__X114 )?1 :((__1__X113 && __1__X114 )?(((int )same_class__8classdefFP8classdefi ( __1__X113 , __1__X114 , 0 ) )):0 ))) ) ) )|| (! same_class__FP8classdefT1i ( cc ->
# 745 "/home/claude/cfront-3/src/find.cpp"
cot__11dcl_context , __1priSeen , 0 ) )))&& ((cc -> nof__11dcl_context == 0 )|| (has_friend__8classdefFP3fct ( __1cl , ((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp ))))
# 745 "/home/claude/cfront-3/src/find.cpp"
== 0 )))|| (__1priSeen && (has_friend__8classdefFP3fct ( __1priSeen , ((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp )))) == 0 )))
# 749 "/home/claude/cfront-3/src/find.cpp"
Nvis = __1b -> ppp__6basecl ;
# 749 "/home/claude/cfront-3/src/find.cpp"

# 751 "/home/claude/cfront-3/src/find.cpp"
if (__1b -> base__4node == 77 ){ 
# 751 "/home/claude/cfront-3/src/find.cpp"
register struct mdot *__0__X115 ;

# 752 "/home/claude/cfront-3/src/find.cpp"
Nptr = (struct expr *)( (__0__X115 = 0 ), ( ((__0__X115 || (__0__X115 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 752 "/home/claude/cfront-3/src/find.cpp"
))?( (__0__X115 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X115 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 752 "/home/claude/cfront-3/src/find.cpp"
( (__0__X115 -> __O3__4expr.string2 = __1s ), (__0__X115 -> __O4__4expr.mem = ((struct expr *)0 ))) ) :0 ), __0__X115 ) ) ;

# 754 "/home/claude/cfront-3/src/find.cpp"
if (__1b -> allocated__6basecl != 1 ){ 
# 755 "/home/claude/cfront-3/src/find.cpp"
Nvbc_alloc = 0 ;
Nalloc_base = has_allocated_base__8classdefFPCc ( __1cl , __1s ) ;
}
}
}
else { 
# 761 "/home/claude/cfront-3/src/find.cpp"
if (__1b -> base__4node == 77 ){ 
# 761 "/home/claude/cfront-3/src/find.cpp"
struct clist *__0__X116 ;

# 761 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__2__X117 ;

# 761 "/home/claude/cfront-3/src/find.cpp"
struct clist *__2__X118 ;

# 762 "/home/claude/cfront-3/src/find.cpp"
if (vcllist && onlist__5clistFP8classdef ( vcllist , __1b -> bclass__6basecl ) )continue ;
vcllist = ( (__0__X116 = 0 ), ( (__2__X117 = __1b -> bclass__6basecl ), ( (__2__X118 = vcllist ), ( ((__0__X116 || (__0__X116 =
# 763 "/home/claude/cfront-3/src/find.cpp"
(struct clist *)__nw__FUl ( (size_t )(sizeof (struct clist))) ))?( (__0__X116 -> cl__5clist = __2__X117 ), (__0__X116 -> next__5clist = __2__X118 )) :0 ),
# 763 "/home/claude/cfront-3/src/find.cpp"
__0__X116 ) ) ) ) ;
}

# 766 "/home/claude/cfront-3/src/find.cpp"
{ Pclass __3clscope ;

# 766 "/home/claude/cfront-3/src/find.cpp"
__3clscope = 0 ;
if (cc && cc -> c_this__11dcl_context ){ 
# 768 "/home/claude/cfront-3/src/find.cpp"
Ptype __4t ;

# 768 "/home/claude/cfront-3/src/find.cpp"
__4t = (((struct ptr *)(((struct ptr *)cc -> c_this__11dcl_context -> __O1__4expr.tp ))))-> typ__5pvtyp ;
__3clscope = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__4t ))))-> b_name__8basetype -> __O1__4expr.tp ))));
}

# 772 "/home/claude/cfront-3/src/find.cpp"
{ Pclass __3new_priSeen ;

# 773 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X119 ;

# 773 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X120 ;

# 772 "/home/claude/cfront-3/src/find.cpp"
__3new_priSeen = __1priSeen ;
if (((__1b -> ppp__6basecl != 25 )&& (! ( (__1__X119 = __1cl ), ( (__1__X120 = __3clscope ), ( ((__1__X119 == __1__X120 )?1 :((__1__X119 &&
# 773 "/home/claude/cfront-3/src/find.cpp"
__1__X120 )?(((int )same_class__8classdefFP8classdefi ( __1__X119 , __1__X120 , 0 ) )):0 ))) ) ) ))&& (__1priSeen == 0 ))
# 774 "/home/claude/cfront-3/src/find.cpp"
__3new_priSeen = __1cl ;

# 776 "/home/claude/cfront-3/src/find.cpp"
{ int __3ii ;

# 776 "/home/claude/cfront-3/src/find.cpp"
__3ii = is_unique_base__FP8classdefPCciT3T1 ( __1b -> bclass__6basecl , __1s , __2no , 1 , __3new_priSeen ) ;

# 779 "/home/claude/cfront-3/src/find.cpp"
__1i += __3ii ;
if ((__3ii == 1 )&& (__1b -> base__4node == 77 )){ 
# 780 "/home/claude/cfront-3/src/find.cpp"
register struct mdot *__0__X121 ;

# 780 "/home/claude/cfront-3/src/find.cpp"
const char *__2__X122 ;

# 781 "/home/claude/cfront-3/src/find.cpp"
Nptr = (struct expr *)( (__0__X121 = 0 ), ( (__2__X122 = __1b -> bclass__6basecl -> string__8classdef ), ( ((__0__X121 || (__0__X121 = (struct
# 781 "/home/claude/cfront-3/src/find.cpp"
mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot))) ))?( (__0__X121 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X121 ), (unsigned char )177 ,
# 781 "/home/claude/cfront-3/src/find.cpp"
(struct expr *)0 , (struct expr *)0 ) ), ( (__0__X121 -> __O3__4expr.string2 = __2__X122 ), (__0__X121 -> __O4__4expr.mem = ((struct expr *)0 ))) )
# 781 "/home/claude/cfront-3/src/find.cpp"
:0 ), __0__X121 ) ) ) ;

# 783 "/home/claude/cfront-3/src/find.cpp"
if (__1b -> allocated__6basecl != 1 ){ 
# 784 "/home/claude/cfront-3/src/find.cpp"
Nvbc_alloc = 0 ;
Nalloc_base = has_allocated_base__8classdefFPCc ( __1cl , __1b -> bclass__6basecl -> string__8classdef ) ;
}
}

# 787 "/home/claude/cfront-3/src/find.cpp"
}

# 787 "/home/claude/cfront-3/src/find.cpp"
}

# 787 "/home/claude/cfront-3/src/find.cpp"
}
}
}

# 791 "/home/claude/cfront-3/src/find.cpp"
return __1i ;

# 791 "/home/claude/cfront-3/src/find.cpp"
}

# 791 "/home/claude/cfront-3/src/find.cpp"
}
}

# 822 "/home/claude/cfront-3/src/find.cpp"
int link_compat_hack = 0 ;
int has_allocated_base__8classdefFP8classdefUc (struct classdef *__0this , Pclass __1bcl , bit __1first );

# 823 "/home/claude/cfront-3/src/find.cpp"
int has_allocated_base__8classdefFP8classdefUc (register struct classdef *__0this , Pclass __1bcl , bit __1first )
# 831 "/home/claude/cfront-3/src/find.cpp"
{ 
# 833 "/home/claude/cfront-3/src/find.cpp"
{ { Pbcl __1l ;

# 833 "/home/claude/cfront-3/src/find.cpp"
__1l = __0this -> baselist__8classdef ;

# 833 "/home/claude/cfront-3/src/find.cpp"
for(;__1l ;__1l = __1l -> next__6basecl ) { 
# 833 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X123 ;

# 833 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X124 ;

# 835 "/home/claude/cfront-3/src/find.cpp"
if ((__1l -> base__4node == 77 )&& ( (__1__X123 = __1l -> bclass__6basecl ), ( (__1__X124 = __1bcl ), ( ((__1__X123 == __1__X124 )?1 :((__1__X123 &&
# 835 "/home/claude/cfront-3/src/find.cpp"
__1__X124 )?(((int )same_class__8classdefFP8classdefi ( __1__X123 , __1__X124 , 0 ) )):0 ))) ) ) )
# 836 "/home/claude/cfront-3/src/find.cpp"
{ 
# 837 "/home/claude/cfront-3/src/find.cpp"
if (__1l -> obj_offset__6basecl && (__1first == 0 ))
# 838 "/home/claude/cfront-3/src/find.cpp"
return
# 838 "/home/claude/cfront-3/src/find.cpp"
__1l -> obj_offset__6basecl ;

# 840 "/home/claude/cfront-3/src/find.cpp"
{ { Pbcl __3ll ;

# 840 "/home/claude/cfront-3/src/find.cpp"
__3ll = __0this -> baselist__8classdef ;

# 840 "/home/claude/cfront-3/src/find.cpp"
for(;__3ll != __1l ;__3ll = __3ll -> next__6basecl ) { 
# 841 "/home/claude/cfront-3/src/find.cpp"
if (__3ll -> base__4node == 77 )continue ;
{ int __4i ;

# 842 "/home/claude/cfront-3/src/find.cpp"
__4i = has_allocated_base__8classdefFP8classdefUc ( __3ll -> bclass__6basecl , __1bcl , (unsigned char )(__3ll == __0this -> baselist__8classdef )) ;

# 844 "/home/claude/cfront-3/src/find.cpp"
if (__4i ){ 
# 845 "/home/claude/cfront-3/src/find.cpp"
link_compat_hack = 1 ;

# 847 "/home/claude/cfront-3/src/find.cpp"
return 0 ;
}

# 848 "/home/claude/cfront-3/src/find.cpp"
}
}

# 849 "/home/claude/cfront-3/src/find.cpp"
}

# 849 "/home/claude/cfront-3/src/find.cpp"
}
}

# 853 "/home/claude/cfront-3/src/find.cpp"
if ((__1l -> base__4node == 77 )|| (__1l != __0this -> baselist__8classdef )){ 
# 856 "/home/claude/cfront-3/src/find.cpp"
int __3i ;

# 856 "/home/claude/cfront-3/src/find.cpp"
__3i = has_allocated_base__8classdefFP8classdefUc ( __1l -> bclass__6basecl , __1bcl , (unsigned char )0 ) ;
if (__3i )return (__1l -> obj_offset__6basecl + __3i );
}
}
return 0 ;

# 860 "/home/claude/cfront-3/src/find.cpp"
}

# 860 "/home/claude/cfront-3/src/find.cpp"
}
}

# 863 "/home/claude/cfront-3/src/find.cpp"
extern bit Vvtab ;
extern bit Vvbc_inher ;
extern bit Vvbc_alloc ;

# 868 "/home/claude/cfront-3/src/find.cpp"
const char *has_allocated_base__8classdefFPCc (register struct classdef *__0this , const char *__1str )
# 874 "/home/claude/cfront-3/src/find.cpp"
{ 
# 876 "/home/claude/cfront-3/src/find.cpp"
{ { Pbcl __1l ;

# 876 "/home/claude/cfront-3/src/find.cpp"
__1l = __0this -> baselist__8classdef ;

# 876 "/home/claude/cfront-3/src/find.cpp"
for(;__1l ;__1l = __1l -> next__6basecl ) { 
# 877 "/home/claude/cfront-3/src/find.cpp"
if (__1l -> base__4node == 77 ){ 
# 880 "/home/claude/cfront-3/src/find.cpp"
if (__1l -> allocated__6basecl == 1 )
# 881 "/home/claude/cfront-3/src/find.cpp"
Nvbc_alloc = __1l ;
else 
# 883 "/home/claude/cfront-3/src/find.cpp"
if (strcmp ( __1str , __1l -> bclass__6basecl -> string__8classdef ) == 0 ){ 
# 885 "/home/claude/cfront-3/src/find.cpp"
Vvbc_inher = 1 ;
return (const char *)0 ;
}
continue ;
}

# 891 "/home/claude/cfront-3/src/find.cpp"
{ Pclass __2bc ;

# 891 "/home/claude/cfront-3/src/find.cpp"
__2bc = __1l -> bclass__6basecl ;
{ { Pbcl __2ll ;

# 892 "/home/claude/cfront-3/src/find.cpp"
__2ll = __2bc -> baselist__8classdef ;

# 892 "/home/claude/cfront-3/src/find.cpp"
for(;__2ll ;__2ll = __2ll -> next__6basecl ) { 
# 893 "/home/claude/cfront-3/src/find.cpp"
if (__2ll -> base__4node != 77 )continue ;

# 895 "/home/claude/cfront-3/src/find.cpp"
if ((__2ll -> allocated__6basecl == 1 )&& (strcmp ( __1str , __2ll -> bclass__6basecl -> string__8classdef ) == 0 ))
# 896 "/home/claude/cfront-3/src/find.cpp"
{ 
# 896 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X125 ;

# 896 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X126 ;

# 897 "/home/claude/cfront-3/src/find.cpp"
if (( (__1__X125 = __2bc ), ( (__1__X126 = __0this -> baselist__8classdef -> bclass__6basecl ), ( ((__1__X125 == __1__X126 )?1 :((__1__X125 && __1__X126 )?(((int )same_class__8classdefFP8classdefi (
# 897 "/home/claude/cfront-3/src/find.cpp"
__1__X125 , __1__X126 , 0 ) )):0 ))) ) ) ){ 
# 898 "/home/claude/cfront-3/src/find.cpp"
Vvtab = __2ll -> bclass__6basecl -> has_vvtab__8classdef ;
return (const char *)0 ;
}
return __2bc -> string__8classdef ;
}
}

# 903 "/home/claude/cfront-3/src/find.cpp"
}

# 903 "/home/claude/cfront-3/src/find.cpp"
}

# 903 "/home/claude/cfront-3/src/find.cpp"
}
}
if (Nvbc_alloc == 0 )Vvbc_alloc = 1 ;
return (const char *)0 ;

# 906 "/home/claude/cfront-3/src/find.cpp"
}

# 906 "/home/claude/cfront-3/src/find.cpp"
}
}

# 927 "/home/claude/cfront-3/src/find.cpp"
Pname vfct__FP8classdefPc (Pclass __1cl , char *__1s );

# 927 "/home/claude/cfront-3/src/find.cpp"
Pname vfct__FP8classdefPc (Pclass __1cl , char *__1s )
# 934 "/home/claude/cfront-3/src/find.cpp"
{ 
# 935 "/home/claude/cfront-3/src/find.cpp"
Pname __1n ;

# 935 "/home/claude/cfront-3/src/find.cpp"
__1n = look__5tableFPCcUc ( __1cl -> memtbl__8classdef , (const char *)__1s , (unsigned char )0 ) ;
if (__1n )return __1n ;

# 938 "/home/claude/cfront-3/src/find.cpp"
{ { Pbcl __1b ;

# 938 "/home/claude/cfront-3/src/find.cpp"
__1b = __1cl -> baselist__8classdef ;

# 938 "/home/claude/cfront-3/src/find.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 939 "/home/claude/cfront-3/src/find.cpp"
Pname __2nn ;

# 939 "/home/claude/cfront-3/src/find.cpp"
__2nn = vfct__FP8classdefPc ( __1b -> bclass__6basecl , __1s ) ;
if (__2nn ){ 
# 942 "/home/claude/cfront-3/src/find.cpp"
if (__1n && (__1n != __2nn )){ 
# 943 "/home/claude/cfront-3/src/find.cpp"
Pclass __4ncl ;
Pclass __4nncl ;

# 943 "/home/claude/cfront-3/src/find.cpp"
__4ncl = (((struct classdef *)(((struct classdef *)__1n -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))));
__4nncl = (((struct classdef *)(((struct classdef *)__2nn -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))));

# 946 "/home/claude/cfront-3/src/find.cpp"
if (is_base__8classdefFPCcPUci ( __4nncl , __4ncl -> string__8classdef , (TOK *)0 , 0 ) )
# 947 "/home/claude/cfront-3/src/find.cpp"
__1n = __2nn ;
}
else 
# 950 "/home/claude/cfront-3/src/find.cpp"
__1n = __2nn ;
}
}

# 954 "/home/claude/cfront-3/src/find.cpp"
return __1n ;

# 954 "/home/claude/cfront-3/src/find.cpp"
}

# 954 "/home/claude/cfront-3/src/find.cpp"
}
}

# 828 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 957 "/home/claude/cfront-3/src/find.cpp"
Pexpr rptr__FP4typeP4expri (Ptype __1t , Pexpr __1p , int __1offset )
# 962 "/home/claude/cfront-3/src/find.cpp"
{ 
# 963 "/home/claude/cfront-3/src/find.cpp"
if (__1t == 0 )error__FiPCc ( (int )'i' , (const char *)"rptr(), t==0 (type passed for cast)")
# 963 "/home/claude/cfront-3/src/find.cpp"
;
{ Pexpr __1pp ;

# 965 "/home/claude/cfront-3/src/find.cpp"
register struct cast *__0__X130 ;

# 964 "/home/claude/cfront-3/src/find.cpp"
__1pp = __1p ;

# 966 "/home/claude/cfront-3/src/find.cpp"
if (__1offset ){ 
# 967 "/home/claude/cfront-3/src/find.cpp"
Pexpr __2i ;

# 968 "/home/claude/cfront-3/src/find.cpp"
register struct cast *__0__X127 ;

# 968 "/home/claude/cfront-3/src/find.cpp"
struct type *__2__X128 ;

# 968 "/home/claude/cfront-3/src/find.cpp"
struct ival *__0__X129 ;

# 967 "/home/claude/cfront-3/src/find.cpp"
__2i = (struct expr *)( (__0__X129 = 0 ), ( ((__0__X129 || (__0__X129 = (struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival)))
# 967 "/home/claude/cfront-3/src/find.cpp"
))?( (__0__X129 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X129 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 ) ),
# 967 "/home/claude/cfront-3/src/find.cpp"
(__0__X129 -> __O2__4expr.i1 = ((long long )__1offset ))) :0 ), __0__X129 ) ) ;

# 969 "/home/claude/cfront-3/src/find.cpp"
__1pp = (struct expr *)( (__0__X127 = 0 ), ( (__2__X128 = Pchar_type ), ( ((__0__X127 || (__0__X127 = (struct cast *)__nw__4exprSFUl ( (unsigned
# 969 "/home/claude/cfront-3/src/find.cpp"
long )(sizeof (struct cast))) ))?( (__0__X127 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X127 ), (unsigned char )191 , __1pp , (struct
# 969 "/home/claude/cfront-3/src/find.cpp"
expr *)0 ) ), (__0__X127 -> __O1__4expr.tp = (__0__X127 -> __O4__4expr.tp2 = __2__X128 ))) :0 ), __0__X127 ) ) ) ;
__1pp = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )54 , __1pp , __2i ) ;
}
__1pp = (struct expr *)( (__0__X130 = 0 ), ( ((__0__X130 || (__0__X130 = (struct cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast)))
# 972 "/home/claude/cfront-3/src/find.cpp"
))?( (__0__X130 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X130 ), (unsigned char )191 , __1pp , (struct expr *)0 ) ), (__0__X130 ->
# 972 "/home/claude/cfront-3/src/find.cpp"
__O1__4expr.tp = (__0__X130 -> __O4__4expr.tp2 = __1t ))) :0 ), __0__X130 ) ) ;
return __1pp ;

# 973 "/home/claude/cfront-3/src/find.cpp"
}
}

# 995 "/home/claude/cfront-3/src/find.cpp"
int friend_check__FP8classdefT1P3fct (Pclass __1start , Pclass __1stop , Pfct __1f );

# 995 "/home/claude/cfront-3/src/find.cpp"
int friend_check__FP8classdefT1P3fct (Pclass __1start , Pclass __1stop , Pfct __1f )
# 1000 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1003 "/home/claude/cfront-3/src/find.cpp"
if (has_friend__8classdefFP3fct ( __1start , __1f ) )return 1 ;
if (__1stop == __1start )return 0 ;
{ { Pbcl __1b ;

# 1005 "/home/claude/cfront-3/src/find.cpp"
__1b = __1start -> baselist__8classdef ;

# 1005 "/home/claude/cfront-3/src/find.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 1006 "/home/claude/cfront-3/src/find.cpp"
if (has_friend__8classdefFP3fct ( __1b -> bclass__6basecl , __1f ) )return 1 ;
if (friend_check__FP8classdefT1P3fct ( __1b -> bclass__6basecl , __1stop , __1f ) )return 1 ;
}
return 0 ;

# 1009 "/home/claude/cfront-3/src/find.cpp"
}

# 1009 "/home/claude/cfront-3/src/find.cpp"
}
}

# 477 "/home/claude/cfront-3/src/template.h"

# 1012 "/home/claude/cfront-3/src/find.cpp"
int has_friend__17function_templateFP4name (register struct function_template *__0this , Pname __1ifn )
# 1013 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1015 "/home/claude/cfront-3/src/find.cpp"
Ptype __1t ;

# 1015 "/home/claude/cfront-3/src/find.cpp"
__1t = __1ifn -> __O1__4expr.tp ;

# 1017 "/home/claude/cfront-3/src/find.cpp"
switch (__1t -> base__4node ){ 
# 1018 "/home/claude/cfront-3/src/find.cpp"
case 108 :
# 1019 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1020 "/home/claude/cfront-3/src/find.cpp"
Pfct __3f ;
Pname __3ftn ;

# 1020 "/home/claude/cfront-3/src/find.cpp"
__3f = (((struct fct *)(((struct fct *)__1t ))));
__3ftn = ((__3f -> fct_base__3fct == 0)?__1ifn :( (((struct templ_fct *)(((struct templ_fct *)__3f ))))-> inst__9templ_fct -> def__10funct_inst -> fn__17function_template ) );

# 1025 "/home/claude/cfront-3/src/find.cpp"
return (strcmp ( __3ftn -> __O2__4expr.string , __0this -> fn__17function_template -> __O2__4expr.string ) == 0 );
}

# 1031 "/home/claude/cfront-3/src/find.cpp"
}

# 1033 "/home/claude/cfront-3/src/find.cpp"
return 0 ;
}

# 328 "/home/claude/cfront-3/src/cfront.h"
Pclass classtype__4typeFv (struct type *__0this );

# 470 "/home/claude/cfront-3/src/template.h"

# 1036 "/home/claude/cfront-3/src/find.cpp"
int has_friend__5templFP4name (register struct templ *__0this , Pname __1cn )
# 1037 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1039 "/home/claude/cfront-3/src/find.cpp"
if (__1cn -> __O1__4expr.tp -> base__4node != 108 )
# 1040 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1041 "/home/claude/cfront-3/src/find.cpp"
Pclass __2cl ;
Pname __2ptn ;

# 1041 "/home/claude/cfront-3/src/find.cpp"
__2cl = classtype__4typeFv ( __1cn -> __O1__4expr.tp ) ;
__2ptn = ( (((struct templ_classdef *)(((struct templ_classdef *)__2cl ))))-> inst__14templ_classdef -> def__10templ_inst -> namep__5templ ) ;

# 1045 "/home/claude/cfront-3/src/find.cpp"
return (strcmp ( __2ptn -> __O2__4expr.string , __0this -> namep__5templ -> __O2__4expr.string ) == 0 );
}
return 0 ;
}

# 263 "/home/claude/cfront-3/src/template.h"
struct data_template {	/* sizeof data_template == 64 */

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

# 267 "/home/claude/cfront-3/src/template.h"
Pname dat_mem__13data_template ;
Pdata next__13data_template ;
};

# 1050 "/home/claude/cfront-3/src/find.cpp"
int has_friend__13data_templateFP4name (struct data_template *__0this , Pname __1__A131 )
# 1051 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1052 "/home/claude/cfront-3/src/find.cpp"
return 0 ;
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 192 "/home/claude/cfront-3/src/template.h"
int has_friend__14basic_templateFP4name (struct basic_template *__0this , Pname );

# 1055 "/home/claude/cfront-3/src/find.cpp"
bit has_friend__8classdefFP3fct (register struct classdef *__0this , Pfct __1f )
# 1059 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1059 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X133 ;

# 1059 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X134 ;

# 1063 "/home/claude/cfront-3/src/find.cpp"
if (( (__1__X133 = __1f -> memof__3fct ), ( (__1__X134 = __0this ), ( ((__1__X133 == __1__X134 )?1 :((__1__X133 && __1__X134 )?(((int )same_class__8classdefFP8classdefi ( __1__X133 ,
# 1063 "/home/claude/cfront-3/src/find.cpp"
__1__X134 , 0 ) )):0 ))) ) ) )return (unsigned char )1 ;
{ { Plist __1l ;

# 1064 "/home/claude/cfront-3/src/find.cpp"
__1l = __0this -> friend_list__8classdef ;

# 1064 "/home/claude/cfront-3/src/find.cpp"
for(;__1l ;__1l = __1l -> l__9name_list ) { 
# 1065 "/home/claude/cfront-3/src/find.cpp"
Pname __2fr ;
Ptype __2frt ;

# 1065 "/home/claude/cfront-3/src/find.cpp"
__2fr = __1l -> f__9name_list ;
__2frt = __2fr -> __O1__4expr.tp ;

# 1068 "/home/claude/cfront-3/src/find.cpp"
switch (__2frt -> base__4node ){ 
# 1068 "/home/claude/cfront-3/src/find.cpp"
unsigned long __2__X135 ;

# 1069 "/home/claude/cfront-3/src/find.cpp"
case 108 :
# 1070 "/home/claude/cfront-3/src/find.cpp"
if ((((struct type *)__1f ))== __2frt )return (unsigned char )1 ;
break ;
case 76 :
# 1073 "/home/claude/cfront-3/src/find.cpp"
__1l -> f__9name_list = (__2fr = (((struct gen *)(((struct gen *)__2frt ))))-> fct_list__3gen -> f__9name_list );
if (__2fr -> __O1__4expr.tp == (((struct type *)__1f )))return (unsigned char )1 ;
case 6 :
# 1076 "/home/claude/cfront-3/src/find.cpp"
break ;
default :
# 1078 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1078 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V132 ;

# 1078 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"bad friend %k", (const struct ea *)( (__2__X135 =
# 1078 "/home/claude/cfront-3/src/find.cpp"
__2fr -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__V132 )-> __O1__2ea.i = __2__X135 ), 0 ) ), (& __0__V132 )) )
# 1078 "/home/claude/cfront-3/src/find.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}

# 1082 "/home/claude/cfront-3/src/find.cpp"
{ Pname __1fn ;

# 1082 "/home/claude/cfront-3/src/find.cpp"
__1fn = (me ?me :((cc -> nof__11dcl_context && (cc -> nof__11dcl_context -> __O1__4expr.tp == (((struct type *)__1f ))))?cc -> nof__11dcl_context :(((struct name *)0 ))));

# 1084 "/home/claude/cfront-3/src/find.cpp"
if (__1fn )
# 1085 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1087 "/home/claude/cfront-3/src/find.cpp"
{ { Pcons __2p ;

# 1087 "/home/claude/cfront-3/src/find.cpp"
__2p = __0this -> templ_friends__8classdef ;

# 1087 "/home/claude/cfront-3/src/find.cpp"
for(;__2p ;__2p = __2p -> cdr__4cons ) 
# 1088 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1089 "/home/claude/cfront-3/src/find.cpp"
Ptempl_base __3ptb ;

# 1089 "/home/claude/cfront-3/src/find.cpp"
__3ptb = (((struct basic_template *)(((struct basic_template *)__2p -> car__4cons ))));
if (__3ptb && ((*(((int (*)(struct basic_template *__0this , Pname ))(__3ptb -> __vptr__14basic_template [2]).f))))( ((struct basic_template *)((((char *)__3ptb ))+ (__3ptb -> __vptr__14basic_template [2]).d)), __1fn ) )return
# 1090 "/home/claude/cfront-3/src/find.cpp"
(unsigned char )1 ;
}

# 1091 "/home/claude/cfront-3/src/find.cpp"
}

# 1091 "/home/claude/cfront-3/src/find.cpp"
}
}

# 1094 "/home/claude/cfront-3/src/find.cpp"
if (__1f -> memof__3fct )return has_friend__8classdefFP8classdef ( __0this , __1f -> memof__3fct ) ;
return (unsigned char )0 ;

# 1095 "/home/claude/cfront-3/src/find.cpp"
}

# 1095 "/home/claude/cfront-3/src/find.cpp"
}

# 1095 "/home/claude/cfront-3/src/find.cpp"
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 1279 "/home/claude/cfront-3/src/cfront.h"

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

# 1098 "/home/claude/cfront-3/src/find.cpp"
bit has_friend__8classdefFP8classdef (register struct classdef *__0this , Pclass __1cl )
# 1102 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1105 "/home/claude/cfront-3/src/find.cpp"
{ { Plist __1l ;

# 1106 "/home/claude/cfront-3/src/find.cpp"
int __1__Xt00a3glwanawcnm ;

# 1105 "/home/claude/cfront-3/src/find.cpp"
__1l = __0this -> friend_list__8classdef ;

# 1105 "/home/claude/cfront-3/src/find.cpp"
for(;__1l ;__1l = __1l -> l__9name_list ) { 
# 1106 "/home/claude/cfront-3/src/find.cpp"
Pname __2fr ;
Ptype __2frt ;

# 1106 "/home/claude/cfront-3/src/find.cpp"
__2fr = __1l -> f__9name_list ;
__2frt = __2fr -> __O1__4expr.tp ;
switch (__2frt -> base__4node ){ 
# 1108 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X137 ;

# 1108 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X138 ;

# 1109 "/home/claude/cfront-3/src/find.cpp"
case 6 :
# 1111 "/home/claude/cfront-3/src/find.cpp"
if (( (__1__X137 = __1cl ), ( (__1__X138 = (((struct classdef *)(((struct classdef *)__2frt ))))), ( ((__1__X137 == __1__X138 )?1 :((__1__X137 && __1__X138 )?(((int
# 1111 "/home/claude/cfront-3/src/find.cpp"
)same_class__8classdefFP8classdefi ( __1__X137 , __1__X138 , 1 ) )):0 ))) ) ) )
# 1112 "/home/claude/cfront-3/src/find.cpp"
return (unsigned char )1 ;
case 108 :
# 1114 "/home/claude/cfront-3/src/find.cpp"
case 76 :
# 1115 "/home/claude/cfront-3/src/find.cpp"
break ;
default :
# 1117 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1117 "/home/claude/cfront-3/src/find.cpp"
unsigned long __2__X139 ;

# 1117 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1117 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V136 ;

# 1117 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"bad friend %k", (const struct ea *)( (__2__X139 =
# 1117 "/home/claude/cfront-3/src/find.cpp"
__2frt -> base__4node ), ( (( ((& __0__V136 )-> __O1__2ea.i = __2__X139 ), 0 ) ), (& __0__V136 )) ) ,
# 1117 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1117 "/home/claude/cfront-3/src/find.cpp"
}
}
}

# 1121 "/home/claude/cfront-3/src/find.cpp"
if (( (__1__Xt00a3glwanawcnm = ((((struct type *)__1cl )-> base__4node == 108 )?(((struct fct *)(((struct fct *)((struct type *)__1cl )))))-> fct_base__3fct :((((struct type *)__1cl )-> base__4node ==
# 1121 "/home/claude/cfront-3/src/find.cpp"
6 )?(((struct classdef *)(((struct classdef *)((struct type *)__1cl )))))-> class_base__8classdef :(((int )0 ))))), (((unsigned char )((__1__Xt00a3glwanawcnm == 4)|| (__1__Xt00a3glwanawcnm == 5))))) ){ 
# 1122 "/home/claude/cfront-3/src/find.cpp"
Pname __2tn ;
# 1122 "/home/claude/cfront-3/src/find.cpp"
__2tn = find_cn__6ktableFPCc ( __1cl -> k_tbl__8classdef , __1cl -> string__8classdef ) ;

# 1124 "/home/claude/cfront-3/src/find.cpp"
{ { Pcons __2p ;

# 1124 "/home/claude/cfront-3/src/find.cpp"
__2p = __0this -> templ_friends__8classdef ;

# 1124 "/home/claude/cfront-3/src/find.cpp"
for(;__2p ;__2p = __2p -> cdr__4cons ) { 
# 1125 "/home/claude/cfront-3/src/find.cpp"
Ptempl_base __3ptb ;

# 1125 "/home/claude/cfront-3/src/find.cpp"
__3ptb = (((struct basic_template *)(((struct basic_template *)__2p -> car__4cons ))));
if (__3ptb && ((*(((int (*)(struct basic_template *__0this , Pname ))(__3ptb -> __vptr__14basic_template [2]).f))))( ((struct basic_template *)((((char *)__3ptb ))+ (__3ptb -> __vptr__14basic_template [2]).d)), __2tn ) )return
# 1126 "/home/claude/cfront-3/src/find.cpp"
(unsigned char )1 ;
}

# 1127 "/home/claude/cfront-3/src/find.cpp"
}

# 1127 "/home/claude/cfront-3/src/find.cpp"
}
}

# 1130 "/home/claude/cfront-3/src/find.cpp"
if (__1cl -> in_fct__4type )return has_friend__8classdefFP3fct ( __0this , ((struct fct *)(((struct fct *)__1cl -> in_fct__4type -> __O1__4expr.tp )))) ;
if (__1cl -> in_class__4type )return has_friend__8classdefFP8classdef ( __0this , __1cl -> in_class__4type ) ;
return (unsigned char )0 ;

# 1132 "/home/claude/cfront-3/src/find.cpp"
}

# 1132 "/home/claude/cfront-3/src/find.cpp"
}
}

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 1135 "/home/claude/cfront-3/src/find.cpp"
Pname find_virtual__FP8classdefP4name (Pclass __1cl , Pname __1s );

# 1135 "/home/claude/cfront-3/src/find.cpp"
Pname find_virtual__FP8classdefP4name (Pclass __1cl , Pname __1s )
# 1139 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1140 "/home/claude/cfront-3/src/find.cpp"
{ { Pbcl __1b ;

# 1140 "/home/claude/cfront-3/src/find.cpp"
__1b = __1cl -> baselist__8classdef ;

# 1140 "/home/claude/cfront-3/src/find.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 1141 "/home/claude/cfront-3/src/find.cpp"
Pclass __2bcl ;
Pname __2n ;

# 1141 "/home/claude/cfront-3/src/find.cpp"
__2bcl = __1b -> bclass__6basecl ;

# 1143 "/home/claude/cfront-3/src/find.cpp"
if (__2n = look__5tableFPCcUc ( __2bcl -> memtbl__8classdef , __1s -> __O2__4expr.string , (unsigned char )0 ) ){ 
# 1145 "/home/claude/cfront-3/src/find.cpp"
if (__2n -> base__4node ==
# 1145 "/home/claude/cfront-3/src/find.cpp"
25 )
# 1146 "/home/claude/cfront-3/src/find.cpp"
continue ;
{ Pfct __3f ;

# 1147 "/home/claude/cfront-3/src/find.cpp"
__3f = (((struct fct *)(((struct fct *)__2n -> __O1__4expr.tp ))));
if (__3f -> base__4node == 76 ){ 
# 1149 "/home/claude/cfront-3/src/find.cpp"
{ { Plist __4gl ;

# 1149 "/home/claude/cfront-3/src/find.cpp"
__4gl = (((struct gen *)(((struct gen *)__3f ))))-> fct_list__3gen ;

# 1149 "/home/claude/cfront-3/src/find.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) { 
# 1150 "/home/claude/cfront-3/src/find.cpp"
__2n = __4gl -> f__9name_list ;

# 1153 "/home/claude/cfront-3/src/find.cpp"
if (check__4typeFP4typeUcT2 ( __2n -> __O1__4expr.tp , __1s -> __O1__4expr.tp , (unsigned char )77 , (unsigned char )0 ) )continue ;
# 1153 "/home/claude/cfront-3/src/find.cpp"

# 1154 "/home/claude/cfront-3/src/find.cpp"
if ((((struct fct *)(((struct fct *)__2n -> __O1__4expr.tp ))))-> f_virtual__3fct )return __2n ;
}

# 1155 "/home/claude/cfront-3/src/find.cpp"
}

# 1155 "/home/claude/cfront-3/src/find.cpp"
}
}
else 
# 1158 "/home/claude/cfront-3/src/find.cpp"
if (__3f -> f_virtual__3fct && (check__4typeFP4typeUcT2 ( __2n -> __O1__4expr.tp , __1s -> __O1__4expr.tp , (unsigned char )77 , (unsigned char
# 1158 "/home/claude/cfront-3/src/find.cpp"
)0 ) == 0 ))
# 1159 "/home/claude/cfront-3/src/find.cpp"
return __2n ;

# 1159 "/home/claude/cfront-3/src/find.cpp"
}
}
else if (__2n = find_virtual__FP8classdefP4name ( __2bcl , __1s ) )
# 1162 "/home/claude/cfront-3/src/find.cpp"
return __2n ;
}
return (struct name *)0 ;

# 1164 "/home/claude/cfront-3/src/find.cpp"
}

# 1164 "/home/claude/cfront-3/src/find.cpp"
}
}

# 1167 "/home/claude/cfront-3/src/find.cpp"
Pname dummy_fct = 0 ;

# 1170 "/home/claude/cfront-3/src/find.cpp"
static int is_accessible__FP4nameP8classdefUc (Pname __1n , Pclass __1this_class , bit __1noCdcl )
# 1172 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1172 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X140 ;

# 1172 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X141 ;

# 1172 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X142 ;

# 1172 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X143 ;

# 1183 "/home/claude/cfront-3/src/find.cpp"
if (( (__1__X140 = __1this_class ), ( (__1__X141 = mec ), ( ((__1__X140 == __1__X141 )?1 :((__1__X140 && __1__X141 )?(((int )same_class__8classdefFP8classdefi ( __1__X140 , __1__X141 ,
# 1183 "/home/claude/cfront-3/src/find.cpp"
0 ) )):0 ))) ) ) || (mec && has_friend__8classdefFP8classdef ( __1this_class , mec ) ))
# 1184 "/home/claude/cfront-3/src/find.cpp"
return 1 ;
if ((mef && ((mec == 0 )|| ( (__1__X142 = mec ), ( (__1__X143 = mef -> memof__3fct ), ( ((__1__X142 == __1__X143 )?1 :((__1__X142 &&
# 1185 "/home/claude/cfront-3/src/find.cpp"
__1__X143 )?(((int )same_class__8classdefFP8classdefi ( __1__X142 , __1__X143 , 0 ) )):0 ))) ) ) ))&& has_friend__8classdefFP3fct ( __1this_class , mef ) )
# 1186 "/home/claude/cfront-3/src/find.cpp"
return 1 ;
# 1186 "/home/claude/cfront-3/src/find.cpp"

# 1188 "/home/claude/cfront-3/src/find.cpp"
if (__1n -> n_protect__4name && tcl ){ 
# 1188 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X146 ;

# 1188 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X147 ;

# 1189 "/home/claude/cfront-3/src/find.cpp"
if (mec )
# 1190 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1190 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X144 ;

# 1190 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X145 ;

# 1191 "/home/claude/cfront-3/src/find.cpp"
if (has_friend__8classdefFP8classdef ( tcl , mec ) || (has_base__8classdefFP8classdefiT2 ( mec , __1this_class , 0 , 0 ) && (( (__1__X144 = tcl ),
# 1191 "/home/claude/cfront-3/src/find.cpp"
( (__1__X145 = mec ), ( ((__1__X144 == __1__X145 )?1 :((__1__X144 && __1__X145 )?(((int )same_class__8classdefFP8classdefi ( __1__X144 , __1__X145 , 0 ) )):0 ))) ) )
# 1191 "/home/claude/cfront-3/src/find.cpp"
|| has_base__8classdefFP8classdefiT2 ( tcl , mec , 0 , 0 ) )))
# 1194 "/home/claude/cfront-3/src/find.cpp"
return 1 ;
}

# 1197 "/home/claude/cfront-3/src/find.cpp"
if (mef && ((mec == 0 )|| ( (__1__X146 = mec ), ( (__1__X147 = mef -> memof__3fct ), ( ((__1__X146 == __1__X147 )?1 :((__1__X146 &&
# 1197 "/home/claude/cfront-3/src/find.cpp"
__1__X147 )?(((int )same_class__8classdefFP8classdefi ( __1__X146 , __1__X147 , 0 ) )):0 ))) ) ) ))
# 1198 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1199 "/home/claude/cfront-3/src/find.cpp"
if (has_base__8classdefFP8classdefiT2 ( tcl , __1this_class , 0 ,
# 1199 "/home/claude/cfront-3/src/find.cpp"
0 ) && friend_check__FP8classdefT1P3fct ( tcl , __1this_class , mef ) )
# 1202 "/home/claude/cfront-3/src/find.cpp"
return 1 ;
}
}

# 1207 "/home/claude/cfront-3/src/find.cpp"
if (__1noCdcl )return 0 ;

# 1209 "/home/claude/cfront-3/src/find.cpp"
if ((((Cdcl && (Cdcl -> base__4node == 85 ))&& (Cdcl -> n_stclass__4name == 31 ))&& ((! Cdcl -> __O1__4expr.tp )|| (skiptypedefs__4typeFv ( Cdcl -> __O1__4expr.tp )
# 1209 "/home/claude/cfront-3/src/find.cpp"
-> base__4node != 108 )))&& Cdcl -> __O2__4name.n_qualifier )
# 1214 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1215 "/home/claude/cfront-3/src/find.cpp"
Pbase __2bn ;
Pclass __2cl ;

# 1217 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X148 ;

# 1217 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X149 ;

# 1215 "/home/claude/cfront-3/src/find.cpp"
__2bn = (((struct basetype *)(((struct basetype *)Cdcl -> __O2__4name.n_qualifier -> __O1__4expr.tp ))));
__2cl = (((struct classdef *)(((struct classdef *)__2bn -> b_name__8basetype -> __O1__4expr.tp ))));

# 1218 "/home/claude/cfront-3/src/find.cpp"
if ((( (__1__X148 = __2cl ), ( (__1__X149 = __1this_class ), ( ((__1__X148 == __1__X149 )?1 :((__1__X148 && __1__X149 )?(((int )same_class__8classdefFP8classdefi ( __1__X148 , __1__X149 ,
# 1218 "/home/claude/cfront-3/src/find.cpp"
0 ) )):0 ))) ) ) || (__1n -> n_protect__4name && has_base__8classdefFP8classdefiT2 ( __2cl , __1this_class , 0 , 0 ) ))|| has_friend__8classdefFP8classdef (
# 1218 "/home/claude/cfront-3/src/find.cpp"
__1this_class , __2cl ) )
# 1221 "/home/claude/cfront-3/src/find.cpp"
return 1 ;
}

# 1224 "/home/claude/cfront-3/src/find.cpp"
return 0 ;
}

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 449 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8classdefFP4name (struct classdef *__0this , Pname );

# 486 "/home/claude/cfront-3/src/cfront.h"
Pexpr find_in_base__8classdefFPCcP8classdefiT3 (struct classdef *__0this , const char *, Pclass , int , int );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 1232 "/home/claude/cfront-3/src/cfront.h"
extern int make_assignment__FP4name (Pname );

# 1227 "/home/claude/cfront-3/src/find.cpp"
Pexpr find_name__8classdefFPCcP8classdefiT3 (register struct classdef *__0this , const char *__1s , Pclass __1cl , int __1access_only , int __1newflag )
# 1236 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1238 "/home/claude/cfront-3/src/find.cpp"
Pname __1n ;

# 1239 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X205 ;

# 1239 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X206 ;

# 1238 "/home/claude/cfront-3/src/find.cpp"
__1n = look__5tableFPCcUc ( __0this -> memtbl__8classdef , __1s , (unsigned char )0 ) ;
if (__1n == 0 ){ 
# 1240 "/home/claude/cfront-3/src/find.cpp"
if ((__0this -> in_class__4type && (__0this -> templ_base__4type == 0))&& (__0this -> in_class__4type -> class_base__8classdef == 4))
# 1241 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1242 "/home/claude/cfront-3/src/find.cpp"
Pname __3nn ;
# 1242 "/home/claude/cfront-3/src/find.cpp"
__3nn = look__5tableFPCcUc ( __0this -> in_class__4type -> memtbl__8classdef , __0this -> string__8classdef , (unsigned char )6 ) ;
if (__3nn ){ 
# 1244 "/home/claude/cfront-3/src/find.cpp"
Pclass __4cl ;

# 1244 "/home/claude/cfront-3/src/find.cpp"
__4cl = (((struct classdef *)(((struct classdef *)__3nn -> __O1__4expr.tp ))));
__1n = look__5tableFPCcUc ( __4cl -> memtbl__8classdef , __1s , (unsigned char )0 ) ;
}
}
}

# 1250 "/home/claude/cfront-3/src/find.cpp"
if (__1n ){ 
# 1250 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X190 ;

# 1250 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X191 ;

# 1251 "/home/claude/cfront-3/src/find.cpp"
if (__1n -> __O1__4expr.tp && (! __1access_only )){ 
# 1252 "/home/claude/cfront-3/src/find.cpp"
switch (__1n -> __O1__4expr.tp -> base__4node ){ 
# 1253 "/home/claude/cfront-3/src/find.cpp"
case 76 :
# 1254 "/home/claude/cfront-3/src/find.cpp"
break ;
case 108 :
# 1256 "/home/claude/cfront-3/src/find.cpp"
if ((((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))))-> f_virtual__3fct == 0 ){ 
# 1257 "/home/claude/cfront-3/src/find.cpp"
if (__1n -> n_dcl_printed__4name == 0 )dcl_print__4nameFUc ( __1n , (unsigned
# 1257 "/home/claude/cfront-3/src/find.cpp"
char )0 ) ;
break ;
}
default :
# 1261 "/home/claude/cfront-3/src/find.cpp"
if (__0this -> class_base__8classdef == 4)
# 1262 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1263 "/home/claude/cfront-3/src/find.cpp"
current_instantiation = __0this ;
}
dcl_print__8classdefFP4name ( __0this , (struct name *)0 ) ;
if (__0this -> class_base__8classdef == 4)
# 1267 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1268 "/home/claude/cfront-3/src/find.cpp"
current_instantiation = 0 ;
}
}
}

# 1273 "/home/claude/cfront-3/src/find.cpp"
if (__1n -> base__4node == 25 ){ 
# 1274 "/home/claude/cfront-3/src/find.cpp"
if (mex && (__1n -> n_scope__4name == 0 )){ 
# 1275 "/home/claude/cfront-3/src/find.cpp"
if (is_accessible__FP4nameP8classdefUc ( __1n , __0this , (unsigned
# 1275 "/home/claude/cfront-3/src/find.cpp"
char )0 ) == 0 )
# 1276 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1276 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X186 ;

# 1276 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X187 ;

# 1276 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X188 ;

# 1276 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X189 ;

# 1277 "/home/claude/cfront-3/src/find.cpp"
if (me == dummy_fct ){ 
# 1277 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X185 ;

# 1278 "/home/claude/cfront-3/src/find.cpp"
if (mec )
# 1279 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1279 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V150 ;

# 1279 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V151 ;

# 1279 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V152 ;

# 1279 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cannot access%n: %sM", (const struct ea *)( (__2__X185 = (const void
# 1279 "/home/claude/cfront-3/src/find.cpp"
*)mec ), ( ((& __0__V150 )-> __O1__2ea.p = __2__X185 ), (& __0__V150 )) ) , (const struct ea *)( ((&
# 1279 "/home/claude/cfront-3/src/find.cpp"
__0__V151 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V151 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V152 , (const
# 1279 "/home/claude/cfront-3/src/find.cpp"
void *)(__1n -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1279 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} else 
# 1281 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1281 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V153 ;

# 1281 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V154 ;

# 1281 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"G scope cannot access%n: %sM", (const struct ea *)( ((& __0__V153 )-> __O1__2ea.p =
# 1281 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1n )), (& __0__V153 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V154 , (const void *)(__1n ->
# 1281 "/home/claude/cfront-3/src/find.cpp"
n_protect__4name ?"protected":(((char *)"private")))) , (const struct ea *)ea0 ,
# 1281 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 ) ;
} }
else 
# 1282 "/home/claude/cfront-3/src/find.cpp"
if (mec && ((mef == 0 )|| (! ( (__1__X186 = mec ), ( (__1__X187 = mef -> memof__3fct ),
# 1282 "/home/claude/cfront-3/src/find.cpp"
( ((__1__X186 == __1__X187 )?1 :((__1__X186 && __1__X187 )?(((int )same_class__8classdefFP8classdefi ( __1__X186 , __1__X187 , 0 ) )):0 ))) ) ) )))
# 1283 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1283 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V155 ;
# 1283 "/home/claude/cfront-3/src/find.cpp"

# 1283 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V156 ;

# 1283 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V157 ;

# 1283 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cannot access%n: %sM", (const struct ea *)( (__2__X188 = (const void
# 1283 "/home/claude/cfront-3/src/find.cpp"
*)mec ), ( ((& __0__V155 )-> __O1__2ea.p = __2__X188 ), (& __0__V155 )) ) , (const struct ea *)( ((&
# 1283 "/home/claude/cfront-3/src/find.cpp"
__0__V156 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V156 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V157 , (const
# 1283 "/home/claude/cfront-3/src/find.cpp"
void *)(__1n -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1283 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} else 
# 1285 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1285 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V158 ;

# 1285 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V159 ;

# 1285 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V160 ;

# 1285 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n cannot access%n: %sM", (const struct ea *)( (__2__X189 = (const void
# 1285 "/home/claude/cfront-3/src/find.cpp"
*)me ), ( ((& __0__V158 )-> __O1__2ea.p = __2__X189 ), (& __0__V158 )) ) , (const struct ea *)( ((&
# 1285 "/home/claude/cfront-3/src/find.cpp"
__0__V159 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V159 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V160 , (const
# 1285 "/home/claude/cfront-3/src/find.cpp"
void *)(__1n -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1285 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} mex = 0 ;
}
}
mex = 0 ;
return find_in_base__8classdefFPCcP8classdefiT3 ( __0this , __1s , __1cl , __1access_only , __1newflag ) ;
}

# 1293 "/home/claude/cfront-3/src/find.cpp"
if ((__1cl == 0 )|| ( (__1__X190 = __1cl ), ( (__1__X191 = __0this ), ( ((__1__X190 == __1__X191 )?1 :((__1__X190 && __1__X191 )?(((int )same_class__8classdefFP8classdefi (
# 1293 "/home/claude/cfront-3/src/find.cpp"
__1__X190 , __1__X191 , 0 ) )):0 ))) ) ) ){ 
# 1294 "/home/claude/cfront-3/src/find.cpp"
if (((mptr == 0 )&& (__1n -> n_stclass__4name != 31 ))&& (__1n ->
# 1294 "/home/claude/cfront-3/src/find.cpp"
n_stclass__4name != 13 ))
# 1296 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1297 "/home/claude/cfront-3/src/find.cpp"
Ptype __4t ;

# 1297 "/home/claude/cfront-3/src/find.cpp"
__4t = __1n -> __O1__4expr.tp ;

# 1301 "/home/claude/cfront-3/src/find.cpp"
if ((mex && (__1n -> n_scope__4name == 0 ))&& (__1n -> __O1__4expr.tp -> base__4node != 76 )){ 
# 1302 "/home/claude/cfront-3/src/find.cpp"
if (is_accessible__FP4nameP8classdefUc ( __1n , __0this , (unsigned
# 1302 "/home/claude/cfront-3/src/find.cpp"
char )0 ) == 0 )
# 1303 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1303 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X193 ;

# 1303 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X194 ;

# 1303 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X195 ;

# 1303 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X196 ;

# 1304 "/home/claude/cfront-3/src/find.cpp"
if (me == dummy_fct ){ 
# 1304 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X192 ;

# 1305 "/home/claude/cfront-3/src/find.cpp"
if (mec )
# 1306 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1306 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V161 ;

# 1306 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V162 ;

# 1306 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V163 ;

# 1306 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cannot access%n: %sM", (const struct ea *)( (__2__X192 = (const void
# 1306 "/home/claude/cfront-3/src/find.cpp"
*)mec ), ( ((& __0__V161 )-> __O1__2ea.p = __2__X192 ), (& __0__V161 )) ) , (const struct ea *)( ((&
# 1306 "/home/claude/cfront-3/src/find.cpp"
__0__V162 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V162 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V163 , (const
# 1306 "/home/claude/cfront-3/src/find.cpp"
void *)(__1n -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1306 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} else 
# 1308 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1308 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V164 ;

# 1308 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V165 ;

# 1308 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"G scope cannot access%n: %sM", (const struct ea *)( ((& __0__V164 )-> __O1__2ea.p =
# 1308 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1n )), (& __0__V164 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V165 , (const void *)(__1n ->
# 1308 "/home/claude/cfront-3/src/find.cpp"
n_protect__4name ?"protected":(((char *)"private")))) , (const struct ea *)ea0 ,
# 1308 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 ) ;
} }
else 
# 1309 "/home/claude/cfront-3/src/find.cpp"
if (mec && ((mef == 0 )|| (! ( (__1__X193 = mec ), ( (__1__X194 = mef -> memof__3fct ),
# 1309 "/home/claude/cfront-3/src/find.cpp"
( ((__1__X193 == __1__X194 )?1 :((__1__X193 && __1__X194 )?(((int )same_class__8classdefFP8classdefi ( __1__X193 , __1__X194 , 0 ) )):0 ))) ) ) )))
# 1310 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1310 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V166 ;
# 1310 "/home/claude/cfront-3/src/find.cpp"

# 1310 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V167 ;

# 1310 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V168 ;

# 1310 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cannot access%n: %sM", (const struct ea *)( (__2__X195 = (const void
# 1310 "/home/claude/cfront-3/src/find.cpp"
*)mec ), ( ((& __0__V166 )-> __O1__2ea.p = __2__X195 ), (& __0__V166 )) ) , (const struct ea *)( ((&
# 1310 "/home/claude/cfront-3/src/find.cpp"
__0__V167 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V167 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V168 , (const
# 1310 "/home/claude/cfront-3/src/find.cpp"
void *)(__1n -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1310 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} else 
# 1312 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1312 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V169 ;

# 1312 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V170 ;

# 1312 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V171 ;

# 1312 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n cannot access%n: %sM", (const struct ea *)( (__2__X196 = (const void
# 1312 "/home/claude/cfront-3/src/find.cpp"
*)me ), ( ((& __0__V169 )-> __O1__2ea.p = __2__X196 ), (& __0__V169 )) ) , (const struct ea *)( ((&
# 1312 "/home/claude/cfront-3/src/find.cpp"
__0__V170 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V170 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V171 , (const
# 1312 "/home/claude/cfront-3/src/find.cpp"
void *)(__1n -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1312 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} mex = 0 ;
}
}

# 1317 "/home/claude/cfront-3/src/find.cpp"
if (__1n -> base__4node == 123 )return (struct expr *)0 ;
if (__1access_only )return (struct expr *)__1n ;

# 1320 "/home/claude/cfront-3/src/find.cpp"
{ Pname __4th ;
Pexpr __4r ;

# 1322 "/home/claude/cfront-3/src/find.cpp"
struct ref *__0__X197 ;

# 1322 "/home/claude/cfront-3/src/find.cpp"
struct expr *__2__X198 ;

# 1322 "/home/claude/cfront-3/src/find.cpp"
struct expr *__2__X199 ;

# 1320 "/home/claude/cfront-3/src/find.cpp"
__4th = cc -> c_this__11dcl_context ;
__4r = (struct expr *)( (__0__X197 = 0 ), ( (__2__X198 = (struct expr *)__4th ), ( (__2__X199 = (struct expr *)__1n ), (
# 1321 "/home/claude/cfront-3/src/find.cpp"
((__0__X197 || (__0__X197 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X197 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X197 ),
# 1321 "/home/claude/cfront-3/src/find.cpp"
((unsigned char )44 ), __2__X198 , (struct expr *)0 ) ), (__0__X197 -> __O4__4expr.mem = __2__X199 )) :0 ), __0__X197 ) ) )
# 1321 "/home/claude/cfront-3/src/find.cpp"
) ;
if (__4th )( (__4th -> n_used__4name ++ ), (((void )0 ))) ;
( (__1n -> n_used__4name ++ ), (((void )0 ))) ;
__4r -> __O1__4expr.tp = __4t ;
return __4r ;

# 1325 "/home/claude/cfront-3/src/find.cpp"
}
}

# 1328 "/home/claude/cfront-3/src/find.cpp"
if ((mex && (__1n -> n_scope__4name == 0 ))&& (__1n -> __O1__4expr.tp -> base__4node != 76 )){ 
# 1329 "/home/claude/cfront-3/src/find.cpp"
if (is_accessible__FP4nameP8classdefUc ( __1n , __0this , (unsigned
# 1329 "/home/claude/cfront-3/src/find.cpp"
char )0 ) == 0 )
# 1330 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1330 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X201 ;

# 1330 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X202 ;

# 1330 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X203 ;

# 1330 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X204 ;

# 1331 "/home/claude/cfront-3/src/find.cpp"
if (me == dummy_fct ){ 
# 1331 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X200 ;

# 1332 "/home/claude/cfront-3/src/find.cpp"
if (mec )
# 1333 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1333 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V172 ;

# 1333 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V173 ;

# 1333 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V174 ;

# 1333 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cannot access%n: %sM", (const struct ea *)( (__2__X200 = (const void
# 1333 "/home/claude/cfront-3/src/find.cpp"
*)mec ), ( ((& __0__V172 )-> __O1__2ea.p = __2__X200 ), (& __0__V172 )) ) , (const struct ea *)( ((&
# 1333 "/home/claude/cfront-3/src/find.cpp"
__0__V173 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V173 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V174 , (const
# 1333 "/home/claude/cfront-3/src/find.cpp"
void *)(__1n -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1333 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} else 
# 1335 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1335 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V175 ;

# 1335 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V176 ;

# 1335 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"G scope cannot access%n: %sM", (const struct ea *)( ((& __0__V175 )-> __O1__2ea.p =
# 1335 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1n )), (& __0__V175 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V176 , (const void *)(__1n ->
# 1335 "/home/claude/cfront-3/src/find.cpp"
n_protect__4name ?"protected":(((char *)"private")))) , (const struct ea *)ea0 ,
# 1335 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 ) ;
} }
else 
# 1336 "/home/claude/cfront-3/src/find.cpp"
if (mec && ((mef == 0 )|| (! ( (__1__X201 = mec ), ( (__1__X202 = mef -> memof__3fct ),
# 1336 "/home/claude/cfront-3/src/find.cpp"
( ((__1__X201 == __1__X202 )?1 :((__1__X201 && __1__X202 )?(((int )same_class__8classdefFP8classdefi ( __1__X201 , __1__X202 , 0 ) )):0 ))) ) ) )))
# 1337 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1337 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V177 ;
# 1337 "/home/claude/cfront-3/src/find.cpp"

# 1337 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V178 ;

# 1337 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V179 ;

# 1337 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cannot access%n: %sM", (const struct ea *)( (__2__X203 = (const void
# 1337 "/home/claude/cfront-3/src/find.cpp"
*)mec ), ( ((& __0__V177 )-> __O1__2ea.p = __2__X203 ), (& __0__V177 )) ) , (const struct ea *)( ((&
# 1337 "/home/claude/cfront-3/src/find.cpp"
__0__V178 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V178 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V179 , (const
# 1337 "/home/claude/cfront-3/src/find.cpp"
void *)(__1n -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1337 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} else 
# 1339 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1339 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V180 ;

# 1339 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V181 ;

# 1339 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V182 ;

# 1339 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n cannot access%n: %sM", (const struct ea *)( (__2__X204 = (const void
# 1339 "/home/claude/cfront-3/src/find.cpp"
*)me ), ( ((& __0__V180 )-> __O1__2ea.p = __2__X204 ), (& __0__V180 )) ) , (const struct ea *)( ((&
# 1339 "/home/claude/cfront-3/src/find.cpp"
__0__V181 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V181 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V182 , (const
# 1339 "/home/claude/cfront-3/src/find.cpp"
void *)(__1n -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1339 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} mex = 0 ;
}
}
( (__1n -> n_used__4name ++ ), (((void )0 ))) ;
return (struct expr *)__1n ;
}
}

# 1348 "/home/claude/cfront-3/src/find.cpp"
if (((((__1cl == 0 )|| ( (__1__X205 = __1cl ), ( (__1__X206 = __0this ), ( ((__1__X205 == __1__X206 )?1 :((__1__X205 && __1__X206 )?(((int )same_class__8classdefFP8classdefi (
# 1348 "/home/claude/cfront-3/src/find.cpp"
__1__X205 , __1__X206 , 0 ) )):0 ))) ) ) )&& (__0this -> csu__8classdef != 36 ))&& (__0this -> csu__8classdef != 167 ))&& (strcmp (
# 1348 "/home/claude/cfront-3/src/find.cpp"
__1s , (const char *)"__as") == 0 ))
# 1351 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1352 "/home/claude/cfront-3/src/find.cpp"
if ((__0this -> baselist__8classdef == 0 )||
# 1352 "/home/claude/cfront-3/src/find.cpp"
(__0this -> baselist__8classdef -> bclass__6basecl -> obj_size__8classdef != __0this -> obj_size__8classdef ))
# 1353 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1354 "/home/claude/cfront-3/src/find.cpp"
Pname __3cn ;

# 1355 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X207 ;

# 1354 "/home/claude/cfront-3/src/find.cpp"
__3cn = find_cn__6ktableFPCc ( __0this -> k_tbl__8classdef , __0this -> string__8classdef ) ;
if (__3cn == 0 ){ 
# 1355 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V183 ;

# 1355 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V184 ;

# 1355 "/home/claude/cfront-3/src/find.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"CN %s missing inCdef::find_name(%s)", (const struct ea *)( (__2__X207 =
# 1355 "/home/claude/cfront-3/src/find.cpp"
(const void *)__0this -> string__8classdef ), ( ((& __0__V183 )-> __O1__2ea.p = __2__X207 ), (& __0__V183 )) ) , (const
# 1355 "/home/claude/cfront-3/src/find.cpp"
struct ea *)( ((& __0__V184 )-> __O1__2ea.p = ((const void *)__1s )), (& __0__V184 )) , (const struct ea *)ea0 ,
# 1355 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 ) ;
} if (__3cn -> __O1__4expr.tp -> base__4node == 119 )__3cn = (((struct basetype *)(((struct basetype *)__3cn -> __O1__4expr.tp ))))-> b_name__8basetype ;
{ Pname __3x ;

# 1357 "/home/claude/cfront-3/src/find.cpp"
__3x = look__5tableFPCcUc ( gtbl , (const char *)"__as", (unsigned char )0 ) ;
# 1357 "/home/claude/cfront-3/src/find.cpp"

# 1358 "/home/claude/cfront-3/src/find.cpp"
if (__3x ){ 
# 1360 "/home/claude/cfront-3/src/find.cpp"
Pfct __4f ;

# 1360 "/home/claude/cfront-3/src/find.cpp"
__4f = (((struct fct *)(((struct fct *)__3x -> __O1__4expr.tp ))));
if (__4f -> base__4node == 108 ){ 
# 1362 "/home/claude/cfront-3/src/find.cpp"
Pptr __5r ;

# 1362 "/home/claude/cfront-3/src/find.cpp"
__5r = is_ref__4typeFv ( __4f -> argtype__3fct -> __O1__4expr.tp ) ;
if (__5r ){ 
# 1364 "/home/claude/cfront-3/src/find.cpp"
Pname __6cnn ;

# 1364 "/home/claude/cfront-3/src/find.cpp"
__6cnn = is_cl_obj__4typeFv ( __5r -> typ__5pvtyp ) ;
if (__6cnn && (__3cn == __6cnn ))return (struct expr *)0 ;
}
}
else 
# 1367 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1368 "/home/claude/cfront-3/src/find.cpp"
{ { Plist __5gl ;

# 1368 "/home/claude/cfront-3/src/find.cpp"
__5gl = (((struct gen *)(((struct gen *)__4f ))))-> fct_list__3gen ;

# 1368 "/home/claude/cfront-3/src/find.cpp"
for(;__5gl ;__5gl = __5gl -> l__9name_list ) { 
# 1369 "/home/claude/cfront-3/src/find.cpp"
Pptr __6r ;

# 1369 "/home/claude/cfront-3/src/find.cpp"
__6r = is_ref__4typeFv ( (((struct fct *)(((struct fct *)__5gl -> f__9name_list ))))-> argtype__3fct -> __O1__4expr.tp ) ;
if (__6r ){ 
# 1371 "/home/claude/cfront-3/src/find.cpp"
Pname __7cnn ;

# 1371 "/home/claude/cfront-3/src/find.cpp"
__7cnn = is_cl_obj__4typeFv ( __6r -> typ__5pvtyp ) ;
if (__7cnn && (__3cn == __7cnn ))return (struct expr *)0 ;
}
}

# 1374 "/home/claude/cfront-3/src/find.cpp"
}

# 1374 "/home/claude/cfront-3/src/find.cpp"
}
}
}
return (make_assignment__FP4name ( __3cn ) ?find_name__8classdefFPCcP8classdefiT3 ( __0this , __1s , __1cl , 0 , 0 ) :(((struct expr *)0 )));

# 1377 "/home/claude/cfront-3/src/find.cpp"
}
}
}

# 1381 "/home/claude/cfront-3/src/find.cpp"
return find_in_base__8classdefFPCcP8classdefiT3 ( __0this , __1s , __1cl , __1access_only , __1newflag ) ;
}

# 1384 "/home/claude/cfront-3/src/find.cpp"
static Pclass rootClass ;
static Pbcl pubVClass ;
struct PendingMessage;

# 1390 "/home/claude/cfront-3/src/find.cpp"
static struct PendingMessage *pM ;

# 1386 "/home/claude/cfront-3/src/find.cpp"
struct PendingMessage {	/* sizeof PendingMessage == 24 */
Pbcl bc__14PendingMessage ;
Pname mf__14PendingMessage ;
const char *nm__14PendingMessage ;
};

# 121 "/home/claude/cfront-3/src/cfront.h"
extern const char *name_oper__FPCc (const char *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 848 "/home/claude/cfront-3/src/cfront.h"

# 1392 "/home/claude/cfront-3/src/find.cpp"
Pexpr find_in_base__8classdefFPCcP8classdefiT3 (register struct classdef *__0this , const char *__1s , Pclass __1cl , int __1access_only , int __1newflag )
# 1393 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1395 "/home/claude/cfront-3/src/find.cpp"
int __1statflag ;
Pbcl __1e_bc ;

# 1396 "/home/claude/cfront-3/src/find.cpp"
Pbcl __1bc ;
Pexpr __1e ;

# 1394 "/home/claude/cfront-3/src/find.cpp"
static Pbcl __1bc_found_in = 0 ;
__1statflag = 0 ;
__1e_bc = 0 ;

# 1396 "/home/claude/cfront-3/src/find.cpp"
__1bc = 0 ;
__1e = 0 ;

# 1401 "/home/claude/cfront-3/src/find.cpp"
if (me == 0 )mef = 0 ;

# 1403 "/home/claude/cfront-3/src/find.cpp"
if (rootClass == 0 ){ 
# 1404 "/home/claude/cfront-3/src/find.cpp"
rootClass = __0this ;
__1bc_found_in = 0 ;
}

# 1408 "/home/claude/cfront-3/src/find.cpp"
{ { Pbcl __1b ;

# 1409 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X253 ;

# 1409 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X254 ;

# 1409 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X273 ;

# 1409 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X274 ;

# 1408 "/home/claude/cfront-3/src/find.cpp"
__1b = __0this -> baselist__8classdef ;

# 1408 "/home/claude/cfront-3/src/find.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 1409 "/home/claude/cfront-3/src/find.cpp"
Pclass __2ccl ;

# 1411 "/home/claude/cfront-3/src/find.cpp"
Pexpr __2ee ;

# 1412 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X251 ;

# 1412 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X252 ;

# 1409 "/home/claude/cfront-3/src/find.cpp"
__2ccl = (( (__1__X251 = __1cl ), ( (__1__X252 = __0this ), ( ((__1__X251 == __1__X252 )?1 :((__1__X251 && __1__X252 )?(((int )same_class__8classdefFP8classdefi ( __1__X251 , __1__X252 ,
# 1409 "/home/claude/cfront-3/src/find.cpp"
0 ) )):0 ))) ) ) ?(((struct classdef *)0 )):__1cl );

# 1411 "/home/claude/cfront-3/src/find.cpp"
__2ee = find_name__8classdefFPCcP8classdefiT3 ( __1b -> bclass__6basecl , __1s , __2ccl , __1access_only , __1newflag ) ;

# 1413 "/home/claude/cfront-3/src/find.cpp"
if (__2ee ){ 
# 1414 "/home/claude/cfront-3/src/find.cpp"
if (! __1access_only ){ 
# 1415 "/home/claude/cfront-3/src/find.cpp"
if ((__1b != __0this -> baselist__8classdef )|| (__1b -> base__4node == 77 ))
# 1416 "/home/claude/cfront-3/src/find.cpp"
dcl_print__8classdefFP4name ( __0this , (struct
# 1416 "/home/claude/cfront-3/src/find.cpp"
name *)0 ) ;
else { 
# 1418 "/home/claude/cfront-3/src/find.cpp"
Pexpr __5ex ;

# 1418 "/home/claude/cfront-3/src/find.cpp"
__5ex = __2ee ;
while (((__5ex -> base__4node == 177 )&& (__5ex -> __O2__4expr.i1 == 1 ))|| ((__5ex -> base__4node == 44 )&& (__5ex -> __O2__4expr.e1 == (((struct expr *)cc ->
# 1419 "/home/claude/cfront-3/src/find.cpp"
c_this__11dcl_context )))))
# 1420 "/home/claude/cfront-3/src/find.cpp"
__5ex = __5ex -> __O4__4expr.mem ;
switch (__5ex -> __O1__4expr.tp -> base__4node ){ 
# 1422 "/home/claude/cfront-3/src/find.cpp"
case 76 :
# 1423 "/home/claude/cfront-3/src/find.cpp"
break ;
case 108 :
# 1425 "/home/claude/cfront-3/src/find.cpp"
if ((((struct fct *)(((struct fct *)__5ex -> __O1__4expr.tp ))))-> f_virtual__3fct == 0 )break ;
default :
# 1427 "/home/claude/cfront-3/src/find.cpp"
dcl_print__8classdefFP4name ( __0this , (struct name *)0 ) ;
}
}
}

# 1432 "/home/claude/cfront-3/src/find.cpp"
if (__1e ){ 
# 1434 "/home/claude/cfront-3/src/find.cpp"
Pexpr __4ex ;
int __4evb ;

# 1434 "/home/claude/cfront-3/src/find.cpp"
__4ex = __1e ;
__4evb = 0 ;

# 1438 "/home/claude/cfront-3/src/find.cpp"
while ((__4ex -> base__4node == 177 )|| ((__4ex -> base__4node == 44 )&& (__4ex -> __O2__4expr.e1 == (((struct expr *)cc -> c_this__11dcl_context )))))
# 1439 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1440 "/home/claude/cfront-3/src/find.cpp"
if (__4ex ->
# 1440 "/home/claude/cfront-3/src/find.cpp"
base__4node == 177 )__4evb += (((int )__4ex -> __O2__4expr.i1 ));
__4ex = __4ex -> __O4__4expr.mem ;
}

# 1444 "/home/claude/cfront-3/src/find.cpp"
{ Pexpr __4eex ;
int __4eevb ;

# 1446 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X245 ;

# 1446 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X246 ;

# 1446 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X247 ;

# 1446 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X248 ;

# 1444 "/home/claude/cfront-3/src/find.cpp"
__4eex = __2ee ;
__4eevb = (__1b -> base__4node == 77 );

# 1447 "/home/claude/cfront-3/src/find.cpp"
while ((__4eex -> base__4node == 177 )|| ((__4eex -> base__4node == 44 )&& (__4eex -> __O2__4expr.e1 == (((struct expr *)cc -> c_this__11dcl_context )))))
# 1448 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1449 "/home/claude/cfront-3/src/find.cpp"
if (__4eex ->
# 1449 "/home/claude/cfront-3/src/find.cpp"
base__4node == 177 )__4eevb += (((int )__4eex -> __O2__4expr.i1 ));
__4eex = __4eex -> __O4__4expr.mem ;
}

# 1456 "/home/claude/cfront-3/src/find.cpp"
if (__4ex != __4eex ){ 
# 1459 "/home/claude/cfront-3/src/find.cpp"
Pclass __5ocl ;

# 1459 "/home/claude/cfront-3/src/find.cpp"
Pclass __5ncl ;
if (__4ex -> __O1__4expr.tp -> base__4node == 108 )
# 1461 "/home/claude/cfront-3/src/find.cpp"
__5ocl = (((struct fct *)(((struct fct *)__4ex -> __O1__4expr.tp ))))-> memof__3fct ;
else 
# 1463 "/home/claude/cfront-3/src/find.cpp"
if (__4ex -> __O1__4expr.tp -> base__4node == 76 )
# 1464 "/home/claude/cfront-3/src/find.cpp"
__5ocl = (((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__4ex -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list ->
# 1464 "/home/claude/cfront-3/src/find.cpp"
__O1__4expr.tp ))))-> memof__3fct ;
else __5ocl = (((struct classdef *)(((struct classdef *)__4ex -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))));

# 1468 "/home/claude/cfront-3/src/find.cpp"
if (__4eex -> __O1__4expr.tp -> base__4node == 108 )
# 1469 "/home/claude/cfront-3/src/find.cpp"
__5ncl = (((struct fct *)(((struct fct *)__4eex -> __O1__4expr.tp ))))-> memof__3fct ;
else 
# 1471 "/home/claude/cfront-3/src/find.cpp"
if (__4eex -> __O1__4expr.tp -> base__4node == 76 )
# 1472 "/home/claude/cfront-3/src/find.cpp"
__5ncl = (((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__4eex -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list ->
# 1472 "/home/claude/cfront-3/src/find.cpp"
__O1__4expr.tp ))))-> memof__3fct ;
else __5ncl = (((struct classdef *)(((struct classdef *)__4eex -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))));

# 1478 "/home/claude/cfront-3/src/find.cpp"
{ int __5eb ;
int __5eeb ;

# 1478 "/home/claude/cfront-3/src/find.cpp"
__5eb = (__5ocl ?(((int )has_base__8classdefFP8classdefiT2 ( __5ocl , __5ncl , 0 , 0 ) )):0 );
__5eeb = (__5ncl ?(((int )has_base__8classdefFP8classdefiT2 ( __5ncl , __5ocl , 0 , 0 ) )):0 );

# 1482 "/home/claude/cfront-3/src/find.cpp"
if (((__5eb == 0 )&& (__5eeb == 0 ))&& (! __1newflag )){ 
# 1484 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1484 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V208 ;

# 1484 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V209 ;

# 1484 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous%n and%n", (const struct ea *)( ((& __0__V208 )-> __O1__2ea.p =
# 1484 "/home/claude/cfront-3/src/find.cpp"
((const void *)__4ex )), (& __0__V208 )) , (const struct ea *)( ((& __0__V209 )-> __O1__2ea.p = ((const void
# 1484 "/home/claude/cfront-3/src/find.cpp"
*)__4eex )), (& __0__V209 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
} }
else if (__5eb ){ 
# 1487 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X243 ;

# 1487 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X244 ;

# 1488 "/home/claude/cfront-3/src/find.cpp"
if ((__4eevb < __4evb )&& (! __1newflag ))
# 1489 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1489 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V210 ;

# 1489 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V211 ;

# 1489 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous%n and%n (different sub-objects)", (const struct ea *)( ((& __0__V210 )-> __O1__2ea.p =
# 1489 "/home/claude/cfront-3/src/find.cpp"
((const void *)__4ex )), (& __0__V210 )) , (const struct ea *)( ((& __0__V211 )-> __O1__2ea.p = ((const void
# 1489 "/home/claude/cfront-3/src/find.cpp"
*)__4eex )), (& __0__V211 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 1491 "/home/claude/cfront-3/src/find.cpp"
if ((((__4eevb && ( (__1__X243 = rootClass ), ( (__1__X244 = __0this ), ( ((__1__X243 == __1__X244 )?1 :((__1__X243 && __1__X244 )?(((int
# 1491 "/home/claude/cfront-3/src/find.cpp"
)same_class__8classdefFP8classdefi ( __1__X243 , __1__X244 , 0 ) )):0 ))) ) ) )&& (__1b -> ppp__6basecl == 25 ))&& pM )&& (strcmp ( __1b ->
# 1491 "/home/claude/cfront-3/src/find.cpp"
bclass__6basecl -> string__8classdef , pM -> bc__14PendingMessage -> bclass__6basecl -> string__8classdef ) == 0 ))
# 1493 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1494 "/home/claude/cfront-3/src/find.cpp"
__dl__FPv ( (void *)pM ) ;
pM = 0 ;
pubVClass = __1bc ;
}
}
else { 
# 1500 "/home/claude/cfront-3/src/find.cpp"
__1e = __2ee ;
__1bc = __1b ;
if ((__4evb < __4eevb )&& (! __1newflag )){ 
# 1502 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V212 ;

# 1502 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V213 ;

# 1502 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous%n and%n (different sub-objects)", (const struct ea *)( ((& __0__V212 )-> __O1__2ea.p =
# 1502 "/home/claude/cfront-3/src/find.cpp"
((const void *)__4ex )), (& __0__V212 )) , (const struct ea *)( ((& __0__V213 )-> __O1__2ea.p = ((const void
# 1502 "/home/claude/cfront-3/src/find.cpp"
*)__4eex )), (& __0__V213 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
if (((__4evb == 0 )&& (__4eevb == 0 ))&& (! __1newflag )){ 
# 1505 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1505 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V214 ;

# 1505 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V215 ;

# 1505 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous%n and%n (different sub-objects)", (const struct ea *)( ((& __0__V214 )-> __O1__2ea.p =
# 1505 "/home/claude/cfront-3/src/find.cpp"
((const void *)__4ex )), (& __0__V214 )) , (const struct ea *)( ((& __0__V215 )-> __O1__2ea.p = ((const void
# 1505 "/home/claude/cfront-3/src/find.cpp"
*)__4eex )), (& __0__V215 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1506 "/home/claude/cfront-3/src/find.cpp"
}
}
else if ((__4ex -> base__4node == 85 )&& ((((((struct name *)(((struct name *)__4ex ))))-> n_evaluated__4name || ((((struct name *)(((struct name *)__4ex ))))-> n_sto__4name ==
# 1508 "/home/claude/cfront-3/src/find.cpp"
14 ))|| ((((struct name *)(((struct name *)__4ex ))))-> n_stclass__4name == 31 ))|| ((__4ex -> __O1__4expr.tp && (__4ex -> __O1__4expr.tp -> base__4node == 108 ))&& (((struct fct *)(((struct
# 1508 "/home/claude/cfront-3/src/find.cpp"
fct *)__4ex -> __O1__4expr.tp ))))-> f_static__3fct )))
# 1519 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1520 "/home/claude/cfront-3/src/find.cpp"
}
else if ((__4evb == 0 )&& (__4eevb == 0 )){ 
# 1524 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1524 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V216 ;

# 1524 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V217 ;

# 1524 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous%n and%n (no virtualB)", (const struct ea *)( ((& __0__V216 )-> __O1__2ea.p =
# 1524 "/home/claude/cfront-3/src/find.cpp"
((const void *)__4ex )), (& __0__V216 )) , (const struct ea *)( ((& __0__V217 )-> __O1__2ea.p = ((const void
# 1524 "/home/claude/cfront-3/src/find.cpp"
*)__4eex )), (& __0__V217 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
} }
else if ((__4evb && (__4eevb == 0 ))|| (__4eevb && (__4evb == 0 ))){ 
# 1529 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1529 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V218 ;

# 1529 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V219 ;

# 1529 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous%n and%n (one not in virtualB)", (const struct ea *)( ((& __0__V218 )-> __O1__2ea.p =
# 1529 "/home/claude/cfront-3/src/find.cpp"
((const void *)__4ex )), (& __0__V218 )) , (const struct ea *)( ((& __0__V219 )-> __O1__2ea.p = ((const void
# 1529 "/home/claude/cfront-3/src/find.cpp"
*)__4eex )), (& __0__V219 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
} }
else if (((__1e_bc && __1bc_found_in )&& ( (__1__X245 = __1e_bc -> bclass__6basecl ), ( (__1__X246 = __1bc_found_in -> bclass__6basecl ), (
# 1532 "/home/claude/cfront-3/src/find.cpp"
((__1__X245 == __1__X246 )?1 :((__1__X245 && __1__X246 )?(((int )same_class__8classdefFP8classdefi ( __1__X245 , __1__X246 , 0 ) )):0 ))) ) ) )&& (__1e_bc -> base__4node != __1bc_found_in ->
# 1532 "/home/claude/cfront-3/src/find.cpp"
base__4node ))
# 1534 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1535 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1535 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V220 ;

# 1535 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V221 ;

# 1535 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V222 ;

# 1535 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V223 ;

# 1535 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous%n: (%t both %s and %s)", (const struct ea *)( ((& __0__V220 )-> __O1__2ea.p =
# 1535 "/home/claude/cfront-3/src/find.cpp"
((const void *)__4ex )), (& __0__V220 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V221 , (const void *)__1e_bc ->
# 1535 "/home/claude/cfront-3/src/find.cpp"
bclass__6basecl ) , (const struct ea *)__ct__2eaFPCv ( & __0__V222 , (const void *)((__1e_bc -> base__4node == 77 )?"virtual":(((char
# 1535 "/home/claude/cfront-3/src/find.cpp"
*)"nonvirtual")))) , (const struct ea *)__ct__2eaFPCv ( & __0__V223 , (const void *)((__1bc_found_in ->
# 1535 "/home/claude/cfront-3/src/find.cpp"
base__4node == 77 )?"virtual":(((char *)"nonvirtual")))) ) ;
__1e_bc = 0 ;
} }

# 1539 "/home/claude/cfront-3/src/find.cpp"
if ((((__4eevb && ( (__1__X247 = rootClass ), ( (__1__X248 = __0this ), ( ((__1__X247 == __1__X248 )?1 :((__1__X247 && __1__X248 )?(((int )same_class__8classdefFP8classdefi (
# 1539 "/home/claude/cfront-3/src/find.cpp"
__1__X247 , __1__X248 , 0 ) )):0 ))) ) ) )&& (__1b -> ppp__6basecl == 25 ))&& pM )&& (! strcmp ( __1b ->
# 1539 "/home/claude/cfront-3/src/find.cpp"
bclass__6basecl -> string__8classdef , pM -> bc__14PendingMessage -> bclass__6basecl -> string__8classdef ) ))
# 1543 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1544 "/home/claude/cfront-3/src/find.cpp"
__dl__FPv ( (void *)pM ) ;
pM = 0 ;
pubVClass = __1bc ;
}

# 1547 "/home/claude/cfront-3/src/find.cpp"
}
}
else { 
# 1549 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X249 ;

# 1549 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X250 ;

# 1550 "/home/claude/cfront-3/src/find.cpp"
__1e = __2ee ;
__1bc = __1b ;
if (__1bc_found_in == 0 )__1bc_found_in = __1b ;
if (( (__1__X249 = rootClass ), ( (__1__X250 = __0this ), ( ((__1__X249 == __1__X250 )?1 :((__1__X249 && __1__X250 )?(((int )same_class__8classdefFP8classdefi ( __1__X249 , __1__X250 ,
# 1553 "/home/claude/cfront-3/src/find.cpp"
0 ) )):0 ))) ) ) ){ 
# 1554 "/home/claude/cfront-3/src/find.cpp"
__1e_bc = __1bc_found_in ;
__1bc_found_in = 0 ;
}
}

# 1559 "/home/claude/cfront-3/src/find.cpp"
if ((((((__2ee -> __O1__4expr.tp -> base__4node == 108 )&& (((struct fct *)(((struct fct *)__2ee -> __O1__4expr.tp ))))-> f_static__3fct )&& __1cl )&& (((struct fct *)(((struct fct *)__2ee ->
# 1559 "/home/claude/cfront-3/src/find.cpp"
__O1__4expr.tp ))))-> memof__3fct )&& (strcmp ( __1cl -> string__8classdef , (((struct fct *)(((struct fct *)__2ee -> __O1__4expr.tp ))))-> memof__3fct -> string__8classdef ) == 0 ))|| ((__2ee ->
# 1559 "/home/claude/cfront-3/src/find.cpp"
base__4node == 85 )&& ((((struct name *)(((struct name *)__2ee ))))-> n_stclass__4name == 31 )))
# 1560 "/home/claude/cfront-3/src/find.cpp"
__1statflag = 1 ;
}
}

# 1564 "/home/claude/cfront-3/src/find.cpp"
if (( (__1__X253 = rootClass ), ( (__1__X254 = __0this ), ( ((__1__X253 == __1__X254 )?1 :((__1__X253 && __1__X254 )?(((int )same_class__8classdefFP8classdefi ( __1__X253 , __1__X254 ,
# 1564 "/home/claude/cfront-3/src/find.cpp"
0 ) )):0 ))) ) ) ){ 
# 1565 "/home/claude/cfront-3/src/find.cpp"
if (pM ){ 
# 1567 "/home/claude/cfront-3/src/find.cpp"
Pbcl __3b ;
const char *__3str ;

# 1569 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X255 ;

# 1569 "/home/claude/cfront-3/src/find.cpp"
unsigned long __2__X256 ;

# 1567 "/home/claude/cfront-3/src/find.cpp"
__3b = pM -> bc__14PendingMessage ;
__3str = __3b -> bclass__6basecl -> string__8classdef ;
{ 
# 1569 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V224 ;

# 1569 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V225 ;

# 1569 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V226 ;

# 1569 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V227 ;

# 1569 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n cannot access %s: %s is a%kBC", (const struct ea *)( (__2__X255 = (const void
# 1569 "/home/claude/cfront-3/src/find.cpp"
*)pM -> mf__14PendingMessage ), ( ((& __0__V224 )-> __O1__2ea.p = __2__X255 ), (& __0__V224 )) ) , (const struct ea *)__ct__2eaFPCv (
# 1569 "/home/claude/cfront-3/src/find.cpp"
& __0__V225 , (const void *)name_oper__FPCc ( pM -> nm__14PendingMessage ) ) , (const struct ea *)( ((& __0__V226 )->
# 1569 "/home/claude/cfront-3/src/find.cpp"
__O1__2ea.p = ((const void *)__3str )), (& __0__V226 )) , (const struct ea *)( (__2__X256 = __3b -> ppp__6basecl ), (
# 1569 "/home/claude/cfront-3/src/find.cpp"
(( ((& __0__V227 )-> __O1__2ea.i = __2__X256 ), 0 ) ), (& __0__V227 )) ) ) ;
__dl__FPv ( (void *)pM ) ;

# 1570 "/home/claude/cfront-3/src/find.cpp"
pM = 0 ;
} }

# 1573 "/home/claude/cfront-3/src/find.cpp"
if (__1e == 0 ){ 
# 1574 "/home/claude/cfront-3/src/find.cpp"
rootClass = 0 ;
pubVClass = 0 ;
}
}

# 1579 "/home/claude/cfront-3/src/find.cpp"
if (__1e == 0 )return (struct expr *)0 ;

# 1581 "/home/claude/cfront-3/src/find.cpp"
if (mex ){ 
# 1582 "/home/claude/cfront-3/src/find.cpp"
if ((__1bc -> ppp__6basecl == 174 )|| (__1bc -> ppp__6basecl == 79 )){ 
# 1582 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X257 ;

# 1582 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X258 ;

# 1582 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X259 ;

# 1582 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X260 ;

# 1583 "/home/claude/cfront-3/src/find.cpp"
if (((( (__1__X257 = __0this ), ( (__1__X258 = mec ), ( ((__1__X257 == __1__X258 )?1 :((__1__X257 && __1__X258 )?(((int )same_class__8classdefFP8classdefi ( __1__X257 , __1__X258 ,
# 1583 "/home/claude/cfront-3/src/find.cpp"
0 ) )):0 ))) ) ) || (mec && has_friend__8classdefFP8classdef ( __0this , mec ) ))|| (mef && has_friend__8classdefFP3fct ( __0this , mef )
# 1583 "/home/claude/cfront-3/src/find.cpp"
))|| (((mec && (__1bc -> ppp__6basecl == 79 ))&& is_base__8classdefFPCcPUci ( mec , __0this -> string__8classdef , (TOK *)0 , 0 ) )&& (ppbase != 174 )))
# 1588 "/home/claude/cfront-3/src/find.cpp"
;
# 1588 "/home/claude/cfront-3/src/find.cpp"
else 
# 1590 "/home/claude/cfront-3/src/find.cpp"
if ((__1bc -> base__4node == 77 )&& (! ( (__1__X259 = rootClass ), ( (__1__X260 = __0this ), ( ((__1__X259 ==
# 1590 "/home/claude/cfront-3/src/find.cpp"
__1__X260 )?1 :((__1__X259 && __1__X260 )?(((int )same_class__8classdefFP8classdefi ( __1__X259 , __1__X260 , 0 ) )):0 ))) ) ) ))
# 1591 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1593 "/home/claude/cfront-3/src/find.cpp"
if ((pubVClass == 0 )|| strcmp (
# 1593 "/home/claude/cfront-3/src/find.cpp"
pubVClass -> bclass__6basecl -> string__8classdef , __1bc -> bclass__6basecl -> string__8classdef ) )
# 1594 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1594 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X261 ;

# 1594 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X262 ;

# 1595 "/home/claude/cfront-3/src/find.cpp"
pM = (((struct PendingMessage *)(((char *)__nw__FUl ( (size_t)(24* (sizeof (char )))) ))));
pM -> bc__14PendingMessage = __1bc ;

# 1596 "/home/claude/cfront-3/src/find.cpp"
pM -> nm__14PendingMessage = __1s ;
if (me == dummy_fct )
# 1598 "/home/claude/cfront-3/src/find.cpp"
pM -> mf__14PendingMessage = (mec ?mec -> k_tbl__8classdef -> k_name__6ktable :me );
else if (mec && ((mef == 0 )|| (! ( (__1__X261 = mec ), ( (__1__X262 = mef -> memof__3fct ), (
# 1599 "/home/claude/cfront-3/src/find.cpp"
((__1__X261 == __1__X262 )?1 :((__1__X261 && __1__X262 )?(((int )same_class__8classdefFP8classdefi ( __1__X261 , __1__X262 , 0 ) )):0 ))) ) ) )))
# 1600 "/home/claude/cfront-3/src/find.cpp"
pM -> mf__14PendingMessage = mec -> k_tbl__8classdef ->
# 1600 "/home/claude/cfront-3/src/find.cpp"
k_name__6ktable ;
else 
# 1602 "/home/claude/cfront-3/src/find.cpp"
pM -> mf__14PendingMessage = me ;
}
}
else { 
# 1606 "/home/claude/cfront-3/src/find.cpp"
if (me == dummy_fct ){ 
# 1606 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X263 ;

# 1606 "/home/claude/cfront-3/src/find.cpp"
unsigned long __2__X264 ;

# 1606 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X265 ;

# 1606 "/home/claude/cfront-3/src/find.cpp"
unsigned long __2__X266 ;

# 1607 "/home/claude/cfront-3/src/find.cpp"
if (mec )
# 1608 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1608 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V228 ;

# 1608 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V229 ;

# 1608 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V230 ;

# 1608 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V231 ;

# 1608 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cannot access %s: %s is a %k BC", (const struct ea *)( (__2__X263 = (const void
# 1608 "/home/claude/cfront-3/src/find.cpp"
*)mec ), ( ((& __0__V228 )-> __O1__2ea.p = __2__X263 ), (& __0__V228 )) ) , (const struct ea *)__ct__2eaFPCv ( &
# 1608 "/home/claude/cfront-3/src/find.cpp"
__0__V229 , (const void *)name_oper__FPCc ( __1s ) ) , (const struct ea *)__ct__2eaFPCv ( & __0__V230 , (const void
# 1608 "/home/claude/cfront-3/src/find.cpp"
*)__1bc -> bclass__6basecl -> string__8classdef ) , (const struct ea *)( (__2__X264 = __1bc -> ppp__6basecl ), ( (( ((& __0__V231 )->
# 1608 "/home/claude/cfront-3/src/find.cpp"
__O1__2ea.i = __2__X264 ), 0 ) ), (& __0__V231 )) ) ) ;
} else 
# 1610 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1610 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V232 ;

# 1610 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V233 ;

# 1610 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V234 ;

# 1610 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"G scope cannot access %s: %s is a %k BC", (const struct ea *)( (__2__X265 = (const void
# 1610 "/home/claude/cfront-3/src/find.cpp"
*)name_oper__FPCc ( __1s ) ), ( ((& __0__V232 )-> __O1__2ea.p = __2__X265 ), (& __0__V232 )) ) , (const struct
# 1610 "/home/claude/cfront-3/src/find.cpp"
ea *)__ct__2eaFPCv ( & __0__V233 , (const void *)__1bc -> bclass__6basecl -> string__8classdef ) , (const struct ea *)( (__2__X266 = __1bc ->
# 1610 "/home/claude/cfront-3/src/find.cpp"
ppp__6basecl ), ( (( ((& __0__V234 )-> __O1__2ea.i = __2__X266 ), 0 ) ), (& __0__V234 )) ) , (const
# 1610 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} }
else 
# 1611 "/home/claude/cfront-3/src/find.cpp"
if (((__1statflag == 0 )|| (strcmp ( __1s , (const char *)"__nw")
# 1611 "/home/claude/cfront-3/src/find.cpp"
== 0 ))|| (strcmp ( __1s , (const char *)"__dl") == 0 )){ 
# 1611 "/home/claude/cfront-3/src/find.cpp"
struct
# 1611 "/home/claude/cfront-3/src/find.cpp"
classdef *__1__X267 ;

# 1611 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X268 ;

# 1611 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X269 ;

# 1611 "/home/claude/cfront-3/src/find.cpp"
unsigned long __2__X270 ;

# 1611 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X271 ;

# 1611 "/home/claude/cfront-3/src/find.cpp"
unsigned long __2__X272 ;

# 1612 "/home/claude/cfront-3/src/find.cpp"
if (mec && ((mef == 0 )|| (! ( (__1__X267 = mec ), ( (__1__X268 = mef -> memof__3fct ), ( ((__1__X267 ==
# 1612 "/home/claude/cfront-3/src/find.cpp"
__1__X268 )?1 :((__1__X267 && __1__X268 )?(((int )same_class__8classdefFP8classdefi ( __1__X267 , __1__X268 , 0 ) )):0 ))) ) ) )))
# 1613 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1613 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V235 ;

# 1613 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V236 ;

# 1613 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V237 ;

# 1613 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V238 ;

# 1613 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cannot access %s: %s is a %k BC", (const struct ea *)( (__2__X269 = (const void
# 1613 "/home/claude/cfront-3/src/find.cpp"
*)mec ), ( ((& __0__V235 )-> __O1__2ea.p = __2__X269 ), (& __0__V235 )) ) , (const struct ea *)__ct__2eaFPCv ( &
# 1613 "/home/claude/cfront-3/src/find.cpp"
__0__V236 , (const void *)name_oper__FPCc ( __1s ) ) , (const struct ea *)__ct__2eaFPCv ( & __0__V237 , (const void
# 1613 "/home/claude/cfront-3/src/find.cpp"
*)__1bc -> bclass__6basecl -> string__8classdef ) , (const struct ea *)( (__2__X270 = __1bc -> ppp__6basecl ), ( (( ((& __0__V238 )->
# 1613 "/home/claude/cfront-3/src/find.cpp"
__O1__2ea.i = __2__X270 ), 0 ) ), (& __0__V238 )) ) ) ;
} else 
# 1615 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1615 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V239 ;

# 1615 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V240 ;

# 1615 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V241 ;

# 1615 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V242 ;

# 1615 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n cannot access %s: %s is a %k BC", (const struct ea *)( (__2__X271 = (const void
# 1615 "/home/claude/cfront-3/src/find.cpp"
*)me ), ( ((& __0__V239 )-> __O1__2ea.p = __2__X271 ), (& __0__V239 )) ) , (const struct ea *)__ct__2eaFPCv ( &
# 1615 "/home/claude/cfront-3/src/find.cpp"
__0__V240 , (const void *)name_oper__FPCc ( __1s ) ) , (const struct ea *)__ct__2eaFPCv ( & __0__V241 , (const void
# 1615 "/home/claude/cfront-3/src/find.cpp"
*)__1bc -> bclass__6basecl -> string__8classdef ) , (const struct ea *)( (__2__X272 = __1bc -> ppp__6basecl ), ( (( ((& __0__V242 )->
# 1615 "/home/claude/cfront-3/src/find.cpp"
__O1__2ea.i = __2__X272 ), 0 ) ), (& __0__V242 )) ) ) ;
} }
mex = 0 ;
}
}
else { 
# 1621 "/home/claude/cfront-3/src/find.cpp"
if (__1bc -> base__4node == 77 ){ 
# 1622 "/home/claude/cfront-3/src/find.cpp"
if (pM && (strcmp ( __1bc -> bclass__6basecl -> string__8classdef , pM -> bc__14PendingMessage ->
# 1622 "/home/claude/cfront-3/src/find.cpp"
bclass__6basecl -> string__8classdef ) == 0 ))
# 1623 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1624 "/home/claude/cfront-3/src/find.cpp"
__dl__FPv ( (void *)pM ) ;
pM = 0 ;
pubVClass = __1bc ;
}
else pubVClass = __1bc ;
}
}
}

# 1633 "/home/claude/cfront-3/src/find.cpp"
if (( (__1__X273 = rootClass ), ( (__1__X274 = __0this ), ( ((__1__X273 == __1__X274 )?1 :((__1__X273 && __1__X274 )?(((int )same_class__8classdefFP8classdefi ( __1__X273 , __1__X274 ,
# 1633 "/home/claude/cfront-3/src/find.cpp"
0 ) )):0 ))) ) ) ){ 
# 1634 "/home/claude/cfront-3/src/find.cpp"
rootClass = 0 ;
pubVClass = 0 ;
}

# 1638 "/home/claude/cfront-3/src/find.cpp"
if ((__1e -> base__4node == 85 )&& ((((struct name *)(((struct name *)__1e ))))-> n_stclass__4name == 31 ))
# 1639 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1640 "/home/claude/cfront-3/src/find.cpp"
( ((((struct name *)(((struct name *)__1e ))))-> n_used__4name ++
# 1640 "/home/claude/cfront-3/src/find.cpp"
), (((void )0 ))) ;
return __1e ;
}
if (__1e -> base__4node != 85 )
# 1644 "/home/claude/cfront-3/src/find.cpp"
if (__1bc -> base__4node == 77 ){ 
# 1644 "/home/claude/cfront-3/src/find.cpp"
register struct mdot *__0__X275 ;

# 1644 "/home/claude/cfront-3/src/find.cpp"
const char *__2__X276 ;

# 1644 "/home/claude/cfront-3/src/find.cpp"
struct expr *__2__X277 ;

# 1645 "/home/claude/cfront-3/src/find.cpp"
__1e -> __O4__4expr.mem = (struct expr *)( (__0__X275 = 0 ), ( (__2__X276 = __1bc -> bclass__6basecl -> string__8classdef ), ( (__2__X277 = __1e ->
# 1645 "/home/claude/cfront-3/src/find.cpp"
__O4__4expr.mem ), ( ((__0__X275 || (__0__X275 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot))) ))?( (__0__X275 = (struct mdot *)__ct__4exprFUcP4exprT2 (
# 1645 "/home/claude/cfront-3/src/find.cpp"
((struct expr *)__0__X275 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ), ( (__0__X275 -> __O3__4expr.string2 = __2__X276 ),
# 1645 "/home/claude/cfront-3/src/find.cpp"
(__0__X275 -> __O4__4expr.mem = __2__X277 )) ) :0 ), __0__X275 ) ) ) ) ;
__1e -> __O4__4expr.mem -> __O2__4expr.i1 = 1 ;
__1e -> __O4__4expr.mem -> __O1__4expr.tp = __1e -> __O4__4expr.mem -> __O4__4expr.mem -> __O1__4expr.tp ;
}
else if (__1bc != __0this -> baselist__8classdef ){ 
# 1650 "/home/claude/cfront-3/src/find.cpp"
if (__1e -> __O2__4expr.e1 == (((struct expr *)cc -> c_this__11dcl_context ))){ 
# 1650 "/home/claude/cfront-3/src/find.cpp"
register struct mdot *__0__X278 ;
# 1650 "/home/claude/cfront-3/src/find.cpp"

# 1650 "/home/claude/cfront-3/src/find.cpp"
const char *__2__X279 ;

# 1650 "/home/claude/cfront-3/src/find.cpp"
struct expr *__2__X280 ;

# 1651 "/home/claude/cfront-3/src/find.cpp"
__1e -> __O4__4expr.mem = (struct expr *)( (__0__X278 = 0 ), ( (__2__X279 = __1bc -> bclass__6basecl -> string__8classdef ), ( (__2__X280 = __1e ->
# 1651 "/home/claude/cfront-3/src/find.cpp"
__O4__4expr.mem ), ( ((__0__X278 || (__0__X278 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot))) ))?( (__0__X278 = (struct mdot *)__ct__4exprFUcP4exprT2 (
# 1651 "/home/claude/cfront-3/src/find.cpp"
((struct expr *)__0__X278 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ), ( (__0__X278 -> __O3__4expr.string2 = __2__X279 ),
# 1651 "/home/claude/cfront-3/src/find.cpp"
(__0__X278 -> __O4__4expr.mem = __2__X280 )) ) :0 ), __0__X278 ) ) ) ) ;
__1e -> __O4__4expr.mem -> __O1__4expr.tp = __1e -> __O4__4expr.mem -> __O4__4expr.mem -> __O1__4expr.tp ;
}
else { 
# 1655 "/home/claude/cfront-3/src/find.cpp"
Pexpr __3ee ;

# 1656 "/home/claude/cfront-3/src/find.cpp"
register struct mdot *__0__X281 ;

# 1656 "/home/claude/cfront-3/src/find.cpp"
const char *__2__X282 ;

# 1656 "/home/claude/cfront-3/src/find.cpp"
struct expr *__2__X283 ;

# 1655 "/home/claude/cfront-3/src/find.cpp"
__3ee = __1e ;
while (__3ee -> __O2__4expr.e1 -> base__4node == 44 )__3ee = __3ee -> __O2__4expr.e1 ;
__3ee -> __O4__4expr.mem = (struct expr *)( (__0__X281 = 0 ), ( (__2__X282 = __1bc -> bclass__6basecl -> string__8classdef ), ( (__2__X283 = __3ee ->
# 1657 "/home/claude/cfront-3/src/find.cpp"
__O4__4expr.mem ), ( ((__0__X281 || (__0__X281 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot))) ))?( (__0__X281 = (struct mdot *)__ct__4exprFUcP4exprT2 (
# 1657 "/home/claude/cfront-3/src/find.cpp"
((struct expr *)__0__X281 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ), ( (__0__X281 -> __O3__4expr.string2 = __2__X282 ),
# 1657 "/home/claude/cfront-3/src/find.cpp"
(__0__X281 -> __O4__4expr.mem = __2__X283 )) ) :0 ), __0__X281 ) ) ) ) ;
__3ee -> __O4__4expr.mem -> __O1__4expr.tp = __3ee -> __O4__4expr.mem -> __O4__4expr.mem -> __O1__4expr.tp ;
}
}

# 1662 "/home/claude/cfront-3/src/find.cpp"
return __1e ;

# 1662 "/home/claude/cfront-3/src/find.cpp"
}

# 1662 "/home/claude/cfront-3/src/find.cpp"
}
}

# 1665 "/home/claude/cfront-3/src/find.cpp"
int has_virt__FP8classdef (Pclass __1cl );

# 1665 "/home/claude/cfront-3/src/find.cpp"
int has_virt__FP8classdef (Pclass __1cl )
# 1666 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1667 "/home/claude/cfront-3/src/find.cpp"
if (__1cl -> virt_count__8classdef )return 1 ;
{ { Pbcl __1b ;

# 1668 "/home/claude/cfront-3/src/find.cpp"
__1b = __1cl -> baselist__8classdef ;

# 1668 "/home/claude/cfront-3/src/find.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) 
# 1669 "/home/claude/cfront-3/src/find.cpp"
if (__1b -> bclass__6basecl -> virt_count__8classdef || has_virt__FP8classdef ( __1b -> bclass__6basecl ) )return 1 ;
return 0 ;

# 1670 "/home/claude/cfront-3/src/find.cpp"
}

# 1670 "/home/claude/cfront-3/src/find.cpp"
}
}

# 1673 "/home/claude/cfront-3/src/find.cpp"
Pname find_vptr__FP8classdef (Pclass __1cl )
# 1678 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1680 "/home/claude/cfront-3/src/find.cpp"
while (__1cl ){ 
# 1681 "/home/claude/cfront-3/src/find.cpp"
Pname __2vp ;

# 1681 "/home/claude/cfront-3/src/find.cpp"
__2vp = look__5tableFPCcUc ( __1cl -> memtbl__8classdef , (const char *)"__vptr", (unsigned char )0 )
# 1681 "/home/claude/cfront-3/src/find.cpp"
;
if (__2vp )return __2vp ;
{ Pbcl __2b ;

# 1683 "/home/claude/cfront-3/src/find.cpp"
__2b = __1cl -> baselist__8classdef ;
__1cl = 0 ;
for(;__2b ;__2b = __2b -> next__6basecl ) 
# 1686 "/home/claude/cfront-3/src/find.cpp"
if (__2b -> base__4node == 85 ){ 
# 1687 "/home/claude/cfront-3/src/find.cpp"
__1cl = __2b -> bclass__6basecl ;
break ;
}

# 1689 "/home/claude/cfront-3/src/find.cpp"
}
}

# 1692 "/home/claude/cfront-3/src/find.cpp"
return (struct name *)0 ;
}

# 940 "/home/claude/cfront-3/src/cfront.h"
Pname dcl__4nameFP5tableUc (struct name *__0this , Ptable , TOK );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 1695 "/home/claude/cfront-3/src/find.cpp"
void make_dummy__Fv (void )
# 1697 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1698 "/home/claude/cfront-3/src/find.cpp"
Pname __1x ;

# 1698 "/home/claude/cfront-3/src/find.cpp"
__1x = __ct__4nameFPCc ( (struct name *)0 , (const char *)"..") ;
__1x -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , Pvoid_type , (struct name *)0 , (unsigned char )1 ) ;
dummy_fct = dcl__4nameFP5tableUc ( __1x , gtbl , (unsigned char )14 ) ;

# 1702 "/home/claude/cfront-3/src/find.cpp"
( (__1x ?(((void )(__1x ?(((void )( ( ((((struct expr *)__1x ))?(((void )((((struct expr *)__1x ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 1702 "/home/claude/cfront-3/src/find.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1x , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
}

# 1705 "/home/claude/cfront-3/src/find.cpp"
void check_visibility__FP4nameT1P8classdefP5tableT1 (Pname __1n , Pname __1q , Pclass __1cl , Ptable __1tbl , Pname __1fn )
# 1710 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1712 "/home/claude/cfront-3/src/find.cpp"
if (__1fn == 0 ){ 
# 1713 "/home/claude/cfront-3/src/find.cpp"
if (dummy_fct == 0 )make_dummy__Fv ( ) ;
# 1713 "/home/claude/cfront-3/src/find.cpp"

# 1714 "/home/claude/cfront-3/src/find.cpp"
__1fn = dummy_fct ;
}
{ Pname __1nn ;
const char *__1s ;

# 1716 "/home/claude/cfront-3/src/find.cpp"
__1nn = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1s = __1n -> n_gen_fct_name__4name ;
__1nn -> __O2__4expr.string = (__1s ?__1s :__1n -> __O2__4expr.string );
__1nn -> __O2__4name.n_qualifier = __1q ;
{ Pname __1nx ;

# 1720 "/home/claude/cfront-3/src/find.cpp"
__1nx = (((struct name *)(((struct name *)find_name__FP4nameP8classdefP5tableiT1 ( __1nn , __1cl , __1tbl , 44 , __1fn ) ))));
if (__1nx -> __O1__4expr.tp -> base__4node != 76 )return ;

# 1728 "/home/claude/cfront-3/src/find.cpp"
{ { Plist __1gl ;

# 1728 "/home/claude/cfront-3/src/find.cpp"
__1gl = (((struct gen *)(((struct gen *)__1nx -> __O1__4expr.tp ))))-> fct_list__3gen ;

# 1728 "/home/claude/cfront-3/src/find.cpp"
for(;__1gl ;__1gl = __1gl -> l__9name_list ) { 
# 1729 "/home/claude/cfront-3/src/find.cpp"
Pname __2nn ;

# 1729 "/home/claude/cfront-3/src/find.cpp"
__2nn = __1gl -> f__9name_list ;
if (__1n == __2nn ){ 
# 1731 "/home/claude/cfront-3/src/find.cpp"
if (__2nn -> n_scope__4name )return ;

# 1733 "/home/claude/cfront-3/src/find.cpp"
{ Pname __3ome ;
Pfct __3omef ;
Pclass __3omec ;
Pclass __3otcl ;

# 1738 "/home/claude/cfront-3/src/find.cpp"
Pclass __3ncl ;
Pname __3fncn ;

# 1733 "/home/claude/cfront-3/src/find.cpp"
__3ome = me ;
__3omef = mef ;
__3omec = mec ;
__3otcl = tcl ;

# 1738 "/home/claude/cfront-3/src/find.cpp"
__3ncl = (((struct classdef *)(((struct classdef *)__2nn -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))));
__3fncn = __1fn -> __O4__4expr.n_table -> t_name__5table ;

# 1741 "/home/claude/cfront-3/src/find.cpp"
me = __1fn ;
mec = (__3fncn ?(((struct classdef *)(((struct classdef *)__3fncn -> __O1__4expr.tp )))):(((struct classdef *)0 )));
if (cc -> cot__11dcl_context && (cc -> cot__11dcl_context -> lex_level__4type > __1fn -> lex_level__4name ))
# 1744 "/home/claude/cfront-3/src/find.cpp"
mec = cc -> cot__11dcl_context ;
{ Pfct __3f ;

# 1745 "/home/claude/cfront-3/src/find.cpp"
__3f = (mef = (((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp )))));
tcl = __1cl ;

# 1748 "/home/claude/cfront-3/src/find.cpp"
{ int __3ok ;

# 1749 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X298 ;

# 1749 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X299 ;

# 1749 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X300 ;

# 1748 "/home/claude/cfront-3/src/find.cpp"
__3ok = is_accessible__FP4nameP8classdefUc ( __1n , __3ncl , (unsigned char )1 ) ;

# 1751 "/home/claude/cfront-3/src/find.cpp"
mef = __3omef ;

# 1751 "/home/claude/cfront-3/src/find.cpp"
mec = __3omec ;

# 1751 "/home/claude/cfront-3/src/find.cpp"
tcl = __3otcl ;

# 1751 "/home/claude/cfront-3/src/find.cpp"
me = __3ome ;

# 1753 "/home/claude/cfront-3/src/find.cpp"
if (__3ok )return ;

# 1755 "/home/claude/cfront-3/src/find.cpp"
if ((((Cdcl && (Cdcl -> base__4node == 85 ))&& (Cdcl -> n_stclass__4name == 31 ))&& Cdcl -> __O3__4expr.n_initializer )&& Cdcl -> __O2__4name.n_qualifier )
# 1759 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1760 "/home/claude/cfront-3/src/find.cpp"
Pbase __4bn ;
Pclass __4ccl ;

# 1762 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X295 ;

# 1762 "/home/claude/cfront-3/src/find.cpp"
struct classdef *__1__X296 ;

# 1760 "/home/claude/cfront-3/src/find.cpp"
__4bn = (((struct basetype *)(((struct basetype *)Cdcl -> __O2__4name.n_qualifier -> __O1__4expr.tp ))));
__4ccl = (((struct classdef *)(((struct classdef *)__4bn -> b_name__8basetype -> __O1__4expr.tp ))));

# 1763 "/home/claude/cfront-3/src/find.cpp"
if ((( (__1__X295 = __4ccl ), ( (__1__X296 = __1cl ), ( ((__1__X295 == __1__X296 )?1 :((__1__X295 && __1__X296 )?(((int )same_class__8classdefFP8classdefi ( __1__X295 , __1__X296 ,
# 1763 "/home/claude/cfront-3/src/find.cpp"
0 ) )):0 ))) ) ) || has_friend__8classdefFP3fct ( __4ccl , __3f ) )|| (__1n -> n_protect__4name && has_base__8classdefFP8classdefiT2 ( __4ccl , __3ncl ,
# 1763 "/home/claude/cfront-3/src/find.cpp"
0 , 0 ) ))
# 1765 "/home/claude/cfront-3/src/find.cpp"
return ;
}

# 1768 "/home/claude/cfront-3/src/find.cpp"
if (__1fn == dummy_fct ){ 
# 1768 "/home/claude/cfront-3/src/find.cpp"
const void *__2__X297 ;

# 1769 "/home/claude/cfront-3/src/find.cpp"
if (mec )
# 1770 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1770 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V284 ;

# 1770 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V285 ;

# 1770 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V286 ;

# 1770 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cannot access%a: %sM", (const struct ea *)( (__2__X297 = (const void
# 1770 "/home/claude/cfront-3/src/find.cpp"
*)mec ), ( ((& __0__V284 )-> __O1__2ea.p = __2__X297 ), (& __0__V284 )) ) , (const struct ea *)( ((&
# 1770 "/home/claude/cfront-3/src/find.cpp"
__0__V285 )-> __O1__2ea.p = ((const void *)__2nn )), (& __0__V285 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V286 , (const
# 1770 "/home/claude/cfront-3/src/find.cpp"
void *)(__2nn -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1770 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} else 
# 1772 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1772 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V287 ;

# 1772 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V288 ;

# 1772 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"G scope cannot access%n: %sM", (const struct ea *)( ((& __0__V287 )-> __O1__2ea.p =
# 1772 "/home/claude/cfront-3/src/find.cpp"
((const void *)__2nn )), (& __0__V287 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V288 , (const void *)(__2nn ->
# 1772 "/home/claude/cfront-3/src/find.cpp"
n_protect__4name ?"protected":(((char *)"private")))) , (const struct ea *)ea0 ,
# 1772 "/home/claude/cfront-3/src/find.cpp"
(const struct ea *)ea0 ) ;
} }
else 
# 1773 "/home/claude/cfront-3/src/find.cpp"
if (mec && ((mef == 0 )|| (! ( (__1__X298 = mec ), ( (__1__X299 = mef -> memof__3fct ),
# 1773 "/home/claude/cfront-3/src/find.cpp"
( ((__1__X298 == __1__X299 )?1 :((__1__X298 && __1__X299 )?(((int )same_class__8classdefFP8classdefi ( __1__X298 , __1__X299 , 0 ) )):0 ))) ) ) )))
# 1774 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1774 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V289 ;
# 1774 "/home/claude/cfront-3/src/find.cpp"

# 1774 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V290 ;

# 1774 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V291 ;

# 1774 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cannot access%a: %sM", (const struct ea *)( (__2__X300 = (const void
# 1774 "/home/claude/cfront-3/src/find.cpp"
*)mec ), ( ((& __0__V289 )-> __O1__2ea.p = __2__X300 ), (& __0__V289 )) ) , (const struct ea *)( ((&
# 1774 "/home/claude/cfront-3/src/find.cpp"
__0__V290 )-> __O1__2ea.p = ((const void *)__2nn )), (& __0__V290 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V291 , (const
# 1774 "/home/claude/cfront-3/src/find.cpp"
void *)(__2nn -> n_protect__4name ?"protected":(((char *)"private")))) , (const
# 1774 "/home/claude/cfront-3/src/find.cpp"
struct ea *)ea0 ) ;
} else 
# 1776 "/home/claude/cfront-3/src/find.cpp"
{ 
# 1776 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V292 ;

# 1776 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V293 ;

# 1776 "/home/claude/cfront-3/src/find.cpp"
struct ea __0__V294 ;

# 1776 "/home/claude/cfront-3/src/find.cpp"
error__FPCcRC2eaN32 ( (const char *)"%a cannot access%a: %sM", (const struct ea *)( ((& __0__V292 )-> __O1__2ea.p =
# 1776 "/home/claude/cfront-3/src/find.cpp"
((const void *)__1fn )), (& __0__V292 )) , (const struct ea *)( ((& __0__V293 )-> __O1__2ea.p = ((const void
# 1776 "/home/claude/cfront-3/src/find.cpp"
*)__2nn )), (& __0__V293 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V294 , (const void *)(__2nn -> n_protect__4name ?"protected":(((char
# 1776 "/home/claude/cfront-3/src/find.cpp"
*)"private")))) , (const struct ea *)ea0 ) ;
} return ;

# 1777 "/home/claude/cfront-3/src/find.cpp"
}

# 1777 "/home/claude/cfront-3/src/find.cpp"
}

# 1777 "/home/claude/cfront-3/src/find.cpp"
}
}
}
error__FiPCc ( (int )'i' , (const char *)"visibility check failed") ;

# 1780 "/home/claude/cfront-3/src/find.cpp"
}

# 1780 "/home/claude/cfront-3/src/find.cpp"
}

# 1780 "/home/claude/cfront-3/src/find.cpp"
}

# 1780 "/home/claude/cfront-3/src/find.cpp"
}
}
void dummy__14basic_templateFv (struct basic_template *__0this );
struct __mptr __vtbl__13data_template[] = {0,0,0,
0,0,(__vptp)dummy__14basic_templateFv ,
0,0,(__vptp)has_friend__13data_templateFP4name ,
0,0,0};
struct __mptr __vtbl__5templ[] = {0,0,0,
0,0,(__vptp)dummy__14basic_templateFv ,
0,0,(__vptp)has_friend__5templFP4name ,
0,0,0};
struct __mptr __vtbl__17function_template[] = {0,0,0,
0,0,(__vptp)dummy__14basic_templateFv ,
0,0,(__vptp)has_friend__17function_templateFP4name ,
0,0,0};

# 493 "/home/claude/cfront-3/src/cfront.h"
static int same_class__FP8classdefT1i (
# 493 "/home/claude/cfront-3/src/cfront.h"
Pclass __1c1 , 
# 493 "/home/claude/cfront-3/src/cfront.h"
Pclass __1c2 , 
# 493 "/home/claude/cfront-3/src/cfront.h"
int __1dummy ){ 
# 498 "/home/claude/cfront-3/src/cfront.h"
return ((__1c1 == __1c2 )?1 :((__1c1 && __1c2 )?(((int )same_class__8classdefFP8classdefi ( __1c1 , __1c2 , __1dummy )
# 498 "/home/claude/cfront-3/src/cfront.h"
)):0 ));
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

# 1781 "/home/claude/cfront-3/src/find.cpp"

/* the end */
