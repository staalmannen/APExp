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

#pragma lib "c++/libC.a"

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

# 21 "/home/claude/cfront-3/src/dcl2.cpp"
extern Pblock top_block ;
struct for_info;

# 28 "/home/claude/cfront-3/src/dcl2.cpp"
static struct for_info *for_info_head = 0 ;

# 75 "/home/claude/cfront-3/src/cfront.h"

# 23 "/home/claude/cfront-3/src/dcl2.cpp"
struct for_info {	/* sizeof for_info == 24 */
char *s__8for_info ;
Pstmt rb__8for_info ;
struct for_info *next__8for_info ;
};

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 29 "/home/claude/cfront-3/src/dcl2.cpp"
static int for_check__FP4nameP4stmt (Pname __1n , Pstmt __1rb )
# 30 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 31 "/home/claude/cfront-3/src/dcl2.cpp"
struct for_info *__1p ;
if ((! __1n )|| (! __1rb ))
# 33 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 33 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V37 ;

# 33 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V38 ;

# 33 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"for_check(n=%d,rb=%d)", (const struct ea *)( ((&
# 33 "/home/claude/cfront-3/src/dcl2.cpp"
__0__V37 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V37 )) , (const struct ea *)( ((& __0__V38 )-> __O1__2ea.p =
# 33 "/home/claude/cfront-3/src/dcl2.cpp"
((const void *)__1rb )), (& __0__V38 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if ((__1n -> __O1__4expr.tp -> base__4node == 108 )|| (__1n -> __O1__4expr.tp -> base__4node == 76 ))
# 35 "/home/claude/cfront-3/src/dcl2.cpp"
return 0 ;
__1p = for_info_head ;
while (__1p && (strcmp ( (const char *)__1p -> s__8for_info , __1n -> __O2__4expr.string ) || (__1p -> rb__8for_info != __1rb )))
# 38 "/home/claude/cfront-3/src/dcl2.cpp"
__1p = __1p ->
# 38 "/home/claude/cfront-3/src/dcl2.cpp"
next__8for_info ;
if (__1p ){ 
# 40 "/home/claude/cfront-3/src/dcl2.cpp"
return 1 ;
}
else { 
# 43 "/home/claude/cfront-3/src/dcl2.cpp"
__1p = (((struct for_info *)__nw__FUl ( sizeof (struct for_info )) ));
__1p -> s__8for_info = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __1n -> __O2__4expr.string ) + 1 )))
# 44 "/home/claude/cfront-3/src/dcl2.cpp"
));
strcpy ( __1p -> s__8for_info , __1n -> __O2__4expr.string ) ;
__1p -> rb__8for_info = __1rb ;
__1p -> next__8for_info = for_info_head ;
for_info_head = __1p ;
return 0 ;
}
}
void for_check_delete__Fv (void )
# 53 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 54 "/home/claude/cfront-3/src/dcl2.cpp"
struct for_info *__1p ;
struct for_info *__1r ;

# 57 "/home/claude/cfront-3/src/dcl2.cpp"
__1p = for_info_head ;
while (__1p ){ 
# 59 "/home/claude/cfront-3/src/dcl2.cpp"
__1r = __1p ;
__dl__FPv ( (void *)__1p -> s__8for_info ) ;
__1p = __1p -> next__8for_info ;
__dl__FPv ( (void *)__1r ) ;
}
for_info_head = 0 ;
}

# 67 "/home/claude/cfront-3/src/dcl2.cpp"
static Pname is_decl__FP5blockP4name (Pblock __1cb , Pname __1v )
# 68 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 69 "/home/claude/cfront-3/src/dcl2.cpp"
if (! __1cb -> __O1__4stmt.d )return (struct name *)0 ;
{ { Pname __1n ;

# 70 "/home/claude/cfront-3/src/dcl2.cpp"
__1n = __1cb -> __O1__4stmt.d ;

# 70 "/home/claude/cfront-3/src/dcl2.cpp"
for(;__1n ;__1n = __1n -> __O1__4name.n_list ) { 
# 71 "/home/claude/cfront-3/src/dcl2.cpp"
if (strcmp ( __1v -> __O2__4expr.string , __1n -> __O2__4expr.string ) == 0 )
# 72 "/home/claude/cfront-3/src/dcl2.cpp"
return __1n ;
}
return (struct name *)0 ;

# 74 "/home/claude/cfront-3/src/dcl2.cpp"
}

# 74 "/home/claude/cfront-3/src/dcl2.cpp"
}
}

# 77 "/home/claude/cfront-3/src/dcl2.cpp"
static Pname redecl = 0 ;

# 79 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt find_return__FP4stmtP4name (Pstmt __1s , Pname __1v );

# 79 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt find_return__FP4stmtP4name (Pstmt __1s , Pname __1v )
# 80 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 82 "/home/claude/cfront-3/src/dcl2.cpp"
while (__1s ){ 
# 83 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__1s -> base__4node ){ 
# 84 "/home/claude/cfront-3/src/dcl2.cpp"
case 28 :
# 85 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 86 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __4te ;

# 86 "/home/claude/cfront-3/src/dcl2.cpp"
__4te = ((__1s -> __O2__4stmt.e -> base__4node == 85 )?(((struct name *)(((struct name *)__1s -> __O2__4stmt.e )))):(((struct name *)0 )));
if ((! __4te )|| strcmp ( __4te -> __O2__4expr.string , __1v -> __O2__4expr.string ) )
# 90 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 91 "/home/claude/cfront-3/src/dcl2.cpp"
return __1s ;
}
if (__4te == __1v )return (struct stmt *)0 ;
if (redecl )return __1s ;
else return (struct stmt *)0 ;
}
case 116 :
# 98 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 99 "/home/claude/cfront-3/src/dcl2.cpp"
if (! redecl )redecl = is_decl__FP5blockP4name ( ((struct block *)(((struct block *)__1s ))), __1v ) ;
{ Pstmt __4tt ;

# 100 "/home/claude/cfront-3/src/dcl2.cpp"
__4tt = find_return__FP4stmtP4name ( (((struct block *)(((struct block *)__1s ))))-> s__4stmt , __1v ) ;
if (__4tt )return __4tt ;
redecl = 0 ;
break ;

# 103 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
case 10 :
# 106 "/home/claude/cfront-3/src/dcl2.cpp"
case 39 :
# 107 "/home/claude/cfront-3/src/dcl2.cpp"
case 16 :
# 108 "/home/claude/cfront-3/src/dcl2.cpp"
case 33 :
# 109 "/home/claude/cfront-3/src/dcl2.cpp"
case 4 :
# 110 "/home/claude/cfront-3/src/dcl2.cpp"
case 8 :
# 111 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 112 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __4tt ;

# 112 "/home/claude/cfront-3/src/dcl2.cpp"
__4tt = find_return__FP4stmtP4name ( __1s -> s__4stmt , __1v ) ;
if (__4tt )return __4tt ;
break ;
}
case 20 :
# 117 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 118 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __4tt ;

# 118 "/home/claude/cfront-3/src/dcl2.cpp"
__4tt = find_return__FP4stmtP4name ( __1s -> s__4stmt , __1v ) ;
if (__4tt )return __4tt ;
__4tt = find_return__FP4stmtP4name ( __1s -> __O3__4stmt.else_stmt , __1v ) ;
if (__4tt )return __4tt ;
break ;
}
}
__1s = __1s -> s_list__4stmt ;
}
return (struct stmt *)0 ;
}

# 1288 "/home/claude/cfront-3/src/cfront.h"

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 460 "/home/claude/cfront-3/src/cfront.h"
bit has_base__8classdefFP8classdefiT2 (struct classdef *__0this , Pclass __1cl , int __1level , int __1ccflag );

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 130 "/home/claude/cfront-3/src/dcl2.cpp"
Pname hier_dominates__FP4nameT1 (Pname __1on1 , Pname __1on2 )
# 139 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 140 "/home/claude/cfront-3/src/dcl2.cpp"
Pfct __1f1 ;
Pfct __1f2 ;

# 143 "/home/claude/cfront-3/src/dcl2.cpp"
Ptype __1r1 ;
Ptype __1r2 ;

# 140 "/home/claude/cfront-3/src/dcl2.cpp"
__1f1 = ( ((__1on1 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1on1 -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__1on1 -> __O1__4expr.tp ))))->
# 140 "/home/claude/cfront-3/src/dcl2.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;
__1f2 = ( ((__1on2 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1on2 -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__1on2 -> __O1__4expr.tp ))))->
# 141 "/home/claude/cfront-3/src/dcl2.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;

# 143 "/home/claude/cfront-3/src/dcl2.cpp"
__1r1 = __1f1 -> returns__3fct ;
__1r2 = __1f2 -> returns__3fct ;

# 146 "/home/claude/cfront-3/src/dcl2.cpp"
if ((__1r1 == __1r2 )|| (check__4typeFP4typeUcT2 ( __1r1 , __1r2 , (unsigned char )0 , (unsigned char )0 ) == 0 )){
# 146 "/home/claude/cfront-3/src/dcl2.cpp"

# 147 "/home/claude/cfront-3/src/dcl2.cpp"
Pclass __2m1 ;
Pclass __2m2 ;

# 147 "/home/claude/cfront-3/src/dcl2.cpp"
__2m1 = __1f1 -> memof__3fct ;
__2m2 = __1f2 -> memof__3fct ;
if (has_base__8classdefFP8classdefiT2 ( __2m1 , __2m2 , 0 , 0 ) )return __1on1 ;
if (has_base__8classdefFP8classdefiT2 ( __2m2 , __2m1 , 0 , 0 ) )return __1on2 ;
return (struct name *)0 ;
}
{ Pptr __1p1 ;
Pptr __1p2 ;

# 153 "/home/claude/cfront-3/src/dcl2.cpp"
__1p1 = is_ptr_or_ref__4typeFv ( __1r1 ) ;
__1p2 = is_ptr_or_ref__4typeFv ( __1r2 ) ;
if (__1p1 && __1p2 ){ 
# 156 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __2cn1 ;
Pname __2cn2 ;

# 156 "/home/claude/cfront-3/src/dcl2.cpp"
__2cn1 = is_cl_obj__4typeFv ( __1p1 -> typ__5pvtyp ) ;
__2cn2 = is_cl_obj__4typeFv ( __1p2 -> typ__5pvtyp ) ;
if (__2cn1 && __2cn2 ){ 
# 159 "/home/claude/cfront-3/src/dcl2.cpp"
Pclass __3c1 ;
Pclass __3c2 ;

# 159 "/home/claude/cfront-3/src/dcl2.cpp"
__3c1 = (((struct classdef *)(((struct classdef *)__2cn1 -> __O1__4expr.tp ))));
__3c2 = (((struct classdef *)(((struct classdef *)__2cn2 -> __O1__4expr.tp ))));
if (__3c1 && __3c2 ){ 
# 162 "/home/claude/cfront-3/src/dcl2.cpp"
if (has_base__8classdefFP8classdefiT2 ( __3c1 , __3c2 , 0 , 0 ) )
# 163 "/home/claude/cfront-3/src/dcl2.cpp"
return __1on1 ;
else if (has_base__8classdefFP8classdefiT2 ( __3c2 , __3c1 , 0 , 0 ) )
# 165 "/home/claude/cfront-3/src/dcl2.cpp"
return __1on2 ;
}
}
}
return (struct name *)0 ;

# 169 "/home/claude/cfront-3/src/dcl2.cpp"
}
}

# 65 "/home/claude/cfront-3/src/Bits.h"
struct Bits *__ct__4BitsFUlT1 (struct Bits *__0this , Bits_chunk , size_t );

# 71 "/home/claude/cfront-3/src/Bits.h"
extern void __co__FRC4Bits (struct Bits *__0_result , const struct Bits *);

# 103 "/home/claude/cfront-3/src/Bits.h"

# 113 "/home/claude/cfront-3/src/Bits.h"
size_t count__4BitsCFv (const struct Bits *const __0this );

# 39 "/home/claude/cfront-3/src/overload.h"

# 115 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 41 "/home/claude/cfront-3/src/cfront.h"
extern Pname really_dominate__FP4nameT1Uc (Pname , Pname , bit );

# 103 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 172 "/home/claude/cfront-3/src/dcl2.cpp"
void best_conv__FRC11Block_PnameRiUc (
# 47 "/home/claude/cfront-3/src/overload.h"
struct Bits *__0_result , 
# 172 "/home/claude/cfront-3/src/dcl2.cpp"
const struct Block_Pname *__1CONV , int *__1nfound , bit __1cO )
# 173 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 174 "/home/claude/cfront-3/src/dcl2.cpp"
struct Bits __1zeroBits ;

# 177 "/home/claude/cfront-3/src/dcl2.cpp"
struct Bits __1tempBits ;
int __1sigbit ;

# 179 "/home/claude/cfront-3/src/dcl2.cpp"
struct Block_Bits_chunk *__0__X36 ;

# 179 "/home/claude/cfront-3/src/dcl2.cpp"
struct Block_Bits_chunk *__0__X32 ;

# 179 "/home/claude/cfront-3/src/dcl2.cpp"
int __2__X33 ;

# 174 "/home/claude/cfront-3/src/dcl2.cpp"
__ct__4BitsFUlT1 ( & __1zeroBits , (unsigned long )0 , (unsigned long )((*__1nfound ))) ;
__co__FRC4Bits ( __0_result , (const struct Bits *)(& __1zeroBits )) ;

# 177 "/home/claude/cfront-3/src/dcl2.cpp"
__co__FRC4Bits ( & __1tempBits , (const struct Bits *)(& __1zeroBits )) ;
__1sigbit = (signif__4BitsCFv ( (const struct Bits *)(& __1tempBits )) - 1 );
( ((((unsigned long )__1sigbit )< (& __1tempBits )-> n__4Bits )?(((*( (__0__X32 = (& (& __1tempBits )-> b__4Bits )), ( (__2__X33 =
# 179 "/home/claude/cfront-3/src/dcl2.cpp"
( (((unsigned long )__1sigbit )>> 5)) ), ( (((Bits_chunk *)(& (__0__X32 -> p__16Block_Bits_chunk [__2__X33 ]))))) ) ) ))&= (~
# 179 "/home/claude/cfront-3/src/dcl2.cpp"
((((unsigned long )1 ))<< (((unsigned long )__1sigbit )& 31)))):0 ), (((struct Bits *)(& __1tempBits )))) ;

