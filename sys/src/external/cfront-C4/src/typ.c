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

# 21 "/home/claude/cfront-3/src/typ.cpp"
Pbase short_type = 0 ;
Pbase int_type = 0 ;
Pbase char_type = 0 ;
Pbase long_type = 0 ;
Pbase llong_type = 0 ;

# 27 "/home/claude/cfront-3/src/typ.cpp"
Pbase uchar_type = 0 ;
Pbase ushort_type = 0 ;
Pbase uint_type = 0 ;
Pbase ulong_type = 0 ;
Pbase ullong_type = 0 ;

# 33 "/home/claude/cfront-3/src/typ.cpp"
Pbase zero_type = 0 ;
Pbase float_type = 0 ;
Pbase double_type = 0 ;
Pbase ldouble_type = 0 ;
Pbase void_type = 0 ;
Pbase any_type = 0 ;

# 40 "/home/claude/cfront-3/src/typ.cpp"
Ptype Pint_type = 0 ;
Ptype Pchar_type = 0 ;
Ptype Pvoid_type = 0 ;
Ptype Pfctvec_type = 0 ;

# 45 "/home/claude/cfront-3/src/typ.cpp"
Ptable gtbl = 0 ;
Ptable ptbl = 0 ;

# 48 "/home/claude/cfront-3/src/typ.cpp"
Pname Cdcl = 0 ;
Pstmt Cstmt = 0 ;

# 51 "/home/claude/cfront-3/src/typ.cpp"
bit new_type = 0 ;

# 76 "/home/claude/cfront-3/src/cfront.h"

# 53 "/home/claude/cfront-3/src/typ.cpp"
Pclass classtype__4typeFv (register struct type *__0this ){ 
# 53 "/home/claude/cfront-3/src/typ.cpp"
unsigned long __2__X18 ;

# 54 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 54 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V17 ;

# 54 "/home/claude/cfront-3/src/typ.cpp"
return ((__0this -> base__4node == 119 )?(((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__0this ))))-> b_name__8basetype -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const
# 54 "/home/claude/cfront-3/src/typ.cpp"
char *)"T::classtype(): %k cobjX", (const struct ea *)( (__2__X18 = __0this -> base__4node ), ( ((
# 54 "/home/claude/cfront-3/src/typ.cpp"
((& __0__V17 )-> __O1__2ea.i = __2__X18 ), 0 ) ), (& __0__V17 )) ) , (const struct ea *)ea0 , (const
# 54 "/home/claude/cfront-3/src/typ.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct classdef *)0 ))) );
} 
# 56 "/home/claude/cfront-3/src/typ.cpp"
}

# 588 "/home/claude/cfront-3/src/cfront.h"
Pbase arit_conv__8basetypeFP8basetype (struct basetype *__0this , Pbase );

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 342 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr__4typeFv (struct type *__0this );

# 462 "/home/claude/cfront-3/src/cfront.h"
bit baseof__8classdefFP8classdef (struct classdef *__0this , Pclass );

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 359 "/home/claude/cfront-3/src/cfront.h"
Pfct memptr__4typeFv (struct type *__0this );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 58 "/home/claude/cfront-3/src/typ.cpp"
Ptype np_promote__FUcN21P4typeT4N21 (TOK __1oper , TOK __1r1 , TOK __1r2 , Ptype __1t1 , Ptype __1t2 , TOK __1p , bit __1perr )
# 71 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 72 "/home/claude/cfront-3/src/typ.cpp"
if (__1r2 == 'A' )
# 73 "/home/claude/cfront-3/src/typ.cpp"
return __1t1 ;

# 75 "/home/claude/cfront-3/src/typ.cpp"
switch (__1r1 ){ 
# 76 "/home/claude/cfront-3/src/typ.cpp"
case 'A' :
# 77 "/home/claude/cfront-3/src/typ.cpp"
return __1t2 ;
case 'Z' :
# 79 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 80 "/home/claude/cfront-3/src/typ.cpp"
case 130 :
# 81 "/home/claude/cfront-3/src/typ.cpp"
case 131 :
# 82 "/home/claude/cfront-3/src/typ.cpp"
case 132 :
# 83 "/home/claude/cfront-3/src/typ.cpp"
case 134 :
# 84 "/home/claude/cfront-3/src/typ.cpp"
case 135 :
# 85 "/home/claude/cfront-3/src/typ.cpp"
case 126 :
# 86 "/home/claude/cfront-3/src/typ.cpp"
case 127 :
# 87 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
}
switch (__1r2 ){ 
# 90 "/home/claude/cfront-3/src/typ.cpp"
case 'Z' :return (struct type *)int_type ;
case 'F' :
# 92 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 93 "/home/claude/cfront-3/src/typ.cpp"
case 53 :
# 94 "/home/claude/cfront-3/src/typ.cpp"
case 52 :
# 95 "/home/claude/cfront-3/src/typ.cpp"
case 64 :
# 96 "/home/claude/cfront-3/src/typ.cpp"
case 65 :
# 97 "/home/claude/cfront-3/src/typ.cpp"
case 56 :
# 98 "/home/claude/cfront-3/src/typ.cpp"
case 57 :
# 99 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
}

# 102 "/home/claude/cfront-3/src/typ.cpp"
case 'I' :
# 103 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 104 "/home/claude/cfront-3/src/typ.cpp"
case 111 :
# 105 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
case 56 :
# 107 "/home/claude/cfront-3/src/typ.cpp"
case 57 :
# 108 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)int_type ;
}
return (struct type *)(__1p ?arit_conv__8basetypeFP8basetype ( ((struct basetype *)(((struct basetype *)skiptypedefs__4typeFv ( __1t2 ) ))), (struct basetype *)0 ) :(((struct basetype *)0 )));

# 115 "/home/claude/cfront-3/src/typ.cpp"
case 'P' :
# 116 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 117 "/home/claude/cfront-3/src/typ.cpp"
case 53 :
# 118 "/home/claude/cfront-3/src/typ.cpp"
case 52 :
# 119 "/home/claude/cfront-3/src/typ.cpp"
case 64 :
# 120 "/home/claude/cfront-3/src/typ.cpp"
case 65 :
# 121 "/home/claude/cfront-3/src/typ.cpp"
case 56 :
# 122 "/home/claude/cfront-3/src/typ.cpp"
case 57 :
# 123 "/home/claude/cfront-3/src/typ.cpp"
case 61 :
# 124 "/home/claude/cfront-3/src/typ.cpp"
case 60 :
# 125 "/home/claude/cfront-3/src/typ.cpp"
case 59 :
# 126 "/home/claude/cfront-3/src/typ.cpp"
case 58 :
# 127 "/home/claude/cfront-3/src/typ.cpp"
return
# 127 "/home/claude/cfront-3/src/typ.cpp"
(struct type *)any_type ;
case 54 :
# 129 "/home/claude/cfront-3/src/typ.cpp"
case 126 :
# 130 "/home/claude/cfront-3/src/typ.cpp"
if (__1t2 != Pvoid_type )
# 131 "/home/claude/cfront-3/src/typ.cpp"
break ;
case 62 :
# 133 "/home/claude/cfront-3/src/typ.cpp"
case 63 :
# 134 "/home/claude/cfront-3/src/typ.cpp"
case 68 :
# 135 "/home/claude/cfront-3/src/typ.cpp"
break ;
default :
# 137 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
}
return __1t2 ;
case 108 :
# 141 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 142 "/home/claude/cfront-3/src/typ.cpp"
case 68 :
# 143 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
case 62 :
# 145 "/home/claude/cfront-3/src/typ.cpp"
case 63 :
# 146 "/home/claude/cfront-3/src/typ.cpp"
return __1t2 ;
}
if (__1perr ){ 
# 148 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V19 ;

# 148 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"zero%kF", (const struct ea *)( (( ((& __0__V19 )->
# 148 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V19 )) , (const struct ea *)ea0 , (const struct
# 148 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (struct type *)any_type ;
default :
# 151 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 151 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V20 ;

# 151 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"zero(%d)", (const struct ea *)( ((
# 151 "/home/claude/cfront-3/src/typ.cpp"
((& __0__V20 )-> __O1__2ea.i = ((unsigned long )__1r2 )), 0 ) ), (& __0__V20 )) , (const struct ea *)ea0 ,
# 151 "/home/claude/cfront-3/src/typ.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
case 'I' :
# 154 "/home/claude/cfront-3/src/typ.cpp"
switch (__1r2 ){ 
# 155 "/home/claude/cfront-3/src/typ.cpp"
case 'Z' :
# 156 "/home/claude/cfront-3/src/typ.cpp"
__1t2 = 0 ;
switch (__1oper ){ 
# 158 "/home/claude/cfront-3/src/typ.cpp"
case 111 :
# 159 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
}
return (struct type *)(__1p ?arit_conv__8basetypeFP8basetype ( ((struct basetype *)(((struct basetype *)skiptypedefs__4typeFv ( __1t1 ) ))), ((struct basetype *)(((struct basetype *)__1t2 )))) :(((struct basetype *)0 )));

# 166 "/home/claude/cfront-3/src/typ.cpp"
case 'F' :
# 167 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 168 "/home/claude/cfront-3/src/typ.cpp"
case 53 :
# 169 "/home/claude/cfront-3/src/typ.cpp"
case 52 :
# 170 "/home/claude/cfront-3/src/typ.cpp"
case 64 :
# 171 "/home/claude/cfront-3/src/typ.cpp"
case 65 :
# 172 "/home/claude/cfront-3/src/typ.cpp"
case 56 :
# 173 "/home/claude/cfront-3/src/typ.cpp"
case 57 :
# 174 "/home/claude/cfront-3/src/typ.cpp"
case 130 :
# 175 "/home/claude/cfront-3/src/typ.cpp"
case 131 :
# 176 "/home/claude/cfront-3/src/typ.cpp"
case 132 :
# 177 "/home/claude/cfront-3/src/typ.cpp"
case 134 :
# 178 "/home/claude/cfront-3/src/typ.cpp"
case
# 178 "/home/claude/cfront-3/src/typ.cpp"
135 :
# 179 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
}

# 182 "/home/claude/cfront-3/src/typ.cpp"
case 'I' :
# 183 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 184 "/home/claude/cfront-3/src/typ.cpp"
case 111 :
# 185 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
case 56 :
# 187 "/home/claude/cfront-3/src/typ.cpp"
case 57 :
# 188 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)(__1p ?arit_conv__8basetypeFP8basetype ( ((struct basetype *)(((struct basetype *)skiptypedefs__4typeFv ( __1t1 ) ))), ((struct basetype *)0 )) :(((struct basetype *)0 )));
# 188 "/home/claude/cfront-3/src/typ.cpp"

# 193 "/home/claude/cfront-3/src/typ.cpp"
}
return (struct type *)(__1p ?arit_conv__8basetypeFP8basetype ( ((struct basetype *)(((struct basetype *)skiptypedefs__4typeFv ( __1t1 ) ))), ((struct basetype *)(((struct basetype *)__1t2 )))) :(((struct basetype *)0 )));

# 199 "/home/claude/cfront-3/src/typ.cpp"
case 'P' :
# 200 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 201 "/home/claude/cfront-3/src/typ.cpp"
case 111 :
# 202 "/home/claude/cfront-3/src/typ.cpp"
break ;
case 54 :
# 204 "/home/claude/cfront-3/src/typ.cpp"
case 126 :
# 205 "/home/claude/cfront-3/src/typ.cpp"
if (__1t2 != Pvoid_type )
# 206 "/home/claude/cfront-3/src/typ.cpp"
break ;
default :
# 208 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 208 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V21 ;

# 208 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"int%kP", (const struct ea *)( (( ((& __0__V21 )->
# 208 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V21 )) , (const struct ea *)ea0 , (const struct
# 208 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (struct type *)any_type ;
}
return __1t2 ;
case 108 :
# 213 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 213 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V22 ;

