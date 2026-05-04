# 1 ""

/* <<AT&T C++ Language System <3.0.3> 05/05/94>> pragma*/

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
extern void *__nw__FUl (size_t );

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
if (__0this || (__0this = (struct ptr *)__nw__3ptrSFUl ( (size_t )(sizeof (struct ptr))) )){ __0this = (struct ptr *)( (__0__X8 =
# 708 "/home/claude/cfront-3/src/cfront.h"
(((struct pvtyp *)__0this ))), ( ((__0__X8 || (__0__X8 = (struct pvtyp *)__nw__FUl ( (size_t )(sizeof (struct pvtyp))) ))?(__0__X8 = (struct pvtyp *)(
# 708 "/home/claude/cfront-3/src/cfront.h"
(__0__X6 = (((struct type *)__0__X8 ))), ( ((__0__X6 || (__0__X6 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type))) ))?( (
# 708 "/home/claude/cfront-3/src/cfront.h"
( ( ( ( ( ( (__0__X6 = (struct type *)( (__0__X1 = (((struct node *)__0__X6 ))), ( ((__0__X1 ||
# 708 "/home/claude/cfront-3/src/cfront.h"
(__0__X1 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 -> permanent__4node =
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

# 21 "/home/claude/cfront-3/src/dcl3.cpp"
Pblock top_block = 0 ;
int New_in_arg_list = 0 ;

# 25 "/home/claude/cfront-3/src/dcl3.cpp"
static int is_zero__FP4expr (Pexpr __1e )
# 26 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 27 "/home/claude/cfront-3/src/dcl3.cpp"
if (! __1e )
# 28 "/home/claude/cfront-3/src/dcl3.cpp"
return 0 ;
if (__1e -> base__4node == 86 )
# 30 "/home/claude/cfront-3/src/dcl3.cpp"
return 1 ;
if ((__1e -> base__4node != 113 )&& (__1e -> base__4node != 191 ))
# 32 "/home/claude/cfront-3/src/dcl3.cpp"
return 0 ;
return (__1e -> __O2__4expr.e1 -> base__4node == 86 );
}

# 36 "/home/claude/cfront-3/src/dcl3.cpp"
static void vbase_pointers__FP4nameP8classdef (Pname __1fn , Pclass __1cl )
# 41 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 43 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __1f ;

# 43 "/home/claude/cfront-3/src/dcl3.cpp"
__1f = (((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))));
if (__1fn -> n_oper__4name == 161 ){ 
# 45 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __2d ;

# 45 "/home/claude/cfront-3/src/dcl3.cpp"
__2d = 0 ;
{ { Pbcl __2b ;

# 46 "/home/claude/cfront-3/src/dcl3.cpp"
__2b = __1cl -> baselist__8classdef ;

# 46 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__2b ;__2b = __2b -> next__6basecl ) { 
# 47 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2b -> base__4node != 77 )
# 48 "/home/claude/cfront-3/src/dcl3.cpp"
continue ;
{ Pname __3a ;

# 49 "/home/claude/cfront-3/src/dcl3.cpp"
__3a = __ct__4nameFPCc ( (struct name *)0 , __2b -> bclass__6basecl -> string__8classdef ) ;
__3a -> __O1__4expr.tp = __2b -> bclass__6basecl -> this_type__8classdef ;
__3a -> __O1__4name.n_list = __2d ;
__3a -> __O4__4expr.n_table = (__1f -> body__3fct ?__1f -> body__3fct -> memtbl__4stmt :(((struct table *)0 )));
__3a -> where__4name = __1fn -> where__4name ;
__2d = __3a ;

# 54 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 57 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2d ){ 
# 58 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __3dd ;

# 58 "/home/claude/cfront-3/src/dcl3.cpp"
__3dd = __2d ;
for(;;) { 
# 60 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2d -> __O1__4name.n_list == 0 ){ 
# 61 "/home/claude/cfront-3/src/dcl3.cpp"
__2d -> __O1__4name.n_list = __1f -> f_args__3fct -> __O1__4name.n_list ;
break ;
}
__2d = __2d -> __O1__4name.n_list ;
}
__1f -> f_args__3fct -> __O1__4name.n_list = __3dd ;
}

# 67 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 67 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
if (__1fn -> n_oper__4name == 162 ){ 
# 71 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __2fa ;

# 71 "/home/claude/cfront-3/src/dcl3.cpp"
__2fa = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__2fa -> __O1__4expr.tp = (struct type *)int_type ;
__2fa -> n_scope__4name = 136 ;
__2fa -> where__4name = __1fn -> where__4name ;

# 76 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pname __2a ;

# 76 "/home/claude/cfront-3/src/dcl3.cpp"
__2a = __1f -> f_args__3fct ;
if (__2a == 0 )
# 78 "/home/claude/cfront-3/src/dcl3.cpp"
__1f -> f_args__3fct = __2fa ;
else { 
# 80 "/home/claude/cfront-3/src/dcl3.cpp"
for(;;__2a = __2a -> __O1__4name.n_list ) { 
# 82 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2a -> __O1__4name.n_list == 0 ){ 
# 83 "/home/claude/cfront-3/src/dcl3.cpp"
__2a -> __O1__4name.n_list = __2fa ;
break ;
}
}
}

# 87 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
}

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 468 "/home/claude/cfront-3/src/cfront.h"

# 715 "/home/claude/cfront-3/src/cfront.h"

# 91 "/home/claude/cfront-3/src/dcl3.cpp"
void make_res__FP3fct (Pfct __1f )
# 96 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 97 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __1cl ;

# 98 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__0__X26 ;

# 97 "/home/claude/cfront-3/src/dcl3.cpp"
__1cl = is_cl_obj__4typeFv ( __1f -> returns__3fct ) ;
if ((__1cl == 0 )|| (( (__0__X26 = (((struct classdef *)(((struct classdef *)__1cl -> __O1__4expr.tp ))))), ( __0__X26 -> c_itor__8classdef ) ) ==
# 98 "/home/claude/cfront-3/src/dcl3.cpp"
0 ))
# 99 "/home/claude/cfront-3/src/dcl3.cpp"
return ;

# 101 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pname __1rv ;

# 102 "/home/claude/cfront-3/src/dcl3.cpp"
struct type *__0__X27 ;

# 101 "/home/claude/cfront-3/src/dcl3.cpp"
__1rv = __ct__4nameFPCc ( (struct name *)0 , (const char *)"_result") ;
__1rv -> __O1__4expr.tp = (struct type *)( (__0__X27 = __1f -> returns__3fct ), ( __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 ,
# 102 "/home/claude/cfront-3/src/dcl3.cpp"
__0__X27 ) ) ) ;
__1rv -> permanent__4node = 1 ;
__1rv -> __O1__4expr.tp -> permanent__4node = 1 ;
__1rv -> n_scope__4name = 108 ;
__1rv -> n_used__4name = 1 ;
__1rv -> __O1__4name.n_list = __1f -> argtype__3fct ;
if (__1f -> f_this__3fct )
# 109 "/home/claude/cfront-3/src/dcl3.cpp"
__1f -> f_this__3fct -> __O1__4name.n_list = __1rv ;
else 
# 111 "/home/claude/cfront-3/src/dcl3.cpp"
__1f -> f_args__3fct = __1rv ;
__1f -> f_result__3fct = __1rv ;
__1f -> s_returns__3fct = (struct type *)void_type ;

# 113 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 470 "/home/claude/cfront-3/src/template.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 470 "/home/claude/cfront-3/src/template.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 633 "/home/claude/cfront-3/src/cfront.h"
struct fct *__ct__3fctFP4typeP4nameUc (struct fct *__0this , Ptype , Pname , TOK );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 362 "/home/claude/cfront-3/src/cfront.h"
void del__4typeFv (struct type *__0this );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 321 "/home/claude/cfront-3/src/cfront.h"
char *signature__4typeFPci (struct type *__0this , char *, int );

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 116 "/home/claude/cfront-3/src/dcl3.cpp"
void check_oper__4nameFP4name (register struct name *__0this , Pname __1cn )
# 120 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 121 "/home/claude/cfront-3/src/dcl3.cpp"
;
switch (__0this -> n_oper__4name ){ 
# 122 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X62 ;

# 122 "/home/claude/cfront-3/src/dcl3.cpp"
unsigned long __2__X64 ;

# 122 "/home/claude/cfront-3/src/dcl3.cpp"
register struct templ_classdef *__0__X67 ;

# 122 "/home/claude/cfront-3/src/dcl3.cpp"
register struct templ_classdef *__0__X70 ;

# 123 "/home/claude/cfront-3/src/dcl3.cpp"
case 109 :
# 124 "/home/claude/cfront-3/src/dcl3.cpp"
case 111 :
# 125 "/home/claude/cfront-3/src/dcl3.cpp"
case 44 :
# 126 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cn == 0 )
# 127 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 127 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V28 ;

# 127 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"operator%s must be aM", (const struct ea *)( (__2__X62 = (const void
# 127 "/home/claude/cfront-3/src/dcl3.cpp"
*)(keys [__0this -> n_oper__4name ])), ( ((& __0__V28 )-> __O1__2ea.p = __2__X62 ), (& __0__V28 )) ) , (const struct ea *)ea0 ,
# 127 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} break ;
case 126 :
# 130 "/home/claude/cfront-3/src/dcl3.cpp"
case 127 :
# 131 "/home/claude/cfront-3/src/dcl3.cpp"
case 128 :
# 132 "/home/claude/cfront-3/src/dcl3.cpp"
case 129 :
# 133 "/home/claude/cfront-3/src/dcl3.cpp"
case 130 :
# 134 "/home/claude/cfront-3/src/dcl3.cpp"
case 131 :
# 135 "/home/claude/cfront-3/src/dcl3.cpp"
case 132 :
# 136 "/home/claude/cfront-3/src/dcl3.cpp"
case 133 :
# 137 "/home/claude/cfront-3/src/dcl3.cpp"
case 134 :
# 138 "/home/claude/cfront-3/src/dcl3.cpp"
case 135 :
# 139 "/home/claude/cfront-3/src/dcl3.cpp"
if (warning_opt ){ 
# 139 "/home/claude/cfront-3/src/dcl3.cpp"
const void
# 139 "/home/claude/cfront-3/src/dcl3.cpp"
*__2__X63 ;

# 140 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1cn == 0 )|| (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_static__3fct )
# 141 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 141 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V29 ;

# 141 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"operator%s should be a non-staticMF", (const struct ea *)( (__2__X63 =
# 141 "/home/claude/cfront-3/src/dcl3.cpp"
(const void *)(keys [__0this -> n_oper__4name ])), ( ((& __0__V29 )-> __O1__2ea.p = __2__X63 ), (& __0__V29 )) ) , (const
# 141 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
break ;
case 70 :
# 145 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cn == 0 )
# 146 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 146 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V30 ;

# 146 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"non-member operator%k()", (const struct ea *)( (__2__X64 = __0this -> n_oper__4name ),
# 146 "/home/claude/cfront-3/src/dcl3.cpp"
( (( ((& __0__V30 )-> __O1__2ea.i = __2__X64 ), 0 ) ), (& __0__V30 )) ) , (const struct
# 146 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} break ;
case 58 :case 59 :case 60 :case 61 :case 62 :case 63 :
# 149 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cn && (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_static__3fct ){ 
# 149 "/home/claude/cfront-3/src/dcl3.cpp"
const
# 149 "/home/claude/cfront-3/src/dcl3.cpp"
void *__2__X65 ;

# 150 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 150 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V31 ;

# 150 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"operator%s cannot be static", (const struct ea *)( (__2__X65 = (const void
# 150 "/home/claude/cfront-3/src/dcl3.cpp"
*)(keys [__0this -> n_oper__4name ])), ( ((& __0__V31 )-> __O1__2ea.p = __2__X65 ), (& __0__V31 )) ) , (const struct ea *)ea0 ,
# 150 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
(((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_static__3fct = 0 ;
} }
break ;
case 46 :
# 155 "/home/claude/cfront-3/src/dcl3.cpp"
case 47 :
# 156 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 157 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __3f ;

# 157 "/home/claude/cfront-3/src/dcl3.cpp"
__3f = (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))));
if (__1cn && __3f -> argtype__3fct )
# 159 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 159 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V32 ;

# 159 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V33 ;

# 159 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n::%n takes noAs", (const struct ea *)( ((& __0__V32 )-> __O1__2ea.p =
# 159 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1cn )), (& __0__V32 )) , (const struct ea *)( ((& __0__V33 )-> __O1__2ea.p = ((const void
# 159 "/home/claude/cfront-3/src/dcl3.cpp"
*)__0this )), (& __0__V33 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else if (__3f -> nargs__3fct == 2 )
# 161 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 161 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V34 ;

# 161 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n takes 1A only", (const struct ea *)( ((& __0__V34 )-> __O1__2ea.p =
# 161 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V34 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 161 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} if (__1cn && (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_static__3fct ){ 
# 162 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X66 ;

# 163 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 163 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V35 ;

# 163 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"operator%s cannot be static", (const struct ea *)( (__2__X66 = (const void
# 163 "/home/claude/cfront-3/src/dcl3.cpp"
*)(keys [__0this -> n_oper__4name ])), ( ((& __0__V35 )-> __O1__2ea.p = __2__X66 ), (& __0__V35 )) ) , (const struct ea *)ea0 ,
# 163 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
(((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_static__3fct = 0 ;
} }
break ;
}
case 48 :
# 169 "/home/claude/cfront-3/src/dcl3.cpp"
case 49 :
# 171 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 172 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __3f ;

# 172 "/home/claude/cfront-3/src/dcl3.cpp"
__3f = (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))));
if (__1cn ){ 
# 174 "/home/claude/cfront-3/src/dcl3.cpp"
if (__3f -> argtype__3fct && (__3f -> nargs__3fct == 1 )){ 
# 175 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __5n ;
Ptype __5at ;

# 175 "/home/claude/cfront-3/src/dcl3.cpp"
__5n = __3f -> argtype__3fct ;
__5at = skiptypedefs__4typeFv ( __5n -> __O1__4expr.tp ) ;
if ((__5at -> base__4node != 21 )|| (((struct basetype *)(((struct basetype *)__5at ))))-> b_unsigned__8basetype )
# 178 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 178 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V36 ;

# 178 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V37 ;

# 178 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n must takeA ofT int, not %t", (const struct ea *)( ((& __0__V36 )-> __O1__2ea.p =
# 178 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V36 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V37 , (const void *)__5n ->
# 178 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
else if (__3f -> nargs__3fct == 2 ){ 
# 182 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __4n ;
Ptype __4at ;

# 182 "/home/claude/cfront-3/src/dcl3.cpp"
__4n = __3f -> argtype__3fct -> __O1__4name.n_list ;
__4at = skiptypedefs__4typeFv ( __4n -> __O1__4expr.tp ) ;
if ((__4at -> base__4node != 21 )|| (((struct basetype *)(((struct basetype *)__4at ))))-> b_unsigned__8basetype )
# 185 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 185 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V38 ;

# 185 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V39 ;

# 185 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n must takeA ofT int, not %t", (const struct ea *)( ((& __0__V38 )-> __O1__2ea.p =
# 185 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V38 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V39 , (const void *)__4n ->
# 185 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
break ;
}
case 0 :
# 190 "/home/claude/cfront-3/src/dcl3.cpp"
case 123 :
# 191 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cn && ((strcmp ( __1cn -> __O2__4expr.string , __0this -> __O2__4expr.string ) == 0 )|| (((((struct classdef *)(((struct classdef *)__1cn ->
# 191 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ))))-> class_base__8classdef == 4)&& (strcmp ( __0this -> __O2__4expr.string , ( (__0__X67 = (((struct templ_classdef *)(((struct templ_classdef *)__1cn -> __O1__4expr.tp ))))), ( __0__X67 ->
# 191 "/home/claude/cfront-3/src/dcl3.cpp"
inst__14templ_classdef -> def__10templ_inst -> namep__5templ ) ) -> __O2__4expr.string ) == 0 ))))
# 202 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 203 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> __O1__4expr.tp -> base__4node == 108 ){ 
# 204 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __4f ;
# 204 "/home/claude/cfront-3/src/dcl3.cpp"

# 204 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X68 ;

# 204 "/home/claude/cfront-3/src/dcl3.cpp"
__4f = (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))));
if (__4f -> returns__3fct != (((struct type *)defa_type )))
# 206 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 206 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V40 ;

# 206 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V41 ;

# 206 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s::%s()W returnT", (const struct ea *)( (__2__X68 = (const void
# 206 "/home/claude/cfront-3/src/dcl3.cpp"
*)__0this -> __O2__4expr.string ), ( ((& __0__V40 )-> __O1__2ea.p = __2__X68 ), (& __0__V40 )) ) , (const struct ea *)__ct__2eaFPCv (
# 206 "/home/claude/cfront-3/src/dcl3.cpp"
& __0__V41 , (const void *)__0this -> __O2__4expr.string ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 206 "/home/claude/cfront-3/src/dcl3.cpp"
} 
# 207 "/home/claude/cfront-3/src/dcl3.cpp"
__4f -> returns__3fct = (struct type *)void_type ;
__0this -> __O2__4expr.string = (const char *)"__ct";
__0this -> n_oper__4name = 161 ;
}
else 
# 212 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 212 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V42 ;

# 212 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V43 ;

# 212 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"struct%nM%n", (const struct ea *)( ((&
# 212 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V42 )-> __O1__2ea.p = ((const void *)__1cn )), (& __0__V42 )) , (const struct ea *)( ((& __0__V43 )-> __O1__2ea.p =
# 212 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1cn )), (& __0__V43 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else 
# 215 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> n_oper__4name = 0 ;
break ;

# 218 "/home/claude/cfront-3/src/dcl3.cpp"
case 162 :
# 220 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cn == 0 ){ 
# 220 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X69 ;

# 221 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> n_oper__4name = 0 ;
{ 
# 222 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V44 ;

# 222 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"destructor ~%s() not inC", (const struct ea *)( (__2__X69 = (const void
# 222 "/home/claude/cfront-3/src/dcl3.cpp"
*)__0this -> __O2__4expr.string ), ( ((& __0__V44 )-> __O1__2ea.p = __2__X69 ), (& __0__V44 )) ) , (const struct ea *)ea0 ,
# 222 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else if ((strcmp ( __1cn -> __O2__4expr.string , __0this -> __O2__4expr.string ) == 0 )|| (((((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))))->
# 224 "/home/claude/cfront-3/src/dcl3.cpp"
class_base__8classdef == 4)&& (strcmp ( __0this -> __O2__4expr.string , ( (__0__X70 = (((struct templ_classdef *)(((struct templ_classdef *)__1cn -> __O1__4expr.tp ))))), ( __0__X70 -> inst__14templ_classdef ->
# 224 "/home/claude/cfront-3/src/dcl3.cpp"
def__10templ_inst -> namep__5templ ) ) -> __O2__4expr.string ) == 0 )))
# 230 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 231 "/home/claude/cfront-3/src/dcl3.cpp"
dto :
# 232 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pfct __3f ;

# 232 "/home/claude/cfront-3/src/dcl3.cpp"
__3f = (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))));
__0this -> __O2__4expr.string = (const char *)"__dt";
if (__0this -> __O1__4expr.tp -> base__4node != 108 ){ 
# 234 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X71 ;

# 235 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 235 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V45 ;

# 235 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V46 ;

# 235 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s::~%s notF", (const struct ea *)( (__2__X71 = (const void
# 235 "/home/claude/cfront-3/src/dcl3.cpp"
*)__1cn -> __O2__4expr.string ), ( ((& __0__V45 )-> __O1__2ea.p = __2__X71 ), (& __0__V45 )) ) , (const struct ea *)__ct__2eaFPCv (
# 235 "/home/claude/cfront-3/src/dcl3.cpp"
& __0__V46 , (const void *)__1cn -> __O2__4expr.string ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 235 "/home/claude/cfront-3/src/dcl3.cpp"

# 236 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> __O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)void_type , (struct name *)0 , (unsigned char )1 ) ;
# 236 "/home/claude/cfront-3/src/dcl3.cpp"
} 
# 237 "/home/claude/cfront-3/src/dcl3.cpp"
}
else if (__3f -> returns__3fct != (((struct type *)defa_type ))){ 
# 238 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X72 ;

# 239 "/home/claude/cfront-3/src/dcl3.cpp"
if (((__3f -> returns__3fct != (((struct type *)void_type )))|| (__3f -> body__3fct != 0 ))|| (friend_in_class == 0 ))
# 246 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 246 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V47 ;

# 246 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V48 ;

# 246 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s::~%s()W returnT", (const struct ea *)( (__2__X72 = (const void
# 246 "/home/claude/cfront-3/src/dcl3.cpp"
*)__1cn -> __O2__4expr.string ), ( ((& __0__V47 )-> __O1__2ea.p = __2__X72 ), (& __0__V47 )) ) , (const struct ea *)__ct__2eaFPCv (
# 246 "/home/claude/cfront-3/src/dcl3.cpp"
& __0__V48 , (const void *)__1cn -> __O2__4expr.string ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 246 "/home/claude/cfront-3/src/dcl3.cpp"
} 
# 247 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 249 "/home/claude/cfront-3/src/dcl3.cpp"
if (__3f -> argtype__3fct || (__3f -> nargs_known__3fct == 155 )){ 
# 249 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X73 ;

# 250 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 250 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V49 ;

# 250 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V50 ;

# 250 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s::~%s()WAs", (const struct ea *)( (__2__X73 = (const void
# 250 "/home/claude/cfront-3/src/dcl3.cpp"
*)__1cn -> __O2__4expr.string ), ( ((& __0__V49 )-> __O1__2ea.p = __2__X73 ), (& __0__V49 )) ) , (const struct ea *)__ct__2eaFPCv (
# 250 "/home/claude/cfront-3/src/dcl3.cpp"
& __0__V50 , (const void *)__1cn -> __O2__4expr.string ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 250 "/home/claude/cfront-3/src/dcl3.cpp"

# 251 "/home/claude/cfront-3/src/dcl3.cpp"
__3f -> nargs__3fct = 0 ;
__3f -> nargs_known__3fct = 1 ;
__3f -> argtype__3fct = 0 ;
} }
__3f -> returns__3fct = (struct type *)void_type ;

# 255 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
else { 
# 257 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X74 ;

# 258 "/home/claude/cfront-3/src/dcl3.cpp"
if (strcmp ( __0this -> __O2__4expr.string , (const char *)"__dt") == 0 )
# 259 "/home/claude/cfront-3/src/dcl3.cpp"
goto dto ;
# 259 "/home/claude/cfront-3/src/dcl3.cpp"

# 260 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 260 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V51 ;

# 260 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V52 ;

# 260 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"~%s in %s", (const struct ea *)( (__2__X74 = (const void
# 260 "/home/claude/cfront-3/src/dcl3.cpp"
*)__0this -> __O2__4expr.string ), ( ((& __0__V51 )-> __O1__2ea.p = __2__X74 ), (& __0__V51 )) ) , (const struct ea *)__ct__2eaFPCv (
# 260 "/home/claude/cfront-3/src/dcl3.cpp"
& __0__V52 , (const void *)__1cn -> __O2__4expr.string ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 260 "/home/claude/cfront-3/src/dcl3.cpp"

# 261 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> n_oper__4name = 0 ;
} }
break ;

# 265 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 267 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cn == 0 ){ 
# 267 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X75 ;

# 268 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 268 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V53 ;

# 268 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"operator%t() not aM", (const struct ea *)( (__2__X75 = (const void
# 268 "/home/claude/cfront-3/src/dcl3.cpp"
*)(((struct type *)(((struct type *)__0this -> __O4__4expr.cond ))))), ( ((& __0__V53 )-> __O1__2ea.p = __2__X75 ), (& __0__V53 )) ) , (const
# 268 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__0this -> n_oper__4name = 0 ;
__0this -> __O4__4expr.cond = 0 ;
} }
else 
# 274 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> __O4__4expr.cond ){ 
# 275 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __3f ;
Ptype __3tx ;

# 275 "/home/claude/cfront-3/src/dcl3.cpp"
__3f = (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))));
__3tx = (((struct type *)(((struct type *)__0this -> __O4__4expr.cond ))));
__0this -> __O4__4expr.cond = 0 ;
if (skiptypedefs__4typeFv ( __3tx ) -> base__4node == 108 )
# 279 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 279 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V54 ;

# 279 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V55 ;

# 279 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badT for%n::operator%t() - cannot return aF", (const struct ea *)( ((& __0__V54 )-> __O1__2ea.p =
# 279 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1cn )), (& __0__V54 )) , (const struct ea *)( ((& __0__V55 )-> __O1__2ea.p = ((const void
# 279 "/home/claude/cfront-3/src/dcl3.cpp"
*)__3tx )), (& __0__V55 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__3f -> base__4node != 108 )
# 281 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 281 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V56 ;

# 281 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V57 ;

# 281 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badT for%n::operator%t()", (const struct ea *)( ((& __0__V56 )-> __O1__2ea.p =
# 281 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1cn )), (& __0__V56 )) , (const struct ea *)( ((& __0__V57 )-> __O1__2ea.p = ((const void
# 281 "/home/claude/cfront-3/src/dcl3.cpp"
*)__3tx )), (& __0__V57 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__3f -> returns__3fct != (((struct type *)defa_type ))){ 
# 283 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 283 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V58 ;

# 283 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V59 ;

# 283 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"resultT for%n::operator%t()", (const struct ea *)( ((& __0__V58 )-> __O1__2ea.p =
# 283 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1cn )), (& __0__V58 )) , (const struct ea *)( ((& __0__V59 )-> __O1__2ea.p = ((const void
# 283 "/home/claude/cfront-3/src/dcl3.cpp"
*)__3tx )), (& __0__V59 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
if (__3f -> returns__3fct && (__3f -> returns__3fct -> permanent__4node == 0 ))del__4typeFv ( __3f -> returns__3fct ) ;
} }
if (__3f -> argtype__3fct || (__3f -> nargs_known__3fct == 155 )){ 
# 287 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 287 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V60 ;

# 287 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V61 ;

# 287 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n::operator%t()WAs", (const struct ea *)( ((& __0__V60 )-> __O1__2ea.p =
# 287 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1cn )), (& __0__V60 )) , (const struct ea *)( ((& __0__V61 )-> __O1__2ea.p = ((const void
# 287 "/home/claude/cfront-3/src/dcl3.cpp"
*)__3tx )), (& __0__V61 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__3f -> argtype__3fct = 0 ;
} }
__3f -> returns__3fct = __3tx ;
{ char __3buf [1024];
char *__3bb ;
int __3l2 ;

# 292 "/home/claude/cfront-3/src/dcl3.cpp"
__3bb = signature__4typeFPci ( __3tx , (char *)__3buf , 0 ) ;
__3l2 = (__3bb - __3buf );
if (1023 < __3l2 )
# 295 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCc ( (int )'i' , (const char *)"N::check_oper():N buffer overflow") ;
{ char *__3p ;

# 296 "/home/claude/cfront-3/src/dcl3.cpp"
__3p = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* (__3l2 + 5 ))) ));
(__3p [0 ])= '_' ;
(__3p [1 ])= '_' ;
(__3p [2 ])= 'o' ;
(__3p [3 ])= 'p' ;
strcpy ( __3p + 4 , (const char *)__3buf ) ;
__0this -> __O2__4expr.string = (const char *)__3p ;

# 302 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 302 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
break ;
}
}

# 308 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr vbase_args__FP3fctP4name (Pfct __1a , Pname __1bn )
# 313 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 314 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __1b ;

# 316 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __1args ;
Pexpr __1tail ;

# 314 "/home/claude/cfront-3/src/dcl3.cpp"
__1b = (((struct fct *)(((struct fct *)__1bn -> __O1__4expr.tp ))));

