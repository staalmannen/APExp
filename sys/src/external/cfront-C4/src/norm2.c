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

# 323 "/home/claude/cfront-3/src/cfront.h"

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 35 "/home/claude/cfront-3/src/norm2.cpp"
struct fct *__ct__3fctFP4typeP4nameUc (register struct fct *__0this , Ptype __1t , Pname __1arg , TOK __1known )
# 36 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 46 "/home/claude/cfront-3/src/norm2.cpp"
Pname __1n ;
Pname __1pn ;

# 48 "/home/claude/cfront-3/src/norm2.cpp"
struct type *__0__X20 ;

# 48 "/home/claude/cfront-3/src/norm2.cpp"
struct node *__0__X1 ;

# 36 "/home/claude/cfront-3/src/norm2.cpp"
if (__0this || (__0this = (struct fct *)__nw__3fctSFUl ( (size_t )(sizeof (struct fct))) )){ __0this = (struct fct *)( (__0__X20 =
# 36 "/home/claude/cfront-3/src/norm2.cpp"
(((struct type *)__0this ))), ( ((__0__X20 || (__0__X20 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type))) ))?( ( (
# 36 "/home/claude/cfront-3/src/norm2.cpp"
( ( ( ( ( (__0__X20 = (struct type *)( (__0__X1 = (((struct node *)__0__X20 ))), ( ((__0__X1 || (__0__X1 =
# 36 "/home/claude/cfront-3/src/norm2.cpp"
(struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 -> permanent__4node = 0 ))
# 36 "/home/claude/cfront-3/src/norm2.cpp"
, (__0__X1 -> baseclass__4node = 0 )) :0 ), __0__X1 ) ) ), (__0__X20 -> defined__4type = 0 )) , (__0__X20 -> lex_level__4type =
# 36 "/home/claude/cfront-3/src/norm2.cpp"
0 )) , (__0__X20 -> templ_base__4type = 0)) , (__0__X20 -> in_class__4type = 0 )) , (__0__X20 -> nested_sig__4type = 0 )) ,
# 36 "/home/claude/cfront-3/src/norm2.cpp"
(__0__X20 -> local_sig__4type = 0 )) , (__0__X20 -> b_const__4type = 0 )) , (__0__X20 -> ansi_const__4type = 0 )) :0 ), __0__X20 ) )
# 36 "/home/claude/cfront-3/src/norm2.cpp"
;
__0this -> base__4node = 108 ;
__0this -> nargs_known__3fct = __1known ;
__0this -> returns__3fct = __1t ;
__0this -> argtype__3fct = __1arg ;
__0this -> f_virtual__3fct = 0 ;
;

# 44 "/home/claude/cfront-3/src/norm2.cpp"
if ((__1arg == 0 )|| (__1arg -> base__4node == 140 ))return __0this ;

