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

# 460 "/home/claude/cfront-3/src/cfront.h"
bit has_base__8classdefFP8classdefiT2 (struct classdef *__0this , Pclass __1cl , int __1level , int __1ccflag );

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 25 "/home/claude/cfront-3/src/dcl4.cpp"
static Pname get_vf__FP4nameP8classdef (Pname __1n_pvf , Pclass __1cl );

# 25 "/home/claude/cfront-3/src/dcl4.cpp"
static Pname get_vf__FP4nameP8classdef (Pname __1n_pvf , Pclass __1cl ){ 
# 34 "/home/claude/cfront-3/src/dcl4.cpp"
if ((! __1n_pvf )|| (! __1cl ))return (struct name *)0 ;

# 36 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1n_pvf -> __O1__4expr.tp && (! has_base__8classdefFP8classdefiT2 ( __1cl , (((struct fct *)(((struct fct *)__1n_pvf -> __O1__4expr.tp ))))-> memof__3fct , 0 , 0 ) ))
# 37 "/home/claude/cfront-3/src/dcl4.cpp"
{
# 37 "/home/claude/cfront-3/src/dcl4.cpp"

# 38 "/home/claude/cfront-3/src/dcl4.cpp"
return (struct name *)0 ;
}
{ Pname __1n_vf ;

# 40 "/home/claude/cfront-3/src/dcl4.cpp"
__1n_vf = look__5tableFPCcUc ( __1cl -> memtbl__8classdef , __1n_pvf -> __O2__4expr.string , (unsigned char )0 ) ;
if ((__1n_vf && __1n_pvf -> __O1__4expr.tp )&& __1n_vf -> __O1__4expr.tp ){ 
# 42 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1n_vf -> __O1__4expr.tp -> base__4node == 76 ){ 
# 43 "/home/claude/cfront-3/src/dcl4.cpp"
Plist __3gl ;

# 43 "/home/claude/cfront-3/src/dcl4.cpp"
__3gl = (((struct gen *)(((struct gen *)__1n_vf -> __O1__4expr.tp ))))-> fct_list__3gen ;
for(;__3gl ;__3gl = __3gl -> l__9name_list ) { 
# 45 "/home/claude/cfront-3/src/dcl4.cpp"
if (! check__4typeFP4typeUcT2 ( (struct type *)(((struct fct *)(((struct fct *)__1n_pvf -> __O1__4expr.tp )))), __3gl -> f__9name_list ->
# 45 "/home/claude/cfront-3/src/dcl4.cpp"
__O1__4expr.tp , (unsigned char )77 , (unsigned char )0 ) )
# 46 "/home/claude/cfront-3/src/dcl4.cpp"
break ;
}
if (! __3gl )
# 49 "/home/claude/cfront-3/src/dcl4.cpp"
__1n_vf = 0 ;
}
else { 
# 52 "/home/claude/cfront-3/src/dcl4.cpp"
if (check__4typeFP4typeUcT2 ( (struct type *)(((struct fct *)(((struct fct *)__1n_pvf -> __O1__4expr.tp )))), (struct type *)(((struct fct *)(((struct fct *)__1n_vf -> __O1__4expr.tp )))),
# 52 "/home/claude/cfront-3/src/dcl4.cpp"
(unsigned char )77 , (unsigned char )0 ) )
# 53 "/home/claude/cfront-3/src/dcl4.cpp"
__1n_vf = 0 ;
}
}

# 57 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1n_vf == 0 ){ 
# 58 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pbcl __2b ;

# 58 "/home/claude/cfront-3/src/dcl4.cpp"
__2b = __1cl -> baselist__8classdef ;

# 58 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2b ;__2b = __2b -> next__6basecl ) { 
# 59 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__2b -> base__4node == 85 )|| (__2b -> base__4node == 77 )){ 
# 60 "/home/claude/cfront-3/src/dcl4.cpp"
__1n_vf = get_vf__FP4nameP8classdef ( __1n_pvf ,
# 60 "/home/claude/cfront-3/src/dcl4.cpp"
__2b -> bclass__6basecl ) ;
if (__1n_vf && (! __1n_vf -> __O3__4expr.n_initializer )){ 
# 62 "/home/claude/cfront-3/src/dcl4.cpp"
break ;
}
else 
# 63 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 64 "/home/claude/cfront-3/src/dcl4.cpp"
__1n_vf = 0 ;
}
}
}

# 67 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 67 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 70 "/home/claude/cfront-3/src/dcl4.cpp"
return __1n_vf ;

# 70 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 74 "/home/claude/cfront-3/src/dcl4.cpp"
void fix_args__FP3fctP8classdef (Pfct __1f , Pclass __1cl )
# 80 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 81 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pname __1a ;

# 81 "/home/claude/cfront-3/src/dcl4.cpp"
__1a = __1f -> argtype__3fct ;

# 81 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1a ;__1a = __1a -> __O1__4name.n_list ) { 
# 82 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2n ;

# 83 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X26 ;

# 83 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X27 ;

# 82 "/home/claude/cfront-3/src/dcl4.cpp"
__2n = is_cl_obj__4typeFv ( __1a -> __O1__4expr.tp ) ;
if (__2n && ( (__1__X26 = (((struct classdef *)(((struct classdef *)__2n -> __O1__4expr.tp ))))), ( (__1__X27 = __1cl ), ( ((__1__X26 == __1__X27 )?1 :((__1__X26 &&
# 83 "/home/claude/cfront-3/src/dcl4.cpp"
__1__X27 )?(((int )same_class__8classdefFP8classdefi ( __1__X26 , __1__X27 , 0 ) )):0 ))) ) ) )
# 84 "/home/claude/cfront-3/src/dcl4.cpp"
__1a -> n_xref__4name = 1 ;
}

# 85 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 85 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
struct typedef_info;

# 92 "/home/claude/cfront-3/src/dcl4.cpp"
static struct typedef_info *typedef_info_head = 0 ;

# 92 "/home/claude/cfront-3/src/dcl4.cpp"
static struct typedef_info *typedef_info_tail = 0 ;

# 94 "/home/claude/cfront-3/src/dcl4.cpp"
static Pfct get_fct_node__FP4name (Pname __1n )
# 95 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 96 "/home/claude/cfront-3/src/dcl4.cpp"
Ptype __1t ;

# 96 "/home/claude/cfront-3/src/dcl4.cpp"
__1t = (__1n -> __O1__4expr.tp ?skiptypedefs__4typeFv ( __1n -> __O1__4expr.tp ) :(((struct type *)0 )));

# 98 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1t && (__1t -> base__4node == 158 ))
# 99 "/home/claude/cfront-3/src/dcl4.cpp"
__1t = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp ) ;

# 101 "/home/claude/cfront-3/src/dcl4.cpp"
while (__1t && (__1t -> base__4node == 125 ))
# 102 "/home/claude/cfront-3/src/dcl4.cpp"
__1t = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp ) ;

# 104 "/home/claude/cfront-3/src/dcl4.cpp"
return ((__1t && (__1t -> base__4node == 108 ))?(((struct fct *)(((struct fct *)__1t )))):(((struct fct *)0 )));
}

# 88 "/home/claude/cfront-3/src/dcl4.cpp"
struct typedef_info {	/* sizeof typedef_info == 16 */
Pname n__12typedef_info ;
struct typedef_info *next__12typedef_info ;
};

# 107 "/home/claude/cfront-3/src/dcl4.cpp"
static void record_typedef__FP4name (Pname __1tn )
# 108 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 109 "/home/claude/cfront-3/src/dcl4.cpp"
struct typedef_info *__1p ;

# 109 "/home/claude/cfront-3/src/dcl4.cpp"
__1p = (((struct typedef_info *)__nw__FUl ( sizeof (struct typedef_info )) ));
__1p -> n__12typedef_info = __1tn ;
if (typedef_info_head == 0 ){ 
# 112 "/home/claude/cfront-3/src/dcl4.cpp"
typedef_info_head = (typedef_info_tail = __1p );
}
else 
# 113 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 114 "/home/claude/cfront-3/src/dcl4.cpp"
typedef_info_tail -> next__12typedef_info = __1p ;
typedef_info_tail = __1p ;
}
}

# 119 "/home/claude/cfront-3/src/dcl4.cpp"
void typedef_check__FP4name (Pname __1n )
# 120 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 121 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __1cn ;
Pfct __1f ;

# 122 "/home/claude/cfront-3/src/dcl4.cpp"
__1f = get_fct_node__FP4name ( __1n ) ;

# 124 "/home/claude/cfront-3/src/dcl4.cpp"
if (! __1f )return ;

# 126 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pname __1a ;

# 126 "/home/claude/cfront-3/src/dcl4.cpp"
__1a = __1f -> argtype__3fct ;

# 126 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1a ;__1a = __1a -> __O1__4name.n_list ) { 
# 127 "/home/claude/cfront-3/src/dcl4.cpp"
__1cn = (__1a -> __O1__4expr.tp ?is_cl_obj__4typeFv ( __1a -> __O1__4expr.tp ) :(((struct name *)0 )));
if ((((! __1a -> n_xref__4name )&& __1cn )&& __1cn -> __O1__4expr.tp )&& (! ((((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))))-> defined__4type & 01 ))){
# 128 "/home/claude/cfront-3/src/dcl4.cpp"

# 129 "/home/claude/cfront-3/src/dcl4.cpp"
record_typedef__FP4name ( __1n ) ;
return ;
}
}

# 134 "/home/claude/cfront-3/src/dcl4.cpp"
__1cn = (__1f -> returns__3fct ?is_cl_obj__4typeFv ( __1f -> returns__3fct ) :(((struct name *)0 )));
if (((((! __1f -> s_returns__3fct )|| (__1f -> s_returns__3fct != (((struct type *)void_type ))))&& __1cn )&& __1cn -> __O1__4expr.tp )&& (! ((((struct classdef *)(((struct
# 135 "/home/claude/cfront-3/src/dcl4.cpp"
classdef *)__1cn -> __O1__4expr.tp ))))-> defined__4type & 01 )))
# 136 "/home/claude/cfront-3/src/dcl4.cpp"
record_typedef__FP4name ( __1n ) ;

# 136 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 136 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 139 "/home/claude/cfront-3/src/dcl4.cpp"
static void typedef_checkall__FP8classdef (Pclass __1cl )
# 140 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 141 "/home/claude/cfront-3/src/dcl4.cpp"
{ { struct typedef_info *__1p ;

# 141 "/home/claude/cfront-3/src/dcl4.cpp"
__1p = typedef_info_head ;

# 141 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1p ;__1p = __1p -> next__12typedef_info ) { 
# 142 "/home/claude/cfront-3/src/dcl4.cpp"
Pfct __2f ;
Pname __2cn ;

# 142 "/home/claude/cfront-3/src/dcl4.cpp"
__2f = get_fct_node__FP4name ( __1p -> n__12typedef_info ) ;

# 144 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pname __2a ;

# 145 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X36 ;

# 145 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X37 ;

# 144 "/home/claude/cfront-3/src/dcl4.cpp"
__2a = __2f -> argtype__3fct ;

# 144 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2a ;__2a = __2a -> __O1__4name.n_list ) { 
# 144 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X34 ;

# 144 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X35 ;

# 145 "/home/claude/cfront-3/src/dcl4.cpp"
__2cn = (__2a -> __O1__4expr.tp ?is_cl_obj__4typeFv ( __2a -> __O1__4expr.tp ) :(((struct name *)0 )));
if (((((! __2a -> n_xref__4name )&& __2cn )&& __2cn -> __O1__4expr.tp )&& ( (__1__X34 = (((struct classdef *)(((struct classdef *)__2cn -> __O1__4expr.tp ))))), (
# 146 "/home/claude/cfront-3/src/dcl4.cpp"
(__1__X35 = __1cl ), ( ((__1__X34 == __1__X35 )?1 :((__1__X34 && __1__X35 )?(((int )same_class__8classdefFP8classdefi ( __1__X34 , __1__X35 , 0 ) )):0 ))) ) ) )&&
# 146 "/home/claude/cfront-3/src/dcl4.cpp"
( __1cl -> c_itor__8classdef ) ){ 
# 147 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 147 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V28 ;

# 147 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V29 ;

# 147 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V30 ;

# 147 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & __1p -> n__12typedef_info -> where__4name , (const char *)"C%t used asAT inTdef%n before it was known that%t has a copyK",
# 147 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)( ((& __0__V28 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V28 )) , (const struct
# 147 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)__ct__2eaFPCv ( & __0__V29 , (const void *)__1p -> n__12typedef_info ) , (const struct ea *)( ((& __0__V30 )-> __O1__2ea.p =
# 147 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1cl )), (& __0__V30 )) , (const struct ea *)ea0 ) ;
break ;
} }
}
__2cn = (__2f -> returns__3fct ?is_cl_obj__4typeFv ( __2f -> returns__3fct ) :(((struct name *)0 )));
if ((((((! __2f -> s_returns__3fct )|| (__2f -> s_returns__3fct != (((struct type *)void_type ))))&& __2cn )&& __2cn -> __O1__4expr.tp )&& ( (__1__X36 = (((struct
# 152 "/home/claude/cfront-3/src/dcl4.cpp"
classdef *)(((struct classdef *)__2cn -> __O1__4expr.tp ))))), ( (__1__X37 = __1cl ), ( ((__1__X36 == __1__X37 )?1 :((__1__X36 && __1__X37 )?(((int )same_class__8classdefFP8classdefi ( __1__X36 , __1__X37 , 0 )
# 152 "/home/claude/cfront-3/src/dcl4.cpp"
)):0 ))) ) ) )&& ( __1cl -> c_itor__8classdef ) )
# 153 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 153 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V31 ;

# 153 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V32 ;

# 153 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V33 ;

# 153 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & __1p -> n__12typedef_info -> where__4name , (const char *)"C%t used as returnT inTdef%n before it was known that%t has a copyK",
# 153 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)( ((& __0__V31 )-> __O1__2ea.p = ((const void *)__1cl )), (& __0__V31 )) , (const struct
# 153 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)__ct__2eaFPCv ( & __0__V32 , (const void *)__1p -> n__12typedef_info ) , (const struct ea *)( ((& __0__V33 )-> __O1__2ea.p =
# 153 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1cl )), (& __0__V33 )) , (const struct ea *)ea0 ) ;
} 
# 153 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 153 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 154 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 154 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 157 "/home/claude/cfront-3/src/dcl4.cpp"
Pname merge_conv__FP4nameT1 (Pname __1c1 , Pname __1c2 )
# 158 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 159 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1c1 == 0 )
# 160 "/home/claude/cfront-3/src/dcl4.cpp"
return __1c2 ;
if (__1c2 == 0 )
# 162 "/home/claude/cfront-3/src/dcl4.cpp"
return __1c1 ;
if (__1c1 == __1c2 )
# 164 "/home/claude/cfront-3/src/dcl4.cpp"
return __1c1 ;
error__FiPCc ( (int )'s' , (const char *)"cannot merge lists of conversion functions") ;
return __1c1 ;
}

# 169 "/home/claude/cfront-3/src/dcl4.cpp"
static int Eppp ;

# 22 "/home/claude/incl-linux32/string.h"
extern int strncmp (const char *, const char *, size_t );

# 171 "/home/claude/cfront-3/src/dcl4.cpp"
const char *get_classname__FPCc (const char *__1s )
# 175 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 177 "/home/claude/cfront-3/src/dcl4.cpp"
const char *__1s1 ;

# 177 "/home/claude/cfront-3/src/dcl4.cpp"
__1s1 = 0 ;

# 179 "/home/claude/cfront-3/src/dcl4.cpp"
while ((*__1s )){ 
# 180 "/home/claude/cfront-3/src/dcl4.cpp"
__1s1 = __1s ;
loop :
# 182 "/home/claude/cfront-3/src/dcl4.cpp"
for(;(__1s [0 ])&& (((__1s [0 ])!= '_' )|| ((__1s [1 ])&& ((__1s [1 ])!= '_' )));__1s ++ ) ;
if ((*__1s )){ 
# 184 "/home/claude/cfront-3/src/dcl4.cpp"
if (strncmp ( __1s , (const char *)"___pt__", (unsigned long
# 184 "/home/claude/cfront-3/src/dcl4.cpp"
)7 ) == 0 ){ 
# 185 "/home/claude/cfront-3/src/dcl4.cpp"
__1s += 7 ;

# 185 "/home/claude/cfront-3/src/dcl4.cpp"
goto loop ;
}
if (strncmp ( __1s , (const char *)"__pt__", (unsigned long )6 ) ==
# 187 "/home/claude/cfront-3/src/dcl4.cpp"
0 ){ 
# 188 "/home/claude/cfront-3/src/dcl4.cpp"
__1s += 6 ;

# 188 "/home/claude/cfront-3/src/dcl4.cpp"
goto loop ;
}
if ((__1s [1 ])== 0 )++ __1s ;
else __1s += 2 ;
}
}

# 195 "/home/claude/cfront-3/src/dcl4.cpp"
return __1s1 ;
}

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 80 "/home/claude/incl-linux32/stdio.h"
extern int sprintf (char *, const char *,...);

# 198 "/home/claude/cfront-3/src/dcl4.cpp"
char *drop_classname__FPCc (const char *__1s0 )
# 202 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 204 "/home/claude/cfront-3/src/dcl4.cpp"
char *__1r ;

