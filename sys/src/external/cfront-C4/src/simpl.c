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

# 38 "/home/claude/cfront-3/src/simpl.cpp"
Pname new_fct = 0 ;
Pname del_fct = 0 ;
Pname vec_new_fct = 0 ;
Pname vec_del_fct = 0 ;

# 43 "/home/claude/cfront-3/src/simpl.cpp"
Pstmt del_list = 0 ;
Pstmt break_del_list = 0 ;
Pstmt continue_del_list = 0 ;

# 48 "/home/claude/cfront-3/src/simpl.cpp"
Pname curr_fct = 0 ;
Pexpr init_list = 0 ;
Pexpr one = 0 ;

# 52 "/home/claude/cfront-3/src/simpl.cpp"
Ptype Pfct_type = 0 ;
Ptype Pvptr_type = 0 ;
Pbase mptr_type = 0 ;
Ptype size_t_type = 0 ;

# 61 "/home/claude/cfront-3/src/simpl.cpp"
struct loc no_where = { 0 } ;

# 63 "/home/claude/cfront-3/src/simpl.cpp"
int imeasure = 0 ;

# 66 "/home/claude/cfront-3/src/simpl.cpp"
static Pclass topclass ;

# 68 "/home/claude/cfront-3/src/simpl.cpp"
int replace_ret__FP4stmtiP5table (Pstmt __1sl , int __1level , Ptable __1tbl );

# 37 "/home/claude/cfront-3/src/cfront.h"
extern char *make_name__FUc (TOK );

# 1059 "/home/claude/cfront-3/src/cfront.h"

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1059 "/home/claude/cfront-3/src/cfront.h"

# 68 "/home/claude/cfront-3/src/simpl.cpp"
int replace_ret__FP4stmtiP5table (Pstmt __1sl , int __1level , Ptable __1tbl )
# 69 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 70 "/home/claude/cfront-3/src/simpl.cpp"
int __1nl ;
Pstmt __1ls ;
static char *__1buf ;

# 70 "/home/claude/cfront-3/src/simpl.cpp"
__1nl = 0 ;

# 74 "/home/claude/cfront-3/src/simpl.cpp"
if (! __1level )
# 75 "/home/claude/cfront-3/src/simpl.cpp"
__1buf = 0 ;

# 77 "/home/claude/cfront-3/src/simpl.cpp"
{ { Pstmt __1s ;

# 77 "/home/claude/cfront-3/src/simpl.cpp"
__1s = __1sl ;

# 77 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1s ;( (__1ls = __1s ), (__1s = __1s -> s_list__4stmt )) ) { 
# 78 "/home/claude/cfront-3/src/simpl.cpp"
switch (__1s -> base__4node ){ 
# 79 "/home/claude/cfront-3/src/simpl.cpp"
case 39 :
# 80 "/home/claude/cfront-3/src/simpl.cpp"
case 10 :
# 81 "/home/claude/cfront-3/src/simpl.cpp"
case
# 81 "/home/claude/cfront-3/src/simpl.cpp"
16 :
# 82 "/home/claude/cfront-3/src/simpl.cpp"
case 33 :
# 83 "/home/claude/cfront-3/src/simpl.cpp"
case 116 :
# 84 "/home/claude/cfront-3/src/simpl.cpp"
case 115 :
# 85 "/home/claude/cfront-3/src/simpl.cpp"
case 4 :
# 86 "/home/claude/cfront-3/src/simpl.cpp"
case 8 :
# 87 "/home/claude/cfront-3/src/simpl.cpp"
__1nl += replace_ret__FP4stmtiP5table ( __1s -> s__4stmt , __1level + 1 , __1tbl ) ;
break ;
case 20 :
# 90 "/home/claude/cfront-3/src/simpl.cpp"
__1nl += replace_ret__FP4stmtiP5table ( __1s -> s__4stmt , __1level + 1 , __1tbl ) ;
if (__1s -> __O3__4stmt.else_stmt )
# 92 "/home/claude/cfront-3/src/simpl.cpp"
__1nl += replace_ret__FP4stmtiP5table ( __1s -> __O3__4stmt.else_stmt , __1level + 1 , __1tbl ) ;
break ;
case 166 :
# 95 "/home/claude/cfront-3/src/simpl.cpp"
__1nl += replace_ret__FP4stmtiP5table ( __1s -> s__4stmt , __1level + 1 , __1tbl ) ;
__1nl += replace_ret__FP4stmtiP5table ( __1s -> __O2__4stmt.s2 , __1level + 1 , __1tbl ) ;
break ;
case 28 :{ 
# 99 "/home/claude/cfront-3/src/simpl.cpp"
if (! __1buf )
# 100 "/home/claude/cfront-3/src/simpl.cpp"
__1buf = make_name__FUc ( (unsigned char )'Z' ) ;
{ Pname __4lab ;

# 102 "/home/claude/cfront-3/src/simpl.cpp"
struct lstmt *__0__X17 ;

# 102 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X18 ;

# 101 "/home/claude/cfront-3/src/simpl.cpp"
__4lab = insert__5tableFP4nameUc ( __1tbl , __ct__4nameFPCc ( (struct name *)0 , (const char *)__1buf ) , (unsigned char )115 ) ;
# 101 "/home/claude/cfront-3/src/simpl.cpp"

# 102 "/home/claude/cfront-3/src/simpl.cpp"
__1nl ++ ;
__1s -> gt__4stmt = (struct stmt *)( (__0__X17 = 0 ), ( (__2__X18 = __1s -> where__4stmt ), ( ((__0__X17 || (__0__X17 = (struct
# 103 "/home/claude/cfront-3/src/simpl.cpp"
lstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct lstmt))) ))?( (__0__X17 = (struct lstmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X17 ), ((unsigned char )19 ),
# 103 "/home/claude/cfront-3/src/simpl.cpp"
__2__X18 , ((struct stmt *)0 )) ), (__0__X17 -> __O1__4stmt.d = __4lab )) :0 ), __0__X17 ) ) ) ;
break ;

# 104 "/home/claude/cfront-3/src/simpl.cpp"
}
}
}
}

# 109 "/home/claude/cfront-3/src/simpl.cpp"
if ((! __1level )&& __1nl ){ 
# 110 "/home/claude/cfront-3/src/simpl.cpp"
Pname __2lab ;

# 111 "/home/claude/cfront-3/src/simpl.cpp"
struct estmt *__0__X19 ;

# 111 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X20 ;

# 111 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X21 ;

# 111 "/home/claude/cfront-3/src/simpl.cpp"
struct lstmt *__0__X22 ;

# 111 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X23 ;

# 111 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__2__X24 ;

# 110 "/home/claude/cfront-3/src/simpl.cpp"
__2lab = look__5tableFPCcUc ( __1tbl , (const char *)__1buf , (unsigned char )115 ) ;

# 112 "/home/claude/cfront-3/src/simpl.cpp"
__1ls -> s_list__4stmt = (struct stmt *)( (__0__X22 = 0 ), ( (__2__X23 = curloc ), ( (__2__X24 = (struct stmt *)( (__0__X19 =
# 112 "/home/claude/cfront-3/src/simpl.cpp"
0 ), ( (__2__X20 = curloc ), ( (__2__X21 = dummy ), ( ((__0__X19 || (__0__X19 = (struct estmt *)__nw__4stmtSFUl ( (unsigned long
# 112 "/home/claude/cfront-3/src/simpl.cpp"
)(sizeof (struct estmt))) ))?( (__0__X19 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X19 ), ((unsigned char )72 ), __2__X20 , ((struct stmt *)0 ))
# 112 "/home/claude/cfront-3/src/simpl.cpp"
), (__0__X19 -> __O2__4stmt.e = __2__X21 )) :0 ), __0__X19 ) ) ) ) ), ( ((__0__X22 || (__0__X22 = (struct
# 112 "/home/claude/cfront-3/src/simpl.cpp"
lstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct lstmt))) ))?( (__0__X22 = (struct lstmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X22 ), ((unsigned char )115 ),
# 112 "/home/claude/cfront-3/src/simpl.cpp"
__2__X23 , __2__X24 ) ), (__0__X22 -> __O1__4stmt.d = __2lab )) :0 ), __0__X22 ) ) ) ) ;
}

# 115 "/home/claude/cfront-3/src/simpl.cpp"
return __1nl ;

# 115 "/home/claude/cfront-3/src/simpl.cpp"
}

# 115 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 120 "/home/claude/cfront-3/src/cfront.h"
extern const char *oper_name__FUc (TOK );

# 346 "/home/claude/cfront-3/src/cfront.h"
int tsizeof__4typeFi (struct type *__0this , int );

# 633 "/home/claude/cfront-3/src/cfront.h"
struct fct *__ct__3fctFP4typeP4nameUc (struct fct *__0this , Ptype , Pname , TOK );

# 940 "/home/claude/cfront-3/src/cfront.h"
Pname dcl__4nameFP5tableUc (struct name *__0this , Ptable , TOK );

# 942 "/home/claude/cfront-3/src/cfront.h"

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 942 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 77 "/home/claude/incl-linux32/stdio.h"
extern int fputs (const char *__0s , void *__0stream );

# 443 "/home/claude/cfront-3/src/cfront.h"
struct classdef *__ct__8classdefFUc (struct classdef *__0this , TOK );

# 579 "/home/claude/cfront-3/src/cfront.h"
struct basetype *__ct__8basetypeFUcP4name (struct basetype *__0this , TOK , Pname );

# 715 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 118 "/home/claude/cfront-3/src/simpl.cpp"
void simpl_init__Fv (void )
# 119 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 120 "/home/claude/cfront-3/src/simpl.cpp"
const char *__1ns ;
const char *__1ds ;

# 120 "/home/claude/cfront-3/src/simpl.cpp"
__1ns = oper_name__FUc ( (unsigned char )23 ) ;
__1ds = oper_name__FUc ( (unsigned char )9 ) ;

# 125 "/home/claude/cfront-3/src/simpl.cpp"
size_t_type = (struct type *)((tsizeof__4typeFi ( Pvoid_type , 0 ) > tsizeof__4typeFi ( (struct type *)uint_type , 0 ) )?((tsizeof__4typeFi ( Pvoid_type , 0 ) >
# 125 "/home/claude/cfront-3/src/simpl.cpp"
tsizeof__4typeFi ( (struct type *)ulong_type , 0 ) )?ullong_type :ulong_type ):uint_type );

