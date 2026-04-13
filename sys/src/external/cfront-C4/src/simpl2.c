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

# 39 "/home/claude/cfront-3/src/simpl2.cpp"
extern Plist inllist ;

# 43 "/home/claude/cfront-3/src/simpl2.cpp"
extern int no_of_returns ;

# 45 "/home/claude/cfront-3/src/simpl2.cpp"
extern Pname new_fct ;

# 48 "/home/claude/cfront-3/src/simpl2.cpp"
extern Pstmt del_list ;
extern Pstmt break_del_list ;
extern Pstmt continue_del_list ;

# 52 "/home/claude/cfront-3/src/simpl2.cpp"
extern Pname curr_fct ;
extern Pexpr init_list ;
extern int imeasure ;

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 579 "/home/claude/cfront-3/src/cfront.h"
struct basetype *__ct__8basetypeFUcP4name (struct basetype *__0this , TOK , Pname );

# 56 "/home/claude/cfront-3/src/simpl2.cpp"
Ptype unconst_type__FP4type (Ptype __1tp )
# 57 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 58 "/home/claude/cfront-3/src/simpl2.cpp"
if (((! ansi_opt )|| (! __1tp ))|| (! tconst__4typeFv ( __1tp ) ))
# 59 "/home/claude/cfront-3/src/simpl2.cpp"
return __1tp ;

# 61 "/home/claude/cfront-3/src/simpl2.cpp"
{ Ptype __1curr ;

# 61 "/home/claude/cfront-3/src/simpl2.cpp"
Ptype __1t ;

# 61 "/home/claude/cfront-3/src/simpl2.cpp"
__1t = skiptypedefs__4typeFv ( __1tp ) ;

# 63 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__1t -> base__4node ){ 
# 64 "/home/claude/cfront-3/src/simpl2.cpp"
case 110 :
# 65 "/home/claude/cfront-3/src/simpl2.cpp"
case 108 :
# 66 "/home/claude/cfront-3/src/simpl2.cpp"
case 76 :
# 67 "/home/claude/cfront-3/src/simpl2.cpp"
return __1tp ;
case 125 :
# 69 "/home/claude/cfront-3/src/simpl2.cpp"
case 158 :
# 70 "/home/claude/cfront-3/src/simpl2.cpp"
__1curr = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )0 , (struct type *)0 ) ;
((*(((struct ptr *)(((struct ptr *)__1curr ))))))= (*(((struct ptr *)(((struct ptr *)__1t )))));
break ;
default :
# 74 "/home/claude/cfront-3/src/simpl2.cpp"
__1curr = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )0 , (struct name *)0 ) ;
((*(((struct basetype *)(((struct basetype *)__1curr ))))))= (*(((struct basetype *)(((struct basetype *)__1t )))));
break ;
}

# 79 "/home/claude/cfront-3/src/simpl2.cpp"
__1curr -> ansi_const__4type = 1 ;
return __1curr ;

# 80 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 83 "/home/claude/cfront-3/src/simpl2.cpp"
bit return_nrv__FP4expr (Pexpr __1e )
# 87 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 88 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__1e -> base__4node == 111 )&& (__1e -> __O2__4expr.e1 -> base__4node == 85 ))&& (strcmp ( (((struct name *)(((struct name *)__1e -> __O2__4expr.e1 ))))->
# 88 "/home/claude/cfront-3/src/simpl2.cpp"
__O2__4expr.string , (const char *)"_result") == 0 ))
# 94 "/home/claude/cfront-3/src/simpl2.cpp"
return (unsigned char )1 ;

# 96 "/home/claude/cfront-3/src/simpl2.cpp"
return (unsigned char )0 ;
}

# 820 "/home/claude/cfront-3/src/cfront.h"

# 346 "/home/claude/cfront-3/src/cfront.h"
int tsizeof__4typeFi (struct type *__0this , int );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 801 "/home/claude/cfront-3/src/cfront.h"
int lval__4exprFUc (struct expr *__0this , TOK );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 832 "/home/claude/cfront-3/src/cfront.h"

# 100 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr cdvec__FP4nameP4exprP8classdefT1iN22 (Pname __1f , Pexpr __1vec , Pclass __1cl , Pname __1cd , int __1tail , Pexpr __1i , Pexpr __1vec2 )
# 104 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 106 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1sz ;

# 107 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X29 ;

# 106 "/home/claude/cfront-3/src/simpl2.cpp"
__1sz = (struct expr *)( (__0__X29 = 0 ), ( ((__0__X29 || (__0__X29 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 106 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X29 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X29 ), ((unsigned char )30 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 106 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X29 -> __O4__4expr.tp2 = ((struct type *)__1cl ))) :0 ), __0__X29 ) ) ;
__1sz -> __O1__4expr.tp = (struct type *)uint_type ;
((void )tsizeof__4typeFi ( (struct type *)__1cl , 0 ) );

# 110 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __1esz ;

# 113 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1noe ;

# 114 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X17 ;

# 114 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X18 ;

# 114 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X19 ;

# 114 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X20 ;

# 114 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X28 ;

# 110 "/home/claude/cfront-3/src/simpl2.cpp"
__1esz = (struct expr *)( (__0__X28 = 0 ), ( ((__0__X28 || (__0__X28 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 110 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X28 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X28 ), ((unsigned char )30 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 110 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X28 -> __O4__4expr.tp2 = ((struct type *)__1cl ))) :0 ), __0__X28 ) ) ;
__1esz -> __O1__4expr.tp = (struct type *)int_type ;

# 113 "/home/claude/cfront-3/src/simpl2.cpp"
;
if (__1vec2 )
# 115 "/home/claude/cfront-3/src/simpl2.cpp"
__1noe = (struct expr *)( (__0__X17 = 0 ), ( (__2__X18 = __1vec2 -> __O1__4expr.tp ), ( ((__0__X17 || (__0__X17 = (struct
# 115 "/home/claude/cfront-3/src/simpl2.cpp"
texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X17 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X17 ), ((unsigned char )30 ),
# 115 "/home/claude/cfront-3/src/simpl2.cpp"
((struct expr *)0 ), (struct expr *)0 ) ), (__0__X17 -> __O4__4expr.tp2 = __2__X18 )) :0 ), __0__X17 ) ) ) ;
else __1noe = (struct expr *)( (__0__X19 = 0 ), ( (__2__X20 = __1vec -> __O1__4expr.tp ), ( ((__0__X19 || (__0__X19 = (struct
# 116 "/home/claude/cfront-3/src/simpl2.cpp"
texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X19 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X19 ), ((unsigned char )30 ),
# 116 "/home/claude/cfront-3/src/simpl2.cpp"
((struct expr *)0 ), (struct expr *)0 ) ), (__0__X19 -> __O4__4expr.tp2 = __2__X20 )) :0 ), __0__X19 ) ) ) ;

# 119 "/home/claude/cfront-3/src/simpl2.cpp"
__1noe -> __O1__4expr.tp = (struct type *)int_type ;
__1noe = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )51 , __1noe , __1esz ) ;
__1noe -> __O1__4expr.tp = (struct type *)uint_type ;

# 124 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __1arg ;

# 125 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X21 ;

# 125 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X22 ;

# 125 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X23 ;

# 125 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X24 ;

# 125 "/home/claude/cfront-3/src/simpl2.cpp"
struct call *__0__X25 ;

# 125 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X26 ;

# 125 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X27 ;

# 124 "/home/claude/cfront-3/src/simpl2.cpp"
__1arg = (__1i ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1i , (struct expr *)0 ) :(((struct expr *)0 )));
__1arg = ((0 <= __1tail )?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , __1arg ) :__1arg );
__1arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (struct expr *)( (__0__X21 = 0 ), ( (__2__X22 = Pvoid_type ),
# 126 "/home/claude/cfront-3/src/simpl2.cpp"
( ((__0__X21 || (__0__X21 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X21 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct
# 126 "/home/claude/cfront-3/src/simpl2.cpp"
expr *)__0__X21 ), ((unsigned char )191 ), ((struct expr *)__1cd ), (struct expr *)0 ) ), (__0__X21 -> __O4__4expr.tp2 = __2__X22 )) :0 ), __0__X21 )
# 126 "/home/claude/cfront-3/src/simpl2.cpp"
) ) , __1arg ) ;
lval__4exprFUc ( (struct expr *)__1cd , (unsigned char )112 ) ;

# 129 "/home/claude/cfront-3/src/simpl2.cpp"
__1arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1sz , __1arg ) ;
__1arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1noe , __1arg ) ;
__1arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (struct expr *)( (__0__X23 = 0 ), ( (__2__X24 = Pvoid_type ),
# 131 "/home/claude/cfront-3/src/simpl2.cpp"
( ((__0__X23 || (__0__X23 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X23 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct
# 131 "/home/claude/cfront-3/src/simpl2.cpp"
expr *)__0__X23 ), ((unsigned char )191 ), __1vec , (struct expr *)0 ) ), (__0__X23 -> __O4__4expr.tp2 = __2__X24 )) :0 ), __0__X23 ) )
# 131 "/home/claude/cfront-3/src/simpl2.cpp"
) , __1arg ) ;

# 133 "/home/claude/cfront-3/src/simpl2.cpp"
__1arg = (struct expr *)( (__0__X25 = 0 ), ( (__2__X26 = (struct expr *)__1f ), ( (__2__X27 = __1arg ), ( ((__0__X25 ||
# 133 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X25 = (struct call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X25 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X25 ), (unsigned char
# 133 "/home/claude/cfront-3/src/simpl2.cpp"
)109 , __2__X26 , __2__X27 ) ):0 ), __0__X25 ) ) ) ) ;
__1arg -> base__4node = 146 ;
__1arg -> __O4__4expr.fct_name = __1f ;

# 137 "/home/claude/cfront-3/src/simpl2.cpp"
return __1arg ;

# 137 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 137 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 162 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt trim_tail__FP4stmt (Pstmt __1tt );

# 162 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt trim_tail__FP4stmt (Pstmt __1tt )
# 167 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 168 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1tt == 0 )return (struct stmt *)0 ;

# 170 "/home/claude/cfront-3/src/simpl2.cpp"
while (__1tt -> s_list__4stmt ){ 
# 171 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __2tpx ;
switch (__1tt -> base__4node ){ 
# 173 "/home/claude/cfront-3/src/simpl2.cpp"
case 166 :
# 174 "/home/claude/cfront-3/src/simpl2.cpp"
__2tpx = trim_tail__FP4stmt ( __1tt -> __O2__4stmt.s2 ) ;
goto tpxl ;
case 116 :
# 177 "/home/claude/cfront-3/src/simpl2.cpp"
__2tpx = trim_tail__FP4stmt ( __1tt -> s__4stmt ) ;
tpxl :
# 179 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2tpx == 0 )return (struct stmt *)0 ;

# 181 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__2tpx -> base__4node ){ 
# 182 "/home/claude/cfront-3/src/simpl2.cpp"
case 72 :
# 183 "/home/claude/cfront-3/src/simpl2.cpp"
break ;
case 7 :
# 185 "/home/claude/cfront-3/src/simpl2.cpp"
case 3 :
# 186 "/home/claude/cfront-3/src/simpl2.cpp"
case 19 :
# 187 "/home/claude/cfront-3/src/simpl2.cpp"
case 28 :
# 188 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1tt -> s_list__4stmt -> base__4node != 115 )__1tt -> s_list__4stmt = 0 ;
default :
# 190 "/home/claude/cfront-3/src/simpl2.cpp"
return __2tpx ;
}
default :
# 193 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1tt = __1tt -> s_list__4stmt )break ;
return (struct stmt *)0 ;
case 28 :
# 196 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1tt -> s_list__4stmt -> base__4node != 115 )__1tt -> s_list__4stmt = 0 ;
return __1tt ;
}
}

# 201 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__1tt -> base__4node ){ 
# 202 "/home/claude/cfront-3/src/simpl2.cpp"
case 166 :return trim_tail__FP4stmt ( __1tt -> __O2__4stmt.s2 ) ;

# 204 "/home/claude/cfront-3/src/simpl2.cpp"
case 116 :if (__1tt -> s__4stmt )return trim_tail__FP4stmt ( __1tt -> s__4stmt ) ;
default :return __1tt ;
}
}

# 209 "/home/claude/cfront-3/src/simpl2.cpp"
extern Ptype Pfct_type ;

# 942 "/home/claude/cfront-3/src/cfront.h"

# 848 "/home/claude/cfront-3/src/cfront.h"

# 211 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr mptr_assign__FP4exprT1 (Pexpr __1n , Pexpr __1in )
# 212 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 213 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1i1 ;
Pexpr __1i2 ;
Pexpr __1i3 ;

# 217 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1n -> base__4node == 85 )
# 218 "/home/claude/cfront-3/src/simpl2.cpp"
( ((((struct name *)(((struct name *)__1n ))))-> n_used__4name ++ ), (((void )0 ))) ;

# 220 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1in -> base__4node == 85 ){ 
# 220 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X30 ;

# 220 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X31 ;

# 220 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X32 ;

# 221 "/home/claude/cfront-3/src/simpl2.cpp"
__1i1 = (struct expr *)( (__0__X30 = 0 ), ( ((__0__X30 || (__0__X30 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 221 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X30 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X30 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 221 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X30 -> __O3__4expr.string2 = ((const char *)"d")), (__0__X30 -> __O4__4expr.mem = __1in )) )
# 221 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X30 ) ) ;
__1i1 -> __O2__4expr.i1 = 9 ;
__1i2 = (struct expr *)( (__0__X31 = 0 ), ( ((__0__X31 || (__0__X31 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 223 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X31 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X31 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 223 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X31 -> __O3__4expr.string2 = ((const char *)"i")), (__0__X31 -> __O4__4expr.mem = __1in )) )
# 223 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X31 ) ) ;
__1i2 -> __O2__4expr.i1 = 9 ;
__1i3 = (struct expr *)( (__0__X32 = 0 ), ( ((__0__X32 || (__0__X32 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 225 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X32 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X32 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 225 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X32 -> __O3__4expr.string2 = ((const char *)"f")), (__0__X32 -> __O4__4expr.mem = __1in )) )
# 225 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X32 ) ) ;
__1i3 -> __O2__4expr.i1 = 9 ;
}
else if (__1in -> base__4node == 86 ){ 
# 229 "/home/claude/cfront-3/src/simpl2.cpp"
__1i1 = zero ;
__1i2 = zero ;
__1i3 = zero ;
}
else { 
# 234 "/home/claude/cfront-3/src/simpl2.cpp"
__1i1 = (__1in -> __O2__4expr.e1 -> __O2__4expr.e1 ?__1in -> __O2__4expr.e1 -> __O2__4expr.e1 :zero );
__1i2 = (__1in -> __O2__4expr.e1 -> __O3__4expr.e2 ?__1in -> __O2__4expr.e1 -> __O3__4expr.e2 :zero );
__1i3 = (__1in -> __O3__4expr.e2 ?__1in -> __O3__4expr.e2 :zero );
}
{ Pexpr __1nd ;

# 239 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X35 ;

# 238 "/home/claude/cfront-3/src/simpl2.cpp"
__1nd = (struct expr *)( (__0__X35 = 0 ), ( ((__0__X35 || (__0__X35 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 238 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X35 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X35 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 238 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X35 -> __O3__4expr.string2 = ((const char *)"d")), (__0__X35 -> __O4__4expr.mem = __1n )) )
# 238 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X35 ) ) ;
__1nd -> __O2__4expr.i1 = 9 ;
{ Pexpr __1e1 ;

# 242 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1ni ;

# 243 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X34 ;

# 240 "/home/claude/cfront-3/src/simpl2.cpp"
__1e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __1nd , __1i1 ) ;

# 242 "/home/claude/cfront-3/src/simpl2.cpp"
__1ni = (struct expr *)( (__0__X34 = 0 ), ( ((__0__X34 || (__0__X34 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 242 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X34 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X34 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 242 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X34 -> __O3__4expr.string2 = ((const char *)"i")), (__0__X34 -> __O4__4expr.mem = __1n )) )
# 242 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X34 ) ) ;
__1ni -> __O2__4expr.i1 = 9 ;
{ Pexpr __1e2 ;

# 246 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1nf ;

# 247 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X33 ;

# 244 "/home/claude/cfront-3/src/simpl2.cpp"
__1e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __1ni , __1i2 ) ;

# 246 "/home/claude/cfront-3/src/simpl2.cpp"
__1nf = (struct expr *)( (__0__X33 = 0 ), ( ((__0__X33 || (__0__X33 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 246 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X33 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X33 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 246 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X33 -> __O3__4expr.string2 = ((const char *)"f")), (__0__X33 -> __O4__4expr.mem = __1n )) )
# 246 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X33 ) ) ;
__1nf -> __O2__4expr.i1 = 9 ;
{ Pexpr __1e3 ;

# 250 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1ee ;

# 248 "/home/claude/cfront-3/src/simpl2.cpp"
__1e3 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __1nf , __1i3 ) ;

# 250 "/home/claude/cfront-3/src/simpl2.cpp"
__1ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1e2 , __1e3 ) ;
return __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1e1 , __1ee ) ;

# 251 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 251 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 251 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 251 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 267 "/home/claude/cfront-3/src/simpl2.cpp"
Ptable tmp_tbl = 0 ;
static Pname tmp_list ;
static Ptable Ntmp_tbl ;
static Pstmt tmp_dtor ;
bit need_lift = 0 ;
Pexpr Ntmp_dtor = 0 ;

# 275 "/home/claude/cfront-3/src/simpl2.cpp"
static bit need_lift_dtors__FP4expr (Pexpr __1e )
# 276 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 278 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1ee ;

# 278 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1ex ;

# 280 "/home/claude/cfront-3/src/simpl2.cpp"
for(__1ex = Ntmp_dtor ;__1ex ;__1ex = __1ex -> __O3__4expr.e2 ) { 
# 281 "/home/claude/cfront-3/src/simpl2.cpp"
__1ee = __1ex -> __O2__4expr.e1 ;
if (__1ee == __1e )break ;
}
if (! __1ex )return (unsigned char )0 ;
return (unsigned char )1 ;
}

# 1294 "/home/claude/cfront-3/src/cfront.h"

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 467 "/home/claude/cfront-3/src/cfront.h"

# 1229 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr call_dtor__FP4exprN21iT1 (Pexpr __0p , Pexpr __0dtor , Pexpr __0arg , int __0d , Pexpr __0vb_args );

# 805 "/home/claude/cfront-3/src/cfront.h"
void simpl__4exprFv (struct expr *__0this );

# 289 "/home/claude/cfront-3/src/simpl2.cpp"
static Pexpr make_dtor_expr__FP4name (Pname __1nl )
# 290 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 291 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1dl ;
Pname __1n ;

# 291 "/home/claude/cfront-3/src/simpl2.cpp"
__1dl = 0 ;

# 294 "/home/claude/cfront-3/src/simpl2.cpp"
for(__1n = __1nl ;__1n ;__1n = __1n -> __O1__4name.n_list ) { 
# 294 "/home/claude/cfront-3/src/simpl2.cpp"
register struct table *__0__X36 ;

# 294 "/home/claude/cfront-3/src/simpl2.cpp"
struct name *__1__Xnn00aqkw3vgovcnm ;

# 297 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X36 = tmp_tbl ), ( (__1__Xnn00aqkw3vgovcnm = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ), ( (((*__1__Xnn00aqkw3vgovcnm ))=
# 297 "/home/claude/cfront-3/src/simpl2.cpp"
(*__1n )), ( (__1__Xnn00aqkw3vgovcnm -> __O4__4expr.n_table = 0 ), ( (__1__Xnn00aqkw3vgovcnm -> n_tbl_list__4name = 0 ), insert__5tableFP4nameUc ( __0__X36 , __1__Xnn00aqkw3vgovcnm , ((unsigned char
# 297 "/home/claude/cfront-3/src/simpl2.cpp"
)0 )) ) ) ) ) ) ;
{ Pname __2cln ;
Pname __2d ;
Pexpr __2e ;

# 301 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__0__X37 ;

# 298 "/home/claude/cfront-3/src/simpl2.cpp"
__2cln = is_cl_obj__4typeFv ( __1n -> __O1__4expr.tp ) ;
__2d = ( (__0__X37 = (((struct classdef *)(((struct classdef *)__2cln -> __O1__4expr.tp ))))), ( __0__X37 -> c_dtor__8classdef ) ) ;
__2e = call_dtor__FP4exprN21iT1 ( (struct expr *)__1n , (struct expr *)__2d , (struct expr *)0 , 45 , one ) ;
if (__1dl == 0 )
# 302 "/home/claude/cfront-3/src/simpl2.cpp"
__1dl = __2e ;
else { 
# 304 "/home/claude/cfront-3/src/simpl2.cpp"
__1dl = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1dl , __2e ) ;
__1dl -> __O1__4expr.tp = __2e -> __O1__4expr.tp ;
}

# 306 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
if (__1dl )simpl__4exprFv ( __1dl ) ;
return __1dl ;
}

# 312 "/home/claude/cfront-3/src/simpl2.cpp"
static int prune ;

# 314 "/home/claude/cfront-3/src/simpl2.cpp"
static void find_temps_in_expr__FP4exprPCc (Pexpr __1e , const char *__1s );

# 467 "/home/claude/cfront-3/src/cfront.h"

# 122 "/home/claude/cfront-3/src/cfront.h"
extern int is_probably_temp__FPCc (const char *);

# 314 "/home/claude/cfront-3/src/simpl2.cpp"
static void find_temps_in_expr__FP4exprPCc (Pexpr __1e , const char *__1s )
# 315 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 316 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1e == 0 )return ;

# 318 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__1e -> base__4node ){ 
# 319 "/home/claude/cfront-3/src/simpl2.cpp"
case 66 :
# 320 "/home/claude/cfront-3/src/simpl2.cpp"
case 67 :
# 321 "/home/claude/cfront-3/src/simpl2.cpp"
case 68 :
# 322 "/home/claude/cfront-3/src/simpl2.cpp"
if (prune )return ;
if (__1s && tmp_list )return ;
find_temps_in_expr__FP4exprPCc ( __1e -> __O4__4expr.cond , __1s ) ;
default :
# 326 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1s && tmp_list )return ;
find_temps_in_expr__FP4exprPCc ( __1e -> __O2__4expr.e1 , __1s ) ;
if (__1s && tmp_list )return ;
find_temps_in_expr__FP4exprPCc ( __1e -> __O3__4expr.e2 , __1s ) ;
return ;
case 44 :case 45 :
# 332 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1s && tmp_list )return ;
find_temps_in_expr__FP4exprPCc ( __1e -> __O2__4expr.e1 , __1s ) ;
case 177 :
# 336 "/home/claude/cfront-3/src/simpl2.cpp"
case 30 :case 86 :
# 337 "/home/claude/cfront-3/src/simpl2.cpp"
case 123 :case 81 :
# 338 "/home/claude/cfront-3/src/simpl2.cpp"
case 82 :case 80 :
# 339 "/home/claude/cfront-3/src/simpl2.cpp"
case 83 :case 84 :
# 340 "/home/claude/cfront-3/src/simpl2.cpp"
case 150 :case 116 :
# 341 "/home/claude/cfront-3/src/simpl2.cpp"
case 169 :
# 342 "/home/claude/cfront-3/src/simpl2.cpp"
case 165 :
# 343 "/home/claude/cfront-3/src/simpl2.cpp"
return
# 343 "/home/claude/cfront-3/src/simpl2.cpp"
;
case 85 :
# 345 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 346 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __3n ;
Pname __3cln ;

# 348 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__0__X38 ;

# 346 "/home/claude/cfront-3/src/simpl2.cpp"
__3n = (((struct name *)(((struct name *)__1e ))));
__3cln = is_cl_obj__4typeFv ( __3n -> __O1__4expr.tp ) ;
if ((__3cln && ( (__0__X38 = (((struct classdef *)(((struct classdef *)__3cln -> __O1__4expr.tp ))))), ( __0__X38 -> c_dtor__8classdef ) ) )&& is_probably_temp__FPCc (
# 348 "/home/claude/cfront-3/src/simpl2.cpp"
__3n -> __O2__4expr.string ) )
# 351 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 353 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1s ){ 
# 354 "/home/claude/cfront-3/src/simpl2.cpp"
if (strcmp ( __1s , __3n -> __O2__4expr.string ) == 0 )
# 355 "/home/claude/cfront-3/src/simpl2.cpp"
tmp_list = __3n ;
return ;
}

# 359 "/home/claude/cfront-3/src/simpl2.cpp"
if (tmp_list == 0 )
# 360 "/home/claude/cfront-3/src/simpl2.cpp"
tmp_list = __3n ;
else { 
# 362 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __5nn ;

# 362 "/home/claude/cfront-3/src/simpl2.cpp"
__5nn = tmp_list ;
if (__3n == __5nn )return ;
while (__5nn -> __O1__4name.n_list ){ 
# 365 "/home/claude/cfront-3/src/simpl2.cpp"
__5nn = __5nn -> __O1__4name.n_list ;
if (__3n == __5nn )return ;
}
__5nn -> __O1__4name.n_list = __3n ;
}
}
return ;
}
}
}

# 377 "/home/claude/cfront-3/src/simpl2.cpp"
static bit find_in_Ntmp__FPCc (const char *__1s )
# 378 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 380 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1ee ;

# 380 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1ex ;

