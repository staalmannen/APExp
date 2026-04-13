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

# 187 "/home/claude/cfront-3/src/cfront.h"

# 31 "/home/claude/incl-linux32/string.h"
extern void *memset (void *, int , size_t );

# 28 "/home/claude/cfront-3/src/table.cpp"
struct table *__ct__5tableFsP5tableP4name (register struct table *__0this , short __1sz , Ptable __1nx , Pname __1n )
# 39 "/home/claude/cfront-3/src/table.cpp"
{ 
# 39 "/home/claude/cfront-3/src/table.cpp"
struct node *__0__X17 ;

# 39 "/home/claude/cfront-3/src/table.cpp"
if (__0this || (__0this = (struct table *)__nw__5tableSFUl ( (unsigned long )(sizeof (struct table))) )){ __0this = (struct table *)( (__0__X17 =
# 39 "/home/claude/cfront-3/src/table.cpp"
(((struct node *)__0this ))), ( ((__0__X17 || (__0__X17 = (struct node *)__nw__FUl ( (unsigned long )(sizeof (struct node))) ))?( ( (__0__X17 ->
# 39 "/home/claude/cfront-3/src/table.cpp"
base__4node = 0 ), (__0__X17 -> permanent__4node = 0 )) , (__0__X17 -> baseclass__4node = 0 )) :0 ), __0__X17 ) ) ;
;
__0this -> base__4node = 142 ;
__0this -> t_name__5table = __1n ;
__0this -> size__5table = (__1sz = ((__1sz <= 0 )?2 :(__1sz + 1 )));

# 45 "/home/claude/cfront-3/src/table.cpp"
__0this -> entries__5table = (((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* __1sz )) ));
__0this -> hashsize__5table = (__1sz = ((__1sz * 3 )/ 2 ));
__0this -> hashtbl__5table = (((short *)__nw__FUl ( (unsigned long )((sizeof (short ))* __1sz )) ));
memset ( (void *)__0this -> hashtbl__5table , 0 , (sizeof (short ))* __1sz ) ;
__0this -> next__5table = __1nx ;
__0this -> free_slot__5table = 1 ;
;
} 
# 51 "/home/claude/cfront-3/src/table.cpp"
return __0this ;
}

# 1 ""
extern void __dl__FPv (void *);

# 54 "/home/claude/cfront-3/src/table.cpp"
void __dt__5tableFv (struct table *__0this , 
# 54 "/home/claude/cfront-3/src/table.cpp"
int __0__free )
# 55 "/home/claude/cfront-3/src/table.cpp"
{ if (__0this ){ 
# 56 "/home/claude/cfront-3/src/table.cpp"
__dl__FPv ( (void *)__0this -> entries__5table ) ;
__dl__FPv ( (void *)__0this -> hashtbl__5table ) ;
if (__0this )if (__0__free & 1)__dl__5tableSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct table))) ;
} 
# 58 "/home/claude/cfront-3/src/table.cpp"
}

# 60 "/home/claude/cfront-3/src/table.cpp"
Pname look__5tableFPCcUc (register struct table *__0this , const char *__1s , TOK __1k )
# 65 "/home/claude/cfront-3/src/table.cpp"
{ 
# 66 "/home/claude/cfront-3/src/table.cpp"
Ptable __1t ;
const char *__1p ;
const char *__1q ;
int __1i ;
Pname __1n ;
int __1rr ;

# 75 "/home/claude/cfront-3/src/table.cpp"
;

# 83 "/home/claude/cfront-3/src/table.cpp"
__1p = __1s ;
__1i = 0 ;
while ((*__1p ))__1i += (__1i + ((*(__1p ++ ))));
__1rr = ((0 <= __1i )?__1i :(- __1i ));

# 88 "/home/claude/cfront-3/src/table.cpp"
for(__1t = __0this ;__1t ;__1t = __1t -> next__5table ) { 
# 90 "/home/claude/cfront-3/src/table.cpp"
Pname *__2np ;
int __2mx ;
short *__2hash ;
int __2firsti ;

# 90 "/home/claude/cfront-3/src/table.cpp"
__2np = __1t -> entries__5table ;
__2mx = __1t -> hashsize__5table ;
__2hash = __1t -> hashtbl__5table ;
__2firsti = (__1i = (__1rr % __2mx ));

# 95 "/home/claude/cfront-3/src/table.cpp"
do { 
# 96 "/home/claude/cfront-3/src/table.cpp"
if ((__2hash [__1i ])== 0 )goto not_found ;
__1n = (__2np [(__2hash [__1i ])]);
if (__1n == 0 )error__FiPCc ( (int )'i' , (const char *)"hashed lookup") ;
__1p = __1n -> __O2__4expr.string ;
__1q = __1s ;
while (((*__1p ))&& ((*__1q )))
# 102 "/home/claude/cfront-3/src/table.cpp"
if (((*(__1p ++ )))!= ((*(__1q ++ ))))goto nxt ;
if (((*__1p ))== ((*__1q )))goto found ;
nxt :
# 105 "/home/claude/cfront-3/src/table.cpp"
if (__2mx <= (++ __1i ))__1i = 0 ;
}
while (__1i != __2firsti );
found :
# 109 "/home/claude/cfront-3/src/table.cpp"
for(;__1n ;__1n = __1n -> n_tbl_list__4name ) { 
# 112 "/home/claude/cfront-3/src/table.cpp"
;
if (__1n -> n_key__4name == __1k )return __1n ;
}

# 116 "/home/claude/cfront-3/src/table.cpp"
not_found :;
}

# 121 "/home/claude/cfront-3/src/table.cpp"
;
return (struct name *)0 ;
}