# 46 "/home/claude/cfront-3/src/norm2.cpp"
;
__1pn = 0 ;
for(__1n = __1arg ;__1n ;( (__1pn = __1n ), (__1n = __1n -> __O1__4name.n_list )) ) { 
# 49 "/home/claude/cfront-3/src/norm2.cpp"
if (__1n -> n_sto__4name == 14 )error__FPCc ( (const
# 49 "/home/claude/cfront-3/src/norm2.cpp"
char *)"cannot specify extern linkage for anA") ;
if (__1n -> n_sto__4name == 31 ){ 
# 50 "/home/claude/cfront-3/src/norm2.cpp"
struct ea __0__V17 ;

# 50 "/home/claude/cfront-3/src/norm2.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot specify static forA%n", (const struct ea *)( ((& __0__V17 )-> __O1__2ea.p =
# 50 "/home/claude/cfront-3/src/norm2.cpp"
((const void *)__1arg )), (& __0__V17 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 50 "/home/claude/cfront-3/src/norm2.cpp"
ea *)ea0 ) ;
} 
# 52 "/home/claude/cfront-3/src/norm2.cpp"
switch (skiptypedefs__4typeFv ( __1n -> __O1__4expr.tp ) -> base__4node ){ 
# 52 "/home/claude/cfront-3/src/norm2.cpp"
unsigned long __2__X21 ;

# 53 "/home/claude/cfront-3/src/norm2.cpp"
case 38 :
# 54 "/home/claude/cfront-3/src/norm2.cpp"
__0this -> argtype__3fct = 0 ;
__0this -> nargs_known__3fct = 1 ;
if (__1n -> __O3__4expr.n_initializer )
# 57 "/home/claude/cfront-3/src/norm2.cpp"
error__FPCc ( (const char *)"voidFA") ;
else if (__1n -> __O2__4expr.string )
# 59 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 59 "/home/claude/cfront-3/src/norm2.cpp"
struct ea __0__V18 ;

# 59 "/home/claude/cfront-3/src/norm2.cpp"
error__FPCcRC2eaN32 ( (const char *)"voidFA%n", (const struct ea *)( ((& __0__V18 )-> __O1__2ea.p =
# 59 "/home/claude/cfront-3/src/norm2.cpp"
((const void *)__1n )), (& __0__V18 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 59 "/home/claude/cfront-3/src/norm2.cpp"
ea *)ea0 ) ;
} else if (__0this -> nargs__3fct || __1n -> __O1__4name.n_list ){ 
# 61 "/home/claude/cfront-3/src/norm2.cpp"
error__FPCc ( (const char *)"voidFA")
# 61 "/home/claude/cfront-3/src/norm2.cpp"
;
__0this -> nargs_known__3fct = 0 ;
}
__0this -> nargs__3fct = 0 ;
break ;
case 6 :
# 67 "/home/claude/cfront-3/src/norm2.cpp"
case 13 :
# 68 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 68 "/home/claude/cfront-3/src/norm2.cpp"
struct ea __0__V19 ;

# 68 "/home/claude/cfront-3/src/norm2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k defined inAL (will not be in scope at point of call)", (const struct ea *)( (__2__X21 = __1n -> __O1__4expr.tp ->
# 68 "/home/claude/cfront-3/src/norm2.cpp"
base__4node ), ( (( ((& __0__V19 )-> __O1__2ea.i = __2__X21 ), 0 ) ), (& __0__V19 )) ) , (const
# 68 "/home/claude/cfront-3/src/norm2.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
if (__1n == __0this -> argtype__3fct )
# 70 "/home/claude/cfront-3/src/norm2.cpp"
__0this -> argtype__3fct = __1n -> __O1__4name.n_list ;
else 
# 72 "/home/claude/cfront-3/src/norm2.cpp"
__1pn -> __O1__4name.n_list = __1n -> __O1__4name.n_list ;
break ;
default :
# 75 "/home/claude/cfront-3/src/norm2.cpp"
__0this -> nargs__3fct ++ ;
} }
}
} 
# 48 "/home/claude/cfront-3/src/norm2.cpp"
return __0this ;

# 78 "/home/claude/cfront-3/src/norm2.cpp"
}

# 187 "/home/claude/cfront-3/src/cfront.h"

# 80 "/home/claude/cfront-3/src/norm2.cpp"
struct expr *__ct__4exprFUcP4exprT2 (register struct expr *__0this , TOK __1ba , Pexpr __1a , Pexpr __1b )
# 81 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 81 "/home/claude/cfront-3/src/norm2.cpp"
struct node *__0__X22 ;

# 81 "/home/claude/cfront-3/src/norm2.cpp"
if (__0this || (__0this = (struct expr *)__nw__4exprSFUl ( (size_t )(sizeof (struct expr))) )){ __0this = (struct expr *)( (__0__X22 =
# 81 "/home/claude/cfront-3/src/norm2.cpp"
(((struct node *)__0this ))), ( ((__0__X22 || (__0__X22 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X22 ->
# 81 "/home/claude/cfront-3/src/norm2.cpp"
base__4node = 0 ), (__0__X22 -> permanent__4node = 0 )) , (__0__X22 -> baseclass__4node = 0 )) :0 ), __0__X22 ) ) ;
;

# 84 "/home/claude/cfront-3/src/norm2.cpp"
__0this -> base__4node = __1ba ;
__0this -> __O2__4expr.e1 = __1a ;
__0this -> __O3__4expr.e2 = __1b ;
__0this -> __O4__4expr.mem = 0 ;
__0this -> __O1__4expr.tp = 0 ;
;
} 
# 89 "/home/claude/cfront-3/src/norm2.cpp"
return __0this ;
}

