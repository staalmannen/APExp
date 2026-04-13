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
union YYSTYPE;

# 118 "/home/claude/cfront-3/src/yystype.h"
typedef union YYSTYPE YYSTYPE ;

# 100 "/home/claude/cfront-3/src/yystype.h"
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

# 120 "/home/claude/cfront-3/src/yystype.h"
extern union YYSTYPE yylval ;

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

# 31 "/home/claude/cfront-3/src/tqueue.h"
void *__nw__7toknodeSFUl (size_t );
void __dl__7toknodeSFPvUl (void *, size_t );

# 35 "/home/claude/cfront-3/src/tqueue.h"
extern struct toknode *front ;

# 43 "/home/claude/cfront-3/src/tqueue.h"
extern int yychar ;
extern union YYSTYPE yylval ;
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
struct Block_short;

# 41 "/home/claude/cfront-3/src/lex.cpp"
struct Block_short {	/* sizeof Block_short == 16 */

# 41 "/home/claude/cfront-3/src/lex.cpp"
short *p__11Block_short ;

# 41 "/home/claude/cfront-3/src/lex.cpp"
size_t n__11Block_short ;
};

# 41 "/home/claude/cfront-3/src/lex.cpp"
void move__11Block_shortFPsUl (struct Block_short *__0this , short *, size_t );

# 41 "/home/claude/cfront-3/src/lex.cpp"
void copy__11Block_shortFRC11Block_short (struct Block_short *__0this , const struct Block_short *);

# 41 "/home/claude/cfront-3/src/lex.cpp"
size_t grow__11Block_shortFUl (struct Block_short *__0this , size_t );

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

# 44 "/home/claude/cfront-3/src/lex.cpp"
extern int in_progress__17templ_compilation;

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 46 "/home/claude/cfront-3/src/lex.cpp"
char *strdup (const char *__1s1 )
# 52 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 53 "/home/claude/cfront-3/src/lex.cpp"
char *__1s2 ;

# 55 "/home/claude/cfront-3/src/lex.cpp"
__1s2 = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __1s1 ) + 1 ))) ));
return ((__1s2 == 0 )?(((char *)0 )):strcpy ( __1s2 , __1s1 ) );
}

# 104 "/home/claude/cfront-3/src/lex.cpp"

# 105 "/home/claude/cfront-3/src/lex.cpp"

# 108 "/home/claude/cfront-3/src/lex.cpp"
static char inbuf [8184];
static char *txtmax = (& (inbuf [8183]));
static char *txtstart = 0 ;
static char *txtfree = 0 ;
struct buf;

# 113 "/home/claude/cfront-3/src/lex.cpp"
static struct buf *bufhead ;
static struct buf *freebuf ;

# 116 "/home/claude/cfront-3/src/lex.cpp"
static struct loc tloc ;

# 118 "/home/claude/cfront-3/src/lex.cpp"
struct buf {	/* sizeof buf == 4096 */
struct buf *next__3buf ;
char chars__3buf [4088];
};

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 124 "/home/claude/cfront-3/src/lex.cpp"
int new_buf__Fc (char __1c )
# 125 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 127 "/home/claude/cfront-3/src/lex.cpp"
struct buf *__1pbuf ;
if (freebuf ){ 
# 129 "/home/claude/cfront-3/src/lex.cpp"
__1pbuf = freebuf ;
freebuf = freebuf -> next__3buf ;
}
else 
# 133 "/home/claude/cfront-3/src/lex.cpp"
__1pbuf = (((struct buf *)__nw__FUl ( sizeof (struct buf )) ));
__1pbuf -> next__3buf = bufhead ;
bufhead = __1pbuf ;

# 137 "/home/claude/cfront-3/src/lex.cpp"
if (4088< (txtmax - txtstart ))error__FiP3locPCcRC2eaN34 ( (int )'l' , & tloc , (const char *)"lexical token too long",
# 137 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 140 "/home/claude/cfront-3/src/lex.cpp"
{ char *__1p ;

# 140 "/home/claude/cfront-3/src/lex.cpp"
__1p = txtstart ;
txtstart = (txtfree = (& (__1pbuf -> chars__3buf [0 ])));
while (__1p < txtmax )((*(txtfree ++ )))= ((*(__1p ++ )));
((*(txtfree ++ )))= __1c ;
txtmax = (& (__1pbuf -> chars__3buf [4087]));
return 0 ;

# 145 "/home/claude/cfront-3/src/lex.cpp"
}
}

# 153 "/home/claude/cfront-3/src/lex.cpp"
static int Nfile ;

# 491 "/home/claude/cfront-3/src/template.h"

# 154 "/home/claude/cfront-3/src/lex.cpp"
static struct Block_CPchar file_name ;

# 157 "/home/claude/cfront-3/src/lex.cpp"
static int tcurr_file ;

# 159 "/home/claude/cfront-3/src/lex.cpp"
int linkage = 0;

# 161 "/home/claude/cfront-3/src/lex.cpp"
static int lvec [10]= { 0} ;
static int lcount = 0 ;

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 164 "/home/claude/cfront-3/src/lex.cpp"
void set_linkage__FPCc (const char *__1p )
# 165 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 166 "/home/claude/cfront-3/src/lex.cpp"
if ((__1p == 0 )|| (((*__1p ))== 0 )){ 
# 167 "/home/claude/cfront-3/src/lex.cpp"
if (lcount > 0 )linkage = (lvec [(-- lcount )]);
# 167 "/home/claude/cfront-3/src/lex.cpp"

# 168 "/home/claude/cfront-3/src/lex.cpp"
}
else { 
# 170 "/home/claude/cfront-3/src/lex.cpp"
if (10<= (++ lcount )){ 
# 171 "/home/claude/cfront-3/src/lex.cpp"
error__FiPCc ( (int )'l' , (const char *)"linkage directive nested too deep")
# 171 "/home/claude/cfront-3/src/lex.cpp"
;
-- lcount ;
}
else 
# 173 "/home/claude/cfront-3/src/lex.cpp"
if (strcmp ( __1p , (const char *)"C") == 0 )
# 174 "/home/claude/cfront-3/src/lex.cpp"
(lvec [lcount ])= (linkage =
# 174 "/home/claude/cfront-3/src/lex.cpp"
1);
else if (strcmp ( __1p , (const char *)"C++") == 0 )
# 176 "/home/claude/cfront-3/src/lex.cpp"
(lvec [lcount ])= (linkage =
# 176 "/home/claude/cfront-3/src/lex.cpp"
2);
else { 
# 178 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 178 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V26 ;

# 178 "/home/claude/cfront-3/src/lex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s linkage", (const struct ea *)( ((& __0__V26 )-> __O1__2ea.p =
# 178 "/home/claude/cfront-3/src/lex.cpp"
((const void *)__1p )), (& __0__V26 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 178 "/home/claude/cfront-3/src/lex.cpp"
ea *)ea0 ) ;
-- lcount ;
} }
}
}

# 136 "/home/claude/incl-linux32/stdio.h"
extern void *_get_stdout (void );

# 184 "/home/claude/cfront-3/src/lex.cpp"
void *out_file = 0 ; /* initialized in _main */

# 135 "/home/claude/incl-linux32/stdio.h"
extern void *_get_stdin (void );

# 185 "/home/claude/cfront-3/src/lex.cpp"
void *in_file = 0 ;
void *pt_file = 0 ;
void *dtpt_file = 0 ;
static bit doneflag = 0 ;
int first_file = 0 ;

# 191 "/home/claude/cfront-3/src/lex.cpp"
static Ptable keyword_table ;

# 193 "/home/claude/cfront-3/src/lex.cpp"
static int p_level = 0 ;
static int b_level = 0 ;

# 208 "/home/claude/cfront-3/src/lex.cpp"
static short lxmask [129];

# 210 "/home/claude/cfront-3/src/lex.cpp"
int saved = 0 ;

# 235 "/home/claude/cfront-3/src/lex.cpp"
const char *keys [256];

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 238 "/home/claude/cfront-3/src/lex.cpp"
static void new_key__FPCcUcT2 (const char *__1s , TOK __1toknum , TOK __1yyclass )
# 244 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 245 "/home/claude/cfront-3/src/lex.cpp"
Pname __1n ;

# 245 "/home/claude/cfront-3/src/lex.cpp"
__1n = __ct__4nameFPCc ( (struct name *)0 , __1s ) ;

# 247 "/home/claude/cfront-3/src/lex.cpp"
(keys [((__1toknum == 143 )?__1yyclass :__1toknum )])= __1s ;