# 382 "/home/claude/cfront-3/src/simpl2.cpp"
tmp_list = 0 ;
for(__1ex = Ntmp_dtor ;__1ex ;__1ex = __1ex -> __O3__4expr.e2 ) { 
# 384 "/home/claude/cfront-3/src/simpl2.cpp"
__1ee = __1ex -> __O2__4expr.e1 ;

# 387 "/home/claude/cfront-3/src/simpl2.cpp"
find_temps_in_expr__FP4exprPCc ( __1ee , __1s ) ;
if (tmp_list ){ tmp_list = 0 ;

# 388 "/home/claude/cfront-3/src/simpl2.cpp"
return (unsigned char )1 ;

# 388 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
return (unsigned char )0 ;
}

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 394 "/home/claude/cfront-3/src/simpl2.cpp"
static void mk_dtor_for_temp__FP4nameT1 (Pname __1tmp , Pname __1dtor )
# 395 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 398 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1dl ;
Pstmt __1dls ;

# 400 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X39 ;

# 400 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X40 ;

# 398 "/home/claude/cfront-3/src/simpl2.cpp"
__1dl = call_dtor__FP4exprN21iT1 ( (struct expr *)__1tmp , (struct expr *)__1dtor , (struct expr *)0 , 45 , one ) ;
__1dls = (struct stmt *)( (__0__X39 = 0 ), ( (__2__X40 = __1tmp -> where__4name ), ( ((__0__X39 || (__0__X39 = (struct estmt *)__nw__4stmtSFUl (
# 399 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X39 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X39 ), ((unsigned char )72 ), __2__X40 ,
# 399 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X39 -> __O2__4stmt.e = __1dl )) :0 ), __0__X39 ) ) ) ;
if (tmp_dtor ){ 
# 401 "/home/claude/cfront-3/src/simpl2.cpp"
__1dls -> s_list__4stmt = tmp_dtor ;
tmp_dtor = __1dls ;
}
else tmp_dtor = __1dls ;
}

# 1234 "/home/claude/cfront-3/src/cfront.h"
extern Pname make_tmp__FcP4typeP5table (char , Ptype , Ptable );

# 467 "/home/claude/cfront-3/src/cfront.h"

# 408 "/home/claude/cfront-3/src/simpl2.cpp"
static Pexpr lift_dtors__FP4exprP5table (Pexpr __1e , Ptable __1tbl )
# 409 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 412 "/home/claude/cfront-3/src/simpl2.cpp"
prune = 1 ;

# 412 "/home/claude/cfront-3/src/simpl2.cpp"
tmp_list = 0 ;

# 412 "/home/claude/cfront-3/src/simpl2.cpp"
find_temps_in_expr__FP4exprPCc ( __1e -> __O2__4expr.e1 , (const char *)0 ) ;

# 412 "/home/claude/cfront-3/src/simpl2.cpp"
prune = 0 ;
{ Pname __1n1 ;

# 413 "/home/claude/cfront-3/src/simpl2.cpp"
__1n1 = tmp_list ;

# 413 "/home/claude/cfront-3/src/simpl2.cpp"
tmp_list = 0 ;

# 415 "/home/claude/cfront-3/src/simpl2.cpp"
prune = 1 ;

# 415 "/home/claude/cfront-3/src/simpl2.cpp"
find_temps_in_expr__FP4exprPCc ( __1e -> __O3__4expr.e2 , (const char *)0 ) ;

# 415 "/home/claude/cfront-3/src/simpl2.cpp"
prune = 0 ;
{ Pname __1n2 ;

# 416 "/home/claude/cfront-3/src/simpl2.cpp"
__1n2 = tmp_list ;

# 416 "/home/claude/cfront-3/src/simpl2.cpp"
tmp_list = 0 ;

# 419 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1tbl == 0 )__1tbl = scope ;
{ Ptype __1t ;

# 420 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __1tmp ;

# 420 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1ex ;

# 422 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1dl ;

# 452 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __1cn ;

# 452 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __1d ;

# 453 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__0__X41 ;

# 420 "/home/claude/cfront-3/src/simpl2.cpp"
__1t = 0 ;

# 420 "/home/claude/cfront-3/src/simpl2.cpp"
__1tmp = 0 ;

# 422 "/home/claude/cfront-3/src/simpl2.cpp"
__1dl = make_dtor_expr__FP4name ( __1n1 ) ;
if (__1dl ){ 
# 424 "/home/claude/cfront-3/src/simpl2.cpp"
__1t = __1e -> __O2__4expr.e1 -> __O1__4expr.tp ;
__1tmp = make_tmp__FcP4typeP5table ( 'Q' , __1t , __1tbl ) ;
__1tmp -> n_assigned_to__4name ++ ;
__1ex = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1tmp , __1e -> __O2__4expr.e1 ) ;

# 427 "/home/claude/cfront-3/src/simpl2.cpp"
__1ex -> __O1__4expr.tp = __1t ;
__1e -> __O2__4expr.e1 = __1ex ;

# 428 "/home/claude/cfront-3/src/simpl2.cpp"
__1e -> __O2__4expr.e1 -> __O1__4expr.tp = __1t ;
__1e -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1e -> __O2__4expr.e1 , __1dl ) ;

# 429 "/home/claude/cfront-3/src/simpl2.cpp"
__1e -> __O2__4expr.e1 -> __O1__4expr.tp = __1dl -> __O1__4expr.tp ;
__1e -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1e -> __O2__4expr.e1 , (struct expr *)__1tmp ) ;

# 430 "/home/claude/cfront-3/src/simpl2.cpp"
__1e -> __O2__4expr.e1 -> __O1__4expr.tp = __1t ;
}

# 433 "/home/claude/cfront-3/src/simpl2.cpp"
__1dl = make_dtor_expr__FP4name ( __1n2 ) ;
if (__1dl ){ 
# 436 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1e -> __O3__4expr.e2 -> __O1__4expr.tp != __1t ){ 
# 437 "/home/claude/cfront-3/src/simpl2.cpp"
__1t = __1e -> __O3__4expr.e2 -> __O1__4expr.tp ;
__1tmp = make_tmp__FcP4typeP5table ( 'Q' , __1t , __1tbl ) ;
}
__1tmp -> n_assigned_to__4name ++ ;
__1ex = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1tmp , __1e -> __O3__4expr.e2 ) ;

# 441 "/home/claude/cfront-3/src/simpl2.cpp"
__1ex -> __O1__4expr.tp = __1t ;
__1e -> __O3__4expr.e2 = __1ex ;

# 442 "/home/claude/cfront-3/src/simpl2.cpp"
__1e -> __O3__4expr.e2 -> __O1__4expr.tp = __1t ;
__1e -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1e -> __O3__4expr.e2 , __1dl ) ;

# 443 "/home/claude/cfront-3/src/simpl2.cpp"
__1e -> __O3__4expr.e2 -> __O1__4expr.tp = __1dl -> __O1__4expr.tp ;
__1e -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1e -> __O3__4expr.e2 , (struct expr *)__1tmp ) ;

# 444 "/home/claude/cfront-3/src/simpl2.cpp"
__1e -> __O3__4expr.e2 -> __O1__4expr.tp = __1t ;
}

# 452 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 452 "/home/claude/cfront-3/src/simpl2.cpp"
;
if (((__1e -> base__4node == 68 )&& (__1cn = is_cl_obj__4typeFv ( __1t ) ))&& (__1d = ( (__0__X41 = (((struct classdef *)(((struct classdef *)__1cn ->
# 453 "/home/claude/cfront-3/src/simpl2.cpp"
__O1__4expr.tp ))))), ( __0__X41 -> c_dtor__8classdef ) ) ))
# 456 "/home/claude/cfront-3/src/simpl2.cpp"
mk_dtor_for_temp__FP4nameT1 ( __1tmp , __1d ) ;

# 458 "/home/claude/cfront-3/src/simpl2.cpp"
return __1e ;

# 458 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 458 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 458 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 462 "/home/claude/cfront-3/src/simpl2.cpp"
static Pexpr lift_dtors__FRP4exprP5tableUc (Pexpr *__1e , Ptable __1tbl , TOK __1__A42 )
# 463 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 466 "/home/claude/cfront-3/src/simpl2.cpp"
prune = 1 ;

# 466 "/home/claude/cfront-3/src/simpl2.cpp"
tmp_list = 0 ;

# 466 "/home/claude/cfront-3/src/simpl2.cpp"
find_temps_in_expr__FP4exprPCc ( (*__1e ), (const char *)0 ) ;

# 466 "/home/claude/cfront-3/src/simpl2.cpp"
prune = 0 ;
{ Pname __1n1 ;

# 467 "/home/claude/cfront-3/src/simpl2.cpp"
__1n1 = tmp_list ;

# 467 "/home/claude/cfront-3/src/simpl2.cpp"
tmp_list = 0 ;

# 470 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1tbl == 0 )__1tbl = scope ;

# 472 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __1dl ;

# 472 "/home/claude/cfront-3/src/simpl2.cpp"
__1dl = make_dtor_expr__FP4name ( __1n1 ) ;
if (__1dl ){ 
# 474 "/home/claude/cfront-3/src/simpl2.cpp"
Ptype __2t ;
Pname __2tmp ;

# 474 "/home/claude/cfront-3/src/simpl2.cpp"
__2t = ((*__1e ))-> __O1__4expr.tp ;
__2tmp = make_tmp__FcP4typeP5table ( 'Q' , __2t , __1tbl ) ;
__2tmp -> n_assigned_to__4name ++ ;

# 478 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __2ex ;

# 478 "/home/claude/cfront-3/src/simpl2.cpp"
__2ex = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__2tmp , (*__1e )) ;

# 478 "/home/claude/cfront-3/src/simpl2.cpp"
__2ex -> __O1__4expr.tp = __2t ;
((*__1e ))= __2ex ;

# 479 "/home/claude/cfront-3/src/simpl2.cpp"
((*__1e ))-> __O1__4expr.tp = __2t ;
((*__1e ))= __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , (*__1e ), __1dl ) ;

# 480 "/home/claude/cfront-3/src/simpl2.cpp"
((*__1e ))-> __O1__4expr.tp = __1dl -> __O1__4expr.tp ;
((*__1e ))= __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , (*__1e ), (struct expr *)__2tmp ) ;

# 481 "/home/claude/cfront-3/src/simpl2.cpp"
((*__1e ))-> __O1__4expr.tp = __2t ;

# 481 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
return ((*__1e ));

# 483 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 483 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 226 "/home/claude/cfront-3/src/cfront.h"
void reinit__5tableFv (struct table *__0this );

# 1018 "/home/claude/cfront-3/src/cfront.h"
Pstmt simpl__4stmtFv (struct stmt *__0this );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 535 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr mk_zero_init__FP4typeP4nameT2 (Ptype , Pname , Pname );

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 467 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/incl-linux32/ctype.h"
extern int isdigit (int );

# 467 "/home/claude/cfront-3/src/cfront.h"

# 22 "/home/claude/incl-linux32/string.h"
extern int strncmp (const char *, const char *, size_t );

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 470 "/home/claude/cfront-3/src/cfront.h"
Pname has_ictor__8classdefFv (struct classdef *__0this );

# 469 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 1083 "/home/claude/cfront-3/src/cfront.h"

# 486 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt simpl__5blockFv (register struct block *__0this )
# 487 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 488 "/home/claude/cfront-3/src/simpl2.cpp"
int __1i ;
Pname __1n ;
Pstmt __1ss ;

# 490 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __1sst ;
Pstmt __1dd ;

# 491 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __1ddt ;
Pstmt __1stail ;
Ptable __1old_scope ;
const char *__1fudge_007 ;

# 490 "/home/claude/cfront-3/src/simpl2.cpp"
__1ss = 0 ;

# 490 "/home/claude/cfront-3/src/simpl2.cpp"
__1sst = 0 ;
__1dd = 0 ;

# 491 "/home/claude/cfront-3/src/simpl2.cpp"
__1ddt = 0 ;

# 493 "/home/claude/cfront-3/src/simpl2.cpp"
__1old_scope = scope ;
__1fudge_007 = 0 ;

# 496 "/home/claude/cfront-3/src/simpl2.cpp"
if (! need_lift )reinit__5tableFv ( tmp_tbl ) ;

# 500 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 502 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O2__4stmt.own_tbl == 0 ){ 
# 503 "/home/claude/cfront-3/src/simpl2.cpp"
__1ss = (__0this -> s__4stmt ?simpl__4stmtFv ( __0this -> s__4stmt ) :(((struct stmt *)0 )));
return __1ss ;
}

# 507 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pfct __1f ;

# 508 "/home/claude/cfront-3/src/simpl2.cpp"
struct table *__0__X46 ;

# 508 "/home/claude/cfront-3/src/simpl2.cpp"
int __2__X47 ;

# 508 "/home/claude/cfront-3/src/simpl2.cpp"
struct table *__0__X48 ;

# 508 "/home/claude/cfront-3/src/simpl2.cpp"
int __2__X49 ;

# 508 "/home/claude/cfront-3/src/simpl2.cpp"
register struct name *__0__X93 ;

# 508 "/home/claude/cfront-3/src/simpl2.cpp"
unsigned long __2__X16 ;

# 508 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__X__V1400qmdw3vgovcnm ;

# 508 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__X__V1500qmdw3vgovcnm ;

# 507 "/home/claude/cfront-3/src/simpl2.cpp"
__1f = ( (__0__X93 = curr_fct ), ( ((__0__X93 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X93 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int
# 507 "/home/claude/cfront-3/src/simpl2.cpp"
)'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qmdw3vgovcnm )-> __O1__2ea.p =
# 507 "/home/claude/cfront-3/src/simpl2.cpp"
((const void *)__0__X93 )), (& __0__X__V1400qmdw3vgovcnm )) , (const struct ea *)( (__2__X16 = __0__X93 -> __O1__4expr.tp -> base__4node ), (
# 507 "/home/claude/cfront-3/src/simpl2.cpp"
(( ((& __0__X__V1500qmdw3vgovcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmdw3vgovcnm )) ) , (const struct ea *)ea0 ,
# 507 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) ;

# 509 "/home/claude/cfront-3/src/simpl2.cpp"
scope = __0this -> memtbl__4stmt ;
if (scope -> init_stat__5table == 0 )scope -> init_stat__5table = 1 ;

# 512 "/home/claude/cfront-3/src/simpl2.cpp"
for(__1n = ( (__0__X46 = scope ), ( (__2__X47 = (__1i = 1 )), ( (((__2__X47 <= 0 )|| (__0__X46 -> free_slot__5table <= __2__X47 ))?(((struct
# 512 "/home/claude/cfront-3/src/simpl2.cpp"
name *)0 )):(__0__X46 -> entries__5table [__2__X47 ]))) ) ) ;__1n ;__1n = (__1n -> n_tbl_list__4name ?__1n -> n_tbl_list__4name :( (__0__X48 = scope ), ( (__2__X49 = (++ __1i )),
# 512 "/home/claude/cfront-3/src/simpl2.cpp"
( (((__2__X49 <= 0 )|| (__0__X48 -> free_slot__5table <= __2__X49 ))?(((struct name *)0 )):(__0__X48 -> entries__5table [__2__X49 ]))) ) ) )) { 
# 513 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __2st ;
bit __2is_nrv ;
Pname __2cln ;
Pexpr __2in ;

# 513 "/home/claude/cfront-3/src/simpl2.cpp"
__2st = 0 ;
__2is_nrv = (! strcmp ( __1n -> __O2__4expr.string , (const char *)"__NRV") );

# 516 "/home/claude/cfront-3/src/simpl2.cpp"
__2in = __1n -> __O3__4expr.n_initializer ;

# 518 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2in || __1n -> n_evaluated__4name ){ 
# 519 "/home/claude/cfront-3/src/simpl2.cpp"
scope -> init_stat__5table = 2 ;
if (__1n -> n_sto__4name == 14 ){ 
# 521 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 521 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V43 ;

# 521 "/home/claude/cfront-3/src/simpl2.cpp"
error__FP3locPCcRC2eaN33 ( & __1n -> where__4name , (const char *)"Id local extern%n", (const struct ea *)(
# 521 "/home/claude/cfront-3/src/simpl2.cpp"
((& __0__V43 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V43 )) , (const struct ea *)ea0 , (const struct
# 521 "/home/claude/cfront-3/src/simpl2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
continue ;
} }
}

# 526 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__1n -> n_scope__4name ){ 
# 527 "/home/claude/cfront-3/src/simpl2.cpp"
case 136 :
# 528 "/home/claude/cfront-3/src/simpl2.cpp"
case 0 :
# 529 "/home/claude/cfront-3/src/simpl2.cpp"
case 25 :
# 530 "/home/claude/cfront-3/src/simpl2.cpp"
continue ;
}

# 533 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1n -> n_stclass__4name == 31 ){ 
# 543 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__2in == 0 )&& (__1n -> n_scope__4name == 137 ))|| (__2in && (__2in -> base__4node == 186 )))
# 545 "/home/claude/cfront-3/src/simpl2.cpp"
{
# 545 "/home/claude/cfront-3/src/simpl2.cpp"

# 546 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __4cn ;
Pname __4x ;
Ptype __4ct ;
int __4vec_seen ;

# 572 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __4set ;

# 549 "/home/claude/cfront-3/src/simpl2.cpp"
__4vec_seen = 0 ;

# 551 "/home/claude/cfront-3/src/simpl2.cpp"
__4cn = is_cl_obj__4typeFv ( __1n -> __O1__4expr.tp ) ;
if (__4cn == 0 ){ ++ __4vec_seen ;

# 552 "/home/claude/cfront-3/src/simpl2.cpp"
__4cn = cl_obj_vec ;

# 552 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 554 "/home/claude/cfront-3/src/simpl2.cpp"
if (__4cn ){ 
# 555 "/home/claude/cfront-3/src/simpl2.cpp"
__4ct = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __4vec_seen ?(((struct vec *)(((struct vec *)__1n -> __O1__4expr.tp ))))->
# 555 "/home/claude/cfront-3/src/simpl2.cpp"
typ__5pvtyp :__1n -> __O1__4expr.tp ) ;
__4x = make_tmp__FcP4typeP5table ( 'F' , __4ct , gtbl ) ;

# 558 "/home/claude/cfront-3/src/simpl2.cpp"
__4x -> __O3__4expr.n_initializer = mk_zero_init__FP4typeP4nameT2 ( __4x -> __O1__4expr.tp , __1n , __1n ) ;
}
else 
# 561 "/home/claude/cfront-3/src/simpl2.cpp"
__4x = make_tmp__FcP4typeP5table ( 'F' , (struct type *)int_type , scope ) ;

# 563 "/home/claude/cfront-3/src/simpl2.cpp"
__4x -> n_sto__4name = (__1n -> n_stclass__4name = 31 );
__4x -> where__4name = __1n -> where__4name ;

# 566 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2in ){ 
# 567 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2in -> __O3__4expr.e2 )
# 568 "/home/claude/cfront-3/src/simpl2.cpp"
__2in -> base__4node = 70 ;
else __2in = __2in -> __O2__4expr.e1 ;
}

# 572 "/home/claude/cfront-3/src/simpl2.cpp"
;
if (__4cn ){ 
# 574 "/home/claude/cfront-3/src/simpl2.cpp"
dcl_print__4nameFUc ( __4x , (unsigned char )0 ) ;
{ Pclass __5cl ;
Pname __5dtor ;

# 578 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __5cc ;

# 603 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __5xe ;

# 575 "/home/claude/cfront-3/src/simpl2.cpp"
__5cl = (((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp ))));
__5dtor = ( __5cl -> c_dtor__8classdef ) ;

# 579 "/home/claude/cfront-3/src/simpl2.cpp"
if (__5dtor ){ 
# 580 "/home/claude/cfront-3/src/simpl2.cpp"
if (__4vec_seen == 0 ){ 
# 581 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __7eee ;
Pexpr __7c ;

# 584 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __7e4 ;

# 581 "/home/claude/cfront-3/src/simpl2.cpp"
__7eee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , (struct expr *)__4x , (struct expr *)0 ) ;
__7c = call_dtor__FP4exprN21iT1 ( __7eee , (struct expr *)__5dtor , (struct expr *)0 , 45 , one ) ;
__7c -> __O1__4expr.tp = (struct type *)any_type ;
;
if (ansi_opt ){ 
# 586 "/home/claude/cfront-3/src/simpl2.cpp"
__7e4 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __7c , zero ) ;
__7e4 -> __O1__4expr.tp = (struct type *)zero_type ;
}
else { 
# 590 "/home/claude/cfront-3/src/simpl2.cpp"
__7e4 = __7c ;
}
__5cc = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , __7e4 , zero ) ;
__5cc -> __O4__4expr.cond = (struct expr *)__4x ;
}
else __5cc = cdvec__FP4nameP4exprP8classdefT1iN22 ( vec_del_fct , (struct expr *)__4x , __5cl , __5dtor , 0 , zero , (struct expr *)__1n ) ;
__5cc -> __O1__4expr.tp = (struct type *)any_type ;

# 598 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pstmt __6dls ;

# 599 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X50 ;

# 599 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X51 ;

# 598 "/home/claude/cfront-3/src/simpl2.cpp"
__6dls = (struct stmt *)( (__0__X50 = 0 ), ( (__2__X51 = __1n -> where__4name ), ( ((__0__X50 || (__0__X50 = (struct estmt *)__nw__4stmtSFUl (
# 598 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X50 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X50 ), ((unsigned char )72 ), __2__X51 ,
# 598 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X50 -> __O2__4stmt.e = __5cc )) :0 ), __0__X50 ) ) ) ;
if (st_dlist )__6dls -> s_list__4stmt = st_dlist ;
st_dlist = __6dls ;

# 600 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 603 "/home/claude/cfront-3/src/simpl2.cpp"
;
if (__4cn ){ 
# 605 "/home/claude/cfront-3/src/simpl2.cpp"
if (__4vec_seen == 0 )
# 606 "/home/claude/cfront-3/src/simpl2.cpp"
__5xe = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , (struct
# 606 "/home/claude/cfront-3/src/simpl2.cpp"
expr *)__1n ) ;
else { 
# 608 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __7ee ;

# 608 "/home/claude/cfront-3/src/simpl2.cpp"
__7ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , (struct expr *)__1n , zero ) ;
__5xe = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __7ee ) ;
}
}

# 613 "/home/claude/cfront-3/src/simpl2.cpp"
__4set = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__4x , __5xe ) ;
__4set -> __O1__4expr.tp = __4ct ;

# 614 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
else { 
# 617 "/home/claude/cfront-3/src/simpl2.cpp"
__4set = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__4x , one ) ;
__4set -> __O1__4expr.tp = (struct type *)int_type ;
}

# 623 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__1n -> n_scope__4name == 137 )&& (__2in == 0 )){ 
# 623 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X52 ;

# 623 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X53 ;

# 624 "/home/claude/cfront-3/src/simpl2.cpp"
__4set = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , zero , __4set ) ;
__4set -> __O4__4expr.cond = (struct expr *)__4x ;
__2st = (struct stmt *)( (__0__X52 = 0 ), ( (__2__X53 = __1n -> where__4name ), ( ((__0__X52 || (__0__X52 = (struct estmt *)__nw__4stmtSFUl (
# 626 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X52 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X52 ), ((unsigned char )72 ), __2__X53 ,
# 626 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X52 -> __O2__4stmt.e = __4set )) :0 ), __0__X52 ) ) ) ;
goto init_stat3 ;
}

# 630 "/home/claude/cfront-3/src/simpl2.cpp"
if (one == __4set -> __O3__4expr.e2 )
# 631 "/home/claude/cfront-3/src/simpl2.cpp"
__2in = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __4set , __2in ) ;
else 
# 633 "/home/claude/cfront-3/src/simpl2.cpp"
__2in = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __2in , __4set ) ;
__2in = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )186 , zero , __2in ) ;
__2in -> __O4__4expr.cond = (struct expr *)__4x ;
}
else 
# 638 "/home/claude/cfront-3/src/simpl2.cpp"
continue ;
}

# 641 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2in ){ 
# 642 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__2in -> base__4node == 124 )&& (__2in -> __O3__4expr.e2 == 0 ))|| ((__2in -> base__4node == 81 )&& (skiptypedefs__4typeFv ( __1n ->
# 642 "/home/claude/cfront-3/src/simpl2.cpp"
__O1__4expr.tp ) -> base__4node == 110 )))
# 644 "/home/claude/cfront-3/src/simpl2.cpp"
if (ansi_opt == 0 ){ 
# 645 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 645 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V44 ;

# 645 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & __1n -> where__4name , (const char *)"initialization of%n (automatic aggregate)", (const
# 645 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea *)( ((& __0__V44 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V44 )) , (const struct ea *)ea0 ,
# 645 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
continue ;
} }
else { 
# 649 "/home/claude/cfront-3/src/simpl2.cpp"
__1n -> __O3__4expr.n_initializer = __2in ;
continue ;
}
}

# 654 "/home/claude/cfront-3/src/simpl2.cpp"
if ((((ansi_opt && __2in )&& tconst__4typeFv ( __1n -> __O1__4expr.tp ) )&& (__1n -> __O1__4expr.tp -> base__4node != 110 ))&& (__1n -> n_sto__4name != 31 )){
# 654 "/home/claude/cfront-3/src/simpl2.cpp"

# 658 "/home/claude/cfront-3/src/simpl2.cpp"
(((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp ))))-> ansi_const__4type = 1 ;
}

# 661 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1n -> __O1__4expr.tp == 0 )continue ;
if (__1n -> n_evaluated__4name )continue ;

# 668 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 669 "/home/claude/cfront-3/src/simpl2.cpp"
const char *__3s ;

# 669 "/home/claude/cfront-3/src/simpl2.cpp"
__3s = __1n -> __O2__4expr.string ;

# 671 "/home/claude/cfront-3/src/simpl2.cpp"
if (((((__3s [0 ])== '_' )&& ((__3s [1 ])== '_' ))&& ((__3s [2 ])== 'D' ))&& isdigit ( (int )(__3s [3 ])) )
# 672 "/home/claude/cfront-3/src/simpl2.cpp"
continue ;
}

# 675 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2cln = is_cl_obj__4typeFv ( __1n -> __O1__4expr.tp ) ){ 
# 676 "/home/claude/cfront-3/src/simpl2.cpp"
Pclass __3cl ;
Pname __3d ;

# 676 "/home/claude/cfront-3/src/simpl2.cpp"
__3cl = (((struct classdef *)(((struct classdef *)__2cln -> __O1__4expr.tp ))));
__3d = ( __3cl -> c_dtor__8classdef ) ;

# 679 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__1n -> n_stclass__4name == 31 )&& __2in )&& (__2in -> base__4node == 186 ))
# 681 "/home/claude/cfront-3/src/simpl2.cpp"
goto stat_init ;

# 683 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3d && (! __2is_nrv )){ 
# 687 "/home/claude/cfront-3/src/simpl2.cpp"
if ((Ntmp_dtor && is_probably_temp__FPCc ( __1n -> __O2__4expr.string ) )&& find_in_Ntmp__FPCc ( __1n -> __O2__4expr.string ) )
# 690 "/home/claude/cfront-3/src/simpl2.cpp"
continue
# 690 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 692 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __4dl ;

# 692 "/home/claude/cfront-3/src/simpl2.cpp"
__4dl = call_dtor__FP4exprN21iT1 ( (struct expr *)__1n , (struct expr *)__3d , (struct expr *)0 , 45 , one ) ;

# 694 "/home/claude/cfront-3/src/simpl2.cpp"
if (pdlist && ((strncmp ( (const char *)"__R", __1n -> __O2__4expr.string , (unsigned long
# 694 "/home/claude/cfront-3/src/simpl2.cpp"
)3 ) == 0 )|| (strncmp ( (const char *)"__V", __1n -> __O2__4expr.string , (unsigned
# 694 "/home/claude/cfront-3/src/simpl2.cpp"
long )3 ) == 0 )))
# 696 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 697 "/home/claude/cfront-3/src/simpl2.cpp"
int __5len ;

# 697 "/home/claude/cfront-3/src/simpl2.cpp"
__5len = (strlen ( __1n -> __O2__4expr.string ) + 1 );
{ { struct con_dtor *__5pcd ;

# 698 "/home/claude/cfront-3/src/simpl2.cpp"
__5pcd = pdlist ;

# 698 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__5pcd ;__5pcd = __5pcd -> next__8con_dtor ) { 
# 699 "/home/claude/cfront-3/src/simpl2.cpp"
if (strncmp ( __1n -> __O2__4expr.string , __5pcd -> tn__8con_dtor -> __O2__4expr.string , (unsigned long )__5len )
# 699 "/home/claude/cfront-3/src/simpl2.cpp"
== 0 ){ 
# 700 "/home/claude/cfront-3/src/simpl2.cpp"
__1fudge_007 = __5pcd -> condition__8con_dtor -> __O2__4expr.string ;
{ Pexpr __7e ;

# 701 "/home/claude/cfront-3/src/simpl2.cpp"
__7e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __5pcd -> condition__8con_dtor , zero ) ;
__7e -> __O1__4expr.tp = (struct type *)int_type ;
{ Pexpr __7ee ;

# 703 "/home/claude/cfront-3/src/simpl2.cpp"
__7ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __7e , __4dl ) ;
__7ee -> __O1__4expr.tp = (struct type *)int_type ;
__7ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __7ee , zero ) ;
__7ee -> __O1__4expr.tp = (struct type *)int_type ;
{ Pexpr __7qe ;

# 707 "/home/claude/cfront-3/src/simpl2.cpp"
__7qe = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , __7ee , zero ) ;
__7qe -> __O4__4expr.cond = __5pcd -> condition__8con_dtor ;
__7qe -> __O1__4expr.tp = (struct type *)int_type ;
__4dl = __7qe ;
break ;

# 711 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 711 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 711 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
}

# 713 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 713 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 717 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pstmt __4dls ;

# 718 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X54 ;

# 718 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X55 ;

# 717 "/home/claude/cfront-3/src/simpl2.cpp"
__4dls = (struct stmt *)( (__0__X54 = 0 ), ( (__2__X55 = no_where ), ( ((__0__X54 || (__0__X54 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 717 "/home/claude/cfront-3/src/simpl2.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X54 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X54 ), ((unsigned char )72 ), __2__X55 , ((struct
# 717 "/home/claude/cfront-3/src/simpl2.cpp"
stmt *)0 )) ), (__0__X54 -> __O2__4stmt.e = __4dl )) :0 ), __0__X54 ) ) ) ;
if (__1dd ){ 
# 719 "/home/claude/cfront-3/src/simpl2.cpp"
__4dls -> s_list__4stmt = __1dd ;
__1dd = __4dls ;
}
else 
# 723 "/home/claude/cfront-3/src/simpl2.cpp"
__1ddt = (__1dd = __4dls );

# 723 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 723 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 727 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2in ){ 
# 728 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__2in -> base__4node ){ 
# 728 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X59 ;

# 728 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X60 ;

# 728 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X61 ;

# 728 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X62 ;

# 728 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X63 ;

# 729 "/home/claude/cfront-3/src/simpl2.cpp"
case 111 :
# 730 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2in -> __O2__4expr.e1 -> base__4node == 146 ){ 
# 731 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __6fn ;

# 732 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X56 ;

# 732 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X57 ;

# 732 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X58 ;

# 731 "/home/claude/cfront-3/src/simpl2.cpp"
__6fn = __2in -> __O2__4expr.e1 -> __O4__4expr.fct_name ;
if ((__6fn == 0 )|| (__6fn -> n_oper__4name != 161 ))goto ddd ;
if (__2is_nrv ){ 
# 734 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __7et ;

# 734 "/home/claude/cfront-3/src/simpl2.cpp"
__7et = __2in -> __O2__4expr.e1 -> __O2__4expr.e1 ;
__7et -> __O2__4expr.e1 = (struct expr *)__1f -> f_result__3fct ;
__7et -> base__4node = 44 ;
}
__2st = (struct stmt *)( (__0__X56 = 0 ), ( (__2__X57 = __1n -> where__4name ), ( (__2__X58 = __2in -> __O2__4expr.e1 ), (
# 738 "/home/claude/cfront-3/src/simpl2.cpp"
((__0__X56 || (__0__X56 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X56 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X56 ),
# 738 "/home/claude/cfront-3/src/simpl2.cpp"
((unsigned char )72 ), __2__X57 , ((struct stmt *)0 )) ), (__0__X56 -> __O2__4stmt.e = __2__X58 )) :0 ), __0__X56 ) ) )
# 738 "/home/claude/cfront-3/src/simpl2.cpp"
) ;
__1n -> __O3__4expr.n_initializer = 0 ;
break ;
}
goto ddd ;
case 186 :
# 744 "/home/claude/cfront-3/src/simpl2.cpp"
stat_init :
# 746 "/home/claude/cfront-3/src/simpl2.cpp"
__2in -> base__4node = 68 ;
__2st = (struct stmt *)( (__0__X59 = 0 ), ( (__2__X60 = __1n -> where__4name ), ( ((__0__X59 || (__0__X59 = (struct estmt *)__nw__4stmtSFUl (
# 747 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X59 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X59 ), ((unsigned char )72 ), __2__X60 ,
# 747 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X59 -> __O2__4stmt.e = __2in )) :0 ), __0__X59 ) ) ) ;
__1n -> __O3__4expr.n_initializer = 0 ;
break ;
case 147 :
# 751 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__2is_nrv && ((__2in -> __O2__4expr.e1 -> base__4node == 109 )|| (__2in -> __O2__4expr.e1 -> base__4node == 146 )))&& (__2in -> __O2__4expr.e1 -> __O3__4expr.e2 ->
# 751 "/home/claude/cfront-3/src/simpl2.cpp"
__O2__4expr.e1 -> base__4node == 145 ))&& ((((struct name *)(((struct name *)__2in -> __O2__4expr.e1 -> __O3__4expr.e2 -> __O2__4expr.e1 -> __O3__4expr.e2 ))))== __1n ))
# 760 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 761 "/home/claude/cfront-3/src/simpl2.cpp"
__2in -> __O2__4expr.e1 -> __O3__4expr.e2 ->
# 761 "/home/claude/cfront-3/src/simpl2.cpp"
__O2__4expr.e1 = (struct expr *)__1f -> f_result__3fct ;
}
__2st = (struct stmt *)( (__0__X61 = 0 ), ( (__2__X62 = __1n -> where__4name ), ( (__2__X63 = __2in -> __O2__4expr.e1 ), (
# 763 "/home/claude/cfront-3/src/simpl2.cpp"
((__0__X61 || (__0__X61 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X61 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X61 ),
# 763 "/home/claude/cfront-3/src/simpl2.cpp"
((unsigned char )72 ), __2__X62 , ((struct stmt *)0 )) ), (__0__X61 -> __O2__4stmt.e = __2__X63 )) :0 ), __0__X61 ) ) )
# 763 "/home/claude/cfront-3/src/simpl2.cpp"
) ;
__1n -> __O3__4expr.n_initializer = 0 ;
break ;
case 70 :
# 767 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2in -> __O2__4expr.e1 == (((struct expr *)__1n ))){ 
# 767 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X64 ;

# 767 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X65 ;

# 768 "/home/claude/cfront-3/src/simpl2.cpp"
__2st = (struct stmt *)( (__0__X64 = 0 ), ( (__2__X65 = __1n -> where__4name ), ( ((__0__X64 || (__0__X64 = (struct estmt *)__nw__4stmtSFUl (
# 768 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X64 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X64 ), ((unsigned char )72 ), __2__X65 ,
# 768 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X64 -> __O2__4stmt.e = __2in )) :0 ), __0__X64 ) ) ) ;
__1n -> __O3__4expr.n_initializer = 0 ;
break ;
}
default :
# 773 "/home/claude/cfront-3/src/simpl2.cpp"
goto ddd ;
}
}
}
else if (cl_obj_vec ){ 
# 778 "/home/claude/cfront-3/src/simpl2.cpp"
Pclass __3cl ;
Pname __3d ;
Pname __3c ;

# 781 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X70 ;

# 781 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X71 ;

# 778 "/home/claude/cfront-3/src/simpl2.cpp"
__3cl = (((struct classdef *)(((struct classdef *)cl_obj_vec -> __O1__4expr.tp ))));
__3d = ( __3cl -> c_dtor__8classdef ) ;
__3c = has_ictor__8classdefFv ( __3cl ) ;
__1n -> __O3__4expr.n_initializer = 0 ;

# 783 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__1n -> n_stclass__4name == 31 )&& __2in )&& (__2in -> base__4node == 186 ))
# 785 "/home/claude/cfront-3/src/simpl2.cpp"
goto stat_init2 ;

# 787 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3c ){ 
# 787 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X68 ;

# 787 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X69 ;

# 788 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__2in == 0 )|| (__2in -> base__4node == 124 )){ 
# 790 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __5vctor ;
Pexpr __5a ;

# 792 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X66 ;

# 792 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X67 ;

# 790 "/home/claude/cfront-3/src/simpl2.cpp"
__5vctor = ( __3cl -> c_vtor__8classdef ) ;
__5a = cdvec__FP4nameP4exprP8classdefT1iN22 ( vec_new_fct , (struct expr *)__1n , __3cl , __5vctor ?__5vctor :__3c , -1, (struct expr *)0 , (struct expr *)0 ) ;
__2st = (struct stmt *)( (__0__X66 = 0 ), ( (__2__X67 = __1n -> where__4name ), ( ((__0__X66 || (__0__X66 = (struct estmt *)__nw__4stmtSFUl (
# 792 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X66 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X66 ), ((unsigned char )72 ), __2__X67 ,
# 792 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X66 -> __O2__4stmt.e = __5a )) :0 ), __0__X66 ) ) ) ;
}
else 
# 795 "/home/claude/cfront-3/src/simpl2.cpp"
__2st = (struct stmt *)( (__0__X68 = 0 ), ( (__2__X69 = __1n -> where__4name ), ( ((__0__X68 || (__0__X68 = (struct
# 795 "/home/claude/cfront-3/src/simpl2.cpp"
estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X68 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X68 ), ((unsigned char )72 ),
# 795 "/home/claude/cfront-3/src/simpl2.cpp"
__2__X69 , ((struct stmt *)0 )) ), (__0__X68 -> __O2__4stmt.e = __2in )) :0 ), __0__X68 ) ) ) ;
}
else 
# 798 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2in )__2st = (struct stmt *)( (__0__X70 = 0 ), ( (__2__X71 = __1n -> where__4name ), ( ((__0__X70 || (__0__X70 =
# 798 "/home/claude/cfront-3/src/simpl2.cpp"
(struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X70 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X70 ), ((unsigned char
# 798 "/home/claude/cfront-3/src/simpl2.cpp"
)72 ), __2__X71 , ((struct stmt *)0 )) ), (__0__X70 -> __O2__4stmt.e = __2in )) :0 ), __0__X70 ) ) ) ;

# 801 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3d ){ 
# 802 "/home/claude/cfront-3/src/simpl2.cpp"
Pfct __4f ;
int __4i ;

# 802 "/home/claude/cfront-3/src/simpl2.cpp"
__4f = (((struct fct *)(((struct fct *)__3d -> __O1__4expr.tp ))));
__4i = 0 ;
{ { Pname __4nn ;

# 804 "/home/claude/cfront-3/src/simpl2.cpp"
__4nn = __4f -> f_args__3fct -> __O1__4name.n_list ;

# 804 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__4nn && __4nn -> __O1__4name.n_list ;__4nn = __4nn -> __O1__4name.n_list ) 
# 805 "/home/claude/cfront-3/src/simpl2.cpp"
__4i ++ ;
{ Pexpr __4a ;

# 808 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __4dls ;

# 809 "/home/claude/cfront-3/src/simpl2.cpp"
struct ival *__0__X72 ;

# 809 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X73 ;

# 809 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X74 ;

# 806 "/home/claude/cfront-3/src/simpl2.cpp"
__4a = cdvec__FP4nameP4exprP8classdefT1iN22 ( vec_del_fct , (struct expr *)__1n , __3cl , __3d , 0 , (struct expr *)( (__0__X72 = 0 ), ( ((__0__X72 ||
# 806 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X72 = (struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival))) ))?( (__0__X72 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X72 ), (unsigned
# 806 "/home/claude/cfront-3/src/simpl2.cpp"
char )150 , (struct expr *)0 , (struct expr *)0 ) ), (__0__X72 -> __O2__4expr.i1 = ((long long )__4i ))) :0 ), __0__X72 ) )
# 806 "/home/claude/cfront-3/src/simpl2.cpp"
, (struct expr *)0 ) ;

# 808 "/home/claude/cfront-3/src/simpl2.cpp"
__4dls = (struct stmt *)( (__0__X73 = 0 ), ( (__2__X74 = no_where ), ( ((__0__X73 || (__0__X73 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 808 "/home/claude/cfront-3/src/simpl2.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X73 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X73 ), ((unsigned char )72 ), __2__X74 , ((struct
# 808 "/home/claude/cfront-3/src/simpl2.cpp"
stmt *)0 )) ), (__0__X73 -> __O2__4stmt.e = __4a )) :0 ), __0__X73 ) ) ) ;
if (__1dd ){ 
# 810 "/home/claude/cfront-3/src/simpl2.cpp"
__4dls -> s_list__4stmt = __1dd ;
__1dd = __4dls ;
}
else 
# 814 "/home/claude/cfront-3/src/simpl2.cpp"
__1ddt = (__1dd = __4dls );

