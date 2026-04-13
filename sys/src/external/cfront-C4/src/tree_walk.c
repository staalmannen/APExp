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
enum discriminator_error { discrim_none_valid = 0, discrim_bad_index = -1, discrim_inconsistent_node = -2} ;
enum node_class { nc_unused = 0, nc_eof = 1, nc_virt = 2, nc_nlist = 3, nc_gen = 4, nc_vec = 5, nc_ptr = 6, nc_fct = 7, nc_table = 8, nc_basetype = 9, nc_name = 10, nc_expr = 11, nc_stmt = 12, nc_enumdef = 13,
# 226 "/home/claude/cfront-3/src/cfront.h"
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

# 1 ""
extern void __dl__FPv (void *);

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
struct pointer_hash;

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
struct walker;

# 36 "/home/claude/cfront-3/src/tree_walk.cpp"
struct walker {	/* sizeof walker == 112 */
struct tree_walk_control control__6walker ;
Pnode orig_addr__6walker ;
struct Hash *nodes_seen_hash__6walker ;
int depth__6walker ;
int made_ht__6walker ;
struct tree_walk_tree *cur_tree__6walker ;
};

# 1 ""

# 131 "/home/claude/cfront-3/src/hash.h"

# 50 "/home/claude/cfront-3/src/tree_walk.cpp"
int walk___6walkerFRP4node (struct walker *__0this , Pnode *);

# 93 "/home/claude/cfront-3/src/tree_walk.cpp"
int fetch__6walkerFPvUlRPv (struct walker *__0this , void *, size_t , void **);

# 45 "/home/claude/cfront-3/src/tree_walk.h"
struct tree_walk_tree {	/* sizeof tree_walk_tree == 16 */

# 47 "/home/claude/cfront-3/src/tree_walk.h"
struct tree_walk_tree *parent__14tree_walk_tree ;
char storage__14tree_walk_tree [1];
};

# 49 "/home/claude/cfront-3/src/tree_walk.cpp"
int walk__6walkerFRP4node (struct walker *__0this , Pnode *);

# 129 "/home/claude/cfront-3/src/tree_walk.cpp"
int walk___6walkerFRP4node (register struct walker *__0this , Pnode *__1n )
# 130 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 131 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((*__1n )){ 
# 132 "/home/claude/cfront-3/src/tree_walk.cpp"
int __2save_depth ;
struct tree_walk_tree *__2save_cur_tree ;

# 132 "/home/claude/cfront-3/src/tree_walk.cpp"
__2save_depth = __0this -> depth__6walker ;
__2save_cur_tree = __0this -> cur_tree__6walker ;

# 135 "/home/claude/cfront-3/src/tree_walk.cpp"
__0this -> depth__6walker ++ ;
if (__0this -> control__6walker . alloc_stack_bytes__17tree_walk_control ){ 
# 139 "/home/claude/cfront-3/src/tree_walk.cpp"
__0this -> cur_tree__6walker = (((struct tree_walk_tree *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))*
# 139 "/home/claude/cfront-3/src/tree_walk.cpp"
(__0this -> control__6walker . alloc_stack_bytes__17tree_walk_control + (sizeof (struct tree_walk_tree ))))) ))));
__0this -> cur_tree__6walker -> parent__14tree_walk_tree = __2save_cur_tree ;
}
{ int __2r ;

# 142 "/home/claude/cfront-3/src/tree_walk.cpp"
__2r = walk__6walkerFRP4node ( __0this , __1n ) ;
__0this -> depth__6walker = __2save_depth ;
return __2r ;

# 144 "/home/claude/cfront-3/src/tree_walk.cpp"
}
}
else 
# 145 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 210 "/home/claude/cfront-3/src/hash.h"

# 81 "/home/claude/cfront-3/src/tree_walk.h"

# 148 "/home/claude/cfront-3/src/tree_walk.cpp"
struct walker *__ct__6walkerFRC17tree_walk_control (register struct walker *__0this , const struct tree_walk_control *__1c )
# 149 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 149 "/home/claude/cfront-3/src/tree_walk.cpp"
register struct tree_walk_control *__0__X18 ;

# 149 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__0this || (__0this = (struct walker *)__nw__FUl ( (unsigned long )(sizeof (struct walker))) )){ ( (__0__X18 = (& __0this ->
# 149 "/home/claude/cfront-3/src/tree_walk.cpp"
control__6walker )), ( ((__0__X18 || (__0__X18 = (struct tree_walk_control *)__nw__FUl ( (unsigned long )(sizeof (struct tree_walk_control))) ))?( (__0__X18 -> version__17tree_walk_control = 1 ),
# 149 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__0__X18 -> callback_info__17tree_walk_control = 0 ), ( (__0__X18 -> fetcher__17tree_walk_control = null_tfp ), ( (__0__X18 -> call_i_error__17tree_walk_control = 0 ), ( (__0__X18 ->
# 149 "/home/claude/cfront-3/src/tree_walk.cpp"
nodes_seen_hash__17tree_walk_control = 0 ), ( (__0__X18 -> resolve_by_name__17tree_walk_control = 1 ), ( (__0__X18 -> alloc_stack_bytes__17tree_walk_control = 0 ), ( (__0__X18 -> post_action_proc__17tree_walk_control = 0 ),
# 149 "/home/claude/cfront-3/src/tree_walk.cpp"
(__0__X18 -> dont_chase_lists_top__17tree_walk_control = 0 )) ) ) ) ) ) ) ) :0 ), __0__X18 ) ) ;
# 149 "/home/claude/cfront-3/src/tree_walk.cpp"
__0this -> control__6walker = (*__1c );
__0this -> made_ht__6walker = 0 ;
if (((*__1c )). nodes_seen_hash__17tree_walk_control )
# 152 "/home/claude/cfront-3/src/tree_walk.cpp"
__0this -> nodes_seen_hash__6walker = ((*__1c )). nodes_seen_hash__17tree_walk_control ;
else { 
# 153 "/home/claude/cfront-3/src/tree_walk.cpp"
register struct pointer_hash *__0__X19 ;

# 154 "/home/claude/cfront-3/src/tree_walk.cpp"
__0this -> nodes_seen_hash__6walker = (struct Hash *)( (__0__X19 = 0 ), ( ((__0__X19 || (__0__X19 = (struct pointer_hash *)__nw__FUl ( (unsigned long )(sizeof
# 154 "/home/claude/cfront-3/src/tree_walk.cpp"
(struct pointer_hash))) ))?( (__0__X19 = (struct pointer_hash *)__ct__4HashFi ( ((struct Hash *)__0__X19 ), (int )((unsigned long )100 )) ), ( (__0__X19 ->
# 154 "/home/claude/cfront-3/src/tree_walk.cpp"
key_hash_function__4Hash = (pointer_hash_fcn__FUl )), (__0__X19 -> key_key_equality_function__4Hash = (pointer_hasheq__FUlT1 ))) ) :0 ), __0__X19 ) ) ;
__0this -> made_ht__6walker = 1 ;
}
__0this -> depth__6walker = 0 ;
__0this -> cur_tree__6walker = 0 ;
} 
# 158 "/home/claude/cfront-3/src/tree_walk.cpp"
return __0this ;
}

# 161 "/home/claude/cfront-3/src/tree_walk.cpp"
extern Ppatch_tree head__10patch_tree;
extern struct Hash *ht__10patch_tree ;

# 82 "/home/claude/cfront-3/src/hash.h"
void action__4HashFUlT1Q2_4Hash13insert_actionRUlT4 (struct Hash *__0this , size_t __1key , size_t __1val , int __1what , size_t *__1found , size_t *__1old_val );

# 164 "/home/claude/cfront-3/src/tree_walk.cpp"
Pnode probe__10patch_treeSFP4node (Pnode __1n )
# 165 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 166 "/home/claude/cfront-3/src/tree_walk.cpp"
size_t __1found ;

# 166 "/home/claude/cfront-3/src/tree_walk.cpp"
size_t __1replacement ;

# 166 "/home/claude/cfront-3/src/tree_walk.cpp"
__1found = 0 ;

# 166 "/home/claude/cfront-3/src/tree_walk.cpp"
__1replacement = 0 ;

# 168 "/home/claude/cfront-3/src/tree_walk.cpp"
action__4HashFUlT1Q2_4Hash13insert_actionRUlT4 ( ht__10patch_tree , ((unsigned long )__1n ), (unsigned long )0 , 0, (size_t *)(& __1found ), (size_t *)(& __1replacement )) ;
# 168 "/home/claude/cfront-3/src/tree_walk.cpp"

# 169 "/home/claude/cfront-3/src/tree_walk.cpp"
return (__1found ?(((struct node *)__1replacement )):__1n );
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

# 172 "/home/claude/cfront-3/src/tree_walk.cpp"
void patch_a_ktable__10patch_treeSFP6ktable (Pktab __1tbl )
# 173 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 174 "/home/claude/cfront-3/src/tree_walk.cpp"
__1tbl -> k_next__6ktable = (((struct ktable *)(((struct ktable *)probe__10patch_treeSFP4node ( (struct node *)__1tbl -> k_next__6ktable ) ))));
}

# 177 "/home/claude/cfront-3/src/tree_walk.cpp"
void patch_a_table__10patch_treeSFP5table (Ptable __1tbl )
# 178 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 179 "/home/claude/cfront-3/src/tree_walk.cpp"
{ { int __1i ;

# 179 "/home/claude/cfront-3/src/tree_walk.cpp"
__1i = 0 ;

# 179 "/home/claude/cfront-3/src/tree_walk.cpp"
for(;__1i < __1tbl -> size__5table ;__1i ++ ) 
# 180 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 181 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1tbl -> entries__5table [__1i ])
# 182 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 183 "/home/claude/cfront-3/src/tree_walk.cpp"
(__1tbl -> entries__5table [__1i ])= (((struct name *)(((struct name *)probe__10patch_treeSFP4node ( (struct
# 183 "/home/claude/cfront-3/src/tree_walk.cpp"
node *)(__1tbl -> entries__5table [__1i ])) ))));
}
}