# 249 "/home/claude/cfront-3/src/lex.cpp"
{ Pname __1nn ;

# 249 "/home/claude/cfront-3/src/lex.cpp"
__1nn = insert__5tableFP4nameUc ( keyword_table , __1n , (unsigned char )0 ) ;

# 251 "/home/claude/cfront-3/src/lex.cpp"
__1nn -> base__4node = __1toknum ;
__1nn -> __O2__4name.syn_class = (__1yyclass ?__1yyclass :__1toknum );
( (__1n ?(((void )(__1n ?(((void )( ( ((((struct expr *)__1n ))?(((void )((((struct expr *)__1n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 253 "/home/claude/cfront-3/src/lex.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1n , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 253 "/home/claude/cfront-3/src/lex.cpp"
}
}

# 256 "/home/claude/cfront-3/src/lex.cpp"

# 220 "/home/claude/cfront-3/src/cfront.h"
struct table *__ct__5tableFsP5tableP4name (struct table *__0this , short , Ptable , Pname );

# 258 "/home/claude/cfront-3/src/lex.cpp"
static void ktbl_init__Fv (void )
# 263 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 264 "/home/claude/cfront-3/src/lex.cpp"
keyword_table = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )67, (struct table *)0 , (struct name *)0 )
# 264 "/home/claude/cfront-3/src/lex.cpp"
;

# 266 "/home/claude/cfront-3/src/lex.cpp"
new_key__FPCcUcT2 ( (const char *)"asm", (unsigned char )1 , (unsigned char )0 )
# 266 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"auto", (unsigned char )2 , (unsigned char )97 )
# 267 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"break", (unsigned char )143 , (unsigned char )3 )
# 268 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"case", (unsigned char )143 , (unsigned char )4 )
# 269 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"continue", (unsigned char )143 , (unsigned char )7 )
# 270 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"char", (unsigned char )5 , (unsigned char )97 )
# 271 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"do", (unsigned char )143 , (unsigned char )10 )
# 272 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"double", (unsigned char )11 , (unsigned char )97 )
# 273 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"default", (unsigned char )143 , (unsigned char )8 )
# 274 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"enum", (unsigned char )13 , (unsigned char )0 )
# 275 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"else", (unsigned char )143 , (unsigned char )12 )
# 276 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"extern", (unsigned char )14 , (unsigned char )97 )
# 277 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"float", (unsigned char )15 , (unsigned char )97 )
# 278 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"for", (unsigned char )143 , (unsigned char )16 )
# 279 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"goto", (unsigned char )143 , (unsigned char )19 )
# 280 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"if", (unsigned char )143 , (unsigned char )20 )
# 281 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"int", (unsigned char )21 , (unsigned char )97 )
# 282 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"long", (unsigned char )22 , (unsigned char )97 )
# 283 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"long long", (unsigned char )122 , (unsigned char )97 )
# 284 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"return", (unsigned char )143 , (unsigned char )28 )
# 285 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"register", (unsigned char )27 , (unsigned char )97 )
# 286 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"static", (unsigned char )31 , (unsigned char )97 )
# 287 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"struct", (unsigned char )32 , (unsigned char )156 )
# 288 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"sizeof", (unsigned char )30 , (unsigned char )0 )
# 289 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"short", (unsigned char )29 , (unsigned char )97 )
# 290 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"switch", (unsigned char )143 , (unsigned char )33 )
# 291 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"typedef", (unsigned char )35 , (unsigned char )97 )
# 292 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"unsigned", (unsigned char )37 , (unsigned char )97 )
# 293 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"union", (unsigned char )36 , (unsigned char )156 )
# 294 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"void", (unsigned char )38 , (unsigned char )97 )
# 295 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"while", (unsigned char )143 , (unsigned char )39 )
# 296 "/home/claude/cfront-3/src/lex.cpp"
;

# 298 "/home/claude/cfront-3/src/lex.cpp"
new_key__FPCcUcT2 ( (const char *)"catch", (unsigned char )98 , (unsigned char )98 )
# 298 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"class", (unsigned char )6 , (unsigned char )156 )
# 299 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"const", (unsigned char )26 , (unsigned char )97 )
# 300 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"delete", (unsigned char )143 , (unsigned char )9 )
# 301 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"friend", (unsigned char )18 , (unsigned char )97 )
# 302 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"inline", (unsigned char )75 , (unsigned char )97 )
# 303 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"namespace", (unsigned char )102 , (unsigned char )102 )
# 304 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"mutable", (unsigned char )101 , (unsigned char )101 )
# 305 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"new", (unsigned char )23 , (unsigned char )0 )
# 306 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"operator", (unsigned char )24 , (unsigned char )0 )
# 307 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"overload", (unsigned char )76 , (unsigned char )97 )
# 308 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"private", (unsigned char )174 , (unsigned char )175 )
# 309 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"protected", (unsigned char )79 , (unsigned char )175 )
# 310 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"public", (unsigned char )25 , (unsigned char )175 )
# 311 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"signed", (unsigned char )171 , (unsigned char )97 )
# 312 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"template", (unsigned char )185 , (unsigned char )0 )
# 313 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"this", (unsigned char )34 , (unsigned char )0 )
# 314 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"throw", (unsigned char )99 , (unsigned char )99 )
# 315 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"try", (unsigned char )100 , (unsigned char )100 )
# 316 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"using", (unsigned char )103 , (unsigned char )103 )
# 317 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"virtual", (unsigned char )77 , (unsigned char )97 )
# 318 "/home/claude/cfront-3/src/lex.cpp"
;
new_key__FPCcUcT2 ( (const char *)"volatile", (unsigned char )170 , (unsigned char )97 )
# 319 "/home/claude/cfront-3/src/lex.cpp"
;
}

# 322 "/home/claude/cfront-3/src/lex.cpp"
struct loc last_line = { 0 } ;
struct loc noloc = { 0 , 0 } ;

# 491 "/home/claude/cfront-3/src/template.h"

# 79 "/home/claude/incl-linux32/stdio.h"
extern int fprintf (void *, const char *,...);

# 325 "/home/claude/cfront-3/src/lex.cpp"
void putline__3locFv (register struct loc *__0this )
# 326 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 327 "/home/claude/cfront-3/src/lex.cpp"
if ((__0this -> file__3loc == 0 )&& (__0this -> line__3loc == 0 ))return ;
if ((0 <= __0this -> file__3loc )&& (__0this -> file__3loc <= Nfile )){ 
# 329 "/home/claude/cfront-3/src/lex.cpp"
const char *__2f ;

# 330 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X27 ;

# 330 "/home/claude/cfront-3/src/lex.cpp"
int __2__X28 ;

# 329 "/home/claude/cfront-3/src/lex.cpp"
__2f = ((*( (__0__X27 = (& file_name )), ( (__2__X28 = __0this -> file__3loc ), ( (((CPchar *)(& (__0__X27 -> p__12Block_CPchar [__2__X28 ]))))) )
# 329 "/home/claude/cfront-3/src/lex.cpp"
) ));
if (__2f == 0 )__2f = src_file_name ;
fprintf ( out_file , line_format , __0this -> line__3loc , __2f ) ;
last_line = (*__0this );
}
}

# 491 "/home/claude/cfront-3/src/template.h"

# 336 "/home/claude/cfront-3/src/lex.cpp"
void put__3locFPv (register struct loc *__0this , void *__1p )
# 337 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 338 "/home/claude/cfront-3/src/lex.cpp"
if ((0 <= __0this -> file__3loc )&& (__0this -> file__3loc <= Nfile )){ 
# 339 "/home/claude/cfront-3/src/lex.cpp"
const
# 339 "/home/claude/cfront-3/src/lex.cpp"
char *__2f ;

# 340 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X29 ;

# 340 "/home/claude/cfront-3/src/lex.cpp"
int __2__X30 ;

# 339 "/home/claude/cfront-3/src/lex.cpp"
__2f = ((*( (__0__X29 = (& file_name )), ( (__2__X30 = __0this -> file__3loc ), ( (((CPchar *)(& (__0__X29 -> p__12Block_CPchar [__2__X30 ]))))) )
# 339 "/home/claude/cfront-3/src/lex.cpp"
) ));
if (__2f == 0 )__2f = src_file_name ;
fprintf ( __1p , (const char *)"\"%s\", line %d: ", __2f , __0this -> line__3loc ) ;
}
}

# 491 "/home/claude/cfront-3/src/template.h"

# 345 "/home/claude/cfront-3/src/lex.cpp"
const char *curr_filename__Fv (void )
# 346 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 346 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X31 ;

# 346 "/home/claude/cfront-3/src/lex.cpp"
int __2__X32 ;

# 347 "/home/claude/cfront-3/src/lex.cpp"
return ((*( (__0__X31 = (& file_name )), ( (__2__X32 = curloc . file__3loc ), ( (((CPchar *)(& (__0__X31 -> p__12Block_CPchar [__2__X32 ]))))) )
# 347 "/home/claude/cfront-3/src/lex.cpp"
) ));
}

# 350 "/home/claude/cfront-3/src/lex.cpp"
void lxenter__FPCcs (const char *__1s , short __1m )
# 352 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 353 "/home/claude/cfront-3/src/lex.cpp"
int __1c ;

# 355 "/home/claude/cfront-3/src/lex.cpp"
while (__1c = ((*(__1s ++ ))))(lxmask [(__1c + 1 )])|= __1m ;

# 357 "/home/claude/cfront-3/src/lex.cpp"
}

# 92 "/home/claude/incl-linux32/stdio.h"
extern int fgetc (void *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 360 "/home/claude/cfront-3/src/lex.cpp"
void lxget__FiT1 (int __1c , int __1m )
# 366 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 367 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
if (( (saved ?( ( (__1c = saved ), (saved = 0 )) , __1c ) :(__1c = fgetc ( in_file ) )),
# 368 "/home/claude/cfront-3/src/lex.cpp"
((lxmask [(__1c + 1 )])& __1m )) ){ 
# 369 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
while (( (__1c = fgetc ( in_file ) ), ((lxmask [(__1c + 1 )])& __1m )) )(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int
# 370 "/home/claude/cfront-3/src/lex.cpp"
)(((*(txtfree ++ )))= __1c )));
}
{ 
# 372 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X34 ;

# 372 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 372 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V33 ;

# 372 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 372 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X34 = saved ), ( (( ((& __0__V33 )-> __O1__2ea.i = __2__X34 ), 0 ) ), (& __0__V33 )) )
# 372 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 372 "/home/claude/cfront-3/src/lex.cpp"
saved = __1c ;

# 372 "/home/claude/cfront-3/src/lex.cpp"
}

# 372 "/home/claude/cfront-3/src/lex.cpp"
;
(txtmax <= txtfree )?new_buf__Fc ( '\0' ) :(((int )(((*(txtfree ++ )))= '\0' )));
}
struct LXDOPE;

# 376 "/home/claude/cfront-3/src/lex.cpp"
struct LXDOPE {	/* sizeof LXDOPE == 6 */
short lxch__6LXDOPE ;
short lxact__6LXDOPE ;
TOK lxtok__6LXDOPE ;
};

# 380 "/home/claude/cfront-3/src/lex.cpp"
static struct LXDOPE lxdope [34]= { '$' , 30 , 0 , '_' , 1 , 0 , '0' , 2 , 0 , ' ' ,
# 380 "/home/claude/cfront-3/src/lex.cpp"
10 , 0 , '\n' , 11 , 0 , '"' , 4 , 0 , '\'' , 5 , 0 , '`' , 6 , 0 ,
# 380 "/home/claude/cfront-3/src/lex.cpp"
'(' , 14 , 40 , ')' , 15 , 41 , '{' , 12 , 73 , '}' , 13 , 74 , '[' , 3 ,
# 380 "/home/claude/cfront-3/src/lex.cpp"
42 , ']' , 3 , 43 , '*' , 26 , 50 , '?' , 3 , 68 , ':' , 28 , 69 , '+' ,
# 380 "/home/claude/cfront-3/src/lex.cpp"
27 , 54 , '-' , 25 , 55 , '/' , 7 , 51 , '%' , 23 , 53 , '&' , 22 , 52 ,
# 380 "/home/claude/cfront-3/src/lex.cpp"
'|' , 21 , 65 , '^' , 20 , 64 , '!' , 24 , 46 , '~' , 3 , 47 , ',' , 3 ,
# 380 "/home/claude/cfront-3/src/lex.cpp"
71 , ';' , 3 , 72 , '.' , 8 , 45 , '<' , 18 , 58 , '>' , 19 , 60 , '=' ,
# 380 "/home/claude/cfront-3/src/lex.cpp"
17 , 70 , '#' , 29 , 0 , - 1 , 16 , 0 } ;

# 423 "/home/claude/cfront-3/src/lex.cpp"
static struct LXDOPE *lxcp [129];

# 491 "/home/claude/cfront-3/src/template.h"

# 48 "/home/claude/cfront-3/src/token.h"
extern void lex_clear__Fv (void );

# 211 "/home/claude/cfront-3/src/lex.cpp"
static int lxtitle__Fv (void );

# 426 "/home/claude/cfront-3/src/lex.cpp"
void lex_init__Fv (void )
# 427 "/home/claude/cfront-3/src/lex.cpp"
{
# 428 "/home/claude/cfront-3/src/lex.cpp"
struct LXDOPE *__1p ;
int __1i ;
const char *__1cp ;

# 431 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X35 ;

# 431 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X36 ;

# 434 "/home/claude/cfront-3/src/lex.cpp"
for(__1i = 0 ;__1i <= 128 ;__1i ++ ) (lxmask [__1i ])= 0 ;

# 439 "/home/claude/cfront-3/src/lex.cpp"
lxenter__FPCcs ( (const char *)"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_", (short )01 ) ;

# 441 "/home/claude/cfront-3/src/lex.cpp"
lxenter__FPCcs ( (const char *)"0123456789", (short )02 ) ;
lxenter__FPCcs ( (const char *)"0123456789abcdefABCDEF", (short )010 ) ;

# 444 "/home/claude/cfront-3/src/lex.cpp"
lxenter__FPCcs ( (const char *)" \t\r\b\f\013", (short )020 ) ;
(lxmask [47])|= 040 ;

# 451 "/home/claude/cfront-3/src/lex.cpp"
for(__1i = 0 ;__1i <= 128 ;++ __1i ) (lxcp [__1i ])= (struct LXDOPE *)lxdope ;

# 455 "/home/claude/cfront-3/src/lex.cpp"
for(__1p = (struct LXDOPE *)lxdope ;;++ __1p ) { 
# 456 "/home/claude/cfront-3/src/lex.cpp"
(lxcp [(__1p -> lxch__6LXDOPE + 1 )])= __1p ;
if (__1p -> lxch__6LXDOPE < 0 )break ;
}

# 463 "/home/claude/cfront-3/src/lex.cpp"
__1cp = (const char *)"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
while ((*__1cp ))(lxcp [(((*(__1cp ++ )))+ 1 )])= (& (lxdope [1 ]));
__1cp = (const char *)"123456789";
while ((*__1cp ))(lxcp [(((*(__1cp ++ )))+ 1 )])= (& (lxdope [2 ]));
__1cp = (const char *)"\t\b\r\f\013";
while ((*__1cp ))(lxcp [(((*(__1cp ++ )))+ 1 )])= (& (lxdope [3 ]));

# 470 "/home/claude/cfront-3/src/lex.cpp"
( (__0__X35 = (& file_name )), ( ((((unsigned long )0 )< __0__X35 -> n__12Block_CPchar )|| grow__12Block_CPcharFUl ( __0__X35 , ((unsigned long
# 470 "/home/claude/cfront-3/src/lex.cpp"
)0 )) )) ) ;
((*( (__0__X36 = (& file_name )), ( (((CPchar *)(& (__0__X36 -> p__12Block_CPchar [0 ]))))) ) ))= src_file_name ;

# 474 "/home/claude/cfront-3/src/lex.cpp"
curloc . line__3loc = (tloc . line__3loc = 1 );

# 476 "/home/claude/cfront-3/src/lex.cpp"
ktbl_init__Fv ( ) ;
lex_clear__Fv ( ) ;
saved = lxtitle__Fv ( ) ;
}

# 481 "/home/claude/cfront-3/src/lex.cpp"
void lex_clear__Fv (void )
# 482 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 484 "/home/claude/cfront-3/src/lex.cpp"
struct buf *__1p ;

# 484 "/home/claude/cfront-3/src/lex.cpp"
__1p = bufhead ;
bufhead = 0 ;

# 490 "/home/claude/cfront-3/src/lex.cpp"
while (__1p ){ 
# 491 "/home/claude/cfront-3/src/lex.cpp"
struct buf *__2pp ;

# 491 "/home/claude/cfront-3/src/lex.cpp"
__2pp = __1p ;
__1p = __1p -> next__3buf ;
__2pp -> next__3buf = freebuf ;
freebuf = __2pp ;
}

# 498 "/home/claude/cfront-3/src/lex.cpp"
txtstart = (txtfree = inbuf );
txtmax = (& (inbuf [8183]));
}

# 502 "/home/claude/cfront-3/src/lex.cpp"
int int_val__Fc (char __1hex )
# 503 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 504 "/home/claude/cfront-3/src/lex.cpp"
switch (__1hex ){ 
# 505 "/home/claude/cfront-3/src/lex.cpp"
case '0' :case '1' :case '2' :case '3' :case '4' :
# 506 "/home/claude/cfront-3/src/lex.cpp"
case '5' :case '6' :case '7' :case
# 506 "/home/claude/cfront-3/src/lex.cpp"
'8' :case '9' :
# 507 "/home/claude/cfront-3/src/lex.cpp"
return (__1hex - '0' );
case 'a' :case 'b' :case 'c' :case 'd' :case 'e' :case 'f' :
# 509 "/home/claude/cfront-3/src/lex.cpp"
return ((__1hex - 'a' )+ 10 );
case 'A' :case 'B' :case 'C' :case 'D' :case 'E' :case 'F' :
# 511 "/home/claude/cfront-3/src/lex.cpp"
return ((__1hex - 'A' )+ 10 );
}
error__FiPCc ( (int )'i' , (const char *)"fall off end of int_val()") ;
return 0 ;
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 517 "/home/claude/cfront-3/src/lex.cpp"
void hex_to_oct__Fv (void )
# 522 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 523 "/home/claude/cfront-3/src/lex.cpp"
int __1i ;
int __1c ;

# 523 "/home/claude/cfront-3/src/lex.cpp"
__1i = 0 ;

# 525 "/home/claude/cfront-3/src/lex.cpp"
saved ?( ( (__1c = saved ), (saved = 0 )) , __1c ) :(__1c = fgetc ( in_file ) );
if ((lxmask [(__1c + 1 )])& 010 ){ 
# 527 "/home/claude/cfront-3/src/lex.cpp"
__1i = int_val__Fc ( (char )__1c ) ;
__1c = fgetc ( in_file ) ;
if ((lxmask [(__1c + 1 )])& 010 ){ 
# 530 "/home/claude/cfront-3/src/lex.cpp"
__1i = ((__1i << 4 )+ int_val__Fc ( (char )__1c ) );
__1c = fgetc ( in_file ) ;
if ((lxmask [(__1c + 1 )])& 010 )
# 533 "/home/claude/cfront-3/src/lex.cpp"
__1i = ((__1i << 4 )+ int_val__Fc ( (char )__1c ) );
else 
# 535 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 535 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X40 ;

# 535 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 535 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V37 ;

# 535 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 535 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X40 = saved ), ( (( ((& __0__V37 )-> __O1__2ea.i = __2__X40 ), 0 ) ), (& __0__V37 )) )
# 535 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 535 "/home/claude/cfront-3/src/lex.cpp"
saved = __1c ;

# 535 "/home/claude/cfront-3/src/lex.cpp"
}

# 535 "/home/claude/cfront-3/src/lex.cpp"
;
}
else 
# 538 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 538 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X41 ;

# 538 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 538 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V38 ;

# 538 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 538 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X41 = saved ), ( (( ((& __0__V38 )-> __O1__2ea.i = __2__X41 ), 0 ) ), (& __0__V38 )) )
# 538 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 538 "/home/claude/cfront-3/src/lex.cpp"
saved = __1c ;

# 538 "/home/claude/cfront-3/src/lex.cpp"
}

# 538 "/home/claude/cfront-3/src/lex.cpp"
;
}
else { 
# 541 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"hexadecimal digitE after \\x", (const struct
# 541 "/home/claude/cfront-3/src/lex.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
{ 
# 542 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X42 ;

# 542 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 542 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V39 ;

# 542 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 542 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X42 = saved ), ( (( ((& __0__V39 )-> __O1__2ea.i = __2__X42 ), 0 ) ), (& __0__V39 )) )
# 542 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 542 "/home/claude/cfront-3/src/lex.cpp"
saved = __1c ;

# 542 "/home/claude/cfront-3/src/lex.cpp"
}

# 542 "/home/claude/cfront-3/src/lex.cpp"
;
}

# 546 "/home/claude/cfront-3/src/lex.cpp"
__1i &= 0377 ;

# 548 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )('0' + (__1i >> 6 ))) :(((int )(((*(txtfree ++ )))= ('0' + (__1i >> 6 )))));
(txtmax <= txtfree )?new_buf__Fc ( (char )('0' + ((__1i & 070 )>> 3 ))) :(((int )(((*(txtfree ++ )))= ('0' + ((__1i & 070 )>> 3 )))));
# 549 "/home/claude/cfront-3/src/lex.cpp"

# 550 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )('0' + (__1i & 7 ))) :(((int )(((*(txtfree ++ )))= ('0' + (__1i & 7 )))));
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 554 "/home/claude/cfront-3/src/lex.cpp"
char *chconst__Fv (void )
# 558 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 559 "/home/claude/cfront-3/src/lex.cpp"
int __1c ;
int __1nch ;

# 560 "/home/claude/cfront-3/src/lex.cpp"
__1nch = 0 ;

# 562 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( '\'' ) :(((int )(((*(txtfree ++ )))= '\'' )));

# 564 "/home/claude/cfront-3/src/lex.cpp"
for(;;) { 
# 565 "/home/claude/cfront-3/src/lex.cpp"
char *__2p ;
char __2cc ;

# 566 "/home/claude/cfront-3/src/lex.cpp"
__2cc = 0 ;
saved ?( ( (__1c = saved ), (saved = 0 )) , __1c ) :(__1c = fgetc ( in_file ) );
switch (__1c ){ 
# 569 "/home/claude/cfront-3/src/lex.cpp"
case '\'' :
# 570 "/home/claude/cfront-3/src/lex.cpp"
goto ex ;
case -1:
# 572 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"eof in char constant", (const struct ea *)ea0 ,
# 572 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
goto ex ;
case '\n' :
# 575 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"newline in char constant", (const struct ea *)ea0 ,
# 575 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
goto ex ;
case '\\' :
# 578 "/home/claude/cfront-3/src/lex.cpp"
if (SZ_INT == (__1nch ++ ))error__FiP3locPCcRC2eaN34 ( (int )'l' , & tloc , (const char *)"char constant too long",
# 578 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
switch (__1c = fgetc ( in_file ) ){ 
# 581 "/home/claude/cfront-3/src/lex.cpp"
case '\n' :
# 582 "/home/claude/cfront-3/src/lex.cpp"
++ tloc . line__3loc ;
default :
# 584 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
break ;
case '4' :case '5' :case '6' :case '7' :
# 587 "/home/claude/cfront-3/src/lex.cpp"
__2p = txtfree ;
__2cc = (__1c - 4 );
case '0' :case '1' :case '2' :case '3' :
# 590 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
__1c = fgetc ( in_file ) ;
if (((lxmask [(__1c + 1 )])& 02 )&& (__1c < '8' )){ 
# 593 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
# 593 "/home/claude/cfront-3/src/lex.cpp"

# 594 "/home/claude/cfront-3/src/lex.cpp"
__1c = fgetc ( in_file ) ;
if (((lxmask [(__1c + 1 )])& 02 )&& (__1c < '8' )){ 
# 596 "/home/claude/cfront-3/src/lex.cpp"
if (__2cc )((*__2p ))= __2cc ;
(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
}
else 
# 600 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 600 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X45 ;

# 600 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 600 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V43 ;

# 600 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 600 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X45 = saved ), ( (( ((& __0__V43 )-> __O1__2ea.i = __2__X45 ), 0 ) ), (& __0__V43 )) )
# 600 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 600 "/home/claude/cfront-3/src/lex.cpp"
saved = __1c ;

# 600 "/home/claude/cfront-3/src/lex.cpp"
}

# 600 "/home/claude/cfront-3/src/lex.cpp"
;
}
else 
# 603 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 603 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X46 ;

# 603 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 603 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V44 ;

# 603 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 603 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X46 = saved ), ( (( ((& __0__V44 )-> __O1__2ea.i = __2__X46 ), 0 ) ), (& __0__V44 )) )
# 603 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 603 "/home/claude/cfront-3/src/lex.cpp"
saved = __1c ;

# 603 "/home/claude/cfront-3/src/lex.cpp"
}

# 603 "/home/claude/cfront-3/src/lex.cpp"
;
break ;
case 'x' :
# 606 "/home/claude/cfront-3/src/lex.cpp"
hex_to_oct__Fv ( ) ;
break ;
}

# 608 "/home/claude/cfront-3/src/lex.cpp"
;
break ;
default :
# 611 "/home/claude/cfront-3/src/lex.cpp"
if (SZ_INT == (__1nch ++ ))error__FiP3locPCcRC2eaN34 ( (int )'l' , & tloc , (const char *)"char constant too long",
# 611 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
}
}
ex :
# 616 "/home/claude/cfront-3/src/lex.cpp"
if (__1nch == 0 )
# 617 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"empty char constant", (const struct
# 617 "/home/claude/cfront-3/src/lex.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
(txtmax <= txtfree )?new_buf__Fc ( '\'' ) :(((int )(((*(txtfree ++ )))= '\'' )));
(txtmax <= txtfree )?new_buf__Fc ( '\0' ) :(((int )(((*(txtfree ++ )))= '\0' )));
return txtstart ;
}

# 623 "/home/claude/cfront-3/src/lex.cpp"
void lxcom__Fv (void )
# 625 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 626 "/home/claude/cfront-3/src/lex.cpp"
int __1c ;
saved ?( ( (__1c = saved ), (saved = 0 )) , __1c ) :(__1c = fgetc ( in_file ) );
for(;;__1c = fgetc ( in_file ) ) { 
# 629 "/home/claude/cfront-3/src/lex.cpp"
xx :switch (__1c ){ 
# 630 "/home/claude/cfront-3/src/lex.cpp"
case -1:
# 631 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & tloc , (const
# 631 "/home/claude/cfront-3/src/lex.cpp"
char *)"eof in comment", (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 631 "/home/claude/cfront-3/src/lex.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
return ;
case '\n' :
# 634 "/home/claude/cfront-3/src/lex.cpp"
tloc . line__3loc ++ ;

# 636 "/home/claude/cfront-3/src/lex.cpp"
break ;
case '*' :
# 638 "/home/claude/cfront-3/src/lex.cpp"
if ((__1c = fgetc ( in_file ) )== '/' )return ;
goto xx ;
case '/' :
# 641 "/home/claude/cfront-3/src/lex.cpp"
if ((__1c = fgetc ( in_file ) )== '*' ){ 
# 642 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & tloc , (const char
# 642 "/home/claude/cfront-3/src/lex.cpp"
*)"``/*'' in comment", (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 642 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 ) ;
if ((__1c = fgetc ( in_file ) )== '/' )return ;
}
goto xx ;
}
}
}