# 181 "/home/claude/cfront-3/src/dcl2.cpp"
while (count__4BitsCFv ( (const struct Bits *)(& __1tempBits )) ){ 
# 182 "/home/claude/cfront-3/src/dcl2.cpp"
int __2tempPtr ;
Pname __2tname ;

# 182 "/home/claude/cfront-3/src/dcl2.cpp"
__2tempPtr = (signif__4BitsCFv ( (const struct Bits *)(& __1tempBits )) - 1 );
__2tname = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1CONV )-> p__11Block_Pname [__2tempPtr ]))))) ));
{ { int __2k ;

# 185 "/home/claude/cfront-3/src/dcl2.cpp"
struct Block_Bits_chunk *__0__X32 ;

# 185 "/home/claude/cfront-3/src/dcl2.cpp"
int __2__X33 ;

# 184 "/home/claude/cfront-3/src/dcl2.cpp"
__2k = (((*__1nfound ))- 1 );

# 184 "/home/claude/cfront-3/src/dcl2.cpp"
for(;__2k > __2tempPtr ;__2k -- ) { 
# 184 "/home/claude/cfront-3/src/dcl2.cpp"
const struct Block_Bits_chunk *__0__X34 ;

# 184 "/home/claude/cfront-3/src/dcl2.cpp"
int __2__X35 ;

# 185 "/home/claude/cfront-3/src/dcl2.cpp"
if (! ( ((((unsigned long )__2k )>= ((const struct Bits *)__0_result )-> n__4Bits )?(((int )0 )):(((int )((((*( (__0__X34 = (const
# 185 "/home/claude/cfront-3/src/dcl2.cpp"
struct Block_Bits_chunk *)(& ((const struct Bits *)__0_result )-> b__4Bits )), ( (__2__X35 = ( (((unsigned long )__2k )>> 5)) ),
# 185 "/home/claude/cfront-3/src/dcl2.cpp"
( (((const Bits_chunk *)(& (__0__X34 -> p__16Block_Bits_chunk [__2__X35 ]))))) ) ) ))>> (((unsigned long )__2k )& 31))& 1 ))))) )continue
# 185 "/home/claude/cfront-3/src/dcl2.cpp"
;
{ Pname __3r ;

# 187 "/home/claude/cfront-3/src/dcl2.cpp"
struct Block_Bits_chunk *__0__X32 ;

# 187 "/home/claude/cfront-3/src/dcl2.cpp"
int __2__X33 ;

# 186 "/home/claude/cfront-3/src/dcl2.cpp"
__3r = really_dominate__FP4nameT1Uc ( __2tname , (struct name *)((*( (((const Pname *)(& (((const struct Block_Pname *)__1CONV )-> p__11Block_Pname [__2k ]))))) )), __1cO ) ;
# 186 "/home/claude/cfront-3/src/dcl2.cpp"

# 187 "/home/claude/cfront-3/src/dcl2.cpp"
if (__3r == __2tname )
# 188 "/home/claude/cfront-3/src/dcl2.cpp"
( ((((unsigned long )__2k )< __0_result -> n__4Bits )?(((*( (__0__X32 = (& __0_result -> b__4Bits )), ( (__2__X33 =
# 188 "/home/claude/cfront-3/src/dcl2.cpp"
( (((unsigned long )__2k )>> 5)) ), ( (((Bits_chunk *)(& (__0__X32 -> p__16Block_Bits_chunk [__2__X33 ]))))) ) ) ))&= (~
# 188 "/home/claude/cfront-3/src/dcl2.cpp"
((((unsigned long )1 ))<< (((unsigned long )__2k )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
if (__3r == ((*( (((const Pname *)(& (((const struct Block_Pname *)__1CONV )-> p__11Block_Pname [__2k ]))))) ))){ 
# 189 "/home/claude/cfront-3/src/dcl2.cpp"
struct Block_Bits_chunk *__0__X32 ;

# 189 "/home/claude/cfront-3/src/dcl2.cpp"
int __2__X33 ;

# 190 "/home/claude/cfront-3/src/dcl2.cpp"
( ((((unsigned long )__2tempPtr )< __0_result -> n__4Bits )?(((*( (__0__X32 = (& __0_result -> b__4Bits )), ( (__2__X33 = ( (((unsigned
# 190 "/home/claude/cfront-3/src/dcl2.cpp"
long )__2tempPtr )>> 5)) ), ( (((Bits_chunk *)(& (__0__X32 -> p__16Block_Bits_chunk [__2__X33 ]))))) ) ) ))&= (~ ((((unsigned long
# 190 "/home/claude/cfront-3/src/dcl2.cpp"
)1 ))<< (((unsigned long )__2tempPtr )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
break ;
}

# 192 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
( ((((unsigned long )__2tempPtr )< (& __1tempBits )-> n__4Bits )?(((*( (__0__X32 = (& (& __1tempBits )-> b__4Bits )), ( (__2__X33 =
# 194 "/home/claude/cfront-3/src/dcl2.cpp"
( (((unsigned long )__2tempPtr )>> 5)) ), ( (((Bits_chunk *)(& (__0__X32 -> p__16Block_Bits_chunk [__2__X33 ]))))) ) ) ))&= (~
# 194 "/home/claude/cfront-3/src/dcl2.cpp"
((((unsigned long )1 ))<< (((unsigned long )__2tempPtr )& 31)))):0 ), (((struct Bits *)(& __1tempBits )))) ;

# 194 "/home/claude/cfront-3/src/dcl2.cpp"
}

# 194 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
((*__1nfound ))= count__4BitsCFv ( (const struct Bits *)__0_result ) ;
{ { ;

# 197 "/home/claude/cfront-3/src/dcl2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __1tempBits )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv (
# 197 "/home/claude/cfront-3/src/dcl2.cpp"
(void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 197 "/home/claude/cfront-3/src/dcl2.cpp"
))))) ;

# 197 "/home/claude/cfront-3/src/dcl2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __1zeroBits )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv (
# 197 "/home/claude/cfront-3/src/dcl2.cpp"
(void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 197 "/home/claude/cfront-3/src/dcl2.cpp"
))))) ;
} 
# 197 "/home/claude/cfront-3/src/dcl2.cpp"
return ;
} }

# 200 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt curr_loop = 0 ;
Pstmt curr_switch = 0 ;
Pblock curr_block = 0 ;
static Pstmt curr_case ;
static Pblock block_since_case ;

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 206 "/home/claude/cfront-3/src/dcl2.cpp"
void reached__4stmtFv (register struct stmt *__0this )
# 207 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 208 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __1ss ;

# 208 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss = __0this -> s_list__4stmt ;

# 210 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss == 0 )return ;

# 212 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__1ss -> base__4node ){ 
# 212 "/home/claude/cfront-3/src/dcl2.cpp"
unsigned long __2__X43 ;

# 212 "/home/claude/cfront-3/src/dcl2.cpp"
unsigned long __2__X44 ;

# 213 "/home/claude/cfront-3/src/dcl2.cpp"
case 115 :
# 214 "/home/claude/cfront-3/src/dcl2.cpp"
case 4 :
# 215 "/home/claude/cfront-3/src/dcl2.cpp"
case 8 :
# 216 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
default :
# 218 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> where__4stmt . line__3loc != 0 )
# 219 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 219 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V41 ;

# 219 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __1ss -> where__4stmt , (const char *)"S after%k not reached", (const
# 219 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea *)( (__2__X43 = __0this -> base__4node ), ( (( ((& __0__V41 )-> __O1__2ea.i = __2__X43 ), 0 ) ), (&
# 219 "/home/claude/cfront-3/src/dcl2.cpp"
__0__V41 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 221 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 221 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V42 ;

# 221 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"S after%k not reached", (const struct ea *)( (__2__X44 =
# 221 "/home/claude/cfront-3/src/dcl2.cpp"
__0this -> base__4node ), ( (( ((& __0__V42 )-> __O1__2ea.i = __2__X44 ), 0 ) ), (& __0__V42 )) ) ,
# 221 "/home/claude/cfront-3/src/dcl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} for(;__1ss ;__1ss = __1ss -> s_list__4stmt ) { 
# 223 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__1ss -> base__4node ){ 
# 224 "/home/claude/cfront-3/src/dcl2.cpp"
case 115 :
# 225 "/home/claude/cfront-3/src/dcl2.cpp"
case 4 :
# 226 "/home/claude/cfront-3/src/dcl2.cpp"
case 8 :
# 227 "/home/claude/cfront-3/src/dcl2.cpp"
__0this -> s_list__4stmt = __1ss ;
# 227 "/home/claude/cfront-3/src/dcl2.cpp"

# 228 "/home/claude/cfront-3/src/dcl2.cpp"
return ;
case 118 :
# 231 "/home/claude/cfront-3/src/dcl2.cpp"
case 20 :
# 232 "/home/claude/cfront-3/src/dcl2.cpp"
case 10 :
# 233 "/home/claude/cfront-3/src/dcl2.cpp"
case 39 :
# 234 "/home/claude/cfront-3/src/dcl2.cpp"
case 33 :
# 235 "/home/claude/cfront-3/src/dcl2.cpp"
case 16 :
# 236 "/home/claude/cfront-3/src/dcl2.cpp"
case 116 :
# 237 "/home/claude/cfront-3/src/dcl2.cpp"
__0this -> s_list__4stmt = __1ss ;
return ;
}
}
__0this -> s_list__4stmt = 0 ;
}
}

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 245 "/home/claude/cfront-3/src/dcl2.cpp"
bit oper_okay__FP4typeUc (Ptype __1t , TOK __1b )
# 246 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 247 "/home/claude/cfront-3/src/dcl2.cpp"
if (is_ref__4typeFv ( __1t ) )__1t = (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp ;

# 249 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__1t -> base__4node ){ 
# 250 "/home/claude/cfront-3/src/dcl2.cpp"
case 125 :
# 251 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1b == 107 )break ;
case 15 :
# 253 "/home/claude/cfront-3/src/dcl2.cpp"
case 11 :
# 254 "/home/claude/cfront-3/src/dcl2.cpp"
case 181 :
# 255 "/home/claude/cfront-3/src/dcl2.cpp"
if (((__1b == 47 )|| (__1b == 111 ))|| (__1b == 33 ))
# 256 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
case 5 :
# 258 "/home/claude/cfront-3/src/dcl2.cpp"
case 29 :
# 259 "/home/claude/cfront-3/src/dcl2.cpp"
case 21 :
# 260 "/home/claude/cfront-3/src/dcl2.cpp"
case 22 :
# 261 "/home/claude/cfront-3/src/dcl2.cpp"
case 122 :
# 262 "/home/claude/cfront-3/src/dcl2.cpp"
case 121 :
# 263 "/home/claude/cfront-3/src/dcl2.cpp"
return (unsigned char )1 ;
}

# 266 "/home/claude/cfront-3/src/dcl2.cpp"
return (unsigned char )0 ;
}

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 808 "/home/claude/cfront-3/src/cfront.h"
bit is_const_obj__4exprFv (struct expr *__0this );

# 1288 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 801 "/home/claude/cfront-3/src/cfront.h"
int lval__4exprFUc (struct expr *__0this , TOK );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 798 "/home/claude/cfront-3/src/cfront.h"
Pexpr typ__4exprFP5table (struct expr *__0this , Ptable );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 359 "/home/claude/cfront-3/src/cfront.h"
Pfct memptr__4typeFv (struct type *__0this );

# 20 "/home/claude/cfront-3/src/dcl2.cpp"
extern Pexpr make_dot__FP4exprP5tablePCc (Pexpr , Ptable , const char *__0s );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 354 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 269 "/home/claude/cfront-3/src/dcl2.cpp"
Pexpr check_cond__FP4exprUcP5table (Pexpr __1e , TOK __1b , Ptable __1tbl )
# 270 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 272 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __1cn ;
if (__1e == dummy ){ 
# 273 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V45 ;

# 273 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"empty condition for %k", (const struct ea *)( (( ((& __0__V45 )->
# 273 "/home/claude/cfront-3/src/dcl2.cpp"
__O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V45 )) , (const struct ea *)ea0 , (const struct
# 273 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 275 "/home/claude/cfront-3/src/dcl2.cpp"
{ int __1const_obj ;

# 276 "/home/claude/cfront-3/src/dcl2.cpp"
struct type *__0__X66 ;

# 275 "/home/claude/cfront-3/src/dcl2.cpp"
__1const_obj = 0 ;
__1const_obj = (tconst__4typeFv ( __1e -> __O1__4expr.tp ) ?(((unsigned int )1 )):(((unsigned int )is_const_obj__4exprFv ( __1e ) )));

# 278 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1cn = is_cl_obj__4typeFv ( __1e -> __O1__4expr.tp ) ){ 
# 279 "/home/claude/cfront-3/src/dcl2.cpp"
int __2no_const ;
Pclass __2cl ;
Pname __2found ;
Pname __2other ;
int __2nfound ;
struct Block_Pname __2conv ;

# 279 "/home/claude/cfront-3/src/dcl2.cpp"
__2no_const = 0 ;
__2cl = (((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))));
__2found = 0 ;
__2other = 0 ;
__2nfound = 0 ;
( (( ((& __2conv )-> n__11Block_Pname = 0 ), ((& __2conv )-> p__11Block_Pname = 0 )) ), (& __2conv )) ;
# 284 "/home/claude/cfront-3/src/dcl2.cpp"

# 285 "/home/claude/cfront-3/src/dcl2.cpp"
{ { Pname __2on ;

# 285 "/home/claude/cfront-3/src/dcl2.cpp"
__2on = __2cl -> conv__8classdef ;

# 285 "/home/claude/cfront-3/src/dcl2.cpp"
for(;__2on ;__2on = __2on -> __O1__4name.n_list ) { 
# 286 "/home/claude/cfront-3/src/dcl2.cpp"
Pfct __3f ;
Ptype __3t ;

# 286 "/home/claude/cfront-3/src/dcl2.cpp"
__3f = ( ((__2on -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__2on -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__2on -> __O1__4expr.tp ))))->
# 286 "/home/claude/cfront-3/src/dcl2.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;
__3t = skiptypedefs__4typeFv ( __3f -> returns__3fct ) ;

# 289 "/home/claude/cfront-3/src/dcl2.cpp"
if (oper_okay__FP4typeUc ( __3t , __1b ) == 1 )
# 290 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 290 "/home/claude/cfront-3/src/dcl2.cpp"
int __2__X58 ;

# 291 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1const_obj && (! __3f -> f_const__3fct )){ 
# 292 "/home/claude/cfront-3/src/dcl2.cpp"
__2no_const ++ ;
continue ;
}

# 296 "/home/claude/cfront-3/src/dcl2.cpp"
( ((((unsigned long )(__2nfound + 1 ))< (& __2conv )-> n__11Block_Pname )|| grow__11Block_PnameFUl ( (& __2conv ), ((unsigned long )(__2nfound +
# 296 "/home/claude/cfront-3/src/dcl2.cpp"
1 ))) )) ;
((*( (__2__X58 = (__2nfound ++ )), ( (((Pname *)(& ((& __2conv )-> p__11Block_Pname [__2__X58 ]))))) ) ))= __2on ;
}
}
if (__2nfound == 1 )__2found = ((*( (((Pname *)(& ((& __2conv )-> p__11Block_Pname [(__2nfound - 1 )]))))) ));
if (__2nfound > 1 ){ 
# 302 "/home/claude/cfront-3/src/dcl2.cpp"
struct Bits __3b ;
int __3i ;

# 304 "/home/claude/cfront-3/src/dcl2.cpp"
struct Block_Bits_chunk *__0__X36 ;

# 302 "/home/claude/cfront-3/src/dcl2.cpp"
best_conv__FRC11Block_PnameRiUc ( & __3b , (const struct Block_Pname *)(& __2conv ), (int *)(& __2nfound ), (unsigned char )__1const_obj ) ;
# 302 "/home/claude/cfront-3/src/dcl2.cpp"

# 303 "/home/claude/cfront-3/src/dcl2.cpp"
__3i = (signif__4BitsCFv ( (const struct Bits *)(& __3b )) - 1 );
__2found = ((*( (((Pname *)(& ((& __2conv )-> p__11Block_Pname [__3i ]))))) ));
if (count__4BitsCFv ( (const struct Bits *)(& __3b )) == 2 ){ 
# 305 "/home/claude/cfront-3/src/dcl2.cpp"
struct Block_Bits_chunk *__0__X32 ;

# 305 "/home/claude/cfront-3/src/dcl2.cpp"
int __2__X33 ;

# 305 "/home/claude/cfront-3/src/dcl2.cpp"
int __2__X59 ;

# 306 "/home/claude/cfront-3/src/dcl2.cpp"
( ((((unsigned long )__3i )< (& __3b )-> n__4Bits )?(((*( (__0__X32 = (& (& __3b )-> b__4Bits )), ( (__2__X33 =
# 306 "/home/claude/cfront-3/src/dcl2.cpp"
( (((unsigned long )__3i )>> 5)) ), ( (((Bits_chunk *)(& (__0__X32 -> p__16Block_Bits_chunk [__2__X33 ]))))) ) ) ))&= (~
# 306 "/home/claude/cfront-3/src/dcl2.cpp"
((((unsigned long )1 ))<< (((unsigned long )__3i )& 31)))):0 ), (((struct Bits *)(& __3b )))) ;
__2other = ((*( (__2__X59 = (signif__4BitsCFv ( (const struct Bits *)(& __3b )) - 1 )), ( (((Pname *)(& ((& __2conv )->
# 307 "/home/claude/cfront-3/src/dcl2.cpp"
p__11Block_Pname [__2__X59 ]))))) ) ));
}

# 308 "/home/claude/cfront-3/src/dcl2.cpp"
( (((void )(((void )( ( (__0__X36 = (& (& __3b )-> b__4Bits )), ( (__0__X36 ?(((void )( __dl__FPv (
# 308 "/home/claude/cfront-3/src/dcl2.cpp"
(void *)__0__X36 -> p__16Block_Bits_chunk ) , (__0__X36 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 308 "/home/claude/cfront-3/src/dcl2.cpp"
))))) ;
}

# 311 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__2nfound ){ 
# 312 "/home/claude/cfront-3/src/dcl2.cpp"
case 0 :
# 313 "/home/claude/cfront-3/src/dcl2.cpp"
if (__2no_const )
# 314 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 314 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V47 ;

# 314 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V48 ;

# 314 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%nO in%kE (no usable const conversion)", (const struct ea *)( ((& __0__V47 )-> __O1__2ea.p =
# 314 "/home/claude/cfront-3/src/dcl2.cpp"
((const void *)__1cn )), (& __0__V47 )) , (const struct ea *)( (( ((& __0__V48 )-> __O1__2ea.i = ((unsigned
# 314 "/home/claude/cfront-3/src/dcl2.cpp"
long )__1b )), 0 ) ), (& __0__V48 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 314 "/home/claude/cfront-3/src/dcl2.cpp"
} else 
# 315 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 315 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V49 ;

# 315 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V50 ;

# 315 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%nO in%kE", (const struct ea *)( ((& __0__V49 )-> __O1__2ea.p =
# 315 "/home/claude/cfront-3/src/dcl2.cpp"
((const void *)__1cn )), (& __0__V49 )) , (const struct ea *)( (( ((& __0__V50 )-> __O1__2ea.i = ((unsigned
# 315 "/home/claude/cfront-3/src/dcl2.cpp"
long )__1b )), 0 ) ), (& __0__V50 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 315 "/home/claude/cfront-3/src/dcl2.cpp"
} 
# 316 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
case 1 :
# 318 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 319 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __4xx ;
Pexpr __4c ;

# 319 "/home/claude/cfront-3/src/dcl2.cpp"
__4xx = __ct__4nameFPCc ( (struct name *)0 , __2found -> __O2__4expr.string ) ;

# 322 "/home/claude/cfront-3/src/dcl2.cpp"
if (lval__4exprFUc ( __1e , (unsigned char )0 ) ){ 
# 323 "/home/claude/cfront-3/src/dcl2.cpp"
Pref __5r ;
Pexpr __5rr ;

# 325 "/home/claude/cfront-3/src/dcl2.cpp"
struct ref *__0__X60 ;

# 325 "/home/claude/cfront-3/src/dcl2.cpp"
struct expr *__2__X61 ;

# 325 "/home/claude/cfront-3/src/dcl2.cpp"
struct expr *__2__X62 ;

# 323 "/home/claude/cfront-3/src/dcl2.cpp"
__5r = ( (__0__X60 = 0 ), ( (__2__X61 = __1e ), ( (__2__X62 = (struct expr *)__4xx ), ( ((__0__X60 || (__0__X60 =
# 323 "/home/claude/cfront-3/src/dcl2.cpp"
(struct ref *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ref))) ))?( (__0__X60 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X60 ), ((unsigned char
# 323 "/home/claude/cfront-3/src/dcl2.cpp"
)45 ), __2__X61 , (struct expr *)0 ) ), (__0__X60 -> __O4__4expr.mem = __2__X62 )) :0 ), __0__X60 ) ) ) ) ;
# 323 "/home/claude/cfront-3/src/dcl2.cpp"

# 324 "/home/claude/cfront-3/src/dcl2.cpp"
__5rr = typ__4exprFP5table ( (struct expr *)__5r , __1tbl ) ;
__4c = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , __5rr , (struct expr *)0 ) ;
}
else { 
# 330 "/home/claude/cfront-3/src/dcl2.cpp"
Pref __5r ;
Pexpr __5rr ;

# 332 "/home/claude/cfront-3/src/dcl2.cpp"
struct ref *__0__X63 ;

# 332 "/home/claude/cfront-3/src/dcl2.cpp"
struct expr *__2__X64 ;

# 332 "/home/claude/cfront-3/src/dcl2.cpp"
struct expr *__2__X65 ;

# 330 "/home/claude/cfront-3/src/dcl2.cpp"
__5r = ( (__0__X63 = 0 ), ( (__2__X64 = __1e ), ( (__2__X65 = (struct expr *)__4xx ), ( ((__0__X63 || (__0__X63 =
# 330 "/home/claude/cfront-3/src/dcl2.cpp"
(struct ref *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ref))) ))?( (__0__X63 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X63 ), ((unsigned char
# 330 "/home/claude/cfront-3/src/dcl2.cpp"
)45 ), __2__X64 , (struct expr *)0 ) ), (__0__X63 -> __O4__4expr.mem = __2__X65 )) :0 ), __0__X63 ) ) ) ) ;
# 330 "/home/claude/cfront-3/src/dcl2.cpp"