# 187 "/home/claude/cfront-3/src/tree_walk.cpp"
__1tbl -> next__5table = (((struct table *)(((struct table *)probe__10patch_treeSFP4node ( (struct node *)__1tbl -> next__5table ) ))));

# 187 "/home/claude/cfront-3/src/tree_walk.cpp"
}

# 187 "/home/claude/cfront-3/src/tree_walk.cpp"
}
}

# 190 "/home/claude/cfront-3/src/tree_walk.cpp"
void patch_a_name__10patch_treeSFP4name (Pname __1n )
# 191 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 192 "/home/claude/cfront-3/src/tree_walk.cpp"
__1n -> n_ktable__4name = (((struct ktable *)(((struct ktable *)probe__10patch_treeSFP4node ( (struct node *)__1n -> n_ktable__4name ) ))));
}

# 112 "/home/claude/cfront-3/src/tree_walk.h"

# 1 ""

# 112 "/home/claude/cfront-3/src/tree_walk.h"

# 195 "/home/claude/cfront-3/src/tree_walk.cpp"
void patch__10patch_treeSFv (void )
# 196 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 197 "/home/claude/cfront-3/src/tree_walk.cpp"
while (head__10patch_tree )
# 198 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 199 "/home/claude/cfront-3/src/tree_walk.cpp"
if (head__10patch_tree -> node__10patch_tree -> base__4node == 149 )
# 200 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 201 "/home/claude/cfront-3/src/tree_walk.cpp"
patch_a_ktable__10patch_treeSFP6ktable ( ((struct ktable *)(((struct ktable *)head__10patch_tree ->
# 201 "/home/claude/cfront-3/src/tree_walk.cpp"
node__10patch_tree )))) ;
}
else if (head__10patch_tree -> node__10patch_tree -> base__4node == 142 )
# 204 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 205 "/home/claude/cfront-3/src/tree_walk.cpp"
patch_a_table__10patch_treeSFP5table ( ((struct table *)(((struct table *)head__10patch_tree -> node__10patch_tree )))) ;
}
else 
# 208 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 209 "/home/claude/cfront-3/src/tree_walk.cpp"
patch_a_name__10patch_treeSFP4name ( ((struct name *)(((struct name *)head__10patch_tree -> node__10patch_tree )))) ;
}

# 212 "/home/claude/cfront-3/src/tree_walk.cpp"
{ Ppatch_tree __2p ;

# 212 "/home/claude/cfront-3/src/tree_walk.cpp"
__2p = head__10patch_tree -> next__10patch_tree ;
( (head__10patch_tree ?(((void )(head__10patch_tree ?(((void )(((void )__dl__FPv ( (void *)head__10patch_tree ) )))):(((void )0 ))))):(((void )0 )))) ;
head__10patch_tree = __2p ;

# 214 "/home/claude/cfront-3/src/tree_walk.cpp"
}
}
}

# 98 "/home/claude/cfront-3/src/tree_walk.h"

# 46 "/home/claude/cfront-3/src/tree_walk.cpp"

# 219 "/home/claude/cfront-3/src/tree_walk.cpp"
int walk_tree__FR17tree_walk_controlRP4node (struct tree_walk_control *__1c , Pnode *__1n )
# 220 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 221 "/home/claude/cfront-3/src/tree_walk.cpp"
struct walker __1w ;

# 222 "/home/claude/cfront-3/src/tree_walk.cpp"
struct Hash *__0__X17 ;

# 222 "/home/claude/cfront-3/src/tree_walk.cpp"
struct Hash *__2__X20 ;

# 221 "/home/claude/cfront-3/src/tree_walk.cpp"
__ct__6walkerFRC17tree_walk_control ( & __1w , (const struct tree_walk_control *)__1c ) ;

# 223 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__X20 = ((*__1c )). nodes_seen_hash__17tree_walk_control ), ( ( (head__10patch_tree = 0 ), (ht__10patch_tree = __2__X20 )) , (((void )0 ))) )
# 223 "/home/claude/cfront-3/src/tree_walk.cpp"
;
{ int __1action ;

# 224 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = walk__6walkerFRP4node ( & __1w , __1n ) ;
patch__10patch_treeSFv ( ) ;
{ 
# 226 "/home/claude/cfront-3/src/tree_walk.cpp"
( (((void )( ((& __1w )-> made_ht__6walker ?(((void )( (__0__X17 = (& __1w )-> nodes_seen_hash__6walker ), ( (__0__X17 ?(((void
# 226 "/home/claude/cfront-3/src/tree_walk.cpp"
)( __dl__FPv ( (void *)__0__X17 -> tab__4Hash ) , (__0__X17 ?(((void )(((void )__dl__FPv ( (void *)__0__X17 ) )))):(((void )0 )))) )):(((void
# 226 "/home/claude/cfront-3/src/tree_walk.cpp"
)0 )))) ) )):(((void )0 ))), (((void )(((void )0 ))))) ))) ;

# 226 "/home/claude/cfront-3/src/tree_walk.cpp"
return __1action ;
} 
# 226 "/home/claude/cfront-3/src/tree_walk.cpp"
}
}

# 80 "/home/claude/incl-linux32/stdio.h"
extern int sprintf (char *, const char *,...);

# 232 "/home/claude/cfront-3/src/tree_walk.cpp"
void error__6walkerFPCcUl (register struct walker *__0this , const char *__1format , size_t __1v )
# 233 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 234 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__0this -> control__6walker . call_i_error__17tree_walk_control ){ 
# 235 "/home/claude/cfront-3/src/tree_walk.cpp"
char __2buf [1000];
# 235 "/home/claude/cfront-3/src/tree_walk.cpp"

# 239 "/home/claude/cfront-3/src/tree_walk.cpp"
sprintf ( (char *)__2buf , __1format , __1v ) ;
((*__0this -> control__6walker . i_error__17tree_walk_control ))( (int )'i' , (const char *)__2buf ) ;
}
}

# 9 "/home/claude/incl-linux32/malloc.h"
extern void free (void *);

# 246 "/home/claude/cfront-3/src/tree_walk.cpp"
void free_fetched__6walkerFPv (struct walker *__0this , void *__1addr )
# 247 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 248 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )
# 250 "/home/claude/cfront-3/src/tree_walk.cpp"
free ( __1addr ) ;
}

# 254 "/home/claude/cfront-3/src/tree_walk.cpp"
int fetch__6walkerFPvUlRPv (register struct walker *__0this , void *__1addr , size_t __1length , void **__1taddr )
# 255 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 256 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1err ;

# 258 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__0this -> control__6walker . fetcher__17tree_walk_control == null_tfp ){ 
# 259 "/home/claude/cfront-3/src/tree_walk.cpp"
((*__1taddr ))= __1addr ;
return 0 ;
}
else 
# 261 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 262 "/home/claude/cfront-3/src/tree_walk.cpp"
((*__1taddr ))= (((void *)(((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* __1length )) ))));
if (((*__1taddr ))== 0 ){ 
# 264 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"walker::fetch: failed to malloc %d bytes.", __1length ) ;
# 264 "/home/claude/cfront-3/src/tree_walk.cpp"

# 265 "/home/claude/cfront-3/src/tree_walk.cpp"
return 1 ;
}

