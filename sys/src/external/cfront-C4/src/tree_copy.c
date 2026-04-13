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
enum discriminator_error { discrim_none_valid = 0, discrim_bad_index = -1, discrim_inconsistent_node = -2} ;
enum node_class { nc_unused = 0, nc_eof = 1, nc_virt = 2, nc_nlist = 3, nc_gen = 4, nc_vec = 5, nc_ptr = 6, nc_fct = 7, nc_table = 8, nc_basetype = 9, nc_name = 10, nc_expr = 11, nc_stmt = 12, nc_enumdef = 13,
# 504 "/home/claude/cfront-3/src/template.h"
nc_classdef = 14, nc_baseclass = 15, nc_iline = 16, nc_ia = 17, nc_tpdef = 18, nc_ktable = 19} ;

# 31 "/home/claude/cfront-3/src/hash.h"
typedef void (*Error_Proc )(const char *);

# 38 "/home/claude/cfront-3/src/hash.h"
typedef void (*intProc )(int );
struct HashTableEntry;
struct HashWalker;
struct Hash;
enum __Q2_4Hash13insert_action { probe__Q2_4Hash13insert_action = 0, insert__Q2_4Hash13insert_action = 1, replace__Q2_4Hash13insert_action = 2} ;

# 53 "/home/claude/cfront-3/src/hash.h"
struct Hash {	/* sizeof Hash == 32 */

# 56 "/home/claude/cfront-3/src/hash.h"
struct HashTableEntry *tab__4Hash ;
int size__4Hash ;
int entry_count__4Hash ;

# 61 "/home/claude/cfront-3/src/hash.h"
size_t (*key_hash_function__4Hash )(size_t );
int (*key_key_equality_function__4Hash )(size_t , size_t );
};

# 93 "/home/claude/cfront-3/src/hash.h"
struct HashWalker {	/* sizeof HashWalker == 16 */
struct Hash *h__10HashWalker ;
int pos__10HashWalker ;
};

# 106 "/home/claude/cfront-3/src/hash.h"
void reset__10HashWalkerFv (struct HashWalker *__0this );

# 89 "/home/claude/cfront-3/src/hash.h"
void error__4HashFPCc (struct Hash *__0this , const char *__1msg );

# 44 "/home/claude/cfront-3/src/hash.h"
struct HashTableEntry {	/* sizeof HashTableEntry == 12 */
int key__14HashTableEntry ;
int cont__14HashTableEntry ;
char status__14HashTableEntry ;
};

# 67 "/home/claude/cfront-3/src/hash.h"
struct Hash *__ct__4HashFi (struct Hash *__0this , int __1sz );

# 208 "/home/claude/cfront-3/src/hash.h"
struct pointer_hash {	/* sizeof pointer_hash == 32 */

# 56 "/home/claude/cfront-3/src/hash.h"
struct HashTableEntry *tab__4Hash ;
int size__4Hash ;
int entry_count__4Hash ;

# 61 "/home/claude/cfront-3/src/hash.h"
size_t (*key_hash_function__4Hash )(size_t );
int (*key_key_equality_function__4Hash )(size_t , size_t );
};

# 206 "/home/claude/cfront-3/src/hash.h"
extern size_t pointer_hash_fcn__FUl (size_t );

# 205 "/home/claude/cfront-3/src/hash.h"
extern int pointer_hasheq__FUlT1 (size_t , size_t );

# 68 "/home/claude/cfront-3/src/hash.h"
struct Hash *__ct__4HashFR4Hash (struct Hash *__0this , struct Hash *__1a );

# 131 "/home/claude/cfront-3/src/hash.h"
struct string_hash;

# 221 "/home/claude/cfront-3/src/hash.h"
struct string_hash {	/* sizeof string_hash == 32 */

# 56 "/home/claude/cfront-3/src/hash.h"
struct HashTableEntry *tab__4Hash ;
int size__4Hash ;
int entry_count__4Hash ;

# 61 "/home/claude/cfront-3/src/hash.h"
size_t (*key_hash_function__4Hash )(size_t );
int (*key_key_equality_function__4Hash )(size_t , size_t );
};

# 219 "/home/claude/cfront-3/src/hash.h"
extern size_t string_hash_fcn__FUl (size_t );

# 218 "/home/claude/cfront-3/src/hash.h"
extern int string_hasheq__FUlT1 (size_t , size_t );

# 131 "/home/claude/cfront-3/src/hash.h"
enum tree_node_action { tna_continue = 0, tna_stop = 1, tna_error = 2} ;

# 36 "/home/claude/cfront-3/src/tree_walk.h"
typedef int (*tree_fetch_proc )(void *__0info , void *__0pointer , size_t __0length , int __0zero_stop , void *__0target );

# 43 "/home/claude/cfront-3/src/tree_walk.h"
static tree_fetch_proc null_tfp = (int (*)(void *__0info , void *__0pointer , size_t __0length , int __0zero_stop , void *__0target ))(((int (*)(void *__0info ,
# 43 "/home/claude/cfront-3/src/tree_walk.h"
void *__0pointer , unsigned long __0length , int __0zero_stop , void *__0target ))0 ));
struct tree_walk_tree;

