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

# 25 "/home/claude/cfront-3/src/print2.cpp"
bit TCast = 0 ;
bit Cast = 0 ;
int last_ll = 1 ;
Pin curr_icall = 0 ;
char emode = 0 ;
int ntok = 0 ;
bit mk_zero_init_flag = 0 ;

# 33 "/home/claude/cfront-3/src/print2.cpp"
static int MAIN ;

# 41 "/home/claude/cfront-3/src/print2.cpp"
static Ptable mem_table ;
static Ptable perm_table ;
static int mem_depth ;
extern int dem_opt_mem ;
extern int dem_opt_local ;

# 22 "/home/claude/incl-linux32/string.h"
extern int strncmp (const char *, const char *, size_t );

# 47 "/home/claude/cfront-3/src/print2.cpp"
int ispt_data__FP4name (Pname __1n )
# 48 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 49 "/home/claude/cfront-3/src/print2.cpp"
if ((((! __1n -> __O1__4expr.tp )|| (! __1n -> __O4__4expr.n_table ))|| (! __1n -> __O4__4expr.n_table -> t_name__5table ))|| (!
# 49 "/home/claude/cfront-3/src/print2.cpp"
__1n -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))
# 50 "/home/claude/cfront-3/src/print2.cpp"
return 0 ;
{ const char *__1s ;

# 51 "/home/claude/cfront-3/src/print2.cpp"
__1s = (((struct classdef *)(((struct classdef *)__1n -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))))-> string__8classdef ;
while ((*__1s )){ 
# 53 "/home/claude/cfront-3/src/print2.cpp"
if (! strncmp ( __1s , (const char *)"__pt__", (unsigned
# 53 "/home/claude/cfront-3/src/print2.cpp"
long )6 ) )
# 54 "/home/claude/cfront-3/src/print2.cpp"
return 1 ;
__1s ++ ;
}
return 0 ;

# 57 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 220 "/home/claude/cfront-3/src/cfront.h"
struct table *__ct__5tableFsP5tableP4name (struct table *__0this , short , Ptable , Pname );

# 60 "/home/claude/cfront-3/src/print2.cpp"
static void begin_mem__Fv (void )
# 61 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 62 "/home/claude/cfront-3/src/print2.cpp"
if (! dem_opt_mem )
# 63 "/home/claude/cfront-3/src/print2.cpp"
return ;
if (! (mem_depth ++ ))
# 65 "/home/claude/cfront-3/src/print2.cpp"
mem_table = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )16 , (struct table *)0 , (struct name *)0 ) ;
# 65 "/home/claude/cfront-3/src/print2.cpp"

# 66 "/home/claude/cfront-3/src/print2.cpp"
}

# 218 "/home/claude/cfront-3/src/cfront.h"

# 221 "/home/claude/cfront-3/src/cfront.h"
void __dt__5tableFv (struct table *__0this , int );

# 68 "/home/claude/cfront-3/src/print2.cpp"
static void end_mem__Fv (void )
# 69 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 70 "/home/claude/cfront-3/src/print2.cpp"
if (! dem_opt_mem )
# 71 "/home/claude/cfront-3/src/print2.cpp"
return ;
if (! (-- mem_depth )){ 
# 73 "/home/claude/cfront-3/src/print2.cpp"
__dt__5tableFv ( mem_table , 3) ;
mem_table = 0 ;
}
}

# 80 "/home/claude/incl-linux32/stdio.h"
extern int sprintf (char *, const char *,...);

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 78 "/home/claude/cfront-3/src/print2.cpp"
static int dem_mem__FPCcT1 (const char *__1cn , const char *__1mn )
# 79 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 80 "/home/claude/cfront-3/src/print2.cpp"
char __1buf [1024];
Pname __1n ;

# 83 "/home/claude/cfront-3/src/print2.cpp"
if ((((! __1cn )|| (! __1mn ))|| (! ((*__1cn ))))|| (! ((*__1mn ))))
# 84 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCc ( (int )'i' , (const char *)"invalidA to dem_mem()")
# 84 "/home/claude/cfront-3/src/print2.cpp"
;

# 86 "/home/claude/cfront-3/src/print2.cpp"
sprintf ( (char *)__1buf , (const char *)"%s__%s", __1cn , __1mn ) ;

# 88 "/home/claude/cfront-3/src/print2.cpp"
if (mem_table ){ 
# 89 "/home/claude/cfront-3/src/print2.cpp"
if (look__5tableFPCcUc ( mem_table , __1mn , (unsigned char )0 ) ){ 
# 90 "/home/claude/cfront-3/src/print2.cpp"
if (! perm_table )
# 91 "/home/claude/cfront-3/src/print2.cpp"
perm_table = __ct__5tableFsP5tableP4name (
# 91 "/home/claude/cfront-3/src/print2.cpp"
(struct table *)0 , (short )16 , (struct table *)0 , (struct name *)0 ) ;
__1n = __ct__4nameFPCc ( (struct name *)0 , (const char *)__1buf ) ;
insert__5tableFP4nameUc ( perm_table , __1n , (unsigned char )0 ) ;
( (__1n ?(((void )(__1n ?(((void )( ( ((((struct expr *)__1n ))?(((void )((((struct expr *)__1n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 94 "/home/claude/cfront-3/src/print2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1n , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
return 0 ;
}
else { 
# 98 "/home/claude/cfront-3/src/print2.cpp"
__1n = __ct__4nameFPCc ( (struct name *)0 , __1mn ) ;
insert__5tableFP4nameUc ( mem_table , __1n , (unsigned char )0 ) ;
( (__1n ?(((void )(__1n ?(((void )( ( ((((struct expr *)__1n ))?(((void )((((struct expr *)__1n ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 100 "/home/claude/cfront-3/src/print2.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1n , (unsigned long )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
return 1 ;
}
}
else { 
# 105 "/home/claude/cfront-3/src/print2.cpp"
return ((! perm_table )|| (! look__5tableFPCcUc ( perm_table , (const char *)__1buf , (unsigned char )0 )
# 105 "/home/claude/cfront-3/src/print2.cpp"
));
}
}

# 77 "/home/claude/incl-linux32/stdio.h"
extern int fputs (const char *__0s , void *__0stream );

# 55 "/home/claude/cfront-3/src/cfront.h"
void putline__3locFv (struct loc *__0this );

# 96 "/home/claude/incl-linux32/stdio.h"
extern int fputc (int , void *);

# 109 "/home/claude/cfront-3/src/print2.cpp"
void puttok__FUc (TOK __1t )
# 113 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 114 "/home/claude/cfront-3/src/print2.cpp"
fputs ( keys [__1t ], out_file ) ;

# 116 "/home/claude/cfront-3/src/print2.cpp"
if (12 < (ntok ++ )){ 
# 117 "/home/claude/cfront-3/src/print2.cpp"
ntok = 0 ;
if (emode == 0 )putline__3locFv ( & last_line ) ;
}
else if (__1t == 72 ){ 
# 121 "/home/claude/cfront-3/src/print2.cpp"
ntok = 0 ;
fputc ( (int )'\n' , out_file ) ;
if (last_ll )last_line . line__3loc ++ ;
}
else 
# 126 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )' ' , out_file ) ;
}
struct dcl_buf;

# 131 "/home/claude/cfront-3/src/print2.cpp"
struct dcl_buf {	/* sizeof dcl_buf == 392 */

# 144 "/home/claude/cfront-3/src/print2.cpp"
Pbase b__7dcl_buf ;
Pname n__7dcl_buf ;
TOK left__7dcl_buf [20];

# 146 "/home/claude/cfront-3/src/print2.cpp"
TOK right__7dcl_buf [20];
Pnode rnode__7dcl_buf [20];
Pclass lnode__7dcl_buf [20];
int li__7dcl_buf ;

# 149 "/home/claude/cfront-3/src/print2.cpp"
int ri__7dcl_buf ;
bit cf__7dcl_buf ;
};

# 154 "/home/claude/cfront-3/src/print2.cpp"

# 156 "/home/claude/cfront-3/src/print2.cpp"

# 159 "/home/claude/cfront-3/src/print2.cpp"
static struct dcl_buf *tbufvec [10]= { ((struct dcl_buf *)0 )} ;

# 159 "/home/claude/cfront-3/src/print2.cpp"
static struct dcl_buf *tbuf = 0 ;

# 161 "/home/claude/cfront-3/src/print2.cpp"
static int freetbuf = 0 ;

# 75 "/home/claude/cfront-3/src/cfront.h"

# 587 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8basetypeFv (struct basetype *__0this );

# 79 "/home/claude/incl-linux32/stdio.h"
extern int fprintf (void *, const char *,...);

# 947 "/home/claude/cfront-3/src/cfront.h"
void print__4nameFUc (struct name *__0this , bit __1fullprint );

# 796 "/home/claude/cfront-3/src/cfront.h"
void print__4exprFv (struct expr *__0this );

# 638 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__3fctFv (struct fct *__0this );

# 266 "/home/claude/cfront-3/src/print2.cpp"
extern void print_body__FP3fct (Pfct );

# 163 "/home/claude/cfront-3/src/print2.cpp"
void put__7dcl_bufFv (register struct dcl_buf *__0this )
# 164 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 165 "/home/claude/cfront-3/src/print2.cpp"
int __1i ;
Pfct __1ff ;

# 266 "/home/claude/cfront-3/src/print2.cpp"

# 266 "/home/claude/cfront-3/src/print2.cpp"
const void *__2__X27 ;

# 166 "/home/claude/cfront-3/src/print2.cpp"
__1ff = 0 ;

# 168 "/home/claude/cfront-3/src/print2.cpp"
if ((20 <= __0this -> li__7dcl_buf )|| (20 <= __0this -> ri__7dcl_buf ))error__FiPCc ( (int )'i' , (const char *)"T buffer overflow")
# 168 "/home/claude/cfront-3/src/print2.cpp"
;

# 170 "/home/claude/cfront-3/src/print2.cpp"
if (((__0this -> n__7dcl_buf && __0this -> n__7dcl_buf -> n_sto__4name )&& (__0this -> n__7dcl_buf -> n_sto__4name != 27 ))&& (__0this -> n__7dcl_buf -> n_sto__4name != 2 ))puttok__FUc (
# 170 "/home/claude/cfront-3/src/print2.cpp"
__0this -> n__7dcl_buf -> n_sto__4name ) ;

# 172 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> b__7dcl_buf == 0 )
# 180 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 180 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V26 ;

# 180 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"noBT%s", (const struct ea *)( (__2__X27 =
# 180 "/home/claude/cfront-3/src/print2.cpp"
(const void *)(Cast ?" in cast":(((char *)"")))), ( ((&
# 180 "/home/claude/cfront-3/src/print2.cpp"
__0__V26 )-> __O1__2ea.p = __2__X27 ), (& __0__V26 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const
# 180 "/home/claude/cfront-3/src/print2.cpp"
struct ea *)ea0 ) ;
} else 
# 182 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 183 "/home/claude/cfront-3/src/print2.cpp"
bit __2ac_save ;
if (__0this -> cf__7dcl_buf ){ 
# 185 "/home/claude/cfront-3/src/print2.cpp"
__2ac_save = __0this -> b__7dcl_buf -> ansi_const__4type ;
__0this -> b__7dcl_buf -> ansi_const__4type = 1 ;
}
dcl_print__8basetypeFv ( __0this -> b__7dcl_buf ) ;
if (__0this -> cf__7dcl_buf )
# 190 "/home/claude/cfront-3/src/print2.cpp"
__0this -> b__7dcl_buf -> ansi_const__4type = __2ac_save ;
}

# 193 "/home/claude/cfront-3/src/print2.cpp"
for(;__0this -> li__7dcl_buf ;__0this -> li__7dcl_buf -- ) { 
# 194 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> left__7dcl_buf [__0this -> li__7dcl_buf ]){ 
# 195 "/home/claude/cfront-3/src/print2.cpp"
case 40 :
# 196 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'(' , out_file )
# 196 "/home/claude/cfront-3/src/print2.cpp"
;
break ;
case 125 :
# 199 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'*' , out_file ) ;
break ;
case 158 :
# 202 "/home/claude/cfront-3/src/print2.cpp"
if (emode )
# 203 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'&' , out_file ) ;
else 
# 205 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'*' , out_file ) ;
break ;
case 163 :
# 208 "/home/claude/cfront-3/src/print2.cpp"
if (emode || (ansi_opt && (Cast == 0 )))
# 209 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"*const ", out_file )
# 209 "/home/claude/cfront-3/src/print2.cpp"
;
else 
# 211 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'*' , out_file ) ;
break ;
case 164 :
# 214 "/home/claude/cfront-3/src/print2.cpp"
if (emode )
# 215 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"&const ", out_file ) ;
else if (ansi_opt && (Cast == 0 ))
# 217 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"*const ", out_file ) ;
# 217 "/home/claude/cfront-3/src/print2.cpp"
else 
# 219 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'*' , out_file ) ;
break ;
case 173 :
# 222 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> lnode__7dcl_buf [__0this -> li__7dcl_buf ])fprintf ( out_file , (const char *)"%s::", (__0this ->
# 222 "/home/claude/cfront-3/src/print2.cpp"
lnode__7dcl_buf [__0this -> li__7dcl_buf ])-> string__8classdef ) ;
}
}

# 226 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> n__7dcl_buf )print__4nameFUc ( __0this -> n__7dcl_buf , (unsigned char )0 ) ;

# 228 "/home/claude/cfront-3/src/print2.cpp"
for(__1i = 1 ;__1i <= __0this -> ri__7dcl_buf ;__1i ++ ) { 
# 229 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> right__7dcl_buf [__1i ]){ 
# 230 "/home/claude/cfront-3/src/print2.cpp"
case 41 :
# 231 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )')' , out_file )
# 231 "/home/claude/cfront-3/src/print2.cpp"
;
break ;
case 110 :
# 234 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'[' , out_file ) ;
{ Pvec __4v ;
Pexpr __4d ;
int __4s ;

# 235 "/home/claude/cfront-3/src/print2.cpp"
__4v = (((struct vec *)(((struct vec *)(__0this -> rnode__7dcl_buf [__1i ])))));
__4d = __4v -> dim__3vec ;
__4s = __4v -> size__3vec ;
if (__4d )print__4exprFv ( __4d ) ;
if (__4s )fprintf ( out_file , (const char *)"%d", __4s ) ;
}
fputc ( (int )']' , out_file ) ;
break ;
case 108 :
# 245 "/home/claude/cfront-3/src/print2.cpp"
{ Pfct __4f ;

# 245 "/home/claude/cfront-3/src/print2.cpp"
__4f = (((struct fct *)(((struct fct *)(__0this -> rnode__7dcl_buf [__1i ])))));
if (__4f -> body__3fct )__1ff = __4f ;
dcl_print__3fctFv ( __4f ) ;
break ;
}
case 114 :
# 251 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 252 "/home/claude/cfront-3/src/print2.cpp"
Pbase __4f ;
Pexpr __4d ;
int __4s ;

# 252 "/home/claude/cfront-3/src/print2.cpp"
__4f = (((struct basetype *)(((struct basetype *)(__0this -> rnode__7dcl_buf [__1i ])))));
__4d = (((struct expr *)(((struct expr *)__4f -> b_name__8basetype ))));
__4s = __4f -> b_bits__8basetype ;
fputc ( (int )':' , out_file ) ;
if (__4d )
# 257 "/home/claude/cfront-3/src/print2.cpp"
print__4exprFv ( __4d ) ;
else if (__4s )
# 259 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%d", __4s ) ;
else 
# 261 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )86 ) ;
break ;
}
}
}
;
if (__1ff && (emode == 0 ))print_body__FP3fct ( __1ff ) ;
}

# 270 "/home/claude/cfront-3/src/print2.cpp"
Pexpr mk_zero_init__FP4typeP4nameT2 (Ptype __1tt , Pname __1obname , Pname __1currname );

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 359 "/home/claude/cfront-3/src/cfront.h"
Pfct memptr__4typeFv (struct type *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 270 "/home/claude/cfront-3/src/print2.cpp"
Pexpr mk_zero_init__FP4typeP4nameT2 (Ptype __1tt , Pname __1obname , Pname __1currname )
# 275 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 276 "/home/claude/cfront-3/src/print2.cpp"
if (dtpt_opt && mk_zero_init_flag )
# 277 "/home/claude/cfront-3/src/print2.cpp"
return (struct expr *)0 ;

# 279 "/home/claude/cfront-3/src/print2.cpp"
__1tt = skiptypedefs__4typeFv ( __1tt ) ;

# 281 "/home/claude/cfront-3/src/print2.cpp"
switch (__1tt -> base__4node ){ 
# 282 "/home/claude/cfront-3/src/print2.cpp"
case 110 :
# 283 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 284 "/home/claude/cfront-3/src/print2.cpp"
if ((__1obname == __1currname )&& (! ispt_data__FP4name ( __1obname ) )){ 
# 286 "/home/claude/cfront-3/src/print2.cpp"
return (struct
# 286 "/home/claude/cfront-3/src/print2.cpp"
expr *)0 ;
}
else { 
# 289 "/home/claude/cfront-3/src/print2.cpp"
Pexpr __4i ;

# 289 "/home/claude/cfront-3/src/print2.cpp"
__4i = mk_zero_init__FP4typeP4nameT2 ( (((struct vec *)(((struct vec *)__1tt ))))-> typ__5pvtyp , __1obname , __1currname ) ;
if (__4i == 0 )return (struct expr *)0 ;
return __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , __4i , (struct expr *)0 ) ;
}
}
case 119 :
# 295 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 296 "/home/claude/cfront-3/src/print2.cpp"
Pclass __3cl ;

# 296 "/home/claude/cfront-3/src/print2.cpp"
__3cl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1tt ))))-> b_name__8basetype -> __O1__4expr.tp ))));
if ((! ansi_opt )&& ((__3cl -> csu__8classdef == 167 )|| (__3cl -> csu__8classdef == 36 ))){ 
# 298 "/home/claude/cfront-3/src/print2.cpp"
if (warning_opt ){ 
# 301 "/home/claude/cfront-3/src/print2.cpp"
Ptype __5tn ;

# 301 "/home/claude/cfront-3/src/print2.cpp"
__5tn = __1obname -> __O1__4expr.tp ;
for(;;) 
# 303 "/home/claude/cfront-3/src/print2.cpp"
if (__5tn -> base__4node == 110 )
# 304 "/home/claude/cfront-3/src/print2.cpp"
__5tn = (((struct vec *)(((struct vec *)__5tn ))))-> typ__5pvtyp ;
else 
# 306 "/home/claude/cfront-3/src/print2.cpp"
break ;
if ((__1obname == __1currname )&& (__1tt == __5tn )){ 
# 308 "/home/claude/cfront-3/src/print2.cpp"
if (((__3cl -> string__8classdef [0 ])== '_' )&& ((__3cl -> string__8classdef [1 ])== '_' ))
# 309 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 309 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V28 ;
# 309 "/home/claude/cfront-3/src/print2.cpp"

# 309 "/home/claude/cfront-3/src/print2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __1obname -> where__4name , (const char *)"cannot generate zeroIr for%n ofT union; toI, compile with +a1 or insert non-union object as first member", (const
# 309 "/home/claude/cfront-3/src/print2.cpp"
struct ea *)( ((& __0__V28 )-> __O1__2ea.p = ((const void *)__1obname )), (& __0__V28 )) , (const struct ea *)ea0 ,
# 309 "/home/claude/cfront-3/src/print2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 311 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 311 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V29 ;

# 311 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V30 ;

# 311 "/home/claude/cfront-3/src/print2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __1obname -> where__4name , (const char *)"cannot generate zeroIr for%n ofT%t; toI, compile with +a1 or insert non-union object as first member", (const
# 311 "/home/claude/cfront-3/src/print2.cpp"
struct ea *)( ((& __0__V29 )-> __O1__2ea.p = ((const void *)__1obname )), (& __0__V29 )) , (const struct ea *)__ct__2eaFPCv (
# 311 "/home/claude/cfront-3/src/print2.cpp"
& __0__V30 , (const void *)__1obname -> __O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 311 "/home/claude/cfront-3/src/print2.cpp"
} 
# 312 "/home/claude/cfront-3/src/print2.cpp"
}
else { 
# 314 "/home/claude/cfront-3/src/print2.cpp"
Pclass __6cx ;
if ((((__5tn -> base__4node == 119 )&& (__6cx = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__5tn ))))-> b_name__8basetype -> __O1__4expr.tp ))))))&& ((__6cx -> string__8classdef [0 ])==
# 315 "/home/claude/cfront-3/src/print2.cpp"
'_' ))&& ((__6cx -> string__8classdef [1 ])== '_' ))
# 324 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 324 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V31 ;

# 324 "/home/claude/cfront-3/src/print2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __1obname -> where__4name , (const char *)"cannot generate zeroIr for%n (union or aggregate with union as first element); toI, compile with +a1 or insert non-union object as first member", (const
# 324 "/home/claude/cfront-3/src/print2.cpp"
struct ea *)( ((& __0__V31 )-> __O1__2ea.p = ((const void *)__1obname )), (& __0__V31 )) , (const struct ea *)ea0 ,
# 324 "/home/claude/cfront-3/src/print2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 326 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 326 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V32 ;

# 326 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V33 ;

# 326 "/home/claude/cfront-3/src/print2.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'w' , & __1obname -> where__4name , (const char *)"cannot generate zeroIr for%n ofT%t (union or aggregate with union as first element); toI, compile with +a1 or insert non-union object as first member", (const
# 326 "/home/claude/cfront-3/src/print2.cpp"
struct ea *)( ((& __0__V32 )-> __O1__2ea.p = ((const void *)__1obname )), (& __0__V32 )) , (const struct ea *)__ct__2eaFPCv (
# 326 "/home/claude/cfront-3/src/print2.cpp"
& __0__V33 , (const void *)__1obname -> __O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 326 "/home/claude/cfront-3/src/print2.cpp"
} 
# 327 "/home/claude/cfront-3/src/print2.cpp"
}
}
return (struct expr *)0 ;
}
{ Pbcl __3l ;

# 331 "/home/claude/cfront-3/src/print2.cpp"
__3l = __3cl -> baselist__8classdef ;
while (__3l ){ 
# 333 "/home/claude/cfront-3/src/print2.cpp"
if (__3l -> base__4node == 85 )__3cl = __3l -> bclass__6basecl ;
else return __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , zero , (struct expr *)0 ) ;
__3l = __3cl -> baselist__8classdef ;
}
{ int __3i ;
Pname __3nn ;

# 339 "/home/claude/cfront-3/src/print2.cpp"
struct table *__0__X34 ;

# 339 "/home/claude/cfront-3/src/print2.cpp"
int __2__X35 ;

# 339 "/home/claude/cfront-3/src/print2.cpp"
struct table *__0__X36 ;

# 337 "/home/claude/cfront-3/src/print2.cpp"
__3i = 1 ;
__3nn = ( (__0__X36 = __3cl -> memtbl__8classdef ), ( (((__3i <= 0 )|| (__0__X36 -> free_slot__5table <= __3i ))?(((struct name *)0 )):(__0__X36 -> entries__5table [__3i ]))) )
# 338 "/home/claude/cfront-3/src/print2.cpp"
;
for(;__3nn ;__3nn = (__3nn -> n_tbl_list__4name ?__3nn -> n_tbl_list__4name :( (__0__X34 = __3cl -> memtbl__8classdef ), ( (__2__X35 = (++ __3i )), ( (((__2__X35 <= 0 )||
# 339 "/home/claude/cfront-3/src/print2.cpp"
(__0__X34 -> free_slot__5table <= __2__X35 ))?(((struct name *)0 )):(__0__X34 -> entries__5table [__2__X35 ]))) ) ) )) { 
# 340 "/home/claude/cfront-3/src/print2.cpp"
if ((__3nn -> base__4node == 123 )|| (__3nn ->
# 340 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp == 0 ))continue ;
{ Ptype __4tx ;

# 341 "/home/claude/cfront-3/src/print2.cpp"
__4tx = skiptypedefs__4typeFv ( __3nn -> __O1__4expr.tp ) ;
if ((((((((__3nn -> base__4node == 85 )&& (__3nn -> n_anon__4name == 0 ))&& (__4tx -> base__4node != 108 ))&& (__4tx -> base__4node != 76 ))&& (__4tx ->
# 342 "/home/claude/cfront-3/src/print2.cpp"
base__4node != 6 ))&& (__4tx -> base__4node != 13 ))&& (__3nn -> n_stclass__4name != 31 ))&& (__3nn -> n_stclass__4name != 13 ))
# 349 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 350 "/home/claude/cfront-3/src/print2.cpp"
Pexpr __5i ;

# 350 "/home/claude/cfront-3/src/print2.cpp"
__5i = mk_zero_init__FP4typeP4nameT2 ( __4tx , __1obname , __3nn ) ;
if (__5i == 0 )return (struct expr *)0 ;
return __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , __5i , (struct expr *)0 ) ;
}

# 353 "/home/claude/cfront-3/src/print2.cpp"
}
}
return (struct expr *)0 ;

# 355 "/home/claude/cfront-3/src/print2.cpp"
}