# 268 "/home/claude/cfront-3/src/tree_walk.cpp"
__1err = ((*__0this -> control__6walker . fetcher__17tree_walk_control ))( __0this -> control__6walker . callback_info__17tree_walk_control , __1addr , __1length , 0 , (*__1taddr )) ;
if (__1err ){ 
# 270 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"walker::fetch: fetcher returned %d.", (unsigned long )__1err )
# 270 "/home/claude/cfront-3/src/tree_walk.cpp"
;
return 1 ;
}
}
error__FiPCc ( (int )'i' , (const char *)"fall off end of walker::fetch()") ;
return 0 ;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 249 "/home/claude/cfront-3/src/node_classes.h"
extern int classify_node__FP4nodeRi (Pnode , int *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 121 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_virt__6walkerFP4nodeP4virtRP4node (struct walker *__0this , Pnode , Pvirt , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 122 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_name_list__6walkerFP4nodeP9name_listRP4node (struct walker *__0this , Pnode , Plist , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 123 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_iline__6walkerFP4nodeP5ilineRP4node (struct walker *__0this , Pnode , Pin , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 108 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_gen__6walkerFP4nodeP3genRP4node (struct walker *__0this , Pnode , Pgen , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 109 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_tpdef__6walkerFP4nodeP4typeRP4node (struct walker *__0this , Pnode , Ptype , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 110 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_vec__6walkerFP4nodeP3vecRP4node (struct walker *__0this , Pnode , Pvec , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 111 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_ptr__6walkerFP4nodeP3ptrRP4node (struct walker *__0this , Pnode , Pptr , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 112 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_fct__6walkerFP4nodeP3fctRP4node (struct walker *__0this , Pnode , Pfct , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 113 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_table__6walkerFP4nodeP5tableRP4node (struct walker *__0this , Pnode , Ptable , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 114 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_ktable__6walkerFP4nodeP6ktableRP4node (struct walker *__0this , Pnode , Pktab , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 115 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_basetype__6walkerFP4nodeP8basetypeRP4node (struct walker *__0this , Pnode , Pbase , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 116 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_name__6walkerFP4nodeP4nameRP4node (struct walker *__0this , Pnode , Pname , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 117 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_expr__6walkerFP4nodeP4exprRP4node (struct walker *__0this , Pnode , Pexpr , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 118 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_stmt__6walkerFP4nodeP4stmtRP4node (struct walker *__0this , Pnode , Pstmt , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 119 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_enumdef__6walkerFP4nodeP7enumdefRP4node (struct walker *__0this , Pnode , Penum , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 120 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_classdef__6walkerFP4nodeP8classdefRP4node (struct walker *__0this , Pnode , Pclass , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 124 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_ia__6walkerFP4nodeP2iaRP4node (struct walker *__0this , Pnode , Pia , Pnode *);

# 94 "/home/claude/cfront-3/src/tree_walk.cpp"

# 125 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_baseclass__6walkerFP4nodeP6baseclRP4node (struct walker *__0this , Pnode , Pbcl , Pnode *);

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 304 "/home/claude/cfront-3/src/tree_walk.cpp"
int walk__6walkerFRP4node (register struct walker *__0this , Pnode *__1top )
# 305 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 306 "/home/claude/cfront-3/src/tree_walk.cpp"
Pnode __1replacement ;
int __1err ;
int __1class_err ;
int __1nclass ;
Pnode __1node ;

# 306 "/home/claude/cfront-3/src/tree_walk.cpp"
__1replacement = 0 ;

# 310 "/home/claude/cfront-3/src/tree_walk.cpp"
__1node = 0 ;

# 313 "/home/claude/cfront-3/src/tree_walk.cpp"
__0this -> orig_addr__6walker = ((*__1top ));

# 315 "/home/claude/cfront-3/src/tree_walk.cpp"
if (( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) ){ 
# 315 "/home/claude/cfront-3/src/tree_walk.cpp"
int __2__Xret00q2hiobkawcko ;

# 315 "/home/claude/cfront-3/src/tree_walk.cpp"
void *__2__Xt00q2hiobkawcko ;

# 316 "/home/claude/cfront-3/src/tree_walk.cpp"
if (( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct node )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 316 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) )
# 317 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int
# 317 "/home/claude/cfront-3/src/tree_walk.cpp"
)2;
}
else 
# 318 "/home/claude/cfront-3/src/tree_walk.cpp"
__1node = ((*__1top ));

# 325 "/home/claude/cfront-3/src/tree_walk.cpp"
__1nclass = classify_node__FP4nodeRi ( __1node , (int *)(& __1class_err )) ;

# 327 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1class_err ){ 
# 328 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"walker::walk: unknown node type %d.", (unsigned long )__1node ->
# 328 "/home/claude/cfront-3/src/tree_walk.cpp"
base__4node ) ;
free_fetched__6walkerFPv ( __0this , ((void *)__1node )) ;
__1err = 2;
goto Return ;
}

# 334 "/home/claude/cfront-3/src/tree_walk.cpp"
switch (__1nclass )
# 335 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 335 "/home/claude/cfront-3/src/tree_walk.cpp"
int __2__Xret00q2hiobkawcko ;

# 335 "/home/claude/cfront-3/src/tree_walk.cpp"
void *__2__Xt00q2hiobkawcko ;

# 336 "/home/claude/cfront-3/src/tree_walk.cpp"
default :
# 337 "/home/claude/cfront-3/src/tree_walk.cpp"
case 0:
# 338 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"walker::walk: unused node type %d.", (unsigned long )__1node ->
# 338 "/home/claude/cfront-3/src/tree_walk.cpp"
base__4node ) ;
__1err = 2;
goto Return ;

# 342 "/home/claude/cfront-3/src/tree_walk.cpp"
case 1:
# 343 "/home/claude/cfront-3/src/tree_walk.cpp"
break ;

# 345 "/home/claude/cfront-3/src/tree_walk.cpp"
case 2:
# 346 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct virt )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 346 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_virt__6walkerFP4nodeP4virtRP4node ( __0this , (*__1top ), ((struct virt *)(((struct virt *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 350 "/home/claude/cfront-3/src/tree_walk.cpp"
case 3:
# 351 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct name_list )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 351 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_name_list__6walkerFP4nodeP9name_listRP4node ( __0this , (*__1top ), ((struct name_list *)(((struct name_list *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 355 "/home/claude/cfront-3/src/tree_walk.cpp"
case 16:
# 356 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct iline )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 356 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_iline__6walkerFP4nodeP5ilineRP4node ( __0this , (*__1top ), ((struct iline *)(((struct iline *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 360 "/home/claude/cfront-3/src/tree_walk.cpp"
case 4:
# 361 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct gen )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 361 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_gen__6walkerFP4nodeP3genRP4node ( __0this , (*__1top ), ((struct gen *)(((struct gen *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 365 "/home/claude/cfront-3/src/tree_walk.cpp"
case 18:
# 366 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct type )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 366 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_tpdef__6walkerFP4nodeP4typeRP4node ( __0this , (*__1top ), ((struct type *)(((struct type *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 370 "/home/claude/cfront-3/src/tree_walk.cpp"
case 5:
# 371 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct vec )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 371 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_vec__6walkerFP4nodeP3vecRP4node ( __0this , (*__1top ), ((struct vec *)(((struct vec *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 375 "/home/claude/cfront-3/src/tree_walk.cpp"
case 6:
# 376 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct ptr )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 376 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_ptr__6walkerFP4nodeP3ptrRP4node ( __0this , (*__1top ), ((struct ptr *)(((struct ptr *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 380 "/home/claude/cfront-3/src/tree_walk.cpp"
case 7:
# 381 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct fct )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 381 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_fct__6walkerFP4nodeP3fctRP4node ( __0this , (*__1top ), ((struct fct *)(((struct fct *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 385 "/home/claude/cfront-3/src/tree_walk.cpp"
case 8:
# 386 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct table )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 386 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_table__6walkerFP4nodeP5tableRP4node ( __0this , (*__1top ), ((struct table *)(((struct table *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 390 "/home/claude/cfront-3/src/tree_walk.cpp"
case 19:
# 391 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct ktable )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 391 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_ktable__6walkerFP4nodeP6ktableRP4node ( __0this , (*__1top ), ((struct ktable *)(((struct ktable *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 395 "/home/claude/cfront-3/src/tree_walk.cpp"
case 9:
# 396 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct basetype )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 396 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_basetype__6walkerFP4nodeP8basetypeRP4node ( __0this , (*__1top ), ((struct basetype *)(((struct basetype *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 400 "/home/claude/cfront-3/src/tree_walk.cpp"
case 10:
# 401 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct name )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 401 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_name__6walkerFP4nodeP4nameRP4node ( __0this , (*__1top ), ((struct name *)(((struct name *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 405 "/home/claude/cfront-3/src/tree_walk.cpp"
case 11:
# 406 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct expr )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 406 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_expr__6walkerFP4nodeP4exprRP4node ( __0this , (*__1top ), ((struct expr *)(((struct expr *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 410 "/home/claude/cfront-3/src/tree_walk.cpp"
case 12:
# 411 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct stmt )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 411 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_stmt__6walkerFP4nodeP4stmtRP4node ( __0this , (*__1top ), ((struct stmt *)(((struct stmt *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 415 "/home/claude/cfront-3/src/tree_walk.cpp"
case 13:
# 416 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct enumdef )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 416 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_enumdef__6walkerFP4nodeP7enumdefRP4node ( __0this , (*__1top ), ((struct enumdef *)(((struct enumdef *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 420 "/home/claude/cfront-3/src/tree_walk.cpp"
case 14:
# 421 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct classdef )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 421 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_classdef__6walkerFP4nodeP8classdefRP4node ( __0this , (*__1top ), ((struct classdef *)(((struct classdef *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 425 "/home/claude/cfront-3/src/tree_walk.cpp"
case 17:
# 426 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct ia )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 426 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_ia__6walkerFP4nodeP2iaRP4node ( __0this , (*__1top ), ((struct ia *)(((struct ia *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 430 "/home/claude/cfront-3/src/tree_walk.cpp"
case 15:
# 431 "/home/claude/cfront-3/src/tree_walk.cpp"
( (__2__Xret00q2hiobkawcko = fetch__6walkerFPvUlRPv ( __0this , (((void *)((*__1top )))), (sizeof (struct basecl )), (void **)(& __2__Xt00q2hiobkawcko )) ),
# 431 "/home/claude/cfront-3/src/tree_walk.cpp"
( ((! __2__Xret00q2hiobkawcko )?( (((*((Pnode *)(& __1node ))))= (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko ))))), 0 ) :0 ), __2__Xret00q2hiobkawcko ) ) ;
__1err = a_baseclass__6walkerFP4nodeP6baseclRP4node ( __0this , (*__1top ), ((struct basecl *)(((struct basecl *)__1node ))), (Pnode *)(& __1replacement )) ;
break ;

# 435 "/home/claude/cfront-3/src/tree_walk.cpp"
}

# 437 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1replacement ){ 
# 438 "/home/claude/cfront-3/src/tree_walk.cpp"
if (( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) ){ 
# 440 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"walker::walk: Attempt to replace tree in cross-address space mode.",
# 440 "/home/claude/cfront-3/src/tree_walk.cpp"
(unsigned long )0 ) ;
__1err = 2;
}
else ((*__1top ))= __1replacement ;
}

# 446 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__0this -> control__6walker . post_action_proc__17tree_walk_control && (__1err != 2)){ 
# 447 "/home/claude/cfront-3/src/tree_walk.cpp"
int __2post_err ;
Pnode *__2post_repl ;

# 448 "/home/claude/cfront-3/src/tree_walk.cpp"
__2post_repl = (& __1node );

# 451 "/home/claude/cfront-3/src/tree_walk.cpp"
((*__0this -> control__6walker . post_action_proc__17tree_walk_control ))( __2post_repl , __1nclass , __0this -> control__6walker . callback_info__17tree_walk_control , (int *)(& __2post_err ), __0this -> depth__6walker , __0this ->
# 451 "/home/claude/cfront-3/src/tree_walk.cpp"
orig_addr__6walker , (struct tree_walk_tree *)__0this -> cur_tree__6walker ) ;
if (__2post_err != 0)__1err = __2post_err ;
if (((*__2post_repl ))!= __1node ){ 
# 454 "/home/claude/cfront-3/src/tree_walk.cpp"
if (( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) ){ 
# 456 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char
# 456 "/home/claude/cfront-3/src/tree_walk.cpp"
*)"walker::walk: Attempt to replace tree in cross-address space mode.", (unsigned long )0 ) ;
__1err = 2;
}
else ((*__1top ))= ((*__2post_repl ));
}
}

# 463 "/home/claude/cfront-3/src/tree_walk.cpp"
free_fetched__6walkerFPv ( __0this , ((void *)__1node )) ;

# 465 "/home/claude/cfront-3/src/tree_walk.cpp"
Return :
# 466 "/home/claude/cfront-3/src/tree_walk.cpp"
return __1err ;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 480 "/home/claude/cfront-3/src/tree_walk.cpp"
int pre_act_on_node__6walkerFP4node10node_classT1RP4node (register struct walker *__0this , Pnode __1node , int __1nc , 
# 481 "/home/claude/cfront-3/src/tree_walk.cpp"
Pnode __1node_copy , Pnode *__1replacement )
# 482 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 486 "/home/claude/cfront-3/src/tree_walk.cpp"
size_t __1found ;
size_t __1old_node ;
int __1action ;
Pnode __1new_node ;
int __1register_in_hash ;

# 490 "/home/claude/cfront-3/src/tree_walk.cpp"
__1register_in_hash = 1 ;

# 492 "/home/claude/cfront-3/src/tree_walk.cpp"
action__4HashFUlT1Q2_4Hash13insert_actionRUlT4 ( __0this -> nodes_seen_hash__6walker , ((unsigned long )__1node ), (unsigned long )0 , 0, (size_t *)(& __1found ), (size_t *)(& __1old_node ))
# 492 "/home/claude/cfront-3/src/tree_walk.cpp"
;

# 494 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1found ){ 
# 495 "/home/claude/cfront-3/src/tree_walk.cpp"
__1new_node = (((struct node *)__1old_node ));
if (__1new_node != __1node )((*__1replacement ))= __1new_node ;
return (int )1;
}

# 502 "/home/claude/cfront-3/src/tree_walk.cpp"
__1new_node = ((( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) && __1node_copy )?__1node_copy :__1node );

# 506 "/home/claude/cfront-3/src/tree_walk.cpp"
((*__0this -> control__6walker . action_proc__17tree_walk_control ))( (Pnode *)(& __1new_node ), __1nc , __0this -> control__6walker . callback_info__17tree_walk_control , (int *)(& __1action ), __0this -> depth__6walker ,
# 506 "/home/claude/cfront-3/src/tree_walk.cpp"
__0this -> orig_addr__6walker , (struct tree_walk_tree *)__0this -> cur_tree__6walker , (int *)(& __1register_in_hash )) ;

# 508 "/home/claude/cfront-3/src/tree_walk.cpp"
{ size_t __1zero1 ;

# 508 "/home/claude/cfront-3/src/tree_walk.cpp"
size_t __1zero2 ;

# 508 "/home/claude/cfront-3/src/tree_walk.cpp"
__1zero1 = 0 ;

# 508 "/home/claude/cfront-3/src/tree_walk.cpp"
__1zero2 = 0 ;
if (((__1action != 2)&& (! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) ))&& (__1new_node != __1node )){ 
# 510 "/home/claude/cfront-3/src/tree_walk.cpp"
((*__1replacement ))= __1new_node ;
# 510 "/home/claude/cfront-3/src/tree_walk.cpp"

# 511 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1register_in_hash )
# 514 "/home/claude/cfront-3/src/tree_walk.cpp"
action__4HashFUlT1Q2_4Hash13insert_actionRUlT4 ( __0this -> nodes_seen_hash__6walker , ((unsigned long )__1node ), ((unsigned long )__1new_node ), 1, (size_t *)(& __1zero1 ), (size_t *)(&
# 514 "/home/claude/cfront-3/src/tree_walk.cpp"
__1zero2 )) ;
}
else { 
# 517 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1register_in_hash )
# 518 "/home/claude/cfront-3/src/tree_walk.cpp"
action__4HashFUlT1Q2_4Hash13insert_actionRUlT4 ( __0this -> nodes_seen_hash__6walker , ((unsigned long )__1node ), ((unsigned long )__1node ), 1, (size_t *)(&
# 518 "/home/claude/cfront-3/src/tree_walk.cpp"
__1zero1 ), (size_t *)(& __1zero2 )) ;
}
return __1action ;

# 520 "/home/claude/cfront-3/src/tree_walk.cpp"
}
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 62 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 523 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_ktable__6walkerFP4nodeP6ktableRP4node (register struct walker *__0this , Pnode __1ta , Pktab __1t , Pnode *__1replacement )
# 524 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 525 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 526 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptable *__2__X21 ;

# 526 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X22 ;

# 526 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 19, ((struct node *)(((struct node *)__1t ))), __1replacement ) ;
if (__1action != 0)return __1action ;

# 529 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 530 "/home/claude/cfront-3/src/tree_walk.cpp"
__1t = (((struct ktable *)(((struct ktable *)((*__1replacement ))))));

# 532 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X21 = (& __1t -> __O1__6ktable.k_t )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X21 )) ) ) ;
# 532 "/home/claude/cfront-3/src/tree_walk.cpp"

# 533 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 535 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X22 = (& __1t -> k_name__6ktable )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X22 )) ) ) ;
# 535 "/home/claude/cfront-3/src/tree_walk.cpp"

# 536 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 540 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 72 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 544 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_table__6walkerFP4nodeP5tableRP4node (register struct walker *__0this , Pnode __1ta , Ptable __1t , Pnode *__1replacement )
# 545 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 548 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 8, ((struct node *)(((struct node *)__1t ))), __1replacement ) ;
if (__1action != 0)return __1action ;

# 552 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 553 "/home/claude/cfront-3/src/tree_walk.cpp"
__1t = (((struct table *)(((struct table *)((*__1replacement ))))));

# 555 "/home/claude/cfront-3/src/tree_walk.cpp"
{ { int __1i ;

# 556 "/home/claude/cfront-3/src/tree_walk.cpp"
Pstmt *__2__X24 ;

# 556 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X25 ;

# 555 "/home/claude/cfront-3/src/tree_walk.cpp"
__1i = 0 ;

# 555 "/home/claude/cfront-3/src/tree_walk.cpp"
for(;__1i < __1t -> size__5table ;__1i ++ ) 
# 556 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 557 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((__1t -> entries__5table [__1i ])&& ((__1t -> entries__5table [__1i ])-> base__4node == 123 ))
# 558 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 558 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X23 ;

# 559 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X23 = (& (__1t -> entries__5table [__1i ]))), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X23 )) ) ) ;
# 559 "/home/claude/cfront-3/src/tree_walk.cpp"

# 560 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;
}
}

# 564 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X24 = (& __1t -> real_block__5table )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X24 )) ) ) ;
# 564 "/home/claude/cfront-3/src/tree_walk.cpp"

# 565 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 567 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X25 = (& __1t -> t_name__5table )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X25 )) ) ) ;
# 567 "/home/claude/cfront-3/src/tree_walk.cpp"

# 568 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 572 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;

# 572 "/home/claude/cfront-3/src/tree_walk.cpp"
}

