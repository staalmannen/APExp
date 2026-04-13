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

# 23 "/home/claude/cfront-3/src/expand.cpp"
static Ptable Scope ;

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 26 "/home/claude/cfront-3/src/expand.cpp"
static const char *temp__FPCcP4name (const char *__1vn , Pname __1fn )
# 36 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 37 "/home/claude/cfront-3/src/expand.cpp"
if ((((__1vn [0 ])!= '_' )|| ((__1vn [1 ])!= '_' ))|| ((__1vn [2 ])!= 'X' )){
# 37 "/home/claude/cfront-3/src/expand.cpp"

# 38 "/home/claude/cfront-3/src/expand.cpp"
size_t __2a ;

# 41 "/home/claude/cfront-3/src/expand.cpp"
size_t __2aa ;
int __2al ;

# 38 "/home/claude/cfront-3/src/expand.cpp"
__2a = (((unsigned long )__1fn -> __O1__4expr.tp ));

# 41 "/home/claude/cfront-3/src/expand.cpp"
__2aa = __2a ;
__2al = 0 ;
while (__2aa ){ 
# 44 "/home/claude/cfront-3/src/expand.cpp"
__2al ++ ;
__2aa >>= 5 ;
}

# 49 "/home/claude/cfront-3/src/expand.cpp"
{ int __2ll ;
char *__2s ;
char *__2p ;

# 49 "/home/claude/cfront-3/src/expand.cpp"
__2ll = strlen ( __1vn ) ;
__2s = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* ((__2ll + __2al )+ 8 ))) ));
__2p = __2s ;

# 54 "/home/claude/cfront-3/src/expand.cpp"
((*(__2p ++ )))= '_' ;
((*(__2p ++ )))= '_' ;
((*(__2p ++ )))= 'X' ;
strcpy ( __2p , __1vn ) ;
__2p += __2ll ;
((*(__2p ++ )))= '0' ;
((*(__2p ++ )))= '0' ;

# 63 "/home/claude/cfront-3/src/expand.cpp"
while (__2a ){ 
# 64 "/home/claude/cfront-3/src/expand.cpp"
((*(__2p ++ )))= ("abcdefghijklmnopqrstuvwxyz012345"[(__2a & 037 )]);
__2a >>= 5 ;
}

# 69 "/home/claude/cfront-3/src/expand.cpp"
((*(__2p ++ )))= ("abcdefghijlkmnop"[(((((unsigned long )Scope ))>> 4 )& 15 )]);
((*(__2p ++ )))= ("abcdefghijlkmnop"[(((((unsigned long )Scope ))>> 8 )& 15 )]);
((*__2p ))= '\0' ;

# 73 "/home/claude/cfront-3/src/expand.cpp"
return (const char *)__2s ;

# 73 "/home/claude/cfront-3/src/expand.cpp"
}
}
else { 
# 77 "/home/claude/cfront-3/src/expand.cpp"
return __1vn ;
}

# 80 "/home/claude/cfront-3/src/expand.cpp"
}

# 82 "/home/claude/cfront-3/src/expand.cpp"
Plist inllist = 0 ;

# 220 "/home/claude/cfront-3/src/cfront.h"
struct table *__ct__5tableFsP5tableP4name (struct table *__0this , short , Ptable , Pname );

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 37 "/home/claude/cfront-3/src/cfront.h"
extern char *make_name__FUc (TOK );

# 35 "/home/claude/cfront-3/src/cfront.h"
extern Ptype unconst_type__FP4type (Ptype );

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 657 "/home/claude/cfront-3/src/cfront.h"
struct name_list *__ct__9name_listFP4nameP9name_list (struct name_list *__0this , Pname __1ff , Plist __1ll );

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 84 "/home/claude/cfront-3/src/expand.cpp"
Pname dcl_local__FP5tableP4nameT2Uc (Ptable __1scope , Pname __1an , Pname __1fn , bit __1tempflag )
# 85 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 98 "/home/claude/cfront-3/src/expand.cpp"
const char *__1s ;

# 86 "/home/claude/cfront-3/src/expand.cpp"
if ((__1scope == 0 )|| (__1scope -> base__4node == 0 )){ 
# 87 "/home/claude/cfront-3/src/expand.cpp"
if (sti_tbl == 0 )sti_tbl = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )8 ,
# 87 "/home/claude/cfront-3/src/expand.cpp"
gtbl , (struct name *)0 ) ;
__1scope = sti_tbl ;

# 91 "/home/claude/cfront-3/src/expand.cpp"
}

# 93 "/home/claude/cfront-3/src/expand.cpp"
if (__1an -> n_stclass__4name == 31 ){ 
# 94 "/home/claude/cfront-3/src/expand.cpp"
if ((__1an -> __O1__4expr.tp -> base__4node != 108 )&& (__1an -> __O1__4expr.tp -> base__4node != 76 )){ 
# 94 "/home/claude/cfront-3/src/expand.cpp"
struct
# 94 "/home/claude/cfront-3/src/expand.cpp"
ea __0__V17 ;

# 94 "/home/claude/cfront-3/src/expand.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & __1fn -> where__4name , (const char *)"cannot expand inlineF with static%n", (const
# 94 "/home/claude/cfront-3/src/expand.cpp"
struct ea *)( ((& __0__V17 )-> __O1__2ea.p = ((const void *)__1an )), (& __0__V17 )) , (const struct ea *)ea0 ,
# 94 "/home/claude/cfront-3/src/expand.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} return __1an ;
}

# 98 "/home/claude/cfront-3/src/expand.cpp"
;
if (__1tempflag )
# 100 "/home/claude/cfront-3/src/expand.cpp"
__1s = (const char *)make_name__FUc ( (unsigned char )'X' ) ;
else __1s = temp__FPCcP4name ( __1an -> __O2__4expr.string , __1fn ) ;
{ Pname __1nx ;
Ptype __1atp ;

# 102 "/home/claude/cfront-3/src/expand.cpp"
__1nx = __ct__4nameFPCc ( (struct name *)0 , __1s ) ;
__1atp = __1an -> __O1__4expr.tp ;

# 107 "/home/claude/cfront-3/src/expand.cpp"
while (__1atp -> base__4node == 97 )__1atp = (((struct basetype *)(((struct basetype *)__1atp ))))-> b_name__8basetype -> __O1__4expr.tp ;
if (__1atp -> base__4node == 110 ){ 
# 109 "/home/claude/cfront-3/src/expand.cpp"
if (__1an -> n_scope__4name == 136 ){ 
# 110 "/home/claude/cfront-3/src/expand.cpp"
Pptr __3t ;

# 110 "/home/claude/cfront-3/src/expand.cpp"
__3t = __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (((struct vec *)(((struct vec *)__1atp ))))-> typ__5pvtyp ) ;
__1nx -> __O1__4expr.tp = (struct type *)__3t ;
}
else { 
# 114 "/home/claude/cfront-3/src/expand.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & __1fn -> where__4name , (const char *)"cannot expand inlineF needing temporaryV of arrayT",
# 114 "/home/claude/cfront-3/src/expand.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return __1an ;
}
}
else 
# 119 "/home/claude/cfront-3/src/expand.cpp"
__1nx -> __O1__4expr.tp = __1atp ;
__1nx -> __O1__4expr.tp = unconst_type__FP4type ( __1nx -> __O1__4expr.tp ) ;
__1nx -> __O1__4expr.tp -> permanent__4node = 1 ;

# 123 "/home/claude/cfront-3/src/expand.cpp"
__1nx -> n_used__4name = __1an -> n_used__4name ;
__1nx -> n_assigned_to__4name = __1an -> n_assigned_to__4name ;
__1nx -> n_addr_taken__4name = __1an -> n_addr_taken__4name ;
__1nx -> n_xref__4name = __1an -> n_xref__4name ;