# 355 "/home/claude/cfront-3/src/print2.cpp"
}
}
case 125 :
# 358 "/home/claude/cfront-3/src/print2.cpp"
if (memptr__4typeFv ( __1tt ) ){ 
# 359 "/home/claude/cfront-3/src/print2.cpp"
Pexpr __3i ;

# 359 "/home/claude/cfront-3/src/print2.cpp"
__3i = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , zero ) ;
return __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , __3i , zero ) ;
}

# 363 "/home/claude/cfront-3/src/print2.cpp"
case 158 :
# 364 "/home/claude/cfront-3/src/print2.cpp"
case 5 :
# 365 "/home/claude/cfront-3/src/print2.cpp"
case 29 :
# 366 "/home/claude/cfront-3/src/print2.cpp"
case 21 :
# 367 "/home/claude/cfront-3/src/print2.cpp"
case 121 :
# 368 "/home/claude/cfront-3/src/print2.cpp"
case 22 :
# 369 "/home/claude/cfront-3/src/print2.cpp"
case 122 :
# 370 "/home/claude/cfront-3/src/print2.cpp"
case 15 :
# 371 "/home/claude/cfront-3/src/print2.cpp"
case 11 :
# 372 "/home/claude/cfront-3/src/print2.cpp"
case 181 :
# 373 "/home/claude/cfront-3/src/print2.cpp"
case 114 :
# 374 "/home/claude/cfront-3/src/print2.cpp"
case 141 :
# 375 "/home/claude/cfront-3/src/print2.cpp"
return zero ;
# 375 "/home/claude/cfront-3/src/print2.cpp"

# 376 "/home/claude/cfront-3/src/print2.cpp"
}
return (struct expr *)0 ;
}

# 338 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4typeFP4name (struct type *__0this , Pname );

# 380 "/home/claude/cfront-3/src/print2.cpp"
void arg_print__3fctFv (register struct fct *__0this )
# 382 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 383 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'(' , out_file ) ;
{ { Pname __1nn ;

# 384 "/home/claude/cfront-3/src/print2.cpp"
__1nn = __0this -> argtype__3fct ;

# 384 "/home/claude/cfront-3/src/print2.cpp"
for(;__1nn ;) { 
# 385 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__4typeFP4name ( __1nn -> __O1__4expr.tp , (struct name *)0 ) ;
if (__1nn = __1nn -> __O1__4name.n_list )
# 387 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )71 ) ;
else 
# 389 "/home/claude/cfront-3/src/print2.cpp"
break ;
}
switch (__0this -> nargs_known__3fct ){ 
# 392 "/home/claude/cfront-3/src/print2.cpp"
case 0 :
# 393 "/home/claude/cfront-3/src/print2.cpp"
case 155 :puttok__FUc ( (unsigned char )155 ) ;

# 393 "/home/claude/cfront-3/src/print2.cpp"
break ;
}

# 396 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )')' , out_file ) ;

# 398 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> f_const__3fct )
# 399 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )26 ) ;
if (__0this -> f_static__3fct )
# 401 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )31 ) ;

# 401 "/home/claude/cfront-3/src/print2.cpp"
}

# 401 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 335 "/home/claude/cfront-3/src/cfront.h"
Ptype skiptypedefs__4typeFRUc (struct type *__0this , bit *__1isconst );

# 449 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8classdefFP4name (struct classdef *__0this , Pname );

# 375 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__7enumdefFP4name (struct enumdef *__0this , Pname );

# 1279 "/home/claude/cfront-3/src/cfront.h"

# 1224 "/home/claude/cfront-3/src/cfront.h"
extern void make_res__FP3fct (Pfct );

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 942 "/home/claude/cfront-3/src/cfront.h"

# 477 "/home/claude/cfront-3/src/cfront.h"
void print_all_vtbls__8classdefFP8classdef (struct classdef *__0this , Pclass );

# 405 "/home/claude/cfront-3/src/print2.cpp"
void dcl_print__4nameFUc (struct name *__0this , TOK __1list );

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 468 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 337 "/home/claude/cfront-3/src/cfront.h"
void print__4typeFv (struct type *__0this );

# 1247 "/home/claude/cfront-3/src/cfront.h"
extern void Eprint__FP4expr (Pexpr );

# 344 "/home/claude/cfront-3/src/cfront.h"
bit is_unsigned__4typeFv (struct type *__0this );

# 405 "/home/claude/cfront-3/src/print2.cpp"
void dcl_print__4nameFUc (register struct name *__0this , TOK __1list )
# 418 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 419 "/home/claude/cfront-3/src/print2.cpp"
if (error_count )return ;

# 423 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> n_stclass__4name == 31 )
# 424 "/home/claude/cfront-3/src/print2.cpp"
__0this -> __O1__4expr.tp -> ansi_const__4type = 1 ;

# 426 "/home/claude/cfront-3/src/print2.cpp"
{ { Pname __1n ;

# 426 "/home/claude/cfront-3/src/print2.cpp"
__1n = __0this ;

# 426 "/home/claude/cfront-3/src/print2.cpp"
for(;__1n ;__1n = __1n -> __O1__4name.n_list ) { 
# 427 "/home/claude/cfront-3/src/print2.cpp"
Ptype __2t ;
int __2sm ;

# 427 "/home/claude/cfront-3/src/print2.cpp"
__2t = __1n -> __O1__4expr.tp ;
__2sm = 0 ;

# 430 "/home/claude/cfront-3/src/print2.cpp"
if (__2t == 0 ){ 
# 430 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V37 ;

# 430 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::dcl_print(%n)T missing", (const struct ea *)( ((&
# 430 "/home/claude/cfront-3/src/print2.cpp"
__0__V37 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V37 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 430 "/home/claude/cfront-3/src/print2.cpp"
(const struct ea *)ea0 ) ;
} 
# 432 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> n_stclass__4name == 13 )if (__1list )continue ;
else 
# 432 "/home/claude/cfront-3/src/print2.cpp"
return ;

# 434 "/home/claude/cfront-3/src/print2.cpp"
if ((__1n -> where__4name . line__3loc != last_line . line__3loc )|| (__1n -> where__4name . file__3loc != last_line . file__3loc ))
# 435 "/home/claude/cfront-3/src/print2.cpp"
if (last_ll = __1n -> where__4name .
# 435 "/home/claude/cfront-3/src/print2.cpp"
line__3loc )
# 436 "/home/claude/cfront-3/src/print2.cpp"
putline__3locFv ( & __1n -> where__4name ) ;
else 
# 438 "/home/claude/cfront-3/src/print2.cpp"
putline__3locFv ( & last_line ) ;

# 440 "/home/claude/cfront-3/src/print2.cpp"
{ bit __2tc ;
Ptype __2tt ;

# 440 "/home/claude/cfront-3/src/print2.cpp"
__2tc = 0 ;
__2tt = skiptypedefs__4typeFRUc ( __2t , (bit *)(& __2tc )) ;

# 443 "/home/claude/cfront-3/src/print2.cpp"
switch (__2t -> base__4node ){ 
# 444 "/home/claude/cfront-3/src/print2.cpp"
case 6 :
# 445 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> base__4node != 123 ){ 
# 446 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__8classdefFP4name ( ((struct classdef *)(((struct classdef *)__2t ))), __1n ) ;
# 446 "/home/claude/cfront-3/src/print2.cpp"

# 447 "/home/claude/cfront-3/src/print2.cpp"
}
__2sm = 1 ;
break ;

# 451 "/home/claude/cfront-3/src/print2.cpp"
case 13 :
# 452 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__7enumdefFP4name ( ((struct enumdef *)(((struct enumdef *)__2t ))), (struct name *)0 ) ;
__2sm = 1 ;
break ;

# 456 "/home/claude/cfront-3/src/print2.cpp"
case 108 :
# 457 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 458 "/home/claude/cfront-3/src/print2.cpp"
Pfct __4f ;

# 459 "/home/claude/cfront-3/src/print2.cpp"
int __1__Xt00a3w1ovbwvcnm ;

# 458 "/home/claude/cfront-3/src/print2.cpp"
__4f = (((struct fct *)(((struct fct *)__2t ))));

# 463 "/home/claude/cfront-3/src/print2.cpp"
if ((((((dtpt_opt && (all_flag == 0 ))&& (curloc . file__3loc != first_file ))&& (__4f -> f_inline__3fct == 0 ))&& (__4f -> f_is_inline__3fct == 0 ))&& (!
# 463 "/home/claude/cfront-3/src/print2.cpp"
((__1n -> n_sto__4name == 31 )&& (! __1n -> n_stclass__4name ))))&& (none_flag == 0 ))
# 470 "/home/claude/cfront-3/src/print2.cpp"
__4f -> body__3fct = 0 ;

# 472 "/home/claude/cfront-3/src/print2.cpp"
if (( (__1__Xt00a3w1ovbwvcnm = ((__2t -> base__4node == 108 )?(((struct fct *)(((struct fct *)__2t ))))-> fct_base__3fct :((__2t -> base__4node == 6 )?(((struct classdef *)(((struct classdef *)__2t ))))-> class_base__8classdef :(((int
# 472 "/home/claude/cfront-3/src/print2.cpp"
)0 ))))), (((unsigned char )((__1__Xt00a3w1ovbwvcnm == 4)|| (__1__Xt00a3w1ovbwvcnm == 5))))) && (current_fct_instantiation != __4f ))
# 474 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 475 "/home/claude/cfront-3/src/print2.cpp"
if (((__1n -> n_addr_taken__4name == 1 )&&
# 475 "/home/claude/cfront-3/src/print2.cpp"
(current_fct_instantiation == 0 ))&& (__4f -> f_inline__3fct || __4f -> last_expanded__3fct ))
# 480 "/home/claude/cfront-3/src/print2.cpp"
;
else return ;
}

# 484 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> base__4node == 123 )puttok__FUc ( (unsigned char )35 ) ;

# 486 "/home/claude/cfront-3/src/print2.cpp"
if ((__1n -> n_dcl_printed__4name == 2 )|| ((__1n -> n_dcl_printed__4name == 1 )&& (__4f -> body__3fct == 0 )))
# 490 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 492 "/home/claude/cfront-3/src/print2.cpp"
__2sm = 1 ;
break ;
}

# 496 "/home/claude/cfront-3/src/print2.cpp"
if (__4f -> f_result__3fct == 0 )make_res__FP3fct ( __4f ) ;

# 498 "/home/claude/cfront-3/src/print2.cpp"
if (__4f -> body__3fct && (__1n -> n_sto__4name == 14 ))__1n -> n_sto__4name = 0 ;

# 500 "/home/claude/cfront-3/src/print2.cpp"
if (__4f -> f_inline__3fct && ((__1n -> __O4__4expr.n_table != gtbl )|| strcmp ( __1n -> __O2__4expr.string , (const char *)"main")
# 500 "/home/claude/cfront-3/src/print2.cpp"
))
# 504 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 505 "/home/claude/cfront-3/src/print2.cpp"
if (debug_opt ){ 
# 506 "/home/claude/cfront-3/src/print2.cpp"
if (((__4f -> defined__4type & 01 )&& (__4f -> defined__4type & 02 ))&& (__4f -> f_inline__3fct != 77 ))
# 513 "/home/claude/cfront-3/src/print2.cpp"
goto prnt_def ;
# 513 "/home/claude/cfront-3/src/print2.cpp"
else 
# 514 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> n_dcl_printed__4name == 0 )
# 515 "/home/claude/cfront-3/src/print2.cpp"
goto prnt_dcl ;
else { 
# 517 "/home/claude/cfront-3/src/print2.cpp"
__2sm = 1 ;
break ;
}
}
if (__4f -> f_virtual__3fct || __1n -> n_addr_taken__4name ){ 
# 522 "/home/claude/cfront-3/src/print2.cpp"
prnt_dcl :
# 523 "/home/claude/cfront-3/src/print2.cpp"
{ TOK __6st ;
Pblock __6b ;

# 523 "/home/claude/cfront-3/src/print2.cpp"
__6st = __1n -> n_sto__4name ;
__6b = __4f -> body__3fct ;
__4f -> body__3fct = 0 ;
dcl_print__4typeFP4name ( __2t , __1n ) ;
__1n -> n_dcl_printed__4name = 1 ;
__1n -> n_sto__4name = __6st ;
__4f -> body__3fct = __6b ;
break ;

# 530 "/home/claude/cfront-3/src/print2.cpp"
}
}
else 
# 533 "/home/claude/cfront-3/src/print2.cpp"
__2sm = 1 ;
}
else if (((__4f -> defined__4type & 01 )== 0 )|| ((__4f -> defined__4type & 02 )== 0 ))
# 540 "/home/claude/cfront-3/src/print2.cpp"
goto prnt_dcl ;
else if ((__1n -> __O4__4expr.n_table == gtbl )&& (strcmp ( __1n -> __O2__4expr.string , (const char *)"main")
# 541 "/home/claude/cfront-3/src/print2.cpp"
== 0 ))
# 545 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 545 "/home/claude/cfront-3/src/print2.cpp"
struct name *__0__X38 ;

# 546 "/home/claude/cfront-3/src/print2.cpp"
if (__4f -> f_inline__3fct ){ 
# 547 "/home/claude/cfront-3/src/print2.cpp"
error__FP3locPCcRC2eaN33 ( & __1n -> where__4name , (const char *)"main() cannot be declared inline",
# 547 "/home/claude/cfront-3/src/print2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__4f -> f_inline__3fct = 0 ;
__1n -> n_sto__4name = 0 ;
}
if (__1n -> n_sto__4name == 31 ){ 
# 552 "/home/claude/cfront-3/src/print2.cpp"
error__FP3locPCcRC2eaN33 ( & __1n -> where__4name , (const char *)"main() cannot be declared static",
# 552 "/home/claude/cfront-3/src/print2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1n -> n_sto__4name = 0 ;
}
MAIN = 1 ;
( (__0__X38 = look__5tableFPCcUc ( gtbl , (const char *)"main", (unsigned char )0 )
# 556 "/home/claude/cfront-3/src/print2.cpp"
), ( (__0__X38 -> n_used__4name ++ ), (((void )0 ))) ) ;
__4f -> f_signature__3fct = 0 ;
dcl_print__4typeFP4name ( __2t , __1n ) ;
__1n -> n_dcl_printed__4name = (__4f -> body__3fct ?2 :1 );
MAIN = 0 ;
}
else { 
# 563 "/home/claude/cfront-3/src/print2.cpp"
prnt_def :
# 564 "/home/claude/cfront-3/src/print2.cpp"
if ((__1n -> n_oper__4name == 161 )|| (__1n -> n_oper__4name == 162 )){ 
# 565 "/home/claude/cfront-3/src/print2.cpp"
Pclass __6cl ;

# 565 "/home/claude/cfront-3/src/print2.cpp"
__6cl = (((struct classdef *)(((struct classdef *)__1n -> __O4__4expr.n_table -> t_name__5table -> __O1__4expr.tp ))));
if (__6cl -> c_body__8classdef == 3 )print_all_vtbls__8classdefFP8classdef ( __6cl , __6cl ) ;
}

# 569 "/home/claude/cfront-3/src/print2.cpp"
if (((__1n -> n_sto__4name == 31 )&& (pdef_name == 0 ))&& (def_name == 0 ))
# 575 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 576 "/home/claude/cfront-3/src/print2.cpp"
pdef_name = __1n ;
if (last_ll = __1n -> where__4name . line__3loc )
# 578 "/home/claude/cfront-3/src/print2.cpp"
putline__3locFv ( & __1n -> where__4name ) ;
else 
# 580 "/home/claude/cfront-3/src/print2.cpp"
putline__3locFv ( & last_line ) ;
}
dcl_print__4typeFP4name ( __2t , __1n ) ;
__1n -> n_dcl_printed__4name = (__4f -> body__3fct ?2 :1 );
}
if (__4f -> body__3fct )__2sm = 1 ;
break ;
}

# 589 "/home/claude/cfront-3/src/print2.cpp"
case 76 :
# 590 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 591 "/home/claude/cfront-3/src/print2.cpp"
{ { Plist __4gl ;

# 591 "/home/claude/cfront-3/src/print2.cpp"
__4gl = (((struct gen *)(((struct gen *)__2t ))))-> fct_list__3gen ;

# 591 "/home/claude/cfront-3/src/print2.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) { 
# 592 "/home/claude/cfront-3/src/print2.cpp"
Pname __5nn ;
Pfct __5f ;

# 592 "/home/claude/cfront-3/src/print2.cpp"
__5nn = __4gl -> f__9name_list ;
__5f = (((struct fct *)(((struct fct *)__5nn -> __O1__4expr.tp ))));
if (__5f -> defined__4type )dcl_print__4nameFUc ( __5nn , (unsigned char )0 ) ;
__2sm = 1 ;
}
break ;

# 597 "/home/claude/cfront-3/src/print2.cpp"
}

# 597 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 600 "/home/claude/cfront-3/src/print2.cpp"
case 1 :
# 601 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"asm(\"%s\")\n", ((char *)(((struct basetype *)(((struct basetype *)__2t ))))->
# 601 "/home/claude/cfront-3/src/print2.cpp"
b_name__8basetype )) ;
break ;

# 604 "/home/claude/cfront-3/src/print2.cpp"
case 21 :
# 605 "/home/claude/cfront-3/src/print2.cpp"
case 121 :
# 606 "/home/claude/cfront-3/src/print2.cpp"
case 5 :
# 607 "/home/claude/cfront-3/src/print2.cpp"
case 22 :
# 608 "/home/claude/cfront-3/src/print2.cpp"
case 122 :
# 609 "/home/claude/cfront-3/src/print2.cpp"
case 29 :
# 610 "/home/claude/cfront-3/src/print2.cpp"
tcx :
# 614 "/home/claude/cfront-3/src/print2.cpp"
if ((__2tc && (__1n -> n_sto__4name != 14 ))&& (((__1n -> n_scope__4name == 14 )||
# 614 "/home/claude/cfront-3/src/print2.cpp"
(__1n -> n_scope__4name == 31 ))|| (__1n -> n_scope__4name == 108 )))
# 630 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 631 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> n_evaluated__4name && (__1n -> n_addr_taken__4name == 0 )){ 
# 632 "/home/claude/cfront-3/src/print2.cpp"
__2sm = 1 ;
# 632 "/home/claude/cfront-3/src/print2.cpp"

# 633 "/home/claude/cfront-3/src/print2.cpp"
break ;
}
}
__2tc = 0 ;

# 640 "/home/claude/cfront-3/src/print2.cpp"
default :
# 641 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 644 "/home/claude/cfront-3/src/print2.cpp"
Pexpr __4saveinit ;
TOK __4savesto ;

# 647 "/home/claude/cfront-3/src/print2.cpp"
Pexpr __4i ;

# 644 "/home/claude/cfront-3/src/print2.cpp"
__4saveinit = __1n -> __O3__4expr.n_initializer ;
__4savesto = __1n -> n_sto__4name ;

# 647 "/home/claude/cfront-3/src/print2.cpp"
__4i = __1n -> __O3__4expr.n_initializer ;
if ((__1n -> base__4node == 123 )&& __1n -> __O3__4expr.tpdef )__4i = 0 ;

# 650 "/home/claude/cfront-3/src/print2.cpp"
if ((((dtpt_opt && (all_flag == 0 ))&& (__1n -> n_scope__4name != 31 ))&& (none_flag == 0 ))&& (curloc . file__3loc != first_file ))
# 656 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 657 "/home/claude/cfront-3/src/print2.cpp"
if ((__1n ->
# 657 "/home/claude/cfront-3/src/print2.cpp"
base__4node == 123 )&& __1n -> __O3__4expr.tpdef )
# 658 "/home/claude/cfront-3/src/print2.cpp"
;
else { 
# 660 "/home/claude/cfront-3/src/print2.cpp"
__1n -> __O3__4expr.n_initializer = (__4i = 0 );
mk_zero_init_flag = 1 ;
if ((__1n -> n_scope__4name == 14 )&& ((((struct basetype *)(((struct basetype *)__2t ))))-> b_const__4type == 0 ))
# 663 "/home/claude/cfront-3/src/print2.cpp"
__1n -> n_sto__4name = 14 ;
}
}

# 667 "/home/claude/cfront-3/src/print2.cpp"
if (__2tc ){ 
# 668 "/home/claude/cfront-3/src/print2.cpp"
switch (__2tt -> base__4node ){ 
# 669 "/home/claude/cfront-3/src/print2.cpp"
case 5 :
# 670 "/home/claude/cfront-3/src/print2.cpp"
case 29 :
# 671 "/home/claude/cfront-3/src/print2.cpp"
case 21 :
# 672 "/home/claude/cfront-3/src/print2.cpp"
case 22 :
# 673 "/home/claude/cfront-3/src/print2.cpp"
case 122 :
# 674 "/home/claude/cfront-3/src/print2.cpp"
case 121 :
# 675 "/home/claude/cfront-3/src/print2.cpp"
goto tcx ;
}
}

# 679 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> base__4node == 123 ){ 
# 684 "/home/claude/cfront-3/src/print2.cpp"
if (! __0this -> n_template_arg__4name ){ 
# 688 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> lex_level__4name )return ;
}
puttok__FUc ( (unsigned char )35 ) ;
}

# 693 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> n_stclass__4name == 27 ){ 
# 696 "/home/claude/cfront-3/src/print2.cpp"
Pname __5cln ;

# 696 "/home/claude/cfront-3/src/print2.cpp"
__5cln = is_cl_obj__4typeFv ( __1n -> __O1__4expr.tp ) ;
if (__5cln ){ 
# 698 "/home/claude/cfront-3/src/print2.cpp"
Pclass __6cl ;

# 698 "/home/claude/cfront-3/src/print2.cpp"
__6cl = (((struct classdef *)(((struct classdef *)__5cln -> __O1__4expr.tp ))));
if (((((__6cl -> csu__8classdef != 6 )&& (__6cl -> baselist__8classdef == 0 ))&& (( __6cl -> c_itor__8classdef ) == 0 ))&& (__6cl -> virt_count__8classdef ==
# 699 "/home/claude/cfront-3/src/print2.cpp"
0 ))&& (! __1n -> n_addr_taken__4name ))
# 710 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )27 ) ;
}
else if (! __1n -> n_addr_taken__4name )
# 713 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )27 ) ;
}