# 213 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"int%kF", (const struct ea *)( (( ((& __0__V22 )->
# 213 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V22 )) , (const struct ea *)ea0 , (const struct
# 213 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (struct type *)any_type ;
default :
# 216 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 216 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V23 ;

# 216 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"int(%d)", (const struct ea *)( ((
# 216 "/home/claude/cfront-3/src/typ.cpp"
((& __0__V23 )-> __O1__2ea.i = ((unsigned long )__1r2 )), 0 ) ), (& __0__V23 )) , (const struct ea *)ea0 ,
# 216 "/home/claude/cfront-3/src/typ.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return (struct type *)any_type ;
} }
case 'F' :
# 220 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 221 "/home/claude/cfront-3/src/typ.cpp"
case 53 :
# 222 "/home/claude/cfront-3/src/typ.cpp"
case 130 :
# 223 "/home/claude/cfront-3/src/typ.cpp"
case 52 :
# 224 "/home/claude/cfront-3/src/typ.cpp"
case 64 :
# 225 "/home/claude/cfront-3/src/typ.cpp"
case 65 :
# 226 "/home/claude/cfront-3/src/typ.cpp"
case 131 :
# 227 "/home/claude/cfront-3/src/typ.cpp"
case 132 :
# 228 "/home/claude/cfront-3/src/typ.cpp"
case 56 :
# 229 "/home/claude/cfront-3/src/typ.cpp"
case 57 :
# 230 "/home/claude/cfront-3/src/typ.cpp"
case
# 230 "/home/claude/cfront-3/src/typ.cpp"
134 :
# 231 "/home/claude/cfront-3/src/typ.cpp"
case 135 :
# 232 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
}
switch (__1r2 ){ 
# 235 "/home/claude/cfront-3/src/typ.cpp"
case 'Z' :
# 236 "/home/claude/cfront-3/src/typ.cpp"
__1t2 = 0 ;
case 'I' :
# 238 "/home/claude/cfront-3/src/typ.cpp"
case 'F' :
# 239 "/home/claude/cfront-3/src/typ.cpp"
if (__1oper == 111 )
# 240 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
return (struct type *)(__1p ?arit_conv__8basetypeFP8basetype ( ((struct basetype *)(((struct basetype *)skiptypedefs__4typeFv ( __1t1 ) ))), ((struct basetype *)(((struct basetype *)__1t2 )))) :(((struct basetype *)0 )));

# 246 "/home/claude/cfront-3/src/typ.cpp"
case 'P' :
# 247 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 247 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V24 ;

# 247 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"float%kP", (const struct ea *)( (( ((& __0__V24 )->
# 247 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V24 )) , (const struct ea *)ea0 , (const struct
# 247 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (struct type *)any_type ;
case 108 :
# 250 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 250 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V25 ;

# 250 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"float%kF", (const struct ea *)( (( ((& __0__V25 )->
# 250 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V25 )) , (const struct ea *)ea0 , (const struct
# 250 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (struct type *)any_type ;
default :
# 253 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 253 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V26 ;

# 253 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"float(%d)", (const struct ea *)( ((
# 253 "/home/claude/cfront-3/src/typ.cpp"
((& __0__V26 )-> __O1__2ea.i = ((unsigned long )__1r2 )), 0 ) ), (& __0__V26 )) , (const struct ea *)ea0 ,
# 253 "/home/claude/cfront-3/src/typ.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return (struct type *)any_type ;
} }
case 'P' :
# 257 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 258 "/home/claude/cfront-3/src/typ.cpp"
case 56 :
# 259 "/home/claude/cfront-3/src/typ.cpp"
case 57 :
# 260 "/home/claude/cfront-3/src/typ.cpp"
case 134 :
# 261 "/home/claude/cfront-3/src/typ.cpp"
case 135 :
# 262 "/home/claude/cfront-3/src/typ.cpp"
case 53 :
# 263 "/home/claude/cfront-3/src/typ.cpp"
case 130 :
# 264 "/home/claude/cfront-3/src/typ.cpp"
case 64 :
# 265 "/home/claude/cfront-3/src/typ.cpp"
case 65 :
# 266 "/home/claude/cfront-3/src/typ.cpp"
case 132 :
# 267 "/home/claude/cfront-3/src/typ.cpp"
case
# 267 "/home/claude/cfront-3/src/typ.cpp"
52 :
# 268 "/home/claude/cfront-3/src/typ.cpp"
case 131 :
# 269 "/home/claude/cfront-3/src/typ.cpp"
case 51 :
# 270 "/home/claude/cfront-3/src/typ.cpp"
case 50 :
# 271 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
}
switch (__1r2 ){ 
# 274 "/home/claude/cfront-3/src/typ.cpp"
case 'Z' :
# 275 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 276 "/home/claude/cfront-3/src/typ.cpp"
case 61 :
# 277 "/home/claude/cfront-3/src/typ.cpp"
case 60 :
# 278 "/home/claude/cfront-3/src/typ.cpp"
case 59 :
# 279 "/home/claude/cfront-3/src/typ.cpp"
case 58 :
# 280 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
}
return __1t1 ;
case 'I' :
# 284 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 285 "/home/claude/cfront-3/src/typ.cpp"
case 111 :
# 286 "/home/claude/cfront-3/src/typ.cpp"
case 54 :
# 287 "/home/claude/cfront-3/src/typ.cpp"
case 55 :
# 288 "/home/claude/cfront-3/src/typ.cpp"
case 126 :
# 289 "/home/claude/cfront-3/src/typ.cpp"
case 127 :
# 290 "/home/claude/cfront-3/src/typ.cpp"
if (check__4typeFP4typeUcT2 ( __1t1 , Pvoid_type , (unsigned char
# 290 "/home/claude/cfront-3/src/typ.cpp"
)0 , (unsigned char )0 ) == 0 ){ 
# 291 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
}
break ;
default :
# 295 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 295 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V27 ;

# 295 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"P%k int", (const struct ea *)( (( ((& __0__V27 )->
# 295 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V27 )) , (const struct ea *)ea0 , (const struct
# 295 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (struct type *)any_type ;
}
return __1t1 ;
case 'F' :
# 300 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 300 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V28 ;

# 300 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"P%k float", (const struct ea *)( (( ((& __0__V28 )->
# 300 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V28 )) , (const struct ea *)ea0 , (const struct
# 300 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (struct type *)any_type ;
case 'P' :
# 303 "/home/claude/cfront-3/src/typ.cpp"
if (check__4typeFP4typeUcT2 ( __1t1 , __1t2 , (unsigned char )70 , (unsigned char )0 ) ){ 
# 304 "/home/claude/cfront-3/src/typ.cpp"
Ptype __4tt1 ;
Ptype __4tt2 ;

# 304 "/home/claude/cfront-3/src/typ.cpp"
__4tt1 = skiptypedefs__4typeFv ( is_ptr__4typeFv ( __1t1 ) -> typ__5pvtyp ) ;
__4tt2 = skiptypedefs__4typeFv ( is_ptr__4typeFv ( __1t2 ) -> typ__5pvtyp ) ;
switch (__1oper ){ 
# 307 "/home/claude/cfront-3/src/typ.cpp"
case 62 :
# 308 "/home/claude/cfront-3/src/typ.cpp"
case 63 :
# 309 "/home/claude/cfront-3/src/typ.cpp"
case 59 :
# 310 "/home/claude/cfront-3/src/typ.cpp"
case 61 :
# 311 "/home/claude/cfront-3/src/typ.cpp"
case 60 :
# 312 "/home/claude/cfront-3/src/typ.cpp"
case 58 :
# 313 "/home/claude/cfront-3/src/typ.cpp"
case 55 :
# 314 "/home/claude/cfront-3/src/typ.cpp"
case 68 :
# 315 "/home/claude/cfront-3/src/typ.cpp"
if (((__4tt1 && __4tt2 )&& (__4tt1 ->
# 315 "/home/claude/cfront-3/src/typ.cpp"
base__4node == 119 ))&& (__4tt2 -> base__4node == 119 ))
# 318 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 319 "/home/claude/cfront-3/src/typ.cpp"
Pclass __6c1 ;
Pclass __6c2 ;

# 319 "/home/claude/cfront-3/src/typ.cpp"
__6c1 = classtype__4typeFv ( __4tt1 ) ;
__6c2 = classtype__4typeFv ( __4tt2 ) ;
if (((__6c1 && __6c2 )&& baseof__8classdefFP8classdef ( __6c1 , __6c2 ) )|| baseof__8classdefFP8classdef ( __6c2 , __6c1 ) )
# 324 "/home/claude/cfront-3/src/typ.cpp"
goto zz ;
}
if (check__4typeFP4typeUcT2 ( __1t2 , __1t1 , (unsigned char )70 , (unsigned char )0 ) == 0 ){ 
# 327 "/home/claude/cfront-3/src/typ.cpp"
if (__1oper ==
# 327 "/home/claude/cfront-3/src/typ.cpp"
68 )return __1t2 ;
goto zz ;
}
break ;
case 180 :
# 332 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 333 "/home/claude/cfront-3/src/typ.cpp"
Pname __6cn ;

# 334 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X39 ;

# 334 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X40 ;

# 333 "/home/claude/cfront-3/src/typ.cpp"
__6cn = is_cl_obj__4typeFv ( __4tt1 ) ;
if ((__6cn && (__4tt2 -> base__4node == 108 ))&& ( (__1__X39 = (((struct classdef *)(((struct classdef *)__6cn -> __O1__4expr.tp ))))), ( (__1__X40 = (((struct
# 334 "/home/claude/cfront-3/src/typ.cpp"
fct *)(((struct fct *)__4tt2 ))))-> memof__3fct ), ( ((__1__X39 == __1__X40 )?1 :((__1__X39 && __1__X40 )?(((int )same_class__8classdefFP8classdefi ( __1__X39 , __1__X40 , 0 ) )):0 ))) ) )
# 334 "/home/claude/cfront-3/src/typ.cpp"
)
# 338 "/home/claude/cfront-3/src/typ.cpp"
return __1t2 ;
}
}
if (__1perr ){ 
# 341 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V29 ;

# 341 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V30 ;

# 341 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V31 ;

# 341 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"T mismatch:%t %k%t", (const struct ea *)( ((& __0__V29 )-> __O1__2ea.p =
# 341 "/home/claude/cfront-3/src/typ.cpp"
((const void *)__1t1 )), (& __0__V29 )) , (const struct ea *)( (( ((& __0__V30 )-> __O1__2ea.i = ((unsigned
# 341 "/home/claude/cfront-3/src/typ.cpp"
long )__1oper )), 0 ) ), (& __0__V30 )) , (const struct ea *)( ((& __0__V31 )-> __O1__2ea.p = ((const
# 341 "/home/claude/cfront-3/src/typ.cpp"
void *)__1t2 )), (& __0__V31 )) , (const struct ea *)ea0 ) ;
} return (struct type *)any_type ;
}
zz :
# 345 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 346 "/home/claude/cfront-3/src/typ.cpp"
case 55 :
# 347 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)((__1t2 != Pvoid_type )?int_type :any_type );

