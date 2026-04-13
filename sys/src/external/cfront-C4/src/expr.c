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

# 25 "/home/claude/cfront-3/src/expr.cpp"
int const_save = 0 ;
extern int no_const ;
extern Ptype Pfct_type ;

# 30 "/home/claude/cfront-3/src/expr.cpp"
int processing_sizeof = 0 ;

# 32 "/home/claude/cfront-3/src/expr.cpp"
Pexpr address__4exprFv (struct expr *__0this );

# 1234 "/home/claude/cfront-3/src/cfront.h"
extern Pname make_tmp__FcP4typeP5table (char , Ptype , Ptable );
extern Pexpr init_tmp__FP4nameP4exprP5table (Pname , Pexpr , Ptable );

# 807 "/home/claude/cfront-3/src/cfront.h"
bit not_simple__4exprFi (struct expr *__0this , int __1inflag );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 944 "/home/claude/cfront-3/src/cfront.h"
void take_addr__4nameFv (struct name *__0this );

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );

# 715 "/home/claude/cfront-3/src/cfront.h"

# 32 "/home/claude/cfront-3/src/expr.cpp"
Pexpr address__4exprFv (register struct expr *__0this )
# 33 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 36 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> base__4node ){ 
# 36 "/home/claude/cfront-3/src/expr.cpp"
unsigned long __2__X19 ;

# 37 "/home/claude/cfront-3/src/expr.cpp"
case 111 :
# 38 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 == 0 )return __0this -> __O2__4expr.e1 ;
break ;
case 68 :
# 41 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = address__4exprFv ( __0this -> __O2__4expr.e1 ) ;

# 43 "/home/claude/cfront-3/src/expr.cpp"
case 147 :
# 44 "/home/claude/cfront-3/src/expr.cpp"
if (((__0this -> __O2__4expr.e1 && ((__0this -> __O2__4expr.e1 -> base__4node == 146 )|| (__0this -> __O2__4expr.e1 -> base__4node == 109 )))&& __0this -> __O3__4expr.e2 )&&
# 44 "/home/claude/cfront-3/src/expr.cpp"
(__0this -> __O3__4expr.e2 -> base__4node == 145 ))
# 46 "/home/claude/cfront-3/src/expr.cpp"
return __0this ;
case 71 :
# 48 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 && (__0this -> __O3__4expr.e2 -> base__4node == 146 )){ 
# 49 "/home/claude/cfront-3/src/expr.cpp"
Pname __3tmp ;

# 49 "/home/claude/cfront-3/src/expr.cpp"
__3tmp = make_tmp__FcP4typeP5table ( 'Q' , __0this -> __O3__4expr.e2 -> __O1__4expr.tp , cc -> ftbl__11dcl_context ) ;
__0this -> __O3__4expr.e2 = init_tmp__FP4nameP4exprP5table ( __3tmp , __0this -> __O3__4expr.e2 , cc -> ftbl__11dcl_context ) ;
{ Pexpr __3aa ;

# 51 "/home/claude/cfront-3/src/expr.cpp"
__3aa = address__4exprFv ( (struct expr *)__3tmp ) ;
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __0this -> __O3__4expr.e2 , __3aa ) ;
__0this -> __O3__4expr.e2 -> __O1__4expr.tp = __3aa -> __O1__4expr.tp ;

# 53 "/home/claude/cfront-3/src/expr.cpp"
}
}
else __0this -> __O3__4expr.e2 = address__4exprFv ( __0this -> __O3__4expr.e2 ) ;
__0this -> __O1__4expr.tp = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;
return __0this ;
case 48 :
# 59 "/home/claude/cfront-3/src/expr.cpp"
case 49 :
# 60 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O2__4expr.e1 )break ;
nin ++ ;
if (not_simple__4exprFi ( __0this -> __O3__4expr.e2 , 0 ) ){ 
# 62 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V17 ;

# 62 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"& of%k", (const struct ea *)( (__2__X19 =
# 62 "/home/claude/cfront-3/src/expr.cpp"
__0this -> base__4node ), ( (( ((& __0__V17 )-> __O1__2ea.i = __2__X19 ), 0 ) ), (& __0__V17 )) ) ,
# 62 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} nin -- ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , (struct expr *)0 , __0this -> __O3__4expr.e2 ) ;
__0this -> __O3__4expr.e2 = address__4exprFv ( __0this -> __O3__4expr.e2 ) ;
__0this -> base__4node = 147 ;
__0this -> __O1__4expr.tp = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;
return __0this ;
case 70 :
# 70 "/home/claude/cfront-3/src/expr.cpp"
case 126 :
# 71 "/home/claude/cfront-3/src/expr.cpp"
case 127 :
# 72 "/home/claude/cfront-3/src/expr.cpp"
case 128 :
# 73 "/home/claude/cfront-3/src/expr.cpp"
case 129 :
# 74 "/home/claude/cfront-3/src/expr.cpp"
case 130 :
# 75 "/home/claude/cfront-3/src/expr.cpp"
case 131 :
# 76 "/home/claude/cfront-3/src/expr.cpp"
case 132 :
# 77 "/home/claude/cfront-3/src/expr.cpp"
case 133 :
# 78 "/home/claude/cfront-3/src/expr.cpp"
case 134 :
# 79 "/home/claude/cfront-3/src/expr.cpp"
case 135 :
# 80 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 80 "/home/claude/cfront-3/src/expr.cpp"
unsigned long
# 80 "/home/claude/cfront-3/src/expr.cpp"
__2__X20 ;

# 81 "/home/claude/cfront-3/src/expr.cpp"
nin ++ ;
if (not_simple__4exprFi ( __0this -> __O2__4expr.e1 , 0 ) ){ 
# 82 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V18 ;

# 82 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"& of%k", (const struct ea *)( (__2__X20 =
# 82 "/home/claude/cfront-3/src/expr.cpp"
__0this -> base__4node ), ( (( ((& __0__V18 )-> __O1__2ea.i = __2__X20 ), 0 ) ), (& __0__V18 )) ) ,
# 82 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} nin -- ;
{ Pexpr __3a ;

# 84 "/home/claude/cfront-3/src/expr.cpp"
__3a = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , __0this -> __O2__4expr.e1 , __0this -> __O3__4expr.e2 ) ;
__3a -> __O1__4expr.tp = __3a -> __O2__4expr.e1 -> __O1__4expr.tp ;
__0this -> base__4node = 147 ;
__0this -> __O2__4expr.e1 = __3a ;
__0this -> __O3__4expr.e2 = address__4exprFv ( __3a -> __O2__4expr.e1 ) ;
__0this -> __O1__4expr.tp = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;
return __0this ;

# 90 "/home/claude/cfront-3/src/expr.cpp"
}
}
case 85 :
# 93 "/home/claude/cfront-3/src/expr.cpp"
take_addr__4nameFv ( ((struct name *)(((struct name *)__0this )))) ;
if ((((struct name *)(((struct name *)__0this ))))-> n_xref__4name )
# 97 "/home/claude/cfront-3/src/expr.cpp"
return __0this ;
break ;
case 109 :
# 100 "/home/claude/cfront-3/src/expr.cpp"
case 113 :
# 101 "/home/claude/cfront-3/src/expr.cpp"
case 191 :
# 102 "/home/claude/cfront-3/src/expr.cpp"
case 23 :
# 103 "/home/claude/cfront-3/src/expr.cpp"
case 184 :
# 104 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O1__4expr.tp && is_ptr_or_ref__4typeFv ( __0this -> __O1__4expr.tp ) ){ 
# 105 "/home/claude/cfront-3/src/expr.cpp"
return __0this ;
# 105 "/home/claude/cfront-3/src/expr.cpp"

# 106 "/home/claude/cfront-3/src/expr.cpp"
}
break ;
}

# 110 "/home/claude/cfront-3/src/expr.cpp"
{ Pexpr __1ee ;

# 110 "/home/claude/cfront-3/src/expr.cpp"
__1ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __0this ) ;
if (__0this -> __O1__4expr.tp ){ 
# 111 "/home/claude/cfront-3/src/expr.cpp"
struct type *__0__X21 ;

# 112 "/home/claude/cfront-3/src/expr.cpp"
__1ee -> __O1__4expr.tp = (struct type *)( (__0__X21 = __0this -> __O1__4expr.tp ), ( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 ,
# 112 "/home/claude/cfront-3/src/expr.cpp"
__0__X21 ) ) ) ;

# 114 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O1__4expr.tp -> base__4node ){ 
# 115 "/home/claude/cfront-3/src/expr.cpp"
case 125 :
# 116 "/home/claude/cfront-3/src/expr.cpp"
(((struct ptr *)(((struct ptr *)__1ee -> __O1__4expr.tp ))))-> memof__3ptr = (((struct ptr *)(((struct ptr *)__0this -> __O1__4expr.tp ))))->
# 116 "/home/claude/cfront-3/src/expr.cpp"
memof__3ptr ;
break ;
case 108 :
# 119 "/home/claude/cfront-3/src/expr.cpp"
if ((((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_static__3fct == 0 )
# 120 "/home/claude/cfront-3/src/expr.cpp"
(((struct ptr *)(((struct ptr *)__1ee -> __O1__4expr.tp ))))-> memof__3ptr = (((struct fct *)(((struct
# 120 "/home/claude/cfront-3/src/expr.cpp"
fct *)__0this -> __O1__4expr.tp ))))-> memof__3fct ;
break ;
case 76 :
# 123 "/home/claude/cfront-3/src/expr.cpp"
if ((((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__0this -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ))))-> f_static__3fct == 0 )
# 124 "/home/claude/cfront-3/src/expr.cpp"
(((struct ptr *)(((struct
# 124 "/home/claude/cfront-3/src/expr.cpp"
ptr *)__1ee -> __O1__4expr.tp ))))-> memof__3ptr = (((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__0this -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ))))-> memof__3fct ;
}
}

# 128 "/home/claude/cfront-3/src/expr.cpp"
return __1ee ;

# 128 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 359 "/home/claude/cfront-3/src/cfront.h"
Pfct memptr__4typeFv (struct type *__0this );

# 848 "/home/claude/cfront-3/src/cfront.h"

# 131 "/home/claude/cfront-3/src/expr.cpp"
Pexpr make_dot__FP4exprP5tablePCc (Pexpr __1e , Ptable __1tbl , const char *__1c )
# 132 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 133 "/home/claude/cfront-3/src/expr.cpp"
if (! memptr__4typeFv ( __1e -> __O1__4expr.tp ) )
# 134 "/home/claude/cfront-3/src/expr.cpp"
return __1e ;

# 136 "/home/claude/cfront-3/src/expr.cpp"
if ((((__1e -> base__4node == 71 )|| (__1e -> base__4node == 146 ))|| (__1e -> base__4node == 109 ))|| (__1e -> base__4node == 70 )){ 
# 137 "/home/claude/cfront-3/src/expr.cpp"
Pname __2atmp ;
# 137 "/home/claude/cfront-3/src/expr.cpp"

# 138 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __2as ;

# 139 "/home/claude/cfront-3/src/expr.cpp"
register struct mdot *__0__X22 ;

# 137 "/home/claude/cfront-3/src/expr.cpp"
__2atmp = make_tmp__FcP4typeP5table ( 'A' , __1e -> __O1__4expr.tp , __1tbl ) ;
__2as = init_tmp__FP4nameP4exprP5table ( __2atmp , __1e , __1tbl ) ;
__1e = (struct expr *)( (__0__X22 = 0 ), ( ((__0__X22 || (__0__X22 = (struct mdot *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct mdot)))
# 139 "/home/claude/cfront-3/src/expr.cpp"
))?( (__0__X22 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X22 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 139 "/home/claude/cfront-3/src/expr.cpp"
( (__0__X22 -> __O3__4expr.string2 = __1c ), (__0__X22 -> __O4__4expr.mem = ((struct expr *)__2atmp ))) ) :0 ), __0__X22 ) ) ;
__1e -> __O2__4expr.i1 = 9 ;
__1e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __2as , __1e ) ;
}
else if (__1e -> base__4node == 124 ){ 
# 144 "/home/claude/cfront-3/src/expr.cpp"
if ((__1c [0 ])== 'i' )__1e = __1e -> __O2__4expr.e1 -> __O3__4expr.e2 ;
if ((__1c [0 ])== 'f' )__1e = __1e -> __O3__4expr.e2 ;
}
else { 
# 147 "/home/claude/cfront-3/src/expr.cpp"
register struct mdot *__0__X23 ;

# 148 "/home/claude/cfront-3/src/expr.cpp"
__1e = (struct expr *)( (__0__X23 = 0 ), ( ((__0__X23 || (__0__X23 = (struct mdot *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct mdot)))
# 148 "/home/claude/cfront-3/src/expr.cpp"
))?( (__0__X23 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X23 ), (unsigned char )177 , (struct expr *)0 , (struct expr *)0 ) ),
# 148 "/home/claude/cfront-3/src/expr.cpp"
( (__0__X23 -> __O3__4expr.string2 = __1c ), (__0__X23 -> __O4__4expr.mem = __1e )) ) :0 ), __0__X23 ) ) ;
__1e -> __O2__4expr.i1 = 9 ;
}
return __1e ;
}

# 154 "/home/claude/cfront-3/src/expr.cpp"
Pexpr contents__4exprFv (struct expr *__0this );

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 449 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8classdefFP4name (struct classdef *__0this , Pname );

# 154 "/home/claude/cfront-3/src/expr.cpp"
Pexpr contents__4exprFv (register struct expr *__0this )
# 155 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 157 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> base__4node ){ 
# 158 "/home/claude/cfront-3/src/expr.cpp"
case 112 :
# 159 "/home/claude/cfront-3/src/expr.cpp"
case 145 :
# 160 "/home/claude/cfront-3/src/expr.cpp"
return __0this -> __O3__4expr.e2 ;
case 140 :
# 163 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = contents__4exprFv ( __0this -> __O2__4expr.e1 ) ;
__0this -> __O1__4expr.tp = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
return __0this ;
}

# 166 "/home/claude/cfront-3/src/expr.cpp"
;

# 168 "/home/claude/cfront-3/src/expr.cpp"
{ Pexpr __1ee ;

# 168 "/home/claude/cfront-3/src/expr.cpp"
__1ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __0this , (struct expr *)0 ) ;
if (__0this -> __O1__4expr.tp ){ 
# 170 "/home/claude/cfront-3/src/expr.cpp"
Ptype __2tt ;

# 170 "/home/claude/cfront-3/src/expr.cpp"
__2tt = skiptypedefs__4typeFv ( __0this -> __O1__4expr.tp ) ;
__1ee -> __O1__4expr.tp = (((struct ptr *)(((struct ptr *)__2tt ))))-> typ__5pvtyp ;
{ Pname __2cn ;

# 172 "/home/claude/cfront-3/src/expr.cpp"
__2cn = is_cl_obj__4typeFv ( __1ee -> __O1__4expr.tp ) ;
if (__2cn ){ 
# 175 "/home/claude/cfront-3/src/expr.cpp"
Pclass __3cl ;

# 175 "/home/claude/cfront-3/src/expr.cpp"
__3cl = (((struct classdef *)(((struct classdef *)__2cn -> __O1__4expr.tp ))));
if (__3cl -> c_body__8classdef == 1 )dcl_print__8classdefFP4name ( __3cl , (struct name *)0 ) ;
}

# 177 "/home/claude/cfront-3/src/expr.cpp"
}
}
return __1ee ;

# 179 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 276 "/home/claude/cfront-3/src/expr.cpp"
int bound = 0 ;
int chars_in_largest = 0 ;
int chars_in_largestl = 0 ;
int chars_in_largestll = 0 ;

# 1259 "/home/claude/cfront-3/src/cfront.h"

# 958 "/home/claude/cfront-3/src/cfront.h"

# 282 "/home/claude/cfront-3/src/expr.cpp"
static bit ptr_is_template_formal__FP3ptr (Pptr __1p )
# 283 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 286 "/home/claude/cfront-3/src/expr.cpp"
if (__1p -> typ__5pvtyp ){ 
# 287 "/home/claude/cfront-3/src/expr.cpp"
if (__1p -> typ__5pvtyp -> base__4node != 97 )return (unsigned char )0 ;
{ Pname __2n ;

# 289 "/home/claude/cfront-3/src/expr.cpp"
struct type *__0__X24 ;

# 288 "/home/claude/cfront-3/src/expr.cpp"
__2n = ( (__0__X24 = __1p -> typ__5pvtyp ), ( (((struct basetype *)(((struct basetype *)__0__X24 ))))-> b_name__8basetype ) ) ;
return ( (((unsigned char )(__2n -> n_template_arg__4name == 1)))) ;

# 289 "/home/claude/cfront-3/src/expr.cpp"
}
}
else return (unsigned char )0 ;
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 458 "/home/claude/cfront-3/src/cfront.h"
bit has_friend__8classdefFP3fct (struct classdef *__0this , Pfct );

# 457 "/home/claude/cfront-3/src/cfront.h"
bit has_friend__8classdefFP8classdef (struct classdef *__0this , Pclass );

# 460 "/home/claude/cfront-3/src/cfront.h"
bit has_base__8classdefFP8classdefiT2 (struct classdef *__0this , Pclass __1cl , int __1level , int __1ccflag );

# 579 "/home/claude/cfront-3/src/cfront.h"
struct basetype *__ct__8basetypeFUcP4name (struct basetype *__0this , TOK , Pname );

# 294 "/home/claude/cfront-3/src/expr.cpp"
Ptype common_base__FP8classdefT1 (Pclass __1cl1 , Pclass __1cl2 )
# 298 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 299 "/home/claude/cfront-3/src/expr.cpp"
if ((__1cl1 == 0 )|| (__1cl2 == 0 ))return (struct type *)0 ;
if ((__1cl1 -> baselist__8classdef == 0 )|| (__1cl2 -> baselist__8classdef == 0 ))return (struct type *)0 ;
{ Pbase __1answer ;

# 301 "/home/claude/cfront-3/src/expr.cpp"
__1answer = 0 ;

# 303 "/home/claude/cfront-3/src/expr.cpp"
{ { Pbcl __1b ;

# 303 "/home/claude/cfront-3/src/expr.cpp"
__1b = __1cl1 -> baselist__8classdef ;

# 303 "/home/claude/cfront-3/src/expr.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 303 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__1__X25 ;

# 303 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__1__X26 ;

# 304 "/home/claude/cfront-3/src/expr.cpp"
if ((((__1b -> ppp__6basecl != 25 )&& (! ( (__1__X25 = cc -> cot__11dcl_context ), ( (__1__X26 = __1cl1 ), ( ((__1__X25 ==
# 304 "/home/claude/cfront-3/src/expr.cpp"
__1__X26 )?1 :((__1__X25 && __1__X26 )?(((int )same_class__8classdefFP8classdefi ( __1__X25 , __1__X26 , 0 ) )):0 ))) ) ) ))&& ((cc -> nof__11dcl_context == 0 )|| (has_friend__8classdefFP3fct (
# 304 "/home/claude/cfront-3/src/expr.cpp"
__1cl1 , ((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp )))) == 0 )))&& ((cc -> cot__11dcl_context == 0 )|| (has_friend__8classdefFP8classdef ( __1cl1 , cc ->
# 304 "/home/claude/cfront-3/src/expr.cpp"
cot__11dcl_context ) == 0 )))
# 310 "/home/claude/cfront-3/src/expr.cpp"
continue ;
Nvis = 0 ;
if (has_base__8classdefFP8classdefiT2 ( __1cl2 , __1b -> bclass__6basecl , 0 , 0 ) ){ 
# 313 "/home/claude/cfront-3/src/expr.cpp"
if (Nvis )continue ;
if (__1answer )return (struct type *)0 ;
{ Pname __3bn ;

# 315 "/home/claude/cfront-3/src/expr.cpp"
__3bn = __ct__4nameFPCc ( (struct name *)0 , __1b -> bclass__6basecl -> string__8classdef ) ;
__3bn -> __O1__4expr.tp = (struct type *)__1b -> bclass__6basecl ;
__1answer = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )119 , __3bn ) ;

# 317 "/home/claude/cfront-3/src/expr.cpp"
}
}
}
return (struct type *)__1answer ;

# 320 "/home/claude/cfront-3/src/expr.cpp"
}

# 320 "/home/claude/cfront-3/src/expr.cpp"
}

# 320 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 113 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_name__FPCcP6ktableUc (const char *, Pktab , TOK );

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 114 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_member__FPCcP8classdefUc (const char *, Pclass , TOK );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 324 "/home/claude/cfront-3/src/expr.cpp"
static Pexpr do_qualifiers__FP4typeP4expr (Ptype __1t , Pexpr __1mem )
# 329 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 331 "/home/claude/cfront-3/src/expr.cpp"
Pname __1m ;

