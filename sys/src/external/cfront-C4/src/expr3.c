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

# 33 "/home/claude/cfront-3/src/expr3.cpp"
static int refd ;
static int no_sti ;
static int miFlag ;
int no_const = 0 ;
extern int stat_init ;
int ambig = 0 ;
bit in_return = 0 ;

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 342 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr__4typeFv (struct type *__0this );

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 460 "/home/claude/cfront-3/src/cfront.h"
bit has_base__8classdefFP8classdefiT2 (struct classdef *__0this , Pclass __1cl , int __1level , int __1ccflag );

# 41 "/home/claude/cfront-3/src/expr3.cpp"
static int pr_dominate__FP4typeT1 (Ptype __1t1 , Ptype __1t2 )
# 44 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 45 "/home/claude/cfront-3/src/expr3.cpp"
Pname __1cn1 ;
Pname __1cn2 ;

# 45 "/home/claude/cfront-3/src/expr3.cpp"
__1cn1 = is_cl_obj__4typeFv ( __1t1 ) ;
__1cn2 = is_cl_obj__4typeFv ( __1t2 ) ;

# 48 "/home/claude/cfront-3/src/expr3.cpp"
if ((__1cn1 == 0 )|| (__1cn2 == 0 )){ 
# 49 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __2p1 ;
Ptype __2p2 ;

# 49 "/home/claude/cfront-3/src/expr3.cpp"
__2p1 = (struct type *)is_ptr__4typeFv ( __1t1 ) ;
__2p2 = (struct type *)is_ptr__4typeFv ( __1t2 ) ;
if (__2p1 && __2p2 ){ 
# 52 "/home/claude/cfront-3/src/expr3.cpp"
__1cn1 = is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)__2p1 ))))-> typ__5pvtyp ) ;
__1cn2 = is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)__2p2 ))))-> typ__5pvtyp ) ;
if ((__1cn1 == 0 )|| (__1cn2 == 0 ))return 0 ;
}
else { 
# 57 "/home/claude/cfront-3/src/expr3.cpp"
__2p1 = (struct type *)is_ref__4typeFv ( __1t1 ) ;
__2p2 = (struct type *)is_ref__4typeFv ( __1t2 ) ;
if (__2p1 && __2p2 ){ 
# 60 "/home/claude/cfront-3/src/expr3.cpp"
__1cn1 = is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)__2p1 ))))-> typ__5pvtyp ) ;
__1cn2 = is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)__2p2 ))))-> typ__5pvtyp ) ;
if ((__1cn1 == 0 )|| (__1cn2 == 0 ))return 0 ;
}
else 
# 65 "/home/claude/cfront-3/src/expr3.cpp"
return 0 ;
}
}
{ Pclass __1c1 ;
Pclass __1c2 ;

# 68 "/home/claude/cfront-3/src/expr3.cpp"
__1c1 = (((struct classdef *)(((struct classdef *)__1cn1 -> __O1__4expr.tp ))));
__1c2 = (((struct classdef *)(((struct classdef *)__1cn2 -> __O1__4expr.tp ))));

# 71 "/home/claude/cfront-3/src/expr3.cpp"
if (has_base__8classdefFP8classdefiT2 ( __1c1 , __1c2 , 0 , 0 ) )return 1 ;
if (has_base__8classdefFP8classdefiT2 ( __1c2 , __1c1 , 0 , 0 ) )return 2 ;
return 0 ;

# 73 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 76 "/home/claude/cfront-3/src/expr3.cpp"
Pname Ntmp = 0 ;
Pname Ntmp_refd = 0 ;
Pname Ntmp_flag = 0 ;
extern Pname Ntmp_flag_list ;

# 467 "/home/claude/cfront-3/src/cfront.h"

# 220 "/home/claude/cfront-3/src/cfront.h"
struct table *__ct__5tableFsP5tableP4name (struct table *__0this , short , Ptable , Pname );

# 37 "/home/claude/cfront-3/src/cfront.h"
extern char *make_name__FUc (TOK );

# 346 "/home/claude/cfront-3/src/cfront.h"
int tsizeof__4typeFi (struct type *__0this , int );

# 940 "/home/claude/cfront-3/src/cfront.h"
Pname dcl__4nameFP5tableUc (struct name *__0this , Ptable , TOK );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 81 "/home/claude/cfront-3/src/expr3.cpp"
Pname make_tmp__FcP4typeP5table (char __1c , Ptype __1t , Ptable __1tbl )
# 82 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 83 "/home/claude/cfront-3/src/expr3.cpp"
int __1dt ;
Pname __1tn ;
Pname __1cn ;

# 86 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__0__X46 ;

# 83 "/home/claude/cfront-3/src/expr3.cpp"
__1dt = 0 ;
__1tn = __1tbl -> t_name__5table ;
__1cn = is_cl_obj__4typeFv ( __1t ) ;

# 87 "/home/claude/cfront-3/src/expr3.cpp"
if (__1tn && __1tn -> __O1__4expr.tp )error__FiPCc ( (int )'s' , (const char *)"defaultA too complicated") ;
# 87 "/home/claude/cfront-3/src/expr3.cpp"

# 88 "/home/claude/cfront-3/src/expr3.cpp"
if (__1cn && ( (__0__X46 = (((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))))), ( __0__X46 -> c_dtor__8classdef ) ) )__1dt = 1 ;
# 88 "/home/claude/cfront-3/src/expr3.cpp"

# 89 "/home/claude/cfront-3/src/expr3.cpp"
if ((Ntmp == 0 )&& __1dt )Ntmp = __1cn ;

# 92 "/home/claude/cfront-3/src/expr3.cpp"
if (Cstmt ){ 
# 93 "/home/claude/cfront-3/src/expr3.cpp"
if (Cstmt -> memtbl__4stmt == 0 )Cstmt -> memtbl__4stmt = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )4 , __1tbl , (struct
# 93 "/home/claude/cfront-3/src/expr3.cpp"
name *)0 ) ;
__1tbl = Cstmt -> memtbl__4stmt ;
}
else if ((__1tbl == gtbl )&& (no_sti == 0 )){ 
# 97 "/home/claude/cfront-3/src/expr3.cpp"
if (sti_tbl == 0 )sti_tbl = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )8 ,
# 97 "/home/claude/cfront-3/src/expr3.cpp"
gtbl , (struct name *)0 ) ;
__1tbl = sti_tbl ;
}

# 101 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __1tmpx ;

# 101 "/home/claude/cfront-3/src/expr3.cpp"
__1tmpx = __ct__4nameFPCc ( (struct name *)0 , (const char *)make_name__FUc ( (unsigned char )__1c ) ) ;
__1tmpx -> where__4name = no_where ;
__1tmpx -> __O1__4expr.tp = __1t ;
((void )tsizeof__4typeFi ( __1t , 0 ) );
if (__1t -> base__4node == 119 ){ 
# 106 "/home/claude/cfront-3/src/expr3.cpp"
Pclass __2cl ;

# 106 "/home/claude/cfront-3/src/expr3.cpp"
__2cl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ))));
if (__2cl -> lex_level__4type )__1tmpx -> lex_level__4name = __2cl -> lex_level__4type ;
}

# 110 "/home/claude/cfront-3/src/expr3.cpp"
{ TOK __1scop ;

# 110 "/home/claude/cfront-3/src/expr3.cpp"
__1scop = 136 ;
if (stat_init && __1dt ){ 
# 112 "/home/claude/cfront-3/src/expr3.cpp"
__1tmpx -> n_sto__4name = 31 ;

# 112 "/home/claude/cfront-3/src/expr3.cpp"
__1scop = 137 ;
}
else 
# 113 "/home/claude/cfront-3/src/expr3.cpp"
if (gtbl == __1tbl ){ 
# 114 "/home/claude/cfront-3/src/expr3.cpp"
__1tmpx -> n_sto__4name = 31 ;
}

# 118 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __1tmp ;

# 118 "/home/claude/cfront-3/src/expr3.cpp"
__1tmp = dcl__4nameFP5tableUc ( __1tmpx , __1tbl , __1scop ) ;
( (__1tmpx ?(((void )(__1tmpx ?(((void )( ( ((((struct expr *)__1tmpx ))?(((void )((((struct expr *)__1tmpx ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 119 "/home/claude/cfront-3/src/expr3.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1tmpx , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 122 "/home/claude/cfront-3/src/expr3.cpp"
__1tmp -> n_scope__4name = ((__1scop == 136 )?108 :137 );
return __1tmp ;

# 123 "/home/claude/cfront-3/src/expr3.cpp"
}

# 123 "/home/claude/cfront-3/src/expr3.cpp"
}

# 123 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 468 "/home/claude/cfront-3/src/cfront.h"

# 803 "/home/claude/cfront-3/src/cfront.h"
Pexpr address__4exprFv (struct expr *__0this );

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 1228 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr call_ctor__FP5tableP4exprN22iT2 (Ptable , Pexpr __0p , Pexpr __0ctor , Pexpr __0args , int __0d , Pexpr __0vb_args );

# 359 "/home/claude/cfront-3/src/cfront.h"
Pfct memptr__4typeFv (struct type *__0this );

# 1249 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr mptr_assign__FP4exprT1 (Pexpr , Pexpr );

# 126 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr init_tmp__FP4nameP4exprP5table (Pname __1tmp , Pexpr __1init , Ptable __1tbl )
# 127 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 128 "/home/claude/cfront-3/src/expr3.cpp"
Pname __1cn ;
Pname __1ct ;

# 159 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __1ass ;

# 160 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__0__X47 ;

# 128 "/home/claude/cfront-3/src/expr3.cpp"
__1cn = is_cl_obj__4typeFv ( __1tmp -> __O1__4expr.tp ) ;
__1ct = (__1cn ?( (__0__X47 = (((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))))), ( __0__X47 -> c_itor__8classdef ) ) :(((struct name *)0 )));

# 131 "/home/claude/cfront-3/src/expr3.cpp"
__1tmp -> n_assigned_to__4name = 1 ;

# 133 "/home/claude/cfront-3/src/expr3.cpp"
if (__1ct ){ 
# 134 "/home/claude/cfront-3/src/expr3.cpp"
if (refd ){ 
# 136 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1init -> __O2__4expr.e1 -> base__4node ){ 
# 137 "/home/claude/cfront-3/src/expr3.cpp"
case 85 :
# 138 "/home/claude/cfront-3/src/expr3.cpp"
case 44 :
# 139 "/home/claude/cfront-3/src/expr3.cpp"
case 111 :
# 140 "/home/claude/cfront-3/src/expr3.cpp"
if (__1init -> base__4node ==
# 140 "/home/claude/cfront-3/src/expr3.cpp"
68 )
# 141 "/home/claude/cfront-3/src/expr3.cpp"
__1init = address__4exprFv ( __1init ) ;
else if (is_ptr__4typeFv ( __1init -> __O2__4expr.e1 -> __O1__4expr.tp ) )
# 143 "/home/claude/cfront-3/src/expr3.cpp"
__1init = __1init -> __O2__4expr.e1 ;
else 
# 145 "/home/claude/cfront-3/src/expr3.cpp"
__1init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __1init , address__4exprFv ( __1init -> __O2__4expr.e1 ) ) ;
# 145 "/home/claude/cfront-3/src/expr3.cpp"

# 147 "/home/claude/cfront-3/src/expr3.cpp"
}
if (__1ct -> __O1__4expr.tp -> base__4node == 76 )__1ct = (((struct gen *)(((struct gen *)__1ct -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list ;
__1tbl = 0 ;

# 151 "/home/claude/cfront-3/src/expr3.cpp"
if (__1ct -> n_dcl_printed__4name == 0 )dcl_print__4nameFUc ( __1ct , (unsigned char )0 ) ;
}
return call_ctor__FP5tableP4exprN22iT2 ( __1tbl , (struct expr *)__1tmp , (struct expr *)__1ct , __1init , 45 , (struct expr *)0 ) ;
}

# 156 "/home/claude/cfront-3/src/expr3.cpp"
if (ansi_opt )
# 157 "/home/claude/cfront-3/src/expr3.cpp"
__1tmp -> __O1__4expr.tp -> ansi_const__4type = 1 ;

# 159 "/home/claude/cfront-3/src/expr3.cpp"
;
if ((__1init -> base__4node == 86 )&& memptr__4typeFv ( __1tmp -> __O1__4expr.tp ) )
# 161 "/home/claude/cfront-3/src/expr3.cpp"
__1ass = mptr_assign__FP4exprT1 ( (struct expr *)__1tmp , __1init ) ;
else __1ass = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1tmp , __1init ) ;
__1ass -> __O1__4expr.tp = __1tmp -> __O1__4expr.tp ;
return __1ass ;
}

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 715 "/home/claude/cfront-3/src/cfront.h"

# 706 "/home/claude/cfront-3/src/cfront.h"

# 712 "/home/claude/cfront-3/src/cfront.h"

# 706 "/home/claude/cfront-3/src/cfront.h"

# 712 "/home/claude/cfront-3/src/cfront.h"

# 167 "/home/claude/cfront-3/src/expr3.cpp"
int exact3__FP4nameP4type (Pname __1nn , Ptype __1at )
# 172 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 173 "/home/claude/cfront-3/src/expr3.cpp"
if (__1nn == 0 )return 0 ;
{ Ptype __1nt ;

# 174 "/home/claude/cfront-3/src/expr3.cpp"
__1nt = skiptypedefs__4typeFv ( __1nn -> __O1__4expr.tp ) ;

# 176 "/home/claude/cfront-3/src/expr3.cpp"
if (__1at == __1nt )return 1 ;

# 178 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1nt -> base__4node ){ 
# 179 "/home/claude/cfront-3/src/expr3.cpp"
case 158 :
# 180 "/home/claude/cfront-3/src/expr3.cpp"
if ((__1nt -> base__4node == 158 )&& (check__4typeFP4typeUcT2 ( (((struct ptr *)(((struct ptr *)__1nt ))))-> typ__5pvtyp , __1at ,
# 180 "/home/claude/cfront-3/src/expr3.cpp"
(unsigned char )78 , (unsigned char )0 ) == 0 ))
# 181 "/home/claude/cfront-3/src/expr3.cpp"
return 1 ;
if ((__1at == (((struct type *)zero_type )))&& (is_ptr__4typeFv ( (((struct ptr *)(((struct ptr *)__1nt ))))-> typ__5pvtyp ) == 0 ))return 0 ;
if (check__4typeFP4typeUcT2 ( __1nt , __1at , (unsigned char )78 , (unsigned char )0 ) ){ 
# 184 "/home/claude/cfront-3/src/expr3.cpp"
Pptr __3pt ;

# 184 "/home/claude/cfront-3/src/expr3.cpp"
__3pt = ( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __1at ) ) ;
__1nt -> base__4node = 125 ;
if (check__4typeFP4typeUcT2 ( __1nt , (struct type *)__3pt , (unsigned char )78 , (unsigned char )0 ) ){ 
# 187 "/home/claude/cfront-3/src/expr3.cpp"
__1nt -> base__4node =
# 187 "/home/claude/cfront-3/src/expr3.cpp"
158 ;
( (__3pt ?(((void )(__3pt ?(((void )(((void )__dl__3ptrSFPvUl ( (void *)__3pt , (unsigned long )(sizeof (struct ptr))) )))):(((void )0 ))))):(((void )0 ))))
# 188 "/home/claude/cfront-3/src/expr3.cpp"
;
return 0 ;
}
__1nt -> base__4node = 158 ;
( (__3pt ?(((void )(__3pt ?(((void )(((void )__dl__3ptrSFPvUl ( (void *)__3pt , (unsigned long )(sizeof (struct ptr))) )))):(((void )0 ))))):(((void )0 ))))
# 192 "/home/claude/cfront-3/src/expr3.cpp"
;
}
break ;
default :
# 196 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1at -> base__4node ){ 
# 203 "/home/claude/cfront-3/src/expr3.cpp"
Plist __3gl ;
int __3no_match ;

# 197 "/home/claude/cfront-3/src/expr3.cpp"
default :
# 198 "/home/claude/cfront-3/src/expr3.cpp"
if (check__4typeFP4typeUcT2 ( __1nt , __1at , (unsigned char )78 , (unsigned char )0 ) )return 0 ;
break ;
case 76 :
# 203 "/home/claude/cfront-3/src/expr3.cpp"
;
__3no_match = 1 ;

# 206 "/home/claude/cfront-3/src/expr3.cpp"
for(__3gl = (((struct gen *)(((struct gen *)__1at ))))-> fct_list__3gen ;__3gl ;__3gl = __3gl -> l__9name_list ) { 
# 207 "/home/claude/cfront-3/src/expr3.cpp"
if (check__4typeFP4typeUcT2 ( __1nt , __3gl -> f__9name_list -> __O1__4expr.tp ,
# 207 "/home/claude/cfront-3/src/expr3.cpp"
(unsigned char )78 , (unsigned char )0 ) == 0 ){ 
# 208 "/home/claude/cfront-3/src/expr3.cpp"
__3no_match = 0 ;
break ;
}
}

# 213 "/home/claude/cfront-3/src/expr3.cpp"
if (__3no_match )return 0 ;
}
}
return 1 ;

# 216 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 219 "/home/claude/cfront-3/src/expr3.cpp"
int exact1__FP4nameP4type (Pname __1nn , Ptype __1at )
# 229 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 230 "/home/claude/cfront-3/src/expr3.cpp"
if (__1nn == 0 )return 0 ;
{ Ptype __1nt ;

# 231 "/home/claude/cfront-3/src/expr3.cpp"
__1nt = skiptypedefs__4typeFv ( __1nn -> __O1__4expr.tp ) ;
if (__1at == __1nt )return 1 ;
if (__1at -> base__4node == 138 )__1at = (struct type *)int_type ;

# 237 "/home/claude/cfront-3/src/expr3.cpp"
if (__1at -> base__4node == 76 ){ 
# 238 "/home/claude/cfront-3/src/expr3.cpp"
Plist __2gl ;

# 240 "/home/claude/cfront-3/src/expr3.cpp"
for(__2gl = (((struct gen *)(((struct gen *)__1at ))))-> fct_list__3gen ;__2gl ;__2gl = __2gl -> l__9name_list ) { 
# 241 "/home/claude/cfront-3/src/expr3.cpp"
if (check__4typeFP4typeUcT2 ( __1nt , __2gl -> f__9name_list -> __O1__4expr.tp ,
# 241 "/home/claude/cfront-3/src/expr3.cpp"
(unsigned char )0 , (unsigned char )0 ) == 0 ){ 
# 242 "/home/claude/cfront-3/src/expr3.cpp"
return 1 ;
}
}
return 0 ;
}

# 248 "/home/claude/cfront-3/src/expr3.cpp"
{ Pptr __1rt ;
Pptr __1art ;

# 248 "/home/claude/cfront-3/src/expr3.cpp"
__1rt = is_ptr__4typeFv ( __1nt ) ;
__1art = is_ptr__4typeFv ( __1at ) ;

# 251 "/home/claude/cfront-3/src/expr3.cpp"
if (check__4typeFP4typeUcT2 ( __1nt , __1at , (unsigned char )0 , (unsigned char )0 ) ){ 
# 253 "/home/claude/cfront-3/src/expr3.cpp"
if (const_problem && (__1nt ->
# 253 "/home/claude/cfront-3/src/expr3.cpp"
base__4node != 125 ))return 1 ;

# 256 "/home/claude/cfront-3/src/expr3.cpp"
if ((__1rt && __1rt -> memof__3ptr )|| (__1art && __1art -> memof__3ptr ))return 0 ;

# 258 "/home/claude/cfront-3/src/expr3.cpp"
__1rt = is_ref__4typeFv ( __1nt ) ;
if (__1rt && ((check__4typeFP4typeUcT2 ( __1at , (((struct ptr *)(((struct ptr *)__1rt ))))-> typ__5pvtyp , (unsigned char )0 , (unsigned char )0 )
# 259 "/home/claude/cfront-3/src/expr3.cpp"
== 0 )|| const_problem ))
# 260 "/home/claude/cfront-3/src/expr3.cpp"
return 1 ;

# 262 "/home/claude/cfront-3/src/expr3.cpp"
if (__1rt && __1art )return 0 ;

# 266 "/home/claude/cfront-3/src/expr3.cpp"
if (__1rt || (__1rt = is_ptr__4typeFv ( __1nt ) )){ 
# 267 "/home/claude/cfront-3/src/expr3.cpp"
if (__1art == 0 )__1art = is_ref__4typeFv ( __1at ) ;
if (__1art ){ 
# 269 "/home/claude/cfront-3/src/expr3.cpp"
if (check__4typeFP4typeUcT2 ( __1art -> typ__5pvtyp , __1rt -> typ__5pvtyp , (unsigned char )0 , (unsigned char )0 )
# 269 "/home/claude/cfront-3/src/expr3.cpp"
){ 
# 270 "/home/claude/cfront-3/src/expr3.cpp"
if (const_problem && ((((struct basetype *)(((struct basetype *)__1art -> typ__5pvtyp ))))-> b_const__4type != 1 ))
# 272 "/home/claude/cfront-3/src/expr3.cpp"
return 1 ;
}
else 
# 275 "/home/claude/cfront-3/src/expr3.cpp"
return 1 ;
}
}
return 0 ;
}
return 1 ;

# 280 "/home/claude/cfront-3/src/expr3.cpp"
}

# 280 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 283 "/home/claude/cfront-3/src/expr3.cpp"
int exact2__FP4nameP4type (Pname __1nn , Ptype __1at )
# 288 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 290 "/home/claude/cfront-3/src/expr3.cpp"
__1at = skiptypedefs__4typeFv ( __1at ) ;
switch (__1at -> base__4node ){ 
# 292 "/home/claude/cfront-3/src/expr3.cpp"
case 121 :
# 293 "/home/claude/cfront-3/src/expr3.cpp"
__1at = (struct type *)(((struct enumdef *)(((struct enumdef *)(((struct basetype *)(((struct basetype *)__1at ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> e_type__7enumdef ;
# 293 "/home/claude/cfront-3/src/expr3.cpp"

# 294 "/home/claude/cfront-3/src/expr3.cpp"
break ;
case 138 :
# 296 "/home/claude/cfront-3/src/expr3.cpp"
__1at = (struct type *)int_type ;
break ;
case 5 :
# 299 "/home/claude/cfront-3/src/expr3.cpp"
case 29 :
# 304 "/home/claude/cfront-3/src/expr3.cpp"
__1at = (struct type *)(((((struct basetype *)(((struct basetype *)__1at ))))-> b_unsigned__8basetype && (tsizeof__4typeFi ( __1at , 0 ) == SZ_INT ))?uint_type :int_type );
break ;
case 15 :
# 307 "/home/claude/cfront-3/src/expr3.cpp"
__1at = (struct type *)double_type ;
}

# 310 "/home/claude/cfront-3/src/expr3.cpp"
if (__1nn == 0 )return 0 ;
return exact1__FP4nameP4type ( __1nn , __1at ) ;
}

# 314 "/home/claude/cfront-3/src/expr3.cpp"
Pname Ncoerce = 0 ;
static int ref_cast ;
int Nstd = 0 ;

# 715 "/home/claude/cfront-3/src/cfront.h"

# 318 "/home/claude/cfront-3/src/expr3.cpp"
bit can_coerce__FP4typeT1 (Ptype __1t1 , Ptype __1t2 );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 1288 "/home/claude/cfront-3/src/cfront.h"

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 39 "/home/claude/cfront-3/src/overload.h"

# 47 "/home/claude/cfront-3/src/overload.h"
extern void best_conv__FRC11Block_PnameRiUc (struct Bits *__0_result , const struct Block_Pname *, int *, bit );

# 39 "/home/claude/cfront-3/src/overload.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 318 "/home/claude/cfront-3/src/expr3.cpp"
bit can_coerce__FP4typeT1 (Ptype __1t1 , Ptype __1t2 )
# 323 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 324 "/home/claude/cfront-3/src/expr3.cpp"
int __1zz ;

# 324 "/home/claude/cfront-3/src/expr3.cpp"
__1zz = 0 ;
Ncoerce = 0 ;
no_const = 0 ;
if (__1t2 -> base__4node == 141 )return (unsigned char )0 ;

# 329 "/home/claude/cfront-3/src/expr3.cpp"
if (! check__4typeFP4typeUcT2 ( __1t1 , __1t2 , (unsigned char )78 , (unsigned char )0 ) )
# 330 "/home/claude/cfront-3/src/expr3.cpp"
return (unsigned char
# 330 "/home/claude/cfront-3/src/expr3.cpp"
)1 ;

# 334 "/home/claude/cfront-3/src/expr3.cpp"
if (is_ref__4typeFv ( __1t1 ) ){ 
# 334 "/home/claude/cfront-3/src/expr3.cpp"
struct type *__0__X50 ;

# 335 "/home/claude/cfront-3/src/expr3.cpp"
if (check__4typeFP4typeUcT2 ( __1t1 , (struct type *)( (__0__X50 = skiptypedefs__4typeFv ( __1t2 ) ), ( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned
# 335 "/home/claude/cfront-3/src/expr3.cpp"
char )125 , __0__X50 ) ) ) , (unsigned char )78 , (unsigned char )0 ) == 0 )
# 336 "/home/claude/cfront-3/src/expr3.cpp"
return
# 336 "/home/claude/cfront-3/src/expr3.cpp"
(unsigned char )1 ;

# 338 "/home/claude/cfront-3/src/expr3.cpp"
if (! ref_cast ){ 
# 340 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __3tt1 ;
int __3bc ;

# 340 "/home/claude/cfront-3/src/expr3.cpp"
__3tt1 = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv ( __1t1 ) ))))-> typ__5pvtyp ) ;

# 342 "/home/claude/cfront-3/src/expr3.cpp"
if ((__3tt1 -> base__4node != 125 )&& (__3tt1 -> base__4node != 158 )){ 
# 343 "/home/claude/cfront-3/src/expr3.cpp"
__3bc = (((struct basetype *)(((struct basetype *)__3tt1 ))))-> b_const__4type ;
(((struct basetype *)(((struct basetype *)__3tt1 ))))-> b_const__4type = 0 ;
}
{ int __3i ;

# 346 "/home/claude/cfront-3/src/expr3.cpp"
__3i = can_coerce__FP4typeT1 ( __3tt1 , __1t2 ) ;
if ((__3tt1 -> base__4node != 125 )&& (__3tt1 -> base__4node != 158 ))
# 348 "/home/claude/cfront-3/src/expr3.cpp"
(((struct basetype *)(((struct basetype *)__3tt1 ))))-> b_const__4type = __3bc ;
if (__3i )return (unsigned char )__3i ;
__1zz = 1 ;

# 350 "/home/claude/cfront-3/src/expr3.cpp"
}
}
}

# 354 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __1c1 ;
Pname __1c2 ;
int __1val ;

# 357 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__0__X58 ;

# 354 "/home/claude/cfront-3/src/expr3.cpp"
__1c1 = is_cl_obj__4typeFv ( __1t1 ) ;
__1c2 = is_cl_obj__4typeFv ( __1t2 ) ;
__1val = 0 ;
if ((__1c1 && (! ref_cast ))&& (! __1zz )){ 
# 358 "/home/claude/cfront-3/src/expr3.cpp"
Pclass __2cl ;

# 359 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X51 ;

# 359 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X52 ;

# 359 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X53 ;

# 359 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X54 ;

# 358 "/home/claude/cfront-3/src/expr3.cpp"
__2cl = (((struct classdef *)(((struct classdef *)__1c1 -> __O1__4expr.tp ))));
if (__1c2 && ( (__1__X51 = (((struct classdef *)(((struct classdef *)__1c2 -> __O1__4expr.tp ))))), ( (__1__X52 = __2cl ), ( ((__1__X51 == __1__X52 )?1 :((__1__X51 &&
# 359 "/home/claude/cfront-3/src/expr3.cpp"
__1__X52 )?(((int )same_class__8classdefFP8classdefi ( __1__X51 , __1__X52 , 0 ) )):0 ))) ) ) )return (unsigned char )1 ;

# 362 "/home/claude/cfront-3/src/expr3.cpp"
if (__1c2 && ( (__1__X53 = (((struct classdef *)(((struct classdef *)__1c1 -> __O1__4expr.tp ))))), ( (__1__X54 = (((struct classdef *)(((struct classdef *)__1c2 -> __O1__4expr.tp ))))),
# 362 "/home/claude/cfront-3/src/expr3.cpp"
( ((__1__X53 == __1__X54 )?1 :((__1__X53 && __1__X54 )?(((int )same_class__8classdefFP8classdefi ( __1__X53 , __1__X54 , 0 ) )):0 ))) ) ) )
# 363 "/home/claude/cfront-3/src/expr3.cpp"
return (unsigned char
# 363 "/home/claude/cfront-3/src/expr3.cpp"
)1 ;

# 369 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __2ctor ;
Pfct __2f ;

# 369 "/home/claude/cfront-3/src/expr3.cpp"
__2ctor = ( __2cl -> c_ctor__8classdef ) ;
__2f = (__2ctor ?(((struct fct *)(((struct fct *)__2ctor -> __O1__4expr.tp )))):(((struct fct *)0 )));

# 372 "/home/claude/cfront-3/src/expr3.cpp"
if (__2f && (__2f -> base__4node == 108 )){ 
# 373 "/home/claude/cfront-3/src/expr3.cpp"
if ((__2f -> nargs__3fct == 1 )|| ((__2f -> nargs__3fct > 1 )&& __2f -> argtype__3fct ->
# 373 "/home/claude/cfront-3/src/expr3.cpp"
__O1__4name.n_list -> __O3__4expr.n_initializer ))
# 376 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 377 "/home/claude/cfront-3/src/expr3.cpp"
if (exact3__FP4nameP4type ( __2f -> argtype__3fct , __1t2 ) ){ 
# 378 "/home/claude/cfront-3/src/expr3.cpp"
__1val = 1 ;
}
}
}
else if (__2f && (__2f -> base__4node == 76 )){ 
# 383 "/home/claude/cfront-3/src/expr3.cpp"
Plist __3gl ;

# 385 "/home/claude/cfront-3/src/expr3.cpp"
for(__3gl = (((struct gen *)(((struct gen *)__2f ))))-> fct_list__3gen ;__3gl ;__3gl = __3gl -> l__9name_list ) { 
# 386 "/home/claude/cfront-3/src/expr3.cpp"
Pname __4nn ;
Pfct __4ff ;

# 386 "/home/claude/cfront-3/src/expr3.cpp"
__4nn = __3gl -> f__9name_list ;
__4ff = (((struct fct *)(((struct fct *)__4nn -> __O1__4expr.tp ))));

# 389 "/home/claude/cfront-3/src/expr3.cpp"
if ((__4ff -> nargs__3fct == 1 )|| ((__4ff -> nargs__3fct > 1 )&& __4ff -> argtype__3fct -> __O1__4name.n_list -> __O3__4expr.n_initializer ))
# 394 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 395 "/home/claude/cfront-3/src/expr3.cpp"
if (exact3__FP4nameP4type ( __4ff ->
# 395 "/home/claude/cfront-3/src/expr3.cpp"
argtype__3fct , __1t2 ) ){ 
# 396 "/home/claude/cfront-3/src/expr3.cpp"
__1val = 1 ;
break ;
}
}
}
}
else if (__2f ){ 
# 402 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X55 ;

# 403 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 403 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V48 ;

# 403 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"cannot_coerce(%k)\n", (const struct ea *)( (__2__X55 =
# 403 "/home/claude/cfront-3/src/expr3.cpp"
__2f -> base__4node ), ( (( ((& __0__V48 )-> __O1__2ea.i = __2__X55 ), 0 ) ), (& __0__V48 )) ) ,
# 403 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 404 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 407 "/home/claude/cfront-3/src/expr3.cpp"
if (__1c2 ){ 
# 408 "/home/claude/cfront-3/src/expr3.cpp"

# 409 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Pname __2conv ;
int __2found ;
Pclass __2cl ;
int __2best ;

# 409 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __2conv )-> n__11Block_Pname = 0 ), ((& __2conv )-> p__11Block_Pname = 0 )) ), (& __2conv )) ;
# 409 "/home/claude/cfront-3/src/expr3.cpp"

# 410 "/home/claude/cfront-3/src/expr3.cpp"
__2found = 0 ;
__2cl = (((struct classdef *)(((struct classdef *)__1c2 -> __O1__4expr.tp ))));
__2best = 0 ;
{ { Pname __2ox ;

# 413 "/home/claude/cfront-3/src/expr3.cpp"
Pname __2on ;

# 413 "/home/claude/cfront-3/src/expr3.cpp"
__2on = __2cl -> conv__8classdef ;

# 413 "/home/claude/cfront-3/src/expr3.cpp"
for(;__2on ;__2on = __2ox ) { 
# 414 "/home/claude/cfront-3/src/expr3.cpp"
__2ox = __2on -> __O1__4name.n_list ;
{ Pfct __3f ;

# 417 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __3rt ;
Pptr __3rr ;

# 415 "/home/claude/cfront-3/src/expr3.cpp"
__3f = ( ((__2on -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__2on -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__2on -> __O1__4expr.tp ))))->
# 415 "/home/claude/cfront-3/src/expr3.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) ;

# 417 "/home/claude/cfront-3/src/expr3.cpp"
__3rt = __3f -> returns__3fct ;
__3rr = is_ref__4typeFv ( __3rt ) ;
if (__3rr && (! is_ref__4typeFv ( __1t1 ) ))__3rt = __3rr -> typ__5pvtyp ;
Nstd = 0 ;
{ int __3howgood ;

# 422 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X56 ;

# 421 "/home/claude/cfront-3/src/expr3.cpp"
__3howgood = 0 ;
if (check__4typeFP4typeUcT2 ( __1t1 , __3rt , (unsigned char )0 , (unsigned char )0 ) == 0 ){ 
# 423 "/home/claude/cfront-3/src/expr3.cpp"
__3howgood = 6;
# 423 "/home/claude/cfront-3/src/expr3.cpp"

# 424 "/home/claude/cfront-3/src/expr3.cpp"
}
else if (check__4typeFP4typeUcT2 ( __1t1 , __3rt , (unsigned char )78 , (unsigned char )0 ) == 0 ){ 
# 426 "/home/claude/cfront-3/src/expr3.cpp"
if
# 426 "/home/claude/cfront-3/src/expr3.cpp"
(! Nstd )__3howgood = 5;
else { 
# 428 "/home/claude/cfront-3/src/expr3.cpp"
Pname __5t_nn ;

# 428 "/home/claude/cfront-3/src/expr3.cpp"
__5t_nn = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__5t_nn -> __O1__4expr.tp = skiptypedefs__4typeFv ( __1t1 ) ;
if (exact2__FP4nameP4type ( __5t_nn , __3rt ) )__3howgood = 4;
else __3howgood = 3;
}
}

# 435 "/home/claude/cfront-3/src/expr3.cpp"
if (tconst__4typeFv ( __1t2 ) && (__3f -> f_const__3fct == 0 )){ 
# 436 "/home/claude/cfront-3/src/expr3.cpp"
if (__3howgood )no_const ++ ;
continue ;
}
if ((__3howgood == 0 )|| (__3howgood < __2best ))continue ;
if (__3howgood > __2best ){ __2found = 0 ;

# 440 "/home/claude/cfront-3/src/expr3.cpp"
__2best = __3howgood ;

# 440 "/home/claude/cfront-3/src/expr3.cpp"
}
( move__11Block_PnameFPP4nameUl ( (& __2conv ), (Pname *)(((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* ((unsigned long )(__2found +
# 441 "/home/claude/cfront-3/src/expr3.cpp"
1 )))) )), ((unsigned long )(__2found + 1 ))) , (& __2conv )-> n__11Block_Pname ) ;
((*( (__2__X56 = (__2found ++ )), ( (((Pname *)(& ((& __2conv )-> p__11Block_Pname [__2__X56 ]))))) ) ))= __2on ;

# 442 "/home/claude/cfront-3/src/expr3.cpp"
}

# 442 "/home/claude/cfront-3/src/expr3.cpp"
}
}
if (__2found ){ 
# 445 "/home/claude/cfront-3/src/expr3.cpp"
if (__2found == 1 )Ncoerce = ((*( (((Pname *)(& ((& __2conv )-> p__11Block_Pname [0 ]))))) ));
else { 
# 447 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits __4b ;

# 448 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 448 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X57 ;

# 447 "/home/claude/cfront-3/src/expr3.cpp"
best_conv__FRC11Block_PnameRiUc ( & __4b , (const struct Block_Pname *)(& __2conv ), (int *)(& __2found ), tconst__4typeFv ( __1t1 ) ) ;
# 447 "/home/claude/cfront-3/src/expr3.cpp"

# 448 "/home/claude/cfront-3/src/expr3.cpp"
Ncoerce = ((*( (__2__X57 = (signif__4BitsCFv ( (const struct Bits *)(& __4b )) - 1 )), ( (((Pname *)(& ((& __2conv )->
# 448 "/home/claude/cfront-3/src/expr3.cpp"
p__11Block_Pname [__2__X57 ]))))) ) ));

# 448 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __4b )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 448 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 448 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
}
__1val = (__1val + __2found );
}

# 451 "/home/claude/cfront-3/src/expr3.cpp"
}

# 451 "/home/claude/cfront-3/src/expr3.cpp"
}

# 451 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __2conv )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 451 "/home/claude/cfront-3/src/expr3.cpp"

# 452 "/home/claude/cfront-3/src/expr3.cpp"
}
if (__1val )return (unsigned char )__1val ;
if (__1c1 && ( (__0__X58 = (((struct classdef *)(((struct classdef *)__1c1 -> __O1__4expr.tp ))))), ( __0__X58 -> c_itor__8classdef ) ) )return (unsigned
# 454 "/home/claude/cfront-3/src/expr3.cpp"
char )0 ;
if (check__4typeFP4typeUcT2 ( __1t1 , __1t2 , (unsigned char )78 , (unsigned char )0 ) )return (unsigned char )0 ;
# 455 "/home/claude/cfront-3/src/expr3.cpp"

# 456 "/home/claude/cfront-3/src/expr3.cpp"
return (unsigned char )1 ;

# 456 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 952 "/home/claude/cfront-3/src/cfront.h"

# 37 "/home/claude/cfront-3/src/overload.h"

# 459 "/home/claude/cfront-3/src/expr3.cpp"
int matchable__FP4nameP4expri (Pname __1n , Pexpr __1arg , int __1constObj )
# 464 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 465 "/home/claude/cfront-3/src/expr3.cpp"
Pfct __1f ;
Pexpr __1e ;
Pname __1nn ;
int __1worst ;

# 469 "/home/claude/cfront-3/src/expr3.cpp"
int __1__X62 ;

# 469 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 469 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 469 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 465 "/home/claude/cfront-3/src/expr3.cpp"
__1f = ( ((__1n -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 465 "/home/claude/cfront-3/src/expr3.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__1n )),
# 465 "/home/claude/cfront-3/src/expr3.cpp"
(& __0__X__V1400qmhwx544vcnm )) , (const struct ea *)( (__2__X16 = __1n -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )->
# 465 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmhwx544vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 465 "/home/claude/cfront-3/src/expr3.cpp"
, (((struct fct *)0 ))) )) ;

# 468 "/home/claude/cfront-3/src/expr3.cpp"
__1worst = 5;

# 470 "/home/claude/cfront-3/src/expr3.cpp"
if (( __1n -> n_template_fct__4name ) )return 0 ;

# 472 "/home/claude/cfront-3/src/expr3.cpp"
if (((__1constObj && (__1n -> n_oper__4name != 161 ))&& (! __1f -> f_const__3fct ))&& (! __1f -> f_static__3fct )){ 
# 473 "/home/claude/cfront-3/src/expr3.cpp"
non_const ++ ;
return (int )0;
}

# 477 "/home/claude/cfront-3/src/expr3.cpp"
for(( (__1e = __1arg ), (__1nn = __1f -> argtype__3fct )) ;__1e ;( (__1e = __1e -> __O3__4expr.e2 ), (__1nn = __1nn -> __O1__4name.n_list )) )
# 477 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 478 "/home/claude/cfront-3/src/expr3.cpp"
if (__1nn == 0 )return (__1f -> nargs_known__3fct == 155 );
{ Pexpr __2a ;
Ptype __2at ;

# 479 "/home/claude/cfront-3/src/expr3.cpp"
__2a = __1e -> __O2__4expr.e1 ;
__2at = __2a -> __O1__4expr.tp ;
if (__2at -> base__4node == 141 )return (int )0;
if (exact1__FP4nameP4type ( __1nn , __2at ) ){ 
# 482 "/home/claude/cfront-3/src/expr3.cpp"
int __1__X59 ;

# 482 "/home/claude/cfront-3/src/expr3.cpp"
__1worst = ( (__1__X59 = 5), ( ((__1worst < __1__X59 )?__1worst :__1__X59 )) ) ;

# 482 "/home/claude/cfront-3/src/expr3.cpp"
continue ;

# 482 "/home/claude/cfront-3/src/expr3.cpp"
}
if (exact2__FP4nameP4type ( __1nn , __2at ) ){ 
# 483 "/home/claude/cfront-3/src/expr3.cpp"
int __1__X60 ;

# 483 "/home/claude/cfront-3/src/expr3.cpp"
__1worst = ( (__1__X60 = 4), ( ((__1worst < __1__X60 )?__1worst :__1__X60 )) ) ;

# 483 "/home/claude/cfront-3/src/expr3.cpp"
continue ;

# 483 "/home/claude/cfront-3/src/expr3.cpp"
}
if (exact3__FP4nameP4type ( __1nn , __2at ) ){ 
# 484 "/home/claude/cfront-3/src/expr3.cpp"
int __1__X61 ;

# 484 "/home/claude/cfront-3/src/expr3.cpp"
__1worst = ( (__1__X61 = 3), ( ((__1worst < __1__X61 )?__1worst :__1__X61 )) ) ;

# 484 "/home/claude/cfront-3/src/expr3.cpp"
continue ;

# 484 "/home/claude/cfront-3/src/expr3.cpp"
}
{ int __2cc ;

# 485 "/home/claude/cfront-3/src/expr3.cpp"
__2cc = can_coerce__FP4typeT1 ( __1nn -> __O1__4expr.tp , __2at ) ;
if (__2cc != 1 )return (int )0;
else __1worst = 2;

# 487 "/home/claude/cfront-3/src/expr3.cpp"
}

# 487 "/home/claude/cfront-3/src/expr3.cpp"
}
}
if (__1nn && (__1nn -> __O3__4expr.n_initializer == 0 ))return (int )0;
return ( (__1__X62 = 5), ( ((__1worst < __1__X62 )?__1worst :__1__X62 )) ) ;
}

# 493 "/home/claude/cfront-3/src/expr3.cpp"
int is_arg = 0 ;

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 848 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 671 "/home/claude/cfront-3/src/cfront.h"
Pname exactMatch__3genFP4expri (struct gen *__0this , Pexpr , int );

# 674 "/home/claude/cfront-3/src/cfront.h"

# 239 "/home/claude/cfront-3/src/template.h"
extern Pname has_templ_instance__FP4nameP4exprUc (Pname , Pexpr , bit );

# 672 "/home/claude/cfront-3/src/cfront.h"
Pname oneArgMatch__3genFP4expri (struct gen *__0this , Pexpr , int );
Pname multArgMatch__3genFP4expri (struct gen *__0this , Pexpr , int );

# 39 "/home/claude/cfront-3/src/overload.h"

# 49 "/home/claude/cfront-3/src/overload.h"
extern void fmError__FiRC11Block_PnameP4exprUc (int , const struct Block_Pname *, Pexpr , bit );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 952 "/home/claude/cfront-3/src/cfront.h"

# 1230 "/home/claude/cfront-3/src/cfront.h"
extern void check_visibility__FP4nameT1P8classdefP5tableT1 (Pname , Pname , Pclass , Ptable , Pname );

# 1224 "/home/claude/cfront-3/src/cfront.h"
extern void make_res__FP3fct (Pfct );

# 753 "/home/claude/cfront-3/src/expr3.cpp"
extern void uninline__FP4name (Pname __3fn );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 942 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 738 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ref_init__FP3ptrP4exprP5table (Pptr , Pexpr , Ptable );
extern Pexpr class_init__FP4exprP4typeT1P5table (Pexpr , Ptype , Pexpr , Ptable );

# 468 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 1227 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ptr_init__FP3ptrP4exprP5table (Pptr , Pexpr , Ptable );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 1155 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr try_to_coerce__FP4typeP4exprPCcP5table (Ptype , Pexpr , const char *, Ptable );

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

# 801 "/home/claude/cfront-3/src/cfront.h"
int lval__4exprFUc (struct expr *__0this , TOK );

# 466 "/home/claude/cfront-3/src/cfront.h"

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 804 "/home/claude/cfront-3/src/cfront.h"
Pexpr contents__4exprFv (struct expr *__0this );

# 828 "/home/claude/cfront-3/src/cfront.h"

# 943 "/home/claude/cfront-3/src/cfront.h"
void assign__4nameFv (struct name *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 495 "/home/claude/cfront-3/src/expr3.cpp"
Ptype call_fct__4exprFP5table (register struct expr *__0this , Ptable __1tbl )
# 501 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 502 "/home/claude/cfront-3/src/expr3.cpp"
Pfct __1f ;
Pname __1fn ;
int __1x ;
int __1k ;
Pname __1nn ;
Pexpr __1e ;
Ptype __1t ;
Pexpr __1arg ;
Ptype __1t1 ;

# 512 "/home/claude/cfront-3/src/expr3.cpp"
int __1argno ;
Pexpr __1etail ;
bit __1no_change ;
Pname __1no_virt ;
Pname __1chk ;

# 519 "/home/claude/cfront-3/src/expr3.cpp"
int __1const_obj ;

# 520 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X112 ;

# 520 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X113 ;

# 509 "/home/claude/cfront-3/src/expr3.cpp"
__1arg = __0this -> __O3__4expr.e2 ;
__1t1 = (__0this -> __O2__4expr.e1 ?__0this -> __O2__4expr.e1 -> __O1__4expr.tp :(((struct type *)0 )));
ambig = 0 ;
;
__1etail = 0 ;
__1no_change = 0 ;
__1no_virt = 0 ;
__1chk = 0 ;

# 519 "/home/claude/cfront-3/src/expr3.cpp"
__1const_obj = 0 ;

# 521 "/home/claude/cfront-3/src/expr3.cpp"
if (__1t1 == (((struct type *)any_type )))return (struct type *)any_type ;

# 523 "/home/claude/cfront-3/src/expr3.cpp"
switch (__0this -> base__4node ){ 
# 523 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X111 ;

# 524 "/home/claude/cfront-3/src/expr3.cpp"
case 109 :
# 525 "/home/claude/cfront-3/src/expr3.cpp"
case 146 :break ;
default :{ 
# 526 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V63 ;

# 526 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"call_fct(%k)", (const struct ea *)( (__2__X111 =
# 526 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> base__4node ), ( (( ((& __0__V63 )-> __O1__2ea.i = __2__X111 ), 0 ) ), (& __0__V63 )) ) ,
# 526 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 530 "/home/claude/cfront-3/src/expr3.cpp"
if (__1t1 == 0 ){ 
# 530 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V64 ;

# 530 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V65 ;

# 530 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"call_fct(e1=%d,e1->tp=%t)", (const struct ea *)( (__2__X112 =
# 530 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)__0this -> __O2__4expr.e1 ), ( ((& __0__V64 )-> __O1__2ea.p = __2__X112 ), (& __0__V64 )) ) , (const
# 530 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)( ((& __0__V65 )-> __O1__2ea.p = ((const void *)__1t1 )), (& __0__V65 )) , (const struct ea *)ea0 ,
# 530 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 ) ;
} if (__1arg && (__1arg -> base__4node != 140 )){ 
# 531 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V66 ;

# 531 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V67 ;

# 531 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"badAL%d%k", (const struct ea *)( ((&
# 531 "/home/claude/cfront-3/src/expr3.cpp"
__0__V66 )-> __O1__2ea.p = ((const void *)__1arg )), (& __0__V66 )) , (const struct ea *)( (__2__X113 = __1arg -> base__4node ),
# 531 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __0__V67 )-> __O1__2ea.i = __2__X113 ), 0 ) ), (& __0__V67 )) ) , (const struct
# 531 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 533 "/home/claude/cfront-3/src/expr3.cpp"
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 534 "/home/claude/cfront-3/src/expr3.cpp"
case 162 :
# 535 "/home/claude/cfront-3/src/expr3.cpp"
__1fn = (((struct name *)(((struct name *)__0this -> __O2__4expr.e1 ))));
break ;
case 85 :
# 538 "/home/claude/cfront-3/src/expr3.cpp"
__1fn = (((struct name *)(((struct name *)__0this -> __O2__4expr.e1 ))));
switch (__1fn -> n_oper__4name ){ 
# 540 "/home/claude/cfront-3/src/expr3.cpp"
case 0 :
# 541 "/home/claude/cfront-3/src/expr3.cpp"
case 161 :
# 542 "/home/claude/cfront-3/src/expr3.cpp"
case 162 :
# 543 "/home/claude/cfront-3/src/expr3.cpp"
case 97 :
# 544 "/home/claude/cfront-3/src/expr3.cpp"
case 23 :
# 545 "/home/claude/cfront-3/src/expr3.cpp"
case 213 :
# 546 "/home/claude/cfront-3/src/expr3.cpp"
case 9 :
# 547 "/home/claude/cfront-3/src/expr3.cpp"
case 212 :
# 548 "/home/claude/cfront-3/src/expr3.cpp"
break ;
default :
# 550 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 551 "/home/claude/cfront-3/src/expr3.cpp"
if (__1arg == 0 )break ;
{ Pexpr __4a ;

# 553 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X114 ;

# 552 "/home/claude/cfront-3/src/expr3.cpp"
__4a = __1arg -> __O2__4expr.e1 ;

# 554 "/home/claude/cfront-3/src/expr3.cpp"
if (is_cl_obj__4typeFv ( __4a -> __O1__4expr.tp ) )break ;
if (is_ref__4typeFv ( __4a -> __O1__4expr.tp ) )break ;
__4a = __1arg -> __O3__4expr.e2 ;
if (__4a == 0 )
# 558 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 558 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V68 ;

# 558 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k of basicT", (const struct ea *)( (__2__X114 = __1fn -> n_oper__4name ),
# 558 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __0__V68 )-> __O1__2ea.i = __2__X114 ), 0 ) ), (& __0__V68 )) ) , (const struct
# 558 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 559 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X115 ;

# 560 "/home/claude/cfront-3/src/expr3.cpp"
__4a = __4a -> __O2__4expr.e1 ;
if (is_cl_obj__4typeFv ( __4a -> __O1__4expr.tp ) || is_ref__4typeFv ( __4a -> __O1__4expr.tp ) )break ;
{ 
# 562 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V69 ;

# 562 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k of basicTs", (const struct ea *)( (__2__X115 = __1fn -> n_oper__4name ),
# 562 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __0__V69 )-> __O1__2ea.i = __2__X115 ), 0 ) ), (& __0__V69 )) ) , (const struct
# 562 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
break ;

# 564 "/home/claude/cfront-3/src/expr3.cpp"
}
}
}
break ;
case 44 :
# 569 "/home/claude/cfront-3/src/expr3.cpp"
case 45 :
# 570 "/home/claude/cfront-3/src/expr3.cpp"
__1no_virt = (((struct name *)(((struct name *)__0this -> __O2__4expr.e1 -> __O3__4expr.n_initializer ))));
__0this -> __O2__4expr.e1 -> __O3__4expr.n_initializer = 0 ;
if (__0this -> __O2__4expr.e1 && __0this -> __O2__4expr.e1 -> __O2__4expr.e1 ){ 
# 573 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __3t ;
Pptr __3tt ;

# 573 "/home/claude/cfront-3/src/expr3.cpp"
__3t = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ;
__3tt = is_ref__4typeFv ( __3t ) ;
__3t = (__3tt ?__3tt -> typ__5pvtyp :__3t );
{ Pptr __3p_t ;

# 576 "/home/claude/cfront-3/src/expr3.cpp"
__3p_t = is_ptr__4typeFv ( __3t ) ;
__3t = (((__0this -> __O2__4expr.e1 -> base__4node == 44 )&& __3p_t )?__3p_t -> typ__5pvtyp :__3t );
__3tt = is_ref__4typeFv ( __3t ) ;
__3t = (__3tt ?__3tt -> typ__5pvtyp :__3t );
__1const_obj = tconst__4typeFv ( __3t ) ;

# 580 "/home/claude/cfront-3/src/expr3.cpp"
}
}
case 177 :
# 583 "/home/claude/cfront-3/src/expr3.cpp"
{ Pexpr __3n ;

# 583 "/home/claude/cfront-3/src/expr3.cpp"
__3n = __0this -> __O2__4expr.e1 -> __O4__4expr.mem ;
lxlx :
# 585 "/home/claude/cfront-3/src/expr3.cpp"
switch (__3n -> base__4node ){ 
# 585 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X118 ;

# 586 "/home/claude/cfront-3/src/expr3.cpp"
case 177 :
# 592 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 593 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __5r ;
Pexpr __5p ;

# 593 "/home/claude/cfront-3/src/expr3.cpp"
__5r = __0this -> __O2__4expr.e1 ;
__5p = __5r -> __O2__4expr.e1 ;
{ { Pexpr __5m ;

# 595 "/home/claude/cfront-3/src/expr3.cpp"
__5m = __5r -> __O4__4expr.mem ;

# 595 "/home/claude/cfront-3/src/expr3.cpp"
for(;__5m -> base__4node == 177 ;__5m = __5r -> __O4__4expr.mem ) { 
# 595 "/home/claude/cfront-3/src/expr3.cpp"
register struct mdot *__0__X116 ;

# 595 "/home/claude/cfront-3/src/expr3.cpp"
const char *__2__X117 ;

# 596 "/home/claude/cfront-3/src/expr3.cpp"
__5p = (struct expr *)( (__0__X116 = 0 ), ( (__2__X117 = __5m -> __O3__4expr.string2 ), ( ((__0__X116 || (__0__X116 = (struct mdot *)__nw__4exprSFUl (
# 596 "/home/claude/cfront-3/src/expr3.cpp"
(unsigned long )(sizeof (struct mdot))) ))?( (__0__X116 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X116 ), (unsigned char )177 , (struct
# 596 "/home/claude/cfront-3/src/expr3.cpp"
expr *)0 , (struct expr *)0 ) ), ( (__0__X116 -> __O3__4expr.string2 = __2__X117 ), (__0__X116 -> __O4__4expr.mem = __5p )) ) :0 ), __0__X116 )
# 596 "/home/claude/cfront-3/src/expr3.cpp"
) ) ;
__5p -> __O2__4expr.i1 = (__5m -> __O2__4expr.i1 + 2 );
if (__5p -> __O4__4expr.mem && ((((struct expr *)(((struct expr *)__5p -> __O4__4expr.mem ))))!= (((struct expr *)1 ))))
# 599 "/home/claude/cfront-3/src/expr3.cpp"
__5p -> __O1__4expr.tp = __5p -> __O4__4expr.mem -> __O1__4expr.tp ;
__5r -> __O4__4expr.mem = __5m -> __O4__4expr.mem ;
__5r -> __O2__4expr.e1 = __5p ;
}

# 602 "/home/claude/cfront-3/src/expr3.cpp"
}

# 602 "/home/claude/cfront-3/src/expr3.cpp"
}
}
case 44 :
# 605 "/home/claude/cfront-3/src/expr3.cpp"
case 45 :
# 606 "/home/claude/cfront-3/src/expr3.cpp"
__3n = __3n -> __O4__4expr.mem ;
goto lxlx ;
case 85 :
# 609 "/home/claude/cfront-3/src/expr3.cpp"
case 162 :
# 610 "/home/claude/cfront-3/src/expr3.cpp"
break ;
default :
# 612 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 612 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V70 ;

# 612 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"ref %k", (const struct ea *)( (__2__X118 =
# 612 "/home/claude/cfront-3/src/expr3.cpp"
__3n -> base__4node ), ( (( ((& __0__V70 )-> __O1__2ea.i = __2__X118 ), 0 ) ), (& __0__V70 )) ) ,
# 612 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
__1fn = (((struct name *)(((struct name *)__3n ))));
break ;
}
case 173 :
# 618 "/home/claude/cfront-3/src/expr3.cpp"
default :
# 619 "/home/claude/cfront-3/src/expr3.cpp"
__1fn = 0 ;
}

# 622 "/home/claude/cfront-3/src/expr3.cpp"
lll :
# 624 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1t1 -> base__4node ){ 
# 624 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X119 ;

# 624 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X120 ;

# 625 "/home/claude/cfront-3/src/expr3.cpp"
case 97 :
# 626 "/home/claude/cfront-3/src/expr3.cpp"
__1t1 = (((struct basetype *)(((struct basetype *)__1t1 ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto lll ;

# 629 "/home/claude/cfront-3/src/expr3.cpp"
case 125 :
# 630 "/home/claude/cfront-3/src/expr3.cpp"
switch (skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__1t1 ))))-> typ__5pvtyp ) -> base__4node ){ 
# 631 "/home/claude/cfront-3/src/expr3.cpp"
case 108 :
# 632 "/home/claude/cfront-3/src/expr3.cpp"
case 76 :
# 633 "/home/claude/cfront-3/src/expr3.cpp"
if ((((struct ptr *)(((struct
# 633 "/home/claude/cfront-3/src/expr3.cpp"
ptr *)__1t1 ))))-> memof__3ptr )error__FPCc ( (const char *)"O missing in call throughP toMF") ;
__1t1 = (((struct ptr *)(((struct ptr *)__1t1 ))))-> typ__5pvtyp ;
__1fn = 0 ;
goto lll ;
}

# 639 "/home/claude/cfront-3/src/expr3.cpp"
default :
# 640 "/home/claude/cfront-3/src/expr3.cpp"
if (__1fn )
# 641 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 641 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V71 ;

# 641 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V72 ;

# 641 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V73 ;

# 641 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"call of%n;%n is a%t", (const struct ea *)( ((& __0__V71 )-> __O1__2ea.p =
# 641 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1fn )), (& __0__V71 )) , (const struct ea *)( ((& __0__V72 )-> __O1__2ea.p = ((const void
# 641 "/home/claude/cfront-3/src/expr3.cpp"
*)__1fn )), (& __0__V72 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V73 , (const void *)__0this -> __O2__4expr.e1 -> __O1__4expr.tp )
# 641 "/home/claude/cfront-3/src/expr3.cpp"
, (const struct ea *)ea0 ) ;
} else 
# 643 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 643 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V74 ;