# 204 "/home/claude/cfront-3/src/dcl4.cpp"
__1r = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __1s0 ) + 1 ))) ));
sprintf ( __1r , (const char *)"%s", __1s0 ) ;
{ char *__1s ;

# 208 "/home/claude/cfront-3/src/dcl4.cpp"
char *__1s1 ;

# 206 "/home/claude/cfront-3/src/dcl4.cpp"
__1s = __1r ;

# 208 "/home/claude/cfront-3/src/dcl4.cpp"
__1s1 = __1s ;
while ((*__1s )){ 
# 210 "/home/claude/cfront-3/src/dcl4.cpp"
loop :
# 211 "/home/claude/cfront-3/src/dcl4.cpp"
for(;(__1s [0 ])&& (((__1s [0 ])!= '_' )|| ((__1s [1 ])&& ((__1s [1 ])!= '_' )));__1s ++ ) ;
if ((*__1s )){ 
# 213 "/home/claude/cfront-3/src/dcl4.cpp"
if (strncmp ( (const char *)__1s , (const char *)"___pt__",
# 213 "/home/claude/cfront-3/src/dcl4.cpp"
(unsigned long )7 ) == 0 ){ 
# 214 "/home/claude/cfront-3/src/dcl4.cpp"
__1s += 7 ;

# 214 "/home/claude/cfront-3/src/dcl4.cpp"
goto loop ;
}
if (strncmp ( (const char *)__1s , (const char *)"__pt__", (unsigned long
# 216 "/home/claude/cfront-3/src/dcl4.cpp"
)6 ) == 0 ){ 
# 217 "/home/claude/cfront-3/src/dcl4.cpp"
__1s += 6 ;

# 217 "/home/claude/cfront-3/src/dcl4.cpp"
goto loop ;
}
if ((__1s [1 ])== 0 ){ __1s1 = (++ __1s );

# 219 "/home/claude/cfront-3/src/dcl4.cpp"
break ;

# 219 "/home/claude/cfront-3/src/dcl4.cpp"
}
__1s1 = __1s ;
__1s += 2 ;
}
}

# 225 "/home/claude/cfront-3/src/dcl4.cpp"
((*__1s1 ))= '\0' ;
return (((*__1r ))?__1r :(((char *)0 )));

# 226 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 234 "/home/claude/cfront-3/src/cfront.h"

# 348 "/home/claude/cfront-3/src/cfront.h"
bit is_const_object__4typeFv (struct type *__0this );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 229 "/home/claude/cfront-3/src/dcl4.cpp"
bit has_const_mem__8classdefFv (register struct classdef *__0this )
# 233 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 234 "/home/claude/cfront-3/src/dcl4.cpp"
int __1i ;
{ { Pname __1m ;

# 236 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X38 ;

# 236 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X39 ;

# 236 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X40 ;

# 236 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X41 ;

# 235 "/home/claude/cfront-3/src/dcl4.cpp"
__1m = ( (__0__X40 = __0this -> memtbl__8classdef ), ( (__2__X41 = (__1i = 1 )), ( (((__2__X41 <= 0 )|| (__0__X40 -> free_slot__5table <=
# 235 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X41 ))?(((struct name *)0 )):(__0__X40 -> entries__5table [__2__X41 ]))) ) ) ;

# 235 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1m ;__1m = (__1m -> n_tbl_list__4name ?__1m -> n_tbl_list__4name :( (__0__X38 = __0this -> memtbl__8classdef ), ( (__2__X39 = (++ __1i )), ( (((__2__X39 <= 0 )||
# 235 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X38 -> free_slot__5table <= __2__X39 ))?(((struct name *)0 )):(__0__X38 -> entries__5table [__2__X39 ]))) ) ) )) 
# 236 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1m && __1m -> __O1__4expr.tp )
# 237 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__1m -> __O1__4expr.tp ->
# 237 "/home/claude/cfront-3/src/dcl4.cpp"
base__4node ){ 
# 238 "/home/claude/cfront-3/src/dcl4.cpp"
case 108 :break ;
case 76 :break ;
case 121 :break ;
default :
# 242 "/home/claude/cfront-3/src/dcl4.cpp"
if (is_const_object__4typeFv ( __1m -> __O1__4expr.tp ) && (__1m -> n_stclass__4name != 31 ))return (unsigned char )1 ;
}

# 245 "/home/claude/cfront-3/src/dcl4.cpp"
return (unsigned char )0 ;

# 245 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 245 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 248 "/home/claude/cfront-3/src/dcl4.cpp"
Pbcl get_base__8classdefFPCc (register struct classdef *__0this , const char *__1s )
# 252 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 254 "/home/claude/cfront-3/src/dcl4.cpp"
Pbcl __1b ;

# 254 "/home/claude/cfront-3/src/dcl4.cpp"
__1b = __0this -> baselist__8classdef ;
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 257 "/home/claude/cfront-3/src/dcl4.cpp"
const char *__2s1 ;

# 257 "/home/claude/cfront-3/src/dcl4.cpp"
const char *__2s2 ;

# 257 "/home/claude/cfront-3/src/dcl4.cpp"
__2s1 = __1s ;

# 257 "/home/claude/cfront-3/src/dcl4.cpp"
__2s2 = __1b -> bclass__6basecl -> string__8classdef ;
for(;(((*__2s1 ))&& ((*__2s2 )))&& (((*__2s1 ))== ((*__2s2 )));( (__2s1 ++ ), (__2s2 ++ )) ) 
# 259 "/home/claude/cfront-3/src/dcl4.cpp"
;

# 261 "/home/claude/cfront-3/src/dcl4.cpp"
if (! (((*__2s1 ))|| ((*__2s2 ))))
# 262 "/home/claude/cfront-3/src/dcl4.cpp"
break ;
}

# 265 "/home/claude/cfront-3/src/dcl4.cpp"
return __1b ;
}

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 481 "/home/claude/cfront-3/src/cfront.h"
int has_allocated_base__8classdefFP8classdefUc (struct classdef *__0this , Pclass , bit );

# 269 "/home/claude/cfront-3/src/dcl4.cpp"
static int offset_magic_0__FP6baseclT1s (Pbcl __1b , Pbcl __1bb , short __1virt_count )
# 270 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 273 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __1bcl ;
int __1offset ;

# 273 "/home/claude/cfront-3/src/dcl4.cpp"
__1bcl = __1bb -> bclass__6basecl ;
__1offset = 0 ;
{ { Pbcl __1l ;

# 275 "/home/claude/cfront-3/src/dcl4.cpp"
__1l = __1b ;

# 275 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1l ;__1l = __1l -> next__6basecl ) { 
# 276 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1l -> base__4node == 77 )continue ;
{ Pclass __2bc ;

# 277 "/home/claude/cfront-3/src/dcl4.cpp"
__2bc = __1l -> bclass__6basecl ;
{ { Pbcl __2ll ;

# 278 "/home/claude/cfront-3/src/dcl4.cpp"
__2ll = __2bc -> baselist__8classdef ;

# 278 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2ll ;__2ll = __2ll -> next__6basecl ) { 
# 279 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2ll -> base__4node != 77 )continue ;
{ int __3diff ;

# 280 "/home/claude/cfront-3/src/dcl4.cpp"
__3diff = strcmp ( __1bcl -> string__8classdef , __2ll -> bclass__6basecl -> string__8classdef ) ;

# 282 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__2ll -> allocated__6basecl == 1 )&& (! __3diff )){ 
# 283 "/home/claude/cfront-3/src/dcl4.cpp"
__1offset = (__2ll -> obj_offset__6basecl + __1l -> obj_offset__6basecl );

# 285 "/home/claude/cfront-3/src/dcl4.cpp"
return __1offset ;
}

# 289 "/home/claude/cfront-3/src/dcl4.cpp"
if (__3diff && (__2ll -> allocated__6basecl == 1 )){ 
# 290 "/home/claude/cfront-3/src/dcl4.cpp"
__1offset = has_allocated_base__8classdefFP8classdefUc ( __2ll -> bclass__6basecl , __1bcl , (unsigned char )0 ) ;
# 290 "/home/claude/cfront-3/src/dcl4.cpp"

# 291 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1offset ){ 
# 292 "/home/claude/cfront-3/src/dcl4.cpp"
if (! __1virt_count )
# 293 "/home/claude/cfront-3/src/dcl4.cpp"
__1offset += __1l -> obj_offset__6basecl ;

# 295 "/home/claude/cfront-3/src/dcl4.cpp"
return __1offset ;
}
}

# 297 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 298 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 298 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 298 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 301 "/home/claude/cfront-3/src/dcl4.cpp"
if (Nvbc_alloc ){ 
# 302 "/home/claude/cfront-3/src/dcl4.cpp"
__1offset = (__1bb -> obj_offset__6basecl - Nvbc_alloc -> obj_offset__6basecl );
if (__1virt_count )__1offset += 4 ;

# 305 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 308 "/home/claude/cfront-3/src/dcl4.cpp"
return __1offset ;

# 308 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 308 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 312 "/home/claude/cfront-3/src/dcl4.cpp"
static int offset_magic_1__FP6baseclT1 (Pbcl __1b , Pbcl __1bl )
# 313 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 315 "/home/claude/cfront-3/src/dcl4.cpp"
const char *__1str ;

# 315 "/home/claude/cfront-3/src/dcl4.cpp"
__1str = __1b -> bclass__6basecl -> string__8classdef ;
{ { Pbcl __1bb ;

# 316 "/home/claude/cfront-3/src/dcl4.cpp"
__1bb = __1bl -> bclass__6basecl -> baselist__8classdef ;

# 316 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1bb ;__1bb = __1bb -> next__6basecl ) { 
# 317 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1bb -> base__4node != 77 )continue ;
{ const char *__2s ;

# 318 "/home/claude/cfront-3/src/dcl4.cpp"
__2s = __1bb -> bclass__6basecl -> string__8classdef ;
if (strcmp ( __2s , __1str ) == 0 ){ 
# 320 "/home/claude/cfront-3/src/dcl4.cpp"
int __3offset ;

# 320 "/home/claude/cfront-3/src/dcl4.cpp"
__3offset = ((__1bb -> obj_offset__6basecl - __1bb -> ptr_offset__6basecl )+ 1 );

# 322 "/home/claude/cfront-3/src/dcl4.cpp"
return (__3offset + __1bl -> obj_offset__6basecl );
}

# 323 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 328 "/home/claude/cfront-3/src/dcl4.cpp"
return 0 ;

# 328 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 328 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 332 "/home/claude/cfront-3/src/dcl4.cpp"
extern int link_compat_hack ;
static int Voffset ;
bit Vvtab = 0 ;
bit Vvbc_alloc = 0 ;
bit Vvbc_inher = 0 ;

# 482 "/home/claude/cfront-3/src/cfront.h"
const char *has_allocated_base__8classdefFPCc (struct classdef *__0this , const char *);

# 338 "/home/claude/cfront-3/src/dcl4.cpp"
int get_offset__8classdefFPCcUc (struct classdef *__0this , const char *__1s , bit __1rechk );

# 338 "/home/claude/cfront-3/src/dcl4.cpp"
int get_offset__8classdefFPCcUc (register struct classdef *__0this , const char *__1s , bit __1rechk )
# 340 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 342 "/home/claude/cfront-3/src/dcl4.cpp"
if (! __1s )return 0 ;

# 344 "/home/claude/cfront-3/src/dcl4.cpp"
{ const char *__1str ;
Pbcl __1b ;

# 347 "/home/claude/cfront-3/src/dcl4.cpp"
bit __1unalloc ;
const char *__1found_virtual ;

# 344 "/home/claude/cfront-3/src/dcl4.cpp"
__1str = get_classname__FPCc ( __1s ) ;
__1b = get_base__8classdefFPCc ( __0this , __1str ) ;

# 347 "/home/claude/cfront-3/src/dcl4.cpp"
__1unalloc = 0 ;
__1found_virtual = 0 ;

# 350 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1rechk ){ 
# 352 "/home/claude/cfront-3/src/dcl4.cpp"
__1unalloc = (__1b -> promoted__6basecl && (__1b -> allocated__6basecl != 1 ));

# 355 "/home/claude/cfront-3/src/dcl4.cpp"
if (! __1unalloc )return 0 ;
Vvtab = 0 ;
Vvbc_inher = 0 ;
Vvbc_alloc = 0 ;
Nvbc_alloc = 0 ;
__1found_virtual = has_allocated_base__8classdefFPCc ( __0this , __1str ) ;
}

# 363 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1unalloc ){ 
# 365 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1found_virtual == 0 ){ 
# 366 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vvbc_alloc && __1b -> bclass__6basecl -> baselist__8classdef )
# 367 "/home/claude/cfront-3/src/dcl4.cpp"
return __1b -> obj_offset__6basecl ;

# 369 "/home/claude/cfront-3/src/dcl4.cpp"
if (strcmp ( __1s , __1str ) ){ 
# 370 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vvbc_inher )
# 371 "/home/claude/cfront-3/src/dcl4.cpp"
return 0 ;

# 373 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vvtab == 0 )
# 374 "/home/claude/cfront-3/src/dcl4.cpp"
return get_offset__8classdefFPCcUc ( __1b -> bclass__6basecl , (const char *)drop_classname__FPCc ( __1s ) , (unsigned char )0 )
# 374 "/home/claude/cfront-3/src/dcl4.cpp"
;

# 376 "/home/claude/cfront-3/src/dcl4.cpp"
return (__1b -> obj_offset__6basecl + get_offset__8classdefFPCcUc ( __1b -> bclass__6basecl , (const char *)drop_classname__FPCc ( __1s ) , (unsigned char )0 )
# 376 "/home/claude/cfront-3/src/dcl4.cpp"
);
}
else { 
# 379 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vvbc_inher ){ 
# 380 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1b -> allocated__6basecl == 2 )
# 381 "/home/claude/cfront-3/src/dcl4.cpp"
link_compat_hack = __1b -> obj_offset__6basecl ;
return 0 ;
}
return offset_magic_0__FP6baseclT1s ( __0this -> baselist__8classdef -> next__6basecl , __1b , __0this -> virt_count__8classdef ) ;
}
}

# 388 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1found_virtual ){ 
# 389 "/home/claude/cfront-3/src/dcl4.cpp"
if (strcmp ( __1s , __1str ) )
# 390 "/home/claude/cfront-3/src/dcl4.cpp"
return offset_magic_1__FP6baseclT1 ( __1b , get_base__8classdefFPCc ( __0this , __1found_virtual ) ) ;
# 390 "/home/claude/cfront-3/src/dcl4.cpp"
else 
# 391 "/home/claude/cfront-3/src/dcl4.cpp"
return __1b -> obj_offset__6basecl ;
}
}

# 395 "/home/claude/cfront-3/src/dcl4.cpp"
return (__1b -> obj_offset__6basecl + get_offset__8classdefFPCcUc ( __1b -> bclass__6basecl , (const char *)drop_classname__FPCc ( __1s ) , (unsigned char )0 )
# 395 "/home/claude/cfront-3/src/dcl4.cpp"
);

# 395 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 398 "/home/claude/cfront-3/src/dcl4.cpp"
const char *vtbl_str__FPCcT1 (const char *__1s1 , const char *__1s2 )
# 402 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 404 "/home/claude/cfront-3/src/dcl4.cpp"
char *__1s3 ;
if (__1s1 )
# 406 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1s2 ){ 
# 407 "/home/claude/cfront-3/src/dcl4.cpp"
__1s3 = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* ((strlen ( __1s1 ) +
# 407 "/home/claude/cfront-3/src/dcl4.cpp"
strlen ( __1s2 ) )+ 3 ))) ));
sprintf ( __1s3 , (const char *)"%s__%s", __1s1 , __1s2 ) ;
return (const char *)__1s3 ;
}
else 
# 412 "/home/claude/cfront-3/src/dcl4.cpp"
return __1s1 ;
else 
# 414 "/home/claude/cfront-3/src/dcl4.cpp"
return __1s2 ;
}

# 394 "/home/claude/cfront-3/src/cfront.h"

# 381 "/home/claude/cfront-3/src/cfront.h"
struct velem {	/* sizeof velem == 16 */
Pname n__5velem ;
int offset__5velem ;
};

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 417 "/home/claude/cfront-3/src/dcl4.cpp"
void add_vtbl__8classdefFP5velemPCcUci (register struct classdef *__0this , struct velem *__1v , const char *__1s , bit __1virt_flag , int __1n_init )
# 421 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 423 "/home/claude/cfront-3/src/dcl4.cpp"
Pvirt __1vtab ;

# 424 "/home/claude/cfront-3/src/dcl4.cpp"
register struct virt *__0__X44 ;

# 424 "/home/claude/cfront-3/src/dcl4.cpp"
struct node *__0__X3 ;

# 423 "/home/claude/cfront-3/src/dcl4.cpp"
__1vtab = ( (__0__X44 = 0 ), ( ((__0__X44 || (__0__X44 = (struct virt *)__nw__FUl ( (unsigned long )(sizeof (struct virt))) ))?(
# 423 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X44 = (struct virt *)( (__0__X3 = (((struct node *)__0__X44 ))), ( ((__0__X3 || (__0__X3 = (struct node *)__nw__FUl ( (unsigned long )(sizeof
# 423 "/home/claude/cfront-3/src/dcl4.cpp"
(struct node))) ))?( ( (__0__X3 -> base__4node = 0 ), (__0__X3 -> permanent__4node = 0 )) , (__0__X3 -> baseclass__4node = 0 )) :0 ),
# 423 "/home/claude/cfront-3/src/dcl4.cpp"
__0__X3 ) ) ), ( (__0__X44 -> base__4node = 200 ), ( (__0__X44 -> vclass__4virt = __0this ), ( (__0__X44 -> virt_init__4virt =
# 423 "/home/claude/cfront-3/src/dcl4.cpp"
__1v ), ( (__0__X44 -> string__4virt = __1s ), ( (__0__X44 -> is_vbase__4virt = __1virt_flag ), ( (__0__X44 -> next__4virt = 0 ), (
# 423 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X44 -> n_init__4virt = __1n_init ), (__0__X44 -> printed__4virt = 0 )) ) ) ) ) ) ) ) :0 ),
# 423 "/home/claude/cfront-3/src/dcl4.cpp"
__0__X44 ) ) ;

# 425 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1virt_flag )
# 426 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> has_vvtab__8classdef = 1 ;

# 428 "/home/claude/cfront-3/src/dcl4.cpp"
if (! __0this -> virt_list__8classdef ){ 
# 429 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> virt_list__8classdef = __1vtab ;
return ;
}

# 435 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pvirt __1vt ;

# 435 "/home/claude/cfront-3/src/dcl4.cpp"
__1vt = __0this -> virt_list__8classdef ;

# 435 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1vt ;__1vt = __1vt -> next__4virt ) 
# 436 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1vt -> string__4virt && (strcmp ( __1vt -> string__4virt , __1s ) == 0 )){ 
# 437 "/home/claude/cfront-3/src/dcl4.cpp"
struct velem *__2ivec ;
# 437 "/home/claude/cfront-3/src/dcl4.cpp"

# 438 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2on ;
Pname __2nn ;
Pclass __2ocl ;

# 440 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __2ncl ;

# 437 "/home/claude/cfront-3/src/dcl4.cpp"
__2ivec = __1vt -> virt_init__4virt ;
__2on = (__2ivec [0 ]). n__5velem ;
__2nn = (__1v [0 ]). n__5velem ;

# 441 "/home/claude/cfront-3/src/dcl4.cpp"
{ { int __2i ;

# 441 "/home/claude/cfront-3/src/dcl4.cpp"
__2i = 0 ;

# 441 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2on && __2nn ;( ( (__2i ++ ), (__2on = (__2ivec [__2i ]). n__5velem )) , (__2nn = (__1v [__2i ]). n__5velem )) ) {
# 441 "/home/claude/cfront-3/src/dcl4.cpp"

# 442 "/home/claude/cfront-3/src/dcl4.cpp"
__2ocl = (((struct fct *)(((struct fct *)__2on -> __O1__4expr.tp ))))-> memof__3fct ;
__2ncl = (((struct fct *)(((struct fct *)__2nn -> __O1__4expr.tp ))))-> memof__3fct ;
if (__2on != __2nn )
# 445 "/home/claude/cfront-3/src/dcl4.cpp"
if (! has_base__8classdefFP8classdefiT2 ( __2ocl , __2ncl , 0 , 0 ) )
# 446 "/home/claude/cfront-3/src/dcl4.cpp"
if (! has_base__8classdefFP8classdefiT2 ( __2ncl , __2ocl ,
# 446 "/home/claude/cfront-3/src/dcl4.cpp"
0 , 0 ) )
# 447 "/home/claude/cfront-3/src/dcl4.cpp"
break ;
else { 
# 449 "/home/claude/cfront-3/src/dcl4.cpp"
(__2ivec [__2i ]). n__5velem = __2nn ;
(__2ivec [__2i ]). offset__5velem = (__1v [__2i ]). offset__5velem ;
}
}
if (__2on || __2nn )
# 454 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 454 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V42 ;

# 454 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V43 ;

# 454 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"virtualB: ambiguous%n and%n", (const struct ea *)( ((& __0__V42 )-> __O1__2ea.p =
# 454 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__2on )), (& __0__V42 )) , (const struct ea *)( ((& __0__V43 )-> __O1__2ea.p = ((const void
# 454 "/home/claude/cfront-3/src/dcl4.cpp"
*)__2nn )), (& __0__V43 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} return ;

# 455 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 455 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 458 "/home/claude/cfront-3/src/dcl4.cpp"
__1vtab -> next__4virt = __0this -> virt_list__8classdef -> next__4virt ;
__0this -> virt_list__8classdef -> next__4virt = __1vtab ;

# 459 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 459 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 462 "/home/claude/cfront-3/src/dcl4.cpp"
static int baseoffset__FP8classdefT1 (Pclass __1b , Pclass __1d );

# 462 "/home/claude/cfront-3/src/dcl4.cpp"
static int baseoffset__FP8classdefT1 (Pclass __1b , Pclass __1d )
# 466 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 479 "/home/claude/cfront-3/src/dcl4.cpp"
Pbcl __1bx ;

# 480 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X45 ;

# 480 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X46 ;

# 467 "/home/claude/cfront-3/src/dcl4.cpp"
static int __1level = 0 ;
++ __1level ;

# 470 "/home/claude/cfront-3/src/dcl4.cpp"
if ((! __1b )|| (! __1d )){ 
# 471 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCc ( (int )'i' , (const char *)"invalidA to baseoffset()")
# 471 "/home/claude/cfront-3/src/dcl4.cpp"
;
}

# 474 "/home/claude/cfront-3/src/dcl4.cpp"
if (( (__1__X45 = __1b ), ( (__1__X46 = __1d ), ( ((__1__X45 == __1__X46 )?1 :((__1__X45 && __1__X46 )?(((int )same_class__8classdefFP8classdefi ( __1__X45 , __1__X46 ,
# 474 "/home/claude/cfront-3/src/dcl4.cpp"
0 ) )):0 ))) ) ) ){ 
# 475 "/home/claude/cfront-3/src/dcl4.cpp"
__1level -- ;
return 0 ;
}

# 479 "/home/claude/cfront-3/src/dcl4.cpp"
;

# 482 "/home/claude/cfront-3/src/dcl4.cpp"
for(__1bx = __1d -> baselist__8classdef ;__1bx ;__1bx = __1bx -> next__6basecl ) 
# 483 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 483 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X47 ;

# 483 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X48 ;

# 484 "/home/claude/cfront-3/src/dcl4.cpp"
if (( (__1__X47 = __1b ), ( (__1__X48 = __1bx -> bclass__6basecl ), ( ((__1__X47 == __1__X48 )?1 :((__1__X47 && __1__X48 )?(((int )same_class__8classdefFP8classdefi ( __1__X47 ,
# 484 "/home/claude/cfront-3/src/dcl4.cpp"
__1__X48 , 0 ) )):0 ))) ) ) ){ 
# 485 "/home/claude/cfront-3/src/dcl4.cpp"
__1level -- ;
return __1bx -> obj_offset__6basecl ;
}
}

# 491 "/home/claude/cfront-3/src/dcl4.cpp"
for(__1bx = __1d -> baselist__8classdef ;__1bx ;__1bx = __1bx -> next__6basecl ) 
# 492 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 494 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1bx -> promoted__6basecl )
# 495 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;
{ int __2found ;

# 496 "/home/claude/cfront-3/src/dcl4.cpp"
__2found = baseoffset__FP8classdefT1 ( __1b , __1bx -> bclass__6basecl ) ;
if (__2found != -1){ 
# 498 "/home/claude/cfront-3/src/dcl4.cpp"
__1level -- ;
return (__1bx -> obj_offset__6basecl + __2found );
}

# 500 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 503 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__1level -- )> 1 )
# 504 "/home/claude/cfront-3/src/dcl4.cpp"
return -1;

# 506 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCc ( (int )'i' , (const char *)"fall off end of baseoffset()") ;
return 0 ;
}

# 510 "/home/claude/cfront-3/src/dcl4.cpp"
int vcounter = 0 ;
static int vmax ;

# 234 "/home/claude/cfront-3/src/cfront.h"

# 514 "/home/claude/cfront-3/src/dcl4.cpp"
int do_virtuals__8classdefFP4virtPCciUc (register struct classdef *__0this , Pvirt __1vtab , const char *__1str , int __1leftmost , bit __1virt_flag )
# 520 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 521 "/home/claude/cfront-3/src/dcl4.cpp"
if (vmax < vcounter )
# 522 "/home/claude/cfront-3/src/dcl4.cpp"
vmax =
# 522 "/home/claude/cfront-3/src/dcl4.cpp"
vcounter ;
{ int __1vpsz ;

# 523 "/home/claude/cfront-3/src/dcl4.cpp"
__1vpsz = (((vmax + vcounter )/ 32)+ 1 );
__1vpsz *= 32;
{ Pname *__1vp ;
struct velem *__1ivec ;
int __1vo ;
int __1vc ;
int __1changed ;

# 525 "/home/claude/cfront-3/src/dcl4.cpp"
__1vp = (((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* __1vpsz )) ));
__1ivec = (__1vtab ?__1vtab -> virt_init__4virt :(((struct velem *)0 )));
__1vo = Voffset ;
__1vc = 0 ;
__1changed = 0 ;

# 534 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1ivec ){ 
# 542 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2vn ;
int __2i ;

# 535 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1vtab -> is_vbase__4virt ){ 
# 536 "/home/claude/cfront-3/src/dcl4.cpp"
__1str = 0 ;
Voffset = get_offset__8classdefFPCcUc ( __0this , __1vtab -> string__4virt , (unsigned char )0 ) ;

# 539 "/home/claude/cfront-3/src/dcl4.cpp"
}
else 
# 541 "/home/claude/cfront-3/src/dcl4.cpp"
Voffset = (Voffset + get_offset__8classdefFPCcUc ( __1vtab -> vclass__4virt , __1vtab -> string__4virt , (unsigned char )0 ) );
;
__2i = 0 ;
for(;__2vn = (__1ivec [__2i ]). n__5velem ;__2i ++ ) { 
# 551 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2i >= __1vpsz ){ 
# 552 "/home/claude/cfront-3/src/dcl4.cpp"
int __4tvpsz ;
Pname *__4tvp ;

# 552 "/home/claude/cfront-3/src/dcl4.cpp"
__4tvpsz = (__1vpsz + 32);
__4tvp = (((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* __4tvpsz )) ));
{ { int __4j ;

# 554 "/home/claude/cfront-3/src/dcl4.cpp"
__4j = 0 ;

# 554 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4j < __2i ;++ __4j ) 
# 555 "/home/claude/cfront-3/src/dcl4.cpp"
(__4tvp [__4j ])= (__1vp [__4j ]);
__dl__FPv ( (void *)__1vp ) ;
__1vp = __4tvp ;

# 559 "/home/claude/cfront-3/src/dcl4.cpp"
__1vpsz = __4tvpsz ;

# 559 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 559 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 562 "/home/claude/cfront-3/src/dcl4.cpp"
{ const char *__3s ;
Pname __3n ;

# 562 "/home/claude/cfront-3/src/dcl4.cpp"
__3s = __2vn -> n_gen_fct_name__4name ;
__3n = look__5tableFPCcUc ( __0this -> memtbl__8classdef , __3s ?__3s :__2vn -> __O2__4expr.string , (unsigned char )0 ) ;

# 567 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__3n == 0 )|| (__3n -> base__4node == 25 )){ 
# 569 "/home/claude/cfront-3/src/dcl4.cpp"
inher :
# 570 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2vn -> __O3__4expr.n_initializer ){ 
# 571 "/home/claude/cfront-3/src/dcl4.cpp"
if (! get_vf__FP4nameP8classdef ( __2vn , __0this )
# 571 "/home/claude/cfront-3/src/dcl4.cpp"
){ 
# 572 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_abstract__8classdef = __2vn ;
}
}
(__1vp [__2i ])= __2vn ;
if ((__1ivec [__2i ]). offset__5velem && __1vtab -> is_vbase__4virt ){ 
# 580 "/home/claude/cfront-3/src/dcl4.cpp"
(__1vp [__2i ])-> n_offset__4name = (Voffset - baseoffset__FP8classdefT1 ( (((struct fct *)(((struct fct *)__2vn -> __O1__4expr.tp ))))-> memof__3fct ,
# 580 "/home/claude/cfront-3/src/dcl4.cpp"
__0this ) );
}
else (__1vp [__2i ])-> n_offset__4name = (__1ivec [__2i ]). offset__5velem ;
continue ;
}

# 586 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pfct __3f ;

# 586 "/home/claude/cfront-3/src/dcl4.cpp"
__3f = (((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))));
if (__3f == 0 )continue ;

# 589 "/home/claude/cfront-3/src/dcl4.cpp"
if (__3s && (__3f -> base__4node == 76 )){ 
# 592 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Plist __4gl ;

# 592 "/home/claude/cfront-3/src/dcl4.cpp"
__4gl = (((struct gen *)(((struct gen *)__3f ))))-> fct_list__3gen ;

# 592 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) 
# 593 "/home/claude/cfront-3/src/dcl4.cpp"
if (__4gl -> f__9name_list == __2vn )
# 594 "/home/claude/cfront-3/src/dcl4.cpp"
goto inher ;

# 594 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 594 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 597 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pfct __3vnf ;

# 597 "/home/claude/cfront-3/src/dcl4.cpp"
__3vnf = (((struct fct *)(((struct fct *)__2vn -> __O1__4expr.tp ))));
switch (__3f -> base__4node ){ 
# 599 "/home/claude/cfront-3/src/dcl4.cpp"
default :
# 600 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 600 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V49 ;

# 600 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V50 ;

# 600 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __3n -> where__4name , (const char *)"%n hides virtual%n", (const
# 600 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea *)( ((& __0__V49 )-> __O1__2ea.p = ((const void *)__3n )), (& __0__V49 )) , (const struct ea *)(
# 600 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V50 )-> __O1__2ea.p = ((const void *)__2vn )), (& __0__V50 )) , (const struct ea *)ea0 , (const struct
# 600 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
(__1vp [__2i ])= __2vn ;
if (__2vn -> __O3__4expr.n_initializer ){ 
# 603 "/home/claude/cfront-3/src/dcl4.cpp"
if (! get_vf__FP4nameP8classdef ( __2vn , __0this ) ){ 
# 604 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_abstract__8classdef = __2vn ;
}
}
if ((__1ivec [__2i ]). offset__5velem && __1vtab -> is_vbase__4virt ){ 
# 608 "/home/claude/cfront-3/src/dcl4.cpp"
if ((Voffset - __1vo )!= (__1ivec [__2i ]). offset__5velem ){ 
# 611 "/home/claude/cfront-3/src/dcl4.cpp"
int __6noffset ;

# 611 "/home/claude/cfront-3/src/dcl4.cpp"
__6noffset = get_offset__8classdefFPCcUc ( __0this , __1vtab -> string__4virt , (unsigned char )1 ) ;
if (__6noffset && (__6noffset != Voffset ))
# 613 "/home/claude/cfront-3/src/dcl4.cpp"
__6noffset -= __1vo ;
if (__6noffset == 0 ){ 
# 615 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vvbc_inher )
# 618 "/home/claude/cfront-3/src/dcl4.cpp"
__6noffset = (link_compat_hack ?(link_compat_hack - (__1ivec [__2i ]). offset__5velem ):(__1ivec [__2i ]). offset__5velem );
else __6noffset = (Voffset - __1vo );
}
(__1vp [__2i ])-> n_offset__4name = __6noffset ;
}
else (__1vp [__2i ])-> n_offset__4name = (Voffset - __1vo );
}
else (__1vp [__2i ])-> n_offset__4name = (__1ivec [__2i ]). offset__5velem ;
break ;
case 108 :
# 628 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 629 "/home/claude/cfront-3/src/dcl4.cpp"
if (check__4typeFP4typeUcT2 ( (struct type *)__3vnf , (struct type *)__3f , (unsigned char )77 , (unsigned char )0 )
# 629 "/home/claude/cfront-3/src/dcl4.cpp"
== 0 ){ 
# 632 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vcheckerror )
# 633 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 633 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V51 ;

# 633 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad virtualT match for %n", (const struct ea *)( ((& __0__V51 )-> __O1__2ea.p =
# 633 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__2vn )), (& __0__V51 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 633 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} if (__3f -> f_virtual__3fct == 22222 )
# 635 "/home/claude/cfront-3/src/dcl4.cpp"
__3f -> f_virtual__3fct = (__2i + 1 );
(__1vp [__2i ])= __3n ;
(__1vp [__2i ])-> n_offset__4name = Voffset ;
__1changed = 1 ;
}
else { 
# 641 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vcheckerror )
# 642 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 642 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V52 ;

# 642 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad virtualT match for %n", (const struct ea *)( ((& __0__V52 )-> __O1__2ea.p =
# 642 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__2vn )), (& __0__V52 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 642 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} else { 
# 646 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2vn -> __O3__4expr.n_initializer ){ 
# 647 "/home/claude/cfront-3/src/dcl4.cpp"
if (! get_vf__FP4nameP8classdef ( __2vn , __0this ) ){ 
# 648 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_abstract__8classdef =
# 648 "/home/claude/cfront-3/src/dcl4.cpp"
__2vn ;
}
}
{ 
# 651 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V53 ;

# 651 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V54 ;

# 651 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __3n -> where__4name , (const char *)"%n hides virtual%n", (const
# 651 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea *)( ((& __0__V53 )-> __O1__2ea.p = ((const void *)__3n )), (& __0__V53 )) , (const struct ea *)(
# 651 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V54 )-> __O1__2ea.p = ((const void *)__2vn )), (& __0__V54 )) , (const struct ea *)ea0 , (const struct
# 651 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} }
(__1vp [__2i ])= __2vn ;
if ((__1ivec [__2i ]). offset__5velem && __1vtab -> is_vbase__4virt ){ 
# 655 "/home/claude/cfront-3/src/dcl4.cpp"
if ((Voffset - __1vo )!= (__1ivec [__2i ]). offset__5velem ){ 
# 658 "/home/claude/cfront-3/src/dcl4.cpp"
int __8noffset ;

# 658 "/home/claude/cfront-3/src/dcl4.cpp"
__8noffset = get_offset__8classdefFPCcUc ( __0this , __1vtab -> string__4virt , (unsigned char )1 ) ;
if (__8noffset && (__8noffset != Voffset ))
# 660 "/home/claude/cfront-3/src/dcl4.cpp"
__8noffset -= __1vo ;
if (__8noffset == 0 ){ 
# 662 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vvbc_inher )
# 665 "/home/claude/cfront-3/src/dcl4.cpp"
__8noffset = (link_compat_hack ?(link_compat_hack - (__1ivec [__2i ]). offset__5velem ):(__1ivec [__2i ]). offset__5velem );
else __8noffset = (Voffset - __1vo );
}
(__1vp [__2i ])-> n_offset__4name = __8noffset ;
}
else (__1vp [__2i ])-> n_offset__4name = (Voffset - __1vo );
}
else (__1vp [__2i ])-> n_offset__4name = (__1ivec [__2i ]). offset__5velem ;
}
break ;
}
case 76 :
# 677 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 678 "/home/claude/cfront-3/src/dcl4.cpp"
int __5hit ;

# 678 "/home/claude/cfront-3/src/dcl4.cpp"
__5hit = 0 ;
{ { Plist __5gl ;

# 679 "/home/claude/cfront-3/src/dcl4.cpp"
__5gl = (((struct gen *)(((struct gen *)__3f ))))-> fct_list__3gen ;

# 679 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__5gl ;__5gl = __5gl -> l__9name_list ) { 
# 681 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __6fn ;
Pfct __6f ;

# 681 "/home/claude/cfront-3/src/dcl4.cpp"
__6fn = __5gl -> f__9name_list ;
__6f = (((struct fct *)(((struct fct *)__6fn -> __O1__4expr.tp ))));

# 684 "/home/claude/cfront-3/src/dcl4.cpp"
if (check__4typeFP4typeUcT2 ( (struct type *)__6f , (struct type *)__3vnf , (unsigned char )77 , (unsigned char )0 ) == 0 ){
# 684 "/home/claude/cfront-3/src/dcl4.cpp"

# 685 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vcheckerror )
# 686 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 686 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V55 ;

# 686 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad virtualT match for %n", (const struct ea *)( ((& __0__V55 )-> __O1__2ea.p =
# 686 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__2vn )), (& __0__V55 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 686 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} if (__6f -> f_virtual__3fct == 22222 )
# 688 "/home/claude/cfront-3/src/dcl4.cpp"
__6f -> f_virtual__3fct = (__2i + 1 );
(__1vp [__2i ])= __6fn ;
(__1vp [__2i ])-> n_offset__4name = Voffset ;
__1changed = 1 ;
goto found ;
}
else { 
# 695 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vcheckerror )
# 696 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 696 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V56 ;

# 696 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad virtualT match for %n", (const struct ea *)( ((& __0__V56 )-> __O1__2ea.p =
# 696 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__2vn )), (& __0__V56 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 696 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} }
if (Vcheckerror == 0 )
# 699 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__6f -> f_virtual__3fct ){ 
# 700 "/home/claude/cfront-3/src/dcl4.cpp"
case 0 :
# 701 "/home/claude/cfront-3/src/dcl4.cpp"
case 22222 :
# 702 "/home/claude/cfront-3/src/dcl4.cpp"
__5hit = 1 ;
}

# 705 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 707 "/home/claude/cfront-3/src/dcl4.cpp"
if (__5hit ){ 
# 709 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2vn -> __O3__4expr.n_initializer ){ 
# 710 "/home/claude/cfront-3/src/dcl4.cpp"
if (! get_vf__FP4nameP8classdef ( __2vn , __0this ) ){ 
# 711 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_abstract__8classdef = __2vn ;
# 711 "/home/claude/cfront-3/src/dcl4.cpp"

# 712 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
{ 
# 714 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V57 ;

# 714 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V58 ;

# 714 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V59 ;

# 714 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __3n -> where__4name , (const char *)"%n hides virtual%n ofT %t", (const
# 714 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea *)( ((& __0__V57 )-> __O1__2ea.p = ((const void *)__3n )), (& __0__V57 )) , (const struct ea *)(
# 714 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V58 )-> __O1__2ea.p = ((const void *)__2vn )), (& __0__V58 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V59 ,
# 714 "/home/claude/cfront-3/src/dcl4.cpp"
(const void *)__2vn -> __O1__4expr.tp ) , (const struct ea *)ea0 ) ;
} }

# 717 "/home/claude/cfront-3/src/dcl4.cpp"
(__1vp [__2i ])= __2vn ;
if ((__1ivec [__2i ]). offset__5velem && __1vtab -> is_vbase__4virt ){ 
# 719 "/home/claude/cfront-3/src/dcl4.cpp"
if ((Voffset - __1vo )!= (__1ivec [__2i ]). offset__5velem ){ 
# 722 "/home/claude/cfront-3/src/dcl4.cpp"
int __7noffset ;

# 722 "/home/claude/cfront-3/src/dcl4.cpp"
__7noffset = get_offset__8classdefFPCcUc ( __0this , __1vtab -> string__4virt , (unsigned char )1 ) ;
if (__7noffset && (__7noffset != Voffset ))
# 724 "/home/claude/cfront-3/src/dcl4.cpp"
__7noffset -= __1vo ;
if (__7noffset == 0 ){ 
# 726 "/home/claude/cfront-3/src/dcl4.cpp"
if (Vvbc_inher )
# 729 "/home/claude/cfront-3/src/dcl4.cpp"
__7noffset = (link_compat_hack ?(link_compat_hack - (__1ivec [__2i ]). offset__5velem ):(__1ivec [__2i ]). offset__5velem );
else __7noffset = (Voffset - __1vo );
}
(__1vp [__2i ])-> n_offset__4name = __7noffset ;
}
else (__1vp [__2i ])-> n_offset__4name = (Voffset - __1vo );
}
else (__1vp [__2i ])-> n_offset__4name = (__1ivec [__2i ]). offset__5velem ;
found :
# 738 "/home/claude/cfront-3/src/dcl4.cpp"
break ;

# 738 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 738 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
} }

# 740 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 740 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 740 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 743 "/home/claude/cfront-3/src/dcl4.cpp"
Voffset = __1vo ;
__1vc = __2i ;
}

# 749 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1leftmost ){ 
# 755 "/home/claude/cfront-3/src/dcl4.cpp"
int __2i ;
{ { Pname __2nn ;

# 757 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X60 ;

# 757 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X61 ;

# 757 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X62 ;

# 757 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X63 ;

# 756 "/home/claude/cfront-3/src/dcl4.cpp"
__2nn = ( (__0__X62 = __0this -> memtbl__8classdef ), ( (__2__X63 = (__2i = 1 )), ( (((__2__X63 <= 0 )|| (__0__X62 -> free_slot__5table <=
# 756 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X63 ))?(((struct name *)0 )):(__0__X62 -> entries__5table [__2__X63 ]))) ) ) ;

# 756 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2nn ;__2nn = (__2nn -> n_tbl_list__4name ?__2nn -> n_tbl_list__4name :( (__0__X60 = __0this -> memtbl__8classdef ), ( (__2__X61 = (++ __2i )), ( (((__2__X61 <= 0 )||
# 756 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X60 -> free_slot__5table <= __2__X61 ))?(((struct name *)0 )):(__0__X60 -> entries__5table [__2__X61 ]))) ) ) )) { 
# 757 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2nn -> base__4node == 123 )continue ;
# 757 "/home/claude/cfront-3/src/dcl4.cpp"

# 758 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pfct __3f ;

# 758 "/home/claude/cfront-3/src/dcl4.cpp"
__3f = (((struct fct *)(((struct fct *)__2nn -> __O1__4expr.tp ))));

# 760 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1vc >= __1vpsz ){ 
# 761 "/home/claude/cfront-3/src/dcl4.cpp"
int __4tvpsz ;
Pname *__4tvp ;

# 761 "/home/claude/cfront-3/src/dcl4.cpp"
__4tvpsz = (__1vpsz + 32);
__4tvp = (((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* __4tvpsz )) ));
{ { int __4j ;

# 763 "/home/claude/cfront-3/src/dcl4.cpp"
__4j = 0 ;

# 763 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4j < __1vc ;++ __4j ) 
# 764 "/home/claude/cfront-3/src/dcl4.cpp"
(__4tvp [__4j ])= (__1vp [__4j ]);
__dl__FPv ( (void *)__1vp ) ;
__1vp = __4tvp ;
__1vpsz = __4tvpsz ;

# 767 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 767 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 771 "/home/claude/cfront-3/src/dcl4.cpp"
if (__3f )
# 772 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__3f -> base__4node ){ 
# 773 "/home/claude/cfront-3/src/dcl4.cpp"
case 108 :
# 775 "/home/claude/cfront-3/src/dcl4.cpp"
if (__3f -> f_virtual__3fct == 22222 ){ 
# 778 "/home/claude/cfront-3/src/dcl4.cpp"
__3f -> f_virtual__3fct = (++ __1vc );
(__1vp [(__3f -> f_virtual__3fct - 1 )])= __2nn ;
(__1vp [(__3f -> f_virtual__3fct - 1 )])-> n_offset__4name = 0 ;
__3f -> f_vdef__3fct = 1 ;
__1changed = 2 ;
}
break ;
case 76 :
# 786 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 787 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Plist __5gl ;

# 787 "/home/claude/cfront-3/src/dcl4.cpp"
__5gl = (((struct gen *)(((struct gen *)__3f ))))-> fct_list__3gen ;

# 787 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__5gl ;__5gl = __5gl -> l__9name_list ) { 
# 788 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __6fn ;
Pfct __6f ;

# 788 "/home/claude/cfront-3/src/dcl4.cpp"
__6fn = __5gl -> f__9name_list ;
__6f = (((struct fct *)(((struct fct *)__6fn -> __O1__4expr.tp ))));

# 791 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1vc >= __1vpsz ){ 
# 792 "/home/claude/cfront-3/src/dcl4.cpp"
int __7tvpsz ;
Pname *__7tvp ;

# 792 "/home/claude/cfront-3/src/dcl4.cpp"
__7tvpsz = (__1vpsz + 32);
__7tvp = (((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* __7tvpsz )) ));
{ { int __7j ;

# 794 "/home/claude/cfront-3/src/dcl4.cpp"
__7j = 0 ;

# 794 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__7j < __1vc ;++ __7j ) { 
# 795 "/home/claude/cfront-3/src/dcl4.cpp"
(__7tvp [__7j ])= (__1vp [__7j ]);
}
__dl__FPv ( (void *)__1vp ) ;
__1vp = __7tvp ;
__1vpsz = __7tvpsz ;

# 799 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 799 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 802 "/home/claude/cfront-3/src/dcl4.cpp"
if (__6f -> f_virtual__3fct == 22222 ){ 
# 803 "/home/claude/cfront-3/src/dcl4.cpp"
__6f -> f_virtual__3fct = (++ __1vc );
(__1vp [(__6f -> f_virtual__3fct - 1 )])= __6fn ;
(__1vp [(__6f -> f_virtual__3fct - 1 )])-> n_offset__4name = 0 ;
__6f -> f_vdef__3fct = 1 ;
__1changed = 2 ;
}
}
break ;

# 810 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 810 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}

# 812 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 816 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> virt_count__8classdef = 0 ;
if (__1changed )
# 818 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> virt_count__8classdef = __1vc ;
else if (__0this -> has_vvtab__8classdef ){ 
# 820 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> virt_merge__8classdef = 1 ;
if (__1vc && __1vtab -> is_vbase__4virt )
# 822 "/home/claude/cfront-3/src/dcl4.cpp"
__1leftmost = 0 ;
}

# 823 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 823 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 827 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1changed || (! __1leftmost )){ 
# 829 "/home/claude/cfront-3/src/dcl4.cpp"
struct velem *__2v ;

# 829 "/home/claude/cfront-3/src/dcl4.cpp"
__2v = (((struct velem *)__nw__FUl ( (unsigned long )((sizeof (struct velem ))* (__1vc + 1 ))) ));

# 831 "/home/claude/cfront-3/src/dcl4.cpp"
{ { int __2i ;

# 831 "/home/claude/cfront-3/src/dcl4.cpp"
__2i = 0 ;

# 831 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2i < __1vc ;__2i ++ ) { 
# 832 "/home/claude/cfront-3/src/dcl4.cpp"
(__2v [__2i ]). n__5velem = (__1vp [__2i ]);
(__2v [__2i ]). offset__5velem = (__1vp [__2i ])-> n_offset__4name ;
}
(__2v [__1vc ]). n__5velem = 0 ;

# 837 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1leftmost )
# 838 "/home/claude/cfront-3/src/dcl4.cpp"
add_vtbl__8classdefFP5velemPCcUci ( __0this , __2v , (const char *)0 , (unsigned char )0 , 0 ) ;
else 
# 840 "/home/claude/cfront-3/src/dcl4.cpp"
add_vtbl__8classdefFP5velemPCcUci ( __0this , __2v , vtbl_str__FPCcT1 ( __1vtab -> string__4virt , __1str ) , (unsigned char )(__1virt_flag || __1vtab -> is_vbase__4virt ),
# 840 "/home/claude/cfront-3/src/dcl4.cpp"
__1vc + 1 ) ;
__dl__FPv ( (void *)__1vp ) ;
vcounter = 0 ;
return 1 ;

# 843 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 843 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 846 "/home/claude/cfront-3/src/dcl4.cpp"
__dl__FPv ( (void *)__1vp ) ;
vcounter = 0 ;
return 0 ;

# 848 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 848 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 851 "/home/claude/cfront-3/src/dcl4.cpp"
int all_virt__8classdefFP8classdefPCciUc (struct classdef *__0this , Pclass __1bcl , const char *__1s , int __1leftmost , bit __1virt_flag );

# 851 "/home/claude/cfront-3/src/dcl4.cpp"
int all_virt__8classdefFP8classdefPCciUc (register struct classdef *__0this , Pclass __1bcl , const char *__1s , int __1leftmost , bit __1virt_flag )
# 852 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 854 "/home/claude/cfront-3/src/dcl4.cpp"
int __1i ;

# 854 "/home/claude/cfront-3/src/dcl4.cpp"
__1i = 0 ;
if (__1bcl -> virt_count__8classdef ){ 
# 856 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pvirt __2blist ;

# 856 "/home/claude/cfront-3/src/dcl4.cpp"
__2blist = __1bcl -> virt_list__8classdef ;

# 856 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2blist ;__2blist = __2blist -> next__4virt ) { 
# 857 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__0this -> virt_merge__8classdef && (__1virt_flag == 0 ))&& (__2blist -> is_vbase__4virt == 0 ))
# 864 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 866 "/home/claude/cfront-3/src/dcl4.cpp"
__1i += do_virtuals__8classdefFP4virtPCciUc ( __0this , __2blist , __1s , __1leftmost , __1virt_flag ) ;
if (((__1i == 0 )&& __1leftmost )&& (__0this -> virt_merge__8classdef == 0 ))
# 868 "/home/claude/cfront-3/src/dcl4.cpp"
return 0 ;

# 870 "/home/claude/cfront-3/src/dcl4.cpp"
__1leftmost = 0 ;
}

# 871 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 871 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 876 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1i )
# 877 "/home/claude/cfront-3/src/dcl4.cpp"
return __1i ;

# 879 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pbcl __1b ;

# 879 "/home/claude/cfront-3/src/dcl4.cpp"
__1b = __1bcl -> baselist__8classdef ;

# 879 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 880 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1b -> promoted__6basecl )
# 881 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 883 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1leftmost && (__1b -> base__4node == 77 )){ 
# 884 "/home/claude/cfront-3/src/dcl4.cpp"
__1i += do_virtuals__8classdefFP4virtPCciUc ( __0this , (struct virt *)0 , (const char *)0 , 1 ,
# 884 "/home/claude/cfront-3/src/dcl4.cpp"
(unsigned char )0 ) ;
if ((__1i == 0 )&& (__0this -> virt_merge__8classdef == 0 )){ 
# 887 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__1bcl == __0this )&& __1b -> bclass__6basecl -> c_abstract__8classdef )
# 888 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_abstract__8classdef = __1b ->
# 888 "/home/claude/cfront-3/src/dcl4.cpp"
bclass__6basecl -> c_abstract__8classdef ;
return 0 ;
}
__1leftmost = 0 ;
}
{ int __2vo ;

# 893 "/home/claude/cfront-3/src/dcl4.cpp"
__2vo = Voffset ;
if (__1b -> base__4node == 77 )
# 895 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 896 "/home/claude/cfront-3/src/dcl4.cpp"
Voffset = baseoffset__FP8classdefT1 ( __1b -> bclass__6basecl , __0this ) ;
}
else 
# 899 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 900 "/home/claude/cfront-3/src/dcl4.cpp"
Voffset += __1b -> obj_offset__6basecl ;
}

# 904 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1b -> base__4node == 77 )
# 905 "/home/claude/cfront-3/src/dcl4.cpp"
__1i += all_virt__8classdefFP8classdefPCciUc ( __0this , __1b -> bclass__6basecl , __1b -> bclass__6basecl -> string__8classdef , __1leftmost , (unsigned char
# 905 "/home/claude/cfront-3/src/dcl4.cpp"
)1 ) ;
else __1i += all_virt__8classdefFP8classdefPCciUc ( __0this , __1b -> bclass__6basecl , vtbl_str__FPCcT1 ( __1b -> bclass__6basecl -> string__8classdef , __1s ) , __1leftmost , __1virt_flag )
# 906 "/home/claude/cfront-3/src/dcl4.cpp"
;

# 908 "/home/claude/cfront-3/src/dcl4.cpp"
if (((__1i == 0 )&& __1leftmost )&& (__0this -> virt_merge__8classdef == 0 )){ 
# 910 "/home/claude/cfront-3/src/dcl4.cpp"
if (((__1bcl == __0this )&& (! __0this -> c_abstract__8classdef ))&& __1b ->
# 910 "/home/claude/cfront-3/src/dcl4.cpp"
next__6basecl ){ 
# 911 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pbcl __4bb ;

# 911 "/home/claude/cfront-3/src/dcl4.cpp"
__4bb = __1b ;

# 911 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4bb ;__4bb = __4bb -> next__6basecl ) { 
# 912 "/home/claude/cfront-3/src/dcl4.cpp"
if (__4bb -> promoted__6basecl )continue ;
if (__4bb -> bclass__6basecl -> c_abstract__8classdef )
# 914 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_abstract__8classdef = __4bb -> bclass__6basecl -> c_abstract__8classdef ;
}

# 915 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 915 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
return 0 ;
}

# 920 "/home/claude/cfront-3/src/dcl4.cpp"
Voffset = __2vo ;
__1leftmost = 0 ;

# 921 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 925 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1i )
# 926 "/home/claude/cfront-3/src/dcl4.cpp"
return __1i ;

# 930 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1leftmost )
# 931 "/home/claude/cfront-3/src/dcl4.cpp"
return do_virtuals__8classdefFP4virtPCciUc ( __0this , (struct virt *)0 , (const char *)0 , 1 , (unsigned char )0 ) ;
# 931 "/home/claude/cfront-3/src/dcl4.cpp"
else 
# 933 "/home/claude/cfront-3/src/dcl4.cpp"
return 0 ;

# 933 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 933 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 37 "/home/claude/cfront-3/src/cfront.h"
extern char *make_name__FUc (TOK );

# 79 "/home/claude/incl-linux32/stdio.h"
extern int fprintf (void *, const char *,...);

# 579 "/home/claude/cfront-3/src/cfront.h"
struct basetype *__ct__8basetypeFUcP4name (struct basetype *__0this , TOK , Pname );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 804 "/home/claude/cfront-3/src/cfront.h"
Pexpr contents__4exprFv (struct expr *__0this );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 936 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr copy_obj__FP4exprT1i (Pexpr __1l , Pexpr __1r , int __1sz )
# 942 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 943 "/home/claude/cfront-3/src/dcl4.cpp"
if (! __1sz )__1sz = 1 ;

# 945 "/home/claude/cfront-3/src/dcl4.cpp"
{ char *__1s ;

# 945 "/home/claude/cfront-3/src/dcl4.cpp"
__1s = make_name__FUc ( (unsigned char )'S' ) ;
fprintf ( out_file , (const char *)"struct %s { char v[%d]; };\n", __1s , __1sz ) ;
{ Pname __1n ;
Ptype __1t ;

# 949 "/home/claude/cfront-3/src/dcl4.cpp"
struct texpr *__0__X64 ;

# 949 "/home/claude/cfront-3/src/dcl4.cpp"
struct texpr *__0__X65 ;

# 947 "/home/claude/cfront-3/src/dcl4.cpp"
__1n = __ct__4nameFPCc ( (struct name *)0 , (const char *)__1s ) ;
__1t = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )119 , __1n ) ;
__1t = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __1t ) ;

# 951 "/home/claude/cfront-3/src/dcl4.cpp"
__1l = (struct expr *)( (__0__X64 = 0 ), ( ((__0__X64 || (__0__X64 = (struct texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr)))
# 951 "/home/claude/cfront-3/src/dcl4.cpp"
))?( (__0__X64 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X64 ), ((unsigned char )191 ), __1l , (struct expr *)0 ) ), (__0__X64 ->
# 951 "/home/claude/cfront-3/src/dcl4.cpp"
__O4__4expr.tp2 = __1t )) :0 ), __0__X64 ) ) ;
__1l = contents__4exprFv ( __1l ) ;

# 954 "/home/claude/cfront-3/src/dcl4.cpp"
__1r = (struct expr *)( (__0__X65 = 0 ), ( ((__0__X65 || (__0__X65 = (struct texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr)))
# 954 "/home/claude/cfront-3/src/dcl4.cpp"
))?( (__0__X65 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X65 ), ((unsigned char )191 ), __1r , (struct expr *)0 ) ), (__0__X65 ->
# 954 "/home/claude/cfront-3/src/dcl4.cpp"
__O4__4expr.tp2 = __1t )) :0 ), __0__X65 ) ) ;
__1r = contents__4exprFv ( __1r ) ;