# 331 "/home/claude/cfront-3/src/expr.cpp"
__1m = (((struct name *)(((struct name *)__1mem ))));
if ((((__1m -> base__4node != 85 )&& (__1m -> base__4node != 162 ))|| (__1m -> __O2__4name.n_qualifier == 0 ))|| (__1m -> __O2__4name.n_qualifier -> base__4node != 176 ))
# 335 "/home/claude/cfront-3/src/expr.cpp"
return
# 335 "/home/claude/cfront-3/src/expr.cpp"
__1mem ;
{ Pname __1cn ;
Pname __1tn ;
Pname __1q ;

# 336 "/home/claude/cfront-3/src/expr.cpp"
__1cn = (__1t ?is_cl_obj__4typeFv ( __1t ) :(((struct name *)0 )));
__1tn = 0 ;
__1q = __1m -> __O2__4name.n_qualifier ;
__1m -> __O2__4name.n_qualifier = 0 ;
if (__1q -> __O2__4expr.string == 0 ){ 
# 342 "/home/claude/cfront-3/src/expr.cpp"
do { 
# 343 "/home/claude/cfront-3/src/expr.cpp"
Pname __3qx ;

# 343 "/home/claude/cfront-3/src/expr.cpp"
__3qx = __1q -> __O1__4name.n_list ;
( (__1q ?(((void )(__1q ?(((void )( ( ((((struct expr *)__1q ))?(((void )((((struct expr *)__1q ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 344 "/home/claude/cfront-3/src/expr.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1q , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
__1q = __3qx ;
}
while (__1q && (__1q -> __O2__4expr.string == 0 ));

# 347 "/home/claude/cfront-3/src/expr.cpp"
if (__1q == 0 ){ __1m -> __O3__4expr.n_initializer = (struct expr *)sta_name ;

# 347 "/home/claude/cfront-3/src/expr.cpp"
return __1mem ;

# 347 "/home/claude/cfront-3/src/expr.cpp"
}
__1tn = k_find_name__FPCcP6ktableUc ( __1q -> __O2__4expr.string , Gtbl , (unsigned char )159 ) ;
}
else 
# 349 "/home/claude/cfront-3/src/expr.cpp"
if (__1cn )
# 350 "/home/claude/cfront-3/src/expr.cpp"
__1tn = k_find_name__FPCcP6ktableUc ( __1q -> __O2__4expr.string , (((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))))-> k_tbl__8classdef , (unsigned char )159 )
# 350 "/home/claude/cfront-3/src/expr.cpp"
;
else 
# 352 "/home/claude/cfront-3/src/expr.cpp"
__1tn = k_find_name__FPCcP6ktableUc ( __1q -> __O2__4expr.string , Ctbl , (unsigned char )159 ) ;

# 368 "/home/claude/cfront-3/src/expr.cpp"
{ Pname __1cx ;

# 368 "/home/claude/cfront-3/src/expr.cpp"
__1cx = 0 ;
for(;;) { 
# 370 "/home/claude/cfront-3/src/expr.cpp"
if (__1tn == 0 ){ 
# 371 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 371 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V27 ;

# 371 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V28 ;

# 371 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n :: --TN%n not found", (const struct ea *)( ((& __0__V27 )-> __O1__2ea.p =
# 371 "/home/claude/cfront-3/src/expr.cpp"
((const void *)__1q )), (& __0__V27 )) , (const struct ea *)( ((& __0__V28 )-> __O1__2ea.p = ((const void
# 371 "/home/claude/cfront-3/src/expr.cpp"
*)__1q )), (& __0__V28 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return __1mem ;
} }
__1cn = is_cl_obj__4typeFv ( __1tn -> __O1__4expr.tp ) ;
if (__1cn == 0 ){ 
# 380 "/home/claude/cfront-3/src/expr.cpp"
if ((__1q -> __O1__4name.n_list == 0 )&& (__1m -> base__4node == 162 ))
# 381 "/home/claude/cfront-3/src/expr.cpp"
__1m -> __O2__4name.n_qualifier = __1tn ;
else 
# 383 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 383 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V29 ;

# 383 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V30 ;

# 383 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n :: --%n is not aCN", (const struct ea *)( ((& __0__V29 )-> __O1__2ea.p =
# 383 "/home/claude/cfront-3/src/expr.cpp"
((const void *)__1tn )), (& __0__V29 )) , (const struct ea *)( ((& __0__V30 )-> __O1__2ea.p = ((const void
# 383 "/home/claude/cfront-3/src/expr.cpp"
*)__1tn )), (& __0__V30 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} return __1mem ;
}
if (__1cx ){ 
# 387 "/home/claude/cfront-3/src/expr.cpp"
if (has_base__8classdefFP8classdefiT2 ( ((struct classdef *)(((struct classdef *)__1cx -> __O1__4expr.tp ))), ((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))), 0 , 0 )
# 387 "/home/claude/cfront-3/src/expr.cpp"
)
# 388 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 388 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V31 ;

# 388 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V32 ;

# 388 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V33 ;

# 388 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V34 ;

# 388 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n ::%n :: --%n not aM of%n", (const struct ea *)( ((& __0__V31 )-> __O1__2ea.p =
# 388 "/home/claude/cfront-3/src/expr.cpp"
((const void *)__1cx )), (& __0__V31 )) , (const struct ea *)( ((& __0__V32 )-> __O1__2ea.p = ((const void
# 388 "/home/claude/cfront-3/src/expr.cpp"
*)__1cn )), (& __0__V32 )) , (const struct ea *)( ((& __0__V33 )-> __O1__2ea.p = ((const void *)__1cn )), (&
# 388 "/home/claude/cfront-3/src/expr.cpp"
__0__V33 )) , (const struct ea *)( ((& __0__V34 )-> __O1__2ea.p = ((const void *)__1cx )), (& __0__V34 )) )
# 388 "/home/claude/cfront-3/src/expr.cpp"
;
} }
__1cx = __1cn ;
{ Pname __3qx ;

# 391 "/home/claude/cfront-3/src/expr.cpp"
__3qx = __1q -> __O1__4name.n_list ;

# 391 "/home/claude/cfront-3/src/expr.cpp"
( (__1q ?(((void )(__1q ?(((void )( ( ((((struct expr *)__1q ))?(((void )((((struct expr *)__1q ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 391 "/home/claude/cfront-3/src/expr.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1q , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 391 "/home/claude/cfront-3/src/expr.cpp"
__1q = __3qx ;

# 391 "/home/claude/cfront-3/src/expr.cpp"
}
if (__1q == 0 )break ;
if (__1q -> __O2__4expr.string == 0 ){ 
# 394 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"scope qualification syntax") ;
return __1mem ;
}
__1tn = k_find_member__FPCcP8classdefUc ( __1q -> __O2__4expr.string , ((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))), (unsigned char )159 ) ;
}
__1m -> __O2__4name.n_qualifier = __1tn ;
return __1mem ;

# 400 "/home/claude/cfront-3/src/expr.cpp"
}

# 400 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 328 "/home/claude/cfront-3/src/cfront.h"
Pclass classtype__4typeFv (struct type *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 120 "/home/claude/cfront-3/src/cfront.h"
extern const char *oper_name__FUc (TOK );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 404 "/home/claude/cfront-3/src/expr.cpp"
static Pexpr do_dtor__FP4typeP4expr (Ptype __1t , Pexpr __1mem )
# 405 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 406 "/home/claude/cfront-3/src/expr.cpp"
Pname __1m ;

# 419 "/home/claude/cfront-3/src/expr.cpp"
Pname __1q ;
Pname __1d ;
Pname __1cn ;

# 406 "/home/claude/cfront-3/src/expr.cpp"
__1m = (((struct name *)(((struct name *)__1mem ))));

# 419 "/home/claude/cfront-3/src/expr.cpp"
__1q = __1m -> __O2__4name.n_qualifier ;
__1d = __1m -> __O1__4name.n_dtag ;
__1cn = (__1t ?is_cl_obj__4typeFv ( __1t ) :(((struct name *)0 )));

# 426 "/home/claude/cfront-3/src/expr.cpp"
;
if (__1cn ){ 
# 429 "/home/claude/cfront-3/src/expr.cpp"
if (__1d && __1d -> __O2__4expr.string ){ 
# 430 "/home/claude/cfront-3/src/expr.cpp"
Pclass __3cl ;

# 433 "/home/claude/cfront-3/src/expr.cpp"
Pname __3dx ;

# 430 "/home/claude/cfront-3/src/expr.cpp"
__3cl = ((__1q && is_cl_obj__4typeFv ( __1q -> __O1__4expr.tp ) )?classtype__4typeFv ( skiptypedefs__4typeFv ( __1q -> __O1__4expr.tp ) ) :(((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp )))));
# 430 "/home/claude/cfront-3/src/expr.cpp"

# 433 "/home/claude/cfront-3/src/expr.cpp"
__3dx = k_find_name__FPCcP6ktableUc ( __1d -> __O2__4expr.string , __3cl -> k_tbl__8classdef , (unsigned char )159 ) ;
if (__3dx == 0 ){ { 
# 434 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V35 ;

# 434 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V36 ;

# 434 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"TN%n not found in%t", (const struct ea *)( ((& __0__V35 )-> __O1__2ea.p =
# 434 "/home/claude/cfront-3/src/expr.cpp"
((const void *)__1d )), (& __0__V35 )) , (const struct ea *)( ((& __0__V36 )-> __O1__2ea.p = ((const void
# 434 "/home/claude/cfront-3/src/expr.cpp"
*)__1t )), (& __0__V36 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 434 "/home/claude/cfront-3/src/expr.cpp"
__3dx = __1q ;
} 
# 434 "/home/claude/cfront-3/src/expr.cpp"
}
__1d = (__1m -> __O1__4name.n_dtag = __3dx );
}
}

# 440 "/home/claude/cfront-3/src/expr.cpp"
;
if (__1q ){ 
# 442 "/home/claude/cfront-3/src/expr.cpp"
if (__1d && check__4typeFP4typeUcT2 ( __1d -> __O1__4expr.tp , __1q -> __O1__4expr.tp , (unsigned char )0 , (unsigned char
# 442 "/home/claude/cfront-3/src/expr.cpp"
)0 ) ){ 
# 443 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"bad syntax for destructor call:N andQr do not match") ;
__1q = __1d ;
}
else 
# 445 "/home/claude/cfront-3/src/expr.cpp"
if (__1m -> __O3__4expr.tpdef && check__4typeFP4typeUcT2 ( __1m -> __O3__4expr.tpdef , __1q -> __O1__4expr.tp , (unsigned char )0 , (unsigned char
# 445 "/home/claude/cfront-3/src/expr.cpp"
)0 ) )
# 446 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"bad syntax for destructor call:N andQr do not match") ;
if (__1d && is_cl_obj__4typeFv ( __1d -> __O1__4expr.tp ) ){ 
# 448 "/home/claude/cfront-3/src/expr.cpp"
real_dtor :
# 449 "/home/claude/cfront-3/src/expr.cpp"
__1m -> base__4node = 85 ;

# 451 "/home/claude/cfront-3/src/expr.cpp"
__1m -> __O1__4expr.tp = (__1m -> __O3__4expr.tpdef = (__1m -> __O4__4expr.tp2 = 0 ));
__1m -> __O2__4expr.string = oper_name__FUc ( (unsigned char )162 ) ;
__1m -> n_oper__4name = 162 ;
}
else 
# 454 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 455 "/home/claude/cfront-3/src/expr.cpp"
if (__1m -> __O3__4expr.tpdef )__1m -> __O4__4expr.tp2 = __1m -> __O3__4expr.tpdef ;
else __1m -> __O4__4expr.tp2 = (__1m -> __O3__4expr.tpdef = __1q -> __O1__4expr.tp );
__1m -> __O2__4name.n_qualifier = (__1m -> __O1__4name.n_dtag = 0 );
}
}
else { 
# 461 "/home/claude/cfront-3/src/expr.cpp"
if ((__1d && (__1m -> __O4__4expr.tp2 == 0 ))&& is_cl_obj__4typeFv ( __1d -> __O1__4expr.tp ) ){ 
# 462 "/home/claude/cfront-3/src/expr.cpp"
goto real_dtor ;
}
if ((__1d && __1m -> __O4__4expr.tp2 )&& check__4typeFP4typeUcT2 ( __1d -> __O1__4expr.tp , __1m -> __O4__4expr.tp2 , (unsigned char )0 , (unsigned char
# 464 "/home/claude/cfront-3/src/expr.cpp"
)0 ) )
# 465 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"bad syntax for destructor call:N andQr do not match") ;
if (__1d ){ __1m -> __O4__4expr.tp2 = (__1m -> __O3__4expr.tpdef = __1d -> __O1__4expr.tp );

# 466 "/home/claude/cfront-3/src/expr.cpp"
__1m -> __O1__4name.n_dtag = 0 ;

# 466 "/home/claude/cfront-3/src/expr.cpp"
}
}
;

# 473 "/home/claude/cfront-3/src/expr.cpp"
if (__1t ){ 
# 474 "/home/claude/cfront-3/src/expr.cpp"
if (__1mem -> __O4__4expr.tp2 ){ 
# 477 "/home/claude/cfront-3/src/expr.cpp"
if (check__4typeFP4typeUcT2 ( __1t , __1mem -> __O4__4expr.tp2 , (unsigned char )0 , (unsigned
# 477 "/home/claude/cfront-3/src/expr.cpp"
char )0 ) ){ 
# 477 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X40 ;

# 478 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 478 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V37 ;

# 478 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"T mismatch for simpleT destructor:XO ofT%t", (const struct ea *)( (__2__X40 = (const void
# 478 "/home/claude/cfront-3/src/expr.cpp"
*)__1mem -> __O4__4expr.tp2 ), ( ((& __0__V37 )-> __O1__2ea.p = __2__X40 ), (& __0__V37 )) ) , (const struct ea *)ea0 ,
# 478 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
else 
# 480 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 481 "/home/claude/cfront-3/src/expr.cpp"
if (__1cn ){ 
# 484 "/home/claude/cfront-3/src/expr.cpp"
if (__1d && check__4typeFP4typeUcT2 ( __1t , __1d -> __O1__4expr.tp , (unsigned char )0 ,
# 484 "/home/claude/cfront-3/src/expr.cpp"
(unsigned char )0 ) ){ 
# 487 "/home/claude/cfront-3/src/expr.cpp"
Pname __5dn ;

# 487 "/home/claude/cfront-3/src/expr.cpp"
__5dn = (__1d -> __O1__4expr.tp ?is_cl_obj__4typeFv ( __1d -> __O1__4expr.tp ) :(((struct name *)0 )));
if (__1cn && __5dn ){ 
# 489 "/home/claude/cfront-3/src/expr.cpp"
if ((! __1q )&& (! has_base__8classdefFP8classdefiT2 ( ((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))), ((struct classdef *)(((struct
# 489 "/home/claude/cfront-3/src/expr.cpp"
classdef *)__5dn -> __O1__4expr.tp ))), 0 , 0 ) )){ 
# 495 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"bad syntax for destructor call") ;
# 495 "/home/claude/cfront-3/src/expr.cpp"

# 496 "/home/claude/cfront-3/src/expr.cpp"
}
}
else 
# 497 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 497 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X41 ;

# 498 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 498 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V38 ;

# 498 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"T mismatch for destructor:XO ofT%t", (const struct ea *)( (__2__X41 = (const void
# 498 "/home/claude/cfront-3/src/expr.cpp"
*)__1d -> __O1__4expr.tp ), ( ((& __0__V38 )-> __O1__2ea.p = __2__X41 ), (& __0__V38 )) ) , (const struct ea *)ea0 ,
# 498 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
}
else 
# 501 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 501 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X42 ;

# 502 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 502 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V39 ;

# 502 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"T mismatch for destructor:XO ofT%t", (const struct ea *)( (__2__X42 = (const void
# 502 "/home/claude/cfront-3/src/expr.cpp"
*)__1d -> __O1__4expr.tp ), ( ((& __0__V39 )-> __O1__2ea.p = __2__X42 ), (& __0__V39 )) ) , (const struct ea *)ea0 ,
# 502 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
}
return __1mem ;
}

# 512 "/home/claude/cfront-3/src/expr.cpp"
Pname Ntmp_flag_list = 0 ;
bit in_quest = 0 ;
struct con_dtor *pdlist = 0 ;

# 76 "/home/claude/cfront-3/src/cfront.h"

# 516 "/home/claude/cfront-3/src/expr.cpp"
Pexpr typ__4exprFP5table (struct expr *__0this , Ptable __1tbl );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 19 "/home/claude/incl-linux32/string.h"
extern char *strdup (const char *);

# 1210 "/home/claude/cfront-3/src/cfront.h"
extern int c_strlen__FPCc (const char *__0s );

# 693 "/home/claude/cfront-3/src/cfront.h"
static struct vec *__ct__3vecFP4typeP4expr (register struct vec *__0this , Ptype __2t , Pexpr __2e ){ 
# 693 "/home/claude/cfront-3/src/cfront.h"
struct pvtyp *__0__X7 ;

# 693 "/home/claude/cfront-3/src/cfront.h"
struct type *__0__X6 ;

# 693 "/home/claude/cfront-3/src/cfront.h"
struct node *__0__X1 ;

# 693 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct vec *)__nw__3vecSFUl ( (unsigned long )(sizeof (struct vec))) )){ __0this = (struct vec *)( (__0__X7 =
# 693 "/home/claude/cfront-3/src/cfront.h"
(((struct pvtyp *)__0this ))), ( ((__0__X7 || (__0__X7 = (struct pvtyp *)__nw__FUl ( (unsigned long )(sizeof (struct pvtyp))) ))?(__0__X7 = (struct pvtyp *)(
# 693 "/home/claude/cfront-3/src/cfront.h"
(__0__X6 = (((struct type *)__0__X7 ))), ( ((__0__X6 || (__0__X6 = (struct type *)__nw__FUl ( (unsigned long )(sizeof (struct type))) ))?( (
# 693 "/home/claude/cfront-3/src/cfront.h"
( ( ( ( ( ( (__0__X6 = (struct type *)( (__0__X1 = (((struct node *)__0__X6 ))), ( ((__0__X1 ||
# 693 "/home/claude/cfront-3/src/cfront.h"
(__0__X1 = (struct node *)__nw__FUl ( (unsigned long )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 -> permanent__4node =
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

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 824 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 537 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr find_name__FP4nameP8classdefP5tableiT1 (Pname , Pclass , Ptable , int , Pname );

# 325 "/home/claude/cfront-3/src/cfront.h"
Ptype mkconst__4typeFv (struct type *__0this );

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 345 "/home/claude/cfront-3/src/cfront.h"
void dcl__4typeFP5table (struct type *__0this , Ptable );

# 794 "/home/claude/cfront-3/src/cfront.h"
void del__4exprFv (struct expr *__0this );

# 346 "/home/claude/cfront-3/src/cfront.h"
int tsizeof__4typeFi (struct type *__0this , int );

# 810 "/home/claude/cfront-3/src/cfront.h"
Pexpr docast__4exprFP5table (struct expr *__0this , Ptable );
Pexpr dovalue__4exprFP5table (struct expr *__0this , Ptable );
Pexpr donew__4exprFP5table (struct expr *__0this , Ptable );

# 1155 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr try_to_coerce__FP4typeP4exprPCcP5table (Ptype , Pexpr , const char *, Ptable );

# 354 "/home/claude/cfront-3/src/cfront.h"

# 352 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 335 "/home/claude/cfront-3/src/cfront.h"
Ptype skiptypedefs__4typeFRUc (struct type *__0this , bit *__1isconst );

# 122 "/home/claude/cfront-3/src/cfront.h"
extern int is_probably_temp__FPCc (const char *);

# 465 "/home/claude/cfront-3/src/cfront.h"
Pname has_oper__8classdefFUc (struct classdef *__0this , TOK );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 832 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 1229 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr call_dtor__FP4exprN21iT1 (Pexpr __0p , Pexpr __0dtor , Pexpr __0arg , int __0d , Pexpr __0vb_args );

# 1188 "/home/claude/cfront-3/src/cfront.h"

# 809 "/home/claude/cfront-3/src/cfront.h"
Pexpr oper_overload__4exprFP5table (struct expr *__0this , Ptable );

# 1188 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 844 "/home/claude/cfront-3/src/cfront.h"

# 832 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 802 "/home/claude/cfront-3/src/cfront.h"
Ptype call_fct__4exprFP5table (struct expr *__0this , Ptable );

# 356 "/home/claude/cfront-3/src/cfront.h"
Ptype deref__4typeFv (struct type *__0this );

# 355 "/home/claude/cfront-3/src/cfront.h"
bit vec_type__4typeFv (struct type *__0this );

# 740 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr check_cond__FP4exprUcP5table (Pexpr , TOK , Ptable );

# 352 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 801 "/home/claude/cfront-3/src/cfront.h"
int lval__4exprFUc (struct expr *__0this , TOK );

# 715 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 353 "/home/claude/cfront-3/src/cfront.h"

# 354 "/home/claude/cfront-3/src/cfront.h"

# 352 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 354 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 353 "/home/claude/cfront-3/src/cfront.h"

# 1157 "/home/claude/cfront-3/src/cfront.h"
extern Ptype np_promote__FUcN21P4typeT4N21 (TOK , TOK , TOK , Ptype , Ptype , TOK , bit );

# 354 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 352 "/home/claude/cfront-3/src/cfront.h"

# 354 "/home/claude/cfront-3/src/cfront.h"

# 799 "/home/claude/cfront-3/src/cfront.h"
long long eval__4exprFv (struct expr *__0this );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 741 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ptof__FP3fctP4exprP5table (Pfct , Pexpr , Ptable );

# 354 "/home/claude/cfront-3/src/cfront.h"

# 342 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr__4typeFv (struct type *__0this );

# 1248 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr cast_cptr__FP8classdefP4exprP5tablei (Pclass __0ccl , Pexpr __0ee , Ptable __0tbl , int __0real_cast );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 354 "/home/claude/cfront-3/src/cfront.h"

# 1249 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr mptr_assign__FP4exprT1 (Pexpr , Pexpr );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 354 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 354 "/home/claude/cfront-3/src/cfront.h"

# 353 "/home/claude/cfront-3/src/cfront.h"

# 352 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 1227 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ptr_init__FP3ptrP4exprP5table (Pptr , Pexpr , Ptable );

# 1156 "/home/claude/cfront-3/src/cfront.h"
extern bit can_coerce__FP4typeT1 (Ptype , Ptype );

# 509 "/home/claude/cfront-3/src/cfront.h"
void clear__5clistFv (struct clist *__0this );

# 1241 "/home/claude/cfront-3/src/cfront.h"
extern int is_unique_base__FP8classdefPCciT3T1 (Pclass , const char *, int , int , Pclass __0priSeen );

# 1232 "/home/claude/cfront-3/src/cfront.h"
extern int make_assignment__FP4name (Pname );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 489 "/home/claude/cfront-3/src/cfront.h"
bit has_const_mem__8classdefFv (struct classdef *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 718 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 693 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFUl (struct ea *__0this , size_t __2ii );

# 516 "/home/claude/cfront-3/src/expr.cpp"
Pexpr typ__4exprFP5table (register struct expr *__0this , Ptable __1tbl )
# 522 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 523 "/home/claude/cfront-3/src/expr.cpp"
Pname __1n ;
Ptype __1t ;
Ptype __1t1 ;

# 525 "/home/claude/cfront-3/src/expr.cpp"
Ptype __1t2 ;
TOK __1b ;
TOK __1r1 ;

# 527 "/home/claude/cfront-3/src/expr.cpp"
TOK __1r2 ;

# 528 "/home/claude/cfront-3/src/expr.cpp"
unsigned long __2__X90 ;

# 524 "/home/claude/cfront-3/src/expr.cpp"
__1t = 0 ;

# 526 "/home/claude/cfront-3/src/expr.cpp"
__1b = __0this -> base__4node ;

# 528 "/home/claude/cfront-3/src/expr.cpp"
if (__1tbl -> base__4node != 142 ){ 
# 528 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V43 ;

# 528 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"expr::typ(%d)", (const struct ea *)( (__2__X90 =
# 528 "/home/claude/cfront-3/src/expr.cpp"
__1tbl -> base__4node ), ( (( ((& __0__V43 )-> __O1__2ea.i = __2__X90 ), 0 ) ), (& __0__V43 )) ) ,
# 528 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 533 "/home/claude/cfront-3/src/expr.cpp"
;

# 537 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O1__4expr.tp ){ 
# 538 "/home/claude/cfront-3/src/expr.cpp"
switch (__1b ){ 
# 539 "/home/claude/cfront-3/src/expr.cpp"
case 85 :
# 540 "/home/claude/cfront-3/src/expr.cpp"
break ;
case 177 :
# 542 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O4__4expr.mem = typ__4exprFP5table ( __0this -> __O4__4expr.mem , __1tbl ) ;
}

# 543 "/home/claude/cfront-3/src/expr.cpp"
;
return __0this ;
}

# 547 "/home/claude/cfront-3/src/expr.cpp"
switch (__1b ){ 
# 547 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X91 ;

# 547 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X92 ;

# 547 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X93 ;

# 548 "/home/claude/cfront-3/src/expr.cpp"
case 177 :
# 549 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 549 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V44 ;

# 549 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"mdot %s", (const struct ea *)( (__2__X91 =
# 549 "/home/claude/cfront-3/src/expr.cpp"
(const void *)__0this -> __O3__4expr.string2 ), ( ((& __0__V44 )-> __O1__2ea.p = __2__X91 ), (& __0__V44 )) ) , (const
# 549 "/home/claude/cfront-3/src/expr.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
case 144 :
# 551 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"emptyE") ;
__0this -> __O1__4expr.tp = (struct type *)any_type ;
case 162 :
# 554 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 555 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __3e ;

# 555 "/home/claude/cfront-3/src/expr.cpp"
__3e = do_dtor__FP4typeP4expr ( (struct type *)0 , __0this ) ;
return ((__3e -> base__4node == 85 )?typ__4exprFP5table ( __3e , __1tbl ) :__3e );
}

# 559 "/home/claude/cfront-3/src/expr.cpp"
case 86 :
# 560 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)zero_type ;
return __0this ;

# 563 "/home/claude/cfront-3/src/expr.cpp"
case 150 :
# 564 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)int_type ;
return __0this ;

# 567 "/home/claude/cfront-3/src/expr.cpp"
case 82 :
# 573 "/home/claude/cfront-3/src/expr.cpp"
{ int __3ll ;

# 573 "/home/claude/cfront-3/src/expr.cpp"
char *__3str_tmp ;

# 573 "/home/claude/cfront-3/src/expr.cpp"
__3ll = strlen ( __0this -> __O2__4expr.string ) ;

# 575 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O2__4expr.string [(__3ll - 1 )]){ 
# 576 "/home/claude/cfront-3/src/expr.cpp"
case 'l' :
# 577 "/home/claude/cfront-3/src/expr.cpp"
case 'L' :
# 578 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O2__4expr.string [(__3ll - 2 )]){ 
# 579 "/home/claude/cfront-3/src/expr.cpp"
case 'u' :
# 580 "/home/claude/cfront-3/src/expr.cpp"
case 'U' :
# 581 "/home/claude/cfront-3/src/expr.cpp"
__3str_tmp = strdup (
# 581 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.string ) ;
(__3str_tmp [(__3ll - 2 )])= 0 ;

# 584 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.string = (const char *)__3str_tmp ;
ulng :
# 586 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)ulong_type ;
goto cast_n_save ;
case 'l' :
# 589 "/home/claude/cfront-3/src/expr.cpp"
case 'L' :
# 590 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O2__4expr.string [(__3ll - 3 )]){ 
# 591 "/home/claude/cfront-3/src/expr.cpp"
case 'u' :
# 592 "/home/claude/cfront-3/src/expr.cpp"
case 'U' :
# 593 "/home/claude/cfront-3/src/expr.cpp"
__3str_tmp = strdup ( __0this -> __O2__4expr.string ) ;
(__3str_tmp [(__3ll - 3 )])= 0 ;

# 596 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.string = (const char *)__3str_tmp ;
ullng :
# 598 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)ullong_type ;
goto cast_n_save ;
}
llng :
# 602 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)llong_type ;
goto save ;
}
lng :
# 606 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)long_type ;
goto save ;
case 'u' :
# 609 "/home/claude/cfront-3/src/expr.cpp"
case 'U' :
# 610 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O2__4expr.string [(__3ll - 2 )]){ 
# 611 "/home/claude/cfront-3/src/expr.cpp"
case 'l' :
# 612 "/home/claude/cfront-3/src/expr.cpp"
case 'L' :
# 613 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O2__4expr.string [(__3ll - 3 )]){ 
# 614 "/home/claude/cfront-3/src/expr.cpp"
case 'l' :
# 615 "/home/claude/cfront-3/src/expr.cpp"
case
# 615 "/home/claude/cfront-3/src/expr.cpp"
'L' :
# 616 "/home/claude/cfront-3/src/expr.cpp"
__3str_tmp = strdup ( __0this -> __O2__4expr.string ) ;
(__3str_tmp [(__3ll - 3 )])= 0 ;

# 619 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.string = (const char *)__3str_tmp ;
goto ullng ;
}
__3str_tmp = strdup ( __0this -> __O2__4expr.string ) ;
(__3str_tmp [(__3ll - 2 )])= 0 ;

# 625 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.string = (const char *)__3str_tmp ;
goto ulng ;
default :
# 628 "/home/claude/cfront-3/src/expr.cpp"
__3str_tmp = strdup ( __0this -> __O2__4expr.string ) ;
(__3str_tmp [(__3ll - 1 )])= 0 ;

# 631 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.string = (const char *)__3str_tmp ;
labuint :
# 633 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)uint_type ;
goto cast_n_save ;
}
}

# 639 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> __O2__4expr.string [0 ])== '0' ){ 
# 640 "/home/claude/cfront-3/src/expr.cpp"
int __4index ;

# 640 "/home/claude/cfront-3/src/expr.cpp"
__4index = 1 ;
switch (__0this -> __O2__4expr.string [1 ]){ 
# 642 "/home/claude/cfront-3/src/expr.cpp"
case 'x' :
# 643 "/home/claude/cfront-3/src/expr.cpp"
case 'X' :
# 644 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 645 "/home/claude/cfront-3/src/expr.cpp"
while ((__0this -> __O2__4expr.string [(++ __4index )])== '0' );
__3ll -= __4index ;
{ int __6HSZ ;

# 647 "/home/claude/cfront-3/src/expr.cpp"
__6HSZ = (SZ_INT + SZ_INT );
if (__3ll < __6HSZ )goto nrm ;
if (__3ll == __6HSZ )
# 650 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> __O2__4expr.string [2 ])>= '8' )goto labuint ;
else goto nrm ;
if (SZ_INT == SZ_LLONG )break ;
__6HSZ = (SZ_LONG + SZ_LONG );
if (__3ll < __6HSZ )goto lng ;
if (__3ll == __6HSZ )
# 656 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> __O2__4expr.string [2 ])>= '8' )goto ulng ;
else goto lng ;
if (SZ_LONG == SZ_LLONG )break ;
__6HSZ = (SZ_LLONG + SZ_LLONG );
if (__3ll < __6HSZ )goto llng ;
if (__3ll == __6HSZ )
# 662 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> __O2__4expr.string [2 ])>= '8' )goto ullng ;
else goto llng ;
break ;

# 664 "/home/claude/cfront-3/src/expr.cpp"
}
}
default :
# 667 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 668 "/home/claude/cfront-3/src/expr.cpp"
int __6IBITS ;

# 668 "/home/claude/cfront-3/src/expr.cpp"
__6IBITS = (BI_IN_BYTE * SZ_INT );
while ((__0this -> __O2__4expr.string [__4index ])== '0' )__4index ++ ;
{ char __6x ;
int __6lbt ;

# 673 "/home/claude/cfront-3/src/expr.cpp"
int __6nbits ;

# 670 "/home/claude/cfront-3/src/expr.cpp"
__6x = (__0this -> __O2__4expr.string [__4index ]);
__6lbt = ((__6x == '1' )?1 :(((__6x == '2' )|| (__6x == '3' ))?2 :3 ));

# 673 "/home/claude/cfront-3/src/expr.cpp"
__6nbits = ((((__3ll - __4index )- 1 )* 3 )+ __6lbt );
if (__6nbits < __6IBITS )goto nrm ;
if (__6nbits == __6IBITS )goto labuint ;
if (__6nbits < (BI_IN_BYTE * SZ_LONG ))goto lng ;
if (__6nbits == (BI_IN_BYTE * SZ_LONG ))goto ulng ;
if (__6nbits < (BI_IN_BYTE * SZ_LLONG ))goto llng ;

# 678 "/home/claude/cfront-3/src/expr.cpp"
}
}
}
goto ullng ;
}
else { 
# 684 "/home/claude/cfront-3/src/expr.cpp"
if (__3ll < chars_in_largest ){ 
# 685 "/home/claude/cfront-3/src/expr.cpp"
nrm :
# 686 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)int_type ;
goto save ;
}
if (__3ll == chars_in_largest ){ 
# 690 "/home/claude/cfront-3/src/expr.cpp"
const char *__5p ;
const char *__5q ;

# 690 "/home/claude/cfront-3/src/expr.cpp"
__5p = __0this -> __O2__4expr.string ;
__5q = LARGEST_INT ;
do if (((*__5p ))> ((*__5q ))){ 
# 693 "/home/claude/cfront-3/src/expr.cpp"
if (SZ_INT == SZ_LONG )goto ulng ;
goto lng ;
}
while ((((*(__5p ++ )))== ((*(__5q ++ ))))&& ((*__5p )));

# 696 "/home/claude/cfront-3/src/expr.cpp"
goto nrm ;
}

# 699 "/home/claude/cfront-3/src/expr.cpp"
if (__3ll < chars_in_largestl )
# 700 "/home/claude/cfront-3/src/expr.cpp"
goto lng ;
if (__3ll == chars_in_largestl ){ 
# 702 "/home/claude/cfront-3/src/expr.cpp"
const char *__5p ;
const char *__5q ;

# 702 "/home/claude/cfront-3/src/expr.cpp"
__5p = __0this -> __O2__4expr.string ;
__5q = LARGEST_LONG ;
do if (((*__5p ))> ((*__5q ))){ 
# 705 "/home/claude/cfront-3/src/expr.cpp"
if (SZ_LONG == SZ_LLONG )goto ullng ;
goto llng ;
}
while ((((*(__5p ++ )))== ((*(__5q ++ ))))&& ((*__5p )));

# 708 "/home/claude/cfront-3/src/expr.cpp"
goto lng ;
}

# 711 "/home/claude/cfront-3/src/expr.cpp"
if (__3ll < chars_in_largestll )
# 712 "/home/claude/cfront-3/src/expr.cpp"
goto llng ;

# 714 "/home/claude/cfront-3/src/expr.cpp"
{ const char *__4p ;
const char *__4q ;

# 714 "/home/claude/cfront-3/src/expr.cpp"
__4p = __0this -> __O2__4expr.string ;
__4q = LARGEST_LLONG ;
do if (((*__4p ))> ((*__4q ))){ 
# 717 "/home/claude/cfront-3/src/expr.cpp"
goto ullng ;
}
while ((((*(__4p ++ )))== ((*(__4q ++ ))))&& ((*__4p )));

# 719 "/home/claude/cfront-3/src/expr.cpp"
goto llng ;

# 719 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 723 "/home/claude/cfront-3/src/expr.cpp"
}
case 84 :
# 725 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)((c_strlen__FPCc ( __0this -> __O2__4expr.string ) < 5 )?char_type :int_type );
goto save ;

# 728 "/home/claude/cfront-3/src/expr.cpp"
case 83 :
# 729 "/home/claude/cfront-3/src/expr.cpp"
{ int __3ll ;

# 729 "/home/claude/cfront-3/src/expr.cpp"
char *__3str_tmp ;
int __3last ;

# 729 "/home/claude/cfront-3/src/expr.cpp"
__3ll = strlen ( __0this -> __O2__4expr.string ) ;
__3last = (__0this -> __O2__4expr.string [(__3ll - 1 )]);
__0this -> __O1__4expr.tp = (struct type *)double_type ;
if ((__3last == 'F' )|| (__3last == 'f' )){ 
# 733 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)float_type ;
if (! ansi_opt ){ 
# 735 "/home/claude/cfront-3/src/expr.cpp"
__3str_tmp = strdup ( __0this -> __O2__4expr.string ) ;
(__3str_tmp [(__3ll - 1 )])= 0 ;

# 738 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.string = (const char *)__3str_tmp ;
goto cast_n_save ;
}
}
else if ((__3last == 'L' )|| (__3last == 'l' )){ 
# 743 "/home/claude/cfront-3/src/expr.cpp"
if (ansi_opt == 0 ){ 
# 744 "/home/claude/cfront-3/src/expr.cpp"
__3str_tmp = strdup ( __0this -> __O2__4expr.string ) ;
# 744 "/home/claude/cfront-3/src/expr.cpp"

# 745 "/home/claude/cfront-3/src/expr.cpp"
(__3str_tmp [(__3ll - 1 )])= 0 ;

# 747 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.string = (const char *)__3str_tmp ;
}
__0this -> __O1__4expr.tp = (struct type *)ldouble_type ;
}
goto save ;
}
case 81 :
# 755 "/home/claude/cfront-3/src/expr.cpp"
{ Pvec __3v ;

# 755 "/home/claude/cfront-3/src/expr.cpp"
__3v = __ct__3vecFP4typeP4expr ( (struct vec *)0 , (struct type *)char_type , (struct expr *)0 ) ;
__3v -> size__3vec = c_strlen__FPCc ( __0this -> __O2__4expr.string ) ;
__0this -> __O1__4expr.tp = (struct type *)__3v ;
}
save :
# 760 "/home/claude/cfront-3/src/expr.cpp"
if (const_save ){ 
# 761 "/home/claude/cfront-3/src/expr.cpp"
char *__3p ;

# 761 "/home/claude/cfront-3/src/expr.cpp"
__3p = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __0this -> __O2__4expr.string ) + 1 ))) ));
# 761 "/home/claude/cfront-3/src/expr.cpp"

# 762 "/home/claude/cfront-3/src/expr.cpp"
strcpy ( __3p , __0this -> __O2__4expr.string ) ;
__0this -> __O2__4expr.string = (const char *)__3p ;
}

# 766 "/home/claude/cfront-3/src/expr.cpp"
return __0this ;

# 768 "/home/claude/cfront-3/src/expr.cpp"
cast_n_save :
# 769 "/home/claude/cfront-3/src/expr.cpp"
if (const_save ){ 
# 770 "/home/claude/cfront-3/src/expr.cpp"
char *__3p ;

# 770 "/home/claude/cfront-3/src/expr.cpp"
__3p = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __0this -> __O2__4expr.string ) + 1 ))) ));
# 770 "/home/claude/cfront-3/src/expr.cpp"

# 771 "/home/claude/cfront-3/src/expr.cpp"
strcpy ( __3p , __0this -> __O2__4expr.string ) ;
__0this -> __O2__4expr.string = (const char *)__3p ;
}

# 775 "/home/claude/cfront-3/src/expr.cpp"
return (struct expr *)( (__0__X92 = 0 ), ( (__2__X93 = __0this -> __O1__4expr.tp ), ( ((__0__X92 || (__0__X92 = (struct cast *)__nw__4exprSFUl (
# 775 "/home/claude/cfront-3/src/expr.cpp"
(unsigned long )(sizeof (struct cast))) ))?( (__0__X92 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X92 ), (unsigned char )191 , __0this ,
# 775 "/home/claude/cfront-3/src/expr.cpp"
(struct expr *)0 ) ), (__0__X92 -> __O1__4expr.tp = (__0__X92 -> __O4__4expr.tp2 = __2__X93 ))) :0 ), __0__X92 ) ) ) ;

# 777 "/home/claude/cfront-3/src/expr.cpp"
case 34 :
# 778 "/home/claude/cfront-3/src/expr.cpp"
( (__0this ?(((void )(__0this ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct expr))) )))):(((void )0 ))))):(((void
# 778 "/home/claude/cfront-3/src/expr.cpp"
)0 )))) ;
if (cc -> c_this__11dcl_context ){ 
# 779 "/home/claude/cfront-3/src/expr.cpp"
struct name *__0__X94 ;

# 780 "/home/claude/cfront-3/src/expr.cpp"
( (__0__X94 = cc -> c_this__11dcl_context ), ( (__0__X94 -> n_used__4name ++ ), (((void )0 ))) ) ;
return (struct expr *)cc -> c_this__11dcl_context ;
}
error__FPCc ( (const char *)"``this'' used in nonC context") ;
__1n = __ct__4nameFPCc ( (struct name *)0 , (const char *)"this") ;
__1n -> __O1__4expr.tp = (struct type *)any_type ;
return (struct expr *)insert__5tableFP4nameUc ( __1tbl , __1n , (unsigned char )0 ) ;

# 788 "/home/claude/cfront-3/src/expr.cpp"
case 85 :
# 789 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 790 "/home/claude/cfront-3/src/expr.cpp"
Pname __3q ;
Pexpr __3ee ;

# 790 "/home/claude/cfront-3/src/expr.cpp"
__3q = (((struct name *)(((struct name *)__0this ))))-> __O2__4name.n_qualifier ;
__3ee = find_name__FP4nameP8classdefP5tableiT1 ( ((struct name *)(((struct name *)__0this ))), cc -> cot__11dcl_context , __1tbl , 0 , cc -> nof__11dcl_context ) ;
if (__3q && ((__3ee -> base__4node == 44 )|| (__3ee -> base__4node == 45 )))
# 793 "/home/claude/cfront-3/src/expr.cpp"
__3ee -> __O3__4expr.n_initializer = (((struct expr *)(((struct expr *)__3q ))));

# 795 "/home/claude/cfront-3/src/expr.cpp"
if (((((cc -> nof__11dcl_context && (((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp ))))-> f_const__3fct )&& ((__3ee -> base__4node == 44 )|| (__3ee -> base__4node ==
# 795 "/home/claude/cfront-3/src/expr.cpp"
45 )))&& __3ee -> __O1__4expr.tp )&& (skiptypedefs__4typeFv ( __3ee -> __O1__4expr.tp ) -> base__4node != 108 ))&& (skiptypedefs__4typeFv ( __3ee -> __O1__4expr.tp ) -> base__4node !=
# 795 "/home/claude/cfront-3/src/expr.cpp"
76 ))
# 808 "/home/claude/cfront-3/src/expr.cpp"
__3ee -> __O1__4expr.tp = mkconst__4typeFv ( __3ee -> __O1__4expr.tp ) ;

# 811 "/home/claude/cfront-3/src/expr.cpp"
if (is_ref__4typeFv ( __3ee -> __O1__4expr.tp ) )return contents__4exprFv ( __3ee ) ;

# 813 "/home/claude/cfront-3/src/expr.cpp"
if ((__3ee -> base__4node == 85 )&& (((struct name *)(((struct name *)__3ee ))))-> n_xref__4name ){ 
# 815 "/home/claude/cfront-3/src/expr.cpp"
__3ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char
# 815 "/home/claude/cfront-3/src/expr.cpp"
)111 , __3ee , (struct expr *)0 ) ;
__3ee -> __O1__4expr.tp = __3ee -> __O2__4expr.e1 -> __O1__4expr.tp ;
}

# 819 "/home/claude/cfront-3/src/expr.cpp"
return __3ee ;
}

# 822 "/home/claude/cfront-3/src/expr.cpp"
case 112 :
# 823 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 -> base__4node == 34 ){ 
# 824 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"&this")
# 824 "/home/claude/cfront-3/src/expr.cpp"
;
break ;
}
case 145 :
# 828 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 -> base__4node == 85 )__0this -> __O3__4expr.e2 = find_name__FP4nameP8classdefP5tableiT1 ( ((struct name *)(((struct name *)__0this -> __O3__4expr.e2 ))), cc -> cot__11dcl_context ,
# 828 "/home/claude/cfront-3/src/expr.cpp"
__1tbl , 112 , cc -> nof__11dcl_context ) ;