# 128 "/home/claude/cfront-3/src/expand.cpp"
{ Pname __1r ;

# 128 "/home/claude/cfront-3/src/expand.cpp"
__1r = look__5tableFPCcUc ( __1scope , __1nx -> __O2__4expr.string , (unsigned char )0 ) ;
if (__1r ){ 
# 131 "/home/claude/cfront-3/src/expand.cpp"
if (check__4typeFP4typeUcT2 ( __1r -> __O1__4expr.tp , __1nx -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 )
# 131 "/home/claude/cfront-3/src/expand.cpp"
)
# 132 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 132 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V18 ;

# 132 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V19 ;

# 132 "/home/claude/cfront-3/src/expand.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & __1fn -> where__4name , (const char *)"cannot expand inlineF %a with two local variables with the sameN (%s)", (const
# 132 "/home/claude/cfront-3/src/expand.cpp"
struct ea *)( ((& __0__V18 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V18 )) , (const struct ea *)__ct__2eaFPCv (
# 132 "/home/claude/cfront-3/src/expand.cpp"
& __0__V19 , (const void *)__1an -> __O2__4expr.string ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 132 "/home/claude/cfront-3/src/expand.cpp"
} else 
# 134 "/home/claude/cfront-3/src/expand.cpp"
__1r = 0 ;
}
if (__1r == 0 ){ 
# 137 "/home/claude/cfront-3/src/expand.cpp"
__1r = insert__5tableFP4nameUc ( __1scope , __1nx , (unsigned char )0 ) ;

# 140 "/home/claude/cfront-3/src/expand.cpp"
if (__1r -> __O1__4expr.tp -> base__4node == 119 )
# 141 "/home/claude/cfront-3/src/expand.cpp"
inllist = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __1r , inllist ) ;

# 143 "/home/claude/cfront-3/src/expand.cpp"
__1r -> n_stclass__4name = __1an -> n_stclass__4name ;
__1r -> lex_level__4name = __1an -> lex_level__4name ;
( (__1nx ?(((void )(__1nx ?(((void )( ( ((((struct expr *)__1nx ))?(((void )((((struct expr *)__1nx ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 145 "/home/claude/cfront-3/src/expand.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1nx , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
__1r -> where__4name . line__3loc = 0 ;
}
return __1r ;

# 148 "/home/claude/cfront-3/src/expand.cpp"
}

# 148 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 151 "/home/claude/cfront-3/src/expand.cpp"
int ck_cast__FP4typeT1 (Ptype __1t1 , Ptype __1t2 )
# 156 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 157 "/home/claude/cfront-3/src/expand.cpp"
st :
# 158 "/home/claude/cfront-3/src/expand.cpp"
while (__1t1 -> base__4node == 97 )__1t1 = (((struct basetype *)(((struct basetype *)__1t1 ))))-> b_name__8basetype -> __O1__4expr.tp ;
while (__1t2 -> base__4node == 97 )__1t2 = (((struct basetype *)(((struct basetype *)__1t2 ))))-> b_name__8basetype -> __O1__4expr.tp ;

# 161 "/home/claude/cfront-3/src/expand.cpp"
if (__1t1 == __1t2 )return 0 ;

# 163 "/home/claude/cfront-3/src/expand.cpp"
if (__1t1 -> base__4node != __1t2 -> base__4node )return 1 ;

# 165 "/home/claude/cfront-3/src/expand.cpp"
switch (__1t1 -> base__4node ){ 
# 166 "/home/claude/cfront-3/src/expand.cpp"
case 158 :
# 167 "/home/claude/cfront-3/src/expand.cpp"
case 125 :
# 168 "/home/claude/cfront-3/src/expand.cpp"
{ __1t1 = (((struct ptr *)(((struct ptr *)__1t1 ))))-> typ__5pvtyp ;
if (__1t1 -> base__4node == 38 )return 1 ;
__1t2 = (((struct ptr *)(((struct ptr *)__1t2 ))))-> typ__5pvtyp ;
goto st ;
}
case 5 :
# 174 "/home/claude/cfront-3/src/expand.cpp"
case 29 :
# 175 "/home/claude/cfront-3/src/expand.cpp"
case 21 :
# 176 "/home/claude/cfront-3/src/expand.cpp"
case 22 :
# 177 "/home/claude/cfront-3/src/expand.cpp"
case 122 :
# 178 "/home/claude/cfront-3/src/expand.cpp"
if ((((struct basetype *)(((struct basetype *)__1t1 ))))-> b_unsigned__8basetype != (((struct basetype *)(((struct basetype *)__1t2 ))))-> b_unsigned__8basetype )return
# 178 "/home/claude/cfront-3/src/expand.cpp"
1 ;
break ;
case 119 :
# 181 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 182 "/home/claude/cfront-3/src/expand.cpp"
Pname __3nn ;

# 182 "/home/claude/cfront-3/src/expand.cpp"
__3nn = (((struct basetype *)(((struct basetype *)__1t1 ))))-> b_name__8basetype ;

# 184 "/home/claude/cfront-3/src/expand.cpp"
if ((((struct classdef *)(((struct classdef *)__3nn -> __O1__4expr.tp ))))-> csu__8classdef == 36 )return 0 ;

# 186 "/home/claude/cfront-3/src/expand.cpp"
if ((__1t2 -> base__4node == 119 )&& (__3nn -> __O1__4expr.tp == (((struct basetype *)(((struct basetype *)__1t2 ))))-> b_name__8basetype -> __O1__4expr.tp ))return 0 ;

# 188 "/home/claude/cfront-3/src/expand.cpp"
return 1 ;
}
}

# 192 "/home/claude/cfront-3/src/expand.cpp"
return 0 ;
}

# 195 "/home/claude/cfront-3/src/expand.cpp"
int makeCM__FP4type (Ptype __1t )
# 200 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 201 "/home/claude/cfront-3/src/expand.cpp"
while (__1t -> base__4node == 97 )
# 202 "/home/claude/cfront-3/src/expand.cpp"
__1t = (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ;

# 204 "/home/claude/cfront-3/src/expand.cpp"
switch (__1t -> base__4node ){ 
# 205 "/home/claude/cfront-3/src/expand.cpp"
case 15 :
# 206 "/home/claude/cfront-3/src/expand.cpp"
case 11 :
# 207 "/home/claude/cfront-3/src/expand.cpp"
case 181 :
# 208 "/home/claude/cfront-3/src/expand.cpp"
case 5 :
# 209 "/home/claude/cfront-3/src/expand.cpp"
case 29 :
# 210 "/home/claude/cfront-3/src/expand.cpp"
case 21 :
# 211 "/home/claude/cfront-3/src/expand.cpp"
case 22 :
# 212 "/home/claude/cfront-3/src/expand.cpp"
case 122 :
# 213 "/home/claude/cfront-3/src/expand.cpp"
case 121 :
# 214 "/home/claude/cfront-3/src/expand.cpp"
return 0 ;
# 214 "/home/claude/cfront-3/src/expand.cpp"

# 215 "/home/claude/cfront-3/src/expand.cpp"
default :
# 216 "/home/claude/cfront-3/src/expand.cpp"
return 1 ;
}
}

# 220 "/home/claude/cfront-3/src/expand.cpp"
static int ret_seen = 0 ;

# 222 "/home/claude/cfront-3/src/expand.cpp"
static int has_return__FP4stmt (Pstmt __1sl );

# 222 "/home/claude/cfront-3/src/expand.cpp"
static int has_return__FP4stmt (Pstmt __1sl )
# 223 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 224 "/home/claude/cfront-3/src/expand.cpp"
int __1hr ;

# 226 "/home/claude/cfront-3/src/expand.cpp"
if (! __1sl )
# 227 "/home/claude/cfront-3/src/expand.cpp"
return 0 ;
__1hr = 0 ;
{ { Pstmt __1s ;

# 229 "/home/claude/cfront-3/src/expand.cpp"
__1s = __1sl ;

# 229 "/home/claude/cfront-3/src/expand.cpp"
for(;__1s ;__1s = __1s -> s_list__4stmt ) { 
# 230 "/home/claude/cfront-3/src/expand.cpp"
switch (__1s -> base__4node ){ 
# 231 "/home/claude/cfront-3/src/expand.cpp"
case 39 :
# 232 "/home/claude/cfront-3/src/expand.cpp"
case 10 :
# 233 "/home/claude/cfront-3/src/expand.cpp"
case 16 :
# 234 "/home/claude/cfront-3/src/expand.cpp"
case 33 :
# 235 "/home/claude/cfront-3/src/expand.cpp"
case 116 :
# 236 "/home/claude/cfront-3/src/expand.cpp"
case 115 :
# 237 "/home/claude/cfront-3/src/expand.cpp"
case
# 237 "/home/claude/cfront-3/src/expand.cpp"
4 :
# 238 "/home/claude/cfront-3/src/expand.cpp"
case 8 :
# 239 "/home/claude/cfront-3/src/expand.cpp"
__1hr = has_return__FP4stmt ( __1s -> s__4stmt ) ;
break ;
case 20 :
# 242 "/home/claude/cfront-3/src/expand.cpp"
__1hr = has_return__FP4stmt ( __1s -> s__4stmt ) ;
__1hr = (__1hr || has_return__FP4stmt ( __1s -> __O3__4stmt.else_stmt ) );
break ;
case 166 :
# 246 "/home/claude/cfront-3/src/expand.cpp"
__1hr = has_return__FP4stmt ( __1s -> s__4stmt ) ;
__1hr = (__1hr || has_return__FP4stmt ( __1s -> __O2__4stmt.s2 ) );
break ;
case 28 :
# 250 "/home/claude/cfront-3/src/expand.cpp"
if (__1s -> __O2__4stmt.e && (__1s -> __O2__4stmt.e != dummy ))
# 251 "/home/claude/cfront-3/src/expand.cpp"
__1hr = 1 ;
break ;
}
if (__1hr )
# 255 "/home/claude/cfront-3/src/expand.cpp"
return 1 ;
}

# 258 "/home/claude/cfront-3/src/expand.cpp"
return 0 ;

# 258 "/home/claude/cfront-3/src/expand.cpp"
}

# 258 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 234 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 261 "/home/claude/cfront-3/src/expand.cpp"
Pstmt expand__4stmtFv (struct stmt *__0this );

# 806 "/home/claude/cfront-3/src/cfront.h"
Pexpr expand__4exprFv (struct expr *__0this );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 359 "/home/claude/cfront-3/src/cfront.h"
Pfct memptr__4typeFv (struct type *__0this );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 261 "/home/claude/cfront-3/src/expand.cpp"
Pstmt expand__4stmtFv (register struct stmt *__0this )
# 269 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 269 "/home/claude/cfront-3/src/expand.cpp"
const void *__2__X25 ;

# 270 "/home/claude/cfront-3/src/expand.cpp"
if (__0this == 0 ){ 
# 270 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V20 ;

# 270 "/home/claude/cfront-3/src/expand.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"0->S::expand() for%n", (const struct ea *)( (__2__X25 =
# 270 "/home/claude/cfront-3/src/expand.cpp"
(const void *)expand_fn ), ( ((& __0__V20 )-> __O1__2ea.p = __2__X25 ), (& __0__V20 )) ) , (const struct
# 270 "/home/claude/cfront-3/src/expand.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} { Pstmt __1ostmt ;

# 271 "/home/claude/cfront-3/src/expand.cpp"
__1ostmt = Cstmt ;
if (__0this -> where__4stmt . line__3loc )Cstmt = __0this ;

# 274 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> memtbl__4stmt ){ 
# 275 "/home/claude/cfront-3/src/expand.cpp"
Ptable __2t ;
int __2i ;

# 275 "/home/claude/cfront-3/src/expand.cpp"
__2t = __0this -> memtbl__4stmt ;

# 277 "/home/claude/cfront-3/src/expand.cpp"
{ { Pname __2n ;

# 278 "/home/claude/cfront-3/src/expand.cpp"
int __2__X26 ;

# 278 "/home/claude/cfront-3/src/expand.cpp"
int __2__X27 ;

# 277 "/home/claude/cfront-3/src/expand.cpp"
__2n = ( (__2__X27 = (__2i = 1 )), ( (((__2__X27 <= 0 )|| (__2t -> free_slot__5table <= __2__X27 ))?(((struct name *)0 )):(__2t -> entries__5table [__2__X27 ]))) )
# 277 "/home/claude/cfront-3/src/expand.cpp"
;

# 277 "/home/claude/cfront-3/src/expand.cpp"
for(;__2n ;__2n = (__2n -> n_tbl_list__4name ?__2n -> n_tbl_list__4name :( (__2__X26 = (++ __2i )), ( (((__2__X26 <= 0 )|| (__2t -> free_slot__5table <= __2__X26 ))?(((struct name *)0 )):(__2t ->
# 277 "/home/claude/cfront-3/src/expand.cpp"
entries__5table [__2__X26 ]))) ) )) { 
# 278 "/home/claude/cfront-3/src/expand.cpp"
if (__2n -> n_stclass__4name == 31 ){ 
# 279 "/home/claude/cfront-3/src/expand.cpp"
if ((__2n -> __O1__4expr.tp -> base__4node == 108 )|| (__2n ->
# 279 "/home/claude/cfront-3/src/expand.cpp"
__O1__4expr.tp -> base__4node == 76 ))continue ;
{ 
# 280 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V21 ;

# 280 "/home/claude/cfront-3/src/expand.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"cannot expand inlineF with static%n", (const struct ea *)( ((&
# 280 "/home/claude/cfront-3/src/expand.cpp"
__0__V21 )-> __O1__2ea.p = ((const void *)__2n )), (& __0__V21 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 280 "/home/claude/cfront-3/src/expand.cpp"
(const struct ea *)ea0 ) ;
__2n -> n_stclass__4name = 2 ;
} }
__2n -> where__4name . line__3loc = 0 ;
}

# 284 "/home/claude/cfront-3/src/expand.cpp"
}

# 284 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 287 "/home/claude/cfront-3/src/expand.cpp"
if (expand_tbl ){ 
# 288 "/home/claude/cfront-3/src/expand.cpp"
Pexpr __2ee ;

# 290 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> memtbl__4stmt ){ 
# 291 "/home/claude/cfront-3/src/expand.cpp"
int __3i ;
{ { Pname __3n ;

# 293 "/home/claude/cfront-3/src/expand.cpp"
struct table *__0__X28 ;

# 293 "/home/claude/cfront-3/src/expand.cpp"
int __2__X29 ;

# 293 "/home/claude/cfront-3/src/expand.cpp"
struct table *__0__X30 ;

# 293 "/home/claude/cfront-3/src/expand.cpp"
int __2__X31 ;

# 292 "/home/claude/cfront-3/src/expand.cpp"
__3n = ( (__0__X30 = __0this -> memtbl__4stmt ), ( (__2__X31 = (__3i = 1 )), ( (((__2__X31 <= 0 )|| (__0__X30 -> free_slot__5table <=
# 292 "/home/claude/cfront-3/src/expand.cpp"
__2__X31 ))?(((struct name *)0 )):(__0__X30 -> entries__5table [__2__X31 ]))) ) ) ;

# 292 "/home/claude/cfront-3/src/expand.cpp"
for(;__3n ;__3n = (__3n -> n_tbl_list__4name ?__3n -> n_tbl_list__4name :( (__0__X28 = __0this -> memtbl__4stmt ), ( (__2__X29 = (++ __3i )), ( (((__2__X29 <= 0 )||
# 292 "/home/claude/cfront-3/src/expand.cpp"
(__0__X28 -> free_slot__5table <= __2__X29 ))?(((struct name *)0 )):(__0__X28 -> entries__5table [__2__X29 ]))) ) ) )) { 
# 294 "/home/claude/cfront-3/src/expand.cpp"
if (((__3n -> base__4node != 85 )|| (__3n ->
# 294 "/home/claude/cfront-3/src/expand.cpp"
__O1__4expr.tp == (((struct type *)any_type ))))|| (__3n -> n_key__4name == 6 ))continue ;

# 296 "/home/claude/cfront-3/src/expand.cpp"
if ((((__0this -> base__4node == 116 )&& (__0this -> memtbl__4stmt -> real_block__5table == __0this ))&& (__3n -> lex_level__4name < 2 ))&& ((((__3n -> __O2__4expr.string [0 ])!= '_' )||
# 296 "/home/claude/cfront-3/src/expand.cpp"
((__3n -> __O2__4expr.string [1 ])!= '_' ))|| (((__3n -> __O2__4expr.string [2 ])!= 'X' )&& ((__3n -> __O2__4expr.string [2 ])!= 'K' ))))
# 305 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 307 "/home/claude/cfront-3/src/expand.cpp"
continue ;
}

# 310 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> memtbl__4stmt != scope )
# 311 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 312 "/home/claude/cfront-3/src/expand.cpp"
Pname __5nn ;

# 312 "/home/claude/cfront-3/src/expand.cpp"
__5nn = dcl_local__FP5tableP4nameT2Uc ( scope , __3n , expand_fn , (unsigned char )0 ) ;
__5nn -> base__4node = 85 ;
__3n -> __O2__4expr.string = __5nn -> __O2__4expr.string ;
}
else if ((__3n -> __O1__4expr.tp && (__3n -> __O1__4expr.tp -> base__4node != 108 ))&& (__3n -> __O1__4expr.tp -> base__4node != 76 )){ 
# 317 "/home/claude/cfront-3/src/expand.cpp"
__3n -> __O2__4expr.string =
# 317 "/home/claude/cfront-3/src/expand.cpp"
temp__FPCcP4name ( __3n -> __O2__4expr.string , expand_fn ) ;
__3n -> where__4name . line__3loc = 0 ;
}
}

# 320 "/home/claude/cfront-3/src/expand.cpp"
}

# 320 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 323 "/home/claude/cfront-3/src/expand.cpp"
switch (__0this -> base__4node ){ 
# 323 "/home/claude/cfront-3/src/expand.cpp"
const void *__2__X32 ;

# 323 "/home/claude/cfront-3/src/expand.cpp"
unsigned long __2__X33 ;

# 324 "/home/claude/cfront-3/src/expand.cpp"
default :
# 325 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 325 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V22 ;

# 325 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V23 ;

# 325 "/home/claude/cfront-3/src/expand.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"cannot expand inlineF%a with %kS in inline", (const struct ea *)( (__2__X32 =
# 325 "/home/claude/cfront-3/src/expand.cpp"
(const void *)expand_fn ), ( ((& __0__V22 )-> __O1__2ea.p = __2__X32 ), (& __0__V22 )) ) , (const struct
# 325 "/home/claude/cfront-3/src/expand.cpp"
ea *)( (__2__X33 = __0this -> base__4node ), ( (( ((& __0__V23 )-> __O1__2ea.i = __2__X33 ), 0 ) ), (& __0__V23 ))
# 325 "/home/claude/cfront-3/src/expand.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
Cstmt = __1ostmt ;
return (((struct stmt *)(((struct stmt *)dummy ))));

# 329 "/home/claude/cfront-3/src/expand.cpp"
case 116 :
# 330 "/home/claude/cfront-3/src/expand.cpp"
;
if (__0this -> s_list__4stmt ){ 
# 332 "/home/claude/cfront-3/src/expand.cpp"
__2ee = (((struct expr *)(((struct expr *)expand__4stmtFv ( __0this -> s_list__4stmt ) ))));
if (__0this -> s__4stmt ){ 
# 334 "/home/claude/cfront-3/src/expand.cpp"
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , ((struct expr *)(((struct expr *)expand__4stmtFv ( __0this ->
# 334 "/home/claude/cfront-3/src/expand.cpp"
s__4stmt ) ))), __2ee ) ;
__2ee -> __O1__4expr.tp = __2ee -> __O3__4expr.e2 -> __O1__4expr.tp ;
__2ee -> permanent__4node = 1 ;
}
Cstmt = __1ostmt ;
return (((struct stmt *)(((struct stmt *)__2ee ))));
}

# 342 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> s__4stmt ){ 
# 343 "/home/claude/cfront-3/src/expand.cpp"
Pstmt __4st ;

# 343 "/home/claude/cfront-3/src/expand.cpp"
__4st = expand__4stmtFv ( __0this -> s__4stmt ) ;
Cstmt = __1ostmt ;
return __4st ;
}

# 348 "/home/claude/cfront-3/src/expand.cpp"
Cstmt = __1ostmt ;
return (((struct stmt *)(((struct stmt *)zero ))));

# 351 "/home/claude/cfront-3/src/expand.cpp"
case 166 :
# 352 "/home/claude/cfront-3/src/expand.cpp"
__2ee = (__0this -> __O2__4stmt.s2 ?(((struct expr *)(((struct expr *)expand__4stmtFv ( __0this -> __O2__4stmt.s2 ) )))):(((struct expr *)0 )));
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __0this -> s__4stmt ?(((struct expr *)(((struct expr *)expand__4stmtFv ( __0this -> s__4stmt ) )))):(((struct
# 353 "/home/claude/cfront-3/src/expand.cpp"
expr *)0 )), __2ee ) ;
__2ee -> __O1__4expr.tp = __2ee -> __O3__4expr.e2 -> __O1__4expr.tp ;
if (__0this -> s_list__4stmt ){ 
# 356 "/home/claude/cfront-3/src/expand.cpp"
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __2ee , ((struct expr *)(((struct expr *)expand__4stmtFv (
# 356 "/home/claude/cfront-3/src/expand.cpp"
__0this -> s_list__4stmt ) )))) ;
__2ee -> __O1__4expr.tp = __2ee -> __O3__4expr.e2 -> __O1__4expr.tp ;
}
__2ee -> permanent__4node = 1 ;
Cstmt = __1ostmt ;
return (((struct stmt *)(((struct stmt *)__2ee ))));

# 363 "/home/claude/cfront-3/src/expand.cpp"
case 28 :
# 364 "/home/claude/cfront-3/src/expand.cpp"
ret_seen = 1 ;
__0this -> s_list__4stmt = 0 ;

# 367 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> __O2__4stmt.e == 0 )
# 368 "/home/claude/cfront-3/src/expand.cpp"
__2ee = zero ;
else { 
# 370 "/home/claude/cfront-3/src/expand.cpp"
__2ee = expand__4exprFv ( __0this -> __O2__4stmt.e ) ;
{ Ptype __4tt ;

# 372 "/home/claude/cfront-3/src/expand.cpp"
register struct cast *__0__X34 ;

# 371 "/home/claude/cfront-3/src/expand.cpp"
__4tt = (((struct fct *)(((struct fct *)expand_fn -> __O1__4expr.tp ))))-> s_returns__3fct ;
if (__4tt == 0 )__4tt = (((struct fct *)(((struct fct *)expand_fn -> __O1__4expr.tp ))))-> returns__3fct ;

# 375 "/home/claude/cfront-3/src/expand.cpp"
if ((__4tt != __2ee -> __O1__4expr.tp )&& ck_cast__FP4typeT1 ( __4tt , __2ee -> __O1__4expr.tp ) )__2ee = (struct expr *)( (__0__X34 = 0 ), (
# 375 "/home/claude/cfront-3/src/expand.cpp"
((__0__X34 || (__0__X34 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X34 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X34 ),
# 375 "/home/claude/cfront-3/src/expand.cpp"
(unsigned char )191 , __2ee , (struct expr *)0 ) ), (__0__X34 -> __O1__4expr.tp = (__0__X34 -> __O4__4expr.tp2 = __4tt ))) :0 ), __0__X34 )
# 375 "/home/claude/cfront-3/src/expand.cpp"
) ;

# 375 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 378 "/home/claude/cfront-3/src/expand.cpp"
Cstmt = __1ostmt ;
return (((struct stmt *)(((struct stmt *)__2ee ))));

# 381 "/home/claude/cfront-3/src/expand.cpp"
case 72 :
# 382 "/home/claude/cfront-3/src/expand.cpp"
if ((__0this -> __O2__4stmt.e == 0 )|| (__0this -> __O2__4stmt.e == dummy ))
# 383 "/home/claude/cfront-3/src/expand.cpp"
__2ee = zero ;
else { 
# 385 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> __O2__4stmt.e -> base__4node == 111 )__0this -> __O2__4stmt.e = __0this -> __O2__4stmt.e -> __O2__4expr.e1 ;
__2ee = expand__4exprFv ( __0this -> __O2__4stmt.e ) ;
}
if (__0this -> s_list__4stmt ){ 
# 389 "/home/claude/cfront-3/src/expand.cpp"
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __2ee , ((struct expr *)(((struct expr *)expand__4stmtFv (
# 389 "/home/claude/cfront-3/src/expand.cpp"
__0this -> s_list__4stmt ) )))) ;
__2ee -> __O1__4expr.tp = __2ee -> __O3__4expr.e2 -> __O1__4expr.tp ;
__2ee -> permanent__4node = 1 ;
}
Cstmt = __1ostmt ;
return (((struct stmt *)(((struct stmt *)__2ee ))));

# 396 "/home/claude/cfront-3/src/expand.cpp"
case 1 :
# 397 "/home/claude/cfront-3/src/expand.cpp"
error__FiPCc ( (int )'s' , (const char *)"asm() in value-returning inline") ;
return __0this ;

# 400 "/home/claude/cfront-3/src/expand.cpp"
case 20 :
# 401 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 402 "/home/claude/cfront-3/src/expand.cpp"
int __4ors ;

# 402 "/home/claude/cfront-3/src/expand.cpp"
__4ors = ret_seen ;
ret_seen = 0 ;
__2ee = (((struct expr *)(((struct expr *)expand__4stmtFv ( __0this -> s__4stmt ) ))));
if ((__2ee -> __O1__4expr.tp && memptr__4typeFv ( __2ee -> __O1__4expr.tp ) )|| (((__2ee -> base__4node == 70 )&& __2ee -> __O2__4expr.e1 -> __O1__4expr.tp )&& (__2ee ->
# 405 "/home/claude/cfront-3/src/expand.cpp"
__O2__4expr.e1 -> __O1__4expr.tp -> base__4node != 125 )))
# 411 "/home/claude/cfront-3/src/expand.cpp"
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __2ee , zero ) ;
{ Pexpr __4qq ;
int __4ret1 ;

# 412 "/home/claude/cfront-3/src/expand.cpp"
__4qq = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , __2ee , zero ) ;
__4ret1 = ret_seen ;
ret_seen = 0 ;

# 416 "/home/claude/cfront-3/src/expand.cpp"
__4qq -> __O4__4expr.cond = expand__4exprFv ( __0this -> __O2__4stmt.e ) ;
__4qq -> __O3__4expr.e2 = (__0this -> __O3__4stmt.else_stmt ?(((struct expr *)(((struct expr *)expand__4stmtFv ( __0this -> __O3__4stmt.else_stmt ) )))):zero );
if (((((! has_return__FP4stmt ( __0this -> s__4stmt ) )&& (! has_return__FP4stmt ( __0this -> __O3__4stmt.else_stmt ) ))&& __4qq -> __O2__4expr.e1 -> __O1__4expr.tp )&&
# 418 "/home/claude/cfront-3/src/expand.cpp"
__4qq -> __O3__4expr.e2 -> __O1__4expr.tp )&& check__4typeFP4typeUcT2 ( __4qq -> __O2__4expr.e1 -> __O1__4expr.tp , __4qq -> __O3__4expr.e2 -> __O1__4expr.tp , (unsigned char )70 , (unsigned
# 418 "/home/claude/cfront-3/src/expand.cpp"
char )0 ) )
# 420 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 420 "/home/claude/cfront-3/src/expand.cpp"
register struct cast *__0__X35 ;

# 420 "/home/claude/cfront-3/src/expand.cpp"
struct type *__2__X36 ;

# 420 "/home/claude/cfront-3/src/expand.cpp"
struct expr *__2__X37 ;

# 420 "/home/claude/cfront-3/src/expand.cpp"
register struct cast *__0__X38 ;

# 420 "/home/claude/cfront-3/src/expand.cpp"
struct type *__2__X39 ;

# 420 "/home/claude/cfront-3/src/expand.cpp"
struct expr *__2__X40 ;

# 421 "/home/claude/cfront-3/src/expand.cpp"
__4qq -> __O2__4expr.e1 = (struct expr *)( (__0__X35 = 0 ), ( (__2__X36 = (struct type *)void_type ), ( (__2__X37 = __4qq -> __O2__4expr.e1 ),
# 421 "/home/claude/cfront-3/src/expand.cpp"
( ((__0__X35 || (__0__X35 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X35 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct
# 421 "/home/claude/cfront-3/src/expand.cpp"
expr *)__0__X35 ), (unsigned char )191 , __2__X37 , (struct expr *)0 ) ), (__0__X35 -> __O1__4expr.tp = (__0__X35 -> __O4__4expr.tp2 = __2__X36 ))) :0 ),
# 421 "/home/claude/cfront-3/src/expand.cpp"
__0__X35 ) ) ) ) ;
__4qq -> __O3__4expr.e2 = (struct expr *)( (__0__X38 = 0 ), ( (__2__X39 = (struct type *)void_type ), ( (__2__X40 = __4qq -> __O3__4expr.e2 ),
# 422 "/home/claude/cfront-3/src/expand.cpp"
( ((__0__X38 || (__0__X38 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X38 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct
# 422 "/home/claude/cfront-3/src/expand.cpp"
expr *)__0__X38 ), (unsigned char )191 , __2__X40 , (struct expr *)0 ) ), (__0__X38 -> __O1__4expr.tp = (__0__X38 -> __O4__4expr.tp2 = __2__X39 ))) :0 ),
# 422 "/home/claude/cfront-3/src/expand.cpp"
__0__X38 ) ) ) ) ;
}