# 54 "/home/claude/cfront-3/src/tree_walk.h"
typedef void (*tree_pre_action )(Pnode *, int , void *, int *, int , Pnode , struct tree_walk_tree *,
# 54 "/home/claude/cfront-3/src/tree_walk.h"
int *);

# 59 "/home/claude/cfront-3/src/tree_walk.h"
typedef void (*tree_post_action )(Pnode *, int , void *, int *, int , Pnode , struct tree_walk_tree *);
# 59 "/home/claude/cfront-3/src/tree_walk.h"

# 63 "/home/claude/cfront-3/src/tree_walk.h"
typedef void (*errorp )(char , const char *);
struct tree_walk_control;

# 65 "/home/claude/cfront-3/src/tree_walk.h"
struct tree_walk_control {	/* sizeof tree_walk_control == 80 */

# 67 "/home/claude/cfront-3/src/tree_walk.h"
int version__17tree_walk_control ;
void *callback_info__17tree_walk_control ;
tree_fetch_proc fetcher__17tree_walk_control ;
tree_pre_action action_proc__17tree_walk_control ;
tree_post_action post_action_proc__17tree_walk_control ;
int (*i_error__17tree_walk_control )(int , const char *);
int call_i_error__17tree_walk_control ;
struct Hash *nodes_seen_hash__17tree_walk_control ;

# 76 "/home/claude/cfront-3/src/tree_walk.h"
int resolve_by_name__17tree_walk_control ;
int alloc_stack_bytes__17tree_walk_control ;

# 80 "/home/claude/cfront-3/src/tree_walk.h"
int dont_chase_lists_top__17tree_walk_control ;
};
struct patch_tree;

# 94 "/home/claude/cfront-3/src/tree_walk.h"
typedef struct patch_tree *Ppatch_tree ;

# 96 "/home/claude/cfront-3/src/tree_walk.h"
struct patch_tree {	/* sizeof patch_tree == 16 */

# 108 "/home/claude/cfront-3/src/tree_walk.h"
Pnode node__10patch_tree ;
Ppatch_tree next__10patch_tree ;
};

# 106 "/home/claude/cfront-3/src/tree_walk.h"
extern Ppatch_tree head__10patch_tree ;
extern struct Hash *ht__10patch_tree ;

# 30 "/home/claude/cfront-3/src/tree_copy.h"
struct tree_copy_info {	/* sizeof tree_copy_info == 24 */

# 42 "/home/claude/cfront-3/src/tree_copy.h"
void (*node_hook__14tree_copy_info )(void *__1info , Pnode *, int , int *, int *);

# 48 "/home/claude/cfront-3/src/tree_copy.h"
char *(*malloc_hook__14tree_copy_info )(void *__1info , size_t );
void *hook_info__14tree_copy_info ;
};
union __C1__copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi__L29;

# 47 "/home/claude/cfront-3/src/tree_copy.cpp"
union __C1__copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi__L29 {	/* sizeof __C1__copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi__L29 == 8 */
Pnode node ;
Pvirt vr ;
Plist list ;
Pgen g ;
Pvec vc ;
Pfct f ;
Ptable t ;
Pktab kt ;
Pbase bt ;
Pexpr x ;
Pstmt s ;
Ptype tp ;
Penum e ;
Pclass c ;
Pbcl bcl ;
Pin iline ;
Pia ia ;
Pname n ;
Pptr p ;
};

# 59 "/home/claude/cfront-3/src/tree_copy.h"

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 99 "/home/claude/cfront-3/src/tree_walk.h"
void add__10patch_treeSFP4node (Pnode );

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 30 "/home/claude/incl-linux32/string.h"
extern void *memcpy (void *, const void *, size_t );

# 56 "/home/claude/cfront-3/src/tree_copy.h"

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

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 37 "/home/claude/cfront-3/src/tree_copy.cpp"

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 591 "/home/claude/cfront-3/src/cfront.h"
int discriminator__8basetypeFi (struct basetype *__0this , int );

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 816 "/home/claude/cfront-3/src/cfront.h"
int discriminator__4exprFi (struct expr *__0this , int );

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 37 "/home/claude/cfront-3/src/tree_copy.cpp"

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 37 "/home/claude/cfront-3/src/tree_copy.cpp"

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 113 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_name__FPCcP6ktableUc (const char *, Pktab , TOK );

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 56 "/home/claude/cfront-3/src/tree_copy.h"