# 127 "/home/claude/cfront-3/src/simpl.cpp"
{ Pname __1nw ;

# 127 "/home/claude/cfront-3/src/simpl.cpp"
__1nw = __ct__4nameFPCc ( (struct name *)0 , __1ns ) ;
__1nw -> n_oper__4name = 23 ;
{ Pname __1a ;

# 129 "/home/claude/cfront-3/src/simpl.cpp"
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = size_t_type ;
__1nw -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , Pvoid_type , __1a , (unsigned char )1 ) ;
new_fct = dcl__4nameFP5tableUc ( __1nw , gtbl , (unsigned char )14 ) ;
( (__1nw ?(((void )(__1nw ?(((void )( ( ((((struct expr *)__1nw ))?(((void )((((struct expr *)__1nw ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 133 "/home/claude/cfront-3/src/simpl.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1nw , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 136 "/home/claude/cfront-3/src/simpl.cpp"
{ Pname __1dl ;

# 136 "/home/claude/cfront-3/src/simpl.cpp"
__1dl = __ct__4nameFPCc ( (struct name *)0 , __1ds ) ;
__1dl -> n_oper__4name = 9 ;
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = Pvoid_type ;
__1dl -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)void_type , __1a , (unsigned char )1 ) ;
del_fct = dcl__4nameFP5tableUc ( __1dl , gtbl , (unsigned char )14 ) ;
( (__1dl ?(((void )(__1dl ?(((void )( ( ((((struct expr *)__1dl ))?(((void )((((struct expr *)__1dl ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 142 "/home/claude/cfront-3/src/simpl.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1dl , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 146 "/home/claude/cfront-3/src/simpl.cpp"
{ Pname __1vn ;
Pname __1vd ;

# 146 "/home/claude/cfront-3/src/simpl.cpp"
__1vn = __ct__4nameFPCc ( (struct name *)0 , (const char *)"__vec_new") ;
__1vd = __ct__4nameFPCc ( (struct name *)0 , (const char *)"__vec_delete") ;

# 149 "/home/claude/cfront-3/src/simpl.cpp"
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = Pvoid_type ;
{ Pname __1al ;

# 152 "/home/claude/cfront-3/src/simpl.cpp"
struct name *__0__X25 ;

# 152 "/home/claude/cfront-3/src/simpl.cpp"
struct name *__0__X26 ;

# 152 "/home/claude/cfront-3/src/simpl.cpp"
struct ival *__0__X27 ;

# 152 "/home/claude/cfront-3/src/simpl.cpp"
struct type *__0__X28 ;

# 151 "/home/claude/cfront-3/src/simpl.cpp"
__1al = __1a ;
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = (struct type *)int_type ;
__1a -> __O1__4name.n_list = __1al ;
__1al = __1a ;
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = (struct type *)int_type ;
__1a -> __O1__4name.n_list = __1al ;
__1al = __1a ;
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = Pvoid_type ;
__1a -> __O1__4name.n_list = __1al ;
__1al = __1a ;

# 165 "/home/claude/cfront-3/src/simpl.cpp"
vec_new_fct = insert__5tableFP4nameUc ( gtbl , __1vn , (unsigned char )0 ) ;
( (__1vn ?(((void )(__1vn ?(((void )( ( ((((struct expr *)__1vn ))?(((void )((((struct expr *)__1vn ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 166 "/home/claude/cfront-3/src/simpl.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1vn , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
vec_new_fct -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , Pvoid_type , __1al , (unsigned char )1 ) ;
(((struct fct *)(((struct fct *)vec_new_fct -> __O1__4expr.tp ))))-> f_linkage__3fct = 1;
vec_new_fct -> n_scope__4name = 14 ;
vec_new_fct -> permanent__4node = 1 ;
vec_new_fct -> __O1__4expr.tp -> permanent__4node = 1 ;
( (__0__X25 = vec_new_fct ), ( (__0__X25 -> n_used__4name ++ ), (((void )0 ))) ) ;
dcl_print__4nameFUc ( vec_new_fct , (unsigned char )0 ) ;

# 175 "/home/claude/cfront-3/src/simpl.cpp"
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = (struct type *)int_type ;
__1al = __1a ;
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = (struct type *)int_type ;
__1a -> __O1__4name.n_list = __1al ;
__1al = __1a ;
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = Pvoid_type ;
__1a -> __O1__4name.n_list = __1al ;
__1al = __1a ;
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = (struct type *)int_type ;
__1a -> __O1__4name.n_list = __1al ;
__1al = __1a ;
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = (struct type *)int_type ;
__1a -> __O1__4name.n_list = __1al ;
__1al = __1a ;
__1a = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__1a -> __O1__4expr.tp = Pvoid_type ;
__1a -> __O1__4name.n_list = __1al ;
__1al = __1a ;

# 199 "/home/claude/cfront-3/src/simpl.cpp"
vec_del_fct = insert__5tableFP4nameUc ( gtbl , __1vd , (unsigned char )0 ) ;
( (__1vd ?(((void )(__1vd ?(((void )( ( ((((struct expr *)__1vd ))?(((void )((((struct expr *)__1vd ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 200 "/home/claude/cfront-3/src/simpl.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1vd , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
vec_del_fct -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)void_type , __1al , (unsigned char )1 ) ;
(((struct fct *)(((struct fct *)vec_del_fct -> __O1__4expr.tp ))))-> f_linkage__3fct = 1;
vec_del_fct -> n_scope__4name = 14 ;
vec_del_fct -> permanent__4node = 1 ;
vec_del_fct -> __O1__4expr.tp -> permanent__4node = 1 ;
( (__0__X26 = vec_del_fct ), ( (__0__X26 -> n_used__4name ++ ), (((void )0 ))) ) ;
dcl_print__4nameFUc ( vec_del_fct , (unsigned char )0 ) ;

# 209 "/home/claude/cfront-3/src/simpl.cpp"
one = (struct expr *)( (__0__X27 = 0 ), ( ((__0__X27 || (__0__X27 = (struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival)))
# 209 "/home/claude/cfront-3/src/simpl.cpp"
))?( (__0__X27 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X27 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 ) ),
# 209 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X27 -> __O2__4expr.i1 = ((long long )1 ))) :0 ), __0__X27 ) ) ;
one -> __O1__4expr.tp = (struct type *)int_type ;
one -> permanent__4node = 1 ;

# 213 "/home/claude/cfront-3/src/simpl.cpp"
Pfct_type = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)int_type , (struct name *)0 , (unsigned char )1 ) ;
Pfct_type = (struct type *)( (__0__X28 = Pfct_type ), ( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __0__X28 ) )
# 214 "/home/claude/cfront-3/src/simpl.cpp"
) ;
Pfct_type -> permanent__4node = 1 ;

# 217 "/home/claude/cfront-3/src/simpl.cpp"
if (ansi_opt )
# 218 "/home/claude/cfront-3/src/simpl.cpp"
fputs ( (const char *)"typedef int (*__vptp)(void);\n", out_file ) ;
else fputs ( (const char *)"typedef int (*__vptp)();\n", out_file ) ;
fputs ( (const char *)"struct __mptr {short d; short i; __vptp f; };\n", out_file ) ;
{ Pname __1b ;

# 222 "/home/claude/cfront-3/src/simpl.cpp"
struct type *__0__X29 ;

# 221 "/home/claude/cfront-3/src/simpl.cpp"
__1b = __ct__4nameFPCc ( (struct name *)0 , (const char *)"__mptr") ;
__1b -> __O1__4expr.tp = (struct type *)__ct__8classdefFUc ( (struct classdef *)0 , (unsigned char )32 ) ;
__1b -> __O1__4expr.tp -> defined__4type = 01 ;
(((struct classdef *)(((struct classdef *)__1b -> __O1__4expr.tp ))))-> obj_size__8classdef = ((SZ_SHORT + SZ_SHORT )+ SZ_WPTR );
mptr_type = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )119 , __1b ) ;
mptr_type -> permanent__4node = 1 ;

# 228 "/home/claude/cfront-3/src/simpl.cpp"
Pvptr_type = (struct type *)( (__0__X29 = (struct type *)mptr_type ), ( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __0__X29 )
# 228 "/home/claude/cfront-3/src/simpl.cpp"
) ) ;
Pvptr_type -> permanent__4node = 1 ;

# 229 "/home/claude/cfront-3/src/simpl.cpp"
}

# 229 "/home/claude/cfront-3/src/simpl.cpp"
}

# 229 "/home/claude/cfront-3/src/simpl.cpp"
}

# 229 "/home/claude/cfront-3/src/simpl.cpp"
}

# 229 "/home/claude/cfront-3/src/simpl.cpp"
}

# 229 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 232 "/home/claude/cfront-3/src/simpl.cpp"
Ptable scope = 0 ;
Pname expand_fn = 0 ;
Ptable expand_tbl = 0 ;

# 473 "/home/claude/cfront-3/src/cfront.h"
Pexpr find_name__8classdefFPCcP8classdefiT3 (struct classdef *__0this , const char *, Pclass , int , int );

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 236 "/home/claude/cfront-3/src/simpl.cpp"
Pname has_oper__8classdefFUc (register struct classdef *__0this , TOK __1op )
# 237 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 238 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __1n ;

# 238 "/home/claude/cfront-3/src/simpl.cpp"
__1n = find_name__8classdefFPCcP8classdefiT3 ( __0this , oper_name__FUc ( __1op ) , (struct classdef *)0 , 0 , 1 ) ;
if (__1n == 0 )return (struct name *)0 ;

# 241 "/home/claude/cfront-3/src/simpl.cpp"
while ((__1n -> base__4node == 44 )|| (__1n -> base__4node == 177 )){ 
# 242 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __2e ;

# 242 "/home/claude/cfront-3/src/simpl.cpp"
__2e = (((struct expr *)(((struct expr *)__1n ))));
__1n = (struct expr *)(((struct name *)(((struct name *)__1n -> __O4__4expr.mem ))));
( (__2e ?(((void )(__2e ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__2e , (size_t )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 244 "/home/claude/cfront-3/src/simpl.cpp"
;
}
if ((__1n -> __O1__4expr.tp -> base__4node == 108 )&& ((((struct name *)(((struct name *)__1n ))))-> n_dcl_printed__4name == 0 ))dcl_print__4nameFUc ( ((struct name *)(((struct name *)__1n ))), (unsigned
# 246 "/home/claude/cfront-3/src/simpl.cpp"
char )0 ) ;
return (((struct name *)(((struct name *)__1n ))));
}

# 250 "/home/claude/cfront-3/src/simpl.cpp"
int is_expr__FP4stmt (Pstmt __1s );

# 250 "/home/claude/cfront-3/src/simpl.cpp"
int is_expr__FP4stmt (Pstmt __1s )
# 255 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 256 "/home/claude/cfront-3/src/simpl.cpp"
int __1i ;

# 256 "/home/claude/cfront-3/src/simpl.cpp"
__1i = 0 ;
while (__1s -> base__4node == 116 ){ 
# 258 "/home/claude/cfront-3/src/simpl.cpp"
if (__1s -> s__4stmt == 0 )return 1 ;
__1s = __1s -> s__4stmt ;
}
{ { Pstmt __1ss ;

# 261 "/home/claude/cfront-3/src/simpl.cpp"
__1ss = __1s ;

# 261 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1ss ;__1ss = __1ss -> s_list__4stmt ) { 
# 263 "/home/claude/cfront-3/src/simpl.cpp"
switch (__1ss -> base__4node ){ 
# 264 "/home/claude/cfront-3/src/simpl.cpp"
case 116 :
# 265 "/home/claude/cfront-3/src/simpl.cpp"
if ((((struct block *)(((struct block *)__1ss ))))-> memtbl__4stmt || (is_expr__FP4stmt (
# 265 "/home/claude/cfront-3/src/simpl.cpp"
__1ss -> s__4stmt ) == 0 ))return 0 ;
case 72 :
# 267 "/home/claude/cfront-3/src/simpl.cpp"
if (__1ss -> __O2__4stmt.e && (__1ss -> __O2__4stmt.e -> base__4node == 168 )){ 
# 268 "/home/claude/cfront-3/src/simpl.cpp"
Pname __4fn ;
Pfct __4f ;

# 268 "/home/claude/cfront-3/src/simpl.cpp"
__4fn = __1ss -> __O2__4stmt.e -> __O4__4expr.il -> fct_name__5iline ;
__4f = (((struct fct *)(((struct fct *)__4fn -> __O1__4expr.tp ))));
if (__4f -> f_expr__3fct == 0 )return 0 ;
}
break ;
case 20 :
# 274 "/home/claude/cfront-3/src/simpl.cpp"
if (is_expr__FP4stmt ( __1ss -> s__4stmt ) == 0 )return 0 ;
if (__1ss -> __O3__4stmt.else_stmt && (is_expr__FP4stmt ( __1ss -> __O3__4stmt.else_stmt ) == 0 ))return 0 ;
break ;
default :
# 278 "/home/claude/cfront-3/src/simpl.cpp"
return 0 ;
}
__1i ++ ;
}
return __1i ;

# 282 "/home/claude/cfront-3/src/simpl.cpp"
}

# 282 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 285 "/home/claude/cfront-3/src/simpl.cpp"
int no_of_returns = 0 ;

# 287 "/home/claude/cfront-3/src/simpl.cpp"
int size_complexity_measure = 20 ;

# 75 "/home/claude/cfront-3/src/cfront.h"

# 289 "/home/claude/cfront-3/src/simpl.cpp"
void simpl__4nameFv (struct name *__0this );

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 644 "/home/claude/cfront-3/src/cfront.h"
void simpl__3fctFv (struct fct *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 1019 "/home/claude/cfront-3/src/cfront.h"
Pstmt expand__4stmtFv (struct stmt *__0this );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 450 "/home/claude/cfront-3/src/cfront.h"
void simpl__8classdefFv (struct classdef *__0this );

# 805 "/home/claude/cfront-3/src/cfront.h"
void simpl__4exprFv (struct expr *__0this );

# 289 "/home/claude/cfront-3/src/simpl.cpp"
void simpl__4nameFv (register struct name *__0this )
# 290 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 292 "/home/claude/cfront-3/src/simpl.cpp"
if (__0this -> base__4node == 25 )return ;

# 294 "/home/claude/cfront-3/src/simpl.cpp"
if (__0this -> __O1__4expr.tp == 0 ){ 
# 294 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V30 ;

# 294 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%n->N::simple(tp==0)", (const struct ea *)( ((&
# 294 "/home/claude/cfront-3/src/simpl.cpp"
__0__V30 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V30 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 294 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 ) ;
} if ((__0this -> __O1__4expr.tp -> base__4node == 6 )&& (__0this -> n_key__4name == 44 ))return ;
if ((__0this -> __O1__4expr.tp -> base__4node == 6 )&& (((((struct classdef *)(((struct classdef *)__0this -> __O1__4expr.tp ))))-> defined__4type & 01 )== 0 ))return ;

# 298 "/home/claude/cfront-3/src/simpl.cpp"
switch (__0this -> __O1__4expr.tp -> base__4node ){ 
# 299 "/home/claude/cfront-3/src/simpl.cpp"
case 0 :
# 300 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 300 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V31 ;

# 300 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%n->N::simpl(tp->B==0)", (const struct ea *)( ((&
# 300 "/home/claude/cfront-3/src/simpl.cpp"
__0__V31 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V31 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 300 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 ) ;

# 302 "/home/claude/cfront-3/src/simpl.cpp"
case 97 :
# 303 "/home/claude/cfront-3/src/simpl.cpp"
case 110 :
# 304 "/home/claude/cfront-3/src/simpl.cpp"
case 125 :
# 305 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 306 "/home/claude/cfront-3/src/simpl.cpp"
Ptype __3t ;

# 306 "/home/claude/cfront-3/src/simpl.cpp"
__3t = __0this -> __O1__4expr.tp ;
xx :
# 308 "/home/claude/cfront-3/src/simpl.cpp"
switch (__3t -> base__4node ){ 
# 309 "/home/claude/cfront-3/src/simpl.cpp"
case 97 :__3t = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype -> __O1__4expr.tp ;

# 309 "/home/claude/cfront-3/src/simpl.cpp"
goto xx ;
case 110 :__3t = (((struct vec *)(((struct vec *)__3t ))))-> typ__5pvtyp ;

# 310 "/home/claude/cfront-3/src/simpl.cpp"
goto xx ;
case 125 :__3t = (((struct ptr *)(((struct ptr *)__3t ))))-> typ__5pvtyp ;

# 311 "/home/claude/cfront-3/src/simpl.cpp"
goto xx ;
case 108 :break ;
}
break ;
}

# 317 "/home/claude/cfront-3/src/simpl.cpp"
case 76 :
# 318 "/home/claude/cfront-3/src/simpl.cpp"
{ { { Plist __3gl ;

# 318 "/home/claude/cfront-3/src/simpl.cpp"
__3gl = (((struct gen *)(((struct gen *)__0this -> __O1__4expr.tp ))))-> fct_list__3gen ;

# 318 "/home/claude/cfront-3/src/simpl.cpp"
for(;__3gl ;__3gl = __3gl -> l__9name_list ) simpl__4nameFv ( __3gl -> f__9name_list ) ;
break ;

# 319 "/home/claude/cfront-3/src/simpl.cpp"
}

# 319 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 322 "/home/claude/cfront-3/src/simpl.cpp"
case 108 :
# 323 "/home/claude/cfront-3/src/simpl.cpp"
{ Pfct __3f ;
Pname __3n ;
Pname __3th ;

# 323 "/home/claude/cfront-3/src/simpl.cpp"
__3f = (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))));

# 325 "/home/claude/cfront-3/src/simpl.cpp"
__3th = __3f -> f_this__3fct ;

# 327 "/home/claude/cfront-3/src/simpl.cpp"
if (__3th ){ 
# 330 "/home/claude/cfront-3/src/simpl.cpp"
__3th -> n_stclass__4name = (((! __3th -> n_addr_taken__4name )&& (2 < __3th -> n_used__4name ))?27 :2 );
if (__3th -> n_assigned_to__4name && (__3th -> n_assigned_to__4name != 11111 ))
# 336 "/home/claude/cfront-3/src/simpl.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __0this -> where__4name , (const char *)"assignment to this (anachronism)",
# 336 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
}

# 339 "/home/claude/cfront-3/src/simpl.cpp"
if (__0this -> __O1__4expr.tp -> defined__4type & 02 )return ;
if ((__0this -> __O1__4expr.tp -> defined__4type & 01 )== 0 )return ;

# 342 "/home/claude/cfront-3/src/simpl.cpp"
for(__3n = __3f -> f_args__3fct ;__3n ;__3n = __3n -> __O1__4name.n_list ) simpl__4nameFv ( __3n ) ;

# 344 "/home/claude/cfront-3/src/simpl.cpp"
if (__3f -> body__3fct ){ 
# 345 "/home/claude/cfront-3/src/simpl.cpp"
Ptable __4oscope ;
Pname __4ocurr ;
int __4oim ;

# 345 "/home/claude/cfront-3/src/simpl.cpp"
__4oscope = scope ;
__4ocurr = curr_fct ;
__4oim = imeasure ;
scope = __3f -> body__3fct -> memtbl__4stmt ;

# 350 "/home/claude/cfront-3/src/simpl.cpp"
if (scope == 0 ){ 
# 350 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V32 ;

# 350 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%n memtbl missing", (const struct ea *)( ((&
# 350 "/home/claude/cfront-3/src/simpl.cpp"
__0__V32 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V32 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 350 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 ) ;
} curr_fct = __0this ;
simpl__3fctFv ( __3f ) ;
if ((__3f -> f_inline__3fct == 0 )|| debug_opt )
# 354 "/home/claude/cfront-3/src/simpl.cpp"
__3f -> f_imeasure__3fct = 0 ;
else { 
# 356 "/home/claude/cfront-3/src/simpl.cpp"
if (warning_opt && __3f -> f_virtual__3fct )
# 357 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 357 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V33 ;

# 357 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"virtual function %n cannot be inlined", (const struct ea *)( ((&
# 357 "/home/claude/cfront-3/src/simpl.cpp"
__0__V33 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V33 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 357 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 ) ;
} 
# 360 "/home/claude/cfront-3/src/simpl.cpp"
if (size_complexity_measure < __3f -> f_imeasure__3fct ){ 
# 361 "/home/claude/cfront-3/src/simpl.cpp"
if (warning_opt ){ 
# 362 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 362 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V34 ;

# 362 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%n too large for inlining", (const struct ea *)( ((&
# 362 "/home/claude/cfront-3/src/simpl.cpp"
__0__V34 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V34 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 362 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 ) ;
} }
__3f -> f_inline__3fct = 0 ;

# 366 "/home/claude/cfront-3/src/simpl.cpp"
scope = __4oscope ;
__0this -> __O1__4expr.tp -> defined__4type |= 02 ;
return ;
}
{ int __5i ;

# 370 "/home/claude/cfront-3/src/simpl.cpp"
__5i = 0 ;
for(__3n = __3f -> f_args__3fct ;__3n ;__3n = __3n -> __O1__4name.n_list ) { 
# 372 "/home/claude/cfront-3/src/simpl.cpp"
__3n -> base__4node = 169 ;
__3n -> argno__4name = (__5i ++ );

# 375 "/home/claude/cfront-3/src/simpl.cpp"
}
expand_tbl = (((__3f -> returns__3fct -> base__4node != 38 )|| (__0this -> n_oper__4name == 161 ))?scope :(((struct table *)0 )));
expand_fn = __0this ;

# 379 "/home/claude/cfront-3/src/simpl.cpp"
if (expand_tbl ){ 
# 380 "/home/claude/cfront-3/src/simpl.cpp"
genlab :
# 383 "/home/claude/cfront-3/src/simpl.cpp"
{ Pexpr __6ee ;
Ptype __6t ;

# 385 "/home/claude/cfront-3/src/simpl.cpp"
register struct cast *__0__X35 ;

# 385 "/home/claude/cfront-3/src/simpl.cpp"
struct type *__2__X36 ;

# 385 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X37 ;

# 383 "/home/claude/cfront-3/src/simpl.cpp"
__6ee = (((struct expr *)(((struct expr *)expand__4stmtFv ( (struct stmt *)__3f -> body__3fct ) ))));
__6t = 0 ;
if (__3f -> s_returns__3fct ){ 
# 386 "/home/claude/cfront-3/src/simpl.cpp"
if (__6ee -> __O1__4expr.tp != __3f -> s_returns__3fct )__6t = __3f -> s_returns__3fct ;
}
else if (__6ee -> __O1__4expr.tp != __3f -> returns__3fct )
# 389 "/home/claude/cfront-3/src/simpl.cpp"
__6t = __3f -> returns__3fct ;

# 391 "/home/claude/cfront-3/src/simpl.cpp"
if (__6t && (__6t == (((struct type *)void_type ))))
# 392 "/home/claude/cfront-3/src/simpl.cpp"
__6ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __6ee , (struct expr *)(
# 392 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X35 = 0 ), ( (__2__X36 = (struct type *)(ansi_opt ?void_type :char_type )), ( (__2__X37 = zero ), ( ((__0__X35 || (__0__X35 = (struct cast *)__nw__4exprSFUl (
# 392 "/home/claude/cfront-3/src/simpl.cpp"
(size_t )(sizeof (struct cast))) ))?( (__0__X35 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X35 ), (unsigned char )191 , __2__X37 ,
# 392 "/home/claude/cfront-3/src/simpl.cpp"
(struct expr *)0 ) ), (__0__X35 -> __O1__4expr.tp = (__0__X35 -> __O4__4expr.tp2 = __2__X36 ))) :0 ), __0__X35 ) ) ) ) )
# 392 "/home/claude/cfront-3/src/simpl.cpp"
;
__3f -> f_expr__3fct = ((__6ee -> base__4node == 71 )?__6ee :__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , zero , __6ee ) );

# 393 "/home/claude/cfront-3/src/simpl.cpp"
}

# 395 "/home/claude/cfront-3/src/simpl.cpp"
}
else { 
# 397 "/home/claude/cfront-3/src/simpl.cpp"
if (is_expr__FP4stmt ( (struct stmt *)__3f -> body__3fct ) ){ 
# 399 "/home/claude/cfront-3/src/simpl.cpp"
expand_tbl = scope ;
goto genlab ;
}

# 403 "/home/claude/cfront-3/src/simpl.cpp"
__3f -> f_expr__3fct = 0 ;
replace_ret__FP4stmtiP5table ( __3f -> body__3fct -> s__4stmt , 0 , __3f -> body__3fct -> memtbl__4stmt ) ;
__3f -> body__3fct = (((struct block *)(((struct block *)expand__4stmtFv ( (struct stmt *)__3f -> body__3fct ) ))));
}
expand_fn = 0 ;
expand_tbl = 0 ;

# 408 "/home/claude/cfront-3/src/simpl.cpp"
}
}
scope = __4oscope ;
curr_fct = __4ocurr ;
imeasure = __4oim ;
}
break ;
}

# 417 "/home/claude/cfront-3/src/simpl.cpp"
case 6 :
# 418 "/home/claude/cfront-3/src/simpl.cpp"
simpl__8classdefFv ( ((struct classdef *)(((struct classdef *)__0this -> __O1__4expr.tp )))) ;
} }

# 423 "/home/claude/cfront-3/src/simpl.cpp"
if ((__0this -> base__4node != 123 )&& __0this -> __O3__4expr.n_initializer )simpl__4exprFv ( __0this -> __O3__4expr.n_initializer ) ;
__0this -> __O1__4expr.tp -> defined__4type |= 02 ;
}

# 844 "/home/claude/cfront-3/src/cfront.h"

# 798 "/home/claude/cfront-3/src/cfront.h"
Pexpr typ__4exprFP5table (struct expr *__0this , Ptable );

# 427 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr call_ctor__FP5tableP4exprN22iT2 (Ptable __1tbl , Pexpr __1p , Pexpr __1ctor , Pexpr __1args , int __1d , Pexpr __1vb_args )
# 428 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 429 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __1ee ;

# 430 "/home/claude/cfront-3/src/simpl.cpp"
struct ref *__0__X38 ;

# 430 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X39 ;

# 430 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X40 ;

# 429 "/home/claude/cfront-3/src/simpl.cpp"
__1ee = (struct expr *)( (__0__X38 = 0 ), ( (__2__X39 = __1p ), ( (__2__X40 = __1ctor ), ( ((__0__X38 || (__0__X38 =
# 429 "/home/claude/cfront-3/src/simpl.cpp"
(struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X38 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X38 ), ((unsigned char
# 429 "/home/claude/cfront-3/src/simpl.cpp"
)__1d ), __2__X39 , (struct expr *)0 ) ), (__0__X38 -> __O4__4expr.mem = __2__X40 )) :0 ), __0__X38 ) ) ) ) ;
# 429 "/home/claude/cfront-3/src/simpl.cpp"

# 430 "/home/claude/cfront-3/src/simpl.cpp"
if ((__1p == 0 )|| (__1tbl == 0 ))__1ee -> __O1__4expr.tp = __1ctor -> __O1__4expr.tp ;

# 432 "/home/claude/cfront-3/src/simpl.cpp"
if (__1args && (__1args -> base__4node != 140 ))__1args = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1args , (struct expr *)0 )
# 432 "/home/claude/cfront-3/src/simpl.cpp"
;
__1ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , __1ee , __1args ) ;
{ Pname __1n ;

# 434 "/home/claude/cfront-3/src/simpl.cpp"
__1n = (((struct name *)(((struct name *)__1ctor ))));

# 436 "/home/claude/cfront-3/src/simpl.cpp"
while (__1n -> base__4node == 177 )__1n = (((struct name *)(((struct name *)__1n -> __O4__4expr.mem ))));
if (__1n -> __O1__4expr.tp -> base__4node == 108 )__1ee -> __O4__4expr.fct_name = __1n ;

# 439 "/home/claude/cfront-3/src/simpl.cpp"
if (__1tbl )
# 440 "/home/claude/cfront-3/src/simpl.cpp"
__1ee = typ__4exprFP5table ( __1ee , __1tbl ) ;
else 
# 442 "/home/claude/cfront-3/src/simpl.cpp"
if (__1n -> __O1__4expr.tp -> base__4node == 108 )
# 443 "/home/claude/cfront-3/src/simpl.cpp"
__1ee -> __O1__4expr.tp = (((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))))-> s_returns__3fct ;

# 445 "/home/claude/cfront-3/src/simpl.cpp"
if (__1ee -> __O1__4expr.tp == (((struct type *)any_type )))return __1ee ;
__1args = __1ee -> __O3__4expr.e2 ;

# 448 "/home/claude/cfront-3/src/simpl.cpp"
if (__1vb_args == 0 ){ 
# 449 "/home/claude/cfront-3/src/simpl.cpp"
Pfct __2f ;

# 449 "/home/claude/cfront-3/src/simpl.cpp"
__2f = (((struct fct *)(((struct fct *)__1ee -> __O4__4expr.fct_name -> __O1__4expr.tp ))));
{ { Pname __2nn ;

# 450 "/home/claude/cfront-3/src/simpl.cpp"
__2nn = __2f -> f_args__3fct -> __O1__4name.n_list ;

# 450 "/home/claude/cfront-3/src/simpl.cpp"
for(;__2nn && (__2nn != __2f -> argtype__3fct );__2nn = __2nn -> __O1__4name.n_list ) 
# 451 "/home/claude/cfront-3/src/simpl.cpp"
__1args = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero ,
# 451 "/home/claude/cfront-3/src/simpl.cpp"
__1args ) ;

# 451 "/home/claude/cfront-3/src/simpl.cpp"
}

# 451 "/home/claude/cfront-3/src/simpl.cpp"
}
}
else { 
# 454 "/home/claude/cfront-3/src/simpl.cpp"
if (__1args ){ 
# 455 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __3d ;

# 455 "/home/claude/cfront-3/src/simpl.cpp"
__3d = __1vb_args ;
for(;__3d -> __O3__4expr.e2 ;__3d = __3d -> __O3__4expr.e2 ) ;
__3d -> __O3__4expr.e2 = __1args ;
}
__1args = __1vb_args ;
}

# 463 "/home/claude/cfront-3/src/simpl.cpp"
if (__1n -> __O1__4expr.tp -> base__4node == 108 ){ 
# 464 "/home/claude/cfront-3/src/simpl.cpp"
Pfct __2f ;
Pexpr __2ee ;
Pname __2nn ;

# 464 "/home/claude/cfront-3/src/simpl.cpp"
__2f = (((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))));

# 467 "/home/claude/cfront-3/src/simpl.cpp"
if (__2f -> argtype__3fct && __1args )
# 468 "/home/claude/cfront-3/src/simpl.cpp"
for(( (__2nn = __2f -> argtype__3fct -> __O1__4name.n_list ), (__2ee = __1args )) ;__2nn ;( (__2nn = __2nn -> __O1__4name.n_list ),
# 468 "/home/claude/cfront-3/src/simpl.cpp"
(__2ee = __2ee -> __O3__4expr.e2 )) ) 
# 469 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 470 "/home/claude/cfront-3/src/simpl.cpp"
if (__2ee -> __O3__4expr.e2 == 0 ){ 
# 471 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __4a ;
Pexpr __4e ;

# 471 "/home/claude/cfront-3/src/simpl.cpp"
__4a = __2nn -> __O3__4expr.n_initializer ;
__4e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __4a , (struct expr *)0 ) ;
__2ee -> __O3__4expr.e2 = __4e ;
}
}
}

# 478 "/home/claude/cfront-3/src/simpl.cpp"
__1ee -> __O3__4expr.e2 = __1args ;
return __1ee ;

# 479 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 844 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 832 "/home/claude/cfront-3/src/cfront.h"

# 449 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8classdefFP4name (struct classdef *__0this , Pname );

# 482 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr call_dtor__FP4exprN21iT1 (Pexpr __1p , Pexpr __1dtor , Pexpr __1arg , int __1d , Pexpr __1vb_args )
# 483 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 487 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __1r ;

# 488 "/home/claude/cfront-3/src/simpl.cpp"
struct ival *__0__X41 ;

# 488 "/home/claude/cfront-3/src/simpl.cpp"
struct ival *__0__X42 ;

# 488 "/home/claude/cfront-3/src/simpl.cpp"
struct ref *__0__X46 ;

# 488 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X47 ;

# 488 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X48 ;

# 487 "/home/claude/cfront-3/src/simpl.cpp"
__1r = (struct expr *)( (__0__X46 = 0 ), ( (__2__X47 = __1p ), ( (__2__X48 = __1dtor ), ( ((__0__X46 || (__0__X46 =
# 487 "/home/claude/cfront-3/src/simpl.cpp"
(struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X46 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X46 ), ((unsigned char
# 487 "/home/claude/cfront-3/src/simpl.cpp"
)(__1d ?__1d :44 )), __2__X47 , (struct expr *)0 ) ), (__0__X46 -> __O4__4expr.mem = __2__X48 )) :0 ), __0__X46 ) ) ) ) ;
# 487 "/home/claude/cfront-3/src/simpl.cpp"

# 489 "/home/claude/cfront-3/src/simpl.cpp"
if (__1arg && __1vb_args )
# 490 "/home/claude/cfront-3/src/simpl.cpp"
__1arg = (struct expr *)( (__0__X41 = 0 ), ( ((__0__X41 || (__0__X41 = (struct ival *)__nw__4exprSFUl ( (unsigned long
# 490 "/home/claude/cfront-3/src/simpl.cpp"
)(sizeof (struct ival))) ))?( (__0__X41 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X41 ), (unsigned char )150 , (struct expr *)0 , (struct
# 490 "/home/claude/cfront-3/src/simpl.cpp"
expr *)0 ) ), (__0__X41 -> __O2__4expr.i1 = ((long long )3 ))) :0 ), __0__X41 ) ) ;
else if (__1vb_args )
# 492 "/home/claude/cfront-3/src/simpl.cpp"
__1arg = (struct expr *)( (__0__X42 = 0 ), ( ((__0__X42 || (__0__X42 = (struct ival *)__nw__4exprSFUl ( (unsigned long
# 492 "/home/claude/cfront-3/src/simpl.cpp"
)(sizeof (struct ival))) ))?( (__0__X42 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X42 ), (unsigned char )150 , (struct expr *)0 , (struct
# 492 "/home/claude/cfront-3/src/simpl.cpp"
expr *)0 ) ), (__0__X42 -> __O2__4expr.i1 = ((long long )2 ))) :0 ), __0__X42 ) ) ;
else if (__1arg == 0 )
# 494 "/home/claude/cfront-3/src/simpl.cpp"
__1arg = zero ;
if (__1arg -> __O1__4expr.tp == 0 )__1arg -> __O1__4expr.tp = (struct type *)int_type ;

# 497 "/home/claude/cfront-3/src/simpl.cpp"
{ Pexpr __1aa ;

# 501 "/home/claude/cfront-3/src/simpl.cpp"
Pfct __1f ;

# 508 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __1ee ;

# 509 "/home/claude/cfront-3/src/simpl.cpp"
struct call *__0__X43 ;

# 509 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X44 ;

# 509 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X45 ;

# 497 "/home/claude/cfront-3/src/simpl.cpp"
__1aa = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1arg , (struct expr *)0 ) ;

# 501 "/home/claude/cfront-3/src/simpl.cpp"
__1f = (((struct fct *)(((struct fct *)__1dtor -> __O1__4expr.tp ))));

# 508 "/home/claude/cfront-3/src/simpl.cpp"
__1ee = (struct expr *)( (__0__X43 = 0 ), ( (__2__X44 = __1r ), ( (__2__X45 = __1aa ), ( ((__0__X43 || (__0__X43 =
# 508 "/home/claude/cfront-3/src/simpl.cpp"
(struct call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X43 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X43 ), (unsigned char )109 ,
# 508 "/home/claude/cfront-3/src/simpl.cpp"
__2__X44 , __2__X45 ) ):0 ), __0__X43 ) ) ) ) ;
while (__1dtor -> base__4node == 177 )__1dtor = __1dtor -> __O4__4expr.mem ;
if (__1d == 44 )
# 511 "/home/claude/cfront-3/src/simpl.cpp"
__1ee -> __O4__4expr.fct_name = (((struct name *)(((struct name *)__1dtor ))));
else { 
# 513 "/home/claude/cfront-3/src/simpl.cpp"
__1r -> __O3__4expr.n_initializer = __1dtor ;
__1ee -> __O4__4expr.fct_name = 0 ;
}
__1ee -> base__4node = 146 ;
__1ee -> __O1__4expr.tp = (struct type *)void_type ;

# 519 "/home/claude/cfront-3/src/simpl.cpp"
if (__1f -> memof__3fct -> c_body__8classdef == 1 )dcl_print__8classdefFP4name ( __1f -> memof__3fct , (struct name *)0 ) ;
if ((((struct name *)(((struct name *)__1dtor ))))-> n_dcl_printed__4name == 0 )dcl_print__4nameFUc ( ((struct name *)(((struct name *)__1dtor ))), (unsigned char )0 ) ;

# 522 "/home/claude/cfront-3/src/simpl.cpp"
return __1ee ;

# 522 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 75 "/home/claude/cfront-3/src/cfront.h"

# 959 "/home/claude/cfront-3/src/cfront.h"
void del__4nameFv (struct name *__0this );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 467 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 1230 "/home/claude/cfront-3/src/cfront.h"
extern void check_visibility__FP4nameT1P8classdefP5tableT1 (Pname , Pname , Pclass , Ptable , Pname );

# 467 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 534 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr cdvec__FP4nameP4exprP8classdefT1iN22 (Pname , Pexpr , Pclass , Pname , int , Pexpr , Pexpr );

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 870 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 532 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr rptr__FP4typeP4expri (Ptype , Pexpr , int );

# 804 "/home/claude/cfront-3/src/cfront.h"
Pexpr contents__4exprFv (struct expr *__0this );

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 828 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 537 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr find_name__FP4nameP8classdefP5tableiT1 (Pname , Pclass , Ptable , int , Pname );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 832 "/home/claude/cfront-3/src/cfront.h"

# 802 "/home/claude/cfront-3/src/cfront.h"
Ptype call_fct__4exprFP5table (struct expr *__0this , Ptable );

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1050 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 1050 "/home/claude/cfront-3/src/cfront.h"

# 1018 "/home/claude/cfront-3/src/cfront.h"
Pstmt simpl__4stmtFv (struct stmt *__0this );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 1 ""
extern void __dl__FPv (void *);

# 527 "/home/claude/cfront-3/src/simpl.cpp"
Pstmt dtor_simpl__3fctFP8classdefP4expr (register struct fct *__0this , Pclass __1cl , Pexpr __1th )
# 528 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 529 "/home/claude/cfront-3/src/simpl.cpp"
Pstmt __1dtail ;

# 533 "/home/claude/cfront-3/src/simpl.cpp"
Pname __1fa ;

# 529 "/home/claude/cfront-3/src/simpl.cpp"
__1dtail = 0 ;

# 533 "/home/claude/cfront-3/src/simpl.cpp"
__1fa = __ct__4nameFPCc ( (struct name *)0 , (const char *)"__free") ;
__1fa -> __O1__4expr.tp = (struct type *)int_type ;
{ Pname __1free_arg ;

# 535 "/home/claude/cfront-3/src/simpl.cpp"
__1free_arg = dcl__4nameFP5tableUc ( __1fa , __0this -> body__3fct -> memtbl__4stmt , (unsigned char )136 ) ;
__1free_arg -> where__4name = no_where ;
( (__1fa ?(((void )(__1fa ?(((void )( ( ((((struct expr *)__1fa ))?(((void )((((struct expr *)__1fa ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 537 "/home/claude/cfront-3/src/simpl.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1fa , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
{ Pname __1a ;

# 538 "/home/claude/cfront-3/src/simpl.cpp"
__1a = __0this -> f_args__3fct ;
if ((__1a == 0 )|| (__1a -> __O1__4name.n_list == 0 )){ 
# 539 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V49 ;

# 539 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"__freeA missing in destructor for %t", (const struct ea *)( ((&
# 539 "/home/claude/cfront-3/src/simpl.cpp"
__0__V49 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V49 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 539 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 ) ;
} { Pname __1p ;

# 540 "/home/claude/cfront-3/src/simpl.cpp"
__1p = 0 ;
for(;;( (__1p = __1a ), (__1a = __1a -> __O1__4name.n_list )) ) { 
# 543 "/home/claude/cfront-3/src/simpl.cpp"
if (__1a -> __O1__4name.n_list == 0 ){ 
# 545 "/home/claude/cfront-3/src/simpl.cpp"
if (__1p ->
# 545 "/home/claude/cfront-3/src/simpl.cpp"
__O1__4name.n_list && (__1p -> __O1__4name.n_list -> permanent__4node == 0 ))del__4nameFv ( __1p -> __O1__4name.n_list ) ;
__1p -> __O1__4name.n_list = __1free_arg ;
break ;
}
}

# 552 "/home/claude/cfront-3/src/simpl.cpp"
{ Ptable __1tbl ;
int __1i ;

# 552 "/home/claude/cfront-3/src/simpl.cpp"
__1tbl = __1cl -> memtbl__8classdef ;
__1i = 1 ;
{ { Pname __1m ;

# 555 "/home/claude/cfront-3/src/simpl.cpp"
int __2__X50 ;

# 554 "/home/claude/cfront-3/src/simpl.cpp"
__1m = ( (((__1i <= 0 )|| (__1tbl -> free_slot__5table <= __1i ))?(((struct name *)0 )):(__1tbl -> entries__5table [__1i ]))) ;

# 554 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1m ;__1m = (__1m -> n_tbl_list__4name ?__1m -> n_tbl_list__4name :( (__2__X50 = (++ __1i )), ( (((__2__X50 <= 0 )|| (__1tbl -> free_slot__5table <= __2__X50 ))?(((struct name *)0 )):(__1tbl ->
# 554 "/home/claude/cfront-3/src/simpl.cpp"
entries__5table [__2__X50 ]))) ) )) { 
# 555 "/home/claude/cfront-3/src/simpl.cpp"
if ((__1m -> base__4node == 123 )|| (__1m -> __O1__4expr.tp == 0 ))continue ;

# 557 "/home/claude/cfront-3/src/simpl.cpp"
if ((__1m -> n_stclass__4name == 31 )|| (__1m -> base__4node == 25 ))continue ;

# 559 "/home/claude/cfront-3/src/simpl.cpp"
{ Ptype __2t ;
Pexpr __2ee ;
Pname __2cn ;
Pname __2dtor ;

# 559 "/home/claude/cfront-3/src/simpl.cpp"
__2t = __1m -> __O1__4expr.tp ;
__2ee = 0 ;

# 564 "/home/claude/cfront-3/src/simpl.cpp"
if (__2cn = is_cl_obj__4typeFv ( __2t ) ){ 
# 565 "/home/claude/cfront-3/src/simpl.cpp"
Pclass __3cl ;

# 565 "/home/claude/cfront-3/src/simpl.cpp"
__3cl = (((struct classdef *)(((struct classdef *)__2cn -> __O1__4expr.tp ))));
if (__2dtor = ( __3cl -> c_dtor__8classdef ) ){ 
# 566 "/home/claude/cfront-3/src/simpl.cpp"
struct ref *__0__X51 ;

# 566 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X52 ;

# 566 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X53 ;

# 567 "/home/claude/cfront-3/src/simpl.cpp"
__2ee = (struct expr *)( (__0__X51 = 0 ), ( (__2__X52 = __1th ), ( (__2__X53 = (struct expr *)__1m ), ( ((__0__X51 ||
# 567 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X51 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X51 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X51 ), ((unsigned
# 567 "/home/claude/cfront-3/src/simpl.cpp"
char )44 ), __2__X52 , (struct expr *)0 ) ), (__0__X51 -> __O4__4expr.mem = __2__X53 )) :0 ), __0__X51 ) ) ) )
# 567 "/home/claude/cfront-3/src/simpl.cpp"
;
__2ee -> __O1__4expr.tp = __1m -> __O1__4expr.tp ;
__2ee = call_dtor__FP4exprN21iT1 ( __2ee , (struct expr *)__2dtor , (struct expr *)0 , 45 , one ) ;
check_visibility__FP4nameT1P8classdefP5tableT1 ( __2dtor , (struct name *)0 , ((struct classdef *)(((struct classdef *)__2dtor -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))), __1tbl , curr_fct ) ;
}
}
else if (cl_obj_vec ){ 
# 574 "/home/claude/cfront-3/src/simpl.cpp"
Pclass __3cl ;

# 574 "/home/claude/cfront-3/src/simpl.cpp"
__3cl = (((struct classdef *)(((struct classdef *)cl_obj_vec -> __O1__4expr.tp ))));
if (__2dtor = ( __3cl -> c_dtor__8classdef ) ){ 
# 576 "/home/claude/cfront-3/src/simpl.cpp"
Pfct __4f ;
int __4i ;

# 576 "/home/claude/cfront-3/src/simpl.cpp"
__4f = (((struct fct *)(((struct fct *)__2dtor -> __O1__4expr.tp ))));
__4i = 0 ;
{ { Pname __4nn ;

# 579 "/home/claude/cfront-3/src/simpl.cpp"
struct ref *__0__X54 ;

# 579 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X55 ;

# 579 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X56 ;

# 579 "/home/claude/cfront-3/src/simpl.cpp"
struct ival *__0__X57 ;

# 578 "/home/claude/cfront-3/src/simpl.cpp"
__4nn = __4f -> f_args__3fct -> __O1__4name.n_list ;

# 578 "/home/claude/cfront-3/src/simpl.cpp"
for(;__4nn && __4nn -> __O1__4name.n_list ;__4nn = __4nn -> __O1__4name.n_list ) __4i ++ ;

# 580 "/home/claude/cfront-3/src/simpl.cpp"
__2ee = (struct expr *)( (__0__X54 = 0 ), ( (__2__X55 = __1th ), ( (__2__X56 = (struct expr *)__1m ), ( ((__0__X54 ||
# 580 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X54 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X54 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X54 ), ((unsigned
# 580 "/home/claude/cfront-3/src/simpl.cpp"
char )44 ), __2__X55 , (struct expr *)0 ) ), (__0__X54 -> __O4__4expr.mem = __2__X56 )) :0 ), __0__X54 ) ) ) )
# 580 "/home/claude/cfront-3/src/simpl.cpp"
;
__2ee -> __O1__4expr.tp = __1m -> __O1__4expr.tp ;
__2ee = cdvec__FP4nameP4exprP8classdefT1iN22 ( vec_del_fct , __2ee , __3cl , __2dtor , 0 , (struct expr *)( (__0__X57 = 0 ), ( ((__0__X57 || (__0__X57 =
# 582 "/home/claude/cfront-3/src/simpl.cpp"
(struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival))) ))?( (__0__X57 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X57 ), (unsigned char
# 582 "/home/claude/cfront-3/src/simpl.cpp"
)150 , (struct expr *)0 , (struct expr *)0 ) ), (__0__X57 -> __O2__4expr.i1 = ((long long )__4i ))) :0 ), __0__X57 ) ) ,
# 582 "/home/claude/cfront-3/src/simpl.cpp"
(struct expr *)0 ) ;
check_visibility__FP4nameT1P8classdefP5tableT1 ( __2dtor , (struct name *)0 , ((struct classdef *)(((struct classdef *)__2dtor -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))), __1tbl , curr_fct ) ;

# 583 "/home/claude/cfront-3/src/simpl.cpp"
}

# 583 "/home/claude/cfront-3/src/simpl.cpp"
}
}
}

# 587 "/home/claude/cfront-3/src/simpl.cpp"
if (__2ee ){ 
# 588 "/home/claude/cfront-3/src/simpl.cpp"
Pstmt __3es ;

# 589 "/home/claude/cfront-3/src/simpl.cpp"
struct estmt *__0__X58 ;

# 589 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X59 ;

# 588 "/home/claude/cfront-3/src/simpl.cpp"
__3es = (struct stmt *)( (__0__X58 = 0 ), ( (__2__X59 = curloc ), ( ((__0__X58 || (__0__X58 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 588 "/home/claude/cfront-3/src/simpl.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X58 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X58 ), ((unsigned char )72 ), __2__X59 , ((struct
# 588 "/home/claude/cfront-3/src/simpl.cpp"
stmt *)0 )) ), (__0__X58 -> __O2__4stmt.e = __2ee )) :0 ), __0__X58 ) ) ) ;

# 590 "/home/claude/cfront-3/src/simpl.cpp"
__3es -> s_list__4stmt = del_list ;
del_list = __3es ;
if (__1dtail == 0 )__1dtail = __3es ;
}

# 593 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 597 "/home/claude/cfront-3/src/simpl.cpp"
{ Pexpr __1ee ;

# 601 "/home/claude/cfront-3/src/simpl.cpp"
Pbcl __1b ;
Pbcl __1t ;
Pbcl __1l ;

# 597 "/home/claude/cfront-3/src/simpl.cpp"
__1ee = 0 ;

# 601 "/home/claude/cfront-3/src/simpl.cpp"
__1b = 0 ;
__1t = 0 ;
__1l = __1cl -> baselist__8classdef ;
for(;__1l ;__1l = __1l -> next__6basecl ) { 
# 605 "/home/claude/cfront-3/src/simpl.cpp"
if (__1l -> base__4node != 77 ){ 
# 606 "/home/claude/cfront-3/src/simpl.cpp"
Pbcl __3x ;

# 607 "/home/claude/cfront-3/src/simpl.cpp"
register struct basecl *__0__X60 ;

# 607 "/home/claude/cfront-3/src/simpl.cpp"
struct classdef *__2__X61 ;

# 607 "/home/claude/cfront-3/src/simpl.cpp"
struct basecl *__2__X62 ;

# 607 "/home/claude/cfront-3/src/simpl.cpp"
struct node *__0__X9 ;

# 606 "/home/claude/cfront-3/src/simpl.cpp"
__3x = ( (__0__X60 = 0 ), ( (__2__X61 = __1l -> bclass__6basecl ), ( (__2__X62 = 0 ), ( ((__0__X60 || (__0__X60 =
# 606 "/home/claude/cfront-3/src/simpl.cpp"
(struct basecl *)__nw__FUl ( (size_t )(sizeof (struct basecl))) ))?( (__0__X60 = (struct basecl *)( (__0__X9 = (((struct node *)__0__X60 ))), (
# 606 "/home/claude/cfront-3/src/simpl.cpp"
((__0__X9 || (__0__X9 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X9 -> base__4node = 0 ), (__0__X9 ->
# 606 "/home/claude/cfront-3/src/simpl.cpp"
permanent__4node = 0 )) , (__0__X9 -> baseclass__4node = 0 )) :0 ), __0__X9 ) ) ), ( (__0__X60 -> baseclass__4node = 1 ),
# 606 "/home/claude/cfront-3/src/simpl.cpp"
( (__0__X60 -> bclass__6basecl = __2__X61 ), ( (__0__X60 -> next__6basecl = __2__X62 ), ( (__0__X60 -> promoted__6basecl = 0 ), ( (__0__X60 ->
# 606 "/home/claude/cfront-3/src/simpl.cpp"
init__6basecl = 0 ), ( (__0__X60 -> obj_offset__6basecl = (__0__X60 -> ptr_offset__6basecl = 0 )), (__0__X60 -> allocated__6basecl = 0 )) ) ) )
# 606 "/home/claude/cfront-3/src/simpl.cpp"
) ) ) :0 ), __0__X60 ) ) ) ) ;
if (__1t == 0 )
# 608 "/home/claude/cfront-3/src/simpl.cpp"
__1b = __3x ;
else 
# 610 "/home/claude/cfront-3/src/simpl.cpp"
__1t -> next__6basecl = __3x ;
__1t = __3x ;
__3x -> base__4node = __1l -> base__4node ;
__3x -> obj_offset__6basecl = __1l -> obj_offset__6basecl ;
}
}
for(__1l = __1cl -> baselist__8classdef ;__1l ;__1l = __1l -> next__6basecl ) { 
# 617 "/home/claude/cfront-3/src/simpl.cpp"
if (__1l -> base__4node == 77 ){ 
# 617 "/home/claude/cfront-3/src/simpl.cpp"
register struct basecl *__0__X63 ;

# 617 "/home/claude/cfront-3/src/simpl.cpp"
struct classdef *__2__X64 ;

# 617 "/home/claude/cfront-3/src/simpl.cpp"
struct basecl *__2__X65 ;

# 617 "/home/claude/cfront-3/src/simpl.cpp"
struct node *__0__X9 ;

# 618 "/home/claude/cfront-3/src/simpl.cpp"
__1b = ( (__0__X63 = 0 ), ( (__2__X64 = __1l -> bclass__6basecl ), ( (__2__X65 = __1b ), ( ((__0__X63 || (__0__X63 =
# 618 "/home/claude/cfront-3/src/simpl.cpp"
(struct basecl *)__nw__FUl ( (size_t )(sizeof (struct basecl))) ))?( (__0__X63 = (struct basecl *)( (__0__X9 = (((struct node *)__0__X63 ))), (
# 618 "/home/claude/cfront-3/src/simpl.cpp"
((__0__X9 || (__0__X9 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X9 -> base__4node = 0 ), (__0__X9 ->
# 618 "/home/claude/cfront-3/src/simpl.cpp"
permanent__4node = 0 )) , (__0__X9 -> baseclass__4node = 0 )) :0 ), __0__X9 ) ) ), ( (__0__X63 -> baseclass__4node = 1 ),
# 618 "/home/claude/cfront-3/src/simpl.cpp"
( (__0__X63 -> bclass__6basecl = __2__X64 ), ( (__0__X63 -> next__6basecl = __2__X65 ), ( (__0__X63 -> promoted__6basecl = 0 ), ( (__0__X63 ->
# 618 "/home/claude/cfront-3/src/simpl.cpp"
init__6basecl = 0 ), ( (__0__X63 -> obj_offset__6basecl = (__0__X63 -> ptr_offset__6basecl = 0 )), (__0__X63 -> allocated__6basecl = 0 )) ) ) )
# 618 "/home/claude/cfront-3/src/simpl.cpp"
) ) ) :0 ), __0__X63 ) ) ) ) ;
__1b -> base__4node = __1l -> base__4node ;
__1b -> obj_offset__6basecl = __1l -> obj_offset__6basecl ;
}
}

# 624 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1b ;__1b = __1l ) { 
# 625 "/home/claude/cfront-3/src/simpl.cpp"
Pclass __2bcl ;

# 625 "/home/claude/cfront-3/src/simpl.cpp"
__2bcl = __1b -> bclass__6basecl ;
__1l = __1b -> next__6basecl ;
{ Pname __2dtor ;

# 627 "/home/claude/cfront-3/src/simpl.cpp"
__2dtor = ( __2bcl -> c_dtor__8classdef ) ;

# 629 "/home/claude/cfront-3/src/simpl.cpp"
if (__2dtor ){ 
# 630 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __3val ;

# 630 "/home/claude/cfront-3/src/simpl.cpp"
__3val = rptr__FP4typeP4expri ( __2bcl -> this_type__8classdef , __1th , __1b -> obj_offset__6basecl ) ;
__3val = contents__4exprFv ( __3val ) ;
{ Pexpr __3e ;

# 632 "/home/claude/cfront-3/src/simpl.cpp"
__3e = call_dtor__FP4exprN21iT1 ( __3val , (struct expr *)__2dtor , (struct expr *)0 , 45 , (struct expr *)0 ) ;
if (__1b -> base__4node == 77 ){ 
# 635 "/home/claude/cfront-3/src/simpl.cpp"
{ { Pname __4dd ;

# 635 "/home/claude/cfront-3/src/simpl.cpp"
__4dd = __0this -> f_this__3fct -> __O1__4name.n_list ;

# 635 "/home/claude/cfront-3/src/simpl.cpp"
for(;__4dd != __0this -> argtype__3fct ;__4dd = __4dd -> __O1__4name.n_list ) 
# 636 "/home/claude/cfront-3/src/simpl.cpp"
if (strcmp ( __4dd -> __O2__4expr.string , __2bcl -> string__8classdef ) == 0 )break ;
# 636 "/home/claude/cfront-3/src/simpl.cpp"

# 638 "/home/claude/cfront-3/src/simpl.cpp"
if (ansi_opt ){ 
# 639 "/home/claude/cfront-3/src/simpl.cpp"
__3e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __3e , zero ) ;
__3e -> __O1__4expr.tp = (struct type *)zero_type ;
}
__3e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , __3e , zero ) ;
{ Pexpr __4two ;

# 644 "/home/claude/cfront-3/src/simpl.cpp"
struct ival *__0__X66 ;

# 643 "/home/claude/cfront-3/src/simpl.cpp"
__4two = (struct expr *)( (__0__X66 = 0 ), ( ((__0__X66 || (__0__X66 = (struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival)))
# 643 "/home/claude/cfront-3/src/simpl.cpp"
))?( (__0__X66 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X66 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 ) ),
# 643 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X66 -> __O2__4expr.i1 = ((long long )2 ))) :0 ), __0__X66 ) ) ;
__4two -> __O1__4expr.tp = (struct type *)int_type ;
__3e -> __O4__4expr.cond = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )52 , (struct expr *)__1free_arg , __4two ) ;

# 645 "/home/claude/cfront-3/src/simpl.cpp"
}

# 645 "/home/claude/cfront-3/src/simpl.cpp"
}

# 645 "/home/claude/cfront-3/src/simpl.cpp"
}
}
__1ee = (__1ee ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __3e , __1ee ) :__3e );

# 647 "/home/claude/cfront-3/src/simpl.cpp"
}
}
__dl__FPv ( (void *)__1b ) ;

# 649 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 652 "/home/claude/cfront-3/src/simpl.cpp"
{ Pstmt __1es ;

# 653 "/home/claude/cfront-3/src/simpl.cpp"
struct estmt *__0__X82 ;

# 653 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X83 ;

# 652 "/home/claude/cfront-3/src/simpl.cpp"
__1es = (struct stmt *)(__1ee ?( (__0__X82 = 0 ), ( (__2__X83 = curloc ), ( ((__0__X82 || (__0__X82 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 652 "/home/claude/cfront-3/src/simpl.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X82 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X82 ), ((unsigned char )72 ), __2__X83 , ((struct
# 652 "/home/claude/cfront-3/src/simpl.cpp"
stmt *)0 )) ), (__0__X82 -> __O2__4stmt.e = __1ee )) :0 ), __0__X82 ) ) ) :(((struct estmt *)0 )));

# 654 "/home/claude/cfront-3/src/simpl.cpp"
__1ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1th , (struct expr *)0 ) ;
{ Pname __1n ;
Pexpr __1del ;

# 657 "/home/claude/cfront-3/src/simpl.cpp"
struct call *__0__X68 ;

# 657 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X69 ;

# 657 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X70 ;

# 655 "/home/claude/cfront-3/src/simpl.cpp"
__1n = __ct__4nameFPCc ( (struct name *)0 , oper_name__FUc ( (unsigned char )9 ) ) ;
__1del = find_name__FP4nameP8classdefP5tableiT1 ( __1n , __1cl , scope , 109 , curr_fct ) ;
if ((__1del -> __O1__4expr.tp -> base__4node == 76 )|| ((((struct fct *)(((struct fct *)__1del -> __O1__4expr.tp ))))-> nargs__3fct == 2 )){ 
# 658 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __2ss ;

# 659 "/home/claude/cfront-3/src/simpl.cpp"
struct texpr *__0__X67 ;

# 658 "/home/claude/cfront-3/src/simpl.cpp"
__2ss = (struct expr *)( (__0__X67 = 0 ), ( ((__0__X67 || (__0__X67 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 658 "/home/claude/cfront-3/src/simpl.cpp"
))?( (__0__X67 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X67 ), ((unsigned char )30 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 658 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X67 -> __O4__4expr.tp2 = ((struct type *)__1cl ))) :0 ), __0__X67 ) ) ;
__2ss -> __O1__4expr.tp = (struct type *)uint_type ;
__1ee -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __2ss , (struct expr *)0 ) ;
}
__1ee = (struct expr *)( (__0__X68 = 0 ), ( (__2__X69 = __1del ), ( (__2__X70 = __1ee ), ( ((__0__X68 || (__0__X68 =
# 662 "/home/claude/cfront-3/src/simpl.cpp"
(struct call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X68 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X68 ), (unsigned char )109 ,
# 662 "/home/claude/cfront-3/src/simpl.cpp"
__2__X69 , __2__X70 ) ):0 ), __0__X68 ) ) ) ) ;
__1ee -> __O1__4expr.tp = call_fct__4exprFP5table ( __1ee , scope ) ;

# 665 "/home/claude/cfront-3/src/simpl.cpp"
{ Pstmt __1ess ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
register struct ifstmt *__0__X71 ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X72 ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X73 ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__2__X74 ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__2__X75 ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
register struct ifstmt *__0__X76 ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X77 ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__2__X78 ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__2__X79 ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
struct estmt *__0__X80 ;

# 666 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X81 ;

# 665 "/home/claude/cfront-3/src/simpl.cpp"
__1ess = (struct stmt *)( (__0__X80 = 0 ), ( (__2__X81 = curloc ), ( ((__0__X80 || (__0__X80 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 665 "/home/claude/cfront-3/src/simpl.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X80 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X80 ), ((unsigned char )72 ), __2__X81 , ((struct
# 665 "/home/claude/cfront-3/src/simpl.cpp"
stmt *)0 )) ), (__0__X80 -> __O2__4stmt.e = __1ee )) :0 ), __0__X80 ) ) ) ;
__1ess = (struct stmt *)( (__0__X71 = 0 ), ( (__2__X72 = curloc ), ( (__2__X73 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned
# 666 "/home/claude/cfront-3/src/simpl.cpp"
char )52 , (struct expr *)__1free_arg , one ) ), ( (__2__X74 = __1ess ), ( (__2__X75 = 0 ), ( ((__0__X71 ||
# 666 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X71 = (struct ifstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct ifstmt))) ))?( (__0__X71 = (struct ifstmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X71 ), (unsigned
# 666 "/home/claude/cfront-3/src/simpl.cpp"
char )20 , __2__X72 , __2__X74 ) ), ( (__0__X71 -> __O2__4stmt.e = __2__X73 ), (__0__X71 -> __O3__4stmt.else_stmt = __2__X75 )) ) :0 ),
# 666 "/home/claude/cfront-3/src/simpl.cpp"
__0__X71 ) ) ) ) ) ) ;
if (__1es )
# 668 "/home/claude/cfront-3/src/simpl.cpp"
__1es -> s_list__4stmt = __1ess ;
else 
# 670 "/home/claude/cfront-3/src/simpl.cpp"
__1es = __1ess ;

# 672 "/home/claude/cfront-3/src/simpl.cpp"
( (__1free_arg -> n_used__4name ++ ), (((void )0 ))) ;
( ((((struct name *)(((struct name *)__1th ))))-> n_used__4name ++ ), (((void )0 ))) ;

# 675 "/home/claude/cfront-3/src/simpl.cpp"
if (__1dtail )
# 676 "/home/claude/cfront-3/src/simpl.cpp"
__1dtail -> s_list__4stmt = __1es ;
else 
# 678 "/home/claude/cfront-3/src/simpl.cpp"
del_list = __1es ;

# 681 "/home/claude/cfront-3/src/simpl.cpp"
if (! perf_opt )
# 682 "/home/claude/cfront-3/src/simpl.cpp"
del_list = (struct stmt *)( (__0__X76 = 0 ), ( (__2__X77 = curloc ), ( (__2__X78 = del_list ), (
# 682 "/home/claude/cfront-3/src/simpl.cpp"
(__2__X79 = 0 ), ( ((__0__X76 || (__0__X76 = (struct ifstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct ifstmt))) ))?( (__0__X76 = (struct
# 682 "/home/claude/cfront-3/src/simpl.cpp"
ifstmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X76 ), (unsigned char )20 , __2__X77 , __2__X78 ) ), ( (__0__X76 -> __O2__4stmt.e = __1th ), (__0__X76 ->
# 682 "/home/claude/cfront-3/src/simpl.cpp"
__O3__4stmt.else_stmt = __2__X79 )) ) :0 ), __0__X76 ) ) ) ) ) ;
if (del_list )simpl__4stmtFv ( del_list ) ;
return __1dtail ;

# 684 "/home/claude/cfront-3/src/simpl.cpp"
}

# 684 "/home/claude/cfront-3/src/simpl.cpp"
}

# 684 "/home/claude/cfront-3/src/simpl.cpp"
}

# 684 "/home/claude/cfront-3/src/simpl.cpp"
}

# 684 "/home/claude/cfront-3/src/simpl.cpp"
}