# 187 "/home/claude/cfront-3/src/cfront.h"

# 92 "/home/claude/cfront-3/src/norm2.cpp"
struct stmt *__ct__4stmtFUc3locP4stmt (register struct stmt *__0this , TOK __1ba , struct loc __1ll , Pstmt __1a )
# 93 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 93 "/home/claude/cfront-3/src/norm2.cpp"
struct node *__0__X23 ;

# 93 "/home/claude/cfront-3/src/norm2.cpp"
if (__0this || (__0this = (struct stmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct stmt))) )){ __0this = (struct stmt *)( (__0__X23 =
# 93 "/home/claude/cfront-3/src/norm2.cpp"
(((struct node *)__0this ))), ( ((__0__X23 || (__0__X23 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X23 ->
# 93 "/home/claude/cfront-3/src/norm2.cpp"
base__4node = 0 ), (__0__X23 -> permanent__4node = 0 )) , (__0__X23 -> baseclass__4node = 0 )) :0 ), __0__X23 ) ) ;
;

# 96 "/home/claude/cfront-3/src/norm2.cpp"
__0this -> base__4node = __1ba ;
__0this -> where__4stmt = __1ll ;
__0this -> s__4stmt = __1a ;
__0this -> memtbl__4stmt = 0 ;
__0this -> k_tbl__4stmt = 0 ;
;
} 
# 101 "/home/claude/cfront-3/src/norm2.cpp"
return __0this ;
}

# 323 "/home/claude/cfront-3/src/cfront.h"

# 220 "/home/claude/cfront-3/src/cfront.h"
struct table *__ct__5tableFsP5tableP4name (struct table *__0this , short , Ptable , Pname );

# 104 "/home/claude/cfront-3/src/norm2.cpp"
struct classdef *__ct__8classdefFUc (register struct classdef *__0this , TOK __1b )
# 105 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 105 "/home/claude/cfront-3/src/norm2.cpp"
struct type *__0__X24 ;

# 105 "/home/claude/cfront-3/src/norm2.cpp"
struct node *__0__X1 ;

# 105 "/home/claude/cfront-3/src/norm2.cpp"
if (__0this || (__0this = (struct classdef *)__nw__FUl ( (size_t )(sizeof (struct classdef))) )){ __0this = (struct classdef *)( (__0__X24 =
# 105 "/home/claude/cfront-3/src/norm2.cpp"
(((struct type *)__0this ))), ( ((__0__X24 || (__0__X24 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type))) ))?( ( (
# 105 "/home/claude/cfront-3/src/norm2.cpp"
( ( ( ( ( (__0__X24 = (struct type *)( (__0__X1 = (((struct node *)__0__X24 ))), ( ((__0__X1 || (__0__X1 =
# 105 "/home/claude/cfront-3/src/norm2.cpp"
(struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 -> permanent__4node = 0 ))
# 105 "/home/claude/cfront-3/src/norm2.cpp"
, (__0__X1 -> baseclass__4node = 0 )) :0 ), __0__X1 ) ) ), (__0__X24 -> defined__4type = 0 )) , (__0__X24 -> lex_level__4type =
# 105 "/home/claude/cfront-3/src/norm2.cpp"
0 )) , (__0__X24 -> templ_base__4type = 0)) , (__0__X24 -> in_class__4type = 0 )) , (__0__X24 -> nested_sig__4type = 0 )) ,
# 105 "/home/claude/cfront-3/src/norm2.cpp"
(__0__X24 -> local_sig__4type = 0 )) , (__0__X24 -> b_const__4type = 0 )) , (__0__X24 -> ansi_const__4type = 0 )) :0 ), __0__X24 ) )
# 105 "/home/claude/cfront-3/src/norm2.cpp"
;
__0this -> base__4node = 6 ;
__0this -> csu__8classdef = __1b ;
__0this -> memtbl__8classdef = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )12 , (struct table *)0 , (struct name *)0 ) ;
__0this -> k_tbl__8classdef = 0 ;
__0this -> class_base__8classdef = 0;
__0this -> c_xref__8classdef = 0 ;
__0this -> c_body__8classdef = 0 ;
__0this -> has_vvtab__8classdef = 0 ;
__0this -> obj_align__8classdef = 0 ;
__0this -> virt_merge__8classdef = 0 ;
__0this -> virt_count__8classdef = 0 ;
__0this -> c_context__8classdef = 0 ;
__0this -> mem_list__8classdef = 0 ;
__0this -> baselist__8classdef = 0 ;
__0this -> friend_list__8classdef = 0 ;
__0this -> c_funqf__8classdef = (__0this -> c_funqr__8classdef = 0 );
__0this -> c_ctor__8classdef = 0 ;
__0this -> c_itor__8classdef = 0 ;
__0this -> c_dtor__8classdef = 0 ;
__0this -> c_vtor__8classdef = 0 ;
__0this -> virt_list__8classdef = 0 ;
__0this -> c_abstract__8classdef = 0 ;
__0this -> conv__8classdef = 0 ;
__0this -> string__8classdef = 0 ;
;
} 
# 130 "/home/claude/cfront-3/src/norm2.cpp"
return __0this ;
}