# 957 "/home/claude/cfront-3/src/dcl4.cpp"
return __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __1l , __1r ) ;

# 957 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 957 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 468 "/home/claude/cfront-3/src/cfront.h"

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 960 "/home/claude/cfront-3/src/dcl4.cpp"
Ptype find_arg_type__FP8classdef (Pclass __1cl )
# 962 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 963 "/home/claude/cfront-3/src/dcl4.cpp"
int __1i ;
int __1mod ;

# 964 "/home/claude/cfront-3/src/dcl4.cpp"
__1mod = 0 ;
{ { Pbcl __1b ;

# 965 "/home/claude/cfront-3/src/dcl4.cpp"
__1b = __1cl -> baselist__8classdef ;

# 965 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 966 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __2bcl ;

# 966 "/home/claude/cfront-3/src/dcl4.cpp"
__2bcl = __1b -> bclass__6basecl ;
switch (__1b -> base__4node ){ 
# 968 "/home/claude/cfront-3/src/dcl4.cpp"
case 77 :
# 969 "/home/claude/cfront-3/src/dcl4.cpp"
case 85 :
# 970 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 971 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __4itor ;

# 971 "/home/claude/cfront-3/src/dcl4.cpp"
__4itor = ( __2bcl -> c_itor__8classdef ) ;
if (__4itor && (__4itor -> __O1__4expr.tp -> base__4node == 108 )){ 
# 973 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5a ;
Pptr __5p ;

# 973 "/home/claude/cfront-3/src/dcl4.cpp"
__5a = (((struct fct *)(((struct fct *)__4itor -> __O1__4expr.tp ))))-> argtype__3fct ;
__5p = is_ref__4typeFv ( __5a -> __O1__4expr.tp ) ;
if (__5p && (tconst__4typeFv ( __5p -> typ__5pvtyp ) == 0 )){ 
# 976 "/home/claude/cfront-3/src/dcl4.cpp"
__1mod = 1 ;
goto ll1 ;
}
}
}
}
}
ll1 :
# 984 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1mod == 0 ){ 
# 985 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pname __2m ;

# 986 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X66 ;

# 986 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X67 ;

# 986 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X69 ;

# 986 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X70 ;

# 985 "/home/claude/cfront-3/src/dcl4.cpp"
__2m = ( (__0__X69 = __1cl -> memtbl__8classdef ), ( (__2__X70 = (__1i = 1 )), ( (((__2__X70 <= 0 )|| (__0__X69 -> free_slot__5table <=
# 985 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X70 ))?(((struct name *)0 )):(__0__X69 -> entries__5table [__2__X70 ]))) ) ) ;

# 985 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2m ;__2m = (__2m -> n_tbl_list__4name ?__2m -> n_tbl_list__4name :( (__0__X66 = __1cl -> memtbl__8classdef ), ( (__2__X67 = (++ __1i )), ( (((__2__X67 <= 0 )||
# 985 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X66 -> free_slot__5table <= __2__X67 ))?(((struct name *)0 )):(__0__X66 -> entries__5table [__2__X67 ]))) ) ) )) { 
# 986 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2m -> base__4node == 123 )continue ;
# 986 "/home/claude/cfront-3/src/dcl4.cpp"

# 987 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2m -> n_evaluated__4name || (__2m -> n_stclass__4name == 31 ))
# 988 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;
{ Pname __3cln ;

# 989 "/home/claude/cfront-3/src/dcl4.cpp"
__3cln = is_cl_obj__4typeFv ( ((__2m -> base__4node == 25 )?__2m -> __O2__4name.n_qualifier :__2m )-> __O1__4expr.tp ) ;
if (__3cln ){ 
# 991 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __4itor ;

# 992 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__0__X68 ;

# 991 "/home/claude/cfront-3/src/dcl4.cpp"
__4itor = ( (__0__X68 = (((struct classdef *)(((struct classdef *)__3cln -> __O1__4expr.tp ))))), ( __0__X68 -> c_itor__8classdef ) ) ;
if (__4itor && (__4itor -> __O1__4expr.tp -> base__4node == 108 )){ 
# 993 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5a ;
Pptr __5p ;

# 993 "/home/claude/cfront-3/src/dcl4.cpp"
__5a = (((struct fct *)(((struct fct *)__4itor -> __O1__4expr.tp ))))-> argtype__3fct ;
__5p = is_ref__4typeFv ( __5a -> __O1__4expr.tp ) ;
if (__5p && (tconst__4typeFv ( __5p -> typ__5pvtyp ) == 0 )){ 
# 996 "/home/claude/cfront-3/src/dcl4.cpp"
__1mod = 1 ;
goto ll2 ;
}
}
}

# 1000 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1001 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1001 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
ll2 :
# 1005 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pbase __1bp ;

# 1005 "/home/claude/cfront-3/src/dcl4.cpp"
__1bp = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )21 , (struct name *)0 ) ;
((*__1bp ))= (*(((struct basetype *)(((struct basetype *)(((struct ptr *)(((struct ptr *)__1cl -> this_type__8classdef ))))-> typ__5pvtyp )))));
if (__1mod == 0 )__1bp -> b_const__4type = 1 ;
return (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )158 , (struct type *)__1bp ) ;

# 1008 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1008 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1008 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 803 "/home/claude/cfront-3/src/cfront.h"
Pexpr address__4exprFv (struct expr *__0this );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 346 "/home/claude/cfront-3/src/cfront.h"
int tsizeof__4typeFi (struct type *__0this , int );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

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

# 1011 "/home/claude/cfront-3/src/dcl4.cpp"
Pname make_itor__8classdefFi (register struct classdef *__0this , int __1def )
# 1015 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1017 "/home/claude/cfront-3/src/dcl4.cpp"
Pstmt __1s ;
Pname __1e ;
int __1i ;
Pname __1arg ;

# 1020 "/home/claude/cfront-3/src/dcl4.cpp"
__1arg = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'A' ) ) ;
__1arg -> __O1__4expr.tp = find_arg_type__FP8classdef ( __0this ) ;

# 1023 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_xref__8classdef |= 2;

# 1025 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1def ){ 
# 1026 "/home/claude/cfront-3/src/dcl4.cpp"
int __2slow ;
int __2first ;
Pexpr __2es ;

# 1029 "/home/claude/cfront-3/src/dcl4.cpp"
struct estmt *__0__X75 ;

# 1029 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X76 ;

# 1029 "/home/claude/cfront-3/src/dcl4.cpp"
unsigned long __2__X77 ;

# 1029 "/home/claude/cfront-3/src/dcl4.cpp"
const void *__2__X78 ;

# 1026 "/home/claude/cfront-3/src/dcl4.cpp"
__2slow = 0 ;
__2first = 1 ;
__2es = 0 ;
__1s = (struct stmt *)( (__0__X75 = 0 ), ( (__2__X76 = no_where ), ( ((__0__X75 || (__0__X75 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 1029 "/home/claude/cfront-3/src/dcl4.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X75 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X75 ), ((unsigned char )72 ), __2__X76 , ((struct
# 1029 "/home/claude/cfront-3/src/dcl4.cpp"
stmt *)0 )) ), (__0__X75 -> __O2__4stmt.e = ((struct expr *)0 ))) :0 ), __0__X75 ) ) ) ;
__1e = 0 ;

# 1032 "/home/claude/cfront-3/src/dcl4.cpp"
if (warning_opt && (128 < __0this -> obj_size__8classdef ))
# 1033 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1033 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V71 ;

# 1033 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V72 ;

# 1033 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"copying a %d byte object (ofC %s)", (const struct ea *)( (__2__X77 =
# 1033 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> obj_size__8classdef ), ( (( ((& __0__V71 )-> __O1__2ea.i = __2__X77 ), 0 ) ), (& __0__V71 )) ) ,
# 1033 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)( (__2__X78 = (const void *)__0this -> string__8classdef ), ( ((& __0__V72 )-> __O1__2ea.p = __2__X78 ), (&
# 1033 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V72 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1035 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> baselist__8classdef )
# 1036 "/home/claude/cfront-3/src/dcl4.cpp"
__2slow = 1 ;

# 1039 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2slow ){ 
# 1040 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pbcl __3b ;

# 1040 "/home/claude/cfront-3/src/dcl4.cpp"
__3b = __0this -> baselist__8classdef ;

# 1040 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__3b ;__3b = __3b -> next__6basecl ) { 
# 1041 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __4bcl ;
Ptype __4pt ;

# 1041 "/home/claude/cfront-3/src/dcl4.cpp"
__4bcl = __3b -> bclass__6basecl ;
__4pt = __4bcl -> this_type__8classdef ;
if ((__3b -> base__4node == 77 )|| (__3b -> base__4node == 85 )){ 
# 1044 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __5b2 ;

# 1045 "/home/claude/cfront-3/src/dcl4.cpp"
struct texpr *__0__X79 ;

# 1044 "/home/claude/cfront-3/src/dcl4.cpp"
__5b2 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ;
__5b2 = address__4exprFv ( __5b2 ) ;
__5b2 = (struct expr *)( (__0__X79 = 0 ), ( ((__0__X79 || (__0__X79 = (struct texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr)))
# 1046 "/home/claude/cfront-3/src/dcl4.cpp"
))?( (__0__X79 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X79 ), ((unsigned char )191 ), __5b2 , (struct expr *)0 ) ), (__0__X79 ->
# 1046 "/home/claude/cfront-3/src/dcl4.cpp"
__O4__4expr.tp2 = __4pt )) :0 ), __0__X79 ) ) ;
__5b2 -> __O3__4expr.i2 = 1 ;
__5b2 = contents__4exprFv ( __5b2 ) ;

# 1050 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pname __5ee ;

# 1050 "/home/claude/cfront-3/src/dcl4.cpp"
__5ee = __ct__4nameFPCc ( (struct name *)0 , __4bcl -> string__8classdef ) ;
__5ee -> base__4node = 123 ;
__5ee -> __O3__4expr.n_initializer = __5b2 ;
if (__1e )
# 1054 "/home/claude/cfront-3/src/dcl4.cpp"
__5ee -> __O1__4name.n_list = __1e ;
__1e = __5ee ;

# 1055 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}

# 1057 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1057 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1060 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pname __2mm ;

# 1061 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X80 ;

# 1061 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X81 ;

# 1061 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X93 ;

# 1061 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X94 ;

# 1060 "/home/claude/cfront-3/src/dcl4.cpp"
__2mm = ( (__0__X93 = __0this -> memtbl__8classdef ), ( (__2__X94 = (__1i = 1 )), ( (((__2__X94 <= 0 )|| (__0__X93 -> free_slot__5table <=
# 1060 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X94 ))?(((struct name *)0 )):(__0__X93 -> entries__5table [__2__X94 ]))) ) ) ;

# 1060 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2mm ;__2mm = (__2mm -> n_tbl_list__4name ?__2mm -> n_tbl_list__4name :( (__0__X80 = __0this -> memtbl__8classdef ), ( (__2__X81 = (++ __1i )), ( (((__2__X81 <= 0 )||
# 1060 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X80 -> free_slot__5table <= __2__X81 ))?(((struct name *)0 )):(__0__X80 -> entries__5table [__2__X81 ]))) ) ) )) { 
# 1061 "/home/claude/cfront-3/src/dcl4.cpp"
Ptype __3t ;

# 1061 "/home/claude/cfront-3/src/dcl4.cpp"
__3t = __2mm -> __O1__4expr.tp ;
if (__3t && ((__3t = skiptypedefs__4typeFv ( __3t ) )-> base__4node == 119 )){ 
# 1063 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __4mcl ;

# 1063 "/home/claude/cfront-3/src/dcl4.cpp"
__4mcl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype -> __O1__4expr.tp ))));
if (__4mcl -> c_xref__8classdef & 10)__2slow = 1 ;
}
}

# 1069 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pname __2m ;

# 1070 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X82 ;

# 1070 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X83 ;

# 1070 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X91 ;

# 1070 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X92 ;

# 1069 "/home/claude/cfront-3/src/dcl4.cpp"
__2m = ( (__0__X91 = __0this -> memtbl__8classdef ), ( (__2__X92 = (__1i = 1 )), ( (((__2__X92 <= 0 )|| (__0__X91 -> free_slot__5table <=
# 1069 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X92 ))?(((struct name *)0 )):(__0__X91 -> entries__5table [__2__X92 ]))) ) ) ;

# 1069 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2m ;__2m = (__2m -> n_tbl_list__4name ?__2m -> n_tbl_list__4name :( (__0__X82 = __0this -> memtbl__8classdef ), ( (__2__X83 = (++ __1i )), ( (((__2__X83 <= 0 )||
# 1069 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X82 -> free_slot__5table <= __2__X83 ))?(((struct name *)0 )):(__0__X82 -> entries__5table [__2__X83 ]))) ) ) )) { 
# 1070 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2m -> base__4node == 123 )continue ;
# 1070 "/home/claude/cfront-3/src/dcl4.cpp"

# 1071 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2m -> n_evaluated__4name || (__2m -> n_stclass__4name == 31 ))
# 1072 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 1074 "/home/claude/cfront-3/src/dcl4.cpp"
if (strcmp ( __2m -> __O2__4expr.string , (const char *)"__vptr") == 0 ){ 
# 1075 "/home/claude/cfront-3/src/dcl4.cpp"
if
# 1075 "/home/claude/cfront-3/src/dcl4.cpp"
(((__2slow == 0 )&& (__2first == 0 ))&& __2m -> n_offset__4name ){ 
# 1076 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __5th ;
Pexpr __5a ;

# 1076 "/home/claude/cfront-3/src/dcl4.cpp"
__5th = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )34 , (struct expr *)0 , (struct expr *)0 ) ;
__5a = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ;
__5a = address__4exprFv ( __5a ) ;
{ Pexpr __5ee ;

# 1079 "/home/claude/cfront-3/src/dcl4.cpp"
__5ee = copy_obj__FP4exprT1i ( __5th , __5a , __2m -> n_offset__4name ) ;
__2es = (__2es ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __2es , __5ee ) :__5ee );

# 1080 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
__2slow = 1 ;
__2first = 0 ;
continue ;
}
{ Ptype __3mt ;

# 1086 "/home/claude/cfront-3/src/dcl4.cpp"
__3mt = __2m -> __O1__4expr.tp ;
if (__3mt )
# 1088 "/home/claude/cfront-3/src/dcl4.cpp"
tx :switch (__3mt -> base__4node ){ 
# 1089 "/home/claude/cfront-3/src/dcl4.cpp"
case 97 :
# 1090 "/home/claude/cfront-3/src/dcl4.cpp"
__3mt = (((struct basetype *)(((struct basetype *)__3mt ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto tx ;
case 110 :
# 1093 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1094 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5cn ;

# 1094 "/home/claude/cfront-3/src/dcl4.cpp"
__5cn = is_cl_obj__4typeFv ( (((struct vec *)(((struct vec *)__3mt ))))-> typ__5pvtyp ) ;
if (__5cn && ((((struct classdef *)(((struct classdef *)__5cn -> __O1__4expr.tp ))))-> c_xref__8classdef & 10)){ 
# 1096 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1096 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V73 ;

# 1096 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V74 ;

# 1096 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"copy of %n[], no memberwise copy for%n", (const struct ea *)( ((&
# 1096 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V73 )-> __O1__2ea.p = ((const void *)__5cn )), (& __0__V73 )) , (const struct ea *)( ((& __0__V74 )-> __O1__2ea.p =
# 1096 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__5cn )), (& __0__V74 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__2slow = 1 ;
} 
# 1100 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1102 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2slow && tsizeof__4typeFi ( __3mt , 0 ) ){ 
# 1108 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __6l ;
Pexpr __6r ;

# 1110 "/home/claude/cfront-3/src/dcl4.cpp"
struct ref *__0__X84 ;

# 1110 "/home/claude/cfront-3/src/dcl4.cpp"
struct expr *__2__X85 ;

# 1110 "/home/claude/cfront-3/src/dcl4.cpp"
struct expr *__2__X86 ;

# 1108 "/home/claude/cfront-3/src/dcl4.cpp"
__6l = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __2m -> __O2__4expr.string ) ;
__6r = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __2m -> __O2__4expr.string ) ;
__6r = (struct expr *)( (__0__X84 = 0 ), ( (__2__X85 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ),
# 1110 "/home/claude/cfront-3/src/dcl4.cpp"
( (__2__X86 = __6r ), ( ((__0__X84 || (__0__X84 = (struct ref *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ref))) ))?( (__0__X84 =
# 1110 "/home/claude/cfront-3/src/dcl4.cpp"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X84 ), ((unsigned char )45 ), __2__X85 , (struct expr *)0 ) ), (__0__X84 -> __O4__4expr.mem = __2__X86 ))
# 1110 "/home/claude/cfront-3/src/dcl4.cpp"
:0 ), __0__X84 ) ) ) ) ;
{ Pexpr __6ee ;

# 1111 "/home/claude/cfront-3/src/dcl4.cpp"
__6ee = copy_obj__FP4exprT1i ( __6l , __6r , tsizeof__4typeFi ( __3mt , 0 ) ) ;
__2es = (__2es ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __2es , __6ee ) :__6ee );
break ;

# 1113 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}
case 108 :
# 1117 "/home/claude/cfront-3/src/dcl4.cpp"
case 76 :
# 1118 "/home/claude/cfront-3/src/dcl4.cpp"
case 6 :
# 1119 "/home/claude/cfront-3/src/dcl4.cpp"
case 13 :
# 1120 "/home/claude/cfront-3/src/dcl4.cpp"
break ;
case 119 :
# 1122 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1123 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __5mcl ;

# 1123 "/home/claude/cfront-3/src/dcl4.cpp"
__5mcl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__3mt ))))-> b_name__8basetype -> __O1__4expr.tp ))));
if ((__2slow == 0 )&& (__5mcl -> c_xref__8classdef & 10))
# 1128 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1129 "/home/claude/cfront-3/src/dcl4.cpp"
__2slow = 1 ;
if ((__2first == 0 )&& __2m -> n_offset__4name ){ 
# 1132 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __7th ;
Pexpr __7a ;

# 1132 "/home/claude/cfront-3/src/dcl4.cpp"
__7th = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )34 , (struct expr *)0 , (struct expr *)0 ) ;
__7a = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ;
__7a = address__4exprFv ( __7a ) ;
{ Pexpr __7ee ;

# 1135 "/home/claude/cfront-3/src/dcl4.cpp"
__7ee = copy_obj__FP4exprT1i ( __7th , __7a , __2m -> n_offset__4name ) ;
__2es = (__2es ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __2es , __7ee ) :__7ee );

# 1136 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}

# 1140 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1142 "/home/claude/cfront-3/src/dcl4.cpp"
default :
# 1143 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2slow ){ 
# 1145 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5ee ;

# 1146 "/home/claude/cfront-3/src/dcl4.cpp"
struct ref *__0__X87 ;

# 1146 "/home/claude/cfront-3/src/dcl4.cpp"
struct expr *__2__X88 ;

# 1146 "/home/claude/cfront-3/src/dcl4.cpp"
struct expr *__2__X89 ;

# 1145 "/home/claude/cfront-3/src/dcl4.cpp"
__5ee = __ct__4nameFPCc ( (struct name *)0 , __2m -> __O2__4expr.string ) ;
__5ee -> __O3__4expr.n_initializer = (struct expr *)( (__0__X87 = 0 ), ( (__2__X88 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string )
# 1146 "/home/claude/cfront-3/src/dcl4.cpp"
), ( (__2__X89 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __2m -> __O2__4expr.string ) ), ( ((__0__X87 || (__0__X87 = (struct
# 1146 "/home/claude/cfront-3/src/dcl4.cpp"
ref *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ref))) ))?( (__0__X87 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X87 ), ((unsigned char )45 ),
# 1146 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X88 , (struct expr *)0 ) ), (__0__X87 -> __O4__4expr.mem = __2__X89 )) :0 ), __0__X87 ) ) ) ) ;
if (__1e )
# 1148 "/home/claude/cfront-3/src/dcl4.cpp"
__5ee -> __O1__4name.n_list = __1e ;
__1e = __5ee ;
}
}
__2first = 0 ;

# 1152 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1155 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2slow == 0 ){ 
# 1161 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __3th ;
Pexpr __3a ;

# 1161 "/home/claude/cfront-3/src/dcl4.cpp"
__3th = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )34 , (struct expr *)0 , (struct expr *)0 ) ;
__3a = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ;
__3a = address__4exprFv ( __3a ) ;
{ Pexpr __3ee ;

# 1164 "/home/claude/cfront-3/src/dcl4.cpp"
__3ee = copy_obj__FP4exprT1i ( __3th , __3a , __0this -> obj_size__8classdef ) ;
__2es = (__2es ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __2es , __3ee ) :__3ee );