# 684 "/home/claude/cfront-3/src/simpl.cpp"
}

# 684 "/home/claude/cfront-3/src/simpl.cpp"
}

# 684 "/home/claude/cfront-3/src/simpl.cpp"
}

# 684 "/home/claude/cfront-3/src/simpl.cpp"
}

# 684 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 688 "/home/claude/cfront-3/src/simpl.cpp"
Pclass find_vbase_ptr__FP8classdefT1 (Pclass __1cl , Pclass __1vbase );

# 688 "/home/claude/cfront-3/src/simpl.cpp"
Pclass find_vbase_ptr__FP8classdefT1 (Pclass __1cl , Pclass __1vbase )
# 689 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 690 "/home/claude/cfront-3/src/simpl.cpp"
{ { Pbcl __1bb ;

# 690 "/home/claude/cfront-3/src/simpl.cpp"
__1bb = __1cl -> baselist__8classdef ;

# 690 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1bb ;__1bb = __1bb -> next__6basecl ) { 
# 691 "/home/claude/cfront-3/src/simpl.cpp"
if (__1bb -> base__4node == 77 ){ 
# 691 "/home/claude/cfront-3/src/simpl.cpp"
struct classdef *__1__X84 ;

# 691 "/home/claude/cfront-3/src/simpl.cpp"
struct classdef *__1__X85 ;

# 692 "/home/claude/cfront-3/src/simpl.cpp"
if (( (__1__X84 = __1bb -> bclass__6basecl ), ( (__1__X85 = __1vbase ), ( ((__1__X84 == __1__X85 )?1 :((__1__X84 && __1__X85 )?(((int )same_class__8classdefFP8classdefi ( __1__X84 ,
# 692 "/home/claude/cfront-3/src/simpl.cpp"
__1__X85 , 0 ) )):0 ))) ) ) && __1bb -> ptr_offset__6basecl )return __1cl ;
}
else { 
# 695 "/home/claude/cfront-3/src/simpl.cpp"
Pclass __3f ;

# 695 "/home/claude/cfront-3/src/simpl.cpp"
__3f = find_vbase_ptr__FP8classdefT1 ( __1bb -> bclass__6basecl , __1vbase ) ;
if (__3f )return __3f ;
}
}
return (struct classdef *)0 ;

# 699 "/home/claude/cfront-3/src/simpl.cpp"
}