# 352 "/home/claude/cfront-3/src/typ.cpp"
case 127 :
# 353 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr )error__FPCc ( (const char *)"P -=P") ;
return (struct type *)any_type ;
case 54 :
# 356 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr )error__FPCc ( (const char *)"P +P") ;
return (struct type *)any_type ;
case 126 :
# 359 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr )error__FPCc ( (const char *)"P +=P") ;
return (struct type *)any_type ;
case 53 :
# 362 "/home/claude/cfront-3/src/typ.cpp"
case 130 :
# 363 "/home/claude/cfront-3/src/typ.cpp"
case 52 :
# 364 "/home/claude/cfront-3/src/typ.cpp"
case 64 :
# 365 "/home/claude/cfront-3/src/typ.cpp"
case 65 :
# 366 "/home/claude/cfront-3/src/typ.cpp"
case 131 :
# 367 "/home/claude/cfront-3/src/typ.cpp"
case 132 :
# 368 "/home/claude/cfront-3/src/typ.cpp"
case 134 :
# 369 "/home/claude/cfront-3/src/typ.cpp"
case 135 :
# 370 "/home/claude/cfront-3/src/typ.cpp"
case 56 :
# 371 "/home/claude/cfront-3/src/typ.cpp"
case 57 :
# 372 "/home/claude/cfront-3/src/typ.cpp"
case 111 :
# 373 "/home/claude/cfront-3/src/typ.cpp"
return (struct
# 373 "/home/claude/cfront-3/src/typ.cpp"
type *)any_type ;
default :
# 375 "/home/claude/cfront-3/src/typ.cpp"
return __1t1 ;
}
case 108 :
# 378 "/home/claude/cfront-3/src/typ.cpp"
return __1t1 ;
default :
# 380 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 380 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V32 ;

# 380 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"P(%d)", (const struct ea *)( ((
# 380 "/home/claude/cfront-3/src/typ.cpp"
((& __0__V32 )-> __O1__2ea.i = ((unsigned long )__1r2 )), 0 ) ), (& __0__V32 )) , (const struct ea *)ea0 ,
# 380 "/home/claude/cfront-3/src/typ.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
case 108 :
# 383 "/home/claude/cfront-3/src/typ.cpp"
if (__1oper == 68 ){ 
# 384 "/home/claude/cfront-3/src/typ.cpp"
switch (__1r2 ){ 
# 385 "/home/claude/cfront-3/src/typ.cpp"
case 'Z' :
# 386 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
case 'P' :
# 388 "/home/claude/cfront-3/src/typ.cpp"
return __1t2 ;
case 'I' :
# 390 "/home/claude/cfront-3/src/typ.cpp"
case 'F' :
# 391 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 391 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V33 ;

# 391 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V34 ;

# 391 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"F%k%t", (const struct ea *)( (( ((& __0__V33 )->
# 391 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V33 )) , (const struct ea *)( ((& __0__V34 )->
# 391 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.p = ((const void *)__1t2 )), (& __0__V34 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 391 "/home/claude/cfront-3/src/typ.cpp"
} 
# 392 "/home/claude/cfront-3/src/typ.cpp"
default :
# 393 "/home/claude/cfront-3/src/typ.cpp"
return __1t1 ;
}
}
if (((((struct fct *)(((struct fct *)__1t1 ))))-> memof__3fct && (__1r2 == 'P' ))&& memptr__4typeFv ( __1t2 ) )
# 397 "/home/claude/cfront-3/src/typ.cpp"
return __1t2 ;
if (((__1oper == 62 )|| (__1oper == 63 ))&& (__1r2 == 'Z' ))return __1t1 ;
if (__1perr ){ 
# 399 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V35 ;

# 399 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V36 ;

# 399 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"F%k%t", (const struct ea *)( (( ((& __0__V35 )->
# 399 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V35 )) , (const struct ea *)( ((& __0__V36 )->
# 399 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.p = ((const void *)__1t2 )), (& __0__V36 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 399 "/home/claude/cfront-3/src/typ.cpp"
} 
# 400 "/home/claude/cfront-3/src/typ.cpp"
return (struct type *)any_type ;
default :
# 402 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 402 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V37 ;

# 402 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V38 ;

# 402 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"np_promote(%d,%d)", (const struct ea *)( ((
# 402 "/home/claude/cfront-3/src/typ.cpp"
((& __0__V37 )-> __O1__2ea.i = ((unsigned long )__1r1 )), 0 ) ), (& __0__V37 )) , (const struct ea *)(
# 402 "/home/claude/cfront-3/src/typ.cpp"
(( ((& __0__V38 )-> __O1__2ea.i = ((unsigned long )__1r2 )), 0 ) ), (& __0__V38 )) , (const struct
# 402 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
return (struct type *)0 ;
} }
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 346 "/home/claude/cfront-3/src/cfront.h"
int tsizeof__4typeFi (struct type *__0this , int );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 407 "/home/claude/cfront-3/src/typ.cpp"
TOK kind__4typeFUcN21 (register struct type *__0this , TOK __1oper , TOK __1v , bit __1perr )
# 412 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 413 "/home/claude/cfront-3/src/typ.cpp"
Ptype __1t ;

# 413 "/home/claude/cfront-3/src/typ.cpp"
__1t = __0this ;
if (__0this == 0 )
# 415 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCc ( (int )'i' , (const char *)"type::kind(): this==0") ;

# 417 "/home/claude/cfront-3/src/typ.cpp"
__1t = skiptypedefs__4typeFv ( __1t ) ;

# 419 "/home/claude/cfront-3/src/typ.cpp"
switch (__1t -> base__4node ){ 
# 419 "/home/claude/cfront-3/src/typ.cpp"
unsigned long __2__X54 ;

# 420 "/home/claude/cfront-3/src/typ.cpp"
case 141 :
# 421 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )'A' ;
case 138 :
# 423 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )'Z' ;
case 114 :
# 425 "/home/claude/cfront-3/src/typ.cpp"
case 5 :
# 426 "/home/claude/cfront-3/src/typ.cpp"
case 29 :
# 427 "/home/claude/cfront-3/src/typ.cpp"
case 21 :
# 428 "/home/claude/cfront-3/src/typ.cpp"
case 22 :
# 429 "/home/claude/cfront-3/src/typ.cpp"
case 122 :
# 430 "/home/claude/cfront-3/src/typ.cpp"
case 121 :
# 431 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )'I' ;
case 15 :
# 433 "/home/claude/cfront-3/src/typ.cpp"
case 181 :
# 434 "/home/claude/cfront-3/src/typ.cpp"
case 11 :
# 435 "/home/claude/cfront-3/src/typ.cpp"
if (__1v == 'I' )
# 436 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 436 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V41 ;

# 436 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"float operand for %k", (const struct ea *)( (( ((& __0__V41 )->
# 436 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V41 )) , (const struct ea *)ea0 , (const struct
# 436 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (unsigned char )'F' ;
case 110 :
# 439 "/home/claude/cfront-3/src/typ.cpp"
case 125 :
# 440 "/home/claude/cfront-3/src/typ.cpp"
if (__1v != 'P' )
# 441 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 441 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V42 ;

# 441 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"P operand for %k", (const struct ea *)( (( ((& __0__V42 )->
# 441 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V42 )) , (const struct ea *)ea0 , (const struct
# 441 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} switch (__1oper ){ 
# 443 "/home/claude/cfront-3/src/typ.cpp"
case 48 :
# 444 "/home/claude/cfront-3/src/typ.cpp"
case 49 :
# 445 "/home/claude/cfront-3/src/typ.cpp"
case 55 :
# 446 "/home/claude/cfront-3/src/typ.cpp"
case 54 :
# 447 "/home/claude/cfront-3/src/typ.cpp"
case 127 :
# 448 "/home/claude/cfront-3/src/typ.cpp"
case 126 :
# 449 "/home/claude/cfront-3/src/typ.cpp"
if ((__1t -> base__4node == 125 )&& ((((struct
# 449 "/home/claude/cfront-3/src/typ.cpp"
ptr *)(((struct ptr *)__1t ))))-> memof__3ptr || ((((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp -> base__4node == 108 )))
# 457 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 458 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 458 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V43 ;

# 458 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V44 ;

# 458 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t operand of%k", (const struct ea *)( ((& __0__V43 )-> __O1__2ea.p =
# 458 "/home/claude/cfront-3/src/typ.cpp"
((const void *)__0this )), (& __0__V43 )) , (const struct ea *)( (( ((& __0__V44 )-> __O1__2ea.i = ((unsigned
# 458 "/home/claude/cfront-3/src/typ.cpp"
long )__1oper )), 0 ) ), (& __0__V44 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 458 "/home/claude/cfront-3/src/typ.cpp"
} 
# 459 "/home/claude/cfront-3/src/typ.cpp"
}
else { 
# 461 "/home/claude/cfront-3/src/typ.cpp"
tsizeof__4typeFi ( (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp , 0 ) ;
}
break ;
default :
# 465 "/home/claude/cfront-3/src/typ.cpp"
if ((__1t -> base__4node == 125 )&& ((((struct ptr *)(((struct ptr *)__1t ))))-> memof__3ptr || ((((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp -> base__4node ==
# 465 "/home/claude/cfront-3/src/typ.cpp"
108 )))
# 474 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 474 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V45 ;

# 474 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V46 ;

# 474 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t operand of%k", (const struct ea *)( ((& __0__V45 )-> __O1__2ea.p =
# 474 "/home/claude/cfront-3/src/typ.cpp"
((const void *)__0this )), (& __0__V45 )) , (const struct ea *)( (( ((& __0__V46 )-> __O1__2ea.i = ((unsigned
# 474 "/home/claude/cfront-3/src/typ.cpp"
long )__1oper )), 0 ) ), (& __0__V46 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 474 "/home/claude/cfront-3/src/typ.cpp"
} 
# 475 "/home/claude/cfront-3/src/typ.cpp"
case 58 :
# 476 "/home/claude/cfront-3/src/typ.cpp"
case 59 :
# 477 "/home/claude/cfront-3/src/typ.cpp"
case 60 :
# 478 "/home/claude/cfront-3/src/typ.cpp"
case 61 :
# 479 "/home/claude/cfront-3/src/typ.cpp"
case 66 :
# 480 "/home/claude/cfront-3/src/typ.cpp"
case 67 :
# 481 "/home/claude/cfront-3/src/typ.cpp"
case 70 :
# 482 "/home/claude/cfront-3/src/typ.cpp"
case 63 :
# 483 "/home/claude/cfront-3/src/typ.cpp"
case 62 :
# 484 "/home/claude/cfront-3/src/typ.cpp"
case 20 :
# 485 "/home/claude/cfront-3/src/typ.cpp"
case 39 :
# 486 "/home/claude/cfront-3/src/typ.cpp"
case 10 :
# 487 "/home/claude/cfront-3/src/typ.cpp"
case
# 487 "/home/claude/cfront-3/src/typ.cpp"
16 :
# 488 "/home/claude/cfront-3/src/typ.cpp"
case 68 :
# 489 "/home/claude/cfront-3/src/typ.cpp"
case 46 :
# 490 "/home/claude/cfront-3/src/typ.cpp"
break ;
}
return (unsigned char )'P' ;
case 158 :
# 494 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 494 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V47 ;

# 494 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"R operand for %k", (const struct ea *)( (( ((& __0__V47 )->
# 494 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V47 )) , (const struct ea *)ea0 , (const struct
# 494 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (unsigned char )'A' ;
case 108 :
# 497 "/home/claude/cfront-3/src/typ.cpp"
if (__1v != 'P' )
# 498 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 498 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V48 ;

# 498 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"F operand for %k", (const struct ea *)( (( ((& __0__V48 )->
# 498 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V48 )) , (const struct ea *)ea0 , (const struct
# 498 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (unsigned char )108 ;
case 76 :
# 501 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 501 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V49 ;

# 501 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"overloaded operand for %k", (const struct ea *)( (( ((& __0__V49 )->
# 501 "/home/claude/cfront-3/src/typ.cpp"
__O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V49 )) , (const struct ea *)ea0 , (const struct
# 501 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} return (unsigned char )'A' ;
case 6 :
# 504 "/home/claude/cfront-3/src/typ.cpp"
case 13 :
# 505 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 505 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V50 ;

# 505 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V51 ;

# 505 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k operand for %k", (const struct ea *)( (__2__X54 = __0this -> base__4node ),
# 505 "/home/claude/cfront-3/src/typ.cpp"
( (( ((& __0__V50 )-> __O1__2ea.i = __2__X54 ), 0 ) ), (& __0__V50 )) ) , (const struct
# 505 "/home/claude/cfront-3/src/typ.cpp"
ea *)( (( ((& __0__V51 )-> __O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V51 )) , (const
# 505 "/home/claude/cfront-3/src/typ.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} return (unsigned char )'A' ;
default :
# 508 "/home/claude/cfront-3/src/typ.cpp"
if (__1perr ){ 
# 508 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V52 ;

# 508 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V53 ;

# 508 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"%t operand for %k", (const struct ea *)( ((& __0__V52 )-> __O1__2ea.p =
# 508 "/home/claude/cfront-3/src/typ.cpp"
((const void *)__0this )), (& __0__V52 )) , (const struct ea *)( (( ((& __0__V53 )-> __O1__2ea.i = ((unsigned
# 508 "/home/claude/cfront-3/src/typ.cpp"
long )__1oper )), 0 ) ), (& __0__V53 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 508 "/home/claude/cfront-3/src/typ.cpp"
} 
# 509 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )'A' ;
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 798 "/home/claude/cfront-3/src/cfront.h"
Pexpr typ__4exprFP5table (struct expr *__0this , Ptable );

# 740 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr check_cond__FP4exprUcP5table (Pexpr , TOK , Ptable );

# 352 "/home/claude/cfront-3/src/cfront.h"

# 799 "/home/claude/cfront-3/src/cfront.h"
long long eval__4exprFv (struct expr *__0this );

# 794 "/home/claude/cfront-3/src/cfront.h"
void del__4exprFv (struct expr *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 654 "/home/claude/cfront-3/src/typ.cpp"
extern void dargs__FP4nameP3fctP5table (Pname , Pfct , Ptable );

# 513 "/home/claude/cfront-3/src/typ.cpp"
void dcl__4typeFP5table (struct type *__0this , Ptable __1tbl );

# 468 "/home/claude/cfront-3/src/cfront.h"

# 1224 "/home/claude/cfront-3/src/cfront.h"
extern void make_res__FP3fct (Pfct );

# 352 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 513 "/home/claude/cfront-3/src/typ.cpp"
void dcl__4typeFP5table (register struct type *__0this , Ptable __1tbl )
# 521 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 522 "/home/claude/cfront-3/src/typ.cpp"
Ptype __1t ;

# 527 "/home/claude/cfront-3/src/typ.cpp"
int __1os ;

# 528 "/home/claude/cfront-3/src/typ.cpp"
unsigned long __2__X60 ;

# 522 "/home/claude/cfront-3/src/typ.cpp"
__1t = __0this ;

# 527 "/home/claude/cfront-3/src/typ.cpp"
__1os = processing_sizeof ;
processing_sizeof = 0 ;

# 530 "/home/claude/cfront-3/src/typ.cpp"
if (__0this == 0 )
# 531 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCc ( (int )'i' , (const char *)"T::dcl(this==0)") ;
if (__1tbl -> base__4node != 142 )
# 533 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 533 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V55 ;

# 533 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"T::dcl(%d)", (const struct ea *)( (__2__X60 =
# 533 "/home/claude/cfront-3/src/typ.cpp"
__1tbl -> base__4node ), ( (( ((& __0__V55 )-> __O1__2ea.i = __2__X60 ), 0 ) ), (& __0__V55 )) ) ,
# 533 "/home/claude/cfront-3/src/typ.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 535 "/home/claude/cfront-3/src/typ.cpp"
xx :
# 536 "/home/claude/cfront-3/src/typ.cpp"
switch (__1t -> base__4node ){ 
# 537 "/home/claude/cfront-3/src/typ.cpp"
case 97 :
# 538 "/home/claude/cfront-3/src/typ.cpp"
__1t = (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto xx ;
case 125 :
# 541 "/home/claude/cfront-3/src/typ.cpp"
case 158 :
# 542 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 543 "/home/claude/cfront-3/src/typ.cpp"
Pptr __3p ;

# 543 "/home/claude/cfront-3/src/typ.cpp"
__3p = (((struct ptr *)(((struct ptr *)__1t ))));
if ((__3p -> memof__3ptr == 0 )&& __3p -> ptname__3ptr ){ 
# 545 "/home/claude/cfront-3/src/typ.cpp"
Ptype __4tp ;

# 545 "/home/claude/cfront-3/src/typ.cpp"
__4tp = skiptypedefs__4typeFv ( __3p -> ptname__3ptr -> __O1__4expr.tp ) ;
switch (__4tp -> base__4node ){ 
# 547 "/home/claude/cfront-3/src/typ.cpp"
case 119 :
# 548 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 549 "/home/claude/cfront-3/src/typ.cpp"
__3p -> memof__3ptr = classtype__4typeFv ( __4tp ) ;
if (__3p -> typ__5pvtyp )
# 551 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 552 "/home/claude/cfront-3/src/typ.cpp"
Ptype __7t ;

# 552 "/home/claude/cfront-3/src/typ.cpp"
__7t = skiptypedefs__4typeFv ( __3p -> typ__5pvtyp ) ;
if (__7t && (__7t -> base__4node == 108 ))
# 554 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 555 "/home/claude/cfront-3/src/typ.cpp"
(((struct fct *)(((struct fct *)__7t ))))-> memof__3fct = __3p -> memof__3ptr ;
}
}
break ;
}
case 6 :
# 561 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 562 "/home/claude/cfront-3/src/typ.cpp"
__3p -> memof__3ptr = (((struct classdef *)(((struct classdef *)__4tp ))));
{ Ptype __6t ;
Pfct __6f ;

# 563 "/home/claude/cfront-3/src/typ.cpp"
__6t = skiptypedefs__4typeFv ( __3p -> typ__5pvtyp ) ;
__6f = (((struct fct *)(((struct fct *)__6t ))));
__6f -> memof__3fct = __3p -> memof__3ptr ;
break ;

# 566 "/home/claude/cfront-3/src/typ.cpp"
}
}
default :
# 569 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 569 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V56 ;

# 569 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"illegalZizedP toM %t::*", (const struct ea *)( ((& __0__V56 )-> __O1__2ea.p =
# 569 "/home/claude/cfront-3/src/typ.cpp"
((const void *)__4tp )), (& __0__V56 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 569 "/home/claude/cfront-3/src/typ.cpp"
ea *)ea0 ) ;
break ;
} }
}
__1t = __3p -> typ__5pvtyp ;
if (__1t -> base__4node == 97 ){ 
# 575 "/home/claude/cfront-3/src/typ.cpp"
Ptype __4tt ;

# 575 "/home/claude/cfront-3/src/typ.cpp"
__4tt = (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ;
if (__4tt -> base__4node == 108 )
# 577 "/home/claude/cfront-3/src/typ.cpp"
__3p -> typ__5pvtyp = __4tt ;
goto done ;
}
goto xx ;
}

