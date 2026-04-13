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

# 24 "/home/claude/cfront-3/src/print.cpp"
static int addrof_cm ;

# 29 "/home/claude/cfront-3/src/print.cpp"
static ssize_t lab_cnt = 0 ;
static ssize_t curr_lab = 0 ;

# 796 "/home/claude/cfront-3/src/cfront.h"
void print__4exprFv (struct expr *__0this );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 96 "/home/claude/incl-linux32/stdio.h"
extern int fputc (int , void *);

# 32 "/home/claude/cfront-3/src/print.cpp"
void Eprint__FP4expr (Pexpr __1e )
# 33 "/home/claude/cfront-3/src/print.cpp"
{ 
# 35 "/home/claude/cfront-3/src/print.cpp"
switch (__1e -> base__4node ){ 
# 36 "/home/claude/cfront-3/src/print.cpp"
case 45 :
# 37 "/home/claude/cfront-3/src/print.cpp"
case 44 :
# 38 "/home/claude/cfront-3/src/print.cpp"
if (((((struct ref *)(((struct ref *)__1e ))))-> __O4__4expr.mem && (((struct ref *)(((struct
# 38 "/home/claude/cfront-3/src/print.cpp"
ref *)__1e ))))-> __O4__4expr.mem -> __O1__4expr.tp )&& ((((struct ref *)(((struct ref *)__1e ))))-> __O4__4expr.mem -> __O1__4expr.tp -> base__4node == 108 ))
# 44 "/home/claude/cfront-3/src/print.cpp"
{ 
# 45 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( (((struct ref *)(((struct ref *)__1e ))))->
# 45 "/home/claude/cfront-3/src/print.cpp"
__O4__4expr.mem ) ;
break ;
}
case 85 :
# 49 "/home/claude/cfront-3/src/print.cpp"
case 177 :
# 50 "/home/claude/cfront-3/src/print.cpp"
case 80 :
# 51 "/home/claude/cfront-3/src/print.cpp"
case 86 :
# 52 "/home/claude/cfront-3/src/print.cpp"
case 82 :
# 53 "/home/claude/cfront-3/src/print.cpp"
case 84 :
# 54 "/home/claude/cfront-3/src/print.cpp"
case 83 :
# 55 "/home/claude/cfront-3/src/print.cpp"
case 81 :
# 56 "/home/claude/cfront-3/src/print.cpp"
case 150 :
# 57 "/home/claude/cfront-3/src/print.cpp"
case 165 :
# 58 "/home/claude/cfront-3/src/print.cpp"
case 71 :
# 59 "/home/claude/cfront-3/src/print.cpp"
case 147 :
# 60 "/home/claude/cfront-3/src/print.cpp"
case 140 :
# 61 "/home/claude/cfront-3/src/print.cpp"
case
# 61 "/home/claude/cfront-3/src/print.cpp"
69 :
# 62 "/home/claude/cfront-3/src/print.cpp"
case 124 :
# 63 "/home/claude/cfront-3/src/print.cpp"
case 34 :
# 64 "/home/claude/cfront-3/src/print.cpp"
case 109 :
# 65 "/home/claude/cfront-3/src/print.cpp"
case 146 :
# 66 "/home/claude/cfront-3/src/print.cpp"
case 168 :
# 67 "/home/claude/cfront-3/src/print.cpp"
case 169 :
# 68 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __1e ) ;
break ;
case 162 :
# 71 "/home/claude/cfront-3/src/print.cpp"
{ 
# 71 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V17 ;

# 71 "/home/claude/cfront-3/src/print.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"T destructor in %cprint()", (const struct ea *)( ((
# 71 "/home/claude/cfront-3/src/print.cpp"
((& __0__V17 )-> __O1__2ea.i = ((unsigned long )'E' )), 0 ) ), (& __0__V17 )) , (const struct ea *)ea0 ,
# 71 "/home/claude/cfront-3/src/print.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
case 144 :
# 73 "/home/claude/cfront-3/src/print.cpp"
break ;
default :
# 75 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )'(' , out_file ) ;
print__4exprFv ( __1e ) ;
fputc ( (int )')' , out_file ) ;
} }
}

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 77 "/home/claude/incl-linux32/stdio.h"
extern int fputs (const char *__0s , void *__0stream );

# 25 "/home/claude/cfront-3/src/print.cpp"
extern void puttok__FUc (TOK );

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );
bit is_unsigned__4typeFv (struct type *__0this );

# 337 "/home/claude/cfront-3/src/cfront.h"
void print__4typeFv (struct type *__0this );

# 79 "/home/claude/incl-linux32/stdio.h"
extern int fprintf (void *, const char *,...);

# 947 "/home/claude/cfront-3/src/cfront.h"
void print__4nameFUc (struct name *__0this , bit __1fullprint );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 1014 "/home/claude/cfront-3/src/cfront.h"
void print__4stmtFv (struct stmt *__0this );

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 359 "/home/claude/cfront-3/src/cfront.h"
Pfct memptr__4typeFv (struct type *__0this );

# 855 "/home/claude/cfront-3/src/cfront.h"
extern char *vtbl_name__FPCcT1 (const char *, const char *);

# 748 "/home/claude/cfront-3/src/cfront.h"
extern char *ptbl_lookup__FPCc (const char *);

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 13 "/home/claude/incl-linux32/string.h"
extern char *strcat (char *, const char *);

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 342 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr__4typeFv (struct type *__0this );

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 803 "/home/claude/cfront-3/src/cfront.h"
Pexpr address__4exprFv (struct expr *__0this );

# 799 "/home/claude/cfront-3/src/cfront.h"
long long eval__4exprFv (struct expr *__0this );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 1 ""
extern void __dl__FPv (void *);