# 43 "/home/claude/cfront-3/src/tree_copy.cpp"
void copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi (Pnode *__1node , int __1cl , void *__1info , 
# 44 "/home/claude/cfront-3/src/tree_copy.cpp"
int *__1action , int __1__A26 , Pnode __1__A27 , struct tree_walk_tree *__1__A28 , 
# 45 "/home/claude/cfront-3/src/tree_copy.cpp"
int
# 45 "/home/claude/cfront-3/src/tree_copy.cpp"
*__1register_in_hash )
# 46 "/home/claude/cfront-3/src/tree_copy.cpp"
{ 
# 47 "/home/claude/cfront-3/src/tree_copy.cpp"

# 67 "/home/claude/cfront-3/src/tree_copy.cpp"
union __C1__copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi__L29 __1n ;
Pnode __1original_node ;

# 70 "/home/claude/cfront-3/src/tree_copy.cpp"
struct tree_copy_info *__1tci ;

# 68 "/home/claude/cfront-3/src/tree_copy.cpp"
__1original_node = ((*__1node ));

# 70 "/home/claude/cfront-3/src/tree_copy.cpp"
__1tci = (((struct tree_copy_info *)(((struct tree_copy_info *)__1info ))));
((*__1action ))= 0;

# 75 "/home/claude/cfront-3/src/tree_copy.cpp"
( (__1tci -> node_hook__14tree_copy_info ?(((void )(*(__1tci -> node_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , __1node , __1cl , __1action , __1register_in_hash ) )):(((void )0 )))) ;
# 75 "/home/claude/cfront-3/src/tree_copy.cpp"

# 76 "/home/claude/cfront-3/src/tree_copy.cpp"
if (((*__1action ))!= 0)return ;

# 78 "/home/claude/cfront-3/src/tree_copy.cpp"
if (((*__1node ))!= __1original_node ){ 
# 79 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . node = ((*__1node ));
}
else switch (__1cl ){ 
# 81 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X31 ;

# 81 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X32 ;

# 82 "/home/claude/cfront-3/src/tree_copy.cpp"
case 0:
# 83 "/home/claude/cfront-3/src/tree_copy.cpp"
break ;
case 1:
# 85 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . node = (((struct node *)(((struct node *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof ((*__1node )))) :(((char
# 85 "/home/claude/cfront-3/src/tree_copy.cpp"
*)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof ((*__1node ))))) )))))) ))));
((*__1n . node ))= (*((*__1node )));
goto Replace ;

# 89 "/home/claude/cfront-3/src/tree_copy.cpp"
case 2:
# 90 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . vr = (((struct virt *)(((struct virt *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct virt )))
# 90 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct virt )))) )))))) ))));
((*__1n . vr ))= (*(((struct virt *)(((struct virt *)((*__1node )))))));
goto Replace ;

# 94 "/home/claude/cfront-3/src/tree_copy.cpp"
case 3:
# 95 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . list = (((struct name_list *)(((struct name_list *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct name_list )))
# 95 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct name_list )))) )))))) ))));
((*__1n . list ))= (*(((struct name_list *)(((struct name_list *)((*__1node )))))));
goto Replace ;

# 99 "/home/claude/cfront-3/src/tree_copy.cpp"
case 4:
# 100 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . g = (((struct gen *)(((struct gen *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct gen )))
# 100 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct gen )))) )))))) ))));
((*__1n . g ))= (*(((struct gen *)(((struct gen *)((*__1node )))))));
goto Replace ;

# 104 "/home/claude/cfront-3/src/tree_copy.cpp"
case 5:
# 105 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . vc = (((struct vec *)(((struct vec *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct vec )))
# 105 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct vec )))) )))))) ))));
((*__1n . vc ))= (*(((struct vec *)(((struct vec *)((*__1node )))))));
goto Replace ;

# 109 "/home/claude/cfront-3/src/tree_copy.cpp"
case 6:
# 110 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . p = (((struct ptr *)(((struct ptr *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct ptr )))
# 110 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct ptr )))) )))))) ))));
((*__1n . p ))= (*(((struct ptr *)(((struct ptr *)((*__1node )))))));
goto Replace ;

# 114 "/home/claude/cfront-3/src/tree_copy.cpp"
case 7:
# 115 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . f = (((struct fct *)(((struct fct *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct fct )))
# 115 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct fct )))) )))))) ))));
((*__1n . f ))= (*(((struct fct *)(((struct fct *)((*__1node )))))));
if (__1n . f -> f_signature__3fct ){ 
# 118 "/home/claude/cfront-3/src/tree_copy.cpp"
char *__3str_tmp ;

# 119 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X30 ;

# 118 "/home/claude/cfront-3/src/tree_copy.cpp"
__3str_tmp = (((char *)( (__2__X30 = (strlen ( (((struct fct *)(((struct fct *)((*__1node ))))))-> f_signature__3fct ) + 1 )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci ->
# 118 "/home/claude/cfront-3/src/tree_copy.cpp"
malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , __2__X30 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X30 )) ))))))
# 118 "/home/claude/cfront-3/src/tree_copy.cpp"
) ));

# 120 "/home/claude/cfront-3/src/tree_copy.cpp"
strcpy ( __3str_tmp , (((struct fct *)(((struct fct *)((*__1node ))))))-> f_signature__3fct ) ;

# 122 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . f -> f_signature__3fct = (const char *)__3str_tmp ;
}

# 123 "/home/claude/cfront-3/src/tree_copy.cpp"
;
goto Replace ;