# 830 "/home/claude/cfront-3/src/expr.cpp"
if (((((cc -> nof__11dcl_context && (((struct fct *)(((struct fct *)cc -> nof__11dcl_context -> __O1__4expr.tp ))))-> f_const__3fct )&& ((__0this -> __O3__4expr.e2 -> base__4node == 44 )|| (__0this ->
# 830 "/home/claude/cfront-3/src/expr.cpp"
__O3__4expr.e2 -> base__4node == 45 )))&& __0this -> __O3__4expr.e2 -> __O1__4expr.tp )&& (skiptypedefs__4typeFv ( __0this -> __O3__4expr.e2 -> __O1__4expr.tp ) -> base__4node != 108 ))&& (skiptypedefs__4typeFv (
# 830 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 -> __O1__4expr.tp ) -> base__4node != 76 ))
# 843 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 -> __O1__4expr.tp = mkconst__4typeFv ( __0this -> __O3__4expr.e2 -> __O1__4expr.tp ) ;

# 845 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> __O3__4expr.e2 -> base__4node == 85 )&& (((struct name *)(((struct name *)__0this -> __O3__4expr.e2 ))))-> n_xref__4name ){ 
# 847 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct
# 847 "/home/claude/cfront-3/src/expr.cpp"
expr *)0 , (unsigned char )111 , __0this -> __O3__4expr.e2 , (struct expr *)0 ) ;
__0this -> __O3__4expr.e2 -> __O1__4expr.tp = __0this -> __O3__4expr.e2 -> __O2__4expr.e1 -> __O1__4expr.tp ;
}
if (__0this -> __O3__4expr.e2 -> base__4node == 45 ){ 
# 851 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O3__4expr.e2 -> __O2__4expr.e1 -> base__4node ){ 
# 852 "/home/claude/cfront-3/src/expr.cpp"
case 109 :
# 853 "/home/claude/cfront-3/src/expr.cpp"
case 146 :
# 854 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 855 "/home/claude/cfront-3/src/expr.cpp"
Pcall __5c ;
# 855 "/home/claude/cfront-3/src/expr.cpp"
__5c = (((struct call *)(((struct call *)__0this -> __O3__4expr.e2 -> __O2__4expr.e1 ))));
if (__5c && __5c -> __O2__4expr.e1 ){ 
# 857 "/home/claude/cfront-3/src/expr.cpp"
__5c -> __O2__4expr.e1 = typ__4exprFP5table ( __5c -> __O2__4expr.e1 , __1tbl ) ;
if (__5c -> __O2__4expr.e1 -> __O1__4expr.tp && ((((struct fct *)(((struct fct *)__5c -> __O2__4expr.e1 -> __O1__4expr.tp ))))-> returns__3fct -> base__4node == 158 ))break ;
}
}
case 157 :
# 862 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"& non-lvalue") ;
}
}
break ;

# 867 "/home/claude/cfront-3/src/expr.cpp"
case 30 :
# 868 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O4__4expr.tp2 ){ 
# 869 "/home/claude/cfront-3/src/expr.cpp"
dcl__4typeFP5table ( __0this -> __O4__4expr.tp2 , __1tbl ) ;
switch (__0this -> __O4__4expr.tp2 -> base__4node ){ 
# 871 "/home/claude/cfront-3/src/expr.cpp"
case 38 :
# 872 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"sizeof(void)") ;
# 872 "/home/claude/cfront-3/src/expr.cpp"

# 873 "/home/claude/cfront-3/src/expr.cpp"
break ;
case 6 :
# 875 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 876 "/home/claude/cfront-3/src/expr.cpp"
Pclass __5cl ;

# 876 "/home/claude/cfront-3/src/expr.cpp"
__5cl = (((struct classdef *)(((struct classdef *)__0this -> __O4__4expr.tp2 ))));
if ((__5cl -> c_body__8classdef == 1 )&& ((__5cl -> defined__4type & 3)== 0 ))
# 879 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCc ( (int )'s' , (const char *)"class defined within sizeof")
# 879 "/home/claude/cfront-3/src/expr.cpp"
;
}
}

# 883 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O2__4expr.e1 && (__0this -> __O2__4expr.e1 != dummy )){ 
# 884 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
if (__0this -> __O2__4expr.e1 && (__0this -> __O2__4expr.e1 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O2__4expr.e1 ) ;
__0this -> __O2__4expr.e1 = dummy ;
}
{ Pptr __3r ;

# 888 "/home/claude/cfront-3/src/expr.cpp"
__3r = is_ref__4typeFv ( __0this -> __O4__4expr.tp2 ) ;
if (__3r )__0this -> __O4__4expr.tp2 = __3r -> typ__5pvtyp ;

# 889 "/home/claude/cfront-3/src/expr.cpp"
}
}
else if (__0this -> __O2__4expr.e1 == dummy ){ 
# 892 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"sizeof emptyE") ;
# 892 "/home/claude/cfront-3/src/expr.cpp"

# 893 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)any_type ;
return __0this ;
}
else { 
# 897 "/home/claude/cfront-3/src/expr.cpp"
++ processing_sizeof ;
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
-- processing_sizeof ;
__0this -> __O4__4expr.tp2 = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
if (__0this -> __O4__4expr.tp2 -> base__4node == 110 )__0this -> __O4__4expr.tp2 -> permanent__4node = 1 ;
if (__0this -> __O2__4expr.e1 -> base__4node == 124 )
# 903 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = dummy ;
else if (__0this -> __O4__4expr.tp2 == (((struct type *)char_type )))
# 905 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = dummy ;
}
((void )tsizeof__4typeFi ( __0this -> __O4__4expr.tp2 , 0 ) );
if (__0this -> __O4__4expr.tp2 -> base__4node == 38 )error__FPCc ( (const char *)"sizeof(void)") ;
__0this -> __O1__4expr.tp = size_t_type ;
return __0this ;

# 912 "/home/claude/cfront-3/src/expr.cpp"
case 113 :
# 913 "/home/claude/cfront-3/src/expr.cpp"
case 191 :
# 914 "/home/claude/cfront-3/src/expr.cpp"
{ Pexpr __3ee ;

# 914 "/home/claude/cfront-3/src/expr.cpp"
__3ee = docast__4exprFP5table ( __0this , __1tbl ) ;
return (is_ref__4typeFv ( __3ee -> __O1__4expr.tp ) ?contents__4exprFv ( __3ee ) :__3ee );
}

# 918 "/home/claude/cfront-3/src/expr.cpp"
case 157 :
# 920 "/home/claude/cfront-3/src/expr.cpp"
return dovalue__4exprFP5table ( __0this , __1tbl ) ;

# 922 "/home/claude/cfront-3/src/expr.cpp"
case 23 :
# 923 "/home/claude/cfront-3/src/expr.cpp"
case 213 :
# 924 "/home/claude/cfront-3/src/expr.cpp"
case 184 :
# 925 "/home/claude/cfront-3/src/expr.cpp"
return donew__4exprFP5table ( __0this , __1tbl ) ;

# 927 "/home/claude/cfront-3/src/expr.cpp"
case 9 :
# 928 "/home/claude/cfront-3/src/expr.cpp"
case 212 :
# 929 "/home/claude/cfront-3/src/expr.cpp"
case 188 :
# 930 "/home/claude/cfront-3/src/expr.cpp"
{ int __3i ;

# 931 "/home/claude/cfront-3/src/expr.cpp"
struct type *__0__X95 ;

# 932 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
if (skiptypedefs__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) -> base__4node == 119 ){ 
# 934 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __4x ;

# 934 "/home/claude/cfront-3/src/expr.cpp"
__4x = try_to_coerce__FP4typeP4exprPCcP5table ( Pvoid_type , __0this -> __O2__4expr.e1 , (const char *)"argument", __1tbl ) ;
# 934 "/home/claude/cfront-3/src/expr.cpp"

# 935 "/home/claude/cfront-3/src/expr.cpp"
if (__4x )__0this -> __O2__4expr.e1 = __4x ;
}
__3i = ( (__0__X95 = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ), ( kind__4typeFUcN21 ( __0__X95 , ((unsigned char )9 ), (unsigned char
# 937 "/home/claude/cfront-3/src/expr.cpp"
)'P' , (unsigned char )1 ) ) ) ;
if (__3i != 'P' )error__FPCc ( (const char *)"nonP deleted") ;
if (__0this -> __O3__4expr.e2 ){ 
# 939 "/home/claude/cfront-3/src/expr.cpp"
struct type *__0__X96 ;

# 940 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = typ__4exprFP5table ( __0this -> __O3__4expr.e2 , __1tbl ) ;
( (__0__X96 = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ), ( kind__4typeFUcN21 ( __0__X96 , ((unsigned char )9 ), (unsigned char )'I' ,
# 941 "/home/claude/cfront-3/src/expr.cpp"
(unsigned char )1 ) ) ) ;
}
__0this -> __O1__4expr.tp = (struct type *)void_type ;
return __0this ;
}

# 947 "/home/claude/cfront-3/src/expr.cpp"
case 124 :
# 948 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
__0this -> __O1__4expr.tp = (struct type *)any_type ;
return __0this ;

# 952 "/home/claude/cfront-3/src/expr.cpp"
case 140 :
# 953 "/home/claude/cfront-3/src/expr.cpp"
{ Pexpr __3e ;
Pexpr __3ex ;

# 956 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> __O2__4expr.e1 == dummy )&& (__0this -> __O3__4expr.e2 == 0 )){ 
# 957 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"emptyIrL")
# 957 "/home/claude/cfront-3/src/expr.cpp"
;
__0this -> __O1__4expr.tp = (struct type *)any_type ;
return __0this ;
}

# 962 "/home/claude/cfront-3/src/expr.cpp"
for(__3e = __0this ;__3e ;__3e = __3ex ) { 
# 963 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __4ee ;

# 964 "/home/claude/cfront-3/src/expr.cpp"
unsigned long __2__X97 ;

# 963 "/home/claude/cfront-3/src/expr.cpp"
__4ee = __3e -> __O2__4expr.e1 ;

# 965 "/home/claude/cfront-3/src/expr.cpp"
if (__3e -> base__4node != 140 ){ 
# 965 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V45 ;

# 965 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"elist%k", (const struct ea *)( (__2__X97 =
# 965 "/home/claude/cfront-3/src/expr.cpp"
__3e -> base__4node ), ( (( ((& __0__V45 )-> __O1__2ea.i = __2__X97 ), 0 ) ), (& __0__V45 )) ) ,
# 965 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__3ex = __3e -> __O3__4expr.e2 ){ 
# 967 "/home/claude/cfront-3/src/expr.cpp"
if (__4ee == dummy )error__FPCc ( (const char *)"EX in EL")
# 967 "/home/claude/cfront-3/src/expr.cpp"
;
if ((__3ex -> __O2__4expr.e1 == dummy )&& (__3ex -> __O3__4expr.e2 == 0 )){ 
# 970 "/home/claude/cfront-3/src/expr.cpp"
if (__3ex && (__3ex -> permanent__4node == 0 ))del__4exprFv ( __3ex ) ;
# 970 "/home/claude/cfront-3/src/expr.cpp"

# 971 "/home/claude/cfront-3/src/expr.cpp"
__3e -> __O3__4expr.e2 = (__3ex = 0 );
}
}
__3e -> __O2__4expr.e1 = typ__4exprFP5table ( __4ee , __1tbl ) ;
__1t = __3e -> __O2__4expr.e1 -> __O1__4expr.tp ;
if (__1t -> base__4node == 108 ){ 
# 977 "/home/claude/cfront-3/src/expr.cpp"
__4ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __3e ->
# 977 "/home/claude/cfront-3/src/expr.cpp"
__O2__4expr.e1 ) ;
__3e -> __O2__4expr.e1 = typ__4exprFP5table ( __4ee , __1tbl ) ;
__1t = __3e -> __O2__4expr.e1 -> __O1__4expr.tp ;
}
}
__0this -> __O1__4expr.tp = __1t ;
return __0this ;
}

# 986 "/home/claude/cfront-3/src/expr.cpp"
case 45 :
# 987 "/home/claude/cfront-3/src/expr.cpp"
case 44 :
# 988 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 989 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 ){ 
# 990 "/home/claude/cfront-3/src/expr.cpp"
if (__1b == 44 )__1b = (__0this -> base__4node = 180 );
if ((__0this -> __O3__4expr.e2 -> base__4node == 85 )&& ((((struct name *)(((struct name *)__0this -> __O3__4expr.e2 ))))-> permanent__4node != 1 ))(((struct name *)(((struct name *)__0this -> __O3__4expr.e2 ))))->
# 991 "/home/claude/cfront-3/src/expr.cpp"
permanent__4node = 1 ;
break ;
}

# 995 "/home/claude/cfront-3/src/expr.cpp"
{ Pbase __3b ;
bit __3bcc ;

# 998 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
__1t = skiptypedefs__4typeFRUc ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp , (bit *)(& __3bcc )) ;

# 1001 "/home/claude/cfront-3/src/expr.cpp"
if ((((__0this -> base__4node == 45 )&& (__0this -> __O2__4expr.e1 -> base__4node == 111 ))&& (__0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> base__4node == 85 ))&& is_probably_temp__FPCc (
# 1001 "/home/claude/cfront-3/src/expr.cpp"
(((struct name *)(((struct name *)__0this -> __O2__4expr.e1 -> __O2__4expr.e1 ))))-> __O2__4expr.string ) )
# 1006 "/home/claude/cfront-3/src/expr.cpp"
__3bcc = 0 ;

# 1009 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> base__4node == 44 ){ 
# 1010 "/home/claude/cfront-3/src/expr.cpp"
switch (__1t -> base__4node ){ 
# 1010 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X104 ;

# 1011 "/home/claude/cfront-3/src/expr.cpp"
case 119 :
# 1012 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1013 "/home/claude/cfront-3/src/expr.cpp"
Pname __6n ;

# 1013 "/home/claude/cfront-3/src/expr.cpp"
__6n = has_oper__8classdefFUc ( classtype__4typeFv ( __1t ) , (unsigned char )44 ) ;
if (__6n ){ 
# 1014 "/home/claude/cfront-3/src/expr.cpp"
struct ref *__0__X98 ;

# 1014 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X99 ;

# 1014 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X100 ;

# 1014 "/home/claude/cfront-3/src/expr.cpp"
struct call *__0__X101 ;

# 1014 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X102 ;

# 1014 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X103 ;

# 1015 "/home/claude/cfront-3/src/expr.cpp"
__6n -> n_used__4name += 2 ;
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X101 = 0 ), ( (__2__X102 = (struct expr *)( (__0__X98 = 0 ), ( (__2__X99 =
# 1016 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 ), ( (__2__X100 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , __6n -> __O2__4expr.string ) ), ( ((__0__X98 || (__0__X98 =
# 1016 "/home/claude/cfront-3/src/expr.cpp"
(struct ref *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ref))) ))?( (__0__X98 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X98 ), ((unsigned char
# 1016 "/home/claude/cfront-3/src/expr.cpp"
)45 ), __2__X99 , (struct expr *)0 ) ), (__0__X98 -> __O4__4expr.mem = __2__X100 )) :0 ), __0__X98 ) ) ) ) ),
# 1016 "/home/claude/cfront-3/src/expr.cpp"
( (__2__X103 = 0 ), ( ((__0__X101 || (__0__X101 = (struct call *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct call))) ))?(__0__X101 = (struct
# 1016 "/home/claude/cfront-3/src/expr.cpp"
call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X101 ), (unsigned char )109 , __2__X102 , __2__X103 ) ):0 ), __0__X101 ) ) ) ) ;
# 1016 "/home/claude/cfront-3/src/expr.cpp"

# 1017 "/home/claude/cfront-3/src/expr.cpp"
return typ__4exprFP5table ( __0this , __1tbl ) ;
}

# 1020 "/home/claude/cfront-3/src/expr.cpp"
}
default :
# 1022 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1022 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V46 ;

# 1022 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"nonP ->%n", (const struct ea *)( (__2__X104 = (const void
# 1022 "/home/claude/cfront-3/src/expr.cpp"
*)__0this -> __O4__4expr.mem ), ( ((& __0__V46 )-> __O1__2ea.p = __2__X104 ), (& __0__V46 )) ) , (const struct ea *)ea0 ,
# 1022 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1t = (struct type *)any_type ;

# 1025 "/home/claude/cfront-3/src/expr.cpp"
case 141 :
# 1026 "/home/claude/cfront-3/src/expr.cpp"
goto qqq ;
case 125 :
# 1028 "/home/claude/cfront-3/src/expr.cpp"
case 110 :
# 1029 "/home/claude/cfront-3/src/expr.cpp"
__3b = (((struct basetype *)(((struct basetype *)skiptypedefs__4typeFRUc ( (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp , (bit *)(& __3bcc )) ))));
__0this -> __O4__4expr.mem = do_qualifiers__FP4typeP4expr ( (struct type *)__3b , __0this -> __O4__4expr.mem ) ;
if (__0this -> __O4__4expr.mem -> base__4node == 162 )__0this -> __O4__4expr.mem = do_dtor__FP4typeP4expr ( (struct type *)__3b , __0this -> __O4__4expr.mem ) ;
} }
}
else { 
# 1035 "/home/claude/cfront-3/src/expr.cpp"
qqq :
# 1036 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O4__4expr.mem = do_qualifiers__FP4typeP4expr ( __1t , __0this -> __O4__4expr.mem ) ;
switch (__1t -> base__4node ){ 
# 1037 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X105 ;

# 1038 "/home/claude/cfront-3/src/expr.cpp"
default :
# 1039 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O4__4expr.mem -> base__4node == 162 )__0this -> __O4__4expr.mem = do_dtor__FP4typeP4expr ( __1t , __0this -> __O4__4expr.mem ) ;
if (__0this -> __O4__4expr.mem -> base__4node == 162 )
# 1041 "/home/claude/cfront-3/src/expr.cpp"
break ;
{ 
# 1042 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V47 ;

# 1042 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"nonO .%n", (const struct ea *)( (__2__X105 = (const void
# 1042 "/home/claude/cfront-3/src/expr.cpp"
*)__0this -> __O4__4expr.mem ), ( ((& __0__V47 )-> __O1__2ea.p = __2__X105 ), (& __0__V47 )) ) , (const struct ea *)ea0 ,
# 1042 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 1042 "/home/claude/cfront-3/src/expr.cpp"
__1t = (struct type *)any_type ;
case 141 :
# 1044 "/home/claude/cfront-3/src/expr.cpp"
break ;
case 119 :
# 1046 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O4__4expr.mem -> base__4node == 162 )__0this -> __O4__4expr.mem = do_dtor__FP4typeP4expr ( __1t , __0this -> __O4__4expr.mem ) ;
} }

# 1049 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 1050 "/home/claude/cfront-3/src/expr.cpp"
case 68 :
# 1051 "/home/claude/cfront-3/src/expr.cpp"
case 70 :
# 1052 "/home/claude/cfront-3/src/expr.cpp"
case 48 :
# 1053 "/home/claude/cfront-3/src/expr.cpp"
case 49 :
# 1054 "/home/claude/cfront-3/src/expr.cpp"
case 126 :
# 1055 "/home/claude/cfront-3/src/expr.cpp"
case 127 :
# 1056 "/home/claude/cfront-3/src/expr.cpp"
case 128 :
# 1057 "/home/claude/cfront-3/src/expr.cpp"
case 129 :
# 1058 "/home/claude/cfront-3/src/expr.cpp"
case
# 1058 "/home/claude/cfront-3/src/expr.cpp"
130 :
# 1059 "/home/claude/cfront-3/src/expr.cpp"
case 131 :
# 1060 "/home/claude/cfront-3/src/expr.cpp"
case 132 :
# 1061 "/home/claude/cfront-3/src/expr.cpp"
case 133 :
# 1062 "/home/claude/cfront-3/src/expr.cpp"
case 134 :
# 1063 "/home/claude/cfront-3/src/expr.cpp"
case 135 :
# 1064 "/home/claude/cfront-3/src/expr.cpp"
case 71 :
# 1065 "/home/claude/cfront-3/src/expr.cpp"
case 147 :
# 1066 "/home/claude/cfront-3/src/expr.cpp"
__0this -> base__4node = 44 ;
__0this -> __O2__4expr.e1 = address__4exprFv ( __0this -> __O2__4expr.e1 ) ;
break ;
case 109 :
# 1070 "/home/claude/cfront-3/src/expr.cpp"
case 146 :
# 1078 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1079 "/home/claude/cfront-3/src/expr.cpp"
Pname __6tmp ;

# 1079 "/home/claude/cfront-3/src/expr.cpp"
__6tmp = make_tmp__FcP4typeP5table ( 'Q' , __0this -> __O2__4expr.e1 -> __O1__4expr.tp , __1tbl ) ;

# 1081 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = init_tmp__FP4nameP4exprP5table ( __6tmp , __0this -> __O2__4expr.e1 , __1tbl ) ;
{ Pexpr __6aa ;

# 1082 "/home/claude/cfront-3/src/expr.cpp"
__6aa = address__4exprFv ( (struct expr *)__6tmp ) ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __0this -> __O2__4expr.e1 , __6aa ) ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = __6aa -> __O1__4expr.tp ;
__0this -> base__4node = 44 ;
break ;

# 1086 "/home/claude/cfront-3/src/expr.cpp"
}
}
}
__3b = (((struct basetype *)(((struct basetype *)__1t ))));
}

# 1092 "/home/claude/cfront-3/src/expr.cpp"
switch (__3b -> base__4node ){ 
# 1092 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X106 ;

# 1092 "/home/claude/cfront-3/src/expr.cpp"
unsigned long __2__X107 ;

# 1093 "/home/claude/cfront-3/src/expr.cpp"
default :
# 1094 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O4__4expr.mem -> base__4node == 162 ){ 
# 1098 "/home/claude/cfront-3/src/expr.cpp"
return __0this -> __O4__4expr.mem ;
}
else { 
# 1100 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V48 ;

# 1100 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V49 ;

# 1100 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V50 ;

# 1100 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V51 ;

# 1100 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"(%t) before%k%n (%n not aM)", (const struct ea *)( (__2__X106 = (const void
# 1100 "/home/claude/cfront-3/src/expr.cpp"
*)__0this -> __O2__4expr.e1 -> __O1__4expr.tp ), ( ((& __0__V48 )-> __O1__2ea.p = __2__X106 ), (& __0__V48 )) ) , (const struct
# 1100 "/home/claude/cfront-3/src/expr.cpp"
ea *)( (__2__X107 = __0this -> base__4node ), ( (( ((& __0__V49 )-> __O1__2ea.i = __2__X107 ), 0 ) ), (& __0__V49 ))
# 1100 "/home/claude/cfront-3/src/expr.cpp"
) , (const struct ea *)__ct__2eaFPCv ( & __0__V50 , (const void *)__0this -> __O4__4expr.mem ) , (const struct
# 1100 "/home/claude/cfront-3/src/expr.cpp"
ea *)__ct__2eaFPCv ( & __0__V51 , (const void *)__0this -> __O4__4expr.mem ) ) ;
} case 141 :
# 1102 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)any_type ;
return __0this ;
case 119 :
# 1105 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1106 "/home/claude/cfront-3/src/expr.cpp"
Pclass __5cl ;

# 1106 "/home/claude/cfront-3/src/expr.cpp"
__5cl = classtype__4typeFv ( (struct type *)__3b ) ;
if (__5cl -> c_body__8classdef == 1 )dcl_print__8classdefFP4name ( __5cl , (struct name *)0 ) ;
break ;
}
}