# 651 "/home/claude/cfront-3/src/lex.cpp"
void linecom__Fv (void )
# 653 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 654 "/home/claude/cfront-3/src/lex.cpp"
int __1c ;

# 656 "/home/claude/cfront-3/src/lex.cpp"
saved ?( ( (__1c = saved ), (saved = 0 )) , __1c ) :(__1c = fgetc ( in_file ) );

# 665 "/home/claude/cfront-3/src/lex.cpp"
for(;;__1c = fgetc ( in_file ) ) 
# 666 "/home/claude/cfront-3/src/lex.cpp"
switch (__1c ){ 
# 667 "/home/claude/cfront-3/src/lex.cpp"
case -1:
# 668 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & tloc , (const char
# 668 "/home/claude/cfront-3/src/lex.cpp"
*)"eof in comment", (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 668 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 ) ;
return ;
case '\n' :
# 671 "/home/claude/cfront-3/src/lex.cpp"
tloc . line__3loc ++ ;

# 673 "/home/claude/cfront-3/src/lex.cpp"
saved = lxtitle__Fv ( ) ;
return ;
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 98 "/home/claude/incl-linux32/stdio.h"
extern int ungetc (int , void *);

# 678 "/home/claude/cfront-3/src/lex.cpp"
char eat_whitespace__Fv (void )
# 679 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 680 "/home/claude/cfront-3/src/lex.cpp"
int __1c ;
saved ?( ( (__1c = saved ), (saved = 0 )) , __1c ) :(__1c = fgetc ( in_file ) );
for(;;) { 
# 683 "/home/claude/cfront-3/src/lex.cpp"
lx :
# 684 "/home/claude/cfront-3/src/lex.cpp"
switch (__1c ){ 
# 685 "/home/claude/cfront-3/src/lex.cpp"
case -1:
# 686 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & tloc , (const char *)"unexpected comment",
# 686 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return (char )-1;
case '/' :
# 689 "/home/claude/cfront-3/src/lex.cpp"
switch (__1c = fgetc ( in_file ) ){ 
# 690 "/home/claude/cfront-3/src/lex.cpp"
case '*' :
# 691 "/home/claude/cfront-3/src/lex.cpp"
lxcom__Fv ( ) ;
break ;
case '/' :
# 694 "/home/claude/cfront-3/src/lex.cpp"
linecom__Fv ( ) ;
break ;
default :
# 697 "/home/claude/cfront-3/src/lex.cpp"
if (__1c == -1)
# 698 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"eof after /", (const
# 698 "/home/claude/cfront-3/src/lex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
else 
# 700 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 701 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 701 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X48 ;

# 701 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 701 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V47 ;

# 701 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 701 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X48 = saved ), ( (( ((& __0__V47 )-> __O1__2ea.i = __2__X48 ), 0 ) ), (& __0__V47 )) )
# 701 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 701 "/home/claude/cfront-3/src/lex.cpp"
saved = __1c ;

# 701 "/home/claude/cfront-3/src/lex.cpp"
}

# 701 "/home/claude/cfront-3/src/lex.cpp"
;
( ungetc ( saved , in_file ) , (saved = 0 )) ;
}
return '/' ;
}
saved ?( ( (__1c = saved ), (saved = 0 )) , __1c ) :(__1c = fgetc ( in_file ) );
goto lx ;
case '\n' :
# 709 "/home/claude/cfront-3/src/lex.cpp"
++ tloc . line__3loc ;
__1c = lxtitle__Fv ( ) ;
goto lx ;
case ' ' :
# 713 "/home/claude/cfront-3/src/lex.cpp"
case '\t' :
# 714 "/home/claude/cfront-3/src/lex.cpp"
break ;
default :
# 716 "/home/claude/cfront-3/src/lex.cpp"
return (char )__1c ;
}
__1c = fgetc ( in_file ) ;
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 722 "/home/claude/cfront-3/src/lex.cpp"
void get_string__Fv (void )
# 723 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 724 "/home/claude/cfront-3/src/lex.cpp"
int __1lxchar ;