# 716 "/home/claude/cfront-3/src/print2.cpp"
if (__4i ){ 
# 717 "/home/claude/cfront-3/src/print2.cpp"
if ((__1n -> n_sto__4name == 14 )&& (__1n -> n_stclass__4name == 31 )){ 
# 718 "/home/claude/cfront-3/src/print2.cpp"
__1n -> __O3__4expr.n_initializer = 0 ;
dcl_print__4typeFP4name ( __2t , __1n ) ;
puttok__FUc ( (unsigned char )72 ) ;
__1n -> __O3__4expr.n_initializer = __4i ;
__1n -> n_sto__4name = 0 ;
dcl_print__4typeFP4name ( __2t , __1n ) ;
__1n -> n_sto__4name = 14 ;
}
else 
# 727 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__4typeFP4name ( __2t , __1n ) ;
if (__1n -> __O4__4expr.n_table ){ 
# 729 "/home/claude/cfront-3/src/print2.cpp"
Pname __6nn ;

# 729 "/home/claude/cfront-3/src/print2.cpp"
__6nn = look__5tableFPCcUc ( __1n -> __O4__4expr.n_table , __1n -> __O2__4expr.string , (unsigned char )0 ) ;
if (__6nn )
# 731 "/home/claude/cfront-3/src/print2.cpp"
__6nn -> n_dcl_printed__4name = 1 ;
else 
# 733 "/home/claude/cfront-3/src/print2.cpp"
__1n -> n_dcl_printed__4name = 1 ;
}
else 
# 736 "/home/claude/cfront-3/src/print2.cpp"
__1n -> n_dcl_printed__4name = 1 ;
}
else if (__1n -> n_evaluated__4name && (((struct basetype *)(((struct basetype *)__2t ))))-> b_const__4type ){ 
# 739 "/home/claude/cfront-3/src/print2.cpp"
if ((__1n -> n_sto__4name == 14 )&& (__1n -> n_stclass__4name ==
# 739 "/home/claude/cfront-3/src/print2.cpp"
31 )){ 
# 740 "/home/claude/cfront-3/src/print2.cpp"
int __6v ;

# 740 "/home/claude/cfront-3/src/print2.cpp"
__6v = __1n -> n_evaluated__4name ;
__1n -> n_evaluated__4name = 0 ;
dcl_print__4typeFP4name ( __2t , __1n ) ;
puttok__FUc ( (unsigned char )72 ) ;
if ((__1n -> where__4name . line__3loc != last_line . line__3loc )|| (__1n -> where__4name . file__3loc != last_line . file__3loc ))
# 745 "/home/claude/cfront-3/src/print2.cpp"
if (last_ll = __1n -> where__4name .
# 745 "/home/claude/cfront-3/src/print2.cpp"
line__3loc )
# 746 "/home/claude/cfront-3/src/print2.cpp"
putline__3locFv ( & __1n -> where__4name ) ;
else 
# 748 "/home/claude/cfront-3/src/print2.cpp"
putline__3locFv ( & last_line ) ;
__1n -> n_evaluated__4name = __6v ;
__1n -> n_sto__4name = 0 ;
dcl_print__4typeFP4name ( __2t , __1n ) ;
__1n -> n_sto__4name = 14 ;
}
else 
# 755 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__4typeFP4name ( __2t , __1n ) ;
if (__1n -> __O4__4expr.n_table ){ 
# 757 "/home/claude/cfront-3/src/print2.cpp"
Pname __6nn ;

# 757 "/home/claude/cfront-3/src/print2.cpp"
__6nn = look__5tableFPCcUc ( __1n -> __O4__4expr.n_table , __1n -> __O2__4expr.string , (unsigned char )0 ) ;
if (__6nn )
# 759 "/home/claude/cfront-3/src/print2.cpp"
__6nn -> n_dcl_printed__4name = 1 ;
else 
# 761 "/home/claude/cfront-3/src/print2.cpp"
__1n -> n_dcl_printed__4name = 1 ;
}
else 
# 764 "/home/claude/cfront-3/src/print2.cpp"
__1n -> n_dcl_printed__4name = 1 ;
}
else { 
# 767 "/home/claude/cfront-3/src/print2.cpp"
Ptype __5tempt ;

# 767 "/home/claude/cfront-3/src/print2.cpp"
__5tempt = skiptypedefs__4typeFv ( __2t ) ;
if (__5tempt -> base__4node == 119 ){ 
# 769 "/home/claude/cfront-3/src/print2.cpp"
Pname __6cln ;

# 769 "/home/claude/cfront-3/src/print2.cpp"
__6cln = is_cl_obj__4typeFv ( __1n -> __O1__4expr.tp ) ;
if (__6cln ){ 
# 771 "/home/claude/cfront-3/src/print2.cpp"
Pclass __7cl ;
Pname __7ctor ;

# 771 "/home/claude/cfront-3/src/print2.cpp"
__7cl = (((struct classdef *)(((struct classdef *)__6cln -> __O1__4expr.tp ))));
__7ctor = ( __7cl -> c_ctor__8classdef ) ;
if (((((__1n -> __O4__4expr.n_table != gtbl )&& (__1n -> n_sto__4name != 14 ))&& (__1n -> n_evaluated__4name == 0 ))&& (__0this -> n_stclass__4name == 31 ))&& __7ctor )
# 784 "/home/claude/cfront-3/src/print2.cpp"
__1n ->
# 784 "/home/claude/cfront-3/src/print2.cpp"
__O3__4expr.n_initializer = (__4i = mk_zero_init__FP4typeP4nameT2 ( __2t , __1n , __1n ) );
}
}
if (((((__1n -> n_sto__4name == 0 )|| (__1n -> n_val__4name && (__1n -> n_evaluated__4name == 0 )))&& (__0this -> n_stclass__4name == 31 ))&& (__1n -> n_sto__4name !=
# 787 "/home/claude/cfront-3/src/print2.cpp"
31 ))&& ((__1n -> __O4__4expr.n_table == gtbl )|| ispt_data__FP4name ( __1n ) ))
# 799 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 800 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> n_val__4name && (__1n -> n_evaluated__4name == 0 )){ 
# 804 "/home/claude/cfront-3/src/print2.cpp"
__1n ->
# 804 "/home/claude/cfront-3/src/print2.cpp"
n_sto__4name = 0 ;
}

# 807 "/home/claude/cfront-3/src/print2.cpp"
__1n -> __O3__4expr.n_initializer = (__4i = mk_zero_init__FP4typeP4nameT2 ( __2t , __1n , __1n ) );
}
dcl_print__4typeFP4name ( __2t , __1n ) ;
if (__1n -> __O4__4expr.n_table ){ 
# 811 "/home/claude/cfront-3/src/print2.cpp"
Pname __6nn ;

# 811 "/home/claude/cfront-3/src/print2.cpp"
__6nn = look__5tableFPCcUc ( __1n -> __O4__4expr.n_table , __1n -> __O2__4expr.string , (unsigned char )0 ) ;
if (__6nn )
# 813 "/home/claude/cfront-3/src/print2.cpp"
__6nn -> n_dcl_printed__4name = 1 ;
else 
# 815 "/home/claude/cfront-3/src/print2.cpp"
__1n -> n_dcl_printed__4name = 1 ;
}
else 
# 818 "/home/claude/cfront-3/src/print2.cpp"
__1n -> n_dcl_printed__4name = 1 ;
}

# 821 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> n_scope__4name != 136 ){ 
# 822 "/home/claude/cfront-3/src/print2.cpp"
if (__4i ){ 
# 823 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )70 ) ;

# 825 "/home/claude/cfront-3/src/print2.cpp"
{ Pexpr __6i2 ;

# 825 "/home/claude/cfront-3/src/print2.cpp"
__6i2 = __4i ;
while ((__6i2 -> base__4node == 113 )|| (__6i2 -> base__4node == 191 ))
# 827 "/home/claude/cfront-3/src/print2.cpp"
__6i2 = __6i2 -> __O2__4expr.e1 ;
if (__6i2 -> base__4node == 124 )__4i = __6i2 ;

# 830 "/home/claude/cfront-3/src/print2.cpp"
if (((__2t != __4i -> __O1__4expr.tp )&& (__4i -> base__4node != 86 ))&& (__4i -> base__4node != 124 ))
# 836 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 837 "/home/claude/cfront-3/src/print2.cpp"
Ptype __7t1 ;

# 837 "/home/claude/cfront-3/src/print2.cpp"
__7t1 = skiptypedefs__4typeFv ( __1n -> __O1__4expr.tp ) ;

# 839 "/home/claude/cfront-3/src/print2.cpp"
switch (__7t1 -> base__4node ){ 
# 840 "/home/claude/cfront-3/src/print2.cpp"
default :
# 841 "/home/claude/cfront-3/src/print2.cpp"
print__4exprFv ( __4i ) ;
break ;
case 110 :
# 844 "/home/claude/cfront-3/src/print2.cpp"
if ((((struct vec *)(((struct vec *)__7t1 ))))-> typ__5pvtyp -> base__4node == 5 ){ 
# 845 "/home/claude/cfront-3/src/print2.cpp"
print__4exprFv ( __4i ) ;
break ;
}

# 849 "/home/claude/cfront-3/src/print2.cpp"
case 125 :
# 850 "/home/claude/cfront-3/src/print2.cpp"
case 158 :
# 851 "/home/claude/cfront-3/src/print2.cpp"
if (((__4i -> __O1__4expr.tp == 0 )|| (((((! ansi_opt )&& (((struct ptr *)(((struct ptr *)__2t ))))-> typ__5pvtyp )&& (skiptypedefs__4typeFv ( (((struct
# 851 "/home/claude/cfront-3/src/print2.cpp"
ptr *)(((struct ptr *)__2t ))))-> typ__5pvtyp ) -> base__4node == 110 ))&& (__4i -> base__4node != 191 ))&& (__4i -> base__4node != 113 )))|| check__4typeFP4typeUcT2 ( __1n ->
# 851 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp , __4i -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) )
# 863 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 864 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'(' , out_file )
# 864 "/home/claude/cfront-3/src/print2.cpp"
;
{ bit __9oc ;

# 865 "/home/claude/cfront-3/src/print2.cpp"
__9oc = Cast ;
Cast = 1 ;
print__4typeFv ( __2t ) ;
Cast = __9oc ;
fputc ( (int )')' , out_file ) ;

# 869 "/home/claude/cfront-3/src/print2.cpp"
}
}
if (__4i )Eprint__FP4expr ( __4i ) ;
}
}
else { 
# 875 "/home/claude/cfront-3/src/print2.cpp"
if (__4i == zero ){ 
# 876 "/home/claude/cfront-3/src/print2.cpp"
while (__2t -> base__4node == 97 )__2t = (((struct basetype *)(((struct basetype *)__2t ))))-> b_name__8basetype -> __O1__4expr.tp ;
# 876 "/home/claude/cfront-3/src/print2.cpp"

# 877 "/home/claude/cfront-3/src/print2.cpp"
}
if (__4i )Eprint__FP4expr ( __4i ) ;
}

# 879 "/home/claude/cfront-3/src/print2.cpp"
}
}
else if (__1n -> n_evaluated__4name ){ 
# 882 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )70 ) ;
if ((__1n -> __O1__4expr.tp -> base__4node != 21 )|| is_unsigned__4typeFv ( __1n -> __O1__4expr.tp ) ){ 
# 884 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"((",
# 884 "/home/claude/cfront-3/src/print2.cpp"
out_file ) ;
{ bit __7oc ;

# 885 "/home/claude/cfront-3/src/print2.cpp"
__7oc = Cast ;
Cast = 1 ;
print__4typeFv ( __1n -> __O1__4expr.tp ) ;
Cast = __7oc ;
fprintf ( out_file , (const char *)")%lld)", __1n -> n_val__4name ) ;

# 889 "/home/claude/cfront-3/src/print2.cpp"
}
}
else 
# 892 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%lld", __1n -> n_val__4name ) ;
}
}

# 896 "/home/claude/cfront-3/src/print2.cpp"
__1n -> __O3__4expr.n_initializer = __4saveinit ;
__1n -> n_sto__4name = __4savesto ;

# 899 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 902 "/home/claude/cfront-3/src/print2.cpp"
switch (__1list ){ 
# 903 "/home/claude/cfront-3/src/print2.cpp"
case 72 :
# 904 "/home/claude/cfront-3/src/print2.cpp"
if (__2sm == 0 )puttok__FUc ( (unsigned char )72 ) ;
break ;
case 0 :
# 907 "/home/claude/cfront-3/src/print2.cpp"
if (__2sm == 0 )puttok__FUc ( (unsigned char )72 ) ;
return ;
case 71 :
# 910 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> __O1__4name.n_list )puttok__FUc ( (unsigned char )71 ) ;
break ;
}

# 912 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 913 "/home/claude/cfront-3/src/print2.cpp"
}

# 913 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 321 "/home/claude/cfront-3/src/cfront.h"
char *signature__4typeFPci (struct type *__0this , char *, int );

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 916 "/home/claude/cfront-3/src/print2.cpp"
char *local_sign__FP4type (Ptype __1pt )
# 917 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 918 "/home/claude/cfront-3/src/print2.cpp"
char __1buf [1024];
char *__1bb ;
int __1ll ;

# 919 "/home/claude/cfront-3/src/print2.cpp"
__1bb = signature__4typeFPci ( __1pt , (char *)__1buf , 0 ) ;
__1ll = (__1bb - __1buf );
if (1023 < __1ll )error__FiPCc ( (int )'i' , (const char *)"local class N buffer overflow") ;
{ char *__1p ;

# 922 "/home/claude/cfront-3/src/print2.cpp"
__1p = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (__1ll + 1 ))) ));
strcpy ( __1p , (const char *)__1buf ) ;
return __1p ;

# 924 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 927 "/home/claude/cfront-3/src/print2.cpp"
void dcl_print__7enumdefFP4name (register struct enumdef *__0this , Pname __1cln )
# 928 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 930 "/home/claude/cfront-3/src/print2.cpp"
const char *__1s ;

# 930 "/home/claude/cfront-3/src/print2.cpp"
__1s = (__0this -> nested_sig__4type ?(((const char *)__0this -> nested_sig__4type )):(__1cln ?__1cln -> __O2__4expr.string :(((const char *)0 ))));
if (__0this -> nested_sig__4type )
# 932 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"enum __%s { ", __0this -> nested_sig__4type ) ;
# 932 "/home/claude/cfront-3/src/print2.cpp"
else 
# 934 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"enum %s { ", __0this -> local_sig__4type ?(((const char *)__0this ->
# 934 "/home/claude/cfront-3/src/print2.cpp"
local_sig__4type )):__0this -> string__7enumdef ) ;

# 936 "/home/claude/cfront-3/src/print2.cpp"
{ { Pname __1px ;

# 936 "/home/claude/cfront-3/src/print2.cpp"
Pname __1p ;

# 936 "/home/claude/cfront-3/src/print2.cpp"
__1p = __0this -> mem__7enumdef ;

# 936 "/home/claude/cfront-3/src/print2.cpp"
for(;__1p ;__1p = __1px ) { 
# 937 "/home/claude/cfront-3/src/print2.cpp"
__1px = __1p -> __O1__4name.n_list ;
if (__1s ){ 
# 939 "/home/claude/cfront-3/src/print2.cpp"
if (__1p -> n_evaluated__4name )
# 940 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s__%s = %lld", __1p ->
# 940 "/home/claude/cfront-3/src/print2.cpp"
__O2__4expr.string , __1s , __1p -> n_val__4name ) ;
else 
# 942 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s__%s", __1p -> __O2__4expr.string , __1s ) ;
# 942 "/home/claude/cfront-3/src/print2.cpp"

# 943 "/home/claude/cfront-3/src/print2.cpp"
}
else { 
# 945 "/home/claude/cfront-3/src/print2.cpp"
if (__1p -> n_evaluated__4name )
# 946 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s = %lld", __1p ->
# 946 "/home/claude/cfront-3/src/print2.cpp"
__O2__4expr.string , __1p -> n_val__4name ) ;
else 
# 948 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s", __1p -> __O2__4expr.string ) ;
}
if (__1px )puttok__FUc ( (unsigned char )71 ) ;
__1p -> __O3__4expr.n_initializer = 0 ;

# 954 "/home/claude/cfront-3/src/print2.cpp"
if ((__0this -> in_class__4type == 0 )|| (__0this -> in_class__4type -> class_base__8classdef != 4))
# 956 "/home/claude/cfront-3/src/print2.cpp"
( (__1p ?(((void )(__1p ?(((void )( ( ((((struct expr *)__1p ))?(((void
# 956 "/home/claude/cfront-3/src/print2.cpp"
)((((struct expr *)__1p ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) , (((void )__dl__4nameSFPvUl ( (void *)__1p , (unsigned long )(sizeof
# 956 "/home/claude/cfront-3/src/print2.cpp"
(struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;
}
if ((__0this -> in_class__4type == 0 )|| (__0this -> in_class__4type -> class_base__8classdef != 4))
# 960 "/home/claude/cfront-3/src/print2.cpp"
__0this -> mem__7enumdef = 0 ;
else __0this -> e_body__7enumdef = 3 ;
puttok__FUc ( (unsigned char )74 ) ;
puttok__FUc ( (unsigned char )72 ) ;

# 963 "/home/claude/cfront-3/src/print2.cpp"
}

# 963 "/home/claude/cfront-3/src/print2.cpp"
}
}

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

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 435 "/home/claude/cfront-3/src/template.h"
void print_pretty_name__10templ_instFv (struct templ_inst *__0this );

# 477 "/home/claude/cfront-3/src/template.h"

# 966 "/home/claude/cfront-3/src/print2.cpp"
void print__4nameFUc (register struct name *__0this , bit __1fullprint )
# 967 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 968 "/home/claude/cfront-3/src/print2.cpp"
if (__0this == 0 )error__FiPCc ( (int )'i' , (const char *)"0->N::print()")
# 968 "/home/claude/cfront-3/src/print2.cpp"
;
if (__0this -> __O2__4expr.string == 0 ){ 
# 970 "/home/claude/cfront-3/src/print2.cpp"
if (emode )fputc ( (int )'?' , out_file ) ;
return ;
}

# 974 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> base__4node ){ 
# 975 "/home/claude/cfront-3/src/print2.cpp"
case 123 :
# 977 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O3__4expr.tpdef == 0 ){ 
# 978 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> __O1__4expr.tp -> base__4node ){ 
# 978 "/home/claude/cfront-3/src/print2.cpp"
const void
# 978 "/home/claude/cfront-3/src/print2.cpp"
*__2__X40 ;

# 979 "/home/claude/cfront-3/src/print2.cpp"
default :
# 980 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 980 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V39 ;

# 980 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"missing tpdef forTdefN %s", (const struct ea *)( (__2__X40 =
# 980 "/home/claude/cfront-3/src/print2.cpp"
(const void *)__0this -> __O2__4expr.string ), ( ((& __0__V39 )-> __O1__2ea.p = __2__X40 ), (& __0__V39 )) ) , (const
# 980 "/home/claude/cfront-3/src/print2.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
case 119 :
# 982 "/home/claude/cfront-3/src/print2.cpp"
case 121 :
# 983 "/home/claude/cfront-3/src/print2.cpp"
print__4nameFUc ( (((struct basetype *)(((struct basetype *)__0this -> __O1__4expr.tp ))))-> b_name__8basetype , (unsigned char )0 ) ;
} }
}
else 
# 985 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O3__4expr.tpdef -> nested_sig__4type ){ 
# 986 "/home/claude/cfront-3/src/print2.cpp"
if (emode == 0 ){ 
# 987 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)" __",
# 987 "/home/claude/cfront-3/src/print2.cpp"
out_file ) ;
( fputs ( (const char *)__0this -> __O3__4expr.tpdef -> nested_sig__4type , out_file ) , fputc ( (int )' ' , out_file ) )
# 988 "/home/claude/cfront-3/src/print2.cpp"
;
}
else { 
# 991 "/home/claude/cfront-3/src/print2.cpp"
print__4nameFUc ( (((struct basetype *)(((struct basetype *)__0this -> __O3__4expr.tpdef -> in_class__4type -> k_tbl__8classdef -> k_name__6ktable -> __O1__4expr.tp ))))-> b_name__8basetype , (unsigned char
# 991 "/home/claude/cfront-3/src/print2.cpp"
)0 ) ;
fputs ( (const char *)"::", out_file ) ;
fputs ( __0this -> __O2__4expr.string , out_file ) ;
}
}
else 
# 995 "/home/claude/cfront-3/src/print2.cpp"
if (emode )
# 996 "/home/claude/cfront-3/src/print2.cpp"
fputs ( __0this -> __O2__4expr.string , out_file ) ;
else 
# 998 "/home/claude/cfront-3/src/print2.cpp"
( fputs ( __0this -> n_template_arg_string__4name ?(((const char *)__0this -> n_template_arg_string__4name )):__0this -> __O2__4expr.string , out_file ) , fputc ( (int )' ' ,
# 998 "/home/claude/cfront-3/src/print2.cpp"
out_file ) ) ;
return ;

# 1001 "/home/claude/cfront-3/src/print2.cpp"
case 177 :
# 1002 "/home/claude/cfront-3/src/print2.cpp"
print__4exprFv ( ((struct expr *)(((struct expr *)__0this )))) ;
return ;
}

# 1006 "/home/claude/cfront-3/src/print2.cpp"
if (emode ){ 
# 1007 "/home/claude/cfront-3/src/print2.cpp"
Ptable __2tbl ;
bit __2f ;

# 1007 "/home/claude/cfront-3/src/print2.cpp"
__2tbl = 0 ;
__2f = 0 ;
if (__0this -> __O1__4expr.tp ){ 
# 1010 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> __O1__4expr.tp -> base__4node ){ 
# 1011 "/home/claude/cfront-3/src/print2.cpp"
case 76 :
# 1012 "/home/claude/cfront-3/src/print2.cpp"
case 108 :{ 
# 1014 "/home/claude/cfront-3/src/print2.cpp"
Pfct __5ft ;

# 1015 "/home/claude/cfront-3/src/print2.cpp"
unsigned long __2__X16 ;

# 1015 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__X__V1400qmp1ovbwvcnm ;

# 1015 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__X__V1500qmp1ovbwvcnm ;

# 1013 "/home/claude/cfront-3/src/print2.cpp"
__2f = 1 ;
;
if (__0this -> __O1__4expr.tp -> base__4node == 108 )
# 1016 "/home/claude/cfront-3/src/print2.cpp"
__5ft = ( ((__0this -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 (
# 1016 "/home/claude/cfront-3/src/print2.cpp"
(int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400qmp1ovbwvcnm )->
# 1016 "/home/claude/cfront-3/src/print2.cpp"
__O1__2ea.p = ((const void *)__0this )), (& __0__X__V1400qmp1ovbwvcnm )) , (const struct ea *)( (__2__X16 = __0this -> __O1__4expr.tp -> base__4node ),
# 1016 "/home/claude/cfront-3/src/print2.cpp"
( (( ((& __0__X__V1500qmp1ovbwvcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500qmp1ovbwvcnm )) ) , (const struct
# 1016 "/home/claude/cfront-3/src/print2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ;
else 
# 1018 "/home/claude/cfront-3/src/print2.cpp"
__5ft = (((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__0this -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ))));
if ((__1fullprint && __5ft -> returns__3fct )&& (__5ft -> returns__3fct -> base__4node != 38 ))
# 1020 "/home/claude/cfront-3/src/print2.cpp"
print__4typeFv ( __5ft -> returns__3fct ) ;
}
default :
# 1023 "/home/claude/cfront-3/src/print2.cpp"
if (__2tbl = __0this -> __O4__4expr.n_table ){ 
# 1024 "/home/claude/cfront-3/src/print2.cpp"
if (__2tbl == gtbl ){ 
# 1025 "/home/claude/cfront-3/src/print2.cpp"
if (__2f == 0 )fputs ( (const char *)"::",
# 1025 "/home/claude/cfront-3/src/print2.cpp"
out_file ) ;
}
else { 
# 1028 "/home/claude/cfront-3/src/print2.cpp"
if (__2tbl -> t_name__5table ){ 
# 1029 "/home/claude/cfront-3/src/print2.cpp"
print__4nameFUc ( __2tbl -> t_name__5table , (unsigned char )0 ) ;
fprintf ( out_file , (const char *)"::") ;
}
}
}

# 1035 "/home/claude/cfront-3/src/print2.cpp"
if ((__0this -> n_scope__4name == 136 )&& (strcmp ( __0this -> __O2__4expr.string , (const char *)"this")
# 1035 "/home/claude/cfront-3/src/print2.cpp"
== 0 )){ 
# 1037 "/home/claude/cfront-3/src/print2.cpp"
Ptype __5tt ;
Pname __5cn ;

# 1037 "/home/claude/cfront-3/src/print2.cpp"
__5tt = (((struct ptr *)(((struct ptr *)__0this -> __O1__4expr.tp ))))-> typ__5pvtyp ;
__5cn = (((struct basetype *)(((struct basetype *)__5tt ))))-> b_name__8basetype ;
fprintf ( out_file , (const char *)"%s::", __5cn -> __O2__4expr.string ) ;
}
break ;

# 1043 "/home/claude/cfront-3/src/print2.cpp"
case 6 :
# 1044 "/home/claude/cfront-3/src/print2.cpp"
case 13 :
# 1045 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O1__4expr.tp -> local_sig__4type ){ 
# 1046 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s(local to ",
# 1046 "/home/claude/cfront-3/src/print2.cpp"
__0this -> __O2__4expr.string ) ;
print__4nameFUc ( __0this -> __O1__4expr.tp -> in_fct__4type , (unsigned char )0 ) ;
fprintf ( out_file , (const char *)")") ;
return ;
}
else 
# 1050 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1051 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O1__4expr.tp -> nested_sig__4type ){ 
# 1052 "/home/claude/cfront-3/src/print2.cpp"
print__4nameFUc ( (((struct basetype *)(((struct basetype *)__0this -> __O1__4expr.tp -> in_class__4type -> k_tbl__8classdef -> k_name__6ktable ->
# 1052 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp ))))-> b_name__8basetype , (unsigned char )0 ) ;
fprintf ( out_file , (const char *)"::") ;
}
if (__0this -> __O1__4expr.tp -> base__4node == 6 ){ 
# 1056 "/home/claude/cfront-3/src/print2.cpp"
Ptclass __6pc ;

# 1056 "/home/claude/cfront-3/src/print2.cpp"
__6pc = (((struct templ_classdef *)(((struct templ_classdef *)__0this -> __O1__4expr.tp ))));
if (__6pc -> class_base__8classdef == 4)
# 1060 "/home/claude/cfront-3/src/print2.cpp"
((*(((void (*)(struct templ_inst *__0this ))(__6pc -> inst__14templ_classdef -> __vptr__10basic_inst [2]).f))))( ((struct templ_inst *)((((char *)__6pc -> inst__14templ_classdef ))+ (__6pc -> inst__14templ_classdef ->
# 1060 "/home/claude/cfront-3/src/print2.cpp"
__vptr__10basic_inst [2]).d))) ;
else 
# 1062 "/home/claude/cfront-3/src/print2.cpp"
fputs ( __0this -> __O2__4expr.string , out_file ) ;
}
else fputs ( __0this -> __O2__4expr.string , out_file ) ;
return ;
}
}
nop :
# 1069 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> n_oper__4name ){ 
# 1070 "/home/claude/cfront-3/src/print2.cpp"
case 97 :
# 1071 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"operator ", out_file ) ;
# 1071 "/home/claude/cfront-3/src/print2.cpp"

# 1072 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O1__4expr.tp && (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> returns__3fct )dcl_print__4typeFP4name ( (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> returns__3fct , (struct
# 1072 "/home/claude/cfront-3/src/print2.cpp"
name *)0 ) ;
break ;
case 0 :
# 1075 "/home/claude/cfront-3/src/print2.cpp"
fputs ( __0this -> __O2__4expr.string , out_file ) ;
break ;
case 162 :
# 1078 "/home/claude/cfront-3/src/print2.cpp"
if (__2tbl && __2tbl -> t_name__5table ){ 
# 1079 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'~' , out_file ) ;
fputs ( __2tbl -> t_name__5table -> __O2__4expr.string , out_file ) ;
}
else 
# 1081 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1082 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O2__4expr.string )
# 1084 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s", __0this ->
# 1084 "/home/claude/cfront-3/src/print2.cpp"
n_template_arg_string__4name ?__0this -> n_template_arg_string__4name :(((char *)"destructor"))) ;
else 
# 1086 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"destructor", out_file ) ;
__2f = 0 ;
}
break ;
case 161 :
# 1091 "/home/claude/cfront-3/src/print2.cpp"
if (__2tbl && __2tbl -> t_name__5table )
# 1092 "/home/claude/cfront-3/src/print2.cpp"
fputs ( __2tbl -> t_name__5table -> __O2__4expr.string , out_file ) ;
else { 
# 1094 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O2__4expr.string )
# 1096 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s", __0this ->
# 1096 "/home/claude/cfront-3/src/print2.cpp"
n_template_arg_string__4name ?__0this -> n_template_arg_string__4name :(((char *)"constructor"))) ;
else 
# 1098 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"constructor", out_file ) ;
__2f = 0 ;
}
break ;
case 123 :
# 1103 "/home/claude/cfront-3/src/print2.cpp"
fputs ( __0this -> __O2__4expr.string , out_file ) ;
break ;
default :
# 1106 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"operator ", out_file ) ;
fputs ( keys [__0this -> n_oper__4name ], out_file ) ;
break ;
}

# 1111 "/home/claude/cfront-3/src/print2.cpp"
if (__2f )
# 1112 "/home/claude/cfront-3/src/print2.cpp"
if (__1fullprint )
# 1113 "/home/claude/cfront-3/src/print2.cpp"
arg_print__3fctFv ( ((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp )))) ;
else fputs ( (const char *)"()", out_file ) ;
}
else { 
# 1117 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> n_oper__4name )goto nop ;
if (__0this -> __O2__4expr.string )
# 1120 "/home/claude/cfront-3/src/print2.cpp"
fputs ( __0this -> n_template_arg_string__4name ?(((const char *)__0this -> n_template_arg_string__4name )):__0this -> __O2__4expr.string , out_file ) ;
}
return ;
}

# 1125 "/home/claude/cfront-3/src/print2.cpp"
{ const char *__1sig ;
const char *__1templ_fct_name ;
Pclass __1cl ;
const char *__1asig ;

# 1125 "/home/claude/cfront-3/src/print2.cpp"
__1sig = 0 ;
__1templ_fct_name = 0 ;
__1cl = 0 ;
__1asig = __0this -> n_anon__4name ;

# 1130 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O1__4expr.tp ){ 
# 1131 "/home/claude/cfront-3/src/print2.cpp"
Ptable __2tbl ;

# 1133 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> __O1__4expr.tp -> base__4node ){ 
# 1134 "/home/claude/cfront-3/src/print2.cpp"
default :
# 1135 "/home/claude/cfront-3/src/print2.cpp"
if (__2tbl = __0this -> __O4__4expr.n_table ){ 
# 1136 "/home/claude/cfront-3/src/print2.cpp"
Pname __4tn ;
if (__2tbl == gtbl ){ 
# 1138 "/home/claude/cfront-3/src/print2.cpp"
if (__1asig ){ 
# 1139 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s.",
# 1139 "/home/claude/cfront-3/src/print2.cpp"
__1asig ) ;
}
break ;
}

# 1144 "/home/claude/cfront-3/src/print2.cpp"
if (__4tn = __2tbl -> t_name__5table ){ 
# 1145 "/home/claude/cfront-3/src/print2.cpp"
__1cl = (((struct classdef *)(((struct classdef *)__4tn -> __O1__4expr.tp ))));

# 1147 "/home/claude/cfront-3/src/print2.cpp"
if (__1asig ){ 
# 1148 "/home/claude/cfront-3/src/print2.cpp"
if ((((__1cl -> string__8classdef [0 ])== '_' )&& ((__1cl -> string__8classdef [1 ])== '_' ))&& ((__1cl -> string__8classdef [2 ])== 'C' ))
# 1154 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1155 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file ,
# 1155 "/home/claude/cfront-3/src/print2.cpp"
(const char *)"%s.", __1asig ) ;
}
else { 
# 1158 "/home/claude/cfront-3/src/print2.cpp"
const char *__7cn ;
int __7f ;
char __7buf [1024];
if (__1cl -> nested_sig__4type )
# 1162 "/home/claude/cfront-3/src/print2.cpp"
__7cn = (const char *)__1cl -> nested_sig__4type ;
else if (__1cl -> lex_level__4type )
# 1164 "/home/claude/cfront-3/src/print2.cpp"
__7cn = (const char *)__1cl -> local_sig__4type ;
else 
# 1166 "/home/claude/cfront-3/src/print2.cpp"
__7cn = __1cl -> string__8classdef ;
__7f = (dem_opt_mem && dem_mem__FPCcT1 ( __7cn , __1asig ) );
fprintf ( out_file , (const char *)"%s", __1asig ) ;
if (__1cl -> nested_sig__4type ){ 
# 1170 "/home/claude/cfront-3/src/print2.cpp"
sprintf ( (char *)__7buf , (const char *)"__%s", __1cl ->
# 1170 "/home/claude/cfront-3/src/print2.cpp"
nested_sig__4type ) ;
}
else if (__1cl -> lex_level__4type ){ 
# 1173 "/home/claude/cfront-3/src/print2.cpp"
sprintf ( (char *)__7buf , (const char *)"__%d%s",
# 1173 "/home/claude/cfront-3/src/print2.cpp"
__1cl -> c_strlen__8classdef , __1cl -> local_sig__4type ) ;
}
else { 
# 1176 "/home/claude/cfront-3/src/print2.cpp"
sprintf ( (char *)__7buf , (const char *)"__%d%s", __1cl -> c_strlen__8classdef ,
# 1176 "/home/claude/cfront-3/src/print2.cpp"
__1cl -> string__8classdef ) ;
}
if (! __7f )
# 1179 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s", __7buf ) ;
fprintf ( out_file , (const char *)".") ;
}
__1cl = 0 ;
}
else if (((((__1cl -> string__8classdef [0 ])== '_' )&& ((__1cl -> string__8classdef [1 ])== '_' ))&& ((__1cl -> string__8classdef [2 ])== 'C' ))&& (__0this -> n_stclass__4name != 31 ))
# 1192 "/home/claude/cfront-3/src/print2.cpp"
{
# 1192 "/home/claude/cfront-3/src/print2.cpp"

# 1194 "/home/claude/cfront-3/src/print2.cpp"
if (((__0this -> __O1__4expr.tp -> base__4node == 108 )&& ((((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_is_inline__3fct && vtbl_opt ))|| (ansi_opt && (__0this -> n_sto__4name ==
# 1194 "/home/claude/cfront-3/src/print2.cpp"
31 )))
# 1197 "/home/claude/cfront-3/src/print2.cpp"
;
else 
# 1199 "/home/claude/cfront-3/src/print2.cpp"
__1cl = 0 ;
}
break ;
}
}

# 1205 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> n_stclass__4name ){ 
# 1206 "/home/claude/cfront-3/src/print2.cpp"
case 31 :
# 1207 "/home/claude/cfront-3/src/print2.cpp"
case 14 :
# 1208 "/home/claude/cfront-3/src/print2.cpp"
if (__1asig )
# 1209 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s.",
# 1209 "/home/claude/cfront-3/src/print2.cpp"
__1asig ) ;
else if ((__0this -> n_sto__4name == 31 )&& (__0this -> __O1__4expr.tp -> base__4node != 108 )){ 
# 1211 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> lex_level__4name == 0 )
# 1212 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const
# 1212 "/home/claude/cfront-3/src/print2.cpp"
char *)"__S", out_file ) ;
else if ((! dem_opt_local )|| look__5tableFPCcUc ( gtbl , __0this -> __O2__4expr.string , (unsigned char )0 ) )
# 1214 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const
# 1214 "/home/claude/cfront-3/src/print2.cpp"
char *)"__%d", ((int )__0this -> lex_level__4name )) ;
}
break ;
default :
# 1220 "/home/claude/cfront-3/src/print2.cpp"
if ((((__0this -> __O2__4expr.string [0 ])!= '_' )|| ((__0this -> __O2__4expr.string [1 ])!= '_' ))|| ((__0this -> __O2__4expr.string [2 ])!= 'C' )){ 
# 1221 "/home/claude/cfront-3/src/print2.cpp"
if (__1asig ){ 
# 1222 "/home/claude/cfront-3/src/print2.cpp"
if
# 1222 "/home/claude/cfront-3/src/print2.cpp"
((! dem_opt_local )|| look__5tableFPCcUc ( gtbl , __1asig , (unsigned char )0 ) )
# 1223 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"__%d",
# 1223 "/home/claude/cfront-3/src/print2.cpp"
((int )__0this -> lex_level__4name )) ;
fprintf ( out_file , (const char *)"%s.", __1asig ) ;
}
else if ((! dem_opt_local )|| look__5tableFPCcUc ( gtbl , __0this -> __O2__4expr.string , (unsigned char )0 ) ){ 
# 1227 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file ,
# 1227 "/home/claude/cfront-3/src/print2.cpp"
(const char *)"__%d", ((int )__0this -> lex_level__4name )) ;
}
}
}
break ;