# 434 "/home/claude/cfront-3/src/expand.cpp"
{ int __4ret2 ;

# 434 "/home/claude/cfront-3/src/expand.cpp"
__4ret2 = ret_seen ;
if ((__4ret1 + __4ret2 )&& __0this -> s_list__4stmt ){ 
# 435 "/home/claude/cfront-3/src/expand.cpp"
const void *__2__X41 ;

# 436 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 436 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V24 ;

# 436 "/home/claude/cfront-3/src/expand.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"cannot expand inlineF%a with S after \"return\"", (const struct ea *)( (__2__X41 =
# 436 "/home/claude/cfront-3/src/expand.cpp"
(const void *)expand_fn ), ( ((& __0__V24 )-> __O1__2ea.p = __2__X41 ), (& __0__V24 )) ) , (const struct
# 436 "/home/claude/cfront-3/src/expand.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
ret_seen = 0 ;
} }
ret_seen += __4ret1 ;
ret_seen += __4ret2 ;
ret_seen += __4ors ;

# 445 "/home/claude/cfront-3/src/expand.cpp"
{ Ptype __4t1 ;

# 445 "/home/claude/cfront-3/src/expand.cpp"
__4t1 = __4qq -> __O2__4expr.e1 -> __O1__4expr.tp ;
if (__4qq -> __O2__4expr.e1 -> base__4node == 147 )
# 447 "/home/claude/cfront-3/src/expand.cpp"
__4t1 = __4qq -> __O2__4expr.e1 -> __O3__4expr.e2 -> __O1__4expr.tp ;
{ Ptype __4t2 ;

# 448 "/home/claude/cfront-3/src/expand.cpp"
__4t2 = __4qq -> __O3__4expr.e2 -> __O1__4expr.tp ;

# 450 "/home/claude/cfront-3/src/expand.cpp"
if (__4t1 && (__4t1 -> base__4node == 108 ))
# 451 "/home/claude/cfront-3/src/expand.cpp"
__4t1 = ((((struct fct *)(((struct fct *)__4t1 ))))-> s_returns__3fct ?(((struct fct *)(((struct fct *)__4t1 ))))-> s_returns__3fct :(((struct fct *)(((struct fct *)__4t1 ))))->
# 451 "/home/claude/cfront-3/src/expand.cpp"
returns__3fct );

# 453 "/home/claude/cfront-3/src/expand.cpp"
if (__4t2 && (__4t2 -> base__4node == 108 ))
# 454 "/home/claude/cfront-3/src/expand.cpp"
__4t2 = ((((struct fct *)(((struct fct *)__4t2 ))))-> s_returns__3fct ?(((struct fct *)(((struct fct *)__4t2 ))))-> s_returns__3fct :(((struct fct *)(((struct fct *)__4t2 ))))->
# 454 "/home/claude/cfront-3/src/expand.cpp"
returns__3fct );

# 456 "/home/claude/cfront-3/src/expand.cpp"
{ Pname __4c1 ;
Pname __4c2 ;

# 459 "/home/claude/cfront-3/src/expand.cpp"
int __4z1 ;
int __4z2 ;

# 456 "/home/claude/cfront-3/src/expand.cpp"
__4c1 = (__4t1 ?is_cl_obj__4typeFv ( __4t1 ) :(((struct name *)0 )));
__4c2 = (__4t2 ?is_cl_obj__4typeFv ( __4t2 ) :(((struct name *)0 )));

# 459 "/home/claude/cfront-3/src/expand.cpp"
__4z1 = (__4c1 && (__4c1 != __4c2 ));
__4z2 = (__4c2 && (__4c1 != __4c2 ));

# 465 "/home/claude/cfront-3/src/expand.cpp"
if ((((((__4c1 == 0 )&& (__4c2 == 0 ))&& __4t1 )&& __4t2 )&& check__4typeFP4typeUcT2 ( __4t2 , __4t1 , (unsigned char )70 , (unsigned
# 465 "/home/claude/cfront-3/src/expand.cpp"
char )0 ) )&& check__4typeFP4typeUcT2 ( __4t1 , __4t2 , (unsigned char )70 , (unsigned char )0 ) )
# 470 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 471 "/home/claude/cfront-3/src/expand.cpp"
__4z1 =
# 471 "/home/claude/cfront-3/src/expand.cpp"
makeCM__FP4type ( __4t1 ) ;
__4z2 = makeCM__FP4type ( __4t2 ) ;
if ((__4z1 && __4ret1 )|| (__4z2 && __4ret2 ))
# 474 "/home/claude/cfront-3/src/expand.cpp"
error__FiPCc ( (int )'s' , (const char *)"cannot expand inlineF with return in ifS")
# 474 "/home/claude/cfront-3/src/expand.cpp"
;
}

# 480 "/home/claude/cfront-3/src/expand.cpp"
if (__4t1 && (__4z1 == 0 )){ 
# 488 "/home/claude/cfront-3/src/expand.cpp"
__4z1 = ((((is_ptr_or_ref__4typeFv ( __4t1 ) && __4t2 )&& is_ptr_or_ref__4typeFv ( __4t2 ) )&& check__4typeFP4typeUcT2 ( __4t1 ,
# 488 "/home/claude/cfront-3/src/expand.cpp"
__4t2 , (unsigned char )0 , (unsigned char )0 ) )&& (! const_problem ));
}

# 494 "/home/claude/cfront-3/src/expand.cpp"
if (__4z1 ){ 
# 495 "/home/claude/cfront-3/src/expand.cpp"
Pexpr __5v ;

# 496 "/home/claude/cfront-3/src/expand.cpp"
register struct cast *__0__X42 ;

# 496 "/home/claude/cfront-3/src/expand.cpp"
struct expr *__2__X43 ;

# 495 "/home/claude/cfront-3/src/expand.cpp"
__5v = ((((__4z2 == 0 )&& __4t2 )&& is_ptr_or_ref__4typeFv ( __4t2 ) )?(((struct expr *)( (__0__X42 = 0 ), ( (__2__X43 = zero ), (
# 495 "/home/claude/cfront-3/src/expand.cpp"
((__0__X42 || (__0__X42 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X42 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X42 ),
# 495 "/home/claude/cfront-3/src/expand.cpp"
(unsigned char )191 , __2__X43 , (struct expr *)0 ) ), (__0__X42 -> __O1__4expr.tp = (__0__X42 -> __O4__4expr.tp2 = __4t2 ))) :0 ), __0__X42 )
# 495 "/home/claude/cfront-3/src/expand.cpp"
) ) )):zero );
__4qq -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __4qq -> __O2__4expr.e1 , __5v ) ;
__4qq -> __O2__4expr.e1 -> __O1__4expr.tp = __4qq -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ;
}