# 1165 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1168 "/home/claude/cfront-3/src/dcl4.cpp"
__1s -> __O2__4stmt.e = __2es ;
{ Pname __2cn ;

# 1170 "/home/claude/cfront-3/src/dcl4.cpp"
struct dcl_context *__0__X90 ;

# 1169 "/home/claude/cfront-3/src/dcl4.cpp"
__2cn = find_cn__6ktableFPCc ( __0this -> k_tbl__8classdef , __0this -> string__8classdef ) ;
if (__2cn )
# 1171 "/home/claude/cfront-3/src/dcl4.cpp"
__2cn = (((struct basetype *)(((struct basetype *)__2cn -> __O1__4expr.tp ))))-> b_name__8basetype ;
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 1172 "/home/claude/cfront-3/src/dcl4.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;
cc -> not4__11dcl_context = __2cn ;
cc -> cot__11dcl_context = __0this ;

# 1174 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1174 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1174 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1174 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1174 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
{ Pname __1fn ;
Pfct __1f ;

# 1176 "/home/claude/cfront-3/src/dcl4.cpp"
__1fn = __ct__4nameFPCc ( (struct name *)0 , __0this -> string__8classdef ) ;
__1f = __ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)defa_type , __1arg , (unsigned char )1 ) ;
__1fn -> __O1__4expr.tp = (struct type *)__1f ;
__1fn -> n_oper__4name = 123 ;

# 1181 "/home/claude/cfront-3/src/dcl4.cpp"
(((struct fct *)(((struct fct *)__1f ))))-> f_inline__3fct = (__1def ?1 :77 );
(((struct fct *)(((struct fct *)__1f ))))-> f_is_inline__3fct = 1 ;
if (__1def ){ 
# 1183 "/home/claude/cfront-3/src/dcl4.cpp"
register struct block *__0__X95 ;

# 1183 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X96 ;

# 1183 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X97 ;

# 1184 "/home/claude/cfront-3/src/dcl4.cpp"
__1f -> body__3fct = ( (__0__X95 = 0 ), ( (__2__X96 = curloc ), ( (__2__X97 = noloc ), ( ((__0__X95 || (__0__X95 =
# 1184 "/home/claude/cfront-3/src/dcl4.cpp"
(struct block *)__nw__4stmtSFUl ( (unsigned long )(sizeof (struct block))) ))?(((void )( (__0__X95 = (struct block *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X95 ), (unsigned
# 1184 "/home/claude/cfront-3/src/dcl4.cpp"
char )116 , __2__X96 , __1s ) ), ( (__0__X95 -> __O1__4stmt.d = ((struct name *)0 )), (__0__X95 -> __O3__4stmt.where2 = __2__X97 )) )
# 1184 "/home/claude/cfront-3/src/dcl4.cpp"
)):(((void )0 ))), __0__X95 ) ) ) ) ;
__1f -> f_init__3fct = __1e ;
}

# 1188 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pname __1nn ;

# 1188 "/home/claude/cfront-3/src/dcl4.cpp"
__1nn = dcl__4nameFP5tableUc ( __1fn , __0this -> memtbl__8classdef , (unsigned char )25 ) ;
( (__1fn ?(((void )(__1fn ?(((void )( ( ((((struct expr *)__1fn ))?(((void )((((struct expr *)__1fn ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 1189 "/home/claude/cfront-3/src/dcl4.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1fn , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 1191 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1def ){ 
# 1191 "/home/claude/cfront-3/src/dcl4.cpp"
struct dcl_context *__0__X98 ;

# 1192 "/home/claude/cfront-3/src/dcl4.cpp"
( ( (cc -- ), (((void )0 ))) ) ;
simpl__4nameFv ( __1nn ) ;
if (debug_opt )
# 1195 "/home/claude/cfront-3/src/dcl4.cpp"
dcl_print__4nameFUc ( __1nn , (unsigned char )0 ) ;
}
return __1nn ;

# 1197 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1197 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 1200 "/home/claude/cfront-3/src/dcl4.cpp"
Ptype is_op_ass__FP3fctP8classdef (Pfct __1f , Pclass __1tcl )
# 1202 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1203 "/home/claude/cfront-3/src/dcl4.cpp"
Ptype __1t ;
Pname __1an ;

# 1205 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X99 ;

# 1205 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X100 ;

# 1203 "/home/claude/cfront-3/src/dcl4.cpp"
__1t = __1f -> argtype__3fct -> __O1__4expr.tp ;
__1an = is_cl_obj__4typeFv ( __1t ) ;
if ((__1an == 0 )&& (__1t = (struct type *)is_ref__4typeFv ( __1t ) )){ 
# 1206 "/home/claude/cfront-3/src/dcl4.cpp"
__1t = (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp ;

# 1208 "/home/claude/cfront-3/src/dcl4.cpp"
{ Ptype __2nt ;

# 1208 "/home/claude/cfront-3/src/dcl4.cpp"
__2nt = __1t ;
while (__2nt -> base__4node == 97 )
# 1210 "/home/claude/cfront-3/src/dcl4.cpp"
__2nt = (((struct basetype *)(((struct basetype *)__2nt ))))-> b_name__8basetype -> __O1__4expr.tp ;

# 1212 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2nt -> base__4node == 119 )
# 1213 "/home/claude/cfront-3/src/dcl4.cpp"
__1an = (((struct basetype *)(((struct basetype *)__2nt ))))-> b_name__8basetype ;

# 1213 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
if (__1an && ( (__1__X99 = (((struct classdef *)(((struct classdef *)__1an -> __O1__4expr.tp ))))), ( (__1__X100 = __1tcl ), ( ((__1__X99 == __1__X100 )?1 :((__1__X99 &&
# 1215 "/home/claude/cfront-3/src/dcl4.cpp"
__1__X100 )?(((int )same_class__8classdefFP8classdefi ( __1__X99 , __1__X100 , 0 ) )):0 ))) ) ) )return __1t ;
return (struct type *)0 ;
}

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 848 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 465 "/home/claude/cfront-3/src/cfront.h"
Pname has_oper__8classdefFUc (struct classdef *__0this , TOK );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 120 "/home/claude/cfront-3/src/cfront.h"
extern const char *oper_name__FUc (TOK );

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 639 "/home/claude/cfront-3/src/cfront.h"
void dcl__3fctFP4name (struct fct *__0this , Pname );

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 1219 "/home/claude/cfront-3/src/dcl4.cpp"
int make_assignment__FP4name (Pname __1cn )
# 1227 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1228 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __1cl ;
Pstmt __1s ;
Pexpr __1e ;
Pname __1arg ;

# 1232 "/home/claude/cfront-3/src/dcl4.cpp"
unsigned long __2__X110 ;

# 1232 "/home/claude/cfront-3/src/dcl4.cpp"
const void *__2__X111 ;

# 1232 "/home/claude/cfront-3/src/dcl4.cpp"
struct estmt *__0__X136 ;

# 1232 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X137 ;

# 1228 "/home/claude/cfront-3/src/dcl4.cpp"
__1cl = (((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))));
__1s = (struct stmt *)( (__0__X136 = 0 ), ( (__2__X137 = no_where ), ( ((__0__X136 || (__0__X136 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 1229 "/home/claude/cfront-3/src/dcl4.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X136 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X136 ), ((unsigned char )72 ), __2__X137 , ((struct
# 1229 "/home/claude/cfront-3/src/dcl4.cpp"
stmt *)0 )) ), (__0__X136 -> __O2__4stmt.e = ((struct expr *)0 ))) :0 ), __0__X136 ) ) ) ;
__1e = 0 ;
__1arg = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'A' ) ) ;
__1arg -> __O1__4expr.tp = find_arg_type__FP8classdef ( __1cl ) ;

# 1235 "/home/claude/cfront-3/src/dcl4.cpp"
if (warning_opt && (128 < __1cl -> obj_size__8classdef ))
# 1236 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1236 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V101 ;

# 1236 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V102 ;

# 1236 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"copying a %d byte object (ofC %s)", (const struct ea *)( (__2__X110 =
# 1236 "/home/claude/cfront-3/src/dcl4.cpp"
__1cl -> obj_size__8classdef ), ( (( ((& __0__V101 )-> __O1__2ea.i = __2__X110 ), 0 ) ), (& __0__V101 )) ) ,
# 1236 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)( (__2__X111 = (const void *)__1cl -> string__8classdef ), ( ((& __0__V102 )-> __O1__2ea.p = __2__X111 ), (&
# 1236 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V102 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} { int __1slow ;
int __1first ;
bit __1unconst ;

# 1297 "/home/claude/cfront-3/src/dcl4.cpp"
int __1i ;

# 1237 "/home/claude/cfront-3/src/dcl4.cpp"
__1slow = 0 ;
__1first = 1 ;
__1unconst = 0 ;

# 1241 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1cl -> baselist__8classdef )
# 1242 "/home/claude/cfront-3/src/dcl4.cpp"
__1slow = 1 ;

# 1244 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1slow ){ 
# 1245 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pbcl __2b ;

# 1245 "/home/claude/cfront-3/src/dcl4.cpp"
__2b = __1cl -> baselist__8classdef ;

# 1245 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2b ;__2b = __2b -> next__6basecl ) { 
# 1246 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __3bcl ;
Ptype __3pt ;

# 1246 "/home/claude/cfront-3/src/dcl4.cpp"
__3bcl = __2b -> bclass__6basecl ;
__3pt = __3bcl -> this_type__8classdef ;
switch (__2b -> base__4node ){ 
# 1249 "/home/claude/cfront-3/src/dcl4.cpp"
case 85 :
# 1250 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1252 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __5b1 ;

# 1253 "/home/claude/cfront-3/src/dcl4.cpp"
struct texpr *__0__X112 ;

# 1252 "/home/claude/cfront-3/src/dcl4.cpp"
__5b1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )34 , (struct expr *)0 , (struct expr *)0 ) ;
__5b1 = (struct expr *)( (__0__X112 = 0 ), ( ((__0__X112 || (__0__X112 = (struct texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr)))
# 1253 "/home/claude/cfront-3/src/dcl4.cpp"
))?( (__0__X112 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X112 ), ((unsigned char )191 ), __5b1 , (struct expr *)0 ) ), (__0__X112 ->
# 1253 "/home/claude/cfront-3/src/dcl4.cpp"
__O4__4expr.tp2 = __3pt )) :0 ), __0__X112 ) ) ;
__5b1 = contents__4exprFv ( __5b1 ) ;

# 1256 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pexpr __5b2 ;

# 1257 "/home/claude/cfront-3/src/dcl4.cpp"
struct texpr *__0__X113 ;

# 1256 "/home/claude/cfront-3/src/dcl4.cpp"
__5b2 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ;
__5b2 = address__4exprFv ( __5b2 ) ;
__5b2 = (struct expr *)( (__0__X113 = 0 ), ( ((__0__X113 || (__0__X113 = (struct texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr)))
# 1258 "/home/claude/cfront-3/src/dcl4.cpp"
))?( (__0__X113 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X113 ), ((unsigned char )191 ), __5b2 , (struct expr *)0 ) ), (__0__X113 ->
# 1258 "/home/claude/cfront-3/src/dcl4.cpp"
__O4__4expr.tp2 = __3pt )) :0 ), __0__X113 ) ) ;
__5b2 -> __O3__4expr.i2 = 1 ;
__5b2 = contents__4exprFv ( __5b2 ) ;

# 1262 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pexpr __5ee ;

# 1262 "/home/claude/cfront-3/src/dcl4.cpp"
__5ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __5b1 , __5b2 ) ;
__1e = (__1e ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1e , __5ee ) :__5ee );
break ;

# 1264 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1264 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
case 77 :
# 1267 "/home/claude/cfront-3/src/dcl4.cpp"
if (warning_opt )
# 1268 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1268 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V103 ;

# 1268 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"copying an object ofC%n with a virtualBC", (const struct ea *)( ((&
# 1268 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V103 )-> __O1__2ea.p = ((const void *)__1cn )), (& __0__V103 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1268 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)ea0 ) ;
} if (__2b -> ptr_offset__6basecl ){ 
# 1276 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __5b1 ;

# 1277 "/home/claude/cfront-3/src/dcl4.cpp"
register struct mdot *__0__X114 ;

# 1277 "/home/claude/cfront-3/src/dcl4.cpp"
const char *__2__X115 ;

# 1276 "/home/claude/cfront-3/src/dcl4.cpp"
__5b1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )34 , (struct expr *)0 , (struct expr *)0 ) ;
__5b1 = (struct expr *)( (__0__X114 = 0 ), ( (__2__X115 = __3bcl -> string__8classdef ), ( ((__0__X114 || (__0__X114 = (struct mdot *)__nw__4exprSFUl (
# 1277 "/home/claude/cfront-3/src/dcl4.cpp"
(unsigned long )(sizeof (struct mdot))) ))?( (__0__X114 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X114 ), (unsigned char )177 , (struct
# 1277 "/home/claude/cfront-3/src/dcl4.cpp"
expr *)0 , (struct expr *)0 ) ), ( (__0__X114 -> __O3__4expr.string2 = __2__X115 ), (__0__X114 -> __O4__4expr.mem = __5b1 )) ) :0 ), __0__X114 )
# 1277 "/home/claude/cfront-3/src/dcl4.cpp"
) ) ;
__5b1 -> __O2__4expr.i1 = 3 ;
__5b1 -> __O1__4expr.tp = __3pt ;
__5b1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __5b1 , (struct expr *)0 ) ;

# 1282 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pexpr __5b2 ;

# 1283 "/home/claude/cfront-3/src/dcl4.cpp"
register struct mdot *__0__X116 ;

# 1283 "/home/claude/cfront-3/src/dcl4.cpp"
const char *__2__X117 ;

# 1282 "/home/claude/cfront-3/src/dcl4.cpp"
__5b2 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ;
__5b2 = address__4exprFv ( __5b2 ) ;
__5b2 = (struct expr *)( (__0__X116 = 0 ), ( (__2__X117 = __3bcl -> string__8classdef ), ( ((__0__X116 || (__0__X116 = (struct mdot *)__nw__4exprSFUl (
# 1284 "/home/claude/cfront-3/src/dcl4.cpp"
(unsigned long )(sizeof (struct mdot))) ))?( (__0__X116 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X116 ), (unsigned char )177 , (struct
# 1284 "/home/claude/cfront-3/src/dcl4.cpp"
expr *)0 , (struct expr *)0 ) ), ( (__0__X116 -> __O3__4expr.string2 = __2__X117 ), (__0__X116 -> __O4__4expr.mem = __5b2 )) ) :0 ), __0__X116 )
# 1284 "/home/claude/cfront-3/src/dcl4.cpp"
) ) ;
__5b2 -> __O2__4expr.i1 = 3 ;
__5b2 -> __O1__4expr.tp = __3pt ;
__5b2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __5b2 , (struct expr *)0 ) ;

# 1289 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pexpr __5ee ;

# 1289 "/home/claude/cfront-3/src/dcl4.cpp"
__5ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __5b1 , __5b2 ) ;
__1e = (__1e ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1e , __5ee ) :__5ee );

# 1290 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1290 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
break ;
}
}

# 1294 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1294 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1297 "/home/claude/cfront-3/src/dcl4.cpp"
;
{ { Pname __1m ;

# 1299 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X118 ;

# 1299 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X119 ;

# 1299 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X134 ;

# 1299 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X135 ;

# 1298 "/home/claude/cfront-3/src/dcl4.cpp"
__1m = ( (__0__X134 = __1cl -> memtbl__8classdef ), ( (__2__X135 = (__1i = 1 )), ( (((__2__X135 <= 0 )|| (__0__X134 -> free_slot__5table <=
# 1298 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X135 ))?(((struct name *)0 )):(__0__X134 -> entries__5table [__2__X135 ]))) ) ) ;

# 1298 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1m ;__1m = (__1m -> n_tbl_list__4name ?__1m -> n_tbl_list__4name :( (__0__X118 = __1cl -> memtbl__8classdef ), ( (__2__X119 = (++ __1i )), ( (((__2__X119 <= 0 )||
# 1298 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X118 -> free_slot__5table <= __2__X119 ))?(((struct name *)0 )):(__0__X118 -> entries__5table [__2__X119 ]))) ) ) )) { 
# 1299 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1m -> base__4node == 123 )continue ;
# 1299 "/home/claude/cfront-3/src/dcl4.cpp"

# 1301 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1m -> n_evaluated__4name || (__1m -> n_stclass__4name == 31 ))
# 1302 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 1304 "/home/claude/cfront-3/src/dcl4.cpp"
if (strcmp ( __1m -> __O2__4expr.string , (const char *)"__vptr") == 0 ){ 
# 1307 "/home/claude/cfront-3/src/dcl4.cpp"
if
# 1307 "/home/claude/cfront-3/src/dcl4.cpp"
(((__1first == 0 )&& __1m -> n_offset__4name )&& (! __1e )){ 
# 1310 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __4th ;
Pexpr __4a ;

# 1310 "/home/claude/cfront-3/src/dcl4.cpp"
__4th = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )34 , (struct expr *)0 , (struct expr *)0 ) ;
__4a = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ;
__4a = address__4exprFv ( __4a ) ;
__1e = copy_obj__FP4exprT1i ( __4th , __4a , __1m -> n_offset__4name ) ;
}
__1slow = 1 ;
__1first = 0 ;
continue ;
}
{ Ptype __2mt ;

# 1319 "/home/claude/cfront-3/src/dcl4.cpp"
__2mt = __1m -> __O1__4expr.tp ;
if (__2mt )
# 1321 "/home/claude/cfront-3/src/dcl4.cpp"
tx :switch (__2mt -> base__4node ){ 
# 1322 "/home/claude/cfront-3/src/dcl4.cpp"
case 97 :
# 1323 "/home/claude/cfront-3/src/dcl4.cpp"
__2mt = (((struct basetype *)(((struct basetype *)__2mt ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto tx ;
case 110 :
# 1326 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1327 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __4cn ;

# 1327 "/home/claude/cfront-3/src/dcl4.cpp"
__4cn = is_cl_obj__4typeFv ( (((struct vec *)(((struct vec *)__2mt ))))-> typ__5pvtyp ) ;
if (__4cn && ((((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp ))))-> c_xref__8classdef & 12)){ 
# 1329 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1329 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V104 ;

# 1329 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V105 ;

# 1329 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"copy of %n[], no memberwise copy for%n", (const struct ea *)( ((&
# 1329 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V104 )-> __O1__2ea.p = ((const void *)__4cn )), (& __0__V104 )) , (const struct ea *)( ((& __0__V105 )-> __O1__2ea.p =
# 1329 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__4cn )), (& __0__V105 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1slow = 1 ;
} 
# 1333 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1335 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1slow && tsizeof__4typeFi ( __2mt , 0 ) ){ 
# 1342 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __5l ;
Pexpr __5r ;

# 1344 "/home/claude/cfront-3/src/dcl4.cpp"
struct ref *__0__X120 ;

# 1344 "/home/claude/cfront-3/src/dcl4.cpp"
struct expr *__2__X121 ;

# 1344 "/home/claude/cfront-3/src/dcl4.cpp"
struct expr *__2__X122 ;

# 1342 "/home/claude/cfront-3/src/dcl4.cpp"
__5l = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1m -> __O2__4expr.string ) ;
__5r = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1m -> __O2__4expr.string ) ;
__5r = (struct expr *)( (__0__X120 = 0 ), ( (__2__X121 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ),
# 1344 "/home/claude/cfront-3/src/dcl4.cpp"
( (__2__X122 = __5r ), ( ((__0__X120 || (__0__X120 = (struct ref *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ref))) ))?( (__0__X120 =
# 1344 "/home/claude/cfront-3/src/dcl4.cpp"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X120 ), ((unsigned char )45 ), __2__X121 , (struct expr *)0 ) ), (__0__X120 -> __O4__4expr.mem = __2__X122 ))
# 1344 "/home/claude/cfront-3/src/dcl4.cpp"
:0 ), __0__X120 ) ) ) ) ;
{ Pexpr __5ee ;

# 1345 "/home/claude/cfront-3/src/dcl4.cpp"
__5ee = copy_obj__FP4exprT1i ( __5l , __5r , tsizeof__4typeFi ( __2mt , 0 ) ) ;
__1e = (__1e ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __5ee , __1e ) :__5ee );
break ;

# 1347 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}
case 108 :
# 1351 "/home/claude/cfront-3/src/dcl4.cpp"
case 76 :
# 1352 "/home/claude/cfront-3/src/dcl4.cpp"
case 6 :
# 1353 "/home/claude/cfront-3/src/dcl4.cpp"
case 13 :
# 1354 "/home/claude/cfront-3/src/dcl4.cpp"
break ;
case 119 :
# 1357 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1358 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __4tempcl ;

# 1358 "/home/claude/cfront-3/src/dcl4.cpp"
__4tempcl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__2mt ))))-> b_name__8basetype -> __O1__4expr.tp ))));
if ((__1slow == 0 )&& ((((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__2mt ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> c_xref__8classdef & 12))
# 1363 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1364 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__1first ==
# 1364 "/home/claude/cfront-3/src/dcl4.cpp"
0 )&& __1m -> n_offset__4name ){ 
# 1365 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __6th ;
Pexpr __6a ;

# 1365 "/home/claude/cfront-3/src/dcl4.cpp"
__6th = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )34 , (struct expr *)0 , (struct expr *)0 ) ;
__6a = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ;
__6a = address__4exprFv ( __6a ) ;
__1e = copy_obj__FP4exprT1i ( __6th , __6a , __1m -> n_offset__4name ) ;
}
__1slow = 1 ;
}