# 1 ""
extern void __dl__FPv (void *);

# 218 "/home/claude/cfront-3/src/cfront.h"

# 221 "/home/claude/cfront-3/src/cfront.h"
void __dt__5tableFv (struct table *__0this , int );

# 133 "/home/claude/cfront-3/src/norm2.cpp"
void __dt__8classdefFv (struct classdef *__0this , 
# 133 "/home/claude/cfront-3/src/norm2.cpp"
int __0__free )
# 134 "/home/claude/cfront-3/src/norm2.cpp"
{ if (__0this ){ 
# 135 "/home/claude/cfront-3/src/norm2.cpp"
__dt__5tableFv ( __0this -> memtbl__8classdef , 3) ;
if (__0this )if (__0__free & 1)__dl__FPv ( (void *)__0this ) ;
} 
# 136 "/home/claude/cfront-3/src/norm2.cpp"
}

# 323 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 138 "/home/claude/cfront-3/src/norm2.cpp"
struct basetype *__ct__8basetypeFUcP4name (register struct basetype *__0this , TOK __1b , Pname __1n )
# 139 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 139 "/home/claude/cfront-3/src/norm2.cpp"
struct type *__0__X27 ;

# 139 "/home/claude/cfront-3/src/norm2.cpp"
struct node *__0__X1 ;

# 139 "/home/claude/cfront-3/src/norm2.cpp"
if (__0this || (__0this = (struct basetype *)__nw__FUl ( (size_t )(sizeof (struct basetype))) )){ __0this = (struct basetype *)( (__0__X27 =
# 139 "/home/claude/cfront-3/src/norm2.cpp"
(((struct type *)__0this ))), ( ((__0__X27 || (__0__X27 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type))) ))?( ( (
# 139 "/home/claude/cfront-3/src/norm2.cpp"
( ( ( ( ( (__0__X27 = (struct type *)( (__0__X1 = (((struct node *)__0__X27 ))), ( ((__0__X1 || (__0__X1 =
# 139 "/home/claude/cfront-3/src/norm2.cpp"
(struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 -> permanent__4node = 0 ))
# 139 "/home/claude/cfront-3/src/norm2.cpp"
, (__0__X1 -> baseclass__4node = 0 )) :0 ), __0__X1 ) ) ), (__0__X27 -> defined__4type = 0 )) , (__0__X27 -> lex_level__4type =
# 139 "/home/claude/cfront-3/src/norm2.cpp"
0 )) , (__0__X27 -> templ_base__4type = 0)) , (__0__X27 -> in_class__4type = 0 )) , (__0__X27 -> nested_sig__4type = 0 )) ,
# 139 "/home/claude/cfront-3/src/norm2.cpp"
(__0__X27 -> local_sig__4type = 0 )) , (__0__X27 -> b_const__4type = 0 )) , (__0__X27 -> ansi_const__4type = 0 )) :0 ), __0__X27 ) )
# 139 "/home/claude/cfront-3/src/norm2.cpp"
;
__0this -> b_xname__8basetype = 0 ;
__0this -> b_sto__8basetype = 0 ;
__0this -> b_name__8basetype = 0 ;