# 643 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V75 ;

# 643 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"call of%kE ofT%t", (const struct ea *)( (__2__X119 = __0this -> __O2__4expr.e1 ->
# 643 "/home/claude/cfront-3/src/expr3.cpp"
base__4node ), ( (( ((& __0__V74 )-> __O1__2ea.i = __2__X119 ), 0 ) ), (& __0__V74 )) ) , (const
# 643 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)( (__2__X120 = (const void *)__0this -> __O2__4expr.e1 -> __O1__4expr.tp ), ( ((& __0__V75 )-> __O1__2ea.p = __2__X120 ), (&
# 643 "/home/claude/cfront-3/src/expr3.cpp"
__0__V75 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 645 "/home/claude/cfront-3/src/expr3.cpp"
case 141 :
# 646 "/home/claude/cfront-3/src/expr3.cpp"
return (struct type *)any_type ;

# 648 "/home/claude/cfront-3/src/expr3.cpp"
case 76 :
# 649 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 650 "/home/claude/cfront-3/src/expr3.cpp"
Pgen __3g ;
Pname __3found ;

# 652 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 652 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 652 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 650 "/home/claude/cfront-3/src/expr3.cpp"
__3g = (((struct gen *)(((struct gen *)__1t1 ))));
__3found = 0 ;

# 654 "/home/claude/cfront-3/src/expr3.cpp"
__3found = exactMatch__3genFP4expri ( __3g , __1arg , __1const_obj ) ;

# 657 "/home/claude/cfront-3/src/expr3.cpp"
if (((! __3found )&& __1arg )&& ( (__3g -> holds_templ__3gen != 0)) ){ 
# 658 "/home/claude/cfront-3/src/expr3.cpp"
__3found = has_templ_instance__FP4nameP4exprUc ( __1fn , __1arg , (unsigned
# 658 "/home/claude/cfront-3/src/expr3.cpp"
char )0 ) ;
}

# 662 "/home/claude/cfront-3/src/expr3.cpp"
if (((! __3found )&& __1arg )&& (__1arg -> __O3__4expr.e2 == 0 )){ 
# 663 "/home/claude/cfront-3/src/expr3.cpp"
__3found = oneArgMatch__3genFP4expri ( __3g , __1arg , __1const_obj ) ;
}
else 
# 668 "/home/claude/cfront-3/src/expr3.cpp"
if ((! __3found )&& __1arg ){ 
# 669 "/home/claude/cfront-3/src/expr3.cpp"
__3found = multArgMatch__3genFP4expri ( __3g , __1arg , __1const_obj ) ;
}

# 673 "/home/claude/cfront-3/src/expr3.cpp"
if (! __3found ){ 
# 674 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Pname __4tmp ;

# 674 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __4tmp )-> n__11Block_Pname = 0 ), ( ((& __4tmp )-> p__11Block_Pname = 0 ), ( move__11Block_PnameFPP4nameUl ( (&
# 674 "/home/claude/cfront-3/src/expr3.cpp"
__4tmp ), (Pname *)(((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* ((unsigned long )1 ))) )), ((unsigned long
# 674 "/home/claude/cfront-3/src/expr3.cpp"
)1 )) , (& __4tmp )-> n__11Block_Pname ) ) ) ), (& __4tmp )) ;
((*( (((Pname *)(& ((& __4tmp )-> p__11Block_Pname [0 ]))))) ))= __1fn ;
fmError__FiRC11Block_PnameP4exprUc ( 0 , (const struct Block_Pname *)(& __4tmp ), __1arg , (unsigned char )__1const_obj ) ;
{ 
# 677 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __4tmp )-> p__11Block_Pname ) , (((void )(((void )0 ))))) )))
# 677 "/home/claude/cfront-3/src/expr3.cpp"
;

# 677 "/home/claude/cfront-3/src/expr3.cpp"
return (struct type *)any_type ;
} }

# 680 "/home/claude/cfront-3/src/expr3.cpp"
overFound = (__1chk = (__1fn = __3found ));
__1f = ( ((__1fn -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 681 "/home/claude/cfront-3/src/expr3.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__1fn )),
# 681 "/home/claude/cfront-3/src/expr3.cpp"
(& __0__X__V1400qmhwx544vcnm )) , (const struct ea *)( (__2__X16 = __1fn -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )->
# 681 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmhwx544vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 681 "/home/claude/cfront-3/src/expr3.cpp"
, (((struct fct *)0 ))) )) ;
break ;
}

# 685 "/home/claude/cfront-3/src/expr3.cpp"
case 108 :
# 686 "/home/claude/cfront-3/src/expr3.cpp"
__1f = (((struct fct *)(((struct fct *)__1t1 ))));
if (__1fn ){ 
# 688 "/home/claude/cfront-3/src/expr3.cpp"
if (( __1fn -> n_template_fct__4name ) ){ 
# 689 "/home/claude/cfront-3/src/expr3.cpp"
Pname __4f_inst ;

# 689 "/home/claude/cfront-3/src/expr3.cpp"
__4f_inst = has_templ_instance__FP4nameP4exprUc ( __1fn , __1arg , (unsigned char )0 ) ;
if (__4f_inst ){ 
# 691 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = (struct expr *)__4f_inst ;

# 691 "/home/claude/cfront-3/src/expr3.cpp"
__1fn = __4f_inst ;
__1t1 = __4f_inst -> __O1__4expr.tp ;

# 692 "/home/claude/cfront-3/src/expr3.cpp"
__1f = (((struct fct *)(((struct fct *)__4f_inst -> __O1__4expr.tp ))));
}
}
else 
# 696 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1fn -> n_oper__4name ){ 
# 697 "/home/claude/cfront-3/src/expr3.cpp"
case 161 :
# 698 "/home/claude/cfront-3/src/expr3.cpp"
case 97 :
# 699 "/home/claude/cfront-3/src/expr3.cpp"
__1chk = __1fn ;
}
}
}

# 704 "/home/claude/cfront-3/src/expr3.cpp"
if (__1chk ){ 
# 705 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __2t ;
Pexpr __2ee ;

# 705 "/home/claude/cfront-3/src/expr3.cpp"
__2t = 0 ;
__2ee = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 ;

# 708 "/home/claude/cfront-3/src/expr3.cpp"
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 709 "/home/claude/cfront-3/src/expr3.cpp"
case 44 :
# 710 "/home/claude/cfront-3/src/expr3.cpp"
if (__2ee == 0 ){ 
# 711 "/home/claude/cfront-3/src/expr3.cpp"
check_visibility__FP4nameT1P8classdefP5tableT1 ( __1chk , __1no_virt , ((struct classdef *)(((struct classdef *)__1chk ->
# 711 "/home/claude/cfront-3/src/expr3.cpp"
__O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))), __1tbl , cc -> nof__11dcl_context ) ;
break ;
}

# 713 "/home/claude/cfront-3/src/expr3.cpp"
;
__2t = skiptypedefs__4typeFv ( __2ee -> __O1__4expr.tp ) ;
__2t = (((struct ptr *)(((struct ptr *)__2t ))))-> typ__5pvtyp ;
break ;
case 45 :
# 718 "/home/claude/cfront-3/src/expr3.cpp"
__2t = __2ee -> __O1__4expr.tp ;
}

# 721 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __2cn ;
Pclass __2cl ;

# 721 "/home/claude/cfront-3/src/expr3.cpp"
__2cn = (__2t ?is_cl_obj__4typeFv ( __2t ) :(((struct name *)0 )));
__2cl = (__2cn ?(((struct classdef *)(((struct classdef *)__2cn -> __O1__4expr.tp )))):(((struct classdef *)0 )));

# 724 "/home/claude/cfront-3/src/expr3.cpp"
if (__2cl ){ 
# 725 "/home/claude/cfront-3/src/expr3.cpp"
if ((((__1chk -> n_oper__4name == 161 )&& __1chk -> n_protect__4name )&& cc -> nof__11dcl_context )&& (cc -> nof__11dcl_context -> n_oper__4name == 161 ))
# 731 "/home/claude/cfront-3/src/expr3.cpp"
;
# 731 "/home/claude/cfront-3/src/expr3.cpp"
else 
# 732 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 733 "/home/claude/cfront-3/src/expr3.cpp"
check_visibility__FP4nameT1P8classdefP5tableT1 ( __1chk , __1no_virt , __2cl , __1tbl , cc -> nof__11dcl_context ) ;
}
}

# 735 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 738 "/home/claude/cfront-3/src/expr3.cpp"
if ((__1fn && is_cl_obj__4typeFv ( __1f -> returns__3fct ) )&& (__1f -> f_result__3fct == 0 )){ 
# 740 "/home/claude/cfront-3/src/expr3.cpp"
make_res__FP3fct ( __1f ) ;
tsizeof__4typeFi ( __1f -> returns__3fct , 0 ) ;
}

# 745 "/home/claude/cfront-3/src/expr3.cpp"
if (__1fn ){ 
# 747 "/home/claude/cfront-3/src/expr3.cpp"
{ { Pname __2nn ;

# 747 "/home/claude/cfront-3/src/expr3.cpp"
__2nn = __1f -> argtype__3fct ;

# 747 "/home/claude/cfront-3/src/expr3.cpp"
for(;__2nn ;__2nn = __2nn -> __O1__4name.n_list ) 
# 748 "/home/claude/cfront-3/src/expr3.cpp"
if (is_cl_obj__4typeFv ( __2nn -> __O1__4expr.tp ) )((void )tsizeof__4typeFi ( __2nn -> __O1__4expr.tp , 0 ) );

# 748 "/home/claude/cfront-3/src/expr3.cpp"
}

# 748 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 751 "/home/claude/cfront-3/src/expr3.cpp"
if (__1fn && (__1fn -> n_dcl_printed__4name == 0 )){ 
# 752 "/home/claude/cfront-3/src/expr3.cpp"
if ((__1f -> f_inline__3fct == 0 )&& __1f -> f_imeasure__3fct ){ 
# 754 "/home/claude/cfront-3/src/expr3.cpp"
uninline__FP4name ( __1fn ) ;
# 754 "/home/claude/cfront-3/src/expr3.cpp"

# 755 "/home/claude/cfront-3/src/expr3.cpp"
}

# 761 "/home/claude/cfront-3/src/expr3.cpp"
dcl_print__4nameFUc ( __1fn , (unsigned char )0 ) ;
}

# 764 "/home/claude/cfront-3/src/expr3.cpp"
if (__1no_virt && (__1f -> f_static__3fct == 0 )){ 
# 765 "/home/claude/cfront-3/src/expr3.cpp"
if ((__0this -> __O2__4expr.e1 -> base__4node == 44 )|| (__0this -> __O2__4expr.e1 -> base__4node == 45 ))__0this ->
# 765 "/home/claude/cfront-3/src/expr3.cpp"
__O2__4expr.e1 -> __O3__4expr.n_initializer = (struct expr *)__1fn ;
}
else 
# 768 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O4__4expr.fct_name = __1fn ;

# 770 "/home/claude/cfront-3/src/expr3.cpp"
if (__1f -> f_this__3fct ){ 
# 771 "/home/claude/cfront-3/src/expr3.cpp"
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 771 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X121 ;

# 772 "/home/claude/cfront-3/src/expr3.cpp"
case 173 :
# 773 "/home/claude/cfront-3/src/expr3.cpp"
case 44 :
# 774 "/home/claude/cfront-3/src/expr3.cpp"
case 45 :
# 775 "/home/claude/cfront-3/src/expr3.cpp"
break ;
default :
# 777 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 777 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V76 ;

# 777 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V77 ;

# 777 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"O orP missing for%n ofT %t", (const struct ea *)( (__2__X121 = (const void
# 777 "/home/claude/cfront-3/src/expr3.cpp"
*)__0this -> __O4__4expr.fct_name ), ( ((& __0__V76 )-> __O1__2ea.p = __2__X121 ), (& __0__V76 )) ) , (const struct ea *)(
# 777 "/home/claude/cfront-3/src/expr3.cpp"
((& __0__V77 )-> __O1__2ea.p = ((const void *)__1f )), (& __0__V77 )) , (const struct ea *)ea0 , (const struct
# 777 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 ) ;
} }
}
else if (__1fn ){ 
# 781 "/home/claude/cfront-3/src/expr3.cpp"
sss :
# 782 "/home/claude/cfront-3/src/expr3.cpp"
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 783 "/home/claude/cfront-3/src/expr3.cpp"
case 44 :
# 784 "/home/claude/cfront-3/src/expr3.cpp"
case 45 :
# 785 "/home/claude/cfront-3/src/expr3.cpp"
case 177 :
# 786 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = __0this ->
# 786 "/home/claude/cfront-3/src/expr3.cpp"
__O2__4expr.e1 -> __O4__4expr.mem ;
goto sss ;
}
}

# 791 "/home/claude/cfront-3/src/expr3.cpp"
if (__1fn )( (__1fn -> n_used__4name ++ ), (((void )0 ))) ;

# 793 "/home/claude/cfront-3/src/expr3.cpp"
if ((((__1f -> f_const__3fct == 0 )&& __0this -> __O2__4expr.e1 -> __O1__4expr.tp )&& (! is_ptr__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) ))&& ((__1fn ==
# 793 "/home/claude/cfront-3/src/expr3.cpp"
0 )|| ((__1fn -> n_oper__4name != 161 )&& (__1fn -> n_oper__4name != 162 ))))
# 794 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 795 "/home/claude/cfront-3/src/expr3.cpp"
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 796 "/home/claude/cfront-3/src/expr3.cpp"
case 44 :
# 797 "/home/claude/cfront-3/src/expr3.cpp"
{ Pptr __4p ;
# 797 "/home/claude/cfront-3/src/expr3.cpp"
__4p = (__0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ?is_ptr__4typeFv ( __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ) :(((struct ptr *)0 )));
if (__4p && tconst__4typeFv ( __4p -> typ__5pvtyp ) )
# 799 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 799 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V78 ;

# 799 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"non-constMF%n called for constO", (const struct ea *)( ((& __0__V78 )-> __O1__2ea.p =
# 799 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1fn )), (& __0__V78 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 799 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 ) ;
} break ;
}
case 45 :
# 803 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 804 "/home/claude/cfront-3/src/expr3.cpp"
int __4tc ;

# 804 "/home/claude/cfront-3/src/expr3.cpp"
__4tc = (__0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ?(((int )tconst__4typeFv ( __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ) )):0 );
if ((__0this -> __O2__4expr.e1 -> __O1__4expr.tp && __4tc )&& ((! strict_opt )|| (__4tc != 2 )))
# 806 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 806 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V79 ;

# 806 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"non-constMF%n called for constO", (const struct ea *)( ((& __0__V79 )-> __O1__2ea.p =
# 806 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1fn )), (& __0__V79 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 806 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 ) ;
} break ;
}
case 173 :
# 810 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 811 "/home/claude/cfront-3/src/expr3.cpp"
Pptr __4p ;

# 811 "/home/claude/cfront-3/src/expr3.cpp"
__4p = (__0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ?is_ptr__4typeFv ( __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ) :(((struct ptr *)0 )));
if (__4p && tconst__4typeFv ( __4p -> typ__5pvtyp ) )
# 813 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCc ( (const char *)"non-constMF called for constO") ;
# 813 "/home/claude/cfront-3/src/expr3.cpp"

# 814 "/home/claude/cfront-3/src/expr3.cpp"
break ;
}
}
}

# 819 "/home/claude/cfront-3/src/expr3.cpp"
__1t = __1f -> returns__3fct ;
__1x = __1f -> nargs__3fct ;
__1k = __1f -> nargs_known__3fct ;

# 823 "/home/claude/cfront-3/src/expr3.cpp"
__1e = __1arg ;
if (__1k == 0 )goto rlab ;