# 583 "/home/claude/cfront-3/src/typ.cpp"
case 110 :
# 584 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 585 "/home/claude/cfront-3/src/typ.cpp"
Pvec __3v ;
Pexpr __3e ;

# 585 "/home/claude/cfront-3/src/typ.cpp"
__3v = (((struct vec *)(((struct vec *)__1t ))));
__3e = __3v -> dim__3vec ;
if (__3e ){ 
# 588 "/home/claude/cfront-3/src/typ.cpp"
Ptype __4et ;
__3v -> dim__3vec = (__3e = typ__4exprFP5table ( __3e , __1tbl ) );
if (skiptypedefs__4typeFv ( __3e -> __O1__4expr.tp ) -> base__4node == 119 ){ 
# 591 "/home/claude/cfront-3/src/typ.cpp"
__3e = check_cond__FP4exprUcP5table ( __3e , (unsigned char )111 , __1tbl )
# 591 "/home/claude/cfront-3/src/typ.cpp"
;
__3v -> dim__3vec = __3e ;
}
__4et = __3e -> __O1__4expr.tp ;
if (( kind__4typeFUcN21 ( __4et , ((unsigned char )0 ), (unsigned char )'I' , (unsigned char )1 ) )
# 595 "/home/claude/cfront-3/src/typ.cpp"
== 'A' ){ 
# 596 "/home/claude/cfront-3/src/typ.cpp"
error__FPCc ( (const char *)"UN in array dimension") ;
}
else { 
# 599 "/home/claude/cfront-3/src/typ.cpp"
long long __5i ;
Neval = 0 ;
__5i = eval__4exprFv ( __3e ) ;
if (Neval == 0 ){ 
# 603 "/home/claude/cfront-3/src/typ.cpp"
if (largest_int < __5i )
# 604 "/home/claude/cfront-3/src/typ.cpp"
error__FPCc ( (const char *)"array dimension too large") ;
# 604 "/home/claude/cfront-3/src/typ.cpp"

# 605 "/home/claude/cfront-3/src/typ.cpp"
__3v -> size__3vec = (((int )__5i ));

# 607 "/home/claude/cfront-3/src/typ.cpp"
if (__3v -> dim__3vec && (__3v -> dim__3vec -> permanent__4node == 0 ))del__4exprFv ( __3v -> dim__3vec ) ;
__3v -> dim__3vec = 0 ;
}

# 611 "/home/claude/cfront-3/src/typ.cpp"
if (new_type ){ 
# 612 "/home/claude/cfront-3/src/typ.cpp"
if (Neval )
# 613 "/home/claude/cfront-3/src/typ.cpp"
;
else if (__5i == 0 )
# 615 "/home/claude/cfront-3/src/typ.cpp"
__3v -> dim__3vec = zero ;
else if (__5i < 0 ){ 
# 617 "/home/claude/cfront-3/src/typ.cpp"
error__FPCc ( (const char *)"negative array dimension") ;
__5i = 1 ;
}
}
else { 
# 621 "/home/claude/cfront-3/src/typ.cpp"
const void *__2__X61 ;

# 622 "/home/claude/cfront-3/src/typ.cpp"
if (Neval )
# 623 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 623 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V57 ;

# 623 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s", (const struct ea *)( (__2__X61 = (const void
# 623 "/home/claude/cfront-3/src/typ.cpp"
*)Neval ), ( ((& __0__V57 )-> __O1__2ea.p = __2__X61 ), (& __0__V57 )) ) , (const struct ea *)ea0 , (const
# 623 "/home/claude/cfront-3/src/typ.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (__5i == 0 ){ 
# 625 "/home/claude/cfront-3/src/typ.cpp"
error__FPCc ( (const char *)"array dimension == 0") ;
# 625 "/home/claude/cfront-3/src/typ.cpp"

# 626 "/home/claude/cfront-3/src/typ.cpp"
__3v -> dim__3vec = __3e ;
}
else if (__5i < 0 ){ 
# 629 "/home/claude/cfront-3/src/typ.cpp"
error__FPCc ( (const char *)"negative array dimension") ;
__5i = 1 ;
}
}
}
}
__1t = __3v -> typ__5pvtyp ;
llx :
# 637 "/home/claude/cfront-3/src/typ.cpp"
switch (__1t -> base__4node ){ 
# 638 "/home/claude/cfront-3/src/typ.cpp"
case 97 :
# 639 "/home/claude/cfront-3/src/typ.cpp"
__1t = (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto llx ;
case 108 :
# 642 "/home/claude/cfront-3/src/typ.cpp"
__3v -> typ__5pvtyp = __1t ;
break ;
case 110 :
# 645 "/home/claude/cfront-3/src/typ.cpp"
if (((((struct vec *)(((struct vec *)__1t ))))-> dim__3vec == 0 )&& ((((struct vec *)(((struct vec *)__1t ))))-> size__3vec == 0 ))
# 646 "/home/claude/cfront-3/src/typ.cpp"
error__FPCc ( (const char
# 646 "/home/claude/cfront-3/src/typ.cpp"
*)"null dimension (something like [][] seen)") ;
}
goto xx ;
}