# 81 "/home/claude/cfront-3/src/print.cpp"
void print__4exprFv (register struct expr *__0this )
# 82 "/home/claude/cfront-3/src/print.cpp"
{ 
# 82 "/home/claude/cfront-3/src/print.cpp"
unsigned long __2__X31 ;

# 83 "/home/claude/cfront-3/src/print.cpp"
if (__0this == 0 )error__FiPCc ( (int )'i' , (const char *)"0->E::print()") ;
if (((__0this == __0this -> __O2__4expr.e1 )|| (__0this == __0this -> __O3__4expr.e2 ))&& (__0this -> base__4node != 85 )){ 
# 84 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V18 ;

# 84 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V19 ;

# 84 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V20 ;

# 84 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V21 ;

# 84 "/home/claude/cfront-3/src/print.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"(%p%k)->E::print(%p %p)", (const struct ea *)( ((&
# 84 "/home/claude/cfront-3/src/print.cpp"
__0__V18 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V18 )) , (const struct ea *)( (__2__X31 = __0this -> base__4node ),
# 84 "/home/claude/cfront-3/src/print.cpp"
( (( ((& __0__V19 )-> __O1__2ea.i = __2__X31 ), 0 ) ), (& __0__V19 )) ) , (const struct
# 84 "/home/claude/cfront-3/src/print.cpp"
ea *)__ct__2eaFPCv ( & __0__V20 , (const void *)__0this -> __O2__4expr.e1 ) , (const struct ea *)__ct__2eaFPCv ( & __0__V21 , (const
# 84 "/home/claude/cfront-3/src/print.cpp"
void *)__0this -> __O3__4expr.e2 ) ) ;
} 
# 87 "/home/claude/cfront-3/src/print.cpp"
switch (__0this -> base__4node ){ 
# 87 "/home/claude/cfront-3/src/print.cpp"
unsigned long __2__X33 ;

# 88 "/home/claude/cfront-3/src/print.cpp"
case 177 :
# 89 "/home/claude/cfront-3/src/print.cpp"
{ 
# 91 "/home/claude/cfront-3/src/print.cpp"
int __3not_allocated ;

# 91 "/home/claude/cfront-3/src/print.cpp"
__3not_allocated = 0 ;
switch (__0this -> __O2__4expr.i1 ){ 
# 93 "/home/claude/cfront-3/src/print.cpp"
case 0 :
# 94 "/home/claude/cfront-3/src/print.cpp"
( fputc ( (int )'O' , out_file ) , fputs ( __0this -> __O3__4expr.string2 , out_file )
# 94 "/home/claude/cfront-3/src/print.cpp"
) ;
puttok__FUc ( (unsigned char )45 ) ;
print__4exprFv ( __0this -> __O4__4expr.mem ) ;
break ;
case 1 :
# 99 "/home/claude/cfront-3/src/print.cpp"
( fputc ( (int )'P' , out_file ) , fputs ( __0this -> __O3__4expr.string2 , out_file ) ) ;
puttok__FUc ( (unsigned char )44 ) ;
print__4exprFv ( __0this -> __O4__4expr.mem ) ;
break ;
case 2 :
# 104 "/home/claude/cfront-3/src/print.cpp"
if (is_ptr_or_ref__4typeFv ( __0this -> __O4__4expr.mem -> __O1__4expr.tp ) == 0 ){ 
# 105 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O4__4expr.mem ) ;
puttok__FUc ( (unsigned char )45 ) ;
( fputc ( (int )'O' , out_file ) , fputs ( __0this -> __O3__4expr.string2 , out_file ) ) ;
}
else { 
# 110 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )'(' , out_file ) ;
fputc ( (int )'&' , out_file ) ;
fputc ( (int )'(' , out_file ) ;
if (__0this -> __O4__4expr.mem )Eprint__FP4expr ( __0this -> __O4__4expr.mem ) ;
puttok__FUc ( (unsigned char )44 ) ;
( fputc ( (int )'O' , out_file ) , fputs ( __0this -> __O3__4expr.string2 , out_file ) ) ;
fputc ( (int )')' , out_file ) ;
fputc ( (int )')' , out_file ) ;
}
break ;
case 5 :
# 121 "/home/claude/cfront-3/src/print.cpp"
__3not_allocated = 1 ;

# 123 "/home/claude/cfront-3/src/print.cpp"
case 3 :
# 124 "/home/claude/cfront-3/src/print.cpp"
if (is_ptr_or_ref__4typeFv ( __0this -> __O4__4expr.mem -> __O1__4expr.tp ) == 0 ){ 
# 125 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )'(' , out_file ) ;
fputc ( (int )'*' , out_file ) ;
fputc ( (int )'(' , out_file ) ;
if (__0this -> __O4__4expr.mem )Eprint__FP4expr ( __0this -> __O4__4expr.mem ) ;
puttok__FUc ( (unsigned char )45 ) ;
( fputc ( (int )'P' , out_file ) , fputs ( __0this -> __O3__4expr.string2 , out_file ) ) ;
fputc ( (int )')' , out_file ) ;
fputc ( (int )')' , out_file ) ;
}
else { 
# 135 "/home/claude/cfront-3/src/print.cpp"
TOK __5m ;

# 135 "/home/claude/cfront-3/src/print.cpp"
__5m = __0this -> __O4__4expr.mem -> base__4node ;
if ((__5m == 112 )|| (__5m == 145 )){ 
# 137 "/home/claude/cfront-3/src/print.cpp"
if ((__0this -> __O4__4expr.mem -> __O3__4expr.e2 -> base__4node == 111 )&& (! __0this -> __O4__4expr.mem ->
# 137 "/home/claude/cfront-3/src/print.cpp"
__O3__4expr.e2 -> __O3__4expr.e2 ))
# 138 "/home/claude/cfront-3/src/print.cpp"
__5m = __0this -> __O4__4expr.mem -> __O3__4expr.e2 -> __O2__4expr.e1 -> base__4node ;
}
if (__3not_allocated ){ 
# 141 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )'(' , out_file ) ;
print__4exprFv ( __0this -> __O4__4expr.mem ) ;
if (((__5m == 85 )|| (__5m == 169 ))|| (__5m == 44 ))
# 144 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )44 ) ;
else 
# 146 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )45 ) ;
( fputc ( (int )'O' , out_file ) , fputs ( (const char *)__0this -> __O1__4expr.string4 , out_file ) ) ;
# 147 "/home/claude/cfront-3/src/print.cpp"

# 148 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )')' , out_file ) ;
}
else 
# 151 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O4__4expr.mem )Eprint__FP4expr ( __0this -> __O4__4expr.mem ) ;
if ((((__5m == 85 )|| (__5m == 169 ))|| (__5m == 44 ))&& __3not_allocated )
# 153 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )45 ) ;
else 
# 155 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )44 ) ;
( fputc ( (int )'P' , out_file ) , fputs ( __0this -> __O3__4expr.string2 , out_file ) ) ;
}
break ;
case 9 :
# 161 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O4__4expr.mem )Eprint__FP4expr ( __0this -> __O4__4expr.mem ) ;
fputc ( (int )'.' , out_file ) ;
fputs ( __0this -> __O3__4expr.string2 , out_file ) ;
}
break ;
}

# 168 "/home/claude/cfront-3/src/print.cpp"
case 85 :
# 169 "/home/claude/cfront-3/src/print.cpp"
{ Pname __3n ;

# 169 "/home/claude/cfront-3/src/print.cpp"
__3n = (((struct name *)(((struct name *)__0this ))));
if (__3n -> n_evaluated__4name && (__3n -> n_scope__4name != 136 )){ 
# 171 "/home/claude/cfront-3/src/print.cpp"
Ptype __4t ;

# 171 "/home/claude/cfront-3/src/print.cpp"
__4t = skiptypedefs__4typeFv ( __0this -> __O1__4expr.tp ) ;
if (__4t -> base__4node == 121 )
# 173 "/home/claude/cfront-3/src/print.cpp"
__4t = (struct type *)(((struct enumdef *)(((struct enumdef *)(((struct basetype *)(((struct basetype *)__4t ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> e_type__7enumdef ;
if ((__4t -> base__4node != 21 )|| is_unsigned__4typeFv ( __4t ) ){ 
# 175 "/home/claude/cfront-3/src/print.cpp"
fputs ( (const char *)"((",
# 175 "/home/claude/cfront-3/src/print.cpp"
out_file ) ;
{ bit __5oc ;

# 176 "/home/claude/cfront-3/src/print.cpp"
__5oc = Cast ;
Cast = 1 ;
print__4typeFv ( __4t ) ;
Cast = __5oc ;
fprintf ( out_file , (const char *)")%lld)", __3n -> n_val__4name ) ;

# 180 "/home/claude/cfront-3/src/print.cpp"
}
}
else 
# 183 "/home/claude/cfront-3/src/print.cpp"
fprintf ( out_file , (const char *)"%lld", __3n -> n_val__4name ) ;
}
else 
# 186 "/home/claude/cfront-3/src/print.cpp"
print__4nameFUc ( __3n , (unsigned char )0 ) ;
break ;
}

# 190 "/home/claude/cfront-3/src/print.cpp"
case 169 :
# 191 "/home/claude/cfront-3/src/print.cpp"
if (curr_icall ){ 
# 192 "/home/claude/cfront-3/src/print.cpp"
Pname __3n ;
int __3argno ;

# 195 "/home/claude/cfront-3/src/print.cpp"
Pin __3il ;

# 192 "/home/claude/cfront-3/src/print.cpp"
__3n = (((struct name *)(((struct name *)__0this ))));
__3argno = __3n -> argno__4name ;

# 195 "/home/claude/cfront-3/src/print.cpp"
__3il = curr_icall ;
for(;__3il ;__3il = __3il -> i_next__5iline ) 
# 197 "/home/claude/cfront-3/src/print.cpp"
if (__3n -> __O4__4expr.n_table == __3il -> i_table__5iline )
# 198 "/home/claude/cfront-3/src/print.cpp"
goto aok ;
goto bok ;
aok :
# 201 "/home/claude/cfront-3/src/print.cpp"
if (__3n = (__3il -> i_args__5iline [__3argno ]). local__2ia ){ 
# 202 "/home/claude/cfront-3/src/print.cpp"
print__4nameFUc ( __3n , (unsigned char )0 ) ;
}
else { 
# 205 "/home/claude/cfront-3/src/print.cpp"
Pexpr __4ee ;
Ptype __4t ;

# 205 "/home/claude/cfront-3/src/print.cpp"
__4ee = (__3il -> i_args__5iline [__3argno ]). arg__2ia ;
__4t = (__3il -> i_args__5iline [__3argno ]). tp__2ia ;
if ((__4ee == 0 )|| (__4ee == __0this ))
# 208 "/home/claude/cfront-3/src/print.cpp"
{ 
# 208 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V22 ;

# 208 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V23 ;

# 208 "/home/claude/cfront-3/src/print.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%p->E::print(A %p)", (const struct ea *)( ((&
# 208 "/home/claude/cfront-3/src/print.cpp"
__0__V22 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V22 )) , (const struct ea *)( ((& __0__V23 )-> __O1__2ea.p =
# 208 "/home/claude/cfront-3/src/print.cpp"
((const void *)__4ee )), (& __0__V23 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if ((__4ee -> __O1__4expr.tp == 0 )|| (((__4t != __4ee -> __O1__4expr.tp )&& check__4typeFP4typeUcT2 ( __4t , __4ee -> __O1__4expr.tp , (unsigned char
# 209 "/home/claude/cfront-3/src/print.cpp"
)0 , (unsigned char )0 ) )&& (is_cl_obj__4typeFv ( __4t ) == 0 )))
# 219 "/home/claude/cfront-3/src/print.cpp"
{ 
# 220 "/home/claude/cfront-3/src/print.cpp"
fputs ( (const char *)"((",
# 220 "/home/claude/cfront-3/src/print.cpp"
out_file ) ;
{ bit __5oc ;

# 221 "/home/claude/cfront-3/src/print.cpp"
__5oc = Cast ;
Cast = 1 ;
print__4typeFv ( __4t ) ;
Cast = __5oc ;
fputc ( (int )')' , out_file ) ;
if (__4ee )Eprint__FP4expr ( __4ee ) ;
fputc ( (int )')' , out_file ) ;

# 227 "/home/claude/cfront-3/src/print.cpp"
}
}
else 
# 230 "/home/claude/cfront-3/src/print.cpp"
if (__4ee )Eprint__FP4expr ( __4ee ) ;
}
}
else { 
# 234 "/home/claude/cfront-3/src/print.cpp"
bok :
# 235 "/home/claude/cfront-3/src/print.cpp"
print__4nameFUc ( ((struct name *)(((struct name *)__0this ))), (unsigned char )0 ) ;
}
break ;

# 239 "/home/claude/cfront-3/src/print.cpp"
case 168 :
# 240 "/home/claude/cfront-3/src/print.cpp"
{ 
# 241 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O4__4expr.il == 0 )
# 242 "/home/claude/cfront-3/src/print.cpp"
error__FiPCc ( (int )'i' , (const char *)"E::print: iline missing")
# 242 "/home/claude/cfront-3/src/print.cpp"
;
__0this -> __O4__4expr.il -> i_next__5iline = curr_icall ;
curr_icall = __0this -> __O4__4expr.il ;

# 247 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;
if (__0this -> __O3__4expr.e2 ){ 
# 249 "/home/claude/cfront-3/src/print.cpp"
ssize_t __4save ;

# 249 "/home/claude/cfront-3/src/print.cpp"
__4save = curr_lab ;
curr_lab = (++ lab_cnt );
print__4stmtFv ( ((struct stmt *)(((struct stmt *)__0this -> __O3__4expr.e2 )))) ;
curr_lab = __4save ;
}
curr_icall = __0this -> __O4__4expr.il -> i_next__5iline ;
break ;
}

# 258 "/home/claude/cfront-3/src/print.cpp"
case 44 :
# 259 "/home/claude/cfront-3/src/print.cpp"
case 45 :
# 260 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;
puttok__FUc ( __0this -> base__4node ) ;
if (__0this -> __O4__4expr.mem == 0 ){ 
# 263 "/home/claude/cfront-3/src/print.cpp"
fprintf ( out_file , (const char *)"MEM0") ;
# 263 "/home/claude/cfront-3/src/print.cpp"

# 264 "/home/claude/cfront-3/src/print.cpp"
break ;
}
if (__0this -> __O4__4expr.mem -> base__4node == 85 )
# 267 "/home/claude/cfront-3/src/print.cpp"
print__4nameFUc ( ((struct name *)(((struct name *)__0this -> __O4__4expr.mem ))), (unsigned char )0 ) ;
else 
# 269 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O4__4expr.mem ) ;
break ;

# 272 "/home/claude/cfront-3/src/print.cpp"
case 173 :
# 273 "/home/claude/cfront-3/src/print.cpp"
error__FPCc ( (const char *)"P toMF not called") ;
break ;

# 276 "/home/claude/cfront-3/src/print.cpp"
case 157 :
# 277 "/home/claude/cfront-3/src/print.cpp"
print__4typeFv ( __0this -> __O4__4expr.tp2 ) ;
puttok__FUc ( (unsigned char )40 ) ;
if (__0this -> __O2__4expr.e1 )
# 280 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O2__4expr.e1 ) ;
puttok__FUc ( (unsigned char )41 ) ;
break ;

# 284 "/home/claude/cfront-3/src/print.cpp"
case 30 :
# 285 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )30 ) ;
if (((__0this -> __O2__4expr.e1 && (__0this -> __O2__4expr.e1 != dummy ))&& (__0this -> __O2__4expr.e1 -> base__4node != 124 ))&& (((__0this -> __O2__4expr.e1 -> base__4node != 113 )&&
# 286 "/home/claude/cfront-3/src/print.cpp"
(__0this -> __O2__4expr.e1 -> base__4node != 191 ))|| (__0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> base__4node != 124 ))){ 
# 287 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 )
# 287 "/home/claude/cfront-3/src/print.cpp"
;
}
else if (__0this -> __O4__4expr.tp2 ){ 
# 290 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )'(' , out_file ) ;
if (__0this -> __O4__4expr.tp2 -> base__4node == 6 ){ 
# 292 "/home/claude/cfront-3/src/print.cpp"
Pclass __4cl ;

# 292 "/home/claude/cfront-3/src/print.cpp"
__4cl = (((struct classdef *)(((struct classdef *)__0this -> __O4__4expr.tp2 ))));
fputs ( (const char *)((__4cl -> csu__8classdef == 36 )?"union ":(((char *)"struct "))),
# 293 "/home/claude/cfront-3/src/print.cpp"
out_file ) ;
{ char *__4str ;

# 294 "/home/claude/cfront-3/src/print.cpp"
__4str = 0 ;

# 296 "/home/claude/cfront-3/src/print.cpp"
if (__4cl -> lex_level__4type && (__4cl -> nested_sig__4type == 0 ))
# 297 "/home/claude/cfront-3/src/print.cpp"
__4str = __4cl -> local_sig__4type ;

# 299 "/home/claude/cfront-3/src/print.cpp"
if (__4str )
# 300 "/home/claude/cfront-3/src/print.cpp"
fputs ( (const char *)__4str , out_file ) ;
else if (__4cl -> nested_sig__4type )
# 302 "/home/claude/cfront-3/src/print.cpp"
fprintf ( out_file , (const char *)"__%s", __4cl -> nested_sig__4type )
# 302 "/home/claude/cfront-3/src/print.cpp"
;
else fputs ( __4cl -> string__8classdef , out_file ) ;

# 303 "/home/claude/cfront-3/src/print.cpp"
}
}
else 
# 306 "/home/claude/cfront-3/src/print.cpp"
print__4typeFv ( __0this -> __O4__4expr.tp2 ) ;
fputc ( (int )')' , out_file ) ;
}
else { 
# 310 "/home/claude/cfront-3/src/print.cpp"
error__FiPCc ( (int )'i' , (const char *)"missingE for sizeof") ;
}
break ;

# 314 "/home/claude/cfront-3/src/print.cpp"
case 113 :
# 315 "/home/claude/cfront-3/src/print.cpp"
case 191 :
# 316 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O2__4expr.e1 -> base__4node == 124 ){ 
# 317 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;
break ;
}
fputc ( (int )'(' , out_file ) ;

# 322 "/home/claude/cfront-3/src/print.cpp"
if (((__0this -> __O4__4expr.tp2 != (((struct type *)mptr_type )))&& ((__0this -> __O4__4expr.tp2 -> base__4node != 38 )|| ansi_opt ))&& (memptr__4typeFv ( __0this -> __O4__4expr.tp2 ) ==
# 322 "/home/claude/cfront-3/src/print.cpp"
0 )){ 
# 325 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )'(' , out_file ) ;
{ bit __3oc ;

# 326 "/home/claude/cfront-3/src/print.cpp"
__3oc = Cast ;
Cast = 1 ;
if ((__0this -> __O4__4expr.tp2 -> base__4node == 97 )|| (__0this -> __O4__4expr.tp2 -> base__4node == 110 ))
# 329 "/home/claude/cfront-3/src/print.cpp"
TCast = 1 ;
else TCast = 0 ;
print__4typeFv ( __0this -> __O4__4expr.tp2 ) ;
TCast = 0 ;
Cast = __3oc ;
fputc ( (int )')' , out_file ) ;

# 334 "/home/claude/cfront-3/src/print.cpp"
}
}
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;
fputc ( (int )')' , out_file ) ;
break ;

# 340 "/home/claude/cfront-3/src/print.cpp"
case 82 :
# 341 "/home/claude/cfront-3/src/print.cpp"
case 83 :
# 342 "/home/claude/cfront-3/src/print.cpp"
case 84 :
# 343 "/home/claude/cfront-3/src/print.cpp"
case 80 :
# 344 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O2__4expr.string )
# 345 "/home/claude/cfront-3/src/print.cpp"
( fputs ( __0this -> __O2__4expr.string , out_file ) , fputc ( (int
# 345 "/home/claude/cfront-3/src/print.cpp"
)' ' , out_file ) ) ;
break ;

# 348 "/home/claude/cfront-3/src/print.cpp"
case 81 :
# 350 "/home/claude/cfront-3/src/print.cpp"
ntok += 4 ;
fprintf ( out_file , (const char *)"\"%s\"", __0this -> __O2__4expr.string ) ;
break ;

# 354 "/home/claude/cfront-3/src/print.cpp"
case 34 :
# 355 "/home/claude/cfront-3/src/print.cpp"
case 86 :
# 356 "/home/claude/cfront-3/src/print.cpp"
fputs ( (const char *)"0 ", out_file ) ;
break ;

# 359 "/home/claude/cfront-3/src/print.cpp"
case 150 :
# 360 "/home/claude/cfront-3/src/print.cpp"
fprintf ( out_file , (const char *)"%lld", __0this -> __O2__4expr.i1 ) ;
break ;

# 363 "/home/claude/cfront-3/src/print.cpp"
case 165 :
# 364 "/home/claude/cfront-3/src/print.cpp"
{ 
# 365 "/home/claude/cfront-3/src/print.cpp"
int __3oo ;

# 365 "/home/claude/cfront-3/src/print.cpp"
__3oo = vtbl_opt ;
vtbl_opt = -1;
{ char *__3s ;

# 367 "/home/claude/cfront-3/src/print.cpp"
__3s = vtbl_name__FPCcT1 ( __0this -> __O2__4expr.string , __0this -> __O3__4expr.string2 ) ;
vtbl_opt = __3oo ;
(__3s [2 ])= 'p' ;
{ char *__3t ;

# 370 "/home/claude/cfront-3/src/print.cpp"
__3t = ptbl_lookup__FPCc ( (const char *)__3s ) ;
fprintf ( out_file , (const char *)" %s", __3t ) ;
__dl__FPv ( (void *)__3t ) ;

# 374 "/home/claude/cfront-3/src/print.cpp"
{ char *__3str ;

# 374 "/home/claude/cfront-3/src/print.cpp"
__3str = 0 ;
if (__0this -> __O2__4expr.string ){ 
# 376 "/home/claude/cfront-3/src/print.cpp"
__3str = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* ((strlen ( __0this -> __O2__4expr.string )
# 376 "/home/claude/cfront-3/src/print.cpp"
+ strlen ( __0this -> __O3__4expr.string2 ) )+ 1 ))) ));
strcpy ( __3str , __0this -> __O2__4expr.string ) ;
strcat ( __3str , __0this -> __O3__4expr.string2 ) ;
}

# 381 "/home/claude/cfront-3/src/print.cpp"
if ((look__5tableFPCcUc ( ptbl , __3str ?(((const char *)__3str )):__0this -> __O3__4expr.string2 , (unsigned char )0 ) == 0 )&& (look__5tableFPCcUc ( ptbl ,
# 381 "/home/claude/cfront-3/src/print.cpp"
__3str ?(((const char *)__3str )):__0this -> __O3__4expr.string2 , (unsigned char )159 ) == 0 ))
# 385 "/home/claude/cfront-3/src/print.cpp"
{ 
# 386 "/home/claude/cfront-3/src/print.cpp"
Pname __4nn ;
char *__4str ;

# 386 "/home/claude/cfront-3/src/print.cpp"
__4nn = insert__5tableFP4nameUc ( ptbl , __ct__4nameFPCc ( (struct name *)0 , __3str ?(((const char *)__3str )):__0this -> __O3__4expr.string2 ) , (unsigned char )0 )
# 386 "/home/claude/cfront-3/src/print.cpp"
;
__4str = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( (const char *)__3s ) + 1 )))
# 387 "/home/claude/cfront-3/src/print.cpp"
));
strcpy ( __4str , (const char *)__3s ) ;

# 390 "/home/claude/cfront-3/src/print.cpp"
__4nn -> __O3__4expr.string2 = (const char *)__4str ;
}

# 393 "/home/claude/cfront-3/src/print.cpp"
__dl__FPv ( (void *)__3str ) ;
__dl__FPv ( (void *)__3s ) ;

# 394 "/home/claude/cfront-3/src/print.cpp"
}

# 394 "/home/claude/cfront-3/src/print.cpp"
}

# 394 "/home/claude/cfront-3/src/print.cpp"
}
}
break ;

