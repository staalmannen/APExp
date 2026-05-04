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

# 29 "/home/claude/cfront-3/src/norm.cpp"
Pktab Gtbl = 0 ;
Pktab Ctbl = 0 ;

# 32 "/home/claude/cfront-3/src/norm.cpp"
Pname sta_name = 0 ;
static Ptype generic_tpdef = 0 ;

# 323 "/home/claude/cfront-3/src/cfront.h"

# 579 "/home/claude/cfront-3/src/cfront.h"
struct basetype *__ct__8basetypeFUcP4name (struct basetype *__0this , TOK , Pname );

# 254 "/home/claude/cfront-3/src/cfront.h"
struct ktable *__ct__6ktableFiP6ktableP4name (struct ktable *__0this , int , Pktab , Pname );

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

# 35 "/home/claude/cfront-3/src/norm.cpp"
void syn_init__Fv (void )
# 36 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 36 "/home/claude/cfront-3/src/norm.cpp"
struct type *__0__X26 ;

# 36 "/home/claude/cfront-3/src/norm.cpp"
struct node *__0__X1 ;

# 37 "/home/claude/cfront-3/src/norm.cpp"
generic_tpdef = ( (__0__X26 = 0 ), ( ((__0__X26 || (__0__X26 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type))) ))?(
# 37 "/home/claude/cfront-3/src/norm.cpp"
( ( ( ( ( ( ( (__0__X26 = (struct type *)( (__0__X1 = (((struct node *)__0__X26 ))), (
# 37 "/home/claude/cfront-3/src/norm.cpp"
((__0__X1 || (__0__X1 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 ->
# 37 "/home/claude/cfront-3/src/norm.cpp"
permanent__4node = 0 )) , (__0__X1 -> baseclass__4node = 0 )) :0 ), __0__X1 ) ) ), (__0__X26 -> defined__4type = 0 )) ,
# 37 "/home/claude/cfront-3/src/norm.cpp"
(__0__X26 -> lex_level__4type = 0 )) , (__0__X26 -> templ_base__4type = 0)) , (__0__X26 -> in_class__4type = 0 )) , (__0__X26 -> nested_sig__4type =
# 37 "/home/claude/cfront-3/src/norm.cpp"
0 )) , (__0__X26 -> local_sig__4type = 0 )) , (__0__X26 -> b_const__4type = 0 )) , (__0__X26 -> ansi_const__4type = 0 )) :0 ),
# 37 "/home/claude/cfront-3/src/norm.cpp"
__0__X26 ) ) ;
generic_tpdef -> base__4node = 190 ;
generic_tpdef -> permanent__4node = 1 ;
any_type = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )141 , (struct name *)0 ) ;
any_type -> permanent__4node = 1 ;

# 41 "/home/claude/cfront-3/src/norm.cpp"
any_type -> defined__4type = 01 ;
dummy = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )144 , (struct expr *)0 , (struct expr *)0 ) ;
dummy -> permanent__4node = 1 ;
dummy -> __O1__4expr.tp = (struct type *)any_type ;
zero = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )86 , (struct expr *)0 , (struct expr *)0 ) ;
zero -> permanent__4node = 1 ;
sta_name = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
sta_name -> permanent__4node = 1 ;

# 50 "/home/claude/cfront-3/src/norm.cpp"
Gtbl = __ct__6ktableFiP6ktableP4name ( (struct ktable *)0 , 257 , (struct ktable *)0 , (struct name *)0 ) ;
Ctbl = Gtbl ;
}

# 54 "/home/claude/cfront-3/src/norm.cpp"
int stcount = 0 ;

# 80 "/home/claude/incl-linux32/stdio.h"
extern int sprintf (char *, const char *,...);

# 56 "/home/claude/cfront-3/src/norm.cpp"
char *make_name__FUc (TOK __1c )
# 57 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 58 "/home/claude/cfront-3/src/norm.cpp"
char *__1s ;

# 58 "/home/claude/cfront-3/src/norm.cpp"
__1s = (((char *)__nw__FUl ( (size_t)(8* (sizeof (char )))) ));

# 60 "/home/claude/cfront-3/src/norm.cpp"
if (10000 <= (++ stcount ))error__FiPCc ( (int )'i' , (const char *)"too many generatedNs") ;
# 60 "/home/claude/cfront-3/src/norm.cpp"

# 62 "/home/claude/cfront-3/src/norm.cpp"
sprintf ( __1s , (const char *)"__%c%d", __1c , stcount ) ;
return __1s ;
}

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 66 "/home/claude/cfront-3/src/norm.cpp"
Pbase type_adj__8basetypeFUc (register struct basetype *__0this , TOK __1t )
# 67 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 68 "/home/claude/cfront-3/src/norm.cpp"
;
if (__0this -> b_xname__8basetype ){ 
# 69 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X39 ;

# 70 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> base__4node )
# 71 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 71 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V27 ;

# 71 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V28 ;

# 71 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%n%k", (const struct ea *)( (__2__X39 = (const void
# 71 "/home/claude/cfront-3/src/norm.cpp"
*)__0this -> b_xname__8basetype ), ( ((& __0__V27 )-> __O1__2ea.p = __2__X39 ), (& __0__V27 )) ) , (const struct ea *)(
# 71 "/home/claude/cfront-3/src/norm.cpp"
(( ((& __0__V28 )-> __O1__2ea.i = ((unsigned long )__1t )), 0 ) ), (& __0__V28 )) , (const struct
# 71 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 73 "/home/claude/cfront-3/src/norm.cpp"
__0this -> base__4node = 97 ;
__0this -> b_name__8basetype = __0this -> b_xname__8basetype ;
}
__0this -> b_xname__8basetype = 0 ;
}

# 79 "/home/claude/cfront-3/src/norm.cpp"
switch (__1t ){ 
# 79 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X40 ;

# 79 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X41 ;

# 80 "/home/claude/cfront-3/src/norm.cpp"
case 35 :
# 81 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_typedef__8basetype )
# 82 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCc ( (int )'w' , (const char *)"two typedefs") ;
# 82 "/home/claude/cfront-3/src/norm.cpp"
else 
# 83 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_inline__8basetype ){ 
# 84 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 84 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V29 ;

# 84 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V30 ;

# 84 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k and%k", (const struct ea *)( (( ((& __0__V29 )->
# 84 "/home/claude/cfront-3/src/norm.cpp"
__O1__2ea.i = ((unsigned long )75 )), 0 ) ), (& __0__V29 )) , (const struct ea *)( (( ((&
# 84 "/home/claude/cfront-3/src/norm.cpp"
__0__V30 )-> __O1__2ea.i = ((unsigned long )35 )), 0 ) ), (& __0__V30 )) , (const struct ea *)ea0 , (const
# 84 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 ) ;
__0this -> b_typedef__8basetype = 0 ;
} }
else 
# 88 "/home/claude/cfront-3/src/norm.cpp"
__0this -> b_typedef__8basetype = 1 ;
break ;
case 75 :
# 91 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_inline__8basetype )
# 92 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCc ( (int )'w' , (const char *)"two inlines") ;
# 92 "/home/claude/cfront-3/src/norm.cpp"
else 
# 93 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_typedef__8basetype ){ 
# 94 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 94 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V31 ;

# 94 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V32 ;

# 94 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k and%k", (const struct ea *)( (( ((& __0__V31 )->
# 94 "/home/claude/cfront-3/src/norm.cpp"
__O1__2ea.i = ((unsigned long )35 )), 0 ) ), (& __0__V31 )) , (const struct ea *)( (( ((&
# 94 "/home/claude/cfront-3/src/norm.cpp"
__0__V32 )-> __O1__2ea.i = ((unsigned long )75 )), 0 ) ), (& __0__V32 )) , (const struct ea *)ea0 , (const
# 94 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 ) ;
__0this -> b_inline__8basetype = 0 ;
} }
else 
# 98 "/home/claude/cfront-3/src/norm.cpp"
__0this -> b_inline__8basetype = 1 ;
break ;
case 77 :__0this -> b_virtual__8basetype = 1 ;

# 100 "/home/claude/cfront-3/src/norm.cpp"
break ;
case 26 :if (__0this -> b_const__4type )error__FiPCc ( (int )'w' , (const char *)"two const declarators") ;
# 101 "/home/claude/cfront-3/src/norm.cpp"

# 102 "/home/claude/cfront-3/src/norm.cpp"
__0this -> b_const__4type = 1 ;

# 102 "/home/claude/cfront-3/src/norm.cpp"
break ;
case 37 :__0this -> b_unsigned__8basetype = 1 ;

# 103 "/home/claude/cfront-3/src/norm.cpp"
break ;
case 29 :__0this -> b_short__8basetype = 1 ;

# 104 "/home/claude/cfront-3/src/norm.cpp"
break ;
case 22 :if (__0this -> base__4node == 11 ){ 
# 106 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_long__8basetype ){ 
# 107 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCc ( (int )'w' , (const char *)"redundant long declarators")
# 107 "/home/claude/cfront-3/src/norm.cpp"
;
__0this -> b_long__8basetype = 0 ;
}
__0this -> base__4node = 181 ;
}
else 
# 111 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_long__8basetype > 1 ){ 
# 112 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCc ( (int )'w' , (const char *)"too many long declarators")
# 112 "/home/claude/cfront-3/src/norm.cpp"
;
}
else 
# 113 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_long__8basetype ){ 
# 114 "/home/claude/cfront-3/src/norm.cpp"
__0this -> b_long__8basetype = 2 ;
}
else __0this -> b_long__8basetype = 1 ;
break ;
case 18 :
# 119 "/home/claude/cfront-3/src/norm.cpp"
case 76 :
# 120 "/home/claude/cfront-3/src/norm.cpp"
case 14 :
# 121 "/home/claude/cfront-3/src/norm.cpp"
case 31 :
# 122 "/home/claude/cfront-3/src/norm.cpp"
case 2 :
# 123 "/home/claude/cfront-3/src/norm.cpp"
case 27 :
# 124 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_sto__8basetype )
# 125 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 125 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V33 ;

# 125 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V34 ;

# 125 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k%k", (const struct ea *)( (__2__X40 = __0this -> b_sto__8basetype ),
# 125 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V33 )-> __O1__2ea.i = __2__X40 ), 0 ) ), (& __0__V33 )) ) , (const struct
# 125 "/home/claude/cfront-3/src/norm.cpp"
ea *)( (( ((& __0__V34 )-> __O1__2ea.i = ((unsigned long )__1t )), 0 ) ), (& __0__V34 )) , (const
# 125 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 127 "/home/claude/cfront-3/src/norm.cpp"
__0this -> b_sto__8basetype = __1t ;
break ;
case 11 :
# 130 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_long__8basetype > 1 )
# 131 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCc ( (int )'w' , (const char *)"excessive long declarators")
# 131 "/home/claude/cfront-3/src/norm.cpp"
;
if (__0this -> b_long__8basetype ){ 
# 133 "/home/claude/cfront-3/src/norm.cpp"
__1t = 181 ;
__0this -> b_long__8basetype = 0 ;
}

# 137 "/home/claude/cfront-3/src/norm.cpp"
case 38 :
# 138 "/home/claude/cfront-3/src/norm.cpp"
case 5 :
# 139 "/home/claude/cfront-3/src/norm.cpp"
case 21 :
# 140 "/home/claude/cfront-3/src/norm.cpp"
case 15 :
# 141 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> base__4node )
# 142 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 142 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V35 ;

# 142 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V36 ;

# 142 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k%k", (const struct ea *)( (__2__X41 = __0this -> base__4node ),
# 142 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V35 )-> __O1__2ea.i = __2__X41 ), 0 ) ), (& __0__V35 )) ) , (const struct
# 142 "/home/claude/cfront-3/src/norm.cpp"
ea *)( (( ((& __0__V36 )-> __O1__2ea.i = ((unsigned long )__1t )), 0 ) ), (& __0__V36 )) , (const
# 142 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 144 "/home/claude/cfront-3/src/norm.cpp"
__0this -> base__4node = __1t ;
break ;
case 171 :
# 148 "/home/claude/cfront-3/src/norm.cpp"
break ;
case 170 :
# 150 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 150 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V37 ;

# 150 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"\"%k\" not implemented (ignored)", (const struct ea *)( ((
# 150 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V37 )-> __O1__2ea.i = ((unsigned long )__1t )), 0 ) ), (& __0__V37 )) , (const struct ea *)ea0 ,
# 150 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
default :
# 153 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 153 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V38 ;

# 153 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"BT::type_adj(%k)", (const struct ea *)( ((
# 153 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V38 )-> __O1__2ea.i = ((unsigned long )__1t )), 0 ) ), (& __0__V38 )) , (const struct ea *)ea0 ,
# 153 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} } }
return __0this ;
}

# 75 "/home/claude/cfront-3/src/cfront.h"

# 158 "/home/claude/cfront-3/src/norm.cpp"
Pbase name_adj__8basetypeFP4name (register struct basetype *__0this , Pname __1n )
# 159 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 160 "/home/claude/cfront-3/src/norm.cpp"
;
if (__0this -> b_xname__8basetype ){ 
# 161 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X44 ;

# 162 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> base__4node )
# 163 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 163 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V42 ;

# 163 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V43 ;

# 163 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%n%n", (const struct ea *)( (__2__X44 = (const void
# 163 "/home/claude/cfront-3/src/norm.cpp"
*)__0this -> b_xname__8basetype ), ( ((& __0__V42 )-> __O1__2ea.p = __2__X44 ), (& __0__V42 )) ) , (const struct ea *)(
# 163 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V43 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V43 )) , (const struct ea *)ea0 , (const struct
# 163 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} else { 
# 165 "/home/claude/cfront-3/src/norm.cpp"
__0this -> base__4node = 97 ;
__0this -> b_name__8basetype = __0this -> b_xname__8basetype ;
}
__0this -> b_xname__8basetype = 0 ;
}

# 171 "/home/claude/cfront-3/src/norm.cpp"
if (((__0this -> base__4node == 0 )&& (__1n -> base__4node == 123 ))&& ((__1n -> __O1__4expr.tp -> base__4node != 119 )|| (Ctbl -> k_id__6ktable == 136 )))
# 174 "/home/claude/cfront-3/src/norm.cpp"
{
# 174 "/home/claude/cfront-3/src/norm.cpp"

# 175 "/home/claude/cfront-3/src/norm.cpp"
__0this -> base__4node = 97 ;
__0this -> b_name__8basetype = __1n ;
}
else 
# 179 "/home/claude/cfront-3/src/norm.cpp"
__0this -> b_xname__8basetype = __1n ;

# 181 "/home/claude/cfront-3/src/norm.cpp"
return __0this ;
}

# 184 "/home/claude/cfront-3/src/norm.cpp"
static TOK type_set__FP8basetype (Pbase __1b )
# 185 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 186 "/home/claude/cfront-3/src/norm.cpp"
TOK __1t ;

# 186 "/home/claude/cfront-3/src/norm.cpp"
__1t = 0 ;

# 188 "/home/claude/cfront-3/src/norm.cpp"
if (__1b -> b_long__8basetype > 1 )__1t = 122 ;
else if (__1b -> b_long__8basetype )__1t = 22 ;
else if (__1b -> b_short__8basetype )__1t = 29 ;
else if (__1b -> b_unsigned__8basetype )__1t = 37 ;
else if (__1b -> b_inline__8basetype )__1t = 75 ;
else if (__1b -> b_virtual__8basetype )__1t = 77 ;
else if (__1b -> b_sto__8basetype == 76 )__1t = 76 ;
return __1t ;
}

# 198 "/home/claude/cfront-3/src/norm.cpp"
int declTag = 1 ;

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFUl (struct ea *__0this , size_t __2ii );

# 200 "/home/claude/cfront-3/src/norm.cpp"
Pbase base_adj__8basetypeFP8basetype (register struct basetype *__0this , Pbase __1b )
# 201 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 202 "/home/claude/cfront-3/src/norm.cpp"
;
{ Pname __1bn ;

# 212 "/home/claude/cfront-3/src/norm.cpp"
TOK __1t ;

# 203 "/home/claude/cfront-3/src/norm.cpp"
__1bn = __1b -> b_name__8basetype ;

# 205 "/home/claude/cfront-3/src/norm.cpp"
switch (__0this -> base__4node ){ 
# 205 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X61 ;

# 205 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X62 ;

# 206 "/home/claude/cfront-3/src/norm.cpp"
case 119 :
# 207 "/home/claude/cfront-3/src/norm.cpp"
case 121 :
# 208 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 208 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V45 ;

# 208 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V46 ;

# 208 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"NX after%k%n", (const struct ea *)( (__2__X61 = __0this -> base__4node ),
# 208 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V45 )-> __O1__2ea.i = __2__X61 ), 0 ) ), (& __0__V45 )) ) , (const struct
# 208 "/home/claude/cfront-3/src/norm.cpp"
ea *)( (__2__X62 = (const void *)__0this -> b_name__8basetype ), ( ((& __0__V46 )-> __O1__2ea.p = __2__X62 ), (& __0__V46 )) )
# 208 "/home/claude/cfront-3/src/norm.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return __0this ;
} }

# 212 "/home/claude/cfront-3/src/norm.cpp"
;
if (__0this -> base__4node ){ 
# 213 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X63 ;

# 213 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X64 ;

# 213 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X65 ;

# 214 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_name__8basetype )
# 215 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 215 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V47 ;

# 215 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V48 ;

# 215 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V49 ;

# 215 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V50 ;

# 215 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k%n%k%n", (const struct ea *)( (__2__X63 = __0this -> base__4node ),
# 215 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V47 )-> __O1__2ea.i = __2__X63 ), 0 ) ), (& __0__V47 )) ) , (const struct
# 215 "/home/claude/cfront-3/src/norm.cpp"
ea *)( (__2__X64 = (const void *)__0this -> b_name__8basetype ), ( ((& __0__V48 )-> __O1__2ea.p = __2__X64 ), (& __0__V48 )) )
# 215 "/home/claude/cfront-3/src/norm.cpp"
, (const struct ea *)__ct__2eaFUl ( & __0__V49 , (unsigned long )__1b -> base__4node ) , (const struct ea *)(
# 215 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V50 )-> __O1__2ea.p = ((const void *)__1bn )), (& __0__V50 )) ) ;
} else 
# 217 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 217 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V51 ;

# 217 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V52 ;

# 217 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V53 ;

# 217 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k%k%n", (const struct ea *)( (__2__X65 = __0this -> base__4node ),
# 217 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V51 )-> __O1__2ea.i = __2__X65 ), 0 ) ), (& __0__V51 )) ) , (const struct
# 217 "/home/claude/cfront-3/src/norm.cpp"
ea *)__ct__2eaFUl ( & __0__V52 , (unsigned long )__1b -> base__4node ) , (const struct ea *)( ((& __0__V53 )-> __O1__2ea.p =
# 217 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1bn )), (& __0__V53 )) , (const struct ea *)ea0 ) ;
} }
else if (__1t = type_set__FP8basetype ( __0this ) ){ 
# 219 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X66 ;

# 220 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_name__8basetype )
# 221 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 221 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V54 ;

# 221 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V55 ;

# 221 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V56 ;

# 221 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V57 ;

# 221 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k%n%k%n", (const struct ea *)( (( ((& __0__V54 )->
# 221 "/home/claude/cfront-3/src/norm.cpp"
__O1__2ea.i = ((unsigned long )__1t )), 0 ) ), (& __0__V54 )) , (const struct ea *)( (__2__X66 = (const
# 221 "/home/claude/cfront-3/src/norm.cpp"
void *)__0this -> b_name__8basetype ), ( ((& __0__V55 )-> __O1__2ea.p = __2__X66 ), (& __0__V55 )) ) , (const struct
# 221 "/home/claude/cfront-3/src/norm.cpp"
ea *)__ct__2eaFUl ( & __0__V56 , (unsigned long )__1b -> base__4node ) , (const struct ea *)( ((& __0__V57 )-> __O1__2ea.p =
# 221 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1bn )), (& __0__V57 )) ) ;
} else { 
# 223 "/home/claude/cfront-3/src/norm.cpp"
if ((declTag ++ )&& (! ((__1t == 75 )&& (__1b -> base__4node == 121 )))){ 
# 223 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V58 ;
# 223 "/home/claude/cfront-3/src/norm.cpp"

# 223 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V59 ;

# 223 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V60 ;

# 223 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k%k%n", (const struct ea *)( (( ((& __0__V58 )->
# 223 "/home/claude/cfront-3/src/norm.cpp"
__O1__2ea.i = ((unsigned long )__1t )), 0 ) ), (& __0__V58 )) , (const struct ea *)__ct__2eaFUl ( & __0__V59 ,
# 223 "/home/claude/cfront-3/src/norm.cpp"
(unsigned long )__1b -> base__4node ) , (const struct ea *)( ((& __0__V60 )-> __O1__2ea.p = ((const void *)__1bn )),
# 223 "/home/claude/cfront-3/src/norm.cpp"
(& __0__V60 )) , (const struct ea *)ea0 ) ;
} __0this -> base__4node = __1b -> base__4node ;

# 224 "/home/claude/cfront-3/src/norm.cpp"
__0this -> b_name__8basetype = __1bn ;

# 226 "/home/claude/cfront-3/src/norm.cpp"
}
}
else { 
# 229 "/home/claude/cfront-3/src/norm.cpp"
__0this -> base__4node = __1b -> base__4node ;
__0this -> b_name__8basetype = __1bn ;
__0this -> b_table__8basetype = __1b -> b_table__8basetype ;
}

# 234 "/home/claude/cfront-3/src/norm.cpp"
return __0this ;

# 234 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 75 "/home/claude/cfront-3/src/cfront.h"

# 938 "/home/claude/cfront-3/src/cfront.h"
void hide__4nameFv (struct name *__0this );

# 113 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_name__FPCcP6ktableUc (const char *, Pktab , TOK );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 237 "/home/claude/cfront-3/src/norm.cpp"
Pbase check__8basetypeFP4name (register struct basetype *__0this , Pname __1n )
# 243 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 244 "/home/claude/cfront-3/src/norm.cpp"
__0this -> b_inline__8basetype = 0 ;
__0this -> b_virtual__8basetype = 0 ;

# 248 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_xname__8basetype && (__1n -> __O1__4expr.tp || __1n -> __O2__4expr.string )){ 
# 248 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X84 ;

# 248 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X85 ;

# 249 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> base__4node )
# 250 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 250 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V67 ;

# 250 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V68 ;

# 250 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k%n", (const struct ea *)( (__2__X84 = __0this -> base__4node ),
# 250 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V67 )-> __O1__2ea.i = __2__X84 ), 0 ) ), (& __0__V67 )) ) , (const struct
# 250 "/home/claude/cfront-3/src/norm.cpp"
ea *)( (__2__X85 = (const void *)__0this -> b_xname__8basetype ), ( ((& __0__V68 )-> __O1__2ea.p = __2__X85 ), (& __0__V68 )) )
# 250 "/home/claude/cfront-3/src/norm.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 252 "/home/claude/cfront-3/src/norm.cpp"
__0this -> base__4node = 97 ;
__0this -> b_name__8basetype = __0this -> b_xname__8basetype ;
}
__0this -> b_xname__8basetype = 0 ;
}