# 1373 "/home/claude/cfront-3/src/dcl4.cpp"
suppress_error ++ ;
{ Pname __4nn ;

# 1374 "/home/claude/cfront-3/src/dcl4.cpp"
__4nn = has_oper__8classdefFUc ( __4tempcl , (unsigned char )70 ) ;
suppress_error -- ;
if (__4nn && (__4nn -> __O1__4expr.tp -> base__4node == 108 )){ 
# 1377 "/home/claude/cfront-3/src/dcl4.cpp"
Pptr __5atp ;

# 1378 "/home/claude/cfront-3/src/dcl4.cpp"
unsigned long __2__X16 ;

# 1378 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__X__V1400qmhnqtzzvcnm ;

# 1378 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__X__V1500qmhnqtzzvcnm ;

# 1377 "/home/claude/cfront-3/src/dcl4.cpp"
__5atp = (((struct ptr *)(((struct ptr *)( ((__4nn -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__4nn -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' ,
# 1377 "/home/claude/cfront-3/src/dcl4.cpp"
(const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qmhnqtzzvcnm )-> __O1__2ea.p = ((const
# 1377 "/home/claude/cfront-3/src/dcl4.cpp"
void *)__4nn )), (& __0__X__V1400qmhnqtzzvcnm )) , (const struct ea *)( (__2__X16 = __4nn -> __O1__4expr.tp -> base__4node ), ( ((
# 1377 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__X__V1500qmhnqtzzvcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmhnqtzzvcnm )) ) , (const struct ea *)ea0 , (const
# 1377 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea *)ea0 ) , (((struct fct *)0 ))) )) -> argtype__3fct -> __O1__4expr.tp ))));
if ((__5atp && __5atp -> typ__5pvtyp )&& (__5atp -> typ__5pvtyp -> b_const__4type == 0 )){ 
# 1379 "/home/claude/cfront-3/src/dcl4.cpp"
__1unconst = 1 ;
}
}
else if (__4nn && (__4nn -> __O1__4expr.tp -> base__4node == 76 )){ 
# 1383 "/home/claude/cfront-3/src/dcl4.cpp"
Plist __5pl ;

# 1383 "/home/claude/cfront-3/src/dcl4.cpp"
__5pl = (((struct gen *)(((struct gen *)__4nn -> __O1__4expr.tp ))))-> fct_list__3gen ;
while (__5pl ){ 
# 1385 "/home/claude/cfront-3/src/dcl4.cpp"
Pfct __6ff ;
Ptype __6t ;

# 1387 "/home/claude/cfront-3/src/dcl4.cpp"
register struct name *__0__X123 ;

# 1387 "/home/claude/cfront-3/src/dcl4.cpp"
unsigned long __2__X16 ;

# 1387 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__X__V1400qmhnqtzzvcnm ;

# 1387 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__X__V1500qmhnqtzzvcnm ;

# 1385 "/home/claude/cfront-3/src/dcl4.cpp"
__6ff = ( (__0__X123 = __5pl -> f__9name_list ), ( ((__0__X123 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X123 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 (
# 1385 "/home/claude/cfront-3/src/dcl4.cpp"
(int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qmhnqtzzvcnm )->
# 1385 "/home/claude/cfront-3/src/dcl4.cpp"
__O1__2ea.p = ((const void *)__0__X123 )), (& __0__X__V1400qmhnqtzzvcnm )) , (const struct ea *)( (__2__X16 = __0__X123 -> __O1__4expr.tp -> base__4node ),
# 1385 "/home/claude/cfront-3/src/dcl4.cpp"
( (( ((& __0__X__V1500qmhnqtzzvcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmhnqtzzvcnm )) ) , (const struct
# 1385 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) ;
__6t = is_op_ass__FP3fctP8classdef ( __6ff , __4tempcl ) ;
if (__6t && (__6t -> b_const__4type == 0 )){ 
# 1388 "/home/claude/cfront-3/src/dcl4.cpp"
__1unconst = 1 ;
break ;
}
__5pl = __5pl -> l__9name_list ;
}
}

# 1393 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1396 "/home/claude/cfront-3/src/dcl4.cpp"
case 158 :
# 1397 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2mt -> base__4node == 158 )
# 1398 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1cl -> c_xref__8classdef != 16){ 
# 1399 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1399 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V106 ;

# 1399 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V107 ;

# 1399 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot assignC%t:RM%n", (const struct ea *)( ((& __0__V106 )-> __O1__2ea.p =
# 1399 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1cl )), (& __0__V106 )) , (const struct ea *)( ((& __0__V107 )-> __O1__2ea.p = ((const void
# 1399 "/home/claude/cfront-3/src/dcl4.cpp"
*)__1m )), (& __0__V107 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
} }
else __1slow = 1 ;
default :
# 1405 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1slow ){ 
# 1406 "/home/claude/cfront-3/src/dcl4.cpp"
if (tconst__4typeFv ( __1m -> __O1__4expr.tp ) )
# 1407 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1407 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V108 ;

# 1407 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V109 ;

# 1407 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot assignC%t: const M%n", (const struct ea *)( ((& __0__V108 )-> __O1__2ea.p =
# 1407 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1cl )), (& __0__V108 )) , (const struct ea *)( ((& __0__V109 )-> __O1__2ea.p = ((const void
# 1407 "/home/claude/cfront-3/src/dcl4.cpp"
*)__1m )), (& __0__V109 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} { Pname __4ms ;
Pname __4as ;
Pexpr __4ee ;

# 1411 "/home/claude/cfront-3/src/dcl4.cpp"
struct ref *__0__X124 ;

# 1411 "/home/claude/cfront-3/src/dcl4.cpp"
struct expr *__2__X125 ;

# 1411 "/home/claude/cfront-3/src/dcl4.cpp"
struct expr *__2__X126 ;

# 1408 "/home/claude/cfront-3/src/dcl4.cpp"
__4ms = __ct__4nameFPCc ( (struct name *)0 , __1m -> __O2__4expr.string ) ;
__4as = __ct__4nameFPCc ( (struct name *)0 , __1arg -> __O2__4expr.string ) ;
__4ee = (struct expr *)( (__0__X124 = 0 ), ( (__2__X125 = (struct expr *)__4as ), ( (__2__X126 = (struct expr *)__ct__4nameFPCc ( (struct
# 1410 "/home/claude/cfront-3/src/dcl4.cpp"
name *)0 , __1m -> __O2__4expr.string ) ), ( ((__0__X124 || (__0__X124 = (struct ref *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ref))) ))?(
# 1410 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X124 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X124 ), ((unsigned char )45 ), __2__X125 , (struct expr *)0 ) ), (__0__X124 -> __O4__4expr.mem =
# 1410 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X126 )) :0 ), __0__X124 ) ) ) ) ;
__4ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__4ms , __4ee ) ;
__1e = (__1e ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1e , __4ee ) :__4ee );

# 1412 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}
__1first = 0 ;

# 1415 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1418 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1slow == 0 ){ 
# 1419 "/home/claude/cfront-3/src/dcl4.cpp"
return 0 ;
}

# 1422 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pexpr __1rv ;

# 1423 "/home/claude/cfront-3/src/dcl4.cpp"
struct estmt *__0__X127 ;

# 1423 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X128 ;

# 1423 "/home/claude/cfront-3/src/dcl4.cpp"
struct dcl_context *__0__X129 ;

# 1422 "/home/claude/cfront-3/src/dcl4.cpp"
__1rv = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )34 , (struct expr *)0 , (struct expr *)0 ) ;
__1rv = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __1rv , (struct expr *)0 ) ;

# 1425 "/home/claude/cfront-3/src/dcl4.cpp"
__1s -> __O2__4stmt.e = (__1e ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1e , __1rv ) :__1e );
__1s -> s_list__4stmt = (struct stmt *)( (__0__X127 = 0 ), ( (__2__X128 = no_where ), ( ((__0__X127 || (__0__X127 = (struct estmt *)__nw__4stmtSFUl (
# 1426 "/home/claude/cfront-3/src/dcl4.cpp"
(unsigned long )(sizeof (struct estmt))) ))?( (__0__X127 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X127 ), ((unsigned char )28 ), __2__X128 ,
# 1426 "/home/claude/cfront-3/src/dcl4.cpp"
((struct stmt *)0 )) ), (__0__X127 -> __O2__4stmt.e = __1rv )) :0 ), __0__X127 ) ) ) ;

# 1428 "/home/claude/cfront-3/src/dcl4.cpp"
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 1428 "/home/claude/cfront-3/src/dcl4.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;
cc -> not4__11dcl_context = __1cn ;
cc -> cot__11dcl_context = __1cl ;

# 1432 "/home/claude/cfront-3/src/dcl4.cpp"
__1cl -> c_xref__8classdef |= 4;

# 1434 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pname __1fn ;
Pfct __1f ;

# 1434 "/home/claude/cfront-3/src/dcl4.cpp"
__1fn = __ct__4nameFPCc ( (struct name *)0 , oper_name__FUc ( (unsigned char )70 ) ) ;
__1f = __ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )158 , (((struct ptr *)(((struct ptr *)__1cl ->
# 1435 "/home/claude/cfront-3/src/dcl4.cpp"
this_type__8classdef ))))-> typ__5pvtyp ) , __1arg , (unsigned char )1 ) ;
__1f -> f_inline__3fct = 1 ;
__1f -> f_is_inline__3fct = 1 ;
if (__1unconst )
# 1439 "/home/claude/cfront-3/src/dcl4.cpp"
(((struct ptr *)(((struct ptr *)__1f -> argtype__3fct -> __O1__4expr.tp ))))-> typ__5pvtyp -> b_const__4type = 0 ;
__1fn -> __O1__4expr.tp = (struct type *)__1f ;
__1fn -> n_oper__4name = 70 ;
__1fn -> n_sto__4name = 31 ;
{ Pname __1nn ;

# 1444 "/home/claude/cfront-3/src/dcl4.cpp"
register struct block *__0__X130 ;

# 1444 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X131 ;

# 1444 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X132 ;

# 1444 "/home/claude/cfront-3/src/dcl4.cpp"
struct dcl_context *__0__X133 ;

# 1443 "/home/claude/cfront-3/src/dcl4.cpp"
__1nn = dcl__4nameFP5tableUc ( __1fn , __1cl -> memtbl__8classdef , (unsigned char )25 ) ;
( (__1fn ?(((void )(__1fn ?(((void )( ( ((((struct expr *)__1fn ))?(((void )((((struct expr *)__1fn ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 1444 "/home/claude/cfront-3/src/dcl4.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1fn , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
(((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> body__3fct = ( (__0__X130 = 0 ), ( (__2__X131 = curloc ), ( (__2__X132 = noloc ),
# 1445 "/home/claude/cfront-3/src/dcl4.cpp"
( ((__0__X130 || (__0__X130 = (struct block *)__nw__4stmtSFUl ( (unsigned long )(sizeof (struct block))) ))?(((void )( (__0__X130 = (struct block *)__ct__4stmtFUc3locP4stmt (
# 1445 "/home/claude/cfront-3/src/dcl4.cpp"
((struct stmt *)__0__X130 ), (unsigned char )116 , __2__X131 , __1s ) ), ( (__0__X130 -> __O1__4stmt.d = ((struct name *)0 )), (__0__X130 ->
# 1445 "/home/claude/cfront-3/src/dcl4.cpp"
__O3__4stmt.where2 = __2__X132 )) ) )):(((void )0 ))), __0__X130 ) ) ) ) ;
dcl__3fctFP4name ( ((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))), __1nn ) ;

# 1448 "/home/claude/cfront-3/src/dcl4.cpp"
( ( (cc -- ), (((void )0 ))) ) ;
simpl__4nameFv ( __1nn ) ;

# 1451 "/home/claude/cfront-3/src/dcl4.cpp"
return 1 ;

# 1451 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1451 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1451 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1451 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1451 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1451 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1454 "/home/claude/cfront-3/src/dcl4.cpp"
void prnt_all_in_scope__FP8classdef (Pclass __1cl );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 1454 "/home/claude/cfront-3/src/dcl4.cpp"
void prnt_all_in_scope__FP8classdef (Pclass __1cl ){ 
# 1459 "/home/claude/cfront-3/src/dcl4.cpp"
int __1i ;

# 1461 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1cl -> in_class__4type )
# 1462 "/home/claude/cfront-3/src/dcl4.cpp"
prnt_all_in_scope__FP8classdef ( __1cl -> in_class__4type ) ;
{ { Pname __1nn ;

# 1464 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X138 ;

# 1464 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X139 ;

# 1464 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X140 ;

# 1464 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X141 ;

# 1463 "/home/claude/cfront-3/src/dcl4.cpp"
__1nn = ( (__0__X140 = __1cl -> memtbl__8classdef ), ( (__2__X141 = (__1i = 1 )), ( (((__2__X141 <= 0 )|| (__0__X140 -> free_slot__5table <=
# 1463 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X141 ))?(((struct name *)0 )):(__0__X140 -> entries__5table [__2__X141 ]))) ) ) ;

# 1463 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1nn ;__1nn = (__1nn -> n_tbl_list__4name ?__1nn -> n_tbl_list__4name :( (__0__X138 = __1cl -> memtbl__8classdef ), ( (__2__X139 = (++ __1i )), ( (((__2__X139 <= 0 )||
# 1463 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X138 -> free_slot__5table <= __2__X139 ))?(((struct name *)0 )):(__0__X138 -> entries__5table [__2__X139 ]))) ) ) )) 
# 1464 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1465 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1nn -> base__4node == 123 )continue ;
# 1465 "/home/claude/cfront-3/src/dcl4.cpp"

# 1466 "/home/claude/cfront-3/src/dcl4.cpp"
if ((((__1nn -> base__4node && (__1nn -> base__4node == 85 ))&& (__1nn -> n_anon__4name == 0 ))&& (__1nn -> n_stclass__4name == 31 ))&& (__1nn -> __O1__4expr.tp &&
# 1466 "/home/claude/cfront-3/src/dcl4.cpp"
((((__1nn -> __O1__4expr.tp -> base__4node != 108 )&& (__1nn -> __O1__4expr.tp -> base__4node != 76 ))&& (__1nn -> __O1__4expr.tp -> base__4node != 6 ))&& (__1nn -> __O1__4expr.tp ->
# 1466 "/home/claude/cfront-3/src/dcl4.cpp"
base__4node != 13 ))))
# 1484 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1485 "/home/claude/cfront-3/src/dcl4.cpp"
dcl_print__4nameFUc ( __1nn , (unsigned char )0 ) ;
}
}

# 1487 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1487 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1490 "/home/claude/cfront-3/src/dcl4.cpp"
bit simpl_friend = 0 ;

# 76 "/home/claude/cfront-3/src/cfront.h"

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 467 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 480 "/home/claude/cfront-3/src/cfront.h"
int check_dup__8classdefFP8classdefUc (struct classdef *__0this , Pclass , TOK );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 870 "/home/claude/cfront-3/src/cfront.h"

# 350 "/home/claude/cfront-3/src/cfront.h"
int align__4typeFv (struct type *__0this );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 229 "/home/claude/cfront-3/src/cfront.h"

# 228 "/home/claude/cfront-3/src/cfront.h"
void grow__5tableFi (struct table *__0this , int );

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 463 "/home/claude/cfront-3/src/cfront.h"
Pclass is_base__8classdefFPCcPUci (struct classdef *__0this , const char *, TOK *, int __1level );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 473 "/home/claude/cfront-3/src/cfront.h"
Pexpr find_name__8classdefFPCcP8classdefiT3 (struct classdef *__0this , const char *, Pclass , int , int );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 38 "/home/claude/cfront-3/src/cfront.h"
extern char *make_nested_name__FPCcP8classdef (const char *, Pclass );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 657 "/home/claude/cfront-3/src/cfront.h"
struct name_list *__ct__9name_listFP4nameP9name_list (struct name_list *__0this , Pname __1ff , Plist __1ll );

# 466 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 470 "/home/claude/cfront-3/src/cfront.h"
Pname has_ictor__8classdefFv (struct classdef *__0this );

# 467 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 73 "/home/claude/cfront-3/src/dcl4.cpp"
extern Pname find_vptr__FP8classdef (Pclass );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 122 "/home/claude/cfront-3/src/cfront.h"
extern int is_probably_temp__FPCc (const char *);

# 61 "/home/claude/cfront-3/src/cfront.h"
extern const char *curr_filename__Fv (void );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 450 "/home/claude/cfront-3/src/cfront.h"
void simpl__8classdefFv (struct classdef *__0this );

# 449 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8classdefFP4name (struct classdef *__0this , Pname );

# 2624 "/home/claude/cfront-3/src/dcl4.cpp"
extern void dump_func__FP8classdef (Pclass );

# 2629 "/home/claude/cfront-3/src/dcl4.cpp"
extern void check_abst__FP8classdef (Pclass );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 1492 "/home/claude/cfront-3/src/dcl4.cpp"
void dcl__8classdefFP4nameP5table (register struct classdef *__0this , Pname __1cname , Ptable __1tbl )
# 1493 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1494 "/home/claude/cfront-3/src/dcl4.cpp"
int __1bvirt ;
int __1dvirt ;
int __1scope ;
int __1protect ;
int __1st ;

# 1500 "/home/claude/cfront-3/src/dcl4.cpp"
int __1byte_old ;
int __1bit_old ;
int __1max_old ;
int __1boff ;

# 1505 "/home/claude/cfront-3/src/dcl4.cpp"
int __1in_union ;
int __1usz ;
int __1make_ctor ;
int __1make_dtor ;

# 1509 "/home/claude/cfront-3/src/dcl4.cpp"
unsigned long __2__X212 ;

# 1509 "/home/claude/cfront-3/src/dcl4.cpp"
unsigned long __2__X213 ;

# 1509 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X222 ;

# 1494 "/home/claude/cfront-3/src/dcl4.cpp"
__1bvirt = 0 ;
__1dvirt = 0 ;
__1scope = 25 ;
__1protect = 0 ;
__1st = 1 ;

# 1500 "/home/claude/cfront-3/src/dcl4.cpp"
__1byte_old = byte_offset ;
__1bit_old = bit_offset ;
__1max_old = max_align ;
__1boff = 0 ;

# 1505 "/home/claude/cfront-3/src/dcl4.cpp"
__1in_union = 0 ;

# 1507 "/home/claude/cfront-3/src/dcl4.cpp"
__1make_ctor = 0 ;
__1make_dtor = 0 ;

# 1510 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this == 0 )
# 1511 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1511 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V142 ;

# 1511 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"0->Cdef::dcl(%p)", (const struct ea *)( ((&
# 1511 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V142 )-> __O1__2ea.p = ((const void *)__1tbl )), (& __0__V142 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1511 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)ea0 ) ;
} if (__0this -> base__4node != 6 )
# 1513 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1513 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V143 ;

# 1513 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"Cdef::dcl(%d)", (const struct ea *)( (__2__X212 =
# 1513 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> base__4node ), ( (( ((& __0__V143 )-> __O1__2ea.i = __2__X212 ), 0 ) ), (& __0__V143 )) ) ,
# 1513 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__1cname == 0 )
# 1515 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCc ( (int )'i' , (const char *)"unNdC") ;
# 1515 "/home/claude/cfront-3/src/dcl4.cpp"

# 1516 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1cname -> __O1__4expr.tp != (((struct type *)__0this )))
# 1517 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCc ( (int )'i' , (const char *)"badCdef")
# 1517 "/home/claude/cfront-3/src/dcl4.cpp"
;
if (__1tbl == 0 )
# 1519 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1519 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V144 ;

# 1519 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"Cdef::dcl(%n,0)", (const struct ea *)( ((&
# 1519 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V144 )-> __O1__2ea.p = ((const void *)__1cname )), (& __0__V144 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1519 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)ea0 ) ;
} if (__1tbl -> base__4node != 142 )
# 1521 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1521 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V145 ;

# 1521 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V146 ;

# 1521 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"Cdef::dcl(%n,tbl=%d)", (const struct ea *)( ((&
# 1521 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V145 )-> __O1__2ea.p = ((const void *)__1cname )), (& __0__V145 )) , (const struct ea *)( (__2__X213 = __1tbl -> base__4node ),
# 1521 "/home/claude/cfront-3/src/dcl4.cpp"
( (( ((& __0__V146 )-> __O1__2ea.i = __2__X213 ), 0 ) ), (& __0__V146 )) ) , (const struct
# 1521 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} ;

# 1525 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__0this -> csu__8classdef ){ 
# 1526 "/home/claude/cfront-3/src/dcl4.cpp"
case 36 :
# 1527 "/home/claude/cfront-3/src/dcl4.cpp"
__1in_union = 36 ;
break ;
case 167 :
# 1530 "/home/claude/cfront-3/src/dcl4.cpp"
__1in_union = 167 ;
break ;
case 6 :
# 1533 "/home/claude/cfront-3/src/dcl4.cpp"
__1scope = 0 ;
}

# 1536 "/home/claude/cfront-3/src/dcl4.cpp"
max_align = AL_STRUCT ;

# 1538 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> local_sig__4type ){ 
# 1539 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_context__8classdef = __1tbl ;
__0this -> in_fct__4type = cc -> nof__11dcl_context ;
}
else 
# 1541 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> in_fct__4type = 0 ;

# 1543 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> baselist__8classdef ){ 
# 1555 "/home/claude/cfront-3/src/dcl4.cpp"
Pbcl __2ll ;
Pbcl __2lll ;
Pbcl __2vlist ;
Pbcl __2lx ;

# 1558 "/home/claude/cfront-3/src/dcl4.cpp"
Pbcl __2l ;

# 1555 "/home/claude/cfront-3/src/dcl4.cpp"
__2ll = 0 ;
__2lll = 0 ;
__2vlist = 0 ;
__2l = __0this -> baselist__8classdef ;
for(;__2l ;__2l = __2lx ) { 
# 1560 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __3cl ;

# 1560 "/home/claude/cfront-3/src/dcl4.cpp"
__3cl = __2l -> bclass__6basecl ;

# 1562 "/home/claude/cfront-3/src/dcl4.cpp"
__2lx = __2l -> next__6basecl ;

# 1565 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2l -> ppp__6basecl == 0 ){ 
# 1566 "/home/claude/cfront-3/src/dcl4.cpp"
__2l -> ppp__6basecl = ((__0this -> csu__8classdef == 6 )?174 :25 );

# 1568 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2l -> ppp__6basecl == 174 )
# 1569 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1569 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V147 ;

# 1569 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V148 ;

# 1569 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"B%t private by default: please be explicit ``: private%t", (const struct ea *)( ((&
# 1569 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V147 )-> __O1__2ea.p = ((const void *)__3cl )), (& __0__V147 )) , (const struct ea *)( ((& __0__V148 )-> __O1__2ea.p =
# 1569 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__3cl )), (& __0__V148 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1571 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1573 "/home/claude/cfront-3/src/dcl4.cpp"
if (__3cl && (__3cl -> csu__8classdef == 6 ))
# 1574 "/home/claude/cfront-3/src/dcl4.cpp"
__1st = 0 ;

# 1576 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__3cl -> defined__4type & 3)== 0 ){ 
# 1577 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1577 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V149 ;

# 1577 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"BC %tU", (const struct ea *)( ((& __0__V149 )-> __O1__2ea.p =
# 1577 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__3cl )), (& __0__V149 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1577 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
continue ;
} }
else 
# 1581 "/home/claude/cfront-3/src/dcl4.cpp"
((void )tsizeof__4typeFi ( (struct type *)__3cl , 0 ) );

# 1583 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__3cl -> csu__8classdef == 36 )|| (__3cl -> csu__8classdef == 167 )){ 
# 1584 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCc ( (const char *)"C derived from union")
# 1584 "/home/claude/cfront-3/src/dcl4.cpp"
;
continue ;
}

# 1588 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1in_union ){ 
# 1589 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCc ( (const char *)"derived union") ;
continue ;
}

# 1593 "/home/claude/cfront-3/src/dcl4.cpp"
if ((((warning_opt && ((__2l -> base__4node == 77 )|| (__2l != __0this -> baselist__8classdef )))&& ( __3cl -> c_dtor__8classdef ) )&& ( __3cl ->
# 1593 "/home/claude/cfront-3/src/dcl4.cpp"
c_dtor__8classdef ) -> __O1__4expr.tp )&& (! (((struct fct *)(((struct fct *)( __3cl -> c_dtor__8classdef ) -> __O1__4expr.tp ))))-> f_virtual__3fct ))
# 1597 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1597 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V150 ;
# 1597 "/home/claude/cfront-3/src/dcl4.cpp"

# 1597 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"second or virtualBC%tWout virtual destructor", (const struct ea *)( ((&
# 1597 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V150 )-> __O1__2ea.p = ((const void *)__3cl )), (& __0__V150 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1597 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)ea0 ) ;
} 
# 1599 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2l -> base__4node == 77 ){ 
# 1600 "/home/claude/cfront-3/src/dcl4.cpp"
__2l -> next__6basecl = __2vlist ;
__2vlist = __2l ;
}
else { 
# 1604 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2ll == 0 ){ 
# 1605 "/home/claude/cfront-3/src/dcl4.cpp"
__2lll = __2l ;
__2l -> next__6basecl = 0 ;
}
else 
# 1609 "/home/claude/cfront-3/src/dcl4.cpp"
__2ll -> next__6basecl = __2l ;
__2ll = __2l ;
}
}
if (__2ll ){ 
# 1614 "/home/claude/cfront-3/src/dcl4.cpp"
__2ll -> next__6basecl = __2vlist ;
__0this -> baselist__8classdef = __2lll ;
}
else 
# 1618 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> baselist__8classdef = __2vlist ;

# 1620 "/home/claude/cfront-3/src/dcl4.cpp"
__2lll = 0 ;
__2l = __0this -> baselist__8classdef ;
for(;__2l ;__2l = __2l -> next__6basecl ) { 
# 1623 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __3b ;

# 1624 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X214 ;

# 1624 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X215 ;

# 1623 "/home/claude/cfront-3/src/dcl4.cpp"
__3b = __2l -> bclass__6basecl ;

# 1625 "/home/claude/cfront-3/src/dcl4.cpp"
for(__2ll = __0this -> baselist__8classdef ;__2ll ;__2ll = __2ll -> next__6basecl ) 
# 1626 "/home/claude/cfront-3/src/dcl4.cpp"
if ((! ( (__1__X214 = __3b ), ( (__1__X215 = __2ll -> bclass__6basecl ),
# 1626 "/home/claude/cfront-3/src/dcl4.cpp"
( ((__1__X214 == __1__X215 )?1 :((__1__X214 && __1__X215 )?(((int )same_class__8classdefFP8classdefi ( __1__X214 , __1__X215 , 0 ) )):0 ))) ) ) )&& check_dup__8classdefFP8classdefUc ( __2ll ->
# 1626 "/home/claude/cfront-3/src/dcl4.cpp"
bclass__6basecl , __3b , __2l -> base__4node ) ){ 
# 1627 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2lll )
# 1628 "/home/claude/cfront-3/src/dcl4.cpp"
__2lll -> next__6basecl = __2l -> next__6basecl ;
else 
# 1630 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> baselist__8classdef = __2l -> next__6basecl ;
goto mmm ;
}

# 1634 "/home/claude/cfront-3/src/dcl4.cpp"
__2lll = __2l ;
mmm :;
}

# 1638 "/home/claude/cfront-3/src/dcl4.cpp"
for(__2l = __0this -> baselist__8classdef ;__2l ;__2l = __2l -> next__6basecl ) { 
# 1639 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __3b ;

# 1639 "/home/claude/cfront-3/src/dcl4.cpp"
__3b = __2l -> bclass__6basecl ;
for(__2ll = __3b -> baselist__8classdef ;__2ll ;__2ll = __2ll -> next__6basecl ) { 
# 1641 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2ll -> base__4node == 77 ){ 
# 1642 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __5v ;

# 1642 "/home/claude/cfront-3/src/dcl4.cpp"
__5v = __2ll -> bclass__6basecl ;
{ { Pbcl __5lll ;

# 1644 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X216 ;

# 1644 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X217 ;

# 1644 "/home/claude/cfront-3/src/dcl4.cpp"
register struct basecl *__0__X218 ;

# 1644 "/home/claude/cfront-3/src/dcl4.cpp"
struct basecl *__2__X219 ;

# 1644 "/home/claude/cfront-3/src/dcl4.cpp"
struct node *__0__X9 ;

# 1643 "/home/claude/cfront-3/src/dcl4.cpp"
__5lll = __0this -> baselist__8classdef ;

# 1643 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__5lll ;__5lll = __5lll -> next__6basecl ) 
# 1644 "/home/claude/cfront-3/src/dcl4.cpp"
if (( (__1__X216 = __5lll -> bclass__6basecl ), ( (__1__X217 = __5v ), ( ((__1__X216 == __1__X217 )?1 :((__1__X216 &&
# 1644 "/home/claude/cfront-3/src/dcl4.cpp"
__1__X217 )?(((int )same_class__8classdefFP8classdefi ( __1__X216 , __1__X217 , 0 ) )):0 ))) ) ) ){ 
# 1647 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2ll -> ppp__6basecl < __5lll -> ppp__6basecl )
# 1648 "/home/claude/cfront-3/src/dcl4.cpp"
__5lll ->
# 1648 "/home/claude/cfront-3/src/dcl4.cpp"
ppp__6basecl = __2ll -> ppp__6basecl ;
goto nnn ;
}
__0this -> baselist__8classdef = ( (__0__X218 = 0 ), ( (__2__X219 = __0this -> baselist__8classdef ), ( ((__0__X218 || (__0__X218 = (struct basecl *)__nw__FUl (
# 1651 "/home/claude/cfront-3/src/dcl4.cpp"
(unsigned long )(sizeof (struct basecl))) ))?( (__0__X218 = (struct basecl *)( (__0__X9 = (((struct node *)__0__X218 ))), ( ((__0__X9 || (__0__X9 =
# 1651 "/home/claude/cfront-3/src/dcl4.cpp"
(struct node *)__nw__FUl ( (unsigned long )(sizeof (struct node))) ))?( ( (__0__X9 -> base__4node = 0 ), (__0__X9 -> permanent__4node = 0 ))
# 1651 "/home/claude/cfront-3/src/dcl4.cpp"
, (__0__X9 -> baseclass__4node = 0 )) :0 ), __0__X9 ) ) ), ( (__0__X218 -> baseclass__4node = 1 ), ( (__0__X218 ->
# 1651 "/home/claude/cfront-3/src/dcl4.cpp"
bclass__6basecl = __5v ), ( (__0__X218 -> next__6basecl = __2__X219 ), ( (__0__X218 -> promoted__6basecl = 0 ), ( (__0__X218 -> init__6basecl = 0 ),
# 1651 "/home/claude/cfront-3/src/dcl4.cpp"
( (__0__X218 -> obj_offset__6basecl = (__0__X218 -> ptr_offset__6basecl = 0 )), (__0__X218 -> allocated__6basecl = 0 )) ) ) ) ) )
# 1651 "/home/claude/cfront-3/src/dcl4.cpp"
) :0 ), __0__X218 ) ) ) ;
__0this -> baselist__8classdef -> base__4node = 77 ;
__0this -> baselist__8classdef -> promoted__6basecl = 1 ;

# 1656 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> baselist__8classdef -> ppp__6basecl = __2ll -> ppp__6basecl ;

# 1656 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1656 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
nnn :;
}
}

# 1662 "/home/claude/cfront-3/src/dcl4.cpp"
__2ll = 0 ;
__2lll = 0 ;
__2l = __0this -> baselist__8classdef ;
__0this -> baselist__8classdef = 0 ;
__2vlist = 0 ;
for(;__2l ;__2l = __2lx ) { 
# 1670 "/home/claude/cfront-3/src/dcl4.cpp"
__2lx = __2l -> next__6basecl ;
if (__2l -> base__4node == 77 ){ 
# 1673 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2vlist == 0 ){ 
# 1674 "/home/claude/cfront-3/src/dcl4.cpp"
__2vlist = __2l ;
__2l -> next__6basecl = 0 ;
}
else { 
# 1678 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __5lb ;
Pbcl __5v_prev ;

# 1678 "/home/claude/cfront-3/src/dcl4.cpp"
__5lb = __2l -> bclass__6basecl ;
__5v_prev = 0 ;
{ { Pbcl __5vx ;

# 1680 "/home/claude/cfront-3/src/dcl4.cpp"
Pbcl __5v ;

# 1680 "/home/claude/cfront-3/src/dcl4.cpp"
__5v = __2vlist ;

# 1680 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__5v ;__5v = __5vx ) { 
# 1681 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __6vb ;

# 1681 "/home/claude/cfront-3/src/dcl4.cpp"
__6vb = __5v -> bclass__6basecl ;
__5vx = __5v -> next__6basecl ;

# 1684 "/home/claude/cfront-3/src/dcl4.cpp"
if (has_base__8classdefFP8classdefiT2 ( __5lb , __6vb , 0 , 0 ) ){ 
# 1685 "/home/claude/cfront-3/src/dcl4.cpp"
__2l -> next__6basecl = __5v ;
if (__5v_prev )
# 1687 "/home/claude/cfront-3/src/dcl4.cpp"
__5v_prev -> next__6basecl = __2l ;
else 
# 1689 "/home/claude/cfront-3/src/dcl4.cpp"
__2vlist = __2l ;
break ;
}
if (__5vx == 0 ){ 
# 1693 "/home/claude/cfront-3/src/dcl4.cpp"
__5v -> next__6basecl = __2l ;
__2l -> next__6basecl = 0 ;
break ;
}
__5v_prev = __5v ;
}

# 1698 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1698 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}
else { 
# 1702 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2ll == 0 ){ 
# 1703 "/home/claude/cfront-3/src/dcl4.cpp"
__2lll = __2l ;
__2l -> next__6basecl = 0 ;
}
else 
# 1707 "/home/claude/cfront-3/src/dcl4.cpp"
__2ll -> next__6basecl = __2l ;
__2ll = __2l ;
}
}

# 1712 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2ll ){ 
# 1713 "/home/claude/cfront-3/src/dcl4.cpp"
__2ll -> next__6basecl = __2vlist ;
__0this -> baselist__8classdef = __2lll ;
}
else 
# 1717 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> baselist__8classdef = __2vlist ;

# 1719 "/home/claude/cfront-3/src/dcl4.cpp"
for(__2l = __0this -> baselist__8classdef ;__2l ;__2l = __2l -> next__6basecl ) { 
# 1720 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __3cl ;

# 1720 "/home/claude/cfront-3/src/dcl4.cpp"
__3cl = __2l -> bclass__6basecl ;

# 1722 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2l -> base__4node == 77 ){ 
# 1725 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_xref__8classdef |= 8;
__1dvirt += __3cl -> virt_count__8classdef ;
}
else { 
# 1729 "/home/claude/cfront-3/src/dcl4.cpp"
int __4ba ;

# 1730 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X220 ;

# 1730 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X221 ;

# 1729 "/home/claude/cfront-3/src/dcl4.cpp"
__4ba = align__4typeFv ( (struct type *)__3cl ) ;
if (max_align < __4ba )
# 1731 "/home/claude/cfront-3/src/dcl4.cpp"
max_align = __4ba ;

# 1733 "/home/claude/cfront-3/src/dcl4.cpp"
if (( (__1__X220 = __3cl ), ( (__1__X221 = __0this -> baselist__8classdef -> bclass__6basecl ), ( ((__1__X220 == __1__X221 )?1 :((__1__X220 && __1__X221 )?(((int )same_class__8classdefFP8classdefi (
# 1733 "/home/claude/cfront-3/src/dcl4.cpp"
__1__X220 , __1__X221 , 0 ) )):0 ))) ) ) ){ 
# 1734 "/home/claude/cfront-3/src/dcl4.cpp"
__1boff = __3cl -> real_size__8classdef ;

# 1737 "/home/claude/cfront-3/src/dcl4.cpp"
{ int __5xtra ;

# 1737 "/home/claude/cfront-3/src/dcl4.cpp"
__5xtra = (__1boff % __4ba );

# 1739 "/home/claude/cfront-3/src/dcl4.cpp"
if (__5xtra )
# 1740 "/home/claude/cfront-3/src/dcl4.cpp"
__1boff += (__4ba - __5xtra );

# 1740 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
else { 
# 1743 "/home/claude/cfront-3/src/dcl4.cpp"
int __5xtra ;

# 1743 "/home/claude/cfront-3/src/dcl4.cpp"
__5xtra = (__1boff % __4ba );
if (__5xtra )
# 1745 "/home/claude/cfront-3/src/dcl4.cpp"
__1boff += (__4ba - __5xtra );
__2l -> obj_offset__6basecl = __1boff ;

# 1748 "/home/claude/cfront-3/src/dcl4.cpp"
__1boff += __3cl -> obj_size__8classdef ;
}
__1bvirt += __3cl -> virt_count__8classdef ;
}

# 1753 "/home/claude/cfront-3/src/dcl4.cpp"
if (__3cl -> has_vvtab__8classdef )
# 1754 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> has_vvtab__8classdef = 1 ;
__0this -> c_xref__8classdef |= __3cl -> c_xref__8classdef ;

# 1758 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> conv__8classdef = merge_conv__FP4nameT1 ( __0this -> conv__8classdef , __3cl -> conv__8classdef ) ;
}
}

# 1762 "/home/claude/cfront-3/src/dcl4.cpp"
( (__0__X222 = __0this -> memtbl__8classdef ), ( (__0__X222 -> t_name__5table = __1cname ), (((void )0 ))) ) ;

# 1764 "/home/claude/cfront-3/src/dcl4.cpp"
{ int __1nmem ;
int __1fct_mem ;

# 1766 "/home/claude/cfront-3/src/dcl4.cpp"
struct dcl_context *__0__X223 ;

# 1764 "/home/claude/cfront-3/src/dcl4.cpp"
__1nmem = 0 ;
__1fct_mem = 0 ;
{ 
# 1767 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pname __2m ;

# 1767 "/home/claude/cfront-3/src/dcl4.cpp"
__2m = __0this -> mem_list__8classdef ;

# 1767 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2m ;__2m = __2m -> __O1__4name.n_list ) { 
# 1768 "/home/claude/cfront-3/src/dcl4.cpp"
__1nmem ++ ;
if (__2m -> __O1__4expr.tp && (__2m -> __O1__4expr.tp -> base__4node == 108 ))
# 1770 "/home/claude/cfront-3/src/dcl4.cpp"
__1fct_mem ++ ;
else if (__2m -> base__4node == 123 )
# 1772 "/home/claude/cfront-3/src/dcl4.cpp"
;
else { 
# 1774 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__2m -> __O1__4expr.tp && (__2m -> __O1__4expr.tp -> base__4node == 158 ))&& (__0this -> c_xref__8classdef == 0 ))
# 1775 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_xref__8classdef = 16;
# 1775 "/home/claude/cfront-3/src/dcl4.cpp"

# 1776 "/home/claude/cfront-3/src/dcl4.cpp"
if (((ansi_opt && __2m -> __O1__4expr.tp )&& tconst__4typeFv ( __2m -> __O1__4expr.tp ) )&& (__2m -> n_sto__4name != 31 ))
# 1777 "/home/claude/cfront-3/src/dcl4.cpp"
(((struct basetype *)(((struct basetype *)__2m -> __O1__4expr.tp ))))->
# 1777 "/home/claude/cfront-3/src/dcl4.cpp"
ansi_const__4type = 1 ;
}
}

# 1779 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1779 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 1782 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1nmem )
# 1783 "/home/claude/cfront-3/src/dcl4.cpp"
grow__5tableFi ( __0this -> memtbl__8classdef , (__1nmem <= 2 )?3 :__1nmem ) ;

# 1785 "/home/claude/cfront-3/src/dcl4.cpp"
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 1785 "/home/claude/cfront-3/src/dcl4.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;
cc -> not4__11dcl_context = __1cname ;
cc -> cot__11dcl_context = __0this ;

# 1789 "/home/claude/cfront-3/src/dcl4.cpp"
byte_offset = (__1usz = __1boff );
bit_offset = 0 ;

# 1792 "/home/claude/cfront-3/src/dcl4.cpp"
{ int __1real_virts ;
Pbase __1bt ;

# 1792 "/home/claude/cfront-3/src/dcl4.cpp"
__1real_virts = 0 ;
__1bt = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )119 , __1cname ) ;
__1bt -> b_table__8basetype = __0this -> memtbl__8classdef ;
{ Ptype __1cct ;

# 1795 "/home/claude/cfront-3/src/dcl4.cpp"
__1cct = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , ((struct type *)__1bt )) ) ;

# 1798 "/home/claude/cfront-3/src/dcl4.cpp"
if (strict_opt && perf_opt )
# 1799 "/home/claude/cfront-3/src/dcl4.cpp"
(((struct ptr *)(((struct ptr *)__1cct ))))-> b_const__4type = 2 ;
__0this -> this_type__8classdef = (cc -> tot__11dcl_context = __1cct );
__0this -> this_type__8classdef -> ansi_const__4type = 1 ;
__1cct -> permanent__4node = 1 ;
__1bt -> permanent__4node = 1 ;

# 1805 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pname __1px ;

# 1805 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __1p ;

# 1805 "/home/claude/cfront-3/src/dcl4.cpp"
__1p = __0this -> mem_list__8classdef ;
for(;__1p ;__1p = __1px ) { 
# 1812 "/home/claude/cfront-3/src/dcl4.cpp"
__1px = __1p -> __O1__4name.n_list ;

# 1815 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__1p -> base__4node ){ 
# 1815 "/home/claude/cfront-3/src/dcl4.cpp"
unsigned long __2__X224 ;

# 1816 "/home/claude/cfront-3/src/dcl4.cpp"
case 25 :
# 1817 "/home/claude/cfront-3/src/dcl4.cpp"
__1scope = 25 ;
__1protect = 0 ;
goto prpr ;

# 1821 "/home/claude/cfront-3/src/dcl4.cpp"
case 174 :
# 1822 "/home/claude/cfront-3/src/dcl4.cpp"
__1scope = 0 ;
__1protect = 0 ;
goto prpr ;

# 1826 "/home/claude/cfront-3/src/dcl4.cpp"
case 79 :
# 1827 "/home/claude/cfront-3/src/dcl4.cpp"
__1scope = 0 ;
__1protect = 79 ;
prpr :
# 1830 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1in_union == 167 )
# 1831 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1831 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V151 ;

# 1831 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __1p -> where__4name , (const char *)"%k in anonymous unionD", (const struct ea *)(
# 1831 "/home/claude/cfront-3/src/dcl4.cpp"
(__2__X224 = __1p -> base__4node ), ( (( ((& __0__V151 )-> __O1__2ea.i = __2__X224 ), 0 ) ), (& __0__V151 )) )
# 1831 "/home/claude/cfront-3/src/dcl4.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} continue ;

# 1834 "/home/claude/cfront-3/src/dcl4.cpp"
case 175 :
# 1835 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1836 "/home/claude/cfront-3/src/dcl4.cpp"
const char *__4qs ;
const char *__4ms ;
TOK __4ppp ;

# 1836 "/home/claude/cfront-3/src/dcl4.cpp"
__4qs = __1p -> __O2__4name.n_qualifier -> __O2__4expr.string ;
__4ms = __1p -> __O2__4expr.string ;
__4ppp = (__1scope ?25 :(__1protect ?79 :174 ));

# 1840 "/home/claude/cfront-3/src/dcl4.cpp"
__1p -> base__4node = 85 ;
__1p -> n_scope__4name = __1scope ;
__1p -> n_protect__4name = __1protect ;

# 1844 "/home/claude/cfront-3/src/dcl4.cpp"
if (strcmp ( __4ms , __4qs ) == 0 )
# 1845 "/home/claude/cfront-3/src/dcl4.cpp"
__4ms = (const char *)"__ct";

# 1847 "/home/claude/cfront-3/src/dcl4.cpp"
ppbase = 25 ;

# 1849 "/home/claude/cfront-3/src/dcl4.cpp"
if (is_base__8classdefFPCcPUci ( __0this , __4qs , (TOK *)0 , 0 ) == 0 ){ 
# 1850 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1850 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V152 ;

# 1850 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V153 ;

# 1850 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V154 ;

# 1850 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"%kQr %s not aBC of %t", (const struct ea *)( (( ((& __0__V152 )->
# 1850 "/home/claude/cfront-3/src/dcl4.cpp"
__O1__2ea.i = ((unsigned long )__4ppp )), 0 ) ), (& __0__V152 )) , (const struct ea *)( ((& __0__V153 )->
# 1850 "/home/claude/cfront-3/src/dcl4.cpp"
__O1__2ea.p = ((const void *)__4qs )), (& __0__V153 )) , (const struct ea *)( ((& __0__V154 )-> __O1__2ea.p = ((const
# 1850 "/home/claude/cfront-3/src/dcl4.cpp"
void *)__0this )), (& __0__V154 )) , (const struct ea *)ea0 ) ;
continue ;
} }

# 1854 "/home/claude/cfront-3/src/dcl4.cpp"
mex = 1 ;
tcl = (mec = __0this );
{ Pname __4os ;

# 1856 "/home/claude/cfront-3/src/dcl4.cpp"
__4os = Cdcl ;
Cdcl = __1p ;
{ Pexpr __4ee ;

# 1859 "/home/claude/cfront-3/src/dcl4.cpp"
unsigned long __2__X225 ;

# 1858 "/home/claude/cfront-3/src/dcl4.cpp"
__4ee = find_name__8classdefFPCcP8classdefiT3 ( __0this , __4ms , (struct classdef *)0 , 1 , 0 ) ;
Cdcl = __4os ;

# 1863 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__4ee && (__4ee -> base__4node != 85 ))&& (__4ee -> base__4node != 123 ))
# 1864 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1864 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V155 ;

# 1864 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V156 ;

# 1864 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V157 ;

# 1864 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"bad returnE%k from %t->find_name(%s,0,1)", (const struct ea *)( (__2__X225 =
# 1864 "/home/claude/cfront-3/src/dcl4.cpp"
__4ee -> base__4node ), ( (( ((& __0__V155 )-> __O1__2ea.i = __2__X225 ), 0 ) ), (& __0__V155 )) ) ,
# 1864 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)( ((& __0__V156 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V156 )) , (const struct
# 1864 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)( ((& __0__V157 )-> __O1__2ea.p = ((const void *)__4ms )), (& __0__V157 )) , (const struct ea *)ea0 ) ;
# 1864 "/home/claude/cfront-3/src/dcl4.cpp"
} 
# 1865 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pname __4mx ;

# 1865 "/home/claude/cfront-3/src/dcl4.cpp"
__4mx = (((struct name *)(((struct name *)__4ee ))));

# 1869 "/home/claude/cfront-3/src/dcl4.cpp"
if (__4mx == 0 ){ 
# 1870 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1870 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V158 ;

# 1870 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V159 ;

# 1870 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"C %s does not have aM %s", (const struct ea *)( ((& __0__V158 )-> __O1__2ea.p =
# 1870 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__4qs )), (& __0__V158 )) , (const struct ea *)( ((& __0__V159 )-> __O1__2ea.p = ((const void
# 1870 "/home/claude/cfront-3/src/dcl4.cpp"
*)__4ms )), (& __0__V159 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
continue ;
} }

# 1874 "/home/claude/cfront-3/src/dcl4.cpp"
if (__4mx -> __O1__4expr.tp -> base__4node == 76 ){ 
# 1875 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1875 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V160 ;

# 1875 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V161 ;

# 1875 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"%k specification of overloaded%n", (const struct ea *)( ((
# 1875 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V160 )-> __O1__2ea.i = ((unsigned long )__4ppp )), 0 ) ), (& __0__V160 )) , (const struct ea *)(
# 1875 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V161 )-> __O1__2ea.p = ((const void *)__4mx )), (& __0__V161 )) , (const struct ea *)ea0 , (const struct
# 1875 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
continue ;
} }

# 1879 "/home/claude/cfront-3/src/dcl4.cpp"
{ TOK __4pp ;

# 1879 "/home/claude/cfront-3/src/dcl4.cpp"
__4pp = (__4mx -> n_scope__4name ?25 :(__4mx -> n_protect__4name ?79 :174 ));

# 1882 "/home/claude/cfront-3/src/dcl4.cpp"
if (__4ppp != __4pp ){ 
# 1883 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1883 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V162 ;

# 1883 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V163 ;

# 1883 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V164 ;

# 1883 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __1p -> where__4name , (const char *)"%kM%n specified%k", (const struct ea *)(
# 1883 "/home/claude/cfront-3/src/dcl4.cpp"
(( ((& __0__V162 )-> __O1__2ea.i = ((unsigned long )__4pp )), 0 ) ), (& __0__V162 )) , (const struct
# 1883 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)( ((& __0__V163 )-> __O1__2ea.p = ((const void *)__4mx )), (& __0__V163 )) , (const struct ea *)( ((
# 1883 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V164 )-> __O1__2ea.i = ((unsigned long )__4ppp )), 0 ) ), (& __0__V164 )) , (const struct ea *)ea0 )
# 1883 "/home/claude/cfront-3/src/dcl4.cpp"
;
continue ;
} }

# 1887 "/home/claude/cfront-3/src/dcl4.cpp"
__1p -> __O2__4name.n_qualifier = __4mx ;
{ Pname __4m ;

# 1888 "/home/claude/cfront-3/src/dcl4.cpp"
__4m = insert__5tableFP4nameUc ( __0this -> memtbl__8classdef , __1p , (unsigned char )0 ) ;
__4m -> base__4node = 25 ;
if (Nold )
# 1891 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1891 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V165 ;

# 1891 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoDs ofCM%n", (const struct ea *)( ((& __0__V165 )-> __O1__2ea.p =
# 1891 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1p )), (& __0__V165 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1891 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} continue ;

# 1892 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1892 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1892 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1892 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1892 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}

# 1906 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1scope == 0 ){ 
# 1907 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p -> n_sto__4name != 31 )
# 1908 "/home/claude/cfront-3/src/dcl4.cpp"
__1st = 0 ;
}
else if (__1p -> __O1__4expr.tp -> base__4node == 97 ){ 
# 1911 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __3nn ;

# 1911 "/home/claude/cfront-3/src/dcl4.cpp"
__3nn = is_cl_obj__4typeFv ( __1p -> __O1__4expr.tp ) ;
if (__3nn ){ 
# 1914 "/home/claude/cfront-3/src/dcl4.cpp"
if (((((struct classdef *)(((struct classdef *)__3nn -> __O1__4expr.tp ))))-> csu__8classdef == 6 )&& strcmp ( __0this -> string__8classdef , __3nn -> __O2__4expr.string )
# 1914 "/home/claude/cfront-3/src/dcl4.cpp"
)
# 1919 "/home/claude/cfront-3/src/dcl4.cpp"
__1st = 0 ;
}
}

# 1931 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1in_union == 167 ){ 
# 1932 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__1p -> __O1__4expr.tp -> base__4node == 6 )&& ((((struct classdef *)(((struct classdef *)__1p -> __O1__4expr.tp ))))-> csu__8classdef == 167 )){
# 1932 "/home/claude/cfront-3/src/dcl4.cpp"

# 1934 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __4pu ;

# 1934 "/home/claude/cfront-3/src/dcl4.cpp"
__4pu = (((struct classdef *)(((struct classdef *)__1p -> __O1__4expr.tp ))))-> mem_list__8classdef ;
while (__4pu ){ 
# 1937 "/home/claude/cfront-3/src/dcl4.cpp"
Ptype __5tx ;

# 1937 "/home/claude/cfront-3/src/dcl4.cpp"
__5tx = 0 ;
if (__4pu -> base__4node == 123 )__5tx = __4pu -> __O3__4expr.tpdef ;
else if ((__4pu -> __O1__4expr.tp -> base__4node == 6 )|| (__4pu -> __O1__4expr.tp -> base__4node == 13 ))
# 1941 "/home/claude/cfront-3/src/dcl4.cpp"
__5tx = __4pu -> __O1__4expr.tp ;
else -- __4pu -> lex_level__4name ;
if (__5tx ){ 
# 1944 "/home/claude/cfront-3/src/dcl4.cpp"
__5tx -> in_class__4type = __0this ;
__dl__FPv ( (void *)__5tx -> nested_sig__4type ) ;
__5tx -> nested_sig__4type = make_nested_name__FPCcP8classdef ( __4pu -> __O2__4expr.string , __0this ) ;
}
if (! __4pu -> __O1__4name.n_list )break ;
__4pu = __4pu -> __O1__4name.n_list ;
}
if (__4pu ){ 
# 1952 "/home/claude/cfront-3/src/dcl4.cpp"
__4pu -> __O1__4name.n_list = __1px -> __O1__4name.n_list ;
__1px = (((struct classdef *)(((struct classdef *)__1p -> __O1__4expr.tp ))))-> mem_list__8classdef ;
}
(((struct classdef *)(((struct classdef *)__1p -> __O1__4expr.tp ))))-> mem_list__8classdef = 0 ;
continue ;
}
if (((__1p -> base__4node != 123 )&& (__1p -> __O1__4expr.tp -> base__4node != 6 ))&& (__1p -> __O1__4expr.tp -> base__4node != 13 ))
# 1961 "/home/claude/cfront-3/src/dcl4.cpp"
-- __1p -> lex_level__4name ;
# 1961 "/home/claude/cfront-3/src/dcl4.cpp"

# 1962 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 1965 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p -> base__4node == 123 ){ 
# 1966 "/home/claude/cfront-3/src/dcl4.cpp"
dcl__4nameFP5tableUc ( __1p , __0this -> memtbl__8classdef , (unsigned char )__1scope ) ;

# 1968 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p -> __O1__4expr.tp && ((((struct basetype *)(((struct basetype *)__1p -> __O1__4expr.tp ))))-> base__4node != 119 )){ 
# 1969 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p -> n_dcl_printed__4name == 2 )
# 1970 "/home/claude/cfront-3/src/dcl4.cpp"
;
else dcl_print__4nameFUc ( __1p , (unsigned char )0 ) ;
}
continue ;
}

# 1976 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p -> __O1__4expr.tp -> base__4node == 108 ){ 
# 1977 "/home/claude/cfront-3/src/dcl4.cpp"
int __3ff ;
Pfct __3f ;
Pblock __3b ;

# 1977 "/home/claude/cfront-3/src/dcl4.cpp"
__3ff = 0 ;
__3f = (((struct fct *)(((struct fct *)__1p -> __O1__4expr.tp ))));
__3b = __3f -> body__3fct ;
__3f -> body__3fct = 0 ;
if (__3b ){ 
# 1982 "/home/claude/cfront-3/src/dcl4.cpp"
__3f -> f_inline__3fct = 1 ;
__3f -> f_is_inline__3fct = 1 ;
}
else if (__0this -> lex_level__4type )
# 1986 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1986 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V166 ;

# 1986 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V167 ;

# 1986 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __1p -> where__4name , (const char *)"non-inlineMF%n in localC %t", (const
# 1986 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea *)( ((& __0__V166 )-> __O1__2ea.p = ((const void *)__1p )), (& __0__V166 )) , (const struct ea *)(
# 1986 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V167 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V167 )) , (const struct ea *)ea0 , (const struct
# 1986 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} else if (((((__0this -> csu__8classdef != 167 )&& __0this -> string__8classdef )&& ((__0this -> string__8classdef [0 ])== '_' ))&& ((__0this -> string__8classdef [1 ])== '_' ))&&
# 1987 "/home/claude/cfront-3/src/dcl4.cpp"
((__0this -> string__8classdef [2 ])== 'C' ))
# 1988 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1988 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V168 ;

# 1988 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"non-inlineMF%n in unnamedC", (const struct ea *)( ((& __0__V168 )-> __O1__2ea.p =
# 1988 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1p )), (& __0__V168 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1988 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} switch (__1p -> n_sto__4name ){ 
# 1989 "/home/claude/cfront-3/src/dcl4.cpp"
unsigned long __2__X226 ;

# 1990 "/home/claude/cfront-3/src/dcl4.cpp"
case 18 :
# 1991 "/home/claude/cfront-3/src/dcl4.cpp"
__3ff = 1 ;
break ;
case 31 :
# 1995 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> lex_level__4type )
# 1996 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 1996 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V169 ;

# 1996 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V170 ;

# 1996 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __1p -> where__4name , (const char *)"staticMF%n in localC %t", (const
# 1996 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea *)( ((& __0__V169 )-> __O1__2ea.p = ((const void *)__1p )), (& __0__V169 )) , (const struct ea *)(
# 1996 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V170 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V170 )) , (const struct ea *)ea0 , (const struct
# 1996 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} __3f -> f_static__3fct = 1 ;
__1p -> n_sto__4name = 0 ;
break ;
case 2 :
# 2001 "/home/claude/cfront-3/src/dcl4.cpp"
case 27 :
# 2002 "/home/claude/cfront-3/src/dcl4.cpp"
case 14 :
# 2003 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2003 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V171 ;

# 2003 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V172 ;

# 2003 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __1p -> where__4name , (const char *)"M%n cannot be%k", (const struct ea *)(
# 2003 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V171 )-> __O1__2ea.p = ((const void *)__1p )), (& __0__V171 )) , (const struct ea *)( (__2__X226 = __1p ->
# 2003 "/home/claude/cfront-3/src/dcl4.cpp"
n_sto__4name ), ( (( ((& __0__V172 )-> __O1__2ea.i = __2__X226 ), 0 ) ), (& __0__V172 )) ) , (const
# 2003 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1p -> n_sto__4name = 0 ;
} }