# 1233 "/home/claude/cfront-3/src/print2.cpp"
case 6 :
# 1234 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O1__4expr.tp -> nested_sig__4type )
# 1235 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"__%s", __0this ->
# 1235 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp -> nested_sig__4type ) ;
else if (__0this -> __O1__4expr.tp -> local_sig__4type )
# 1237 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s", __0this ->
# 1237 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp -> local_sig__4type ) ;
else 
# 1239 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s", (((struct classdef *)(((struct classdef *)__0this -> __O1__4expr.tp ))))->
# 1239 "/home/claude/cfront-3/src/print2.cpp"
string__8classdef ) ;
return ;
case 13 :
# 1242 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O1__4expr.tp -> nested_sig__4type )
# 1243 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"__%s", __0this ->
# 1243 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp -> nested_sig__4type ) ;
else if (__0this -> __O1__4expr.tp -> local_sig__4type )
# 1245 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s", __0this ->
# 1245 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp -> local_sig__4type ) ;
else 
# 1247 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%s", (((struct enumdef *)(((struct enumdef *)__0this -> __O1__4expr.tp ))))->
# 1247 "/home/claude/cfront-3/src/print2.cpp"
string__7enumdef ) ;
return ;
}

# 1251 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O1__4expr.tp -> base__4node == 108 ){ 
# 1251 "/home/claude/cfront-3/src/print2.cpp"
register struct templ_fct *__0__X41 ;

# 1252 "/home/claude/cfront-3/src/print2.cpp"
__1sig = (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_signature__3fct ;
if (__1sig && ((__1sig [0 ])== 0 ))
# 1254 "/home/claude/cfront-3/src/print2.cpp"
__1sig = 0 ;
if (__1sig && ((((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> fct_base__3fct == 4))
# 1256 "/home/claude/cfront-3/src/print2.cpp"
__1templ_fct_name = ( (__0__X41 = (((struct templ_fct *)(((struct templ_fct *)__0this -> __O1__4expr.tp ))))),
# 1256 "/home/claude/cfront-3/src/print2.cpp"
( __0__X41 -> inst__9templ_fct -> def__10funct_inst -> fn__17function_template ) ) -> __O2__4expr.string ;
}
}

# 1260 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> __O2__4expr.string ){ 
# 1286 "/home/claude/cfront-3/src/print2.cpp"
const char *__2mn ;
{ 
# 1288 "/home/claude/cfront-3/src/print2.cpp"
const char *__3s ;

# 1288 "/home/claude/cfront-3/src/print2.cpp"
__3s = (__0this -> n_template_arg_string__4name ?(((const char *)__0this -> n_template_arg_string__4name )):(__1templ_fct_name ?__1templ_fct_name :__0this -> __O2__4expr.string ));

# 1290 "/home/claude/cfront-3/src/print2.cpp"
fputs ( __3s , out_file ) ;
__2mn = __3s ;
}

# 1294 "/home/claude/cfront-3/src/print2.cpp"
if (__1cl ){ 
# 1295 "/home/claude/cfront-3/src/print2.cpp"
int __3f ;

# 1295 "/home/claude/cfront-3/src/print2.cpp"
__3f = 0 ;
if (((__0this -> __O1__4expr.tp -> base__4node != 108 )&& (__0this -> n_stclass__4name != 31 ))&& dem_opt_mem ){ 
# 1297 "/home/claude/cfront-3/src/print2.cpp"
const char *__4cn ;
if (__1cl -> nested_sig__4type )
# 1299 "/home/claude/cfront-3/src/print2.cpp"
__4cn = (const char *)__1cl -> nested_sig__4type ;
else if (__1cl -> lex_level__4type )
# 1301 "/home/claude/cfront-3/src/print2.cpp"
__4cn = (const char *)__1cl -> local_sig__4type ;
else 
# 1303 "/home/claude/cfront-3/src/print2.cpp"
__4cn = __1cl -> string__8classdef ;
__3f = dem_mem__FPCcT1 ( __4cn , __2mn ) ;
}
if ((! dem_opt_mem )|| (! __3f )){ 
# 1307 "/home/claude/cfront-3/src/print2.cpp"
if (__1cl -> nested_sig__4type )
# 1308 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"__%s",
# 1308 "/home/claude/cfront-3/src/print2.cpp"
__1cl -> nested_sig__4type ) ;
else if (__1cl -> lex_level__4type )
# 1310 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"__%d%s", ((int )__1cl ->
# 1310 "/home/claude/cfront-3/src/print2.cpp"
c_strlen__8classdef ), __1cl -> local_sig__4type ) ;
else 
# 1312 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"__%d%s", ((int )__1cl -> c_strlen__8classdef ), __1cl ->
# 1312 "/home/claude/cfront-3/src/print2.cpp"
string__8classdef ) ;
}
}

# 1316 "/home/claude/cfront-3/src/print2.cpp"
if (__1sig ){ 
# 1317 "/home/claude/cfront-3/src/print2.cpp"
if (__1cl == 0 )
# 1318 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"__", out_file ) ;
# 1318 "/home/claude/cfront-3/src/print2.cpp"

# 1319 "/home/claude/cfront-3/src/print2.cpp"
fputs ( __1sig , out_file ) ;
}
fputc ( (int )' ' , out_file ) ;
}

# 1322 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 1351 "/home/claude/cfront-3/src/print2.cpp"
void print__4typeFv (register struct type *__0this )
# 1352 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1353 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> base__4node ){ 
# 1354 "/home/claude/cfront-3/src/print2.cpp"
case 125 :
# 1355 "/home/claude/cfront-3/src/print2.cpp"
case 158 :
# 1356 "/home/claude/cfront-3/src/print2.cpp"
case 110 :
# 1357 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__4typeFP4name ( (struct type *)(((struct ptr *)(((struct
# 1357 "/home/claude/cfront-3/src/print2.cpp"
ptr *)__0this )))), (struct name *)0 ) ;
break ;
case 108 :
# 1360 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__3fctFv ( ((struct fct *)(((struct fct *)__0this )))) ;
break ;
case 6 :
# 1363 "/home/claude/cfront-3/src/print2.cpp"
case 13 :
# 1364 "/home/claude/cfront-3/src/print2.cpp"
if (emode )
# 1365 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> base__4node == 6 )
# 1366 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"class ",
# 1366 "/home/claude/cfront-3/src/print2.cpp"
out_file ) ;
else fputs ( (const char *)"enum ", out_file ) ;
else if (__0this -> base__4node == 6 ){ 
# 1369 "/home/claude/cfront-3/src/print2.cpp"
if ((((struct classdef *)(((struct classdef *)__0this ))))-> nested_sig__4type )
# 1370 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"struct __%s *",
# 1370 "/home/claude/cfront-3/src/print2.cpp"
(((struct classdef *)(((struct classdef *)__0this ))))-> nested_sig__4type ) ;
else 
# 1372 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"struct %s *", (((struct classdef *)(((struct classdef *)__0this ))))-> local_sig__4type ?(((const
# 1372 "/home/claude/cfront-3/src/print2.cpp"
char *)(((struct classdef *)(((struct classdef *)__0this ))))-> local_sig__4type )):(((struct classdef *)(((struct classdef *)__0this ))))-> string__8classdef ) ;
}
else 
# 1375 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"enum %s *", (((struct enumdef *)(((struct enumdef *)__0this ))))-> string__7enumdef )
# 1375 "/home/claude/cfront-3/src/print2.cpp"
;
break ;
case 97 :
# 1378 "/home/claude/cfront-3/src/print2.cpp"
if (Cast || (((struct basetype *)(((struct basetype *)__0this ))))-> b_name__8basetype -> lex_level__4name ){ 
# 1379 "/home/claude/cfront-3/src/print2.cpp"
print__4typeFv ( (((struct basetype *)(((struct basetype *)__0this ))))-> b_name__8basetype -> __O1__4expr.tp )
# 1379 "/home/claude/cfront-3/src/print2.cpp"
;
break ;
}

# 1383 "/home/claude/cfront-3/src/print2.cpp"
default :
# 1384 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__8basetypeFv ( ((struct basetype *)(((struct basetype *)__0this )))) ;
}
}

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 1388 "/home/claude/cfront-3/src/print2.cpp"
char *signature__4typeFPci (register struct type *__0this , char *__1p , int __1ptflag )
# 1393 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1394 "/home/claude/cfront-3/src/print2.cpp"
Ptype __1t ;
int __1pp ;

# 1394 "/home/claude/cfront-3/src/print2.cpp"
__1t = __0this ;
__1pp = 0 ;