# 726 "/home/claude/cfront-3/src/lex.cpp"
for(;;) 
# 727 "/home/claude/cfront-3/src/lex.cpp"
switch (saved ?( ( (__1lxchar = saved ), (saved = 0 )) , __1lxchar ) :(__1lxchar = fgetc ( in_file ) )){
# 727 "/home/claude/cfront-3/src/lex.cpp"

# 728 "/home/claude/cfront-3/src/lex.cpp"
case '\\' :
# 729 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( '\\' ) :(((int )(((*(txtfree ++ )))= '\\' )));
switch (__1lxchar = fgetc ( in_file ) ){ 
# 731 "/home/claude/cfront-3/src/lex.cpp"
case '\n' :
# 732 "/home/claude/cfront-3/src/lex.cpp"
++ tloc . line__3loc ;
default :
# 734 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__1lxchar ) :(((int )(((*(txtfree ++ )))= __1lxchar )));
break ;
case 'x' :
# 737 "/home/claude/cfront-3/src/lex.cpp"
hex_to_oct__Fv ( ) ;
break ;
}

# 739 "/home/claude/cfront-3/src/lex.cpp"
;
break ;
case '"' :
# 742 "/home/claude/cfront-3/src/lex.cpp"
{ char *__3p ;

# 742 "/home/claude/cfront-3/src/lex.cpp"
__3p = txtstart ;
if ((__1lxchar = eat_whitespace__Fv ( ) )== '"' ){ 
# 747 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( '\\' ) :(((int )(((*(txtfree ++ )))= '\\' )));
(txtmax <= txtfree )?new_buf__Fc ( '\n' ) :(((int )(((*(txtfree ++ )))= '\n' )));

# 750 "/home/claude/cfront-3/src/lex.cpp"
continue ;
}

# 751 "/home/claude/cfront-3/src/lex.cpp"
;

# 753 "/home/claude/cfront-3/src/lex.cpp"
txtstart = __3p ;
{ 
# 754 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X50 ;

# 754 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 754 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V49 ;

# 754 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 754 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X50 = saved ), ( (( ((& __0__V49 )-> __O1__2ea.i = __2__X50 ), 0 ) ), (& __0__V49 )) )
# 754 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 754 "/home/claude/cfront-3/src/lex.cpp"
saved = __1lxchar ;

# 754 "/home/claude/cfront-3/src/lex.cpp"
}

# 754 "/home/claude/cfront-3/src/lex.cpp"
;
(txtmax <= txtfree )?new_buf__Fc ( (char )0 ) :(((int )(((*(txtfree ++ )))= 0 )));
return ;
}
case '\n' :
# 759 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"newline in string", (const struct ea *)ea0 ,
# 759 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
(txtmax <= txtfree )?new_buf__Fc ( (char )0 ) :(((int )(((*(txtfree ++ )))= 0 )));
return ;
case -1:
# 763 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"eof in string", (const struct ea *)ea0 ,
# 763 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
(txtmax <= txtfree )?new_buf__Fc ( (char )0 ) :(((int )(((*(txtfree ++ )))= 0 )));
return ;
default :
# 767 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__1lxchar ) :(((int )(((*(txtfree ++ )))= __1lxchar )));
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 37 "/home/claude/cfront-3/src/tqueue.h"
extern void addtok__FUc7YYSTYPE3loc (TOK , union YYSTYPE , struct loc );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 216 "/home/claude/cfront-3/src/lex.cpp"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 33 "/home/claude/cfront-3/src/cfront.h"
extern void ext__Fi (int );

# 216 "/home/claude/cfront-3/src/lex.cpp"

# 215 "/home/claude/cfront-3/src/lex.cpp"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 771 "/home/claude/cfront-3/src/lex.cpp"
TOK tlex__Fv (void )
# 772 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 773 "/home/claude/cfront-3/src/lex.cpp"
TOK __1ret ;
Pname __1n ;

# 778 "/home/claude/cfront-3/src/lex.cpp"
for(;;) { 
# 779 "/home/claude/cfront-3/src/lex.cpp"
int __2lxchar ;
struct LXDOPE *__2p ;

# 782 "/home/claude/cfront-3/src/lex.cpp"
txtstart = txtfree ;

# 784 "/home/claude/cfront-3/src/lex.cpp"
saved ?( ( (__2lxchar = saved ), (saved = 0 )) , __2lxchar ) :(__2lxchar = fgetc ( in_file ) );

# 786 "/home/claude/cfront-3/src/lex.cpp"
if ((__2lxchar + 1 )>= 128 )
# 787 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 787 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V51 ;

# 787 "/home/claude/cfront-3/src/lex.cpp"
error__FPCcRC2eaN32 ( (const char *)"illegal input character encountered: %d", (const struct ea *)( (( ((& __0__V51 )->
# 787 "/home/claude/cfront-3/src/lex.cpp"
__O1__2ea.i = ((unsigned long )__2lxchar )), 0 ) ), (& __0__V51 )) , (const struct ea *)ea0 , (const struct
# 787 "/home/claude/cfront-3/src/lex.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 789 "/home/claude/cfront-3/src/lex.cpp"
switch ((__2p = (lxcp [(__2lxchar + 1 )]))-> lxact__6LXDOPE ){ 
# 789 "/home/claude/cfront-3/src/lex.cpp"
const void *__2__X76 ;

# 791 "/home/claude/cfront-3/src/lex.cpp"
case 3 :
# 792 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 792 "/home/claude/cfront-3/src/lex.cpp"
int __1__X75 ;

# 792 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 792 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( __2p -> lxtok__6LXDOPE , ( (__1__X75 = __2p -> lxtok__6LXDOPE ), ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = __1__X75 ), __1__Xy00qjtkvpt5vcij ) ) ,
# 792 "/home/claude/cfront-3/src/lex.cpp"
tloc ) ;

# 792 "/home/claude/cfront-3/src/lex.cpp"
return __2p -> lxtok__6LXDOPE ;

# 792 "/home/claude/cfront-3/src/lex.cpp"
}

# 792 "/home/claude/cfront-3/src/lex.cpp"
;

# 794 "/home/claude/cfront-3/src/lex.cpp"
case 16 :
# 795 "/home/claude/cfront-3/src/lex.cpp"
if (p_level || (b_level + lcount ))
# 796 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 796 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V52 ;

# 796 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"'%s' missing at end of input", (const struct ea *)( (__2__X76 =
# 796 "/home/claude/cfront-3/src/lex.cpp"
(const void *)((b_level + lcount )?"}":")")), ( ((&
# 796 "/home/claude/cfront-3/src/lex.cpp"
__0__V52 )-> __O1__2ea.p = __2__X76 ), (& __0__V52 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const
# 796 "/home/claude/cfront-3/src/lex.cpp"
struct ea *)ea0 ) ;
} 
# 798 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 798 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 798 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )0 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 0 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 798 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )0 ;

# 798 "/home/claude/cfront-3/src/lex.cpp"
}

# 798 "/home/claude/cfront-3/src/lex.cpp"
;

# 800 "/home/claude/cfront-3/src/lex.cpp"
case 29 :
# 802 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 802 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X77 ;

# 802 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 802 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V53 ;

# 802 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 802 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X77 = saved ), ( (( ((& __0__V53 )-> __O1__2ea.i = __2__X77 ), 0 ) ), (& __0__V53 )) )
# 802 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 802 "/home/claude/cfront-3/src/lex.cpp"
saved = '#' ;

# 802 "/home/claude/cfront-3/src/lex.cpp"
}

# 802 "/home/claude/cfront-3/src/lex.cpp"
;
saved = lxtitle__Fv ( ) ;
continue ;

# 806 "/home/claude/cfront-3/src/lex.cpp"
case 0 :
# 807 "/home/claude/cfront-3/src/lex.cpp"
{ if ((' ' <= __2lxchar )&& (__2lxchar <= '~' ))
# 808 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 808 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V54 ;

# 808 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"illegal character '%c' (ignored)", (const struct ea *)( ((
# 808 "/home/claude/cfront-3/src/lex.cpp"
((& __0__V54 )-> __O1__2ea.i = ((unsigned long )__2lxchar )), 0 ) ), (& __0__V54 )) , (const struct ea *)ea0 ,
# 808 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 810 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 810 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V55 ;

# 810 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"illegal character%o (ignored)", (const struct ea *)( ((
# 810 "/home/claude/cfront-3/src/lex.cpp"
((& __0__V55 )-> __O1__2ea.i = ((unsigned long )__2lxchar )), 0 ) ), (& __0__V55 )) , (const struct ea *)ea0 ,
# 810 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} continue ;
}

# 814 "/home/claude/cfront-3/src/lex.cpp"
case 30 :
# 815 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 823 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 823 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V56 ;

# 823 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"illegal character%o (ignored)", (const struct ea *)( ((
# 823 "/home/claude/cfront-3/src/lex.cpp"
((& __0__V56 )-> __O1__2ea.i = ((unsigned long )__2lxchar )), 0 ) ), (& __0__V56 )) , (const struct ea *)ea0 ,
# 823 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
continue ;
} 
# 841 "/home/claude/cfront-3/src/lex.cpp"
}

# 843 "/home/claude/cfront-3/src/lex.cpp"
case 1 :
# 844 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 845 "/home/claude/cfront-3/src/lex.cpp"
char __4ll ;
switch (__4ll = __2lxchar ){ 
# 848 "/home/claude/cfront-3/src/lex.cpp"
case 'L' :
# 849 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 850 "/home/claude/cfront-3/src/lex.cpp"
case '\'' :
# 851 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , &
# 851 "/home/claude/cfront-3/src/lex.cpp"
tloc , (const char *)"wide character constant", (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 851 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
{ 
# 852 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X78 ;

# 852 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 852 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V57 ;

# 852 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 852 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X78 = saved ), ( (( ((& __0__V57 )-> __O1__2ea.i = __2__X78 ), 0 ) ), (& __0__V57 )) )
# 852 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 852 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;

# 852 "/home/claude/cfront-3/src/lex.cpp"
}

# 852 "/home/claude/cfront-3/src/lex.cpp"
;
continue ;
case '"' :
# 855 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & tloc , (const char *)"wide character string", (const
# 855 "/home/claude/cfront-3/src/lex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
{ 
# 856 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X79 ;

# 856 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 856 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V58 ;

# 856 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 856 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X79 = saved ), ( (( ((& __0__V58 )-> __O1__2ea.i = __2__X79 ), 0 ) ), (& __0__V58 )) )
# 856 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 856 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;

# 856 "/home/claude/cfront-3/src/lex.cpp"
}

# 856 "/home/claude/cfront-3/src/lex.cpp"
;
continue ;
}
{ 
# 859 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X80 ;

# 859 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 859 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V59 ;

# 859 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 859 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X80 = saved ), ( (( ((& __0__V59 )-> __O1__2ea.i = __2__X80 ), 0 ) ), (& __0__V59 )) )
# 859 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 859 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;

# 859 "/home/claude/cfront-3/src/lex.cpp"
}

# 859 "/home/claude/cfront-3/src/lex.cpp"
;
__2lxchar = __4ll ;
}
}

# 864 "/home/claude/cfront-3/src/lex.cpp"
lxget__FiT1 ( __2lxchar , 3) ;