# 258 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_xname__8basetype ){ 
# 258 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X86 ;

# 259 "/home/claude/cfront-3/src/norm.cpp"
if (__1n -> __O2__4expr.string )
# 260 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 260 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V69 ;

# 260 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V70 ;

# 260 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoNs inD:%n%n", (const struct ea *)( (__2__X86 = (const void
# 260 "/home/claude/cfront-3/src/norm.cpp"
*)__0this -> b_xname__8basetype ), ( ((& __0__V69 )-> __O1__2ea.p = __2__X86 ), (& __0__V69 )) ) , (const struct ea *)(
# 260 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V70 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V70 )) , (const struct ea *)ea0 , (const struct
# 260 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} else { 
# 262 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O2__4expr.string = __0this -> b_xname__8basetype -> __O2__4expr.string ;
hide__4nameFv ( __0this -> b_xname__8basetype ) ;
}
__0this -> b_xname__8basetype = 0 ;
}

# 268 "/home/claude/cfront-3/src/norm.cpp"
if ((((((ccl == 0 )&& __1n )&& (__1n -> n_oper__4name == 123 ))&& (! in_typedef ))&& (__1n -> __O2__4name.n_qualifier == 0 ))&& __1n -> __O2__4expr.string )
# 273 "/home/claude/cfront-3/src/norm.cpp"
{
# 273 "/home/claude/cfront-3/src/norm.cpp"

# 274 "/home/claude/cfront-3/src/norm.cpp"
Pname __2nx ;

# 274 "/home/claude/cfront-3/src/norm.cpp"
__2nx = k_find_name__FPCcP6ktableUc ( __1n -> __O2__4expr.string , Ctbl , (unsigned char )0 ) ;
if (__2nx && (__2nx -> base__4node == 123 ))hide__4nameFv ( __2nx ) ;
}

# 278 "/home/claude/cfront-3/src/norm.cpp"
{ int __1defa ;

# 279 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X89 ;

# 278 "/home/claude/cfront-3/src/norm.cpp"
__1defa = 0 ;
switch (__0this -> base__4node ){ 
# 279 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X87 ;

# 280 "/home/claude/cfront-3/src/norm.cpp"
case 0 :
# 281 "/home/claude/cfront-3/src/norm.cpp"
__1defa = 1 ;
__0this -> base__4node = 21 ;
break ;
case 121 :
# 285 "/home/claude/cfront-3/src/norm.cpp"
case 119 :
# 286 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_name__8basetype -> base__4node == 123 ){ 
# 286 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V71 ;

# 286 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V72 ;

# 286 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"TN%n inCO %p", (const struct ea *)( (__2__X87 =
# 286 "/home/claude/cfront-3/src/norm.cpp"
(const void *)__0this -> b_name__8basetype ), ( ((& __0__V71 )-> __O1__2ea.p = __2__X87 ), (& __0__V71 )) ) , (const
# 286 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)( ((& __0__V72 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V72 )) , (const struct ea *)ea0 ,
# 286 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} }

# 289 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_long__8basetype || __0this -> b_short__8basetype ){ 
# 290 "/home/claude/cfront-3/src/norm.cpp"
TOK __2sl ;

# 291 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X88 ;

# 290 "/home/claude/cfront-3/src/norm.cpp"
__2sl = (__0this -> b_short__8basetype ?29 :((__0this -> b_long__8basetype > 1 )?122 :22 ));
if (__0this -> b_long__8basetype && __0this -> b_short__8basetype ){ 
# 291 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V73 ;

# 291 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V74 ;

# 291 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:long short%k%n", (const struct ea *)( (__2__X88 = __0this -> base__4node ),
# 291 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V73 )-> __O1__2ea.i = __2__X88 ), 0 ) ), (& __0__V73 )) ) , (const struct
# 291 "/home/claude/cfront-3/src/norm.cpp"
ea *)( ((& __0__V74 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V74 )) , (const struct ea *)ea0 , (const
# 291 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 ) ;
} if (__0this -> base__4node != 21 )
# 293 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 293 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V75 ;

# 293 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V76 ;

# 293 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V77 ;

# 293 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:%k%k%n", (const struct ea *)( (( ((& __0__V75 )->
# 293 "/home/claude/cfront-3/src/norm.cpp"
__O1__2ea.i = ((unsigned long )__2sl )), 0 ) ), (& __0__V75 )) , (const struct ea *)__ct__2eaFUl ( & __0__V76 ,
# 293 "/home/claude/cfront-3/src/norm.cpp"
(unsigned long )__0this -> base__4node ) , (const struct ea *)( ((& __0__V77 )-> __O1__2ea.p = ((const void *)__1n )),
# 293 "/home/claude/cfront-3/src/norm.cpp"
(& __0__V77 )) , (const struct ea *)ea0 ) ;
} else 
# 295 "/home/claude/cfront-3/src/norm.cpp"
__0this -> base__4node = __2sl ;
__0this -> b_short__8basetype = (__0this -> b_long__8basetype = 0 );
}

# 299 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_typedef__8basetype && __0this -> b_sto__8basetype ){ 
# 299 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V78 ;

# 299 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V79 ;

# 299 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT:Tdef%k%n", (const struct ea *)( (__2__X89 = __0this -> b_sto__8basetype ),
# 299 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V78 )-> __O1__2ea.i = __2__X89 ), 0 ) ), (& __0__V78 )) ) , (const struct
# 299 "/home/claude/cfront-3/src/norm.cpp"
ea *)( ((& __0__V79 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V79 )) , (const struct ea *)ea0 , (const
# 299 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 ) ;
} __0this -> b_typedef__8basetype = (__0this -> b_sto__8basetype = 0 );

# 302 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> __O1__8basetype.b_linkage ){ 
# 303 "/home/claude/cfront-3/src/norm.cpp"
if (1 <= bl_level )error__FPCc ( (const char *)"local linkage directive") ;
# 303 "/home/claude/cfront-3/src/norm.cpp"

# 304 "/home/claude/cfront-3/src/norm.cpp"
}

# 306 "/home/claude/cfront-3/src/norm.cpp"
if (Pfctvec_type == 0 )return __0this ;

# 308 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_const__4type ){ 
# 309 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_unsigned__8basetype ){ 
# 310 "/home/claude/cfront-3/src/norm.cpp"
switch (__0this -> base__4node ){ 
# 310 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X90 ;

# 311 "/home/claude/cfront-3/src/norm.cpp"
default :
# 312 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 312 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V80 ;

# 312 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V81 ;

# 312 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT: unsigned const %k%n", (const struct ea *)( (__2__X90 = __0this -> base__4node ),
# 312 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V80 )-> __O1__2ea.i = __2__X90 ), 0 ) ), (& __0__V80 )) ) , (const struct
# 312 "/home/claude/cfront-3/src/norm.cpp"
ea *)( ((& __0__V81 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V81 )) , (const struct ea *)ea0 , (const
# 312 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 ) ;
__0this -> b_unsigned__8basetype = 0 ;
case 22 :
# 315 "/home/claude/cfront-3/src/norm.cpp"
case 122 :
# 316 "/home/claude/cfront-3/src/norm.cpp"
case 29 :
# 317 "/home/claude/cfront-3/src/norm.cpp"
case 21 :
# 318 "/home/claude/cfront-3/src/norm.cpp"
case 5 :
# 319 "/home/claude/cfront-3/src/norm.cpp"
return __0this ;
} }
}
return __0this ;
}
else if (__0this -> b_unsigned__8basetype ){ 
# 325 "/home/claude/cfront-3/src/norm.cpp"
switch (__0this -> base__4node ){ 
# 325 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X91 ;

# 326 "/home/claude/cfront-3/src/norm.cpp"
case 22 :
# 327 "/home/claude/cfront-3/src/norm.cpp"
__dl__FPv ( (void *)__0this ) ;
return ulong_type ;
case 122 :
# 330 "/home/claude/cfront-3/src/norm.cpp"
__dl__FPv ( (void *)__0this ) ;
return ullong_type ;
case 29 :
# 333 "/home/claude/cfront-3/src/norm.cpp"
__dl__FPv ( (void *)__0this ) ;
return ushort_type ;
case 21 :
# 336 "/home/claude/cfront-3/src/norm.cpp"
__dl__FPv ( (void *)__0this ) ;
return uint_type ;
case 5 :
# 339 "/home/claude/cfront-3/src/norm.cpp"
__dl__FPv ( (void *)__0this ) ;
return uchar_type ;
default :
# 342 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 342 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V82 ;

# 342 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V83 ;

# 342 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"badBT: unsigned%k%n", (const struct ea *)( (__2__X91 = __0this -> base__4node ),
# 342 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V82 )-> __O1__2ea.i = __2__X91 ), 0 ) ), (& __0__V82 )) ) , (const struct
# 342 "/home/claude/cfront-3/src/norm.cpp"
ea *)( ((& __0__V83 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V83 )) , (const struct ea *)ea0 , (const
# 342 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 ) ;
__0this -> b_unsigned__8basetype = 0 ;
return __0this ;
} }
}
else { 
# 348 "/home/claude/cfront-3/src/norm.cpp"
switch (__0this -> base__4node ){ 
# 349 "/home/claude/cfront-3/src/norm.cpp"
case 22 :
# 350 "/home/claude/cfront-3/src/norm.cpp"
__dl__FPv ( (void *)__0this ) ;
return long_type ;
case 122 :
# 353 "/home/claude/cfront-3/src/norm.cpp"
__dl__FPv ( (void *)__0this ) ;
return llong_type ;
case 29 :
# 356 "/home/claude/cfront-3/src/norm.cpp"
__dl__FPv ( (void *)__0this ) ;
return short_type ;
case 21 :
# 359 "/home/claude/cfront-3/src/norm.cpp"
if ((__0this == int_type )|| (__0this == defa_type ))return __0this ;
__dl__FPv ( (void *)__0this ) ;
if (__1defa )return defa_type ;
return int_type ;
case 5 :
# 364 "/home/claude/cfront-3/src/norm.cpp"
__dl__FPv ( (void *)__0this ) ;
return char_type ;
case 38 :
# 367 "/home/claude/cfront-3/src/norm.cpp"
__dl__FPv ( (void *)__0this ) ;
return void_type ;
case 97 :
# 371 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_name__8basetype -> __O2__4name.n_qualifier ){ 
# 372 "/home/claude/cfront-3/src/norm.cpp"
Pbase __4rv ;

# 372 "/home/claude/cfront-3/src/norm.cpp"
__4rv = (((struct basetype *)(((struct basetype *)__0this -> b_name__8basetype -> __O2__4name.n_qualifier ))));
__dl__FPv ( (void *)__0this ) ;
return __4rv ;
}
else { 
# 377 "/home/claude/cfront-3/src/norm.cpp"
__0this -> permanent__4node = 1 ;
__0this -> b_name__8basetype -> __O2__4name.n_qualifier = (((struct name *)(((struct name *)__0this ))));
return __0this ;
}
default :
# 382 "/home/claude/cfront-3/src/norm.cpp"
return __0this ;
}
}

# 384 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 115 "/home/claude/cfront-3/src/cfront.h"
extern Pname insert_type__FP4nameP6ktableUc (Pname , Pktab , TOK );

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 388 "/home/claude/cfront-3/src/norm.cpp"
static int check_redef__FP4nameT1 (Pname __1on , Pname __1nn )
# 389 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 394 "/home/claude/cfront-3/src/norm.cpp"
if (Nold ){ 
# 397 "/home/claude/cfront-3/src/norm.cpp"
if (check__4typeFP4typeUcT2 ( __1on -> __O1__4expr.tp , __1nn -> __O1__4expr.tp , (unsigned char
# 397 "/home/claude/cfront-3/src/norm.cpp"
)0 , (unsigned char )0 ) == 0 ){ 
# 398 "/home/claude/cfront-3/src/norm.cpp"
__1nn -> base__4node = 123 ;
return 1 ;
}
if (__1nn -> __O3__4expr.tpdef -> in_class__4type && (__1nn -> __O3__4expr.tpdef -> in_class__4type -> csu__8classdef == 167 )){ 
# 401 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X101 ;

# 402 "/home/claude/cfront-3/src/norm.cpp"
if (__1nn -> __O3__4expr.tpdef -> defined__4type == 0 )
# 403 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 403 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V92 ;

# 403 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"twoDs of %s (one in anonymous union)", (const struct ea *)(
# 403 "/home/claude/cfront-3/src/norm.cpp"
(__2__X101 = (const void *)__1nn -> __O2__4expr.string ), ( ((& __0__V92 )-> __O1__2ea.p = __2__X101 ), (& __0__V92 )) ) ,
# 403 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else 
# 404 "/home/claude/cfront-3/src/norm.cpp"
if (__1on -> __O3__4expr.tpdef )
# 405 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 405 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V93 ;

# 405 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V94 ;

# 405 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V95 ;

# 405 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"%n redefined:Tdef%t andTdef%t", (const struct ea *)(
# 405 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V93 )-> __O1__2ea.p = ((const void *)__1on )), (& __0__V93 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V94 ,
# 405 "/home/claude/cfront-3/src/norm.cpp"
(const void *)__1on -> __O1__4expr.tp ) , (const struct ea *)__ct__2eaFPCv ( & __0__V95 , (const void *)__1nn -> __O1__4expr.tp )
# 405 "/home/claude/cfront-3/src/norm.cpp"
, (const struct ea *)ea0 ) ;
} else 
# 407 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 407 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V96 ;

# 407 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V97 ;

# 407 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V98 ;

# 407 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"%n redefined:%t andTdef%t", (const struct ea *)(
# 407 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V96 )-> __O1__2ea.p = ((const void *)__1on )), (& __0__V96 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V97 ,
# 407 "/home/claude/cfront-3/src/norm.cpp"
(const void *)__1on -> __O1__4expr.tp ) , (const struct ea *)__ct__2eaFPCv ( & __0__V98 , (const void *)__1nn -> __O1__4expr.tp )
# 407 "/home/claude/cfront-3/src/norm.cpp"
, (const struct ea *)ea0 ) ;
} 
# 409 "/home/claude/cfront-3/src/norm.cpp"
__1nn -> __O3__4expr.tpdef -> defined__4type = 1 ;
{ Pname __2nw ;
Pname __2x ;

# 410 "/home/claude/cfront-3/src/norm.cpp"
__2nw = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__2x = __1on ;

# 411 "/home/claude/cfront-3/src/norm.cpp"
__2x -> n_key__4name = 38 ;
((*__2nw ))= (*__1nn );
__2nw -> n_tbl_list__4name = 0 ;
__2nw -> n_ktable__4name = 0 ;
__2nw -> __O4__4expr.n_table = 0 ;
__1on = insert_type__FP4nameP6ktableUc ( __2nw , Ctbl , (unsigned char )97 ) ;
if (Nold )error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1nn -> where__4name , (const char *)"cannot recover",
# 417 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1on -> __O1__4name.n_hidden = __2x ;

# 418 "/home/claude/cfront-3/src/norm.cpp"
}
}
if (__1on -> n_key__4name == 159 ){ 
# 421 "/home/claude/cfront-3/src/norm.cpp"
if (__1nn -> __O3__4expr.tpdef -> in_class__4type && (__1nn -> __O3__4expr.tpdef -> in_class__4type -> csu__8classdef == 167 )){ 
# 421 "/home/claude/cfront-3/src/norm.cpp"
const
# 421 "/home/claude/cfront-3/src/norm.cpp"
void *__2__X102 ;

# 422 "/home/claude/cfront-3/src/norm.cpp"
if (__1nn -> __O3__4expr.tpdef -> defined__4type == 0 )
# 423 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 423 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V99 ;

# 423 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"twoDs of %s (one in anonymous union)", (const struct ea *)(
# 423 "/home/claude/cfront-3/src/norm.cpp"
(__2__X102 = (const void *)__1nn -> __O2__4expr.string ), ( ((& __0__V99 )-> __O1__2ea.p = __2__X102 ), (& __0__V99 )) ) ,
# 423 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else { 
# 425 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V100 ;

# 425 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"%n redefined: identifier andTdef", (const struct ea *)(
# 425 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V100 )-> __O1__2ea.p = ((const void *)__1on )), (& __0__V100 )) , (const struct ea *)ea0 , (const struct
# 425 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 427 "/home/claude/cfront-3/src/norm.cpp"
__1nn -> __O3__4expr.tpdef -> defined__4type = 1 ;
}
return 0 ;
}

# 935 "/home/claude/cfront-3/src/cfront.h"
Pname normalize__4nameFP8basetypeP5blockUc (struct name *__0this , Pbase , Pblock , bit );

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 265 "/home/claude/cfront-3/src/cfront.h"
Pname get_mem__6ktableFi (struct ktable *__0this , int );

# 116 "/home/claude/cfront-3/src/cfront.h"
extern Pname insert_name__FP4nameP6ktable (Pname , Pktab );

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 432 "/home/claude/cfront-3/src/norm.cpp"
Pname aggr__8basetypeFv (register struct basetype *__0this )
# 449 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 450 "/home/claude/cfront-3/src/norm.cpp"
;
if (__0this -> b_xname__8basetype ){ 
# 452 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> base__4node ){ 
# 453 "/home/claude/cfront-3/src/norm.cpp"
Pname __3n ;

# 453 "/home/claude/cfront-3/src/norm.cpp"
__3n = __ct__4nameFPCc ( (struct name *)0 , __0this -> b_xname__8basetype -> __O2__4expr.string ) ;

# 455 "/home/claude/cfront-3/src/norm.cpp"
__0this -> b_xname__8basetype = 0 ;
return normalize__4nameFP8basetypeP5blockUc ( __3n , __0this , (struct block *)0 , (unsigned char )0 ) ;
}
else { 
# 459 "/home/claude/cfront-3/src/norm.cpp"
__0this -> base__4node = 97 ;
__0this -> b_name__8basetype = __0this -> b_xname__8basetype ;
__0this -> b_xname__8basetype = 0 ;
}
}

# 465 "/home/claude/cfront-3/src/norm.cpp"
switch (__0this -> base__4node ){ 
# 466 "/home/claude/cfront-3/src/norm.cpp"
case 119 :
# 467 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 468 "/home/claude/cfront-3/src/norm.cpp"
Pclass __3cl ;
const char *__3s ;

# 470 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X117 ;

# 470 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X118 ;

# 470 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X119 ;

# 468 "/home/claude/cfront-3/src/norm.cpp"
__3cl = (((struct classdef *)(((struct classdef *)__0this -> b_name__8basetype -> __O1__4expr.tp ))));
__3s = __3cl -> string__8classdef ;
if (((__3cl -> class_base__8classdef != 2)&& ((__3cl -> in_class__4type == 0 )|| (__3cl -> in_class__4type -> class_base__8classdef != 2)))&& (__0this -> b_name__8basetype -> base__4node ==
# 470 "/home/claude/cfront-3/src/norm.cpp"
123 ))
# 473 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 473 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V103 ;

# 473 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"TN%n inCO", (const struct ea *)( (__2__X117 =
# 473 "/home/claude/cfront-3/src/norm.cpp"
(const void *)__0this -> b_name__8basetype ), ( ((& __0__V103 )-> __O1__2ea.p = __2__X117 ), (& __0__V103 )) ) , (const
# 473 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__0this -> b_const__4type ){ 
# 474 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V104 ;

# 474 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V105 ;

# 474 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"const%k%n", (const struct ea *)( (__2__X118 = __3cl -> csu__8classdef ),
# 474 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V104 )-> __O1__2ea.i = __2__X118 ), 0 ) ), (& __0__V104 )) ) , (const struct
# 474 "/home/claude/cfront-3/src/norm.cpp"
ea *)( (__2__X119 = (const void *)__0this -> b_name__8basetype ), ( ((& __0__V105 )-> __O1__2ea.p = __2__X119 ), (& __0__V105 )) )
# 474 "/home/claude/cfront-3/src/norm.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 476 "/home/claude/cfront-3/src/norm.cpp"
if (__3cl -> c_body__8classdef == 2 ){ 
# 476 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X124 ;

# 476 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X125 ;

# 477 "/home/claude/cfront-3/src/norm.cpp"
if ((((__3s [0 ])== '_' )&& ((__3s [1 ])== '_' ))&& ((__3s [2 ])== 'C' )){ 
# 478 "/home/claude/cfront-3/src/norm.cpp"
char *__5ss ;
Pname __5obj ;

# 480 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X123 ;

# 478 "/home/claude/cfront-3/src/norm.cpp"
__5ss = (((char *)__nw__FUl ( (size_t)(8* (sizeof (char )))) ));
__5obj = __ct__4nameFPCc ( (struct name *)0 , (const char *)__5ss ) ;
strcpy ( __5ss , __3s ) ;
if ((__3cl -> csu__8classdef == 36 )&& (__3cl -> class_base__8classdef != 2)){ 
# 482 "/home/claude/cfront-3/src/norm.cpp"
(__5ss [2 ])= 'O' ;
__3cl -> csu__8classdef = 167 ;
{ Pname __6un ;

# 487 "/home/claude/cfront-3/src/norm.cpp"
int __6i ;
Pname __6nn ;

# 484 "/home/claude/cfront-3/src/norm.cpp"
__6un = normalize__4nameFP8basetypeP5blockUc ( __5obj , __0this , (struct block *)0 , (unsigned char )0 ) ;

# 487 "/home/claude/cfront-3/src/norm.cpp"
__6i = 1 ;
__6nn = get_mem__6ktableFi ( __3cl -> k_tbl__8classdef , __6i ) ;
for(;__6nn ;__6nn = (__6nn -> n_tbl_list__4name ?__6nn -> n_tbl_list__4name :get_mem__6ktableFi ( __3cl -> k_tbl__8classdef , ++ __6i ) )) { 
# 490 "/home/claude/cfront-3/src/norm.cpp"
if (__6nn -> __O2__4expr.string == 0 )continue
# 490 "/home/claude/cfront-3/src/norm.cpp"
;
if (__6nn -> base__4node == 85 ){ 
# 492 "/home/claude/cfront-3/src/norm.cpp"
insert_name__FP4nameP6ktable ( __ct__4nameFPCc ( (struct name *)0 , __6nn -> __O2__4expr.string ) , Ctbl ) ;
}
else 
# 493 "/home/claude/cfront-3/src/norm.cpp"
if (__6nn -> __O1__4expr.tp == 0 ){ 
# 494 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 494 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V106 ;

# 494 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"BT::aggr(): nullT for%n in anon union", (const struct ea *)( ((&
# 494 "/home/claude/cfront-3/src/norm.cpp"
__0__V106 )-> __O1__2ea.p = ((const void *)__6nn )), (& __0__V106 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 494 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} }
else 
# 495 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 496 "/home/claude/cfront-3/src/norm.cpp"
Pname __8nx ;

# 496 "/home/claude/cfront-3/src/norm.cpp"
__8nx = __ct__4nameFPCc ( (struct name *)0 , __6nn -> __O2__4expr.string ) ;
__8nx -> __O1__4expr.tp = __6nn -> __O1__4expr.tp ;
__8nx -> __O3__4expr.tpdef = __6nn -> __O3__4expr.tpdef ;
__8nx -> where__4name = __6nn -> where__4name ;
if (__6nn -> __O3__4expr.tpdef ){ 
# 501 "/home/claude/cfront-3/src/norm.cpp"
__8nx = insert_type__FP4nameP6ktableUc ( __8nx , Ctbl , (unsigned char )97 ) ;
check_redef__FP4nameT1 ( __8nx , __6nn ) ;
}
else 
# 503 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 504 "/home/claude/cfront-3/src/norm.cpp"
switch (__8nx -> __O1__4expr.tp -> base__4node ){ 
# 504 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X122 ;

# 505 "/home/claude/cfront-3/src/norm.cpp"
case 119 :
# 506 "/home/claude/cfront-3/src/norm.cpp"
{ Pclass __11mcl ;

# 506 "/home/claude/cfront-3/src/norm.cpp"
__11mcl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__6nn -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))));
if ((__11mcl -> csu__8classdef != 167 )&& (! ((((__11mcl -> string__8classdef [0 ])== '_' )&& ((__11mcl -> string__8classdef [1 ])== '_' ))&& ((__11mcl -> string__8classdef [2 ])== 'C' ))))
# 511 "/home/claude/cfront-3/src/norm.cpp"
{
# 511 "/home/claude/cfront-3/src/norm.cpp"

# 512 "/home/claude/cfront-3/src/norm.cpp"
__8nx = insert_type__FP4nameP6ktableUc ( __8nx , Ctbl , __11mcl -> csu__8classdef ) ;
if (Nold ){ 
# 514 "/home/claude/cfront-3/src/norm.cpp"
Pname __13x ;
Pclass __13ocl ;

# 516 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X120 ;

# 514 "/home/claude/cfront-3/src/norm.cpp"
__13x = is_cl_obj__4typeFv ( __8nx -> __O1__4expr.tp ) ;
__13ocl = (__13x ?(((struct classdef *)(((struct classdef *)__13x -> __O1__4expr.tp )))):(((struct classdef *)0 )));
if (((__13ocl == 0 )|| strcmp ( __13ocl -> string__8classdef , __11mcl -> string__8classdef ) )|| ((__13ocl -> defined__4type & 5)&& (__11mcl -> defined__4type &
# 516 "/home/claude/cfront-3/src/norm.cpp"
5)))
# 521 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 521 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V107 ;

# 521 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __6nn -> where__4name , (const char *)"twoDs of %s (one in anonymous union)", (const struct ea *)(
# 521 "/home/claude/cfront-3/src/norm.cpp"
(__2__X120 = (const void *)__6nn -> __O2__4expr.string ), ( ((& __0__V107 )-> __O1__2ea.p = __2__X120 ), (& __0__V107 )) ) ,
# 521 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (__11mcl -> defined__4type & 5)
# 523 "/home/claude/cfront-3/src/norm.cpp"
__8nx -> __O1__4expr.tp = __6nn -> __O1__4expr.tp ;
}
}
}
break ;
case 121 :
# 529 "/home/claude/cfront-3/src/norm.cpp"
if ((((__6nn -> __O2__4expr.string [0 ])== '_' )&& ((__6nn -> __O2__4expr.string [1 ])== '_' ))&& ((__6nn -> __O2__4expr.string [2 ])== 'E' ))
# 532 "/home/claude/cfront-3/src/norm.cpp"
break ;
__8nx = insert_type__FP4nameP6ktableUc ( __8nx , Ctbl , (unsigned char )13 ) ;
if (Nold ){ 
# 535 "/home/claude/cfront-3/src/norm.cpp"
Ptype __11t ;
Penum __11oe ;

# 535 "/home/claude/cfront-3/src/norm.cpp"
__11t = skiptypedefs__4typeFv ( __8nx -> __O1__4expr.tp ) ;
__11oe = ((__11t -> base__4node == 121 )?(((struct enumdef *)(((struct enumdef *)(((struct basetype *)(((struct basetype *)__11t ))))-> b_name__8basetype -> __O1__4expr.tp )))):(((struct enumdef *)0 )));
__11t = skiptypedefs__4typeFv ( __6nn -> __O1__4expr.tp ) ;
{ Penum __11ne ;

# 539 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X121 ;

# 538 "/home/claude/cfront-3/src/norm.cpp"
__11ne = ((__11t -> base__4node == 121 )?(((struct enumdef *)(((struct enumdef *)(((struct basetype *)(((struct basetype *)__11t ))))-> b_name__8basetype -> __O1__4expr.tp )))):(((struct enumdef *)0 )));
if (((__11oe == 0 )|| strcmp ( __11oe -> string__7enumdef , __11ne -> string__7enumdef ) )|| ((__11oe -> defined__4type & 5)&& (__11ne -> defined__4type &
# 539 "/home/claude/cfront-3/src/norm.cpp"
5)))
# 544 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 544 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V108 ;

# 544 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __6nn -> where__4name , (const char *)"twoDs of %s (one in anonymous union)", (const struct ea *)(
# 544 "/home/claude/cfront-3/src/norm.cpp"
(__2__X121 = (const void *)__6nn -> __O2__4expr.string ), ( ((& __0__V108 )-> __O1__2ea.p = __2__X121 ), (& __0__V108 )) ) ,
# 544 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (__11ne -> defined__4type & 5)
# 546 "/home/claude/cfront-3/src/norm.cpp"
__8nx -> __O1__4expr.tp = __6nn -> __O1__4expr.tp ;

# 546 "/home/claude/cfront-3/src/norm.cpp"
}
}
break ;
default :
# 550 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 550 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V109 ;