# 2007 "/home/claude/cfront-3/src/dcl4.cpp"
if (__3f -> f_virtual__3fct )__1real_virts ++ ;
if (__3ff && (__3f -> fct_base__3fct == 1))continue ;

# 2010 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pname __3m ;

# 2010 "/home/claude/cfront-3/src/dcl4.cpp"
__3m = dcl__4nameFP5tableUc ( __1p , __0this -> memtbl__8classdef , (unsigned char )__1scope ) ;
if ((__3m == 0 )|| (__3m -> __O1__4expr.tp -> base__4node != 108 ))
# 2012 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;
if (__3m -> __O3__4expr.n_initializer ){ 
# 2014 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_abstract__8classdef = __3m ;
if (__3m -> n_oper__4name == 162 )
# 2016 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2016 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V173 ;

# 2016 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"please provide an out-of-line definition: %n {}; which is needed by derived classes", (const struct ea *)( ((&
# 2016 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V173 )-> __O1__2ea.p = ((const void *)__3m )), (& __0__V173 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2016 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)ea0 ) ;
} }
if (__3ff == 0 )
# 2019 "/home/claude/cfront-3/src/dcl4.cpp"
__3m -> n_protect__4name = __1protect ;
if (__3b ){ 
# 2021 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__3m -> __O1__4expr.tp -> defined__4type & 01 )|| (((struct fct *)(((struct fct *)__3m -> __O1__4expr.tp ))))-> body__3fct )
# 2022 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2022 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V174 ;
# 2022 "/home/claude/cfront-3/src/dcl4.cpp"

# 2022 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __1p -> where__4name , (const char *)"two definitions of%n", (const struct ea *)(
# 2022 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V174 )-> __O1__2ea.p = ((const void *)__3m )), (& __0__V174 )) , (const struct ea *)ea0 , (const struct
# 2022 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 2024 "/home/claude/cfront-3/src/dcl4.cpp"
(((struct fct *)(((struct fct *)__3m -> __O1__4expr.tp ))))-> body__3fct = __3b ;
(((struct fct *)(((struct fct *)__3m -> __O1__4expr.tp ))))-> def_context__3fct = __3f -> def_context__3fct ;
}
}
if ((__3ff == 0 )&& (__1p -> __O1__4expr.tp != __3m -> __O1__4expr.tp ))
# 2029 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2029 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V175 ;

# 2029 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __1p -> where__4name , (const char *)"%n cannot be redeclared inCD", (const struct ea *)(
# 2029 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V175 )-> __O1__2ea.p = ((const void *)__1p )), (& __0__V175 )) , (const struct ea *)ea0 , (const struct
# 2029 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 2029 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
else { 
# 2032 "/home/claude/cfront-3/src/dcl4.cpp"
Eppp = (__1scope ?__1scope :(__1protect ?__1protect :0 ));

# 2034 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p -> __O3__4expr.n_initializer ){ 
# 2035 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2035 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V176 ;

# 2035 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __1p -> where__4name , (const char *)"Ir forM%n", (const struct ea *)(
# 2035 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V176 )-> __O1__2ea.p = ((const void *)__1p )), (& __0__V176 )) , (const struct ea *)ea0 , (const struct
# 2035 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
__1p -> __O3__4expr.n_initializer = 0 ;
} }

# 2039 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p -> __O1__4expr.tp -> base__4node == 76 ){ 
# 2040 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Plist __4gl ;

# 2040 "/home/claude/cfront-3/src/dcl4.cpp"
__4gl = (((struct gen *)(((struct gen *)__1p -> __O1__4expr.tp ))))-> fct_list__3gen ;

# 2040 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) { 
# 2041 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5nn ;
Pfct __5ff ;

# 2041 "/home/claude/cfront-3/src/dcl4.cpp"
__5nn = __4gl -> f__9name_list ;
__5ff = (((struct fct *)(((struct fct *)__5nn -> __O1__4expr.tp ))));
if (__5ff -> f_virtual__3fct )__1real_virts ++ ;
}

# 2044 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2044 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2049 "/home/claude/cfront-3/src/dcl4.cpp"
{ TOK __3is_friend ;

# 2049 "/home/claude/cfront-3/src/dcl4.cpp"
__3is_friend = __1p -> n_sto__4name ;
if ((__1protect && (__1p -> __O1__4expr.tp -> base__4node == 119 ))&& ((((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1p -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))))->
# 2050 "/home/claude/cfront-3/src/dcl4.cpp"
csu__8classdef == 167 ))
# 2057 "/home/claude/cfront-3/src/dcl4.cpp"
__1p -> n_protect__4name = __1protect ;

# 2059 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pname __3m ;

# 2059 "/home/claude/cfront-3/src/dcl4.cpp"
__3m = dcl__4nameFP5tableUc ( __1p , __0this -> memtbl__8classdef , (unsigned char )__1scope ) ;
Eppp = 0 ;
if (__3m == 0 )
# 2062 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 2064 "/home/claude/cfront-3/src/dcl4.cpp"
__3m -> n_protect__4name = __1protect ;

# 2066 "/home/claude/cfront-3/src/dcl4.cpp"
if (__3m -> n_stclass__4name == 31 ){ 
# 2067 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1in_union && (__3is_friend != 18 ))
# 2068 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2068 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V177 ;

# 2068 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __3m -> where__4name , (const char *)"staticM%n in union", (const struct ea *)(
# 2068 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V177 )-> __O1__2ea.p = ((const void *)__3m )), (& __0__V177 )) , (const struct ea *)ea0 , (const struct
# 2068 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__3is_friend != 18 ){ 
# 2070 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> lex_level__4type )
# 2071 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2071 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V178 ;

# 2071 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V179 ;

# 2071 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __3m -> where__4name , (const char *)"staticM%n in localC %t", (const struct ea *)(
# 2071 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V178 )-> __O1__2ea.p = ((const void *)__3m )), (& __0__V178 )) , (const struct ea *)( ((& __0__V179 )->
# 2071 "/home/claude/cfront-3/src/dcl4.cpp"
__O1__2ea.p = ((const void *)__0this )), (& __0__V179 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 2071 "/home/claude/cfront-3/src/dcl4.cpp"
} 
# 2072 "/home/claude/cfront-3/src/dcl4.cpp"
}
__3m -> n_sto__4name = 14 ;
if (__1tbl == gtbl )
# 2075 "/home/claude/cfront-3/src/dcl4.cpp"
stat_mem_list = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __3m , stat_mem_list ) ;
if (__3m -> __O3__4expr.n_initializer )
# 2077 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2077 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V180 ;

# 2077 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"staticM%nWIr", (const struct ea *)( ((&
# 2077 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V180 )-> __O1__2ea.p = ((const void *)__3m )), (& __0__V180 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2077 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)ea0 ) ;
} }

# 2080 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1in_union ){ 
# 2081 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1usz < byte_offset )
# 2082 "/home/claude/cfront-3/src/dcl4.cpp"
__1usz = byte_offset ;
byte_offset = 0 ;
if (__1in_union == 167 )
# 2085 "/home/claude/cfront-3/src/dcl4.cpp"
__3m -> n_offset__4name += __1byte_old ;
}

# 2086 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2086 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}

# 2090 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1st && (__0this -> csu__8classdef == 6 ))
# 2091 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> csu__8classdef = 32 ;
if ((__1st == 0 )&& (__0this -> csu__8classdef == 32 ))
# 2093 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> csu__8classdef = 6 ;

# 2095 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1in_union )
# 2096 "/home/claude/cfront-3/src/dcl4.cpp"
byte_offset = __1usz ;

# 2100 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pname __1ct ;
Pname __1dt ;

# 2103 "/home/claude/cfront-3/src/dcl4.cpp"
int __1i ;

# 2105 "/home/claude/cfront-3/src/dcl4.cpp"
int __1omex ;

# 2100 "/home/claude/cfront-3/src/dcl4.cpp"
__1ct = ( __0this -> c_ctor__8classdef ) ;
__1dt = ( __0this -> c_dtor__8classdef ) ;

# 2105 "/home/claude/cfront-3/src/dcl4.cpp"
__1omex = mex ;

# 2105 "/home/claude/cfront-3/src/dcl4.cpp"
mex = 0 ;
{ Pname __1on ;
Pname __1onv ;
Pname __1od ;
Pname __1odv ;

# 2106 "/home/claude/cfront-3/src/dcl4.cpp"
__1on = has_oper__8classdefFUc ( __0this , (unsigned char )23 ) ;
__1onv = has_oper__8classdefFUc ( __0this , (unsigned char )213 ) ;
__1od = has_oper__8classdefFUc ( __0this , (unsigned char )9 ) ;
__1odv = has_oper__8classdefFUc ( __0this , (unsigned char )212 ) ;
mex = __1omex ;

# 2112 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__1dt && (__1ct == 0 ))&& ((((struct fct *)(((struct fct *)__1dt -> __O1__4expr.tp ))))-> f_virtual__3fct == 0 ))
# 2113 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2113 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V181 ;

# 2113 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V182 ;

# 2113 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%t has%n but noK", (const struct ea *)( ((&
# 2113 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V181 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V181 )) , (const struct ea *)( ((& __0__V182 )-> __O1__2ea.p =
# 2113 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1dt )), (& __0__V182 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__1on && (__1od == 0 ))
# 2115 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2115 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V183 ;

# 2115 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V184 ;

# 2115 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%t has%n but no operator delete()", (const struct ea *)( ((&
# 2115 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V183 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V183 )) , (const struct ea *)( ((& __0__V184 )-> __O1__2ea.p =
# 2115 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1on )), (& __0__V184 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__1od && (__1on == 0 ))
# 2117 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2117 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V185 ;

# 2117 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V186 ;

# 2117 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%t has%n but no operator new()", (const struct ea *)( ((&
# 2117 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V185 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V185 )) , (const struct ea *)( ((& __0__V186 )-> __O1__2ea.p =
# 2117 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1od )), (& __0__V186 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__1onv && (__1odv == 0 ))
# 2119 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2119 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V187 ;

# 2119 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V188 ;

# 2119 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%t has%n but no operator delete[]()", (const struct ea *)( ((&
# 2119 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V187 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V187 )) , (const struct ea *)( ((& __0__V188 )-> __O1__2ea.p =
# 2119 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1on )), (& __0__V188 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__1odv && (__1onv == 0 ))
# 2121 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2121 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V189 ;

# 2121 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V190 ;

# 2121 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%t has%n but no operator new[]()", (const struct ea *)( ((&
# 2121 "/home/claude/cfront-3/src/dcl4.cpp"
__0__V189 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V189 )) , (const struct ea *)( ((& __0__V190 )-> __O1__2ea.p =
# 2121 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1od )), (& __0__V190 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 2123 "/home/claude/cfront-3/src/dcl4.cpp"
if ((((__1dt == 0 )&& __1od )&& __1od )&& (__1od -> __O4__4expr.n_table == __0this -> memtbl__8classdef ))
# 2124 "/home/claude/cfront-3/src/dcl4.cpp"
__1make_dtor = 1 ;

# 2126 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pname __1m ;

# 2127 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X227 ;

# 2127 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X228 ;

# 2127 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X254 ;

# 2127 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X255 ;

# 2126 "/home/claude/cfront-3/src/dcl4.cpp"
__1m = ( (__0__X254 = __0this -> memtbl__8classdef ), ( (__2__X255 = (__1i = 1 )), ( (((__2__X255 <= 0 )|| (__0__X254 -> free_slot__5table <=
# 2126 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X255 ))?(((struct name *)0 )):(__0__X254 -> entries__5table [__2__X255 ]))) ) ) ;

# 2126 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1m ;__1m = (__1m -> n_tbl_list__4name ?__1m -> n_tbl_list__4name :( (__0__X227 = __0this -> memtbl__8classdef ), ( (__2__X228 = (++ __1i )), ( (((__2__X228 <= 0 )||
# 2126 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X227 -> free_slot__5table <= __2__X228 ))?(((struct name *)0 )):(__0__X227 -> entries__5table [__2__X228 ]))) ) ) )) { 
# 2127 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1m -> base__4node == 123 )continue ;
# 2127 "/home/claude/cfront-3/src/dcl4.cpp"

# 2132 "/home/claude/cfront-3/src/dcl4.cpp"
{ Ptype __2t ;

# 2132 "/home/claude/cfront-3/src/dcl4.cpp"
__2t = __1m -> __O1__4expr.tp ;

# 2134 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2t == 0 )
# 2135 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 2138 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__2t -> base__4node ){ 
# 2139 "/home/claude/cfront-3/src/dcl4.cpp"
default :
# 2140 "/home/claude/cfront-3/src/dcl4.cpp"
if (((__1ct == 0 )&& (__1m -> n_stclass__4name != 13 ))&& (__1m -> n_stclass__4name != 31 ))
# 2146 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2147 "/home/claude/cfront-3/src/dcl4.cpp"
if
# 2147 "/home/claude/cfront-3/src/dcl4.cpp"
(is_ref__4typeFv ( __2t ) )
# 2148 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2148 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V191 ;

# 2148 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V192 ;

# 2148 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"R%n inC%tWoutK", (const struct ea *)( ((& __0__V191 )-> __O1__2ea.p =
# 2148 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1m )), (& __0__V191 )) , (const struct ea *)( ((& __0__V192 )-> __O1__2ea.p = ((const void
# 2148 "/home/claude/cfront-3/src/dcl4.cpp"
*)__0this )), (& __0__V192 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if ((tconst__4typeFv ( __2t ) && (vec_const == 0 ))&& (__1m -> n_evaluated__4name == 0 ))
# 2156 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2156 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V193 ;

# 2156 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V194 ;

# 2156 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"const%n inC%tWoutK", (const struct ea *)( ((& __0__V193 )-> __O1__2ea.p =
# 2156 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1m )), (& __0__V193 )) , (const struct ea *)( ((& __0__V194 )-> __O1__2ea.p = ((const void
# 2156 "/home/claude/cfront-3/src/dcl4.cpp"
*)__0this )), (& __0__V194 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 2159 "/home/claude/cfront-3/src/dcl4.cpp"
case 110 :
# 2160 "/home/claude/cfront-3/src/dcl4.cpp"
break ;

# 2162 "/home/claude/cfront-3/src/dcl4.cpp"
case 108 :
# 2163 "/home/claude/cfront-3/src/dcl4.cpp"
case 76 :
# 2164 "/home/claude/cfront-3/src/dcl4.cpp"
case 6 :
# 2165 "/home/claude/cfront-3/src/dcl4.cpp"
case 13 :
# 2166 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;
}

# 2169 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pname __2cn ;

# 2169 "/home/claude/cfront-3/src/dcl4.cpp"
__2cn = is_cl_obj__4typeFv ( __2t ) ;
if (__2cn == 0 )
# 2171 "/home/claude/cfront-3/src/dcl4.cpp"
__2cn = cl_obj_vec ;
if (__2cn == 0 )
# 2173 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 2175 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pclass __2cl ;

# 2175 "/home/claude/cfront-3/src/dcl4.cpp"
__2cl = (((struct classdef *)(((struct classdef *)__2cn -> __O1__4expr.tp ))));
__0this -> c_xref__8classdef |= __2cl -> c_xref__8classdef ;

# 2178 "/home/claude/cfront-3/src/dcl4.cpp"
if (( __2cl -> c_ctor__8classdef ) ){ 
# 2179 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1m -> n_stclass__4name == 31 )
# 2180 "/home/claude/cfront-3/src/dcl4.cpp"
;
else if (__1in_union ){ 
# 2181 "/home/claude/cfront-3/src/dcl4.cpp"
const void *__2__X229 ;

# 2182 "/home/claude/cfront-3/src/dcl4.cpp"
if (strncmp ( (const char *)"__C", __0this -> string__8classdef , (unsigned long )3 )
# 2182 "/home/claude/cfront-3/src/dcl4.cpp"
== 0 )
# 2183 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2183 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V195 ;

# 2183 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V196 ;

# 2183 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"M %s ofC%tWK in union", (const struct ea *)( (__2__X229 = (const void
# 2183 "/home/claude/cfront-3/src/dcl4.cpp"
*)__1m -> __O2__4expr.string ), ( ((& __0__V195 )-> __O1__2ea.p = __2__X229 ), (& __0__V195 )) ) , (const struct ea *)(
# 2183 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V196 )-> __O1__2ea.p = ((const void *)__2cl )), (& __0__V196 )) , (const struct ea *)ea0 , (const struct
# 2183 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} else 
# 2185 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2185 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V197 ;

# 2185 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V198 ;

# 2185 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"M%n ofC%tWK in union", (const struct ea *)( ((& __0__V197 )-> __O1__2ea.p =
# 2185 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1m )), (& __0__V197 )) , (const struct ea *)( ((& __0__V198 )-> __O1__2ea.p = ((const void
# 2185 "/home/claude/cfront-3/src/dcl4.cpp"
*)__2cl )), (& __0__V198 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else if (__1ct == 0 ){ 
# 2189 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__1make_ctor == 0 )&& (has_ictor__8classdefFv ( __2cl ) == 0 ))
# 2190 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2190 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V199 ;
# 2190 "/home/claude/cfront-3/src/dcl4.cpp"

# 2190 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t needs aK; it has aMWK requiringAs", (const struct ea *)( ((& __0__V199 )-> __O1__2ea.p =
# 2190 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__0this )), (& __0__V199 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2190 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} __1make_ctor = 1 ;
}
}
if (__1in_union && (__0this -> c_xref__8classdef & 4))
# 2195 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2195 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V200 ;

# 2195 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V201 ;

# 2195 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"M%n ofC%tW assignment operator in union", (const struct ea *)( ((& __0__V200 )-> __O1__2ea.p =
# 2195 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1m )), (& __0__V200 )) , (const struct ea *)( ((& __0__V201 )-> __O1__2ea.p = ((const void
# 2195 "/home/claude/cfront-3/src/dcl4.cpp"
*)__2cl )), (& __0__V201 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 2197 "/home/claude/cfront-3/src/dcl4.cpp"
if (( __2cl -> c_dtor__8classdef ) ){ 
# 2198 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1m -> n_stclass__4name == 31 )
# 2199 "/home/claude/cfront-3/src/dcl4.cpp"
;
else if (__1in_union ){ 
# 2200 "/home/claude/cfront-3/src/dcl4.cpp"
const void *__2__X230 ;

# 2201 "/home/claude/cfront-3/src/dcl4.cpp"
if (strncmp ( (const char *)"__C", __0this -> string__8classdef , (unsigned long )3 )
# 2201 "/home/claude/cfront-3/src/dcl4.cpp"
== 0 )
# 2202 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2202 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V202 ;

# 2202 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V203 ;

# 2202 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"M %s ofC%tW destructor in union", (const struct ea *)( (__2__X230 = (const void
# 2202 "/home/claude/cfront-3/src/dcl4.cpp"
*)__1m -> __O2__4expr.string ), ( ((& __0__V202 )-> __O1__2ea.p = __2__X230 ), (& __0__V202 )) ) , (const struct ea *)(
# 2202 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V203 )-> __O1__2ea.p = ((const void *)__2cl )), (& __0__V203 )) , (const struct ea *)ea0 , (const struct
# 2202 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} else 
# 2204 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2204 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V204 ;

# 2204 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V205 ;

# 2204 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"M%n ofC%tW destructor in union", (const struct ea *)( ((& __0__V204 )-> __O1__2ea.p =
# 2204 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__1m )), (& __0__V204 )) , (const struct ea *)( ((& __0__V205 )-> __O1__2ea.p = ((const void
# 2204 "/home/claude/cfront-3/src/dcl4.cpp"
*)__2cl )), (& __0__V205 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else if (__1dt == 0 )
# 2207 "/home/claude/cfront-3/src/dcl4.cpp"
__1make_dtor = 1 ;
}