# 125 "/home/claude/cfront-3/src/table.cpp"
bit Nold = 0 ;

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 228 "/home/claude/cfront-3/src/cfront.h"
void grow__5tableFi (struct table *__0this , int );

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 127 "/home/claude/cfront-3/src/table.cpp"
Pname insert__5tableFP4nameUc (register struct table *__0this , Pname __1nx , TOK __1k )
# 133 "/home/claude/cfront-3/src/table.cpp"
{ 
# 134 "/home/claude/cfront-3/src/table.cpp"
const char *__1p ;
int __1i ;
Pname __1n ;
Pname *__1np ;
Pname *__1link ;
int __1firsti ;
int __1mx ;
short *__1hash ;
const char *__1s ;

# 137 "/home/claude/cfront-3/src/table.cpp"
__1np = __0this -> entries__5table ;

# 140 "/home/claude/cfront-3/src/table.cpp"
__1mx = __0this -> hashsize__5table ;
__1hash = __0this -> hashtbl__5table ;
__1s = __1nx -> __O2__4expr.string ;

# 148 "/home/claude/cfront-3/src/table.cpp"
;

# 150 "/home/claude/cfront-3/src/table.cpp"
if (__1s == 0 ){ 
# 150 "/home/claude/cfront-3/src/table.cpp"
struct ea __0__V18 ;

# 150 "/home/claude/cfront-3/src/table.cpp"
struct ea __0__V19 ;

# 150 "/home/claude/cfront-3/src/table.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%p->insert(0,%k)", (const struct ea *)( ((&
# 150 "/home/claude/cfront-3/src/table.cpp"
__0__V18 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V18 )) , (const struct ea *)( (( ((& __0__V19 )->
# 150 "/home/claude/cfront-3/src/table.cpp"
__O1__2ea.i = ((unsigned long )__1k )), 0 ) ), (& __0__V19 )) , (const struct ea *)ea0 , (const struct
# 150 "/home/claude/cfront-3/src/table.cpp"
ea *)ea0 ) ;
} __1nx -> n_key__4name = __1k ;
if (__1nx -> n_tbl_list__4name || __1nx -> __O4__4expr.n_table ){ 
# 152 "/home/claude/cfront-3/src/table.cpp"
struct ea __0__V20 ;

# 152 "/home/claude/cfront-3/src/table.cpp"
struct ea __0__V21 ;

# 152 "/home/claude/cfront-3/src/table.cpp"
struct ea __0__V22 ;

# 152 "/home/claude/cfront-3/src/table.cpp"
struct ea __0__V23 ;

# 152 "/home/claude/cfront-3/src/table.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%n in two tables (n_tbl_list %d, n_table %d%n)", (const struct ea *)( ((&
# 152 "/home/claude/cfront-3/src/table.cpp"
__0__V20 )-> __O1__2ea.p = ((const void *)__1nx )), (& __0__V20 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V21 , (const
# 152 "/home/claude/cfront-3/src/table.cpp"
void *)__1nx -> n_tbl_list__4name ) , (const struct ea *)__ct__2eaFPCv ( & __0__V22 , (const void *)__1nx -> __O4__4expr.n_table ) ,
# 152 "/home/claude/cfront-3/src/table.cpp"
(const struct ea *)__ct__2eaFPCv ( & __0__V23 , (const void *)(__1nx -> __O4__4expr.n_table ?__1nx -> __O4__4expr.n_table -> t_name__5table :(((struct name *)0 )))) ) ;
# 152 "/home/claude/cfront-3/src/table.cpp"
} 
# 155 "/home/claude/cfront-3/src/table.cpp"
__1p = __1s ;
__1i = 0 ;
while ((*__1p ))__1i += (__1i + ((*(__1p ++ ))));
if (__1i < 0 )__1i = (- __1i );
__1firsti = (__1i = (__1i % __1mx ));