# 503 "/home/claude/cfront-3/src/expand.cpp"
if (__4z2 ){ 
# 504 "/home/claude/cfront-3/src/expand.cpp"
Pexpr __5v ;

# 505 "/home/claude/cfront-3/src/expand.cpp"
register struct cast *__0__X44 ;

# 505 "/home/claude/cfront-3/src/expand.cpp"
struct expr *__2__X45 ;

# 504 "/home/claude/cfront-3/src/expand.cpp"
__5v = ((((__4z1 == 0 )&& __4t1 )&& is_ptr_or_ref__4typeFv ( __4t1 ) )?(((struct expr *)( (__0__X44 = 0 ), ( (__2__X45 = zero ), (
# 504 "/home/claude/cfront-3/src/expand.cpp"
((__0__X44 || (__0__X44 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X44 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X44 ),
# 504 "/home/claude/cfront-3/src/expand.cpp"
(unsigned char )191 , __2__X45 , (struct expr *)0 ) ), (__0__X44 -> __O1__4expr.tp = (__0__X44 -> __O4__4expr.tp2 = __4t1 ))) :0 ), __0__X44 )
# 504 "/home/claude/cfront-3/src/expand.cpp"
) ) )):zero );
__4qq -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __4qq -> __O3__4expr.e2 , __5v ) ;
__4qq -> __O3__4expr.e2 -> __O1__4expr.tp = __4qq -> __O3__4expr.e2 -> __O2__4expr.e1 -> __O1__4expr.tp ;
}

# 512 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> s_list__4stmt ){ 
# 513 "/home/claude/cfront-3/src/expand.cpp"
__4qq = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __4qq , ((struct expr *)(((struct expr *)expand__4stmtFv (
# 513 "/home/claude/cfront-3/src/expand.cpp"
__0this -> s_list__4stmt ) )))) ;
__4qq -> __O1__4expr.tp = __4qq -> __O3__4expr.e2 -> __O1__4expr.tp ;
}
else 
# 517 "/home/claude/cfront-3/src/expand.cpp"
__4qq -> __O1__4expr.tp = __4qq -> __O2__4expr.e1 -> __O1__4expr.tp ;
__4qq -> permanent__4node = 1 ;
Cstmt = __1ostmt ;
return (((struct stmt *)(((struct stmt *)__4qq ))));

# 520 "/home/claude/cfront-3/src/expand.cpp"
}

# 520 "/home/claude/cfront-3/src/expand.cpp"
}

# 520 "/home/claude/cfront-3/src/expand.cpp"
}

# 520 "/home/claude/cfront-3/src/expand.cpp"
}

# 520 "/home/claude/cfront-3/src/expand.cpp"
}
}
} }
}

# 525 "/home/claude/cfront-3/src/expand.cpp"
__0this -> where__4stmt . line__3loc = 0 ;

# 527 "/home/claude/cfront-3/src/expand.cpp"
switch (__0this -> base__4node ){ 
# 528 "/home/claude/cfront-3/src/expand.cpp"
default :
# 529 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> __O2__4stmt.e )__0this -> __O2__4stmt.e = expand__4exprFv ( __0this -> __O2__4stmt.e ) ;
break ;
case 166 :
# 532 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> __O2__4stmt.s2 )__0this -> __O2__4stmt.s2 = expand__4stmtFv ( __0this -> __O2__4stmt.s2 ) ;
break ;
case 116 :
# 535 "/home/claude/cfront-3/src/expand.cpp"
break ;
case 16 :
# 537 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> __O3__4stmt.for_init )__0this -> __O3__4stmt.for_init = expand__4stmtFv ( __0this -> __O3__4stmt.for_init ) ;
if (__0this -> __O1__4stmt.e2 )__0this -> __O1__4stmt.e2 = expand__4exprFv ( __0this -> __O1__4stmt.e2 ) ;
case 1 :
# 540 "/home/claude/cfront-3/src/expand.cpp"
break ;
case 115 :
# 542 "/home/claude/cfront-3/src/expand.cpp"
case 19 :{ 
# 543 "/home/claude/cfront-3/src/expand.cpp"
char *__3s ;

# 543 "/home/claude/cfront-3/src/expand.cpp"
__3s = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __0this -> __O1__4stmt.d -> __O2__4expr.string ) + 1 )))
# 543 "/home/claude/cfront-3/src/expand.cpp"
));
strcpy ( __3s , __0this -> __O1__4stmt.d -> __O2__4expr.string ) ;
__0this -> __O1__4stmt.d -> __O2__4expr.string = (const char *)__3s ;
break ;
}

# 552 "/home/claude/cfront-3/src/expand.cpp"
}

# 554 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> s__4stmt )__0this -> s__4stmt = expand__4stmtFv ( __0this -> s__4stmt ) ;
if (__0this -> s_list__4stmt )__0this -> s_list__4stmt = expand__4stmtFv ( __0this -> s_list__4stmt ) ;
__0this -> permanent__4node = 1 ;
Cstmt = __1ostmt ;
return __0this ;

# 558 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 561 "/home/claude/cfront-3/src/expand.cpp"
Pexpr expand__4exprFv (register struct expr *__0this )
# 562 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 563 "/home/claude/cfront-3/src/expand.cpp"
if (__0this == 0 )error__FiPCc ( (int )'i' , (const char *)"E::expand(0)")
# 563 "/home/claude/cfront-3/src/expand.cpp"
;