# 1117 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O4__4expr.mem -> __O1__4expr.tp ){ 
# 1118 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = __0this -> __O4__4expr.mem -> __O1__4expr.tp ;
{ { Pexpr __4ee ;

# 1119 "/home/claude/cfront-3/src/expr.cpp"
__4ee = __0this -> __O4__4expr.mem ;

# 1119 "/home/claude/cfront-3/src/expr.cpp"
for(;__4ee -> base__4node == 44 ;__4ee = __4ee -> __O2__4expr.e1 ) { 
# 1120 "/home/claude/cfront-3/src/expr.cpp"
if (__4ee -> __O2__4expr.e1 == (((struct expr *)cc -> c_this__11dcl_context ))){ 
# 1121 "/home/claude/cfront-3/src/expr.cpp"
__4ee -> __O2__4expr.e1 =
# 1121 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 ;
__4ee -> base__4node = __0this -> base__4node ;
if (((__3bcc && __0this -> __O4__4expr.mem -> __O1__4expr.tp )&& (skiptypedefs__4typeFv ( __0this -> __O4__4expr.mem -> __O1__4expr.tp ) -> base__4node != 108 ))&& (skiptypedefs__4typeFv ( __0this ->
# 1123 "/home/claude/cfront-3/src/expr.cpp"
__O4__4expr.mem -> __O1__4expr.tp ) -> base__4node != 76 ))
# 1132 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O4__4expr.mem -> __O1__4expr.tp = mkconst__4typeFv ( __0this -> __O4__4expr.mem -> __O1__4expr.tp ) ;
return (is_ref__4typeFv ( __0this -> __O4__4expr.mem -> __O1__4expr.tp ) ?contents__4exprFv ( __0this -> __O4__4expr.mem ) :__0this -> __O4__4expr.mem );
}
}

# 1137 "/home/claude/cfront-3/src/expr.cpp"
return (is_ref__4typeFv ( __0this -> __O1__4expr.tp ) ?contents__4exprFv ( __0this ) :__0this );

# 1137 "/home/claude/cfront-3/src/expr.cpp"
}

# 1137 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 1141 "/home/claude/cfront-3/src/expr.cpp"
{ Pname __3q ;

# 1141 "/home/claude/cfront-3/src/expr.cpp"
__3q = (((struct name *)(((struct name *)__0this -> __O4__4expr.mem ))))-> __O2__4name.n_qualifier ;

# 1148 "/home/claude/cfront-3/src/expr.cpp"
if ((! __3q )&& (strcmp ( (((struct name *)(((struct name *)__0this -> __O4__4expr.mem ))))-> __O2__4expr.string , oper_name__FUc ( (unsigned char )162 ) )
# 1148 "/home/claude/cfront-3/src/expr.cpp"
== 0 )){ 
# 1149 "/home/claude/cfront-3/src/expr.cpp"
(((struct name *)(((struct name *)__0this -> __O4__4expr.mem ))))-> __O2__4name.n_qualifier = (((struct name *)(((struct name *)__0this -> __O4__4expr.mem ))))-> __O1__4name.n_dtag ;
}
{ Pexpr __3e ;

# 1151 "/home/claude/cfront-3/src/expr.cpp"
__3e = find_name__FP4nameP8classdefP5tableiT1 ( ((struct name *)(((struct name *)__0this -> __O4__4expr.mem ))), classtype__4typeFv ( (struct type *)__3b ) , (struct table *)0 , (int )__0this ->
# 1151 "/home/claude/cfront-3/src/expr.cpp"
base__4node , cc -> nof__11dcl_context ) ;
if (__3q && ((__3e -> base__4node == 44 )|| (__3e -> base__4node == 45 ))){ 
# 1153 "/home/claude/cfront-3/src/expr.cpp"
(((struct name *)(((struct name *)__3e ))))-> __O3__4expr.n_initializer = (((struct expr *)(((struct
# 1153 "/home/claude/cfront-3/src/expr.cpp"
expr *)__3q ))));

# 1155 "/home/claude/cfront-3/src/expr.cpp"
}

# 1157 "/home/claude/cfront-3/src/expr.cpp"
{ { Pexpr __3ee ;

# 1157 "/home/claude/cfront-3/src/expr.cpp"
__3ee = __3e ;

# 1157 "/home/claude/cfront-3/src/expr.cpp"
for(;__3ee -> base__4node == 44 ;__3ee = __3ee -> __O2__4expr.e1 ) { 
# 1158 "/home/claude/cfront-3/src/expr.cpp"
if (__3ee -> __O2__4expr.e1 == (((struct expr *)cc -> c_this__11dcl_context ))){ 
# 1159 "/home/claude/cfront-3/src/expr.cpp"
__3ee -> __O2__4expr.e1 =
# 1159 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 ;
__3ee -> base__4node = __0this -> base__4node ;
if (((__3bcc && __3e -> __O1__4expr.tp )&& (skiptypedefs__4typeFv ( __3e -> __O1__4expr.tp ) -> base__4node != 108 ))&& (skiptypedefs__4typeFv ( __3e -> __O1__4expr.tp ) ->
# 1161 "/home/claude/cfront-3/src/expr.cpp"
base__4node != 76 ))
# 1170 "/home/claude/cfront-3/src/expr.cpp"
__3e -> __O1__4expr.tp = mkconst__4typeFv ( __3e -> __O1__4expr.tp ) ;
break ;
}
}

# 1175 "/home/claude/cfront-3/src/expr.cpp"
if (__3e -> base__4node == 85 ){ 
# 1176 "/home/claude/cfront-3/src/expr.cpp"
switch (__3e -> __O1__4expr.tp -> base__4node ){ 
# 1177 "/home/claude/cfront-3/src/expr.cpp"
case 108 :
# 1178 "/home/claude/cfront-3/src/expr.cpp"
case 76 :
# 1179 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O4__4expr.mem = __3e ;
__0this -> __O1__4expr.tp = __3e -> __O1__4expr.tp ;
__3e = __0this ;
}
}

# 1186 "/home/claude/cfront-3/src/expr.cpp"
return (is_ref__4typeFv ( __3e -> __O1__4expr.tp ) ?contents__4exprFv ( __3e ) :__3e );

# 1186 "/home/claude/cfront-3/src/expr.cpp"
}

# 1186 "/home/claude/cfront-3/src/expr.cpp"
}

# 1186 "/home/claude/cfront-3/src/expr.cpp"
}

# 1186 "/home/claude/cfront-3/src/expr.cpp"
}

# 1186 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 1189 "/home/claude/cfront-3/src/expr.cpp"
case 109 :
# 1191 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> __O2__4expr.e1 -> base__4node == 85 )&& (__0this -> __O2__4expr.e1 -> __O1__4expr.tp == 0 )){ 
# 1192 "/home/claude/cfront-3/src/expr.cpp"
Pname __3q ;

# 1192 "/home/claude/cfront-3/src/expr.cpp"
__3q = (((struct name *)(((struct name *)__0this -> __O2__4expr.e1 ))))-> __O2__4name.n_qualifier ;
__0this -> __O2__4expr.e1 = find_name__FP4nameP8classdefP5tableiT1 ( ((struct name *)(((struct name *)__0this -> __O2__4expr.e1 ))), cc -> cot__11dcl_context , __1tbl , 109 , cc -> nof__11dcl_context ) ;
# 1193 "/home/claude/cfront-3/src/expr.cpp"

# 1195 "/home/claude/cfront-3/src/expr.cpp"
if (__3q && ((__0this -> __O2__4expr.e1 -> base__4node == 44 )|| (__0this -> __O2__4expr.e1 -> base__4node == 45 )))
# 1196 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 -> __O3__4expr.n_initializer = (((struct expr *)(((struct
# 1196 "/home/claude/cfront-3/src/expr.cpp"
expr *)__3q ))));
}

# 1199 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> __O2__4expr.e1 -> base__4node == 85 )&& (((struct name *)(((struct name *)__0this -> __O2__4expr.e1 ))))-> n_xref__4name ){ 
# 1201 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct
# 1201 "/home/claude/cfront-3/src/expr.cpp"
expr *)0 , (unsigned char )111 , __0this -> __O2__4expr.e1 , (struct expr *)0 ) ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ;
}

# 1205 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 1206 "/home/claude/cfront-3/src/expr.cpp"
case 162 :
# 1208 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCc ( (int )'e' , (const char *)"O orP missing for explicit destructor call\n")
# 1208 "/home/claude/cfront-3/src/expr.cpp"
;
break ;
case 45 :
# 1211 "/home/claude/cfront-3/src/expr.cpp"
case 44 :
# 1212 "/home/claude/cfront-3/src/expr.cpp"
if (((__0this -> __O3__4expr.e2 == 0 )&& (((struct ref *)(((struct ref *)__0this -> __O2__4expr.e1 ))))-> __O4__4expr.mem )&& ((((struct ref *)(((struct ref *)__0this ->
# 1212 "/home/claude/cfront-3/src/expr.cpp"
__O2__4expr.e1 ))))-> __O4__4expr.mem -> base__4node == 162 ))
# 1214 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1215 "/home/claude/cfront-3/src/expr.cpp"
Pref __4r ;

# 1215 "/home/claude/cfront-3/src/expr.cpp"
__4r = (((struct ref *)(((struct ref *)__0this -> __O2__4expr.e1 ))));
if (__4r -> base__4node == 45 ){ 
# 1217 "/home/claude/cfront-3/src/expr.cpp"
__4r -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )112 , (struct expr *)0 ,
# 1217 "/home/claude/cfront-3/src/expr.cpp"
__4r -> __O2__4expr.e1 ) ;
__4r -> base__4node = 44 ;
}
{ Pname __4m ;
bit __4qual ;
int __4tok ;

# 1220 "/home/claude/cfront-3/src/expr.cpp"
__4m = (((struct name *)(((struct name *)__4r -> __O4__4expr.mem ))));
__4qual = (__4m -> __O2__4name.n_qualifier != 0 );
__4tok = (__4qual ?0 :44 );

# 1225 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;

# 1228 "/home/claude/cfront-3/src/expr.cpp"
__4r = (((struct ref *)(((struct ref *)__0this -> __O2__4expr.e1 ))));
__4m = (((struct name *)(((struct name *)__4r -> __O4__4expr.mem ))));
if (__4m -> base__4node == 85 ){ 
# 1231 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __5ee ;

# 1231 "/home/claude/cfront-3/src/expr.cpp"
__5ee = call_dtor__FP4exprN21iT1 ( __0this -> __O2__4expr.e1 -> __O2__4expr.e1 , __4r -> __O4__4expr.mem , (struct expr *)0 , __4tok , one ) ;
__5ee -> __O1__4expr.tp = (struct type *)void_type ;
return __5ee ;
}

# 1234 "/home/claude/cfront-3/src/expr.cpp"
}
}
}
break ;

# 1239 "/home/claude/cfront-3/src/expr.cpp"
case 68 :
# 1240 "/home/claude/cfront-3/src/expr.cpp"
Ntmp = 0 ;
Ntmp_flag = 0 ;
if (in_quest < 1 ){ 
# 1243 "/home/claude/cfront-3/src/expr.cpp"
Ntmp_refd = 0 ;
Ntmp_flag_list = 0 ;
}
__0this -> __O4__4expr.cond = typ__4exprFP5table ( __0this -> __O4__4expr.cond , __1tbl ) ;
in_quest ++ ;
if (Ntmp_refd ){ 
# 1249 "/home/claude/cfront-3/src/expr.cpp"
Pname __3n ;
Pname __3nn ;

# 1249 "/home/claude/cfront-3/src/expr.cpp"
__3n = Ntmp_refd ;
__3nn = Ntmp_flag_list ;
for(;__3n && __3nn ;( (__3n = __3n -> __O1__4name.n_list ), (__3nn = __3nn -> __O1__4name.n_list )) ) { 
# 1253 "/home/claude/cfront-3/src/expr.cpp"
Pname __4nc ;

# 1253 "/home/claude/cfront-3/src/expr.cpp"
__4nc = __ct__4nameFPCc ( (struct name *)0 , (const char *)"") ;
((*__4nc ))= (*__3n );
{ char *__4str ;

# 1255 "/home/claude/cfront-3/src/expr.cpp"
__4str = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __3n -> __O2__4expr.string ) + 1 ))) ));
# 1255 "/home/claude/cfront-3/src/expr.cpp"

# 1256 "/home/claude/cfront-3/src/expr.cpp"
strcpy ( __4str , __3n -> __O2__4expr.string ) ;
__4nc -> __O2__4expr.string = (const char *)__4str ;
{ Pname __4nnc ;

# 1258 "/home/claude/cfront-3/src/expr.cpp"
__4nnc = __ct__4nameFPCc ( (struct name *)0 , (const char *)"") ;
((*__4nnc ))= (*__3nn );
__4str = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __3nn -> __O2__4expr.string ) + 1 ))) ));
# 1260 "/home/claude/cfront-3/src/expr.cpp"

# 1261 "/home/claude/cfront-3/src/expr.cpp"
strcpy ( __4str , __3nn -> __O2__4expr.string ) ;
__4nnc -> __O2__4expr.string = (const char *)__4str ;
{ struct con_dtor *__4t ;

# 1264 "/home/claude/cfront-3/src/expr.cpp"
struct con_dtor *__0__X108 ;

# 1263 "/home/claude/cfront-3/src/expr.cpp"
__4t = ( (__0__X108 = 0 ), ( ((__0__X108 || (__0__X108 = (struct con_dtor *)__nw__FUl ( (unsigned long )(sizeof (struct con_dtor))) ))?(
# 1263 "/home/claude/cfront-3/src/expr.cpp"
( (__0__X108 -> tn__8con_dtor = __4nc ), (__0__X108 -> condition__8con_dtor = ((struct expr *)__4nnc ))) , (__0__X108 -> next__8con_dtor = 0 )) :0 ), __0__X108 )
# 1263 "/home/claude/cfront-3/src/expr.cpp"
) ;
if (pdlist )__4t -> next__8con_dtor = pdlist ;
pdlist = __4t ;

# 1265 "/home/claude/cfront-3/src/expr.cpp"
}

# 1265 "/home/claude/cfront-3/src/expr.cpp"
}

# 1265 "/home/claude/cfront-3/src/expr.cpp"
}
}
Ntmp_flag = 0 ;
}
break ;

# 1271 "/home/claude/cfront-3/src/expr.cpp"
case 66 :
# 1272 "/home/claude/cfront-3/src/expr.cpp"
case 67 :
# 1273 "/home/claude/cfront-3/src/expr.cpp"
Ntmp = 0 ;
Ntmp_flag = 0 ;
if (in_quest < 2 ){ 
# 1276 "/home/claude/cfront-3/src/expr.cpp"
Ntmp_refd = 0 ;
Ntmp_flag_list = 0 ;
}
} }

# 1281 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O2__4expr.e1 ){ 
# 1282 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
if (is_ref__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) )__0this -> __O2__4expr.e1 = contents__4exprFv ( __0this -> __O2__4expr.e1 ) ;
__1t1 = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
if (Ntmp_flag ){ 
# 1286 "/home/claude/cfront-3/src/expr.cpp"
if ((__1b == 68 )|| in_quest ){ 
# 1287 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __4e ;

# 1287 "/home/claude/cfront-3/src/expr.cpp"
__4e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)Ntmp_flag , one ) ;
__4e -> __O1__4expr.tp = (struct type *)int_type ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __4e , __0this -> __O2__4expr.e1 ) ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = __1t1 ;
}
Ntmp_flag = 0 ;
}
}
else 
# 1296 "/home/claude/cfront-3/src/expr.cpp"
__1t1 = 0 ;

# 1298 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 ){ 
# 1299 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = typ__4exprFP5table ( __0this -> __O3__4expr.e2 , __1tbl ) ;
if (is_ref__4typeFv ( __0this -> __O3__4expr.e2 -> __O1__4expr.tp ) )__0this -> __O3__4expr.e2 = contents__4exprFv ( __0this -> __O3__4expr.e2 ) ;
__1t2 = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;
if (Ntmp_flag ){ 
# 1303 "/home/claude/cfront-3/src/expr.cpp"
if ((__1b == 68 )|| in_quest ){ 
# 1304 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __4e ;

# 1304 "/home/claude/cfront-3/src/expr.cpp"
__4e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)Ntmp_flag , one ) ;
__4e -> __O1__4expr.tp = (struct type *)int_type ;
if (__0this -> __O3__4expr.e2 -> base__4node == 140 ){ 
# 1307 "/home/claude/cfront-3/src/expr.cpp"
Ptype __5t ;

# 1307 "/home/claude/cfront-3/src/expr.cpp"
__5t = __0this -> __O3__4expr.e2 -> __O2__4expr.e1 -> __O1__4expr.tp ;
__0this -> __O3__4expr.e2 -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __4e , __0this -> __O3__4expr.e2 -> __O2__4expr.e1 ) ;
# 1308 "/home/claude/cfront-3/src/expr.cpp"

# 1309 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 -> __O2__4expr.e1 -> __O1__4expr.tp = __5t ;
}
else 
# 1310 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1311 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __4e , __0this -> __O3__4expr.e2 ) ;
# 1311 "/home/claude/cfront-3/src/expr.cpp"

# 1312 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 -> __O1__4expr.tp = __1t2 ;
}
}
Ntmp_flag = 0 ;
}
}
else 
# 1319 "/home/claude/cfront-3/src/expr.cpp"
__1t2 = 0 ;

# 1321 "/home/claude/cfront-3/src/expr.cpp"
switch (__1b ){ 
# 1322 "/home/claude/cfront-3/src/expr.cpp"
default :
# 1323 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1324 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __3x ;

# 1324 "/home/claude/cfront-3/src/expr.cpp"
__3x = oper_overload__4exprFP5table ( __0this , __1tbl ) ;
if (__3x ){ 
# 1326 "/home/claude/cfront-3/src/expr.cpp"
if ((((__3x -> __O1__4expr.tp != (((struct type *)any_type )))&& ((__1b == 48 )|| (__1b == 49 )))&& (__3x -> base__4node != 48 ))&&
# 1326 "/home/claude/cfront-3/src/expr.cpp"
(__3x -> base__4node != 49 ))
# 1331 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1359 "/home/claude/cfront-3/src/expr.cpp"
}
return __3x ;
}
if ((__1t2 && (__1t1 == 0 ))&& (__1t2 != __0this -> __O3__4expr.e2 -> __O1__4expr.tp ))__1t2 = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;
}
case 45 :
# 1365 "/home/claude/cfront-3/src/expr.cpp"
case 147 :
# 1366 "/home/claude/cfront-3/src/expr.cpp"
case 145 :
# 1367 "/home/claude/cfront-3/src/expr.cpp"
case 146 :
# 1368 "/home/claude/cfront-3/src/expr.cpp"
case 68 :
# 1369 "/home/claude/cfront-3/src/expr.cpp"
break ;
}

# 1372 "/home/claude/cfront-3/src/expr.cpp"
switch (__1b ){ 
# 1373 "/home/claude/cfront-3/src/expr.cpp"
case 68 :
# 1374 "/home/claude/cfront-3/src/expr.cpp"
in_quest -- ;
case 66 :
# 1376 "/home/claude/cfront-3/src/expr.cpp"
case 67 :
# 1377 "/home/claude/cfront-3/src/expr.cpp"
if (Ntmp && (__1b != 68 )){ 
# 1378 "/home/claude/cfront-3/src/expr.cpp"
Ntmp_dtor = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __0this ,
# 1378 "/home/claude/cfront-3/src/expr.cpp"
Ntmp_dtor ) ;

# 1380 "/home/claude/cfront-3/src/expr.cpp"
}

# 1382 "/home/claude/cfront-3/src/expr.cpp"
if ((__1b == 68 )&& Ntmp_refd ){ 
# 1383 "/home/claude/cfront-3/src/expr.cpp"
Pname __3n ;
Pname __3nn ;

# 1383 "/home/claude/cfront-3/src/expr.cpp"
__3n = Ntmp_refd ;
__3nn = Ntmp_flag_list ;
for(;__3n && __3nn ;( (__3n = __3n -> __O1__4name.n_list ), (__3nn = __3nn -> __O1__4name.n_list )) ) { 
# 1387 "/home/claude/cfront-3/src/expr.cpp"
Pname __4nc ;

# 1387 "/home/claude/cfront-3/src/expr.cpp"
__4nc = __ct__4nameFPCc ( (struct name *)0 , (const char *)"") ;
((*__4nc ))= (*__3n );
{ char *__4str ;

# 1389 "/home/claude/cfront-3/src/expr.cpp"
__4str = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __3n -> __O2__4expr.string ) + 1 ))) ));
# 1389 "/home/claude/cfront-3/src/expr.cpp"

# 1390 "/home/claude/cfront-3/src/expr.cpp"
strcpy ( __4str , __3n -> __O2__4expr.string ) ;
__4nc -> __O2__4expr.string = (const char *)__4str ;
{ Pname __4nnc ;

# 1392 "/home/claude/cfront-3/src/expr.cpp"
__4nnc = __ct__4nameFPCc ( (struct name *)0 , (const char *)"") ;
((*__4nnc ))= (*__3nn );
__4str = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __3nn -> __O2__4expr.string ) + 1 ))) ));
# 1394 "/home/claude/cfront-3/src/expr.cpp"

# 1395 "/home/claude/cfront-3/src/expr.cpp"
strcpy ( __4str , __3nn -> __O2__4expr.string ) ;
__4nnc -> __O2__4expr.string = (const char *)__4str ;
{ struct con_dtor *__4t ;

# 1398 "/home/claude/cfront-3/src/expr.cpp"
struct con_dtor *__0__X109 ;

# 1397 "/home/claude/cfront-3/src/expr.cpp"
__4t = ( (__0__X109 = 0 ), ( ((__0__X109 || (__0__X109 = (struct con_dtor *)__nw__FUl ( (unsigned long )(sizeof (struct con_dtor))) ))?(
# 1397 "/home/claude/cfront-3/src/expr.cpp"
( (__0__X109 -> tn__8con_dtor = __4nc ), (__0__X109 -> condition__8con_dtor = ((struct expr *)__4nnc ))) , (__0__X109 -> next__8con_dtor = 0 )) :0 ), __0__X109 )
# 1397 "/home/claude/cfront-3/src/expr.cpp"
) ;
if (pdlist )__4t -> next__8con_dtor = pdlist ;
pdlist = __4t ;

# 1399 "/home/claude/cfront-3/src/expr.cpp"
}

# 1399 "/home/claude/cfront-3/src/expr.cpp"
}

# 1399 "/home/claude/cfront-3/src/expr.cpp"
}
}
Ntmp_flag = 0 ;
}
}

# 1405 "/home/claude/cfront-3/src/expr.cpp"
__1t = ((__1t1 == 0 )?__1t2 :((__1t2 == 0 )?__1t1 :(((struct type *)0 ))));
switch (__1b ){ 
# 1407 "/home/claude/cfront-3/src/expr.cpp"
case 180 :
# 1408 "/home/claude/cfront-3/src/expr.cpp"
__0this -> base__4node = 44 ;

# 1410 "/home/claude/cfront-3/src/expr.cpp"
case 45 :
# 1411 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1414 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __3a ;
Ptype __3at ;

# 1414 "/home/claude/cfront-3/src/expr.cpp"
__3a = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
__3at = skiptypedefs__4typeFv ( __3a -> __O1__4expr.tp ) ;
if (__0this -> base__4node == 45 ){ 
# 1417 "/home/claude/cfront-3/src/expr.cpp"
__3a = address__4exprFv ( __3a ) ;
__3at = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __3at ) ) ;
}

# 1421 "/home/claude/cfront-3/src/expr.cpp"
{ Pname __3cn ;
Pclass __3mm ;

# 1424 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __3p ;
Ptype __3pt ;
Pname __3pcn ;

# 1421 "/home/claude/cfront-3/src/expr.cpp"
__3cn = ((__3at -> base__4node == 125 )?is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)__3at ))))-> typ__5pvtyp ) :(((struct name *)0 )));
__3mm = (__3cn ?(((struct classdef *)(((struct classdef *)__3cn -> __O1__4expr.tp )))):(((struct classdef *)0 )));

# 1424 "/home/claude/cfront-3/src/expr.cpp"
__3p = typ__4exprFP5table ( __0this -> __O3__4expr.e2 , __1tbl ) ;
__3pt = skiptypedefs__4typeFv ( __3p -> __O1__4expr.tp ) ;
__3pcn = is_cl_obj__4typeFv ( __3pt ) ;

# 1429 "/home/claude/cfront-3/src/expr.cpp"
if (__3pcn ){ 
# 1430 "/home/claude/cfront-3/src/expr.cpp"
Pclass __4cl ;
Pname __4found ;

# 1430 "/home/claude/cfront-3/src/expr.cpp"
__4cl = (((struct classdef *)(((struct classdef *)__3pcn -> __O1__4expr.tp ))));
__4found = 0 ;
{ { Pname __4on ;

# 1432 "/home/claude/cfront-3/src/expr.cpp"
__4on = __4cl -> conv__8classdef ;

# 1432 "/home/claude/cfront-3/src/expr.cpp"
for(;__4on ;__4on = __4on -> __O1__4name.n_list ) { 
# 1433 "/home/claude/cfront-3/src/expr.cpp"
Pfct __5f ;
Pptr __5frt ;

# 1435 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__1__X110 ;

# 1435 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__1__X111 ;

# 1433 "/home/claude/cfront-3/src/expr.cpp"
__5f = (((struct fct *)(((struct fct *)__4on -> __O1__4expr.tp ))));
__5frt = (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv ( __5f -> returns__3fct ) ))));
if ((__5frt -> base__4node != 125 )|| ((((struct ptr *)(((struct ptr *)__5frt ))))-> memof__3ptr == 0 ))break ;
if (( (__1__X110 = (((struct ptr *)(((struct ptr *)__5frt ))))-> memof__3ptr ), ( (__1__X111 = __3mm ), ( ((__1__X110 == __1__X111 )?1 :((__1__X110 && __1__X111 )?(((int
# 1436 "/home/claude/cfront-3/src/expr.cpp"
)same_class__8classdefFP8classdefi ( __1__X110 , __1__X111 , 0 ) )):0 ))) ) ) || has_base__8classdefFP8classdefiT2 ( __3mm , (((struct ptr *)(((struct ptr *)__5frt ))))-> memof__3ptr ,
# 1436 "/home/claude/cfront-3/src/expr.cpp"
0 , 0 ) ){ 
# 1437 "/home/claude/cfront-3/src/expr.cpp"
if (__4found )
# 1438 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1438 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V52 ;

# 1438 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V53 ;

# 1438 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"two possible conversions forP toM: %n and %n", (const struct ea *)( ((& __0__V52 )-> __O1__2ea.p =
# 1438 "/home/claude/cfront-3/src/expr.cpp"
((const void *)__4found )), (& __0__V52 )) , (const struct ea *)( ((& __0__V53 )-> __O1__2ea.p = ((const void
# 1438 "/home/claude/cfront-3/src/expr.cpp"
*)__4on )), (& __0__V53 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 1440 "/home/claude/cfront-3/src/expr.cpp"
__4found = __4on ;
}
}

# 1444 "/home/claude/cfront-3/src/expr.cpp"
if (__4found ){ 
# 1444 "/home/claude/cfront-3/src/expr.cpp"
struct ref *__0__X112 ;

# 1444 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X113 ;

# 1444 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X114 ;

# 1444 "/home/claude/cfront-3/src/expr.cpp"
struct call *__0__X115 ;

# 1444 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X116 ;

# 1444 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X117 ;

# 1445 "/home/claude/cfront-3/src/expr.cpp"
__3p = (struct expr *)( (__0__X112 = 0 ), ( (__2__X113 = __3p ), ( (__2__X114 = (struct expr *)__4found ), ( ((__0__X112 ||
# 1445 "/home/claude/cfront-3/src/expr.cpp"
(__0__X112 = (struct ref *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ref))) ))?( (__0__X112 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X112 ), ((unsigned
# 1445 "/home/claude/cfront-3/src/expr.cpp"
char )45 ), __2__X113 , (struct expr *)0 ) ), (__0__X112 -> __O4__4expr.mem = __2__X114 )) :0 ), __0__X112 ) ) ) )
# 1445 "/home/claude/cfront-3/src/expr.cpp"
;
__3p = (struct expr *)( (__0__X115 = 0 ), ( (__2__X116 = __3p ), ( (__2__X117 = 0 ), ( ((__0__X115 || (__0__X115 =
# 1446 "/home/claude/cfront-3/src/expr.cpp"
(struct call *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct call))) ))?(__0__X115 = (struct call *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X115 ), (unsigned char )109 ,
# 1446 "/home/claude/cfront-3/src/expr.cpp"
__2__X116 , __2__X117 ) ):0 ), __0__X115 ) ) ) ) ;
__3p = typ__4exprFP5table ( __3p , __1tbl ) ;
__3pt = skiptypedefs__4typeFv ( __3p -> __O1__4expr.tp ) ;
}

# 1449 "/home/claude/cfront-3/src/expr.cpp"
}

# 1449 "/home/claude/cfront-3/src/expr.cpp"
}

# 1451 "/home/claude/cfront-3/src/expr.cpp"
}
if ((__3pt -> base__4node != 125 )|| ((((struct ptr *)(((struct ptr *)__3pt ))))-> memof__3ptr == 0 )){ 
# 1453 "/home/claude/cfront-3/src/expr.cpp"
if (__1b == 45 )
# 1454 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1454 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V54 ;
# 1454 "/home/claude/cfront-3/src/expr.cpp"

# 1454 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"P toMX in .*E: %t", (const struct ea *)( ((& __0__V54 )-> __O1__2ea.p =
# 1454 "/home/claude/cfront-3/src/expr.cpp"
((const void *)__3pt )), (& __0__V54 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1454 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 ) ;
} else 
# 1456 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1456 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V55 ;