# 2208 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2208 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2208 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2211 "/home/claude/cfront-3/src/dcl4.cpp"
if ((( __0this -> c_dtor__8classdef ) == 0 )&& (__1make_dtor == 0 )){ 
# 2213 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __2bcl ;

# 2213 "/home/claude/cfront-3/src/dcl4.cpp"
__2bcl = 0 ;
{ { Pbcl __2b ;

# 2214 "/home/claude/cfront-3/src/dcl4.cpp"
__2b = __0this -> baselist__8classdef ;

# 2214 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2b ;__2b = __2b -> next__6basecl ) { 
# 2215 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__2b -> base__4node ){ 
# 2215 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__0__X232 ;

# 2216 "/home/claude/cfront-3/src/dcl4.cpp"
case 85 :
# 2217 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2bcl == 0 ){ 
# 2218 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5d ;

# 2219 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__0__X231 ;

# 2218 "/home/claude/cfront-3/src/dcl4.cpp"
__5d = ( (__0__X231 = __2b -> bclass__6basecl ), ( __0__X231 -> c_dtor__8classdef ) ) ;
if (__5d == 0 )
# 2220 "/home/claude/cfront-3/src/dcl4.cpp"
break ;

# 2234 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2236 "/home/claude/cfront-3/src/dcl4.cpp"
__1make_dtor = 1 ;
goto zbzb ;
case 77 :
# 2239 "/home/claude/cfront-3/src/dcl4.cpp"
if (( (__0__X232 = __2b -> bclass__6basecl ), ( __0__X232 -> c_dtor__8classdef ) ) )
# 2240 "/home/claude/cfront-3/src/dcl4.cpp"
__1make_dtor = 1 ;
goto zbzb ;
}
}
if (__2bcl )
# 2245 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_dtor__8classdef = ( __2bcl -> c_dtor__8classdef ) ;
zbzb :;

# 2246 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2246 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2249 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1make_dtor && (__1dt == 0 )){ 
# 2252 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2n ;
Pfct __2f ;

# 2254 "/home/claude/cfront-3/src/dcl4.cpp"
register struct block *__0__X233 ;

# 2254 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X234 ;

# 2254 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X235 ;

# 2252 "/home/claude/cfront-3/src/dcl4.cpp"
__2n = __ct__4nameFPCc ( (struct name *)0 , __0this -> string__8classdef ) ;
__2f = __ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)defa_type , (struct name *)0 , (unsigned char )1 ) ;
__2f -> f_inline__3fct = 1 ;
__2f -> f_is_inline__3fct = 1 ;
__2n -> __O1__4expr.tp = (struct type *)__2f ;
__2n -> n_oper__4name = 162 ;
__1dt = dcl__4nameFP5tableUc ( __2n , __0this -> memtbl__8classdef , (unsigned char )25 ) ;
( (__2n ?(((void )(__2n ?(((void )( ( ((((struct expr *)__2n ))?(((void )((((struct expr *)__2n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 2259 "/home/claude/cfront-3/src/dcl4.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__2n , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
(((struct fct *)(((struct fct *)__1dt -> __O1__4expr.tp ))))-> body__3fct = ( (__0__X233 = 0 ), ( (__2__X234 = curloc ), ( (__2__X235 = noloc ),
# 2260 "/home/claude/cfront-3/src/dcl4.cpp"
( ((__0__X233 || (__0__X233 = (struct block *)__nw__4stmtSFUl ( (unsigned long )(sizeof (struct block))) ))?(((void )( (__0__X233 = (struct block *)__ct__4stmtFUc3locP4stmt (
# 2260 "/home/claude/cfront-3/src/dcl4.cpp"
((struct stmt *)__0__X233 ), (unsigned char )116 , __2__X234 , ((struct stmt *)0 )) ), ( (__0__X233 -> __O1__4stmt.d = ((struct name *)0 )),
# 2260 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X233 -> __O3__4stmt.where2 = __2__X235 )) ) )):(((void )0 ))), __0__X233 ) ) ) ) ;
__1dt = ( __0this -> c_dtor__8classdef ) ;
}

# 2264 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> virt_count__8classdef && (find_vptr__FP8classdef ( __0this ) == 0 )){ 
# 2268 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2vp ;

# 2268 "/home/claude/cfront-3/src/dcl4.cpp"
__2vp = __ct__4nameFPCc ( (struct name *)0 , (const char *)"__vptr") ;
__2vp -> __O1__4expr.tp = Pvptr_type ;
((void )dcl__4nameFP5tableUc ( __2vp , __0this -> memtbl__8classdef , (unsigned char )0 ) );
( (__2vp ?(((void )(__2vp ?(((void )( ( ((((struct expr *)__2vp ))?(((void )((((struct expr *)__2vp ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 2271 "/home/claude/cfront-3/src/dcl4.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__2vp , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
__0this -> c_xref__8classdef |= 1;
}
else { 
# 2278 "/home/claude/cfront-3/src/dcl4.cpp"
if (bit_offset ){ 
# 2279 "/home/claude/cfront-3/src/dcl4.cpp"
byte_offset += ((bit_offset / BI_IN_BYTE )+ ((bit_offset % BI_IN_BYTE )?1 :0 ));
bit_offset = 0 ;
}
}

# 2285 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pbcl __1b ;

# 2285 "/home/claude/cfront-3/src/dcl4.cpp"
__1b = __0this -> baselist__8classdef ;
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 2287 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1b -> base__4node != 77 )
# 2288 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;
{ Pclass __2bcl ;

# 2289 "/home/claude/cfront-3/src/dcl4.cpp"
__2bcl = __1b -> bclass__6basecl ;

# 2292 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pbcl __2bb ;

# 2292 "/home/claude/cfront-3/src/dcl4.cpp"
__2bb = __0this -> baselist__8classdef ;

# 2292 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2bb ;__2bb = __2bb -> next__6basecl ) 
# 2293 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2bb -> base__4node == 85 ){ 
# 2294 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pbcl __3l ;

# 2295 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X236 ;

# 2295 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__1__X237 ;

# 2294 "/home/claude/cfront-3/src/dcl4.cpp"
__3l = __2bb -> bclass__6basecl -> baselist__8classdef ;

# 2294 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__3l ;__3l = __3l -> next__6basecl ) 
# 2295 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__3l -> base__4node == 77 )&& ( (__1__X236 = __3l -> bclass__6basecl ), ( (__1__X237 = __2bcl ),
# 2295 "/home/claude/cfront-3/src/dcl4.cpp"
( ((__1__X236 == __1__X237 )?1 :((__1__X236 && __1__X237 )?(((int )same_class__8classdefFP8classdefi ( __1__X236 , __1__X237 , 0 ) )):0 ))) ) ) )
# 2296 "/home/claude/cfront-3/src/dcl4.cpp"
goto eee ;

# 2296 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2296 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2299 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2301 "/home/claude/cfront-3/src/dcl4.cpp"
if ((((int )__0this -> obj_align__8classdef ))< AL_WPTR )
# 2302 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> obj_align__8classdef = AL_WPTR ;
if (max_align < AL_WPTR )
# 2304 "/home/claude/cfront-3/src/dcl4.cpp"
max_align = AL_WPTR ;
{ int __3waste ;

# 2305 "/home/claude/cfront-3/src/dcl4.cpp"
__3waste = (byte_offset % AL_WPTR );
if (__3waste )
# 2307 "/home/claude/cfront-3/src/dcl4.cpp"
byte_offset += (AL_WPTR - __3waste );
__1b -> ptr_offset__6basecl = (byte_offset + 1 );
byte_offset += SZ_WPTR ;

# 2309 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
eee :;

# 2311 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2311 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2311 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2314 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> real_size__8classdef = byte_offset ;

# 2316 "/home/claude/cfront-3/src/dcl4.cpp"
for(__1b = __0this -> baselist__8classdef ;__1b ;__1b = __1b -> next__6basecl ) { 
# 2317 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1b -> base__4node != 77 )
# 2318 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;
{ Pclass __2bcl ;

# 2319 "/home/claude/cfront-3/src/dcl4.cpp"
__2bcl = __1b -> bclass__6basecl ;

# 2322 "/home/claude/cfront-3/src/dcl4.cpp"
link_compat_hack = 0 ;
if (__1b -> obj_offset__6basecl = has_allocated_base__8classdefFP8classdefUc ( __0this , __2bcl , (unsigned char )0 ) )
# 2324 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 2327 "/home/claude/cfront-3/src/dcl4.cpp"
{ int __2ba ;

# 2327 "/home/claude/cfront-3/src/dcl4.cpp"
__2ba = align__4typeFv ( (struct type *)__2bcl ) ;
if ((((int )__0this -> obj_align__8classdef ))< __2ba )
# 2329 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> obj_align__8classdef = __2ba ;
if (max_align < __2ba )
# 2331 "/home/claude/cfront-3/src/dcl4.cpp"
max_align = __2ba ;
{ int __2waste ;

# 2332 "/home/claude/cfront-3/src/dcl4.cpp"
__2waste = (byte_offset % __2ba );
if (__2waste )
# 2334 "/home/claude/cfront-3/src/dcl4.cpp"
byte_offset += (__2ba - __2waste );
__1b -> obj_offset__6basecl = byte_offset ;
__1b -> allocated__6basecl = (1 + link_compat_hack );
link_compat_hack = 0 ;

# 2339 "/home/claude/cfront-3/src/dcl4.cpp"
byte_offset += tsizeof__4typeFi ( (struct type *)__2bcl , 0 ) ;

# 2339 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2339 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2339 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2345 "/home/claude/cfront-3/src/dcl4.cpp"
if (byte_offset == 0 ){ 
# 2346 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2c ;

# 2346 "/home/claude/cfront-3/src/dcl4.cpp"
__2c = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'W' ) ) ;
__2c -> where__4name = __1cname -> where__4name ;
__2c -> __O1__4expr.tp = (struct type *)char_type ;
((void )dcl__4nameFP5tableUc ( __2c , __0this -> memtbl__8classdef , (unsigned char )0 ) );
__0this -> real_size__8classdef = (byte_offset = 1 );
}
if (byte_offset < SZ_STRUCT )
# 2353 "/home/claude/cfront-3/src/dcl4.cpp"
byte_offset = SZ_STRUCT ;
{ int __1waste ;

# 2354 "/home/claude/cfront-3/src/dcl4.cpp"
__1waste = (byte_offset % max_align );

# 2356 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1waste )
# 2357 "/home/claude/cfront-3/src/dcl4.cpp"
byte_offset += (max_align - __1waste );
__0this -> obj_size__8classdef = byte_offset ;
__0this -> obj_align__8classdef = max_align ;

# 2365 "/home/claude/cfront-3/src/dcl4.cpp"
if (all_virt__8classdefFP8classdefPCciUc ( __0this , __0this , (const char *)0 , 1 , (unsigned char )0 ) ){ 
# 2366 "/home/claude/cfront-3/src/dcl4.cpp"
if ((
# 2366 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_ctor__8classdef ) == 0 )
# 2367 "/home/claude/cfront-3/src/dcl4.cpp"
__1make_ctor = 1 ;
}
else if (__0this -> has_vvtab__8classdef )
# 2370 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCc ( (const char *)"virtualB: conflicting vtable initialization") ;

# 2375 "/home/claude/cfront-3/src/dcl4.cpp"
{ Pname __1hito ;

# 2376 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X243 ;

# 2376 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X244 ;

# 2376 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X245 ;

# 2376 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X246 ;

# 2376 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X247 ;

# 2376 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X248 ;

# 2376 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X249 ;

# 2376 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X250 ;

# 2376 "/home/claude/cfront-3/src/dcl4.cpp"
struct dcl_context *__0__X251 ;

# 2376 "/home/claude/cfront-3/src/dcl4.cpp"
struct dcl_context *__0__X252 ;

# 2375 "/home/claude/cfront-3/src/dcl4.cpp"
__1hito = ( __0this -> c_itor__8classdef ) ;

# 2377 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1hito )
# 2378 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> c_xref__8classdef |= 2;

# 2380 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__1hito == 0 )&& (__0this -> c_xref__8classdef & 11)){ 
# 2384 "/home/claude/cfront-3/src/dcl4.cpp"
__1hito = make_itor__8classdefFi ( __0this , 0 ) ;

# 2387 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> baselist__8classdef ){ 
# 2388 "/home/claude/cfront-3/src/dcl4.cpp"
int __3mc ;

# 2388 "/home/claude/cfront-3/src/dcl4.cpp"
__3mc = 1 ;
{ { Pbcl __3b ;

# 2389 "/home/claude/cfront-3/src/dcl4.cpp"
__3b = __0this -> baselist__8classdef ;

# 2389 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__3b ;__3b = __3b -> next__6basecl ) { 
# 2389 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__0__X238 ;

# 2390 "/home/claude/cfront-3/src/dcl4.cpp"
if (( (__0__X238 = __3b -> bclass__6basecl ), ( __0__X238 -> c_ctor__8classdef ) ) && (has_ictor__8classdefFv ( __3b -> bclass__6basecl ) ==
# 2390 "/home/claude/cfront-3/src/dcl4.cpp"
0 ))
# 2391 "/home/claude/cfront-3/src/dcl4.cpp"
__3mc = 0 ;
}
__1make_ctor = __3mc ;

# 2393 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2393 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
else 
# 2396 "/home/claude/cfront-3/src/dcl4.cpp"
__1make_ctor = 1 ;
}

# 2399 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__0this -> c_ctor__8classdef == 0 )&& (__1make_ctor == 0 )){ 
# 2400 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2btor ;
Pclass __2bc ;

# 2400 "/home/claude/cfront-3/src/dcl4.cpp"
__2btor = 0 ;
__2bc = 0 ;
{ { Pbcl __2b ;

# 2402 "/home/claude/cfront-3/src/dcl4.cpp"
__2b = __0this -> baselist__8classdef ;

# 2402 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__2b ;__2b = __2b -> next__6basecl ) { 
# 2403 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__2b -> base__4node ){ 
# 2404 "/home/claude/cfront-3/src/dcl4.cpp"
case 85 :
# 2405 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2406 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5c ;

# 2407 "/home/claude/cfront-3/src/dcl4.cpp"
struct classdef *__0__X239 ;

# 2406 "/home/claude/cfront-3/src/dcl4.cpp"
__5c = ( (__0__X239 = __2b -> bclass__6basecl ), ( __0__X239 -> c_ctor__8classdef ) ) ;
if (__5c == 0 )
# 2408 "/home/claude/cfront-3/src/dcl4.cpp"
break ;
if ((__5c -> n_scope__4name == 25 )&& (__2b == __0this -> baselist__8classdef )){ 
# 2410 "/home/claude/cfront-3/src/dcl4.cpp"
__2bc = __2b -> bclass__6basecl ;
__2btor = has_ictor__8classdefFv ( __2bc ) ;
break ;
}
}

# 2416 "/home/claude/cfront-3/src/dcl4.cpp"
case 77 :
# 2417 "/home/claude/cfront-3/src/dcl4.cpp"
__1make_ctor = 1 ;
goto zaza ;
}
}

# 2422 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2bc ){ 
# 2423 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2btor )
# 2424 "/home/claude/cfront-3/src/dcl4.cpp"
__1make_ctor = 1 ;
else 
# 2426 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2426 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V206 ;

# 2426 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V207 ;

# 2426 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"K needed for%t, BC%t hasK", (const struct ea *)( ((& __0__V206 )-> __O1__2ea.p =
# 2426 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__0this )), (& __0__V206 )) , (const struct ea *)( ((& __0__V207 )-> __O1__2ea.p = ((const void
# 2426 "/home/claude/cfront-3/src/dcl4.cpp"
*)__2bc )), (& __0__V207 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
zaza :;

# 2428 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2428 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2431 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1make_ctor && (__1ct == 0 )){ 
# 2433 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2n ;
Pfct __2f ;

# 2435 "/home/claude/cfront-3/src/dcl4.cpp"
register struct block *__0__X240 ;

# 2435 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X241 ;

# 2435 "/home/claude/cfront-3/src/dcl4.cpp"
struct loc __2__X242 ;

# 2433 "/home/claude/cfront-3/src/dcl4.cpp"
__2n = __ct__4nameFPCc ( (struct name *)0 , __0this -> string__8classdef ) ;
__2f = __ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)defa_type , (struct name *)0 , (unsigned char )1 ) ;
__2f -> f_inline__3fct = 1 ;
__2f -> f_is_inline__3fct = 1 ;
__2n -> __O1__4expr.tp = (struct type *)__2f ;
__2n -> n_oper__4name = 123 ;
__1ct = dcl__4nameFP5tableUc ( __2n , __0this -> memtbl__8classdef , (unsigned char )25 ) ;
( (__2n ?(((void )(__2n ?(((void )( ( ((((struct expr *)__2n ))?(((void )((((struct expr *)__2n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 2440 "/home/claude/cfront-3/src/dcl4.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__2n , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
(((struct fct *)(((struct fct *)__1ct -> __O1__4expr.tp ))))-> body__3fct = ( (__0__X240 = 0 ), ( (__2__X241 = curloc ), ( (__2__X242 = noloc ),
# 2441 "/home/claude/cfront-3/src/dcl4.cpp"
( ((__0__X240 || (__0__X240 = (struct block *)__nw__4stmtSFUl ( (unsigned long )(sizeof (struct block))) ))?(((void )( (__0__X240 = (struct block *)__ct__4stmtFUc3locP4stmt (
# 2441 "/home/claude/cfront-3/src/dcl4.cpp"
((struct stmt *)__0__X240 ), (unsigned char )116 , __2__X241 , ((struct stmt *)0 )) ), ( (__0__X240 -> __O1__4stmt.d = ((struct name *)0 )),
# 2441 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X240 -> __O3__4stmt.where2 = __2__X242 )) ) )):(((void )0 ))), __0__X240 ) ) ) ) ;
}

# 2445 "/home/claude/cfront-3/src/dcl4.cpp"
if ((((pt_opt && (! __0this -> nested_sig__4type ))&& (! __0this -> local_sig__4type ))&& (! is_probably_temp__FPCc ( __0this -> string__8classdef ) ))&& (!
# 2445 "/home/claude/cfront-3/src/dcl4.cpp"
tempdcl ))
# 2447 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> csu__8classdef == 36 )
# 2448 "/home/claude/cfront-3/src/dcl4.cpp"
fprintf ( pt_file , (const char *)"u %s %s\n", __0this -> string__8classdef ,
# 2448 "/home/claude/cfront-3/src/dcl4.cpp"
curr_filename__Fv ( ) ) ;
else if (__0this -> csu__8classdef == 32 ){ 
# 2450 "/home/claude/cfront-3/src/dcl4.cpp"
fprintf ( pt_file , (const char *)"s %s %s\n",
# 2450 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> string__8classdef , curr_filename__Fv ( ) ) ;
}
else if (__0this -> csu__8classdef == 6 )
# 2453 "/home/claude/cfront-3/src/dcl4.cpp"
fprintf ( pt_file , (const char *)"c %s %s\n", __0this ->
# 2453 "/home/claude/cfront-3/src/dcl4.cpp"
string__8classdef , curr_filename__Fv ( ) ) ;

# 2464 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> defined__4type |= 01 ;
typedef_checkall__FP8classdef ( __0this ) ;

# 2470 "/home/claude/cfront-3/src/dcl4.cpp"
for(__1p = ( (__0__X243 = __0this -> memtbl__8classdef ), ( (__2__X244 = (__1i = 1 )), ( (((__2__X244 <= 0 )|| (__0__X243 -> free_slot__5table <=
# 2470 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X244 ))?(((struct name *)0 )):(__0__X243 -> entries__5table [__2__X244 ]))) ) ) ;__1p ;__1p = (__1p -> n_tbl_list__4name ?__1p -> n_tbl_list__4name :( (__0__X245 = __0this -> memtbl__8classdef ), ( (__2__X246 =
# 2470 "/home/claude/cfront-3/src/dcl4.cpp"
(++ __1i )), ( (((__2__X246 <= 0 )|| (__0__X245 -> free_slot__5table <= __2__X246 ))?(((struct name *)0 )):(__0__X245 -> entries__5table [__2__X246 ]))) ) ) )) {
# 2470 "/home/claude/cfront-3/src/dcl4.cpp"

# 2471 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p -> base__4node == 123 )continue ;
{ Pfct __2f ;

# 2472 "/home/claude/cfront-3/src/dcl4.cpp"
__2f = (((struct fct *)(((struct fct *)__1p -> __O1__4expr.tp ))));
if (__2f == 0 )
# 2474 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 2476 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__2f -> base__4node ){ 
# 2477 "/home/claude/cfront-3/src/dcl4.cpp"
case 108 :
# 2479 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1hito && __2f -> argtype__3fct )
# 2480 "/home/claude/cfront-3/src/dcl4.cpp"
fix_args__FP3fctP8classdef ( __2f , __0this ) ;
if (__1p -> n_oper__4name == 161 )
# 2482 "/home/claude/cfront-3/src/dcl4.cpp"
__2f -> s_returns__3fct = __0this -> this_type__8classdef ;
if (__2f -> body__3fct )
# 2484 "/home/claude/cfront-3/src/dcl4.cpp"
__1p -> n_sto__4name = 31 ;
break ;
case 76 :
# 2487 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2488 "/home/claude/cfront-3/src/dcl4.cpp"
Pgen __4g ;

# 2488 "/home/claude/cfront-3/src/dcl4.cpp"
__4g = (((struct gen *)(((struct gen *)__2f ))));
{ { Plist __4gl ;

# 2489 "/home/claude/cfront-3/src/dcl4.cpp"
__4gl = __4g -> fct_list__3gen ;

# 2489 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) { 
# 2490 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5n ;
Pfct __5f ;

# 2490 "/home/claude/cfront-3/src/dcl4.cpp"
__5n = __4gl -> f__9name_list ;
__5f = (((struct fct *)(((struct fct *)__5n -> __O1__4expr.tp ))));

# 2493 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1hito && __5f -> argtype__3fct )
# 2494 "/home/claude/cfront-3/src/dcl4.cpp"
fix_args__FP3fctP8classdef ( __5f , __0this ) ;
if (__5n -> n_oper__4name == 161 )
# 2496 "/home/claude/cfront-3/src/dcl4.cpp"
__5f -> s_returns__3fct = __0this -> this_type__8classdef ;
if (__5f -> body__3fct )
# 2498 "/home/claude/cfront-3/src/dcl4.cpp"
__5n -> n_sto__4name = 31 ;
}

# 2499 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2499 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}

# 2501 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2505 "/home/claude/cfront-3/src/dcl4.cpp"
for(__1p = ( (__0__X247 = __0this -> memtbl__8classdef ), ( (__2__X248 = (__1i = 1 )), ( (((__2__X248 <= 0 )|| (__0__X247 -> free_slot__5table <=
# 2505 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X248 ))?(((struct name *)0 )):(__0__X247 -> entries__5table [__2__X248 ]))) ) ) ;__1p ;__1p = (__1p -> n_tbl_list__4name ?__1p -> n_tbl_list__4name :( (__0__X249 = __0this -> memtbl__8classdef ), ( (__2__X250 =
# 2505 "/home/claude/cfront-3/src/dcl4.cpp"
(++ __1i )), ( (((__2__X250 <= 0 )|| (__0__X249 -> free_slot__5table <= __2__X250 ))?(((struct name *)0 )):(__0__X249 -> entries__5table [__2__X250 ]))) ) ) )) {
# 2505 "/home/claude/cfront-3/src/dcl4.cpp"

# 2506 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p -> base__4node == 123 )continue ;
{ Pfct __2f ;

# 2507 "/home/claude/cfront-3/src/dcl4.cpp"
__2f = (((struct fct *)(((struct fct *)__1p -> __O1__4expr.tp ))));
if (__2f == 0 )
# 2509 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 2511 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__2f -> base__4node ){ 
# 2512 "/home/claude/cfront-3/src/dcl4.cpp"
case 108 :
# 2513 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2f -> body__3fct ){ 
# 2514 "/home/claude/cfront-3/src/dcl4.cpp"
dcl__3fctFP4name ( __2f , __1p ) ;
simpl__4nameFv ( __1p ) ;
}
break ;
case 76 :
# 2519 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2520 "/home/claude/cfront-3/src/dcl4.cpp"
Pgen __4g ;

# 2520 "/home/claude/cfront-3/src/dcl4.cpp"
__4g = (((struct gen *)(((struct gen *)__2f ))));
{ { Plist __4gl ;

# 2521 "/home/claude/cfront-3/src/dcl4.cpp"
__4gl = __4g -> fct_list__3gen ;

# 2521 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) { 
# 2522 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5n ;
Pfct __5f ;

# 2522 "/home/claude/cfront-3/src/dcl4.cpp"
__5n = __4gl -> f__9name_list ;
__5f = (((struct fct *)(((struct fct *)__5n -> __O1__4expr.tp ))));

# 2525 "/home/claude/cfront-3/src/dcl4.cpp"
if (__5f -> body__3fct ){ 
# 2526 "/home/claude/cfront-3/src/dcl4.cpp"
dcl__3fctFP4name ( __5f , __5n ) ;
simpl__4nameFv ( __5n ) ;
}
}

# 2529 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2529 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}

# 2531 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2534 "/home/claude/cfront-3/src/dcl4.cpp"
byte_offset = __1byte_old ;
bit_offset = __1bit_old ;
max_align = __1max_old ;

# 2538 "/home/claude/cfront-3/src/dcl4.cpp"
( ( (cc -- ), (((void )0 ))) ) ;

# 2543 "/home/claude/cfront-3/src/dcl4.cpp"
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 2543 "/home/claude/cfront-3/src/dcl4.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;
cc -> cot__11dcl_context = 0 ;

# 2544 "/home/claude/cfront-3/src/dcl4.cpp"
cc -> not4__11dcl_context = 0 ;

# 2544 "/home/claude/cfront-3/src/dcl4.cpp"
cc -> tot__11dcl_context = 0 ;

# 2544 "/home/claude/cfront-3/src/dcl4.cpp"
cc -> c_this__11dcl_context = 0 ;
{ Plist __1fl ;

# 2546 "/home/claude/cfront-3/src/dcl4.cpp"
struct dcl_context *__0__X253 ;

# 2545 "/home/claude/cfront-3/src/dcl4.cpp"
__1fl = __0this -> friend_list__8classdef ;
for(;__1fl ;__1fl = __1fl -> l__9name_list ) { 
# 2547 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2p ;
Pfct __2f ;

# 2547 "/home/claude/cfront-3/src/dcl4.cpp"
__2p = __1fl -> f__9name_list ;
__2f = (((struct fct *)(((struct fct *)__2p -> __O1__4expr.tp ))));

# 2550 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__2f -> base__4node ){ 
# 2551 "/home/claude/cfront-3/src/dcl4.cpp"
case 108 :
# 2552 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1hito && __2f -> argtype__3fct )
# 2553 "/home/claude/cfront-3/src/dcl4.cpp"
fix_args__FP3fctP8classdef ( __2f , __0this ) ;
if (__2f -> body__3fct && ((__2f -> defined__4type & 3)== 0 ))
# 2555 "/home/claude/cfront-3/src/dcl4.cpp"
__2p -> n_sto__4name = 31 ;
else if (__2p -> n_scope__4name == 31 )
# 2557 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2557 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V208 ;

# 2557 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V209 ;

# 2557 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( strict_opt ?0 :119, (const char *)"static%n declared friend toC%t", (const struct ea *)( ((& __0__V208 )->
# 2557 "/home/claude/cfront-3/src/dcl4.cpp"
__O1__2ea.p = ((const void *)__2p )), (& __0__V208 )) , (const struct ea *)( ((& __0__V209 )-> __O1__2ea.p = ((const
# 2557 "/home/claude/cfront-3/src/dcl4.cpp"
void *)__0this )), (& __0__V209 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} break ;
case 76 :
# 2560 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2561 "/home/claude/cfront-3/src/dcl4.cpp"
Pgen __4g ;

# 2561 "/home/claude/cfront-3/src/dcl4.cpp"
__4g = (((struct gen *)(((struct gen *)__2f ))));
{ { Plist __4gl ;

# 2562 "/home/claude/cfront-3/src/dcl4.cpp"
__4gl = __4g -> fct_list__3gen ;

# 2562 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) { 
# 2563 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5n ;
Pfct __5f ;

# 2563 "/home/claude/cfront-3/src/dcl4.cpp"
__5n = __4gl -> f__9name_list ;
__5f = (((struct fct *)(((struct fct *)__5n -> __O1__4expr.tp ))));

# 2566 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1hito && __5f -> argtype__3fct )
# 2567 "/home/claude/cfront-3/src/dcl4.cpp"
fix_args__FP3fctP8classdef ( __5f , __0this ) ;
if (__5f -> body__3fct && ((__5f -> defined__4type & 3)== 0 ))
# 2569 "/home/claude/cfront-3/src/dcl4.cpp"
__5n -> n_sto__4name = 31 ;
else if (__2p -> n_scope__4name == 31 )
# 2571 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2571 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V210 ;

# 2571 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V211 ;

# 2571 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiPCcRC2eaN33 ( strict_opt ?0 :119, (const char *)"static%n declared friend toC%t", (const struct ea *)( ((& __0__V210 )->
# 2571 "/home/claude/cfront-3/src/dcl4.cpp"
__O1__2ea.p = ((const void *)__2p )), (& __0__V210 )) , (const struct ea *)( ((& __0__V211 )-> __O1__2ea.p = ((const
# 2571 "/home/claude/cfront-3/src/dcl4.cpp"
void *)__0this )), (& __0__V211 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 2572 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2572 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}
}

# 2578 "/home/claude/cfront-3/src/dcl4.cpp"
simpl_friend = 0 ;
for(__1fl = __0this -> friend_list__8classdef ;__1fl ;__1fl = __1fl -> l__9name_list ) { 
# 2580 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2p ;
Pfct __2f ;

# 2580 "/home/claude/cfront-3/src/dcl4.cpp"
__2p = __1fl -> f__9name_list ;
__2f = (((struct fct *)(((struct fct *)__2p -> __O1__4expr.tp ))));
simpl_friend = 1 ;

# 2584 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__2f -> base__4node ){ 
# 2585 "/home/claude/cfront-3/src/dcl4.cpp"
case 108 :
# 2586 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2f -> body__3fct && ((__2f -> defined__4type & 3)== 0 )){ 
# 2587 "/home/claude/cfront-3/src/dcl4.cpp"
dcl__3fctFP4name ( __2f , __2p )
# 2587 "/home/claude/cfront-3/src/dcl4.cpp"
;
simpl__4nameFv ( __2p ) ;
}
break ;
case 76 :
# 2592 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2593 "/home/claude/cfront-3/src/dcl4.cpp"
Pgen __4g ;

# 2593 "/home/claude/cfront-3/src/dcl4.cpp"
__4g = (((struct gen *)(((struct gen *)__2f ))));
{ { Plist __4gl ;

# 2594 "/home/claude/cfront-3/src/dcl4.cpp"
__4gl = __4g -> fct_list__3gen ;

# 2594 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) { 
# 2595 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5n ;
Pfct __5f ;

# 2595 "/home/claude/cfront-3/src/dcl4.cpp"
__5n = __4gl -> f__9name_list ;
__5f = (((struct fct *)(((struct fct *)__5n -> __O1__4expr.tp ))));

# 2598 "/home/claude/cfront-3/src/dcl4.cpp"
if (__5f -> body__3fct && ((__5f -> defined__4type & 3)== 0 )){ 
# 2599 "/home/claude/cfront-3/src/dcl4.cpp"
dcl__3fctFP4name ( __5f , __5n ) ;
simpl__4nameFv ( __5n ) ;
}
}

# 2602 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2602 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}
}
simpl_friend = 0 ;
( ( (cc -- ), (((void )0 ))) ) ;

# 2609 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1tbl != gtbl )
# 2610 "/home/claude/cfront-3/src/dcl4.cpp"
simpl__8classdefFv ( __0this ) ;

# 2617 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__0this -> defined__4type & 010 )!= 0 )
# 2618 "/home/claude/cfront-3/src/dcl4.cpp"
dcl_print__8classdefFP4name ( __0this , (struct name *)0 ) ;

# 2620 "/home/claude/cfront-3/src/dcl4.cpp"
if (debug_opt ){ 
# 2621 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> nested_sig__4type ){ 
# 2622 "/home/claude/cfront-3/src/dcl4.cpp"
prnt_all_in_scope__FP8classdef ( __0this -> in_class__4type ) ;
}
{ 
# 2625 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> in_fct__4type || (! __0this -> in_class__4type ))
# 2626 "/home/claude/cfront-3/src/dcl4.cpp"
dump_func__FP8classdef ( __0this ) ;

# 2626 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2629 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2630 "/home/claude/cfront-3/src/dcl4.cpp"
if (! __0this -> in_class__4type )
# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
check_abst__FP8classdef ( __0this ) ;

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2631 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 234 "/home/claude/cfront-3/src/cfront.h"

# 2634 "/home/claude/cfront-3/src/dcl4.cpp"
void dump_func__FP8classdef (Pclass __1th );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 2634 "/home/claude/cfront-3/src/dcl4.cpp"
void dump_func__FP8classdef (Pclass __1th )
# 2635 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2636 "/home/claude/cfront-3/src/dcl4.cpp"
int __1i ;
{ { Pname __1p ;

# 2638 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X256 ;

# 2638 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X257 ;

# 2638 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X258 ;

# 2638 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X259 ;

# 2637 "/home/claude/cfront-3/src/dcl4.cpp"
__1p = ( (__0__X258 = __1th -> memtbl__8classdef ), ( (__2__X259 = (__1i = 1 )), ( (((__2__X259 <= 0 )|| (__0__X258 -> free_slot__5table <=
# 2637 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X259 ))?(((struct name *)0 )):(__0__X258 -> entries__5table [__2__X259 ]))) ) ) ;

# 2637 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1p ;__1p = (__1p -> n_tbl_list__4name ?__1p -> n_tbl_list__4name :( (__0__X256 = __1th -> memtbl__8classdef ), ( (__2__X257 = (++ __1i )), ( (((__2__X257 <= 0 )||
# 2637 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X256 -> free_slot__5table <= __2__X257 ))?(((struct name *)0 )):(__0__X256 -> entries__5table [__2__X257 ]))) ) ) )) { 
# 2638 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__1p -> base__4node == 123 )|| (!
# 2638 "/home/claude/cfront-3/src/dcl4.cpp"
__1p -> __O1__4expr.tp ))continue ;
{ Ptype __2t ;

# 2639 "/home/claude/cfront-3/src/dcl4.cpp"
__2t = skiptypedefs__4typeFv ( __1p -> __O1__4expr.tp ) ;
if (__2t -> base__4node == 6 ){ 
# 2641 "/home/claude/cfront-3/src/dcl4.cpp"
dump_func__FP8classdef ( ((struct classdef *)(((struct classdef *)__2t )))) ;
continue ;
}
{ Pfct __2f ;

# 2644 "/home/claude/cfront-3/src/dcl4.cpp"
__2f = (((struct fct *)(((struct fct *)__2t ))));
if (__2f == 0 )
# 2646 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;

# 2648 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__2f -> base__4node ){ 
# 2649 "/home/claude/cfront-3/src/dcl4.cpp"
case 108 :
# 2650 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2f -> body__3fct ){ 
# 2651 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1th -> c_body__8classdef == 1 ){ 
# 2652 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1th -> class_base__8classdef ==
# 2652 "/home/claude/cfront-3/src/dcl4.cpp"
4)
# 2653 "/home/claude/cfront-3/src/dcl4.cpp"
current_instantiation = __1th ;
dcl_print__8classdefFP4name ( __1th , (struct name *)0 ) ;
if (__1th -> class_base__8classdef == 4)
# 2656 "/home/claude/cfront-3/src/dcl4.cpp"
current_instantiation = 0 ;
}
dcl_print__4nameFUc ( __1p , (unsigned char )0 ) ;
}
break ;
case 76 :
# 2662 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2663 "/home/claude/cfront-3/src/dcl4.cpp"
Pgen __4g ;

# 2663 "/home/claude/cfront-3/src/dcl4.cpp"
__4g = (((struct gen *)(((struct gen *)__2f ))));
{ { Plist __4gl ;

# 2664 "/home/claude/cfront-3/src/dcl4.cpp"
__4gl = __4g -> fct_list__3gen ;

# 2664 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) { 
# 2665 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5n ;
Pfct __5f ;

# 2665 "/home/claude/cfront-3/src/dcl4.cpp"
__5n = __4gl -> f__9name_list ;
__5f = (((struct fct *)(((struct fct *)__5n -> __O1__4expr.tp ))));
if (__5f -> body__3fct ){ 
# 2668 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1th -> c_body__8classdef == 1 ){ 
# 2669 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1th -> class_base__8classdef == 4)
# 2670 "/home/claude/cfront-3/src/dcl4.cpp"
current_instantiation = __1th ;
dcl_print__8classdefFP4name ( __1th , (struct name *)0 ) ;
if (__1th -> class_base__8classdef == 4)
# 2673 "/home/claude/cfront-3/src/dcl4.cpp"
current_instantiation = 0 ;
}
dcl_print__4nameFUc ( __1p , (unsigned char )0 ) ;
}
}

# 2677 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2677 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}

# 2679 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2679 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2682 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Plist __1fl ;

# 2682 "/home/claude/cfront-3/src/dcl4.cpp"
__1fl = __1th -> friend_list__8classdef ;

# 2682 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1fl ;__1fl = __1fl -> l__9name_list ) { 
# 2683 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2p ;
Pfct __2f ;

# 2683 "/home/claude/cfront-3/src/dcl4.cpp"
__2p = __1fl -> f__9name_list ;
__2f = (((struct fct *)(((struct fct *)__2p -> __O1__4expr.tp ))));

# 2686 "/home/claude/cfront-3/src/dcl4.cpp"
switch (__2f -> base__4node ){ 
# 2687 "/home/claude/cfront-3/src/dcl4.cpp"
case 108 :
# 2688 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2f -> body__3fct && ((__2f -> defined__4type & 3)== 0 ))
# 2689 "/home/claude/cfront-3/src/dcl4.cpp"
dcl_print__4nameFUc ( __2p , (unsigned char
# 2689 "/home/claude/cfront-3/src/dcl4.cpp"
)0 ) ;
break ;
case 76 :
# 2692 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2693 "/home/claude/cfront-3/src/dcl4.cpp"
Pgen __4g ;

# 2693 "/home/claude/cfront-3/src/dcl4.cpp"
__4g = (((struct gen *)(((struct gen *)__2f ))));
{ { Plist __4gl ;

# 2694 "/home/claude/cfront-3/src/dcl4.cpp"
__4gl = __4g -> fct_list__3gen ;

# 2694 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) { 
# 2695 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __5n ;
Pfct __5f ;

# 2695 "/home/claude/cfront-3/src/dcl4.cpp"
__5n = __4gl -> f__9name_list ;
__5f = (((struct fct *)(((struct fct *)__5n -> __O1__4expr.tp ))));

# 2698 "/home/claude/cfront-3/src/dcl4.cpp"
if (__5f -> body__3fct && ((__5f -> defined__4type & 3)== 0 ))
# 2699 "/home/claude/cfront-3/src/dcl4.cpp"
dcl_print__4nameFUc ( __2p , (unsigned char )0 ) ;
}

# 2700 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2700 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}
}

# 2703 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2703 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2703 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2703 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 234 "/home/claude/cfront-3/src/cfront.h"

# 2706 "/home/claude/cfront-3/src/dcl4.cpp"
void check_abst__FP8classdef (Pclass __1th );

# 2717 "/home/claude/cfront-3/src/dcl4.cpp"
extern void check_abst_func__FP4nameP3fct (Pname , Pfct );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 2706 "/home/claude/cfront-3/src/dcl4.cpp"
void check_abst__FP8classdef (Pclass __1th )
# 2707 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2708 "/home/claude/cfront-3/src/dcl4.cpp"
int __1i ;
{ { Pname __1p ;

# 2710 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X260 ;

# 2710 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X261 ;

# 2710 "/home/claude/cfront-3/src/dcl4.cpp"
struct table *__0__X262 ;

# 2710 "/home/claude/cfront-3/src/dcl4.cpp"
int __2__X263 ;

# 2709 "/home/claude/cfront-3/src/dcl4.cpp"
__1p = ( (__0__X262 = __1th -> memtbl__8classdef ), ( (__2__X263 = (__1i = 1 )), ( (((__2__X263 <= 0 )|| (__0__X262 -> free_slot__5table <=
# 2709 "/home/claude/cfront-3/src/dcl4.cpp"
__2__X263 ))?(((struct name *)0 )):(__0__X262 -> entries__5table [__2__X263 ]))) ) ) ;

# 2709 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1p ;__1p = (__1p -> n_tbl_list__4name ?__1p -> n_tbl_list__4name :( (__0__X260 = __1th -> memtbl__8classdef ), ( (__2__X261 = (++ __1i )), ( (((__2__X261 <= 0 )||
# 2709 "/home/claude/cfront-3/src/dcl4.cpp"
(__0__X260 -> free_slot__5table <= __2__X261 ))?(((struct name *)0 )):(__0__X260 -> entries__5table [__2__X261 ]))) ) ) )) { 
# 2710 "/home/claude/cfront-3/src/dcl4.cpp"
if ((__1p -> base__4node == 123 )|| (!
# 2710 "/home/claude/cfront-3/src/dcl4.cpp"
__1p -> __O1__4expr.tp ))continue ;
{ Ptype __2t ;

# 2711 "/home/claude/cfront-3/src/dcl4.cpp"
__2t = skiptypedefs__4typeFv ( __1p -> __O1__4expr.tp ) ;
if (__2t -> base__4node == 6 ){ 
# 2713 "/home/claude/cfront-3/src/dcl4.cpp"
check_abst__FP8classdef ( ((struct classdef *)(((struct classdef *)__2t )))) ;
continue ;
}
{ Pfct __2f ;

# 2716 "/home/claude/cfront-3/src/dcl4.cpp"
__2f = (((struct fct *)(((struct fct *)__2t ))));

# 2718 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2f == 0 )
# 2719 "/home/claude/cfront-3/src/dcl4.cpp"
continue ;
switch (__2f -> base__4node ){ 
# 2721 "/home/claude/cfront-3/src/dcl4.cpp"
case 108 :
# 2722 "/home/claude/cfront-3/src/dcl4.cpp"
check_abst_func__FP4nameP3fct ( __1p , __2f ) ;
break ;
case 76 :{ 
# 2725 "/home/claude/cfront-3/src/dcl4.cpp"
Pgen __4g ;

# 2725 "/home/claude/cfront-3/src/dcl4.cpp"
__4g = (((struct gen *)(((struct gen *)__2f ))));
{ { Plist __4gl ;

# 2726 "/home/claude/cfront-3/src/dcl4.cpp"
__4gl = __4g -> fct_list__3gen ;

# 2726 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) { 
# 2727 "/home/claude/cfront-3/src/dcl4.cpp"
Pfct __5f ;

# 2727 "/home/claude/cfront-3/src/dcl4.cpp"
__5f = (((struct fct *)(((struct fct *)__4gl -> f__9name_list -> __O1__4expr.tp ))));
check_abst_func__FP4nameP3fct ( __4gl -> f__9name_list , __5f ) ;
}
break ;

# 2730 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2730 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
}

# 2732 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2732 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 2733 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2733 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2735 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 328 "/home/claude/cfront-3/src/cfront.h"
Pclass classtype__4typeFv (struct type *__0this );

# 2737 "/home/claude/cfront-3/src/dcl4.cpp"
void check_abst_func__FP4nameP3fct (Pname __1p , Pfct __1f )
# 2738 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2739 "/home/claude/cfront-3/src/dcl4.cpp"
if (is_cl_obj__4typeFv ( __1f -> returns__3fct ) ){ 
# 2740 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __2cl ;

# 2740 "/home/claude/cfront-3/src/dcl4.cpp"
__2cl = classtype__4typeFv ( skiptypedefs__4typeFv ( __1f -> returns__3fct ) ) ;
if (__2cl -> c_abstract__8classdef ){ 
# 2741 "/home/claude/cfront-3/src/dcl4.cpp"
const void *__2__X270 ;

# 2742 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2742 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V264 ;

# 2742 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __1p -> where__4name , (const char *)"abstractC%t cannot be used as aF returnT", (const struct ea *)(
# 2742 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V264 )-> __O1__2ea.p = ((const void *)__2cl )), (& __0__V264 )) , (const struct ea *)ea0 , (const struct
# 2742 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
{ 
# 2743 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V265 ;

# 2743 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V266 ;

# 2743 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'C' , & __1p -> where__4name , (const char *)"\t%a is a pure virtualF ofC%t\n", (const
# 2743 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea *)( (__2__X270 = (const void *)__2cl -> c_abstract__8classdef ), ( ((& __0__V265 )-> __O1__2ea.p = __2__X270 ), (& __0__V265 ))
# 2743 "/home/claude/cfront-3/src/dcl4.cpp"
) , (const struct ea *)( ((& __0__V266 )-> __O1__2ea.p = ((const void *)__2cl )), (& __0__V266 )) ,
# 2743 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} } }
}

# 2747 "/home/claude/cfront-3/src/dcl4.cpp"
{ { Pname __1a ;

# 2747 "/home/claude/cfront-3/src/dcl4.cpp"
__1a = __1f -> argtype__3fct ;

# 2747 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1a ;__1a = __1a -> __O1__4name.n_list ) { 
# 2748 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1a -> __O1__4expr.tp && is_cl_obj__4typeFv ( __1a -> __O1__4expr.tp ) ){ 
# 2749 "/home/claude/cfront-3/src/dcl4.cpp"
Pclass __3cl ;

# 2749 "/home/claude/cfront-3/src/dcl4.cpp"
__3cl = classtype__4typeFv ( skiptypedefs__4typeFv ( __1a -> __O1__4expr.tp ) ) ;
if (__3cl -> c_abstract__8classdef ){ 
# 2750 "/home/claude/cfront-3/src/dcl4.cpp"
const void *__2__X271 ;

# 2751 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2751 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V267 ;

# 2751 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __1p -> where__4name , (const char *)"abstractC%t cannot be used as anAT", (const struct ea *)(
# 2751 "/home/claude/cfront-3/src/dcl4.cpp"
((& __0__V267 )-> __O1__2ea.p = ((const void *)__3cl )), (& __0__V267 )) , (const struct ea *)ea0 , (const struct
# 2751 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
{ 
# 2752 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V268 ;

# 2752 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V269 ;

# 2752 "/home/claude/cfront-3/src/dcl4.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'C' , & __1p -> where__4name , (const char *)"\t%a is a pure virtualF ofC%t\n", (const
# 2752 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea *)( (__2__X271 = (const void *)__3cl -> c_abstract__8classdef ), ( ((& __0__V268 )-> __O1__2ea.p = __2__X271 ), (& __0__V268 ))
# 2752 "/home/claude/cfront-3/src/dcl4.cpp"
) , (const struct ea *)( ((& __0__V269 )-> __O1__2ea.p = ((const void *)__3cl )), (& __0__V269 )) ,
# 2752 "/home/claude/cfront-3/src/dcl4.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} } }
}
}

# 2755 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2755 "/home/claude/cfront-3/src/dcl4.cpp"
}
}

# 941 "/home/claude/cfront-3/src/cfront.h"
int no_of_names__4nameFv (struct name *__0this );

# 798 "/home/claude/cfront-3/src/cfront.h"
Pexpr typ__4exprFP5table (struct expr *__0this , Ptable );
long long eval__4exprFv (struct expr *__0this );

# 344 "/home/claude/cfront-3/src/cfront.h"
bit is_unsigned__4typeFv (struct type *__0this );

# 794 "/home/claude/cfront-3/src/cfront.h"
void del__4exprFv (struct expr *__0this );

# 2758 "/home/claude/cfront-3/src/dcl4.cpp"
void dcl__7enumdefFP4nameP5table (register struct enumdef *__0this , Pname __1n , Ptable __1tbl )
# 2759 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2760 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __1px ;
Pname __1p ;

# 2761 "/home/claude/cfront-3/src/dcl4.cpp"
__1p = __0this -> mem__7enumdef ;
;
{ Pbase __1b ;

# 2763 "/home/claude/cfront-3/src/dcl4.cpp"
__1b = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )121 , __1n ) ;
__1b -> b_const__4type = 1 ;

# 2766 "/home/claude/cfront-3/src/dcl4.cpp"
if (__0this -> local_sig__4type ){ 
# 2767 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> in_fct__4type = cc -> nof__11dcl_context ;
}
else 
# 2768 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> in_fct__4type = 0 ;

# 2771 "/home/claude/cfront-3/src/dcl4.cpp"
{ int __1enum_count ;

# 2771 "/home/claude/cfront-3/src/dcl4.cpp"
__1enum_count = 0 ;
__0this -> no_of_enumerators__7enumdef = no_of_names__4nameFv ( __0this -> mem__7enumdef ) ;
{ int __1largest ;

# 2773 "/home/claude/cfront-3/src/dcl4.cpp"
__1largest = 0 ;

# 2775 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p == 0 )
# 2776 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> mem__7enumdef = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )'e' ) )
# 2776 "/home/claude/cfront-3/src/dcl4.cpp"
;

# 2778 "/home/claude/cfront-3/src/dcl4.cpp"
for(;__1p ;__1p = __1px ) { 
# 2849 "/home/claude/cfront-3/src/dcl4.cpp"
Pname __2nn ;

# 2779 "/home/claude/cfront-3/src/dcl4.cpp"
__1px = __1p -> __O1__4name.n_list ;

# 2781 "/home/claude/cfront-3/src/dcl4.cpp"
if (__1p -> __O3__4expr.n_initializer ){ 
# 2782 "/home/claude/cfront-3/src/dcl4.cpp"
Pexpr __3i ;

# 2782 "/home/claude/cfront-3/src/dcl4.cpp"
__3i = typ__4exprFP5table ( __1p -> __O3__4expr.n_initializer , __1tbl ) ;
Neval = 0 ;
{ long long __3ii ;

# 2785 "/home/claude/cfront-3/src/dcl4.cpp"
const void *__2__X275 ;

# 2784 "/home/claude/cfront-3/src/dcl4.cpp"
__3ii = eval__4exprFv ( __3i ) ;

# 2787 "/home/claude/cfront-3/src/dcl4.cpp"
if (__3i -> __O1__4expr.tp ){ 
# 2788 "/home/claude/cfront-3/src/dcl4.cpp"
bit __4u ;
bit __4ok ;
int __4smallest_int ;

# 2788 "/home/claude/cfront-3/src/dcl4.cpp"
__4u = is_unsigned__4typeFv ( skiptypedefs__4typeFv ( __3i -> __O1__4expr.tp ) ) ;
__4ok = 0 ;
__4smallest_int = (- largest_int );
switch (skiptypedefs__4typeFv ( __3i -> __O1__4expr.tp ) -> base__4node ){ 
# 2794 "/home/claude/cfront-3/src/dcl4.cpp"
case 5 :
# 2795 "/home/claude/cfront-3/src/dcl4.cpp"
if (__4u )
# 2796 "/home/claude/cfront-3/src/dcl4.cpp"
{ __4ok = ((((unsigned char )__3ii ))<= largest_int );
# 2796 "/home/claude/cfront-3/src/dcl4.cpp"
}
else 
# 2798 "/home/claude/cfront-3/src/dcl4.cpp"
{ __4ok = (((((char )__3ii ))>= __4smallest_int )&& ((((char )__3ii ))<= largest_int ));

# 2798 "/home/claude/cfront-3/src/dcl4.cpp"
}
break ;
case 29 :
# 2801 "/home/claude/cfront-3/src/dcl4.cpp"
if (__4u )
# 2802 "/home/claude/cfront-3/src/dcl4.cpp"
{ __4ok = ((((unsigned short )__3ii ))<= largest_int );

# 2802 "/home/claude/cfront-3/src/dcl4.cpp"
}
else 
# 2804 "/home/claude/cfront-3/src/dcl4.cpp"
{ __4ok = (((((short )__3ii ))>= __4smallest_int )&& ((((short )__3ii ))<= largest_int ));

# 2804 "/home/claude/cfront-3/src/dcl4.cpp"
}
break ;
case 138 :
# 2807 "/home/claude/cfront-3/src/dcl4.cpp"
case 21 :
# 2808 "/home/claude/cfront-3/src/dcl4.cpp"
case 13 :
# 2809 "/home/claude/cfront-3/src/dcl4.cpp"
case 121 :
# 2810 "/home/claude/cfront-3/src/dcl4.cpp"
if (__4u )
# 2811 "/home/claude/cfront-3/src/dcl4.cpp"
{ __4ok = ((((unsigned int )__3ii ))<= largest_int );

# 2811 "/home/claude/cfront-3/src/dcl4.cpp"
}
else 
# 2813 "/home/claude/cfront-3/src/dcl4.cpp"
{ __4ok = (((((int )__3ii ))>= __4smallest_int )&& ((((int )__3ii ))<= largest_int ));

# 2813 "/home/claude/cfront-3/src/dcl4.cpp"
}
break ;
case 22 :
# 2816 "/home/claude/cfront-3/src/dcl4.cpp"
if (__4u )
# 2817 "/home/claude/cfront-3/src/dcl4.cpp"
{ __4ok = ((((unsigned long )__3ii ))<= largest_int );

# 2817 "/home/claude/cfront-3/src/dcl4.cpp"
}
else 
# 2819 "/home/claude/cfront-3/src/dcl4.cpp"
{ __4ok = (((((long )__3ii ))>= __4smallest_int )&& ((((long )__3ii ))<= largest_int ));

# 2819 "/home/claude/cfront-3/src/dcl4.cpp"
}
break ;
case 122 :
# 2822 "/home/claude/cfront-3/src/dcl4.cpp"
if (__4u )
# 2823 "/home/claude/cfront-3/src/dcl4.cpp"
{ __4ok = ((((unsigned long long )__3ii ))<= largest_int );

# 2823 "/home/claude/cfront-3/src/dcl4.cpp"
}
else 
# 2825 "/home/claude/cfront-3/src/dcl4.cpp"
{ __4ok = (((((long long )__3ii ))>= __4smallest_int )&& ((((long long )__3ii ))<= largest_int ));

# 2825 "/home/claude/cfront-3/src/dcl4.cpp"
}
break ;
default :
# 2830 "/home/claude/cfront-3/src/dcl4.cpp"
__4ok = 1 ;
break ;
}
if (! __4ok )
# 2834 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCc ( (const char *)"long enumerator") ;
}
__1enum_count = (((int )__3ii ));
if (Neval )
# 2838 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2838 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V272 ;

# 2838 "/home/claude/cfront-3/src/dcl4.cpp"
error__FP3locPCcRC2eaN33 ( & __1p -> where__4name , (const char *)"%s", (const struct ea *)(
# 2838 "/home/claude/cfront-3/src/dcl4.cpp"
(__2__X275 = (const void *)Neval ), ( ((& __0__V272 )-> __O1__2ea.p = __2__X275 ), (& __0__V272 )) ) , (const
# 2838 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__3i && (__3i -> permanent__4node == 0 ))del__4exprFv ( __3i ) ;
__1p -> __O3__4expr.n_initializer = 0 ;

# 2840 "/home/claude/cfront-3/src/dcl4.cpp"
}
}
__1p -> n_evaluated__4name = 1 ;
__1largest |= __1enum_count ;
if (((__1enum_count == largest_int )&& __1px )&& (! __1px -> __O3__4expr.n_initializer ))
# 2845 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCc ( (const char *)"enumerator too large")
# 2845 "/home/claude/cfront-3/src/dcl4.cpp"
;
__1p -> n_val__4name = (__1enum_count ++ );
__1p -> __O1__4expr.tp = (struct type *)__1b ;

# 2849 "/home/claude/cfront-3/src/dcl4.cpp"
;
if ((__1tbl == gtbl )|| __1tbl -> t_name__5table )
# 2851 "/home/claude/cfront-3/src/dcl4.cpp"
__2nn = look__5tableFPCcUc ( __1tbl , __1p -> __O2__4expr.string , (unsigned char )0 ) ;
else 
# 2853 "/home/claude/cfront-3/src/dcl4.cpp"
__2nn = look__5tableFPCcUc ( curr_block -> memtbl__4stmt , __1p -> __O2__4expr.string , (unsigned char )0 ) ;
if (__2nn && (((__1tbl == gtbl )|| __1tbl -> t_name__5table )|| ((__2nn -> __O4__4expr.n_table -> real_block__5table == curr_block -> memtbl__4stmt -> real_block__5table )&& (__2nn -> lex_level__4name ==
# 2854 "/home/claude/cfront-3/src/dcl4.cpp"
__1p -> lex_level__4name ))))
# 2862 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2863 "/home/claude/cfront-3/src/dcl4.cpp"
if (__2nn -> n_stclass__4name == 13 )
# 2864 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2864 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V273 ;

# 2864 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"enumerator%n declared twice", (const struct ea *)( ((& __0__V273 )-> __O1__2ea.p =
# 2864 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__2nn )), (& __0__V273 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2864 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} else 
# 2866 "/home/claude/cfront-3/src/dcl4.cpp"
{ 
# 2866 "/home/claude/cfront-3/src/dcl4.cpp"
struct ea __0__V274 ;

# 2866 "/home/claude/cfront-3/src/dcl4.cpp"
error__FPCcRC2eaN32 ( (const char *)"incompatibleDs of%n", (const struct ea *)( ((& __0__V274 )-> __O1__2ea.p =
# 2866 "/home/claude/cfront-3/src/dcl4.cpp"
((const void *)__2nn )), (& __0__V274 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2866 "/home/claude/cfront-3/src/dcl4.cpp"
ea *)ea0 ) ;
} }
else { 
# 2869 "/home/claude/cfront-3/src/dcl4.cpp"
__2nn = insert__5tableFP4nameUc ( __1tbl , __1p , (unsigned char )0 ) ;
__2nn -> n_stclass__4name = 13 ;
if (Eppp == 79 )
# 2872 "/home/claude/cfront-3/src/dcl4.cpp"
__2nn -> n_protect__4name = 79 ;
else if (Eppp == 25 )
# 2874 "/home/claude/cfront-3/src/dcl4.cpp"
__2nn -> n_scope__4name = 25 ;
}
__1p -> __O2__4expr.string = __2nn -> __O2__4expr.string ;
}

# 2879 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> e_type__7enumdef = int_type ;

# 2881 "/home/claude/cfront-3/src/dcl4.cpp"
__0this -> defined__4type |= 01 ;

# 2883 "/home/claude/cfront-3/src/dcl4.cpp"
if (((pt_opt && (! __0this -> nested_sig__4type ))&& (! __0this -> local_sig__4type ))&& (! is_probably_temp__FPCc ( __0this -> string__7enumdef ) ))
# 2884 "/home/claude/cfront-3/src/dcl4.cpp"
fprintf ( pt_file ,
# 2884 "/home/claude/cfront-3/src/dcl4.cpp"
(const char *)"e %s %s\n", __0this -> string__7enumdef , curr_filename__Fv ( ) ) ;

# 2884 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2884 "/home/claude/cfront-3/src/dcl4.cpp"
}

# 2884 "/home/claude/cfront-3/src/dcl4.cpp"
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

# 2885 "/home/claude/cfront-3/src/dcl4.cpp"

/* the end */