# 316 "/home/claude/cfront-3/src/dcl3.cpp"
__1args = 0 ;
__1tail = 0 ;
if (__1b -> base__4node == 76 )
# 319 "/home/claude/cfront-3/src/dcl3.cpp"
__1b = (((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__1b ))))-> fct_list__3gen -> f__9name_list -> __O1__4expr.tp ))));
{ { Pname __1d ;

# 320 "/home/claude/cfront-3/src/dcl3.cpp"
__1d = __1b -> f_args__3fct -> __O1__4name.n_list ;

# 320 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__1d != __1b -> argtype__3fct ;__1d = __1d -> __O1__4name.n_list ) { 
# 321 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __2dd ;

# 321 "/home/claude/cfront-3/src/dcl3.cpp"
__2dd = __1a -> f_args__3fct -> __O1__4name.n_list ;
for(;__2dd ;__2dd = __2dd -> __O1__4name.n_list ) 
# 323 "/home/claude/cfront-3/src/dcl3.cpp"
if (strcmp ( __2dd -> __O2__4expr.string , __1d -> __O2__4expr.string ) == 0 )
# 324 "/home/claude/cfront-3/src/dcl3.cpp"
break ;

# 326 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pexpr __2aa ;

# 326 "/home/claude/cfront-3/src/dcl3.cpp"
__2aa = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (struct expr *)__2dd , (struct expr *)0 ) ;
if (__1args == 0 )
# 328 "/home/claude/cfront-3/src/dcl3.cpp"
__1args = __2aa ;
else 
# 330 "/home/claude/cfront-3/src/dcl3.cpp"
__1tail -> __O3__4expr.e2 = __2aa ;
__1tail = __2aa ;

# 331 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
return __1args ;

# 333 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 333 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 227 "/home/claude/cfront-3/src/template.h"

# 640 "/home/claude/cfront-3/src/cfront.h"
Pexpr base_init__3fctFP8classdefP4exprP5tablei (struct fct *__0this , Pclass , Pexpr , Ptable , int );
Pexpr mem_init__3fctFP4nameP4exprP5table (struct fct *__0this , Pname , Pexpr , Ptable );

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 466 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 336 "/home/claude/cfront-3/src/dcl3.cpp"
void init_bases__3fctFP8classdefP4expr (register struct fct *__0this , Pclass __1cl , Pexpr __1__A76 )
# 349 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 350 "/home/claude/cfront-3/src/dcl3.cpp"
Ptable __1ftbl ;

# 351 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X90 ;

# 350 "/home/claude/cfront-3/src/dcl3.cpp"
__1ftbl = __0this -> body__3fct -> memtbl__4stmt ;
;

# 354 "/home/claude/cfront-3/src/dcl3.cpp"
if (((__1cl && (__1cl -> csu__8classdef == 36 ))&& __0this -> f_init__3fct )&& __0this -> f_init__3fct -> __O1__4name.n_list )
# 355 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 355 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V77 ;

# 355 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V78 ;

# 355 "/home/claude/cfront-3/src/dcl3.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> f_init__3fct -> where__4name , (const char *)"multipleIrs in unionK %s:: %s", (const struct
# 355 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)( (__2__X90 = (const void *)__1cl -> string__8classdef ), ( ((& __0__V77 )-> __O1__2ea.p = __2__X90 ), (& __0__V77 )) )
# 355 "/home/claude/cfront-3/src/dcl3.cpp"
, (const struct ea *)__ct__2eaFPCv ( & __0__V78 , (const void *)__1cl -> string__8classdef ) , (const struct ea *)ea0 ,
# 355 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} { { Pname __1nx ;

# 356 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __1nn ;

# 356 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn = __0this -> f_init__3fct ;

# 356 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__1nn ;( ( (__1nn ?(((void )(__1nn ?(((void )( ( ((((struct expr *)__1nn ))?(((void )((((struct expr *)__1nn ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 ))))
# 356 "/home/claude/cfront-3/src/dcl3.cpp"
, (((void )__dl__4nameSFPvUl ( (void *)__1nn , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ,
# 356 "/home/claude/cfront-3/src/dcl3.cpp"
(__1nn = __1nx )) ) { 
# 357 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __2i ;

# 357 "/home/claude/cfront-3/src/dcl3.cpp"
__2i = __1nn -> __O3__4expr.n_initializer ;
__1nn -> __O3__4expr.n_initializer = 0 ;
__1nx = __1nn -> __O1__4name.n_list ;

# 362 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1nn -> __O2__4expr.string ){ 
# 364 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 365 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __4mmm ;

# 365 "/home/claude/cfront-3/src/dcl3.cpp"
__4mmm = look__5tableFPCcUc ( __1cl -> memtbl__8classdef , __1nn -> __O2__4expr.string , (unsigned char )0 ) ;
if (__4mmm )
# 367 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn -> base__4node = __4mmm -> base__4node ;
}
if (__1nn -> base__4node == 123 ){ 
# 370 "/home/claude/cfront-3/src/dcl3.cpp"
const char *__4bn ;
while (__1nn -> __O1__4expr.tp && (__1nn -> __O1__4expr.tp -> base__4node == 97 ))
# 372 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn -> __O1__4expr.tp = (((struct basetype *)(((struct basetype *)__1nn -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ;
# 372 "/home/claude/cfront-3/src/dcl3.cpp"

# 373 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1nn -> __O1__4expr.tp && (__1nn -> __O1__4expr.tp -> base__4node == 119 ))
# 374 "/home/claude/cfront-3/src/dcl3.cpp"
__4bn = (((struct basetype *)(((struct basetype *)__1nn -> __O1__4expr.tp ))))-> b_name__8basetype -> __O2__4expr.string ;
else 
# 376 "/home/claude/cfront-3/src/dcl3.cpp"
__4bn = __1nn -> __O2__4expr.string ;
{ { Pbcl __4l ;

# 378 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X92 ;

# 377 "/home/claude/cfront-3/src/dcl3.cpp"
__4l = __1cl -> baselist__8classdef ;

# 377 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__4l ;__4l = __4l -> next__6basecl ) { 
# 378 "/home/claude/cfront-3/src/dcl3.cpp"
Pclass __5bcl ;

# 379 "/home/claude/cfront-3/src/dcl3.cpp"
register struct templ *__0__X91 ;

# 378 "/home/claude/cfront-3/src/dcl3.cpp"
__5bcl = __4l -> bclass__6basecl ;
if ((strcmp ( __5bcl -> string__8classdef , __4bn ) == 0 )|| ((__5bcl -> class_base__8classdef == 4)&& (strcmp ( ( (__0__X91 = (((struct
# 379 "/home/claude/cfront-3/src/dcl3.cpp"
templ_classdef *)(((struct templ_classdef *)__5bcl ))))-> inst__14templ_classdef -> def__10templ_inst ), ( (((struct classdef *)(((struct classdef *)__0__X91 -> basep__5templ -> b_name__8basetype -> __O1__4expr.tp ))))) ) -> string__8classdef ,
# 379 "/home/claude/cfront-3/src/dcl3.cpp"
__4bn ) == 0 )))
# 385 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 388 "/home/claude/cfront-3/src/dcl3.cpp"
if (__4l -> init__6basecl && (error_count == 0 ))
# 389 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 389 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V79 ;

# 389 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoIrs for%t", (const struct ea *)( ((& __0__V79 )-> __O1__2ea.p =
# 389 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__5bcl )), (& __0__V79 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 389 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else 
# 391 "/home/claude/cfront-3/src/dcl3.cpp"
__4l -> init__6basecl = base_init__3fctFP8classdefP4exprP5tablei ( __0this , __5bcl , __2i , __1ftbl , __4l -> obj_offset__6basecl ) ;
goto con ;
}
}
if (((__1nn -> base__4node == 123 )&& (! __1nn -> __O3__4expr.tpdef ))&& ((! __1nn -> __O1__4expr.tp )|| ((__1nn -> __O1__4expr.tp -> base__4node != 119 )&&
# 395 "/home/claude/cfront-3/src/dcl3.cpp"
(__1nn -> __O1__4expr.tp -> base__4node != 121 ))))
# 398 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 398 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V80 ;

# 398 "/home/claude/cfront-3/src/dcl3.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"unexpectedAL: noBC %s", (const struct ea *)(
# 398 "/home/claude/cfront-3/src/dcl3.cpp"
(__2__X92 = (const void *)__1nn -> __O2__4expr.string ), ( ((& __0__V80 )-> __O1__2ea.p = __2__X92 ), (& __0__V80 )) ) ,
# 398 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 400 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 400 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V81 ;

# 400 "/home/claude/cfront-3/src/dcl3.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"unexpectedAL: noBC%n", (const struct ea *)(
# 400 "/home/claude/cfront-3/src/dcl3.cpp"
((& __0__V81 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V81 )) , (const struct ea *)ea0 , (const struct
# 400 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} con :
# 402 "/home/claude/cfront-3/src/dcl3.cpp"
continue ;

# 402 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 402 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
else { 
# 405 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __4m ;

# 405 "/home/claude/cfront-3/src/dcl3.cpp"
__4m = look__5tableFPCcUc ( __1cl -> memtbl__8classdef , __1nn -> __O2__4expr.string , (unsigned char )0 ) ;
if (__4m && (__4m -> __O4__4expr.n_table == __1cl -> memtbl__8classdef ))
# 407 "/home/claude/cfront-3/src/dcl3.cpp"
__4m -> __O3__4expr.n_initializer = mem_init__3fctFP4nameP4exprP5table ( __0this , __4m , __2i , __1ftbl ) ;
else 
# 409 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 409 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V82 ;

# 409 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V83 ;

# 409 "/home/claude/cfront-3/src/dcl3.cpp"
error__FP3locPCcRC2eaN33 ( & __1nn -> where__4name , (const char *)"%n not inC %s", (const struct ea *)(
# 409 "/home/claude/cfront-3/src/dcl3.cpp"
((& __0__V82 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V82 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V83 ,
# 409 "/home/claude/cfront-3/src/dcl3.cpp"
(const void *)__1cl -> string__8classdef ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
else { 
# 413 "/home/claude/cfront-3/src/dcl3.cpp"
Pbcl __3l ;

# 414 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X93 ;

# 413 "/home/claude/cfront-3/src/dcl3.cpp"
__3l = __1cl -> baselist__8classdef ;
if (__3l == 0 ){ 
# 415 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"unexpectedAL: noBC called") ;
continue ;
}

# 419 "/home/claude/cfront-3/src/dcl3.cpp"
if (__3l -> next__6basecl ){ 
# 420 "/home/claude/cfront-3/src/dcl3.cpp"
bit __4cnt ;

# 420 "/home/claude/cfront-3/src/dcl3.cpp"
bit __4rvb ;

# 420 "/home/claude/cfront-3/src/dcl3.cpp"
__4cnt = 0 ;

# 420 "/home/claude/cfront-3/src/dcl3.cpp"
__4rvb = 0 ;
{ { Pbcl __4ll ;

# 421 "/home/claude/cfront-3/src/dcl3.cpp"
__4ll = __3l ;

# 421 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__4ll ;( (__4ll = __4ll -> next__6basecl ), (++ __4cnt )) ) 
# 422 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__4ll -> base__4node == 77 )&& __4ll -> promoted__6basecl )
# 423 "/home/claude/cfront-3/src/dcl3.cpp"
++ __4rvb ;
# 423 "/home/claude/cfront-3/src/dcl3.cpp"

# 424 "/home/claude/cfront-3/src/dcl3.cpp"
if (__4rvb )
# 425 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 425 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V84 ;

# 425 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V85 ;

# 425 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V86 ;

# 425 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"unnamedBCIr: %dBCes(%d non-explicit virtualBC%s)", (const struct ea *)( (( ((& __0__V84 )->
# 425 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__2ea.i = ((unsigned long )__4cnt )), 0 ) ), (& __0__V84 )) , (const struct ea *)( (( ((&
# 425 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V85 )-> __O1__2ea.i = ((unsigned long )__4rvb )), 0 ) ), (& __0__V85 )) , (const struct ea *)( ((&
# 425 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V86 )-> __O1__2ea.p = ((const void *)((__4rvb == 1 )?"":(((char *)"es"))))),
# 425 "/home/claude/cfront-3/src/dcl3.cpp"
(& __0__V86 )) , (const struct ea *)ea0 ) ;
} else { 
# 426 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V87 ;

# 426 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"unnamedBCIr: %dBCes", (const struct ea *)( (( ((& __0__V87 )->
# 426 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__2ea.i = ((unsigned long )__4cnt )), 0 ) ), (& __0__V87 )) , (const struct ea *)ea0 , (const struct
# 426 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} continue ;

# 427 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 427 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
if (__3l -> init__6basecl )
# 430 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 430 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V88 ;

# 430 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"twoIrs for%t", (const struct ea *)( (__2__X93 = (const void
# 430 "/home/claude/cfront-3/src/dcl3.cpp"
*)__3l -> bclass__6basecl ), ( ((& __0__V88 )-> __O1__2ea.p = __2__X93 ), (& __0__V88 )) ) , (const struct ea *)ea0 ,
# 430 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 431 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X94 ;

# 432 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 432 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V89 ;

# 432 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiP3locPCcRC2eaN34 ( strict_opt ?0 :119, & __1nn -> where__4name , (const char *)"N ofBC%t missing from BCIr (anachronism)", (const struct
# 432 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)( (__2__X94 = (const void *)__3l -> bclass__6basecl ), ( ((& __0__V89 )-> __O1__2ea.p = __2__X94 ), (& __0__V89 )) )
# 432 "/home/claude/cfront-3/src/dcl3.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__3l -> init__6basecl = base_init__3fctFP8classdefP4exprP5tablei ( __0this , __3l -> bclass__6basecl , __2i , __1ftbl , __3l -> obj_offset__6basecl ) ;
} }
}
}

# 438 "/home/claude/cfront-3/src/dcl3.cpp"
{ { Pbcl __1l ;

# 438 "/home/claude/cfront-3/src/dcl3.cpp"
__1l = __1cl -> baselist__8classdef ;

# 438 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__1l ;__1l = __1l -> next__6basecl ) { 
# 440 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __2ctor ;
Pclass __2bcl ;

# 441 "/home/claude/cfront-3/src/dcl3.cpp"
__2bcl = __1l -> bclass__6basecl ;
if ((__1l -> init__6basecl == 0 )&& (__2ctor = ( __2bcl -> c_ctor__8classdef ) ))
# 443 "/home/claude/cfront-3/src/dcl3.cpp"
__1l -> init__6basecl = base_init__3fctFP8classdefP4exprP5tablei ( __0this , __2bcl , (struct
# 443 "/home/claude/cfront-3/src/dcl3.cpp"
expr *)0 , __1ftbl , __1l -> obj_offset__6basecl ) ;
}

# 444 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 444 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 444 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 444 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 447 "/home/claude/cfront-3/src/dcl3.cpp"
int inline_restr = 0 ;

# 76 "/home/claude/cfront-3/src/cfront.h"

# 220 "/home/claude/cfront-3/src/cfront.h"
struct table *__ct__5tableFsP5tableP4name (struct table *__0this , short , Ptable , Pname );

# 477 "/home/claude/cfront-3/src/dcl3.cpp"
extern void for_check_delete__Fv (void );

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 477 "/home/claude/cfront-3/src/cfront.h"
void print_all_vtbls__8classdefFP8classdef (struct classdef *__0this , Pclass );

# 346 "/home/claude/cfront-3/src/cfront.h"
int tsizeof__4typeFi (struct type *__0this , int );

# 940 "/home/claude/cfront-3/src/cfront.h"
Pname dcl__4nameFP5tableUc (struct name *__0this , Ptable , TOK );

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 953 "/home/claude/cfront-3/src/cfront.h"
bit inst_body__4nameFv (struct name *__0this );
bit finst_body__4nameFv (struct name *__0this );

# 1071 "/home/claude/cfront-3/src/cfront.h"
void dcl__5blockFP5table (struct block *__0this , Ptable );

# 946 "/home/claude/cfront-3/src/cfront.h"
void simpl__4nameFv (struct name *__0this );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 657 "/home/claude/cfront-3/src/cfront.h"
struct name_list *__ct__9name_listFP4nameP9name_list (struct name_list *__0this , Pname __1ff , Plist __1ll );

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 932 "/home/claude/cfront-3/src/cfront.h"

# 962 "/home/claude/cfront-3/src/cfront.h"

# 449 "/home/claude/cfront-3/src/dcl3.cpp"
void dcl__3fctFP4name (register struct fct *__0this , Pname __1n )
# 450 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 451 "/home/claude/cfront-3/src/dcl3.cpp"
int __1nmem ;
Pname __1a ;
Pname __1ll ;
Ptable __1ftbl ;

# 456 "/home/claude/cfront-3/src/dcl3.cpp"
int __1const_old ;

# 458 "/home/claude/cfront-3/src/dcl3.cpp"
int __1bit_old ;
int __1byte_old ;
int __1max_old ;

# 461 "/home/claude/cfront-3/src/dcl3.cpp"
unsigned long __2__X102 ;

# 461 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X103 ;

# 461 "/home/claude/cfront-3/src/dcl3.cpp"
unsigned long __2__X104 ;

# 461 "/home/claude/cfront-3/src/dcl3.cpp"
struct dcl_context *__0__X105 ;

# 451 "/home/claude/cfront-3/src/dcl3.cpp"
__1nmem = 20 ;

# 456 "/home/claude/cfront-3/src/dcl3.cpp"
__1const_old = const_save ;

# 458 "/home/claude/cfront-3/src/dcl3.cpp"
__1bit_old = bit_offset ;
__1byte_old = byte_offset ;
__1max_old = max_align ;

# 462 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> base__4node != 108 )
# 463 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 463 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V95 ;

# 463 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"F::dcl(%d)", (const struct ea *)( (__2__X102 =
# 463 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> base__4node ), ( (( ((& __0__V95 )-> __O1__2ea.i = __2__X102 ), 0 ) ), (& __0__V95 )) ) ,
# 463 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__0this -> body__3fct == 0 )
# 465 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 465 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V96 ;

# 465 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"F::dcl(body=%d)", (const struct ea *)( (__2__X103 =
# 465 "/home/claude/cfront-3/src/dcl3.cpp"
(const void *)__0this -> body__3fct ), ( ((& __0__V96 )-> __O1__2ea.p = __2__X103 ), (& __0__V96 )) ) , (const
# 465 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if ((__1n == 0 )|| (__1n -> base__4node != 85 ))
# 467 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 467 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V97 ;

# 467 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V98 ;

# 467 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"F::dcl(N=%d %d)", (const struct ea *)( ((&
# 467 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V97 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V97 )) , (const struct ea *)( (__2__X104 = (__1n ?(((int )__1n ->
# 467 "/home/claude/cfront-3/src/dcl3.cpp"
base__4node )):0 )), ( (( ((& __0__V98 )-> __O1__2ea.i = __2__X104 ), 0 ) ), (& __0__V98 )) ) , (const
# 467 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) ;
} ;
if (__0this -> body__3fct -> __O2__4stmt.own_tbl )
# 470 "/home/claude/cfront-3/src/dcl3.cpp"
return ;

# 472 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> body__3fct -> memtbl__4stmt == 0 )
# 473 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> body__3fct -> memtbl__4stmt = __ct__5tableFsP5tableP4name ( (struct table *)0 , (short )(__1nmem + 3 ), gtbl ,
# 473 "/home/claude/cfront-3/src/dcl3.cpp"
(struct name *)0 ) ;
__0this -> body__3fct -> __O2__4stmt.own_tbl = 1 ;
__1ftbl = __0this -> body__3fct -> memtbl__4stmt ;
__1ftbl -> real_block__5table = (struct stmt *)__0this -> body__3fct ;
;
for_check_delete__Fv ( ) ;

# 480 "/home/claude/cfront-3/src/dcl3.cpp"
max_align = 0 ;
bit_offset = 0 ;

# 483 "/home/claude/cfront-3/src/dcl3.cpp"
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 483 "/home/claude/cfront-3/src/dcl3.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;
cc -> nof__11dcl_context = __1n ;
cc -> ftbl__11dcl_context = __1ftbl ;

# 487 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1n -> n_scope__4name ){ 
# 488 "/home/claude/cfront-3/src/dcl3.cpp"
case 0 :
# 489 "/home/claude/cfront-3/src/dcl3.cpp"
case 25 :
# 490 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 491 "/home/claude/cfront-3/src/dcl3.cpp"
cc -> not4__11dcl_context = __1n -> __O4__4expr.n_table -> t_name__5table ;
cc -> cot__11dcl_context = (((struct classdef *)(((struct classdef *)cc -> not4__11dcl_context -> __O1__4expr.tp ))));
cc -> tot__11dcl_context = cc -> cot__11dcl_context -> this_type__8classdef ;
if (__0this -> f_this__3fct )
# 495 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> f_this__3fct -> __O4__4expr.n_table = __1ftbl ;
cc -> c_this__11dcl_context = __0this -> f_this__3fct ;

# 498 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pclass __3cl ;

# 498 "/home/claude/cfront-3/src/dcl3.cpp"
__3cl = (((struct classdef *)(((struct classdef *)cc -> not4__11dcl_context -> __O1__4expr.tp ))));

# 500 "/home/claude/cfront-3/src/dcl3.cpp"
if ((((((__3cl -> c_body__8classdef == 3 )&& (__1n -> __O3__4expr.n_initializer == 0 ))&& (__1n -> n_sto__4name != 31 ))&& (__0this -> f_inline__3fct == 0 ))&& (__0this ->
# 500 "/home/claude/cfront-3/src/dcl3.cpp"
f_imeasure__3fct == 0 ))&& (__0this -> f_virtual__3fct != 0 ))
# 512 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 514 "/home/claude/cfront-3/src/dcl3.cpp"
int __4i ;
{ { Pname __4nn ;

# 516 "/home/claude/cfront-3/src/dcl3.cpp"
struct table *__0__X106 ;

# 516 "/home/claude/cfront-3/src/dcl3.cpp"
int __2__X107 ;

# 516 "/home/claude/cfront-3/src/dcl3.cpp"
struct table *__0__X108 ;

# 516 "/home/claude/cfront-3/src/dcl3.cpp"
int __2__X109 ;

# 515 "/home/claude/cfront-3/src/dcl3.cpp"
__4nn = ( (__0__X108 = __3cl -> memtbl__8classdef ), ( (__2__X109 = (__4i = 1 )), ( (((__2__X109 <= 0 )|| (__0__X108 -> free_slot__5table <=
# 515 "/home/claude/cfront-3/src/dcl3.cpp"
__2__X109 ))?(((struct name *)0 )):(__0__X108 -> entries__5table [__2__X109 ]))) ) ) ;

# 515 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__4nn ;__4nn = (__4nn -> n_tbl_list__4name ?__4nn -> n_tbl_list__4name :( (__0__X106 = __3cl -> memtbl__8classdef ), ( (__2__X107 = (++ __4i )), ( (((__2__X107 <= 0 )||
# 515 "/home/claude/cfront-3/src/dcl3.cpp"
(__0__X106 -> free_slot__5table <= __2__X107 ))?(((struct name *)0 )):(__0__X106 -> entries__5table [__2__X107 ]))) ) ) )) { 
# 516 "/home/claude/cfront-3/src/dcl3.cpp"
if (__4nn -> base__4node == 123 )continue ;
# 516 "/home/claude/cfront-3/src/dcl3.cpp"

# 517 "/home/claude/cfront-3/src/dcl3.cpp"
{ Ptype __5t ;

# 517 "/home/claude/cfront-3/src/dcl3.cpp"
__5t = __4nn -> __O1__4expr.tp ;

# 519 "/home/claude/cfront-3/src/dcl3.cpp"
if (__5t == 0 )
# 520 "/home/claude/cfront-3/src/dcl3.cpp"
continue ;

# 522 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__5t -> base__4node ){ 
# 523 "/home/claude/cfront-3/src/dcl3.cpp"
case 108 :
# 524 "/home/claude/cfront-3/src/dcl3.cpp"
if (__4nn == __1n )
# 525 "/home/claude/cfront-3/src/dcl3.cpp"
goto prnt ;
if ((((__4nn -> __O3__4expr.n_initializer || (__4nn -> n_sto__4name == 31 ))|| (((struct fct *)(((struct fct *)__4nn -> __O1__4expr.tp ))))-> f_inline__3fct )|| (((struct fct *)(((struct fct *)__4nn ->
# 526 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ))))-> f_imeasure__3fct )|| ((((struct fct *)(((struct fct *)__4nn -> __O1__4expr.tp ))))-> f_virtual__3fct == 0 ))
# 537 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
goto zaq ;

# 540 "/home/claude/cfront-3/src/dcl3.cpp"
case 76 :
# 541 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 542 "/home/claude/cfront-3/src/dcl3.cpp"
{ { Plist __7gl ;

# 542 "/home/claude/cfront-3/src/dcl3.cpp"
__7gl = (((struct gen *)(((struct gen *)__5t ))))-> fct_list__3gen ;

# 542 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__7gl ;__7gl = __7gl -> l__9name_list ) { 
# 543 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __8nn ;

# 543 "/home/claude/cfront-3/src/dcl3.cpp"
__8nn = __7gl -> f__9name_list ;
if (__8nn == __1n )
# 545 "/home/claude/cfront-3/src/dcl3.cpp"
goto prnt ;
if ((((__8nn -> __O3__4expr.n_initializer || (__8nn -> n_sto__4name == 31 ))|| (((struct fct *)(((struct fct *)__8nn -> __O1__4expr.tp ))))-> f_inline__3fct )|| (((struct fct *)(((struct fct *)__8nn ->
# 546 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ))))-> f_imeasure__3fct )|| ((((struct fct *)(((struct fct *)__8nn -> __O1__4expr.tp ))))-> f_virtual__3fct == 0 ))
# 557 "/home/claude/cfront-3/src/dcl3.cpp"
continue ;
goto zaq ;
}

# 559 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 559 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
}

# 561 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
goto zaq ;
prnt :
# 565 "/home/claude/cfront-3/src/dcl3.cpp"
print_all_vtbls__8classdefFP8classdef ( __3cl , __3cl ) ;
goto zaq ;

# 566 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 566 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 567 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
}
zaq :
# 571 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> f_result__3fct == 0 )
# 572 "/home/claude/cfront-3/src/dcl3.cpp"
make_res__FP3fct ( __0this ) ;
if (__0this -> f_result__3fct )
# 574 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> f_result__3fct -> __O4__4expr.n_table = __1ftbl ;

# 576 "/home/claude/cfront-3/src/dcl3.cpp"
tsizeof__4typeFi ( __0this -> returns__3fct , 0 ) ;

# 578 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pname __1ax ;

# 579 "/home/claude/cfront-3/src/dcl3.cpp"
struct dcl_context *__0__X110 ;

# 579 "/home/claude/cfront-3/src/dcl3.cpp"
for(( (__1a = __0this -> argtype__3fct ), (__1ll = 0 )) ;__1a ;__1a = __1ax ) { 
# 580 "/home/claude/cfront-3/src/dcl3.cpp"
__1ax = __1a -> __O1__4name.n_list ;
{ Pname __2nn ;

# 581 "/home/claude/cfront-3/src/dcl3.cpp"
__2nn = dcl__4nameFP5tableUc ( __1a , __1ftbl , (unsigned char )136 ) ;
++ __2nn -> lex_level__4name ;
{ Pname __2cn ;

# 583 "/home/claude/cfront-3/src/dcl3.cpp"
__2cn = is_cl_obj__4typeFv ( __2nn -> __O1__4expr.tp ) ;
if (__2cn == 0 )
# 585 "/home/claude/cfront-3/src/dcl3.cpp"
__2cn = cl_obj_vec ;
if (__2cn )
# 587 "/home/claude/cfront-3/src/dcl3.cpp"
((void )tsizeof__4typeFi ( __2cn -> __O1__4expr.tp , 0 ) );
__2nn -> n_assigned_to__4name = (__2nn -> n_used__4name = (__2nn -> n_addr_taken__4name = 0 ));
__2nn -> __O1__4name.n_list = 0 ;

# 591 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__2nn -> __O1__4expr.tp -> base__4node ){ 
# 592 "/home/claude/cfront-3/src/dcl3.cpp"
case 6 :
# 593 "/home/claude/cfront-3/src/dcl3.cpp"
case 13 :
# 594 "/home/claude/cfront-3/src/dcl3.cpp"
dcl_print__4nameFUc ( __2nn , (unsigned char )0 ) ;
break ;
default :
# 597 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1ll )
# 598 "/home/claude/cfront-3/src/dcl3.cpp"
__1ll -> __O1__4name.n_list = __2nn ;
else 
# 600 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> f_args__3fct = (__0this -> argtype__3fct = __2nn );
__1ll = __2nn ;
}
( (__1a ?(((void )(__1a ?(((void )( ( ((((struct expr *)__1a ))?(((void )((((struct expr *)__1a ))?(((void )(((void )0 )))):(((void )0 ))))):(((void )0 )))) ,
# 603 "/home/claude/cfront-3/src/dcl3.cpp"
(((void )__dl__4nameSFPvUl ( (void *)__1a , (size_t )(sizeof (struct name))) ))) )):(((void )0 ))))):(((void )0 )))) ;

# 603 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 603 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 606 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> f_result__3fct ){ 
# 607 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> f_args__3fct = __0this -> f_result__3fct ;
__0this -> f_result__3fct -> __O1__4name.n_list = __0this -> argtype__3fct ;
}

# 611 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> f_this__3fct ){ 
# 612 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> body__3fct )
# 613 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> f_this__3fct -> where__4name . line__3loc = __1n -> where__4name . line__3loc ;
__0this -> f_args__3fct = __0this -> f_this__3fct ;
__0this -> f_this__3fct -> __O1__4name.n_list = (__0this -> f_result__3fct ?__0this -> f_result__3fct :__0this -> argtype__3fct );
}

# 618 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1n -> n_oper__4name == 161 )|| (__1n -> n_oper__4name == 162 ))
# 619 "/home/claude/cfront-3/src/dcl3.cpp"
vbase_pointers__FP4nameP8classdef ( __1n , cc -> cot__11dcl_context ) ;

# 621 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1n -> n_oper__4name == 161 ){ 
# 622 "/home/claude/cfront-3/src/dcl3.cpp"
const_save = 1 ;
init_bases__3fctFP8classdefP4expr ( __0this , cc -> cot__11dcl_context , (struct expr *)__0this -> f_init__3fct ) ;
}
else if (__0this -> f_init__3fct )
# 626 "/home/claude/cfront-3/src/dcl3.cpp"
error__FP3locPCcRC2eaN33 ( & __0this -> f_init__3fct -> where__4name , (const char *)"unexpectedAL: not aK",
# 626 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 628 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> returns__3fct -> permanent__4node = 1 ;
const_save = (__0this -> f_inline__3fct && (debug_opt == 0 ));
inline_restr = 0 ;
top_block = __0this -> body__3fct ;

# 633 "/home/claude/cfront-3/src/dcl3.cpp"
if (se_opt && ((inst_body__4nameFv ( __1n ) == 0 )|| (finst_body__4nameFv ( __1n ) == 0 )))
# 636 "/home/claude/cfront-3/src/dcl3.cpp"
suppress_error ++ ;

# 638 "/home/claude/cfront-3/src/dcl3.cpp"
dcl__5blockFP5table ( __0this -> body__3fct , __1ftbl ) ;

# 640 "/home/claude/cfront-3/src/dcl3.cpp"
if (se_opt && ((inst_body__4nameFv ( __1n ) == 0 )|| (finst_body__4nameFv ( __1n ) == 0 )))
# 643 "/home/claude/cfront-3/src/dcl3.cpp"
suppress_error -- ;

# 645 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> defined__4type |= 01 ;
if ((__0this -> f_inline__3fct && inline_restr )&& (__0this -> returns__3fct -> base__4node != 38 )){ 
# 647 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> f_inline__3fct = 0 ;
{ const char *__2s ;

# 648 "/home/claude/cfront-3/src/dcl3.cpp"
__2s = (const char *)((inline_restr & 32 )?"continue":(((char *)((inline_restr & 16 )?"break":(((char
# 648 "/home/claude/cfront-3/src/dcl3.cpp"
*)((inline_restr & 8 )?"loop":(((char *)((inline_restr & 4 )?"switch":(((char *)((inline_restr & 2 )?"goto":(((char
# 648 "/home/claude/cfront-3/src/dcl3.cpp"
*)((inline_restr & 1 )?"label":(((char *)""))))))))))))))))));

# 655 "/home/claude/cfront-3/src/dcl3.cpp"
if (warning_opt ){ 
# 656 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 656 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V99 ;

# 656 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V100 ;

# 656 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"\"inline\" ignored,%n contains %s", (const struct ea *)( ((&
# 656 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V99 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V99 )) , (const struct ea *)( ((& __0__V100 )-> __O1__2ea.p =
# 656 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__2s )), (& __0__V100 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
{ 
# 657 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V101 ;

# 657 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"out-of-line copy of%n created", (const struct ea *)( ((&
# 657 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V101 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V101 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 657 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} } }
simpl__4nameFv ( __1n ) ;
if ((cc -> cot__11dcl_context && (cc -> cot__11dcl_context -> class_base__8classdef == 4))&& (cc -> cot__11dcl_context -> c_body__8classdef == 1 ))
# 662 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 663 "/home/claude/cfront-3/src/dcl3.cpp"
current_instantiation = cc -> cot__11dcl_context ;
# 663 "/home/claude/cfront-3/src/dcl3.cpp"

# 664 "/home/claude/cfront-3/src/dcl3.cpp"
dcl_print__4nameFUc ( cc -> not4__11dcl_context , (unsigned char )0 ) ;
current_instantiation = 0 ;
}
dcl_print__4nameFUc ( __1n , (unsigned char )0 ) ;

# 667 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
const_save = __1const_old ;

# 671 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> f_inline__3fct && (debug_opt == 0 ))
# 672 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 673 "/home/claude/cfront-3/src/dcl3.cpp"
if (dtpt_opt && (inst_body__4nameFv ( __1n ) == 0 )){ 
# 673 "/home/claude/cfront-3/src/dcl3.cpp"
unsigned long __2__X16 ;
# 673 "/home/claude/cfront-3/src/dcl3.cpp"

# 673 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__X__V1400qmhxl1b4vcnm ;

# 673 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__X__V1500qmhxl1b4vcnm ;

# 674 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> f_inline__3fct = 0 ;
( ((__1n -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF",
# 675 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)( ((& __0__X__V1400qmhxl1b4vcnm )-> __O1__2ea.p = ((const void *)__1n )), (& __0__X__V1400qmhxl1b4vcnm )) , (const struct
# 675 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)( (__2__X16 = __1n -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500qmhxl1b4vcnm )-> __O1__2ea.i = __2__X16 ), 0 ) ), (&
# 675 "/home/claude/cfront-3/src/dcl3.cpp"
__0__X__V1500qmhxl1b4vcnm )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ->
# 675 "/home/claude/cfront-3/src/dcl3.cpp"
body__3fct = 0 ;
}
isf_list = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __1n , isf_list ) ;
}

# 680 "/home/claude/cfront-3/src/dcl3.cpp"
bit_offset = __1bit_old ;
byte_offset = __1byte_old ;
max_align = __1max_old ;
( ( (cc -- ), (((void )0 ))) ) ;

# 683 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 686 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 688 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr this_handler = 0 ;

# 532 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr rptr__FP4typeP4expri (Ptype , Pexpr , int );

# 466 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 798 "/home/claude/cfront-3/src/cfront.h"
Pexpr typ__4exprFP5table (struct expr *__0this , Ptable );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 460 "/home/claude/cfront-3/src/cfront.h"
bit has_base__8classdefFP8classdefiT2 (struct classdef *__0this , Pclass __1cl , int __1level , int __1ccflag );

# 820 "/home/claude/cfront-3/src/cfront.h"

# 804 "/home/claude/cfront-3/src/cfront.h"
Pexpr contents__4exprFv (struct expr *__0this );

# 493 "/home/claude/cfront-3/src/cfront.h"

# 820 "/home/claude/cfront-3/src/cfront.h"

# 1228 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr call_ctor__FP5tableP4exprN22iT2 (Ptable , Pexpr __0p , Pexpr __0ctor , Pexpr __0args , int __0d , Pexpr __0vb_args );

# 689 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr base_init__3fctFP8classdefP4exprP5tablei (register struct fct *__0this , Pclass __1bcl , Pexpr __1i , Ptable __1ftbl , int __1offset )
# 695 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 696 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __1ty ;
Pexpr __1th ;
Pname __1ctor ;

# 701 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __1ii ;

# 729 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __1icn ;

# 696 "/home/claude/cfront-3/src/dcl3.cpp"
__1ty = __1bcl -> this_type__8classdef ;
__1th = rptr__FP4typeP4expri ( __1ty , (struct expr *)__0this -> f_this__3fct , __1offset ) ;
__1ctor = ( __1bcl -> c_ctor__8classdef ) ;

# 701 "/home/claude/cfront-3/src/dcl3.cpp"
__1ii = ((__1i && (__1i -> base__4node == 140 ))?__1i -> __O2__4expr.e1 :__1i );

# 703 "/home/claude/cfront-3/src/dcl3.cpp"
if (((__1ii && (__1ii -> base__4node == 111 ))&& ((__1ii -> __O2__4expr.e1 -> base__4node == 113 )|| (__1ii -> __O2__4expr.e1 -> base__4node == 191 )))&& ((__1th ->
# 703 "/home/claude/cfront-3/src/dcl3.cpp"
base__4node == 113 )|| (__1th -> base__4node == 191 )))
# 707 "/home/claude/cfront-3/src/dcl3.cpp"
__1th -> __O3__4expr.i2 = __1ii -> __O2__4expr.e1 -> __O3__4expr.i2 ;

# 709 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1ctor == 0 ){ 
# 710 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1i && (__1i -> base__4node != 140 ))
# 711 "/home/claude/cfront-3/src/dcl3.cpp"
__1i = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 ,
# 711 "/home/claude/cfront-3/src/dcl3.cpp"
__1i , (struct expr *)0 ) ;

# 713 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pexpr __2v ;

# 714 "/home/claude/cfront-3/src/dcl3.cpp"
struct texpr *__0__X113 ;

# 713 "/home/claude/cfront-3/src/dcl3.cpp"
__2v = (struct expr *)( (__0__X113 = 0 ), ( ((__0__X113 || (__0__X113 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 713 "/home/claude/cfront-3/src/dcl3.cpp"
))?( (__0__X113 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X113 ), ((unsigned char )157 ), __1i , (struct expr *)0 ) ), (__0__X113 ->
# 713 "/home/claude/cfront-3/src/dcl3.cpp"
__O4__4expr.tp2 = ((struct type *)__1bcl ))) :0 ), __0__X113 ) ) ;
__2v -> __O3__4expr.e2 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )111 , __1th , (struct expr *)0 ) ;
__2v = typ__4exprFP5table ( __2v , __1ftbl ) ;

# 717 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__2v -> base__4node ){ 
# 717 "/home/claude/cfront-3/src/dcl3.cpp"
struct texpr *__0__X111 ;

# 717 "/home/claude/cfront-3/src/dcl3.cpp"
struct expr *__2__X112 ;

# 718 "/home/claude/cfront-3/src/dcl3.cpp"
case 111 :
# 719 "/home/claude/cfront-3/src/dcl3.cpp"
return __2v -> __O2__4expr.e1 ;
case 70 :
# 721 "/home/claude/cfront-3/src/dcl3.cpp"
__1th = (struct expr *)( (__0__X111 = 0 ), ( (__2__X112 = (struct expr *)__0this -> f_this__3fct ), ( ((__0__X111 || (__0__X111 =
# 721 "/home/claude/cfront-3/src/dcl3.cpp"
(struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X111 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X111 ), ((unsigned char
# 721 "/home/claude/cfront-3/src/dcl3.cpp"
)191 ), __2__X112 , (struct expr *)0 ) ), (__0__X111 -> __O4__4expr.tp2 = __1ty )) :0 ), __0__X111 ) ) ) ;
__2v = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __2v , __1th ) ;
return typ__4exprFP5table ( __2v , __1ftbl ) ;
default :
# 725 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct expr *)0 ;
}

# 726 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 729 "/home/claude/cfront-3/src/dcl3.cpp"
;
if (__1i ){ 
# 731 "/home/claude/cfront-3/src/dcl3.cpp"
int __2na ;

# 732 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__1__X114 ;

# 732 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__1__X115 ;

# 731 "/home/claude/cfront-3/src/dcl3.cpp"
__2na = ((__1i -> base__4node != 140 )?1 :((__1i -> __O3__4expr.e2 != 0 )?2 :1 ));
__1ii = typ__4exprFP5table ( __1ii , __1ftbl ) ;
if ((((( __1bcl -> c_itor__8classdef ) == 0 )&& (__1icn = is_cl_obj__4typeFv ( __1ii -> __O1__4expr.tp ) ))&& (__2na == 1 ))&& ((
# 733 "/home/claude/cfront-3/src/dcl3.cpp"
(__1__X114 = (((struct classdef *)(((struct classdef *)__1icn -> __O1__4expr.tp ))))), ( (__1__X115 = __1bcl ), ( ((__1__X114 == __1__X115 )?1 :((__1__X114 && __1__X115 )?(((int )same_class__8classdefFP8classdefi ( __1__X114 ,
# 733 "/home/claude/cfront-3/src/dcl3.cpp"
__1__X115 , 0 ) )):0 ))) ) ) || has_base__8classdefFP8classdefiT2 ( ((struct classdef *)(((struct classdef *)__1icn -> __O1__4expr.tp ))), __1bcl , 0 , 0 )
# 733 "/home/claude/cfront-3/src/dcl3.cpp"
))
# 745 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 745 "/home/claude/cfront-3/src/dcl3.cpp"
struct texpr *__0__X116 ;

# 745 "/home/claude/cfront-3/src/dcl3.cpp"
struct expr *__2__X117 ;

# 745 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__1__X118 ;

# 745 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__1__X119 ;

# 749 "/home/claude/cfront-3/src/dcl3.cpp"
this_handler = __1th ;
__1th = (struct expr *)( (__0__X116 = 0 ), ( (__2__X117 = (struct expr *)__0this -> f_this__3fct ), ( ((__0__X116 || (__0__X116 = (struct
# 750 "/home/claude/cfront-3/src/dcl3.cpp"
texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr))) ))?( (__0__X116 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X116 ), ((unsigned char )191 ),
# 750 "/home/claude/cfront-3/src/dcl3.cpp"
__2__X117 , (struct expr *)0 ) ), (__0__X116 -> __O4__4expr.tp2 = __1ty )) :0 ), __0__X116 ) ) ) ;
__1th = contents__4exprFv ( __1th ) ;
__1th = typ__4exprFP5table ( __1th , __1ftbl ) ;
if (! ( (__1__X118 = (((struct classdef *)(((struct classdef *)__1icn -> __O1__4expr.tp ))))), ( (__1__X119 = __1bcl ), ( ((__1__X118 == __1__X119 )?1 :((__1__X118 &&
# 753 "/home/claude/cfront-3/src/dcl3.cpp"
__1__X119 )?(((int )same_class__8classdefFP8classdefi ( __1__X118 , __1__X119 , 0 ) )):0 ))) ) ) ){ 
# 754 "/home/claude/cfront-3/src/dcl3.cpp"
Pptr __4r ;

# 755 "/home/claude/cfront-3/src/dcl3.cpp"
struct texpr *__0__X120 ;

# 754 "/home/claude/cfront-3/src/dcl3.cpp"
__4r = __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )158 , (((struct ptr *)(((struct ptr *)__1ty ))))-> typ__5pvtyp ) ;
__1ii = (struct expr *)( (__0__X120 = 0 ), ( ((__0__X120 || (__0__X120 = (struct texpr *)__nw__4exprSFUl ( (size_t )(sizeof (struct texpr)))
# 755 "/home/claude/cfront-3/src/dcl3.cpp"
))?( (__0__X120 = (struct texpr *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X120 ), ((unsigned char )191 ), __1ii , (struct expr *)0 ) ), (__0__X120 ->
# 755 "/home/claude/cfront-3/src/dcl3.cpp"
__O4__4expr.tp2 = ((struct type *)__4r ))) :0 ), __0__X120 ) ) ;
__1ii = typ__4exprFP5table ( __1ii , __1ftbl ) ;
}
__1ii = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , __1th , __1ii ) ;
__1ii -> __O1__4expr.tp = __1th -> __O1__4expr.tp ;

# 765 "/home/claude/cfront-3/src/dcl3.cpp"
__1ii = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )71 , __1ii , this_handler ) ;
this_handler = 0 ;
__1ii -> __O1__4expr.tp = __1ty ;