# 572 "/home/claude/cfront-3/src/tree_walk.cpp"
}
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 78 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 66 "/home/claude/cfront-3/src/tree_walk.cpp"

# 575 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_enumdef__6walkerFP4nodeP7enumdefRP4node (register struct walker *__0this , Pnode __1ta , Penum __1e , Pnode *__1replacement )
# 576 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 577 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 578 "/home/claude/cfront-3/src/tree_walk.cpp"
Pclass *__2__X26 ;

# 578 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X27 ;

# 578 "/home/claude/cfront-3/src/tree_walk.cpp"
Pbase *__2__X28 ;

# 577 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 13, ((struct node *)(((struct node *)__1e ))), __1replacement ) ;

# 579 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 581 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 582 "/home/claude/cfront-3/src/tree_walk.cpp"
__1e = (((struct enumdef *)(((struct enumdef *)((*__1replacement ))))));

# 584 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X26 = (& __1e -> in_class__4type )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X26 )) ) ) ;
# 584 "/home/claude/cfront-3/src/tree_walk.cpp"

# 585 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 587 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X27 = (& __1e -> mem__7enumdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X27 )) ) ) ;
# 587 "/home/claude/cfront-3/src/tree_walk.cpp"

# 588 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 590 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X28 = (& __1e -> e_type__7enumdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X28 )) ) ) ;
# 590 "/home/claude/cfront-3/src/tree_walk.cpp"

# 592 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 381 "/home/claude/cfront-3/src/cfront.h"
struct velem {	/* sizeof velem == 16 */
Pname n__5velem ;
int offset__5velem ;
};

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 78 "/home/claude/cfront-3/src/tree_walk.cpp"

# 595 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_virt__6walkerFP4nodeP4virtRP4node (register struct walker *__0this , Pnode __1ta , Pvirt __1v , Pnode *__1replacement )
# 596 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 599 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1nx ;
int __1action ;

# 609 "/home/claude/cfront-3/src/tree_walk.cpp"
struct velem *__1v_virt_init ;