# 161 "/home/claude/cfront-3/src/table.cpp"
do { 
# 162 "/home/claude/cfront-3/src/table.cpp"
if ((__1hash [__1i ])== 0 ){ 
# 163 "/home/claude/cfront-3/src/table.cpp"
(__1hash [__1i ])= __0this -> free_slot__5table ;
goto add_np ;
}
__1n = (__1np [(__1hash [__1i ])]);
if (__1n == 0 )error__FiPCc ( (int )'i' , (const char *)"hashed lookup") ;
if (strcmp ( __1n -> __O2__4expr.string , __1s ) == 0 )goto found ;

# 176 "/home/claude/cfront-3/src/table.cpp"
if (__1mx <= (++ __1i ))__1i = 0 ;
}
while (__1i != __1firsti );
error__FPCc ( (const char *)"N table full") ;

# 181 "/home/claude/cfront-3/src/table.cpp"
found :
# 184 "/home/claude/cfront-3/src/table.cpp"
for(;;) { 
# 186 "/home/claude/cfront-3/src/table.cpp"
if (__1n -> n_key__4name == __1k ){ Nold = 1 ;

# 186 "/home/claude/cfront-3/src/table.cpp"
return __1n ;

# 186 "/home/claude/cfront-3/src/table.cpp"
}

# 188 "/home/claude/cfront-3/src/table.cpp"
if (__1n -> n_tbl_list__4name )
# 189 "/home/claude/cfront-3/src/table.cpp"
__1n = __1n -> n_tbl_list__4name ;
else { 
# 191 "/home/claude/cfront-3/src/table.cpp"
__1link = (& __1n -> n_tbl_list__4name );
goto re_allocate ;
}
}

# 196 "/home/claude/cfront-3/src/table.cpp"
add_np :
# 197 "/home/claude/cfront-3/src/table.cpp"
if (__0this -> size__5table <= __0this -> free_slot__5table ){ 
# 198 "/home/claude/cfront-3/src/table.cpp"
grow__5tableFi ( __0this , 2 * __0this -> size__5table ) ;
return insert__5tableFP4nameUc ( __0this , __1nx , __1k ) ;
}

# 202 "/home/claude/cfront-3/src/table.cpp"
__1link = (& (__1np [(__0this -> free_slot__5table ++ )]));

# 204 "/home/claude/cfront-3/src/table.cpp"
re_allocate :
# 205 "/home/claude/cfront-3/src/table.cpp"
{ 
# 206 "/home/claude/cfront-3/src/table.cpp"
Pname __2nw ;

# 206 "/home/claude/cfront-3/src/table.cpp"
__2nw = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
((*__2nw ))= (*__1nx );
{ char *__2ps ;

# 208 "/home/claude/cfront-3/src/table.cpp"
__2ps = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( __1s ) + 1 ))) ));
strcpy ( __2ps , __1s ) ;

# 211 "/home/claude/cfront-3/src/table.cpp"
__2nw -> __O2__4expr.string = (const char *)__2ps ;
__2nw -> __O4__4expr.n_table = __0this ;
((*__1link ))= __2nw ;
Nold = 0 ;

# 216 "/home/claude/cfront-3/src/table.cpp"
return __2nw ;

# 216 "/home/claude/cfront-3/src/table.cpp"
}
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFUl (struct ea *__0this , size_t __2ii );