# 769 "/home/claude/cfront-3/src/dcl3.cpp"
return __1ii ;
}
if (__1i -> base__4node == 140 )
# 772 "/home/claude/cfront-3/src/dcl3.cpp"
__1i -> __O2__4expr.e1 = __1ii ;
}

# 775 "/home/claude/cfront-3/src/dcl3.cpp"
return call_ctor__FP5tableP4exprN22iT2 ( __1ftbl , __1th , (struct expr *)__1ctor , __1i , 44 , vbase_args__FP3fctP4name ( __0this , __1ctor ) ) ;
}

# 844 "/home/claude/cfront-3/src/cfront.h"

# 466 "/home/claude/cfront-3/src/cfront.h"

# 468 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 943 "/home/claude/cfront-3/src/cfront.h"
void assign__4nameFv (struct name *__0this );

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 1227 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ptr_init__FP3ptrP4exprP5table (Pptr , Pexpr , Ptable );

# 738 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ref_init__FP3ptrP4exprP5table (Pptr , Pexpr , Ptable );

# 779 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr mem_init__3fctFP4nameP4exprP5table (register struct fct *__0this , Pname __1mn , Pexpr __1i , Ptable __1ftbl )
# 783 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 792 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1mn -> n_stclass__4name ){ 
# 793 "/home/claude/cfront-3/src/dcl3.cpp"
case 31 :
# 794 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 794 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V121 ;

# 794 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"MIr for static%n", (const struct ea *)( ((& __0__V121 )-> __O1__2ea.p =
# 794 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1mn )), (& __0__V121 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 794 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
break ;
case 13 :
# 797 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 797 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V122 ;

# 797 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"MIr for enumeration constant%n", (const struct ea *)( ((& __0__V122 )-> __O1__2ea.p =
# 797 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1mn )), (& __0__V122 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 797 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
break ;
} } }

# 801 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pname __1member ;

# 801 "/home/claude/cfront-3/src/dcl3.cpp"
__1member = (((__1mn -> base__4node == 25 )&& __1mn -> __O2__4name.n_qualifier )?__1mn -> __O2__4name.n_qualifier :__1mn );

# 807 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1i )
# 808 "/home/claude/cfront-3/src/dcl3.cpp"
__1i = typ__4exprFP5table ( __1i , __1ftbl ) ;

# 810 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pname __1cn ;
Pref __1tn ;

# 880 "/home/claude/cfront-3/src/dcl3.cpp"
Pptr __1pt ;

# 881 "/home/claude/cfront-3/src/dcl3.cpp"
struct ref *__0__X136 ;

# 881 "/home/claude/cfront-3/src/dcl3.cpp"
struct expr *__2__X137 ;

# 881 "/home/claude/cfront-3/src/dcl3.cpp"
struct expr *__2__X138 ;

# 810 "/home/claude/cfront-3/src/dcl3.cpp"
__1cn = is_cl_obj__4typeFv ( __1member -> __O1__4expr.tp ) ;
__1tn = ( (__0__X136 = 0 ), ( (__2__X137 = (struct expr *)__0this -> f_this__3fct ), ( (__2__X138 = (struct expr *)__1member ), (
# 811 "/home/claude/cfront-3/src/dcl3.cpp"
((__0__X136 || (__0__X136 = (struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X136 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X136 ),
# 811 "/home/claude/cfront-3/src/dcl3.cpp"
((unsigned char )44 ), __2__X137 , (struct expr *)0 ) ), (__0__X136 -> __O4__4expr.mem = __2__X138 )) :0 ), __0__X136 ) ) )
# 811 "/home/claude/cfront-3/src/dcl3.cpp"
) ;

# 813 "/home/claude/cfront-3/src/dcl3.cpp"
__1tn -> __O1__4expr.tp = __1member -> __O1__4expr.tp ;

# 816 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cn ){ 
# 817 "/home/claude/cfront-3/src/dcl3.cpp"
Pclass __2mcl ;
Pname __2ctor ;
Pname __2icn ;

# 820 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__1__X132 ;

# 820 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__1__X133 ;

# 817 "/home/claude/cfront-3/src/dcl3.cpp"
__2mcl = (((struct classdef *)(((struct classdef *)__1cn -> __O1__4expr.tp ))));
__2ctor = ( __2mcl -> c_ctor__8classdef ) ;

# 821 "/home/claude/cfront-3/src/dcl3.cpp"
if (((__1i && (( __2mcl -> c_itor__8classdef ) == 0 ))&& (__2icn = is_cl_obj__4typeFv ( __1i -> __O1__4expr.tp ) ))&& ( (__1__X132 =
# 821 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct classdef *)(((struct classdef *)__2icn -> __O1__4expr.tp ))))), ( (__1__X133 = __2mcl ), ( ((__1__X132 == __1__X133 )?1 :((__1__X132 && __1__X133 )?(((int )same_class__8classdefFP8classdefi ( __1__X132 , __1__X133 ,
# 821 "/home/claude/cfront-3/src/dcl3.cpp"
0 ) )):0 ))) ) ) )
# 829 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 830 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __3init ;

# 830 "/home/claude/cfront-3/src/dcl3.cpp"
__3init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1tn , __1i ) ;
__3init -> __O1__4expr.tp = __1tn -> __O1__4expr.tp ;
assign__4nameFv ( __1member ) ;
return __3init ;
}

# 836 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2ctor )
# 837 "/home/claude/cfront-3/src/dcl3.cpp"
return call_ctor__FP5tableP4exprN22iT2 ( __1ftbl , (struct expr *)__1tn , (struct expr *)__2ctor , __1i , 45 , (struct expr *)0 ) ;

# 839 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 839 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V123 ;

# 839 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"Ir forM%nW noK", (const struct ea *)( ((& __0__V123 )-> __O1__2ea.p =
# 839 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1member )), (& __0__V123 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 839 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
return (struct expr *)0 ;
} }

# 843 "/home/claude/cfront-3/src/dcl3.cpp"
if (cl_obj_vec ){ 
# 843 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X134 ;

# 843 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X135 ;

# 844 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1i && (__1i -> base__4node == 140 ))
# 845 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 845 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V124 ;

# 845 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V125 ;

# 845 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"illegalIrL for %t%nWinM initializationL", (const struct ea *)( (__2__X134 = (const void
# 845 "/home/claude/cfront-3/src/dcl3.cpp"
*)__1mn -> __O1__4expr.tp ), ( ((& __0__V124 )-> __O1__2ea.p = __2__X134 ), (& __0__V124 )) ) , (const struct ea *)(
# 845 "/home/claude/cfront-3/src/dcl3.cpp"
((& __0__V125 )-> __O1__2ea.p = ((const void *)__1mn )), (& __0__V125 )) , (const struct ea *)ea0 , (const struct
# 845 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else 
# 847 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 847 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V126 ;

# 847 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V127 ;

# 847 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"Ir forCM %t%nWK", (const struct ea *)( (__2__X135 =
# 847 "/home/claude/cfront-3/src/dcl3.cpp"
(const void *)__1mn -> __O1__4expr.tp ), ( ((& __0__V126 )-> __O1__2ea.p = __2__X135 ), (& __0__V126 )) ) , (const
# 847 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V127 )-> __O1__2ea.p = ((const void *)__1mn )), (& __0__V127 )) , (const struct ea *)ea0 ,
# 847 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} return (struct expr *)0 ;
}

# 851 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1i && (__1i -> base__4node == 140 )){ 
# 852 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1i -> __O3__4expr.e2 )
# 853 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 853 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V128 ;

# 853 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"Ir for%n not a simpleE", (const struct ea *)( ((& __0__V128 )-> __O1__2ea.p =
# 853 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1member )), (& __0__V128 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 853 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} __1i = __1i -> __O2__4expr.e1 ;
}

# 857 "/home/claude/cfront-3/src/dcl3.cpp"
if (is_ref__4typeFv ( __1member -> __O1__4expr.tp ) && (__1i == 0 )){ 
# 858 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 858 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V129 ;

# 858 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"emptyIr for reference%n", (const struct ea *)( ((& __0__V129 )-> __O1__2ea.p =
# 858 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1member )), (& __0__V129 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 858 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
return (struct expr *)0 ;
} }

# 863 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1member -> __O1__4expr.tp -> base__4node ){ 
# 864 "/home/claude/cfront-3/src/dcl3.cpp"
case 110 :
# 865 "/home/claude/cfront-3/src/dcl3.cpp"
case 108 :
# 866 "/home/claude/cfront-3/src/dcl3.cpp"
case 76 :
# 867 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 867 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V130 ;

# 867 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V131 ;

# 867 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"Ir for%n ofT %t", (const struct ea *)( ((& __0__V130 )-> __O1__2ea.p =
# 867 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1member )), (& __0__V130 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V131 , (const void *)__1member ->
# 867 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return (struct expr *)0 ;
} }

# 872 "/home/claude/cfront-3/src/dcl3.cpp"
if (tconst__4typeFv ( __1member -> __O1__4expr.tp ) ){ 
# 873 "/home/claude/cfront-3/src/dcl3.cpp"
ignore_const ++ ;
__1i = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1tn , __1i ) ;
__1i = typ__4exprFP5table ( __1i , __1ftbl ) ;
ignore_const -- ;
return __1i ;
}

# 880 "/home/claude/cfront-3/src/dcl3.cpp"
;
if (__1pt = is_ref__4typeFv ( __1member -> __O1__4expr.tp ) ){ 
# 882 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1pt -> typ__5pvtyp -> base__4node ){ 
# 883 "/home/claude/cfront-3/src/dcl3.cpp"
case 108 :
# 884 "/home/claude/cfront-3/src/dcl3.cpp"
case 76 :
# 885 "/home/claude/cfront-3/src/dcl3.cpp"
__1i = ptr_init__FP3ptrP4exprP5table (
# 885 "/home/claude/cfront-3/src/dcl3.cpp"
__1pt , __1i , __1ftbl ) ;
break ;
default :
# 888 "/home/claude/cfront-3/src/dcl3.cpp"
__1i = ref_init__FP3ptrP4exprP5table ( __1pt , __1i , __1ftbl ) ;
}
__1i = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1tn , __1i ) ;
__1i -> __O1__4expr.tp = __1tn -> __O1__4expr.tp ;
assign__4nameFv ( __1member ) ;
return __1i ;
}

# 896 "/home/claude/cfront-3/src/dcl3.cpp"
__1i = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )70 , (struct expr *)__1tn , __1i ) ;
return typ__4exprFP5table ( __1i , __1ftbl ) ;

# 897 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 897 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 900 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr replace_temp__FP4exprT1 (Pexpr __1e , Pexpr __1n )
# 913 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 914 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __1c ;
Pexpr __1ff ;
Pexpr __1a ;
Pexpr __1tmp ;

# 914 "/home/claude/cfront-3/src/dcl3.cpp"
__1c = __1e -> __O2__4expr.e1 ;
__1ff = __1c -> __O2__4expr.e1 ;
__1a = __1c -> __O3__4expr.e2 ;
__1tmp = __1e -> __O3__4expr.e2 ;

# 920 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1tmp -> base__4node == 111 )
# 921 "/home/claude/cfront-3/src/dcl3.cpp"
__1tmp = __1tmp -> __O2__4expr.e1 ;
if ((__1tmp -> base__4node == 113 )|| (__1tmp -> base__4node == 191 ))
# 923 "/home/claude/cfront-3/src/dcl3.cpp"
__1tmp = __1tmp -> __O2__4expr.e1 ;
if ((__1tmp -> base__4node == 112 )|| (__1tmp -> base__4node == 145 ))
# 925 "/home/claude/cfront-3/src/dcl3.cpp"
__1tmp = __1tmp -> __O3__4expr.e2 ;
if (__1tmp -> base__4node != 85 )
# 927 "/home/claude/cfront-3/src/dcl3.cpp"
return __1e ;
__1tmp -> __O1__4expr.tp = (struct type *)any_type ;

# 931 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1ff -> base__4node ){ 
# 932 "/home/claude/cfront-3/src/dcl3.cpp"
case 44 :
# 933 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1ff -> __O2__4expr.e1 -> base__4node == 145 )&& (__1ff -> __O2__4expr.e1 -> __O3__4expr.e2 == __1tmp ))
# 934 "/home/claude/cfront-3/src/dcl3.cpp"
__1a = __1ff ;
# 934 "/home/claude/cfront-3/src/dcl3.cpp"

# 935 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
case 45 :
# 937 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1ff -> __O2__4expr.e1 -> base__4node == 85 )&& (__1ff -> __O2__4expr.e1 == __1tmp )){ 
# 938 "/home/claude/cfront-3/src/dcl3.cpp"
__1a = __1ff ;
__1a -> base__4node = 44 ;
}
break ;
}
__1a -> __O2__4expr.e1 = __1n ;
return __1c ;
}

# 466 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 947 "/home/claude/cfront-3/src/dcl3.cpp"
Pname has_ictor__8classdefFv (register struct classdef *__0this )
# 951 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 952 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __1c ;

# 952 "/home/claude/cfront-3/src/dcl3.cpp"
__1c = ( __0this -> c_ctor__8classdef ) ;
if (__1c == 0 )
# 954 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct name *)0 ;

# 956 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pfct __1f ;

# 956 "/home/claude/cfront-3/src/dcl3.cpp"
__1f = (((struct fct *)(((struct fct *)__1c -> __O1__4expr.tp ))));

# 958 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1f -> base__4node ){ 
# 958 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X141 ;

# 958 "/home/claude/cfront-3/src/dcl3.cpp"
unsigned long __2__X142 ;

# 959 "/home/claude/cfront-3/src/dcl3.cpp"
default :
# 960 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 960 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V139 ;

# 960 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V140 ;

# 960 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%s: badK (%k)", (const struct ea *)( (__2__X141 =
# 960 "/home/claude/cfront-3/src/dcl3.cpp"
(const void *)__0this -> string__8classdef ), ( ((& __0__V139 )-> __O1__2ea.p = __2__X141 ), (& __0__V139 )) ) , (const
# 960 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( (__2__X142 = __1c -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__V140 )-> __O1__2ea.i = __2__X142 ), 0 ) ),
# 960 "/home/claude/cfront-3/src/dcl3.cpp"
(& __0__V140 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;

# 962 "/home/claude/cfront-3/src/dcl3.cpp"
case 108 :
# 963 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1f -> nargs__3fct ){ 
# 964 "/home/claude/cfront-3/src/dcl3.cpp"
case 0 :
# 965 "/home/claude/cfront-3/src/dcl3.cpp"
return __1c ;
default :
# 967 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> argtype__3fct -> __O3__4expr.n_initializer )
# 968 "/home/claude/cfront-3/src/dcl3.cpp"
return __1c ;
}
return (struct name *)0 ;

# 972 "/home/claude/cfront-3/src/dcl3.cpp"
case 76 :
# 973 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 974 "/home/claude/cfront-3/src/dcl3.cpp"
{ { Plist __3l ;

# 974 "/home/claude/cfront-3/src/dcl3.cpp"
__3l = (((struct gen *)(((struct gen *)__1f ))))-> fct_list__3gen ;

# 974 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__3l ;__3l = __3l -> l__9name_list ) { 
# 975 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __4n ;

# 975 "/home/claude/cfront-3/src/dcl3.cpp"
__4n = __3l -> f__9name_list ;
__1f = (((struct fct *)(((struct fct *)__4n -> __O1__4expr.tp ))));
switch (__1f -> nargs__3fct ){ 
# 978 "/home/claude/cfront-3/src/dcl3.cpp"
case 0 :
# 979 "/home/claude/cfront-3/src/dcl3.cpp"
return __4n ;
default :
# 981 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> argtype__3fct -> __O3__4expr.n_initializer )
# 982 "/home/claude/cfront-3/src/dcl3.cpp"
return __4n ;
}
}
return (struct name *)0 ;

# 985 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 985 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
} }

# 987 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 990 "/home/claude/cfront-3/src/dcl3.cpp"
int add_first = 0 ;
static int add_without_find ;

# 649 "/home/claude/cfront-3/src/cfront.h"

# 674 "/home/claude/cfront-3/src/cfront.h"

# 675 "/home/claude/cfront-3/src/cfront.h"

# 669 "/home/claude/cfront-3/src/cfront.h"
Pname find__3genFP3fctUc (struct gen *__0this , Pfct , bit );

# 648 "/home/claude/cfront-3/src/cfront.h"
void sign__3fctFv (struct fct *__0this );

# 993 "/home/claude/cfront-3/src/dcl3.cpp"
Pname add__3genFP4name (register struct gen *__0this , Pname __1n )
# 1002 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1003 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __1f ;
Pname __1nx ;

# 1003 "/home/claude/cfront-3/src/dcl3.cpp"
__1f = (((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))));

# 1006 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> base__4node != 108 )
# 1007 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1007 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V143 ;

# 1007 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n: overloaded nonF", (const struct ea *)( ((& __0__V143 )-> __O1__2ea.p =
# 1007 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1n )), (& __0__V143 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1007 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} 
# 1013 "/home/claude/cfront-3/src/dcl3.cpp"
if (( (__1f -> fct_base__3fct != 0)) ){ 
# 1014 "/home/claude/cfront-3/src/dcl3.cpp"
if (! ( (__0this -> holds_templ__3gen != 0)) ){
# 1014 "/home/claude/cfront-3/src/dcl3.cpp"

# 1015 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> fct_list__3gen )
# 1016 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> holds_templ__3gen = 1;
else __0this -> holds_templ__3gen = 2;
}
}
else 
# 1019 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1020 "/home/claude/cfront-3/src/dcl3.cpp"
if (( (__0this -> holds_templ__3gen == 2)) )
# 1021 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> holds_templ__3gen = 1;
}

# 1025 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__0this -> fct_list__3gen && (add_without_find == 0 ))&& (__1nx = find__3genFP3fctUc ( __0this , __1f , (unsigned char )1 ) )){ 
# 1027 "/home/claude/cfront-3/src/dcl3.cpp"
int
# 1027 "/home/claude/cfront-3/src/dcl3.cpp"
__2l1 ;
int __2l2 ;

# 1027 "/home/claude/cfront-3/src/dcl3.cpp"
__2l1 = (((struct fct *)(((struct fct *)__1nx -> __O1__4expr.tp ))))-> f_linkage__3fct ;
__2l2 = __1f -> f_linkage__3fct ;
if ((__2l2 != 0)&& (__2l1 != __2l2 ))
# 1030 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1030 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V144 ;

# 1030 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"inconsistent linkage specifications for%n", (const struct ea *)( ((& __0__V144 )-> __O1__2ea.p =
# 1030 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1n )), (& __0__V144 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1030 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} Nold = 1 ;
}
else { 
# 1034 "/home/claude/cfront-3/src/dcl3.cpp"
if (((add_first == 0 )&& (__1f -> f_signature__3fct == 0 ))&& (__1f -> fct_base__3fct != 1))
# 1035 "/home/claude/cfront-3/src/dcl3.cpp"
sign__3fctFv ( __1f ) ;

# 1037 "/home/claude/cfront-3/src/dcl3.cpp"
__1nx = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
((*__1nx ))= (*__1n );
__1nx -> n_gen_fct_name__4name = __1n -> __O2__4expr.string ;
__1nx -> permanent__4node = 1 ;
Nold = 0 ;
if (__0this -> fct_list__3gen ){ 
# 1043 "/home/claude/cfront-3/src/dcl3.cpp"
int __3clink ;
Plist __3gl ;

# 1043 "/home/claude/cfront-3/src/dcl3.cpp"
__3clink = (__1f -> f_linkage__3fct == 1);
__3gl = __0this -> fct_list__3gen ;
for(;;) { 
# 1046 "/home/claude/cfront-3/src/dcl3.cpp"
if (__3clink && ((((struct fct *)(((struct fct *)__3gl -> f__9name_list -> __O1__4expr.tp ))))-> f_linkage__3fct == 1)){ 
# 1047 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1047 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V145 ;
# 1047 "/home/claude/cfront-3/src/dcl3.cpp"

# 1047 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"two%ns with c linkage", (const struct ea *)( ((& __0__V145 )-> __O1__2ea.p =
# 1047 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1n )), (& __0__V145 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1047 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
if (__1f -> f_signature__3fct == 0 )
# 1049 "/home/claude/cfront-3/src/dcl3.cpp"
sign__3fctFv ( __1f ) ;
} }
if (__3gl -> l__9name_list )
# 1052 "/home/claude/cfront-3/src/dcl3.cpp"
__3gl = __3gl -> l__9name_list ;
else 
# 1054 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
}
__3gl -> l__9name_list = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __1nx , (struct name_list *)0 ) ;
}
else 
# 1059 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> fct_list__3gen = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __1nx , (struct name_list *)0 ) ;
__1nx -> __O1__4name.n_list = 0 ;
}
return __1nx ;
}

# 1065 "/home/claude/cfront-3/src/dcl3.cpp"
void sign__3fctFv (register struct fct *__0this )
# 1066 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1067 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__0this -> f_linkage__3fct ){ 
# 1068 "/home/claude/cfront-3/src/dcl3.cpp"
case 1:
# 1069 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> f_signature__3fct = (const char *)"";
# 1069 "/home/claude/cfront-3/src/dcl3.cpp"

# 1070 "/home/claude/cfront-3/src/dcl3.cpp"
return ;
case 2:
# 1072 "/home/claude/cfront-3/src/dcl3.cpp"
case 0:
# 1073 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
}
{ char __1buf [1024];
char *__1bb ;
int __1ll ;

# 1076 "/home/claude/cfront-3/src/dcl3.cpp"
__1bb = signature__4typeFPci ( (struct type *)__0this , (char *)__1buf , 0 ) ;
__1ll = (__1bb - __1buf );
if (1023 < __1ll )
# 1079 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCc ( (int )'i' , (const char *)"gen::add():N buffer overflow") ;
{ char *__1p ;

# 1080 "/home/claude/cfront-3/src/dcl3.cpp"
__1p = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* (__1ll + 1 ))) ));
strcpy ( __1p , (const char *)__1buf ) ;
__0this -> f_signature__3fct = (const char *)__1p ;

# 1082 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 1082 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 1084 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 670 "/home/claude/cfront-3/src/cfront.h"
Pname match__3genFP4nameP3fctUc (struct gen *__0this , Pname , Pfct , bit );