# 398 "/home/claude/cfront-3/src/print.cpp"
case 162 :
# 399 "/home/claude/cfront-3/src/print.cpp"
error__FiPCc ( (int )'i' , (const char *)"T destructor in expr::print()") ;
case 144 :
# 401 "/home/claude/cfront-3/src/print.cpp"
break ;

# 403 "/home/claude/cfront-3/src/print.cpp"
case 146 :
# 404 "/home/claude/cfront-3/src/print.cpp"
case 109 :
# 405 "/home/claude/cfront-3/src/print.cpp"
{ Pname __3fn ;
Pname __3at ;
int __3m_ptr ;
int __3comflag ;

# 405 "/home/claude/cfront-3/src/print.cpp"
__3fn = __0this -> __O4__4expr.fct_name ;

# 407 "/home/claude/cfront-3/src/print.cpp"
__3m_ptr = 0 ;
__3comflag = 0 ;

# 410 "/home/claude/cfront-3/src/print.cpp"
if (__3fn ){ 
# 411 "/home/claude/cfront-3/src/print.cpp"
Pfct __4f ;

# 411 "/home/claude/cfront-3/src/print.cpp"
__4f = (((struct fct *)(((struct fct *)__3fn -> __O1__4expr.tp ))));

# 413 "/home/claude/cfront-3/src/print.cpp"
if (__4f -> base__4node == 76 ){ 
# 414 "/home/claude/cfront-3/src/print.cpp"
__0this -> __O4__4expr.fct_name = (__3fn = (((struct gen *)(((struct gen *)__4f ))))-> fct_list__3gen -> f__9name_list );
__4f = (((struct fct *)(((struct fct *)__3fn -> __O1__4expr.tp ))));
}

# 418 "/home/claude/cfront-3/src/print.cpp"
if ((__0this -> __O2__4expr.e1 -> base__4node == 71 )|| (__0this -> __O2__4expr.e1 -> base__4node == 147 )){ 
# 419 "/home/claude/cfront-3/src/print.cpp"
__3comflag = 1 ;
puttok__FUc ( (unsigned char )40 ) ;
print__4exprFv ( __0this -> __O2__4expr.e1 -> __O2__4expr.e1 ) ;
puttok__FUc ( (unsigned char )71 ) ;
}
print__4nameFUc ( __3fn , (unsigned char )0 ) ;
__3at = __4f -> f_args__3fct ;
}
else { 
# 428 "/home/claude/cfront-3/src/print.cpp"
Pfct __4f ;

# 428 "/home/claude/cfront-3/src/print.cpp"
__4f = (((struct fct *)(((struct fct *)__0this -> __O2__4expr.e1 -> __O1__4expr.tp ))));

# 430 "/home/claude/cfront-3/src/print.cpp"
if (__4f ){ 
# 431 "/home/claude/cfront-3/src/print.cpp"
Pexpr __5exex ;

# 431 "/home/claude/cfront-3/src/print.cpp"
__5exex = __0this -> __O2__4expr.e1 ;
if (__5exex -> base__4node == 111 ){ 
# 433 "/home/claude/cfront-3/src/print.cpp"
__5exex = __5exex -> __O2__4expr.e1 ;
while ((__5exex -> base__4node == 113 )|| (__5exex -> base__4node == 191 ))
# 436 "/home/claude/cfront-3/src/print.cpp"
__5exex = __5exex -> __O2__4expr.e1 ;
if (__5exex -> base__4node == 177 )
# 438 "/home/claude/cfront-3/src/print.cpp"
__3m_ptr = 1 ;
}

# 441 "/home/claude/cfront-3/src/print.cpp"
if (__4f -> base__4node == 76 ){ 
# 442 "/home/claude/cfront-3/src/print.cpp"
__0this -> __O4__4expr.fct_name = (__3fn = (((struct gen *)(((struct gen *)__4f ))))-> fct_list__3gen -> f__9name_list );
__4f = (((struct fct *)(((struct fct *)__3fn -> __O1__4expr.tp ))));
}

# 446 "/home/claude/cfront-3/src/print.cpp"
__4f = (((struct fct *)(((struct fct *)skiptypedefs__4typeFv ( (struct type *)__4f ) ))));
if (__4f -> base__4node == 125 ){ 
# 448 "/home/claude/cfront-3/src/print.cpp"
fputs ( (const char *)"(*(", out_file ) ;
# 448 "/home/claude/cfront-3/src/print.cpp"

# 449 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O2__4expr.e1 ) ;
fputs ( (const char *)"))", out_file ) ;
__4f = (((struct fct *)(((struct fct *)skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__4f ))))-> typ__5pvtyp ) ))));
}
else 
# 454 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;

# 456 "/home/claude/cfront-3/src/print.cpp"
__3at = __4f -> f_args__3fct ;
}
else { 
# 460 "/home/claude/cfront-3/src/print.cpp"
__3at = ((__0this -> __O2__4expr.e1 -> base__4node == 68 )?(((struct name *)(((struct name *)__0this -> __O2__4expr.e1 -> __O2__4expr.e1 -> __O4__4expr.tp2 )))):(((struct name *)(((struct name *)__0this ->
# 460 "/home/claude/cfront-3/src/print.cpp"
__O2__4expr.e1 -> __O4__4expr.tp2 )))));
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;
}
}

# 465 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )40 ) ;

# 467 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 ){ 
# 468 "/home/claude/cfront-3/src/print.cpp"
if (__3at ){ 
# 469 "/home/claude/cfront-3/src/print.cpp"
Pexpr __5e ;

# 469 "/home/claude/cfront-3/src/print.cpp"
__5e = __0this -> __O3__4expr.e2 ;
while (__3at ){ 
# 471 "/home/claude/cfront-3/src/print.cpp"
Pexpr __6ex ;
Ptype __6t ;

# 472 "/home/claude/cfront-3/src/print.cpp"
__6t = __3at -> __O1__4expr.tp ;

# 474 "/home/claude/cfront-3/src/print.cpp"
if (__6t == 0 )
# 475 "/home/claude/cfront-3/src/print.cpp"
{ 
# 475 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V24 ;

# 475 "/home/claude/cfront-3/src/print.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"T ofA missing for%n", (const struct ea *)( ((&
# 475 "/home/claude/cfront-3/src/print.cpp"
__0__V24 )-> __O1__2ea.p = ((const void *)__3fn )), (& __0__V24 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 475 "/home/claude/cfront-3/src/print.cpp"
(const struct ea *)ea0 ) ;
} if (__5e == 0 )
# 477 "/home/claude/cfront-3/src/print.cpp"
{ 
# 477 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V25 ;

# 477 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V26 ;

# 477 "/home/claude/cfront-3/src/print.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%tA missing for%n", (const struct ea *)( ((&
# 477 "/home/claude/cfront-3/src/print.cpp"
__0__V25 )-> __O1__2ea.p = ((const void *)__6t )), (& __0__V25 )) , (const struct ea *)( ((& __0__V26 )-> __O1__2ea.p =
# 477 "/home/claude/cfront-3/src/print.cpp"
((const void *)__3fn )), (& __0__V26 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__5e -> base__4node == 140 ){ 
# 479 "/home/claude/cfront-3/src/print.cpp"
__6ex = __5e -> __O2__4expr.e1 ;
__5e = __5e -> __O3__4expr.e2 ;
}
else 
# 483 "/home/claude/cfront-3/src/print.cpp"
__6ex = __5e ;

# 485 "/home/claude/cfront-3/src/print.cpp"
if (__6ex == 0 )
# 486 "/home/claude/cfront-3/src/print.cpp"
{ 
# 486 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V27 ;

# 486 "/home/claude/cfront-3/src/print.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"A ofT%t missing", (const struct ea *)( ((&
# 486 "/home/claude/cfront-3/src/print.cpp"
__0__V27 )-> __O1__2ea.p = ((const void *)__6t )), (& __0__V27 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 486 "/home/claude/cfront-3/src/print.cpp"
(const struct ea *)ea0 ) ;
} if (((((((__6t != __6ex -> __O1__4expr.tp )&& __6ex -> __O1__4expr.tp )&& check__4typeFP4typeUcT2 ( __6t , __6ex -> __O1__4expr.tp , (unsigned char )0 ,
# 487 "/home/claude/cfront-3/src/print.cpp"
(unsigned char )0 ) )&& (is_cl_obj__4typeFv ( __6t ) == 0 ))&& (eobj == 0 ))&& (__3m_ptr == 0 ))&& ((is_ptr__4typeFv ( __6t )
# 487 "/home/claude/cfront-3/src/print.cpp"
== 0 )|| (Mptr == 0 )))
# 505 "/home/claude/cfront-3/src/print.cpp"
{ 
# 506 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )'(' , out_file ) ;
{ bit __7oc ;

# 507 "/home/claude/cfront-3/src/print.cpp"
__7oc = Cast ;
Cast = 1 ;
print__4typeFv ( __6t ) ;
Cast = __7oc ;
fputc ( (int )')' , out_file ) ;

# 520 "/home/claude/cfront-3/src/print.cpp"
if ((is_cl_obj__4typeFv ( __6ex -> __O1__4expr.tp ) && (((__6ex -> base__4node != 85 )&& (__6ex -> base__4node != 169 ))|| ((((struct name *)(((struct name *)__6ex ))))->
# 520 "/home/claude/cfront-3/src/print.cpp"
n_xref__4name == 0 )))&& (is_ptr__4typeFv ( __6t ) || is_ref__4typeFv ( __6t ) ))
# 522 "/home/claude/cfront-3/src/print.cpp"
{ 
# 527 "/home/claude/cfront-3/src/print.cpp"
__6ex = address__4exprFv ( __6ex ) ;
}
if (__6ex )Eprint__FP4expr ( __6ex ) ;

# 529 "/home/claude/cfront-3/src/print.cpp"
}

# 533 "/home/claude/cfront-3/src/print.cpp"
}
else 
# 535 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __6ex ) ;