# 550 "/home/claude/cfront-3/src/norm.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __6nn -> where__4name , (const char *)"missing tpdef forTdefN %s", (const
# 550 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)( (__2__X122 = (const void *)__8nx -> __O2__4expr.string ), ( ((& __0__V109 )-> __O1__2ea.p = __2__X122 ), (& __0__V109 ))
# 550 "/home/claude/cfront-3/src/norm.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}

# 554 "/home/claude/cfront-3/src/norm.cpp"
}
}
return __6un ;

# 556 "/home/claude/cfront-3/src/norm.cpp"
}
}
if (__3cl -> class_base__8classdef != 2)
# 559 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 559 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V110 ;

# 559 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"unusable%k ignored", (const struct ea *)( (__2__X123 =
# 559 "/home/claude/cfront-3/src/norm.cpp"
__3cl -> csu__8classdef ), ( (( ((& __0__V110 )-> __O1__2ea.i = __2__X123 ), 0 ) ), (& __0__V110 )) ) ,
# 559 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
if (__0this -> b_sto__8basetype == 18 )
# 562 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 562 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V111 ;

# 562 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V112 ;

# 562 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"friend%k%n{...} -- may only declare a friendC", (const struct ea *)( (__2__X124 = __3cl -> csu__8classdef ),
# 562 "/home/claude/cfront-3/src/norm.cpp"
( (( ((& __0__V111 )-> __O1__2ea.i = __2__X124 ), 0 ) ), (& __0__V111 )) ) , (const struct
# 562 "/home/claude/cfront-3/src/norm.cpp"
ea *)( (__2__X125 = (const void *)__0this -> b_name__8basetype ), ( ((& __0__V112 )-> __O1__2ea.p = __2__X125 ), (& __0__V112 )) )
# 562 "/home/claude/cfront-3/src/norm.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __3cl -> c_body__8classdef = 1 ;
return __0this -> b_name__8basetype ;
}
else { 
# 567 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_sto__8basetype == 18 )goto frr ;
{ Pname __4nn ;

# 568 "/home/claude/cfront-3/src/norm.cpp"
__4nn = __ct__4nameFPCc ( (struct name *)0 , __3cl -> string__8classdef ) ;
__4nn -> __O1__4expr.tp = __0this -> b_name__8basetype -> __O1__4expr.tp ;
__4nn -> n_key__4name = 44 ;
return __4nn ;

# 571 "/home/claude/cfront-3/src/norm.cpp"
}
}
}

# 575 "/home/claude/cfront-3/src/norm.cpp"
case 121 :
# 576 "/home/claude/cfront-3/src/norm.cpp"
{ Penum __3en ;

# 577 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X126 ;

# 577 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X127 ;

# 576 "/home/claude/cfront-3/src/norm.cpp"
__3en = (((struct enumdef *)(((struct enumdef *)__0this -> b_name__8basetype -> __O1__4expr.tp ))));
if (__0this -> b_name__8basetype -> base__4node == 123 ){ 
# 577 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V113 ;

# 577 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"TN%n in enumO", (const struct ea *)( (__2__X126 =
# 577 "/home/claude/cfront-3/src/norm.cpp"
(const void *)__0this -> b_name__8basetype ), ( ((& __0__V113 )-> __O1__2ea.p = __2__X126 ), (& __0__V113 )) ) , (const
# 577 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__0this -> b_const__4type ){ 
# 578 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V114 ;

# 578 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"const enum%n", (const struct ea *)( (__2__X127 = (const void
# 578 "/home/claude/cfront-3/src/norm.cpp"
*)__0this -> b_name__8basetype ), ( ((& __0__V114 )-> __O1__2ea.p = __2__X127 ), (& __0__V114 )) ) , (const struct ea *)ea0 ,
# 578 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__3en -> e_body__7enumdef == 2 ){ 
# 580 "/home/claude/cfront-3/src/norm.cpp"
__3en -> e_body__7enumdef = 1 ;
return __0this -> b_name__8basetype ;
}
else { 
# 583 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X128 ;

# 584 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 584 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V115 ;

# 584 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"forwardD of enum%n", (const struct ea *)( (__2__X128 = (const void
# 584 "/home/claude/cfront-3/src/norm.cpp"
*)__0this -> b_name__8basetype ), ( ((& __0__V115 )-> __O1__2ea.p = __2__X128 ), (& __0__V115 )) ) , (const struct ea *)ea0 ,
# 584 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__3en -> e_type__7enumdef = int_type ;
} }
return (struct name *)0 ;
}

# 590 "/home/claude/cfront-3/src/norm.cpp"
case 0 :
# 591 "/home/claude/cfront-3/src/norm.cpp"
{ Pname __3n ;

# 591 "/home/claude/cfront-3/src/norm.cpp"
__3n = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'D' ) ) ;
__3n -> __O1__4expr.tp = (struct type *)defa_type ;
error__FPCc ( (const char *)"NX inDL") ;
return __3n ;
}
default :
# 597 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> b_typedef__8basetype )error__FiPCc ( (int )'w' , (const char *)"illegalTdef ignored") ;
# 597 "/home/claude/cfront-3/src/norm.cpp"

# 599 "/home/claude/cfront-3/src/norm.cpp"
if ((__0this -> b_sto__8basetype == 18 )&& __0this -> b_name__8basetype ){ 
# 600 "/home/claude/cfront-3/src/norm.cpp"
frr :
# 601 "/home/claude/cfront-3/src/norm.cpp"
{ Pname __3fr ;

# 602 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X129 ;

# 601 "/home/claude/cfront-3/src/norm.cpp"
__3fr = k_find_name__FPCcP6ktableUc ( __0this -> b_name__8basetype -> __O2__4expr.string , Ctbl , (unsigned char )0 ) ;
if ((__3fr == 0 )|| (__3fr -> base__4node != 123 )){ 
# 602 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V116 ;

# 602 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"cannot find friend%n", (const struct ea *)( (__2__X129 =
# 602 "/home/claude/cfront-3/src/norm.cpp"
(const void *)__0this -> b_name__8basetype ), ( ((& __0__V116 )-> __O1__2ea.p = __2__X129 ), (& __0__V116 )) ) , (const
# 602 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} { Pname __3n ;

# 603 "/home/claude/cfront-3/src/norm.cpp"
__3n = __ct__4nameFPCc ( (struct name *)0 , __0this -> b_name__8basetype -> __O2__4expr.string ) ;
__3n -> n_sto__4name = 18 ;

# 607 "/home/claude/cfront-3/src/norm.cpp"
if ((__3fr -> __O1__4expr.tp -> base__4node == 119 )&& ((((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__3fr -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> class_base__8classdef ==
# 607 "/home/claude/cfront-3/src/norm.cpp"
2))
# 608 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 609 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> base__4node == 119 )
# 610 "/home/claude/cfront-3/src/norm.cpp"
__3n -> __O1__4expr.tp = (struct type *)__0this ;
else 
# 612 "/home/claude/cfront-3/src/norm.cpp"
if (((__0this -> base__4node == 97 )&& ((((struct basetype *)(((struct basetype *)__0this ))))-> b_name__8basetype -> base__4node == 123 ))&& ((((struct basetype *)(((struct basetype *)__0this ))))->
# 612 "/home/claude/cfront-3/src/norm.cpp"
b_name__8basetype -> __O1__4expr.tp -> base__4node == 119 ))
# 615 "/home/claude/cfront-3/src/norm.cpp"
__3n -> __O1__4expr.tp = (((struct basetype *)(((struct basetype *)__0this ))))-> b_name__8basetype -> __O1__4expr.tp ;
else 
# 617 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCc ( (int )'i' , (const char *)"basetype wasn't a COBJ") ;
}
else __3n -> __O1__4expr.tp = __3fr -> __O1__4expr.tp ;
return __3n ;

# 620 "/home/claude/cfront-3/src/norm.cpp"
}

# 620 "/home/claude/cfront-3/src/norm.cpp"
}
}
else { 
# 623 "/home/claude/cfront-3/src/norm.cpp"
Pname __3n ;

# 623 "/home/claude/cfront-3/src/norm.cpp"
__3n = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'D' ) ) ;
__3n -> __O1__4expr.tp = (struct type *)defa_type ;
error__FPCc ( (const char *)"NX inDL") ;
return __3n ;
}
}
}

# 643 "/home/claude/cfront-3/src/norm.cpp"
int defer_check = 0 ;

# 493 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 328 "/home/claude/cfront-3/src/cfront.h"
Pclass classtype__4typeFv (struct type *__0this );

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

# 646 "/home/claude/cfront-3/src/norm.cpp"
void hide__4nameFv (register struct name *__0this )
# 650 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 651 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> base__4node != 123 )return ;

# 653 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> n_key__4name == 0 ){ 
# 654 "/home/claude/cfront-3/src/norm.cpp"
if ((__0this -> lex_level__4name == bl_level )&& (in_arg_list == 0 )){ 
# 655 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> __O1__4expr.tp -> base__4node !=
# 655 "/home/claude/cfront-3/src/norm.cpp"
119 ){ 
# 657 "/home/claude/cfront-3/src/norm.cpp"
if (((in_typedef && in_typedef -> base__4node )&& (__0this -> __O1__4expr.tp -> base__4node != type_set__FP8basetype ( ((struct basetype *)(((struct basetype *)in_typedef )))) ))&& check__4typeFP4typeUcT2 (
# 657 "/home/claude/cfront-3/src/norm.cpp"
in_typedef , __0this -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) )
# 659 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 660 "/home/claude/cfront-3/src/norm.cpp"
if (defer_check == 0 )
# 661 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 661 "/home/claude/cfront-3/src/norm.cpp"
struct
# 661 "/home/claude/cfront-3/src/norm.cpp"
ea __0__V130 ;

# 661 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V131 ;

# 661 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V132 ;

# 661 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n redefined: previous: %t now: %t", (const struct ea *)( ((& __0__V130 )-> __O1__2ea.p =
# 661 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__0this )), (& __0__V130 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V131 , (const void *)__0this ->
# 661 "/home/claude/cfront-3/src/norm.cpp"
__O1__4expr.tp ) , (const struct ea *)__ct__2eaFPCv ( & __0__V132 , (const void *)in_typedef ) , (const struct ea *)ea0 )
# 661 "/home/claude/cfront-3/src/norm.cpp"
;
} }
}
else { 
# 667 "/home/claude/cfront-3/src/norm.cpp"
if ((in_typedef && in_typedef -> base__4node )&& check__4typeFP4typeUcT2 ( in_typedef , __0this -> __O1__4expr.tp , (unsigned char )0 ,
# 667 "/home/claude/cfront-3/src/norm.cpp"
(unsigned char )0 ) )
# 668 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 669 "/home/claude/cfront-3/src/norm.cpp"
if (defer_check == 0 )
# 670 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 670 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V133 ;

# 670 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V134 ;

# 670 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V135 ;

# 670 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n redefined: previous: %t now: %t", (const struct ea *)( ((& __0__V133 )-> __O1__2ea.p =
# 670 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__0this )), (& __0__V133 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V134 , (const void *)__0this ->
# 670 "/home/claude/cfront-3/src/norm.cpp"
__O1__4expr.tp ) , (const struct ea *)__ct__2eaFPCv ( & __0__V135 , (const void *)in_typedef ) , (const struct ea *)ea0 )
# 670 "/home/claude/cfront-3/src/norm.cpp"
;
} }
else { 
# 673 "/home/claude/cfront-3/src/norm.cpp"
Pname __5nn ;
Pclass __5cl ;

# 675 "/home/claude/cfront-3/src/norm.cpp"
struct classdef *__1__X141 ;

# 675 "/home/claude/cfront-3/src/norm.cpp"
struct classdef *__1__X142 ;

# 673 "/home/claude/cfront-3/src/norm.cpp"
__5nn = (((struct basetype *)(((struct basetype *)__0this -> __O1__4expr.tp ))))-> b_name__8basetype ;
__5cl = (((struct classdef *)(((struct classdef *)__5nn -> __O1__4expr.tp ))));

# 677 "/home/claude/cfront-3/src/norm.cpp"
if (in_typedef )
# 678 "/home/claude/cfront-3/src/norm.cpp"
while (in_typedef -> base__4node == 97 )
# 679 "/home/claude/cfront-3/src/norm.cpp"
in_typedef = (((struct basetype *)(((struct basetype *)in_typedef ))))-> b_name__8basetype -> __O1__4expr.tp ;
if ((in_typedef && (in_typedef -> base__4node == 119 ))&& ( (__1__X141 = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)in_typedef ))))-> b_name__8basetype -> __O1__4expr.tp ))))),
# 680 "/home/claude/cfront-3/src/norm.cpp"
( (__1__X142 = __5cl ), ( ((__1__X141 == __1__X142 )?1 :((__1__X141 && __1__X142 )?(((int )same_class__8classdefFP8classdefi ( __1__X141 , __1__X142 , 0 ) )):0 ))) ) )
# 680 "/home/claude/cfront-3/src/norm.cpp"
)
# 683 "/home/claude/cfront-3/src/norm.cpp"
in_typedef = __0this -> __O1__4expr.tp ;
else if (( __5cl -> c_ctor__8classdef ) )
# 685 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 685 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V136 ;

# 685 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V137 ;

# 685 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n redefined: both aCNWK and %s", (const struct ea *)( ((& __0__V136 )-> __O1__2ea.p =
# 685 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__0this )), (& __0__V136 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V137 , (const void *)(in_typedef ?"a type name":(((char
# 685 "/home/claude/cfront-3/src/norm.cpp"
*)"an identifier")))) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}

# 689 "/home/claude/cfront-3/src/norm.cpp"
}

# 691 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> __O4__4expr.n_table == 0 ){ 
# 693 "/home/claude/cfront-3/src/norm.cpp"
Pclass __3cl ;

# 693 "/home/claude/cfront-3/src/norm.cpp"
__3cl = 0 ;
if (__0this -> __O1__4expr.tp -> base__4node == 119 )__3cl = classtype__4typeFv ( __0this -> __O1__4expr.tp ) ;
if ((__0this -> n_template_arg__4name == 1)&& in_progress__17templ_compilation )
# 697 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 697 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V138 ;

# 697 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"reuse of formalYZ%n", (const struct ea *)( ((&
# 697 "/home/claude/cfront-3/src/norm.cpp"
__0__V138 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V138 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 697 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} else if (__3cl && ((__3cl -> class_base__8classdef == 4)|| (__3cl -> class_base__8classdef == 5)))
# 700 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 700 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V139 ;

# 700 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"illegal use of instantiatedYC%t", (const struct ea *)( ((& __0__V139 )-> __O1__2ea.p =
# 700 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__3cl )), (& __0__V139 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 700 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} else { 
# 701 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V140 ;

# 701 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%n->hide() -- no n_table", (const struct ea *)( ((&
# 701 "/home/claude/cfront-3/src/norm.cpp"
__0__V140 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V140 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 701 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} }
insert_name__FP4nameP6ktable ( __ct__4nameFPCc ( (struct name *)0 , __0this -> __O2__4expr.string ) , Ctbl ) ;
}
}

# 712 "/home/claude/cfront-3/src/norm.cpp"
int classid = 0 ;

# 937 "/home/claude/cfront-3/src/cfront.h"
Pname tname__4nameFUc (struct name *__0this , TOK );

# 129 "/home/claude/cfront-3/src/template.h"
void introduce_class_templ__17templ_compilationFP4name (struct templ_compilation *__0this , Pname __1cnamep );

# 657 "/home/claude/cfront-3/src/cfront.h"
struct name_list *__ct__9name_listFP4nameP9name_list (struct name_list *__0this , Pname __1ff , Plist __1ll );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 717 "/home/claude/cfront-3/src/norm.cpp"
Pname start_cl__FUcP4nameP6basecl (TOK __1t , Pname __1c , Pbcl __1b )
# 718 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 719 "/home/claude/cfront-3/src/norm.cpp"
int __1mk_local ;

# 719 "/home/claude/cfront-3/src/norm.cpp"
__1mk_local = 0 ;

# 722 "/home/claude/cfront-3/src/norm.cpp"
;
if (__1c == 0 ){ 
# 724 "/home/claude/cfront-3/src/norm.cpp"
int __2save ;

# 724 "/home/claude/cfront-3/src/norm.cpp"
__2save = stcount ;

# 724 "/home/claude/cfront-3/src/norm.cpp"
stcount = (classid ++ );
__1c = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'C' ) ) ;
stcount = __2save ;
__1c -> lex_level__4name -= (in_class_decl + 1 );
if (in_typedef && __1c -> lex_level__4name )
# 729 "/home/claude/cfront-3/src/norm.cpp"
__1mk_local = 1 ;

# 731 "/home/claude/cfront-3/src/norm.cpp"
}
else if ((ccl && (ccl -> lex_level__4type == __1c -> lex_level__4name ))&& (strcmp ( ccl -> string__8classdef , __1c -> __O2__4expr.string ) == 0 ))
# 733 "/home/claude/cfront-3/src/norm.cpp"
{
# 733 "/home/claude/cfront-3/src/norm.cpp"

# 733 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X155 ;

# 734 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 734 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V143 ;

# 734 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V144 ;

# 734 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k %s redefines enclosing class", (const struct ea *)( (( ((& __0__V143 )->
# 734 "/home/claude/cfront-3/src/norm.cpp"
__O1__2ea.i = ((unsigned long )__1t )), 0 ) ), (& __0__V143 )) , (const struct ea *)( (__2__X155 = (const
# 734 "/home/claude/cfront-3/src/norm.cpp"
void *)__1c -> __O2__4expr.string ), ( ((& __0__V144 )-> __O1__2ea.p = __2__X155 ), (& __0__V144 )) ) , (const struct
# 734 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
error__FiPCc ( (int )'i' , (const char *)"can't recover from previous errors") ;
} }
{ Pname __1n ;

# 737 "/home/claude/cfront-3/src/norm.cpp"
__1n = tname__4nameFUc ( __1c , __1t ) ;
__1n -> where__4name = curloc ;
{ Pbase __1bt ;

# 739 "/home/claude/cfront-3/src/norm.cpp"
__1bt = (((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp ))));
if (__1bt -> base__4node != 119 ){ 
# 741 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 741 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V145 ;

# 741 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V146 ;

# 741 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of%n:%t andC", (const struct ea *)( ((& __0__V145 )-> __O1__2ea.p =
# 741 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1n )), (& __0__V145 )) , (const struct ea *)( ((& __0__V146 )-> __O1__2ea.p = ((const void
# 741 "/home/claude/cfront-3/src/norm.cpp"
*)__1bt )), (& __0__V146 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
error__FiPCc ( (int )'i' , (const char *)"can't recover from previous errors") ;
} }
else { 
# 745 "/home/claude/cfront-3/src/norm.cpp"
if (strcmp ( __1n -> __O2__4expr.string , (((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp ))))-> b_name__8basetype -> __O2__4expr.string ) !=
# 745 "/home/claude/cfront-3/src/norm.cpp"
0 )
# 746 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 746 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V147 ;