# 1086 "/home/claude/cfront-3/src/dcl3.cpp"
Pname find__3genFP3fctUc (register struct gen *__0this , Pfct __1f , bit __1warn )
# 1087 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1088 "/home/claude/cfront-3/src/dcl3.cpp"
{ { Plist __1gl ;

# 1088 "/home/claude/cfront-3/src/dcl3.cpp"
__1gl = __0this -> fct_list__3gen ;

# 1088 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__1gl ;__1gl = __1gl -> l__9name_list ) { 
# 1089 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __2n ;

# 1089 "/home/claude/cfront-3/src/dcl3.cpp"
__2n = match__3genFP4nameP3fctUc ( __0this , __1gl -> f__9name_list , __1f , __1warn ) ;
if (__2n )
# 1091 "/home/claude/cfront-3/src/dcl3.cpp"
return __2n ;
}
return (struct name *)0 ;

# 1093 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 1093 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 649 "/home/claude/cfront-3/src/cfront.h"

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 342 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr__4typeFv (struct type *__0this );

# 1096 "/home/claude/cfront-3/src/dcl3.cpp"
Pname match__3genFP4nameP3fctUc (register struct gen *__0this , Pname __1nx , Pfct __1f , bit __1warn )
# 1097 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1098 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __1fx ;
Pname __1a ;

# 1099 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __1ax ;
int __1op ;

# 1098 "/home/claude/cfront-3/src/dcl3.cpp"
__1fx = (((struct fct *)(((struct fct *)__1nx -> __O1__4expr.tp ))));

# 1100 "/home/claude/cfront-3/src/dcl3.cpp"
__1op = 0 ;

# 1103 "/home/claude/cfront-3/src/dcl3.cpp"
if (( (__1f -> fct_base__3fct != 0)) )return (struct name *)0 ;
if (( (__1fx -> fct_base__3fct != 0)) )return (struct name *)0 ;

# 1107 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> nargs_known__3fct != __1fx -> nargs_known__3fct )
# 1108 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct name *)0 ;

# 1110 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_const__3fct != __1fx -> f_const__3fct )
# 1111 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct name *)0 ;

# 1113 "/home/claude/cfront-3/src/dcl3.cpp"
if (((__1fx -> nargs__3fct != __1f -> nargs__3fct )&& (__1fx -> nargs_known__3fct == 1 ))&& (__1f -> nargs_known__3fct == 1 ))
# 1120 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct name *)0 ;

# 1123 "/home/claude/cfront-3/src/dcl3.cpp"
for(( (__1ax = __1fx -> argtype__3fct ), (__1a = __1f -> argtype__3fct )) ;__1a && __1ax ;( (__1ax = __1ax -> __O1__4name.n_list ), (__1a = __1a ->
# 1123 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4name.n_list )) ) { 
# 1124 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __2at ;
Ptype __2atp ;

# 1124 "/home/claude/cfront-3/src/dcl3.cpp"
__2at = __1ax -> __O1__4expr.tp ;
__2atp = __1a -> __O1__4expr.tp ;

# 1128 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __2at , __2atp , (unsigned char )204 , (unsigned char )0 ) == 0 ){ 
# 1129 "/home/claude/cfront-3/src/dcl3.cpp"
continue ;
# 1129 "/home/claude/cfront-3/src/dcl3.cpp"

# 1130 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 1132 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1warn == 0 )
# 1133 "/home/claude/cfront-3/src/dcl3.cpp"
goto xx ;

# 1143 "/home/claude/cfront-3/src/dcl3.cpp"
__2at = skiptypedefs__4typeFv ( __2at ) ;
__2atp = skiptypedefs__4typeFv ( __2atp ) ;

# 1146 "/home/claude/cfront-3/src/dcl3.cpp"
if (const_problem ){ 
# 1147 "/home/claude/cfront-3/src/dcl3.cpp"
if ((is_ptr__4typeFv ( __2at ) && is_ptr__4typeFv ( __2atp ) )|| (is_ref__4typeFv ( __2at ) && is_ref__4typeFv ( __2atp )
# 1147 "/home/claude/cfront-3/src/dcl3.cpp"
))
# 1151 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1152 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __4ap ;
Ptype __4app ;

# 1152 "/home/claude/cfront-3/src/dcl3.cpp"
__4ap = (((struct ptr *)(((struct ptr *)__2at ))))-> typ__5pvtyp ;
__4app = (((struct ptr *)(((struct ptr *)__2atp ))))-> typ__5pvtyp ;
if (check__4typeFP4typeUcT2 ( __4ap , __4app , (unsigned char )204 , (unsigned char )0 ) != 0 )
# 1155 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct name *)0 ;
# 1155 "/home/claude/cfront-3/src/dcl3.cpp"

# 1156 "/home/claude/cfront-3/src/dcl3.cpp"
}
__1op ++ ;
continue ;
}

# 1161 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2atp -> base__4node == 158 ){ 
# 1164 "/home/claude/cfront-3/src/dcl3.cpp"
if ((check__4typeFP4typeUcT2 ( (((struct ptr *)(((struct ptr *)__2atp ))))-> typ__5pvtyp , __2at , (unsigned char )255 ,
# 1164 "/home/claude/cfront-3/src/dcl3.cpp"
(unsigned char )0 ) == 0 )|| (const_problem && ((is_ptr__4typeFv ( __2at ) == 0 )|| (tconst__4typeFv ( __2at ) != tconst__4typeFv (
# 1164 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct ptr *)(((struct ptr *)__2atp ))))-> typ__5pvtyp ) ))))
# 1172 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1173 "/home/claude/cfront-3/src/dcl3.cpp"
__1op ++ ;
continue ;
}
}

# 1178 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2at -> base__4node == 158 ){ 
# 1180 "/home/claude/cfront-3/src/dcl3.cpp"
if ((check__4typeFP4typeUcT2 ( (((struct ptr *)(((struct ptr *)__2at ))))-> typ__5pvtyp , __2atp , (unsigned char )255 ,
# 1180 "/home/claude/cfront-3/src/dcl3.cpp"
(unsigned char )0 ) == 0 )|| (const_problem && ((is_ptr__4typeFv ( __2atp ) == 0 )|| (tconst__4typeFv ( __2atp ) != tconst__4typeFv (
# 1180 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct ptr *)(((struct ptr *)__2at ))))-> typ__5pvtyp ) ))))
# 1188 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1189 "/home/claude/cfront-3/src/dcl3.cpp"
__1op ++ ;
continue ;
}
break ;
}

# 1196 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct name *)0 ;
}

# 1201 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1a || __1ax )
# 1202 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct name *)0 ;

# 1204 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1op == 0 ){ 
# 1206 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1warn && check__4typeFP4typeUcT2 ( __1fx -> returns__3fct , __1f -> returns__3fct , (unsigned char )255 , (unsigned
# 1206 "/home/claude/cfront-3/src/dcl3.cpp"
char )0 ) )
# 1207 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1207 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V146 ;

# 1207 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V147 ;

# 1207 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V148 ;

# 1207 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"two different return valueTs for%n: %t and %t", (const struct ea *)( ((& __0__V146 )-> __O1__2ea.p =
# 1207 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nx )), (& __0__V146 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V147 , (const void *)__1fx ->
# 1207 "/home/claude/cfront-3/src/dcl3.cpp"
returns__3fct ) , (const struct ea *)__ct__2eaFPCv ( & __0__V148 , (const void *)__1f -> returns__3fct ) , (const struct
# 1207 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} 
# 1209 "/home/claude/cfront-3/src/dcl3.cpp"
return __1nx ;
}
xx :
# 1212 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1warn && __1op )
# 1213 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1213 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V149 ;

# 1213 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V150 ;

# 1213 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"the overloading mechanism cannot tell a%t from a%t", (const struct ea *)( ((& __0__V149 )-> __O1__2ea.p =
# 1213 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1fx )), (& __0__V149 )) , (const struct ea *)( ((& __0__V150 )-> __O1__2ea.p = ((const void
# 1213 "/home/claude/cfront-3/src/dcl3.cpp"
*)__1f )), (& __0__V150 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1215 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct name *)0 ;
}

# 1218 "/home/claude/cfront-3/src/dcl3.cpp"
int no_of_names__4nameFv (struct name *__0this )
# 1219 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1220 "/home/claude/cfront-3/src/dcl3.cpp"
int __1i ;
Pname __1n ;

# 1220 "/home/claude/cfront-3/src/dcl3.cpp"
__1i = 0 ;

# 1222 "/home/claude/cfront-3/src/dcl3.cpp"
for(__1n = __0this ;__1n ;__1n = __1n -> __O1__4name.n_list ) 
# 1223 "/home/claude/cfront-3/src/dcl3.cpp"
__1i ++ ;
return __1i ;
}

# 1227 "/home/claude/cfront-3/src/dcl3.cpp"
static Pexpr lvec [20];

# 1227 "/home/claude/cfront-3/src/dcl3.cpp"
static Pexpr *lll ;

# 1227 "/home/claude/cfront-3/src/dcl3.cpp"
static Pexpr *curr_e ;
static Pexpr last_il = 0 ;
static Pexpr list_back = 0 ;
static Pexpr last_el = 0 ;

# 1230 "/home/claude/cfront-3/src/dcl3.cpp"
static Pexpr *last_lll ;

# 1232 "/home/claude/cfront-3/src/dcl3.cpp"
void new_list__FP4expr (Pexpr __1lx )
# 1233 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1234 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1lx -> base__4node != 124 )
# 1235 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCc ( (int )'i' , (const char *)"IrLX")
# 1235 "/home/claude/cfront-3/src/dcl3.cpp"
;

# 1237 "/home/claude/cfront-3/src/dcl3.cpp"
lll = (last_lll = lvec );
lll ++ ;
((*lll ))= (last_el = __1lx -> __O2__4expr.e1 );
}

# 359 "/home/claude/cfront-3/src/cfront.h"
Pfct memptr__4typeFv (struct type *__0this );

# 1154 "/home/claude/cfront-3/src/cfront.h"
extern int need_sti__FP4exprP5tableUc (Pexpr __0e , Ptable __0tbl , bit __0is_static_ok );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 1242 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr next_elem__Fv (void )
# 1243 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1244 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __1e ;
Pexpr __1lx ;

# 1247 "/home/claude/cfront-3/src/dcl3.cpp"
if (lll == lvec )
# 1248 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct expr *)0 ;

# 1250 "/home/claude/cfront-3/src/dcl3.cpp"
__1lx = ((*lll ));

# 1252 "/home/claude/cfront-3/src/dcl3.cpp"
if (list_back ){ 
# 1253 "/home/claude/cfront-3/src/dcl3.cpp"
__1e = list_back ;
list_back = 0 ;
return __1e ;
}

# 1258 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1lx == 0 ){ 
# 1259 "/home/claude/cfront-3/src/dcl3.cpp"
lll -- ;
return (struct expr *)0 ;
}

# 1263 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1lx -> base__4node ){ 
# 1263 "/home/claude/cfront-3/src/dcl3.cpp"
unsigned long __2__X152 ;

# 1264 "/home/claude/cfront-3/src/dcl3.cpp"
case 140 :
# 1265 "/home/claude/cfront-3/src/dcl3.cpp"
__1e = __1lx -> __O2__4expr.e1 ;
curr_e = (& __1lx -> __O2__4expr.e1 );
last_el = __1lx ;
last_lll = lll ;
((*lll ))= __1lx -> __O3__4expr.e2 ;
switch (__1e -> base__4node ){ 
# 1271 "/home/claude/cfront-3/src/dcl3.cpp"
case 124 :
# 1272 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1e -> __O1__4expr.tp && memptr__4typeFv ( __1e -> __O1__4expr.tp ) )
# 1273 "/home/claude/cfront-3/src/dcl3.cpp"
return __1e ;
lll ++ ;
((*lll ))= __1e -> __O2__4expr.e1 ;
last_il = __1e ;
return (((struct expr *)1 ));
case 140 :
# 1279 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"nestedEL") ;
return (struct expr *)0 ;
default :
# 1282 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1283 "/home/claude/cfront-3/src/dcl3.cpp"
if (need_sti__FP4exprP5tableUc ( __1e , (struct table *)0 , (unsigned char )0 ) )
# 1284 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCc ( (int )'s' , (const
# 1284 "/home/claude/cfront-3/src/dcl3.cpp"
char *)"generalIr inIrL") ;
return __1e ;
}
}
case 150 :
# 1289 "/home/claude/cfront-3/src/dcl3.cpp"
case 86 :
# 1290 "/home/claude/cfront-3/src/dcl3.cpp"
lll -- ;
return (struct expr *)0 ;
default :
# 1293 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1293 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V151 ;

# 1293 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"IrL %k", (const struct ea *)( (__2__X152 =
# 1293 "/home/claude/cfront-3/src/dcl3.cpp"
__1lx -> base__4node ), ( (( ((& __0__V151 )-> __O1__2ea.i = __2__X152 ), 0 ) ), (& __0__V151 )) ) ,
# 1293 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return (struct expr *)0 ;
} }
}

# 1298 "/home/claude/cfront-3/src/dcl3.cpp"
static Pexpr insert_init__FP4expr (Pexpr __1newval ){ 
# 1301 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __1t ;

# 1301 "/home/claude/cfront-3/src/dcl3.cpp"
__1t = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , last_el -> __O2__4expr.e1 , last_el -> __O3__4expr.e2 ) ;

# 1303 "/home/claude/cfront-3/src/dcl3.cpp"
last_el -> __O2__4expr.e1 = __1newval ;
last_el -> __O3__4expr.e2 = __1t ;
lll = last_lll ;
((*lll ))= last_el ;
return next_elem__Fv ( ) ;
}

# 1310 "/home/claude/cfront-3/src/dcl3.cpp"
void skip_ilist__Fv (void )
# 1312 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1313 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __1e ;

# 1313 "/home/claude/cfront-3/src/dcl3.cpp"
__1e = next_elem__Fv ( ) ;
__1e = next_elem__Fv ( ) ;
}

# 1318 "/home/claude/cfront-3/src/dcl3.cpp"
static int pts_to_templ__FP4type (Ptype __1t )
# 1319 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1320 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __1tt ;

# 1320 "/home/claude/cfront-3/src/dcl3.cpp"
__1tt = skiptypedefs__4typeFv ( __1t ) ;
if (__1tt -> base__4node != 125 )return 0 ;
__1tt = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__1tt ))))-> typ__5pvtyp ) ;
return ((__1tt -> base__4node == 108 )&& ((((struct fct *)(((struct fct *)__1tt ))))-> fct_base__3fct == 1));
}

# 1327 "/home/claude/cfront-3/src/dcl3.cpp"
static void grab_braces__FPP4expri (Pexpr *__1base , int __1lst )
# 1328 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1329 "/home/claude/cfront-3/src/dcl3.cpp"
int __1flag ;

# 1329 "/home/claude/cfront-3/src/dcl3.cpp"
__1flag = 0 ;

# 1331 "/home/claude/cfront-3/src/dcl3.cpp"
while (lll > (__1base - __1lst )){ 
# 1332 "/home/claude/cfront-3/src/dcl3.cpp"
if (next_elem__Fv ( ) && (! (__1flag ++ )))
# 1333 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"IrL too long")
# 1333 "/home/claude/cfront-3/src/dcl3.cpp"
;
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 1337 "/home/claude/cfront-3/src/dcl3.cpp"
void list_check__FP4nameP4typeP4exprP5table (Pname __1nn , Ptype __1t , Pexpr __1il , Ptable __1tbl );

# 718 "/home/claude/cfront-3/src/cfront.h"

# 741 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr ptof__FP3fctP4exprP5table (Pfct , Pexpr , Ptable );

# 824 "/home/claude/cfront-3/src/cfront.h"

# 718 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 449 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__8classdefFP4name (struct classdef *__0this , Pname );

# 234 "/home/claude/cfront-3/src/cfront.h"

# 445 "/home/claude/cfront-3/src/cfront.h"

# 718 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 824 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFUl (struct ea *__0this , size_t __2ii );

# 1337 "/home/claude/cfront-3/src/dcl3.cpp"
void list_check__FP4nameP4typeP4exprP5table (Pname __1nn , Ptype __1t , Pexpr __1il , Ptable __1tbl )
# 1343 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1344 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __1e ;
bit __1lst ;
int __1i ;
Pclass __1cl ;
int __1tdef ;

# 1345 "/home/claude/cfront-3/src/dcl3.cpp"
__1lst = 0 ;

# 1348 "/home/claude/cfront-3/src/dcl3.cpp"
__1tdef = 0 ;

# 1351 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1il == (((struct expr *)1 ))){ 
# 1352 "/home/claude/cfront-3/src/dcl3.cpp"
__1lst = 1 ;
__1e = __1il ;
}
else if (__1il )
# 1356 "/home/claude/cfront-3/src/dcl3.cpp"
list_back = __1il ;

# 1358 "/home/claude/cfront-3/src/dcl3.cpp"
zzz :
# 1359 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1t -> base__4node ){ 
# 1360 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 1361 "/home/claude/cfront-3/src/dcl3.cpp"
__1t = (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ;
__1tdef = 1 ;
goto zzz ;

# 1365 "/home/claude/cfront-3/src/dcl3.cpp"
case 110 :
# 1366 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1367 "/home/claude/cfront-3/src/dcl3.cpp"
Pvec __3v ;
Ptype __3vt ;

# 1367 "/home/claude/cfront-3/src/dcl3.cpp"
__3v = (((struct vec *)(((struct vec *)__1t ))));
__3vt = skiptypedefs__4typeFv ( __3v -> typ__5pvtyp ) ;

# 1370 "/home/claude/cfront-3/src/dcl3.cpp"
if (__3v -> size__3vec ){ 
# 1371 "/home/claude/cfront-3/src/dcl3.cpp"
if (__3vt -> base__4node == 5 ){ 
# 1372 "/home/claude/cfront-3/src/dcl3.cpp"
__1e = next_elem__Fv ( ) ;
if (__1e -> base__4node == 81 ){ 
# 1374 "/home/claude/cfront-3/src/dcl3.cpp"
int __6isz ;

# 1374 "/home/claude/cfront-3/src/dcl3.cpp"
__6isz = (((struct vec *)(((struct vec *)__1e -> __O1__4expr.tp ))))-> size__3vec ;
if (__3v -> size__3vec < __6isz )
# 1376 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1376 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V153 ;

# 1376 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V154 ;

# 1376 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V155 ;

# 1376 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"Ir too long (%d characters) for%n[%d]", (const struct ea *)( (( ((& __0__V153 )->
# 1376 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__2ea.i = ((unsigned long )__6isz )), 0 ) ), (& __0__V153 )) , (const struct ea *)( ((& __0__V154 )->
# 1376 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__2ea.p = ((const void *)__1nn )), (& __0__V154 )) , (const struct ea *)__ct__2eaFUl ( & __0__V155 , (unsigned long
# 1376 "/home/claude/cfront-3/src/dcl3.cpp"
)__3v -> size__3vec ) , (const struct ea *)ea0 ) ;
} break ;
}
else 
# 1380 "/home/claude/cfront-3/src/dcl3.cpp"
list_back = __1e ;
}
{ Pexpr *__4lllsave_vec ;

# 1382 "/home/claude/cfront-3/src/dcl3.cpp"
__4lllsave_vec = lll ;
for(__1i = 0 ;__1i < __3v -> size__3vec ;__1i ++ ) { 
# 1384 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __5MP ;

# 1384 "/home/claude/cfront-3/src/dcl3.cpp"
__5MP = 0 ;
ee :
# 1386 "/home/claude/cfront-3/src/dcl3.cpp"
__1e = next_elem__Fv ( ) ;
if (__1e == 0 ){ 
# 1388 "/home/claude/cfront-3/src/dcl3.cpp"
if (! ansi_opt )
# 1389 "/home/claude/cfront-3/src/dcl3.cpp"
goto xsw ;
if (lll < __4lllsave_vec )
# 1391 "/home/claude/cfront-3/src/dcl3.cpp"
goto xsw ;
goto ee ;
}

# 1395 "/home/claude/cfront-3/src/dcl3.cpp"
if (((lll - __4lllsave_vec )>= 2 )&& ansi_opt )
# 1396 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"unexpectedIrL") ;
vtz :
# 1399 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__3vt -> base__4node ){ 
# 1399 "/home/claude/cfront-3/src/dcl3.cpp"
register struct type *__0__X188 ;

# 1399 "/home/claude/cfront-3/src/dcl3.cpp"
struct type *__1__Xt00anhgl1b4vcog ;

# 1400 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 1401 "/home/claude/cfront-3/src/dcl3.cpp"
__3vt = (((struct basetype *)(((struct basetype *)__3vt ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto vtz ;
case 110 :
# 1404 "/home/claude/cfront-3/src/dcl3.cpp"
case 119 :
# 1405 "/home/claude/cfront-3/src/dcl3.cpp"
list_check__FP4nameP4typeP4exprP5table ( __1nn , __3vt , __1e , (struct table *)0 ) ;
if ((lll < __4lllsave_vec )&& ansi_opt )
# 1407 "/home/claude/cfront-3/src/dcl3.cpp"
return ;
break ;
case 125 :
# 1410 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__5MP = memptr__4typeFv ( __3vt ) )&& (__1e == (((struct expr *)1 )))){ 
# 1411 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __3vt , last_il -> __O1__4expr.tp ,
# 1411 "/home/claude/cfront-3/src/dcl3.cpp"
(unsigned char )70 , (unsigned char )0 ) )
# 1412 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1412 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V156 ;

# 1412 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V157 ;

# 1412 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V158 ;

# 1412 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT for%n:%t (%tX)", (const struct ea *)( ((& __0__V156 )-> __O1__2ea.p =
# 1412 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__3v )), (& __0__V156 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V157 , (const void *)last_il ->
# 1412 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)( ((& __0__V158 )-> __O1__2ea.p = ((const void *)__3vt )), (& __0__V158 )) ,
# 1412 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} skip_ilist__Fv ( ) ;
break ;
}
if (__5MP && is_zero__FP4expr ( __1e ) ){ 
# 1417 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , zero )
# 1417 "/home/claude/cfront-3/src/dcl3.cpp"
;
((*curr_e ))= __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , (*curr_e ), zero ) ;
((*curr_e ))-> __O1__4expr.tp = (struct type *)zero_type ;
break ;
}
if ((__1e && (__1e != (((struct expr *)1 ))))&& (( (__0__X188 = __1e -> __O1__4expr.tp ), ( (__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv ( __0__X188 ) ),
# 1422 "/home/claude/cfront-3/src/dcl3.cpp"
( ((__1__Xt00anhgl1b4vcog -> base__4node == 125 )?( (__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__1__Xt00anhgl1b4vcog ))))-> typ__5pvtyp ) ), 0 ) :0 ), (((unsigned
# 1422 "/home/claude/cfront-3/src/dcl3.cpp"
char )((__1__Xt00anhgl1b4vcog -> base__4node == ((unsigned char )76 ))?1 :0 )))) ) ) || pts_to_templ__FP4type ( __1e -> __O1__4expr.tp ) ))
# 1424 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1425 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __7op ;
# 1425 "/home/claude/cfront-3/src/dcl3.cpp"
__7op = ptof__FP3fctP4exprP5table ( ((struct fct *)(((struct fct *)(((struct ptr *)(((struct ptr *)__3vt ))))-> typ__5pvtyp ))), __1e , __1tbl ) ;
if (__7op && check__4typeFP4typeUcT2 ( __3vt , __7op -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) )
# 1427 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1427 "/home/claude/cfront-3/src/dcl3.cpp"
struct
# 1427 "/home/claude/cfront-3/src/dcl3.cpp"
ea __0__V159 ;

# 1427 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V160 ;

# 1427 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V161 ;

# 1427 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT for%n:%t (%tX)", (const struct ea *)( ((& __0__V159 )-> __O1__2ea.p =
# 1427 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V159 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V160 , (const void *)__7op ->
# 1427 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)( ((& __0__V161 )-> __O1__2ea.p = ((const void *)__3vt )), (& __0__V161 )) ,
# 1427 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} if (__7op ){ 
# 1429 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= __7op ;
break ;
}
}

# 1434 "/home/claude/cfront-3/src/dcl3.cpp"
default :
# 1435 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1436 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1e == (((struct expr *)1 ))){ 
# 1437 "/home/claude/cfront-3/src/dcl3.cpp"
if (! ansi_opt )
# 1438 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"unexpectedIrL")
# 1438 "/home/claude/cfront-3/src/dcl3.cpp"
;
goto ee ;
}

# 1442 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __3vt , __1e -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) )
# 1443 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1443 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V162 ;
# 1443 "/home/claude/cfront-3/src/dcl3.cpp"

# 1443 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V163 ;

# 1443 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V164 ;

# 1443 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT for%n:%t (%tX)", (const struct ea *)( ((& __0__V162 )-> __O1__2ea.p =
# 1443 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V162 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V163 , (const void *)__1e ->
# 1443 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)( ((& __0__V164 )-> __O1__2ea.p = ((const void *)__3vt )), (& __0__V164 )) ,
# 1443 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} 
# 1445 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pptr __7p ;
if (((check__4typeFP4typeUcT2 ( __3vt , __1e -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) && (__7p = is_ptr__4typeFv (
# 1446 "/home/claude/cfront-3/src/dcl3.cpp"
__3vt ) ))&& ((((struct type *)(((struct type *)__7p ))))!= (((struct type *)zero_type ))))&& (__7p -> typ__5pvtyp != (((struct type *)char_type ))))
# 1454 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1455 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __8te ;
Ptype __8t ;

# 1457 "/home/claude/cfront-3/src/dcl3.cpp"
register struct cast *__0__X189 ;

# 1455 "/home/claude/cfront-3/src/dcl3.cpp"
__8te = __1e ;
__8t = __7p -> typ__5pvtyp ;
while (__8t -> base__4node == 97 )
# 1458 "/home/claude/cfront-3/src/dcl3.cpp"
__8t = (((struct basetype *)(((struct basetype *)__8t ))))-> b_name__8basetype -> __O1__4expr.tp ;
if (__8t -> base__4node == 119 )
# 1460 "/home/claude/cfront-3/src/dcl3.cpp"
__8te = ptr_init__FP3ptrP4exprP5table ( __7p , __1e , __1tbl ) ;
if (__8te == __1e )
# 1462 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= (struct expr *)( (__0__X189 = 0 ), ( ((__0__X189 || (__0__X189 = (struct cast *)__nw__4exprSFUl ( (unsigned long
# 1462 "/home/claude/cfront-3/src/dcl3.cpp"
)(sizeof (struct cast))) ))?( (__0__X189 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X189 ), (unsigned char )191 , __1e , (struct expr *)0 )
# 1462 "/home/claude/cfront-3/src/dcl3.cpp"
), (__0__X189 -> __O1__4expr.tp = (__0__X189 -> __O4__4expr.tp2 = __3vt ))) :0 ), __0__X189 ) ) ;
else 
# 1464 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= __8te ;
}

# 1465 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
}
}
if (ansi_opt ){ 
# 1470 "/home/claude/cfront-3/src/dcl3.cpp"
grab_braces__FPP4expri ( __4lllsave_vec , (int )__1lst ) ;
}
else { 
# 1473 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1lst && (__1e = next_elem__Fv ( ) ))
# 1474 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"end ofIrLX after array")
# 1474 "/home/claude/cfront-3/src/dcl3.cpp"
;
}
xsw :;

# 1476 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
else { 
# 1479 "/home/claude/cfront-3/src/dcl3.cpp"
__1i = 0 ;
((void )tsizeof__4typeFi ( __3v -> typ__5pvtyp , 0 ) );
{ Pexpr *__4lllsave_vec2 ;

# 1481 "/home/claude/cfront-3/src/dcl3.cpp"
__4lllsave_vec2 = lll ;
xx :
# 1483 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pfct __4MP ;

# 1483 "/home/claude/cfront-3/src/dcl3.cpp"
__4MP = 0 ;
__1i ++ ;
xx2 :
# 1486 "/home/claude/cfront-3/src/dcl3.cpp"
__1e = next_elem__Fv ( ) ;
if (__1e == 0 ){ 
# 1488 "/home/claude/cfront-3/src/dcl3.cpp"
if ((! ansi_opt )|| (lll < __4lllsave_vec2 )){ 
# 1489 "/home/claude/cfront-3/src/dcl3.cpp"
__1i -- ;
goto done ;
}
goto xx2 ;
}
if (((lll - __4lllsave_vec2 )>= 2 )&& ansi_opt )
# 1495 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"unexpectedIrL") ;
vtzz :
# 1498 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__3vt -> base__4node ){ 
# 1498 "/home/claude/cfront-3/src/dcl3.cpp"
register struct type *__0__X190 ;

# 1498 "/home/claude/cfront-3/src/dcl3.cpp"
struct type *__1__Xt00anhgl1b4vcog ;

# 1499 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 1500 "/home/claude/cfront-3/src/dcl3.cpp"
__3vt = (((struct basetype *)(((struct basetype *)__3vt ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto vtzz ;
case 110 :
# 1503 "/home/claude/cfront-3/src/dcl3.cpp"
case 119 :
# 1504 "/home/claude/cfront-3/src/dcl3.cpp"
list_check__FP4nameP4typeP4exprP5table ( __1nn , __3vt , __1e , (struct table *)0 ) ;
break ;
case 125 :
# 1507 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__4MP = memptr__4typeFv ( __3vt ) )&& (__1e == (((struct expr *)1 )))){ 
# 1508 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __3vt , last_il -> __O1__4expr.tp ,
# 1508 "/home/claude/cfront-3/src/dcl3.cpp"
(unsigned char )70 , (unsigned char )0 ) )
# 1509 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1509 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V165 ;

# 1509 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V166 ;

# 1509 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V167 ;

# 1509 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT for%n:%t (%tX)", (const struct ea *)( ((& __0__V165 )-> __O1__2ea.p =
# 1509 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__3v )), (& __0__V165 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V166 , (const void *)last_il ->
# 1509 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)( ((& __0__V167 )-> __O1__2ea.p = ((const void *)__3vt )), (& __0__V167 )) ,
# 1509 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} skip_ilist__Fv ( ) ;
break ;
}
if (__4MP && is_zero__FP4expr ( __1e ) ){ 
# 1514 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , zero )
# 1514 "/home/claude/cfront-3/src/dcl3.cpp"
;
((*curr_e ))= __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , (*curr_e ), zero ) ;
((*curr_e ))-> __O1__4expr.tp = (struct type *)zero_type ;
break ;
}

# 1520 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1e && (__1e != (((struct expr *)1 ))))&& (( (__0__X190 = __1e -> __O1__4expr.tp ), ( (__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv ( __0__X190 ) ),
# 1520 "/home/claude/cfront-3/src/dcl3.cpp"
( ((__1__Xt00anhgl1b4vcog -> base__4node == 125 )?( (__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__1__Xt00anhgl1b4vcog ))))-> typ__5pvtyp ) ), 0 ) :0 ), (((unsigned
# 1520 "/home/claude/cfront-3/src/dcl3.cpp"
char )((__1__Xt00anhgl1b4vcog -> base__4node == ((unsigned char )76 ))?1 :0 )))) ) ) || pts_to_templ__FP4type ( __1e -> __O1__4expr.tp ) ))
# 1522 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1523 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __6op ;
# 1523 "/home/claude/cfront-3/src/dcl3.cpp"
__6op = ptof__FP3fctP4exprP5table ( ((struct fct *)(((struct fct *)(((struct ptr *)(((struct ptr *)__3vt ))))-> typ__5pvtyp ))), __1e , __1tbl ) ;
if (__6op && check__4typeFP4typeUcT2 ( __3vt , __6op -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) )
# 1525 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1525 "/home/claude/cfront-3/src/dcl3.cpp"
struct
# 1525 "/home/claude/cfront-3/src/dcl3.cpp"
ea __0__V168 ;

# 1525 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V169 ;

# 1525 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V170 ;

# 1525 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT for%n:%t (%tX)", (const struct ea *)( ((& __0__V168 )-> __O1__2ea.p =
# 1525 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V168 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V169 , (const void *)__6op ->
# 1525 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)( ((& __0__V170 )-> __O1__2ea.p = ((const void *)__3vt )), (& __0__V170 )) ,
# 1525 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} if (__6op ){ 
# 1527 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= __6op ;
break ;
}
}

# 1532 "/home/claude/cfront-3/src/dcl3.cpp"
default :
# 1533 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1534 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1e == (((struct expr *)1 ))){ 
# 1535 "/home/claude/cfront-3/src/dcl3.cpp"
if (! ansi_opt ){ 
# 1536 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"unexpectedIrL")
# 1536 "/home/claude/cfront-3/src/dcl3.cpp"
;
goto xx ;
}
goto xx2 ;
}

# 1542 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __3vt , __1e -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) )
# 1543 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1543 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V171 ;
# 1543 "/home/claude/cfront-3/src/dcl3.cpp"

# 1543 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V172 ;

# 1543 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V173 ;

# 1543 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT for%n:%t (%tX)", (const struct ea *)( ((& __0__V171 )-> __O1__2ea.p =
# 1543 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V171 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V172 , (const void *)__1e ->
# 1543 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)( ((& __0__V173 )-> __O1__2ea.p = ((const void *)__3vt )), (& __0__V173 )) ,
# 1543 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} 
# 1545 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pptr __6p ;
if (((check__4typeFP4typeUcT2 ( __3vt , __1e -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) && (__6p = is_ptr__4typeFv (
# 1546 "/home/claude/cfront-3/src/dcl3.cpp"
__3vt ) ))&& ((((struct type *)(((struct type *)__6p ))))!= (((struct type *)zero_type ))))&& (__6p -> typ__5pvtyp != (((struct type *)char_type ))))
# 1554 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1555 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __7te ;
Ptype __7t ;