# 331 "/home/claude/cfront-3/src/dcl2.cpp"
__5rr = typ__4exprFP5table ( (struct expr *)__5r , __1tbl ) ;
__4c = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , __5rr , (struct expr *)0 ) ;

# 334 "/home/claude/cfront-3/src/dcl2.cpp"
}
{ Pexpr __4E ;

# 335 "/home/claude/cfront-3/src/dcl2.cpp"
__4E = typ__4exprFP5table ( __4c , __1tbl ) ;
if (memptr__4typeFv ( __4E -> __O1__4expr.tp ) ){ 
# 337 "/home/claude/cfront-3/src/dcl2.cpp"
__4E = make_dot__FP4exprP5tablePCc ( __4E , __1tbl , (const char *)"i")
# 337 "/home/claude/cfront-3/src/dcl2.cpp"
;
__4E = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )63 , __4E , zero ) ;
__4E -> __O1__4expr.tp = (struct type *)int_type ;
}
__1e = __4E ;
break ;

# 342 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
case 2 :
# 346 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 346 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V51 ;

# 346 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V52 ;

# 346 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V53 ;

# 346 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V54 ;

# 346 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"two conversions for%nO in%kE: %n and %n", (const struct ea *)( ((& __0__V51 )-> __O1__2ea.p =
# 346 "/home/claude/cfront-3/src/dcl2.cpp"
((const void *)__1cn )), (& __0__V51 )) , (const struct ea *)( (( ((& __0__V52 )-> __O1__2ea.i = ((unsigned
# 346 "/home/claude/cfront-3/src/dcl2.cpp"
long )__1b )), 0 ) ), (& __0__V52 )) , (const struct ea *)( ((& __0__V53 )-> __O1__2ea.p = ((const
# 346 "/home/claude/cfront-3/src/dcl2.cpp"
void *)__2found )), (& __0__V53 )) , (const struct ea *)( ((& __0__V54 )-> __O1__2ea.p = ((const void *)__2other )),
# 346 "/home/claude/cfront-3/src/dcl2.cpp"
(& __0__V54 )) ) ;
break ;
default :
# 349 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 349 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V55 ;

# 349 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V56 ;

# 349 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"multiple conversions for%nO in%kE", (const struct ea *)( ((& __0__V55 )-> __O1__2ea.p =
# 349 "/home/claude/cfront-3/src/dcl2.cpp"
((const void *)__1cn )), (& __0__V55 )) , (const struct ea *)( (( ((& __0__V56 )-> __O1__2ea.i = ((unsigned
# 349 "/home/claude/cfront-3/src/dcl2.cpp"
long )__1b )), 0 ) ), (& __0__V56 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 349 "/home/claude/cfront-3/src/dcl2.cpp"

# 350 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
} } }
{ 
# 352 "/home/claude/cfront-3/src/dcl2.cpp"
( (((void )( __dl__FPv ( (void *)(& __2conv )-> p__11Block_Pname ) , (((void )(((void
# 352 "/home/claude/cfront-3/src/dcl2.cpp"
)0 ))))) ))) ;

# 352 "/home/claude/cfront-3/src/dcl2.cpp"
return __1e ;
} 
# 352 "/home/claude/cfront-3/src/dcl2.cpp"
}

# 352 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
if (__1e -> __O1__4expr.tp -> base__4node == 108 ){ 
# 355 "/home/claude/cfront-3/src/dcl2.cpp"
__1e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct
# 355 "/home/claude/cfront-3/src/dcl2.cpp"
expr *)0 , __1e ) ;
__1e = typ__4exprFP5table ( __1e , __1tbl ) ;
}
if (memptr__4typeFv ( __1e -> __O1__4expr.tp ) ){ 
# 359 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1b == 33 ){ 
# 360 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"P toM as switchE")
# 360 "/home/claude/cfront-3/src/dcl2.cpp"
;
return __1e ;
}
if ((__1e -> base__4node == 124 )|| (((__1e -> base__4node == 113 )|| (__1e -> base__4node == 191 ))&& (__1e -> __O2__4expr.e1 -> base__4node == 124 )))
# 364 "/home/claude/cfront-3/src/dcl2.cpp"
{
# 364 "/home/claude/cfront-3/src/dcl2.cpp"

# 365 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1e -> base__4node != 124 )
# 366 "/home/claude/cfront-3/src/dcl2.cpp"
__1e = __1e -> __O2__4expr.e1 ;
if (__1e -> __O2__4expr.e1 -> __O3__4expr.e2 != zero )
# 368 "/home/claude/cfront-3/src/dcl2.cpp"
__1e = one ;
else 
# 370 "/home/claude/cfront-3/src/dcl2.cpp"
__1e = zero ;
}
else { 
# 373 "/home/claude/cfront-3/src/dcl2.cpp"
__1e = make_dot__FP4exprP5tablePCc ( __1e , __1tbl , (const char *)"i") ;
# 373 "/home/claude/cfront-3/src/dcl2.cpp"

# 374 "/home/claude/cfront-3/src/dcl2.cpp"
__1e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )63 , __1e , zero ) ;
__1e -> __O1__4expr.tp = (struct type *)int_type ;
}
}
else if (( (__0__X66 = __1e -> __O1__4expr.tp ), ( kind__4typeFUcN21 ( __0__X66 , __1b , (unsigned char )'P' , (unsigned
# 378 "/home/claude/cfront-3/src/dcl2.cpp"
char )1 ) ) ) == 108 )
# 379 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 379 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V57 ;

# 379 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k(F)", (const struct ea *)( (( ((& __0__V57 )->
# 379 "/home/claude/cfront-3/src/dcl2.cpp"
__O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V57 )) , (const struct ea *)ea0 , (const struct
# 379 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return __1e ;

# 380 "/home/claude/cfront-3/src/dcl2.cpp"
}
}

# 383 "/home/claude/cfront-3/src/dcl2.cpp"
void dcl__4stmtFi (struct stmt *__0this , int __1forflag );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 807 "/home/claude/cfront-3/src/cfront.h"
bit not_simple__4exprFi (struct expr *__0this , int __1inflag );

# 1234 "/home/claude/cfront-3/src/cfront.h"
extern Pname make_tmp__FcP4typeP5table (char , Ptype , Ptable );

# 1249 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr mptr_assign__FP4exprT1 (Pexpr , Pexpr );

# 738 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ref_init__FP3ptrP4exprP5table (Pptr , Pexpr , Ptable );

# 122 "/home/claude/cfront-3/src/cfront.h"
extern int is_probably_temp__FPCc (const char *);

# 1223 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr replace_temp__FP4exprT1 (Pexpr , Pexpr );

# 804 "/home/claude/cfront-3/src/cfront.h"
Pexpr contents__4exprFv (struct expr *__0this );

# 739 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr class_init__FP4exprP4typeT1P5table (Pexpr , Ptype , Pexpr , Ptable );

# 468 "/home/claude/cfront-3/src/cfront.h"

# 1227 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ptr_init__FP3ptrP4exprP5table (Pptr , Pexpr , Ptable );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 1155 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr try_to_coerce__FP4typeP4exprPCcP5table (Ptype , Pexpr , const char *, Ptable );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 354 "/home/claude/cfront-3/src/cfront.h"

# 799 "/home/claude/cfront-3/src/cfront.h"
long long eval__4exprFv (struct expr *__0this );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 943 "/home/claude/cfront-3/src/cfront.h"
void assign__4nameFv (struct name *__0this );

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 1012 "/home/claude/cfront-3/src/cfront.h"
void del__4stmtFv (struct stmt *__0this );

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 466 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 220 "/home/claude/cfront-3/src/cfront.h"
struct table *__ct__5tableFsP5tableP4name (struct table *__0this , short , Ptable , Pname );

# 1071 "/home/claude/cfront-3/src/cfront.h"
void dcl__5blockFP5table (struct block *__0this , Ptable );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 940 "/home/claude/cfront-3/src/cfront.h"
Pname dcl__4nameFP5tableUc (struct name *__0this , Ptable , TOK );

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 1010 "/home/claude/cfront-3/src/cfront.h"

# 1025 "/home/claude/cfront-3/src/cfront.h"

# 383 "/home/claude/cfront-3/src/dcl2.cpp"
void dcl__4stmtFi (register struct stmt *__0this , int __1forflag )
# 387 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 388 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __1ss ;
Pname __1n ;
Pname __1nn ;
Pstmt __1ostmt ;

# 391 "/home/claude/cfront-3/src/dcl2.cpp"
__1ostmt = Cstmt ;
;
for(__1ss = __0this ;__1ss ;__1ss = __1ss -> s_list__4stmt ) { 
# 394 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __2old_loop ;

# 394 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __2old_switch ;
Cstmt = __1ss ;
{ Ptable __2tbl ;

# 396 "/home/claude/cfront-3/src/dcl2.cpp"
__2tbl = curr_block -> memtbl__4stmt ;

# 398 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__1ss -> base__4node ){ 
# 398 "/home/claude/cfront-3/src/dcl2.cpp"
struct type *__0__X92 ;

# 398 "/home/claude/cfront-3/src/dcl2.cpp"
unsigned long __2__X95 ;

# 398 "/home/claude/cfront-3/src/dcl2.cpp"
unsigned long __2__X106 ;

# 399 "/home/claude/cfront-3/src/dcl2.cpp"
case 3 :
# 400 "/home/claude/cfront-3/src/dcl2.cpp"
inline_restr |= 16 ;
if ((curr_loop == 0 )&& (curr_switch == 0 ))
# 402 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"break not in loop or switch") ;
reached__4stmtFv ( __1ss ) ;
break ;

# 406 "/home/claude/cfront-3/src/dcl2.cpp"
case 7 :
# 407 "/home/claude/cfront-3/src/dcl2.cpp"
inline_restr |= 32 ;
if (curr_loop == 0 )
# 409 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"continue not in loop") ;
reached__4stmtFv ( __1ss ) ;
break ;

# 413 "/home/claude/cfront-3/src/dcl2.cpp"
case 8 :
# 414 "/home/claude/cfront-3/src/dcl2.cpp"
if (curr_switch == 0 ){ 
# 415 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"default not in switch") ;
break ;
}
if (curr_switch -> __O1__4stmt.has_default )
# 419 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"two defaults in switch") ;
curr_case = __1ss ;
block_since_case = 0 ;
curr_switch -> __O1__4stmt.has_default = __1ss ;
__1ss -> s__4stmt -> s_list__4stmt = __1ss -> s_list__4stmt ;
__1ss -> s_list__4stmt = 0 ;
dcl__4stmtFi ( __1ss -> s__4stmt , 0 ) ;
break ;

# 428 "/home/claude/cfront-3/src/dcl2.cpp"
case 72 :
# 429 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 430 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> __O2__4stmt.e == 0 )
# 431 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
{ TOK __4b ;

# 432 "/home/claude/cfront-3/src/dcl2.cpp"
__4b = __1ss -> __O2__4stmt.e -> base__4node ;
switch (__4b ){ 
# 434 "/home/claude/cfront-3/src/dcl2.cpp"
case 144 :
# 435 "/home/claude/cfront-3/src/dcl2.cpp"
case 162 :
# 436 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O2__4stmt.e = 0 ;
break ;

# 442 "/home/claude/cfront-3/src/dcl2.cpp"
case 62 :
# 443 "/home/claude/cfront-3/src/dcl2.cpp"
case 63 :
# 444 "/home/claude/cfront-3/src/dcl2.cpp"
case 60 :
# 445 "/home/claude/cfront-3/src/dcl2.cpp"
case 61 :
# 446 "/home/claude/cfront-3/src/dcl2.cpp"
case 58 :
# 447 "/home/claude/cfront-3/src/dcl2.cpp"
case 59 :
# 448 "/home/claude/cfront-3/src/dcl2.cpp"
case 54 :
# 449 "/home/claude/cfront-3/src/dcl2.cpp"
case 55 :
# 450 "/home/claude/cfront-3/src/dcl2.cpp"
case 44 :
# 451 "/home/claude/cfront-3/src/dcl2.cpp"
case 45 :
# 452 "/home/claude/cfront-3/src/dcl2.cpp"
case 50 :
# 453 "/home/claude/cfront-3/src/dcl2.cpp"
case 51 :
# 454 "/home/claude/cfront-3/src/dcl2.cpp"
case 112 :
# 455 "/home/claude/cfront-3/src/dcl2.cpp"
case
# 455 "/home/claude/cfront-3/src/dcl2.cpp"
52 :
# 456 "/home/claude/cfront-3/src/dcl2.cpp"
case 65 :
# 457 "/home/claude/cfront-3/src/dcl2.cpp"
case 64 :
# 458 "/home/claude/cfront-3/src/dcl2.cpp"
case 111 :
# 459 "/home/claude/cfront-3/src/dcl2.cpp"
case 66 :
# 460 "/home/claude/cfront-3/src/dcl2.cpp"
case 67 :
# 461 "/home/claude/cfront-3/src/dcl2.cpp"
case 85 :
# 462 "/home/claude/cfront-3/src/dcl2.cpp"
case 157 :
# 463 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> __O2__4stmt.e -> __O1__4expr.tp )
# 464 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
__1ss -> __O2__4stmt.e = typ__4exprFP5table ( __1ss -> __O2__4stmt.e , __2tbl ) ;
if (__1ss -> __O2__4stmt.e -> base__4node == 109 )
# 467 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
if (__1ss -> __O2__4stmt.e -> __O1__4expr.tp -> base__4node != 38 ){ 
# 468 "/home/claude/cfront-3/src/dcl2.cpp"
const void *__2__X87 ;

# 469 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> __O2__4stmt.e -> base__4node == 111 )
# 470 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 470 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V67 ;

# 470 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"result of %sE not used", (const struct ea *)( (__2__X87 =
# 470 "/home/claude/cfront-3/src/dcl2.cpp"
(const void *)(__1ss -> __O2__4stmt.e -> __O3__4expr.e2 ?"[]":(((char *)"*")))),
# 470 "/home/claude/cfront-3/src/dcl2.cpp"
( ((& __0__V67 )-> __O1__2ea.p = __2__X87 ), (& __0__V67 )) ) , (const struct ea *)ea0 , (const struct
# 470 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 472 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 472 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V68 ;

# 472 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"result of%kE not used", (const struct ea *)( ((
# 472 "/home/claude/cfront-3/src/dcl2.cpp"
((& __0__V68 )-> __O1__2ea.i = ((unsigned long )__4b )), 0 ) ), (& __0__V68 )) , (const struct ea *)ea0 ,
# 472 "/home/claude/cfront-3/src/dcl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
if ((__1ss -> __O2__4stmt.e -> base__4node == 85 )&& (__1ss -> __O2__4stmt.e -> __O1__4expr.tp -> base__4node == 108 ))
# 474 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 475 "/home/claude/cfront-3/src/dcl2.cpp"
int __8i ;

# 475 "/home/claude/cfront-3/src/dcl2.cpp"
__8i = (((struct name *)(((struct name *)__1ss -> __O2__4stmt.e ))))-> n_addr_taken__4name ;
(((struct name *)(((struct name *)__1ss -> __O2__4stmt.e ))))-> n_addr_taken__4name = 1 ;
dcl_print__4nameFUc ( ((struct name *)(((struct name *)__1ss -> __O2__4stmt.e ))), (unsigned char )0 ) ;
(((struct name *)(((struct name *)__1ss -> __O2__4stmt.e ))))-> n_addr_taken__4name = __8i ;
}
} }
if (not_simple__4exprFi ( __1ss -> __O2__4stmt.e , 0 ) == 0 )
# 482 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O2__4stmt.e = dummy ;
}
if (__1ss -> __O2__4stmt.e -> base__4node == 124 ){ 
# 485 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __6tt ;

# 485 "/home/claude/cfront-3/src/dcl2.cpp"
__6tt = make_tmp__FcP4typeP5table ( 'A' , (struct type *)mptr_type , __2tbl ) ;
__1ss -> __O2__4stmt.e = mptr_assign__FP4exprT1 ( (struct expr *)__6tt , __1ss -> __O2__4stmt.e ) ;
}
break ;
default :
# 490 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O2__4stmt.e = typ__4exprFP5table ( __1ss -> __O2__4stmt.e , __2tbl ) ;
}
break ;