# 699 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 702 "/home/claude/cfront-3/src/simpl.cpp"
Pclass second_base__FP8classdefT1 (Pclass __1cl , Pclass __1base );

# 702 "/home/claude/cfront-3/src/simpl.cpp"
Pclass second_base__FP8classdefT1 (Pclass __1cl , Pclass __1base )
# 703 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 705 "/home/claude/cfront-3/src/simpl.cpp"
{ { Pbcl __1b ;

# 705 "/home/claude/cfront-3/src/simpl.cpp"
__1b = __1cl -> baselist__8classdef ;

# 705 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1b && (__1b -> base__4node == 85 );__1b = __1b -> next__6basecl ) { 
# 705 "/home/claude/cfront-3/src/simpl.cpp"
struct classdef *__1__X86 ;

# 705 "/home/claude/cfront-3/src/simpl.cpp"
struct classdef *__1__X87 ;

# 706 "/home/claude/cfront-3/src/simpl.cpp"
if (( (__1__X86 = __1b -> bclass__6basecl ), ( (__1__X87 = __1base ), ( ((__1__X86 == __1__X87 )?1 :((__1__X86 && __1__X87 )?(((int )same_class__8classdefFP8classdefi ( __1__X86 ,
# 706 "/home/claude/cfront-3/src/simpl.cpp"
__1__X87 , 0 ) )):0 ))) ) ) ){ 
# 707 "/home/claude/cfront-3/src/simpl.cpp"
if (__1b == __1cl -> baselist__8classdef )return (struct classdef *)0 ;
return __1base ;
}
{ Pclass __2bb ;

# 710 "/home/claude/cfront-3/src/simpl.cpp"
__2bb = second_base__FP8classdefT1 ( __1b -> bclass__6basecl , __1base ) ;
if (__2bb == (((struct classdef *)-1)))continue ;
if (__2bb ){ 
# 713 "/home/claude/cfront-3/src/simpl.cpp"
if (__1b != __1cl -> baselist__8classdef )error__FiPCc ( (int )'s' , (const char *)"C hierarchy too complicated")
# 713 "/home/claude/cfront-3/src/simpl.cpp"
;
return __2bb ;
}
if (__1b == __1cl -> baselist__8classdef )return (struct classdef *)0 ;
return __1b -> bclass__6basecl ;

# 717 "/home/claude/cfront-3/src/simpl.cpp"
}
}
return (((struct classdef *)-1));

# 719 "/home/claude/cfront-3/src/simpl.cpp"
}