# 1397 "/home/claude/cfront-3/src/print2.cpp"
xx :
# 1402 "/home/claude/cfront-3/src/print2.cpp"
switch (__1t -> base__4node ){ 
# 1403 "/home/claude/cfront-3/src/print2.cpp"
case 97 :
# 1404 "/home/claude/cfront-3/src/print2.cpp"
if ((((struct basetype *)(((struct basetype *)__1t ))))-> b_const__4type )
# 1405 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'C' ;
__1t = (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto xx ;

# 1409 "/home/claude/cfront-3/src/print2.cpp"
case 110 :
# 1410 "/home/claude/cfront-3/src/print2.cpp"
if ((__1pp || __1ptflag )&& (((struct vec *)(((struct vec *)__1t ))))-> size__3vec ){ 
# 1411 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'A' ;
sprintf ( __1p , (const char *)"%d\0", (((struct vec *)(((struct vec *)__1t ))))-> size__3vec ) ;
# 1412 "/home/claude/cfront-3/src/print2.cpp"

# 1414 "/home/claude/cfront-3/src/print2.cpp"
while ((*(++ __1p )));
((*(__1p ++ )))= '_' ;
}
else 
# 1418 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'P' ;
__1t = (((struct vec *)(((struct vec *)__1t ))))-> typ__5pvtyp ;
__1pp = 1 ;
goto xx ;

# 1423 "/home/claude/cfront-3/src/print2.cpp"
case 125 :
# 1424 "/home/claude/cfront-3/src/print2.cpp"
if ((((struct ptr *)(((struct ptr *)__1t ))))-> b_const__4type )
# 1425 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'C' ;
{ const char *__2s ;
int __2d ;
__2s = 0 ;
__2d = 0 ;
if (((! (((struct ptr *)(((struct ptr *)__1t ))))-> memof__3ptr )&& (((struct ptr *)(((struct ptr *)__1t ))))-> ptname__3ptr )&& (((struct ptr *)(((struct ptr *)__1t ))))-> ptname__3ptr ->
# 1430 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp ){ 
# 1431 "/home/claude/cfront-3/src/print2.cpp"
__2s = (((struct basetype *)(((struct basetype *)(((struct ptr *)(((struct ptr *)__1t ))))-> ptname__3ptr -> __O1__4expr.tp ))))-> b_name__8basetype -> __O2__4expr.string ;
__2d = strlen ( __2s ) ;
}
if ((((struct ptr *)(((struct ptr *)__1t ))))-> memof__3ptr || __2s ){ 
# 1435 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'M' ;
if (! __2s ){ 
# 1437 "/home/claude/cfront-3/src/print2.cpp"
Pclass __4cl ;
char *__4ns ;
char *__4ls ;

# 1437 "/home/claude/cfront-3/src/print2.cpp"
__4cl = (((struct ptr *)(((struct ptr *)__1t ))))-> memof__3ptr ;
__4ns = __4cl -> nested_sig__4type ;
__4ls = __4cl -> local_sig__4type ;
if (__4ns )__2s = (const char *)__4ns ;
else { 
# 1442 "/home/claude/cfront-3/src/print2.cpp"
if (__4ls )__2s = (const char *)__4ls ;
else __2s = __4cl -> string__8classdef ;
__2d = __4cl -> c_strlen__8classdef ;
}
}
if (__2d >= 100 )
# 1448 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= ('0' + (__2d / 100 ));
if (__2d >= 10 )
# 1450 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= ('0' + ((__2d % 100 )/ 10 ));
if (__2d )
# 1452 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= ('0' + (__2d % 10 ));
while (((*(__1p ++ )))= ((*(__2s ++ ))));
-- __1p ;
}
else 
# 1457 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'P' ;
__1t = (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp ;
__1pp = 1 ;
goto xx ;

# 1462 "/home/claude/cfront-3/src/print2.cpp"
case 158 :
# 1463 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'R' ;
__1t = (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp ;
__1pp = 1 ;
goto xx ;

# 1468 "/home/claude/cfront-3/src/print2.cpp"
case 108 :
# 1469 "/home/claude/cfront-3/src/print2.cpp"
{ Pfct __3f ;
Pname __3n ;

# 1469 "/home/claude/cfront-3/src/print2.cpp"
__3f = (((struct fct *)(((struct fct *)__1t ))));
__3n = __3f -> argtype__3fct ;

# 1472 "/home/claude/cfront-3/src/print2.cpp"
if (__3f -> f_const__3fct )
# 1473 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'C' ;
if (__3f -> f_static__3fct )
# 1475 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'S' ;
((*(__1p ++ )))= 'F' ;

# 1478 "/home/claude/cfront-3/src/print2.cpp"
if (__3n == 0 )
# 1479 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'v' ;
else 
# 1481 "/home/claude/cfront-3/src/print2.cpp"
for(;__3n ;__3n = __3n -> __O1__4name.n_list ) { 
# 1484 "/home/claude/cfront-3/src/print2.cpp"
int __4i ;

# 1484 "/home/claude/cfront-3/src/print2.cpp"
__4i = 0 ;
{ { Pname __4nn ;

# 1485 "/home/claude/cfront-3/src/print2.cpp"
__4nn = __3f -> argtype__3fct ;

# 1485 "/home/claude/cfront-3/src/print2.cpp"
for(;__3n != __4nn ;__4nn = __4nn -> __O1__4name.n_list ) { 
# 1486 "/home/claude/cfront-3/src/print2.cpp"
__4i ++ ;
if ((__4nn -> __O1__4expr.tp == __3n -> __O1__4expr.tp )|| (check__4typeFP4typeUcT2 ( __4nn -> __O1__4expr.tp , __3n -> __O1__4expr.tp , (unsigned char )0 , (unsigned
# 1487 "/home/claude/cfront-3/src/print2.cpp"
char )0 ) == 0 )){ 
# 1489 "/home/claude/cfront-3/src/print2.cpp"
int __6x ;
Pname __6nnn ;

# 1489 "/home/claude/cfront-3/src/print2.cpp"
__6x = 1 ;
__6nnn = __3n ;
while ((__6nnn = __6nnn -> __O1__4name.n_list )&& (__6x < 9 )){ 
# 1492 "/home/claude/cfront-3/src/print2.cpp"
if ((__6nnn -> __O1__4expr.tp == __3n -> __O1__4expr.tp )|| (check__4typeFP4typeUcT2 ( __6nnn -> __O1__4expr.tp ,
# 1492 "/home/claude/cfront-3/src/print2.cpp"
__3n -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) == 0 ))
# 1496 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1497 "/home/claude/cfront-3/src/print2.cpp"
__6x ++ ;
__3n = __6nnn ;
}
else 
# 1501 "/home/claude/cfront-3/src/print2.cpp"
break ;
}

# 1504 "/home/claude/cfront-3/src/print2.cpp"
if (__6x == 1 )
# 1505 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'T' ;
else { 
# 1507 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'N' ;
((*(__1p ++ )))= ('0' + __6x );
}

# 1512 "/home/claude/cfront-3/src/print2.cpp"
if (9 < __4i )
# 1513 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= ('0' + (__4i / 10 ));
((*(__1p ++ )))= ('0' + (__4i % 10 ));
goto zk ;
}
}

# 1520 "/home/claude/cfront-3/src/print2.cpp"
__1p = signature__4typeFPci ( __3n -> __O1__4expr.tp , __1p , 0 ) ;
zk :;

# 1521 "/home/claude/cfront-3/src/print2.cpp"
}

# 1521 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 1524 "/home/claude/cfront-3/src/print2.cpp"
if (__3f -> nargs_known__3fct == 155 )
# 1525 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= 'e' ;

# 1527 "/home/claude/cfront-3/src/print2.cpp"
if (__1pp ){ 
# 1528 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= '_' ;
__1p = signature__4typeFPci ( __3f -> returns__3fct , __1p , 0 ) ;
}

# 1532 "/home/claude/cfront-3/src/print2.cpp"
((*__1p ))= 0 ;
return __1p ;
}

# 1534 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 1539 "/home/claude/cfront-3/src/print2.cpp"
if ((((struct basetype *)(((struct basetype *)__1t ))))-> b_const__4type )((*(__1p ++ )))= 'C' ;

# 1541 "/home/claude/cfront-3/src/print2.cpp"
if ((((struct basetype *)(((struct basetype *)__1t ))))-> b_unsigned__8basetype )((*(__1p ++ )))= 'U' ;

# 1547 "/home/claude/cfront-3/src/print2.cpp"
{ const char *__1s ;

# 1547 "/home/claude/cfront-3/src/print2.cpp"
const char *__1ns ;

# 1547 "/home/claude/cfront-3/src/print2.cpp"
__1ns = 0 ;

# 1547 "/home/claude/cfront-3/src/print2.cpp"
;
{ char *__1ls ;
int __1d ;
Pclass __1cl ;
switch (__1t -> base__4node ){ 
# 1551 "/home/claude/cfront-3/src/print2.cpp"
unsigned long __2__X43 ;

# 1552 "/home/claude/cfront-3/src/print2.cpp"
case 141 :break ;
case 138 :break ;
case 38 :((*(__1p ++ )))= 'v' ;

# 1554 "/home/claude/cfront-3/src/print2.cpp"
break ;
case 5 :((*(__1p ++ )))= 'c' ;

# 1555 "/home/claude/cfront-3/src/print2.cpp"
break ;
case 29 :((*(__1p ++ )))= 's' ;

# 1556 "/home/claude/cfront-3/src/print2.cpp"
break ;
case 21 :((*(__1p ++ )))= 'i' ;

# 1557 "/home/claude/cfront-3/src/print2.cpp"
break ;
case 22 :((*(__1p ++ )))= 'l' ;

# 1558 "/home/claude/cfront-3/src/print2.cpp"
break ;
case 122 :((*(__1p ++ )))= 'm' ;

# 1559 "/home/claude/cfront-3/src/print2.cpp"
break ;
case 15 :((*(__1p ++ )))= 'f' ;

# 1560 "/home/claude/cfront-3/src/print2.cpp"
break ;
case 11 :((*(__1p ++ )))= 'd' ;

# 1561 "/home/claude/cfront-3/src/print2.cpp"
break ;
case 181 :((*(__1p ++ )))= 'r' ;

# 1562 "/home/claude/cfront-3/src/print2.cpp"
break ;
case 121 :
# 1564 "/home/claude/cfront-3/src/print2.cpp"
{ Penum __3en ;

# 1564 "/home/claude/cfront-3/src/print2.cpp"
__3en = (((struct enumdef *)(((struct enumdef *)(((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ))));
__1ls = __3en -> local_sig__4type ;
__1ns = (const char *)__3en -> nested_sig__4type ;
__1s = __3en -> string__7enumdef ;
__1d = __3en -> e_strlen__7enumdef ;
goto pppp ;
}

# 1572 "/home/claude/cfront-3/src/print2.cpp"
case 119 :
# 1573 "/home/claude/cfront-3/src/print2.cpp"
{ __1cl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ))));
__1ls = __1cl -> local_sig__4type ;
__1ns = (const char *)__1cl -> nested_sig__4type ;
__1s = __1cl -> string__8classdef ;
__1d = __1cl -> c_strlen__8classdef ;
pppp :
# 1579 "/home/claude/cfront-3/src/print2.cpp"
if (__1ns )__1s = __1ns ;
else { 
# 1581 "/home/claude/cfront-3/src/print2.cpp"
if (__1ls )__1s = (const char *)__1ls ;
if (__1d >= 100 )
# 1583 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= ('0' + (__1d / 100 ));
if (__1d >= 10 )
# 1585 "/home/claude/cfront-3/src/print2.cpp"
((*(__1p ++ )))= ('0' + ((__1d % 100 )/ 10 ));
((*(__1p ++ )))= ('0' + (__1d % 10 ));
}
while (((*(__1p ++ )))= ((*(__1s ++ ))));
-- __1p ;
break ;
}
case 114 :
# 1593 "/home/claude/cfront-3/src/print2.cpp"
default :
# 1594 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1594 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V42 ;

# 1594 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"signature of%k", (const struct ea *)( (__2__X43 =
# 1594 "/home/claude/cfront-3/src/print2.cpp"
__1t -> base__4node ), ( (( ((& __0__V42 )-> __O1__2ea.i = __2__X43 ), 0 ) ), (& __0__V42 )) ) ,
# 1594 "/home/claude/cfront-3/src/print2.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1597 "/home/claude/cfront-3/src/print2.cpp"
((*__1p ))= 0 ;
return __1p ;

# 1598 "/home/claude/cfront-3/src/print2.cpp"
}

# 1598 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 1601 "/home/claude/cfront-3/src/print2.cpp"
void dcl_print__8basetypeFv (register struct basetype *__0this )
# 1602 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1603 "/home/claude/cfront-3/src/print2.cpp"
Pname __1nn ;
Pclass __1cl ;

# 1606 "/home/claude/cfront-3/src/print2.cpp"
if (emode ){ 
# 1607 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> b_virtual__8basetype )
# 1608 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )77 ) ;
if (__0this -> b_inline__8basetype )
# 1610 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )75 ) ;
}
if ((ansi_opt && (! __0this -> ansi_const__4type ))|| emode )
# 1613 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> b_const__4type )
# 1614 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )26 ) ;
if (__0this -> b_unsigned__8basetype )
# 1616 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )37 ) ;

# 1618 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> base__4node ){ 
# 1618 "/home/claude/cfront-3/src/print2.cpp"
unsigned long __2__X46 ;

# 1619 "/home/claude/cfront-3/src/print2.cpp"
case 141 :
# 1620 "/home/claude/cfront-3/src/print2.cpp"
if (emode )
# 1621 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"any ", out_file ) ;
else 
# 1623 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"int ", out_file ) ;
break ;

# 1626 "/home/claude/cfront-3/src/print2.cpp"
case 138 :
# 1627 "/home/claude/cfront-3/src/print2.cpp"
if (emode )
# 1628 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"zero ", out_file ) ;
else 
# 1630 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"int ", out_file ) ;
break ;

# 1633 "/home/claude/cfront-3/src/print2.cpp"
case 38 :
# 1634 "/home/claude/cfront-3/src/print2.cpp"
if ((emode == 0 )&& (ansi_opt == 0 )){ 
# 1638 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )5 ) ;
break ;
}
case 5 :
# 1642 "/home/claude/cfront-3/src/print2.cpp"
case 29 :
# 1643 "/home/claude/cfront-3/src/print2.cpp"
case 21 :
# 1644 "/home/claude/cfront-3/src/print2.cpp"
case 22 :
# 1645 "/home/claude/cfront-3/src/print2.cpp"
case 122 :
# 1646 "/home/claude/cfront-3/src/print2.cpp"
case 15 :
# 1647 "/home/claude/cfront-3/src/print2.cpp"
case 11 :
# 1648 "/home/claude/cfront-3/src/print2.cpp"
case 181 :
# 1649 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( __0this -> base__4node ) ;
break ;

# 1652 "/home/claude/cfront-3/src/print2.cpp"
case 121 :
# 1653 "/home/claude/cfront-3/src/print2.cpp"
__1nn = __0this -> b_name__8basetype ;
eob :
# 1655 "/home/claude/cfront-3/src/print2.cpp"
if ((emode == 0 )&& (((struct enumdef *)(((struct enumdef *)__1nn -> __O1__4expr.tp ))))-> e_type__7enumdef ){ 
# 1656 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__8basetypeFv ( (((struct enumdef *)(((struct enumdef *)__1nn -> __O1__4expr.tp ))))-> e_type__7enumdef )
# 1656 "/home/claude/cfront-3/src/print2.cpp"
;
}
else 
# 1657 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1658 "/home/claude/cfront-3/src/print2.cpp"
const char *__3s ;

# 1658 "/home/claude/cfront-3/src/print2.cpp"
__3s = __1nn -> __O2__4expr.string ;
puttok__FUc ( (unsigned char )13 ) ;
if (((((*__3s ))!= '_' )|| ((__3s [1 ])!= '_' ))|| ((__3s [2 ])!= 'E' ))
# 1661 "/home/claude/cfront-3/src/print2.cpp"
print__4nameFUc ( __1nn , (unsigned char )0 ) ;
}
break ;

# 1665 "/home/claude/cfront-3/src/print2.cpp"
case 119 :
# 1666 "/home/claude/cfront-3/src/print2.cpp"
__1nn = __0this -> b_name__8basetype ;
cob :
# 1668 "/home/claude/cfront-3/src/print2.cpp"
__1cl = (((struct classdef *)(((struct classdef *)__1nn -> __O1__4expr.tp ))));
if ((emode && __1cl )&& (__1cl -> base__4node == 6 )){ 
# 1670 "/home/claude/cfront-3/src/print2.cpp"
const char *__3s ;

# 1670 "/home/claude/cfront-3/src/print2.cpp"
__3s = __1nn -> __O2__4expr.string ;
puttok__FUc ( __1cl -> csu__8classdef ) ;
if (((((*__3s ))!= '_' )|| ((__3s [1 ])!= '_' ))|| ((__3s [2 ])!= 'C' ))
# 1673 "/home/claude/cfront-3/src/print2.cpp"
print__4nameFUc ( __1nn , (unsigned char )0 ) ;
break ;
}
if (__1cl && ((__1cl -> csu__8classdef == 36 )|| (__1cl -> csu__8classdef == 167 )))
# 1677 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )36 ) ;
else 
# 1679 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )32 ) ;
if (__1cl && __1cl -> nested_sig__4type )
# 1681 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)" __%s ", __1cl -> nested_sig__4type )
# 1681 "/home/claude/cfront-3/src/print2.cpp"
;
else { 
# 1683 "/home/claude/cfront-3/src/print2.cpp"
char *__3s ;

# 1683 "/home/claude/cfront-3/src/print2.cpp"
__3s = 0 ;
if ((__1cl && __1cl -> lex_level__4type )&& __1cl -> local_sig__4type )
# 1685 "/home/claude/cfront-3/src/print2.cpp"
__3s = __1cl -> local_sig__4type ;
( fputs ( __3s ?(((const char *)__3s )):__1nn -> __O2__4expr.string , out_file ) , fputc ( (int )' ' , out_file ) ) ;
# 1686 "/home/claude/cfront-3/src/print2.cpp"

# 1687 "/home/claude/cfront-3/src/print2.cpp"
}
break ;

# 1690 "/home/claude/cfront-3/src/print2.cpp"
case 97 :
# 1691 "/home/claude/cfront-3/src/print2.cpp"
if (emode == 0 ){ 
# 1692 "/home/claude/cfront-3/src/print2.cpp"
switch (__0this -> b_name__8basetype -> __O1__4expr.tp -> base__4node ){ 
# 1693 "/home/claude/cfront-3/src/print2.cpp"
case 119 :
# 1694 "/home/claude/cfront-3/src/print2.cpp"
__1nn = (((struct basetype *)(((struct basetype *)__0this ->
# 1694 "/home/claude/cfront-3/src/print2.cpp"
b_name__8basetype -> __O1__4expr.tp ))))-> b_name__8basetype ;
goto cob ;
case 121 :
# 1697 "/home/claude/cfront-3/src/print2.cpp"
__1nn = (((struct basetype *)(((struct basetype *)__0this -> b_name__8basetype -> __O1__4expr.tp ))))-> b_name__8basetype ;
goto eob ;
}
}
print__4nameFUc ( __0this -> b_name__8basetype , (unsigned char )0 ) ;
break ;

# 1704 "/home/claude/cfront-3/src/print2.cpp"
default :
# 1705 "/home/claude/cfront-3/src/print2.cpp"
if (emode ){ 
# 1706 "/home/claude/cfront-3/src/print2.cpp"
int __3base2 ;

# 1706 "/home/claude/cfront-3/src/print2.cpp"
__3base2 = __0this -> base__4node ;
if (((0 < __3base2 )&& (__3base2 <= 255 ))&& (keys [__0this -> base__4node ]))
# 1708 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)" %s",
# 1708 "/home/claude/cfront-3/src/print2.cpp"
keys [__0this -> base__4node ]) ;
else 
# 1710 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )'?' , out_file ) ;
}
else 
# 1713 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1713 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V44 ;

# 1713 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V45 ;

# 1713 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%p->BT::dcl_print(%d)", (const struct ea *)( ((&
# 1713 "/home/claude/cfront-3/src/print2.cpp"
__0__V44 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V44 )) , (const struct ea *)( (__2__X46 = __0this -> base__4node ),
# 1713 "/home/claude/cfront-3/src/print2.cpp"
( (( ((& __0__V45 )-> __O1__2ea.i = __2__X46 ), 0 ) ), (& __0__V45 )) ) , (const struct
# 1713 "/home/claude/cfront-3/src/print2.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}

# 152 "/home/claude/cfront-3/src/print2.cpp"

# 154 "/home/claude/cfront-3/src/print2.cpp"

# 155 "/home/claude/cfront-3/src/print2.cpp"

# 153 "/home/claude/cfront-3/src/print2.cpp"

# 154 "/home/claude/cfront-3/src/print2.cpp"

# 157 "/home/claude/cfront-3/src/print2.cpp"

# 156 "/home/claude/cfront-3/src/print2.cpp"

# 157 "/home/claude/cfront-3/src/print2.cpp"

# 155 "/home/claude/cfront-3/src/print2.cpp"

# 156 "/home/claude/cfront-3/src/print2.cpp"

# 153 "/home/claude/cfront-3/src/print2.cpp"

# 1260 "/home/claude/cfront-3/src/cfront.h"

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );

# 153 "/home/claude/cfront-3/src/print2.cpp"

# 1717 "/home/claude/cfront-3/src/print2.cpp"
void dcl_print__4typeFP4name (register struct type *__0this , Pname __1n )
# 1721 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1722 "/home/claude/cfront-3/src/print2.cpp"
Ptype __1t ;
Pptr __1p ;
TOK __1pre ;

# 1725 "/home/claude/cfront-3/src/print2.cpp"
register struct dcl_buf *__0__X49 ;

# 1725 "/home/claude/cfront-3/src/print2.cpp"
register struct dcl_buf *__0__X50 ;

# 1725 "/home/claude/cfront-3/src/print2.cpp"
struct dcl_buf *__0__X51 ;

# 1722 "/home/claude/cfront-3/src/print2.cpp"
__1t = __0this ;

# 1724 "/home/claude/cfront-3/src/print2.cpp"
__1pre = 0 ;

# 1726 "/home/claude/cfront-3/src/print2.cpp"
if (__1t == 0 )
# 1727 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCc ( (int )'i' , (const char *)"0->dcl_print()") ;
if (__1n && (__1n -> __O1__4expr.tp != __1t ))
# 1729 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1729 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V47 ;

# 1729 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V48 ;

# 1729 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"not %n'sT (%p)", (const struct ea *)( ((&
# 1729 "/home/claude/cfront-3/src/print2.cpp"
__0__V47 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V47 )) , (const struct ea *)( ((& __0__V48 )-> __O1__2ea.p =
# 1729 "/home/claude/cfront-3/src/print2.cpp"
((const void *)__1t )), (& __0__V48 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1731 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> base__4node == 76 ){ 
# 1732 "/home/claude/cfront-3/src/print2.cpp"
{ { Plist __2gl ;

# 1732 "/home/claude/cfront-3/src/print2.cpp"
__2gl = (((struct gen *)(((struct gen *)__0this ))))-> fct_list__3gen ;

# 1732 "/home/claude/cfront-3/src/print2.cpp"
for(;__2gl ;__2gl = __2gl -> l__9name_list ) { 
# 1733 "/home/claude/cfront-3/src/print2.cpp"
Pname __3nn ;

# 1733 "/home/claude/cfront-3/src/print2.cpp"
__3nn = __2gl -> f__9name_list ;
dcl_print__4typeFP4name ( __3nn -> __O1__4expr.tp , __3nn ) ;
if (__2gl -> l__9name_list )puttok__FUc ( (unsigned char )72 ) ;
}
return ;

# 1737 "/home/claude/cfront-3/src/print2.cpp"
}

# 1737 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 1740 "/home/claude/cfront-3/src/print2.cpp"
tbuf = (tbufvec [freetbuf ]);
if (tbuf == 0 ){ 
# 1742 "/home/claude/cfront-3/src/print2.cpp"
if (freetbuf == 9)error__FiPCc ( (int )'i' , (const char *)"AT nesting overflow")
# 1742 "/home/claude/cfront-3/src/print2.cpp"
;
(tbufvec [freetbuf ])= (tbuf = (((struct dcl_buf *)__nw__FUl ( sizeof (struct dcl_buf )) )));
}
freetbuf ++ ;
if ((__0this -> base__4node == 114 )&& ((((struct basetype *)(((struct basetype *)__0this ))))-> b_bits__8basetype == 0 ))
# 1747 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X49 = tbuf ), ( ( (__0__X49 ->
# 1747 "/home/claude/cfront-3/src/print2.cpp"
b__7dcl_buf = 0 ), ( (__0__X49 -> n__7dcl_buf = ((struct name *)0 )), (__0__X49 -> cf__7dcl_buf = (__0__X49 -> li__7dcl_buf = (__0__X49 -> ri__7dcl_buf = 0 ))))
# 1747 "/home/claude/cfront-3/src/print2.cpp"
) , (((void )0 ))) ) ;
else 
# 1749 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X50 = tbuf ), ( ( (__0__X50 -> b__7dcl_buf = 0 ), ( (__0__X50 -> n__7dcl_buf = __1n ), (__0__X50 ->
# 1749 "/home/claude/cfront-3/src/print2.cpp"
cf__7dcl_buf = (__0__X50 -> li__7dcl_buf = (__0__X50 -> ri__7dcl_buf = 0 )))) ) , (((void )0 ))) ) ;
if (__1n && __1n -> n_xref__4name )
# 1751 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X51 = tbuf ), ( ((__0__X51 -> left__7dcl_buf [(++ __0__X51 -> li__7dcl_buf )])= ((unsigned char )125 )),
# 1751 "/home/claude/cfront-3/src/print2.cpp"
(((void )0 ))) ) ;

# 1753 "/home/claude/cfront-3/src/print2.cpp"
{ bit __1vec_const_flag ;
bit __1prev_const ;

# 1753 "/home/claude/cfront-3/src/print2.cpp"
__1vec_const_flag = 0 ;
__1prev_const = 0 ;
while (__1t ){ 
# 1756 "/home/claude/cfront-3/src/print2.cpp"
TOK __2k ;
switch (__1t -> base__4node ){ 
# 1757 "/home/claude/cfront-3/src/print2.cpp"
struct dcl_buf *__0__X58 ;

# 1757 "/home/claude/cfront-3/src/print2.cpp"
register struct dcl_buf *__0__X66 ;

# 1757 "/home/claude/cfront-3/src/print2.cpp"
struct dcl_buf *__0__X67 ;

# 1757 "/home/claude/cfront-3/src/print2.cpp"
struct basetype *__2__X68 ;

# 1757 "/home/claude/cfront-3/src/print2.cpp"
struct dcl_buf *__0__X69 ;

# 1758 "/home/claude/cfront-3/src/print2.cpp"
case 125 :
# 1759 "/home/claude/cfront-3/src/print2.cpp"
__1p = (((struct ptr *)(((struct ptr *)__1t ))));
__2k = ((__1p -> b_const__4type && (! __1p -> ansi_const__4type ))?163 :125 );
goto ppp ;
case 158 :
# 1763 "/home/claude/cfront-3/src/print2.cpp"
__1p = (((struct ptr *)(((struct ptr *)__1t ))));
__2k = ((__1p -> b_const__4type && (! __1p -> ansi_const__4type ))?164 :158 );
ppp :
# 1766 "/home/claude/cfront-3/src/print2.cpp"
if (__1p -> memof__3ptr ){ 
# 1767 "/home/claude/cfront-3/src/print2.cpp"
if (emode ){ 
# 1767 "/home/claude/cfront-3/src/print2.cpp"
struct dcl_buf *__0__X52 ;

# 1767 "/home/claude/cfront-3/src/print2.cpp"
register struct dcl_buf *__0__X53 ;

# 1767 "/home/claude/cfront-3/src/print2.cpp"
struct classdef *__2__X54 ;

# 1768 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X52 = tbuf ), ( ((__0__X52 -> left__7dcl_buf [(++ __0__X52 -> li__7dcl_buf )])= __2k ), (((void )0 ))) ) ;
( (__0__X53 = tbuf ), ( (__2__X54 = __1p -> memof__3ptr ), ( ( ((__0__X53 -> left__7dcl_buf [(++ __0__X53 -> li__7dcl_buf )])= 173 ),
# 1769 "/home/claude/cfront-3/src/print2.cpp"
((__0__X53 -> lnode__7dcl_buf [__0__X53 -> li__7dcl_buf ])= __2__X54 )) , (((void )0 ))) ) ) ;
}
else { 
# 1771 "/home/claude/cfront-3/src/print2.cpp"
struct dcl_buf *__0__X57 ;

# 1772 "/home/claude/cfront-3/src/print2.cpp"
__1t = skiptypedefs__4typeFv ( __1p -> typ__5pvtyp ) ;
if (__1t -> base__4node == 108 ){ 
# 1773 "/home/claude/cfront-3/src/print2.cpp"
struct dcl_buf *__0__X55 ;

# 1773 "/home/claude/cfront-3/src/print2.cpp"
struct basetype *__2__X56 ;

# 1774 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X55 = tbuf ), ( (__2__X56 = mptr_type ), ( ( (__0__X55 -> b__7dcl_buf = __2__X56 ), (__0__X55 -> cf__7dcl_buf = ((unsigned
# 1774 "/home/claude/cfront-3/src/print2.cpp"
char )0 ))) , (((void )0 ))) ) ) ;
goto zaq ;
}
else 
# 1778 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X57 = tbuf ), ( ((__0__X57 -> left__7dcl_buf [(++ __0__X57 -> li__7dcl_buf )])= __2k ), (((void )0 ))) ) ;
# 1778 "/home/claude/cfront-3/src/print2.cpp"