# 651 "/home/claude/cfront-3/src/typ.cpp"
case 108 :
# 652 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 653 "/home/claude/cfront-3/src/typ.cpp"
Pfct __3f ;

# 653 "/home/claude/cfront-3/src/typ.cpp"
__3f = (((struct fct *)(((struct fct *)__1t ))));

# 656 "/home/claude/cfront-3/src/typ.cpp"
if (__3f -> argtype__3fct )
# 657 "/home/claude/cfront-3/src/typ.cpp"
dargs__FP4nameP3fctP5table ( (struct name *)0 , __3f , __1tbl ) ;
{ { Pname __3n ;

# 658 "/home/claude/cfront-3/src/typ.cpp"
__3n = __3f -> argtype__3fct ;

# 658 "/home/claude/cfront-3/src/typ.cpp"
for(;__3n ;__3n = __3n -> __O1__4name.n_list ) { 
# 659 "/home/claude/cfront-3/src/typ.cpp"
Ptype __4t ;

# 659 "/home/claude/cfront-3/src/typ.cpp"
__4t = __3n -> __O1__4expr.tp ;
dcl__4typeFP5table ( __3n -> __O1__4expr.tp , __1tbl ) ;
while (__4t -> base__4node == 97 )
# 662 "/home/claude/cfront-3/src/typ.cpp"
__4t = (((struct basetype *)(((struct basetype *)__4t ))))-> b_name__8basetype -> __O1__4expr.tp ;
if (__4t -> base__4node == 110 )
# 664 "/home/claude/cfront-3/src/typ.cpp"
__3n -> __O1__4expr.tp = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (((struct vec *)(((struct
# 664 "/home/claude/cfront-3/src/typ.cpp"
vec *)__4t ))))-> typ__5pvtyp ) ;
}
{ Pname __3cn ;

# 667 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__0__X62 ;

# 666 "/home/claude/cfront-3/src/typ.cpp"
__3cn = is_cl_obj__4typeFv ( __3f -> returns__3fct ) ;
if (__3cn && ( (__0__X62 = (((struct classdef *)(((struct classdef *)__3cn -> __O1__4expr.tp ))))), ( __0__X62 -> c_itor__8classdef ) ) )
# 668 "/home/claude/cfront-3/src/typ.cpp"
make_res__FP3fct ( __3f )
# 668 "/home/claude/cfront-3/src/typ.cpp"
;
else if (__3f -> f_this__3fct == 0 )
# 670 "/home/claude/cfront-3/src/typ.cpp"
__3f -> f_args__3fct = __3f -> argtype__3fct ;

# 672 "/home/claude/cfront-3/src/typ.cpp"
__1t = __3f -> returns__3fct ;
goto xx ;

# 673 "/home/claude/cfront-3/src/typ.cpp"
}

# 673 "/home/claude/cfront-3/src/typ.cpp"
}

# 673 "/home/claude/cfront-3/src/typ.cpp"
}
}

# 676 "/home/claude/cfront-3/src/typ.cpp"
case 114 :
# 677 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 678 "/home/claude/cfront-3/src/typ.cpp"
Pbase __3f ;
Pexpr __3e ;
long long __3i ;
Ptype __3et ;

# 678 "/home/claude/cfront-3/src/typ.cpp"
__3f = (((struct basetype *)(((struct basetype *)__1t ))));
__3e = (((struct expr *)(((struct expr *)__3f -> b_name__8basetype ))));

# 682 "/home/claude/cfront-3/src/typ.cpp"
__3e = typ__4exprFP5table ( __3e , __1tbl ) ;
__3f -> b_name__8basetype = (((struct name *)(((struct name *)__3e ))));
__3et = __3e -> __O1__4expr.tp ;
if (( kind__4typeFUcN21 ( __3et , ((unsigned char )0 ), (unsigned char )'I' , (unsigned char )1 ) )
# 685 "/home/claude/cfront-3/src/typ.cpp"
== 'A' ){ 
# 686 "/home/claude/cfront-3/src/typ.cpp"
error__FPCc ( (const char *)"UN in field size") ;
__3i = 1 ;
}
else { 
# 689 "/home/claude/cfront-3/src/typ.cpp"
const void *__2__X63 ;

# 689 "/home/claude/cfront-3/src/typ.cpp"
const void *__2__X64 ;

# 690 "/home/claude/cfront-3/src/typ.cpp"
Neval = 0 ;
__3i = eval__4exprFv ( __3e ) ;
if (Neval )
# 693 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 693 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V58 ;

# 693 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s", (const struct ea *)( (__2__X63 = (const void
# 693 "/home/claude/cfront-3/src/typ.cpp"
*)Neval ), ( ((& __0__V58 )-> __O1__2ea.p = __2__X63 ), (& __0__V58 )) ) , (const struct ea *)ea0 , (const
# 693 "/home/claude/cfront-3/src/typ.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (__3i < 0 ){ 
# 695 "/home/claude/cfront-3/src/typ.cpp"
error__FPCc ( (const char *)"negative field size") ;
# 695 "/home/claude/cfront-3/src/typ.cpp"

# 696 "/home/claude/cfront-3/src/typ.cpp"
__3i = 1 ;
}
else if ((tsizeof__4typeFi ( __3f -> __O1__8basetype.b_fieldtype , 0 ) * BI_IN_BYTE )< __3i )
# 699 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 699 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V59 ;

# 699 "/home/claude/cfront-3/src/typ.cpp"
error__FPCcRC2eaN32 ( (const char *)"field size > sizeof(%t)", (const struct ea *)( (__2__X64 = (const void
# 699 "/home/claude/cfront-3/src/typ.cpp"
*)__3f -> __O1__8basetype.b_fieldtype ), ( ((& __0__V59 )-> __O1__2ea.p = __2__X64 ), (& __0__V59 )) ) , (const struct ea *)ea0 ,
# 699 "/home/claude/cfront-3/src/typ.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__3e && (__3e -> permanent__4node == 0 ))del__4exprFv ( __3e ) ;
}
__3f -> b_bits__8basetype = (((int )__3i ));
__3f -> b_name__8basetype = 0 ;
break ;
}
}
done :
# 708 "/home/claude/cfront-3/src/typ.cpp"
processing_sizeof = __1os ;
return ;
}

# 493 "/home/claude/cfront-3/src/cfront.h"

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 713 "/home/claude/cfront-3/src/typ.cpp"
static bit fm_same_class__FP8classdefT1 (Pclass __1c1 , Pclass __1c2 )
# 723 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 723 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X65 ;

# 723 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X66 ;

# 727 "/home/claude/cfront-3/src/typ.cpp"
if (( (__1__X65 = __1c1 ), ( (__1__X66 = __1c2 ), ( ((__1__X65 == __1__X66 )?1 :((__1__X65 && __1__X66 )?(((int )same_class__8classdefFP8classdefi ( __1__X65 , __1__X66 ,
# 727 "/home/claude/cfront-3/src/typ.cpp"
0 ) )):0 ))) ) ) )return (unsigned char )1 ;

# 729 "/home/claude/cfront-3/src/typ.cpp"
{ int __1t1 ;
int __1t2 ;

# 729 "/home/claude/cfront-3/src/typ.cpp"
__1t1 = __1c1 -> class_base__8classdef ;
__1t2 = __1c2 -> class_base__8classdef ;

# 732 "/home/claude/cfront-3/src/typ.cpp"
if ((((__1t1 == 5)|| (__1t1 == 2))&& ((__1t2 == 5)|| (__1t2 == 2)))&& (strcmp ( __1c1 -> string__8classdef , __1c2 -> string__8classdef )
# 732 "/home/claude/cfront-3/src/typ.cpp"
== 0 ))
# 735 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;

# 737 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )0 ;

# 737 "/home/claude/cfront-3/src/typ.cpp"
}
}

# 740 "/home/claude/cfront-3/src/typ.cpp"
bit const_problem = 0 ;
bit return_error = 0 ;
static bit pt_ptm ;
static bit pt_over ;
int Vcheckerror = 0 ;
extern int template_hier ;

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 335 "/home/claude/cfront-3/src/cfront.h"
Ptype skiptypedefs__4typeFRUc (struct type *__0this , bit *__1isconst );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );

# 460 "/home/claude/cfront-3/src/cfront.h"
bit has_base__8classdefFP8classdefiT2 (struct classdef *__0this , Pclass __1cl , int __1level , int __1ccflag );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 463 "/home/claude/cfront-3/src/cfront.h"
Pclass is_base__8classdefFPCcPUci (struct classdef *__0this , const char *, TOK *, int __1level );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 747 "/home/claude/cfront-3/src/typ.cpp"
bit check__4typeFP4typeUcT2 (register struct type *__0this , Ptype __1t , TOK __1oper , bit __1level )
# 769 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 771 "/home/claude/cfront-3/src/typ.cpp"
Ptype __1t1 ;

# 771 "/home/claude/cfront-3/src/typ.cpp"
Ptype __1t2 ;
bit __1cnst1 ;

# 772 "/home/claude/cfront-3/src/typ.cpp"
bit __1cnst2 ;
TOK __1b1 ;

# 773 "/home/claude/cfront-3/src/typ.cpp"
TOK __1b2 ;
bit __1vv ;

# 774 "/home/claude/cfront-3/src/typ.cpp"
bit __1over ;

# 774 "/home/claude/cfront-3/src/typ.cpp"
bit __1strict_any_check ;
TOK __1rec_oper ;

# 777 "/home/claude/cfront-3/src/typ.cpp"
TOK __1rec_oper0 ;

# 771 "/home/claude/cfront-3/src/typ.cpp"
__1t1 = __0this ;

# 771 "/home/claude/cfront-3/src/typ.cpp"
__1t2 = __1t ;
__1cnst1 = 0 ;

# 772 "/home/claude/cfront-3/src/typ.cpp"
__1cnst2 = 0 ;

# 774 "/home/claude/cfront-3/src/typ.cpp"
__1vv = 0 ;

# 774 "/home/claude/cfront-3/src/typ.cpp"
__1over = 0 ;

# 774 "/home/claude/cfront-3/src/typ.cpp"
__1strict_any_check = 0 ;

# 780 "/home/claude/cfront-3/src/typ.cpp"
if ((__1t1 == 0 )|| (__1t2 == 0 ))
# 781 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 781 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V67 ;

# 781 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V68 ;

# 781 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V69 ;

# 781 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"check(%p,%p,%d)", (const struct ea *)( ((&
# 781 "/home/claude/cfront-3/src/typ.cpp"
__0__V67 )-> __O1__2ea.p = ((const void *)__1t1 )), (& __0__V67 )) , (const struct ea *)( ((& __0__V68 )-> __O1__2ea.p =
# 781 "/home/claude/cfront-3/src/typ.cpp"
((const void *)__1t2 )), (& __0__V68 )) , (const struct ea *)( (( ((& __0__V69 )-> __O1__2ea.i = ((unsigned
# 781 "/home/claude/cfront-3/src/typ.cpp"
long )__1oper )), 0 ) ), (& __0__V69 )) , (const struct ea *)ea0 ) ;
} 
# 783 "/home/claude/cfront-3/src/typ.cpp"
if (__1t1 == __1t2 )
# 784 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )0 ;

# 786 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 787 "/home/claude/cfront-3/src/typ.cpp"
case 77 :
# 788 "/home/claude/cfront-3/src/typ.cpp"
__1vv = 1 ;
Vcheckerror = 0 ;
__1oper = 0 ;
break ;
case 76 :
# 793 "/home/claude/cfront-3/src/typ.cpp"
__1over = 1 ;
__1oper = 0 ;
break ;
case 204 :
# 797 "/home/claude/cfront-3/src/typ.cpp"
__1over = 1 ;