# 539 "/home/claude/cfront-3/src/print.cpp"
if (__3m_ptr ){ 
# 540 "/home/claude/cfront-3/src/print.cpp"
__3m_ptr = 0 ;
if (__3at )
# 542 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )71 ) ;
continue ;
}

# 546 "/home/claude/cfront-3/src/print.cpp"
__3at = __3at -> __O1__4name.n_list ;
if (__3at )
# 548 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )71 ) ;
}
if (__5e ){ 
# 551 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )71 ) ;
print__4exprFv ( __5e ) ;
}
}
else 
# 556 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O3__4expr.e2 ) ;
}
puttok__FUc ( (unsigned char )41 ) ;
if (__3comflag )
# 560 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )41 ) ;
break ;
}

# 564 "/home/claude/cfront-3/src/print.cpp"
case 70 :
# 565 "/home/claude/cfront-3/src/print.cpp"
if ((__0this -> __O2__4expr.e1 -> base__4node == 169 )&& ((((struct name *)(((struct name *)__0this -> __O2__4expr.e1 ))))-> n_assigned_to__4name == 11111 ))
# 569 "/home/claude/cfront-3/src/print.cpp"
{ 
# 571 "/home/claude/cfront-3/src/print.cpp"
Pname __3n ;
int __3argno ;
Pin __3il ;

# 571 "/home/claude/cfront-3/src/print.cpp"
__3n = (((struct name *)(((struct name *)__0this -> __O2__4expr.e1 ))));
__3argno = (((int )__3n -> n_val__4name ));
__3il = curr_icall ;
for(;__3il ;__3il = __3il -> i_next__5iline ) 
# 575 "/home/claude/cfront-3/src/print.cpp"
if (__3il -> i_table__5iline == __3n -> __O4__4expr.n_table )
# 576 "/home/claude/cfront-3/src/print.cpp"
goto akk ;
goto bkk ;
akk :
# 579 "/home/claude/cfront-3/src/print.cpp"
if ((__3il -> i_args__5iline [__3argno ]). local__2ia == 0 ){ 
# 580 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O3__4expr.e2 ) ;
break ;
}
}

# 585 "/home/claude/cfront-3/src/print.cpp"
case 62 :
# 586 "/home/claude/cfront-3/src/print.cpp"
case 63 :
# 587 "/home/claude/cfront-3/src/print.cpp"
case 60 :
# 588 "/home/claude/cfront-3/src/print.cpp"
case 61 :
# 589 "/home/claude/cfront-3/src/print.cpp"
case 59 :
# 590 "/home/claude/cfront-3/src/print.cpp"
case 58 :
# 591 "/home/claude/cfront-3/src/print.cpp"
bkk :
# 592 "/home/claude/cfront-3/src/print.cpp"
{ 
# 594 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;
puttok__FUc ( __0this -> base__4node ) ;

# 597 "/home/claude/cfront-3/src/print.cpp"
if ((__0this -> __O2__4expr.e1 -> __O1__4expr.tp && (__0this -> __O2__4expr.e1 -> __O1__4expr.tp != __0this -> __O3__4expr.e2 -> __O1__4expr.tp ))&& (__0this -> __O3__4expr.e2 -> base__4node != 86 ))
# 603 "/home/claude/cfront-3/src/print.cpp"
{
# 603 "/home/claude/cfront-3/src/print.cpp"

# 604 "/home/claude/cfront-3/src/print.cpp"
Ptype __4t1 ;

# 604 "/home/claude/cfront-3/src/print.cpp"
__4t1 = skiptypedefs__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) ;
switch (__4t1 -> base__4node ){ 
# 606 "/home/claude/cfront-3/src/print.cpp"
default :
# 607 "/home/claude/cfront-3/src/print.cpp"
break ;
case 125 :
# 609 "/home/claude/cfront-3/src/print.cpp"
case 158 :
# 610 "/home/claude/cfront-3/src/print.cpp"
case 110 :
# 611 "/home/claude/cfront-3/src/print.cpp"
{ 
# 612 "/home/claude/cfront-3/src/print.cpp"
Ptype __6t2 ;

# 612 "/home/claude/cfront-3/src/print.cpp"
__6t2 = (__0this -> __O3__4expr.e2 -> __O1__4expr.tp ?skiptypedefs__4typeFv ( __0this -> __O3__4expr.e2 -> __O1__4expr.tp ) :(((struct type *)0 )));

# 614 "/home/claude/cfront-3/src/print.cpp"
if (((__0this -> __O3__4expr.e2 -> __O1__4expr.tp == 0 )|| (((((! ansi_opt )&& (((struct ptr *)(((struct ptr *)__4t1 ))))-> typ__5pvtyp )&& (skiptypedefs__4typeFv ( (((struct ptr *)(((struct
# 614 "/home/claude/cfront-3/src/print.cpp"
ptr *)__4t1 ))))-> typ__5pvtyp ) -> base__4node == 110 ))&& (__0this -> __O3__4expr.e2 -> base__4node != 191 ))&& (__0this -> __O3__4expr.e2 -> base__4node != 113 )))|| ((((((struct
# 614 "/home/claude/cfront-3/src/print.cpp"
ptr *)(((struct ptr *)__4t1 ))))-> typ__5pvtyp != (((struct ptr *)(((struct ptr *)__6t2 ))))-> typ__5pvtyp )&& check__4typeFP4typeUcT2 ( __4t1 , __6t2 , (unsigned char )0 , (unsigned
# 614 "/home/claude/cfront-3/src/print.cpp"
char )0 ) )&& (((memptr__4typeFv ( __4t1 ) == 0 )|| (memptr__4typeFv ( __6t2 ) == 0 ))|| check__4typeFP4typeUcT2 ( __4t1 , __6t2 ,
# 614 "/home/claude/cfront-3/src/print.cpp"
(unsigned char )78 , (unsigned char )0 ) )))
# 640 "/home/claude/cfront-3/src/print.cpp"
{ 
# 641 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )'(' , out_file ) ;
{ bit __7oc ;

# 642 "/home/claude/cfront-3/src/print.cpp"
__7oc = Cast ;
Cast = 1 ;
print__4typeFv ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp ) ;
Cast = __7oc ;
fputc ( (int )')' , out_file ) ;

# 646 "/home/claude/cfront-3/src/print.cpp"
}
}
}
}
}

# 652 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
break ;
}

# 656 "/home/claude/cfront-3/src/print.cpp"
case 111 :
# 657 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 ){ 
# 658 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;
fputc ( (int )'[' , out_file ) ;
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
fputc ( (int )']' , out_file ) ;
}
else { 
# 664 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )'(' , out_file ) ;
fputc ( (int )'*' , out_file ) ;
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;
fputc ( (int )')' , out_file ) ;
}
break ;

# 671 "/home/claude/cfront-3/src/print.cpp"
case 124 :{ 
# 672 "/home/claude/cfront-3/src/print.cpp"
static int __3level = 0 ;
__3level ++ ;
{ bit __3flag ;

# 674 "/home/claude/cfront-3/src/print.cpp"
__3flag = (((__3level > 1 )&& __0this -> __O1__4expr.tp )&& ((__0this -> __O1__4expr.tp == (((struct type *)zero_type )))|| memptr__4typeFv ( __0this -> __O1__4expr.tp ) ));
if (! __3flag )
# 676 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )73 ) ;
if (__0this -> __O2__4expr.e1 )
# 678 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O2__4expr.e1 ) ;
if (__0this -> __O3__4expr.e2 ){ 
# 680 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )71 ) ;
print__4exprFv ( __0this -> __O3__4expr.e2 ) ;
}
if (! __3flag )
# 684 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )74 ) ;
__3level -- ;
break ;

# 686 "/home/claude/cfront-3/src/print.cpp"
}
}

# 689 "/home/claude/cfront-3/src/print.cpp"
case 140 :
# 690 "/home/claude/cfront-3/src/print.cpp"
{ Pexpr __3e ;

# 690 "/home/claude/cfront-3/src/print.cpp"
__3e = __0this ;
for(;;) { 
# 692 "/home/claude/cfront-3/src/print.cpp"
if (__3e -> base__4node == 140 ){ 
# 693 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __3e -> __O2__4expr.e1 ) ;
if (__3e = __3e -> __O3__4expr.e2 ){ 
# 695 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )71 ) ;
}
else 
# 698 "/home/claude/cfront-3/src/print.cpp"
return ;
}
else { 
# 701 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __3e ) ;
return ;
}
}
}

# 707 "/home/claude/cfront-3/src/print.cpp"
case 68 :
# 708 "/home/claude/cfront-3/src/print.cpp"
{ 
# 709 "/home/claude/cfront-3/src/print.cpp"
Neval = 0 ;
binary_val = 1 ;
{ long long __3i ;

# 711 "/home/claude/cfront-3/src/print.cpp"
__3i = eval__4exprFv ( __0this -> __O4__4expr.cond ) ;
binary_val = 0 ;
if (Neval == 0 )
# 714 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __3i ?__0this -> __O2__4expr.e1 :__0this -> __O3__4expr.e2 ) ;
else { 
# 716 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O4__4expr.cond )Eprint__FP4expr ( __0this -> __O4__4expr.cond ) ;
fputc ( (int )'?' , out_file ) ;
if (! ansi_opt ){ 
# 719 "/home/claude/cfront-3/src/print.cpp"
if ((((__0this -> __O2__4expr.e1 -> base__4node == 113 )|| (__0this -> __O2__4expr.e1 -> base__4node == 191 ))&& __0this -> __O2__4expr.e1 ->
# 719 "/home/claude/cfront-3/src/print.cpp"
__O1__4expr.tp )&& (! check__4typeFP4typeUcT2 ( __0this -> __O2__4expr.e1 -> __O1__4expr.tp , (struct type *)void_type , (unsigned char )0 , (unsigned char )0 )
# 719 "/home/claude/cfront-3/src/print.cpp"
))
# 720 "/home/claude/cfront-3/src/print.cpp"
{ 
# 721 "/home/claude/cfront-3/src/print.cpp"
__0this -> __O2__4expr.e1 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __0this -> __O2__4expr.e1 -> __O2__4expr.e1 , zero ) ;
# 721 "/home/claude/cfront-3/src/print.cpp"

# 722 "/home/claude/cfront-3/src/print.cpp"
__0this -> __O2__4expr.e1 -> __O1__4expr.tp = (struct type *)zero_type ;
}
if ((((__0this -> __O3__4expr.e2 -> base__4node == 113 )|| (__0this -> __O3__4expr.e2 -> base__4node == 191 ))&& __0this -> __O3__4expr.e2 -> __O1__4expr.tp )&& (! check__4typeFP4typeUcT2 (
# 724 "/home/claude/cfront-3/src/print.cpp"
__0this -> __O3__4expr.e2 -> __O1__4expr.tp , (struct type *)void_type , (unsigned char )0 , (unsigned char )0 ) ))
# 725 "/home/claude/cfront-3/src/print.cpp"
{ 
# 726 "/home/claude/cfront-3/src/print.cpp"
__0this -> __O3__4expr.e2 =
# 726 "/home/claude/cfront-3/src/print.cpp"
__ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )147 , __0this -> __O3__4expr.e2 -> __O2__4expr.e1 , zero ) ;
__0this -> __O3__4expr.e2 -> __O1__4expr.tp = (struct type *)zero_type ;
}
}
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;
fputc ( (int )':' , out_file ) ;
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
}
break ;