# 1456 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"P toMX in ->*E: %t", (const struct ea *)( ((& __0__V55 )-> __O1__2ea.p =
# 1456 "/home/claude/cfront-3/src/expr.cpp"
((const void *)__3pt )), (& __0__V55 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1456 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 ) ;
} __0this -> __O1__4expr.tp = (struct type *)any_type ;
__0this -> base__4node = 144 ;
return __0this ;
}
{ Pclass __3pm ;

# 1462 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__1__X118 ;

# 1462 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__1__X119 ;

# 1461 "/home/claude/cfront-3/src/expr.cpp"
__3pm = (((struct ptr *)(((struct ptr *)__3pt ))))-> memof__3ptr ;

# 1463 "/home/claude/cfront-3/src/expr.cpp"
if (! ( (__1__X118 = __3mm ), ( (__1__X119 = __3pm ), ( ((__1__X118 == __1__X119 )?1 :((__1__X118 && __1__X119 )?(((int )same_class__8classdefFP8classdefi ( __1__X118 ,
# 1463 "/home/claude/cfront-3/src/expr.cpp"
__1__X119 , 0 ) )):0 ))) ) ) ){ 
# 1463 "/home/claude/cfront-3/src/expr.cpp"
struct texpr *__0__X121 ;

# 1463 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X122 ;

# 1464 "/home/claude/cfront-3/src/expr.cpp"
if (has_base__8classdefFP8classdefiT2 ( __3mm , __3pm , 0 , 0 ) == 0 ){ 
# 1464 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X120 ;

# 1465 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1465 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V56 ;

# 1465 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V57 ;

# 1465 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"badOT in .*E: %t (%s*X)", (const struct ea *)( (__2__X120 = (const void
# 1465 "/home/claude/cfront-3/src/expr.cpp"
*)__3a -> __O1__4expr.tp ), ( ((& __0__V56 )-> __O1__2ea.p = __2__X120 ), (& __0__V56 )) ) , (const struct ea *)__ct__2eaFPCv (
# 1465 "/home/claude/cfront-3/src/expr.cpp"
& __0__V57 , (const void *)__3pm -> string__8classdef ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 1465 "/home/claude/cfront-3/src/expr.cpp"

# 1466 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)any_type ;
} }
__3a = (struct expr *)( (__0__X121 = 0 ), ( (__2__X122 = __3pm -> this_type__8classdef ), ( ((__0__X121 || (__0__X121 = (struct
# 1468 "/home/claude/cfront-3/src/expr.cpp"
texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr))) ))?( (__0__X121 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X121 ), ((unsigned char )191 ),
# 1468 "/home/claude/cfront-3/src/expr.cpp"
__3a , (struct expr *)0 ) ), (__0__X121 -> __O4__4expr.tp2 = __2__X122 )) :0 ), __0__X121 ) ) ) ;
__0this -> __O2__4expr.e1 = (__3a = typ__4exprFP5table ( __3a , __1tbl ) );
}

# 1472 "/home/claude/cfront-3/src/expr.cpp"
{ Ptype __3tpx ;

# 1472 "/home/claude/cfront-3/src/expr.cpp"
__3tpx = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__3pt ))))-> typ__5pvtyp ) ;

# 1474 "/home/claude/cfront-3/src/expr.cpp"
if (__3tpx -> base__4node == 108 ){ 
# 1475 "/home/claude/cfront-3/src/expr.cpp"
__0this -> base__4node = 173 ;
__0this -> __O4__4expr.tp2 = (struct type *)__3mm ;
__0this -> __O2__4expr.e1 = __3a ;
__0this -> __O3__4expr.e2 = __3p ;
}
else { 
# 1480 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X123 ;

# 1480 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X124 ;

# 1480 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X125 ;

# 1480 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X126 ;

# 1481 "/home/claude/cfront-3/src/expr.cpp"
__3a = (struct expr *)( (__0__X123 = 0 ), ( (__2__X124 = Pchar_type ), ( ((__0__X123 || (__0__X123 = (struct cast *)__nw__4exprSFUl ( (unsigned
# 1481 "/home/claude/cfront-3/src/expr.cpp"
long )(sizeof (struct cast))) ))?( (__0__X123 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X123 ), (unsigned char )191 , __3a , (struct
# 1481 "/home/claude/cfront-3/src/expr.cpp"
expr *)0 ) ), (__0__X123 -> __O1__4expr.tp = (__0__X123 -> __O4__4expr.tp2 = __2__X124 ))) :0 ), __0__X123 ) ) ) ;
__3p = (struct expr *)( (__0__X125 = 0 ), ( (__2__X126 = (struct type *)int_type ), ( ((__0__X125 || (__0__X125 = (struct cast *)__nw__4exprSFUl (
# 1482 "/home/claude/cfront-3/src/expr.cpp"
(unsigned long )(sizeof (struct cast))) ))?( (__0__X125 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X125 ), (unsigned char )191 , __3p ,
# 1482 "/home/claude/cfront-3/src/expr.cpp"
(struct expr *)0 ) ), (__0__X125 -> __O1__4expr.tp = (__0__X125 -> __O4__4expr.tp2 = __2__X126 ))) :0 ), __0__X125 ) ) ) ;
__3p = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )55 , __3p , one ) ;
__3p -> __O1__4expr.tp = (struct type *)int_type ;
{ Pexpr __4pl ;

# 1486 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X127 ;

# 1485 "/home/claude/cfront-3/src/expr.cpp"
__4pl = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )54 , __3a , __3p ) ;
__4pl -> __O1__4expr.tp = Pchar_type ;
__0this -> base__4node = 111 ;
__3pt = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __3tpx ) ;
(((struct ptr *)(((struct ptr *)__3pt ))))-> b_const__4type = (((struct ptr *)(((struct ptr *)__3tpx ))))-> b_const__4type ;
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X127 = 0 ), ( ((__0__X127 || (__0__X127 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof
# 1490 "/home/claude/cfront-3/src/expr.cpp"
(struct cast))) ))?( (__0__X127 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X127 ), (unsigned char )191 , __4pl , (struct expr *)0 ) ),
# 1490 "/home/claude/cfront-3/src/expr.cpp"
(__0__X127 -> __O1__4expr.tp = (__0__X127 -> __O4__4expr.tp2 = __3pt ))) :0 ), __0__X127 ) ) ;
__0this -> __O3__4expr.e2 = 0 ;

# 1491 "/home/claude/cfront-3/src/expr.cpp"
}
}
__0this -> __O1__4expr.tp = __3tpx ;
return (is_ref__4typeFv ( __0this -> __O1__4expr.tp ) ?contents__4exprFv ( __0this ) :__0this );

# 1494 "/home/claude/cfront-3/src/expr.cpp"
}

# 1494 "/home/claude/cfront-3/src/expr.cpp"
}

# 1494 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 1497 "/home/claude/cfront-3/src/expr.cpp"
case 146 :
# 1498 "/home/claude/cfront-3/src/expr.cpp"
case 109 :
# 1499 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = call_fct__4exprFP5table ( __0this , __1tbl ) ;
if (is_ref__4typeFv ( __0this -> __O1__4expr.tp ) )return contents__4exprFv ( __0this ) ;
return __0this ;

# 1503 "/home/claude/cfront-3/src/expr.cpp"
case 111 :
# 1504 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O2__4expr.e1 == dummy )error__FPCc ( (const char *)"O missing before []\n") ;
if (__0this -> __O3__4expr.e2 == dummy )error__FPCc ( (const char *)"subscriptE missing") ;

# 1507 "/home/claude/cfront-3/src/expr.cpp"
if (__1t ){ 
# 1508 "/home/claude/cfront-3/src/expr.cpp"
__1t = skiptypedefs__4typeFv ( __1t ) ;
if ((__1t -> base__4node == 125 )&& (((struct ptr *)(((struct ptr *)__1t ))))-> memof__3ptr )error__FPCc ( (const char *)"P toM dereferenced")
# 1509 "/home/claude/cfront-3/src/expr.cpp"
;
__0this -> __O1__4expr.tp = deref__4typeFv ( __1t ) ;
}
else { 
# 1514 "/home/claude/cfront-3/src/expr.cpp"
if (vec_type__4typeFv ( __1t1 ) ){ 
# 1515 "/home/claude/cfront-3/src/expr.cpp"
switch (__1t2 -> base__4node ){ 
# 1516 "/home/claude/cfront-3/src/expr.cpp"
case 5 :
# 1517 "/home/claude/cfront-3/src/expr.cpp"
case 29 :
# 1518 "/home/claude/cfront-3/src/expr.cpp"
case 21 :
# 1519 "/home/claude/cfront-3/src/expr.cpp"
case 22 :
# 1520 "/home/claude/cfront-3/src/expr.cpp"
case
# 1520 "/home/claude/cfront-3/src/expr.cpp"
122 :
# 1521 "/home/claude/cfront-3/src/expr.cpp"
case 121 :
# 1522 "/home/claude/cfront-3/src/expr.cpp"
break ;
default :
# 1524 "/home/claude/cfront-3/src/expr.cpp"
{ Pname __6cn ;

# 1524 "/home/claude/cfront-3/src/expr.cpp"
__6cn = is_cl_obj__4typeFv ( __1t2 ) ;
if (__6cn )
# 1526 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = check_cond__FP4exprUcP5table ( __0this -> __O3__4expr.e2 , (unsigned char )111 , __1tbl ) ;
else 
# 1528 "/home/claude/cfront-3/src/expr.cpp"
( kind__4typeFUcN21 ( __1t2 , ((unsigned char )111 ), (unsigned char )'I' , (unsigned char )1 ) )
# 1528 "/home/claude/cfront-3/src/expr.cpp"
;
}
}
__1t1 = skiptypedefs__4typeFv ( __1t1 ) ;
if ((__1t1 -> base__4node == 125 )&& (((struct ptr *)(((struct ptr *)__1t1 ))))-> memof__3ptr )error__FPCc ( (const char *)"P toM dereferenced")
# 1532 "/home/claude/cfront-3/src/expr.cpp"
;
__0this -> __O1__4expr.tp = deref__4typeFv ( __1t1 ) ;
((void )tsizeof__4typeFi ( __0this -> __O1__4expr.tp , 0 ) );
}
else if (vec_type__4typeFv ( __1t2 ) ){ 
# 1537 "/home/claude/cfront-3/src/expr.cpp"
( kind__4typeFUcN21 ( __1t1 , ((unsigned char )111 ), (unsigned char )'I' ,
# 1537 "/home/claude/cfront-3/src/expr.cpp"
(unsigned char )1 ) ) ;
__1t2 = skiptypedefs__4typeFv ( __1t2 ) ;
if ((__1t2 -> base__4node == 125 )&& (((struct ptr *)(((struct ptr *)__1t2 ))))-> memof__3ptr )error__FPCc ( (const char *)"P toM dereferenced")
# 1539 "/home/claude/cfront-3/src/expr.cpp"
;
__0this -> __O1__4expr.tp = deref__4typeFv ( __1t2 ) ;
((void )tsizeof__4typeFi ( __0this -> __O1__4expr.tp , 0 ) );
}
else { 
# 1544 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1544 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V58 ;

# 1544 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V59 ;

# 1544 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"[] applied to nonPT:%t[%t]", (const struct ea *)( ((& __0__V58 )-> __O1__2ea.p =
# 1544 "/home/claude/cfront-3/src/expr.cpp"
((const void *)__1t1 )), (& __0__V58 )) , (const struct ea *)( ((& __0__V59 )-> __O1__2ea.p = ((const void
# 1544 "/home/claude/cfront-3/src/expr.cpp"
*)__1t2 )), (& __0__V59 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__0this -> __O1__4expr.tp = (struct type *)any_type ;
} }
}

# 1549 "/home/claude/cfront-3/src/expr.cpp"
if (is_ref__4typeFv ( __0this -> __O1__4expr.tp ) )return contents__4exprFv ( __0this ) ;

# 1551 "/home/claude/cfront-3/src/expr.cpp"
return __0this ;

# 1553 "/home/claude/cfront-3/src/expr.cpp"
case 145 :
# 1554 "/home/claude/cfront-3/src/expr.cpp"
case 112 :
# 1556 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1557 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O3__4expr.e2 -> base__4node ){ 
# 1558 "/home/claude/cfront-3/src/expr.cpp"
case 147 :
# 1559 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> base__4node == 112 )&& (__0this -> __O3__4expr.e2 ->
# 1559 "/home/claude/cfront-3/src/expr.cpp"
__O3__4expr.e2 -> base__4node == 85 )){ 
# 1561 "/home/claude/cfront-3/src/expr.cpp"
const char *__5s ;

# 1561 "/home/claude/cfront-3/src/expr.cpp"
__5s = __0this -> __O3__4expr.e2 -> __O3__4expr.e2 -> __O2__4expr.string ;
if ((((__5s [0 ])== '_' )&& (__5s [1 ]))&& ((__5s [1 ])== '_' )){ 
# 1563 "/home/claude/cfront-3/src/expr.cpp"
if ((__5s [2 ])&& (((__5s [2 ])== 'R' )|| ((__5s [2 ])== 'V' ))){ 
# 1564 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const
# 1564 "/home/claude/cfront-3/src/expr.cpp"
char *)"address of non-lvalue") ;
break ;
}
}
}
case 71 :
# 1570 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1571 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __5ee ;

# 1571 "/home/claude/cfront-3/src/expr.cpp"
__5ee = __0this -> __O3__4expr.e2 ;
__5ee -> __O1__4expr.tp = 0 ;
__5ee -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , (struct expr *)0 , __5ee -> __O3__4expr.e2 ) ;
( (__0this ?(((void )(__0this ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 1574 "/home/claude/cfront-3/src/expr.cpp"
;
return typ__4exprFP5table ( __5ee , __1tbl ) ;
}
case 68 :
# 1578 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1579 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __5ee ;

# 1579 "/home/claude/cfront-3/src/expr.cpp"
__5ee = __0this -> __O3__4expr.e2 ;
__5ee -> __O1__4expr.tp = 0 ;
__5ee -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , (struct expr *)0 , __5ee -> __O2__4expr.e1 ) ;
__5ee -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , (struct expr *)0 , __5ee -> __O3__4expr.e2 ) ;
( (__0this ?(((void )(__0this ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 1583 "/home/claude/cfront-3/src/expr.cpp"
;
return typ__4exprFP5table ( __5ee , __1tbl ) ;
}
case 48 :
# 1587 "/home/claude/cfront-3/src/expr.cpp"
case 49 :
# 1588 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 -> __O2__4expr.e1 )break ;
case 70 :
# 1590 "/home/claude/cfront-3/src/expr.cpp"
case 126 :
# 1591 "/home/claude/cfront-3/src/expr.cpp"
case 127 :
# 1592 "/home/claude/cfront-3/src/expr.cpp"
case 128 :
# 1593 "/home/claude/cfront-3/src/expr.cpp"
case 129 :
# 1594 "/home/claude/cfront-3/src/expr.cpp"
case 130 :
# 1595 "/home/claude/cfront-3/src/expr.cpp"
case 131 :
# 1596 "/home/claude/cfront-3/src/expr.cpp"
case 132 :
# 1597 "/home/claude/cfront-3/src/expr.cpp"
case 133 :
# 1598 "/home/claude/cfront-3/src/expr.cpp"
case 134 :
# 1599 "/home/claude/cfront-3/src/expr.cpp"
case 135 :
# 1600 "/home/claude/cfront-3/src/expr.cpp"
return address__4exprFv ( __0this ->
# 1600 "/home/claude/cfront-3/src/expr.cpp"
__O3__4expr.e2 ) ;
}

# 1603 "/home/claude/cfront-3/src/expr.cpp"
{ int __3oerror_count ;

# 1603 "/home/claude/cfront-3/src/expr.cpp"
__3oerror_count = error_count ;
if (lval__4exprFUc ( __0this -> __O3__4expr.e2 , (unsigned char )112 ) == 0 ){ 
# 1605 "/home/claude/cfront-3/src/expr.cpp"
if (error_count > __3oerror_count ){ 
# 1607 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp =
# 1607 "/home/claude/cfront-3/src/expr.cpp"
(struct type *)any_type ;
return __0this ;
}
}

# 1612 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __1t ) ) ;

# 1614 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 -> __O1__4expr.tp -> base__4node == 110 ){ 
# 1615 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 -> base__4node != 85 ){ 
# 1616 "/home/claude/cfront-3/src/expr.cpp"
__0this -> base__4node = 191 ;
# 1616 "/home/claude/cfront-3/src/expr.cpp"

# 1617 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O4__4expr.tp2 = __0this -> __O1__4expr.tp ;
__0this -> __O2__4expr.e1 = __0this -> __O3__4expr.e2 ;
__0this -> __O3__4expr.e2 = 0 ;
return __0this ;
}
}

# 1624 "/home/claude/cfront-3/src/expr.cpp"
if (__1t -> base__4node == 108 )
# 1625 "/home/claude/cfront-3/src/expr.cpp"
(((struct ptr *)(((struct ptr *)__0this -> __O1__4expr.tp ))))-> memof__3ptr = (((struct fct *)(((struct fct *)__1t ))))-> memof__3fct ;

# 1630 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O3__4expr.e2 -> base__4node ){ 
# 1631 "/home/claude/cfront-3/src/expr.cpp"
case 85 :
# 1632 "/home/claude/cfront-3/src/expr.cpp"
mname :
# 1633 "/home/claude/cfront-3/src/expr.cpp"
{ Pname __5n2 ;
Pname __5cn ;

# 1633 "/home/claude/cfront-3/src/expr.cpp"
__5n2 = (((struct name *)(((struct name *)__0this -> __O3__4expr.e2 ))));
__5cn = ((__5n2 -> __O4__4expr.n_table && (__5n2 -> __O4__4expr.n_table != gtbl ))?__5n2 -> __O4__4expr.n_table -> t_name__5table :(((struct name *)0 )));

# 1636 "/home/claude/cfront-3/src/expr.cpp"
if (__5cn == 0 )break ;

# 1638 "/home/claude/cfront-3/src/expr.cpp"
if ((__1t -> base__4node == 108 )&& (((struct fct *)(((struct fct *)__1t ))))-> f_static__3fct ){ 
# 1639 "/home/claude/cfront-3/src/expr.cpp"
(((struct ptr *)(((struct ptr *)__0this -> __O1__4expr.tp ))))-> memof__3ptr = 0 ;
# 1639 "/home/claude/cfront-3/src/expr.cpp"

# 1640 "/home/claude/cfront-3/src/expr.cpp"
break ;
}

# 1643 "/home/claude/cfront-3/src/expr.cpp"
switch (__1t -> base__4node ){ 
# 1644 "/home/claude/cfront-3/src/expr.cpp"
case 76 :
# 1645 "/home/claude/cfront-3/src/expr.cpp"
return __0this -> __O3__4expr.e2 ;
case 108 :
# 1648 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1649 "/home/claude/cfront-3/src/expr.cpp"
Pclass __7cl ;

# 1650 "/home/claude/cfront-3/src/expr.cpp"
struct ival *__0__X130 ;

# 1649 "/home/claude/cfront-3/src/expr.cpp"
__7cl = (((struct classdef *)(((struct classdef *)__5cn -> __O1__4expr.tp ))));
(((struct ptr *)(((struct ptr *)__0this -> __O1__4expr.tp ))))-> memof__3ptr = __7cl ;

# 1652 "/home/claude/cfront-3/src/expr.cpp"
if ((((struct fct *)(((struct fct *)__1t ))))-> f_virtual__3fct ){ 
# 1652 "/home/claude/cfront-3/src/expr.cpp"
struct ival *__0__X128 ;

# 1652 "/home/claude/cfront-3/src/expr.cpp"
long long __2__X129 ;

# 1654 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X128 = 0 ), ( (__2__X129 = (((struct fct *)(((struct fct *)__1t ))))-> f_virtual__3fct ), ( ((__0__X128 ||
# 1654 "/home/claude/cfront-3/src/expr.cpp"
(__0__X128 = (struct ival *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ival))) ))?( (__0__X128 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X128 ), (unsigned
# 1654 "/home/claude/cfront-3/src/expr.cpp"
char )150 , (struct expr *)0 , (struct expr *)0 ) ), (__0__X128 -> __O2__4expr.i1 = __2__X129 )) :0 ), __0__X128 ) ) )
# 1654 "/home/claude/cfront-3/src/expr.cpp"
;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , __0this -> __O2__4expr.e1 ) ;
__0this -> __O3__4expr.e2 = zero ;
__0this -> base__4node = 124 ;
return __0this ;
}

# 1662 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X130 = 0 ), ( ((__0__X130 || (__0__X130 = (struct ival *)__nw__4exprSFUl ( (unsigned long )(sizeof
# 1662 "/home/claude/cfront-3/src/expr.cpp"
(struct ival))) ))?( (__0__X130 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X130 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 )
# 1662 "/home/claude/cfront-3/src/expr.cpp"
), (__0__X130 -> __O2__4expr.i1 = ((long long )-1))) :0 ), __0__X130 ) ) ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , __0this -> __O2__4expr.e1 ) ;

# 1665 "/home/claude/cfront-3/src/expr.cpp"
if (((((struct name *)(((struct name *)__0this -> __O3__4expr.e2 ))))-> n_oper__4name == 70 )&& (look__5tableFPCcUc ( __7cl -> memtbl__8classdef , __0this -> __O3__4expr.e2 -> __O2__4expr.string , (unsigned
# 1665 "/home/claude/cfront-3/src/expr.cpp"
char )0 ) -> __O1__4expr.tp -> base__4node != 76 ))
# 1670 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1671 "/home/claude/cfront-3/src/expr.cpp"
Pname __8nmw ;

# 1672 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X131 ;

# 1672 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X132 ;

# 1671 "/home/claude/cfront-3/src/expr.cpp"
__8nmw = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
((*__8nmw ))= (*(((struct name *)(((struct name *)__0this -> __O3__4expr.e2 )))));
__0this -> __O3__4expr.e2 = (struct expr *)( (__0__X131 = 0 ), ( (__2__X132 = Pfct_type ), ( ((__0__X131 || (__0__X131 = (struct cast *)__nw__4exprSFUl (
# 1673 "/home/claude/cfront-3/src/expr.cpp"
(unsigned long )(sizeof (struct cast))) ))?( (__0__X131 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X131 ), (unsigned char )191 , ((struct
# 1673 "/home/claude/cfront-3/src/expr.cpp"
expr *)__8nmw ), (struct expr *)0 ) ), (__0__X131 -> __O1__4expr.tp = (__0__X131 -> __O4__4expr.tp2 = __2__X132 ))) :0 ), __0__X131 ) ) ) ;
# 1673 "/home/claude/cfront-3/src/expr.cpp"

# 1674 "/home/claude/cfront-3/src/expr.cpp"
}
else { 
# 1675 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X133 ;

# 1675 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X134 ;

# 1675 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X135 ;

# 1676 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = (struct expr *)( (__0__X133 = 0 ), ( (__2__X134 = Pfct_type ), ( (__2__X135 = __0this -> __O3__4expr.e2 ), (
# 1676 "/home/claude/cfront-3/src/expr.cpp"
((__0__X133 || (__0__X133 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X133 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X133 ),
# 1676 "/home/claude/cfront-3/src/expr.cpp"
(unsigned char )191 , __2__X135 , (struct expr *)0 ) ), (__0__X133 -> __O1__4expr.tp = (__0__X133 -> __O4__4expr.tp2 = __2__X134 ))) :0 ), __0__X133 )
# 1676 "/home/claude/cfront-3/src/expr.cpp"
) ) ) ;
}
__0this -> base__4node = 124 ;
return __0this ;
}

# 1682 "/home/claude/cfront-3/src/expr.cpp"
default :
# 1683 "/home/claude/cfront-3/src/expr.cpp"
if (__5n2 -> n_stclass__4name != 31 ){ 
# 1683 "/home/claude/cfront-3/src/expr.cpp"
struct ival *__0__X136 ;

# 1683 "/home/claude/cfront-3/src/expr.cpp"
long long __2__X137 ;

# 1684 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X136 = 0 ), ( (__2__X137 = (__5n2 -> n_offset__4name + 1 )), ( ((__0__X136 || (__0__X136 =
# 1684 "/home/claude/cfront-3/src/expr.cpp"
(struct ival *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ival))) ))?( (__0__X136 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X136 ), (unsigned char
# 1684 "/home/claude/cfront-3/src/expr.cpp"
)150 , (struct expr *)0 , (struct expr *)0 ) ), (__0__X136 -> __O2__4expr.i1 = __2__X137 )) :0 ), __0__X136 ) ) ) ;
# 1684 "/home/claude/cfront-3/src/expr.cpp"

# 1685 "/home/claude/cfront-3/src/expr.cpp"
(((struct ptr *)(((struct ptr *)__0this -> __O1__4expr.tp ))))-> memof__3ptr = (((struct classdef *)(((struct classdef *)__5cn -> __O1__4expr.tp ))));

# 1687 "/home/claude/cfront-3/src/expr.cpp"
}
else 
# 1689 "/home/claude/cfront-3/src/expr.cpp"
return __0this ;
}

# 1692 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = (struct type *)int_type ;
__0this -> __O3__4expr.e2 = 0 ;
__0this -> __O4__4expr.tp2 = __0this -> __O1__4expr.tp ;
__0this -> base__4node = 191 ;
return __0this ;
}
case 45 :
# 1699 "/home/claude/cfront-3/src/expr.cpp"
case 44 :
# 1700 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1701 "/home/claude/cfront-3/src/expr.cpp"
Pname __5m ;

# 1701 "/home/claude/cfront-3/src/expr.cpp"
__5m = (((struct name *)(((struct name *)__0this -> __O3__4expr.e2 -> __O4__4expr.mem ))));
while (__5m -> base__4node == 177 )__5m = (((struct name *)(((struct name *)(((struct expr *)(((struct expr *)__5m ))))-> __O4__4expr.mem ))));

# 1704 "/home/claude/cfront-3/src/expr.cpp"
{ Pfct __5f ;

# 1704 "/home/claude/cfront-3/src/expr.cpp"
__5f = (((struct fct *)(((struct fct *)__5m -> __O1__4expr.tp ))));

# 1706 "/home/claude/cfront-3/src/expr.cpp"
if ((__1t -> base__4node == 108 )&& (((struct fct *)(((struct fct *)__1t ))))-> f_static__3fct ){ 
# 1707 "/home/claude/cfront-3/src/expr.cpp"
(((struct ptr *)(((struct ptr *)__0this -> __O1__4expr.tp ))))-> memof__3ptr = 0 ;
# 1707 "/home/claude/cfront-3/src/expr.cpp"

# 1708 "/home/claude/cfront-3/src/expr.cpp"
break ;
}

# 1711 "/home/claude/cfront-3/src/expr.cpp"
{ bit __5all_stat ;

# 1711 "/home/claude/cfront-3/src/expr.cpp"
__5all_stat = 1 ;
if (__5f -> base__4node == 76 ){ 
# 1713 "/home/claude/cfront-3/src/expr.cpp"
Plist __6gl ;

# 1713 "/home/claude/cfront-3/src/expr.cpp"
__6gl = (((struct gen *)(((struct gen *)__5m -> __O1__4expr.tp ))))-> fct_list__3gen ;
for(;__6gl ;__6gl = __6gl -> l__9name_list ) { 
# 1715 "/home/claude/cfront-3/src/expr.cpp"
if ((((struct fct *)(((struct fct *)__6gl -> f__9name_list -> __O1__4expr.tp ))))-> f_static__3fct == 0 ){ 
# 1716 "/home/claude/cfront-3/src/expr.cpp"
__5all_stat = 0 ;
# 1716 "/home/claude/cfront-3/src/expr.cpp"

# 1717 "/home/claude/cfront-3/src/expr.cpp"
break ;
}
}
}

# 1722 "/home/claude/cfront-3/src/expr.cpp"
if ((__5f -> base__4node == 108 )|| (__5f -> base__4node == 76 )){ 
# 1723 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __6q ;

# 1723 "/home/claude/cfront-3/src/expr.cpp"
__6q = (((struct name *)(((struct name *)__0this -> __O3__4expr.e2 ))))-> __O3__4expr.n_initializer ;

# 1725 "/home/claude/cfront-3/src/expr.cpp"
if ((__6q && (bound == 0 ))&& (__0this -> __O3__4expr.e2 -> __O2__4expr.e1 == (((struct expr *)cc -> c_this__11dcl_context )))){ 
# 1727 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 && (__0this ->
# 1727 "/home/claude/cfront-3/src/expr.cpp"
__O3__4expr.e2 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O3__4expr.e2 ) ;
__0this -> __O3__4expr.e2 = (struct expr *)__5m ;
goto mname ;
}

# 1732 "/home/claude/cfront-3/src/expr.cpp"
bound = 1 ;
if (((__5f -> base__4node == 76 )&& (__5all_stat == 0 ))|| ((__5f -> base__4node == 108 )&& (! __5f -> f_static__3fct )))
# 1736 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1736 "/home/claude/cfront-3/src/expr.cpp"
const void
# 1736 "/home/claude/cfront-3/src/expr.cpp"
*__2__X138 ;

# 1742 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1742 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V60 ;

# 1742 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V61 ;

# 1742 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V62 ;

# 1742 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"address of boundF (try using ``%s::*'' forPT and ``&%s::%s'' for address)", (const struct ea *)( (__2__X138 = (const void
# 1742 "/home/claude/cfront-3/src/expr.cpp"
*)__5m -> __O4__4expr.n_table -> t_name__5table -> __O2__4expr.string ), ( ((& __0__V60 )-> __O1__2ea.p = __2__X138 ), (& __0__V60 )) ) , (const
# 1742 "/home/claude/cfront-3/src/expr.cpp"
struct ea *)__ct__2eaFPCv ( & __0__V61 , (const void *)__5m -> __O4__4expr.n_table -> t_name__5table -> __O2__4expr.string ) , (const struct ea *)__ct__2eaFPCv (
# 1742 "/home/claude/cfront-3/src/expr.cpp"
& __0__V62 , (const void *)__5m -> __O2__4expr.string ) , (const struct ea *)ea0 ) ;
} }