# 1557 "/home/claude/cfront-3/src/dcl3.cpp"
register struct cast *__0__X191 ;

# 1555 "/home/claude/cfront-3/src/dcl3.cpp"
__7te = __1e ;
__7t = __6p -> typ__5pvtyp ;
while (__7t -> base__4node == 97 )
# 1558 "/home/claude/cfront-3/src/dcl3.cpp"
__7t = (((struct basetype *)(((struct basetype *)__7t ))))-> b_name__8basetype -> __O1__4expr.tp ;
if (__7t -> base__4node == 119 )
# 1560 "/home/claude/cfront-3/src/dcl3.cpp"
__7te = ptr_init__FP3ptrP4exprP5table ( __6p , __1e , __1tbl ) ;
if (__7te == __1e )
# 1562 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= (struct expr *)( (__0__X191 = 0 ), ( ((__0__X191 || (__0__X191 = (struct cast *)__nw__4exprSFUl ( (unsigned long
# 1562 "/home/claude/cfront-3/src/dcl3.cpp"
)(sizeof (struct cast))) ))?( (__0__X191 = (struct cast *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X191 ), (unsigned char )191 , __1e , (struct expr *)0 )
# 1562 "/home/claude/cfront-3/src/dcl3.cpp"
), (__0__X191 -> __O1__4expr.tp = (__0__X191 -> __O4__4expr.tp2 = __3vt ))) :0 ), __0__X191 ) ) ;
else 
# 1564 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= __7te ;
}

# 1565 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
}
goto xx ;
done :
# 1570 "/home/claude/cfront-3/src/dcl3.cpp"
if (ansi_opt ){ 
# 1571 "/home/claude/cfront-3/src/dcl3.cpp"
grab_braces__FPP4expri ( __4lllsave_vec2 , (int )__1lst ) ;
}
if (__1tdef == 0 )__3v -> size__3vec = __1i ;

# 1573 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 1573 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
break ;
}

# 1578 "/home/claude/cfront-3/src/dcl3.cpp"
case 6 :
# 1579 "/home/claude/cfront-3/src/dcl3.cpp"
__1cl = (((struct classdef *)(((struct classdef *)__1t ))));
goto ccc ;

# 1582 "/home/claude/cfront-3/src/dcl3.cpp"
case 119 :
# 1583 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1584 "/home/claude/cfront-3/src/dcl3.cpp"
__1cl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ))));
ccc :
# 1586 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cl -> defined__4type == 0 ){ 
# 1587 "/home/claude/cfront-3/src/dcl3.cpp"
lll = lvec ;
return ;
}

# 1591 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cl -> c_body__8classdef == 1 )
# 1592 "/home/claude/cfront-3/src/dcl3.cpp"
dcl_print__8classdefFP4name ( __1cl , (struct name *)0 ) ;

# 1594 "/home/claude/cfront-3/src/dcl3.cpp"
{ Ptable __3tbl ;
Pname __3m ;

# 1594 "/home/claude/cfront-3/src/dcl3.cpp"
__3tbl = __1cl -> memtbl__8classdef ;

# 1596 "/home/claude/cfront-3/src/dcl3.cpp"
if ((ansi_opt == 0 )&& (__1cl -> csu__8classdef == 36 ))
# 1597 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCc ( (int )'s' , (const char *)"initialization of union withIL")
# 1597 "/home/claude/cfront-3/src/dcl3.cpp"
;

# 1599 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pexpr *__3lllsave_cobj ;

# 1600 "/home/claude/cfront-3/src/dcl3.cpp"
int __2__X192 ;

# 1600 "/home/claude/cfront-3/src/dcl3.cpp"
int __2__X193 ;

# 1599 "/home/claude/cfront-3/src/dcl3.cpp"
__3lllsave_cobj = lll ;

# 1601 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cl -> baselist__8classdef ){ 
# 1602 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cl -> baselist__8classdef -> next__6basecl )error__FPCc ( (const char *)"IrL forO ofC with multipleBCs")
# 1602 "/home/claude/cfront-3/src/dcl3.cpp"
;
list_check__FP4nameP4typeP4exprP5table ( __1nn , (struct type *)__1cl -> baselist__8classdef -> bclass__6basecl , (struct expr *)0 , (struct table *)0 ) ;
if ((lll < __3lllsave_cobj )&& ansi_opt )
# 1605 "/home/claude/cfront-3/src/dcl3.cpp"
return ;
}

# 1608 "/home/claude/cfront-3/src/dcl3.cpp"
for(__3m = ( (__2__X192 = (__1i = 1 )), ( (((__2__X192 <= 0 )|| (__3tbl -> free_slot__5table <= __2__X192 ))?(((struct name *)0 )):(__3tbl -> entries__5table [__2__X192 ]))) )
# 1608 "/home/claude/cfront-3/src/dcl3.cpp"
;__3m ;__3m = (__3m -> n_tbl_list__4name ?__3m -> n_tbl_list__4name :( (__2__X193 = (++ __1i )), ( (((__2__X193 <= 0 )|| (__3tbl -> free_slot__5table <= __2__X193 ))?(((struct name *)0 )):(__3tbl ->
# 1608 "/home/claude/cfront-3/src/dcl3.cpp"
entries__5table [__2__X193 ]))) ) )) { 
# 1609 "/home/claude/cfront-3/src/dcl3.cpp"
if (__3m -> base__4node == 123 )continue ;
{ Ptype __4mt ;
Pfct __4MP ;

# 1610 "/home/claude/cfront-3/src/dcl3.cpp"
__4mt = __3m -> __O1__4expr.tp ;
__4MP = 0 ;
if (__4mt == 0 )continue ;
switch (__4mt -> base__4node ){ 
# 1614 "/home/claude/cfront-3/src/dcl3.cpp"
case 108 :
# 1615 "/home/claude/cfront-3/src/dcl3.cpp"
case 76 :
# 1616 "/home/claude/cfront-3/src/dcl3.cpp"
case 6 :
# 1617 "/home/claude/cfront-3/src/dcl3.cpp"
if (__4mt -> base__4node == 6 ){ 
# 1618 "/home/claude/cfront-3/src/dcl3.cpp"
Pclass __6cl ;

# 1618 "/home/claude/cfront-3/src/dcl3.cpp"
__6cl = (((struct classdef *)(((struct classdef *)__4mt ))));
if (! ( (((unsigned char )((__6cl -> csu__8classdef == 6 )?0 :(((int )__6cl -> csu__8classdef )))))) )
# 1620 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1620 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V174 ;

# 1620 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V175 ;

# 1620 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannotI%nWIrL because class %s has private or protected members", (const struct ea *)( ((& __0__V174 )-> __O1__2ea.p =
# 1620 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V174 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V175 , (const void *)__6cl ->
# 1620 "/home/claude/cfront-3/src/dcl3.cpp"
string__8classdef ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
case 13 :
# 1623 "/home/claude/cfront-3/src/dcl3.cpp"
continue ;
}
if ((__3m -> n_stclass__4name == 31 )|| (__3m -> n_stclass__4name == 13 ))
# 1626 "/home/claude/cfront-3/src/dcl3.cpp"
continue ;

# 1628 "/home/claude/cfront-3/src/dcl3.cpp"
dd :
# 1629 "/home/claude/cfront-3/src/dcl3.cpp"
while (__4mt -> base__4node == 97 )
# 1630 "/home/claude/cfront-3/src/dcl3.cpp"
__4mt = (((struct basetype *)(((struct basetype *)__4mt ))))-> b_name__8basetype -> __O1__4expr.tp ;

# 1632 "/home/claude/cfront-3/src/dcl3.cpp"
if (((lll - __3lllsave_cobj )>= 2 )&& ansi_opt )
# 1633 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"unexpectedIrL") ;

# 1635 "/home/claude/cfront-3/src/dcl3.cpp"
if (((__4MP = memptr__4typeFv ( __4mt ) )&& (__1e == (((struct expr *)1 ))))&& (last_il -> __O1__4expr.tp -> base__4node == 125 ))
# 1641 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1642 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1i ==
# 1642 "/home/claude/cfront-3/src/dcl3.cpp"
1 )
# 1643 "/home/claude/cfront-3/src/dcl3.cpp"
__1lst = 0 ;
}
else 
# 1646 "/home/claude/cfront-3/src/dcl3.cpp"
__1e = next_elem__Fv ( ) ;

# 1648 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1e == 0 ){ 
# 1649 "/home/claude/cfront-3/src/dcl3.cpp"
if ((! ansi_opt )|| (lll < __3lllsave_cobj ))
# 1650 "/home/claude/cfront-3/src/dcl3.cpp"
return ;
goto dd ;
}

# 1654 "/home/claude/cfront-3/src/dcl3.cpp"
if ((((__4mt -> base__4node == 114 )&& ((__3m -> __O2__4expr.string [0 ])== '_' ))&& ((__3m -> __O2__4expr.string [1 ])== '_' ))&& ((__3m -> __O2__4expr.string [2 ])== 'F' ))
# 1662 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1663 "/home/claude/cfront-3/src/dcl3.cpp"
__1e =
# 1663 "/home/claude/cfront-3/src/dcl3.cpp"
insert_init__FP4expr ( zero ) ;
}

# 1667 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__4mt -> base__4node ){ 
# 1667 "/home/claude/cfront-3/src/dcl3.cpp"
register struct type *__0__X194 ;

# 1667 "/home/claude/cfront-3/src/dcl3.cpp"
struct type *__1__Xt00anhgl1b4vcog ;

# 1668 "/home/claude/cfront-3/src/dcl3.cpp"
case 6 :
# 1669 "/home/claude/cfront-3/src/dcl3.cpp"
case 13 :
# 1670 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
case 110 :
# 1672 "/home/claude/cfront-3/src/dcl3.cpp"
case 119 :
# 1673 "/home/claude/cfront-3/src/dcl3.cpp"
list_check__FP4nameP4typeP4exprP5table ( __1nn , __3m -> __O1__4expr.tp , __1e , (struct table *)0 ) ;
if ((lll < __3lllsave_cobj )&& ansi_opt )
# 1675 "/home/claude/cfront-3/src/dcl3.cpp"
return ;
break ;
case 125 :
# 1678 "/home/claude/cfront-3/src/dcl3.cpp"
if (__4MP && (__1e == (((struct expr *)1 )))){ 
# 1679 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __4mt , last_il -> __O1__4expr.tp , (unsigned char )70 ,
# 1679 "/home/claude/cfront-3/src/dcl3.cpp"
(unsigned char )0 ) )
# 1680 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1680 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V176 ;

# 1680 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V177 ;

# 1680 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V178 ;

# 1680 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT for%n:%t (%tX)", (const struct ea *)( ((& __0__V176 )-> __O1__2ea.p =
# 1680 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__3m )), (& __0__V176 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V177 , (const void *)last_il ->
# 1680 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)( ((& __0__V178 )-> __O1__2ea.p = ((const void *)__4mt )), (& __0__V178 )) ,
# 1680 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} skip_ilist__Fv ( ) ;
break ;
}
if (__4MP && is_zero__FP4expr ( __1e ) ){ 
# 1685 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , zero , zero )
# 1685 "/home/claude/cfront-3/src/dcl3.cpp"
;
((*curr_e ))= __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )124 , (*curr_e ), zero ) ;
((*curr_e ))-> __O1__4expr.tp = (struct type *)zero_type ;
break ;
}

# 1691 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1e && (__1e != (((struct expr *)1 ))))&& (( (__0__X194 = __1e -> __O1__4expr.tp ), ( (__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv ( __0__X194 ) ),
# 1691 "/home/claude/cfront-3/src/dcl3.cpp"
( ((__1__Xt00anhgl1b4vcog -> base__4node == 125 )?( (__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__1__Xt00anhgl1b4vcog ))))-> typ__5pvtyp ) ), 0 ) :0 ), (((unsigned
# 1691 "/home/claude/cfront-3/src/dcl3.cpp"
char )((__1__Xt00anhgl1b4vcog -> base__4node == ((unsigned char )76 ))?1 :0 )))) ) ) || pts_to_templ__FP4type ( __1e -> __O1__4expr.tp ) ))
# 1693 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1694 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __6op ;
# 1694 "/home/claude/cfront-3/src/dcl3.cpp"
__6op = ptof__FP3fctP4exprP5table ( ((struct fct *)(((struct fct *)(((struct ptr *)(((struct ptr *)__4mt ))))-> typ__5pvtyp ))), __1e , __3tbl ) ;
if (__6op && check__4typeFP4typeUcT2 ( __4mt , __6op -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) )
# 1696 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1696 "/home/claude/cfront-3/src/dcl3.cpp"
struct
# 1696 "/home/claude/cfront-3/src/dcl3.cpp"
ea __0__V179 ;

# 1696 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V180 ;

# 1696 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V181 ;

# 1696 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT for%n:%t (%tX)", (const struct ea *)( ((& __0__V179 )-> __O1__2ea.p =
# 1696 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V179 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V180 , (const void *)__6op ->
# 1696 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)( ((& __0__V181 )-> __O1__2ea.p = ((const void *)__4mt )), (& __0__V181 )) ,
# 1696 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} if (__6op ){ 
# 1698 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= __6op ;
break ;
}
}

# 1703 "/home/claude/cfront-3/src/dcl3.cpp"
default :
# 1704 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1705 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1e == (((struct expr *)1 ))){ 
# 1706 "/home/claude/cfront-3/src/dcl3.cpp"
if (! ansi_opt )
# 1707 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"unexpectedIrL")
# 1707 "/home/claude/cfront-3/src/dcl3.cpp"
;
goto dd ;
}

# 1711 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __4mt , __1e -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) )
# 1712 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1712 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V182 ;
# 1712 "/home/claude/cfront-3/src/dcl3.cpp"

# 1712 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V183 ;

# 1712 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V184 ;

# 1712 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT for%n:%t (%tX)", (const struct ea *)( ((& __0__V182 )-> __O1__2ea.p =
# 1712 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__3m )), (& __0__V182 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V183 , (const void *)__1e ->
# 1712 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)__ct__2eaFPCv ( & __0__V184 , (const void *)__3m -> __O1__4expr.tp ) , (const struct
# 1712 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} 
# 1714 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__4MP && __1e )&& ((__1e -> base__4node == 113 )|| (__1e -> base__4node == 191 )))
# 1715 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= __1e -> __O2__4expr.e1 ;

# 1717 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pptr __6p ;

# 1718 "/home/claude/cfront-3/src/dcl3.cpp"
register struct cast *__0__X195 ;

# 1718 "/home/claude/cfront-3/src/dcl3.cpp"
if (((check__4typeFP4typeUcT2 ( __4mt , __1e -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) && (__6p = is_ptr__4typeFv (
# 1718 "/home/claude/cfront-3/src/dcl3.cpp"
__4mt ) ))&& ((((struct type *)(((struct type *)__6p ))))!= (((struct type *)zero_type ))))&& (__6p -> typ__5pvtyp != (((struct type *)char_type ))))
# 1727 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= (struct expr *)( (__0__X195 =
# 1727 "/home/claude/cfront-3/src/dcl3.cpp"
0 ), ( ((__0__X195 || (__0__X195 = (struct cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast))) ))?( (__0__X195 = (struct cast *)__ct__4exprFUcP4exprT2 (
# 1727 "/home/claude/cfront-3/src/dcl3.cpp"
((struct expr *)__0__X195 ), (unsigned char )191 , __1e , (struct expr *)0 ) ), (__0__X195 -> __O1__4expr.tp = (__0__X195 -> __O4__4expr.tp2 = __4mt )))
# 1727 "/home/claude/cfront-3/src/dcl3.cpp"
:0 ), __0__X195 ) ) ;

# 1727 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
}
if (__1cl -> csu__8classdef == 36 )
# 1731 "/home/claude/cfront-3/src/dcl3.cpp"
break ;

# 1731 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
if (ansi_opt ){ 
# 1734 "/home/claude/cfront-3/src/dcl3.cpp"
grab_braces__FPP4expri ( __3lllsave_cobj , (int )__1lst ) ;
}
else { 
# 1737 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1lst && (__1e = next_elem__Fv ( ) ))error__FPCc ( (const char *)"end ofIrLX afterCO")
# 1737 "/home/claude/cfront-3/src/dcl3.cpp"
;
}
break ;

# 1739 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 1739 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 1742 "/home/claude/cfront-3/src/dcl3.cpp"
default :
# 1743 "/home/claude/cfront-3/src/dcl3.cpp"
__1e = next_elem__Fv ( ) ;

# 1745 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1e == 0 ){ 
# 1746 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"noIr forO") ;
break ;
}

# 1750 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1e == (((struct expr *)1 ))){ 
# 1751 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"unexpectedIrL") ;
break ;
}

# 1755 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __1t , __1e -> __O1__4expr.tp , (unsigned char )70 , (unsigned char )0 ) )
# 1756 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1756 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V185 ;
# 1756 "/home/claude/cfront-3/src/dcl3.cpp"

# 1756 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V186 ;

# 1756 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V187 ;

# 1756 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT for%n:%t (%tX)", (const struct ea *)( ((& __0__V185 )-> __O1__2ea.p =
# 1756 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V185 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V186 , (const void *)__1e ->
# 1756 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ) , (const struct ea *)( ((& __0__V187 )-> __O1__2ea.p = ((const void *)__1t )), (& __0__V187 )) ,
# 1756 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} { Pptr __2p ;

# 1758 "/home/claude/cfront-3/src/dcl3.cpp"
register struct cast *__0__X196 ;

# 1758 "/home/claude/cfront-3/src/dcl3.cpp"
if (((check__4typeFP4typeUcT2 ( __1t , __1e -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 ) && (__2p = is_ptr__4typeFv (
# 1758 "/home/claude/cfront-3/src/dcl3.cpp"
__1t ) ))&& ((((struct type *)(((struct type *)__2p ))))!= (((struct type *)zero_type ))))&& (__2p -> typ__5pvtyp != (((struct type *)char_type ))))
# 1767 "/home/claude/cfront-3/src/dcl3.cpp"
((*curr_e ))= (struct expr *)( (__0__X196 =
# 1767 "/home/claude/cfront-3/src/dcl3.cpp"
0 ), ( ((__0__X196 || (__0__X196 = (struct cast *)__nw__4exprSFUl ( (size_t )(sizeof (struct cast))) ))?( (__0__X196 = (struct cast *)__ct__4exprFUcP4exprT2 (
# 1767 "/home/claude/cfront-3/src/dcl3.cpp"
((struct expr *)__0__X196 ), (unsigned char )191 , __1e , (struct expr *)0 ) ), (__0__X196 -> __O1__4expr.tp = (__0__X196 -> __O4__4expr.tp2 = __1t )))
# 1767 "/home/claude/cfront-3/src/dcl3.cpp"
:0 ), __0__X196 ) ) ;
if (__1lst && (__1e = next_elem__Fv ( ) ))
# 1769 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"end ofIrLX afterO") ;
# 1769 "/home/claude/cfront-3/src/dcl3.cpp"

# 1770 "/home/claude/cfront-3/src/dcl3.cpp"
break ;

# 1770 "/home/claude/cfront-3/src/dcl3.cpp"
}
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

# 262 "/home/claude/cfront-3/src/cfront.h"
Pname find_cn__6ktableFPCc (struct ktable *__0this , const char *);

# 453 "/home/claude/cfront-3/src/cfront.h"
void dcl__8classdefFP4nameP5table (struct classdef *__0this , Pname , Ptable );

# 1798 "/home/claude/cfront-3/src/dcl3.cpp"
Pname dclass__FP4nameP5table (Pname __1n , Ptable __1tbl )
# 1799 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1800 "/home/claude/cfront-3/src/dcl3.cpp"
Pclass __1cl ;
Pbase __1bt ;
Pname __1bn ;
Pname __1ntbl ;

# 1803 "/home/claude/cfront-3/src/dcl3.cpp"
__1ntbl = __1tbl -> t_name__5table ;

# 1806 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1n -> __O1__4expr.tp == 0 )|| (__1n -> __O1__4expr.tp -> base__4node != 6 ))
# 1807 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1807 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V197 ;

# 1807 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"dclass%n: non-class", (const
# 1807 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V197 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V197 )) , (const struct ea *)ea0 ,
# 1807 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} { Pname __1nx ;

# 1808 "/home/claude/cfront-3/src/dcl3.cpp"
__1nx = find_cn__6ktableFPCc ( (((struct classdef *)(((struct classdef *)__1n -> __O1__4expr.tp ))))-> k_tbl__8classdef , __1n -> __O2__4expr.string ) ;
if ((__1nx == 0 )|| (__1nx -> base__4node != 123 ))
# 1810 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1810 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V198 ;

# 1810 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"dclass%n: missingTN", (const
# 1810 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V198 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V198 )) , (const struct ea *)ea0 ,
# 1810 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1815 "/home/claude/cfront-3/src/dcl3.cpp"
;

# 1818 "/home/claude/cfront-3/src/dcl3.cpp"
__1bt = 0 ;

# 1818 "/home/claude/cfront-3/src/dcl3.cpp"
__1bn = 0 ;

# 1818 "/home/claude/cfront-3/src/dcl3.cpp"
__1cl = 0 ;

# 1821 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1nx ){ 
# 1822 "/home/claude/cfront-3/src/dcl3.cpp"
__1bt = (((struct basetype *)(((struct basetype *)__1nx -> __O1__4expr.tp ))));
if (__1bt -> base__4node != 119 ){ 
# 1825 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1825 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V199 ;

# 1825 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"%n is not aCN", (const
# 1825 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V199 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V199 )) , (const struct ea *)ea0 ,
# 1825 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
__1bn = __1bt -> b_name__8basetype ;
}
else { 
# 1830 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1830 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V200 ;

# 1830 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"%n is not aCN", (const
# 1830 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V200 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V200 )) , (const struct ea *)ea0 ,
# 1830 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1834 "/home/claude/cfront-3/src/dcl3.cpp"
if ((((struct classdef *)(((struct classdef *)__1bn -> __O1__4expr.tp ))))-> class_base__8classdef == 4)__1nx -> where__4name = __1n -> where__4name ;
__1bn -> where__4name = __1nx -> where__4name ;

# 1837 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pname __1bnn ;

# 1837 "/home/claude/cfront-3/src/dcl3.cpp"
__1bnn = insert__5tableFP4nameUc ( __1tbl , __1bn , (unsigned char )6 ) ;
__1cl = (((struct classdef *)(((struct classdef *)__1bn -> __O1__4expr.tp ))));

# 1841 "/home/claude/cfront-3/src/dcl3.cpp"
if ((! __1cl -> in_class__4type )&& (__1cl -> class_base__8classdef == 2))
# 1842 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1842 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V201 ;

# 1842 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"C%n defined previously asYC", (const struct ea *)( ((& __0__V201 )-> __O1__2ea.p =
# 1842 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1bn )), (& __0__V201 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1842 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} 
# 1844 "/home/claude/cfront-3/src/dcl3.cpp"
{ bit __1no_err ;

# 1844 "/home/claude/cfront-3/src/dcl3.cpp"
__1no_err = ((__1cl -> in_class__4type && (__1cl -> in_class__4type -> class_base__8classdef == 2))&& (__1tbl != gtbl ));

# 1847 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1cl -> defined__4type & 3)&& (__1no_err == 0 )){ 
# 1848 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1nx -> n_key__4name == 159 )
# 1849 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1849 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V202 ;

# 1849 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"hiddenC%t defined twice", (const struct ea *)( ((& __0__V202 )-> __O1__2ea.p =
# 1849 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1cl )), (& __0__V202 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1849 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else { 
# 1851 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1cl -> in_class__4type && (__1cl -> in_class__4type -> class_base__8classdef == 2))
# 1852 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1852 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V203 ;

# 1852 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V204 ;

# 1852 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot provide a specialized instance ofC%t nestedWinYC%t<>", (const struct ea *)( ((& __0__V203 )-> __O1__2ea.p =
# 1852 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1cl )), (& __0__V203 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V204 , (const void *)__1cl ->
# 1852 "/home/claude/cfront-3/src/dcl3.cpp"
in_class__4type ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 1853 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V205 ;

# 1853 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"C%t defined twice", (const struct ea *)( ((& __0__V205 )-> __O1__2ea.p =
# 1853 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1cl )), (& __0__V205 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1853 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} }
}
else { 
# 1857 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1bn -> n_scope__4name == 136 )
# 1858 "/home/claude/cfront-3/src/dcl3.cpp"
__1bn -> n_scope__4name = 139 ;
{ Pktab __2otbl ;

# 1859 "/home/claude/cfront-3/src/dcl3.cpp"
__2otbl = Ctbl ;
Ctbl = __1cl -> k_tbl__8classdef ;
dcl__8classdefFP4nameP5table ( __1cl , __1bn , __1tbl ) ;
Ctbl = __2otbl ;

# 1862 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
__1n -> __O1__4expr.tp = (struct type *)__1cl ;
return __1bnn ;

# 1865 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 1865 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 1865 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 113 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_name__FPCcP6ktableUc (const char *, Pktab , TOK );

# 376 "/home/claude/cfront-3/src/cfront.h"
void dcl__7enumdefFP4nameP5table (struct enumdef *__0this , Pname , Ptable );

# 1868 "/home/claude/cfront-3/src/dcl3.cpp"
Pname denum__FP4nameP5table (Pname __1n , Ptable __1tbl )
# 1869 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1870 "/home/claude/cfront-3/src/dcl3.cpp"
Penum __1en ;
Pbase __1bt ;
Pname __1bn ;
Pname __1ntbl ;

# 1876 "/home/claude/cfront-3/src/dcl3.cpp"
Pktab __1tb ;
Pname __1nx ;

# 1873 "/home/claude/cfront-3/src/dcl3.cpp"
__1ntbl = __1tbl -> t_name__5table ;

# 1876 "/home/claude/cfront-3/src/dcl3.cpp"
__1tb = ((__1n -> __O1__4expr.tp -> in_class__4type && __1n -> __O1__4expr.tp -> nested_sig__4type )?__1n -> __O1__4expr.tp -> in_class__4type -> k_tbl__8classdef :(((struct ktable *)0 )));
__1nx = k_find_name__FPCcP6ktableUc ( __1n -> __O2__4expr.string , __1tb ?__1tb :Ctbl , (unsigned char )159 ) ;

# 1884 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1nx ){ 
# 1886 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1nx -> __O1__4expr.tp == 0 )|| (__1nx -> __O1__4expr.tp -> base__4node != 121 )){ 
# 1887 "/home/claude/cfront-3/src/dcl3.cpp"
__1nx = __1nx -> __O1__4name.n_hidden ;
if (((__1nx == 0 )|| (__1nx -> n_key__4name != 38 ))|| (__1nx -> __O1__4expr.tp -> base__4node != 121 ))
# 1889 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1889 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V206 ;

# 1889 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"%n is not an enum", (const
# 1889 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V206 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V206 )) , (const struct ea *)ea0 ,
# 1889 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
__1bt = (((struct basetype *)(((struct basetype *)__1nx -> __O1__4expr.tp ))));
__1bn = __1bt -> b_name__8basetype ;
__1en = (((struct enumdef *)(((struct enumdef *)__1bn -> __O1__4expr.tp ))));
}
else { 
# 1896 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1896 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V207 ;

# 1896 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"%n is not an enum", (const
# 1896 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V207 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V207 )) , (const struct ea *)ea0 ,
# 1896 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1899 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pname __1bnn ;

# 1899 "/home/claude/cfront-3/src/dcl3.cpp"
__1bnn = insert__5tableFP4nameUc ( __1tbl , __1bn , (unsigned char )6 ) ;

# 1901 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1en -> defined__4type & 3)
# 1902 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1903 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1nx -> n_key__4name == 159 )
# 1904 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1904 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V208 ;

# 1904 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"hidden enum%n defined twice", (const struct ea *)( ((& __0__V208 )-> __O1__2ea.p =
# 1904 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1n )), (& __0__V208 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1904 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else 
# 1906 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1906 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V209 ;

# 1906 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"enum%n defined twice", (const struct ea *)( ((& __0__V209 )-> __O1__2ea.p =
# 1906 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1n )), (& __0__V209 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1906 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} }
else 
# 1907 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1908 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1bn -> n_scope__4name == 136 )
# 1909 "/home/claude/cfront-3/src/dcl3.cpp"
__1bn -> n_scope__4name = 139 ;
dcl__7enumdefFP4nameP5table ( __1en , __1bn , __1tbl ) ;
}
__1n -> __O1__4expr.tp = (struct type *)__1en ;
return __1bnn ;

# 1913 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 39 "/home/claude/incl-linux32/ctype.h"
extern int isdigit (int );

# 1916 "/home/claude/cfront-3/src/dcl3.cpp"
int is_probably_temp__FPCc (const char *__1str )
# 1917 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1920 "/home/claude/cfront-3/src/dcl3.cpp"
if (((__1str [0 ])!= '_' )|| ((__1str [1 ])!= '_' ))
# 1921 "/home/claude/cfront-3/src/dcl3.cpp"
return 0 ;

# 1923 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1str [2 ]){ 
# 1924 "/home/claude/cfront-3/src/dcl3.cpp"
default :
# 1925 "/home/claude/cfront-3/src/dcl3.cpp"
return 0 ;
case 'A' :case 'C' :case 'D' :case 'E' :case 'F' :
# 1927 "/home/claude/cfront-3/src/dcl3.cpp"
case 'I' :case 'K' :case 'L' :case 'M' :case 'N' :
# 1928 "/home/claude/cfront-3/src/dcl3.cpp"
case 'Q' :case 'R' :case 'S' :case
# 1928 "/home/claude/cfront-3/src/dcl3.cpp"
'T' :case 'U' :
# 1929 "/home/claude/cfront-3/src/dcl3.cpp"
case 'V' :case 'W' :
# 1930 "/home/claude/cfront-3/src/dcl3.cpp"
if (isdigit ( (int )(__1str [3 ])) )
# 1931 "/home/claude/cfront-3/src/dcl3.cpp"
return 1 ;
return 0 ;
case 'X' :
# 1934 "/home/claude/cfront-3/src/dcl3.cpp"
return 1 ;
}

# 1937 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 1940 "/home/claude/cfront-3/src/dcl3.cpp"
static int illegal_local_ref__FP4name (Pname __1nn )
# 1941 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1942 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1nn -> n_scope__4name ){ 
# 1943 "/home/claude/cfront-3/src/dcl3.cpp"
default :
# 1944 "/home/claude/cfront-3/src/dcl3.cpp"
return 0 ;
case 136 :
# 1946 "/home/claude/cfront-3/src/dcl3.cpp"
return 1 ;
case 108 :
# 1948 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1nn -> n_sto__4name == 31 )|| (__1nn -> n_sto__4name == 14 ))
# 1949 "/home/claude/cfront-3/src/dcl3.cpp"
return 0 ;
else { 
# 1951 "/home/claude/cfront-3/src/dcl3.cpp"
int __3cc ;
Ptype __3tt ;

# 1951 "/home/claude/cfront-3/src/dcl3.cpp"
__3cc = tconst__4typeFv ( __1nn -> __O1__4expr.tp ) ;
__3tt = skiptypedefs__4typeFv ( __1nn -> __O1__4expr.tp ) ;
while (__3cc && (__3tt -> base__4node == 110 )){ 
# 1954 "/home/claude/cfront-3/src/dcl3.cpp"
__3tt = (((struct vec *)(((struct vec *)__3tt ))))-> typ__5pvtyp ;
__3cc = tconst__4typeFv ( __3tt ) ;
__3tt = skiptypedefs__4typeFv ( __3tt ) ;
}
if (! __3cc ){ 
# 1959 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__3tt -> base__4node ){ 
# 1960 "/home/claude/cfront-3/src/dcl3.cpp"
case 108 :case 76 :
# 1961 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
default :
# 1963 "/home/claude/cfront-3/src/dcl3.cpp"
return 1 ;
}
}
}
return 0 ;
}
}