# 826 "/home/claude/cfront-3/src/expr3.cpp"
for(( (__1nn = __1f -> argtype__3fct ), (__1argno = 1 )) ;__1e || __1nn ;( ( (__1nn = __1nn -> __O1__4name.n_list ), (__1e = __1etail ->
# 826 "/home/claude/cfront-3/src/expr3.cpp"
__O3__4expr.e2 )) , (__1argno ++ )) ) { 
# 827 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __2a ;
int __2save_base ;
const char *__2save_name ;
bit __2mpt ;

# 828 "/home/claude/cfront-3/src/expr3.cpp"
__2save_base = 0 ;
__2save_name = 0 ;
__2mpt = ((__1nn && __1nn -> __O1__4expr.tp )&& memptr__4typeFv ( skiptypedefs__4typeFv ( __1nn -> __O1__4expr.tp ) ) );

# 832 "/home/claude/cfront-3/src/expr3.cpp"
if (__1e ){ 
# 833 "/home/claude/cfront-3/src/expr3.cpp"
__2a = __1e -> __O2__4expr.e1 ;
__1etail = __1e ;

# 836 "/home/claude/cfront-3/src/expr3.cpp"
if (__1nn ){ 
# 837 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __4t1 ;

# 837 "/home/claude/cfront-3/src/expr3.cpp"
__4t1 = skiptypedefs__4typeFv ( __1nn -> __O1__4expr.tp ) ;

# 840 "/home/claude/cfront-3/src/expr3.cpp"
switch (__4t1 -> base__4node ){ 
# 841 "/home/claude/cfront-3/src/expr3.cpp"
case 158 :
# 842 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 843 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __6pt ;

# 843 "/home/claude/cfront-3/src/expr3.cpp"
__6pt = (((struct ptr *)(((struct ptr *)__4t1 ))))-> typ__5pvtyp ;
if (skiptypedefs__4typeFv ( __6pt ) -> base__4node == 110 ){ 
# 845 "/home/claude/cfront-3/src/expr3.cpp"
if (check__4typeFP4typeUcT2 ( __6pt , __2a -> __O1__4expr.tp , (unsigned char )254 ,
# 845 "/home/claude/cfront-3/src/expr3.cpp"
(unsigned char )0 ) ){ 
# 846 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 846 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V80 ;

# 846 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V81 ;

# 846 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V82 ;

# 846 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V83 ;

# 846 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badA %dT for%n:%t (%tX)", (const struct ea *)( (( ((& __0__V80 )->
# 846 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = ((unsigned long )__1argno )), 0 ) ), (& __0__V80 )) , (const struct ea *)( ((& __0__V81 )->
# 846 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.p = ((const void *)__1fn )), (& __0__V81 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V82 , (const void
# 846 "/home/claude/cfront-3/src/expr3.cpp"
*)__2a -> __O1__4expr.tp ) , (const struct ea *)__ct__2eaFPCv ( & __0__V83 , (const void *)__1nn -> __O1__4expr.tp ) ) ;
# 846 "/home/claude/cfront-3/src/expr3.cpp"

# 847 "/home/claude/cfront-3/src/expr3.cpp"
return (struct type *)any_type ;
} }

# 848 "/home/claude/cfront-3/src/expr3.cpp"
;
}
if ((__6pt -> base__4node != 108 )|| check__4typeFP4typeUcT2 ( __6pt , __2a -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 )
# 850 "/home/claude/cfront-3/src/expr3.cpp"
)
# 853 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 854 "/home/claude/cfront-3/src/expr3.cpp"
is_arg = 1 ;
__2a = ref_init__FP3ptrP4exprP5table ( ((struct ptr *)(((struct ptr *)__1nn -> __O1__4expr.tp ))), __2a , __1tbl ) ;
is_arg = 0 ;
}
goto cbcb ;
}
case 119 :
# 861 "/home/claude/cfront-3/src/expr3.cpp"
if ((__2a -> base__4node != 147 )|| check__4typeFP4typeUcT2 ( __1nn -> __O1__4expr.tp , __2a -> __O1__4expr.tp , (unsigned char )70 , (unsigned
# 861 "/home/claude/cfront-3/src/expr3.cpp"
char )0 ) )
# 863 "/home/claude/cfront-3/src/expr3.cpp"
__2a = class_init__FP4exprP4typeT1P5table ( (struct expr *)0 , __4t1 , __2a , __1tbl ) ;
else if (__2a -> __O3__4expr.e2 -> __O1__4expr.tp != __1nn -> __O1__4expr.tp )
# 865 "/home/claude/cfront-3/src/expr3.cpp"
__2a -> __O3__4expr.e2 = class_init__FP4exprP4typeT1P5table ( (struct expr *)0 , __4t1 , __2a -> __O3__4expr.e2 ,
# 865 "/home/claude/cfront-3/src/expr3.cpp"
__1tbl ) ;
if (__1nn -> n_xref__4name ){ 
# 868 "/home/claude/cfront-3/src/expr3.cpp"
__2a = address__4exprFv ( __2a ) ;
}
else { 
# 873 "/home/claude/cfront-3/src/expr3.cpp"
Pname __6cln ;

# 874 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__0__X122 ;

# 873 "/home/claude/cfront-3/src/expr3.cpp"
__6cln = (((struct basetype *)(((struct basetype *)__4t1 ))))-> b_name__8basetype ;
if (__6cln && ( (__0__X122 = (((struct classdef *)(((struct classdef *)__6cln -> __O1__4expr.tp ))))), ( __0__X122 -> c_itor__8classdef ) ) ){ 
# 876 "/home/claude/cfront-3/src/expr3.cpp"
__1nn ->
# 876 "/home/claude/cfront-3/src/expr3.cpp"
n_xref__4name = 1 ;
__2a = address__4exprFv ( __2a ) ;
}
}
cbcb :
# 882 "/home/claude/cfront-3/src/expr3.cpp"
if (__2a -> base__4node == 147 ){ 
# 883 "/home/claude/cfront-3/src/expr3.cpp"
if (__2a -> __O2__4expr.e1 -> base__4node == 111 )__2a -> __O2__4expr.e1 = __2a -> __O2__4expr.e1 -> __O3__4expr.e2 ;
if ((((__2a -> __O2__4expr.e1 -> base__4node == 146 )&& (((struct name *)(((struct name *)__2a -> __O2__4expr.e1 -> __O4__4expr.fct_name )))))&& ((((struct name *)(((struct name *)__2a -> __O2__4expr.e1 ->
# 884 "/home/claude/cfront-3/src/expr3.cpp"
__O4__4expr.fct_name ))))-> n_oper__4name == 161 ))&& ((__2a -> __O3__4expr.e2 -> base__4node == 145 )|| (__2a -> __O3__4expr.e2 -> base__4node == 112 )))
# 887 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 888 "/home/claude/cfront-3/src/expr3.cpp"
__2a = __2a -> __O2__4expr.e1 ;
# 888 "/home/claude/cfront-3/src/expr3.cpp"

# 889 "/home/claude/cfront-3/src/expr3.cpp"
goto cccc ;
}
else if ((__2a -> __O3__4expr.e2 -> base__4node == 145 )&& (__2a -> __O3__4expr.e2 -> __O3__4expr.e2 -> base__4node == 85 ))
# 892 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 893 "/home/claude/cfront-3/src/expr3.cpp"
cccc :
# 894 "/home/claude/cfront-3/src/expr3.cpp"
if ((__4t1 -> base__4node ==
# 894 "/home/claude/cfront-3/src/expr3.cpp"
158 )&& (tconst__4typeFv ( (((struct ptr *)(((struct ptr *)__4t1 ))))-> typ__5pvtyp ) == 0 )){ 
# 894 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X123 ;

# 894 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X124 ;

# 895 "/home/claude/cfront-3/src/expr3.cpp"
if (strict_opt )
# 896 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 896 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V84 ;

# 896 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"temporary used for non-const%tA", (const struct ea *)( (__2__X123 = (const void
# 896 "/home/claude/cfront-3/src/expr3.cpp"
*)__1nn -> __O1__4expr.tp ), ( ((& __0__V84 )-> __O1__2ea.p = __2__X123 ), (& __0__V84 )) ) , (const struct ea *)ea0 ,
# 896 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 898 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 898 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V85 ;

# 898 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"temporary used for non-const%tA; no changes will be propagated to actual argument (anachronism)", (const struct ea *)( (__2__X124 =
# 898 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)__1nn -> __O1__4expr.tp ), ( ((& __0__V85 )-> __O1__2ea.p = __2__X124 ), (& __0__V85 )) ) , (const
# 898 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
}
__1e -> __O2__4expr.e1 = __2a ;
break ;
case 141 :
# 905 "/home/claude/cfront-3/src/expr3.cpp"
goto rlab ;
case 125 :
# 907 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 908 "/home/claude/cfront-3/src/expr3.cpp"
__2save_base = __1e -> __O2__4expr.e1 -> base__4node ;
if (__2a -> __O1__4expr.tp -> base__4node == 76 )
# 910 "/home/claude/cfront-3/src/expr3.cpp"
__2save_name = (((struct gen *)(((struct gen *)__2a -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list -> __O2__4expr.string ;
{ Pexpr __6te_a ;

# 911 "/home/claude/cfront-3/src/expr3.cpp"
__6te_a = __2a ;
__1e -> __O2__4expr.e1 = (__2a = ptr_init__FP3ptrP4exprP5table ( ((struct ptr *)(((struct ptr *)__4t1 ))), __2a , __1tbl ) );
__1no_change = (__6te_a == __2a );
if (Pchecked == 0 )goto def ;
break ;

# 915 "/home/claude/cfront-3/src/expr3.cpp"
}
}
case 5 :
# 918 "/home/claude/cfront-3/src/expr3.cpp"
case 29 :
# 919 "/home/claude/cfront-3/src/expr3.cpp"
case 21 :
# 920 "/home/claude/cfront-3/src/expr3.cpp"
{ Ptype __6t ;

# 920 "/home/claude/cfront-3/src/expr3.cpp"
__6t = skiptypedefs__4typeFv ( __2a -> __O1__4expr.tp ) ;
switch (__6t -> base__4node ){ 
# 921 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X125 ;

# 922 "/home/claude/cfront-3/src/expr3.cpp"
case 22 :
# 923 "/home/claude/cfront-3/src/expr3.cpp"
case 15 :
# 924 "/home/claude/cfront-3/src/expr3.cpp"
case 11 :
# 925 "/home/claude/cfront-3/src/expr3.cpp"
case 181 :
# 926 "/home/claude/cfront-3/src/expr3.cpp"
if (! ambig )
# 927 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 927 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V86 ;

# 927 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V87 ;

# 927 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V88 ;

# 927 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"A%d: %t passed as %t", (const struct ea *)( ((
# 927 "/home/claude/cfront-3/src/expr3.cpp"
((& __0__V86 )-> __O1__2ea.i = ((unsigned long )__1argno )), 0 ) ), (& __0__V86 )) , (const struct ea *)(
# 927 "/home/claude/cfront-3/src/expr3.cpp"
(__2__X125 = (const void *)__2a -> __O1__4expr.tp ), ( ((& __0__V87 )-> __O1__2ea.p = __2__X125 ), (& __0__V87 )) ) ,
# 927 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)( ((& __0__V88 )-> __O1__2ea.p = ((const void *)__4t1 )), (& __0__V88 )) , (const struct
# 927 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 ) ;
} }
}

# 931 "/home/claude/cfront-3/src/expr3.cpp"
case 22 :
# 932 "/home/claude/cfront-3/src/expr3.cpp"
if (((((struct basetype *)(((struct basetype *)__4t1 ))))-> b_unsigned__8basetype && (__2a -> base__4node == 107 ))&& (__2a -> __O3__4expr.e2 -> base__4node == 82 ))
# 935 "/home/claude/cfront-3/src/expr3.cpp"
{
# 935 "/home/claude/cfront-3/src/expr3.cpp"

# 935 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V89 ;

# 935 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"negativeA for%n, unsignedX", (const struct ea *)( ((&
# 935 "/home/claude/cfront-3/src/expr3.cpp"
__0__V89 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V89 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 935 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 ) ;
} default :
# 937 "/home/claude/cfront-3/src/expr3.cpp"
def :
# 938 "/home/claude/cfront-3/src/expr3.cpp"
{ Pexpr __6x ;
int __6ct ;

# 938 "/home/claude/cfront-3/src/expr3.cpp"
__6x = try_to_coerce__FP4typeP4exprPCcP5table ( __4t1 , __2a , (const char *)"argument", __1tbl ) ;
__6ct = no_const ;

# 941 "/home/claude/cfront-3/src/expr3.cpp"
if (__6x ){ 
# 942 "/home/claude/cfront-3/src/expr3.cpp"
if ((is_ptr__4typeFv ( __4t1 ) && (Pchecked == 0 ))&& __1no_change ){ 
# 943 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __8te_x ;

# 943 "/home/claude/cfront-3/src/expr3.cpp"
__8te_x = ptr_init__FP3ptrP4exprP5table ( ((struct ptr *)(((struct ptr *)__4t1 ))), __6x , __1tbl ) ;

# 945 "/home/claude/cfront-3/src/expr3.cpp"
if (__8te_x != __6x )__1e -> __O2__4expr.e1 = (__2a = __8te_x );
else 
# 945 "/home/claude/cfront-3/src/expr3.cpp"
__1e -> __O2__4expr.e1 = __6x ;
}
else 
# 948 "/home/claude/cfront-3/src/expr3.cpp"
__1e -> __O2__4expr.e1 = __6x ;
}
else if (check__4typeFP4typeUcT2 ( __1nn -> __O1__4expr.tp , __2a -> __O1__4expr.tp , (unsigned char )136 , (unsigned char )0 ) ){
# 950 "/home/claude/cfront-3/src/expr3.cpp"

# 951 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 951 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V90 ;

# 951 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V91 ;

# 951 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V92 ;

# 951 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V93 ;

# 951 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"badA %dT for%n:%t (%tX)", (const struct ea *)( ((
# 951 "/home/claude/cfront-3/src/expr3.cpp"
((& __0__V90 )-> __O1__2ea.i = ((unsigned long )__1argno )), 0 ) ), (& __0__V90 )) , (const struct ea *)(
# 951 "/home/claude/cfront-3/src/expr3.cpp"
((& __0__V91 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V91 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V92 ,
# 951 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)__2a -> __O1__4expr.tp ) , (const struct ea *)__ct__2eaFPCv ( & __0__V93 , (const void *)__1nn -> __O1__4expr.tp )
# 951 "/home/claude/cfront-3/src/expr3.cpp"
) ;
if (__6ct )error__FiPCc ( (int )'c' , (const char *)" (no usable const conversion)\n") ;
else error__FiPCc ( (int )'c' , (const char *)"\n") ;
return (struct type *)any_type ;
} }
}
}

# 959 "/home/claude/cfront-3/src/expr3.cpp"
{ Pexpr __4tt ;

# 959 "/home/claude/cfront-3/src/expr3.cpp"
__4tt = __1e -> __O2__4expr.e1 ;
while ((__4tt -> base__4node == 113 )|| (__4tt -> base__4node == 191 ))
# 961 "/home/claude/cfront-3/src/expr3.cpp"
__4tt = __4tt -> __O2__4expr.e1 ;
if (__4tt -> base__4node == 124 )
# 963 "/home/claude/cfront-3/src/expr3.cpp"
__1e -> __O2__4expr.e1 = __4tt ;

# 965 "/home/claude/cfront-3/src/expr3.cpp"
if (__1e -> __O2__4expr.e1 -> base__4node == 124 ){ 
# 968 "/home/claude/cfront-3/src/expr3.cpp"
if (__2save_base == 44 ){ 
# 969 "/home/claude/cfront-3/src/expr3.cpp"
Pptr __6m ;

# 970 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X126 ;

# 969 "/home/claude/cfront-3/src/expr3.cpp"
__6m = (((struct ptr *)(((struct ptr *)__2a -> __O1__4expr.tp ))));

# 975 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 975 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V94 ;

# 975 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V95 ;

# 975 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V96 ;

# 975 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"address of boundF (try using ``%s::*'' forPT and ``&%s::%s'' for address)", (const struct ea *)( (__2__X126 = (const void
# 975 "/home/claude/cfront-3/src/expr3.cpp"
*)__6m -> memof__3ptr -> string__8classdef ), ( ((& __0__V94 )-> __O1__2ea.p = __2__X126 ), (& __0__V94 )) ) , (const struct
# 975 "/home/claude/cfront-3/src/expr3.cpp"
ea *)__ct__2eaFPCv ( & __0__V95 , (const void *)__6m -> memof__3ptr -> string__8classdef ) , (const struct ea *)( ((& __0__V96 )->
# 975 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.p = ((const void *)__2save_name )), (& __0__V96 )) , (const struct ea *)ea0 ) ;
} }
if (__2mpt ){ 
# 978 "/home/claude/cfront-3/src/expr3.cpp"
Pname __6temp ;

# 978 "/home/claude/cfront-3/src/expr3.cpp"
__6temp = make_tmp__FcP4typeP5table ( 'A' , (struct type *)mptr_type , __1tbl ) ;
__1e -> __O2__4expr.e1 = mptr_assign__FP4exprT1 ( (struct expr *)__6temp , __1e -> __O2__4expr.e1 ) ;
__1e -> __O2__4expr.e1 = (__2a = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __1e -> __O2__4expr.e1 , (struct expr *)__6temp ) );
# 980 "/home/claude/cfront-3/src/expr3.cpp"

# 981 "/home/claude/cfront-3/src/expr3.cpp"
__2a -> __O1__4expr.tp = __6temp -> __O1__4expr.tp ;
}
else { 
# 984 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __6t ;

# 984 "/home/claude/cfront-3/src/expr3.cpp"
__6t = __1e -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ;
__1e -> __O2__4expr.e1 = __1e -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O2__4expr.e1 ;
__2a -> __O1__4expr.tp = (__1e -> __O2__4expr.e1 -> __O1__4expr.tp = __6t );
}
}

# 988 "/home/claude/cfront-3/src/expr3.cpp"
}

# 990 "/home/claude/cfront-3/src/expr3.cpp"
}
else { 
# 992 "/home/claude/cfront-3/src/expr3.cpp"
if (__1k != 155 ){ 
# 993 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 993 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V97 ;

# 993 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V98 ;

# 993 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"unexpected %dA for%n", (const struct ea *)( (( ((& __0__V97 )->
# 993 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = ((unsigned long )__1argno )), 0 ) ), (& __0__V97 )) , (const struct ea *)( ((& __0__V98 )->
# 993 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.p = ((const void *)__1fn )), (& __0__V98 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 993 "/home/claude/cfront-3/src/expr3.cpp"

# 994 "/home/claude/cfront-3/src/expr3.cpp"
return (struct type *)any_type ;
} }
if (! check__4typeFP4typeUcT2 ( skiptypedefs__4typeFv ( __2a -> __O1__4expr.tp ) , (struct type *)void_type , (unsigned char )0 , (unsigned
# 996 "/home/claude/cfront-3/src/expr3.cpp"
char )0 ) )
# 997 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 997 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V99 ;

# 997 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V100 ;

# 997 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V101 ;

# 997 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badA %dT for%n:%t", (const struct ea *)( (( ((& __0__V99 )->
# 997 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = ((unsigned long )__1argno )), 0 ) ), (& __0__V99 )) , (const struct ea *)( ((& __0__V100 )->
# 997 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.p = ((const void *)__1fn )), (& __0__V100 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V101 , (const void
# 997 "/home/claude/cfront-3/src/expr3.cpp"
*)__2a -> __O1__4expr.tp ) , (const struct ea *)ea0 ) ;
} { Pexpr __4te ;

# 998 "/home/claude/cfront-3/src/expr3.cpp"
__4te = __1e ;
while (__1e ){ 
# 1000 "/home/claude/cfront-3/src/expr3.cpp"
if (__1e -> __O1__4expr.tp )
# 1001 "/home/claude/cfront-3/src/expr3.cpp"
tsizeof__4typeFi ( __1e -> __O1__4expr.tp , 0 ) ;
if (__1e -> __O2__4expr.e1 -> base__4node == 124 ){ 
# 1005 "/home/claude/cfront-3/src/expr3.cpp"
Pname __6temp ;

# 1005 "/home/claude/cfront-3/src/expr3.cpp"
__6temp = make_tmp__FcP4typeP5table ( 'A' , (struct type *)mptr_type , __1tbl ) ;
__1e -> __O2__4expr.e1 = mptr_assign__FP4exprT1 ( (struct expr *)__6temp , __1e -> __O2__4expr.e1 ) ;
__1e -> __O2__4expr.e1 = (__2a = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __1e -> __O2__4expr.e1 , (struct expr *)__6temp ) );
# 1007 "/home/claude/cfront-3/src/expr3.cpp"

# 1008 "/home/claude/cfront-3/src/expr3.cpp"
__2a -> __O1__4expr.tp = __6temp -> __O1__4expr.tp ;
}
__1e = __1e -> __O3__4expr.e2 ;
}
__1e = __4te ;
goto rlab ;

# 1013 "/home/claude/cfront-3/src/expr3.cpp"
}
}
}
else { 
# 1017 "/home/claude/cfront-3/src/expr3.cpp"
__2a = __1nn -> __O3__4expr.n_initializer ;
if (__2a == 0 ){ 
# 1018 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X127 ;

# 1018 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X128 ;

# 1019 "/home/claude/cfront-3/src/expr3.cpp"
if (__1fn == 0 )
# 1020 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1020 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V102 ;

# 1020 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V103 ;

# 1020 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"A %d ofT%tX for call", (const struct ea *)( (( ((& __0__V102 )->
# 1020 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = ((unsigned long )__1argno )), 0 ) ), (& __0__V102 )) , (const struct ea *)( (__2__X127 = (const
# 1020 "/home/claude/cfront-3/src/expr3.cpp"
void *)__1nn -> __O1__4expr.tp ), ( ((& __0__V103 )-> __O1__2ea.p = __2__X127 ), (& __0__V103 )) ) , (const struct
# 1020 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 1022 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1022 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V104 ;

# 1022 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V105 ;

# 1022 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V106 ;

# 1022 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"A %d ofT%tX for%n", (const struct ea *)( (( ((& __0__V104 )->
# 1022 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = ((unsigned long )__1argno )), 0 ) ), (& __0__V104 )) , (const struct ea *)( (__2__X128 = (const
# 1022 "/home/claude/cfront-3/src/expr3.cpp"
void *)__1nn -> __O1__4expr.tp ), ( ((& __0__V105 )-> __O1__2ea.p = __2__X128 ), (& __0__V105 )) ) , (const struct
# 1022 "/home/claude/cfront-3/src/expr3.cpp"
ea *)( ((& __0__V106 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V106 )) , (const struct ea *)ea0 ) ;
# 1022 "/home/claude/cfront-3/src/expr3.cpp"
} 
# 1023 "/home/claude/cfront-3/src/expr3.cpp"
return (struct type *)any_type ;
}
if ((__2a -> base__4node == 124 )|| (((__2a -> base__4node == 113 )|| (__2a -> base__4node == 191 ))&& (__2a -> __O2__4expr.e1 -> base__4node == 124 )))
# 1026 "/home/claude/cfront-3/src/expr3.cpp"
{
# 1026 "/home/claude/cfront-3/src/expr3.cpp"

# 1029 "/home/claude/cfront-3/src/expr3.cpp"
Pname __4temp ;

# 1029 "/home/claude/cfront-3/src/expr3.cpp"
__4temp = make_tmp__FcP4typeP5table ( 'A' , (struct type *)mptr_type , __1tbl ) ;
if (__2a -> base__4node != 124 )
# 1031 "/home/claude/cfront-3/src/expr3.cpp"
__2a = __2a -> __O2__4expr.e1 ;
__2a = mptr_assign__FP4exprT1 ( (struct expr *)__4temp , __2a ) ;
__2a = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __2a , (struct expr *)__4temp ) ;
__2a -> __O1__4expr.tp = __4temp -> __O1__4expr.tp ;
}
__2a -> permanent__4node = 2 ;
__1e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __2a , (struct expr *)0 ) ;
if (__1etail )
# 1039 "/home/claude/cfront-3/src/expr3.cpp"
__1etail -> __O3__4expr.e2 = __1e ;
else 
# 1041 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O3__4expr.e2 = __1e ;
__1etail = __1e ;
}
}

# 1046 "/home/claude/cfront-3/src/expr3.cpp"
rlab :
# 1048 "/home/claude/cfront-3/src/expr3.cpp"
for(;__1e ;__1e = __1e -> __O3__4expr.e2 ) { 
# 1049 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __2a ;
Pname __2cn ;

# 1049 "/home/claude/cfront-3/src/expr3.cpp"
__2a = __1e -> __O2__4expr.e1 ;

# 1052 "/home/claude/cfront-3/src/expr3.cpp"
if ((__2a -> base__4node == 85 )&& (__2a -> __O1__4expr.tp -> base__4node == 108 )){ 
# 1055 "/home/claude/cfront-3/src/expr3.cpp"
lval__4exprFUc ( __2a , (unsigned char )112 ) ;
# 1055 "/home/claude/cfront-3/src/expr3.cpp"

# 1056 "/home/claude/cfront-3/src/expr3.cpp"
}
else if (warning_opt && (__2cn = is_cl_obj__4typeFv ( __2a -> __O1__4expr.tp ) )){ 
# 1058 "/home/claude/cfront-3/src/expr3.cpp"
Pclass __3cl ;

# 1058 "/home/claude/cfront-3/src/expr3.cpp"
__3cl = (((struct classdef *)(((struct classdef *)__2cn -> __O1__4expr.tp ))));
if (( __3cl -> c_ctor__8classdef ) || look__5tableFPCcUc ( __3cl -> memtbl__8classdef , (const char *)"__as",
# 1059 "/home/claude/cfront-3/src/expr3.cpp"
(unsigned char )0 ) )
# 1060 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1061 "/home/claude/cfront-3/src/expr3.cpp"
if (__0this -> __O4__4expr.fct_name )
# 1062 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1062 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V107 ;

# 1062 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V108 ;

# 1062 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V109 ;

# 1062 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"O ofC%t withK or = copied asA to%n (%t)", (const struct ea *)( ((&
# 1062 "/home/claude/cfront-3/src/expr3.cpp"
__0__V107 )-> __O1__2ea.p = ((const void *)__3cl )), (& __0__V107 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V108 , (const
# 1062 "/home/claude/cfront-3/src/expr3.cpp"
void *)__0this -> __O4__4expr.fct_name ) , (const struct ea *)__ct__2eaFPCv ( & __0__V109 , (const void *)__0this -> __O4__4expr.fct_name -> __O1__4expr.tp )
# 1062 "/home/claude/cfront-3/src/expr3.cpp"
, (const struct ea *)ea0 ) ;
} else 
# 1064 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1064 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V110 ;

# 1064 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"O ofC%t withK or = copied asA to `...'", (const struct ea *)( ((&
# 1064 "/home/claude/cfront-3/src/expr3.cpp"
__0__V110 )-> __O1__2ea.p = ((const void *)__3cl )), (& __0__V110 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1064 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 ) ;
} }
}
else if (is_ref__4typeFv ( __2a -> __O1__4expr.tp ) )
# 1068 "/home/claude/cfront-3/src/expr3.cpp"
__1e -> __O2__4expr.e1 = contents__4exprFv ( __2a ) ;
}

# 1071 "/home/claude/cfront-3/src/expr3.cpp"
if (__1f -> f_result__3fct ){ 
# 1072 "/home/claude/cfront-3/src/expr3.cpp"
Pname __2oldNtmp ;

# 1072 "/home/claude/cfront-3/src/expr3.cpp"
__2oldNtmp = Ntmp ;
Ntmp = 0 ;
{ Pname __2tn ;

# 1076 "/home/claude/cfront-3/src/expr3.cpp"
extern bit in_quest ;

# 1074 "/home/claude/cfront-3/src/expr3.cpp"
__2tn = make_tmp__FcP4typeP5table ( 'R' , __1f -> returns__3fct , __1tbl ) ;

# 1077 "/home/claude/cfront-3/src/expr3.cpp"
if (Ntmp ){ 
# 1078 "/home/claude/cfront-3/src/expr3.cpp"
if (Ntmp_refd && in_quest ){ 
# 1079 "/home/claude/cfront-3/src/expr3.cpp"
__2tn -> __O1__4name.n_list = Ntmp_refd ;
Ntmp_refd = __2tn ;
}
else Ntmp_refd = __2tn ;
}

# 1087 "/home/claude/cfront-3/src/expr3.cpp"
if (__2oldNtmp )Ntmp = __2oldNtmp ;

# 1089 "/home/claude/cfront-3/src/expr3.cpp"
if (Ntmp_refd && in_quest ){ 
# 1089 "/home/claude/cfront-3/src/expr3.cpp"
struct ival *__0__X129 ;

# 1090 "/home/claude/cfront-3/src/expr3.cpp"
Ntmp_flag = make_tmp__FcP4typeP5table ( 'Q' , (struct type *)int_type , __1tbl ) ;
Ntmp_flag -> __O3__4expr.n_initializer = (struct expr *)( (__0__X129 = 0 ), ( ((__0__X129 || (__0__X129 = (struct ival *)__nw__4exprSFUl ( (unsigned long )(sizeof
# 1091 "/home/claude/cfront-3/src/expr3.cpp"
(struct ival))) ))?( (__0__X129 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X129 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 )
# 1091 "/home/claude/cfront-3/src/expr3.cpp"
), (__0__X129 -> __O2__4expr.i1 = ((long long )0L ))) :0 ), __0__X129 ) ) ;
assign__4nameFv ( Ntmp_flag ) ;
if (Ntmp_flag_list && in_quest ){ 
# 1094 "/home/claude/cfront-3/src/expr3.cpp"
Ntmp_flag -> __O1__4name.n_list = Ntmp_flag_list ;
Ntmp_flag_list = Ntmp_flag ;
}
else Ntmp_flag_list = Ntmp_flag ;
}

# 1100 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , address__4exprFv ( (struct expr *)__2tn ) , __0this -> __O3__4expr.e2 )
# 1100 "/home/claude/cfront-3/src/expr3.cpp"
;
{ Pexpr __2ee ;

# 1101 "/home/claude/cfront-3/src/expr3.cpp"
__2ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )0 , (struct expr *)0 , (struct expr *)0 ) ;
((*__2ee ))= (*__0this );
__0this -> base__4node = 147 ;
__0this -> __O2__4expr.e1 = __2ee ;
if (refd == 2 )
# 1106 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O3__4expr.e2 = address__4exprFv ( (struct expr *)__2tn ) ;
else __0this -> __O3__4expr.e2 = (struct expr *)__2tn ;
__0this -> __O1__4expr.tp = __2tn -> __O1__4expr.tp ;

# 1108 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1108 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 1111 "/home/claude/cfront-3/src/expr3.cpp"
return __1t ;
}

# 715 "/home/claude/cfront-3/src/cfront.h"

# 718 "/home/claude/cfront-3/src/cfront.h"

# 741 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ptof__FP3fctP4exprP5table (Pfct , Pexpr , Ptable );

# 35 "/home/claude/cfront-3/src/cfront.h"
extern Ptype unconst_type__FP4type (Ptype );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 1114 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr ref_init__FP3ptrP4exprP5table (Pptr __1p , Pexpr __1init , Ptable __1tbl )
# 1120 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1121 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __1it ;
Pptr __1px ;
Ptype __1p1 ;
Pname __1c1 ;

# 1121 "/home/claude/cfront-3/src/expr3.cpp"
__1it = skiptypedefs__4typeFv ( __1init -> __O1__4expr.tp ) ;
__1px = (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv ( (struct type *)__1p ) ))));
__1p1 = __1px -> typ__5pvtyp ;
__1c1 = is_cl_obj__4typeFv ( __1p1 ) ;

# 1128 "/home/claude/cfront-3/src/expr3.cpp"
if (__1init -> base__4node == 124 )error__FPCc ( (const char *)"IrL as RIr") ;

# 1130 "/home/claude/cfront-3/src/expr3.cpp"
if (((__1init -> base__4node == 85 )&& ((((struct name *)(((struct name *)__1init ))))-> n_scope__4name == 136 ))&& (__1init -> __O1__4expr.tp -> base__4node == 15 ))
# 1133 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCc ( (int
# 1133 "/home/claude/cfront-3/src/expr3.cpp"
)'w' , (const char *)"initializing a float& with floatA is non-portable") ;

# 1135 "/home/claude/cfront-3/src/expr3.cpp"
{ Ptype __1tt ;

# 1135 "/home/claude/cfront-3/src/expr3.cpp"
__1tt = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __1it ) ) ;
__1px -> base__4node = 125 ;

# 1138 "/home/claude/cfront-3/src/expr3.cpp"
{ int __1x ;

# 1138 "/home/claude/cfront-3/src/expr3.cpp"
__1x = check__4typeFP4typeUcT2 ( (struct type *)__1px , __1tt , (unsigned char )78 , (unsigned char )0 ) ;

# 1140 "/home/claude/cfront-3/src/expr3.cpp"
if (__1x == 0 ){ 
# 1141 "/home/claude/cfront-3/src/expr3.cpp"
if ((tconst__4typeFv ( __1init -> __O1__4expr.tp ) && (vec_const == 0 ))&& (fct_const == 0 ))
# 1143 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1143 "/home/claude/cfront-3/src/expr3.cpp"
const void
# 1143 "/home/claude/cfront-3/src/expr3.cpp"
*__2__X142 ;

# 1145 "/home/claude/cfront-3/src/expr3.cpp"
if (__1init -> base__4node == 140 )__1init = __1init -> __O2__4expr.e1 ;
if (tconst__4typeFv ( __1px -> typ__5pvtyp ) == 0 )
# 1147 "/home/claude/cfront-3/src/expr3.cpp"
if (cc -> nof__11dcl_context && in_return )
# 1148 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1148 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V130 ;

# 1148 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot return a reference to a non-constO from const member function %n", (const struct ea *)( (__2__X142 = (const void
# 1148 "/home/claude/cfront-3/src/expr3.cpp"
*)cc -> nof__11dcl_context ), ( ((& __0__V130 )-> __O1__2ea.p = __2__X142 ), (& __0__V130 )) ) , (const struct ea *)ea0 ,
# 1148 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else error__FPCc ( (const char *)"R to constO") ;
__1px -> base__4node = 158 ;

# 1152 "/home/claude/cfront-3/src/expr3.cpp"
ignore_const ++ ;
if (lval__4exprFUc ( __1init , (unsigned char )0 ) ){ 
# 1154 "/home/claude/cfront-3/src/expr3.cpp"
lval__4exprFUc ( __1init , (unsigned char )112 ) ;
ignore_const -- ;

# 1157 "/home/claude/cfront-3/src/expr3.cpp"
return ptr_init__FP3ptrP4exprP5table ( __1px , address__4exprFv ( __1init ) , __1tbl ) ;
}
ignore_const -- ;
goto xxx ;
}
__1px -> base__4node = 158 ;
if (lval__4exprFUc ( __1init , (unsigned char )0 ) ){ 
# 1164 "/home/claude/cfront-3/src/expr3.cpp"
lval__4exprFUc ( __1init , (unsigned char )112 ) ;

# 1166 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __4name_in_deref ;
Pexpr __4act_param ;

# 1167 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __4ret_exp ;

# 1166 "/home/claude/cfront-3/src/expr3.cpp"
__4name_in_deref = 0 ;
__4act_param = 0 ;

# 1167 "/home/claude/cfront-3/src/expr3.cpp"
__4ret_exp = 0 ;
if ((__1init -> base__4node == 111 )&& (__1init -> __O2__4expr.e1 && (__1init -> __O2__4expr.e1 -> base__4node == 85 )))
# 1170 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1171 "/home/claude/cfront-3/src/expr3.cpp"
__4name_in_deref = (((struct name *)(((struct name *)__1init ->
# 1171 "/home/claude/cfront-3/src/expr3.cpp"
__O2__4expr.e1 ))));
}

# 1172 "/home/claude/cfront-3/src/expr3.cpp"
;

# 1174 "/home/claude/cfront-3/src/expr3.cpp"
if (__4name_in_deref && (__4name_in_deref -> n_xref__4name && (__4name_in_deref -> n_scope__4name == 136 )))
# 1177 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1188 "/home/claude/cfront-3/src/expr3.cpp"
if (__1init -> __O2__4expr.e1 -> __O1__4expr.tp ){ 
# 1188 "/home/claude/cfront-3/src/expr3.cpp"
struct type *__0__X143 ;

# 1189 "/home/claude/cfront-3/src/expr3.cpp"
__4act_param = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __1init -> __O2__4expr.e1 ) ;
__4act_param -> __O1__4expr.tp = (struct type *)( (__0__X143 = __1init -> __O2__4expr.e1 -> __O1__4expr.tp ), ( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char
# 1190 "/home/claude/cfront-3/src/expr3.cpp"
)125 , __0__X143 ) ) ) ;

# 1192 "/home/claude/cfront-3/src/expr3.cpp"
__4ret_exp = ptr_init__FP3ptrP4exprP5table ( __1px , __4act_param , __1tbl ) ;
}
else 
# 1193 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1195 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1195 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V131 ;

# 1195 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V132 ;

# 1195 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"i", (const struct ea *)( ((& __0__V131 )-> __O1__2ea.p =
# 1195 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)"No type for actual param %n")), (& __0__V131 )) , (const struct ea *)( ((&
# 1195 "/home/claude/cfront-3/src/expr3.cpp"
__0__V132 )-> __O1__2ea.p = ((const void *)__4name_in_deref )), (& __0__V132 )) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 1195 "/home/claude/cfront-3/src/expr3.cpp"
;
} }
}
else 
# 1197 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1198 "/home/claude/cfront-3/src/expr3.cpp"
__4ret_exp = ptr_init__FP3ptrP4exprP5table ( __1px , address__4exprFv ( __1init ) , __1tbl ) ;
}

# 1199 "/home/claude/cfront-3/src/expr3.cpp"
;
return __4ret_exp ;
}

# 1201 "/home/claude/cfront-3/src/expr3.cpp"
;
}
goto xxx ;
}

# 1206 "/home/claude/cfront-3/src/expr3.cpp"
__1px -> base__4node = 158 ;

# 1210 "/home/claude/cfront-3/src/expr3.cpp"
if (__1c1 ){ 
# 1211 "/home/claude/cfront-3/src/expr3.cpp"
ref_cast ++ ;
{ Pexpr __2x ;

# 1212 "/home/claude/cfront-3/src/expr3.cpp"
__2x = try_to_coerce__FP4typeP4exprPCcP5table ( (struct type *)__1p , __1init , (const char *)"reference initialization", __1tbl ) ;
# 1212 "/home/claude/cfront-3/src/expr3.cpp"

# 1213 "/home/claude/cfront-3/src/expr3.cpp"
ref_cast -- ;
if (__2x ){ 
# 1215 "/home/claude/cfront-3/src/expr3.cpp"
__1init = __2x ;
goto xxx ;
}
if ((tconst__4typeFv ( __1init -> __O1__4expr.tp ) && (! vec_const ))&& (! tconst__4typeFv ( __1p1 ) )){ 
# 1219 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCc ( (const char
# 1219 "/home/claude/cfront-3/src/expr3.cpp"
*)"R to constO") ;
return __1init ;
}
switch (__1init -> base__4node ){ 
# 1223 "/home/claude/cfront-3/src/expr3.cpp"
case 81 :case 86 :case 84 :
# 1224 "/home/claude/cfront-3/src/expr3.cpp"
case 82 :case 83 :case 150 :
# 1225 "/home/claude/cfront-3/src/expr3.cpp"
case 85 :
# 1226 "/home/claude/cfront-3/src/expr3.cpp"
refd = 1 ;
break ;
default :
# 1231 "/home/claude/cfront-3/src/expr3.cpp"
refd = ((((__1init -> __O2__4expr.e1 && (__1init -> __O2__4expr.e1 -> base__4node == 85 ))&& (__1init -> __O2__4expr.e1 -> __O1__4expr.tp -> base__4node != 158 ))&& ((((struct
# 1231 "/home/claude/cfront-3/src/expr3.cpp"
name *)(((struct name *)__1init -> __O2__4expr.e1 ))))-> n_xref__4name == 0 ))?2 :1 );
break ;
}

# 1235 "/home/claude/cfront-3/src/expr3.cpp"
{ Pexpr __2a ;

# 1235 "/home/claude/cfront-3/src/expr3.cpp"
__2a = class_init__FP4exprP4typeT1P5table ( (struct expr *)0 , __1p1 , __1init , __1tbl ) ;
refd = 0 ;
if ((__2a == __1init )&& (__1init -> __O1__4expr.tp != (((struct type *)any_type ))))goto xxx ;

# 1239 "/home/claude/cfront-3/src/expr3.cpp"
switch (__2a -> base__4node ){ 
# 1240 "/home/claude/cfront-3/src/expr3.cpp"
case 146 :
# 1241 "/home/claude/cfront-3/src/expr3.cpp"
__1init = __2a ;
goto xxx ;
}
switch (__1init -> base__4node ){ 
# 1245 "/home/claude/cfront-3/src/expr3.cpp"
case 71 :
# 1246 "/home/claude/cfront-3/src/expr3.cpp"
case 147 :
# 1247 "/home/claude/cfront-3/src/expr3.cpp"
break ;
case 85 :
# 1249 "/home/claude/cfront-3/src/expr3.cpp"
case 111 :
# 1250 "/home/claude/cfront-3/src/expr3.cpp"
case 44 :
# 1251 "/home/claude/cfront-3/src/expr3.cpp"
case 45 :
# 1252 "/home/claude/cfront-3/src/expr3.cpp"
if (((tconst__4typeFv ( __1it ) == 0 )|| vec_const )&& ((fct_const == 0 )|| (is_ptr__4typeFv ( __1p1 )
# 1252 "/home/claude/cfront-3/src/expr3.cpp"
== 0 )))
# 1256 "/home/claude/cfront-3/src/expr3.cpp"
break ;
default :
# 1258 "/home/claude/cfront-3/src/expr3.cpp"
if (__1p1 && (__1p1 -> b_const__4type == 0 )){ 
# 1258 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X144 ;

# 1259 "/home/claude/cfront-3/src/expr3.cpp"
if ((__1tbl == gtbl )|| (strict_opt && (! is_arg )))
# 1260 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1260 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V133 ;

# 1260 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"Ir for%snon-constR not an lvalue", (const struct ea *)( (__2__X144 = (const void
# 1260 "/home/claude/cfront-3/src/expr3.cpp"
*)(strict_opt ?"":(((char *)" global ")))), ( ((& __0__V133 )-> __O1__2ea.p =
# 1260 "/home/claude/cfront-3/src/expr3.cpp"
__2__X144 ), (& __0__V133 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 1260 "/home/claude/cfront-3/src/expr3.cpp"
;
} else if (! is_arg )
# 1262 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCc ( (int )'w' , (const char *)"Ir for non-constR not an lvalue (anachronism)")
# 1262 "/home/claude/cfront-3/src/expr3.cpp"
;
}
}
__2a = address__4exprFv ( __2a ) ;
__2a = ptr_init__FP3ptrP4exprP5table ( __1px , __2a , __1tbl ) ;
return __2a ;