# 492 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
case 28 :
# 495 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 496 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __4fn ;
Pfct __4f ;
Ptype __4rt ;
Pexpr __4v ;

# 496 "/home/claude/cfront-3/src/dcl2.cpp"
__4fn = cc -> nof__11dcl_context ;
__4f = (((struct fct *)(((struct fct *)__4fn -> __O1__4expr.tp ))));
__4rt = skiptypedefs__4typeFv ( __4f -> returns__3fct ) ;
__4v = __1ss -> __O2__4stmt.e ;

# 501 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4v != dummy ){ 
# 502 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4rt -> base__4node == 158 ){ 
# 503 "/home/claude/cfront-3/src/dcl2.cpp"
ref_initializer ++ ;
__4v = typ__4exprFP5table ( __4v , __2tbl ) ;
ref_initializer -- ;
}
else __4v = typ__4exprFP5table ( __4v , __2tbl ) ;

# 509 "/home/claude/cfront-3/src/dcl2.cpp"
if (((__4fn -> n_oper__4name == 161 )|| (__4fn -> n_oper__4name == 162 ))|| (__4rt -> base__4node == 38 ))
# 515 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 516 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"unexpected return value")
# 516 "/home/claude/cfront-3/src/dcl2.cpp"
;

# 518 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O2__4stmt.e = dummy ;
}
else { 
# 521 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__4rt -> base__4node ){ 
# 522 "/home/claude/cfront-3/src/dcl2.cpp"
case 158 :
# 523 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__4v -> base__4node ){ 
# 524 "/home/claude/cfront-3/src/dcl2.cpp"
case 85 :
# 525 "/home/claude/cfront-3/src/dcl2.cpp"
if (((((struct name *)(((struct name *)__4v ))))->
# 525 "/home/claude/cfront-3/src/dcl2.cpp"
n_scope__4name == 108 )|| ((((struct name *)(((struct name *)__4v ))))-> n_scope__4name == 136 ))
# 530 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCc ( (int )'w' , (const char *)"R to localV returned")
# 530 "/home/claude/cfront-3/src/dcl2.cpp"
;
break ;
case 82 :
# 533 "/home/claude/cfront-3/src/dcl2.cpp"
case 84 :
# 534 "/home/claude/cfront-3/src/dcl2.cpp"
case 83 :
# 535 "/home/claude/cfront-3/src/dcl2.cpp"
case 81 :
# 536 "/home/claude/cfront-3/src/dcl2.cpp"
if (tconst__4typeFv ( (((struct ptr *)(((struct ptr *)__4rt ))))-> typ__5pvtyp ) == 0 )
# 537 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCc ( (int )'w' ,
# 537 "/home/claude/cfront-3/src/dcl2.cpp"
(const char *)"R to literal returned") ;
}
in_return = 1 ;
__4v = ref_init__FP3ptrP4exprP5table ( ((struct ptr *)(((struct ptr *)__4rt ))), __4v , __2tbl ) ;
in_return = 0 ;
if ((((__4v -> base__4node == 147 )&& (__4v -> __O3__4expr.e2 -> base__4node == 145 ))&& (__4v -> __O3__4expr.e2 -> __O3__4expr.e2 -> base__4node == 85 ))&& is_probably_temp__FPCc (
# 542 "/home/claude/cfront-3/src/dcl2.cpp"
__4v -> __O3__4expr.e2 -> __O3__4expr.e2 -> __O2__4expr.string ) )
# 551 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCc ( (int )'w' , (const char *)"R to temporary returned (return value is not lvalue or of wrongT)")
# 551 "/home/claude/cfront-3/src/dcl2.cpp"
;
case 141 :
# 553 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
case 119 :
# 555 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4v -> base__4node == 111 ){ 
# 556 "/home/claude/cfront-3/src/dcl2.cpp"
Pexpr __8v1 ;

# 556 "/home/claude/cfront-3/src/dcl2.cpp"
__8v1 = __4v -> __O2__4expr.e1 ;
if ((__8v1 -> base__4node == 113 )|| (__8v1 -> base__4node == 191 ))
# 558 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 559 "/home/claude/cfront-3/src/dcl2.cpp"
Pexpr __9v2 ;

# 559 "/home/claude/cfront-3/src/dcl2.cpp"
__9v2 = __8v1 -> __O2__4expr.e1 ;
if (__9v2 -> base__4node == 147 ){ 
# 562 "/home/claude/cfront-3/src/dcl2.cpp"
Pexpr __10v3 ;

# 562 "/home/claude/cfront-3/src/dcl2.cpp"
__10v3 = __9v2 -> __O3__4expr.e2 ;
__9v2 -> __O3__4expr.e2 = __4v ;
__9v2 -> __O1__4expr.tp = __4v -> __O1__4expr.tp ;
__4v = __9v2 ;
__8v1 -> __O2__4expr.e1 = __10v3 ;
}
}
}
if (__4f -> f_result__3fct ){ 
# 571 "/home/claude/cfront-3/src/dcl2.cpp"
if ((__4v -> base__4node == 147 )&& (check__4typeFP4typeUcT2 ( __4rt , __4v -> __O1__4expr.tp , (unsigned char )0 ,
# 571 "/home/claude/cfront-3/src/dcl2.cpp"
(unsigned char )0 ) == 0 ))
# 576 "/home/claude/cfront-3/src/dcl2.cpp"
__4v = replace_temp__FP4exprT1 ( __4v , (struct expr *)__4f -> f_result__3fct ) ;
else { 
# 578 "/home/claude/cfront-3/src/dcl2.cpp"
if (! __4f -> nrv__3fct )
# 579 "/home/claude/cfront-3/src/dcl2.cpp"
__4v = class_init__FP4exprP4typeT1P5table ( contents__4exprFv ( (struct expr *)__4f -> f_result__3fct ) , __4rt , __4v ,
# 579 "/home/claude/cfront-3/src/dcl2.cpp"
__2tbl ) ;
{ Pname __9rcn ;

# 581 "/home/claude/cfront-3/src/dcl2.cpp"
struct classdef *__0__X88 ;

# 580 "/home/claude/cfront-3/src/dcl2.cpp"
__9rcn = is_cl_obj__4typeFv ( __4rt ) ;
if (( (__0__X88 = (((struct classdef *)(((struct classdef *)__9rcn -> __O1__4expr.tp ))))), ( __0__X88 -> c_itor__8classdef ) ) == 0 ){ 
# 583 "/home/claude/cfront-3/src/dcl2.cpp"
__4v ->
# 583 "/home/claude/cfront-3/src/dcl2.cpp"
__O1__4expr.tp = __4rt ;
__4v = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , contents__4exprFv ( (struct expr *)__4f -> f_result__3fct ) , __4v ) ;
# 584 "/home/claude/cfront-3/src/dcl2.cpp"

# 585 "/home/claude/cfront-3/src/dcl2.cpp"
__4v -> __O1__4expr.tp = __4rt ;
}

# 586 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
}
else 
# 590 "/home/claude/cfront-3/src/dcl2.cpp"
__4v = class_init__FP4exprP4typeT1P5table ( (struct expr *)0 , __4rt , __4v , __2tbl ) ;
break ;

# 593 "/home/claude/cfront-3/src/dcl2.cpp"
case 125 :
# 594 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 594 "/home/claude/cfront-3/src/dcl2.cpp"
const void *__2__X89 ;

# 594 "/home/claude/cfront-3/src/dcl2.cpp"
__4v = ptr_init__FP3ptrP4exprP5table ( ((struct ptr *)(((struct ptr *)__4rt ))), __4v , __2tbl ) ;
if (((__4v -> base__4node == 112 )&& (__4v -> __O3__4expr.e2 -> base__4node == 85 ))&& ((((struct name *)(((struct name *)__4v -> __O3__4expr.e2 ))))-> n_stclass__4name == 2 ))
# 602 "/home/claude/cfront-3/src/dcl2.cpp"
{
# 602 "/home/claude/cfront-3/src/dcl2.cpp"

# 602 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V69 ;

# 602 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"P to local variable%n returned", (const struct ea *)( (__2__X89 =
# 602 "/home/claude/cfront-3/src/dcl2.cpp"
(const void *)(((struct name *)(((struct name *)__4v -> __O3__4expr.e2 ))))), ( ((& __0__V69 )-> __O1__2ea.p = __2__X89 ), (& __0__V69 )) )
# 602 "/home/claude/cfront-3/src/dcl2.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (Pchecked == 0 )
# 604 "/home/claude/cfront-3/src/dcl2.cpp"
goto def ;
goto ret_save ;
}

# 608 "/home/claude/cfront-3/src/dcl2.cpp"
case 21 :
# 609 "/home/claude/cfront-3/src/dcl2.cpp"
case 5 :
# 610 "/home/claude/cfront-3/src/dcl2.cpp"
case 22 :
# 611 "/home/claude/cfront-3/src/dcl2.cpp"
case 122 :
# 612 "/home/claude/cfront-3/src/dcl2.cpp"
case 29 :
# 613 "/home/claude/cfront-3/src/dcl2.cpp"
if (((((struct basetype *)(((struct basetype *)__4rt ))))-> b_unsigned__8basetype && (__4v -> base__4node == 107 ))&& (__4v ->
# 613 "/home/claude/cfront-3/src/dcl2.cpp"
__O3__4expr.e2 -> base__4node == 82 ))
# 620 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCc ( (int )'w' , (const char *)"negative returned fromF returning unsigned") ;
default :
# 622 "/home/claude/cfront-3/src/dcl2.cpp"
def :
# 623 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 624 "/home/claude/cfront-3/src/dcl2.cpp"
Pexpr __8x ;
int __8ct ;

# 624 "/home/claude/cfront-3/src/dcl2.cpp"
__8x = try_to_coerce__FP4typeP4exprPCcP5table ( __4rt , __4v , (const char *)"return value", __2tbl ) ;
__8ct = no_const ;
if (__8x )
# 627 "/home/claude/cfront-3/src/dcl2.cpp"
__4v = __8x ;
else if (check__4typeFP4typeUcT2 ( __4rt , __4v -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) ){ 
# 629 "/home/claude/cfront-3/src/dcl2.cpp"
{
# 629 "/home/claude/cfront-3/src/dcl2.cpp"

# 629 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V70 ;

# 629 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V71 ;

# 629 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V72 ;

# 629 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"bad return valueT for%n:%t (%tX)", (const struct ea *)( ((&
# 629 "/home/claude/cfront-3/src/dcl2.cpp"
__0__V70 )-> __O1__2ea.p = ((const void *)__4fn )), (& __0__V70 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V71 , (const
# 629 "/home/claude/cfront-3/src/dcl2.cpp"
void *)__4v -> __O1__4expr.tp ) , (const struct ea *)( ((& __0__V72 )-> __O1__2ea.p = ((const void *)__4rt )), (&
# 629 "/home/claude/cfront-3/src/dcl2.cpp"
__0__V72 )) , (const struct ea *)ea0 ) ;
if (__8ct )error__FiPCc ( (int )'c' , (const char *)" (no usable const conversion)\n") ;
else error__FiPCc ( (int )'c' , (const char *)"\n") ;
} }
break ;
}

# 636 "/home/claude/cfront-3/src/dcl2.cpp"
}
ret_save :
# 638 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O1__4stmt.ret_tp = __4rt ;
__1ss -> __O2__4stmt.e = __4v ;
}
}
else { 
# 643 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4rt -> base__4node != 38 )
# 644 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"return valueX") ;
# 644 "/home/claude/cfront-3/src/dcl2.cpp"

# 645 "/home/claude/cfront-3/src/dcl2.cpp"
}
reached__4stmtFv ( __1ss ) ;
break ;
}

# 650 "/home/claude/cfront-3/src/dcl2.cpp"
case 10 :
# 651 "/home/claude/cfront-3/src/dcl2.cpp"
inline_restr |= 8 ;
__2old_loop = curr_loop ;
curr_loop = __1ss ;
{ 
# 655 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __4st ;

# 655 "/home/claude/cfront-3/src/dcl2.cpp"
__4st = __1ss -> s__4stmt ;
while (__4st && (__4st -> base__4node == 16 ))
# 657 "/home/claude/cfront-3/src/dcl2.cpp"
__4st = __4st -> __O3__4stmt.for_init ;
if (__4st && (__4st -> base__4node == 118 ))
# 659 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4st == __1ss -> s__4stmt )
# 660 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"D as onlyS in do-loop")
# 660 "/home/claude/cfront-3/src/dcl2.cpp"
;
}
dcl__4stmtFi ( __1ss -> s__4stmt , 0 ) ;
__1ss -> __O2__4stmt.e = typ__4exprFP5table ( __1ss -> __O2__4stmt.e , __2tbl ) ;
__1ss -> __O2__4stmt.e = check_cond__FP4exprUcP5table ( __1ss -> __O2__4stmt.e , (unsigned char )10 , __2tbl ) ;
curr_loop = __2old_loop ;
break ;