# 719 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 477 "/home/claude/cfront-3/src/cfront.h"
void print_all_vtbls__8classdefFP8classdef (struct classdef *__0this , Pclass );

# 58 "/home/claude/cfront-3/src/simpl.cpp"
extern Pname find_vptr__FP8classdef (Pclass );

# 484 "/home/claude/cfront-3/src/cfront.h"
Pbcl get_base__8classdefFPCc (struct classdef *__0this , const char *);

# 59 "/home/claude/cfront-3/src/simpl.cpp"
extern const char *get_classname__FPCc (const char *);

# 724 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr get_vptr_exp__8classdefFPCc (struct classdef *__0this , const char *__1s );

# 60 "/home/claude/cfront-3/src/simpl.cpp"
extern const char *drop_classname__FPCc (const char *);

# 848 "/home/claude/cfront-3/src/cfront.h"

# 724 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr get_vptr_exp__8classdefFPCc (register struct classdef *__0this , const char *__1s )
# 725 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 727 "/home/claude/cfront-3/src/simpl.cpp"
if (__0this -> c_body__8classdef == 1 )dcl_print__8classdefFP4name ( __0this , (struct name *)0 ) ;
# 727 "/home/claude/cfront-3/src/simpl.cpp"

# 728 "/home/claude/cfront-3/src/simpl.cpp"
if (__0this -> c_body__8classdef == 3 )print_all_vtbls__8classdefFP8classdef ( __0this , __0this ) ;
if (__1s == 0 )return (struct expr *)find_vptr__FP8classdef ( __0this ) ;
{ Pbcl __1b ;

# 730 "/home/claude/cfront-3/src/simpl.cpp"
__1b = get_base__8classdefFPCc ( __0this , get_classname__FPCc ( __1s ) ) ;
if (strcmp ( __1s , __1b -> bclass__6basecl -> string__8classdef ) == 0 )__1s = 0 ;
{ Pexpr __1vp ;

# 733 "/home/claude/cfront-3/src/simpl.cpp"
register struct mdot *__0__X88 ;

# 733 "/home/claude/cfront-3/src/simpl.cpp"
const char *__2__X89 ;

# 732 "/home/claude/cfront-3/src/simpl.cpp"
__1vp = get_vptr_exp__8classdefFPCc ( __1b -> bclass__6basecl , __1s ?drop_classname__FPCc ( __1s ) :(((const char *)0 ))) ;
if ((__1b == __0this -> baselist__8classdef )&& (__1b -> base__4node != 77 ))return __1vp ;
__1vp = (struct expr *)( (__0__X88 = 0 ), ( (__2__X89 = __1b -> bclass__6basecl -> string__8classdef ), ( ((__0__X88 || (__0__X88 = (struct
# 734 "/home/claude/cfront-3/src/simpl.cpp"
mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot))) ))?( (__0__X88 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X88 ), (unsigned char )177 ,
# 734 "/home/claude/cfront-3/src/simpl.cpp"
(struct expr *)0 , (struct expr *)0 ) ), ( (__0__X88 -> __O3__4expr.string2 = __2__X89 ), (__0__X88 -> __O4__4expr.mem = __1vp )) ) :0 ),
# 734 "/home/claude/cfront-3/src/simpl.cpp"
__0__X88 ) ) ) ;
if (__0this -> c_body__8classdef == 1 )dcl_print__8classdefFP4name ( __1b -> bclass__6basecl , (struct name *)0 ) ;
if (__0this -> c_body__8classdef == 3 )print_all_vtbls__8classdefFP8classdef ( __1b -> bclass__6basecl , __1b -> bclass__6basecl ) ;
if (__1b -> base__4node == 77 ){ 
# 738 "/home/claude/cfront-3/src/simpl.cpp"
__1vp -> __O2__4expr.i1 = 1 ;
if (__1b -> ptr_offset__6basecl == 0 ){ 
# 740 "/home/claude/cfront-3/src/simpl.cpp"
Pclass __3bb ;
Pclass __3sb ;

# 742 "/home/claude/cfront-3/src/simpl.cpp"
register struct mdot *__0__X90 ;

# 742 "/home/claude/cfront-3/src/simpl.cpp"
const char *__2__X91 ;

# 740 "/home/claude/cfront-3/src/simpl.cpp"
__3bb = find_vbase_ptr__FP8classdefT1 ( __0this , __1b -> bclass__6basecl ) ;
__3sb = second_base__FP8classdefT1 ( topclass , __3bb ) ;

# 743 "/home/claude/cfront-3/src/simpl.cpp"
if (__3sb && (__3sb != (((struct classdef *)-1))))__1vp = (struct expr *)( (__0__X90 = 0 ), ( (__2__X91 = __3sb -> string__8classdef ), (
# 743 "/home/claude/cfront-3/src/simpl.cpp"
((__0__X90 || (__0__X90 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot))) ))?( (__0__X90 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X90 ),
# 743 "/home/claude/cfront-3/src/simpl.cpp"
(unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ), ( (__0__X90 -> __O3__4expr.string2 = __2__X91 ), (__0__X90 -> __O4__4expr.mem =
# 743 "/home/claude/cfront-3/src/simpl.cpp"
__1vp )) ) :0 ), __0__X90 ) ) ) ;
}
}
return __1vp ;

# 746 "/home/claude/cfront-3/src/simpl.cpp"
}

# 746 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 943 "/home/claude/cfront-3/src/cfront.h"
void assign__4nameFv (struct name *__0this );

# 834 "/home/claude/cfront-3/src/cfront.h"
void simpl__4callFv (struct call *__0this );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 848 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 852 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 470 "/home/claude/cfront-3/src/cfront.h"
Pname has_ictor__8classdefFv (struct classdef *__0this );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 469 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 749 "/home/claude/cfront-3/src/simpl.cpp"
int ctor_simpl__3fctFP8classdefP4expr (register struct fct *__0this , Pclass __1cl , Pexpr __1th )
# 750 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 751 "/home/claude/cfront-3/src/simpl.cpp"
Ptable __1tbl ;

# 753 "/home/claude/cfront-3/src/simpl.cpp"
int __1ass_count ;

# 751 "/home/claude/cfront-3/src/simpl.cpp"
__1tbl = __1cl -> memtbl__8classdef ;

# 753 "/home/claude/cfront-3/src/simpl.cpp"
__1ass_count = 0 ;
init_list = 0 ;

# 766 "/home/claude/cfront-3/src/simpl.cpp"
{ { Pbcl __1l ;

# 766 "/home/claude/cfront-3/src/simpl.cpp"
__1l = __1cl -> baselist__8classdef ;

# 766 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1l ;__1l = __1l -> next__6basecl ) { 
# 767 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __2i ;

# 767 "/home/claude/cfront-3/src/simpl.cpp"
__2i = __1l -> init__6basecl ;

# 770 "/home/claude/cfront-3/src/simpl.cpp"
if (__1l -> base__4node != 77 )continue ;
__1l -> init__6basecl = 0 ;

# 775 "/home/claude/cfront-3/src/simpl.cpp"
{ Pclass __2bc ;
Pexpr __2dp ;

# 780 "/home/claude/cfront-3/src/simpl.cpp"
Pname __2dd ;

# 775 "/home/claude/cfront-3/src/simpl.cpp"
__2bc = __1l -> bclass__6basecl ;
__2dp = 0 ;

# 780 "/home/claude/cfront-3/src/simpl.cpp"
__2dd = __0this -> f_this__3fct -> __O1__4name.n_list ;
for(;__2dd != __0this -> argtype__3fct ;__2dd = __2dd -> __O1__4name.n_list ) 
# 782 "/home/claude/cfront-3/src/simpl.cpp"
if (strcmp ( __2dd -> __O2__4expr.string , __2bc -> string__8classdef ) == 0 )break ;
# 782 "/home/claude/cfront-3/src/simpl.cpp"

# 787 "/home/claude/cfront-3/src/simpl.cpp"
{ int __2off ;
Pexpr __2val ;

# 787 "/home/claude/cfront-3/src/simpl.cpp"
__2off = __1l -> obj_offset__6basecl ;
__2val = rptr__FP4typeP4expri ( __2bc -> this_type__8classdef , __1th , __2off ) ;
__2dp = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__2dd , __2val ) ;
assign__4nameFv ( __2dd ) ;

# 793 "/home/claude/cfront-3/src/simpl.cpp"
if (__2i ){ 
# 795 "/home/claude/cfront-3/src/simpl.cpp"
switch (__2i -> base__4node ){ 
# 795 "/home/claude/cfront-3/src/simpl.cpp"
unsigned long __2__X100 ;

# 796 "/home/claude/cfront-3/src/simpl.cpp"
case 70 :
# 797 "/home/claude/cfront-3/src/simpl.cpp"
case 71 :
# 798 "/home/claude/cfront-3/src/simpl.cpp"
simpl__4exprFv ( __2i ) ;
break ;
case 109 :
# 801 "/home/claude/cfront-3/src/simpl.cpp"
case 146 :
# 802 "/home/claude/cfront-3/src/simpl.cpp"
{ Pcall __5cc ;
Pname __5bn ;

# 802 "/home/claude/cfront-3/src/simpl.cpp"
__5cc = (((struct call *)(((struct call *)__2i ))));
__5bn = __5cc -> __O4__4expr.fct_name ;
__1ass_count = (((struct fct *)(((struct fct *)__5bn -> __O1__4expr.tp ))))-> f_this__3fct -> n_assigned_to__4name ;
simpl__4callFv ( __5cc ) ;
break ;
}
default :
# 809 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 809 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V92 ;

# 809 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"badBCIr %k", (const struct ea *)( (__2__X100 =
# 809 "/home/claude/cfront-3/src/simpl.cpp"
__2i -> base__4node ), ( (( ((& __0__V92 )-> __O1__2ea.i = __2__X100 ), 0 ) ), (& __0__V92 )) ) ,
# 809 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
__2dp = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __2dp , __2i ) ;
}

# 815 "/home/claude/cfront-3/src/simpl.cpp"
{ { Pname __2a ;

# 815 "/home/claude/cfront-3/src/simpl.cpp"
__2a = __0this -> f_args__3fct -> __O1__4name.n_list ;

# 815 "/home/claude/cfront-3/src/simpl.cpp"
for(;__2a ;__2a = __2a -> __O1__4name.n_list ) 
# 816 "/home/claude/cfront-3/src/simpl.cpp"
if (strcmp ( __2bc -> string__8classdef , __2a -> __O2__4expr.string ) == 0 ){ 
# 817 "/home/claude/cfront-3/src/simpl.cpp"
__2dp = __ct__4exprFUcP4exprT2 ( (struct
# 817 "/home/claude/cfront-3/src/simpl.cpp"
expr *)0 , (unsigned char )68 , __2dp , (struct expr *)__2a ) ;
__2dp -> __O4__4expr.cond = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )62 , (struct expr *)__2a , zero ) ;
break ;
}

# 823 "/home/claude/cfront-3/src/simpl.cpp"
{ { Pbcl __2ll ;

# 823 "/home/claude/cfront-3/src/simpl.cpp"
__2ll = __1cl -> baselist__8classdef ;

# 823 "/home/claude/cfront-3/src/simpl.cpp"
for(;__2ll ;__2ll = __2ll -> next__6basecl ) { 
# 823 "/home/claude/cfront-3/src/simpl.cpp"
struct classdef *__1__X101 ;

# 823 "/home/claude/cfront-3/src/simpl.cpp"
struct classdef *__1__X102 ;

# 824 "/home/claude/cfront-3/src/simpl.cpp"
if (( (__1__X101 = __2ll -> bclass__6basecl ), ( (__1__X102 = __2bc ), ( ((__1__X101 == __1__X102 )?1 :((__1__X101 && __1__X102 )?(((int )same_class__8classdefFP8classdefi ( __1__X101 ,
# 824 "/home/claude/cfront-3/src/simpl.cpp"
__1__X102 , 0 ) )):0 ))) ) ) && __2ll -> ptr_offset__6basecl ){ 
# 829 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __4dpp ;

# 830 "/home/claude/cfront-3/src/simpl.cpp"
register struct mdot *__0__X103 ;

# 830 "/home/claude/cfront-3/src/simpl.cpp"
const char *__2__X104 ;

# 829 "/home/claude/cfront-3/src/simpl.cpp"
__4dpp = (struct expr *)( (__0__X103 = 0 ), ( (__2__X104 = __2bc -> string__8classdef ), ( ((__0__X103 || (__0__X103 = (struct mdot *)__nw__4exprSFUl (
# 829 "/home/claude/cfront-3/src/simpl.cpp"
(size_t )(sizeof (struct mdot))) ))?( (__0__X103 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X103 ), (unsigned char )177 , (struct
# 829 "/home/claude/cfront-3/src/simpl.cpp"
expr *)0 , (struct expr *)0 ) ), ( (__0__X103 -> __O3__4expr.string2 = __2__X104 ), (__0__X103 -> __O4__4expr.mem = __1th )) ) :0 ), __0__X103 )
# 829 "/home/claude/cfront-3/src/simpl.cpp"
) ) ;
__4dpp -> __O2__4expr.i1 = 3 ;
__2dp = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __4dpp , __2dp ) ;

# 833 "/home/claude/cfront-3/src/simpl.cpp"
break ;
}
}

# 838 "/home/claude/cfront-3/src/simpl.cpp"
if (__2dp )init_list = (init_list ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __2dp , init_list ) :__2dp );

# 838 "/home/claude/cfront-3/src/simpl.cpp"
}

# 838 "/home/claude/cfront-3/src/simpl.cpp"
}

# 838 "/home/claude/cfront-3/src/simpl.cpp"
}