# 814 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 814 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 814 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
}
else if (__2in ){ 
# 818 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__2in -> base__4node ){ 
# 818 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X77 ;

# 818 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X78 ;

# 819 "/home/claude/cfront-3/src/simpl2.cpp"
case 124 :
# 820 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__1n -> n_scope__4name ){ 
# 821 "/home/claude/cfront-3/src/simpl2.cpp"
case 108 :
# 822 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2in -> __O3__4expr.e2 ){ 
# 823 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __6ee ;

# 824 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X75 ;

# 824 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X76 ;

# 823 "/home/claude/cfront-3/src/simpl2.cpp"
__6ee = mptr_assign__FP4exprT1 ( (struct expr *)__1n , __2in ) ;
__2st = (struct stmt *)( (__0__X75 = 0 ), ( (__2__X76 = __1n -> where__4name ), ( ((__0__X75 || (__0__X75 = (struct estmt *)__nw__4stmtSFUl (
# 824 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X75 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X75 ), ((unsigned char )72 ), __2__X76 ,
# 824 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X75 -> __O2__4stmt.e = __6ee )) :0 ), __0__X75 ) ) ) ;
__1n -> __O3__4expr.n_initializer = 0 ;
break ;
}
case 136 :
# 829 "/home/claude/cfront-3/src/simpl2.cpp"
if (ansi_opt == 0 ){ 
# 829 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V45 ;

# 829 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"Ir list for localV%n", (const struct ea *)( ((&
# 829 "/home/claude/cfront-3/src/simpl2.cpp"
__0__V45 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V45 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 829 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)ea0 ) ;
} }
break ;
case 186 :
# 833 "/home/claude/cfront-3/src/simpl2.cpp"
stat_init2 :
# 835 "/home/claude/cfront-3/src/simpl2.cpp"
__2in -> base__4node = 68 ;
__2st = (struct stmt *)( (__0__X77 = 0 ), ( (__2__X78 = __1n -> where__4name ), ( ((__0__X77 || (__0__X77 = (struct estmt *)__nw__4stmtSFUl (
# 836 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X77 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X77 ), ((unsigned char )72 ), __2__X78 ,
# 836 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X77 -> __O2__4stmt.e = __2in )) :0 ), __0__X77 ) ) ) ;
__1n -> __O3__4expr.n_initializer = 0 ;
break ;
case 81 :
# 840 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1n -> __O1__4expr.tp -> base__4node == 110 )break ;
default :
# 842 "/home/claude/cfront-3/src/simpl2.cpp"
ddd :
# 843 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 846 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1fudge_007 && (strcmp ( __1n -> __O2__4expr.string , __1fudge_007 ) == 0 ))
# 848 "/home/claude/cfront-3/src/simpl2.cpp"
__1fudge_007 = 0 ;
else { 
# 850 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __6ee ;

# 851 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X79 ;

# 851 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X80 ;

# 850 "/home/claude/cfront-3/src/simpl2.cpp"
__6ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1n , __2in ) ;
__2st = (struct stmt *)( (__0__X79 = 0 ), ( (__2__X80 = __1n -> where__4name ), ( ((__0__X79 || (__0__X79 = (struct estmt *)__nw__4stmtSFUl (
# 851 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X79 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X79 ), ((unsigned char )72 ), __2__X80 ,
# 851 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X79 -> __O2__4stmt.e = __6ee )) :0 ), __0__X79 ) ) ) ;
__1n -> __O3__4expr.n_initializer = 0 ;
}
}
}
}

# 858 "/home/claude/cfront-3/src/simpl2.cpp"
init_stat3 :if (__2st ){ 
# 859 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1ss )
# 860 "/home/claude/cfront-3/src/simpl2.cpp"
__1sst -> s_list__4stmt = __2st ;
else 
# 862 "/home/claude/cfront-3/src/simpl2.cpp"
__1ss = __2st ;
__1sst = __2st ;
}
if (__2is_nrv )__1n -> __O1__4expr.tp = (struct type *)any_type ;
}

# 868 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1dd ){ 
# 869 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __2od ;
Pstmt __2obd ;
Pstmt __2ocd ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct pair *__0__X81 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X82 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X83 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X84 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct pair *__0__X85 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X86 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X87 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X88 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct pair *__0__X89 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X90 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X91 ;

# 872 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X92 ;

# 869 "/home/claude/cfront-3/src/simpl2.cpp"
__2od = del_list ;
__2obd = break_del_list ;
__2ocd = continue_del_list ;

# 873 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4stmtFv ( __1dd ) ;
del_list = (__2od ?(((struct stmt *)(((struct stmt *)( (__0__X81 = 0 ), ( (__2__X82 = curloc ), ( (__2__X83 = __1dd ), ( (__2__X84 =
# 874 "/home/claude/cfront-3/src/simpl2.cpp"
__2od ), ( ((__0__X81 || (__0__X81 = (struct pair *)__nw__4stmtSFUl ( (size_t )(sizeof (struct pair))) ))?( (__0__X81 = (struct pair *)__ct__4stmtFUc3locP4stmt (
# 874 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)__0__X81 ), (unsigned char )166 , __2__X82 , __2__X83 ) ), (__0__X81 -> __O2__4stmt.s2 = __2__X84 )) :0 ), __0__X81 ) )
# 874 "/home/claude/cfront-3/src/simpl2.cpp"
) ) ) )))):__1dd );
break_del_list = ((break_del_list && __2obd )?(((struct stmt *)(((struct stmt *)( (__0__X85 = 0 ), ( (__2__X86 = curloc ), ( (__2__X87 = __1dd ), (
# 875 "/home/claude/cfront-3/src/simpl2.cpp"
(__2__X88 = __2obd ), ( ((__0__X85 || (__0__X85 = (struct pair *)__nw__4stmtSFUl ( (size_t )(sizeof (struct pair))) ))?( (__0__X85 = (struct
# 875 "/home/claude/cfront-3/src/simpl2.cpp"
pair *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X85 ), (unsigned char )166 , __2__X86 , __2__X87 ) ), (__0__X85 -> __O2__4stmt.s2 = __2__X88 )) :0 ), __0__X85 )
# 875 "/home/claude/cfront-3/src/simpl2.cpp"
) ) ) ) )))):__1dd );
continue_del_list = ((continue_del_list && __2ocd )?(((struct stmt *)(((struct stmt *)( (__0__X89 = 0 ), ( (__2__X90 = curloc ), ( (__2__X91 = __1dd ), (
# 876 "/home/claude/cfront-3/src/simpl2.cpp"
(__2__X92 = __2ocd ), ( ((__0__X89 || (__0__X89 = (struct pair *)__nw__4stmtSFUl ( (size_t )(sizeof (struct pair))) ))?( (__0__X89 = (struct
# 876 "/home/claude/cfront-3/src/simpl2.cpp"
pair *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X89 ), (unsigned char )166 , __2__X90 , __2__X91 ) ), (__0__X89 -> __O2__4stmt.s2 = __2__X92 )) :0 ), __0__X89 )
# 876 "/home/claude/cfront-3/src/simpl2.cpp"
) ) ) ) )))):__1dd );

# 878 "/home/claude/cfront-3/src/simpl2.cpp"
__1stail = (__0this -> s__4stmt ?simpl__4stmtFv ( __0this -> s__4stmt ) :(((struct stmt *)0 )));

# 880 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pfct __2f ;

# 880 "/home/claude/cfront-3/src/simpl2.cpp"
__2f = (((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))));
if ((((__0this != __2f -> body__3fct )|| (__2f -> returns__3fct -> base__4node == 38 ))|| ((__2f -> returns__3fct -> base__4node != 38 )&& (no_of_returns == 0 )))||
# 881 "/home/claude/cfront-3/src/simpl2.cpp"
(strcmp ( curr_fct -> __O2__4expr.string , (const char *)"main") == 0 ))
# 884 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 886 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1stail ){
# 886 "/home/claude/cfront-3/src/simpl2.cpp"

# 887 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __4tt ;

# 887 "/home/claude/cfront-3/src/simpl2.cpp"
__4tt = (((__1stail -> base__4node == 28 )|| (__1stail -> base__4node == 115 ))?__1stail :trim_tail__FP4stmt ( __1stail ) );
if (__4tt && (__4tt -> base__4node != 28 ))__1stail -> s_list__4stmt = __1dd ;
}
else 
# 891 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> s__4stmt = __1dd ;
__1stail = __1ddt ;
}

# 895 "/home/claude/cfront-3/src/simpl2.cpp"
del_list = __2od ;
continue_del_list = __2ocd ;
break_del_list = __2obd ;

# 897 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
else 
# 900 "/home/claude/cfront-3/src/simpl2.cpp"
__1stail = (__0this -> s__4stmt ?simpl__4stmtFv ( __0this -> s__4stmt ) :(((struct stmt *)0 )));

# 902 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1ss ){ 
# 903 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4stmtFv ( __1ss ) ;
__1sst -> s_list__4stmt = __0this -> s__4stmt ;
__0this -> s__4stmt = __1ss ;
if (__1stail == 0 )__1stail = __1sst ;
}

# 909 "/home/claude/cfront-3/src/simpl2.cpp"
if (tmp_dtor ){ 
# 910 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4stmtFv ( tmp_dtor ) ;
if (__1stail == 0 )
# 912 "/home/claude/cfront-3/src/simpl2.cpp"
__1stail = tmp_dtor ;
else __1stail -> s_list__4stmt = tmp_dtor ;
tmp_dtor = 0 ;
}

# 918 "/home/claude/cfront-3/src/simpl2.cpp"
scope = __1old_scope ;

# 920 "/home/claude/cfront-3/src/simpl2.cpp"
return __1stail ;

# 920 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 923 "/home/claude/cfront-3/src/simpl2.cpp"
int no_sizeof = 0 ;

# 794 "/home/claude/cfront-3/src/cfront.h"
void del__4exprFv (struct expr *__0this );

# 828 "/home/claude/cfront-3/src/cfront.h"

# 40 "/home/claude/cfront-3/src/simpl2.cpp"
extern Pname find_vptr__FP8classdef (Pclass );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 834 "/home/claude/cfront-3/src/cfront.h"
void simpl__4callFv (struct call *__0this );

# 813 "/home/claude/cfront-3/src/cfront.h"
void simpl_new__4exprFv (struct expr *__0this );
void simpl_delete__4exprFv (struct expr *__0this );

# 803 "/home/claude/cfront-3/src/cfront.h"
Pexpr address__4exprFv (struct expr *__0this );

# 449 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8classdefFP4name (struct classdef *__0this , Pname );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 799 "/home/claude/cfront-3/src/cfront.h"
long long eval__4exprFv (struct expr *__0this );

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 924 "/home/claude/cfront-3/src/simpl2.cpp"
void simpl__4exprFv (register struct expr *__0this )
# 925 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 929 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 932 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this == 0 )return ;
if (__0this -> permanent__4node == 2 )return ;
{ static TOK __1obase = 0 ;

# 937 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__0this -> base__4node ){ 
# 938 "/home/claude/cfront-3/src/simpl2.cpp"
case 177 :
# 939 "/home/claude/cfront-3/src/simpl2.cpp"
__1obase = __0this -> base__4node ;
simpl__4exprFv ( __0this -> __O4__4expr.mem ) ;
__1obase = 0 ;

# 944 "/home/claude/cfront-3/src/simpl2.cpp"
case 168 :
# 945 "/home/claude/cfront-3/src/simpl2.cpp"
return ;

# 947 "/home/claude/cfront-3/src/simpl2.cpp"
case 145 :
# 948 "/home/claude/cfront-3/src/simpl2.cpp"
case 112 :
# 951 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4exprFv ( __0this -> __O3__4expr.e2 ) ;
switch (__0this -> __O3__4expr.e2 -> base__4node ){ 
# 953 "/home/claude/cfront-3/src/simpl2.cpp"
case 45 :
# 954 "/home/claude/cfront-3/src/simpl2.cpp"
case 44 :
# 955 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pref __4r ;
Pname __4m ;

# 955 "/home/claude/cfront-3/src/simpl2.cpp"
__4r = (((struct ref *)(((struct ref *)__0this -> __O3__4expr.e2 ))));
__4m = (((struct name *)(((struct name *)__4r -> __O4__4expr.mem ))));
while (__4m -> base__4node == 177 )__4m = (((struct name *)(((struct name *)__4m -> __O4__4expr.mem ))));
if (__4m -> n_stclass__4name == 31 ){ 
# 959 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __5x ;
delp :
# 961 "/home/claude/cfront-3/src/simpl2.cpp"
__5x = __0this -> __O3__4expr.e2 ;
__0this -> __O3__4expr.e2 = (struct expr *)__4m ;
__4r -> __O4__4expr.mem = 0 ;
if (__5x && (__5x -> permanent__4node == 0 ))del__4exprFv ( __5x ) ;
}
else if (__4m -> __O1__4expr.tp -> base__4node == 108 ){ 
# 967 "/home/claude/cfront-3/src/simpl2.cpp"
Pfct __5f ;

# 967 "/home/claude/cfront-3/src/simpl2.cpp"
__5f = (((struct fct *)(((struct fct *)__4m -> __O1__4expr.tp ))));
if (__5f -> f_virtual__3fct ){ 
# 969 "/home/claude/cfront-3/src/simpl2.cpp"
int __6index ;
Pexpr __6ie ;

# 971 "/home/claude/cfront-3/src/simpl2.cpp"
struct ival *__0__X98 ;

# 969 "/home/claude/cfront-3/src/simpl2.cpp"
__6index = __5f -> f_virtual__3fct ;
__6ie = (struct expr *)(__6index ?( (__0__X98 = 0 ), ( ((__0__X98 || (__0__X98 = (struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival)))
# 970 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X98 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X98 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 ) ),
# 970 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X98 -> __O2__4expr.i1 = ((long long )__6index ))) :0 ), __0__X98 ) ) :(((struct ival *)0 )));
if (__6ie )__6ie -> __O1__4expr.tp = (struct type *)int_type ;
{ Pname __6cn ;
Pname __6vp ;

# 972 "/home/claude/cfront-3/src/simpl2.cpp"
__6cn = __4m -> __O4__4expr.n_table -> t_name__5table ;
__6vp = find_vptr__FP8classdef ( ((struct classdef *)(((struct classdef *)__6cn -> __O1__4expr.tp )))) ;
__4r -> __O4__4expr.mem = (struct expr *)__6vp ;

# 976 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1obase == 177 ){ 
# 977 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> base__4node = 111 ;
__0this -> __O2__4expr.e1 = __0this -> __O3__4expr.e2 ;
__0this -> __O3__4expr.e2 = __6ie ;
}
else { 
# 982 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> base__4node = 177 ;
__0this -> __O4__4expr.mem = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __0this -> __O3__4expr.e2 , __6ie ) ;
__0this -> __O3__4expr.string2 = (const char *)"f";
__0this -> __O2__4expr.i1 = 9 ;
}

# 986 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
else { 
# 989 "/home/claude/cfront-3/src/simpl2.cpp"
goto delp ;
}
}
break ;
}
}
break ;
case 126 :
# 997 "/home/claude/cfront-3/src/simpl2.cpp"
case 127 :
# 998 "/home/claude/cfront-3/src/simpl2.cpp"
case 128 :
# 999 "/home/claude/cfront-3/src/simpl2.cpp"
case 129 :
# 1000 "/home/claude/cfront-3/src/simpl2.cpp"
case 130 :
# 1001 "/home/claude/cfront-3/src/simpl2.cpp"
case 131 :
# 1002 "/home/claude/cfront-3/src/simpl2.cpp"
case 132 :
# 1003 "/home/claude/cfront-3/src/simpl2.cpp"
case 133 :
# 1004 "/home/claude/cfront-3/src/simpl2.cpp"
case 134 :
# 1005 "/home/claude/cfront-3/src/simpl2.cpp"
case 135 :
# 1006 "/home/claude/cfront-3/src/simpl2.cpp"
imeasure ++ ;
if (__0this -> __O2__4expr.e1 )simpl__4exprFv ( __0this -> __O2__4expr.e1 ) ;
if (__0this -> __O3__4expr.e2 )simpl__4exprFv ( __0this -> __O3__4expr.e2 ) ;
break ;
case 66 :
# 1011 "/home/claude/cfront-3/src/simpl2.cpp"
case 67 :
# 1013 "/home/claude/cfront-3/src/simpl2.cpp"
if (Ntmp_dtor && need_lift_dtors__FP4expr ( __0this ) ){ 
# 1014 "/home/claude/cfront-3/src/simpl2.cpp"
need_lift = 1 ;
{ Pexpr __3e ;

# 1015 "/home/claude/cfront-3/src/simpl2.cpp"
__3e = lift_dtors__FP4exprP5table ( __0this , Ntmp_tbl ) ;
((*__0this ))= (*__3e );

# 1016 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
Ntmp = 0 ;

# 1021 "/home/claude/cfront-3/src/simpl2.cpp"
default :
# 1023 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O2__4expr.e1 )simpl__4exprFv ( __0this -> __O2__4expr.e1 ) ;
if (__0this -> __O3__4expr.e2 )simpl__4exprFv ( __0this -> __O3__4expr.e2 ) ;
break ;

# 1027 "/home/claude/cfront-3/src/simpl2.cpp"
case 71 :
# 1028 "/home/claude/cfront-3/src/simpl2.cpp"
case 147 :
# 1029 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1030 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __3n ;

# 1030 "/home/claude/cfront-3/src/simpl2.cpp"
__3n = 0 ;
simpl__4exprFv ( __0this -> __O2__4expr.e1 ) ;
simpl__4exprFv ( __0this -> __O3__4expr.e2 ) ;
if ((__0this -> __O2__4expr.e1 -> base__4node == 168 )&& (__0this -> __O2__4expr.e1 -> __O2__4expr.e1 == 0 ))__3n = __0this -> __O2__4expr.e1 -> __O4__4expr.il -> fct_name__5iline ;
if ((__0this -> __O3__4expr.e2 -> base__4node == 168 )&& (__0this -> __O3__4expr.e2 -> __O2__4expr.e1 == 0 ))__3n = __0this -> __O3__4expr.e2 -> __O4__4expr.il -> fct_name__5iline ;
if (__3n ){ 
# 1035 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V94 ;

# 1035 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"cannot expand inline void%n called in commaE", (const struct ea *)( ((&
# 1035 "/home/claude/cfront-3/src/simpl2.cpp"
__0__V94 )-> __O1__2ea.p = ((const void *)__3n )), (& __0__V94 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1035 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)ea0 ) ;
} return ;
}
case 162 :
# 1039 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> base__4node = 150 ;
__0this -> __O2__4expr.i1 = 0 ;

# 1042 "/home/claude/cfront-3/src/simpl2.cpp"
case 144 :
# 1043 "/home/claude/cfront-3/src/simpl2.cpp"
case 85 :
# 1044 "/home/claude/cfront-3/src/simpl2.cpp"
case 82 :
# 1045 "/home/claude/cfront-3/src/simpl2.cpp"
case 83 :
# 1046 "/home/claude/cfront-3/src/simpl2.cpp"
case 84 :
# 1047 "/home/claude/cfront-3/src/simpl2.cpp"
case 150 :
# 1050 "/home/claude/cfront-3/src/simpl2.cpp"
case 81 :
# 1051 "/home/claude/cfront-3/src/simpl2.cpp"
case 86 :
# 1052 "/home/claude/cfront-3/src/simpl2.cpp"
case 124 :
# 1054 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> base__4node == 82 ){ 
# 1055 "/home/claude/cfront-3/src/simpl2.cpp"
char
# 1055 "/home/claude/cfront-3/src/simpl2.cpp"
*__3s ;

# 1055 "/home/claude/cfront-3/src/simpl2.cpp"
__3s = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* (strlen ( __0this -> __O2__4expr.string ) + 1 ))) ));
# 1055 "/home/claude/cfront-3/src/simpl2.cpp"

# 1056 "/home/claude/cfront-3/src/simpl2.cpp"
strcpy ( __3s , __0this -> __O2__4expr.string ) ;
__0this -> __O2__4expr.string = (const char *)__3s ;
}
return ;

# 1067 "/home/claude/cfront-3/src/simpl2.cpp"
case 30 :
# 1068 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O2__4expr.e1 )simpl__4exprFv ( __0this -> __O2__4expr.e1 ) ;
return ;

# 1071 "/home/claude/cfront-3/src/simpl2.cpp"
case 146 :
# 1072 "/home/claude/cfront-3/src/simpl2.cpp"
case 109 :
# 1073 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4callFv ( ((struct call *)(((struct call *)__0this )))) ;
break ;

# 1076 "/home/claude/cfront-3/src/simpl2.cpp"
case 23 :
# 1077 "/home/claude/cfront-3/src/simpl2.cpp"
case 213 :
# 1078 "/home/claude/cfront-3/src/simpl2.cpp"
case 184 :
# 1079 "/home/claude/cfront-3/src/simpl2.cpp"
simpl_new__4exprFv ( __0this ) ;
return ;

# 1082 "/home/claude/cfront-3/src/simpl2.cpp"
case 9 :
# 1083 "/home/claude/cfront-3/src/simpl2.cpp"
case 212 :
# 1084 "/home/claude/cfront-3/src/simpl2.cpp"
case 188 :
# 1085 "/home/claude/cfront-3/src/simpl2.cpp"
simpl_delete__4exprFv ( __0this ) ;
break ;

# 1088 "/home/claude/cfront-3/src/simpl2.cpp"
case 68 :
# 1089 "/home/claude/cfront-3/src/simpl2.cpp"
if (Ntmp_dtor && need_lift_dtors__FP4expr ( __0this ) ){ 
# 1090 "/home/claude/cfront-3/src/simpl2.cpp"
need_lift = 1 ;
{ Pexpr __3e ;

# 1091 "/home/claude/cfront-3/src/simpl2.cpp"
__3e = lift_dtors__FP4exprP5table ( __0this , Ntmp_tbl ) ;
((*__0this ))= (*__3e );

# 1092 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
simpl__4exprFv ( __0this -> __O4__4expr.cond ) ;
Ntmp = 0 ;
simpl__4exprFv ( __0this -> __O3__4expr.e2 ) ;

# 1099 "/home/claude/cfront-3/src/simpl2.cpp"
case 113 :
# 1100 "/home/claude/cfront-3/src/simpl2.cpp"
case 191 :
# 1101 "/home/claude/cfront-3/src/simpl2.cpp"
case 44 :
# 1102 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4exprFv ( __0this -> __O2__4expr.e1 ) ;
break ;

# 1105 "/home/claude/cfront-3/src/simpl2.cpp"
case 45 :
# 1106 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4exprFv ( __0this -> __O2__4expr.e1 ) ;
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 1108 "/home/claude/cfront-3/src/simpl2.cpp"
case 71 :
# 1109 "/home/claude/cfront-3/src/simpl2.cpp"
case 147 :
# 1110 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1111 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __4ex ;

# 1111 "/home/claude/cfront-3/src/simpl2.cpp"
__4ex = __0this -> __O2__4expr.e1 ;
cfr :
# 1113 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__4ex -> __O3__4expr.e2 -> base__4node ){ 
# 1114 "/home/claude/cfront-3/src/simpl2.cpp"
case 85 :
# 1115 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> base__4node = 44 ;
__4ex -> __O3__4expr.e2 = address__4exprFv ( __4ex -> __O3__4expr.e2 ) ;
break ;
case 71 :
# 1119 "/home/claude/cfront-3/src/simpl2.cpp"
case 147 :
# 1120 "/home/claude/cfront-3/src/simpl2.cpp"
__4ex = __4ex -> __O3__4expr.e2 ;
goto cfr ;
}
}
}
break ;

# 1127 "/home/claude/cfront-3/src/simpl2.cpp"
case 70 :
# 1128 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1129 "/home/claude/cfront-3/src/simpl2.cpp"
Pfct __3f ;
Pexpr __3th ;

# 1129 "/home/claude/cfront-3/src/simpl2.cpp"
__3f = 0 ;
__3th = 0 ;
if (curr_fct ){ 
# 1132 "/home/claude/cfront-3/src/simpl2.cpp"
__3f = (((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))));
__3th = (struct expr *)__3f -> f_this__3fct ;
}

# 1136 "/home/claude/cfront-3/src/simpl2.cpp"
imeasure ++ ;
if (__0this -> __O2__4expr.e1 )simpl__4exprFv ( __0this -> __O2__4expr.e1 ) ;
if (__0this -> __O3__4expr.e2 ){ 
# 1139 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __4c ;

# 1139 "/home/claude/cfront-3/src/simpl2.cpp"
__4c = __0this -> __O3__4expr.e2 ;
simpl__4exprFv ( __4c ) ;
while ((__4c -> base__4node == 113 )|| (__4c -> base__4node == 191 ))
# 1142 "/home/claude/cfront-3/src/simpl2.cpp"
__4c = __4c -> __O2__4expr.e1 ;
if (__4c -> base__4node == 124 )__0this -> __O3__4expr.e2 = __4c ;

# 1145 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O3__4expr.e2 -> base__4node == 124 ){ 
# 1146 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __5ee ;
if (__0this -> __O2__4expr.e1 -> base__4node == 111 ){ 
# 1148 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __6tmp ;

# 1148 "/home/claude/cfront-3/src/simpl2.cpp"
__6tmp = (struct expr *)make_tmp__FcP4typeP5table ( 'A' , __0this -> __O2__4expr.e1 -> __O1__4expr.tp , cc -> ftbl__11dcl_context ) ;
__5ee = mptr_assign__FP4exprT1 ( __6tmp , __0this -> __O3__4expr.e2 ) ;
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __5ee -> __O2__4expr.e1 , __5ee -> __O3__4expr.e2 ) ;
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __0this -> __O3__4expr.e2 , __6tmp ) ;
__0this -> __O3__4expr.e2 -> __O1__4expr.tp = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
}
else { 
# 1155 "/home/claude/cfront-3/src/simpl2.cpp"
__5ee = mptr_assign__FP4exprT1 ( __0this -> __O2__4expr.e1 , __0this -> __O3__4expr.e2 ) ;
{ Pexpr __6eee ;

# 1156 "/home/claude/cfront-3/src/simpl2.cpp"
__6eee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __5ee -> __O3__4expr.e2 , __0this -> __O2__4expr.e1 ) ;
__0this -> __O2__4expr.e1 = __5ee -> __O2__4expr.e1 ;
__0this -> __O3__4expr.e2 = __6eee ;
__0this -> base__4node = 71 ;

# 1159 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
( (__5ee ?(((void )(__5ee ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__5ee , (size_t )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 1161 "/home/claude/cfront-3/src/simpl2.cpp"
;
}
}

# 1165 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__3th && (__3th == __0this -> __O2__4expr.e1 ))&& (curr_fct -> n_oper__4name == 161 ))&& init_list ){ 
# 1167 "/home/claude/cfront-3/src/simpl2.cpp"
Pclass __4cl ;

# 1168 "/home/claude/cfront-3/src/simpl2.cpp"
const void *__2__X99 ;

# 1167 "/home/claude/cfront-3/src/simpl2.cpp"
__4cl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)(((struct ptr *)(((struct ptr *)__3th -> __O1__4expr.tp ))))-> typ__5pvtyp ))))-> b_name__8basetype -> __O1__4expr.tp ))));
if (__4cl -> c_body__8classdef == 1 )dcl_print__8classdefFP4name ( __4cl , (struct name *)0 ) ;
imeasure ++ ;
__0this -> base__4node = 71 ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __0this -> __O2__4expr.e1 , __0this -> __O3__4expr.e2 ) ;
__0this -> __O3__4expr.e2 = init_list ;
if (warning_opt )
# 1174 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1174 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V95 ;

# 1174 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"assignment to ``this'' inK: try defining%t::operator new() instead", (const struct ea *)( (__2__X99 =
# 1174 "/home/claude/cfront-3/src/simpl2.cpp"
(const void *)__3f -> memof__3fct ), ( ((& __0__V95 )-> __O1__2ea.p = __2__X99 ), (& __0__V95 )) ) , (const
# 1174 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
break ;
}
}