# 668 "/home/claude/cfront-3/src/dcl2.cpp"
case 39 :
# 669 "/home/claude/cfront-3/src/dcl2.cpp"
inline_restr |= 8 ;
__2old_loop = curr_loop ;
curr_loop = __1ss ;
__1ss -> __O2__4stmt.e = typ__4exprFP5table ( __1ss -> __O2__4stmt.e , __2tbl ) ;
__1ss -> __O2__4stmt.e = check_cond__FP4exprUcP5table ( __1ss -> __O2__4stmt.e , (unsigned char )39 , __2tbl ) ;
{ 
# 675 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __4st ;

# 675 "/home/claude/cfront-3/src/dcl2.cpp"
__4st = __1ss -> s__4stmt ;
while (__4st && (__4st -> base__4node == 16 ))
# 677 "/home/claude/cfront-3/src/dcl2.cpp"
__4st = __4st -> __O3__4stmt.for_init ;
if (__4st && (__4st -> base__4node == 118 ))
# 679 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4st == __1ss -> s__4stmt )
# 680 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"D as onlyS in while-loop")
# 680 "/home/claude/cfront-3/src/dcl2.cpp"
;
}
dcl__4stmtFi ( __1ss -> s__4stmt , 0 ) ;
curr_loop = __2old_loop ;
break ;

# 686 "/home/claude/cfront-3/src/dcl2.cpp"
case 33 :
# 687 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 688 "/home/claude/cfront-3/src/dcl2.cpp"
int __4ne ;
Pstmt __4old_case ;
Pblock __4old_bsc ;

# 688 "/home/claude/cfront-3/src/dcl2.cpp"
__4ne = 0 ;
__4old_case = curr_case ;
__4old_bsc = block_since_case ;
curr_case = 0 ;

# 691 "/home/claude/cfront-3/src/dcl2.cpp"
block_since_case = 0 ;
inline_restr |= 4 ;
__2old_switch = curr_switch ;
curr_switch = __1ss ;
__1ss -> __O2__4stmt.e = typ__4exprFP5table ( __1ss -> __O2__4stmt.e , __2tbl ) ;
__1ss -> __O2__4stmt.e = check_cond__FP4exprUcP5table ( __1ss -> __O2__4stmt.e , (unsigned char )33 , __2tbl ) ;
{ 
# 698 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __5st ;

# 698 "/home/claude/cfront-3/src/dcl2.cpp"
__5st = __1ss -> s__4stmt ;
while (__5st && (__5st -> base__4node == 16 ))
# 700 "/home/claude/cfront-3/src/dcl2.cpp"
__5st = __5st -> __O3__4stmt.for_init ;
if (__5st && (__5st -> base__4node == 118 ))
# 702 "/home/claude/cfront-3/src/dcl2.cpp"
if (__5st == __1ss -> s__4stmt )
# 703 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"D as onlyS in switchS")
# 703 "/home/claude/cfront-3/src/dcl2.cpp"
;
}
{ 
# 706 "/home/claude/cfront-3/src/dcl2.cpp"
Ptype __5tt ;

# 706 "/home/claude/cfront-3/src/dcl2.cpp"
__5tt = skiptypedefs__4typeFv ( __1ss -> __O2__4stmt.e -> __O1__4expr.tp ) ;

# 708 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__5tt -> base__4node ){ 
# 708 "/home/claude/cfront-3/src/dcl2.cpp"
const void *__2__X90 ;

# 709 "/home/claude/cfront-3/src/dcl2.cpp"
case 121 :
# 710 "/home/claude/cfront-3/src/dcl2.cpp"
__4ne = (((struct enumdef *)(((struct enumdef *)(((struct basetype *)(((struct basetype *)__5tt ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> no_of_enumerators__7enumdef ;
case 138 :
# 712 "/home/claude/cfront-3/src/dcl2.cpp"
case 141 :
# 713 "/home/claude/cfront-3/src/dcl2.cpp"
case 5 :
# 714 "/home/claude/cfront-3/src/dcl2.cpp"
case 29 :
# 715 "/home/claude/cfront-3/src/dcl2.cpp"
case 21 :
# 716 "/home/claude/cfront-3/src/dcl2.cpp"
case 22 :
# 717 "/home/claude/cfront-3/src/dcl2.cpp"
case 122 :
# 718 "/home/claude/cfront-3/src/dcl2.cpp"
case 114 :
# 719 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
default :
# 721 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 721 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V73 ;

# 721 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t switchE", (const struct ea *)( (__2__X90 = (const void
# 721 "/home/claude/cfront-3/src/dcl2.cpp"
*)__1ss -> __O2__4stmt.e -> __O1__4expr.tp ), ( ((& __0__V73 )-> __O1__2ea.p = __2__X90 ), (& __0__V73 )) ) , (const struct
# 721 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
dcl__4stmtFi ( __1ss -> s__4stmt , 0 ) ;
if (__4ne ){ 
# 727 "/home/claude/cfront-3/src/dcl2.cpp"
int __5i ;
Pstmt __5cs ;

# 727 "/home/claude/cfront-3/src/dcl2.cpp"
__5i = 0 ;

# 729 "/home/claude/cfront-3/src/dcl2.cpp"
for(__5cs = __1ss -> __O3__4stmt.case_list ;__5cs ;__5cs = __5cs -> __O3__4stmt.case_list ) 
# 730 "/home/claude/cfront-3/src/dcl2.cpp"
__5i ++ ;
if (__5i && (__5i != __4ne )){ 
# 732 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4ne < __5i ){ 
# 732 "/home/claude/cfront-3/src/dcl2.cpp"
const void *__2__X91 ;

# 733 "/home/claude/cfront-3/src/dcl2.cpp"
ee :if (__1ss -> __O1__4stmt.has_default == 0 ){ 
# 733 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V74 ;

# 733 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V75 ;

# 733 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V76 ;

# 733 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"switch (%t)W %d cases (%d enumerators)", (const struct ea *)( (__2__X91 =
# 733 "/home/claude/cfront-3/src/dcl2.cpp"
(const void *)__1ss -> __O2__4stmt.e -> __O1__4expr.tp ), ( ((& __0__V74 )-> __O1__2ea.p = __2__X91 ), (& __0__V74 )) ) ,
# 733 "/home/claude/cfront-3/src/dcl2.cpp"
(const struct ea *)( (( ((& __0__V75 )-> __O1__2ea.i = ((unsigned long )__5i )), 0 ) ), (& __0__V75 ))
# 733 "/home/claude/cfront-3/src/dcl2.cpp"
, (const struct ea *)( (( ((& __0__V76 )-> __O1__2ea.i = ((unsigned long )__4ne )), 0 ) ), (&
# 733 "/home/claude/cfront-3/src/dcl2.cpp"
__0__V76 )) , (const struct ea *)ea0 ) ;
} }
else { 
# 736 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__4ne - __5i ){ 
# 737 "/home/claude/cfront-3/src/dcl2.cpp"
case 1 :if (3 < __4ne )goto ee ;
case 2 :if (7 < __4ne )goto ee ;
case 3 :if (23 < __4ne )goto ee ;
case 4 :if (60 < __4ne )goto ee ;
case 5 :if (99 < __4ne )goto ee ;
}
}
}
}
curr_switch = __2old_switch ;
curr_case = __4old_case ;
block_since_case = __4old_bsc ;
break ;
}

# 752 "/home/claude/cfront-3/src/dcl2.cpp"
case 4 :
# 753 "/home/claude/cfront-3/src/dcl2.cpp"
if (curr_switch == 0 ){ 
# 754 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"case not in switch") ;
break ;
}
curr_case = __1ss ;
block_since_case = 0 ;
__1ss -> __O2__4stmt.e = typ__4exprFP5table ( __1ss -> __O2__4stmt.e , __2tbl ) ;
( (__0__X92 = __1ss -> __O2__4stmt.e -> __O1__4expr.tp ), ( kind__4typeFUcN21 ( __0__X92 , ((unsigned char )4 ), (unsigned char )'P' ,
# 760 "/home/claude/cfront-3/src/dcl2.cpp"
(unsigned char )1 ) ) ) ;
{ 
# 762 "/home/claude/cfront-3/src/dcl2.cpp"
Ptype __4tt ;

# 762 "/home/claude/cfront-3/src/dcl2.cpp"
__4tt = skiptypedefs__4typeFv ( __1ss -> __O2__4stmt.e -> __O1__4expr.tp ) ;

# 764 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__4tt -> base__4node ){ 
# 764 "/home/claude/cfront-3/src/dcl2.cpp"
const void *__2__X94 ;

# 765 "/home/claude/cfront-3/src/dcl2.cpp"
case 138 :
# 766 "/home/claude/cfront-3/src/dcl2.cpp"
case 141 :
# 767 "/home/claude/cfront-3/src/dcl2.cpp"
case 5 :
# 768 "/home/claude/cfront-3/src/dcl2.cpp"
case 29 :
# 769 "/home/claude/cfront-3/src/dcl2.cpp"
case 21 :
# 770 "/home/claude/cfront-3/src/dcl2.cpp"
case 22 :
# 771 "/home/claude/cfront-3/src/dcl2.cpp"
case 122 :
# 772 "/home/claude/cfront-3/src/dcl2.cpp"
case 121 :
# 773 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 774 "/home/claude/cfront-3/src/dcl2.cpp"
Neval = 0 ;
{ long long __6i ;

# 776 "/home/claude/cfront-3/src/dcl2.cpp"
const void *__2__X93 ;

# 775 "/home/claude/cfront-3/src/dcl2.cpp"
__6i = eval__4exprFv ( __1ss -> __O2__4stmt.e ) ;
if (Neval == 0 ){ 
# 777 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __7cs ;
if (largest_int < __6i )
# 779 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"long case value") ;
for(__7cs = curr_switch -> __O3__4stmt.case_list ;__7cs ;__7cs = __7cs -> __O3__4stmt.case_list ) { 
# 781 "/home/claude/cfront-3/src/dcl2.cpp"
if (__7cs -> __O1__4stmt.case_value == __6i )
# 782 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 782 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V77 ;

# 782 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"case %d used twice in switch", (const struct ea *)( (( ((& __0__V77 )->
# 782 "/home/claude/cfront-3/src/dcl2.cpp"
__O1__2ea.i = ((unsigned long )__6i )), 0 ) ), (& __0__V77 )) , (const struct ea *)ea0 , (const struct
# 782 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} }
__1ss -> __O1__4stmt.case_value = (((int )__6i ));
__1ss -> __O3__4stmt.case_list = curr_switch -> __O3__4stmt.case_list ;
curr_switch -> __O3__4stmt.case_list = __1ss ;
}
else 
# 789 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 789 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V78 ;

# 789 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad case label: %s", (const struct ea *)( (__2__X93 = (const void
# 789 "/home/claude/cfront-3/src/dcl2.cpp"
*)Neval ), ( ((& __0__V78 )-> __O1__2ea.p = __2__X93 ), (& __0__V78 )) ) , (const struct ea *)ea0 , (const
# 789 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} break ;

# 790 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
default :
# 793 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 793 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V79 ;

# 793 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t caseE", (const struct ea *)( (__2__X94 = (const void
# 793 "/home/claude/cfront-3/src/dcl2.cpp"
*)__1ss -> __O2__4stmt.e -> __O1__4expr.tp ), ( ((& __0__V79 )-> __O1__2ea.p = __2__X94 ), (& __0__V79 )) ) , (const struct
# 793 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
if (__1ss -> s__4stmt -> s_list__4stmt )
# 797 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 797 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V80 ;

# 797 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"case%k", (const struct ea *)( (__2__X95 =
# 797 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> s__4stmt -> s_list__4stmt -> base__4node ), ( (( ((& __0__V80 )-> __O1__2ea.i = __2__X95 ), 0 ) ), (& __0__V80 ))
# 797 "/home/claude/cfront-3/src/dcl2.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __1ss -> s__4stmt -> s_list__4stmt = __1ss -> s_list__4stmt ;
__1ss -> s_list__4stmt = 0 ;
dcl__4stmtFi ( __1ss -> s__4stmt , 0 ) ;
break ;

# 803 "/home/claude/cfront-3/src/dcl2.cpp"
case 19 :
# 804 "/home/claude/cfront-3/src/dcl2.cpp"
inline_restr |= 2 ;
reached__4stmtFv ( __1ss ) ;

# 807 "/home/claude/cfront-3/src/dcl2.cpp"
case 115 :
# 810 "/home/claude/cfront-3/src/dcl2.cpp"
__1n = __1ss -> __O1__4stmt.d ;
__1nn = insert__5tableFP4nameUc ( cc -> ftbl__11dcl_context , __1n , (unsigned char )115 ) ;

# 816 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> base__4node == 115 ){ 
# 817 "/home/claude/cfront-3/src/dcl2.cpp"
__1nn -> __O2__4name.n_realscope = curr_block -> memtbl__4stmt ;
inline_restr |= 1 ;
}

# 821 "/home/claude/cfront-3/src/dcl2.cpp"
if (Nold ){ 
# 822 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> base__4node == 115 ){ 
# 823 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1nn -> __O3__4expr.n_initializer )
# 824 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 824 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V81 ;

# 824 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of label%n", (const struct ea *)( ((& __0__V81 )-> __O1__2ea.p =
# 824 "/home/claude/cfront-3/src/dcl2.cpp"
((const void *)__1n )), (& __0__V81 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 824 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 ) ;
} __1nn -> __O3__4expr.n_initializer = (((struct expr *)1 ));
}
if (__1n != __1nn )
# 828 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O1__4stmt.d = __1nn ;
}
else { 
# 831 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> base__4node == 115 )
# 832 "/home/claude/cfront-3/src/dcl2.cpp"
__1nn -> __O3__4expr.n_initializer = (((struct expr *)1 ));
__1nn -> where__4name = __1ss -> where__4stmt ;
}
if (__1ss -> base__4node == 19 )
# 836 "/home/claude/cfront-3/src/dcl2.cpp"
( (__1nn -> n_used__4name ++ ), (((void )0 ))) ;
else { 
# 837 "/home/claude/cfront-3/src/dcl2.cpp"
unsigned long __2__X96 ;

# 838 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> s__4stmt -> s_list__4stmt )
# 839 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 839 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V82 ;

# 839 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"label%k", (const struct ea *)( (__2__X96 =
# 839 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> s__4stmt -> s_list__4stmt -> base__4node ), ( (( ((& __0__V82 )-> __O1__2ea.i = __2__X96 ), 0 ) ), (& __0__V82 ))
# 839 "/home/claude/cfront-3/src/dcl2.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __1ss -> s__4stmt -> s_list__4stmt = __1ss -> s_list__4stmt ;
__1ss -> s_list__4stmt = 0 ;
assign__4nameFv ( __1nn ) ;
}
if (__1ss -> s__4stmt )
# 845 "/home/claude/cfront-3/src/dcl2.cpp"
dcl__4stmtFi ( __1ss -> s__4stmt , 0 ) ;
break ;

# 848 "/home/claude/cfront-3/src/dcl2.cpp"
case 20 :
# 849 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 850 "/home/claude/cfront-3/src/dcl2.cpp"
Pexpr __4ee ;

# 850 "/home/claude/cfront-3/src/dcl2.cpp"
__4ee = typ__4exprFP5table ( __1ss -> __O2__4stmt.e , __2tbl ) ;
if (__4ee -> base__4node == 70 ){ 
# 852 "/home/claude/cfront-3/src/dcl2.cpp"
Neval = 0 ;
((void )eval__4exprFv ( __4ee -> __O3__4expr.e2 ) );
if (Neval == 0 )
# 855 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCc ( (int )'w' , (const char *)"constant assignment in condition") ;
}
__1ss -> __O2__4stmt.e = (__4ee = check_cond__FP4exprUcP5table ( __4ee , (unsigned char )20 , __2tbl ) );