# 610 "/home/claude/cfront-3/src/tree_walk.cpp"
Pclass *__2__X30 ;

# 600 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 13, ((struct node *)(((struct node *)__1v ))), __1replacement ) ;

# 602 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 604 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 605 "/home/claude/cfront-3/src/tree_walk.cpp"
__1v = (((struct virt *)(((struct virt *)((*__1replacement ))))));

# 609 "/home/claude/cfront-3/src/tree_walk.cpp"
;

# 611 "/home/claude/cfront-3/src/tree_walk.cpp"
if (( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) ){ 
# 612 "/home/claude/cfront-3/src/tree_walk.cpp"
void *__2t ;
fetch__6walkerFPvUlRPv ( __0this , ((void *)__1v -> virt_init__4virt ), __1v -> n_init__4virt * (sizeof (struct velem )), (void **)(& __2t )) ;
# 613 "/home/claude/cfront-3/src/tree_walk.cpp"

# 614 "/home/claude/cfront-3/src/tree_walk.cpp"
__1v_virt_init = (((struct velem *)(((struct velem *)__2t ))));
}
else __1v_virt_init = __1v -> virt_init__4virt ;

# 618 "/home/claude/cfront-3/src/tree_walk.cpp"
for(__1nx = 0 ;__1nx < __1v -> n_init__4virt ;__1nx ++ ) { 
# 618 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X29 ;

# 619 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X29 = (& (__1v_virt_init [__1nx ]). n__5velem )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X29 )) ) ) ;
# 619 "/home/claude/cfront-3/src/tree_walk.cpp"

# 620 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;
}

# 623 "/home/claude/cfront-3/src/tree_walk.cpp"
if (( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )free_fetched__6walkerFPv ( __0this , ((void *)__1v_virt_init )) ;

# 625 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X30 = (& __1v -> vclass__4virt )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X30 )) ) ) ;
# 625 "/home/claude/cfront-3/src/tree_walk.cpp"

# 627 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 88 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 62 "/home/claude/cfront-3/src/tree_walk.cpp"

# 64 "/home/claude/cfront-3/src/tree_walk.cpp"

# 82 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 78 "/home/claude/cfront-3/src/tree_walk.cpp"

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 80 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 630 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_classdef__6walkerFP4nodeP8classdefRP4node (register struct walker *__0this , Pnode __1ta , Pclass __1c , Pnode *__1replacement )
# 631 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 634 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Pbcl *__2__X31 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X32 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptable *__2__X33 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Pktab *__2__X34 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Plist *__2__X35 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X36 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Pclass *__2__X37 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X38 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Pvirt *__2__X39 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X40 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X41 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X42 ;

# 635 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X43 ;

# 634 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 14, ((struct node *)(((struct node *)__1c ))), __1replacement ) ;

# 636 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 638 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 639 "/home/claude/cfront-3/src/tree_walk.cpp"
__1c = (((struct classdef *)(((struct classdef *)((*__1replacement ))))));

# 641 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X31 = (& __1c -> baselist__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X31 )) ) ) ;
# 641 "/home/claude/cfront-3/src/tree_walk.cpp"

# 642 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 644 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X32 = (& __1c -> mem_list__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X32 )) ) ) ;
# 644 "/home/claude/cfront-3/src/tree_walk.cpp"

# 645 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 647 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X33 = (& __1c -> memtbl__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X33 )) ) ) ;
# 647 "/home/claude/cfront-3/src/tree_walk.cpp"

# 648 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 650 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X34 = (& __1c -> k_tbl__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X34 )) ) ) ;
# 650 "/home/claude/cfront-3/src/tree_walk.cpp"

# 651 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 653 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X35 = (& __1c -> friend_list__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X35 )) ) ) ;
# 653 "/home/claude/cfront-3/src/tree_walk.cpp"

# 654 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 656 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X36 = (& __1c -> pubdef__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X36 )) ) ) ;
# 656 "/home/claude/cfront-3/src/tree_walk.cpp"

# 657 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 662 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X37 = (& __1c -> in_class__4type )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X37 )) ) ) ;
# 662 "/home/claude/cfront-3/src/tree_walk.cpp"

# 663 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 665 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X38 = (& __1c -> this_type__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X38 )) ) ) ;
# 665 "/home/claude/cfront-3/src/tree_walk.cpp"

# 666 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 668 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X39 = (& __1c -> virt_list__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X39 )) ) ) ;
# 668 "/home/claude/cfront-3/src/tree_walk.cpp"

# 669 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 671 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X40 = (& __1c -> c_ctor__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X40 )) ) ) ;
# 671 "/home/claude/cfront-3/src/tree_walk.cpp"

# 672 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;
__1action = ( (__2__X41 = (& __1c -> c_dtor__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X41 )) ) ) ;
# 673 "/home/claude/cfront-3/src/tree_walk.cpp"

# 674 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;
__1action = ( (__2__X42 = (& __1c -> c_itor__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X42 )) ) ) ;
# 675 "/home/claude/cfront-3/src/tree_walk.cpp"

# 676 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 678 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X43 = (& __1c -> conv__8classdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X43 )) ) ) ;
# 678 "/home/claude/cfront-3/src/tree_walk.cpp"

# 679 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 683 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 62 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 591 "/home/claude/cfront-3/src/cfront.h"
int discriminator__8basetypeFi (struct basetype *__0this , int );

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 686 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_basetype__6walkerFP4nodeP8basetypeRP4node (register struct walker *__0this , Pnode __1ta , Pbase __1b , Pnode *__1replacement )
# 687 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 688 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1derr ;

# 690 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 691 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X44 ;

# 691 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptable *__2__X45 ;

# 691 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X46 ;

# 690 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 9, ((struct node *)(((struct node *)__1b ))), __1replacement ) ;

# 692 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 694 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 695 "/home/claude/cfront-3/src/tree_walk.cpp"
__1b = (((struct basetype *)(((struct basetype *)((*__1replacement ))))));

# 697 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X44 = (& __1b -> b_name__8basetype )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X44 )) ) ) ;
# 697 "/home/claude/cfront-3/src/tree_walk.cpp"

# 698 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 700 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X45 = (& __1b -> b_table__8basetype )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X45 )) ) ) ;
# 700 "/home/claude/cfront-3/src/tree_walk.cpp"

# 701 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 706 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X46 = (& __1b -> b_xname__8basetype )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X46 )) ) ) ;
# 706 "/home/claude/cfront-3/src/tree_walk.cpp"

# 707 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 709 "/home/claude/cfront-3/src/tree_walk.cpp"
switch (__1derr = discriminator__8basetypeFi ( __1b , 0 ) ){ 
# 709 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X47 ;

# 710 "/home/claude/cfront-3/src/tree_walk.cpp"
case 0 :break ;
case 1 :
# 712 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X47 = (& __1b -> __O1__8basetype.b_fieldtype )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X47 )) ) )
# 712 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 2 :break ;
default :
# 717 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"a_basetype: discrim error %d.", (unsigned long )__1derr ) ;
# 717 "/home/claude/cfront-3/src/tree_walk.cpp"

# 718 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )2;
}

# 721 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 78 "/home/claude/cfront-3/src/tree_walk.cpp"

# 74 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 70 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 724 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_fct__6walkerFP4nodeP3fctRP4node (register struct walker *__0this , Pnode __1ta , Pfct __1f , Pnode *__1replacement )
# 725 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 727 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 728 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X48 ;

# 728 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X49 ;

# 728 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X50 ;

# 728 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X51 ;

# 728 "/home/claude/cfront-3/src/tree_walk.cpp"
Pclass *__2__X52 ;

# 728 "/home/claude/cfront-3/src/tree_walk.cpp"
Pblock *__2__X53 ;

# 728 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X54 ;

# 728 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X55 ;

# 728 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X56 ;

# 728 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X57 ;

# 727 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 7, ((struct node *)(((struct node *)__1f ))), __1replacement ) ;

# 729 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 731 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 732 "/home/claude/cfront-3/src/tree_walk.cpp"
__1f = (((struct fct *)(((struct fct *)((*__1replacement ))))));

# 734 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X48 = (& __1f -> returns__3fct )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X48 )) ) ) ;
# 734 "/home/claude/cfront-3/src/tree_walk.cpp"

# 735 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 737 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X49 = (& __1f -> argtype__3fct )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X49 )) ) ) ;
# 737 "/home/claude/cfront-3/src/tree_walk.cpp"

# 738 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 740 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X50 = (& __1f -> s_returns__3fct )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X50 )) ) ) ;
# 740 "/home/claude/cfront-3/src/tree_walk.cpp"

# 741 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 743 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X51 = (& __1f -> f_this__3fct )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X51 )) ) ) ;
# 743 "/home/claude/cfront-3/src/tree_walk.cpp"

# 744 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 746 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X52 = (& __1f -> memof__3fct )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X52 )) ) ) ;
# 746 "/home/claude/cfront-3/src/tree_walk.cpp"

# 747 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 749 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X53 = (& __1f -> body__3fct )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X53 )) ) ) ;
# 749 "/home/claude/cfront-3/src/tree_walk.cpp"

# 750 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 752 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X54 = (& __1f -> f_init__3fct )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X54 )) ) ) ;
# 752 "/home/claude/cfront-3/src/tree_walk.cpp"

# 753 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 755 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X55 = (& __1f -> f_expr__3fct )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X55 )) ) ) ;
# 755 "/home/claude/cfront-3/src/tree_walk.cpp"

# 756 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 761 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X56 = (& __1f -> f_result__3fct )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X56 )) ) ) ;
# 761 "/home/claude/cfront-3/src/tree_walk.cpp"

# 762 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 764 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X57 = (& __1f -> f_args__3fct )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X57 )) ) ) ;
# 764 "/home/claude/cfront-3/src/tree_walk.cpp"