# 866 "/home/claude/cfront-3/src/lex.cpp"
if (__1n = look__5tableFPCcUc ( keyword_table , (const char *)txtstart , (unsigned char )0 ) )
# 867 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 868 "/home/claude/cfront-3/src/lex.cpp"
TOK __4x ;
switch (__4x = __1n -> base__4node ){ 
# 870 "/home/claude/cfront-3/src/lex.cpp"
case 123 :
# 871 "/home/claude/cfront-3/src/lex.cpp"
txtfree = txtstart ;
{ 
# 872 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V60 ;

# 872 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"TN%n in keyword_table", (const struct
# 872 "/home/claude/cfront-3/src/lex.cpp"
ea *)( ((& __0__V60 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V60 )) , (const struct ea *)ea0 , (const
# 872 "/home/claude/cfront-3/src/lex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;

# 875 "/home/claude/cfront-3/src/lex.cpp"
case 143 :
# 876 "/home/claude/cfront-3/src/lex.cpp"
txtfree = txtstart ;
{ 
# 877 "/home/claude/cfront-3/src/lex.cpp"
struct loc __1__X81 ;

# 877 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00adtkvpt5vcij ;

# 877 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )__1n -> __O2__4name.syn_class , ( (__1__X81 = tloc ), ( (__1__Xy00adtkvpt5vcij . l__7YYSTYPE = __1__X81 ), __1__Xy00adtkvpt5vcij ) )
# 877 "/home/claude/cfront-3/src/lex.cpp"
, tloc ) ;

# 877 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )__1n -> __O2__4name.syn_class ;

# 877 "/home/claude/cfront-3/src/lex.cpp"
}

# 877 "/home/claude/cfront-3/src/lex.cpp"
;
case 14 :
# 879 "/home/claude/cfront-3/src/lex.cpp"
txtfree = txtstart ;
if ((__2lxchar = eat_whitespace__Fv ( ) )== '\"' ){ 
# 882 "/home/claude/cfront-3/src/lex.cpp"
get_string__Fv ( ) ;
{ 
# 883 "/home/claude/cfront-3/src/lex.cpp"
char *__1__X82 ;

# 883 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00aqtkvpt5vcij ;

# 883 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )182 , ( (__1__X82 = txtstart ), ( (__1__Xy00aqtkvpt5vcij . s__7YYSTYPE = (const char *)__1__X82 ), __1__Xy00aqtkvpt5vcij )
# 883 "/home/claude/cfront-3/src/lex.cpp"
) , tloc ) ;

# 883 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )182 ;

# 883 "/home/claude/cfront-3/src/lex.cpp"
}

# 883 "/home/claude/cfront-3/src/lex.cpp"
;
}

# 886 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 886 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X83 ;

# 886 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 886 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V61 ;

# 886 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 886 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X83 = saved ), ( (( ((& __0__V61 )-> __O1__2ea.i = __2__X83 ), 0 ) ), (& __0__V61 )) )
# 886 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 886 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;

# 886 "/home/claude/cfront-3/src/lex.cpp"
}

# 886 "/home/claude/cfront-3/src/lex.cpp"
;
{ 
# 887 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 887 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )97 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 14 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 887 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )97 ;

# 887 "/home/claude/cfront-3/src/lex.cpp"
}

# 887 "/home/claude/cfront-3/src/lex.cpp"
;
case 98 :
# 889 "/home/claude/cfront-3/src/lex.cpp"
txtfree = txtstart ;
{ 
# 891 "/home/claude/cfront-3/src/lex.cpp"
static bit __6warned = 0 ;
if (__6warned == 0 ){ 
# 893 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 893 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V62 ;

# 893 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & tloc , (const char *)"%k", (const struct
# 893 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (( ((& __0__V62 )-> __O1__2ea.i = ((unsigned long )__4x )), 0 ) ), (& __0__V62 )) , (const
# 893 "/home/claude/cfront-3/src/lex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__6warned = 1 ;
} }
}
{ 
# 897 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 897 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )__1n -> __O2__4name.syn_class , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = ((int )__4x )), __1__Xy00qjtkvpt5vcij ) , tloc ) ;
# 897 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )__1n -> __O2__4name.syn_class ;

# 897 "/home/claude/cfront-3/src/lex.cpp"
}

# 897 "/home/claude/cfront-3/src/lex.cpp"
;
case 99 :
# 899 "/home/claude/cfront-3/src/lex.cpp"
txtfree = txtstart ;
{ 
# 901 "/home/claude/cfront-3/src/lex.cpp"
static bit __6warned = 0 ;
if (__6warned == 0 ){ 
# 903 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 903 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V63 ;

# 903 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & tloc , (const char *)"%k", (const struct
# 903 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (( ((& __0__V63 )-> __O1__2ea.i = ((unsigned long )__4x )), 0 ) ), (& __0__V63 )) , (const
# 903 "/home/claude/cfront-3/src/lex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__6warned = 1 ;
} }
}
{ 
# 907 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 907 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )__1n -> __O2__4name.syn_class , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = ((int )__4x )), __1__Xy00qjtkvpt5vcij ) , tloc ) ;
# 907 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )__1n -> __O2__4name.syn_class ;

# 907 "/home/claude/cfront-3/src/lex.cpp"
}

# 907 "/home/claude/cfront-3/src/lex.cpp"
;
case 100 :
# 909 "/home/claude/cfront-3/src/lex.cpp"
txtfree = txtstart ;
{ 
# 911 "/home/claude/cfront-3/src/lex.cpp"
static bit __6warned = 0 ;
if (__6warned == 0 ){ 
# 913 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 913 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V64 ;

# 913 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'s' , & tloc , (const char *)"%k", (const struct
# 913 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (( ((& __0__V64 )-> __O1__2ea.i = ((unsigned long )__4x )), 0 ) ), (& __0__V64 )) , (const
# 913 "/home/claude/cfront-3/src/lex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__6warned = 1 ;
} }
}
{ 
# 917 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 917 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )__1n -> __O2__4name.syn_class , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = ((int )__4x )), __1__Xy00qjtkvpt5vcij ) , tloc ) ;
# 917 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )__1n -> __O2__4name.syn_class ;

# 917 "/home/claude/cfront-3/src/lex.cpp"
}

# 917 "/home/claude/cfront-3/src/lex.cpp"
;
case 101 :
# 919 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 920 "/home/claude/cfront-3/src/lex.cpp"
static bit __6warned = 0 ;
if (__6warned == 0 ){ 
# 921 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X84 ;

# 922 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 922 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V65 ;

# 922 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & tloc , (const char *)"%k is a future reserved keyword", (const struct
# 922 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X84 = __1n -> __O2__4name.syn_class ), ( (( ((& __0__V65 )-> __O1__2ea.i = __2__X84 ), 0 ) ), (& __0__V65 ))
# 922 "/home/claude/cfront-3/src/lex.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__6warned = 1 ;
} }
}
{ 
# 926 "/home/claude/cfront-3/src/lex.cpp"
char *__1__X85 ;

# 926 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00aqtkvpt5vcij ;

# 926 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )80 , ( (__1__X85 = ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation )?strdup ( (const char *)txtstart ) :txtstart )), ( (__1__Xy00aqtkvpt5vcij .
# 926 "/home/claude/cfront-3/src/lex.cpp"
s__7YYSTYPE = (const char *)__1__X85 ), __1__Xy00aqtkvpt5vcij ) ) , tloc ) ;

# 926 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )80 ;

# 926 "/home/claude/cfront-3/src/lex.cpp"
}

# 926 "/home/claude/cfront-3/src/lex.cpp"
;
case 102 :
# 928 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 929 "/home/claude/cfront-3/src/lex.cpp"
static bit __6warned = 0 ;
if (__6warned == 0 ){ 
# 930 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X86 ;

# 931 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 931 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V66 ;

# 931 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & tloc , (const char *)"%k is a future reserved keyword", (const struct
# 931 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X86 = __1n -> __O2__4name.syn_class ), ( (( ((& __0__V66 )-> __O1__2ea.i = __2__X86 ), 0 ) ), (& __0__V66 ))
# 931 "/home/claude/cfront-3/src/lex.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__6warned = 1 ;
} }
}
{ 
# 935 "/home/claude/cfront-3/src/lex.cpp"
char *__1__X87 ;

# 935 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00aqtkvpt5vcij ;

# 935 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )80 , ( (__1__X87 = ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation )?strdup ( (const char *)txtstart ) :txtstart )), ( (__1__Xy00aqtkvpt5vcij .
# 935 "/home/claude/cfront-3/src/lex.cpp"
s__7YYSTYPE = (const char *)__1__X87 ), __1__Xy00aqtkvpt5vcij ) ) , tloc ) ;

# 935 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )80 ;

# 935 "/home/claude/cfront-3/src/lex.cpp"
}

# 935 "/home/claude/cfront-3/src/lex.cpp"
;
case 103 :
# 937 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 938 "/home/claude/cfront-3/src/lex.cpp"
static bit __6warned = 0 ;
if (__6warned == 0 ){ 
# 939 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X88 ;

# 940 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 940 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V67 ;

# 940 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & tloc , (const char *)"%k is a future reserved keyword", (const struct
# 940 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X88 = __1n -> __O2__4name.syn_class ), ( (( ((& __0__V67 )-> __O1__2ea.i = __2__X88 ), 0 ) ), (& __0__V67 ))
# 940 "/home/claude/cfront-3/src/lex.cpp"
) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__6warned = 1 ;
} }
}
{ 
# 944 "/home/claude/cfront-3/src/lex.cpp"
char *__1__X89 ;

# 944 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00aqtkvpt5vcij ;

# 944 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )80 , ( (__1__X89 = ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation )?strdup ( (const char *)txtstart ) :txtstart )), ( (__1__Xy00aqtkvpt5vcij .
# 944 "/home/claude/cfront-3/src/lex.cpp"
s__7YYSTYPE = (const char *)__1__X89 ), __1__Xy00aqtkvpt5vcij ) ) , tloc ) ;

# 944 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )80 ;

# 944 "/home/claude/cfront-3/src/lex.cpp"
}

# 944 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 946 "/home/claude/cfront-3/src/lex.cpp"
txtfree = txtstart ;
{ 
# 947 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 947 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )__1n -> __O2__4name.syn_class , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = ((int )__4x )), __1__Xy00qjtkvpt5vcij ) , tloc ) ;
# 947 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )__1n -> __O2__4name.syn_class ;

# 947 "/home/claude/cfront-3/src/lex.cpp"
}

# 947 "/home/claude/cfront-3/src/lex.cpp"
;
} }
}

# 951 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 951 "/home/claude/cfront-3/src/lex.cpp"
char *__1__X90 ;

# 951 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00aqtkvpt5vcij ;

# 951 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )80 , ( (__1__X90 = ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation )?strdup ( (const char *)txtstart ) :txtstart )), ( (__1__Xy00aqtkvpt5vcij .
# 951 "/home/claude/cfront-3/src/lex.cpp"
s__7YYSTYPE = (const char *)__1__X90 ), __1__Xy00aqtkvpt5vcij ) ) , tloc ) ;

# 951 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )80 ;

# 951 "/home/claude/cfront-3/src/lex.cpp"
}

# 951 "/home/claude/cfront-3/src/lex.cpp"
;

# 953 "/home/claude/cfront-3/src/lex.cpp"
case 2 :
# 955 "/home/claude/cfront-3/src/lex.cpp"
__1ret = 82 ;

# 957 "/home/claude/cfront-3/src/lex.cpp"
if (__2lxchar == '0' ){ 
# 958 "/home/claude/cfront-3/src/lex.cpp"
int __4pkchar ;
__4pkchar = fgetc ( in_file ) ;
if ((__4pkchar == 'x' )|| (__4pkchar == 'X' )){ 
# 961 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))= __2lxchar )));
lxget__FiT1 ( __4pkchar , 010 ) ;
txtfree -- ;
if ((txtfree - txtstart )< 3 )
# 965 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"hex digitX after \"0x\"", (const
# 965 "/home/claude/cfront-3/src/lex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
saved ?( ( (__2lxchar = saved ), (saved = 0 )) , __2lxchar ) :(__2lxchar = fgetc ( in_file ) );
goto getsuffix ;
}
{ 
# 969 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X91 ;

# 969 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 969 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V68 ;

# 969 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 969 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X91 = saved ), ( (( ((& __0__V68 )-> __O1__2ea.i = __2__X91 ), 0 ) ), (& __0__V68 )) )
# 969 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 969 "/home/claude/cfront-3/src/lex.cpp"
saved = __4pkchar ;

# 969 "/home/claude/cfront-3/src/lex.cpp"
}

# 969 "/home/claude/cfront-3/src/lex.cpp"
;
}

# 972 "/home/claude/cfront-3/src/lex.cpp"
lxget__FiT1 ( __2lxchar , 02 ) ;
txtfree -- ;

# 975 "/home/claude/cfront-3/src/lex.cpp"
if ((saved ?( ( (__2lxchar = saved ), (saved = 0 )) , __2lxchar ) :(__2lxchar = fgetc ( in_file ) ))== '.' ){
# 975 "/home/claude/cfront-3/src/lex.cpp"

# 976 "/home/claude/cfront-3/src/lex.cpp"
getfp :
# 977 "/home/claude/cfront-3/src/lex.cpp"
lxget__FiT1 ( (int )'.' , 02 ) ;
txtfree -- ;
__1ret = 83 ;
saved ?( ( (__2lxchar = saved ), (saved = 0 )) , __2lxchar ) :(__2lxchar = fgetc ( in_file ) );
}