# 859 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> s__4stmt && ((__1ss -> s__4stmt -> base__4node == 118 )|| (__1ss -> s__4stmt -> base__4node == 117 )))
# 860 "/home/claude/cfront-3/src/dcl2.cpp"
error__FP3locPCcRC2eaN33 ( & __1ss -> s__4stmt ->
# 860 "/home/claude/cfront-3/src/dcl2.cpp"
where__4stmt , (const char *)"D as onlyS after `if'", (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 860 "/home/claude/cfront-3/src/dcl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 863 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4ee -> __O1__4expr.tp )
# 864 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__4ee -> __O1__4expr.tp -> base__4node ){ 
# 865 "/home/claude/cfront-3/src/dcl2.cpp"
case 21 :
# 866 "/home/claude/cfront-3/src/dcl2.cpp"
case 121 :
# 867 "/home/claude/cfront-3/src/dcl2.cpp"
case 138 :
# 868 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 869 "/home/claude/cfront-3/src/dcl2.cpp"
long long __6i ;
Neval = 0 ;
__6i = eval__4exprFv ( __4ee ) ;

# 873 "/home/claude/cfront-3/src/dcl2.cpp"
if (Neval == 0 ){ 
# 874 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __7sl ;

# 874 "/home/claude/cfront-3/src/dcl2.cpp"
__7sl = __1ss -> s_list__4stmt ;
if (__6i ){ 
# 876 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> __O3__4stmt.else_stmt && (__1ss -> __O3__4stmt.else_stmt -> permanent__4node == 0 ))del__4stmtFv ( __1ss -> __O3__4stmt.else_stmt ) ;
dcl__4stmtFi ( __1ss -> s__4stmt , 0 ) ;
((*__1ss ))= (*__1ss -> s__4stmt );
}
else { 
# 881 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss -> s__4stmt && (__1ss -> s__4stmt -> permanent__4node == 0 ))del__4stmtFv ( __1ss -> s__4stmt ) ;
if (__1ss -> __O3__4stmt.else_stmt ){ 
# 883 "/home/claude/cfront-3/src/dcl2.cpp"
dcl__4stmtFi ( __1ss -> __O3__4stmt.else_stmt , 0 ) ;
((*__1ss ))= (*__1ss -> __O3__4stmt.else_stmt );
}
else { 
# 887 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> base__4node = 72 ;
__1ss -> __O2__4stmt.e = dummy ;
__1ss -> s__4stmt = 0 ;
}
}
__1ss -> s_list__4stmt = __7sl ;
continue ;
}
}
}
if (__1ss -> s__4stmt -> base__4node != 117 )dcl__4stmtFi ( __1ss -> s__4stmt , 0 ) ;
if (__1ss -> __O3__4stmt.else_stmt ){ 
# 899 "/home/claude/cfront-3/src/dcl2.cpp"
if ((__1ss -> __O3__4stmt.else_stmt -> base__4node == 118 )|| (__1ss -> __O3__4stmt.else_stmt -> base__4node == 117 ))
# 900 "/home/claude/cfront-3/src/dcl2.cpp"
error__FP3locPCcRC2eaN33 ( & __1ss ->
# 900 "/home/claude/cfront-3/src/dcl2.cpp"
__O3__4stmt.else_stmt -> where__4stmt , (const char *)"D as onlyS after `else'", (const struct ea *)ea0 , (const struct
# 900 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
if (__1ss -> __O3__4stmt.else_stmt -> base__4node != 117 )dcl__4stmtFi ( __1ss -> __O3__4stmt.else_stmt , 0 ) ;
}
break ;
}

# 906 "/home/claude/cfront-3/src/dcl2.cpp"
case 16 :
# 907 "/home/claude/cfront-3/src/dcl2.cpp"
inline_restr |= 8 ;
__2old_loop = curr_loop ;
curr_loop = __1ss ;
if (__1ss -> __O3__4stmt.for_init ){ 
# 911 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __4fi ;

# 911 "/home/claude/cfront-3/src/dcl2.cpp"
__4fi = __1ss -> __O3__4stmt.for_init ;
switch (__4fi -> base__4node ){ 
# 913 "/home/claude/cfront-3/src/dcl2.cpp"
case 72 :
# 914 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4fi -> __O2__4stmt.e == dummy ){ 
# 915 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O3__4stmt.for_init = 0 ;
break ;
}
dcl__4stmtFi ( __4fi , 0 ) ;
break ;
default :
# 931 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 932 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __6tmp ;

# 932 "/home/claude/cfront-3/src/dcl2.cpp"
__6tmp = __ct__4stmtFUc3locP4stmt ( (struct stmt *)0 , (unsigned char )72 , curloc , (struct stmt *)0 ) ;
((*__6tmp ))= (*__1ss );
__6tmp -> __O3__4stmt.for_init = 0 ;
__4fi -> s_list__4stmt = __6tmp ;
((*__1ss ))= (*__4fi );
curr_loop = __2old_loop ;
dcl__4stmtFi ( __1ss , 1 ) ;
__6tmp = __1ss -> s_list__4stmt ;
if (((__1ss -> base__4node == 118 )&& (__6tmp -> base__4node == 16 ))&& (__6tmp -> __O3__4stmt.for_init == 0 ))
# 946 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 948 "/home/claude/cfront-3/src/dcl2.cpp"
((*__4fi ))= (*__1ss );
((*__1ss ))= (*__6tmp );
__1ss -> __O3__4stmt.for_init = __4fi ;
__4fi -> s_list__4stmt = 0 ;
}
else { 
# 953 "/home/claude/cfront-3/src/dcl2.cpp"
register struct block *__0__X97 ;

# 953 "/home/claude/cfront-3/src/dcl2.cpp"
struct loc __2__X98 ;

# 953 "/home/claude/cfront-3/src/dcl2.cpp"
struct loc __2__X99 ;

# 959 "/home/claude/cfront-3/src/dcl2.cpp"
((*__4fi ))= (*__1ss );
__6tmp = (struct stmt *)( (__0__X97 = 0 ), ( (__2__X98 = __1ss -> where__4stmt ), ( (__2__X99 = noloc ), ( ((__0__X97 ||
# 960 "/home/claude/cfront-3/src/dcl2.cpp"
(__0__X97 = (struct block *)__nw__4stmtSFUl ( (unsigned long )(sizeof (struct block))) ))?(((void )( (__0__X97 = (struct block *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X97 ),
# 960 "/home/claude/cfront-3/src/dcl2.cpp"
(unsigned char )116 , __2__X98 , __4fi ) ), ( (__0__X97 -> __O1__4stmt.d = ((struct name *)0 )), (__0__X97 -> __O3__4stmt.where2 = __2__X99 ))
# 960 "/home/claude/cfront-3/src/dcl2.cpp"
) )):(((void )0 ))), __0__X97 ) ) ) ) ;
__6tmp -> __O2__4stmt.own_tbl = 0 ;
__6tmp -> memtbl__4stmt = curr_block -> memtbl__4stmt ;
__6tmp -> permanent__4node = __1ss -> permanent__4node ;
((*__1ss ))= (*__6tmp );
__6tmp -> permanent__4node = 0 ;

# 965 "/home/claude/cfront-3/src/dcl2.cpp"
( (__6tmp ?(((void )(__6tmp ?(((void )(((void )__dl__4stmtSFPvUl ( (void *)__6tmp , (unsigned long )(sizeof (struct stmt))) )))):(((void )0 ))))):(((void )0 ))))
# 965 "/home/claude/cfront-3/src/dcl2.cpp"
;
}

# 969 "/home/claude/cfront-3/src/dcl2.cpp"
goto done ;
}
}
}
if (__1ss -> __O2__4stmt.e == dummy )
# 974 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O2__4stmt.e = 0 ;
else { 
# 976 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O2__4stmt.e = typ__4exprFP5table ( __1ss -> __O2__4stmt.e , __2tbl ) ;

# 978 "/home/claude/cfront-3/src/dcl2.cpp"
if (Ntmp ){ 
# 979 "/home/claude/cfront-3/src/dcl2.cpp"
Ntmp_dtor = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1ss -> __O2__4stmt.e , Ntmp_dtor ) ;

# 981 "/home/claude/cfront-3/src/dcl2.cpp"
}
__1ss -> __O2__4stmt.e = check_cond__FP4exprUcP5table ( __1ss -> __O2__4stmt.e , (unsigned char )16 , __2tbl ) ;
}
{ 
# 985 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __4st ;

# 985 "/home/claude/cfront-3/src/dcl2.cpp"
__4st = __1ss -> s__4stmt ;
while (__4st && (__4st -> base__4node == 16 ))
# 987 "/home/claude/cfront-3/src/dcl2.cpp"
__4st = __4st -> __O3__4stmt.for_init ;
if (__4st && ((__4st -> base__4node == 118 )|| (__4st -> base__4node == 117 )))
# 989 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4st == __1ss -> s__4stmt )
# 990 "/home/claude/cfront-3/src/dcl2.cpp"
error__FP3locPCcRC2eaN33 ( & __1ss -> s__4stmt ->
# 990 "/home/claude/cfront-3/src/dcl2.cpp"
where__4stmt , (const char *)"D as onlyS in for-loop", (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 990 "/home/claude/cfront-3/src/dcl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
}
if (__1ss -> s__4stmt -> base__4node != 117 )dcl__4stmtFi ( __1ss -> s__4stmt , 0 ) ;
__1ss -> __O1__4stmt.e2 = ((__1ss -> __O1__4stmt.e2 == dummy )?(((struct expr *)0 )):typ__4exprFP5table ( __1ss -> __O1__4stmt.e2 , __2tbl ) );
curr_loop = __2old_loop ;
break ;

# 997 "/home/claude/cfront-3/src/dcl2.cpp"
case 118 :
# 998 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1001 "/home/claude/cfront-3/src/dcl2.cpp"
int __4non_trivial ;
int __4count ;
Pname __4tail ;
Pname __4nn ;

# 1001 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 0 ;
__4count = 0 ;
__4tail = __1ss -> __O1__4stmt.d ;
__4nn = __4tail ;
for(__4nn = __4tail ;__4nn ;__4nn = __4nn -> __O1__4name.n_list ) { 
# 1008 "/home/claude/cfront-3/src/dcl2.cpp"
__4count ++ ;

# 1010 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4nn -> __O1__4name.n_list )
# 1011 "/home/claude/cfront-3/src/dcl2.cpp"
__4tail = __4nn -> __O1__4name.n_list ;
{ Pname __5n ;

# 1012 "/home/claude/cfront-3/src/dcl2.cpp"
__5n = look__5tableFPCcUc ( __2tbl , __4nn -> __O2__4expr.string , (unsigned char )0 ) ;

# 1014 "/home/claude/cfront-3/src/dcl2.cpp"
if (__5n && (__5n -> __O4__4expr.n_table == __2tbl ))
# 1015 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 2 ;
if (__4non_trivial >= 2 )
# 1017 "/home/claude/cfront-3/src/dcl2.cpp"
continue ;
if ((((__4nn -> n_sto__4name == 31 )&& (__4nn -> __O1__4expr.tp -> base__4node != 108 ))|| is_ref__4typeFv ( __4nn -> __O1__4expr.tp ) )|| (tconst__4typeFv ( __4nn ->
# 1018 "/home/claude/cfront-3/src/dcl2.cpp"
__O1__4expr.tp ) && (fct_const == 0 )))
# 1028 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1029 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 2 ;
continue ;
}

# 1033 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4nn -> base__4node == 85 ){ 
# 1034 "/home/claude/cfront-3/src/dcl2.cpp"
Pexpr __6in ;

# 1034 "/home/claude/cfront-3/src/dcl2.cpp"
__6in = __4nn -> __O3__4expr.n_initializer ;
if (__6in )
# 1036 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__6in -> base__4node ){ 
# 1037 "/home/claude/cfront-3/src/dcl2.cpp"
case 124 :
# 1038 "/home/claude/cfront-3/src/dcl2.cpp"
case 81 :
# 1039 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 2 ;
continue ;
}

# 1043 "/home/claude/cfront-3/src/dcl2.cpp"
if (__6in )
# 1044 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 3 ;
else __4non_trivial = 1 ;
}
{ Pname __5cln ;

# 1048 "/home/claude/cfront-3/src/dcl2.cpp"
struct classdef *__0__X100 ;

# 1048 "/home/claude/cfront-3/src/dcl2.cpp"
struct classdef *__0__X101 ;

# 1047 "/home/claude/cfront-3/src/dcl2.cpp"
__5cln = is_cl_obj__4typeFv ( __4nn -> __O1__4expr.tp ) ;
if (__5cln == 0 )
# 1049 "/home/claude/cfront-3/src/dcl2.cpp"
__5cln = cl_obj_vec ;
if (__5cln == 0 )
# 1051 "/home/claude/cfront-3/src/dcl2.cpp"
continue ;
if (( (__0__X100 = (((struct classdef *)(((struct classdef *)__5cln -> __O1__4expr.tp ))))), ( __0__X100 -> c_ctor__8classdef ) ) ){ 
# 1053 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 3 ;
# 1053 "/home/claude/cfront-3/src/dcl2.cpp"

# 1054 "/home/claude/cfront-3/src/dcl2.cpp"
continue ;
}
if (( (__0__X101 = (((struct classdef *)(((struct classdef *)__5cln -> __O1__4expr.tp ))))), ( __0__X101 -> c_dtor__8classdef ) ) )
# 1057 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 2 ;

# 1057 "/home/claude/cfront-3/src/dcl2.cpp"
}

# 1057 "/home/claude/cfront-3/src/dcl2.cpp"
}
}

# 1060 "/home/claude/cfront-3/src/dcl2.cpp"
while (__1ss -> s_list__4stmt && (__1ss -> s_list__4stmt -> base__4node == 118 )){ 
# 1061 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __5sx ;

# 1061 "/home/claude/cfront-3/src/dcl2.cpp"
__5sx = __1ss -> s_list__4stmt ;
__4tail = (__4tail -> __O1__4name.n_list = __5sx -> __O1__4stmt.d );
for(__4nn = __5sx -> __O1__4stmt.d ;__4nn ;__4nn = __4nn -> __O1__4name.n_list ) { 
# 1066 "/home/claude/cfront-3/src/dcl2.cpp"
__4count ++ ;
if (__4nn -> __O1__4name.n_list )
# 1068 "/home/claude/cfront-3/src/dcl2.cpp"
__4tail = __4nn -> __O1__4name.n_list ;
{ Pname __6n ;

# 1069 "/home/claude/cfront-3/src/dcl2.cpp"
__6n = look__5tableFPCcUc ( __2tbl , __4nn -> __O2__4expr.string , (unsigned char )0 ) ;
if (__6n && (__6n -> __O4__4expr.n_table == __2tbl ))
# 1071 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 2 ;
if (__4non_trivial >= 2 )
# 1073 "/home/claude/cfront-3/src/dcl2.cpp"
continue ;
if ((((__4nn -> n_sto__4name == 31 )&& (__4nn -> __O1__4expr.tp -> base__4node != 108 ))|| is_ref__4typeFv ( __4nn -> __O1__4expr.tp ) )|| (tconst__4typeFv ( __4nn ->
# 1074 "/home/claude/cfront-3/src/dcl2.cpp"
__O1__4expr.tp ) && (fct_const == 0 )))
# 1084 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1085 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 2 ;
continue ;
}
if (__4nn -> base__4node == 85 ){ 
# 1089 "/home/claude/cfront-3/src/dcl2.cpp"
Pexpr __7in ;

# 1089 "/home/claude/cfront-3/src/dcl2.cpp"
__7in = __4nn -> __O3__4expr.n_initializer ;
if (__7in )
# 1091 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__7in -> base__4node ){ 
# 1092 "/home/claude/cfront-3/src/dcl2.cpp"
case 124 :
# 1093 "/home/claude/cfront-3/src/dcl2.cpp"
case 81 :
# 1094 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 2 ;
continue ;
}
}

# 1099 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 1 ;
{ Pname __6cln ;

# 1101 "/home/claude/cfront-3/src/dcl2.cpp"
struct classdef *__0__X102 ;

# 1101 "/home/claude/cfront-3/src/dcl2.cpp"
struct classdef *__0__X103 ;

# 1100 "/home/claude/cfront-3/src/dcl2.cpp"
__6cln = is_cl_obj__4typeFv ( __4nn -> __O1__4expr.tp ) ;
if (__6cln == 0 )
# 1102 "/home/claude/cfront-3/src/dcl2.cpp"
__6cln = cl_obj_vec ;
if (__6cln == 0 )
# 1104 "/home/claude/cfront-3/src/dcl2.cpp"
continue ;
if (( (__0__X102 = (((struct classdef *)(((struct classdef *)__6cln -> __O1__4expr.tp ))))), ( __0__X102 -> c_ctor__8classdef ) ) ){ 
# 1106 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 2 ;
# 1106 "/home/claude/cfront-3/src/dcl2.cpp"

# 1107 "/home/claude/cfront-3/src/dcl2.cpp"
continue ;
}
if (( (__0__X103 = (((struct classdef *)(((struct classdef *)__6cln -> __O1__4expr.tp ))))), ( __0__X103 -> c_dtor__8classdef ) ) )
# 1110 "/home/claude/cfront-3/src/dcl2.cpp"
__4non_trivial = 2 ;

# 1110 "/home/claude/cfront-3/src/dcl2.cpp"
}

# 1110 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
__1ss -> s_list__4stmt = __5sx -> s_list__4stmt ;
}