# 838 "/home/claude/cfront-3/src/simpl.cpp"
}

# 838 "/home/claude/cfront-3/src/simpl.cpp"
}

# 838 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 842 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 843 "/home/claude/cfront-3/src/simpl.cpp"
{ { Pbcl __2l ;

# 843 "/home/claude/cfront-3/src/simpl.cpp"
__2l = __1cl -> baselist__8classdef ;

# 843 "/home/claude/cfront-3/src/simpl.cpp"
for(;__2l ;__2l = __2l -> next__6basecl ) { 
# 844 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __3i ;

# 844 "/home/claude/cfront-3/src/simpl.cpp"
__3i = __2l -> init__6basecl ;
if ((__3i == 0 )|| (__2l -> base__4node == 77 ))continue ;

# 847 "/home/claude/cfront-3/src/simpl.cpp"
__2l -> init__6basecl = 0 ;

# 849 "/home/claude/cfront-3/src/simpl.cpp"
switch (__3i -> base__4node ){ 
# 849 "/home/claude/cfront-3/src/simpl.cpp"
unsigned long __2__X105 ;

# 850 "/home/claude/cfront-3/src/simpl.cpp"
case 70 :
# 851 "/home/claude/cfront-3/src/simpl.cpp"
case 71 :
# 852 "/home/claude/cfront-3/src/simpl.cpp"
simpl__4exprFv ( __3i ) ;
break ;
case 109 :
# 855 "/home/claude/cfront-3/src/simpl.cpp"
case 146 :
# 856 "/home/claude/cfront-3/src/simpl.cpp"
{ Pcall __5cc ;
Pname __5bn ;

# 856 "/home/claude/cfront-3/src/simpl.cpp"
__5cc = (((struct call *)(((struct call *)__3i ))));
__5bn = __5cc -> __O4__4expr.fct_name ;
__1ass_count = (((struct fct *)(((struct fct *)__5bn -> __O1__4expr.tp ))))-> f_this__3fct -> n_assigned_to__4name ;
simpl__4callFv ( __5cc ) ;

# 861 "/home/claude/cfront-3/src/simpl.cpp"
if ((__2l == __1cl -> baselist__8classdef )&& (__1cl -> baselist__8classdef -> next__6basecl == 0 ))__3i = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 ,
# 861 "/home/claude/cfront-3/src/simpl.cpp"
__1th , (struct expr *)__5cc ) ;
break ;
}
default :
# 865 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 865 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V93 ;

# 865 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"badBCIr %k", (const struct ea *)( (__2__X105 =
# 865 "/home/claude/cfront-3/src/simpl.cpp"
__3i -> base__4node ), ( (( ((& __0__V93 )-> __O1__2ea.i = __2__X105 ), 0 ) ), (& __0__V93 )) ) ,
# 865 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 868 "/home/claude/cfront-3/src/simpl.cpp"
init_list = (init_list ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , init_list , __3i ) :__3i );
}

# 869 "/home/claude/cfront-3/src/simpl.cpp"
}

# 869 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 873 "/home/claude/cfront-3/src/simpl.cpp"
{ { Pvirt __1blist ;

# 897 "/home/claude/cfront-3/src/simpl.cpp"
int __1i ;

# 873 "/home/claude/cfront-3/src/simpl.cpp"
__1blist = __1cl -> virt_list__8classdef ;

# 873 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1blist ;__1blist = __1blist -> next__4virt ) { 
# 879 "/home/claude/cfront-3/src/simpl.cpp"
topclass = __1cl ;
{ Pexpr __2vp ;

# 882 "/home/claude/cfront-3/src/simpl.cpp"
char *__2str ;
const char *__2cs ;

# 880 "/home/claude/cfront-3/src/simpl.cpp"
__2vp = get_vptr_exp__8classdefFPCc ( __1cl , __1blist -> string__4virt ) ;

# 882 "/home/claude/cfront-3/src/simpl.cpp"
__2str = 0 ;
__2cs = (__1cl -> nested_sig__4type ?(((const char *)__1cl -> nested_sig__4type )):__1cl -> string__8classdef );
if (__1cl -> lex_level__4type && (__1cl -> nested_sig__4type == 0 )){ 
# 885 "/home/claude/cfront-3/src/simpl.cpp"
__2str = (((char *)__nw__FUl ( (size_t)((sizeof (char ))*
# 885 "/home/claude/cfront-3/src/simpl.cpp"
(__1cl -> c_strlen__8classdef + 1 ))) ));
strcpy ( __2str , (const char *)__1cl -> local_sig__4type ) ;
}
{ Pexpr __2vtbl ;

# 890 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __2ee ;

# 891 "/home/claude/cfront-3/src/simpl.cpp"
register struct text_expr *__0__X106 ;

# 891 "/home/claude/cfront-3/src/simpl.cpp"
const char *__2__X107 ;

# 891 "/home/claude/cfront-3/src/simpl.cpp"
const char *__2__X108 ;

# 891 "/home/claude/cfront-3/src/simpl.cpp"
struct ref *__0__X109 ;

# 891 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X110 ;

# 891 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X111 ;

# 888 "/home/claude/cfront-3/src/simpl.cpp"
__2vtbl = (struct expr *)( (__0__X106 = 0 ), ( (__2__X107 = __1blist -> string__4virt ), ( (__2__X108 = (__2str ?(((const char *)__2str )):__2cs )),
# 888 "/home/claude/cfront-3/src/simpl.cpp"
( ((__0__X106 || (__0__X106 = (struct text_expr *)__nw__4exprSFUl ( (size_t )(sizeof (struct text_expr))) ))?( (__0__X106 = (struct text_expr *)__ct__4exprFUcP4exprT2 ( ((struct
# 888 "/home/claude/cfront-3/src/simpl.cpp"
expr *)__0__X106 ), (unsigned char )165 , (struct expr *)0 , (struct expr *)0 ) ), ( (__0__X106 -> __O2__4expr.string = __2__X107 ), (__0__X106 ->
# 888 "/home/claude/cfront-3/src/simpl.cpp"
__O3__4expr.string2 = __2__X108 )) ) :0 ), __0__X106 ) ) ) ) ;

# 890 "/home/claude/cfront-3/src/simpl.cpp"
__2ee = (struct expr *)( (__0__X109 = 0 ), ( (__2__X110 = __1th ), ( (__2__X111 = __2vp ), ( ((__0__X109 || (__0__X109 =
# 890 "/home/claude/cfront-3/src/simpl.cpp"
(struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X109 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X109 ), ((unsigned char
# 890 "/home/claude/cfront-3/src/simpl.cpp"
)44 ), __2__X110 , (struct expr *)0 ) ), (__0__X109 -> __O4__4expr.mem = __2__X111 )) :0 ), __0__X109 ) ) ) ) ;
# 890 "/home/claude/cfront-3/src/simpl.cpp"

# 891 "/home/claude/cfront-3/src/simpl.cpp"
__2ee -> __O1__4expr.tp = __2vp -> __O1__4expr.tp ;
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __2ee , __2vtbl ) ;
init_list = (init_list ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , init_list , __2ee ) :__2ee );

# 893 "/home/claude/cfront-3/src/simpl.cpp"
}

# 893 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 897 "/home/claude/cfront-3/src/simpl.cpp"
;
{ { Pname __1m ;

# 899 "/home/claude/cfront-3/src/simpl.cpp"
int __2__X112 ;

# 899 "/home/claude/cfront-3/src/simpl.cpp"
int __2__X119 ;

# 898 "/home/claude/cfront-3/src/simpl.cpp"
__1m = ( (__2__X119 = (__1i = 1 )), ( (((__2__X119 <= 0 )|| (__1tbl -> free_slot__5table <= __2__X119 ))?(((struct name *)0 )):(__1tbl -> entries__5table [__2__X119 ]))) )
# 898 "/home/claude/cfront-3/src/simpl.cpp"
;

# 898 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1m ;__1m = (__1m -> n_tbl_list__4name ?__1m -> n_tbl_list__4name :( (__2__X112 = (++ __1i )), ( (((__2__X112 <= 0 )|| (__1tbl -> free_slot__5table <= __2__X112 ))?(((struct name *)0 )):(__1tbl ->
# 898 "/home/claude/cfront-3/src/simpl.cpp"
entries__5table [__2__X112 ]))) ) )) { 
# 899 "/home/claude/cfront-3/src/simpl.cpp"
if (__1m -> base__4node == 123 )continue ;
{ Ptype __2t ;
Pname __2cn ;
Pname __2ctor ;

# 900 "/home/claude/cfront-3/src/simpl.cpp"
__2t = __1m -> __O1__4expr.tp ;

# 903 "/home/claude/cfront-3/src/simpl.cpp"
if (__2t == 0 )continue ;

# 905 "/home/claude/cfront-3/src/simpl.cpp"
switch (__2t -> base__4node ){ 
# 906 "/home/claude/cfront-3/src/simpl.cpp"
case 108 :
# 907 "/home/claude/cfront-3/src/simpl.cpp"
case 76 :
# 908 "/home/claude/cfront-3/src/simpl.cpp"
case 6 :
# 909 "/home/claude/cfront-3/src/simpl.cpp"
case 13 :
# 910 "/home/claude/cfront-3/src/simpl.cpp"
continue ;
}

# 913 "/home/claude/cfront-3/src/simpl.cpp"
switch (__1m -> n_stclass__4name ){ 
# 914 "/home/claude/cfront-3/src/simpl.cpp"
case 31 :
# 915 "/home/claude/cfront-3/src/simpl.cpp"
case 13 :
# 916 "/home/claude/cfront-3/src/simpl.cpp"
continue ;
}

# 919 "/home/claude/cfront-3/src/simpl.cpp"
if (__1m -> base__4node == 25 )continue ;

# 921 "/home/claude/cfront-3/src/simpl.cpp"
{ Pexpr __2ee ;

# 921 "/home/claude/cfront-3/src/simpl.cpp"
__2ee = __1m -> __O3__4expr.n_initializer ;
if (__2ee )__1m -> __O3__4expr.n_initializer = 0 ;

# 924 "/home/claude/cfront-3/src/simpl.cpp"
if (__2ee ){ 
# 927 "/home/claude/cfront-3/src/simpl.cpp"
}
else if (__2cn = is_cl_obj__4typeFv ( __2t ) ){ 
# 929 "/home/claude/cfront-3/src/simpl.cpp"
Pclass __3cl ;

# 929 "/home/claude/cfront-3/src/simpl.cpp"
__3cl = (((struct classdef *)(((struct classdef *)__2cn -> __O1__4expr.tp ))));
if (__2ctor = has_ictor__8classdefFv ( __3cl ) ){ 
# 931 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __4r ;

# 932 "/home/claude/cfront-3/src/simpl.cpp"
struct ref *__0__X113 ;

# 932 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X114 ;

# 932 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X115 ;

# 931 "/home/claude/cfront-3/src/simpl.cpp"
__4r = (struct expr *)( (__0__X113 = 0 ), ( (__2__X114 = __1th ), ( (__2__X115 = (struct expr *)__1m ), ( ((__0__X113 ||
# 931 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X113 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X113 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X113 ), ((unsigned
# 931 "/home/claude/cfront-3/src/simpl.cpp"
char )44 ), __2__X114 , (struct expr *)0 ) ), (__0__X113 -> __O4__4expr.mem = __2__X115 )) :0 ), __0__X113 ) ) ) )
# 931 "/home/claude/cfront-3/src/simpl.cpp"
;
__2ee = call_ctor__FP5tableP4exprN22iT2 ( __1tbl , __4r , (struct expr *)__2ctor , (struct expr *)0 , 45 , (struct expr *)0 ) ;
check_visibility__FP4nameT1P8classdefP5tableT1 ( __2ctor , (struct name *)0 , ((struct classdef *)(((struct classdef *)__2ctor -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))), __1tbl , curr_fct ) ;
}
else if (( __3cl -> c_ctor__8classdef ) ){ 
# 936 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 936 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V94 ;

# 936 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V95 ;

# 936 "/home/claude/cfront-3/src/simpl.cpp"
error__FPCcRC2eaN32 ( (const char *)"M%n needsIr (no defaultK forC %s)", (const struct ea *)( ((& __0__V94 )-> __O1__2ea.p =
# 936 "/home/claude/cfront-3/src/simpl.cpp"
((const void *)__1m )), (& __0__V94 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V95 , (const void *)__3cl ->
# 936 "/home/claude/cfront-3/src/simpl.cpp"
string__8classdef ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
else if (cl_obj_vec ){ 
# 940 "/home/claude/cfront-3/src/simpl.cpp"
Pclass __3cl ;

# 940 "/home/claude/cfront-3/src/simpl.cpp"
__3cl = (((struct classdef *)(((struct classdef *)cl_obj_vec -> __O1__4expr.tp ))));
if (__2ctor = has_ictor__8classdefFv ( __3cl ) ){ 
# 942 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __4mm ;

# 943 "/home/claude/cfront-3/src/simpl.cpp"
struct ref *__0__X116 ;

# 943 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X117 ;

# 943 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X118 ;

# 942 "/home/claude/cfront-3/src/simpl.cpp"
__4mm = (struct expr *)( (__0__X116 = 0 ), ( (__2__X117 = __1th ), ( (__2__X118 = (struct expr *)__1m ), ( ((__0__X116 ||
# 942 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X116 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X116 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X116 ), ((unsigned
# 942 "/home/claude/cfront-3/src/simpl.cpp"
char )44 ), __2__X117 , (struct expr *)0 ) ), (__0__X116 -> __O4__4expr.mem = __2__X118 )) :0 ), __0__X116 ) ) ) )
# 942 "/home/claude/cfront-3/src/simpl.cpp"
;
__4mm -> __O1__4expr.tp = __1m -> __O1__4expr.tp ;

# 945 "/home/claude/cfront-3/src/simpl.cpp"
{ Pname __4vctor ;

# 945 "/home/claude/cfront-3/src/simpl.cpp"
__4vctor = ( __3cl -> c_vtor__8classdef ) ;
__2ee = cdvec__FP4nameP4exprP8classdefT1iN22 ( vec_new_fct , __4mm , __3cl , __4vctor ?__4vctor :__2ctor , -1, (struct expr *)0 , (struct expr *)0 ) ;
check_visibility__FP4nameT1P8classdefP5tableT1 ( __2ctor , (struct name *)0 , ((struct classdef *)(((struct classdef *)__2ctor -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))), __1tbl , curr_fct ) ;

# 947 "/home/claude/cfront-3/src/simpl.cpp"
}
}
else if (( __3cl -> c_ctor__8classdef ) ){ 
# 950 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 950 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V96 ;

# 950 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V97 ;

# 950 "/home/claude/cfront-3/src/simpl.cpp"
error__FPCcRC2eaN32 ( (const char *)"M%n[] needsIr (no defaultK forC %s)", (const struct ea *)( ((& __0__V96 )-> __O1__2ea.p =
# 950 "/home/claude/cfront-3/src/simpl.cpp"
((const void *)__1m )), (& __0__V96 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V97 , (const void *)__3cl ->
# 950 "/home/claude/cfront-3/src/simpl.cpp"
string__8classdef ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
else if (is_ref__4typeFv ( __2t ) ){ 
# 954 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 954 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V98 ;

# 954 "/home/claude/cfront-3/src/simpl.cpp"
error__FPCcRC2eaN32 ( (const char *)"RM%n needsIr", (const struct ea *)( ((& __0__V98 )-> __O1__2ea.p =
# 954 "/home/claude/cfront-3/src/simpl.cpp"
((const void *)__1m )), (& __0__V98 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 954 "/home/claude/cfront-3/src/simpl.cpp"
ea *)ea0 ) ;
} }
else if (tconst__4typeFv ( __2t ) && (vec_const == 0 )){ 
# 957 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 957 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V99 ;

# 957 "/home/claude/cfront-3/src/simpl.cpp"
error__FPCcRC2eaN32 ( (const char *)"constM%n needsIr", (const struct ea *)( ((& __0__V99 )-> __O1__2ea.p =
# 957 "/home/claude/cfront-3/src/simpl.cpp"
((const void *)__1m )), (& __0__V99 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 957 "/home/claude/cfront-3/src/simpl.cpp"
ea *)ea0 ) ;
} }

# 960 "/home/claude/cfront-3/src/simpl.cpp"
if (__2ee ){ 
# 961 "/home/claude/cfront-3/src/simpl.cpp"
simpl__4exprFv ( __2ee ) ;
init_list = (init_list ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , init_list , __2ee ) :__2ee );
}

# 963 "/home/claude/cfront-3/src/simpl.cpp"
}

# 963 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 966 "/home/claude/cfront-3/src/simpl.cpp"
return __1ass_count ;

# 966 "/home/claude/cfront-3/src/simpl.cpp"
}

# 966 "/home/claude/cfront-3/src/simpl.cpp"
}

# 966 "/home/claude/cfront-3/src/simpl.cpp"
}

# 966 "/home/claude/cfront-3/src/simpl.cpp"
}

# 966 "/home/claude/cfront-3/src/simpl.cpp"
}

# 966 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 220 "/home/claude/cfront-3/src/cfront.h"
struct table *__ct__5tableFsP5tableP4name (struct table *__0this , short , Ptable , Pname );

# 1072 "/home/claude/cfront-3/src/cfront.h"
Pstmt simpl__5blockFv (struct block *__0this );

# 57 "/home/claude/cfront-3/src/simpl.cpp"
extern Pstmt trim_tail__FP4stmt (Pstmt __0tt );

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 649 "/home/claude/cfront-3/src/cfront.h"

# 852 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1050 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 832 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1050 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 218 "/home/claude/cfront-3/src/cfront.h"

# 221 "/home/claude/cfront-3/src/cfront.h"
void __dt__5tableFv (struct table *__0this , int );

# 1010 "/home/claude/cfront-3/src/cfront.h"

# 1025 "/home/claude/cfront-3/src/cfront.h"

# 1010 "/home/claude/cfront-3/src/cfront.h"

# 1025 "/home/claude/cfront-3/src/cfront.h"

# 969 "/home/claude/cfront-3/src/simpl.cpp"
void simpl__3fctFv (register struct fct *__0this )
# 991 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 992 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __1th ;
Ptable __1tbl ;
Pstmt __1tail ;
Pclass __1cl ;

# 992 "/home/claude/cfront-3/src/simpl.cpp"
__1th = (struct expr *)__0this -> f_this__3fct ;
__1tbl = __0this -> body__3fct -> memtbl__4stmt ;