# 765 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 767 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 82 "/home/claude/cfront-3/src/tree_walk.cpp"

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 82 "/home/claude/cfront-3/src/tree_walk.cpp"

# 770 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_name_list__6walkerFP4nodeP9name_listRP4node (register struct walker *__0this , Pnode __1ta , Plist __1l , Pnode *__1replacement )
# 771 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 773 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1cl_error ;
int __1action ;

# 775 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X59 ;

# 775 "/home/claude/cfront-3/src/tree_walk.cpp"
Plist *__2__X60 ;

# 774 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 3, ((struct node *)(((struct node *)__1l ))), __1replacement ) ;

# 776 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 1){ 
# 777 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 778 "/home/claude/cfront-3/src/tree_walk.cpp"
__1l = (((struct name_list *)(((struct
# 778 "/home/claude/cfront-3/src/tree_walk.cpp"
name_list *)((*__1replacement ))))));
__1cl_error = 0 ;
if ((classify_node__FP4nodeRi ( ((struct node *)(((struct node *)__1l ))), (int *)(& __1cl_error )) == 3)&& (! __1cl_error )){ 
# 780 "/home/claude/cfront-3/src/tree_walk.cpp"
Plist *__2__X58 ;

# 781 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X58 = (& __1l -> l__9name_list )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X58 )) ) ) ;
# 781 "/home/claude/cfront-3/src/tree_walk.cpp"

# 782 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;
}
}

# 786 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 788 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 789 "/home/claude/cfront-3/src/tree_walk.cpp"
__1l = (((struct name_list *)(((struct name_list *)((*__1replacement ))))));

# 791 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X59 = (& __1l -> f__9name_list )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X59 )) ) ) ;
# 791 "/home/claude/cfront-3/src/tree_walk.cpp"

# 792 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 794 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X60 = (& __1l -> l__9name_list )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X60 )) ) ) ;
# 794 "/home/claude/cfront-3/src/tree_walk.cpp"

# 795 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 797 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 78 "/home/claude/cfront-3/src/tree_walk.cpp"

# 800 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_tpdef__6walkerFP4nodeP4typeRP4node (register struct walker *__0this , Pnode __1ta , Ptype __1t , Pnode *__1replacement )
# 801 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 802 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 803 "/home/claude/cfront-3/src/tree_walk.cpp"
Pclass *__2__X61 ;

# 802 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 18, ((struct node *)(((struct node *)__1t ))), __1replacement ) ;

# 804 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 806 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 807 "/home/claude/cfront-3/src/tree_walk.cpp"
__1t = (((struct type *)(((struct type *)((*__1replacement ))))));

# 809 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X61 = (& __1t -> in_class__4type )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X61 )) ) ) ;
# 809 "/home/claude/cfront-3/src/tree_walk.cpp"

# 810 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 812 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 82 "/home/claude/cfront-3/src/tree_walk.cpp"

# 815 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_gen__6walkerFP4nodeP3genRP4node (register struct walker *__0this , Pnode __1ta , Pgen __1g , Pnode *__1replacement )
# 816 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 818 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 819 "/home/claude/cfront-3/src/tree_walk.cpp"
Plist *__2__X62 ;

# 818 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 4, ((struct node *)(((struct node *)__1g ))), __1replacement ) ;

# 820 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 822 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 823 "/home/claude/cfront-3/src/tree_walk.cpp"
__1g = (((struct gen *)(((struct gen *)((*__1replacement ))))));

# 825 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X62 = (& __1g -> fct_list__3gen )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X62 )) ) ) ;
# 825 "/home/claude/cfront-3/src/tree_walk.cpp"

# 826 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 828 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 70 "/home/claude/cfront-3/src/tree_walk.cpp"

# 831 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_vec__6walkerFP4nodeP3vecRP4node (register struct walker *__0this , Pnode __1ta , Pvec __1v , Pnode *__1replacement )
# 832 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 834 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 835 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X63 ;

# 835 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X64 ;

# 834 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 5, ((struct node *)(((struct node *)__1v ))), __1replacement ) ;

# 836 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 838 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 839 "/home/claude/cfront-3/src/tree_walk.cpp"
__1v = (((struct vec *)(((struct vec *)((*__1replacement ))))));

# 841 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X63 = (& __1v -> typ__5pvtyp )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X63 )) ) ) ;
# 841 "/home/claude/cfront-3/src/tree_walk.cpp"

# 842 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 844 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X64 = (& __1v -> dim__3vec )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X64 )) ) ) ;
# 844 "/home/claude/cfront-3/src/tree_walk.cpp"

# 845 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 847 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 78 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 850 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_ptr__6walkerFP4nodeP3ptrRP4node (register struct walker *__0this , Pnode __1ta , Pptr __1p , Pnode *__1replacement )
# 851 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 853 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 854 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X65 ;

# 854 "/home/claude/cfront-3/src/tree_walk.cpp"
Pclass *__2__X66 ;

# 854 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X67 ;

# 853 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 6, ((struct node *)(((struct node *)__1p ))), __1replacement ) ;

# 855 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 857 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 858 "/home/claude/cfront-3/src/tree_walk.cpp"
__1p = (((struct ptr *)(((struct ptr *)((*__1replacement ))))));

# 860 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X65 = (& __1p -> typ__5pvtyp )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X65 )) ) ) ;
# 860 "/home/claude/cfront-3/src/tree_walk.cpp"

# 861 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 863 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X66 = (& __1p -> memof__3ptr )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X66 )) ) ) ;
# 863 "/home/claude/cfront-3/src/tree_walk.cpp"

# 864 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 866 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X67 = (& __1p -> ptname__3ptr )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X67 )) ) ) ;
# 866 "/home/claude/cfront-3/src/tree_walk.cpp"

# 867 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 869 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 816 "/home/claude/cfront-3/src/cfront.h"
int discriminator__4exprFi (struct expr *__0this , int );

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 70 "/home/claude/cfront-3/src/tree_walk.cpp"

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 70 "/home/claude/cfront-3/src/tree_walk.cpp"

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 62 "/home/claude/cfront-3/src/tree_walk.cpp"

# 84 "/home/claude/cfront-3/src/tree_walk.cpp"

# 873 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_expr_guts__6walkerFP4expr (register struct walker *__0this , Pexpr __1e )
# 874 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 875 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1derr ;
int __1action ;

# 878 "/home/claude/cfront-3/src/tree_walk.cpp"
switch (__1derr = discriminator__4exprFi ( __1e , 0 ) ){ 
# 878 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X68 ;

# 879 "/home/claude/cfront-3/src/tree_walk.cpp"
case 1 :
# 880 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X68 = (& __1e -> __O1__4expr.tp )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X68 )) ) )
# 880 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 0 :
# 884 "/home/claude/cfront-3/src/tree_walk.cpp"
break ;
default :
# 886 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"a_expr: discrim error %d on union 0.", (unsigned long )__1derr ) ;
# 886 "/home/claude/cfront-3/src/tree_walk.cpp"

# 887 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )2;
}

# 890 "/home/claude/cfront-3/src/tree_walk.cpp"
switch (__1derr = discriminator__4exprFi ( __1e , 1 ) ){ 
# 890 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X69 ;

# 891 "/home/claude/cfront-3/src/tree_walk.cpp"
case 0 :
# 892 "/home/claude/cfront-3/src/tree_walk.cpp"
break ;
default :
# 894 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"a_expr: discrim error %d on union 1.", (unsigned long )__1derr ) ;
# 894 "/home/claude/cfront-3/src/tree_walk.cpp"

# 895 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )2;
case 1 :
# 897 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X69 = (& __1e -> __O2__4expr.e1 )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X69 )) ) )
# 897 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 2 :
# 901 "/home/claude/cfront-3/src/tree_walk.cpp"
break ;
case 3 :
# 903 "/home/claude/cfront-3/src/tree_walk.cpp"
break ;
}

# 906 "/home/claude/cfront-3/src/tree_walk.cpp"
switch (__1derr = discriminator__4exprFi ( __1e , 2 ) ){ 
# 906 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X71 ;

# 906 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X72 ;

# 907 "/home/claude/cfront-3/src/tree_walk.cpp"
case 0 :
# 908 "/home/claude/cfront-3/src/tree_walk.cpp"
break ;
default :
# 910 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"a_expr: discrim error %d on union 2.", (unsigned long )__1derr ) ;
# 910 "/home/claude/cfront-3/src/tree_walk.cpp"

# 911 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )2;
case 1 :
# 915 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1e -> base__4node != 140 ){ 
# 915 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X70 ;

# 916 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X70 = (& __1e -> __O3__4expr.e2 )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X70 )) ) ) ;
# 916 "/home/claude/cfront-3/src/tree_walk.cpp"

# 917 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;
}
break ;
case 2 :
# 921 "/home/claude/cfront-3/src/tree_walk.cpp"
break ;
case 3 :
# 923 "/home/claude/cfront-3/src/tree_walk.cpp"
break ;
case 4 :
# 925 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X71 = (& __1e -> __O3__4expr.n_initializer )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X71 )) ) )
# 925 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 5 :
# 929 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X72 = (& __1e -> __O3__4expr.tpdef )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X72 )) ) )
# 929 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
}