# 565 "/home/claude/cfront-3/src/expand.cpp"
switch (__0this -> base__4node ){ 
# 566 "/home/claude/cfront-3/src/expand.cpp"
case 85 :
# 567 "/home/claude/cfront-3/src/expand.cpp"
if ((expand_tbl && ((((struct name *)(((struct name *)__0this ))))-> n_scope__4name == 108 ))&& ((((struct name *)(((struct name *)__0this ))))->
# 567 "/home/claude/cfront-3/src/expand.cpp"
lex_level__4name > expand_fn -> lex_level__4name ))
# 569 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 570 "/home/claude/cfront-3/src/expand.cpp"
Pname __3n ;
const char *__3s ;

# 570 "/home/claude/cfront-3/src/expand.cpp"
__3n = (((struct name *)(((struct name *)__0this ))));
__3s = __3n -> __O2__4expr.string ;
if ((((__3s [0 ])== '_' )&& ((__3s [1 ])== '_' ))&& (((__3s [2 ])== 'X' )|| ((__3s [2 ])== 'K' )))break ;

# 575 "/home/claude/cfront-3/src/expand.cpp"
__3n -> __O2__4expr.string = temp__FPCcP4name ( __3s , expand_fn ) ;
}
case 144 :
# 578 "/home/claude/cfront-3/src/expand.cpp"
case 162 :
# 579 "/home/claude/cfront-3/src/expand.cpp"
case 82 :
# 580 "/home/claude/cfront-3/src/expand.cpp"
case 83 :
# 581 "/home/claude/cfront-3/src/expand.cpp"
case 84 :
# 582 "/home/claude/cfront-3/src/expand.cpp"
case 150 :
# 585 "/home/claude/cfront-3/src/expand.cpp"
case 81 :
# 586 "/home/claude/cfront-3/src/expand.cpp"
case 86 :
# 587 "/home/claude/cfront-3/src/expand.cpp"
case 165 :
# 588 "/home/claude/cfront-3/src/expand.cpp"
case 169 :
# 589 "/home/claude/cfront-3/src/expand.cpp"
case 177 :
# 590 "/home/claude/cfront-3/src/expand.cpp"
break ;
case 168 :
# 592 "/home/claude/cfront-3/src/expand.cpp"
if (expand_tbl && (__0this -> __O2__4expr.e1 == 0 )){ 
# 593 "/home/claude/cfront-3/src/expand.cpp"
int __3ors ;

# 593 "/home/claude/cfront-3/src/expand.cpp"
__3ors = ret_seen ;
ret_seen = 0 ;
{ Pname __3fn ;
Pfct __3f ;

# 597 "/home/claude/cfront-3/src/expand.cpp"
const void *__2__X48 ;

# 595 "/home/claude/cfront-3/src/expand.cpp"
__3fn = __0this -> __O4__4expr.il -> fct_name__5iline ;
__3f = (((struct fct *)(((struct fct *)__3fn -> __O1__4expr.tp ))));
if (__3f -> f_expr__3fct == 0 )
# 602 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 602 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V46 ;

# 602 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V47 ;

# 602 "/home/claude/cfront-3/src/expand.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & __3fn -> where__4name , (const char *)"cannot expand value-returning inline%a with call of non-value-returning inline%a", (const
# 602 "/home/claude/cfront-3/src/expand.cpp"
struct ea *)( (__2__X48 = (const void *)expand_fn ), ( ((& __0__V46 )-> __O1__2ea.p = __2__X48 ), (& __0__V46 )) )
# 602 "/home/claude/cfront-3/src/expand.cpp"
, (const struct ea *)( ((& __0__V47 )-> __O1__2ea.p = ((const void *)__3fn )), (& __0__V47 )) , (const
# 602 "/home/claude/cfront-3/src/expand.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 605 "/home/claude/cfront-3/src/expand.cpp"
ret_seen = __3ors ;

# 605 "/home/claude/cfront-3/src/expand.cpp"
}
}
break ;
case 30 :
# 609 "/home/claude/cfront-3/src/expand.cpp"
case 113 :
# 610 "/home/claude/cfront-3/src/expand.cpp"
case 191 :
# 611 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> __O4__4expr.tp2 )__0this -> __O4__4expr.tp2 -> permanent__4node = 1 ;
goto rrr ;
case 68 :
# 614 "/home/claude/cfront-3/src/expand.cpp"
__0this -> __O4__4expr.cond = expand__4exprFv ( __0this -> __O4__4expr.cond ) ;
default :
# 616 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> __O3__4expr.e2 )__0this -> __O3__4expr.e2 = expand__4exprFv ( __0this -> __O3__4expr.e2 ) ;
case 44 :
# 618 "/home/claude/cfront-3/src/expand.cpp"
case 45 :
# 619 "/home/claude/cfront-3/src/expand.cpp"
rrr :
# 620 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> __O2__4expr.e1 )__0this -> __O2__4expr.e1 = expand__4exprFv ( __0this -> __O2__4expr.e1 ) ;
break ;
}

# 624 "/home/claude/cfront-3/src/expand.cpp"
switch (__0this -> base__4node ){ 
# 625 "/home/claude/cfront-3/src/expand.cpp"
case 71 :
# 626 "/home/claude/cfront-3/src/expand.cpp"
case 147 :
# 627 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> __O1__4expr.tp == 0 )__0this -> __O1__4expr.tp = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;
}

# 630 "/home/claude/cfront-3/src/expand.cpp"
__0this -> permanent__4node = 1 ;
return __0this ;
}

# 634 "/home/claude/cfront-3/src/expand.cpp"
int nin = 0 ;

# 636 "/home/claude/cfront-3/src/expand.cpp"
static int watch_out ;
bit not_simple__4exprFi (struct expr *__0this , int __1inflag );

# 637 "/home/claude/cfront-3/src/expand.cpp"
bit not_simple__4exprFi (register struct expr *__0this , int __1inflag )
# 644 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 645 "/home/claude/cfront-3/src/expand.cpp"
int __1s ;

# 647 "/home/claude/cfront-3/src/expand.cpp"
switch (__0this -> base__4node ){ 
# 648 "/home/claude/cfront-3/src/expand.cpp"
default :
# 649 "/home/claude/cfront-3/src/expand.cpp"
return (unsigned char )2 ;
case 85 :
# 651 "/home/claude/cfront-3/src/expand.cpp"
if ((nin == 0 )&& ((((struct name *)(((struct name *)__0this ))))-> __O4__4expr.n_table == gtbl ))return (unsigned char )2 ;
case 86 :
# 653 "/home/claude/cfront-3/src/expand.cpp"
case 150 :
# 655 "/home/claude/cfront-3/src/expand.cpp"
case 82 :
# 656 "/home/claude/cfront-3/src/expand.cpp"
case 84 :
# 657 "/home/claude/cfront-3/src/expand.cpp"
case 83 :
# 658 "/home/claude/cfront-3/src/expand.cpp"
return (unsigned char )0 ;
case 81 :
# 660 "/home/claude/cfront-3/src/expand.cpp"
watch_out = 1 ;
return (unsigned char )0 ;
case 177 :
# 663 "/home/claude/cfront-3/src/expand.cpp"
return not_simple__4exprFi ( __0this -> __O4__4expr.mem , __1inflag ) ;
case 30 :
# 665 "/home/claude/cfront-3/src/expand.cpp"
return (unsigned char )(((__0this -> __O2__4expr.e1 == 0 )|| (__0this -> __O2__4expr.e1 == dummy ))?0 :(((int )not_simple__4exprFi ( __0this -> __O2__4expr.e1 , __1inflag )
# 665 "/home/claude/cfront-3/src/expand.cpp"
)));
case 145 :
# 667 "/home/claude/cfront-3/src/expand.cpp"
case 112 :
# 668 "/home/claude/cfront-3/src/expand.cpp"
return not_simple__4exprFi ( __0this -> __O3__4expr.e2 , __1inflag ) ;
case 113 :
# 670 "/home/claude/cfront-3/src/expand.cpp"
case 191 :
# 671 "/home/claude/cfront-3/src/expand.cpp"
return not_simple__4exprFi ( __0this -> __O2__4expr.e1 , __1inflag ) ;
case 45 :
# 673 "/home/claude/cfront-3/src/expand.cpp"
case 44 :
# 674 "/home/claude/cfront-3/src/expand.cpp"
watch_out = 1 ;
if (! __1inflag )
# 676 "/home/claude/cfront-3/src/expand.cpp"
return not_simple__4exprFi ( __0this -> __O2__4expr.e1 , __1inflag ) ;
else 
# 678 "/home/claude/cfront-3/src/expand.cpp"
return (unsigned char )2 ;
case 107 :
# 680 "/home/claude/cfront-3/src/expand.cpp"
case 46 :
# 681 "/home/claude/cfront-3/src/expand.cpp"
case 47 :
# 682 "/home/claude/cfront-3/src/expand.cpp"
return not_simple__4exprFi ( __0this -> __O3__4expr.e2 , __1inflag ) ;
case 111 :
# 684 "/home/claude/cfront-3/src/expand.cpp"
__1s = not_simple__4exprFi ( __0this -> __O2__4expr.e1 , __1inflag ) ;
if (1 < __1s )return (unsigned char )2 ;
if (__0this -> __O3__4expr.e2 == 0 )return (unsigned char )__1s ;
return (unsigned char )(__1s |= not_simple__4exprFi ( __0this -> __O3__4expr.e2 , __1inflag ) );
case 50 :
# 689 "/home/claude/cfront-3/src/expand.cpp"
case 51 :
# 690 "/home/claude/cfront-3/src/expand.cpp"
case 53 :
# 691 "/home/claude/cfront-3/src/expand.cpp"
case 54 :
# 692 "/home/claude/cfront-3/src/expand.cpp"
case 55 :
# 693 "/home/claude/cfront-3/src/expand.cpp"
case 56 :
# 694 "/home/claude/cfront-3/src/expand.cpp"
case 57 :
# 695 "/home/claude/cfront-3/src/expand.cpp"
case 52 :
# 696 "/home/claude/cfront-3/src/expand.cpp"
case 65 :
# 697 "/home/claude/cfront-3/src/expand.cpp"
case 64 :
# 698 "/home/claude/cfront-3/src/expand.cpp"
case 58 :
# 699 "/home/claude/cfront-3/src/expand.cpp"
case 59 :
# 700 "/home/claude/cfront-3/src/expand.cpp"
case 60 :
# 701 "/home/claude/cfront-3/src/expand.cpp"
case
# 701 "/home/claude/cfront-3/src/expand.cpp"
61 :
# 702 "/home/claude/cfront-3/src/expand.cpp"
case 62 :
# 703 "/home/claude/cfront-3/src/expand.cpp"
case 63 :
# 704 "/home/claude/cfront-3/src/expand.cpp"
case 66 :
# 705 "/home/claude/cfront-3/src/expand.cpp"
case 67 :
# 706 "/home/claude/cfront-3/src/expand.cpp"
case 71 :
# 707 "/home/claude/cfront-3/src/expand.cpp"
__1s = not_simple__4exprFi ( __0this -> __O2__4expr.e1 , __1inflag ) ;
if (1 < __1s )return (unsigned char )2 ;
return (unsigned char )(__1s |= not_simple__4exprFi ( __0this -> __O3__4expr.e2 , __1inflag ) );
case 68 :
# 711 "/home/claude/cfront-3/src/expand.cpp"
__1s = not_simple__4exprFi ( __0this -> __O4__4expr.cond , __1inflag ) ;
if (1 < __1s )return (unsigned char )2 ;
__1s |= not_simple__4exprFi ( __0this -> __O2__4expr.e1 , __1inflag ) ;
if (1 < __1s )return (unsigned char )2 ;
return (unsigned char )(__1s |= not_simple__4exprFi ( __0this -> __O3__4expr.e2 , __1inflag ) );
case 169 :
# 717 "/home/claude/cfront-3/src/expand.cpp"
if (curr_icall ){ 
# 718 "/home/claude/cfront-3/src/expand.cpp"
Pname __3n ;
int __3argno ;
Pin __3il ;

# 718 "/home/claude/cfront-3/src/expand.cpp"
__3n = (((struct name *)(((struct name *)__0this ))));
__3argno = (((int )__3n -> n_val__4name ));
__3il = curr_icall ;
for(;__3il ;__3il = __3il -> i_next__5iline ) 
# 722 "/home/claude/cfront-3/src/expand.cpp"
if (__3n -> __O4__4expr.n_table == __3il -> i_table__5iline )goto aok ;
goto bok ;
aok :
# 725 "/home/claude/cfront-3/src/expand.cpp"
return (unsigned char )((__3il -> i_args__5iline [__3argno ]). local__2ia ?0 :(((int )not_simple__4exprFi ( (__3il -> i_args__5iline [__3argno ]). arg__2ia , __1inflag ) )));
}
bok :{ 
# 727 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V49 ;

# 727 "/home/claude/cfront-3/src/expand.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"expand aname%n", (const struct ea *)( ((&
# 727 "/home/claude/cfront-3/src/expand.cpp"
__0__V49 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V49 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 727 "/home/claude/cfront-3/src/expand.cpp"
(const struct ea *)ea0 ) ;
case 147 :
# 729 "/home/claude/cfront-3/src/expand.cpp"
case 157 :
# 730 "/home/claude/cfront-3/src/expand.cpp"
case 23 :
# 731 "/home/claude/cfront-3/src/expand.cpp"
case 184 :
# 732 "/home/claude/cfront-3/src/expand.cpp"
case 109 :
# 733 "/home/claude/cfront-3/src/expand.cpp"
case 146 :
# 734 "/home/claude/cfront-3/src/expand.cpp"
case 168 :
# 735 "/home/claude/cfront-3/src/expand.cpp"
case 70 :
# 736 "/home/claude/cfront-3/src/expand.cpp"
case 48 :
# 737 "/home/claude/cfront-3/src/expand.cpp"
case 49 :
# 738 "/home/claude/cfront-3/src/expand.cpp"
case 126 :
# 739 "/home/claude/cfront-3/src/expand.cpp"
case 127 :
# 740 "/home/claude/cfront-3/src/expand.cpp"
case 128 :
# 741 "/home/claude/cfront-3/src/expand.cpp"
case
# 741 "/home/claude/cfront-3/src/expand.cpp"
129 :
# 742 "/home/claude/cfront-3/src/expand.cpp"
case 130 :
# 743 "/home/claude/cfront-3/src/expand.cpp"
case 131 :
# 744 "/home/claude/cfront-3/src/expand.cpp"
case 132 :
# 745 "/home/claude/cfront-3/src/expand.cpp"
case 133 :
# 746 "/home/claude/cfront-3/src/expand.cpp"
case 134 :
# 747 "/home/claude/cfront-3/src/expand.cpp"
case 135 :
# 748 "/home/claude/cfront-3/src/expand.cpp"
return (unsigned char )2 ;
} }
}