# 1267 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1267 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 1271 "/home/claude/cfront-3/src/expr3.cpp"
if (check__4typeFP4typeUcT2 ( __1p1 , __1it , (unsigned char )0 , (unsigned char )0 ) ){ 
# 1273 "/home/claude/cfront-3/src/expr3.cpp"
if (check__4typeFP4typeUcT2 ( __1p1 ,
# 1273 "/home/claude/cfront-3/src/expr3.cpp"
__1it , (unsigned char )70 , (unsigned char )0 ) == 0 ){ 
# 1274 "/home/claude/cfront-3/src/expr3.cpp"
goto def ;
}

# 1277 "/home/claude/cfront-3/src/expr3.cpp"
{ Pexpr __2x ;

# 1277 "/home/claude/cfront-3/src/expr3.cpp"
__2x = try_to_coerce__FP4typeP4exprPCcP5table ( __1p1 , __1init , (const char *)"reference", __1tbl ) ;
if (__2x == 0 )
# 1279 "/home/claude/cfront-3/src/expr3.cpp"
__2x = try_to_coerce__FP4typeP4exprPCcP5table ( (struct type *)__1px , __1init , (const char *)"reference",
# 1279 "/home/claude/cfront-3/src/expr3.cpp"
__1tbl ) ;
if (__2x ){ 
# 1281 "/home/claude/cfront-3/src/expr3.cpp"
__1init = __2x ;
goto def ;
}
{ int __2nc ;

# 1286 "/home/claude/cfront-3/src/expr3.cpp"
Pptr __2p1_ptr ;

# 1287 "/home/claude/cfront-3/src/expr3.cpp"
struct type *__1__Xt00anhfx544vcog ;

# 1284 "/home/claude/cfront-3/src/expr3.cpp"
__2nc = no_const ;

# 1286 "/home/claude/cfront-3/src/expr3.cpp"
__2p1_ptr = is_ptr__4typeFv ( __1p1 ) ;

# 1288 "/home/claude/cfront-3/src/expr3.cpp"
if ((__2p1_ptr && (skiptypedefs__4typeFv ( __2p1_ptr -> typ__5pvtyp ) -> base__4node == 108 ))&& ( (__1__Xt00anhfx544vcog = skiptypedefs__4typeFv ( __1it ) ), (
# 1288 "/home/claude/cfront-3/src/expr3.cpp"
((__1__Xt00anhfx544vcog -> base__4node == 125 )?( (__1__Xt00anhfx544vcog = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__1__Xt00anhfx544vcog ))))-> typ__5pvtyp ) ), 0 ) :0 ), (((unsigned char
# 1288 "/home/claude/cfront-3/src/expr3.cpp"
)((__1__Xt00anhfx544vcog -> base__4node == ((unsigned char )76 ))?1 :0 )))) ) )
# 1291 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1292 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __3op ;

# 1292 "/home/claude/cfront-3/src/expr3.cpp"
__3op = ptof__FP3fctP4exprP5table ( ((struct fct *)(((struct fct *)skiptypedefs__4typeFv ( __2p1_ptr -> typ__5pvtyp ) ))), __1init , __1tbl ) ;

# 1297 "/home/claude/cfront-3/src/expr3.cpp"
if (__3op ){ __1init = __3op ;

# 1297 "/home/claude/cfront-3/src/expr3.cpp"
goto def ;

# 1297 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 1300 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1300 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V134 ;

# 1300 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V135 ;

# 1300 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"badIrT:%t (%tX)", (const struct ea *)( ((&
# 1300 "/home/claude/cfront-3/src/expr3.cpp"
__0__V134 )-> __O1__2ea.p = ((const void *)__1it )), (& __0__V134 )) , (const struct ea *)( ((& __0__V135 )-> __O1__2ea.p =
# 1300 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1p )), (& __0__V135 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
if (__2nc )error__FiPCc ( (int )'c' , (const char *)" (no usable const conversion)\n") ;
else error__FiPCc ( (int )'c' , (const char *)"\n") ;
if (__1init -> base__4node != 85 )__1init -> __O1__4expr.tp = (struct type *)any_type ;
return __1init ;
} 
# 1304 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1304 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 1307 "/home/claude/cfront-3/src/expr3.cpp"
xxx :
# 1316 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1init -> base__4node ){ 
# 1317 "/home/claude/cfront-3/src/expr3.cpp"
case 85 :
# 1318 "/home/claude/cfront-3/src/expr3.cpp"
case 111 :
# 1319 "/home/claude/cfront-3/src/expr3.cpp"
case 44 :
# 1320 "/home/claude/cfront-3/src/expr3.cpp"
case 45 :
# 1321 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1322 "/home/claude/cfront-3/src/expr3.cpp"
bit __3it_isconst ;
bit __3vec_const_save ;
bit __3fct_const_save ;

# 1322 "/home/claude/cfront-3/src/expr3.cpp"
__3it_isconst = tconst__4typeFv ( __1it ) ;
__3vec_const_save = vec_const ;
__3fct_const_save = fct_const ;

# 1326 "/home/claude/cfront-3/src/expr3.cpp"
if (((__1init -> base__4node == 85 )&& ((((struct name *)(((struct name *)__1init ))))-> n_stclass__4name == 13 ))|| ((((__3it_isconst && (((struct basetype *)(((struct basetype *)__1p -> typ__5pvtyp )))))&&
# 1326 "/home/claude/cfront-3/src/expr3.cpp"
(! tconst__4typeFv ( (struct type *)(((struct basetype *)(((struct basetype *)__1p -> typ__5pvtyp ))))) ))&& (__3vec_const_save == 0 ))&& (__3fct_const_save == 0 )))
# 1333 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1334 "/home/claude/cfront-3/src/expr3.cpp"
goto def ;
# 1334 "/home/claude/cfront-3/src/expr3.cpp"

# 1335 "/home/claude/cfront-3/src/expr3.cpp"
}
lval__4exprFUc ( __1init , (unsigned char )112 ) ;

# 1338 "/home/claude/cfront-3/src/expr3.cpp"
if (__3vec_const_save )return __1init ;
if (__3fct_const_save && is_ptr__4typeFv ( __1p1 ) )goto def ;
}

# 1342 "/home/claude/cfront-3/src/expr3.cpp"
case 71 :
# 1343 "/home/claude/cfront-3/src/expr3.cpp"
case 147 :
# 1344 "/home/claude/cfront-3/src/expr3.cpp"
return ptr_init__FP3ptrP4exprP5table ( __1px , address__4exprFv ( __1init ) , __1tbl ) ;
default :
# 1346 "/home/claude/cfront-3/src/expr3.cpp"
def :
# 1347 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1349 "/home/claude/cfront-3/src/expr3.cpp"
if (__1p1 && (__1p1 -> b_const__4type == 0 )){ 
# 1349 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X145 ;

# 1350 "/home/claude/cfront-3/src/expr3.cpp"
if ((__1tbl == gtbl )|| (strict_opt && (! is_arg )))
# 1351 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1351 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V136 ;

# 1351 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"Ir for%snon-constR not an lvalue", (const struct ea *)( (__2__X145 = (const void
# 1351 "/home/claude/cfront-3/src/expr3.cpp"
*)(strict_opt ?"":(((char *)" global ")))), ( ((& __0__V136 )-> __O1__2ea.p =
# 1351 "/home/claude/cfront-3/src/expr3.cpp"
__2__X145 ), (& __0__V136 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 1351 "/home/claude/cfront-3/src/expr3.cpp"
;
} else if (! is_arg )
# 1353 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCc ( (int )'w' , (const char *)"Ir for non-constR not an lvalue (anachronism)")
# 1353 "/home/claude/cfront-3/src/expr3.cpp"
;
}

# 1356 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __3tcl ;

# 1356 "/home/claude/cfront-3/src/expr3.cpp"
__3tcl = is_cl_obj__4typeFv ( __1p1 ) ;
if (__3tcl && (((struct classdef *)(((struct classdef *)__3tcl -> __O1__4expr.tp ))))-> c_abstract__8classdef ){ 
# 1357 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X146 ;

# 1357 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X147 ;

# 1358 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1358 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V137 ;

# 1358 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"a temporary is needed for a parameter, but the AT is abstractC %t.", (const struct ea *)( (__2__X146 = (const void
# 1358 "/home/claude/cfront-3/src/expr3.cpp"
*)__3tcl -> __O1__4expr.tp ), ( ((& __0__V137 )-> __O1__2ea.p = __2__X146 ), (& __0__V137 )) ) , (const struct ea *)ea0 ,
# 1358 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
{ 
# 1359 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V138 ;

# 1359 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V139 ;

# 1359 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'C' , (const char *)"%a is a pure virtualF ofC%t", (const struct ea *)( (__2__X147 =
# 1359 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)(((struct classdef *)(((struct classdef *)__3tcl -> __O1__4expr.tp ))))-> c_abstract__8classdef ), ( ((& __0__V138 )-> __O1__2ea.p = __2__X147 ), (& __0__V138 ))
# 1359 "/home/claude/cfront-3/src/expr3.cpp"
) , (const struct ea *)__ct__2eaFPCv ( & __0__V139 , (const void *)__3tcl -> __O1__4expr.tp ) , (const struct
# 1359 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} } }

# 1362 "/home/claude/cfront-3/src/expr3.cpp"
no_sti = 1 ;
{ Pname __3n ;

# 1363 "/home/claude/cfront-3/src/expr3.cpp"
__3n = make_tmp__FcP4typeP5table ( 'I' , unconst_type__FP4type ( __1p1 ) , __1tbl ) ;
no_sti = 0 ;
assign__4nameFv ( __3n ) ;
if (__1tbl == gtbl )dcl_print__4nameFUc ( __3n , (unsigned char )0 ) ;
{ Pexpr __3a ;
Pname __3ic ;

# 1369 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X148 ;

# 1369 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X149 ;

# 1367 "/home/claude/cfront-3/src/expr3.cpp"
__3a = 0 ;
__3ic = is_cl_obj__4typeFv ( __1init -> __O1__4expr.tp ) ;

# 1370 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1p1 -> base__4node ){ 
# 1371 "/home/claude/cfront-3/src/expr3.cpp"
case 21 :
# 1372 "/home/claude/cfront-3/src/expr3.cpp"
case 5 :
# 1373 "/home/claude/cfront-3/src/expr3.cpp"
case 29 :
# 1374 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1it -> base__4node ){ 
# 1375 "/home/claude/cfront-3/src/expr3.cpp"
case 22 :
# 1376 "/home/claude/cfront-3/src/expr3.cpp"
case 15 :
# 1377 "/home/claude/cfront-3/src/expr3.cpp"
case 11 :
# 1378 "/home/claude/cfront-3/src/expr3.cpp"
case 181 :
# 1379 "/home/claude/cfront-3/src/expr3.cpp"
{
# 1379 "/home/claude/cfront-3/src/expr3.cpp"

# 1379 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V140 ;

# 1379 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V141 ;

# 1379 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%t assigned to %t inRIr", (const struct ea *)( ((&
# 1379 "/home/claude/cfront-3/src/expr3.cpp"
__0__V140 )-> __O1__2ea.p = ((const void *)__1it )), (& __0__V140 )) , (const struct ea *)( ((& __0__V141 )-> __O1__2ea.p =
# 1379 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1p1 )), (& __0__V141 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}

# 1383 "/home/claude/cfront-3/src/expr3.cpp"
if (((__3ic && __1c1 )&& (__3ic != __1c1 ))&& (! ( (__1__X148 = (((struct classdef *)(((struct classdef *)__3ic -> __O1__4expr.tp ))))), (
# 1383 "/home/claude/cfront-3/src/expr3.cpp"
(__1__X149 = (((struct classdef *)(((struct classdef *)__1c1 -> __O1__4expr.tp ))))), ( ((__1__X148 == __1__X149 )?1 :((__1__X148 && __1__X149 )?(((int )same_class__8classdefFP8classdefi ( __1__X148 , __1__X149 , 0 ) )):0 )))
# 1383 "/home/claude/cfront-3/src/expr3.cpp"
) ) )){ 
# 1383 "/home/claude/cfront-3/src/expr3.cpp"
struct texpr *__0__X150 ;

# 1385 "/home/claude/cfront-3/src/expr3.cpp"
__3n -> __O1__4expr.tp = __1init -> __O1__4expr.tp ;
__3a = ptr_init__FP3ptrP4exprP5table ( __1px , address__4exprFv ( (struct expr *)__3n ) , __1tbl ) ;
__1p -> permanent__4node = 1 ;
__3a = (struct expr *)( (__0__X150 = 0 ), ( ((__0__X150 || (__0__X150 = (struct texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr)))
# 1388 "/home/claude/cfront-3/src/expr3.cpp"
))?( (__0__X150 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X150 ), ((unsigned char )191 ), __3a , (struct expr *)0 ) ), (__0__X150 ->
# 1388 "/home/claude/cfront-3/src/expr3.cpp"
__O4__4expr.tp2 = ((struct type *)__1p ))) :0 ), __0__X150 ) ) ;
__3a -> __O1__4expr.tp = (struct type *)__1p ;
}
else 
# 1390 "/home/claude/cfront-3/src/expr3.cpp"
if ((((! __3ic )&& (! __1c1 ))&& is_ptr__4typeFv ( __1init -> __O1__4expr.tp ) )&& is_ptr__4typeFv ( __1p1 ) ){ 
# 1391 "/home/claude/cfront-3/src/expr3.cpp"
Pname __4icx ;
# 1391 "/home/claude/cfront-3/src/expr3.cpp"

# 1392 "/home/claude/cfront-3/src/expr3.cpp"
Pname __4c1x ;

# 1393 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X151 ;

# 1393 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X152 ;

# 1391 "/home/claude/cfront-3/src/expr3.cpp"
__4icx = is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv ( __1init -> __O1__4expr.tp ) ))))-> typ__5pvtyp ) ;
__4c1x = is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv ( __1p1 ) ))))-> typ__5pvtyp ) ;
if (((__4icx && __4c1x )&& (__4icx != __4c1x ))&& (! ( (__1__X151 = (((struct classdef *)(((struct classdef *)__4icx -> __O1__4expr.tp ))))), ( (__1__X152 =
# 1393 "/home/claude/cfront-3/src/expr3.cpp"
(((struct classdef *)(((struct classdef *)__4c1x -> __O1__4expr.tp ))))), ( ((__1__X151 == __1__X152 )?1 :((__1__X151 && __1__X152 )?(((int )same_class__8classdefFP8classdefi ( __1__X151 , __1__X152 , 0 ) )):0 ))) )
# 1393 "/home/claude/cfront-3/src/expr3.cpp"
) )){ 
# 1395 "/home/claude/cfront-3/src/expr3.cpp"
__1init = ptr_init__FP3ptrP4exprP5table ( ((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv ( __1p1 ) ))), __1init , __1tbl ) ;
}
}
if (! __3a )
# 1399 "/home/claude/cfront-3/src/expr3.cpp"
__3a = address__4exprFv ( (struct expr *)__3n ) ;

# 1401 "/home/claude/cfront-3/src/expr3.cpp"
refd = 1 ;
{ Pexpr __3as ;
if (memptr__4typeFv ( __1init -> __O1__4expr.tp ) || ((__1init -> __O1__4expr.tp -> base__4node == 108 )&& (((struct fct *)(((struct fct *)__1init -> __O1__4expr.tp ))))-> memof__3fct ))
# 1406 "/home/claude/cfront-3/src/expr3.cpp"
{
# 1406 "/home/claude/cfront-3/src/expr3.cpp"

# 1407 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __4pit ;

# 1407 "/home/claude/cfront-3/src/expr3.cpp"
__4pit = skiptypedefs__4typeFv ( __1p -> typ__5pvtyp ) ;
__3as = mptr_assign__FP4exprT1 ( (struct expr *)__3n , ptof__FP3fctP4exprP5table ( ((struct fct *)(((struct fct *)__4pit ))), __1init , __1tbl ) ) ;
}
else { 
# 1411 "/home/claude/cfront-3/src/expr3.cpp"
__3as = init_tmp__FP4nameP4exprP5table ( __3n , __1init , __1tbl ) ;
}
refd = 0 ;
__3a = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __3as , __3a ) ;
__3a -> __O1__4expr.tp = __3a -> __O3__4expr.e2 -> __O1__4expr.tp ;
return __3a ;

# 1416 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1416 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1416 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1416 "/home/claude/cfront-3/src/expr3.cpp"
}
}
}

# 1418 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1418 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 1248 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr cast_cptr__FP8classdefP4exprP5tablei (Pclass __0ccl , Pexpr __0ee , Ptable __0tbl , int __0real_cast );

# 715 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 798 "/home/claude/cfront-3/src/cfront.h"
Pexpr typ__4exprFP5table (struct expr *__0this , Ptable );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 1421 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr class_init__FP4exprP4typeT1P5table (Pexpr __1nn , Ptype __1tt , Pexpr __1init , Ptable __1tbl )
# 1427 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1428 "/home/claude/cfront-3/src/expr3.cpp"
if (__1init == dummy )return (struct expr *)0 ;

# 1430 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __1c1 ;

# 1430 "/home/claude/cfront-3/src/expr3.cpp"
__1c1 = is_cl_obj__4typeFv ( __1tt ) ;

# 1432 "/home/claude/cfront-3/src/expr3.cpp"
if (__1init == 0 ){ 
# 1433 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCc ( (const char *)"emptyIr") ;
return dummy ;
}

# 1437 "/home/claude/cfront-3/src/expr3.cpp"
if (__1c1 ){ 
# 1438 "/home/claude/cfront-3/src/expr3.cpp"
Pclass __2cl ;
Pname __2c2 ;

# 1440 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X160 ;

# 1440 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X161 ;

# 1438 "/home/claude/cfront-3/src/expr3.cpp"
__2cl = (((struct classdef *)(((struct classdef *)__1c1 -> __O1__4expr.tp ))));
__2c2 = is_cl_obj__4typeFv ( __1init -> __O1__4expr.tp ) ;

# 1442 "/home/claude/cfront-3/src/expr3.cpp"
if (((__1c1 != __2c2 )&& ((__2c2 == 0 )|| (( (__1__X160 = __2cl ), ( (__1__X161 = (((struct classdef *)(((struct classdef *)__2c2 -> __O1__4expr.tp ))))),
# 1442 "/home/claude/cfront-3/src/expr3.cpp"
( ((__1__X160 == __1__X161 )?1 :((__1__X160 && __1__X161 )?(((int )same_class__8classdefFP8classdefi ( __1__X160 , __1__X161 , 1 ) )):0 ))) ) ) == 0 )))|| ((refd ==
# 1442 "/home/claude/cfront-3/src/expr3.cpp"
0 )&& ( __2cl -> c_itor__8classdef ) ))
# 1444 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1447 "/home/claude/cfront-3/src/expr3.cpp"
int __3i ;

# 1447 "/home/claude/cfront-3/src/expr3.cpp"
__3i = can_coerce__FP4typeT1 ( __1tt , __1init -> __O1__4expr.tp ) ;

# 1449 "/home/claude/cfront-3/src/expr3.cpp"
switch (__3i ){ 
# 1450 "/home/claude/cfront-3/src/expr3.cpp"
default :
# 1451 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1451 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V153 ;

# 1451 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V154 ;

# 1451 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V155 ;

# 1451 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%d ways of making a%n from a%t", (const struct ea *)( (( ((& __0__V153 )->
# 1451 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = ((unsigned long )__3i )), 0 ) ), (& __0__V153 )) , (const struct ea *)( ((& __0__V154 )->
# 1451 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.p = ((const void *)__1c1 )), (& __0__V154 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V155 , (const void
# 1451 "/home/claude/cfront-3/src/expr3.cpp"
*)__1init -> __O1__4expr.tp ) , (const struct ea *)ea0 ) ;
__1init -> __O1__4expr.tp = (struct type *)any_type ;
return __1init ;
case 0 :
# 1455 "/home/claude/cfront-3/src/expr3.cpp"
if (__2c2 && has_base__8classdefFP8classdefiT2 ( ((struct classdef *)(((struct classdef *)__2c2 -> __O1__4expr.tp ))), __2cl , 0 , 0 ) ){ 
# 1456 "/home/claude/cfront-3/src/expr3.cpp"
__1init = address__4exprFv (
# 1456 "/home/claude/cfront-3/src/expr3.cpp"
__1init ) ;
{ Pexpr __5x ;

# 1457 "/home/claude/cfront-3/src/expr3.cpp"
__5x = cast_cptr__FP8classdefP4exprP5tablei ( __2cl , __1init , __1tbl , 0 ) ;

# 1459 "/home/claude/cfront-3/src/expr3.cpp"
if (__5x == __1init ){ 
# 1460 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __6pt ;

# 1461 "/home/claude/cfront-3/src/expr3.cpp"
register struct cast *__0__X162 ;

# 1460 "/home/claude/cfront-3/src/expr3.cpp"
__6pt = (struct type *)( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __1tt ) ) ;
__6pt -> permanent__4node = 1 ;
__5x = (struct expr *)( (__0__X162 = 0 ), ( ((__0__X162 || (__0__X162 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast)))
# 1462 "/home/claude/cfront-3/src/expr3.cpp"
))?( (__0__X162 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X162 ), (unsigned char )191 , __1init , (struct expr *)0 ) ), (__0__X162 ->
# 1462 "/home/claude/cfront-3/src/expr3.cpp"
__O1__4expr.tp = (__0__X162 -> __O4__4expr.tp2 = __6pt ))) :0 ), __0__X162 ) ) ;
}

# 1465 "/home/claude/cfront-3/src/expr3.cpp"
return contents__4exprFv ( __5x ) ;

# 1465 "/home/claude/cfront-3/src/expr3.cpp"
}
}
{ 
# 1467 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V156 ;

# 1467 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V157 ;

# 1467 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot make a%t from a%t", (const struct ea *)( ((& __0__V156 )-> __O1__2ea.p =
# 1467 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__2cl )), (& __0__V156 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V157 , (const void *)__1init ->
# 1467 "/home/claude/cfront-3/src/expr3.cpp"
__O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1init -> __O1__4expr.tp = (struct type *)any_type ;
return __1init ;
case 1 :
# 1472 "/home/claude/cfront-3/src/expr3.cpp"
if (Ncoerce == 0 ){ 
# 1473 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __5a ;

# 1474 "/home/claude/cfront-3/src/expr3.cpp"
struct texpr *__0__X163 ;

# 1474 "/home/claude/cfront-3/src/expr3.cpp"
struct type *__2__X164 ;

# 1473 "/home/claude/cfront-3/src/expr3.cpp"
__5a = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1init , (struct expr *)0 ) ;
__5a = (struct expr *)( (__0__X163 = 0 ), ( (__2__X164 = skiptypedefs__4typeFv ( __1tt ) ), ( ((__0__X163 || (__0__X163 = (struct
# 1474 "/home/claude/cfront-3/src/expr3.cpp"
texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr))) ))?( (__0__X163 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X163 ), ((unsigned char )157 ),
# 1474 "/home/claude/cfront-3/src/expr3.cpp"
__5a , (struct expr *)0 ) ), (__0__X163 -> __O4__4expr.tp2 = __2__X164 )) :0 ), __0__X163 ) ) ) ;
__5a -> __O3__4expr.e2 = __1nn ;
__5a = typ__4exprFP5table ( __5a , __1tbl ) ;

# 1478 "/home/claude/cfront-3/src/expr3.cpp"
return __5a ;
}

# 1481 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1init -> base__4node ){ 
# 1482 "/home/claude/cfront-3/src/expr3.cpp"
case 71 :
# 1483 "/home/claude/cfront-3/src/expr3.cpp"
case 147 :
# 1484 "/home/claude/cfront-3/src/expr3.cpp"
case 85 :
# 1485 "/home/claude/cfront-3/src/expr3.cpp"
case 111 :
# 1486 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1487 "/home/claude/cfront-3/src/expr3.cpp"
Pref __6r ;
Pexpr __6rr ;

# 1489 "/home/claude/cfront-3/src/expr3.cpp"
struct ref *__0__X165 ;

# 1489 "/home/claude/cfront-3/src/expr3.cpp"
struct expr *__2__X166 ;

# 1489 "/home/claude/cfront-3/src/expr3.cpp"
struct expr *__2__X167 ;

# 1487 "/home/claude/cfront-3/src/expr3.cpp"
__6r = ( (__0__X165 = 0 ), ( (__2__X166 = __1init ), ( (__2__X167 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 , Ncoerce ->
# 1487 "/home/claude/cfront-3/src/expr3.cpp"
__O2__4expr.string ) ), ( ((__0__X165 || (__0__X165 = (struct ref *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ref))) ))?( (__0__X165 = (struct
# 1487 "/home/claude/cfront-3/src/expr3.cpp"
ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X165 ), ((unsigned char )45 ), __2__X166 , (struct expr *)0 ) ), (__0__X165 -> __O4__4expr.mem = __2__X167 )) :0 ),
# 1487 "/home/claude/cfront-3/src/expr3.cpp"
__0__X165 ) ) ) ) ;
__6rr = typ__4exprFP5table ( (struct expr *)__6r , __1tbl ) ;
__1init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , __6rr , (struct expr *)0 ) ;
break ;
}
default :
# 1493 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __6tmp ;
int __6x ;

# 1493 "/home/claude/cfront-3/src/expr3.cpp"
__6tmp = make_tmp__FcP4typeP5table ( 'U' , __1init -> __O1__4expr.tp , __1tbl ) ;
__6x = refd ;
refd = 0 ;
{ Pexpr __6ass ;

# 1496 "/home/claude/cfront-3/src/expr3.cpp"
__6ass = init_tmp__FP4nameP4exprP5table ( __6tmp , __1init , __1tbl ) ;
refd = __6x ;
{ Pref __6r ;
Pexpr __6rr ;
Pexpr __6c ;

# 1501 "/home/claude/cfront-3/src/expr3.cpp"
struct ref *__0__X168 ;

# 1501 "/home/claude/cfront-3/src/expr3.cpp"
struct expr *__2__X169 ;

# 1501 "/home/claude/cfront-3/src/expr3.cpp"
struct expr *__2__X170 ;

# 1498 "/home/claude/cfront-3/src/expr3.cpp"
__6r = ( (__0__X168 = 0 ), ( (__2__X169 = (struct expr *)__6tmp ), ( (__2__X170 = (struct expr *)__ct__4nameFPCc ( (struct name *)0 ,
# 1498 "/home/claude/cfront-3/src/expr3.cpp"
Ncoerce -> __O2__4expr.string ) ), ( ((__0__X168 || (__0__X168 = (struct ref *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct ref))) ))?( (__0__X168 =
# 1498 "/home/claude/cfront-3/src/expr3.cpp"
(struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X168 ), ((unsigned char )45 ), __2__X169 , (struct expr *)0 ) ), (__0__X168 -> __O4__4expr.mem = __2__X170 ))
# 1498 "/home/claude/cfront-3/src/expr3.cpp"
:0 ), __0__X168 ) ) ) ) ;
__6rr = typ__4exprFP5table ( (struct expr *)__6r , __1tbl ) ;
__6c = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , __6rr , (struct expr *)0 ) ;
__6c = typ__4exprFP5table ( __6c , __1tbl ) ;
__1init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __6ass , __6c ) ;
__1init -> __O1__4expr.tp = __6c -> __O1__4expr.tp ;
if (refd ){ 
# 1505 "/home/claude/cfront-3/src/expr3.cpp"
Pname __7tmp2 ;

# 1505 "/home/claude/cfront-3/src/expr3.cpp"
__7tmp2 = make_tmp__FcP4typeP5table ( 'L' , __6c -> __O1__4expr.tp , __1tbl ) ;
__6ass = init_tmp__FP4nameP4exprP5table ( __7tmp2 , __1init , __1tbl ) ;
__1init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __6ass , (struct expr *)__7tmp2 ) ;
}

# 1508 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1508 "/home/claude/cfront-3/src/expr3.cpp"
}
}
}

# 1512 "/home/claude/cfront-3/src/expr3.cpp"
if (__1nn ){ 
# 1513 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __5a ;

# 1514 "/home/claude/cfront-3/src/expr3.cpp"
struct texpr *__0__X171 ;

# 1514 "/home/claude/cfront-3/src/expr3.cpp"
struct type *__2__X172 ;

# 1513 "/home/claude/cfront-3/src/expr3.cpp"
__5a = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __1init , (struct expr *)0 ) ;
__5a = (struct expr *)( (__0__X171 = 0 ), ( (__2__X172 = skiptypedefs__4typeFv ( __1tt ) ), ( ((__0__X171 || (__0__X171 = (struct
# 1514 "/home/claude/cfront-3/src/expr3.cpp"
texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr))) ))?( (__0__X171 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X171 ), ((unsigned char )157 ),
# 1514 "/home/claude/cfront-3/src/expr3.cpp"
__5a , (struct expr *)0 ) ), (__0__X171 -> __O4__4expr.tp2 = __2__X172 )) :0 ), __0__X171 ) ) ) ;
__5a -> __O3__4expr.e2 = __1nn ;
return typ__4exprFP5table ( __5a , __1tbl ) ;
}
} } }

# 1520 "/home/claude/cfront-3/src/expr3.cpp"
return typ__4exprFP5table ( __1init , __1tbl ) ;
}
return __1init ;
}

# 1525 "/home/claude/cfront-3/src/expr3.cpp"
if (check__4typeFP4typeUcT2 ( __1tt , __1init -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) && (refd == 0 )){
# 1525 "/home/claude/cfront-3/src/expr3.cpp"

# 1525 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X173 ;

# 1526 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1526 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V158 ;

# 1526 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V159 ;

# 1526 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT:%t (%tX)", (const struct ea *)( (__2__X173 = (const void
# 1526 "/home/claude/cfront-3/src/expr3.cpp"
*)__1init -> __O1__4expr.tp ), ( ((& __0__V158 )-> __O1__2ea.p = __2__X173 ), (& __0__V158 )) ) , (const struct ea *)(
# 1526 "/home/claude/cfront-3/src/expr3.cpp"
((& __0__V159 )-> __O1__2ea.p = ((const void *)__1tt )), (& __0__V159 )) , (const struct ea *)ea0 , (const struct
# 1526 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 ) ;
__1init -> __O1__4expr.tp = (struct type *)any_type ;
} }

# 1530 "/home/claude/cfront-3/src/expr3.cpp"
return __1init ;

# 1530 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 1533 "/home/claude/cfront-3/src/expr3.cpp"
extern int bound ;

# 345 "/home/claude/cfront-3/src/cfront.h"
void dcl__4typeFP5table (struct type *__0this , Ptable );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 848 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 848 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 792 "/home/claude/cfront-3/src/cfront.h"

# 817 "/home/claude/cfront-3/src/cfront.h"

# 1535 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr docast__4exprFP5table (register struct expr *__0this , Ptable __1tbl )
# 1536 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1540 "/home/claude/cfront-3/src/expr3.cpp"
if (__0this -> __O2__4expr.e1 == dummy ){ 
# 1541 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCc ( (const char *)"E missing for cast")
# 1541 "/home/claude/cfront-3/src/expr3.cpp"
;
__0this -> __O1__4expr.tp = (struct type *)any_type ;
return __0this ;
}

# 1546 "/home/claude/cfront-3/src/expr3.cpp"
{ int __1pmf ;
int __1ptom_cast ;
int __1noconst ;
Pexpr __1ee ;

# 1546 "/home/claude/cfront-3/src/expr3.cpp"
__1pmf = 0 ;
__1ptom_cast = 0 ;
__1noconst = 0 ;
__1ee = __0this -> __O2__4expr.e1 ;

# 1552 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1ee -> base__4node ){ 
# 1553 "/home/claude/cfront-3/src/expr3.cpp"
case 112 :
# 1554 "/home/claude/cfront-3/src/expr3.cpp"
__1ee = __1ee -> __O3__4expr.e2 ;
switch (__1ee -> base__4node ){ 
# 1556 "/home/claude/cfront-3/src/expr3.cpp"
case 85 :goto nm ;
case 44 :goto rf ;
}
break ;

# 1561 "/home/claude/cfront-3/src/expr3.cpp"
case 85 :
# 1562 "/home/claude/cfront-3/src/expr3.cpp"
nm :
# 1563 "/home/claude/cfront-3/src/expr3.cpp"
if ((((struct name *)(((struct name *)__1ee ))))-> __O2__4name.n_qualifier )__1pmf = 1 ;
break ;

# 1566 "/home/claude/cfront-3/src/expr3.cpp"
case 44 :
# 1567 "/home/claude/cfront-3/src/expr3.cpp"
rf :
# 1568 "/home/claude/cfront-3/src/expr3.cpp"
if (__1ee -> __O2__4expr.e1 -> base__4node == 34 )bound = 1 ;
break ;
}

# 1572 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;

# 1574 "/home/claude/cfront-3/src/expr3.cpp"
{ int __1b ;

# 1574 "/home/claude/cfront-3/src/expr3.cpp"
__1b = bound ;
bound = 0 ;

# 1577 "/home/claude/cfront-3/src/expr3.cpp"
__1pmf = (__1pmf && (((__0this -> __O2__4expr.e1 -> base__4node == 113 )|| (__0this -> __O2__4expr.e1 -> base__4node == 191 ))|| (__0this -> __O2__4expr.e1 -> base__4node == 124 )));
# 1577 "/home/claude/cfront-3/src/expr3.cpp"

# 1579 "/home/claude/cfront-3/src/expr3.cpp"
{ Ptype __1etp ;
Ptype __1tt ;
Ptype __1t ;

# 1579 "/home/claude/cfront-3/src/expr3.cpp"
__1etp = skiptypedefs__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) ;
__1tt = __0this -> __O4__4expr.tp2 ;
__1t = __1tt ;
dcl__4typeFP5table ( __1tt , __1tbl ) ;

# 1584 "/home/claude/cfront-3/src/expr3.cpp"
__1tt = skiptypedefs__4typeFv ( __1tt ) ;

# 1587 "/home/claude/cfront-3/src/expr3.cpp"
{ bit __1isptm ;

# 1587 "/home/claude/cfront-3/src/expr3.cpp"
__1isptm = 0 ;
switch (__1etp -> base__4node ){ 
# 1589 "/home/claude/cfront-3/src/expr3.cpp"
case 125 :
# 1590 "/home/claude/cfront-3/src/expr3.cpp"
if (! memptr__4typeFv ( __1etp ) )
# 1591 "/home/claude/cfront-3/src/expr3.cpp"
break ;
if (memptr__4typeFv ( __1etp ) -> f_static__3fct )
# 1593 "/home/claude/cfront-3/src/expr3.cpp"
break ;
__1isptm = 1 ;
break ;
case 108 :
# 1597 "/home/claude/cfront-3/src/expr3.cpp"
if (! (((struct fct *)(((struct fct *)__1etp ))))-> memof__3fct )
# 1598 "/home/claude/cfront-3/src/expr3.cpp"
break ;
if ((((struct fct *)(((struct fct *)__1etp ))))-> f_static__3fct )
# 1600 "/home/claude/cfront-3/src/expr3.cpp"
break ;
__1isptm = 1 ;
break ;
case 124 :
# 1604 "/home/claude/cfront-3/src/expr3.cpp"
__1isptm = 1 ;
break ;
}
if ((__1isptm && (! memptr__4typeFv ( __1tt ) ))&& (__1tt -> base__4node != 38 ))
# 1608 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1608 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V174 ;

# 1608 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( strict_opt ?0 :119, (const char *)"cast to%t ofP toM (anachronism)", (const struct ea *)( ((& __0__V174 )->
# 1608 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.p = ((const void *)__1tt )), (& __0__V174 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const
# 1608 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)ea0 ) ;
} 
# 1610 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1etp -> base__4node ){ 
# 1611 "/home/claude/cfront-3/src/expr3.cpp"
case 125 :
# 1612 "/home/claude/cfront-3/src/expr3.cpp"
case 158 :
# 1613 "/home/claude/cfront-3/src/expr3.cpp"
if ((((struct ptr *)(((struct ptr *)__1etp ))))-> typ__5pvtyp -> base__4node == 76 )goto over ;
# 1613 "/home/claude/cfront-3/src/expr3.cpp"

# 1614 "/home/claude/cfront-3/src/expr3.cpp"
if (((((struct ptr *)(((struct ptr *)__1etp ))))-> typ__5pvtyp -> base__4node == 108 )&& (((struct fct *)(((struct fct *)(((struct ptr *)(((struct ptr *)__1etp ))))-> typ__5pvtyp ))))-> fct_base__3fct )
# 1615 "/home/claude/cfront-3/src/expr3.cpp"
goto
# 1615 "/home/claude/cfront-3/src/expr3.cpp"
over ;
if ((warning_opt && (__0this -> __O3__4expr.i2 == 0 ))&& tconst__4typeFv ( (((struct ptr *)(((struct ptr *)__1etp ))))-> typ__5pvtyp ) ){ 
# 1617 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1tt -> base__4node ){
# 1617 "/home/claude/cfront-3/src/expr3.cpp"

# 1617 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X191 ;

# 1618 "/home/claude/cfront-3/src/expr3.cpp"
case 108 :
# 1619 "/home/claude/cfront-3/src/expr3.cpp"
break ;
case 125 :
# 1621 "/home/claude/cfront-3/src/expr3.cpp"
case 158 :
# 1622 "/home/claude/cfront-3/src/expr3.cpp"
if (tconst__4typeFv ( (((struct ptr *)(((struct ptr *)__1tt ))))-> typ__5pvtyp ) )break ;
default :
# 1628 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1628 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V175 ;

# 1628 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V176 ;

# 1628 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"const cast away:%t->%t", (const struct ea *)( (__2__X191 =
# 1628 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)__0this -> __O2__4expr.e1 -> __O1__4expr.tp ), ( ((& __0__V175 )-> __O1__2ea.p = __2__X191 ), (& __0__V175 )) ) ,
# 1628 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)__ct__2eaFPCv ( & __0__V176 , (const void *)__0this -> __O4__4expr.tp2 ) , (const struct ea *)ea0 , (const
# 1628 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)ea0 ) ;
} }
}
else 
# 1632 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O3__4expr.i2 = 0 ;
break ;
case 119 :
# 1635 "/home/claude/cfront-3/src/expr3.cpp"
{ ref_cast = 1 ;
{ Pexpr __3x ;

# 1636 "/home/claude/cfront-3/src/expr3.cpp"
__3x = try_to_coerce__FP4typeP4exprPCcP5table ( __1tt , __0this -> __O2__4expr.e1 , (const char *)"cast", __1tbl ) ;
# 1636 "/home/claude/cfront-3/src/expr3.cpp"

# 1637 "/home/claude/cfront-3/src/expr3.cpp"
if ((! __3x )&& (__1tt -> base__4node == 121 ))
# 1638 "/home/claude/cfront-3/src/expr3.cpp"
__3x = try_to_coerce__FP4typeP4exprPCcP5table ( (struct type *)int_type , __0this -> __O2__4expr.e1 , (const char *)"cast",
# 1638 "/home/claude/cfront-3/src/expr3.cpp"
__1tbl ) ;
__1noconst = no_const ;
ref_cast = 0 ;

# 1642 "/home/claude/cfront-3/src/expr3.cpp"
if (__3x ){ 
# 1642 "/home/claude/cfront-3/src/expr3.cpp"
register struct cast *__0__X192 ;

# 1643 "/home/claude/cfront-3/src/expr3.cpp"
if (((__3x != __0this -> __O2__4expr.e1 )&& (__3x -> base__4node == 111 ))&& is_ref__4typeFv ( __1tt ) )__3x = __3x -> __O2__4expr.e1 ;
if (((__1tt == __3x -> __O1__4expr.tp )|| (check__4typeFP4typeUcT2 ( __1tt , __3x -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 )
# 1644 "/home/claude/cfront-3/src/expr3.cpp"
== 0 ))|| const_problem )
# 1645 "/home/claude/cfront-3/src/expr3.cpp"
return __3x ;
else 
# 1647 "/home/claude/cfront-3/src/expr3.cpp"
return (struct expr *)( (__0__X192 = 0 ), ( ((__0__X192 || (__0__X192 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof
# 1647 "/home/claude/cfront-3/src/expr3.cpp"
(struct cast))) ))?( (__0__X192 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X192 ), (unsigned char )191 , __3x , (struct expr *)0 ) ),
# 1647 "/home/claude/cfront-3/src/expr3.cpp"
(__0__X192 -> __O1__4expr.tp = (__0__X192 -> __O4__4expr.tp2 = __1tt ))) :0 ), __0__X192 ) ) ;
}
break ;