# 1972 "/home/claude/cfront-3/src/dcl3.cpp"
static int size_t_check__FP4type (Ptype __1tp )
# 1975 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1976 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __1tp , size_t_type , (unsigned char )0 , (unsigned char )0 ) ==
# 1976 "/home/claude/cfront-3/src/dcl3.cpp"
0 )return 0 ;
{ int __1size_t_size ;

# 1977 "/home/claude/cfront-3/src/dcl3.cpp"
__1size_t_size = tsizeof__4typeFi ( size_t_type , 0 ) ;
if ((__1size_t_size == tsizeof__4typeFi ( (struct type *)ulong_type , 0 ) )&& (check__4typeFP4typeUcT2 ( __1tp , (struct type *)ulong_type , (unsigned char )0 ,
# 1978 "/home/claude/cfront-3/src/dcl3.cpp"
(unsigned char )0 ) == 0 ))
# 1979 "/home/claude/cfront-3/src/dcl3.cpp"
return 0 ;
if ((__1size_t_size == tsizeof__4typeFi ( (struct type *)ullong_type , 0 ) )&& (check__4typeFP4typeUcT2 ( __1tp , (struct type *)ullong_type , (unsigned char )0 ,
# 1980 "/home/claude/cfront-3/src/dcl3.cpp"
(unsigned char )0 ) == 0 ))
# 1981 "/home/claude/cfront-3/src/dcl3.cpp"
return 0 ;
if ((__1size_t_size == tsizeof__4typeFi ( (struct type *)ushort_type , 0 ) )&& (check__4typeFP4typeUcT2 ( __1tp , (struct type *)ushort_type , (unsigned char )0 ,
# 1982 "/home/claude/cfront-3/src/dcl3.cpp"
(unsigned char )0 ) == 0 ))
# 1983 "/home/claude/cfront-3/src/dcl3.cpp"
return 0 ;
return 1 ;

# 1984 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 1989 "/home/claude/cfront-3/src/dcl3.cpp"
static void check_for_local__FP4expr (Pexpr __1ee );

# 1989 "/home/claude/cfront-3/src/dcl3.cpp"
static void check_for_local__FP4expr (Pexpr __1ee )
# 1990 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 1991 "/home/claude/cfront-3/src/dcl3.cpp"
static Pname __1n [2]= { ((struct name *)0 ), ((struct name *)0 )} ;
static int __1index = 0 ;

# 1994 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1ee == 0 )return ;

# 1998 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1ee -> base__4node ){ 
# 1999 "/home/claude/cfront-3/src/dcl3.cpp"
case 85 :
# 2000 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2001 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __3nn ;

# 2001 "/home/claude/cfront-3/src/dcl3.cpp"
__3nn = (((struct name *)(((struct name *)__1ee ))));
if ((((((__3nn -> n_scope__4name == 108 )|| (__3nn -> n_scope__4name == 136 ))&& illegal_local_ref__FP4name ( __3nn ) )&& (is_probably_temp__FPCc ( __3nn -> __O2__4expr.string ) ==
# 2002 "/home/claude/cfront-3/src/dcl3.cpp"
0 ))&& ((__1n [0 ])!= __3nn ))&& ((__1n [1 ])!= __3nn ))
# 2012 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2013 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2013 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V210 ;

# 2013 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"local%n used in defaultA", (const struct ea *)( ((& __0__V210 )-> __O1__2ea.p =
# 2013 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__3nn )), (& __0__V210 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2013 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
(__1n [__1index ])= __3nn ;
__1index = ((__1index == 0 )?1 :0 );
} }

# 2018 "/home/claude/cfront-3/src/dcl3.cpp"
}
case 123 :
# 2020 "/home/claude/cfront-3/src/dcl3.cpp"
case 81 :
# 2021 "/home/claude/cfront-3/src/dcl3.cpp"
case 150 :
# 2022 "/home/claude/cfront-3/src/dcl3.cpp"
case 82 :
# 2023 "/home/claude/cfront-3/src/dcl3.cpp"
case 84 :
# 2024 "/home/claude/cfront-3/src/dcl3.cpp"
case 83 :
# 2025 "/home/claude/cfront-3/src/dcl3.cpp"
case 86 :
# 2026 "/home/claude/cfront-3/src/dcl3.cpp"
case 144 :
# 2027 "/home/claude/cfront-3/src/dcl3.cpp"
case 162 :
# 2028 "/home/claude/cfront-3/src/dcl3.cpp"
case 30 :
# 2029 "/home/claude/cfront-3/src/dcl3.cpp"
case 116 :
# 2030 "/home/claude/cfront-3/src/dcl3.cpp"
case 165 :
# 2031 "/home/claude/cfront-3/src/dcl3.cpp"
case
# 2031 "/home/claude/cfront-3/src/dcl3.cpp"
169 :
# 2032 "/home/claude/cfront-3/src/dcl3.cpp"
return ;
case 68 :
# 2034 "/home/claude/cfront-3/src/dcl3.cpp"
check_for_local__FP4expr ( __1ee -> __O4__4expr.cond ) ;
break ;
case 177 :
# 2037 "/home/claude/cfront-3/src/dcl3.cpp"
check_for_local__FP4expr ( __1ee -> __O4__4expr.mem ) ;
return ;
}

# 2041 "/home/claude/cfront-3/src/dcl3.cpp"
check_for_local__FP4expr ( __1ee -> __O2__4expr.e1 ) ;
check_for_local__FP4expr ( __1ee -> __O3__4expr.e2 ) ;
}

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 328 "/home/claude/cfront-3/src/cfront.h"
Pclass classtype__4typeFv (struct type *__0this );

# 468 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 739 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr class_init__FP4exprP4typeT1P5table (Pexpr , Ptype , Pexpr , Ptable );

# 742 "/home/claude/cfront-3/src/cfront.h"
extern void dosimpl__FP4exprP4name (Pexpr , Pname );

# 1156 "/home/claude/cfront-3/src/cfront.h"
extern bit can_coerce__FP4typeT1 (Ptype , Ptype );

# 844 "/home/claude/cfront-3/src/cfront.h"

# 794 "/home/claude/cfront-3/src/cfront.h"
void del__4exprFv (struct expr *__0this );

# 799 "/home/claude/cfront-3/src/cfront.h"
long long eval__4exprFv (struct expr *__0this );

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 2045 "/home/claude/cfront-3/src/dcl3.cpp"
void dargs__FP4nameP3fctP5table (Pname __1__A211 , Pfct __1f , Ptable __1tbl )
# 2046 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2047 "/home/claude/cfront-3/src/dcl3.cpp"
int __1argnamesize ;
int __1oo ;

# 2047 "/home/claude/cfront-3/src/dcl3.cpp"
__1argnamesize = 0 ;
__1oo = const_save ;

# 2050 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> memof__3fct ){ 
# 2050 "/home/claude/cfront-3/src/dcl3.cpp"
struct dcl_context *__0__X220 ;

# 2051 "/home/claude/cfront-3/src/dcl3.cpp"
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 2051 "/home/claude/cfront-3/src/dcl3.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;
cc -> cot__11dcl_context = __1f -> memof__3fct ;
cc -> not4__11dcl_context = __1f -> memof__3fct -> memtbl__8classdef -> t_name__5table ;
cc -> tot__11dcl_context = __1f -> memof__3fct -> this_type__8classdef ;
__1tbl = __1f -> memof__3fct -> memtbl__8classdef ;
}

# 2058 "/home/claude/cfront-3/src/dcl3.cpp"
const_save = 1 ;
if (ansi_opt ){ 
# 2060 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __2th ;

# 2060 "/home/claude/cfront-3/src/dcl3.cpp"
__2th = __1f -> f_this__3fct ;
if (__2th && __2th -> __O2__4expr.string )
# 2062 "/home/claude/cfront-3/src/dcl3.cpp"
__1argnamesize += (strlen ( __2th -> __O2__4expr.string ) + 1 );
__2th = __1f -> f_result__3fct ;
if (__2th && __2th -> __O2__4expr.string )
# 2065 "/home/claude/cfront-3/src/dcl3.cpp"
__1argnamesize += (strlen ( __2th -> __O2__4expr.string ) + 1 );
}

# 2068 "/home/claude/cfront-3/src/dcl3.cpp"
{ { Pname __1a ;

# 2069 "/home/claude/cfront-3/src/dcl3.cpp"
struct dcl_context *__0__X231 ;

# 2068 "/home/claude/cfront-3/src/dcl3.cpp"
__1a = __1f -> argtype__3fct ;

# 2068 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__1a ;__1a = __1a -> __O1__4name.n_list ) { 
# 2069 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr __2init ;

# 2071 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1a -> __O1__4expr.tp == 0 ){ 
# 2072 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"A has noT") ;
__1a -> __O1__4expr.tp = (struct type *)any_type ;
__1a -> __O1__4name.n_list = 0 ;
continue ;
}
if (ansi_opt && __1a -> __O2__4expr.string )
# 2078 "/home/claude/cfront-3/src/dcl3.cpp"
__1argnamesize += (strlen ( __1a -> __O2__4expr.string ) + 1 );

# 2080 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pname __2cln ;

# 2081 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__0__X222 ;

# 2080 "/home/claude/cfront-3/src/dcl3.cpp"
__2cln = is_cl_obj__4typeFv ( __1a -> __O1__4expr.tp ) ;

# 2083 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2084 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __3t ;
Pclass __3cl ;

# 2084 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = skiptypedefs__4typeFv ( __1a -> __O1__4expr.tp ) ;
__3cl = ((__3t -> base__4node == 119 )?classtype__4typeFv ( __3t ) :(((struct classdef *)0 )));
if ((__3cl && __3cl -> c_abstract__8classdef )&& (__3cl -> defined__4type & 01 )){ 
# 2086 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X221 ;

# 2087 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2087 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V212 ;

# 2087 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"abstractC%t cannot be used as anAT", (const struct ea *)( ((& __0__V212 )-> __O1__2ea.p =
# 2087 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__3cl )), (& __0__V212 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2087 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
{ 
# 2088 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V213 ;

# 2088 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V214 ;

# 2088 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'C' , (const char *)"\t%a is a pure virtualF ofC%t\n", (const struct ea *)( (__2__X221 =
# 2088 "/home/claude/cfront-3/src/dcl3.cpp"
(const void *)__3cl -> c_abstract__8classdef ), ( ((& __0__V213 )-> __O1__2ea.p = __2__X221 ), (& __0__V213 )) ) , (const
# 2088 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V214 )-> __O1__2ea.p = ((const void *)__3cl )), (& __0__V214 )) , (const struct ea *)ea0 ,
# 2088 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} } }
}

# 2092 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2cln && ( (__0__X222 = (((struct classdef *)(((struct classdef *)__2cln -> __O1__4expr.tp ))))), ( __0__X222 -> c_itor__8classdef ) )
# 2092 "/home/claude/cfront-3/src/dcl3.cpp"
)
# 2093 "/home/claude/cfront-3/src/dcl3.cpp"
__1a -> n_xref__4name = 1 ;
else { 
# 2095 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __3t ;

# 2095 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = __1a -> __O1__4expr.tp ;
while (__3t -> base__4node == 97 )
# 2097 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype -> __O1__4expr.tp ;
if (__3t -> base__4node == 108 )
# 2099 "/home/claude/cfront-3/src/dcl3.cpp"
__1a -> __O1__4expr.tp = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , __1a -> __O1__4expr.tp )
# 2099 "/home/claude/cfront-3/src/dcl3.cpp"
;
}

# 2102 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2init = __1a -> __O3__4expr.n_initializer )
# 2105 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2106 "/home/claude/cfront-3/src/dcl3.cpp"
Pptr __3pt ;
if (__2init == dummy ){ 
# 2108 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"emptyIr") ;
__1a -> __O3__4expr.n_initializer = 0 ;
continue ;
}
if (__2cln ){ 
# 2113 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2init -> base__4node == 157 ){ 
# 2114 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__2init -> __O4__4expr.tp2 -> base__4node ){ 
# 2114 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__1__X223 ;

# 2114 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__1__X224 ;

# 2115 "/home/claude/cfront-3/src/dcl3.cpp"
case 6 :
# 2116 "/home/claude/cfront-3/src/dcl3.cpp"
if (! ( (__1__X223 = (((struct classdef *)(((struct classdef *)__2init -> __O4__4expr.tp2 ))))), ( (__1__X224 = (((struct classdef *)(((struct classdef *)__2cln ->
# 2116 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__4expr.tp ))))), ( ((__1__X223 == __1__X224 )?1 :((__1__X223 && __1__X224 )?(((int )same_class__8classdefFP8classdefi ( __1__X223 , __1__X224 , 0 ) )):0 ))) ) ) )
# 2117 "/home/claude/cfront-3/src/dcl3.cpp"
goto inin2 ;
# 2117 "/home/claude/cfront-3/src/dcl3.cpp"

# 2118 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
default :
# 2120 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2121 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __7n2 ;

# 2122 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__1__X225 ;

# 2122 "/home/claude/cfront-3/src/dcl3.cpp"
struct classdef *__1__X226 ;

# 2121 "/home/claude/cfront-3/src/dcl3.cpp"
__7n2 = is_cl_obj__4typeFv ( __2init -> __O4__4expr.tp2 ) ;
if ((__7n2 == 0 )|| (! ( (__1__X225 = (((struct classdef *)(((struct classdef *)__7n2 -> __O1__4expr.tp ))))), ( (__1__X226 = (((struct classdef *)(((struct
# 2122 "/home/claude/cfront-3/src/dcl3.cpp"
classdef *)__2cln -> __O1__4expr.tp ))))), ( ((__1__X225 == __1__X226 )?1 :((__1__X225 && __1__X226 )?(((int )same_class__8classdefFP8classdefi ( __1__X225 , __1__X226 , 0 ) )):0 ))) ) ) ))
# 2123 "/home/claude/cfront-3/src/dcl3.cpp"
goto
# 2123 "/home/claude/cfront-3/src/dcl3.cpp"
inin2 ;
}
}

# 2127 "/home/claude/cfront-3/src/dcl3.cpp"
__1a -> __O3__4expr.n_initializer = (__2init = 0 );
error__FiPCc ( (int )'s' , (const char *)"K as defaultA") ;
}
else { 
# 2131 "/home/claude/cfront-3/src/dcl3.cpp"
inin2 :
# 2132 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2init -> base__4node == 124 )
# 2133 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"list as AIr") ;
# 2133 "/home/claude/cfront-3/src/dcl3.cpp"

# 2134 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pexpr __5i ;

# 2134 "/home/claude/cfront-3/src/dcl3.cpp"
__5i = typ__4exprFP5table ( __2init , __1tbl ) ;
__2init = class_init__FP4exprP4typeT1P5table ( (struct expr *)__1a , __1a -> __O1__4expr.tp , __5i , __1tbl ) ;
if ((__5i != __2init )&& (__2init -> base__4node == 111 )){ 
# 2137 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCc ( (int )'s' , (const char *)"K needed forAIr")
# 2137 "/home/claude/cfront-3/src/dcl3.cpp"
;
__2init = 0 ;
}
else { 
# 2141 "/home/claude/cfront-3/src/dcl3.cpp"
dosimpl__FP4exprP4name ( __2init , cc -> nof__11dcl_context ) ;
__2init -> permanent__4node = 2 ;
}
__1a -> __O3__4expr.n_initializer = __2init ;

# 2144 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
}
else if (__3pt = is_ref__4typeFv ( __1a -> __O1__4expr.tp ) ){ 
# 2148 "/home/claude/cfront-3/src/dcl3.cpp"
ref_initializer ++ ;
__2init = typ__4exprFP5table ( __2init , __1tbl ) ;
ref_initializer -- ;
{ int __4tcount ;

# 2151 "/home/claude/cfront-3/src/dcl3.cpp"
__4tcount = stcount ;
__2init = ref_init__FP3ptrP4exprP5table ( __3pt , __2init , __1tbl ) ;
if (__4tcount != stcount ){ 
# 2154 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCc ( (int )'s' , (const char *)"needs temporaryV to evaluateAIr") ;
# 2154 "/home/claude/cfront-3/src/dcl3.cpp"

# 2155 "/home/claude/cfront-3/src/dcl3.cpp"
__2init = 0 ;
}
else { 
# 2158 "/home/claude/cfront-3/src/dcl3.cpp"
dosimpl__FP4exprP4name ( __2init , cc -> nof__11dcl_context ) ;
__2init -> permanent__4node = 2 ;
}
__1a -> __O3__4expr.n_initializer = __2init ;

# 2161 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
else { 
# 2164 "/home/claude/cfront-3/src/dcl3.cpp"
Pptr __4p ;

# 2164 "/home/claude/cfront-3/src/dcl3.cpp"
__4p = is_ptr__4typeFv ( __1a -> __O1__4expr.tp ) ;
if (perf_opt && ((__2init -> base__4node == 23 )|| (__2init -> base__4node == 184 )))
# 2167 "/home/claude/cfront-3/src/dcl3.cpp"
New_in_arg_list = 1 ;
__2init = typ__4exprFP5table ( __2init , __1tbl ) ;
if (__4p )
# 2170 "/home/claude/cfront-3/src/dcl3.cpp"
__2init = ptr_init__FP3ptrP4exprP5table ( __4p , __2init , __1tbl ) ;

# 2172 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __1a -> __O1__4expr.tp , __2init -> __O1__4expr.tp , (unsigned char )136 , (unsigned char )0 ) ){ 
# 2173 "/home/claude/cfront-3/src/dcl3.cpp"
int
# 2173 "/home/claude/cfront-3/src/dcl3.cpp"
__5i ;

# 2173 "/home/claude/cfront-3/src/dcl3.cpp"
__5i = can_coerce__FP4typeT1 ( __1a -> __O1__4expr.tp , __2init -> __O1__4expr.tp ) ;

# 2175 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__5i ){ 
# 2175 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X230 ;

# 2176 "/home/claude/cfront-3/src/dcl3.cpp"
case 1 :
# 2177 "/home/claude/cfront-3/src/dcl3.cpp"
if (Ncoerce ){ 
# 2178 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __7cn ;
Pname __7xx ;
Pref __7r ;

# 2181 "/home/claude/cfront-3/src/dcl3.cpp"
struct ref *__0__X227 ;

# 2181 "/home/claude/cfront-3/src/dcl3.cpp"
struct expr *__2__X228 ;

# 2181 "/home/claude/cfront-3/src/dcl3.cpp"
struct expr *__2__X229 ;

# 2178 "/home/claude/cfront-3/src/dcl3.cpp"
__7cn = is_cl_obj__4typeFv ( __2init -> __O1__4expr.tp ) ;
__7xx = __ct__4nameFPCc ( (struct name *)0 , Ncoerce -> __O2__4expr.string ) ;
__7r = ( (__0__X227 = 0 ), ( (__2__X228 = __2init ), ( (__2__X229 = (struct expr *)__7xx ), ( ((__0__X227 || (__0__X227 =
# 2180 "/home/claude/cfront-3/src/dcl3.cpp"
(struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X227 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X227 ), ((unsigned char
# 2180 "/home/claude/cfront-3/src/dcl3.cpp"
)45 ), __2__X228 , (struct expr *)0 ) ), (__0__X227 -> __O4__4expr.mem = __2__X229 )) :0 ), __0__X227 ) ) ) ) ;
# 2180 "/home/claude/cfront-3/src/dcl3.cpp"

# 2181 "/home/claude/cfront-3/src/dcl3.cpp"
__2init = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , (struct expr *)__7r , (struct expr *)0 ) ;
__2init = typ__4exprFP5table ( __2init , __1tbl ) ;
}
break ;
default :
# 2186 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2186 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V215 ;

# 2186 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%d possible conversions for defaultA", (const struct ea *)( (( ((& __0__V215 )->
# 2186 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__2ea.i = ((unsigned long )__5i )), 0 ) ), (& __0__V215 )) , (const struct ea *)ea0 , (const struct
# 2186 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
case 0 :
# 2188 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2188 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V216 ;

# 2188 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V217 ;

# 2188 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V218 ;

# 2188 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badIrT%t forA%n (%tX)", (const struct ea *)( (__2__X230 = (const void
# 2188 "/home/claude/cfront-3/src/dcl3.cpp"
*)__2init -> __O1__4expr.tp ), ( ((& __0__V216 )-> __O1__2ea.p = __2__X230 ), (& __0__V216 )) ) , (const struct ea *)(
# 2188 "/home/claude/cfront-3/src/dcl3.cpp"
((& __0__V217 )-> __O1__2ea.p = ((const void *)__1a )), (& __0__V217 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V218 ,
# 2188 "/home/claude/cfront-3/src/dcl3.cpp"
(const void *)__1a -> __O1__4expr.tp ) , (const struct ea *)ea0 ) ;
if (__2init && (__2init -> permanent__4node == 0 ))del__4exprFv ( __2init ) ;
__1a -> __O3__4expr.n_initializer = (__2init = 0 );
} } }
}

# 2194 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2init && (__2init -> __O1__4expr.tp -> base__4node != 141 )){ 
# 2195 "/home/claude/cfront-3/src/dcl3.cpp"
dosimpl__FP4exprP4name ( __2init , cc -> nof__11dcl_context ) ;
__2init -> permanent__4node = 2 ;
__1a -> __O3__4expr.n_initializer = __2init ;
Neval = 0 ;
{ long long __5i ;

# 2199 "/home/claude/cfront-3/src/dcl3.cpp"
__5i = eval__4exprFv ( __2init ) ;
if (Neval == 0 ){ 
# 2201 "/home/claude/cfront-3/src/dcl3.cpp"
__1a -> n_evaluated__4name = 1 ;
__1a -> n_val__4name = __5i ;
}

# 2203 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
}
if (__1a -> __O3__4expr.n_initializer )
# 2207 "/home/claude/cfront-3/src/dcl3.cpp"
check_for_local__FP4expr ( __1a -> __O3__4expr.n_initializer ) ;
}

# 2208 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
if (ansi_opt && __1argnamesize ){ 
# 2211 "/home/claude/cfront-3/src/dcl3.cpp"
char *__2ps ;
Pname __2a ;

# 2211 "/home/claude/cfront-3/src/dcl3.cpp"
__2ps = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* __1argnamesize )) ));
__2a = __1f -> f_this__3fct ;
if (__2a && __2a -> __O2__4expr.string ){ 
# 2214 "/home/claude/cfront-3/src/dcl3.cpp"
int __3i ;

# 2214 "/home/claude/cfront-3/src/dcl3.cpp"
__3i = (strlen ( __2a -> __O2__4expr.string ) + 1 );
if ((__1argnamesize -= __3i )< 0 )
# 2216 "/home/claude/cfront-3/src/dcl3.cpp"
goto bad ;
strcpy ( __2ps , __2a -> __O2__4expr.string ) ;
__2a -> __O2__4expr.string = (const char *)__2ps ;
__2ps += __3i ;
}
__2a = __1f -> f_result__3fct ;
if (__2a && __2a -> __O2__4expr.string ){ 
# 2223 "/home/claude/cfront-3/src/dcl3.cpp"
int __3i ;

# 2223 "/home/claude/cfront-3/src/dcl3.cpp"
__3i = (strlen ( __2a -> __O2__4expr.string ) + 1 );
if ((__1argnamesize -= __3i )< 0 )
# 2225 "/home/claude/cfront-3/src/dcl3.cpp"
goto bad ;
strcpy ( __2ps , __2a -> __O2__4expr.string ) ;
__2a -> __O2__4expr.string = (const char *)__2ps ;
__2ps += __3i ;
}
for(__2a = __1f -> argtype__3fct ;__2a ;__2a = __2a -> __O1__4name.n_list ) { 
# 2231 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2a -> __O2__4expr.string == 0 )
# 2232 "/home/claude/cfront-3/src/dcl3.cpp"
continue ;
{ int __3i ;

# 2233 "/home/claude/cfront-3/src/dcl3.cpp"
__3i = (strlen ( __2a -> __O2__4expr.string ) + 1 );
if ((__1argnamesize -= __3i )< 0 )
# 2235 "/home/claude/cfront-3/src/dcl3.cpp"
goto bad ;
strcpy ( __2ps , __2a -> __O2__4expr.string ) ;
__2a -> __O2__4expr.string = (const char *)__2ps ;
__2ps += __3i ;

# 2238 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
if (__1argnamesize )
# 2241 "/home/claude/cfront-3/src/dcl3.cpp"
bad :
# 2242 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2242 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V219 ;

# 2242 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"bad argN size for%t", (const struct ea *)( ((&
# 2242 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V219 )-> __O1__2ea.p = ((const void *)__1f )), (& __0__V219 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2242 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} }
const_save = __1oo ;
if (__1f -> memof__3fct )( ( (cc -- ), (((void )0 ))) ) ;

# 2245 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 2245 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 2248 "/home/claude/cfront-3/src/dcl3.cpp"
void merge_init__FP4nameP3fctT2 (Pname __1nn , Pfct __1f , Pfct __1nf )
# 2249 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2250 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __1a1 ;
Pname __1a2 ;

# 2250 "/home/claude/cfront-3/src/dcl3.cpp"
__1a1 = __1f -> argtype__3fct ;
__1a2 = __1nf -> argtype__3fct ;

# 2253 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__1a1 ;( (__1a1 = __1a1 -> __O1__4name.n_list ), (__1a2 = __1a2 -> __O1__4name.n_list )) ) { 
# 2254 "/home/claude/cfront-3/src/dcl3.cpp"
int __2i1 ;
int __2i2 ;

# 2254 "/home/claude/cfront-3/src/dcl3.cpp"
__2i1 = (__1a1 -> __O3__4expr.n_initializer || __1a1 -> n_evaluated__4name );
__2i2 = (__1a2 -> __O3__4expr.n_initializer || __1a2 -> n_evaluated__4name );

# 2257 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2i1 && __2i2 )
# 2258 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1a1 -> __O2__4expr.string == 0 )
# 2259 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2259 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V232 ;

# 2259 "/home/claude/cfront-3/src/dcl3.cpp"
error__FP3locPCcRC2eaN33 ( & __1a1 -> where__4name , (const char *)"twoIrs for%nA", (const struct ea *)(
# 2259 "/home/claude/cfront-3/src/dcl3.cpp"
((& __0__V232 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V232 )) , (const struct ea *)ea0 , (const struct
# 2259 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 2261 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2261 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V233 ;

# 2261 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V234 ;

# 2261 "/home/claude/cfront-3/src/dcl3.cpp"
error__FP3locPCcRC2eaN33 ( & __1a1 -> where__4name , (const char *)"twoIrs for%nA%n", (const struct ea *)(
# 2261 "/home/claude/cfront-3/src/dcl3.cpp"
((& __0__V233 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V233 )) , (const struct ea *)( ((& __0__V234 )->
# 2261 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__2ea.p = ((const void *)__1a1 )), (& __0__V234 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 2261 "/home/claude/cfront-3/src/dcl3.cpp"
} 
# 2263 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2i1 ){ 
# 2264 "/home/claude/cfront-3/src/dcl3.cpp"
__1a2 -> __O3__4expr.n_initializer = __1a1 -> __O3__4expr.n_initializer ;
__1a2 -> n_evaluated__4name = __1a1 -> n_evaluated__4name ;
__1a2 -> n_val__4name = __1a1 -> n_val__4name ;
}
if (__2i2 ){ 
# 2269 "/home/claude/cfront-3/src/dcl3.cpp"
__1a1 -> __O3__4expr.n_initializer = __1a2 -> __O3__4expr.n_initializer ;
__1a1 -> n_evaluated__4name = __1a2 -> n_evaluated__4name ;
__1a1 -> n_val__4name = __1a2 -> n_val__4name ;
}

# 2274 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 844 "/home/claude/cfront-3/src/cfront.h"

# 2277 "/home/claude/cfront-3/src/dcl3.cpp"
Pexpr try_to_coerce__FP4typeP4exprPCcP5table (Ptype __1rt , Pexpr __1e , const char *__1s , Ptable __1tbl )
# 2281 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2282 "/home/claude/cfront-3/src/dcl3.cpp"
int __1i ;
Pname __1cn ;

# 2283 "/home/claude/cfront-3/src/dcl3.cpp"
__1cn = 0 ;

# 2286 "/home/claude/cfront-3/src/dcl3.cpp"
if (((__1e -> __O1__4expr.tp && (__1cn = is_cl_obj__4typeFv ( __1e -> __O1__4expr.tp ) ))&& (__1i = can_coerce__FP4typeT1 ( __1rt , __1e -> __O1__4expr.tp ) ))&&
# 2286 "/home/claude/cfront-3/src/dcl3.cpp"
Ncoerce )
# 2292 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2293 "/home/claude/cfront-3/src/dcl3.cpp"
if (1 < __1i )
# 2294 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2294 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V235 ;

# 2294 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V236 ;

# 2294 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%d possible conversions for %s", (const struct ea *)( (( ((& __0__V235 )->
# 2294 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__2ea.i = ((unsigned long )__1i )), 0 ) ), (& __0__V235 )) , (const struct ea *)( ((& __0__V236 )->
# 2294 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__2ea.p = ((const void *)__1s )), (& __0__V236 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 2294 "/home/claude/cfront-3/src/dcl3.cpp"
} 
# 2296 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pname __2xx ;
Pref __2r ;
Pexpr __2c ;

# 2299 "/home/claude/cfront-3/src/dcl3.cpp"
struct ref *__0__X237 ;

# 2299 "/home/claude/cfront-3/src/dcl3.cpp"
struct expr *__2__X238 ;

# 2299 "/home/claude/cfront-3/src/dcl3.cpp"
struct expr *__2__X239 ;

# 2296 "/home/claude/cfront-3/src/dcl3.cpp"
__2xx = __ct__4nameFPCc ( (struct name *)0 , Ncoerce -> __O2__4expr.string ) ;
__2r = ( (__0__X237 = 0 ), ( (__2__X238 = __1e ), ( (__2__X239 = (struct expr *)__2xx ), ( ((__0__X237 || (__0__X237 =
# 2297 "/home/claude/cfront-3/src/dcl3.cpp"
(struct ref *)__nw__4exprSFUl ( (size_t )(sizeof (struct ref))) ))?( (__0__X237 = (struct ref *)__ct__4exprFUcP4exprT2 ( ((struct expr *)__0__X237 ), ((unsigned char
# 2297 "/home/claude/cfront-3/src/dcl3.cpp"
)45 ), __2__X238 , (struct expr *)0 ) ), (__0__X237 -> __O4__4expr.mem = __2__X239 )) :0 ), __0__X237 ) ) ) ) ;
# 2297 "/home/claude/cfront-3/src/dcl3.cpp"

# 2298 "/home/claude/cfront-3/src/dcl3.cpp"
__2c = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )146 , (struct expr *)__2r , (struct expr *)0 ) ;
__2c = typ__4exprFP5table ( __2c , __1tbl ) ;

# 2301 "/home/claude/cfront-3/src/dcl3.cpp"
return __2c ;

# 2301 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 2304 "/home/claude/cfront-3/src/dcl3.cpp"
return (struct expr *)0 ;
}

# 2307 "/home/claude/cfront-3/src/dcl3.cpp"
int in_class_dcl = 0 ;

# 345 "/home/claude/cfront-3/src/cfront.h"
void dcl__4typeFP5table (struct type *__0this , Ptable );

# 538 "/home/claude/cfront-3/src/cfront.h"
extern Pname find_virtual__FP8classdefP4name (Pclass , Pname );

# 465 "/home/claude/cfront-3/src/cfront.h"
Pname has_oper__8classdefFUc (struct classdef *__0this , TOK );

# 667 "/home/claude/cfront-3/src/cfront.h"
static struct gen *__ct__3genFv (struct gen *__0this ){ 
# 667 "/home/claude/cfront-3/src/cfront.h"
struct type *__0__X5 ;

# 667 "/home/claude/cfront-3/src/cfront.h"
struct node *__0__X1 ;

# 667 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct gen *)__nw__FUl ( (size_t )(sizeof (struct gen))) )){ ( ( (__0this = (struct
# 667 "/home/claude/cfront-3/src/cfront.h"
gen *)( (__0__X5 = (((struct type *)__0this ))), ( ((__0__X5 || (__0__X5 = (struct type *)__nw__FUl ( (size_t )(sizeof (struct type))) ))?(
# 667 "/home/claude/cfront-3/src/cfront.h"
( ( ( ( ( ( ( (__0__X5 = (struct type *)( (__0__X1 = (((struct node *)__0__X5 ))), (
# 667 "/home/claude/cfront-3/src/cfront.h"
((__0__X1 || (__0__X1 = (struct node *)__nw__FUl ( (size_t )(sizeof (struct node))) ))?( ( (__0__X1 -> base__4node = 0 ), (__0__X1 ->
# 667 "/home/claude/cfront-3/src/cfront.h"
permanent__4node = 0 )) , (__0__X1 -> baseclass__4node = 0 )) :0 ), __0__X1 ) ) ), (__0__X5 -> defined__4type = 0 )) ,
# 667 "/home/claude/cfront-3/src/cfront.h"
(__0__X5 -> lex_level__4type = 0 )) , (__0__X5 -> templ_base__4type = 0)) , (__0__X5 -> in_class__4type = 0 )) , (__0__X5 -> nested_sig__4type =
# 667 "/home/claude/cfront-3/src/cfront.h"
0 )) , (__0__X5 -> local_sig__4type = 0 )) , (__0__X5 -> b_const__4type = 0 )) , (__0__X5 -> ansi_const__4type = 0 )) :0 ),
# 667 "/home/claude/cfront-3/src/cfront.h"
__0__X5 ) ) ), (__0this -> fct_list__3gen = 0 )) , (__0this -> holds_templ__3gen = 0)) ;