# 145 "/home/claude/cfront-3/src/norm2.cpp"
__0this -> b_unsigned__8basetype = (__0this -> b_signed__8basetype = (__0this -> b_volatile__8basetype = (__0this -> b_typedef__8basetype = (__0this -> b_inline__8basetype = (__0this -> b_virtual__8basetype = (__0this -> b_short__8basetype =
# 145 "/home/claude/cfront-3/src/norm2.cpp"
(__0this -> b_long__8basetype = (__0this -> b_bits__8basetype = (__0this -> b_offset__8basetype = 0 )))))))));
__0this -> __O1__8basetype.b_linkage = 0 ;
switch (__1b ){ 
# 148 "/home/claude/cfront-3/src/norm2.cpp"
case 0 :break ;
case 35 :__0this -> b_typedef__8basetype = 1 ;

# 149 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 75 :__0this -> b_inline__8basetype = 1 ;

# 150 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 77 :__0this -> b_virtual__8basetype = 1 ;

# 151 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 26 :__0this -> b_const__4type = 1 ;

# 152 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 37 :__0this -> b_unsigned__8basetype = 1 ;

# 153 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 18 :
# 155 "/home/claude/cfront-3/src/norm2.cpp"
case 76 :
# 156 "/home/claude/cfront-3/src/norm2.cpp"
case 14 :
# 157 "/home/claude/cfront-3/src/norm2.cpp"
case 31 :
# 158 "/home/claude/cfront-3/src/norm2.cpp"
case 2 :
# 159 "/home/claude/cfront-3/src/norm2.cpp"
case 27 :__0this -> b_sto__8basetype = __1b ;

# 159 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 29 :__0this -> b_short__8basetype = 1 ;

# 160 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 22 :__0this -> b_long__8basetype = 1 ;

# 161 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 122 :__0this -> b_long__8basetype = 2 ;

# 162 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 141 :
# 164 "/home/claude/cfront-3/src/norm2.cpp"
case 138 :
# 165 "/home/claude/cfront-3/src/norm2.cpp"
case 38 :
# 166 "/home/claude/cfront-3/src/norm2.cpp"
case 5 :
# 167 "/home/claude/cfront-3/src/norm2.cpp"
case 21 :
# 168 "/home/claude/cfront-3/src/norm2.cpp"
case 15 :
# 169 "/home/claude/cfront-3/src/norm2.cpp"
case 181 :
# 170 "/home/claude/cfront-3/src/norm2.cpp"
case 11 :__0this -> base__4node = __1b ;

# 170 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 97 :
# 172 "/home/claude/cfront-3/src/norm2.cpp"
case 119 :
# 173 "/home/claude/cfront-3/src/norm2.cpp"
case 121 :
# 174 "/home/claude/cfront-3/src/norm2.cpp"
case 114 :
# 175 "/home/claude/cfront-3/src/norm2.cpp"
case 1 :
# 176 "/home/claude/cfront-3/src/norm2.cpp"
__0this -> base__4node = __1b ;
__0this -> b_name__8basetype = __1n ;
break ;
case 171 :
# 181 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 170 :
# 183 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 183 "/home/claude/cfront-3/src/norm2.cpp"
struct ea __0__V25 ;

# 183 "/home/claude/cfront-3/src/norm2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"\"%k\" not implemented (ignored)", (const struct ea *)( ((
# 183 "/home/claude/cfront-3/src/norm2.cpp"
((& __0__V25 )-> __O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V25 )) , (const struct ea *)ea0 ,
# 183 "/home/claude/cfront-3/src/norm2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
default :
# 186 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 186 "/home/claude/cfront-3/src/norm2.cpp"
struct ea __0__V26 ;

# 186 "/home/claude/cfront-3/src/norm2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"badBT:%k", (const struct ea *)( ((
# 186 "/home/claude/cfront-3/src/norm2.cpp"
((& __0__V26 )-> __O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V26 )) , (const struct ea *)ea0 ,
# 186 "/home/claude/cfront-3/src/norm2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} } }
;
} 
# 188 "/home/claude/cfront-3/src/norm2.cpp"
return __0this ;
}