# 1115 "/home/claude/cfront-3/src/dcl2.cpp"
{ Pstmt __4next_st ;

# 1115 "/home/claude/cfront-3/src/dcl2.cpp"
__4next_st = __1ss -> s_list__4stmt ;

# 1117 "/home/claude/cfront-3/src/dcl2.cpp"
if (((__4non_trivial == 3 )|| (__4non_trivial == 2 ))|| ((__4non_trivial == 1 )&& ((curr_block -> __O2__4stmt.own_tbl == 0 )|| (inline_restr & 3 ))))
# 1129 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1130 "/home/claude/cfront-3/src/dcl2.cpp"
if (curr_switch &&
# 1130 "/home/claude/cfront-3/src/dcl2.cpp"
(__4non_trivial >= 2 )){ 
# 1131 "/home/claude/cfront-3/src/dcl2.cpp"
if ((curr_case == 0 )|| (block_since_case == 0 ))
# 1133 "/home/claude/cfront-3/src/dcl2.cpp"
if (__4non_trivial == 3 )
# 1134 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"jump past initializer (did you forget a '{ }'?)")
# 1134 "/home/claude/cfront-3/src/dcl2.cpp"
;
else 
# 1136 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCc ( (const char *)"non trivialD in switchS (try enclosing it in a block)") ;
}

# 1148 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1149 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __6lastnn ;

# 1149 "/home/claude/cfront-3/src/dcl2.cpp"
__6lastnn = 0 ;
for(__4nn = __1ss -> __O1__4stmt.d ;__4nn ;__4nn = __4nn -> __O1__4name.n_list ) { 
# 1151 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __7n ;

# 1155 "/home/claude/cfront-3/src/dcl2.cpp"
if ((((((__7n = look__5tableFPCcUc ( curr_block -> memtbl__4stmt , __4nn -> __O2__4expr.string , (unsigned char )0 ) )&& (__7n -> __O4__4expr.n_table -> real_block__5table ==
# 1155 "/home/claude/cfront-3/src/dcl2.cpp"
curr_block -> memtbl__4stmt -> real_block__5table ))&& (__7n -> __O1__4expr.tp -> base__4node != 108 ))&& (__7n -> __O1__4expr.tp -> base__4node != 76 ))&& (__4nn -> lex_level__4name == __7n ->
# 1155 "/home/claude/cfront-3/src/dcl2.cpp"
lex_level__4name ))|| (__1forflag && for_check__FP4nameP4stmt ( __7n = __4nn , curr_block -> memtbl__4stmt -> real_block__5table ) ))
# 1167 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1168 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1168 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V83 ;

# 1168 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of%n", (const struct ea *)( ((& __0__V83 )-> __O1__2ea.p =
# 1168 "/home/claude/cfront-3/src/dcl2.cpp"
((const void *)__7n )), (& __0__V83 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1168 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 ) ;
if (__6lastnn == 0 )
# 1170 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O1__4stmt.d = __4nn -> __O1__4name.n_list ;
else 
# 1172 "/home/claude/cfront-3/src/dcl2.cpp"
__6lastnn -> __O1__4name.n_list = __4nn -> __O1__4name.n_list ;
} }
else 
# 1175 "/home/claude/cfront-3/src/dcl2.cpp"
__6lastnn = __4nn ;
}
}

# 1181 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> s__4stmt = __4next_st ;
__1ss -> s_list__4stmt = 0 ;

# 1187 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> memtbl__4stmt = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )(__4count + 4 ), __2tbl , (struct name *)0 ) ;
__1ss -> memtbl__4stmt -> real_block__5table = curr_block -> memtbl__4stmt -> real_block__5table ;
dcl__5blockFP5table ( ((struct block *)(((struct block *)__1ss ))), __1ss -> memtbl__4stmt ) ;
}
else { 
# 1196 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __5sss ;

# 1196 "/home/claude/cfront-3/src/dcl2.cpp"
__5sss = __1ss ;
{ 
# 1198 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __6lastnn ;

# 1198 "/home/claude/cfront-3/src/dcl2.cpp"
__6lastnn = 0 ;
for(__4nn = __1ss -> __O1__4stmt.d ;__4nn ;__4nn = __4nn -> __O1__4name.n_list ) { 
# 1200 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __7n ;

# 1201 "/home/claude/cfront-3/src/dcl2.cpp"
struct estmt *__0__X104 ;

# 1201 "/home/claude/cfront-3/src/dcl2.cpp"
struct loc __2__X105 ;

# 1201 "/home/claude/cfront-3/src/dcl2.cpp"
if ((((((__7n = look__5tableFPCcUc ( curr_block -> memtbl__4stmt , __4nn -> __O2__4expr.string , (unsigned char )0 ) )&& (__7n -> __O4__4expr.n_table -> real_block__5table ==
# 1201 "/home/claude/cfront-3/src/dcl2.cpp"
curr_block -> memtbl__4stmt -> real_block__5table ))&& (__7n -> __O1__4expr.tp -> base__4node != 108 ))&& (__7n -> __O1__4expr.tp -> base__4node != 76 ))&& (__4nn -> lex_level__4name == __7n ->
# 1201 "/home/claude/cfront-3/src/dcl2.cpp"
lex_level__4name ))|| (__1forflag && for_check__FP4nameP4stmt ( __7n = __4nn , curr_block -> memtbl__4stmt -> real_block__5table ) ))
# 1212 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1213 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1213 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V84 ;

# 1213 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs of%n", (const struct ea *)( ((& __0__V84 )-> __O1__2ea.p =
# 1213 "/home/claude/cfront-3/src/dcl2.cpp"
((const void *)__7n )), (& __0__V84 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1213 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 ) ;
__7n = 0 ;
if (__6lastnn == 0 )
# 1216 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> __O1__4stmt.d = __4nn -> __O1__4name.n_list ;
else 
# 1218 "/home/claude/cfront-3/src/dcl2.cpp"
__6lastnn -> __O1__4name.n_list = __4nn -> __O1__4name.n_list ;
} }
else { 
# 1221 "/home/claude/cfront-3/src/dcl2.cpp"
__7n = dcl__4nameFP5tableUc ( __4nn , __2tbl , (unsigned char )108 ) ;
__6lastnn = __4nn ;
}

# 1225 "/home/claude/cfront-3/src/dcl2.cpp"
if (__7n == 0 ){ 
# 1226 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss ){ 
# 1227 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss -> base__4node = 72 ;
__1ss -> __O2__4stmt.e = 0 ;
}
continue ;
}

# 1234 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1ss ){ 
# 1235 "/home/claude/cfront-3/src/dcl2.cpp"
__5sss -> base__4node = 72 ;
__1ss = 0 ;
}
else 
# 1239 "/home/claude/cfront-3/src/dcl2.cpp"
__5sss = (__5sss -> s_list__4stmt = (struct stmt *)( (__0__X104 = 0 ), ( (__2__X105 = __5sss -> where__4stmt ), ( ((__0__X104 ||
# 1239 "/home/claude/cfront-3/src/dcl2.cpp"
(__0__X104 = (struct estmt *)__nw__4stmtSFUl ( (unsigned long )(sizeof (struct estmt))) ))?( (__0__X104 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X104 ), ((unsigned
# 1239 "/home/claude/cfront-3/src/dcl2.cpp"
char )72 ), __2__X105 , ((struct stmt *)0 )) ), (__0__X104 -> __O2__4stmt.e = ((struct expr *)0 ))) :0 ), __0__X104 ) ) )
# 1239 "/home/claude/cfront-3/src/dcl2.cpp"
);
if ((__7n -> base__4node == 85 )&& __7n -> __O3__4expr.n_initializer ){ 
# 1241 "/home/claude/cfront-3/src/dcl2.cpp"
Pexpr __8in ;

# 1241 "/home/claude/cfront-3/src/dcl2.cpp"
__8in = __7n -> __O3__4expr.n_initializer ;
__7n -> __O3__4expr.n_initializer = 0 ;
switch (__8in -> base__4node ){ 
# 1244 "/home/claude/cfront-3/src/dcl2.cpp"
case 146 :
# 1245 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1246 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __10fn ;

# 1246 "/home/claude/cfront-3/src/dcl2.cpp"
__10fn = __8in -> __O4__4expr.fct_name ;
if (__10fn && (__10fn -> n_oper__4name == 161 ))
# 1248 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
}
default :
# 1251 "/home/claude/cfront-3/src/dcl2.cpp"
__8in = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__7n , __8in ) ;
__8in -> __O1__4expr.tp = __7n -> __O1__4expr.tp ;
}
__5sss -> __O2__4stmt.e = __8in ;
__5sss -> where__4stmt = __7n -> where__4name ;
}
else 
# 1258 "/home/claude/cfront-3/src/dcl2.cpp"
__5sss -> __O2__4stmt.e = dummy ;
}
}

# 1262 "/home/claude/cfront-3/src/dcl2.cpp"
__1ss = __5sss ;
__1ss -> s_list__4stmt = __4next_st ;
}
break ;

# 1265 "/home/claude/cfront-3/src/dcl2.cpp"
}
}

# 1268 "/home/claude/cfront-3/src/dcl2.cpp"
case 116 :
# 1269 "/home/claude/cfront-3/src/dcl2.cpp"
dcl__5blockFP5table ( ((struct block *)(((struct block *)__1ss ))), __2tbl ) ;
break ;

# 1272 "/home/claude/cfront-3/src/dcl2.cpp"
case 1 :
# 1274 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1275 "/home/claude/cfront-3/src/dcl2.cpp"
char *__4s ;
int __4ll ;
char *__4s2 ;

# 1275 "/home/claude/cfront-3/src/dcl2.cpp"
__4s = (((char *)__1ss -> __O2__4stmt.e ));
__4ll = strlen ( (const char *)__4s ) ;
__4s2 = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (__4ll + 1 ))) ));
strcpy ( __4s2 , (const char *)__4s ) ;
__1ss -> __O2__4stmt.e = (((struct expr *)(((struct expr *)__4s2 ))));
break ;
}

# 1283 "/home/claude/cfront-3/src/dcl2.cpp"
default :
# 1284 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1284 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V85 ;

# 1284 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V86 ;

# 1284 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"badS(%p %d)", (const struct ea *)( ((&
# 1284 "/home/claude/cfront-3/src/dcl2.cpp"
__0__V85 )-> __O1__2ea.p = ((const void *)__1ss )), (& __0__V85 )) , (const struct ea *)( (__2__X106 = __1ss -> base__4node ),
# 1284 "/home/claude/cfront-3/src/dcl2.cpp"
( (( ((& __0__V86 )-> __O1__2ea.i = __2__X106 ), 0 ) ), (& __0__V86 )) ) , (const struct
# 1284 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1285 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
done :
# 1288 "/home/claude/cfront-3/src/dcl2.cpp"
Cstmt = __1ostmt ;
}

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 941 "/home/claude/cfront-3/src/cfront.h"
int no_of_names__4nameFv (struct name *__0this );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 1291 "/home/claude/cfront-3/src/dcl2.cpp"
void dcl__5blockFP5table (register struct block *__0this , Ptable __1tbl )
# 1297 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1298 "/home/claude/cfront-3/src/dcl2.cpp"
int __1bit_old ;
int __1byte_old ;
Pblock __1block_old ;
Pstmt __1save_case ;
Pblock __1old_bsc ;

# 1304 "/home/claude/cfront-3/src/dcl2.cpp"
Pfct __1f ;

# 1305 "/home/claude/cfront-3/src/dcl2.cpp"
unsigned long __2__X112 ;

# 1305 "/home/claude/cfront-3/src/dcl2.cpp"
register struct name *__0__X119 ;

# 1305 "/home/claude/cfront-3/src/dcl2.cpp"
unsigned long __2__X16 ;

# 1305 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__X__V1400qm5nwo3mvcnm ;

# 1305 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__X__V1500qm5nwo3mvcnm ;

# 1298 "/home/claude/cfront-3/src/dcl2.cpp"
__1bit_old = bit_offset ;
__1byte_old = byte_offset ;
__1block_old = curr_block ;
__1save_case = curr_case ;
__1old_bsc = block_since_case ;