# 1779 "/home/claude/cfront-3/src/print2.cpp"
}
}
else 
# 1782 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X58 = tbuf ), ( ((__0__X58 -> left__7dcl_buf [(++ __0__X58 -> li__7dcl_buf )])= __2k ), (((void )0 ))) ) ;
# 1782 "/home/claude/cfront-3/src/print2.cpp"

# 1783 "/home/claude/cfront-3/src/print2.cpp"
__1pre = 125 ;
__1t = __1p -> typ__5pvtyp ;
break ;
case 110 :
# 1787 "/home/claude/cfront-3/src/print2.cpp"
{ Pvec __4v ;

# 1787 "/home/claude/cfront-3/src/print2.cpp"
__4v = (((struct vec *)(((struct vec *)__1t ))));
if ((Cast && (__1pre != 125 ))&& (__1pre != 110 )){ 
# 1788 "/home/claude/cfront-3/src/print2.cpp"
struct dcl_buf *__0__X59 ;

# 1789 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X59 = tbuf ), ( ((__0__X59 -> left__7dcl_buf [(++ __0__X59 -> li__7dcl_buf )])= ((unsigned char )125 )), (((void )0 ))) )
# 1789 "/home/claude/cfront-3/src/print2.cpp"
;
__1pre = 125 ;
}
else { 
# 1792 "/home/claude/cfront-3/src/print2.cpp"
register struct dcl_buf *__0__X60 ;

# 1792 "/home/claude/cfront-3/src/print2.cpp"
register struct dcl_buf *__0__X61 ;

# 1793 "/home/claude/cfront-3/src/print2.cpp"
if (__1pre == 125 )
# 1794 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X60 = tbuf ), ( ( ((__0__X60 -> left__7dcl_buf [(++ __0__X60 -> li__7dcl_buf )])= ((unsigned char )40 )),
# 1794 "/home/claude/cfront-3/src/print2.cpp"
(((void )0 ))) , ( ( ((__0__X60 -> right__7dcl_buf [(++ __0__X60 -> ri__7dcl_buf )])= ((unsigned char )41 )), ((__0__X60 -> rnode__7dcl_buf [__0__X60 ->
# 1794 "/home/claude/cfront-3/src/print2.cpp"
ri__7dcl_buf ])= ((struct node *)0 ))) , (((void )0 ))) ) ) ;
( (__0__X61 = tbuf ), ( ( ((__0__X61 -> right__7dcl_buf [(++ __0__X61 -> ri__7dcl_buf )])= ((unsigned char )110 )), ((__0__X61 -> rnode__7dcl_buf [__0__X61 ->
# 1795 "/home/claude/cfront-3/src/print2.cpp"
ri__7dcl_buf ])= ((struct node *)__4v ))) , (((void )0 ))) ) ;
__1pre = 110 ;
}
if (ansi_opt ){ 
# 1799 "/home/claude/cfront-3/src/print2.cpp"
Ptype __5t ;

# 1799 "/home/claude/cfront-3/src/print2.cpp"
__5t = (((struct vec *)(((struct vec *)__4v ))))-> typ__5pvtyp ;
while (__5t && (skiptypedefs__4typeFv ( __5t ) -> base__4node == 110 ))
# 1801 "/home/claude/cfront-3/src/print2.cpp"
__5t = (((struct vec *)(((struct vec *)__5t ))))-> typ__5pvtyp ;
switch (__5t ?(((int )skiptypedefs__4typeFv ( __5t ) -> base__4node )):0 ){ 
# 1803 "/home/claude/cfront-3/src/print2.cpp"
case 125 :
# 1804 "/home/claude/cfront-3/src/print2.cpp"
case 158 :
# 1805 "/home/claude/cfront-3/src/print2.cpp"
case 5 :
# 1806 "/home/claude/cfront-3/src/print2.cpp"
case 29 :
# 1807 "/home/claude/cfront-3/src/print2.cpp"
case 21 :
# 1808 "/home/claude/cfront-3/src/print2.cpp"
case 121 :
# 1809 "/home/claude/cfront-3/src/print2.cpp"
case 22 :
# 1810 "/home/claude/cfront-3/src/print2.cpp"
case
# 1810 "/home/claude/cfront-3/src/print2.cpp"
122 :
# 1811 "/home/claude/cfront-3/src/print2.cpp"
case 15 :
# 1812 "/home/claude/cfront-3/src/print2.cpp"
case 11 :
# 1813 "/home/claude/cfront-3/src/print2.cpp"
case 181 :
# 1814 "/home/claude/cfront-3/src/print2.cpp"
case 114 :
# 1815 "/home/claude/cfront-3/src/print2.cpp"
case 141 :
# 1816 "/home/claude/cfront-3/src/print2.cpp"
break ;
default :
# 1818 "/home/claude/cfront-3/src/print2.cpp"
__1vec_const_flag = 1 ;
break ;
}
}
__1t = __4v -> typ__5pvtyp ;
break ;
}

# 1826 "/home/claude/cfront-3/src/print2.cpp"
case 108 :
# 1827 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1828 "/home/claude/cfront-3/src/print2.cpp"
Pfct __4f ;

# 1829 "/home/claude/cfront-3/src/print2.cpp"
register struct dcl_buf *__0__X62 ;

# 1829 "/home/claude/cfront-3/src/print2.cpp"
register struct dcl_buf *__0__X63 ;

# 1829 "/home/claude/cfront-3/src/print2.cpp"
struct classdef *__2__X64 ;

# 1829 "/home/claude/cfront-3/src/print2.cpp"
register struct dcl_buf *__0__X65 ;

# 1828 "/home/claude/cfront-3/src/print2.cpp"
__4f = (((struct fct *)(((struct fct *)__1t ))));
if (__1pre == 125 )
# 1830 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X62 = tbuf ), ( ( ((__0__X62 -> left__7dcl_buf [(++ __0__X62 -> li__7dcl_buf )])= ((unsigned char )40 )),
# 1830 "/home/claude/cfront-3/src/print2.cpp"
(((void )0 ))) , ( ( ((__0__X62 -> right__7dcl_buf [(++ __0__X62 -> ri__7dcl_buf )])= ((unsigned char )41 )), ((__0__X62 -> rnode__7dcl_buf [__0__X62 ->
# 1830 "/home/claude/cfront-3/src/print2.cpp"
ri__7dcl_buf ])= ((struct node *)0 ))) , (((void )0 ))) ) ) ;
else if ((emode && __4f -> memof__3fct )&& (__1n == 0 ))
# 1832 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X63 = tbuf ), ( (__2__X64 = __4f -> memof__3fct ), (
# 1832 "/home/claude/cfront-3/src/print2.cpp"
( ((__0__X63 -> left__7dcl_buf [(++ __0__X63 -> li__7dcl_buf )])= 173 ), ((__0__X63 -> lnode__7dcl_buf [__0__X63 -> li__7dcl_buf ])= __2__X64 )) , (((void )0 ))) )
# 1832 "/home/claude/cfront-3/src/print2.cpp"
) ;
( (__0__X65 = tbuf ), ( ( ((__0__X65 -> right__7dcl_buf [(++ __0__X65 -> ri__7dcl_buf )])= ((unsigned char )108 )), ((__0__X65 -> rnode__7dcl_buf [__0__X65 ->
# 1833 "/home/claude/cfront-3/src/print2.cpp"
ri__7dcl_buf ])= ((struct node *)__4f ))) , (((void )0 ))) ) ;
__1pre = 108 ;
__1t = (__4f -> s_returns__3fct ?__4f -> s_returns__3fct :__4f -> returns__3fct );
break ;
}

# 1839 "/home/claude/cfront-3/src/print2.cpp"
case 114 :
# 1840 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X66 = tbuf ), ( ( ((__0__X66 -> right__7dcl_buf [(++ __0__X66 -> ri__7dcl_buf )])= ((unsigned char )114 )), ((__0__X66 ->
# 1840 "/home/claude/cfront-3/src/print2.cpp"
rnode__7dcl_buf [__0__X66 -> ri__7dcl_buf ])= ((struct node *)__1t ))) , (((void )0 ))) ) ;
( (__0__X67 = tbuf ), ( (__2__X68 = (((struct basetype *)(((struct basetype *)(((struct basetype *)(((struct basetype *)__1t ))))-> __O1__8basetype.b_fieldtype ))))), ( ( (__0__X67 ->
# 1841 "/home/claude/cfront-3/src/print2.cpp"
b__7dcl_buf = __2__X68 ), (__0__X67 -> cf__7dcl_buf = ((unsigned char )0 ))) , (((void )0 ))) ) ) ;
__1t = 0 ;
break ;

# 1845 "/home/claude/cfront-3/src/print2.cpp"
case 0 :
# 1846 "/home/claude/cfront-3/src/print2.cpp"
if (! emode )error__FiPCc ( (int )'i' , (const char *)"noBT(B=0)") ;
# 1846 "/home/claude/cfront-3/src/print2.cpp"

# 1847 "/home/claude/cfront-3/src/print2.cpp"
goto dobase ;

# 1849 "/home/claude/cfront-3/src/print2.cpp"
case 97 :
# 1850 "/home/claude/cfront-3/src/print2.cpp"
if ((Cast && TCast )|| (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> lex_level__4name ){ 
# 1851 "/home/claude/cfront-3/src/print2.cpp"
Ptype __4tt ;
bit __4ok ;

# 1851 "/home/claude/cfront-3/src/print2.cpp"
__4tt = __1t ;
__4ok = 0 ;
while (__4tt && (__4tt -> base__4node == 97 )){ 
# 1854 "/home/claude/cfront-3/src/print2.cpp"
if ((((struct basetype *)(((struct basetype *)__4tt ))))-> b_const__4type )
# 1855 "/home/claude/cfront-3/src/print2.cpp"
__4ok = 1 ;
if ((((struct basetype *)(((struct basetype *)__4tt ))))-> ansi_const__4type ){ 
# 1857 "/home/claude/cfront-3/src/print2.cpp"
__4ok = 0 ;
break ;
}
__4tt = ( (((struct basetype *)(((struct basetype *)__4tt ))))-> b_name__8basetype -> __O1__4expr.tp ) ;
}
if ((__4ok && __4tt )&& is_ptr_or_ref__4typeFv ( __4tt ) )
# 1863 "/home/claude/cfront-3/src/print2.cpp"
__4ok = 0 ;
__1t = skiptypedefs__4typeFv ( __1t ) ;
if (((emode || ansi_opt )&& __4ok )&& (! __1prev_const ))
# 1870 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1871 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"const ",
# 1871 "/home/claude/cfront-3/src/print2.cpp"
out_file ) ;
__1prev_const = 1 ;
}
break ;
}

# 1877 "/home/claude/cfront-3/src/print2.cpp"
default :
# 1878 "/home/claude/cfront-3/src/print2.cpp"
dobase :
# 1879 "/home/claude/cfront-3/src/print2.cpp"
if (emode ){ 
# 1880 "/home/claude/cfront-3/src/print2.cpp"
const char *__4s ;
Ptype __4tt ;

# 1881 "/home/claude/cfront-3/src/print2.cpp"
__4tt = skiptypedefs__4typeFv ( __1t ) ;

# 1883 "/home/claude/cfront-3/src/print2.cpp"
switch (__4tt -> base__4node ){ 
# 1884 "/home/claude/cfront-3/src/print2.cpp"
case 6 :
# 1885 "/home/claude/cfront-3/src/print2.cpp"
__4s = (((struct classdef *)(((struct classdef *)__4tt ))))-> string__8classdef ;
if ((((((struct templ_classdef *)(((struct templ_classdef *)__4tt ))))-> class_base__8classdef == 4)|| ((((struct templ_classdef *)(((struct templ_classdef *)__4tt ))))-> class_base__8classdef == 5))|| (! ((((__4s [0 ])== '_' )&&
# 1886 "/home/claude/cfront-3/src/print2.cpp"
((__4s [1 ])== '_' ))&& ((__4s [2 ])== 'C' ))))
# 1892 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1893 "/home/claude/cfront-3/src/print2.cpp"
print__4nameFUc ( (((struct basetype *)(((struct basetype *)(((struct classdef *)(((struct classdef *)__4tt ))))-> k_tbl__8classdef -> k_name__6ktable -> __O1__4expr.tp ))))-> b_name__8basetype ,
# 1893 "/home/claude/cfront-3/src/print2.cpp"
(unsigned char )0 ) ;
-- freetbuf ;
return ;
}
__4s = (const char *)"class";
goto fret ;
case 13 :
# 1900 "/home/claude/cfront-3/src/print2.cpp"
__4s = (const char *)"enum";
goto fret ;
case 76 :
# 1903 "/home/claude/cfront-3/src/print2.cpp"
__4s = (const char *)"overloaded";
fret :
# 1905 "/home/claude/cfront-3/src/print2.cpp"
fputs ( __4s , out_file ) ;
freetbuf -- ;
return ;
}
}

# 1911 "/home/claude/cfront-3/src/print2.cpp"
( (__0__X69 = tbuf ), ( ( (__0__X69 -> b__7dcl_buf = (((struct basetype *)(((struct basetype *)__1t ))))), (__0__X69 -> cf__7dcl_buf = __1vec_const_flag )) ,
# 1911 "/home/claude/cfront-3/src/print2.cpp"
(((void )0 ))) ) ;
goto zaq ;
}
}
zaq :
# 1916 "/home/claude/cfront-3/src/print2.cpp"
put__7dcl_bufFv ( tbuf ) ;
freetbuf -- ;

# 1917 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 649 "/home/claude/cfront-3/src/cfront.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 1920 "/home/claude/cfront-3/src/print2.cpp"
void dcl_print__3fctFv (register struct fct *__0this )
# 1921 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 1923 "/home/claude/cfront-3/src/print2.cpp"
Pname __1nn ;
if (( (__0this -> fct_base__3fct != 0)) && (current_fct_instantiation != __0this ))
# 1925 "/home/claude/cfront-3/src/print2.cpp"
return ;

# 1927 "/home/claude/cfront-3/src/print2.cpp"
if (emode ){ 
# 1928 "/home/claude/cfront-3/src/print2.cpp"
arg_print__3fctFv ( __0this ) ;
return ;
}

# 1932 "/home/claude/cfront-3/src/print2.cpp"
{ Pname __1at ;

# 1932 "/home/claude/cfront-3/src/print2.cpp"
__1at = __0this -> f_args__3fct ;
fputc ( (int )'(' , out_file ) ;

# 1935 "/home/claude/cfront-3/src/print2.cpp"
if (ansi_opt ){ 
# 1937 "/home/claude/cfront-3/src/print2.cpp"
__1at = (__0this -> f_this__3fct ?__0this -> f_this__3fct :(__0this -> f_result__3fct ?__0this -> f_result__3fct :__0this -> argtype__3fct ));

# 1940 "/home/claude/cfront-3/src/print2.cpp"
if (__1at == 0 ){ 
# 1941 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> nargs_known__3fct == 155 ){ 
# 1942 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )')' , out_file ) ;
return ;
}
puttok__FUc ( (unsigned char )38 ) ;
}
else if (__0this -> body__3fct && (Cast == 0 )){ 
# 1948 "/home/claude/cfront-3/src/print2.cpp"
if (__1at == __0this -> argtype__3fct )
# 1949 "/home/claude/cfront-3/src/print2.cpp"
__1at = __0this -> f_args__3fct ;
dcl_print__4nameFUc ( __1at , (unsigned char )71 ) ;
}
else { 
# 1953 "/home/claude/cfront-3/src/print2.cpp"
{ { Pname __3a ;

# 1953 "/home/claude/cfront-3/src/print2.cpp"
__3a = __0this -> argtype__3fct ;

# 1953 "/home/claude/cfront-3/src/print2.cpp"
for(;__3a ;__3a = __3a -> __O1__4name.n_list ) { 
# 1954 "/home/claude/cfront-3/src/print2.cpp"
Pname __4cln ;

# 1955 "/home/claude/cfront-3/src/print2.cpp"
struct classdef *__0__X70 ;

# 1954 "/home/claude/cfront-3/src/print2.cpp"
__4cln = is_cl_obj__4typeFv ( __3a -> __O1__4expr.tp ) ;
if (__4cln && ( (__0__X70 = (((struct classdef *)(((struct classdef *)__4cln -> __O1__4expr.tp ))))), ( __0__X70 -> c_itor__8classdef ) ) )
# 1956 "/home/claude/cfront-3/src/print2.cpp"
__3a -> n_xref__4name =
# 1956 "/home/claude/cfront-3/src/print2.cpp"
1 ;
}
for(__1nn = __1at ;__1nn ;) { 
# 1959 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__4typeFP4name ( __1nn -> __O1__4expr.tp , __1nn ) ;

# 1961 "/home/claude/cfront-3/src/print2.cpp"
if (__1nn = __1nn -> __O1__4name.n_list )
# 1962 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )71 ) ;
else 
# 1964 "/home/claude/cfront-3/src/print2.cpp"
break ;
}

# 1965 "/home/claude/cfront-3/src/print2.cpp"
}

# 1965 "/home/claude/cfront-3/src/print2.cpp"
}
}
if (__0this -> nargs_known__3fct == 155 )
# 1968 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)",...", out_file ) ;
fputc ( (int )')' , out_file ) ;
}
else { 
# 1973 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> body__3fct && (Cast == 0 )){ 
# 1974 "/home/claude/cfront-3/src/print2.cpp"
for(__1nn = __1at ;__1nn ;) { 
# 1975 "/home/claude/cfront-3/src/print2.cpp"
print__4nameFUc ( __1nn , (unsigned char
# 1975 "/home/claude/cfront-3/src/print2.cpp"
)0 ) ;
if (__1nn = __1nn -> __O1__4name.n_list )
# 1977 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )71 ) ;
else 
# 1979 "/home/claude/cfront-3/src/print2.cpp"
break ;
}

# 1995 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )')' , out_file ) ;

# 2001 "/home/claude/cfront-3/src/print2.cpp"
}
else 
# 2003 "/home/claude/cfront-3/src/print2.cpp"
fputc ( (int )')' , out_file ) ;
}

# 2004 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 1014 "/home/claude/cfront-3/src/cfront.h"
void print__4stmtFv (struct stmt *__0this );

# 2007 "/home/claude/cfront-3/src/print2.cpp"
void print_body__FP3fct (Pfct __1f )
# 2008 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2011 "/home/claude/cfront-3/src/print2.cpp"
if (Cast == 0 ){ 
# 2012 "/home/claude/cfront-3/src/print2.cpp"
if ((ansi_opt == 0 )&& __1f -> f_args__3fct ){ 
# 2013 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__4nameFUc ( __1f -> f_args__3fct , (unsigned
# 2013 "/home/claude/cfront-3/src/print2.cpp"
char )72 ) ;
if ((last_ll == 0 )&& (last_ll = __1f -> body__3fct -> where__4stmt . line__3loc ))
# 2015 "/home/claude/cfront-3/src/print2.cpp"
putline__3locFv ( & __1f -> body__3fct -> where__4stmt ) ;
}

# 2018 "/home/claude/cfront-3/src/print2.cpp"
if (MAIN ){ 
# 2019 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"{ extern void _main(); _main(); ", out_file ) ;
print__4stmtFv ( (struct stmt *)__1f -> body__3fct ) ;
puttok__FUc ( (unsigned char )74 ) ;
}
else print__4stmtFv ( (struct stmt *)__1f -> body__3fct ) ;
}
}

# 2027 "/home/claude/cfront-3/src/print2.cpp"
void print_members__8classdefFv (struct classdef *__0this );

# 350 "/home/claude/cfront-3/src/cfront.h"
int align__4typeFv (struct type *__0this );

# 37 "/home/claude/cfront-3/src/cfront.h"
extern char *make_name__FUc (TOK );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 2027 "/home/claude/cfront-3/src/print2.cpp"
void print_members__8classdefFv (register struct classdef *__0this )
# 2028 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2029 "/home/claude/cfront-3/src/print2.cpp"
int __1i ;

# 2031 "/home/claude/cfront-3/src/print2.cpp"
Pbcl __1l ;