# 191 "/home/claude/cfront-3/src/norm2.cpp"
struct name *__ct__4nameFPCc (register struct name *__0this , const char *__1s )
# 192 "/home/claude/cfront-3/src/norm2.cpp"
{ if (__0this || (__0this = (struct name *)__nw__4nameSFUl ( (unsigned long
# 192 "/home/claude/cfront-3/src/norm2.cpp"
)(sizeof (struct name))) )){ __0this = (struct name *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0this ), (unsigned char )85 , (struct expr *)0 , (struct
# 192 "/home/claude/cfront-3/src/norm2.cpp"
expr *)0 ) ;

# 194 "/home/claude/cfront-3/src/norm2.cpp"
__0this -> __O2__4expr.string = __1s ;
__0this -> where__4name = curloc ;
__0this -> lex_level__4name = bl_level ;
} 
# 196 "/home/claude/cfront-3/src/norm2.cpp"
return __0this ;
}

# 187 "/home/claude/cfront-3/src/cfront.h"

# 199 "/home/claude/cfront-3/src/norm2.cpp"
struct name_list *__ct__9name_listFP4nameP9name_list (register struct name_list *__0this , Pname __1ff , Plist __1ll )
# 200 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 200 "/home/claude/cfront-3/src/norm2.cpp"
struct node *__0__X28 ;

# 200 "/home/claude/cfront-3/src/norm2.cpp"
if (__0this || (__0this = (struct name_list *)__nw__FUl ( (size_t )(sizeof (struct name_list))) )){ __0this = (struct name_list *)( (__0__X28 =
# 200 "/home/claude/cfront-3/src/norm2.cpp"
(((struct node *)__0this ))), ( ((__0__X28 || (__0__X28 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X28 ->
# 200 "/home/claude/cfront-3/src/norm2.cpp"
base__4node = 0 ), (__0__X28 -> permanent__4node = 0 )) , (__0__X28 -> baseclass__4node = 0 )) :0 ), __0__X28 ) ) ;
__0this -> base__4node = 201 ;
__0this -> f__9name_list = __1ff ;
__0this -> l__9name_list = __1ll ;
} 
# 203 "/home/claude/cfront-3/src/norm2.cpp"
return __0this ;
}

# 206 "/home/claude/cfront-3/src/norm2.cpp"
struct nlist *__ct__5nlistFP4name (register struct nlist *__0this , Pname __1n )
# 207 "/home/claude/cfront-3/src/norm2.cpp"
{ if (__0this || (__0this = (struct nlist *)__nw__FUl ( (size_t )(sizeof (struct nlist)))
# 207 "/home/claude/cfront-3/src/norm2.cpp"
)){ 
# 208 "/home/claude/cfront-3/src/norm2.cpp"
__0this -> head__5nlist = __1n ;
{ Pname __1nn ;

# 209 "/home/claude/cfront-3/src/norm2.cpp"
__1nn = __1n ;
for(;__1nn -> __O1__4name.n_list ;__1nn = __1nn -> __O1__4name.n_list ) ;
__0this -> tail__5nlist = __1nn ;

# 211 "/home/claude/cfront-3/src/norm2.cpp"
}
} 
# 209 "/home/claude/cfront-3/src/norm2.cpp"
return __0this ;

# 212 "/home/claude/cfront-3/src/norm2.cpp"
}

# 214 "/home/claude/cfront-3/src/norm2.cpp"
void add_list__5nlistFP4name (register struct nlist *__0this , Pname __1n )
# 215 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 216 "/home/claude/cfront-3/src/norm2.cpp"
if (__1n -> __O1__4expr.tp && (__1n -> __O1__4expr.tp -> defined__4type & 020 ))return ;

# 218 "/home/claude/cfront-3/src/norm2.cpp"
__0this -> tail__5nlist -> __O1__4name.n_list = __1n ;
{ Pname __1nn ;

# 219 "/home/claude/cfront-3/src/norm2.cpp"
__1nn = __1n ;
for(;__1nn -> __O1__4name.n_list ;__1nn = __1nn -> __O1__4name.n_list ) ;
__0this -> tail__5nlist = __1nn ;

# 221 "/home/claude/cfront-3/src/norm2.cpp"
}
}