# 220 "/home/claude/cfront-3/src/table.cpp"
void grow__5tableFi (register struct table *__0this , int __1g )
# 221 "/home/claude/cfront-3/src/table.cpp"
{ 
# 222 "/home/claude/cfront-3/src/table.cpp"
short *__1hash ;
int __1j ;
int __1mx ;
Pname *__1np ;
Pname __1n ;

# 228 "/home/claude/cfront-3/src/table.cpp"
if (__1g <= __0this -> free_slot__5table ){ 
# 228 "/home/claude/cfront-3/src/table.cpp"
struct ea __0__V24 ;

# 228 "/home/claude/cfront-3/src/table.cpp"
struct ea __0__V25 ;

# 228 "/home/claude/cfront-3/src/table.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"table.grow(%d,%d)", (const struct ea *)( ((
# 228 "/home/claude/cfront-3/src/table.cpp"
((& __0__V24 )-> __O1__2ea.i = ((unsigned long )__1g )), 0 ) ), (& __0__V24 )) , (const struct ea *)__ct__2eaFUl (
# 228 "/home/claude/cfront-3/src/table.cpp"
& __0__V25 , (unsigned long )__0this -> free_slot__5table ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 228 "/home/claude/cfront-3/src/table.cpp"
} 
# 229 "/home/claude/cfront-3/src/table.cpp"
if (__1g <= __0this -> size__5table )return ;

# 231 "/home/claude/cfront-3/src/table.cpp"
__0this -> size__5table = (__1mx = (__1g + 1 ));

# 233 "/home/claude/cfront-3/src/table.cpp"
__1np = (((struct name **)__nw__FUl ( (unsigned long )((sizeof (struct name *))* __1mx )) ));
for(__1j = 0 ;__1j < __0this -> free_slot__5table ;__1j ++ ) (__1np [__1j ])= (__0this -> entries__5table [__1j ]);
__dl__FPv ( (void *)__0this -> entries__5table ) ;
__0this -> entries__5table = __1np ;

# 238 "/home/claude/cfront-3/src/table.cpp"
__dl__FPv ( (void *)__0this -> hashtbl__5table ) ;
__0this -> hashsize__5table = (__1mx = ((__1g * 3 )/ 2 ));
__1hash = (__0this -> hashtbl__5table = (((short *)__nw__FUl ( (unsigned long )((sizeof (short ))* __1mx )) )));
memset ( (void *)__1hash , 0 , __1mx * (sizeof (short ))) ;

# 243 "/home/claude/cfront-3/src/table.cpp"
for(__1j = 1 ;__1j < __0this -> free_slot__5table ;__1j ++ ) { 
# 244 "/home/claude/cfront-3/src/table.cpp"
const char *__2s ;
const char *__2p ;
const char *__2q ;
int __2i ;
int __2firsti ;

# 244 "/home/claude/cfront-3/src/table.cpp"
__2s = (__1np [__1j ])-> __O2__4expr.string ;

# 250 "/home/claude/cfront-3/src/table.cpp"
__2p = __2s ;
__2i = 0 ;
while ((*__2p ))__2i += (__2i + ((*(__2p ++ ))));
if (__2i < 0 )__2i = (- __2i );
__2firsti = (__2i = (__2i % __1mx ));

# 256 "/home/claude/cfront-3/src/table.cpp"
do { 
# 257 "/home/claude/cfront-3/src/table.cpp"
if ((__1hash [__2i ])== 0 ){ 
# 258 "/home/claude/cfront-3/src/table.cpp"
(__1hash [__2i ])= __1j ;
goto add_np ;
}
__1n = (__1np [(__1hash [__2i ])]);
if (__1n == 0 )error__FiPCc ( (int )'i' , (const char *)"hashed lookup") ;
__2p = __1n -> __O2__4expr.string ;
__2q = __2s ;
while (((*__2p ))&& ((*__2q )))if (((*(__2p ++ )))!= ((*(__2q ++ ))))goto nxt ;
if (((*__2p ))== ((*__2q )))goto found ;
nxt :
# 268 "/home/claude/cfront-3/src/table.cpp"
if (__1mx <= (++ __2i ))__2i = 0 ;
}
while (__2i != __2firsti );
error__FiPCc ( (int )'i' , (const char *)"rehash??") ;

# 273 "/home/claude/cfront-3/src/table.cpp"
found :
# 274 "/home/claude/cfront-3/src/table.cpp"
error__FiPCc ( (int )'i' , (const char *)"rehash failed") ;

# 276 "/home/claude/cfront-3/src/table.cpp"
add_np :;
}
}