# 2031 "/home/claude/cfront-3/src/print2.cpp"
__1l = __0this -> baselist__8classdef ;
if (__1l ){ 
# 2033 "/home/claude/cfront-3/src/print2.cpp"
if (__1l -> base__4node == 85 ){ 
# 2034 "/home/claude/cfront-3/src/print2.cpp"
print_members__8classdefFv ( __1l -> bclass__6basecl ) ;

# 2036 "/home/claude/cfront-3/src/print2.cpp"
{ int __3boff ;
int __3ba ;
int __3xtra ;
int __3waste ;

# 2036 "/home/claude/cfront-3/src/print2.cpp"
__3boff = __1l -> bclass__6basecl -> real_size__8classdef ;
__3ba = align__4typeFv ( (struct type *)__1l -> bclass__6basecl ) ;
__3xtra = (__3boff % __3ba );
__3waste = (__3xtra ?(__3ba - __3xtra ):0 );
if (__3waste ){ 
# 2043 "/home/claude/cfront-3/src/print2.cpp"
char *__4s ;

# 2043 "/home/claude/cfront-3/src/print2.cpp"
__4s = make_name__FUc ( (unsigned char )'W' ) ;
fprintf ( out_file , (const char *)"char %s[%d];\n", __4s , __3waste ) ;
__dl__FPv ( (void *)__4s ) ;
}
__1l = __1l -> next__6basecl ;

# 2047 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 2050 "/home/claude/cfront-3/src/print2.cpp"
for(;__1l ;__1l = __1l -> next__6basecl ) 
# 2056 "/home/claude/cfront-3/src/print2.cpp"
if (__1l -> base__4node == 85 ){ 
# 2057 "/home/claude/cfront-3/src/print2.cpp"
Pclass __3bcl ;
char *__3str ;
const char *__3cs ;

# 2057 "/home/claude/cfront-3/src/print2.cpp"
__3bcl = __1l -> bclass__6basecl ;
__3str = 0 ;
__3cs = (__3bcl -> nested_sig__4type ?(((const char *)__3bcl -> nested_sig__4type )):__3bcl -> string__8classdef );
if (__3bcl -> lex_level__4type && (! __3bcl -> nested_sig__4type ))
# 2061 "/home/claude/cfront-3/src/print2.cpp"
__3str = __3bcl -> local_sig__4type ;
puttok__FUc ( (unsigned char )32 ) ;
if (__3bcl -> nested_sig__4type )fputs ( (const char *)"__", out_file ) ;
( fputs ( __3str ?(((const char *)__3str )):__3cs , out_file ) , fputc ( (int )' ' , out_file ) ) ;
( fputc ( (int )'O' , out_file ) , fputs ( __3bcl -> string__8classdef , out_file ) ) ;
puttok__FUc ( (unsigned char )72 ) ;
}
}

# 2070 "/home/claude/cfront-3/src/print2.cpp"
{ { Pname __1nn ;

# 2071 "/home/claude/cfront-3/src/print2.cpp"
struct table *__0__X71 ;

# 2071 "/home/claude/cfront-3/src/print2.cpp"
int __2__X72 ;

# 2071 "/home/claude/cfront-3/src/print2.cpp"
struct table *__0__X73 ;

# 2071 "/home/claude/cfront-3/src/print2.cpp"
int __2__X74 ;

# 2070 "/home/claude/cfront-3/src/print2.cpp"
__1nn = ( (__0__X73 = __0this -> memtbl__8classdef ), ( (__2__X74 = (__1i = 1 )), ( (((__2__X74 <= 0 )|| (__0__X73 -> free_slot__5table <=
# 2070 "/home/claude/cfront-3/src/print2.cpp"
__2__X74 ))?(((struct name *)0 )):(__0__X73 -> entries__5table [__2__X74 ]))) ) ) ;

# 2070 "/home/claude/cfront-3/src/print2.cpp"
for(;__1nn ;__1nn = (__1nn -> n_tbl_list__4name ?__1nn -> n_tbl_list__4name :( (__0__X71 = __0this -> memtbl__8classdef ), ( (__2__X72 = (++ __1i )), ( (((__2__X72 <= 0 )||
# 2070 "/home/claude/cfront-3/src/print2.cpp"
(__0__X71 -> free_slot__5table <= __2__X72 ))?(((struct name *)0 )):(__0__X71 -> entries__5table [__2__X72 ]))) ) ) )) { 
# 2071 "/home/claude/cfront-3/src/print2.cpp"
if (__1nn -> base__4node == 123 )continue ;
# 2071 "/home/claude/cfront-3/src/print2.cpp"

# 2072 "/home/claude/cfront-3/src/print2.cpp"
if (((((((__1nn -> base__4node == 85 )&& (__1nn -> n_anon__4name == 0 ))&& (__1nn -> __O1__4expr.tp -> base__4node != 108 ))&& (__1nn -> __O1__4expr.tp -> base__4node !=
# 2072 "/home/claude/cfront-3/src/print2.cpp"
76 ))&& (__1nn -> __O1__4expr.tp -> base__4node != 6 ))&& (__1nn -> __O1__4expr.tp -> base__4node != 13 ))&& (__1nn -> n_stclass__4name != 31 ))
# 2086 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2087 "/home/claude/cfront-3/src/print2.cpp"
Pexpr __3i ;

# 2087 "/home/claude/cfront-3/src/print2.cpp"
__3i = __1nn -> __O3__4expr.n_initializer ;
__1nn -> __O3__4expr.n_initializer = 0 ;
;
dcl_print__4nameFUc ( __1nn , (unsigned char )0 ) ;
__1nn -> __O3__4expr.n_initializer = __3i ;
}
}

# 2095 "/home/claude/cfront-3/src/print2.cpp"
for(__1l = __0this -> baselist__8classdef ;__1l ;__1l = __1l -> next__6basecl ) 
# 2096 "/home/claude/cfront-3/src/print2.cpp"
if ((__1l -> base__4node == 77 )&& __1l -> ptr_offset__6basecl ){ 
# 2097 "/home/claude/cfront-3/src/print2.cpp"
Pclass __2bcl ;
char *__2str ;
const char *__2cs ;

# 2097 "/home/claude/cfront-3/src/print2.cpp"
__2bcl = __1l -> bclass__6basecl ;
__2str = 0 ;
__2cs = (__2bcl -> nested_sig__4type ?(((const char *)__2bcl -> nested_sig__4type )):__2bcl -> string__8classdef );

# 2101 "/home/claude/cfront-3/src/print2.cpp"
if (__2bcl -> lex_level__4type && (! __2bcl -> nested_sig__4type ))
# 2102 "/home/claude/cfront-3/src/print2.cpp"
__2str = __2bcl -> local_sig__4type ;

# 2104 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned char )32 ) ;
if (__2bcl -> nested_sig__4type )fputs ( (const char *)"__", out_file ) ;
( fputs ( __2str ?(((const char *)__2str )):__2cs , out_file ) , fputc ( (int )' ' , out_file ) ) ;
fputc ( (int )'*' , out_file ) ;
( fputc ( (int )'P' , out_file ) , fputs ( __2bcl -> string__8classdef , out_file ) ) ;
puttok__FUc ( (unsigned char )72 ) ;
}

# 2110 "/home/claude/cfront-3/src/print2.cpp"
}

# 2110 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 2113 "/home/claude/cfront-3/src/print2.cpp"
struct vl *vlist = 0 ;

# 855 "/home/claude/cfront-3/src/cfront.h"
extern char *vtbl_name__FPCcT1 (const char *, const char *);

# 2115 "/home/claude/cfront-3/src/print2.cpp"
extern void really_really_print__FP8classdefP4virtPCcPc (Pclass __0cl , Pvirt __0vtab , const char *__0s , char *__0ss );

# 13 "/home/claude/incl-linux32/string.h"
extern char *strcat (char *, const char *);

# 747 "/home/claude/cfront-3/src/cfront.h"
extern void ptbl_add_pair__FPCcT1 (const char *, const char *);

# 2117 "/home/claude/cfront-3/src/print2.cpp"
int p2__FP4nameP4typeP8classdefP4virtPc (Pname __1nn , Ptype __1t , Pclass __1cl , Pvirt __1vtab , char *__1s )
# 2118 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2119 "/home/claude/cfront-3/src/print2.cpp"
int __1init ;

# 2121 "/home/claude/cfront-3/src/print2.cpp"
if (__1t -> base__4node == 108 ){ 
# 2122 "/home/claude/cfront-3/src/print2.cpp"
Pfct __2f ;

# 2122 "/home/claude/cfront-3/src/print2.cpp"
__2f = (((struct fct *)(((struct fct *)__1t ))));

# 2124 "/home/claude/cfront-3/src/print2.cpp"
if ((((__1nn -> __O3__4expr.n_initializer || (__1nn -> n_sto__4name == 31 ))|| __2f -> f_inline__3fct )|| __2f -> f_imeasure__3fct )|| (__2f -> f_virtual__3fct == 0 ))
# 2135 "/home/claude/cfront-3/src/print2.cpp"
return 0 ;
# 2135 "/home/claude/cfront-3/src/print2.cpp"

# 2136 "/home/claude/cfront-3/src/print2.cpp"
__1init = (__2f -> body__3fct != 0 );
}
else 
# 2139 "/home/claude/cfront-3/src/print2.cpp"
__1init = (__1nn -> __O3__4expr.n_initializer != 0 );

# 2141 "/home/claude/cfront-3/src/print2.cpp"
{ int __1oo ;

# 2141 "/home/claude/cfront-3/src/print2.cpp"
__1oo = vtbl_opt ;
vtbl_opt = 1 ;
{ const char *__1cs ;
const char *__1sstr ;
const char *__1ss ;

# 2143 "/home/claude/cfront-3/src/print2.cpp"
__1cs = (__1cl -> nested_sig__4type ?(((const char *)__1cl -> nested_sig__4type )):__1cl -> string__8classdef );
__1sstr = (const char *)((__1cl -> lex_level__4type && (! __1cl -> nested_sig__4type ))?__1cl -> local_sig__4type :(((char *)0 )));
__1ss = (const char *)vtbl_name__FPCcT1 ( __1vtab -> string__4virt , __1sstr ?__1sstr :__1cs ) ;

# 2147 "/home/claude/cfront-3/src/print2.cpp"
if (__1init ){ 
# 2148 "/home/claude/cfront-3/src/print2.cpp"
really_really_print__FP8classdefP4virtPCcPc ( __1cl , __1vtab , __1ss , __1s ) ;
}
else { 
# 2151 "/home/claude/cfront-3/src/print2.cpp"
char *__2vstr ;

# 2157 "/home/claude/cfront-3/src/print2.cpp"
Pname __2nn ;

# 2151 "/home/claude/cfront-3/src/print2.cpp"
__2vstr = 0 ;
if (__1vtab && __1vtab -> string__4virt ){ 
# 2153 "/home/claude/cfront-3/src/print2.cpp"
__2vstr = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* ((strlen ( __1vtab ->
# 2153 "/home/claude/cfront-3/src/print2.cpp"
string__4virt ) + __1cl -> c_strlen__8classdef )+ 1 ))) ));
strcpy ( __2vstr , __1vtab -> string__4virt ) ;
strcat ( __2vstr , __1cl -> string__8classdef ) ;
}
;
if (__2nn = look__5tableFPCcUc ( ptbl , __2vstr ?(((const char *)__2vstr )):__1cl -> string__8classdef , (unsigned char )0 ) ){ 
# 2159 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file ,
# 2159 "/home/claude/cfront-3/src/print2.cpp"
(const char *)"extern struct __mptr %s[];\n", __1ss ) ;
(__1s [2 ])= 'p' ;
ptbl_add_pair__FPCcT1 ( (const char *)__1s , __1ss ) ;
__2nn -> n_key__4name = 159 ;
}
__dl__FPv ( (void *)__2vstr ) ;
}
vtbl_opt = __1oo ;

# 2168 "/home/claude/cfront-3/src/print2.cpp"
__dl__FPv ( (void *)(((char *)__1ss ))) ;

# 2170 "/home/claude/cfront-3/src/print2.cpp"
return 1 ;

# 2170 "/home/claude/cfront-3/src/print2.cpp"
}

# 2170 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 234 "/home/claude/cfront-3/src/cfront.h"

# 2173 "/home/claude/cfront-3/src/print2.cpp"
void really_print__8classdefFP4virt (register struct classdef *__0this , Pvirt __1vtab )
# 2174 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2175 "/home/claude/cfront-3/src/print2.cpp"
int __1oo ;

# 2175 "/home/claude/cfront-3/src/print2.cpp"
__1oo = vtbl_opt ;
vtbl_opt = -1;
{ const char *__1cs ;
char *__1str ;
char *__1s ;

# 2183 "/home/claude/cfront-3/src/print2.cpp"
int __1i ;

# 2177 "/home/claude/cfront-3/src/print2.cpp"
__1cs = (__0this -> nested_sig__4type ?(((const char *)__0this -> nested_sig__4type )):__0this -> string__8classdef );
__1str = ((__0this -> lex_level__4type && (! __0this -> nested_sig__4type ))?__0this -> local_sig__4type :(((char *)0 )));
__1s = vtbl_name__FPCcT1 ( __1vtab -> string__4virt , __1str ?(((const char *)__1str )):__1cs ) ;
vtbl_opt = __1oo ;

# 2183 "/home/claude/cfront-3/src/print2.cpp"
;
{ { Pname __1nn ;

# 2185 "/home/claude/cfront-3/src/print2.cpp"
struct table *__0__X75 ;

# 2185 "/home/claude/cfront-3/src/print2.cpp"
int __2__X76 ;

# 2185 "/home/claude/cfront-3/src/print2.cpp"
struct table *__0__X77 ;

# 2185 "/home/claude/cfront-3/src/print2.cpp"
int __2__X78 ;

# 2184 "/home/claude/cfront-3/src/print2.cpp"
__1nn = ( (__0__X77 = __0this -> memtbl__8classdef ), ( (__2__X78 = (__1i = 1 )), ( (((__2__X78 <= 0 )|| (__0__X77 -> free_slot__5table <=
# 2184 "/home/claude/cfront-3/src/print2.cpp"
__2__X78 ))?(((struct name *)0 )):(__0__X77 -> entries__5table [__2__X78 ]))) ) ) ;

# 2184 "/home/claude/cfront-3/src/print2.cpp"
for(;__1nn ;__1nn = (__1nn -> n_tbl_list__4name ?__1nn -> n_tbl_list__4name :( (__0__X75 = __0this -> memtbl__8classdef ), ( (__2__X76 = (++ __1i )), ( (((__2__X76 <= 0 )||
# 2184 "/home/claude/cfront-3/src/print2.cpp"
(__0__X75 -> free_slot__5table <= __2__X76 ))?(((struct name *)0 )):(__0__X75 -> entries__5table [__2__X76 ]))) ) ) )) { 
# 2185 "/home/claude/cfront-3/src/print2.cpp"
if ((__1nn -> base__4node == 123 )|| (__1nn ->
# 2185 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp == 0 ))continue ;
{ Ptype __2t ;

# 2186 "/home/claude/cfront-3/src/print2.cpp"
__2t = skiptypedefs__4typeFv ( __1nn -> __O1__4expr.tp ) ;

# 2188 "/home/claude/cfront-3/src/print2.cpp"
if (__2t )
# 2189 "/home/claude/cfront-3/src/print2.cpp"
switch (__2t -> base__4node ){ 
# 2190 "/home/claude/cfront-3/src/print2.cpp"
case 108 :
# 2191 "/home/claude/cfront-3/src/print2.cpp"
if (p2__FP4nameP4typeP8classdefP4virtPc ( __1nn , __2t , __0this , __1vtab , __1s ) )
# 2192 "/home/claude/cfront-3/src/print2.cpp"
goto xyzzy ;
# 2192 "/home/claude/cfront-3/src/print2.cpp"

# 2193 "/home/claude/cfront-3/src/print2.cpp"
break ;

# 2195 "/home/claude/cfront-3/src/print2.cpp"
case 76 :
# 2196 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2197 "/home/claude/cfront-3/src/print2.cpp"
{ { Plist __4gl ;

# 2197 "/home/claude/cfront-3/src/print2.cpp"
__4gl = (((struct gen *)(((struct gen *)__2t ))))-> fct_list__3gen ;

# 2197 "/home/claude/cfront-3/src/print2.cpp"
for(;__4gl ;__4gl = __4gl -> l__9name_list ) 
# 2198 "/home/claude/cfront-3/src/print2.cpp"
if (p2__FP4nameP4typeP8classdefP4virtPc ( __4gl -> f__9name_list , __4gl -> f__9name_list -> __O1__4expr.tp , __0this , __1vtab , __1s ) )
# 2199 "/home/claude/cfront-3/src/print2.cpp"
goto
# 2199 "/home/claude/cfront-3/src/print2.cpp"
xyzzy ;

# 2199 "/home/claude/cfront-3/src/print2.cpp"
}

# 2199 "/home/claude/cfront-3/src/print2.cpp"
}
}
}

# 2201 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 2204 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2205 "/home/claude/cfront-3/src/print2.cpp"
char *__2ss ;

# 2205 "/home/claude/cfront-3/src/print2.cpp"
__2ss = vtbl_name__FPCcT1 ( __1vtab -> string__4virt , __1str ?(((const char *)__1str )):__1cs ) ;

# 2207 "/home/claude/cfront-3/src/print2.cpp"
if (vtbl_opt )
# 2208 "/home/claude/cfront-3/src/print2.cpp"
really_really_print__FP8classdefP4virtPCcPc ( __0this , __1vtab , (const char *)__2ss , __1s ) ;
else { 
# 2210 "/home/claude/cfront-3/src/print2.cpp"
char *__3vstr ;

# 2210 "/home/claude/cfront-3/src/print2.cpp"
__3vstr = 0 ;
if (__1vtab && __1vtab -> string__4virt ){ 
# 2212 "/home/claude/cfront-3/src/print2.cpp"
__3vstr = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* ((strlen ( __1vtab ->
# 2212 "/home/claude/cfront-3/src/print2.cpp"
string__4virt ) + __0this -> c_strlen__8classdef )+ 1 ))) ));
strcpy ( __3vstr , __1vtab -> string__4virt ) ;
strcat ( __3vstr , __0this -> string__8classdef ) ;
}
{ Pname __3nn ;
if (__3nn = look__5tableFPCcUc ( ptbl , __3vstr ?(((const char *)__3vstr )):__0this -> string__8classdef , (unsigned char )0 ) ){ 
# 2218 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file ,
# 2218 "/home/claude/cfront-3/src/print2.cpp"
(const char *)"extern struct __mptr %s[];\n", __2ss ) ;
(__1s [2 ])= 'p' ;
ptbl_add_pair__FPCcT1 ( (const char *)__1s , (const char *)__2ss ) ;
__3nn -> n_key__4name = 159 ;
}
__dl__FPv ( (void *)__3vstr ) ;

# 2223 "/home/claude/cfront-3/src/print2.cpp"
}
}
__dl__FPv ( (void *)__2ss ) ;
}
xyzzy :
# 2228 "/home/claude/cfront-3/src/print2.cpp"
__dl__FPv ( (void *)__1s ) ;

# 2228 "/home/claude/cfront-3/src/print2.cpp"
}

# 2228 "/home/claude/cfront-3/src/print2.cpp"
}

# 2228 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 381 "/home/claude/cfront-3/src/cfront.h"
struct velem {	/* sizeof velem == 16 */
Pname n__5velem ;
int offset__5velem ;
};

# 19 "/home/claude/incl-linux32/string.h"
extern char *strdup (const char *);

# 2231 "/home/claude/cfront-3/src/print2.cpp"
void really_really_print__FP8classdefP4virtPCcPc (Pclass __1cl , Pvirt __1vtab , const char *__1s , char *__1ss )
# 2232 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2235 "/home/claude/cfront-3/src/print2.cpp"
Pname __1nn ;
int __1i ;

# 2271 "/home/claude/cfront-3/src/print2.cpp"
Pname __1n ;

# 2237 "/home/claude/cfront-3/src/print2.cpp"
for(__1i = 0 ;__1nn = (__1vtab -> virt_init__4virt [__1i ]). n__5velem ;__1i ++ ) { 
# 2238 "/home/claude/cfront-3/src/print2.cpp"
if (__1nn -> __O1__4expr.tp -> base__4node == 76 ){ 
# 2239 "/home/claude/cfront-3/src/print2.cpp"
__1nn = (((struct
# 2239 "/home/claude/cfront-3/src/print2.cpp"
gen *)(((struct gen *)__1nn -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list ;
}
{ Pfct __2f ;

# 2241 "/home/claude/cfront-3/src/print2.cpp"
__2f = (((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))));
if (__1nn -> __O3__4expr.n_initializer ){ 
# 2243 "/home/claude/cfront-3/src/print2.cpp"
static int __3pv ;
if (__3pv == 0 ){ 
# 2245 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"char __pure_virtual_called();\n") ;
__3pv = 1 ;
}
continue ;
}
if (__2f -> base__4node != 108 )
# 2251 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2251 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V79 ;

# 2251 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"vtbl %n", (const struct ea *)( ((&
# 2251 "/home/claude/cfront-3/src/print2.cpp"
__0__V79 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V79 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2251 "/home/claude/cfront-3/src/print2.cpp"
(const struct ea *)ea0 ) ;
} 
# 2253 "/home/claude/cfront-3/src/print2.cpp"
if (__1nn -> n_dcl_printed__4name == 0 ){ 
# 2254 "/home/claude/cfront-3/src/print2.cpp"
if ((__2f -> f_inline__3fct && vtbl_opt )|| (ansi_opt && (__1nn -> n_sto__4name == 31 )))
# 2255 "/home/claude/cfront-3/src/print2.cpp"
puttok__FUc ( (unsigned
# 2255 "/home/claude/cfront-3/src/print2.cpp"
char )31 ) ;
if (__2f -> f_result__3fct == 0 )
# 2257 "/home/claude/cfront-3/src/print2.cpp"
make_res__FP3fct ( __2f ) ;
{ Ptype __3r ;

# 2258 "/home/claude/cfront-3/src/print2.cpp"
__3r = (__2f -> s_returns__3fct ?__2f -> s_returns__3fct :__2f -> returns__3fct );
print__4typeFv ( __3r ) ;
print__4nameFUc ( __1nn , (unsigned char )0 ) ;
if (ansi_opt )
# 2262 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__3fctFv ( __2f ) ;
else fputs ( (const char *)"()", out_file ) ;
puttok__FUc ( (unsigned char )72 ) ;
__1nn -> n_dcl_printed__4name = 1 ;

# 2265 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 2266 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 2269 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"struct __mptr %s[] = {0,0,0,\n", __1s ) ;

# 2271 "/home/claude/cfront-3/src/print2.cpp"
;
for(__1i = 0 ;__1n = (__1vtab -> virt_init__4virt [__1i ]). n__5velem ;__1i ++ ) { 
# 2273 "/home/claude/cfront-3/src/print2.cpp"
if (__1n -> __O1__4expr.tp -> base__4node == 76 ){ 
# 2274 "/home/claude/cfront-3/src/print2.cpp"
__1n = (((struct
# 2274 "/home/claude/cfront-3/src/print2.cpp"
gen *)(((struct gen *)__1n -> __O1__4expr.tp ))))-> fct_list__3gen -> f__9name_list ;
}
if (__1n -> __O3__4expr.n_initializer )
# 2277 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)"0,0,(__vptp)__pure_virtual_called,\n", out_file ) ;
else { 
# 2279 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"%d,0,(__vptp)", - (__1vtab -> virt_init__4virt [__1i ]).
# 2279 "/home/claude/cfront-3/src/print2.cpp"
offset__5velem ) ;
print__4nameFUc ( __1n , (unsigned char )0 ) ;
__1n -> n_addr_taken__4name = 1 ;
fputs ( (const char *)",\n", out_file ) ;
}
}
fputs ( (const char *)"0,0,0};\n", out_file ) ;

# 2287 "/home/claude/cfront-3/src/print2.cpp"
(__1ss [2 ])= 'p' ;
{ char *__1bs ;

# 2293 "/home/claude/cfront-3/src/print2.cpp"
Pname __1nm ;
char *__1cstr ;
const char *__1vstr ;
const char *__1cs ;

# 2288 "/home/claude/cfront-3/src/print2.cpp"
__1bs = strdup ( __1s ) ;
(__1bs [2 ])= 'v' ;
ptbl_add_pair__FPCcT1 ( (const char *)__1ss , (const char *)__1bs ) ;
__dl__FPv ( (void *)__1bs ) ;

# 2293 "/home/claude/cfront-3/src/print2.cpp"
;
__1cstr = 0 ;
__1vstr = 0 ;
__1cs = (__1cl -> nested_sig__4type ?(((const char *)__1cl -> nested_sig__4type )):__1cl -> string__8classdef );
if (__1cl -> lex_level__4type && (! __1cl -> nested_sig__4type ))
# 2298 "/home/claude/cfront-3/src/print2.cpp"
__1cstr = __1cl -> local_sig__4type ;
if (__1vtab && __1vtab -> string__4virt ){ 
# 2300 "/home/claude/cfront-3/src/print2.cpp"
char *__2str_tmp ;

# 2300 "/home/claude/cfront-3/src/print2.cpp"
__2str_tmp = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* ((strlen ( __1vtab -> string__4virt ) + (__1cstr ?strlen ( (const
# 2300 "/home/claude/cfront-3/src/print2.cpp"
char *)__1cstr ) :strlen ( __1cs ) ))+ 1 ))) ));
strcpy ( __2str_tmp , __1vtab -> string__4virt ) ;
strcat ( __2str_tmp , __1cstr ?(((const char *)__1cstr )):__1cs ) ;
__1vstr = (const char *)__2str_tmp ;
}

# 2306 "/home/claude/cfront-3/src/print2.cpp"
if (__1vstr == 0 )
# 2307 "/home/claude/cfront-3/src/print2.cpp"
__1vstr = (__1cstr ?(((const char *)__1cstr )):(__1cs ?__1cs :__1cl -> string__8classdef ));
if (__1nm = look__5tableFPCcUc ( ptbl , __1vstr , (unsigned char )0 ) ){ 
# 2309 "/home/claude/cfront-3/src/print2.cpp"
__1nm -> n_key__4name = 159 ;
if (((__1vstr != (const char *)__1cstr )&& (__1vstr != __1cs ))&& (__1vstr != __1cl -> string__8classdef ))__dl__FPv ( (void *)(((char *)__1vstr ))) ;
# 2310 "/home/claude/cfront-3/src/print2.cpp"

# 2311 "/home/claude/cfront-3/src/print2.cpp"
}
else 
# 2311 "/home/claude/cfront-3/src/print2.cpp"
if (look__5tableFPCcUc ( ptbl , __1vstr , (unsigned char )159 ) == 0 )
# 2312 "/home/claude/cfront-3/src/print2.cpp"
insert__5tableFP4nameUc ( ptbl , __ct__4nameFPCc ( (struct name *)0 ,
# 2312 "/home/claude/cfront-3/src/print2.cpp"
__1vstr ) , (unsigned char )159 ) ;
else 
# 2314 "/home/claude/cfront-3/src/print2.cpp"
if (((__1vstr != (const char *)__1cstr )&& (__1vstr != __1cl -> string__8classdef ))&& (__1vstr != __1cs ))__dl__FPv ( (void *)(((char *)__1vstr )))
# 2314 "/home/claude/cfront-3/src/print2.cpp"
;

# 2314 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 37 "/home/claude/incl-linux32/ctype.h"
extern int isalpha (int );

# 39 "/home/claude/incl-linux32/ctype.h"
extern int isdigit (int );

# 2318 "/home/claude/cfront-3/src/print2.cpp"
char *vtbl_name__FPCcT1 (const char *__1s1 , const char *__1s2 )
# 2319 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2320 "/home/claude/cfront-3/src/print2.cpp"
const char *__1s3 ;

# 2323 "/home/claude/cfront-3/src/print2.cpp"
int __1ll ;
int __1ll2 ;
int __1ll3 ;
int __1sz ;

# 2320 "/home/claude/cfront-3/src/print2.cpp"
__1s3 = (((vtbl_opt == -1)&& ((*src_file_name )))?src_file_name :(((const char *)0 )));

# 2323 "/home/claude/cfront-3/src/print2.cpp"
__1ll = (__1s1 ?strlen ( __1s1 ) :(((unsigned long )0 )));
__1ll2 = strlen ( __1s2 ) ;
__1ll3 = (__1s3 ?strlen ( __1s3 ) :(((unsigned long )0 )));
__1sz = (((((__1ll + __1ll2 )+ __1ll3 )+ 20 )/ 32 )+ 1 );

# 2328 "/home/claude/cfront-3/src/print2.cpp"
__1sz *= 32 ;
{ char *__1buf ;

# 2329 "/home/claude/cfront-3/src/print2.cpp"
__1buf = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __1sz )) ));
if (__1s3 ){ 
# 2331 "/home/claude/cfront-3/src/print2.cpp"
if (__1s1 )
# 2332 "/home/claude/cfront-3/src/print2.cpp"
sprintf ( __1buf , (const char *)"__vtbl__%d%s__%d%s__%s", __1ll , __1s1 ,
# 2332 "/home/claude/cfront-3/src/print2.cpp"
__1ll2 , __1s2 , __1s3 ) ;
else 
# 2334 "/home/claude/cfront-3/src/print2.cpp"
sprintf ( __1buf , (const char *)"__vtbl__%d%s__%s", __1ll2 , __1s2 , __1s3 ) ;
# 2334 "/home/claude/cfront-3/src/print2.cpp"

# 2335 "/home/claude/cfront-3/src/print2.cpp"
}
else if (__1s1 )
# 2337 "/home/claude/cfront-3/src/print2.cpp"
sprintf ( __1buf , (const char *)"__vtbl__%d%s__%d%s", __1ll , __1s1 , __1ll2 ,
# 2337 "/home/claude/cfront-3/src/print2.cpp"
__1s2 ) ;
else 
# 2339 "/home/claude/cfront-3/src/print2.cpp"
sprintf ( __1buf , (const char *)"__vtbl__%d%s", __1ll2 , __1s2 ) ;