# 995 "/home/claude/cfront-3/src/simpl.cpp"
__1cl = 0 ;
if (((__1th && __1th -> __O1__4expr.tp )&& (((struct ptr *)(((struct ptr *)__1th -> __O1__4expr.tp ))))-> typ__5pvtyp )&& (((struct basetype *)(((struct basetype *)(((struct ptr *)(((struct ptr *)__1th ->
# 996 "/home/claude/cfront-3/src/simpl.cpp"
__O1__4expr.tp ))))-> typ__5pvtyp ))))-> b_name__8basetype )
# 997 "/home/claude/cfront-3/src/simpl.cpp"
__1cl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)(((struct ptr *)(((struct ptr *)__1th -> __O1__4expr.tp ))))-> typ__5pvtyp ))))-> b_name__8basetype -> __O1__4expr.tp ))));
# 997 "/home/claude/cfront-3/src/simpl.cpp"

# 998 "/home/claude/cfront-3/src/simpl.cpp"
{ Pstmt __1dtail ;

# 1000 "/home/claude/cfront-3/src/simpl.cpp"
Pname __1ocurr_fct ;
int __1oret ;
int __1oim ;

# 998 "/home/claude/cfront-3/src/simpl.cpp"
__1dtail = 0 ;

# 1000 "/home/claude/cfront-3/src/simpl.cpp"
__1ocurr_fct = curr_fct ;
__1oret = no_of_returns ;
__1oim = imeasure ;

# 1006 "/home/claude/cfront-3/src/simpl.cpp"
del_list = 0 ;
continue_del_list = 0 ;
break_del_list = 0 ;
scope = __1tbl ;
if (scope == 0 )error__FiPCc ( (int )'i' , (const char *)"F::simpl()") ;
{ int __1ass_count ;

# 1012 "/home/claude/cfront-3/src/simpl.cpp"
struct dcl_context *__0__X125 ;

# 1011 "/home/claude/cfront-3/src/simpl.cpp"
__1ass_count = 0 ;
imeasure = 0 ;
no_of_returns = 0 ;

# 1015 "/home/claude/cfront-3/src/simpl.cpp"
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 1015 "/home/claude/cfront-3/src/simpl.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;
cc -> nof__11dcl_context = curr_fct ;
cc -> ftbl__11dcl_context = __1tbl ;

# 1021 "/home/claude/cfront-3/src/simpl.cpp"
{ { Plist __1l ;

# 1047 "/home/claude/cfront-3/src/simpl.cpp"
extern bit need_lift ;
bit __1onl ;
Ptable __1ott ;

# 1050 "/home/claude/cfront-3/src/simpl.cpp"
struct dcl_context *__0__X162 ;

# 1021 "/home/claude/cfront-3/src/simpl.cpp"
__1l = __0this -> local_class__3fct ;

# 1021 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1l ;__1l = __1l -> l__9name_list ) { 
# 1022 "/home/claude/cfront-3/src/simpl.cpp"
Pname __2n ;
Pclass __2cl ;

# 1022 "/home/claude/cfront-3/src/simpl.cpp"
__2n = __1l -> f__9name_list ;
__2cl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__2n -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))));
if (__2cl -> c_body__8classdef == 1 )dcl_print__8classdefFP4name ( __2cl , (struct name *)0 ) ;
}

# 1027 "/home/claude/cfront-3/src/simpl.cpp"
(((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp ))))-> local_class__3fct = __0this -> local_class__3fct ;
__0this -> local_class__3fct = 0 ;

# 1031 "/home/claude/cfront-3/src/simpl.cpp"
switch (curr_fct -> n_scope__4name ){ 
# 1032 "/home/claude/cfront-3/src/simpl.cpp"
case 0 :
# 1033 "/home/claude/cfront-3/src/simpl.cpp"
case 25 :
# 1034 "/home/claude/cfront-3/src/simpl.cpp"
cc -> not4__11dcl_context = curr_fct -> __O4__4expr.n_table -> t_name__5table ;
cc -> cot__11dcl_context = (((struct classdef *)(((struct classdef *)cc -> not4__11dcl_context -> __O1__4expr.tp ))));
cc -> tot__11dcl_context = cc -> cot__11dcl_context -> this_type__8classdef ;
}

# 1039 "/home/claude/cfront-3/src/simpl.cpp"
switch (curr_fct -> n_oper__4name ){ 
# 1040 "/home/claude/cfront-3/src/simpl.cpp"
case 162 :
# 1041 "/home/claude/cfront-3/src/simpl.cpp"
__1dtail = dtor_simpl__3fctFP8classdefP4expr ( __0this , __1cl , __1th ) ;
break ;
case 161 :
# 1044 "/home/claude/cfront-3/src/simpl.cpp"
__1ass_count = ctor_simpl__3fctFP8classdefP4expr ( __0this , __1cl , __1th ) ;
}

# 1047 "/home/claude/cfront-3/src/simpl.cpp"
;
__1onl = need_lift ;
__1ott = tmp_tbl ;
need_lift = 0 ;
tmp_tbl = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )12 , (struct table *)0 , (struct name *)0 ) ;

# 1053 "/home/claude/cfront-3/src/simpl.cpp"
__1tail = simpl__5blockFv ( __0this -> body__3fct ) ;

# 1055 "/home/claude/cfront-3/src/simpl.cpp"
need_lift = __1onl ;
__dt__5tableFv ( tmp_tbl , 3) ;
tmp_tbl = __1ott ;

# 1059 "/home/claude/cfront-3/src/simpl.cpp"
if (! __0this -> body__3fct )
# 1060 "/home/claude/cfront-3/src/simpl.cpp"
return ;

# 1062 "/home/claude/cfront-3/src/simpl.cpp"
if ((skiptypedefs__4typeFv ( __0this -> returns__3fct ) -> base__4node != 38 )|| __0this -> f_result__3fct ){ 
# 1063 "/home/claude/cfront-3/src/simpl.cpp"
if (no_of_returns ){ 
# 1064 "/home/claude/cfront-3/src/simpl.cpp"
Pstmt __3tt ;

# 1064 "/home/claude/cfront-3/src/simpl.cpp"
__3tt = (((__1tail -> base__4node == 28 )|| (__1tail -> base__4node == 115 ))?__1tail :trim_tail__FP4stmt ( __1tail ) );

# 1066 "/home/claude/cfront-3/src/simpl.cpp"
if (__3tt )
# 1067 "/home/claude/cfront-3/src/simpl.cpp"
switch (__3tt -> base__4node ){ 
# 1067 "/home/claude/cfront-3/src/simpl.cpp"
const void *__2__X126 ;

# 1068 "/home/claude/cfront-3/src/simpl.cpp"
case 28 :
# 1069 "/home/claude/cfront-3/src/simpl.cpp"
case 19 :
# 1070 "/home/claude/cfront-3/src/simpl.cpp"
del_list = 0 ;
break ;
case 72 :
# 1073 "/home/claude/cfront-3/src/simpl.cpp"
if (__3tt -> __O2__4stmt.e )
# 1074 "/home/claude/cfront-3/src/simpl.cpp"
switch (__3tt -> __O2__4stmt.e -> base__4node ){ 
# 1075 "/home/claude/cfront-3/src/simpl.cpp"
case 168 :
# 1076 "/home/claude/cfront-3/src/simpl.cpp"
case 146 :
# 1077 "/home/claude/cfront-3/src/simpl.cpp"
goto chicken ;
}
default :
# 1080 "/home/claude/cfront-3/src/simpl.cpp"
if (warning_opt || strcmp ( curr_fct -> __O2__4expr.string , (const char *)"main") )
# 1081 "/home/claude/cfront-3/src/simpl.cpp"
{
# 1081 "/home/claude/cfront-3/src/simpl.cpp"

# 1081 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V120 ;

# 1081 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"maybe no value returned from%n", (const struct ea *)( (__2__X126 =
# 1081 "/home/claude/cfront-3/src/simpl.cpp"
(const void *)curr_fct ), ( ((& __0__V120 )-> __O1__2ea.p = __2__X126 ), (& __0__V120 )) ) , (const struct
# 1081 "/home/claude/cfront-3/src/simpl.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} case 20 :
# 1083 "/home/claude/cfront-3/src/simpl.cpp"
if ((((__3tt -> base__4node == 20 )&& (__1tail -> base__4node == 20 ))&& (__3tt -> __O3__4stmt.else_stmt == 0 ))&& (no_of_returns == 1 )){
# 1083 "/home/claude/cfront-3/src/simpl.cpp"

# 1084 "/home/claude/cfront-3/src/simpl.cpp"
if ((strcmp ( curr_fct -> __O2__4expr.string , (const char *)"main") == 0 )&& (skiptypedefs__4typeFv (
# 1084 "/home/claude/cfront-3/src/simpl.cpp"
__0this -> returns__3fct ) -> base__4node != 38 ))
# 1085 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 1086 "/home/claude/cfront-3/src/simpl.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __3tt -> where__4stmt , (const char *)"maybe no value returned from main()",
# 1086 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
}
else error__FP3locPCcRC2eaN33 ( & __3tt -> where__4stmt , (const char *)"if with return but no else with return", (const struct
# 1088 "/home/claude/cfront-3/src/simpl.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
}
case 33 :
# 1091 "/home/claude/cfront-3/src/simpl.cpp"
case 10 :
# 1092 "/home/claude/cfront-3/src/simpl.cpp"
case 39 :
# 1093 "/home/claude/cfront-3/src/simpl.cpp"
case 16 :
# 1094 "/home/claude/cfront-3/src/simpl.cpp"
case 115 :
# 1095 "/home/claude/cfront-3/src/simpl.cpp"
chicken :
# 1096 "/home/claude/cfront-3/src/simpl.cpp"
break ;
}
}
else { 
# 1099 "/home/claude/cfront-3/src/simpl.cpp"
const void *__2__X127 ;

# 1105 "/home/claude/cfront-3/src/simpl.cpp"
if (((((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))))-> f_inline__3fct && (skiptypedefs__4typeFv ( (((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))))-> returns__3fct ) != (((struct
# 1105 "/home/claude/cfront-3/src/simpl.cpp"
type *)void_type ))))&& is_cl_obj__4typeFv ( (((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))))-> returns__3fct ) )
# 1109 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 1109 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V121 ;

# 1109 "/home/claude/cfront-3/src/simpl.cpp"
error__FPCcRC2eaN32 ( (const char *)"no value returned from%n", (const struct ea *)( (__2__X127 = (const void
# 1109 "/home/claude/cfront-3/src/simpl.cpp"
*)curr_fct ), ( ((& __0__V121 )-> __O1__2ea.p = __2__X127 ), (& __0__V121 )) ) , (const struct ea *)ea0 , (const
# 1109 "/home/claude/cfront-3/src/simpl.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (strcmp ( curr_fct -> __O2__4expr.string , (const char *)"main") )
# 1111 "/home/claude/cfront-3/src/simpl.cpp"
{
# 1111 "/home/claude/cfront-3/src/simpl.cpp"

# 1111 "/home/claude/cfront-3/src/simpl.cpp"
struct fct *__0__X128 ;

# 1111 "/home/claude/cfront-3/src/simpl.cpp"
const void *__2__X129 ;

# 1111 "/home/claude/cfront-3/src/simpl.cpp"
const void *__2__X130 ;

# 1111 "/home/claude/cfront-3/src/simpl.cpp"
const void *__2__X131 ;

# 1112 "/home/claude/cfront-3/src/simpl.cpp"
if (( (__0__X128 = (((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))))), ( (__0__X128 -> fct_base__3fct != 0)) ) && ((((struct
# 1112 "/home/claude/cfront-3/src/simpl.cpp"
fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))))-> returns__3fct == (((struct type *)defa_type ))))
# 1113 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 1113 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V122 ;

# 1113 "/home/claude/cfront-3/src/simpl.cpp"
error__FPCcRC2eaN32 ( (const char *)"no value returned from%n", (const struct ea *)( (__2__X129 = (const void
# 1113 "/home/claude/cfront-3/src/simpl.cpp"
*)curr_fct ), ( ((& __0__V122 )-> __O1__2ea.p = __2__X129 ), (& __0__V122 )) ) , (const struct ea *)ea0 , (const
# 1113 "/home/claude/cfront-3/src/simpl.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (((((((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))))-> returns__3fct == (((struct type *)defa_type )))&& (! (((struct fct *)(((struct fct *)curr_fct ->
# 1114 "/home/claude/cfront-3/src/simpl.cpp"
__O1__4expr.tp ))))-> memof__3fct ))&& (! curr_fct -> n_oper__4name ))&& (simpl_friend == 0 ))
# 1116 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 1116 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V123 ;

# 1116 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCcRC2eaN33 ( strict_opt ?0 :119, (const char *)"no value returned from%n (anachronism)", (const struct ea *)( (__2__X130 = (const
# 1116 "/home/claude/cfront-3/src/simpl.cpp"
void *)curr_fct ), ( ((& __0__V123 )-> __O1__2ea.p = __2__X130 ), (& __0__V123 )) ) , (const struct ea *)ea0 ,
# 1116 "/home/claude/cfront-3/src/simpl.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 1118 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 1118 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V124 ;

# 1118 "/home/claude/cfront-3/src/simpl.cpp"
error__FPCcRC2eaN32 ( (const char *)"no value returned from%n", (const struct ea *)( (__2__X131 = (const void
# 1118 "/home/claude/cfront-3/src/simpl.cpp"
*)curr_fct ), ( ((& __0__V124 )-> __O1__2ea.p = __2__X131 ), (& __0__V124 )) ) , (const struct ea *)ea0 , (const
# 1118 "/home/claude/cfront-3/src/simpl.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
if ((warning_opt && (strcmp ( curr_fct -> __O2__4expr.string , (const char *)"main") ==
# 1120 "/home/claude/cfront-3/src/simpl.cpp"
0 ))&& (skiptypedefs__4typeFv ( (((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))))-> returns__3fct ) != (((struct type *)void_type ))))
# 1121 "/home/claude/cfront-3/src/simpl.cpp"
error__FiPCc ( (int )'w' , (const char
# 1121 "/home/claude/cfront-3/src/simpl.cpp"
*)"no value returned from main()") ;
}
if (del_list )goto zaq ;
}
else if (del_list ){ 
# 1126 "/home/claude/cfront-3/src/simpl.cpp"
zaq :
# 1127 "/home/claude/cfront-3/src/simpl.cpp"
if (__1tail )
# 1128 "/home/claude/cfront-3/src/simpl.cpp"
__1tail -> s_list__4stmt = del_list ;
else 
# 1130 "/home/claude/cfront-3/src/simpl.cpp"
__0this -> body__3fct -> s__4stmt = del_list ;
__1tail = __1dtail ;
}