# 280 "/home/claude/cfront-3/src/table.cpp"
void reinit__5tableFv (register struct table *__0this )
# 281 "/home/claude/cfront-3/src/table.cpp"
{ 
# 282 "/home/claude/cfront-3/src/table.cpp"
int __1i ;

# 282 "/home/claude/cfront-3/src/table.cpp"
__1i = 1 ;
for(;__1i < __0this -> free_slot__5table ;__1i ++ ) (__0this -> entries__5table [__1i ])= 0 ;
for(__1i = 0 ;__1i < __0this -> hashsize__5table ;__1i ++ ) (__0this -> hashtbl__5table [__1i ])= 0 ;
__0this -> free_slot__5table = 1 ;
}

# 290 "/home/claude/cfront-3/src/table.cpp"
const char *whatami__5tableFv (register struct table *__0this )
# 291 "/home/claude/cfront-3/src/table.cpp"
{ 
# 292 "/home/claude/cfront-3/src/table.cpp"
if (__0this == 0 )return (const char *)"<null table>";
# 292 "/home/claude/cfront-3/src/table.cpp"

# 293 "/home/claude/cfront-3/src/table.cpp"
if (__0this == gtbl )return (const char *)"global";
if (__0this -> t_name__5table )return (__0this -> t_name__5table -> __O2__4expr.string ?__0this -> t_name__5table -> __O2__4expr.string :(((const char *)"???")));
# 294 "/home/claude/cfront-3/src/table.cpp"

# 295 "/home/claude/cfront-3/src/table.cpp"
return (const char *)"block";
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

# 187 "/home/claude/cfront-3/src/cfront.h"

# 315 "/home/claude/cfront-3/src/table.cpp"
struct ktable *__ct__6ktableFiP6ktableP4name (register struct ktable *__0this , int __1sz , struct ktable *__1nx , Pname __1n )
# 316 "/home/claude/cfront-3/src/table.cpp"
{ 
# 316 "/home/claude/cfront-3/src/table.cpp"
struct node *__0__X26 ;

# 316 "/home/claude/cfront-3/src/table.cpp"
if (__0this || (__0this = (struct ktable *)__nw__6ktableSFUl ( (unsigned long )(sizeof (struct ktable))) )){ __0this = (struct ktable *)( (__0__X26 =
# 316 "/home/claude/cfront-3/src/table.cpp"
(((struct node *)__0this ))), ( ((__0__X26 || (__0__X26 = (struct node *)__nw__FUl ( (unsigned long )(sizeof (struct node))) ))?( ( (__0__X26 ->
# 316 "/home/claude/cfront-3/src/table.cpp"
base__4node = 0 ), (__0__X26 -> permanent__4node = 0 )) , (__0__X26 -> baseclass__4node = 0 )) :0 ), __0__X26 ) ) ;
;

# 317 "/home/claude/cfront-3/src/table.cpp"
__0this -> base__4node = 149 ;
if (__1sz == 0 ){ __0this -> k_tiny__6ktable = 1 ;

# 318 "/home/claude/cfront-3/src/table.cpp"
__0this -> __O1__6ktable.k_n = 0 ;

# 318 "/home/claude/cfront-3/src/table.cpp"
__0this -> k_size__6ktable = 0 ;

# 318 "/home/claude/cfront-3/src/table.cpp"
}
else { __0this -> k_tiny__6ktable = 0 ;

# 319 "/home/claude/cfront-3/src/table.cpp"
__0this -> __O1__6ktable.k_t = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )__1sz , (struct table *)0 , __1n ) ;

# 319 "/home/claude/cfront-3/src/table.cpp"
__0this -> __O1__6ktable.k_t -> t_realbase__5table = 149 ;

# 319 "/home/claude/cfront-3/src/table.cpp"
}
__0this -> k_next__6ktable = __1nx ;

# 320 "/home/claude/cfront-3/src/table.cpp"
__0this -> k_name__6ktable = __1n ;
;
} 
# 321 "/home/claude/cfront-3/src/table.cpp"
return __0this ;
}

# 959 "/home/claude/cfront-3/src/cfront.h"
void del__4nameFv (struct name *__0this );