# 799 "/home/claude/cfront-3/src/typ.cpp"
case 255 :
# 800 "/home/claude/cfront-3/src/typ.cpp"
__1oper = 0 ;
__1strict_any_check = 1 ;
break ;
}

# 805 "/home/claude/cfront-3/src/typ.cpp"
if (__1level == 0 ){ 
# 806 "/home/claude/cfront-3/src/typ.cpp"
const_problem = 0 ;
return_error = 0 ;
pt_ptm = 0 ;
pt_over = __1over ;
}

# 812 "/home/claude/cfront-3/src/typ.cpp"
__1rec_oper = (__1strict_any_check ?(((unsigned int )(__1over ?204 :255 ))):(((unsigned int )__1oper )));
__1rec_oper0 = (__1strict_any_check ?(__1over ?204 :255 ):0 );

# 815 "/home/claude/cfront-3/src/typ.cpp"
__1t1 = skiptypedefs__4typeFRUc ( __1t1 , (bit *)(& __1cnst1 )) ;

# 821 "/home/claude/cfront-3/src/typ.cpp"
if ((__1t1 -> base__4node == 141 )|| (__1t2 -> base__4node == 141 ))
# 822 "/home/claude/cfront-3/src/typ.cpp"
if ((__1over == 0 )|| (__1strict_any_check == 0 ))
# 823 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )(__1strict_any_check ?(__1t1 !=
# 823 "/home/claude/cfront-3/src/typ.cpp"
__1t2 ):0 );

# 825 "/home/claude/cfront-3/src/typ.cpp"
__1t2 = skiptypedefs__4typeFRUc ( __1t2 , (bit *)(& __1cnst2 )) ;

# 827 "/home/claude/cfront-3/src/typ.cpp"
if (__1t1 == __1t2 )
# 828 "/home/claude/cfront-3/src/typ.cpp"
goto const_check ;

# 830 "/home/claude/cfront-3/src/typ.cpp"
__1b1 = __1t1 -> base__4node ;
__1b2 = __1t2 -> base__4node ;

# 833 "/home/claude/cfront-3/src/typ.cpp"
if (__1b1 != __1b2 ){ 
# 834 "/home/claude/cfront-3/src/typ.cpp"
switch (__1b1 ){ 
# 835 "/home/claude/cfront-3/src/typ.cpp"
case 125 :
# 836 "/home/claude/cfront-3/src/typ.cpp"
switch (__1b2 ){ 
# 837 "/home/claude/cfront-3/src/typ.cpp"
case 110 :
# 838 "/home/claude/cfront-3/src/typ.cpp"
if (((((__1level > 0 )|| (((__1oper == 0 )||
# 838 "/home/claude/cfront-3/src/typ.cpp"
(__1oper == 254 ))&& (__1over == 0 )))|| (((struct ptr *)(((struct ptr *)__1t1 ))))-> memof__3ptr )|| (((struct ptr *)(((struct ptr *)__1t1 ))))-> ptname__3ptr )|| check__4typeFP4typeUcT2 ( (((struct
# 838 "/home/claude/cfront-3/src/typ.cpp"
ptr *)(((struct ptr *)__1t1 ))))-> typ__5pvtyp , (((struct vec *)(((struct vec *)__1t2 ))))-> typ__5pvtyp , __1rec_oper , (unsigned char )(__1level + 1 )) )
# 851 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned
# 851 "/home/claude/cfront-3/src/typ.cpp"
char )1 ;

# 853 "/home/claude/cfront-3/src/typ.cpp"
goto const_check ;

# 855 "/home/claude/cfront-3/src/typ.cpp"
case 108 :
# 856 "/home/claude/cfront-3/src/typ.cpp"
if ((__1level > 0 )|| check__4typeFP4typeUcT2 ( (((struct ptr *)(((struct ptr *)__1t1 ))))-> typ__5pvtyp , __1t2 , __1rec_oper , (unsigned char )(__1level +
# 856 "/home/claude/cfront-3/src/typ.cpp"
1 )) )
# 861 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
goto const_check ;
}
break ;

# 866 "/home/claude/cfront-3/src/typ.cpp"
case 108 :
# 867 "/home/claude/cfront-3/src/typ.cpp"
if (__1b2 == 125 ){ 
# 868 "/home/claude/cfront-3/src/typ.cpp"
if ((__1level > 0 )|| check__4typeFP4typeUcT2 ( __1t1 , (((struct ptr *)(((struct ptr *)__1t2 ))))-> typ__5pvtyp , __1rec_oper ,
# 868 "/home/claude/cfront-3/src/typ.cpp"
(unsigned char )(__1level + 1 )) )
# 873 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
goto const_check ;
}
break ;

# 878 "/home/claude/cfront-3/src/typ.cpp"
case 110 :
# 879 "/home/claude/cfront-3/src/typ.cpp"
if (__1b2 == 125 ){ 
# 880 "/home/claude/cfront-3/src/typ.cpp"
if (((((__1level > 0 )|| (((__1oper == 0 )|| (__1oper == 254 ))&& (__1over == 0 )))|| (((struct
# 880 "/home/claude/cfront-3/src/typ.cpp"
ptr *)(((struct ptr *)__1t2 ))))-> memof__3ptr )|| (((struct ptr *)(((struct ptr *)__1t2 ))))-> ptname__3ptr )|| check__4typeFP4typeUcT2 ( (((struct vec *)(((struct vec *)__1t1 ))))-> typ__5pvtyp , (((struct ptr *)(((struct
# 880 "/home/claude/cfront-3/src/typ.cpp"
ptr *)__1t2 ))))-> typ__5pvtyp , __1rec_oper , (unsigned char )(__1level + 1 )) )
# 893 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;

# 895 "/home/claude/cfront-3/src/typ.cpp"
goto const_check ;
}
break ;
}

# 900 "/home/claude/cfront-3/src/typ.cpp"
if (__1level > 0 ){ 
# 901 "/home/claude/cfront-3/src/typ.cpp"
if ((((__1oper != 0 )&& (__1oper != 254 ))&& (__1b1 == 38 ))&& (__1level == 1 )){ 
# 902 "/home/claude/cfront-3/src/typ.cpp"
if (__1b2 ==
# 902 "/home/claude/cfront-3/src/typ.cpp"
108 ){ 
# 903 "/home/claude/cfront-3/src/typ.cpp"
Pfct __5f ;

# 903 "/home/claude/cfront-3/src/typ.cpp"
__5f = (((struct fct *)(((struct fct *)__1t2 ))));
if (__5f -> memof__3fct && (__5f -> f_static__3fct == 0 ))
# 905 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
}
goto const_check ;
}
return (unsigned char )1 ;
}

# 912 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 913 "/home/claude/cfront-3/src/typ.cpp"
case 0 :
# 914 "/home/claude/cfront-3/src/typ.cpp"
case 254 :
# 915 "/home/claude/cfront-3/src/typ.cpp"
if ((((__1b2 == 138 )&& (__1b1 == 21 ))&& ((((struct basetype *)(((struct basetype *)__1t1 ))))-> b_unsigned__8basetype == 0 ))||
# 915 "/home/claude/cfront-3/src/typ.cpp"
(((__1b1 == 138 )&& (__1b2 == 21 ))&& ((((struct basetype *)(((struct basetype *)__1t2 ))))-> b_unsigned__8basetype == 0 )))
# 920 "/home/claude/cfront-3/src/typ.cpp"
goto const_check ;
return (unsigned char )1 ;
case 136 :
# 923 "/home/claude/cfront-3/src/typ.cpp"
case 70 :
# 924 "/home/claude/cfront-3/src/typ.cpp"
case 28 :
# 925 "/home/claude/cfront-3/src/typ.cpp"
case 78 :
# 926 "/home/claude/cfront-3/src/typ.cpp"
switch (__1b1 ){ 
# 927 "/home/claude/cfront-3/src/typ.cpp"
case 138 :
# 928 "/home/claude/cfront-3/src/typ.cpp"
case 5 :
# 929 "/home/claude/cfront-3/src/typ.cpp"
case 29 :
# 930 "/home/claude/cfront-3/src/typ.cpp"
case 21 :
# 931 "/home/claude/cfront-3/src/typ.cpp"
case 22 :
# 932 "/home/claude/cfront-3/src/typ.cpp"
case 122 :
# 933 "/home/claude/cfront-3/src/typ.cpp"
case 15 :
# 934 "/home/claude/cfront-3/src/typ.cpp"
case
# 934 "/home/claude/cfront-3/src/typ.cpp"
11 :
# 935 "/home/claude/cfront-3/src/typ.cpp"
case 181 :
# 936 "/home/claude/cfront-3/src/typ.cpp"
case 114 :
# 937 "/home/claude/cfront-3/src/typ.cpp"
switch (__1b2 ){ 
# 938 "/home/claude/cfront-3/src/typ.cpp"
case 22 :
# 939 "/home/claude/cfront-3/src/typ.cpp"
case 122 :
# 940 "/home/claude/cfront-3/src/typ.cpp"
case 15 :
# 941 "/home/claude/cfront-3/src/typ.cpp"
case 11 :
# 942 "/home/claude/cfront-3/src/typ.cpp"
case 181 :
# 943 "/home/claude/cfront-3/src/typ.cpp"
case 121 :
# 944 "/home/claude/cfront-3/src/typ.cpp"
case 138 :
# 945 "/home/claude/cfront-3/src/typ.cpp"
case 5 :
# 946 "/home/claude/cfront-3/src/typ.cpp"
case 29 :
# 947 "/home/claude/cfront-3/src/typ.cpp"
case
# 947 "/home/claude/cfront-3/src/typ.cpp"
21 :
# 948 "/home/claude/cfront-3/src/typ.cpp"
case 114 :
# 949 "/home/claude/cfront-3/src/typ.cpp"
if (__1oper == 78 )
# 950 "/home/claude/cfront-3/src/typ.cpp"
Nstd ++ ;
goto const_check ;
}
return (unsigned char )1 ;
case 125 :
# 955 "/home/claude/cfront-3/src/typ.cpp"
case 110 :
# 956 "/home/claude/cfront-3/src/typ.cpp"
if (__1b2 == 138 ){ 
# 957 "/home/claude/cfront-3/src/typ.cpp"
if (__1oper == 78 )
# 958 "/home/claude/cfront-3/src/typ.cpp"
Nstd ++ ;
goto const_check ;
}
case 158 :
# 962 "/home/claude/cfront-3/src/typ.cpp"
case 119 :
# 963 "/home/claude/cfront-3/src/typ.cpp"
case 108 :
# 964 "/home/claude/cfront-3/src/typ.cpp"
case 121 :
# 965 "/home/claude/cfront-3/src/typ.cpp"
default :
# 966 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
}
}
goto const_check ;
}