# 126 "/home/claude/cfront-3/src/tree_copy.cpp"
case 8:
# 127 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . t = (((struct table *)(((struct table *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct table )))
# 127 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct table )))) )))))) ))));
((*__1n . t ))= (*(((struct table *)(((struct table *)((*__1node )))))));
add__10patch_treeSFP4node ( __1n . node ) ;
__1n . t -> entries__5table = (((Pname *)( (__2__X31 = ((sizeof (Pname ))* __1n . t -> size__5table )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))(
# 130 "/home/claude/cfront-3/src/tree_copy.cpp"
__1tci -> hook_info__14tree_copy_info , __2__X31 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X31 )) )))))) )
# 130 "/home/claude/cfront-3/src/tree_copy.cpp"
));
memcpy ( (void *)(((char *)__1n . t -> entries__5table )), (const void *)(((char *)(((struct table *)(((struct table *)((*__1node ))))))-> entries__5table )), __1n .
# 131 "/home/claude/cfront-3/src/tree_copy.cpp"
t -> size__5table * (sizeof (Pname ))) ;
__1n . t -> hashtbl__5table = (((short *)( (__2__X32 = ((sizeof (short ))* __1n . t -> hashsize__5table )), ( (__1tci ->
# 132 "/home/claude/cfront-3/src/tree_copy.cpp"
malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , __2__X32 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X32 ))
# 132 "/home/claude/cfront-3/src/tree_copy.cpp"
)))))) ) ));
memcpy ( (void *)(((char *)__1n . t -> hashtbl__5table )), (const void *)(((char *)(((struct table *)(((struct table *)((*__1node ))))))-> hashtbl__5table )), __1n .
# 133 "/home/claude/cfront-3/src/tree_copy.cpp"
t -> hashsize__5table * (sizeof (short ))) ;
goto Replace ;

# 136 "/home/claude/cfront-3/src/tree_copy.cpp"
case 19:
# 138 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . kt = (((struct ktable *)(((struct ktable *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct ktable )))
# 138 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct ktable )))) )))))) ))));
((*__1n . kt ))= (*(((struct ktable *)(((struct ktable *)((*__1node )))))));
add__10patch_treeSFP4node ( __1n . node ) ;
goto Replace ;

# 143 "/home/claude/cfront-3/src/tree_copy.cpp"
case 9:
# 145 "/home/claude/cfront-3/src/tree_copy.cpp"
if (( ((((struct type *)(((struct type *)((*__1node ))))))-> defined__4type & 65)) ){ 
# 146 "/home/claude/cfront-3/src/tree_copy.cpp"
((*__1action ))= 1;
return ;
}
__1n . bt = (((struct basetype *)(((struct basetype *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct basetype ))) :(((char
# 149 "/home/claude/cfront-3/src/tree_copy.cpp"
*)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct basetype )))) )))))) ))));
((*__1n . bt ))= (*(((struct basetype *)(((struct basetype *)((*__1node )))))));
__1n . bt -> defined__4type |= 0100 ;
if ((discriminator__8basetypeFi ( __1n . bt , 0 ) == 2 )&& __1n . bt -> __O1__8basetype.b_linkage ){ 
# 153 "/home/claude/cfront-3/src/tree_copy.cpp"
char *__3str_tmp ;

# 154 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X33 ;

# 153 "/home/claude/cfront-3/src/tree_copy.cpp"
__3str_tmp = ( (__2__X33 = (strlen ( __1n . bt -> __O1__8basetype.b_linkage ) + 1 )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci ->
# 153 "/home/claude/cfront-3/src/tree_copy.cpp"
hook_info__14tree_copy_info , __2__X33 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X33 )) )))))) ) ;
# 153 "/home/claude/cfront-3/src/tree_copy.cpp"

# 154 "/home/claude/cfront-3/src/tree_copy.cpp"
strcpy ( __3str_tmp , (((struct basetype *)(((struct basetype *)((*__1node ))))))-> __O1__8basetype.b_linkage ) ;

# 156 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . bt -> __O1__8basetype.b_linkage = (const char *)__3str_tmp ;
}
goto Replace ;

# 160 "/home/claude/cfront-3/src/tree_copy.cpp"
case 11:
# 162 "/home/claude/cfront-3/src/tree_copy.cpp"
if ((((*__1node ))== (((struct node *)dummy )))|| (((*__1node ))== (((struct node *)zero )))){ 
# 163 "/home/claude/cfront-3/src/tree_copy.cpp"
((*__1action ))= 1;
return ;
}
__1n . x = (((struct expr *)(((struct expr *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct expr ))) :(((char
# 166 "/home/claude/cfront-3/src/tree_copy.cpp"
*)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct expr )))) )))))) ))));
((*__1n . x ))= (*(((struct expr *)(((struct expr *)((*__1node )))))));
if ((discriminator__4exprFi ( __1n . x , 1 ) == 3 )&& __1n . x -> __O2__4expr.string ){ 
# 169 "/home/claude/cfront-3/src/tree_copy.cpp"
char *__3str_tmp ;

# 170 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X34 ;

# 169 "/home/claude/cfront-3/src/tree_copy.cpp"
__3str_tmp = ( (__2__X34 = (strlen ( __1n . x -> __O2__4expr.string ) + 1 )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci ->
# 169 "/home/claude/cfront-3/src/tree_copy.cpp"
hook_info__14tree_copy_info , __2__X34 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X34 )) )))))) ) ;
# 169 "/home/claude/cfront-3/src/tree_copy.cpp"