# 755 "/home/claude/cfront-3/src/expand.cpp"
extern Pstmt del_list ;
extern Pstmt break_del_list ;
extern Pstmt continue_del_list ;
extern Pname curr_fct ;
extern Pexpr init_list ;

# 471 "/home/claude/cfront-3/src/cfront.h"
Pname make_itor__8classdefFi (struct classdef *__0this , int );

# 762 "/home/claude/cfront-3/src/expand.cpp"
void expand_itor__FP8classdef (Pclass __1cl )
# 763 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 765 "/home/claude/cfront-3/src/expand.cpp"
Pexpr __1s2 ;
Pstmt __1s5 ;
Pstmt __1s6 ;
Pstmt __1s7 ;
Pname __1s8 ;
Pexpr __1s9 ;

# 765 "/home/claude/cfront-3/src/expand.cpp"
__1s2 = curr_expr ;
__1s5 = del_list ;
__1s6 = break_del_list ;
__1s7 = continue_del_list ;
__1s8 = curr_fct ;
__1s9 = init_list ;
((void )make_itor__8classdefFi ( __1cl , 1 ) );
curr_expr = __1s2 ;
del_list = __1s5 ;
break_del_list = __1s6 ;
continue_del_list = __1s7 ;
curr_fct = __1s8 ;
init_list = __1s9 ;
}

# 752 "/home/claude/cfront-3/src/expand.cpp"
extern void uninline__FP4name (Pname __0fn );

# 818 "/home/claude/cfront-3/src/expand.cpp"
Pexpr expand__3fctFP4nameP5tableP4expr (struct fct *__0this , Pname __1fn , Ptable __1scope , Pexpr __1ll );

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 477 "/home/claude/cfront-3/src/cfront.h"
void print_all_vtbls__8classdefFP8classdef (struct classdef *__0this , Pclass );

# 1180 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 1171 "/home/claude/cfront-3/src/cfront.h"

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 234 "/home/claude/cfront-3/src/cfront.h"

# 342 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr__4typeFv (struct type *__0this );

# 1249 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr mptr_assign__FP4exprT1 (Pexpr , Pexpr );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 1042 "/home/claude/cfront-3/src/cfront.h"

# 1068 "/home/claude/cfront-3/src/cfront.h"

# 1171 "/home/claude/cfront-3/src/cfront.h"
static struct ia *__ct__2iaFv (struct ia *__0this );

# 1 ""
extern void __dl__FPv (void *);

# 818 "/home/claude/cfront-3/src/expand.cpp"
Pexpr expand__3fctFP4nameP5tableP4expr (register struct fct *__0this , Pname __1fn , Ptable __1scope , Pexpr __1ll )
# 826 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 827 "/home/claude/cfront-3/src/expand.cpp"
Scope = __1scope ;

# 829 "/home/claude/cfront-3/src/expand.cpp"
if (__0this -> f_inline__3fct == 77 ){ 
# 830 "/home/claude/cfront-3/src/expand.cpp"
Pexpr __2s1 ;

# 830 "/home/claude/cfront-3/src/expand.cpp"
__2s1 = __0this -> last_expanded__3fct ;
expand_itor__FP8classdef ( __0this -> memof__3fct ) ;
__0this -> last_expanded__3fct = __2s1 ;
__0this -> last_stmt__3fct = stmtno ;

# 835 "/home/claude/cfront-3/src/expand.cpp"
{ Pfct __2nf ;

# 835 "/home/claude/cfront-3/src/expand.cpp"
__2nf = (((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))));
if ((__2nf -> f_inline__3fct == 0 )&& __2nf -> f_imeasure__3fct ){ 
# 837 "/home/claude/cfront-3/src/expand.cpp"
uninline__FP4name ( __1fn ) ;
return (struct expr *)0 ;
}
return expand__3fctFP4nameP5tableP4expr ( __2nf , __1fn , __1scope , __1ll ) ;

# 840 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 846 "/home/claude/cfront-3/src/expand.cpp"
if (((((__0this -> body__3fct == 0 )&& (__0this -> f_expr__3fct == 0 ))|| ((__0this -> defined__4type & 02 )== 0 ))|| ((((struct fct *)(((struct fct *)__1fn ->
# 846 "/home/claude/cfront-3/src/expand.cpp"
__O1__4expr.tp ))))-> body__3fct -> memtbl__4stmt == __1scope ))|| (__0this -> f_inline__3fct > 1 ))
# 850 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 853 "/home/claude/cfront-3/src/expand.cpp"
extern Pfct current_fct_instantiation ;

# 851 "/home/claude/cfront-3/src/expand.cpp"
if (warning_opt ){ 
# 851 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V50 ;

# 851 "/home/claude/cfront-3/src/expand.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"cannot inline%n in thisE", (const struct ea *)( ((&
# 851 "/home/claude/cfront-3/src/expand.cpp"
__0__V50 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V50 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 851 "/home/claude/cfront-3/src/expand.cpp"
(const struct ea *)ea0 ) ;
} 
# 853 "/home/claude/cfront-3/src/expand.cpp"
;
if (__0this -> fct_base__3fct == 4)
# 855 "/home/claude/cfront-3/src/expand.cpp"
current_fct_instantiation = __0this ;
if ((__1fn -> n_addr_taken__4name ++ )== 0 )dcl_print__4nameFUc ( __1fn , (unsigned char )0 ) ;
if (__0this -> fct_base__3fct == 4)
# 858 "/home/claude/cfront-3/src/expand.cpp"
current_fct_instantiation = 0 ;
return (struct expr *)0 ;
}

# 862 "/home/claude/cfront-3/src/expand.cpp"
if (__1fn -> n_oper__4name == 161 ){ 
# 863 "/home/claude/cfront-3/src/expand.cpp"
Pclass __2cl ;

# 863 "/home/claude/cfront-3/src/expand.cpp"
__2cl = (((struct classdef *)(((struct classdef *)__1fn -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))));
if (__2cl -> c_body__8classdef == 3 )print_all_vtbls__8classdefFP8classdef ( __2cl , __2cl ) ;
}