# 1649 "/home/claude/cfront-3/src/expr3.cpp"
}
}
case 38 :
# 1652 "/home/claude/cfront-3/src/expr3.cpp"
if (__1tt -> base__4node == 38 ){ 
# 1653 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O1__4expr.tp = __1t ;
return __0this ;
}
error__FPCc ( (const char *)"cast of void value") ;

# 1658 "/home/claude/cfront-3/src/expr3.cpp"
case 141 :
# 1659 "/home/claude/cfront-3/src/expr3.cpp"
any :
# 1660 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O1__4expr.tp = (struct type *)any_type ;
return __0this ;
case 108 :
# 1663 "/home/claude/cfront-3/src/expr3.cpp"
if ((__1tt -> base__4node == 125 )&& ((((struct ptr *)(((struct ptr *)__1tt ))))-> typ__5pvtyp -> base__4node != 108 ))
# 1664 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCc ( (int )'w' , (const
# 1664 "/home/claude/cfront-3/src/expr3.cpp"
char *)"P toF cast toP to nonF") ;
if ((((struct fct *)(((struct fct *)__1etp ))))-> fct_base__3fct )
# 1666 "/home/claude/cfront-3/src/expr3.cpp"
goto over ;
break ;
case 76 :
# 1669 "/home/claude/cfront-3/src/expr3.cpp"
over :
# 1670 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCc ( (const char *)"cast of overloaded") ;
goto any ;
}

# 1675 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1tt -> base__4node ){ 
# 1676 "/home/claude/cfront-3/src/expr3.cpp"
case 110 :
# 1677 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1677 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V177 ;

# 1677 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"cast to arrayT %t", (const struct ea *)( ((& __0__V177 )-> __O1__2ea.p =
# 1677 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1tt )), (& __0__V177 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1677 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 ) ;
break ;
case 125 :
# 1680 "/home/claude/cfront-3/src/expr3.cpp"
if (memptr__4typeFv ( __1tt ) ){ 
# 1681 "/home/claude/cfront-3/src/expr3.cpp"
if ((memptr__4typeFv ( __1etp ) == 0 )&& ((__1etp -> base__4node != 108 )|| ((((struct
# 1681 "/home/claude/cfront-3/src/expr3.cpp"
fct *)(((struct fct *)__1etp ))))-> memof__3fct == 0 )))
# 1684 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1685 "/home/claude/cfront-3/src/expr3.cpp"
if (__1etp -> base__4node == 138 ){ 
# 1686 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned
# 1686 "/home/claude/cfront-3/src/expr3.cpp"
char )140 , zero , zero ) ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , __0this -> __O2__4expr.e1 , zero ) ;
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = __1tt ;
return __0this -> __O2__4expr.e1 ;
}
{ 
# 1691 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V178 ;

# 1691 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"cast toP toM %t", (const struct ea *)( ((& __0__V178 )-> __O1__2ea.p =
# 1691 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1tt )), (& __0__V178 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1691 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 ) ;
} }
else 
# 1694 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1697 "/home/claude/cfront-3/src/expr3.cpp"
__1ptom_cast = 1 ;
__0this -> __O4__4expr.tp2 = (struct type *)mptr_type ;
}
}

# 1702 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1etp -> base__4node ){ 
# 1703 "/home/claude/cfront-3/src/expr3.cpp"
case 119 :
# 1704 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCc ( (int )'e' , (const char *)"cannot castCO toP")
# 1704 "/home/claude/cfront-3/src/expr3.cpp"
;
if (__1noconst )error__FiPCc ( (int )'c' , (const char *)" (no usable const conversion)\n") ;
else error__FiPCc ( (int )'c' , (const char *)"\n") ;
break ;
case 108 :
# 1709 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )145 , (struct expr *)0 , __0this -> __O2__4expr.e1 ) ;
# 1709 "/home/claude/cfront-3/src/expr3.cpp"

# 1710 "/home/claude/cfront-3/src/expr3.cpp"
bound = __1b ;
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
bound = 0 ;
if ((__0this -> __O2__4expr.e1 -> base__4node == 113 )|| (__0this -> __O2__4expr.e1 -> base__4node == 191 ))
# 1714 "/home/claude/cfront-3/src/expr3.cpp"
__1pmf = 1 ;
else 
# 1716 "/home/claude/cfront-3/src/expr3.cpp"
break ;

# 1719 "/home/claude/cfront-3/src/expr3.cpp"
case 158 :
# 1720 "/home/claude/cfront-3/src/expr3.cpp"
case 125 :
# 1721 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __4cn ;

# 1721 "/home/claude/cfront-3/src/expr3.cpp"
__4cn = is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)__1tt ))))-> typ__5pvtyp ) ;
if (__4cn ){ 
# 1723 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __5x ;

# 1723 "/home/claude/cfront-3/src/expr3.cpp"
__5x = cast_cptr__FP8classdefP4exprP5tablei ( ((struct classdef *)(((struct classdef *)__4cn -> __O1__4expr.tp ))), __0this -> __O2__4expr.e1 , __1tbl , (__0this -> base__4node == 113 )?1 :0 ) ;

# 1725 "/home/claude/cfront-3/src/expr3.cpp"
if (__5x == __0this -> __O2__4expr.e1 ){ 
# 1725 "/home/claude/cfront-3/src/expr3.cpp"
register struct cast *__0__X193 ;

# 1725 "/home/claude/cfront-3/src/expr3.cpp"
struct expr *__2__X194 ;

# 1726 "/home/claude/cfront-3/src/expr3.cpp"
__1tt -> permanent__4node = 1 ;
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X193 = 0 ), ( (__2__X194 = __0this -> __O2__4expr.e1 ), ( ((__0__X193 || (__0__X193 = (struct
# 1727 "/home/claude/cfront-3/src/expr3.cpp"
cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X193 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X193 ), (unsigned char )191 ,
# 1727 "/home/claude/cfront-3/src/expr3.cpp"
__2__X194 , (struct expr *)0 ) ), (__0__X193 -> __O1__4expr.tp = (__0__X193 -> __O4__4expr.tp2 = __1tt ))) :0 ), __0__X193 ) ) ) ;
# 1727 "/home/claude/cfront-3/src/expr3.cpp"

# 1728 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 -> __O3__4expr.i2 = __0this -> __O3__4expr.i2 ;
}
else 
# 1731 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = __5x ;
}
if (__1pmf ){ 
# 1734 "/home/claude/cfront-3/src/expr3.cpp"
__1tt = skiptypedefs__4typeFv ( __1tt ) ;

# 1736 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1tt -> base__4node ){ 
# 1736 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X195 ;

# 1737 "/home/claude/cfront-3/src/expr3.cpp"
case 125 :
# 1738 "/home/claude/cfront-3/src/expr3.cpp"
if ((((struct ptr *)(((struct ptr *)__1tt ))))-> memof__3ptr )break ;
default :
# 1740 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1740 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V179 ;

# 1740 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V180 ;

# 1740 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V181 ;

# 1740 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t cast to%t (%t is not aP toM)", (const struct ea *)( (__2__X195 = (const void
# 1740 "/home/claude/cfront-3/src/expr3.cpp"
*)__0this -> __O2__4expr.e1 -> __O1__4expr.tp ), ( ((& __0__V179 )-> __O1__2ea.p = __2__X195 ), (& __0__V179 )) ) , (const struct
# 1740 "/home/claude/cfront-3/src/expr3.cpp"
ea *)__ct__2eaFPCv ( & __0__V180 , (const void *)__0this -> __O4__4expr.tp2 ) , (const struct ea *)__ct__2eaFPCv ( & __0__V181 , (const
# 1740 "/home/claude/cfront-3/src/expr3.cpp"
void *)__0this -> __O4__4expr.tp2 ) , (const struct ea *)ea0 ) ;
} }
}
}
}
break ;

# 1747 "/home/claude/cfront-3/src/expr3.cpp"
case 158 :
# 1748 "/home/claude/cfront-3/src/expr3.cpp"
{ Ptype __3er ;
Ptype __3cr ;

# 1748 "/home/claude/cfront-3/src/expr3.cpp"
__3er = __1etp ;
__3cr = __1tt ;
do { 
# 1751 "/home/claude/cfront-3/src/expr3.cpp"
if (__3er = (struct type *)is_ptr_or_ref__4typeFv ( __3er ) )__3er = (((struct ptr *)(((struct ptr *)__3er ))))-> typ__5pvtyp ;
if (__3cr = (struct type *)is_ptr_or_ref__4typeFv ( __3cr ) )__3cr = (((struct ptr *)(((struct ptr *)__3cr ))))-> typ__5pvtyp ;
}
while (__3er && __3cr );

# 1754 "/home/claude/cfront-3/src/expr3.cpp"
{ int __3pp ;

# 1754 "/home/claude/cfront-3/src/expr3.cpp"
__3pp = (__3er != 0 );

# 1758 "/home/claude/cfront-3/src/expr3.cpp"
if ((((__0this -> __O2__4expr.e1 -> base__4node == 147 )|| (__0this -> __O2__4expr.e1 -> base__4node == 109 ))|| (__0this -> __O2__4expr.e1 -> base__4node == 146 ))|| lval__4exprFUc (
# 1758 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 , (unsigned char )0 ) )
# 1762 "/home/claude/cfront-3/src/expr3.cpp"
;
else if (tconst__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) ){ 
# 1763 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X196 ;

# 1768 "/home/claude/cfront-3/src/expr3.cpp"
if (warning_opt && (tconst__4typeFv ( (((struct ptr *)(((struct ptr *)__1tt ))))-> typ__5pvtyp ) == 0 ))
# 1769 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1769 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V182 ;

# 1769 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V183 ;

# 1769 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"const cast away:%t->%t", (const struct ea *)( (__2__X196 =
# 1769 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)__0this -> __O2__4expr.e1 -> __O1__4expr.tp ), ( ((& __0__V182 )-> __O1__2ea.p = __2__X196 ), (& __0__V182 )) ) ,
# 1769 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)__ct__2eaFPCv ( & __0__V183 , (const void *)__0this -> __O4__4expr.tp2 ) , (const struct ea *)ea0 , (const
# 1769 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)ea0 ) ;
} 
# 1771 "/home/claude/cfront-3/src/expr3.cpp"
}
else 
# 1773 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1773 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V184 ;

# 1773 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V185 ;

# 1773 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot cast%t to%t", (const struct ea *)( ((& __0__V184 )-> __O1__2ea.p =
# 1773 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1etp )), (& __0__V184 )) , (const struct ea *)( ((& __0__V185 )-> __O1__2ea.p = ((const void
# 1773 "/home/claude/cfront-3/src/expr3.cpp"
*)__1t )), (& __0__V185 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1775 "/home/claude/cfront-3/src/expr3.cpp"
if (__3pp == 0 )__0this -> __O2__4expr.e1 = address__4exprFv ( __0this -> __O2__4expr.e1 ) ;
__0this -> __O1__4expr.tp = __1t ;

# 1779 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __3cn ;

# 1779 "/home/claude/cfront-3/src/expr3.cpp"
__3cn = is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)__1tt ))))-> typ__5pvtyp ) ;
if (__3cn ){ 
# 1781 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __4x ;

# 1781 "/home/claude/cfront-3/src/expr3.cpp"
__4x = cast_cptr__FP8classdefP4exprP5tablei ( ((struct classdef *)(((struct classdef *)__3cn -> __O1__4expr.tp ))), __0this -> __O2__4expr.e1 , __1tbl , (__0this -> base__4node == 113 )?1 :0 ) ;

# 1783 "/home/claude/cfront-3/src/expr3.cpp"
if (__4x == __0this -> __O2__4expr.e1 ){ 
# 1783 "/home/claude/cfront-3/src/expr3.cpp"
register struct cast *__0__X197 ;

# 1783 "/home/claude/cfront-3/src/expr3.cpp"
struct expr *__2__X198 ;

# 1784 "/home/claude/cfront-3/src/expr3.cpp"
__1tt -> permanent__4node = 1 ;
__0this -> __O2__4expr.e1 = (struct expr *)( (__0__X197 = 0 ), ( (__2__X198 = __0this -> __O2__4expr.e1 ), ( ((__0__X197 || (__0__X197 = (struct
# 1785 "/home/claude/cfront-3/src/expr3.cpp"
cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast))) ))?( (__0__X197 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X197 ), (unsigned char )191 ,
# 1785 "/home/claude/cfront-3/src/expr3.cpp"
__2__X198 , (struct expr *)0 ) ), (__0__X197 -> __O1__4expr.tp = (__0__X197 -> __O4__4expr.tp2 = __1tt ))) :0 ), __0__X197 ) ) ) ;
# 1785 "/home/claude/cfront-3/src/expr3.cpp"

# 1786 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 -> __O3__4expr.i2 = __0this -> __O3__4expr.i2 ;
}
else 
# 1789 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = __4x ;
}

# 1792 "/home/claude/cfront-3/src/expr3.cpp"
return (__3pp ?__0this :contents__4exprFv ( __0this ) );

# 1792 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1792 "/home/claude/cfront-3/src/expr3.cpp"
}
}
case 119 :
# 1795 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> base__4node = 157 ;
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , __0this -> __O2__4expr.e1 , (struct expr *)0 ) ;
return typ__4exprFP5table ( __0this , __1tbl ) ;

# 1799 "/home/claude/cfront-3/src/expr3.cpp"
case 5 :
# 1800 "/home/claude/cfront-3/src/expr3.cpp"
case 21 :
# 1801 "/home/claude/cfront-3/src/expr3.cpp"
case 29 :
# 1802 "/home/claude/cfront-3/src/expr3.cpp"
case 22 :
# 1803 "/home/claude/cfront-3/src/expr3.cpp"
case 121 :
# 1804 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1etp -> base__4node ){ 
# 1804 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X199 ;

# 1805 "/home/claude/cfront-3/src/expr3.cpp"
case 108 :
# 1806 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )112 , (struct expr *)0 , __0this -> __O2__4expr.e1 ) ;
# 1806 "/home/claude/cfront-3/src/expr3.cpp"

# 1807 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 , __1tbl ) ;
case 125 :
# 1809 "/home/claude/cfront-3/src/expr3.cpp"
if ((! memptr__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) )&& (tsizeof__4typeFi ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp , 0 ) >
# 1809 "/home/claude/cfront-3/src/expr3.cpp"
tsizeof__4typeFi ( __1tt , 0 ) ))
# 1810 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1810 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V186 ;

# 1810 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V187 ;

# 1810 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"type ``%t'' not large enough for values of ``%t ''", (const struct ea *)( ((& __0__V186 )-> __O1__2ea.p =
# 1810 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1tt )), (& __0__V186 )) , (const struct ea *)( ((& __0__V187 )-> __O1__2ea.p = ((const void
# 1810 "/home/claude/cfront-3/src/expr3.cpp"
*)__1etp )), (& __0__V187 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} break ;
case 119 :
# 1813 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1813 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V188 ;

# 1813 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'e' , (const char *)"cannot castCO to%k", (const struct ea *)( (__2__X199 =
# 1813 "/home/claude/cfront-3/src/expr3.cpp"
__1tt -> base__4node ), ( (( ((& __0__V188 )-> __O1__2ea.i = __2__X199 ), 0 ) ), (& __0__V188 )) ) ,
# 1813 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
if (__1noconst )error__FiPCc ( (int )'c' , (const char *)" (no usable const conversion)\n") ;
else error__FiPCc ( (int )'c' , (const char *)"\n") ;
break ;
} }
break ;

# 1820 "/home/claude/cfront-3/src/expr3.cpp"
case 15 :
# 1821 "/home/claude/cfront-3/src/expr3.cpp"
case 11 :
# 1822 "/home/claude/cfront-3/src/expr3.cpp"
case 181 :
# 1823 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1etp -> base__4node ){ 
# 1824 "/home/claude/cfront-3/src/expr3.cpp"
case 15 :
# 1825 "/home/claude/cfront-3/src/expr3.cpp"
case 11 :
# 1826 "/home/claude/cfront-3/src/expr3.cpp"
case 181 :
# 1827 "/home/claude/cfront-3/src/expr3.cpp"
case 5 :
# 1828 "/home/claude/cfront-3/src/expr3.cpp"
case 21 :
# 1829 "/home/claude/cfront-3/src/expr3.cpp"
case 29 :
# 1830 "/home/claude/cfront-3/src/expr3.cpp"
case 22 :
# 1831 "/home/claude/cfront-3/src/expr3.cpp"
case
# 1831 "/home/claude/cfront-3/src/expr3.cpp"
121 :
# 1832 "/home/claude/cfront-3/src/expr3.cpp"
case 138 :
# 1833 "/home/claude/cfront-3/src/expr3.cpp"
break ;
default :
# 1835 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1835 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V189 ;

# 1835 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V190 ;

# 1835 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot cast ``%t '' to ``%t''", (const struct ea *)( ((& __0__V189 )-> __O1__2ea.p =
# 1835 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1etp )), (& __0__V189 )) , (const struct ea *)( ((& __0__V190 )-> __O1__2ea.p = ((const void
# 1835 "/home/claude/cfront-3/src/expr3.cpp"
*)__1tt )), (& __0__V190 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
} }
break ;

# 1840 "/home/claude/cfront-3/src/expr3.cpp"
case 108 :
# 1841 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCc ( (const char *)"cannot cast toFT") ;
break ;
} }

# 1845 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O1__4expr.tp = __1t ;

# 1847 "/home/claude/cfront-3/src/expr3.cpp"
if ((__0this -> __O2__4expr.e1 -> base__4node == 124 )&& (__1ptom_cast == 0 )){ 
# 1848 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __2ee ;
int __2i ;

# 1848 "/home/claude/cfront-3/src/expr3.cpp"
__2ee = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 ;

# 1850 "/home/claude/cfront-3/src/expr3.cpp"
switch (__2ee -> __O3__4expr.e2 -> base__4node ){ 
# 1851 "/home/claude/cfront-3/src/expr3.cpp"
case 150 :
# 1852 "/home/claude/cfront-3/src/expr3.cpp"
__2i = (((int )__2ee -> __O3__4expr.e2 -> __O2__4expr.i1 ));
break ;
case 86 :
# 1855 "/home/claude/cfront-3/src/expr3.cpp"
__2i = 0 ;
}

# 1858 "/home/claude/cfront-3/src/expr3.cpp"
if (__2i < 0 )
# 1859 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = __0this -> __O2__4expr.e1 -> __O3__4expr.e2 ;
else 
# 1861 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = __2ee -> __O3__4expr.e2 ;
return __0this ;
}

# 1865 "/home/claude/cfront-3/src/expr3.cpp"
if (memptr__4typeFv ( __1etp ) ){ 
# 1866 "/home/claude/cfront-3/src/expr3.cpp"
Pclass __2cl ;

# 1866 "/home/claude/cfront-3/src/expr3.cpp"
__2cl = (((struct ptr *)(((struct ptr *)__1etp ))))-> memof__3ptr ;

# 1868 "/home/claude/cfront-3/src/expr3.cpp"
if (((((struct ptr *)(((struct ptr *)__1tt ))))-> memof__3ptr == 0 )&& (__1b == 0 )){ 
# 1869 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __3y ;

# 1870 "/home/claude/cfront-3/src/expr3.cpp"
register struct cast *__0__X202 ;

# 1870 "/home/claude/cfront-3/src/expr3.cpp"
if (((__0this -> __O2__4expr.e1 -> base__4node == 191 )|| (__0this -> __O2__4expr.e1 -> base__4node == 113 ))&& (__0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> base__4node == 124 ))
# 1871 "/home/claude/cfront-3/src/expr3.cpp"
{
# 1871 "/home/claude/cfront-3/src/expr3.cpp"

# 1872 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 ;
__3y = __0this -> __O2__4expr.e1 -> __O3__4expr.e2 ;
}
else { 
# 1875 "/home/claude/cfront-3/src/expr3.cpp"
register struct mdot *__0__X200 ;

# 1875 "/home/claude/cfront-3/src/expr3.cpp"
struct expr *__2__X201 ;

# 1876 "/home/claude/cfront-3/src/expr3.cpp"
__3y = (struct expr *)( (__0__X200 = 0 ), ( (__2__X201 = __0this -> __O2__4expr.e1 ), ( ((__0__X200 || (__0__X200 = (struct mdot *)__nw__4exprSFUl (
# 1876 "/home/claude/cfront-3/src/expr3.cpp"
(unsigned long )(sizeof (struct mdot))) ))?( (__0__X200 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X200 ), (unsigned char )177 , (struct
# 1876 "/home/claude/cfront-3/src/expr3.cpp"
expr *)0 , (struct expr *)0 ) ), ( (__0__X200 -> __O3__4expr.string2 = ((const char *)"f")),
# 1876 "/home/claude/cfront-3/src/expr3.cpp"
(__0__X200 -> __O4__4expr.mem = __2__X201 )) ) :0 ), __0__X200 ) ) ) ;
__3y -> __O2__4expr.i1 = 9 ;
}
__3y = (struct expr *)( (__0__X202 = 0 ), ( ((__0__X202 || (__0__X202 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast)))
# 1879 "/home/claude/cfront-3/src/expr3.cpp"
))?( (__0__X202 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X202 ), (unsigned char )191 , __3y , (struct expr *)0 ) ), (__0__X202 ->
# 1879 "/home/claude/cfront-3/src/expr3.cpp"
__O1__4expr.tp = (__0__X202 -> __O4__4expr.tp2 = __1tt ))) :0 ), __0__X202 ) ) ;
if (__2cl -> virt_count__8classdef && (__1b == 0 )){ 
# 1882 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __4z ;
Pexpr __4x ;

# 1884 "/home/claude/cfront-3/src/expr3.cpp"
register struct cast *__0__X203 ;

# 1884 "/home/claude/cfront-3/src/expr3.cpp"
register struct mdot *__0__X204 ;

# 1884 "/home/claude/cfront-3/src/expr3.cpp"
struct expr *__2__X205 ;

# 1884 "/home/claude/cfront-3/src/expr3.cpp"
register struct mdot *__0__X206 ;

# 1884 "/home/claude/cfront-3/src/expr3.cpp"
struct expr *__2__X207 ;

# 1882 "/home/claude/cfront-3/src/expr3.cpp"
__4z = (struct expr *)( (__0__X204 = 0 ), ( (__2__X205 = __0this -> __O2__4expr.e1 ), ( ((__0__X204 || (__0__X204 = (struct mdot *)__nw__4exprSFUl (
# 1882 "/home/claude/cfront-3/src/expr3.cpp"
(unsigned long )(sizeof (struct mdot))) ))?( (__0__X204 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X204 ), (unsigned char )177 , (struct
# 1882 "/home/claude/cfront-3/src/expr3.cpp"
expr *)0 , (struct expr *)0 ) ), ( (__0__X204 -> __O3__4expr.string2 = ((const char *)"i")),
# 1882 "/home/claude/cfront-3/src/expr3.cpp"
(__0__X204 -> __O4__4expr.mem = __2__X205 )) ) :0 ), __0__X204 ) ) ) ;
__4x = (struct expr *)( (__0__X206 = 0 ), ( (__2__X207 = __0this -> __O2__4expr.e1 ), ( ((__0__X206 || (__0__X206 = (struct mdot *)__nw__4exprSFUl (
# 1883 "/home/claude/cfront-3/src/expr3.cpp"
(unsigned long )(sizeof (struct mdot))) ))?( (__0__X206 = (struct mdot *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X206 ), (unsigned char )177 , (struct
# 1883 "/home/claude/cfront-3/src/expr3.cpp"
expr *)0 , (struct expr *)0 ) ), ( (__0__X206 -> __O3__4expr.string2 = ((const char *)"i")),
# 1883 "/home/claude/cfront-3/src/expr3.cpp"
(__0__X206 -> __O4__4expr.mem = __2__X207 )) ) :0 ), __0__X206 ) ) ) ;
__4x -> __O2__4expr.i1 = 9 ;
__4x = (struct expr *)( (__0__X203 = 0 ), ( ((__0__X203 || (__0__X203 = (struct cast *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct cast)))
# 1885 "/home/claude/cfront-3/src/expr3.cpp"
))?( (__0__X203 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X203 ), (unsigned char )191 , __4x , (struct expr *)0 ) ), (__0__X203 ->
# 1885 "/home/claude/cfront-3/src/expr3.cpp"
__O1__4expr.tp = (__0__X203 -> __O4__4expr.tp2 = __1tt ))) :0 ), __0__X203 ) ) ;
__4z -> __O2__4expr.i1 = 9 ;
{ Pexpr __4q ;

# 1887 "/home/claude/cfront-3/src/expr3.cpp"
__4q = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )68 , __4x , __3y ) ;
__4q -> __O4__4expr.cond = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )59 , zero , __4z ) ;
__4q -> __O1__4expr.tp = __1tt ;
( (__0this ?(((void )(__0this ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 1890 "/home/claude/cfront-3/src/expr3.cpp"
;
return __4q ;

# 1891 "/home/claude/cfront-3/src/expr3.cpp"
}
}
( (__0this ?(((void )(__0this ?(((void )(((void )__dl__4exprSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct expr))) )))):(((void )0 ))))):(((void )0 ))))
# 1893 "/home/claude/cfront-3/src/expr3.cpp"
;
return __3y ;
}
}

# 1898 "/home/claude/cfront-3/src/expr3.cpp"
return __0this ;

# 1898 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1898 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1898 "/home/claude/cfront-3/src/expr3.cpp"
}

# 1898 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 466 "/home/claude/cfront-3/src/cfront.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 509 "/home/claude/cfront-3/src/cfront.h"
void clear__5clistFv (struct clist *__0this );

# 1241 "/home/claude/cfront-3/src/cfront.h"
extern int is_unique_base__FP8classdefPCciT3T1 (Pclass , const char *, int , int , Pclass __0priSeen );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 828 "/home/claude/cfront-3/src/cfront.h"

# 1901 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr dovalue__4exprFP5table (register struct expr *__0this , Ptable __1tbl )
# 1902 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1903 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __1tt ;
Pclass __1cl ;
Pname __1cn ;

# 1903 "/home/claude/cfront-3/src/expr3.cpp"
__1tt = __0this -> __O4__4expr.tp2 ;

# 1909 "/home/claude/cfront-3/src/expr3.cpp"
dcl__4typeFP5table ( __1tt , __1tbl ) ;

# 1911 "/home/claude/cfront-3/src/expr3.cpp"
__1tt = skiptypedefs__4typeFv ( __1tt ) ;

# 1913 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1tt -> base__4node ){ 
# 1914 "/home/claude/cfront-3/src/expr3.cpp"
case 121 :
# 1915 "/home/claude/cfront-3/src/expr3.cpp"
default :
# 1916 "/home/claude/cfront-3/src/expr3.cpp"
if (__0this -> __O2__4expr.e1 == 0 ){ 
# 1918 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = zero ;
}
else 
# 1919 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1920 "/home/claude/cfront-3/src/expr3.cpp"
if (__0this -> __O2__4expr.e1 -> __O3__4expr.e2 == 0 ){ 
# 1921 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 ;
if ((__0this -> __O2__4expr.e1 -> base__4node == 85 )&& (__0this -> __O2__4expr.e1 -> permanent__4node == 0 ))
# 1923 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O2__4expr.e1 -> permanent__4node = 1 ;
}
else { 
# 1926 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCc ( (const char *)"more than oneA for basicTK") ;
{ Pexpr __4e ;

# 1927 "/home/claude/cfront-3/src/expr3.cpp"
__4e = __0this -> __O2__4expr.e1 ;
for(;__4e -> __O3__4expr.e2 -> __O3__4expr.e2 ;__4e = __4e -> __O3__4expr.e2 ) 
# 1929 "/home/claude/cfront-3/src/expr3.cpp"
__4e -> base__4node = 71 ;
__4e -> base__4node = 71 ;
__4e -> __O3__4expr.e2 = __4e -> __O3__4expr.e2 -> __O2__4expr.e1 ;

# 1931 "/home/claude/cfront-3/src/expr3.cpp"
}
}
}
__0this -> base__4node = 191 ;
return typ__4exprFP5table ( __0this , __1tbl ) ;

# 1937 "/home/claude/cfront-3/src/expr3.cpp"
case 6 :
# 1938 "/home/claude/cfront-3/src/expr3.cpp"
__1cl = (((struct classdef *)(((struct classdef *)__1tt ))));
if (__1cl -> this_type__8classdef )
# 1940 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O4__4expr.tp2 = (((struct ptr *)(((struct ptr *)__1cl -> this_type__8classdef ))))-> typ__5pvtyp ;
break ;

# 1943 "/home/claude/cfront-3/src/expr3.cpp"
case 119 :
# 1944 "/home/claude/cfront-3/src/expr3.cpp"
__1cn = (((struct basetype *)(((struct basetype *)__1tt ))))-> b_name__8basetype ;
__1cl = (((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))));
}

# 1948 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __1ctor ;

# 1948 "/home/claude/cfront-3/src/expr3.cpp"
__1ctor = ( __1cl -> c_ctor__8classdef ) ;

# 1951 "/home/claude/cfront-3/src/expr3.cpp"
if (__0this -> __O2__4expr.e1 && (__0this -> __O2__4expr.e1 -> __O3__4expr.e2 == 0 )){ 
# 1952 "/home/claude/cfront-3/src/expr3.cpp"
if (__0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> base__4node == 140 )__0this -> __O2__4expr.e1 ->
# 1952 "/home/claude/cfront-3/src/expr3.cpp"
__O2__4expr.e1 = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O2__4expr.e1 ;
__0this -> __O2__4expr.e1 -> __O2__4expr.e1 = typ__4exprFP5table ( __0this -> __O2__4expr.e1 -> __O2__4expr.e1 , __1tbl ) ;
if (__1tt -> base__4node == 119 ){ 
# 1955 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __3x ;

# 1955 "/home/claude/cfront-3/src/expr3.cpp"
__3x = try_to_coerce__FP4typeP4exprPCcP5table ( __1tt , __0this -> __O2__4expr.e1 -> __O2__4expr.e1 , (const char *)"type conversion", __1tbl )
# 1955 "/home/claude/cfront-3/src/expr3.cpp"
;
if (( __1cl -> c_itor__8classdef ) == 0 ){ 
# 1957 "/home/claude/cfront-3/src/expr3.cpp"
if (__3x )
# 1958 "/home/claude/cfront-3/src/expr3.cpp"
return __3x ;
}
else { 
# 1961 "/home/claude/cfront-3/src/expr3.cpp"
if (__3x && (__3x -> base__4node != 111 ))
# 1962 "/home/claude/cfront-3/src/expr3.cpp"
return __3x ;
}
}

# 1966 "/home/claude/cfront-3/src/expr3.cpp"
{ Pname __2acn ;

# 1966 "/home/claude/cfront-3/src/expr3.cpp"
__2acn = is_cl_obj__4typeFv ( __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ) ;

# 1968 "/home/claude/cfront-3/src/expr3.cpp"
if (__2acn && (( __1cl -> c_itor__8classdef ) == 0 )){ 
# 1969 "/home/claude/cfront-3/src/expr3.cpp"
Pclass __3acl ;
int __3hb ;

# 1971 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X210 ;

# 1971 "/home/claude/cfront-3/src/expr3.cpp"
struct classdef *__1__X211 ;

# 1969 "/home/claude/cfront-3/src/expr3.cpp"
__3acl = (((struct classdef *)(((struct classdef *)__2acn -> __O1__4expr.tp ))));
__3hb = has_base__8classdefFP8classdefiT2 ( __3acl , __1cl , 0 , 0 ) ;

# 1973 "/home/claude/cfront-3/src/expr3.cpp"
if (__1ctor && __3hb ){ 
# 1974 "/home/claude/cfront-3/src/expr3.cpp"
Pname __4n ;

# 1974 "/home/claude/cfront-3/src/expr3.cpp"
__4n = 0 ;
switch (__1ctor -> __O1__4expr.tp -> base__4node ){ 
# 1976 "/home/claude/cfront-3/src/expr3.cpp"
case 76 :
# 1977 "/home/claude/cfront-3/src/expr3.cpp"
__4n = exactMatch__3genFP4expri ( ((struct gen *)(((struct gen *)__1ctor -> __O1__4expr.tp ))), __0this -> __O2__4expr.e1 , 0 )
# 1977 "/home/claude/cfront-3/src/expr3.cpp"
;
if (__4n )__1ctor = __4n ;
break ;
case 108 :
# 1981 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 1982 "/home/claude/cfront-3/src/expr3.cpp"
Pfct __6f ;

# 1982 "/home/claude/cfront-3/src/expr3.cpp"
__6f = (((struct fct *)(((struct fct *)__1ctor -> __O1__4expr.tp ))));
if (__6f -> nargs__3fct != 1 )break ;
__4n = (exact1__FP4nameP4type ( __6f -> argtype__3fct , __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp ) ?__1ctor :(((struct name *)0 )));
break ;
}
}
if (__4n )goto mk_ctor_call ;
}

# 1991 "/home/claude/cfront-3/src/expr3.cpp"
if (( (__1__X210 = __3acl ), ( (__1__X211 = __1cl ), ( ((__1__X210 == __1__X211 )?1 :((__1__X210 && __1__X211 )?(((int )same_class__8classdefFP8classdefi ( __1__X210 , __1__X211 ,
# 1991 "/home/claude/cfront-3/src/expr3.cpp"
0 ) )):0 ))) ) ) || __3hb ){ 
# 1992 "/home/claude/cfront-3/src/expr3.cpp"
clear__5clistFv ( vcllist ) ;
vcllist = 0 ;
if (1 < is_unique_base__FP8classdefPCciT3T1 ( __3acl , __1cl -> string__8classdef , 0 , 0 , (struct classdef *)0 ) ){ 
# 1994 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V208 ;

# 1994 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"ambiguous assignment to base %t", (const struct ea *)( ((& __0__V208 )-> __O1__2ea.p =
# 1994 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1cl )), (& __0__V208 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1994 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 ) ;
} { Pexpr __4ee ;

# 1995 "/home/claude/cfront-3/src/expr3.cpp"
__4ee = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 ;
if (__4ee -> base__4node == 140 )__4ee = __4ee -> __O2__4expr.e1 ;
if (__3hb ){ 
# 1997 "/home/claude/cfront-3/src/expr3.cpp"
struct texpr *__0__X212 ;

# 1997 "/home/claude/cfront-3/src/expr3.cpp"
struct type *__2__X213 ;

# 2000 "/home/claude/cfront-3/src/expr3.cpp"
ignore_const ++ ;
if (lval__4exprFUc ( __4ee , (unsigned char )0 ) == 0 ){ 
# 2002 "/home/claude/cfront-3/src/expr3.cpp"
Pname __6tmp ;

# 2002 "/home/claude/cfront-3/src/expr3.cpp"
__6tmp = make_tmp__FcP4typeP5table ( 'T' , __4ee -> __O1__4expr.tp , __1tbl ) ;
__4ee = init_tmp__FP4nameP4exprP5table ( __6tmp , __4ee , __1tbl ) ;
__4ee = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __4ee , address__4exprFv ( (struct expr *)__6tmp ) ) ;
}
else 
# 2007 "/home/claude/cfront-3/src/expr3.cpp"
__4ee = address__4exprFv ( __4ee ) ;
ignore_const -- ;
__4ee = (struct expr *)( (__0__X212 = 0 ), ( (__2__X213 = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 ,
# 2009 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> __O4__4expr.tp2 ) ), ( ((__0__X212 || (__0__X212 = (struct texpr *)__nw__4exprSFUl ( (unsigned long )(sizeof (struct texpr))) ))?( (__0__X212 =
# 2009 "/home/claude/cfront-3/src/expr3.cpp"
(struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X212 ), ((unsigned char )191 ), __4ee , (struct expr *)0 ) ), (__0__X212 -> __O4__4expr.tp2 = __2__X213 ))
# 2009 "/home/claude/cfront-3/src/expr3.cpp"
:0 ), __0__X212 ) ) ) ;
__4ee = contents__4exprFv ( __4ee ) ;
typ__4exprFP5table ( __4ee , __1tbl ) ;
}

# 2014 "/home/claude/cfront-3/src/expr3.cpp"
if (__0this -> __O3__4expr.e2 ){ 
# 2015 "/home/claude/cfront-3/src/expr3.cpp"
__0this -> base__4node = 70 ;
__0this -> __O2__4expr.e1 = __0this -> __O3__4expr.e2 ;
__0this -> __O3__4expr.e2 = __4ee ;
__0this -> __O1__4expr.tp = __0this -> __O4__4expr.tp2 ;
return __0this ;
}
return __4ee ;

# 2021 "/home/claude/cfront-3/src/expr3.cpp"
}
}
}

# 2023 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2028 "/home/claude/cfront-3/src/expr3.cpp"
if (__1ctor == 0 ){ 
# 2029 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2029 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V209 ;

# 2029 "/home/claude/cfront-3/src/expr3.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot make a%t", (const struct ea *)( ((& __0__V209 )-> __O1__2ea.p =
# 2029 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1cl )), (& __0__V209 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2029 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 ) ;
return dummy ;
} }