# 734 "/home/claude/cfront-3/src/print.cpp"
}
}

# 737 "/home/claude/cfront-3/src/print.cpp"
case 71 :
# 738 "/home/claude/cfront-3/src/print.cpp"
case 147 :
# 739 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )40 ) ;
switch (__0this -> __O2__4expr.e1 -> base__4node ){ 
# 741 "/home/claude/cfront-3/src/print.cpp"
case 86 :
# 742 "/home/claude/cfront-3/src/print.cpp"
case 150 :
# 743 "/home/claude/cfront-3/src/print.cpp"
case 82 :
# 744 "/home/claude/cfront-3/src/print.cpp"
case 85 :
# 745 "/home/claude/cfront-3/src/print.cpp"
case 144 :
# 746 "/home/claude/cfront-3/src/print.cpp"
case 177 :
# 747 "/home/claude/cfront-3/src/print.cpp"
case 45 :
# 748 "/home/claude/cfront-3/src/print.cpp"
case 44 :
# 749 "/home/claude/cfront-3/src/print.cpp"
case 83 :
# 750 "/home/claude/cfront-3/src/print.cpp"
case
# 750 "/home/claude/cfront-3/src/print.cpp"
81 :
# 751 "/home/claude/cfront-3/src/print.cpp"
goto le2 ;
case 162 :
# 753 "/home/claude/cfront-3/src/print.cpp"
error__FiPCc ( (int )'i' , (const char *)"T destructor in expr::print()") ;
default :
# 755 "/home/claude/cfront-3/src/print.cpp"
{ 
# 756 "/home/claude/cfront-3/src/print.cpp"
int __4oo ;

# 756 "/home/claude/cfront-3/src/print.cpp"
__4oo = addrof_cm ;
addrof_cm = 0 ;
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this -> __O2__4expr.e1 ) ;
addrof_cm = __4oo ;
}
puttok__FUc ( (unsigned char )71 ) ;
le2 :
# 763 "/home/claude/cfront-3/src/print.cpp"
if (addrof_cm ){ 
# 764 "/home/claude/cfront-3/src/print.cpp"
switch (__0this -> __O3__4expr.e2 -> base__4node ){ 
# 764 "/home/claude/cfront-3/src/print.cpp"
unsigned long __2__X32 ;

# 765 "/home/claude/cfront-3/src/print.cpp"
case 113 :
# 766 "/home/claude/cfront-3/src/print.cpp"
case 191 :
# 767 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 -> __O3__4expr.e2 )
# 768 "/home/claude/cfront-3/src/print.cpp"
switch (__0this -> __O3__4expr.e2 -> __O3__4expr.e2 -> base__4node ){ 
# 769 "/home/claude/cfront-3/src/print.cpp"
case 71 :
# 770 "/home/claude/cfront-3/src/print.cpp"
case 147 :
# 771 "/home/claude/cfront-3/src/print.cpp"
case 168 :goto
# 771 "/home/claude/cfront-3/src/print.cpp"
ec ;
}
case 85 :
# 774 "/home/claude/cfront-3/src/print.cpp"
case 177 :
# 775 "/home/claude/cfront-3/src/print.cpp"
case 45 :
# 776 "/home/claude/cfront-3/src/print.cpp"
case 111 :
# 777 "/home/claude/cfront-3/src/print.cpp"
case 44 :
# 778 "/home/claude/cfront-3/src/print.cpp"
case 169 :
# 779 "/home/claude/cfront-3/src/print.cpp"
if ((__0this -> __O3__4expr.e2 -> base__4node != 112 )&& (__0this -> __O3__4expr.e2 -> base__4node !=
# 779 "/home/claude/cfront-3/src/print.cpp"
145 ))
# 781 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )112 ) ;
addrof_cm -- ;
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
addrof_cm ++ ;
break ;
case 168 :
# 787 "/home/claude/cfront-3/src/print.cpp"
case 71 :
# 788 "/home/claude/cfront-3/src/print.cpp"
case 147 :
# 789 "/home/claude/cfront-3/src/print.cpp"
ec :
# 790 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
break ;
case 146 :
# 794 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 -> __O4__4expr.fct_name && (__0this -> __O3__4expr.e2 -> __O4__4expr.fct_name -> n_oper__4name == 161 )){ 
# 795 "/home/claude/cfront-3/src/print.cpp"
addrof_cm -- ;
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
addrof_cm ++ ;
break ;
}
default :
# 801 "/home/claude/cfront-3/src/print.cpp"
{ 
# 801 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V28 ;

# 801 "/home/claude/cfront-3/src/print.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"& inlineF call (%k)", (const struct ea *)( (__2__X32 =
# 801 "/home/claude/cfront-3/src/print.cpp"
__0this -> __O3__4expr.e2 -> base__4node ), ( (( ((& __0__V28 )-> __O1__2ea.i = __2__X32 ), 0 ) ), (& __0__V28 )) )
# 801 "/home/claude/cfront-3/src/print.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
else 
# 805 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
puttok__FUc ( (unsigned char )41 ) ;
}
break ;

# 810 "/home/claude/cfront-3/src/print.cpp"
case 112 :
# 811 "/home/claude/cfront-3/src/print.cpp"
case 145 :
# 812 "/home/claude/cfront-3/src/print.cpp"
{ 
# 813 "/home/claude/cfront-3/src/print.cpp"
switch (__0this -> __O3__4expr.e2 -> base__4node ){ 
# 814 "/home/claude/cfront-3/src/print.cpp"
case 111 :
# 815 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 -> __O3__4expr.e2 == 0 ){ 
# 816 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv (
# 816 "/home/claude/cfront-3/src/print.cpp"
__0this -> __O3__4expr.e2 -> __O2__4expr.e1 ) ;
return ;
}
break ;
case 168 :
# 821 "/home/claude/cfront-3/src/print.cpp"
addrof_cm ++ ;
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
addrof_cm -- ;
return ;
case 70 :
# 826 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
return ;
case 169 :
# 829 "/home/claude/cfront-3/src/print.cpp"
case 85 :{ 
# 830 "/home/claude/cfront-3/src/print.cpp"
Pname __5n ;

# 830 "/home/claude/cfront-3/src/print.cpp"
__5n = (((struct name *)(((struct name *)__0this -> __O3__4expr.e2 ))));

# 832 "/home/claude/cfront-3/src/print.cpp"
if (__5n -> n_evaluated__4name ){ 
# 833 "/home/claude/cfront-3/src/print.cpp"
__5n -> n_evaluated__4name = 0 ;
if ((__0this -> __O3__4expr.e2 -> base__4node != 112 )&& (__0this -> __O3__4expr.e2 -> base__4node != 145 ))
# 836 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )112 ) ;
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
__5n -> n_evaluated__4name = 1 ;
return ;
}

# 842 "/home/claude/cfront-3/src/print.cpp"
if ((__0this -> __O3__4expr.e2 -> __O1__4expr.tp && is_cl_obj__4typeFv ( __0this -> __O3__4expr.e2 -> __O1__4expr.tp ) )&& __5n -> n_xref__4name )
# 843 "/home/claude/cfront-3/src/print.cpp"
{ 
# 844 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr (
# 844 "/home/claude/cfront-3/src/print.cpp"
__0this -> __O3__4expr.e2 ) ;
return ;
}
if ((! ansi_opt )&& (__0this -> __O3__4expr.e2 -> __O1__4expr.tp && (skiptypedefs__4typeFv ( __0this -> __O3__4expr.e2 -> __O1__4expr.tp ) -> base__4node == 110 )))
# 848 "/home/claude/cfront-3/src/print.cpp"
{ 
# 850 "/home/claude/cfront-3/src/print.cpp"
if
# 850 "/home/claude/cfront-3/src/print.cpp"
(__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
return ;
}
break ;
}
}