# 224 "/home/claude/cfront-3/src/norm2.cpp"
Pname name_unlist__FP5nlist (Pnlist __1l )
# 225 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 226 "/home/claude/cfront-3/src/norm2.cpp"
if (__1l == 0 )return (struct name *)0 ;
{ Pname __1n ;

# 227 "/home/claude/cfront-3/src/norm2.cpp"
__1n = __1l -> head__5nlist ;

# 229 "/home/claude/cfront-3/src/norm2.cpp"
__dl__FPv ( (void *)__1l ) ;
return __1n ;

# 230 "/home/claude/cfront-3/src/norm2.cpp"
}
}

# 233 "/home/claude/cfront-3/src/norm2.cpp"
Pstmt stmt_unlist__FP5slist (Pslist __1l )
# 234 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 235 "/home/claude/cfront-3/src/norm2.cpp"
if (__1l == 0 )return (struct stmt *)0 ;
{ Pstmt __1s ;

# 236 "/home/claude/cfront-3/src/norm2.cpp"
__1s = __1l -> head__5slist ;

# 239 "/home/claude/cfront-3/src/norm2.cpp"
__dl__FPv ( (void *)__1l ) ;
return __1s ;

# 240 "/home/claude/cfront-3/src/norm2.cpp"
}
}

# 243 "/home/claude/cfront-3/src/norm2.cpp"
Pexpr expr_unlist__FP5elist (Pelist __1l )
# 244 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 245 "/home/claude/cfront-3/src/norm2.cpp"
if (__1l == 0 )return (struct expr *)0 ;
{ Pexpr __1e ;

# 246 "/home/claude/cfront-3/src/norm2.cpp"
__1e = __1l -> head__5elist ;

# 249 "/home/claude/cfront-3/src/norm2.cpp"
__dl__FPv ( (void *)__1l ) ;
return __1e ;

# 250 "/home/claude/cfront-3/src/norm2.cpp"
}
}

# 321 "/home/claude/cfront-3/src/cfront.h"
char *signature__4typeFPci (struct type *__0this , char *, int );

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 253 "/home/claude/cfront-3/src/norm2.cpp"
void sig_name__FP4name (Pname __1n )
# 254 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 255 "/home/claude/cfront-3/src/norm2.cpp"
static char __1buf [1024];
(__1buf [0 ])= '_' ;
(__1buf [1 ])= '_' ;
(__1buf [2 ])= 'o' ;
(__1buf [3 ])= 'p' ;
{ char *__1p ;

# 260 "/home/claude/cfront-3/src/norm2.cpp"
__1p = signature__4typeFPci ( __1n -> __O1__4expr.tp , (char *)(__1buf + 4 ), 0 ) ;
if (255 < (__1p - __1buf ))error__FiPCc ( (int )'i' , (const char *)"sig_name():N buffer overflow") ;
# 261 "/home/claude/cfront-3/src/norm2.cpp"

# 262 "/home/claude/cfront-3/src/norm2.cpp"
{ char *__1s ;

# 262 "/home/claude/cfront-3/src/norm2.cpp"
__1s = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* ((__1p - __1buf )+ 1 ))) ));
strcpy ( __1s , (const char *)__1buf ) ;
__1n -> __O2__4expr.string = (const char *)__1s ;
__1n -> __O1__4expr.tp = 0 ;

# 265 "/home/claude/cfront-3/src/norm2.cpp"
}