# 2034 "/home/claude/cfront-3/src/expr3.cpp"
mk_ctor_call :
# 2036 "/home/claude/cfront-3/src/expr3.cpp"
if (__0this -> __O3__4expr.e2 == 0 ){ 
# 2037 "/home/claude/cfront-3/src/expr3.cpp"
if ((__0this -> __O2__4expr.e1 && __0this -> __O2__4expr.e1 -> __O2__4expr.e1 )&& (! __0this -> __O2__4expr.e1 ->
# 2037 "/home/claude/cfront-3/src/expr3.cpp"
__O3__4expr.e2 )){ 
# 2038 "/home/claude/cfront-3/src/expr3.cpp"
const char *__3s ;

# 2038 "/home/claude/cfront-3/src/expr3.cpp"
__3s = __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O2__4expr.string ;
if ((((((__3s && ((__3s [0 ])== '_' ))&& ((__3s [1 ])== '_' ))&& ((__3s [2 ])== 'V' ))&& __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp )&& __0this -> __O4__4expr.tp2 )&&
# 2039 "/home/claude/cfront-3/src/expr3.cpp"
(! check__4typeFP4typeUcT2 ( __0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O1__4expr.tp , __0this -> __O4__4expr.tp2 , (unsigned char )0 , (unsigned char )0 )
# 2039 "/home/claude/cfront-3/src/expr3.cpp"
))
# 2041 "/home/claude/cfront-3/src/expr3.cpp"
return __0this -> __O2__4expr.e1 ;
}
no_sti = 1 ;
Ntmp = 0 ;
{ Pname __2n ;

# 2045 "/home/claude/cfront-3/src/expr3.cpp"
__2n = make_tmp__FcP4typeP5table ( 'V' , __0this -> __O4__4expr.tp2 , __1tbl ) ;
no_sti = 0 ;
assign__4nameFv ( __2n ) ;
if (__1tbl == gtbl )dcl_print__4nameFUc ( __2n , (unsigned char )0 ) ;
{ Pexpr __2c ;
extern bit in_quest ;

# 2049 "/home/claude/cfront-3/src/expr3.cpp"
__2c = call_ctor__FP5tableP4exprN22iT2 ( __1tbl , (struct expr *)__2n , (struct expr *)__1ctor , __0this -> __O2__4expr.e1 , 45 , (struct expr *)0 ) ;

# 2051 "/home/claude/cfront-3/src/expr3.cpp"
if (Ntmp && in_quest ){ 
# 2051 "/home/claude/cfront-3/src/expr3.cpp"
struct ival *__0__X214 ;

# 2052 "/home/claude/cfront-3/src/expr3.cpp"
if (Ntmp_refd ){ 
# 2053 "/home/claude/cfront-3/src/expr3.cpp"
__2n -> __O1__4name.n_list = Ntmp_refd ;
Ntmp_refd = __2n ;
}
else Ntmp_refd = __2n ;

# 2058 "/home/claude/cfront-3/src/expr3.cpp"
Ntmp_flag = make_tmp__FcP4typeP5table ( 'Q' , (struct type *)int_type , __1tbl ) ;
Ntmp_flag -> __O3__4expr.n_initializer = (struct expr *)( (__0__X214 = 0 ), ( ((__0__X214 || (__0__X214 = (struct ival *)__nw__4exprSFUl ( (unsigned long )(sizeof
# 2059 "/home/claude/cfront-3/src/expr3.cpp"
(struct ival))) ))?( (__0__X214 = (struct ival *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X214 ), (unsigned char )150 , (struct expr *)0 , (struct expr *)0 )
# 2059 "/home/claude/cfront-3/src/expr3.cpp"
), (__0__X214 -> __O2__4expr.i1 = ((long long )0L ))) :0 ), __0__X214 ) ) ;
assign__4nameFv ( Ntmp_flag ) ;

# 2062 "/home/claude/cfront-3/src/expr3.cpp"
if (Ntmp_flag_list ){ 
# 2063 "/home/claude/cfront-3/src/expr3.cpp"
Ntmp_flag -> __O1__4name.n_list = Ntmp_flag_list ;
Ntmp_flag_list = Ntmp_flag ;
}
else Ntmp_flag_list = Ntmp_flag ;

# 2068 "/home/claude/cfront-3/src/expr3.cpp"
{ Pexpr __3e ;

# 2068 "/home/claude/cfront-3/src/expr3.cpp"
__3e = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)Ntmp_flag , one ) ;
__3e -> __O1__4expr.tp = (struct type *)int_type ;
{ Ptype __3t ;

# 2070 "/home/claude/cfront-3/src/expr3.cpp"
__3t = __2c -> __O1__4expr.tp ;
Ntmp_flag = 0 ;
__2c = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __3e , __2c ) ;
__2c -> __O1__4expr.tp = __3t ;

# 2073 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2073 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2076 "/home/claude/cfront-3/src/expr3.cpp"
__2c = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __2c , (struct expr *)__2n ) ;
__2c -> __O1__4expr.tp = __2n -> __O1__4expr.tp ;
return __2c ;

# 2078 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2078 "/home/claude/cfront-3/src/expr3.cpp"
}
}
else { 
# 2081 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __2c ;

# 2081 "/home/claude/cfront-3/src/expr3.cpp"
__2c = call_ctor__FP5tableP4exprN22iT2 ( __1tbl , __0this -> __O3__4expr.e2 , (struct expr *)__1ctor , __0this -> __O2__4expr.e1 , 45 , (struct expr *)0 ) ;
__2c = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __2c , (struct expr *)0 ) ;
__2c -> __O1__4expr.tp = __2c -> __O2__4expr.e1 -> __O1__4expr.tp ;
return __2c ;
}

# 2085 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 675 "/home/claude/cfront-3/src/cfront.h"

# 952 "/home/claude/cfront-3/src/cfront.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 65 "/home/claude/cfront-3/src/Bits.h"
struct Bits *__ct__4BitsFUlT1 (struct Bits *__0this , Bits_chunk , size_t );

# 71 "/home/claude/cfront-3/src/Bits.h"
extern void __co__FRC4Bits (struct Bits *__0_result , const struct Bits *);

# 30 "/home/claude/cfront-3/src/expr3.cpp"
static Pname breakTie__FRC11Block_PnameR4BitsP4expri (const struct Block_Pname *, struct Bits *, Pexpr , int );

# 123 "/home/claude/cfront-3/src/Bits.h"

# 2089 "/home/claude/cfront-3/src/expr3.cpp"
Pname exactMatch__3genFP4expri (register struct gen *__0this , Pexpr __1arg , int __1constObj )
# 2096 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2096 "/home/claude/cfront-3/src/expr3.cpp"
struct name *__0_result ;

# 2097 "/home/claude/cfront-3/src/expr3.cpp"
if (( (__0this -> holds_templ__3gen == 2)) )return (struct name *)0 ;
{ Plist __1gl ;
int __1ok ;
struct Block_Pname __1funVec ;

# 2102 "/home/claude/cfront-3/src/expr3.cpp"
int __1numEx ;

# 2100 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __1funVec )-> n__11Block_Pname = 0 ), ((& __1funVec )-> p__11Block_Pname = 0 )) ), (& __1funVec )) ;
# 2100 "/home/claude/cfront-3/src/expr3.cpp"

# 2102 "/home/claude/cfront-3/src/expr3.cpp"
__1numEx = 0 ;
for(__1gl = __0this -> fct_list__3gen ;__1gl ;__1gl = __1gl -> l__9name_list ) { 
# 2104 "/home/claude/cfront-3/src/expr3.cpp"
Pname __2nn ;

# 2104 "/home/claude/cfront-3/src/expr3.cpp"
__2nn = __1gl -> f__9name_list ;
if (( __2nn -> n_template_fct__4name ) )continue ;
{ Pfct __2f ;
Pname __2n ;

# 2108 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X217 ;

# 2108 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 2108 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 2108 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 2106 "/home/claude/cfront-3/src/expr3.cpp"
__2f = ( ((__2nn -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__2nn -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 2106 "/home/claude/cfront-3/src/expr3.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__2nn )),
# 2106 "/home/claude/cfront-3/src/expr3.cpp"
(& __0__X__V1400qmhwx544vcnm )) , (const struct ea *)( (__2__X16 = __2nn -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )->
# 2106 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmhwx544vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 2106 "/home/claude/cfront-3/src/expr3.cpp"
, (((struct fct *)0 ))) )) ;
__2n = __2f -> argtype__3fct ;
if (((__1constObj && (__2nn -> n_oper__4name != 161 ))&& (! __2f -> f_const__3fct ))&& (! __2f -> f_static__3fct )){ 
# 2109 "/home/claude/cfront-3/src/expr3.cpp"
non_const ++ ;
continue ;
}
__1ok = 0 ;
if (! __1arg )__1ok = 1 ;
else { 
# 2115 "/home/claude/cfront-3/src/expr3.cpp"
{ { Pexpr __3e ;

# 2115 "/home/claude/cfront-3/src/expr3.cpp"
__3e = __1arg ;

# 2115 "/home/claude/cfront-3/src/expr3.cpp"
for(;__3e ;( (__3e = __3e -> __O3__4expr.e2 ), (__2n = __2n -> __O1__4name.n_list )) ) { 
# 2116 "/home/claude/cfront-3/src/expr3.cpp"
if ((! __2n )&& (__2f -> nargs_known__3fct !=
# 2116 "/home/claude/cfront-3/src/expr3.cpp"
155 ))break ;
{ Pexpr __4a ;
Ptype __4at ;

# 2117 "/home/claude/cfront-3/src/expr3.cpp"
__4a = __3e -> __O2__4expr.e1 ;
__4at = __4a -> __O1__4expr.tp ;
if (__4at -> base__4node == 141 )break ;
if (__4at -> base__4node == 138 )__4at = (struct type *)int_type ;
if (! exact1__FP4nameP4type ( __2n , __4at ) )break ;
if (! __3e -> __O3__4expr.e2 )__1ok = 1 ;

# 2122 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2123 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2123 "/home/claude/cfront-3/src/expr3.cpp"
}
}
if ((! __1ok )|| (__2n && (! __2n -> __O3__4expr.n_initializer )))continue ;

# 2127 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )(__1numEx + 1 ))< (& __1funVec )-> n__11Block_Pname )|| grow__11Block_PnameFUl ( (& __1funVec ), ((unsigned long )(__1numEx +
# 2127 "/home/claude/cfront-3/src/expr3.cpp"
1 ))) )) ;
((*( (__2__X217 = (__1numEx ++ )), ( (((Pname *)(& ((& __1funVec )-> p__11Block_Pname [__2__X217 ]))))) ) ))= __2nn ;

# 2128 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2131 "/home/claude/cfront-3/src/expr3.cpp"
if (! __1numEx ){ { __0_result = 0 ;

# 2131 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2131 "/home/claude/cfront-3/src/expr3.cpp"
} return __0_result ;
} if (__1numEx == 1 ){ { __0_result = ((*( (((Pname *)(& ((& __1funVec )-> p__11Block_Pname [0 ]))))) ));

# 2132 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2132 "/home/claude/cfront-3/src/expr3.cpp"
} return __0_result ;
} 
# 2135 "/home/claude/cfront-3/src/expr3.cpp"
{ struct Bits __1bestOnes ;

# 2136 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits __0__V215 ;

# 2136 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2135 "/home/claude/cfront-3/src/expr3.cpp"
__co__FRC4Bits ( & __1bestOnes , (const struct Bits *)__ct__4BitsFUlT1 ( & __0__V215 , (unsigned long )0 , (unsigned long )__1numEx )
# 2135 "/home/claude/cfront-3/src/expr3.cpp"
) ;
{ { __0_result = breakTie__FRC11Block_PnameR4BitsP4expri ( (const struct Block_Pname *)(& __1funVec ), (struct Bits *)(& __1bestOnes ), __1arg , __1constObj ) ;
# 2136 "/home/claude/cfront-3/src/expr3.cpp"

# 2137 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2137 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __0__V215 )-> b__4Bits )), ( (__0__X45 ?(((void )(
# 2137 "/home/claude/cfront-3/src/expr3.cpp"
__dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 2137 "/home/claude/cfront-3/src/expr3.cpp"
)0 ))) ))))) ;

# 2137 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1bestOnes )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2137 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2137 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;

# 2137 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2137 "/home/claude/cfront-3/src/expr3.cpp"
} } 
# 2136 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} 
# 2136 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2136 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 675 "/home/claude/cfront-3/src/cfront.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 952 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 28 "/home/claude/cfront-3/src/expr3.cpp"
static void bestMatch__FRC11Block_PnameiP4type (struct Bits *__0_result , const struct Block_Pname *, int , Ptype );

# 113 "/home/claude/cfront-3/src/Bits.h"
size_t count__4BitsCFv (const struct Bits *const __0this );

# 39 "/home/claude/cfront-3/src/overload.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 2140 "/home/claude/cfront-3/src/expr3.cpp"
Pname oneArgMatch__3genFP4expri (register struct gen *__0this , Pexpr __1aarg , int __1constObj )
# 2148 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2148 "/home/claude/cfront-3/src/expr3.cpp"
struct name *__0_result ;

# 2149 "/home/claude/cfront-3/src/expr3.cpp"
if (( (__0this -> holds_templ__3gen == 2)) )return (struct name *)0 ;
{ Plist __1gl ;
int __1numFunc ;
struct Block_Pname __1ArgVec ;
struct Block_Pname __1funVec ;
Pname __1fn ;

# 2151 "/home/claude/cfront-3/src/expr3.cpp"
__1numFunc = 0 ;
( (( ((& __1ArgVec )-> n__11Block_Pname = 0 ), ((& __1ArgVec )-> p__11Block_Pname = 0 )) ), (& __1ArgVec )) ;
# 2152 "/home/claude/cfront-3/src/expr3.cpp"

# 2153 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __1funVec )-> n__11Block_Pname = 0 ), ((& __1funVec )-> p__11Block_Pname = 0 )) ), (& __1funVec )) ;
# 2153 "/home/claude/cfront-3/src/expr3.cpp"

# 2154 "/home/claude/cfront-3/src/expr3.cpp"
__1fn = __0this -> fct_list__3gen -> f__9name_list ;

# 2156 "/home/claude/cfront-3/src/expr3.cpp"
for(__1gl = __0this -> fct_list__3gen ;__1gl ;__1gl = __1gl -> l__9name_list ) { 
# 2157 "/home/claude/cfront-3/src/expr3.cpp"
Pname __2nn ;
Pfct __2ft ;
Pname __2nnargs ;

# 2160 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X219 ;

# 2160 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 2160 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 2160 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 2157 "/home/claude/cfront-3/src/expr3.cpp"
__2nn = __1gl -> f__9name_list ;
__2ft = ( ((__2nn -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__2nn -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 2158 "/home/claude/cfront-3/src/expr3.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__2nn )),
# 2158 "/home/claude/cfront-3/src/expr3.cpp"
(& __0__X__V1400qmhwx544vcnm )) , (const struct ea *)( (__2__X16 = __2nn -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )->
# 2158 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmhwx544vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 2158 "/home/claude/cfront-3/src/expr3.cpp"
, (((struct fct *)0 ))) )) ;
__2nnargs = __2ft -> argtype__3fct ;

# 2161 "/home/claude/cfront-3/src/expr3.cpp"
if (( __2nn -> n_template_fct__4name ) )continue ;

# 2163 "/home/claude/cfront-3/src/expr3.cpp"
if (((__1constObj && (__1fn -> n_oper__4name != 161 ))&& (! __2ft -> f_const__3fct ))&& (! __2ft -> f_static__3fct ))
# 2164 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2165 "/home/claude/cfront-3/src/expr3.cpp"
non_const ++ ;
continue ;
}
if ((! __2nnargs )&& (__2ft -> nargs_known__3fct != 155 ))
# 2169 "/home/claude/cfront-3/src/expr3.cpp"
continue ;
if ((__2nnargs && __2nnargs -> __O1__4name.n_list )&& (! __2nnargs -> __O1__4name.n_list -> __O3__4expr.n_initializer ))
# 2171 "/home/claude/cfront-3/src/expr3.cpp"
continue ;
( ((((unsigned long )(__1numFunc + 1 ))< (& __1ArgVec )-> n__11Block_Pname )|| grow__11Block_PnameFUl ( (& __1ArgVec ), ((unsigned long )(__1numFunc +
# 2172 "/home/claude/cfront-3/src/expr3.cpp"
1 ))) )) ;
( ((((unsigned long )(__1numFunc + 1 ))< (& __1funVec )-> n__11Block_Pname )|| grow__11Block_PnameFUl ( (& __1funVec ), ((unsigned long )(__1numFunc +
# 2173 "/home/claude/cfront-3/src/expr3.cpp"
1 ))) )) ;
((*( (((Pname *)(& ((& __1ArgVec )-> p__11Block_Pname [__1numFunc ]))))) ))= (__2nnargs ?__2nnargs :(((struct name *)155 )));
((*( (__2__X219 = (__1numFunc ++ )), ( (((Pname *)(& ((& __1funVec )-> p__11Block_Pname [__2__X219 ]))))) ) ))= __2nn ;
}
if (! __1numFunc ){ { __0_result = 0 ;

# 2177 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2177 "/home/claude/cfront-3/src/expr3.cpp"

# 2177 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1ArgVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2177 "/home/claude/cfront-3/src/expr3.cpp"
} return __0_result ;
} 
# 2179 "/home/claude/cfront-3/src/expr3.cpp"
{ struct Bits __1bestOnes ;

# 2181 "/home/claude/cfront-3/src/expr3.cpp"
int __1numFuncs ;

# 2182 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2182 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X220 ;

# 2179 "/home/claude/cfront-3/src/expr3.cpp"
bestMatch__FRC11Block_PnameiP4type ( & __1bestOnes , (const struct Block_Pname *)(& __1ArgVec ), __1numFunc , __1aarg -> __O2__4expr.e1 -> __O1__4expr.tp ) ;

# 2181 "/home/claude/cfront-3/src/expr3.cpp"
__1numFuncs = count__4BitsCFv ( (const struct Bits *)(& __1bestOnes )) ;
if (! __1numFuncs ){ { __0_result = 0 ;

# 2187 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1bestOnes )-> b__4Bits )), ( (__0__X45 ?(((void )(
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
__dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
)0 ))) ))))) ;

# 2187 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2187 "/home/claude/cfront-3/src/expr3.cpp"

# 2187 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1ArgVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
} } 
# 2182 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} if (__1numFuncs == 1 )
# 2184 "/home/claude/cfront-3/src/expr3.cpp"
{ { __0_result = ((*( (__2__X220 = (signif__4BitsCFv ( (const struct Bits *)(& __1bestOnes )) -
# 2184 "/home/claude/cfront-3/src/expr3.cpp"
1 )), ( (((Pname *)(& ((& __1funVec )-> p__11Block_Pname [__2__X220 ]))))) ) ));

# 2187 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1bestOnes )-> b__4Bits )), ( (__0__X45 ?(((void )(
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
__dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
)0 ))) ))))) ;

# 2187 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2187 "/home/claude/cfront-3/src/expr3.cpp"

# 2187 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1ArgVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
} } 
# 2184 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} 
# 2186 "/home/claude/cfront-3/src/expr3.cpp"
{ { __0_result = breakTie__FRC11Block_PnameR4BitsP4expri ( (const struct Block_Pname *)(& __1funVec ), (struct Bits *)(& __1bestOnes ), __1aarg , __1constObj )
# 2186 "/home/claude/cfront-3/src/expr3.cpp"
;
{ 
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1bestOnes )-> b__4Bits )), ( (__0__X45 ?(((void )(
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
__dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
)0 ))) ))))) ;

# 2187 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2187 "/home/claude/cfront-3/src/expr3.cpp"

# 2187 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1ArgVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2187 "/home/claude/cfront-3/src/expr3.cpp"
} } 
# 2186 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} 
# 2186 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2186 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 675 "/home/claude/cfront-3/src/cfront.h"

# 41 "/home/claude/cfront-3/src/overload.h"

# 952 "/home/claude/cfront-3/src/cfront.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 41 "/home/claude/cfront-3/src/overload.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 41 "/home/claude/cfront-3/src/overload.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 41 "/home/claude/cfront-3/src/overload.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 41 "/home/claude/cfront-3/src/overload.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 27 "/home/claude/cfront-3/src/expr3.cpp"
static void intersectRule__FRC16Block_BlockPnameiP4expr (struct Bits *__0_result , const struct Block_BlockPname *, int , Pexpr );

# 39 "/home/claude/cfront-3/src/overload.h"

# 41 "/home/claude/cfront-3/src/overload.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 41 "/home/claude/cfront-3/src/overload.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 45 "/home/claude/cfront-3/src/overload.h"
extern Pname bestOfPair__FP4nameT1P4type (Pname , Pname , Ptype );

# 123 "/home/claude/cfront-3/src/Bits.h"

# 87 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 41 "/home/claude/cfront-3/src/overload.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"
static Pname *__vc__11Block_PnameFi (struct Block_Pname *__0this , int __2i );

# 123 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 2190 "/home/claude/cfront-3/src/expr3.cpp"
Pname multArgMatch__3genFP4expri (register struct gen *__0this , Pexpr __1arg , int __1constObj )
# 2198 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2198 "/home/claude/cfront-3/src/expr3.cpp"
struct name *__0_result ;

# 2199 "/home/claude/cfront-3/src/expr3.cpp"
if (( (__0this -> holds_templ__3gen == 2)) )return (struct name *)0 ;
{ int __1numargs ;
Pexpr __1tmp ;

# 2200 "/home/claude/cfront-3/src/expr3.cpp"
__1numargs = 1 ;
__1tmp = __1arg ;
if (! __1tmp )return (struct name *)0 ;
while (__1tmp = __1tmp -> __O3__4expr.e2 )__1numargs ++ ;
{ struct Block_BlockPname __1intFun ;

# 2204 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __1intFun )-> n__16Block_BlockPname = 0 ), ( ((& __1intFun )-> p__16Block_BlockPname = 0 ), ( move__16Block_BlockPnameFP11Block_PnameUl ( (&
# 2204 "/home/claude/cfront-3/src/expr3.cpp"
__1intFun ), (BlockPname *)(((struct Block_Pname *)__vec_new ( ((void *)0 ), ((unsigned long )__1numargs ), sizeof (struct Block_Pname ), ((void *)__ct__11Block_PnameFv )) )),
# 2204 "/home/claude/cfront-3/src/expr3.cpp"
((unsigned long )__1numargs )) , (& __1intFun )-> n__16Block_BlockPname ) ) ) ), (& __1intFun )) ;

# 2206 "/home/claude/cfront-3/src/expr3.cpp"
miFlag = 0 ;
{ int __1numFunc ;
struct Block_Pname __1funVec ;

# 2207 "/home/claude/cfront-3/src/expr3.cpp"
__1numFunc = 0 ;
( (( ((& __1funVec )-> n__11Block_Pname = 0 ), ((& __1funVec )-> p__11Block_Pname = 0 )) ), (& __1funVec )) ;
# 2208 "/home/claude/cfront-3/src/expr3.cpp"

# 2210 "/home/claude/cfront-3/src/expr3.cpp"
{ { Plist __1gl ;

# 2210 "/home/claude/cfront-3/src/expr3.cpp"
__1gl = __0this -> fct_list__3gen ;

# 2210 "/home/claude/cfront-3/src/expr3.cpp"
for(;__1gl ;__1gl = __1gl -> l__9name_list ) { 
# 2211 "/home/claude/cfront-3/src/expr3.cpp"
Pname __2nn ;

# 2211 "/home/claude/cfront-3/src/expr3.cpp"
__2nn = __1gl -> f__9name_list ;

# 2213 "/home/claude/cfront-3/src/expr3.cpp"
if (( __2nn -> n_template_fct__4name ) )continue ;

# 2216 "/home/claude/cfront-3/src/expr3.cpp"
if (! matchable__FP4nameP4expri ( __2nn , __1arg , __1constObj ) )continue ;

# 2219 "/home/claude/cfront-3/src/expr3.cpp"
{ int __2ai ;
Pfct __2tf ;

# 2221 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 2221 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 2221 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 2219 "/home/claude/cfront-3/src/expr3.cpp"
__2ai = 0 ;
__2tf = ( ((__2nn -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__2nn -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 2220 "/home/claude/cfront-3/src/expr3.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__2nn )),
# 2220 "/home/claude/cfront-3/src/expr3.cpp"
(& __0__X__V1400qmhwx544vcnm )) , (const struct ea *)( (__2__X16 = __2nn -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )->
# 2220 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmhwx544vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 2220 "/home/claude/cfront-3/src/expr3.cpp"
, (((struct fct *)0 ))) )) ;

# 2222 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )(__1numFunc + 1 ))< (& __1funVec )-> n__11Block_Pname )|| grow__11Block_PnameFUl ( (& __1funVec ), ((unsigned long )(__1numFunc +
# 2222 "/home/claude/cfront-3/src/expr3.cpp"
1 ))) )) ;
((*( (((Pname *)(& ((& __1funVec )-> p__11Block_Pname [__1numFunc ]))))) ))= __2nn ;
{ { Pname __2x ;

# 2224 "/home/claude/cfront-3/src/expr3.cpp"
__2x = __2tf -> argtype__3fct ;

# 2224 "/home/claude/cfront-3/src/expr3.cpp"
for(;__2x && (__2ai < __1numargs );__2x = __2x -> __O1__4name.n_list ) { 
# 2224 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Pname *__0__X222 ;

# 2224 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Pname *__0__X223 ;

# 2225 "/home/claude/cfront-3/src/expr3.cpp"
( (__0__X222 = (struct Block_Pname *)( (((BlockPname *)(& ((& __1intFun )-> p__16Block_BlockPname [__2ai ]))))) ), ( ((((unsigned long )(__1numFunc + 1 ))<
# 2225 "/home/claude/cfront-3/src/expr3.cpp"
__0__X222 -> n__11Block_Pname )|| grow__11Block_PnameFUl ( __0__X222 , ((unsigned long )(__1numFunc + 1 ))) )) ) ;
((*( (__0__X223 = (struct Block_Pname *)( (((BlockPname *)(& ((& __1intFun )-> p__16Block_BlockPname [__2ai ]))))) ), ( (((Pname *)(& (__0__X223 -> p__11Block_Pname [__1numFunc ]))))) )
# 2226 "/home/claude/cfront-3/src/expr3.cpp"
))= __2x ;
__2ai ++ ;
}

# 2231 "/home/claude/cfront-3/src/expr3.cpp"
if (__2tf -> nargs_known__3fct == 155 ){ 
# 2232 "/home/claude/cfront-3/src/expr3.cpp"
while (__2ai < __1numargs ){ 
# 2232 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Pname *__0__X224 ;

# 2232 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X225 ;

# 2232 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Pname *__0__X226 ;

# 2233 "/home/claude/cfront-3/src/expr3.cpp"
( (__0__X224 = (struct Block_Pname *)( (((BlockPname *)(& ((& __1intFun )-> p__16Block_BlockPname [__2ai ]))))) ), ( ((((unsigned long )(__1numFunc + 1 ))<
# 2233 "/home/claude/cfront-3/src/expr3.cpp"
__0__X224 -> n__11Block_Pname )|| grow__11Block_PnameFUl ( __0__X224 , ((unsigned long )(__1numFunc + 1 ))) )) ) ;
((*( (__0__X226 = (struct Block_Pname *)( (__2__X225 = (__2ai ++ )), ( (((BlockPname *)(& ((& __1intFun )-> p__16Block_BlockPname [__2__X225 ]))))) ) ),
# 2234 "/home/claude/cfront-3/src/expr3.cpp"
( (((Pname *)(& (__0__X226 -> p__11Block_Pname [__1numFunc ]))))) ) ))= (((struct name *)155 ));
}
}
__1numFunc ++ ;

# 2237 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2237 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2237 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2241 "/home/claude/cfront-3/src/expr3.cpp"
if (__1numFunc == 0 ){ { __0_result = 0 ;

# 2305 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) )))
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
;

# 2305 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __vec_delete ( ((void *)(& __1intFun )-> p__16Block_BlockPname ), -1, sizeof (struct Block_Pname ), ((void *)__dt__11Block_PnameFv ),
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
1, 0) , (((void )(((void )0 ))))) ))) ;
} } 
# 2241 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} 
# 2244 "/home/claude/cfront-3/src/expr3.cpp"
if (__1numFunc == 1 ){ { __0_result = ((*( (((Pname *)(& ((& __1funVec )-> p__11Block_Pname [0 ]))))) ));

# 2305 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) )))
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
;

# 2305 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __vec_delete ( ((void *)(& __1intFun )-> p__16Block_BlockPname ), -1, sizeof (struct Block_Pname ), ((void *)__dt__11Block_PnameFv ),
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
1, 0) , (((void )(((void )0 ))))) ))) ;
} } 
# 2244 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} 
# 2247 "/home/claude/cfront-3/src/expr3.cpp"
if (__1numFunc > 1 ){ 
# 2249 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits __2bestFuncs ;

# 2251 "/home/claude/cfront-3/src/expr3.cpp"
Pname __2best ;
int __2sigbit ;

# 2253 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2249 "/home/claude/cfront-3/src/expr3.cpp"
intersectRule__FRC16Block_BlockPnameiP4expr ( & __2bestFuncs , (const struct Block_BlockPname *)(& __1intFun ), __1numFunc , __1arg ) ;

# 2251 "/home/claude/cfront-3/src/expr3.cpp"
__2best = 0 ;
__2sigbit = (signif__4BitsCFv ( (const struct Bits *)(& __2bestFuncs )) - 1 );

# 2254 "/home/claude/cfront-3/src/expr3.cpp"
switch (count__4BitsCFv ( (const struct Bits *)(& __2bestFuncs )) ){ 
# 2255 "/home/claude/cfront-3/src/expr3.cpp"
case 0 :
# 2256 "/home/claude/cfront-3/src/expr3.cpp"
fmError__FiRC11Block_PnameP4exprUc ( 1 , (const struct Block_Pname *)(& __1funVec ),
# 2256 "/home/claude/cfront-3/src/expr3.cpp"
__1arg , (unsigned char )__1constObj ) ;
__2best = ((*( (((Pname *)(& ((& __1funVec )-> p__11Block_Pname [0 ]))))) ));
break ;

# 2260 "/home/claude/cfront-3/src/expr3.cpp"
default :
# 2261 "/home/claude/cfront-3/src/expr3.cpp"
__2best = breakTie__FRC11Block_PnameR4BitsP4expri ( (const struct Block_Pname *)(& __1funVec ), (struct Bits *)(& __2bestFuncs ), __1arg , __1constObj ) ;
__2sigbit = (signif__4BitsCFv ( (const struct Bits *)(& __2bestFuncs )) - 1 );

# 2264 "/home/claude/cfront-3/src/expr3.cpp"
case 1 :
# 2266 "/home/claude/cfront-3/src/expr3.cpp"
if ((miFlag == 1 )&& (__1numFunc > 2 )){ 
# 2268 "/home/claude/cfront-3/src/expr3.cpp"
{ { int __4K ;

# 2268 "/home/claude/cfront-3/src/expr3.cpp"
__4K = 0 ;

# 2268 "/home/claude/cfront-3/src/expr3.cpp"
for(;__4K < __1numFunc ;__4K ++ ) { 
# 2269 "/home/claude/cfront-3/src/expr3.cpp"
if (__4K == __2sigbit )continue ;
{ int __5gotit ;
Pexpr __5targ ;

# 2270 "/home/claude/cfront-3/src/expr3.cpp"
__5gotit = 0 ;
__5targ = __1arg ;
{ { int __5I ;

# 2272 "/home/claude/cfront-3/src/expr3.cpp"
__5I = 0 ;

# 2272 "/home/claude/cfront-3/src/expr3.cpp"
for(;__5I < __1numargs ;__5I ++ ) { 
# 2272 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Pname *__0__X227 ;

# 2273 "/home/claude/cfront-3/src/expr3.cpp"
if (bestOfPair__FP4nameT1P4type ( (*( (__0__X227 = (struct Block_Pname *)( (((BlockPname *)(& ((& __1intFun )-> p__16Block_BlockPname [__5I ]))))) ), ( (((Pname *)(& (__0__X227 ->
# 2273 "/home/claude/cfront-3/src/expr3.cpp"
p__11Block_Pname [__2sigbit ]))))) ) ), (*__vc__11Block_PnameFi ( (struct Block_Pname *)( (((BlockPname *)(& ((& __1intFun )-> p__16Block_BlockPname [__5I ]))))) , __4K ) ), __5targ ->
# 2273 "/home/claude/cfront-3/src/expr3.cpp"
__O2__4expr.e1 -> __O1__4expr.tp ) )
# 2274 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2275 "/home/claude/cfront-3/src/expr3.cpp"
__5gotit = 1 ;
break ;
}
__5targ = __5targ -> __O3__4expr.e2 ;
}
if (! __5gotit ){ 
# 2281 "/home/claude/cfront-3/src/expr3.cpp"
if (! __2best ){ 
# 2282 "/home/claude/cfront-3/src/expr3.cpp"
fmError__FiRC11Block_PnameP4exprUc ( 1 , (const struct Block_Pname *)(& __1funVec ), __1arg , (unsigned
# 2282 "/home/claude/cfront-3/src/expr3.cpp"
char )__1constObj ) ;
break ;
}
{ struct Bits __6temp ;

# 2286 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2286 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X37 ;

# 2286 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X38 ;

# 2286 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X229 ;

# 2286 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__2__X230 ;

# 2285 "/home/claude/cfront-3/src/expr3.cpp"
( (( ( ( (__0__X229 = (& (& __6temp )-> b__4Bits )), ( (__2__X230 = (const struct Block_Bits_chunk *)(&
# 2285 "/home/claude/cfront-3/src/expr3.cpp"
((*((const struct Bits *)(& __2bestFuncs )))). b__4Bits )), ( ((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl ( (unsigned long )(sizeof (struct Block_Bits_chunk)))
# 2285 "/home/claude/cfront-3/src/expr3.cpp"
))?(((void )copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X229 , __2__X230 ) )):(((void )0 ))), __0__X229 ) ) ) , ((& __6temp )-> n__4Bits = ((*((const
# 2285 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits *)(& __2bestFuncs )))). n__4Bits )) , 0 ) ), (& __6temp )) ;
( ((((unsigned long )__4K )< (& __2bestFuncs )-> n__4Bits )?(((*( (__0__X37 = (& (& __2bestFuncs )-> b__4Bits )), ( (__2__X38 =
# 2286 "/home/claude/cfront-3/src/expr3.cpp"
( (((unsigned long )__4K )>> 5)) ), ( (((Bits_chunk *)(& (__0__X37 -> p__16Block_Bits_chunk [__2__X38 ]))))) ) ) ))|= ((((unsigned
# 2286 "/home/claude/cfront-3/src/expr3.cpp"
long )1 ))<< (((unsigned long )__4K )& 31))):0 ), (((struct Bits *)(& __2bestFuncs )))) ;
if (breakTie__FRC11Block_PnameR4BitsP4expri ( (const struct Block_Pname *)(& __1funVec ), (struct Bits *)(& __6temp ), __1arg , __1constObj ) != ((*( (((Pname *)(&
# 2287 "/home/claude/cfront-3/src/expr3.cpp"
((& __1funVec )-> p__11Block_Pname [__2sigbit ]))))) )))
# 2291 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2292 "/home/claude/cfront-3/src/expr3.cpp"
fmError__FiRC11Block_PnameP4exprUc ( 1 , (const struct Block_Pname *)(& __1funVec ), __1arg , (unsigned char )__1constObj )
# 2292 "/home/claude/cfront-3/src/expr3.cpp"
;
{ { 
# 2293 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __6temp )-> b__4Bits )), ( (__0__X45 ?(((void
# 2293 "/home/claude/cfront-3/src/expr3.cpp"
)( __dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) ,
# 2293 "/home/claude/cfront-3/src/expr3.cpp"
(((void )0 ))) ))))) ;

# 2293 "/home/claude/cfront-3/src/expr3.cpp"
break ;
} 
# 2293 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2294 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __6temp )-> b__4Bits )), ( (__0__X45 ?(((void )(
# 2294 "/home/claude/cfront-3/src/expr3.cpp"
__dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 2294 "/home/claude/cfront-3/src/expr3.cpp"
)0 ))) ))))) ;

# 2294 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2295 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2295 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2295 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2296 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2296 "/home/claude/cfront-3/src/expr3.cpp"
}
}
__2best = ((*( (((Pname *)(& ((& __1funVec )-> p__11Block_Pname [__2sigbit ]))))) ));
}
{ 
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __2bestFuncs )-> b__4Bits )), ( (__0__X45 ?(((void
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
)( __dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) ,
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
(((void )0 ))) ))))) ;

# 2305 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) )))
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
;

# 2305 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __vec_delete ( ((void *)(& __1intFun )-> p__16Block_BlockPname ), -1, sizeof (struct Block_Pname ), ((void *)__dt__11Block_PnameFv ),
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
1, 0) , (((void )(((void )0 ))))) ))) ;
} } 
# 2300 "/home/claude/cfront-3/src/expr3.cpp"
return __2best ;
} }

# 2303 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCc ( (int )'i' , (const char *)"fall off end of gen::multArgMatch()") ;
{ { __0_result = 0 ;
{ 
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1funVec )-> p__11Block_Pname ) , (((void )(((void )0 ))))) )))
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
;

# 2305 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __vec_delete ( ((void *)(& __1intFun )-> p__16Block_BlockPname ), -1, sizeof (struct Block_Pname ), ((void *)__dt__11Block_PnameFv ),
# 2305 "/home/claude/cfront-3/src/expr3.cpp"
1, 0) , (((void )(((void )0 ))))) ))) ;
} } 
# 2304 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} 
# 2304 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2304 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2304 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2304 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2304 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2305 "/home/claude/cfront-3/src/expr3.cpp"

# 42 "/home/claude/cfront-3/src/overload.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 42 "/home/claude/cfront-3/src/overload.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 2447 "/home/claude/cfront-3/src/expr3.cpp"

# 42 "/home/claude/cfront-3/src/overload.h"

# 87 "/home/claude/cfront-3/src/Bits.h"

# 2305 "/home/claude/cfront-3/src/expr3.cpp"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 115 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 2305 "/home/claude/cfront-3/src/expr3.cpp"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 115 "/home/claude/cfront-3/src/Bits.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 42 "/home/claude/cfront-3/src/overload.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 2307 "/home/claude/cfront-3/src/expr3.cpp"
static void bestMatch__FRC11Block_PnameiP4type (
# 28 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits *__0_result , 
# 2307 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Pname *__1AV , int __1nav , Ptype __1at )
# 2312 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2313 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits __1zeroBits ;

# 2316 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_int __1rate ;
struct Block_Pname __1udcBlock ;

# 2319 "/home/claude/cfront-3/src/expr3.cpp"
int __1i ;

# 2320 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2320 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X229 ;

# 2320 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__2__X230 ;

# 2313 "/home/claude/cfront-3/src/expr3.cpp"
__ct__4BitsFUlT1 ( & __1zeroBits , (unsigned long )0 , (unsigned long )__1nav ) ;

# 2315 "/home/claude/cfront-3/src/expr3.cpp"
( (( ( ( (__0__X229 = (& __0_result -> b__4Bits )), ( (__2__X230 = (const struct Block_Bits_chunk *)(& ((*((const
# 2315 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits *)(& __1zeroBits )))). b__4Bits )), ( ((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl ( (unsigned long )(sizeof (struct Block_Bits_chunk))) ))?(((void
# 2315 "/home/claude/cfront-3/src/expr3.cpp"
)copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X229 , __2__X230 ) )):(((void )0 ))), __0__X229 ) ) ) , (__0_result -> n__4Bits = ((*((const struct Bits *)(&
# 2315 "/home/claude/cfront-3/src/expr3.cpp"
__1zeroBits )))). n__4Bits )) , 0 ) ), __0_result ) ;
( (( ((& __1rate )-> n__9Block_int = 0 ), ( ((& __1rate )-> p__9Block_int = 0 ), ( move__9Block_intFPiUl ( (&
# 2316 "/home/claude/cfront-3/src/expr3.cpp"
__1rate ), (int *)(((int *)__nw__FUl ( (unsigned long )((sizeof (int ))* ((unsigned long )__1nav ))) )), ((unsigned
# 2316 "/home/claude/cfront-3/src/expr3.cpp"
long )__1nav )) , (& __1rate )-> n__9Block_int ) ) ) ), (& __1rate )) ;
( (( ((& __1udcBlock )-> n__11Block_Pname = 0 ), ( ((& __1udcBlock )-> p__11Block_Pname = 0 ), ( move__11Block_PnameFPP4nameUl ( (&
# 2317 "/home/claude/cfront-3/src/expr3.cpp"
__1udcBlock ), (Pname *)(((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* ((unsigned long )__1nav ))) )), ((unsigned long
# 2317 "/home/claude/cfront-3/src/expr3.cpp"
)__1nav )) , (& __1udcBlock )-> n__11Block_Pname ) ) ) ), (& __1udcBlock )) ;

