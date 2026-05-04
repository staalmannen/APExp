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

# 39 "gram.y"
int in_friend = 0 ;
int must_be_friend = 0 ;
int dont_instantiate = 0 ;
static int explicit_template_definition = 0 ;
Pname righttname = 0 ;
struct parstate;

# 46 "gram.y"
struct parstate {	/* sizeof parstate == 32 */
Ptype intypedef__8parstate ;
int infriend__8parstate ;
int defercheck__8parstate ;
Pname intag__8parstate ;
int cid__8parstate ;
};

# 52 "gram.y"
static struct parstate pstate [128];
static int px ;
extern int classid ;

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

# 267 "/home/claude/cfront-3/src/cfront.h"
const char *whereami__6ktableFv (struct ktable *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 56 "gram.y"
static void SAVE_STATE__Fv (void )
# 57 "gram.y"
{ 
# 57 "gram.y"
const void *__2__X27 ;

# 59 "gram.y"
if (px >= 128 ){ 
# 59 "gram.y"
struct ea __0__V26 ;

# 59 "gram.y"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"parsing state stack overflow -- current table %s", (const struct ea *)( (__2__X27 =
# 59 "gram.y"
(const void *)whereami__6ktableFv ( Ctbl ) ), ( ((& __0__V26 )-> __O1__2ea.p = __2__X27 ), (& __0__V26 )) ) ,
# 59 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} (pstate [px ]). intypedef__8parstate = in_typedef ;
(pstate [px ]). infriend__8parstate = in_friend ;
in_typedef = 0 ;
in_friend = 0 ;
(pstate [px ]). defercheck__8parstate = defer_check ;
defer_check = 0 ;
(pstate [px ]). intag__8parstate = in_tag ;
in_tag = 0 ;
(pstate [px ]). cid__8parstate = classid ;
classid = 0 ;
++ px ;
}

# 75 "/home/claude/cfront-3/src/cfront.h"

# 73 "gram.y"
static void RESTORE_STATE__Fv (void )
# 74 "gram.y"
{ 
# 74 "gram.y"
const void *__2__X29 ;

# 76 "gram.y"
if ((-- px )< 0 ){ 
# 76 "gram.y"
struct ea __0__V28 ;

# 76 "gram.y"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"parsing state stack underflow -- current table %s", (const struct ea *)( (__2__X29 =
# 76 "gram.y"
(const void *)whereami__6ktableFv ( Ctbl ) ), ( ((& __0__V28 )-> __O1__2ea.p = __2__X29 ), (& __0__V28 )) ) ,
# 76 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} in_typedef = (pstate [px ]). intypedef__8parstate ;
in_friend = (pstate [px ]). infriend__8parstate ;
defer_check = (pstate [px ]). defercheck__8parstate ;
in_tag = (pstate [px ]). intag__8parstate ;
classid = (pstate [px ]). cid__8parstate ;

# 83 "gram.y"
}

# 254 "/home/claude/cfront-3/src/cfront.h"
struct ktable *__ct__6ktableFiP6ktableP4name (struct ktable *__0this , int , Pktab , Pname );

# 328 "/home/claude/cfront-3/src/cfront.h"
Pclass classtype__4typeFv (struct type *__0this );

# 263 "/home/claude/cfront-3/src/cfront.h"
void expand__6ktableFi (struct ktable *__0this , int );

# 258 "/home/claude/cfront-3/src/cfront.h"

# 255 "/home/claude/cfront-3/src/cfront.h"
void __dt__6ktableFv (struct ktable *__0this , int );
struct pcontext;

# 148 "gram.y"
struct pcontext {	/* sizeof pcontext == 16 */
Pktab ktbl__8pcontext ;
int saved_template__8pcontext ;
};
static struct pcontext scopestack [128];
static int scopex = 0 ;

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 155 "gram.y"
Pname SET_SCOPE__FP4name (Pname __1n )
# 156 "gram.y"
{ 
# 157 "gram.y"
Pktab __1ntb ;

# 158 "gram.y"
const void *__2__X32 ;

# 158 "gram.y"
if (__1n == 0 )__1ntb = 0 ;
else if (__1n == sta_name )__1ntb = Gtbl ;
else if (__1n -> n_template_arg__4name == 1){ 
# 161 "gram.y"
;
return __1n ;
}
else if (__1n -> __O1__4expr.tp ){ 
# 165 "gram.y"
Ptype __2t ;

# 165 "gram.y"
__2t = skiptypedefs__4typeFv ( __1n -> __O1__4expr.tp ) ;
if (__2t -> base__4node == 119 )__1ntb = classtype__4typeFv ( __2t ) -> k_tbl__8classdef ;
else __1ntb = 0 ;
}
else 
# 168 "gram.y"
__1ntb = 0 ;
;
if (__1ntb == 0 )return (struct name *)0 ;
if (scopex >= 128 ){ 
# 171 "gram.y"
struct ea __0__V30 ;

# 171 "gram.y"
struct ea __0__V31 ;

# 171 "gram.y"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"set scope %s: parsing scope stack overflow -- current table %s", (const struct ea *)( (__2__X32 =
# 171 "gram.y"
(const void *)whereami__6ktableFv ( __1ntb ) ), ( ((& __0__V30 )-> __O1__2ea.p = __2__X32 ), (& __0__V30 )) ) ,
# 171 "gram.y"
(const struct ea *)__ct__2eaFPCv ( & __0__V31 , (const void *)whereami__6ktableFv ( Ctbl ) ) , (const struct ea *)ea0 ,
# 171 "gram.y"
(const struct ea *)ea0 ) ;
} { Pktab __1tt ;

# 172 "gram.y"
__1tt = Ctbl ;
if (Ctbl -> k_id__6ktable == 185 ){ 
# 179 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;
__1tt -> k_next__6ktable = __1ntb -> k_next__6ktable ;
__1ntb -> k_next__6ktable = __1tt ;
(scopestack [scopex ]). saved_template__8pcontext = 1 ;
}
else if ((Ctbl -> k_id__6ktable == 136 )&& (Ctbl -> k_next__6ktable -> k_id__6ktable == 185 )){ 
# 188 "gram.y"
Ctbl = Ctbl -> k_next__6ktable -> k_next__6ktable ;
__1tt -> k_next__6ktable -> k_next__6ktable = __1ntb -> k_next__6ktable ;
__1ntb -> k_next__6ktable = __1tt -> k_next__6ktable ;
__1tt -> k_next__6ktable = __1ntb ;
(scopestack [scopex ]). saved_template__8pcontext = 1 ;
__1ntb = __1tt ;
}
(scopestack [(scopex ++ )]). ktbl__8pcontext = Ctbl ;
Ctbl = __1ntb ;
return __1n ;

# 197 "gram.y"
}
}

# 200 "gram.y"
void UNSET_SCOPE__Fv (void )
# 201 "gram.y"
{ 
# 203 "gram.y"
Pktab __1tt ;

# 204 "gram.y"
const void *__2__X35 ;

# 203 "gram.y"
__1tt = 0 ;
if ((-- scopex )< 0 ){ 
# 204 "gram.y"
struct ea __0__V33 ;

# 204 "gram.y"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"parsing scope stack underflow -- current scope %s", (const struct ea *)( (__2__X35 =
# 204 "gram.y"
(const void *)whereami__6ktableFv ( Ctbl ) ), ( ((& __0__V33 )-> __O1__2ea.p = __2__X35 ), (& __0__V33 )) ) ,
# 204 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if ((scopestack [scopex ]). saved_template__8pcontext ){ 
# 205 "gram.y"
const void *__2__X36 ;

# 206 "gram.y"
(scopestack [scopex ]). saved_template__8pcontext = 0 ;
if ((Ctbl -> k_next__6ktable == 0 )|| (Ctbl -> k_next__6ktable -> k_id__6ktable != 185 ))
# 208 "gram.y"
{ 
# 208 "gram.y"
struct ea __0__V34 ;

# 208 "gram.y"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"set scope failed restoring template table -- current table %s", (const struct ea *)( (__2__X36 =
# 208 "gram.y"
(const void *)whereami__6ktableFv ( Ctbl ) ), ( ((& __0__V34 )-> __O1__2ea.p = __2__X36 ), (& __0__V34 )) ) ,
# 208 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __1tt = Ctbl -> k_next__6ktable ;
Ctbl -> k_next__6ktable = __1tt -> k_next__6ktable ;
}
;
Ctbl = (scopestack [scopex ]). ktbl__8pcontext ;
if (__1tt ){ __1tt -> k_next__6ktable = Ctbl ;

# 214 "gram.y"
Ctbl = __1tt ;

# 214 "gram.y"
}
}

# 246 "gram.y"
static int init_seen = 0 ;
static int cdi = 0 ;
static Pnlist cd = 0 ;

# 248 "gram.y"
static Pnlist cd_vec [128];
static char stmt_seen = 0 ;

# 249 "gram.y"
static char stmt_vec [128];
static Pnlist scd [128];
static int scdp = -1;

# 253 "gram.y"
static Pname memptr_pn ;
static TOK memptr_tok ;

# 256 "gram.y"
static Pname err_name = 0 ;

# 259 "gram.y"
static Pcons templ_friends ;

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 266 "gram.y"
static bit decl_with_init__FP5nlist (Pnlist __1cd )
# 269 "gram.y"
{ 
# 270 "gram.y"
{ { Pname __1n ;

# 270 "gram.y"
__1n = __1cd -> head__5nlist ;

# 270 "gram.y"
for(;__1n ;__1n = __1n -> __O1__4name.n_list ) { 
# 271 "gram.y"
if (__1n -> __O3__4expr.n_initializer )return (unsigned char )1 ;
{ Pname __2cln ;

# 272 "gram.y"
__2cln = is_cl_obj__4typeFv ( __1n -> __O1__4expr.tp ) ;
if (__2cln && (((struct classdef *)(((struct classdef *)__2cln -> __O1__4expr.tp ))))-> c_ctor__8classdef )
# 274 "gram.y"
return (unsigned char )1 ;

# 274 "gram.y"
}
}
return (unsigned char )0 ;

# 276 "gram.y"
}

# 276 "gram.y"
}
}

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 80 "/home/claude/incl-linux32/stdio.h"
extern int sprintf (char *, const char *,...);

# 22 "/home/claude/incl-linux32/string.h"
extern int strncmp (const char *, const char *, size_t );

# 281 "gram.y"
static char *get_classname__FPCc (const char *__1s )
# 282 "gram.y"
{ 
# 284 "gram.y"
char *__1r ;

# 284 "gram.y"
__1r = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* (strlen ( __1s ) + 1 ))) ));
sprintf ( __1r , (const char *)"%s", __1s ) ;
{ char *__1s2 ;

# 288 "gram.y"
const char *__1s1 ;

# 286 "gram.y"
__1s2 = __1r ;

# 288 "gram.y"
__1s1 = __1s ;
while ((*__1s )){ 
# 290 "gram.y"
for(;(__1s [0 ])&& (((__1s [0 ])!= '_' )|| ((__1s [1 ])&& ((__1s [1 ])!= '_' )));__1s ++ ) __1s1 ++ ;

# 290 "gram.y"
;
if ((*__1s )){ 
# 292 "gram.y"
if (strncmp ( __1s , (const char *)"___pt__", (unsigned long
# 292 "gram.y"
)7 ) == 0 ){ 
# 293 "gram.y"
((*__1s2 ))= 0 ;
return __1r ;
}
if (strncmp ( __1s , (const char *)"__pt__", (unsigned long )6 ) ==
# 296 "gram.y"
0 ){ 
# 297 "gram.y"
((*__1s2 ))= '\0' ;
return __1r ;
}
}
return __1r ;
}
return __1r ;

# 303 "gram.y"
}
}

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 306 "gram.y"
static Pptr doptr__FUcT1 (TOK __1p , TOK __1t )
# 307 "gram.y"
{ 
# 308 "gram.y"
Pptr __1r ;

# 308 "gram.y"
__1r = __ct__3ptrFUcP4type ( (struct ptr *)0 , __1p , (struct type *)0 ) ;
switch (__1t ){ 
# 310 "gram.y"
case 26 :
# 311 "gram.y"
__1r -> b_const__4type = 1 ;

# 313 "gram.y"
break ;
case 170 :
# 315 "gram.y"
error__FiPCc ( (int )'w' , (const char *)"\"volatile\" not implemented (ignored)") ;
break ;
default :
# 318 "gram.y"
{ 
# 318 "gram.y"
struct ea __0__V41 ;

# 318 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"syntax error: *%k", (const struct ea *)( (( ((& __0__V41 )->
# 318 "gram.y"
__O1__2ea.i = ((unsigned long )__1t )), 0 ) ), (& __0__V41 )) , (const struct ea *)ea0 , (const struct
# 318 "gram.y"
ea *)ea0 , (const struct ea *)ea0 ) ;
} }
return __1r ;
}

# 870 "/home/claude/cfront-3/src/cfront.h"

# 113 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_name__FPCcP6ktableUc (const char *, Pktab , TOK );

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

# 76 "/home/claude/cfront-3/src/cfront.h"

# 323 "gram.y"
static Pbcl dobase__FUcP4nameT1 (TOK __1pr , Pname __1n , TOK __1v )
# 324 "gram.y"
{ 
# 327 "gram.y"
Pbcl __1b ;

# 328 "gram.y"
register struct basecl *__0__X46 ;

# 328 "gram.y"
struct basecl *__2__X47 ;

# 328 "gram.y"
struct node *__0__X9 ;

# 327 "gram.y"
__1b = ( (__0__X46 = 0 ), ( (__2__X47 = 0 ), ( ((__0__X46 || (__0__X46 = (struct basecl *)__nw__FUl ( (unsigned long
# 327 "gram.y"
)(sizeof (struct basecl))) ))?( (__0__X46 = (struct basecl *)( (__0__X9 = (((struct node *)__0__X46 ))), ( ((__0__X9 || (__0__X9 = (struct node *)__nw__FUl (
# 327 "gram.y"
(size_t )(sizeof (struct node))) ))?( ( (__0__X9 -> base__4node = 0 ), (__0__X9 -> permanent__4node = 0 )) , (__0__X9 ->
# 327 "gram.y"
baseclass__4node = 0 )) :0 ), __0__X9 ) ) ), ( (__0__X46 -> baseclass__4node = 1 ), ( (__0__X46 -> bclass__6basecl = ((struct
# 327 "gram.y"
classdef *)0 )), ( (__0__X46 -> next__6basecl = __2__X47 ), ( (__0__X46 -> promoted__6basecl = 0 ), ( (__0__X46 -> init__6basecl = 0 ), (
# 327 "gram.y"
(__0__X46 -> obj_offset__6basecl = (__0__X46 -> ptr_offset__6basecl = 0 )), (__0__X46 -> allocated__6basecl = 0 )) ) ) ) ) ) )
# 327 "gram.y"
:0 ), __0__X46 ) ) ) ;
__1b -> ppp__6basecl = __1pr ;

# 330 "gram.y"
if (__1n ){ 
# 331 "gram.y"
if (__1n -> base__4node != 123 ){ 
# 332 "gram.y"
Pname __3nn ;

# 332 "gram.y"
__3nn = k_find_name__FPCcP6ktableUc ( __1n -> __O2__4expr.string , Ctbl , (unsigned char )159 ) ;
if (__3nn == 0 ){ 
# 334 "gram.y"
{ 
# 334 "gram.y"
struct ea __0__V42 ;

# 334 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"BN%n not aTN", (const struct ea *)( ((& __0__V42 )-> __O1__2ea.p =
# 334 "gram.y"
((const void *)__1n )), (& __0__V42 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 334 "gram.y"
ea *)ea0 ) ;
return (struct basecl *)0 ;
} }
else __1n = __3nn ;
}

# 340 "gram.y"
{ Pbase __2bt ;

# 340 "gram.y"
__2bt = (((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp ))));
while (__2bt -> base__4node == 97 )__2bt = (((struct basetype *)(((struct basetype *)__2bt -> b_name__8basetype -> __O1__4expr.tp ))));

# 343 "gram.y"
if (__2bt -> base__4node != 119 ){ 
# 345 "gram.y"
if ((in_progress__17templ_compilation == 1)&& (__2bt -> base__4node == 141 ))
# 346 "gram.y"
{ 
# 346 "gram.y"
struct ea __0__V43 ;

# 346 "gram.y"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"formalTZ%n used asBC ofY", (const struct ea *)( ((&
# 346 "gram.y"
__0__V43 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V43 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 346 "gram.y"
(const struct ea *)ea0 ) ;
} else { 
# 347 "gram.y"
struct ea __0__V44 ;

# 347 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"BN%n not aCN", (const struct ea *)( ((& __0__V44 )-> __O1__2ea.p =
# 347 "gram.y"
((const void *)__1n )), (& __0__V44 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 347 "gram.y"
ea *)ea0 ) ;
} return (struct basecl *)0 ;
}

# 351 "gram.y"
if (__1v ){ 
# 352 "gram.y"
if (__1v != 77 ){ 
# 352 "gram.y"
struct ea __0__V45 ;

# 352 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"syntax error:%k inBCD", (const struct ea *)( (( ((& __0__V45 )->
# 352 "gram.y"
__O1__2ea.i = ((unsigned long )__1v )), 0 ) ), (& __0__V45 )) , (const struct ea *)ea0 , (const struct
# 352 "gram.y"
ea *)ea0 , (const struct ea *)ea0 ) ;
} __1b -> base__4node = 77 ;
}
else 
# 356 "gram.y"
__1b -> base__4node = 85 ;

# 358 "gram.y"
__1b -> bclass__6basecl = (((struct classdef *)(((struct classdef *)__2bt -> b_name__8basetype -> __O1__4expr.tp ))));

# 358 "gram.y"
}
}

# 361 "gram.y"
return __1b ;
}
union YYSTYPE;

# 509 "gram.y"
typedef union YYSTYPE YYSTYPE ;

# 491 "gram.y"
union YYSTYPE {	/* sizeof YYSTYPE == 8 */
const char *s__7YYSTYPE ;
TOK t__7YYSTYPE ;
int i__7YYSTYPE ;
struct loc l__7YYSTYPE ;
Pname pn__7YYSTYPE ;
Ptype pt__7YYSTYPE ;
Pexpr pe__7YYSTYPE ;
Pstmt ps__7YYSTYPE ;
Pbase pb__7YYSTYPE ;
Pnlist nl__7YYSTYPE ;
Pslist sl__7YYSTYPE ;
Pelist el__7YYSTYPE ;
Pbcl pbc__7YYSTYPE ;
Pptr pp__7YYSTYPE ;
PP p__7YYSTYPE ;
Plist pl__7YYSTYPE ;
struct toknode *q__7YYSTYPE ;
};

# 31 "/home/claude/cfront-3/src/tqueue.h"
void *__nw__7toknodeSFUl (size_t );
void __dl__7toknodeSFPvUl (void *, size_t );

# 35 "/home/claude/cfront-3/src/tqueue.h"
extern struct toknode *front ;

# 43 "/home/claude/cfront-3/src/tqueue.h"
extern int yychar ;
extern union YYSTYPE yylval ;

# 512 "gram.y"
extern union YYSTYPE yylval ;

# 512 "gram.y"
extern union YYSTYPE yyval ;

# 516 "gram.y"
extern int declTag ;
int in_sizeof = 0 ;
int in_new = 0 ;
Ptype in_typedef = 0 ;
Pname in_tag = 0 ;
extern int defer_check ;

# 523 "gram.y"
extern int must_be_id ;
int DECL_TYPE = 0 ;
int in_arg_list = 0 ;
static int in_binit_list = 0 ;
int in_class_decl = 0 ;
int parsing_class_members = 0 ;
int in_mem_fct = 0 ;
Ptempl_inst pti = 0 ;

# 513 "gram.y"
extern int yyparse__Fv (void );

# 537 "gram.y"
Pname syn__Fv (void )
# 538 "gram.y"
{ 
# 539 "gram.y"
ll :
# 540 "gram.y"
switch (yyparse__Fv ( ) ){ 
# 541 "gram.y"
case 0 :return (struct name *)0 ;
case 1 :goto ll ;
default :return yyval . pn__7YYSTYPE ;
}
}

# 675 "y.tab.c"
typedef int YYINT ;
static const YYINT yylhs [415]= { - 1 , 0 , 0 , 0 , 0 , 0 , 0 , 83 , 85 ,
# 676 "y.tab.c"
86 , 82 , 66 , 66 , 66 , 66 , 66 , 72 , 72 , 1 , 1 , 1 , 1 , 1 ,
# 676 "y.tab.c"
2 , 2 , 88 , 4 , 4 , 4 , 89 , 3 , 3 , 3 , 90 , 71 , 87 , 91 ,
# 676 "y.tab.c"
6 , 6 , 7 , 7 , 8 , 8 , 5 , 5 , 24 , 92 , 24 , 24 , 93 , 24 ,
# 676 "y.tab.c"
25 , 25 , 9 , 9 , 94 , 95 , 64 , 64 , 64 , 13 , 13 , 13 , 13 , 13 ,
# 676 "y.tab.c"
13 , 13 , 12 , 12 , 12 , 12 , 12 , 12 , 57 , 81 , 81 , 56 , 56 , 56 ,
# 676 "y.tab.c"
56 , 56 , 55 , 80 , 80 , 19 , 19 , 19 , 96 , 14 , 97 , 14 , 14 , 15 ,
# 676 "y.tab.c"
15 , 84 , 84 , 84 , 98 , 98 , 48 , 48 , 48 , 48 , 48 , 16 , 99 , 16 ,
# 676 "y.tab.c"
16 , 101 , 21 , 21 , 21 , 21 , 100 , 100 , 74 , 74 , 75 , 75 , 76 , 76 ,
# 676 "y.tab.c"
76 , 76 , 76 , 20 , 20 , 20 , 17 , 17 , 18 , 18 , 22 , 22 , 22 , 23 ,
# 676 "y.tab.c"
23 , 23 , 23 , 23 , 23 , 23 , 23 , 26 , 26 , 26 , 26 , 69 , 69 , 69 ,
# 676 "y.tab.c"
69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 ,
# 676 "y.tab.c"
69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 , 69 , 62 , 60 , 60 ,
# 676 "y.tab.c"
63 , 63 , 77 , 77 , 77 , 79 , 79 , 27 , 27 , 27 , 27 , 27 , 27 , 27 ,
# 676 "y.tab.c"
27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 27 , 47 , 47 , 47 ,
# 676 "y.tab.c"
47 , 47 , 47 , 47 , 53 , 53 , 53 , 42 , 42 , 42 , 42 , 42 , 44 , 44 ,
# 676 "y.tab.c"
29 , 29 , 29 , 30 , 31 , 58 , 102 , 32 , 32 , 32 , 34 , 34 , 34 , 34 ,
# 676 "y.tab.c"
103 , 34 , 34 , 105 , 104 , 33 , 33 , 33 , 33 , 33 , 33 , 33 , 33 , 33 ,
# 676 "y.tab.c"
33 , 106 , 33 , 107 , 33 , 108 , 33 , 109 , 33 , 110 , 33 , 111 , 33 , 33 ,
# 676 "y.tab.c"
67 , 67 , 68 , 73 , 73 , 36 , 35 , 35 , 28 , 28 , 38 , 38 , 38 , 38 ,
# 676 "y.tab.c"
38 , 38 , 38 , 38 , 38 , 38 , 38 , 38 , 38 , 38 , 38 , 38 , 38 , 38 ,
# 676 "y.tab.c"
38 , 38 , 38 , 38 , 38 , 38 , 38 , 37 , 37 , 37 , 37 , 37 , 37 , 37 ,
# 676 "y.tab.c"
37 , 37 , 37 , 37 , 37 , 37 , 37 , 37 , 37 , 37 , 37 , 37 , 37 , 37 ,
# 676 "y.tab.c"
37 , 37 , 37 , 37 , 37 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 ,
# 676 "y.tab.c"
39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 ,
# 676 "y.tab.c"
39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 , 39 ,
# 676 "y.tab.c"
39 , 39 , 39 , 61 , 61 , 61 , 61 , 61 , 61 , 61 , 61 , 41 , 41 , 41 ,
# 676 "y.tab.c"
41 , 41 , 41 , 41 , 65 , 59 , 59 , 59 , 40 , 40 , 40 , 43 , 112 , 46 ,
# 676 "y.tab.c"
46 , 46 , 46 , 45 , 54 , 50 , 113 , 50 , 78 , 51 , 52 , 52 , 49 , 49 ,
# 676 "y.tab.c"
70 , 70 , 70 , 11 , 11 , 11 , 11 , 11 , 11 , 11 , 11 , 11 , 10 , 10 }
# 676 "y.tab.c"
;

# 720 "y.tab.c"
static const YYINT yylen [415]= { 2 , 1 , 1 , 1 , 2 , 1 , 1 , 0 , 0 , 0 ,
# 720 "y.tab.c"
8 , 1 , 1 , 1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 5 , 4 ,
# 720 "y.tab.c"
2 , 0 , 7 , 5 , 5 , 0 , 6 , 4 , 4 , 0 , 4 , 0 , 0 , 3 ,
# 720 "y.tab.c"
0 , 1 , 3 , 3 , 4 , 2 , 0 , 1 , 0 , 4 , 2 , 0 , 4 , 1 ,
# 720 "y.tab.c"
3 , 3 , 2 , 1 , 1 , 1 , 4 , 4 , 1 , 1 , 1 , 2 , 1 , 1 ,
# 720 "y.tab.c"
1 , 1 , 2 , 2 , 2 , 2 , 2 , 1 , 3 , 1 , 0 , 3 , 2 , 2 ,
# 720 "y.tab.c"
2 , 2 , 1 , 1 , 1 , 1 , 2 , 0 , 5 , 0 , 6 , 2 , 1 , 3 ,
# 720 "y.tab.c"
3 , 1 , 0 , 2 , 2 , 1 , 2 , 2 , 2 , 3 , 1 , 0 , 4 , 0 ,
# 720 "y.tab.c"
0 , 5 , 2 , 5 , 2 , 0 , 2 , 2 , 0 , 1 , 3 , 1 , 2 , 2 ,
# 720 "y.tab.c"
3 , 3 , 2 , 4 , 7 , 1 , 1 , 1 , 1 , 2 , 0 , 2 , 1 , 2 ,
# 720 "y.tab.c"
2 , 1 , 1 , 1 , 2 , 3 , 1 , 2 , 2 , 2 , 1 , 1 , 1 , 1 ,
# 720 "y.tab.c"
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 1 , 1 ,
# 720 "y.tab.c"
1 , 1 , 1 , 1 , 3 , 1 , 3 , 1 , 1 , 1 , 1 , 1 , 2 , 2 ,
# 720 "y.tab.c"
1 , 0 , 2 , 5 , 1 , 3 , 2 , 4 , 2 , 4 , 6 , 6 , 4 , 4 ,
# 720 "y.tab.c"
6 , 1 , 3 , 2 , 4 , 2 , 2 , 2 , 2 , 3 , 1 , 2 , 0 , 2 ,
# 720 "y.tab.c"
2 , 2 , 3 , 0 , 2 , 2 , 0 , 2 , 2 , 4 , 4 , 0 , 2 , 0 ,
# 720 "y.tab.c"
2 , 2 , 2 , 0 , 3 , 0 , 4 , 2 , 3 , 1 , 1 , 1 , 2 , 0 ,
# 720 "y.tab.c"
5 , 4 , 0 , 2 , 2 , 1 , 3 , 3 , 1 , 1 , 1 , 3 , 5 , 3 ,
# 720 "y.tab.c"
0 , 9 , 0 , 4 , 0 , 4 , 0 , 4 , 0 , 5 , 0 , 4 , 3 , 0 ,
# 720 "y.tab.c"
2 , 3 , 4 , 3 , 1 , 1 , 3 , 1 , 3 , 3 , 3 , 3 , 3 , 3 ,
# 720 "y.tab.c"
3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 5 , 3 ,
# 720 "y.tab.c"
2 , 5 , 3 , 6 , 1 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 ,
# 720 "y.tab.c"
3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 5 , 3 , 2 , 5 , 3 ,
# 720 "y.tab.c"
6 , 1 , 2 , 0 , 2 , 2 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 ,
# 720 "y.tab.c"
2 , 2 , 2 , 2 , 2 , 4 , 3 , 4 , 4 , 3 , 4 , 4 , 3 , 4 ,
# 720 "y.tab.c"
4 , 3 , 4 , 4 , 1 , 2 , 3 , 3 , 1 , 3 , 1 , 1 , 1 , 1 ,
# 720 "y.tab.c"
1 , 1 , 2 , 3 , 4 , 2 , 4 , 3 , 3 , 3 , 4 , 4 , 5 , 5 ,
# 720 "y.tab.c"
6 , 6 , 4 , 4 , 1 , 1 , 2 , 1 , 2 , 2 , 4 , 1 , 1 , 1 ,
# 720 "y.tab.c"
2 , 2 , 2 , 2 , 2 , 0 , 5 , 1 , 5 , 3 , 1 , 1 , 0 , 0 ,
# 720 "y.tab.c"
1 , 2 , 1 , 1 , 2 , 2 , 2 , 2 , 1 , 3 , 2 , 3 , 1 } ;
# 720 "y.tab.c"

# 764 "y.tab.c"
static const YYINT yydefred [709]= { 0 , 3 , 0 , 0 , 0 , 395 , 0 , 0 , 0 , 2 ,
# 764 "y.tab.c"
5 , 0 , 0 , 60 , 178 , 0 , 379 , 0 , 378 , 66 , 0 , 7 , 0 , 0 ,
# 764 "y.tab.c"
1 , 21 , 20 , 19 , 18 , 0 , 0 , 67 , 65 , 132 , 64 , 193 , 0 , 175 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 6 , 0 , 87 , 127 , 85 , 84 , 0 , 0 ,
# 764 "y.tab.c"
128 , 0 , 0 , 0 , 0 , 0 , 171 , 162 , 163 , 148 , 149 , 146 , 147 , 156 ,
# 764 "y.tab.c"
157 , 151 , 150 , 158 , 159 , 166 , 172 , 165 , 155 , 153 , 154 , 152 , 164 , 386 ,
# 764 "y.tab.c"
173 , 145 , 0 , 0 , 387 , 144 , 143 , 406 , 408 , 0 , 55 , 0 , 124 , 112 ,
# 764 "y.tab.c"
0 , 0 , 412 , 4 , 0 , 0 , 407 , 0 , 0 , 0 , 0 , 54 , 0 , 68 ,
# 764 "y.tab.c"
72 , 71 , 70 , 51 , 0 , 0 , 0 , 0 , 0 , 0 , 414 , 0 , 24 , 0 ,
# 764 "y.tab.c"
200 , 184 , 0 , 177 , 63 , 176 , 0 , 195 , 0 , 0 , 199 , 186 , 0 , 0 ,
# 764 "y.tab.c"
380 , 0 , 0 , 0 , 0 , 89 , 86 , 0 , 0 , 160 , 161 , 388 , 0 , 390 ,
# 764 "y.tab.c"
389 , 142 , 194 , 0 , 0 , 0 , 0 , 361 , 385 , 0 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
0 , 381 , 359 , 357 , 358 , 360 , 356 , 0 , 0 , 0 , 0 , 61 , 0 , 0 ,
# 764 "y.tab.c"
0 , 350 , 354 , 0 , 82 , 0 , 0 , 0 , 75 , 0 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
8 , 0 , 0 , 0 , 0 , 0 , 46 , 0 , 53 , 49 , 0 , 108 , 0 , 139 ,
# 764 "y.tab.c"
0 , 0 , 134 , 131 , 0 , 133 , 179 , 0 , 0 , 0 , 0 , 43 , 0 , 0 ,
# 764 "y.tab.c"
62 , 0 , 0 , 267 , 0 , 0 , 398 , 399 , 0 , 0 , 0 , 179 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 411 , 201 , 0 , 0 , 0 , 92 , 0 , 170 , 168 , 218 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 322 , 323 , 0 , 383 , 382 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 69 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 326 , 0 , 0 , 351 , 0 , 56 , 73 , 0 ,
# 764 "y.tab.c"
59 , 0 , 0 , 129 , 0 , 0 , 119 , 130 , 0 , 117 , 125 , 0 , 0 , 377 ,
# 764 "y.tab.c"
0 , 52 , 0 , 0 , 0 , 113 , 140 , 136 , 135 , 0 , 0 , 413 , 0 , 23 ,
# 764 "y.tab.c"
31 , 32 , 0 , 202 , 0 , 0 , 0 , 0 , 187 , 0 , 402 , 0 , 196 , 58 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 190 , 22 , 0 , 0 , 88 , 0 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 324 , 325 , 0 , 0 , 80 , 79 , 0 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
314 , 0 , 0 , 0 , 0 , 0 , 338 , 0 , 341 , 0 , 0 , 344 , 347 , 0 ,
# 764 "y.tab.c"
353 , 352 , 0 , 74 , 0 , 0 , 0 , 355 , 0 , 121 , 0 , 120 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 95 , 0 , 50 , 27 , 28 , 0 , 0 , 141 , 180 , 0 , 270 ,
# 764 "y.tab.c"
36 , 0 , 0 , 203 , 393 , 206 , 207 , 0 , 268 , 403 , 397 , 179 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 93 , 90 , 0 , 0 , 211 , 0 , 370 , 0 , 0 , 77 , 0 , 376 ,
# 764 "y.tab.c"
337 , 365 , 362 , 0 , 0 , 340 , 339 , 0 , 343 , 342 , 346 , 345 , 349 , 348 ,
# 764 "y.tab.c"
371 , 0 , 0 , 384 , 214 , 123 , 122 , 118 , 0 , 0 , 0 , 97 , 99 , 0 ,
# 764 "y.tab.c"
0 , 0 , 9 , 0 , 0 , 33 , 114 , 0 , 0 , 0 , 30 , 0 , 208 , 0 ,
# 764 "y.tab.c"
188 , 189 , 192 , 0 , 0 , 372 , 373 , 0 , 0 , 0 , 0 , 0 , 367 , 363 ,
# 764 "y.tab.c"
369 , 368 , 0 , 126 , 0 , 101 , 102 , 0 , 0 , 94 , 26 , 0 , 182 , 0 ,
# 764 "y.tab.c"
0 , 0 , 39 , 0 , 0 , 227 , 219 , 394 , 0 , 374 , 375 , 364 , 366 , 216 ,
# 764 "y.tab.c"
215 , 103 , 14 , 13 , 12 , 11 , 0 , 10 , 0 , 181 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
228 , 0 , 15 , 34 , 183 , 41 , 40 , 0 , 226 , 220 , 221 , 0 , 42 , 0 ,
# 764 "y.tab.c"
230 , 256 , 231 , 0 , 0 , 233 , 0 , 0 , 0 , 0 , 250 , 0 , 239 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 243 , 242 , 244 , 222 , 236 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
258 , 0 , 0 , 223 , 248 , 232 , 0 , 223 , 0 , 0 , 223 , 252 , 0 , 0 ,
# 764 "y.tab.c"
261 , 254 , 0 , 238 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 223 , 0 ,
# 764 "y.tab.c"
0 , 223 , 0 , 0 , 240 , 223 , 247 , 223 , 241 , 0 , 223 , 0 , 0 , 237 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 289 , 235 , 223 , 259 , 0 , 0 , 0 , 224 , 223 , 251 ,
# 764 "y.tab.c"
253 , 0 , 262 , 255 , 0 , 0 , 257 , 0 , 234 , 0 , 246 , 0 , 0 , 0 ,
# 764 "y.tab.c"
0 , 0 , 0 , 0 , 263 , 0 , 0 , 0 , 265 , 0 , 223 , 264 , 249 } ;
# 764 "y.tab.c"

# 837 "y.tab.c"
static const YYINT yydgoto [114]= { 23 , 24 , 25 , 26 , 27 , 121 , 431 , 529 , 530 , 217 ,
# 837 "y.tab.c"
122 , 29 , 176 , 31 , 32 , 240 , 241 , 94 , 310 , 50 , 33 , 34 , 115 , 209 ,
# 837 "y.tab.c"
111 , 112 , 35 , 36 , 223 , 557 , 566 , 567 , 496 , 592 , 593 , 224 , 225 , 216 ,
# 837 "y.tab.c"
594 , 178 , 179 , 180 , 408 , 181 , 149 , 81 , 82 , 337 , 486 , 226 , 227 , 123 ,
# 837 "y.tab.c"
228 , 358 , 252 , 182 , 270 , 303 , 605 , 37 , 196 , 396 , 184 , 40 , 197 , 53 ,
# 837 "y.tab.c"
549 , 649 , 684 , 85 , 343 , 492 , 483 , 694 , 190 , 312 , 313 , 328 , 134 , 527 ,
# 837 "y.tab.c"
186 , 187 , 44 , 98 , 418 , 316 , 522 , 221 , 424 , 334 , 525 , 494 , 318 , 321 ,
# 837 "y.tab.c"
191 , 304 , 140 , 242 , 419 , 352 , 425 , 323 , 534 , 601 , 615 , 616 , 641 , 607 ,
# 837 "y.tab.c"
647 , 650 , 597 , 638 , 188 , 497 } ;

# 851 "y.tab.c"
static const YYINT yysindex [709]= { 877 , 0 , - 20 , 735 , 1925 , 0 , - 88 , -
# 851 "y.tab.c"
52 , - 10 , 0 , 0 , 49 , 94 , 0 , 0 , 870 , 0 , 35 , 0 , 0 ,
# 851 "y.tab.c"
114 , 0 , 94 , 0 , 0 , 0 , 0 , 0 , 0 , 929 , 4059 , 0 , 0 , 0 ,
# 851 "y.tab.c"
0 , 0 , 757 , 0 , 437 , 67 , 94 , 319 , 77 , 2036 , 0 , 141 , 0 , 0 ,
# 851 "y.tab.c"
0 , 0 , 209 , 586 , 0 , 109 , 269 , 288 , 284 , 295 , 0 , 0 , 0 , 0 ,
# 851 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 851 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 1049 , 433 , 0 , 0 , 0 , 0 , 0 , 71 ,
# 851 "y.tab.c"
0 , 2015 , 0 , 0 , 224 , 94 , 0 , 0 , 315 , 2015 , 0 , 593 , 433 , 319 ,
# 851 "y.tab.c"
2176 , 0 , 37 , 0 , 0 , 0 , 0 , 0 , 474 , 630 , 319 , 3731 , 305 , 2176 ,
# 851 "y.tab.c"
0 , 2106 , 0 , 808 , 0 , 0 , 1103 , 0 , 0 , 0 , 360 , 0 , 2015 , 1210 ,
# 851 "y.tab.c"
0 , 0 , 808 , 278 , 0 , 436 , 319 , 379 , 365 , 0 , 0 , 393 , 407 , 0 ,
# 851 "y.tab.c"
0 , 0 , - 23 , 0 , 0 , 0 , 0 , 4634 , 572 , 1925 , 4934 , 0 , 0 ,
# 851 "y.tab.c"
4934 , 4934 , 4934 , 4934 , 4934 , 4934 , 0 , 0 , 0 , 0 , 0 , 0 , 4934 , 424 ,
# 851 "y.tab.c"
4934 , 299 , 0 , 3925 , 1782 , 1135 , 0 , 0 , 4934 , 0 , 302 , 84 , 431 , 0 ,
# 851 "y.tab.c"
88 , 2015 , 731 , 418 , 2015 , 0 , 88 , 424 , 7373 , 119 , 431 , 0 , 552 , 0 ,
# 851 "y.tab.c"
0 , 808 , 0 , 427 , 0 , 442 , 454 , 0 , 0 , 67 , 0 , 0 , 6538 , 2106 ,
# 851 "y.tab.c"
461 , 7373 , 0 , 4059 , 437 , 0 , 505 , 4421 , 0 , 464 , 520 , 0 , 0 , -
# 851 "y.tab.c"
32 , 71 , 88 , 0 , 5000 , 5084 , 2036 , 530 , 0 , 0 , 507 , 0 , 196 , 0 ,
# 851 "y.tab.c"
365 , 0 , 0 , 0 , 432 , 2176 , 585 , 1135 , 1045 , 0 , 0 , 1103 , 0 , 0 ,
# 851 "y.tab.c"
1135 , 4532 , 1135 , 1135 , 1135 , 1135 , 1135 , 1135 , 1135 , 2106 , 1135 , 4700 , 572 , 391 ,
# 851 "y.tab.c"
720 , 0 , 3 , 2176 , 2176 , 2176 , 2176 , 2176 , 2176 , 2176 , 2176 , 2176 , 2176 , 2176 ,
# 851 "y.tab.c"
2176 , 2176 , 2176 , 2176 , 2176 , 2176 , 2176 , 2176 , 2106 , 2176 , 23 , 710 , 0 , 1135 ,
# 851 "y.tab.c"
987 , 0 , 2106 , 0 , 0 , 2015 , 0 , 4523 , 4708 , 0 , 1039 , 695 , 0 , 0 ,
# 851 "y.tab.c"
539 , 0 , 0 , 88 , 1093 , 0 , 2176 , 0 , 630 , 2106 , 527 , 0 , 0 , 0 ,
# 851 "y.tab.c"
0 , 554 , - 28 , 0 , 564 , 0 , 0 , 0 , 559 , 0 , 1828 , 736 , 354 ,
# 851 "y.tab.c"
2106 , 0 , 504 , 0 , 603 , 0 , 0 , - 28 , 612 , 617 , 457 , 0 , 0 ,
# 851 "y.tab.c"
611 , 365 , 0 , 297 , 6584 , - 23 , 301 , 632 , 648 , 2176 , 1135 , 0 , 0 ,
# 851 "y.tab.c"
1103 , 720 , 0 , 0 , 678 , 521 , 1600 , 46 , 46 , - 18 , - 18 , 1395 ,
# 851 "y.tab.c"
2073 , 3889 , 2253 , 7100 , 7373 , 7373 , 7373 , - 18 , 1446 , 521 , 103 , 0 , 669 ,
# 851 "y.tab.c"
6630 , 1294 , 556 , 200 , 0 , 79 , 0 , 4 , 289 , 0 , 0 , 62 , 0 , 0 ,
# 851 "y.tab.c"
688 , 0 , 8 , 544 , 21 , 0 , 1738 , 0 , 1738 , 0 , 731 , 224 , 930 , 4463 ,
# 851 "y.tab.c"
124 , 0 , 7373 , 0 , 0 , 0 , 559 , 604 , 0 , 0 , 699 , 0 , 0 , 671 ,
# 851 "y.tab.c"
720 , 0 , 0 , 0 , 0 , 983 , 0 , 0 , 0 , 0 , 712 , 712 , 712 , 2176 ,
# 851 "y.tab.c"
0 , 0 , 4934 , 301 , 0 , 572 , 0 , 6676 , 718 , 0 , 2176 , 0 , 0 , 0 ,
# 851 "y.tab.c"
0 , 716 , 1863 , 0 , 0 , 2118 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 576 ,
# 851 "y.tab.c"
301 , 0 , 0 , 0 , 0 , 0 , 697 , 0 , 94 , 0 , 0 , 343 , 720 , 404 ,
# 851 "y.tab.c"
0 , 1093 , 671 , 0 , 0 , 369 , 729 , - 40 , 0 , 2106 , 0 , - 28 ,
# 851 "y.tab.c"
0 , 0 , 0 , 7373 , 1135 , 0 , 0 , 808 , 4934 , 572 , 2390 , 2293 , 0 , 0 ,
# 851 "y.tab.c"
0 , 0 , 720 , 0 , 720 , 0 , 0 , 1196 , 4233 , 0 , 0 , 559 , 0 , 31 ,
# 851 "y.tab.c"
2106 , 706 , 0 , 739 , 714 , 0 , 0 , 0 , 1135 , 0 , 0 , 0 , 0 , 0 ,
# 851 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 722 , 0 , 671 , 0 , 369 , 743 , 729 , 2106 ,
# 851 "y.tab.c"
0 , - 6 , 0 , 0 , 0 , 0 , 0 , 755 , 0 , 0 , 0 , 1633 , 0 ,
# 851 "y.tab.c"
765 , 0 , 0 , 0 , 754 , 4784 , 0 , 809 , 771 , 813 , 2176 , 0 , 813 , 0 ,
# 851 "y.tab.c"
799 , 9 , 4934 , 671 , 803 , 310 , 0 , 0 , 0 , 0 , 0 , 7328 , 1135 , 800 ,
# 851 "y.tab.c"
2176 , 0 , 2176 , 1135 , 0 , 0 , 0 , 2176 , 0 , 7146 , 813 , 0 , 0 , 671 ,
# 851 "y.tab.c"
1135 , 0 , 0 , 4850 , 0 , 810 , 2240 , 2240 , 2240 , 2240 , 2240 , 2240 , 2240 , 2240 ,
# 851 "y.tab.c"
2240 , 2240 , 2240 , 2240 , 2240 , 2240 , 2240 , 2240 , 2240 , 2240 , 2240 , 844 , 7191 , 0 ,
# 851 "y.tab.c"
6722 , 848 , 0 , 4858 , 880 , 0 , 0 , 0 , 0 , 0 , 796 , 0 , 2176 , 1135 ,
# 851 "y.tab.c"
0 , 728 , 1711 , 51 , 51 , 569 , 569 , 2089 , 4645 , 4911 , 2684 , 7237 , 7419 , 7419 ,
# 851 "y.tab.c"
7419 , 569 , 2188 , 728 , 285 , 0 , 0 , 0 , 0 , 4934 , 813 , 2176 , 0 , 0 ,
# 851 "y.tab.c"
0 , 0 , 856 , 0 , 0 , 6768 , 2240 , 0 , 1135 , 0 , 7282 , 0 , 756 , 671 ,
# 851 "y.tab.c"
808 , 4934 , 2566 , 2176 , 857 , 0 , 4421 , 1135 , 5008 , 0 , 1227 , 0 , 0 , 0 }
# 851 "y.tab.c"
;

# 924 "y.tab.c"
static const YYINT yyrindex [709]= { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 2337 , 2483 , 0 ,
# 924 "y.tab.c"
0 , 3689 , 0 , 0 , 0 , 0 , 0 , 2629 , 0 , 0 , 4111 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1995 , 0 ,
# 924 "y.tab.c"
534 , 0 , 2775 , 4275 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 3067 , 0 ,
# 924 "y.tab.c"
0 , 0 , 3437 , 3513 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 5205 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 7481 , 0 , 0 ,
# 924 "y.tab.c"
3141 , 3215 , 0 , 0 , 0 , 7481 , 0 , 1388 , 534 , 2526 , 2992 , 0 , 701 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 2964 , 4290 , 0 , 1847 , 6782 , 0 , 2992 , 0 , 406 ,
# 924 "y.tab.c"
0 , 0 , 6400 , 0 , 0 , 0 , 3689 , 0 , 7481 , 5254 , 0 , 0 , - 15 ,
# 924 "y.tab.c"
2921 , 0 , 0 , 0 , 0 , 326 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 5131 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 3777 , 0 , 81 , 0 , 479 ,
# 924 "y.tab.c"
258 , 5670 , 0 , 0 , 0 , 0 , 222 , 0 , 3629 , 0 , 0 , 6492 , 0 , 0 ,
# 924 "y.tab.c"
7481 , 0 , 0 , 0 , 607 , 222 , 0 , 0 , 0 , 0 , 0 , 406 , 0 , 0 ,
# 924 "y.tab.c"
0 , 3845 , 3877 , 0 , 0 , 0 , 0 , 0 , 0 , 7430 , 0 , 516 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 283 , 1005 , 0 , 25 , 0 , 0 , 0 , 871 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 495 , 0 , 0 , 326 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
6782 , 125 , 5724 , 5328 , 0 , 0 , 6492 , 0 , 0 , 5769 , 5625 , 5823 , 5868 , 5922 ,
# 924 "y.tab.c"
5967 , 6021 , 6066 , 6120 , 6492 , 6165 , 0 , 0 , 906 , 291 , 0 , 651 , 2850 , 2850 ,
# 924 "y.tab.c"
2850 , 2850 , 2850 , 2850 , 2850 , 2850 , 2850 , 2850 , 7467 , 2850 , 2850 , 2850 , 2850 , 2850 ,
# 924 "y.tab.c"
2850 , 2850 , 2850 , 6492 , 6782 , 0 , 0 , 0 , 6219 , 0 , 0 , 6492 , 0 , 0 ,
# 924 "y.tab.c"
7481 , 0 , 665 , 0 , 0 , 0 , 0 , 0 , 0 , 850 , 0 , 0 , 0 , 331 ,
# 924 "y.tab.c"
0 , 2992 , 0 , 627 , 2992 , 364 , 0 , 0 , 0 , 0 , 2727 , 3918 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 852 , 0 , 1005 , 18 , 874 , 6437 , 0 , 36 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 3994 , 5568 , 5568 , 0 , 0 , 0 , 0 , 326 , 0 , 0 , 0 , 5328 , 5385 ,
# 924 "y.tab.c"
0 , 0 , 6782 , 6264 , 0 , 0 , 6492 , 74 , 0 , 0 , 0 , 7526 , 3812 , 7628 ,
# 924 "y.tab.c"
7671 , 7741 , 7776 , 6501 , 3000 , 5461 , 5574 , 0 , 748 , 828 , 1436 , 7811 , 7843 , 7572 ,
# 924 "y.tab.c"
7706 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 241 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 665 , 665 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
3289 , 0 , 0 , 0 , 0 , 730 , 0 , 0 , 0 , 852 , 3363 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 97 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 7430 , 0 , 0 , 0 , 5451 , 0 , 0 , 0 , 0 , 0 , 0 , 2850 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 885 , 0 , 0 , 0 , 0 , 0 , 0 , 2291 , 4119 , 0 , 0 ,
# 924 "y.tab.c"
0 , 397 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 988 , 0 , 6455 , 0 ,
# 924 "y.tab.c"
3587 , 0 , 0 , 0 , 356 , 6318 , 0 , 0 , 0 , 0 , 0 , 1051 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 444 , 0 , 0 , 0 , 0 , 0 , 0 , 852 , 0 ,
# 924 "y.tab.c"
0 , 6492 , 859 , 0 , 0 , 0 , 0 , 0 , 0 , 6363 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 4352 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
6492 , 0 , 1744 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 2992 , 0 , 0 , 0 ,
# 924 "y.tab.c"
5508 , 4367 , 0 , 0 , 4173 , 81 , 0 , 0 , 0 , 0 , 0 , 849 , 6827 , 0 ,
# 924 "y.tab.c"
7467 , 0 , 6782 , 6873 , 0 , 0 , 0 , 6492 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
6918 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 1522 , 0 , 0 , 0 , 0 , 0 , 1342 , 0 , 6782 , 6964 ,
# 924 "y.tab.c"
0 , 7909 , 1672 , 7998 , 8039 , 8109 , 8138 , 2408 , 2661 , 1561 , 1963 , 0 , 41 , 596 ,
# 924 "y.tab.c"
741 , 8167 , 2520 , 7955 , 8074 , 0 , 0 , 0 , 0 , 0 , 0 , 2992 , 0 , 0 ,
# 924 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 7009 , 0 , 0 , 0 , 1288 , 0 ,
# 924 "y.tab.c"
0 , 0 , 1122 , 6492 , 0 , 0 , 874 , 7055 , 0 , 0 , 0 , 0 , 0 , 0 }
# 924 "y.tab.c"
;

# 997 "y.tab.c"
static const YYINT yygindex [114]= { 0 , 0 , - 115 , - 103 , - 106 , 817 , -
# 997 "y.tab.c"
382 , 0 , 383 , 6 , 217 , 298 , 73 , 0 , - 7 , 691 , 588 , 7 , -
# 997 "y.tab.c"
301 , 0 , 0 , - 16 , 0 , 0 , 740 , 0 , - 1 , 11 , - 101 ,
# 997 "y.tab.c"
0 , 3716 , 0 , - 469 , 0 , 0 , 0 , - 129 , 557 , 7319 , 703 , -
# 997 "y.tab.c"
120 , 0 , 330 , - 139 , 794 , 790 , 0 , - 325 , - 305 , 605 , 0 ,
# 997 "y.tab.c"
16 , 0 , 598 , - 243 , 0 , 250 , 0 , - 204 , - 5 , 1 , 661 ,
# 997 "y.tab.c"
50 , 215 , 233 , 22 , 0 , 0 , 0 , 804 , 0 , 0 , 0 , 0 , 543 , 0 ,
# 997 "y.tab.c"
547 , - 228 , 271 , 0 , 660 , 251 , 858 , 0 , 0 , 0 , 0 , 763 , 0 ,
# 997 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 252 , - 169 , 0 , 0 , 478 , 0 , 0 , 0 ,
# 997 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , - 135 , 0 } ;
# 997 "y.tab.c"

# 1012 "y.tab.c"
static const YYINT yytable [8260]= { 205 , 38 , 235 , 346 , 51 , 83 , 28 , 411 , 413 , 207 ,
# 1012 "y.tab.c"
49 , 432 , 206 , 437 , 110 , 251 , 83 , 257 , 215 , 253 , 45 , 524 , 42 , 109 ,
# 1012 "y.tab.c"
317 , 364 , 400 , 7 , 155 , 8 , 102 , 102 , 273 , 127 , 533 , 86 , 275 , 276 ,
# 1012 "y.tab.c"
129 , 341 , 101 , 113 , 490 , 5 , 102 , 87 , 127 , 155 , 406 , 265 , 39 , 42 ,
# 1012 "y.tab.c"
42 , 7 , 137 , 8 , 400 , 133 , 7 , 392 , 8 , 345 , 475 , 117 , 299 , 42 ,
# 1012 "y.tab.c"
266 , 118 , 564 , 427 , 391 , 428 , 551 , 30 , 100 , 289 , 290 , 400 , 127 , 39 ,
# 1012 "y.tab.c"
39 , 559 , 89 , 83 , 165 , 330 , 155 , 88 , 152 , 392 , 610 , 4 , 183 , 39 ,
# 1012 "y.tab.c"
89 , 4 , 273 , 127 , 591 , 266 , 183 , 617 , 552 , 165 , 42 , 379 , 198 , 400 ,
# 1012 "y.tab.c"
155 , 477 , 271 , 478 , 271 , 271 , 6 , 78 , 38 , 612 , 6 , 133 , 392 , 208 ,
# 1012 "y.tab.c"
219 , 342 , 359 , 183 , 465 , 466 , 379 , 363 , 133 , 183 , 96 , 365 , 78 , 219 ,
# 1012 "y.tab.c"
360 , 42 , 205 , 289 , 400 , 648 , 165 , 550 , 633 , 78 , 415 , 128 , 301 , 379 ,
# 1012 "y.tab.c"
17 , 151 , 90 , 273 , 133 , 219 , 83 , 275 , 276 , 302 , 110 , 379 , 291 , 389 ,
# 1012 "y.tab.c"
165 , 210 , 298 , 205 , 205 , 109 , 246 , 404 , 379 , 392 , 394 , 399 , 17 , 83 ,
# 1012 "y.tab.c"
127 , 565 , 518 , 17 , 521 , 16 , 488 , 470 , 22 , 97 , 30 , 183 , 83 , 127 ,
# 1012 "y.tab.c"
183 , 531 , 218 , 489 , 289 , 222 , 42 , 393 , 102 , 18 , 110 , 219 , 379 , 379 ,
# 1012 "y.tab.c"
110 , 222 , 506 , 327 , 320 , 109 , 22 , 499 , 127 , 109 , 532 , 22 , 52 , 102 ,
# 1012 "y.tab.c"
421 , 42 , 139 , 83 , 155 , 700 , 291 , 250 , 344 , 320 , 95 , 635 , 22 , 41 ,
# 1012 "y.tab.c"
110 , 102 , 454 , 84 , 438 , 16 , 42 , 379 , 125 , 109 , 42 , 349 , 174 , 462 ,
# 1012 "y.tab.c"
379 , 39 , 135 , 83 , 205 , 531 , 183 , 136 , 42 , 18 , 132 , 379 , 379 , 305 ,
# 1012 "y.tab.c"
103 , 114 , 91 , 174 , 538 , 353 , 39 , 219 , 354 , 43 , 42 , 464 , 99 , 218 ,
# 1012 "y.tab.c"
138 , 467 , 469 , 16 , 165 , 471 , 141 , 291 , 39 , 379 , 368 , 136 , 22 , 110 ,
# 1012 "y.tab.c"
379 , 246 , 130 , 189 , 246 , 395 , 395 , 18 , 109 , 83 , 43 , 43 , 174 , 379 ,
# 1012 "y.tab.c"
183 , 403 , 83 , 124 , 267 , 83 , 83 , 143 , 505 , 155 , 43 , 150 , 507 , 219 ,
# 1012 "y.tab.c"
83 , 614 , 132 , 174 , 268 , 463 , 185 , 145 , 305 , 42 , 22 , 83 , 144 , 132 ,
# 1012 "y.tab.c"
185 , 268 , 379 , 617 , 462 , 83 , 146 , 619 , 620 , 250 , 219 , 117 , 397 , 401 ,
# 1012 "y.tab.c"
212 , 118 , 41 , 298 , 193 , 81 , 29 , 436 , 220 , 132 , 29 , 185 , 42 , 131 ,
# 1012 "y.tab.c"
246 , 117 , 81 , 185 , 174 , 118 , 183 , 220 , 353 , 165 , 537 , 447 , 124 , 192 ,
# 1012 "y.tab.c"
507 , 236 , 705 , 608 , 633 , 246 , 148 , 230 , 368 , 5 , 124 , 368 , 43 , 220 ,
# 1012 "y.tab.c"
84 , 417 , 127 , 96 , 83 , 7 , 5 , 8 , 535 , 107 , 460 , 553 , 107 , 110 ,
# 1012 "y.tab.c"
96 , 645 , 7 , 229 , 8 , 544 , 124 , 271 , 109 , 83 , 468 , 83 , 222 , 83 ,
# 1012 "y.tab.c"
546 , 83 , 83 , 545 , 238 , 185 , 311 , 484 , 185 , 125 , 563 , 106 , 246 , 246 ,
# 1012 "y.tab.c"
106 , 5 , 138 , 25 , 335 , 220 , 243 , 25 , 305 , 42 , 100 , 7 , 315 , 8 ,
# 1012 "y.tab.c"
5 , 239 , 148 , 272 , 436 , 47 , 244 , 114 , 219 , 436 , 7 , 271 , 8 , 98 ,
# 1012 "y.tab.c"
500 , 501 , 502 , 589 , 16 , 83 , 265 , 635 , 83 , 138 , 98 , 513 , 43 , 300 ,
# 1012 "y.tab.c"
515 , 690 , 269 , 35 , 116 , 237 , 117 , 35 , 18 , 126 , 118 , 271 , 484 , 100 ,
# 1012 "y.tab.c"
185 , 367 , 100 , 43 , 219 , 314 , 14 , 338 , 83 , 83 , 324 , 116 , 444 , 117 ,
# 1012 "y.tab.c"
526 , 220 , 520 , 118 , 100 , 43 , 548 , 246 , 219 , 246 , 219 , 22 , 83 , 52 ,
# 1012 "y.tab.c"
325 , 100 , 17 , 3 , 540 , 366 , 336 , 76 , 369 , 38 , 250 , 76 , 326 , 17 ,
# 1012 "y.tab.c"
547 , 16 , 35 , 35 , 542 , 331 , 520 , 339 , 185 , 520 , 271 , 76 , 272 , 311 ,
# 1012 "y.tab.c"
311 , 272 , 42 , 199 , 200 , 18 , 357 , 220 , 76 , 433 , 22 , 83 , 435 , 83 ,
# 1012 "y.tab.c"
125 , 269 , 174 , 560 , 125 , 340 , 417 , 22 , 17 , 105 , 104 , 269 , 183 , 104 ,
# 1012 "y.tab.c"
269 , 350 , 39 , 590 , 220 , 450 , 4 , 17 , 22 , 351 , 305 , 174 , 250 , 367 ,
# 1012 "y.tab.c"
406 , 3 , 367 , 269 , 269 , 12 , 269 , 124 , 5 , 16 , 7 , 30 , 8 , 16 ,
# 1012 "y.tab.c"
185 , 6 , 22 , 13 , 7 , 407 , 8 , 135 , 52 , 338 , 268 , 338 , 414 , 18 ,
# 1012 "y.tab.c"
158 , 22 , 174 , 18 , 126 , 516 , 117 , 617 , 124 , 104 , 118 , 619 , 620 , 476 ,
# 1012 "y.tab.c"
426 , 14 , 430 , 332 , 333 , 482 , 106 , 116 , 336 , 117 , 336 , 12 , 429 , 118 ,
# 1012 "y.tab.c"
30 , 100 , 22 , 311 , 441 , 311 , 22 , 311 , 177 , 435 , 271 , 422 , 423 , 442 ,
# 1012 "y.tab.c"
435 , 357 , 177 , 12 , 443 , 439 , 15 , 195 , 633 , 634 , 16 , 287 , 450 , 287 ,
# 1012 "y.tab.c"
287 , 13 , 116 , 269 , 117 , 451 , 213 , 14 , 118 , 52 , 48 , 48 , 52 , 445 ,
# 1012 "y.tab.c"
18 , 19 , 220 , 110 , 175 , 177 , 487 , 452 , 476 , 476 , 76 , 76 , 109 , 14 ,
# 1012 "y.tab.c"
219 , 76 , 45 , 45 , 201 , 291 , 83 , 519 , 407 , 407 , 212 , 212 , 52 , 125 ,
# 1012 "y.tab.c"
457 , 212 , 16 , 22 , 142 , 485 , 461 , 17 , 5 , 455 , 117 , 436 , 220 , 42 ,
# 1012 "y.tab.c"
118 , 17 , 52 , 311 , 15 , 472 , 18 , 491 , 16 , 541 , 155 , 519 , 473 , 474 ,
# 1012 "y.tab.c"
519 , 493 , 220 , 142 , 220 , 142 , 495 , 306 , 16 , 142 , 177 , 635 , 18 , 19 ,
# 1012 "y.tab.c"
5 , 22 , 175 , 41 , 487 , 391 , 487 , 509 , 5 , 22 , 117 , 511 , 18 , 142 ,
# 1012 "y.tab.c"
118 , 52 , 701 , 528 , 517 , 142 , 142 , 142 , 142 , 307 , 5 , 554 , 117 , 555 ,
# 1012 "y.tab.c"
12 , 22 , 118 , 485 , 561 , 485 , 142 , 311 , 556 , 296 , 165 , 296 , 412 , 43 ,
# 1012 "y.tab.c"
558 , 22 , 568 , 116 , 142 , 117 , 185 , 47 , 47 , 118 , 356 , 596 , 434 , 392 ,
# 1012 "y.tab.c"
46 , 307 , 286 , 307 , 286 , 286 , 12 , 47 , 12 , 296 , 14 , 296 , 296 , 3 ,
# 1012 "y.tab.c"
296 , 598 , 142 , 142 , 142 , 119 , 308 , 120 , 370 , 371 , 372 , 373 , 374 , 375 ,
# 1012 "y.tab.c"
376 , 377 , 378 , 379 , 380 , 381 , 382 , 383 , 384 , 385 , 386 , 387 , 388 , 602 ,
# 1012 "y.tab.c"
390 , 603 , 14 , 604 , 14 , 16 , 249 , 142 , 14 , 256 , 177 , 142 , 258 , 259 ,
# 1012 "y.tab.c"
260 , 261 , 262 , 263 , 609 , 312 , 16 , 312 , 613 , 18 , 264 , 420 , 266 , 1 ,
# 1012 "y.tab.c"
2 , 142 , 142 , 636 , 653 , 142 , 297 , 673 , 398 , 677 , 18 , 16 , 3 , 16 ,
# 1012 "y.tab.c"
680 , 12 , 683 , 16 , 693 , 312 , 704 , 312 , 312 , 4 , 312 , 296 , 22 , 13 ,
# 1012 "y.tab.c"
309 , 18 , 635 , 18 , 142 , 699 , 401 , 18 , 48 , 204 , 204 , 5 , 453 , 22 ,
# 1012 "y.tab.c"
204 , 229 , 435 , 115 , 6 , 38 , 213 , 7 , 220 , 8 , 202 , 14 , 37 , 355 ,
# 1012 "y.tab.c"
271 , 260 , 261 , 562 , 22 , 319 , 22 , 446 , 245 , 92 , 22 , 254 , 440 , 76 ,
# 1012 "y.tab.c"
76 , 9 , 47 , 10 , 76 , 4 , 695 , 449 , 400 , 11 , 480 , 255 , 297 , 479 ,
# 1012 "y.tab.c"
12 , 405 , 15 , 322 , 76 , 523 , 16 , 5 , 362 , 0 , 338 , 211 , 13 , 0 ,
# 1012 "y.tab.c"
6 , 76 , 0 , 7 , 0 , 8 , 0 , 312 , 0 , 0 , 18 , 19 , 0 , 225 ,
# 1012 "y.tab.c"
175 , 225 , 225 , 14 , 0 , 225 , 225 , 225 , 225 , 336 , 14 , 225 , 503 , 92 ,
# 1012 "y.tab.c"
225 , 0 , 0 , 225 , 225 , 11 , 481 , 225 , 225 , 510 , 12 , 0 , 225 , 22 ,
# 1012 "y.tab.c"
225 , 0 , 0 , 225 , 225 , 5 , 498 , 117 , 100 , 225 , 225 , 118 , 16 , 0 ,
# 1012 "y.tab.c"
0 , 15 , 225 , 225 , 0 , 16 , 225 , 0 , 225 , 0 , 225 , 225 , 0 , 0 ,
# 1012 "y.tab.c"
204 , 204 , 18 , 93 , 17 , 204 , 14 , 14 , 0 , 18 , 19 , 0 , 3 , 20 ,
# 1012 "y.tab.c"
225 , 225 , 21 , 0 , 0 , 0 , 0 , 47 , 225 , 225 , 225 , 225 , 225 , 225 ,
# 1012 "y.tab.c"
225 , 204 , 204 , 0 , 0 , 22 , 0 , 0 , 0 , 225 , 402 , 225 , 22 , 225 ,
# 1012 "y.tab.c"
225 , 16 , 16 , 0 , 313 , 0 , 313 , 7 , 0 , 8 , 0 , 7 , 0 , 8 ,
# 1012 "y.tab.c"
17 , 0 , 0 , 0 , 3 , 18 , 18 , 93 , 14 , 225 , 153 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
3 , 0 , 0 , 307 , 313 , 313 , 313 , 313 , 12 , 313 , 154 , 155 , 0 , 0 ,
# 1012 "y.tab.c"
12 , 0 , 0 , 156 , 12 , 0 , 606 , 157 , 22 , 22 , 0 , 313 , 107 , 158 ,
# 1012 "y.tab.c"
225 , 0 , 147 , 16 , 225 , 159 , 160 , 504 , 0 , 161 , 637 , 162 , 639 , 163 ,
# 1012 "y.tab.c"
164 , 0 , 204 , 642 , 14 , 0 , 0 , 18 , 225 , 225 , 14 , 0 , 225 , 0 ,
# 1012 "y.tab.c"
14 , 225 , 0 , 292 , 214 , 293 , 12 , 294 , 295 , 0 , 0 , 165 , 166 , 167 ,
# 1012 "y.tab.c"
168 , 169 , 12 , 170 , 13 , 288 , 288 , 288 , 288 , 0 , 22 , 225 , 171 , 16 ,
# 1012 "y.tab.c"
172 , 15 , 173 , 0 , 0 , 16 , 313 , 0 , 686 , 16 , 0 , 536 , 288 , 0 ,
# 1012 "y.tab.c"
410 , 0 , 14 , 18 , 17 , 153 , 0 , 0 , 17 , 18 , 108 , 0 , 14 , 18 ,
# 1012 "y.tab.c"
0 , 0 , 296 , 0 , 0 , 154 , 155 , 691 , 5 , 543 , 117 , 0 , 156 , 0 ,
# 1012 "y.tab.c"
118 , 0 , 157 , 0 , 0 , 0 , 22 , 416 , 158 , 231 , 0 , 16 , 22 , 703 ,
# 1012 "y.tab.c"
159 , 160 , 22 , 15 , 232 , 0 , 233 , 174 , 163 , 164 , 0 , 5 , 707 , 117 ,
# 1012 "y.tab.c"
595 , 18 , 19 , 118 , 0 , 175 , 0 , 600 , 0 , 0 , 0 , 18 , 19 , 214 ,
# 1012 "y.tab.c"
0 , 175 , 0 , 0 , 611 , 0 , 165 , 166 , 167 , 168 , 169 , 12 , 170 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 395 , 22 , 0 , 0 , 171 , 0 , 0 , 0 , 173 , 0 , 0 ,
# 1012 "y.tab.c"
22 , 0 , 0 , 0 , 0 , 652 , 0 , 0 , 595 , 595 , 595 , 595 , 595 , 595 ,
# 1012 "y.tab.c"
595 , 595 , 595 , 595 , 595 , 595 , 595 , 595 , 595 , 595 , 595 , 595 , 595 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 260 , 0 , 260 , 260 , 0 , 0 , 260 , 260 , 260 , 260 , 0 ,
# 1012 "y.tab.c"
260 , 260 , 0 , 0 , 260 , 0 , 0 , 260 , 260 , 0 , 0 , 260 , 260 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 260 , 0 , 260 , 395 , 47 , 260 , 260 , 0 , 0 , 689 , 0 , 260 ,
# 1012 "y.tab.c"
260 , 234 , 0 , 395 , 0 , 0 , 260 , 260 , 595 , 459 , 260 , 0 , 260 , 0 ,
# 1012 "y.tab.c"
260 , 260 , 0 , 702 , 260 , 197 , 260 , 0 , 0 , 0 , 260 , 260 , 260 , 260 ,
# 1012 "y.tab.c"
260 , 395 , 260 , 260 , 260 , 260 , 260 , 14 , 0 , 22 , 0 , 0 , 260 , 260 ,
# 1012 "y.tab.c"
260 , 260 , 260 , 260 , 260 , 197 , 0 , 0 , 260 , 260 , 260 , 260 , 260 , 260 ,
# 1012 "y.tab.c"
0 , 260 , 0 , 260 , 260 , 0 , 395 , 273 , 0 , 274 , 395 , 275 , 276 , 0 ,
# 1012 "y.tab.c"
0 , 277 , 16 , 278 , 0 , 197 , 197 , 197 , 197 , 197 , 0 , 0 , 0 , 260 ,
# 1012 "y.tab.c"
395 , 395 , 0 , 0 , 395 , 0 , 18 , 197 , 0 , 0 , 0 , 311 , 0 , 311 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 197 , 287 , 288 , 289 , 290 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 273 , 395 , 260 , 0 , 275 , 276 , 260 , 22 , 277 , 311 , 278 , 311 ,
# 1012 "y.tab.c"
311 , 0 , 311 , 197 , 197 , 197 , 0 , 0 , 0 , 0 , 0 , 0 , 260 , 260 ,
# 1012 "y.tab.c"
260 , 245 , 260 , 245 , 245 , 260 , 0 , 245 , 245 , 245 , 245 , 0 , 0 , 245 ,
# 1012 "y.tab.c"
0 , 287 , 245 , 289 , 290 , 245 , 245 , 0 , 197 , 245 , 245 , 0 , 197 , 0 ,
# 1012 "y.tab.c"
245 , 260 , 245 , 0 , 0 , 245 , 245 , 0 , 0 , 0 , 0 , 245 , 245 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 197 , 197 , 245 , 245 , 197 , 0 , 245 , 0 , 245 , 291 , 245 , 245 ,
# 1012 "y.tab.c"
0 , 0 , 245 , 0 , 245 , 0 , 0 , 0 , 245 , 245 , 245 , 245 , 245 , 311 ,
# 1012 "y.tab.c"
245 , 245 , 245 , 245 , 245 , 197 , 0 , 0 , 0 , 0 , 245 , 245 , 245 , 245 ,
# 1012 "y.tab.c"
245 , 245 , 245 , 0 , 0 , 0 , 245 , 245 , 245 , 245 , 245 , 245 , 0 , 245 ,
# 1012 "y.tab.c"
0 , 245 , 245 , 0 , 0 , 0 , 291 , 284 , 284 , 284 , 284 , 284 , 284 , 284 ,
# 1012 "y.tab.c"
569 , 0 , 570 , 571 , 0 , 0 , 572 , 573 , 574 , 575 , 0 , 245 , 3 , 0 ,
# 1012 "y.tab.c"
0 , 576 , 273 , 284 , 577 , 578 , 275 , 276 , 154 , 155 , 277 , 0 , 278 , 579 ,
# 1012 "y.tab.c"
0 , 156 , 0 , 0 , 580 , 157 , 0 , 0 , 0 , 0 , 581 , 158 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 245 , 159 , 160 , 0 , 245 , 161 , 0 , 162 , 0 , 163 , 164 , 0 ,
# 1012 "y.tab.c"
0 , 287 , 288 , 289 , 290 , 0 , 0 , 0 , 0 , 0 , 245 , 245 , 245 , 0 ,
# 1012 "y.tab.c"
245 , 582 , 495 , 245 , 0 , 0 , 0 , 0 , 0 , 583 , 166 , 167 , 168 , 169 ,
# 1012 "y.tab.c"
12 , 170 , 0 , 0 , 0 , 0 , 275 , 0 , 0 , 0 , 171 , 0 , 584 , 245 ,
# 1012 "y.tab.c"
585 , 586 , 0 , 0 , 275 , 275 , 275 , 275 , 275 , 275 , 275 , 275 , 275 , 223 ,
# 1012 "y.tab.c"
0 , 223 , 223 , 0 , 0 , 223 , 223 , 223 , 223 , 0 , 587 , 223 , 0 , 0 ,
# 1012 "y.tab.c"
223 , 617 , 275 , 223 , 223 , 619 , 620 , 223 , 223 , 621 , 0 , 622 , 223 , 0 ,
# 1012 "y.tab.c"
223 , 0 , 0 , 223 , 223 , 0 , 291 , 0 , 0 , 223 , 223 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 15 , 223 , 223 , 0 , 588 , 223 , 0 , 223 , 0 , 223 , 223 , 0 , 0 ,
# 1012 "y.tab.c"
631 , 632 , 633 , 634 , 0 , 0 , 0 , 0 , 0 , 18 , 19 , 0 , 0 , 175 ,
# 1012 "y.tab.c"
223 , 223 , 307 , 0 , 0 , 0 , 0 , 12 , 223 , 223 , 223 , 223 , 223 , 223 ,
# 1012 "y.tab.c"
223 , 0 , 273 , 0 , 274 , 0 , 275 , 276 , 0 , 223 , 277 , 223 , 22 , 223 ,
# 1012 "y.tab.c"
223 , 0 , 279 , 280 , 281 , 282 , 283 , 0 , 284 , 0 , 0 , 0 , 395 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 395 , 14 , 0 , 0 , 0 , 0 , 0 , 223 , 5 , 0 , 395 , 395 ,
# 1012 "y.tab.c"
286 , 287 , 288 , 289 , 290 , 395 , 7 , 0 , 8 , 395 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 395 , 0 , 0 , 0 , 635 , 0 , 395 , 395 , 0 , 0 , 395 , 16 , 395 ,
# 1012 "y.tab.c"
223 , 395 , 395 , 0 , 223 , 395 , 0 , 395 , 335 , 0 , 0 , 395 , 395 , 395 ,
# 1012 "y.tab.c"
395 , 395 , 18 , 395 , 395 , 0 , 395 , 0 , 223 , 223 , 0 , 100 , 223 , 395 ,
# 1012 "y.tab.c"
395 , 395 , 395 , 395 , 395 , 395 , 54 , 0 , 0 , 395 , 395 , 395 , 395 , 395 ,
# 1012 "y.tab.c"
395 , 47 , 395 , 0 , 395 , 22 , 55 , 0 , 0 , 14 , 0 , 223 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 512 , 0 , 291 , 0 , 0 , 56 , 0 , 57 , 0 , 58 ,
# 1012 "y.tab.c"
395 , 59 , 60 , 0 , 0 , 61 , 0 , 62 , 0 , 63 , 64 , 0 , 0 , 65 ,
# 1012 "y.tab.c"
0 , 66 , 14 , 0 , 16 , 67 , 68 , 69 , 70 , 0 , 0 , 71 , 72 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 17 , 395 , 395 , 0 , 0 , 18 , 395 , 44 , 0 , 12 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 73 , 74 , 75 , 76 , 77 , 78 , 0 , 79 , 16 , 153 , 395 ,
# 1012 "y.tab.c"
395 , 395 , 3 , 395 , 285 , 285 , 285 , 285 , 285 , 285 , 0 , 22 , 154 , 155 ,
# 1012 "y.tab.c"
0 , 18 , 0 , 0 , 0 , 156 , 0 , 0 , 14 , 157 , 0 , 0 , 0 , 285 ,
# 1012 "y.tab.c"
0 , 158 , 395 , 0 , 0 , 0 , 4 , 159 , 160 , 0 , 44 , 161 , 0 , 162 ,
# 1012 "y.tab.c"
44 , 163 , 164 , 0 , 22 , 0 , 0 , 0 , 5 , 0 , 0 , 0 , 44 , 0 ,
# 1012 "y.tab.c"
0 , 6 , 0 , 16 , 7 , 0 , 8 , 0 , 0 , 0 , 44 , 0 , 0 , 165 ,
# 1012 "y.tab.c"
166 , 167 , 168 , 169 , 12 , 170 , 0 , 18 , 0 , 80 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
171 , 0 , 172 , 0 , 173 , 153 , 11 , 0 , 44 , 44 , 44 , 12 , 0 , 273 ,
# 1012 "y.tab.c"
0 , 274 , 0 , 275 , 276 , 154 , 155 , 277 , 0 , 278 , 22 , 0 , 156 , 279 ,
# 1012 "y.tab.c"
14 , 617 , 157 , 618 , 0 , 619 , 620 , 0 , 158 , 621 , 0 , 622 , 0 , 44 ,
# 1012 "y.tab.c"
159 , 160 , 0 , 44 , 161 , 0 , 162 , 14 , 163 , 164 , 0 , 0 , 287 , 288 ,
# 1012 "y.tab.c"
289 , 290 , 0 , 0 , 0 , 15 , 0 , 44 , 44 , 174 , 0 , 44 , 0 , 214 ,
# 1012 "y.tab.c"
631 , 632 , 633 , 634 , 0 , 153 , 165 , 166 , 167 , 168 , 169 , 12 , 170 , 18 ,
# 1012 "y.tab.c"
19 , 0 , 16 , 175 , 47 , 154 , 155 , 171 , 0 , 194 , 44 , 173 , 156 , 0 ,
# 1012 "y.tab.c"
0 , 17 , 157 , 0 , 0 , 0 , 18 , 514 , 158 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
159 , 160 , 22 , 0 , 161 , 0 , 162 , 14 , 163 , 164 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 617 , 0 , 0 , 14 , 619 , 620 , 0 , 22 , 621 , 0 , 622 , 574 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 291 , 0 , 0 , 165 , 166 , 167 , 168 , 169 , 12 , 170 , 154 ,
# 1012 "y.tab.c"
155 , 0 , 174 , 0 , 0 , 635 , 156 , 171 , 0 , 194 , 157 , 173 , 0 , 0 ,
# 1012 "y.tab.c"
16 , 631 , 158 , 633 , 634 , 0 , 18 , 0 , 159 , 160 , 0 , 0 , 161 , 0 ,
# 1012 "y.tab.c"
162 , 0 , 163 , 164 , 18 , 0 , 0 , 14 , 0 , 0 , 0 , 273 , 127 , 274 ,
# 1012 "y.tab.c"
0 , 275 , 276 , 0 , 0 , 277 , 0 , 278 , 0 , 22 , 0 , 279 , 280 , 281 ,
# 1012 "y.tab.c"
165 , 166 , 167 , 168 , 169 , 12 , 170 , 22 , 0 , 0 , 0 , 127 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 171 , 174 , 194 , 0 , 585 , 0 , 127 , 0 , 127 , 287 , 288 , 289 , 290 ,
# 1012 "y.tab.c"
0 , 0 , 404 , 16 , 0 , 0 , 18 , 0 , 0 , 0 , 0 , 0 , 127 , 404 ,
# 1012 "y.tab.c"
16 , 14 , 127 , 0 , 0 , 0 , 635 , 0 , 0 , 127 , 0 , 47 , 0 , 0 ,
# 1012 "y.tab.c"
127 , 404 , 404 , 404 , 404 , 404 , 404 , 404 , 404 , 22 , 0 , 404 , 127 , 404 ,
# 1012 "y.tab.c"
539 , 404 , 404 , 0 , 0 , 404 , 0 , 404 , 0 , 0 , 588 , 404 , 404 , 404 ,
# 1012 "y.tab.c"
404 , 404 , 404 , 404 , 404 , 404 , 404 , 404 , 0 , 0 , 127 , 0 , 14 , 404 ,
# 1012 "y.tab.c"
18 , 0 , 0 , 0 , 404 , 0 , 0 , 0 , 0 , 404 , 404 , 404 , 404 , 404 ,
# 1012 "y.tab.c"
404 , 291 , 0 , 0 , 0 , 0 , 0 , 0 , 273 , 0 , 274 , 0 , 275 , 276 ,
# 1012 "y.tab.c"
0 , 127 , 277 , 22 , 278 , 127 , 0 , 16 , 279 , 280 , 281 , 282 , 283 , 0 ,
# 1012 "y.tab.c"
404 , 404 , 404 , 0 , 127 , 0 , 0 , 0 , 0 , 127 , 127 , 18 , 277 , 277 ,
# 1012 "y.tab.c"
277 , 277 , 277 , 277 , 277 , 277 , 277 , 287 , 288 , 289 , 290 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 404 , 404 , 0 , 0 , 405 , 404 , 277 , 0 , 127 , 0 ,
# 1012 "y.tab.c"
22 , 0 , 0 , 0 , 0 , 405 , 0 , 0 , 404 , 0 , 0 , 0 , 0 , 404 ,
# 1012 "y.tab.c"
404 , 404 , 0 , 404 , 0 , 0 , 0 , 405 , 405 , 405 , 405 , 405 , 405 , 405 ,
# 1012 "y.tab.c"
405 , 0 , 0 , 405 , 0 , 405 , 0 , 405 , 405 , 198 , 0 , 405 , 0 , 405 ,
# 1012 "y.tab.c"
0 , 0 , 404 , 405 , 405 , 405 , 405 , 405 , 405 , 405 , 405 , 405 , 405 , 405 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 405 , 0 , 0 , 0 , 198 , 405 , 0 , 291 , 0 ,
# 1012 "y.tab.c"
279 , 405 , 405 , 405 , 405 , 405 , 405 , 0 , 0 , 0 , 0 , 0 , 279 , 279 ,
# 1012 "y.tab.c"
279 , 279 , 279 , 279 , 279 , 279 , 279 , 0 , 0 , 198 , 198 , 198 , 198 , 198 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 405 , 405 , 405 , 0 , 279 , 198 , 279 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 617 , 0 , 618 , 0 , 619 , 620 , 0 , 198 , 621 , 0 , 622 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 623 , 624 , 625 , 626 , 627 , 0 , 0 , 0 , 405 , 405 , 0 , 0 ,
# 1012 "y.tab.c"
410 , 405 , 0 , 0 , 0 , 0 , 0 , 198 , 198 , 198 , 0 , 410 , 0 , 0 ,
# 1012 "y.tab.c"
405 , 631 , 632 , 633 , 634 , 405 , 405 , 405 , 0 , 405 , 0 , 0 , 0 , 410 ,
# 1012 "y.tab.c"
410 , 410 , 410 , 410 , 410 , 410 , 410 , 0 , 0 , 410 , 0 , 410 , 198 , 410 ,
# 1012 "y.tab.c"
410 , 0 , 198 , 410 , 0 , 410 , 0 , 0 , 405 , 410 , 410 , 410 , 410 , 410 ,
# 1012 "y.tab.c"
410 , 410 , 410 , 410 , 410 , 410 , 198 , 198 , 0 , 0 , 198 , 410 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 410 , 0 , 0 , 0 , 0 , 410 , 410 , 410 , 410 , 410 , 410 , 0 ,
# 1012 "y.tab.c"
276 , 276 , 276 , 276 , 276 , 276 , 276 , 276 , 617 , 198 , 618 , 0 , 619 , 620 ,
# 1012 "y.tab.c"
195 , 0 , 621 , 0 , 622 , 0 , 635 , 0 , 623 , 624 , 625 , 276 , 410 , 410 ,
# 1012 "y.tab.c"
410 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 195 ,
# 1012 "y.tab.c"
0 , 195 , 0 , 0 , 0 , 195 , 0 , 631 , 632 , 633 , 634 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 410 , 410 , 0 , 0 , 57 , 410 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
195 , 195 , 0 , 57 , 195 , 0 , 410 , 0 , 0 , 0 , 0 , 410 , 410 , 410 ,
# 1012 "y.tab.c"
0 , 410 , 195 , 0 , 0 , 57 , 57 , 57 , 57 , 57 , 57 , 57 , 57 , 0 ,
# 1012 "y.tab.c"
195 , 57 , 0 , 57 , 0 , 57 , 57 , 0 , 0 , 0 , 0 , 57 , 0 , 0 ,
# 1012 "y.tab.c"
410 , 57 , 57 , 57 , 57 , 57 , 57 , 57 , 57 , 57 , 57 , 57 , 195 , 195 ,
# 1012 "y.tab.c"
195 , 0 , 0 , 57 , 0 , 0 , 0 , 0 , 57 , 0 , 0 , 0 , 635 , 57 ,
# 1012 "y.tab.c"
57 , 57 , 57 , 57 , 57 , 0 , 57 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 195 , 0 , 0 , 0 , 195 , 0 , 0 , 0 , 321 , 0 , 321 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 57 , 57 , 57 , 0 , 0 , 0 , 0 , 195 , 195 , 0 ,
# 1012 "y.tab.c"
321 , 195 , 321 , 0 , 0 , 0 , 321 , 321 , 321 , 321 , 321 , 321 , 321 , 321 ,
# 1012 "y.tab.c"
321 , 0 , 321 , 0 , 0 , 0 , 0 , 0 , 57 , 57 , 0 , 0 , 409 , 57 ,
# 1012 "y.tab.c"
195 , 0 , 0 , 0 , 321 , 321 , 321 , 321 , 321 , 409 , 0 , 0 , 57 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 57 , 57 , 57 , 0 , 57 , 0 , 0 , 0 , 409 , 409 , 409 ,
# 1012 "y.tab.c"
409 , 409 , 409 , 409 , 409 , 0 , 0 , 409 , 0 , 409 , 0 , 409 , 409 , 44 ,
# 1012 "y.tab.c"
0 , 409 , 0 , 409 , 0 , 0 , 57 , 409 , 409 , 409 , 409 , 409 , 409 , 409 ,
# 1012 "y.tab.c"
409 , 409 , 409 , 409 , 0 , 0 , 0 , 0 , 0 , 409 , 0 , 0 , 0 , 321 ,
# 1012 "y.tab.c"
409 , 0 , 0 , 0 , 0 , 409 , 409 , 409 , 409 , 409 , 409 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 321 , 0 , 0 , 44 ,
# 1012 "y.tab.c"
0 , 45 , 45 , 44 , 0 , 0 , 0 , 301 , 0 , 301 , 409 , 409 , 409 , 0 ,
# 1012 "y.tab.c"
0 , 44 , 321 , 0 , 321 , 0 , 0 , 0 , 321 , 321 , 321 , 321 , 321 , 44 ,
# 1012 "y.tab.c"
321 , 321 , 321 , 301 , 301 , 301 , 301 , 301 , 301 , 301 , 301 , 0 , 301 , 0 ,
# 1012 "y.tab.c"
409 , 409 , 0 , 0 , 91 , 409 , 321 , 321 , 321 , 321 , 321 , 44 , 44 , 44 ,
# 1012 "y.tab.c"
301 , 91 , 0 , 0 , 409 , 0 , 0 , 0 , 0 , 409 , 409 , 409 , 0 , 409 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 91 , 91 , 91 , 91 , 91 , 91 , 91 , 91 , 0 , 0 , 91 ,
# 1012 "y.tab.c"
0 , 91 , 44 , 91 , 91 , 0 , 44 , 91 , 0 , 91 , 0 , 0 , 409 , 91 ,
# 1012 "y.tab.c"
91 , 91 , 91 , 91 , 91 , 91 , 91 , 91 , 0 , 91 , 44 , 44 , 0 , 0 ,
# 1012 "y.tab.c"
44 , 91 , 0 , 0 , 0 , 0 , 91 , 0 , 110 , 301 , 0 , 91 , 91 , 91 ,
# 1012 "y.tab.c"
91 , 91 , 91 , 0 , 91 , 110 , 0 , 0 , 0 , 0 , 0 , 0 , 321 , 44 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 110 , 110 , 110 , 110 , 110 , 110 , 110 ,
# 1012 "y.tab.c"
110 , 0 , 91 , 110 , 0 , 110 , 0 , 110 , 110 , 0 , 0 , 110 , 0 , 110 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 110 , 110 , 110 , 110 , 110 , 0 , 110 , 110 , 110 , 116 , 110 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 110 , 91 , 91 , 0 , 0 , 110 , 91 , 128 , 0 ,
# 1012 "y.tab.c"
0 , 110 , 110 , 110 , 110 , 110 , 110 , 0 , 110 , 128 , 91 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 91 , 91 , 91 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 128 , 128 , 128 ,
# 1012 "y.tab.c"
128 , 128 , 128 , 128 , 128 , 0 , 110 , 128 , 0 , 128 , 0 , 128 , 128 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 128 , 91 , 0 , 0 , 128 , 128 , 128 , 128 , 128 , 128 , 128 ,
# 1012 "y.tab.c"
128 , 128 , 128 , 128 , 0 , 0 , 0 , 0 , 0 , 128 , 110 , 110 , 0 , 0 ,
# 1012 "y.tab.c"
128 , 110 , 111 , 0 , 0 , 128 , 128 , 128 , 128 , 128 , 128 , 0 , 128 , 111 ,
# 1012 "y.tab.c"
110 , 0 , 0 , 0 , 0 , 110 , 110 , 110 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 111 , 111 , 111 , 111 , 111 , 111 , 111 , 111 , 0 , 128 , 111 , 0 , 111 ,
# 1012 "y.tab.c"
0 , 111 , 111 , 0 , 0 , 111 , 0 , 111 , 110 , 0 , 0 , 111 , 111 , 111 ,
# 1012 "y.tab.c"
111 , 111 , 0 , 111 , 111 , 111 , 116 , 111 , 0 , 0 , 0 , 0 , 0 , 111 ,
# 1012 "y.tab.c"
128 , 128 , 0 , 0 , 111 , 128 , 109 , 0 , 0 , 111 , 111 , 111 , 111 , 111 ,
# 1012 "y.tab.c"
111 , 0 , 111 , 109 , 128 , 0 , 0 , 0 , 0 , 128 , 128 , 128 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 109 , 109 , 109 , 109 , 109 , 109 , 109 , 109 , 0 ,
# 1012 "y.tab.c"
111 , 109 , 0 , 109 , 0 , 109 , 109 , 0 , 0 , 109 , 0 , 109 , 128 , 0 ,
# 1012 "y.tab.c"
0 , 109 , 109 , 109 , 109 , 109 , 109 , 109 , 109 , 109 , 0 , 109 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 109 , 111 , 111 , 0 , 0 , 109 , 111 , 169 , 0 , 0 , 109 ,
# 1012 "y.tab.c"
109 , 109 , 109 , 109 , 109 , 0 , 109 , 0 , 111 , 0 , 0 , 0 , 0 , 111 ,
# 1012 "y.tab.c"
111 , 111 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 169 , 169 , 0 , 169 , 169 ,
# 1012 "y.tab.c"
169 , 169 , 0 , 0 , 109 , 169 , 0 , 169 , 0 , 169 , 169 , 0 , 0 , 169 ,
# 1012 "y.tab.c"
0 , 169 , 111 , 0 , 0 , 169 , 169 , 169 , 169 , 169 , 169 , 169 , 169 , 169 ,
# 1012 "y.tab.c"
169 , 169 , 0 , 0 , 0 , 0 , 0 , 0 , 109 , 109 , 0 , 0 , 169 , 109 ,
# 1012 "y.tab.c"
0 , 0 , 167 , 169 , 169 , 169 , 169 , 169 , 169 , 0 , 169 , 0 , 109 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 109 , 109 , 109 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 167 , 167 , 0 , 167 , 167 , 167 , 167 , 169 , 169 , 169 , 167 , 0 , 167 ,
# 1012 "y.tab.c"
0 , 167 , 167 , 0 , 0 , 167 , 109 , 167 , 0 , 0 , 0 , 167 , 167 , 167 ,
# 1012 "y.tab.c"
167 , 167 , 167 , 167 , 167 , 167 , 167 , 167 , 0 , 0 , 0 , 0 , 169 , 169 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 169 , 167 , 0 , 396 , 0 , 0 , 167 , 167 , 167 , 167 , 167 ,
# 1012 "y.tab.c"
167 , 0 , 167 , 0 , 0 , 0 , 0 , 169 , 169 , 169 , 0 , 169 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 396 , 396 , 396 , 0 , 0 , 0 , 396 , 0 , 0 ,
# 1012 "y.tab.c"
167 , 167 , 167 , 0 , 0 , 0 , 62 , 0 , 0 , 0 , 169 , 396 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 62 , 0 , 0 , 396 , 396 , 396 , 396 , 396 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 167 , 167 , 62 , 62 , 396 , 167 , 0 , 62 , 62 , 0 ,
# 1012 "y.tab.c"
0 , 62 , 0 , 62 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 62 , 0 , 167 ,
# 1012 "y.tab.c"
167 , 167 , 0 , 167 , 0 , 0 , 62 , 62 , 62 , 62 , 142 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 62 , 396 , 396 , 396 , 0 , 62 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 167 , 0 , 0 , 0 , 62 , 0 , 0 , 142 , 142 , 142 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 142 , 0 , 0 , 0 , 0 , 0 , 0 , 396 , 396 , 3 , 0 , 0 , 396 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 62 , 0 , 0 , 4 , 0 , 0 , 142 , 142 , 142 , 142 ,
# 1012 "y.tab.c"
142 , 0 , 0 , 396 , 396 , 0 , 0 , 396 , 0 , 5 , 0 , 0 , 142 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 6 , 0 , 0 , 7 , 0 , 8 , 62 , 62 , 142 , 0 , 0 , 62 ,
# 1012 "y.tab.c"
60 , 0 , 0 , 0 , 0 , 0 , 396 , 0 , 0 , 0 , 0 , 0 , 62 , 0 ,
# 1012 "y.tab.c"
0 , 203 , 0 , 62 , 62 , 0 , 0 , 11 , 142 , 142 , 142 , 0 , 12 , 0 ,
# 1012 "y.tab.c"
60 , 60 , 0 , 0 , 0 , 60 , 0 , 0 , 0 , 60 , 13 , 60 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 60 , 62 , 0 , 0 , 0 , 0 , 0 , 0 , 142 ,
# 1012 "y.tab.c"
0 , 60 , 60 , 142 , 0 , 0 , 0 , 300 , 14 , 300 , 0 , 60 , 137 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 60 , 0 , 300 , 0 , 0 , 142 , 142 , 137 , 0 , 142 , 0 , 0 ,
# 1012 "y.tab.c"
60 , 0 , 300 , 300 , 300 , 300 , 300 , 300 , 300 , 300 , 300 , 137 , 300 , 15 ,
# 1012 "y.tab.c"
0 , 0 , 138 , 16 , 137 , 0 , 0 , 137 , 0 , 137 , 142 , 0 , 60 , 138 ,
# 1012 "y.tab.c"
300 , 0 , 17 , 0 , 204 , 0 , 0 , 18 , 19 , 0 , 0 , 175 , 0 , 0 ,
# 1012 "y.tab.c"
21 , 138 , 0 , 137 , 0 , 0 , 0 , 0 , 138 , 137 , 0 , 138 , 0 , 138 ,
# 1012 "y.tab.c"
137 , 185 , 60 , 60 , 0 , 0 , 0 , 60 , 3 , 273 , 22 , 274 , 137 , 275 ,
# 1012 "y.tab.c"
276 , 0 , 0 , 277 , 0 , 278 , 60 , 138 , 0 , 279 , 280 , 60 , 60 , 138 ,
# 1012 "y.tab.c"
185 , 185 , 185 , 0 , 138 , 0 , 185 , 5 , 0 , 300 , 137 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 138 , 7 , 0 , 8 , 0 , 0 , 287 , 288 , 289 , 290 , 0 , 0 ,
# 1012 "y.tab.c"
60 , 185 , 185 , 185 , 185 , 185 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
138 , 137 , 0 , 185 , 0 , 137 , 0 , 191 , 0 , 0 , 12 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 137 , 0 , 137 , 0 , 107 , 137 , 137 , 0 , 0 , 137 ,
# 1012 "y.tab.c"
0 , 0 , 137 , 0 , 0 , 138 , 191 , 191 , 191 , 138 , 0 , 0 , 191 , 185 ,
# 1012 "y.tab.c"
185 , 185 , 0 , 0 , 0 , 0 , 14 , 0 , 138 , 0 , 138 , 0 , 137 , 138 ,
# 1012 "y.tab.c"
138 , 0 , 0 , 138 , 0 , 0 , 138 , 191 , 191 , 191 , 191 , 191 , 0 , 291 ,
# 1012 "y.tab.c"
0 , 0 , 3 , 0 , 185 , 0 , 0 , 0 , 185 , 191 , 0 , 15 , 0 , 4 ,
# 1012 "y.tab.c"
0 , 16 , 138 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 185 , 185 ,
# 1012 "y.tab.c"
17 , 5 , 185 , 0 , 0 , 18 , 108 , 0 , 6 , 0 , 0 , 7 , 0 , 8 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 191 , 191 , 191 , 0 , 0 , 0 , 0 , 61 , 0 ,
# 1012 "y.tab.c"
0 , 185 , 104 , 0 , 0 , 105 , 128 , 0 , 22 , 61 , 0 , 0 , 0 , 106 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 12 , 0 , 0 , 0 , 0 , 0 , 191 , 61 , 0 , 0 ,
# 1012 "y.tab.c"
191 , 0 , 107 , 0 , 61 , 128 , 0 , 61 , 0 , 61 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 128 , 0 , 128 , 191 , 191 , 0 , 0 , 191 , 0 , 0 , 17 , 61 , 0 ,
# 1012 "y.tab.c"
14 , 61 , 0 , 0 , 178 , 0 , 128 , 0 , 17 , 61 , 128 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
61 , 178 , 0 , 128 , 0 , 0 , 0 , 191 , 128 , 0 , 0 , 0 , 61 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 178 , 0 , 15 , 128 , 0 , 0 , 16 , 178 , 0 , 0 , 178 ,
# 1012 "y.tab.c"
0 , 178 , 0 , 0 , 0 , 0 , 0 , 178 , 17 , 0 , 61 , 0 , 0 , 18 ,
# 1012 "y.tab.c"
108 , 0 , 0 , 0 , 128 , 0 , 0 , 178 , 3 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 178 , 0 , 0 , 0 , 4 , 178 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 61 , 22 , 0 , 178 , 61 , 0 , 5 , 0 , 128 , 0 , 0 , 0 , 128 ,
# 1012 "y.tab.c"
6 , 0 , 0 , 7 , 61 , 8 , 0 , 0 , 62 , 61 , 61 , 0 , 128 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 178 , 128 , 128 , 62 , 0 , 0 , 0 , 69 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 11 , 69 , 0 , 0 , 640 , 12 , 0 , 61 , 643 ,
# 1012 "y.tab.c"
62 , 0 , 646 , 62 , 0 , 62 , 128 , 178 , 13 , 0 , 0 , 178 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 69 , 0 , 0 , 69 , 0 , 69 , 0 , 62 , 0 , 178 , 62 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 178 , 178 , 0 , 675 , 62 , 14 , 678 , 0 , 69 , 62 , 681 , 69 , 682 ,
# 1012 "y.tab.c"
0 , 64 , 685 , 0 , 0 , 0 , 69 , 0 , 62 , 0 , 0 , 69 , 64 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 60 , 0 , 178 , 0 , 0 , 0 , 0 , 69 , 0 , 15 , 688 , 60 ,
# 1012 "y.tab.c"
64 , 16 , 0 , 0 , 692 , 0 , 62 , 64 , 0 , 0 , 64 , 0 , 64 , 0 ,
# 1012 "y.tab.c"
17 , 0 , 0 , 0 , 0 , 18 , 19 , 69 , 60 , 175 , 0 , 60 , 0 , 60 ,
# 1012 "y.tab.c"
0 , 64 , 708 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 62 , 64 , 0 ,
# 1012 "y.tab.c"
3 , 62 , 60 , 64 , 0 , 60 , 0 , 0 , 22 , 0 , 0 , 0 , 69 , 60 ,
# 1012 "y.tab.c"
62 , 64 , 69 , 0 , 60 , 62 , 62 , 0 , 0 , 0 , 0 , 0 , 0 , 5 ,
# 1012 "y.tab.c"
0 , 69 , 60 , 0 , 0 , 0 , 69 , 69 , 0 , 7 , 0 , 8 , 0 , 64 ,
# 1012 "y.tab.c"
3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 62 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
60 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 69 , 0 , 335 , 0 , 5 ,
# 1012 "y.tab.c"
0 , 0 , 12 , 0 , 64 , 0 , 0 , 0 , 64 , 7 , 0 , 8 , 0 , 0 ,
# 1012 "y.tab.c"
107 , 0 , 0 , 0 , 0 , 60 , 0 , 64 , 0 , 60 , 0 , 0 , 64 , 64 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 3 , 0 , 0 , 0 , 60 , 0 , 0 , 484 , 14 , 60 ,
# 1012 "y.tab.c"
60 , 0 , 12 , 0 , 0 , 0 , 0 , 0 , 0 , 154 , 155 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
107 , 64 , 156 , 406 , 0 , 0 , 157 , 0 , 0 , 0 , 0 , 0 , 158 , 7 ,
# 1012 "y.tab.c"
0 , 8 , 60 , 15 , 159 , 160 , 0 , 16 , 0 , 0 , 0 , 0 , 14 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 17 , 0 , 0 , 0 , 0 , 18 , 108 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 12 , 0 , 0 , 0 , 165 , 166 , 167 , 168 ,
# 1012 "y.tab.c"
169 , 12 , 170 , 15 , 107 , 0 , 0 , 16 , 0 , 0 , 0 , 171 , 0 , 194 ,
# 1012 "y.tab.c"
22 , 0 , 0 , 0 , 0 , 0 , 17 , 0 , 0 , 0 , 0 , 18 , 108 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 14 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 14 , 0 , 154 ,
# 1012 "y.tab.c"
155 , 0 , 0 , 0 , 0 , 0 , 156 , 0 , 0 , 0 , 157 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
22 , 0 , 158 , 0 , 247 , 0 , 0 , 15 , 159 , 160 , 0 , 16 , 161 , 0 ,
# 1012 "y.tab.c"
162 , 0 , 163 , 164 , 0 , 0 , 248 , 0 , 0 , 617 , 17 , 618 , 0 , 619 ,
# 1012 "y.tab.c"
620 , 18 , 108 , 621 , 0 , 622 , 0 , 0 , 0 , 623 , 18 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
165 , 166 , 167 , 168 , 169 , 12 , 170 , 0 , 0 , 154 , 155 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 171 , 156 , 194 , 22 , 0 , 157 , 0 , 631 , 632 , 633 , 634 , 158 , 22 ,
# 1012 "y.tab.c"
361 , 0 , 0 , 0 , 159 , 160 , 0 , 409 , 161 , 0 , 162 , 0 , 163 , 164 ,
# 1012 "y.tab.c"
0 , 14 , 273 , 0 , 274 , 0 , 275 , 276 , 0 , 0 , 277 , 0 , 278 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 279 , 280 , 281 , 282 , 283 , 0 , 284 , 285 , 165 , 166 , 167 , 168 ,
# 1012 "y.tab.c"
169 , 12 , 170 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 248 , 171 , 0 , 194 ,
# 1012 "y.tab.c"
286 , 287 , 288 , 289 , 290 , 0 , 0 , 0 , 0 , 154 , 155 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
18 , 0 , 156 , 0 , 0 , 0 , 157 , 0 , 0 , 0 , 0 , 14 , 158 , 635 ,
# 1012 "y.tab.c"
599 , 0 , 0 , 0 , 159 , 160 , 0 , 0 , 161 , 0 , 162 , 0 , 163 , 164 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 22 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 248 , 0 , 0 , 0 , 165 , 166 , 167 , 168 ,
# 1012 "y.tab.c"
169 , 12 , 170 , 0 , 0 , 154 , 155 , 0 , 0 , 0 , 18 , 171 , 156 , 194 ,
# 1012 "y.tab.c"
0 , 0 , 157 , 0 , 0 , 0 , 291 , 0 , 158 , 0 , 651 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
159 , 160 , 0 , 679 , 161 , 0 , 162 , 0 , 163 , 164 , 0 , 14 , 273 , 22 ,
# 1012 "y.tab.c"
274 , 0 , 275 , 276 , 0 , 0 , 277 , 0 , 278 , 0 , 0 , 0 , 279 , 280 ,
# 1012 "y.tab.c"
281 , 282 , 283 , 0 , 284 , 285 , 165 , 166 , 167 , 168 , 169 , 12 , 170 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 248 , 171 , 0 , 194 , 286 , 287 , 288 , 289 ,
# 1012 "y.tab.c"
290 , 0 , 0 , 0 , 0 , 154 , 155 , 0 , 0 , 617 , 18 , 618 , 156 , 619 ,
# 1012 "y.tab.c"
620 , 0 , 157 , 621 , 0 , 622 , 0 , 14 , 158 , 623 , 624 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
159 , 160 , 0 , 0 , 161 , 0 , 162 , 0 , 163 , 164 , 0 , 0 , 0 , 22 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 631 , 632 , 633 , 634 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 248 , 0 , 0 , 0 , 165 , 166 , 167 , 168 , 169 , 12 , 170 , 0 ,
# 1012 "y.tab.c"
0 , 154 , 155 , 0 , 0 , 0 , 18 , 171 , 156 , 194 , 0 , 0 , 157 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 291 , 0 , 158 , 0 , 0 , 0 , 0 , 0 , 159 , 160 , 0 , 706 ,
# 1012 "y.tab.c"
161 , 0 , 162 , 0 , 163 , 164 , 0 , 14 , 273 , 22 , 274 , 0 , 275 , 276 ,
# 1012 "y.tab.c"
0 , 0 , 277 , 0 , 278 , 0 , 0 , 0 , 279 , 280 , 281 , 282 , 283 , 0 ,
# 1012 "y.tab.c"
284 , 285 , 347 , 166 , 167 , 168 , 169 , 12 , 170 , 0 , 0 , 0 , 0 , 635 ,
# 1012 "y.tab.c"
0 , 0 , 248 , 171 , 0 , 194 , 286 , 287 , 288 , 289 , 290 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 154 , 155 , 0 , 0 , 0 , 18 , 0 , 156 , 0 , 0 , 0 , 157 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 14 , 158 , 0 , 0 , 0 , 0 , 0 , 159 , 160 , 0 , 0 ,
# 1012 "y.tab.c"
161 , 0 , 162 , 0 , 163 , 164 , 0 , 0 , 0 , 22 , 217 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 248 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 348 , 166 , 167 , 168 , 169 , 12 , 170 , 217 , 217 , 217 , 217 , 217 ,
# 1012 "y.tab.c"
217 , 217 , 18 , 171 , 0 , 194 , 0 , 0 , 0 , 217 , 217 , 0 , 291 , 217 ,
# 1012 "y.tab.c"
0 , 217 , 0 , 0 , 0 , 217 , 217 , 217 , 217 , 217 , 217 , 217 , 217 , 217 ,
# 1012 "y.tab.c"
217 , 217 , 0 , 14 , 0 , 22 , 0 , 0 , 0 , 0 , 0 , 0 , 217 , 0 ,
# 1012 "y.tab.c"
217 , 0 , 0 , 217 , 217 , 217 , 217 , 217 , 217 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 248 , 217 ,
# 1012 "y.tab.c"
217 , 217 , 217 , 217 , 217 , 217 , 0 , 0 , 217 , 217 , 217 , 0 , 0 , 217 ,
# 1012 "y.tab.c"
217 , 0 , 18 , 217 , 0 , 217 , 0 , 395 , 0 , 217 , 217 , 217 , 217 , 217 ,
# 1012 "y.tab.c"
217 , 217 , 217 , 217 , 217 , 217 , 0 , 0 , 0 , 0 , 0 , 0 , 217 , 217 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 217 , 0 , 22 , 0 , 217 , 217 , 217 , 217 , 217 , 217 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 217 , 217 , 217 , 321 , 217 , 321 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 321 , 321 , 321 , 321 , 321 , 0 , 321 , 321 , 0 , 0 , 0 , 217 ,
# 1012 "y.tab.c"
217 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
321 , 321 , 321 , 321 , 321 , 0 , 0 , 395 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 217 , 217 , 0 , 0 , 0 , 0 , 0 , 0 , 209 , 209 , 209 , 209 ,
# 1012 "y.tab.c"
209 , 209 , 209 , 0 , 0 , 395 , 0 , 0 , 0 , 0 , 209 , 209 , 217 , 217 ,
# 1012 "y.tab.c"
209 , 217 , 209 , 0 , 0 , 0 , 209 , 209 , 209 , 209 , 209 , 209 , 209 , 209 ,
# 1012 "y.tab.c"
209 , 0 , 209 , 0 , 0 , 0 , 0 , 0 , 0 , 395 , 395 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
395 , 0 , 0 , 0 , 209 , 209 , 209 , 209 , 209 , 209 , 0 , 391 , 391 , 0 ,
# 1012 "y.tab.c"
391 , 391 , 391 , 0 , 395 , 395 , 321 , 391 , 395 , 391 , 0 , 391 , 391 , 0 ,
# 1012 "y.tab.c"
0 , 391 , 0 , 391 , 0 , 0 , 0 , 391 , 391 , 391 , 391 , 391 , 391 , 391 ,
# 1012 "y.tab.c"
391 , 391 , 0 , 391 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 391 , 391 , 391 , 391 , 391 , 391 , 0 , 0 , 209 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 210 , 210 , 0 , 210 , 210 , 210 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 210 , 309 , 210 , 309 , 210 , 210 , 0 , 209 , 210 , 0 , 210 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 210 , 210 , 210 , 210 , 210 , 210 , 210 , 210 , 210 , 0 , 210 ,
# 1012 "y.tab.c"
0 , 309 , 309 , 309 , 309 , 309 , 309 , 309 , 0 , 309 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
391 , 210 , 210 , 210 , 210 , 210 , 210 , 0 , 381 , 0 , 381 , 309 , 381 , 381 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 381 , 0 , 381 , 0 , 381 , 381 , 0 , 391 , 381 , 0 ,
# 1012 "y.tab.c"
381 , 0 , 0 , 0 , 381 , 381 , 381 , 381 , 381 , 0 , 381 , 381 , 381 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 381 , 381 , 381 , 381 , 381 , 381 , 0 , 0 , 210 , 0 , 381 , 0 ,
# 1012 "y.tab.c"
381 , 0 , 381 , 381 , 0 , 310 , 309 , 310 , 381 , 0 , 381 , 0 , 381 , 381 ,
# 1012 "y.tab.c"
0 , 0 , 381 , 0 , 381 , 0 , 0 , 210 , 381 , 381 , 381 , 381 , 381 , 0 ,
# 1012 "y.tab.c"
381 , 381 , 0 , 310 , 310 , 310 , 310 , 310 , 310 , 0 , 310 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 381 , 381 , 381 , 381 , 381 , 381 , 310 , 0 ,
# 1012 "y.tab.c"
336 , 336 , 336 , 336 , 336 , 0 , 0 , 0 , 0 , 336 , 0 , 336 , 0 , 336 ,
# 1012 "y.tab.c"
336 , 0 , 0 , 336 , 0 , 336 , 0 , 0 , 381 , 336 , 336 , 336 , 336 , 336 ,
# 1012 "y.tab.c"
336 , 336 , 336 , 336 , 0 , 336 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 319 , 0 , 319 , 0 , 336 , 336 , 336 , 336 , 336 , 319 , 0 ,
# 1012 "y.tab.c"
319 , 0 , 319 , 319 , 0 , 0 , 319 , 310 , 319 , 0 , 0 , 0 , 319 , 319 ,
# 1012 "y.tab.c"
319 , 319 , 319 , 319 , 319 , 319 , 319 , 0 , 319 , 0 , 0 , 0 , 381 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 319 , 319 , 319 , 319 ,
# 1012 "y.tab.c"
319 , 315 , 0 , 315 , 0 , 0 , 0 , 0 , 0 , 0 , 315 , 0 , 315 , 0 ,
# 1012 "y.tab.c"
315 , 315 , 336 , 0 , 315 , 0 , 315 , 0 , 0 , 0 , 315 , 315 , 315 , 315 ,
# 1012 "y.tab.c"
315 , 315 , 315 , 315 , 315 , 0 , 315 , 0 , 0 , 0 , 0 , 0 , 0 , 336 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 335 , 0 , 335 , 0 , 315 , 315 , 315 , 315 , 315 , 335 ,
# 1012 "y.tab.c"
0 , 335 , 0 , 335 , 335 , 319 , 0 , 335 , 0 , 335 , 0 , 0 , 0 , 335 ,
# 1012 "y.tab.c"
335 , 335 , 335 , 335 , 335 , 335 , 335 , 335 , 0 , 335 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 319 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 335 , 335 , 335 ,
# 1012 "y.tab.c"
335 , 335 , 332 , 0 , 332 , 0 , 0 , 0 , 0 , 0 , 0 , 332 , 0 , 332 ,
# 1012 "y.tab.c"
0 , 332 , 332 , 315 , 0 , 332 , 0 , 332 , 0 , 0 , 0 , 332 , 332 , 332 ,
# 1012 "y.tab.c"
332 , 332 , 332 , 332 , 332 , 332 , 0 , 332 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
315 , 0 , 0 , 0 , 0 , 333 , 0 , 333 , 0 , 332 , 332 , 332 , 332 , 332 ,
# 1012 "y.tab.c"
333 , 0 , 333 , 0 , 333 , 333 , 335 , 0 , 333 , 0 , 333 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
333 , 333 , 333 , 333 , 333 , 333 , 333 , 333 , 333 , 0 , 333 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 335 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 333 , 333 ,
# 1012 "y.tab.c"
333 , 333 , 333 , 328 , 0 , 328 , 0 , 0 , 0 , 0 , 0 , 0 , 328 , 0 ,
# 1012 "y.tab.c"
328 , 0 , 328 , 328 , 332 , 0 , 328 , 0 , 328 , 0 , 0 , 0 , 328 , 328 ,
# 1012 "y.tab.c"
328 , 328 , 328 , 328 , 328 , 328 , 328 , 0 , 328 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 332 , 0 , 0 , 0 , 0 , 329 , 0 , 329 , 0 , 328 , 328 , 328 , 328 ,
# 1012 "y.tab.c"
328 , 329 , 0 , 329 , 0 , 329 , 329 , 333 , 0 , 329 , 0 , 329 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 329 , 329 , 329 , 329 , 329 , 329 , 329 , 329 , 329 , 0 , 329 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 333 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 329 ,
# 1012 "y.tab.c"
329 , 329 , 329 , 329 , 331 , 0 , 331 , 0 , 0 , 0 , 0 , 0 , 0 , 331 ,
# 1012 "y.tab.c"
0 , 331 , 0 , 331 , 331 , 328 , 0 , 331 , 0 , 331 , 0 , 0 , 0 , 331 ,
# 1012 "y.tab.c"
331 , 331 , 331 , 331 , 331 , 331 , 331 , 331 , 0 , 331 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 328 , 0 , 0 , 0 , 0 , 330 , 0 , 330 , 0 , 331 , 331 , 331 ,
# 1012 "y.tab.c"
331 , 331 , 330 , 0 , 330 , 0 , 330 , 330 , 329 , 0 , 330 , 0 , 330 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 330 , 330 , 330 , 330 , 330 , 330 , 330 , 330 , 330 , 0 , 330 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 329 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
330 , 330 , 330 , 330 , 330 , 334 , 0 , 334 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
334 , 0 , 334 , 0 , 334 , 334 , 331 , 0 , 334 , 0 , 334 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
334 , 334 , 334 , 334 , 334 , 334 , 334 , 334 , 334 , 0 , 334 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 331 , 0 , 0 , 0 , 0 , 320 , 0 , 320 , 0 , 334 , 334 ,
# 1012 "y.tab.c"
334 , 334 , 334 , 320 , 0 , 320 , 0 , 320 , 320 , 330 , 0 , 320 , 0 , 320 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 320 , 320 , 320 , 320 , 320 , 320 , 320 , 320 , 320 , 0 , 320 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 330 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 320 , 320 , 320 , 320 , 320 , 327 , 0 , 327 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 327 , 0 , 327 , 0 , 327 , 327 , 334 , 0 , 327 , 0 , 327 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 327 , 327 , 327 , 327 , 327 , 327 , 327 , 327 , 327 , 0 , 327 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 334 , 0 , 0 , 0 , 0 , 317 , 0 , 317 , 0 , 327 ,
# 1012 "y.tab.c"
327 , 327 , 327 , 327 , 317 , 0 , 317 , 0 , 317 , 317 , 320 , 0 , 317 , 0 ,
# 1012 "y.tab.c"
317 , 0 , 0 , 0 , 317 , 317 , 317 , 317 , 317 , 317 , 317 , 317 , 317 , 0 ,
# 1012 "y.tab.c"
317 , 0 , 0 , 0 , 0 , 0 , 0 , 320 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 317 , 317 , 317 , 317 , 317 , 316 , 0 , 316 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 316 , 0 , 316 , 0 , 316 , 316 , 327 , 0 , 316 , 0 , 316 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 316 , 316 , 316 , 316 , 316 , 316 , 316 , 316 , 316 , 0 , 316 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 327 , 0 , 0 , 0 , 0 , 318 , 0 , 318 , 0 ,
# 1012 "y.tab.c"
316 , 316 , 316 , 316 , 316 , 318 , 0 , 318 , 0 , 318 , 318 , 317 , 0 , 318 ,
# 1012 "y.tab.c"
0 , 318 , 0 , 0 , 0 , 318 , 318 , 318 , 318 , 318 , 318 , 318 , 318 , 318 ,
# 1012 "y.tab.c"
0 , 318 , 0 , 0 , 0 , 321 , 0 , 0 , 317 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 318 , 318 , 318 , 318 , 318 , 321 , 0 , 321 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
321 , 321 , 321 , 321 , 321 , 0 , 321 , 321 , 0 , 316 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
321 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 321 , 321 ,
# 1012 "y.tab.c"
321 , 321 , 321 , 321 , 321 , 321 , 316 , 0 , 0 , 321 , 321 , 321 , 321 , 321 ,
# 1012 "y.tab.c"
0 , 321 , 321 , 0 , 0 , 321 , 0 , 321 , 0 , 321 , 0 , 0 , 318 , 321 ,
# 1012 "y.tab.c"
321 , 321 , 321 , 321 , 0 , 321 , 321 , 321 , 321 , 321 , 321 , 321 , 0 , 321 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 302 , 318 , 302 , 321 , 321 , 321 ,
# 1012 "y.tab.c"
321 , 321 , 321 , 0 , 321 , 0 , 0 , 400 , 321 , 321 , 321 , 321 , 321 , 0 ,
# 1012 "y.tab.c"
321 , 321 , 0 , 302 , 302 , 302 , 302 , 302 , 302 , 302 , 302 , 302 , 0 , 302 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 321 , 329 , 321 , 321 , 321 , 321 , 321 , 0 , 273 , 0 ,
# 1012 "y.tab.c"
274 , 302 , 275 , 276 , 0 , 0 , 277 , 0 , 278 , 0 , 0 , 0 , 279 , 280 ,
# 1012 "y.tab.c"
281 , 282 , 283 , 0 , 284 , 285 , 321 , 0 , 0 , 0 , 0 , 0 , 0 , 321 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 448 , 286 , 287 , 288 , 289 ,
# 1012 "y.tab.c"
290 , 0 , 273 , 321 , 274 , 0 , 275 , 276 , 0 , 0 , 277 , 0 , 278 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 279 , 280 , 281 , 282 , 283 , 0 , 284 , 285 , 302 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 321 , 458 ,
# 1012 "y.tab.c"
286 , 287 , 288 , 289 , 290 , 0 , 273 , 0 , 274 , 0 , 275 , 276 , 0 , 0 ,
# 1012 "y.tab.c"
277 , 0 , 278 , 0 , 0 , 0 , 279 , 280 , 281 , 282 , 283 , 0 , 284 , 285 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 291 , 508 , 286 , 287 , 288 , 289 , 290 , 0 , 273 , 0 , 274 , 0 ,
# 1012 "y.tab.c"
275 , 276 , 0 , 0 , 277 , 0 , 278 , 0 , 0 , 0 , 279 , 280 , 281 , 282 ,
# 1012 "y.tab.c"
283 , 0 , 284 , 285 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 291 , 676 , 286 , 287 , 288 , 289 , 290 , 0 ,
# 1012 "y.tab.c"
273 , 0 , 274 , 0 , 275 , 276 , 0 , 0 , 277 , 0 , 278 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
279 , 280 , 281 , 282 , 283 , 0 , 284 , 285 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 291 , 696 , 286 , 287 ,
# 1012 "y.tab.c"
288 , 289 , 290 , 0 , 273 , 0 , 274 , 0 , 275 , 276 , 0 , 321 , 277 , 0 ,
# 1012 "y.tab.c"
278 , 0 , 0 , 0 , 279 , 280 , 281 , 282 , 283 , 0 , 284 , 285 , 321 , 0 ,
# 1012 "y.tab.c"
321 , 0 , 0 , 0 , 321 , 321 , 321 , 321 , 321 , 0 , 321 , 321 , 0 , 0 ,
# 1012 "y.tab.c"
291 , 0 , 286 , 287 , 288 , 289 , 290 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 321 , 321 , 321 , 321 , 321 , 294 , 0 , 294 , 0 , 294 , 294 , 0 ,
# 1012 "y.tab.c"
0 , 294 , 0 , 294 , 0 , 0 , 0 , 294 , 294 , 294 , 294 , 294 , 294 , 294 ,
# 1012 "y.tab.c"
294 , 294 , 0 , 0 , 291 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 294 , 294 , 294 , 294 , 294 , 0 , 290 , 0 , 290 ,
# 1012 "y.tab.c"
0 , 290 , 290 , 0 , 0 , 290 , 0 , 290 , 0 , 0 , 0 , 290 , 290 , 290 ,
# 1012 "y.tab.c"
290 , 290 , 290 , 290 , 290 , 290 , 0 , 0 , 291 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 321 , 290 , 290 , 290 , 290 , 290 ,
# 1012 "y.tab.c"
295 , 0 , 295 , 0 , 295 , 295 , 0 , 0 , 295 , 0 , 295 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
295 , 295 , 295 , 295 , 295 , 295 , 295 , 295 , 295 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 294 , 295 , 295 ,
# 1012 "y.tab.c"
295 , 295 , 295 , 0 , 292 , 0 , 292 , 0 , 292 , 292 , 0 , 0 , 292 , 0 ,
# 1012 "y.tab.c"
292 , 0 , 0 , 0 , 292 , 292 , 292 , 292 , 292 , 292 , 292 , 292 , 292 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 290 , 292 , 292 , 292 , 292 , 292 , 291 , 0 , 291 , 0 , 291 , 291 , 0 ,
# 1012 "y.tab.c"
0 , 291 , 0 , 291 , 0 , 0 , 0 , 291 , 291 , 291 , 291 , 291 , 291 , 291 ,
# 1012 "y.tab.c"
291 , 291 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 295 , 291 , 291 , 291 , 291 , 291 , 0 , 293 , 0 , 293 ,
# 1012 "y.tab.c"
0 , 293 , 293 , 0 , 0 , 293 , 0 , 293 , 0 , 0 , 0 , 293 , 293 , 293 ,
# 1012 "y.tab.c"
293 , 293 , 293 , 293 , 293 , 293 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 292 , 293 , 293 , 293 , 293 , 293 ,
# 1012 "y.tab.c"
273 , 0 , 274 , 0 , 275 , 276 , 0 , 0 , 277 , 0 , 278 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
279 , 280 , 281 , 282 , 283 , 456 , 284 , 285 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 291 , 286 , 287 ,
# 1012 "y.tab.c"
288 , 289 , 290 , 0 , 273 , 0 , 274 , 0 , 275 , 276 , 0 , 0 , 277 , 0 ,
# 1012 "y.tab.c"
278 , 0 , 0 , 0 , 279 , 280 , 281 , 282 , 283 , 0 , 284 , 285 , 644 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 293 , 286 , 287 , 288 , 289 , 290 , 273 , 0 , 274 , 0 , 275 , 276 , 0 ,
# 1012 "y.tab.c"
0 , 277 , 0 , 278 , 0 , 0 , 0 , 279 , 280 , 281 , 282 , 283 , 674 , 284 ,
# 1012 "y.tab.c"
285 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 291 , 286 , 287 , 288 , 289 , 290 , 0 , 617 , 0 , 618 ,
# 1012 "y.tab.c"
0 , 619 , 620 , 0 , 0 , 621 , 0 , 622 , 0 , 0 , 0 , 623 , 624 , 625 ,
# 1012 "y.tab.c"
626 , 627 , 687 , 628 , 629 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 291 , 630 , 631 , 632 , 633 , 634 ,
# 1012 "y.tab.c"
273 , 0 , 274 , 0 , 275 , 276 , 0 , 0 , 277 , 0 , 278 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
279 , 280 , 281 , 282 , 283 , 0 , 284 , 285 , 698 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 291 , 286 , 287 ,
# 1012 "y.tab.c"
288 , 289 , 290 , 0 , 617 , 0 , 618 , 0 , 619 , 620 , 0 , 0 , 621 , 0 ,
# 1012 "y.tab.c"
622 , 0 , 0 , 0 , 623 , 624 , 625 , 626 , 627 , 0 , 628 , 629 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 635 , 630 , 631 , 632 , 633 , 634 , 273 , 0 , 274 , 0 , 275 , 276 , 0 ,
# 1012 "y.tab.c"
0 , 277 , 0 , 278 , 0 , 0 , 0 , 279 , 280 , 281 , 282 , 283 , 0 , 284 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 291 , 286 , 287 , 288 , 289 , 290 , 0 , 617 , 0 , 618 ,
# 1012 "y.tab.c"
0 , 619 , 620 , 0 , 0 , 621 , 0 , 622 , 0 , 0 , 0 , 623 , 624 , 625 ,
# 1012 "y.tab.c"
626 , 627 , 321 , 628 , 321 , 0 , 0 , 0 , 321 , 321 , 321 , 321 , 321 , 0 ,
# 1012 "y.tab.c"
321 , 321 , 0 , 0 , 321 , 0 , 0 , 0 , 635 , 630 , 631 , 632 , 633 , 634 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 321 , 321 , 321 , 321 , 321 , 321 , 0 , 321 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 321 , 321 , 321 , 321 , 321 , 321 , 321 , 321 , 321 , 0 , 321 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 321 , 321 , 321 , 321 , 321 , 0 , 321 , 321 , 291 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 321 , 321 , 321 , 321 , 321 , 0 , 0 , 0 , 0 , 0 , 299 , 0 , 299 ,
# 1012 "y.tab.c"
0 , 321 , 321 , 321 , 321 , 321 , 299 , 0 , 299 , 0 , 299 , 299 , 0 , 0 ,
# 1012 "y.tab.c"
299 , 0 , 299 , 0 , 0 , 0 , 299 , 299 , 299 , 299 , 299 , 299 , 299 , 299 ,
# 1012 "y.tab.c"
299 , 635 , 299 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 321 , 0 ,
# 1012 "y.tab.c"
0 , 305 , 0 , 305 , 299 , 299 , 299 , 299 , 299 , 0 , 305 , 0 , 305 , 0 ,
# 1012 "y.tab.c"
305 , 305 , 0 , 0 , 305 , 0 , 305 , 0 , 0 , 0 , 305 , 305 , 305 , 305 ,
# 1012 "y.tab.c"
305 , 305 , 305 , 305 , 305 , 0 , 305 , 321 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 321 , 305 , 305 , 305 , 305 , 305 , 0 ,
# 1012 "y.tab.c"
0 , 297 , 0 , 297 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 297 , 299 ,
# 1012 "y.tab.c"
297 , 297 , 0 , 0 , 297 , 0 , 297 , 0 , 0 , 0 , 297 , 297 , 297 , 297 ,
# 1012 "y.tab.c"
297 , 297 , 297 , 297 , 297 , 0 , 297 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 298 , 0 , 298 , 0 , 0 , 0 , 297 , 297 , 297 , 0 , 297 , 298 ,
# 1012 "y.tab.c"
0 , 298 , 298 , 305 , 0 , 298 , 0 , 298 , 0 , 0 , 0 , 298 , 298 , 298 ,
# 1012 "y.tab.c"
298 , 298 , 298 , 298 , 298 , 298 , 0 , 298 , 0 , 303 , 0 , 303 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 303 , 0 , 0 , 298 , 298 , 298 , 303 , 298 ,
# 1012 "y.tab.c"
303 , 0 , 0 , 0 , 303 , 303 , 303 , 303 , 303 , 303 , 303 , 303 , 303 , 0 ,
# 1012 "y.tab.c"
303 , 0 , 307 , 297 , 307 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 307 ,
# 1012 "y.tab.c"
0 , 0 , 303 , 303 , 303 , 307 , 303 , 307 , 0 , 0 , 0 , 307 , 307 , 307 ,
# 1012 "y.tab.c"
307 , 307 , 307 , 307 , 307 , 307 , 0 , 307 , 0 , 308 , 0 , 308 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 298 , 0 , 308 , 0 , 0 , 307 , 307 , 307 , 308 , 0 ,
# 1012 "y.tab.c"
308 , 0 , 0 , 0 , 308 , 308 , 308 , 308 , 308 , 308 , 308 , 308 , 308 , 0 ,
# 1012 "y.tab.c"
308 , 0 , 306 , 0 , 306 , 0 , 0 , 0 , 0 , 0 , 0 , 303 , 0 , 306 ,
# 1012 "y.tab.c"
0 , 0 , 308 , 308 , 308 , 306 , 0 , 306 , 0 , 0 , 0 , 306 , 306 , 306 ,
# 1012 "y.tab.c"
306 , 306 , 306 , 306 , 306 , 306 , 304 , 306 , 304 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 304 , 307 , 0 , 0 , 0 , 0 , 306 , 306 , 306 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 304 , 304 , 304 , 304 , 304 , 304 , 304 , 304 , 304 , 0 , 304 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 308 , 0 , 304 ,
# 1012 "y.tab.c"
0 , 304 , 654 , 655 , 656 , 657 , 658 , 659 , 660 , 661 , 662 , 663 , 664 , 665 ,
# 1012 "y.tab.c"
666 , 667 , 668 , 669 , 670 , 671 , 672 , 0 , 0 , 0 , 0 , 274 , 0 , 274 ,
# 1012 "y.tab.c"
0 , 274 , 274 , 0 , 306 , 274 , 0 , 274 , 0 , 0 , 0 , 274 , 274 , 274 ,
# 1012 "y.tab.c"
274 , 274 , 274 , 274 , 274 , 274 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 304 , 274 , 274 , 274 , 274 , 274 ,
# 1012 "y.tab.c"
0 , 280 , 697 , 280 , 0 , 280 , 280 , 0 , 0 , 280 , 0 , 280 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 280 , 280 , 280 , 280 , 280 , 280 , 280 , 280 , 280 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 280 ,
# 1012 "y.tab.c"
280 , 280 , 280 , 280 , 272 , 0 , 272 , 272 , 0 , 0 , 272 , 0 , 272 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 272 , 272 , 272 , 272 , 272 , 272 , 272 , 272 , 272 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
272 , 272 , 272 , 273 , 272 , 273 , 273 , 0 , 0 , 273 , 0 , 273 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 273 , 273 , 273 , 273 , 273 , 273 , 273 , 273 , 273 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 278 , 0 , 0 , 273 ,
# 1012 "y.tab.c"
273 , 273 , 278 , 273 , 278 , 0 , 0 , 0 , 278 , 278 , 278 , 278 , 278 , 278 ,
# 1012 "y.tab.c"
278 , 278 , 278 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 283 , 0 , 0 , 278 , 278 , 278 , 283 , 278 , 283 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 283 , 283 , 283 , 283 , 283 , 283 , 283 , 283 , 283 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 282 , 0 , 0 , 0 , 0 , 0 , 282 , 0 , 282 , 283 ,
# 1012 "y.tab.c"
283 , 283 , 282 , 282 , 282 , 282 , 282 , 282 , 282 , 282 , 282 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 281 , 0 , 0 , 0 , 0 , 0 , 281 , 0 , 281 ,
# 1012 "y.tab.c"
282 , 282 , 282 , 281 , 281 , 281 , 281 , 281 , 281 , 281 , 281 , 281 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
# 1012 "y.tab.c"
0 , 281 , 281 , 281 } ;

# 1840 "y.tab.c"
static const YYINT yycheck [8260]= { 115 , 0 , 131 , 231 , 3 , 4 , 0 , 308 , 309 , 115 ,
# 1840 "y.tab.c"
3 , 336 , 115 , 338 , 30 , 154 , 15 , 156 , 119 , 154 , 40 , 490 , 0 , 30 ,
# 1840 "y.tab.c"
193 , 268 , 41 , 50 , 24 , 52 , 29 , 30 , 50 , 38 , 74 , 123 , 54 , 55 ,
# 1840 "y.tab.c"
39 , 71 , 29 , 30 , 424 , 40 , 43 , 97 , 51 , 24 , 40 , 40 , 0 , 29 ,
# 1840 "y.tab.c"
30 , 50 , 43 , 52 , 71 , 41 , 50 , 41 , 52 , 230 , 41 , 42 , 184 , 43 ,
# 1840 "y.tab.c"
41 , 46 , 74 , 97 , 47 , 99 , 41 , 0 , 97 , 93 , 94 , 41 , 83 , 29 ,
# 1840 "y.tab.c"
30 , 550 , 45 , 82 , 80 , 214 , 24 , 97 , 89 , 71 , 81 , 24 , 91 , 43 ,
# 1840 "y.tab.c"
45 , 24 , 50 , 102 , 567 , 74 , 99 , 50 , 71 , 80 , 82 , 24 , 69 , 71 ,
# 1840 "y.tab.c"
24 , 410 , 69 , 412 , 71 , 72 , 47 , 41 , 115 , 586 , 47 , 103 , 97 , 115 ,
# 1840 "y.tab.c"
121 , 155 , 253 , 124 , 47 , 123 , 47 , 268 , 114 , 130 , 97 , 268 , 60 , 134 ,
# 1840 "y.tab.c"
265 , 115 , 41 , 93 , 155 , 610 , 80 , 525 , 93 , 71 , 315 , 80 , 60 , 24 ,
# 1840 "y.tab.c"
173 , 80 , 58 , 50 , 138 , 154 , 155 , 54 , 55 , 71 , 176 , 80 , 180 , 292 ,
# 1840 "y.tab.c"
80 , 115 , 47 , 70 , 71 , 176 , 148 , 300 , 47 , 155 , 294 , 295 , 173 , 176 ,
# 1840 "y.tab.c"
183 , 185 , 485 , 173 , 487 , 160 , 60 , 123 , 209 , 73 , 115 , 188 , 189 , 196 ,
# 1840 "y.tab.c"
191 , 494 , 121 , 71 , 93 , 124 , 176 , 176 , 199 , 178 , 218 , 202 , 123 , 80 ,
# 1840 "y.tab.c"
222 , 134 , 451 , 210 , 199 , 218 , 209 , 441 , 219 , 222 , 256 , 209 , 3 , 218 ,
# 1840 "y.tab.c"
321 , 199 , 81 , 222 , 24 , 694 , 180 , 154 , 229 , 218 , 15 , 180 , 209 , 0 ,
# 1840 "y.tab.c"
250 , 234 , 365 , 4 , 339 , 160 , 218 , 160 , 123 , 250 , 222 , 234 , 24 , 47 ,
# 1840 "y.tab.c"
123 , 199 , 173 , 250 , 155 , 554 , 253 , 178 , 234 , 178 , 41 , 178 , 179 , 188 ,
# 1840 "y.tab.c"
29 , 30 , 12 , 24 , 509 , 71 , 218 , 268 , 74 , 0 , 250 , 393 , 22 , 202 ,
# 1840 "y.tab.c"
43 , 397 , 398 , 160 , 80 , 401 , 73 , 180 , 234 , 160 , 270 , 178 , 209 , 305 ,
# 1840 "y.tab.c"
209 , 269 , 40 , 69 , 272 , 294 , 295 , 178 , 305 , 298 , 29 , 30 , 80 , 178 ,
# 1840 "y.tab.c"
303 , 298 , 305 , 36 , 9 , 308 , 309 , 42 , 451 , 24 , 43 , 82 , 451 , 316 ,
# 1840 "y.tab.c"
60 , 9 , 103 , 80 , 23 , 123 , 91 , 41 , 253 , 305 , 209 , 71 , 42 , 114 ,
# 1840 "y.tab.c"
99 , 23 , 209 , 50 , 47 , 336 , 43 , 54 , 55 , 268 , 341 , 42 , 294 , 295 ,
# 1840 "y.tab.c"
41 , 46 , 115 , 47 , 99 , 60 , 69 , 337 , 121 , 138 , 73 , 124 , 336 , 40 ,
# 1840 "y.tab.c"
338 , 42 , 71 , 130 , 123 , 46 , 365 , 134 , 71 , 80 , 509 , 74 , 101 , 58 ,
# 1840 "y.tab.c"
509 , 97 , 701 , 581 , 93 , 357 , 82 , 130 , 366 , 40 , 113 , 369 , 115 , 154 ,
# 1840 "y.tab.c"
155 , 316 , 395 , 60 , 391 , 50 , 40 , 52 , 497 , 71 , 391 , 528 , 74 , 417 ,
# 1840 "y.tab.c"
71 , 607 , 50 , 45 , 52 , 522 , 137 , 176 , 417 , 410 , 123 , 412 , 341 , 414 ,
# 1840 "y.tab.c"
522 , 416 , 417 , 522 , 41 , 188 , 189 , 80 , 191 , 123 , 555 , 71 , 406 , 407 ,
# 1840 "y.tab.c"
74 , 40 , 199 , 69 , 80 , 202 , 43 , 73 , 365 , 417 , 97 , 50 , 191 , 52 ,
# 1840 "y.tab.c"
40 , 80 , 148 , 176 , 432 , 80 , 43 , 218 , 451 , 437 , 50 , 222 , 52 , 60 ,
# 1840 "y.tab.c"
442 , 443 , 444 , 567 , 160 , 462 , 40 , 180 , 465 , 234 , 71 , 462 , 199 , 40 ,
# 1840 "y.tab.c"
465 , 677 , 176 , 69 , 40 , 41 , 42 , 73 , 178 , 179 , 46 , 250 , 80 , 41 ,
# 1840 "y.tab.c"
253 , 270 , 97 , 218 , 489 , 73 , 123 , 222 , 493 , 494 , 69 , 40 , 41 , 42 ,
# 1840 "y.tab.c"
493 , 268 , 486 , 46 , 60 , 234 , 522 , 485 , 507 , 487 , 509 , 209 , 511 , 298 ,
# 1840 "y.tab.c"
72 , 71 , 173 , 13 , 511 , 269 , 222 , 42 , 272 , 522 , 451 , 46 , 72 , 173 ,
# 1840 "y.tab.c"
522 , 160 , 124 , 125 , 516 , 72 , 518 , 71 , 303 , 521 , 305 , 60 , 269 , 308 ,
# 1840 "y.tab.c"
309 , 272 , 522 , 71 , 72 , 178 , 250 , 316 , 71 , 336 , 209 , 552 , 337 , 554 ,
# 1840 "y.tab.c"
123 , 41 , 24 , 552 , 123 , 41 , 489 , 209 , 173 , 70 , 71 , 269 , 567 , 74 ,
# 1840 "y.tab.c"
272 , 41 , 522 , 567 , 341 , 358 , 24 , 173 , 209 , 72 , 507 , 47 , 509 , 366 ,
# 1840 "y.tab.c"
40 , 13 , 369 , 71 , 72 , 85 , 74 , 320 , 40 , 160 , 50 , 522 , 52 , 160 ,
# 1840 "y.tab.c"
365 , 47 , 209 , 97 , 50 , 305 , 52 , 173 , 391 , 336 , 23 , 338 , 71 , 178 ,
# 1840 "y.tab.c"
40 , 209 , 80 , 178 , 179 , 41 , 42 , 50 , 349 , 69 , 46 , 54 , 55 , 408 ,
# 1840 "y.tab.c"
72 , 123 , 69 , 124 , 125 , 416 , 80 , 40 , 336 , 42 , 338 , 85 , 74 , 46 ,
# 1840 "y.tab.c"
567 , 97 , 209 , 410 , 41 , 412 , 209 , 414 , 91 , 432 , 417 , 124 , 125 , 41 ,
# 1840 "y.tab.c"
437 , 357 , 99 , 85 , 41 , 155 , 156 , 104 , 93 , 94 , 160 , 69 , 449 , 71 ,
# 1840 "y.tab.c"
72 , 97 , 40 , 155 , 42 , 41 , 117 , 123 , 46 , 462 , 71 , 72 , 465 , 70 ,
# 1840 "y.tab.c"
178 , 179 , 451 , 701 , 182 , 130 , 417 , 41 , 473 , 474 , 41 , 42 , 701 , 123 ,
# 1840 "y.tab.c"
695 , 46 , 71 , 72 , 70 , 180 , 701 , 486 , 406 , 407 , 41 , 42 , 493 , 123 ,
# 1840 "y.tab.c"
41 , 46 , 160 , 209 , 13 , 417 , 160 , 173 , 40 , 41 , 42 , 705 , 489 , 701 ,
# 1840 "y.tab.c"
46 , 173 , 511 , 494 , 156 , 41 , 178 , 127 , 160 , 516 , 24 , 518 , 406 , 407 ,
# 1840 "y.tab.c"
521 , 40 , 507 , 40 , 509 , 42 , 73 , 188 , 160 , 46 , 191 , 180 , 178 , 179 ,
# 1840 "y.tab.c"
40 , 209 , 182 , 522 , 485 , 47 , 487 , 41 , 40 , 209 , 42 , 47 , 178 , 179 ,
# 1840 "y.tab.c"
46 , 552 , 695 , 40 , 73 , 70 , 71 , 72 , 73 , 80 , 40 , 71 , 42 , 40 ,
# 1840 "y.tab.c"
85 , 209 , 46 , 485 , 41 , 487 , 85 , 554 , 74 , 41 , 80 , 43 , 97 , 522 ,
# 1840 "y.tab.c"
72 , 209 , 41 , 40 , 97 , 42 , 567 , 71 , 72 , 46 , 247 , 40 , 70 , 97 ,
# 1840 "y.tab.c"
73 , 80 , 69 , 80 , 71 , 72 , 85 , 80 , 85 , 69 , 123 , 71 , 72 , 13 ,
# 1840 "y.tab.c"
74 , 69 , 123 , 124 , 125 , 70 , 97 , 72 , 273 , 274 , 275 , 276 , 277 , 278 ,
# 1840 "y.tab.c"
279 , 280 , 281 , 282 , 283 , 284 , 285 , 286 , 287 , 288 , 289 , 290 , 291 , 40 ,
# 1840 "y.tab.c"
293 , 80 , 123 , 40 , 123 , 160 , 153 , 156 , 123 , 156 , 303 , 160 , 159 , 160 ,
# 1840 "y.tab.c"
161 , 162 , 163 , 164 , 69 , 41 , 160 , 43 , 69 , 178 , 171 , 318 , 173 , 0 ,
# 1840 "y.tab.c"
1 , 178 , 179 , 81 , 72 , 182 , 181 , 41 , 176 , 39 , 178 , 160 , 13 , 160 ,
# 1840 "y.tab.c"
12 , 85 , 98 , 160 , 40 , 69 , 41 , 71 , 72 , 24 , 74 , 155 , 209 , 97 ,
# 1840 "y.tab.c"
175 , 178 , 180 , 178 , 209 , 155 , 41 , 178 , 179 , 41 , 42 , 40 , 361 , 209 ,
# 1840 "y.tab.c"
46 , 72 , 705 , 73 , 47 , 73 , 41 , 50 , 695 , 52 , 113 , 123 , 73 , 242 ,
# 1840 "y.tab.c"
701 , 232 , 233 , 554 , 209 , 199 , 209 , 353 , 148 , 73 , 209 , 155 , 341 , 41 ,
# 1840 "y.tab.c"
42 , 72 , 80 , 74 , 46 , 24 , 683 , 357 , 295 , 80 , 415 , 155 , 257 , 414 ,
# 1840 "y.tab.c"
85 , 303 , 156 , 202 , 60 , 489 , 160 , 40 , 267 , - 1 , 701 , 115 , 97 ,
# 1840 "y.tab.c"
- 1 , 47 , 71 , - 1 , 50 , - 1 , 52 , - 1 , 155 , -
# 1840 "y.tab.c"
1 , - 1 , 178 , 179 , - 1 , 1 , 182 , 3 , 4 , 123 , - 1 ,
# 1840 "y.tab.c"
7 , 8 , 9 , 10 , 701 , 123 , 13 , 445 , 73 , 16 , - 1 , - 1 ,
# 1840 "y.tab.c"
19 , 20 , 80 , 80 , 23 , 24 , 456 , 85 , - 1 , 28 , 209 , 30 , -
# 1840 "y.tab.c"
1 , - 1 , 33 , 34 , 40 , 41 , 42 , 97 , 39 , 40 , 46 , 160 , -
# 1840 "y.tab.c"
1 , - 1 , 156 , 46 , 47 , - 1 , 160 , 50 , - 1 , 52 , -
# 1840 "y.tab.c"
1 , 54 , 55 , - 1 , - 1 , 41 , 42 , 178 , 179 , 173 , 46 , 123 ,
# 1840 "y.tab.c"
123 , - 1 , 178 , 179 , - 1 , 13 , 182 , 72 , 73 , 185 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 80 , 80 , 81 , 82 , 83 , 84 , 85 , 86 ,
# 1840 "y.tab.c"
70 , 71 , - 1 , - 1 , 209 , - 1 , - 1 , - 1 , 95 ,
# 1840 "y.tab.c"
97 , 97 , 209 , 99 , 100 , 160 , 160 , - 1 , 41 , - 1 , 43 , 50 ,
# 1840 "y.tab.c"
- 1 , 52 , - 1 , 50 , - 1 , 52 , 173 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 13 , 178 , 178 , 179 , 123 , 123 , 9 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 13 , - 1 , - 1 , 80 , 69 , 70 , 71 , 72 , 85 , 74 , 23 ,
# 1840 "y.tab.c"
24 , - 1 , - 1 , 85 , - 1 , - 1 , 30 , 85 , - 1 ,
# 1840 "y.tab.c"
579 , 34 , 209 , 209 , - 1 , 90 , 97 , 40 , 156 , - 1 , 97 , 160 ,
# 1840 "y.tab.c"
160 , 46 , 47 , 448 , - 1 , 50 , 597 , 52 , 599 , 54 , 55 , - 1 ,
# 1840 "y.tab.c"
155 , 604 , 123 , - 1 , - 1 , 178 , 178 , 179 , 123 , - 1 , 182 ,
# 1840 "y.tab.c"
- 1 , 123 , 185 , - 1 , 40 , 73 , 42 , 85 , 44 , 45 , - 1 ,
# 1840 "y.tab.c"
- 1 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , 97 , 69 , 70 , 71 , 72 ,
# 1840 "y.tab.c"
- 1 , 209 , 209 , 95 , 160 , 97 , 156 , 99 , - 1 , - 1 , 160 ,
# 1840 "y.tab.c"
155 , - 1 , 651 , 160 , - 1 , 508 , 90 , - 1 , 175 , - 1 ,
# 1840 "y.tab.c"
123 , 178 , 173 , 9 , - 1 , - 1 , 173 , 178 , 179 , - 1 , 123 ,
# 1840 "y.tab.c"
178 , - 1 , - 1 , 95 , - 1 , - 1 , 23 , 24 , 678 , 40 ,
# 1840 "y.tab.c"
41 , 42 , - 1 , 30 , - 1 , 46 , - 1 , 34 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 209 , 156 , 40 , 41 , - 1 , 160 , 209 , 698 , 46 , 47 ,
# 1840 "y.tab.c"
209 , 156 , 50 , - 1 , 52 , 160 , 54 , 55 , - 1 , 40 , 41 , 42 ,
# 1840 "y.tab.c"
567 , 178 , 179 , 46 , - 1 , 182 , - 1 , 574 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 178 , 179 , 73 , - 1 , 182 , - 1 , - 1 , 585 , -
# 1840 "y.tab.c"
1 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 13 , 209 , - 1 , - 1 , 95 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 99 , - 1 , - 1 , 209 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 614 , - 1 , - 1 , 617 , 618 , 619 , 620 , 621 , 622 , 623 , 624 ,
# 1840 "y.tab.c"
625 , 626 , 627 , 628 , 629 , 630 , 631 , 632 , 633 , 634 , 635 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 1 , - 1 , 3 , 4 , - 1 , - 1 ,
# 1840 "y.tab.c"
7 , 8 , 9 , 10 , - 1 , 12 , 13 , - 1 , - 1 , 16 , -
# 1840 "y.tab.c"
1 , - 1 , 19 , 20 , - 1 , - 1 , 23 , 24 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 28 , - 1 , 30 , 85 , 80 , 33 , 34 , - 1 , -
# 1840 "y.tab.c"
1 , 676 , - 1 , 39 , 40 , 173 , - 1 , 97 , - 1 , - 1 ,
# 1840 "y.tab.c"
46 , 47 , 687 , 97 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 ,
# 1840 "y.tab.c"
696 , 58 , 13 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 ,
# 1840 "y.tab.c"
68 , 123 , 70 , 71 , 72 , 73 , 74 , 123 , - 1 , 209 , - 1 , -
# 1840 "y.tab.c"
1 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , 41 , - 1 , - 1 , 90 ,
# 1840 "y.tab.c"
91 , 92 , 93 , 94 , 95 , - 1 , 97 , - 1 , 99 , 100 , - 1 ,
# 1840 "y.tab.c"
156 , 50 , - 1 , 52 , 160 , 54 , 55 , - 1 , - 1 , 58 , 160 ,
# 1840 "y.tab.c"
60 , - 1 , 69 , 70 , 71 , 72 , 73 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
123 , 178 , 179 , - 1 , - 1 , 182 , - 1 , 178 , 85 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 41 , - 1 , 43 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 97 , 91 , 92 , 93 , 94 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 50 , 209 , 156 , - 1 , 54 , 55 ,
# 1840 "y.tab.c"
160 , 209 , 58 , 69 , 60 , 71 , 72 , - 1 , 74 , 123 , 124 , 125 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 178 , 179 , 180 ,
# 1840 "y.tab.c"
1 , 182 , 3 , 4 , 185 , - 1 , 7 , 8 , 9 , 10 , - 1 , -
# 1840 "y.tab.c"
1 , 13 , - 1 , 91 , 16 , 93 , 94 , 19 , 20 , - 1 , 156 , 23 ,
# 1840 "y.tab.c"
24 , - 1 , 160 , - 1 , 28 , 209 , 30 , - 1 , - 1 , 33 ,
# 1840 "y.tab.c"
34 , - 1 , - 1 , - 1 , - 1 , 39 , 40 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 178 , 179 , 46 , 47 , 182 , - 1 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
180 , 54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 64 , 65 , 66 , 67 , 68 , 155 , 70 , 71 , 72 , 73 , 74 ,
# 1840 "y.tab.c"
209 , - 1 , - 1 , - 1 , - 1 , 80 , 81 , 82 , 83 , 84 ,
# 1840 "y.tab.c"
85 , 86 , - 1 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 95 ,
# 1840 "y.tab.c"
- 1 , 97 , - 1 , 99 , 100 , - 1 , - 1 , - 1 , 180 ,
# 1840 "y.tab.c"
66 , 67 , 68 , 69 , 70 , 71 , 72 , 1 , - 1 , 3 , 4 , - 1 ,
# 1840 "y.tab.c"
- 1 , 7 , 8 , 9 , 10 , - 1 , 123 , 13 , - 1 , - 1 ,
# 1840 "y.tab.c"
16 , 50 , 90 , 19 , 20 , 54 , 55 , 23 , 24 , 58 , - 1 , 60 , 28 ,
# 1840 "y.tab.c"
- 1 , 30 , - 1 , - 1 , 33 , 34 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 39 , 40 , - 1 , - 1 , - 1 , - 1 , 156 ,
# 1840 "y.tab.c"
46 , 47 , - 1 , 160 , 50 , - 1 , 52 , - 1 , 54 , 55 , -
# 1840 "y.tab.c"
1 , - 1 , 91 , 92 , 93 , 94 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 178 , 179 , 180 , - 1 , 182 , 72 , 73 , 185 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 80 , 81 , 82 , 83 , 84 , 85 ,
# 1840 "y.tab.c"
86 , - 1 , - 1 , - 1 , - 1 , 52 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 95 , - 1 , 97 , 209 , 99 , 100 , - 1 , - 1 , 64 ,
# 1840 "y.tab.c"
65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 1 , - 1 , 3 , 4 , -
# 1840 "y.tab.c"
1 , - 1 , 7 , 8 , 9 , 10 , - 1 , 123 , 13 , - 1 , -
# 1840 "y.tab.c"
1 , 16 , 50 , 90 , 19 , 20 , 54 , 55 , 23 , 24 , 58 , - 1 , 60 ,
# 1840 "y.tab.c"
28 , - 1 , 30 , - 1 , - 1 , 33 , 34 , - 1 , 180 , -
# 1840 "y.tab.c"
1 , - 1 , 39 , 40 , - 1 , - 1 , - 1 , - 1 , 156 ,
# 1840 "y.tab.c"
46 , 47 , - 1 , 160 , 50 , - 1 , 52 , - 1 , 54 , 55 , -
# 1840 "y.tab.c"
1 , - 1 , 91 , 92 , 93 , 94 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 178 , 179 , - 1 , - 1 , 182 , 72 , 73 , 80 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 85 , 80 , 81 , 82 , 83 , 84 , 85 ,
# 1840 "y.tab.c"
86 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , 95 ,
# 1840 "y.tab.c"
58 , 97 , 209 , 99 , 100 , - 1 , 64 , 65 , 66 , 67 , 68 , - 1 ,
# 1840 "y.tab.c"
70 , - 1 , - 1 , - 1 , 9 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
13 , 123 , - 1 , - 1 , - 1 , - 1 , - 1 , 123 , 40 ,
# 1840 "y.tab.c"
- 1 , 23 , 24 , 90 , 91 , 92 , 93 , 94 , 30 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
34 , - 1 , - 1 , - 1 , - 1 , - 1 , 40 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 180 , - 1 , 46 , 47 , - 1 , - 1 , 50 ,
# 1840 "y.tab.c"
160 , 52 , 156 , 54 , 55 , - 1 , 160 , 58 , - 1 , 60 , 80 , -
# 1840 "y.tab.c"
1 , - 1 , 64 , 65 , 66 , 67 , 68 , 178 , 70 , 71 , - 1 , 73 ,
# 1840 "y.tab.c"
- 1 , 178 , 179 , - 1 , 97 , 182 , 80 , 81 , 82 , 83 , 84 , 85 ,
# 1840 "y.tab.c"
86 , 9 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 95 , 80 , 97 ,
# 1840 "y.tab.c"
- 1 , 99 , 209 , 23 , - 1 , - 1 , 123 , - 1 , 209 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 97 , - 1 ,
# 1840 "y.tab.c"
180 , - 1 , - 1 , 40 , - 1 , 42 , - 1 , 44 , 123 , 46 ,
# 1840 "y.tab.c"
47 , - 1 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , -
# 1840 "y.tab.c"
1 , - 1 , 58 , - 1 , 60 , 123 , - 1 , 160 , 64 , 65 , 66 ,
# 1840 "y.tab.c"
67 , - 1 , - 1 , 70 , 71 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 173 , 155 , 156 , - 1 , - 1 , 178 , 160 , 13 , - 1 , 85 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 95 ,
# 1840 "y.tab.c"
- 1 , 97 , 160 , 9 , 178 , 179 , 180 , 13 , 182 , 67 , 68 , 69 , 70 ,
# 1840 "y.tab.c"
71 , 72 , - 1 , 209 , 23 , 24 , - 1 , 178 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 30 , - 1 , - 1 , 123 , 34 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 90 , - 1 , 40 , 209 , - 1 , - 1 , - 1 , 24 , 46 ,
# 1840 "y.tab.c"
47 , - 1 , 69 , 50 , - 1 , 52 , 73 , 54 , 55 , - 1 , 209 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 40 , - 1 , - 1 , - 1 , 85 ,
# 1840 "y.tab.c"
- 1 , - 1 , 47 , - 1 , 160 , 50 , - 1 , 52 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 97 , - 1 , - 1 , 80 , 81 , 82 , 83 , 84 ,
# 1840 "y.tab.c"
85 , 86 , - 1 , 178 , - 1 , 180 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 95 , - 1 , 97 , - 1 , 99 , 9 , 80 , - 1 , 123 ,
# 1840 "y.tab.c"
124 , 125 , 85 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , 23 ,
# 1840 "y.tab.c"
24 , 58 , - 1 , 60 , 209 , - 1 , 30 , 64 , 123 , 50 , 34 , 52 ,
# 1840 "y.tab.c"
- 1 , 54 , 55 , - 1 , 40 , 58 , - 1 , 60 , - 1 , 156 ,
# 1840 "y.tab.c"
46 , 47 , - 1 , 160 , 50 , - 1 , 52 , 123 , 54 , 55 , - 1 ,
# 1840 "y.tab.c"
- 1 , 91 , 92 , 93 , 94 , - 1 , - 1 , - 1 , 156 , -
# 1840 "y.tab.c"
1 , 178 , 179 , 160 , - 1 , 182 , - 1 , 73 , 91 , 92 , 93 , 94 ,
# 1840 "y.tab.c"
- 1 , 9 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , 178 , 179 , - 1 ,
# 1840 "y.tab.c"
160 , 182 , 80 , 23 , 24 , 95 , - 1 , 97 , 209 , 99 , 30 , - 1 ,
# 1840 "y.tab.c"
- 1 , 173 , 34 , - 1 , - 1 , - 1 , 178 , 97 , 40 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 46 , 47 , 209 , - 1 ,
# 1840 "y.tab.c"
50 , - 1 , 52 , 123 , 54 , 55 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 50 , - 1 , - 1 , 123 , 54 , 55 , -
# 1840 "y.tab.c"
1 , 209 , 58 , - 1 , 60 , 9 , - 1 , - 1 , - 1 , 180 ,
# 1840 "y.tab.c"
- 1 , - 1 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , 23 , 24 , -
# 1840 "y.tab.c"
1 , 160 , - 1 , - 1 , 180 , 30 , 95 , - 1 , 97 , 34 , 99 ,
# 1840 "y.tab.c"
- 1 , - 1 , 160 , 91 , 40 , 93 , 94 , - 1 , 178 , - 1 ,
# 1840 "y.tab.c"
46 , 47 , - 1 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 ,
# 1840 "y.tab.c"
178 , - 1 , - 1 , 123 , - 1 , - 1 , - 1 , 50 , 13 ,
# 1840 "y.tab.c"
52 , - 1 , 54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , -
# 1840 "y.tab.c"
1 , 209 , - 1 , 64 , 65 , 66 , 80 , 81 , 82 , 83 , 84 , 85 , 86 ,
# 1840 "y.tab.c"
209 , - 1 , - 1 , - 1 , 40 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
95 , 160 , 97 , - 1 , 99 , - 1 , 50 , - 1 , 52 , 91 , 92 ,
# 1840 "y.tab.c"
93 , 94 , - 1 , - 1 , 13 , 60 , - 1 , - 1 , 178 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 69 , 24 , 71 , 123 , 73 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 180 , - 1 , - 1 , 80 , - 1 ,
# 1840 "y.tab.c"
80 , - 1 , - 1 , 85 , 40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 ,
# 1840 "y.tab.c"
209 , - 1 , 50 , 97 , 52 , 97 , 54 , 55 , - 1 , - 1 , 58 ,
# 1840 "y.tab.c"
- 1 , 60 , - 1 , - 1 , 160 , 64 , 65 , 66 , 67 , 68 , 69 ,
# 1840 "y.tab.c"
70 , 71 , 72 , 73 , 74 , - 1 , - 1 , 123 , - 1 , 123 , 80 ,
# 1840 "y.tab.c"
178 , - 1 , - 1 , - 1 , 85 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 90 , 91 , 92 , 93 , 94 , 95 , 180 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 50 , - 1 , 52 , - 1 , 54 ,
# 1840 "y.tab.c"
55 , - 1 , 156 , 58 , 209 , 60 , 160 , - 1 , 160 , 64 , 65 , 66 ,
# 1840 "y.tab.c"
67 , 68 , - 1 , 123 , 124 , 125 , - 1 , 173 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 178 , 179 , 178 , 64 , 65 , 66 , 67 , 68 , 69 , 70 ,
# 1840 "y.tab.c"
71 , 72 , 91 , 92 , 93 , 94 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 155 , 156 , - 1 , - 1 , 13 , 160 ,
# 1840 "y.tab.c"
90 , - 1 , 209 , - 1 , 209 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 24 , - 1 , - 1 , 173 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 178 , 179 , 180 , - 1 , 182 , - 1 , - 1 , - 1 , 40 ,
# 1840 "y.tab.c"
41 , 42 , 43 , 44 , 45 , 46 , 47 , - 1 , - 1 , 50 , - 1 ,
# 1840 "y.tab.c"
52 , - 1 , 54 , 55 , 13 , - 1 , 58 , - 1 , 60 , - 1 ,
# 1840 "y.tab.c"
- 1 , 209 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , 80 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 41 , 85 , - 1 , 180 , - 1 , 52 , 90 , 91 , 92 ,
# 1840 "y.tab.c"
93 , 94 , 95 , - 1 , - 1 , - 1 , - 1 , - 1 , 64 ,
# 1840 "y.tab.c"
65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , - 1 , 69 , 70 ,
# 1840 "y.tab.c"
71 , 72 , 73 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 123 , 124 , 125 , - 1 , 90 , 85 , 92 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , 97 , 58 , -
# 1840 "y.tab.c"
1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 155 , 156 , - 1 , - 1 , 13 , 160 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 123 , 124 , 125 , - 1 ,
# 1840 "y.tab.c"
24 , - 1 , - 1 , 173 , 91 , 92 , 93 , 94 , 178 , 179 , 180 , -
# 1840 "y.tab.c"
1 , 182 , - 1 , - 1 , - 1 , 40 , 41 , 42 , 43 , 44 , 45 ,
# 1840 "y.tab.c"
46 , 47 , - 1 , - 1 , 50 , - 1 , 52 , 156 , 54 , 55 , -
# 1840 "y.tab.c"
1 , 160 , 58 , - 1 , 60 , - 1 , - 1 , 209 , 64 , 65 , 66 ,
# 1840 "y.tab.c"
67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , 178 , 179 , - 1 , - 1 ,
# 1840 "y.tab.c"
182 , 80 , - 1 , - 1 , - 1 , - 1 , 85 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 95 , - 1 , 65 ,
# 1840 "y.tab.c"
66 , 67 , 68 , 69 , 70 , 71 , 72 , 50 , 209 , 52 , - 1 , 54 , 55 ,
# 1840 "y.tab.c"
13 , - 1 , 58 , - 1 , 60 , - 1 , 180 , - 1 , 64 , 65 ,
# 1840 "y.tab.c"
66 , 90 , 123 , 124 , 125 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 40 , - 1 , 42 , - 1 , - 1 , - 1 , 46 , - 1 ,
# 1840 "y.tab.c"
91 , 92 , 93 , 94 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
155 , 156 , - 1 , - 1 , 13 , 160 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 69 , 70 , - 1 , 24 , 73 , - 1 ,
# 1840 "y.tab.c"
173 , - 1 , - 1 , - 1 , - 1 , 178 , 179 , 180 , - 1 ,
# 1840 "y.tab.c"
182 , 85 , - 1 , - 1 , 40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 ,
# 1840 "y.tab.c"
- 1 , 97 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 60 , - 1 , - 1 , 209 , 64 , 65 , 66 ,
# 1840 "y.tab.c"
67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , 123 , 124 , 125 , - 1 , -
# 1840 "y.tab.c"
1 , 80 , - 1 , - 1 , - 1 , - 1 , 85 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 180 , 90 , 91 , 92 , 93 , 94 , 95 , - 1 , 97 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 156 , - 1 , - 1 , - 1 , 160 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 41 , - 1 , 43 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 123 , 124 , 125 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
178 , 179 , - 1 , 58 , 182 , 60 , - 1 , - 1 , - 1 , 64 ,
# 1840 "y.tab.c"
65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 155 , 156 , - 1 , - 1 , 13 ,
# 1840 "y.tab.c"
160 , 209 , - 1 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 24 ,
# 1840 "y.tab.c"
- 1 , - 1 , 173 , - 1 , - 1 , - 1 , - 1 , 178 ,
# 1840 "y.tab.c"
179 , 180 , - 1 , 182 , - 1 , - 1 , - 1 , 40 , 41 , 42 ,
# 1840 "y.tab.c"
43 , 44 , 45 , 46 , 47 , - 1 , - 1 , 50 , - 1 , 52 , -
# 1840 "y.tab.c"
1 , 54 , 55 , 13 , - 1 , 58 , - 1 , 60 , - 1 , - 1 ,
# 1840 "y.tab.c"
209 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 80 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 155 , 85 , - 1 , - 1 , - 1 , - 1 , 90 , 91 , 92 ,
# 1840 "y.tab.c"
93 , 94 , 95 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 180 , - 1 , - 1 , 69 , - 1 , 71 , 72 , 73 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 41 , - 1 , 43 , 123 , 124 , 125 , - 1 , -
# 1840 "y.tab.c"
1 , 85 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 ,
# 1840 "y.tab.c"
66 , 67 , 68 , 97 , 70 , 71 , 72 , 65 , 66 , 67 , 68 , 69 , 70 , 71 ,
# 1840 "y.tab.c"
72 , - 1 , 74 , - 1 , 155 , 156 , - 1 , - 1 , 13 , 160 ,
# 1840 "y.tab.c"
90 , 91 , 92 , 93 , 94 , 123 , 124 , 125 , 90 , 24 , - 1 , - 1 ,
# 1840 "y.tab.c"
173 , - 1 , - 1 , - 1 , - 1 , 178 , 179 , 180 , - 1 ,
# 1840 "y.tab.c"
182 , - 1 , - 1 , - 1 , 40 , 41 , 42 , 43 , 44 , 45 , 46 ,
# 1840 "y.tab.c"
47 , - 1 , - 1 , 50 , - 1 , 52 , 156 , 54 , 55 , - 1 ,
# 1840 "y.tab.c"
160 , 58 , - 1 , 60 , - 1 , - 1 , 209 , 64 , 65 , 66 , 67 ,
# 1840 "y.tab.c"
68 , 69 , 70 , 71 , 72 , - 1 , 74 , 178 , 179 , - 1 , - 1 ,
# 1840 "y.tab.c"
182 , 80 , - 1 , - 1 , - 1 , - 1 , 85 , - 1 , 13 ,
# 1840 "y.tab.c"
155 , - 1 , 90 , 91 , 92 , 93 , 94 , 95 , - 1 , 97 , 24 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 180 , 209 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 40 ,
# 1840 "y.tab.c"
41 , 42 , 43 , 44 , 45 , 46 , 47 , - 1 , 123 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
- 1 , 54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 , 71 , 72 ,
# 1840 "y.tab.c"
73 , 74 , - 1 , - 1 , - 1 , - 1 , - 1 , 80 , 155 ,
# 1840 "y.tab.c"
156 , - 1 , - 1 , 85 , 160 , 13 , - 1 , - 1 , 90 , 91 ,
# 1840 "y.tab.c"
92 , 93 , 94 , 95 , - 1 , 97 , 24 , 173 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 178 , 179 , 180 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 ,
# 1840 "y.tab.c"
- 1 , 123 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 60 , 209 , - 1 , - 1 , 64 , 65 , 66 ,
# 1840 "y.tab.c"
67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 80 , 155 , 156 , - 1 , - 1 , 85 , 160 , 13 ,
# 1840 "y.tab.c"
- 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 95 , - 1 , 97 , 24 ,
# 1840 "y.tab.c"
173 , - 1 , - 1 , - 1 , - 1 , 178 , 179 , 180 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 40 , 41 ,
# 1840 "y.tab.c"
42 , 43 , 44 , 45 , 46 , 47 , - 1 , 123 , 50 , - 1 , 52 , -
# 1840 "y.tab.c"
1 , 54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , 209 , - 1 ,
# 1840 "y.tab.c"
- 1 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 , 71 , 72 , 73 , 74 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , 80 , 155 , 156 , -
# 1840 "y.tab.c"
1 , - 1 , 85 , 160 , 13 , - 1 , - 1 , 90 , 91 , 92 , 93 ,
# 1840 "y.tab.c"
94 , 95 , - 1 , 97 , 24 , 173 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 178 , 179 , 180 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 , - 1 ,
# 1840 "y.tab.c"
123 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 , 58 ,
# 1840 "y.tab.c"
- 1 , 60 , 209 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 ,
# 1840 "y.tab.c"
70 , 71 , 72 , - 1 , 74 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 80 , 155 , 156 , - 1 , - 1 , 85 , 160 , 13 , - 1 ,
# 1840 "y.tab.c"
- 1 , 90 , 91 , 92 , 93 , 94 , 95 , - 1 , 97 , - 1 , 173 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 178 , 179 , 180 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 40 , 41 , -
# 1840 "y.tab.c"
1 , 43 , 44 , 45 , 46 , - 1 , - 1 , 123 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
- 1 , 54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , 209 , -
# 1840 "y.tab.c"
1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 155 , 156 ,
# 1840 "y.tab.c"
- 1 , - 1 , 85 , 160 , - 1 , - 1 , 13 , 90 , 91 , 92 ,
# 1840 "y.tab.c"
93 , 94 , 95 , - 1 , 97 , - 1 , 173 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 178 , 179 , 180 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , 40 , 41 , - 1 ,
# 1840 "y.tab.c"
43 , 44 , 45 , 46 , 123 , 124 , 125 , 50 , - 1 , 52 , - 1 , 54 ,
# 1840 "y.tab.c"
55 , - 1 , - 1 , 58 , 209 , 60 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 155 , 156 , - 1 , - 1 , - 1 , 160 ,
# 1840 "y.tab.c"
85 , - 1 , 13 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 95 ,
# 1840 "y.tab.c"
- 1 , 97 , - 1 , - 1 , - 1 , - 1 , 178 , 179 , 180 ,
# 1840 "y.tab.c"
- 1 , 182 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 40 , 41 , 42 , - 1 , - 1 , - 1 , 46 , -
# 1840 "y.tab.c"
1 , - 1 , 123 , 124 , 125 , - 1 , - 1 , - 1 , 13 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 209 , 60 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 24 , - 1 , - 1 , 69 , 70 , 71 , 72 , 73 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 155 ,
# 1840 "y.tab.c"
156 , 41 , 42 , 85 , 160 , - 1 , 46 , 47 , - 1 , - 1 , 50 ,
# 1840 "y.tab.c"
- 1 , 52 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 60 , - 1 , 178 , 179 , 180 , - 1 , 182 , - 1 ,
# 1840 "y.tab.c"
- 1 , 69 , 70 , 71 , 72 , 13 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 80 , 123 , 124 , 125 , - 1 , 85 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 209 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 97 , - 1 , - 1 , 40 , 41 , 42 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 46 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 155 , 156 , 13 , - 1 , - 1 , 160 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 123 , - 1 , - 1 , 24 , - 1 ,
# 1840 "y.tab.c"
- 1 , 69 , 70 , 71 , 72 , 73 , - 1 , - 1 , 178 , 179 , -
# 1840 "y.tab.c"
1 , - 1 , 182 , - 1 , 40 , - 1 , - 1 , 85 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 47 , - 1 , - 1 , 50 , - 1 , 52 , 155 ,
# 1840 "y.tab.c"
156 , 97 , - 1 , - 1 , 160 , 13 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 209 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 173 , - 1 , - 1 , 74 , - 1 , 178 , 179 , - 1 , -
# 1840 "y.tab.c"
1 , 80 , 123 , 124 , 125 , - 1 , 85 , - 1 , 41 , 42 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 46 , - 1 , - 1 , - 1 , 50 , 97 , 52 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
60 , 209 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
156 , - 1 , 70 , 71 , 160 , - 1 , - 1 , - 1 , 41 , 123 ,
# 1840 "y.tab.c"
43 , - 1 , 80 , 13 , - 1 , - 1 , - 1 , 85 , - 1 ,
# 1840 "y.tab.c"
52 , - 1 , - 1 , 178 , 179 , 24 , - 1 , 182 , - 1 , -
# 1840 "y.tab.c"
1 , 97 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 40 ,
# 1840 "y.tab.c"
74 , 156 , - 1 , - 1 , 13 , 160 , 47 , - 1 , - 1 , 50 ,
# 1840 "y.tab.c"
- 1 , 52 , 209 , - 1 , 123 , 24 , 90 , - 1 , 173 , - 1 ,
# 1840 "y.tab.c"
175 , - 1 , - 1 , 178 , 179 , - 1 , - 1 , 182 , - 1 ,
# 1840 "y.tab.c"
- 1 , 185 , 40 , - 1 , 74 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 47 , 80 , - 1 , 50 , - 1 , 52 , 85 , 13 , 155 , 156 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 160 , 13 , 50 , 209 , 52 , 97 , 54 , 55 , -
# 1840 "y.tab.c"
1 , - 1 , 58 , - 1 , 60 , 173 , 74 , - 1 , 64 , 65 , 178 ,
# 1840 "y.tab.c"
179 , 80 , 40 , 41 , 42 , - 1 , 85 , - 1 , 46 , 40 , - 1 ,
# 1840 "y.tab.c"
155 , 123 , - 1 , - 1 , - 1 , - 1 , - 1 , 97 , 50 ,
# 1840 "y.tab.c"
- 1 , 52 , - 1 , - 1 , 91 , 92 , 93 , 94 , - 1 , -
# 1840 "y.tab.c"
1 , 209 , 69 , 70 , 71 , 72 , 73 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 123 , 156 , - 1 , 85 ,
# 1840 "y.tab.c"
- 1 , 160 , - 1 , 13 , - 1 , - 1 , 85 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 173 , - 1 ,
# 1840 "y.tab.c"
175 , - 1 , 97 , 178 , 179 , - 1 , - 1 , 182 , - 1 , -
# 1840 "y.tab.c"
1 , 185 , - 1 , - 1 , 156 , 40 , 41 , 42 , 160 , - 1 , -
# 1840 "y.tab.c"
1 , 46 , 123 , 124 , 125 , - 1 , - 1 , - 1 , - 1 , 123 ,
# 1840 "y.tab.c"
- 1 , 173 , - 1 , 175 , - 1 , 209 , 178 , 179 , - 1 , -
# 1840 "y.tab.c"
1 , 182 , - 1 , - 1 , 185 , 69 , 70 , 71 , 72 , 73 , - 1 ,
# 1840 "y.tab.c"
180 , - 1 , - 1 , 13 , - 1 , 156 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 160 , 85 , - 1 , 156 , - 1 , 24 , - 1 , 160 , 209 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 178 , 179 , 173 , 40 , 182 , - 1 , - 1 , 178 , 179 ,
# 1840 "y.tab.c"
- 1 , 47 , - 1 , - 1 , 50 , - 1 , 52 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 123 , 124 , 125 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 13 , - 1 , - 1 , 209 , 69 , - 1 , -
# 1840 "y.tab.c"
1 , 72 , 13 , - 1 , 209 , 24 , - 1 , - 1 , - 1 , 80 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 85 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 156 , 40 , - 1 , - 1 , 160 , - 1 ,
# 1840 "y.tab.c"
97 , - 1 , 47 , 40 , - 1 , 50 , - 1 , 52 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 50 , - 1 , 52 , 178 , 179 , -
# 1840 "y.tab.c"
1 , - 1 , 182 , - 1 , - 1 , 60 , 69 , - 1 , 123 , 72 ,
# 1840 "y.tab.c"
- 1 , - 1 , 13 , - 1 , 69 , - 1 , 71 , 80 , 73 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 85 , 24 , - 1 , 80 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 209 , 85 , - 1 , - 1 , - 1 , 97 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 40 , - 1 , 156 , 97 , - 1 , - 1 ,
# 1840 "y.tab.c"
160 , 47 , - 1 , - 1 , 50 , - 1 , 52 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 58 , 173 , - 1 , 123 , - 1 , -
# 1840 "y.tab.c"
1 , 178 , 179 , - 1 , - 1 , - 1 , 123 , - 1 , - 1 ,
# 1840 "y.tab.c"
72 , 13 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
80 , - 1 , - 1 , - 1 , 24 , 85 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 156 , 209 , -
# 1840 "y.tab.c"
1 , 97 , 160 , - 1 , 40 , - 1 , 156 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 160 , 47 , - 1 , - 1 , 50 , 173 , 52 , - 1 , - 1 ,
# 1840 "y.tab.c"
13 , 178 , 179 , - 1 , 173 , - 1 , - 1 , - 1 , 123 , 178 ,
# 1840 "y.tab.c"
179 , 24 , - 1 , - 1 , - 1 , 13 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 80 ,
# 1840 "y.tab.c"
24 , - 1 , - 1 , 601 , 85 , - 1 , 209 , 605 , 47 , - 1 ,
# 1840 "y.tab.c"
608 , 50 , - 1 , 52 , 209 , 156 , 97 , - 1 , - 1 , 160 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 47 , - 1 , - 1 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
- 1 , 69 , - 1 , 173 , 72 , - 1 , - 1 , - 1 , 178 ,
# 1840 "y.tab.c"
179 , - 1 , 638 , 80 , 123 , 641 , - 1 , 69 , 85 , 645 , 72 , 647 ,
# 1840 "y.tab.c"
- 1 , 13 , 650 , - 1 , - 1 , - 1 , 80 , - 1 , 97 ,
# 1840 "y.tab.c"
- 1 , - 1 , 85 , 24 , - 1 , - 1 , - 1 , 13 , -
# 1840 "y.tab.c"
1 , 209 , - 1 , - 1 , - 1 , - 1 , 97 , - 1 , 156 ,
# 1840 "y.tab.c"
674 , 24 , 40 , 160 , - 1 , - 1 , 680 , - 1 , 123 , 47 , -
# 1840 "y.tab.c"
1 , - 1 , 50 , - 1 , 52 , - 1 , 173 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 178 , 179 , 123 , 47 , 182 , - 1 , 50 , - 1 ,
# 1840 "y.tab.c"
52 , - 1 , 69 , 706 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 156 , 80 , - 1 , 13 , 160 , 69 ,
# 1840 "y.tab.c"
85 , - 1 , 72 , - 1 , - 1 , 209 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 156 , 80 , 173 , 97 , 160 , - 1 , 85 , 178 , 179 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 40 , - 1 , 173 , 97 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 178 , 179 , - 1 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
- 1 , 123 , 13 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 209 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 123 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 209 , - 1 , 80 , - 1 , 40 , - 1 , -
# 1840 "y.tab.c"
1 , 85 , - 1 , 156 , - 1 , - 1 , - 1 , 160 , 50 , -
# 1840 "y.tab.c"
1 , 52 , - 1 , - 1 , 97 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 156 , - 1 , 173 , - 1 , 160 , - 1 , - 1 , 178 , 179 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 13 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 173 , - 1 , - 1 , 80 , 123 , 178 , 179 , - 1 , 85 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 23 , 24 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 97 , 209 , 30 , 40 , - 1 , - 1 , 34 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , 40 , 50 , - 1 ,
# 1840 "y.tab.c"
52 , 209 , 156 , 46 , 47 , - 1 , 160 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 123 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 173 , - 1 , - 1 , - 1 , - 1 , 178 , 179 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
85 , - 1 , - 1 , - 1 , 80 , 81 , 82 , 83 , 84 , 85 , 86 ,
# 1840 "y.tab.c"
156 , 97 , - 1 , - 1 , 160 , - 1 , - 1 , - 1 , 95 ,
# 1840 "y.tab.c"
- 1 , 97 , 209 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
173 , - 1 , - 1 , - 1 , - 1 , 178 , 179 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 123 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 123 , - 1 , 23 , 24 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 30 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
34 , - 1 , - 1 , - 1 , 209 , - 1 , 40 , - 1 , 42 ,
# 1840 "y.tab.c"
- 1 , - 1 , 156 , 46 , 47 , - 1 , 160 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
- 1 , 54 , 55 , - 1 , - 1 , 160 , - 1 , - 1 , 50 ,
# 1840 "y.tab.c"
173 , 52 , - 1 , 54 , 55 , 178 , 179 , 58 , - 1 , 60 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 64 , 178 , - 1 , - 1 , - 1 , 80 , 81 ,
# 1840 "y.tab.c"
82 , 83 , 84 , 85 , 86 , - 1 , - 1 , 23 , 24 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 95 , 30 , 97 , 209 , - 1 , 34 , - 1 ,
# 1840 "y.tab.c"
91 , 92 , 93 , 94 , 40 , 209 , 42 , - 1 , - 1 , - 1 , 46 ,
# 1840 "y.tab.c"
47 , - 1 , 41 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 ,
# 1840 "y.tab.c"
123 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 , 58 ,
# 1840 "y.tab.c"
- 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 ,
# 1840 "y.tab.c"
- 1 , 70 , 71 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 160 , 95 , -
# 1840 "y.tab.c"
1 , 97 , 90 , 91 , 92 , 93 , 94 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 23 , 24 , - 1 , - 1 , - 1 , 178 , - 1 , 30 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 34 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
123 , 40 , 180 , 42 , - 1 , - 1 , - 1 , 46 , 47 , - 1 ,
# 1840 "y.tab.c"
- 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 209 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 160 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
80 , 81 , 82 , 83 , 84 , 85 , 86 , - 1 , - 1 , 23 , 24 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 178 , 95 , 30 , 97 , - 1 , - 1 , 34 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 180 , - 1 , 40 , - 1 , 42 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 46 , 47 , - 1 , 41 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
- 1 , 54 , 55 , - 1 , 123 , 50 , 209 , 52 , - 1 , 54 , 55 ,
# 1840 "y.tab.c"
- 1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
64 , 65 , 66 , 67 , 68 , - 1 , 70 , 71 , 80 , 81 , 82 , 83 , 84 ,
# 1840 "y.tab.c"
85 , 86 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 160 , 95 , - 1 , 97 , 90 , 91 , 92 , 93 , 94 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 23 , 24 , - 1 , - 1 , 50 , 178 ,
# 1840 "y.tab.c"
52 , 30 , 54 , 55 , - 1 , 34 , 58 , - 1 , 60 , - 1 , 123 ,
# 1840 "y.tab.c"
40 , 64 , 65 , - 1 , - 1 , - 1 , 46 , 47 , - 1 , -
# 1840 "y.tab.c"
1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 209 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 91 , 92 , 93 , 94 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 160 , - 1 , - 1 , - 1 , 80 , 81 , 82 , 83 , 84 ,
# 1840 "y.tab.c"
85 , 86 , - 1 , - 1 , 23 , 24 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
178 , 95 , 30 , 97 , - 1 , - 1 , 34 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 180 , - 1 , 40 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 46 , 47 , - 1 , 41 , 50 , - 1 , 52 , - 1 , 54 , 55 ,
# 1840 "y.tab.c"
- 1 , 123 , 50 , 209 , 52 , - 1 , 54 , 55 , - 1 , - 1 ,
# 1840 "y.tab.c"
58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 ,
# 1840 "y.tab.c"
68 , - 1 , 70 , 71 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 180 , - 1 , - 1 , 160 , 95 , -
# 1840 "y.tab.c"
1 , 97 , 90 , 91 , 92 , 93 , 94 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 23 , 24 , - 1 , - 1 , - 1 , 178 , - 1 , 30 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 34 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
123 , 40 , - 1 , - 1 , - 1 , - 1 , - 1 , 46 , 47 ,
# 1840 "y.tab.c"
- 1 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 209 , 13 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 160 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , 40 , 41 , 42 , 43 , 44 , 45 ,
# 1840 "y.tab.c"
46 , 178 , 95 , - 1 , 97 , - 1 , - 1 , - 1 , 54 , 55 ,
# 1840 "y.tab.c"
- 1 , 180 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 ,
# 1840 "y.tab.c"
65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , - 1 , 123 , -
# 1840 "y.tab.c"
1 , 209 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
85 , - 1 , 13 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 95 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 160 , 40 , 41 , 42 , 43 , 44 , 45 , 46 ,
# 1840 "y.tab.c"
- 1 , - 1 , 123 , 124 , 125 , - 1 , - 1 , 54 , 55 , -
# 1840 "y.tab.c"
1 , 178 , 58 , - 1 , 60 , - 1 , 13 , - 1 , 64 , 65 , 66 ,
# 1840 "y.tab.c"
67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 155 , 156 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
160 , - 1 , 209 , - 1 , 90 , 91 , 92 , 93 , 94 , 95 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
178 , 179 , 180 , 58 , 182 , 60 , - 1 , - 1 , - 1 , 64 , 65 ,
# 1840 "y.tab.c"
66 , 67 , 68 , - 1 , 70 , 71 , - 1 , - 1 , - 1 , 124 ,
# 1840 "y.tab.c"
125 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 90 ,
# 1840 "y.tab.c"
91 , 92 , 93 , 94 , - 1 , - 1 , 97 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 155 , 156 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 40 , 41 , 42 ,
# 1840 "y.tab.c"
43 , 44 , 45 , 46 , - 1 , - 1 , 123 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 54 , 55 , 179 , 180 , 58 , 182 , 60 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 155 , 156 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 160 , - 1 , - 1 , - 1 , 90 ,
# 1840 "y.tab.c"
91 , 92 , 93 , 94 , 95 , - 1 , 40 , 41 , - 1 , 43 , 44 , 45 ,
# 1840 "y.tab.c"
- 1 , 178 , 179 , 180 , 50 , 182 , 52 , - 1 , 54 , 55 , - 1 ,
# 1840 "y.tab.c"
- 1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 ,
# 1840 "y.tab.c"
66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 90 , 91 ,
# 1840 "y.tab.c"
92 , 93 , 94 , 95 , - 1 , - 1 , 155 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 40 , 41 , - 1 , 43 ,
# 1840 "y.tab.c"
44 , 45 , - 1 , - 1 , - 1 , - 1 , 50 , 41 , 52 , 43 ,
# 1840 "y.tab.c"
54 , 55 , - 1 , 180 , 58 , - 1 , 60 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , -
# 1840 "y.tab.c"
1 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 155 , 90 , 91 , 92 , 93 , 94 , 95 , - 1 ,
# 1840 "y.tab.c"
40 , - 1 , 42 , 90 , 44 , 45 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , 180 , 58 , -
# 1840 "y.tab.c"
1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , -
# 1840 "y.tab.c"
1 , 70 , 71 , 72 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , 90 , 91 , 92 , 93 ,
# 1840 "y.tab.c"
94 , 95 , - 1 , - 1 , 155 , - 1 , 40 , - 1 , 42 , -
# 1840 "y.tab.c"
1 , 44 , 45 , - 1 , 41 , 155 , 43 , 50 , - 1 , 52 , - 1 ,
# 1840 "y.tab.c"
54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 ,
# 1840 "y.tab.c"
180 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 , 71 , - 1 , 67 , 68 ,
# 1840 "y.tab.c"
69 , 70 , 71 , 72 , - 1 , 74 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 90 , 91 , 92 ,
# 1840 "y.tab.c"
93 , 94 , 95 , 90 , - 1 , 41 , 42 , 43 , 44 , 45 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , -
# 1840 "y.tab.c"
1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , 180 , 64 , 65 ,
# 1840 "y.tab.c"
66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 41 , - 1 , 43 , - 1 , 90 , 91 , 92 , 93 ,
# 1840 "y.tab.c"
94 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 , 58 ,
# 1840 "y.tab.c"
155 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 ,
# 1840 "y.tab.c"
70 , 71 , 72 , - 1 , 74 , - 1 , - 1 , - 1 , 180 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 41 , -
# 1840 "y.tab.c"
1 , 43 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
50 , - 1 , 52 , - 1 , 54 , 55 , 155 , - 1 , 58 , - 1 ,
# 1840 "y.tab.c"
60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 ,
# 1840 "y.tab.c"
71 , 72 , - 1 , 74 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 180 , - 1 , - 1 , - 1 , - 1 , 41 , -
# 1840 "y.tab.c"
1 , 43 , - 1 , 90 , 91 , 92 , 93 , 94 , 50 , - 1 , 52 , -
# 1840 "y.tab.c"
1 , 54 , 55 , 155 , - 1 , 58 , - 1 , 60 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 180 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 90 , 91 , 92 , 93 , 94 , 41 , - 1 , 43 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 50 , - 1 , 52 , - 1 ,
# 1840 "y.tab.c"
54 , 55 , 155 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 180 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 41 , - 1 , 43 , - 1 , 90 , 91 ,
# 1840 "y.tab.c"
92 , 93 , 94 , 50 , - 1 , 52 , - 1 , 54 , 55 , 155 , - 1 ,
# 1840 "y.tab.c"
58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 ,
# 1840 "y.tab.c"
68 , 69 , 70 , 71 , 72 , - 1 , 74 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 180 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 ,
# 1840 "y.tab.c"
41 , - 1 , 43 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , 155 , - 1 , 58 ,
# 1840 "y.tab.c"
- 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 ,
# 1840 "y.tab.c"
69 , 70 , 71 , 72 , - 1 , 74 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 180 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
41 , - 1 , 43 , - 1 , 90 , 91 , 92 , 93 , 94 , 50 , - 1 ,
# 1840 "y.tab.c"
52 , - 1 , 54 , 55 , 155 , - 1 , 58 , - 1 , 60 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , -
# 1840 "y.tab.c"
1 , 74 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
180 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 90 , 91 , 92 , 93 , 94 , 41 , - 1 , 43 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
- 1 , 54 , 55 , 155 , - 1 , 58 , - 1 , 60 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 ,
# 1840 "y.tab.c"
74 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 180 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 41 , - 1 , 43 , - 1 ,
# 1840 "y.tab.c"
90 , 91 , 92 , 93 , 94 , 50 , - 1 , 52 , - 1 , 54 , 55 , 155 ,
# 1840 "y.tab.c"
- 1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 ,
# 1840 "y.tab.c"
66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 180 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 90 , 91 , 92 ,
# 1840 "y.tab.c"
93 , 94 , 41 , - 1 , 43 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , 155 , -
# 1840 "y.tab.c"
1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 ,
# 1840 "y.tab.c"
67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 180 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 41 , - 1 , 43 , - 1 , 90 , 91 , 92 , 93 , 94 , 50 ,
# 1840 "y.tab.c"
- 1 , 52 , - 1 , 54 , 55 , 155 , - 1 , 58 , - 1 , 60 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 ,
# 1840 "y.tab.c"
72 , - 1 , 74 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 180 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 41 , - 1 , 43 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 50 , -
# 1840 "y.tab.c"
1 , 52 , - 1 , 54 , 55 , 155 , - 1 , 58 , - 1 , 60 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 ,
# 1840 "y.tab.c"
- 1 , 74 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 180 , - 1 , - 1 , - 1 , - 1 , 41 , - 1 , 43 ,
# 1840 "y.tab.c"
- 1 , 90 , 91 , 92 , 93 , 94 , 50 , - 1 , 52 , - 1 , 54 ,
# 1840 "y.tab.c"
55 , 155 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , 180 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 90 ,
# 1840 "y.tab.c"
91 , 92 , 93 , 94 , 41 , - 1 , 43 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 ,
# 1840 "y.tab.c"
155 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 ,
# 1840 "y.tab.c"
65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 180 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 41 , - 1 , 43 , - 1 , 90 , 91 , 92 , 93 ,
# 1840 "y.tab.c"
94 , 50 , - 1 , 52 , - 1 , 54 , 55 , 155 , - 1 , 58 , -
# 1840 "y.tab.c"
1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 ,
# 1840 "y.tab.c"
70 , 71 , 72 , - 1 , 74 , - 1 , - 1 , - 1 , 41 , -
# 1840 "y.tab.c"
1 , - 1 , 180 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 58 , - 1 ,
# 1840 "y.tab.c"
60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , - 1 ,
# 1840 "y.tab.c"
70 , 71 , - 1 , 155 , - 1 , - 1 , - 1 , - 1 , 41 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 , 58 ,
# 1840 "y.tab.c"
41 , 60 , 180 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , - 1 ,
# 1840 "y.tab.c"
70 , 71 , - 1 , - 1 , 74 , - 1 , 58 , - 1 , 60 , -
# 1840 "y.tab.c"
1 , - 1 , 155 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 , 71 , 90 ,
# 1840 "y.tab.c"
91 , 92 , 93 , 94 , - 1 , 41 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 41 , 180 , 43 , 90 , 91 ,
# 1840 "y.tab.c"
92 , 93 , 94 , 58 , - 1 , 60 , - 1 , - 1 , 155 , 64 , 65 ,
# 1840 "y.tab.c"
66 , 67 , 68 , - 1 , 70 , 71 , - 1 , 64 , 65 , 66 , 67 , 68 ,
# 1840 "y.tab.c"
69 , 70 , 71 , 72 , - 1 , 74 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 180 , 43 , 90 , 91 , 92 , 93 , 94 , - 1 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
90 , 54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 , 71 , 155 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 180 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 43 , 90 , 91 , 92 , 93 , 94 , - 1 , 50 , 180 , 52 , -
# 1840 "y.tab.c"
1 , 54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 , 71 , 155 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 180 , 43 , 90 , 91 , 92 , 93 , 94 , - 1 , 50 , - 1 , 52 ,
# 1840 "y.tab.c"
- 1 , 54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 , 71 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 180 , 43 , 90 , 91 , 92 , 93 , 94 , - 1 , 50 , -
# 1840 "y.tab.c"
1 , 52 , - 1 , 54 , 55 , - 1 , - 1 , 58 , - 1 , 60 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 ,
# 1840 "y.tab.c"
71 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 180 , 43 , 90 , 91 , 92 , 93 , 94 , - 1 ,
# 1840 "y.tab.c"
50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 , 58 , -
# 1840 "y.tab.c"
1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , -
# 1840 "y.tab.c"
1 , 70 , 71 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , 180 , 43 , 90 , 91 , 92 , 93 , 94 ,
# 1840 "y.tab.c"
- 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , 43 , 58 ,
# 1840 "y.tab.c"
- 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 ,
# 1840 "y.tab.c"
- 1 , 70 , 71 , 58 , - 1 , 60 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
64 , 65 , 66 , 67 , 68 , - 1 , 70 , 71 , - 1 , - 1 , 180 ,
# 1840 "y.tab.c"
- 1 , 90 , 91 , 92 , 93 , 94 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 90 , 91 , 92 ,
# 1840 "y.tab.c"
93 , 94 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 ,
# 1840 "y.tab.c"
58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 ,
# 1840 "y.tab.c"
68 , 69 , 70 , 71 , 72 , - 1 , - 1 , 180 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , 90 , 91 , 92 , 93 ,
# 1840 "y.tab.c"
94 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , -
# 1840 "y.tab.c"
1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 ,
# 1840 "y.tab.c"
67 , 68 , 69 , 70 , 71 , 72 , - 1 , - 1 , 180 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 180 , 90 , 91 , 92 , 93 ,
# 1840 "y.tab.c"
94 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 , 58 ,
# 1840 "y.tab.c"
- 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 ,
# 1840 "y.tab.c"
69 , 70 , 71 , 72 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 180 , 90 , 91 , 92 , 93 , 94 ,
# 1840 "y.tab.c"
- 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 ,
# 1840 "y.tab.c"
58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 ,
# 1840 "y.tab.c"
68 , 69 , 70 , 71 , 72 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 180 , 90 , 91 , 92 , 93 ,
# 1840 "y.tab.c"
94 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 , 58 ,
# 1840 "y.tab.c"
- 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 ,
# 1840 "y.tab.c"
69 , 70 , 71 , 72 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , 180 , 90 , 91 , 92 , 93 , 94 ,
# 1840 "y.tab.c"
- 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 ,
# 1840 "y.tab.c"
58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 ,
# 1840 "y.tab.c"
68 , 69 , 70 , 71 , 72 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 180 , 90 , 91 , 92 , 93 ,
# 1840 "y.tab.c"
94 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , - 1 , 58 ,
# 1840 "y.tab.c"
- 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 ,
# 1840 "y.tab.c"
69 , 70 , 71 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 180 , 90 , 91 , 92 , 93 ,
# 1840 "y.tab.c"
94 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , -
# 1840 "y.tab.c"
1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 ,
# 1840 "y.tab.c"
67 , 68 , - 1 , 70 , 71 , 72 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 180 , 90 , 91 ,
# 1840 "y.tab.c"
92 , 93 , 94 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 , -
# 1840 "y.tab.c"
1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 ,
# 1840 "y.tab.c"
67 , 68 , 69 , 70 , 71 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 180 , 90 , 91 ,
# 1840 "y.tab.c"
92 , 93 , 94 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , -
# 1840 "y.tab.c"
1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 ,
# 1840 "y.tab.c"
65 , 66 , 67 , 68 , 69 , 70 , 71 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 180 ,
# 1840 "y.tab.c"
90 , 91 , 92 , 93 , 94 , 50 , - 1 , 52 , - 1 , 54 , 55 , -
# 1840 "y.tab.c"
1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 ,
# 1840 "y.tab.c"
65 , 66 , 67 , 68 , - 1 , 70 , 71 , 72 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 180 ,
# 1840 "y.tab.c"
90 , 91 , 92 , 93 , 94 , - 1 , 50 , - 1 , 52 , - 1 , 54 ,
# 1840 "y.tab.c"
55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 , 71 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 180 , 90 , 91 , 92 , 93 , 94 , 50 , - 1 , 52 , - 1 ,
# 1840 "y.tab.c"
54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 180 , 90 , 91 , 92 , 93 , 94 , - 1 , 50 , -
# 1840 "y.tab.c"
1 , 52 , - 1 , 54 , 55 , - 1 , - 1 , 58 , - 1 , 60 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 58 , 70 , 60 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , - 1 , 70 ,
# 1840 "y.tab.c"
71 , - 1 , - 1 , 74 , - 1 , - 1 , - 1 , 180 , 90 ,
# 1840 "y.tab.c"
91 , 92 , 93 , 94 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 90 , 91 , 92 , 93 , 94 , 58 , - 1 , 60 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 58 , - 1 ,
# 1840 "y.tab.c"
60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , - 1 ,
# 1840 "y.tab.c"
70 , 71 , 180 , - 1 , - 1 , - 1 , 90 , 91 , 92 , 93 , 94 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , 41 , - 1 , 43 ,
# 1840 "y.tab.c"
- 1 , 90 , 91 , 92 , 93 , 94 , 50 , - 1 , 52 , - 1 , 54 ,
# 1840 "y.tab.c"
55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 180 , 74 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 180 , - 1 , - 1 , 41 , - 1 , 43 , 90 , 91 , 92 ,
# 1840 "y.tab.c"
93 , 94 , - 1 , 50 , - 1 , 52 , - 1 , 54 , 55 , - 1 ,
# 1840 "y.tab.c"
- 1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 ,
# 1840 "y.tab.c"
66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , 180 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 180 , 90 , 91 , 92 , 93 ,
# 1840 "y.tab.c"
94 , - 1 , - 1 , 41 , - 1 , 43 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , 52 , 155 , 54 ,
# 1840 "y.tab.c"
55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 41 , - 1 , 43 , - 1 , - 1 , - 1 , 90 ,
# 1840 "y.tab.c"
91 , 92 , - 1 , 94 , 52 , - 1 , 54 , 55 , 155 , - 1 , 58 ,
# 1840 "y.tab.c"
- 1 , 60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 ,
# 1840 "y.tab.c"
69 , 70 , 71 , 72 , - 1 , 74 , - 1 , 41 , - 1 , 43 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 52 , - 1 , - 1 , 90 , 91 , 92 , 58 , 94 , 60 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , -
# 1840 "y.tab.c"
1 , 74 , - 1 , 41 , 155 , 43 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 52 , - 1 , - 1 ,
# 1840 "y.tab.c"
90 , 91 , 92 , 58 , 94 , 60 , - 1 , - 1 , - 1 , 64 , 65 ,
# 1840 "y.tab.c"
66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , 74 , - 1 , 41 , -
# 1840 "y.tab.c"
1 , 43 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
155 , - 1 , 52 , - 1 , - 1 , 90 , 91 , 92 , 58 , - 1 ,
# 1840 "y.tab.c"
60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 ,
# 1840 "y.tab.c"
71 , 72 , - 1 , 74 , - 1 , 41 , - 1 , 43 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , 155 , - 1 , 52 , -
# 1840 "y.tab.c"
1 , - 1 , 90 , 91 , 92 , 58 , - 1 , 60 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 41 , 74 , 43 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 52 , 155 , - 1 , - 1 , - 1 , - 1 , 90 , 91 ,
# 1840 "y.tab.c"
92 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 ,
# 1840 "y.tab.c"
71 , 72 , - 1 , 74 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 155 , - 1 , 90 , - 1 , 92 , 617 , 618 , 619 , 620 ,
# 1840 "y.tab.c"
621 , 622 , 623 , 624 , 625 , 626 , 627 , 628 , 629 , 630 , 631 , 632 , 633 , 634 ,
# 1840 "y.tab.c"
635 , - 1 , - 1 , - 1 , - 1 , 50 , - 1 , 52 , -
# 1840 "y.tab.c"
1 , 54 , 55 , - 1 , 155 , 58 , - 1 , 60 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 155 , 90 , 91 , 92 , 93 , 94 , - 1 , 50 , 687 , 52 , - 1 ,
# 1840 "y.tab.c"
54 , 55 , - 1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 90 , 91 , 92 , 93 , 94 , 52 , - 1 , 54 , 55 , -
# 1840 "y.tab.c"
1 , - 1 , 58 , - 1 , 60 , - 1 , - 1 , - 1 , 64 ,
# 1840 "y.tab.c"
65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
90 , 91 , 92 , 52 , 94 , 54 , 55 , - 1 , - 1 , 58 , - 1 ,
# 1840 "y.tab.c"
60 , - 1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 ,
# 1840 "y.tab.c"
71 , 72 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , 52 , - 1 , - 1 , 90 , 91 , 92 , 58 , 94 , 60 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
52 , - 1 , - 1 , 90 , 91 , 92 , 58 , 94 , 60 , - 1 , -
# 1840 "y.tab.c"
1 , - 1 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
52 , - 1 , - 1 , - 1 , - 1 , - 1 , 58 , - 1 ,
# 1840 "y.tab.c"
60 , 90 , 91 , 92 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , -
# 1840 "y.tab.c"
1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , -
# 1840 "y.tab.c"
1 , 52 , - 1 , - 1 , - 1 , - 1 , - 1 , 58 , -
# 1840 "y.tab.c"
1 , 60 , 90 , 91 , 92 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 ,
# 1840 "y.tab.c"
- 1 , - 1 , - 1 , 90 , 91 , 92 } ;

# 3121 "y.tab.c"
int yyerrflag = 0 ;
int yychar = 0 ;
union YYSTYPE yyval = { 0 } ;
union YYSTYPE yylval = { 0 } ;
int yynerrs = 0 ;
struct __C1;

# 3149 "y.tab.c"
typedef struct YYSTACKDATA YYSTACKDATA ;

# 3149 "y.tab.c"
struct YYSTACKDATA {	/* sizeof YYSTACKDATA == 48 */

# 3143 "y.tab.c"
unsigned int stacksize__11YYSTACKDATA ;
int *s_base__11YYSTACKDATA ;
int *s_mark__11YYSTACKDATA ;
int *s_last__11YYSTACKDATA ;
union YYSTYPE *l_base__11YYSTACKDATA ;
union YYSTYPE *l_mark__11YYSTACKDATA ;
};

# 3151 "y.tab.c"
static struct YYSTACKDATA yystack ;

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 3041 "gram.y"
static Pname enumcheck__FP4name (Pname __1n )
# 3042 "gram.y"
{ 
# 3043 "gram.y"
Ptype __1tx ;

# 3043 "gram.y"
__1tx = __1n -> __O1__4expr.tp ;
if (__1tx -> base__4node == 97 ){ 
# 3045 "gram.y"
Pname __2bn ;

# 3045 "gram.y"
__2bn = (((struct basetype *)(((struct basetype *)__1tx ))))-> b_name__8basetype ;
__1tx = __2bn -> __O1__4expr.tp ;
if ((__1tx -> base__4node != 121 )|| strcmp ( __2bn -> __O2__4expr.string , __1n -> __O2__4expr.string ) )
# 3050 "gram.y"
{ 
# 3050 "gram.y"
struct ea __0__V48 ;

# 3050 "gram.y"
struct ea __0__V49 ;

# 3050 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"%n ofT%t redeclared as enum.", (const struct ea *)( ((& __0__V48 )-> __O1__2ea.p =
# 3050 "gram.y"
((const void *)__1n )), (& __0__V48 )) , (const struct ea *)( ((& __0__V49 )-> __O1__2ea.p = ((const void
# 3050 "gram.y"
*)__1tx )), (& __0__V49 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __1n = __2bn ;
}
else 
# 3052 "gram.y"
if (__1tx -> base__4node != 121 )
# 3053 "gram.y"
{ 
# 3053 "gram.y"
struct ea __0__V50 ;

# 3053 "gram.y"
struct ea __0__V51 ;

# 3053 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"%n ofT%t redeclared as enum", (const struct ea *)( ((& __0__V50 )-> __O1__2ea.p =
# 3053 "gram.y"
((const void *)__1n )), (& __0__V50 )) , (const struct ea *)( ((& __0__V51 )-> __O1__2ea.p = ((const void
# 3053 "gram.y"
*)__1tx )), (& __0__V51 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 3056 "gram.y"
return __1n ;
}

# 1256 "/home/claude/cfront-3/src/cfront.h"
extern TOK lalex__Fv (void );

# 3060 "gram.y"
static void check_tag__Fv (void )
# 3066 "gram.y"
{ 
# 3067 "gram.y"
switch ((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar ){ 
# 3068 "gram.y"
case
# 3068 "gram.y"
72 :case 69 :case 73 :
# 3069 "gram.y"
declTag = 1 ;
break ;
default :
# 3072 "gram.y"
declTag = 0 ;
break ;
}
}

# 217 "gram.y"

# 128 "gram.y"

# 223 "gram.y"

# 264 "/home/claude/cfront-3/src/cfront.h"
void hoist__6ktableFv (struct ktable *__0this );

# 128 "gram.y"

# 3078 "gram.y"
static void hoist_al__Fv (void )
# 3083 "gram.y"
{ 
# 3084 "gram.y"
if (Ctbl -> k_id__6ktable != 136 ){ 
# 3088 "gram.y"
Pktab __2otbl ;

# 3089 "gram.y"
const void *__2__X38 ;

# 3089 "gram.y"
struct ea __0__X__V3700atejpkkfwcgn ;

# 3089 "gram.y"
struct ktable *__1__X52 ;

# 3089 "gram.y"
const void *__2__X40 ;

# 3089 "gram.y"
struct ea __0__X__V3900qmejpkkfwcpm ;

# 3088 "gram.y"
__2otbl = Ctbl ;
Ctbl = ( (((scopex - 1 )< 0 )?error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"parsing scope stack underflow -- current table %s",
# 3089 "gram.y"
(const struct ea *)( (__2__X38 = (const void *)whereami__6ktableFv ( Ctbl ) ), ( ((& __0__X__V3700atejpkkfwcgn )-> __O1__2ea.p = __2__X38 ),
# 3089 "gram.y"
(& __0__X__V3700atejpkkfwcgn )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) :0 ),
# 3089 "gram.y"
(scopestack [(scopex - 1 )]). ktbl__8pcontext ) ;
if (Ctbl -> k_id__6ktable != 136 )error__FiPCc ( (int )'i' , (const char *)"hoist_al: noA table") ;
# 3090 "gram.y"

# 3091 "gram.y"

# 3091 "gram.y"
{ 
# 3091 "gram.y"
;

# 3091 "gram.y"
if (Ctbl == Gtbl )
# 3091 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"bad parsing table") ;

# 3091 "gram.y"
{ 
# 3091 "gram.y"
Pktab __1b ;

# 3091 "gram.y"
__1b = Ctbl ;

# 3091 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;

# 3091 "gram.y"
if ((__1b -> k_id__6ktable == 136 )|| 0 )
# 3091 "gram.y"
__dt__6ktableFv ( __1b , 3) ;

# 3091 "gram.y"
}

# 135 "gram.y"
}

# 3092 "gram.y"
( (__1__X52 = Ctbl ), ( ( (((scopex - 1 )< 0 )?error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"parsing scope stack underflow -- current table %s",
# 3092 "gram.y"
(const struct ea *)( (__2__X40 = (const void *)whereami__6ktableFv ( Ctbl ) ), ( ((& __0__X__V3900qmejpkkfwcpm )-> __O1__2ea.p = __2__X40 ),
# 3092 "gram.y"
(& __0__X__V3900qmejpkkfwcpm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) :0 ),
# 3092 "gram.y"
((scopestack [(scopex - 1 )]). ktbl__8pcontext = __1__X52 )) , (((void )0 ))) ) ;
Ctbl = __2otbl ;
return ;
}
if ((! in_typedef )&& (! in_friend ))hoist__6ktableFv ( Ctbl ) ;

# 3097 "gram.y"
{ 
# 3097 "gram.y"
;

# 3097 "gram.y"
if (Ctbl == Gtbl )
# 3097 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"bad parsing table") ;

# 3097 "gram.y"
{ 
# 3097 "gram.y"
Pktab __1b ;

# 3097 "gram.y"
__1b = Ctbl ;

# 3097 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;

# 3097 "gram.y"
if ((__1b -> k_id__6ktable == 136 )|| 0 )
# 3097 "gram.y"
__dt__6ktableFv ( __1b , 3) ;

# 3097 "gram.y"
}

# 135 "gram.y"
}

# 3098 "gram.y"
}

# 116 "/home/claude/cfront-3/src/cfront.h"
extern Pname insert_name__FP4nameP6ktable (Pname , Pktab );

# 3100 "gram.y"
static void arg_redec__FP4name (Pname __1fn )
# 3104 "gram.y"
{ 
# 3105 "gram.y"
if ((__1fn == 0 )|| (__1fn -> __O1__4expr.tp -> base__4node != 108 ))
# 3106 "gram.y"
{ 
# 3106 "gram.y"
struct ea __0__V53 ;

# 3106 "gram.y"
struct ea __0__V54 ;

# 3106 "gram.y"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"bad inline rewrite! --%n %t", (const struct ea *)( ((&
# 3106 "gram.y"
__0__V53 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V53 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V54 , (const
# 3106 "gram.y"
void *)(__1fn ?__1fn -> __O1__4expr.tp :(((struct type *)0 )))) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (Ctbl -> k_id__6ktable != 136 )
# 3108 "gram.y"
{ 
# 3108 "gram.y"
struct ea __0__V55 ;

# 3108 "gram.y"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"arg_redec(%n ) -- noA table", (const struct ea *)( ((&
# 3108 "gram.y"
__0__V55 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V55 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 3108 "gram.y"
(const struct ea *)ea0 ) ;
} 
# 3111 "gram.y"
{ Pname __1al ;
Pname __1n ;

# 3111 "gram.y"
__1al = (((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))))-> argtype__3fct ;
__1n = 0 ;
for(;__1al ;__1al = __1al -> __O1__4name.n_list ) { 
# 3114 "gram.y"
;
__1n = __ct__4nameFPCc ( (struct name *)0 , __1al -> __O2__4expr.string ) ;
insert_name__FP4nameP6ktable ( __1n , Ctbl ) ;
;
}

# 3118 "gram.y"
}
}

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 633 "/home/claude/cfront-3/src/cfront.h"
struct fct *__ct__3fctFP4typeP4nameUc (struct fct *__0this , Ptype , Pname , TOK );

# 3122 "gram.y"
static Pname dummy_dtor__FUcT1 (TOK __1q , TOK __1d )
# 3123 "gram.y"
{ 
# 3124 "gram.y"
if (__1q != __1d ){ 
# 3125 "gram.y"
error__FPCc ( (const char *)"syntax error: inconsistent destructor notation")
# 3125 "gram.y"
;
__1q = __1d ;
}
{ Pname __1dt ;

# 3128 "gram.y"
__1dt = __ct__4nameFPCc ( (struct name *)0 , (const char *)"type destructor") ;
__1dt -> base__4node = 162 ;
__1dt -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)void_type , (struct name *)0 , (unsigned char )1 ) ;
# 3130 "gram.y"

# 3131 "gram.y"
__1dt -> n_dcl_printed__4name = 1 ;
switch (__1d ){ 
# 3133 "gram.y"
default :
# 3134 "gram.y"
error__FPCc ( (const char *)"syntax error: illegal destructor notation") ;
__1dt -> __O4__4expr.tp2 = (struct type *)any_type ;
break ;
case 5 :
# 3138 "gram.y"
__1dt -> __O4__4expr.tp2 = (__1dt -> __O3__4expr.tpdef = (struct type *)char_type );
break ;
case 29 :
# 3141 "gram.y"
__1dt -> __O4__4expr.tp2 = (__1dt -> __O3__4expr.tpdef = (struct type *)short_type );
break ;
case 171 :
# 3144 "gram.y"
case 21 :
# 3145 "gram.y"
__1dt -> __O4__4expr.tp2 = (__1dt -> __O3__4expr.tpdef = (struct type *)int_type );
break ;
case 37 :
# 3148 "gram.y"
__1dt -> __O4__4expr.tp2 = (__1dt -> __O3__4expr.tpdef = (struct type *)uint_type );
break ;
case 22 :
# 3151 "gram.y"
__1dt -> __O4__4expr.tp2 = (__1dt -> __O3__4expr.tpdef = (struct type *)long_type );
break ;
case 15 :
# 3154 "gram.y"
__1dt -> __O4__4expr.tp2 = (__1dt -> __O3__4expr.tpdef = (struct type *)float_type );
break ;
case 11 :
# 3157 "gram.y"
__1dt -> __O4__4expr.tp2 = (__1dt -> __O3__4expr.tpdef = (struct type *)double_type );
break ;
case 38 :
# 3160 "gram.y"
__1dt -> __O4__4expr.tp2 = (__1dt -> __O3__4expr.tpdef = (struct type *)void_type );
break ;
}
return __1dt ;

# 3163 "gram.y"
}
}

# 3166 "gram.y"
static Pname dummy_dtor__Fv (void )
# 3167 "gram.y"
{ 
# 3168 "gram.y"
Pname __1dt ;

# 3168 "gram.y"
__1dt = __ct__4nameFPCc ( (struct name *)0 , (const char *)"type destructor") ;
__1dt -> base__4node = 162 ;
__1dt -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)void_type , (struct name *)0 , (unsigned char )1 ) ;
# 3170 "gram.y"

# 3171 "gram.y"
__1dt -> n_dcl_printed__4name = 1 ;
__1dt -> __O4__4expr.tp2 = 0 ;
__1dt -> __O3__4expr.tpdef = 0 ;
return __1dt ;
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 3178 "gram.y"
static bit check_if_base__FP8classdefT1 (Pclass __1c1 , Pclass __1c2 );

# 3178 "gram.y"
static bit check_if_base__FP8classdefT1 (Pclass __1c1 , Pclass __1c2 )
# 3179 "gram.y"
{ 
# 3179 "gram.y"
struct classdef *__1__X56 ;

# 3179 "gram.y"
struct classdef *__1__X57 ;

# 3180 "gram.y"
if (( (__1__X56 = __1c1 ), ( (__1__X57 = __1c2 ), ( ((__1__X56 == __1__X57 )?1 :((__1__X56 && __1__X57 )?(((int )same_class__8classdefFP8classdefi ( __1__X56 , __1__X57 ,
# 3180 "gram.y"
0 ) )):0 ))) ) ) )return (unsigned char )1 ;
{ { Pbcl __1b ;

# 3181 "gram.y"
__1b = __1c1 -> baselist__8classdef ;

# 3181 "gram.y"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 3181 "gram.y"
struct classdef *__1__X58 ;

# 3181 "gram.y"
struct classdef *__1__X59 ;

# 3182 "gram.y"
if (( (__1__X58 = __1b -> bclass__6basecl ), ( (__1__X59 = __1c2 ), ( ((__1__X58 == __1__X59 )?1 :((__1__X58 && __1__X59 )?(((int )same_class__8classdefFP8classdefi ( __1__X58 ,
# 3182 "gram.y"
__1__X59 , 0 ) )):0 ))) ) ) )return (unsigned char )1 ;
if (check_if_base__FP8classdefT1 ( __1b -> bclass__6basecl , __1c2 ) )return (unsigned char )1 ;
}
return (unsigned char )0 ;

# 3185 "gram.y"
}

# 3185 "gram.y"
}
}

# 10 "/home/claude/incl-linux32/malloc.h"
extern void *realloc (void *, size_t );

# 3311 "y.tab.c"
static int yygrowstack__FP11YYSTACKDATA (struct YYSTACKDATA *__1data )
# 3312 "y.tab.c"
{ 
# 3313 "y.tab.c"
int __1i ;
unsigned int __1newsize ;
int *__1newss ;
union YYSTYPE *__1newvs ;

# 3318 "y.tab.c"
if ((__1newsize = __1data -> stacksize__11YYSTACKDATA )== 0 )
# 3319 "y.tab.c"
__1newsize = 200 ;
else if (__1newsize >= 600 )
# 3321 "y.tab.c"
return -2;
else if ((__1newsize *= 2 )> 600 )
# 3323 "y.tab.c"
__1newsize = 600 ;

# 3325 "y.tab.c"
__1i = (((int )(__1data -> s_mark__11YYSTACKDATA - __1data -> s_base__11YYSTACKDATA )));
__1newss = (((int *)realloc ( (void *)__1data -> s_base__11YYSTACKDATA , __1newsize * (sizeof ((*__1newss )))) ));
if (__1newss == 0 )
# 3328 "y.tab.c"
return -2;

# 3330 "y.tab.c"
__1data -> s_base__11YYSTACKDATA = __1newss ;
__1data -> s_mark__11YYSTACKDATA = (__1newss + __1i );

# 3333 "y.tab.c"
__1newvs = (((union YYSTYPE *)(((union YYSTYPE *)realloc ( (void *)__1data -> l_base__11YYSTACKDATA , __1newsize * (sizeof ((*__1newvs )))) ))));
if (__1newvs == 0 )
# 3335 "y.tab.c"
return -2;

# 3337 "y.tab.c"
__1data -> l_base__11YYSTACKDATA = __1newvs ;
__1data -> l_mark__11YYSTACKDATA = (__1newvs + __1i );

# 3340 "y.tab.c"
__1data -> stacksize__11YYSTACKDATA = __1newsize ;
__1data -> s_last__11YYSTACKDATA = ((__1data -> s_base__11YYSTACKDATA + __1newsize )- 1 );
return 0 ;
}

# 1142 "/home/claude/cfront-3/src/cfront.h"
extern void yyerror__FPCc (const char *);

# 31 "/home/claude/incl-linux32/string.h"
extern void *memset (void *, int , size_t );

# 596 "/home/claude/cfront-3/src/cfront.h"
extern void set_linkage__FPCc (const char *);

# 121 "gram.y"

# 80 "/home/claude/cfront-3/src/template.h"
struct templ_state *__ct__11templ_stateFv (struct templ_state *__0this );

# 124 "/home/claude/cfront-3/src/template.h"
void start__17templ_compilationFv (struct templ_compilation *__0this );

# 141 "/home/claude/cfront-3/src/template.h"
void enter_parameters__17templ_compilationFv (struct templ_compilation *__0this );

# 125 "/home/claude/cfront-3/src/template.h"
void end__17templ_compilationFP4name (struct templ_compilation *__0this , Pname __1class_name );

# 128 "gram.y"

# 226 "/home/claude/cfront-3/src/cfront.h"
void reinit__5tableFv (struct table *__0this );

# 584 "/home/claude/cfront-3/src/cfront.h"
Pname aggr__8basetypeFv (struct basetype *__0this );

# 369 "gram.y"

# 37 "/home/claude/cfront-3/src/cfront.h"
extern char *make_name__FUc (TOK );

# 579 "/home/claude/cfront-3/src/cfront.h"
struct basetype *__ct__8basetypeFUcP4name (struct basetype *__0this , TOK , Pname );

# 935 "/home/claude/cfront-3/src/cfront.h"
Pname normalize__4nameFP8basetypeP5blockUc (struct name *__0this , Pbase , Pblock , bit );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 634 "/home/claude/cfront-3/src/cfront.h"
void argdcl__3fctFP4nameT1 (struct fct *__0this , Pname , Pname );

# 1095 "/home/claude/cfront-3/src/cfront.h"
extern Pname name_unlist__FP5nlist (struct nlist *);

# 22 "/home/claude/cfront-3/src/tqueue.h"
struct toknode {	/* sizeof toknode == 48 */
TOK tok__7toknode ;
bit used__7toknode ;
union YYSTYPE retval__7toknode ;
Pname idname__7toknode ;
struct loc place__7toknode ;
struct toknode *next__7toknode ;
struct toknode *last__7toknode ;
};

# 30 "/home/claude/cfront-3/src/tqueue.h"
extern struct toknode *free_toks__7toknode ;

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 326 "/home/claude/cfront-3/src/template.h"

# 88 "gram.y"

# 46 "/home/claude/cfront-3/src/tqueue.h"
extern void la_backup__FUc7YYSTYPE (TOK , union YYSTYPE );

# 53 "/home/claude/cfront-3/src/tqueue.h"
extern struct toknode *save_text__Fv (void );

# 128 "gram.y"

# 369 "gram.y"

# 1092 "/home/claude/cfront-3/src/cfront.h"
void add_list__5nlistFP4name (struct nlist *__0this , Pname );

# 1090 "/home/claude/cfront-3/src/cfront.h"
struct nlist *__ct__5nlistFP4name (struct nlist *__0this , Pname );

# 88 "gram.y"

# 45 "/home/claude/cfront-3/src/tqueue.h"
extern TOK la_look__Fv (void );

# 1091 "/home/claude/cfront-3/src/cfront.h"

# 48 "/home/claude/cfront-3/src/tqueue.h"
extern void check_decl__Fv (void );

# 144 "/home/claude/cfront-3/src/template.h"
Pname check_tname__17templ_compilationFP4name (struct templ_compilation *__0this , Pname __1p );

# 1113 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr expr_unlist__FP5elist (struct elist *);

# 161 "/home/claude/cfront-3/src/template.h"
extern Pname parametrized_typename__FP4nameP4exprUc (Pname __0p , Pexpr __0actuals , bit );

# 936 "/home/claude/cfront-3/src/cfront.h"
Pname tdef__4nameFv (struct name *__0this );

# 362 "/home/claude/cfront-3/src/cfront.h"
void del__4typeFv (struct type *__0this );

# 581 "/home/claude/cfront-3/src/cfront.h"
Pbase type_adj__8basetypeFUc (struct basetype *__0this , TOK );

# 583 "/home/claude/cfront-3/src/cfront.h"
Pbase name_adj__8basetypeFP4name (struct basetype *__0this , Pname );

# 582 "/home/claude/cfront-3/src/cfront.h"
Pbase base_adj__8basetypeFP8basetype (struct basetype *__0this , Pbase );

# 1110 "/home/claude/cfront-3/src/cfront.h"

# 1109 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 286 "/home/claude/cfront-3/src/cfront.h"
extern Pbase end_enum__FP4nameP5nlist (Pname , struct nlist *);

# 1091 "/home/claude/cfront-3/src/cfront.h"

# 138 "/home/claude/cfront-3/src/template.h"
void collect__17templ_compilationFUcP4name (struct templ_compilation *__0this , TOK __1parm_type , Pname __1namep );
void collect__17templ_compilationFP4name (struct templ_compilation *__0this , Pname );

# 54 "/home/claude/cfront-3/src/tqueue.h"
extern void restore_text__Fv (void );

# 128 "gram.y"

# 423 "/home/claude/cfront-3/src/template.h"
void explicit_inst__10templ_instFv (struct templ_inst *__0this );

# 1259 "/home/claude/cfront-3/src/cfront.h"

# 285 "/home/claude/cfront-3/src/cfront.h"
extern void end_cl__Fv (void );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 147 "/home/claude/cfront-3/src/template.h"
Ptempl is_template__17templ_compilationFP4name (struct templ_compilation *__0this , Pname );

# 214 "/home/claude/cfront-3/src/template.h"
int check_actual_args__5templFP4expr (struct templ *__0this , Pexpr );

# 213 "/home/claude/cfront-3/src/template.h"
Ptempl_inst get_match__5templFP4exprP10templ_inst4bool (struct templ *__0this , Pexpr , Ptempl_inst , int );

# 432 "/home/claude/cfront-3/src/template.h"

# 404 "/home/claude/cfront-3/src/template.h"
struct templ_inst *__ct__10templ_instFP4exprP5templUc (struct templ_inst *__0this , Pexpr __1act , Ptempl __1owner , TOK __1csu );

# 193 "/home/claude/cfront-3/src/template.h"

# 326 "/home/claude/cfront-3/src/template.h"

# 284 "/home/claude/cfront-3/src/cfront.h"
extern Pname start_cl__FUcP4nameP6basecl (TOK , Pname , Pbcl );

# 95 "gram.y"

# 432 "/home/claude/cfront-3/src/template.h"

# 326 "/home/claude/cfront-3/src/template.h"

# 95 "gram.y"

# 50 "/home/claude/cfront-3/src/template.h"

# 369 "gram.y"

# 262 "gram.y"
extern void sig_name__FP4name (Pname );

# 369 "gram.y"

# 120 "/home/claude/cfront-3/src/cfront.h"
extern const char *oper_name__FUc (TOK );

# 369 "gram.y"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 369 "gram.y"

# 938 "/home/claude/cfront-3/src/cfront.h"
void hide__4nameFv (struct name *__0this );

# 128 "gram.y"

# 369 "gram.y"

# 264 "gram.y"
extern void memptrdcl__FP4nameT1P4typeT1 (Pname , Pname , Ptype , Pname );

# 369 "gram.y"

# 1101 "/home/claude/cfront-3/src/cfront.h"

# 1100 "/home/claude/cfront-3/src/cfront.h"

# 106 "gram.y"

# 1104 "/home/claude/cfront-3/src/cfront.h"
extern Pstmt stmt_unlist__FP5slist (struct slist *);

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 128 "gram.y"

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 128 "gram.y"

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 128 "gram.y"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1059 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 1050 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1064 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1059 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1077 "/home/claude/cfront-3/src/cfront.h"

# 1101 "/home/claude/cfront-3/src/cfront.h"

# 1100 "/home/claude/cfront-3/src/cfront.h"

# 1109 "/home/claude/cfront-3/src/cfront.h"

# 1110 "/home/claude/cfront-3/src/cfront.h"

# 840 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 369 "gram.y"

# 19 "/home/claude/incl-linux32/string.h"
extern char *strdup (const char *);

# 263 "gram.y"
extern Ptype tok_to_type__FUc (TOK );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 958 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 832 "/home/claude/cfront-3/src/cfront.h"

# 260 "/home/claude/cfront-3/src/cfront.h"
Pname look__6ktableFPCcUc (struct ktable *__0this , const char *, TOK );

# 49 "/home/claude/cfront-3/src/tqueue.h"
extern void check_cast__Fv (void );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 88 "gram.y"

# 128 "gram.y"

# 1091 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 958 "/home/claude/cfront-3/src/cfront.h"

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

# 75 "/home/claude/cfront-3/src/template.h"
struct templ_state {	/* sizeof templ_state == 56 */

# 83 "/home/claude/cfront-3/src/template.h"
Plist param_end__11templ_state ;
Plist params__11templ_state ;
Pcons templ_refs__11templ_state ;
Pcons friend_templ_refs__11templ_state ;
Pcons last_cons__11templ_state ;
Pcons last_friend_cons__11templ_state ;
Ptempl owner__11templ_state ;
};

# 1 ""

# 81 "/home/claude/cfront-3/src/template.h"
void __dt__11templ_stateFv (struct templ_state *__0this , int );

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 693 "/home/claude/cfront-3/src/cfront.h"

# 3362 "y.tab.c"
int yyparse__Fv (void )
# 3363 "y.tab.c"
{ 
# 3364 "y.tab.c"
int __1yym ;

# 3364 "y.tab.c"
int __1yyn ;

# 3364 "y.tab.c"
int __1yystate ;

# 3378 "y.tab.c"
yynerrs = 0 ;
yyerrflag = 0 ;
yychar = -1;
__1yystate = 0 ;

# 3387 "y.tab.c"
if ((yystack . s_base__11YYSTACKDATA == 0 )&& (yygrowstack__FP11YYSTACKDATA ( & yystack ) == -2))goto yyoverflow ;
yystack . s_mark__11YYSTACKDATA = yystack . s_base__11YYSTACKDATA ;
yystack . l_mark__11YYSTACKDATA = yystack . l_base__11YYSTACKDATA ;
__1yystate = 0 ;
((*yystack . s_mark__11YYSTACKDATA ))= 0 ;

# 3393 "y.tab.c"
yyloop :
# 3394 "y.tab.c"
if ((__1yyn = (yydefred [__1yystate ]))!= 0 )goto yyreduce ;
if (yychar < 0 )
# 3396 "y.tab.c"
{ 
# 3397 "y.tab.c"
yychar = lalex__Fv ( ) ;
if (yychar < 0 )yychar = 0 ;

# 3407 "y.tab.c"
}
if (((((__1yyn = (yysindex [__1yystate ]))!= 0 )&& ((__1yyn += yychar )>= 0 ))&& (__1yyn <= 8259 ))&& ((yycheck [__1yyn ])== (((int )yychar ))))
# 3410 "y.tab.c"
{ 
# 3416 "y.tab.c"
if ((yystack .
# 3416 "y.tab.c"
s_mark__11YYSTACKDATA >= yystack . s_last__11YYSTACKDATA )&& (yygrowstack__FP11YYSTACKDATA ( & yystack ) == -2))goto yyoverflow ;
__1yystate = (yytable [__1yyn ]);
((*(++ yystack . s_mark__11YYSTACKDATA )))= (yytable [__1yyn ]);
((*(++ yystack . l_mark__11YYSTACKDATA )))= yylval ;
yychar = -1;
if (yyerrflag > 0 )-- yyerrflag ;
goto yyloop ;
}
if (((((__1yyn = (yyrindex [__1yystate ]))!= 0 )&& ((__1yyn += yychar )>= 0 ))&& (__1yyn <= 8259 ))&& ((yycheck [__1yyn ])== (((int )yychar ))))
# 3426 "y.tab.c"
{ 
# 3427 "y.tab.c"
__1yyn = (yytable [__1yyn ]);
# 3427 "y.tab.c"

# 3428 "y.tab.c"
goto yyreduce ;
}
if (yyerrflag != 0 )goto yyinrecovery ;

# 3432 "y.tab.c"
yyerror__FPCc ( (const char *)"syntax error") ;

# 3434 "y.tab.c"
goto yyerrlab ;
yyerrlab :
# 3436 "y.tab.c"
++ yynerrs ;

# 3438 "y.tab.c"
yyinrecovery :
# 3439 "y.tab.c"
if (yyerrflag < 3 )
# 3440 "y.tab.c"
{ 
# 3441 "y.tab.c"
yyerrflag = 3 ;
for(;;) 
# 3443 "y.tab.c"
{ 
# 3444 "y.tab.c"
if (((((__1yyn = (yysindex [((*yystack . s_mark__11YYSTACKDATA ))]))!= 0 )&& ((__1yyn += 256 )>= 0 ))&& (__1yyn <= 8259 ))&& ((yycheck [__1yyn ])== (((int
# 3444 "y.tab.c"
)256 ))))
# 3446 "y.tab.c"
{ 
# 3452 "y.tab.c"
if ((yystack . s_mark__11YYSTACKDATA >= yystack . s_last__11YYSTACKDATA )&& (yygrowstack__FP11YYSTACKDATA ( & yystack ) == -2))goto yyoverflow ;
__1yystate = (yytable [__1yyn ]);
((*(++ yystack . s_mark__11YYSTACKDATA )))= (yytable [__1yyn ]);
((*(++ yystack . l_mark__11YYSTACKDATA )))= yylval ;
goto yyloop ;
}
else 
# 3459 "y.tab.c"
{ 
# 3465 "y.tab.c"
if (yystack . s_mark__11YYSTACKDATA <= yystack . s_base__11YYSTACKDATA )goto yyabort ;
-- yystack . s_mark__11YYSTACKDATA ;
-- yystack . l_mark__11YYSTACKDATA ;
}
}
}
else 
# 3472 "y.tab.c"
{ 
# 3473 "y.tab.c"
if (yychar == 0 )goto yyabort ;

# 3482 "y.tab.c"
yychar = -1;
goto yyloop ;
}

# 3486 "y.tab.c"
yyreduce :
# 3492 "y.tab.c"
__1yym = (yylen [__1yyn ]);
if (__1yym > 0 )
# 3494 "y.tab.c"
yyval = yystack . l_mark__11YYSTACKDATA [(1 - __1yym )];
else 
# 3496 "y.tab.c"
memset ( (void *)(& yyval ), 0 , sizeof yyval ) ;

# 3498 "y.tab.c"
switch (__1yyn )
# 3499 "y.tab.c"
{ 
# 3500 "y.tab.c"
case 1 :
# 732 "gram.y"
{ ;

# 732 "gram.y"
return 2 ;

# 732 "gram.y"
}

# 3504 "y.tab.c"
break ;
case 2 :
# 733 "gram.y"
{ ;

# 733 "gram.y"
return 1 ;

# 733 "gram.y"
}

# 3509 "y.tab.c"
break ;
case 3 :
# 734 "gram.y"
{ ;

# 734 "gram.y"
return 0 ;

# 734 "gram.y"
}

# 3514 "y.tab.c"
break ;
case 4 :
# 736 "gram.y"
{ 
# 737 "gram.y"
set_linkage__FPCc ( (yystack . l_mark__11YYSTACKDATA [-1]). s__7YYSTYPE ) ;
bl_level -- ;
;

# 739 "gram.y"
return 1 ;
}

# 3523 "y.tab.c"
break ;
case 5 :
# 742 "gram.y"
{ 
# 743 "gram.y"
set_linkage__FPCc ( (const char *)0 ) ;
bl_level ++ ;
;

# 745 "gram.y"
return 1 ;
}

# 3532 "y.tab.c"
break ;
case 6 :
# 747 "gram.y"
{ ;

# 747 "gram.y"
return 1 ;

# 747 "gram.y"
}

# 3537 "y.tab.c"
break ;
case 7 :
# 751 "gram.y"
{ 
# 752 "gram.y"
( ( ( (Ctbl = __ct__6ktableFiP6ktableP4name ( (struct ktable *)0 , 0 , Ctbl , (struct name *)0 ) ),
# 752 "gram.y"
(Ctbl -> k_id__6ktable = 185 )) ) , (((void )0 ))) ;

# 754 "gram.y"
if (in_class_decl ){ 
# 755 "gram.y"
must_be_friend = 1 ;
if (in_progress__17templ_compilation == 1)
# 757 "gram.y"
save_templ__17templ_compilation = __ct__11templ_stateFv ( (struct templ_state *)0 ) ;
}
else must_be_friend = 0 ;
start__17templ_compilationFv ( templp ) ;
formals_in_progress__17templ_compilation = 1;
}

# 3553 "y.tab.c"
break ;
case 8 :
# 763 "gram.y"
{ in_arg_list = 2 ;

# 763 "gram.y"
}

# 3558 "y.tab.c"
break ;
case 9 :
# 764 "gram.y"
{ 
# 765 "gram.y"
enter_parameters__17templ_compilationFv ( templp ) ;
formals_in_progress__17templ_compilation = 0;
in_arg_list = 0 ;
}

# 3567 "y.tab.c"
break ;
case 10 :
# 770 "gram.y"
{ 
# 771 "gram.y"
end__17templ_compilationFP4name ( templp , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;

# 772 "gram.y"
{ 
# 772 "gram.y"
;

# 772 "gram.y"
if (Ctbl == Gtbl )
# 772 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"bad parsing table") ;

# 772 "gram.y"
{ 
# 772 "gram.y"
Pktab __1b ;

# 772 "gram.y"
__1b = Ctbl ;

# 772 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;

# 772 "gram.y"
if ((__1b -> k_id__6ktable == 136 )|| 0 )
# 772 "gram.y"
__dt__6ktableFv ( __1b , 3) ;

# 772 "gram.y"
}

# 135 "gram.y"
}

# 773 "gram.y"
if (in_class_decl && save_templ__17templ_compilation ){ 
# 774 "gram.y"
__dt__11templ_stateFv ( save_templ__17templ_compilation , 3) ;
save_templ__17templ_compilation = 0 ;
}
else { 
# 778 "gram.y"
in_progress__17templ_compilation = 0;
reinit__5tableFv ( bound_expr_tbl ) ;
}

# 782 "gram.y"
}

# 3584 "y.tab.c"
break ;
case 12 :
# 786 "gram.y"
{ goto mod ;

# 786 "gram.y"
}

# 3589 "y.tab.c"
break ;
case 13 :
# 787 "gram.y"
{ goto mod ;

# 787 "gram.y"
}

# 3594 "y.tab.c"
break ;
case 15 :
# 790 "gram.y"
{ 
# 791 "gram.y"
Pname __3pn ;

# 791 "gram.y"
__3pn = aggr__8basetypeFv ( (yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE ) ;

# 794 "gram.y"
yyval . p__7YYSTYPE = (struct node *)(__3pn ?__3pn :(yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE -> b_name__8basetype );
DECL_TYPE = 0 ;
}

# 3605 "y.tab.c"
break ;
case 17 :
# 801 "gram.y"
{ 
# 801 "gram.y"
struct name *__1__X101 ;

# 801 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 801 "gram.y"
yyval . pn__7YYSTYPE = ( (__1__X101 = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__1__X101 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X101 ), 0 )
# 801 "gram.y"
:( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X101 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X101 -> n_template_arg__4name )) ), __1__Xnn00qycjpkkfwcaj )
# 801 "gram.y"
) ;

# 801 "gram.y"
}

# 3610 "y.tab.c"
break ;
case 18 :
# 805 "gram.y"
{ 
# 807 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE == 0 )yyval . i__7YYSTYPE = 1 ;
}

# 3618 "y.tab.c"
break ;
case 19 :
# 809 "gram.y"
{ goto mod ;

# 809 "gram.y"
}

# 3623 "y.tab.c"
break ;
case 20 :
# 811 "gram.y"
{ mod :
# 812 "gram.y"
{ Pname __3n ;

# 812 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
if (__3n && __3n -> __O2__4name.n_qualifier ){ 
# 814 "gram.y"
if (__3n -> __O2__4name.n_qualifier -> n_template_arg__4name != 1)
# 815 "gram.y"
UNSET_SCOPE__Fv ( ) ;
if (__3n -> __O2__4name.n_qualifier == sta_name )
# 817 "gram.y"
__3n -> __O2__4name.n_qualifier = 0 ;
}

# 818 "gram.y"
}
}

# 3636 "y.tab.c"
break ;
case 22 :
# 822 "gram.y"
{ Pname __3n ;

# 822 "gram.y"
__3n = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'A' ) ) ;
__3n -> __O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )1 , (struct name *)0 ) ;
(((struct basetype *)(((struct basetype *)__3n -> __O1__4expr.tp ))))-> b_name__8basetype = (((struct name *)(((struct name *)(yystack . l_mark__11YYSTACKDATA [-2]). s__7YYSTYPE ))));
yyval . p__7YYSTYPE = (struct node *)__3n ;
}

# 3645 "y.tab.c"
break ;
case 23 :
# 830 "gram.y"
{ 
# 831 "gram.y"
err_name = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ;
if (err_name )err_name -> __O3__4expr.n_initializer = (yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ;
goto fix ;
}

# 3654 "y.tab.c"
break ;
case 24 :
# 836 "gram.y"
{ 
# 837 "gram.y"
Ptype __3t ;
err_name = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
fix :
# 840 "gram.y"
if (err_name == 0 ){ 
# 841 "gram.y"
error__FPCc ( (const char *)"syntax error:TX") ;
yyval . p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc ( err_name , ((struct basetype *)(((struct basetype *)defa_type ))), (struct block *)0 , (unsigned char )0 ) ;
# 842 "gram.y"

# 843 "gram.y"
}
else if ((__3t = err_name -> __O1__4expr.tp )== 0 ){ 
# 844 "gram.y"
const void *__2__X102 ;

# 845 "gram.y"
{ 
# 845 "gram.y"
struct ea __0__V60 ;

# 845 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"TX for%n", (const struct ea *)( (__2__X102 = (const void
# 845 "gram.y"
*)err_name ), ( ((& __0__V60 )-> __O1__2ea.p = __2__X102 ), (& __0__V60 )) ) , (const struct ea *)ea0 , (const
# 845 "gram.y"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
yyval . p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc ( err_name , ((struct basetype *)(((struct basetype *)defa_type ))), (struct block *)0 , (unsigned char )0 ) ;
# 846 "gram.y"
} 
# 847 "gram.y"
}
else if (__3t -> base__4node == 108 ){ 
# 849 "gram.y"
if ((((struct fct *)(((struct fct *)__3t ))))-> returns__3fct == 0 )
# 850 "gram.y"
yyval . p__7YYSTYPE = (struct
# 850 "gram.y"
node *)normalize__4nameFP8basetypeP5blockUc ( err_name , ((struct basetype *)(((struct basetype *)defa_type ))), ((struct block *)0 ), (unsigned char )0 ) ;
else 
# 852 "gram.y"
yyval . p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc ( err_name , ((struct basetype *)0 ), (struct block *)0 , (unsigned char )0 ) ;
# 852 "gram.y"

# 853 "gram.y"
}
else { 
# 854 "gram.y"
unsigned long __2__X103 ;

# 854 "gram.y"
const void *__2__X104 ;

# 855 "gram.y"
{ 
# 855 "gram.y"
struct ea __0__V61 ;

# 855 "gram.y"
struct ea __0__V62 ;

# 855 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"syntax error:TX for%k%n", (const struct ea *)( (__2__X103 = __3t -> base__4node ),
# 855 "gram.y"
( (( ((& __0__V61 )-> __O1__2ea.i = __2__X103 ), 0 ) ), (& __0__V61 )) ) , (const struct
# 855 "gram.y"
ea *)( (__2__X104 = (const void *)err_name ), ( ((& __0__V62 )-> __O1__2ea.p = __2__X104 ), (& __0__V62 )) ) ,
# 855 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
yyval . p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc ( err_name , ((struct basetype *)(((struct basetype *)defa_type ))), (struct block *)0 , (unsigned char )0 ) ;
# 856 "gram.y"
} 
# 857 "gram.y"
}
if (err_name && err_name -> __O2__4name.n_qualifier ){ 
# 859 "gram.y"
if (err_name -> __O2__4name.n_qualifier -> n_template_arg__4name != 1)
# 860 "gram.y"
UNSET_SCOPE__Fv ( ) ;
if (err_name -> __O2__4name.n_qualifier == sta_name )
# 862 "gram.y"
err_name -> __O2__4name.n_qualifier = 0 ;
}
}

# 3687 "y.tab.c"
break ;
case 25 :
# 868 "gram.y"
{ if (yychar == 73 )-- bl_level ;
{ Pname __3n ;

# 869 "gram.y"
__3n = normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-3]). p__7YYSTYPE ))), ((struct block *)(((struct block *)dummy ))), (unsigned
# 869 "gram.y"
char )0 ) ;
argdcl__3fctFP4nameT1 ( ((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))), name_unlist__FP5nlist ( (yystack . l_mark__11YYSTACKDATA [-1]). nl__7YYSTYPE ) , __3n ) ;
arg_redec__FP4name ( (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ) ;
yyval . pn__7YYSTYPE = __3n ;
if (yychar == 73 )++ bl_level ;
Ctbl -> k_name__6ktable = __3n ;

# 874 "gram.y"
}
}

# 3699 "y.tab.c"
break ;
case 26 :
# 877 "gram.y"
{ Pname __3n ;

# 877 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
if (! in_typedef ){ 
# 879 "gram.y"
(((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))))-> body__3fct = (((struct block *)(((struct block *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
(((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))))-> f_init__3fct = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
}
yyval . p__7YYSTYPE = (struct node *)__3n ;
must_be_id = 0 ;
}

# 3711 "y.tab.c"
break ;
case 27 :
# 886 "gram.y"
{ 
# 887 "gram.y"
Pname __3n ;

# 887 "gram.y"
__3n = normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-4]). p__7YYSTYPE ))), ((struct block *)(((struct block *)dummy ))), (unsigned
# 887 "gram.y"
char )0 ) ;
argdcl__3fctFP4nameT1 ( ((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))), name_unlist__FP5nlist ( (yystack . l_mark__11YYSTACKDATA [-2]). nl__7YYSTYPE ) , __3n ) ;
(yystack . l_mark__11YYSTACKDATA [0 ]). q__7YYSTYPE -> retval__7toknode . pn__7YYSTYPE = __3n ;
yyval . p__7YYSTYPE = (struct node *)__3n ;
must_be_id = 0 ;
}

# 3722 "y.tab.c"
break ;
case 28 :
# 894 "gram.y"
{ 
# 895 "gram.y"
if (! in_progress__17templ_compilation )
# 896 "gram.y"
error__FP3locPCcRC2eaN33 ( & (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> where__4name , (const char *)"syntax error -- did you forget a ';'?",
# 896 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
{ Pname __3n ;

# 897 "gram.y"
__3n = normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-4]). p__7YYSTYPE ))), ((struct block *)0 ), (unsigned char
# 897 "gram.y"
)0 ) ;
yyval . p__7YYSTYPE = (struct node *)__3n ;
must_be_id = 0 ;

# 899 "gram.y"
}
}

# 3733 "y.tab.c"
break ;
case 29 :
# 904 "gram.y"
{ if (yychar == 73 )-- bl_level ;
{ Pname __3n ;

# 905 "gram.y"
__3n = normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)defa_type ))), ((struct block *)(((struct block *)dummy ))), (unsigned char )0 )
# 905 "gram.y"
;
argdcl__3fctFP4nameT1 ( ((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))), name_unlist__FP5nlist ( (yystack . l_mark__11YYSTACKDATA [-1]). nl__7YYSTYPE ) , __3n ) ;
arg_redec__FP4name ( (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ) ;
yyval . pn__7YYSTYPE = __3n ;
if (yychar == 73 )++ bl_level ;
Ctbl -> k_name__6ktable = __3n ;

# 910 "gram.y"
}
}

# 3745 "y.tab.c"
break ;
case 30 :
# 913 "gram.y"
{ Pname __3n ;

# 914 "gram.y"
const void *__2__X105 ;

# 913 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
(((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))))-> body__3fct = (((struct block *)(((struct block *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
if ((((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE && (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4name.n_list )&& ccl )&& (ccl -> csu__8classdef == 36 ))
# 917 "gram.y"
{ 
# 917 "gram.y"
struct ea __0__V63 ;
# 917 "gram.y"

# 917 "gram.y"
struct ea __0__V64 ;

# 917 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"multiple initializers in unionK %s::%n", (const struct ea *)( (__2__X105 = (const void
# 917 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [-5]). pn__7YYSTYPE -> __O2__4expr.string ), ( ((& __0__V63 )-> __O1__2ea.p = __2__X105 ), (& __0__V63 )) ) , (const
# 917 "gram.y"
struct ea *)__ct__2eaFPCv ( & __0__V64 , (const void *)(yystack . l_mark__11YYSTACKDATA [-5]). pn__7YYSTYPE ) , (const struct ea *)ea0 , (const
# 917 "gram.y"
struct ea *)ea0 ) ;
} (((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))))-> f_init__3fct = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)__3n ;
must_be_id = 0 ;
}

# 3758 "y.tab.c"
break ;
case 31 :
# 923 "gram.y"
{ 
# 924 "gram.y"
Pname __3n ;

# 924 "gram.y"
__3n = normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)defa_type ))), ((struct block *)(((struct block *)dummy ))), (unsigned char )0 )
# 924 "gram.y"
;
argdcl__3fctFP4nameT1 ( ((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))), name_unlist__FP5nlist ( (yystack . l_mark__11YYSTACKDATA [-2]). nl__7YYSTYPE ) , __3n ) ;
(yystack . l_mark__11YYSTACKDATA [0 ]). q__7YYSTYPE -> retval__7toknode . pn__7YYSTYPE = __3n ;
yyval . p__7YYSTYPE = (struct node *)__3n ;
must_be_id = 0 ;
}

# 3769 "y.tab.c"
break ;
case 32 :
# 931 "gram.y"
{ 
# 931 "gram.y"
const void *__2__X106 ;

# 932 "gram.y"
if (explicit_template_definition == 0 )
# 933 "gram.y"
{ 
# 933 "gram.y"
struct ea __0__V65 ;

# 933 "gram.y"
error__FP3locPCcRC2eaN33 ( & (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> where__4name , (const char *)"badD of%n -- did you forget a ';'?", (const
# 933 "gram.y"
struct ea *)( (__2__X106 = (const void *)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ), ( ((& __0__V65 )-> __O1__2ea.p = __2__X106 ), (&
# 933 "gram.y"
__0__V65 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 935 "gram.y"
Pname __4n ;

# 936 "gram.y"
struct basic_inst *__0__X107 ;

# 935 "gram.y"
__4n = ( (__0__X107 = (struct basic_inst *)pti ), ( __0__X107 -> tname__10basic_inst ) ) ;
if ((yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> n_oper__4name == 162 )
# 937 "gram.y"
{ 
# 937 "gram.y"
struct ea __0__V66 ;

# 937 "gram.y"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"explicitYZL for destructor of specializedYC%n -- please drop the parameter list", (const struct ea *)( ((&
# 937 "gram.y"
__0__V66 )-> __O1__2ea.p = ((const void *)__4n )), (& __0__V66 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 937 "gram.y"
(const struct ea *)ea0 ) ;
} else 
# 939 "gram.y"
{ 
# 939 "gram.y"
struct ea __0__V67 ;

# 939 "gram.y"
struct ea __0__V68 ;

# 939 "gram.y"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"specialializedYC%n: declaration problem: %s", (const struct ea *)( ((&
# 939 "gram.y"
__0__V67 )-> __O1__2ea.p = ((const void *)__4n )), (& __0__V67 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V68 , (const
# 939 "gram.y"
void *)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O2__4expr.string ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} error__FiPCc ( (int )'i' , (const char *)"cannot recover from previous error") ;
}
{ Pname __3n ;

# 942 "gram.y"
__3n = normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)defa_type ))), ((struct block *)0 ), (unsigned char )0 ) ;
# 942 "gram.y"

# 943 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__3n ;
must_be_id = 0 ;

# 944 "gram.y"
}
}

# 3788 "y.tab.c"
break ;
case 33 :
# 949 "gram.y"
{ ( ( ( (Ctbl = __ct__6ktableFiP6ktableP4name ( (struct ktable *)0 , 0 , Ctbl , (struct name *)0 ) ),
# 949 "gram.y"
(Ctbl -> k_id__6ktable = 136 )) ) , (((void )0 ))) ;
arg_redec__FP4name ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
Ctbl -> k_name__6ktable = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 3796 "y.tab.c"
break ;
case 34 :
# 954 "gram.y"
{ 
# 955 "gram.y"
(((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O1__4expr.tp ))))-> f_init__3fct = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
(((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O1__4expr.tp ))))-> body__3fct = (((struct block *)(((struct block *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
yyval . pn__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ;
must_be_id = 0 ;
}

# 3806 "y.tab.c"
break ;
case 35 :
# 964 "gram.y"
{ 
# 967 "gram.y"
if (Ctbl -> k_id__6ktable != 136 )
# 968 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"expectingA table in check_inline!")
# 968 "gram.y"
;
switch ((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar ){ 
# 970 "gram.y"
case 73 :case 69 :
# 971 "gram.y"
if (in_class_decl ){ 
# 974 "gram.y"
la_backup__FUc7YYSTYPE (
# 974 "gram.y"
(unsigned char )yychar , yylval ) ;

# 976 "gram.y"
la_backup__FUc7YYSTYPE ( (unsigned char )127 , yylval ) ;
if (yylval . q__7YYSTYPE = save_text__Fv ( ) ){ 
# 978 "gram.y"
yychar = 124 ;

# 979 "gram.y"
{ 
# 979 "gram.y"
;

# 979 "gram.y"
if (Ctbl == Gtbl )
# 979 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"bad parsing table") ;

# 979 "gram.y"
{ 
# 979 "gram.y"
Pktab __1b ;

# 979 "gram.y"
__1b = Ctbl ;

# 979 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;

# 979 "gram.y"
if ((__1b -> k_id__6ktable == 136 )|| 0 )
# 979 "gram.y"
__dt__6ktableFv ( __1b , 3) ;

# 979 "gram.y"
}

# 135 "gram.y"
}

# 980 "gram.y"
}
else 
# 980 "gram.y"
{ 
# 982 "gram.y"
lalex__Fv ( ) ;
lalex__Fv ( ) ;
yychar = 125 ;
hoist_al__Fv ( ) ;
}
}

# 990 "gram.y"
break ;
default :
# 992 "gram.y"
la_backup__FUc7YYSTYPE ( (unsigned char )yychar , yylval ) ;
yychar = 125 ;
hoist_al__Fv ( ) ;
break ;
}
}

# 3844 "y.tab.c"
break ;
case 36 :
# 1000 "gram.y"
{ ++ in_binit_list ;

# 1000 "gram.y"
}

# 3849 "y.tab.c"
break ;
case 37 :
# 1001 "gram.y"
{ 
# 1002 "gram.y"
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;
in_arg_list = 0 ;
-- in_binit_list ;
}

# 3858 "y.tab.c"
break ;
case 38 :
# 1007 "gram.y"
{ yyval . p__7YYSTYPE = 0 ;

# 1007 "gram.y"
}

# 3863 "y.tab.c"
break ;
case 39 :
# 1011 "gram.y"
{ yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;

# 1011 "gram.y"
}

# 3868 "y.tab.c"
break ;
case 40 :
# 1013 "gram.y"
{ yyval . pn__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;

# 1013 "gram.y"
yyval . pn__7YYSTYPE -> __O1__4name.n_list = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;

# 1013 "gram.y"
}

# 3873 "y.tab.c"
break ;
case 41 :
# 1017 "gram.y"
{ 
# 1018 "gram.y"
yyval . pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
yyval . pn__7YYSTYPE -> __O3__4expr.n_initializer = (yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ;
}

# 3881 "y.tab.c"
break ;
case 42 :
# 1022 "gram.y"
{ 
# 1023 "gram.y"
Pname __3n ;

# 1024 "gram.y"
struct name *__1__X108 ;

# 1024 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 1023 "gram.y"
__3n = ( (__1__X108 = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ), ( ((__1__X108 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X108 ), 0 ) :(
# 1023 "gram.y"
(__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X108 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X108 -> n_template_arg__4name )) ), __1__Xnn00qycjpkkfwcaj ) )
# 1023 "gram.y"
;
__3n -> base__4node = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> base__4node ;
__3n -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O1__4expr.tp ;
__3n -> __O3__4expr.n_initializer = (yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ;
yyval . pn__7YYSTYPE = __3n ;
}

# 3892 "y.tab.c"
break ;
case 43 :
# 1037 "gram.y"
{ 
# 1037 "gram.y"
const void *__2__X109 ;

# 1037 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE == 0 )
# 1038 "gram.y"
error__FPCc ( (const char *)"badAD") ;
else if ((yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp -> base__4node == 108 )
# 1040 "gram.y"
{ 
# 1040 "gram.y"
struct ea __0__V69 ;

# 1040 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"FD inAL (%n)", (const struct ea *)( (__2__X109 = (const void
# 1040 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((& __0__V69 )-> __O1__2ea.p = __2__X109 ), (& __0__V69 )) ) , (const struct
# 1040 "gram.y"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if ((yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE )
# 1042 "gram.y"
add_list__5nlistFP4name ( (yystack . l_mark__11YYSTACKDATA [-1]). nl__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
else 
# 1044 "gram.y"
yyval . nl__7YYSTYPE = __ct__5nlistFP4name ( (struct nlist *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
}

# 3905 "y.tab.c"
break ;
case 44 :
# 1047 "gram.y"
{ 
# 1048 "gram.y"
( ( ( (Ctbl = __ct__6ktableFiP6ktableP4name ( (struct ktable *)0 , 0 , Ctbl , (struct name *)0 ) ),
# 1048 "gram.y"
(Ctbl -> k_id__6ktable = 136 )) ) , (((void )0 ))) ;
yyval . p__7YYSTYPE = 0 ;
}

# 3913 "y.tab.c"
break ;
case 46 :
# 1055 "gram.y"
{ 
# 1056 "gram.y"
if (in_typedef ){ 
# 1057 "gram.y"
error__FPCc ( (const char *)"Tdef field") ;
in_typedef = 0 ;
}

# 1061 "gram.y"
}

# 3924 "y.tab.c"
break ;
case 47 :
# 1063 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )114 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
# 1064 "gram.y"

# 1065 "gram.y"
}

# 3931 "y.tab.c"
break ;
case 48 :
# 1067 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )114 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
# 1068 "gram.y"

# 1069 "gram.y"
if (in_typedef ){ 
# 1070 "gram.y"
error__FPCc ( (const char *)"Tdef field") ;
in_typedef = 0 ;
}
}

# 3942 "y.tab.c"
break ;
case 49 :
# 1075 "gram.y"
{ 
# 1077 "gram.y"
}

# 3949 "y.tab.c"
break ;
case 50 :
# 1079 "gram.y"
{ Pexpr __3e ;

# 1079 "gram.y"
__3e = (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ;
if (__3e == dummy )error__FPCc ( (const char *)"emptyIr") ;
(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O3__4expr.n_initializer = __3e ;
init_seen = 0 ;
}

# 3958 "y.tab.c"
break ;
case 51 :
# 1087 "gram.y"
{ Pname __3n ;

# 1087 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
if (__3n ){ 
# 1089 "gram.y"
yyval . nl__7YYSTYPE = __ct__5nlistFP4name ( (struct nlist *)0 , __3n ) ;
if (__3n -> __O2__4name.n_qualifier ){ 
# 1091 "gram.y"
if (__3n -> __O2__4name.n_qualifier -> n_template_arg__4name != 1)
# 1092 "gram.y"
UNSET_SCOPE__Fv ( ) ;
if (__3n -> __O2__4name.n_qualifier == sta_name )
# 1094 "gram.y"
__3n -> __O2__4name.n_qualifier = 0 ;
}
}
if ((((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar )== 71 )&& (la_look__Fv ( ) == 123 ))
# 1098 "gram.y"
must_be_id =
# 1098 "gram.y"
1 ;
}

# 3975 "y.tab.c"
break ;
case 52 :
# 1101 "gram.y"
{ Pname __3n ;

# 1102 "gram.y"
register struct nlist *__0__X110 ;

# 1101 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
if ((yystack . l_mark__11YYSTACKDATA [-2]). p__7YYSTYPE )
# 1103 "gram.y"
if (__3n )
# 1104 "gram.y"
( (__0__X110 = (yystack . l_mark__11YYSTACKDATA [-2]). nl__7YYSTYPE ), ( ( (__0__X110 -> tail__5nlist -> __O1__4name.n_list =
# 1104 "gram.y"
__3n ), (__0__X110 -> tail__5nlist = __3n )) , (((void )0 ))) ) ;
else 
# 1106 "gram.y"
error__FPCc ( (const char *)"DL syntax") ;
else { 
# 1108 "gram.y"
if (__3n )yyval . nl__7YYSTYPE = __ct__5nlistFP4name ( (struct nlist *)0 , __3n ) ;
error__FPCc ( (const char *)"DL syntax") ;
}
if (__3n ){ 
# 1112 "gram.y"
if (__3n -> __O2__4name.n_qualifier ){ 
# 1113 "gram.y"
if (__3n -> __O2__4name.n_qualifier -> n_template_arg__4name != 1)
# 1114 "gram.y"
UNSET_SCOPE__Fv ( ) ;
if (__3n -> __O2__4name.n_qualifier == sta_name )
# 1116 "gram.y"
__3n -> __O2__4name.n_qualifier = 0 ;
}
}
if ((((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar )== 71 )&& (la_look__Fv ( ) == 123 ))
# 1120 "gram.y"
must_be_id =
# 1120 "gram.y"
1 ;
}

# 4000 "y.tab.c"
break ;
case 53 :
# 1125 "gram.y"
{ 
# 1126 "gram.y"
extern int co_hack ;
co_hack = 1 ;

# 1129 "gram.y"
{ Pname __3n ;

# 1129 "gram.y"
__3n = normalize__4nameFP8basetypeP5blockUc ( name_unlist__FP5nlist ( (yystack . l_mark__11YYSTACKDATA [-1]). nl__7YYSTYPE ) , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-2]). p__7YYSTYPE ))), (struct block *)0 ,
# 1129 "gram.y"
(unsigned char )0 ) ;

# 1132 "gram.y"
in_typedef = 0 ;
in_friend = 0 ;
in_tag = 0 ;
co_hack = 0 ;
DECL_TYPE = 0 ;
yyval . p__7YYSTYPE = (struct node *)__3n ;

# 1137 "gram.y"
}
}

# 4018 "y.tab.c"
break ;
case 54 :
# 1140 "gram.y"
{ 
# 1141 "gram.y"
yyval . p__7YYSTYPE = (struct node *)aggr__8basetypeFv ( (yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE ) ;
in_typedef = 0 ;
in_friend = 0 ;
in_tag = 0 ;
DECL_TYPE = 0 ;
}

# 4029 "y.tab.c"
break ;
case 55 :
# 1152 "gram.y"
{ 
# 1153 "gram.y"
parameters_in_progress__17templ_compilation ++ ;
in_arg_list = 2 ;
check_decl__Fv ( ) ;
}

# 4038 "y.tab.c"
break ;
case 56 :
# 1158 "gram.y"
{ 
# 1159 "gram.y"
parameters_in_progress__17templ_compilation -- ;
if (! parameters_in_progress__17templ_compilation )
# 1161 "gram.y"
in_arg_list = 0 ;
}

# 4047 "y.tab.c"
break ;
case 57 :
# 1164 "gram.y"
{ yyval . pn__7YYSTYPE = check_tname__17templ_compilationFP4name ( templp , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;

# 1164 "gram.y"
}

# 4052 "y.tab.c"
break ;
case 58 :
# 1166 "gram.y"
{ 
# 1167 "gram.y"
int __3sm ;

# 1167 "gram.y"
__3sm = (((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar )== 72 );
if (in_friend )in_friend += __3sm ;
{ bit __3flag ;

# 1169 "gram.y"
__3flag = 0 ;
if (((dtpt_opt && in_typedef )&& (! parameters_in_progress__17templ_compilation ))&& (curloc . file__3loc == first_file ))
# 1173 "gram.y"
__3flag = 1 ;

# 1175 "gram.y"
yyval . pn__7YYSTYPE = parametrized_typename__FP4nameP4exprUc ( (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE , expr_unlist__FP5elist ( (yystack . l_mark__11YYSTACKDATA [-1]). el__7YYSTYPE ) , (unsigned char )in_friend )
# 1175 "gram.y"
;
if (__3flag )
# 1177 "gram.y"
righttname = yyval . pn__7YYSTYPE ;

# 1177 "gram.y"
}
}

# 4069 "y.tab.c"
break ;
case 59 :
# 1180 "gram.y"
{ extern Pbase any_type ;

# 1181 "gram.y"
const void *__2__X111 ;

# 1181 "gram.y"
{ 
# 1181 "gram.y"
struct ea __0__V70 ;

# 1181 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"%n was not aZizedT.", (const struct ea *)( (__2__X111 = (const void
# 1181 "gram.y"
*)yyval . pn__7YYSTYPE ), ( ((& __0__V70 )-> __O1__2ea.p = __2__X111 ), (& __0__V70 )) ) , (const struct ea *)ea0 ,
# 1181 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
yyval . pn__7YYSTYPE = tdef__4nameFv ( (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ) ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (struct type *)any_type ;
} 
# 1183 "gram.y"
}

# 4077 "y.tab.c"
break ;
case 60 :
# 1189 "gram.y"
{ 
# 1190 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE , (struct name *)0 ) ;
# 1190 "gram.y"

# 1191 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE == 35 ){ 
# 1192 "gram.y"
in_typedef = yyval . pt__7YYSTYPE ;

# 1194 "gram.y"
}
else if ((yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE == 18 ){ 
# 1196 "gram.y"
in_friend = 1 ;
must_be_friend = 0 ;
}
if (DECL_TYPE == -1)DECL_TYPE = 0 ;
}

# 4093 "y.tab.c"
break ;
case 61 :
# 1202 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )14 , (struct name *)0 ) ;
# 1202 "gram.y"

# 1203 "gram.y"
yyval . pb__7YYSTYPE -> __O1__8basetype.b_linkage = (yystack . l_mark__11YYSTACKDATA [0 ]). s__7YYSTYPE ;
if (DECL_TYPE == -1)DECL_TYPE = 0 ;
}

# 4101 "y.tab.c"
break ;
case 62 :
# 1207 "gram.y"
{ 
# 1208 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )97 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE )
# 1208 "gram.y"
;
if (DECL_TYPE == -1)DECL_TYPE = 0 ;
}

# 4109 "y.tab.c"
break ;
case 63 :
# 1212 "gram.y"
{ 
# 1213 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )97 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE )
# 1213 "gram.y"
;

# 1215 "gram.y"
if (DECL_TYPE == -1)DECL_TYPE = 0 ;
}

# 4118 "y.tab.c"
break ;
case 66 :
# 1220 "gram.y"
{ 
# 1221 "gram.y"
if (DECL_TYPE == 123 )
# 1222 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )97 , (yystack .
# 1222 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
else 
# 1226 "gram.y"
if ((DECL_TYPE == 0 )&& ((yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE -> base__4node == 123 ))
# 1228 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name ( (struct basetype *)0 ,
# 1228 "gram.y"
(unsigned char )97 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
else 
# 1230 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE , (struct name *)0 ) ;
DECL_TYPE = -1;
}

# 4135 "y.tab.c"
break ;
case 68 :
# 1237 "gram.y"
{ 
# 1238 "gram.y"
if (DECL_TYPE != -1){ 
# 1239 "gram.y"
switch ((yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE -> base__4node ){ 
# 1240 "gram.y"
case 119 :case 121 :
# 1241 "gram.y"
{ Pbase __5bt ;
# 1241 "gram.y"

# 1242 "gram.y"
__5bt = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )0 , (struct name *)0 ) ;
((*__5bt ))= (*(yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE );
if ((yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE && ((yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE -> permanent__4node == 0 ))del__4typeFv ( (struct type *)(yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE ) ;
# 1244 "gram.y"

# 1245 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE = __5bt ;

# 1245 "gram.y"
}
}
yyval . p__7YYSTYPE = (struct node *)type_adj__8basetypeFUc ( (yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ;
}
DECL_TYPE = 0 ;
}

# 4153 "y.tab.c"
break ;
case 69 :
# 1252 "gram.y"
{ 
# 1254 "gram.y"
if (DECL_TYPE != -1)
# 1255 "gram.y"
yyval . p__7YYSTYPE = (struct node *)name_adj__8basetypeFP4name ( (yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE )
# 1255 "gram.y"
;
else if ((yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE == 0 )yyval . p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )97 ,
# 1256 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
DECL_TYPE = 0 ;
}

# 4164 "y.tab.c"
break ;
case 70 :
# 1259 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)base_adj__8basetypeFP8basetype ( (yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pb__7YYSTYPE ) ;

# 1259 "gram.y"
}

# 4169 "y.tab.c"
break ;
case 71 :
# 1260 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)base_adj__8basetypeFP8basetype ( (yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pb__7YYSTYPE ) ;

# 1260 "gram.y"
}

# 4174 "y.tab.c"
break ;
case 72 :
# 1262 "gram.y"
{ 
# 1263 "gram.y"
if (DECL_TYPE == 97 ){ 
# 1264 "gram.y"
switch ((yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE -> base__4node ){ 
# 1265 "gram.y"
case 119 :case 121 :
# 1266 "gram.y"
{ 
# 1267 "gram.y"
Pbase __6bt ;
# 1267 "gram.y"

# 1268 "gram.y"
__6bt = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )0 , (struct name *)0 ) ;
((*__6bt ))= (*(yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE );
if ((yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE && ((yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE -> permanent__4node == 0 ))del__4typeFv ( (struct type *)(yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE ) ;
# 1270 "gram.y"

# 1271 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE = __6bt ;
}
}
yyval . p__7YYSTYPE = (struct node *)type_adj__8basetypeFUc ( (yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ;
}
else if (DECL_TYPE == 178 ){ 
# 1277 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"T decl_marker(tscope)")
# 1277 "gram.y"
;

# 1279 "gram.y"
}
else 
# 1281 "gram.y"
yyval . p__7YYSTYPE = (struct node *)name_adj__8basetypeFP4name ( (yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
DECL_TYPE = -1;
}

# 4200 "y.tab.c"
break ;
case 73 :
# 1286 "gram.y"
{ in_arg_list = 2 ;

# 1286 "gram.y"
check_decl__Fv ( ) ;

# 1286 "gram.y"
}

# 4205 "y.tab.c"
break ;
case 74 :
# 1290 "gram.y"
{ 
# 1290 "gram.y"
register struct elist *__0__X112 ;

# 1290 "gram.y"
struct expr *__2__X113 ;

# 1290 "gram.y"
( (__0__X112 = (yystack . l_mark__11YYSTACKDATA [-2]). el__7YYSTYPE ), ( (__2__X113 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (yystack .
# 1290 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE , (struct expr *)0 ) ), ( ( (__0__X112 -> tail__5elist -> __O3__4expr.e2 = __2__X113 ), (__0__X112 -> tail__5elist = __2__X113 ))
# 1290 "gram.y"
, (((void )0 ))) ) ) ;

# 1290 "gram.y"
}

# 4210 "y.tab.c"
break ;
case 75 :
# 1292 "gram.y"
{ 
# 1292 "gram.y"
struct elist *__0__X114 ;

# 1292 "gram.y"
struct expr *__2__X115 ;

# 1292 "gram.y"
in_arg_list = 0 ;

# 1292 "gram.y"
yyval . el__7YYSTYPE = ( (__0__X114 = 0 ), ( (__2__X115 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (yystack .
# 1292 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE , (struct expr *)0 ) ), ( ((__0__X114 || (__0__X114 = (struct elist *)__nw__FUl ( (size_t )(sizeof (struct elist)))
# 1292 "gram.y"
))?( (__0__X114 -> head__5elist = (__0__X114 -> tail__5elist = __2__X115 )), 0 ) :0 ), __0__X114 ) ) ) ;

# 1292 "gram.y"
}

# 4215 "y.tab.c"
break ;
case 76 :
# 1296 "gram.y"
{ 
# 1297 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
}

# 4222 "y.tab.c"
break ;
case 77 :
# 1300 "gram.y"
{ 
# 1301 "gram.y"
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ;
in_arg_list = 0 ;
hoist_al__Fv ( ) ;
}

# 4231 "y.tab.c"
break ;
case 78 :
# 1306 "gram.y"
{ 
# 1307 "gram.y"
(((struct ptr *)(((struct ptr *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))));
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;
must_be_id = 0 ;
}

# 4241 "y.tab.c"
break ;
case 79 :
# 1313 "gram.y"
{ 
# 1314 "gram.y"
(((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> returns__3fct = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
}

# 4249 "y.tab.c"
break ;
case 80 :
# 1318 "gram.y"
{ 
# 1319 "gram.y"
(((struct vec *)(((struct vec *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
}

# 4257 "y.tab.c"
break ;
case 81 :
# 1324 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))),
# 1324 "gram.y"
(struct block *)0 , (unsigned char )1 ) ;

# 1324 "gram.y"
}

# 4262 "y.tab.c"
break ;
case 82 :
# 1327 "gram.y"
{ 
# 1328 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> n_template_arg__4name = 3;
yyval . pe__7YYSTYPE = (struct expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 4270 "y.tab.c"
break ;
case 83 :
# 1332 "gram.y"
{ 
# 1333 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE == dummy )error__FPCc ( (const char *)"emptyYZL")
# 1333 "gram.y"
;
yyval . pe__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ;
}

# 4278 "y.tab.c"
break ;
case 84 :
# 1340 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)enumcheck__FP4name ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;

# 1340 "gram.y"
}

# 4283 "y.tab.c"
break ;
case 85 :
# 1342 "gram.y"
{ 
# 1343 "gram.y"
if (DECL_TYPE != 123 ){ 
# 1343 "gram.y"
unsigned long __2__X116 ;

# 1344 "gram.y"
{ 
# 1344 "gram.y"
struct ea __0__V71 ;

# 1344 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"syntax error -- enum%k", (const struct ea *)( (__2__X116 = (yystack . l_mark__11YYSTACKDATA [0 ]).
# 1344 "gram.y"
t__7YYSTYPE ), ( (( ((& __0__V71 )-> __O1__2ea.i = __2__X116 ), 0 ) ), (& __0__V71 )) ) , (const
# 1344 "gram.y"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
yyval . p__7YYSTYPE = 0 ;
} }
else yyval . p__7YYSTYPE = (struct node *)enumcheck__FP4name ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
}

# 4294 "y.tab.c"
break ;
case 86 :
# 1350 "gram.y"
{ 
# 1351 "gram.y"
if (DECL_TYPE != 123 ){ 
# 1352 "gram.y"
error__FPCc ( (const char *)"enum declaration syntax") ;
# 1352 "gram.y"

# 1353 "gram.y"
yyval . p__7YYSTYPE = 0 ;
}
else yyval . pn__7YYSTYPE = enumcheck__FP4name ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
if (in_typedef && (in_typedef -> base__4node == 0 ))
# 1357 "gram.y"
in_typedef -> defined__4type = 040 ;

# 1359 "gram.y"
}

# 4308 "y.tab.c"
break ;
case 87 :
# 1362 "gram.y"
{ ++ in_class_decl ;

# 1362 "gram.y"
}

# 4313 "y.tab.c"
break ;
case 88 :
# 1363 "gram.y"
{ -- in_class_decl ;

# 1363 "gram.y"
yyval . p__7YYSTYPE = (struct node *)end_enum__FP4nameP5nlist ( (struct name *)0 , (yystack . l_mark__11YYSTACKDATA [-1]). nl__7YYSTYPE ) ;

# 1363 "gram.y"
}

# 4318 "y.tab.c"
break ;
case 89 :
# 1364 "gram.y"
{ ++ in_class_decl ;

# 1364 "gram.y"
}

# 4323 "y.tab.c"
break ;
case 90 :
# 1365 "gram.y"
{ -- in_class_decl ;

# 1365 "gram.y"
yyval . p__7YYSTYPE = (struct node *)end_enum__FP4nameP5nlist ( (yystack . l_mark__11YYSTACKDATA [-4]). pn__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-1]). nl__7YYSTYPE ) ;

# 1365 "gram.y"
}

# 4328 "y.tab.c"
break ;
case 91 :
# 1366 "gram.y"
{ yyval . pb__7YYSTYPE = (((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ))));

# 1366 "gram.y"
}

# 4333 "y.tab.c"
break ;
case 92 :
# 1370 "gram.y"
{ if ((yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE )yyval . nl__7YYSTYPE = __ct__5nlistFP4name ( (struct nlist *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
# 1370 "gram.y"
}

# 4338 "y.tab.c"
break ;
case 93 :
# 1372 "gram.y"
{ 
# 1372 "gram.y"
register struct nlist *__0__X117 ;

# 1372 "gram.y"
struct name *__2__X118 ;

# 1372 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE )
# 1373 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-2]). p__7YYSTYPE )
# 1374 "gram.y"
( (__0__X117 = (yystack . l_mark__11YYSTACKDATA [-2]). nl__7YYSTYPE ), ( (__2__X118 = (yystack .
# 1374 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ( (__0__X117 -> tail__5nlist -> __O1__4name.n_list = __2__X118 ), (__0__X117 -> tail__5nlist = __2__X118 )) , (((void )0 )))
# 1374 "gram.y"
) ) ;
else 
# 1376 "gram.y"
yyval . nl__7YYSTYPE = __ct__5nlistFP4name ( (struct nlist *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
}

# 4348 "y.tab.c"
break ;
case 96 :
# 1383 "gram.y"
{ 
# 1384 "gram.y"
yyval . pn__7YYSTYPE = 0 ;
error__FPCc ( (const char *)"emptyYZL") ;
}

# 4356 "y.tab.c"
break ;
case 97 :
# 1392 "gram.y"
{ collect__17templ_compilationFUcP4name ( templp , (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;

# 1392 "gram.y"
}

# 4361 "y.tab.c"
break ;
case 98 :
# 1394 "gram.y"
{ collect__17templ_compilationFP4name ( templp , normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))), (struct
# 1394 "gram.y"
block *)0 , (unsigned char )0 ) ) ;

# 1394 "gram.y"
}

# 4366 "y.tab.c"
break ;
case 99 :
# 1401 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;

# 1401 "gram.y"
}

# 4371 "y.tab.c"
break ;
case 100 :
# 1403 "gram.y"
{ (((struct ptr *)(((struct ptr *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))));
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;
}

# 4379 "y.tab.c"
break ;
case 101 :
# 1408 "gram.y"
{ (((struct vec *)(((struct vec *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
}

# 4386 "y.tab.c"
break ;
case 102 :
# 1412 "gram.y"
{ (((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> returns__3fct = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
}

# 4393 "y.tab.c"
break ;
case 103 :
# 1416 "gram.y"
{ 
# 1417 "gram.y"
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ;
in_arg_list = 0 ;
hoist_al__Fv ( ) ;
}

# 4402 "y.tab.c"
break ;
case 104 :
# 1425 "gram.y"
{ 
# 1426 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> n_oper__4name != 123 )
# 1427 "gram.y"
insert_name__FP4nameP6ktable ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , Ctbl ) ;
yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (struct type *)moe_type ;
}

# 4412 "y.tab.c"
break ;
case 105 :
# 1432 "gram.y"
{ 
# 1433 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> n_oper__4name != 123 )
# 1434 "gram.y"
insert_name__FP4nameP6ktable ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , Ctbl ) ;
}

# 4420 "y.tab.c"
break ;
case 106 :
# 1437 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (struct type *)moe_type ;
yyval . pn__7YYSTYPE -> __O3__4expr.n_initializer = (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ;
}

# 4428 "y.tab.c"
break ;
case 107 :
# 1442 "gram.y"
{ yyval . p__7YYSTYPE = 0 ;

# 1442 "gram.y"
}

# 4433 "y.tab.c"
break ;
case 108 :
# 1446 "gram.y"
{ parsing_class_members = 0 ;
RESTORE_STATE__Fv ( ) ;
switch ((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar ){ 
# 1449 "gram.y"
case 97 :case 156 :case 13 :case 0 :
# 1450 "gram.y"
error__FPCc (
# 1450 "gram.y"
(const char *)"`;' or declaratorX afterCD") ;
la_backup__FUc7YYSTYPE ( (unsigned char )yychar , yylval ) ;
yychar = 72 ;
break ;
}
la_backup__FUc7YYSTYPE ( (unsigned char )yychar , yylval ) ;
yychar = -1;
restore_text__Fv ( ) ;
++ bl_level ;
++ in_mem_fct ;
}

# 4452 "y.tab.c"
break ;
case 109 :
# 1462 "gram.y"
{ 
# 1463 "gram.y"
-- in_mem_fct ;
-- bl_level ;
if (yychar == 80 ){ 
# 1467 "gram.y"
-- yylval . pn__7YYSTYPE -> lex_level__4name ;
}
ccl -> mem_list__8classdef = name_unlist__FP5nlist ( (yystack . l_mark__11YYSTACKDATA [-3]). nl__7YYSTYPE ) ;

# 1471 "gram.y"
ccl -> templ_friends__8classdef = templ_friends ;

# 1471 "gram.y"
templ_friends = 0 ;
if (-- in_class_decl )
# 1474 "gram.y"
parsing_class_members = 1 ;

# 1476 "gram.y"

# 1476 "gram.y"
{ 
# 1476 "gram.y"
;

# 1476 "gram.y"
if (Ctbl == Gtbl )
# 1476 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"bad parsing table") ;

# 1476 "gram.y"
{ 
# 1476 "gram.y"
Pktab __1b ;

# 1476 "gram.y"
__1b = Ctbl ;

# 1476 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;

# 1476 "gram.y"
if ((__1b -> k_id__6ktable == 136 )|| 0 )
# 1476 "gram.y"
__dt__6ktableFv ( __1b , 3) ;

# 1476 "gram.y"
}

# 135 "gram.y"
}

# 1477 "gram.y"
if (Ctbl -> k_id__6ktable == 185 ){ 
# 1480 "gram.y"
ccl -> k_tbl__8classdef -> k_next__6ktable = Ctbl -> k_next__6ktable ;
}

# 1483 "gram.y"
if (pti ){ 
# 1484 "gram.y"
explicit_inst__10templ_instFv ( pti ) ;
{ Pname __4nnn ;

# 1486 "gram.y"
struct type *__0__X119 ;

# 1485 "gram.y"
__4nnn = ( (__0__X119 = yyval . pt__7YYSTYPE ), ( (((struct basetype *)(((struct basetype *)__0__X119 ))))-> b_name__8basetype ) ) ;

# 1487 "gram.y"
__4nnn -> __O2__4expr.string = ccl -> string__8classdef ;
explicit_template_definition = 0 ;
pti = 0 ;

# 1489 "gram.y"
}
}

# 1492 "gram.y"
end_cl__Fv ( ) ;
declTag = 1 ;
}

# 4489 "y.tab.c"
break ;
case 110 :
# 1496 "gram.y"
{ 
# 1496 "gram.y"
const void *__2__X124 ;

# 1496 "gram.y"
unsigned long __2__X125 ;

# 1496 "gram.y"
aggrcheck :
# 1497 "gram.y"
yyval . pb__7YYSTYPE = (((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ))));
if (yyval . p__7YYSTYPE == 0 ){ 
# 1498 "gram.y"
const void *__2__X120 ;

# 1498 "gram.y"
const void *__2__X121 ;

# 1499 "gram.y"
if (parameters_in_progress__17templ_compilation )
# 1500 "gram.y"
{ 
# 1500 "gram.y"
struct ea __0__V72 ;

# 1500 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"TX for%n -- did you misdeclare aY?", (const struct ea *)( (__2__X120 = (const void
# 1500 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((& __0__V72 )-> __O1__2ea.p = __2__X120 ), (& __0__V72 )) ) , (const struct
# 1500 "gram.y"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 1501 "gram.y"
struct ea __0__V73 ;

# 1501 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"TX for %n", (const struct ea *)( (__2__X121 = (const void
# 1501 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((& __0__V73 )-> __O1__2ea.p = __2__X121 ), (& __0__V73 )) ) , (const struct
# 1501 "gram.y"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} error__FiPCc ( (int )'i' , (const char *)"cannot recover from previous error") ;
}

# 1505 "gram.y"
if (yyval . p__7YYSTYPE -> base__4node == 97 ){ 
# 1506 "gram.y"
Pname __4nx ;

# 1507 "gram.y"
const void *__2__X122 ;

# 1507 "gram.y"
unsigned long __2__X123 ;

# 1506 "gram.y"
__4nx = yyval . pb__7YYSTYPE -> b_name__8basetype ;
yyval . pb__7YYSTYPE = (((struct basetype *)(((struct basetype *)__4nx -> __O1__4expr.tp ))));
if ((yyval . p__7YYSTYPE -> base__4node != 119 )|| strcmp ( __4nx -> __O2__4expr.string , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4expr.string ) )
# 1511 "gram.y"
{ 
# 1511 "gram.y"
struct
# 1511 "gram.y"
ea __0__V74 ;

# 1511 "gram.y"
struct ea __0__V75 ;

# 1511 "gram.y"
struct ea __0__V76 ;

# 1511 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"%n of type%t redeclared as%k.", (const struct ea *)( (__2__X122 = (const void
# 1511 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((& __0__V74 )-> __O1__2ea.p = __2__X122 ), (& __0__V74 )) ) , (const struct
# 1511 "gram.y"
ea *)__ct__2eaFPCv ( & __0__V75 , (const void *)yyval . pb__7YYSTYPE ) , (const struct ea *)( (__2__X123 = (yystack . l_mark__11YYSTACKDATA [-1]).
# 1511 "gram.y"
t__7YYSTYPE ), ( (( ((& __0__V76 )-> __O1__2ea.i = __2__X123 ), 0 ) ), (& __0__V76 )) ) , (const
# 1511 "gram.y"
struct ea *)ea0 ) ;
} }
else 
# 1512 "gram.y"
if (yyval . p__7YYSTYPE -> base__4node != 119 )
# 1513 "gram.y"
{ 
# 1513 "gram.y"
struct ea __0__V77 ;

# 1513 "gram.y"
struct ea __0__V78 ;

# 1513 "gram.y"
struct ea __0__V79 ;

# 1513 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"%n of type%t redeclared as%k", (const struct ea *)( (__2__X124 = (const void
# 1513 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((& __0__V77 )-> __O1__2ea.p = __2__X124 ), (& __0__V77 )) ) , (const struct
# 1513 "gram.y"
ea *)__ct__2eaFPCv ( & __0__V78 , (const void *)yyval . pb__7YYSTYPE ) , (const struct ea *)( (__2__X125 = (yystack . l_mark__11YYSTACKDATA [-1]).
# 1513 "gram.y"
t__7YYSTYPE ), ( (( ((& __0__V79 )-> __O1__2ea.i = __2__X125 ), 0 ) ), (& __0__V79 )) ) , (const
# 1513 "gram.y"
struct ea *)ea0 ) ;
} check_tag__Fv ( ) ;
}

# 4513 "y.tab.c"
break ;
case 111 :
# 1517 "gram.y"
{ 
# 1522 "gram.y"
dont_instantiate = (((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar )== 72 );
{ Pexpr __3e ;

# 1523 "gram.y"
__3e = 0 ;
if (dont_instantiate && (in_friend == 0 )){ 
# 1526 "gram.y"
Ptempl __4t ;

# 1527 "gram.y"
const void *__2__X129 ;

# 1527 "gram.y"
struct basic_inst *__0__X130 ;

# 1527 "gram.y"
const void *__2__X131 ;

# 1527 "gram.y"
const void *__2__X132 ;

# 1526 "gram.y"
__4t = is_template__17templ_compilationFP4name ( templp , (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ) ;

# 1529 "gram.y"
if (__4t == 0 ){ 
# 1529 "gram.y"
const void *__2__X126 ;

# 1530 "gram.y"
{ 
# 1530 "gram.y"
struct ea __0__V80 ;

# 1530 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"explicitC instance of a nonYC%n", (const struct ea *)( (__2__X126 = (const void
# 1530 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ), ( ((& __0__V80 )-> __O1__2ea.p = __2__X126 ), (& __0__V80 )) ) , (const struct
# 1530 "gram.y"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
error__FiPCc ( (int )'i' , (const char *)"cannot recover from previous error") ;
} }

# 1535 "gram.y"
__3e = expr_unlist__FP5elist ( (yystack . l_mark__11YYSTACKDATA [-1]). el__7YYSTYPE ) ;
check_actual_args__5templFP4expr ( __4t , __3e ) ;

# 1540 "gram.y"
pti = get_match__5templFP4exprP10templ_inst4bool ( __4t , __3e , (struct templ_inst *)0 , 0) ;
if (pti ){ 
# 1541 "gram.y"
register struct templ_inst *__0__X127 ;

# 1541 "gram.y"
const void *__2__X128 ;

# 1542 "gram.y"
if (( (__0__X127 = pti ), ( (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__0__X127 -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp )))))
# 1542 "gram.y"
) -> class_base__8classdef == 4)
# 1543 "gram.y"
{ 
# 1543 "gram.y"
struct ea __0__V81 ;

# 1543 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"ZC%n multiply instantiated", (const struct ea *)( (__2__X128 = (const void
# 1543 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ), ( ((& __0__V81 )-> __O1__2ea.p = __2__X128 ), (& __0__V81 )) ) , (const struct
# 1543 "gram.y"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else pti = __ct__10templ_instFP4exprP5templUc ( (struct templ_inst *)0 , __3e , __4t , (yystack . l_mark__11YYSTACKDATA [-4]). t__7YYSTYPE ) ;
pti -> inst_formals__10basic_inst = ( ((struct basic_template *)__4t )-> formals__14basic_template ) ;

# 1548 "gram.y"
{ 
# 1548 "gram.y"
struct ea __0__V82 ;

# 1548 "gram.y"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"forwardD of a specialized version ofY%n", (const struct ea *)( (__2__X129 =
# 1548 "gram.y"
(const void *)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ), ( ((& __0__V82 )-> __O1__2ea.p = __2__X129 ), (& __0__V82 )) ) ,
# 1548 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
{ 
# 1549 "gram.y"
struct ea __0__V83 ;

# 1549 "gram.y"
error__FiPCcRC2eaN33 ( (int )'C' , (const char *)"\tclass %n", (const struct ea *)( (__2__X131 =
# 1549 "gram.y"
(const void *)( (__0__X130 = (struct basic_inst *)pti ), ( __0__X130 -> tname__10basic_inst ) ) ), ( ((& __0__V83 )->
# 1549 "gram.y"
__O1__2ea.p = __2__X131 ), (& __0__V83 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1549 "gram.y"
ea *)ea0 ) ;
error__FiPCc ( (int )'c' , (const char *)" -- did you mean a general forward declaration of theY?\n") ;
{ 
# 1551 "gram.y"
struct ea __0__V84 ;

# 1551 "gram.y"
error__FiPCcRC2eaN33 ( (int )'C' , (const char *)"\tif so, use:  template <formal-parameters> class %n;\n", (const struct ea *)( (__2__X132 =
# 1551 "gram.y"
(const void *)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ), ( ((& __0__V84 )-> __O1__2ea.p = __2__X132 ), (& __0__V84 )) ) ,
# 1551 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} } } }

# 1554 "gram.y"
if (! __3e )
# 1555 "gram.y"
{ 
# 1556 "gram.y"
__3e = expr_unlist__FP5elist ( (yystack . l_mark__11YYSTACKDATA [-1]). el__7YYSTYPE ) ;
}
{ Pname __3p ;

# 1558 "gram.y"
__3p = parametrized_typename__FP4nameP4exprUc ( (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE , __3e , (unsigned char )in_friend ) ;
dont_instantiate = 0 ;
yyval . pb__7YYSTYPE = (((struct basetype *)(((struct basetype *)__3p -> __O1__4expr.tp ))));
check_tag__Fv ( ) ;

# 1561 "gram.y"
}

# 1561 "gram.y"
}
}

# 4563 "y.tab.c"
break ;
case 112 :
# 1564 "gram.y"
{ 
# 1565 "gram.y"
goto aggrcheck ;
}

# 4570 "y.tab.c"
break ;
case 115 :
# 1574 "gram.y"
{ yyval . pbc__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). pbc__7YYSTYPE ;

# 1574 "gram.y"
}

# 4575 "y.tab.c"
break ;
case 116 :
# 1575 "gram.y"
{ yyval . pbc__7YYSTYPE = 0 ;

# 1575 "gram.y"
}

# 4580 "y.tab.c"
break ;
case 118 :
# 1580 "gram.y"
{ if ((yystack . l_mark__11YYSTACKDATA [0 ]). pbc__7YYSTYPE ){ yyval . pbc__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). pbc__7YYSTYPE ;

# 1580 "gram.y"
yyval . pbc__7YYSTYPE -> next__6basecl = (yystack . l_mark__11YYSTACKDATA [-2]). pbc__7YYSTYPE ;

# 1580 "gram.y"
}

# 1580 "gram.y"
}

# 4585 "y.tab.c"
break ;
case 119 :
# 1583 "gram.y"
{ yyval . pbc__7YYSTYPE = dobase__FUcP4nameT1 ( (unsigned char )0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , (unsigned char )0 )
# 1583 "gram.y"
;

# 1583 "gram.y"
}

# 4590 "y.tab.c"
break ;
case 120 :
# 1584 "gram.y"
{ yyval . pbc__7YYSTYPE = dobase__FUcP4nameT1 ( (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , (unsigned char )0 )
# 1584 "gram.y"
;

# 1584 "gram.y"
}

# 4595 "y.tab.c"
break ;
case 121 :
# 1585 "gram.y"
{ yyval . pbc__7YYSTYPE = dobase__FUcP4nameT1 ( (unsigned char )0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE )
# 1585 "gram.y"
;

# 1585 "gram.y"
}

# 4600 "y.tab.c"
break ;
case 122 :
# 1586 "gram.y"
{ yyval . pbc__7YYSTYPE = dobase__FUcP4nameT1 ( (yystack . l_mark__11YYSTACKDATA [-2]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE )
# 1586 "gram.y"
;

# 1586 "gram.y"
}

# 4605 "y.tab.c"
break ;
case 123 :
# 1587 "gram.y"
{ yyval . pbc__7YYSTYPE = dobase__FUcP4nameT1 ( (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]). t__7YYSTYPE )
# 1587 "gram.y"
;

# 1587 "gram.y"
}

# 4610 "y.tab.c"
break ;
case 124 :
# 1591 "gram.y"
{ 
# 1592 "gram.y"
Pname __3n ;

# 1592 "gram.y"
__3n = start_cl__FUcP4nameP6basecl ( (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE , (struct name *)0 , (struct basecl *)0 ) ;

# 1593 "gram.y"
{ 
# 1593 "gram.y"
;

# 1593 "gram.y"
{ 
# 1593 "gram.y"
Pclass __1cl ;

# 1593 "gram.y"
__1cl = classtype__4typeFv ( __3n -> __O1__4expr.tp ) ;

# 1593 "gram.y"
__1cl -> k_tbl__8classdef -> k_next__6ktable = Ctbl ;

# 1593 "gram.y"
Ctbl = __1cl -> k_tbl__8classdef ;

# 1593 "gram.y"
expand__6ktableFi ( Ctbl , 12 ) ;

# 1593 "gram.y"
}

# 104 "gram.y"
}

# 1594 "gram.y"
ccl -> k_tbl__8classdef = Ctbl ;
yyval . p__7YYSTYPE = (struct node *)(((struct basetype *)(((struct basetype *)__3n -> __O1__4expr.tp ))));
parsing_class_members = 1 ;

# 1598 "gram.y"
in_class_decl ++ ;
SAVE_STATE__Fv ( ) ;
}

# 4624 "y.tab.c"
break ;
case 125 :
# 1603 "gram.y"
{ 
# 1604 "gram.y"
Pname __3n ;

# 1604 "gram.y"
__3n = start_cl__FUcP4nameP6basecl ( (yystack . l_mark__11YYSTACKDATA [-3]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-1]). pbc__7YYSTYPE ) ;

# 1605 "gram.y"
{ 
# 1605 "gram.y"
;

# 1605 "gram.y"
{ 
# 1605 "gram.y"
Pclass __1cl ;

# 1605 "gram.y"
__1cl = classtype__4typeFv ( __3n -> __O1__4expr.tp ) ;

# 1605 "gram.y"
__1cl -> k_tbl__8classdef -> k_next__6ktable = Ctbl ;

# 1605 "gram.y"
Ctbl = __1cl -> k_tbl__8classdef ;

# 1605 "gram.y"
expand__6ktableFi ( Ctbl , 12 ) ;

# 1605 "gram.y"
}

# 104 "gram.y"
}

# 1606 "gram.y"
ccl -> k_tbl__8classdef = Ctbl ;
yyval . p__7YYSTYPE = (struct node *)(((struct basetype *)(((struct basetype *)__3n -> __O1__4expr.tp ))));
parsing_class_members = 1 ;

# 1610 "gram.y"
in_class_decl ++ ;
SAVE_STATE__Fv ( ) ;
}

# 4638 "y.tab.c"
break ;
case 126 :
# 1614 "gram.y"
{ 
# 1614 "gram.y"
const void *__2__X133 ;

# 1616 "gram.y"
if (bl_level > 1 )
# 1617 "gram.y"
{ 
# 1617 "gram.y"
struct ea __0__V85 ;

# 1617 "gram.y"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"specializedY%n not at global scope", (const struct ea *)( (__2__X133 =
# 1617 "gram.y"
(const void *)(yystack . l_mark__11YYSTACKDATA [-5]). pn__7YYSTYPE ), ( ((& __0__V85 )-> __O1__2ea.p = __2__X133 ), (& __0__V85 )) ) ,
# 1617 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} explicit_template_definition = 1 ;
{ Ptempl __3t ;

# 1619 "gram.y"
__3t = is_template__17templ_compilationFP4name ( templp , (yystack . l_mark__11YYSTACKDATA [-5]). pn__7YYSTYPE ) ;

# 1622 "gram.y"
if ((__3t == 0 )|| (! __3t -> defined__5templ )){ 
# 1622 "gram.y"
const void *__2__X134 ;

# 1623 "gram.y"
{ 
# 1623 "gram.y"
struct ea __0__V86 ;

# 1623 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"YC%n must be defined prior to an explicitC instance", (const struct ea *)( (__2__X134 = (const void
# 1623 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [-5]). pn__7YYSTYPE ), ( ((& __0__V86 )-> __O1__2ea.p = __2__X134 ), (& __0__V86 )) ) , (const struct
# 1623 "gram.y"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
error__FiPCc ( (int )'i' , (const char *)"cannot recover from previous error") ;
} }

# 1628 "gram.y"
{ Pexpr __3e ;

# 1628 "gram.y"
__3e = expr_unlist__FP5elist ( (yystack . l_mark__11YYSTACKDATA [-3]). el__7YYSTYPE ) ;
check_actual_args__5templFP4expr ( __3t , __3e ) ;

# 1633 "gram.y"
pti = get_match__5templFP4exprP10templ_inst4bool ( __3t , __3e , (struct templ_inst *)0 , 0) ;
if (pti ){ 
# 1634 "gram.y"
register struct templ_inst *__0__X135 ;

# 1634 "gram.y"
const void *__2__X136 ;

# 1635 "gram.y"
if (( (__0__X135 = pti ), ( (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__0__X135 -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp )))))
# 1635 "gram.y"
) -> class_base__8classdef == 4)
# 1636 "gram.y"
{ 
# 1636 "gram.y"
struct ea __0__V87 ;

# 1636 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"ZC%n multiply instantiated", (const struct ea *)( (__2__X136 = (const void
# 1636 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [-5]). pn__7YYSTYPE ), ( ((& __0__V87 )-> __O1__2ea.p = __2__X136 ), (& __0__V87 )) ) , (const struct
# 1636 "gram.y"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else pti = __ct__10templ_instFP4exprP5templUc ( (struct templ_inst *)0 , __3e , __3t , (yystack . l_mark__11YYSTACKDATA [-6]). t__7YYSTYPE ) ;

# 1640 "gram.y"
{ Pname __3n ;

# 1641 "gram.y"
struct basic_inst *__0__X137 ;

# 1640 "gram.y"
__3n = start_cl__FUcP4nameP6basecl ( (yystack . l_mark__11YYSTACKDATA [-6]). t__7YYSTYPE , ( (__0__X137 = (struct basic_inst *)pti ), ( __0__X137 -> tname__10basic_inst ) ) ,
# 1640 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-1]). pbc__7YYSTYPE ) ;
(((struct basetype *)(((struct basetype *)__3n -> __O1__4expr.tp ))))-> b_name__8basetype -> n_redefined__4name = 1 ;

# 1642 "gram.y"
{ 
# 1642 "gram.y"
;

# 1642 "gram.y"
{ 
# 1642 "gram.y"
Pclass __1cl ;

# 1642 "gram.y"
__1cl = classtype__4typeFv ( __3n -> __O1__4expr.tp ) ;

# 1642 "gram.y"
__1cl -> k_tbl__8classdef -> k_next__6ktable = Ctbl ;

# 1642 "gram.y"
Ctbl = __1cl -> k_tbl__8classdef ;

# 1642 "gram.y"
expand__6ktableFi ( Ctbl , 12 ) ;

# 1642 "gram.y"
}

# 104 "gram.y"
}

# 1643 "gram.y"
ccl -> k_tbl__8classdef = Ctbl ;
yyval . p__7YYSTYPE = (struct node *)(((struct basetype *)(((struct basetype *)__3n -> __O1__4expr.tp ))));
parsing_class_members = 1 ;
in_class_decl ++ ;
SAVE_STATE__Fv ( ) ;

# 1647 "gram.y"
}

# 1647 "gram.y"
}

# 1647 "gram.y"
}
}

# 4677 "y.tab.c"
break ;
case 127 :
# 1651 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;

# 1651 "gram.y"
}

# 4682 "y.tab.c"
break ;
case 128 :
# 1652 "gram.y"
{ yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;

# 1652 "gram.y"
}

# 4687 "y.tab.c"
break ;
case 129 :
# 1655 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;

# 1655 "gram.y"
}

# 4692 "y.tab.c"
break ;
case 130 :
# 1656 "gram.y"
{ yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;

# 1656 "gram.y"
}

# 4697 "y.tab.c"
break ;
case 131 :
# 1660 "gram.y"
{ 
# 1661 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ){ 
# 1662 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE )
# 1663 "gram.y"
add_list__5nlistFP4name ( (yystack . l_mark__11YYSTACKDATA [-1]). nl__7YYSTYPE , (yystack .
# 1663 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
else 
# 1665 "gram.y"
yyval . nl__7YYSTYPE = __ct__5nlistFP4name ( (struct nlist *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
}
in_friend = 0 ;
}

# 4710 "y.tab.c"
break ;
case 132 :
# 1669 "gram.y"
{ yyval . p__7YYSTYPE = 0 ;

# 1669 "gram.y"
}

# 4715 "y.tab.c"
break ;
case 133 :
# 1671 "gram.y"
{ 
# 1671 "gram.y"
struct cons *__0__X138 ;

# 1671 "gram.y"
struct cons *__2__X139 ;

# 1673 "gram.y"
if (must_be_friend ){ 
# 1674 "gram.y"
error__FPCc ( (const char *)"non-friend ZizedTD must be atG, notC scope") ;
error__FiPCc ( (int )'i' , (const char *)"cannot recover from previous error") ;
}
templ_friends = ( (__0__X138 = 0 ), ( (__2__X139 = templ_friends ), ( ((__0__X138 || (__0__X138 = (struct cons *)__nw__FUl ( (unsigned long
# 1677 "gram.y"
)(sizeof (struct cons))) ))?( (__0__X138 -> car__4cons = ((void *)parsed_template__17templ_compilation )), (__0__X138 -> cdr__4cons = __2__X139 )) :0 ), __0__X138 ) ) )
# 1677 "gram.y"
;
parsed_template__17templ_compilation = 0 ;
}

# 4728 "y.tab.c"
break ;
case 135 :
# 1684 "gram.y"
{ 
# 1685 "gram.y"
fct_friend1 :
# 1686 "gram.y"
if (((in_friend && (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE )&& (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O2__4name.n_qualifier )&& ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ->
# 1686 "gram.y"
__O2__4name.n_qualifier -> n_template_arg__4name != 1))
# 1690 "gram.y"
UNSET_SCOPE__Fv ( ) ;
}

# 4740 "y.tab.c"
break ;
case 136 :
# 1693 "gram.y"
{ 
# 1694 "gram.y"
goto fct_friend1 ;
}

# 4747 "y.tab.c"
break ;
case 137 :
# 1697 "gram.y"
{ 
# 1698 "gram.y"
fct_friend2 :
# 1699 "gram.y"
if (((in_friend && (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE )&& (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4name.n_qualifier )&& ((yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ->
# 1699 "gram.y"
__O2__4name.n_qualifier -> n_template_arg__4name != 1))
# 1703 "gram.y"
UNSET_SCOPE__Fv ( ) ;
}

# 4759 "y.tab.c"
break ;
case 138 :
# 1706 "gram.y"
{ 
# 1707 "gram.y"
goto fct_friend2 ;
}

# 4766 "y.tab.c"
break ;
case 140 :
# 1711 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
yyval . pn__7YYSTYPE -> base__4node = (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE ;
}

# 4773 "y.tab.c"
break ;
case 141 :
# 1715 "gram.y"
{ Pname __3n ;

# 1716 "gram.y"
struct name *__1__X140 ;

# 1716 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 1715 "gram.y"
__3n = ( (__1__X140 = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ), ( ((__1__X140 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X140 ), 0 ) :(
# 1715 "gram.y"
(__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X140 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X140 -> n_template_arg__4name )) ), __1__Xnn00qycjpkkfwcaj ) )
# 1715 "gram.y"
;
if (__3n -> n_oper__4name == 97 ){ 
# 1717 "gram.y"
error__FiPCc ( (int )'s' , (const char *)"visibilityD for conversion operator")
# 1717 "gram.y"
;

# 1719 "gram.y"
__3n -> __O1__4expr.tp = (((struct type *)(((struct type *)__3n -> __O4__4expr.cond ))));
__3n -> __O4__4expr.cond = 0 ;

# 1722 "gram.y"
__3n -> n_oper__4name = 0 ;
sig_name__FP4name ( __3n ) ;
}
__3n -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
__3n -> base__4node = 175 ;
yyval . p__7YYSTYPE = (struct node *)__3n ;
if ((yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE && ((yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE -> n_template_arg__4name != 1))
# 1729 "gram.y"
UNSET_SCOPE__Fv ( ) ;
}

# 4793 "y.tab.c"
break ;
case 142 :
# 1745 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;

# 1745 "gram.y"
}

# 4798 "y.tab.c"
break ;
case 143 :
# 1747 "gram.y"
{ 
# 1747 "gram.y"
struct name *__1__X141 ;

# 1747 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 1747 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__1__X141 = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__1__X141 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X141 ),
# 1747 "gram.y"
0 ) :( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X141 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X141 -> n_template_arg__4name )) ),
# 1747 "gram.y"
__1__Xnn00qycjpkkfwcaj ) ) ;
yyval . pn__7YYSTYPE -> n_oper__4name = 162 ;
}

# 4805 "y.tab.c"
break ;
case 144 :
# 1751 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4nameFPCc ( (struct name *)0 , oper_name__FUc ( (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ) ;
# 1751 "gram.y"

# 1752 "gram.y"
yyval . pn__7YYSTYPE -> n_oper__4name = (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ;
}

# 4812 "y.tab.c"
break ;
case 145 :
# 1755 "gram.y"
{ Pname __3n ;

# 1755 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
__3n -> __O2__4expr.string = (const char *)"_type";
__3n -> n_oper__4name = 97 ;
__3n -> __O4__4expr.cond = (((struct expr *)(((struct expr *)__3n -> __O1__4expr.tp ))));

# 1760 "gram.y"
__3n -> __O1__4expr.tp = 0 ;
yyval . p__7YYSTYPE = (struct node *)__3n ;
}

# 4824 "y.tab.c"
break ;
case 160 :
# 1779 "gram.y"
{ yyval . t__7YYSTYPE = 109 ;

# 1779 "gram.y"
}

# 4829 "y.tab.c"
break ;
case 161 :
# 1780 "gram.y"
{ yyval . t__7YYSTYPE = 111 ;

# 1780 "gram.y"
}

# 4834 "y.tab.c"
break ;
case 167 :
# 1786 "gram.y"
{ yyval . t__7YYSTYPE = 23 ;

# 1786 "gram.y"
-- in_new ;

# 1786 "gram.y"
}

# 4839 "y.tab.c"
break ;
case 168 :
# 1787 "gram.y"
{ yyval . t__7YYSTYPE = 213 ;

# 1787 "gram.y"
-- in_new ;

# 1787 "gram.y"
}

# 4844 "y.tab.c"
break ;
case 169 :
# 1788 "gram.y"
{ yyval . t__7YYSTYPE = 9 ;

# 1788 "gram.y"
}

# 4849 "y.tab.c"
break ;
case 170 :
# 1789 "gram.y"
{ yyval . t__7YYSTYPE = 212 ;

# 1789 "gram.y"
}

# 4854 "y.tab.c"
break ;
case 171 :
# 1790 "gram.y"
{ yyval . t__7YYSTYPE = 44 ;

# 1790 "gram.y"
}

# 4859 "y.tab.c"
break ;
case 172 :
# 1791 "gram.y"
{ yyval . t__7YYSTYPE = 71 ;

# 1791 "gram.y"
}

# 4864 "y.tab.c"
break ;
case 173 :
# 1792 "gram.y"
{ yyval . t__7YYSTYPE = 180 ;
if ((yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE == 45 )error__FPCc ( (const char *)".* cannot be overloaded") ;
}

# 4871 "y.tab.c"
break ;
case 174 :
# 1797 "gram.y"
{ yyval . pn__7YYSTYPE = SET_SCOPE__FP4name ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;

# 1797 "gram.y"
}

# 4876 "y.tab.c"
break ;
case 175 :
# 1801 "gram.y"
{ if ((yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE != sta_name ){ 
# 1802 "gram.y"
Pname __4n ;
const char *__4str ;

# 1803 "gram.y"
const char *__4str2 ;

# 1803 "gram.y"
const char *__4s ;

# 1802 "gram.y"
__4n = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
__4str = 0 ;

# 1803 "gram.y"
__4str2 = 0 ;

# 1803 "gram.y"
__4s = __4n -> __O2__4expr.string ;
if (__4n -> n_template_arg__4name != 1){ 
# 1805 "gram.y"
__4n = is_cl_obj__4typeFv ( __4n -> __O1__4expr.tp ) ;
if (__4n )__4str = (__4s = (const char *)get_classname__FPCc ( __4n -> __O2__4expr.string ) );
}
if ((__4n && (((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar )== 123 ))&& (strcmp ( __4s , __4str2 =
# 1808 "gram.y"
(const char *)get_classname__FPCc ( yylval . pn__7YYSTYPE -> __O2__4expr.string ) ) == 0 ))
# 1809 "gram.y"
{ 
# 1809 "gram.y"
struct name *__1__X142 ;

# 1809 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 1812 "gram.y"
yychar = 80 ;
yylval . pn__7YYSTYPE = ( (__1__X142 = yylval . pn__7YYSTYPE ), ( ((__1__X142 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X142 ), 0 ) :(
# 1813 "gram.y"
(__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X142 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X142 -> n_template_arg__4name )) ), __1__Xnn00qycjpkkfwcaj ) )
# 1813 "gram.y"
;
yylval . pn__7YYSTYPE -> n_oper__4name = 123 ;
}
if (__4str )__dl__FPv ( (void *)(((char *)__4str ))) ;
if (__4str2 )__dl__FPv ( (void *)(((char *)__4str2 ))) ;
}
yyval . pn__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 4900 "y.tab.c"
break ;
case 176 :
# 1822 "gram.y"
{ 
# 1823 "gram.y"
yyval . pn__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
if ((yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE == sta_name ){ 
# 1825 "gram.y"
error__FPCc ( (const char *)"scope qualifier syntax") ;
# 1825 "gram.y"

# 1826 "gram.y"
}
else 
# 1826 "gram.y"
{ 
# 1828 "gram.y"
Pname __4cn ;
const char *__4str ;

# 1829 "gram.y"
const char *__4str2 ;

# 1829 "gram.y"
const char *__4s ;

# 1828 "gram.y"
__4cn = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
__4str = 0 ;

# 1829 "gram.y"
__4str2 = 0 ;

# 1829 "gram.y"
__4s = __4cn -> __O2__4expr.string ;
if (__4cn -> n_template_arg__4name != 1){ 
# 1831 "gram.y"
__4cn = is_cl_obj__4typeFv ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ) ;
if (__4cn )__4str = (__4s = (const char *)get_classname__FPCc ( __4cn -> __O2__4expr.string ) );
}
if ((__4cn && (((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar )== 123 ))&& (strcmp ( __4s , __4str2 =
# 1834 "gram.y"
(const char *)get_classname__FPCc ( yylval . pn__7YYSTYPE -> __O2__4expr.string ) ) == 0 ))
# 1835 "gram.y"
{ 
# 1835 "gram.y"
struct name *__1__X143 ;

# 1835 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 1838 "gram.y"
yychar = 80 ;
yylval . pn__7YYSTYPE = ( (__1__X143 = yylval . pn__7YYSTYPE ), ( ((__1__X143 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X143 ), 0 ) :(
# 1839 "gram.y"
(__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X143 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X143 -> n_template_arg__4name )) ), __1__Xnn00qycjpkkfwcaj ) )
# 1839 "gram.y"
;
yylval . pn__7YYSTYPE -> n_oper__4name = 123 ;
}
if (__4str )__dl__FPv ( (void *)(((char *)__4str ))) ;
if (__4str2 )__dl__FPv ( (void *)(((char *)__4str2 ))) ;
if (((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE != sta_name )&& ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> n_template_arg__4name != 1))
# 1845 "gram.y"
{ 
# 1846 "gram.y"
Pname __5cx ;

# 1846 "gram.y"
__5cx = is_cl_obj__4typeFv ( (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ) ;
if (__5cx )
# 1848 "gram.y"
if (check_if_base__FP8classdefT1 ( ((struct classdef *)(((struct classdef *)__5cx -> __O1__4expr.tp ))), ((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp )))) )
# 1849 "gram.y"
{ 
# 1849 "gram.y"
struct ea __0__V88 ;
# 1849 "gram.y"

# 1849 "gram.y"
struct ea __0__V89 ;

# 1849 "gram.y"
struct ea __0__V90 ;

# 1849 "gram.y"
struct ea __0__V91 ;

# 1849 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"%n ::%n :: --%n not aM of%n", (const struct ea *)( ((& __0__V88 )-> __O1__2ea.p =
# 1849 "gram.y"
((const void *)__5cx )), (& __0__V88 )) , (const struct ea *)( ((& __0__V89 )-> __O1__2ea.p = ((const void
# 1849 "gram.y"
*)__4cn )), (& __0__V89 )) , (const struct ea *)( ((& __0__V90 )-> __O1__2ea.p = ((const void *)__4cn )), (&
# 1849 "gram.y"
__0__V90 )) , (const struct ea *)( ((& __0__V91 )-> __O1__2ea.p = ((const void *)__5cx )), (& __0__V91 )) )
# 1849 "gram.y"
;
} }
}
}

# 4935 "y.tab.c"
break ;
case 177 :
# 1856 "gram.y"
{ 
# 1857 "gram.y"
yyval . pn__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
if (in_typedef && (in_typedef -> base__4node == 0 ))
# 1859 "gram.y"
in_typedef -> defined__4type = 040 ;

# 1864 "gram.y"
}

# 4948 "y.tab.c"
break ;
case 178 :
# 1866 "gram.y"
{ 
# 1867 "gram.y"
yyval . pn__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
if (in_typedef && (in_typedef -> base__4node == 0 ))
# 1869 "gram.y"
in_typedef -> defined__4type = 040 ;

# 1872 "gram.y"
}

# 4959 "y.tab.c"
break ;
case 179 :
# 1876 "gram.y"
{ yyval . i__7YYSTYPE = 0 ;

# 1876 "gram.y"
}

# 4964 "y.tab.c"
break ;
case 180 :
# 1878 "gram.y"
{ 
# 1879 "gram.y"
switch ((yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ){ 
# 1879 "gram.y"
unsigned long __2__X145 ;

# 1880 "gram.y"
case 170 :
# 1881 "gram.y"
error__FiPCc ( (int )'s' , (const char *)"volatile functions") ;
break ;
case 26 :
# 1884 "gram.y"
yyval . i__7YYSTYPE = ((yystack . l_mark__11YYSTACKDATA [-1]). i__7YYSTYPE | 1 );
break ;
default :
# 1887 "gram.y"
if (((((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar )!= 72 )&& (yychar != 69 ))&& (yychar !=
# 1887 "gram.y"
73 ))
# 1889 "gram.y"
{ 
# 1889 "gram.y"
unsigned long __2__X144 ;

# 1890 "gram.y"
la_backup__FUc7YYSTYPE ( (unsigned char )yychar , yylval ) ;
yylval . t__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ;
la_backup__FUc7YYSTYPE ( (unsigned char )97 , yylval ) ;
yylval . t__7YYSTYPE = 72 ;
yychar = 72 ;
{ 
# 1895 "gram.y"
struct ea __0__V92 ;

# 1895 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"syntax error: unexpected%k (did you forget a `;'?)", (const struct ea *)( (__2__X144 = (yystack . l_mark__11YYSTACKDATA [0 ]).
# 1895 "gram.y"
t__7YYSTYPE ), ( (( ((& __0__V92 )-> __O1__2ea.i = __2__X144 ), 0 ) ), (& __0__V92 )) ) , (const
# 1895 "gram.y"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else 
# 1896 "gram.y"
{ 
# 1896 "gram.y"
struct ea __0__V93 ;

# 1896 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"FD syntax: unexpected%k", (const struct ea *)( (__2__X145 = (yystack . l_mark__11YYSTACKDATA [0 ]).
# 1896 "gram.y"
t__7YYSTYPE ), ( (( ((& __0__V93 )-> __O1__2ea.i = __2__X145 ), 0 ) ), (& __0__V93 )) ) , (const
# 1896 "gram.y"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} break ;
}
}

# 4990 "y.tab.c"
break ;
case 181 :
# 1901 "gram.y"
{ yyval . i__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-4]). i__7YYSTYPE ;

# 1901 "gram.y"
}

# 4995 "y.tab.c"
break ;
case 182 :
# 1904 "gram.y"
{ yyval . pl__7YYSTYPE = 0 ;

# 1904 "gram.y"
}

# 5000 "y.tab.c"
break ;
case 183 :
# 1906 "gram.y"
{ yyval . pl__7YYSTYPE = 0 ;

# 1906 "gram.y"
}

# 5005 "y.tab.c"
break ;
case 184 :
# 1910 "gram.y"
{ (((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> returns__3fct = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [0 ]). pt__7YYSTYPE ;
}

# 5012 "y.tab.c"
break ;
case 185 :
# 1914 "gram.y"
{ 
# 1915 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O1__4expr.tp ,
# 1915 "gram.y"
(struct name *)0 , (unsigned char )1 ) ;
(((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O1__4expr.tp ))))-> f_const__3fct = ((yystack . l_mark__11YYSTACKDATA [0 ]). i__7YYSTYPE & 1 );
}

# 5020 "y.tab.c"
break ;
case 186 :
# 1919 "gram.y"
{ Pname __3n ;

# 1920 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 1919 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( ((__3n -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __3n ), 0 ) :( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct
# 1920 "gram.y"
name *)0 , __3n -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __3n -> n_template_arg__4name )) ), __1__Xnn00qycjpkkfwcaj ) ;

# 1923 "gram.y"
if ((! in_typedef )&& ((ccl == 0 )|| strcmp ( __3n -> __O2__4expr.string , ccl -> string__8classdef ) ))
# 1925 "gram.y"
hide__4nameFv ( __3n ) ;
yyval . pn__7YYSTYPE -> n_oper__4name = 123 ;
(((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> returns__3fct = yyval . pn__7YYSTYPE -> __O1__4expr.tp ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [0 ]). pt__7YYSTYPE ;
}

# 5035 "y.tab.c"
break ;
case 187 :
# 1935 "gram.y"
{ 
# 1936 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O1__4expr.tp ,
# 1936 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE , (unsigned char )1 ) ;
in_arg_list = 0 ;

# 1939 "gram.y"

# 1939 "gram.y"
{ 
# 1939 "gram.y"
;

# 1939 "gram.y"
if (Ctbl == Gtbl )
# 1939 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"bad parsing table") ;

# 1939 "gram.y"
{ 
# 1939 "gram.y"
Pktab __1b ;

# 1939 "gram.y"
__1b = Ctbl ;

# 1939 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;

# 1939 "gram.y"
if ((__1b -> k_id__6ktable == 136 )|| 0 )
# 1939 "gram.y"
__dt__6ktableFv ( __1b , 3) ;

# 1939 "gram.y"
}

# 135 "gram.y"
}

# 1941 "gram.y"
}

# 5046 "y.tab.c"
break ;
case 188 :
# 1943 "gram.y"
{ 
# 1944 "gram.y"
Pptr __3p ;

# 1944 "gram.y"
__3p = __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (struct type *)0 ) ;
(((struct ptr *)(((struct ptr *)__3p ))))-> typ__5pvtyp = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )97 , (yystack . l_mark__11YYSTACKDATA [-5]). pn__7YYSTYPE )
# 1945 "gram.y"
;
(((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> returns__3fct = (((struct type *)(((struct type *)__3p ))));
(yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [0 ]). pt__7YYSTYPE ;

# 1949 "gram.y"
if (((yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE -> n_oper__4name != 123 )&& (! in_typedef )){ 
# 1950 "gram.y"
insert_name__FP4nameP6ktable ( (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE , Ctbl ) ;
# 1950 "gram.y"

# 1951 "gram.y"
}
yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
if (DECL_TYPE == -1)DECL_TYPE = 0 ;
}

# 5062 "y.tab.c"
break ;
case 189 :
# 1956 "gram.y"
{ 
# 1957 "gram.y"
Pptr __3p ;

# 1957 "gram.y"
__3p = __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )158 , (struct type *)0 ) ;
(((struct ptr *)(((struct ptr *)__3p ))))-> typ__5pvtyp = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )97 , (yystack . l_mark__11YYSTACKDATA [-5]). pn__7YYSTYPE )
# 1958 "gram.y"
;
(((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> returns__3fct = (((struct type *)(((struct type *)__3p ))));
(yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [0 ]). pt__7YYSTYPE ;

# 1962 "gram.y"
if (((yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE -> n_oper__4name != 123 )&& (! in_typedef )){ 
# 1963 "gram.y"
insert_name__FP4nameP6ktable ( (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE , Ctbl ) ;
# 1963 "gram.y"

# 1964 "gram.y"
}
yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
if (DECL_TYPE == -1)DECL_TYPE = 0 ;
}

# 5078 "y.tab.c"
break ;
case 190 :
# 1969 "gram.y"
{ Pname __3n ;

# 1970 "gram.y"
struct name *__1__X146 ;

# 1970 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 1969 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__1__X146 = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ), ( ((__1__X146 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X146 ),
# 1970 "gram.y"
0 ) :( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X146 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X146 -> n_template_arg__4name )) ),
# 1970 "gram.y"
__1__Xnn00qycjpkkfwcaj ) ) ;

# 1974 "gram.y"
if ((! in_typedef )&& ((ccl == 0 )|| strcmp ( __3n -> __O2__4expr.string , ccl -> string__8classdef ) ))
# 1976 "gram.y"
hide__4nameFv ( __3n ) ;
yyval . pn__7YYSTYPE -> n_oper__4name = 123 ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)0 , (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE , (unsigned char
# 1978 "gram.y"
)1 ) ;
}

# 5093 "y.tab.c"
break ;
case 191 :
# 1981 "gram.y"
{ 
# 1982 "gram.y"
Pname __3n ;

# 1983 "gram.y"
struct name *__1__X147 ;

# 1983 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 1982 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__1__X147 = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ), ( ((__1__X147 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X147 ),
# 1983 "gram.y"
0 ) :( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X147 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X147 -> n_template_arg__4name )) ),
# 1983 "gram.y"
__1__Xnn00qycjpkkfwcaj ) ) ;

# 1985 "gram.y"
if ((! in_typedef )&& ((ccl == 0 )|| strcmp ( __3n -> __O2__4expr.string , ccl -> string__8classdef ) ))
# 1987 "gram.y"
hide__4nameFv ( __3n ) ;
yyval . pn__7YYSTYPE -> n_oper__4name = 123 ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)0 , (struct name *)0 , (unsigned char )1 )
# 1989 "gram.y"
;
(((struct fct *)(((struct fct *)yyval . pn__7YYSTYPE -> __O1__4expr.tp ))))-> f_const__3fct = ((yystack . l_mark__11YYSTACKDATA [0 ]). i__7YYSTYPE & 1 );
}

# 5108 "y.tab.c"
break ;
case 192 :
# 1993 "gram.y"
{ memptrdcl__FP4nameT1P4typeT1 ( (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-5]). pn__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pt__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]).
# 1993 "gram.y"
pn__7YYSTYPE ) ;
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-2]). p__7YYSTYPE ;
}

# 5115 "y.tab.c"
break ;
case 193 :
# 1997 "gram.y"
{ 
# 2007 "gram.y"
if ((((yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> n_oper__4name == 0 )&& (! in_typedef ))&& (! in_friend ))
# 2008 "gram.y"
{ 
# 2010 "gram.y"
if (((ccl ==
# 2010 "gram.y"
0 )|| (parsing_class_members == 0 ))|| strcmp ( ccl -> string__8classdef , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4expr.string ) )
# 2011 "gram.y"
{ 
# 2012 "gram.y"
Pname __5n ;

# 2012 "gram.y"
__5n = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;

# 2012 "gram.y"
((*__5n ))= (*(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE );
insert_name__FP4nameP6ktable ( __5n , Ctbl ) ;
}
}
}

# 5139 "y.tab.c"
break ;
case 194 :
# 2018 "gram.y"
{ 
# 2018 "gram.y"
struct name *__1__X148 ;

# 2018 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 2018 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__1__X148 = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__1__X148 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X148 ),
# 2018 "gram.y"
0 ) :( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X148 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X148 -> n_template_arg__4name )) ),
# 2018 "gram.y"
__1__Xnn00qycjpkkfwcaj ) ) ;

# 2020 "gram.y"
error__FPCc ( (const char *)"`.' used for qualification; please use `::'") ;
}

# 5147 "y.tab.c"
break ;
case 195 :
# 2023 "gram.y"
{ 
# 2023 "gram.y"
const void *__2__X149 ;

# 2023 "gram.y"
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;

# 2026 "gram.y"
if (((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE == sta_name )&& (yyval . pn__7YYSTYPE -> n_oper__4name == 162 ))
# 2028 "gram.y"
{ 
# 2028 "gram.y"
struct ea __0__V94 ;

# 2028 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"bad syntax for destructor ::%n", (const struct ea *)( (__2__X149 = (const void
# 2028 "gram.y"
*)yyval . pn__7YYSTYPE ), ( ((& __0__V94 )-> __O1__2ea.p = __2__X149 ), (& __0__V94 )) ) , (const struct ea *)ea0 ,
# 2028 "gram.y"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} yyval . pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;

# 2031 "gram.y"
}

# 5160 "y.tab.c"
break ;
case 196 :
# 2033 "gram.y"
{ 
# 2033 "gram.y"
struct name *__1__X150 ;

# 2033 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 2033 "gram.y"
const void *__2__X151 ;

# 2033 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__1__X150 = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__1__X150 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X150 ),
# 2033 "gram.y"
0 ) :( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X150 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X150 -> n_template_arg__4name )) ),
# 2033 "gram.y"
__1__Xnn00qycjpkkfwcaj ) ) ;

# 2035 "gram.y"
error__FPCc ( (const char *)"`.' used for qualification; please use `::'") ;
{ 
# 2036 "gram.y"
struct ea __0__V95 ;

# 2036 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"non-type qualifier%n", (const struct ea *)( (__2__X151 = (const void
# 2036 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ), ( ((& __0__V95 )-> __O1__2ea.p = __2__X151 ), (& __0__V95 )) ) , (const struct
# 2036 "gram.y"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 2041 "gram.y"
}

# 5173 "y.tab.c"
break ;
case 197 :
# 2043 "gram.y"
{ (((struct ptr *)(((struct ptr *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [-1]). pt__7YYSTYPE ;
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;
}

# 5181 "y.tab.c"
break ;
case 198 :
# 2048 "gram.y"
{ 
# 2048 "gram.y"
struct name *__1__X152 ;

# 2048 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 2048 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__1__X152 = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__1__X152 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X152 ),
# 2048 "gram.y"
0 ) :( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X152 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X152 -> n_template_arg__4name )) ),
# 2048 "gram.y"
__1__Xnn00qycjpkkfwcaj ) ) ;

# 2050 "gram.y"
yyval . pn__7YYSTYPE -> n_oper__4name = 123 ;

# 2052 "gram.y"
if (! in_typedef )hide__4nameFv ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
else in_tag = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [-1]). pt__7YYSTYPE ;
}

# 5193 "y.tab.c"
break ;
case 199 :
# 2057 "gram.y"
{ 
# 2057 "gram.y"
struct name *__1__X153 ;

# 2057 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 2057 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__1__X153 = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ), ( ((__1__X153 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X153 ),
# 2057 "gram.y"
0 ) :( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X153 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X153 -> n_template_arg__4name )) ),
# 2057 "gram.y"
__1__Xnn00qycjpkkfwcaj ) ) ;

# 2059 "gram.y"
yyval . pn__7YYSTYPE -> n_oper__4name = 123 ;
if (! in_typedef )hide__4nameFv ( (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ) ;
else in_tag = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [0 ]). pt__7YYSTYPE ;
}

# 5204 "y.tab.c"
break ;
case 200 :
# 2065 "gram.y"
{ (((struct vec *)(((struct vec *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [0 ]). pt__7YYSTYPE ;
}

# 5211 "y.tab.c"
break ;
case 201 :
# 2082 "gram.y"
{ 
# 2083 "gram.y"
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ;
in_arg_list = 0 ;
hoist_al__Fv ( ) ;

# 2087 "gram.y"
}

# 5221 "y.tab.c"
break ;
case 202 :
# 2091 "gram.y"
{ 
# 2092 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> n_oper__4name != 123 ){ 
# 2093 "gram.y"
Pname __4n ;

# 2093 "gram.y"
__4n = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;

# 2093 "gram.y"
((*__4n ))= (*(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE );
insert_name__FP4nameP6ktable ( __4n , Ctbl ) ;
}
yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 5232 "y.tab.c"
break ;
case 203 :
# 2099 "gram.y"
{ 
# 2099 "gram.y"
struct name *__1__X154 ;

# 2099 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 2099 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__1__X154 = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__1__X154 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X154 ),
# 2099 "gram.y"
0 ) :( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X154 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X154 -> n_template_arg__4name )) ),
# 2099 "gram.y"
__1__Xnn00qycjpkkfwcaj ) ) ;
yyval . pn__7YYSTYPE -> n_oper__4name = 123 ;
hide__4nameFv ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
yyval . pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [-1]). pt__7YYSTYPE ;
}

# 5241 "y.tab.c"
break ;
case 204 :
# 2105 "gram.y"
{ 
# 2106 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
must_be_id = 0 ;
}

# 5249 "y.tab.c"
break ;
case 205 :
# 2110 "gram.y"
{ (((struct ptr *)(((struct ptr *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))));
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;
}

# 5257 "y.tab.c"
break ;
case 206 :
# 2115 "gram.y"
{ (((struct vec *)(((struct vec *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
}

# 5264 "y.tab.c"
break ;
case 207 :
# 2119 "gram.y"
{ (((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> returns__3fct = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
}

# 5271 "y.tab.c"
break ;
case 208 :
# 2135 "gram.y"
{ 
# 2137 "gram.y"
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ;
in_arg_list = 0 ;
hoist_al__Fv ( ) ;

# 2141 "gram.y"
}

# 5282 "y.tab.c"
break ;
case 209 :
# 2145 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;

# 2145 "gram.y"
}

# 5287 "y.tab.c"
break ;
case 210 :
# 2147 "gram.y"
{ (((struct ptr *)(((struct ptr *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))));
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;
must_be_id = 0 ;
}

# 5296 "y.tab.c"
break ;
case 211 :
# 2153 "gram.y"
{ (((struct vec *)(((struct vec *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
}

# 5303 "y.tab.c"
break ;
case 212 :
# 2158 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;

# 2158 "gram.y"
}

# 5308 "y.tab.c"
break ;
case 213 :
# 2160 "gram.y"
{ (((struct ptr *)(((struct ptr *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))));
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;
must_be_id = 0 ;
}

# 5317 "y.tab.c"
break ;
case 214 :
# 2166 "gram.y"
{ (((struct vec *)(((struct vec *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))));
}

# 5324 "y.tab.c"
break ;
case 215 :
# 2170 "gram.y"
{ (((struct fct *)(((struct fct *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> returns__3fct = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [0 ]). pt__7YYSTYPE ;
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-2]). p__7YYSTYPE ;
}

# 5332 "y.tab.c"
break ;
case 216 :
# 2175 "gram.y"
{ (((struct vec *)(((struct vec *)(yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE -> __O1__4expr.tp = (yystack . l_mark__11YYSTACKDATA [0 ]). pt__7YYSTYPE ;
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-2]). p__7YYSTYPE ;
}

# 5340 "y.tab.c"
break ;
case 217 :
# 2182 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;

# 2182 "gram.y"
}

# 5345 "y.tab.c"
break ;
case 218 :
# 2184 "gram.y"
{ (((struct ptr *)(((struct ptr *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))))-> typ__5pvtyp = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp = (((struct type *)(((struct type *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))));
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;
}

# 5353 "y.tab.c"
break ;
case 219 :
# 2194 "gram.y"
{ 
# 2195 "gram.y"
yyval . p__7YYSTYPE = 0 ;
}

# 5360 "y.tab.c"
break ;
case 220 :
# 2198 "gram.y"
{ 
# 2199 "gram.y"
error__FPCc ( (const char *)"ZizedTD must be atG, not local scope") ;
error__FiPCc ( (int )'i' , (const char *)"cannot recover from previous error") ;
}

# 5368 "y.tab.c"
break ;
case 221 :
# 2203 "gram.y"
{ 
# 2203 "gram.y"
register struct slist *__0__X155 ;

# 2203 "gram.y"
struct stmt *__2__X156 ;

# 2204 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE )
# 2205 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE )
# 2206 "gram.y"
( (__0__X155 = (yystack . l_mark__11YYSTACKDATA [-1]). sl__7YYSTYPE ), ( (__2__X156 = (yystack .
# 2206 "gram.y"
l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ), ( ( (__0__X155 -> tail__5slist -> s_list__4stmt = __2__X156 ), (__0__X155 -> tail__5slist = __2__X156 )) , (((void )0 )))
# 2206 "gram.y"
) ) ;
else { 
# 2207 "gram.y"
struct slist *__0__X157 ;

# 2207 "gram.y"
struct stmt *__2__X158 ;

# 2208 "gram.y"
yyval . sl__7YYSTYPE = ( (__0__X157 = 0 ), ( (__2__X158 = (yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ), ( ((__0__X157 || (__0__X157 = (struct
# 2208 "gram.y"
slist *)__nw__FUl ( (size_t )(sizeof (struct slist))) ))?( (__0__X157 -> head__5slist = (__0__X157 -> tail__5slist = __2__X158 )), 0 ) :0 ), __0__X157 )
# 2208 "gram.y"
) ) ;
stmt_seen = 1 ;
}
}

# 5381 "y.tab.c"
break ;
case 222 :
# 2214 "gram.y"
{ 
# 2215 "gram.y"
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;
if ((yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE )stmt_seen = 1 ;
}

# 5389 "y.tab.c"
break ;
case 223 :
# 2221 "gram.y"
{ 
# 2222 "gram.y"
yyval . p__7YYSTYPE = 0 ;
check_decl__Fv ( ) ;
}

# 5397 "y.tab.c"
break ;
case 224 :
# 2228 "gram.y"
{ yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ;

# 2230 "gram.y"
stmt_seen = 1 ;
}

# 5405 "y.tab.c"
break ;
case 225 :
# 2235 "gram.y"
{ ( ( ( ((Ctbl -> k_id__6ktable == 136 )?(((void )expand__6ktableFi ( Ctbl , 20 ) )):(((void )(Ctbl = __ct__6ktableFiP6ktableP4name (
# 2235 "gram.y"
(struct ktable *)0 , 20 , Ctbl , Ctbl -> k_name__6ktable ) )))), ( (Ctbl -> k_id__6ktable = 116 ), ((((Ctbl -> k_next__6ktable == Gtbl )||
# 2235 "gram.y"
(Ctbl -> k_next__6ktable -> k_id__6ktable == 116 ))|| (Ctbl -> k_next__6ktable -> k_id__6ktable == 6 ))?( (Ctbl -> __O1__6ktable.k_t -> next__5table = Ctbl -> k_next__6ktable -> __O1__6ktable.k_t ),
# 2235 "gram.y"
0 ) :0 )) ) ) , (((void )0 ))) ;
(cd_vec [cdi ])= cd ;
(stmt_vec [cdi ])= stmt_seen ;
++ cdi ;
cd = 0 ;
stmt_seen = 0 ;

# 2242 "gram.y"
}

# 5417 "y.tab.c"
break ;
case 226 :
# 2244 "gram.y"
{ Pname __3n ;
Pstmt __3ss ;

# 2246 "gram.y"
register struct block *__0__X159 ;

# 2246 "gram.y"
struct loc __2__X160 ;

# 2246 "gram.y"
struct loc __2__X161 ;

# 2246 "gram.y"
unsigned long __2__X162 ;

# 2244 "gram.y"
__3n = name_unlist__FP5nlist ( cd ) ;
__3ss = stmt_unlist__FP5slist ( (yystack . l_mark__11YYSTACKDATA [-1]). sl__7YYSTYPE ) ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X159 = 0 ), ( (__2__X160 = (yystack . l_mark__11YYSTACKDATA [-3]). l__7YYSTYPE ), ( (__2__X161 = (yystack .
# 2246 "gram.y"
l_mark__11YYSTACKDATA [0 ]). l__7YYSTYPE ), ( ((__0__X159 || (__0__X159 = (struct block *)__nw__4stmtSFUl ( (size_t )(sizeof (struct block))) ))?(((void )( (__0__X159 =
# 2246 "gram.y"
(struct block *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X159 ), (unsigned char )116 , __2__X160 , __3ss ) ), ( (__0__X159 -> __O1__4stmt.d = __3n ),
# 2246 "gram.y"
(__0__X159 -> __O3__4stmt.where2 = __2__X161 )) ) )):(((void )0 ))), __0__X159 ) ) ) ) ;

# 2248 "gram.y"
cd = (cd_vec [(-- cdi )]);
stmt_seen = (stmt_vec [cdi ]);
if (cdi < 0 ){ 
# 2250 "gram.y"
struct ea __0__V96 ;

# 2250 "gram.y"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"block level(%d)", (const struct ea *)( (__2__X162 =
# 2250 "gram.y"
cdi ), ( (( ((& __0__V96 )-> __O1__2ea.i = __2__X162 ), 0 ) ), (& __0__V96 )) ) , (const
# 2250 "gram.y"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} must_be_id = 0 ;
yyval . ps__7YYSTYPE -> k_tbl__4stmt = Ctbl ;

# 2253 "gram.y"
{ 
# 2253 "gram.y"
;

# 2253 "gram.y"
if (Ctbl == Gtbl )
# 2253 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"bad parsing table") ;

# 2253 "gram.y"
{ 
# 2253 "gram.y"
Pktab __1b ;

# 2253 "gram.y"
__1b = Ctbl ;

# 2253 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;

# 2253 "gram.y"
if ((__1b -> k_id__6ktable == 136 )|| 0 )
# 2253 "gram.y"
__dt__6ktableFv ( __1b , 3) ;

# 2253 "gram.y"
}

# 135 "gram.y"
}

# 2254 "gram.y"
}

# 5432 "y.tab.c"
break ;
case 227 :
# 2256 "gram.y"
{ 
# 2256 "gram.y"
register struct block *__0__X163 ;

# 2256 "gram.y"
struct loc __2__X164 ;

# 2256 "gram.y"
struct loc __2__X165 ;

# 2256 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X163 = 0 ), ( (__2__X164 = (yystack . l_mark__11YYSTACKDATA [-1]). l__7YYSTYPE ), ( (__2__X165 = (yystack .
# 2256 "gram.y"
l_mark__11YYSTACKDATA [0 ]). l__7YYSTYPE ), ( ((__0__X163 || (__0__X163 = (struct block *)__nw__4stmtSFUl ( (size_t )(sizeof (struct block))) ))?(((void )( (__0__X163 =
# 2256 "gram.y"
(struct block *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X163 ), (unsigned char )116 , __2__X164 , ((struct stmt *)0 )) ), ( (__0__X163 -> __O1__4stmt.d =
# 2256 "gram.y"
((struct name *)0 )), (__0__X163 -> __O3__4stmt.where2 = __2__X165 )) ) )):(((void )0 ))), __0__X163 ) ) ) ) ;

# 2256 "gram.y"
must_be_id = 0 ;
if (Ctbl -> k_id__6ktable == 136 )
# 2257 "gram.y"
{ 
# 2257 "gram.y"
;

# 2257 "gram.y"
if (Ctbl == Gtbl )
# 2257 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"bad parsing table") ;

# 2257 "gram.y"
{ 
# 2257 "gram.y"
Pktab __1b ;

# 2257 "gram.y"
__1b = Ctbl ;

# 2257 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;

# 2257 "gram.y"
if ((__1b -> k_id__6ktable == 136 )|| 0 )
# 2257 "gram.y"
__dt__6ktableFv ( __1b , 3) ;

# 2257 "gram.y"
}

# 135 "gram.y"
}

# 2258 "gram.y"
}

# 5439 "y.tab.c"
break ;
case 228 :
# 2260 "gram.y"
{ 
# 2260 "gram.y"
register struct block *__0__X166 ;

# 2260 "gram.y"
struct loc __2__X167 ;

# 2260 "gram.y"
struct loc __2__X168 ;

# 2260 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X166 = 0 ), ( (__2__X167 = (yystack . l_mark__11YYSTACKDATA [-2]). l__7YYSTYPE ), ( (__2__X168 = (yystack .
# 2260 "gram.y"
l_mark__11YYSTACKDATA [0 ]). l__7YYSTYPE ), ( ((__0__X166 || (__0__X166 = (struct block *)__nw__4stmtSFUl ( (size_t )(sizeof (struct block))) ))?(((void )( (__0__X166 =
# 2260 "gram.y"
(struct block *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X166 ), (unsigned char )116 , __2__X167 , ((struct stmt *)0 )) ), ( (__0__X166 -> __O1__4stmt.d =
# 2260 "gram.y"
((struct name *)0 )), (__0__X166 -> __O3__4stmt.where2 = __2__X168 )) ) )):(((void )0 ))), __0__X166 ) ) ) ) ;

# 2260 "gram.y"
must_be_id = 0 ;
if (Ctbl -> k_id__6ktable == 136 )
# 2261 "gram.y"
{ 
# 2261 "gram.y"
;

# 2261 "gram.y"
if (Ctbl == Gtbl )
# 2261 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"bad parsing table") ;

# 2261 "gram.y"
{ 
# 2261 "gram.y"
Pktab __1b ;

# 2261 "gram.y"
__1b = Ctbl ;

# 2261 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;

# 2261 "gram.y"
if ((__1b -> k_id__6ktable == 136 )|| 0 )
# 2261 "gram.y"
__dt__6ktableFv ( __1b , 3) ;

# 2261 "gram.y"
}

# 135 "gram.y"
}

# 2262 "gram.y"
}

# 5446 "y.tab.c"
break ;
case 229 :
# 2266 "gram.y"
{ 
# 2266 "gram.y"
struct estmt *__0__X169 ;

# 2266 "gram.y"
struct loc __2__X170 ;

# 2266 "gram.y"
struct expr *__2__X171 ;

# 2266 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X169 = 0 ), ( (__2__X170 = curloc ), ( (__2__X171 = (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ),
# 2266 "gram.y"
( ((__0__X169 || (__0__X169 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X169 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct
# 2266 "gram.y"
stmt *)__0__X169 ), ((unsigned char )72 ), __2__X170 , ((struct stmt *)0 )) ), (__0__X169 -> __O2__4stmt.e = __2__X171 )) :0 ), __0__X169 ) )
# 2266 "gram.y"
) ) ;

# 2266 "gram.y"
}

# 5451 "y.tab.c"
break ;
case 230 :
# 2268 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4stmtFUc3locP4stmt ( (struct stmt *)0 , (unsigned char )3 , (yystack . l_mark__11YYSTACKDATA [0 ]). l__7YYSTYPE ,
# 2268 "gram.y"
(struct stmt *)0 ) ;

# 2268 "gram.y"
}

# 5456 "y.tab.c"
break ;
case 231 :
# 2270 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4stmtFUc3locP4stmt ( (struct stmt *)0 , (unsigned char )7 , (yystack . l_mark__11YYSTACKDATA [0 ]). l__7YYSTYPE ,
# 2270 "gram.y"
(struct stmt *)0 ) ;

# 2270 "gram.y"
}

# 5461 "y.tab.c"
break ;
case 232 :
# 2272 "gram.y"
{ 
# 2272 "gram.y"
struct lstmt *__0__X172 ;

# 2272 "gram.y"
struct loc __2__X173 ;

# 2272 "gram.y"
struct name *__2__X174 ;

# 2272 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X172 = 0 ), ( (__2__X173 = (yystack . l_mark__11YYSTACKDATA [-1]). l__7YYSTYPE ), ( (__2__X174 = (yystack .
# 2272 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X172 || (__0__X172 = (struct lstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct lstmt))) ))?( (__0__X172 = (struct
# 2272 "gram.y"
lstmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X172 ), ((unsigned char )19 ), __2__X173 , ((struct stmt *)0 )) ), (__0__X172 -> __O1__4stmt.d = __2__X174 )) :0 ),
# 2272 "gram.y"
__0__X172 ) ) ) ) ;

# 2272 "gram.y"
}

# 5466 "y.tab.c"
break ;
case 233 :
# 2273 "gram.y"
{ stmt_seen = 1 ;

# 2273 "gram.y"
}

# 5471 "y.tab.c"
break ;
case 234 :
# 2274 "gram.y"
{ 
# 2274 "gram.y"
struct estmt *__0__X175 ;

# 2274 "gram.y"
struct loc __2__X176 ;

# 2274 "gram.y"
struct expr *__2__X177 ;

# 2274 "gram.y"
struct stmt *__2__X178 ;

# 2274 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X175 = 0 ), ( (__2__X176 = (yystack . l_mark__11YYSTACKDATA [-4]). l__7YYSTYPE ), ( (__2__X177 = (yystack .
# 2274 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ), ( (__2__X178 = (yystack . l_mark__11YYSTACKDATA [-2]). ps__7YYSTYPE ), ( ((__0__X175 || (__0__X175 = (struct estmt *)__nw__4stmtSFUl ( (unsigned long
# 2274 "gram.y"
)(sizeof (struct estmt))) ))?( (__0__X175 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X175 ), ((unsigned char )10 ), __2__X176 , __2__X178 ) ),
# 2274 "gram.y"
(__0__X175 -> __O2__4stmt.e = __2__X177 )) :0 ), __0__X175 ) ) ) ) ) ;

# 2274 "gram.y"
}

# 5476 "y.tab.c"
break ;
case 235 :
# 2276 "gram.y"
{ 
# 2276 "gram.y"
struct estmt *__0__X179 ;

# 2276 "gram.y"
struct loc __2__X180 ;

# 2276 "gram.y"
struct expr *__2__X181 ;

# 2277 "gram.y"
if (stmt_seen )
# 2278 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X179 = 0 ), ( (__2__X180 = curloc ), ( (__2__X181 = (((struct expr *)(((struct
# 2278 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [-1]). s__7YYSTYPE ))))), ( ((__0__X179 || (__0__X179 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X179 =
# 2278 "gram.y"
(struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X179 ), ((unsigned char )1 ), __2__X180 , ((struct stmt *)0 )) ), (__0__X179 -> __O2__4stmt.e = __2__X181 ))
# 2278 "gram.y"
:0 ), __0__X179 ) ) ) ) ;
else { 
# 2280 "gram.y"
Pname __4n ;

# 2280 "gram.y"
__4n = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'A' ) ) ;
__4n -> __O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )1 , ((struct name *)(((struct name *)(yystack . l_mark__11YYSTACKDATA [-1]). s__7YYSTYPE ))))
# 2281 "gram.y"
;
if (cd )
# 2283 "gram.y"
add_list__5nlistFP4name ( cd , __4n ) ;
else 
# 2285 "gram.y"
cd = __ct__5nlistFP4name ( (struct nlist *)0 , __4n ) ;
yyval . p__7YYSTYPE = 0 ;
}
}

# 5493 "y.tab.c"
break ;
case 236 :
# 2291 "gram.y"
{ 
# 2292 "gram.y"
if (((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar )!= 72 ){ 
# 2293 "gram.y"
error__FPCc ( (const
# 2293 "gram.y"
char *)"`;' missing afterS") ;
la_backup__FUc7YYSTYPE ( (unsigned char )yychar , yylval ) ;
yychar = 72 ;
}
}

# 5504 "y.tab.c"
break ;
case 239 :
# 2302 "gram.y"
{ 
# 2302 "gram.y"
struct estmt *__0__X182 ;

# 2302 "gram.y"
struct loc __2__X183 ;

# 2302 "gram.y"
struct expr *__2__X184 ;

# 2302 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X182 = 0 ), ( (__2__X183 = curloc ), ( (__2__X184 = dummy ), ( ((__0__X182 ||
# 2302 "gram.y"
(__0__X182 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X182 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X182 ), ((unsigned
# 2302 "gram.y"
char )72 ), __2__X183 , ((struct stmt *)0 )) ), (__0__X182 -> __O2__4stmt.e = __2__X184 )) :0 ), __0__X182 ) ) ) )
# 2302 "gram.y"
;

# 2302 "gram.y"
}

# 5509 "y.tab.c"
break ;
case 240 :
# 2304 "gram.y"
{ 
# 2304 "gram.y"
struct estmt *__0__X185 ;

# 2304 "gram.y"
struct loc __2__X186 ;

# 2304 "gram.y"
struct expr *__2__X187 ;

# 2304 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X185 = 0 ), ( (__2__X186 = (yystack . l_mark__11YYSTACKDATA [-2]). l__7YYSTYPE ), ( (__2__X187 = (yystack .
# 2304 "gram.y"
l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ), ( ((__0__X185 || (__0__X185 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X185 = (struct
# 2304 "gram.y"
estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X185 ), ((unsigned char )28 ), __2__X186 , ((struct stmt *)0 )) ), (__0__X185 -> __O2__4stmt.e = __2__X187 )) :0 ),
# 2304 "gram.y"
__0__X185 ) ) ) ) ;

# 2304 "gram.y"
}

# 5514 "y.tab.c"
break ;
case 241 :
# 2306 "gram.y"
{ 
# 2307 "gram.y"
error__FPCc ( (const char *)"local linkage specification") ;
yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 5522 "y.tab.c"
break ;
case 242 :
# 2311 "gram.y"
{ Pname __3n ;

# 2311 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
if (__3n ){ 
# 2314 "gram.y"
if (stmt_seen ){ 
# 2314 "gram.y"
register struct block *__0__X188 ;

# 2314 "gram.y"
struct loc __2__X189 ;

# 2314 "gram.y"
struct loc __2__X190 ;

# 2315 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X188 = 0 ), ( (__2__X189 = __3n -> where__4name ), ( (__2__X190 = noloc ), (
# 2315 "gram.y"
((__0__X188 || (__0__X188 = (struct block *)__nw__4stmtSFUl ( (size_t )(sizeof (struct block))) ))?(((void )( (__0__X188 = (struct block *)__ct__4stmtFUc3locP4stmt ( ((struct
# 2315 "gram.y"
stmt *)__0__X188 ), (unsigned char )116 , __2__X189 , ((struct stmt *)0 )) ), ( (__0__X188 -> __O1__4stmt.d = __3n ), (__0__X188 -> __O3__4stmt.where2 =
# 2315 "gram.y"
__2__X190 )) ) )):(((void )0 ))), __0__X188 ) ) ) ) ;
yyval . ps__7YYSTYPE -> base__4node = 118 ;
yyval . ps__7YYSTYPE -> k_tbl__4stmt = Ctbl ;
}
else { 
# 2320 "gram.y"
if (cd )
# 2321 "gram.y"
add_list__5nlistFP4name ( cd , __3n ) ;
else 
# 2323 "gram.y"
cd = __ct__5nlistFP4name ( (struct nlist *)0 , __3n ) ;
yyval . p__7YYSTYPE = 0 ;
}
}
else if (stmt_seen ){ 
# 2327 "gram.y"
register struct block *__0__X191 ;

# 2327 "gram.y"
struct loc __2__X192 ;

# 2327 "gram.y"
struct loc __2__X193 ;

# 2328 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X191 = 0 ), ( (__2__X192 = curloc ), ( (__2__X193 = noloc ), ( ((__0__X191 ||
# 2328 "gram.y"
(__0__X191 = (struct block *)__nw__4stmtSFUl ( (size_t )(sizeof (struct block))) ))?(((void )( (__0__X191 = (struct block *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X191 ),
# 2328 "gram.y"
(unsigned char )116 , __2__X192 , ((struct stmt *)0 )) ), ( (__0__X191 -> __O1__4stmt.d = ((struct name *)0 )), (__0__X191 -> __O3__4stmt.where2 =
# 2328 "gram.y"
__2__X193 )) ) )):(((void )0 ))), __0__X191 ) ) ) ) ;
yyval . ps__7YYSTYPE -> base__4node = 117 ;
}
}

# 5547 "y.tab.c"
break ;
case 243 :
# 2333 "gram.y"
{ 
# 2334 "gram.y"
Pname __3n ;

# 2334 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
if (! in_progress__17templ_compilation )
# 2336 "gram.y"
{ 
# 2336 "gram.y"
struct ea __0__V97 ;

# 2336 "gram.y"
error__FP3locPCcRC2eaN33 ( & __3n -> where__4name , (const char *)"%n's definition is nested (did you forget a ``}''?)", (const struct ea *)(
# 2336 "gram.y"
((& __0__V97 )-> __O1__2ea.p = ((const void *)__3n )), (& __0__V97 )) , (const struct ea *)ea0 , (const struct
# 2336 "gram.y"
ea *)ea0 , (const struct ea *)ea0 ) ;
} if (cd )
# 2338 "gram.y"
add_list__5nlistFP4name ( cd , __3n ) ;
else 
# 2340 "gram.y"
cd = __ct__5nlistFP4name ( (struct nlist *)0 , __3n ) ;
yyval . p__7YYSTYPE = 0 ;
}

# 5561 "y.tab.c"
break ;
case 245 :
# 2345 "gram.y"
{ 
# 2345 "gram.y"
register struct ifstmt *__0__X194 ;

# 2345 "gram.y"
struct loc __2__X195 ;

# 2345 "gram.y"
struct expr *__2__X196 ;

# 2345 "gram.y"
struct stmt *__2__X197 ;

# 2345 "gram.y"
struct stmt *__2__X198 ;

# 2345 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X194 = 0 ), ( (__2__X195 = (yystack . l_mark__11YYSTACKDATA [-2]). l__7YYSTYPE ), ( (__2__X196 = (yystack .
# 2345 "gram.y"
l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ), ( (__2__X197 = (yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ), ( (__2__X198 = 0 ), ( ((__0__X194 || (__0__X194 = (struct
# 2345 "gram.y"
ifstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct ifstmt))) ))?( (__0__X194 = (struct ifstmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X194 ), (unsigned char )20 ,
# 2345 "gram.y"
__2__X195 , __2__X197 ) ), ( (__0__X194 -> __O2__4stmt.e = __2__X196 ), (__0__X194 -> __O3__4stmt.else_stmt = __2__X198 )) ) :0 ), __0__X194 ) )
# 2345 "gram.y"
) ) ) ) ;

# 2345 "gram.y"
}

# 5566 "y.tab.c"
break ;
case 246 :
# 2347 "gram.y"
{ 
# 2347 "gram.y"
register struct ifstmt *__0__X199 ;

# 2347 "gram.y"
struct loc __2__X200 ;

# 2347 "gram.y"
struct expr *__2__X201 ;

# 2347 "gram.y"
struct stmt *__2__X202 ;

# 2347 "gram.y"
struct stmt *__2__X203 ;

# 2347 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X199 = 0 ), ( (__2__X200 = (yystack . l_mark__11YYSTACKDATA [-4]). l__7YYSTYPE ), ( (__2__X201 = (yystack .
# 2347 "gram.y"
l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ), ( (__2__X202 = (yystack . l_mark__11YYSTACKDATA [-2]). ps__7YYSTYPE ), ( (__2__X203 = (yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ), ( ((__0__X199 ||
# 2347 "gram.y"
(__0__X199 = (struct ifstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct ifstmt))) ))?( (__0__X199 = (struct ifstmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X199 ), (unsigned
# 2347 "gram.y"
char )20 , __2__X200 , __2__X202 ) ), ( (__0__X199 -> __O2__4stmt.e = __2__X201 ), (__0__X199 -> __O3__4stmt.else_stmt = __2__X203 )) ) :0 ),
# 2347 "gram.y"
__0__X199 ) ) ) ) ) ) ;

# 2347 "gram.y"
}

# 5571 "y.tab.c"
break ;
case 247 :
# 2349 "gram.y"
{ 
# 2349 "gram.y"
struct estmt *__0__X204 ;

# 2349 "gram.y"
struct loc __2__X205 ;

# 2349 "gram.y"
struct expr *__2__X206 ;

# 2349 "gram.y"
struct stmt *__2__X207 ;

# 2349 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X204 = 0 ), ( (__2__X205 = (yystack . l_mark__11YYSTACKDATA [-2]). l__7YYSTYPE ), ( (__2__X206 = (yystack .
# 2349 "gram.y"
l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ), ( (__2__X207 = (yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ), ( ((__0__X204 || (__0__X204 = (struct estmt *)__nw__4stmtSFUl ( (unsigned long
# 2349 "gram.y"
)(sizeof (struct estmt))) ))?( (__0__X204 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X204 ), ((unsigned char )39 ), __2__X205 , __2__X207 ) ),
# 2349 "gram.y"
(__0__X204 -> __O2__4stmt.e = __2__X206 )) :0 ), __0__X204 ) ) ) ) ) ;

# 2349 "gram.y"
}

# 5576 "y.tab.c"
break ;
case 248 :
# 2350 "gram.y"
{ stmt_seen = 1 ;

# 2350 "gram.y"
}

# 5581 "y.tab.c"
break ;
case 249 :
# 2351 "gram.y"
{ 
# 2351 "gram.y"
register struct forstmt *__0__X208 ;

# 2351 "gram.y"
struct loc __2__X209 ;

# 2351 "gram.y"
struct stmt *__2__X210 ;

# 2351 "gram.y"
struct expr *__2__X211 ;

# 2351 "gram.y"
struct expr *__2__X212 ;

# 2351 "gram.y"
struct stmt *__2__X213 ;

# 2351 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X208 = 0 ), ( (__2__X209 = (yystack . l_mark__11YYSTACKDATA [-8]). l__7YYSTYPE ), ( (__2__X210 = (yystack .
# 2351 "gram.y"
l_mark__11YYSTACKDATA [-5]). ps__7YYSTYPE ), ( (__2__X211 = (yystack . l_mark__11YYSTACKDATA [-4]). pe__7YYSTYPE ), ( (__2__X212 = (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ), ( (__2__X213 =
# 2351 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ), ( ((__0__X208 || (__0__X208 = (struct forstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct forstmt))) ))?( (__0__X208 =
# 2351 "gram.y"
(struct forstmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X208 ), (unsigned char )16 , __2__X209 , __2__X213 ) ), ( (__0__X208 -> __O3__4stmt.for_init = __2__X210 ),
# 2351 "gram.y"
( (__0__X208 -> __O2__4stmt.e = __2__X211 ), (__0__X208 -> __O1__4stmt.e2 = __2__X212 )) ) ) :0 ), __0__X208 ) ) ) )
# 2351 "gram.y"
) ) ) ;

# 2351 "gram.y"
}

# 5586 "y.tab.c"
break ;
case 250 :
# 2352 "gram.y"
{ (scd [(++ scdp )])= cd ;

# 2352 "gram.y"
}

# 5591 "y.tab.c"
break ;
case 251 :
# 2353 "gram.y"
{ 
# 2353 "gram.y"
struct estmt *__0__X214 ;

# 2353 "gram.y"
struct loc __2__X215 ;

# 2353 "gram.y"
struct expr *__2__X216 ;

# 2353 "gram.y"
struct stmt *__2__X217 ;

# 2354 "gram.y"
-- scdp ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X214 = 0 ), ( (__2__X215 = (yystack . l_mark__11YYSTACKDATA [-3]). l__7YYSTYPE ), ( (__2__X216 = (yystack .
# 2355 "gram.y"
l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ), ( (__2__X217 = (yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ), ( ((__0__X214 || (__0__X214 = (struct estmt *)__nw__4stmtSFUl ( (unsigned long
# 2355 "gram.y"
)(sizeof (struct estmt))) ))?( (__0__X214 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X214 ), ((unsigned char )33 ), __2__X215 , __2__X217 ) ),
# 2355 "gram.y"
(__0__X214 -> __O2__4stmt.e = __2__X216 )) :0 ), __0__X214 ) ) ) ) ) ;
}

# 5599 "y.tab.c"
break ;
case 252 :
# 2357 "gram.y"
{ yyval . pn__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;

# 2357 "gram.y"
stmt_seen = 1 ;

# 2357 "gram.y"
}

# 5604 "y.tab.c"
break ;
case 253 :
# 2358 "gram.y"
{ Pname __3n ;

# 2359 "gram.y"
struct lstmt *__0__X218 ;

# 2359 "gram.y"
struct loc __2__X219 ;

# 2359 "gram.y"
struct stmt *__2__X220 ;

# 2358 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X218 = 0 ), ( (__2__X219 = __3n -> where__4name ), ( (__2__X220 = (yystack . l_mark__11YYSTACKDATA [0 ]).
# 2359 "gram.y"
ps__7YYSTYPE ), ( ((__0__X218 || (__0__X218 = (struct lstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct lstmt))) ))?( (__0__X218 = (struct lstmt *)__ct__4stmtFUc3locP4stmt (
# 2359 "gram.y"
((struct stmt *)__0__X218 ), ((unsigned char )115 ), __2__X219 , __2__X220 ) ), (__0__X218 -> __O1__4stmt.d = __3n )) :0 ), __0__X218 ) )
# 2359 "gram.y"
) ) ;
}

# 5611 "y.tab.c"
break ;
case 254 :
# 2361 "gram.y"
{ yyval . pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O2__4expr.string ) ;

# 2361 "gram.y"
stmt_seen = 1 ;

# 2361 "gram.y"
}

# 5616 "y.tab.c"
break ;
case 255 :
# 2362 "gram.y"
{ Pname __3n ;

# 2363 "gram.y"
struct lstmt *__0__X221 ;

# 2363 "gram.y"
struct loc __2__X222 ;

# 2363 "gram.y"
struct stmt *__2__X223 ;

# 2362 "gram.y"
__3n = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X221 = 0 ), ( (__2__X222 = __3n -> where__4name ), ( (__2__X223 = (yystack . l_mark__11YYSTACKDATA [0 ]).
# 2363 "gram.y"
ps__7YYSTYPE ), ( ((__0__X221 || (__0__X221 = (struct lstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct lstmt))) ))?( (__0__X221 = (struct lstmt *)__ct__4stmtFUc3locP4stmt (
# 2363 "gram.y"
((struct stmt *)__0__X221 ), ((unsigned char )115 ), __2__X222 , __2__X223 ) ), (__0__X221 -> __O1__4stmt.d = __3n )) :0 ), __0__X221 ) )
# 2363 "gram.y"
) ) ;
}

# 5623 "y.tab.c"
break ;
case 256 :
# 2365 "gram.y"
{ stmt_seen = 1 ;

# 2365 "gram.y"
}

# 5628 "y.tab.c"
break ;
case 257 :
# 2366 "gram.y"
{ 
# 2366 "gram.y"
struct estmt *__0__X224 ;

# 2366 "gram.y"
struct loc __2__X225 ;

# 2366 "gram.y"
struct expr *__2__X226 ;

# 2366 "gram.y"
struct stmt *__2__X227 ;

# 2367 "gram.y"
if ((((scdp >= 0 )&& ((scd [scdp ])!= cd ))&& cd )&& decl_with_init__FP5nlist ( cd ) )error__FPCc ( (const char *)"jump past initializer (did you forget a '{ }'?)")
# 2367 "gram.y"
;
if ((yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE == dummy )error__FPCc ( (const char *)"empty case label") ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X224 = 0 ), ( (__2__X225 = (yystack . l_mark__11YYSTACKDATA [-4]). l__7YYSTYPE ), ( (__2__X226 = (yystack .
# 2369 "gram.y"
l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ), ( (__2__X227 = (yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ), ( ((__0__X224 || (__0__X224 = (struct estmt *)__nw__4stmtSFUl ( (unsigned long
# 2369 "gram.y"
)(sizeof (struct estmt))) ))?( (__0__X224 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X224 ), ((unsigned char )4 ), __2__X225 , __2__X227 ) ),
# 2369 "gram.y"
(__0__X224 -> __O2__4stmt.e = __2__X226 )) :0 ), __0__X224 ) ) ) ) ) ;
}

# 5637 "y.tab.c"
break ;
case 258 :
# 2371 "gram.y"
{ stmt_seen = 1 ;

# 2371 "gram.y"
}

# 5642 "y.tab.c"
break ;
case 259 :
# 2372 "gram.y"
{ 
# 2373 "gram.y"
if (((((scdp >= 0 )&& ((scd [scdp ])!= cd ))&& cd )&& (yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE )&& decl_with_init__FP5nlist ( cd ) )error__FPCc (
# 2373 "gram.y"
(const char *)"jump past initializer (did you forget a '{ }'?)") ;
yyval . p__7YYSTYPE = (struct node *)__ct__4stmtFUc3locP4stmt ( (struct stmt *)0 , (unsigned char )8 , (yystack . l_mark__11YYSTACKDATA [-3]). l__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]).
# 2374 "gram.y"
ps__7YYSTYPE ) ;
}

# 5650 "y.tab.c"
break ;
case 260 :
# 2377 "gram.y"
{ 
# 2377 "gram.y"
register struct handler *__0__X228 ;

# 2377 "gram.y"
struct stmt *__2__X229 ;

# 2377 "gram.y"
struct stmt *__2__X230 ;

# 2377 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X228 = 0 ), ( (__2__X229 = (yystack . l_mark__11YYSTACKDATA [-1]). ps__7YYSTYPE ), ( (__2__X230 = stmt_unlist__FP5slist (
# 2377 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). sl__7YYSTYPE ) ), ( ((__0__X228 || (__0__X228 = (struct handler *)__nw__4stmtSFUl ( (size_t )(sizeof (struct handler))) ))?(((void
# 2377 "gram.y"
)( (__0__X228 = (struct handler *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X228 ), (unsigned char )100 , __2__X229 ?__2__X229 -> where__4stmt :curloc , __2__X229 ) ), (
# 2377 "gram.y"
(__0__X228 -> __O1__4stmt.d = 0 ), ( (__0__X228 -> s__4stmt -> s_list__4stmt = __2__X230 ), (__0__X228 -> __O3__4stmt.where2 = curloc )) ) ) )):(((void
# 2377 "gram.y"
)0 ))), __0__X228 ) ) ) ) ;

# 2377 "gram.y"
}

# 5655 "y.tab.c"
break ;
case 261 :
# 2382 "gram.y"
{ yyval . sl__7YYSTYPE = 0 ;

# 2382 "gram.y"
}

# 5660 "y.tab.c"
break ;
case 262 :
# 2384 "gram.y"
{ 
# 2384 "gram.y"
register struct slist *__0__X231 ;

# 2384 "gram.y"
struct stmt *__2__X232 ;

# 2385 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE )
# 2386 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-1]). sl__7YYSTYPE )
# 2387 "gram.y"
( (__0__X231 = (yystack . l_mark__11YYSTACKDATA [-1]). sl__7YYSTYPE ), ( (__2__X232 = (yystack .
# 2387 "gram.y"
l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ), ( ( (__0__X231 -> tail__5slist -> s_list__4stmt = __2__X232 ), (__0__X231 -> tail__5slist = __2__X232 )) , (((void )0 )))
# 2387 "gram.y"
) ) ;
else { 
# 2388 "gram.y"
struct slist *__0__X233 ;

# 2388 "gram.y"
struct stmt *__2__X234 ;

# 2389 "gram.y"
yyval . sl__7YYSTYPE = ( (__0__X233 = 0 ), ( (__2__X234 = (yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ), ( ((__0__X233 || (__0__X233 = (struct
# 2389 "gram.y"
slist *)__nw__FUl ( (size_t )(sizeof (struct slist))) ))?( (__0__X233 -> head__5slist = (__0__X233 -> tail__5slist = __2__X234 )), 0 ) :0 ), __0__X233 )
# 2389 "gram.y"
) ) ;
stmt_seen = 1 ;
}
}

# 5673 "y.tab.c"
break ;
case 263 :
# 2396 "gram.y"
{ 
# 2397 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ){ 
# 2398 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4name.n_list = (yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE -> __O1__4stmt.d ;
# 2398 "gram.y"

# 2399 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE -> __O1__4stmt.d = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
}
yyval . ps__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). ps__7YYSTYPE ;
}

# 5684 "y.tab.c"
break ;
case 264 :
# 2407 "gram.y"
{ in_arg_list = 0 ;
yyval . pn__7YYSTYPE = normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-2]). p__7YYSTYPE ))), (struct block *)0 , (unsigned
# 2408 "gram.y"
char )0 ) ;
if (yyval . pn__7YYSTYPE -> __O2__4expr.string == 0 )
# 2410 "gram.y"
yyval . pn__7YYSTYPE = 0 ;
else 
# 2412 "gram.y"
yyval . pn__7YYSTYPE -> base__4node = 98 ;
}

# 5695 "y.tab.c"
break ;
case 265 :
# 2415 "gram.y"
{ yyval . pn__7YYSTYPE = 0 ;

# 2415 "gram.y"
}

# 5700 "y.tab.c"
break ;
case 266 :
# 2422 "gram.y"
{ Pexpr __3e ;

# 2422 "gram.y"
__3e = expr_unlist__FP5elist ( (yystack . l_mark__11YYSTACKDATA [0 ]). el__7YYSTYPE ) ;
while (__3e && (__3e -> __O2__4expr.e1 == dummy )){ 
# 2424 "gram.y"
Pexpr __4ee2 ;

# 2424 "gram.y"
__4ee2 = __3e -> __O3__4expr.e2 ;
if (__4ee2 )error__FPCc ( (const char *)"EX inEL") ;
( (__3e ?(((void )(__3e ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__3e , (size_t )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 2426 "gram.y"
;
__3e = __4ee2 ;
}
yyval . p__7YYSTYPE = (struct node *)__3e ;
}

# 5713 "y.tab.c"
break ;
case 267 :
# 2434 "gram.y"
{ 
# 2434 "gram.y"
struct elist *__0__X235 ;

# 2434 "gram.y"
struct expr *__2__X236 ;

# 2434 "gram.y"
yyval . el__7YYSTYPE = ( (__0__X235 = 0 ), ( (__2__X236 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (yystack .
# 2434 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE , (struct expr *)0 ) ), ( ((__0__X235 || (__0__X235 = (struct elist *)__nw__FUl ( (size_t )(sizeof (struct elist)))
# 2434 "gram.y"
))?( (__0__X235 -> head__5elist = (__0__X235 -> tail__5elist = __2__X236 )), 0 ) :0 ), __0__X235 ) ) ) ;

# 2434 "gram.y"
}

# 5718 "y.tab.c"
break ;
case 268 :
# 2436 "gram.y"
{ 
# 2436 "gram.y"
register struct elist *__0__X237 ;

# 2436 "gram.y"
struct expr *__2__X238 ;

# 2436 "gram.y"
( (__0__X237 = (yystack . l_mark__11YYSTACKDATA [-2]). el__7YYSTYPE ), ( (__2__X238 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (yystack .
# 2436 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE , (struct expr *)0 ) ), ( ( (__0__X237 -> tail__5elist -> __O3__4expr.e2 = __2__X238 ), (__0__X237 -> tail__5elist = __2__X238 ))
# 2436 "gram.y"
, (((void )0 ))) ) ) ;

# 2436 "gram.y"
}

# 5723 "y.tab.c"
break ;
case 270 :
# 2441 "gram.y"
{ 
# 2442 "gram.y"
if (in_arg_list )
# 2443 "gram.y"
error__FPCc ( (const char *)"syntax error: IrL not permitted in AL") ;
else if (in_binit_list )
# 2445 "gram.y"
error__FPCc ( (const char *)"syntax error: IrL not permitted inMIr") ;
else 
# 2447 "gram.y"
init_seen = 1 ;
{ Pexpr __3e ;
if ((yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE )
# 2450 "gram.y"
__3e = (yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ;
else 
# 2452 "gram.y"
__3e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , dummy , (struct expr *)0 ) ;
yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , __3e , (struct expr *)0 ) ;

# 2453 "gram.y"
}
}

# 5741 "y.tab.c"
break ;
case 271 :
# 2458 "gram.y"
{ bbinop :yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ,
# 2458 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ) ;

# 2458 "gram.y"
}

# 5746 "y.tab.c"
break ;
case 272 :
# 2459 "gram.y"
{ goto bbinop ;

# 2459 "gram.y"
}

# 5751 "y.tab.c"
break ;
case 273 :
# 2460 "gram.y"
{ goto bbinop ;

# 2460 "gram.y"
}

# 5756 "y.tab.c"
break ;
case 274 :
# 2461 "gram.y"
{ goto bbinop ;

# 2461 "gram.y"
}

# 5761 "y.tab.c"
break ;
case 275 :
# 2462 "gram.y"
{ goto bbinop ;

# 2462 "gram.y"
}

# 5766 "y.tab.c"
break ;
case 276 :
# 2463 "gram.y"
{ goto bbinop ;

# 2463 "gram.y"
}

# 5771 "y.tab.c"
break ;
case 277 :
# 2464 "gram.y"
{ goto bbinop ;

# 2464 "gram.y"
}

# 5776 "y.tab.c"
break ;
case 278 :
# 2465 "gram.y"
{ goto bbinop ;

# 2465 "gram.y"
}

# 5781 "y.tab.c"
break ;
case 279 :
# 2466 "gram.y"
{ goto bbinop ;

# 2466 "gram.y"
}

# 5786 "y.tab.c"
break ;
case 280 :
# 2467 "gram.y"
{ goto bbinop ;

# 2467 "gram.y"
}

# 5791 "y.tab.c"
break ;
case 281 :
# 2468 "gram.y"
{ goto bbinop ;

# 2468 "gram.y"
}

# 5796 "y.tab.c"
break ;
case 282 :
# 2469 "gram.y"
{ goto bbinop ;

# 2469 "gram.y"
}

# 5801 "y.tab.c"
break ;
case 283 :
# 2470 "gram.y"
{ goto bbinop ;

# 2470 "gram.y"
}

# 5806 "y.tab.c"
break ;
case 284 :
# 2471 "gram.y"
{ goto bbinop ;

# 2471 "gram.y"
}

# 5811 "y.tab.c"
break ;
case 285 :
# 2472 "gram.y"
{ goto bbinop ;

# 2472 "gram.y"
}

# 5816 "y.tab.c"
break ;
case 286 :
# 2473 "gram.y"
{ goto bbinop ;

# 2473 "gram.y"
}

# 5821 "y.tab.c"
break ;
case 287 :
# 2474 "gram.y"
{ goto bbinop ;

# 2474 "gram.y"
}

# 5826 "y.tab.c"
break ;
case 288 :
# 2476 "gram.y"
{ 
# 2476 "gram.y"
struct qexpr *__0__X239 ;

# 2476 "gram.y"
struct expr *__2__X240 ;

# 2476 "gram.y"
struct expr *__2__X241 ;

# 2476 "gram.y"
struct expr *__2__X242 ;

# 2476 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X239 = 0 ), ( (__2__X240 = (yystack . l_mark__11YYSTACKDATA [-4]). pe__7YYSTYPE ), ( (__2__X241 = (yystack .
# 2476 "gram.y"
l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ), ( (__2__X242 = (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ), ( ((__0__X239 || (__0__X239 = (struct qexpr *)__nw__4exprSFUl ( (unsigned long
# 2476 "gram.y"
)(sizeof (struct qexpr))) ))?( (__0__X239 = (struct qexpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X239 ), (unsigned char )68 , __2__X241 , __2__X242 ) ),
# 2476 "gram.y"
(__0__X239 -> __O4__4expr.cond = __2__X240 )) :0 ), __0__X239 ) ) ) ) ) ;

# 2476 "gram.y"
}

# 5831 "y.tab.c"
break ;
case 289 :
# 2478 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ,
# 2478 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ) ;

# 2478 "gram.y"
}

# 5836 "y.tab.c"
break ;
case 290 :
# 2480 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )9 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ,
# 2480 "gram.y"
(struct expr *)0 ) ;

# 2480 "gram.y"
}

# 5841 "y.tab.c"
break ;
case 291 :
# 2482 "gram.y"
{ 
# 2483 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE != dummy ){ 
# 2484 "gram.y"
if (warning_opt || strict_opt )
# 2485 "gram.y"
error__FiPCc ( strict_opt ?0 :119, (const char *)"v in `delete[v]' is redundant; use `delete[] instead (anachronism)")
# 2485 "gram.y"
;
}
yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )9 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]).
# 2487 "gram.y"
pe__7YYSTYPE ) ;
}

# 5852 "y.tab.c"
break ;
case 292 :
# 2490 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )188 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ,
# 2490 "gram.y"
(struct expr *)0 ) ;

# 2490 "gram.y"
}

# 5857 "y.tab.c"
break ;
case 293 :
# 2492 "gram.y"
{ 
# 2493 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE != dummy ){ 
# 2494 "gram.y"
if (warning_opt || strict_opt )
# 2495 "gram.y"
error__FiPCc ( strict_opt ?0 :119, (const char *)"v in `::delete[v]' is redundant; use `::delete[] instead (anachronism)")
# 2495 "gram.y"
;
}
yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )9 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]).
# 2497 "gram.y"
pe__7YYSTYPE ) ;
}

# 5868 "y.tab.c"
break ;
case 295 :
# 2501 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )99 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE , (struct expr *)0 ) ;

# 2501 "gram.y"
}

# 5873 "y.tab.c"
break ;
case 296 :
# 2505 "gram.y"
{ binop :yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ,
# 2505 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ) ;

# 2505 "gram.y"
}

# 5878 "y.tab.c"
break ;
case 297 :
# 2506 "gram.y"
{ goto binop ;

# 2506 "gram.y"
}

# 5883 "y.tab.c"
break ;
case 298 :
# 2507 "gram.y"
{ goto binop ;

# 2507 "gram.y"
}

# 5888 "y.tab.c"
break ;
case 299 :
# 2508 "gram.y"
{ goto binop ;

# 2508 "gram.y"
}

# 5893 "y.tab.c"
break ;
case 300 :
# 2509 "gram.y"
{ goto binop ;

# 2509 "gram.y"
}

# 5898 "y.tab.c"
break ;
case 301 :
# 2510 "gram.y"
{ goto binop ;

# 2510 "gram.y"
}

# 5903 "y.tab.c"
break ;
case 302 :
# 2511 "gram.y"
{ goto binop ;

# 2511 "gram.y"
}

# 5908 "y.tab.c"
break ;
case 303 :
# 2512 "gram.y"
{ goto binop ;

# 2512 "gram.y"
}

# 5913 "y.tab.c"
break ;
case 304 :
# 2513 "gram.y"
{ goto binop ;

# 2513 "gram.y"
}

# 5918 "y.tab.c"
break ;
case 305 :
# 2514 "gram.y"
{ goto binop ;

# 2514 "gram.y"
}

# 5923 "y.tab.c"
break ;
case 306 :
# 2515 "gram.y"
{ goto binop ;

# 2515 "gram.y"
}

# 5928 "y.tab.c"
break ;
case 307 :
# 2516 "gram.y"
{ goto binop ;

# 2516 "gram.y"
}

# 5933 "y.tab.c"
break ;
case 308 :
# 2517 "gram.y"
{ goto binop ;

# 2517 "gram.y"
}

# 5938 "y.tab.c"
break ;
case 309 :
# 2518 "gram.y"
{ goto binop ;

# 2518 "gram.y"
}

# 5943 "y.tab.c"
break ;
case 310 :
# 2519 "gram.y"
{ goto binop ;

# 2519 "gram.y"
}

# 5948 "y.tab.c"
break ;
case 311 :
# 2520 "gram.y"
{ goto binop ;

# 2520 "gram.y"
}

# 5953 "y.tab.c"
break ;
case 312 :
# 2521 "gram.y"
{ goto binop ;

# 2521 "gram.y"
}

# 5958 "y.tab.c"
break ;
case 313 :
# 2523 "gram.y"
{ 
# 2523 "gram.y"
struct qexpr *__0__X243 ;

# 2523 "gram.y"
struct expr *__2__X244 ;

# 2523 "gram.y"
struct expr *__2__X245 ;

# 2523 "gram.y"
struct expr *__2__X246 ;

# 2523 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X243 = 0 ), ( (__2__X244 = (yystack . l_mark__11YYSTACKDATA [-4]). pe__7YYSTYPE ), ( (__2__X245 = (yystack .
# 2523 "gram.y"
l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ), ( (__2__X246 = (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ), ( ((__0__X243 || (__0__X243 = (struct qexpr *)__nw__4exprSFUl ( (unsigned long
# 2523 "gram.y"
)(sizeof (struct qexpr))) ))?( (__0__X243 = (struct qexpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X243 ), (unsigned char )68 , __2__X245 , __2__X246 ) ),
# 2523 "gram.y"
(__0__X243 -> __O4__4expr.cond = __2__X244 )) :0 ), __0__X243 ) ) ) ) ) ;

# 2523 "gram.y"
}

# 5963 "y.tab.c"
break ;
case 314 :
# 2525 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ,
# 2525 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ) ;

# 2525 "gram.y"
}

# 5968 "y.tab.c"
break ;
case 315 :
# 2527 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )9 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ,
# 2527 "gram.y"
(struct expr *)0 ) ;

# 2527 "gram.y"
}

# 5973 "y.tab.c"
break ;
case 316 :
# 2529 "gram.y"
{ 
# 2530 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE != dummy ){ 
# 2531 "gram.y"
if (warning_opt || strict_opt )
# 2532 "gram.y"
error__FiPCc ( strict_opt ?0 :119, (const char *)"v in `delete[v]' is redundant; use `delete[] instead (anachronism)")
# 2532 "gram.y"
;
}
yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )9 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]).
# 2534 "gram.y"
pe__7YYSTYPE ) ;
}

# 5984 "y.tab.c"
break ;
case 317 :
# 2537 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )188 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ,
# 2537 "gram.y"
(struct expr *)0 ) ;

# 2537 "gram.y"
}

# 5989 "y.tab.c"
break ;
case 318 :
# 2539 "gram.y"
{ 
# 2540 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE != dummy ){ 
# 2541 "gram.y"
if (warning_opt || strict_opt )
# 2542 "gram.y"
error__FiPCc ( strict_opt ?0 :119, (const char *)"v in `::delete[v]' is redundant; use `::delete[] instead (anachronism)")
# 2542 "gram.y"
;
}
yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )9 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-2]).
# 2544 "gram.y"
pe__7YYSTYPE ) ;
}

# 6000 "y.tab.c"
break ;
case 319 :
# 2546 "gram.y"
{ 
# 2547 "gram.y"
init_seen = 0 ;
}

# 6007 "y.tab.c"
break ;
case 320 :
# 2550 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )99 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE , (struct expr *)0 ) ;

# 2550 "gram.y"
}

# 6012 "y.tab.c"
break ;
case 321 :
# 2552 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)dummy ;

# 2552 "gram.y"
}

# 6017 "y.tab.c"
break ;
case 322 :
# 2555 "gram.y"
{ goto new1 ;

# 2555 "gram.y"
}

# 6022 "y.tab.c"
break ;
case 323 :
# 2557 "gram.y"
{ new1 :
# 2558 "gram.y"
{ Ptype __3t ;

# 2559 "gram.y"
struct texpr *__0__X247 ;

# 2558 "gram.y"
__3t = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X247 = 0 ), ( ((__0__X247 || (__0__X247 = (struct texpr *)__nw__4exprSFUl ( (size_t)(sizeof
# 2559 "gram.y"
(struct texpr))) ))?( (__0__X247 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X247 ), ((unsigned char )23 ), ((struct expr *)0 ), (struct expr *)0 )
# 2559 "gram.y"
), (__0__X247 -> __O4__4expr.tp2 = __3t )) :0 ), __0__X247 ) ) ;
-- in_new ;

# 2560 "gram.y"
}
}

# 6031 "y.tab.c"
break ;
case 324 :
# 2562 "gram.y"
{ goto new3 ;

# 2562 "gram.y"
}

# 6036 "y.tab.c"
break ;
case 325 :
# 2564 "gram.y"
{ new3 :
# 2565 "gram.y"
{ Ptype __3t ;

# 2566 "gram.y"
struct texpr *__0__X248 ;

# 2565 "gram.y"
__3t = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X248 = 0 ), ( ((__0__X248 || (__0__X248 = (struct texpr *)__nw__4exprSFUl ( (size_t)(sizeof
# 2566 "gram.y"
(struct texpr))) ))?( (__0__X248 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X248 ), ((unsigned char )184 ), ((struct expr *)0 ), (struct expr *)0 )
# 2566 "gram.y"
), (__0__X248 -> __O4__4expr.tp2 = __3t )) :0 ), __0__X248 ) ) ;
-- in_new ;

# 2567 "gram.y"
}
}

# 6045 "y.tab.c"
break ;
case 326 :
# 2570 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ,
# 2570 "gram.y"
(struct expr *)0 ) ;

# 2570 "gram.y"
}

# 6050 "y.tab.c"
break ;
case 327 :
# 2572 "gram.y"
{ 
# 2572 "gram.y"
struct texpr *__0__X249 ;

# 2572 "gram.y"
struct type *__2__X250 ;

# 2572 "gram.y"
struct expr *__2__X251 ;

# 2573 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X249 = 0 ), ( (__2__X250 = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> __O1__4expr.tp ), ( (__2__X251 =
# 2573 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ), ( ((__0__X249 || (__0__X249 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X249 =
# 2573 "gram.y"
(struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X249 ), ((unsigned char )113 ), __2__X251 , (struct expr *)0 ) ), (__0__X249 -> __O4__4expr.tp2 = __2__X250 ))
# 2573 "gram.y"
:0 ), __0__X249 ) ) ) ) ;
}

# 6057 "y.tab.c"
break ;
case 328 :
# 2576 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ,
# 2576 "gram.y"
(struct expr *)0 ) ;

# 2576 "gram.y"
}

# 6062 "y.tab.c"
break ;
case 329 :
# 2578 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )112 , (struct expr *)0 , (yystack .
# 2578 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ) ;

# 2578 "gram.y"
}

# 6067 "y.tab.c"
break ;
case 330 :
# 2580 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )107 , (struct expr *)0 , (yystack .
# 2580 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ) ;

# 2580 "gram.y"
}

# 6072 "y.tab.c"
break ;
case 331 :
# 2582 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )172 , (struct expr *)0 , (yystack .
# 2582 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ) ;

# 2582 "gram.y"
}

# 6077 "y.tab.c"
break ;
case 332 :
# 2584 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )46 , (struct expr *)0 , (yystack .
# 2584 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ) ;

# 2584 "gram.y"
}

# 6082 "y.tab.c"
break ;
case 333 :
# 2586 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )47 , (struct expr *)0 , (yystack .
# 2586 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ) ;

# 2586 "gram.y"
}

# 6087 "y.tab.c"
break ;
case 334 :
# 2588 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (yystack . l_mark__11YYSTACKDATA [-1]). t__7YYSTYPE , (struct expr *)0 , (yystack .
# 2588 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ) ;

# 2588 "gram.y"
}

# 6092 "y.tab.c"
break ;
case 335 :
# 2590 "gram.y"
{ 
# 2590 "gram.y"
struct texpr *__0__X252 ;

# 2590 "gram.y"
struct expr *__2__X253 ;

# 2591 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X252 = 0 ), ( (__2__X253 = (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ), ( ((__0__X252 || (__0__X252 =
# 2591 "gram.y"
(struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X252 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X252 ), ((unsigned char
# 2591 "gram.y"
)30 ), __2__X253 , (struct expr *)0 ) ), (__0__X252 -> __O4__4expr.tp2 = ((struct type *)0 ))) :0 ), __0__X252 ) ) ) ;
# 2591 "gram.y"

# 2592 "gram.y"
-- in_sizeof ;
}

# 6100 "y.tab.c"
break ;
case 336 :
# 2595 "gram.y"
{ 
# 2595 "gram.y"
struct texpr *__0__X254 ;

# 2595 "gram.y"
struct type *__2__X255 ;

# 2596 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X254 = 0 ), ( (__2__X255 = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ), ( ((__0__X254 ||
# 2596 "gram.y"
(__0__X254 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X254 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X254 ), ((unsigned
# 2596 "gram.y"
char )30 ), ((struct expr *)0 ), (struct expr *)0 ) ), (__0__X254 -> __O4__4expr.tp2 = __2__X255 )) :0 ), __0__X254 ) ) )
# 2596 "gram.y"
;
-- in_sizeof ;
}

# 6108 "y.tab.c"
break ;
case 337 :
# 2600 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , (yystack . l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ,
# 2600 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ) ;

# 2600 "gram.y"
}

# 6113 "y.tab.c"
break ;
case 338 :
# 2602 "gram.y"
{ 
# 2602 "gram.y"
struct ref *__0__X256 ;

# 2602 "gram.y"
struct expr *__2__X257 ;

# 2602 "gram.y"
struct expr *__2__X258 ;

# 2602 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X256 = 0 ), ( (__2__X257 = (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ), ( (__2__X258 = (struct
# 2602 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X256 || (__0__X256 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X256 =
# 2602 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X256 ), ((unsigned char )44 ), __2__X257 , (struct expr *)0 ) ), (__0__X256 -> __O4__4expr.mem = __2__X258 ))
# 2602 "gram.y"
:0 ), __0__X256 ) ) ) ) ;

# 2602 "gram.y"
}

# 6118 "y.tab.c"
break ;
case 339 :
# 2604 "gram.y"
{ 
# 2604 "gram.y"
struct ref *__0__X259 ;

# 2604 "gram.y"
struct expr *__2__X260 ;

# 2604 "gram.y"
struct expr *__2__X261 ;

# 2605 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X259 = 0 ), ( (__2__X260 = (yystack . l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ), ( (__2__X261 = (struct
# 2606 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X259 || (__0__X259 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X259 =
# 2606 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X259 ), ((unsigned char )44 ), __2__X260 , (struct expr *)0 ) ), (__0__X259 -> __O4__4expr.mem = __2__X261 ))
# 2606 "gram.y"
:0 ), __0__X259 ) ) ) ) ;
}

# 6126 "y.tab.c"
break ;
case 340 :
# 2609 "gram.y"
{ 
# 2609 "gram.y"
struct ref *__0__X262 ;

# 2609 "gram.y"
struct expr *__2__X263 ;

# 2609 "gram.y"
struct expr *__2__X264 ;

# 2609 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4expr.string ) ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X262 = 0 ), ( (__2__X263 = (yystack . l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ), ( (__2__X264 = (struct
# 2611 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X262 || (__0__X262 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X262 =
# 2611 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X262 ), ((unsigned char )44 ), __2__X263 , (struct expr *)0 ) ), (__0__X262 -> __O4__4expr.mem = __2__X264 ))
# 2611 "gram.y"
:0 ), __0__X262 ) ) ) ) ;
}

# 6134 "y.tab.c"
break ;
case 341 :
# 2614 "gram.y"
{ 
# 2614 "gram.y"
struct ref *__0__X265 ;

# 2614 "gram.y"
struct expr *__2__X266 ;

# 2614 "gram.y"
struct expr *__2__X267 ;

# 2614 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X265 = 0 ), ( (__2__X266 = (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ), ( (__2__X267 = (struct
# 2614 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X265 || (__0__X265 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X265 =
# 2614 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X265 ), ((unsigned char )44 ), __2__X266 , (struct expr *)0 ) ), (__0__X265 -> __O4__4expr.mem = __2__X267 ))
# 2614 "gram.y"
:0 ), __0__X265 ) ) ) ) ;

# 2614 "gram.y"
}

# 6139 "y.tab.c"
break ;
case 342 :
# 2616 "gram.y"
{ 
# 2616 "gram.y"
struct ref *__0__X268 ;

# 2616 "gram.y"
struct expr *__2__X269 ;

# 2616 "gram.y"
struct expr *__2__X270 ;

# 2618 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X268 = 0 ), ( (__2__X269 = (yystack . l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ), ( (__2__X270 = (struct
# 2619 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X268 || (__0__X268 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X268 =
# 2619 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X268 ), ((unsigned char )44 ), __2__X269 , (struct expr *)0 ) ), (__0__X268 -> __O4__4expr.mem = __2__X270 ))
# 2619 "gram.y"
:0 ), __0__X268 ) ) ) ) ;
if ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE && ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> n_template_arg__4name != 1))
# 2621 "gram.y"
UNSET_SCOPE__Fv ( ) ;
}

# 6150 "y.tab.c"
break ;
case 343 :
# 2624 "gram.y"
{ 
# 2624 "gram.y"
struct ref *__0__X271 ;

# 2624 "gram.y"
struct expr *__2__X272 ;

# 2624 "gram.y"
struct expr *__2__X273 ;

# 2626 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4expr.string ) ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X271 = 0 ), ( (__2__X272 = (yystack . l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ), ( (__2__X273 = (struct
# 2628 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X271 || (__0__X271 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X271 =
# 2628 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X271 ), ((unsigned char )44 ), __2__X272 , (struct expr *)0 ) ), (__0__X271 -> __O4__4expr.mem = __2__X273 ))
# 2628 "gram.y"
:0 ), __0__X271 ) ) ) ) ;
if ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE && ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> n_template_arg__4name != 1))
# 2630 "gram.y"
UNSET_SCOPE__Fv ( ) ;
}

# 6162 "y.tab.c"
break ;
case 344 :
# 2633 "gram.y"
{ 
# 2633 "gram.y"
struct ref *__0__X274 ;

# 2633 "gram.y"
struct expr *__2__X275 ;

# 2633 "gram.y"
struct expr *__2__X276 ;

# 2633 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X274 = 0 ), ( (__2__X275 = (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ), ( (__2__X276 = (struct
# 2633 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X274 || (__0__X274 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X274 =
# 2633 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X274 ), ((unsigned char )45 ), __2__X275 , (struct expr *)0 ) ), (__0__X274 -> __O4__4expr.mem = __2__X276 ))
# 2633 "gram.y"
:0 ), __0__X274 ) ) ) ) ;

# 2633 "gram.y"
}

# 6167 "y.tab.c"
break ;
case 345 :
# 2635 "gram.y"
{ 
# 2635 "gram.y"
struct ref *__0__X277 ;

# 2635 "gram.y"
struct expr *__2__X278 ;

# 2635 "gram.y"
struct expr *__2__X279 ;

# 2636 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X277 = 0 ), ( (__2__X278 = (yystack . l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ), ( (__2__X279 = (struct
# 2637 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X277 || (__0__X277 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X277 =
# 2637 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X277 ), ((unsigned char )45 ), __2__X278 , (struct expr *)0 ) ), (__0__X277 -> __O4__4expr.mem = __2__X279 ))
# 2637 "gram.y"
:0 ), __0__X277 ) ) ) ) ;
}

# 6175 "y.tab.c"
break ;
case 346 :
# 2640 "gram.y"
{ 
# 2640 "gram.y"
struct ref *__0__X280 ;

# 2640 "gram.y"
struct expr *__2__X281 ;

# 2640 "gram.y"
struct expr *__2__X282 ;

# 2640 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4expr.string ) ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X280 = 0 ), ( (__2__X281 = (yystack . l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ), ( (__2__X282 = (struct
# 2642 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X280 || (__0__X280 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X280 =
# 2642 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X280 ), ((unsigned char )45 ), __2__X281 , (struct expr *)0 ) ), (__0__X280 -> __O4__4expr.mem = __2__X282 ))
# 2642 "gram.y"
:0 ), __0__X280 ) ) ) ) ;
}

# 6183 "y.tab.c"
break ;
case 347 :
# 2645 "gram.y"
{ 
# 2645 "gram.y"
struct ref *__0__X283 ;

# 2645 "gram.y"
struct expr *__2__X284 ;

# 2645 "gram.y"
struct expr *__2__X285 ;

# 2645 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X283 = 0 ), ( (__2__X284 = (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ), ( (__2__X285 = (struct
# 2645 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X283 || (__0__X283 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X283 =
# 2645 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X283 ), ((unsigned char )45 ), __2__X284 , (struct expr *)0 ) ), (__0__X283 -> __O4__4expr.mem = __2__X285 ))
# 2645 "gram.y"
:0 ), __0__X283 ) ) ) ) ;

# 2645 "gram.y"
}

# 6188 "y.tab.c"
break ;
case 348 :
# 2647 "gram.y"
{ 
# 2647 "gram.y"
struct ref *__0__X286 ;

# 2647 "gram.y"
struct expr *__2__X287 ;

# 2647 "gram.y"
struct expr *__2__X288 ;

# 2649 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X286 = 0 ), ( (__2__X287 = (yystack . l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ), ( (__2__X288 = (struct
# 2650 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X286 || (__0__X286 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X286 =
# 2650 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X286 ), ((unsigned char )45 ), __2__X287 , (struct expr *)0 ) ), (__0__X286 -> __O4__4expr.mem = __2__X288 ))
# 2650 "gram.y"
:0 ), __0__X286 ) ) ) ) ;
if ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE && ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> n_template_arg__4name != 1))
# 2652 "gram.y"
UNSET_SCOPE__Fv ( ) ;
}

# 6199 "y.tab.c"
break ;
case 349 :
# 2655 "gram.y"
{ 
# 2655 "gram.y"
struct ref *__0__X289 ;

# 2655 "gram.y"
struct expr *__2__X290 ;

# 2655 "gram.y"
struct expr *__2__X291 ;

# 2657 "gram.y"
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4expr.string ) ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X289 = 0 ), ( (__2__X290 = (yystack . l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ), ( (__2__X291 = (struct
# 2659 "gram.y"
expr *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__0__X289 || (__0__X289 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X289 =
# 2659 "gram.y"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X289 ), ((unsigned char )45 ), __2__X290 , (struct expr *)0 ) ), (__0__X289 -> __O4__4expr.mem = __2__X291 ))
# 2659 "gram.y"
:0 ), __0__X289 ) ) ) ) ;
if ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE && ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> n_template_arg__4name != 1))
# 2661 "gram.y"
UNSET_SCOPE__Fv ( ) ;
}

# 6211 "y.tab.c"
break ;
case 351 :
# 2665 "gram.y"
{ 
# 2665 "gram.y"
struct name *__1__X292 ;

# 2665 "gram.y"
struct name *__1__Xnn00qycjpkkfwcaj ;

# 2669 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__1__X292 = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((__1__X292 -> base__4node != 123 )?( (__1__Xnn00qycjpkkfwcaj = __1__X292 ),
# 2669 "gram.y"
0 ) :( (__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc ( (struct name *)0 , __1__X292 -> __O2__4expr.string ) ), (__1__Xnn00qycjpkkfwcaj -> n_template_arg__4name = __1__X292 -> n_template_arg__4name )) ),
# 2669 "gram.y"
__1__Xnn00qycjpkkfwcaj ) ) ;
yyval . pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
if ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE && ((yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE -> n_template_arg__4name != 1))
# 2672 "gram.y"
UNSET_SCOPE__Fv ( ) ;
}

# 6224 "y.tab.c"
break ;
case 352 :
# 2675 "gram.y"
{ 
# 2676 "gram.y"
yyval . p__7YYSTYPE = (struct node *)dummy_dtor__Fv ( ) ;
yyval . pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
yyval . pn__7YYSTYPE -> __O1__4name.n_dtag = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 6233 "y.tab.c"
break ;
case 353 :
# 2681 "gram.y"
{ 
# 2682 "gram.y"
yyval . p__7YYSTYPE = (struct node *)dummy_dtor__FUcT1 ( (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ;
yyval . pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
}

# 6241 "y.tab.c"
break ;
case 354 :
# 2686 "gram.y"
{ 
# 2687 "gram.y"
if (init_seen )
# 2688 "gram.y"
error__FPCc ( (const char *)"syntax error:IrL illegal within ()") ;
}

# 6249 "y.tab.c"
break ;
case 355 :
# 2692 "gram.y"
{ 
# 2693 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE == (((struct node *)dummy )))
# 2694 "gram.y"
error__FPCc ( (const char *)"syntax error: nullE")
# 2694 "gram.y"
;
yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ;
}

# 6258 "y.tab.c"
break ;
case 356 :
# 2698 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)zero ;

# 2698 "gram.y"
}

# 6263 "y.tab.c"
break ;
case 357 :
# 2700 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )82 , (struct expr *)0 , (struct
# 2700 "gram.y"
expr *)0 ) ;
yyval . pe__7YYSTYPE -> __O2__4expr.string = ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation )?(((const char *)strdup ( (yystack . l_mark__11YYSTACKDATA [0 ]). s__7YYSTYPE ) )):(yystack . l_mark__11YYSTACKDATA [0 ]). s__7YYSTYPE );
}

# 6270 "y.tab.c"
break ;
case 358 :
# 2704 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )83 , (struct expr *)0 , (struct
# 2704 "gram.y"
expr *)0 ) ;
yyval . pe__7YYSTYPE -> __O2__4expr.string = ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation )?(((const char *)strdup ( (yystack . l_mark__11YYSTACKDATA [0 ]). s__7YYSTYPE ) )):(yystack . l_mark__11YYSTACKDATA [0 ]). s__7YYSTYPE );
}

# 6277 "y.tab.c"
break ;
case 359 :
# 2708 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )81 , (struct expr *)0 , (struct
# 2708 "gram.y"
expr *)0 ) ;
yyval . pe__7YYSTYPE -> __O2__4expr.string = ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation )?(((const char *)strdup ( (yystack . l_mark__11YYSTACKDATA [0 ]). s__7YYSTYPE ) )):(yystack . l_mark__11YYSTACKDATA [0 ]). s__7YYSTYPE );
}

# 6284 "y.tab.c"
break ;
case 360 :
# 2712 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )84 , (struct expr *)0 , (struct
# 2712 "gram.y"
expr *)0 ) ;
yyval . pe__7YYSTYPE -> __O2__4expr.string = ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation )?(((const char *)strdup ( (yystack . l_mark__11YYSTACKDATA [0 ]). s__7YYSTYPE ) )):(yystack . l_mark__11YYSTACKDATA [0 ]). s__7YYSTYPE );
}

# 6291 "y.tab.c"
break ;
case 361 :
# 2716 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )34 , (struct expr *)0 , (struct
# 2716 "gram.y"
expr *)0 ) ;

# 2716 "gram.y"
}

# 6296 "y.tab.c"
break ;
case 362 :
# 2720 "gram.y"
{ 
# 2721 "gram.y"
yyval . p__7YYSTYPE = (struct node *)dummy_dtor__Fv ( ) ;
yyval . pn__7YYSTYPE -> __O1__4name.n_dtag = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 6304 "y.tab.c"
break ;
case 363 :
# 2725 "gram.y"
{ 
# 2726 "gram.y"
yyval . p__7YYSTYPE = (struct node *)dummy_dtor__Fv ( ) ;
yyval . pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
yyval . pn__7YYSTYPE -> __O1__4name.n_dtag = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 6313 "y.tab.c"
break ;
case 364 :
# 2731 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)dummy_dtor__FUcT1 ( (yystack . l_mark__11YYSTACKDATA [-3]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ;

# 2731 "gram.y"
}

# 6318 "y.tab.c"
break ;
case 365 :
# 2733 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)dummy_dtor__FUcT1 ( (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ;

# 2733 "gram.y"
}

# 6323 "y.tab.c"
break ;
case 366 :
# 2735 "gram.y"
{ 
# 2736 "gram.y"
yyval . p__7YYSTYPE = (struct node *)dummy_dtor__FUcT1 ( (yystack . l_mark__11YYSTACKDATA [-3]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [-3]). t__7YYSTYPE ) ;
yyval . pn__7YYSTYPE -> __O1__4name.n_dtag = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 6331 "y.tab.c"
break ;
case 367 :
# 2740 "gram.y"
{ 
# 2741 "gram.y"
yyval . p__7YYSTYPE = (struct node *)dummy_dtor__FUcT1 ( (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ;
yyval . pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
}

# 6339 "y.tab.c"
break ;
case 368 :
# 2745 "gram.y"
{ 
# 2746 "gram.y"
yyval . p__7YYSTYPE = (struct node *)dummy_dtor__Fv ( ) ;
yyval . pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
yyval . pn__7YYSTYPE -> __O1__4name.n_dtag = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 6348 "y.tab.c"
break ;
case 369 :
# 2751 "gram.y"
{ 
# 2752 "gram.y"
yyval . p__7YYSTYPE = (struct node *)dummy_dtor__FUcT1 ( (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ;
yyval . pn__7YYSTYPE -> __O2__4name.n_qualifier = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
}

# 6356 "y.tab.c"
break ;
case 370 :
# 2758 "gram.y"
{ 
# 2758 "gram.y"
struct texpr *__0__X293 ;

# 2758 "gram.y"
struct type *__2__X294 ;

# 2758 "gram.y"
struct expr *__2__X295 ;

# 2758 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X293 = 0 ), ( (__2__X294 = tok_to_type__FUc ( (yystack . l_mark__11YYSTACKDATA [-3]). t__7YYSTYPE ) ), (
# 2758 "gram.y"
(__2__X295 = (yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ), ( ((__0__X293 || (__0__X293 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?(
# 2758 "gram.y"
(__0__X293 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X293 ), ((unsigned char )157 ), __2__X295 , (struct expr *)0 ) ), (__0__X293 -> __O4__4expr.tp2 =
# 2758 "gram.y"
__2__X294 )) :0 ), __0__X293 ) ) ) ) ;

# 2758 "gram.y"
}

# 6361 "y.tab.c"
break ;
case 371 :
# 2763 "gram.y"
{ 
# 2763 "gram.y"
struct texpr *__0__X296 ;

# 2763 "gram.y"
struct type *__2__X297 ;

# 2763 "gram.y"
struct expr *__2__X298 ;

# 2763 "gram.y"
struct name *__0__X299 ;

# 2764 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X296 = 0 ), ( (__2__X297 = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O1__4expr.tp ), ( (__2__X298 =
# 2764 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ), ( ((__0__X296 || (__0__X296 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X296 =
# 2764 "gram.y"
(struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X296 ), ((unsigned char )157 ), __2__X298 , (struct expr *)0 ) ), (__0__X296 -> __O4__4expr.tp2 = __2__X297 ))
# 2764 "gram.y"
:0 ), __0__X296 ) ) ) ) ;
if (( (__0__X299 = (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ), ( (((unsigned char )(__0__X299 -> n_template_arg__4name == 1)))) ) &&
# 2765 "gram.y"
((yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE -> __O1__4expr.tp -> base__4node == 141 )){ 
# 2766 "gram.y"
yyval . pe__7YYSTYPE -> __O4__4expr.tp2 = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned
# 2766 "gram.y"
char )97 , (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE ) ;
}
}

# 6371 "y.tab.c"
break ;
case 372 :
# 2769 "gram.y"
{ goto new2 ;

# 2769 "gram.y"
}

# 6376 "y.tab.c"
break ;
case 373 :
# 2771 "gram.y"
{ new2 :
# 2772 "gram.y"
{ Ptype __3t ;

# 2773 "gram.y"
struct texpr *__0__X300 ;

# 2772 "gram.y"
__3t = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X300 = 0 ), ( ((__0__X300 || (__0__X300 = (struct texpr *)__nw__4exprSFUl ( (size_t)(sizeof
# 2773 "gram.y"
(struct texpr))) ))?( (__0__X300 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X300 ), ((unsigned char )23 ), ((struct expr *)0 ), (struct expr *)0 )
# 2773 "gram.y"
), (__0__X300 -> __O4__4expr.tp2 = __3t )) :0 ), __0__X300 ) ) ;
yyval . pe__7YYSTYPE -> __O3__4expr.e2 = (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ;
-- in_new ;

# 2775 "gram.y"
}
}

# 6386 "y.tab.c"
break ;
case 374 :
# 2777 "gram.y"
{ goto new4 ;

# 2777 "gram.y"
}

# 6391 "y.tab.c"
break ;
case 375 :
# 2779 "gram.y"
{ new4 :
# 2780 "gram.y"
{ Ptype __3t ;

# 2781 "gram.y"
struct texpr *__0__X301 ;

# 2780 "gram.y"
__3t = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O1__4expr.tp ;
yyval . p__7YYSTYPE = (struct node *)( (__0__X301 = 0 ), ( ((__0__X301 || (__0__X301 = (struct texpr *)__nw__4exprSFUl ( (size_t)(sizeof
# 2781 "gram.y"
(struct texpr))) ))?( (__0__X301 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X301 ), ((unsigned char )184 ), ((struct expr *)0 ), (struct expr *)0 )
# 2781 "gram.y"
), (__0__X301 -> __O4__4expr.tp2 = __3t )) :0 ), __0__X301 ) ) ;
yyval . pe__7YYSTYPE -> __O3__4expr.e2 = (yystack . l_mark__11YYSTACKDATA [-2]). pe__7YYSTYPE ;
-- in_new ;

# 2783 "gram.y"
}
}

# 6401 "y.tab.c"
break ;
case 376 :
# 2786 "gram.y"
{ 
# 2787 "gram.y"
Pexpr __3ee ;
Pexpr __3e ;

# 2789 "gram.y"
struct call *__0__X302 ;

# 2789 "gram.y"
struct expr *__2__X303 ;

# 2789 "gram.y"
struct expr *__2__X304 ;

# 2787 "gram.y"
__3ee = (yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE ;
__3e = (yystack . l_mark__11YYSTACKDATA [-3]). pe__7YYSTYPE ;
if ((__3e -> base__4node == 23 )|| (__3e -> base__4node == 184 ))
# 2790 "gram.y"
__3e -> __O2__4expr.e1 = __3ee ;
else 
# 2792 "gram.y"
yyval . p__7YYSTYPE = (struct node *)( (__0__X302 = 0 ), ( (__2__X303 = __3e ), ( (__2__X304 = __3ee ), (
# 2792 "gram.y"
((__0__X302 || (__0__X302 = (struct call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X302 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X302 ), (unsigned
# 2792 "gram.y"
char )109 , __2__X303 , __2__X304 ) ):0 ), __0__X302 ) ) ) ) ;
}

# 6413 "y.tab.c"
break ;
case 377 :
# 2798 "gram.y"
{ 
# 2799 "gram.y"
yyval . pn__7YYSTYPE = parametrized_typename__FP4nameP4exprUc ( (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE , expr_unlist__FP5elist ( (yystack . l_mark__11YYSTACKDATA [-1]). el__7YYSTYPE ) , (unsigned
# 2799 "gram.y"
char )0 ) ;
}

# 6420 "y.tab.c"
break ;
case 378 :
# 2803 "gram.y"
{ yyval . pn__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;

# 2803 "gram.y"
}

# 6425 "y.tab.c"
break ;
case 379 :
# 2804 "gram.y"
{ yyval . pn__7YYSTYPE = sta_name ;

# 2804 "gram.y"
}

# 6430 "y.tab.c"
break ;
case 380 :
# 2805 "gram.y"
{ yyval . pn__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;

# 2805 "gram.y"
}

# 6435 "y.tab.c"
break ;
case 381 :
# 2810 "gram.y"
{ 
# 2811 "gram.y"
if (in_arg_list && (! in_binit_list )){ 
# 2812 "gram.y"
Pktab __4tb ;

# 2812 "gram.y"
__4tb = Ctbl ;
for(;__4tb && (__4tb -> k_id__6ktable == 136 );__4tb = __4tb -> k_next__6ktable ) { 
# 2814 "gram.y"
if (look__6ktableFPCcUc ( __4tb , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE -> __O2__4expr.string ,
# 2814 "gram.y"
(unsigned char )0 ) ){ 
# 2814 "gram.y"
const void *__2__X305 ;

# 2815 "gram.y"
{ 
# 2815 "gram.y"
struct ea __0__V98 ;

# 2815 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"illegalR toA%n in defaultA", (const struct ea *)( (__2__X305 = (const void
# 2815 "gram.y"
*)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ((& __0__V98 )-> __O1__2ea.p = __2__X305 ), (& __0__V98 )) ) , (const struct
# 2815 "gram.y"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
(yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE = dummy ;
break ;
} }
}
}
yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
}

# 6452 "y.tab.c"
break ;
case 382 :
# 2824 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__4nameFPCc ( (struct name *)0 , oper_name__FUc ( (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ) ;
# 2824 "gram.y"

# 2825 "gram.y"
yyval . pn__7YYSTYPE -> n_oper__4name = (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ;
}

# 6459 "y.tab.c"
break ;
case 383 :
# 2828 "gram.y"
{ yyval . p__7YYSTYPE = (yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE ;
sig_name__FP4name ( yyval . pn__7YYSTYPE ) ;
}

# 6466 "y.tab.c"
break ;
case 384 :
# 2837 "gram.y"
{ 
# 2838 "gram.y"
yyval . p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-2]). p__7YYSTYPE ))),
# 2838 "gram.y"
(struct block *)0 , (unsigned char )1 ) ;
}

# 6473 "y.tab.c"
break ;
case 385 :
# 2842 "gram.y"
{ check_cast__Fv ( ) ;

# 2842 "gram.y"
}

# 6478 "y.tab.c"
break ;
case 386 :
# 2846 "gram.y"
{ 
# 2847 "gram.y"
TOK __3t ;

# 2847 "gram.y"
__3t = (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ;

# 2849 "gram.y"
switch (__3t ){ 
# 2850 "gram.y"
case 18 :
# 2851 "gram.y"
case 76 :
# 2852 "gram.y"
case 27 :
# 2853 "gram.y"
case 31 :
# 2854 "gram.y"
case 14 :
# 2855 "gram.y"
case 2 :
# 2856 "gram.y"
case 77 :
# 2857 "gram.y"
{ 
# 2857 "gram.y"
struct ea __0__V99 ;

# 2857 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"%k in operatorT", (const struct ea *)( (( ((& __0__V99 )->
# 2857 "gram.y"
__O1__2ea.i = ((unsigned long )__3t )), 0 ) ), (& __0__V99 )) , (const struct ea *)ea0 , (const struct
# 2857 "gram.y"
ea *)ea0 , (const struct ea *)ea0 ) ;
__3t = 21 ;
} 
# 2860 "gram.y"
}

# 2862 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , __3t , (struct name *)0 ) ;

# 2864 "gram.y"
}

# 6501 "y.tab.c"
break ;
case 387 :
# 2865 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )97 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE )
# 2865 "gram.y"
;

# 2865 "gram.y"
}

# 6506 "y.tab.c"
break ;
case 388 :
# 2867 "gram.y"
{ 
# 2868 "gram.y"
if (DECL_TYPE != -1){ 
# 2869 "gram.y"
switch ((yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE -> base__4node ){ 
# 2870 "gram.y"
case 119 :case 121 :
# 2871 "gram.y"
{ 
# 2872 "gram.y"
Pbase __6bt ;
# 2872 "gram.y"

# 2873 "gram.y"
__6bt = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )0 , (struct name *)0 ) ;
((*__6bt ))= (*(yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE );
if ((yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE && ((yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE -> permanent__4node == 0 ))del__4typeFv ( (struct type *)(yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE ) ;
# 2875 "gram.y"

# 2876 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE = __6bt ;
}
}
yyval . p__7YYSTYPE = (struct node *)type_adj__8basetypeFUc ( (yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ;
}
DECL_TYPE = 0 ;
}

# 6526 "y.tab.c"
break ;
case 389 :
# 2884 "gram.y"
{ 
# 2885 "gram.y"
if (DECL_TYPE != -1)
# 2886 "gram.y"
yyval . p__7YYSTYPE = (struct node *)name_adj__8basetypeFP4name ( (yystack . l_mark__11YYSTACKDATA [-1]). pb__7YYSTYPE , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE )
# 2886 "gram.y"
;
DECL_TYPE = 0 ;
}

# 6535 "y.tab.c"
break ;
case 390 :
# 2891 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))),
# 2891 "gram.y"
(struct block *)0 , (unsigned char )1 ) ;

# 2891 "gram.y"
}

# 6540 "y.tab.c"
break ;
case 391 :
# 2894 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))),
# 2894 "gram.y"
(struct block *)0 , (unsigned char )1 ) ;

# 2894 "gram.y"
}

# 6545 "y.tab.c"
break ;
case 392 :
# 2897 "gram.y"
{ 
# 2899 "gram.y"
yyval . p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-1]). p__7YYSTYPE ))),
# 2899 "gram.y"
(struct block *)0 , (unsigned char )0 ) ;
}

# 6553 "y.tab.c"
break ;
case 393 :
# 2902 "gram.y"
{ 
# 2904 "gram.y"
}

# 6560 "y.tab.c"
break ;
case 394 :
# 2906 "gram.y"
{ 
# 2907 "gram.y"
yyval . p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc ( (yystack . l_mark__11YYSTACKDATA [-3]). pn__7YYSTYPE , ((struct basetype *)(((struct basetype *)(yystack . l_mark__11YYSTACKDATA [-4]). p__7YYSTYPE ))),
# 2907 "gram.y"
(struct block *)0 , (unsigned char )0 ) ;
yyval . pn__7YYSTYPE -> __O3__4expr.n_initializer = (yystack . l_mark__11YYSTACKDATA [0 ]). pe__7YYSTYPE ;
}

# 6568 "y.tab.c"
break ;
case 395 :
# 2913 "gram.y"
{ ( ( ( (Ctbl = __ct__6ktableFiP6ktableP4name ( (struct ktable *)0 , 0 , Ctbl , (struct name *)0 ) ),
# 2913 "gram.y"
(Ctbl -> k_id__6ktable = 136 )) ) , (((void )0 ))) ;

# 2915 "gram.y"
in_arg_list = 1 ;
check_decl__Fv ( ) ;
yyval . pl__7YYSTYPE = 0 ;

# 2919 "gram.y"
}

# 6579 "y.tab.c"
break ;
case 396 :
# 2923 "gram.y"
{ 
# 2924 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)0 , name_unlist__FP5nlist ( (yystack . l_mark__11YYSTACKDATA [-3]). nl__7YYSTYPE )
# 2924 "gram.y"
, (yystack . l_mark__11YYSTACKDATA [-2]). t__7YYSTYPE ) ;
if (((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar )!= 69 )in_arg_list = 0 ;

# 2927 "gram.y"
(((struct fct *)(((struct fct *)yyval . pt__7YYSTYPE ))))-> f_const__3fct = ((yystack . l_mark__11YYSTACKDATA [0 ]). i__7YYSTYPE & 1 );

# 2929 "gram.y"

# 2929 "gram.y"
{ 
# 2929 "gram.y"
;

# 2929 "gram.y"
if (Ctbl == Gtbl )
# 2929 "gram.y"
error__FiPCc ( (int )'i' , (const char *)"bad parsing table") ;

# 2929 "gram.y"
{ 
# 2929 "gram.y"
Pktab __1b ;

# 2929 "gram.y"
__1b = Ctbl ;

# 2929 "gram.y"
Ctbl = Ctbl -> k_next__6ktable ;

# 2929 "gram.y"
if ((__1b -> k_id__6ktable == 136 )|| 0 )
# 2929 "gram.y"
__dt__6ktableFv ( __1b , 3) ;

# 2929 "gram.y"
}

# 135 "gram.y"
}

# 2931 "gram.y"
}

# 6592 "y.tab.c"
break ;
case 397 :
# 2935 "gram.y"
{ 
# 2935 "gram.y"
register struct nlist *__0__X306 ;

# 2935 "gram.y"
struct name *__2__X307 ;

# 2936 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE )
# 2937 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [-2]). p__7YYSTYPE )
# 2938 "gram.y"
( (__0__X306 = (yystack . l_mark__11YYSTACKDATA [-2]). nl__7YYSTYPE ), ( (__2__X307 = (yystack .
# 2938 "gram.y"
l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ), ( ( (__0__X306 -> tail__5nlist -> __O1__4name.n_list = __2__X307 ), (__0__X306 -> tail__5nlist = __2__X307 )) , (((void )0 )))
# 2938 "gram.y"
) ) ;
else { 
# 2940 "gram.y"
error__FPCc ( (const char *)"AD syntax") ;
yyval . nl__7YYSTYPE = __ct__5nlistFP4name ( (struct nlist *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
}
else 
# 2944 "gram.y"
error__FPCc ( (const char *)"AD syntax") ;
}

# 6607 "y.tab.c"
break ;
case 398 :
# 2947 "gram.y"
{ 
# 2948 "gram.y"
if ((yystack . l_mark__11YYSTACKDATA [0 ]). p__7YYSTYPE )yyval . nl__7YYSTYPE = __ct__5nlistFP4name ( (struct nlist *)0 , (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ) ;
# 2948 "gram.y"

# 2949 "gram.y"
}

# 6614 "y.tab.c"
break ;
case 400 :
# 2953 "gram.y"
{ yyval . p__7YYSTYPE = 0 ;

# 2953 "gram.y"
}

# 6619 "y.tab.c"
break ;
case 401 :
# 2957 "gram.y"
{ yyval . t__7YYSTYPE = 1 ;

# 2957 "gram.y"
}

# 6624 "y.tab.c"
break ;
case 402 :
# 2959 "gram.y"
{ yyval . t__7YYSTYPE = 155 ;

# 2959 "gram.y"
}

# 6629 "y.tab.c"
break ;
case 403 :
# 2961 "gram.y"
{ yyval . t__7YYSTYPE = 155 ;

# 2961 "gram.y"
}

# 6634 "y.tab.c"
break ;
case 404 :
# 2965 "gram.y"
{ 
# 2966 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (struct type *)0 ) ;
# 2966 "gram.y"

# 2967 "gram.y"
must_be_id = 1 ;
}

# 6642 "y.tab.c"
break ;
case 405 :
# 2970 "gram.y"
{ 
# 2971 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )158 , (struct type *)0 ) ;
# 2971 "gram.y"

# 2972 "gram.y"
must_be_id = 1 ;
}

# 6650 "y.tab.c"
break ;
case 406 :
# 2975 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)doptr__FUcT1 ( (unsigned char )125 , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ;

# 2975 "gram.y"
}

# 6655 "y.tab.c"
break ;
case 407 :
# 2977 "gram.y"
{ 
# 2978 "gram.y"
switch ((yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ){ 
# 2978 "gram.y"
unsigned long __2__X308 ;

# 2979 "gram.y"
case 26 :
# 2980 "gram.y"
(yystack . l_mark__11YYSTACKDATA [-1]). pp__7YYSTYPE -> b_const__4type = 1 ;

# 2980 "gram.y"
break ;
case 170 :
# 2982 "gram.y"
error__FiPCc ( (int )'w' , (const char *)"\"volatile\" not implemented (ignored)") ;
break ;
default :
# 2985 "gram.y"
{ 
# 2985 "gram.y"
struct ea __0__V100 ;

# 2985 "gram.y"
error__FPCcRC2eaN32 ( (const char *)"syntax error: *%k", (const struct ea *)( (__2__X308 = (yystack . l_mark__11YYSTACKDATA [0 ]).
# 2985 "gram.y"
t__7YYSTYPE ), ( (( ((& __0__V100 )-> __O1__2ea.i = __2__X308 ), 0 ) ), (& __0__V100 )) ) , (const
# 2985 "gram.y"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
yyval . p__7YYSTYPE = (struct node *)(yystack . l_mark__11YYSTACKDATA [-1]). pp__7YYSTYPE ;
}

# 6671 "y.tab.c"
break ;
case 408 :
# 2990 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)doptr__FUcT1 ( (unsigned char )158 , (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ) ;

# 2990 "gram.y"
}

# 6676 "y.tab.c"
break ;
case 409 :
# 2992 "gram.y"
{ 
# 2993 "gram.y"
memptr_pn = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
memptr_tok = 0 ;
goto memptr1 ;
}

# 6685 "y.tab.c"
break ;
case 410 :
# 2998 "gram.y"
{ 
# 2999 "gram.y"
memptr_pn = (yystack . l_mark__11YYSTACKDATA [0 ]). pn__7YYSTYPE ;
memptr_tok = 0 ;
memptr1 :
# 3002 "gram.y"
if (memptr_tok )
# 3003 "gram.y"
yyval . p__7YYSTYPE = (struct node *)doptr__FUcT1 ( (unsigned char )125 , memptr_tok ) ;
else 
# 3005 "gram.y"
yyval . p__7YYSTYPE = (struct node *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (struct type *)0 ) ;
{ Pname __3n ;

# 3006 "gram.y"
__3n = memptr_pn ;
if (( (((unsigned char )(__3n -> n_template_arg__4name == 1)))) == 0 ){ 
# 3008 "gram.y"
if (skiptypedefs__4typeFv ( __3n -> __O1__4expr.tp ) ->
# 3008 "gram.y"
base__4node != 119 ){ 
# 3009 "gram.y"
yyval . pp__7YYSTYPE -> memof__3ptr = 0 ;
error__FPCc ( (const char *)"P toM of nonCT") ;
}
else yyval . pp__7YYSTYPE -> memof__3ptr = classtype__4typeFv ( skiptypedefs__4typeFv ( __3n -> __O1__4expr.tp ) ) ;
}
else { 
# 3015 "gram.y"
yyval . pp__7YYSTYPE -> memof__3ptr = 0 ;
yyval . pp__7YYSTYPE -> ptname__3ptr = __3n ;
}
must_be_id = 1 ;

# 3018 "gram.y"
}
}

# 6711 "y.tab.c"
break ;
case 411 :
# 3021 "gram.y"
{ 
# 3022 "gram.y"
memptr_pn = (yystack . l_mark__11YYSTACKDATA [-2]). pn__7YYSTYPE ;
memptr_tok = (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ;
goto memptr1 ;
}

# 6720 "y.tab.c"
break ;
case 412 :
# 3027 "gram.y"
{ 
# 3028 "gram.y"
memptr_pn = (yystack . l_mark__11YYSTACKDATA [-1]). pn__7YYSTYPE ;
memptr_tok = (yystack . l_mark__11YYSTACKDATA [0 ]). t__7YYSTYPE ;
goto memptr1 ;
}

# 6729 "y.tab.c"
break ;
case 413 :
# 3034 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__3vecFP4typeP4expr ( (struct vec *)0 , (struct type *)0 , ((yystack . l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE != dummy )?(yystack .
# 3034 "gram.y"
l_mark__11YYSTACKDATA [-1]). pe__7YYSTYPE :(((struct expr *)0 ))) ;

# 3034 "gram.y"
}

# 6734 "y.tab.c"
break ;
case 414 :
# 3035 "gram.y"
{ yyval . p__7YYSTYPE = (struct node *)__ct__3vecFP4typeP4expr ( (struct vec *)0 , (struct type *)0 , (struct expr *)0 ) ;

# 3035 "gram.y"
}

# 6739 "y.tab.c"
break ;

# 6741 "y.tab.c"
}
yystack . s_mark__11YYSTACKDATA -= __1yym ;
__1yystate = ((*yystack . s_mark__11YYSTACKDATA ));
yystack . l_mark__11YYSTACKDATA -= __1yym ;
__1yym = (yylhs [__1yyn ]);
if ((__1yystate == 0 )&& (__1yym == 0 ))
# 6747 "y.tab.c"
{ 
# 6753 "y.tab.c"
__1yystate = 23 ;
((*(++ yystack . s_mark__11YYSTACKDATA )))= 23 ;
((*(++ yystack . l_mark__11YYSTACKDATA )))= yyval ;
if (yychar < 0 )
# 6757 "y.tab.c"
{ 
# 6758 "y.tab.c"
yychar = lalex__Fv ( ) ;
if (yychar < 0 )yychar = 0 ;

# 6768 "y.tab.c"
}
if (yychar == 0 )goto yyaccept ;
goto yyloop ;
}
if (((((__1yyn = (yygindex [__1yym ]))!= 0 )&& ((__1yyn += __1yystate )>= 0 ))&& (__1yyn <= 8259 ))&& ((yycheck [__1yyn ])== (((int )__1yystate ))))
# 6774 "y.tab.c"
__1yystate = (yytable [__1yyn ]);
else 
# 6776 "y.tab.c"
__1yystate = (yydgoto [__1yym ]);

# 6782 "y.tab.c"
if ((yystack . s_mark__11YYSTACKDATA >= yystack . s_last__11YYSTACKDATA )&& (yygrowstack__FP11YYSTACKDATA ( & yystack ) == -2))goto yyoverflow ;
((*(++ yystack . s_mark__11YYSTACKDATA )))= (((int )__1yystate ));
((*(++ yystack . l_mark__11YYSTACKDATA )))= yyval ;
goto yyloop ;

# 6787 "y.tab.c"
yyoverflow :
# 6788 "y.tab.c"
yyerror__FPCc ( (const char *)"yacc stack overflow") ;

# 6790 "y.tab.c"
yyabort :
# 6791 "y.tab.c"
;
return 1 ;

# 6794 "y.tab.c"
yyaccept :
# 6795 "y.tab.c"
;
return 0 ;
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

# 30 "/home/claude/cfront-3/src/tqueue.h"
extern struct toknode *free_toks__7toknode ;

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

# 6797 "y.tab.c"

/* the end */