# 1304 "/home/claude/cfront-3/src/dcl2.cpp"
__1f = ( (__0__X119 = cc -> nof__11dcl_context ), ( ((__0__X119 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X119 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 (
# 1304 "/home/claude/cfront-3/src/dcl2.cpp"
(int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qm5nwo3mvcnm )->
# 1304 "/home/claude/cfront-3/src/dcl2.cpp"
__O1__2ea.p = ((const void *)__0__X119 )), (& __0__X__V1400qm5nwo3mvcnm )) , (const struct ea *)( (__2__X16 = __0__X119 -> __O1__4expr.tp -> base__4node ),
# 1304 "/home/claude/cfront-3/src/dcl2.cpp"
( (( ((& __0__X__V1500qm5nwo3mvcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qm5nwo3mvcnm )) ) , (const struct
# 1304 "/home/claude/cfront-3/src/dcl2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) ;

# 1306 "/home/claude/cfront-3/src/dcl2.cpp"
if ((__0this -> base__4node != 116 )&& (__0this -> base__4node != 118 ))
# 1307 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1307 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V107 ;

# 1307 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"block::dcl(%d)", (const struct ea *)( (__2__X112 =
# 1307 "/home/claude/cfront-3/src/dcl2.cpp"
__0this -> base__4node ), ( (( ((& __0__V107 )-> __O1__2ea.i = __2__X112 ), 0 ) ), (& __0__V107 )) ) ,
# 1307 "/home/claude/cfront-3/src/dcl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1309 "/home/claude/cfront-3/src/dcl2.cpp"
curr_block = __0this ;
if (curr_case && (__0this -> base__4node == 116 ))
# 1311 "/home/claude/cfront-3/src/dcl2.cpp"
block_since_case = __0this ;

# 1313 "/home/claude/cfront-3/src/dcl2.cpp"
{ Pname __1re_decl ;

# 1313 "/home/claude/cfront-3/src/dcl2.cpp"
__1re_decl = 0 ;
if (((__1f -> f_result__3fct && __0this -> s__4stmt )&& (__1f -> nrv__3fct == 0 ))&& ((__0this == top_block )|| (__0this -> memtbl__4stmt && (__0this -> memtbl__4stmt ->
# 1314 "/home/claude/cfront-3/src/dcl2.cpp"
real_block__5table == (((struct stmt *)top_block ))))))
# 1317 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1318 "/home/claude/cfront-3/src/dcl2.cpp"
Pstmt __2tmp ;

# 1318 "/home/claude/cfront-3/src/dcl2.cpp"
__2tmp = __0this -> s__4stmt ;
while ((__2tmp -> base__4node != 28 )&& __2tmp -> s_list__4stmt )
# 1320 "/home/claude/cfront-3/src/dcl2.cpp"
__2tmp = __2tmp -> s_list__4stmt ;
if (__2tmp -> base__4node == 28 ){ 
# 1322 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __3tt ;
Pname __3td ;

# 1322 "/home/claude/cfront-3/src/dcl2.cpp"
__3tt = ((__2tmp -> __O2__4stmt.e -> base__4node == 85 )?(((struct name *)(((struct name *)__2tmp -> __O2__4stmt.e )))):(((struct name *)0 )));

# 1324 "/home/claude/cfront-3/src/dcl2.cpp"
if (((__3tt && (__3td = is_decl__FP5blockP4name ( curr_block , __3tt ) ))&& (__3td -> n_sto__4name != 31 ))&& (check__4typeFP4typeUcT2 ( __3td -> __O1__4expr.tp , __1f ->
# 1324 "/home/claude/cfront-3/src/dcl2.cpp"
returns__3fct , (unsigned char )0 , (unsigned char )0 ) == 0 ))
# 1329 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1330 "/home/claude/cfront-3/src/dcl2.cpp"
__1f -> nrv__3fct = __3tt ;
}
}

# 1335 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1f -> nrv__3fct ){ 
# 1336 "/home/claude/cfront-3/src/dcl2.cpp"
if (find_return__FP4stmtP4name ( __0this -> s__4stmt , __1f -> nrv__3fct ) )__1f -> nrv__3fct = 0 ;
}
}
else if (__1f -> nrv__3fct )__1re_decl = is_decl__FP5blockP4name ( curr_block , __1f -> nrv__3fct ) ;

# 1341 "/home/claude/cfront-3/src/dcl2.cpp"
{ Pktab __1otbl ;

# 1341 "/home/claude/cfront-3/src/dcl2.cpp"
__1otbl = Ctbl ;
if (__0this -> k_tbl__4stmt )
# 1343 "/home/claude/cfront-3/src/dcl2.cpp"
Ctbl = __0this -> k_tbl__4stmt ;
if (__0this -> __O1__4stmt.d ){ 
# 1358 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __2nx ;

# 1345 "/home/claude/cfront-3/src/dcl2.cpp"
__0this -> __O2__4stmt.own_tbl = 1 ;
__0this -> base__4node = 116 ;
if (__0this -> memtbl__4stmt == 0 ){ 
# 1348 "/home/claude/cfront-3/src/dcl2.cpp"
int __3nmem ;

# 1348 "/home/claude/cfront-3/src/dcl2.cpp"
__3nmem = (no_of_names__4nameFv ( __0this -> __O1__4stmt.d ) + 4 );
__0this -> memtbl__4stmt = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )__3nmem , __1tbl , (struct name *)0 ) ;
__0this -> memtbl__4stmt -> real_block__5table = (struct stmt *)__0this ;

# 1354 "/home/claude/cfront-3/src/dcl2.cpp"
}
else if (__0this -> memtbl__4stmt != __1tbl )
# 1356 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCc ( (int )'i' , (const char *)"block::dcl(?)")
# 1356 "/home/claude/cfront-3/src/dcl2.cpp"
;

# 1358 "/home/claude/cfront-3/src/dcl2.cpp"
;
{ { Pname __2n ;

# 1359 "/home/claude/cfront-3/src/dcl2.cpp"
__2n = __0this -> __O1__4stmt.d ;

# 1359 "/home/claude/cfront-3/src/dcl2.cpp"
for(;__2n ;__2n = __2nx ) { 
# 1360 "/home/claude/cfront-3/src/dcl2.cpp"
__2nx = __2n -> __O1__4name.n_list ;
if ((__1f -> nrv__3fct && (! __1re_decl ))&& (strcmp ( __1f -> nrv__3fct -> __O2__4expr.string , __2n -> __O2__4expr.string ) == 0 ))
# 1364 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1365 "/home/claude/cfront-3/src/dcl2.cpp"
__2n ->
# 1365 "/home/claude/cfront-3/src/dcl2.cpp"
__O2__4expr.string = (const char *)"__NRV";
}
dcl__4nameFP5tableUc ( __2n , __0this -> memtbl__4stmt , (unsigned char )108 ) ;
switch (__2n -> __O1__4expr.tp -> base__4node ){ 
# 1369 "/home/claude/cfront-3/src/dcl2.cpp"
case 6 :
# 1370 "/home/claude/cfront-3/src/dcl2.cpp"
case 167 :
# 1371 "/home/claude/cfront-3/src/dcl2.cpp"
case 13 :
# 1372 "/home/claude/cfront-3/src/dcl2.cpp"
break ;
default :
# 1374 "/home/claude/cfront-3/src/dcl2.cpp"
( (__2n ?(((void )(__2n ?(((void )( ( ((((struct expr *)__2n ))?(((void )((((struct expr *)__2n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 ))))
# 1374 "/home/claude/cfront-3/src/dcl2.cpp"
, (((void )__dl__4nameSFPvUl ( (void *)__2n , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
# 1374 "/home/claude/cfront-3/src/dcl2.cpp"

# 1375 "/home/claude/cfront-3/src/dcl2.cpp"
}
}

# 1376 "/home/claude/cfront-3/src/dcl2.cpp"
}

# 1376 "/home/claude/cfront-3/src/dcl2.cpp"
}
}
else if (__0this -> base__4node == 116 ){ 
# 1379 "/home/claude/cfront-3/src/dcl2.cpp"
__0this -> __O2__4stmt.own_tbl = 1 ;
if (__0this -> memtbl__4stmt == 0 ){ 
# 1381 "/home/claude/cfront-3/src/dcl2.cpp"
int __3nmem ;

# 1381 "/home/claude/cfront-3/src/dcl2.cpp"
__3nmem = 4 ;
__0this -> memtbl__4stmt = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )__3nmem , __1tbl , (struct name *)0 ) ;
__0this -> memtbl__4stmt -> real_block__5table = (struct stmt *)__0this ;

# 1387 "/home/claude/cfront-3/src/dcl2.cpp"
}
else if (__0this -> memtbl__4stmt != __1tbl )
# 1389 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiPCc ( (int )'i' , (const char *)"block::dcl(?)")
# 1389 "/home/claude/cfront-3/src/dcl2.cpp"
;
}
else { 
# 1392 "/home/claude/cfront-3/src/dcl2.cpp"
__0this -> base__4node = 116 ;
__0this -> memtbl__4stmt = __1tbl ;
}

# 1396 "/home/claude/cfront-3/src/dcl2.cpp"
{ Pname __1odcl ;

# 1396 "/home/claude/cfront-3/src/dcl2.cpp"
__1odcl = Cdcl ;
if (__0this -> s__4stmt )
# 1398 "/home/claude/cfront-3/src/dcl2.cpp"
dcl__4stmtFi ( __0this -> s__4stmt , 0 ) ;
if (__0this -> __O2__4stmt.own_tbl ){ 
# 1400 "/home/claude/cfront-3/src/dcl2.cpp"
Pname __2m ;
int __2i ;

# 1402 "/home/claude/cfront-3/src/dcl2.cpp"
struct table *__0__X113 ;

# 1402 "/home/claude/cfront-3/src/dcl2.cpp"
int __2__X114 ;

# 1402 "/home/claude/cfront-3/src/dcl2.cpp"
struct table *__0__X115 ;

# 1402 "/home/claude/cfront-3/src/dcl2.cpp"
int __2__X116 ;

# 1402 "/home/claude/cfront-3/src/dcl2.cpp"
for(__2m = ( (__0__X113 = __0this -> memtbl__4stmt ), ( (__2__X114 = (__2i = 1 )), ( (((__2__X114 <= 0 )|| (__0__X113 -> free_slot__5table <=
# 1402 "/home/claude/cfront-3/src/dcl2.cpp"
__2__X114 ))?(((struct name *)0 )):(__0__X113 -> entries__5table [__2__X114 ]))) ) ) ;__2m ;__2m = (__2m -> n_tbl_list__4name ?__2m -> n_tbl_list__4name :( (__0__X115 = __0this -> memtbl__4stmt ), ( (__2__X116 =
# 1402 "/home/claude/cfront-3/src/dcl2.cpp"
(++ __2i )), ( (((__2__X116 <= 0 )|| (__0__X115 -> free_slot__5table <= __2__X116 ))?(((struct name *)0 )):(__0__X115 -> entries__5table [__2__X116 ]))) ) ) )) {
# 1402 "/home/claude/cfront-3/src/dcl2.cpp"

# 1403 "/home/claude/cfront-3/src/dcl2.cpp"
Ptype __3t ;

# 1403 "/home/claude/cfront-3/src/dcl2.cpp"
__3t = __2m -> __O1__4expr.tp ;

# 1405 "/home/claude/cfront-3/src/dcl2.cpp"
if (in_class_dcl )
# 1406 "/home/claude/cfront-3/src/dcl2.cpp"
__2m -> lex_level__4name -= 1 ;

# 1408 "/home/claude/cfront-3/src/dcl2.cpp"
if (__3t == 0 ){ 
# 1408 "/home/claude/cfront-3/src/dcl2.cpp"
const void *__2__X117 ;

# 1408 "/home/claude/cfront-3/src/dcl2.cpp"
const void *__2__X118 ;

# 1409 "/home/claude/cfront-3/src/dcl2.cpp"
if (__2m -> n_assigned_to__4name == 0 )
# 1410 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1410 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V108 ;

# 1410 "/home/claude/cfront-3/src/dcl2.cpp"
error__FPCcRC2eaN32 ( (const char *)"label %sU", (const struct ea *)( (__2__X117 = (const void
# 1410 "/home/claude/cfront-3/src/dcl2.cpp"
*)__2m -> __O2__4expr.string ), ( ((& __0__V108 )-> __O1__2ea.p = __2__X117 ), (& __0__V108 )) ) , (const struct ea *)ea0 ,
# 1410 "/home/claude/cfront-3/src/dcl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__2m -> n_used__4name == 0 )
# 1412 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1412 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V109 ;

# 1412 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __2m -> where__4name , (const char *)"label %s not used", (const
# 1412 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea *)( (__2__X118 = (const void *)__2m -> __O2__4expr.string ), ( ((& __0__V109 )-> __O1__2ea.p = __2__X118 ), (& __0__V109 ))
# 1412 "/home/claude/cfront-3/src/dcl2.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} continue ;
}

# 1416 "/home/claude/cfront-3/src/dcl2.cpp"
__3t = skiptypedefs__4typeFv ( __3t ) ;

# 1418 "/home/claude/cfront-3/src/dcl2.cpp"
switch (__3t -> base__4node ){ 
# 1419 "/home/claude/cfront-3/src/dcl2.cpp"
case 6 :
# 1420 "/home/claude/cfront-3/src/dcl2.cpp"
case 167 :
# 1421 "/home/claude/cfront-3/src/dcl2.cpp"
case 13 :
# 1422 "/home/claude/cfront-3/src/dcl2.cpp"
case 108 :
# 1423 "/home/claude/cfront-3/src/dcl2.cpp"
continue ;
}

# 1426 "/home/claude/cfront-3/src/dcl2.cpp"
if (__2m -> n_addr_taken__4name == 0 ){ 
# 1427 "/home/claude/cfront-3/src/dcl2.cpp"
if (__2m -> n_used__4name ){ 
# 1428 "/home/claude/cfront-3/src/dcl2.cpp"
if (((__2m -> n_assigned_to__4name == 0 )&& (__3t -> base__4node != 110 ))&&
# 1428 "/home/claude/cfront-3/src/dcl2.cpp"
(__2m -> n_scope__4name == 108 ))
# 1434 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1435 "/home/claude/cfront-3/src/dcl2.cpp"
Cdcl = __2m ;
if (((__2m -> __O2__4expr.string [0 ])!= '_' )&& ((__2m -> __O2__4expr.string [1 ])!= '_' ))
# 1437 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1437 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V110 ;

# 1437 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __2m -> where__4name , (const char *)"%n used but not set", (const
# 1437 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea *)( ((& __0__V110 )-> __O1__2ea.p = ((const void *)__2m )), (& __0__V110 )) , (const struct ea *)ea0 ,
# 1437 "/home/claude/cfront-3/src/dcl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
else { 
# 1441 "/home/claude/cfront-3/src/dcl2.cpp"
if (((__2m -> n_assigned_to__4name == 0 )&& (((__2m -> __O2__4expr.string [0 ])!= '_' )|| ((__2m -> __O2__4expr.string [1 ])!= '_' )))&& ((__2m ->
# 1441 "/home/claude/cfront-3/src/dcl2.cpp"
n_scope__4name == 136 )|| (__2m -> n_scope__4name == 108 )))
# 1447 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1448 "/home/claude/cfront-3/src/dcl2.cpp"
Cdcl = __2m ;
{ 
# 1449 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea __0__V111 ;

# 1449 "/home/claude/cfront-3/src/dcl2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __2m -> where__4name , (const char *)"%n not used", (const
# 1449 "/home/claude/cfront-3/src/dcl2.cpp"
struct ea *)( ((& __0__V111 )-> __O1__2ea.p = ((const void *)__2m )), (& __0__V111 )) , (const struct ea *)ea0 ,
# 1449 "/home/claude/cfront-3/src/dcl2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
}
}
}
Cdcl = __1odcl ;

# 1457 "/home/claude/cfront-3/src/dcl2.cpp"
__0this -> __O1__4stmt.d = 0 ;

# 1459 "/home/claude/cfront-3/src/dcl2.cpp"
if (bit_offset )
# 1460 "/home/claude/cfront-3/src/dcl2.cpp"
byte_offset += SZ_WORD ;
bit_offset = __1bit_old ;
byte_offset = __1byte_old ;
if (curr_case == __1save_case )block_since_case = __1old_bsc ;
curr_block = __1block_old ;
Ctbl = __1otbl ;

# 1465 "/home/claude/cfront-3/src/dcl2.cpp"
}

# 1465 "/home/claude/cfront-3/src/dcl2.cpp"
}

# 1465 "/home/claude/cfront-3/src/dcl2.cpp"
}
}

# 350 "/home/claude/cfront-3/src/cfront.h"
int align__4typeFv (struct type *__0this );

# 1468 "/home/claude/cfront-3/src/dcl2.cpp"
void field_align__4nameFv (register struct name *__0this )
# 1472 "/home/claude/cfront-3/src/dcl2.cpp"
{ 
# 1473 "/home/claude/cfront-3/src/dcl2.cpp"
Pbase __1fld ;
int __1nbits ;

# 1476 "/home/claude/cfront-3/src/dcl2.cpp"
int __1a ;

# 1473 "/home/claude/cfront-3/src/dcl2.cpp"
__1fld = (((struct basetype *)(((struct basetype *)__0this -> __O1__4expr.tp ))));
__1nbits = __1fld -> b_bits__8basetype ;

# 1476 "/home/claude/cfront-3/src/dcl2.cpp"
__1a = (F_SENSITIVE ?align__4typeFv ( __1fld -> __O1__8basetype.b_fieldtype ) :SZ_WORD );

# 1481 "/home/claude/cfront-3/src/dcl2.cpp"
if (max_align < __1a )
# 1482 "/home/claude/cfront-3/src/dcl2.cpp"
max_align = __1a ;

# 1484 "/home/claude/cfront-3/src/dcl2.cpp"
if (__1nbits == 0 ){ 
# 1485 "/home/claude/cfront-3/src/dcl2.cpp"
int __2b ;
if (bit_offset )
# 1487 "/home/claude/cfront-3/src/dcl2.cpp"
__1nbits = (BI_IN_WORD - bit_offset );
else if (__2b = (byte_offset % SZ_WORD ))
# 1489 "/home/claude/cfront-3/src/dcl2.cpp"
__1nbits = (__2b * BI_IN_BYTE );
if (max_align < SZ_WORD )
# 1491 "/home/claude/cfront-3/src/dcl2.cpp"
max_align = SZ_WORD ;
}
else if (bit_offset == 0 ){ 
# 1494 "/home/claude/cfront-3/src/dcl2.cpp"
int __2b ;

# 1494 "/home/claude/cfront-3/src/dcl2.cpp"
__2b = (byte_offset % SZ_WORD );
if (__2b ){ 
# 1496 "/home/claude/cfront-3/src/dcl2.cpp"
byte_offset -= __2b ;
bit_offset = (__2b * BI_IN_BYTE );
}
}

# 1501 "/home/claude/cfront-3/src/dcl2.cpp"
{ int __1x ;

# 1501 "/home/claude/cfront-3/src/dcl2.cpp"
__1x = (bit_offset += __1nbits );
if ((SZ_INT * BI_IN_BYTE )< __1x ){ 
# 1503 "/home/claude/cfront-3/src/dcl2.cpp"
__1fld -> b_offset__8basetype = 0 ;
byte_offset += SZ_INT ;
bit_offset = __1nbits ;
}
else { 
# 1508 "/home/claude/cfront-3/src/dcl2.cpp"
__1fld -> b_offset__8basetype = bit_offset ;
if ((SZ_INT * BI_IN_BYTE )== __1x ){ 
# 1510 "/home/claude/cfront-3/src/dcl2.cpp"
bit_offset = 0 ;
byte_offset += SZ_INT ;
}
else 
# 1514 "/home/claude/cfront-3/src/dcl2.cpp"
bit_offset = __1x ;
}
__0this -> n_offset__4name = byte_offset ;

# 1516 "/home/claude/cfront-3/src/dcl2.cpp"
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
static struct Block_Pname *__ct__11Block_PnameFv (struct Block_Pname *__0this ){ if (__0this || (__0this = (struct Block_Pname *)__nw__FUl ( (unsigned long )(sizeof (struct Block_Pname)))
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

# 1517 "/home/claude/cfront-3/src/dcl2.cpp"

/* the end */