# 1180 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__0this -> base__4node ){ 
# 1180 "/home/claude/cfront-3/src/simpl2.cpp"
const void *__2__X100 ;

# 1180 "/home/claude/cfront-3/src/simpl2.cpp"
unsigned long __2__X101 ;

# 1181 "/home/claude/cfront-3/src/simpl2.cpp"
case 68 :
# 1182 "/home/claude/cfront-3/src/simpl2.cpp"
case 66 :
# 1183 "/home/claude/cfront-3/src/simpl2.cpp"
case 67 :
# 1184 "/home/claude/cfront-3/src/simpl2.cpp"
if (Ntmp ){ 
# 1184 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V96 ;

# 1184 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V97 ;

# 1184 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"temporary ofC%n with destructor needed in%kE", (const struct ea *)( (__2__X100 =
# 1184 "/home/claude/cfront-3/src/simpl2.cpp"
(const void *)Ntmp ), ( ((& __0__V96 )-> __O1__2ea.p = __2__X100 ), (& __0__V96 )) ) , (const struct
# 1184 "/home/claude/cfront-3/src/simpl2.cpp"
ea *)( (__2__X101 = __0this -> base__4node ), ( (( ((& __0__V97 )-> __O1__2ea.i = __2__X101 ), 0 ) ), (& __0__V97 ))
# 1184 "/home/claude/cfront-3/src/simpl2.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1186 "/home/claude/cfront-3/src/simpl2.cpp"
default :
# 1187 "/home/claude/cfront-3/src/simpl2.cpp"
Ntmp = 0 ;
}

# 1190 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__0this -> __O1__4expr.tp == (((struct type *)int_type )))|| (__0this -> __O1__4expr.tp == (((struct type *)defa_type )))){ 
# 1191 "/home/claude/cfront-3/src/simpl2.cpp"
Neval = 0 ;
no_sizeof = 1 ;
{ long long __2i ;

# 1193 "/home/claude/cfront-3/src/simpl2.cpp"
__2i = eval__4exprFv ( __0this ) ;
no_sizeof = 0 ;
if (Neval == 0 ){ 
# 1196 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> base__4node = 150 ;
__0this -> __O2__4expr.i1 = __2i ;
}

# 1198 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 1199 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1201 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1203 "/home/claude/cfront-3/src/simpl2.cpp"
static Pname vfunt_name ;

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"
static int same_class__FP8classdefT1i (Pclass __1c1 , Pclass __1c2 , int __1dummy );

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 1204 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr vptr_entry__FP4exprT1P8classdef (Pexpr __1pp , Pexpr __1ie , Pclass __1cl )
# 1205 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1206 "/home/claude/cfront-3/src/simpl2.cpp"
Pptr __1ttemp ;

# 1206 "/home/claude/cfront-3/src/simpl2.cpp"
__1ttemp = is_ptr_or_ref__4typeFv ( __1pp -> __O1__4expr.tp ) ;

# 1208 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1ttemp ){ 
# 1209 "/home/claude/cfront-3/src/simpl2.cpp"
Ptype __2pt ;
Pclass __2pc ;

# 1211 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__1__X105 ;

# 1211 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__1__X106 ;

# 1211 "/home/claude/cfront-3/src/simpl2.cpp"
register struct cast *__0__X107 ;

# 1209 "/home/claude/cfront-3/src/simpl2.cpp"
__2pt = __1ttemp -> typ__5pvtyp ;
__2pc = (((struct classdef *)(((struct classdef *)is_cl_obj__4typeFv ( __2pt ) -> __O1__4expr.tp ))));
if (! ( (__1__X105 = __2pc ), ( (__1__X106 = __1cl ), ( ((__1__X105 == __1__X106 )?1 :((__1__X105 && __1__X106 )?(((int )same_class__8classdefFP8classdefi ( __1__X105 ,
# 1211 "/home/claude/cfront-3/src/simpl2.cpp"
__1__X106 , 0 ) )):0 ))) ) ) )__1pp = (struct expr *)( (__0__X107 = 0 ), ( ((__0__X107 || (__0__X107 = (struct
# 1211 "/home/claude/cfront-3/src/simpl2.cpp"
cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast))) ))?( (__0__X107 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X107 ), (unsigned char )191 ,
# 1211 "/home/claude/cfront-3/src/simpl2.cpp"
__1pp , (struct expr *)0 ) ), (__0__X107 -> __O1__4expr.tp = (__0__X107 -> __O4__4expr.tp2 = ((struct type *)__1cl )))) :0 ), __0__X107 ) ) ;
# 1211 "/home/claude/cfront-3/src/simpl2.cpp"

# 1212 "/home/claude/cfront-3/src/simpl2.cpp"
}
{ Pname __1vp ;

# 1213 "/home/claude/cfront-3/src/simpl2.cpp"
__1vp = find_vptr__FP8classdef ( __1cl ) ;
if (__1vp == 0 ){ 
# 1214 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__1__X108 ;

# 1214 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__1__X109 ;

# 1214 "/home/claude/cfront-3/src/simpl2.cpp"
const void *__2__X110 ;

# 1216 "/home/claude/cfront-3/src/simpl2.cpp"
if (cc -> cot__11dcl_context && (( (__1__X108 = cc -> cot__11dcl_context -> in_class__4type ), ( (__1__X109 = __1cl ), ( ((__1__X108 == __1__X109 )?1 :((__1__X108 &&
# 1216 "/home/claude/cfront-3/src/simpl2.cpp"
__1__X109 )?(((int )same_class__8classdefFP8classdefi ( __1__X108 , __1__X109 , 0 ) )):0 ))) ) ) || same_class__FP8classdefT1i ( cc -> cot__11dcl_context , __1cl , 0 )
# 1216 "/home/claude/cfront-3/src/simpl2.cpp"
))
# 1217 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1217 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V102 ;

# 1217 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V103 ;

# 1217 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V104 ;

# 1217 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"call of virtualF%n beforeC %s has been completely declared - %s make function non-virtual", (const struct ea *)( (__2__X110 =
# 1217 "/home/claude/cfront-3/src/simpl2.cpp"
(const void *)vfunt_name ), ( ((& __0__V102 )-> __O1__2ea.p = __2__X110 ), (& __0__V102 )) ) , (const struct
# 1217 "/home/claude/cfront-3/src/simpl2.cpp"
ea *)__ct__2eaFPCv ( & __0__V103 , (const void *)__1cl -> string__8classdef ) , (const struct ea *)__ct__2eaFPCv ( & __0__V104 , (const
# 1217 "/home/claude/cfront-3/src/simpl2.cpp"
void *)((curr_fct && (strcmp ( (const char *)"..", curr_fct -> __O2__4expr.string ) == 0 ))?"try moving call from argument list into function body or":(((char
# 1217 "/home/claude/cfront-3/src/simpl2.cpp"
*)"")))) , (const struct ea *)ea0 ) ;
} else error__FiPCc ( (int )'i' , (const char *)"can't find vptr") ;
}
{ Pexpr __1vptr ;

# 1221 "/home/claude/cfront-3/src/simpl2.cpp"
struct ref *__0__X111 ;

# 1221 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X112 ;

# 1221 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X113 ;

# 1220 "/home/claude/cfront-3/src/simpl2.cpp"
__1vptr = (struct expr *)( (__0__X111 = 0 ), ( (__2__X112 = __1pp ), ( (__2__X113 = (struct expr *)__1vp ), ( ((__0__X111 ||
# 1220 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X111 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X111 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X111 ), ((unsigned
# 1220 "/home/claude/cfront-3/src/simpl2.cpp"
char )44 ), __2__X112 , (struct expr *)0 ) ), (__0__X111 -> __O4__4expr.mem = __2__X113 )) :0 ), __0__X111 ) ) ) )
# 1220 "/home/claude/cfront-3/src/simpl2.cpp"
;
return __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __1vptr , __1ie ) ;

# 1221 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1221 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 848 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 1224 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr new_this__FP4exprT1 (Pexpr __1pp , Pexpr __1ee )
# 1225 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1227 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1dee ;

# 1228 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X118 ;

# 1227 "/home/claude/cfront-3/src/simpl2.cpp"
__1dee = (struct expr *)( (__0__X118 = 0 ), ( ((__0__X118 || (__0__X118 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 1227 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X118 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X118 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 1227 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X118 -> __O3__4expr.string2 = ((const char *)"d")), (__0__X118 -> __O4__4expr.mem = __1ee )) )
# 1227 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X118 ) ) ;
__1dee -> __O2__4expr.i1 = 9 ;
{ Pexpr __1nthis ;

# 1230 "/home/claude/cfront-3/src/simpl2.cpp"
register struct cast *__0__X116 ;

# 1230 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X117 ;

# 1229 "/home/claude/cfront-3/src/simpl2.cpp"
__1nthis = (struct expr *)( (__0__X116 = 0 ), ( (__2__X117 = Pchar_type ), ( ((__0__X116 || (__0__X116 = (struct cast *)__nw__4exprSFUl ( (unsigned
# 1229 "/home/claude/cfront-3/src/simpl2.cpp"
long )(sizeof (struct cast))) ))?( (__0__X116 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X116 ), (unsigned char )191 , __1pp , (struct
# 1229 "/home/claude/cfront-3/src/simpl2.cpp"
expr *)0 ) ), (__0__X116 -> __O1__4expr.tp = (__0__X116 -> __O4__4expr.tp2 = __2__X117 ))) :0 ), __0__X116 ) ) ) ;
__1nthis = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )54 , __1nthis , __1dee ) ;
{ Ptype __1ct ;

# 1232 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__0__X114 ;

# 1232 "/home/claude/cfront-3/src/simpl2.cpp"
register struct cast *__0__X115 ;

# 1231 "/home/claude/cfront-3/src/simpl2.cpp"
__1ct = __1pp -> __O1__4expr.tp ;
if ((__1pp -> base__4node == 85 )&& (((struct name *)(((struct name *)__1pp ))))-> n_xref__4name )__1ct = (struct type *)( (__0__X114 = __1pp -> __O1__4expr.tp ), (
# 1232 "/home/claude/cfront-3/src/simpl2.cpp"
__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __0__X114 ) ) ) ;
return (struct expr *)( (__0__X115 = 0 ), ( ((__0__X115 || (__0__X115 = (struct cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast)))
# 1233 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X115 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X115 ), (unsigned char )191 , __1nthis , (struct expr *)0 ) ), (__0__X115 ->
# 1233 "/home/claude/cfront-3/src/simpl2.cpp"
__O1__4expr.tp = (__0__X115 -> __O4__4expr.tp2 = __1ct ))) :0 ), __0__X115 ) ) ;

# 1233 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1233 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 848 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 832 "/home/claude/cfront-3/src/cfront.h"

# 1236 "/home/claude/cfront-3/src/simpl2.cpp"
Pcall vcall__FP4exprT1P3fctP8classdefT1 (Pexpr __1pp , Pexpr __1ie , Pfct __1f , Pclass __1cl , Pexpr __1args )
# 1252 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1254 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1cl -> c_body__8classdef == 1 )dcl_print__8classdefFP4name ( __1cl , (struct name *)0 ) ;

# 1256 "/home/claude/cfront-3/src/simpl2.cpp"
imeasure += 6 ;
{ Pexpr __1ee ;

# 1259 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1fee ;

# 1260 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X123 ;

# 1257 "/home/claude/cfront-3/src/simpl2.cpp"
__1ee = vptr_entry__FP4exprT1P8classdef ( __1pp , __1ie , __1cl ) ;

# 1259 "/home/claude/cfront-3/src/simpl2.cpp"
__1fee = (struct expr *)( (__0__X123 = 0 ), ( ((__0__X123 || (__0__X123 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 1259 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X123 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X123 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 1259 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X123 -> __O3__4expr.string2 = ((const char *)"f")), (__0__X123 -> __O4__4expr.mem = __1ee )) )
# 1259 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X123 ) ) ;
__1fee -> __O2__4expr.i1 = 9 ;
{ Ptype __1pft ;

# 1262 "/home/claude/cfront-3/src/simpl2.cpp"
register struct cast *__0__X119 ;

# 1261 "/home/claude/cfront-3/src/simpl2.cpp"
__1pft = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , ((struct type *)__1f )) ) ;
__1fee = (struct expr *)( (__0__X119 = 0 ), ( ((__0__X119 || (__0__X119 = (struct cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast)))
# 1262 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X119 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X119 ), (unsigned char )191 , __1fee , (struct expr *)0 ) ), (__0__X119 ->
# 1262 "/home/claude/cfront-3/src/simpl2.cpp"
__O1__4expr.tp = (__0__X119 -> __O4__4expr.tp2 = __1pft ))) :0 ), __0__X119 ) ) ;
{ Pexpr __1r ;

# 1263 "/home/claude/cfront-3/src/simpl2.cpp"
__1r = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __1fee , (struct expr *)0 ) ;

# 1265 "/home/claude/cfront-3/src/simpl2.cpp"
__1r -> __O4__4expr.tp2 = (((struct type *)(((struct type *)__1f -> f_this__3fct ))));

# 1267 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __1nthis ;

# 1267 "/home/claude/cfront-3/src/simpl2.cpp"
__1nthis = new_this__FP4exprT1 ( __1pp , __1ee ) ;

# 1269 "/home/claude/cfront-3/src/simpl2.cpp"
__1args = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1nthis , __1args ) ;
simpl__4exprFv ( __1args ) ;

# 1272 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pcall __1c ;

# 1273 "/home/claude/cfront-3/src/simpl2.cpp"
struct call *__0__X120 ;

# 1273 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X121 ;

# 1273 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X122 ;

# 1272 "/home/claude/cfront-3/src/simpl2.cpp"
__1c = ( (__0__X120 = 0 ), ( (__2__X121 = __1r ), ( (__2__X122 = __1args ), ( ((__0__X120 || (__0__X120 = (struct
# 1272 "/home/claude/cfront-3/src/simpl2.cpp"
call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X120 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X120 ), (unsigned char )109 , __2__X121 ,
# 1272 "/home/claude/cfront-3/src/simpl2.cpp"
__2__X122 ) ):0 ), __0__X120 ) ) ) ) ;
__1c -> __O1__4expr.tp = __1f -> returns__3fct ;
return __1c ;

# 1274 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1274 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1274 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1274 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1274 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 356 "/home/claude/cfront-3/src/cfront.h"
Ptype deref__4typeFv (struct type *__0this );

# 807 "/home/claude/cfront-3/src/cfront.h"
bit not_simple__4exprFi (struct expr *__0this , int __1inflag );

# 848 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 1348 "/home/claude/cfront-3/src/simpl2.cpp"
extern int has_virt__FP8classdef (Pclass );

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 848 "/home/claude/cfront-3/src/cfront.h"

# 832 "/home/claude/cfront-3/src/cfront.h"

# 113 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_name__FPCcP6ktableUc (const char *, Pktab , TOK );

# 37 "/home/claude/cfront-3/src/cfront.h"
extern char *make_name__FUc (TOK );

# 940 "/home/claude/cfront-3/src/cfront.h"
Pname dcl__4nameFP5tableUc (struct name *__0this , Ptable , TOK );

# 467 "/home/claude/cfront-3/src/cfront.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 943 "/home/claude/cfront-3/src/cfront.h"
void assign__4nameFv (struct name *__0this );

# 832 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 647 "/home/claude/cfront-3/src/cfront.h"
Pexpr expand__3fctFP4nameP5tableP4expr (struct fct *__0this , Pname , Ptable , Pexpr );

# 1569 "/home/claude/cfront-3/src/simpl2.cpp"
extern void uninline__FP4name (Pname __2fn );

# 1574 "/home/claude/cfront-3/src/simpl2.cpp"
extern void expand_itor__FP8classdef (Pclass );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 1277 "/home/claude/cfront-3/src/simpl2.cpp"
void simpl__4callFv (register struct call *__0this )
# 1291 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1292 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __1fn ;

# 1295 "/home/claude/cfront-3/src/simpl2.cpp"
Pfct __1f ;

# 1292 "/home/claude/cfront-3/src/simpl2.cpp"
__1fn = __0this -> __O4__4expr.fct_name ;

# 1295 "/home/claude/cfront-3/src/simpl2.cpp"
__1f = (__1fn ?(((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp )))):(((struct fct *)0 )));

# 1297 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1fn == 0 )simpl__4exprFv ( __0this -> __O2__4expr.e1 ) ;

# 1299 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1f ){ 
# 1300 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1fn -> base__4node == 162 ){ 
# 1302 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> base__4node = 150 ;
__0this -> __O2__4expr.i1 = 0 ;
if (__0this -> __O2__4expr.e1 && (__0this -> __O2__4expr.e1 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O2__4expr.e1 ) ;

# 1304 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O3__4expr.e2 && (__0this -> __O3__4expr.e2 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O3__4expr.e2 ) ;
__0this -> __O2__4expr.e1 = 0 ;

# 1305 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O3__4expr.e2 = 0 ;
return ;
}

# 1309 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__1f -> fct_base__3fct == 4)&& curr_fct )&& (strcmp ( curr_fct -> __O2__4expr.string , __1fn -> __O2__4expr.string ) == 0 ))
# 1311 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O4__4expr.fct_name = (__1fn =
# 1311 "/home/claude/cfront-3/src/simpl2.cpp"
curr_fct );

# 1313 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__1f -> base__4node ){ 
# 1314 "/home/claude/cfront-3/src/simpl2.cpp"
case 141 :
# 1315 "/home/claude/cfront-3/src/simpl2.cpp"
return ;
case 76 :
# 1317 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O4__4expr.fct_name = (__1fn = (((struct gen *)(((struct gen *)__1f ))))-> fct_list__3gen -> f__9name_list );
__1f = (((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))));
}
}

# 1322 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 1323 "/home/claude/cfront-3/src/simpl2.cpp"
case 173 :
# 1324 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1325 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __3p ;
Pexpr __3q ;
Pclass __3cl ;
Pfct __3f ;

# 1325 "/home/claude/cfront-3/src/simpl2.cpp"
__3p = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 ;
__3q = __0this -> __O2__4expr.e1 -> __O3__4expr.e2 ;
__3cl = (((struct classdef *)(((struct classdef *)__0this -> __O2__4expr.e1 -> __O4__4expr.tp2 ))));
__3f = (((struct fct *)(((struct fct *)deref__4typeFv ( __3q -> __O1__4expr.tp ) ))));

# 1330 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O3__4expr.e2 )simpl__4exprFv ( __0this -> __O3__4expr.e2 ) ;

# 1332 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3f -> f_this__3fct == 0 ){ 
# 1332 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__1__X129 ;

# 1332 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__1__X130 ;

# 1333 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3f -> memof__3fct == 0 )error__FiPCc ( (int )'i' , (const char *)"memof missing") ;
# 1333 "/home/claude/cfront-3/src/simpl2.cpp"

# 1334 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__3f -> memof__3fct -> class_base__8classdef == 2)&& ( (__1__X129 = __3cl ), ( (__1__X130 = __3f -> memof__3fct ), ( ((__1__X129 ==
# 1334 "/home/claude/cfront-3/src/simpl2.cpp"
__1__X130 )?1 :((__1__X129 && __1__X130 )?(((int )same_class__8classdefFP8classdefi ( __1__X129 , __1__X130 , 0 ) )):0 ))) ) ) )
# 1336 "/home/claude/cfront-3/src/simpl2.cpp"
__3f -> memof__3fct = __3cl ;
{ Pname __4tt ;

# 1337 "/home/claude/cfront-3/src/simpl2.cpp"
__4tt = __ct__4nameFPCc ( (struct name *)0 , (const char *)"this") ;
__4tt -> n_scope__4name = 136 ;
__4tt -> __O1__4expr.tp = __3f -> memof__3fct -> this_type__8classdef ;
__4tt -> permanent__4node = 1 ;

# 1342 "/home/claude/cfront-3/src/simpl2.cpp"
__4tt -> __O1__4name.n_list = __3f -> argtype__3fct ;

# 1344 "/home/claude/cfront-3/src/simpl2.cpp"
__4tt -> __O1__4name.n_list = (__3f -> f_result__3fct ?__3f -> f_result__3fct :__3f -> argtype__3fct );
__3f -> f_this__3fct = (__3f -> f_args__3fct = __4tt );

# 1345 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 1348 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 1351 "/home/claude/cfront-3/src/simpl2.cpp"
nin = 1 ;
if (not_simple__4exprFi ( __3q , 0 ) )error__FiPCc ( (int )'s' , (const char *)"2nd operand of .* too complicated")
# 1352 "/home/claude/cfront-3/src/simpl2.cpp"
;
nin = 0 ;

# 1355 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __3qq ;

# 1356 "/home/claude/cfront-3/src/simpl2.cpp"
register struct cast *__0__X131 ;

# 1356 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X132 ;

# 1356 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X138 ;

# 1355 "/home/claude/cfront-3/src/simpl2.cpp"
__3qq = (struct expr *)( (__0__X138 = 0 ), ( ((__0__X138 || (__0__X138 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 1355 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X138 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X138 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 1355 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X138 -> __O3__4expr.string2 = ((const char *)"f")), (__0__X138 -> __O4__4expr.mem = __3q )) )
# 1355 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X138 ) ) ;
__3qq -> __O2__4expr.i1 = 9 ;
__3qq = (struct expr *)( (__0__X131 = 0 ), ( (__2__X132 = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char
# 1357 "/home/claude/cfront-3/src/simpl2.cpp"
)125 , ((struct type *)__3f )) ) ), ( ((__0__X131 || (__0__X131 = (struct cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast)))
# 1357 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X131 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X131 ), (unsigned char )191 , __3qq , (struct expr *)0 ) ), (__0__X131 ->
# 1357 "/home/claude/cfront-3/src/simpl2.cpp"
__O1__4expr.tp = (__0__X131 -> __O4__4expr.tp2 = __2__X132 ))) :0 ), __0__X131 ) ) ) ;
{ Pexpr __3nc ;

# 1358 "/home/claude/cfront-3/src/simpl2.cpp"
__3nc = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __3qq , (struct expr *)0 ) ;
__3nc -> __O4__4expr.tp2 = (((struct type *)(((struct type *)__3f -> f_this__3fct ))));

# 1361 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __3nthis ;
Pexpr __3args ;

# 1361 "/home/claude/cfront-3/src/simpl2.cpp"
__3nthis = new_this__FP4exprT1 ( __3p , __3q ) ;
__3args = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __3nthis , __0this -> __O3__4expr.e2 ) ;
imeasure += 3 ;

# 1365 "/home/claude/cfront-3/src/simpl2.cpp"
if (has_virt__FP8classdef ( __3cl ) == 0 ){ 
# 1366 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3cl -> defined__4type == 0 )
# 1367 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1367 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V124 ;

# 1367 "/home/claude/cfront-3/src/simpl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"call throughP toMF before definition ofC %t", (const struct ea *)( ((& __0__V124 )-> __O1__2ea.p =
# 1367 "/home/claude/cfront-3/src/simpl2.cpp"
((const void *)__3cl )), (& __0__V124 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1367 "/home/claude/cfront-3/src/simpl2.cpp"
ea *)ea0 ) ;
} 
# 1370 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O2__4expr.e1 = __3nc ;
__0this -> __O3__4expr.e2 = __3args ;
return ;
}

# 1375 "/home/claude/cfront-3/src/simpl2.cpp"
if (find_vptr__FP8classdef ( __3cl ) == 0 ){ 
# 1381 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O2__4expr.e1 = __3nc ;
__0this -> __O3__4expr.e2 = __3args ;
return ;

# 1385 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1387 "/home/claude/cfront-3/src/simpl2.cpp"
nin = 1 ;
if (not_simple__4exprFi ( __3p , 0 ) )error__FiPCc ( (int )'s' , (const char *)"1st operand of .* too complicated")
# 1388 "/home/claude/cfront-3/src/simpl2.cpp"
;
nin = 0 ;

# 1391 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __3c ;

# 1392 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X137 ;

# 1391 "/home/claude/cfront-3/src/simpl2.cpp"
__3c = (struct expr *)( (__0__X137 = 0 ), ( ((__0__X137 || (__0__X137 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 1391 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X137 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X137 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 1391 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X137 -> __O3__4expr.string2 = ((const char *)"i")), (__0__X137 -> __O4__4expr.mem = __3q )) )
# 1391 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X137 ) ) ;
__3c -> __O2__4expr.i1 = 9 ;
__3c = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )58 , __3c , zero ) ;

# 1395 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __3ie ;

# 1396 "/home/claude/cfront-3/src/simpl2.cpp"
struct call *__0__X133 ;

# 1396 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X134 ;

# 1396 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X135 ;

# 1396 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X136 ;

# 1395 "/home/claude/cfront-3/src/simpl2.cpp"
__3ie = (struct expr *)( (__0__X136 = 0 ), ( ((__0__X136 || (__0__X136 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 1395 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X136 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X136 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 1395 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X136 -> __O3__4expr.string2 = ((const char *)"i")), (__0__X136 -> __O4__4expr.mem = __3q )) )
# 1395 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X136 ) ) ;
__3ie -> __O2__4expr.i1 = 9 ;

# 1398 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> base__4node = 68 ;
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X133 = 0 ), ( (__2__X134 = __3nc ), ( (__2__X135 = __3args ), ( ((__0__X133 ||
# 1399 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X133 = (struct call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X133 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X133 ), (unsigned char
# 1399 "/home/claude/cfront-3/src/simpl2.cpp"
)109 , __2__X134 , __2__X135 ) ):0 ), __0__X133 ) ) ) ) ;
__0this -> __O3__4expr.e2 = (struct expr *)vcall__FP4exprT1P3fctP8classdefT1 ( __3p , __3ie , __3f , __3cl , __0this -> __O3__4expr.e2 ) ;
__0this -> __O4__4expr.cond = __3c ;
return ;

# 1402 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1402 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1402 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1402 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1402 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
case 45 :
# 1407 "/home/claude/cfront-3/src/simpl2.cpp"
case 44 :
# 1408 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1409 "/home/claude/cfront-3/src/simpl2.cpp"
Pref __3r ;
Pexpr __3a1 ;
int __3obj ;

# 1409 "/home/claude/cfront-3/src/simpl2.cpp"
__3r = (((struct ref *)(((struct ref *)__0this -> __O2__4expr.e1 ))));
__3a1 = __3r -> __O2__4expr.e1 ;
__3obj = (__3r -> __O3__4expr.n_initializer != 0 );

# 1413 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3obj == 0 ){ 
# 1416 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__0this -> __O2__4expr.e1 -> base__4node == 45 )&& (__3a1 -> base__4node != 111 ))
# 1417 "/home/claude/cfront-3/src/simpl2.cpp"
__3obj = 1 ;
if (((__0this -> __O2__4expr.e1 -> base__4node == 45 )&& (__3a1 -> base__4node == 111 ))&& (((__3a1 -> __O2__4expr.e1 -> base__4node == 85 )&& (((struct name *)(((struct
# 1418 "/home/claude/cfront-3/src/simpl2.cpp"
name *)__3a1 -> __O2__4expr.e1 ))))-> n_xref__4name )|| (__3a1 -> __O2__4expr.e1 -> __O1__4expr.tp && (__3a1 -> __O2__4expr.e1 -> __O1__4expr.tp -> base__4node == 110 ))))
# 1422 "/home/claude/cfront-3/src/simpl2.cpp"
__3obj = 1 ;
if (__3a1 -> base__4node == 177 ){ 
# 1424 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __5eee ;

# 1424 "/home/claude/cfront-3/src/simpl2.cpp"
__5eee = __3a1 ;
while (__5eee -> base__4node == 177 )
# 1426 "/home/claude/cfront-3/src/simpl2.cpp"
__5eee = (struct expr *)(((struct name *)(((struct name *)(((struct ref *)(((struct ref *)__5eee ))))-> __O4__4expr.mem ))));
if (__5eee -> base__4node == 111 )
# 1428 "/home/claude/cfront-3/src/simpl2.cpp"
__3obj = 0 ;
}
}

# 1433 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__1f && (__3obj == 0 ))&& __1f -> f_virtual__3fct ){ 
# 1434 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __4a11 ;
Ptype __4tmp_type ;

# 1434 "/home/claude/cfront-3/src/simpl2.cpp"
__4a11 = 0 ;
__4tmp_type = 0 ;