# 934 "/home/claude/cfront-3/src/tree_walk.cpp"
switch (__1derr = discriminator__4exprFi ( __1e , 3 ) ){ 
# 934 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X73 ;

# 934 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X74 ;

# 934 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X75 ;

# 934 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X76 ;

# 934 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X77 ;

# 934 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptable *__2__X78 ;

# 934 "/home/claude/cfront-3/src/tree_walk.cpp"
Pin *__2__X79 ;

# 935 "/home/claude/cfront-3/src/tree_walk.cpp"
case 0 :
# 936 "/home/claude/cfront-3/src/tree_walk.cpp"
break ;
default :
# 938 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"a_expr: discrim error %d on union 3.", (unsigned long )__1derr ) ;
# 938 "/home/claude/cfront-3/src/tree_walk.cpp"

# 939 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )2;
case 1 :
# 941 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X73 = (& __1e -> __O4__4expr.tp2 )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X73 )) ) )
# 941 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 2 :
# 945 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X74 = (& __1e -> __O4__4expr.fct_name )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X74 )) ) )
# 945 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 3 :
# 949 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X75 = (& __1e -> __O4__4expr.cond )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X75 )) ) )
# 949 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 4 :
# 953 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X76 = (& __1e -> __O4__4expr.mem )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X76 )) ) )
# 953 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 5 :
# 957 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X77 = (& __1e -> __O4__4expr.as_type )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X77 )) ) )
# 957 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 6 :
# 961 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X78 = (& __1e -> __O4__4expr.n_table )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X78 )) ) )
# 961 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 7 :
# 965 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X79 = (& __1e -> __O4__4expr.il )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X79 )) ) )
# 965 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
}
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 70 "/home/claude/cfront-3/src/tree_walk.cpp"

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 70 "/home/claude/cfront-3/src/tree_walk.cpp"

# 973 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_expr__6walkerFP4nodeP4exprRP4node (register struct walker *__0this , Pnode __1ta , Pexpr __1e , Pnode *__1replacement )
# 974 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 975 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 976 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X81 ;

# 975 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 11, ((struct node *)(((struct node *)__1e ))), __1replacement ) ;

# 977 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 1){ 
# 978 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 979 "/home/claude/cfront-3/src/tree_walk.cpp"
__1e = (((struct expr *)(((struct
# 979 "/home/claude/cfront-3/src/tree_walk.cpp"
expr *)((*__1replacement ))))));

# 981 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1e -> base__4node == 140 ){ 
# 981 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X80 ;

# 982 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X80 = (& __1e -> __O3__4expr.e2 )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X80 )) ) ) ;
# 982 "/home/claude/cfront-3/src/tree_walk.cpp"

# 983 "/home/claude/cfront-3/src/tree_walk.cpp"
return __1action ;
}
}

# 987 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 989 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 990 "/home/claude/cfront-3/src/tree_walk.cpp"
__1e = (((struct expr *)(((struct expr *)((*__1replacement ))))));

# 992 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = a_expr_guts__6walkerFP4expr ( __0this , __1e ) ;
if (__1action == 2)return __1action ;
if (__1e -> base__4node == 140 )
# 995 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X81 = (& __1e -> __O3__4expr.e2 )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X81 ))
# 995 "/home/claude/cfront-3/src/tree_walk.cpp"
) ) ;
return __1action ;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 78 "/home/claude/cfront-3/src/tree_walk.cpp"

# 70 "/home/claude/cfront-3/src/tree_walk.cpp"

# 88 "/home/claude/cfront-3/src/tree_walk.cpp"

# 999 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_baseclass__6walkerFP4nodeP6baseclRP4node (register struct walker *__0this , Pnode __1ta , Pbcl __1b , Pnode *__1replacement )
# 1000 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 1001 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 1002 "/home/claude/cfront-3/src/tree_walk.cpp"
Pclass *__2__X82 ;

# 1002 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X83 ;

# 1002 "/home/claude/cfront-3/src/tree_walk.cpp"
Pbcl *__2__X84 ;

# 1001 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 15, ((struct node *)(((struct node *)__1b ))), __1replacement ) ;

# 1003 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 1005 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 1006 "/home/claude/cfront-3/src/tree_walk.cpp"
__1b = (((struct basecl *)(((struct basecl *)((*__1replacement ))))));

# 1008 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X82 = (& __1b -> bclass__6basecl )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X82 )) ) ) ;
# 1008 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1009 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1011 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X83 = (& __1b -> init__6basecl )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X83 )) ) ) ;
# 1011 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1012 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1014 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X84 = (Pbcl *)(& __1b -> next__6basecl )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X84 )) ) ) ;
# 1014 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1015 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1017 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 961 "/home/claude/cfront-3/src/cfront.h"
int discriminator__4nameFi (struct name *__0this , int );

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 62 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1024 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_name__6walkerFP4nodeP4nameRP4node (register struct walker *__0this , Pnode __1ta , Pname __1n , Pnode *__1replacement )
# 1025 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 1026 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1derr ;
int __1action ;

# 1027 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 10, ((struct node *)(((struct node *)__1n ))), __1replacement ) ;

# 1029 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 1031 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 1032 "/home/claude/cfront-3/src/tree_walk.cpp"
__1n = (((struct name *)(((struct name *)((*__1replacement ))))));

# 1036 "/home/claude/cfront-3/src/tree_walk.cpp"
switch (__1derr = discriminator__4nameFi ( __1n , 0 ) ){ 
# 1036 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X85 ;

# 1036 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptable *__2__X86 ;

# 1037 "/home/claude/cfront-3/src/tree_walk.cpp"
case 0 :
# 1038 "/home/claude/cfront-3/src/tree_walk.cpp"
break ;
case 1 :
# 1040 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X85 = (& __1n -> __O2__4name.n_qualifier )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X85 )) ) )
# 1040 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 2 :
# 1044 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X86 = (& __1n -> __O2__4name.n_realscope )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X86 )) ) )
# 1044 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
default :
# 1048 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"a_name: discrim error %d on union 0.", (unsigned long )__1derr ) ;
# 1048 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1049 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )2;
}

# 1052 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1n -> base__4node == 162 ){ 
# 1052 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X87 ;

# 1053 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X87 = (& __1n -> __O1__4name.n_dtag )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X87 )) ) ) ;
# 1053 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1054 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;
if (__1n -> __O1__4name.n_dtag && (__1n -> __O1__4name.n_dtag -> n_template_arg__4name == 1)){ 
# 1056 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname __3nn ;

# 1056 "/home/claude/cfront-3/src/tree_walk.cpp"
__3nn = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
((*__3nn ))= (*__1n -> __O1__4name.n_dtag );
__1n -> __O1__4name.n_dtag = __3nn ;
{ Ptype __3t ;
Pname __3cn ;

# 1059 "/home/claude/cfront-3/src/tree_walk.cpp"
__3t = __1n -> __O1__4name.n_dtag -> __O1__4expr.tp ;
__3cn = is_cl_obj__4typeFv ( __3t ) ;
if (__3cn || eobj ){ 
# 1062 "/home/claude/cfront-3/src/tree_walk.cpp"
char *__4str_tmp ;

# 1062 "/home/claude/cfront-3/src/tree_walk.cpp"
__4str_tmp = (((char *)__nw__FUl ( (unsigned long )((sizeof (char ))* (strlen ( eobj ?(((struct enumdef *)(((struct enumdef *)eobj -> __O1__4expr.tp ))))-> string__7enumdef :(((struct
# 1062 "/home/claude/cfront-3/src/tree_walk.cpp"
classdef *)(((struct classdef *)__3cn -> __O1__4expr.tp ))))-> string__8classdef ) + 1 ))) ));
strcpy ( __4str_tmp , eobj ?(((struct enumdef *)(((struct enumdef *)eobj -> __O1__4expr.tp ))))-> string__7enumdef :(((struct classdef *)(((struct classdef *)__3cn -> __O1__4expr.tp ))))-> string__8classdef ) ;

# 1065 "/home/claude/cfront-3/src/tree_walk.cpp"
__1n -> __O1__4name.n_dtag -> __O2__4expr.string = (const char *)__4str_tmp ;
}
else 
# 1066 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 1067 "/home/claude/cfront-3/src/tree_walk.cpp"
__1n -> __O3__4expr.tpdef = __3t ;
}

# 1068 "/home/claude/cfront-3/src/tree_walk.cpp"
}
}
}

# 1072 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = a_expr_guts__6walkerFP4expr ( __0this , ((struct expr *)(((struct expr *)__1n )))) ;
if (__1action == 2)return __1action ;

# 1075 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((__0this -> depth__6walker > 0 )|| (! __0this -> control__6walker . dont_chase_lists_top__17tree_walk_control )){ 
# 1075 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X88 ;

# 1076 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X88 = (& __1n -> __O1__4name.n_list )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X88 )) ) ) ;
# 1076 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1077 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;
}

# 1082 "/home/claude/cfront-3/src/tree_walk.cpp"
return __1action ;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 72 "/home/claude/cfront-3/src/tree_walk.cpp"

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 72 "/home/claude/cfront-3/src/tree_walk.cpp"

# 62 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1024 "/home/claude/cfront-3/src/cfront.h"
int discriminator__4stmtFi (struct stmt *__0this , int );

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 70 "/home/claude/cfront-3/src/tree_walk.cpp"

# 72 "/home/claude/cfront-3/src/tree_walk.cpp"

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 70 "/home/claude/cfront-3/src/tree_walk.cpp"

# 72 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1090 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_stmt__6walkerFP4nodeP4stmtRP4node (register struct walker *__0this , Pnode __1ta , Pstmt __1s , Pnode *__1replacement )
# 1091 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 1092 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1cl_error ;
int __1derr ;
int __1action ;

# 1095 "/home/claude/cfront-3/src/tree_walk.cpp"
Pstmt *__2__X90 ;

# 1095 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptable *__2__X91 ;

# 1094 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 12, ((struct node *)(((struct node *)__1s ))), __1replacement ) ;