# 1745 "/home/claude/cfront-3/src/expr.cpp"
if (__6q || (__5f -> f_virtual__3fct == 0 )){ 
# 1747 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 && (__0this -> __O3__4expr.e2 -> permanent__4node == 0 ))del__4exprFv ( __0this ->
# 1747 "/home/claude/cfront-3/src/expr.cpp"
__O3__4expr.e2 ) ;
__0this -> __O3__4expr.e2 = (struct expr *)__5m ;
}
}
break ;

# 1751 "/home/claude/cfront-3/src/expr.cpp"
}

# 1751 "/home/claude/cfront-3/src/expr.cpp"
}

# 1753 "/home/claude/cfront-3/src/expr.cpp"
}
case 173 :
# 1756 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"& .* E") ;
}

# 1759 "/home/claude/cfront-3/src/expr.cpp"
return __0this ;

# 1759 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 1762 "/home/claude/cfront-3/src/expr.cpp"
case 107 :
# 1763 "/home/claude/cfront-3/src/expr.cpp"
( kind__4typeFUcN21 ( __1t , ((unsigned char )107 ), (unsigned char )'N' , (unsigned char )1 ) )
# 1763 "/home/claude/cfront-3/src/expr.cpp"
;
__0this -> __O1__4expr.tp = __1t ;
return __0this ;

# 1767 "/home/claude/cfront-3/src/expr.cpp"
case 172 :
# 1768 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = __1t ;
if ((( kind__4typeFUcN21 ( __1t , ((unsigned char )172 ), (unsigned char )'P' , (unsigned char )1 ) )
# 1769 "/home/claude/cfront-3/src/expr.cpp"
== 'P' )|| (ansi_opt == 0 )){ 
# 1770 "/home/claude/cfront-3/src/expr.cpp"
__0this -> base__4node = 54 ;
__0this -> __O2__4expr.e1 = zero ;
}
return __0this ;

# 1775 "/home/claude/cfront-3/src/expr.cpp"
case 46 :
# 1776 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = check_cond__FP4exprUcP5table ( __0this -> __O3__4expr.e2 , (unsigned char )46 , __1tbl ) ;
__0this -> __O1__4expr.tp = (struct type *)int_type ;
return __0this ;

# 1780 "/home/claude/cfront-3/src/expr.cpp"
case 47 :
# 1781 "/home/claude/cfront-3/src/expr.cpp"
( kind__4typeFUcN21 ( __1t , ((unsigned char )47 ), (unsigned char )'I' , (unsigned char )1 ) )
# 1781 "/home/claude/cfront-3/src/expr.cpp"
;
__0this -> __O1__4expr.tp = __1t ;
return __0this ;

# 1785 "/home/claude/cfront-3/src/expr.cpp"
case 48 :
# 1786 "/home/claude/cfront-3/src/expr.cpp"
case 49 :
# 1787 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1789 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __3e ;

# 1789 "/home/claude/cfront-3/src/expr.cpp"
__3e = (__0this -> __O2__4expr.e1 ?__0this -> __O2__4expr.e1 :__0this -> __O3__4expr.e2 );

# 1792 "/home/claude/cfront-3/src/expr.cpp"
lval__4exprFUc ( __3e , __1b ) ;

# 1794 "/home/claude/cfront-3/src/expr.cpp"
switch (__3e -> base__4node ){ 
# 1795 "/home/claude/cfront-3/src/expr.cpp"
case 68 :
# 1796 "/home/claude/cfront-3/src/expr.cpp"
__3e -> __O1__4expr.tp = 0 ;
__3e -> __O2__4expr.e1 = (__0this -> __O2__4expr.e1 ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , __3e -> __O2__4expr.e1 , (struct expr *)0 ) :__ct__4exprFUcP4exprT2 ( (struct
# 1797 "/home/claude/cfront-3/src/expr.cpp"
expr *)0 , __0this -> base__4node , (struct expr *)0 , __3e -> __O2__4expr.e1 ) );
__3e -> __O3__4expr.e2 = (__0this -> __O2__4expr.e1 ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , __3e -> __O3__4expr.e2 , (struct expr *)0 ) :__ct__4exprFUcP4exprT2 ( (struct
# 1798 "/home/claude/cfront-3/src/expr.cpp"
expr *)0 , __0this -> base__4node , (struct expr *)0 , __3e -> __O3__4expr.e2 ) );
( (__0this ?(((void )(__0this ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 1799 "/home/claude/cfront-3/src/expr.cpp"
;
return typ__4exprFP5table ( __3e , __1tbl ) ;
case 71 :
# 1802 "/home/claude/cfront-3/src/expr.cpp"
case 147 :
# 1803 "/home/claude/cfront-3/src/expr.cpp"
__3e -> __O1__4expr.tp = 0 ;
__3e -> __O3__4expr.e2 = (__0this -> __O2__4expr.e1 ?__ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , __3e -> __O3__4expr.e2 , (struct expr *)0 ) :__ct__4exprFUcP4exprT2 ( (struct
# 1804 "/home/claude/cfront-3/src/expr.cpp"
expr *)0 , __0this -> base__4node , (struct expr *)0 , __3e -> __O3__4expr.e2 ) );
( (__0this ?(((void )(__0this ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 1805 "/home/claude/cfront-3/src/expr.cpp"
;
return typ__4exprFP5table ( __3e , __1tbl ) ;
case 48 :
# 1808 "/home/claude/cfront-3/src/expr.cpp"
case 49 :
# 1809 "/home/claude/cfront-3/src/expr.cpp"
if (__3e -> __O2__4expr.e1 )
# 1810 "/home/claude/cfront-3/src/expr.cpp"
break ;
nin ++ ;
if (not_simple__4exprFi ( __3e -> __O3__4expr.e2 , 0 ) )
# 1813 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1813 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V63 ;

# 1813 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V64 ;

# 1813 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"overly complex %k of %k", (const struct ea *)( ((
# 1813 "/home/claude/cfront-3/src/expr.cpp"
((& __0__V63 )-> __O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V63 )) , (const struct ea *)__ct__2eaFUl (
# 1813 "/home/claude/cfront-3/src/expr.cpp"
& __0__V64 , (unsigned long )__3e -> base__4node ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 1813 "/home/claude/cfront-3/src/expr.cpp"
} 
# 1814 "/home/claude/cfront-3/src/expr.cpp"
nin -- ;
__3e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __3e , typ__4exprFP5table ( __3e -> __O3__4expr.e2 , __1tbl ) ) ;
# 1815 "/home/claude/cfront-3/src/expr.cpp"

# 1816 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O2__4expr.e1 )__0this -> __O2__4expr.e1 = __3e ;
else 
# 1816 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = __3e ;

# 1818 "/home/claude/cfront-3/src/expr.cpp"
return typ__4exprFP5table ( __0this , __1tbl ) ;
case 70 :
# 1820 "/home/claude/cfront-3/src/expr.cpp"
case 126 :
# 1821 "/home/claude/cfront-3/src/expr.cpp"
case 127 :
# 1822 "/home/claude/cfront-3/src/expr.cpp"
case 128 :
# 1823 "/home/claude/cfront-3/src/expr.cpp"
case 129 :
# 1824 "/home/claude/cfront-3/src/expr.cpp"
case 130 :
# 1825 "/home/claude/cfront-3/src/expr.cpp"
case 131 :
# 1826 "/home/claude/cfront-3/src/expr.cpp"
case 132 :
# 1827 "/home/claude/cfront-3/src/expr.cpp"
case 133 :
# 1828 "/home/claude/cfront-3/src/expr.cpp"
case 134 :
# 1829 "/home/claude/cfront-3/src/expr.cpp"
case 135 :
# 1830 "/home/claude/cfront-3/src/expr.cpp"
nin ++ ;
if (not_simple__4exprFi ( __3e -> __O2__4expr.e1 , 0 ) )
# 1832 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1832 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V65 ;

# 1832 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V66 ;

# 1832 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"overly complex %k of %k", (const struct ea *)( ((
# 1832 "/home/claude/cfront-3/src/expr.cpp"
((& __0__V65 )-> __O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V65 )) , (const struct ea *)__ct__2eaFUl (
# 1832 "/home/claude/cfront-3/src/expr.cpp"
& __0__V66 , (unsigned long )__3e -> base__4node ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 1832 "/home/claude/cfront-3/src/expr.cpp"
} 
# 1833 "/home/claude/cfront-3/src/expr.cpp"
nin -- ;
__3e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __3e , typ__4exprFP5table ( __3e -> __O2__4expr.e1 , __1tbl ) ) ;
# 1834 "/home/claude/cfront-3/src/expr.cpp"

# 1835 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O2__4expr.e1 )__0this -> __O2__4expr.e1 = __3e ;
else 
# 1835 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = __3e ;
return typ__4exprFP5table ( __0this , __1tbl ) ;
}
}

# 1840 "/home/claude/cfront-3/src/expr.cpp"
__1r1 = ( kind__4typeFUcN21 ( __1t , __1b , (unsigned char )'P' , (unsigned char )1 ) ) ;
if (((__1r1 == 'P' )&& (check__4typeFP4typeUcT2 ( __1t , Pvoid_type , (unsigned char )254 , (unsigned char )0 ) == 0 ))&&
# 1841 "/home/claude/cfront-3/src/expr.cpp"
(ptr_is_template_formal__FP3ptr ( ((struct ptr *)(((struct ptr *)__1t )))) == 0 ))
# 1843 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1843 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V67 ;

# 1843 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k of void*", (const struct ea *)( (( ((& __0__V67 )->
# 1843 "/home/claude/cfront-3/src/expr.cpp"
__O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V67 )) , (const struct ea *)ea0 , (const struct
# 1843 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} __0this -> __O1__4expr.tp = __1t ;
return __0this ;

# 1847 "/home/claude/cfront-3/src/expr.cpp"
}

# 1849 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> __O2__4expr.e1 == dummy )|| (__0this -> __O2__4expr.e1 == 0 )){ 
# 1849 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V68 ;

# 1849 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"operand missing for%k", (const struct ea *)( (( ((& __0__V68 )->
# 1849 "/home/claude/cfront-3/src/expr.cpp"
__O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V68 )) , (const struct ea *)ea0 , (const struct
# 1849 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} if ((__0this -> __O3__4expr.e2 == dummy )|| (__0this -> __O3__4expr.e2 == 0 )){ 
# 1850 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V69 ;

# 1850 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"initializer missing for%k", (const struct ea *)( (( ((& __0__V69 )->
# 1850 "/home/claude/cfront-3/src/expr.cpp"
__O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V69 )) , (const struct ea *)ea0 , (const struct
# 1850 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1852 "/home/claude/cfront-3/src/expr.cpp"
switch (__1b ){ 
# 1853 "/home/claude/cfront-3/src/expr.cpp"
case 50 :
# 1854 "/home/claude/cfront-3/src/expr.cpp"
case 51 :
# 1855 "/home/claude/cfront-3/src/expr.cpp"
__1r1 = ( kind__4typeFUcN21 ( __1t1 , __1b , (unsigned char )'N' , (unsigned
# 1855 "/home/claude/cfront-3/src/expr.cpp"
char )1 ) ) ;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , __1b , (unsigned char )'N' , (unsigned char )1 ) ) ;
__1t = np_promote__FUcN21P4typeT4N21 ( __1b , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )1 , (unsigned char )1 ) ;
# 1857 "/home/claude/cfront-3/src/expr.cpp"

# 1858 "/home/claude/cfront-3/src/expr.cpp"
break ;

# 1860 "/home/claude/cfront-3/src/expr.cpp"
case 54 :
# 1861 "/home/claude/cfront-3/src/expr.cpp"
__1r2 = ( kind__4typeFUcN21 ( __1t2 , ((unsigned char )54 ), (unsigned char )'P' , (unsigned char )1 )
# 1861 "/home/claude/cfront-3/src/expr.cpp"
) ;
__1r1 = ( kind__4typeFUcN21 ( __1t1 , ((unsigned char )54 ), (unsigned char )'P' , (unsigned char )1 ) )
# 1862 "/home/claude/cfront-3/src/expr.cpp"
;
__1t = np_promote__FUcN21P4typeT4N21 ( (unsigned char )54 , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )1 , (unsigned char
# 1863 "/home/claude/cfront-3/src/expr.cpp"
)1 ) ;
goto void_check ;

# 1866 "/home/claude/cfront-3/src/expr.cpp"
case 55 :
# 1867 "/home/claude/cfront-3/src/expr.cpp"
__1r2 = ( kind__4typeFUcN21 ( __1t2 , ((unsigned char )55 ), (unsigned char )'P' , (unsigned char )1 )
# 1867 "/home/claude/cfront-3/src/expr.cpp"
) ;
__1r1 = ( kind__4typeFUcN21 ( __1t1 , ((unsigned char )55 ), (unsigned char )'P' , (unsigned char )1 ) )
# 1868 "/home/claude/cfront-3/src/expr.cpp"
;
if (((__1r2 == 'P' )&& (__1r1 != 'P' ))&& (__1r1 != 'A' ))error__FPCc ( (const char *)"nonP - P")
# 1869 "/home/claude/cfront-3/src/expr.cpp"
;
__1t = np_promote__FUcN21P4typeT4N21 ( (unsigned char )55 , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )1 , (unsigned char
# 1870 "/home/claude/cfront-3/src/expr.cpp"
)1 ) ;
void_check :
# 1874 "/home/claude/cfront-3/src/expr.cpp"
if ((((__1r1 == 'P' )&& (check__4typeFP4typeUcT2 ( __1t1 , Pvoid_type , (unsigned char )254 , (unsigned char )0 ) == 0 ))&&
# 1874 "/home/claude/cfront-3/src/expr.cpp"
(ptr_is_template_formal__FP3ptr ( ((struct ptr *)(((struct ptr *)__1t1 )))) == 0 ))|| (((__1r2 == 'P' )&& (check__4typeFP4typeUcT2 ( __1t2 , Pvoid_type , (unsigned char )254 ,
# 1874 "/home/claude/cfront-3/src/expr.cpp"
(unsigned char )0 ) == 0 ))&& (ptr_is_template_formal__FP3ptr ( ((struct ptr *)(((struct ptr *)__1t2 )))) == 0 )))
# 1878 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1878 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V70 ;

# 1878 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k of void*", (const struct ea *)( (( ((& __0__V70 )->
# 1878 "/home/claude/cfront-3/src/expr.cpp"
__O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V70 )) , (const struct ea *)ea0 , (const struct
# 1878 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} __0this -> __O1__4expr.tp = __1t ;
break ;

# 1882 "/home/claude/cfront-3/src/expr.cpp"
case 56 :
# 1883 "/home/claude/cfront-3/src/expr.cpp"
case 57 :
# 1884 "/home/claude/cfront-3/src/expr.cpp"
case 52 :
# 1885 "/home/claude/cfront-3/src/expr.cpp"
case 65 :
# 1886 "/home/claude/cfront-3/src/expr.cpp"
case 64 :
# 1887 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 1887 "/home/claude/cfront-3/src/expr.cpp"
unsigned long __2__X139 ;

# 1888 "/home/claude/cfront-3/src/expr.cpp"
case 58 :
# 1889 "/home/claude/cfront-3/src/expr.cpp"
case 59 :
# 1890 "/home/claude/cfront-3/src/expr.cpp"
case 60 :
# 1891 "/home/claude/cfront-3/src/expr.cpp"
case 61 :
# 1892 "/home/claude/cfront-3/src/expr.cpp"
case 62 :
# 1893 "/home/claude/cfront-3/src/expr.cpp"
case 63 :
# 1894 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1894 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V71 ;

# 1894 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V72 ;

# 1894 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%kE as operand for%k", (const struct ea *)( (__2__X139 =
# 1894 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 -> base__4node ), ( (( ((& __0__V71 )-> __O1__2ea.i = __2__X139 ), 0 ) ), (& __0__V71 )) )
# 1894 "/home/claude/cfront-3/src/expr.cpp"
, (const struct ea *)( (( ((& __0__V72 )-> __O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (&
# 1894 "/home/claude/cfront-3/src/expr.cpp"
__0__V72 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
switch (__0this -> __O3__4expr.e2 -> base__4node ){ 
# 1896 "/home/claude/cfront-3/src/expr.cpp"
unsigned long __2__X140 ;

# 1897 "/home/claude/cfront-3/src/expr.cpp"
case 58 :
# 1898 "/home/claude/cfront-3/src/expr.cpp"
case 59 :
# 1899 "/home/claude/cfront-3/src/expr.cpp"
case 60 :
# 1900 "/home/claude/cfront-3/src/expr.cpp"
case 61 :
# 1901 "/home/claude/cfront-3/src/expr.cpp"
case 62 :
# 1902 "/home/claude/cfront-3/src/expr.cpp"
case 63 :
# 1903 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1903 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V73 ;

# 1903 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V74 ;

# 1903 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%kE as operand for%k", (const struct ea *)( (__2__X140 =
# 1903 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 -> base__4node ), ( (( ((& __0__V73 )-> __O1__2ea.i = __2__X140 ), 0 ) ), (& __0__V73 )) )
# 1903 "/home/claude/cfront-3/src/expr.cpp"
, (const struct ea *)( (( ((& __0__V74 )-> __O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (&
# 1903 "/home/claude/cfront-3/src/expr.cpp"
__0__V74 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
case 53 :
# 1906 "/home/claude/cfront-3/src/expr.cpp"
__1r1 = ( kind__4typeFUcN21 ( __1t1 , __1b , (unsigned char )'I' , (unsigned char )1 ) )
# 1906 "/home/claude/cfront-3/src/expr.cpp"
;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , __1b , (unsigned char )'I' , (unsigned char )1 ) ) ;
__1t = np_promote__FUcN21P4typeT4N21 ( __1b , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )1 , (unsigned char )1 ) ;
# 1908 "/home/claude/cfront-3/src/expr.cpp"

# 1909 "/home/claude/cfront-3/src/expr.cpp"
break ;

# 1911 "/home/claude/cfront-3/src/expr.cpp"
case 58 :
# 1912 "/home/claude/cfront-3/src/expr.cpp"
case 59 :
# 1913 "/home/claude/cfront-3/src/expr.cpp"
case 60 :
# 1914 "/home/claude/cfront-3/src/expr.cpp"
case 61 :
# 1915 "/home/claude/cfront-3/src/expr.cpp"
case 62 :
# 1916 "/home/claude/cfront-3/src/expr.cpp"
case 63 :
# 1917 "/home/claude/cfront-3/src/expr.cpp"
__1r1 = ( kind__4typeFUcN21 ( __1t1 , __1b , (unsigned char )'P' ,
# 1917 "/home/claude/cfront-3/src/expr.cpp"
(unsigned char )1 ) ) ;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , __1b , (unsigned char )'P' , (unsigned char )1 ) ) ;
if ((__1r1 == 'P' )&& (__1r2 == 'I' )){ 
# 1922 "/home/claude/cfront-3/src/expr.cpp"
Neval = 0 ;
{ long long __3i ;

# 1923 "/home/claude/cfront-3/src/expr.cpp"
__3i = eval__4exprFv ( __0this -> __O3__4expr.e2 ) ;
if ((Neval == 0 )&& (__3i == 0 )){ 
# 1925 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 && (__0this -> __O3__4expr.e2 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O3__4expr.e2 )
# 1925 "/home/claude/cfront-3/src/expr.cpp"
;
__0this -> __O3__4expr.e2 = zero ;
__1r2 = 'Z' ;
}

# 1928 "/home/claude/cfront-3/src/expr.cpp"
}
}
else if ((__1r2 == 'P' )&& (__1r1 == 'I' )){ 
# 1931 "/home/claude/cfront-3/src/expr.cpp"
Neval = 0 ;
{ long long __3i ;

# 1932 "/home/claude/cfront-3/src/expr.cpp"
__3i = eval__4exprFv ( __0this -> __O2__4expr.e1 ) ;
if ((Neval == 0 )&& (__3i == 0 )){ 
# 1934 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O2__4expr.e1 && (__0this -> __O2__4expr.e1 -> permanent__4node == 0 ))del__4exprFv ( __0this -> __O2__4expr.e1 )
# 1934 "/home/claude/cfront-3/src/expr.cpp"
;
__0this -> __O2__4expr.e1 = zero ;
__1r1 = 'Z' ;
}

# 1937 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 1940 "/home/claude/cfront-3/src/expr.cpp"
if ((__1b != 62 )&& (__1b != 63 )){ 
# 1941 "/home/claude/cfront-3/src/expr.cpp"
if ((__1r1 == 'P' )&& (__1r2 == 'Z' )){ 
# 1941 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V75 ;

# 1941 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"P%k 0", (const struct ea *)( (( ((& __0__V75 )->
# 1941 "/home/claude/cfront-3/src/expr.cpp"
__O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V75 )) , (const struct ea *)ea0 , (const struct
# 1941 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} if ((__1r2 == 'P' )&& (__1r1 == 'Z' )){ 
# 1942 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V76 ;

# 1942 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"P%k 0", (const struct ea *)( (( ((& __0__V76 )->
# 1942 "/home/claude/cfront-3/src/expr.cpp"
__O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V76 )) , (const struct ea *)ea0 , (const struct
# 1942 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1947 "/home/claude/cfront-3/src/expr.cpp"
if (__1r1 == 108 ){ 
# 1948 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = ptof__FP3fctP4exprP5table ( (struct fct *)0 , __0this -> __O2__4expr.e1 , __1tbl ) ;
__1t1 = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
__1r1 = ( kind__4typeFUcN21 ( __1t1 , __1b , (unsigned char )'P' , (unsigned char )1 ) ) ;
}
if (__1r2 == 108 ){ 
# 1953 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = ptof__FP3fctP4exprP5table ( (struct fct *)0 , __0this -> __O3__4expr.e2 , __1tbl ) ;
__1t2 = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , __1b , (unsigned char )'P' , (unsigned char )1 ) ) ;
}

# 1958 "/home/claude/cfront-3/src/expr.cpp"
((void )np_promote__FUcN21P4typeT4N21 ( __1b , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )0 , (unsigned char )1 ) );
# 1958 "/home/claude/cfront-3/src/expr.cpp"

# 1960 "/home/claude/cfront-3/src/expr.cpp"
if (__1r1 == 'P' ){ 
# 1961 "/home/claude/cfront-3/src/expr.cpp"
Pptr __3p1 ;
Pptr __3p2 ;
Pname __3cn ;
Pname __3cn2 ;

# 1961 "/home/claude/cfront-3/src/expr.cpp"
__3p1 = is_ptr__4typeFv ( __1t1 ) ;
__3p2 = is_ptr__4typeFv ( __1t2 ) ;
__3cn = (__3p1 ?is_cl_obj__4typeFv ( __3p1 -> typ__5pvtyp ) :(((struct name *)0 )));
__3cn2 = (__3p2 ?is_cl_obj__4typeFv ( __3p2 -> typ__5pvtyp ) :(((struct name *)0 )));

# 1966 "/home/claude/cfront-3/src/expr.cpp"
if (__3cn && __3cn2 ){ 
# 1967 "/home/claude/cfront-3/src/expr.cpp"
Pclass __4cl ;
Pclass __4cl2 ;

# 1967 "/home/claude/cfront-3/src/expr.cpp"
__4cl = (((struct classdef *)(((struct classdef *)__3cn -> __O1__4expr.tp ))));
__4cl2 = (((struct classdef *)(((struct classdef *)__3cn2 -> __O1__4expr.tp ))));

# 1970 "/home/claude/cfront-3/src/expr.cpp"
if (has_base__8classdefFP8classdefiT2 ( __4cl , __4cl2 , 0 , 0 ) ){ 
# 1970 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X141 ;

# 1970 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X142 ;

# 1971 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = cast_cptr__FP8classdefP4exprP5tablei ( __4cl2 , __0this -> __O2__4expr.e1 , __1tbl , (__0this -> base__4node == 113 )?1 :0 ) ;
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X141 = 0 ), ( (__2__X142 = __0this -> __O2__4expr.e1 ), ( ((__0__X141 || (__0__X141 = (struct
# 1972 "/home/claude/cfront-3/src/expr.cpp"
cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X141 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X141 ), (unsigned char )191 ,
# 1972 "/home/claude/cfront-3/src/expr.cpp"
__2__X142 , (struct expr *)0 ) ), (__0__X141 -> __O1__4expr.tp = (__0__X141 -> __O4__4expr.tp2 = ((struct type *)__3p2 )))) :0 ), __0__X141 ) ) )
# 1972 "/home/claude/cfront-3/src/expr.cpp"
;
}
else if (has_base__8classdefFP8classdefiT2 ( __4cl2 , __4cl , 0 , 0 ) ){ 
# 1974 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X143 ;

# 1974 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X144 ;

# 1975 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = cast_cptr__FP8classdefP4exprP5tablei ( __4cl , __0this -> __O3__4expr.e2 , __1tbl , (__0this -> base__4node == 113 )?1 :0 ) ;
__0this -> __O3__4expr.e2 = (struct expr *)( (__0__X143 = 0 ), ( (__2__X144 = __0this -> __O3__4expr.e2 ), ( ((__0__X143 || (__0__X143 = (struct
# 1976 "/home/claude/cfront-3/src/expr.cpp"
cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X143 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X143 ), (unsigned char )191 ,
# 1976 "/home/claude/cfront-3/src/expr.cpp"
__2__X144 , (struct expr *)0 ) ), (__0__X143 -> __O1__4expr.tp = (__0__X143 -> __O4__4expr.tp2 = ((struct type *)__3p1 )))) :0 ), __0__X143 ) ) )
# 1976 "/home/claude/cfront-3/src/expr.cpp"
;
}
}
}

# 1981 "/home/claude/cfront-3/src/expr.cpp"
if (((((__1r1 == 'P' )&& memptr__4typeFv ( __1t1 ) )|| ((__1t1 -> base__4node == 108 )&& (((struct fct *)(((struct fct *)__1t1 ))))-> memof__3fct ))|| ((__1r2 ==
# 1981 "/home/claude/cfront-3/src/expr.cpp"
'P' )&& memptr__4typeFv ( __1t2 ) ))|| ((__1t2 -> base__4node == 108 )&& (((struct fct *)(((struct fct *)__1t2 ))))-> memof__3fct ))
# 1988 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 1989 "/home/claude/cfront-3/src/expr.cpp"
if (__1r1 == 'Z' ){
# 1989 "/home/claude/cfront-3/src/expr.cpp"

# 1990 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = zero ;
if (__0this -> __O3__4expr.e2 -> base__4node == 124 )__0this -> __O3__4expr.e2 = __0this -> __O3__4expr.e2 -> __O2__4expr.e1 -> __O3__4expr.e2 ;
else __0this -> __O3__4expr.e2 = make_dot__FP4exprP5tablePCc ( __0this -> __O3__4expr.e2 , __1tbl , (const char *)"i")
# 1992 "/home/claude/cfront-3/src/expr.cpp"
;
}
else if (__1r2 == 'Z' ){ 
# 1995 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = zero ;
if (__0this -> __O2__4expr.e1 -> base__4node == 124 )__0this -> __O2__4expr.e1 = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O3__4expr.e2 ;
else __0this -> __O2__4expr.e1 = make_dot__FP4exprP5tablePCc ( __0this -> __O2__4expr.e1 , __1tbl , (const char *)"i")
# 1997 "/home/claude/cfront-3/src/expr.cpp"
;
}
else if (((__1r2 == 'P' )&& (! memptr__4typeFv ( __1t2 ) ))|| ((__1r1 == 'P' )&& (! memptr__4typeFv ( __1t1 ) )))
# 2003 "/home/claude/cfront-3/src/expr.cpp"
{
# 2003 "/home/claude/cfront-3/src/expr.cpp"

# 2004 "/home/claude/cfront-3/src/expr.cpp"
;
}
else { 
# 2008 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __4i1 ;
__4i1 = __0this -> __O2__4expr.e1 ;
while ((__4i1 -> base__4node == 191 )|| (__4i1 -> base__4node == 113 ))
# 2011 "/home/claude/cfront-3/src/expr.cpp"
__4i1 = __4i1 -> __O2__4expr.e1 ;
if (__4i1 -> base__4node == 124 ){ 
# 2013 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = __4i1 ;
__4i1 = make_dot__FP4exprP5tablePCc ( __4i1 , __1tbl , (const char *)"i") ;
}
else if (__4i1 -> base__4node == 86 ){ 
# 2017 "/home/claude/cfront-3/src/expr.cpp"
__4i1 = zero ;
__0this -> __O2__4expr.e1 = __4i1 ;
}
else { 
# 2021 "/home/claude/cfront-3/src/expr.cpp"
__4i1 = make_dot__FP4exprP5tablePCc ( __4i1 , __1tbl , (const char *)"i") ;
# 2021 "/home/claude/cfront-3/src/expr.cpp"

# 2022 "/home/claude/cfront-3/src/expr.cpp"
}

# 2024 "/home/claude/cfront-3/src/expr.cpp"
{ Pexpr __4i2 ;
__4i2 = __0this -> __O3__4expr.e2 ;
while ((__4i2 -> base__4node == 191 )|| (__4i2 -> base__4node == 113 ))
# 2027 "/home/claude/cfront-3/src/expr.cpp"
__4i2 = __4i2 -> __O2__4expr.e1 ;
if (__4i2 -> base__4node == 124 ){ 
# 2029 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = __4i2 ;
__4i2 = make_dot__FP4exprP5tablePCc ( __4i2 , __1tbl , (const char *)"i") ;
}
else if (__4i2 -> base__4node == 86 ){ 
# 2033 "/home/claude/cfront-3/src/expr.cpp"
__4i2 = zero ;
__0this -> __O3__4expr.e2 = __4i2 ;
}
else { 
# 2037 "/home/claude/cfront-3/src/expr.cpp"
__4i2 = make_dot__FP4exprP5tablePCc ( __4i2 , __1tbl , (const char *)"i") ;
# 2037 "/home/claude/cfront-3/src/expr.cpp"

# 2038 "/home/claude/cfront-3/src/expr.cpp"
}

# 2040 "/home/claude/cfront-3/src/expr.cpp"
{ Pexpr __4f1 ;
if (__0this -> __O2__4expr.e1 -> base__4node == 124 ){ 
# 2042 "/home/claude/cfront-3/src/expr.cpp"
__4f1 = __0this -> __O2__4expr.e1 -> __O3__4expr.e2 ;
}
else if (__0this -> __O2__4expr.e1 -> base__4node == 86 ){ 
# 2045 "/home/claude/cfront-3/src/expr.cpp"
__4f1 = zero ;
}
else { 
# 2048 "/home/claude/cfront-3/src/expr.cpp"
__4f1 = make_dot__FP4exprP5tablePCc ( __0this -> __O2__4expr.e1 , __1tbl , (const char *)"f")
# 2048 "/home/claude/cfront-3/src/expr.cpp"
;
}

# 2051 "/home/claude/cfront-3/src/expr.cpp"
{ Pexpr __4f2 ;
if (__0this -> __O3__4expr.e2 -> base__4node == 124 ){ 
# 2053 "/home/claude/cfront-3/src/expr.cpp"
__4f2 = __0this -> __O3__4expr.e2 -> __O3__4expr.e2 ;
}
else if (__0this -> __O3__4expr.e2 -> base__4node == 86 ){ 
# 2056 "/home/claude/cfront-3/src/expr.cpp"
__4f2 = zero ;
}
else { 
# 2059 "/home/claude/cfront-3/src/expr.cpp"
__4f2 = make_dot__FP4exprP5tablePCc ( __0this -> __O3__4expr.e2 , __1tbl , (const char *)"f")
# 2059 "/home/claude/cfront-3/src/expr.cpp"
;
__4f2 -> __O1__4expr.tp = __4f1 -> __O1__4expr.tp ;
}

# 2063 "/home/claude/cfront-3/src/expr.cpp"
if ((__1b != 62 )&& (__1b != 63 )){ 
# 2063 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X145 ;

# 2063 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X146 ;

# 2063 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X147 ;

# 2063 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X148 ;

# 2064 "/home/claude/cfront-3/src/expr.cpp"
__4f1 = (struct expr *)( (__0__X145 = 0 ), ( (__2__X146 = Pvoid_type ), ( ((__0__X145 || (__0__X145 = (struct cast *)__nw__4exprSFUl ( (unsigned
# 2064 "/home/claude/cfront-3/src/expr.cpp"
long )(sizeof (struct cast))) ))?( (__0__X145 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X145 ), (unsigned char )191 , __4f1 , (struct
# 2064 "/home/claude/cfront-3/src/expr.cpp"
expr *)0 ) ), (__0__X145 -> __O1__4expr.tp = (__0__X145 -> __O4__4expr.tp2 = __2__X146 ))) :0 ), __0__X145 ) ) ) ;
__4f2 = (struct expr *)( (__0__X147 = 0 ), ( (__2__X148 = Pvoid_type ), ( ((__0__X147 || (__0__X147 = (struct cast *)__nw__4exprSFUl ( (unsigned
# 2065 "/home/claude/cfront-3/src/expr.cpp"
long )(sizeof (struct cast))) ))?( (__0__X147 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X147 ), (unsigned char )191 , __4f2 , (struct
# 2065 "/home/claude/cfront-3/src/expr.cpp"
expr *)0 ) ), (__0__X147 -> __O1__4expr.tp = (__0__X147 -> __O4__4expr.tp2 = __2__X148 ))) :0 ), __0__X147 ) ) ) ;
}
{ Pexpr __4ei ;
Pexpr __4fi ;

# 2067 "/home/claude/cfront-3/src/expr.cpp"
__4ei = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , __4i1 , __4i2 ) ;
__4fi = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> base__4node , __4f1 , __4f2 ) ;

# 2070 "/home/claude/cfront-3/src/expr.cpp"
__0this -> base__4node = ((__1b == 63 )?67 :66 );
__0this -> __O2__4expr.e1 = __4ei ;
__0this -> __O3__4expr.e2 = __4fi ;

# 2072 "/home/claude/cfront-3/src/expr.cpp"
}