# 1437 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__3a1 -> base__4node ){ 
# 1438 "/home/claude/cfront-3/src/simpl2.cpp"
case 177 :{ 
# 1439 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__3a1 -> __O2__4expr.i1 == 2 )|| (__3a1 -> __O2__4expr.i1 == 3 )){ 
# 1440 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __7n ;

# 1440 "/home/claude/cfront-3/src/simpl2.cpp"
__7n = k_find_name__FPCcP6ktableUc ( __3a1 -> __O3__4expr.string2 , Ctbl , (unsigned char )159 ) ;
if ((__7n && __7n -> __O1__4expr.tp )&& (__7n -> __O1__4expr.tp -> base__4node == 119 )){ 
# 1442 "/home/claude/cfront-3/src/simpl2.cpp"
__4tmp_type = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned
# 1442 "/home/claude/cfront-3/src/simpl2.cpp"
char )125 , (struct type *)(((struct classdef *)(((struct classdef *)__7n -> __O1__4expr.tp ))))) ;
break ;
}
}
__4a11 = __3a1 ;
break ;
}
case 85 :
# 1450 "/home/claude/cfront-3/src/simpl2.cpp"
__4a11 = __3a1 ;
break ;
case 44 :
# 1453 "/home/claude/cfront-3/src/simpl2.cpp"
case 45 :
# 1454 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__3a1 -> __O2__4expr.e1 -> base__4node == 85 )|| (((__3a1 -> __O2__4expr.e1 -> base__4node == 45 )|| (__3a1 -> __O2__4expr.e1 -> base__4node ==
# 1454 "/home/claude/cfront-3/src/simpl2.cpp"
44 ))&& (__3a1 -> __O2__4expr.e1 -> __O2__4expr.e1 -> base__4node == 85 )))
# 1455 "/home/claude/cfront-3/src/simpl2.cpp"
__4a11 = __3a1 ;
break ;
case 112 :
# 1458 "/home/claude/cfront-3/src/simpl2.cpp"
case 145 :
# 1459 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__3a1 -> __O3__4expr.e2 -> base__4node == 85 )|| (((__3a1 -> __O3__4expr.e2 -> base__4node == 45 )|| (__3a1 -> __O3__4expr.e2 -> base__4node ==
# 1459 "/home/claude/cfront-3/src/simpl2.cpp"
44 ))&& (__3a1 -> __O3__4expr.e2 -> __O2__4expr.e1 -> base__4node == 85 )))
# 1460 "/home/claude/cfront-3/src/simpl2.cpp"
__4a11 = __3a1 ;
break ;
case 113 :
# 1463 "/home/claude/cfront-3/src/simpl2.cpp"
case 191 :
# 1464 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__3a1 -> __O2__4expr.e1 -> base__4node ){ 
# 1465 "/home/claude/cfront-3/src/simpl2.cpp"
case 85 :
# 1466 "/home/claude/cfront-3/src/simpl2.cpp"
case 177 :
# 1467 "/home/claude/cfront-3/src/simpl2.cpp"
__4a11 = __3a1 ;
}
}

# 1471 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O2__4expr.e1 -> base__4node == 45 ){ 
# 1472 "/home/claude/cfront-3/src/simpl2.cpp"
if (__4a11 )__4a11 = address__4exprFv ( __4a11 ) ;
__3a1 = address__4exprFv ( __3a1 ) ;
}

# 1476 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pcall __4This ;