# 1096 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 1){ 
# 1097 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 1098 "/home/claude/cfront-3/src/tree_walk.cpp"
__1s = (((struct stmt *)(((struct
# 1098 "/home/claude/cfront-3/src/tree_walk.cpp"
stmt *)((*__1replacement ))))));
__1cl_error = 0 ;
if ((classify_node__FP4nodeRi ( ((struct node *)(((struct node *)__1s ))), (int *)(& __1cl_error )) == 12)&& (! __1cl_error )){ 
# 1102 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((__0this ->
# 1102 "/home/claude/cfront-3/src/tree_walk.cpp"
depth__6walker > 0 )|| (! __0this -> control__6walker . dont_chase_lists_top__17tree_walk_control )){ 
# 1102 "/home/claude/cfront-3/src/tree_walk.cpp"
Pstmt *__2__X89 ;

# 1103 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X89 = (& __1s -> s_list__4stmt )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X89 )) ) ) ;
# 1103 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1104 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return (int )2;
}
}
return (int )1;
}

# 1110 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 1112 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 1113 "/home/claude/cfront-3/src/tree_walk.cpp"
__1s = (((struct stmt *)(((struct stmt *)((*__1replacement ))))));

# 1115 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X90 = (& __1s -> s__4stmt )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X90 )) ) ) ;
# 1115 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1116 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1118 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X91 = (& __1s -> memtbl__4stmt )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X91 )) ) ) ;
# 1118 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1119 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1121 "/home/claude/cfront-3/src/tree_walk.cpp"
switch (__1derr = discriminator__4stmtFi ( __1s , 0 ) ){ 
# 1121 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X92 ;

# 1121 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X93 ;

# 1121 "/home/claude/cfront-3/src/tree_walk.cpp"
Pstmt *__2__X94 ;

# 1121 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X95 ;

# 1122 "/home/claude/cfront-3/src/tree_walk.cpp"
default :
# 1123 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"a_stmt: discrim error %d on union 0.", (unsigned long )__1derr ) ;
# 1123 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1124 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )2;
case 4 :
# 1126 "/home/claude/cfront-3/src/tree_walk.cpp"
case 0 :break ;
case 1 :
# 1128 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X92 = (& __1s -> __O1__4stmt.d )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X92 )) ) )
# 1128 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 2 :
# 1132 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X93 = (& __1s -> __O1__4stmt.e2 )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X93 )) ) )
# 1132 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 3 :
# 1136 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X94 = (& __1s -> __O1__4stmt.has_default )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X94 )) ) )
# 1136 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 5 :
# 1140 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X95 = (& __1s -> __O1__4stmt.ret_tp )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X95 )) ) )
# 1140 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
}

# 1145 "/home/claude/cfront-3/src/tree_walk.cpp"
switch (__1derr = discriminator__4stmtFi ( __1s , 1 ) ){ 
# 1145 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X96 ;

# 1145 "/home/claude/cfront-3/src/tree_walk.cpp"
Pstmt *__2__X97 ;

# 1146 "/home/claude/cfront-3/src/tree_walk.cpp"
default :
# 1147 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"a_stmt: discrim error %d on union 1.", (unsigned long )__1derr ) ;
# 1147 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1148 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )2;
case 2 :
# 1150 "/home/claude/cfront-3/src/tree_walk.cpp"
case 0 :break ;
case 1 :
# 1152 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X96 = (& __1s -> __O2__4stmt.e )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X96 )) ) )
# 1152 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 3 :
# 1156 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X97 = (& __1s -> __O2__4stmt.s2 )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X97 )) ) )
# 1156 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
}

# 1161 "/home/claude/cfront-3/src/tree_walk.cpp"
switch (__1derr = discriminator__4stmtFi ( __1s , 2 ) ){ 
# 1161 "/home/claude/cfront-3/src/tree_walk.cpp"
Pstmt *__2__X98 ;

# 1161 "/home/claude/cfront-3/src/tree_walk.cpp"
Pstmt *__2__X99 ;

# 1161 "/home/claude/cfront-3/src/tree_walk.cpp"
Pstmt *__2__X100 ;

# 1162 "/home/claude/cfront-3/src/tree_walk.cpp"
default :
# 1163 "/home/claude/cfront-3/src/tree_walk.cpp"
error__6walkerFPCcUl ( __0this , (const char *)"a_stmt: discrim error %d on union 2.", (unsigned long )__1derr ) ;
# 1163 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1164 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )2;
case 0 :break ;
case 1 :
# 1167 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X98 = (& __1s -> __O3__4stmt.for_init )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X98 )) ) )
# 1167 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 2 :
# 1171 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X99 = (& __1s -> __O3__4stmt.else_stmt )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X99 )) ) )
# 1171 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
case 3 :
# 1175 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X100 = (& __1s -> __O3__4stmt.case_list )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X100 )) ) )
# 1175 "/home/claude/cfront-3/src/tree_walk.cpp"
;
if (__1action == 2)return __1action ;
break ;
}

# 1180 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((__0this -> depth__6walker > 0 )|| (! __0this -> control__6walker . dont_chase_lists_top__17tree_walk_control )){ 
# 1180 "/home/claude/cfront-3/src/tree_walk.cpp"
Pstmt *__2__X101 ;

# 1181 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X101 = (& __1s -> s_list__4stmt )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X101 )) ) ) ;
# 1181 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1182 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;
}

# 1185 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 70 "/home/claude/cfront-3/src/tree_walk.cpp"

# 58 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1188 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_ia__6walkerFP4nodeP2iaRP4node (register struct walker *__0this , Pnode __1ta , Pia __1ia , Pnode *__1replacement )
# 1189 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 1190 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 1191 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X102 ;

# 1191 "/home/claude/cfront-3/src/tree_walk.cpp"
Pexpr *__2__X103 ;

# 1191 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptype *__2__X104 ;

# 1190 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 17, ((struct node *)(((struct node *)__1ia ))), __1replacement ) ;

# 1192 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 1194 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 1195 "/home/claude/cfront-3/src/tree_walk.cpp"
__1ia = (((struct ia *)(((struct ia *)((*__1replacement ))))));

# 1197 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X102 = (& __1ia -> local__2ia )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X102 )) ) ) ;
# 1197 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1198 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1200 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X103 = (& __1ia -> arg__2ia )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X103 )) ) ) ;
# 1200 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1201 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1203 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X104 = (& __1ia -> tp__2ia )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X104 )) ) ) ;
# 1203 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1204 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1206 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 91 "/home/claude/cfront-3/src/tree_walk.cpp"

# 68 "/home/claude/cfront-3/src/tree_walk.cpp"

# 62 "/home/claude/cfront-3/src/tree_walk.cpp"

# 86 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1209 "/home/claude/cfront-3/src/tree_walk.cpp"
int a_iline__6walkerFP4nodeP5ilineRP4node (register struct walker *__0this , Pnode __1ta , Pin __1iline , Pnode *__1replacement )
# 1210 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 1211 "/home/claude/cfront-3/src/tree_walk.cpp"
int __1action ;

# 1212 "/home/claude/cfront-3/src/tree_walk.cpp"
Pname *__2__X105 ;

# 1212 "/home/claude/cfront-3/src/tree_walk.cpp"
Ptable *__2__X106 ;

# 1212 "/home/claude/cfront-3/src/tree_walk.cpp"
Pia *__2__X107 ;

# 1211 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node ( __0this , __1ta , 16, ((struct node *)(((struct node *)__1iline ))), __1replacement ) ;

# 1213 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action != 0)return __1action ;

# 1215 "/home/claude/cfront-3/src/tree_walk.cpp"
if ((! ( (__0this -> control__6walker . fetcher__17tree_walk_control != null_tfp )) )&& ((*__1replacement )))
# 1216 "/home/claude/cfront-3/src/tree_walk.cpp"
__1iline = (((struct iline *)(((struct iline *)((*__1replacement ))))));

# 1218 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X105 = (& __1iline -> fct_name__5iline )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X105 )) ) ) ;
# 1218 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1219 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1224 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X106 = (& __1iline -> i_table__5iline )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X106 )) ) ) ;
# 1224 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1225 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1227 "/home/claude/cfront-3/src/tree_walk.cpp"
__1action = ( (__2__X107 = (& __1iline -> i_args__5iline )), ( walk___6walkerFRP4node ( __0this , ((struct node **)__2__X107 )) ) ) ;
# 1227 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1228 "/home/claude/cfront-3/src/tree_walk.cpp"
if (__1action == 2)return __1action ;

# 1230 "/home/claude/cfront-3/src/tree_walk.cpp"
return (int )0;
}

# 110 "/home/claude/cfront-3/src/tree_walk.h"

# 1233 "/home/claude/cfront-3/src/tree_walk.cpp"
void add__10patch_treeSFP4node (Pnode __1node )
# 1234 "/home/claude/cfront-3/src/tree_walk.cpp"
{ 
# 1234 "/home/claude/cfront-3/src/tree_walk.cpp"
struct patch_tree *__0__X108 ;

# 1234 "/home/claude/cfront-3/src/tree_walk.cpp"
struct patch_tree *__2__X109 ;

# 1235 "/home/claude/cfront-3/src/tree_walk.cpp"
head__10patch_tree = ( (__0__X108 = 0 ), ( (__2__X109 = head__10patch_tree ), ( ((__0__X108 || (__0__X108 = (struct patch_tree *)__nw__FUl ( (unsigned long
# 1235 "/home/claude/cfront-3/src/tree_walk.cpp"
)(sizeof (struct patch_tree))) ))?( (__0__X108 -> node__10patch_tree = __1node ), (__0__X108 -> next__10patch_tree = __2__X109 )) :0 ), __0__X108 ) ) ) ;
# 1235 "/home/claude/cfront-3/src/tree_walk.cpp"

# 1236 "/home/claude/cfront-3/src/tree_walk.cpp"
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

# 1236 "/home/claude/cfront-3/src/tree_walk.cpp"

/* the end */