# 2341 "/home/claude/cfront-3/src/print2.cpp"
if (vtbl_opt == -1){ 
# 2342 "/home/claude/cfront-3/src/print2.cpp"
{ { char *__2p ;

# 2342 "/home/claude/cfront-3/src/print2.cpp"
__2p = ((__1buf + __1ll2 )+ 11 );

# 2342 "/home/claude/cfront-3/src/print2.cpp"
for(;(*__2p );__2p ++ ) 
# 2343 "/home/claude/cfront-3/src/print2.cpp"
if ((! isalpha ( (int )((*__2p ))) )&& (! isdigit ( (int )((*__2p ))) ))((*__2p ))= '_' ;
# 2343 "/home/claude/cfront-3/src/print2.cpp"

# 2343 "/home/claude/cfront-3/src/print2.cpp"
}

# 2343 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 2348 "/home/claude/cfront-3/src/print2.cpp"
return __1buf ;

# 2348 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 520 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 2351 "/home/claude/cfront-3/src/print2.cpp"
void print_all_vtbls__8classdefFP8classdef (register struct classdef *__0this , Pclass __1bcl )
# 2352 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2353 "/home/claude/cfront-3/src/print2.cpp"
{ { Pvirt __1blist ;

# 2353 "/home/claude/cfront-3/src/print2.cpp"
__1blist = __1bcl -> virt_list__8classdef ;

# 2353 "/home/claude/cfront-3/src/print2.cpp"
for(;__1blist ;__1blist = __1blist -> next__4virt ) { 
# 2353 "/home/claude/cfront-3/src/print2.cpp"
struct classdef *__1__X80 ;

# 2353 "/home/claude/cfront-3/src/print2.cpp"
struct classdef *__1__X81 ;

# 2353 "/home/claude/cfront-3/src/print2.cpp"
register struct vl *__0__X82 ;

# 2353 "/home/claude/cfront-3/src/print2.cpp"
struct vl *__2__X83 ;

# 2354 "/home/claude/cfront-3/src/print2.cpp"
if (! ( (__1__X80 = __0this ), ( (__1__X81 = __1blist -> vclass__4virt ), ( ((__1__X80 == __1__X81 )?1 :((__1__X80 && __1__X81 )?(((int )same_class__8classdefFP8classdefi (
# 2354 "/home/claude/cfront-3/src/print2.cpp"
__1__X80 , __1__X81 , 0 ) )):0 ))) ) ) )
# 2355 "/home/claude/cfront-3/src/print2.cpp"
continue ;
if (__1blist -> printed__4virt )
# 2357 "/home/claude/cfront-3/src/print2.cpp"
continue ;
vlist = ( (__0__X82 = 0 ), ( (__2__X83 = vlist ), ( ((__0__X82 || (__0__X82 = (struct vl *)__nw__FUl ( (unsigned long
# 2358 "/home/claude/cfront-3/src/print2.cpp"
)(sizeof (struct vl))) ))?( (__0__X82 -> cl__2vl = __0this ), ( (__0__X82 -> vt__2vl = __1blist ), (__0__X82 -> next__2vl = __2__X83 )) )
# 2358 "/home/claude/cfront-3/src/print2.cpp"
:0 ), __0__X82 ) ) ) ;
__1blist -> printed__4virt = 1 ;
}

# 2362 "/home/claude/cfront-3/src/print2.cpp"
{ { Pbcl __1b ;

# 2363 "/home/claude/cfront-3/src/print2.cpp"
struct classdef *__1__X84 ;

# 2363 "/home/claude/cfront-3/src/print2.cpp"
struct classdef *__1__X85 ;

# 2362 "/home/claude/cfront-3/src/print2.cpp"
__1b = __1bcl -> baselist__8classdef ;

# 2362 "/home/claude/cfront-3/src/print2.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) 
# 2363 "/home/claude/cfront-3/src/print2.cpp"
print_all_vtbls__8classdefFP8classdef ( __0this , __1b -> bclass__6basecl ) ;

# 2365 "/home/claude/cfront-3/src/print2.cpp"
if (( (__1__X84 = __0this ), ( (__1__X85 = __1bcl ), ( ((__1__X84 == __1__X85 )?1 :((__1__X84 && __1__X85 )?(((int )same_class__8classdefFP8classdefi ( __1__X84 , __1__X85 ,
# 2365 "/home/claude/cfront-3/src/print2.cpp"
0 ) )):0 ))) ) ) )
# 2366 "/home/claude/cfront-3/src/print2.cpp"
__0this -> c_body__8classdef = 0 ;

# 2366 "/home/claude/cfront-3/src/print2.cpp"
}

# 2366 "/home/claude/cfront-3/src/print2.cpp"
}

# 2366 "/home/claude/cfront-3/src/print2.cpp"
}

# 2366 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 234 "/home/claude/cfront-3/src/cfront.h"

# 113 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_name__FPCcP6ktableUc (const char *, Pktab , TOK );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 2369 "/home/claude/cfront-3/src/print2.cpp"
void dcl_print__8classdefFP4name (register struct classdef *__0this , Pname __1n )
# 2370 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2382 "/home/claude/cfront-3/src/print2.cpp"
int __1i ;
Pname __1nn ;

# 2384 "/home/claude/cfront-3/src/print2.cpp"
struct table *__0__X86 ;

# 2384 "/home/claude/cfront-3/src/print2.cpp"
int __2__X87 ;

# 2384 "/home/claude/cfront-3/src/print2.cpp"
struct table *__0__X88 ;

# 2384 "/home/claude/cfront-3/src/print2.cpp"
int __2__X89 ;

# 2371 "/home/claude/cfront-3/src/print2.cpp"
__0this -> defined__4type |= 010 ;

# 2377 "/home/claude/cfront-3/src/print2.cpp"
;
if (((__0this -> c_body__8classdef == 0 )|| (__0this -> c_body__8classdef == 3 ))|| ((__0this -> defined__4type & 01 )== 0 ))
# 2379 "/home/claude/cfront-3/src/print2.cpp"
return ;
__0this -> c_body__8classdef = 3 ;

# 2382 "/home/claude/cfront-3/src/print2.cpp"
;
__1nn = ( (__0__X86 = __0this -> memtbl__8classdef ), ( (__2__X87 = (__1i = 1 )), ( (((__2__X87 <= 0 )|| (__0__X86 -> free_slot__5table <=
# 2383 "/home/claude/cfront-3/src/print2.cpp"
__2__X87 ))?(((struct name *)0 )):(__0__X86 -> entries__5table [__2__X87 ]))) ) ) ;
for(;__1nn ;__1nn = (__1nn -> n_tbl_list__4name ?__1nn -> n_tbl_list__4name :( (__0__X88 = __0this -> memtbl__8classdef ), ( (__2__X89 = (++ __1i )), ( (((__2__X89 <= 0 )||
# 2384 "/home/claude/cfront-3/src/print2.cpp"
(__0__X88 -> free_slot__5table <= __2__X89 ))?(((struct name *)0 )):(__0__X88 -> entries__5table [__2__X89 ]))) ) ) )) { 
# 2385 "/home/claude/cfront-3/src/print2.cpp"
if (__1nn -> base__4node == 123 )continue ;
# 2385 "/home/claude/cfront-3/src/print2.cpp"

# 2386 "/home/claude/cfront-3/src/print2.cpp"
if ((((__1nn -> base__4node == 85 )&& (__1nn -> n_anon__4name == 0 ))&& (__1nn -> __O1__4expr.tp -> base__4node == 6 ))&& ((((struct classdef *)(((struct classdef *)__1nn ->
# 2386 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp ))))-> c_body__8classdef == 1 ))
# 2390 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__8classdefFP4name ( ((struct classdef *)(((struct classdef *)__1nn -> __O1__4expr.tp ))), __1nn ) ;
else 
# 2392 "/home/claude/cfront-3/src/print2.cpp"
if ((__1nn -> base__4node == 123 )&& (__1nn -> __O1__4expr.tp -> base__4node != 119 ))
# 2393 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__4nameFUc ( __1nn , (unsigned char )0 ) ;
# 2393 "/home/claude/cfront-3/src/print2.cpp"
else 
# 2395 "/home/claude/cfront-3/src/print2.cpp"
if (((__1nn -> __O1__4expr.tp && (__1nn -> n_anon__4name == 0 ))&& (__1nn -> __O1__4expr.tp -> base__4node == 13 ))&& ((((struct enumdef *)(((struct enumdef *)__1nn ->
# 2395 "/home/claude/cfront-3/src/print2.cpp"
__O1__4expr.tp ))))-> e_body__7enumdef != 3 ))
# 2399 "/home/claude/cfront-3/src/print2.cpp"
dcl_print__7enumdefFP4name ( ((struct enumdef *)(((struct enumdef *)__1nn -> __O1__4expr.tp ))), __1nn ) ;
}

# 2403 "/home/claude/cfront-3/src/print2.cpp"
__1n = k_find_name__FPCcP6ktableUc ( __0this -> string__8classdef , Ctbl , (unsigned char )159 ) ;

# 2405 "/home/claude/cfront-3/src/print2.cpp"
if (__1n ){ 
# 2406 "/home/claude/cfront-3/src/print2.cpp"
if ((__1n -> where__4name . line__3loc != last_line . line__3loc )|| (__1n -> where__4name . file__3loc != last_line . file__3loc ))
# 2411 "/home/claude/cfront-3/src/print2.cpp"
if (last_ll =
# 2411 "/home/claude/cfront-3/src/print2.cpp"
__1n -> where__4name . line__3loc )
# 2412 "/home/claude/cfront-3/src/print2.cpp"
putline__3locFv ( & __1n -> where__4name ) ;
else 
# 2414 "/home/claude/cfront-3/src/print2.cpp"
putline__3locFv ( & last_line ) ;
}

# 2417 "/home/claude/cfront-3/src/print2.cpp"
{ TOK __1c ;

# 2417 "/home/claude/cfront-3/src/print2.cpp"
__1c = ((__0this -> csu__8classdef == 6 )?(((unsigned int )32 )):(((unsigned int )__0this -> csu__8classdef )));
puttok__FUc ( __1c ) ;

# 2420 "/home/claude/cfront-3/src/print2.cpp"
{ char *__1str ;

# 2420 "/home/claude/cfront-3/src/print2.cpp"
__1str = 0 ;

# 2422 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> lex_level__4type && (! __0this -> nested_sig__4type ))
# 2423 "/home/claude/cfront-3/src/print2.cpp"
__1str = __0this -> local_sig__4type ;
if (__0this -> nested_sig__4type )
# 2425 "/home/claude/cfront-3/src/print2.cpp"
fputs ( (const char *)" __", out_file ) ;
( fputs ( __1str ?(((const char *)__1str )):(__0this -> nested_sig__4type ?(((const char *)__0this -> nested_sig__4type )):__0this -> string__8classdef ), out_file ) , fputc ( (int
# 2426 "/home/claude/cfront-3/src/print2.cpp"
)' ' , out_file ) ) ;

# 2429 "/home/claude/cfront-3/src/print2.cpp"
{ int __1dvirt ;

# 2429 "/home/claude/cfront-3/src/print2.cpp"
__1dvirt = 0 ;

# 2431 "/home/claude/cfront-3/src/print2.cpp"
if (__0this -> nested_sig__4type )
# 2432 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"{\t/* sizeof __%s == %d */\n", __0this -> nested_sig__4type , __0this ->
# 2432 "/home/claude/cfront-3/src/print2.cpp"
obj_size__8classdef ) ;
else 
# 2434 "/home/claude/cfront-3/src/print2.cpp"
fprintf ( out_file , (const char *)"{\t/* sizeof %s == %d */\n", __1str ?(((const char *)__1str )):__0this -> string__8classdef ,
# 2434 "/home/claude/cfront-3/src/print2.cpp"
__0this -> obj_size__8classdef ) ;
if (last_ll )
# 2436 "/home/claude/cfront-3/src/print2.cpp"
last_line . line__3loc ++ ;

# 2438 "/home/claude/cfront-3/src/print2.cpp"
begin_mem__Fv ( ) ;
print_members__8classdefFv ( __0this ) ;
end_mem__Fv ( ) ;
{ { Pbcl __1b ;

# 2442 "/home/claude/cfront-3/src/print2.cpp"
struct table *__0__X90 ;

# 2442 "/home/claude/cfront-3/src/print2.cpp"
int __2__X91 ;

# 2442 "/home/claude/cfront-3/src/print2.cpp"
struct table *__0__X92 ;

# 2442 "/home/claude/cfront-3/src/print2.cpp"
int __2__X93 ;

# 2441 "/home/claude/cfront-3/src/print2.cpp"
__1b = __0this -> baselist__8classdef ;

# 2441 "/home/claude/cfront-3/src/print2.cpp"
for(;__1b ;__1b = __1b -> next__6basecl ) { 
# 2442 "/home/claude/cfront-3/src/print2.cpp"
if (__1b -> base__4node != 77 )
# 2443 "/home/claude/cfront-3/src/print2.cpp"
continue ;
{ Pclass __2bcl ;

# 2444 "/home/claude/cfront-3/src/print2.cpp"
__2bcl = __1b -> bclass__6basecl ;
__1dvirt += __2bcl -> virt_count__8classdef ;
if (__1b -> allocated__6basecl == 0 )
# 2447 "/home/claude/cfront-3/src/print2.cpp"
continue ;
{ char *__2str ;
const char *__2cs ;

# 2448 "/home/claude/cfront-3/src/print2.cpp"
__2str = 0 ;
__2cs = (__2bcl -> nested_sig__4type ?(((const char *)__2bcl -> nested_sig__4type )):__2bcl -> string__8classdef );
if (__2bcl -> lex_level__4type && (! __2bcl -> nested_sig__4type ))
# 2451 "/home/claude/cfront-3/src/print2.cpp"
__2str = __2bcl -> local_sig__4type ;
puttok__FUc ( (unsigned char )32 ) ;
if (__2bcl -> nested_sig__4type )fputs ( (const char *)"__", out_file ) ;
( fputs ( __2str ?(((const char *)__2str )):__2cs , out_file ) , fputc ( (int )' ' , out_file ) ) ;
( fputc ( (int )'O' , out_file ) , fputs ( __2bcl -> string__8classdef , out_file ) ) ;
puttok__FUc ( (unsigned char )72 ) ;

# 2456 "/home/claude/cfront-3/src/print2.cpp"
}

# 2456 "/home/claude/cfront-3/src/print2.cpp"
}
}
fputs ( (const char *)"};\n", out_file ) ;
if (last_ll )
# 2460 "/home/claude/cfront-3/src/print2.cpp"
last_line . line__3loc ++ ;

# 2462 "/home/claude/cfront-3/src/print2.cpp"
for(__1nn = ( (__0__X90 = __0this -> memtbl__8classdef ), ( (__2__X91 = (__1i = 1 )), ( (((__2__X91 <= 0 )|| (__0__X90 -> free_slot__5table <=
# 2462 "/home/claude/cfront-3/src/print2.cpp"
__2__X91 ))?(((struct name *)0 )):(__0__X90 -> entries__5table [__2__X91 ]))) ) ) ;__1nn ;__1nn = (__1nn -> n_tbl_list__4name ?__1nn -> n_tbl_list__4name :( (__0__X92 = __0this -> memtbl__8classdef ), ( (__2__X93 =
# 2462 "/home/claude/cfront-3/src/print2.cpp"
(++ __1i )), ( (((__2__X93 <= 0 )|| (__0__X92 -> free_slot__5table <= __2__X93 ))?(((struct name *)0 )):(__0__X92 -> entries__5table [__2__X93 ]))) ) ) )) {
# 2462 "/home/claude/cfront-3/src/print2.cpp"

# 2463 "/home/claude/cfront-3/src/print2.cpp"
if (__1nn -> base__4node == 123 )continue ;
if ((__1nn -> base__4node == 85 )&& (__1nn -> n_anon__4name == 0 )){ 
# 2465 "/home/claude/cfront-3/src/print2.cpp"
Ptype __3t ;

# 2465 "/home/claude/cfront-3/src/print2.cpp"
__3t = __1nn -> __O1__4expr.tp ;
switch (__3t -> base__4node ){ 
# 2467 "/home/claude/cfront-3/src/print2.cpp"
case 108 :
# 2468 "/home/claude/cfront-3/src/print2.cpp"
case 76 :
# 2469 "/home/claude/cfront-3/src/print2.cpp"
break ;
default :
# 2471 "/home/claude/cfront-3/src/print2.cpp"
if (__1nn -> n_stclass__4name == 31 ){ 
# 2472 "/home/claude/cfront-3/src/print2.cpp"
TOK __5b ;

# 2472 "/home/claude/cfront-3/src/print2.cpp"
__5b = __1nn -> n_sto__4name ;
__1nn -> n_sto__4name = (__1nn -> n_evaluated__4name ?(((unsigned int )31 )):(((unsigned int )__5b )));
dcl_print__4nameFUc ( __1nn , (unsigned char )0 ) ;
__1nn -> n_sto__4name = __5b ;
}
}
}
}
if (vtbl_opt != -1)
# 2481 "/home/claude/cfront-3/src/print2.cpp"
print_all_vtbls__8classdefFP8classdef ( __0this , __0this ) ;

# 2481 "/home/claude/cfront-3/src/print2.cpp"
}

# 2481 "/home/claude/cfront-3/src/print2.cpp"
}

# 2481 "/home/claude/cfront-3/src/print2.cpp"
}

# 2481 "/home/claude/cfront-3/src/print2.cpp"
}

# 2481 "/home/claude/cfront-3/src/print2.cpp"
}
}

# 2486 "/home/claude/cfront-3/src/print2.cpp"
char *make_local_name__FP4typeP4name (Ptype __1tt , Pname __1fn )
# 2487 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2488 "/home/claude/cfront-3/src/print2.cpp"
char *__1buf ;
int __1tlen ;
const char *__1tstring ;
switch (__1tt -> base__4node ){ 
# 2492 "/home/claude/cfront-3/src/print2.cpp"
case 6 :
# 2493 "/home/claude/cfront-3/src/print2.cpp"
__1tlen = (((struct classdef *)(((struct classdef *)__1tt ))))-> c_strlen__8classdef ;
__1tstring = (((struct classdef *)(((struct classdef *)__1tt ))))-> string__8classdef ;
break ;
case 13 :
# 2497 "/home/claude/cfront-3/src/print2.cpp"
__1tlen = (((struct enumdef *)(((struct enumdef *)__1tt ))))-> e_strlen__7enumdef ;
__1tstring = (((struct enumdef *)(((struct enumdef *)__1tt ))))-> string__7enumdef ;
break ;
default :
# 2501 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2501 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V94 ;

# 2501 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V95 ;

# 2501 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"make_local_name(%t,%n )", (const struct ea *)( ((&
# 2501 "/home/claude/cfront-3/src/print2.cpp"
__0__V94 )-> __O1__2ea.p = ((const void *)__1tt )), (& __0__V94 )) , (const struct ea *)( ((& __0__V95 )-> __O1__2ea.p =
# 2501 "/home/claude/cfront-3/src/print2.cpp"
((const void *)__1fn )), (& __0__V95 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
{ char *__1lcl ;

# 2503 "/home/claude/cfront-3/src/print2.cpp"
__1lcl = make_name__FUc ( (unsigned char )'L' ) ;
if (((__1fn == 0 )|| (__1fn -> __O1__4expr.tp == 0 ))|| (__1fn -> __O1__4expr.tp -> base__4node != 108 ))
# 2505 "/home/claude/cfront-3/src/print2.cpp"
{ 
# 2505 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V96 ;

# 2505 "/home/claude/cfront-3/src/print2.cpp"
struct ea __0__V97 ;

# 2505 "/home/claude/cfront-3/src/print2.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"localC %smissing or badFN%n", (const struct ea *)( ((&
# 2505 "/home/claude/cfront-3/src/print2.cpp"
__0__V96 )-> __O1__2ea.p = ((const void *)__1tstring )), (& __0__V96 )) , (const struct ea *)( ((& __0__V97 )-> __O1__2ea.p =
# 2505 "/home/claude/cfront-3/src/print2.cpp"
((const void *)__1fn )), (& __0__V97 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __1tt -> in_fct__4type = __1fn ;
{ const char *__1fsig ;

# 2507 "/home/claude/cfront-3/src/print2.cpp"
__1fsig = (((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))))-> f_signature__3fct ;
if (__1fsig == 0 )
# 2509 "/home/claude/cfront-3/src/print2.cpp"
__1fsig = (const char *)local_sign__FP4type ( __1fn -> __O1__4expr.tp ) ;
{ const char *__1fs ;
int __1name_len ;
int __1sz ;

# 2510 "/home/claude/cfront-3/src/print2.cpp"
__1fs = __1fn -> __O2__4expr.string ;
__1name_len = ((((__1tlen + strlen ( __1fsig ) )+ strlen ( __1fs ) )+ strlen ( (const char *)__1lcl ) )+ 4 );
# 2511 "/home/claude/cfront-3/src/print2.cpp"

# 2512 "/home/claude/cfront-3/src/print2.cpp"
__1sz = (((__1name_len + 20 )/ 32 )+ 1 );

# 2514 "/home/claude/cfront-3/src/print2.cpp"
if ((((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))))-> memof__3fct == 0 ){ 
# 2515 "/home/claude/cfront-3/src/print2.cpp"
__1sz *= 32 ;
__1buf = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __1sz )) ));

# 2518 "/home/claude/cfront-3/src/print2.cpp"
sprintf ( __1buf , (const char *)"%s__%s__%s%s", __1tstring , __1fs , __1fsig , __1lcl ) ;
# 2518 "/home/claude/cfront-3/src/print2.cpp"

# 2519 "/home/claude/cfront-3/src/print2.cpp"
}
else { 
# 2521 "/home/claude/cfront-3/src/print2.cpp"
const char *__2cs ;
int __2len ;

# 2521 "/home/claude/cfront-3/src/print2.cpp"
__2cs = (((struct classdef *)(((struct classdef *)(((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))))-> memof__3fct ))))-> string__8classdef ;
__2len = (((struct classdef *)(((struct classdef *)(((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))))-> memof__3fct ))))-> c_strlen__8classdef ;
if (__2len < 10 )
# 2524 "/home/claude/cfront-3/src/print2.cpp"
++ __1name_len ;
else if (__2len > 99 )
# 2526 "/home/claude/cfront-3/src/print2.cpp"
__1name_len += 3 ;
else 
# 2528 "/home/claude/cfront-3/src/print2.cpp"
__1name_len += 2 ;
__1name_len += __2len ;
__1sz = (((__1name_len + 20 )/ 32 )+ 1 );
__1sz *= 32 ;
__1buf = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __1sz )) ));

# 2534 "/home/claude/cfront-3/src/print2.cpp"
sprintf ( __1buf , (const char *)"%s__%s__%d%s%s%s", __1tstring , __1fs , __2len , __2cs , __1fsig ,
# 2534 "/home/claude/cfront-3/src/print2.cpp"
__1lcl ) ;
}

# 2541 "/home/claude/cfront-3/src/print2.cpp"
if (__1tt -> base__4node == 6 )
# 2542 "/home/claude/cfront-3/src/print2.cpp"
(((struct classdef *)(((struct classdef *)__1tt ))))-> c_strlen__8classdef = __1name_len ;
else 
# 2544 "/home/claude/cfront-3/src/print2.cpp"
(((struct enumdef *)(((struct enumdef *)__1tt ))))-> e_strlen__7enumdef = __1name_len ;
return __1buf ;

# 2545 "/home/claude/cfront-3/src/print2.cpp"
}

# 2545 "/home/claude/cfront-3/src/print2.cpp"
}

# 2545 "/home/claude/cfront-3/src/print2.cpp"
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

# 2546 "/home/claude/cfront-3/src/print2.cpp"

/* the end */