# 323 "/home/claude/cfront-3/src/table.cpp"
void __dt__6ktableFv (register struct ktable *__0this , 
# 323 "/home/claude/cfront-3/src/table.cpp"
int __0__free )
# 324 "/home/claude/cfront-3/src/table.cpp"
{ if (__0this ){ 
# 325 "/home/claude/cfront-3/src/table.cpp"
if (__0this -> k_tiny__6ktable ){ 
# 326 "/home/claude/cfront-3/src/table.cpp"
Pname __2nx ;
{ { Pname __2n ;

# 327 "/home/claude/cfront-3/src/table.cpp"
__2n = __0this -> __O1__6ktable.k_n ;

# 327 "/home/claude/cfront-3/src/table.cpp"
for(;__2n ;__2n = __2nx ) { 
# 328 "/home/claude/cfront-3/src/table.cpp"
__2nx = __2n -> n_tbl_list__4name ;
if (__2n && (__2n -> permanent__4node == 0 ))del__4nameFv ( __2n ) ;
}
__0this -> __O1__6ktable.k_n = 0 ;

# 331 "/home/claude/cfront-3/src/table.cpp"
}

# 331 "/home/claude/cfront-3/src/table.cpp"
}
}
else 
# 332 "/home/claude/cfront-3/src/table.cpp"
__dt__5tableFv ( __0this -> __O1__6ktable.k_t , 3) ;
if (__0this )if (__0__free & 1)__dl__6ktableSFPvUl ( (void *)__0this , (unsigned long )(sizeof (struct ktable))) ;
} 
# 333 "/home/claude/cfront-3/src/table.cpp"
}
Pname look__6ktableFPCcUc (register struct ktable *__0this , const char *__1s , TOK __1k )
# 335 "/home/claude/cfront-3/src/table.cpp"
{ 
# 336 "/home/claude/cfront-3/src/table.cpp"
if (__0this -> k_tiny__6ktable ){ 
# 337 "/home/claude/cfront-3/src/table.cpp"
{ { Pname __2n ;
# 337 "/home/claude/cfront-3/src/table.cpp"
__2n = __0this -> __O1__6ktable.k_n ;

# 337 "/home/claude/cfront-3/src/table.cpp"
for(;__2n ;__2n = __2n -> n_tbl_list__4name ) 
# 338 "/home/claude/cfront-3/src/table.cpp"
if ((((((*__2n -> __O2__4expr.string ))== ((*__1s )))?strcmp ( __2n -> __O2__4expr.string , __1s ) :-1)== 0 )&& (__2n -> n_key__4name ==
# 338 "/home/claude/cfront-3/src/table.cpp"
__1k ))return __2n ;
return (struct name *)0 ;

# 339 "/home/claude/cfront-3/src/table.cpp"
}

# 339 "/home/claude/cfront-3/src/table.cpp"
}
}
else 
# 340 "/home/claude/cfront-3/src/table.cpp"
return look__5tableFPCcUc ( __0this -> __O1__6ktable.k_t , __1s , __1k ) ;
}

# 328 "/home/claude/cfront-3/src/cfront.h"
Pclass classtype__4typeFv (struct type *__0this );

# 343 "/home/claude/cfront-3/src/table.cpp"
Pname find_cn__6ktableFPCc (register struct ktable *__0this , const char *__1s )
# 344 "/home/claude/cfront-3/src/table.cpp"
{ 
# 345 "/home/claude/cfront-3/src/table.cpp"
if (__0this -> k_id__6ktable != 6 ){ 
# 345 "/home/claude/cfront-3/src/table.cpp"
struct ea __0__V27 ;

# 345 "/home/claude/cfront-3/src/table.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"find_cn( %s) on nonC table", (const struct ea *)( ((&
# 345 "/home/claude/cfront-3/src/table.cpp"
__0__V27 )-> __O1__2ea.p = ((const void *)__1s )), (& __0__V27 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 345 "/home/claude/cfront-3/src/table.cpp"
(const struct ea *)ea0 ) ;
} { Pclass __1cl ;

# 346 "/home/claude/cfront-3/src/table.cpp"
__1cl = classtype__4typeFv ( __0this -> k_name__6ktable -> __O1__4expr.tp ) ;
if ((__1cl -> class_base__8classdef == 0)|| ((__1cl -> class_base__8classdef == 4)&& (__1cl -> templ_base__4type == 2)))
# 350 "/home/claude/cfront-3/src/table.cpp"
return __0this -> k_name__6ktable ;

# 352 "/home/claude/cfront-3/src/table.cpp"
{ Pname __1n ;

# 352 "/home/claude/cfront-3/src/table.cpp"
__1n = look__6ktableFPCcUc ( __0this -> k_name__6ktable -> n_ktable__4name , __1s , (unsigned char )0 ) ;
return ((__1n && (__1n -> base__4node == 85 ))?__1n -> __O1__4name.n_hidden :__1n );

# 353 "/home/claude/cfront-3/src/table.cpp"
}

# 353 "/home/claude/cfront-3/src/table.cpp"
}
}