# 746 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of %n:Tdef andC", (const struct ea *)( ((& __0__V147 )-> __O1__2ea.p =
# 746 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1n )), (& __0__V147 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 746 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} if ((classtype__4typeFv ( __1n -> __O1__4expr.tp ) -> csu__8classdef != __1t )&& ((__1t == 36 )|| (classtype__4typeFv ( __1n -> __O1__4expr.tp ) ->
# 747 "/home/claude/cfront-3/src/norm.cpp"
csu__8classdef == 36 )))
# 748 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 748 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V148 ;

# 748 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V149 ;

# 748 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V150 ;

# 748 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of%n:%k and%k", (const struct ea *)( ((& __0__V148 )-> __O1__2ea.p =
# 748 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1n )), (& __0__V148 )) , (const struct ea *)( (( ((& __0__V149 )-> __O1__2ea.i = ((unsigned
# 748 "/home/claude/cfront-3/src/norm.cpp"
long )__1t )), 0 ) ), (& __0__V149 )) , (const struct ea *)__ct__2eaFUl ( & __0__V150 , (unsigned long
# 748 "/home/claude/cfront-3/src/norm.cpp"
)classtype__4typeFv ( __1n -> __O1__4expr.tp ) -> csu__8classdef ) , (const struct ea *)ea0 ) ;
} __1bt -> b_name__8basetype -> where__4name = curloc ;
}

# 762 "/home/claude/cfront-3/src/norm.cpp"
if ((in_progress__17templ_compilation && (__1c -> lex_level__4name == 0 ))&& (((ccl == 0 )|| ((! ccl -> in_class__4type )&& (ccl -> class_base__8classdef != 2)))|| (bl_level !=
# 762 "/home/claude/cfront-3/src/norm.cpp"
((ccl -> lex_level__4type + in_class_decl )+ 1 ))))
# 766 "/home/claude/cfront-3/src/norm.cpp"
introduce_class_templ__17templ_compilationFP4name ( templp , __1n ) ;

# 771 "/home/claude/cfront-3/src/norm.cpp"
if (in_progress__17templ_compilation && __1c -> lex_level__4name ){ 
# 772 "/home/claude/cfront-3/src/norm.cpp"
if ((in_class_decl == 0 )|| in_mem_fct )
# 773 "/home/claude/cfront-3/src/norm.cpp"
if (__1mk_local == 0 )
# 774 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 774 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V151 ;

# 774 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"localC%nWinYF", (const struct ea *)( ((&
# 774 "/home/claude/cfront-3/src/norm.cpp"
__0__V151 )-> __O1__2ea.p = ((const void *)__1c )), (& __0__V151 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 774 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} else error__FiPCc ( (int )'s' , (const char *)"localCWinYF") ;
}

# 779 "/home/claude/cfront-3/src/norm.cpp"
if (__1mk_local ){ 
# 780 "/home/claude/cfront-3/src/norm.cpp"
local_class = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __1n , local_class ) ;

# 782 "/home/claude/cfront-3/src/norm.cpp"
}

# 784 "/home/claude/cfront-3/src/norm.cpp"
{ Pclass __1occl ;

# 784 "/home/claude/cfront-3/src/norm.cpp"
__1occl = ccl ;
ccl = (((struct classdef *)(((struct classdef *)__1bt -> b_name__8basetype -> __O1__4expr.tp ))));
if (ccl -> defined__4type )ccl -> defined__4type |= 020 ;
ccl -> defined__4type |= 04 ;

# 791 "/home/claude/cfront-3/src/norm.cpp"
ccl -> string__8classdef = __1n -> __O2__4expr.string ;
ccl -> csu__8classdef = __1t ;

# 795 "/home/claude/cfront-3/src/norm.cpp"
if (__1occl == 0 )
# 796 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 798 "/home/claude/cfront-3/src/norm.cpp"
ccl -> templ_base__4type = (in_progress__17templ_compilation ?3:ccl -> templ_base__4type );
}

# 802 "/home/claude/cfront-3/src/norm.cpp"
if (__1b ){ 
# 803 "/home/claude/cfront-3/src/norm.cpp"
Pbcl __2bx ;

# 803 "/home/claude/cfront-3/src/norm.cpp"
Pbcl __2bb ;

# 803 "/home/claude/cfront-3/src/norm.cpp"
Pbcl __2l ;

# 803 "/home/claude/cfront-3/src/norm.cpp"
__2bb = __1b ;

# 803 "/home/claude/cfront-3/src/norm.cpp"
__2l = 0 ;
for(;__2bb ;__2bb = __2bx ) { 
# 805 "/home/claude/cfront-3/src/norm.cpp"
__2bx = __2bb -> next__6basecl ;
__2bb -> next__6basecl = 0 ;

# 808 "/home/claude/cfront-3/src/norm.cpp"
if (__2bb -> bclass__6basecl && (((__2bb -> bclass__6basecl -> nested_sig__4type && ccl -> nested_sig__4type )&& (strcmp ( (const char *)ccl -> nested_sig__4type , (const
# 808 "/home/claude/cfront-3/src/norm.cpp"
char *)__2bb -> bclass__6basecl -> nested_sig__4type ) == 0 ))|| (((! __2bb -> bclass__6basecl -> nested_sig__4type )&& (! ccl -> nested_sig__4type ))&& (strcmp (
# 808 "/home/claude/cfront-3/src/norm.cpp"
ccl -> string__8classdef , __2bb -> bclass__6basecl -> string__8classdef ) == 0 ))))
# 819 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 819 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V152 ;

# 819 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1n -> where__4name , (const char *)"%n derived from itself", (const struct ea *)(
# 819 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V152 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V152 )) , (const struct ea *)ea0 , (const struct
# 819 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (__2l == 0 )
# 821 "/home/claude/cfront-3/src/norm.cpp"
__2l = __2bb ;
else { 
# 823 "/home/claude/cfront-3/src/norm.cpp"
{ { Pbcl __4ll ;

# 823 "/home/claude/cfront-3/src/norm.cpp"
__4ll = __2l ;

# 823 "/home/claude/cfront-3/src/norm.cpp"
for(;;) { 
# 823 "/home/claude/cfront-3/src/norm.cpp"
struct classdef *__1__X156 ;

# 823 "/home/claude/cfront-3/src/norm.cpp"
struct classdef *__1__X157 ;

# 824 "/home/claude/cfront-3/src/norm.cpp"
if (__2bb -> bclass__6basecl && ( (__1__X156 = __4ll -> bclass__6basecl ), ( (__1__X157 = __2bb -> bclass__6basecl ), ( ((__1__X156 == __1__X157 )?1 :((__1__X156 &&
# 824 "/home/claude/cfront-3/src/norm.cpp"
__1__X157 )?(((int )same_class__8classdefFP8classdefi ( __1__X156 , __1__X157 , 0 ) )):0 ))) ) ) ){ 
# 824 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X158 ;

# 825 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 825 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V153 ;

# 825 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V154 ;

# 825 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s has %s asB twice", (const struct ea *)( (__2__X158 = (const void
# 825 "/home/claude/cfront-3/src/norm.cpp"
*)ccl -> string__8classdef ), ( ((& __0__V153 )-> __O1__2ea.p = __2__X158 ), (& __0__V153 )) ) , (const struct ea *)__ct__2eaFPCv (
# 825 "/home/claude/cfront-3/src/norm.cpp"
& __0__V154 , (const void *)__2bb -> bclass__6basecl -> string__8classdef ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 825 "/home/claude/cfront-3/src/norm.cpp"
;
break ;
} }

# 829 "/home/claude/cfront-3/src/norm.cpp"
if (__4ll -> next__6basecl )
# 830 "/home/claude/cfront-3/src/norm.cpp"
__4ll = __4ll -> next__6basecl ;
else { 
# 832 "/home/claude/cfront-3/src/norm.cpp"
__2bb -> next__6basecl = __2l ;
__2l = __2bb ;
break ;
}
}

# 836 "/home/claude/cfront-3/src/norm.cpp"
}

# 836 "/home/claude/cfront-3/src/norm.cpp"
}
}
}

# 840 "/home/claude/cfront-3/src/norm.cpp"
ccl -> baselist__8classdef = __2l ;

# 842 "/home/claude/cfront-3/src/norm.cpp"
}
return __1n ;

# 843 "/home/claude/cfront-3/src/norm.cpp"
}

# 843 "/home/claude/cfront-3/src/norm.cpp"
}

# 843 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 846 "/home/claude/cfront-3/src/norm.cpp"
void end_cl__Fv (void )
# 847 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 847 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X161 ;

# 848 "/home/claude/cfront-3/src/norm.cpp"
if (parameters_in_progress__17templ_compilation )
# 849 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 849 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V159 ;

# 849 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V160 ;

# 849 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"definition ofC %tWinY parameterL : %d", (const struct ea *)( (__2__X161 = (const void
# 849 "/home/claude/cfront-3/src/norm.cpp"
*)ccl ), ( ((& __0__V159 )-> __O1__2ea.p = __2__X161 ), (& __0__V159 )) ) , (const struct ea *)( ((
# 849 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V160 )-> __O1__2ea.i = ((unsigned long )parameters_in_progress__17templ_compilation )), 0 ) ), (& __0__V160 )) , (const struct ea *)ea0 ,
# 849 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} 
# 851 "/home/claude/cfront-3/src/norm.cpp"
ccl -> c_body__8classdef = 2 ;

# 857 "/home/claude/cfront-3/src/norm.cpp"
ccl -> templ_base__4type = (in_progress__17templ_compilation ?3:(ccl -> in_class__4type ?ccl -> in_class__4type -> templ_base__4type :ccl -> templ_base__4type ));
ccl = ccl -> in_class__4type ;

# 860 "/home/claude/cfront-3/src/norm.cpp"
}

# 1095 "/home/claude/cfront-3/src/cfront.h"
extern Pname name_unlist__FP5nlist (struct nlist *);

# 862 "/home/claude/cfront-3/src/norm.cpp"
Pbase end_enum__FP4nameP5nlist (Pname __1n , struct nlist *__1b )
# 863 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 865 "/home/claude/cfront-3/src/norm.cpp"
bit __1anon ;

# 866 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X166 ;

# 865 "/home/claude/cfront-3/src/norm.cpp"
__1anon = 0 ;
if (__1n == 0 ){ 
# 867 "/home/claude/cfront-3/src/norm.cpp"
__1anon = 1 ;
__1n = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'E' ) ) ;
__1n -> lex_level__4name = (bl_level - in_class_decl );
}

# 875 "/home/claude/cfront-3/src/norm.cpp"
if (parameters_in_progress__17templ_compilation )
# 876 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 876 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V162 ;

# 876 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"definition of enum %sWinY parameterL", (const struct ea *)( (__2__X166 = (const void
# 876 "/home/claude/cfront-3/src/norm.cpp"
*)(__1anon ?(((const char *)"")):__1n -> __O2__4expr.string )), ( ((& __0__V162 )-> __O1__2ea.p = __2__X166 ), (&
# 876 "/home/claude/cfront-3/src/norm.cpp"
__0__V162 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 878 "/home/claude/cfront-3/src/norm.cpp"
if (in_progress__17templ_compilation && __1n -> lex_level__4name ){ 
# 879 "/home/claude/cfront-3/src/norm.cpp"
if ((in_class_decl == 0 )|| in_mem_fct )
# 880 "/home/claude/cfront-3/src/norm.cpp"
if (__1anon == 0 )
# 881 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 881 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V163 ;

# 881 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"local enum%nWinYF", (const struct ea *)( ((&
# 881 "/home/claude/cfront-3/src/norm.cpp"
__0__V163 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V163 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 881 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} else error__FiPCc ( (int )'s' , (const char *)"local enumWinYF") ;
}

# 885 "/home/claude/cfront-3/src/norm.cpp"
__1n = tname__4nameFUc ( __1n , (unsigned char )13 ) ;
{ Pbase __1bt ;

# 886 "/home/claude/cfront-3/src/norm.cpp"
__1bt = (((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp ))));
if (__1bt -> base__4node != 121 ){ 
# 888 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 888 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V164 ;

# 888 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V165 ;

# 888 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of%n:%t and enum", (const struct ea *)( ((& __0__V164 )-> __O1__2ea.p =
# 888 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1n )), (& __0__V164 )) , (const struct ea *)( ((& __0__V165 )-> __O1__2ea.p = ((const void
# 888 "/home/claude/cfront-3/src/norm.cpp"
*)__1bt )), (& __0__V165 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
error__FiPCc ( (int )'i' , (const char *)"can't recover from previous errors") ;
} }
__1bt -> b_name__8basetype -> where__4name = curloc ;
{ Penum __1en ;

# 892 "/home/claude/cfront-3/src/norm.cpp"
__1en = (((struct enumdef *)(((struct enumdef *)__1bt -> b_name__8basetype -> __O1__4expr.tp ))));
__1en -> e_body__7enumdef = 2 ;
__1en -> mem__7enumdef = name_unlist__FP5nlist ( __1b ) ;
if (__1en -> defined__4type ){ 
# 899 "/home/claude/cfront-3/src/norm.cpp"
__1en -> defined__4type |= 020 ;
}
__1en -> defined__4type |= 04 ;

# 906 "/home/claude/cfront-3/src/norm.cpp"
__1en -> templ_base__4type = (in_progress__17templ_compilation ?3:(__1en -> in_class__4type ?__1en -> in_class__4type -> templ_base__4type :__1en -> templ_base__4type ));
return __1bt ;

# 907 "/home/claude/cfront-3/src/norm.cpp"
}

# 907 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 323 "/home/claude/cfront-3/src/cfront.h"

# 38 "/home/claude/cfront-3/src/cfront.h"
extern char *make_nested_name__FPCcP8classdef (const char *, Pclass );

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 910 "/home/claude/cfront-3/src/norm.cpp"
Pname tdef__4nameFv (register struct name *__0this )
# 914 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 949 "/home/claude/cfront-3/src/norm.cpp"
Pname __1n ;

# 921 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> __O2__4name.n_qualifier ){ 
# 922 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 922 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V167 ;

# 922 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"QdN in typedef", (const struct ea *)( ((& __0__V167 )-> __O1__2ea.p =
# 922 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__0this )), (& __0__V167 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 922 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
__0this -> __O2__4name.n_qualifier = 0 ;
} }
if (__0this -> __O1__4expr.tp == 0 ){ 
# 925 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V168 ;

# 925 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"Tdef%n tp==0", (const struct ea *)( ((&
# 925 "/home/claude/cfront-3/src/norm.cpp"
__0__V168 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V168 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 925 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} 
# 927 "/home/claude/cfront-3/src/norm.cpp"
__0this -> lex_level__4name = (bl_level - in_class_decl );

# 929 "/home/claude/cfront-3/src/norm.cpp"
if (ccl && (ccl -> lex_level__4type == __0this -> lex_level__4name )){ 
# 929 "/home/claude/cfront-3/src/norm.cpp"
struct type *__0__X171 ;

# 929 "/home/claude/cfront-3/src/norm.cpp"
struct node *__0__X1 ;

# 931 "/home/claude/cfront-3/src/norm.cpp"
__0this -> __O3__4expr.tpdef = ( (__0__X171 = 0 ), ( ((__0__X171 || (__0__X171 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type)))
# 931 "/home/claude/cfront-3/src/norm.cpp"
))?( ( ( ( ( ( ( ( (__0__X171 = (struct type *)( (__0__X1 = (((struct node *)__0__X171 ))),
# 931 "/home/claude/cfront-3/src/norm.cpp"
( ((__0__X1 || (__0__X1 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ),
# 931 "/home/claude/cfront-3/src/norm.cpp"
(__0__X1 -> permanent__4node = 0 )) , (__0__X1 -> baseclass__4node = 0 )) :0 ), __0__X1 ) ) ), (__0__X171 -> defined__4type = 0 ))
# 931 "/home/claude/cfront-3/src/norm.cpp"
, (__0__X171 -> lex_level__4type = 0 )) , (__0__X171 -> templ_base__4type = 0)) , (__0__X171 -> in_class__4type = 0 )) , (__0__X171 ->
# 931 "/home/claude/cfront-3/src/norm.cpp"
nested_sig__4type = 0 )) , (__0__X171 -> local_sig__4type = 0 )) , (__0__X171 -> b_const__4type = 0 )) , (__0__X171 -> ansi_const__4type = 0 ))
# 931 "/home/claude/cfront-3/src/norm.cpp"
:0 ), __0__X171 ) ) ;
__0this -> __O3__4expr.tpdef -> base__4node = 190 ;
__0this -> __O3__4expr.tpdef -> permanent__4node = 1 ;
__0this -> __O3__4expr.tpdef -> nested_sig__4type = make_nested_name__FPCcP8classdef ( __0this -> __O2__4expr.string , ccl ) ;
if (strcmp ( ccl -> string__8classdef , __0this -> __O2__4expr.string ) == 0 ){ 
# 936 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 936 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V169 ;

# 936 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"nestedTdef%n redefines immediately enclosingC", (const struct ea *)(
# 936 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V169 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V169 )) , (const struct ea *)ea0 , (const struct
# 936 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 939 "/home/claude/cfront-3/src/norm.cpp"
}
__0this -> __O3__4expr.tpdef -> in_class__4type = ccl ;
}
else __0this -> __O3__4expr.tpdef = generic_tpdef ;

# 944 "/home/claude/cfront-3/src/norm.cpp"
if (in_progress__17templ_compilation && __0this -> lex_level__4name ){ 
# 945 "/home/claude/cfront-3/src/norm.cpp"
if ((in_class_decl == 0 )|| in_mem_fct )
# 946 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 946 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V170 ;

# 946 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"localTdef%nWinYF", (const struct ea *)( ((&
# 946 "/home/claude/cfront-3/src/norm.cpp"
__0__V170 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V170 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 946 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} }

# 949 "/home/claude/cfront-3/src/norm.cpp"
;
__1n = insert_type__FP4nameP6ktableUc ( __0this , Ctbl , (unsigned char )97 ) ;
if (__0this -> __O3__4expr.tpdef -> in_class__4type ){ 
# 954 "/home/claude/cfront-3/src/norm.cpp"
if ((__0this -> __O1__4expr.tp != __1n -> __O1__4expr.tp )|| (__0this -> __O3__4expr.tpdef != __1n -> __O3__4expr.tpdef ))
# 955 "/home/claude/cfront-3/src/norm.cpp"
;
else { 
# 961 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O3__4expr.tpdef -> templ_base__4type = (in_progress__17templ_compilation ?3:__0this -> __O3__4expr.tpdef -> in_class__4type -> templ_base__4type );
}

# 964 "/home/claude/cfront-3/src/norm.cpp"
}

# 969 "/home/claude/cfront-3/src/norm.cpp"
if (check_redef__FP4nameT1 ( __1n , __0this ) )return __1n ;
__1n -> base__4node = (__0this -> base__4node = 123 );
__1n -> permanent__4node = 1 ;
__0this -> __O1__4expr.tp -> permanent__4node = 1 ;
if (__0this -> __O1__4expr.tp -> base__4node == 125 )(((struct ptr *)(((struct ptr *)__0this -> __O1__4expr.tp ))))-> typ__5pvtyp -> permanent__4node = 1 ;

# 975 "/home/claude/cfront-3/src/norm.cpp"
if ((__0this -> __O1__4expr.tp -> base__4node == 119 )|| (__0this -> __O1__4expr.tp -> base__4node == 121 ))
# 976 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 977 "/home/claude/cfront-3/src/norm.cpp"
Pname __2b ;

# 977 "/home/claude/cfront-3/src/norm.cpp"
__2b = (((struct basetype *)(((struct basetype *)__0this -> __O1__4expr.tp ))))-> b_name__8basetype ;
if (((__2b -> __O2__4expr.string [0 ])== '_' )&& ((__2b -> __O2__4expr.string [1 ])== '_' ))
# 979 "/home/claude/cfront-3/src/norm.cpp"
switch (__0this -> __O1__4expr.tp -> base__4node ){ 
# 980 "/home/claude/cfront-3/src/norm.cpp"
case 119 :{ 
# 981 "/home/claude/cfront-3/src/norm.cpp"
if ((__2b ->
# 981 "/home/claude/cfront-3/src/norm.cpp"
__O2__4expr.string [2 ])== 'C' ){ 
# 982 "/home/claude/cfront-3/src/norm.cpp"
Pclass __5cl ;

# 982 "/home/claude/cfront-3/src/norm.cpp"
__5cl = (((struct classdef *)(((struct classdef *)__2b -> __O1__4expr.tp ))));
__2b -> __O2__4expr.string = __1n -> __O2__4expr.string ;
__5cl -> string__8classdef = __1n -> __O2__4expr.string ;
if (! __5cl -> local_sig__4type )
# 986 "/home/claude/cfront-3/src/norm.cpp"
__5cl -> c_strlen__8classdef = strlen ( __5cl -> string__8classdef ) ;
}
break ;
}
case 121 :{ 
# 991 "/home/claude/cfront-3/src/norm.cpp"
if ((__2b -> __O2__4expr.string [2 ])== 'E' ){ 
# 992 "/home/claude/cfront-3/src/norm.cpp"
Penum __5en ;

# 992 "/home/claude/cfront-3/src/norm.cpp"
__5en = (((struct enumdef *)(((struct enumdef *)__2b -> __O1__4expr.tp ))));
__2b -> __O2__4expr.string = __1n -> __O2__4expr.string ;
__5en -> string__7enumdef = __1n -> __O2__4expr.string ;
if (! __5en -> local_sig__4type )
# 996 "/home/claude/cfront-3/src/norm.cpp"
__5en -> e_strlen__7enumdef = strlen ( __5en -> string__7enumdef ) ;
}
}
}
}

# 1005 "/home/claude/cfront-3/src/norm.cpp"
;
return __1n ;
}