# 170 "/home/claude/cfront-3/src/tree_copy.cpp"
strcpy ( __3str_tmp , (((struct expr *)(((struct expr *)((*__1node ))))))-> __O2__4expr.string ) ;

# 172 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . x -> __O2__4expr.string = (const char *)__3str_tmp ;
}
if ((discriminator__4exprFi ( __1n . x , 2 ) == 3 )&& __1n . x -> __O3__4expr.string2 ){ 
# 175 "/home/claude/cfront-3/src/tree_copy.cpp"
char *__3str_tmp ;

# 176 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X35 ;

# 175 "/home/claude/cfront-3/src/tree_copy.cpp"
__3str_tmp = ( (__2__X35 = (strlen ( __1n . x -> __O3__4expr.string2 ) + 1 )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci ->
# 175 "/home/claude/cfront-3/src/tree_copy.cpp"
hook_info__14tree_copy_info , __2__X35 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X35 )) )))))) ) ;
# 175 "/home/claude/cfront-3/src/tree_copy.cpp"

# 176 "/home/claude/cfront-3/src/tree_copy.cpp"
strcpy ( __3str_tmp , (((struct expr *)(((struct expr *)((*__1node ))))))-> __O3__4expr.string2 ) ;

# 178 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . x -> __O3__4expr.string2 = (const char *)__3str_tmp ;
}
goto Replace ;

# 182 "/home/claude/cfront-3/src/tree_copy.cpp"
case 12:
# 183 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . s = (((struct stmt *)(((struct stmt *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct stmt )))
# 183 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct stmt )))) )))))) ))));
((*__1n . s ))= (*(((struct stmt *)(((struct stmt *)((*__1node )))))));
goto Replace ;

# 187 "/home/claude/cfront-3/src/tree_copy.cpp"
case 13:
# 188 "/home/claude/cfront-3/src/tree_copy.cpp"
if (( ((((struct type *)(((struct type *)((*__1node ))))))-> defined__4type & 65)) ){ 
# 189 "/home/claude/cfront-3/src/tree_copy.cpp"
((*__1action ))= 1;
return ;
}
__1n . e = (((struct enumdef *)(((struct enumdef *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct enumdef ))) :(((char
# 192 "/home/claude/cfront-3/src/tree_copy.cpp"
*)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct enumdef )))) )))))) ))));
((*__1n . e ))= (*(((struct enumdef *)(((struct enumdef *)((*__1node )))))));
__1n . e -> defined__4type |= 0100 ;
if (__1n . e -> string__7enumdef ){ 
# 196 "/home/claude/cfront-3/src/tree_copy.cpp"
char *__3str_tmp ;

# 197 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X36 ;

# 196 "/home/claude/cfront-3/src/tree_copy.cpp"
__3str_tmp = ( (__2__X36 = (__1n . e -> e_strlen__7enumdef + 1 )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , __2__X36 )
# 196 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X36 )) )))))) ) ;
strcpy ( __3str_tmp , (((struct enumdef *)(((struct enumdef *)((*__1node ))))))-> string__7enumdef ) ;

# 199 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . e -> string__7enumdef = (const char *)__3str_tmp ;
}
if (__1n . e -> nested_sig__4type )
# 202 "/home/claude/cfront-3/src/tree_copy.cpp"
{ 
# 203 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . e -> nested_sig__4type = 0 ;
}
goto Replace ;

# 207 "/home/claude/cfront-3/src/tree_copy.cpp"
case 14:
# 209 "/home/claude/cfront-3/src/tree_copy.cpp"
if (( ((((struct type *)(((struct type *)((*__1node ))))))-> defined__4type & 65)) ){ 
# 210 "/home/claude/cfront-3/src/tree_copy.cpp"
((*__1action ))= 1;
return ;
}
__1n . c = (((struct classdef *)(((struct classdef *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct classdef ))) :(((char
# 213 "/home/claude/cfront-3/src/tree_copy.cpp"
*)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct classdef )))) )))))) ))));
((*__1n . c ))= (*(((struct classdef *)(((struct classdef *)((*__1node )))))));
__1n . c -> defined__4type |= 0100 ;
if (__1n . c -> string__8classdef ){ 
# 217 "/home/claude/cfront-3/src/tree_copy.cpp"
char *__3str_tmp ;

# 218 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X37 ;

# 217 "/home/claude/cfront-3/src/tree_copy.cpp"
__3str_tmp = ( (__2__X37 = (strlen ( __1n . c -> string__8classdef ) + 1 )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci ->
# 217 "/home/claude/cfront-3/src/tree_copy.cpp"
hook_info__14tree_copy_info , __2__X37 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X37 )) )))))) ) ;
# 217 "/home/claude/cfront-3/src/tree_copy.cpp"

# 218 "/home/claude/cfront-3/src/tree_copy.cpp"
strcpy ( __3str_tmp , (((struct classdef *)(((struct classdef *)((*__1node ))))))-> string__8classdef ) ;