# 356 "/home/claude/cfront-3/src/table.cpp"
Pname insert__6ktableFP4nameUc (register struct ktable *__0this , Pname __1nn , TOK __1k )
# 357 "/home/claude/cfront-3/src/table.cpp"
{ 
# 358 "/home/claude/cfront-3/src/table.cpp"
if (__1nn -> n_ktable__4name ){ 
# 358 "/home/claude/cfront-3/src/table.cpp"
struct ea __0__V28 ;

# 358 "/home/claude/cfront-3/src/table.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%n inserted twice", (const struct ea *)( ((&
# 358 "/home/claude/cfront-3/src/table.cpp"
__0__V28 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V28 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 358 "/home/claude/cfront-3/src/table.cpp"
(const struct ea *)ea0 ) ;
} if (__0this -> k_tiny__6ktable ){ 
# 360 "/home/claude/cfront-3/src/table.cpp"
Nold = 0 ;
if (__0this -> __O1__6ktable.k_n == 0 ){ 
# 362 "/home/claude/cfront-3/src/table.cpp"
__0this -> __O1__6ktable.k_n = __1nn ;
}
else 
# 363 "/home/claude/cfront-3/src/table.cpp"
{ 
# 364 "/home/claude/cfront-3/src/table.cpp"
{ { Pname __3n ;

# 364 "/home/claude/cfront-3/src/table.cpp"
__3n = __0this -> __O1__6ktable.k_n ;

# 364 "/home/claude/cfront-3/src/table.cpp"
for(;__3n ;__3n = __3n -> n_tbl_list__4name ) { 
# 365 "/home/claude/cfront-3/src/table.cpp"
if ((((((*__3n -> __O2__4expr.string ))== ((*__1nn -> __O2__4expr.string )))?strcmp ( __3n -> __O2__4expr.string , __1nn -> __O2__4expr.string ) :-1)==
# 365 "/home/claude/cfront-3/src/table.cpp"
0 )&& (__3n -> n_key__4name == __1k ))
# 366 "/home/claude/cfront-3/src/table.cpp"
{ Nold = 1 ;

# 366 "/home/claude/cfront-3/src/table.cpp"
return __3n ;

# 366 "/home/claude/cfront-3/src/table.cpp"
}
if (__3n -> n_tbl_list__4name == 0 ){ 
# 368 "/home/claude/cfront-3/src/table.cpp"
__3n -> n_tbl_list__4name = __1nn ;
break ;
}
}

# 371 "/home/claude/cfront-3/src/table.cpp"
}

# 371 "/home/claude/cfront-3/src/table.cpp"
}
}
__1nn -> n_key__4name = __1k ;
__1nn -> n_ktable__4name = __0this ;
__1nn -> n_tbl_list__4name = 0 ;
__1nn -> permanent__4node = 1 ;
return __1nn ;
}
else 
# 378 "/home/claude/cfront-3/src/table.cpp"
{ 
# 379 "/home/claude/cfront-3/src/table.cpp"
__1nn = insert__5tableFP4nameUc ( __0this -> __O1__6ktable.k_t , __1nn , __1k ) ;
if (! Nold )__1nn -> n_ktable__4name = __0this ;
return __1nn ;
}
}

# 234 "/home/claude/cfront-3/src/cfront.h"