# 372 "/home/claude/cfront-3/src/cfront.h"
static struct enumdef *__ct__7enumdefFP4name (register struct enumdef *__0this , Pname __2n ){ 
# 372 "/home/claude/cfront-3/src/cfront.h"
struct type *__0__X2 ;

# 372 "/home/claude/cfront-3/src/cfront.h"
struct node *__0__X1 ;

# 372 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct enumdef *)__nw__FUl ( (size_t )(sizeof (struct enumdef))) )){ __0this = (struct enumdef *)( (__0__X2 =
# 372 "/home/claude/cfront-3/src/cfront.h"
(((struct type *)__0this ))), ( ((__0__X2 || (__0__X2 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type))) ))?( ( (
# 372 "/home/claude/cfront-3/src/cfront.h"
( ( ( ( ( (__0__X2 = (struct type *)( (__0__X1 = (((struct node *)__0__X2 ))), ( ((__0__X1 || (__0__X1 =
# 372 "/home/claude/cfront-3/src/cfront.h"
(struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 -> permanent__4node = 0 ))
# 372 "/home/claude/cfront-3/src/cfront.h"
, (__0__X1 -> baseclass__4node = 0 )) :0 ), __0__X1 ) ) ), (__0__X2 -> defined__4type = 0 )) , (__0__X2 -> lex_level__4type =
# 372 "/home/claude/cfront-3/src/cfront.h"
0 )) , (__0__X2 -> templ_base__4type = 0)) , (__0__X2 -> in_class__4type = 0 )) , (__0__X2 -> nested_sig__4type = 0 )) ,
# 372 "/home/claude/cfront-3/src/cfront.h"
(__0__X2 -> local_sig__4type = 0 )) , (__0__X2 -> b_const__4type = 0 )) , (__0__X2 -> ansi_const__4type = 0 )) :0 ), __0__X2 ) )
# 372 "/home/claude/cfront-3/src/cfront.h"
;

# 372 "/home/claude/cfront-3/src/cfront.h"
__0this -> base__4node = 13 ;

# 372 "/home/claude/cfront-3/src/cfront.h"
__0this -> mem__7enumdef = __2n ;
} 
# 372 "/home/claude/cfront-3/src/cfront.h"
return __0this ;

# 372 "/home/claude/cfront-3/src/cfront.h"
}

# 443 "/home/claude/cfront-3/src/cfront.h"
struct classdef *__ct__8classdefFUc (struct classdef *__0this , TOK );

# 279 "/home/claude/cfront-3/src/cfront.h"
extern char *make_local_name__FP4typeP4name (Ptype , Pname );

# 79 "/home/claude/incl-linux32/stdio.h"
extern int fprintf (void *, const char *,...);

# 372 "/home/claude/cfront-3/src/cfront.h"

# 1009 "/home/claude/cfront-3/src/norm.cpp"
Pname tname__4nameFUc (register struct name *__0this , TOK __1csu )
# 1014 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1016 "/home/claude/cfront-3/src/norm.cpp"
const char *__1s ;
bit __1nt ;

# 1016 "/home/claude/cfront-3/src/norm.cpp"
__1s = 0 ;
__1nt = 0 ;
switch (__0this -> base__4node ){ 
# 1018 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X177 ;

# 1018 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X178 ;

# 1019 "/home/claude/cfront-3/src/norm.cpp"
case 123 :
# 1020 "/home/claude/cfront-3/src/norm.cpp"
return __0this ;
case 85 :
# 1022 "/home/claude/cfront-3/src/norm.cpp"
{ Pname __3tn ;
Pname __3on ;

# 1022 "/home/claude/cfront-3/src/norm.cpp"
__3tn = insert_type__FP4nameP6ktableUc ( __0this , Ctbl , __1csu ) ;
__3on = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__3tn -> base__4node = 123 ;
__3tn -> lex_level__4name = __0this -> lex_level__4name ;

# 1027 "/home/claude/cfront-3/src/norm.cpp"
__0this -> __O1__4name.n_list = 0 ;
__0this -> __O2__4expr.string = __3tn -> __O2__4expr.string ;
((*__3on ))= (*__0this );
switch (__1csu ){ 
# 1031 "/home/claude/cfront-3/src/norm.cpp"
case 13 :
# 1032 "/home/claude/cfront-3/src/norm.cpp"
__3tn -> __O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )121 , __3on ) ;
# 1032 "/home/claude/cfront-3/src/norm.cpp"

# 1033 "/home/claude/cfront-3/src/norm.cpp"
__3on -> __O1__4expr.tp = (struct type *)__ct__7enumdefFP4name ( (struct enumdef *)0 , (struct name *)0 ) ;
(((struct enumdef *)(((struct enumdef *)__3on -> __O1__4expr.tp ))))-> string__7enumdef = __3tn -> __O2__4expr.string ;
(((struct enumdef *)(((struct enumdef *)__3on -> __O1__4expr.tp ))))-> lex_level__4type = __3tn -> lex_level__4name ;
(((struct enumdef *)(((struct enumdef *)__3on -> __O1__4expr.tp ))))-> in_class__4type = ccl ;
(((struct enumdef *)(((struct enumdef *)__3on -> __O1__4expr.tp ))))-> e_strlen__7enumdef = strlen ( __3tn -> __O2__4expr.string ) ;
break ;
case 6 :
# 1040 "/home/claude/cfront-3/src/norm.cpp"
case 32 :
# 1041 "/home/claude/cfront-3/src/norm.cpp"
case 36 :
# 1042 "/home/claude/cfront-3/src/norm.cpp"
__3on -> __O1__4expr.tp = (struct type *)__ct__8classdefFUc ( (struct classdef *)0 , __1csu ) ;
__1s = ((((struct classdef *)(((struct classdef *)__3on -> __O1__4expr.tp ))))-> string__8classdef = __3tn -> __O2__4expr.string );
(((struct classdef *)(((struct classdef *)__3on -> __O1__4expr.tp ))))-> lex_level__4type = __0this -> lex_level__4name ;

# 1048 "/home/claude/cfront-3/src/norm.cpp"
(((struct classdef *)(((struct classdef *)__3on -> __O1__4expr.tp ))))-> k_tbl__8classdef = __ct__6ktableFiP6ktableP4name ( (struct ktable *)0 , 0 , (struct ktable *)0 , __3tn ) ;
(((struct classdef *)(((struct classdef *)__3on -> __O1__4expr.tp ))))-> k_tbl__8classdef -> k_id__6ktable = 6 ;
(((struct classdef *)(((struct classdef *)__3on -> __O1__4expr.tp ))))-> in_class__4type = ccl ;
__3tn -> __O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )119 , __3on ) ;
(((struct basetype *)(((struct basetype *)__3tn -> __O1__4expr.tp ))))-> b_table__8basetype = (((struct classdef *)(((struct classdef *)__3on -> __O1__4expr.tp ))))-> memtbl__8classdef ;
(((struct classdef *)(((struct classdef *)__3on -> __O1__4expr.tp ))))-> c_strlen__8classdef = strlen ( __3tn -> __O2__4expr.string ) ;
break ;
default :
# 1056 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1056 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V172 ;

# 1056 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V173 ;

# 1056 "/home/claude/cfront-3/src/norm.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __0this -> where__4name , (const char *)"illegal csu%k for%n in name::tname()", (const
# 1056 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)( (( ((& __0__V172 )-> __O1__2ea.i = ((unsigned long )__1csu )), 0 ) ), (& __0__V172 )) ,
# 1056 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)( ((& __0__V173 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V173 )) , (const struct
# 1056 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} }
if (ccl && (__0this -> lex_level__4name == ccl -> lex_level__4type )){ 
# 1059 "/home/claude/cfront-3/src/norm.cpp"
__3on -> __O1__4expr.tp -> nested_sig__4type = make_nested_name__FPCcP8classdef ( __0this -> __O2__4expr.string , ccl )
# 1059 "/home/claude/cfront-3/src/norm.cpp"
;
if (__1s )
# 1061 "/home/claude/cfront-3/src/norm.cpp"
( (__1s = (const char *)__3on -> __O1__4expr.tp -> nested_sig__4type ), (__1nt = 1 )) ;
}
else 
# 1062 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> lex_level__4name ){ 
# 1063 "/home/claude/cfront-3/src/norm.cpp"
__3on -> __O1__4expr.tp -> local_sig__4type = make_local_name__FP4typeP4name ( __3on -> __O1__4expr.tp , Ctbl -> k_name__6ktable ) ;
if (__1s )
# 1065 "/home/claude/cfront-3/src/norm.cpp"
__1s = (const char *)__3on -> __O1__4expr.tp -> local_sig__4type ;
}
__3tn -> permanent__4node = 1 ;
__3tn -> __O1__4expr.tp -> permanent__4node = 1 ;
__3on -> permanent__4node = 1 ;
__3on -> __O1__4expr.tp -> permanent__4node = 1 ;

# 1072 "/home/claude/cfront-3/src/norm.cpp"
if ((__1s && ansi_opt )&& (! in_progress__17templ_compilation ))
# 1073 "/home/claude/cfront-3/src/norm.cpp"
fprintf ( out_file , (const char *)"%s %s%s;\n", ((__1csu ==
# 1073 "/home/claude/cfront-3/src/norm.cpp"
36 )|| (__1csu == 167 ))?"union":(((char *)"struct")), __1nt ?"__":(((char
# 1073 "/home/claude/cfront-3/src/norm.cpp"
*)"")), __1s ) ;
return __3tn ;
}
default :
# 1077 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1077 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V174 ;

# 1077 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V175 ;

# 1077 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V176 ;

# 1077 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"tname(%s %d %k)", (const struct ea *)( (__2__X177 =
# 1077 "/home/claude/cfront-3/src/norm.cpp"
(const void *)__0this -> __O2__4expr.string ), ( ((& __0__V174 )-> __O1__2ea.p = __2__X177 ), (& __0__V174 )) ) , (const
# 1077 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)( ((& __0__V175 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V175 )) , (const struct ea *)(
# 1077 "/home/claude/cfront-3/src/norm.cpp"
(__2__X178 = __0this -> base__4node ), ( (( ((& __0__V176 )-> __O1__2ea.i = __2__X178 ), 0 ) ), (& __0__V176 )) )
# 1077 "/home/claude/cfront-3/src/norm.cpp"
, (const struct ea *)ea0 ) ;
return (struct name *)0 ;
} }
}

# 1082 "/home/claude/cfront-3/src/norm.cpp"
int co_hack = 0 ;

# 693 "/home/claude/cfront-3/src/cfront.h"
static struct vec *__ct__3vecFP4typeP4expr (register struct vec *__0this , Ptype __2t , Pexpr __2e ){ 
# 693 "/home/claude/cfront-3/src/cfront.h"
struct pvtyp *__0__X7 ;

# 693 "/home/claude/cfront-3/src/cfront.h"
struct type *__0__X6 ;

# 693 "/home/claude/cfront-3/src/cfront.h"
struct node *__0__X1 ;

# 693 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct vec *)__nw__3vecSFUl ( (size_t )(sizeof (struct vec))) )){ __0this = (struct vec *)( (__0__X7 =
# 693 "/home/claude/cfront-3/src/cfront.h"
(((struct pvtyp *)__0this ))), ( ((__0__X7 || (__0__X7 = (struct pvtyp *)__nw__FUl ( (size_t )(sizeof (struct pvtyp))) ))?(__0__X7 = (struct pvtyp *)(
# 693 "/home/claude/cfront-3/src/cfront.h"
(__0__X6 = (((struct type *)__0__X7 ))), ( ((__0__X6 || (__0__X6 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type))) ))?( (
# 693 "/home/claude/cfront-3/src/cfront.h"
( ( ( ( ( ( (__0__X6 = (struct type *)( (__0__X1 = (((struct node *)__0__X6 ))), ( ((__0__X1 ||
# 693 "/home/claude/cfront-3/src/cfront.h"
(__0__X1 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 -> permanent__4node =
# 693 "/home/claude/cfront-3/src/cfront.h"
0 )) , (__0__X1 -> baseclass__4node = 0 )) :0 ), __0__X1 ) ) ), (__0__X6 -> defined__4type = 0 )) , (__0__X6 ->
# 693 "/home/claude/cfront-3/src/cfront.h"
lex_level__4type = 0 )) , (__0__X6 -> templ_base__4type = 0)) , (__0__X6 -> in_class__4type = 0 )) , (__0__X6 -> nested_sig__4type = 0 ))
# 693 "/home/claude/cfront-3/src/cfront.h"
, (__0__X6 -> local_sig__4type = 0 )) , (__0__X6 -> b_const__4type = 0 )) , (__0__X6 -> ansi_const__4type = 0 )) :0 ), __0__X6 )
# 693 "/home/claude/cfront-3/src/cfront.h"
) ):0 ), __0__X7 ) ) ;

# 693 "/home/claude/cfront-3/src/cfront.h"
__0this -> base__4node = 110 ;

# 693 "/home/claude/cfront-3/src/cfront.h"
__0this -> typ__5pvtyp = __2t ;

# 693 "/home/claude/cfront-3/src/cfront.h"
__0this -> dim__3vec = __2e ;

# 693 "/home/claude/cfront-3/src/cfront.h"
;
} 
# 693 "/home/claude/cfront-3/src/cfront.h"
return __0this ;

# 693 "/home/claude/cfront-3/src/cfront.h"
}

# 325 "/home/claude/cfront-3/src/cfront.h"
Ptype mkconst__4typeFv (struct type *__0this );

# 633 "/home/claude/cfront-3/src/cfront.h"
struct fct *__ct__3fctFP4typeP4nameUc (struct fct *__0this , Ptype , Pname , TOK );

# 710 "/home/claude/cfront-3/src/cfront.h"
Ptype normalize__3ptrFP4type (struct ptr *__0this , Ptype );

# 695 "/home/claude/cfront-3/src/cfront.h"
Ptype normalize__3vecFP4type (struct vec *__0this , Ptype );

# 636 "/home/claude/cfront-3/src/cfront.h"
Ptype normalize__3fctFP4type (struct fct *__0this , Ptype );

# 335 "/home/claude/cfront-3/src/cfront.h"
Ptype skiptypedefs__4typeFRUc (struct type *__0this , bit *__1isconst );

# 596 "/home/claude/cfront-3/src/cfront.h"
extern void set_linkage__FPCc (const char *);

# 794 "/home/claude/cfront-3/src/cfront.h"
void del__4exprFv (struct expr *__0this );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 693 "/home/claude/cfront-3/src/cfront.h"

# 1083 "/home/claude/cfront-3/src/norm.cpp"
Pname normalize__4nameFP8basetypeP5blockUc (register struct name *__0this , Pbase __1b , Pblock __1bl , bit __1Cast )
# 1098 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1099 "/home/claude/cfront-3/src/norm.cpp"
Pname __1n ;
Pname __1nn ;
TOK __1stc ;
bit __1tpdf ;
bit __1inli ;
bit __1virt ;
const char *__1lnkg ;

# 1109 "/home/claude/cfront-3/src/norm.cpp"
;
if (__1b ){ 
# 1111 "/home/claude/cfront-3/src/norm.cpp"
__1stc = __1b -> b_sto__8basetype ;
__1tpdf = __1b -> b_typedef__8basetype ;
__1inli = __1b -> b_inline__8basetype ;
__1virt = __1b -> b_virtual__8basetype ;
__1lnkg = __1b -> __O1__8basetype.b_linkage ;
}
else { 
# 1118 "/home/claude/cfront-3/src/norm.cpp"
__1stc = 0 ;
__1tpdf = 0 ;
__1inli = 0 ;
__1virt = 0 ;
__1lnkg = 0 ;
}

# 1125 "/home/claude/cfront-3/src/norm.cpp"
if (__1inli && (__1stc == 14 )){ 
# 1126 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"both extern and inline") ;
__1inli = 0 ;
}

# 1130 "/home/claude/cfront-3/src/norm.cpp"
if ((((__1stc == 31 )&& __0this -> __O1__4expr.tp )&& (__0this -> __O1__4expr.tp -> base__4node == 108 ))&& (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_const__3fct )
# 1133 "/home/claude/cfront-3/src/norm.cpp"
{
# 1133 "/home/claude/cfront-3/src/norm.cpp"

# 1133 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V179 ;

# 1133 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n staticMF cannot be const", (const struct ea *)( ((& __0__V179 )-> __O1__2ea.p =
# 1133 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__0this )), (& __0__V179 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1133 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} 
# 1135 "/home/claude/cfront-3/src/norm.cpp"
if (__1stc == 18 ){ 
# 1137 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> __O1__4expr.tp || (__1b && ((__1b -> base__4node || __1b -> b_name__8basetype )|| __1b -> b_xname__8basetype ))){
# 1137 "/home/claude/cfront-3/src/norm.cpp"

# 1139 "/home/claude/cfront-3/src/norm.cpp"
if ((Ctbl -> k_id__6ktable != 6 )&& (Ctbl -> k_id__6ktable != 185 ))
# 1140 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1140 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V180 ;

# 1140 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"friend%n not inC", (const struct ea *)( ((& __0__V180 )-> __O1__2ea.p =
# 1140 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__0this )), (& __0__V180 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1140 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} else if (__0this -> __O2__4name.n_qualifier == 0 ){ 
# 1155 "/home/claude/cfront-3/src/norm.cpp"
__0this -> lex_level__4name = 0 ;
insert_name__FP4nameP6ktable ( __0this , Gtbl ) ;
}
}
else 
# 1158 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1179 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> __O1__4name.n_list ){ 
# 1180 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"L of friends") ;
# 1180 "/home/claude/cfront-3/src/norm.cpp"

# 1181 "/home/claude/cfront-3/src/norm.cpp"
__0this -> __O1__4name.n_list = 0 ;
}

# 1185 "/home/claude/cfront-3/src/norm.cpp"
__0this -> lex_level__4name = ccl -> lex_level__4type ;

# 1187 "/home/claude/cfront-3/src/norm.cpp"
{ Pname __3nx ;

# 1187 "/home/claude/cfront-3/src/norm.cpp"
__3nx = k_find_name__FPCcP6ktableUc ( __0this -> __O2__4expr.string , Ctbl -> k_next__6ktable , (unsigned char )0 ) ;
if (__3nx && (__3nx -> base__4node == 85 )){ 
# 1189 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1189 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V181 ;

# 1189 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"illegal friendD:F signature required for nonTN%n", (const struct ea *)(
# 1189 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V181 )-> __O1__2ea.p = ((const void *)__3nx )), (& __0__V181 )) , (const struct ea *)ea0 , (const struct
# 1189 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
__3nx = __3nx -> __O1__4name.n_hidden ;
} }
if (__3nx == 0 ){ 
# 1202 "/home/claude/cfront-3/src/norm.cpp"
Pktab __4otbl ;
Pclass __4occl ;

# 1202 "/home/claude/cfront-3/src/norm.cpp"
__4otbl = Ctbl ;
__4occl = ccl ;
if ((Ctbl -> k_id__6ktable != 6 )&& (Ctbl -> k_id__6ktable != 185 ))
# 1205 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1205 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V182 ;

# 1205 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"friend%n not inC", (const struct ea *)( ((& __0__V182 )-> __O1__2ea.p =
# 1205 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__0this )), (& __0__V182 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1205 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} Ctbl = Gtbl ;
__0this -> lex_level__4name = 0 ;
ccl = 0 ;

# 1216 "/home/claude/cfront-3/src/norm.cpp"
__3nx = tname__4nameFUc ( __0this , (unsigned char )6 ) ;
Ctbl = __4otbl ;
ccl = __4occl ;
}
if (__3nx -> n_key__4name == 159 )
# 1221 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1221 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V183 ;

# 1221 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"friend%n referring to hiddenTN", (const struct ea *)( ((&
# 1221 "/home/claude/cfront-3/src/norm.cpp"
__0__V183 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V183 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1221 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} 
# 1224 "/home/claude/cfront-3/src/norm.cpp"
__0this -> n_sto__4name = 18 ;
__0this -> __O1__4expr.tp = __3nx -> __O1__4expr.tp ;
return __0this ;

# 1226 "/home/claude/cfront-3/src/norm.cpp"
}
}
}
if ((__0this -> __O1__4expr.tp && (__0this -> __O1__4expr.tp -> base__4node == 108 ))&& ((__0this -> n_oper__4name == 123 )|| (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))->
# 1229 "/home/claude/cfront-3/src/norm.cpp"
returns__3fct ))
# 1231 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1232 "/home/claude/cfront-3/src/norm.cpp"
Pfct __2f ;
Pfct __2f2 ;

# 1232 "/home/claude/cfront-3/src/norm.cpp"
__2f = (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))));
__2f2 = (((struct fct *)(((struct fct *)__2f -> returns__3fct ))));

# 1235 "/home/claude/cfront-3/src/norm.cpp"
if (__2f2 ){ 
# 1236 "/home/claude/cfront-3/src/norm.cpp"
Ptype __3pt ;
Ptype __3t ;

# 1237 "/home/claude/cfront-3/src/norm.cpp"
__3t = (struct type *)__2f2 ;
lxlx :
# 1239 "/home/claude/cfront-3/src/norm.cpp"
switch (__3t -> base__4node ){ 
# 1240 "/home/claude/cfront-3/src/norm.cpp"
case 158 :
# 1241 "/home/claude/cfront-3/src/norm.cpp"
case 125 :
# 1242 "/home/claude/cfront-3/src/norm.cpp"
case 110 :
# 1243 "/home/claude/cfront-3/src/norm.cpp"
if (__3pt = (((struct ptr *)(((struct ptr *)__3t ))))-> typ__5pvtyp ){ 
# 1244 "/home/claude/cfront-3/src/norm.cpp"
if (__3pt ->
# 1244 "/home/claude/cfront-3/src/norm.cpp"
base__4node == 97 ){ 
# 1245 "/home/claude/cfront-3/src/norm.cpp"
(((struct ptr *)(((struct ptr *)__3t ))))-> typ__5pvtyp = 0 ;
__1b = (((struct basetype *)(((struct basetype *)__3pt ))));
}
else { 
# 1249 "/home/claude/cfront-3/src/norm.cpp"
__3t = __3pt ;
goto lxlx ;
}
}
goto zse1 ;
case 108 :
# 1255 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1256 "/home/claude/cfront-3/src/norm.cpp"
Pexpr __5e ;

# 1256 "/home/claude/cfront-3/src/norm.cpp"
__5e = (struct expr *)(((struct fct *)(((struct fct *)__2f ))))-> argtype__3fct ;
if (__5e && (__5e -> base__4node == 140 )){ 
# 1258 "/home/claude/cfront-3/src/norm.cpp"
if (__5e -> __O3__4expr.e2 || (__5e -> __O2__4expr.e1 -> base__4node != 111 ))goto zse1 ;
{ Pexpr __6ee ;
Ptype __6t ;
Ptype __6tpx ;

# 1259 "/home/claude/cfront-3/src/norm.cpp"
__6ee = __5e -> __O2__4expr.e1 ;
__6t = 0 ;

# 1262 "/home/claude/cfront-3/src/norm.cpp"
ldld :
# 1263 "/home/claude/cfront-3/src/norm.cpp"
switch (__6ee -> base__4node ){ 
# 1264 "/home/claude/cfront-3/src/norm.cpp"
case 111 :
# 1265 "/home/claude/cfront-3/src/norm.cpp"
{ Ptype __8tt ;

# 1265 "/home/claude/cfront-3/src/norm.cpp"
__8tt = (__6ee -> __O3__4expr.e2 ?(((struct type *)(((struct type *)__ct__3vecFP4typeP4expr ( (struct vec *)0 , (struct type *)0 , __6ee -> __O3__4expr.e2 ) )))):(((struct type *)(((struct type *)__ct__3ptrFUcP4type (
# 1265 "/home/claude/cfront-3/src/norm.cpp"
(struct ptr *)0 , (unsigned char )125 , (struct type *)0 ) )))));
if (__6t )
# 1267 "/home/claude/cfront-3/src/norm.cpp"
(((struct ptr *)(((struct ptr *)__6t ))))-> typ__5pvtyp = __8tt ;
else 
# 1269 "/home/claude/cfront-3/src/norm.cpp"
__6tpx = __8tt ;
__6t = __8tt ;
__6ee = __6ee -> __O2__4expr.e1 ;
goto ldld ;
}
case 85 :
# 1275 "/home/claude/cfront-3/src/norm.cpp"
{ Pname __8rn ;

# 1275 "/home/claude/cfront-3/src/norm.cpp"
__8rn = (((struct name *)(((struct name *)__6ee ))));
{ Pname __9btn ;

# 1276 "/home/claude/cfront-3/src/norm.cpp"
__9btn = k_find_name__FPCcP6ktableUc ( __0this -> __O2__4expr.string , Ctbl , (unsigned char )0 ) ;
if (__9btn && (__9btn -> base__4node == 85 ))__9btn = 0 ;
__1b = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )97 , __9btn ) ;
}
__2f -> returns__3fct = __6tpx ;
__0this -> n_oper__4name = 0 ;
__0this -> __O2__4expr.string = __8rn -> __O2__4expr.string ;
__0this -> base__4node = 85 ;
}
}

# 1285 "/home/claude/cfront-3/src/norm.cpp"
}
}
}
}
}
}