# 2072 "/home/claude/cfront-3/src/expr.cpp"
}

# 2072 "/home/claude/cfront-3/src/expr.cpp"
}

# 2072 "/home/claude/cfront-3/src/expr.cpp"
}
}
}
else if ((__1b != 62 )&& (__1b != 63 )){ 
# 2076 "/home/claude/cfront-3/src/expr.cpp"
bit __3doit ;

# 2076 "/home/claude/cfront-3/src/expr.cpp"
__3doit = 0 ;
if (__1r1 == 'P' ){ 
# 2078 "/home/claude/cfront-3/src/expr.cpp"
Ptype __4tt1 ;
Ptype __4tt2 ;

# 2078 "/home/claude/cfront-3/src/expr.cpp"
__4tt1 = __1t1 ;

# 2080 "/home/claude/cfront-3/src/expr.cpp"
while (__4tt2 = (struct type *)is_ptr_or_ref__4typeFv ( __4tt1 ) )
# 2081 "/home/claude/cfront-3/src/expr.cpp"
__4tt1 = (((struct ptr *)(((struct ptr *)__4tt2 ))))-> typ__5pvtyp ;
if (__4tt1 -> base__4node == 108 )
# 2083 "/home/claude/cfront-3/src/expr.cpp"
__3doit = 1 ;
}
if ((! __3doit )&& (__1r2 == 'P' )){ 
# 2086 "/home/claude/cfront-3/src/expr.cpp"
Ptype __4tt1 ;
Ptype __4tt2 ;

# 2086 "/home/claude/cfront-3/src/expr.cpp"
__4tt1 = __1t2 ;

# 2088 "/home/claude/cfront-3/src/expr.cpp"
while (__4tt2 = (struct type *)is_ptr_or_ref__4typeFv ( __4tt1 ) )
# 2089 "/home/claude/cfront-3/src/expr.cpp"
__4tt1 = (((struct ptr *)(((struct ptr *)__4tt2 ))))-> typ__5pvtyp ;
if (__4tt1 -> base__4node == 108 )
# 2091 "/home/claude/cfront-3/src/expr.cpp"
__3doit = 1 ;
}
if (__3doit ){ 
# 2093 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X149 ;

# 2093 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X150 ;

# 2093 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X151 ;

# 2093 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X152 ;

# 2093 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X153 ;

# 2093 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X154 ;

# 2094 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X149 = 0 ), ( (__2__X150 = Pvoid_type ), ( (__2__X151 = __0this -> __O2__4expr.e1 ), (
# 2094 "/home/claude/cfront-3/src/expr.cpp"
((__0__X149 || (__0__X149 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X149 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X149 ),
# 2094 "/home/claude/cfront-3/src/expr.cpp"
(unsigned char )191 , __2__X151 , (struct expr *)0 ) ), (__0__X149 -> __O1__4expr.tp = (__0__X149 -> __O4__4expr.tp2 = __2__X150 ))) :0 ), __0__X149 )
# 2094 "/home/claude/cfront-3/src/expr.cpp"
) ) ) ;
__0this -> __O3__4expr.e2 = (struct expr *)( (__0__X152 = 0 ), ( (__2__X153 = Pvoid_type ), ( (__2__X154 = __0this -> __O3__4expr.e2 ), (
# 2095 "/home/claude/cfront-3/src/expr.cpp"
((__0__X152 || (__0__X152 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X152 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X152 ),
# 2095 "/home/claude/cfront-3/src/expr.cpp"
(unsigned char )191 , __2__X154 , (struct expr *)0 ) ), (__0__X152 -> __O1__4expr.tp = (__0__X152 -> __O4__4expr.tp2 = __2__X153 ))) :0 ), __0__X152 )
# 2095 "/home/claude/cfront-3/src/expr.cpp"
) ) ) ;
}
}
__1t = (struct type *)int_type ;
break ;

# 2101 "/home/claude/cfront-3/src/expr.cpp"
case 66 :
# 2102 "/home/claude/cfront-3/src/expr.cpp"
case 67 :
# 2103 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = check_cond__FP4exprUcP5table ( __0this -> __O2__4expr.e1 , __1b , __1tbl ) ;
__0this -> __O3__4expr.e2 = check_cond__FP4exprUcP5table ( __0this -> __O3__4expr.e2 , __1b , __1tbl ) ;

# 2106 "/home/claude/cfront-3/src/expr.cpp"
if (Ntmp && (__1b != 68 )){ 
# 2107 "/home/claude/cfront-3/src/expr.cpp"
Ntmp_dtor = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __0this , Ntmp_dtor ) ;
# 2107 "/home/claude/cfront-3/src/expr.cpp"

# 2109 "/home/claude/cfront-3/src/expr.cpp"
}

# 2111 "/home/claude/cfront-3/src/expr.cpp"
__1t = (struct type *)int_type ;
break ;

# 2114 "/home/claude/cfront-3/src/expr.cpp"
case 68 :
# 2115 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2116 "/home/claude/cfront-3/src/expr.cpp"
Pname __3c1 ;

# 2116 "/home/claude/cfront-3/src/expr.cpp"
Pname __3c2 ;
__0this -> __O4__4expr.cond = check_cond__FP4exprUcP5table ( __0this -> __O4__4expr.cond , __1b , __1tbl ) ;

# 2120 "/home/claude/cfront-3/src/expr.cpp"
{ bit __3MPTR ;

# 2120 "/home/claude/cfront-3/src/expr.cpp"
__3MPTR = 0 ;

# 2122 "/home/claude/cfront-3/src/expr.cpp"
suppress_error ++ ;
__1r1 = ( kind__4typeFUcN21 ( __1t1 , __1b , (unsigned char )'P' , (unsigned char )1 ) ) ;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , __1b , (unsigned char )'P' , (unsigned char )1 ) ) ;
suppress_error -- ;
if ((((__1r1 == 'P' )&& memptr__4typeFv ( __1t1 ) )|| (((__1r1 == 108 )&& (((struct fct *)(((struct fct *)__1t1 ))))-> memof__3fct )&& ((((struct fct *)(((struct
# 2126 "/home/claude/cfront-3/src/expr.cpp"
fct *)__1t1 ))))-> f_static__3fct == 0 )))&& (((__1r2 == 'P' )&& memptr__4typeFv ( __1t2 ) )|| (((__1r2 == 108 )&& (((struct fct *)(((struct fct *)__1t2 ))))-> memof__3fct )&&
# 2126 "/home/claude/cfront-3/src/expr.cpp"
((((struct fct *)(((struct fct *)__1t2 ))))-> f_static__3fct == 0 ))))
# 2130 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2132 "/home/claude/cfront-3/src/expr.cpp"
++ __3MPTR ;

# 2134 "/home/claude/cfront-3/src/expr.cpp"
if (__1r1 == 108 ){ 
# 2135 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __0this ->
# 2135 "/home/claude/cfront-3/src/expr.cpp"
__O2__4expr.e1 ) ;
typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
__1t1 = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
__1r1 = ( kind__4typeFUcN21 ( __1t1 , __1b , (unsigned char )'P' , (unsigned char )1 ) ) ;
}
if (__1r2 == 108 ){ 
# 2141 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __0this ->
# 2141 "/home/claude/cfront-3/src/expr.cpp"
__O3__4expr.e2 ) ;
typ__4exprFP5table ( __0this -> __O3__4expr.e2 , __1tbl ) ;
__1t2 = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , __1b , (unsigned char )'P' , (unsigned char )1 ) ) ;
}

# 2148 "/home/claude/cfront-3/src/expr.cpp"
{ Pexpr __4tt ;

# 2148 "/home/claude/cfront-3/src/expr.cpp"
__4tt = __0this -> __O2__4expr.e1 ;
while ((__4tt -> base__4node == 113 )|| (__4tt -> base__4node == 191 ))
# 2150 "/home/claude/cfront-3/src/expr.cpp"
__4tt = __4tt -> __O2__4expr.e1 ;
if (__4tt -> base__4node == 124 )__0this -> __O2__4expr.e1 = __4tt ;

# 2153 "/home/claude/cfront-3/src/expr.cpp"
__4tt = __0this -> __O3__4expr.e2 ;
while ((__4tt -> base__4node == 113 )|| (__4tt -> base__4node == 191 ))
# 2155 "/home/claude/cfront-3/src/expr.cpp"
__4tt = __4tt -> __O2__4expr.e1 ;
if (__4tt -> base__4node == 124 )__0this -> __O3__4expr.e2 = __4tt ;

# 2160 "/home/claude/cfront-3/src/expr.cpp"
if ((__0this -> __O2__4expr.e1 -> base__4node == 124 )|| (__0this -> __O3__4expr.e2 -> base__4node == 124 )){ 
# 2161 "/home/claude/cfront-3/src/expr.cpp"
Pname __5temp ;

# 2161 "/home/claude/cfront-3/src/expr.cpp"
__5temp = make_tmp__FcP4typeP5table ( 'A' , (struct type *)mptr_type , __1tbl ) ;

# 2163 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O2__4expr.e1 -> base__4node == 124 ){ 
# 2164 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = mptr_assign__FP4exprT1 ( (struct expr *)__5temp , __0this -> __O2__4expr.e1 ) ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __0this -> __O2__4expr.e1 , (struct expr *)__5temp ) ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = __5temp -> __O1__4expr.tp ;
}

# 2169 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 -> base__4node == 124 ){ 
# 2170 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = mptr_assign__FP4exprT1 ( (struct expr *)__5temp , __0this -> __O3__4expr.e2 ) ;
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __0this -> __O3__4expr.e2 , (struct expr *)__5temp ) ;
__0this -> __O3__4expr.e2 -> __O1__4expr.tp = __5temp -> __O1__4expr.tp ;
}
}

# 2174 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 2177 "/home/claude/cfront-3/src/expr.cpp"
{ bit __3redo1 ;
bit __3redo2 ;

# 2177 "/home/claude/cfront-3/src/expr.cpp"
__3redo1 = 0 ;
__3redo2 = 0 ;
__3c1 = is_cl_obj__4typeFv ( __1t1 ) ;
{ Pname __3eo1 ;

# 2180 "/home/claude/cfront-3/src/expr.cpp"
__3eo1 = eobj ;
__3c2 = is_cl_obj__4typeFv ( __1t2 ) ;
{ Pname __3eo2 ;

# 2182 "/home/claude/cfront-3/src/expr.cpp"
__3eo2 = eobj ;

# 2184 "/home/claude/cfront-3/src/expr.cpp"
if (((__1t1 == __1t2 )|| ((__3c1 && __3c2 )&& (__3c1 -> __O1__4expr.tp == __3c2 -> __O1__4expr.tp )))|| ((__3eo1 && __3eo2 )&& (__3eo1 -> __O1__4expr.tp == __3eo2 ->
# 2184 "/home/claude/cfront-3/src/expr.cpp"
__O1__4expr.tp )))
# 2190 "/home/claude/cfront-3/src/expr.cpp"
__1t = __1t1 ;
else { 
# 2192 "/home/claude/cfront-3/src/expr.cpp"
if (__3c1 && __3c2 ){ 
# 2193 "/home/claude/cfront-3/src/expr.cpp"
Ptype __5tt ;
Pclass __5cl1 ;
Pclass __5cl2 ;

# 2196 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__1__X155 ;

# 2196 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__1__X156 ;

# 2194 "/home/claude/cfront-3/src/expr.cpp"
__5cl1 = (((struct classdef *)(((struct classdef *)__3c1 -> __O1__4expr.tp ))));
__5cl2 = (((struct classdef *)(((struct classdef *)__3c2 -> __O1__4expr.tp ))));
if (( (__1__X155 = __5cl1 ), ( (__1__X156 = __5cl2 ), ( ((__1__X155 == __1__X156 )?1 :((__1__X155 && __1__X156 )?(((int )same_class__8classdefFP8classdefi ( __1__X155 , __1__X156 ,
# 2196 "/home/claude/cfront-3/src/expr.cpp"
0 ) )):0 ))) ) ) || has_base__8classdefFP8classdefiT2 ( __5cl2 , __5cl1 , 0 , 0 ) ){ 
# 2197 "/home/claude/cfront-3/src/expr.cpp"
__1t = __1t1 ;
__3redo2 = 1 ;
goto caca ;
}
else if (has_base__8classdefFP8classdefiT2 ( __5cl1 , __5cl2 , 0 , 0 ) ){ 
# 2202 "/home/claude/cfront-3/src/expr.cpp"
__1t = __1t2 ;
__3redo1 = 1 ;
goto caca ;
}
else if (__5tt = common_base__FP8classdefT1 ( __5cl1 , __5cl2 ) ){ 
# 2207 "/home/claude/cfront-3/src/expr.cpp"
__3redo1 = (__3redo2 = 1 );
__1t = __5tt ;
goto caca ;
}
}

# 2213 "/home/claude/cfront-3/src/expr.cpp"
__1r1 = ( kind__4typeFUcN21 ( __1t1 , __1b , (unsigned char )'P' , (unsigned char )1 ) ) ;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , __1b , (unsigned char )'P' , (unsigned char )1 ) ) ;

# 2216 "/home/claude/cfront-3/src/expr.cpp"
if ((__1r1 == 'P' )&& (__1r2 == 'P' )){ 
# 2217 "/home/claude/cfront-3/src/expr.cpp"
Pptr __5p1 ;
Pptr __5p2 ;
Ptype __5tt ;

# 2217 "/home/claude/cfront-3/src/expr.cpp"
__5p1 = is_ptr__4typeFv ( __1t1 ) ;
__5p2 = is_ptr__4typeFv ( __1t2 ) ;

# 2220 "/home/claude/cfront-3/src/expr.cpp"
if ((__3c1 = is_cl_obj__4typeFv ( __5p1 -> typ__5pvtyp ) )&& (__3c2 = is_cl_obj__4typeFv ( __5p2 -> typ__5pvtyp ) ))
# 2221 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2222 "/home/claude/cfront-3/src/expr.cpp"
Pclass __6cl1 ;
Pclass __6cl2 ;

# 2224 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__1__X157 ;

# 2224 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__1__X158 ;

# 2222 "/home/claude/cfront-3/src/expr.cpp"
__6cl1 = (((struct classdef *)(((struct classdef *)__3c1 -> __O1__4expr.tp ))));
__6cl2 = (((struct classdef *)(((struct classdef *)__3c2 -> __O1__4expr.tp ))));
if (( (__1__X157 = __6cl1 ), ( (__1__X158 = __6cl2 ), ( ((__1__X157 == __1__X158 )?1 :((__1__X157 && __1__X158 )?(((int )same_class__8classdefFP8classdefi ( __1__X157 , __1__X158 ,
# 2224 "/home/claude/cfront-3/src/expr.cpp"
0 ) )):0 ))) ) ) || has_base__8classdefFP8classdefiT2 ( __6cl2 , __6cl1 , 0 , 0 ) ){ 
# 2225 "/home/claude/cfront-3/src/expr.cpp"
__1t = __1t1 ;
goto caca ;
}
else if (has_base__8classdefFP8classdefiT2 ( __6cl1 , __6cl2 , 0 , 0 ) ){ 
# 2229 "/home/claude/cfront-3/src/expr.cpp"
__1t = __1t2 ;
goto caca ;
}
else if (__5tt = common_base__FP8classdefT1 ( __6cl1 , __6cl2 ) ){ 
# 2233 "/home/claude/cfront-3/src/expr.cpp"
__1t = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned
# 2233 "/home/claude/cfront-3/src/expr.cpp"
char )125 , __5tt ) ) ;
goto caca ;
}
}
}

# 2239 "/home/claude/cfront-3/src/expr.cpp"
if ((__1r1 == 108 )&& (__1r2 == 108 )){ 
# 2240 "/home/claude/cfront-3/src/expr.cpp"
if (check__4typeFP4typeUcT2 ( __1t1 , __1t2 , (unsigned char )70 , (unsigned char
# 2240 "/home/claude/cfront-3/src/expr.cpp"
)0 ) )
# 2241 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2241 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V77 ;

# 2241 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V78 ;

# 2241 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"badTs in ?:E: %t and %t", (const struct ea *)( ((& __0__V77 )-> __O1__2ea.p =
# 2241 "/home/claude/cfront-3/src/expr.cpp"
((const void *)__1t1 )), (& __0__V77 )) , (const struct ea *)( ((& __0__V78 )-> __O1__2ea.p = ((const void
# 2241 "/home/claude/cfront-3/src/expr.cpp"
*)__1t2 )), (& __0__V78 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __1t = __1t1 ;
}
else 
# 2245 "/home/claude/cfront-3/src/expr.cpp"
__1t = np_promote__FUcN21P4typeT4N21 ( __1b , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )1 , (unsigned char )1 )
# 2245 "/home/claude/cfront-3/src/expr.cpp"
;
caca :
# 2247 "/home/claude/cfront-3/src/expr.cpp"
{ Pptr __4pt ;
bit __4t_ptr ;
Pname __4cn ;

# 2247 "/home/claude/cfront-3/src/expr.cpp"
__4pt = is_ptr__4typeFv ( __1t ) ;
__4t_ptr = (__4pt && (__4pt -> base__4node == 125 ));
__4cn = ((! __4t_ptr )?(((struct name *)0 )):is_cl_obj__4typeFv ( __4pt -> typ__5pvtyp ) );

# 2251 "/home/claude/cfront-3/src/expr.cpp"
if ((__1t != __1t1 )&& check__4typeFP4typeUcT2 ( __1t , __1t1 , (unsigned char )0 , (unsigned char )0 ) ){ 
# 2252 "/home/claude/cfront-3/src/expr.cpp"
__1t ->
# 2252 "/home/claude/cfront-3/src/expr.cpp"
permanent__4node = 1 ;
if (__3redo1 ){ 
# 2253 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X159 ;

# 2253 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X160 ;

# 2253 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X161 ;

# 2254 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = address__4exprFv ( __0this -> __O2__4expr.e1 ) ;
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X159 = 0 ), ( (__2__X160 = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned
# 2255 "/home/claude/cfront-3/src/expr.cpp"
char )125 , __1t ) ) ), ( (__2__X161 = __0this -> __O2__4expr.e1 ), ( ((__0__X159 || (__0__X159 = (struct cast *)__nw__4exprSFUl (
# 2255 "/home/claude/cfront-3/src/expr.cpp"
(unsigned long )(sizeof (struct cast))) ))?( (__0__X159 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X159 ), (unsigned char )191 , __2__X161 ,
# 2255 "/home/claude/cfront-3/src/expr.cpp"
(struct expr *)0 ) ), (__0__X159 -> __O1__4expr.tp = (__0__X159 -> __O4__4expr.tp2 = __2__X160 ))) :0 ), __0__X159 ) ) ) ) ;
# 2255 "/home/claude/cfront-3/src/expr.cpp"

# 2256 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = docast__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __0this -> __O2__4expr.e1 , (struct expr *)0 ) ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = __1t ;
}
else { 
# 2260 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X162 ;

# 2260 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X163 ;

# 2261 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X162 = 0 ), ( (__2__X163 = __0this -> __O2__4expr.e1 ), ( ((__0__X162 || (__0__X162 = (struct
# 2261 "/home/claude/cfront-3/src/expr.cpp"
cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X162 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X162 ), (unsigned char )191 ,
# 2261 "/home/claude/cfront-3/src/expr.cpp"
__2__X163 , (struct expr *)0 ) ), (__0__X162 -> __O1__4expr.tp = (__0__X162 -> __O4__4expr.tp2 = __1t ))) :0 ), __0__X162 ) ) ) ;
# 2261 "/home/claude/cfront-3/src/expr.cpp"

# 2262 "/home/claude/cfront-3/src/expr.cpp"
if (__4cn )__0this -> __O2__4expr.e1 -> __O2__4expr.e1 = cast_cptr__FP8classdefP4exprP5tablei ( ((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp ))), __0this -> __O2__4expr.e1 -> __O2__4expr.e1 , __1tbl , (__0this ->
# 2262 "/home/claude/cfront-3/src/expr.cpp"
__O2__4expr.e1 -> base__4node == 113 )?1 :0 ) ;
}
}

# 2266 "/home/claude/cfront-3/src/expr.cpp"
if ((__1t != __1t2 )&& check__4typeFP4typeUcT2 ( __1t , __1t2 , (unsigned char )0 , (unsigned char )0 ) ){ 
# 2267 "/home/claude/cfront-3/src/expr.cpp"
__1t ->
# 2267 "/home/claude/cfront-3/src/expr.cpp"
permanent__4node = 1 ;
if (__3redo2 ){ 
# 2268 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X164 ;

# 2268 "/home/claude/cfront-3/src/expr.cpp"
struct type *__2__X165 ;

# 2268 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X166 ;

# 2269 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = address__4exprFv ( __0this -> __O3__4expr.e2 ) ;
__0this -> __O3__4expr.e2 = (struct expr *)( (__0__X164 = 0 ), ( (__2__X165 = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned
# 2270 "/home/claude/cfront-3/src/expr.cpp"
char )125 , __1t ) ) ), ( (__2__X166 = __0this -> __O3__4expr.e2 ), ( ((__0__X164 || (__0__X164 = (struct cast *)__nw__4exprSFUl (
# 2270 "/home/claude/cfront-3/src/expr.cpp"
(unsigned long )(sizeof (struct cast))) ))?( (__0__X164 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X164 ), (unsigned char )191 , __2__X166 ,
# 2270 "/home/claude/cfront-3/src/expr.cpp"
(struct expr *)0 ) ), (__0__X164 -> __O1__4expr.tp = (__0__X164 -> __O4__4expr.tp2 = __2__X165 ))) :0 ), __0__X164 ) ) ) ) ;
# 2270 "/home/claude/cfront-3/src/expr.cpp"

# 2271 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = docast__4exprFP5table ( __0this -> __O3__4expr.e2 , __1tbl ) ;
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __0this -> __O3__4expr.e2 , (struct expr *)0 ) ;
__0this -> __O3__4expr.e2 -> __O1__4expr.tp = __1t ;
}
else { 
# 2275 "/home/claude/cfront-3/src/expr.cpp"
register struct cast *__0__X167 ;

# 2275 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X168 ;

# 2276 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = (struct expr *)( (__0__X167 = 0 ), ( (__2__X168 = __0this -> __O3__4expr.e2 ), ( ((__0__X167 || (__0__X167 = (struct
# 2276 "/home/claude/cfront-3/src/expr.cpp"
cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X167 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X167 ), (unsigned char )191 ,
# 2276 "/home/claude/cfront-3/src/expr.cpp"
__2__X168 , (struct expr *)0 ) ), (__0__X167 -> __O1__4expr.tp = (__0__X167 -> __O4__4expr.tp2 = __1t ))) :0 ), __0__X167 ) ) ) ;
# 2276 "/home/claude/cfront-3/src/expr.cpp"

# 2277 "/home/claude/cfront-3/src/expr.cpp"
if (__4cn )__0this -> __O3__4expr.e2 -> __O2__4expr.e1 = cast_cptr__FP8classdefP4exprP5tablei ( ((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp ))), __0this -> __O3__4expr.e2 -> __O2__4expr.e1 , __1tbl , (__0this ->
# 2277 "/home/claude/cfront-3/src/expr.cpp"
__O3__4expr.e2 -> base__4node == 113 )?1 :0 ) ;
}
}
if ((__4t_ptr && __4pt -> memof__3ptr )&& (__3MPTR == 0 ))
# 2281 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2281 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V79 ;

# 2281 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"conditionalE with%t", (const struct ea *)( ((&
# 2281 "/home/claude/cfront-3/src/expr.cpp"
__0__V79 )-> __O1__2ea.p = ((const void *)__1t )), (& __0__V79 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2281 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 ) ;
} 
# 2281 "/home/claude/cfront-3/src/expr.cpp"
}
}

# 2282 "/home/claude/cfront-3/src/expr.cpp"
}

# 2282 "/home/claude/cfront-3/src/expr.cpp"
}

# 2282 "/home/claude/cfront-3/src/expr.cpp"
}

# 2282 "/home/claude/cfront-3/src/expr.cpp"
}
}
break ;

# 2286 "/home/claude/cfront-3/src/expr.cpp"
case 126 :
# 2287 "/home/claude/cfront-3/src/expr.cpp"
__1r1 = ( kind__4typeFUcN21 ( __1t1 , ((unsigned char )126 ), (unsigned char )'P' , (unsigned char )1 )
# 2287 "/home/claude/cfront-3/src/expr.cpp"
) ;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , ((unsigned char )126 ), (unsigned char )'P' , (unsigned char )1 ) )
# 2288 "/home/claude/cfront-3/src/expr.cpp"
;
__1t = np_promote__FUcN21P4typeT4N21 ( (unsigned char )126 , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )1 , (unsigned char
# 2289 "/home/claude/cfront-3/src/expr.cpp"
)1 ) ;
goto ass ;

# 2292 "/home/claude/cfront-3/src/expr.cpp"
case 127 :
# 2293 "/home/claude/cfront-3/src/expr.cpp"
__1r1 = ( kind__4typeFUcN21 ( __1t1 , ((unsigned char )127 ), (unsigned char )'P' , (unsigned char )1 )
# 2293 "/home/claude/cfront-3/src/expr.cpp"
) ;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , ((unsigned char )127 ), (unsigned char )'P' , (unsigned char )1 ) )
# 2294 "/home/claude/cfront-3/src/expr.cpp"
;
if (((__1r2 == 'P' )&& (__1r1 != 'P' ))&& (__1r1 != 'A' ))error__FPCc ( (const char *)"P -= nonP")
# 2295 "/home/claude/cfront-3/src/expr.cpp"
;
__1t = np_promote__FUcN21P4typeT4N21 ( (unsigned char )127 , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )1 , (unsigned char
# 2296 "/home/claude/cfront-3/src/expr.cpp"
)1 ) ;
goto ass ;