# 981 "/home/claude/cfront-3/src/lex.cpp"
;

# 983 "/home/claude/cfront-3/src/lex.cpp"
if ((__2lxchar == 'e' )|| (__2lxchar == 'E' )){ 
# 984 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))= __2lxchar )));
__2lxchar = fgetc ( in_file ) ;
if ((__2lxchar == '-' )|| (__2lxchar == '+' )){ 
# 987 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))= __2lxchar )));
__2lxchar = fgetc ( in_file ) ;
}
if ((lxmask [(__2lxchar + 1 )])& 02 ){ 
# 991 "/home/claude/cfront-3/src/lex.cpp"
lxget__FiT1 ( __2lxchar , 02 ) ;
txtfree -- ;
saved ?( ( (__2lxchar = saved ), (saved = 0 )) , __2lxchar ) :(__2lxchar = fgetc ( in_file ) );
}
else 
# 996 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"missing exponent digits?", (const struct ea *)ea0 ,
# 996 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1ret = 83 ;
}

# 998 "/home/claude/cfront-3/src/lex.cpp"
;

# 1000 "/home/claude/cfront-3/src/lex.cpp"
if ((((*txtstart ))== '0' )&& (__1ret == 82 )){ 
# 1001 "/home/claude/cfront-3/src/lex.cpp"
char *__4bch ;

# 1001 "/home/claude/cfront-3/src/lex.cpp"
__4bch = txtstart ;
while ((++ __4bch )<= txtfree ){ 
# 1003 "/home/claude/cfront-3/src/lex.cpp"
if ((((*__4bch ))== '8' )|| (((*__4bch ))== '9' ))
# 1004 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1004 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V69 ;

# 1004 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"%c used as octal digit", (const struct ea *)( ((
# 1004 "/home/claude/cfront-3/src/lex.cpp"
((& __0__V69 )-> __O1__2ea.i = ((unsigned long )((*__4bch )))), 0 ) ), (& __0__V69 )) , (const struct ea *)ea0 ,
# 1004 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}

# 1008 "/home/claude/cfront-3/src/lex.cpp"
getsuffix :
# 1009 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar ){ 
# 1010 "/home/claude/cfront-3/src/lex.cpp"
case 'f' :
# 1011 "/home/claude/cfront-3/src/lex.cpp"
case 'F' :
# 1012 "/home/claude/cfront-3/src/lex.cpp"
if (__1ret == 82 )
# 1013 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1013 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V70 ;

# 1013 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"%c suffix for integer constant", (const struct ea *)( ((
# 1013 "/home/claude/cfront-3/src/lex.cpp"
((& __0__V70 )-> __O1__2ea.i = ((unsigned long )__2lxchar )), 0 ) ), (& __0__V70 )) , (const struct ea *)ea0 ,
# 1013 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 1015 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))= __2lxchar )));
break ;
case 'u' :
# 1018 "/home/claude/cfront-3/src/lex.cpp"
case 'U' :
# 1019 "/home/claude/cfront-3/src/lex.cpp"
if (__1ret == 83 ){ 
# 1020 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1020 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V71 ;

# 1020 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"%c suffix for floating constant", (const struct ea *)( ((
# 1020 "/home/claude/cfront-3/src/lex.cpp"
((& __0__V71 )-> __O1__2ea.i = ((unsigned long )__2lxchar )), 0 ) ), (& __0__V71 )) , (const struct ea *)ea0 ,
# 1020 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
} }
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))= __2lxchar )));
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1025 "/home/claude/cfront-3/src/lex.cpp"
case 'l' :
# 1026 "/home/claude/cfront-3/src/lex.cpp"
case 'L' :
# 1027 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))=
# 1027 "/home/claude/cfront-3/src/lex.cpp"
__2lxchar )));
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1029 "/home/claude/cfront-3/src/lex.cpp"
case 'l' :
# 1030 "/home/claude/cfront-3/src/lex.cpp"
case 'L' :
# 1031 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))=
# 1031 "/home/claude/cfront-3/src/lex.cpp"
__2lxchar )));
break ;
default :
# 1034 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
break ;
}
break ;
default :
# 1039 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
break ;
}
break ;
case 'l' :
# 1044 "/home/claude/cfront-3/src/lex.cpp"
case 'L' :
# 1045 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))= __2lxchar )));
if (__1ret == 83 ){ 
# 1047 "/home/claude/cfront-3/src/lex.cpp"
break ;
}
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1050 "/home/claude/cfront-3/src/lex.cpp"
case 'l' :
# 1051 "/home/claude/cfront-3/src/lex.cpp"
case 'L' :
# 1052 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))=
# 1052 "/home/claude/cfront-3/src/lex.cpp"
__2lxchar )));
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1054 "/home/claude/cfront-3/src/lex.cpp"
case 'u' :
# 1055 "/home/claude/cfront-3/src/lex.cpp"
case 'U' :
# 1056 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))=
# 1056 "/home/claude/cfront-3/src/lex.cpp"
__2lxchar )));
break ;
default :
# 1059 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
break ;
}
break ;
case 'u' :
# 1064 "/home/claude/cfront-3/src/lex.cpp"
case 'U' :
# 1065 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__2lxchar ) :(((int )(((*(txtfree ++ )))= __2lxchar )));
break ;
default :
# 1068 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
break ;
}
break ;
default :
# 1073 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
break ;
}

# 1075 "/home/claude/cfront-3/src/lex.cpp"
;

# 1077 "/home/claude/cfront-3/src/lex.cpp"
if ((((*txtstart ))== '0' )&& ((txtfree - txtstart )== 1 ))
# 1078 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1078 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1078 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )86 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 0 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1078 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )86 ;

# 1078 "/home/claude/cfront-3/src/lex.cpp"
}

# 1078 "/home/claude/cfront-3/src/lex.cpp"
;

# 1080 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )0 ) :(((int )(((*(txtfree ++ )))= 0 )));
{ 
# 1081 "/home/claude/cfront-3/src/lex.cpp"
char *__1__X92 ;

# 1081 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00aqtkvpt5vcij ;

# 1081 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( __1ret , ( (__1__X92 = txtstart ), ( (__1__Xy00aqtkvpt5vcij . s__7YYSTYPE = (const char *)__1__X92 ), __1__Xy00aqtkvpt5vcij ) ) ,
# 1081 "/home/claude/cfront-3/src/lex.cpp"
tloc ) ;

# 1081 "/home/claude/cfront-3/src/lex.cpp"
return __1ret ;

# 1081 "/home/claude/cfront-3/src/lex.cpp"
}

# 1081 "/home/claude/cfront-3/src/lex.cpp"
;

# 1084 "/home/claude/cfront-3/src/lex.cpp"
case 8 :
# 1085 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1086 "/home/claude/cfront-3/src/lex.cpp"
case '.' :
# 1087 "/home/claude/cfront-3/src/lex.cpp"
if ((__2lxchar = fgetc ( in_file ) )!= '.' ){ 
# 1088 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 (
# 1088 "/home/claude/cfront-3/src/lex.cpp"
& tloc , (const char *)"token .. ?", (const struct ea *)ea0 , (const struct
# 1088 "/home/claude/cfront-3/src/lex.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
saved = __2lxchar ;
}
{ 
# 1091 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1091 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )155 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 0 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1091 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )155 ;

# 1091 "/home/claude/cfront-3/src/lex.cpp"
}

# 1091 "/home/claude/cfront-3/src/lex.cpp"
;
case '*' :
# 1093 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1093 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1093 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )180 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 45 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1093 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )180 ;

# 1093 "/home/claude/cfront-3/src/lex.cpp"
}

# 1093 "/home/claude/cfront-3/src/lex.cpp"
;
}

# 1096 "/home/claude/cfront-3/src/lex.cpp"
if ((lxmask [(__2lxchar + 1 )])& 02 ){ 
# 1097 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1097 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X93 ;

# 1097 "/home/claude/cfront-3/src/lex.cpp"
if (saved ){ 
# 1097 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V72 ;

# 1097 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"unget: saved==%c", (const struct
# 1097 "/home/claude/cfront-3/src/lex.cpp"
ea *)( (__2__X93 = saved ), ( (( ((& __0__V72 )-> __O1__2ea.i = __2__X93 ), 0 ) ), (& __0__V72 )) )
# 1097 "/home/claude/cfront-3/src/lex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1097 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;

# 1097 "/home/claude/cfront-3/src/lex.cpp"
}

# 1097 "/home/claude/cfront-3/src/lex.cpp"
;
goto getfp ;
}
saved = __2lxchar ;
{ 
# 1101 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1101 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )45 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 0 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1101 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )45 ;

# 1101 "/home/claude/cfront-3/src/lex.cpp"
}

# 1101 "/home/claude/cfront-3/src/lex.cpp"
;

# 1103 "/home/claude/cfront-3/src/lex.cpp"
case 4 :
# 1105 "/home/claude/cfront-3/src/lex.cpp"
get_string__Fv ( ) ;
{ 
# 1106 "/home/claude/cfront-3/src/lex.cpp"
char *__1__X94 ;

# 1106 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00aqtkvpt5vcij ;

# 1106 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )81 , ( (__1__X94 = txtstart ), ( (__1__Xy00aqtkvpt5vcij . s__7YYSTYPE = (const char *)__1__X94 ), __1__Xy00aqtkvpt5vcij )
# 1106 "/home/claude/cfront-3/src/lex.cpp"
) , tloc ) ;

# 1106 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )81 ;

# 1106 "/home/claude/cfront-3/src/lex.cpp"
}

# 1106 "/home/claude/cfront-3/src/lex.cpp"
;

# 1108 "/home/claude/cfront-3/src/lex.cpp"
case 5 :
# 1110 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1110 "/home/claude/cfront-3/src/lex.cpp"
char *__1__X95 ;

# 1110 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00aqtkvpt5vcij ;

# 1110 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )84 , ( (__1__X95 = chconst__Fv ( ) ), ( (__1__Xy00aqtkvpt5vcij . s__7YYSTYPE = (const char
# 1110 "/home/claude/cfront-3/src/lex.cpp"
*)__1__X95 ), __1__Xy00aqtkvpt5vcij ) ) , tloc ) ;

# 1110 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )84 ;

# 1110 "/home/claude/cfront-3/src/lex.cpp"
}

# 1110 "/home/claude/cfront-3/src/lex.cpp"
;

# 1112 "/home/claude/cfront-3/src/lex.cpp"
case 6 :
# 1113 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1114 "/home/claude/cfront-3/src/lex.cpp"
int __4i ;
int __4j ;

# 1117 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( '`' ) :(((int )(((*(txtfree ++ )))= '`' )));

# 1119 "/home/claude/cfront-3/src/lex.cpp"
for(__4i = 0 ;__4i < 7 ;++ __4i ) { 
# 1120 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )(__4j = fgetc ( in_file ) )) :(((int )(((*(txtfree ++
# 1120 "/home/claude/cfront-3/src/lex.cpp"
)))= (__4j = fgetc ( in_file ) ))));
if (__4j == '`' )break ;
}
(txtmax <= txtfree )?new_buf__Fc ( (char )0 ) :(((int )(((*(txtfree ++ )))= 0 )));
if (6 < __4i )
# 1125 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'l' , & tloc , (const char *)"bcd constant exceeds 6 characters",
# 1125 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
{ 
# 1126 "/home/claude/cfront-3/src/lex.cpp"
char *__1__X96 ;

# 1126 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00aqtkvpt5vcij ;

# 1126 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )84 , ( (__1__X96 = txtstart ), ( (__1__Xy00aqtkvpt5vcij . s__7YYSTYPE = (const char *)__1__X96 ), __1__Xy00aqtkvpt5vcij )
# 1126 "/home/claude/cfront-3/src/lex.cpp"
) , tloc ) ;

# 1126 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )84 ;

# 1126 "/home/claude/cfront-3/src/lex.cpp"
}

# 1126 "/home/claude/cfront-3/src/lex.cpp"
;
}

# 1129 "/home/claude/cfront-3/src/lex.cpp"
case 7 :
# 1130 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1131 "/home/claude/cfront-3/src/lex.cpp"
case '*' :
# 1132 "/home/claude/cfront-3/src/lex.cpp"
lxcom__Fv ( ) ;
break ;
case '/' :
# 1135 "/home/claude/cfront-3/src/lex.cpp"
linecom__Fv ( ) ;
break ;
case '=' :
# 1138 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1138 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1138 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )90 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 129 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1138 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )90 ;

# 1138 "/home/claude/cfront-3/src/lex.cpp"
}

# 1138 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1140 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1141 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1141 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )93 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 51 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1141 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )93 ;

