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

# 362 "/home/claude/cfront-3/src/cfront.h"
void del__4typeFv (struct type *__0this );

# 794 "/home/claude/cfront-3/src/cfront.h"
void del__4exprFv (struct expr *__0this );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 24 "/home/claude/cfront-3/src/del.cpp"
void del__4nameFv (register struct name *__0this )
# 25 "/home/claude/cfront-3/src/del.cpp"
{ 
# 32 "/home/claude/cfront-3/src/del.cpp"
;
{ Pexpr __1i ;

# 33 "/home/claude/cfront-3/src/del.cpp"
__1i = __0this -> __O3__4expr.n_initializer ;

# 37 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O1__4expr.tp && (__0this -> __O1__4expr.tp -> permanent__4node == 0 ))del__4typeFv ( __0this -> __O1__4expr.tp ) ;
if (__1i && (__1i != (((struct expr *)1 ))))if (__1i && (__1i -> permanent__4node == 0 ))del__4exprFv ( __1i ) ;
( (__0this ?(((void )(__0this ?(((void )( ( ((((struct expr *)__0this ))?(((void )((((struct expr *)__0this ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 39 "/home/claude/cfront-3/src/del.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 39 "/home/claude/cfront-3/src/del.cpp"
}
}

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 631 "/home/claude/cfront-3/src/cfront.h"

# 652 "/home/claude/cfront-3/src/cfront.h"

# 691 "/home/claude/cfront-3/src/cfront.h"

# 697 "/home/claude/cfront-3/src/cfront.h"

# 706 "/home/claude/cfront-3/src/cfront.h"

# 712 "/home/claude/cfront-3/src/cfront.h"

# 42 "/home/claude/cfront-3/src/del.cpp"
void del__4typeFv (register struct type *__0this )
# 43 "/home/claude/cfront-3/src/del.cpp"
{ 
# 49 "/home/claude/cfront-3/src/del.cpp"
;

# 51 "/home/claude/cfront-3/src/del.cpp"
__0this -> permanent__4node = 3 ;
switch (__0this -> base__4node ){ 
# 52 "/home/claude/cfront-3/src/del.cpp"
unsigned long __2__X20 ;

# 53 "/home/claude/cfront-3/src/del.cpp"
case 123 :
# 54 "/home/claude/cfront-3/src/del.cpp"
case 85 :
# 55 "/home/claude/cfront-3/src/del.cpp"
{ 
# 55 "/home/claude/cfront-3/src/del.cpp"
struct ea __0__V17 ;

# 55 "/home/claude/cfront-3/src/del.cpp"
struct ea __0__V18 ;

# 55 "/home/claude/cfront-3/src/del.cpp"
struct ea __0__V19 ;

# 55 "/home/claude/cfront-3/src/del.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%d->T::del():N %s %d", (const struct ea *)( ((&
# 55 "/home/claude/cfront-3/src/del.cpp"
__0__V17 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V17 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V18 , (const
# 55 "/home/claude/cfront-3/src/del.cpp"
void *)(((struct name *)(((struct name *)__0this ))))-> __O2__4expr.string ) , (const struct ea *)( (__2__X20 = __0this -> base__4node ), ( ((
# 55 "/home/claude/cfront-3/src/del.cpp"
((& __0__V19 )-> __O1__2ea.i = __2__X20 ), 0 ) ), (& __0__V19 )) ) , (const struct ea *)ea0 ) ;
# 55 "/home/claude/cfront-3/src/del.cpp"

# 56 "/home/claude/cfront-3/src/del.cpp"
case 108 :
# 57 "/home/claude/cfront-3/src/del.cpp"
{ Pfct __3f ;

# 57 "/home/claude/cfront-3/src/del.cpp"
__3f = (((struct fct *)(((struct fct *)__0this ))));
if (__3f -> returns__3fct && (__3f -> returns__3fct -> permanent__4node == 0 ))del__4typeFv ( __3f -> returns__3fct ) ;
( (__3f ?(((void )(__3f ?(((void )(((void )__dl__3fctSFPvUl ( (void *)__3f , (unsigned long )(sizeof (struct fct))) )))):(((void )0 ))))):(((void )0 ))))
# 59 "/home/claude/cfront-3/src/del.cpp"
;
break ;
}
case 110 :
# 63 "/home/claude/cfront-3/src/del.cpp"
{ Pvec __3v ;

# 63 "/home/claude/cfront-3/src/del.cpp"
__3v = (((struct vec *)(((struct vec *)__0this ))));
if (__3v -> dim__3vec && (__3v -> dim__3vec -> permanent__4node == 0 ))del__4exprFv ( __3v -> dim__3vec ) ;
if (__3v -> typ__5pvtyp && (__3v -> typ__5pvtyp -> permanent__4node == 0 ))del__4typeFv ( __3v -> typ__5pvtyp ) ;
( (__3v ?(((void )(__3v ?(((void )(((void )__dl__3vecSFPvUl ( (void *)__3v , (unsigned long )(sizeof (struct vec))) )))):(((void )0 ))))):(((void )0 ))))
# 66 "/home/claude/cfront-3/src/del.cpp"
;
break ;
}
case 125 :
# 70 "/home/claude/cfront-3/src/del.cpp"
case 158 :
# 71 "/home/claude/cfront-3/src/del.cpp"
{ Pptr __3p ;

# 71 "/home/claude/cfront-3/src/del.cpp"
__3p = (((struct ptr *)(((struct ptr *)__0this ))));
if (__3p -> typ__5pvtyp && (__3p -> typ__5pvtyp -> permanent__4node == 0 ))del__4typeFv ( __3p -> typ__5pvtyp ) ;
( (__3p ?(((void )(__3p ?(((void )(((void )__dl__3ptrSFPvUl ( (void *)__3p , (unsigned long )(sizeof (struct ptr))) )))):(((void )0 ))))):(((void )0 ))))
# 73 "/home/claude/cfront-3/src/del.cpp"
;
break ;
}
} }
}

# 1 ""
extern void __dl__FPv (void *);

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 79 "/home/claude/cfront-3/src/del.cpp"
void del__4exprFv (register struct expr *__0this )
# 80 "/home/claude/cfront-3/src/del.cpp"
{ 
# 85 "/home/claude/cfront-3/src/del.cpp"
;

# 87 "/home/claude/cfront-3/src/del.cpp"
__0this -> permanent__4node = 3 ;
switch (__0this -> base__4node ){ 
# 89 "/home/claude/cfront-3/src/del.cpp"
case 150 :
# 90 "/home/claude/cfront-3/src/del.cpp"
if (__0this == one )return ;

# 92 "/home/claude/cfront-3/src/del.cpp"
case 34 :
# 93 "/home/claude/cfront-3/src/del.cpp"
case 82 :
# 94 "/home/claude/cfront-3/src/del.cpp"
case 83 :
# 95 "/home/claude/cfront-3/src/del.cpp"
case 84 :
# 96 "/home/claude/cfront-3/src/del.cpp"
case 81 :
# 97 "/home/claude/cfront-3/src/del.cpp"
case 165 :
# 98 "/home/claude/cfront-3/src/del.cpp"
goto dd ;
case 144 :
# 100 "/home/claude/cfront-3/src/del.cpp"
case 162 :
# 101 "/home/claude/cfront-3/src/del.cpp"
case 86 :
# 102 "/home/claude/cfront-3/src/del.cpp"
case 85 :
# 103 "/home/claude/cfront-3/src/del.cpp"
return ;
case 113 :
# 105 "/home/claude/cfront-3/src/del.cpp"
case 191 :
# 106 "/home/claude/cfront-3/src/del.cpp"
case 30 :
# 107 "/home/claude/cfront-3/src/del.cpp"
case 23 :
# 108 "/home/claude/cfront-3/src/del.cpp"
case 184 :
# 109 "/home/claude/cfront-3/src/del.cpp"
case 157 :
# 110 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O4__4expr.tp2 && (__0this -> __O4__4expr.tp2 -> permanent__4node == 0 ))del__4typeFv ( __0this ->
# 110 "/home/claude/cfront-3/src/del.cpp"
__O4__4expr.tp2 ) ;
break ;
case 44 :
# 113 "/home/claude/cfront-3/src/del.cpp"
case 45 :
# 114 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O2__4expr.e1 && (__0this -> __O2__4expr.e1 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O2__4expr.e1 ) ;
if (__0this -> __O3__4expr.e2 )if (__0this -> __O3__4expr.e2 && (__0this -> __O3__4expr.e2 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O3__4expr.e2 ) ;
case 177 :
# 117 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O4__4expr.mem && (__0this -> __O4__4expr.mem -> base__4node != 85 ))if (__0this -> __O4__4expr.mem && (__0this -> __O4__4expr.mem -> permanent__4node == 0 ))del__4exprFv (
# 117 "/home/claude/cfront-3/src/del.cpp"
__0this -> __O4__4expr.mem ) ;
if (__0this -> __O2__4expr.i1 == 5 )__dl__FPv ( (void *)__0this -> __O1__4expr.string4 ) ;
goto dd ;
case 68 :
# 121 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O4__4expr.cond && (__0this -> __O4__4expr.cond -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O4__4expr.cond ) ;
break ;
case 168 :
# 124 "/home/claude/cfront-3/src/del.cpp"
__vec_delete ( ((void *)__0this -> __O4__4expr.il -> i_args__5iline ), -1, sizeof (struct ia ), ((void *)0 ), 1, 0)
# 124 "/home/claude/cfront-3/src/del.cpp"
;
__dl__FPv ( (void *)__0this -> __O4__4expr.il ) ;
goto dd ;
case 140 :{ 
# 128 "/home/claude/cfront-3/src/del.cpp"
Pexpr __3tp ;

# 128 "/home/claude/cfront-3/src/del.cpp"
__3tp = __0this -> __O3__4expr.e2 ;
while ((__3tp && __3tp -> __O3__4expr.e2 )&& (__3tp -> __O3__4expr.e2 -> base__4node == 140 )){ 
# 130 "/home/claude/cfront-3/src/del.cpp"
Pexpr __4x ;

# 130 "/home/claude/cfront-3/src/del.cpp"
__4x = __3tp ;
if (__4x -> permanent__4node )break ;
__4x -> permanent__4node = 3 ;
__3tp = __3tp -> __O3__4expr.e2 ;
if (__4x -> __O2__4expr.e1 )if (__4x -> __O2__4expr.e1 && (__4x -> __O2__4expr.e1 -> permanent__4node == 0 ))del__4exprFv ( __4x -> __O2__4expr.e1 ) ;
( (__4x ?(((void )(__4x ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__4x , (unsigned long )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 135 "/home/claude/cfront-3/src/del.cpp"
;
}
__0this -> __O3__4expr.e2 = __3tp ;
break ;
}
}

# 142 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O2__4expr.e1 && (__0this -> __O2__4expr.e1 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O2__4expr.e1 ) ;
if (__0this -> __O3__4expr.e2 && (__0this -> __O3__4expr.e2 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O3__4expr.e2 ) ;
dd :
# 145 "/home/claude/cfront-3/src/del.cpp"
( (__0this ?(((void )(__0this ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 145 "/home/claude/cfront-3/src/del.cpp"
;
}

# 148 "/home/claude/cfront-3/src/del.cpp"
void del__4stmtFv (struct stmt *__0this );

# 235 "/home/claude/cfront-3/src/cfront.h"
void del__5tableFv (struct table *__0this );

# 1010 "/home/claude/cfront-3/src/cfront.h"

# 1025 "/home/claude/cfront-3/src/cfront.h"

# 148 "/home/claude/cfront-3/src/del.cpp"
void del__4stmtFv (register struct stmt *__0this )
# 149 "/home/claude/cfront-3/src/del.cpp"
{ 
# 154 "/home/claude/cfront-3/src/del.cpp"
;

# 156 "/home/claude/cfront-3/src/del.cpp"
__0this -> permanent__4node = 3 ;
switch (__0this -> base__4node ){ 
# 158 "/home/claude/cfront-3/src/del.cpp"
case 72 :
# 159 "/home/claude/cfront-3/src/del.cpp"
case 39 :
# 160 "/home/claude/cfront-3/src/del.cpp"
case 10 :
# 161 "/home/claude/cfront-3/src/del.cpp"
case 28 :
# 162 "/home/claude/cfront-3/src/del.cpp"
case 4 :
# 163 "/home/claude/cfront-3/src/del.cpp"
case 33 :
# 164 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O2__4stmt.e && (__0this -> __O2__4stmt.e ->
# 164 "/home/claude/cfront-3/src/del.cpp"
permanent__4node == 0 ))del__4exprFv ( __0this -> __O2__4stmt.e ) ;
break ;
case 166 :
# 167 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O2__4stmt.s2 && (__0this -> __O2__4stmt.s2 -> permanent__4node == 0 ))del__4stmtFv ( __0this -> __O2__4stmt.s2 ) ;
break ;
case 116 :
# 170 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O1__4stmt.d && (__0this -> __O1__4stmt.d -> permanent__4node == 0 ))del__4nameFv ( __0this -> __O1__4stmt.d ) ;
if (__0this -> s__4stmt && (__0this -> s__4stmt -> permanent__4node == 0 ))del__4stmtFv ( __0this -> s__4stmt ) ;
if (__0this -> __O2__4stmt.own_tbl )if (__0this -> memtbl__4stmt && (__0this -> memtbl__4stmt -> permanent__4node == 0 ))del__5tableFv ( __0this -> memtbl__4stmt ) ;
if (__0this -> s_list__4stmt && (__0this -> s_list__4stmt -> permanent__4node == 0 ))del__4stmtFv ( __0this -> s_list__4stmt ) ;
goto dd ;
case 16 :
# 176 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O2__4stmt.e && (__0this -> __O2__4stmt.e -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O2__4stmt.e ) ;
if (__0this -> __O1__4stmt.e2 && (__0this -> __O1__4stmt.e2 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O1__4stmt.e2 ) ;
if (__0this -> __O3__4stmt.for_init && (__0this -> __O3__4stmt.for_init -> permanent__4node == 0 ))del__4stmtFv ( __0this -> __O3__4stmt.for_init ) ;
break ;
case 20 :
# 181 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> __O2__4stmt.e && (__0this -> __O2__4stmt.e -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O2__4stmt.e ) ;
if (__0this -> __O3__4stmt.else_stmt && (__0this -> __O3__4stmt.else_stmt -> permanent__4node == 0 ))del__4stmtFv ( __0this -> __O3__4stmt.else_stmt ) ;
break ;
}

# 186 "/home/claude/cfront-3/src/del.cpp"
if (__0this -> s__4stmt && (__0this -> s__4stmt -> permanent__4node == 0 ))del__4stmtFv ( __0this -> s__4stmt ) ;
if (__0this -> s_list__4stmt && (__0this -> s_list__4stmt -> permanent__4node == 0 ))del__4stmtFv ( __0this -> s_list__4stmt ) ;
dd :
# 189 "/home/claude/cfront-3/src/del.cpp"
( (__0this ?(((void )(__0this ?(((void )(((void )__dl__4stmtSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct stmt))) )))):(((void )0 ))))):(((void )0 ))))
# 189 "/home/claude/cfront-3/src/del.cpp"
;
}

# 218 "/home/claude/cfront-3/src/cfront.h"

# 221 "/home/claude/cfront-3/src/cfront.h"
void __dt__5tableFv (struct table *__0this , int );

# 192 "/home/claude/cfront-3/src/del.cpp"
void del__5tableFv (register struct table *__0this )
# 193 "/home/claude/cfront-3/src/del.cpp"
{ 
# 196 "/home/claude/cfront-3/src/del.cpp"
{ { int __1i ;

# 196 "/home/claude/cfront-3/src/del.cpp"
__1i = 1 ;

# 196 "/home/claude/cfront-3/src/del.cpp"
for(;__1i < __0this -> free_slot__5table ;__1i ++ ) { 
# 197 "/home/claude/cfront-3/src/del.cpp"
Pname __2n ;

# 197 "/home/claude/cfront-3/src/del.cpp"
__2n = (__0this -> entries__5table [__1i ]);
if (__2n == 0 )error__FiPCc ( (int )'i' , (const char *)"table.del(0)") ;

# 201 "/home/claude/cfront-3/src/del.cpp"
;

# 205 "/home/claude/cfront-3/src/del.cpp"
if (__2n -> n_stclass__4name == 31 )continue ;
switch (__2n -> n_scope__4name ){ 
# 207 "/home/claude/cfront-3/src/del.cpp"
case 136 :
# 208 "/home/claude/cfront-3/src/del.cpp"
case 139 :
# 209 "/home/claude/cfront-3/src/del.cpp"
break ;
default :
# 211 "/home/claude/cfront-3/src/del.cpp"
{ const char *__4s ;

# 211 "/home/claude/cfront-3/src/del.cpp"
__4s = __2n -> __O2__4expr.string ;
if (__4s && ((((__4s [0 ])!= '_' )|| ((__4s [1 ])!= '_' ))|| ((__4s [2 ])!= 'X' )))__dl__FPv ( (void *)(((char *)__4s ))) ;

# 214 "/home/claude/cfront-3/src/del.cpp"
del__4nameFv ( __2n ) ;
}
}
}

# 220 "/home/claude/cfront-3/src/del.cpp"
__dt__5tableFv ( __0this , 3) ;

# 220 "/home/claude/cfront-3/src/del.cpp"
}

# 220 "/home/claude/cfront-3/src/del.cpp"
}
}

# 479 "/home/claude/cfront-3/src/cfront.h"
void really_print__8classdefFP4virt (struct classdef *__0this , Pvirt );

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 230 "/home/claude/cfront-3/src/del.cpp"
void delete_local__Fv (void )
# 231 "/home/claude/cfront-3/src/del.cpp"
{ 
# 234 "/home/claude/cfront-3/src/del.cpp"
;

# 236 "/home/claude/cfront-3/src/del.cpp"
do { 
# 237 "/home/claude/cfront-3/src/del.cpp"
{ { struct vl *__2v ;

# 237 "/home/claude/cfront-3/src/del.cpp"
__2v = vlist ;

# 237 "/home/claude/cfront-3/src/del.cpp"
for(;__2v ;__2v = __2v -> next__2vl ) really_print__8classdefFP4virt ( __2v -> cl__2vl , __2v -> vt__2vl ) ;
vlist = 0 ;

# 240 "/home/claude/cfront-3/src/del.cpp"
{ { Plist __2l ;

# 240 "/home/claude/cfront-3/src/del.cpp"
__2l = isf_list ;

# 240 "/home/claude/cfront-3/src/del.cpp"
for(;__2l ;__2l = __2l -> l__9name_list ) { 
# 241 "/home/claude/cfront-3/src/del.cpp"
Pname __3n ;
Pfct __3f ;

# 241 "/home/claude/cfront-3/src/del.cpp"
__3n = __2l -> f__9name_list ;
__3f = (((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))));

# 244 "/home/claude/cfront-3/src/del.cpp"
if (__3f == 0 ){ error__FiPCc ( (int )'d' , (const char *)"delete_local: f == 0") ;
# 244 "/home/claude/cfront-3/src/del.cpp"
break ;

# 244 "/home/claude/cfront-3/src/del.cpp"
}
if (__3f -> base__4node == 76 ){ 
# 246 "/home/claude/cfront-3/src/del.cpp"
__3n = (((struct gen *)(((struct gen *)__3f ))))-> fct_list__3gen -> f__9name_list ;
__3f = (((struct fct *)(((struct fct *)__3n -> __O1__4expr.tp ))));
}

# 250 "/home/claude/cfront-3/src/del.cpp"
if ((debug_opt == 0 )&& __3n -> n_addr_taken__4name ){ 
# 251 "/home/claude/cfront-3/src/del.cpp"
__3f -> f_inline__3fct = 0 ;
if (__3n -> n_dcl_printed__4name < 2 ){ 
# 253 "/home/claude/cfront-3/src/del.cpp"
if (warning_opt )
# 254 "/home/claude/cfront-3/src/del.cpp"
{ 
# 254 "/home/claude/cfront-3/src/del.cpp"
struct ea __0__V21 ;

# 254 "/home/claude/cfront-3/src/del.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"out-of-line copy of %n created", (const struct ea *)( ((&
# 254 "/home/claude/cfront-3/src/del.cpp"
__0__V21 )-> __O1__2ea.p = ((const void *)__3n )), (& __0__V21 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 254 "/home/claude/cfront-3/src/del.cpp"
(const struct ea *)ea0 ) ;
} dcl_print__4nameFUc ( __3n , (unsigned char )0 ) ;
}
}
}

# 258 "/home/claude/cfront-3/src/del.cpp"
}

# 258 "/home/claude/cfront-3/src/del.cpp"
}

# 258 "/home/claude/cfront-3/src/del.cpp"
}

# 258 "/home/claude/cfront-3/src/del.cpp"
}

# 260 "/home/claude/cfront-3/src/del.cpp"
}
while (vlist );
{ { Plist __1l ;

# 262 "/home/claude/cfront-3/src/del.cpp"
__1l = local_class ;

# 262 "/home/claude/cfront-3/src/del.cpp"
for(;__1l ;__1l = __1l -> l__9name_list ) 
# 263 "/home/claude/cfront-3/src/del.cpp"
{ 
# 264 "/home/claude/cfront-3/src/del.cpp"
Pname __2n ;

# 266 "/home/claude/cfront-3/src/del.cpp"
Pname __2nn ;
Pclass __2cl ;

# 264 "/home/claude/cfront-3/src/del.cpp"
__2n = __1l -> f__9name_list ;

# 266 "/home/claude/cfront-3/src/del.cpp"
__2nn = (((struct basetype *)(((struct basetype *)__2n -> __O1__4expr.tp ))))-> b_name__8basetype ;
__2cl = (((struct classdef *)(((struct classdef *)__2nn -> __O1__4expr.tp ))));
{ { Pname __2px ;

# 268 "/home/claude/cfront-3/src/del.cpp"
Pname __2p ;

# 268 "/home/claude/cfront-3/src/del.cpp"
__2p = __2cl -> mem_list__8classdef ;

# 268 "/home/claude/cfront-3/src/del.cpp"
for(;__2p ;__2p = __2px ) { 
# 269 "/home/claude/cfront-3/src/del.cpp"
__2px = __2p -> __O1__4name.n_list ;
if (__2p -> __O1__4expr.tp )
# 271 "/home/claude/cfront-3/src/del.cpp"
switch (__2p -> __O1__4expr.tp -> base__4node ){ 
# 272 "/home/claude/cfront-3/src/del.cpp"
case 108 :
# 273 "/home/claude/cfront-3/src/del.cpp"
{ Pfct __5f ;

# 273 "/home/claude/cfront-3/src/del.cpp"
__5f = (((struct fct *)(((struct fct *)__2p -> __O1__4expr.tp ))));
if (__5f -> body__3fct ){ 
# 275 "/home/claude/cfront-3/src/del.cpp"
if ((__5f -> f_inline__3fct == 0 )&& (__5f -> f_imeasure__3fct == 0 ))
# 276 "/home/claude/cfront-3/src/del.cpp"
{ 
# 278 "/home/claude/cfront-3/src/del.cpp"
if (ansi_opt && __5f -> f_this__3fct ){
# 278 "/home/claude/cfront-3/src/del.cpp"

# 279 "/home/claude/cfront-3/src/del.cpp"
__5f -> f_this__3fct -> __O4__4expr.n_table = 0 ;
{ { Pname __8n ;

# 280 "/home/claude/cfront-3/src/del.cpp"
__8n = __5f -> f_this__3fct -> __O1__4name.n_list ;

# 280 "/home/claude/cfront-3/src/del.cpp"
for(;__8n ;__8n = __8n -> __O1__4name.n_list ) 
# 281 "/home/claude/cfront-3/src/del.cpp"
__8n -> __O4__4expr.n_table = 0 ;

# 281 "/home/claude/cfront-3/src/del.cpp"
}

# 281 "/home/claude/cfront-3/src/del.cpp"
}
}

# 284 "/home/claude/cfront-3/src/del.cpp"
if (__5f -> body__3fct && (__5f -> body__3fct -> permanent__4node == 0 ))del__4stmtFv ( (struct stmt *)__5f -> body__3fct ) ;
__5f -> body__3fct = 0 ;
}
}
}
case 119 :
# 290 "/home/claude/cfront-3/src/del.cpp"
case 121 :
# 291 "/home/claude/cfront-3/src/del.cpp"
if (__2p && (__2p -> permanent__4node == 0 ))del__4nameFv ( __2p ) ;
break ;
case 6 :
# 294 "/home/claude/cfront-3/src/del.cpp"
case 13 :
# 295 "/home/claude/cfront-3/src/del.cpp"
break ;
default :
# 297 "/home/claude/cfront-3/src/del.cpp"
( (__2p ?(((void )(__2p ?(((void )( ( ((((struct expr *)__2p ))?(((void )((((struct expr *)__2p ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 ))))
# 297 "/home/claude/cfront-3/src/del.cpp"
, (((void )__dl__4nameSFPvUl ( (void *)__2p , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
# 297 "/home/claude/cfront-3/src/del.cpp"

# 298 "/home/claude/cfront-3/src/del.cpp"
}
else ( (__2p ?(((void )(__2p ?(((void )( ( ((((struct expr *)__2p ))?(((void )((((struct expr *)__2p ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 ))))
# 299 "/home/claude/cfront-3/src/del.cpp"
, (((void )__dl__4nameSFPvUl ( (void *)__2p , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
# 299 "/home/claude/cfront-3/src/del.cpp"

# 300 "/home/claude/cfront-3/src/del.cpp"
}
if (__2cl -> memtbl__8classdef && (__2cl -> memtbl__8classdef -> permanent__4node == 0 ))del__5tableFv ( __2cl -> memtbl__8classdef ) ;
__2cl -> mem_list__8classdef = 0 ;
__2cl -> permanent__4node = 3 ;
__2nn -> permanent__4node = 0 ;
if (__2nn && (__2nn -> permanent__4node == 0 ))del__4nameFv ( __2nn ) ;
__2n -> permanent__4node = 0 ;

# 308 "/home/claude/cfront-3/src/del.cpp"
if (__2n && (__2n -> permanent__4node == 0 ))del__4nameFv ( __2n ) ;

# 308 "/home/claude/cfront-3/src/del.cpp"
}

# 308 "/home/claude/cfront-3/src/del.cpp"
}
}

# 309 "/home/claude/cfront-3/src/del.cpp"
}

# 309 "/home/claude/cfront-3/src/del.cpp"
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

# 310 "/home/claude/cfront-3/src/del.cpp"

/* the end */