# 972 "/home/claude/cfront-3/src/typ.cpp"
switch (__1b1 ){ 
# 973 "/home/claude/cfront-3/src/typ.cpp"
case 110 :
# 974 "/home/claude/cfront-3/src/typ.cpp"
if (((((struct vec *)(((struct vec *)__1t1 ))))-> size__3vec != (((struct vec *)(((struct vec *)__1t2 ))))-> size__3vec )&& ((__1level > 0 )||
# 974 "/home/claude/cfront-3/src/typ.cpp"
(((((__1oper == 0 )|| (__1oper == 254 ))&& (__1strict_any_check == 0 ))&& (((struct vec *)(((struct vec *)__1t1 ))))-> size__3vec )&& (((struct vec *)(((struct vec *)__1t2 ))))-> size__3vec )))
# 989 "/home/claude/cfront-3/src/typ.cpp"
return
# 989 "/home/claude/cfront-3/src/typ.cpp"
(unsigned char )1 ;

# 991 "/home/claude/cfront-3/src/typ.cpp"
if (check__4typeFP4typeUcT2 ( (((struct vec *)(((struct vec *)__1t1 ))))-> typ__5pvtyp , (((struct vec *)(((struct vec *)__1t2 ))))-> typ__5pvtyp , __1rec_oper , (unsigned char )(__1level +
# 991 "/home/claude/cfront-3/src/typ.cpp"
1 )) )
# 992 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
break ;

# 995 "/home/claude/cfront-3/src/typ.cpp"
case 125 :
# 996 "/home/claude/cfront-3/src/typ.cpp"
case 158 :
# 997 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 998 "/home/claude/cfront-3/src/typ.cpp"
Pptr __3p1 ;
Pptr __3p2 ;

# 1000 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X74 ;

# 1000 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X75 ;

# 998 "/home/claude/cfront-3/src/typ.cpp"
__3p1 = (((struct ptr *)(((struct ptr *)__1t1 ))));
__3p2 = (((struct ptr *)(((struct ptr *)__1t2 ))));

# 1001 "/home/claude/cfront-3/src/typ.cpp"
if ((__3p1 -> ptname__3ptr && __3p2 -> ptname__3ptr )&& ((! __3p1 -> memof__3ptr )|| (! __3p2 -> memof__3ptr )))
# 1002 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
# 1002 "/home/claude/cfront-3/src/typ.cpp"

# 1004 "/home/claude/cfront-3/src/typ.cpp"
if (! ( (__1__X74 = __3p1 -> memof__3ptr ), ( (__1__X75 = __3p2 -> memof__3ptr ), ( ((__1__X74 == __1__X75 )?1 :((__1__X74 && __1__X75 )?(((int
# 1004 "/home/claude/cfront-3/src/typ.cpp"
)same_class__8classdefFP8classdefi ( __1__X74 , __1__X75 , 0 ) )):0 ))) ) ) ){ 
# 1004 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X76 ;

# 1004 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X77 ;

# 1004 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X78 ;

# 1004 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X79 ;

# 1010 "/home/claude/cfront-3/src/typ.cpp"
if (((__3p1 -> memof__3ptr == 0 )&& __3p1 -> ptname__3ptr )|| ((__3p2 -> memof__3ptr == 0 )&& __3p2 -> ptname__3ptr ))
# 1015 "/home/claude/cfront-3/src/typ.cpp"
pt_ptm = 1 ;
else 
# 1017 "/home/claude/cfront-3/src/typ.cpp"
if (((__3p1 -> memof__3ptr == 0 )|| (__3p2 -> memof__3ptr == 0 ))|| ((baseof__8classdefFP8classdef ( __3p1 -> memof__3ptr , __3p2 -> memof__3ptr ) ==
# 1017 "/home/claude/cfront-3/src/typ.cpp"
0 )&& (( (__1__X76 = __3p1 -> memof__3ptr ), ( (__1__X77 = __3p2 -> memof__3ptr ), ( ((__1__X76 == __1__X77 )?1 :((__1__X76 && __1__X77 )?(((int )same_class__8classdefFP8classdefi (
# 1017 "/home/claude/cfront-3/src/typ.cpp"
__1__X76 , __1__X77 , 1 ) )):0 ))) ) ) == 0 )))
# 1025 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;

# 1027 "/home/claude/cfront-3/src/typ.cpp"
if (((pt_ptm == 0 )&& ((__1oper == 0 )|| (__1oper == 254 )))&& (( (__1__X78 = __3p1 -> memof__3ptr ), ( (__1__X79 = __3p2 ->
# 1027 "/home/claude/cfront-3/src/typ.cpp"
memof__3ptr ), ( ((__1__X78 == __1__X79 )?1 :((__1__X78 && __1__X79 )?(((int )same_class__8classdefFP8classdefi ( __1__X78 , __1__X79 , 0 ) )):0 ))) ) ) == 0 ))
# 1029 "/home/claude/cfront-3/src/typ.cpp"
return
# 1029 "/home/claude/cfront-3/src/typ.cpp"
(unsigned char )1 ;

# 1031 "/home/claude/cfront-3/src/typ.cpp"
if (__1oper == 78 )
# 1032 "/home/claude/cfront-3/src/typ.cpp"
Nstd ++ ;
}

# 1066 "/home/claude/cfront-3/src/typ.cpp"
if (check__4typeFP4typeUcT2 ( __3p1 -> typ__5pvtyp , __3p2 -> typ__5pvtyp , __1rec_oper , (unsigned char )(__1level + 1 )) )
# 1067 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char
# 1067 "/home/claude/cfront-3/src/typ.cpp"
)1 ;

# 1069 "/home/claude/cfront-3/src/typ.cpp"
break ;
}

# 1072 "/home/claude/cfront-3/src/typ.cpp"
case 108 :
# 1073 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 1074 "/home/claude/cfront-3/src/typ.cpp"
Pfct __3f1 ;
Pfct __3f2 ;
Pname __3a1 ;
Pname __3a2 ;
TOK __3k1 ;
TOK __3k2 ;
int __3n1 ;
int __3n2 ;

# 1082 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X80 ;

# 1082 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X81 ;

# 1074 "/home/claude/cfront-3/src/typ.cpp"
__3f1 = (((struct fct *)(((struct fct *)__1t1 ))));
__3f2 = (((struct fct *)(((struct fct *)__1t2 ))));
__3a1 = __3f1 -> argtype__3fct ;
__3a2 = __3f2 -> argtype__3fct ;
__3k1 = __3f1 -> nargs_known__3fct ;
__3k2 = __3f2 -> nargs_known__3fct ;
__3n1 = __3f1 -> nargs__3fct ;
__3n2 = __3f2 -> nargs__3fct ;

# 1084 "/home/claude/cfront-3/src/typ.cpp"
if ((! ( (__1__X80 = __3f1 -> memof__3fct ), ( (__1__X81 = __3f2 -> memof__3fct ), ( ((__1__X80 == __1__X81 )?1 :((__1__X80 && __1__X81 )?(((int
# 1084 "/home/claude/cfront-3/src/typ.cpp"
)same_class__8classdefFP8classdefi ( __1__X80 , __1__X81 , 0 ) )):0 ))) ) ) )&& (pt_ptm == 0 )){ 
# 1084 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X82 ;

# 1084 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X83 ;

# 1085 "/home/claude/cfront-3/src/typ.cpp"
if ((__3f1 -> memof__3fct == 0 )&& __3f2 -> f_static__3fct )
# 1086 "/home/claude/cfront-3/src/typ.cpp"
goto sss ;
if (__1vv == 0 )
# 1088 "/home/claude/cfront-3/src/typ.cpp"
if (((__3f1 -> memof__3fct == 0 )|| (__3f2 -> memof__3fct == 0 ))|| (((__1level > 1 )|| (baseof__8classdefFP8classdef ( __3f1 -> memof__3fct ,
# 1088 "/home/claude/cfront-3/src/typ.cpp"
__3f2 -> memof__3fct ) == 0 ))&& (( (__1__X82 = __3f1 -> memof__3fct ), ( (__1__X83 = __3f2 -> memof__3fct ), ( ((__1__X82 ==
# 1088 "/home/claude/cfront-3/src/typ.cpp"
__1__X83 )?1 :((__1__X82 && __1__X83 )?(((int )same_class__8classdefFP8classdefi ( __1__X82 , __1__X83 , 0 ) )):0 ))) ) ) == 0 )))
# 1101 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
# 1101 "/home/claude/cfront-3/src/typ.cpp"

# 1102 "/home/claude/cfront-3/src/typ.cpp"
if (__1oper == 78 )
# 1103 "/home/claude/cfront-3/src/typ.cpp"
Nstd ++ ;
sss :;
}

# 1107 "/home/claude/cfront-3/src/typ.cpp"
if (__3k1 != __3k2 )
# 1108 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;

# 1110 "/home/claude/cfront-3/src/typ.cpp"
if (((__3n1 != __3n2 )&& __3k1 )&& __3k2 ){ 
# 1111 "/home/claude/cfront-3/src/typ.cpp"
goto aaa ;
}
else if (__3a1 && __3a2 ){ 
# 1114 "/home/claude/cfront-3/src/typ.cpp"
while (__3a1 && __3a2 ){ 
# 1115 "/home/claude/cfront-3/src/typ.cpp"
if (check__4typeFP4typeUcT2 ( __3a1 -> __O1__4expr.tp , __3a2 -> __O1__4expr.tp , __1rec_oper0 ,
# 1115 "/home/claude/cfront-3/src/typ.cpp"
(unsigned char )(__1level + 1 )) )
# 1116 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
__3a1 = __3a1 -> __O1__4name.n_list ;
__3a2 = __3a2 -> __O1__4name.n_list ;
}
if (__3a1 || __3a2 )
# 1121 "/home/claude/cfront-3/src/typ.cpp"
goto aaa ;
}
else if (__3a1 || __3a2 ){ 
# 1124 "/home/claude/cfront-3/src/typ.cpp"
aaa :
# 1125 "/home/claude/cfront-3/src/typ.cpp"
if (__3k1 == 155 ){ 
# 1126 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 1127 "/home/claude/cfront-3/src/typ.cpp"
case 0 :
# 1128 "/home/claude/cfront-3/src/typ.cpp"
case 254 :
# 1129 "/home/claude/cfront-3/src/typ.cpp"
if (__3a2 && (__3k2 ==
# 1129 "/home/claude/cfront-3/src/typ.cpp"
0 ))
# 1130 "/home/claude/cfront-3/src/typ.cpp"
break ;
return (unsigned char )1 ;
case 70 :
# 1133 "/home/claude/cfront-3/src/typ.cpp"
if (__3a2 && (__3k2 == 0 ))
# 1134 "/home/claude/cfront-3/src/typ.cpp"
break ;
return (unsigned char )1 ;
case 136 :
# 1137 "/home/claude/cfront-3/src/typ.cpp"
if (__3a1 )
# 1138 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
break ;
case 78 :
# 1141 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
}
}
else if (__3k2 == 155 ){ 
# 1145 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
}
else if (__3k1 || __3k2 ){ 
# 1148 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
}
}

# 1152 "/home/claude/cfront-3/src/typ.cpp"
__1cnst1 = __3f2 -> f_const__3fct ;
__1cnst2 = __3f1 -> f_const__3fct ;

# 1155 "/home/claude/cfront-3/src/typ.cpp"
if (check__4typeFP4typeUcT2 ( __3f1 -> returns__3fct , __3f2 -> returns__3fct , __1rec_oper0 , (unsigned char )(__1level + 1 )) ){ 
# 1156 "/home/claude/cfront-3/src/typ.cpp"
if (__1vv &&
# 1156 "/home/claude/cfront-3/src/typ.cpp"
(__1cnst1 == __1cnst2 )){ 
# 1157 "/home/claude/cfront-3/src/typ.cpp"
bit __5fail ;
Ptype __5t1 ;
Ptype __5t2 ;

# 1157 "/home/claude/cfront-3/src/typ.cpp"
__5fail = 1 ;
__5t1 = __3f1 -> returns__3fct ;
__5t2 = __3f2 -> returns__3fct ;
if ((is_ptr__4typeFv ( __5t1 ) && is_ptr__4typeFv ( __5t2 ) )|| (is_ref__4typeFv ( __5t1 ) && is_ref__4typeFv ( __5t2 ) ))
# 1161 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 1162 "/home/claude/cfront-3/src/typ.cpp"
__5t1 =
# 1162 "/home/claude/cfront-3/src/typ.cpp"
(((struct ptr *)(((struct ptr *)is_ptr_or_ref__4typeFv ( __5t1 ) ))))-> typ__5pvtyp ;
__5t2 = (((struct ptr *)(((struct ptr *)is_ptr_or_ref__4typeFv ( __5t2 ) ))))-> typ__5pvtyp ;
if ((! is_ptr_or_ref__4typeFv ( __5t1 ) )&& (! is_ptr_or_ref__4typeFv ( __5t2 ) ))
# 1165 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 1166 "/home/claude/cfront-3/src/typ.cpp"
__5t1 = skiptypedefs__4typeFv ( __5t1 ) ;
__5t2 = skiptypedefs__4typeFv ( __5t2 ) ;
if ((__5t1 -> base__4node == 119 )&& (__5t2 -> base__4node == 119 ))
# 1169 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 1170 "/home/claude/cfront-3/src/typ.cpp"
Pclass __8c1 ;
Pclass __8c2 ;

# 1170 "/home/claude/cfront-3/src/typ.cpp"
__8c1 = classtype__4typeFv ( __5t1 ) ;
__8c2 = classtype__4typeFv ( __5t2 ) ;
Nvis = 0 ;
if (has_base__8classdefFP8classdefiT2 ( __8c2 , __8c1 , 0 , 1 ) && (! Nvis ))
# 1174 "/home/claude/cfront-3/src/typ.cpp"
__5fail = 0 ;
}
}
}
if (__5fail )
# 1179 "/home/claude/cfront-3/src/typ.cpp"
Vcheckerror = 1 ;
else 
# 1181 "/home/claude/cfront-3/src/typ.cpp"
break ;
}
if ((__1rec_oper0 == 204 )&& (__1level == 0 ))
# 1184 "/home/claude/cfront-3/src/typ.cpp"
return_error = 1 ;
return (unsigned char )1 ;
}