# 1292 "/home/claude/cfront-3/src/norm.cpp"
zse1 :
# 1293 "/home/claude/cfront-3/src/norm.cpp"
if (__1b == 0 ){ 
# 1293 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X203 ;

# 1294 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1294 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V184 ;

# 1294 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"BTX for %s", (const struct ea *)( (__2__X203 = (const void
# 1294 "/home/claude/cfront-3/src/norm.cpp"
*)__0this -> __O2__4expr.string ), ( ((& __0__V184 )-> __O1__2ea.p = __2__X203 ), (& __0__V184 )) ) , (const struct ea *)ea0 ,
# 1294 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1b = (((struct basetype *)(((struct basetype *)defa_type ))));
} }

# 1298 "/home/claude/cfront-3/src/norm.cpp"
if (__1Cast )__0this -> __O2__4expr.string = (const char *)"";
__1b = check__8basetypeFP4name ( __1b , __0this ) ;

# 1301 "/home/claude/cfront-3/src/norm.cpp"
switch (__1b -> base__4node ){ 
# 1303 "/home/claude/cfront-3/src/norm.cpp"
case 119 :
# 1304 "/home/claude/cfront-3/src/norm.cpp"
__1nn = __1b -> b_name__8basetype ;
if ((! __1Cast )&& ((((struct classdef *)(((struct classdef *)__1nn -> __O1__4expr.tp ))))-> c_body__8classdef == 2 )){ 
# 1308 "/home/claude/cfront-3/src/norm.cpp"
if (__1stc == 18 ){ 
# 1309 "/home/claude/cfront-3/src/norm.cpp"
Pclass __4cl ;

# 1310 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X204 ;

# 1309 "/home/claude/cfront-3/src/norm.cpp"
__4cl = (((struct classdef *)(((struct classdef *)__1nn -> __O1__4expr.tp ))));
if (__4cl -> csu__8classdef == 167 )
# 1311 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"friend anonymous union",
# 1311 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
else 
# 1313 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1313 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V185 ;

# 1313 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V186 ;

# 1313 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"%k%n defined in friendD", (const struct ea *)(
# 1313 "/home/claude/cfront-3/src/norm.cpp"
(__2__X204 = __4cl -> csu__8classdef ), ( (( ((& __0__V185 )-> __O1__2ea.i = __2__X204 ), 0 ) ), (& __0__V185 )) )
# 1313 "/home/claude/cfront-3/src/norm.cpp"
, (const struct ea *)( ((& __0__V186 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V186 )) , (const
# 1313 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
if ((__0this -> __O1__4expr.tp && (__0this -> __O1__4expr.tp -> base__4node == 108 ))&& (co_hack == 0 )){ 
# 1315 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X205 ;

# 1316 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1316 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V187 ;

# 1316 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V188 ;

# 1316 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V189 ;

# 1316 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"%k%n defined as returnT for%n (did you forget a ';' after '}' ?)", (const struct ea *)(
# 1316 "/home/claude/cfront-3/src/norm.cpp"
(__2__X205 = (((struct classdef *)(((struct classdef *)__1nn -> __O1__4expr.tp ))))-> csu__8classdef ), ( (( ((& __0__V187 )-> __O1__2ea.i = __2__X205 ), 0 ) ),
# 1316 "/home/claude/cfront-3/src/norm.cpp"
(& __0__V187 )) ) , (const struct ea *)( ((& __0__V188 )-> __O1__2ea.p = ((const void *)__1nn )), (&
# 1316 "/home/claude/cfront-3/src/norm.cpp"
__0__V188 )) , (const struct ea *)( ((& __0__V189 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V189 )) ,
# 1316 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
__1nn = __0this ;
break ;
} }
__1nn -> __O1__4name.n_list = __0this ;
(((struct classdef *)(((struct classdef *)__1nn -> __O1__4expr.tp ))))-> c_body__8classdef = 1 ;
}
else 
# 1324 "/home/claude/cfront-3/src/norm.cpp"
__1nn = __0this ;
break ;
case 121 :
# 1327 "/home/claude/cfront-3/src/norm.cpp"
__1nn = __1b -> b_name__8basetype ;
if ((((struct enumdef *)(((struct enumdef *)__1nn -> __O1__4expr.tp ))))-> e_body__7enumdef == 2 ){ 
# 1329 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> __O1__4expr.tp && (__0this -> __O1__4expr.tp -> base__4node == 108 )){
# 1329 "/home/claude/cfront-3/src/norm.cpp"

# 1330 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1330 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V190 ;

# 1330 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V191 ;

# 1330 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4name , (const char *)"enum%n defined as returnT for%n (did you forget a ';'?)", (const struct ea *)(
# 1330 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V190 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V190 )) , (const struct ea *)( ((& __0__V191 )->
# 1330 "/home/claude/cfront-3/src/norm.cpp"
__O1__2ea.p = ((const void *)__0this )), (& __0__V191 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 1330 "/home/claude/cfront-3/src/norm.cpp"

# 1331 "/home/claude/cfront-3/src/norm.cpp"
__1nn = __0this ;
break ;
} }
__1nn -> __O1__4name.n_list = __0this ;
(((struct enumdef *)(((struct enumdef *)__1nn -> __O1__4expr.tp ))))-> e_body__7enumdef = 1 ;
}
else { 
# 1338 "/home/claude/cfront-3/src/norm.cpp"
Penum __3en ;

# 1338 "/home/claude/cfront-3/src/norm.cpp"
__3en = (((struct enumdef *)(((struct enumdef *)__1nn -> __O1__4expr.tp ))));
if (__3en -> defined__4type == 0 )
# 1340 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1340 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V192 ;

# 1340 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"forwardD of enum%n", (const struct ea *)( ((& __0__V192 )-> __O1__2ea.p =
# 1340 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1nn )), (& __0__V192 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1340 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} __3en -> e_type__7enumdef = int_type ;
__1nn = __0this ;
}
break ;
default :
# 1346 "/home/claude/cfront-3/src/norm.cpp"
__1nn = __0this ;
}

# 1350 "/home/claude/cfront-3/src/norm.cpp"
{ Pname __1nx ;
Ptype __1btyp ;

# 1353 "/home/claude/cfront-3/src/norm.cpp"
if ((__1b -> base__4node == 97 )&& __1b -> b_const__4type )
# 1354 "/home/claude/cfront-3/src/norm.cpp"
__1btyp = mkconst__4typeFv ( (struct type *)__1b ) ;
else 
# 1356 "/home/claude/cfront-3/src/norm.cpp"
__1btyp = (struct type *)__1b ;

# 1358 "/home/claude/cfront-3/src/norm.cpp"
for(__1n = __0this ;__1n ;__1n = __1nx ) { 
# 1359 "/home/claude/cfront-3/src/norm.cpp"
Ptype __2t ;

# 1359 "/home/claude/cfront-3/src/norm.cpp"
__2t = __1n -> __O1__4expr.tp ;
__1nx = __1n -> __O1__4name.n_list ;
__1n -> n_sto__4name = __1stc ;

# 1363 "/home/claude/cfront-3/src/norm.cpp"
if (__1n -> base__4node == 123 ){ 
# 1363 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V193 ;

# 1363 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"redefinition ofTN%n", (const struct ea *)( ((&
# 1363 "/home/claude/cfront-3/src/norm.cpp"
__0__V193 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V193 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1363 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} 
# 1365 "/home/claude/cfront-3/src/norm.cpp"
if (__2t == 0 ){ 
# 1366 "/home/claude/cfront-3/src/norm.cpp"
if (__1bl == 0 ){ 
# 1367 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O1__4expr.tp = (__2t = __1btyp );
goto skipp ;
}
else { 
# 1371 "/home/claude/cfront-3/src/norm.cpp"
if ((__1n -> base__4node == 85 )&& __1n -> n_oper__4name )
# 1372 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1372 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V194 ;

# 1372 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1n -> where__4name , (const char *)"illegalD of%n", (const struct ea *)(
# 1372 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V194 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V194 )) , (const struct ea *)ea0 , (const struct
# 1372 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 1374 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1374 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V195 ;

# 1374 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1n -> where__4name , (const char *)"body of nonF%n", (const struct ea *)(
# 1374 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V195 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V195 )) , (const struct ea *)ea0 , (const struct
# 1374 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} __2t = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)0 , (struct name *)0 , (unsigned char )0 ) ;
# 1375 "/home/claude/cfront-3/src/norm.cpp"

# 1376 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 1379 "/home/claude/cfront-3/src/norm.cpp"
switch (__2t -> base__4node ){ 
# 1380 "/home/claude/cfront-3/src/norm.cpp"
case 125 :
# 1381 "/home/claude/cfront-3/src/norm.cpp"
case 158 :
# 1382 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O1__4expr.tp = normalize__3ptrFP4type ( ((struct ptr *)(((struct ptr *)__2t ))), __1btyp ) ;
break ;
case 110 :
# 1385 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O1__4expr.tp = normalize__3vecFP4type ( ((struct vec *)(((struct vec *)__2t ))), __1btyp ) ;
break ;
case 108 :
# 1388 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O1__4expr.tp = normalize__3fctFP4type ( ((struct fct *)(((struct fct *)__2t ))), __1btyp ) ;
break ;
case 114 :
# 1391 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1392 "/home/claude/cfront-3/src/norm.cpp"
if (__1n -> __O2__4expr.string == 0 )__1n -> __O2__4expr.string = (const char *)make_name__FUc ( (unsigned char )'F' ) ;
# 1392 "/home/claude/cfront-3/src/norm.cpp"

# 1393 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O1__4expr.tp = __2t ;

# 1395 "/home/claude/cfront-3/src/norm.cpp"
{ bit __4cft ;
Ptype __4tb ;

# 1395 "/home/claude/cfront-3/src/norm.cpp"
__4cft = 0 ;
__4tb = skiptypedefs__4typeFRUc ( __1btyp , (bit *)(& __4cft )) ;

# 1398 "/home/claude/cfront-3/src/norm.cpp"
switch (__4tb -> base__4node ){ 
# 1399 "/home/claude/cfront-3/src/norm.cpp"
case 5 :
# 1400 "/home/claude/cfront-3/src/norm.cpp"
case 29 :
# 1401 "/home/claude/cfront-3/src/norm.cpp"
case 22 :
# 1402 "/home/claude/cfront-3/src/norm.cpp"
case 122 :
# 1403 "/home/claude/cfront-3/src/norm.cpp"
case 121 :
# 1404 "/home/claude/cfront-3/src/norm.cpp"
case 21 :
# 1408 "/home/claude/cfront-3/src/norm.cpp"
(((struct basetype *)(((struct basetype *)__2t ))))-> __O1__8basetype.b_fieldtype = (struct
# 1408 "/home/claude/cfront-3/src/norm.cpp"
type *)((((struct basetype *)(((struct basetype *)__4tb ))))-> b_unsigned__8basetype ?uint_type :int_type );
(((struct basetype *)(((struct basetype *)__2t ))))-> b_unsigned__8basetype = (((struct basetype *)(((struct basetype *)__4tb ))))-> b_unsigned__8basetype ;
(((struct basetype *)(((struct basetype *)__2t ))))-> b_const__4type = __4cft ;
break ;
case 141 :
# 1414 "/home/claude/cfront-3/src/norm.cpp"
if (in_progress__17templ_compilation )
# 1415 "/home/claude/cfront-3/src/norm.cpp"
(((struct basetype *)(((struct basetype *)__2t ))))-> __O1__8basetype.b_fieldtype = (struct type *)int_type ;
break ;
default :
# 1418 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"non-int field") ;
__1n -> __O1__4expr.tp = (struct type *)defa_type ;
}
break ;

# 1421 "/home/claude/cfront-3/src/norm.cpp"
}
}
}
skipp :
# 1426 "/home/claude/cfront-3/src/norm.cpp"
{ Pfct __2f ;

# 1426 "/home/claude/cfront-3/src/norm.cpp"
__2f = (((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))));

# 1428 "/home/claude/cfront-3/src/norm.cpp"
if (__2f -> base__4node != 108 ){ 
# 1429 "/home/claude/cfront-3/src/norm.cpp"
if (__1bl ){ 
# 1430 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1430 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V196 ;

# 1430 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"body for nonF%n", (const struct ea *)( ((& __0__V196 )-> __O1__2ea.p =
# 1430 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1n )), (& __0__V196 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1430 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
__1n -> __O1__4expr.tp = (struct type *)(__2f = __ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)defa_type , (struct name *)0 , (unsigned char )0 )
# 1431 "/home/claude/cfront-3/src/norm.cpp"
);
continue ;
} }
if (__1inli ){ 
# 1434 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V197 ;

# 1434 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"inline nonF%n", (const struct ea *)( ((& __0__V197 )-> __O1__2ea.p =
# 1434 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1n )), (& __0__V197 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1434 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} if (__1virt ){ 
# 1435 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V198 ;

# 1435 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"virtual nonF%n", (const struct ea *)( ((& __0__V198 )-> __O1__2ea.p =
# 1435 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1n )), (& __0__V198 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1435 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} 
# 1437 "/home/claude/cfront-3/src/norm.cpp"
if (__1tpdf ){ 
# 1439 "/home/claude/cfront-3/src/norm.cpp"
if (in_arg_list ){ 
# 1440 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"Tdef inA list") ;
# 1440 "/home/claude/cfront-3/src/norm.cpp"

# 1441 "/home/claude/cfront-3/src/norm.cpp"
continue ;
}

# 1444 "/home/claude/cfront-3/src/norm.cpp"
if (__1n -> __O3__4expr.n_initializer ){ 
# 1445 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1445 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V199 ;

# 1445 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"Ir forTdefN%n", (const struct ea *)( ((& __0__V199 )-> __O1__2ea.p =
# 1445 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1n )), (& __0__V199 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1445 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
__1n -> __O3__4expr.n_initializer = 0 ;
} }
tdef__4nameFv ( __1n ) ;

# 1451 "/home/claude/cfront-3/src/norm.cpp"
}
continue ;
}

# 1455 "/home/claude/cfront-3/src/norm.cpp"
if (__1lnkg )set_linkage__FPCc ( __1lnkg ) ;
__2f -> f_linkage__3fct = linkage ;
if (__1lnkg )set_linkage__FPCc ( (const char *)0 ) ;

# 1460 "/home/claude/cfront-3/src/norm.cpp"
{ extern int inline_opt ;
if (inline_opt )
# 1462 "/home/claude/cfront-3/src/norm.cpp"
__2f -> f_inline__3fct = ((__1bl && strcmp ( __1n -> __O2__4expr.string , (const char *)"main")
# 1462 "/home/claude/cfront-3/src/norm.cpp"
)?1 :0 );
else 
# 1464 "/home/claude/cfront-3/src/norm.cpp"
__2f -> f_inline__3fct = __1inli ;

# 1466 "/home/claude/cfront-3/src/norm.cpp"
__2f -> f_is_inline__3fct = __2f -> f_inline__3fct ;
{ extern int vcounter ;
__2f -> f_virtual__3fct = (__1virt ?( (vcounter ++ ), 22222 ) :0 );

# 1470 "/home/claude/cfront-3/src/norm.cpp"
if (__1tpdf ){ 
# 1471 "/home/claude/cfront-3/src/norm.cpp"
if (__2f -> body__3fct = __1bl ){ 
# 1472 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1472 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V200 ;

# 1472 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"Tdef%n { ... }", (const struct ea *)( ((& __0__V200 )-> __O1__2ea.p =
# 1472 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1n )), (& __0__V200 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1472 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
__2f -> body__3fct = (__1bl = 0 );
} }
if (__1n -> __O2__4name.n_qualifier ){ 
# 1479 "/home/claude/cfront-3/src/norm.cpp"
__2f -> memof__3fct = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1n -> __O2__4name.n_qualifier -> __O1__4expr.tp ))))-> b_name__8basetype ->
# 1479 "/home/claude/cfront-3/src/norm.cpp"
__O1__4expr.tp ))));
__1n -> __O2__4name.n_qualifier = 0 ;
}
tdef__4nameFv ( __1n ) ;

# 1485 "/home/claude/cfront-3/src/norm.cpp"
continue ;
}

# 1488 "/home/claude/cfront-3/src/norm.cpp"
if (__2f -> body__3fct = __1bl )continue ;

# 1498 "/home/claude/cfront-3/src/norm.cpp"
{ Pname __3cn ;
Ptype __3template_formal_type ;
bit __3clob ;

# 1498 "/home/claude/cfront-3/src/norm.cpp"
__3cn = is_cl_obj__4typeFv ( __2f -> returns__3fct ) ;

# 1500 "/home/claude/cfront-3/src/norm.cpp"
__3clob = (__3cn || cl_obj_vec );

# 1502 "/home/claude/cfront-3/src/norm.cpp"
if (__2f -> argtype__3fct ){ 
# 1503 "/home/claude/cfront-3/src/norm.cpp"
Pname __4nn ;

# 1505 "/home/claude/cfront-3/src/norm.cpp"
for(__4nn = __2f -> argtype__3fct ;__4nn ;__4nn = __4nn -> __O1__4name.n_list ) { 
# 1506 "/home/claude/cfront-3/src/norm.cpp"
if (__4nn -> base__4node != 85 ){ 
# 1507 "/home/claude/cfront-3/src/norm.cpp"
if (! __3clob ){ 
# 1508 "/home/claude/cfront-3/src/norm.cpp"
if
# 1508 "/home/claude/cfront-3/src/norm.cpp"
((__2f -> returns__3fct -> base__4node == 97 )&& ((((struct basetype *)(((struct basetype *)__2f -> returns__3fct ))))-> b_name__8basetype -> n_template_arg__4name == 1))
# 1510 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1511 "/home/claude/cfront-3/src/norm.cpp"
__3template_formal_type = __2f -> returns__3fct ;
# 1511 "/home/claude/cfront-3/src/norm.cpp"

# 1512 "/home/claude/cfront-3/src/norm.cpp"
goto is_obj ;
}

# 1515 "/home/claude/cfront-3/src/norm.cpp"
goto zzz ;
}
goto is_obj ;
}
if (__4nn -> __O1__4expr.tp )goto ok ;
}
if (! __3clob ){ 
# 1523 "/home/claude/cfront-3/src/norm.cpp"
goto zzz ;
}
is_obj :
# 1527 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O1__4expr.tp = __2f -> returns__3fct ;
if (__2f -> argtype__3fct -> base__4node != 140 )__2f -> f_args__3fct = (__2f -> argtype__3fct = (((struct name *)(((struct name *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned
# 1528 "/home/claude/cfront-3/src/norm.cpp"
char )140 , ((struct expr *)(((struct expr *)__2f -> argtype__3fct ))), (struct expr *)0 ) )))));
if (__1n -> __O3__4expr.n_initializer ){ 
# 1530 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1530 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V201 ;

# 1530 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1n -> where__4name , (const char *)"twoIrs for%n", (const struct ea *)(
# 1530 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V201 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V201 )) , (const struct ea *)ea0 , (const struct
# 1530 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
if ((((struct expr *)(((struct expr *)__2f -> argtype__3fct ))))&& ((((struct expr *)(((struct expr *)__2f -> argtype__3fct ))))-> permanent__4node == 0 ))del__4exprFv ( ((struct expr *)(((struct expr *)__2f ->
# 1531 "/home/claude/cfront-3/src/norm.cpp"
argtype__3fct )))) ;
__2f -> argtype__3fct = 0 ;
} }
else 
# 1533 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1533 "/home/claude/cfront-3/src/norm.cpp"
struct texpr *__0__X206 ;

# 1533 "/home/claude/cfront-3/src/norm.cpp"
struct type *__2__X207 ;

# 1533 "/home/claude/cfront-3/src/norm.cpp"
struct expr *__2__X208 ;

# 1534 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O3__4expr.n_initializer = (struct expr *)( (__0__X206 = 0 ), ( (__2__X207 = (__3cn ?__3cn -> __O1__4expr.tp :__3template_formal_type )), ( (__2__X208 = (((struct expr *)(((struct
# 1534 "/home/claude/cfront-3/src/norm.cpp"
expr *)__2f -> argtype__3fct ))))), ( ((__0__X206 || (__0__X206 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X206 = (struct
# 1534 "/home/claude/cfront-3/src/norm.cpp"
texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X206 ), ((unsigned char )157 ), __2__X208 , (struct expr *)0 ) ), (__0__X206 -> __O4__4expr.tp2 = __2__X207 )) :0 ),
# 1534 "/home/claude/cfront-3/src/norm.cpp"
__0__X206 ) ) ) ) ;
}
goto ok ;
zzz :
# 1539 "/home/claude/cfront-3/src/norm.cpp"
if (__2f -> argtype__3fct ){ 
# 1540 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O1__4expr.tp = __2f -> returns__3fct ;
if (__2f -> argtype__3fct -> base__4node == 140 ){ 
# 1542 "/home/claude/cfront-3/src/norm.cpp"
if (__2f -> argtype__3fct -> __O3__4expr.e2 == 0 ){ 
# 1544 "/home/claude/cfront-3/src/norm.cpp"
__2f -> argtype__3fct = (((struct name *)(((struct
# 1544 "/home/claude/cfront-3/src/norm.cpp"
name *)__2f -> argtype__3fct -> __O2__4expr.e1 ))));
}
else 
# 1545 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1546 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"more than oneA for basicTIr") ;
{ Pexpr __7e ;

# 1547 "/home/claude/cfront-3/src/norm.cpp"
__7e = (struct expr *)__2f -> argtype__3fct ;
for(;__7e -> __O3__4expr.e2 -> __O3__4expr.e2 ;__7e = __7e -> __O3__4expr.e2 ) 
# 1549 "/home/claude/cfront-3/src/norm.cpp"
__7e -> base__4node = 71 ;
__7e -> base__4node = 71 ;
__7e -> __O3__4expr.e2 = __7e -> __O3__4expr.e2 -> __O2__4expr.e1 ;

# 1551 "/home/claude/cfront-3/src/norm.cpp"
}
}
}
if (__1n -> __O3__4expr.n_initializer ){ 
# 1555 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1555 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V202 ;

# 1555 "/home/claude/cfront-3/src/norm.cpp"
error__FP3locPCcRC2eaN33 ( & __1n -> where__4name , (const char *)"twoIrs for%n", (const struct ea *)(
# 1555 "/home/claude/cfront-3/src/norm.cpp"
((& __0__V202 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V202 )) , (const struct ea *)ea0 , (const struct
# 1555 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
if ((((struct expr *)(((struct expr *)__2f -> argtype__3fct ))))&& ((((struct expr *)(((struct expr *)__2f -> argtype__3fct ))))-> permanent__4node == 0 ))del__4exprFv ( ((struct expr *)(((struct expr *)__2f ->
# 1556 "/home/claude/cfront-3/src/norm.cpp"
argtype__3fct )))) ;
__2f -> argtype__3fct = 0 ;
} }
else 
# 1558 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1559 "/home/claude/cfront-3/src/norm.cpp"
__1n -> __O3__4expr.n_initializer = (((struct expr *)(((struct expr *)__2f -> argtype__3fct ))));
}
goto ok ;
}
}
else { 
# 1571 "/home/claude/cfront-3/src/norm.cpp"
}
ok :
# 1573 "/home/claude/cfront-3/src/norm.cpp"
;
}