# 220 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . c -> string__8classdef = (const char *)__3str_tmp ;
}
if (__1n . c -> nested_sig__4type )
# 223 "/home/claude/cfront-3/src/tree_copy.cpp"
{ 
# 223 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X38 ;

# 224 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . c -> nested_sig__4type = ( (__2__X38 = (strlen ( (const char *)__1n . c -> nested_sig__4type ) + 1 )), (
# 224 "/home/claude/cfront-3/src/tree_copy.cpp"
(__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , __2__X38 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))*
# 224 "/home/claude/cfront-3/src/tree_copy.cpp"
__2__X38 )) )))))) ) ;
strcpy ( __1n . c -> nested_sig__4type , (const char *)(((struct classdef *)(((struct classdef *)((*__1node ))))))-> nested_sig__4type ) ;
}
goto Replace ;

# 229 "/home/claude/cfront-3/src/tree_copy.cpp"
case 15:
# 230 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . bcl = (((struct basecl *)(((struct basecl *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct basecl )))
# 230 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct basecl )))) )))))) ))));
((*__1n . bcl ))= (*(((struct basecl *)(((struct basecl *)((*__1node )))))));
goto Replace ;

# 234 "/home/claude/cfront-3/src/tree_copy.cpp"
case 18:
# 235 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . tp = (((struct type *)(((struct type *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct type )))
# 235 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct type )))) )))))) ))));
((*__1n . tp ))= (*(((struct type *)(((struct type *)((*__1node )))))));
if (__1n . tp -> nested_sig__4type )
# 238 "/home/claude/cfront-3/src/tree_copy.cpp"
{ 
# 238 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X39 ;

# 239 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . tp -> nested_sig__4type = ( (__2__X39 = (strlen ( (const char *)__1n . tp -> nested_sig__4type ) + 1 )), (
# 239 "/home/claude/cfront-3/src/tree_copy.cpp"
(__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , __2__X39 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))*
# 239 "/home/claude/cfront-3/src/tree_copy.cpp"
__2__X39 )) )))))) ) ;
strcpy ( __1n . tp -> nested_sig__4type , (const char *)(((struct type *)(((struct type *)((*__1node ))))))-> nested_sig__4type ) ;
}
goto Replace ;

# 244 "/home/claude/cfront-3/src/tree_copy.cpp"
case 16:
# 245 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . iline = (((struct iline *)(((struct iline *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct iline )))
# 245 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct iline )))) )))))) ))));
((*__1n . iline ))= (*(((struct iline *)(((struct iline *)((*__1node )))))));
goto Replace ;

# 249 "/home/claude/cfront-3/src/tree_copy.cpp"
case 17:
# 250 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . ia = (((struct ia *)(((struct ia *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct ia )))
# 250 "/home/claude/cfront-3/src/tree_copy.cpp"
:(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct ia )))) )))))) ))));
((*__1n . ia ))= (*(((struct ia *)(((struct ia *)((*__1node )))))));
goto Replace ;

# 254 "/home/claude/cfront-3/src/tree_copy.cpp"
case 10:
# 256 "/home/claude/cfront-3/src/tree_copy.cpp"
if ((((struct name *)(((struct name *)((*__1node ))))))-> __O2__4expr.string ){ 
# 258 "/home/claude/cfront-3/src/tree_copy.cpp"
Pname __3n ;
if (((*__1node ))-> base__4node == 123 ){ 
# 260 "/home/claude/cfront-3/src/tree_copy.cpp"
__3n = k_find_name__FPCcP6ktableUc ( (((struct name *)(((struct name *)((*__1node ))))))-> __O2__4expr.string , Gtbl , (unsigned char )0 )
# 260 "/home/claude/cfront-3/src/tree_copy.cpp"
;
if (__3n && (__3n -> base__4node == 85 ))__3n = 0 ;
}
else 
# 262 "/home/claude/cfront-3/src/tree_copy.cpp"
__3n = look__5tableFPCcUc ( gtbl , (((struct name *)(((struct name *)((*__1node ))))))-> __O2__4expr.string , (unsigned char )0 ) ;
if ((((struct name *)(((struct name *)((*__1node ))))))== __3n ){ 
# 264 "/home/claude/cfront-3/src/tree_copy.cpp"
((*__1action ))= 1;
return ;
}
}
__1n . n = (((struct name *)(((struct name *)( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , (sizeof (struct name ))) :(((char
# 268 "/home/claude/cfront-3/src/tree_copy.cpp"
*)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (sizeof (struct name )))) )))))) ))));
((*__1n . n ))= (*(((struct name *)(((struct name *)((*__1node )))))));
if (__1n . n -> n_ktable__4name )
# 271 "/home/claude/cfront-3/src/tree_copy.cpp"
add__10patch_treeSFP4node ( __1n . node ) ;