# 2319 "/home/claude/cfront-3/src/expr3.cpp"
__1i = -1;
while ((++ __1i )< __1nav ){ 
# 2322 "/home/claude/cfront-3/src/expr3.cpp"
Pname __2aa ;

# 2322 "/home/claude/cfront-3/src/expr3.cpp"
__2aa = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1AV )-> p__11Block_Pname [__1i ]))))) ));

# 2324 "/home/claude/cfront-3/src/expr3.cpp"
if (__2aa == 0 )continue ;

# 2326 "/home/claude/cfront-3/src/expr3.cpp"
if (__2aa == (((struct name *)155 ))){ 
# 2327 "/home/claude/cfront-3/src/expr3.cpp"
((*( (((int *)(& ((& __1rate )-> p__9Block_int [__1i ]))))) ))= 1;
continue ;
}
{ Ptype __2t1 ;

# 2330 "/home/claude/cfront-3/src/expr3.cpp"
__2t1 = __2aa -> __O1__4expr.tp ;

# 2332 "/home/claude/cfront-3/src/expr3.cpp"
if ((__2t1 == __1at )|| exact1__FP4nameP4type ( __2aa , __1at ) ){ 
# 2333 "/home/claude/cfront-3/src/expr3.cpp"
((*( (((int *)(& ((& __1rate )-> p__9Block_int [__1i ]))))) ))=
# 2333 "/home/claude/cfront-3/src/expr3.cpp"
5;
continue ;
}
if (exact2__FP4nameP4type ( __2aa , __1at ) ){ 
# 2337 "/home/claude/cfront-3/src/expr3.cpp"
((*( (((int *)(& ((& __1rate )-> p__9Block_int [__1i ]))))) ))= 4;
continue ;
}
if (exact3__FP4nameP4type ( __2aa , __1at ) ){ 
# 2341 "/home/claude/cfront-3/src/expr3.cpp"
((*( (((int *)(& ((& __1rate )-> p__9Block_int [__1i ]))))) ))= 3;
continue ;
}

# 2345 "/home/claude/cfront-3/src/expr3.cpp"
{ int __2cc ;

# 2345 "/home/claude/cfront-3/src/expr3.cpp"
__2cc = can_coerce__FP4typeT1 ( __2t1 , __1at ) ;
if (__2cc == 1 ){ 
# 2347 "/home/claude/cfront-3/src/expr3.cpp"
((*( (((Pname *)(& ((& __1udcBlock )-> p__11Block_Pname [__1i ]))))) ))= Ncoerce ;
((*( (((int *)(& ((& __1rate )-> p__9Block_int [__1i ]))))) ))= 2;
continue ;
}

# 2352 "/home/claude/cfront-3/src/expr3.cpp"
((*( (((int *)(& ((& __1rate )-> p__9Block_int [__1i ]))))) ))= 0;

# 2352 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2352 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2355 "/home/claude/cfront-3/src/expr3.cpp"
{ int __1max ;

# 2355 "/home/claude/cfront-3/src/expr3.cpp"
__1max = 0;
for(__1i = 0 ;__1i < __1nav ;__1i ++ ) { 
# 2357 "/home/claude/cfront-3/src/expr3.cpp"
if (((*( (((int *)(& ((& __1rate )-> p__9Block_int [__1i ]))))) ))> __1max ){
# 2357 "/home/claude/cfront-3/src/expr3.cpp"

# 2357 "/home/claude/cfront-3/src/expr3.cpp"
register struct Block_Bits_chunk *__0__X232 ;

# 2357 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__2__X233 ;

# 2358 "/home/claude/cfront-3/src/expr3.cpp"
__1max = ((*( (((int *)(& ((& __1rate )-> p__9Block_int [__1i ]))))) ));
( ( ( ((*( (__0__X232 = (& __0_result -> b__4Bits )), ( (__2__X233 = (const struct Block_Bits_chunk *)(& ((*((const
# 2359 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits *)(& __1zeroBits )))). b__4Bits )), ( __dl__FPv ( (void *)__0__X232 -> p__16Block_Bits_chunk ) , ( copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X232 , __2__X233 )
# 2359 "/home/claude/cfront-3/src/expr3.cpp"
, (((struct Block_Bits_chunk *)__0__X232 ))) ) ) ) )), (__0_result -> n__4Bits = ((*((const struct Bits *)(& __1zeroBits )))). n__4Bits ))
# 2359 "/home/claude/cfront-3/src/expr3.cpp"
, ((*__0_result ))) , (((struct Bits *)__0_result ))) ;
}
if (((*( (((int *)(& ((& __1rate )-> p__9Block_int [__1i ]))))) ))&& (((*( (((int *)(& ((& __1rate )-> p__9Block_int [__1i ])))))
# 2361 "/home/claude/cfront-3/src/expr3.cpp"
))== __1max )){ 
# 2361 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X37 ;

# 2361 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X38 ;

# 2362 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__1i )< __0_result -> n__4Bits )?(((*( (__0__X37 = (& __0_result -> b__4Bits )), ( (__2__X38 = ( (((unsigned
# 2362 "/home/claude/cfront-3/src/expr3.cpp"
long )__1i )>> 5)) ), ( (((Bits_chunk *)(& (__0__X37 -> p__16Block_Bits_chunk [__2__X38 ]))))) ) ) ))|= ((((unsigned long )1 ))<<
# 2362 "/home/claude/cfront-3/src/expr3.cpp"
(((unsigned long )__1i )& 31))):0 ), (((struct Bits *)__0_result ))) ;
}
}

# 2366 "/home/claude/cfront-3/src/expr3.cpp"
if (count__4BitsCFv ( (const struct Bits *)__0_result ) <= 1 ){ { ;

# 2366 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1udcBlock )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2366 "/home/claude/cfront-3/src/expr3.cpp"

# 2366 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rate )-> p__9Block_int ) , (((void )(((void )0 ))))) ))) ;
# 2366 "/home/claude/cfront-3/src/expr3.cpp"

# 2366 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1zeroBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2366 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2366 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
} 
# 2366 "/home/claude/cfront-3/src/expr3.cpp"
return ;
} 
# 2369 "/home/claude/cfront-3/src/expr3.cpp"
if (__1max == 3){ 
# 2370 "/home/claude/cfront-3/src/expr3.cpp"
if (is_ptr_or_ref__4typeFv ( __1at ) )__1at = (((struct ptr *)(((struct ptr *)__1at ))))-> typ__5pvtyp ;
if (! is_cl_obj__4typeFv ( __1at ) ){ { ;

# 2371 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1udcBlock )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2371 "/home/claude/cfront-3/src/expr3.cpp"

# 2371 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rate )-> p__9Block_int ) , (((void )(((void )0 ))))) ))) ;
# 2371 "/home/claude/cfront-3/src/expr3.cpp"

# 2371 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1zeroBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2371 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2371 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
} 
# 2371 "/home/claude/cfront-3/src/expr3.cpp"
return ;
} 
# 2373 "/home/claude/cfront-3/src/expr3.cpp"
{ struct Bits __2tempBits ;

# 2374 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2374 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X234 ;

# 2374 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2374 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2374 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X229 ;

# 2374 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__2__X230 ;

# 2373 "/home/claude/cfront-3/src/expr3.cpp"
( (( ( ( (__0__X229 = (& (& __2tempBits )-> b__4Bits )), ( (__2__X230 = (const struct Block_Bits_chunk *)(&
# 2373 "/home/claude/cfront-3/src/expr3.cpp"
((*((const struct Bits *)__0_result ))). b__4Bits )), ( ((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl ( (unsigned long )(sizeof (struct Block_Bits_chunk))) ))?(((void
# 2373 "/home/claude/cfront-3/src/expr3.cpp"
)copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X229 , __2__X230 ) )):(((void )0 ))), __0__X229 ) ) ) , ((& __2tempBits )-> n__4Bits = ((*((const struct
# 2373 "/home/claude/cfront-3/src/expr3.cpp"
Bits *)__0_result ))). n__4Bits )) , 0 ) ), (& __2tempBits )) ;
( (__2__X234 = (signif__4BitsCFv ( (const struct Bits *)(& __2tempBits )) - 1 )), ( ((__2__X234 < (& __2tempBits )-> n__4Bits )?(((*(
# 2374 "/home/claude/cfront-3/src/expr3.cpp"
(__0__X41 = (& (& __2tempBits )-> b__4Bits )), ( (__2__X42 = ( (__2__X234 >> 5)) ), ( (((Bits_chunk *)(& (__0__X41 ->
# 2374 "/home/claude/cfront-3/src/expr3.cpp"
p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~ ((((unsigned long )1 ))<< (__2__X234 & 31)))):0 ), (((struct Bits *)(& __2tempBits )))) )
# 2374 "/home/claude/cfront-3/src/expr3.cpp"
;

# 2378 "/home/claude/cfront-3/src/expr3.cpp"
while (count__4BitsCFv ( (const struct Bits *)(& __2tempBits )) ){ 
# 2379 "/home/claude/cfront-3/src/expr3.cpp"
int __3tempPtr ;
Ptype __3t1 ;
Pptr __3p_t1 ;

# 2379 "/home/claude/cfront-3/src/expr3.cpp"
__3tempPtr = (signif__4BitsCFv ( (const struct Bits *)(& __2tempBits )) - 1 );
__3t1 = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1AV )-> p__11Block_Pname [__3tempPtr ]))))) ))-> __O1__4expr.tp ;
__3p_t1 = is_ptr__4typeFv ( __3t1 ) ;
{ { int __3k ;

# 2383 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2383 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2382 "/home/claude/cfront-3/src/expr3.cpp"
__3k = (__1nav - 1 );

# 2382 "/home/claude/cfront-3/src/expr3.cpp"
for(;__3k > __3tempPtr ;__3k -- ) { 
# 2382 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__0__X43 ;

# 2382 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X44 ;

# 2383 "/home/claude/cfront-3/src/expr3.cpp"
if (! ( ((((unsigned long )__3k )>= ((const struct Bits *)__0_result )-> n__4Bits )?(((int )0 )):(((int )((((*( (__0__X43 = (const
# 2383 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *)(& ((const struct Bits *)__0_result )-> b__4Bits )), ( (__2__X44 = ( (((unsigned long )__3k )>> 5)) ),
# 2383 "/home/claude/cfront-3/src/expr3.cpp"
( (((const Bits_chunk *)(& (__0__X43 -> p__16Block_Bits_chunk [__2__X44 ]))))) ) ) ))>> (((unsigned long )__3k )& 31))& 1 ))))) )continue
# 2383 "/home/claude/cfront-3/src/expr3.cpp"
;
{ Ptype __4t2 ;

# 2384 "/home/claude/cfront-3/src/expr3.cpp"
__4t2 = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1AV )-> p__11Block_Pname [__3k ]))))) ))-> __O1__4expr.tp ;
if ((check__4typeFP4typeUcT2 ( __3t1 , __4t2 , (unsigned char )0 , (unsigned char )0 ) == 0 )|| const_problem )
# 2386 "/home/claude/cfront-3/src/expr3.cpp"
continue ;
# 2386 "/home/claude/cfront-3/src/expr3.cpp"