# 1141 "/home/claude/cfront-3/src/lex.cpp"
}

# 1141 "/home/claude/cfront-3/src/lex.cpp"
;
}

# 1144 "/home/claude/cfront-3/src/lex.cpp"
case 10 :
# 1145 "/home/claude/cfront-3/src/lex.cpp"
continue ;

# 1147 "/home/claude/cfront-3/src/lex.cpp"
case 11 :
# 1148 "/home/claude/cfront-3/src/lex.cpp"
++ tloc . line__3loc ;

# 1150 "/home/claude/cfront-3/src/lex.cpp"
saved = lxtitle__Fv ( ) ;
continue ;

# 1153 "/home/claude/cfront-3/src/lex.cpp"
case 12 :
# 1154 "/home/claude/cfront-3/src/lex.cpp"
if (128 <= (b_level ++ )){ 
# 1155 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'l' , & tloc , (const char *)"blocks too deeply nested",
# 1155 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
ext__Fi ( 3 ) ;
}
{ 
# 1158 "/home/claude/cfront-3/src/lex.cpp"
struct loc __1__X97 ;

# 1158 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00adtkvpt5vcij ;

# 1158 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )73 , ( (__1__X97 = tloc ), ( (__1__Xy00adtkvpt5vcij . l__7YYSTYPE = __1__X97 ), __1__Xy00adtkvpt5vcij ) ) ,
# 1158 "/home/claude/cfront-3/src/lex.cpp"
tloc ) ;

# 1158 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )73 ;

# 1158 "/home/claude/cfront-3/src/lex.cpp"
}

# 1158 "/home/claude/cfront-3/src/lex.cpp"
;

# 1160 "/home/claude/cfront-3/src/lex.cpp"
case 13 :
# 1161 "/home/claude/cfront-3/src/lex.cpp"
if ((lcount + (b_level -- ))<= 0 ){ 
# 1162 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"unexpected '}'",
# 1162 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
b_level = 0 ;
}
{ 
# 1165 "/home/claude/cfront-3/src/lex.cpp"
struct loc __1__X98 ;

# 1165 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00adtkvpt5vcij ;

# 1165 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )74 , ( (__1__X98 = tloc ), ( (__1__Xy00adtkvpt5vcij . l__7YYSTYPE = __1__X98 ), __1__Xy00adtkvpt5vcij ) ) ,
# 1165 "/home/claude/cfront-3/src/lex.cpp"
tloc ) ;

# 1165 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )74 ;

# 1165 "/home/claude/cfront-3/src/lex.cpp"
}

# 1165 "/home/claude/cfront-3/src/lex.cpp"
;

# 1167 "/home/claude/cfront-3/src/lex.cpp"
case 14 :
# 1168 "/home/claude/cfront-3/src/lex.cpp"
p_level ++ ;
{ 
# 1169 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1169 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )40 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 0 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1169 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )40 ;

# 1169 "/home/claude/cfront-3/src/lex.cpp"
}

# 1169 "/home/claude/cfront-3/src/lex.cpp"
;

# 1171 "/home/claude/cfront-3/src/lex.cpp"
case 15 :
# 1172 "/home/claude/cfront-3/src/lex.cpp"
if ((p_level -- )<= 0 ){ 
# 1173 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"unexpected ')'",
# 1173 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
p_level = 0 ;
}
{ 
# 1176 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1176 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )41 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 0 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1176 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )41 ;

# 1176 "/home/claude/cfront-3/src/lex.cpp"
}

# 1176 "/home/claude/cfront-3/src/lex.cpp"
;

# 1178 "/home/claude/cfront-3/src/lex.cpp"
case 17 :
# 1179 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1180 "/home/claude/cfront-3/src/lex.cpp"
case '=' :
# 1181 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1181 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1181 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )92 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 62 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1181 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )92 ;

# 1181 "/home/claude/cfront-3/src/lex.cpp"
}

# 1181 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1183 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1184 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1184 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )70 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 70 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1184 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )70 ;

# 1184 "/home/claude/cfront-3/src/lex.cpp"
}

# 1184 "/home/claude/cfront-3/src/lex.cpp"
;
}

# 1187 "/home/claude/cfront-3/src/lex.cpp"
case 28 :
# 1188 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1189 "/home/claude/cfront-3/src/lex.cpp"
case ':' :
# 1190 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1190 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1190 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )160 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 0 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1190 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )160 ;

# 1190 "/home/claude/cfront-3/src/lex.cpp"
}

# 1190 "/home/claude/cfront-3/src/lex.cpp"
;
case '=' :
# 1192 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"':=' is not a c++ operator", (const struct ea *)ea0 ,
# 1192 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
{ 
# 1193 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1193 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )70 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 70 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1193 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )70 ;

# 1193 "/home/claude/cfront-3/src/lex.cpp"
}

# 1193 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1195 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1196 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1196 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )69 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 69 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1196 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )69 ;

# 1196 "/home/claude/cfront-3/src/lex.cpp"
}

# 1196 "/home/claude/cfront-3/src/lex.cpp"
;
}
case 24 :
# 1199 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1200 "/home/claude/cfront-3/src/lex.cpp"
case '=' :
# 1201 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1201 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1201 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )92 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 63 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1201 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )92 ;

# 1201 "/home/claude/cfront-3/src/lex.cpp"
}

# 1201 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1203 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1204 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1204 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )46 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 46 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1204 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )46 ;

# 1204 "/home/claude/cfront-3/src/lex.cpp"
}

# 1204 "/home/claude/cfront-3/src/lex.cpp"
;
}
case 19 :
# 1207 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1208 "/home/claude/cfront-3/src/lex.cpp"
case '>' :
# 1209 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1210 "/home/claude/cfront-3/src/lex.cpp"
case '=' :
# 1211 "/home/claude/cfront-3/src/lex.cpp"
{
# 1211 "/home/claude/cfront-3/src/lex.cpp"

# 1211 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1211 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )90 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 135 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1211 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )90 ;

# 1211 "/home/claude/cfront-3/src/lex.cpp"
}

# 1211 "/home/claude/cfront-3/src/lex.cpp"
;
break ;
default :
# 1214 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1215 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1215 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )94 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 57 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1215 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )94 ;

# 1215 "/home/claude/cfront-3/src/lex.cpp"
}

# 1215 "/home/claude/cfront-3/src/lex.cpp"
;
}
case '=' :
# 1218 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1218 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1218 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )91 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 61 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1218 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )91 ;

# 1218 "/home/claude/cfront-3/src/lex.cpp"
}

# 1218 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1220 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1221 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1221 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )60 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 60 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1221 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )60 ;

# 1221 "/home/claude/cfront-3/src/lex.cpp"
}

# 1221 "/home/claude/cfront-3/src/lex.cpp"
;
}
case 18 :
# 1224 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1225 "/home/claude/cfront-3/src/lex.cpp"
case '<' :
# 1226 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1227 "/home/claude/cfront-3/src/lex.cpp"
case '=' :
# 1228 "/home/claude/cfront-3/src/lex.cpp"
{
# 1228 "/home/claude/cfront-3/src/lex.cpp"

# 1228 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1228 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )90 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 134 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1228 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )90 ;

# 1228 "/home/claude/cfront-3/src/lex.cpp"
}

# 1228 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1230 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1231 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1231 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )94 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 56 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1231 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )94 ;

# 1231 "/home/claude/cfront-3/src/lex.cpp"
}

# 1231 "/home/claude/cfront-3/src/lex.cpp"
;
}
case '=' :
# 1234 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1234 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1234 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )91 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 59 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1234 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )91 ;

# 1234 "/home/claude/cfront-3/src/lex.cpp"
}

# 1234 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1236 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1237 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1237 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )58 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 58 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1237 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )58 ;

# 1237 "/home/claude/cfront-3/src/lex.cpp"
}

# 1237 "/home/claude/cfront-3/src/lex.cpp"
;
}
case 22 :
# 1240 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1241 "/home/claude/cfront-3/src/lex.cpp"
case '&' :
# 1242 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1242 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1242 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )66 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 66 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1242 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )66 ;

# 1242 "/home/claude/cfront-3/src/lex.cpp"
}

# 1242 "/home/claude/cfront-3/src/lex.cpp"
;
case '=' :
# 1244 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1244 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1244 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )90 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 131 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1244 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )90 ;

# 1244 "/home/claude/cfront-3/src/lex.cpp"
}

# 1244 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1246 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1247 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1247 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )52 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 52 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1247 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )52 ;

# 1247 "/home/claude/cfront-3/src/lex.cpp"
}

# 1247 "/home/claude/cfront-3/src/lex.cpp"
;
}
case 21 :
# 1250 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1251 "/home/claude/cfront-3/src/lex.cpp"
case '|' :
# 1252 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1252 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1252 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )67 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 67 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1252 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )67 ;

# 1252 "/home/claude/cfront-3/src/lex.cpp"
}

# 1252 "/home/claude/cfront-3/src/lex.cpp"
;
case '=' :
# 1254 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1254 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1254 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )90 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 132 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1254 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )90 ;

# 1254 "/home/claude/cfront-3/src/lex.cpp"
}

# 1254 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1256 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1257 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1257 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )65 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 65 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1257 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )65 ;

# 1257 "/home/claude/cfront-3/src/lex.cpp"
}

# 1257 "/home/claude/cfront-3/src/lex.cpp"
;
}
case 20 :
# 1260 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1261 "/home/claude/cfront-3/src/lex.cpp"
case '=' :
# 1262 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1262 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1262 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )90 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 133 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1262 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )90 ;

# 1262 "/home/claude/cfront-3/src/lex.cpp"
}

# 1262 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1264 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1265 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1265 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )64 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 64 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1265 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )64 ;

# 1265 "/home/claude/cfront-3/src/lex.cpp"
}

# 1265 "/home/claude/cfront-3/src/lex.cpp"
;
}
case 27 :
# 1268 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1269 "/home/claude/cfront-3/src/lex.cpp"
case '=' :
# 1270 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1270 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1270 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )90 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 126 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1270 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )90 ;

# 1270 "/home/claude/cfront-3/src/lex.cpp"
}

# 1270 "/home/claude/cfront-3/src/lex.cpp"
;
case '+' :
# 1272 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1272 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1272 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )95 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 48 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1272 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )95 ;

# 1272 "/home/claude/cfront-3/src/lex.cpp"
}

# 1272 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1274 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1275 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1275 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )54 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 54 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1275 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )54 ;

# 1275 "/home/claude/cfront-3/src/lex.cpp"
}

# 1275 "/home/claude/cfront-3/src/lex.cpp"
;
}
case 25 :
# 1278 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1279 "/home/claude/cfront-3/src/lex.cpp"
case '=' :
# 1280 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1280 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1280 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )90 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 127 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1280 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )90 ;

# 1280 "/home/claude/cfront-3/src/lex.cpp"
}

# 1280 "/home/claude/cfront-3/src/lex.cpp"
;
case '-' :
# 1282 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1282 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1282 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )95 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 49 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1282 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )95 ;

# 1282 "/home/claude/cfront-3/src/lex.cpp"
}

# 1282 "/home/claude/cfront-3/src/lex.cpp"
;
case '>' :
# 1284 "/home/claude/cfront-3/src/lex.cpp"
if ((__2lxchar = fgetc ( in_file ) )== '*' )
# 1285 "/home/claude/cfront-3/src/lex.cpp"
{ { 
# 1285 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1285 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )180 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 44 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1285 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )180 ;

# 1285 "/home/claude/cfront-3/src/lex.cpp"
}

# 1285 "/home/claude/cfront-3/src/lex.cpp"
;

# 1285 "/home/claude/cfront-3/src/lex.cpp"
}
else 
# 1287 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1288 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1288 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )44 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 44 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1288 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )44 ;

# 1288 "/home/claude/cfront-3/src/lex.cpp"
}

# 1288 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1290 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1291 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1291 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )55 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 55 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1291 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )55 ;

# 1291 "/home/claude/cfront-3/src/lex.cpp"
}

# 1291 "/home/claude/cfront-3/src/lex.cpp"
;
}
case 26 :
# 1294 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1295 "/home/claude/cfront-3/src/lex.cpp"
case '=' :
# 1296 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1296 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1296 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )90 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 128 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1296 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )90 ;

# 1296 "/home/claude/cfront-3/src/lex.cpp"
}

# 1296 "/home/claude/cfront-3/src/lex.cpp"
;
case '/' :
# 1298 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & tloc , (const char *)"*/ not as end of comment", (const
# 1298 "/home/claude/cfront-3/src/lex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
default :
# 1300 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1301 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1301 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )50 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 50 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1301 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )50 ;

# 1301 "/home/claude/cfront-3/src/lex.cpp"
}

# 1301 "/home/claude/cfront-3/src/lex.cpp"
;
}
case 23 :
# 1304 "/home/claude/cfront-3/src/lex.cpp"
switch (__2lxchar = fgetc ( in_file ) ){ 
# 1305 "/home/claude/cfront-3/src/lex.cpp"
case '=' :
# 1306 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1306 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1306 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )90 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 130 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1306 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )90 ;

# 1306 "/home/claude/cfront-3/src/lex.cpp"
}