# 1574 "/home/claude/cfront-3/src/norm.cpp"
}

# 1574 "/home/claude/cfront-3/src/norm.cpp"
}

# 1574 "/home/claude/cfront-3/src/norm.cpp"
}
}
return __1nn ;

# 1576 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 1579 "/home/claude/cfront-3/src/norm.cpp"
Ptype normalize__3vecFP4type (register struct vec *__0this , Ptype __1vecof )
# 1580 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1581 "/home/claude/cfront-3/src/norm.cpp"
Ptype __1t ;

# 1581 "/home/claude/cfront-3/src/norm.cpp"
__1t = __0this -> typ__5pvtyp ;
__0this -> typ__5pvtyp = __1vecof ;

# 1584 "/home/claude/cfront-3/src/norm.cpp"
while (__1vecof -> base__4node == 97 )
# 1585 "/home/claude/cfront-3/src/norm.cpp"
__1vecof = (((struct basetype *)(((struct basetype *)__1vecof ))))-> b_name__8basetype -> __O1__4expr.tp ;

# 1587 "/home/claude/cfront-3/src/norm.cpp"
switch (__1vecof -> base__4node ){ 
# 1588 "/home/claude/cfront-3/src/norm.cpp"
case 158 :
# 1589 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"array ofRs") ;
break ;
case 108 :
# 1592 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"array ofFs") ;
break ;
case 38 :
# 1595 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"array of void") ;
break ;
default :
# 1598 "/home/claude/cfront-3/src/norm.cpp"
break ;
}

# 1601 "/home/claude/cfront-3/src/norm.cpp"
if (__1t == 0 )return (struct type *)__0this ;

# 1603 "/home/claude/cfront-3/src/norm.cpp"
switch (__1t -> base__4node ){ 
# 1603 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X210 ;

# 1604 "/home/claude/cfront-3/src/norm.cpp"
case 125 :
# 1605 "/home/claude/cfront-3/src/norm.cpp"
case 158 :return normalize__3ptrFP4type ( ((struct ptr *)(((struct ptr *)__1t ))), (struct type *)__0this ) ;
case 110 :return normalize__3vecFP4type ( ((struct vec *)(((struct vec *)__1t ))), (struct type *)__0this ) ;
case 108 :return normalize__3fctFP4type ( ((struct fct *)(((struct fct *)__1t ))), (struct type *)__0this ) ;
default :{ 
# 1608 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V209 ;

# 1608 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"bad arrayT(%d)", (const struct ea *)( (__2__X210 =
# 1608 "/home/claude/cfront-3/src/norm.cpp"
__1t -> base__4node ), ( (( ((& __0__V209 )-> __O1__2ea.i = __2__X210 ), 0 ) ), (& __0__V209 )) ) ,
# 1608 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 1608 "/home/claude/cfront-3/src/norm.cpp"
return (struct type *)0 ;
} }

# 1611 "/home/claude/cfront-3/src/norm.cpp"
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 706 "/home/claude/cfront-3/src/cfront.h"

# 712 "/home/claude/cfront-3/src/cfront.h"

# 706 "/home/claude/cfront-3/src/cfront.h"

# 712 "/home/claude/cfront-3/src/cfront.h"

# 706 "/home/claude/cfront-3/src/cfront.h"

# 712 "/home/claude/cfront-3/src/cfront.h"

# 1613 "/home/claude/cfront-3/src/norm.cpp"
Ptype normalize__3ptrFP4type (register struct ptr *__0this , Ptype __1ptrto )
# 1614 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1616 "/home/claude/cfront-3/src/norm.cpp"
Ptype __1t ;

# 1616 "/home/claude/cfront-3/src/norm.cpp"
__1t = __0this -> typ__5pvtyp ;
__0this -> typ__5pvtyp = __1ptrto ;

# 1619 "/home/claude/cfront-3/src/norm.cpp"
{ int __1bc ;

# 1619 "/home/claude/cfront-3/src/norm.cpp"
__1bc = 0 ;
while (__1ptrto -> base__4node == 97 ){ 
# 1621 "/home/claude/cfront-3/src/norm.cpp"
__1bc += (((struct basetype *)(((struct basetype *)__1ptrto ))))-> b_const__4type ;
__1ptrto = (((struct basetype *)(((struct basetype *)__1ptrto ))))-> b_name__8basetype -> __O1__4expr.tp ;
}

# 1625 "/home/claude/cfront-3/src/norm.cpp"
switch (__1ptrto -> base__4node ){ 
# 1626 "/home/claude/cfront-3/src/norm.cpp"
case 108 :
# 1627 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> memof__3ptr )
# 1628 "/home/claude/cfront-3/src/norm.cpp"
if ((((struct fct *)(((struct fct *)__1ptrto ))))-> memof__3fct ){ 
# 1628 "/home/claude/cfront-3/src/norm.cpp"
struct classdef *__1__X214 ;

# 1628 "/home/claude/cfront-3/src/norm.cpp"
struct classdef *__1__X215 ;

# 1628 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X216 ;

# 1629 "/home/claude/cfront-3/src/norm.cpp"
if (! ( (__1__X214 = __0this -> memof__3ptr ), ( (__1__X215 = (((struct fct *)(((struct fct *)__1ptrto ))))-> memof__3fct ), ( ((__1__X214 ==
# 1629 "/home/claude/cfront-3/src/norm.cpp"
__1__X215 )?1 :((__1__X214 && __1__X215 )?(((int )same_class__8classdefFP8classdefi ( __1__X214 , __1__X215 , 0 ) )):0 ))) ) ) ){ 
# 1629 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V211 ;

# 1629 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V212 ;

# 1629 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"P toMF mismatch: %s and %s", (const struct ea *)( (__2__X216 = (const void
# 1629 "/home/claude/cfront-3/src/norm.cpp"
*)__0this -> memof__3ptr -> string__8classdef ), ( ((& __0__V211 )-> __O1__2ea.p = __2__X216 ), (& __0__V211 )) ) , (const struct
# 1629 "/home/claude/cfront-3/src/norm.cpp"
ea *)__ct__2eaFPCv ( & __0__V212 , (const void *)(((struct fct *)(((struct fct *)__1ptrto ))))-> memof__3fct -> string__8classdef ) , (const struct ea *)ea0 ,
# 1629 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} }
else 
# 1632 "/home/claude/cfront-3/src/norm.cpp"
(((struct fct *)(((struct fct *)__1ptrto ))))-> memof__3fct = __0this -> memof__3ptr ;
else 
# 1634 "/home/claude/cfront-3/src/norm.cpp"
__0this -> memof__3ptr = (((struct fct *)(((struct fct *)__1ptrto ))))-> memof__3fct ;
break ;
case 158 :
# 1637 "/home/claude/cfront-3/src/norm.cpp"
switch (__0this -> base__4node ){ 
# 1638 "/home/claude/cfront-3/src/norm.cpp"
case 125 :error__FPCc ( (const char *)"P toR") ;
# 1638 "/home/claude/cfront-3/src/norm.cpp"
break ;
case 158 :error__FPCc ( (const char *)"R toR") ;

# 1639 "/home/claude/cfront-3/src/norm.cpp"
break ;
}
break ;
case 38 :
# 1643 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> base__4node == 158 )
# 1644 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"R to void") ;
break ;
}

# 1648 "/home/claude/cfront-3/src/norm.cpp"
if (__1t == 0 ){ 
# 1649 "/home/claude/cfront-3/src/norm.cpp"
Pbase __2b ;

# 1649 "/home/claude/cfront-3/src/norm.cpp"
__2b = (((struct basetype *)(((struct basetype *)__1ptrto ))));
if (((((((Pfctvec_type && (__0this -> b_const__4type == 0 ))&& (__2b -> b_unsigned__8basetype == 0 ))&& (__2b -> b_const__4type == 0 ))&& (__1bc == 0 ))&& (__0this ->
# 1650 "/home/claude/cfront-3/src/norm.cpp"
memof__3ptr == 0 ))&& (__0this -> ptname__3ptr == 0 ))&& (__0this -> base__4node == 125 ))
# 1656 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1657 "/home/claude/cfront-3/src/norm.cpp"
switch (__2b -> base__4node ){ 
# 1658 "/home/claude/cfront-3/src/norm.cpp"
case 21 :( (__0this ?(((void
# 1658 "/home/claude/cfront-3/src/norm.cpp"
)(__0this ?(((void )(((void )__dl__3ptrSFPvUl ( (void *)__0this , (size_t )(sizeof (struct ptr))) )))):(((void )0 ))))):(((void )0 )))) ;

# 1658 "/home/claude/cfront-3/src/norm.cpp"
return Pint_type ;
case 5 :( (__0this ?(((void )(__0this ?(((void )(((void )__dl__3ptrSFPvUl ( (void *)__0this , (size_t )(sizeof (struct ptr))) )))):(((void )0 ))))):(((void
# 1659 "/home/claude/cfront-3/src/norm.cpp"
)0 )))) ;

# 1659 "/home/claude/cfront-3/src/norm.cpp"
return Pchar_type ;
case 38 :( (__0this ?(((void )(__0this ?(((void )(((void )__dl__3ptrSFPvUl ( (void *)__0this , (size_t )(sizeof (struct ptr))) )))):(((void )0 ))))):(((void
# 1660 "/home/claude/cfront-3/src/norm.cpp"
)0 )))) ;

# 1660 "/home/claude/cfront-3/src/norm.cpp"
return Pvoid_type ;
}
}
return (struct type *)__0this ;
}

# 1666 "/home/claude/cfront-3/src/norm.cpp"
switch (__1t -> base__4node ){ 
# 1666 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X217 ;

# 1667 "/home/claude/cfront-3/src/norm.cpp"
case 125 :
# 1668 "/home/claude/cfront-3/src/norm.cpp"
case 158 :return normalize__3ptrFP4type ( ((struct ptr *)(((struct ptr *)__1t ))), (struct type *)__0this ) ;
case 110 :return normalize__3vecFP4type ( ((struct vec *)(((struct vec *)__1t ))), (struct type *)__0this ) ;
case 108 :return normalize__3fctFP4type ( ((struct fct *)(((struct fct *)__1t ))), (struct type *)__0this ) ;
default :{ 
# 1671 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V213 ;

# 1671 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"badPT(%k)", (const struct ea *)( (__2__X217 =
# 1671 "/home/claude/cfront-3/src/norm.cpp"
__1t -> base__4node ), ( (( ((& __0__V213 )-> __O1__2ea.i = __2__X217 ), 0 ) ), (& __0__V213 )) ) ,
# 1671 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 1671 "/home/claude/cfront-3/src/norm.cpp"
return (struct type *)0 ;
} }

# 1672 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 1675 "/home/claude/cfront-3/src/norm.cpp"
Ptype normalize__3fctFP4type (register struct fct *__0this , Ptype __1ret )
# 1679 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1681 "/home/claude/cfront-3/src/norm.cpp"
Ptype __1t ;

# 1681 "/home/claude/cfront-3/src/norm.cpp"
__1t = __0this -> returns__3fct ;
__0this -> returns__3fct = __1ret ;

# 1684 "/home/claude/cfront-3/src/norm.cpp"
if ((__0this -> argtype__3fct && (__0this -> argtype__3fct -> base__4node == 85 ))&& __0this -> argtype__3fct -> __O2__4name.n_qualifier ){ 
# 1685 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"syntax: ANX")
# 1685 "/home/claude/cfront-3/src/norm.cpp"
;
__0this -> argtype__3fct = 0 ;
__0this -> nargs__3fct = 0 ;
__0this -> nargs_known__3fct = 0 ;
}

# 1691 "/home/claude/cfront-3/src/norm.cpp"
while (__1ret -> base__4node == 97 )
# 1692 "/home/claude/cfront-3/src/norm.cpp"
__1ret = (((struct basetype *)(((struct basetype *)__1ret ))))-> b_name__8basetype -> __O1__4expr.tp ;

# 1694 "/home/claude/cfront-3/src/norm.cpp"
switch (__1ret -> base__4node ){ 
# 1695 "/home/claude/cfront-3/src/norm.cpp"
case 110 :
# 1696 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"F returning array") ;
break ;
case 108 :
# 1699 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"F returningF") ;

# 1701 "/home/claude/cfront-3/src/norm.cpp"
__0this -> returns__3fct = (__1ret = (struct type *)any_type );
break ;
default :
# 1704 "/home/claude/cfront-3/src/norm.cpp"
break ;
}

# 1707 "/home/claude/cfront-3/src/norm.cpp"
if (__1t == 0 )return (struct type *)__0this ;

# 1709 "/home/claude/cfront-3/src/norm.cpp"
switch (__1t -> base__4node ){ 
# 1709 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X219 ;

# 1710 "/home/claude/cfront-3/src/norm.cpp"
case 125 :
# 1711 "/home/claude/cfront-3/src/norm.cpp"
case 158 :return normalize__3ptrFP4type ( ((struct ptr *)(((struct ptr *)__1t ))), (struct type *)__0this ) ;
case 110 :return normalize__3vecFP4type ( ((struct vec *)(((struct vec *)__1t ))), (struct type *)__0this ) ;
case 108 :return normalize__3fctFP4type ( ((struct fct *)(((struct fct *)__1t ))), (struct type *)__0this ) ;
default :{ 
# 1714 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V218 ;

# 1714 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"badFT:%k", (const struct ea *)( (__2__X219 =
# 1714 "/home/claude/cfront-3/src/norm.cpp"
__1t -> base__4node ), ( (( ((& __0__V218 )-> __O1__2ea.i = __2__X219 ), 0 ) ), (& __0__V218 )) ) ,
# 1714 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 1714 "/home/claude/cfront-3/src/norm.cpp"
return (struct type *)0 ;
} }
}

# 1718 "/home/claude/cfront-3/src/norm.cpp"
void argdcl__3fctFP4nameT1 (register struct fct *__0this , Pname __1dcl , Pname __1fn )
# 1725 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1726 "/home/claude/cfront-3/src/norm.cpp"
Pname __1n ;

# 1728 "/home/claude/cfront-3/src/norm.cpp"
switch (__0this -> base__4node ){ 
# 1728 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X227 ;

# 1729 "/home/claude/cfront-3/src/norm.cpp"
case 108 :break ;
case 141 :return ;
default :{ 
# 1731 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V220 ;

# 1731 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"fct::argdcl(%d)", (const struct ea *)( (__2__X227 =
# 1731 "/home/claude/cfront-3/src/norm.cpp"
__0this -> base__4node ), ( (( ((& __0__V220 )-> __O1__2ea.i = __2__X227 ), 0 ) ), (& __0__V220 )) ) ,
# 1731 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1734 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> argtype__3fct ){ 
# 1735 "/home/claude/cfront-3/src/norm.cpp"
switch (__0this -> argtype__3fct -> base__4node ){ 
# 1735 "/home/claude/cfront-3/src/norm.cpp"
unsigned long __2__X228 ;

# 1736 "/home/claude/cfront-3/src/norm.cpp"
case 85 :
# 1737 "/home/claude/cfront-3/src/norm.cpp"
if (__1dcl )error__FPCc ( (const char *)"badF definition syntax") ;
for(__1n = __0this -> argtype__3fct ;__1n ;__1n = __1n -> __O1__4name.n_list ) { 
# 1739 "/home/claude/cfront-3/src/norm.cpp"
if (__1n -> __O2__4expr.string == 0 )__1n -> __O2__4expr.string = (const char *)make_name__FUc (
# 1739 "/home/claude/cfront-3/src/norm.cpp"
(unsigned char )'A' ) ;
}
return ;
case 140 :
# 1744 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1745 "/home/claude/cfront-3/src/norm.cpp"
Pname __4tail ;

# 1745 "/home/claude/cfront-3/src/norm.cpp"
__4tail = 0 ;
__1n = 0 ;

# 1748 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1748 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V221 ;

# 1748 "/home/claude/cfront-3/src/norm.cpp"
error__FiP3locPCcRC2eaN34 ( strict_opt ?0 :119, & __1fn -> where__4name , (const char *)"old style definition of%n (anachronism)", (const struct
# 1748 "/home/claude/cfront-3/src/norm.cpp"
ea *)( ((& __0__V221 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V221 )) , (const struct ea *)ea0 , (const
# 1748 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 1750 "/home/claude/cfront-3/src/norm.cpp"
{ { Pexpr __4e ;

# 1750 "/home/claude/cfront-3/src/norm.cpp"
__4e = (((struct expr *)(((struct expr *)__0this -> argtype__3fct ))));

# 1750 "/home/claude/cfront-3/src/norm.cpp"
for(;__4e ;__4e = __4e -> __O3__4expr.e2 ) { 
# 1751 "/home/claude/cfront-3/src/norm.cpp"
Pexpr __5id ;

# 1751 "/home/claude/cfront-3/src/norm.cpp"
__5id = __4e -> __O2__4expr.e1 ;
if (__5id -> base__4node != 85 ){ 
# 1753 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"NX inAL") ;
__0this -> argtype__3fct = 0 ;
__1dcl = 0 ;
break ;
}
{ Pname __5nn ;

# 1758 "/home/claude/cfront-3/src/norm.cpp"
__5nn = __ct__4nameFPCc ( (struct name *)0 , __5id -> __O2__4expr.string ) ;
if (__1n )
# 1760 "/home/claude/cfront-3/src/norm.cpp"
__4tail = (__4tail -> __O1__4name.n_list = __5nn );
else 
# 1762 "/home/claude/cfront-3/src/norm.cpp"
__4tail = (__1n = __5nn );

# 1762 "/home/claude/cfront-3/src/norm.cpp"
}
}
__0this -> f_args__3fct = (__0this -> argtype__3fct = __1n );
break ;

# 1765 "/home/claude/cfront-3/src/norm.cpp"
}

# 1765 "/home/claude/cfront-3/src/norm.cpp"
}
} }
default :
# 1768 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1768 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V222 ;

# 1768 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"ALX(%d)", (const struct ea *)( (__2__X228 = __0this -> argtype__3fct ->
# 1768 "/home/claude/cfront-3/src/norm.cpp"
base__4node ), ( (( ((& __0__V222 )-> __O1__2ea.i = __2__X228 ), 0 ) ), (& __0__V222 )) ) , (const
# 1768 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__0this -> argtype__3fct = 0 ;
__1dcl = 0 ;
} }
}
else if (__0this -> nargs_known__3fct == 155 ){ 
# 1774 "/home/claude/cfront-3/src/norm.cpp"
return ;
}
else { 
# 1777 "/home/claude/cfront-3/src/norm.cpp"
__0this -> nargs_known__3fct = 1 ;
__0this -> nargs__3fct = 0 ;
if (__1dcl )error__FPCc ( (const char *)"ADL forFWoutAs") ;
return ;
}

# 1785 "/home/claude/cfront-3/src/norm.cpp"
if (__1dcl ){ 
# 1786 "/home/claude/cfront-3/src/norm.cpp"
Pname __2d ;
Pname __2dx ;

# 1792 "/home/claude/cfront-3/src/norm.cpp"
for(__1n = __0this -> argtype__3fct ;__1n ;__1n = __1n -> __O1__4name.n_list ) { 
# 1793 "/home/claude/cfront-3/src/norm.cpp"
const char *__3s ;

# 1794 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X229 ;

# 1794 "/home/claude/cfront-3/src/norm.cpp"
const void *__2__X230 ;

# 1793 "/home/claude/cfront-3/src/norm.cpp"
__3s = __1n -> __O2__4expr.string ;
if (__3s == 0 ){ 
# 1795 "/home/claude/cfront-3/src/norm.cpp"
error__FPCc ( (const char *)"AN missing inF definition") ;
__1n -> __O2__4expr.string = (__3s = (const char *)make_name__FUc ( (unsigned char )'A' ) );
}
else if (__1n -> __O1__4expr.tp ){ 
# 1798 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V223 ;

# 1798 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoTs forA %s", (const struct ea *)( (__2__X229 = (const void
# 1798 "/home/claude/cfront-3/src/norm.cpp"
*)__1n -> __O2__4expr.string ), ( ((& __0__V223 )-> __O1__2ea.p = __2__X229 ), (& __0__V223 )) ) , (const struct ea *)ea0 ,
# 1798 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1800 "/home/claude/cfront-3/src/norm.cpp"
for(__2d = __1dcl ;__2d ;__2d = __2d -> __O1__4name.n_list ) { 
# 1801 "/home/claude/cfront-3/src/norm.cpp"
if (strcmp ( __3s , __2d -> __O2__4expr.string ) == 0 ){ 
# 1802 "/home/claude/cfront-3/src/norm.cpp"
if
# 1802 "/home/claude/cfront-3/src/norm.cpp"
(__2d -> __O1__4expr.tp && (__2d -> __O1__4expr.tp -> base__4node == 38 )){ 
# 1803 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1803 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V224 ;

# 1803 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"voidA%n", (const struct ea *)( ((& __0__V224 )-> __O1__2ea.p =
# 1803 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__2d )), (& __0__V224 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1803 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
__2d -> __O1__4expr.tp = (struct type *)any_type ;
} }
__1n -> __O1__4expr.tp = __2d -> __O1__4expr.tp ;
__1n -> n_sto__4name = __2d -> n_sto__4name ;
__2d -> __O1__4expr.tp = 0 ;
goto xx ;
}
}
__1n -> __O1__4expr.tp = (struct type *)defa_type ;
xx :;
if (__1n -> __O1__4expr.tp == 0 ){ 
# 1814 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V225 ;

# 1814 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"noT for %s", (const struct ea *)( (__2__X230 = (const void
# 1814 "/home/claude/cfront-3/src/norm.cpp"
*)__1n -> __O2__4expr.string ), ( ((& __0__V225 )-> __O1__2ea.p = __2__X230 ), (& __0__V225 )) ) , (const struct ea *)ea0 ,
# 1814 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1820 "/home/claude/cfront-3/src/norm.cpp"
for(__2d = __1dcl ;__2d ;__2d = __2dx ) { 
# 1821 "/home/claude/cfront-3/src/norm.cpp"
__2dx = __2d -> __O1__4name.n_list ;
if (__2d -> __O1__4expr.tp ){ 
# 1824 "/home/claude/cfront-3/src/norm.cpp"
switch (__2d -> __O1__4expr.tp -> base__4node ){ 
# 1825 "/home/claude/cfront-3/src/norm.cpp"
case 6 :
# 1826 "/home/claude/cfront-3/src/norm.cpp"
case 13 :
# 1830 "/home/claude/cfront-3/src/norm.cpp"
__2d -> __O1__4name.n_list = __0this -> argtype__3fct ;
__0this -> f_args__3fct = (__0this -> argtype__3fct = __2d );
break ;
default :
# 1834 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1834 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V226 ;

# 1834 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n inADL not inAL", (const struct ea *)( ((& __0__V226 )-> __O1__2ea.p =
# 1834 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__2d )), (& __0__V226 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1834 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} }
}
}
}