# 1476 "/home/claude/cfront-3/src/simpl2.cpp"
__4This = __0this ;
if (__4a11 == 0 ){ 
# 1479 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3a1 -> base__4node == 85 )
# 1480 "/home/claude/cfront-3/src/simpl2.cpp"
__4a11 = __3a1 ;
else { 
# 1482 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __6nx ;

# 1482 "/home/claude/cfront-3/src/simpl2.cpp"
__6nx = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'K' ) ) ;
__6nx -> __O1__4expr.tp = (__4tmp_type ?__4tmp_type :__3a1 -> __O1__4expr.tp );
{ Pname __6n ;

# 1484 "/home/claude/cfront-3/src/simpl2.cpp"
__6n = dcl__4nameFP5tableUc ( __6nx , scope , (unsigned char )136 ) ;
( (__6nx ?(((void )(__6nx ?(((void )( ( ((((struct expr *)__6nx ))?(((void )((((struct expr *)__6nx ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 1485 "/home/claude/cfront-3/src/simpl2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__6nx , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
{ Pname __6cln ;

# 1486 "/home/claude/cfront-3/src/simpl2.cpp"
__6cln = is_cl_obj__4typeFv ( __3a1 -> __O1__4expr.tp ) ;
if (__6cln ){ 
# 1488 "/home/claude/cfront-3/src/simpl2.cpp"
Pclass __7cl ;

# 1488 "/home/claude/cfront-3/src/simpl2.cpp"
__7cl = (((struct classdef *)(((struct classdef *)__6cln -> __O1__4expr.tp ))));
if ((Ntmp == 0 )&& ( __7cl -> c_dtor__8classdef ) )Ntmp = __6cln ;
if (( __7cl -> c_itor__8classdef ) )__6n -> n_xref__4name = 1 ;
}
__6n -> n_scope__4name = 108 ;
assign__4nameFv ( __6n ) ;
__4a11 = (struct expr *)__6n ;
__3a1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__6n , __3a1 ) ;
if (ansi_opt )(((struct basetype *)(((struct basetype *)__6n -> __O1__4expr.tp ))))-> ansi_const__4type = 1 ;
__3a1 -> __O1__4expr.tp = __6n -> __O1__4expr.tp ;
simpl__4exprFv ( __3a1 ) ;
{ Pcall __6cc ;

# 1500 "/home/claude/cfront-3/src/simpl2.cpp"
struct call *__0__X139 ;

# 1500 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X140 ;

# 1500 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X141 ;

# 1499 "/home/claude/cfront-3/src/simpl2.cpp"
__6cc = ( (__0__X139 = 0 ), ( (__2__X140 = 0 ), ( (__2__X141 = 0 ), ( ((__0__X139 || (__0__X139 = (struct
# 1499 "/home/claude/cfront-3/src/simpl2.cpp"
call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X139 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X139 ), (unsigned char )109 , __2__X140 ,
# 1499 "/home/claude/cfront-3/src/simpl2.cpp"
__2__X141 ) ):0 ), __0__X139 ) ) ) ) ;
((*__6cc ))= (*__0this );
__0this -> base__4node = 71 ;
__0this -> __O2__4expr.e1 = __3a1 ;
__0this -> __O3__4expr.e2 = (struct expr *)__6cc ;
__4This = __6cc ;

# 1504 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1504 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1504 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
}

# 1508 "/home/claude/cfront-3/src/simpl2.cpp"
{ int __4i ;
Pexpr __4ie ;
Pname __4cn ;

# 1511 "/home/claude/cfront-3/src/simpl2.cpp"
struct ival *__0__X142 ;

# 1508 "/home/claude/cfront-3/src/simpl2.cpp"
__4i = __1f -> f_virtual__3fct ;
__4ie = (struct expr *)(__4i ?( (__0__X142 = 0 ), ( ((__0__X142 || (__0__X142 = (struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival)))
# 1509 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X142 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X142 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 ) ),
# 1509 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X142 -> __O2__4expr.i1 = ((long long )__4i ))) :0 ), __0__X142 ) ) :(((struct ival *)0 )));
__4cn = __1fn -> __O4__4expr.n_table -> t_name__5table ;
if (((((__1fn && __1fn -> __O3__4expr.n_initializer )&& cc -> nof__11dcl_context )&& ((cc -> nof__11dcl_context -> n_oper__4name == 161 )|| (cc -> nof__11dcl_context -> n_oper__4name == 162 )))&&
# 1511 "/home/claude/cfront-3/src/simpl2.cpp"
(((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp ))))-> memof__3fct -> c_abstract__8classdef )&& (strcmp ( (((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp ))))-> memof__3fct ->
# 1511 "/home/claude/cfront-3/src/simpl2.cpp"
string__8classdef , __4cn -> __O2__4expr.string ) == 0 ))
# 1516 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1518 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __5ee ;

# 1518 "/home/claude/cfront-3/src/simpl2.cpp"
__5ee = __4This -> __O2__4expr.e1 -> __O2__4expr.e1 ;
while (__5ee && (__5ee -> base__4node != 85 ))__5ee = __5ee -> __O2__4expr.e1 ;
if (__5ee && (strcmp ( __5ee -> __O2__4expr.string , (const char *)"this") == 0 ))
# 1521 "/home/claude/cfront-3/src/simpl2.cpp"
if
# 1521 "/home/claude/cfront-3/src/simpl2.cpp"
(cc -> nof__11dcl_context -> n_oper__4name == 161 )
# 1522 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1522 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V125 ;

# 1522 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V126 ;

# 1522 "/home/claude/cfront-3/src/simpl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"call of pure virtualF%n inK%n", (const struct ea *)( ((& __0__V125 )-> __O1__2ea.p =
# 1522 "/home/claude/cfront-3/src/simpl2.cpp"
((const void *)__1fn )), (& __0__V125 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V126 , (const void *)cc ->
# 1522 "/home/claude/cfront-3/src/simpl2.cpp"
nof__11dcl_context ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 1524 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1524 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V127 ;

# 1524 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V128 ;

# 1524 "/home/claude/cfront-3/src/simpl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"call of pure virtualF%n in destructor%n", (const struct ea *)( ((& __0__V127 )-> __O1__2ea.p =
# 1524 "/home/claude/cfront-3/src/simpl2.cpp"
((const void *)__1fn )), (& __0__V127 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V128 , (const void *)cc ->
# 1524 "/home/claude/cfront-3/src/simpl2.cpp"
nof__11dcl_context ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
vfunt_name = __1fn ;
{ Pcall __4vc ;

# 1527 "/home/claude/cfront-3/src/simpl2.cpp"
__4vc = vcall__FP4exprT1P3fctP8classdefT1 ( __4a11 , __4ie , __1f , ((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp ))), __4This -> __O3__4expr.e2 ) ;
vfunt_name = 0 ;
((*__4This ))= (*__4vc );
return ;

# 1530 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1530 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1530 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 1533 "/home/claude/cfront-3/src/simpl2.cpp"
{ Ptype __3tt ;

# 1533 "/home/claude/cfront-3/src/simpl2.cpp"
__3tt = __3r -> __O4__4expr.mem -> __O1__4expr.tp ;
llp :
# 1536 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3tt )
# 1537 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__3tt -> base__4node ){ 
# 1539 "/home/claude/cfront-3/src/simpl2.cpp"
case 97 :
# 1540 "/home/claude/cfront-3/src/simpl2.cpp"
__3tt = (((struct basetype *)(((struct basetype *)__3tt ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto llp ;
case 76 :
# 1543 "/home/claude/cfront-3/src/simpl2.cpp"
case 108 :
# 1544 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O4__4expr.fct_name == 0 ){ 
# 1546 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O4__4expr.fct_name = (__1fn = (((struct name *)(((struct name *)__0this -> __O2__4expr.e1 -> __O3__4expr.n_initializer )))));
# 1546 "/home/claude/cfront-3/src/simpl2.cpp"

# 1547 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1fn )__1f = (((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))));
}

# 1550 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O2__4expr.e1 -> base__4node == 45 )__3a1 = address__4exprFv ( __3a1 ) ;
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __3a1 , __0this -> __O3__4expr.e2 ) ;
__0this -> __O2__4expr.e1 = __3r -> __O4__4expr.mem ;
}

# 1553 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
}

# 1557 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O3__4expr.e2 )simpl__4exprFv ( __0this -> __O3__4expr.e2 ) ;

# 1559 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__1fn && __1f -> f_inline__3fct )&& (debug_opt == 0 )){ 
# 1560 "/home/claude/cfront-3/src/simpl2.cpp"
imeasure += __1f -> f_imeasure__3fct ;
{ Pclass __2cl ;

# 1561 "/home/claude/cfront-3/src/simpl2.cpp"
__2cl = __1f -> memof__3fct ;
if (__2cl && __2cl -> c_body__8classdef )dcl_print__8classdefFP4name ( __2cl , (struct name *)0 ) ;
{ Ptable __2oscope ;
Pexpr __2ee ;

# 1563 "/home/claude/cfront-3/src/simpl2.cpp"
__2oscope = scope ;
__2ee = expand__3fctFP4nameP5tableP4expr ( __1f , __1fn , scope , __0this -> __O3__4expr.e2 ) ;
scope = __2oscope ;
if (__2ee )((*(((struct expr *)(((struct expr *)__0this ))))))= (*__2ee );

# 1566 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1566 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
else if ((__1fn && (__1f -> f_inline__3fct == 0 ))&& __1f -> f_imeasure__3fct ){ 
# 1570 "/home/claude/cfront-3/src/simpl2.cpp"
uninline__FP4name ( __1fn ) ;
imeasure += 3 ;
}
else if ((__1fn && debug_opt )&& (__1f -> f_inline__3fct == 77 )){ 
# 1575 "/home/claude/cfront-3/src/simpl2.cpp"
expand_itor__FP8classdef ( __1f -> memof__3fct ) ;
}
else 
# 1578 "/home/claude/cfront-3/src/simpl2.cpp"
imeasure += 3 ;
}

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 1581 "/home/claude/cfront-3/src/simpl2.cpp"
void uninline__FP4name (Pname __1fn )
# 1583 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1584 "/home/claude/cfront-3/src/simpl2.cpp"
Pfct __1f ;

# 1584 "/home/claude/cfront-3/src/simpl2.cpp"
__1f = (((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))));

# 1587 "/home/claude/cfront-3/src/simpl2.cpp"
if (warning_opt ){ 
# 1588 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1588 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V143 ;

# 1588 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%n too complex for inlining", (const struct ea *)( ((&
# 1588 "/home/claude/cfront-3/src/simpl2.cpp"
__0__V143 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V143 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1588 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)ea0 ) ;
{ 
# 1589 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V144 ;

# 1589 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"out-of-line copy of %n created", (const struct ea *)( ((&
# 1589 "/home/claude/cfront-3/src/simpl2.cpp"
__0__V144 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V144 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1589 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)ea0 ) ;
} } }
__1f -> f_imeasure__3fct = 0 ;

# 1593 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1f -> body__3fct == 0 )
# 1594 "/home/claude/cfront-3/src/simpl2.cpp"
return ;

# 1596 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pstmt __1s ;

# 1596 "/home/claude/cfront-3/src/simpl2.cpp"
__1s = __1f -> body__3fct -> s__4stmt ;

# 1600 "/home/claude/cfront-3/src/simpl2.cpp"
while (__1s ){ 
# 1602 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1s -> base__4node == 72 ){ 
# 1604 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __3e ;

# 1604 "/home/claude/cfront-3/src/simpl2.cpp"
__3e = __1s -> __O2__4stmt.e ;
if (__3e )
# 1606 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__3e -> base__4node ){ 
# 1607 "/home/claude/cfront-3/src/simpl2.cpp"
case 71 :
# 1608 "/home/claude/cfront-3/src/simpl2.cpp"
case 147 :
# 1609 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pstmt __5ss ;

# 1610 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X145 ;

# 1610 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X146 ;

# 1610 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X147 ;

# 1609 "/home/claude/cfront-3/src/simpl2.cpp"
__5ss = (struct stmt *)( (__0__X145 = 0 ), ( (__2__X146 = no_where ), ( (__2__X147 = __3e -> __O3__4expr.e2 ), ( ((__0__X145 ||
# 1609 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X145 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X145 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X145 ), ((unsigned
# 1609 "/home/claude/cfront-3/src/simpl2.cpp"
char )72 ), __2__X146 , ((struct stmt *)0 )) ), (__0__X145 -> __O2__4stmt.e = __2__X147 )) :0 ), __0__X145 ) ) ) )
# 1609 "/home/claude/cfront-3/src/simpl2.cpp"
;
__1s -> __O2__4stmt.e = __3e -> __O2__4expr.e1 ;
__5ss -> s_list__4stmt = __1s -> s_list__4stmt ;
__1s -> s_list__4stmt = __5ss ;
( (__3e ?(((void )(__3e ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__3e , (size_t )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 1613 "/home/claude/cfront-3/src/simpl2.cpp"
;
continue ;
}
}
}
__1s = __1s -> s_list__4stmt ;
}

# 1623 "/home/claude/cfront-3/src/simpl2.cpp"
dcl_print__4nameFUc ( __1fn , (unsigned char )0 ) ;

# 1623 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 824 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 1679 "/home/claude/cfront-3/src/simpl2.cpp"
void temp_in_cond__FP4exprP4stmtP5table (Pexpr __1ee , Pstmt __1ss , Ptable __1tbl )
# 1684 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1687 "/home/claude/cfront-3/src/simpl2.cpp"
while ((__1ee -> base__4node == 71 )|| (__1ee -> base__4node == 147 ))__1ee = __1ee -> __O3__4expr.e2 ;
{ Ptype __1ct ;
Pname __1n ;

# 1688 "/home/claude/cfront-3/src/simpl2.cpp"
__1ct = unconst_type__FP4type ( __1ee -> __O1__4expr.tp ) ;
__1n = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'Q' ) ) ;
__1n -> __O1__4expr.tp = __1ct ;
{ Pname __1tmp ;

# 1691 "/home/claude/cfront-3/src/simpl2.cpp"
__1tmp = dcl__4nameFP5tableUc ( __1n , __1tbl , (unsigned char )136 ) ;
( (__1n ?(((void )(__1n ?(((void )( ( ((((struct expr *)__1n ))?(((void )((((struct expr *)__1n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 1692 "/home/claude/cfront-3/src/simpl2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1n , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
__1tmp -> n_scope__4name = 108 ;

# 1695 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __1v ;

# 1696 "/home/claude/cfront-3/src/simpl2.cpp"
register struct cast *__0__X148 ;

# 1695 "/home/claude/cfront-3/src/simpl2.cpp"
__1v = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )0 , (struct expr *)0 , (struct expr *)0 ) ;
((*__1v ))= (*__1ee );
__1ct -> permanent__4node = 1 ;
__1v = (struct expr *)( (__0__X148 = 0 ), ( ((__0__X148 || (__0__X148 = (struct cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast)))
# 1698 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X148 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X148 ), (unsigned char )191 , __1v , (struct expr *)0 ) ), (__0__X148 ->
# 1698 "/home/claude/cfront-3/src/simpl2.cpp"
__O1__4expr.tp = (__0__X148 -> __O4__4expr.tp2 = __1ct ))) :0 ), __0__X148 ) ) ;

# 1700 "/home/claude/cfront-3/src/simpl2.cpp"
__1tmp -> n_assigned_to__4name = 1 ;
{ Pexpr __1c ;

# 1701 "/home/claude/cfront-3/src/simpl2.cpp"
__1c = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1tmp , __1v ) ;
__1c -> __O1__4expr.tp = __1ct ;
__1ee -> base__4node = 71 ;
__1ee -> __O2__4expr.e1 = __1c ;

# 1706 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __1ex ;

# 1706 "/home/claude/cfront-3/src/simpl2.cpp"
__1ex = 0 ;

# 1708 "/home/claude/cfront-3/src/simpl2.cpp"
{ { Pstmt __1sx ;

# 1708 "/home/claude/cfront-3/src/simpl2.cpp"
__1sx = __1ss ;

# 1708 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__1sx ;__1sx = __1sx -> s_list__4stmt ) { 
# 1709 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1ex ){ 
# 1710 "/home/claude/cfront-3/src/simpl2.cpp"
__1ex = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1ex ,
# 1710 "/home/claude/cfront-3/src/simpl2.cpp"
__1sx -> __O2__4stmt.e ) ;
__1ex -> __O1__4expr.tp = __1sx -> __O2__4stmt.e -> __O1__4expr.tp ;
}
else 
# 1714 "/home/claude/cfront-3/src/simpl2.cpp"
__1ex = __1sx -> __O2__4stmt.e ;
}
__1ee -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1ex , (struct expr *)__1tmp ) ;
__1ee -> __O3__4expr.e2 -> __O1__4expr.tp = __1ct ;

# 1717 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1717 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1717 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1717 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1717 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1717 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1717 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 467 "/home/claude/cfront-3/src/cfront.h"

# 1720 "/home/claude/cfront-3/src/simpl2.cpp"
bit not_safe__FP4expr (Pexpr __1e );

# 1720 "/home/claude/cfront-3/src/simpl2.cpp"
bit not_safe__FP4expr (Pexpr __1e )
# 1721 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1723 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__1e -> base__4node ){ 
# 1724 "/home/claude/cfront-3/src/simpl2.cpp"
default :
# 1725 "/home/claude/cfront-3/src/simpl2.cpp"
return (unsigned char )1 ;

# 1734 "/home/claude/cfront-3/src/simpl2.cpp"
case 85 :
# 1737 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pname __3n ;

# 1737 "/home/claude/cfront-3/src/simpl2.cpp"
__3n = (((struct name *)(((struct name *)__1e ))));
if ((__3n -> __O4__4expr.n_table != gtbl )&& (__3n -> __O4__4expr.n_table -> t_name__5table == 0 )){ 
# 1739 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __4cn ;

# 1740 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__0__X149 ;

# 1739 "/home/claude/cfront-3/src/simpl2.cpp"
__4cn = is_cl_obj__4typeFv ( __3n -> __O1__4expr.tp ) ;
if (__4cn && ( (__0__X149 = (((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp ))))), ( __0__X149 -> c_dtor__8classdef ) ) )return (unsigned
# 1740 "/home/claude/cfront-3/src/simpl2.cpp"
char )1 ;
}
}
case 150 :
# 1744 "/home/claude/cfront-3/src/simpl2.cpp"
case 82 :
# 1745 "/home/claude/cfront-3/src/simpl2.cpp"
case 84 :
# 1746 "/home/claude/cfront-3/src/simpl2.cpp"
case 83 :
# 1747 "/home/claude/cfront-3/src/simpl2.cpp"
case 81 :
# 1748 "/home/claude/cfront-3/src/simpl2.cpp"
return (unsigned char )0 ;
case 46 :
# 1750 "/home/claude/cfront-3/src/simpl2.cpp"
case 47 :
# 1751 "/home/claude/cfront-3/src/simpl2.cpp"
case 112 :
# 1752 "/home/claude/cfront-3/src/simpl2.cpp"
case 145 :
# 1753 "/home/claude/cfront-3/src/simpl2.cpp"
return not_safe__FP4expr ( __1e -> __O3__4expr.e2 ) ;
case 111 :
# 1756 "/home/claude/cfront-3/src/simpl2.cpp"
{ int __3i ;

# 1756 "/home/claude/cfront-3/src/simpl2.cpp"
__3i = not_safe__FP4expr ( __1e -> __O2__4expr.e1 ) ;
if (__3i )return (unsigned char )__3i ;
if (__1e -> __O3__4expr.e2 )return not_safe__FP4expr ( __1e -> __O3__4expr.e2 ) ;
return (unsigned char )0 ;
}
case 71 :
# 1762 "/home/claude/cfront-3/src/simpl2.cpp"
case 54 :
# 1763 "/home/claude/cfront-3/src/simpl2.cpp"
case 55 :
# 1764 "/home/claude/cfront-3/src/simpl2.cpp"
case 50 :
# 1765 "/home/claude/cfront-3/src/simpl2.cpp"
case 51 :
# 1766 "/home/claude/cfront-3/src/simpl2.cpp"
case 53 :
# 1767 "/home/claude/cfront-3/src/simpl2.cpp"
case 70 :
# 1768 "/home/claude/cfront-3/src/simpl2.cpp"
case 126 :
# 1769 "/home/claude/cfront-3/src/simpl2.cpp"
case 127 :
# 1770 "/home/claude/cfront-3/src/simpl2.cpp"
case 128 :
# 1771 "/home/claude/cfront-3/src/simpl2.cpp"
case 129 :
# 1772 "/home/claude/cfront-3/src/simpl2.cpp"
case 65 :
# 1773 "/home/claude/cfront-3/src/simpl2.cpp"
case 52 :
# 1774 "/home/claude/cfront-3/src/simpl2.cpp"
case
# 1774 "/home/claude/cfront-3/src/simpl2.cpp"
67 :
# 1775 "/home/claude/cfront-3/src/simpl2.cpp"
case 66 :
# 1776 "/home/claude/cfront-3/src/simpl2.cpp"
case 58 :
# 1777 "/home/claude/cfront-3/src/simpl2.cpp"
case 59 :
# 1778 "/home/claude/cfront-3/src/simpl2.cpp"
case 60 :
# 1779 "/home/claude/cfront-3/src/simpl2.cpp"
case 61 :
# 1780 "/home/claude/cfront-3/src/simpl2.cpp"
case 62 :
# 1781 "/home/claude/cfront-3/src/simpl2.cpp"
case 63 :
# 1782 "/home/claude/cfront-3/src/simpl2.cpp"
return (unsigned char )(not_safe__FP4expr ( __1e -> __O2__4expr.e1 ) ||
# 1782 "/home/claude/cfront-3/src/simpl2.cpp"
not_safe__FP4expr ( __1e -> __O3__4expr.e2 ) );
case 68 :
# 1784 "/home/claude/cfront-3/src/simpl2.cpp"
return (unsigned char )((not_safe__FP4expr ( __1e -> __O4__4expr.cond ) || not_safe__FP4expr ( __1e -> __O2__4expr.e1 ) )|| not_safe__FP4expr ( __1e ->
# 1784 "/home/claude/cfront-3/src/simpl2.cpp"
__O3__4expr.e2 ) );
}
}

# 1789 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr curr_expr = 0 ;

# 76 "/home/claude/cfront-3/src/cfront.h"

# 1020 "/home/claude/cfront-3/src/cfront.h"
Pstmt copy__4stmtFv (struct stmt *__0this );

# 1083 "/home/claude/cfront-3/src/cfront.h"

# 1223 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr replace_temp__FP4exprT1 (Pexpr , Pexpr );

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1083 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1083 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 1230 "/home/claude/cfront-3/src/cfront.h"
extern void check_visibility__FP4nameT1P8classdefP5tableT1 (Pname , Pname , Pclass , Ptable , Pname );

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 465 "/home/claude/cfront-3/src/cfront.h"
Pname has_oper__8classdefFUc (struct classdef *__0this , TOK );

# 220 "/home/claude/cfront-3/src/cfront.h"
struct table *__ct__5tableFsP5tableP4name (struct table *__0this , short , Ptable , Pname );

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1083 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 1794 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt simpl__4stmtFv (register struct stmt *__0this )
# 1798 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1799 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this == 0 )error__FiPCc ( (int )'i' , (const char *)"0->S::simpl()")
# 1799 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 1803 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 1807 "/home/claude/cfront-3/src/simpl2.cpp"
stmtno ++ ;
if (__0this -> __O2__4stmt.e )curr_expr = __0this -> __O2__4stmt.e ;

# 1810 "/home/claude/cfront-3/src/simpl2.cpp"
Ntmp_tbl = ((__0this -> base__4node != 116 )?__0this -> memtbl__4stmt :(((struct table *)0 )));

# 1813 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__0this -> base__4node ){ 
# 1813 "/home/claude/cfront-3/src/simpl2.cpp"
unsigned long __2__X156 ;

# 1814 "/home/claude/cfront-3/src/simpl2.cpp"
default :
# 1815 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1815 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V150 ;

# 1815 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"S::simpl(%k)", (const struct ea *)( (__2__X156 =
# 1815 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> base__4node ), ( (( ((& __0__V150 )-> __O1__2ea.i = __2__X156 ), 0 ) ), (& __0__V150 )) ) ,
# 1815 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 1817 "/home/claude/cfront-3/src/simpl2.cpp"
case 1 :
# 1818 "/home/claude/cfront-3/src/simpl2.cpp"
break ;

# 1820 "/home/claude/cfront-3/src/simpl2.cpp"
case 3 :
# 1821 "/home/claude/cfront-3/src/simpl2.cpp"
if (break_del_list ){ 
# 1822 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __3bs ;
Pstmt __3dl ;

# 1824 "/home/claude/cfront-3/src/simpl2.cpp"
struct pair *__0__X157 ;

# 1824 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X158 ;

# 1824 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X159 ;

# 1824 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X160 ;

# 1822 "/home/claude/cfront-3/src/simpl2.cpp"
__3bs = __ct__4stmtFUc3locP4stmt ( (struct stmt *)0 , __0this -> base__4node , __0this -> where__4stmt , (struct stmt *)0 ) ;
__3dl = copy__4stmtFv ( break_del_list ) ;
__0this -> base__4node = 116 ;
__0this -> s__4stmt = (struct stmt *)( (__0__X157 = 0 ), ( (__2__X158 = __0this -> where__4stmt ), ( (__2__X159 = __3dl ), (
# 1825 "/home/claude/cfront-3/src/simpl2.cpp"
(__2__X160 = __3bs ), ( ((__0__X157 || (__0__X157 = (struct pair *)__nw__4stmtSFUl ( (size_t )(sizeof (struct pair))) ))?( (__0__X157 = (struct
# 1825 "/home/claude/cfront-3/src/simpl2.cpp"
pair *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X157 ), (unsigned char )166 , __2__X158 , __2__X159 ) ), (__0__X157 -> __O2__4stmt.s2 = __2__X160 )) :0 ), __0__X157 )
# 1825 "/home/claude/cfront-3/src/simpl2.cpp"
) ) ) ) ;
}
break ;

# 1829 "/home/claude/cfront-3/src/simpl2.cpp"
case 7 :
# 1830 "/home/claude/cfront-3/src/simpl2.cpp"
if (continue_del_list ){ 
# 1831 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __3bs ;
Pstmt __3dl ;

# 1833 "/home/claude/cfront-3/src/simpl2.cpp"
struct pair *__0__X161 ;

# 1833 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X162 ;

# 1833 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X163 ;

# 1833 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X164 ;

# 1831 "/home/claude/cfront-3/src/simpl2.cpp"
__3bs = __ct__4stmtFUc3locP4stmt ( (struct stmt *)0 , __0this -> base__4node , __0this -> where__4stmt , (struct stmt *)0 ) ;
__3dl = copy__4stmtFv ( continue_del_list ) ;
__0this -> base__4node = 116 ;
__0this -> s__4stmt = (struct stmt *)( (__0__X161 = 0 ), ( (__2__X162 = __0this -> where__4stmt ), ( (__2__X163 = __3dl ), (
# 1834 "/home/claude/cfront-3/src/simpl2.cpp"
(__2__X164 = __3bs ), ( ((__0__X161 || (__0__X161 = (struct pair *)__nw__4stmtSFUl ( (size_t )(sizeof (struct pair))) ))?( (__0__X161 = (struct
# 1834 "/home/claude/cfront-3/src/simpl2.cpp"
pair *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X161 ), (unsigned char )166 , __2__X162 , __2__X163 ) ), (__0__X161 -> __O2__4stmt.s2 = __2__X164 )) :0 ), __0__X161 )
# 1834 "/home/claude/cfront-3/src/simpl2.cpp"
) ) ) ) ;
}
break ;

# 1838 "/home/claude/cfront-3/src/simpl2.cpp"
case 8 :
# 1839 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4stmtFv ( __0this -> s__4stmt ) ;
break ;

# 1842 "/home/claude/cfront-3/src/simpl2.cpp"
case 72 :
# 1843 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O2__4stmt.e ){ 
# 1844 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O2__4stmt.e -> base__4node == 111 )__0this -> __O2__4stmt.e = __0this -> __O2__4stmt.e -> __O2__4expr.e1 ;
simpl__4exprFv ( __0this -> __O2__4stmt.e ) ;
if (__0this -> __O2__4stmt.e -> base__4node == 111 )__0this -> __O2__4stmt.e = __0this -> __O2__4stmt.e -> __O2__4expr.e1 ;
if (__0this -> __O2__4stmt.e -> base__4node == 124 )
# 1848 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O2__4stmt.e = 0 ;
}
break ;

# 1852 "/home/claude/cfront-3/src/simpl2.cpp"
case 28 :
# 1853 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 1867 "/home/claude/cfront-3/src/simpl2.cpp"
no_of_returns ++ ;

# 1869 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pstmt __3dl ;
Pfct __3f ;

# 1869 "/home/claude/cfront-3/src/simpl2.cpp"
__3dl = (del_list ?copy__4stmtFv ( del_list ) :(((struct stmt *)0 )));
__3f = (((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))));

# 1872 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O2__4stmt.e == 0 )__0this -> __O2__4stmt.e = dummy ;
if ((__0this -> __O2__4stmt.e == dummy )&& (curr_fct -> n_oper__4name == 161 ))__0this -> __O2__4stmt.e = (struct expr *)__3f -> f_this__3fct ;

# 1877 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __3tt ;

# 1877 "/home/claude/cfront-3/src/simpl2.cpp"
__3tt = __0this -> __O2__4stmt.e ;
while ((__3tt -> base__4node == 113 )|| (__3tt -> base__4node == 191 ))
# 1879 "/home/claude/cfront-3/src/simpl2.cpp"
__3tt = __3tt -> __O2__4expr.e1 ;
if (__3tt -> base__4node == 124 )
# 1881 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O2__4stmt.e = __3tt ;

# 1883 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O2__4stmt.e -> base__4node == 124 ){ 
# 1884 "/home/claude/cfront-3/src/simpl2.cpp"
extern Pbase mptr_type ;

# 1889 "/home/claude/cfront-3/src/simpl2.cpp"
Ptable __4ftbl ;
Pname __4temp ;

# 1889 "/home/claude/cfront-3/src/simpl2.cpp"
__4ftbl = (((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))))-> body__3fct -> memtbl__4stmt ;
__4temp = make_tmp__FcP4typeP5table ( 'A' , (struct type *)mptr_type , __4ftbl ) ;

# 1895 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O2__4stmt.e = mptr_assign__FP4exprT1 ( (struct expr *)__4temp , __0this -> __O2__4stmt.e ) ;
__0this -> __O2__4stmt.e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __0this -> __O2__4stmt.e , (struct expr *)__4temp ) ;
__0this -> __O2__4stmt.e -> __O1__4expr.tp = (struct type *)mptr_type ;
}

# 1900 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3f -> f_result__3fct ){ 
# 1901 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O2__4stmt.e -> base__4node == 147 )__0this -> __O2__4stmt.e = replace_temp__FP4exprT1 ( __0this -> __O2__4stmt.e , (struct expr *)__3f ->
# 1901 "/home/claude/cfront-3/src/simpl2.cpp"
f_result__3fct ) ;
if (__3f -> nrv__3fct && return_nrv__FP4expr ( __0this -> __O2__4stmt.e ) )__0this -> __O2__4stmt.e = dummy ;
simpl__4exprFv ( __0this -> __O2__4stmt.e ) ;
{ Pstmt __4cs ;

# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
struct pair *__0__X165 ;

# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X166 ;

# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X167 ;

# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X168 ;

# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X169 ;

# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X170 ;

# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X171 ;

# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X172 ;

# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X173 ;

# 1904 "/home/claude/cfront-3/src/simpl2.cpp"
__4cs = (struct stmt *)( (__0__X171 = 0 ), ( (__2__X172 = __0this -> where__4stmt ), ( (__2__X173 = __0this -> __O2__4stmt.e ), (
# 1904 "/home/claude/cfront-3/src/simpl2.cpp"
((__0__X171 || (__0__X171 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X171 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X171 ),
# 1904 "/home/claude/cfront-3/src/simpl2.cpp"
((unsigned char )72 ), __2__X172 , ((struct stmt *)0 )) ), (__0__X171 -> __O2__4stmt.e = __2__X173 )) :0 ), __0__X171 ) ) )
# 1904 "/home/claude/cfront-3/src/simpl2.cpp"
) ;
if (__3dl )__4cs = (struct stmt *)( (__0__X165 = 0 ), ( (__2__X166 = __0this -> where__4stmt ), ( (__2__X167 = __4cs ), (
# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
(__2__X168 = __3dl ), ( ((__0__X165 || (__0__X165 = (struct pair *)__nw__4stmtSFUl ( (size_t )(sizeof (struct pair))) ))?( (__0__X165 = (struct
# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
pair *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X165 ), (unsigned char )166 , __2__X166 , __2__X167 ) ), (__0__X165 -> __O2__4stmt.s2 = __2__X168 )) :0 ), __0__X165 )
# 1905 "/home/claude/cfront-3/src/simpl2.cpp"
) ) ) ) ;
__0this -> base__4node = 166 ;
__0this -> s__4stmt = __4cs ;
__0this -> __O2__4stmt.s2 = (struct stmt *)( (__0__X169 = 0 ), ( (__2__X170 = __0this -> where__4stmt ), ( ((__0__X169 || (__0__X169 = (struct
# 1908 "/home/claude/cfront-3/src/simpl2.cpp"
estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X169 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X169 ), ((unsigned char )28 ),
# 1908 "/home/claude/cfront-3/src/simpl2.cpp"
__2__X170 , ((struct stmt *)0 )) ), (__0__X169 -> __O2__4stmt.e = ((struct expr *)0 ))) :0 ), __0__X169 ) ) ) ;

# 1908 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
else { 
# 1911 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4exprFv ( __0this -> __O2__4stmt.e ) ;
if (__3dl ){ 
# 1913 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__0this -> __O2__4stmt.e != dummy )&& not_safe__FP4expr ( __0this -> __O2__4stmt.e ) ){ 
# 1915 "/home/claude/cfront-3/src/simpl2.cpp"
Ptable __6ftbl ;

# 1917 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __6r ;
bit __6was_ansi ;

# 1919 "/home/claude/cfront-3/src/simpl2.cpp"
register struct cast *__0__X174 ;

# 1919 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X175 ;

# 1919 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X176 ;

# 1915 "/home/claude/cfront-3/src/simpl2.cpp"
__6ftbl = (((struct fct *)(((struct fct *)curr_fct -> __O1__4expr.tp ))))-> body__3fct -> memtbl__4stmt ;

# 1917 "/home/claude/cfront-3/src/simpl2.cpp"
__6r = look__5tableFPCcUc ( __6ftbl , (const char *)"_result", (unsigned char )0 ) ;
# 1917 "/home/claude/cfront-3/src/simpl2.cpp"

# 1918 "/home/claude/cfront-3/src/simpl2.cpp"
__6was_ansi = 0 ;
if (__6r == 0 ){ 
# 1920 "/home/claude/cfront-3/src/simpl2.cpp"
__6r = __ct__4nameFPCc ( (struct name *)0 , (const char *)"_result")
# 1920 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 1922 "/home/claude/cfront-3/src/simpl2.cpp"
__6r -> __O1__4expr.tp = unconst_type__FP4type ( __0this -> __O1__4stmt.ret_tp ) ;
__6was_ansi = (__6r -> __O1__4expr.tp != __0this -> __O1__4stmt.ret_tp );
{ Pname __7rn ;

# 1924 "/home/claude/cfront-3/src/simpl2.cpp"
__7rn = dcl__4nameFP5tableUc ( __6r , __6ftbl , (unsigned char )136 ) ;
__7rn -> n_scope__4name = 108 ;
__7rn -> where__4name = no_where ;
assign__4nameFv ( __7rn ) ;
( (__6r ?(((void )(__6r ?(((void )( ( ((((struct expr *)__6r ))?(((void )((((struct expr *)__6r ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 1928 "/home/claude/cfront-3/src/simpl2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__6r , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
__6r = __7rn ;

# 1929 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
if (__6was_ansi )
# 1932 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O2__4stmt.e = (struct expr *)( (__0__X174 = 0 ), ( (__2__X175 = __6r -> __O1__4expr.tp ), ( (__2__X176 = __0this ->
# 1932 "/home/claude/cfront-3/src/simpl2.cpp"
__O2__4stmt.e ), ( ((__0__X174 || (__0__X174 = (struct cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast))) ))?( (__0__X174 = (struct cast *)__ct__4exprFUcP4exprT2 (
# 1932 "/home/claude/cfront-3/src/simpl2.cpp"
((struct expr *)__0__X174 ), (unsigned char )191 , __2__X176 , (struct expr *)0 ) ), (__0__X174 -> __O1__4expr.tp = (__0__X174 -> __O4__4expr.tp2 = __2__X175 )))
# 1932 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X174 ) ) ) ) ;
{ Pexpr __6as ;

# 1933 "/home/claude/cfront-3/src/simpl2.cpp"
__6as = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__6r , __0this -> __O2__4stmt.e ) ;
__6as -> __O1__4expr.tp = __6r -> __O1__4expr.tp ;
{ Pstmt __6cs ;

# 1936 "/home/claude/cfront-3/src/simpl2.cpp"
struct pair *__0__X177 ;

# 1936 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X178 ;

# 1936 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X179 ;

# 1936 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X180 ;

# 1936 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X185 ;

# 1936 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X186 ;

# 1935 "/home/claude/cfront-3/src/simpl2.cpp"
__6cs = (struct stmt *)( (__0__X185 = 0 ), ( (__2__X186 = __0this -> where__4stmt ), ( ((__0__X185 || (__0__X185 = (struct estmt *)__nw__4stmtSFUl (
# 1935 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X185 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X185 ), ((unsigned char )72 ), __2__X186 ,
# 1935 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X185 -> __O2__4stmt.e = __6as )) :0 ), __0__X185 ) ) ) ;
__6cs = (struct stmt *)( (__0__X177 = 0 ), ( (__2__X178 = __0this -> where__4stmt ), ( (__2__X179 = __6cs ), ( (__2__X180 =
# 1936 "/home/claude/cfront-3/src/simpl2.cpp"
__3dl ), ( ((__0__X177 || (__0__X177 = (struct pair *)__nw__4stmtSFUl ( (size_t )(sizeof (struct pair))) ))?( (__0__X177 = (struct pair *)__ct__4stmtFUc3locP4stmt (
# 1936 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)__0__X177 ), (unsigned char )166 , __2__X178 , __2__X179 ) ), (__0__X177 -> __O2__4stmt.s2 = __2__X180 )) :0 ), __0__X177 ) )
# 1936 "/home/claude/cfront-3/src/simpl2.cpp"
) ) ) ;
__0this -> base__4node = 166 ;
__0this -> s__4stmt = __6cs ;
{ Pexpr __6eee ;

# 1940 "/home/claude/cfront-3/src/simpl2.cpp"
register struct cast *__0__X181 ;

# 1940 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X182 ;

# 1940 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X183 ;

# 1940 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X184 ;

# 1939 "/home/claude/cfront-3/src/simpl2.cpp"
__6eee = (((struct expr *)(((struct expr *)__6r ))));
if (__6was_ansi )
# 1941 "/home/claude/cfront-3/src/simpl2.cpp"
__6eee = (struct expr *)( (__0__X181 = 0 ), ( (__2__X182 = __0this -> __O1__4stmt.ret_tp ), ( ((__0__X181 || (__0__X181 = (struct
# 1941 "/home/claude/cfront-3/src/simpl2.cpp"
cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast))) ))?( (__0__X181 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X181 ), (unsigned char )191 ,
# 1941 "/home/claude/cfront-3/src/simpl2.cpp"
__6eee , (struct expr *)0 ) ), (__0__X181 -> __O1__4expr.tp = (__0__X181 -> __O4__4expr.tp2 = __2__X182 ))) :0 ), __0__X181 ) ) ) ;
# 1941 "/home/claude/cfront-3/src/simpl2.cpp"

# 1942 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O2__4stmt.s2 = (struct stmt *)( (__0__X183 = 0 ), ( (__2__X184 = __0this -> where__4stmt ), ( ((__0__X183 || (__0__X183 = (struct
# 1942 "/home/claude/cfront-3/src/simpl2.cpp"
estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X183 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X183 ), ((unsigned char )28 ),
# 1942 "/home/claude/cfront-3/src/simpl2.cpp"
__2__X184 , ((struct stmt *)0 )) ), (__0__X183 -> __O2__4stmt.e = __6eee )) :0 ), __0__X183 ) ) ) ;

# 1942 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1942 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1942 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1944 "/home/claude/cfront-3/src/simpl2.cpp"
}
else { 
# 1945 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X187 ;

# 1945 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X188 ;

# 1945 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X189 ;

# 1946 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> base__4node = 166 ;
__0this -> s__4stmt = __3dl ;
__0this -> __O2__4stmt.s2 = (struct stmt *)( (__0__X187 = 0 ), ( (__2__X188 = __0this -> where__4stmt ), ( (__2__X189 = __0this -> __O2__4stmt.e ),
# 1948 "/home/claude/cfront-3/src/simpl2.cpp"
( ((__0__X187 || (__0__X187 = (struct estmt *)__nw__4stmtSFUl ( (size_t )(sizeof (struct estmt))) ))?( (__0__X187 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct
# 1948 "/home/claude/cfront-3/src/simpl2.cpp"
stmt *)__0__X187 ), ((unsigned char )28 ), __2__X188 , ((struct stmt *)0 )) ), (__0__X187 -> __O2__4stmt.e = __2__X189 )) :0 ), __0__X187 ) )
# 1948 "/home/claude/cfront-3/src/simpl2.cpp"
) ) ;
}
__0this -> __O2__4stmt.s2 -> __O1__4stmt.ret_tp = __0this -> __O1__4stmt.ret_tp ;
}
}

# 1964 "/home/claude/cfront-3/src/simpl2.cpp"
break ;

# 1964 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 1964 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 1967 "/home/claude/cfront-3/src/simpl2.cpp"
case 39 :
# 1968 "/home/claude/cfront-3/src/simpl2.cpp"
case 10 :
# 1969 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4exprFv ( __0this -> __O2__4stmt.e ) ;
{ Pstmt __3obl ;
Pstmt __3ocl ;

# 1970 "/home/claude/cfront-3/src/simpl2.cpp"
__3obl = break_del_list ;
__3ocl = continue_del_list ;
break_del_list = 0 ;
continue_del_list = 0 ;
simpl__4stmtFv ( __0this -> s__4stmt ) ;
break_del_list = __3obl ;
continue_del_list = __3ocl ;
}
break ;

# 1980 "/home/claude/cfront-3/src/simpl2.cpp"
case 33 :
# 1981 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4exprFv ( __0this -> __O2__4stmt.e ) ;
{ Pstmt __3obl ;

# 1982 "/home/claude/cfront-3/src/simpl2.cpp"
__3obl = break_del_list ;
break_del_list = 0 ;
simpl__4stmtFv ( __0this -> s__4stmt ) ;
break_del_list = __3obl ;
}
switch (__0this -> s__4stmt -> base__4node ){ 
# 1988 "/home/claude/cfront-3/src/simpl2.cpp"
case 72 :
# 1990 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> s__4stmt -> __O2__4stmt.e )goto df ;
case 8 :
# 1992 "/home/claude/cfront-3/src/simpl2.cpp"
case 115 :
# 1993 "/home/claude/cfront-3/src/simpl2.cpp"
case 4 :
# 1994 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> s__4stmt -> s__4stmt && (__0this -> s__4stmt -> s__4stmt -> base__4node == 116 ))
# 1995 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> s__4stmt = __0this ->
# 1995 "/home/claude/cfront-3/src/simpl2.cpp"
s__4stmt -> s__4stmt ;
else break ;
case 116 :
# 1998 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> s__4stmt -> s__4stmt )
# 1999 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__0this -> s__4stmt -> s__4stmt -> base__4node ){ 
# 2000 "/home/claude/cfront-3/src/simpl2.cpp"
case 3 :
# 2001 "/home/claude/cfront-3/src/simpl2.cpp"
case 4 :
# 2002 "/home/claude/cfront-3/src/simpl2.cpp"
case 115 :
# 2003 "/home/claude/cfront-3/src/simpl2.cpp"
case 8 :
# 2004 "/home/claude/cfront-3/src/simpl2.cpp"
break
# 2004 "/home/claude/cfront-3/src/simpl2.cpp"
;
default :
# 2006 "/home/claude/cfront-3/src/simpl2.cpp"
goto df ;
}
break ;
default :
# 2010 "/home/claude/cfront-3/src/simpl2.cpp"
df :
# 2011 "/home/claude/cfront-3/src/simpl2.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> s__4stmt -> where__4stmt , (const char *)"S orIdE not reached: (case label missing?)", (const
# 2011 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
}
break ;

# 2015 "/home/claude/cfront-3/src/simpl2.cpp"
case 4 :
# 2016 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4exprFv ( __0this -> __O2__4stmt.e ) ;
simpl__4stmtFv ( __0this -> s__4stmt ) ;
break ;

# 2020 "/home/claude/cfront-3/src/simpl2.cpp"
case 115 :
# 2021 "/home/claude/cfront-3/src/simpl2.cpp"
if (del_list )error__FiPCc ( (int )'s' , (const char *)"label in blockW destructors") ;
simpl__4stmtFv ( __0this -> s__4stmt ) ;
break ;

# 2025 "/home/claude/cfront-3/src/simpl2.cpp"
case 19 :
# 2035 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2036 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __3n ;

# 2037 "/home/claude/cfront-3/src/simpl2.cpp"
const void *__2__X190 ;

# 2036 "/home/claude/cfront-3/src/simpl2.cpp"
__3n = look__5tableFPCcUc ( scope , __0this -> __O1__4stmt.d -> __O2__4expr.string , (unsigned char )115 ) ;
if (__3n == 0 ){ 
# 2037 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V151 ;

# 2037 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __0this -> where__4stmt , (const char *)"label%n missing", (const
# 2037 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea *)( (__2__X190 = (const void *)__0this -> __O1__4stmt.d ), ( ((& __0__V151 )-> __O1__2ea.p = __2__X190 ), (& __0__V151 ))
# 2037 "/home/claude/cfront-3/src/simpl2.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if ((__3n -> __O2__4name.n_realscope != scope )&& __3n -> n_assigned_to__4name ){ 
# 2045 "/home/claude/cfront-3/src/simpl2.cpp"
Ptable __4r ;

# 2045 "/home/claude/cfront-3/src/simpl2.cpp"
__4r = 0 ;

# 2047 "/home/claude/cfront-3/src/simpl2.cpp"
{ { Ptable __4q ;

# 2047 "/home/claude/cfront-3/src/simpl2.cpp"
__4q = __3n -> __O2__4name.n_realscope ;

# 2047 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__4q != gtbl ;__4q = __4q -> next__5table ) { 
# 2048 "/home/claude/cfront-3/src/simpl2.cpp"
{ { Ptable __5p ;

# 2048 "/home/claude/cfront-3/src/simpl2.cpp"
__5p = scope ;

# 2048 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__5p != gtbl ;__5p = __5p -> next__5table ) { 
# 2049 "/home/claude/cfront-3/src/simpl2.cpp"
if (__5p == __4q ){ 
# 2050 "/home/claude/cfront-3/src/simpl2.cpp"
__4r = __5p ;
goto xyzzy ;
}
}

# 2053 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2053 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2056 "/home/claude/cfront-3/src/simpl2.cpp"
xyzzy :if (__4r == 0 )error__FiP3locPCcRC2eaN34 ( (int )'i' , & __0this -> where__4stmt , (const char *)"finding root of subtree",
# 2056 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 2069 "/home/claude/cfront-3/src/simpl2.cpp"
{ { Ptable __4p ;

# 2069 "/home/claude/cfront-3/src/simpl2.cpp"
__4p = __3n -> __O2__4name.n_realscope ;

# 2069 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__4p != __4r ;__4p = __4p -> next__5table ) 
# 2070 "/home/claude/cfront-3/src/simpl2.cpp"
if (__4p -> init_stat__5table == 2 ){ 
# 2070 "/home/claude/cfront-3/src/simpl2.cpp"
const void *__2__X191 ;

# 2071 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2071 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V152 ;

# 2071 "/home/claude/cfront-3/src/simpl2.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> where__4stmt , (const char *)"goto%n pastDWIr", (const struct ea *)(
# 2071 "/home/claude/cfront-3/src/simpl2.cpp"
(__2__X191 = (const void *)__0this -> __O1__4stmt.d ), ( ((& __0__V152 )-> __O1__2ea.p = __2__X191 ), (& __0__V152 )) ) ,
# 2071 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
goto plugh ;
} }
else if (__4p -> init_stat__5table == 0 ){ 
# 2075 "/home/claude/cfront-3/src/simpl2.cpp"
int __5i ;
{ { Pname __5nn ;

# 2077 "/home/claude/cfront-3/src/simpl2.cpp"
int __2__X192 ;

# 2077 "/home/claude/cfront-3/src/simpl2.cpp"
int __2__X194 ;

# 2076 "/home/claude/cfront-3/src/simpl2.cpp"
__5nn = ( (__2__X194 = (__5i = 1 )), ( (((__2__X194 <= 0 )|| (__4p -> free_slot__5table <= __2__X194 ))?(((struct name *)0 )):(__4p -> entries__5table [__2__X194 ]))) )
# 2076 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 2076 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__5nn ;__5nn = (__5nn -> n_tbl_list__4name ?__5nn -> n_tbl_list__4name :( (__2__X192 = (++ __5i )), ( (((__2__X192 <= 0 )|| (__4p -> free_slot__5table <= __2__X192 ))?(((struct name *)0 )):(__4p ->
# 2076 "/home/claude/cfront-3/src/simpl2.cpp"
entries__5table [__2__X192 ]))) ) )) 
# 2077 "/home/claude/cfront-3/src/simpl2.cpp"
if (__5nn -> __O3__4expr.n_initializer || __5nn -> n_evaluated__4name ){ 
# 2077 "/home/claude/cfront-3/src/simpl2.cpp"
const void *__2__X193 ;

# 2078 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2078 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V153 ;

# 2078 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V154 ;

# 2078 "/home/claude/cfront-3/src/simpl2.cpp"
error__FP3locPCcRC2eaN33 ( & __5nn -> where__4name , (const char *)"goto%n pastId%n", (const struct ea *)(
# 2078 "/home/claude/cfront-3/src/simpl2.cpp"
(__2__X193 = (const void *)__0this -> __O1__4stmt.d ), ( ((& __0__V153 )-> __O1__2ea.p = __2__X193 ), (& __0__V153 )) ) ,
# 2078 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)( ((& __0__V154 )-> __O1__2ea.p = ((const void *)__5nn )), (& __0__V154 )) , (const struct
# 2078 "/home/claude/cfront-3/src/simpl2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
goto plugh ;
} }

# 2080 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2080 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
plugh :
# 2092 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2093 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __5dd ;

# 2093 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __5ddt ;

# 2093 "/home/claude/cfront-3/src/simpl2.cpp"
__5dd = 0 ;

# 2093 "/home/claude/cfront-3/src/simpl2.cpp"
__5ddt = 0 ;

# 2095 "/home/claude/cfront-3/src/simpl2.cpp"
{ { Ptable __5p ;

# 2095 "/home/claude/cfront-3/src/simpl2.cpp"
__5p = scope ;

# 2095 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__5p != __4r ;__5p = __5p -> next__5table ) { 
# 2096 "/home/claude/cfront-3/src/simpl2.cpp"
int __6i ;
{ { Pname __6n ;

# 2098 "/home/claude/cfront-3/src/simpl2.cpp"
int __2__X195 ;

# 2098 "/home/claude/cfront-3/src/simpl2.cpp"
int __2__X201 ;

# 2097 "/home/claude/cfront-3/src/simpl2.cpp"
__6n = ( (__2__X201 = (__6i = 1 )), ( (((__2__X201 <= 0 )|| (__5p -> free_slot__5table <= __2__X201 ))?(((struct name *)0 )):(__5p -> entries__5table [__2__X201 ]))) )
# 2097 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 2097 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__6n ;__6n = (__6n -> n_tbl_list__4name ?__6n -> n_tbl_list__4name :( (__2__X195 = (++ __6i )), ( (((__2__X195 <= 0 )|| (__5p -> free_slot__5table <= __2__X195 ))?(((struct name *)0 )):(__5p ->
# 2097 "/home/claude/cfront-3/src/simpl2.cpp"
entries__5table [__2__X195 ]))) ) )) { 
# 2098 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __7cln ;
if (__6n -> __O1__4expr.tp == 0 )continue ;

# 2101 "/home/claude/cfront-3/src/simpl2.cpp"
{ int __7dtor ;

# 2101 "/home/claude/cfront-3/src/simpl2.cpp"
__7dtor = 1 ;
if (inllist ){ 
# 2103 "/home/claude/cfront-3/src/simpl2.cpp"
{ { Plist __8nl ;

# 2103 "/home/claude/cfront-3/src/simpl2.cpp"
__8nl = inllist ;

# 2103 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__8nl ;__8nl = __8nl -> l__9name_list ) 
# 2104 "/home/claude/cfront-3/src/simpl2.cpp"
if (__6n == __8nl -> f__9name_list )__7dtor = 0 ;

# 2104 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2104 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2107 "/home/claude/cfront-3/src/simpl2.cpp"
if (__7cln = is_cl_obj__4typeFv ( __6n -> __O1__4expr.tp ) ){ 
# 2108 "/home/claude/cfront-3/src/simpl2.cpp"
Pclass __8cl ;
Pname __8d ;

# 2108 "/home/claude/cfront-3/src/simpl2.cpp"
__8cl = (((struct classdef *)(((struct classdef *)__7cln -> __O1__4expr.tp ))));
__8d = ( __8cl -> c_dtor__8classdef ) ;

# 2111 "/home/claude/cfront-3/src/simpl2.cpp"
if (__8d && __7dtor ){ 
# 2112 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __9dl ;
Pstmt __9dls ;

# 2114 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X196 ;

# 2114 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X197 ;

# 2112 "/home/claude/cfront-3/src/simpl2.cpp"
__9dl = call_dtor__FP4exprN21iT1 ( (struct expr *)__6n , (struct expr *)__8d , (struct expr *)0 , 45 , one ) ;
__9dls = (struct stmt *)( (__0__X196 = 0 ), ( (__2__X197 = __6n -> where__4name ), ( ((__0__X196 || (__0__X196 = (struct estmt *)__nw__4stmtSFUl (
# 2113 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X196 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X196 ), ((unsigned char )72 ), __2__X197 ,
# 2113 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X196 -> __O2__4stmt.e = __9dl )) :0 ), __0__X196 ) ) ) ;
if (__5dd )
# 2115 "/home/claude/cfront-3/src/simpl2.cpp"
__5ddt -> s_list__4stmt = __9dls ;
else 
# 2117 "/home/claude/cfront-3/src/simpl2.cpp"
__5dd = __9dls ;
__5ddt = __9dls ;
}

# 2121 "/home/claude/cfront-3/src/simpl2.cpp"
}
else if (cl_obj_vec ){ 
# 2123 "/home/claude/cfront-3/src/simpl2.cpp"
Pclass __8cl ;

# 2125 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __8d ;

# 2123 "/home/claude/cfront-3/src/simpl2.cpp"
__8cl = (((struct classdef *)(((struct classdef *)cl_obj_vec -> __O1__4expr.tp ))));

# 2125 "/home/claude/cfront-3/src/simpl2.cpp"
__8d = ( __8cl -> c_dtor__8classdef ) ;

# 2127 "/home/claude/cfront-3/src/simpl2.cpp"
if (__8d && __7dtor ){ 
# 2128 "/home/claude/cfront-3/src/simpl2.cpp"
Pfct __9f ;
int __9i ;

# 2128 "/home/claude/cfront-3/src/simpl2.cpp"
__9f = (((struct fct *)(((struct fct *)__8d -> __O1__4expr.tp ))));
__9i = 0 ;
{ { Pname __9nn ;

# 2130 "/home/claude/cfront-3/src/simpl2.cpp"
__9nn = __9f -> f_args__3fct -> __O1__4name.n_list ;

# 2130 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__9nn && __9nn -> __O1__4name.n_list ;__9nn = __9nn -> __O1__4name.n_list ) 
# 2131 "/home/claude/cfront-3/src/simpl2.cpp"
__9i ++ ;
{ Pexpr __9a ;
Pstmt __9dls ;

# 2134 "/home/claude/cfront-3/src/simpl2.cpp"
struct ival *__0__X198 ;

# 2134 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X199 ;

# 2134 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X200 ;

# 2132 "/home/claude/cfront-3/src/simpl2.cpp"
__9a = cdvec__FP4nameP4exprP8classdefT1iN22 ( vec_del_fct , (struct expr *)__6n , __8cl , __8d , 0 , (struct expr *)( (__0__X198 = 0 ), ( ((__0__X198 ||
# 2132 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X198 = (struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival))) ))?( (__0__X198 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X198 ), (unsigned
# 2132 "/home/claude/cfront-3/src/simpl2.cpp"
char )150 , (struct expr *)0 , (struct expr *)0 ) ), (__0__X198 -> __O2__4expr.i1 = ((long long )__9i ))) :0 ), __0__X198 ) )
# 2132 "/home/claude/cfront-3/src/simpl2.cpp"
, (struct expr *)0 ) ;
__9dls = (struct stmt *)( (__0__X199 = 0 ), ( (__2__X200 = __6n -> where__4name ), ( ((__0__X199 || (__0__X199 = (struct estmt *)__nw__4stmtSFUl (
# 2133 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X199 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X199 ), ((unsigned char )72 ), __2__X200 ,
# 2133 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X199 -> __O2__4stmt.e = __9a )) :0 ), __0__X199 ) ) ) ;
if (__5dd )
# 2135 "/home/claude/cfront-3/src/simpl2.cpp"
__5ddt -> s_list__4stmt = __9dls ;
else 
# 2137 "/home/claude/cfront-3/src/simpl2.cpp"
__5dd = __9dls ;
__5ddt = __9dls ;

# 2138 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2138 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2138 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
}

# 2140 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2141 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2141 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2146 "/home/claude/cfront-3/src/simpl2.cpp"
if (__5dd ){ 
# 2147 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4stmtFv ( __5dd ) ;
{ Pstmt __6bs ;

# 2148 "/home/claude/cfront-3/src/simpl2.cpp"
__6bs = __ct__4stmtFUc3locP4stmt ( (struct stmt *)0 , __0this -> base__4node , __0this -> where__4stmt , (struct stmt *)0 ) ;
((*__6bs ))= (*__0this );
__0this -> base__4node = 166 ;
__0this -> s__4stmt = __5dd ;
__0this -> __O2__4stmt.s2 = __6bs ;

# 2152 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2153 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2153 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2154 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2154 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2154 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2154 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
}
break ;

# 2159 "/home/claude/cfront-3/src/simpl2.cpp"
case 20 :
# 2160 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4exprFv ( __0this -> __O2__4stmt.e ) ;
simpl__4stmtFv ( __0this -> s__4stmt ) ;
if (__0this -> __O3__4stmt.else_stmt )simpl__4stmtFv ( __0this -> __O3__4stmt.else_stmt ) ;
break ;

# 2165 "/home/claude/cfront-3/src/simpl2.cpp"
case 16 :
# 2166 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O3__4stmt.for_init )simpl__4stmtFv ( __0this -> __O3__4stmt.for_init ) ;
if (__0this -> __O2__4stmt.e ){ 
# 2169 "/home/claude/cfront-3/src/simpl2.cpp"
if (Ntmp_dtor && need_lift_dtors__FP4expr ( __0this -> __O2__4stmt.e ) ){ 
# 2170 "/home/claude/cfront-3/src/simpl2.cpp"
need_lift = 1 ;
{ Pexpr __4ee ;

# 2171 "/home/claude/cfront-3/src/simpl2.cpp"
__4ee = lift_dtors__FRP4exprP5tableUc ( (Pexpr *)(& __0this -> __O2__4stmt.e ), Ntmp_tbl , __0this -> __O2__4stmt.e -> base__4node ) ;
((*__0this -> __O2__4stmt.e ))= (*__4ee );

# 2172 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
curr_expr = __0this -> __O2__4stmt.e ;
simpl__4exprFv ( __0this -> __O2__4stmt.e ) ;
}

# 2178 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O1__4stmt.e2 ){ 
# 2178 "/home/claude/cfront-3/src/simpl2.cpp"
const void *__2__X202 ;

# 2179 "/home/claude/cfront-3/src/simpl2.cpp"
curr_expr = __0this -> __O1__4stmt.e2 ;
simpl__4exprFv ( __0this -> __O1__4stmt.e2 ) ;
if (__0this -> __O1__4stmt.e2 -> base__4node == 168 )
# 2182 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> __O1__4stmt.e2 -> __O2__4expr.e1 == 0 ){ 
# 2182 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V155 ;

# 2182 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"cannot expand inline void%n called in forE", (const struct ea *)( (__2__X202 =
# 2182 "/home/claude/cfront-3/src/simpl2.cpp"
(const void *)__0this -> __O1__4stmt.e2 -> __O4__4expr.il -> fct_name__5iline ), ( ((& __0__V155 )-> __O1__2ea.p = __2__X202 ), (& __0__V155 )) )
# 2182 "/home/claude/cfront-3/src/simpl2.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 2185 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2186 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __3obl ;
Pstmt __3ocl ;

# 2186 "/home/claude/cfront-3/src/simpl2.cpp"
__3obl = break_del_list ;
__3ocl = continue_del_list ;
break_del_list = 0 ;
continue_del_list = 0 ;
simpl__4stmtFv ( __0this -> s__4stmt ) ;
break_del_list = __3obl ;
continue_del_list = __3ocl ;
}
break ;

# 2196 "/home/claude/cfront-3/src/simpl2.cpp"
case 116 :
# 2197 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__5blockFv ( ((struct block *)(((struct block *)__0this )))) ;
break ;

# 2200 "/home/claude/cfront-3/src/simpl2.cpp"
case 166 :
# 2201 "/home/claude/cfront-3/src/simpl2.cpp"
break ;
} }

# 2206 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__0this -> base__4node != 116 )&& __0this -> memtbl__4stmt ){ 
# 2207 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __2This ;
Pstmt __2t1 ;

# 2210 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __2ss ;
Pname __2cln ;
int __2i ;
Pname __2tn ;

# 2214 "/home/claude/cfront-3/src/simpl2.cpp"
struct table *__0__X203 ;

# 2214 "/home/claude/cfront-3/src/simpl2.cpp"
int __2__X204 ;

# 2214 "/home/claude/cfront-3/src/simpl2.cpp"
struct table *__0__X216 ;

# 2214 "/home/claude/cfront-3/src/simpl2.cpp"
int __2__X217 ;

# 2207 "/home/claude/cfront-3/src/simpl2.cpp"
__2This = __0this ;
__2t1 = (__0this -> s_list__4stmt ?simpl__4stmtFv ( __0this -> s_list__4stmt ) :(((struct stmt *)0 )));

# 2210 "/home/claude/cfront-3/src/simpl2.cpp"
__2ss = 0 ;

# 2213 "/home/claude/cfront-3/src/simpl2.cpp"
__2tn = ( (__0__X216 = __0this -> memtbl__4stmt ), ( (__2__X217 = (__2i = 1 )), ( (((__2__X217 <= 0 )|| (__0__X216 -> free_slot__5table <=
# 2213 "/home/claude/cfront-3/src/simpl2.cpp"
__2__X217 ))?(((struct name *)0 )):(__0__X216 -> entries__5table [__2__X217 ]))) ) ) ;
for(;__2tn ;__2tn = (__2tn -> n_tbl_list__4name ?__2tn -> n_tbl_list__4name :( (__0__X203 = __0this -> memtbl__4stmt ), ( (__2__X204 = (++ __2i )), ( (((__2__X204 <= 0 )||
# 2214 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X203 -> free_slot__5table <= __2__X204 ))?(((struct name *)0 )):(__0__X203 -> entries__5table [__2__X204 ]))) ) ) )) { 
# 2216 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2cln = is_cl_obj__4typeFv ( __2tn -> __O1__4expr.tp )
# 2216 "/home/claude/cfront-3/src/simpl2.cpp"
){ 
# 2217 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __4d ;

# 2218 "/home/claude/cfront-3/src/simpl2.cpp"
struct classdef *__0__X207 ;

# 2217 "/home/claude/cfront-3/src/simpl2.cpp"
__4d = ( (__0__X207 = (((struct classdef *)(((struct classdef *)__2cln -> __O1__4expr.tp ))))), ( __0__X207 -> c_dtor__8classdef ) ) ;
if (__4d ){ 
# 2219 "/home/claude/cfront-3/src/simpl2.cpp"
if ((need_lift && is_probably_temp__FPCc ( __2tn -> __O2__4expr.string ) )&& look__5tableFPCcUc ( tmp_tbl , __2tn -> __O2__4expr.string , (unsigned char
# 2219 "/home/claude/cfront-3/src/simpl2.cpp"
)0 ) )
# 2222 "/home/claude/cfront-3/src/simpl2.cpp"
continue ;
{ Pexpr __5dl ;

# 2223 "/home/claude/cfront-3/src/simpl2.cpp"
__5dl = call_dtor__FP4exprN21iT1 ( (struct expr *)__2tn , (struct expr *)__4d , (struct expr *)0 , 45 , one ) ;
check_visibility__FP4nameT1P8classdefP5tableT1 ( __4d , (struct name *)0 , ((struct classdef *)(((struct classdef *)__2cln -> __O1__4expr.tp ))), cc -> ftbl__11dcl_context , cc -> nof__11dcl_context ) ;
if (pdlist && ((strncmp ( (const char *)"__R", __2tn -> __O2__4expr.string , (unsigned long
# 2225 "/home/claude/cfront-3/src/simpl2.cpp"
)3 ) == 0 )|| (strncmp ( (const char *)"__V", __2tn -> __O2__4expr.string , (unsigned
# 2225 "/home/claude/cfront-3/src/simpl2.cpp"
long )3 ) == 0 )))
# 2229 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2230 "/home/claude/cfront-3/src/simpl2.cpp"
int __6len ;

# 2230 "/home/claude/cfront-3/src/simpl2.cpp"
__6len = (strlen ( __2tn -> __O2__4expr.string ) + 1 );
{ { struct con_dtor *__6pcd ;

# 2231 "/home/claude/cfront-3/src/simpl2.cpp"
__6pcd = pdlist ;

# 2231 "/home/claude/cfront-3/src/simpl2.cpp"
for(;__6pcd ;__6pcd = __6pcd -> next__8con_dtor ) { 
# 2232 "/home/claude/cfront-3/src/simpl2.cpp"
if (strncmp ( __2tn -> __O2__4expr.string , __6pcd -> tn__8con_dtor -> __O2__4expr.string , (unsigned long )__6len )
# 2232 "/home/claude/cfront-3/src/simpl2.cpp"
== 0 ){ 
# 2233 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __8e ;

# 2233 "/home/claude/cfront-3/src/simpl2.cpp"
__8e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __6pcd -> condition__8con_dtor , zero ) ;
__8e -> __O1__4expr.tp = (struct type *)int_type ;
{ Pexpr __8ee ;

# 2235 "/home/claude/cfront-3/src/simpl2.cpp"
__8ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __8e , __5dl ) ;
__8ee -> __O1__4expr.tp = (struct type *)int_type ;
__8ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __8ee , zero ) ;
__8ee -> __O1__4expr.tp = (struct type *)int_type ;
{ Pexpr __8qe ;

# 2239 "/home/claude/cfront-3/src/simpl2.cpp"
__8qe = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , __8ee , zero ) ;
__8qe -> __O4__4expr.cond = __6pcd -> condition__8con_dtor ;
__8qe -> __O1__4expr.tp = (struct type *)int_type ;
__5dl = __8qe ;
break ;

# 2243 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2243 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
}

# 2245 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2245 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
{ Pstmt __5dls ;

# 2248 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X205 ;

# 2248 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X206 ;

# 2247 "/home/claude/cfront-3/src/simpl2.cpp"
__5dls = (struct stmt *)( (__0__X205 = 0 ), ( (__2__X206 = __2tn -> where__4name ), ( ((__0__X205 || (__0__X205 = (struct estmt *)__nw__4stmtSFUl (
# 2247 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X205 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X205 ), ((unsigned char )72 ), __2__X206 ,
# 2247 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X205 -> __O2__4stmt.e = __5dl )) :0 ), __0__X205 ) ) ) ;
__5dls -> s_list__4stmt = __2ss ;
__2ss = __5dls ;

# 2249 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2249 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
}
}

# 2254 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2ss ){ 
# 2255 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __3t2 ;

# 2255 "/home/claude/cfront-3/src/simpl2.cpp"
__3t2 = simpl__4stmtFv ( __2ss ) ;

# 2257 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__0this -> base__4node ){ 
# 2258 "/home/claude/cfront-3/src/simpl2.cpp"
case 20 :
# 2259 "/home/claude/cfront-3/src/simpl2.cpp"
case 39 :
# 2260 "/home/claude/cfront-3/src/simpl2.cpp"
case 10 :
# 2261 "/home/claude/cfront-3/src/simpl2.cpp"
case 33 :
# 2262 "/home/claude/cfront-3/src/simpl2.cpp"
temp_in_cond__FP4exprP4stmtP5table ( __0this -> __O2__4stmt.e , __2ss , __0this -> memtbl__4stmt ) ;
# 2262 "/home/claude/cfront-3/src/simpl2.cpp"

# 2263 "/home/claude/cfront-3/src/simpl2.cpp"
break ;

# 2265 "/home/claude/cfront-3/src/simpl2.cpp"
case 166 :
# 2266 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pstmt __5ts ;

# 2266 "/home/claude/cfront-3/src/simpl2.cpp"
__5ts = __0this -> __O2__4stmt.s2 ;
while (__5ts -> base__4node == 166 )__5ts = __5ts -> __O2__4stmt.s2 ;
if (__5ts -> base__4node == 28 ){ 
# 2269 "/home/claude/cfront-3/src/simpl2.cpp"
__2This = __5ts ;
goto retu ;
}
goto def ;
}
case 28 :
# 2275 "/home/claude/cfront-3/src/simpl2.cpp"
retu :
# 2276 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2277 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2This -> __O2__4stmt.e == 0 ){ 
# 2279 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __6rs ;

# 2280 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X208 ;

# 2280 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X209 ;

# 2279 "/home/claude/cfront-3/src/simpl2.cpp"
__6rs = (struct stmt *)( (__0__X208 = 0 ), ( (__2__X209 = __2This -> where__4stmt ), ( ((__0__X208 || (__0__X208 = (struct estmt *)__nw__4stmtSFUl (
# 2279 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X208 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X208 ), ((unsigned char )28 ), __2__X209 ,
# 2279 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X208 -> __O2__4stmt.e = ((struct expr *)0 ))) :0 ), __0__X208 ) ) ) ;

# 2281 "/home/claude/cfront-3/src/simpl2.cpp"
__6rs -> __O1__4stmt.ret_tp = __2This -> __O1__4stmt.ret_tp ;
__2This -> base__4node = 166 ;
__2This -> s__4stmt = __2ss ;
__2This -> __O2__4stmt.s2 = __6rs ;

# 2286 "/home/claude/cfront-3/src/simpl2.cpp"
return (__2t1 ?__2t1 :__6rs );
}

# 2289 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pname __5cln ;

# 2289 "/home/claude/cfront-3/src/simpl2.cpp"
__5cln = is_cl_obj__4typeFv ( __2This -> __O2__4stmt.e -> __O1__4expr.tp ) ;

# 2291 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__5cln == 0 )|| (has_oper__8classdefFUc ( ((struct classdef *)(((struct classdef *)__5cln -> __O1__4expr.tp ))), (unsigned char )70 ) == 0 ))
# 2292 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2295 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __6rv ;
# 2295 "/home/claude/cfront-3/src/simpl2.cpp"
__6rv = __ct__4nameFPCc ( (struct name *)0 , (const char *)"_rresult") ;

# 2298 "/home/claude/cfront-3/src/simpl2.cpp"
__6rv -> __O1__4expr.tp = unconst_type__FP4type ( __2This -> __O1__4stmt.ret_tp ) ;

# 2300 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2This -> memtbl__4stmt == 0 )__2This -> memtbl__4stmt = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )4 , (struct table *)0 , (struct name *)0 )
# 2300 "/home/claude/cfront-3/src/simpl2.cpp"
;
{ Pname __6n ;

# 2301 "/home/claude/cfront-3/src/simpl2.cpp"
__6n = dcl__4nameFP5tableUc ( __6rv , __2This -> memtbl__4stmt , (unsigned char )136 ) ;
__6n -> where__4name = no_where ;
__6n -> n_scope__4name = 108 ;
__6n -> n_assigned_to__4name = 1 ;
( (__6rv ?(((void )(__6rv ?(((void )( ( ((((struct expr *)__6rv ))?(((void )((((struct expr *)__6rv ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 2305 "/home/claude/cfront-3/src/simpl2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__6rv , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
{ Pstmt __6rs ;

# 2307 "/home/claude/cfront-3/src/simpl2.cpp"
struct estmt *__0__X214 ;

# 2307 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X215 ;

# 2306 "/home/claude/cfront-3/src/simpl2.cpp"
__6rs = (struct stmt *)( (__0__X214 = 0 ), ( (__2__X215 = __2This -> where__4stmt ), ( ((__0__X214 || (__0__X214 = (struct estmt *)__nw__4stmtSFUl (
# 2306 "/home/claude/cfront-3/src/simpl2.cpp"
(size_t )(sizeof (struct estmt))) ))?( (__0__X214 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X214 ), ((unsigned char )28 ), __2__X215 ,
# 2306 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)0 )) ), (__0__X214 -> __O2__4stmt.e = ((struct expr *)__6n ))) :0 ), __0__X214 ) ) ) ;
__6rs -> __O1__4stmt.ret_tp = __2This -> __O1__4stmt.ret_tp ;
__2This -> base__4node = 72 ;
__2This -> __O2__4stmt.e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__6n , __2This -> __O2__4stmt.e ) ;
__2This -> __O2__4stmt.e -> __O1__4expr.tp = __6n -> __O1__4expr.tp ;
{ Pstmt __6ps ;

# 2312 "/home/claude/cfront-3/src/simpl2.cpp"
struct pair *__0__X210 ;

# 2312 "/home/claude/cfront-3/src/simpl2.cpp"
struct loc __2__X211 ;

# 2312 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X212 ;

# 2312 "/home/claude/cfront-3/src/simpl2.cpp"
struct stmt *__2__X213 ;

# 2311 "/home/claude/cfront-3/src/simpl2.cpp"
__6ps = (struct stmt *)( (__0__X210 = 0 ), ( (__2__X211 = __2This -> where__4stmt ), ( (__2__X212 = __2ss ), ( (__2__X213 =
# 2311 "/home/claude/cfront-3/src/simpl2.cpp"
__6rs ), ( ((__0__X210 || (__0__X210 = (struct pair *)__nw__4stmtSFUl ( (size_t )(sizeof (struct pair))) ))?( (__0__X210 = (struct pair *)__ct__4stmtFUc3locP4stmt (
# 2311 "/home/claude/cfront-3/src/simpl2.cpp"
((struct stmt *)__0__X210 ), (unsigned char )166 , __2__X211 , __2__X212 ) ), (__0__X210 -> __O2__4stmt.s2 = __2__X213 )) :0 ), __0__X210 ) )
# 2311 "/home/claude/cfront-3/src/simpl2.cpp"
) ) ) ;
__6ps -> s_list__4stmt = __2This -> s_list__4stmt ;
__2This -> s_list__4stmt = __6ps ;

# 2315 "/home/claude/cfront-3/src/simpl2.cpp"
return (__2t1 ?__2t1 :__6rs );

# 2315 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2315 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2315 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2316 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
break ;

# 2320 "/home/claude/cfront-3/src/simpl2.cpp"
case 16 :
# 2322 "/home/claude/cfront-3/src/simpl2.cpp"
break ;

# 2324 "/home/claude/cfront-3/src/simpl2.cpp"
case 72 :
# 2325 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2t1 ){ 
# 2327 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __5ttt ;

# 2327 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __5tt ;

# 2327 "/home/claude/cfront-3/src/simpl2.cpp"
__5tt = __0this ;
for(;(__5ttt = __5tt -> s_list__4stmt )&& (__5ttt -> base__4node == 72 );__5tt = __5ttt ) ;
__3t2 -> s_list__4stmt = __5ttt ;
__5tt -> s_list__4stmt = __2ss ;

# 2332 "/home/claude/cfront-3/src/simpl2.cpp"
return ((__2t1 != __5tt )?__2t1 :__3t2 );
}
default :
# 2335 "/home/claude/cfront-3/src/simpl2.cpp"
def :
# 2337 "/home/claude/cfront-3/src/simpl2.cpp"
if (__2t1 ){ 
# 2338 "/home/claude/cfront-3/src/simpl2.cpp"
__3t2 -> s_list__4stmt = __0this -> s_list__4stmt ;
__0this -> s_list__4stmt = __2ss ;

# 2341 "/home/claude/cfront-3/src/simpl2.cpp"
return __2t1 ;
}
__0this -> s_list__4stmt = __2ss ;

# 2345 "/home/claude/cfront-3/src/simpl2.cpp"
return __3t2 ;
}
}

# 2349 "/home/claude/cfront-3/src/simpl2.cpp"
return (__2t1 ?__2t1 :__2This );
}

# 2353 "/home/claude/cfront-3/src/simpl2.cpp"
return (__0this -> s_list__4stmt ?simpl__4stmtFv ( __0this -> s_list__4stmt ) :__0this );
}

# 2356 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt copy__4stmtFv (register struct stmt *__0this )
# 2359 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2360 "/home/claude/cfront-3/src/simpl2.cpp"
Pstmt __1ns ;

# 2360 "/home/claude/cfront-3/src/simpl2.cpp"
__1ns = __ct__4stmtFUc3locP4stmt ( (struct stmt *)0 , (unsigned char )0 , curloc , (struct stmt *)0 ) ;

# 2362 "/home/claude/cfront-3/src/simpl2.cpp"
((*__1ns ))= (*__0this );
if (__0this -> s__4stmt )__1ns -> s__4stmt = copy__4stmtFv ( __0this -> s__4stmt ) ;
if (__0this -> s_list__4stmt )__1ns -> s_list__4stmt = copy__4stmtFv ( __0this -> s_list__4stmt ) ;

# 2366 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__0this -> base__4node ){ 
# 2367 "/home/claude/cfront-3/src/simpl2.cpp"
case 166 :
# 2368 "/home/claude/cfront-3/src/simpl2.cpp"
__1ns -> __O2__4stmt.s2 = copy__4stmtFv ( __0this -> __O2__4stmt.s2 ) ;
break ;
}

# 2372 "/home/claude/cfront-3/src/simpl2.cpp"
return __1ns ;
}

# 2375 "/home/claude/cfront-3/src/simpl2.cpp"
Pname overFound = 0 ;

# 820 "/home/claude/cfront-3/src/cfront.h"

# 120 "/home/claude/cfront-3/src/cfront.h"
extern const char *oper_name__FUc (TOK );

# 537 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr find_name__FP4nameP8classdefP5tableiT1 (Pname , Pclass , Ptable , int , Pname );

# 832 "/home/claude/cfront-3/src/cfront.h"

# 802 "/home/claude/cfront-3/src/cfront.h"
Ptype call_fct__4exprFP5table (struct expr *__0this , Ptable );

# 2378 "/home/claude/cfront-3/src/simpl2.cpp"
static Pexpr mk_new_with_args__FP4exprP4typeP8classdefT1 (Pexpr __1pe , Ptype __1tt , Pclass __1cl , Pexpr __1vec )
# 2379 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2380 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1p ;
Pexpr __1args ;

# 2384 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1ce ;

# 2385 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X218 ;

# 2381 "/home/claude/cfront-3/src/simpl2.cpp"
__1args = __1pe -> __O3__4expr.e2 ;

# 2385 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1vec )
# 2386 "/home/claude/cfront-3/src/simpl2.cpp"
__1ce = __1vec ;
else __1ce = (struct expr *)( (__0__X218 = 0 ), ( ((__0__X218 || (__0__X218 = (struct texpr *)__nw__4exprSFUl ( (size_t)(sizeof
# 2387 "/home/claude/cfront-3/src/simpl2.cpp"
(struct texpr))) ))?( (__0__X218 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X218 ), ((unsigned char )30 ), ((struct expr *)0 ), (struct expr *)0 )
# 2387 "/home/claude/cfront-3/src/simpl2.cpp"
), (__0__X218 -> __O4__4expr.tp2 = __1tt )) :0 ), __0__X218 ) ) ;

# 2389 "/home/claude/cfront-3/src/simpl2.cpp"
((void )tsizeof__4typeFi ( __1tt , 0 ) );
__1ce -> __O1__4expr.tp = size_t_type ;
__1args = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1ce , __1args ) ;
{ const char *__1s ;
Pname __1n ;

# 2394 "/home/claude/cfront-3/src/simpl2.cpp"
struct call *__0__X219 ;

# 2394 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X220 ;

# 2394 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X221 ;

# 2392 "/home/claude/cfront-3/src/simpl2.cpp"
__1s = oper_name__FUc ( (unsigned char )23 ) ;
__1n = __ct__4nameFPCc ( (struct name *)0 , __1s ) ;
if ((__1pe -> base__4node == 184 )|| __1vec )
# 2395 "/home/claude/cfront-3/src/simpl2.cpp"
__1p = (struct expr *)look__5tableFPCcUc ( gtbl , __1s , (unsigned char )0 ) ;
else 
# 2397 "/home/claude/cfront-3/src/simpl2.cpp"
__1p = find_name__FP4nameP8classdefP5tableiT1 ( __1n , __1cl , scope , 109 , curr_fct ) ;
__1p = (struct expr *)( (__0__X219 = 0 ), ( (__2__X220 = __1p ), ( (__2__X221 = __1args ), ( ((__0__X219 || (__0__X219 =
# 2398 "/home/claude/cfront-3/src/simpl2.cpp"
(struct call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X219 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X219 ), (unsigned char )109 ,
# 2398 "/home/claude/cfront-3/src/simpl2.cpp"
__2__X220 , __2__X221 ) ):0 ), __0__X219 ) ) ) ) ;
overFound = 0 ;
((void )call_fct__4exprFP5table ( __1p , __1cl -> memtbl__8classdef ) );
if ((overFound && (overFound -> n_scope__4name != 14 ))&& (overFound -> n_scope__4name != 31 ))
# 2407 "/home/claude/cfront-3/src/simpl2.cpp"
check_visibility__FP4nameT1P8classdefP5tableT1 ( overFound , (struct name *)0 , (((struct fct *)(((struct fct *)overFound ->
# 2407 "/home/claude/cfront-3/src/simpl2.cpp"
__O1__4expr.tp ))))-> memof__3fct , cc -> ftbl__11dcl_context , cc -> nof__11dcl_context ) ;
overFound = 0 ;
return __1p ;

# 2409 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 466 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 469 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 804 "/home/claude/cfront-3/src/cfront.h"
Pexpr contents__4exprFv (struct expr *__0this );

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 2412 "/home/claude/cfront-3/src/simpl2.cpp"
void simpl_new__4exprFv (register struct expr *__0this )
# 2416 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2417 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __1cln ;
Pname __1ctor ;
int __1sz ;

# 2421 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __1var_expr ;
Pexpr __1const_expr ;
Ptype __1tt ;
Pexpr __1arg ;
Pexpr __1szof ;
Pname __1nf ;
Pexpr __1init ;

# 2419 "/home/claude/cfront-3/src/simpl2.cpp"
__1sz = 1 ;

# 2421 "/home/claude/cfront-3/src/simpl2.cpp"
__1var_expr = 0 ;
__1const_expr = 0 ;
__1tt = __0this -> __O4__4expr.tp2 ;

# 2427 "/home/claude/cfront-3/src/simpl2.cpp"
__1init = __0this -> __O2__4expr.e1 ;

# 2429 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1init && __1init -> base__4node )__1init = 0 ;

# 2432 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__1cln = is_cl_obj__4typeFv ( __1tt ) )&& (__1init == 0 )){ 
# 2433 "/home/claude/cfront-3/src/simpl2.cpp"
Pclass __2cl ;
Pexpr __2p ;

# 2433 "/home/claude/cfront-3/src/simpl2.cpp"
__2cl = (((struct classdef *)(((struct classdef *)__1cln -> __O1__4expr.tp ))));

# 2435 "/home/claude/cfront-3/src/simpl2.cpp"
__1ctor = ( __2cl -> c_ctor__8classdef ) ;

# 2437 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__0this -> __O3__4expr.e2 || (__1ctor == 0 ))|| (__1ctor -> __O4__4expr.n_table != __2cl -> memtbl__8classdef ))|| ((__0this -> base__4node == 184 )&& has_oper__8classdefFUc ( __2cl ,
# 2437 "/home/claude/cfront-3/src/simpl2.cpp"
(unsigned char )23 ) ))
# 2441 "/home/claude/cfront-3/src/simpl2.cpp"
__2p = mk_new_with_args__FP4exprP4typeP8classdefT1 ( __0this , __1tt , __2cl , (struct expr *)0 ) ;
else { 
# 2443 "/home/claude/cfront-3/src/simpl2.cpp"
__2p = zero ;

# 2445 "/home/claude/cfront-3/src/simpl2.cpp"
((void )mk_new_with_args__FP4exprP4typeP8classdefT1 ( __0this , __1tt , __2cl , (struct expr *)0 ) );
}

# 2448 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1ctor ){ 
# 2449 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __3c ;
Ptype __3ttt ;

# 2449 "/home/claude/cfront-3/src/simpl2.cpp"
__3c = __0this -> __O2__4expr.e1 ;
__3ttt = __0this -> __O1__4expr.tp ;
__3c -> __O2__4expr.e1 -> __O2__4expr.e1 = __2p ;
simpl__4exprFv ( __3c ) ;
((*__0this ))= (*__3c );
__0this -> __O1__4expr.tp = __3ttt ;
( (__3c ?(((void )(__3c ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__3c , (size_t )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 2455 "/home/claude/cfront-3/src/simpl2.cpp"
;
}
else { 
# 2458 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> base__4node = 191 ;
__0this -> __O4__4expr.tp2 = __0this -> __O1__4expr.tp ;
__0this -> __O2__4expr.e1 = __2p ;
__0this -> __O3__4expr.e2 = 0 ;
simpl__4exprFv ( __0this ) ;
}
return ;
}
else 
# 2465 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1cln ){ 
# 2466 "/home/claude/cfront-3/src/simpl2.cpp"
Pclass __2cl ;

# 2466 "/home/claude/cfront-3/src/simpl2.cpp"
__2cl = (((struct classdef *)(((struct classdef *)__1cln -> __O1__4expr.tp ))));

# 2468 "/home/claude/cfront-3/src/simpl2.cpp"
((void )mk_new_with_args__FP4exprP4typeP8classdefT1 ( __0this , __1tt , __2cl , (struct expr *)0 ) );
}

# 2471 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pclass __1covn ;

# 2471 "/home/claude/cfront-3/src/simpl2.cpp"
__1covn = 0 ;
if (cl_obj_vec ){ 
# 2473 "/home/claude/cfront-3/src/simpl2.cpp"
__1covn = (((struct classdef *)(((struct classdef *)cl_obj_vec -> __O1__4expr.tp ))));
__1ctor = has_ictor__8classdefFv ( __1covn ) ;
if (__1ctor == 0 ){ 
# 2475 "/home/claude/cfront-3/src/simpl2.cpp"
const void *__2__X223 ;

# 2476 "/home/claude/cfront-3/src/simpl2.cpp"
if (( __1covn -> c_ctor__8classdef ) ){ 
# 2476 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V222 ;

# 2476 "/home/claude/cfront-3/src/simpl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"new %s[], no defaultK", (const struct ea *)( (__2__X223 = (const void
# 2476 "/home/claude/cfront-3/src/simpl2.cpp"
*)__1covn -> string__8classdef ), ( ((& __0__V222 )-> __O1__2ea.p = __2__X223 ), (& __0__V222 )) ) , (const struct ea *)ea0 ,
# 2476 "/home/claude/cfront-3/src/simpl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (( __1covn -> c_dtor__8classdef ) == 0 )cl_obj_vec = 0 ;
}
}

# 2481 "/home/claude/cfront-3/src/simpl2.cpp"
xxx :
# 2483 "/home/claude/cfront-3/src/simpl2.cpp"
switch (__1tt -> base__4node ){ 
# 2484 "/home/claude/cfront-3/src/simpl2.cpp"
case 97 :
# 2485 "/home/claude/cfront-3/src/simpl2.cpp"
__1tt = (((struct basetype *)(((struct basetype *)__1tt ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto xxx ;

# 2488 "/home/claude/cfront-3/src/simpl2.cpp"
default :
# 2489 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2490 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __3cov ;

# 2491 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X224 ;

# 2490 "/home/claude/cfront-3/src/simpl2.cpp"
__3cov = cl_obj_vec ;
((void )tsizeof__4typeFi ( __1tt , 0 ) );
cl_obj_vec = __3cov ;
__1szof = (struct expr *)( (__0__X224 = 0 ), ( ((__0__X224 || (__0__X224 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 2493 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X224 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X224 ), ((unsigned char )30 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 2493 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X224 -> __O4__4expr.tp2 = __1tt )) :0 ), __0__X224 ) ) ;
__1szof -> __O1__4expr.tp = (struct type *)uint_type ;
break ;
}

# 2498 "/home/claude/cfront-3/src/simpl2.cpp"
case 110 :
# 2499 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pvec __3v ;

# 2499 "/home/claude/cfront-3/src/simpl2.cpp"
__3v = (((struct vec *)(((struct vec *)__1tt ))));

# 2501 "/home/claude/cfront-3/src/simpl2.cpp"
if (__3v -> size__3vec )
# 2502 "/home/claude/cfront-3/src/simpl2.cpp"
__1sz *= __3v -> size__3vec ;
else if (__3v -> dim__3vec )
# 2504 "/home/claude/cfront-3/src/simpl2.cpp"
__1var_expr = __3v -> dim__3vec ;
else 
# 2506 "/home/claude/cfront-3/src/simpl2.cpp"
__1sz = 0 ;
__1tt = __3v -> typ__5pvtyp ;
goto xxx ;
}
}

# 2512 "/home/claude/cfront-3/src/simpl2.cpp"
if (cl_obj_vec ){ 
# 2512 "/home/claude/cfront-3/src/simpl2.cpp"
struct ival *__0__X225 ;

# 2513 "/home/claude/cfront-3/src/simpl2.cpp"
__1const_expr = (struct expr *)( (__0__X225 = 0 ), ( ((__0__X225 || (__0__X225 = (struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival)))
# 2513 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X225 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X225 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 ) ),
# 2513 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X225 -> __O2__4expr.i1 = ((long long )__1sz ))) :0 ), __0__X225 ) ) ;
{ Pexpr __2noe ;

# 2514 "/home/claude/cfront-3/src/simpl2.cpp"
__2noe = (__1var_expr ?((__1sz != 1 )?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )50 , __1const_expr , __1var_expr ) :__1var_expr ):__1const_expr );
__1const_expr = __1szof ;
__1const_expr -> __O1__4expr.tp = (struct type *)uint_type ;
__0this -> base__4node = 109 ;
{ Pname __2vctor ;

# 2518 "/home/claude/cfront-3/src/simpl2.cpp"
__2vctor = ( __1covn -> c_vtor__8classdef ) ;
if (__1ctor ){ 
# 2519 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X226 ;

# 2519 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X227 ;

# 2520 "/home/claude/cfront-3/src/simpl2.cpp"
__1arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (struct expr *)( (__0__X226 = 0 ), ( (__2__X227 = Pvoid_type ),
# 2520 "/home/claude/cfront-3/src/simpl2.cpp"
( ((__0__X226 || (__0__X226 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X226 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct
# 2520 "/home/claude/cfront-3/src/simpl2.cpp"
expr *)__0__X226 ), ((unsigned char )191 ), ((struct expr *)(__2vctor ?__2vctor :__1ctor )), (struct expr *)0 ) ), (__0__X226 -> __O4__4expr.tp2 = __2__X227 )) :0 ), __0__X226 )
# 2520 "/home/claude/cfront-3/src/simpl2.cpp"
) ) , (struct expr *)0 ) ;
lval__4exprFUc ( (struct expr *)__1ctor , (unsigned char )112 ) ;
}
else __1arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , (struct expr *)0 ) ;

# 2525 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pexpr __2sub ;

# 2526 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X228 ;

# 2526 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X229 ;

# 2526 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X230 ;

# 2525 "/home/claude/cfront-3/src/simpl2.cpp"
__2sub = 0 ;
if ((__0this -> __O3__4expr.e2 && __0this -> __O3__4expr.e2 -> __O2__4expr.e1 )&& __0this -> __O3__4expr.e2 -> __O2__4expr.e1 -> __O1__4expr.tp )
# 2528 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2529 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __3vec_sz ;

# 2529 "/home/claude/cfront-3/src/simpl2.cpp"
__3vec_sz = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )50 , __2noe , __1const_expr ) ;
__2sub = mk_new_with_args__FP4exprP4typeP8classdefT1 ( __0this , __1tt , __1covn , __3vec_sz ) ;
}
__1arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1const_expr , __1arg ) ;
__1arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __2noe , __1arg ) ;

# 2536 "/home/claude/cfront-3/src/simpl2.cpp"
__1arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __0this -> __O3__4expr.e2 ?(__2sub ?__2sub :__0this -> __O3__4expr.e2 ):(((struct expr *)( (__0__X228 = 0 ), (
# 2536 "/home/claude/cfront-3/src/simpl2.cpp"
(__2__X229 = Pvoid_type ), ( (__2__X230 = zero ), ( ((__0__X228 || (__0__X228 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 2536 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X228 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X228 ), ((unsigned char )191 ), __2__X230 , (struct expr *)0 ) ), (__0__X228 ->
# 2536 "/home/claude/cfront-3/src/simpl2.cpp"
__O4__4expr.tp2 = __2__X229 )) :0 ), __0__X228 ) ) ) ) )), __1arg ) ;
__0this -> base__4node = 191 ;
__0this -> __O4__4expr.tp2 = __0this -> __O1__4expr.tp ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , (struct expr *)vec_new_fct , __1arg ) ;
__0this -> __O2__4expr.e1 -> __O4__4expr.fct_name = vec_new_fct ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = (((struct fct *)(((struct fct *)vec_new_fct -> __O1__4expr.tp ))))-> returns__3fct ;
simpl__4exprFv ( __0this ) ;
return ;

# 2543 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2543 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2543 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2548 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1sz == 1 )
# 2549 "/home/claude/cfront-3/src/simpl2.cpp"
__1arg = (__1var_expr ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )50 , __1szof , __1var_expr ) :__1szof );
else { 
# 2550 "/home/claude/cfront-3/src/simpl2.cpp"
struct ival *__0__X231 ;

# 2551 "/home/claude/cfront-3/src/simpl2.cpp"
__1const_expr = (struct expr *)( (__0__X231 = 0 ), ( ((__0__X231 || (__0__X231 = (struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival)))
# 2551 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X231 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X231 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 ) ),
# 2551 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X231 -> __O2__4expr.i1 = ((long long )__1sz ))) :0 ), __0__X231 ) ) ;
__1const_expr -> __O1__4expr.tp = (struct type *)uint_type ;
__1const_expr = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )50 , __1const_expr , __1szof ) ;
__1const_expr -> __O1__4expr.tp = (struct type *)uint_type ;
__1arg = (__1var_expr ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )50 , __1const_expr , __1var_expr ) :__1const_expr );
}

# 2558 "/home/claude/cfront-3/src/simpl2.cpp"
__1arg -> __O1__4expr.tp = (struct type *)uint_type ;
__0this -> base__4node = 191 ;
__0this -> __O4__4expr.tp2 = __0this -> __O1__4expr.tp ;
__1arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1arg , __0this -> __O3__4expr.e2 ) ;
{ Pname __1nn ;

# 2562 "/home/claude/cfront-3/src/simpl2.cpp"
__1nn = 0 ;
if ((__1cln && (__1nn = has_oper__8classdefFUc ( ((struct classdef *)(((struct classdef *)__1cln -> __O1__4expr.tp ))), (unsigned char )23 ) ))&& __1nn ){ 
# 2564 "/home/claude/cfront-3/src/simpl2.cpp"
__1nf =
# 2564 "/home/claude/cfront-3/src/simpl2.cpp"
(((struct name *)(((struct name *)find_name__FP4nameP8classdefP5tableiT1 ( __1nn , ((struct classdef *)(((struct classdef *)__1cln -> __O1__4expr.tp ))), scope , 109 , curr_fct ) ))));
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , (struct expr *)__1nf , __1arg ) ;
((void )call_fct__4exprFP5table ( __0this -> __O2__4expr.e1 , (((struct classdef *)(((struct classdef *)__1cln -> __O1__4expr.tp ))))-> memtbl__8classdef ) );
}
else 
# 2567 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2568 "/home/claude/cfront-3/src/simpl2.cpp"
__1nf = look__5tableFPCcUc ( gtbl , oper_name__FUc ( (unsigned char )23 ) , (unsigned char )0 ) ;
# 2568 "/home/claude/cfront-3/src/simpl2.cpp"

# 2569 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , (struct expr *)__1nf , __1arg ) ;
((void )call_fct__4exprFP5table ( __0this -> __O2__4expr.e1 , gtbl ) );
}
simpl__4exprFv ( __0this ) ;

# 2574 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1init ){ 
# 2575 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __2p ;
Pexpr __2ee ;

# 2575 "/home/claude/cfront-3/src/simpl2.cpp"
__2p = __1init -> __O2__4expr.e1 ;
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )0 , (struct expr *)0 , (struct expr *)0 ) ;
((*__2ee ))= (*__0this );
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __2p , __2ee ) ;
__1init -> base__4node = 70 ;
__1init -> __O2__4expr.e1 = contents__4exprFv ( __2p ) ;
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __2ee , __1init ) ;
simpl__4exprFv ( __2ee ) ;
__0this -> base__4node = 71 ;
__0this -> __O2__4expr.e1 = __2ee ;
__0this -> __O3__4expr.e2 = __2p ;
}

# 2586 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2586 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 467 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 832 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 848 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 342 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr__4typeFv (struct type *__0this );

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 820 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 2589 "/home/claude/cfront-3/src/simpl2.cpp"
void simpl_delete__4exprFv (register struct expr *__0this )
# 2596 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2597 "/home/claude/cfront-3/src/simpl2.cpp"
Ptype __1tt ;

# 2597 "/home/claude/cfront-3/src/simpl2.cpp"
__1tt = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
for(;__1tt -> base__4node == 97 ;__1tt = (((struct basetype *)(((struct basetype *)__1tt ))))-> b_name__8basetype -> __O1__4expr.tp ) ;
__1tt = (((struct ptr *)(((struct ptr *)__1tt ))))-> typ__5pvtyp ;

# 2601 "/home/claude/cfront-3/src/simpl2.cpp"
{ Pname __1cln ;

# 2604 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __1n ;
Pclass __1cl ;

# 2601 "/home/claude/cfront-3/src/simpl2.cpp"
__1cln = is_cl_obj__4typeFv ( __1tt ) ;
if (cl_obj_vec )
# 2603 "/home/claude/cfront-3/src/simpl2.cpp"
__1cln = cl_obj_vec ;
;

# 2604 "/home/claude/cfront-3/src/simpl2.cpp"
;

# 2607 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1cln ){ 
# 2608 "/home/claude/cfront-3/src/simpl2.cpp"
__1cl = (((struct classdef *)(((struct classdef *)__1cln -> __O1__4expr.tp ))));
if ((__1cl -> defined__4type & 01 )== 0 ){ 
# 2609 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V232 ;

# 2609 "/home/claude/cfront-3/src/simpl2.cpp"
struct ea __0__V233 ;

# 2609 "/home/claude/cfront-3/src/simpl2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"delete%t (%t not defined)", (const struct ea *)( ((&
# 2609 "/home/claude/cfront-3/src/simpl2.cpp"
__0__V232 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V232 )) , (const struct ea *)( ((& __0__V233 )-> __O1__2ea.p =
# 2609 "/home/claude/cfront-3/src/simpl2.cpp"
((const void *)__1cl )), (& __0__V233 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else 
# 2612 "/home/claude/cfront-3/src/simpl2.cpp"
__1cl = 0 ;

# 2614 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1cl && ((__1n = ( __1cl -> c_dtor__8classdef ) )|| (__0this -> __O3__4expr.e2 && has_ictor__8classdefFv ( __1cl ) ))){ 
# 2616 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2617 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __3ee ;
# 2617 "/home/claude/cfront-3/src/simpl2.cpp"

# 2618 "/home/claude/cfront-3/src/simpl2.cpp"
const char *__3s ;
Pname __3n ;

# 2620 "/home/claude/cfront-3/src/simpl2.cpp"
struct call *__0__X235 ;

# 2620 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X236 ;

# 2620 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X237 ;

# 2617 "/home/claude/cfront-3/src/simpl2.cpp"
__3ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __0this -> __O2__4expr.e1 , (struct expr *)0 ) ;
__3s = oper_name__FUc ( (unsigned char )9 ) ;

# 2621 "/home/claude/cfront-3/src/simpl2.cpp"
if (__0this -> base__4node != 188 ){ 
# 2622 "/home/claude/cfront-3/src/simpl2.cpp"
__3n = __ct__4nameFPCc ( (struct name *)0 , __3s ) ;
__3n = (((struct name *)(((struct name *)find_name__FP4nameP8classdefP5tableiT1 ( __3n , __1cl , scope , 109 , curr_fct ) ))));

# 2625 "/home/claude/cfront-3/src/simpl2.cpp"
if ((__3n -> __O1__4expr.tp -> base__4node == 76 )|| ((((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))))-> nargs__3fct == 2 ))
# 2626 "/home/claude/cfront-3/src/simpl2.cpp"
{ 
# 2627 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __5ss ;

# 2628 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X234 ;

# 2627 "/home/claude/cfront-3/src/simpl2.cpp"
__5ss = (struct expr *)( (__0__X234 = 0 ), ( ((__0__X234 || (__0__X234 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 2627 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X234 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X234 ), ((unsigned char )30 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 2627 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X234 -> __O4__4expr.tp2 = ((struct type *)__1cl ))) :0 ), __0__X234 ) ) ;
__5ss -> __O1__4expr.tp = size_t_type ;
__3ee -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __5ss , (struct expr *)0 ) ;
}
}
else 
# 2633 "/home/claude/cfront-3/src/simpl2.cpp"
__3n = look__5tableFPCcUc ( gtbl , __3s , (unsigned char )0 ) ;

# 2635 "/home/claude/cfront-3/src/simpl2.cpp"
__3ee = (struct expr *)( (__0__X235 = 0 ), ( (__2__X236 = (struct expr *)__3n ), ( (__2__X237 = __3ee ), ( ((__0__X235 ||
# 2635 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X235 = (struct call *)__nw__4exprSFUl ( (size_t )(sizeof (struct call))) ))?(__0__X235 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X235 ), (unsigned char
# 2635 "/home/claude/cfront-3/src/simpl2.cpp"
)109 , __2__X236 , __2__X237 ) ):0 ), __0__X235 ) ) ) ) ;
__3ee -> base__4node = 146 ;

# 2644 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2648 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__0this -> base__4node == 188 )&& (__0this -> __O3__4expr.e2 == 0 ))|| (__1n && (((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))))-> f_virtual__3fct )){ 
# 2649 "/home/claude/cfront-3/src/simpl2.cpp"
nin =
# 2649 "/home/claude/cfront-3/src/simpl2.cpp"
1 ;
{ int __3needtemp ;

# 2650 "/home/claude/cfront-3/src/simpl2.cpp"
__3needtemp = not_simple__4exprFi ( __0this -> __O2__4expr.e1 , 0 ) ;
nin = 0 ;
if (__3needtemp ){ 
# 2656 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __4tnx ;

# 2656 "/home/claude/cfront-3/src/simpl2.cpp"
__4tnx = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'K' ) ) ;
__4tnx -> __O1__4expr.tp = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
{ Pname __4tn ;

# 2658 "/home/claude/cfront-3/src/simpl2.cpp"
__4tn = dcl__4nameFP5tableUc ( __4tnx , scope , (unsigned char )108 ) ;
( (__4tnx ?(((void )(__4tnx ?(((void )( ( ((((struct expr *)__4tnx ))?(((void )((((struct expr *)__4tnx ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 2659 "/home/claude/cfront-3/src/simpl2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__4tnx , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
assign__4nameFv ( __4tn ) ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__4tn , __0this -> __O2__4expr.e1 ) ;
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , (struct expr *)__4tn , __0this -> __O3__4expr.e2 ) ;
__0this -> base__4node = 71 ;

# 2665 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4exprFv ( __0this ) ;
return ;

# 2666 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2667 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
{ Pexpr __2r ;

# 2669 "/home/claude/cfront-3/src/simpl2.cpp"
__2r = __0this -> __O2__4expr.e1 ;

# 2672 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1n && (__1n -> n_scope__4name != 25 ))check_visibility__FP4nameT1P8classdefP5tableT1 ( __1n , (struct name *)0 , __1cl , cc -> ftbl__11dcl_context , cc -> nof__11dcl_context ) ;
# 2672 "/home/claude/cfront-3/src/simpl2.cpp"

# 2674 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1n && (__0this -> __O3__4expr.e2 == 0 )){ 
# 2675 "/home/claude/cfront-3/src/simpl2.cpp"
if (__1n -> n_dcl_printed__4name == 0 ){ 
# 2676 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __4nn ;
Pexpr __4del ;

# 2676 "/home/claude/cfront-3/src/simpl2.cpp"
__4nn = __ct__4nameFPCc ( (struct name *)0 , oper_name__FUc ( (unsigned char )9 ) ) ;
__4del = find_name__FP4nameP8classdefP5tableiT1 ( __4nn , __1cl , scope , 109 , curr_fct ) ;
dcl_print__4nameFUc ( ((struct name *)(((struct name *)__4del ))), (unsigned char )0 ) ;
}
{ Pexpr __3ee ;

# 2680 "/home/claude/cfront-3/src/simpl2.cpp"
__3ee = call_dtor__FP4exprN21iT1 ( __2r , (struct expr *)__1n , (__0this -> base__4node == 188 )?(((struct expr *)0 )):one , 44 , one ) ;
if ((((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))))-> f_virtual__3fct ){ 
# 2682 "/home/claude/cfront-3/src/simpl2.cpp"
if (ansi_opt ){ 
# 2683 "/home/claude/cfront-3/src/simpl2.cpp"
__3ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char
# 2683 "/home/claude/cfront-3/src/simpl2.cpp"
)147 , __3ee , zero ) ;
__3ee -> __O1__4expr.tp = (struct type *)zero_type ;
}
__3ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , __3ee , zero ) ;
__3ee -> __O1__4expr.tp = __3ee -> __O2__4expr.e1 -> __O1__4expr.tp ;
__3ee -> __O4__4expr.cond = __2r ;
}
if (__0this -> base__4node == 188 ){ 
# 2691 "/home/claude/cfront-3/src/simpl2.cpp"
const char *__4s ;
Pexpr __4p ;
Pname __4n_gdelete ;

# 2694 "/home/claude/cfront-3/src/simpl2.cpp"
struct call *__0__X238 ;

# 2694 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X239 ;

# 2694 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X240 ;

# 2691 "/home/claude/cfront-3/src/simpl2.cpp"
__4s = oper_name__FUc ( (unsigned char )9 ) ;
__4p = (struct expr *)look__5tableFPCcUc ( gtbl , __4s , (unsigned char )0 ) ;
__4n_gdelete = (((struct name *)(((struct name *)__4p ))));
if (__4n_gdelete && (! __4n_gdelete -> n_dcl_printed__4name )){ 
# 2695 "/home/claude/cfront-3/src/simpl2.cpp"
dcl_print__4nameFUc ( __4n_gdelete , (unsigned char )0 ) ;
}
__0this -> __O3__4expr.e2 = (struct expr *)( (__0__X238 = 0 ), ( (__2__X239 = __4p ), ( (__2__X240 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 ,
# 2697 "/home/claude/cfront-3/src/simpl2.cpp"
(unsigned char )140 , __0this -> __O2__4expr.e1 , (struct expr *)0 ) ), ( ((__0__X238 || (__0__X238 = (struct call *)__nw__4exprSFUl ( (unsigned
# 2697 "/home/claude/cfront-3/src/simpl2.cpp"
long )(sizeof (struct call))) ))?(__0__X238 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X238 ), (unsigned char )109 , __2__X239 , __2__X240 ) ):0 ),
# 2697 "/home/claude/cfront-3/src/simpl2.cpp"
__0__X238 ) ) ) ) ;
__0this -> base__4node = 71 ;
__0this -> __O2__4expr.e1 = __3ee ;
}
else { 
# 2702 "/home/claude/cfront-3/src/simpl2.cpp"
((*__0this ))= (*__3ee );
( (__3ee ?(((void )(__3ee ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__3ee , (size_t )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 2703 "/home/claude/cfront-3/src/simpl2.cpp"
;
}
simpl__4exprFv ( __0this ) ;
return ;

# 2706 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
else { 
# 2709 "/home/claude/cfront-3/src/simpl2.cpp"
Ptype __3ttt ;

# 2709 "/home/claude/cfront-3/src/simpl2.cpp"
__3ttt = skiptypedefs__4typeFv ( __1tt ) ;
while (__3ttt -> base__4node == 110 )
# 2711 "/home/claude/cfront-3/src/simpl2.cpp"
__3ttt = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__3ttt ))))-> typ__5pvtyp ) ;
{ Pexpr __3sz ;

# 2713 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X255 ;

# 2712 "/home/claude/cfront-3/src/simpl2.cpp"
__3sz = (struct expr *)( (__0__X255 = 0 ), ( ((__0__X255 || (__0__X255 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 2712 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X255 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X255 ), ((unsigned char )30 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 2712 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X255 -> __O4__4expr.tp2 = __3ttt )) :0 ), __0__X255 ) ) ;
((void )tsizeof__4typeFi ( __3ttt , 0 ) );
{ int __3i ;

# 2714 "/home/claude/cfront-3/src/simpl2.cpp"
__3i = 0 ;
if (__1n ){ 
# 2716 "/home/claude/cfront-3/src/simpl2.cpp"
Pfct __4f ;
Pname __4nn ;

# 2716 "/home/claude/cfront-3/src/simpl2.cpp"
__4f = (((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))));
__4nn = __4f -> f_args__3fct -> __O1__4name.n_list ;
for(;__4nn && __4nn -> __O1__4name.n_list ;__4nn = __4nn -> __O1__4name.n_list ) __3i ++ ;

# 2720 "/home/claude/cfront-3/src/simpl2.cpp"
}
{ Pexpr __3arg ;

# 2722 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X251 ;

# 2722 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X252 ;

# 2722 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X253 ;

# 2722 "/home/claude/cfront-3/src/simpl2.cpp"
struct ival *__0__X254 ;

# 2721 "/home/claude/cfront-3/src/simpl2.cpp"
__3arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (struct expr *)( (__0__X254 = 0 ), ( ((__0__X254 || (__0__X254 =
# 2721 "/home/claude/cfront-3/src/simpl2.cpp"
(struct ival *)__nw__4exprSFUl ( (size_t )(sizeof (struct ival))) ))?( (__0__X254 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X254 ), (unsigned char
# 2721 "/home/claude/cfront-3/src/simpl2.cpp"
)150 , (struct expr *)0 , (struct expr *)0 ) ), (__0__X254 -> __O2__4expr.i1 = ((long long )__3i ))) :0 ), __0__X254 ) ) ,
# 2721 "/home/claude/cfront-3/src/simpl2.cpp"
(struct expr *)0 ) ;
__3sz -> __O1__4expr.tp = (struct type *)uint_type ;

# 2724 "/home/claude/cfront-3/src/simpl2.cpp"
__3arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , one , __3arg ) ;
if (__1n && (((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))))-> f_virtual__3fct ){ 
# 2726 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __4a ;

# 2727 "/home/claude/cfront-3/src/simpl2.cpp"
register struct mdot *__0__X241 ;

# 2727 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X242 ;

# 2727 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X243 ;

# 2727 "/home/claude/cfront-3/src/simpl2.cpp"
struct ref *__0__X244 ;

# 2727 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X245 ;

# 2727 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X246 ;

# 2726 "/home/claude/cfront-3/src/simpl2.cpp"
__4a = (struct expr *)( (__0__X244 = 0 ), ( (__2__X245 = __0this -> __O2__4expr.e1 ), ( (__2__X246 = (struct expr *)__1n ), (
# 2726 "/home/claude/cfront-3/src/simpl2.cpp"
((__0__X244 || (__0__X244 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X244 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X244 ),
# 2726 "/home/claude/cfront-3/src/simpl2.cpp"
((unsigned char )44 ), __2__X245 , (struct expr *)0 ) ), (__0__X244 -> __O4__4expr.mem = __2__X246 )) :0 ), __0__X244 ) ) )
# 2726 "/home/claude/cfront-3/src/simpl2.cpp"
) ;
__4a = address__4exprFv ( __4a ) ;
__4a = (struct expr *)( (__0__X241 = 0 ), ( ((__0__X241 || (__0__X241 = (struct mdot *)__nw__4exprSFUl ( (size_t )(sizeof (struct mdot)))
# 2728 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X241 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X241 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 2728 "/home/claude/cfront-3/src/simpl2.cpp"
( (__0__X241 -> __O3__4expr.string2 = ((const char *)"f")), (__0__X241 -> __O4__4expr.mem = __4a )) )
# 2728 "/home/claude/cfront-3/src/simpl2.cpp"
:0 ), __0__X241 ) ) ;
__4a -> __O2__4expr.i1 = 9 ;
__4a = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , __4a , zero ) ;
__4a -> __O4__4expr.cond = __0this -> __O2__4expr.e1 ;
__3arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (struct expr *)( (__0__X242 = 0 ), ( (__2__X243 = Pvoid_type ),
# 2732 "/home/claude/cfront-3/src/simpl2.cpp"
( ((__0__X242 || (__0__X242 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X242 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct
# 2732 "/home/claude/cfront-3/src/simpl2.cpp"
expr *)__0__X242 ), ((unsigned char )191 ), __4a , (struct expr *)0 ) ), (__0__X242 -> __O4__4expr.tp2 = __2__X243 )) :0 ), __0__X242 ) )
# 2732 "/home/claude/cfront-3/src/simpl2.cpp"
) , __3arg ) ;
}
else { 
# 2734 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X247 ;

# 2734 "/home/claude/cfront-3/src/simpl2.cpp"
struct type *__2__X248 ;

# 2734 "/home/claude/cfront-3/src/simpl2.cpp"
struct expr *__2__X249 ;

# 2735 "/home/claude/cfront-3/src/simpl2.cpp"
__3arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (struct expr *)( (__0__X247 = 0 ), ( (__2__X248 = Pvoid_type ),
# 2735 "/home/claude/cfront-3/src/simpl2.cpp"
( (__2__X249 = (__1n ?(((struct expr *)__1n )):zero )), ( ((__0__X247 || (__0__X247 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?(
# 2735 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X247 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X247 ), ((unsigned char )191 ), __2__X249 , (struct expr *)0 ) ), (__0__X247 -> __O4__4expr.tp2 =
# 2735 "/home/claude/cfront-3/src/simpl2.cpp"
__2__X248 )) :0 ), __0__X247 ) ) ) ) , __3arg ) ;
if (__1n )
# 2737 "/home/claude/cfront-3/src/simpl2.cpp"
lval__4exprFUc ( (struct expr *)__1n , (unsigned char )112 ) ;
}

# 2740 "/home/claude/cfront-3/src/simpl2.cpp"
__3arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __3sz , __3arg ) ;
if (__0this -> __O3__4expr.e2 -> base__4node == 144 ){ 
# 2741 "/home/claude/cfront-3/src/simpl2.cpp"
struct ival *__0__X250 ;

# 2742 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O3__4expr.e2 = (struct expr *)( (__0__X250 = 0 ), ( ((__0__X250 || (__0__X250 = (struct ival *)__nw__4exprSFUl ( (size_t)(sizeof
# 2742 "/home/claude/cfront-3/src/simpl2.cpp"
(struct ival))) ))?( (__0__X250 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X250 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 )
# 2742 "/home/claude/cfront-3/src/simpl2.cpp"
), (__0__X250 -> __O2__4expr.i1 = ((long long )-1))) :0 ), __0__X250 ) ) ;
}

# 2745 "/home/claude/cfront-3/src/simpl2.cpp"
__3arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __0this -> __O3__4expr.e2 , __3arg ) ;
__3arg = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (struct expr *)( (__0__X251 = 0 ), ( (__2__X252 = Pvoid_type ),
# 2746 "/home/claude/cfront-3/src/simpl2.cpp"
( (__2__X253 = __0this -> __O2__4expr.e1 ), ( ((__0__X251 || (__0__X251 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?(
# 2746 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X251 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X251 ), ((unsigned char )191 ), __2__X253 , (struct expr *)0 ) ), (__0__X251 -> __O4__4expr.tp2 =
# 2746 "/home/claude/cfront-3/src/simpl2.cpp"
__2__X252 )) :0 ), __0__X251 ) ) ) ) , __3arg ) ;
{ Pexpr __3ee ;

# 2747 "/home/claude/cfront-3/src/simpl2.cpp"
__3ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , (struct expr *)vec_del_fct , __3arg ) ;
__3ee -> __O4__4expr.fct_name = vec_del_fct ;
__3ee -> __O1__4expr.tp = __0this -> __O1__4expr.tp ;

# 2757 "/home/claude/cfront-3/src/simpl2.cpp"
((*__0this ))= (*__3ee );
simpl__4exprFv ( __0this ) ;
return ;

# 2759 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2759 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2759 "/home/claude/cfront-3/src/simpl2.cpp"
}

# 2759 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2760 "/home/claude/cfront-3/src/simpl2.cpp"
}
}
else { 
# 2763 "/home/claude/cfront-3/src/simpl2.cpp"
if (((__0this -> __O3__4expr.e2 == 0 )&& is_ptr__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) )&& ((((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv (
# 2763 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O2__4expr.e1 -> __O1__4expr.tp ) ))))-> typ__5pvtyp -> base__4node == 110 ))
# 2764 "/home/claude/cfront-3/src/simpl2.cpp"
error__FPCc ( (const char *)"use delete[] to delete an array")
# 2764 "/home/claude/cfront-3/src/simpl2.cpp"
;
{ Pexpr __2ee ;
const char *__2s ;

# 2765 "/home/claude/cfront-3/src/simpl2.cpp"
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __0this -> __O2__4expr.e1 , (struct expr *)0 ) ;
__2s = oper_name__FUc ( (unsigned char )9 ) ;
if (__1cl && (__0this -> base__4node != 188 )){ 
# 2768 "/home/claude/cfront-3/src/simpl2.cpp"
Pname __3n ;

# 2768 "/home/claude/cfront-3/src/simpl2.cpp"
__3n = __ct__4nameFPCc ( (struct name *)0 , __2s ) ;
__0this -> __O2__4expr.e1 = find_name__FP4nameP8classdefP5tableiT1 ( __3n , __1cl , scope , 109 , curr_fct ) ;
if ((__0this -> __O2__4expr.e1 -> __O1__4expr.tp -> base__4node == 76 )|| ((((struct fct *)(((struct fct *)__0this -> __O2__4expr.e1 -> __O1__4expr.tp ))))-> nargs__3fct == 2 )){ 
# 2771 "/home/claude/cfront-3/src/simpl2.cpp"
Pexpr __4ss ;
# 2771 "/home/claude/cfront-3/src/simpl2.cpp"

# 2771 "/home/claude/cfront-3/src/simpl2.cpp"
struct texpr *__0__X256 ;

# 2771 "/home/claude/cfront-3/src/simpl2.cpp"
__4ss = (struct expr *)( (__0__X256 = 0 ), ( ((__0__X256 || (__0__X256 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 2771 "/home/claude/cfront-3/src/simpl2.cpp"
))?( (__0__X256 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X256 ), ((unsigned char )30 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 2771 "/home/claude/cfront-3/src/simpl2.cpp"
(__0__X256 -> __O4__4expr.tp2 = ((struct type *)__1cl ))) :0 ), __0__X256 ) ) ;
__4ss -> __O1__4expr.tp = size_t_type ;
__2ee -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __4ss , (struct expr *)0 ) ;
}
}
else 
# 2777 "/home/claude/cfront-3/src/simpl2.cpp"
__0this -> __O2__4expr.e1 = (struct expr *)look__5tableFPCcUc ( gtbl , __2s , (unsigned char )0 ) ;
__0this -> base__4node = 146 ;
__0this -> __O3__4expr.e2 = __2ee ;
overFound = 0 ;
((void )call_fct__4exprFP5table ( __0this , scope ) );
if (overFound && (overFound -> n_scope__4name != 14 ))
# 2783 "/home/claude/cfront-3/src/simpl2.cpp"
check_visibility__FP4nameT1P8classdefP5tableT1 ( overFound , (struct name *)0 , __1cl , cc -> ftbl__11dcl_context , cc -> nof__11dcl_context ) ;
# 2783 "/home/claude/cfront-3/src/simpl2.cpp"

# 2784 "/home/claude/cfront-3/src/simpl2.cpp"
overFound = 0 ;

# 2784 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

# 2787 "/home/claude/cfront-3/src/simpl2.cpp"
simpl__4callFv ( ((struct call *)(((struct call *)__0this )))) ;

# 2787 "/home/claude/cfront-3/src/simpl2.cpp"
}
}

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

# 2788 "/home/claude/cfront-3/src/simpl2.cpp"

/* the end */