# 667 "/home/claude/cfront-3/src/cfront.h"
__0this -> base__4node = 76 ;
} 
# 667 "/home/claude/cfront-3/src/cfront.h"
return __0this ;

# 667 "/home/claude/cfront-3/src/cfront.h"
}

# 944 "/home/claude/cfront-3/src/cfront.h"
void take_addr__4nameFv (struct name *__0this );

# 579 "/home/claude/cfront-3/src/cfront.h"
struct basetype *__ct__8basetypeFUcP4name (struct basetype *__0this , TOK , Pname );

# 667 "/home/claude/cfront-3/src/cfront.h"

# 2309 "/home/claude/cfront-3/src/dcl3.cpp"
Pname dofct__4nameFP5tableUc (register struct name *__0this , Ptable __1tbl , TOK __1scope )
# 2310 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2311 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __1f ;
Pname __1class_name ;
Ptable __1etbl ;
int __1old_in_class_dcl ;
int __1just_made ;

# 2311 "/home/claude/cfront-3/src/dcl3.cpp"
__1f = (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))));

# 2314 "/home/claude/cfront-3/src/dcl3.cpp"
__1old_in_class_dcl = in_class_dcl ;
__1just_made = 0 ;

# 2320 "/home/claude/cfront-3/src/dcl3.cpp"
;

# 2322 "/home/claude/cfront-3/src/dcl3.cpp"
in_class_dcl = (cc -> not4__11dcl_context != 0 );

# 2324 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_inline__3fct )
# 2325 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> n_sto__4name = 31 ;

# 2327 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> n_stclass__4name )
# 2328 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__0this -> n_stclass__4name ){ 
# 2328 "/home/claude/cfront-3/src/dcl3.cpp"
unsigned long __2__X310 ;

# 2329 "/home/claude/cfront-3/src/dcl3.cpp"
case 14 :
# 2330 "/home/claude/cfront-3/src/dcl3.cpp"
case 31 :
# 2331 "/home/claude/cfront-3/src/dcl3.cpp"
case 76 :
# 2332 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
default :
# 2334 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2334 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V240 ;

# 2334 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V241 ;

# 2334 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n declared%k", (const struct ea *)( ((& __0__V240 )-> __O1__2ea.p =
# 2334 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V240 )) , (const struct ea *)( (__2__X310 = __0this -> n_stclass__4name ), ( ((
# 2334 "/home/claude/cfront-3/src/dcl3.cpp"
((& __0__V241 )-> __O1__2ea.i = __2__X310 ), 0 ) ), (& __0__V241 )) ) , (const struct ea *)ea0 , (const
# 2334 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)ea0 ) ;
__0this -> n_stclass__4name = 14 ;
} }

# 2338 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> __O2__4name.n_qualifier ){ 
# 2339 "/home/claude/cfront-3/src/dcl3.cpp"
__1class_name = (((struct basetype *)(((struct basetype *)__0this -> __O2__4name.n_qualifier -> __O1__4expr.tp ))))-> b_name__8basetype ;
__1etbl = (((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))))-> memtbl__8classdef ;
}
else { 
# 2343 "/home/claude/cfront-3/src/dcl3.cpp"
__1class_name = cc -> not4__11dcl_context ;

# 2346 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1class_name && (__1tbl != cc -> cot__11dcl_context -> memtbl__8classdef )){ 
# 2347 "/home/claude/cfront-3/src/dcl3.cpp"
__1class_name = 0 ;
in_class_dcl = 0 ;
}
}
if (__1class_name )__1f -> memof__3fct = (((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))));

# 2353 "/home/claude/cfront-3/src/dcl3.cpp"
dcl__4typeFP5table ( __0this -> __O1__4expr.tp , __1tbl ) ;

# 2355 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2356 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __2tt ;
Pclass __2cl ;

# 2356 "/home/claude/cfront-3/src/dcl3.cpp"
__2tt = skiptypedefs__4typeFv ( (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> returns__3fct ) ;
__2cl = ((__2tt -> base__4node == 119 )?classtype__4typeFv ( __2tt ) :(((struct classdef *)0 )));
if ((__2cl && __2cl -> c_abstract__8classdef )&& (__2cl -> defined__4type & 01 )){ 
# 2358 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X311 ;

# 2359 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2359 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V242 ;

# 2359 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"abstractC%t cannot be used as aF returnT", (const struct ea *)( ((& __0__V242 )-> __O1__2ea.p =
# 2359 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__2cl )), (& __0__V242 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2359 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
{ 
# 2360 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V243 ;

# 2360 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V244 ;

# 2360 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'C' , (const char *)"\t%a is a pure virtualF ofC%t\n", (const struct ea *)( (__2__X311 =
# 2360 "/home/claude/cfront-3/src/dcl3.cpp"
(const void *)__2cl -> c_abstract__8classdef ), ( ((& __0__V243 )-> __O1__2ea.p = __2__X311 ), (& __0__V243 )) ) , (const
# 2360 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V244 )-> __O1__2ea.p = ((const void *)__2cl )), (& __0__V244 )) , (const struct ea *)ea0 ,
# 2360 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} } }
}

# 2364 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> __O2__4name.n_qualifier ){ 
# 2365 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_virtual__3fct ){ 
# 2366 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2366 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V245 ;

# 2366 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V246 ;

# 2366 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"virtual specifier illegal outsideCD(%n::%s())", (const struct ea *)( ((& __0__V245 )-> __O1__2ea.p =
# 2366 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1class_name )), (& __0__V245 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V246 , (const void *)__0this ->
# 2366 "/home/claude/cfront-3/src/dcl3.cpp"
__O2__4expr.string ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1f -> f_virtual__3fct = 0 ;
} }

# 2370 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__0this -> n_sto__4name && (__0this -> n_sto__4name != 18 ))&& (__1f -> f_inline__3fct == 0 ))
# 2376 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2376 "/home/claude/cfront-3/src/dcl3.cpp"
unsigned long __2__X312 ;

# 2377 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2377 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V247 ;

# 2377 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V248 ;

# 2377 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k specified for QdN%n", (const struct ea *)( (__2__X312 = __0this -> n_sto__4name ),
# 2377 "/home/claude/cfront-3/src/dcl3.cpp"
( (( ((& __0__V247 )-> __O1__2ea.i = __2__X312 ), 0 ) ), (& __0__V247 )) ) , (const struct
# 2377 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)( ((& __0__V248 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V248 )) , (const struct ea *)ea0 , (const
# 2377 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)ea0 ) ;
__0this -> n_sto__4name = 0 ;
} }
}
else { 
# 2382 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_static__3fct && __1f -> f_virtual__3fct ){ 
# 2383 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"virtual staticM")
# 2383 "/home/claude/cfront-3/src/dcl3.cpp"
;
__1f -> f_virtual__3fct = 0 ;
}

# 2387 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> n_oper__4name )
# 2388 "/home/claude/cfront-3/src/dcl3.cpp"
check_oper__4nameFP4name ( __0this , __1class_name ) ;
__1etbl = __1tbl ;
}

# 2392 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1class_name ){ 
# 2393 "/home/claude/cfront-3/src/dcl3.cpp"
Pclass __2cl ;

# 2393 "/home/claude/cfront-3/src/dcl3.cpp"
__2cl = (((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))));
if ((__1f -> f_virtual__3fct == 0 )&& find_virtual__FP8classdefP4name ( __1f -> memof__3fct , __0this ) )
# 2395 "/home/claude/cfront-3/src/dcl3.cpp"
__1f -> f_virtual__3fct = 22222 ;

# 2398 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_static__3fct && __1f -> f_virtual__3fct ){ 
# 2399 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"virtual staticM") ;
# 2399 "/home/claude/cfront-3/src/dcl3.cpp"

# 2400 "/home/claude/cfront-3/src/dcl3.cpp"
__1f -> f_virtual__3fct = 0 ;
}

# 2403 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__2cl -> csu__8classdef == 36 )&& __1f -> f_virtual__3fct ){ 
# 2405 "/home/claude/cfront-3/src/dcl3.cpp"
Ptable __3tt ;

# 2405 "/home/claude/cfront-3/src/dcl3.cpp"
__3tt = __0this -> __O4__4expr.n_table ;
__0this -> __O4__4expr.n_table = __1etbl ;
{ 
# 2407 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V249 ;

# 2407 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n: cannot declare a virtualFWin union", (const struct ea *)( ((& __0__V249 )-> __O1__2ea.p =
# 2407 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V249 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2407 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
__0this -> __O4__4expr.n_table = __3tt ;
} }
}

# 2412 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_const__3fct && (__1f -> memof__3fct == 0 )){ 
# 2413 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"onlyMFs can be constant")
# 2413 "/home/claude/cfront-3/src/dcl3.cpp"
;
}

# 2416 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1etbl == 0 )|| (__1etbl -> base__4node != 142 ))
# 2417 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2417 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V250 ;

# 2417 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::dcl: etbl=%d", (const struct ea *)( ((&
# 2417 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V250 )-> __O1__2ea.p = ((const void *)__1etbl )), (& __0__V250 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2417 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} 
# 2419 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__0this -> n_oper__4name ){ 
# 2496 "/home/claude/cfront-3/src/dcl3.cpp"
Pclass __2cl ;

# 2420 "/home/claude/cfront-3/src/dcl3.cpp"
case 161 :
# 2421 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_virtual__3fct ){ 
# 2422 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"virtualK") ;
__1f -> f_virtual__3fct = 0 ;
}
if (__1f -> f_const__3fct ){ 
# 2426 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"constructors cannot be const") ;
__1f -> f_const__3fct = 0 ;
}
break ;
case 162 :
# 2431 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_const__3fct ){ 
# 2432 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"destructors cannot be const") ;
__1f -> f_const__3fct = 0 ;
}
break ;
case 44 :
# 2437 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> argtype__3fct )
# 2438 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2438 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V251 ;

# 2438 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n takes noAs", (const struct ea *)( ((& __0__V251 )-> __O1__2ea.p =
# 2438 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V251 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2438 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} if (is_ptr__4typeFv ( __1f -> returns__3fct ) == 0 ){ 
# 2440 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __3cn ;

# 2440 "/home/claude/cfront-3/src/dcl3.cpp"
__3cn = is_cl_obj__4typeFv ( __1f -> returns__3fct ) ;
if ((__3cn == 0 )&& (__1f -> returns__3fct -> base__4node == 158 ))
# 2442 "/home/claude/cfront-3/src/dcl3.cpp"
__3cn = is_cl_obj__4typeFv ( (((struct ptr *)(((struct ptr *)__1f -> returns__3fct ))))-> typ__5pvtyp ) ;
# 2442 "/home/claude/cfront-3/src/dcl3.cpp"

# 2443 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__3cn == 0 )|| (has_oper__8classdefFUc ( ((struct classdef *)(((struct classdef *)__3cn -> __O1__4expr.tp ))), (unsigned char )44 ) == 0 ))
# 2447 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2447 "/home/claude/cfront-3/src/dcl3.cpp"
const
# 2447 "/home/claude/cfront-3/src/dcl3.cpp"
void *__2__X313 ;

# 2448 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__3cn && __1class_name )&& (strcmp ( __3cn -> __O2__4expr.string , __1class_name -> __O2__4expr.string ) == 0 ))
# 2452 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2452 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V252 ;

# 2452 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V253 ;

# 2452 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V254 ;

# 2452 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s::%n cannot return aR orCO ofC%n", (const struct ea *)( (__2__X313 = (const void
# 2452 "/home/claude/cfront-3/src/dcl3.cpp"
*)__3cn -> __O2__4expr.string ), ( ((& __0__V252 )-> __O1__2ea.p = __2__X313 ), (& __0__V252 )) ) , (const struct ea *)(
# 2452 "/home/claude/cfront-3/src/dcl3.cpp"
((& __0__V253 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V253 )) , (const struct ea *)( ((& __0__V254 )->
# 2452 "/home/claude/cfront-3/src/dcl3.cpp"
__O1__2ea.p = ((const void *)__3cn )), (& __0__V254 )) , (const struct ea *)ea0 ) ;
} else 
# 2454 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2454 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V255 ;

# 2454 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n must return aP toCO, aR toCO, or aCO", (const struct ea *)( ((& __0__V255 )-> __O1__2ea.p =
# 2454 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V255 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2454 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} __0this -> __O1__4expr.tp = (struct type *)any_type ;
}
}
else { 
# 2459 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __3cn ;

# 2459 "/home/claude/cfront-3/src/dcl3.cpp"
__3cn = is_cl_obj__4typeFv ( is_ptr__4typeFv ( __1f -> returns__3fct ) -> typ__5pvtyp ) ;
if (__3cn == 0 )
# 2461 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2461 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V256 ;

# 2461 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n must return aP toCO, aR toCO, or aCO", (const struct ea *)( ((& __0__V256 )-> __O1__2ea.p =
# 2461 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V256 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2461 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} }

# 2464 "/home/claude/cfront-3/src/dcl3.cpp"
break ;

# 2466 "/home/claude/cfront-3/src/dcl3.cpp"
case 213 :
# 2467 "/home/claude/cfront-3/src/dcl3.cpp"
case 23 :
# 2468 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_virtual__3fct )
# 2469 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2469 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V257 ;

# 2469 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"virtual%n (operator new() is static)", (const struct ea *)( ((& __0__V257 )-> __O1__2ea.p =
# 2469 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V257 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2469 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} if (__1class_name )
# 2471 "/home/claude/cfront-3/src/dcl3.cpp"
__1f -> f_static__3fct = 1 ;
if (__1f -> nargs_known__3fct != 1 )
# 2473 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2473 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V258 ;

# 2473 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"ATs must be fully specified for%n", (const struct ea *)( ((& __0__V258 )-> __O1__2ea.p =
# 2473 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V258 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2473 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else if (__1f -> nargs__3fct < 1 )
# 2475 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2475 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V259 ;

# 2475 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n requires a firstA ofT size_t", (const struct ea *)( ((& __0__V259 )-> __O1__2ea.p =
# 2475 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V259 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2475 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else if (size_t_check__FP4type ( __1f -> argtype__3fct -> __O1__4expr.tp ) ){ 
# 2477 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2477 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V260 ;

# 2477 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n requires a firstA ofT size_t", (const struct ea *)( ((& __0__V260 )-> __O1__2ea.p =
# 2477 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V260 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2477 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
__1f -> argtype__3fct -> __O1__4expr.tp = size_t_type ;
if (__1f -> f_signature__3fct )
# 2480 "/home/claude/cfront-3/src/dcl3.cpp"
sign__3fctFv ( __1f ) ;
} }
else { 
# 2483 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __3t ;

# 2483 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = (__1f -> s_returns__3fct ?__1f -> s_returns__3fct :__1f -> returns__3fct );
if (check__4typeFP4typeUcT2 ( __3t , Pvoid_type , (unsigned char )0 , (unsigned char )0 ) )
# 2485 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2485 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V261 ;

# 2485 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad returnT for%n", (const struct ea *)( ((& __0__V261 )-> __O1__2ea.p =
# 2485 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V261 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2485 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} }
break ;

# 2489 "/home/claude/cfront-3/src/dcl3.cpp"
case 212 :
# 2491 "/home/claude/cfront-3/src/dcl3.cpp"
case 9 :
# 2493 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_virtual__3fct )
# 2494 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2494 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V262 ;

# 2494 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"virtual%n (operator delete() is static)", (const struct ea *)( ((& __0__V262 )-> __O1__2ea.p =
# 2494 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V262 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2494 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} 
# 2496 "/home/claude/cfront-3/src/dcl3.cpp"
;
if (__1class_name ){ 
# 2498 "/home/claude/cfront-3/src/dcl3.cpp"
__1f -> f_static__3fct = 1 ;
__2cl = (((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))));
if (in_class_dcl && look__5tableFPCcUc ( __2cl -> memtbl__8classdef , (const char *)"__dl", (unsigned char
# 2500 "/home/claude/cfront-3/src/dcl3.cpp"
)0 ) )
# 2504 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"operator delete() cannot be overloaded") ;
}

# 2507 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> nargs_known__3fct != 1 )
# 2508 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2508 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V263 ;

# 2508 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"ATs must be fully specified for%n", (const struct ea *)( ((& __0__V263 )-> __O1__2ea.p =
# 2508 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V263 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2508 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else { 
# 2510 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __3t ;

# 2510 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = (__1f -> s_returns__3fct ?__1f -> s_returns__3fct :__1f -> returns__3fct );
if (check__4typeFP4typeUcT2 ( __3t , (struct type *)void_type , (unsigned char )0 , (unsigned char )0 ) )
# 2512 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2512 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V264 ;
# 2512 "/home/claude/cfront-3/src/dcl3.cpp"

# 2512 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad returnT for%n", (const struct ea *)( ((& __0__V264 )-> __O1__2ea.p =
# 2512 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V264 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2512 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else { 
# 2514 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1f -> nargs__3fct ){ 
# 2515 "/home/claude/cfront-3/src/dcl3.cpp"
default :
# 2516 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2516 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V265 ;

# 2516 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n takes 1 or 2As", (const struct ea *)( ((& __0__V265 )-> __O1__2ea.p =
# 2516 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V265 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2516 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
break ;
case 1 :
# 2519 "/home/claude/cfront-3/src/dcl3.cpp"
case 2 :
# 2520 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2521 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __6a ;

# 2521 "/home/claude/cfront-3/src/dcl3.cpp"
__6a = __1f -> argtype__3fct ;
if (check__4typeFP4typeUcT2 ( __6a -> __O1__4expr.tp , Pvoid_type , (unsigned char )0 , (unsigned char )0 ) )
# 2523 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2523 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V266 ;
# 2523 "/home/claude/cfront-3/src/dcl3.cpp"

# 2523 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n's 1stA must be a void*", (const struct ea *)( ((& __0__V266 )-> __O1__2ea.p =
# 2523 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V266 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2523 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else if (__6a = __6a -> __O1__4name.n_list ){ 
# 2525 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1class_name == 0 )&& (__0this -> n_oper__4name != 212 ))
# 2526 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2526 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V267 ;
# 2526 "/home/claude/cfront-3/src/dcl3.cpp"

# 2526 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n takes only oneA", (const struct ea *)( ((& __0__V267 )-> __O1__2ea.p =
# 2526 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V267 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2526 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else if (check__4typeFP4typeUcT2 ( __6a -> __O1__4expr.tp , size_t_type , (unsigned char )0 , (unsigned char )0 ) ){
# 2527 "/home/claude/cfront-3/src/dcl3.cpp"

# 2528 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2528 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V268 ;

# 2528 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n's 2ndA must be a size_t", (const struct ea *)( ((& __0__V268 )-> __O1__2ea.p =
# 2528 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V268 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2528 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
__6a -> __O1__4expr.tp = size_t_type ;
if (__1f -> f_signature__3fct )
# 2531 "/home/claude/cfront-3/src/dcl3.cpp"
sign__3fctFv ( __1f ) ;
} }
}
}
} }
}
}
break ;

# 2540 "/home/claude/cfront-3/src/dcl3.cpp"
case 70 :
# 2541 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1class_name && (__1f -> nargs__3fct == 1 )){ 
# 2542 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __3t ;
Pname __3an ;

# 2542 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = __1f -> argtype__3fct -> __O1__4expr.tp ;
__3an = is_cl_obj__4typeFv ( __3t ) ;
if ((__3an == 0 )&& (__3t = (struct type *)is_ref__4typeFv ( __3t ) )){ 
# 2545 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = (((struct ptr *)(((struct ptr *)__3t ))))-> typ__5pvtyp ;
rx1 :
# 2547 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__3t -> base__4node ){ 
# 2548 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 2549 "/home/claude/cfront-3/src/dcl3.cpp"
if (warning_opt && ((((struct basetype *)(((struct basetype *)__3t ))))-> b_const__4type == 0 ))
# 2550 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2550 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V269 ;

# 2550 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V270 ;

# 2550 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"assignment operators should take a const %t& not a %t&", (const struct ea *)( ((&
# 2550 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V269 )-> __O1__2ea.p = ((const void *)__3t )), (& __0__V269 )) , (const struct ea *)( ((& __0__V270 )-> __O1__2ea.p =
# 2550 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__3t )), (& __0__V270 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __3t = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto rx1 ;
case 119 :
# 2554 "/home/claude/cfront-3/src/dcl3.cpp"
__3an = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype ;
}
}
if (__3an && (__3an == __1class_name ))
# 2558 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct classdef *)(((struct classdef *)__3an -> __O1__4expr.tp ))))-> c_xref__8classdef |= 4;
}
else if (__1f -> nargs__3fct == 2 ){ 
# 2561 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __3t ;
Pname __3an1 ;

# 2561 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = __1f -> argtype__3fct -> __O1__4expr.tp ;

# 2563 "/home/claude/cfront-3/src/dcl3.cpp"
if (__3t = (struct type *)is_ref__4typeFv ( __3t ) ){ 
# 2564 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = (((struct ptr *)(((struct ptr *)__3t ))))-> typ__5pvtyp ;
rx2 :
# 2566 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__3t -> base__4node ){ 
# 2567 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 2568 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto rx2 ;
case 119 :
# 2571 "/home/claude/cfront-3/src/dcl3.cpp"
__3an1 = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype ;
}
}
__3t = __1f -> argtype__3fct -> __O1__4name.n_list -> __O1__4expr.tp ;
{ Pname __3an2 ;

# 2575 "/home/claude/cfront-3/src/dcl3.cpp"
__3an2 = is_cl_obj__4typeFv ( __3t ) ;
if ((__3an2 == 0 )&& (__3t = (struct type *)is_ref__4typeFv ( __3t ) )){ 
# 2577 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = (((struct ptr *)(((struct ptr *)__3t ))))-> typ__5pvtyp ;
rx3 :
# 2579 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__3t -> base__4node ){ 
# 2580 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 2581 "/home/claude/cfront-3/src/dcl3.cpp"
__3t = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto rx3 ;
case 119 :
# 2584 "/home/claude/cfront-3/src/dcl3.cpp"
__3an2 = (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype ;
}
}
if (__3an1 && (__3an1 == __3an2 ))
# 2588 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct classdef *)(((struct classdef *)__3an1 -> __O1__4expr.tp ))))-> c_xref__8classdef |= 4;

# 2588 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
}

# 2592 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1scope ){ 
# 2593 "/home/claude/cfront-3/src/dcl3.cpp"
case 108 :
# 2594 "/home/claude/cfront-3/src/dcl3.cpp"
case 136 :
# 2595 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> n_sto__4name == 31 )
# 2596 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"D of staticF in aF")
# 2596 "/home/claude/cfront-3/src/dcl3.cpp"
;
else { 
# 2598 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __3nx ;

# 2598 "/home/claude/cfront-3/src/dcl3.cpp"
__3nx = look__5tableFPCcUc ( gtbl , __0this -> __O2__4expr.string , (unsigned char )0 ) ;
if (__3nx ){ 
# 2600 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__3nx -> __O1__4expr.tp -> base__4node ){ 
# 2601 "/home/claude/cfront-3/src/dcl3.cpp"
case 108 :
# 2602 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( __0this -> __O1__4expr.tp , __3nx -> __O1__4expr.tp , (unsigned
# 2602 "/home/claude/cfront-3/src/dcl3.cpp"
char )0 , (unsigned char )0 ) && (__0this -> n_sto__4name != 14 ))
# 2603 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2603 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V271 ;

# 2603 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V272 ;

# 2603 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%n has been locally re-declared as%t", (const struct ea *)( ((&
# 2603 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V271 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V271 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V272 , (const
# 2603 "/home/claude/cfront-3/src/dcl3.cpp"
void *)__0this -> __O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 2605 "/home/claude/cfront-3/src/dcl3.cpp"
if ((((struct fct *)(((struct fct *)__3nx -> __O1__4expr.tp ))))-> f_signature__3fct == 0 )
# 2606 "/home/claude/cfront-3/src/dcl3.cpp"
sign__3fctFv ( ((struct fct *)(((struct fct *)__3nx -> __O1__4expr.tp ))))
# 2606 "/home/claude/cfront-3/src/dcl3.cpp"
;
if ((((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_signature__3fct == 0 )
# 2608 "/home/claude/cfront-3/src/dcl3.cpp"
sign__3fctFv ( ((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp )))) ;
if ((((struct fct *)(((struct fct *)__3nx -> __O1__4expr.tp ))))-> f_linkage__3fct != (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_linkage__3fct )
# 2610 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2610 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V273 ;

# 2610 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V274 ;

# 2610 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%n of type %t has been locally re-declared with different linkage", (const struct ea *)( ((&
# 2610 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V273 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V273 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V274 , (const
# 2610 "/home/claude/cfront-3/src/dcl3.cpp"
void *)__0this -> __O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
break ;
case 76 :
# 2614 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2615 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __6ny ;

# 2615 "/home/claude/cfront-3/src/dcl3.cpp"
__6ny = find__3genFP3fctUc ( ((struct gen *)(((struct gen *)__3nx -> __O1__4expr.tp ))), __1f , (unsigned char )0 ) ;
if (__6ny == 0 )
# 2617 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2617 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V275 ;

# 2617 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V276 ;

# 2617 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"overloadedF%n has been locally declared as%t", (const struct ea *)( ((&
# 2617 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V275 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V275 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V276 , (const
# 2617 "/home/claude/cfront-3/src/dcl3.cpp"
void *)__0this -> __O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 2619 "/home/claude/cfront-3/src/dcl3.cpp"
if ((((struct fct *)(((struct fct *)__6ny -> __O1__4expr.tp ))))-> f_signature__3fct == 0 )
# 2620 "/home/claude/cfront-3/src/dcl3.cpp"
sign__3fctFv ( ((struct fct *)(((struct fct *)__6ny -> __O1__4expr.tp ))))
# 2620 "/home/claude/cfront-3/src/dcl3.cpp"
;
if ((((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_signature__3fct == 0 )
# 2622 "/home/claude/cfront-3/src/dcl3.cpp"
sign__3fctFv ( ((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp )))) ;
if ((((struct fct *)(((struct fct *)__6ny -> __O1__4expr.tp ))))-> f_linkage__3fct != (((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp ))))-> f_linkage__3fct )
# 2624 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2624 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V277 ;

# 2624 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V278 ;

# 2624 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"overloadedF%n of type %t has been locally re-declared with different linkage", (const struct ea *)( ((&
# 2624 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V277 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V277 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V278 , (const
# 2624 "/home/claude/cfront-3/src/dcl3.cpp"
void *)__0this -> __O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}
break ;
}
}
}
}

# 2633 "/home/claude/cfront-3/src/dcl3.cpp"
{ Pname __1nn ;
if (__0this -> n_sto__4name == 14 ){ 
# 2635 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn = insert__5tableFP4nameUc ( gtbl , __0this , (unsigned char )0 ) ;
__1nn -> lex_level__4name = 0 ;
}
else 
# 2637 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn = insert__5tableFP4nameUc ( __1etbl , __0this , (unsigned char )0 ) ;
if (__1f -> body__3fct )
# 2639 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn -> where__4name = __0this -> where__4name ;
assign__4nameFv ( __1nn ) ;
if (__1nn -> __O1__4expr.tp -> base__4node == 108 ){ 
# 2642 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __2nnf ;

# 2642 "/home/claude/cfront-3/src/dcl3.cpp"
__2nnf = (((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))));
if (__2nnf -> f_this__3fct )
# 2644 "/home/claude/cfront-3/src/dcl3.cpp"
__2nnf -> f_this__3fct -> where__4name = __0this -> where__4name ;
}
__0this -> __O4__4expr.n_table = __1etbl ;

# 2648 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> __O3__4expr.n_initializer ){ 
# 2649 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_virtual__3fct == 0 )
# 2650 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2650 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V279 ;

# 2650 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"Ir for non-virtualF%n", (const struct ea *)( ((& __0__V279 )-> __O1__2ea.p =
# 2650 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V279 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2650 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} if (__0this -> __O3__4expr.n_initializer != zero )
# 2652 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"virtualFIr must be 0") ;
}

# 2655 "/home/claude/cfront-3/src/dcl3.cpp"
if (Nold && (__1f -> fct_base__3fct != 4)){ 
# 2656 "/home/claude/cfront-3/src/dcl3.cpp"
Pfct __2nf ;

# 2656 "/home/claude/cfront-3/src/dcl3.cpp"
__2nf = (((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))));

# 2658 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__2nf -> base__4node == 141 )|| (__1f -> base__4node == 141 ))
# 2659 "/home/claude/cfront-3/src/dcl3.cpp"
;
else 
# 2661 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2nf -> base__4node == 76 ){ 
# 2662 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> __O2__4expr.string = __1nn -> __O2__4expr.string ;
__1nn = add__3genFP4name ( ((struct gen *)(((struct gen *)__2nf ))), __0this ) ;
__1nn -> where__4name = __0this -> where__4name ;
if ((((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> f_this__3fct != 0 )
# 2666 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> f_this__3fct -> where__4name = __0this -> where__4name ;
# 2666 "/home/claude/cfront-3/src/dcl3.cpp"

# 2668 "/home/claude/cfront-3/src/dcl3.cpp"
if (Nold == 0 ){ 
# 2669 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> body__3fct && __0this -> __O2__4name.n_qualifier ){ 
# 2670 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2670 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V280 ;

# 2670 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badAL for%n", (const struct ea *)( ((& __0__V280 )-> __O1__2ea.p =
# 2670 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V280 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2670 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
return (struct name *)0 ;
} }
goto thth ;
}
__2nf = (((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))));
if (__1f -> body__3fct && __2nf -> body__3fct ){ 
# 2680 "/home/claude/cfront-3/src/dcl3.cpp"
if (((__1class_name == 0 )|| ((((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))))-> class_base__8classdef != 4))||
# 2680 "/home/claude/cfront-3/src/dcl3.cpp"
(__1nn -> n_redefined__4name == 0 ))
# 2686 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2687 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2687 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V281 ;