# 1841 "/home/claude/cfront-3/src/norm.cpp"
for(__1n = __0this -> argtype__3fct ;__1n ;__1n = __1n -> __O1__4name.n_list ) { 
# 1842 "/home/claude/cfront-3/src/norm.cpp"
if (__1n -> __O1__4expr.tp == 0 )__1n -> __O1__4expr.tp = (struct type *)defa_type ;
# 1842 "/home/claude/cfront-3/src/norm.cpp"

# 1843 "/home/claude/cfront-3/src/norm.cpp"
__0this -> nargs__3fct ++ ;
}
}

# 1847 "/home/claude/cfront-3/src/norm.cpp"
Pname cl_obj_vec = 0 ;
Pname eobj = 0 ;

# 1850 "/home/claude/cfront-3/src/norm.cpp"
Pname is_cl_obj__4typeFv (register struct type *__0this )
# 1859 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1860 "/home/claude/cfront-3/src/norm.cpp"
bit __1v ;
Ptype __1t ;

# 1860 "/home/claude/cfront-3/src/norm.cpp"
__1v = 0 ;
__1t = __0this ;

# 1863 "/home/claude/cfront-3/src/norm.cpp"
if (__1t == 0 )return (struct name *)0 ;
eobj = 0 ;
cl_obj_vec = 0 ;
xx :
# 1867 "/home/claude/cfront-3/src/norm.cpp"
switch (__1t -> base__4node ){ 
# 1868 "/home/claude/cfront-3/src/norm.cpp"
case 97 :
# 1869 "/home/claude/cfront-3/src/norm.cpp"
__1t = (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto xx ;

# 1872 "/home/claude/cfront-3/src/norm.cpp"
case 119 :
# 1873 "/home/claude/cfront-3/src/norm.cpp"
if (__1v ){ 
# 1874 "/home/claude/cfront-3/src/norm.cpp"
cl_obj_vec = (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype ;
return (struct name *)0 ;
}
else 
# 1878 "/home/claude/cfront-3/src/norm.cpp"
return (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype ;

# 1880 "/home/claude/cfront-3/src/norm.cpp"
case 110 :
# 1881 "/home/claude/cfront-3/src/norm.cpp"
__1t = (((struct vec *)(((struct vec *)__1t ))))-> typ__5pvtyp ;
__1v = 1 ;
goto xx ;

# 1885 "/home/claude/cfront-3/src/norm.cpp"
case 121 :
# 1886 "/home/claude/cfront-3/src/norm.cpp"
eobj = (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype ;
default :
# 1888 "/home/claude/cfront-3/src/norm.cpp"
return (struct name *)0 ;
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 1900 "/home/claude/cfront-3/src/norm.cpp"
static int k_has_base__FP8classdefT1RUc (Pclass __1c1 , Pclass __1c2 , TOK *__1t );

# 1900 "/home/claude/cfront-3/src/norm.cpp"
static int k_has_base__FP8classdefT1RUc (Pclass __1c1 , Pclass __1c2 , TOK *__1t )
# 1904 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1905 "/home/claude/cfront-3/src/norm.cpp"
if ((__1c1 == 0 )|| (__1c2 == 0 )){ 
# 1905 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V231 ;

# 1905 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V232 ;

# 1905 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"k_has_base(%d,%d,...)", (const struct ea *)( ((&
# 1905 "/home/claude/cfront-3/src/norm.cpp"
__0__V231 )-> __O1__2ea.p = ((const void *)__1c1 )), (& __0__V231 )) , (const struct ea *)( ((& __0__V232 )-> __O1__2ea.p =
# 1905 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1c2 )), (& __0__V232 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} { { Pbcl __1b ;

# 1906 "/home/claude/cfront-3/src/norm.cpp"
__1b = __1c1 -> baselist__8classdef ;

# 1906 "/home/claude/cfront-3/src/norm.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 1907 "/home/claude/cfront-3/src/norm.cpp"
TOK __2v ;

# 1908 "/home/claude/cfront-3/src/norm.cpp"
struct classdef *__1__X233 ;

# 1908 "/home/claude/cfront-3/src/norm.cpp"
struct classdef *__1__X234 ;

# 1908 "/home/claude/cfront-3/src/norm.cpp"
((*__1t ))= __1b -> base__4node ;
if (( (__1__X233 = __1b -> bclass__6basecl ), ( (__1__X234 = __1c2 ), ( ((__1__X233 == __1__X234 )?1 :((__1__X233 && __1__X234 )?(((int )same_class__8classdefFP8classdefi ( __1__X233 ,
# 1909 "/home/claude/cfront-3/src/norm.cpp"
__1__X234 , 0 ) )):0 ))) ) ) )return 1 ;
if (k_has_base__FP8classdefT1RUc ( __1b -> bclass__6basecl , __1c2 , (TOK *)(& __2v )) ){ 
# 1911 "/home/claude/cfront-3/src/norm.cpp"
if (__2v == 77 )((*__1t ))= 77 ;
return 1 ;
}
}
((*__1t ))= 0 ;
return 0 ;

# 1916 "/home/claude/cfront-3/src/norm.cpp"
}

# 1916 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 262 "/home/claude/cfront-3/src/cfront.h"
Pname find_cn__6ktableFPCc (struct ktable *__0this , const char *);

# 260 "/home/claude/cfront-3/src/cfront.h"
Pname look__6ktableFPCcUc (struct ktable *__0this , const char *, TOK );

# 1920 "/home/claude/cfront-3/src/norm.cpp"
static Pname k_find_in_base__FPCcP8classdefRP8classdefUc (const char *__1s , Pclass __1cl , Pclass *__1acl , TOK __1k );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 1920 "/home/claude/cfront-3/src/norm.cpp"
static Pname k_find_in_base__FPCcP8classdefRP8classdefUc (const char *__1s , Pclass __1cl , Pclass *__1acl , TOK __1k )
# 1924 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1925 "/home/claude/cfront-3/src/norm.cpp"
;

# 1927 "/home/claude/cfront-3/src/norm.cpp"
{ Pname __1n ;
Pname __1n2 ;
Pclass __1ncl ;

# 1929 "/home/claude/cfront-3/src/norm.cpp"
Pclass __1n2cl ;

# 1927 "/home/claude/cfront-3/src/norm.cpp"
__1n = 0 ;
__1n2 = 0 ;
__1ncl = 0 ;

# 1929 "/home/claude/cfront-3/src/norm.cpp"
__1n2cl = 0 ;
{ { Pbcl __1b ;

# 1930 "/home/claude/cfront-3/src/norm.cpp"
__1b = __1cl -> baselist__8classdef ;

# 1930 "/home/claude/cfront-3/src/norm.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 1931 "/home/claude/cfront-3/src/norm.cpp"
if (strcmp ( __1s , __1b -> bclass__6basecl -> string__8classdef ) == 0 ){ 
# 1932 "/home/claude/cfront-3/src/norm.cpp"
__1n = find_cn__6ktableFPCc (
# 1932 "/home/claude/cfront-3/src/norm.cpp"
__1b -> bclass__6basecl -> k_tbl__8classdef , __1s ) ;
__1ncl = __1b -> bclass__6basecl ;
}
else if ((__1n = look__6ktableFPCcUc ( __1b -> bclass__6basecl -> k_tbl__8classdef , __1s , (unsigned char )0 ) )!= 0 )
# 1936 "/home/claude/cfront-3/src/norm.cpp"
__1ncl = __1b ->
# 1936 "/home/claude/cfront-3/src/norm.cpp"
bclass__6basecl ;
else 
# 1938 "/home/claude/cfront-3/src/norm.cpp"
__1n = k_find_in_base__FPCcP8classdefRP8classdefUc ( __1s , __1b -> bclass__6basecl , (Pclass *)(& __1ncl ), __1k ) ;
if (__1n == 0 )continue ;
if (__1n2 ){ 
# 1952 "/home/claude/cfront-3/src/norm.cpp"
TOK __3t ;

# 1953 "/home/claude/cfront-3/src/norm.cpp"
struct classdef *__1__X235 ;

# 1953 "/home/claude/cfront-3/src/norm.cpp"
struct classdef *__1__X236 ;

# 1953 "/home/claude/cfront-3/src/norm.cpp"
if (! ( (__1__X235 = __1ncl ), ( (__1__X236 = __1n2cl ), ( ((__1__X235 == __1__X236 )?1 :((__1__X235 && __1__X236 )?(((int )same_class__8classdefFP8classdefi ( __1__X235 ,
# 1953 "/home/claude/cfront-3/src/norm.cpp"
__1__X236 , 0 ) )):0 ))) ) ) ){ 
# 1958 "/home/claude/cfront-3/src/norm.cpp"
if (k_has_base__FP8classdefT1RUc ( __1n2cl , __1ncl , (TOK *)(& __3t )) ){ 
# 1960 "/home/claude/cfront-3/src/norm.cpp"
__1n =
# 1960 "/home/claude/cfront-3/src/norm.cpp"
__1n2 ;
__1ncl = __1n2cl ;
}
}
}
__1n2 = __1n ;
__1n2cl = __1ncl ;
}
if (__1n ){ 
# 1969 "/home/claude/cfront-3/src/norm.cpp"
((*__1acl ))= __1ncl ;
return __1n ;
}
((*__1acl ))= __1n2cl ;
return __1n2 ;

# 1973 "/home/claude/cfront-3/src/norm.cpp"
}

# 1973 "/home/claude/cfront-3/src/norm.cpp"
}

# 1973 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 1977 "/home/claude/cfront-3/src/norm.cpp"
Pname k_find_name__FPCcP6ktableUc (const char *__1s , Pktab __1tbl , TOK __1k )
# 1980 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 1981 "/home/claude/cfront-3/src/norm.cpp"
recurse :
# 1982 "/home/claude/cfront-3/src/norm.cpp"
;
if (__1tbl == 0 )return (struct name *)0 ;
{ Pname __1n ;
if (__1tbl -> k_id__6ktable == 6 ){ 
# 1986 "/home/claude/cfront-3/src/norm.cpp"
if (__1tbl -> k_name__6ktable == 0 )error__FiPCc ( (int )'i' , (const char *)"C table with noN")
# 1986 "/home/claude/cfront-3/src/norm.cpp"
;
if (strcmp ( __1s , __1tbl -> k_name__6ktable -> __O2__4expr.string ) == 0 )
# 1988 "/home/claude/cfront-3/src/norm.cpp"
__1n = find_cn__6ktableFPCc ( __1tbl , __1s ) ;
else { 
# 1990 "/home/claude/cfront-3/src/norm.cpp"
Pclass __3cl ;

# 1990 "/home/claude/cfront-3/src/norm.cpp"
__3cl = classtype__4typeFv ( __1tbl -> k_name__6ktable -> __O1__4expr.tp ) ;
__1n = look__6ktableFPCcUc ( __3cl -> k_tbl__8classdef , __1s , (unsigned char )0 ) ;
}
}
else __1n = look__6ktableFPCcUc ( __1tbl , __1s , (unsigned char )0 ) ;
if ((__1n && (__1k == 159 ))&& (__1n -> base__4node != 123 ))__1n = __1n -> __O1__4name.n_hidden ;

# 1999 "/home/claude/cfront-3/src/norm.cpp"
;
if (__1n )return __1n ;

# 2005 "/home/claude/cfront-3/src/norm.cpp"
while (__1tbl && (__1tbl -> k_id__6ktable == 116 ))__1tbl = __1tbl -> k_next__6ktable ;
if (__1tbl == Gtbl )return (struct name *)0 ;
if (__1tbl -> k_id__6ktable == 6 ){ 
# 2008 "/home/claude/cfront-3/src/norm.cpp"
if (__1tbl -> k_name__6ktable == 0 )error__FiPCc ( (int )'i' , (const char *)"C table with noN")
# 2008 "/home/claude/cfront-3/src/norm.cpp"
;
{ Pclass __2cl ;

# 2009 "/home/claude/cfront-3/src/norm.cpp"
Pclass __2acl ;

# 2009 "/home/claude/cfront-3/src/norm.cpp"
__2cl = classtype__4typeFv ( __1tbl -> k_name__6ktable -> __O1__4expr.tp ) ;
__1n = k_find_in_base__FPCcP8classdefRP8classdefUc ( __1s , __2cl , (Pclass *)(& __2acl ), __1k ) ;

# 2010 "/home/claude/cfront-3/src/norm.cpp"
}
}
else __1n = look__6ktableFPCcUc ( __1tbl , __1s , (unsigned char )0 ) ;
if ((__1n && (__1k == 159 ))&& (__1n -> base__4node != 123 ))__1n = __1n -> __O1__4name.n_hidden ;
if (__1n )return __1n ;

# 2017 "/home/claude/cfront-3/src/norm.cpp"
__1tbl = __1tbl -> k_next__6ktable ;
goto recurse ;

# 2018 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 2021 "/home/claude/cfront-3/src/norm.cpp"
Pname k_find_member__FPCcP8classdefUc (const char *__1s , Pclass __1cl , TOK __1k )
# 2024 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 2025 "/home/claude/cfront-3/src/norm.cpp"
;
{ Pktab __1tbl ;
Pname __1n ;

# 2040 "/home/claude/cfront-3/src/norm.cpp"
Pclass __1acl ;

# 2026 "/home/claude/cfront-3/src/norm.cpp"
__1tbl = __1cl -> k_tbl__8classdef ;

# 2028 "/home/claude/cfront-3/src/norm.cpp"
if (__1tbl -> k_id__6ktable != 6 ){ 
# 2028 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V237 ;

# 2028 "/home/claude/cfront-3/src/norm.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"C tableX for%t!", (const struct ea *)( ((&
# 2028 "/home/claude/cfront-3/src/norm.cpp"
__0__V237 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V237 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2028 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 ) ;
} if (strcmp ( __1s , __1cl -> string__8classdef ) == 0 )
# 2030 "/home/claude/cfront-3/src/norm.cpp"
__1n = find_cn__6ktableFPCc ( __1tbl , __1s ) ;
else 
# 2032 "/home/claude/cfront-3/src/norm.cpp"
__1n = look__6ktableFPCcUc ( __1tbl , __1s , (unsigned char )0 ) ;
if ((__1n && (__1k == 159 ))&& (__1n -> base__4node != 123 ))__1n = __1n -> __O1__4name.n_hidden ;

# 2037 "/home/claude/cfront-3/src/norm.cpp"
;
if (__1n )return __1n ;

# 2040 "/home/claude/cfront-3/src/norm.cpp"
;
__1n = k_find_in_base__FPCcP8classdefRP8classdefUc ( __1s , __1cl , (Pclass *)(& __1acl ), __1k ) ;
if ((__1n && (__1k == 159 ))&& (__1n -> base__4node != 123 ))__1n = __1n -> __O1__4name.n_hidden ;

# 2046 "/home/claude/cfront-3/src/norm.cpp"
;
return __1n ;

# 2047 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 261 "/home/claude/cfront-3/src/cfront.h"
Pname insert__6ktableFP4nameUc (struct ktable *__0this , Pname , TOK );

# 2054 "/home/claude/cfront-3/src/norm.cpp"
Pname insert_name__FP4nameP6ktable (Pname __1nn , Pktab __1tbl )
# 2057 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 2058 "/home/claude/cfront-3/src/norm.cpp"
;
{ Pname __1nx ;

# 2059 "/home/claude/cfront-3/src/norm.cpp"
__1nx = k_find_name__FPCcP6ktableUc ( __1nn -> __O2__4expr.string , __1tbl , (unsigned char )0 ) ;
if (__1nx && (__1nx -> n_ktable__4name == __1tbl )){ 
# 2061 "/home/claude/cfront-3/src/norm.cpp"
if (__1nx -> base__4node == 123 ){ 
# 2062 "/home/claude/cfront-3/src/norm.cpp"
;
if ((__1nx -> __O1__4expr.tp && (__1nx -> __O1__4expr.tp -> base__4node != 119 ))&& (__1nx -> __O1__4expr.tp -> base__4node != 121 ))
# 2065 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 2066 "/home/claude/cfront-3/src/norm.cpp"
;
}
__1nx -> n_key__4name = 159 ;
{ Pname __3ny ;

# 2069 "/home/claude/cfront-3/src/norm.cpp"
__3ny = insert__6ktableFP4nameUc ( __1tbl , __1nn , (unsigned char )0 ) ;
if (Nold ){ 
# 2070 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V238 ;

# 2070 "/home/claude/cfront-3/src/norm.cpp"
error__FPCcRC2eaN32 ( (const char *)"hiddenTN%n inserted twice", (const struct ea *)( ((& __0__V238 )-> __O1__2ea.p =
# 2070 "/home/claude/cfront-3/src/norm.cpp"
((const void *)__1nx )), (& __0__V238 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2070 "/home/claude/cfront-3/src/norm.cpp"
ea *)ea0 ) ;
} else __3ny -> __O1__4name.n_hidden = __1nx ;
__1nx = __3ny ;

# 2072 "/home/claude/cfront-3/src/norm.cpp"
}
}
else 
# 2073 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 2074 "/home/claude/cfront-3/src/norm.cpp"
;
;
}
}
else 
# 2077 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 2078 "/home/claude/cfront-3/src/norm.cpp"
Pname __2ny ;

# 2078 "/home/claude/cfront-3/src/norm.cpp"
__2ny = insert__6ktableFP4nameUc ( __1tbl , __1nn , (unsigned char )0 ) ;
if (__1nx && (__1nx -> base__4node != 123 ))
# 2080 "/home/claude/cfront-3/src/norm.cpp"
__1nx = __1nx -> __O1__4name.n_hidden ;
__2ny -> __O1__4name.n_hidden = __1nx ;
__1nx = __2ny ;
}
return __1nx ;

# 2084 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 2087 "/home/claude/cfront-3/src/norm.cpp"
Pname insert_type__FP4nameP6ktableUc (Pname __1nn , Pktab __1tbl , TOK __1tcsue )
# 2092 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 2095 "/home/claude/cfront-3/src/norm.cpp"
;
if (__1tbl -> k_id__6ktable == 136 ){ 
# 2098 "/home/claude/cfront-3/src/norm.cpp"
do __1tbl = __1tbl -> k_next__6ktable ;
while (__1tbl -> k_id__6ktable == 136 );

# 2099 "/home/claude/cfront-3/src/norm.cpp"
if (__1tbl -> k_id__6ktable == 185 )__1tbl = __1tbl -> k_next__6ktable ;
}
if (__1tbl -> k_id__6ktable == 6 ){ 
# 2102 "/home/claude/cfront-3/src/norm.cpp"
if (ccl == 0 ){ 
# 2102 "/home/claude/cfront-3/src/norm.cpp"
struct ea __0__V239 ;

# 2102 "/home/claude/cfront-3/src/norm.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1nn -> where__4name , (const char *)"insert_type(%n) -- no ccl for class table!", (const
# 2102 "/home/claude/cfront-3/src/norm.cpp"
struct ea *)( ((& __0__V239 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V239 )) , (const struct ea *)ea0 ,
# 2102 "/home/claude/cfront-3/src/norm.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
;

# 2106 "/home/claude/cfront-3/src/norm.cpp"
{ Pname __1nx ;

# 2106 "/home/claude/cfront-3/src/norm.cpp"
__1nx = k_find_name__FPCcP6ktableUc ( __1nn -> __O2__4expr.string , __1tbl , (unsigned char )0 ) ;
if (__1nx && (__1nx -> n_ktable__4name == __1tbl )){ 
# 2108 "/home/claude/cfront-3/src/norm.cpp"
Nold = 0 ;
if (__1nx -> base__4node == 123 ){ 
# 2110 "/home/claude/cfront-3/src/norm.cpp"
Nold = 1 ;
;
}
else 
# 2112 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 2113 "/home/claude/cfront-3/src/norm.cpp"
if (__1tcsue == 97 ){ 
# 2114 "/home/claude/cfront-3/src/norm.cpp"
;
;
}
{ Pname __3ny ;

# 2117 "/home/claude/cfront-3/src/norm.cpp"
__3ny = insert__6ktableFP4nameUc ( __1tbl , __1nn , (unsigned char )159 ) ;
if (Nold ){ 
# 2119 "/home/claude/cfront-3/src/norm.cpp"
;
;
}
else 
# 2121 "/home/claude/cfront-3/src/norm.cpp"
{ __3ny -> __O1__4name.n_hidden = __1nx -> __O1__4name.n_hidden ;

# 2121 "/home/claude/cfront-3/src/norm.cpp"
__1nx -> __O1__4name.n_hidden = __3ny ;
;
}
__1nx = __3ny ;

# 2124 "/home/claude/cfront-3/src/norm.cpp"
}
}
}
else 
# 2126 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 2127 "/home/claude/cfront-3/src/norm.cpp"
Pname __2ny ;

# 2127 "/home/claude/cfront-3/src/norm.cpp"
__2ny = insert__6ktableFP4nameUc ( __1tbl , __1nn , (unsigned char )0 ) ;
__2ny -> __O1__4name.n_hidden = __1nx ;
__1nx = __2ny ;
;
}
__1nx -> base__4node = 123 ;
return __1nx ;

# 2133 "/home/claude/cfront-3/src/norm.cpp"
}
}

# 2137 "/home/claude/cfront-3/src/norm.cpp"
const char *whereami__6ktableFv (register struct ktable *__0this )
# 2138 "/home/claude/cfront-3/src/norm.cpp"
{ 
# 2139 "/home/claude/cfront-3/src/norm.cpp"
if (__0this == 0 )return (const char *)"NULL TABLE!!!";
# 2139 "/home/claude/cfront-3/src/norm.cpp"
else 
# 2140 "/home/claude/cfront-3/src/norm.cpp"
if (__0this -> k_id__6ktable == 136 )return (const char *)"arg scope";
else if (__0this == Gtbl )return (const char *)"global scope";
else if (__0this -> k_id__6ktable == 116 )return (const char *)"block scope";
else if (__0this -> k_id__6ktable == 185 )return (const char *)"template scope";
else if (__0this -> k_name__6ktable )return __0this -> k_name__6ktable -> __O2__4expr.string ;
else return (const char *)"??? scope";
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

# 2146 "/home/claude/cfront-3/src/norm.cpp"

/* the end */