# 858 "/home/claude/cfront-3/src/print.cpp"
if (((__0this -> __O3__4expr.e2 -> base__4node != 112 )&& (__0this -> __O3__4expr.e2 -> base__4node != 145 ))&& ((__0this -> __O3__4expr.e2 -> __O1__4expr.tp == 0 )|| ((__0this ->
# 858 "/home/claude/cfront-3/src/print.cpp"
__O3__4expr.e2 -> __O1__4expr.tp -> base__4node != 108 )&& (__0this -> __O3__4expr.e2 -> __O1__4expr.tp -> base__4node != 76 ))))
# 860 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )112 ) ;
if (__0this -> __O3__4expr.e2 -> __O1__4expr.tp && (__0this -> __O3__4expr.e2 -> __O1__4expr.tp -> base__4node == 76 ))
# 862 "/home/claude/cfront-3/src/print.cpp"
__0this -> __O3__4expr.e2 -> __O1__4expr.tp = (struct type *)(((struct fct *)(((struct
# 862 "/home/claude/cfront-3/src/print.cpp"
fct *)(((struct gen *)(((struct gen *)__0this -> __O3__4expr.e2 -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ))));

# 864 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
}
break ;

# 868 "/home/claude/cfront-3/src/print.cpp"
case 54 :
# 869 "/home/claude/cfront-3/src/print.cpp"
case 55 :
# 870 "/home/claude/cfront-3/src/print.cpp"
case 50 :
# 871 "/home/claude/cfront-3/src/print.cpp"
case 51 :
# 872 "/home/claude/cfront-3/src/print.cpp"
case 53 :
# 873 "/home/claude/cfront-3/src/print.cpp"
case 56 :
# 874 "/home/claude/cfront-3/src/print.cpp"
case 57 :
# 875 "/home/claude/cfront-3/src/print.cpp"
case 52 :
# 876 "/home/claude/cfront-3/src/print.cpp"
case 65 :
# 877 "/home/claude/cfront-3/src/print.cpp"
case 64 :
# 878 "/home/claude/cfront-3/src/print.cpp"
case 66 :
# 879 "/home/claude/cfront-3/src/print.cpp"
case 67 :
# 880 "/home/claude/cfront-3/src/print.cpp"
case 49 :
# 881 "/home/claude/cfront-3/src/print.cpp"
case
# 881 "/home/claude/cfront-3/src/print.cpp"
48 :
# 882 "/home/claude/cfront-3/src/print.cpp"
case 132 :
# 883 "/home/claude/cfront-3/src/print.cpp"
case 133 :
# 884 "/home/claude/cfront-3/src/print.cpp"
case 131 :
# 885 "/home/claude/cfront-3/src/print.cpp"
case 126 :
# 886 "/home/claude/cfront-3/src/print.cpp"
case 127 :
# 887 "/home/claude/cfront-3/src/print.cpp"
case 128 :
# 888 "/home/claude/cfront-3/src/print.cpp"
case 130 :
# 889 "/home/claude/cfront-3/src/print.cpp"
case 129 :
# 890 "/home/claude/cfront-3/src/print.cpp"
case 134 :
# 891 "/home/claude/cfront-3/src/print.cpp"
case 135 :
# 892 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O2__4expr.e1 )Eprint__FP4expr ( __0this ->
# 892 "/home/claude/cfront-3/src/print.cpp"
__O2__4expr.e1 ) ;

# 894 "/home/claude/cfront-3/src/print.cpp"
case 172 :
# 895 "/home/claude/cfront-3/src/print.cpp"
case 107 :
# 896 "/home/claude/cfront-3/src/print.cpp"
case 46 :
# 897 "/home/claude/cfront-3/src/print.cpp"
case 47 :
# 898 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( __0this -> base__4node ) ;
if (__0this -> __O3__4expr.e2 )Eprint__FP4expr ( __0this -> __O3__4expr.e2 ) ;
break ;

# 902 "/home/claude/cfront-3/src/print.cpp"
default :
# 903 "/home/claude/cfront-3/src/print.cpp"
{ 
# 903 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V29 ;

# 903 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V30 ;

# 903 "/home/claude/cfront-3/src/print.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%p->E::print%k", (const struct ea *)( ((&
# 903 "/home/claude/cfront-3/src/print.cpp"
__0__V29 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V29 )) , (const struct ea *)( (__2__X33 = __0this -> base__4node ),
# 903 "/home/claude/cfront-3/src/print.cpp"
( (( ((& __0__V30 )-> __O1__2ea.i = __2__X33 ), 0 ) ), (& __0__V30 )) ) , (const struct
# 903 "/home/claude/cfront-3/src/print.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}

# 907 "/home/claude/cfront-3/src/print.cpp"
Pexpr aval__FP4name (Pname __1a );

# 907 "/home/claude/cfront-3/src/print.cpp"
Pexpr aval__FP4name (Pname __1a )
# 908 "/home/claude/cfront-3/src/print.cpp"
{ 
# 909 "/home/claude/cfront-3/src/print.cpp"
int __1argno ;
Pin __1il ;

# 909 "/home/claude/cfront-3/src/print.cpp"
__1argno = __1a -> argno__4name ;

# 911 "/home/claude/cfront-3/src/print.cpp"
for(__1il = curr_icall ;__1il ;__1il = __1il -> i_next__5iline ) 
# 912 "/home/claude/cfront-3/src/print.cpp"
if (__1il -> i_table__5iline == __1a -> __O4__4expr.n_table )
# 913 "/home/claude/cfront-3/src/print.cpp"
goto aok ;
return (struct expr *)0 ;
aok :
# 916 "/home/claude/cfront-3/src/print.cpp"
{ Pexpr __1aa ;

# 916 "/home/claude/cfront-3/src/print.cpp"
__1aa = (__1il -> i_args__5iline [__1argno ]). arg__2ia ;
ll :
# 918 "/home/claude/cfront-3/src/print.cpp"
switch (__1aa -> base__4node ){ 
# 919 "/home/claude/cfront-3/src/print.cpp"
case 191 :
# 920 "/home/claude/cfront-3/src/print.cpp"
case 113 :__1aa = __1aa -> __O2__4expr.e1 ;

# 920 "/home/claude/cfront-3/src/print.cpp"
goto ll ;
case 169 :return aval__FP4name ( ((struct name *)(((struct name *)__1aa )))) ;
default :return __1aa ;
}

# 923 "/home/claude/cfront-3/src/print.cpp"
}
}

# 926 "/home/claude/cfront-3/src/print.cpp"
static void reprint__FP9name_list (Plist __1ll );

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 926 "/home/claude/cfront-3/src/print.cpp"
static void reprint__FP9name_list (Plist __1ll )
# 928 "/home/claude/cfront-3/src/print.cpp"
{ 
# 929 "/home/claude/cfront-3/src/print.cpp"
if (__1ll -> l__9name_list )
# 930 "/home/claude/cfront-3/src/print.cpp"
reprint__FP9name_list ( __1ll -> l__9name_list ) ;
dcl_print__4nameFUc ( __1ll -> f__9name_list , (unsigned char )0 ) ;
}

# 936 "/home/claude/cfront-3/src/print.cpp"
static struct loc csloc = { 0 , 0 } ;

# 55 "/home/claude/cfront-3/src/cfront.h"
void putline__3locFv (struct loc *__0this );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 467 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 78 "/home/claude/incl-linux32/stdio.h"
extern int printf (const char *,...);

# 234 "/home/claude/cfront-3/src/cfront.h"

# 657 "/home/claude/cfront-3/src/cfront.h"
struct name_list *__ct__9name_listFP4nameP9name_list (struct name_list *__0this , Pname __1ff , Plist __1ll );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 938 "/home/claude/cfront-3/src/print.cpp"
void print__4stmtFv (register struct stmt *__0this )
# 939 "/home/claude/cfront-3/src/print.cpp"
{ 
# 941 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> where__4stmt . line__3loc == 0 ){ 
# 942 "/home/claude/cfront-3/src/print.cpp"
if (csloc . line__3loc )
# 943 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & csloc )
# 943 "/home/claude/cfront-3/src/print.cpp"
;
}
else { 
# 946 "/home/claude/cfront-3/src/print.cpp"
csloc = __0this -> where__4stmt ;
if (__0this -> where__4stmt . line__3loc != last_line . line__3loc )
# 948 "/home/claude/cfront-3/src/print.cpp"
if (last_ll = __0this -> where__4stmt . line__3loc )
# 949 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & __0this -> where__4stmt ) ;
# 949 "/home/claude/cfront-3/src/print.cpp"
else 
# 951 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & last_line ) ;
}

# 954 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> memtbl__4stmt && (__0this -> base__4node != 116 )){ 
# 955 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )73 ) ;
{ Ptable __2tbl ;

# 958 "/home/claude/cfront-3/src/print.cpp"
int __2i ;
int __2bl ;

# 956 "/home/claude/cfront-3/src/print.cpp"
__2tbl = __0this -> memtbl__4stmt ;
__0this -> memtbl__4stmt = 0 ;
;
__2bl = 1 ;
{ { Pname __2n ;

# 961 "/home/claude/cfront-3/src/print.cpp"
int __2__X35 ;

# 961 "/home/claude/cfront-3/src/print.cpp"
int __2__X37 ;

# 960 "/home/claude/cfront-3/src/print.cpp"
__2n = ( (__2__X37 = (__2i = 1 )), ( (((__2__X37 <= 0 )|| (__2tbl -> free_slot__5table <= __2__X37 ))?(((struct name *)0 )):(__2tbl -> entries__5table [__2__X37 ]))) )
# 960 "/home/claude/cfront-3/src/print.cpp"
;

# 960 "/home/claude/cfront-3/src/print.cpp"
for(;__2n ;__2n = (__2n -> n_tbl_list__4name ?__2n -> n_tbl_list__4name :( (__2__X35 = (++ __2i )), ( (((__2__X35 <= 0 )|| (__2tbl -> free_slot__5table <= __2__X35 ))?(((struct name *)0 )):(__2tbl ->
# 960 "/home/claude/cfront-3/src/print.cpp"
entries__5table [__2__X35 ]))) ) )) { 
# 961 "/home/claude/cfront-3/src/print.cpp"
if (__2n -> __O1__4expr.tp == (((struct type *)any_type )))
# 962 "/home/claude/cfront-3/src/print.cpp"
continue ;

# 964 "/home/claude/cfront-3/src/print.cpp"
{ const char *__3s ;

# 975 "/home/claude/cfront-3/src/print.cpp"
Pname __3cn ;

# 976 "/home/claude/cfront-3/src/print.cpp"
struct classdef *__0__X36 ;

# 964 "/home/claude/cfront-3/src/print.cpp"
__3s = __2n -> __O2__4expr.string ;
if ((((__3s [0 ])!= '_' )|| ((__3s [1 ])!= '_' ))|| ((__3s [2 ])!= 'X' ))
# 971 "/home/claude/cfront-3/src/print.cpp"
{ 
# 972 "/home/claude/cfront-3/src/print.cpp"
dcl_print__4nameFUc ( __2n , (unsigned char )0 ) ;
__2bl = 0 ;
}
;
if ((__2bl && (__3cn = is_cl_obj__4typeFv ( __2n -> __O1__4expr.tp ) ))&& ( (__0__X36 = (((struct classdef *)(((struct classdef *)__3cn -> __O1__4expr.tp ))))), (
# 976 "/home/claude/cfront-3/src/print.cpp"
__0__X36 -> c_dtor__8classdef ) ) )
# 983 "/home/claude/cfront-3/src/print.cpp"
__2bl = 0 ;

# 983 "/home/claude/cfront-3/src/print.cpp"
}
}
if ((last_ll == 0 )&& (last_ll = __0this -> where__4stmt . line__3loc ))
# 986 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & __0this -> where__4stmt ) ;
if (__2bl ){ 
# 988 "/home/claude/cfront-3/src/print.cpp"
Pstmt __3sl ;

# 988 "/home/claude/cfront-3/src/print.cpp"
__3sl = __0this -> s_list__4stmt ;
__0this -> s_list__4stmt = 0 ;
print__4stmtFv ( __0this ) ;
__0this -> memtbl__4stmt = __2tbl ;
puttok__FUc ( (unsigned char )74 ) ;
if (__3sl ){ 
# 994 "/home/claude/cfront-3/src/print.cpp"
__0this -> s_list__4stmt = __3sl ;
print__4stmtFv ( __3sl ) ;
}
}
else { 
# 999 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this ) ;
__0this -> memtbl__4stmt = __2tbl ;
puttok__FUc ( (unsigned char )74 ) ;
}
return ;

# 1003 "/home/claude/cfront-3/src/print.cpp"
}

# 1003 "/home/claude/cfront-3/src/print.cpp"
}

# 1003 "/home/claude/cfront-3/src/print.cpp"
}
}

# 1006 "/home/claude/cfront-3/src/print.cpp"
switch (__0this -> base__4node ){ 
# 1006 "/home/claude/cfront-3/src/print.cpp"
unsigned long __2__X38 ;

# 1007 "/home/claude/cfront-3/src/print.cpp"
default :
# 1008 "/home/claude/cfront-3/src/print.cpp"
{ 
# 1008 "/home/claude/cfront-3/src/print.cpp"
struct ea __0__V34 ;

# 1008 "/home/claude/cfront-3/src/print.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"S::print(base=%k)", (const struct ea *)( (__2__X38 =
# 1008 "/home/claude/cfront-3/src/print.cpp"
__0this -> base__4node ), ( (( ((& __0__V34 )-> __O1__2ea.i = __2__X38 ), 0 ) ), (& __0__V34 )) ) ,
# 1008 "/home/claude/cfront-3/src/print.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 1010 "/home/claude/cfront-3/src/print.cpp"
case 1 :
# 1011 "/home/claude/cfront-3/src/print.cpp"
fprintf ( out_file , (const char *)"asm(\"%s\");\n", ((char *)__0this -> __O2__4stmt.e )) ;
# 1011 "/home/claude/cfront-3/src/print.cpp"

# 1012 "/home/claude/cfront-3/src/print.cpp"
break ;

# 1014 "/home/claude/cfront-3/src/print.cpp"
case 118 :
# 1015 "/home/claude/cfront-3/src/print.cpp"
dcl_print__4nameFUc ( __0this -> __O1__4stmt.d , (unsigned char )72 ) ;
break ;

# 1018 "/home/claude/cfront-3/src/print.cpp"
case 3 :
# 1019 "/home/claude/cfront-3/src/print.cpp"
case 7 :
# 1020 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( __0this -> base__4node ) ;
puttok__FUc ( (unsigned char )72 ) ;
break ;

# 1024 "/home/claude/cfront-3/src/print.cpp"
case 8 :
# 1025 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( __0this -> base__4node ) ;
fputc ( (int )':' , out_file ) ;
print__4stmtFv ( __0this -> s__4stmt ) ;
break ;

# 1030 "/home/claude/cfront-3/src/print.cpp"
case 72 :{ 
# 1031 "/home/claude/cfront-3/src/print.cpp"
Pexpr __3ee ;

# 1031 "/home/claude/cfront-3/src/print.cpp"
__3ee = __0this -> __O2__4stmt.e ;
while (__3ee && ((__3ee -> base__4node == 113 )|| (__3ee -> base__4node == 191 )))
# 1033 "/home/claude/cfront-3/src/print.cpp"
__3ee = __3ee -> __O2__4expr.e1 ;
if (__3ee && (__3ee -> base__4node == 124 )){ 
# 1035 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )72 ) ;
break ;
}
if (__0this -> __O2__4stmt.e ){ 
# 1039 "/home/claude/cfront-3/src/print.cpp"
;
print__4exprFv ( __0this -> __O2__4stmt.e ) ;
if ((__0this -> __O2__4stmt.e -> base__4node == 168 )&& __0this -> __O2__4stmt.e -> __O3__4expr.e2 )break ;
}
puttok__FUc ( (unsigned char )72 ) ;
break ;
}

# 1047 "/home/claude/cfront-3/src/print.cpp"
case 39 :
# 1048 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )39 ) ;
fputc ( (int )'(' , out_file ) ;

# 1049 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O2__4stmt.e ) ;

# 1049 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )')' , out_file ) ;
if (__0this -> s__4stmt -> s_list__4stmt ){ 
# 1051 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )73 ) ;
print__4stmtFv ( __0this -> s__4stmt ) ;
puttok__FUc ( (unsigned char )74 ) ;
}
else 
# 1056 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this -> s__4stmt ) ;
break ;

# 1059 "/home/claude/cfront-3/src/print.cpp"
case 10 :
# 1060 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )10 ) ;
print__4stmtFv ( __0this -> s__4stmt ) ;
puttok__FUc ( (unsigned char )39 ) ;
fputc ( (int )'(' , out_file ) ;

# 1063 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O2__4stmt.e ) ;

# 1063 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )')' , out_file ) ;
puttok__FUc ( (unsigned char )72 ) ;
break ;

# 1067 "/home/claude/cfront-3/src/print.cpp"
case 33 :
# 1068 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )33 ) ;
fputc ( (int )'(' , out_file ) ;

# 1069 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O2__4stmt.e ) ;

# 1069 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )')' , out_file ) ;
print__4stmtFv ( __0this -> s__4stmt ) ;
break ;

# 1073 "/home/claude/cfront-3/src/print.cpp"
case 28 :
# 1074 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> gt__4stmt ){ 
# 1075 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this -> gt__4stmt ) ;
break ;
}
puttok__FUc ( (unsigned char )28 ) ;
if (__0this -> __O2__4stmt.e ){ 
# 1081 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O1__4stmt.ret_tp && (__0this -> __O1__4stmt.ret_tp != __0this -> __O2__4stmt.e -> __O1__4expr.tp )){ 
# 1082 "/home/claude/cfront-3/src/print.cpp"
Ptype __4tt ;

# 1082 "/home/claude/cfront-3/src/print.cpp"
__4tt = skiptypedefs__4typeFv ( __0this -> __O1__4stmt.ret_tp ) ;

# 1084 "/home/claude/cfront-3/src/print.cpp"
switch (__4tt -> base__4node ){ 
# 1085 "/home/claude/cfront-3/src/print.cpp"
case 119 :
# 1086 "/home/claude/cfront-3/src/print.cpp"
break ;
case 158 :
# 1088 "/home/claude/cfront-3/src/print.cpp"
case 125 :
# 1089 "/home/claude/cfront-3/src/print.cpp"
if ((((struct ptr *)(((struct ptr *)__4tt ))))-> typ__5pvtyp == (((struct ptr *)(((struct ptr *)__0this -> __O2__4stmt.e -> __O1__4expr.tp ))))-> typ__5pvtyp )
# 1090 "/home/claude/cfront-3/src/print.cpp"
break ;
# 1090 "/home/claude/cfront-3/src/print.cpp"

# 1091 "/home/claude/cfront-3/src/print.cpp"
if ((((struct ptr *)(((struct ptr *)__4tt ))))-> memof__3ptr )
# 1092 "/home/claude/cfront-3/src/print.cpp"
break ;
default :
# 1094 "/home/claude/cfront-3/src/print.cpp"
if ((__0this -> __O2__4stmt.e -> __O1__4expr.tp == 0 )|| check__4typeFP4typeUcT2 ( __0this -> __O1__4stmt.ret_tp , __0this -> __O2__4stmt.e -> __O1__4expr.tp , (unsigned char
# 1094 "/home/claude/cfront-3/src/print.cpp"
)0 , (unsigned char )0 ) ){ 
# 1095 "/home/claude/cfront-3/src/print.cpp"
int __6oc ;

# 1095 "/home/claude/cfront-3/src/print.cpp"
__6oc = Cast ;
fputc ( (int )'(' , out_file ) ;
Cast = 1 ;
print__4typeFv ( __0this -> __O1__4stmt.ret_tp ) ;
Cast = __6oc ;
fputc ( (int )')' , out_file ) ;
}
}
}
if (__0this -> __O2__4stmt.e )Eprint__FP4expr ( __0this -> __O2__4stmt.e ) ;
}
puttok__FUc ( (unsigned char )72 ) ;
while (__0this -> s_list__4stmt && (__0this -> s_list__4stmt -> base__4node == 72 ))
# 1108 "/home/claude/cfront-3/src/print.cpp"
__0this -> s_list__4stmt = __0this -> s_list__4stmt -> s_list__4stmt ;
break ;