# 273 "/home/claude/cfront-3/src/tree_copy.cpp"
{ 
# 274 "/home/claude/cfront-3/src/tree_copy.cpp"
int __3done ;

# 274 "/home/claude/cfront-3/src/tree_copy.cpp"
__3done = 0 ;
if ((__1n . n -> base__4node == 176 )&& __1n . n -> __O2__4expr.string ){ 
# 276 "/home/claude/cfront-3/src/tree_copy.cpp"
Pbase_inst __4bi ;

# 276 "/home/claude/cfront-3/src/tree_copy.cpp"
__4bi = (((struct basic_inst *)(((struct basic_inst *)__1tci -> hook_info__14tree_copy_info ))));
{ { Plist __4formal ;

# 277 "/home/claude/cfront-3/src/tree_copy.cpp"
__4formal = __4bi -> inst_formals__10basic_inst ;

# 277 "/home/claude/cfront-3/src/tree_copy.cpp"
for(;__4formal ;__4formal = __4formal -> l__9name_list ) { 
# 278 "/home/claude/cfront-3/src/tree_copy.cpp"
if (__4formal -> f__9name_list -> n_template_arg__4name != 1)
# 279 "/home/claude/cfront-3/src/tree_copy.cpp"
continue ;
if (strcmp ( __4formal -> f__9name_list -> __O2__4expr.string , __1n . n -> __O2__4expr.string ) == 0 ){ 
# 281 "/home/claude/cfront-3/src/tree_copy.cpp"
Ptype __6t ;
Pname __6cn ;

# 281 "/home/claude/cfront-3/src/tree_copy.cpp"
__6t = __4formal -> f__9name_list -> __O1__4expr.tp ;
__6cn = is_cl_obj__4typeFv ( __6t ) ;
if (__6cn || eobj ){ 
# 284 "/home/claude/cfront-3/src/tree_copy.cpp"
char *__7str_tmp ;

# 285 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X40 ;

# 284 "/home/claude/cfront-3/src/tree_copy.cpp"
__7str_tmp = ( (__2__X40 = (strlen ( eobj ?(((struct enumdef *)(((struct enumdef *)eobj -> __O1__4expr.tp ))))-> string__7enumdef :(((struct classdef *)(((struct classdef *)__6cn -> __O1__4expr.tp ))))-> string__8classdef ) +
# 284 "/home/claude/cfront-3/src/tree_copy.cpp"
1 )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , __2__X40 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof
# 284 "/home/claude/cfront-3/src/tree_copy.cpp"
(char ))* __2__X40 )) )))))) ) ;
strcpy ( __7str_tmp , eobj ?(((struct enumdef *)(((struct enumdef *)eobj -> __O1__4expr.tp ))))-> string__7enumdef :(((struct classdef *)(((struct classdef *)__6cn -> __O1__4expr.tp ))))-> string__8classdef ) ;

# 287 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . n -> __O2__4expr.string = (const char *)__7str_tmp ;
}
else 
# 288 "/home/claude/cfront-3/src/tree_copy.cpp"
{ 
# 289 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . n -> __O2__4expr.string = 0 ;
}
__3done = 1 ;
break ;
}
}

# 294 "/home/claude/cfront-3/src/tree_copy.cpp"
}

# 294 "/home/claude/cfront-3/src/tree_copy.cpp"
}
}
else 
# 295 "/home/claude/cfront-3/src/tree_copy.cpp"
if (((! __3done )&& (discriminator__4exprFi ( __1n . x , 1 ) == 3 ))&& __1n . n -> __O2__4expr.string ){ 
# 296 "/home/claude/cfront-3/src/tree_copy.cpp"
char
# 296 "/home/claude/cfront-3/src/tree_copy.cpp"
*__4str_tmp ;

# 297 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X41 ;

# 296 "/home/claude/cfront-3/src/tree_copy.cpp"
__4str_tmp = ( (__2__X41 = (strlen ( __1n . n -> __O2__4expr.string ) + 1 )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci ->
# 296 "/home/claude/cfront-3/src/tree_copy.cpp"
hook_info__14tree_copy_info , __2__X41 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X41 )) )))))) ) ;
# 296 "/home/claude/cfront-3/src/tree_copy.cpp"

# 297 "/home/claude/cfront-3/src/tree_copy.cpp"
strcpy ( __4str_tmp , (((struct expr *)(((struct expr *)((*__1node ))))))-> __O2__4expr.string ) ;

# 299 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . n -> __O2__4expr.string = (const char *)__4str_tmp ;
}
}
if ((discriminator__4exprFi ( __1n . x , 2 ) == 3 )&& __1n . n -> __O3__4expr.string2 ){ 
# 303 "/home/claude/cfront-3/src/tree_copy.cpp"
char *__3str_tmp ;

# 304 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X42 ;

# 303 "/home/claude/cfront-3/src/tree_copy.cpp"
__3str_tmp = ( (__2__X42 = (strlen ( __1n . n -> __O3__4expr.string2 ) + 1 )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci ->
# 303 "/home/claude/cfront-3/src/tree_copy.cpp"
hook_info__14tree_copy_info , __2__X42 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X42 )) )))))) ) ;
# 303 "/home/claude/cfront-3/src/tree_copy.cpp"

# 304 "/home/claude/cfront-3/src/tree_copy.cpp"
strcpy ( __3str_tmp , (((struct expr *)(((struct expr *)((*__1node ))))))-> __O3__4expr.string2 ) ;

# 306 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . n -> __O3__4expr.string2 = (const char *)__3str_tmp ;