# 265 "/home/claude/cfront-3/src/norm2.cpp"
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 268 "/home/claude/cfront-3/src/norm2.cpp"
Ptype tok_to_type__FUc (TOK __1b )
# 269 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 270 "/home/claude/cfront-3/src/norm2.cpp"
Ptype __1t ;
switch (__1b ){ 
# 272 "/home/claude/cfront-3/src/norm2.cpp"
case 5 :__1t = (struct type *)char_type ;

# 272 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 29 :__1t = (struct type *)short_type ;

# 273 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 22 :__1t = (struct type *)long_type ;

# 274 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 122 :__1t = (struct type *)llong_type ;

# 275 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 37 :__1t = (struct type *)uint_type ;

# 276 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 15 :__1t = (struct type *)float_type ;

# 277 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 11 :__1t = (struct type *)double_type ;

# 278 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 181 :__1t = (struct type *)ldouble_type ;

# 279 "/home/claude/cfront-3/src/norm2.cpp"
break ;
case 38 :__1t = (struct type *)void_type ;

# 280 "/home/claude/cfront-3/src/norm2.cpp"
break ;
default :{ 
# 281 "/home/claude/cfront-3/src/norm2.cpp"
struct ea __0__V29 ;

# 281 "/home/claude/cfront-3/src/norm2.cpp"
error__FPCcRC2eaN32 ( (const char *)"illegalK:%k", (const struct ea *)( (( ((& __0__V29 )->
# 281 "/home/claude/cfront-3/src/norm2.cpp"
__O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V29 )) , (const struct ea *)ea0 , (const struct
# 281 "/home/claude/cfront-3/src/norm2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
case 21 :__1t = (struct type *)int_type ;
} }
return __1t ;
}

# 287 "/home/claude/cfront-3/src/norm2.cpp"
Pbase defa_type = 0 ;
Pbase moe_type = 0 ;
Pexpr dummy = 0 ;
Pexpr zero = 0 ;

# 292 "/home/claude/cfront-3/src/norm2.cpp"
Pclass ccl = 0 ;

# 294 "/home/claude/cfront-3/src/norm2.cpp"
Plist local_class = 0 ;

# 296 "/home/claude/cfront-3/src/norm2.cpp"
void memptrdcl__FP4nameT1P4typeT1 (Pname __1bn , Pname __1tn , Ptype __1ft , Pname __1n )
# 297 "/home/claude/cfront-3/src/norm2.cpp"
{ 
# 298 "/home/claude/cfront-3/src/norm2.cpp"
Pptr __1p ;

# 298 "/home/claude/cfront-3/src/norm2.cpp"
__1p = __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (struct type *)0 ) ;
__1p -> memof__3ptr = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1bn -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))));
{ Pbase __1b ;

# 300 "/home/claude/cfront-3/src/norm2.cpp"
__1b = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )97 , __1tn ) ;
__1p -> permanent__4node = 1 ;
{ Pfct __1f ;
Ptype __1t ;

# 302 "/home/claude/cfront-3/src/norm2.cpp"
__1f = (((struct fct *)(((struct fct *)__1ft ))));
__1t = __1n -> __O1__4expr.tp ;
if (__1t ){ 
# 305 "/home/claude/cfront-3/src/norm2.cpp"
__1p -> typ__5pvtyp = __1t ;
ltlt :
# 307 "/home/claude/cfront-3/src/norm2.cpp"
switch (__1t -> base__4node ){ 
# 308 "/home/claude/cfront-3/src/norm2.cpp"
case 125 :
# 309 "/home/claude/cfront-3/src/norm2.cpp"
case 158 :
# 310 "/home/claude/cfront-3/src/norm2.cpp"
case 110 :
# 311 "/home/claude/cfront-3/src/norm2.cpp"
if ((((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp == 0 ){ 
# 312 "/home/claude/cfront-3/src/norm2.cpp"
(((struct ptr *)(((struct
# 312 "/home/claude/cfront-3/src/norm2.cpp"
ptr *)__1t ))))-> typ__5pvtyp = (struct type *)__1b ;
break ;
}
__1t = (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp ;
goto ltlt ;
default :
# 318 "/home/claude/cfront-3/src/norm2.cpp"
error__FiPCc ( (int )'s' , (const char *)"P toMFT too complicated") ;
}
}
else 
# 322 "/home/claude/cfront-3/src/norm2.cpp"
__1p -> typ__5pvtyp = (struct type *)__1b ;
__1f -> returns__3fct = (struct type *)__1p ;
__1n -> __O1__4expr.tp = (struct type *)__1f ;

# 324 "/home/claude/cfront-3/src/norm2.cpp"
}

# 324 "/home/claude/cfront-3/src/norm2.cpp"
}
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

# 325 "/home/claude/cfront-3/src/norm2.cpp"

/* the end */