# 1111 "/home/claude/cfront-3/src/print.cpp"
case 4 :
# 1112 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )4 ) ;
if (__0this -> __O2__4stmt.e )Eprint__FP4expr ( __0this -> __O2__4stmt.e ) ;
fputc ( (int )':' , out_file ) ;
print__4stmtFv ( __0this -> s__4stmt ) ;
break ;

# 1118 "/home/claude/cfront-3/src/print.cpp"
case 19 :
# 1119 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )19 ) ;
if (curr_lab )
# 1121 "/home/claude/cfront-3/src/print.cpp"
printf ( (const char *)"_%ld__", curr_lab ) ;
print__4nameFUc ( __0this -> __O1__4stmt.d , (unsigned char )0 ) ;
puttok__FUc ( (unsigned char )72 ) ;
break ;

# 1126 "/home/claude/cfront-3/src/print.cpp"
case 115 :
# 1127 "/home/claude/cfront-3/src/print.cpp"
if (curr_lab )
# 1128 "/home/claude/cfront-3/src/print.cpp"
printf ( (const char *)"_%ld__", curr_lab ) ;
print__4nameFUc ( __0this -> __O1__4stmt.d , (unsigned char )0 ) ;
fputc ( (int )':' , out_file ) ;
print__4stmtFv ( __0this -> s__4stmt ) ;
break ;

# 1134 "/home/claude/cfront-3/src/print.cpp"
case 20 :
# 1135 "/home/claude/cfront-3/src/print.cpp"
{ int __3val ;

# 1135 "/home/claude/cfront-3/src/print.cpp"
__3val = 68 ;
if (__0this -> __O2__4stmt.e -> base__4node == 169 ){ 
# 1137 "/home/claude/cfront-3/src/print.cpp"
Pname __4a ;
Pexpr __4arg ;

# 1137 "/home/claude/cfront-3/src/print.cpp"
__4a = (((struct name *)(((struct name *)__0this -> __O2__4stmt.e ))));
__4arg = aval__FP4name ( __4a ) ;

# 1140 "/home/claude/cfront-3/src/print.cpp"
if (__4arg )
# 1141 "/home/claude/cfront-3/src/print.cpp"
switch (__4arg -> base__4node ){ 
# 1142 "/home/claude/cfront-3/src/print.cpp"
case 86 :__3val = 0 ;

# 1142 "/home/claude/cfront-3/src/print.cpp"
break ;
case 112 :
# 1144 "/home/claude/cfront-3/src/print.cpp"
case 145 :__3val = 1 ;

# 1144 "/home/claude/cfront-3/src/print.cpp"
break ;
case 150 :__3val = (__4arg -> __O2__4expr.i1 != 0 );
}
}

# 1149 "/home/claude/cfront-3/src/print.cpp"
switch (__3val ){ 
# 1150 "/home/claude/cfront-3/src/print.cpp"
case 1 :
# 1151 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this -> s__4stmt ) ;
break ;
case 0 :
# 1154 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4stmt.else_stmt )
# 1155 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this -> __O3__4stmt.else_stmt ) ;
else 
# 1157 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )72 ) ;
break ;
default :
# 1160 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )20 ) ;
fputc ( (int )'(' , out_file ) ;

# 1161 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O2__4stmt.e ) ;

# 1161 "/home/claude/cfront-3/src/print.cpp"
fputc ( (int )')' , out_file ) ;
if (__0this -> s__4stmt -> s_list__4stmt ){ 
# 1163 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )73 ) ;
print__4stmtFv ( __0this -> s__4stmt ) ;
puttok__FUc ( (unsigned char )74 ) ;
}
else 
# 1168 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this -> s__4stmt ) ;
if (__0this -> __O3__4stmt.else_stmt ){ 
# 1170 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )12 ) ;
if (__0this -> __O3__4stmt.else_stmt -> where__4stmt . line__3loc == 0 ){ 
# 1172 "/home/claude/cfront-3/src/print.cpp"
if (csloc . line__3loc )
# 1173 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & csloc ) ;
}
else { 
# 1176 "/home/claude/cfront-3/src/print.cpp"
csloc = __0this -> __O3__4stmt.else_stmt -> where__4stmt ;
if (__0this -> __O3__4stmt.else_stmt -> where__4stmt . line__3loc != last_line . line__3loc )
# 1178 "/home/claude/cfront-3/src/print.cpp"
if (last_ll = __0this -> __O3__4stmt.else_stmt -> where__4stmt . line__3loc )
# 1179 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & __0this ->
# 1179 "/home/claude/cfront-3/src/print.cpp"
__O3__4stmt.else_stmt -> where__4stmt ) ;
else 
# 1181 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & last_line ) ;
}
if (__0this -> __O3__4stmt.else_stmt -> s_list__4stmt ){ 
# 1184 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )73 ) ;
print__4stmtFv ( __0this -> __O3__4stmt.else_stmt ) ;
puttok__FUc ( (unsigned char )74 ) ;
}
else 
# 1189 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this -> __O3__4stmt.else_stmt ) ;
}
}
break ;
}

# 1195 "/home/claude/cfront-3/src/print.cpp"
case 16 :
# 1196 "/home/claude/cfront-3/src/print.cpp"
{ 
# 1197 "/home/claude/cfront-3/src/print.cpp"
int __3fi ;

# 1197 "/home/claude/cfront-3/src/print.cpp"
__3fi = 0 ;
if (__0this -> __O3__4stmt.for_init ){ 
# 1199 "/home/claude/cfront-3/src/print.cpp"
__3fi = 1 ;
if ((__0this -> __O3__4stmt.for_init -> memtbl__4stmt == 0 )&& (__0this -> __O3__4stmt.for_init -> s_list__4stmt == 0 ))
# 1201 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O3__4stmt.for_init -> base__4node == 72 )
# 1202 "/home/claude/cfront-3/src/print.cpp"
if ((__0this ->
# 1202 "/home/claude/cfront-3/src/print.cpp"
__O3__4stmt.for_init -> __O2__4stmt.e -> base__4node != 168 )|| __0this -> __O3__4stmt.for_init -> __O2__4stmt.e -> __O2__4expr.e1 )
# 1203 "/home/claude/cfront-3/src/print.cpp"
__3fi = 0 ;
}

# 1206 "/home/claude/cfront-3/src/print.cpp"
if (__3fi ){ 
# 1207 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )73 ) ;
print__4stmtFv ( __0this -> __O3__4stmt.for_init ) ;
}
fputs ( (const char *)"for(", out_file ) ;
if ((__3fi == 0 )&& __0this -> __O3__4stmt.for_init )
# 1212 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O3__4stmt.for_init -> __O2__4stmt.e ) ;
fputc ( (int )';' , out_file ) ;
if (__0this -> __O2__4stmt.e )
# 1215 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O2__4stmt.e ) ;
fputc ( (int )';' , out_file ) ;
if (__0this -> __O1__4stmt.e2 )
# 1218 "/home/claude/cfront-3/src/print.cpp"
print__4exprFv ( __0this -> __O1__4stmt.e2 ) ;
puttok__FUc ( (unsigned char )41 ) ;
print__4stmtFv ( __0this -> s__4stmt ) ;
if (__3fi )
# 1222 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )74 ) ;
break ;
}

# 1226 "/home/claude/cfront-3/src/print.cpp"
case 166 :
# 1227 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> s__4stmt && __0this -> __O2__4stmt.s2 ){ 
# 1228 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )73 ) ;
print__4stmtFv ( __0this -> s__4stmt ) ;
print__4stmtFv ( __0this -> __O2__4stmt.s2 ) ;
puttok__FUc ( (unsigned char )74 ) ;
}
else { 
# 1234 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> s__4stmt )
# 1235 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this -> s__4stmt ) ;
if (__0this -> __O2__4stmt.s2 )
# 1237 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this -> __O2__4stmt.s2 ) ;
}
break ;

# 1241 "/home/claude/cfront-3/src/print.cpp"
case 116 :
# 1242 "/home/claude/cfront-3/src/print.cpp"
puttok__FUc ( (unsigned char )73 ) ;