# 308 "/home/claude/cfront-3/src/tree_copy.cpp"
}
if (__1n . n -> n_anon__4name ){ 
# 310 "/home/claude/cfront-3/src/tree_copy.cpp"
char *__3str_tmp ;

# 311 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X43 ;

# 310 "/home/claude/cfront-3/src/tree_copy.cpp"
__3str_tmp = ( (__2__X43 = (strlen ( __1n . n -> n_anon__4name ) + 1 )), ( (__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci ->
# 310 "/home/claude/cfront-3/src/tree_copy.cpp"
hook_info__14tree_copy_info , __2__X43 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __2__X43 )) )))))) ) ;
# 310 "/home/claude/cfront-3/src/tree_copy.cpp"

# 311 "/home/claude/cfront-3/src/tree_copy.cpp"
strcpy ( __3str_tmp , (((struct name *)(((struct name *)((*__1node ))))))-> n_anon__4name ) ;

# 313 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . n -> n_anon__4name = (const char *)__3str_tmp ;
}
if (__1n . n -> n_template_arg_string__4name ){ 
# 315 "/home/claude/cfront-3/src/tree_copy.cpp"
unsigned long __2__X44 ;

# 317 "/home/claude/cfront-3/src/tree_copy.cpp"
__1n . n -> n_template_arg_string__4name = ( (__2__X44 = (strlen ( (const char *)__1n . n -> n_template_arg_string__4name ) + 1 )), (
# 317 "/home/claude/cfront-3/src/tree_copy.cpp"
(__1tci -> malloc_hook__14tree_copy_info ?(*(__1tci -> malloc_hook__14tree_copy_info ))( __1tci -> hook_info__14tree_copy_info , __2__X44 ) :(((char *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))*
# 317 "/home/claude/cfront-3/src/tree_copy.cpp"
__2__X44 )) )))))) ) ;
strcpy ( __1n . n -> n_template_arg_string__4name , (const char *)(((struct name *)(((struct name *)((*__1node ))))))-> n_template_arg_string__4name ) ;
}
}
Replace :
# 322 "/home/claude/cfront-3/src/tree_copy.cpp"
((*__1node ))= __1n . node ;
((*__1action ))= 0;
return ;
}

# 327 "/home/claude/cfront-3/src/tree_copy.cpp"
static int call_error__FiPCc (int __1i , const char *__1s )
# 328 "/home/claude/cfront-3/src/tree_copy.cpp"
{ 
# 329 "/home/claude/cfront-3/src/tree_copy.cpp"
return error__FiPCc ( __1i , __1s ) ;
}

# 81 "/home/claude/cfront-3/src/tree_walk.h"

# 115 "/home/claude/cfront-3/src/tree_walk.h"
extern int walk_tree__FR17tree_walk_controlRP4node (struct tree_walk_control *__0c , Pnode *__0n );

# 333 "/home/claude/cfront-3/src/tree_copy.cpp"
void copy_tree__FRP4nodeR14tree_copy_infoP4Hash (Pnode *__1node , struct tree_copy_info *__1tci , struct Hash *__1cht )
# 334 "/home/claude/cfront-3/src/tree_copy.cpp"
{ 
# 335 "/home/claude/cfront-3/src/tree_copy.cpp"
struct tree_walk_control __1twc ;

# 335 "/home/claude/cfront-3/src/tree_copy.cpp"
( (( ((& __1twc )-> version__17tree_walk_control = 1 ), ( ((& __1twc )-> callback_info__17tree_walk_control = 0 ), ( ((& __1twc )->
# 335 "/home/claude/cfront-3/src/tree_copy.cpp"
fetcher__17tree_walk_control = null_tfp ), ( ((& __1twc )-> call_i_error__17tree_walk_control = 0 ), ( ((& __1twc )-> nodes_seen_hash__17tree_walk_control = 0 ), ( ((&
# 335 "/home/claude/cfront-3/src/tree_copy.cpp"
__1twc )-> resolve_by_name__17tree_walk_control = 1 ), ( ((& __1twc )-> alloc_stack_bytes__17tree_walk_control = 0 ), ( ((& __1twc )-> post_action_proc__17tree_walk_control = 0 ), ((&
# 335 "/home/claude/cfront-3/src/tree_copy.cpp"
__1twc )-> dont_chase_lists_top__17tree_walk_control = 0 )) ) ) ) ) ) ) ) ), (& __1twc )) ;
# 335 "/home/claude/cfront-3/src/tree_copy.cpp"

# 337 "/home/claude/cfront-3/src/tree_copy.cpp"
__1twc . call_i_error__17tree_walk_control = 1 ;
__1twc . i_error__17tree_walk_control = (call_error__FiPCc );
__1twc . action_proc__17tree_walk_control = (copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi );
__1twc . nodes_seen_hash__17tree_walk_control = __1cht ;
__1twc . callback_info__17tree_walk_control = (((void *)(__1tci )));

# 343 "/home/claude/cfront-3/src/tree_copy.cpp"
walk_tree__FR17tree_walk_controlRP4node ( (struct tree_walk_control *)(& __1twc ), __1node ) ;
}

# 107 "/home/claude/cfront-3/src/tree_walk.h"
extern struct Hash *ht__10patch_tree ;

# 106 "/home/claude/cfront-3/src/tree_walk.h"
extern Ppatch_tree head__10patch_tree;

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

# 344 "/home/claude/cfront-3/src/tree_copy.cpp"

/* the end */