# 2299 "/home/claude/cfront-3/src/expr.cpp"
case 128 :
# 2300 "/home/claude/cfront-3/src/expr.cpp"
case 129 :
# 2301 "/home/claude/cfront-3/src/expr.cpp"
__1r1 = ( kind__4typeFUcN21 ( __1t1 , __1b , (unsigned char )'N' , (unsigned char )1 ) )
# 2301 "/home/claude/cfront-3/src/expr.cpp"
;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , __1b , (unsigned char )'N' , (unsigned char )1 ) ) ;
__1t = np_promote__FUcN21P4typeT4N21 ( __1b , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )1 , (unsigned char )1 ) ;
# 2303 "/home/claude/cfront-3/src/expr.cpp"

# 2304 "/home/claude/cfront-3/src/expr.cpp"
goto ass ;

# 2306 "/home/claude/cfront-3/src/expr.cpp"
case 130 :
# 2307 "/home/claude/cfront-3/src/expr.cpp"
__1r1 = ( kind__4typeFUcN21 ( __1t1 , ((unsigned char )130 ), (unsigned char )'I' , (unsigned char )1 )
# 2307 "/home/claude/cfront-3/src/expr.cpp"
) ;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , ((unsigned char )130 ), (unsigned char )'I' , (unsigned char )1 ) )
# 2308 "/home/claude/cfront-3/src/expr.cpp"
;
__1t = np_promote__FUcN21P4typeT4N21 ( (unsigned char )130 , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )1 , (unsigned char
# 2309 "/home/claude/cfront-3/src/expr.cpp"
)1 ) ;
goto ass ;

# 2312 "/home/claude/cfront-3/src/expr.cpp"
case 131 :
# 2313 "/home/claude/cfront-3/src/expr.cpp"
case 132 :
# 2314 "/home/claude/cfront-3/src/expr.cpp"
case 133 :
# 2315 "/home/claude/cfront-3/src/expr.cpp"
case 134 :
# 2316 "/home/claude/cfront-3/src/expr.cpp"
case 135 :
# 2317 "/home/claude/cfront-3/src/expr.cpp"
__1r1 = ( kind__4typeFUcN21 ( __1t1 , __1b , (unsigned char )'I' , (unsigned
# 2317 "/home/claude/cfront-3/src/expr.cpp"
char )1 ) ) ;
__1r2 = ( kind__4typeFUcN21 ( __1t2 , __1b , (unsigned char )'I' , (unsigned char )1 ) ) ;
((void )np_promote__FUcN21P4typeT4N21 ( __1b , __1r1 , __1r2 , __1t1 , __1t2 , (unsigned char )0 , (unsigned char )1 ) );
# 2319 "/home/claude/cfront-3/src/expr.cpp"

# 2320 "/home/claude/cfront-3/src/expr.cpp"
__1t = (struct type *)int_type ;
goto ass ;
ass :
# 2323 "/home/claude/cfront-3/src/expr.cpp"
if (((__1r1 == 'P' )&& (check__4typeFP4typeUcT2 ( __1t1 , Pvoid_type , (unsigned char )254 , (unsigned char )0 ) == 0 ))&&
# 2323 "/home/claude/cfront-3/src/expr.cpp"
(ptr_is_template_formal__FP3ptr ( ((struct ptr *)(((struct ptr *)__1t1 )))) == 0 ))
# 2325 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2325 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V80 ;

# 2325 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k of void*", (const struct ea *)( (( ((& __0__V80 )->
# 2325 "/home/claude/cfront-3/src/expr.cpp"
__O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V80 )) , (const struct ea *)ea0 , (const struct
# 2325 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} __0this -> __O1__4expr.tp = __1t ;
__0this -> __O4__4expr.as_type = __1t ;
__1t2 = __1t ;

# 2330 "/home/claude/cfront-3/src/expr.cpp"
case 70 :
# 2333 "/home/claude/cfront-3/src/expr.cpp"
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 2334 "/home/claude/cfront-3/src/expr.cpp"
case 147 :
# 2335 "/home/claude/cfront-3/src/expr.cpp"
case 71 :
# 2336 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2337 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 ,
# 2337 "/home/claude/cfront-3/src/expr.cpp"
(unsigned char )145 , (struct expr *)0 , __0this -> __O2__4expr.e1 -> __O3__4expr.e2 ) ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = 0 ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __0this -> __O2__4expr.e1 , (struct expr *)0 ) ;
return typ__4exprFP5table ( __0this , __1tbl ) ;
}
case 68 :
# 2343 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2344 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __0this ->
# 2344 "/home/claude/cfront-3/src/expr.cpp"
__O2__4expr.e1 -> __O2__4expr.e1 ) ;
__0this -> __O2__4expr.e1 -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __0this -> __O2__4expr.e1 -> __O3__4expr.e2 )
# 2345 "/home/claude/cfront-3/src/expr.cpp"
;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = 0 ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __0this -> __O2__4expr.e1 , (struct expr *)0 ) ;
return typ__4exprFP5table ( __0this , __1tbl ) ;
}
case 70 :
# 2351 "/home/claude/cfront-3/src/expr.cpp"
case 126 :
# 2352 "/home/claude/cfront-3/src/expr.cpp"
case 127 :
# 2353 "/home/claude/cfront-3/src/expr.cpp"
case 128 :
# 2354 "/home/claude/cfront-3/src/expr.cpp"
case 129 :
# 2355 "/home/claude/cfront-3/src/expr.cpp"
case 130 :
# 2356 "/home/claude/cfront-3/src/expr.cpp"
case 131 :
# 2357 "/home/claude/cfront-3/src/expr.cpp"
case 132 :
# 2358 "/home/claude/cfront-3/src/expr.cpp"
case 133 :
# 2359 "/home/claude/cfront-3/src/expr.cpp"
case 134 :
# 2360 "/home/claude/cfront-3/src/expr.cpp"
case 135 :
# 2361 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2362 "/home/claude/cfront-3/src/expr.cpp"
__0this -> base__4node =
# 2362 "/home/claude/cfront-3/src/expr.cpp"
147 ;
nin ++ ;
if (not_simple__4exprFi ( __0this -> __O2__4expr.e1 -> __O2__4expr.e1 , 0 ) ){ 
# 2364 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V81 ;

# 2364 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"lvalue %k too complicated", (const struct ea *)( ((
# 2364 "/home/claude/cfront-3/src/expr.cpp"
((& __0__V81 )-> __O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V81 )) , (const struct ea *)ea0 ,
# 2364 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} nin -- ;
{ Pexpr __4aa ;
Pexpr __4bb ;

# 2366 "/home/claude/cfront-3/src/expr.cpp"
__4aa = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> __O2__4expr.e1 -> base__4node , __0this -> __O2__4expr.e1 -> __O2__4expr.e1 , __0this -> __O2__4expr.e1 -> __O3__4expr.e2 ) ;
# 2366 "/home/claude/cfront-3/src/expr.cpp"

# 2367 "/home/claude/cfront-3/src/expr.cpp"
__4bb = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __1b , __0this -> __O2__4expr.e1 -> __O2__4expr.e1 , __0this -> __O3__4expr.e2 ) ;
__0this -> __O2__4expr.e1 = __4aa ;
__0this -> __O3__4expr.e2 = __4bb ;
return typ__4exprFP5table ( __0this , __1tbl ) ;

# 2370 "/home/claude/cfront-3/src/expr.cpp"
}
}
case 48 :
# 2373 "/home/claude/cfront-3/src/expr.cpp"
case 49 :
# 2374 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2375 "/home/claude/cfront-3/src/expr.cpp"
if (! __0this -> __O2__4expr.e1 -> __O3__4expr.e2 )break ;
__0this -> base__4node = 147 ;
nin ++ ;
if (not_simple__4exprFi ( __0this -> __O2__4expr.e1 -> __O3__4expr.e2 , 0 ) ){ 
# 2378 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V82 ;

# 2378 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"lvalue %k too complicated", (const struct ea *)( ((
# 2378 "/home/claude/cfront-3/src/expr.cpp"
((& __0__V82 )-> __O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V82 )) , (const struct ea *)ea0 ,
# 2378 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} nin -- ;
{ Pexpr __4aa ;
Pexpr __4bb ;

# 2380 "/home/claude/cfront-3/src/expr.cpp"
__4aa = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __0this -> __O2__4expr.e1 -> base__4node , (struct expr *)0 , __0this -> __O2__4expr.e1 -> __O3__4expr.e2 ) ;
__4bb = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , __1b , __0this -> __O2__4expr.e1 -> __O3__4expr.e2 , __0this -> __O3__4expr.e2 ) ;
__0this -> __O2__4expr.e1 = __4aa ;
__0this -> __O3__4expr.e2 = __4bb ;
return typ__4exprFP5table ( __0this , __1tbl ) ;

# 2384 "/home/claude/cfront-3/src/expr.cpp"
}
}
case 44 :
# 2387 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2388 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __4r ;

# 2388 "/home/claude/cfront-3/src/expr.cpp"
__4r = __0this -> __O2__4expr.e1 ;

# 2393 "/home/claude/cfront-3/src/expr.cpp"
if (((__4r -> __O2__4expr.e1 -> base__4node == 147 )&& (__4r -> __O2__4expr.e1 -> __O3__4expr.e2 -> base__4node == 145 ))&& (__4r -> __O2__4expr.e1 -> __O3__4expr.e2 -> __O3__4expr.e2 ->
# 2393 "/home/claude/cfront-3/src/expr.cpp"
base__4node == 85 ))
# 2395 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2396 "/home/claude/cfront-3/src/expr.cpp"
const char *__5s ;

# 2396 "/home/claude/cfront-3/src/expr.cpp"
__5s = __4r -> __O2__4expr.e1 -> __O3__4expr.e2 -> __O3__4expr.e2 -> __O2__4expr.string ;
if (((__5s [0 ])== '_' )&& ((__5s [1 ])== '_' ))
# 2398 "/home/claude/cfront-3/src/expr.cpp"
error__FPCc ( (const char *)"left hand side not lvalue") ;
}
}
}

# 2403 "/home/claude/cfront-3/src/expr.cpp"
if (lval__4exprFUc ( __0this -> __O2__4expr.e1 , __1b ) == 0 ){ 
# 2404 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = (struct type *)any_type ;
return __0this ;
}

# 2408 "/home/claude/cfront-3/src/expr.cpp"
__1t1 = skiptypedefs__4typeFv ( __1t1 ) ;
switch (__1t1 -> base__4node ){ 
# 2410 "/home/claude/cfront-3/src/expr.cpp"
case 21 :
# 2411 "/home/claude/cfront-3/src/expr.cpp"
case 5 :
# 2412 "/home/claude/cfront-3/src/expr.cpp"
case 29 :
# 2413 "/home/claude/cfront-3/src/expr.cpp"
{ Ptype __4t ;

# 2413 "/home/claude/cfront-3/src/expr.cpp"
__4t = skiptypedefs__4typeFv ( __0this -> __O3__4expr.e2 -> __O1__4expr.tp ) ;
switch (__4t -> base__4node ){ 
# 2414 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X169 ;

# 2415 "/home/claude/cfront-3/src/expr.cpp"
case 22 :
# 2416 "/home/claude/cfront-3/src/expr.cpp"
case 122 :
# 2417 "/home/claude/cfront-3/src/expr.cpp"
case 15 :
# 2418 "/home/claude/cfront-3/src/expr.cpp"
case 11 :
# 2419 "/home/claude/cfront-3/src/expr.cpp"
case 181 :
# 2420 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2420 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V83 ;

# 2420 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V84 ;

# 2420 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%t assigned to %t", (const struct ea *)( (__2__X169 =
# 2420 "/home/claude/cfront-3/src/expr.cpp"
(const void *)__0this -> __O3__4expr.e2 -> __O1__4expr.tp ), ( ((& __0__V83 )-> __O1__2ea.p = __2__X169 ), (& __0__V83 )) ) ,
# 2420 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)( ((& __0__V84 )-> __O1__2ea.p = ((const void *)__1t1 )), (& __0__V84 )) , (const struct
# 2420 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}

# 2424 "/home/claude/cfront-3/src/expr.cpp"
case 22 :
# 2425 "/home/claude/cfront-3/src/expr.cpp"
case 122 :
# 2426 "/home/claude/cfront-3/src/expr.cpp"
if ((((__1b == 70 )&& (((struct basetype *)(((struct basetype *)__1t1 ))))-> b_unsigned__8basetype )&& (__0this -> __O3__4expr.e2 -> base__4node == 107 ))&&
# 2426 "/home/claude/cfront-3/src/expr.cpp"
(__0this -> __O3__4expr.e2 -> __O3__4expr.e2 -> base__4node == 82 ))
# 2430 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCc ( (int )'w' , (const char *)"negative assigned to unsigned")
# 2430 "/home/claude/cfront-3/src/expr.cpp"
;
break ;
case 125 :
# 2433 "/home/claude/cfront-3/src/expr.cpp"
if (__1b == 70 ){ 
# 2434 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = ptr_init__FP3ptrP4exprP5table ( ((struct ptr *)(((struct ptr *)__1t1 ))), __0this -> __O3__4expr.e2 , __1tbl ) ;
# 2434 "/home/claude/cfront-3/src/expr.cpp"

# 2435 "/home/claude/cfront-3/src/expr.cpp"
__1t2 = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;

# 2437 "/home/claude/cfront-3/src/expr.cpp"
if (Pchecked ){ 
# 2438 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
return __0this ;
}
}
break ;
case 119 :
# 2444 "/home/claude/cfront-3/src/expr.cpp"
{ Pname __4c1 ;

# 2444 "/home/claude/cfront-3/src/expr.cpp"
__4c1 = is_cl_obj__4typeFv ( __1t1 ) ;

# 2447 "/home/claude/cfront-3/src/expr.cpp"
if (__4c1 && __4c1 -> __O1__4expr.tp )
# 2449 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2450 "/home/claude/cfront-3/src/expr.cpp"
Pname __5c2 ;

# 2450 "/home/claude/cfront-3/src/expr.cpp"
__5c2 = is_cl_obj__4typeFv ( __1t2 ) ;

# 2452 "/home/claude/cfront-3/src/expr.cpp"
if (__4c1 != __5c2 ){ 
# 2467 "/home/claude/cfront-3/src/expr.cpp"
if ((((__5c2 && __5c2 -> __O1__4expr.tp )&& (can_coerce__FP4typeT1 ( __1t1 , __1t2 ) == 0 ))&& ( (
# 2467 "/home/claude/cfront-3/src/expr.cpp"
clear__5clistFv ( vcllist ) , (vcllist = 0 )) , (1 < is_unique_base__FP8classdefPCciT3T1 ( ((struct classdef *)(((struct classdef *)__5c2 -> __O1__4expr.tp ))), __4c1 -> __O2__4expr.string ,
# 2467 "/home/claude/cfront-3/src/expr.cpp"
0 , 0 , (struct classdef *)0 ) )) )&& ((((struct classdef *)(((struct classdef *)__4c1 -> __O1__4expr.tp ))))-> c_xref__8classdef & 13))
# 2471 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2473 "/home/claude/cfront-3/src/expr.cpp"
if (make_assignment__FP4name (
# 2473 "/home/claude/cfront-3/src/expr.cpp"
__4c1 ) )return oper_overload__4exprFP5table ( __0this , __1tbl ) ;
}
else 
# 2476 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2476 "/home/claude/cfront-3/src/expr.cpp"
struct texpr *__0__X170 ;

# 2476 "/home/claude/cfront-3/src/expr.cpp"
struct expr *__2__X171 ;

# 2476 "/home/claude/cfront-3/src/expr.cpp"
struct classdef *__0__X172 ;

# 2477 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __0this -> __O3__4expr.e2 , (struct expr *)0 ) ;
__0this -> __O3__4expr.e2 = (struct expr *)( (__0__X170 = 0 ), ( (__2__X171 = __0this -> __O3__4expr.e2 ), ( ((__0__X170 || (__0__X170 = (struct
# 2478 "/home/claude/cfront-3/src/expr.cpp"
texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr))) ))?( (__0__X170 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X170 ), ((unsigned char )157 ),
# 2478 "/home/claude/cfront-3/src/expr.cpp"
__2__X171 , (struct expr *)0 ) ), (__0__X170 -> __O4__4expr.tp2 = __1t1 )) :0 ), __0__X170 ) ) ) ;
if ((( (__0__X172 = (((struct classdef *)(((struct classdef *)__4c1 -> __O1__4expr.tp ))))), ( __0__X172 -> c_dtor__8classdef ) ) == 0 )&& (has_oper__8classdefFUc (
# 2479 "/home/claude/cfront-3/src/expr.cpp"
((struct classdef *)(((struct classdef *)__4c1 -> __O1__4expr.tp ))), (unsigned char )70 ) == 0 ))
# 2480 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2483 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 -> __O3__4expr.e2 = __0this -> __O2__4expr.e1 ;
# 2483 "/home/claude/cfront-3/src/expr.cpp"

# 2484 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = typ__4exprFP5table ( __0this -> __O3__4expr.e2 , __1tbl ) ;
if (((__0this -> __O3__4expr.e2 -> base__4node == 111 )&& (__0this -> __O3__4expr.e2 -> __O2__4expr.e1 -> base__4node == 146 ))|| ((__0this -> __O3__4expr.e2 -> base__4node == 70 )&&
# 2485 "/home/claude/cfront-3/src/expr.cpp"
(__0this -> __O3__4expr.e2 -> __O2__4expr.e1 == __0this -> __O2__4expr.e1 )))
# 2486 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2488 "/home/claude/cfront-3/src/expr.cpp"
((*__0this ))= (*__0this -> __O3__4expr.e2 );
}
__0this -> __O1__4expr.tp = __1t1 ;
return __0this ;
}
return typ__4exprFP5table ( __0this , __1tbl ) ;
}
}
else 
# 2498 "/home/claude/cfront-3/src/expr.cpp"
if (__4c1 -> __O1__4expr.tp && ((((struct classdef *)(((struct classdef *)__4c1 -> __O1__4expr.tp ))))-> c_xref__8classdef & 13)){ 
# 2499 "/home/claude/cfront-3/src/expr.cpp"
if (make_assignment__FP4name ( __4c1 ) )return
# 2499 "/home/claude/cfront-3/src/expr.cpp"
oper_overload__4exprFP5table ( __0this , __1tbl ) ;
}
}
((void )tsizeof__4typeFi ( __1t1 , 0 ) );
break ;
}
}

# 2508 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2509 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __3x ;

# 2510 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X173 ;

# 2510 "/home/claude/cfront-3/src/expr.cpp"
struct type *__1__Xt00anpbtx2ewcog ;

# 2510 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X174 ;

# 2509 "/home/claude/cfront-3/src/expr.cpp"
__3x = try_to_coerce__FP4typeP4exprPCcP5table ( __1t1 , __0this -> __O3__4expr.e2 , (const char *)"assignment", __1tbl ) ;
# 2509 "/home/claude/cfront-3/src/expr.cpp"

# 2511 "/home/claude/cfront-3/src/expr.cpp"
if (((__1t1 -> base__4node == 119 )&& classtype__4typeFv ( __1t1 ) )&& has_const_mem__8classdefFv ( classtype__4typeFv ( __1t1 ) ) )
# 2512 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2512 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V85 ;
# 2512 "/home/claude/cfront-3/src/expr.cpp"

# 2512 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot assign to an object of class %t with const member(s)", (const struct ea *)( (__2__X173 = (const void
# 2512 "/home/claude/cfront-3/src/expr.cpp"
*)classtype__4typeFv ( __1t1 ) ), ( ((& __0__V85 )-> __O1__2ea.p = __2__X173 ), (& __0__V85 )) ) , (const struct
# 2512 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 2514 "/home/claude/cfront-3/src/expr.cpp"
if (__3x )
# 2515 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = __3x ;
else if (( (__1__Xt00anpbtx2ewcog = skiptypedefs__4typeFv ( __1t2 ) ), ( ((__1__Xt00anpbtx2ewcog -> base__4node == 125 )?( (__1__Xt00anpbtx2ewcog = skiptypedefs__4typeFv ( (((struct
# 2516 "/home/claude/cfront-3/src/expr.cpp"
ptr *)(((struct ptr *)__1__Xt00anpbtx2ewcog ))))-> typ__5pvtyp ) ), 0 ) :0 ), (((unsigned char )((__1__Xt00anpbtx2ewcog -> base__4node == ((unsigned char )76 ))?1 :0 )))) )
# 2516 "/home/claude/cfront-3/src/expr.cpp"
)
# 2517 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2517 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V86 ;

# 2517 "/home/claude/cfront-3/src/expr.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad assignmentT:%t =&overloaded function", (const struct ea *)( (__2__X174 = (const void
# 2517 "/home/claude/cfront-3/src/expr.cpp"
*)__0this -> __O2__4expr.e1 -> __O1__4expr.tp ), ( ((& __0__V86 )-> __O1__2ea.p = __2__X174 ), (& __0__V86 )) ) , (const struct
# 2517 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (check__4typeFP4typeUcT2 ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp , __1t2 , (unsigned char )70 , (unsigned char )0 )
# 2518 "/home/claude/cfront-3/src/expr.cpp"
){ 
# 2518 "/home/claude/cfront-3/src/expr.cpp"
const void *__2__X175 ;

# 2519 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2519 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V87 ;

# 2519 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V88 ;

# 2519 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"bad assignmentT:%t =%t", (const struct ea *)( (__2__X175 =
# 2519 "/home/claude/cfront-3/src/expr.cpp"
(const void *)__0this -> __O2__4expr.e1 -> __O1__4expr.tp ), ( ((& __0__V87 )-> __O1__2ea.p = __2__X175 ), (& __0__V87 )) ) ,
# 2519 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)( ((& __0__V88 )-> __O1__2ea.p = ((const void *)__1t2 )), (& __0__V88 )) , (const struct
# 2519 "/home/claude/cfront-3/src/expr.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
if (no_const )
# 2521 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCc ( (int )'c' , (const char *)" (no usable const conversion)\n") ;
else error__FiPCc ( (int )'c' , (const char *)"\n") ;
} }
else if ((__1t1 = (struct type *)is_ptr__4typeFv ( __1t1 ) )&& memptr__4typeFv ( __1t1 ) ){ 
# 2525 "/home/claude/cfront-3/src/expr.cpp"
if (__1t2 == (((struct
# 2525 "/home/claude/cfront-3/src/expr.cpp"
type *)zero_type ))){ 
# 2526 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __5ee ;

# 2526 "/home/claude/cfront-3/src/expr.cpp"
__5ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , zero ) ;
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , __5ee , zero ) ;
}
else if ((__1t2 -> base__4node == 125 )&& memptr__4typeFv ( __1t2 ) ){ 
# 2531 "/home/claude/cfront-3/src/expr.cpp"
}
else { 
# 2533 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __5x ;

# 2533 "/home/claude/cfront-3/src/expr.cpp"
__5x = ptr_init__FP3ptrP4exprP5table ( ((struct ptr *)(((struct ptr *)__1t1 ))), __0this -> __O3__4expr.e2 , __1tbl ) ;
if (__5x != __0this -> __O3__4expr.e2 )__0this -> __O3__4expr.e2 = __5x ;
}
}
}
__1t = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
break ;
case 71 :
# 2541 "/home/claude/cfront-3/src/expr.cpp"
case 147 :
# 2543 "/home/claude/cfront-3/src/expr.cpp"
if (__1t1 -> base__4node == 108 ){ 
# 2544 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 ,
# 2544 "/home/claude/cfront-3/src/expr.cpp"
(struct expr *)0 , __0this -> __O2__4expr.e1 ) ;
typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
__1t1 = __0this -> __O2__4expr.e1 -> __O1__4expr.tp ;
}
if (__1t2 -> base__4node == 108 ){ 
# 2549 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 ,
# 2549 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O3__4expr.e2 ) ;
typ__4exprFP5table ( __0this -> __O3__4expr.e2 , __1tbl ) ;
__1t2 = __0this -> __O3__4expr.e2 -> __O1__4expr.tp ;
}
if (__0this -> __O2__4expr.e1 -> base__4node == 124 ){ 
# 2554 "/home/claude/cfront-3/src/expr.cpp"
Pname __3temp1 ;

# 2554 "/home/claude/cfront-3/src/expr.cpp"
__3temp1 = make_tmp__FcP4typeP5table ( 'A' , (struct type *)mptr_type , __1tbl ) ;
__0this -> __O2__4expr.e1 = mptr_assign__FP4exprT1 ( (struct expr *)__3temp1 , __0this -> __O2__4expr.e1 ) ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __0this -> __O2__4expr.e1 , (struct expr *)__3temp1 ) ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = __3temp1 -> __O1__4expr.tp ;
}

# 2560 "/home/claude/cfront-3/src/expr.cpp"
if (__0this -> __O3__4expr.e2 -> base__4node == 124 ){ 
# 2561 "/home/claude/cfront-3/src/expr.cpp"
Pname __3temp2 ;

# 2561 "/home/claude/cfront-3/src/expr.cpp"
__3temp2 = make_tmp__FcP4typeP5table ( 'A' , (struct type *)mptr_type , __1tbl ) ;
__0this -> __O3__4expr.e2 = mptr_assign__FP4exprT1 ( (struct expr *)__3temp2 , __0this -> __O3__4expr.e2 ) ;
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __0this -> __O3__4expr.e2 , (struct expr *)__3temp2 ) ;
__0this -> __O3__4expr.e2 -> __O1__4expr.tp = __3temp2 -> __O1__4expr.tp ;

# 2566 "/home/claude/cfront-3/src/expr.cpp"
}

# 2568 "/home/claude/cfront-3/src/expr.cpp"
__1t = __1t2 ;
break ;
default :
# 2571 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2571 "/home/claude/cfront-3/src/expr.cpp"
struct ea __0__V89 ;

# 2571 "/home/claude/cfront-3/src/expr.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"unknown operator%k", (const struct ea *)( ((
# 2571 "/home/claude/cfront-3/src/expr.cpp"
((& __0__V89 )-> __O1__2ea.i = ((unsigned long )__1b )), 0 ) ), (& __0__V89 )) , (const struct ea *)ea0 ,
# 2571 "/home/claude/cfront-3/src/expr.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 2574 "/home/claude/cfront-3/src/expr.cpp"
__0this -> __O1__4expr.tp = __1t ;
return __0this ;
}

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 2579 "/home/claude/cfront-3/src/expr.cpp"
bit is_const_obj__4exprFv (register struct expr *__0this )
# 2580 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2581 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __1ee ;

# 2581 "/home/claude/cfront-3/src/expr.cpp"
__1ee = __0this ;
if (__1ee == 0 )return (unsigned char )0 ;

# 2584 "/home/claude/cfront-3/src/expr.cpp"
while (__1ee && ((__1ee -> base__4node == 45 )|| (__1ee -> base__4node == 44 ))){ 
# 2585 "/home/claude/cfront-3/src/expr.cpp"
Pexpr __2m ;

# 2585 "/home/claude/cfront-3/src/expr.cpp"
__2m = __1ee -> __O4__4expr.mem ;
if (((__1ee -> base__4node == 44 )&& __2m -> __O1__4expr.tp )&& is_ptr__4typeFv ( __2m -> __O1__4expr.tp ) )
# 2587 "/home/claude/cfront-3/src/expr.cpp"
break ;
__1ee = __1ee -> __O2__4expr.e1 ;
}
if (__1ee ){ 
# 2591 "/home/claude/cfront-3/src/expr.cpp"
Pptr __2p ;
Ptype __2ttt ;

# 2592 "/home/claude/cfront-3/src/expr.cpp"
__2ttt = __1ee -> __O1__4expr.tp ;
switch (__0this -> base__4node ){ 
# 2594 "/home/claude/cfront-3/src/expr.cpp"
case 44 :
# 2595 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2596 "/home/claude/cfront-3/src/expr.cpp"
__2p = (__2ttt ?is_ptr__4typeFv ( __2ttt ) :(((struct ptr *)0 )));
if (__2p && tconst__4typeFv ( __2p -> typ__5pvtyp ) )
# 2598 "/home/claude/cfront-3/src/expr.cpp"
return (unsigned char )1 ;
break ;
}
case 45 :
# 2602 "/home/claude/cfront-3/src/expr.cpp"
{ 
# 2603 "/home/claude/cfront-3/src/expr.cpp"
__2p = (__2ttt ?is_ptr__4typeFv ( __2ttt ) :(((struct ptr *)0 )));
{ int __4tc ;

# 2604 "/home/claude/cfront-3/src/expr.cpp"
__4tc = (__2ttt ?(((int )tconst__4typeFv ( __2ttt ) )):0 );
if ((((! __2p )&& __2ttt )&& __4tc )&& ((! strict_opt )|| (__4tc != 2 )))
# 2606 "/home/claude/cfront-3/src/expr.cpp"
return (unsigned char )1 ;
break ;

# 2607 "/home/claude/cfront-3/src/expr.cpp"
}
}
}
}
return (unsigned char )0 ;
}

# 76 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFUl (struct ea *__0this , 
# 76 "/home/claude/cfront-3/src/cfront.h"
size_t __2ii ){ 
# 76 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct ea *)__nw__FUl ( (unsigned long )(sizeof (struct ea)))
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

# 2612 "/home/claude/cfront-3/src/expr.cpp"

/* the end */