# 1244 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> __O1__4stmt.d )
# 1245 "/home/claude/cfront-3/src/print.cpp"
dcl_print__4nameFUc ( __0this -> __O1__4stmt.d , (unsigned char )72 ) ;
if (__0this -> memtbl__4stmt && __0this -> __O2__4stmt.own_tbl ){ 
# 1247 "/home/claude/cfront-3/src/print.cpp"
Pname __3n ;
int __3i ;
Plist __3aglist ;

# 1250 "/home/claude/cfront-3/src/print.cpp"
struct table *__0__X39 ;

# 1250 "/home/claude/cfront-3/src/print.cpp"
int __2__X40 ;

# 1250 "/home/claude/cfront-3/src/print.cpp"
struct table *__0__X41 ;

# 1250 "/home/claude/cfront-3/src/print.cpp"
int __2__X42 ;

# 1249 "/home/claude/cfront-3/src/print.cpp"
__3aglist = 0 ;
for(__3n = ( (__0__X39 = __0this -> memtbl__4stmt ), ( (__2__X40 = (__3i = 1 )), ( (((__2__X40 <= 0 )|| (__0__X39 -> free_slot__5table <=
# 1250 "/home/claude/cfront-3/src/print.cpp"
__2__X40 ))?(((struct name *)0 )):(__0__X39 -> entries__5table [__2__X40 ]))) ) ) ;__3n ;__3n = (__3n -> n_tbl_list__4name ?__3n -> n_tbl_list__4name :( (__0__X41 = __0this -> memtbl__4stmt ), ( (__2__X42 =
# 1250 "/home/claude/cfront-3/src/print.cpp"
(++ __3i )), ( (((__2__X42 <= 0 )|| (__0__X41 -> free_slot__5table <= __2__X42 ))?(((struct name *)0 )):(__0__X41 -> entries__5table [__2__X42 ]))) ) ) )) {
# 1250 "/home/claude/cfront-3/src/print.cpp"

# 1251 "/home/claude/cfront-3/src/print.cpp"
;
if ((__3n -> __O1__4expr.tp && (__3n -> n_anon__4name == 0 ))&& (__3n -> __O1__4expr.tp != (((struct type *)any_type ))))
# 1259 "/home/claude/cfront-3/src/print.cpp"
switch (__3n -> n_scope__4name ){ 
# 1260 "/home/claude/cfront-3/src/print.cpp"
case 139 :
# 1261 "/home/claude/cfront-3/src/print.cpp"
case
# 1261 "/home/claude/cfront-3/src/print.cpp"
136 :
# 1262 "/home/claude/cfront-3/src/print.cpp"
break ;
default :
# 1265 "/home/claude/cfront-3/src/print.cpp"
if (((__3n -> base__4node == 123 )&& __3n -> __O3__4expr.tpdef )&& __3n -> __O3__4expr.tpdef -> nested_sig__4type )
# 1269 "/home/claude/cfront-3/src/print.cpp"
continue ;
if ((ansi_opt == 0 )|| (! __3n -> __O3__4expr.n_initializer ))
# 1271 "/home/claude/cfront-3/src/print.cpp"
dcl_print__4nameFUc ( __3n , (unsigned char )0 ) ;
else 
# 1273 "/home/claude/cfront-3/src/print.cpp"
__3aglist = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __3n , __3aglist ) ;
}
}
if (__3aglist )
# 1277 "/home/claude/cfront-3/src/print.cpp"
reprint__FP9name_list ( __3aglist ) ;

# 1279 "/home/claude/cfront-3/src/print.cpp"
if (((last_ll == 0 )&& __0this -> s__4stmt )&& (last_ll = __0this -> s__4stmt -> where__4stmt . line__3loc ))
# 1286 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & __0this -> s__4stmt -> where__4stmt )
# 1286 "/home/claude/cfront-3/src/print.cpp"
;
}

# 1289 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> s__4stmt )
# 1290 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this -> s__4stmt ) ;
if (__0this -> __O3__4stmt.where2 . line__3loc == 0 ){ 
# 1292 "/home/claude/cfront-3/src/print.cpp"
if (csloc . line__3loc )
# 1293 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & csloc ) ;
}
else { 
# 1296 "/home/claude/cfront-3/src/print.cpp"
csloc = __0this -> __O3__4stmt.where2 ;
if (__0this -> __O3__4stmt.where2 . line__3loc != last_line . line__3loc )
# 1298 "/home/claude/cfront-3/src/print.cpp"
if (last_ll = __0this -> __O3__4stmt.where2 . line__3loc )
# 1299 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & __0this -> __O3__4stmt.where2 ) ;
# 1299 "/home/claude/cfront-3/src/print.cpp"
else 
# 1301 "/home/claude/cfront-3/src/print.cpp"
putline__3locFv ( & last_line ) ;
}
fputs ( (const char *)"}\n", out_file ) ;
if (last_ll && __0this -> where__4stmt . line__3loc )
# 1305 "/home/claude/cfront-3/src/print.cpp"
last_line . line__3loc ++ ;
} }

# 1308 "/home/claude/cfront-3/src/print.cpp"
if (__0this -> s_list__4stmt )
# 1309 "/home/claude/cfront-3/src/print.cpp"
print__4stmtFv ( __0this -> s_list__4stmt ) ;
}
struct ptbl_rec;

# 1318 "/home/claude/cfront-3/src/print.cpp"
static char *ptbl_name ;
static struct ptbl_rec *ptbl_rec_lookup_head = 0 ;
static struct ptbl_rec *ptbl_rec_pair_head = 0 ;

# 749 "/home/claude/cfront-3/src/cfront.h"
extern char *st_name__FPCc (const char *);

# 1312 "/home/claude/cfront-3/src/print.cpp"
struct ptbl_rec {	/* sizeof ptbl_rec == 24 */
char *pname__8ptbl_rec ;
char *vname__8ptbl_rec ;
struct ptbl_rec *next__8ptbl_rec ;
};

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 1322 "/home/claude/cfront-3/src/print.cpp"
void ptbl_init__Fi (int __1flag )
# 1323 "/home/claude/cfront-3/src/print.cpp"
{ 
# 1324 "/home/claude/cfront-3/src/print.cpp"
if (! __1flag ){ 
# 1325 "/home/claude/cfront-3/src/print.cpp"
char *__2p ;

# 1325 "/home/claude/cfront-3/src/print.cpp"
__2p = st_name__FPCc ( (const char *)"__ptbl_vec__") ;
ptbl_name = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( (const char *)__2p ) + 1 )))
# 1326 "/home/claude/cfront-3/src/print.cpp"
));
strcpy ( ptbl_name , (const char *)__2p ) ;
__dl__FPv ( (void *)__2p ) ;
{ struct loc __2old ;

# 1329 "/home/claude/cfront-3/src/print.cpp"
__2old = curloc ;
curloc . file__3loc = 0 ;
curloc . line__3loc = 1 ;
putline__3locFv ( & curloc ) ;
curloc = __2old ;
fprintf ( out_file , (const char *)"extern struct __mptr* %s[];\n", ptbl_name ) ;
if (last_ll )
# 1336 "/home/claude/cfront-3/src/print.cpp"
last_line . line__3loc ++ ;

# 1336 "/home/claude/cfront-3/src/print.cpp"
}
}
else { 
# 1339 "/home/claude/cfront-3/src/print.cpp"
struct ptbl_rec *__2r ;

# 1339 "/home/claude/cfront-3/src/print.cpp"
struct ptbl_rec *__2p ;

# 1339 "/home/claude/cfront-3/src/print.cpp"
__2p = ptbl_rec_lookup_head ;
if (__2p == 0 )
# 1341 "/home/claude/cfront-3/src/print.cpp"
return ;
fprintf ( out_file , (const char *)"struct __mptr* %s[] = {\n", ptbl_name ) ;
if (last_ll )
# 1344 "/home/claude/cfront-3/src/print.cpp"
last_line . line__3loc ++ ;
while (__2p != 0 ){ 
# 1346 "/home/claude/cfront-3/src/print.cpp"
__2r = ptbl_rec_pair_head ;
while (__2r && strcmp ( (const char *)__2r -> pname__8ptbl_rec , (const char *)__2p -> pname__8ptbl_rec ) )
# 1348 "/home/claude/cfront-3/src/print.cpp"
__2r = __2r -> next__8ptbl_rec ;
# 1348 "/home/claude/cfront-3/src/print.cpp"

# 1349 "/home/claude/cfront-3/src/print.cpp"
fprintf ( out_file , (const char *)"%s,\n", __2r -> vname__8ptbl_rec ) ;
if (last_ll )
# 1351 "/home/claude/cfront-3/src/print.cpp"
last_line . line__3loc ++ ;
__2p = __2p -> next__8ptbl_rec ;
}
fprintf ( out_file , (const char *)"\n};\n") ;
if (last_ll )
# 1356 "/home/claude/cfront-3/src/print.cpp"
last_line . line__3loc += 2 ;
}
}

# 80 "/home/claude/incl-linux32/stdio.h"
extern int sprintf (char *, const char *,...);

# 1360 "/home/claude/cfront-3/src/print.cpp"
char *ptbl_lookup__FPCc (const char *__1name )
# 1361 "/home/claude/cfront-3/src/print.cpp"
{ 
# 1362 "/home/claude/cfront-3/src/print.cpp"
struct ptbl_rec *__1r ;

# 1362 "/home/claude/cfront-3/src/print.cpp"
struct ptbl_rec *__1s ;

# 1362 "/home/claude/cfront-3/src/print.cpp"
struct ptbl_rec *__1p ;
int __1i ;

# 1362 "/home/claude/cfront-3/src/print.cpp"
__1p = ptbl_rec_lookup_head ;
__1i = 0 ;

# 1365 "/home/claude/cfront-3/src/print.cpp"
while (__1p && strcmp ( __1name , (const char *)__1p -> pname__8ptbl_rec ) ){ 
# 1366 "/home/claude/cfront-3/src/print.cpp"
__1r = __1p ;
__1p = __1p -> next__8ptbl_rec ;
__1i ++ ;
}

# 1371 "/home/claude/cfront-3/src/print.cpp"
if (__1p == 0 ){ 
# 1372 "/home/claude/cfront-3/src/print.cpp"
__1s = (((struct ptbl_rec *)__nw__FUl ( sizeof (struct ptbl_rec )) ));
__1s -> pname__8ptbl_rec = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __1name ) + 1 ))) ));
# 1373 "/home/claude/cfront-3/src/print.cpp"

# 1374 "/home/claude/cfront-3/src/print.cpp"
__1s -> vname__8ptbl_rec = 0 ;
__1s -> next__8ptbl_rec = 0 ;
strcpy ( __1s -> pname__8ptbl_rec , __1name ) ;
if (ptbl_rec_lookup_head == 0 )
# 1378 "/home/claude/cfront-3/src/print.cpp"
ptbl_rec_lookup_head = __1s ;
else 
# 1380 "/home/claude/cfront-3/src/print.cpp"
__1r -> next__8ptbl_rec = __1s ;
}

# 1383 "/home/claude/cfront-3/src/print.cpp"
{ char *__1pp ;

# 1383 "/home/claude/cfront-3/src/print.cpp"
__1pp = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( (const char *)ptbl_name ) + 10 )))
# 1383 "/home/claude/cfront-3/src/print.cpp"
));
sprintf ( __1pp , (const char *)"%s[%d]", ptbl_name , __1i ) ;
return __1pp ;

# 1385 "/home/claude/cfront-3/src/print.cpp"
}
}

# 1388 "/home/claude/cfront-3/src/print.cpp"
void ptbl_add_pair__FPCcT1 (const char *__1ptbl , const char *__1vtbl )
# 1389 "/home/claude/cfront-3/src/print.cpp"
{ 
# 1391 "/home/claude/cfront-3/src/print.cpp"
struct ptbl_rec *__1p ;

# 1391 "/home/claude/cfront-3/src/print.cpp"
__1p = (((struct ptbl_rec *)__nw__FUl ( sizeof (struct ptbl_rec )) ));

# 1393 "/home/claude/cfront-3/src/print.cpp"
__1p -> pname__8ptbl_rec = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __1ptbl ) + 1 ))) ));
# 1393 "/home/claude/cfront-3/src/print.cpp"

# 1394 "/home/claude/cfront-3/src/print.cpp"
strcpy ( __1p -> pname__8ptbl_rec , __1ptbl ) ;
__1p -> vname__8ptbl_rec = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __1vtbl ) + 1 ))) ));
# 1395 "/home/claude/cfront-3/src/print.cpp"

# 1397 "/home/claude/cfront-3/src/print.cpp"
strcpy ( __1p -> vname__8ptbl_rec , __1vtbl ) ;
__1p -> next__8ptbl_rec = ptbl_rec_pair_head ;

# 1400 "/home/claude/cfront-3/src/print.cpp"
ptbl_rec_pair_head = __1p ;
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

# 1401 "/home/claude/cfront-3/src/print.cpp"

/* the end */