# 2387 "/home/claude/cfront-3/src/expr3.cpp"
{ int __4r ;
Pptr __4p_t2 ;

# 2387 "/home/claude/cfront-3/src/expr3.cpp"
__4r = pr_dominate__FP4typeT1 ( __3t1 , __4t2 ) ;
__4p_t2 = is_ptr__4typeFv ( __4t2 ) ;
if ((__4r == 1 )|| (__4p_t2 && (__4p_t2 -> typ__5pvtyp -> base__4node == 38 ))){ 
# 2389 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2389 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2390 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__3k )< __0_result -> n__4Bits )?(((*( (__0__X41 = (& __0_result -> b__4Bits )), ( (__2__X42 = ( (((unsigned
# 2390 "/home/claude/cfront-3/src/expr3.cpp"
long )__3k )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~ ((((unsigned long
# 2390 "/home/claude/cfront-3/src/expr3.cpp"
)1 ))<< (((unsigned long )__3k )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
}
if ((__4r == 2 )|| (__3p_t1 && (__3p_t1 -> typ__5pvtyp -> base__4node == 38 ))){ 
# 2392 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2392 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2393 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__3tempPtr )< __0_result -> n__4Bits )?(((*( (__0__X41 = (& __0_result -> b__4Bits )), ( (__2__X42 = ( (((unsigned
# 2393 "/home/claude/cfront-3/src/expr3.cpp"
long )__3tempPtr )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~ ((((unsigned long
# 2393 "/home/claude/cfront-3/src/expr3.cpp"
)1 ))<< (((unsigned long )__3tempPtr )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
break ;
}
if ((__4r == 0 )&& (miFlag == 0 ))miFlag = 1 ;

# 2396 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2396 "/home/claude/cfront-3/src/expr3.cpp"
}
}
( ((((unsigned long )__3tempPtr )< (& __2tempBits )-> n__4Bits )?(((*( (__0__X41 = (& (& __2tempBits )-> b__4Bits )), ( (__2__X42 =
# 2398 "/home/claude/cfront-3/src/expr3.cpp"
( (((unsigned long )__3tempPtr )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~
# 2398 "/home/claude/cfront-3/src/expr3.cpp"
((((unsigned long )1 ))<< (((unsigned long )__3tempPtr )& 31)))):0 ), (((struct Bits *)(& __2tempBits )))) ;

# 2398 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2398 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2399 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __2tempBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2399 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2399 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;

# 2399 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2403 "/home/claude/cfront-3/src/expr3.cpp"
if (__1max == 2){ 
# 2404 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits __2tempBits ;
int __2sigbit ;

# 2406 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2406 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2406 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2406 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X229 ;

# 2406 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__2__X230 ;

# 2404 "/home/claude/cfront-3/src/expr3.cpp"
( (( ( ( (__0__X229 = (& (& __2tempBits )-> b__4Bits )), ( (__2__X230 = (const struct Block_Bits_chunk *)(&
# 2404 "/home/claude/cfront-3/src/expr3.cpp"
((*((const struct Bits *)__0_result ))). b__4Bits )), ( ((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl ( (unsigned long )(sizeof (struct Block_Bits_chunk))) ))?(((void
# 2404 "/home/claude/cfront-3/src/expr3.cpp"
)copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X229 , __2__X230 ) )):(((void )0 ))), __0__X229 ) ) ) , ((& __2tempBits )-> n__4Bits = ((*((const struct
# 2404 "/home/claude/cfront-3/src/expr3.cpp"
Bits *)__0_result ))). n__4Bits )) , 0 ) ), (& __2tempBits )) ;
__2sigbit = (signif__4BitsCFv ( (const struct Bits *)(& __2tempBits )) - 1 );
( ((((unsigned long )__2sigbit )< (& __2tempBits )-> n__4Bits )?(((*( (__0__X41 = (& (& __2tempBits )-> b__4Bits )), ( (__2__X42 =
# 2406 "/home/claude/cfront-3/src/expr3.cpp"
( (((unsigned long )__2sigbit )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~
# 2406 "/home/claude/cfront-3/src/expr3.cpp"
((((unsigned long )1 ))<< (((unsigned long )__2sigbit )& 31)))):0 ), (((struct Bits *)(& __2tempBits )))) ;

# 2408 "/home/claude/cfront-3/src/expr3.cpp"
while (count__4BitsCFv ( (const struct Bits *)(& __2tempBits )) ){ 
# 2409 "/home/claude/cfront-3/src/expr3.cpp"
int __3tempPtr ;
Pname __3tname ;
bit __3done ;

# 2409 "/home/claude/cfront-3/src/expr3.cpp"
__3tempPtr = (signif__4BitsCFv ( (const struct Bits *)(& __2tempBits )) - 1 );
__3tname = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1AV )-> p__11Block_Pname [__3tempPtr ]))))) ));
__3done = 0 ;
{ { int __3k ;

# 2413 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2413 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2412 "/home/claude/cfront-3/src/expr3.cpp"
__3k = (__1nav - 1 );

# 2412 "/home/claude/cfront-3/src/expr3.cpp"
for(;__3k > __3tempPtr ;__3k -- ) { 
# 2412 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__0__X43 ;

# 2412 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X44 ;

# 2413 "/home/claude/cfront-3/src/expr3.cpp"
if ((! ( ((((unsigned long )__3k )>= ((const struct Bits *)__0_result )-> n__4Bits )?(((int )0 )):(((int )((((*( (__0__X43 = (const
# 2413 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *)(& ((const struct Bits *)__0_result )-> b__4Bits )), ( (__2__X44 = ( (((unsigned long )__3k )>> 5)) ),
# 2413 "/home/claude/cfront-3/src/expr3.cpp"
( (((const Bits_chunk *)(& (__0__X43 -> p__16Block_Bits_chunk [__2__X44 ]))))) ) ) ))>> (((unsigned long )__3k )& 31))& 1 ))))) )||
# 2413 "/home/claude/cfront-3/src/expr3.cpp"
(! ((*( (((Pname *)(& ((& __1udcBlock )-> p__11Block_Pname [__3k ]))))) ))))continue ;
if (((*( (((Pname *)(& ((& __1udcBlock )-> p__11Block_Pname [__3k ]))))) ))-> __O1__4expr.tp -> base__4node == 76 ){ 
# 2415 "/home/claude/cfront-3/src/expr3.cpp"
{ { Plist __5gl ;

# 2415 "/home/claude/cfront-3/src/expr3.cpp"
__5gl = (((struct gen *)(((struct gen *)((*( (((Pname *)(& ((& __1udcBlock )-> p__11Block_Pname [__3k ]))))) ))-> __O1__4expr.tp ))))-> fct_list__3gen ;

# 2415 "/home/claude/cfront-3/src/expr3.cpp"
for(;__5gl ;__5gl = __5gl -> l__9name_list ) { 
# 2416 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __6tt ;
Pname __6r ;

# 2418 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2418 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2418 "/home/claude/cfront-3/src/expr3.cpp"
register struct name *__0__X235 ;

# 2418 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 2418 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 2418 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 2416 "/home/claude/cfront-3/src/expr3.cpp"
__6tt = ( (__0__X235 = __5gl -> f__9name_list ), ( ((__0__X235 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X235 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 (
# 2416 "/home/claude/cfront-3/src/expr3.cpp"
(int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )->
# 2416 "/home/claude/cfront-3/src/expr3.cpp"
__O1__2ea.p = ((const void *)__0__X235 )), (& __0__X__V1400qmhwx544vcnm )) , (const struct ea *)( (__2__X16 = __0__X235 -> __O1__4expr.tp -> base__4node ),
# 2416 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __0__X__V1500qmhwx544vcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmhwx544vcnm )) ) , (const struct
# 2416 "/home/claude/cfront-3/src/expr3.cpp"
ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) -> returns__3fct ;
__6r = ((((*( (((Pname *)(& ((& __1udcBlock )-> p__11Block_Pname [__3tempPtr ]))))) ))== ((*( (((Pname *)(& ((& __1udcBlock )-> p__11Block_Pname [__3k ]))))) )))?bestOfPair__FP4nameT1P4type ( __3tname ,
# 2417 "/home/claude/cfront-3/src/expr3.cpp"
(struct name *)((*( (((const Pname *)(& (((const struct Block_Pname *)__1AV )-> p__11Block_Pname [__3k ]))))) )), __6tt ) :(((struct name *)0 )));

# 2419 "/home/claude/cfront-3/src/expr3.cpp"
if (__6r == __3tname )
# 2420 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__3k )< __0_result -> n__4Bits )?(((*( (__0__X41 = (& __0_result -> b__4Bits )), ( (__2__X42 =
# 2420 "/home/claude/cfront-3/src/expr3.cpp"
( (((unsigned long )__3k )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~
# 2420 "/home/claude/cfront-3/src/expr3.cpp"
((((unsigned long )1 ))<< (((unsigned long )__3k )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
if (__6r == ((*( (((const Pname *)(& (((const struct Block_Pname *)__1AV )-> p__11Block_Pname [__3k ]))))) ))){ 
# 2421 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2421 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2422 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__3tempPtr )< __0_result -> n__4Bits )?(((*( (__0__X41 = (& __0_result -> b__4Bits )), ( (__2__X42 = ( (((unsigned
# 2422 "/home/claude/cfront-3/src/expr3.cpp"
long )__3tempPtr )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~ ((((unsigned long
# 2422 "/home/claude/cfront-3/src/expr3.cpp"
)1 ))<< (((unsigned long )__3tempPtr )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
__3done = 1 ;
break ;
}
}

# 2426 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2426 "/home/claude/cfront-3/src/expr3.cpp"
}
}
else { 
# 2429 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __5tt ;
Pname __5r ;

# 2431 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2431 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2431 "/home/claude/cfront-3/src/expr3.cpp"
register struct name *__0__X236 ;

# 2431 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 2431 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 2431 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 2429 "/home/claude/cfront-3/src/expr3.cpp"
__5tt = ( (__0__X236 = ((*( (((Pname *)(& ((& __1udcBlock )-> p__11Block_Pname [__3k ]))))) ))), ( ((__0__X236 -> __O1__4expr.tp -> base__4node == 108 )?(((struct
# 2429 "/home/claude/cfront-3/src/expr3.cpp"
fct *)(((struct fct *)__0__X236 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF", (const
# 2429 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__0__X236 )), (& __0__X__V1400qmhwx544vcnm )) , (const struct ea *)(
# 2429 "/home/claude/cfront-3/src/expr3.cpp"
(__2__X16 = __0__X236 -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmhwx544vcnm ))
# 2429 "/home/claude/cfront-3/src/expr3.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) ->
# 2429 "/home/claude/cfront-3/src/expr3.cpp"
returns__3fct ;
__5r = ((((*( (((Pname *)(& ((& __1udcBlock )-> p__11Block_Pname [__3tempPtr ]))))) ))== ((*( (((Pname *)(& ((& __1udcBlock )-> p__11Block_Pname [__3k ]))))) )))?bestOfPair__FP4nameT1P4type ( __3tname ,
# 2430 "/home/claude/cfront-3/src/expr3.cpp"
(struct name *)((*( (((const Pname *)(& (((const struct Block_Pname *)__1AV )-> p__11Block_Pname [__3k ]))))) )), __5tt ) :(((struct name *)0 )));

# 2432 "/home/claude/cfront-3/src/expr3.cpp"
if (__5r == __3tname )
# 2433 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__3k )< __0_result -> n__4Bits )?(((*( (__0__X41 = (& __0_result -> b__4Bits )), ( (__2__X42 =
# 2433 "/home/claude/cfront-3/src/expr3.cpp"
( (((unsigned long )__3k )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~
# 2433 "/home/claude/cfront-3/src/expr3.cpp"
((((unsigned long )1 ))<< (((unsigned long )__3k )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
if (__5r == ((*( (((const Pname *)(& (((const struct Block_Pname *)__1AV )-> p__11Block_Pname [__3k ]))))) ))){ 
# 2434 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2434 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2435 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__3tempPtr )< __0_result -> n__4Bits )?(((*( (__0__X41 = (& __0_result -> b__4Bits )), ( (__2__X42 = ( (((unsigned
# 2435 "/home/claude/cfront-3/src/expr3.cpp"
long )__3tempPtr )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~ ((((unsigned long
# 2435 "/home/claude/cfront-3/src/expr3.cpp"
)1 ))<< (((unsigned long )__3tempPtr )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
break ;
}
}
if (__3done )
# 2440 "/home/claude/cfront-3/src/expr3.cpp"
break ;
}
( ((((unsigned long )__3tempPtr )< (& __2tempBits )-> n__4Bits )?(((*( (__0__X41 = (& (& __2tempBits )-> b__4Bits )), ( (__2__X42 =
# 2442 "/home/claude/cfront-3/src/expr3.cpp"
( (((unsigned long )__3tempPtr )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~
# 2442 "/home/claude/cfront-3/src/expr3.cpp"
((((unsigned long )1 ))<< (((unsigned long )__3tempPtr )& 31)))):0 ), (((struct Bits *)(& __2tempBits )))) ;

# 2442 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2442 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2443 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __2tempBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2443 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2443 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
}

# 2446 "/home/claude/cfront-3/src/expr3.cpp"
{ { ;

# 2446 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1udcBlock )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2446 "/home/claude/cfront-3/src/expr3.cpp"

# 2446 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rate )-> p__9Block_int ) , (((void )(((void )0 ))))) ))) ;
# 2446 "/home/claude/cfront-3/src/expr3.cpp"

# 2446 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1zeroBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2446 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2446 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
} 
# 2446 "/home/claude/cfront-3/src/expr3.cpp"
return ;
} 
# 2446 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 39 "/home/claude/cfront-3/src/overload.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 2449 "/home/claude/cfront-3/src/expr3.cpp"
Pname bestOfPair__FP4nameT1P4type (Pname __1a1 , Pname __1a2 , Ptype __1at )
# 2455 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2455 "/home/claude/cfront-3/src/expr3.cpp"
struct name *__0_result ;

# 2456 "/home/claude/cfront-3/src/expr3.cpp"
if (__1a1 -> __O1__4expr.tp == __1a2 -> __O1__4expr.tp )return (struct name *)0 ;

# 2458 "/home/claude/cfront-3/src/expr3.cpp"
{ struct Block_Pname __1tryBlock ;

# 2458 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __1tryBlock )-> n__11Block_Pname = 0 ), ( ((& __1tryBlock )-> p__11Block_Pname = 0 ), ( move__11Block_PnameFPP4nameUl ( (&
# 2458 "/home/claude/cfront-3/src/expr3.cpp"
__1tryBlock ), (Pname *)(((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* ((unsigned long )3 ))) )), ((unsigned long
# 2458 "/home/claude/cfront-3/src/expr3.cpp"
)3 )) , (& __1tryBlock )-> n__11Block_Pname ) ) ) ), (& __1tryBlock )) ;
((*( (((Pname *)(& ((& __1tryBlock )-> p__11Block_Pname [0 ]))))) ))= __1a1 ;
((*( (((Pname *)(& ((& __1tryBlock )-> p__11Block_Pname [1 ]))))) ))= __1a2 ;
{ struct Bits __1bestBits ;

# 2462 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2461 "/home/claude/cfront-3/src/expr3.cpp"
bestMatch__FRC11Block_PnameiP4type ( & __1bestBits , (const struct Block_Pname *)(& __1tryBlock ), 2 , __1at ) ;
if (count__4BitsCFv ( (const struct Bits *)(& __1bestBits )) == 1 ){ 
# 2462 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X238 ;

# 2463 "/home/claude/cfront-3/src/expr3.cpp"
{ { __0_result = ((*( (__2__X238 = (signif__4BitsCFv ( (const struct Bits *)(& __1bestBits )) - 1 )), ( (((Pname *)(&
# 2463 "/home/claude/cfront-3/src/expr3.cpp"
((& __1tryBlock )-> p__11Block_Pname [__2__X238 ]))))) ) ));

# 2466 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2466 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1bestBits )-> b__4Bits )), ( (__0__X45 ?(((void )(
# 2466 "/home/claude/cfront-3/src/expr3.cpp"
__dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 2466 "/home/claude/cfront-3/src/expr3.cpp"
)0 ))) ))))) ;

# 2466 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1tryBlock )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2466 "/home/claude/cfront-3/src/expr3.cpp"
} } 
# 2463 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} }
{ { __0_result = 0 ;
{ 
# 2466 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1bestBits )-> b__4Bits )), ( (__0__X45 ?(((void )(
# 2466 "/home/claude/cfront-3/src/expr3.cpp"
__dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 2466 "/home/claude/cfront-3/src/expr3.cpp"
)0 ))) ))))) ;

# 2466 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1tryBlock )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2466 "/home/claude/cfront-3/src/expr3.cpp"
} } 
# 2465 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} 
# 2465 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2465 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 41 "/home/claude/cfront-3/src/overload.h"

# 80 "/home/claude/cfront-3/src/Bits.h"
struct Bits *__aad__4BitsFRC4Bits (struct Bits *__0this , const struct Bits *);

# 2305 "/home/claude/cfront-3/src/expr3.cpp"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 2468 "/home/claude/cfront-3/src/expr3.cpp"
static void intersectRule__FRC16Block_BlockPnameiP4expr (
# 27 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits *__0_result , 
# 2468 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_BlockPname *__1intFun , int __1numFunc , Pexpr __1arg )
# 2472 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2473 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits __1zeroBits ;
struct Bits __1result ;

# 2476 "/home/claude/cfront-3/src/expr3.cpp"
int __1ai ;

# 2477 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2473 "/home/claude/cfront-3/src/expr3.cpp"
__ct__4BitsFUlT1 ( & __1zeroBits , (unsigned long )0 , (unsigned long )__1numFunc ) ;
__co__FRC4Bits ( & __1result , (const struct Bits *)(& __1zeroBits )) ;

# 2476 "/home/claude/cfront-3/src/expr3.cpp"
__1ai = 0 ;
{ { Pexpr __1aargu ;

# 2478 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X229 ;

# 2478 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__2__X230 ;

# 2477 "/home/claude/cfront-3/src/expr3.cpp"
__1aargu = __1arg ;

# 2477 "/home/claude/cfront-3/src/expr3.cpp"
for(;__1aargu ;__1aargu = __1aargu -> __O3__4expr.e2 ) { 
# 2478 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __2at ;
struct Bits __2tryit ;

# 2480 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2480 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X241 ;

# 2478 "/home/claude/cfront-3/src/expr3.cpp"
__2at = __1aargu -> __O2__4expr.e1 -> __O1__4expr.tp ;
bestMatch__FRC11Block_PnameiP4type ( & __2tryit , ( (__2__X241 = (__1ai ++ )), ( (((const BlockPname *)(& (((const struct Block_BlockPname *)__1intFun )-> p__16Block_BlockPname [__2__X241 ])))))
# 2479 "/home/claude/cfront-3/src/expr3.cpp"
) , __1numFunc , __2at ) ;
if (count__4BitsCFv ( (const struct Bits *)(& __2tryit )) == 1 )miFlag = -1;
__aad__4BitsFRC4Bits ( & __1result , (const struct Bits *)(& __2tryit )) ;
if (! count__4BitsCFv ( (const struct Bits *)(& __1result )) ){ 
# 2482 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X229 ;

# 2482 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__2__X230 ;

# 2482 "/home/claude/cfront-3/src/expr3.cpp"
{ { (*( (( ( ( (__0__X229 = (& __0_result -> b__4Bits )), ( (__2__X230 = (const struct
# 2482 "/home/claude/cfront-3/src/expr3.cpp"
Block_Bits_chunk *)(& ((*((const struct Bits *)(& __1zeroBits )))). b__4Bits )), ( ((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl ( (unsigned long )(sizeof
# 2482 "/home/claude/cfront-3/src/expr3.cpp"
(struct Block_Bits_chunk))) ))?(((void )copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X229 , __2__X230 ) )):(((void )0 ))), __0__X229 ) ) ) , (__0_result -> n__4Bits = ((*((const
# 2482 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits *)(& __1zeroBits )))). n__4Bits )) , 0 ) ), __0_result ) );

# 2485 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2485 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __2tryit )-> b__4Bits )), ( (__0__X45 ?(((void )(
# 2485 "/home/claude/cfront-3/src/expr3.cpp"
__dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 2485 "/home/claude/cfront-3/src/expr3.cpp"
)0 ))) ))))) ;

# 2485 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1result )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2485 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2485 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;

# 2485 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1zeroBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2485 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2485 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
} } 
# 2482 "/home/claude/cfront-3/src/expr3.cpp"
return ;
} 
# 2482 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2482 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __2tryit )-> b__4Bits )), ( (__0__X45 ?(((void )(
# 2482 "/home/claude/cfront-3/src/expr3.cpp"
__dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void
# 2482 "/home/claude/cfront-3/src/expr3.cpp"
)0 ))) ))))) ;
}
{ { (*( (( ( ( (__0__X229 = (& __0_result -> b__4Bits )), ( (__2__X230 = (const struct
# 2484 "/home/claude/cfront-3/src/expr3.cpp"
Block_Bits_chunk *)(& ((*((const struct Bits *)(& __1result )))). b__4Bits )), ( ((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl ( (unsigned long )(sizeof
# 2484 "/home/claude/cfront-3/src/expr3.cpp"
(struct Block_Bits_chunk))) ))?(((void )copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X229 , __2__X230 ) )):(((void )0 ))), __0__X229 ) ) ) , (__0_result -> n__4Bits = ((*((const
# 2484 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits *)(& __1result )))). n__4Bits )) , 0 ) ), __0_result ) );

# 2484 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1result )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2484 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2484 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;

# 2484 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1zeroBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2484 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2484 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
} 
# 2484 "/home/claude/cfront-3/src/expr3.cpp"
return ;
} 
# 2484 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2484 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 66 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 115 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 115 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 29 "/home/claude/cfront-3/src/expr3.cpp"
static void best_const__FRC11Block_PnameiP4type (struct Bits *__0_result , const struct Block_Pname *, int , Ptype );

# 39 "/home/claude/cfront-3/src/overload.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 2305 "/home/claude/cfront-3/src/expr3.cpp"

# 115 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 2447 "/home/claude/cfront-3/src/expr3.cpp"

# 39 "/home/claude/cfront-3/src/overload.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 87 "/home/claude/cfront-3/src/Bits.h"

# 2447 "/home/claude/cfront-3/src/expr3.cpp"

# 39 "/home/claude/cfront-3/src/overload.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 2487 "/home/claude/cfront-3/src/expr3.cpp"
static Pname breakTie__FRC11Block_PnameR4BitsP4expri (const struct Block_Pname *__1FV , struct Bits *__1bestOnes , Pexpr __1arg , int __1cO )
# 2497 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2498 "/home/claude/cfront-3/src/expr3.cpp"
int __1numFunc ;
struct Bits __1zeroBits ;
struct Bits __1result ;

# 2502 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Pname __1rfunc ;

# 2504 "/home/claude/cfront-3/src/expr3.cpp"
int __1i ;

# 2505 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2505 "/home/claude/cfront-3/src/expr3.cpp"
struct name *__0_result ;

# 2498 "/home/claude/cfront-3/src/expr3.cpp"
__1numFunc = ( ((const struct Bits *)__1bestOnes )-> n__4Bits ) ;
__ct__4BitsFUlT1 ( & __1zeroBits , (unsigned long )0 , (unsigned long )__1numFunc ) ;
__co__FRC4Bits ( & __1result , (const struct Bits *)(& __1zeroBits )) ;

# 2502 "/home/claude/cfront-3/src/expr3.cpp"
( (( ((& __1rfunc )-> n__11Block_Pname = 0 ), ( ((& __1rfunc )-> p__11Block_Pname = 0 ), ( move__11Block_PnameFPP4nameUl ( (&
# 2502 "/home/claude/cfront-3/src/expr3.cpp"
__1rfunc ), (Pname *)(((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* ((unsigned long )__1numFunc ))) )), ((unsigned long
# 2502 "/home/claude/cfront-3/src/expr3.cpp"
)__1numFunc )) , (& __1rfunc )-> n__11Block_Pname ) ) ) ), (& __1rfunc )) ;

# 2504 "/home/claude/cfront-3/src/expr3.cpp"
__1i = 0 ;
while ((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [__1i ]))))) )){ 
# 2505 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__0__X43 ;

# 2505 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X44 ;

# 2505 "/home/claude/cfront-3/src/expr3.cpp"
register struct name *__0__X244 ;

# 2505 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 2505 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 2505 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 2506 "/home/claude/cfront-3/src/expr3.cpp"
if (( ((((unsigned long )__1i )>= ((const struct Bits *)__1bestOnes )-> n__4Bits )?(((int )0 )):(((int )((((*( (__0__X43 = (const struct
# 2506 "/home/claude/cfront-3/src/expr3.cpp"
Block_Bits_chunk *)(& ((const struct Bits *)__1bestOnes )-> b__4Bits )), ( (__2__X44 = ( (((unsigned long )__1i )>> 5)) ), (
# 2506 "/home/claude/cfront-3/src/expr3.cpp"
(((const Bits_chunk *)(& (__0__X43 -> p__16Block_Bits_chunk [__2__X44 ]))))) ) ) ))>> (((unsigned long )__1i )& 31))& 1 ))))) )((*( (((Pname *)(&
# 2506 "/home/claude/cfront-3/src/expr3.cpp"
((& __1rfunc )-> p__11Block_Pname [__1i ]))))) ))= ( (__0__X244 = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [__1i ]))))) ))),
# 2506 "/home/claude/cfront-3/src/expr3.cpp"
( ((__0__X244 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X244 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF",
# 2506 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__0__X244 )), (& __0__X__V1400qmhwx544vcnm )) , (const struct
# 2506 "/home/claude/cfront-3/src/expr3.cpp"
ea *)( (__2__X16 = __0__X244 -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (&
# 2506 "/home/claude/cfront-3/src/expr3.cpp"
__0__X__V1500qmhwx544vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) )
# 2506 "/home/claude/cfront-3/src/expr3.cpp"
-> argtype__3fct ;
__1i ++ ;
}

# 2510 "/home/claude/cfront-3/src/expr3.cpp"
{ int __1stat ;

# 2511 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X251 ;

# 2511 "/home/claude/cfront-3/src/expr3.cpp"
register struct name *__0__X252 ;

# 2511 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 2511 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 2511 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 2510 "/home/claude/cfront-3/src/expr3.cpp"
__1stat = ( (__0__X252 = ((*( (__2__X251 = (signif__4BitsCFv ( (const struct Bits *)__1bestOnes ) - 1 )), ( (((const Pname *)(&
# 2510 "/home/claude/cfront-3/src/expr3.cpp"
(((const struct Block_Pname *)__1FV )-> p__11Block_Pname [__2__X251 ]))))) ) ))), ( ((__0__X252 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X252 -> __O1__4expr.tp )))):(
# 2510 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((&
# 2510 "/home/claude/cfront-3/src/expr3.cpp"
__0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__0__X252 )), (& __0__X__V1400qmhwx544vcnm )) , (const struct ea *)( (__2__X16 = __0__X252 -> __O1__4expr.tp ->
# 2510 "/home/claude/cfront-3/src/expr3.cpp"
base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmhwx544vcnm )) ) , (const
# 2510 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) -> f_static__3fct ;
{ { int __1k ;

# 2511 "/home/claude/cfront-3/src/expr3.cpp"
__1k = 0 ;

# 2511 "/home/claude/cfront-3/src/expr3.cpp"
for(;__1k < __1numFunc ;__1k ++ ) { 
# 2511 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__0__X43 ;

# 2511 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X44 ;

# 2512 "/home/claude/cfront-3/src/expr3.cpp"
if (( ((((unsigned long )__1k )>= ((const struct Bits *)__1bestOnes )-> n__4Bits )?(((int )0 )):(((int )((((*( (__0__X43 = (const struct
# 2512 "/home/claude/cfront-3/src/expr3.cpp"
Block_Bits_chunk *)(& ((const struct Bits *)__1bestOnes )-> b__4Bits )), ( (__2__X44 = ( (((unsigned long )__1k )>> 5)) ), (
# 2512 "/home/claude/cfront-3/src/expr3.cpp"
(((const Bits_chunk *)(& (__0__X43 -> p__16Block_Bits_chunk [__2__X44 ]))))) ) ) ))>> (((unsigned long )__1k )& 31))& 1 ))))) ){ 
# 2512 "/home/claude/cfront-3/src/expr3.cpp"
register
# 2512 "/home/claude/cfront-3/src/expr3.cpp"
struct name *__0__X245 ;

# 2512 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 2512 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 2512 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 2513 "/home/claude/cfront-3/src/expr3.cpp"
if (__1stat != ( (__0__X245 = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [__1k ]))))) ))), ( ((__0__X245 ->
# 2513 "/home/claude/cfront-3/src/expr3.cpp"
__O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X245 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF",
# 2513 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__0__X245 )), (& __0__X__V1400qmhwx544vcnm )) , (const struct
# 2513 "/home/claude/cfront-3/src/expr3.cpp"
ea *)( (__2__X16 = __0__X245 -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (&
# 2513 "/home/claude/cfront-3/src/expr3.cpp"
__0__X__V1500qmhwx544vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) )
# 2513 "/home/claude/cfront-3/src/expr3.cpp"
-> f_static__3fct ){ 
# 2513 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X246 ;

# 2514 "/home/claude/cfront-3/src/expr3.cpp"
fmError__FiRC11Block_PnameP4exprUc ( 1 , __1FV , __1arg , (unsigned char )__1cO ) ;
miFlag = 0 ;
{ { __0_result = ((*( (__2__X246 = (signif__4BitsCFv ( (const struct Bits *)__1bestOnes ) - 1 )), ( (((const Pname *)(&
# 2516 "/home/claude/cfront-3/src/expr3.cpp"
(((const struct Block_Pname *)__1FV )-> p__11Block_Pname [__2__X246 ]))))) ) ));

# 2516 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rfunc )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2516 "/home/claude/cfront-3/src/expr3.cpp"

# 2516 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1result )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2516 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2516 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;

# 2516 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1zeroBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2516 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2516 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
} 
# 2516 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} }
}
}

# 2522 "/home/claude/cfront-3/src/expr3.cpp"
{ { Pexpr __1aargu ;

# 2522 "/home/claude/cfront-3/src/expr3.cpp"
__1aargu = __1arg ;

# 2522 "/home/claude/cfront-3/src/expr3.cpp"
for(;__1aargu ;__1aargu = __1aargu -> __O3__4expr.e2 ) { 
# 2523 "/home/claude/cfront-3/src/expr3.cpp"
Ptype __2at ;

# 2526 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits __2temp ;

# 2527 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2523 "/home/claude/cfront-3/src/expr3.cpp"
__2at = __1aargu -> __O2__4expr.e1 -> __O1__4expr.tp ;

# 2526 "/home/claude/cfront-3/src/expr3.cpp"
best_const__FRC11Block_PnameiP4type ( & __2temp , (const struct Block_Pname *)(& __1rfunc ), __1numFunc , __2at ) ;
if (count__4BitsCFv ( (const struct Bits *)(& __2temp )) )__aad__4BitsFRC4Bits ( & __1result , (const struct Bits *)(& __2temp )) ;
# 2527 "/home/claude/cfront-3/src/expr3.cpp"

# 2528 "/home/claude/cfront-3/src/expr3.cpp"
if (! count__4BitsCFv ( (const struct Bits *)(& __1result )) ){ { 
# 2528 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( (
# 2528 "/home/claude/cfront-3/src/expr3.cpp"
(__0__X45 = (& (& __2temp )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv ( (void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void
# 2528 "/home/claude/cfront-3/src/expr3.cpp"
)(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 ))) ))))) ;

# 2528 "/home/claude/cfront-3/src/expr3.cpp"
break ;
} 
# 2528 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2530 "/home/claude/cfront-3/src/expr3.cpp"
{ { int __2k ;

# 2530 "/home/claude/cfront-3/src/expr3.cpp"
__2k = 0 ;

# 2530 "/home/claude/cfront-3/src/expr3.cpp"
for(;__2k < __1numFunc ;__2k ++ ) { 
# 2531 "/home/claude/cfront-3/src/expr3.cpp"
if ((*( (((Pname *)(& ((& __1rfunc )-> p__11Block_Pname [__2k ]))))) ))((*( (((Pname *)(& ((& __1rfunc )->
# 2531 "/home/claude/cfront-3/src/expr3.cpp"
p__11Block_Pname [__2k ]))))) ))= ((*( (((Pname *)(& ((& __1rfunc )-> p__11Block_Pname [__2k ]))))) ))-> __O1__4name.n_list ;
}

# 2532 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2532 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2532 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __2temp )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2532 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2532 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
}

# 2535 "/home/claude/cfront-3/src/expr3.cpp"
{ Pfct __1pf ;

# 2536 "/home/claude/cfront-3/src/expr3.cpp"
register struct Block_Bits_chunk *__0__X232 ;

# 2536 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__2__X233 ;

# 2536 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X249 ;

# 2536 "/home/claude/cfront-3/src/expr3.cpp"
register struct name *__0__X250 ;

# 2536 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 2536 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 2536 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 2535 "/home/claude/cfront-3/src/expr3.cpp"
__1pf = ( (__0__X250 = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [0 ]))))) ))), ( ((__0__X250 -> __O1__4expr.tp ->
# 2535 "/home/claude/cfront-3/src/expr3.cpp"
base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X250 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF",
# 2535 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__0__X250 )), (& __0__X__V1400qmhwx544vcnm )) , (const struct
# 2535 "/home/claude/cfront-3/src/expr3.cpp"
ea *)( (__2__X16 = __0__X250 -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (&
# 2535 "/home/claude/cfront-3/src/expr3.cpp"
__0__X__V1500qmhwx544vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) )
# 2535 "/home/claude/cfront-3/src/expr3.cpp"
;
if ((count__4BitsCFv ( (const struct Bits *)(& __1result )) >= 1 )&& __1pf -> memof__3fct ){ 
# 2537 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits __2temp ;

# 2538 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2538 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X229 ;

# 2538 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__2__X230 ;

# 2537 "/home/claude/cfront-3/src/expr3.cpp"
( (( ( ( (__0__X229 = (& (& __2temp )-> b__4Bits )), ( (__2__X230 = (const struct Block_Bits_chunk *)(&
# 2537 "/home/claude/cfront-3/src/expr3.cpp"
((*((const struct Bits *)(& __1zeroBits )))). b__4Bits )), ( ((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl ( (unsigned long )(sizeof (struct Block_Bits_chunk)))
# 2537 "/home/claude/cfront-3/src/expr3.cpp"
))?(((void )copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X229 , __2__X230 ) )):(((void )0 ))), __0__X229 ) ) ) , ((& __2temp )-> n__4Bits = ((*((const
# 2537 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits *)(& __1zeroBits )))). n__4Bits )) , 0 ) ), (& __2temp )) ;
{ { int __2k ;

# 2538 "/home/claude/cfront-3/src/expr3.cpp"
__2k = 0 ;

# 2538 "/home/claude/cfront-3/src/expr3.cpp"
for(;__2k < __1numFunc ;__2k ++ ) { 
# 2538 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__0__X43 ;

# 2538 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X44 ;

# 2539 "/home/claude/cfront-3/src/expr3.cpp"
if (( ((((unsigned long )__2k )>= ((const struct Bits *)__1bestOnes )-> n__4Bits )?(((int )0 )):(((int )((((*( (__0__X43 = (const struct
# 2539 "/home/claude/cfront-3/src/expr3.cpp"
Block_Bits_chunk *)(& ((const struct Bits *)__1bestOnes )-> b__4Bits )), ( (__2__X44 = ( (((unsigned long )__2k )>> 5)) ), (
# 2539 "/home/claude/cfront-3/src/expr3.cpp"
(((const Bits_chunk *)(& (__0__X43 -> p__16Block_Bits_chunk [__2__X44 ]))))) ) ) ))>> (((unsigned long )__2k )& 31))& 1 ))))) ){ 
# 2539 "/home/claude/cfront-3/src/expr3.cpp"
register
# 2539 "/home/claude/cfront-3/src/expr3.cpp"
struct name *__0__X247 ;

# 2539 "/home/claude/cfront-3/src/expr3.cpp"
unsigned long __2__X16 ;

# 2539 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1400qmhwx544vcnm ;

# 2539 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__X__V1500qmhwx544vcnm ;

# 2539 "/home/claude/cfront-3/src/expr3.cpp"
register struct name *__0__X248 ;

# 2539 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X37 ;

# 2539 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X38 ;

# 2540 "/home/claude/cfront-3/src/expr3.cpp"
if (__1stat != ( (__0__X247 = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [__2k ]))))) ))), ( ((__0__X247 ->
# 2540 "/home/claude/cfront-3/src/expr3.cpp"
__O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X247 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF",
# 2540 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__0__X247 )), (& __0__X__V1400qmhwx544vcnm )) , (const struct
# 2540 "/home/claude/cfront-3/src/expr3.cpp"
ea *)( (__2__X16 = __0__X247 -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (&
# 2540 "/home/claude/cfront-3/src/expr3.cpp"
__0__X__V1500qmhwx544vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) )
# 2540 "/home/claude/cfront-3/src/expr3.cpp"
-> f_static__3fct ){ 
# 2540 "/home/claude/cfront-3/src/expr3.cpp"
register struct Block_Bits_chunk *__0__X232 ;

# 2540 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__2__X233 ;

# 2541 "/home/claude/cfront-3/src/expr3.cpp"
( ( ( ((*( (__0__X232 = (& (& __1result )-> b__4Bits )), ( (__2__X233 = (const struct Block_Bits_chunk *)(&
# 2541 "/home/claude/cfront-3/src/expr3.cpp"
((*((const struct Bits *)(& __1zeroBits )))). b__4Bits )), ( __dl__FPv ( (void *)__0__X232 -> p__16Block_Bits_chunk ) , ( copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X232 ,
# 2541 "/home/claude/cfront-3/src/expr3.cpp"
__2__X233 ) , (((struct Block_Bits_chunk *)__0__X232 ))) ) ) ) )), ((& __1result )-> n__4Bits = ((*((const struct Bits *)(&
# 2541 "/home/claude/cfront-3/src/expr3.cpp"
__1zeroBits )))). n__4Bits )) , ((*(& __1result )))) , (((struct Bits *)(& __1result )))) ;
break ;
}
if (__1cO == ( (__0__X248 = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [__2k ]))))) ))), ( ((__0__X248 ->
# 2544 "/home/claude/cfront-3/src/expr3.cpp"
__O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X248 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF",
# 2544 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)( ((& __0__X__V1400qmhwx544vcnm )-> __O1__2ea.p = ((const void *)__0__X248 )), (& __0__X__V1400qmhwx544vcnm )) , (const struct
# 2544 "/home/claude/cfront-3/src/expr3.cpp"
ea *)( (__2__X16 = __0__X248 -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhwx544vcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (&
# 2544 "/home/claude/cfront-3/src/expr3.cpp"
__0__X__V1500qmhwx544vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) )
# 2544 "/home/claude/cfront-3/src/expr3.cpp"
-> f_const__3fct )( ((((unsigned long )__2k )< (& __2temp )-> n__4Bits )?(((*( (__0__X37 = (& (& __2temp )-> b__4Bits )), (
# 2544 "/home/claude/cfront-3/src/expr3.cpp"
(__2__X38 = ( (((unsigned long )__2k )>> 5)) ), ( (((Bits_chunk *)(& (__0__X37 -> p__16Block_Bits_chunk [__2__X38 ]))))) ) ) ))|=
# 2544 "/home/claude/cfront-3/src/expr3.cpp"
((((unsigned long )1 ))<< (((unsigned long )__2k )& 31))):0 ), (((struct Bits *)(& __2temp )))) ;
}
}
if (count__4BitsCFv ( (const struct Bits *)(& __2temp )) )__aad__4BitsFRC4Bits ( & __1result , (const struct Bits *)(& __2temp )) ;
# 2547 "/home/claude/cfront-3/src/expr3.cpp"

# 2547 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2547 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2547 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __2temp )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2547 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2547 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
}

# 2550 "/home/claude/cfront-3/src/expr3.cpp"
if ((count__4BitsCFv ( (const struct Bits *)(& __1result )) == 0 )|| (count__4BitsCFv ( (const struct Bits *)(& __1result )) >=
# 2550 "/home/claude/cfront-3/src/expr3.cpp"
2 )){ 
# 2551 "/home/claude/cfront-3/src/expr3.cpp"
fmError__FiRC11Block_PnameP4exprUc ( 1 , __1FV , __1arg , (unsigned char )__1cO ) ;
miFlag = 0 ;
}
else ( ( ( ((*( (__0__X232 = (& ((struct Bits *)__1bestOnes )-> b__4Bits )), ( (__2__X233 = (const struct
# 2554 "/home/claude/cfront-3/src/expr3.cpp"
Block_Bits_chunk *)(& ((*((const struct Bits *)(& __1result )))). b__4Bits )), ( __dl__FPv ( (void *)__0__X232 -> p__16Block_Bits_chunk ) , ( copy__16Block_Bits_chunkFRC16Block_Bits_chunk (
# 2554 "/home/claude/cfront-3/src/expr3.cpp"
__0__X232 , __2__X233 ) , (((struct Block_Bits_chunk *)__0__X232 ))) ) ) ) )), (((struct Bits *)__1bestOnes )-> n__4Bits = ((*((const struct
# 2554 "/home/claude/cfront-3/src/expr3.cpp"
Bits *)(& __1result )))). n__4Bits )) , ((*((struct Bits *)__1bestOnes )))) , (((struct Bits *)((struct Bits *)__1bestOnes )))) ;

# 2556 "/home/claude/cfront-3/src/expr3.cpp"
{ { __0_result = ((*( (__2__X249 = (signif__4BitsCFv ( (const struct Bits *)__1bestOnes ) - 1 )), ( (((const Pname *)(&
# 2556 "/home/claude/cfront-3/src/expr3.cpp"
(((const struct Block_Pname *)__1FV )-> p__11Block_Pname [__2__X249 ]))))) ) ));

# 2556 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )( __dl__FPv ( (void *)(& __1rfunc )-> p__11Block_Pname ) , (((void )(((void )0 ))))) ))) ;
# 2556 "/home/claude/cfront-3/src/expr3.cpp"

# 2556 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1result )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2556 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2556 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;

# 2556 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1zeroBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2556 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2556 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
} 
# 2556 "/home/claude/cfront-3/src/expr3.cpp"
return __0_result ;
} 
# 2556 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2556 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2556 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2556 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2556 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2556 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 103 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 115 "/home/claude/cfront-3/src/Bits.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 103 "/home/claude/cfront-3/src/Bits.h"

# 123 "/home/claude/cfront-3/src/Bits.h"

# 2559 "/home/claude/cfront-3/src/expr3.cpp"
static void best_const__FRC11Block_PnameiP4type (
# 29 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits *__0_result , 
# 2559 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Pname *__1CONV , int __1nfound , Ptype __1at )
# 2560 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2561 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits __1zeroBits ;

# 2564 "/home/claude/cfront-3/src/expr3.cpp"
struct Bits __1tempBits ;
int __1sigbit ;

# 2566 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X45 ;

# 2566 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2566 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2561 "/home/claude/cfront-3/src/expr3.cpp"
__ct__4BitsFUlT1 ( & __1zeroBits , (unsigned long )0 , (unsigned long )__1nfound ) ;
__co__FRC4Bits ( __0_result , (const struct Bits *)(& __1zeroBits )) ;

# 2564 "/home/claude/cfront-3/src/expr3.cpp"
__co__FRC4Bits ( & __1tempBits , (const struct Bits *)(& __1zeroBits )) ;
__1sigbit = (signif__4BitsCFv ( (const struct Bits *)(& __1tempBits )) - 1 );
( ((((unsigned long )__1sigbit )< (& __1tempBits )-> n__4Bits )?(((*( (__0__X41 = (& (& __1tempBits )-> b__4Bits )), ( (__2__X42 =
# 2566 "/home/claude/cfront-3/src/expr3.cpp"
( (((unsigned long )__1sigbit )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~
# 2566 "/home/claude/cfront-3/src/expr3.cpp"
((((unsigned long )1 ))<< (((unsigned long )__1sigbit )& 31)))):0 ), (((struct Bits *)(& __1tempBits )))) ;

# 2568 "/home/claude/cfront-3/src/expr3.cpp"
{ { int __1i ;

# 2568 "/home/claude/cfront-3/src/expr3.cpp"
__1i = 0 ;

# 2568 "/home/claude/cfront-3/src/expr3.cpp"
for(;__1i < __1nfound ;__1i ++ ) { 
# 2569 "/home/claude/cfront-3/src/expr3.cpp"
if (((*( (((const Pname *)(& (((const struct Block_Pname *)__1CONV )-> p__11Block_Pname [__1i ]))))) ))== 0 ){
# 2569 "/home/claude/cfront-3/src/expr3.cpp"

# 2569 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2569 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2570 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__1i )< (& __1tempBits )-> n__4Bits )?(((*( (__0__X41 = (& (& __1tempBits )-> b__4Bits )), ( (__2__X42 =
# 2570 "/home/claude/cfront-3/src/expr3.cpp"
( (((unsigned long )__1i )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~
# 2570 "/home/claude/cfront-3/src/expr3.cpp"
((((unsigned long )1 ))<< (((unsigned long )__1i )& 31)))):0 ), (((struct Bits *)(& __1tempBits )))) ;
( ((((unsigned long )__1i )< __0_result -> n__4Bits )?(((*( (__0__X41 = (& __0_result -> b__4Bits )), ( (__2__X42 = ( (((unsigned
# 2571 "/home/claude/cfront-3/src/expr3.cpp"
long )__1i )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~ ((((unsigned long
# 2571 "/home/claude/cfront-3/src/expr3.cpp"
)1 ))<< (((unsigned long )__1i )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
}
}

# 2575 "/home/claude/cfront-3/src/expr3.cpp"
while (count__4BitsCFv ( (const struct Bits *)(& __1tempBits )) ){ 
# 2576 "/home/claude/cfront-3/src/expr3.cpp"
int __2tempPtr ;
Pname __2t1name ;

# 2576 "/home/claude/cfront-3/src/expr3.cpp"
__2tempPtr = (signif__4BitsCFv ( (const struct Bits *)(& __1tempBits )) - 1 );
__2t1name = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1CONV )-> p__11Block_Pname [__2tempPtr ]))))) ));
{ { int __2k ;

# 2579 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2579 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2578 "/home/claude/cfront-3/src/expr3.cpp"
__2k = (__1nfound - 1 );

# 2578 "/home/claude/cfront-3/src/expr3.cpp"
for(;__2k > __2tempPtr ;__2k -- ) { 
# 2578 "/home/claude/cfront-3/src/expr3.cpp"
const struct Block_Bits_chunk *__0__X43 ;

# 2578 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X44 ;

# 2579 "/home/claude/cfront-3/src/expr3.cpp"
if (! ( ((((unsigned long )__2k )>= ((const struct Bits *)__0_result )-> n__4Bits )?(((int )0 )):(((int )((((*( (__0__X43 = (const
# 2579 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *)(& ((const struct Bits *)__0_result )-> b__4Bits )), ( (__2__X44 = ( (((unsigned long )__2k )>> 5)) ),
# 2579 "/home/claude/cfront-3/src/expr3.cpp"
( (((const Bits_chunk *)(& (__0__X43 -> p__16Block_Bits_chunk [__2__X44 ]))))) ) ) ))>> (((unsigned long )__2k )& 31))& 1 ))))) )continue
# 2579 "/home/claude/cfront-3/src/expr3.cpp"
;
{ Pname __3t2name ;
Ptype __3t1 ;
Ptype __3t2 ;
Pptr __3p1 ;

# 2583 "/home/claude/cfront-3/src/expr3.cpp"
Pptr __3p2 ;

# 2580 "/home/claude/cfront-3/src/expr3.cpp"
__3t2name = ((*( (((const Pname *)(& (((const struct Block_Pname *)__1CONV )-> p__11Block_Pname [__2k ]))))) ));
__3t1 = __2t1name -> __O1__4expr.tp ;
__3t2 = __3t2name -> __O1__4expr.tp ;
__3p1 = is_ref__4typeFv ( __3t1 ) ;

# 2583 "/home/claude/cfront-3/src/expr3.cpp"
__3p2 = is_ref__4typeFv ( __3t2 ) ;
if (__3p1 && (! __3p2 ))__3t1 = __3p1 -> typ__5pvtyp ;
if (__3p2 && (! __3p1 ))__3t2 = __3p2 -> typ__5pvtyp ;
( (__3p1 = is_ptr__4typeFv ( __3t1 ) ), (__3p2 = is_ptr__4typeFv ( __3t2 ) )) ;
if (__3p1 && __3p2 ){ 
# 2587 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2587 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2588 "/home/claude/cfront-3/src/expr3.cpp"
if ((check__4typeFP4typeUcT2 ( __1at , __3t1 , (unsigned char )76 , (unsigned char )0 ) == 0 )&& check__4typeFP4typeUcT2 ( __1at ,
# 2588 "/home/claude/cfront-3/src/expr3.cpp"
__3t2 , (unsigned char )76 , (unsigned char )0 ) )
# 2592 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__2k )< __0_result -> n__4Bits )?(((*( (__0__X41 =
# 2592 "/home/claude/cfront-3/src/expr3.cpp"
(& __0_result -> b__4Bits )), ( (__2__X42 = ( (((unsigned long )__2k )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 ->
# 2592 "/home/claude/cfront-3/src/expr3.cpp"
p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~ ((((unsigned long )1 ))<< (((unsigned long )__2k )& 31)))):0 ), (((struct Bits *)__0_result )))
# 2592 "/home/claude/cfront-3/src/expr3.cpp"
;
else if (check__4typeFP4typeUcT2 ( __1at , __3t1 , (unsigned char )76 , (unsigned char )0 ) && (check__4typeFP4typeUcT2 ( __1at ,
# 2593 "/home/claude/cfront-3/src/expr3.cpp"
__3t2 , (unsigned char )76 , (unsigned char )0 ) == 0 ))
# 2596 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2596 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2596 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2597 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__2tempPtr )< __0_result -> n__4Bits )?(((*( (__0__X41 = (& __0_result -> b__4Bits )), ( (__2__X42 = ( (((unsigned
# 2597 "/home/claude/cfront-3/src/expr3.cpp"
long )__2tempPtr )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~ ((((unsigned long
# 2597 "/home/claude/cfront-3/src/expr3.cpp"
)1 ))<< (((unsigned long )__2tempPtr )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
break ;
}
}
else { 
# 2602 "/home/claude/cfront-3/src/expr3.cpp"
Pptr __4p1 ;
Pptr __4p2 ;

# 2602 "/home/claude/cfront-3/src/expr3.cpp"
__4p1 = is_ref__4typeFv ( __3t1 ) ;
__4p2 = is_ref__4typeFv ( __3t2 ) ;

# 2605 "/home/claude/cfront-3/src/expr3.cpp"
if (__4p1 && __4p2 ){ 
# 2605 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2605 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2606 "/home/claude/cfront-3/src/expr3.cpp"
if ((check__4typeFP4typeUcT2 ( __1at , __4p1 -> typ__5pvtyp , (unsigned char )76 , (unsigned char )0 ) == 0 )&& check__4typeFP4typeUcT2 (
# 2606 "/home/claude/cfront-3/src/expr3.cpp"
__1at , __4p2 -> typ__5pvtyp , (unsigned char )76 , (unsigned char )0 ) )
# 2610 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__2k )< __0_result ->
# 2610 "/home/claude/cfront-3/src/expr3.cpp"
n__4Bits )?(((*( (__0__X41 = (& __0_result -> b__4Bits )), ( (__2__X42 = ( (((unsigned long )__2k )>> 5)) ), (
# 2610 "/home/claude/cfront-3/src/expr3.cpp"
(((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~ ((((unsigned long )1 ))<< (((unsigned long )__2k )& 31)))):0 ),
# 2610 "/home/claude/cfront-3/src/expr3.cpp"
(((struct Bits *)__0_result ))) ;
else if (check__4typeFP4typeUcT2 ( __1at , __4p1 -> typ__5pvtyp , (unsigned char )76 , (unsigned char )0 ) && (check__4typeFP4typeUcT2 (
# 2611 "/home/claude/cfront-3/src/expr3.cpp"
__1at , __4p2 -> typ__5pvtyp , (unsigned char )76 , (unsigned char )0 ) == 0 ))
# 2615 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2615 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Bits_chunk *__0__X41 ;

# 2615 "/home/claude/cfront-3/src/expr3.cpp"
int __2__X42 ;

# 2616 "/home/claude/cfront-3/src/expr3.cpp"
( ((((unsigned long )__2tempPtr )< __0_result -> n__4Bits )?(((*( (__0__X41 = (& __0_result -> b__4Bits )), ( (__2__X42 = ( (((unsigned
# 2616 "/home/claude/cfront-3/src/expr3.cpp"
long )__2tempPtr )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~ ((((unsigned long
# 2616 "/home/claude/cfront-3/src/expr3.cpp"
)1 ))<< (((unsigned long )__2tempPtr )& 31)))):0 ), (((struct Bits *)__0_result ))) ;
break ;
}
}
}

# 2620 "/home/claude/cfront-3/src/expr3.cpp"
}
}
( ((((unsigned long )__2tempPtr )< (& __1tempBits )-> n__4Bits )?(((*( (__0__X41 = (& (& __1tempBits )-> b__4Bits )), ( (__2__X42 =
# 2622 "/home/claude/cfront-3/src/expr3.cpp"
( (((unsigned long )__2tempPtr )>> 5)) ), ( (((Bits_chunk *)(& (__0__X41 -> p__16Block_Bits_chunk [__2__X42 ]))))) ) ) ))&= (~
# 2622 "/home/claude/cfront-3/src/expr3.cpp"
((((unsigned long )1 ))<< (((unsigned long )__2tempPtr )& 31)))):0 ), (((struct Bits *)(& __1tempBits )))) ;

# 2622 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2622 "/home/claude/cfront-3/src/expr3.cpp"
}
}
{ { ;

# 2624 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1tempBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2624 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2624 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;

# 2624 "/home/claude/cfront-3/src/expr3.cpp"
( (((void )(((void )( ( (__0__X45 = (& (& __1zeroBits )-> b__4Bits )), ( (__0__X45 ?(((void )( __dl__FPv (
# 2624 "/home/claude/cfront-3/src/expr3.cpp"
(void *)__0__X45 -> p__16Block_Bits_chunk ) , (__0__X45 ?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) ) , (((void )0 )))
# 2624 "/home/claude/cfront-3/src/expr3.cpp"
))))) ;
} 
# 2624 "/home/claude/cfront-3/src/expr3.cpp"
return ;
} 
# 2624 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2624 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 39 "/home/claude/cfront-3/src/overload.h"

# 1288 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 952 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 39 "/home/claude/cfront-3/src/overload.h"

# 2627 "/home/claude/cfront-3/src/expr3.cpp"
void fmError__FiRC11Block_PnameP4exprUc (int __1errorKind , const struct Block_Pname *__1FV , Pexpr __1arg , bit __1co )
# 2628 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2629 "/home/claude/cfront-3/src/expr3.cpp"
Pname __1fn ;

# 2629 "/home/claude/cfront-3/src/expr3.cpp"
__1fn = ((((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [0 ]))))) ))-> __O1__4expr.tp -> base__4node == 76 )?(((struct gen *)(((struct gen *)((*(
# 2629 "/home/claude/cfront-3/src/expr3.cpp"
(((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [0 ]))))) ))-> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list :(((struct name *)((*( (((const Pname *)(& (((const
# 2629 "/home/claude/cfront-3/src/expr3.cpp"
struct Block_Pname *)__1FV )-> p__11Block_Pname [0 ]))))) )))));

# 2632 "/home/claude/cfront-3/src/expr3.cpp"
switch (__1errorKind ){ 
# 2633 "/home/claude/cfront-3/src/expr3.cpp"
case 0 :
# 2634 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCc ( (int )'e' , (const char *)"no match for call: ") ;
# 2634 "/home/claude/cfront-3/src/expr3.cpp"

# 2635 "/home/claude/cfront-3/src/expr3.cpp"
break ;
case 1 :
# 2637 "/home/claude/cfront-3/src/expr3.cpp"
ambig = 1 ;
error__FiPCc ( (int )'e' , (const char *)"ambiguous call: ") ;
break ;
}

# 2643 "/home/claude/cfront-3/src/expr3.cpp"
{ Pclass __1tmp ;

# 2644 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X268 ;

# 2644 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X269 ;

# 2643 "/home/claude/cfront-3/src/expr3.cpp"
__1tmp = ( ((__1fn -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp )))):(((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__1fn -> __O1__4expr.tp ))))->
# 2643 "/home/claude/cfront-3/src/expr3.cpp"
fct_list__3gen -> f__9name_list -> __O1__4expr.tp )))))) -> memof__3fct ;

# 2645 "/home/claude/cfront-3/src/expr3.cpp"
if (__1tmp ){ 
# 2645 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V255 ;

# 2645 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V256 ;

# 2645 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"%s %t* -> ", (const struct ea *)( ((&
# 2645 "/home/claude/cfront-3/src/expr3.cpp"
__0__V255 )-> __O1__2ea.p = ((const void *)(__1co ?"const":(((char *)""))))),
# 2645 "/home/claude/cfront-3/src/expr3.cpp"
(& __0__V255 )) , (const struct ea *)( ((& __0__V256 )-> __O1__2ea.p = ((const void *)__1tmp )), (& __0__V256 ))
# 2645 "/home/claude/cfront-3/src/expr3.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__1fn -> n_oper__4name && (__1fn -> n_oper__4name != 161 ))
# 2647 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2647 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V257 ;

# 2647 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"operator %s(", (const struct ea *)( (__2__X268 =
# 2647 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)(keys [__1fn -> n_oper__4name ])), ( ((& __0__V257 )-> __O1__2ea.p = __2__X268 ), (& __0__V257 )) ) , (const
# 2647 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (__1fn -> n_oper__4name == 161 ){ 
# 2649 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2649 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V258 ;

# 2649 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V259 ;

# 2649 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"%t::%t(", (const struct ea *)( ((&
# 2649 "/home/claude/cfront-3/src/expr3.cpp"
__0__V258 )-> __O1__2ea.p = ((const void *)__1tmp )), (& __0__V258 )) , (const struct ea *)( ((& __0__V259 )-> __O1__2ea.p =
# 2649 "/home/claude/cfront-3/src/expr3.cpp"
((const void *)__1tmp )), (& __0__V259 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else { 
# 2651 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V260 ;

# 2651 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"%s(", (const struct ea *)( (__2__X269 =
# 2651 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)__1fn -> __O2__4expr.string ), ( ((& __0__V260 )-> __O1__2ea.p = __2__X269 ), (& __0__V260 )) ) , (const
# 2651 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 2653 "/home/claude/cfront-3/src/expr3.cpp"
if (__1arg ){ 
# 2654 "/home/claude/cfront-3/src/expr3.cpp"
Pexpr __2tmp ;

# 2655 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X270 ;

# 2654 "/home/claude/cfront-3/src/expr3.cpp"
__2tmp = __1arg ;
{ 
# 2655 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V261 ;

# 2655 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"%t", (const struct ea *)( (__2__X270 =
# 2655 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)skiptypedefs__4typeFv ( __2tmp -> __O2__4expr.e1 -> __O1__4expr.tp ) ), ( ((& __0__V261 )-> __O1__2ea.p = __2__X270 ), (& __0__V261 ))
# 2655 "/home/claude/cfront-3/src/expr3.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
while (__2tmp = __2tmp -> __O3__4expr.e2 ){ 
# 2656 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X271 ;

# 2657 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2657 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V262 ;

# 2657 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)",%t", (const struct ea *)( (__2__X271 =
# 2657 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)skiptypedefs__4typeFv ( __2tmp -> __O2__4expr.e1 -> __O1__4expr.tp ) ), ( ((& __0__V262 )-> __O1__2ea.p = __2__X271 ), (& __0__V262 ))
# 2657 "/home/claude/cfront-3/src/expr3.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
} }
error__FiPCc ( (int )'c' , (const char *)")\n") ;

# 2663 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2663 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V263 ;

# 2663 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'C' , (const char *)"choice of%ns:\n", (const struct ea *)( ((&
# 2663 "/home/claude/cfront-3/src/expr3.cpp"
__0__V263 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V263 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2663 "/home/claude/cfront-3/src/expr3.cpp"
(const struct ea *)ea0 ) ;

# 2665 "/home/claude/cfront-3/src/expr3.cpp"
if (((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [0 ]))))) ))-> __O1__4expr.tp -> base__4node == 76 ){ 
# 2666 "/home/claude/cfront-3/src/expr3.cpp"
int __2num_templ ;
# 2666 "/home/claude/cfront-3/src/expr3.cpp"

# 2667 "/home/claude/cfront-3/src/expr3.cpp"
int __2no_const ;
int __2num_all ;

# 2666 "/home/claude/cfront-3/src/expr3.cpp"
__2num_templ = 0 ;
__2no_const = 0 ;
__2num_all = 0 ;
{ { Plist __2gl ;

# 2669 "/home/claude/cfront-3/src/expr3.cpp"
__2gl = (((struct gen *)(((struct gen *)((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [0 ]))))) ))-> __O1__4expr.tp ))))-> fct_list__3gen ;

# 2669 "/home/claude/cfront-3/src/expr3.cpp"
for(;__2gl ;__2gl = __2gl -> l__9name_list ) { 
# 2669 "/home/claude/cfront-3/src/expr3.cpp"
struct name *__0__X272 ;

# 2669 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X273 ;

# 2670 "/home/claude/cfront-3/src/expr3.cpp"
if (( (__0__X272 = __2gl -> f__9name_list ), ( __0__X272 -> n_template_fct__4name ) ) ){ 
# 2671 "/home/claude/cfront-3/src/expr3.cpp"
__2num_templ ++ ;
}
else { 
# 2673 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V264 ;

# 2673 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'C' , (const char *)"	%a;\n", (const struct ea *)( (__2__X273 =
# 2673 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)__2gl -> f__9name_list ), ( ((& __0__V264 )-> __O1__2ea.p = __2__X273 ), (& __0__V264 )) ) , (const
# 2673 "/home/claude/cfront-3/src/expr3.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__1co && (! (((struct fct *)(((struct fct *)__2gl -> f__9name_list -> __O1__4expr.tp ))))-> f_const__3fct ))__2no_const ++ ;
__2num_all ++ ;
}
if (__2num_templ ){ 
# 2683 "/home/claude/cfront-3/src/expr3.cpp"
{ 
# 2683 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V265 ;

# 2683 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V266 ;

# 2683 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'C' , (const char *)"	%d template version%s;\n", (const struct ea *)( ((
# 2683 "/home/claude/cfront-3/src/expr3.cpp"
((& __0__V265 )-> __O1__2ea.i = ((unsigned long )__2num_templ )), 0 ) ), (& __0__V265 )) , (const struct ea *)(
# 2683 "/home/claude/cfront-3/src/expr3.cpp"
((& __0__V266 )-> __O1__2ea.p = ((const void *)((__2num_templ == 1 )?"":(((char *)"s"))))),
# 2683 "/home/claude/cfront-3/src/expr3.cpp"
(& __0__V266 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
if (__2no_const == __2num_all )
# 2686 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCc ( (int )'C' , (const char *)"(no usable const member function)\n") ;
# 2686 "/home/claude/cfront-3/src/expr3.cpp"

# 2688 "/home/claude/cfront-3/src/expr3.cpp"
return ;

# 2688 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2688 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 2691 "/home/claude/cfront-3/src/expr3.cpp"
{ int __1numFunc ;

# 2691 "/home/claude/cfront-3/src/expr3.cpp"
__1numFunc = ( ((const struct Block_Pname *)__1FV )-> n__11Block_Pname ) ;
{ { int __1i ;

# 2692 "/home/claude/cfront-3/src/expr3.cpp"
__1i = 0 ;

# 2692 "/home/claude/cfront-3/src/expr3.cpp"
for(;__1i < __1numFunc ;__1i ++ ) { 
# 2692 "/home/claude/cfront-3/src/expr3.cpp"
const void *__2__X274 ;

# 2693 "/home/claude/cfront-3/src/expr3.cpp"
if ((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [__1i ]))))) )){ 
# 2693 "/home/claude/cfront-3/src/expr3.cpp"
struct ea __0__V267 ;

# 2693 "/home/claude/cfront-3/src/expr3.cpp"
error__FiPCcRC2eaN33 ( (int )'C' , (const char *)"	%a;\n", (const struct ea *)( (__2__X274 =
# 2693 "/home/claude/cfront-3/src/expr3.cpp"
(const void *)((*( (((const Pname *)(& (((const struct Block_Pname *)__1FV )-> p__11Block_Pname [__1i ]))))) ))), ( ((& __0__V267 )-> __O1__2ea.p =
# 2693 "/home/claude/cfront-3/src/expr3.cpp"
__2__X274 ), (& __0__V267 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 2693 "/home/claude/cfront-3/src/expr3.cpp"
;
} }

# 2694 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2694 "/home/claude/cfront-3/src/expr3.cpp"
}

# 2694 "/home/claude/cfront-3/src/expr3.cpp"
}
} 
# 2694 "/home/claude/cfront-3/src/expr3.cpp"
}
}

# 39 "/home/claude/cfront-3/src/overload.h"
static Pname *__vc__11Block_PnameFi (struct Block_Pname *__0this , 
# 39 "/home/claude/cfront-3/src/overload.h"
int __2i ){ 
# 39 "/home/claude/cfront-3/src/overload.h"
return (& (__0this -> p__11Block_Pname [__2i ]));

# 39 "/home/claude/cfront-3/src/overload.h"
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

# 2695 "/home/claude/cfront-3/src/expr3.cpp"

/* the end */