# 867 "/home/claude/cfront-3/src/expand.cpp"
{ Pin __1il ;
Pexpr __1ic ;
int __1ns ;

# 870 "/home/claude/cfront-3/src/expand.cpp"
struct iline *__0__X64 ;

# 870 "/home/claude/cfront-3/src/expand.cpp"
struct node *__0__X11 ;

# 870 "/home/claude/cfront-3/src/expand.cpp"
struct texpr *__0__X65 ;

# 867 "/home/claude/cfront-3/src/expand.cpp"
__1il = ( (__0__X64 = 0 ), ( ((__0__X64 || (__0__X64 = (struct iline *)__nw__FUl ( (unsigned long )(sizeof (struct iline))) ))?(
# 867 "/home/claude/cfront-3/src/expand.cpp"
(__0__X64 = (struct iline *)( (__0__X11 = (((struct node *)__0__X64 ))), ( ((__0__X11 || (__0__X11 = (struct node *)__nw__FUl ( (unsigned long )(sizeof
# 867 "/home/claude/cfront-3/src/expand.cpp"
(struct node))) ))?( ( (__0__X11 -> base__4node = 0 ), (__0__X11 -> permanent__4node = 0 )) , (__0__X11 -> baseclass__4node = 0 )) :0 ),
# 867 "/home/claude/cfront-3/src/expand.cpp"
__0__X11 ) ) ), (__0__X64 -> base__4node = 202 )) :0 ), __0__X64 ) ) ;
__1ic = (struct expr *)( (__0__X65 = 0 ), ( ((__0__X65 || (__0__X65 = (struct texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr)))
# 868 "/home/claude/cfront-3/src/expand.cpp"
))?( (__0__X65 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X65 ), ((unsigned char )168 ), ((struct expr *)0 ), (struct expr *)0 ) ),
# 868 "/home/claude/cfront-3/src/expand.cpp"
(__0__X65 -> __O4__4expr.tp2 = ((struct type *)0 ))) :0 ), __0__X65 ) ) ;
__1ns = 0 ;
{ { Pname __1an ;

# 870 "/home/claude/cfront-3/src/expand.cpp"
__1an = __0this -> f_args__3fct ;

# 870 "/home/claude/cfront-3/src/expand.cpp"
for(;__1an ;__1an = __1an -> __O1__4name.n_list ) __1ns ++ ;
__1il -> fct_name__5iline = __1fn ;
__1il -> i_slots__5iline = __1ns ;
__1il -> i_args__5iline = (struct ia *)(__1ns ?(((struct ia *)__vec_new ( ((void *)0 ), __1ns , sizeof (struct ia ), ((void *)__ct__2iaFv )) )):(((struct
# 873 "/home/claude/cfront-3/src/expand.cpp"
ia *)0 )));
__1ic -> __O4__4expr.il = __1il ;
__1ic -> __O1__4expr.tp = (__0this -> s_returns__3fct ?__0this -> s_returns__3fct :__0this -> returns__3fct );

# 877 "/home/claude/cfront-3/src/expand.cpp"
{ Pname __1at ;

# 877 "/home/claude/cfront-3/src/expand.cpp"
__1at = __0this -> f_args__3fct ;

# 879 "/home/claude/cfront-3/src/expand.cpp"
__0this -> f_inline__3fct ++ ;

# 881 "/home/claude/cfront-3/src/expand.cpp"
if (__1at )__1il -> i_table__5iline = __1at -> __O4__4expr.n_table ;
{ int __1i ;
int __1not_simple ;

# 885 "/home/claude/cfront-3/src/expand.cpp"
Pname __1n ;

# 882 "/home/claude/cfront-3/src/expand.cpp"
__1i = 0 ;
__1not_simple = 0 ;

# 885 "/home/claude/cfront-3/src/expand.cpp"
__1n = __1at ;
for(;__1n && __1ll ;( (__1n = __1n -> __O1__4name.n_list ), (__1i ++ )) ) { 
# 891 "/home/claude/cfront-3/src/expand.cpp"
Pexpr __2ee ;

# 904 "/home/claude/cfront-3/src/expand.cpp"
int __2s ;

# 893 "/home/claude/cfront-3/src/expand.cpp"
if (__1ll -> base__4node == 140 ){ 
# 894 "/home/claude/cfront-3/src/expand.cpp"
__2ee = __1ll -> __O2__4expr.e1 ;
__1ll = __1ll -> __O3__4expr.e2 ;
}
else { 
# 898 "/home/claude/cfront-3/src/expand.cpp"
__2ee = __1ll ;
__1ll = 0 ;
}

# 903 "/home/claude/cfront-3/src/expand.cpp"
(__1il -> i_args__5iline [__1i ]). local__2ia = 0 ;
;

# 907 "/home/claude/cfront-3/src/expand.cpp"
{ { Pname __2m ;

# 907 "/home/claude/cfront-3/src/expand.cpp"
__2m = __1at ;

# 907 "/home/claude/cfront-3/src/expand.cpp"
for(;__2m ;__2m = __2m -> __O1__4name.n_list ) { 
# 908 "/home/claude/cfront-3/src/expand.cpp"
Pptr __3p ;
if (__1n != __2m ){ 
# 911 "/home/claude/cfront-3/src/expand.cpp"
if (__3p = is_ptr_or_ref__4typeFv ( __2m -> __O1__4expr.tp ) )
# 912 "/home/claude/cfront-3/src/expand.cpp"
if ((check__4typeFP4typeUcT2 ( (struct type *)__3p , __1n -> __O1__4expr.tp ,
# 912 "/home/claude/cfront-3/src/expand.cpp"
(unsigned char )0 , (unsigned char )0 ) == 0 )|| (check__4typeFP4typeUcT2 ( __3p -> typ__5pvtyp , __1n -> __O1__4expr.tp , (unsigned
# 912 "/home/claude/cfront-3/src/expand.cpp"
char )0 , (unsigned char )0 ) == 0 ))goto zxc ;

# 914 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 917 "/home/claude/cfront-3/src/expand.cpp"
watch_out = 0 ;
{ int __2notsimple ;

# 918 "/home/claude/cfront-3/src/expand.cpp"
__2notsimple = not_simple__4exprFi ( __2ee , 1 ) ;
if ((((__2notsimple == 0 )&& watch_out )&& (__1n -> n_used__4name > 1 ))&& (__2ee -> base__4node != 145 ))goto zxc ;
if (((__1n -> n_assigned_to__4name == 11111 )&& (__2ee != zero ))&& (__2notsimple == 0 ))
# 922 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 923 "/home/claude/cfront-3/src/expand.cpp"
if (((__2ee && __2ee -> __O2__4expr.e1 )&& (__2ee -> __O2__4expr.e1 ->
# 923 "/home/claude/cfront-3/src/expand.cpp"
base__4node == 85 ))&& (! strcmp ( __2ee -> __O2__4expr.e1 -> __O2__4expr.string , (const char *)"this")
# 923 "/home/claude/cfront-3/src/expand.cpp"
))
# 924 "/home/claude/cfront-3/src/expand.cpp"
goto zxc ;
}
else if (__1n -> n_addr_taken__4name || __1n -> n_assigned_to__4name )
# 927 "/home/claude/cfront-3/src/expand.cpp"
goto zxc ;
else if (__2s = __2notsimple ){ 
# 929 "/home/claude/cfront-3/src/expand.cpp"
if ((1 < __2s )|| (1 < __1n -> n_used__4name ))
# 931 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 932 "/home/claude/cfront-3/src/expand.cpp"
zxc :
# 933 "/home/claude/cfront-3/src/expand.cpp"
if (((__0this -> last_expanded__3fct && (__0this ->
# 933 "/home/claude/cfront-3/src/expand.cpp"
last_expanded__3fct != dummy ))&& (__0this -> last_expanded__3fct == curr_expr ))&& (__0this -> last_stmt__3fct == stmtno )){ 
# 934 "/home/claude/cfront-3/src/expand.cpp"
if (warning_opt )
# 935 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 935 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V51 ;

# 935 "/home/claude/cfront-3/src/expand.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%a not inlined, called twice in an expression", (const struct ea *)( ((&
# 935 "/home/claude/cfront-3/src/expand.cpp"
__0__V51 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V51 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 935 "/home/claude/cfront-3/src/expand.cpp"
(const struct ea *)ea0 ) ;
} __0this -> f_inline__3fct -- ;
__vec_delete ( ((void *)__1il -> i_args__5iline ), -1, sizeof (struct ia ), ((void *)0 ), 1, 0) ;
__dl__FPv ( (void *)__1il ) ;

# 940 "/home/claude/cfront-3/src/expand.cpp"
{ extern Pfct current_fct_instantiation ;
if (__0this -> fct_base__3fct == 4)
# 942 "/home/claude/cfront-3/src/expand.cpp"
current_fct_instantiation = __0this ;
if ((__1fn -> n_addr_taken__4name ++ )== 0 )dcl_print__4nameFUc ( __1fn , (unsigned char )0 ) ;
if (__0this -> fct_base__3fct == 4)
# 945 "/home/claude/cfront-3/src/expand.cpp"
current_fct_instantiation = 0 ;
return (struct expr *)0 ;

# 946 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 952 "/home/claude/cfront-3/src/expand.cpp"
{ Pname __4nn ;

# 952 "/home/claude/cfront-3/src/expand.cpp"
__4nn = dcl_local__FP5tableP4nameT2Uc ( __1scope , __1n , __1fn , (unsigned char )1 ) ;
__4nn -> base__4node = 85 ;
(__1il -> i_args__5iline [__1i ]). local__2ia = __4nn ;
++ __1not_simple ;

# 955 "/home/claude/cfront-3/src/expand.cpp"
}

# 960 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 963 "/home/claude/cfront-3/src/expand.cpp"
(__1il -> i_args__5iline [__1i ]). arg__2ia = __2ee ;
(__1il -> i_args__5iline [__1i ]). tp__2ia = __1n -> __O1__4expr.tp ;

# 964 "/home/claude/cfront-3/src/expand.cpp"
}

# 964 "/home/claude/cfront-3/src/expand.cpp"
}

# 964 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 967 "/home/claude/cfront-3/src/expand.cpp"
{ Ptable __1tbl ;

# 967 "/home/claude/cfront-3/src/expand.cpp"
__1tbl = __0this -> body__3fct -> memtbl__4stmt ;
if (__0this -> f_expr__3fct ){ 
# 970 "/home/claude/cfront-3/src/expand.cpp"
char __2loc_var ;

# 971 "/home/claude/cfront-3/src/expand.cpp"
int __2__X53 ;

# 971 "/home/claude/cfront-3/src/expand.cpp"
int __2__X54 ;

# 970 "/home/claude/cfront-3/src/expand.cpp"
__2loc_var = 0 ;

# 973 "/home/claude/cfront-3/src/expand.cpp"
for(__1n = ( (__2__X53 = (__1i = 1 )), ( (((__2__X53 <= 0 )|| (__1tbl -> free_slot__5table <= __2__X53 ))?(((struct name *)0 )):(__1tbl -> entries__5table [__2__X53 ]))) )
# 973 "/home/claude/cfront-3/src/expand.cpp"
;__1n ;__1n = (__1n -> n_tbl_list__4name ?__1n -> n_tbl_list__4name :( (__2__X54 = (++ __1i )), ( (((__2__X54 <= 0 )|| (__1tbl -> free_slot__5table <= __2__X54 ))?(((struct name *)0 )):(__1tbl ->
# 973 "/home/claude/cfront-3/src/expand.cpp"
entries__5table [__2__X54 ]))) ) )) { 
# 976 "/home/claude/cfront-3/src/expand.cpp"
if (((__1n -> base__4node == 85 )&& ((__1n -> __O1__4expr.tp -> base__4node != 108 )&& (__1n -> __O1__4expr.tp ->
# 976 "/home/claude/cfront-3/src/expand.cpp"
base__4node != 76 )))&& ((__1n -> n_used__4name || __1n -> n_assigned_to__4name )|| __1n -> n_addr_taken__4name ))
# 978 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 979 "/home/claude/cfront-3/src/expand.cpp"
if ((__0this -> last_expanded__3fct && (__0this -> last_expanded__3fct == curr_expr ))&&
# 979 "/home/claude/cfront-3/src/expand.cpp"
(__0this -> last_stmt__3fct == stmtno )){ 
# 980 "/home/claude/cfront-3/src/expand.cpp"
if (warning_opt ){ 
# 980 "/home/claude/cfront-3/src/expand.cpp"
struct ea __0__V52 ;

# 980 "/home/claude/cfront-3/src/expand.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"cannot inline%n in thisE", (const struct ea *)( ((&
# 980 "/home/claude/cfront-3/src/expand.cpp"
__0__V52 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V52 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 980 "/home/claude/cfront-3/src/expand.cpp"
(const struct ea *)ea0 ) ;
} __0this -> f_inline__3fct -- ;
__vec_delete ( ((void *)__1il -> i_args__5iline ), -1, sizeof (struct ia ), ((void *)0 ), 1, 0) ;
__dl__FPv ( (void *)__1il ) ;
{ extern Pfct current_fct_instantiation ;
if (__0this -> fct_base__3fct == 4)
# 986 "/home/claude/cfront-3/src/expand.cpp"
current_fct_instantiation = __0this ;
if ((__1fn -> n_addr_taken__4name ++ )== 0 )dcl_print__4nameFUc ( __1fn , (unsigned char )0 ) ;
if (__0this -> fct_base__3fct == 4)
# 989 "/home/claude/cfront-3/src/expand.cpp"
current_fct_instantiation = 0 ;
return (struct expr *)0 ;

# 990 "/home/claude/cfront-3/src/expand.cpp"
}
}
{ Pname __4nn ;

# 992 "/home/claude/cfront-3/src/expand.cpp"
__4nn = dcl_local__FP5tableP4nameT2Uc ( __1scope , __1n , __1fn , (unsigned char )0 ) ;
__4nn -> base__4node = 85 ;
__1n -> __O2__4expr.string = __4nn -> __O2__4expr.string ;

# 996 "/home/claude/cfront-3/src/expand.cpp"
__2loc_var ++ ;

# 996 "/home/claude/cfront-3/src/expand.cpp"
}
}
}

# 1000 "/home/claude/cfront-3/src/expand.cpp"
if (__1i || __2loc_var ){ 
# 1001 "/home/claude/cfront-3/src/expand.cpp"
if (! curr_expr )curr_expr = dummy ;
__0this -> last_expanded__3fct = curr_expr ;
__0this -> last_stmt__3fct = stmtno ;
}

# 1006 "/home/claude/cfront-3/src/expand.cpp"
{ Pexpr __2ex ;
if (__1not_simple ){ 
# 1008 "/home/claude/cfront-3/src/expand.cpp"
Pexpr __3etail ;

# 1008 "/home/claude/cfront-3/src/expand.cpp"
__3etail = (__2ex = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , (struct expr *)0 , (struct expr *)0 ) );
for(__1i = 0 ;__1i < __1il -> i_slots__5iline ;__1i ++ ) { 
# 1010 "/home/claude/cfront-3/src/expand.cpp"
Pname __4n ;

# 1010 "/home/claude/cfront-3/src/expand.cpp"
__4n = (__1il -> i_args__5iline [__1i ]). local__2ia ;
if (__4n == 0 )continue ;
{ Pexpr __4e ;

# 1012 "/home/claude/cfront-3/src/expand.cpp"
__4e = (__1il -> i_args__5iline [__1i ]). arg__2ia ;

# 1016 "/home/claude/cfront-3/src/expand.cpp"
if ((__4n -> n_used__4name || __4n -> n_assigned_to__4name )|| __4n -> n_addr_taken__4name )
# 1018 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 1019 "/home/claude/cfront-3/src/expand.cpp"
Pptr __5p1 ;
Pptr __5p2 ;

# 1019 "/home/claude/cfront-3/src/expand.cpp"
__5p1 = is_ptr__4typeFv ( __4n -> __O1__4expr.tp ) ;
__5p2 = (__4e -> __O1__4expr.tp ?is_ptr__4typeFv ( __4e -> __O1__4expr.tp ) :(((struct ptr *)0 )));
if ((__5p1 && __5p1 -> memof__3ptr )&& (! __5p2 )){ 
# 1022 "/home/claude/cfront-3/src/expand.cpp"
switch (__4e -> base__4node ){ 
# 1023 "/home/claude/cfront-3/src/expand.cpp"
case 71 :
# 1024 "/home/claude/cfront-3/src/expand.cpp"
case 147 :
# 1025 "/home/claude/cfront-3/src/expand.cpp"
__4e -> __O3__4expr.e2 = mptr_assign__FP4exprT1 (
# 1025 "/home/claude/cfront-3/src/expand.cpp"
(struct expr *)__4n , __4e -> __O3__4expr.e2 ) ;
break ;
case 168 :
# 1028 "/home/claude/cfront-3/src/expand.cpp"
break ;
default :
# 1030 "/home/claude/cfront-3/src/expand.cpp"
__4e = mptr_assign__FP4exprT1 ( (struct expr *)__4n , __4e ) ;
}
__3etail -> __O2__4expr.e1 = __4e ;
}
else 
# 1035 "/home/claude/cfront-3/src/expand.cpp"
__3etail -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__4n , __4e ) ;
}
else 
# 1038 "/home/claude/cfront-3/src/expand.cpp"
__3etail -> __O2__4expr.e1 = __4e ;
if (-- __1not_simple )
# 1040 "/home/claude/cfront-3/src/expand.cpp"
__3etail = (__3etail -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , (struct expr *)0 , (struct
# 1040 "/home/claude/cfront-3/src/expand.cpp"
expr *)0 ) );
else 
# 1042 "/home/claude/cfront-3/src/expand.cpp"
break ;

# 1042 "/home/claude/cfront-3/src/expand.cpp"
}
}
__3etail -> __O3__4expr.e2 = __0this -> f_expr__3fct ;
}
else 
# 1047 "/home/claude/cfront-3/src/expand.cpp"
__2ex = __0this -> f_expr__3fct ;
__1ic -> __O2__4expr.e1 = __2ex ;

# 1048 "/home/claude/cfront-3/src/expand.cpp"
}
}
else { 
# 1050 "/home/claude/cfront-3/src/expand.cpp"
int __2__X55 ;

# 1050 "/home/claude/cfront-3/src/expand.cpp"
int __2__X56 ;

# 1051 "/home/claude/cfront-3/src/expand.cpp"
for(__1n = ( (__2__X55 = (__1i = 1 )), ( (((__2__X55 <= 0 )|| (__1tbl -> free_slot__5table <= __2__X55 ))?(((struct name *)0 )):(__1tbl -> entries__5table [__2__X55 ]))) )
# 1051 "/home/claude/cfront-3/src/expand.cpp"
;__1n ;__1n = (__1n -> n_tbl_list__4name ?__1n -> n_tbl_list__4name :( (__2__X56 = (++ __1i )), ( (((__2__X56 <= 0 )|| (__1tbl -> free_slot__5table <= __2__X56 ))?(((struct name *)0 )):(__1tbl ->
# 1051 "/home/claude/cfront-3/src/expand.cpp"
entries__5table [__2__X56 ]))) ) )) { 
# 1053 "/home/claude/cfront-3/src/expand.cpp"
if (((__1n -> base__4node == 85 )&& __1n -> __O1__4expr.tp )&& ((__1n -> n_used__4name || __1n -> n_assigned_to__4name )||
# 1053 "/home/claude/cfront-3/src/expand.cpp"
__1n -> n_addr_taken__4name ))
# 1055 "/home/claude/cfront-3/src/expand.cpp"
{ 
# 1058 "/home/claude/cfront-3/src/expand.cpp"
__1n -> __O2__4expr.string = temp__FPCcP4name ( __1n -> __O2__4expr.string , __1fn ) ;
}
}
{ Pstmt __2ss ;
if (__1not_simple ){ 
# 1063 "/home/claude/cfront-3/src/expand.cpp"
if (! curr_expr )curr_expr = dummy ;
__0this -> last_expanded__3fct = curr_expr ;
__0this -> last_stmt__3fct = stmtno ;
{ Pstmt __3st ;

# 1067 "/home/claude/cfront-3/src/expand.cpp"
struct estmt *__0__X62 ;

# 1067 "/home/claude/cfront-3/src/expand.cpp"
struct loc __2__X63 ;

# 1066 "/home/claude/cfront-3/src/expand.cpp"
__3st = (struct stmt *)( (__0__X62 = 0 ), ( (__2__X63 = curloc ), ( ((__0__X62 || (__0__X62 = (struct estmt *)__nw__4stmtSFUl ( (unsigned
# 1066 "/home/claude/cfront-3/src/expand.cpp"
long )(sizeof (struct estmt))) ))?( (__0__X62 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X62 ), ((unsigned char )72 ), __2__X63 , ((struct
# 1066 "/home/claude/cfront-3/src/expand.cpp"
stmt *)0 )) ), (__0__X62 -> __O2__4stmt.e = ((struct expr *)0 ))) :0 ), __0__X62 ) ) ) ;
__3st -> where__4stmt . line__3loc = 0 ;
{ Pstmt __3stail ;

# 1069 "/home/claude/cfront-3/src/expand.cpp"
register struct block *__0__X59 ;

# 1069 "/home/claude/cfront-3/src/expand.cpp"
struct loc __2__X60 ;

# 1069 "/home/claude/cfront-3/src/expand.cpp"
struct loc __2__X61 ;

# 1068 "/home/claude/cfront-3/src/expand.cpp"
__3stail = __3st ;
for(__1i = 0 ;__1i < __1il -> i_slots__5iline ;__1i ++ ) { 
# 1070 "/home/claude/cfront-3/src/expand.cpp"
Pname __4n ;

# 1070 "/home/claude/cfront-3/src/expand.cpp"
__4n = (__1il -> i_args__5iline [__1i ]). local__2ia ;
if (__4n == 0 )continue ;
{ Pexpr __4e ;
Pptr __4p1 ;
Pptr __4p2 ;

# 1072 "/home/claude/cfront-3/src/expand.cpp"
__4e = (__1il -> i_args__5iline [__1i ]). arg__2ia ;
__4p1 = is_ptr__4typeFv ( __4n -> __O1__4expr.tp ) ;
__4p2 = is_ptr__4typeFv ( __4e -> __O1__4expr.tp ) ;
if ((__4p1 && __4p1 -> memof__3ptr )&& (! __4p2 )){ 
# 1076 "/home/claude/cfront-3/src/expand.cpp"
switch (__4e -> base__4node ){ 
# 1077 "/home/claude/cfront-3/src/expand.cpp"
case 71 :
# 1078 "/home/claude/cfront-3/src/expand.cpp"
case 147 :
# 1079 "/home/claude/cfront-3/src/expand.cpp"
__4e -> __O3__4expr.e2 = mptr_assign__FP4exprT1 (
# 1079 "/home/claude/cfront-3/src/expand.cpp"
(struct expr *)__4n , __4e -> __O3__4expr.e2 ) ;
break ;
default :
# 1082 "/home/claude/cfront-3/src/expand.cpp"
__4e = mptr_assign__FP4exprT1 ( (struct expr *)__4n , __4e ) ;
}
__3stail -> __O2__4stmt.e = __4e ;
}
else 
# 1087 "/home/claude/cfront-3/src/expand.cpp"
__3stail -> __O2__4stmt.e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__4n , __4e ) ;
if (-- __1not_simple ){ 
# 1088 "/home/claude/cfront-3/src/expand.cpp"
struct estmt *__0__X57 ;

# 1088 "/home/claude/cfront-3/src/expand.cpp"
struct loc __2__X58 ;

# 1089 "/home/claude/cfront-3/src/expand.cpp"
__3stail = (__3stail -> s_list__4stmt = (struct stmt *)( (__0__X57 = 0 ), ( (__2__X58 = curloc ), ( ((__0__X57 || (__0__X57 = (struct
# 1089 "/home/claude/cfront-3/src/expand.cpp"
estmt *)__nw__4stmtSFUl ( (unsigned long )(sizeof (struct estmt))) ))?( (__0__X57 = (struct estmt *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X57 ), ((unsigned char )72 ),
# 1089 "/home/claude/cfront-3/src/expand.cpp"
__2__X58 , ((struct stmt *)0 )) ), (__0__X57 -> __O2__4stmt.e = ((struct expr *)0 ))) :0 ), __0__X57 ) ) ) );
__3stail -> where__4stmt . line__3loc = 0 ;
}
else 
# 1093 "/home/claude/cfront-3/src/expand.cpp"
break ;

# 1093 "/home/claude/cfront-3/src/expand.cpp"
}
}
__3stail -> s_list__4stmt = (struct stmt *)__0this -> body__3fct ;
__2ss = (struct stmt *)( (__0__X59 = 0 ), ( (__2__X60 = curloc ), ( (__2__X61 = noloc ), ( ((__0__X59 || (__0__X59 =
# 1096 "/home/claude/cfront-3/src/expand.cpp"
(struct block *)__nw__4stmtSFUl ( (unsigned long )(sizeof (struct block))) ))?(((void )( (__0__X59 = (struct block *)__ct__4stmtFUc3locP4stmt ( ((struct stmt *)__0__X59 ), (unsigned
# 1096 "/home/claude/cfront-3/src/expand.cpp"
char )116 , __2__X60 , __3st ) ), ( (__0__X59 -> __O1__4stmt.d = ((struct name *)0 )), (__0__X59 -> __O3__4stmt.where2 = __2__X61 )) )
# 1096 "/home/claude/cfront-3/src/expand.cpp"
)):(((void )0 ))), __0__X59 ) ) ) ) ;
__2ss -> where__4stmt . line__3loc = 0 ;

# 1097 "/home/claude/cfront-3/src/expand.cpp"
}

# 1097 "/home/claude/cfront-3/src/expand.cpp"
}
}
else 
# 1100 "/home/claude/cfront-3/src/expand.cpp"
__2ss = (struct stmt *)__0this -> body__3fct ;
__1ic -> __O3__4expr.e2 = (((struct expr *)(((struct expr *)__2ss ))));

# 1101 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 1104 "/home/claude/cfront-3/src/expand.cpp"
__0this -> f_inline__3fct -- ;

# 1107 "/home/claude/cfront-3/src/expand.cpp"
return __1ic ;

# 1107 "/home/claude/cfront-3/src/expand.cpp"
}