# 1188 "/home/claude/cfront-3/src/typ.cpp"
break ;
}

# 1191 "/home/claude/cfront-3/src/typ.cpp"
case 114 :
# 1192 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 1193 "/home/claude/cfront-3/src/typ.cpp"
case 0 :
# 1194 "/home/claude/cfront-3/src/typ.cpp"
case 254 :
# 1195 "/home/claude/cfront-3/src/typ.cpp"
case 136 :
# 1196 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCc ( (int )'i' , (const char *)"check field?")
# 1196 "/home/claude/cfront-3/src/typ.cpp"
;
}
return (unsigned char )0 ;

# 1200 "/home/claude/cfront-3/src/typ.cpp"
case 15 :
# 1201 "/home/claude/cfront-3/src/typ.cpp"
case 11 :
# 1202 "/home/claude/cfront-3/src/typ.cpp"
case 181 :
# 1203 "/home/claude/cfront-3/src/typ.cpp"
case 5 :
# 1204 "/home/claude/cfront-3/src/typ.cpp"
case 29 :
# 1205 "/home/claude/cfront-3/src/typ.cpp"
case 21 :
# 1206 "/home/claude/cfront-3/src/typ.cpp"
case 22 :
# 1207 "/home/claude/cfront-3/src/typ.cpp"
case 122 :
# 1208 "/home/claude/cfront-3/src/typ.cpp"
if ((((struct basetype *)(((struct basetype *)__1t1 ))))-> b_unsigned__8basetype != (((struct
# 1208 "/home/claude/cfront-3/src/typ.cpp"
basetype *)(((struct basetype *)__1t2 ))))-> b_unsigned__8basetype ){ 
# 1209 "/home/claude/cfront-3/src/typ.cpp"
if ((__1level > 0 )|| ((__1oper == 0 )|| (__1oper == 254 )))
# 1210 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )1 ;
if (__1oper == 78 )
# 1212 "/home/claude/cfront-3/src/typ.cpp"
Nstd ++ ;
}
goto const_check ;

# 1216 "/home/claude/cfront-3/src/typ.cpp"
case 121 :
# 1217 "/home/claude/cfront-3/src/typ.cpp"
if ((((struct basetype *)(((struct basetype *)__1t1 ))))-> b_name__8basetype -> __O1__4expr.tp != (((struct basetype *)(((struct basetype *)__1t2 ))))-> b_name__8basetype -> __O1__4expr.tp )
# 1218 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char
# 1218 "/home/claude/cfront-3/src/typ.cpp"
)1 ;
goto const_check ;

# 1221 "/home/claude/cfront-3/src/typ.cpp"
case 6 :
# 1222 "/home/claude/cfront-3/src/typ.cpp"
case 119 :
# 1223 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 1224 "/home/claude/cfront-3/src/typ.cpp"
Pname __3n1 ;

# 1224 "/home/claude/cfront-3/src/typ.cpp"
Pname __3n2 ;
if (__1b1 == 119 ){ 
# 1226 "/home/claude/cfront-3/src/typ.cpp"
__3n1 = (((struct basetype *)(((struct basetype *)__1t1 ))))-> b_name__8basetype ;
__3n2 = (((struct basetype *)(((struct basetype *)__1t2 ))))-> b_name__8basetype ;
if (__3n1 == __3n2 )
# 1229 "/home/claude/cfront-3/src/typ.cpp"
goto const_check ;
}

# 1239 "/home/claude/cfront-3/src/typ.cpp"
{ extern int is_arg ;
int __3access ;

# 1241 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X84 ;

# 1241 "/home/claude/cfront-3/src/typ.cpp"
struct classdef *__1__X85 ;

# 1240 "/home/claude/cfront-3/src/typ.cpp"
__3access = (template_hier || pt_over );
if (( (__1__X84 = (((struct classdef *)(((struct classdef *)((__1b1 == 119 )?__3n1 -> __O1__4expr.tp :__1t1 )))))), ( (__1__X85 = (((struct classdef *)(((struct classdef *)((__1b1 == 119 )?__3n2 ->
# 1241 "/home/claude/cfront-3/src/typ.cpp"
__O1__4expr.tp :__1t2 )))))), ( ((__1__X84 == __1__X85 )?1 :((__1__X84 && __1__X85 )?(((int )same_class__8classdefFP8classdefi ( __1__X84 , __1__X85 , (__3access || is_arg )) )):0 ))) ) ) ||
# 1241 "/home/claude/cfront-3/src/typ.cpp"
((__1rec_oper == 204 )&& fm_same_class__FP8classdefT1 ( ((struct classdef *)(((struct classdef *)((__1b1 == 119 )?__3n1 -> __O1__4expr.tp :__1t1 )))), ((struct classdef *)(((struct classdef *)((__1b1 == 119 )?__3n2 -> __O1__4expr.tp :__1t2 ))))) ))
# 1248 "/home/claude/cfront-3/src/typ.cpp"
goto
# 1248 "/home/claude/cfront-3/src/typ.cpp"
const_check ;

# 1251 "/home/claude/cfront-3/src/typ.cpp"
if (template_hier != 0 )
# 1252 "/home/claude/cfront-3/src/typ.cpp"
goto pt_hack ;

# 1254 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 1255 "/home/claude/cfront-3/src/typ.cpp"
case 136 :
# 1256 "/home/claude/cfront-3/src/typ.cpp"
case 70 :
# 1257 "/home/claude/cfront-3/src/typ.cpp"
case 28 :
# 1258 "/home/claude/cfront-3/src/typ.cpp"
case 78 :
# 1259 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 1260 "/home/claude/cfront-3/src/typ.cpp"
pt_hack :
# 1261 "/home/claude/cfront-3/src/typ.cpp"
ppbase = 25 ;
if ((__1level <= 1 )&& is_base__8classdefFPCcPUci ( ((struct classdef *)(((struct classdef *)((__1b1 == 119 )?__3n2 -> __O1__4expr.tp :__1t2 )))), (__1b1 == 119 )?__3n1 -> __O2__4expr.string :(((struct classdef *)(((struct classdef *)__1t1 ))))->
# 1262 "/home/claude/cfront-3/src/typ.cpp"
string__8classdef , (TOK *)0 , 0 ) ){ 
# 1263 "/home/claude/cfront-3/src/typ.cpp"
if (ppbase != 25 ){ 
# 1264 "/home/claude/cfront-3/src/typ.cpp"
const_problem = 0 ;
return (unsigned char )1 ;
}
if (__1oper == 78 )
# 1268 "/home/claude/cfront-3/src/typ.cpp"
Nstd ++ ;
goto const_check ;
}
}

# 1273 "/home/claude/cfront-3/src/typ.cpp"
case 0 :
# 1274 "/home/claude/cfront-3/src/typ.cpp"
case 254 :
# 1275 "/home/claude/cfront-3/src/typ.cpp"
const_problem = 0 ;
return (unsigned char )1 ;
}

# 1279 "/home/claude/cfront-3/src/typ.cpp"
goto const_check ;

# 1279 "/home/claude/cfront-3/src/typ.cpp"
}
}

# 1282 "/home/claude/cfront-3/src/typ.cpp"
case 138 :
# 1283 "/home/claude/cfront-3/src/typ.cpp"
case 38 :
# 1284 "/home/claude/cfront-3/src/typ.cpp"
goto const_check ;
default :
# 1286 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 1286 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V70 ;

# 1286 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V71 ;

# 1286 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V72 ;

# 1286 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"T::check(o=%d %d %d)", (const struct ea *)( ((
# 1286 "/home/claude/cfront-3/src/typ.cpp"
((& __0__V70 )-> __O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V70 )) , (const struct ea *)(
# 1286 "/home/claude/cfront-3/src/typ.cpp"
(( ((& __0__V71 )-> __O1__2ea.i = ((unsigned long )__1b1 )), 0 ) ), (& __0__V71 )) , (const struct
# 1286 "/home/claude/cfront-3/src/typ.cpp"
ea *)( (( ((& __0__V72 )-> __O1__2ea.i = ((unsigned long )__1b2 )), 0 ) ), (& __0__V72 )) , (const
# 1286 "/home/claude/cfront-3/src/typ.cpp"
struct ea *)ea0 ) ;
} }

# 1289 "/home/claude/cfront-3/src/typ.cpp"
const_check :
# 1292 "/home/claude/cfront-3/src/typ.cpp"
if (__1cnst1 == __1cnst2 )
# 1293 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )0 ;

# 1295 "/home/claude/cfront-3/src/typ.cpp"
switch (__1oper ){ 
# 1296 "/home/claude/cfront-3/src/typ.cpp"
case 254 :
# 1297 "/home/claude/cfront-3/src/typ.cpp"
return (unsigned char )0 ;

# 1299 "/home/claude/cfront-3/src/typ.cpp"
case 0 :
# 1300 "/home/claude/cfront-3/src/typ.cpp"
const_problem = 1 ;
return (unsigned char )1 ;

# 1303 "/home/claude/cfront-3/src/typ.cpp"
case 70 :
# 1304 "/home/claude/cfront-3/src/typ.cpp"
case 78 :
# 1305 "/home/claude/cfront-3/src/typ.cpp"
case 136 :
# 1306 "/home/claude/cfront-3/src/typ.cpp"
case 28 :
# 1307 "/home/claude/cfront-3/src/typ.cpp"
if (__1level > 0 ){ 
# 1308 "/home/claude/cfront-3/src/typ.cpp"
if (__1cnst2 )
# 1309 "/home/claude/cfront-3/src/typ.cpp"
const_problem = 1 ;
return __1cnst2 ;
}
return (unsigned char )0 ;
default :
# 1314 "/home/claude/cfront-3/src/typ.cpp"
{ 
# 1314 "/home/claude/cfront-3/src/typ.cpp"
struct ea __0__V73 ;

# 1314 "/home/claude/cfront-3/src/typ.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"oper = %k in type::check()", (const struct ea *)( ((
# 1314 "/home/claude/cfront-3/src/typ.cpp"
((& __0__V73 )-> __O1__2ea.i = ((unsigned long )__1oper )), 0 ) ), (& __0__V73 )) , (const struct ea *)ea0 ,
# 1314 "/home/claude/cfront-3/src/typ.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
return (unsigned char )0 ;
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

# 1317 "/home/claude/cfront-3/src/typ.cpp"

/* the end */