# 2687 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"two definitions of%n", (const struct ea *)( ((& __0__V281 )-> __O1__2ea.p =
# 2687 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V281 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2687 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
__1f -> body__3fct = 0 ;
} }
return (struct name *)0 ;
}
if (__1f -> body__3fct )
# 2693 "/home/claude/cfront-3/src/dcl3.cpp"
goto bdbd ;
goto stst ;
}
else if (__2nf -> base__4node != 108 ){ 
# 2697 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2697 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V282 ;

# 2697 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V283 ;

# 2697 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n declared both as%t and asF", (const struct ea *)( ((& __0__V282 )-> __O1__2ea.p =
# 2697 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V282 )) , (const struct ea *)( ((& __0__V283 )-> __O1__2ea.p = ((const void
# 2697 "/home/claude/cfront-3/src/dcl3.cpp"
*)__2nf )), (& __0__V283 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1f -> body__3fct = 0 ;
} }
else { 
# 2701 "/home/claude/cfront-3/src/dcl3.cpp"
{ TOK __4t ;

# 2712 "/home/claude/cfront-3/src/dcl3.cpp"
bit __4both_templs ;
bit __4sp_templ ;

# 2701 "/home/claude/cfront-3/src/dcl3.cpp"
__4t = (((__2nf -> fct_base__3fct == 1)|| (__1f -> fct_base__3fct == 1))?204 :76 );

# 2712 "/home/claude/cfront-3/src/dcl3.cpp"
__4both_templs = (__2nf -> fct_base__3fct && __1f -> fct_base__3fct );
__4sp_templ = (__4both_templs ?0 :(__2nf -> fct_base__3fct + __1f -> fct_base__3fct ));

# 2718 "/home/claude/cfront-3/src/dcl3.cpp"
if (check__4typeFP4typeUcT2 ( (struct type *)__2nf , (struct type *)__1f , __4t , (unsigned char )0 ) || __4sp_templ ){ 
# 2719 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f ->
# 2719 "/home/claude/cfront-3/src/dcl3.cpp"
body__3fct && __0this -> __O2__4name.n_qualifier ){ 
# 2720 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2720 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V284 ;

# 2720 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V285 ;

# 2720 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V286 ;

# 2720 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%nT mismatch: %a and %a", (const struct ea *)( ((& __0__V284 )-> __O1__2ea.p =
# 2720 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V284 )) , (const struct ea *)( ((& __0__V285 )-> __O1__2ea.p = ((const void
# 2720 "/home/claude/cfront-3/src/dcl3.cpp"
*)__1nn )), (& __0__V285 )) , (const struct ea *)( ((& __0__V286 )-> __O1__2ea.p = ((const void *)__0this )), (&
# 2720 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V286 )) , (const struct ea *)ea0 ) ;
return (struct name *)0 ;
} }
if (! strcmp ( __1nn -> __O2__4expr.string , (const char *)"main") )
# 2724 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc (
# 2724 "/home/claude/cfront-3/src/dcl3.cpp"
(const char *)"cannot overload main()!") ;
{ Pgen __5g ;

# 2725 "/home/claude/cfront-3/src/dcl3.cpp"
__5g = __ct__3genFv ( (struct gen *)0 ) ;
add_first = 1 ;
{ Pname __5n1 ;

# 2727 "/home/claude/cfront-3/src/dcl3.cpp"
__5n1 = add__3genFP4name ( __5g , __1nn ) ;
add_first = 0 ;
__0this -> __O2__4expr.string = __1nn -> __O2__4expr.string ;
add_without_find = __4sp_templ ;
{ Pname __5n2 ;

# 2731 "/home/claude/cfront-3/src/dcl3.cpp"
__5n2 = add__3genFP4name ( __5g , __0this ) ;
add_without_find = 0 ;
__1nn -> __O1__4expr.tp = (struct type *)__5g ;
__1nn = __5n2 ;
goto thth ;

# 2735 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 2735 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 2735 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 2736 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 2738 "/home/claude/cfront-3/src/dcl3.cpp"
if (in_class_dcl ){ 
# 2739 "/home/claude/cfront-3/src/dcl3.cpp"
}
else if ((__2nf -> f_static__3fct && (__1f -> f_inline__3fct == 0 ))&& (__0this -> n_sto__4name == 31 )){ 
# 2742 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> n_sto__4name =
# 2742 "/home/claude/cfront-3/src/dcl3.cpp"
0 ;
}
else if (__0this -> n_sto__4name && (__0this -> n_sto__4name != __1nn -> n_scope__4name )){ 
# 2745 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__0this -> n_sto__4name == 14 )&& (__1nn -> n_scope__4name ==
# 2745 "/home/claude/cfront-3/src/dcl3.cpp"
31 ))
# 2746 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2746 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V287 ;

# 2746 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%n declared extern after being declared static", (const struct ea *)( ((&
# 2746 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V287 )-> __O1__2ea.p = ((const void *)__0this )), (& __0__V287 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2746 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} else if ((__2nf -> f_inline__3fct == 0 )&& (__1f -> f_inline__3fct == 0 )){ 
# 2747 "/home/claude/cfront-3/src/dcl3.cpp"
unsigned long __2__X314 ;

# 2748 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1nn -> __O1__4expr.tp == new_fct -> __O1__4expr.tp )|| (__1nn -> __O1__4expr.tp == del_fct -> __O1__4expr.tp ))
# 2749 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn -> n_sto__4name = __0this -> n_sto__4name ;
else 
# 2751 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2751 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V288 ;

# 2751 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V289 ;

# 2751 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V290 ;

# 2751 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n declared as both%k and%k", (const struct ea *)( ((& __0__V288 )-> __O1__2ea.p =
# 2751 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V288 )) , (const struct ea *)( (__2__X314 = __0this -> n_sto__4name ), ( ((
# 2751 "/home/claude/cfront-3/src/dcl3.cpp"
((& __0__V289 )-> __O1__2ea.i = __2__X314 ), 0 ) ), (& __0__V289 )) ) , (const struct ea *)__ct__2eaFUl ( &
# 2751 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V290 , (unsigned long )(__1nn -> n_sto__4name ?(((unsigned int )__1nn -> n_sto__4name )):(((unsigned int )14 )))) , (const struct ea *)ea0 )
# 2751 "/home/claude/cfront-3/src/dcl3.cpp"
;
} }
}

# 2758 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2759 "/home/claude/cfront-3/src/dcl3.cpp"
int __4l1 ;
int __4l2 ;

# 2759 "/home/claude/cfront-3/src/dcl3.cpp"
__4l1 = __2nf -> f_linkage__3fct ;
__4l2 = __1f -> f_linkage__3fct ;
if ((__4l2 != 0)&& (__4l1 != __4l2 ))
# 2762 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2762 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V291 ;

# 2762 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"inconsistent linkage specifications for%n", (const struct ea *)( ((& __0__V291 )-> __O1__2ea.p =
# 2762 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V291 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2762 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} }
if (__2nf -> body__3fct && __1f -> body__3fct ){ 
# 2768 "/home/claude/cfront-3/src/dcl3.cpp"
if (((__1class_name == 0 )|| ((((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))))-> class_base__8classdef !=
# 2768 "/home/claude/cfront-3/src/dcl3.cpp"
4))|| (__1nn -> n_redefined__4name == 0 ))
# 2774 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2775 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2775 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V292 ;

# 2775 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"two definitions of%n", (const struct ea *)( ((& __0__V292 )-> __O1__2ea.p =
# 2775 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V292 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2775 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
__1f -> body__3fct = 0 ;
} }
return (struct name *)0 ;
}

# 2781 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> body__3fct )
# 2782 "/home/claude/cfront-3/src/dcl3.cpp"
goto bdbd ;

# 2784 "/home/claude/cfront-3/src/dcl3.cpp"
goto stst ;

# 2786 "/home/claude/cfront-3/src/dcl3.cpp"
bdbd :
# 2788 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> nargs_known__3fct && __2nf -> nargs_known__3fct )
# 2789 "/home/claude/cfront-3/src/dcl3.cpp"
if (__0this -> n_sto__4name == 14 )
# 2790 "/home/claude/cfront-3/src/dcl3.cpp"
__2nf -> argtype__3fct = __1f -> argtype__3fct ;
else merge_init__FP4nameP3fctT2 ( __1nn , __1f , __2nf ) ;
__1f -> f_virtual__3fct = __2nf -> f_virtual__3fct ;
__1f -> f_this__3fct = __2nf -> f_this__3fct ;
__1f -> f_result__3fct = __2nf -> f_result__3fct ;
__1f -> s_returns__3fct = __2nf -> s_returns__3fct ;
__1f -> f_args__3fct = __2nf -> f_args__3fct ;
__1f -> f_signature__3fct = __2nf -> f_signature__3fct ;
__1f -> f_const__3fct = __2nf -> f_const__3fct ;
__1f -> f_static__3fct = __2nf -> f_static__3fct ;
__1nn -> __O1__4expr.tp = (struct type *)__1f ;
if (__1f -> f_inline__3fct ){ 
# 2802 "/home/claude/cfront-3/src/dcl3.cpp"
if (__2nf -> f_inline__3fct == 0 ){ 
# 2803 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1nn -> n_used__4name && (__1nn -> n_sto__4name != 31 ))
# 2804 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2804 "/home/claude/cfront-3/src/dcl3.cpp"
struct
# 2804 "/home/claude/cfront-3/src/dcl3.cpp"
ea __0__V293 ;

# 2804 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n declared with external linkage and called before defined as inline", (const struct ea *)( ((& __0__V293 )-> __O1__2ea.p =
# 2804 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V293 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2804 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else if (__1nn -> n_used__4name ){ 
# 2806 "/home/claude/cfront-3/src/dcl3.cpp"
take_addr__4nameFv ( __1nn ) ;
if (warning_opt )
# 2808 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2808 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V294 ;

# 2808 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"%n called before defined as inline", (const struct ea *)( ((&
# 2808 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V294 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V294 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2808 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 ) ;
} }
}
__2nf -> f_inline__3fct = 1 ;
__1nn -> n_sto__4name = 31 ;
}
else if (__2nf -> f_inline__3fct ){ 
# 2815 "/home/claude/cfront-3/src/dcl3.cpp"
__1f -> f_inline__3fct = 1 ;
}
goto stst2 ;

# 2819 "/home/claude/cfront-3/src/dcl3.cpp"
stst :
# 2821 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> nargs_known__3fct && __2nf -> nargs_known__3fct )
# 2822 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__0this -> n_sto__4name == 14 )|| __1f -> f_inline__3fct )
# 2823 "/home/claude/cfront-3/src/dcl3.cpp"
__2nf -> argtype__3fct = __1f -> argtype__3fct ;
else merge_init__FP4nameP3fctT2 ( __1nn , __1f , __2nf ) ;
__1f -> f_args__3fct = __2nf -> f_args__3fct ;
stst2 :
# 2828 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_inline__3fct )
# 2829 "/home/claude/cfront-3/src/dcl3.cpp"
__0this -> n_sto__4name = 31 ;
if (((__0this -> n_sto__4name == 31 )&& (__1nn -> n_sto__4name == 14 ))&& ((strcmp ( __0this -> __O2__4expr.string , (const char *)"__nw")
# 2830 "/home/claude/cfront-3/src/dcl3.cpp"
== 0 )|| (strcmp ( __0this -> __O2__4expr.string , (const char *)"__dl") == 0 )))
# 2841 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn ->
# 2841 "/home/claude/cfront-3/src/dcl3.cpp"
n_sto__4name = 31 ;
__0this -> n_scope__4name = __1nn -> n_scope__4name ;
__0this -> n_sto__4name = __1nn -> n_sto__4name ;
}
}
else { 
# 2847 "/home/claude/cfront-3/src/dcl3.cpp"
thth :
# 2848 "/home/claude/cfront-3/src/dcl3.cpp"
__1just_made = 1 ;
if (__1f -> f_inline__3fct )
# 2850 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn -> n_sto__4name = 31 ;
else if (((__1class_name == 0 )&& (__0this -> n_sto__4name == 0 ))&& (__1f -> body__3fct == 0 ))
# 2852 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn -> n_sto__4name = 14 ;

# 2854 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_static__3fct )
# 2855 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__0this -> n_oper__4name ){ 
# 2856 "/home/claude/cfront-3/src/dcl3.cpp"
case 161 :
# 2857 "/home/claude/cfront-3/src/dcl3.cpp"
case 162 :
# 2858 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 2859 "/home/claude/cfront-3/src/dcl3.cpp"
case 109 :
# 2860 "/home/claude/cfront-3/src/dcl3.cpp"
case 111 :
# 2861 "/home/claude/cfront-3/src/dcl3.cpp"
case 44 :
# 2862 "/home/claude/cfront-3/src/dcl3.cpp"
case 70 :
# 2863 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2863 "/home/claude/cfront-3/src/dcl3.cpp"
struct
# 2863 "/home/claude/cfront-3/src/dcl3.cpp"
ea __0__V295 ;

# 2863 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n cannot be a staticMF", (const struct ea *)( ((& __0__V295 )-> __O1__2ea.p =
# 2863 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V295 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2863 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
__1f -> f_static__3fct = 0 ;
} }

# 2867 "/home/claude/cfront-3/src/dcl3.cpp"
if ((((((__1class_name && (__1f -> f_static__3fct == 0 ))&& (__0this -> n_oper__4name != 23 ))&& (__0this -> n_oper__4name != 213 ))&& (__0this -> n_oper__4name !=
# 2867 "/home/claude/cfront-3/src/dcl3.cpp"
9 ))&& (__0this -> n_oper__4name != 212 ))&& (__1etbl != gtbl ))
# 2881 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2882 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __3tt ;

# 2882 "/home/claude/cfront-3/src/dcl3.cpp"
__3tt = __ct__4nameFPCc ( (struct name *)0 , (const char *)"this") ;
__3tt -> n_scope__4name = 136 ;
__3tt -> where__4name = __0this -> where__4name ;
__3tt -> __O1__4expr.tp = (((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))))-> this_type__8classdef ;
__3tt -> permanent__4node = 1 ;

# 2891 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> f_this__3fct = (__1f -> f_this__3fct = ((((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> f_args__3fct = (__1f -> f_args__3fct =
# 2891 "/home/claude/cfront-3/src/dcl3.cpp"
__3tt )));
__3tt -> __O1__4name.n_list = __1f -> argtype__3fct ;

# 2894 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_const__3fct ){ 
# 2895 "/home/claude/cfront-3/src/dcl3.cpp"
Pbase __4x ;
Pbase __4y ;

# 2895 "/home/claude/cfront-3/src/dcl3.cpp"
__4x = (((struct basetype *)(((struct basetype *)(((struct ptr *)(((struct ptr *)__3tt -> __O1__4expr.tp ))))-> typ__5pvtyp ))));
__4y = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )119 , (struct name *)0 ) ;
((*__4y ))= (*__4x );
__4y -> b_const__4type = 1 ;
__3tt -> __O1__4expr.tp = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (struct type *)__4y ) ;
(((struct ptr *)(((struct ptr *)__3tt -> __O1__4expr.tp ))))-> b_const__4type = 1 ;
__3tt -> __O1__4expr.tp -> permanent__4node = 1 ;
}
}
else { 
# 2911 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> f_args__3fct = (__1f -> f_args__3fct = (__1f -> f_result__3fct ?__1f -> f_result__3fct :__1f -> argtype__3fct ));
(((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> f_signature__3fct = __1f -> f_signature__3fct ;
(((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> f_const__3fct = __1f -> f_const__3fct ;
(((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> f_static__3fct = __1f -> f_static__3fct ;
}

# 2918 "/home/claude/cfront-3/src/dcl3.cpp"
if ((((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> f_signature__3fct == 0 )
# 2919 "/home/claude/cfront-3/src/dcl3.cpp"
sign__3fctFv ( ((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp )))) ;

# 2921 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_result__3fct == 0 ){ 
# 2923 "/home/claude/cfront-3/src/dcl3.cpp"
make_res__FP3fct ( __1f ) ;
}
else if (__1f -> f_this__3fct )
# 2926 "/home/claude/cfront-3/src/dcl3.cpp"
__1f -> f_this__3fct -> __O1__4name.n_list = __1f -> f_result__3fct ;

# 2928 "/home/claude/cfront-3/src/dcl3.cpp"
if ((__1nn -> n_oper__4name == 161 )|| (__1nn -> n_oper__4name == 162 ))
# 2929 "/home/claude/cfront-3/src/dcl3.cpp"
vbase_pointers__FP4nameP8classdef ( __1nn , ((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp )))) ;

# 2931 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> f_virtual__3fct ){ 
# 2932 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1nn -> n_scope__4name ){ 
# 2933 "/home/claude/cfront-3/src/dcl3.cpp"
default :
# 2934 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2934 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V296 ;

# 2934 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"nonC virtual%n", (const struct ea *)( ((& __0__V296 )-> __O1__2ea.p =
# 2934 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V296 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2934 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
break ;
case 0 :
# 2937 "/home/claude/cfront-3/src/dcl3.cpp"
case 25 :
# 2938 "/home/claude/cfront-3/src/dcl3.cpp"
cc -> cot__11dcl_context -> virt_count__8classdef = 1 ;
(((struct fct *)(((struct fct *)__1nn -> __O1__4expr.tp ))))-> f_virtual__3fct = __1f -> f_virtual__3fct ;
break ;
} }
}
}

# 2948 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1just_made )
# 2949 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__0this -> n_oper__4name ){ 
# 2950 "/home/claude/cfront-3/src/dcl3.cpp"
case 161 :
# 2951 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__1f -> nargs__3fct ){ 
# 2952 "/home/claude/cfront-3/src/dcl3.cpp"
case 0 :
# 2953 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
default :
# 2955 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2956 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __4n2 ;

# 2956 "/home/claude/cfront-3/src/dcl3.cpp"
__4n2 = __1f -> argtype__3fct -> __O1__4name.n_list ;
if ((__4n2 -> __O3__4expr.n_initializer == 0 )&& (__4n2 -> n_evaluated__4name == 0 ))
# 2958 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
}
case 1 :
# 2961 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2962 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __4t ;

# 2962 "/home/claude/cfront-3/src/dcl3.cpp"
__4t = __1f -> argtype__3fct -> __O1__4expr.tp ;
clll :
# 2964 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__4t -> base__4node ){ 
# 2965 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 2966 "/home/claude/cfront-3/src/dcl3.cpp"
__4t = (((struct basetype *)(((struct basetype *)__4t ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto clll ;
case 158 :
# 2969 "/home/claude/cfront-3/src/dcl3.cpp"
__4t = (((struct ptr *)(((struct ptr *)__4t ))))-> typ__5pvtyp ;
cxll :
# 2971 "/home/claude/cfront-3/src/dcl3.cpp"
switch (__4t -> base__4node ){ 
# 2972 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 2973 "/home/claude/cfront-3/src/dcl3.cpp"
if (warning_opt && ((((struct basetype *)(((struct basetype *)__4t ))))-> b_const__4type == 0 ))
# 2974 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2974 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V297 ;

# 2974 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V298 ;

# 2974 "/home/claude/cfront-3/src/dcl3.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"copy constructors should take a const %t& not a %t&", (const struct ea *)( ((&
# 2974 "/home/claude/cfront-3/src/dcl3.cpp"
__0__V297 )-> __O1__2ea.p = ((const void *)__4t )), (& __0__V297 )) , (const struct ea *)( ((& __0__V298 )-> __O1__2ea.p =
# 2974 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__4t )), (& __0__V298 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __4t = (((struct basetype *)(((struct basetype *)__4t ))))-> b_name__8basetype -> __O1__4expr.tp ;
goto cxll ;
case 119 :
# 2978 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1class_name == (((struct basetype *)(((struct basetype *)__4t ))))-> b_name__8basetype )
# 2979 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))))-> c_itor__8classdef = __1nn ;
}
break ;
case 119 :
# 2983 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1class_name == (((struct basetype *)(((struct basetype *)__4t ))))-> b_name__8basetype ){ 
# 2983 "/home/claude/cfront-3/src/dcl3.cpp"
const void *__2__X315 ;

# 2984 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 2984 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V299 ;

# 2984 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V300 ;

# 2984 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V301 ;

# 2984 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V302 ;

# 2984 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"badK %s(%s) use %s(%s&)", (const struct ea *)( (__2__X315 = (const void
# 2984 "/home/claude/cfront-3/src/dcl3.cpp"
*)__1class_name -> __O2__4expr.string ), ( ((& __0__V299 )-> __O1__2ea.p = __2__X315 ), (& __0__V299 )) ) , (const struct ea *)__ct__2eaFPCv (
# 2984 "/home/claude/cfront-3/src/dcl3.cpp"
& __0__V300 , (const void *)__1class_name -> __O2__4expr.string ) , (const struct ea *)__ct__2eaFPCv ( & __0__V301 , (const void
# 2984 "/home/claude/cfront-3/src/dcl3.cpp"
*)__1class_name -> __O2__4expr.string ) , (const struct ea *)__ct__2eaFPCv ( & __0__V302 , (const void *)__1class_name -> __O2__4expr.string ) ) ;
# 2984 "/home/claude/cfront-3/src/dcl3.cpp"

# 2985 "/home/claude/cfront-3/src/dcl3.cpp"
__1f -> argtype__3fct -> __O1__4expr.tp = (struct type *)any_type ;
} }
}
}
}
if ((((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))))-> c_ctor__8classdef == 0 )
# 2991 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))))-> c_ctor__8classdef = __1nn ;
break ;

# 2994 "/home/claude/cfront-3/src/dcl3.cpp"
case 97 :
# 2997 "/home/claude/cfront-3/src/dcl3.cpp"
__1nn -> __O1__4name.n_list = (((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))))-> conv__8classdef ;
(((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))))-> conv__8classdef = __1nn ;
break ;

# 3001 "/home/claude/cfront-3/src/dcl3.cpp"
case 162 :
# 3002 "/home/claude/cfront-3/src/dcl3.cpp"
(((struct classdef *)(((struct classdef *)__1class_name -> __O1__4expr.tp ))))-> c_dtor__8classdef = __1nn ;
break ;

# 3005 "/home/claude/cfront-3/src/dcl3.cpp"
case 23 :
# 3006 "/home/claude/cfront-3/src/dcl3.cpp"
case 213 :
# 3007 "/home/claude/cfront-3/src/dcl3.cpp"
case 9 :
# 3008 "/home/claude/cfront-3/src/dcl3.cpp"
case 212 :
# 3009 "/home/claude/cfront-3/src/dcl3.cpp"
case 109 :
# 3010 "/home/claude/cfront-3/src/dcl3.cpp"
case 0 :
# 3011 "/home/claude/cfront-3/src/dcl3.cpp"
break ;

# 3013 "/home/claude/cfront-3/src/dcl3.cpp"
default :
# 3014 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 3015 "/home/claude/cfront-3/src/dcl3.cpp"
Pname __3a ;

# 3015 "/home/claude/cfront-3/src/dcl3.cpp"
__3a = __1f -> argtype__3fct ;
for(;__3a ;__3a = __3a -> __O1__4name.n_list ) { 
# 3017 "/home/claude/cfront-3/src/dcl3.cpp"
if (__3a -> __O3__4expr.n_initializer )
# 3018 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 3018 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V303 ;

# 3018 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n: operatorFs cannot take defaultA", (const struct ea *)( ((& __0__V303 )-> __O1__2ea.p =
# 3018 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__0this )), (& __0__V303 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 3018 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} }

# 3021 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> nargs_known__3fct != 1 ){ 
# 3022 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 3022 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V304 ;

# 3022 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"ATs must be fully specified for%n", (const struct ea *)( ((& __0__V304 )-> __O1__2ea.p =
# 3022 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V304 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 3022 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} }
if (__1class_name == 0 ){ 
# 3025 "/home/claude/cfront-3/src/dcl3.cpp"
__3a = __1f -> argtype__3fct ;
__3a = __1f -> argtype__3fct ;
for(;__3a ;__3a = __3a -> __O1__4name.n_list ) { 
# 3028 "/home/claude/cfront-3/src/dcl3.cpp"
Ptype __5tx ;

# 3028 "/home/claude/cfront-3/src/dcl3.cpp"
__5tx = skiptypedefs__4typeFv ( __3a -> __O1__4expr.tp ) ;
if (is_ref__4typeFv ( __5tx ) )
# 3030 "/home/claude/cfront-3/src/dcl3.cpp"
__5tx = (((struct ptr *)(((struct ptr *)__5tx ))))-> typ__5pvtyp ;
if (is_cl_obj__4typeFv ( __5tx ) )
# 3032 "/home/claude/cfront-3/src/dcl3.cpp"
break ;
}
if (! __3a )
# 3035 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 3035 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V305 ;

# 3035 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n must take at least oneCTA", (const struct ea *)( ((& __0__V305 )-> __O1__2ea.p =
# 3035 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V305 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 3035 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} }

# 3039 "/home/claude/cfront-3/src/dcl3.cpp"
{ bit __3memberonly ;

# 3039 "/home/claude/cfront-3/src/dcl3.cpp"
__3memberonly = 0 ;
switch (__0this -> n_oper__4name ){ 
# 3041 "/home/claude/cfront-3/src/dcl3.cpp"
case 47 :
# 3042 "/home/claude/cfront-3/src/dcl3.cpp"
case 46 :
# 3043 "/home/claude/cfront-3/src/dcl3.cpp"
if (((! __1class_name )&& (__1f -> nargs__3fct == 1 ))|| __1class_name )
# 3044 "/home/claude/cfront-3/src/dcl3.cpp"
;
else 
# 3046 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 3046 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V306 ;

# 3046 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n takes 1A", (const struct ea *)( ((& __0__V306 )-> __O1__2ea.p =
# 3046 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1nn )), (& __0__V306 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 3046 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} break ;
case 111 :
# 3049 "/home/claude/cfront-3/src/dcl3.cpp"
case 70 :
# 3050 "/home/claude/cfront-3/src/dcl3.cpp"
__3memberonly = 1 ;
case 180 :
# 3052 "/home/claude/cfront-3/src/dcl3.cpp"
case 173 :
# 3053 "/home/claude/cfront-3/src/dcl3.cpp"
case 51 :
# 3054 "/home/claude/cfront-3/src/dcl3.cpp"
case 53 :
# 3055 "/home/claude/cfront-3/src/dcl3.cpp"
case 56 :
# 3056 "/home/claude/cfront-3/src/dcl3.cpp"
case 57 :
# 3057 "/home/claude/cfront-3/src/dcl3.cpp"
case 58 :
# 3058 "/home/claude/cfront-3/src/dcl3.cpp"
case 59 :
# 3059 "/home/claude/cfront-3/src/dcl3.cpp"
case 60 :
# 3060 "/home/claude/cfront-3/src/dcl3.cpp"
case 61 :
# 3061 "/home/claude/cfront-3/src/dcl3.cpp"
case 62 :
# 3062 "/home/claude/cfront-3/src/dcl3.cpp"
case 63 :
# 3063 "/home/claude/cfront-3/src/dcl3.cpp"
case 64 :
# 3064 "/home/claude/cfront-3/src/dcl3.cpp"
case
# 3064 "/home/claude/cfront-3/src/dcl3.cpp"
65 :
# 3065 "/home/claude/cfront-3/src/dcl3.cpp"
case 66 :
# 3066 "/home/claude/cfront-3/src/dcl3.cpp"
case 67 :
# 3067 "/home/claude/cfront-3/src/dcl3.cpp"
case 126 :
# 3068 "/home/claude/cfront-3/src/dcl3.cpp"
case 127 :
# 3069 "/home/claude/cfront-3/src/dcl3.cpp"
case 128 :
# 3070 "/home/claude/cfront-3/src/dcl3.cpp"
case 129 :
# 3071 "/home/claude/cfront-3/src/dcl3.cpp"
case 130 :
# 3072 "/home/claude/cfront-3/src/dcl3.cpp"
case 131 :
# 3073 "/home/claude/cfront-3/src/dcl3.cpp"
case 132 :
# 3074 "/home/claude/cfront-3/src/dcl3.cpp"
case 133 :
# 3075 "/home/claude/cfront-3/src/dcl3.cpp"
case 134 :
# 3076 "/home/claude/cfront-3/src/dcl3.cpp"
case 135 :
# 3077 "/home/claude/cfront-3/src/dcl3.cpp"
case 71 :
# 3078 "/home/claude/cfront-3/src/dcl3.cpp"
if
# 3078 "/home/claude/cfront-3/src/dcl3.cpp"
(((! __1class_name )&& (__3memberonly || (__1f -> nargs__3fct == 2 )))|| (__1class_name && (__1f -> nargs__3fct == 1 )))
# 3079 "/home/claude/cfront-3/src/dcl3.cpp"
;
else 
# 3081 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 3081 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V307 ;

# 3081 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)(__1class_name ?"%n takes 1A":(((char *)"%n takes 2As"))), (const
# 3081 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V307 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V307 )) , (const struct ea *)ea0 ,
# 3081 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} break ;

# 3084 "/home/claude/cfront-3/src/dcl3.cpp"
case 50 :
# 3085 "/home/claude/cfront-3/src/dcl3.cpp"
case 52 :
# 3086 "/home/claude/cfront-3/src/dcl3.cpp"
case 54 :
# 3087 "/home/claude/cfront-3/src/dcl3.cpp"
case 55 :
# 3088 "/home/claude/cfront-3/src/dcl3.cpp"
case 48 :
# 3089 "/home/claude/cfront-3/src/dcl3.cpp"
case 49 :
# 3090 "/home/claude/cfront-3/src/dcl3.cpp"
if (((! __1class_name )&& ((__1f -> nargs__3fct == 1 )|| (__1f -> nargs__3fct ==
# 3090 "/home/claude/cfront-3/src/dcl3.cpp"
2 )))|| (__1class_name && (__1f -> nargs__3fct <= 1 )))
# 3091 "/home/claude/cfront-3/src/dcl3.cpp"
;
else 
# 3093 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 3093 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V308 ;

# 3093 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)(__1class_name ?"%n takes 0 or 1A":(((char *)"%n takes 1 or 2As"))), (const
# 3093 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea *)( ((& __0__V308 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V308 )) , (const struct ea *)ea0 ,
# 3093 "/home/claude/cfront-3/src/dcl3.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} break ;
}

# 3095 "/home/claude/cfront-3/src/dcl3.cpp"
}
}
}

# 3099 "/home/claude/cfront-3/src/dcl3.cpp"
{ int __1i ;

# 3099 "/home/claude/cfront-3/src/dcl3.cpp"
__1i = 0 ;

# 3101 "/home/claude/cfront-3/src/dcl3.cpp"
{ { Pname __1a ;

# 3101 "/home/claude/cfront-3/src/dcl3.cpp"
__1a = __1f -> f_args__3fct ;

# 3101 "/home/claude/cfront-3/src/dcl3.cpp"
for(;__1a ;__1a = __1a -> __O1__4name.n_list ) { 
# 3102 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1a -> __O3__4expr.n_initializer )
# 3103 "/home/claude/cfront-3/src/dcl3.cpp"
__1i = 1 ;
else if (__1i )
# 3105 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1a )
# 3106 "/home/claude/cfront-3/src/dcl3.cpp"
{ 
# 3106 "/home/claude/cfront-3/src/dcl3.cpp"
struct ea __0__V309 ;

# 3106 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCcRC2eaN32 ( (const char *)"trailingA%n withoutIr", (const struct ea *)( ((& __0__V309 )-> __O1__2ea.p =
# 3106 "/home/claude/cfront-3/src/dcl3.cpp"
((const void *)__1a )), (& __0__V309 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 3106 "/home/claude/cfront-3/src/dcl3.cpp"
ea *)ea0 ) ;
} else 
# 3108 "/home/claude/cfront-3/src/dcl3.cpp"
error__FPCc ( (const char *)"trailingA withoutIr") ;
}

# 3115 "/home/claude/cfront-3/src/dcl3.cpp"
if (__1f -> body__3fct )
# 3116 "/home/claude/cfront-3/src/dcl3.cpp"
dcl__3fctFP4name ( __1f , __1nn ) ;

# 3118 "/home/claude/cfront-3/src/dcl3.cpp"
in_class_dcl = __1old_in_class_dcl ;
return __1nn ;

# 3119 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 3119 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 3119 "/home/claude/cfront-3/src/dcl3.cpp"
}

# 3119 "/home/claude/cfront-3/src/dcl3.cpp"
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFUl (struct ea *__0this , 
# 76 "/home/claude/cfront-3/src/cfront.h"
size_t __2ii ){ 
# 76 "/home/claude/cfront-3/src/cfront.h"
if (__0this || (__0this = (struct ea *)__nw__FUl ( (size_t )(sizeof (struct ea)))
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

# 3120 "/home/claude/cfront-3/src/dcl3.cpp"

/* the end */