# 1134 "/home/claude/cfront-3/src/simpl.cpp"
if (curr_fct -> n_oper__4name == 162 ){ 
# 1137 "/home/claude/cfront-3/src/simpl.cpp"
{ { Pvirt __2blist ;

# 1138 "/home/claude/cfront-3/src/simpl.cpp"
register struct ifstmt *__0__X140 ;

# 1138 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X141 ;

# 1138 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__2__X142 ;

# 1138 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__2__X143 ;

# 1137 "/home/claude/cfront-3/src/simpl.cpp"
__2blist = __1cl -> virt_list__8classdef ;

# 1137 "/home/claude/cfront-3/src/simpl.cpp"
for(;__2blist ;__2blist = __2blist -> next__4virt ) { 
# 1139 "/home/claude/cfront-3/src/simpl.cpp"
topclass = __1cl ;
{ Pexpr __3vp ;

# 1142 "/home/claude/cfront-3/src/simpl.cpp"
char *__3str ;
const char *__3cs ;

# 1140 "/home/claude/cfront-3/src/simpl.cpp"
__3vp = get_vptr_exp__8classdefFPCc ( __1cl , __2blist -> string__4virt ) ;

# 1142 "/home/claude/cfront-3/src/simpl.cpp"
__3str = 0 ;
__3cs = (__1cl -> nested_sig__4type ?(((const char *)__1cl -> nested_sig__4type )):__1cl -> string__8classdef );
if (__1cl -> lex_level__4type && (__1cl -> nested_sig__4type == 0 )){ 
# 1145 "/home/claude/cfront-3/src/simpl.cpp"
__3str = (((char *)__nw__FUl ( (size_t)((sizeof (char ))*
# 1145 "/home/claude/cfront-3/src/simpl.cpp"
(__1cl -> c_strlen__8classdef + 1 ))) ));
strcpy ( __3str , (const char *)__1cl -> local_sig__4type ) ;
}
{ Pexpr __3vtbl ;

# 1150 "/home/claude/cfront-3/src/simpl.cpp"
Pexpr __3ee ;

# 1151 "/home/claude/cfront-3/src/simpl.cpp"
register struct text_expr *__0__X134 ;

# 1151 "/home/claude/cfront-3/src/simpl.cpp"
const char *__2__X135 ;

# 1151 "/home/claude/cfront-3/src/simpl.cpp"
const char *__2__X136 ;

# 1151 "/home/claude/cfront-3/src/simpl.cpp"
struct ref *__0__X137 ;

# 1151 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X138 ;

# 1151 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X139 ;

# 1148 "/home/claude/cfront-3/src/simpl.cpp"
__3vtbl = (struct expr *)( (__0__X134 = 0 ), ( (__2__X135 = __2blist -> string__4virt ), ( (__2__X136 = (__3str ?(((const char *)__3str )):__3cs )),
# 1148 "/home/claude/cfront-3/src/simpl.cpp"
( ((__0__X134 || (__0__X134 = (struct text_expr *)__nw__4exprSFUl ( (size_t )(sizeof (struct text_expr))) ))?( (__0__X134 = (struct text_expr *)__ct__4exprFUcP4exprT2 ( ((struct
# 1148 "/home/claude/cfront-3/src/simpl.cpp"
expr *)__0__X134 ), (unsigned char )165 , (struct expr *)0 , (struct expr *)0 ) ), ( (__0__X134 -> __O2__4expr.string = __2__X135 ), (__0__X134 ->
# 1148 "/home/claude/cfront-3/src/simpl.cpp"
__O3__4expr.string2 = __2__X136 )) ) :0 ), __0__X134 ) ) ) ) ;

# 1150 "/home/claude/cfront-3/src/simpl.cpp"
__3ee = (struct expr *)( (__0__X137 = 0 ), ( (__2__X138 = __1th ), ( (__2__X139 = __3vp ), ( ((__0__X137 || (__0__X137 =
# 1150 "/home/claude/cfront-3/src/simpl.cpp"
(struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X137 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X137 ), ((unsigned char
# 1150 "/home/claude/cfront-3/src/simpl.cpp"
)44 ), __2__X138 , (struct expr *)0 ) ), (__0__X137 -> __O4__4expr.mem = __2__X139 )) :0 ), __0__X137 ) ) ) ) ;
# 1150 "/home/claude/cfront-3/src/simpl.cpp"

# 1151 "/home/claude/cfront-3/src/simpl.cpp"
__3ee -> __O1__4expr.tp = __3vp -> __O1__4expr.tp ;
__3ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __3ee , __3vtbl ) ;
{ Pstmt __3es ;

# 1154 "/home/claude/cfront-3/src/simpl.cpp"
struct estmt *__0__X132 ;

# 1154 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X133 ;

# 1153 "/home/claude/cfront-3/src/simpl.cpp"
__3es = (struct stmt *)( (__0__X132 = 0 ), ( (__2__X133 = curloc ), ( ((__0__X132 || (__0__X132 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 1153 "/home/claude/cfront-3/src/simpl.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X132 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X132 ), ((unsigned char )72 ), __2__X133 , ((struct
# 1153 "/home/claude/cfront-3/src/simpl.cpp"
stmt *)0 )) ), (__0__X132 -> __O2__4stmt.e = __3ee )) :0 ), __0__X132 ) ) ) ;
__3es -> s_list__4stmt = __0this -> body__3fct -> s__4stmt ;
__0this -> body__3fct -> s__4stmt = __3es ;

# 1155 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1155 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1155 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 1158 "/home/claude/cfront-3/src/simpl.cpp"
__0this -> body__3fct -> s__4stmt = (struct stmt *)( (__0__X140 = 0 ), ( (__2__X141 = __0this -> body__3fct -> where__4stmt ), ( (__2__X142 =
# 1158 "/home/claude/cfront-3/src/simpl.cpp"
__0this -> body__3fct -> s__4stmt ), ( (__2__X143 = 0 ), ( ((__0__X140 || (__0__X140 = (struct ifstmt *)__nw__4stmtSFUl ( (size_t)(sizeof
# 1158 "/home/claude/cfront-3/src/simpl.cpp"
(struct ifstmt))) ))?( (__0__X140 = (struct ifstmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X140 ), (unsigned char )20 , __2__X141 , __2__X142 ) ), (
# 1158 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X140 -> __O2__4stmt.e = __1th ), (__0__X140 -> __O3__4stmt.else_stmt = __2__X143 )) ) :0 ), __0__X140 ) ) ) ) ) ;
# 1158 "/home/claude/cfront-3/src/simpl.cpp"

# 1158 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1158 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 1161 "/home/claude/cfront-3/src/simpl.cpp"
if (curr_fct -> n_oper__4name == 161 ){ 
# 1163 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2temploc ;
Pstmt __2tempss ;

# 1163 "/home/claude/cfront-3/src/simpl.cpp"
__2temploc = __0this -> body__3fct -> where__4stmt ;
__2tempss = __0this -> body__3fct -> s__4stmt ;
while (__2tempss ){ 
# 1166 "/home/claude/cfront-3/src/simpl.cpp"
__2temploc = __2tempss -> where__4stmt ;
__2tempss = __2tempss -> s_list__4stmt ;
}

# 1170 "/home/claude/cfront-3/src/simpl.cpp"
if ((((struct name *)(((struct name *)__1th ))))-> n_assigned_to__4name == 0 ){ 
# 1177 "/home/claude/cfront-3/src/simpl.cpp"
(((struct name *)(((struct name *)__1th ))))-> n_assigned_to__4name = (__1ass_count ?__1ass_count :11111 );
{ Pexpr __3sz ;

# 1179 "/home/claude/cfront-3/src/simpl.cpp"
struct texpr *__0__X160 ;

# 1178 "/home/claude/cfront-3/src/simpl.cpp"
__3sz = (struct expr *)( (__0__X160 = 0 ), ( ((__0__X160 || (__0__X160 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 1178 "/home/claude/cfront-3/src/simpl.cpp"
))?( (__0__X160 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X160 ), ((unsigned char )30 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 1178 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X160 -> __O4__4expr.tp2 = ((struct type *)__1cl ))) :0 ), __0__X160 ) ) ;
((void )tsizeof__4typeFi ( (struct type *)__1cl , 0 ) );
__3sz -> __O1__4expr.tp = (struct type *)uint_type ;
{ Pexpr __3ee ;
Pname __3n ;
Pexpr __3p ;

# 1184 "/home/claude/cfront-3/src/simpl.cpp"
struct estmt *__0__X150 ;

# 1184 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X151 ;

# 1184 "/home/claude/cfront-3/src/simpl.cpp"
if (! perf_opt ){ 
# 1184 "/home/claude/cfront-3/src/simpl.cpp"
struct call *__0__X144 ;

# 1184 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X145 ;

# 1184 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X146 ;

# 1186 "/home/claude/cfront-3/src/simpl.cpp"
__3ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __3sz , (struct expr *)0 ) ;
__3n = __ct__4nameFPCc ( (struct name *)0 , oper_name__FUc ( (unsigned char )23 ) ) ;
__3p = find_name__FP4nameP8classdefP5tableiT1 ( __3n , __1cl , scope , 109 , curr_fct ) ;

# 1190 "/home/claude/cfront-3/src/simpl.cpp"
__3ee = (struct expr *)( (__0__X144 = 0 ), ( (__2__X145 = __3p ), ( (__2__X146 = __3ee ), ( ((__0__X144 || (__0__X144 =
# 1190 "/home/claude/cfront-3/src/simpl.cpp"
(struct call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X144 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X144 ), (unsigned char )109 ,
# 1190 "/home/claude/cfront-3/src/simpl.cpp"
__2__X145 , __2__X146 ) ):0 ), __0__X144 ) ) ) ) ;
((void )call_fct__4exprFP5table ( __3ee , __1cl -> memtbl__8classdef ) );
simpl__4exprFv ( __3ee ) ;
__3ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __1th , __3ee ) ;
__3ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )67 , __1th , __3ee ) ;
}

# 1200 "/home/claude/cfront-3/src/simpl.cpp"
if (init_list ){ 
# 1201 "/home/claude/cfront-3/src/simpl.cpp"
Pstmt __4es ;

# 1202 "/home/claude/cfront-3/src/simpl.cpp"
struct estmt *__0__X147 ;

# 1202 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X148 ;

# 1202 "/home/claude/cfront-3/src/simpl.cpp"
struct expr *__2__X149 ;

# 1201 "/home/claude/cfront-3/src/simpl.cpp"
__4es = (struct stmt *)( (__0__X147 = 0 ), ( (__2__X148 = __0this -> body__3fct -> where__4stmt ), ( (__2__X149 = init_list ), (
# 1201 "/home/claude/cfront-3/src/simpl.cpp"
((__0__X147 || (__0__X147 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X147 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X147 ),
# 1201 "/home/claude/cfront-3/src/simpl.cpp"
((unsigned char )72 ), __2__X148 , ((struct stmt *)0 )) ), (__0__X147 -> __O2__4stmt.e = __2__X149 )) :0 ), __0__X147 ) ) )
# 1201 "/home/claude/cfront-3/src/simpl.cpp"
) ;
__4es -> s_list__4stmt = __0this -> body__3fct -> s__4stmt ;
__0this -> body__3fct -> s__4stmt = __4es ;

# 1205 "/home/claude/cfront-3/src/simpl.cpp"
}
else if (__0this -> body__3fct -> s__4stmt == 0 )
# 1207 "/home/claude/cfront-3/src/simpl.cpp"
__0this -> body__3fct -> s__4stmt = (struct stmt *)( (__0__X150 = 0 ), ( (__2__X151 =
# 1207 "/home/claude/cfront-3/src/simpl.cpp"
__0this -> body__3fct -> where__4stmt ), ( ((__0__X150 || (__0__X150 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X150 =
# 1207 "/home/claude/cfront-3/src/simpl.cpp"
(struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X150 ), ((unsigned char )72 ), __2__X151 , ((struct stmt *)0 )) ), (__0__X150 -> __O2__4stmt.e = ((struct
# 1207 "/home/claude/cfront-3/src/simpl.cpp"
expr *)0 ))) :0 ), __0__X150 ) ) ) ;
else if (__1tail -> base__4node == 28 ){ 
# 1209 "/home/claude/cfront-3/src/simpl.cpp"
if (__0this -> body__3fct -> s__4stmt == __1tail ){ 
# 1209 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__0__X152 ;

# 1209 "/home/claude/cfront-3/src/simpl.cpp"
struct estmt *__0__X153 ;

# 1209 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X154 ;

# 1210 "/home/claude/cfront-3/src/simpl.cpp"
( (__0__X152 = __0this -> body__3fct -> s__4stmt ), ( (__0__X152 ?(((void )(__0__X152 ?(((void )(((void )__dl__4stmtSFPvUl ( (void *)__0__X152 , (unsigned long
# 1210 "/home/claude/cfront-3/src/simpl.cpp"
)(sizeof (struct stmt))) )))):(((void )0 ))))):(((void )0 )))) ) ;
__0this -> body__3fct -> s__4stmt = (struct stmt *)( (__0__X153 = 0 ), ( (__2__X154 = __0this -> body__3fct -> where__4stmt ), ( ((__0__X153 ||
# 1211 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X153 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X153 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X153 ), ((unsigned
# 1211 "/home/claude/cfront-3/src/simpl.cpp"
char )72 ), __2__X154 , ((struct stmt *)0 )) ), (__0__X153 -> __O2__4stmt.e = ((struct expr *)0 ))) :0 ), __0__X153 ) ) )
# 1211 "/home/claude/cfront-3/src/simpl.cpp"
;
}
else { 
# 1214 "/home/claude/cfront-3/src/simpl.cpp"
Pstmt __5pr ;

# 1215 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__0__X155 ;

# 1214 "/home/claude/cfront-3/src/simpl.cpp"
__5pr = __0this -> body__3fct -> s__4stmt ;
while (__5pr -> s_list__4stmt != __1tail )
# 1216 "/home/claude/cfront-3/src/simpl.cpp"
__5pr = __5pr -> s_list__4stmt ;
( (__0__X155 = __5pr -> s_list__4stmt ), ( (__0__X155 ?(((void )(__0__X155 ?(((void )(((void )__dl__4stmtSFPvUl ( (void *)__0__X155 , (unsigned long )(sizeof
# 1217 "/home/claude/cfront-3/src/simpl.cpp"
(struct stmt))) )))):(((void )0 ))))):(((void )0 )))) ) ;
__5pr -> s_list__4stmt = 0 ;
}
}

# 1222 "/home/claude/cfront-3/src/simpl.cpp"
if (perf_opt ){ 
# 1226 "/home/claude/cfront-3/src/simpl.cpp"
if (__1tail == 0 )
# 1227 "/home/claude/cfront-3/src/simpl.cpp"
__1tail = __0this -> body__3fct -> s__4stmt ;
}
else { 
# 1230 "/home/claude/cfront-3/src/simpl.cpp"
struct ifstmt *__4ifs ;

# 1231 "/home/claude/cfront-3/src/simpl.cpp"
register struct ifstmt *__0__X156 ;

# 1231 "/home/claude/cfront-3/src/simpl.cpp"
struct loc __2__X157 ;

# 1231 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__2__X158 ;

# 1231 "/home/claude/cfront-3/src/simpl.cpp"
struct stmt *__2__X159 ;

# 1230 "/home/claude/cfront-3/src/simpl.cpp"
__4ifs = ( (__0__X156 = 0 ), ( (__2__X157 = __0this -> body__3fct -> where__4stmt ), ( (__2__X158 = __0this -> body__3fct -> s__4stmt ),
# 1230 "/home/claude/cfront-3/src/simpl.cpp"
( (__2__X159 = 0 ), ( ((__0__X156 || (__0__X156 = (struct ifstmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct ifstmt))) ))?( (__0__X156 =
# 1230 "/home/claude/cfront-3/src/simpl.cpp"
(struct ifstmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X156 ), (unsigned char )20 , __2__X157 , __2__X158 ) ), ( (__0__X156 -> __O2__4stmt.e = __3ee ),
# 1230 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X156 -> __O3__4stmt.else_stmt = __2__X159 )) ) :0 ), __0__X156 ) ) ) ) ) ;
__0this -> body__3fct -> s__4stmt = (struct stmt *)__4ifs ;

# 1233 "/home/claude/cfront-3/src/simpl.cpp"
__1tail = (struct stmt *)__4ifs ;
}

# 1234 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1234 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1236 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1238 "/home/claude/cfront-3/src/simpl.cpp"
{ Pstmt __2st ;

# 1239 "/home/claude/cfront-3/src/simpl.cpp"
struct estmt *__0__X161 ;

# 1238 "/home/claude/cfront-3/src/simpl.cpp"
__2st = (struct stmt *)( (__0__X161 = 0 ), ( ((__0__X161 || (__0__X161 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt)))
# 1238 "/home/claude/cfront-3/src/simpl.cpp"
))?( (__0__X161 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X161 ), ((unsigned char )28 ), __2temploc , ((struct stmt *)0 )) ), (__0__X161 ->
# 1238 "/home/claude/cfront-3/src/simpl.cpp"
__O2__4stmt.e = __1th )) :0 ), __0__X161 ) ) ;
if (__1tail )
# 1240 "/home/claude/cfront-3/src/simpl.cpp"
__1tail -> s_list__4stmt = __2st ;
else 
# 1242 "/home/claude/cfront-3/src/simpl.cpp"
__0this -> body__3fct -> s__4stmt = __2st ;
__1tail = __2st ;

# 1243 "/home/claude/cfront-3/src/simpl.cpp"
}
}
__0this -> f_imeasure__3fct = imeasure ;
curr_fct = __1ocurr_fct ;
no_of_returns = __1oret ;
imeasure = __1oim ;
( ( (cc -- ), (((void )0 ))) ) ;

# 1249 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1249 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1249 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1249 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 1253 "/home/claude/cfront-3/src/simpl.cpp"
void simpl__8classdefFv (register struct classdef *__0this )
# 1254 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 1255 "/home/claude/cfront-3/src/simpl.cpp"
int __1i ;

# 1256 "/home/claude/cfront-3/src/simpl.cpp"
struct dcl_context *__0__X164 ;

# 1258 "/home/claude/cfront-3/src/simpl.cpp"
if (__0this -> defined__4type & 02 )return ;
if ((__0this -> defined__4type & 01 )== 0 )return ;

# 1261 "/home/claude/cfront-3/src/simpl.cpp"
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 1261 "/home/claude/cfront-3/src/simpl.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;
cc -> cot__11dcl_context = __0this ;
cc -> tot__11dcl_context = __0this -> this_type__8classdef ;
cc -> not4__11dcl_context = __0this -> memtbl__8classdef -> t_name__5table ;

# 1266 "/home/claude/cfront-3/src/simpl.cpp"
__1i = 1 ;
{ Pname __1m ;

# 1268 "/home/claude/cfront-3/src/simpl.cpp"
struct table *__0__X165 ;

# 1268 "/home/claude/cfront-3/src/simpl.cpp"
int __2__X166 ;

# 1268 "/home/claude/cfront-3/src/simpl.cpp"
struct table *__0__X168 ;

# 1267 "/home/claude/cfront-3/src/simpl.cpp"
__1m = ( (__0__X168 = __0this -> memtbl__8classdef ), ( (((__1i <= 0 )|| (__0__X168 -> free_slot__5table <= __1i ))?(((struct name *)0 )):(__0__X168 -> entries__5table [__1i ]))) )
# 1267 "/home/claude/cfront-3/src/simpl.cpp"
;
for(;__1m ;__1m = (__1m -> n_tbl_list__4name ?__1m -> n_tbl_list__4name :( (__0__X165 = __0this -> memtbl__8classdef ), ( (__2__X166 = (++ __1i )), ( (((__2__X166 <= 0 )||
# 1268 "/home/claude/cfront-3/src/simpl.cpp"
(__0__X165 -> free_slot__5table <= __2__X166 ))?(((struct name *)0 )):(__0__X165 -> entries__5table [__2__X166 ]))) ) ) )) { 
# 1269 "/home/claude/cfront-3/src/simpl.cpp"
if (__1m -> base__4node == 123 )continue ;
# 1269 "/home/claude/cfront-3/src/simpl.cpp"

# 1270 "/home/claude/cfront-3/src/simpl.cpp"
if (( __0this -> c_ctor__8classdef ) && (strcmp ( __1m -> __O2__4expr.string , __0this -> string__8classdef ) == 0 ))
# 1274 "/home/claude/cfront-3/src/simpl.cpp"
{ 
# 1274 "/home/claude/cfront-3/src/simpl.cpp"
struct ea __0__V163 ;
# 1274 "/home/claude/cfront-3/src/simpl.cpp"

# 1274 "/home/claude/cfront-3/src/simpl.cpp"
error__FP3locPCcRC2eaN33 ( & __1m -> where__4name , (const char *)"nonFM%n inCWK", (const struct ea *)(
# 1274 "/home/claude/cfront-3/src/simpl.cpp"
((& __0__V163 )-> __O1__2ea.p = ((const void *)__1m )), (& __0__V163 )) , (const struct ea *)ea0 , (const struct
# 1274 "/home/claude/cfront-3/src/simpl.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} { Pexpr __2i ;

# 1275 "/home/claude/cfront-3/src/simpl.cpp"
__2i = __1m -> __O3__4expr.n_initializer ;
__1m -> __O3__4expr.n_initializer = 0 ;
simpl__4nameFv ( __1m ) ;
__1m -> __O3__4expr.n_initializer = __2i ;

# 1278 "/home/claude/cfront-3/src/simpl.cpp"
}
}

# 1281 "/home/claude/cfront-3/src/simpl.cpp"
{ { Plist __1fl ;

# 1282 "/home/claude/cfront-3/src/simpl.cpp"
struct dcl_context *__0__X167 ;

# 1281 "/home/claude/cfront-3/src/simpl.cpp"
__1fl = __0this -> friend_list__8classdef ;

# 1281 "/home/claude/cfront-3/src/simpl.cpp"
for(;__1fl ;__1fl = __1fl -> l__9name_list ) { 
# 1282 "/home/claude/cfront-3/src/simpl.cpp"
Pname __2p ;

# 1282 "/home/claude/cfront-3/src/simpl.cpp"
__2p = __1fl -> f__9name_list ;
switch (__2p -> __O1__4expr.tp -> base__4node ){ 
# 1284 "/home/claude/cfront-3/src/simpl.cpp"
case 108 :
# 1285 "/home/claude/cfront-3/src/simpl.cpp"
case 76 :
# 1286 "/home/claude/cfront-3/src/simpl.cpp"
simpl__4nameFv ( __2p ) ;
}
}

# 1290 "/home/claude/cfront-3/src/simpl.cpp"
__0this -> defined__4type |= 02 ;
( ( (cc -- ), (((void )0 ))) ) ;

# 1291 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1291 "/home/claude/cfront-3/src/simpl.cpp"
}

# 1291 "/home/claude/cfront-3/src/simpl.cpp"
}
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

# 1292 "/home/claude/cfront-3/src/simpl.cpp"

/* the end */