# 1107 "/home/claude/cfront-3/src/expand.cpp"
}

# 1107 "/home/claude/cfront-3/src/expand.cpp"
}

# 1107 "/home/claude/cfront-3/src/expand.cpp"
}

# 1107 "/home/claude/cfront-3/src/expand.cpp"
}

# 1107 "/home/claude/cfront-3/src/expand.cpp"
}
}

# 1171 "/home/claude/cfront-3/src/cfront.h"
static struct ia *__ct__2iaFv (struct ia *__0this ){ 
# 1171 "/home/claude/cfront-3/src/cfront.h"
struct node *__0__X10 ;

# 1171 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct ia *)__nw__FUl ( (unsigned long )(sizeof (struct ia))) )){ ( ( ( (__0this =
# 1171 "/home/claude/cfront-3/src/cfront.h"
(struct ia *)( (__0__X10 = (((struct node *)__0this ))), ( ((__0__X10 || (__0__X10 = (struct node *)__nw__FUl ( (unsigned long )(sizeof (struct node)))
# 1171 "/home/claude/cfront-3/src/cfront.h"
))?( ( (__0__X10 -> base__4node = 0 ), (__0__X10 -> permanent__4node = 0 )) , (__0__X10 -> baseclass__4node = 0 )) :0 ), __0__X10 )
# 1171 "/home/claude/cfront-3/src/cfront.h"
) ), (__0this -> local__2ia = 0 )) , (__0this -> arg__2ia = 0 )) , (__0this -> tp__2ia = 0 )) ;
# 1171 "/home/claude/cfront-3/src/cfront.h"
__0this -> base__4node = 203 ;
} 
# 1171 "/home/claude/cfront-3/src/cfront.h"
return __0this ;

# 1171 "/home/claude/cfront-3/src/cfront.h"
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

# 1108 "/home/claude/cfront-3/src/expand.cpp"

/* the end */