# 385 "/home/claude/cfront-3/src/table.cpp"
Pname get_mem__6ktableFi (register struct ktable *__0this , int __1i )
# 386 "/home/claude/cfront-3/src/table.cpp"
{ 
# 386 "/home/claude/cfront-3/src/table.cpp"
struct table *__0__X29 ;

# 387 "/home/claude/cfront-3/src/table.cpp"
if (! __0this -> k_tiny__6ktable )return ( (__0__X29 = __0this -> __O1__6ktable.k_t ), ( (((__1i <= 0 )|| (__0__X29 -> free_slot__5table <= __1i ))?(((struct
# 387 "/home/claude/cfront-3/src/table.cpp"
name *)0 )):(__0__X29 -> entries__5table [__1i ]))) ) ;
else { 
# 389 "/home/claude/cfront-3/src/table.cpp"
Pname __2n ;

# 389 "/home/claude/cfront-3/src/table.cpp"
__2n = __0this -> __O1__6ktable.k_n ;
for(;__2n && (__1i > 1 );( (-- __1i ), (__2n = __2n -> n_tbl_list__4name )) ) ;
return __2n ;
}
}

# 395 "/home/claude/cfront-3/src/table.cpp"
void expand__6ktableFi (register struct ktable *__0this , int __1sz )
# 396 "/home/claude/cfront-3/src/table.cpp"
{ 
# 397 "/home/claude/cfront-3/src/table.cpp"
if (! __0this -> k_tiny__6ktable )return ;
__0this -> k_tiny__6ktable = 0 ;
{ Pname __1names ;

# 399 "/home/claude/cfront-3/src/table.cpp"
__1names = __0this -> __O1__6ktable.k_n ;
__0this -> __O1__6ktable.k_t = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )__1sz , (struct table *)0 , __0this -> k_name__6ktable ) ;
{ { Pname __1nx ;

# 401 "/home/claude/cfront-3/src/table.cpp"
Pname __1n ;

# 401 "/home/claude/cfront-3/src/table.cpp"
__1n = __1names ;

# 401 "/home/claude/cfront-3/src/table.cpp"
for(;__1n ;__1n = __1nx ) { 
# 402 "/home/claude/cfront-3/src/table.cpp"
__1nx = __1n -> n_tbl_list__4name ;
__1n -> n_tbl_list__4name = 0 ;

# 403 "/home/claude/cfront-3/src/table.cpp"
__1n -> __O4__4expr.n_table = 0 ;
insert__5tableFP4nameUc ( __0this -> __O1__6ktable.k_t , __1n , __1n -> n_key__4name ) ;
}

# 405 "/home/claude/cfront-3/src/table.cpp"
}

# 405 "/home/claude/cfront-3/src/table.cpp"
}

# 405 "/home/claude/cfront-3/src/table.cpp"
}
}

# 116 "/home/claude/cfront-3/src/cfront.h"
extern Pname insert_name__FP4nameP6ktable (Pname , Pktab );

# 408 "/home/claude/cfront-3/src/table.cpp"
void hoist__6ktableFv (register struct ktable *__0this )
# 409 "/home/claude/cfront-3/src/table.cpp"
{ 
# 411 "/home/claude/cfront-3/src/table.cpp"
if (! __0this -> k_tiny__6ktable )error__FiPCc ( (int )'i' , (const char *)"hoisting wrong table")
# 411 "/home/claude/cfront-3/src/table.cpp"
;
{ Pname __1names ;

# 412 "/home/claude/cfront-3/src/table.cpp"
__1names = __0this -> __O1__6ktable.k_n ;
__0this -> __O1__6ktable.k_n = 0 ;
{ { Pname __1nx ;

# 414 "/home/claude/cfront-3/src/table.cpp"
Pname __1n ;

# 414 "/home/claude/cfront-3/src/table.cpp"
__1n = __1names ;

# 414 "/home/claude/cfront-3/src/table.cpp"
for(;__1n ;__1n = __1nx ) { 
# 415 "/home/claude/cfront-3/src/table.cpp"
__1nx = __1n -> n_tbl_list__4name ;
__1n -> n_tbl_list__4name = 0 ;

# 416 "/home/claude/cfront-3/src/table.cpp"
__1n -> __O4__4expr.n_table = 0 ;

# 416 "/home/claude/cfront-3/src/table.cpp"
__1n -> n_ktable__4name = 0 ;
insert_name__FP4nameP6ktable ( __1n , __0this -> k_next__6ktable ) ;
}

# 418 "/home/claude/cfront-3/src/table.cpp"
}

# 418 "/home/claude/cfront-3/src/table.cpp"
}

# 418 "/home/claude/cfront-3/src/table.cpp"
}
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

# 419 "/home/claude/cfront-3/src/table.cpp"

/* the end */