# 1306 "/home/claude/cfront-3/src/lex.cpp"
;
default :
# 1308 "/home/claude/cfront-3/src/lex.cpp"
saved = __2lxchar ;
{ 
# 1309 "/home/claude/cfront-3/src/lex.cpp"
union YYSTYPE __1__Xy00qjtkvpt5vcij ;

# 1309 "/home/claude/cfront-3/src/lex.cpp"
addtok__FUc7YYSTYPE3loc ( (unsigned char )93 , ( (__1__Xy00qjtkvpt5vcij . t__7YYSTYPE = 53 ), __1__Xy00qjtkvpt5vcij ) , tloc ) ;

# 1309 "/home/claude/cfront-3/src/lex.cpp"
return (unsigned char )93 ;

# 1309 "/home/claude/cfront-3/src/lex.cpp"
}

# 1309 "/home/claude/cfront-3/src/lex.cpp"
;
}
default :
# 1312 "/home/claude/cfront-3/src/lex.cpp"
{ { 
# 1312 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V73 ;

# 1312 "/home/claude/cfront-3/src/lex.cpp"
struct ea __0__V74 ;

# 1312 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"lex act==%d getc()->%d", (const struct
# 1312 "/home/claude/cfront-3/src/lex.cpp"
ea *)( ((& __0__V73 )-> __O1__2ea.p = ((const void *)__2p )), (& __0__V73 )) , (const struct ea *)( ((
# 1312 "/home/claude/cfront-3/src/lex.cpp"
((& __0__V74 )-> __O1__2ea.i = ((unsigned long )__2lxchar )), 0 ) ), (& __0__V74 )) , (const struct ea *)ea0 ,
# 1312 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 ) ;
} 
# 1312 "/home/claude/cfront-3/src/lex.cpp"
}

# 1314 "/home/claude/cfront-3/src/lex.cpp"
}

# 1316 "/home/claude/cfront-3/src/lex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & tloc , (const char *)"lex, main switch", (const
# 1316 "/home/claude/cfront-3/src/lex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
}

# 1319 "/home/claude/cfront-3/src/lex.cpp"
}

# 491 "/home/claude/cfront-3/src/template.h"

# 1321 "/home/claude/cfront-3/src/lex.cpp"
static int lxtitle__Fv (void )
# 1325 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1326 "/home/claude/cfront-3/src/lex.cpp"
int __1c ;

# 1328 "/home/claude/cfront-3/src/lex.cpp"
for(;;) { 
# 1329 "/home/claude/cfront-3/src/lex.cpp"
saved ?( ( (__1c = saved ), (saved = 0 )) , __1c ) :(__1c = fgetc ( in_file ) );
# 1329 "/home/claude/cfront-3/src/lex.cpp"

# 1330 "/home/claude/cfront-3/src/lex.cpp"
switch (__1c ){ 
# 1331 "/home/claude/cfront-3/src/lex.cpp"
default :
# 1332 "/home/claude/cfront-3/src/lex.cpp"
return __1c ;
case '\n' :
# 1334 "/home/claude/cfront-3/src/lex.cpp"
tloc . line__3loc ++ ;

# 1336 "/home/claude/cfront-3/src/lex.cpp"
ll :
# 1337 "/home/claude/cfront-3/src/lex.cpp"
break ;
case '#' :
# 1339 "/home/claude/cfront-3/src/lex.cpp"
{ int __4cl ;

# 1339 "/home/claude/cfront-3/src/lex.cpp"
__4cl = tloc . line__3loc ;
tloc . line__3loc = 0 ;
for(;;) 
# 1342 "/home/claude/cfront-3/src/lex.cpp"
switch (__1c = fgetc ( in_file ) ){ 
# 1343 "/home/claude/cfront-3/src/lex.cpp"
case '"' :
# 1344 "/home/claude/cfront-3/src/lex.cpp"
txtstart = txtfree ;
for(;;) 
# 1346 "/home/claude/cfront-3/src/lex.cpp"
switch (__1c = fgetc ( in_file ) ){ 
# 1347 "/home/claude/cfront-3/src/lex.cpp"
case '"' :
# 1348 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( '\0' ) :(((int )(((*(txtfree ++ )))= '\0' )));
# 1348 "/home/claude/cfront-3/src/lex.cpp"

# 1350 "/home/claude/cfront-3/src/lex.cpp"
while ((__1c = fgetc ( in_file ) )!= '\n' );

# 1352 "/home/claude/cfront-3/src/lex.cpp"
if ((*txtstart )){ 
# 1353 "/home/claude/cfront-3/src/lex.cpp"
const char *__7fn ;

# 1354 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X99 ;

# 1354 "/home/claude/cfront-3/src/lex.cpp"
int __2__X100 ;

# 1354 "/home/claude/cfront-3/src/lex.cpp"
if ((__7fn = ((*( (__0__X99 = (& file_name )), ( (__2__X100 = tcurr_file ), ( (((CPchar *)(& (__0__X99 -> p__12Block_CPchar [__2__X100 ]))))) )
# 1354 "/home/claude/cfront-3/src/lex.cpp"
) )))&& (strcmp ( (const char *)txtstart , __7fn ) == 0 ))
# 1355 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 1357 "/home/claude/cfront-3/src/lex.cpp"
}
else { 
# 1360 "/home/claude/cfront-3/src/lex.cpp"
int __8found ;
int __8findex ;

# 1360 "/home/claude/cfront-3/src/lex.cpp"
__8found = 0 ;
__8findex = Nfile ;
for(;__8findex >= 0 ;__8findex -- ) { 
# 1362 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X101 ;

# 1363 "/home/claude/cfront-3/src/lex.cpp"
if (__8findex == tcurr_file )continue ;
__7fn = ((*( (__0__X101 = (& file_name )), ( (((CPchar *)(& (__0__X101 -> p__12Block_CPchar [__8findex ]))))) ) ));
if ((__7fn != 0 )&& (strcmp ( (const char *)txtstart , __7fn ) == 0 )){ 
# 1366 "/home/claude/cfront-3/src/lex.cpp"
__8found = 1 ;
tcurr_file = __8findex ;
break ;
}
}
if (__8found == 0 ){ 
# 1373 "/home/claude/cfront-3/src/lex.cpp"
char *__9p ;

# 1374 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X102 ;

# 1374 "/home/claude/cfront-3/src/lex.cpp"
unsigned long __2__X103 ;

# 1374 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X104 ;

# 1374 "/home/claude/cfront-3/src/lex.cpp"
int __2__X105 ;

# 1373 "/home/claude/cfront-3/src/lex.cpp"
__9p = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* ((txtfree - txtstart )+ 1 ))) ));
((void )strcpy ( __9p , (const char *)txtstart ) );
tcurr_file = (++ Nfile );
( (__0__X102 = (& file_name )), ( (__2__X103 = Nfile ), ( ((__2__X103 < __0__X102 -> n__12Block_CPchar )|| grow__12Block_CPcharFUl ( __0__X102 , __2__X103 )
# 1376 "/home/claude/cfront-3/src/lex.cpp"
)) ) ) ;
((*( (__0__X104 = (& file_name )), ( (__2__X105 = Nfile ), ( (((CPchar *)(& (__0__X104 -> p__12Block_CPchar [__2__X105 ]))))) ) ) ))=
# 1377 "/home/claude/cfront-3/src/lex.cpp"
(const char *)__9p ;
}

# 1380 "/home/claude/cfront-3/src/lex.cpp"
}
}
else { 
# 1383 "/home/claude/cfront-3/src/lex.cpp"
tcurr_file = 0 ;
}
txtfree = txtstart ;
tloc . file__3loc = tcurr_file ;
if (dtpt_opt && (doneflag == 0 )){ 
# 1388 "/home/claude/cfront-3/src/lex.cpp"
first_file = 0 ;
doneflag = 1 ;
}

# 1392 "/home/claude/cfront-3/src/lex.cpp"
goto ll ;
case '\n' :
# 1394 "/home/claude/cfront-3/src/lex.cpp"
error__FP3locPCcRC2eaN33 ( & tloc , (const char *)"unexpected end of line on '# line'", (const struct ea *)ea0 ,
# 1394 "/home/claude/cfront-3/src/lex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
default :
# 1396 "/home/claude/cfront-3/src/lex.cpp"
(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
}
case ' ' :
# 1399 "/home/claude/cfront-3/src/lex.cpp"
break ;

# 1401 "/home/claude/cfront-3/src/lex.cpp"
case '0' :
# 1402 "/home/claude/cfront-3/src/lex.cpp"
case '1' :
# 1403 "/home/claude/cfront-3/src/lex.cpp"
case '2' :
# 1404 "/home/claude/cfront-3/src/lex.cpp"
case '3' :
# 1405 "/home/claude/cfront-3/src/lex.cpp"
case '4' :
# 1406 "/home/claude/cfront-3/src/lex.cpp"
case '5' :
# 1407 "/home/claude/cfront-3/src/lex.cpp"
case '6' :
# 1408 "/home/claude/cfront-3/src/lex.cpp"
case '7' :
# 1409 "/home/claude/cfront-3/src/lex.cpp"
case '8' :
# 1410 "/home/claude/cfront-3/src/lex.cpp"
case '9' :
# 1411 "/home/claude/cfront-3/src/lex.cpp"
tloc . line__3loc = (((tloc . line__3loc *
# 1411 "/home/claude/cfront-3/src/lex.cpp"
10 )+ __1c )- '0' );
break ;

# 1414 "/home/claude/cfront-3/src/lex.cpp"
case 'l' :
# 1415 "/home/claude/cfront-3/src/lex.cpp"
if ((((__1c = fgetc ( in_file ) )== 'i' )&& ((__1c = fgetc ( in_file ) )== 'n' ))&& ((__1c = fgetc (
# 1415 "/home/claude/cfront-3/src/lex.cpp"
in_file ) )== 'e' ))break ;
case '\n' :
# 1417 "/home/claude/cfront-3/src/lex.cpp"
putline__3locFv ( & tloc ) ;
goto ll ;

# 1420 "/home/claude/cfront-3/src/lex.cpp"
default :
# 1421 "/home/claude/cfront-3/src/lex.cpp"
tloc . line__3loc = __4cl ;
(txtmax <= txtfree )?new_buf__Fc ( '#' ) :(((int )(((*(txtfree ++ )))= '#' )));
(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
while ((__1c = fgetc ( in_file ) )!= '\n' )(txtmax <= txtfree )?new_buf__Fc ( (char )__1c ) :(((int )(((*(txtfree ++ )))= __1c )));
(txtmax <= txtfree )?new_buf__Fc ( '\0' ) :(((int )(((*(txtfree ++ )))= '\0' )));
fprintf ( out_file , (const char *)"\n%s\n", txtstart ) ;
txtstart = txtfree ;
tloc . line__3loc ++ ;

# 1430 "/home/claude/cfront-3/src/lex.cpp"
goto ll ;
}
}
}
}
}

# 1435 "/home/claude/cfront-3/src/lex.cpp"
void __sti___in_progress_ (void )
# 154 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 154 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X106 ;

# 154 "/home/claude/cfront-3/src/lex.cpp"
( (__0__X106 = (& file_name )), ( ((__0__X106 || (__0__X106 = (struct Block_CPchar *)__nw__FUl ( (unsigned long )(sizeof (struct Block_CPchar))) ))?(
# 154 "/home/claude/cfront-3/src/lex.cpp"
(__0__X106 -> n__12Block_CPchar = 0 ), (__0__X106 -> p__12Block_CPchar = 0 )) :0 ), __0__X106 ) ) ;

# 100 "/home/claude/cfront-3/src/cfront.h"
out_file = _get_stdout ( ) ;
in_file = _get_stdin ( ) ;

# 101 "/home/claude/cfront-3/src/cfront.h"
}

# 1435 "/home/claude/cfront-3/src/lex.cpp"
void __std___in_progress_ (void )
# 154 "/home/claude/cfront-3/src/lex.cpp"
{ 
# 154 "/home/claude/cfront-3/src/lex.cpp"
struct Block_CPchar *__0__X107 ;

# 154 "/home/claude/cfront-3/src/lex.cpp"
( (__0__X107 = (& file_name )), ( (__0__X107 ?(((void )( __dl__FPv ( (void *)__0__X107 -> p__12Block_CPchar ) , (__0__X107 ?(((void )(((void
# 154 "/home/claude/cfront-3/src/lex.cpp"
)0 )))):(((void )0 )))) )):(((void )0 )))) ) ;

# 154 "/home/claude/cfront-3/src/lex.cpp"
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

# 30 "/home/claude/cfront-3/src/tqueue.h"
extern struct toknode *free_toks__7toknode;

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

# 1435 "/home/claude/cfront-3/src/lex.cpp"

/* the end */
