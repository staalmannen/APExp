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

# 31 "/home/claude/cfront-3/src/tqueue.h"
void *__nw__7toknodeSFUl (size_t );
void __dl__7toknodeSFPvUl (void *, size_t );

# 35 "/home/claude/cfront-3/src/tqueue.h"
extern struct toknode *front ;

# 43 "/home/claude/cfront-3/src/tqueue.h"
extern int yychar ;
extern union YYSTYPE yylval ;

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

# 35 "/home/claude/cfront-3/src/lalex.cpp"
extern int parameters_in_progress__17templ_compilation;

# 22 "/home/claude/cfront-3/src/tqueue.h"
struct toknode {	/* sizeof toknode == 48 */
TOK tok__7toknode ;
bit used__7toknode ;
union YYSTYPE retval__7toknode ;
Pname idname__7toknode ;
struct loc place__7toknode ;
struct toknode *next__7toknode ;
struct toknode *last__7toknode ;
};

# 30 "/home/claude/cfront-3/src/tqueue.h"
extern struct toknode *free_toks__7toknode ;

# 36 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *free_toks__7toknode = 0 ;

# 108 "/home/claude/cfront-3/src/lalex.cpp"
int bl_level = 0 ;

# 116 "/home/claude/cfront-3/src/lalex.cpp"
static int lasttk = 0 ;
static union YYSTYPE lastval ;

# 119 "/home/claude/cfront-3/src/lalex.cpp"
static int must_be_expr = 0 ;
int must_be_id = 0 ;

# 122 "/home/claude/cfront-3/src/lalex.cpp"
struct loc curloc = { 0 } ;
int curr_file = 0 ;

# 125 "/home/claude/cfront-3/src/lalex.cpp"
static struct toknode *latok ;
struct toknode *front = 0 ;
static struct toknode *rear = 0 ;

# 129 "/home/claude/cfront-3/src/lalex.cpp"

# 132 "/home/claude/cfront-3/src/lalex.cpp"
void *__nw__7toknodeSFUl (size_t __1__A26 )
# 133 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 134 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__1p ;

# 136 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1p = free_toks__7toknode )== 0 ){ 
# 137 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__2q ;
free_toks__7toknode = (__2q = (((struct toknode *)(((char *)__nw__FUl ( (size_t)(768* (sizeof (char )))) )))));
__1p = free_toks__7toknode ;
for(;__2q != (& (__1p [15]));( (__2q -> next__7toknode = (__2q + 1 )), (++ __2q )) ) ;
__2q -> next__7toknode = 0 ;
}
free_toks__7toknode = __1p -> next__7toknode ;
return (void *)__1p ;
}

# 147 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__ct__7toknodeFUc7YYSTYPE3loc (register struct toknode *__0this , TOK __1t , union YYSTYPE __1r , struct loc __1tloc )
# 148 "/home/claude/cfront-3/src/lalex.cpp"
{ if (__0this || (__0this = (struct toknode *)__nw__7toknodeSFUl (
# 148 "/home/claude/cfront-3/src/lalex.cpp"
(size_t )(sizeof (struct toknode))) )){ 
# 149 "/home/claude/cfront-3/src/lalex.cpp"
__0this -> tok__7toknode = __1t ;
__0this -> used__7toknode = 0 ;
__0this -> retval__7toknode = __1r ;
__0this -> place__7toknode = __1tloc ;
__0this -> next__7toknode = (__0this -> last__7toknode = 0 );
} 
# 153 "/home/claude/cfront-3/src/lalex.cpp"
return __0this ;
}

# 157 "/home/claude/cfront-3/src/lalex.cpp"
void __dl__7toknodeSFPvUl (void *__1vp , size_t __1__A27 )
# 158 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 159 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__1p ;

# 159 "/home/claude/cfront-3/src/lalex.cpp"
__1p = (((struct toknode *)(((struct toknode *)__1vp ))));
__1p -> next__7toknode = free_toks__7toknode ;
free_toks__7toknode = __1p ;
__1vp = 0 ;
}

# 30 "/home/claude/cfront-3/src/cfront.h"
extern TOK tlex__Fv (void );

# 166 "/home/claude/cfront-3/src/lalex.cpp"
static void add_tokens__Fv (void )
# 170 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 171 "/home/claude/cfront-3/src/lalex.cpp"
TOK __1tk ;

# 171 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = tlex__Fv ( ) ;
if (__1tk != 80 )
# 173 "/home/claude/cfront-3/src/lalex.cpp"
return ;

# 175 "/home/claude/cfront-3/src/lalex.cpp"
while (((__1tk == 80 )|| (__1tk == 160 ))|| (__1tk == 45 ))
# 176 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = tlex__Fv ( ) ;
}
enum __E28 { one_back = 0, two_back = 1} ;

# 189 "/home/claude/cfront-3/src/lalex.cpp"
static TOK last_tokens [2];
static Pname last_tname ;

# 87 "/home/claude/cfront-3/src/cfront.h"
extern int error__FiP3locPCcRC2eaN34 (int , struct loc *, const char *, const struct ea *, const struct
# 87 "/home/claude/cfront-3/src/cfront.h"
ea *, const struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 1279 "/home/claude/cfront-3/src/cfront.h"

# 470 "/home/claude/cfront-3/src/template.h"

# 86 "/home/claude/cfront-3/src/cfront.h"
extern int error__FP3locPCcRC2eaN33 (struct loc *, const char *, const struct ea *, const struct ea *, const
# 86 "/home/claude/cfront-3/src/cfront.h"
struct ea *, const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 114 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_member__FPCcP8classdefUc (const char *, Pclass , TOK );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 113 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_name__FPCcP6ktableUc (const char *, Pktab , TOK );

# 157 "/home/claude/cfront-3/src/lalex.cpp"

# 34 "/home/claude/cfront-3/src/tqueue.h"

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 192 "/home/claude/cfront-3/src/lalex.cpp"
static void use_token__FP7toknode (struct toknode *__1T )
# 197 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 198 "/home/claude/cfront-3/src/lalex.cpp"
__1T -> used__7toknode = 1 ;
{ static bit __1aggr = 0 ;
if ((__1T -> tok__7toknode == 156 )|| (__1T -> tok__7toknode == 13 ))
# 201 "/home/claude/cfront-3/src/lalex.cpp"
__1aggr = 1 ;
else if ((__1T -> tok__7toknode != 160 )&& (__1T -> tok__7toknode != 80 ))
# 203 "/home/claude/cfront-3/src/lalex.cpp"
__1aggr = 0 ;

# 209 "/home/claude/cfront-3/src/lalex.cpp"
;

# 211 "/home/claude/cfront-3/src/lalex.cpp"
switch (__1T -> tok__7toknode ){ 
# 212 "/home/claude/cfront-3/src/lalex.cpp"
case 44 :case 45 :
# 213 "/home/claude/cfront-3/src/lalex.cpp"
{ struct toknode *__3t ;
Pname __3q ;

# 214 "/home/claude/cfront-3/src/lalex.cpp"
Pname __3r ;

# 213 "/home/claude/cfront-3/src/lalex.cpp"
__3t = __1T ;
__3q = 0 ;

# 214 "/home/claude/cfront-3/src/lalex.cpp"
__3r = 0 ;
for(;;) { 
# 216 "/home/claude/cfront-3/src/lalex.cpp"
if (__3t -> next__7toknode == 0 )add_tokens__Fv ( ) ;
__3t = __3t -> next__7toknode ;
if ((__3t -> tok__7toknode == 80 )&& (__3t -> next__7toknode -> tok__7toknode == 160 )){ 
# 219 "/home/claude/cfront-3/src/lalex.cpp"
Pname __5n ;

# 219 "/home/claude/cfront-3/src/lalex.cpp"
__5n = __ct__4nameFPCc ( (struct name *)0 , __3t -> retval__7toknode . s__7YYSTYPE ) ;
__5n -> base__4node = 176 ;
if (__3q == 0 )__3q = (__3r = __5n );
else { __3r -> __O1__4name.n_list = __5n ;

# 222 "/home/claude/cfront-3/src/lalex.cpp"
__3r = __5n ;

# 222 "/home/claude/cfront-3/src/lalex.cpp"
}
__3t = __3t -> next__7toknode ;
}
else 
# 224 "/home/claude/cfront-3/src/lalex.cpp"
if (__3t -> tok__7toknode == 160 ){ 
# 225 "/home/claude/cfront-3/src/lalex.cpp"
Pname __5n ;

# 225 "/home/claude/cfront-3/src/lalex.cpp"
__5n = __ct__4nameFPCc ( (struct name *)0 , (const char *)0 ) ;
__5n -> base__4node = 176 ;
if (__3q == 0 )__3q = (__3r = __5n );
else { __3r -> __O1__4name.n_list = __5n ;

# 228 "/home/claude/cfront-3/src/lalex.cpp"
__3r = __5n ;

# 228 "/home/claude/cfront-3/src/lalex.cpp"
}
}
else break ;
}
if (__3q ){ 
# 233 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__4x ;

# 233 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__4xx ;

# 233 "/home/claude/cfront-3/src/lalex.cpp"
__4x = __1T -> next__7toknode ;

# 233 "/home/claude/cfront-3/src/lalex.cpp"
__4xx = __4x -> next__7toknode ;
__4x -> tok__7toknode = 176 ;
__4x -> retval__7toknode . pn__7YYSTYPE = __3q ;
__4x -> used__7toknode = 1 ;
__4x -> next__7toknode = __3t ;
__3t -> last__7toknode -> next__7toknode = 0 ;
__3t -> last__7toknode = __4x ;
for(;__4xx ;__4xx = __4x ) { __4x = __4xx -> next__7toknode ;

# 240 "/home/claude/cfront-3/src/lalex.cpp"
( (__4xx ?(((void )(__4xx ?(((void )(((void )__dl__7toknodeSFPvUl ( (void *)__4xx , (size_t )(sizeof (struct toknode))) )))):(((void )0 ))))):(((void )0 ))))
# 240 "/home/claude/cfront-3/src/lalex.cpp"
;

# 240 "/home/claude/cfront-3/src/lalex.cpp"
}
}
break ;
}
case 80 :
# 245 "/home/claude/cfront-3/src/lalex.cpp"
if ((last_tokens [0])== 176 )break ;
{ 
# 247 "/home/claude/cfront-3/src/lalex.cpp"
Pname __3n ;
TOK __3sc ;

# 247 "/home/claude/cfront-3/src/lalex.cpp"
__3n = 0 ;
__3sc = (((__1T -> next__7toknode && (__1T -> next__7toknode -> tok__7toknode == 160 ))|| __1aggr )?159 :0 );

# 251 "/home/claude/cfront-3/src/lalex.cpp"
if (((last_tokens [0])== 160 )|| (((last_tokens [0])== 178 )&& (! in_progress__17templ_compilation ))){ 
# 252 "/home/claude/cfront-3/src/lalex.cpp"
if (((last_tokens [1])== 123 )|| (((last_tokens [1])== 60 )&& ((last_tokens [0])!= 160 ))){
# 252 "/home/claude/cfront-3/src/lalex.cpp"

# 253 "/home/claude/cfront-3/src/lalex.cpp"
if (((last_tokens [1])== 60 )&& ((last_tokens [0])== 178 ))
# 254 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 255 "/home/claude/cfront-3/src/lalex.cpp"
extern union YYSTYPE yyval ;
last_tname = yyval . pn__7YYSTYPE ;
}

# 259 "/home/claude/cfront-3/src/lalex.cpp"
{ Pname __5tn ;

# 260 "/home/claude/cfront-3/src/lalex.cpp"
const void *__2__X36 ;

# 259 "/home/claude/cfront-3/src/lalex.cpp"
__5tn = last_tname ;
if (__5tn == 0 ){ 
# 260 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V29 ;

# 260 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1T -> place__7toknode , (const char *)"last_tname not set for tname::%s", (const
# 260 "/home/claude/cfront-3/src/lalex.cpp"
struct ea *)( (__2__X36 = (const void *)__1T -> retval__7toknode . s__7YYSTYPE ), ( ((& __0__V29 )-> __O1__2ea.p = __2__X36 ), (&
# 260 "/home/claude/cfront-3/src/lalex.cpp"
__0__V29 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} while (__5tn -> __O1__4expr.tp && (__5tn -> __O1__4expr.tp -> base__4node == 97 ))
# 262 "/home/claude/cfront-3/src/lalex.cpp"
__5tn = (((struct basetype *)(((struct basetype *)__5tn -> __O1__4expr.tp ))))-> b_name__8basetype ;
if (strcmp ( __1T -> retval__7toknode . s__7YYSTYPE , __5tn -> __O2__4expr.string ) == 0 ){ 
# 265 "/home/claude/cfront-3/src/lalex.cpp"
__3n = __5tn ;
}
else 
# 266 "/home/claude/cfront-3/src/lalex.cpp"
if (__5tn -> __O1__4expr.tp && (__5tn -> __O1__4expr.tp -> base__4node == 119 )){ 
# 267 "/home/claude/cfront-3/src/lalex.cpp"
Pclass __6cl ;

# 268 "/home/claude/cfront-3/src/lalex.cpp"
int __1__Xt00admtho24vcnl ;

# 268 "/home/claude/cfront-3/src/lalex.cpp"
const void *__2__X37 ;

# 267 "/home/claude/cfront-3/src/lalex.cpp"
__6cl = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__5tn -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))));

# 269 "/home/claude/cfront-3/src/lalex.cpp"
if (( (__1__Xt00admtho24vcnl = ((((struct type *)__6cl )-> base__4node == 108 )?(((struct fct *)(((struct fct *)((struct type *)__6cl )))))-> fct_base__3fct :((((struct type *)__6cl )-> base__4node == 6 )?(((struct
# 269 "/home/claude/cfront-3/src/lalex.cpp"
classdef *)(((struct classdef *)((struct type *)__6cl )))))-> class_base__8classdef :(((int )0 ))))), (((unsigned char )((__1__Xt00admtho24vcnl == 4)|| (__1__Xt00admtho24vcnl == 5))))) && (strcmp ( __1T ->
# 269 "/home/claude/cfront-3/src/lalex.cpp"
retval__7toknode . s__7YYSTYPE , ( (((struct templ_classdef *)(((struct templ_classdef *)__6cl ))))-> inst__14templ_classdef -> def__10templ_inst -> namep__5templ ) -> __O2__4expr.string ) == 0 ))
# 273 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 274 "/home/claude/cfront-3/src/lalex.cpp"
__3n =
# 274 "/home/claude/cfront-3/src/lalex.cpp"
__5tn ;
}
else 
# 277 "/home/claude/cfront-3/src/lalex.cpp"
if ((__6cl -> defined__4type & 5)== 0 )
# 278 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 278 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V30 ;

# 278 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V31 ;

# 278 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V32 ;

# 278 "/home/claude/cfront-3/src/lalex.cpp"
error__FP3locPCcRC2eaN33 ( & __1T -> place__7toknode , (const char *)"%n:: %s -- %tU", (const struct ea *)(
# 278 "/home/claude/cfront-3/src/lalex.cpp"
(__2__X37 = (const void *)last_tname ), ( ((& __0__V30 )-> __O1__2ea.p = __2__X37 ), (& __0__V30 )) ) , (const
# 278 "/home/claude/cfront-3/src/lalex.cpp"
struct ea *)__ct__2eaFPCv ( & __0__V31 , (const void *)__1T -> retval__7toknode . s__7YYSTYPE ) , (const struct ea *)( ((&
# 278 "/home/claude/cfront-3/src/lalex.cpp"
__0__V32 )-> __O1__2ea.p = ((const void *)__6cl )), (& __0__V32 )) , (const struct ea *)ea0 ) ;
} else { 
# 280 "/home/claude/cfront-3/src/lalex.cpp"
__3n = k_find_member__FPCcP8classdefUc ( __1T -> retval__7toknode . s__7YYSTYPE , __6cl , __3sc ) ;
if (__3n && (__3n -> n_ktable__4name == Gtbl ))
# 282 "/home/claude/cfront-3/src/lalex.cpp"
__3n = 0 ;
}
}
else 
# 284 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 285 "/home/claude/cfront-3/src/lalex.cpp"
if (__5tn -> __O1__4expr.tp -> base__4node != 141 )
# 286 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 286 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V33 ;

# 286 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V34 ;

# 286 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V35 ;

# 286 "/home/claude/cfront-3/src/lalex.cpp"
error__FP3locPCcRC2eaN33 ( & __1T -> place__7toknode , (const char *)"%n:: %s --%n not aCN", (const struct ea *)(
# 286 "/home/claude/cfront-3/src/lalex.cpp"
((& __0__V33 )-> __O1__2ea.p = ((const void *)__5tn )), (& __0__V33 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V34 ,
# 286 "/home/claude/cfront-3/src/lalex.cpp"
(const void *)__1T -> retval__7toknode . s__7YYSTYPE ) , (const struct ea *)( ((& __0__V35 )-> __O1__2ea.p = ((const void
# 286 "/home/claude/cfront-3/src/lalex.cpp"
*)__5tn )), (& __0__V35 )) , (const struct ea *)ea0 ) ;
} __3n = k_find_name__FPCcP6ktableUc ( __1T -> retval__7toknode . s__7YYSTYPE , Ctbl , __3sc ) ;
}

# 288 "/home/claude/cfront-3/src/lalex.cpp"
}
}
else 
# 289 "/home/claude/cfront-3/src/lalex.cpp"
if ((last_tokens [1])!= 80 ){ 
# 291 "/home/claude/cfront-3/src/lalex.cpp"
__3n = k_find_name__FPCcP6ktableUc ( __1T -> retval__7toknode . s__7YYSTYPE , Gtbl , __3sc ) ;
}
}
else __3n = k_find_name__FPCcP6ktableUc ( __1T -> retval__7toknode . s__7YYSTYPE , Ctbl , __3sc ) ;
__1T -> idname__7toknode = __3n ;
if (__3n && (__3n -> base__4node == 123 )){ 
# 297 "/home/claude/cfront-3/src/lalex.cpp"
__1T -> tok__7toknode = 123 ;
__1T -> retval__7toknode . pn__7YYSTYPE = __3n ;
;
}

# 306 "/home/claude/cfront-3/src/lalex.cpp"
break ;
}
case 73 :++ bl_level ;

# 308 "/home/claude/cfront-3/src/lalex.cpp"
break ;
case 74 :-- bl_level ;

# 309 "/home/claude/cfront-3/src/lalex.cpp"
break ;
}

# 312 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1T -> tok__7toknode != 47 )|| ((last_tokens [0])!= 160 )){ 
# 313 "/home/claude/cfront-3/src/lalex.cpp"
(last_tokens [1])= (last_tokens [0]);
(last_tokens [0])= __1T -> tok__7toknode ;
if (__1T -> tok__7toknode == 123 )last_tname = __1T -> retval__7toknode . pn__7YYSTYPE ;
}

# 316 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 320 "/home/claude/cfront-3/src/lalex.cpp"
static void la_reset__FP7toknodeP4name (struct toknode *__1T , Pname __1qual )
# 321 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 327 "/home/claude/cfront-3/src/lalex.cpp"
(last_tokens [0])= 160 ;
(last_tokens [1])= 123 ;
last_tname = __1qual ;
while (__1T && __1T -> used__7toknode ){ 
# 331 "/home/claude/cfront-3/src/lalex.cpp"
__1T -> used__7toknode = 0 ;
switch (__1T -> tok__7toknode ){ 
# 333 "/home/claude/cfront-3/src/lalex.cpp"
case 123 :
# 334 "/home/claude/cfront-3/src/lalex.cpp"
__1T -> tok__7toknode = 80 ;
__1T -> retval__7toknode . s__7YYSTYPE = __1T -> retval__7toknode . pn__7YYSTYPE -> __O2__4expr.string ;
break ;
case 73 :-- bl_level ;

# 337 "/home/claude/cfront-3/src/lalex.cpp"
break ;
case 74 :++ bl_level ;

# 338 "/home/claude/cfront-3/src/lalex.cpp"
break ;
}
__1T = __1T -> next__7toknode ;
}
}

# 345 "/home/claude/cfront-3/src/lalex.cpp"
void addtok__FUc7YYSTYPE3loc (TOK __1t , union YYSTYPE __1r , struct loc __1tloc )
# 346 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 347 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__1T ;

# 347 "/home/claude/cfront-3/src/lalex.cpp"
__1T = __ct__7toknodeFUc7YYSTYPE3loc ( (struct toknode *)0 , __1t , __1r , __1tloc ) ;
if (front == 0 )
# 349 "/home/claude/cfront-3/src/lalex.cpp"
front = (rear = __1T );
else { 
# 351 "/home/claude/cfront-3/src/lalex.cpp"
rear -> next__7toknode = __1T ;
__1T -> last__7toknode = rear ;
rear = __1T ;
}

# 357 "/home/claude/cfront-3/src/lalex.cpp"
}

# 359 "/home/claude/cfront-3/src/lalex.cpp"
static Pname idname ;

# 157 "/home/claude/cfront-3/src/lalex.cpp"

# 34 "/home/claude/cfront-3/src/tqueue.h"

# 361 "/home/claude/cfront-3/src/lalex.cpp"
TOK deltok__Fi (int __1noset )
# 362 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 363 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__1T ;

# 363 "/home/claude/cfront-3/src/lalex.cpp"
__1T = front ;
;

# 364 "/home/claude/cfront-3/src/lalex.cpp"
if (! __1T -> used__7toknode )use_token__FP7toknode ( __1T ) ;

# 364 "/home/claude/cfront-3/src/lalex.cpp"
;
{ TOK __1tk ;

# 365 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = __1T -> tok__7toknode ;
if (! __1noset ){ yylval = __1T -> retval__7toknode ;

# 366 "/home/claude/cfront-3/src/lalex.cpp"
curloc = __1T -> place__7toknode ;

# 366 "/home/claude/cfront-3/src/lalex.cpp"
}
curr_file = curloc . file__3loc ;
if (front = front -> next__7toknode )
# 369 "/home/claude/cfront-3/src/lalex.cpp"
front -> last__7toknode = 0 ;
else 
# 371 "/home/claude/cfront-3/src/lalex.cpp"
latok = (rear = 0 );
idname = __1T -> idname__7toknode ;
( (__1T ?(((void )(__1T ?(((void )(((void )__dl__7toknodeSFPvUl ( (void *)__1T , (size_t )(sizeof (struct toknode))) )))):(((void )0 ))))):(((void )0 ))))
# 373 "/home/claude/cfront-3/src/lalex.cpp"
;
return __1tk ;

# 374 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 157 "/home/claude/cfront-3/src/lalex.cpp"

# 34 "/home/claude/cfront-3/src/tqueue.h"

# 378 "/home/claude/cfront-3/src/lalex.cpp"
static void del_tokens__FP7toknode (struct toknode *__1marker )
# 382 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 383 "/home/claude/cfront-3/src/lalex.cpp"
if (((__1marker == 0 )|| (__1marker == latok ))|| (__1marker -> next__7toknode == 0 ))
# 384 "/home/claude/cfront-3/src/lalex.cpp"
error__FiPCc ( (int )'i' ,
# 384 "/home/claude/cfront-3/src/lalex.cpp"
(const char *)"bad token queue") ;

# 386 "/home/claude/cfront-3/src/lalex.cpp"
;

# 388 "/home/claude/cfront-3/src/lalex.cpp"
{ struct toknode *__1tt ;

# 388 "/home/claude/cfront-3/src/lalex.cpp"
__1tt = __1marker -> next__7toknode ;
if (__1tt == latok )return ;
__1marker -> next__7toknode = latok ;
latok -> last__7toknode -> next__7toknode = 0 ;
latok -> last__7toknode = __1marker ;
{ struct toknode *__1tx ;

# 393 "/home/claude/cfront-3/src/lalex.cpp"
__1tx = __1tt ;
do { 
# 395 "/home/claude/cfront-3/src/lalex.cpp"
;
__1tx = __1tx -> next__7toknode ;
( (__1tt ?(((void )(__1tt ?(((void )(((void )__dl__7toknodeSFPvUl ( (void *)__1tt , (size_t )(sizeof (struct toknode))) )))):(((void )0 ))))):(((void )0 ))))
# 397 "/home/claude/cfront-3/src/lalex.cpp"
;
__1tt = __1tx ;
}
while (__1tx );

# 399 "/home/claude/cfront-3/src/lalex.cpp"
}

# 399 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 157 "/home/claude/cfront-3/src/lalex.cpp"

# 34 "/home/claude/cfront-3/src/tqueue.h"

# 403 "/home/claude/cfront-3/src/lalex.cpp"
static void del_1__FP7toknode (struct toknode *__1t )
# 405 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 406 "/home/claude/cfront-3/src/lalex.cpp"
if (__1t -> last__7toknode )__1t -> last__7toknode -> next__7toknode = __1t -> next__7toknode ;
else front = __1t -> next__7toknode ;
if (latok == __1t )latok = (__1t -> last__7toknode ?__1t -> last__7toknode :front );
if (__1t -> next__7toknode )__1t -> next__7toknode -> last__7toknode = __1t -> last__7toknode ;
else rear = __1t -> last__7toknode ;
( (__1t ?(((void )(__1t ?(((void )(((void )__dl__7toknodeSFPvUl ( (void *)__1t , (size_t )(sizeof (struct toknode))) )))):(((void )0 ))))):(((void )0 ))))
# 411 "/home/claude/cfront-3/src/lalex.cpp"
;
}

# 415 "/home/claude/cfront-3/src/lalex.cpp"
TOK la_look__Fv (void )
# 419 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 420 "/home/claude/cfront-3/src/lalex.cpp"
;
if (front == 0 )
# 422 "/home/claude/cfront-3/src/lalex.cpp"
add_tokens__Fv ( ) ;

# 424 "/home/claude/cfront-3/src/lalex.cpp"
latok = front ;
;

# 425 "/home/claude/cfront-3/src/lalex.cpp"
if (! latok -> used__7toknode )use_token__FP7toknode ( latok ) ;

# 425 "/home/claude/cfront-3/src/lalex.cpp"
;
;
return latok -> tok__7toknode ;
}

# 1256 "/home/claude/cfront-3/src/cfront.h"
extern TOK lalex__Fv (void );

# 113 "/home/claude/cfront-3/src/lalex.cpp"
static TOK lookahead__Fv (void );

# 112 "/home/claude/cfront-3/src/lalex.cpp"
static int la_decl__Fi (int );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 432 "/home/claude/cfront-3/src/lalex.cpp"
void check_decl__Fv (void )
# 437 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 438 "/home/claude/cfront-3/src/lalex.cpp"
TOK __1tk2 ;
switch ((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar ){ 
# 439 "/home/claude/cfront-3/src/lalex.cpp"
unsigned long __2__X39 ;

# 440 "/home/claude/cfront-3/src/lalex.cpp"
default :break ;
case 178 :
# 442 "/home/claude/cfront-3/src/lalex.cpp"
;
__1tk2 = la_look__Fv ( ) ;
while (__1tk2 == 178 )__1tk2 = lookahead__Fv ( ) ;
if (__1tk2 == 123 ){ 
# 446 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__3t ;

# 446 "/home/claude/cfront-3/src/lalex.cpp"
__3t = latok ;
if (__3t -> tok__7toknode != 123 )
# 448 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __3t -> place__7toknode , (const char *)"check_decl() token scan",
# 448 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1tk2 = lookahead__Fv ( ) ;
if ((__1tk2 == 40 )&& la_decl__Fi ( in_arg_list ) ){ 
# 451 "/home/claude/cfront-3/src/lalex.cpp"
__3t -> tok__7toknode = 179 ;
}
}
;
break ;
case 179 :
# 457 "/home/claude/cfront-3/src/lalex.cpp"
if (in_arg_list == 0 )break ;

# 461 "/home/claude/cfront-3/src/lalex.cpp"
yychar = DECL_TYPE ;
DECL_TYPE = 0 ;
if ((yychar != 97 )&& (yychar != 123 )){ 
# 463 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V38 ;

# 463 "/home/claude/cfront-3/src/lalex.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"check_decl() failed rescanning arg decl; yychar==%d", (const struct ea *)( (__2__X39 =
# 463 "/home/claude/cfront-3/src/lalex.cpp"
yychar ), ( (( ((& __0__V38 )-> __O1__2ea.i = __2__X39 ), 0 ) ), (& __0__V38 )) ) , (const
# 463 "/home/claude/cfront-3/src/lalex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 465 "/home/claude/cfront-3/src/lalex.cpp"
case 97 :case 123 :
# 466 "/home/claude/cfront-3/src/lalex.cpp"
;
if ((la_look__Fv ( ) == 40 )&& la_decl__Fi ( in_arg_list ) ){ 
# 468 "/home/claude/cfront-3/src/lalex.cpp"
must_be_id = 0 ;
DECL_TYPE = yychar ;
yychar = 179 ;
;
}
}
}

# 47 "/home/claude/cfront-3/src/tqueue.h"
extern int la_cast__Fv (void );

# 477 "/home/claude/cfront-3/src/lalex.cpp"
void check_cast__Fv (void )
# 482 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 483 "/home/claude/cfront-3/src/lalex.cpp"
TOK __1tk2 ;
switch ((yychar == -1)?( (yychar = lalex__Fv ( ) ), yychar ) :yychar ){ 
# 485 "/home/claude/cfront-3/src/lalex.cpp"
case 178 :
# 486 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = la_look__Fv ( ) ;
# 486 "/home/claude/cfront-3/src/lalex.cpp"

# 487 "/home/claude/cfront-3/src/lalex.cpp"
while (__1tk2 == 178 )__1tk2 = lookahead__Fv ( ) ;
if (__1tk2 == 123 ){ 
# 489 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__3t ;

# 489 "/home/claude/cfront-3/src/lalex.cpp"
__3t = latok ;
if (__3t -> tok__7toknode != 123 )
# 491 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __3t -> place__7toknode , (const char *)"check_cast() token scan",
# 491 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__1tk2 = lookahead__Fv ( ) ;
if ((__1tk2 == 40 )&& la_decl__Fi ( in_arg_list ) ){ 
# 494 "/home/claude/cfront-3/src/lalex.cpp"
__3t -> tok__7toknode = 179 ;
}
}
break ;
case 97 :case 123 :
# 499 "/home/claude/cfront-3/src/lalex.cpp"
if ((la_look__Fv ( ) == 40 )&& la_cast__Fv ( ) ){ 
# 500 "/home/claude/cfront-3/src/lalex.cpp"
must_be_id = 0 ;
DECL_TYPE = yychar ;
yychar = 179 ;
}
}
}

# 509 "/home/claude/cfront-3/src/lalex.cpp"
static int latype__FUc (TOK __1t )
# 510 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 511 "/home/claude/cfront-3/src/lalex.cpp"
switch (__1t ){ 
# 512 "/home/claude/cfront-3/src/lalex.cpp"
default :
# 513 "/home/claude/cfront-3/src/lalex.cpp"
return 0 ;
case 5 :case 29 :case 21 :case 22 :case 122 :
# 515 "/home/claude/cfront-3/src/lalex.cpp"
case 15 :case 11 :
# 516 "/home/claude/cfront-3/src/lalex.cpp"
case 37 :
# 517 "/home/claude/cfront-3/src/lalex.cpp"
return 1 ;
}
}

# 522 "/home/claude/cfront-3/src/lalex.cpp"
static int laexpr__FUc (TOK __1t )
# 523 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 524 "/home/claude/cfront-3/src/lalex.cpp"
switch (__1t ){ 
# 525 "/home/claude/cfront-3/src/lalex.cpp"
default :
# 526 "/home/claude/cfront-3/src/lalex.cpp"
return 0 ;
case 28 :case 23 :case 52 :case 66 :case 65 :case 67 :
# 528 "/home/claude/cfront-3/src/lalex.cpp"
case 30 :case 46 :case 47 :case 50 :case 54 :case 55 :
# 529 "/home/claude/cfront-3/src/lalex.cpp"
case 64 :case
# 529 "/home/claude/cfront-3/src/lalex.cpp"
70 :case 90 :case 91 :case 92 :case 93 :
# 530 "/home/claude/cfront-3/src/lalex.cpp"
case 94 :case 95 :
# 531 "/home/claude/cfront-3/src/lalex.cpp"
return 1 ;
}
}

# 536 "/home/claude/cfront-3/src/lalex.cpp"
static struct toknode *get_next_token__FP7toknode (struct toknode *__1t )
# 537 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 538 "/home/claude/cfront-3/src/lalex.cpp"
if (! __1t -> next__7toknode )
# 539 "/home/claude/cfront-3/src/lalex.cpp"
add_tokens__Fv ( ) ;

# 541 "/home/claude/cfront-3/src/lalex.cpp"
return __1t -> next__7toknode ;
}

# 361 "/home/claude/cfront-3/src/cfront.h"
Pname is_cl_obj__4typeFv (struct type *__0this );

# 546 "/home/claude/cfront-3/src/lalex.cpp"
static int template_tscope__FP4nameP7toknode (Pname __1tn , struct toknode *__1lt )
# 551 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 552 "/home/claude/cfront-3/src/lalex.cpp"
int __1nest ;

# 552 "/home/claude/cfront-3/src/lalex.cpp"
__1nest = 0 ;

# 554 "/home/claude/cfront-3/src/lalex.cpp"
if (__1lt -> tok__7toknode != 58 )error__FiPCc ( (int )'i' , (const char *)"a `<' token was expected") ;
# 554 "/home/claude/cfront-3/src/lalex.cpp"

# 557 "/home/claude/cfront-3/src/lalex.cpp"
parameters_in_progress__17templ_compilation ++ ;

# 559 "/home/claude/cfront-3/src/lalex.cpp"
{ { struct toknode *__1t ;

# 559 "/home/claude/cfront-3/src/lalex.cpp"
__1t = __1lt ;

# 559 "/home/claude/cfront-3/src/lalex.cpp"
for(;;__1t = get_next_token__FP7toknode ( __1t ) ) 
# 560 "/home/claude/cfront-3/src/lalex.cpp"
switch (__1t -> tok__7toknode ){ 
# 562 "/home/claude/cfront-3/src/lalex.cpp"
case 58 :
# 563 "/home/claude/cfront-3/src/lalex.cpp"
++ __1nest ;
continue ;
case 60 :
# 568 "/home/claude/cfront-3/src/lalex.cpp"
if ((-- __1nest )== 0 ){ 
# 569 "/home/claude/cfront-3/src/lalex.cpp"
__1t = get_next_token__FP7toknode ( __1t ) ;
if ((__1t -> tok__7toknode == 160 )|| (__1t -> tok__7toknode == 178 )){ 
# 572 "/home/claude/cfront-3/src/lalex.cpp"
if (__1t -> next__7toknode == 0 )add_tokens__Fv ( ) ;
if (__1t -> next__7toknode -> tok__7toknode == 50 ){ 
# 574 "/home/claude/cfront-3/src/lalex.cpp"
__1t -> tok__7toknode = 173 ;
del_1__FP7toknode ( __1t -> next__7toknode ) ;
}
else 
# 576 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 577 "/home/claude/cfront-3/src/lalex.cpp"
__1t -> tok__7toknode = 178 ;

# 579 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1t -> next__7toknode -> tok__7toknode == 80 )&& in_progress__17templ_compilation ){ 
# 580 "/home/claude/cfront-3/src/lalex.cpp"
Pname __6cn ;

# 580 "/home/claude/cfront-3/src/lalex.cpp"
__6cn = is_cl_obj__4typeFv ( __1tn -> __O1__4expr.tp ) ;
if (__6cn ){ 
# 582 "/home/claude/cfront-3/src/lalex.cpp"
int __7hh ;
Pname __7tn2 ;

# 582 "/home/claude/cfront-3/src/lalex.cpp"
__7hh = (__1t -> next__7toknode -> next__7toknode -> tok__7toknode == 160 );
__7tn2 = k_find_member__FPCcP8classdefUc ( __1t -> next__7toknode -> retval__7toknode . s__7YYSTYPE , ((struct classdef *)(((struct classdef *)__6cn -> __O1__4expr.tp ))), (unsigned char )__7hh ) ;
# 583 "/home/claude/cfront-3/src/lalex.cpp"

# 584 "/home/claude/cfront-3/src/lalex.cpp"
if (__7tn2 && (__7tn2 -> base__4node == 123 )){ 
# 585 "/home/claude/cfront-3/src/lalex.cpp"
__1t -> next__7toknode -> tok__7toknode = 123 ;
__1t -> next__7toknode -> retval__7toknode . pn__7YYSTYPE = __7tn2 ;
}
}
}
}
__1t -> retval__7toknode . pn__7YYSTYPE = __1tn ;
-- parameters_in_progress__17templ_compilation ;
return 1 ;
}
else 
# 594 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 595 "/home/claude/cfront-3/src/lalex.cpp"
-- parameters_in_progress__17templ_compilation ;
return 0 ;
}
}
continue ;

# 601 "/home/claude/cfront-3/src/lalex.cpp"
case 72 :case 73 :case 74 :
# 602 "/home/claude/cfront-3/src/lalex.cpp"
case 0 :
# 603 "/home/claude/cfront-3/src/lalex.cpp"
-- parameters_in_progress__17templ_compilation ;
return 0 ;

# 606 "/home/claude/cfront-3/src/lalex.cpp"
default :
# 607 "/home/claude/cfront-3/src/lalex.cpp"
continue ;
}

# 608 "/home/claude/cfront-3/src/lalex.cpp"
}

# 608 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 938 "/home/claude/cfront-3/src/cfront.h"
void hide__4nameFv (struct name *__0this );

# 612 "/home/claude/cfront-3/src/lalex.cpp"
static TOK lookahead__Fv (void )
# 618 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 619 "/home/claude/cfront-3/src/lalex.cpp"
TOK __1tk ;
TOK __1tk2 ;
TOK __1prev_tk ;
union YYSTYPE __1lastval ;

# 621 "/home/claude/cfront-3/src/lalex.cpp"
__1prev_tk = 0 ;

# 624 "/home/claude/cfront-3/src/lalex.cpp"
if (latok == rear ){ 
# 625 "/home/claude/cfront-3/src/lalex.cpp"
add_tokens__Fv ( ) ;
if (latok )
# 627 "/home/claude/cfront-3/src/lalex.cpp"
latok = latok -> next__7toknode ;
else 
# 629 "/home/claude/cfront-3/src/lalex.cpp"
latok = front ;
}
else 
# 632 "/home/claude/cfront-3/src/lalex.cpp"
latok = latok -> next__7toknode ;

# 634 "/home/claude/cfront-3/src/lalex.cpp"
if (latok -> last__7toknode ){ 
# 635 "/home/claude/cfront-3/src/lalex.cpp"
__1prev_tk = latok -> last__7toknode -> tok__7toknode ;
__1lastval = latok -> last__7toknode -> retval__7toknode ;
}

# 639 "/home/claude/cfront-3/src/lalex.cpp"
nexttok :
# 640 "/home/claude/cfront-3/src/lalex.cpp"
;

# 640 "/home/claude/cfront-3/src/lalex.cpp"
if (! latok -> used__7toknode )use_token__FP7toknode ( latok ) ;

# 640 "/home/claude/cfront-3/src/lalex.cpp"
;
__1tk = latok -> tok__7toknode ;
if ((__1tk == 80 )|| (__1tk == 123 ))
# 643 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 644 "/home/claude/cfront-3/src/lalex.cpp"
if (latok -> next__7toknode == 0 )add_tokens__Fv ( ) ;
;

# 645 "/home/claude/cfront-3/src/lalex.cpp"
if (! latok -> next__7toknode -> used__7toknode )use_token__FP7toknode ( latok -> next__7toknode ) ;

# 645 "/home/claude/cfront-3/src/lalex.cpp"
;
__1tk2 = latok -> next__7toknode -> tok__7toknode ;
if (__1tk == 123 ){ 
# 648 "/home/claude/cfront-3/src/lalex.cpp"
if (__1tk2 == 58 ){ 
# 651 "/home/claude/cfront-3/src/lalex.cpp"
if (template_tscope__FP4nameP7toknode ( latok -> retval__7toknode . pn__7YYSTYPE , latok -> next__7toknode ) )__1tk =
# 651 "/home/claude/cfront-3/src/lalex.cpp"
209 ;
}
else 
# 654 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1tk2 == 160 )|| (__1tk2 == 45 )){ 
# 655 "/home/claude/cfront-3/src/lalex.cpp"
tscope :
# 656 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = 178 ;

# 659 "/home/claude/cfront-3/src/lalex.cpp"
latok = latok -> next__7toknode ;
if (latok -> next__7toknode == 0 )add_tokens__Fv ( ) ;
;

# 661 "/home/claude/cfront-3/src/lalex.cpp"
if (! latok -> next__7toknode -> used__7toknode )use_token__FP7toknode ( latok -> next__7toknode ) ;

# 661 "/home/claude/cfront-3/src/lalex.cpp"
;
__1tk2 = latok -> next__7toknode -> tok__7toknode ;
if (__1tk2 == 50 ){ 
# 664 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = 173 ;
latok = latok -> next__7toknode ;
}
}
else if (((__1prev_tk == 50 )&& (__1tk2 != 41 ))|| (__1prev_tk == 52 ))
# 670 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 671 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = 80 ;
hide__4nameFv ( latok -> retval__7toknode . pn__7YYSTYPE ) ;
latok -> tok__7toknode = 80 ;
latok -> retval__7toknode . s__7YYSTYPE = latok -> retval__7toknode . pn__7YYSTYPE -> __O2__4expr.string ;
}
}
else if (__1tk2 == 160 ){ 
# 681 "/home/claude/cfront-3/src/lalex.cpp"
goto tscope ;
}

# 684 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1tk == 80 )&& ((__1tk2 == 80 )|| ((__1prev_tk == 80 )&& ((__1tk2 == 69 )|| (__1tk2 == 73 )))))
# 686 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 688 "/home/claude/cfront-3/src/lalex.cpp"
latok = latok -> next__7toknode ;
# 688 "/home/claude/cfront-3/src/lalex.cpp"

# 689 "/home/claude/cfront-3/src/lalex.cpp"
goto nexttok ;
}
}

# 693 "/home/claude/cfront-3/src/lalex.cpp"
return __1tk ;
}

# 696 "/home/claude/cfront-3/src/lalex.cpp"
extern int in_sizeof ;
extern int in_friend ;
extern int in_new ;

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

# 701 "/home/claude/cfront-3/src/lalex.cpp"
static int type_is_redefined__FP4name (Pname __1n )
# 702 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 703 "/home/claude/cfront-3/src/lalex.cpp"
Pktab __1tb ;

# 703 "/home/claude/cfront-3/src/lalex.cpp"
__1tb = Ctbl ;
while (__1tb -> k_id__6ktable == 136 )__1tb = __1tb -> k_next__6ktable ;
return (__1n -> n_ktable__4name == __1tb );
}

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 76 "/home/claude/cfront-3/src/cfront.h"

# 328 "/home/claude/cfront-3/src/cfront.h"
Pclass classtype__4typeFv (struct type *__0this );

# 937 "/home/claude/cfront-3/src/cfront.h"
Pname tname__4nameFUc (struct name *__0this , TOK );

# 657 "/home/claude/cfront-3/src/cfront.h"
struct name_list *__ct__9name_listFP4nameP9name_list (struct name_list *__0this , Pname __1ff , Plist __1ll );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 709 "/home/claude/cfront-3/src/lalex.cpp"
static Pname do_nl_type__FP4nameiUc (Pname __1n , int __1lex_level , TOK __1tecsu )
# 716 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 717 "/home/claude/cfront-3/src/lalex.cpp"
Pname __1nn ;

# 717 "/home/claude/cfront-3/src/lalex.cpp"
__1nn = __1n ;
if ((ccl && (in_mem_fct == 0 ))&& (strcmp ( ccl -> string__8classdef , __1n -> __O2__4expr.string ) == 0 )){ 
# 719 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 719 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V40 ;
# 719 "/home/claude/cfront-3/src/lalex.cpp"

# 719 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V41 ;

# 719 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"nested%k%n redefines immediately enclosing class", (const struct ea *)( (( ((& __0__V40 )->
# 719 "/home/claude/cfront-3/src/lalex.cpp"
__O1__2ea.i = ((unsigned long )((__1tecsu == 97 )?(((unsigned int )190 )):(((unsigned int )__1tecsu ))))), 0 ) ), (& __0__V40 )) ,
# 719 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)( ((& __0__V41 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V41 )) , (const struct
# 719 "/home/claude/cfront-3/src/lalex.cpp"
ea *)ea0 , (const struct ea *)ea0 ) ;
error__FiPCc ( (int )'i' , (const char *)"cannot recover from previous errors") ;
} }
switch (__1tecsu ){ 
# 723 "/home/claude/cfront-3/src/lalex.cpp"
case 6 :case 32 :case 36 :case 13 :
# 725 "/home/claude/cfront-3/src/lalex.cpp"
if (((__1n -> base__4node == 123 )&& (__1n -> lex_level__4name == __1lex_level ))&&
# 725 "/home/claude/cfront-3/src/lalex.cpp"
type_is_redefined__FP4name ( __1n ) )
# 728 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 729 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1n -> __O1__4expr.tp == 0 )|| ((__1n -> __O1__4expr.tp -> base__4node != 119 )&& (__1n -> __O1__4expr.tp -> base__4node !=
# 729 "/home/claude/cfront-3/src/lalex.cpp"
121 ))){ 
# 734 "/home/claude/cfront-3/src/lalex.cpp"
return __1n ;
}

# 737 "/home/claude/cfront-3/src/lalex.cpp"
if (((__1n -> __O1__4expr.tp -> base__4node == 121 )&& (__1tecsu != 13 ))|| ((__1n -> __O1__4expr.tp -> base__4node == 119 )&& (__1tecsu == 13 )))
# 738 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 739 "/home/claude/cfront-3/src/lalex.cpp"
{
# 739 "/home/claude/cfront-3/src/lalex.cpp"

# 739 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V42 ;

# 739 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n defined asC and enum", (const struct ea *)( ((& __0__V42 )-> __O1__2ea.p =
# 739 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__1n )), (& __0__V42 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 739 "/home/claude/cfront-3/src/lalex.cpp"
ea *)ea0 ) ;
error__FiPCc ( (int )'i' , (const char *)"cannot recover") ;
} }

# 746 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1n -> __O1__4expr.tp -> base__4node == 119 )&& ((classtype__4typeFv ( __1n -> __O1__4expr.tp ) -> defined__4type & 5)== 0 ))
# 749 "/home/claude/cfront-3/src/lalex.cpp"
return __1n ;
# 749 "/home/claude/cfront-3/src/lalex.cpp"

# 750 "/home/claude/cfront-3/src/lalex.cpp"
}
__1nn = __ct__4nameFPCc ( (struct name *)0 , __1n -> __O2__4expr.string ) ;
__1nn -> lex_level__4name = __1lex_level ;
__1nn = tname__4nameFUc ( __1nn , __1tecsu ) ;
if (__1nn -> n_ktable__4name == 0 ){ 
# 754 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V43 ;

# 754 "/home/claude/cfront-3/src/lalex.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"TN insert failed for%n", (const struct ea *)( ((&
# 754 "/home/claude/cfront-3/src/lalex.cpp"
__0__V43 )-> __O1__2ea.p = ((const void *)__1nn )), (& __0__V43 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 754 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 ) ;
} 
# 756 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1tecsu != 13 )&& (__1nn -> n_ktable__4name -> k_id__6ktable == 116 ))
# 757 "/home/claude/cfront-3/src/lalex.cpp"
local_class = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __1nn , local_class ) ;
# 757 "/home/claude/cfront-3/src/lalex.cpp"

# 758 "/home/claude/cfront-3/src/lalex.cpp"
break ;
default :
# 760 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 760 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V44 ;

# 760 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & __1n -> where__4name , (const char *)"bad tecsu%k in do_nl_type()", (const
# 760 "/home/claude/cfront-3/src/lalex.cpp"
struct ea *)( (( ((& __0__V44 )-> __O1__2ea.i = ((unsigned long )__1tecsu )), 0 ) ), (& __0__V44 )) ,
# 760 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
return __1nn ;
}

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 493 "/home/claude/cfront-3/src/cfront.h"

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 959 "/home/claude/cfront-3/src/cfront.h"
void del__4nameFv (struct name *__0this );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 783 "/home/claude/cfront-3/src/lalex.cpp"
TOK lalex__Fv (void )
# 785 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 786 "/home/claude/cfront-3/src/lalex.cpp"
TOK __1tk ;
if (front == 0 )
# 788 "/home/claude/cfront-3/src/lalex.cpp"
add_tokens__Fv ( ) ;
;

# 791 "/home/claude/cfront-3/src/lalex.cpp"
gettok :
# 792 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = deltok__Fi ( 0 ) ;
{ Pname __1n ;

# 793 "/home/claude/cfront-3/src/lalex.cpp"
__1n = idname ;

# 796 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1tk == 80 )|| (__1tk == 123 ))
# 797 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 798 "/home/claude/cfront-3/src/lalex.cpp"
TOK __2tk2 ;
int __2lex_level ;

# 798 "/home/claude/cfront-3/src/lalex.cpp"
__2tk2 = la_look__Fv ( ) ;
__2lex_level = ((bl_level - in_class_decl )- (__2tk2 == 73 ));

# 801 "/home/claude/cfront-3/src/lalex.cpp"
if (__1tk == 123 )
# 802 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 806 "/home/claude/cfront-3/src/lalex.cpp"
if (((((((__2tk2 == 40 )&& (lasttk != 178 ))&& (lasttk != 160 ))&& (((lasttk == 97 )|| (bl_level == 0 ))||
# 806 "/home/claude/cfront-3/src/lalex.cpp"
parsing_class_members ))&& (laexpr__FUc ( (unsigned char )lasttk ) == 0 ))&& (must_be_expr == 0 ))&& (DECL_TYPE == 0 ))
# 810 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 811 "/home/claude/cfront-3/src/lalex.cpp"
if (la_decl__Fi ( in_arg_list )
# 811 "/home/claude/cfront-3/src/lalex.cpp"
){ 
# 812 "/home/claude/cfront-3/src/lalex.cpp"
must_be_id = 0 ;
DECL_TYPE = __1tk ;
__1tk = 179 ;
goto ret ;
}
}

# 820 "/home/claude/cfront-3/src/lalex.cpp"
if ((lasttk == 156 )|| (lasttk == 13 )){ 
# 821 "/home/claude/cfront-3/src/lalex.cpp"
if (((__2tk2 == 73 )|| (__2tk2 == 69 ))|| (((__2tk2 == 72 )&& (! in_new ))&&
# 821 "/home/claude/cfront-3/src/lalex.cpp"
(! in_friend )))
# 822 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 835 "/home/claude/cfront-3/src/lalex.cpp"
if (in_friend ){ 
# 835 "/home/claude/cfront-3/src/lalex.cpp"
const void *__2__X86 ;

# 836 "/home/claude/cfront-3/src/lalex.cpp"
if (Ctbl -> k_id__6ktable != 6 )
# 837 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 837 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V45 ;

# 837 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"friend %s not inC", (const struct ea *)( (__2__X86 = (const void
# 837 "/home/claude/cfront-3/src/lalex.cpp"
*)yylval . pn__7YYSTYPE -> __O2__4expr.string ), ( ((& __0__V45 )-> __O1__2ea.p = __2__X86 ), (& __0__V45 )) ) , (const struct
# 837 "/home/claude/cfront-3/src/lalex.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 846 "/home/claude/cfront-3/src/lalex.cpp"
}
else 
# 848 "/home/claude/cfront-3/src/lalex.cpp"
if ((__2tk2 != 72 )|| (type_is_redefined__FP4name ( yylval . pn__7YYSTYPE ) == 0 )){ 
# 849 "/home/claude/cfront-3/src/lalex.cpp"
if (__2lex_level && ((in_class_decl == 0 )||
# 849 "/home/claude/cfront-3/src/lalex.cpp"
in_mem_fct ))
# 851 "/home/claude/cfront-3/src/lalex.cpp"
yylval . pn__7YYSTYPE = do_nl_type__FP4nameiUc ( yylval . pn__7YYSTYPE , __2lex_level , lastval . t__7YYSTYPE ) ;
else if (in_class_decl && ccl )
# 853 "/home/claude/cfront-3/src/lalex.cpp"
yylval . pn__7YYSTYPE = do_nl_type__FP4nameiUc ( yylval . pn__7YYSTYPE , __2lex_level , lastval . t__7YYSTYPE ) ;
}

# 860 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 863 "/home/claude/cfront-3/src/lalex.cpp"
if ((__2tk2 == 58 )&& template_tscope__FP4nameP7toknode ( yylval . pn__7YYSTYPE , latok ) ){ 
# 864 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = 209 ;
}
else if ((__2tk2 == 160 )|| ((((__2tk2 == 45 )&& (lasttk != 44 ))&& (lasttk != 45 ))&& (lasttk != 180 ))){ 
# 867 "/home/claude/cfront-3/src/lalex.cpp"
if (__2tk2 ==
# 867 "/home/claude/cfront-3/src/lalex.cpp"
45 )
# 868 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCc ( (const char *)"``.'' used for qualification; please use ``::''") ;

# 870 "/home/claude/cfront-3/src/lalex.cpp"
if (yylval . pn__7YYSTYPE -> __O1__4expr.tp -> base__4node == 119 ){ 
# 871 "/home/claude/cfront-3/src/lalex.cpp"
Pclass __5cl ;
Pclass __5cl2 ;

# 873 "/home/claude/cfront-3/src/lalex.cpp"
struct classdef *__1__X87 ;

# 873 "/home/claude/cfront-3/src/lalex.cpp"
struct classdef *__1__X88 ;

# 873 "/home/claude/cfront-3/src/lalex.cpp"
const void *__2__X89 ;

# 871 "/home/claude/cfront-3/src/lalex.cpp"
__5cl = classtype__4typeFv ( yylval . pn__7YYSTYPE -> __O1__4expr.tp ) ;
__5cl2 = ccl ;
while (__5cl2 && __5cl2 -> in_class__4type )__5cl2 = __5cl2 -> in_class__4type ;
if ((__5cl && __5cl -> class_base__8classdef )&& (((__5cl2 == 0 )|| (__5cl2 -> templ_base__4type == 2))|| (( (__1__X87 = __5cl ), ( (__1__X88 =
# 874 "/home/claude/cfront-3/src/lalex.cpp"
__5cl2 ), ( ((__1__X87 == __1__X88 )?1 :((__1__X87 && __1__X88 )?(((int )same_class__8classdefFP8classdefi ( __1__X87 , __1__X88 , 0 ) )):0 ))) ) ) == 0 )))
# 875 "/home/claude/cfront-3/src/lalex.cpp"
{
# 875 "/home/claude/cfront-3/src/lalex.cpp"

# 875 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V46 ;

# 875 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"YC%n must be qualifiedWZL of instantiations", (const struct ea *)( (__2__X89 = (const void
# 875 "/home/claude/cfront-3/src/lalex.cpp"
*)yylval . pn__7YYSTYPE ), ( ((& __0__V46 )-> __O1__2ea.p = __2__X89 ), (& __0__V46 )) ) , (const struct ea *)ea0 ,
# 875 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 878 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = 178 ;
{ 
# 880 "/home/claude/cfront-3/src/lalex.cpp"
int __5n ;

# 880 "/home/claude/cfront-3/src/lalex.cpp"
__5n = 0 ;
while ((__2tk2 = lookahead__Fv ( ) )== 178 )__5n += 2 ;
if (__2tk2 == 123 ){ 
# 883 "/home/claude/cfront-3/src/lalex.cpp"
Pname __6cn ;
struct toknode *__6t ;

# 883 "/home/claude/cfront-3/src/lalex.cpp"
__6cn = latok -> retval__7toknode . pn__7YYSTYPE ;
__6t = latok ;
__2tk2 = lookahead__Fv ( ) ;
if (((((__2tk2 == 40 )&& ((bl_level == 0 )|| parsing_class_members ))&& (laexpr__FUc ( (unsigned char )lasttk ) == 0 ))&& (must_be_expr == 0 ))&&
# 886 "/home/claude/cfront-3/src/lalex.cpp"
(DECL_TYPE == 0 ))
# 890 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 891 "/home/claude/cfront-3/src/lalex.cpp"
if (la_decl__Fi ( in_arg_list ) ){ 
# 892 "/home/claude/cfront-3/src/lalex.cpp"
must_be_id = 0 ;

# 894 "/home/claude/cfront-3/src/lalex.cpp"
DECL_TYPE = 123 ;

# 896 "/home/claude/cfront-3/src/lalex.cpp"
__5n ++ ;
__5n ++ ;
__1tk = 179 ;
while ((__5n -- )> 0 )
# 900 "/home/claude/cfront-3/src/lalex.cpp"
deltok__Fi ( 0 ) ;
goto ret ;
}
la_reset__FP7toknodeP4name ( __6t -> next__7toknode , __6cn ) ;
}
}
}
__2tk2 = deltok__Fi ( 1 ) ;
__2tk2 = la_look__Fv ( ) ;
if (__2tk2 == 50 ){ 
# 910 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = 173 ;
__2tk2 = deltok__Fi ( 1 ) ;
}
}
else 
# 915 "/home/claude/cfront-3/src/lalex.cpp"
if (must_be_id ){ 
# 915 "/home/claude/cfront-3/src/lalex.cpp"
const void *__2__X90 ;

# 916 "/home/claude/cfront-3/src/lalex.cpp"
;
if (((in_class_decl && (lasttk == 97 ))&& (__2tk2 == 40 ))&& (strcmp ( yylval . pn__7YYSTYPE -> __O2__4expr.string , ccl -> string__8classdef ) == 0 ))
# 921 "/home/claude/cfront-3/src/lalex.cpp"
{
# 921 "/home/claude/cfront-3/src/lalex.cpp"

# 921 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V47 ;

# 921 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%nK with returnT", (const struct ea *)( (__2__X90 = (const void
# 921 "/home/claude/cfront-3/src/lalex.cpp"
*)yylval . pn__7YYSTYPE ), ( ((& __0__V47 )-> __O1__2ea.p = __2__X90 ), (& __0__V47 )) ) , (const struct ea *)ea0 ,
# 921 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 923 "/home/claude/cfront-3/src/lalex.cpp"
if (((lasttk == 97 )&& (lastval . t__7YYSTYPE == 76 ))&& ((__2tk2 == 72 )|| (__2tk2 == 40 )))
# 925 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 926 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = 80 ;
# 926 "/home/claude/cfront-3/src/lalex.cpp"

# 927 "/home/claude/cfront-3/src/lalex.cpp"
hide__4nameFv ( yylval . pn__7YYSTYPE ) ;
yylval . pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , yylval . pn__7YYSTYPE -> __O2__4expr.string ) ;
yylval . pn__7YYSTYPE -> n_oper__4name = 123 ;
}
else if (lasttk == 24 )
# 933 "/home/claude/cfront-3/src/lalex.cpp"
must_be_id = 0 ;
else if (((lasttk != 178 )|| (lastval . pn__7YYSTYPE != yylval . pn__7YYSTYPE ))|| (in_typedef && (check__4typeFP4typeUcT2 ( in_typedef , yylval . pn__7YYSTYPE -> __O1__4expr.tp ,
# 934 "/home/claude/cfront-3/src/lalex.cpp"
(unsigned char )0 , (unsigned char )0 ) == 0 )))
# 938 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 939 "/home/claude/cfront-3/src/lalex.cpp"
;
__1tk = 80 ;
if (in_typedef && ((lasttk == 50 )|| (lasttk == 44 ))){ 
# 942 "/home/claude/cfront-3/src/lalex.cpp"
defer_check = 1 ;
in_tag = yylval . pn__7YYSTYPE ;
}

# 946 "/home/claude/cfront-3/src/lalex.cpp"
if ((lasttk == 160 )&& yylval . pn__7YYSTYPE -> lex_level__4name ){ 
# 949 "/home/claude/cfront-3/src/lalex.cpp"
Pname __6nn ;

# 950 "/home/claude/cfront-3/src/lalex.cpp"
unsigned long __2__X91 ;

# 950 "/home/claude/cfront-3/src/lalex.cpp"
const void *__2__X92 ;

# 949 "/home/claude/cfront-3/src/lalex.cpp"
__6nn = k_find_name__FPCcP6ktableUc ( yylval . pn__7YYSTYPE -> __O2__4expr.string , Gtbl , (unsigned char )0 ) ;
if ((__6nn == 0 )|| (__6nn -> base__4node == 85 ))
# 951 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 951 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V48 ;

# 951 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V49 ;

# 951 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%k%s undeclared", (const struct ea *)( (__2__X91 = lasttk ), (
# 951 "/home/claude/cfront-3/src/lalex.cpp"
(( ((& __0__V48 )-> __O1__2ea.i = __2__X91 ), 0 ) ), (& __0__V48 )) ) , (const struct ea *)(
# 951 "/home/claude/cfront-3/src/lalex.cpp"
(__2__X92 = (const void *)yylval . pn__7YYSTYPE -> __O2__4expr.string ), ( ((& __0__V49 )-> __O1__2ea.p = __2__X92 ), (& __0__V49 )) )
# 951 "/home/claude/cfront-3/src/lalex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else 
# 953 "/home/claude/cfront-3/src/lalex.cpp"
yylval . pn__7YYSTYPE = __6nn ;
}
else { 
# 956 "/home/claude/cfront-3/src/lalex.cpp"
if ((((lasttk != 45 )&& (lasttk != 44 ))&& (lasttk != 178 ))&& (lasttk != 19 ))
# 957 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 960 "/home/claude/cfront-3/src/lalex.cpp"
if ((! in_typedef )||
# 960 "/home/claude/cfront-3/src/lalex.cpp"
in_arg_list ){ 
# 961 "/home/claude/cfront-3/src/lalex.cpp"
;
hide__4nameFv ( yylval . pn__7YYSTYPE ) ;
yylval . pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , yylval . pn__7YYSTYPE -> __O2__4expr.string ) ;
}
else 
# 964 "/home/claude/cfront-3/src/lalex.cpp"
if (yylval . pn__7YYSTYPE -> base__4node == 123 ){ 
# 965 "/home/claude/cfront-3/src/lalex.cpp"
yylval . pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , yylval . pn__7YYSTYPE -> __O2__4expr.string )
# 965 "/home/claude/cfront-3/src/lalex.cpp"
;
}

# 969 "/home/claude/cfront-3/src/lalex.cpp"
yylval . pn__7YYSTYPE -> n_oper__4name = 123 ;
}
else 
# 970 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 972 "/home/claude/cfront-3/src/lalex.cpp"
yylval . pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , yylval . pn__7YYSTYPE -> __O2__4expr.string ) ;
}
;
}
if (defer_check )defer_check = 0 ;
}
}

# 980 "/home/claude/cfront-3/src/lalex.cpp"
;

# 988 "/home/claude/cfront-3/src/lalex.cpp"
}
else 
# 990 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 991 "/home/claude/cfront-3/src/lalex.cpp"
const char *__3s ;

# 991 "/home/claude/cfront-3/src/lalex.cpp"
__3s = yylval . s__7YYSTYPE ;
if (__1n )__1n = __1n -> __O1__4name.n_hidden ;

# 997 "/home/claude/cfront-3/src/lalex.cpp"
if (__2tk2 == 160 ){ 
# 999 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 999 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V50 ;

# 999 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V51 ;

# 999 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s:: -- %sis not aTN", (const struct ea *)( ((& __0__V50 )-> __O1__2ea.p =
# 999 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__3s )), (& __0__V50 )) , (const struct ea *)( ((& __0__V51 )-> __O1__2ea.p = ((const void
# 999 "/home/claude/cfront-3/src/lalex.cpp"
*)__3s )), (& __0__V51 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__2tk2 = deltok__Fi ( 1 ) ;
goto gettok ;
} }
else 
# 1005 "/home/claude/cfront-3/src/lalex.cpp"
if ((lasttk == 13 )|| ((lasttk == 156 )&& ((in_arg_list != 2 )|| ((__2tk2 != 60 )&& (__2tk2 != 71 )))))
# 1008 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1014 "/home/claude/cfront-3/src/lalex.cpp"
int
# 1014 "/home/claude/cfront-3/src/lalex.cpp"
__4tagdef ;

# 1014 "/home/claude/cfront-3/src/lalex.cpp"
__4tagdef = (((__2tk2 == 73 )|| (__2tk2 == 69 ))|| (((__2tk2 == 72 )&& (! in_new ))&& (! in_friend )));
__1tk = 123 ;

# 1020 "/home/claude/cfront-3/src/lalex.cpp"
if (((__1n == 0 )|| (__1n -> n_template_arg__4name == 1))|| __4tagdef )
# 1023 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1036 "/home/claude/cfront-3/src/lalex.cpp"
if (in_friend && __4tagdef ){ 
# 1037 "/home/claude/cfront-3/src/lalex.cpp"
if (Ctbl -> k_id__6ktable != 6 )
# 1038 "/home/claude/cfront-3/src/lalex.cpp"
{
# 1038 "/home/claude/cfront-3/src/lalex.cpp"

# 1038 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V52 ;

# 1038 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"friend %s not inC", (const struct ea *)( ((& __0__V52 )-> __O1__2ea.p =
# 1038 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__3s )), (& __0__V52 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1038 "/home/claude/cfront-3/src/lalex.cpp"
ea *)ea0 ) ;
} 
# 1047 "/home/claude/cfront-3/src/lalex.cpp"
}
else 
# 1049 "/home/claude/cfront-3/src/lalex.cpp"
if (((__1n == 0 )|| (__2tk2 != 72 ))|| (! type_is_redefined__FP4name ( __1n ) )){ 
# 1050 "/home/claude/cfront-3/src/lalex.cpp"
Pname __6nn ;

# 1050 "/home/claude/cfront-3/src/lalex.cpp"
__6nn = __ct__4nameFPCc ( (struct name *)0 , __3s ) ;
if (! __4tagdef )
# 1052 "/home/claude/cfront-3/src/lalex.cpp"
__6nn -> lex_level__4name = 0 ;
else 
# 1054 "/home/claude/cfront-3/src/lalex.cpp"
__6nn -> lex_level__4name = __2lex_level ;

# 1056 "/home/claude/cfront-3/src/lalex.cpp"
if (((ccl && __4tagdef )&& in_class_decl )&& (bl_level == ((ccl -> lex_level__4type + in_class_decl )+ (__2tk2 == 73 ))))
# 1058 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1059 "/home/claude/cfront-3/src/lalex.cpp"
if (__1n ){ if (__6nn &&
# 1059 "/home/claude/cfront-3/src/lalex.cpp"
(__6nn -> permanent__4node == 0 ))del__4nameFv ( __6nn ) ;

# 1059 "/home/claude/cfront-3/src/lalex.cpp"
__6nn = __1n ;

# 1059 "/home/claude/cfront-3/src/lalex.cpp"
}
__1n = do_nl_type__FP4nameiUc ( __6nn , __2lex_level , lastval . t__7YYSTYPE ) ;
}
else 
# 1063 "/home/claude/cfront-3/src/lalex.cpp"
if (__6nn -> lex_level__4name ){ 
# 1064 "/home/claude/cfront-3/src/lalex.cpp"
int __7ll ;

# 1064 "/home/claude/cfront-3/src/lalex.cpp"
__7ll = __6nn -> lex_level__4name ;
if (__1n ){ if (__6nn && (__6nn -> permanent__4node == 0 ))del__4nameFv ( __6nn ) ;

# 1065 "/home/claude/cfront-3/src/lalex.cpp"
__6nn = __1n ;

# 1065 "/home/claude/cfront-3/src/lalex.cpp"
}
__1n = do_nl_type__FP4nameiUc ( __6nn , __7ll , lastval . t__7YYSTYPE ) ;
}
else { 
# 1081 "/home/claude/cfront-3/src/lalex.cpp"
if (__1n == 0 ){ 
# 1082 "/home/claude/cfront-3/src/lalex.cpp"
Pktab __8otbl ;
Pclass __8occl ;

# 1082 "/home/claude/cfront-3/src/lalex.cpp"
__8otbl = Ctbl ;
__8occl = ccl ;
Ctbl = Gtbl ;
ccl = 0 ;
__1n = tname__4nameFUc ( __6nn , lastval . t__7YYSTYPE ) ;
Ctbl = __8otbl ;
ccl = __8occl ;
}
else 
# 1089 "/home/claude/cfront-3/src/lalex.cpp"
if (__6nn && (__6nn -> permanent__4node == 0 ))del__4nameFv ( __6nn ) ;

# 1091 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 1100 "/home/claude/cfront-3/src/lalex.cpp"
}
else { 
# 1102 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1n -> __O1__4expr.tp -> base__4node != 119 )&& (__1n -> __O1__4expr.tp -> base__4node != 121 )){ 
# 1106 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1106 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V53 ;
# 1106 "/home/claude/cfront-3/src/lalex.cpp"

# 1106 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V54 ;

# 1106 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"hidden%n:%t", (const struct ea *)( ((& __0__V53 )-> __O1__2ea.p =
# 1106 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__1n )), (& __0__V53 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V54 , (const void *)__1n ->
# 1106 "/home/claude/cfront-3/src/lalex.cpp"
__O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
error__FiPCc ( (int )'i' , (const char *)"cannot recover") ;
} }

# 1111 "/home/claude/cfront-3/src/lalex.cpp"
}
yylval . pn__7YYSTYPE = __1n ;
}
else { 
# 1115 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = 80 ;
yylval . pn__7YYSTYPE = __ct__4nameFPCc ( (struct name *)0 , __3s ) ;
}

# 1119 "/home/claude/cfront-3/src/lalex.cpp"
if (__1tk == 80 )
# 1120 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1121 "/home/claude/cfront-3/src/lalex.cpp"
switch (__2tk2 ){ 
# 1122 "/home/claude/cfront-3/src/lalex.cpp"
case 80 :case 123 :case 156 :case 13 :
# 1123 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1124 "/home/claude/cfront-3/src/lalex.cpp"
Pname __6n ;

# 1124 "/home/claude/cfront-3/src/lalex.cpp"
__6n = 0 ;

# 1126 "/home/claude/cfront-3/src/lalex.cpp"
__6n = k_find_name__FPCcP6ktableUc ( __3s , Ctbl , (unsigned char )159 ) ;
if (__6n ){ 
# 1128 "/home/claude/cfront-3/src/lalex.cpp"
const char *__7x ;

# 1128 "/home/claude/cfront-3/src/lalex.cpp"
__7x = (((__2tk2 == 80 )|| (__2tk2 == 123 ))?front -> retval__7toknode . s__7YYSTYPE :(keys [__2tk2 ]));

# 1132 "/home/claude/cfront-3/src/lalex.cpp"
switch (__6n -> __O1__4expr.tp -> base__4node ){ 
# 1133 "/home/claude/cfront-3/src/lalex.cpp"
default :
# 1134 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1134 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V55 ;

# 1134 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V56 ;

# 1134 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V57 ;

# 1134 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V58 ;

# 1134 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s%s:Tdef %sis %sin this scope", (const struct ea *)( ((& __0__V55 )-> __O1__2ea.p =
# 1134 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__3s )), (& __0__V55 )) , (const struct ea *)( ((& __0__V56 )-> __O1__2ea.p = ((const void
# 1134 "/home/claude/cfront-3/src/lalex.cpp"
*)__7x )), (& __0__V56 )) , (const struct ea *)( ((& __0__V57 )-> __O1__2ea.p = ((const void *)__3s )), (&
# 1134 "/home/claude/cfront-3/src/lalex.cpp"
__0__V57 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V58 , (const void *)((__6n -> n_key__4name == 159 )?"hidden":(((char
# 1134 "/home/claude/cfront-3/src/lalex.cpp"
*)"undefined")))) ) ;
break ;
case 119 :
# 1137 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1137 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V59 ;

# 1137 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V60 ;

# 1137 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V61 ;

# 1137 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V62 ;

# 1137 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%sis %sin this scope: useC %s%s", (const struct ea *)( ((& __0__V59 )-> __O1__2ea.p =
# 1137 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__3s )), (& __0__V59 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V60 , (const void *)((__6n ->
# 1137 "/home/claude/cfront-3/src/lalex.cpp"
n_key__4name == 159 )?"hidden":(((char *)"undefined")))) , (const struct
# 1137 "/home/claude/cfront-3/src/lalex.cpp"
ea *)( ((& __0__V61 )-> __O1__2ea.p = ((const void *)__3s )), (& __0__V61 )) , (const struct ea *)( ((&
# 1137 "/home/claude/cfront-3/src/lalex.cpp"
__0__V62 )-> __O1__2ea.p = ((const void *)__7x )), (& __0__V62 )) ) ;
break ;
case 121 :
# 1140 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1140 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V63 ;

# 1140 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V64 ;

# 1140 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V65 ;

# 1140 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V66 ;

# 1140 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%sis %sin this scope: use enum %s%s", (const struct ea *)( ((& __0__V63 )-> __O1__2ea.p =
# 1140 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__3s )), (& __0__V63 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V64 , (const void *)((__6n ->
# 1140 "/home/claude/cfront-3/src/lalex.cpp"
n_key__4name == 159 )?"hidden":(((char *)"undefined")))) , (const struct
# 1140 "/home/claude/cfront-3/src/lalex.cpp"
ea *)( ((& __0__V65 )-> __O1__2ea.p = ((const void *)__3s )), (& __0__V65 )) , (const struct ea *)( ((&
# 1140 "/home/claude/cfront-3/src/lalex.cpp"
__0__V66 )-> __O1__2ea.p = ((const void *)__7x )), (& __0__V66 )) ) ;
break ;
} } } }
__1tk = 123 ;
yylval . pn__7YYSTYPE = __6n ;
}
else 
# 1147 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1147 "/home/claude/cfront-3/src/lalex.cpp"
unsigned long __2__X95 ;

# 1148 "/home/claude/cfront-3/src/lalex.cpp"
if (__2tk2 == 80 ){ 
# 1150 "/home/claude/cfront-3/src/lalex.cpp"
if ((lasttk == 178 )&& (lastval . pn__7YYSTYPE -> base__4node == 123 )){ 
# 1150 "/home/claude/cfront-3/src/lalex.cpp"
const void *__2__X93 ;

# 1150 "/home/claude/cfront-3/src/lalex.cpp"
const void *__2__X94 ;

# 1151 "/home/claude/cfront-3/src/lalex.cpp"
if ((lastval . pn__7YYSTYPE -> __O1__4expr.tp -> base__4node == 141 )&& (lastval . pn__7YYSTYPE -> n_template_arg__4name == 1))
# 1153 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1153 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V67 ;

# 1153 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V68 ;

# 1153 "/home/claude/cfront-3/src/lalex.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"use of %n::%sW formalYTZ", (const struct ea *)( (__2__X93 =
# 1153 "/home/claude/cfront-3/src/lalex.cpp"
(const void *)lastval . pn__7YYSTYPE ), ( ((& __0__V67 )-> __O1__2ea.p = __2__X93 ), (& __0__V67 )) ) , (const
# 1153 "/home/claude/cfront-3/src/lalex.cpp"
struct ea *)( ((& __0__V68 )-> __O1__2ea.p = ((const void *)__3s )), (& __0__V68 )) , (const struct ea *)ea0 ,
# 1153 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 ) ;
} else 
# 1155 "/home/claude/cfront-3/src/lalex.cpp"
if ((lastval . pn__7YYSTYPE -> __O1__4expr.tp -> base__4node == 119 )&& (classtype__4typeFv ( lastval . pn__7YYSTYPE -> __O1__4expr.tp ) -> class_base__8classdef !=
# 1155 "/home/claude/cfront-3/src/lalex.cpp"
0))
# 1157 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1157 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V69 ;

# 1157 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V70 ;

# 1157 "/home/claude/cfront-3/src/lalex.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"Zized nestedC access: %n<...>::%s", (const struct ea *)( (__2__X94 =
# 1157 "/home/claude/cfront-3/src/lalex.cpp"
(const void *)lastval . pn__7YYSTYPE ), ( ((& __0__V69 )-> __O1__2ea.p = __2__X94 ), (& __0__V69 )) ) , (const
# 1157 "/home/claude/cfront-3/src/lalex.cpp"
struct ea *)( ((& __0__V70 )-> __O1__2ea.p = ((const void *)__3s )), (& __0__V70 )) , (const struct ea *)ea0 ,
# 1157 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 ) ;
} else { 
# 1158 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V71 ;

# 1158 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V72 ;

# 1158 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V73 ;

# 1158 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s%s: %sis not aTN", (const struct ea *)( ((& __0__V71 )-> __O1__2ea.p =
# 1158 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__3s )), (& __0__V71 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V72 , (const void *)front ->
# 1158 "/home/claude/cfront-3/src/lalex.cpp"
retval__7toknode . s__7YYSTYPE ) , (const struct ea *)( ((& __0__V73 )-> __O1__2ea.p = ((const void *)__3s )), (& __0__V73 ))
# 1158 "/home/claude/cfront-3/src/lalex.cpp"
, (const struct ea *)ea0 ) ;
} error__FiPCc ( (int )'i' , (const char *)"cannot recover from previous errors") ;
}
else { 
# 1161 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V74 ;

# 1161 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V75 ;

# 1161 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V76 ;

# 1161 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s%s: %sis not aTN", (const struct ea *)( ((& __0__V74 )-> __O1__2ea.p =
# 1161 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__3s )), (& __0__V74 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V75 , (const void *)front ->
# 1161 "/home/claude/cfront-3/src/lalex.cpp"
retval__7toknode . s__7YYSTYPE ) , (const struct ea *)( ((& __0__V76 )-> __O1__2ea.p = ((const void *)__3s )), (& __0__V76 ))
# 1161 "/home/claude/cfront-3/src/lalex.cpp"
, (const struct ea *)ea0 ) ;
} }
else if (__2tk2 == 123 )
# 1164 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1164 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V77 ;

# 1164 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V78 ;

# 1164 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V79 ;

# 1164 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s%s: %sis not aTN", (const struct ea *)( ((& __0__V77 )-> __O1__2ea.p =
# 1164 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__3s )), (& __0__V77 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V78 , (const void *)front ->
# 1164 "/home/claude/cfront-3/src/lalex.cpp"
retval__7toknode . pn__7YYSTYPE -> __O2__4expr.string ) , (const struct ea *)( ((& __0__V79 )-> __O1__2ea.p = ((const void *)__3s )), (&
# 1164 "/home/claude/cfront-3/src/lalex.cpp"
__0__V79 )) , (const struct ea *)ea0 ) ;
} else 
# 1166 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1166 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V80 ;

# 1166 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V81 ;

# 1166 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V82 ;

# 1166 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"%s%k: %sis not aTN", (const struct ea *)( ((& __0__V80 )-> __O1__2ea.p =
# 1166 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__3s )), (& __0__V80 )) , (const struct ea *)( (__2__X95 = front -> retval__7toknode . t__7YYSTYPE ), (
# 1166 "/home/claude/cfront-3/src/lalex.cpp"
(( ((& __0__V81 )-> __O1__2ea.i = __2__X95 ), 0 ) ), (& __0__V81 )) ) , (const struct ea *)(
# 1166 "/home/claude/cfront-3/src/lalex.cpp"
((& __0__V82 )-> __O1__2ea.p = ((const void *)__3s )), (& __0__V82 )) , (const struct ea *)ea0 ) ;
} goto gettok ;
}
break ;
}
case 45 :case 44 :
# 1172 "/home/claude/cfront-3/src/lalex.cpp"
break ;
default :
# 1174 "/home/claude/cfront-3/src/lalex.cpp"
if ((lasttk == 123 )&& (__2tk2 == 73 ))
# 1175 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1176 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1176 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V83 ;

# 1176 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V84 ;

# 1176 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V85 ;

# 1176 "/home/claude/cfront-3/src/lalex.cpp"
error__FPCcRC2eaN32 ( (const char *)"T%s %k: %s is unexpected", (const struct ea *)( ((& __0__V83 )-> __O1__2ea.p =
# 1176 "/home/claude/cfront-3/src/lalex.cpp"
((const void *)__3s )), (& __0__V83 )) , (const struct ea *)( (( ((& __0__V84 )-> __O1__2ea.i = ((unsigned
# 1176 "/home/claude/cfront-3/src/lalex.cpp"
long )__2tk2 )), 0 ) ), (& __0__V84 )) , (const struct ea *)( ((& __0__V85 )-> __O1__2ea.p = ((const
# 1176 "/home/claude/cfront-3/src/lalex.cpp"
void *)__3s )), (& __0__V85 )) , (const struct ea *)ea0 ) ;
goto gettok ;
} }

# 1181 "/home/claude/cfront-3/src/lalex.cpp"
break ;
}
}
}

# 1193 "/home/claude/cfront-3/src/lalex.cpp"
}
if ((((((__1tk == 123 )|| ((__1tk == 97 )&& latype__FUc ( yylval . t__7YYSTYPE ) ))|| (__1tk == 44 ))|| (__1tk == 45 ))|| (__1tk ==
# 1194 "/home/claude/cfront-3/src/lalex.cpp"
19 ))|| (__1tk == 173 ))
# 1199 "/home/claude/cfront-3/src/lalex.cpp"
must_be_id = 1 ;
else 
# 1201 "/home/claude/cfront-3/src/lalex.cpp"
must_be_id = 0 ;

# 1203 "/home/claude/cfront-3/src/lalex.cpp"
switch (__1tk ){ 
# 1204 "/home/claude/cfront-3/src/lalex.cpp"
case 72 :
# 1206 "/home/claude/cfront-3/src/lalex.cpp"
case 41 :case 74 :must_be_expr = 0 ;

# 1206 "/home/claude/cfront-3/src/lalex.cpp"
break ;
case 69 :
# 1208 "/home/claude/cfront-3/src/lalex.cpp"
if ((lasttk == 41 )|| ((lasttk == 97 )&& (lastval . t__7YYSTYPE == 26 )))
# 1210 "/home/claude/cfront-3/src/lalex.cpp"
must_be_expr = 1 ;
break ;
case 30 :
# 1213 "/home/claude/cfront-3/src/lalex.cpp"
++ in_sizeof ;
break ;
case 23 :
# 1216 "/home/claude/cfront-3/src/lalex.cpp"
++ in_new ;
break ;
}
ret :
# 1224 "/home/claude/cfront-3/src/lalex.cpp"
lasttk = __1tk ;
lastval = yylval ;

# 1229 "/home/claude/cfront-3/src/lalex.cpp"
;

# 1231 "/home/claude/cfront-3/src/lalex.cpp"
return __1tk ;

# 1231 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 1235 "/home/claude/cfront-3/src/lalex.cpp"
void la_backup__FUc7YYSTYPE (TOK __1t , union YYSTYPE __1r )
# 1239 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1240 "/home/claude/cfront-3/src/lalex.cpp"
;
switch (__1t ){ 
# 1242 "/home/claude/cfront-3/src/lalex.cpp"
case 80 :{ Pname __3n ;

# 1242 "/home/claude/cfront-3/src/lalex.cpp"
__3n = __1r . pn__7YYSTYPE ;

# 1242 "/home/claude/cfront-3/src/lalex.cpp"
__1r . s__7YYSTYPE = __3n -> __O2__4expr.string ;

# 1242 "/home/claude/cfront-3/src/lalex.cpp"
if (__3n && (__3n -> permanent__4node == 0 ))del__4nameFv ( __3n ) ;

# 1242 "/home/claude/cfront-3/src/lalex.cpp"
break ;

# 1242 "/home/claude/cfront-3/src/lalex.cpp"
}
case 73 :-- bl_level ;

# 1243 "/home/claude/cfront-3/src/lalex.cpp"
break ;
case 74 :++ bl_level ;

# 1244 "/home/claude/cfront-3/src/lalex.cpp"
break ;
}
{ struct toknode *__1T ;

# 1246 "/home/claude/cfront-3/src/lalex.cpp"
__1T = __ct__7toknodeFUc7YYSTYPE3loc ( (struct toknode *)0 , __1t , __1r , curloc ) ;
if (front ){ 
# 1248 "/home/claude/cfront-3/src/lalex.cpp"
front -> last__7toknode = __1T ;
__1T -> next__7toknode = front ;
__1T -> last__7toknode = 0 ;
front = __1T ;
}
else front = (rear = __1T );
lasttk = 0 ;

# 1254 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFUl (struct ea *__0this , size_t __2ii );

# 1257 "/home/claude/cfront-3/src/lalex.cpp"
static int la_sctype__FUc (TOK __1t )
# 1258 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1260 "/home/claude/cfront-3/src/lalex.cpp"
if (((__1t != latok -> tok__7toknode )&& (__1t != 178 ))&& (__1t != 173 ))
# 1261 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1261 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V96 ;

# 1261 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V97 ;

# 1261 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & latok -> place__7toknode , (const char *)"la_sctype t%k, latok->tok%k", (const
# 1261 "/home/claude/cfront-3/src/lalex.cpp"
struct ea *)( (( ((& __0__V96 )-> __O1__2ea.i = ((unsigned long )__1t )), 0 ) ), (& __0__V96 )) ,
# 1261 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)__ct__2eaFUl ( & __0__V97 , (unsigned long )latok -> tok__7toknode ) , (const struct ea *)ea0 , (const
# 1261 "/home/claude/cfront-3/src/lalex.cpp"
struct ea *)ea0 ) ;
} 
# 1263 "/home/claude/cfront-3/src/lalex.cpp"
switch (latok -> retval__7toknode . t__7YYSTYPE ){ 
# 1264 "/home/claude/cfront-3/src/lalex.cpp"
case 35 :
# 1265 "/home/claude/cfront-3/src/lalex.cpp"
case 14 :
# 1266 "/home/claude/cfront-3/src/lalex.cpp"
case 31 :
# 1267 "/home/claude/cfront-3/src/lalex.cpp"
case 2 :
# 1268 "/home/claude/cfront-3/src/lalex.cpp"
case 27 :
# 1269 "/home/claude/cfront-3/src/lalex.cpp"
case 76 :
# 1270 "/home/claude/cfront-3/src/lalex.cpp"
case 75 :
# 1271 "/home/claude/cfront-3/src/lalex.cpp"
case 18 :
# 1272 "/home/claude/cfront-3/src/lalex.cpp"
case
# 1272 "/home/claude/cfront-3/src/lalex.cpp"
26 :
# 1273 "/home/claude/cfront-3/src/lalex.cpp"
case 170 :
# 1274 "/home/claude/cfront-3/src/lalex.cpp"
return 1 ;
default :
# 1276 "/home/claude/cfront-3/src/lalex.cpp"
return 0 ;
}
}

# 1281 "/home/claude/cfront-3/src/lalex.cpp"
static TOK ptname_tscope__FP7toknode (struct toknode *__1lt )
# 1282 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1283 "/home/claude/cfront-3/src/lalex.cpp"
int __1nest ;

# 1286 "/home/claude/cfront-3/src/lalex.cpp"
TOK __1tk ;

# 1283 "/home/claude/cfront-3/src/lalex.cpp"
__1nest = 0 ;
if (__1lt -> tok__7toknode != 58 )error__FiPCc ( (int )'i' , (const char *)"ptname_tscope: a `<' token was expected") ;
# 1284 "/home/claude/cfront-3/src/lalex.cpp"

# 1286 "/home/claude/cfront-3/src/lalex.cpp"
;
{ { struct toknode *__1t ;

# 1287 "/home/claude/cfront-3/src/lalex.cpp"
__1t = __1lt ;

# 1287 "/home/claude/cfront-3/src/lalex.cpp"
for(;;__1t = get_next_token__FP7toknode ( __1t ) ) { 
# 1289 "/home/claude/cfront-3/src/lalex.cpp"
switch (__1t -> tok__7toknode ){ 
# 1290 "/home/claude/cfront-3/src/lalex.cpp"
case 58 :++ __1nest ;

# 1290 "/home/claude/cfront-3/src/lalex.cpp"
continue ;
case 60 :
# 1292 "/home/claude/cfront-3/src/lalex.cpp"
if ((-- __1nest )== 0 ){ 
# 1293 "/home/claude/cfront-3/src/lalex.cpp"
__1t = get_next_token__FP7toknode ( __1t ) ;
if (__1t -> tok__7toknode == 160 ){ 
# 1295 "/home/claude/cfront-3/src/lalex.cpp"
if (__1t -> next__7toknode == 0 )add_tokens__Fv ( ) ;
if (__1t -> next__7toknode -> tok__7toknode == 50 ){ 
# 1297 "/home/claude/cfront-3/src/lalex.cpp"
__1t = __1t -> next__7toknode ;
__1tk = 173 ;
}
else __1tk = 178 ;
latok = __1t ;
return __1tk ;
}
else if ((__1t -> tok__7toknode == 173 )|| (__1t -> tok__7toknode == 178 )){ 
# 1305 "/home/claude/cfront-3/src/lalex.cpp"
latok = __1t ;
return __1t -> tok__7toknode ;
}
else 
# 1307 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1308 "/home/claude/cfront-3/src/lalex.cpp"
latok = __1t ;
return (unsigned char )209 ;
}
}
continue ;

# 1314 "/home/claude/cfront-3/src/lalex.cpp"
case 72 :case 73 :case 74 :case 0 :
# 1315 "/home/claude/cfront-3/src/lalex.cpp"
latok = __1t ;
return (unsigned char )209 ;
default :continue ;
}

# 1318 "/home/claude/cfront-3/src/lalex.cpp"
}

# 1318 "/home/claude/cfront-3/src/lalex.cpp"
}

# 1318 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 1322 "/home/claude/cfront-3/src/lalex.cpp"
int la_cast__Fv (void )
# 1327 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1330 "/home/claude/cfront-3/src/lalex.cpp"
;
{ int __1tk ;

# 1331 "/home/claude/cfront-3/src/lalex.cpp"
int __1tk2 ;

# 1331 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = latok -> tok__7toknode ;

# 1333 "/home/claude/cfront-3/src/lalex.cpp"
for(;;) { 
# 1334 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = __1tk2 ;
if (__1tk == 209 ){ 
# 1336 "/home/claude/cfront-3/src/lalex.cpp"
if (latok -> tok__7toknode == 123 )latok -> tok__7toknode = 209 ;
if (latok -> next__7toknode == 0 )add_tokens__Fv ( ) ;
__1tk2 = ptname_tscope__FP7toknode ( latok -> next__7toknode ) ;
}
else __1tk2 = lookahead__Fv ( ) ;

# 1342 "/home/claude/cfront-3/src/lalex.cpp"
switch (__1tk ){ 
# 1343 "/home/claude/cfront-3/src/lalex.cpp"
case 40 :
# 1344 "/home/claude/cfront-3/src/lalex.cpp"
if ((((__1tk2 == 50 )|| (__1tk2 == 52 ))|| (__1tk2 == 173 ))|| (__1tk2 == 209 ))
# 1348 "/home/claude/cfront-3/src/lalex.cpp"
continue ;
else 
# 1351 "/home/claude/cfront-3/src/lalex.cpp"
return 0 ;
case 50 :case 52 :case 173 :
# 1353 "/home/claude/cfront-3/src/lalex.cpp"
while ((__1tk2 == 97 )&& la_sctype__FUc ( (unsigned char )__1tk2 ) )
# 1356 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = lookahead__Fv ( ) ;
# 1356 "/home/claude/cfront-3/src/lalex.cpp"

# 1357 "/home/claude/cfront-3/src/lalex.cpp"
continue ;
case 209 :
# 1360 "/home/claude/cfront-3/src/lalex.cpp"
if (__1tk2 == 173 )continue ;
return 0 ;
case 41 :case 42 :
# 1365 "/home/claude/cfront-3/src/lalex.cpp"
return 1 ;
default :
# 1367 "/home/claude/cfront-3/src/lalex.cpp"
return 0 ;
}
}

# 1369 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 58 "/home/claude/cfront-3/src/tqueue.h"
extern void UNSET_SCOPE__Fv (void );

# 57 "/home/claude/cfront-3/src/tqueue.h"
extern Pname SET_SCOPE__FP4name (Pname );

# 1378 "/home/claude/cfront-3/src/lalex.cpp"
static int la_decl__Fi (int __1arg_decl )
# 1390 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1392 "/home/claude/cfront-3/src/lalex.cpp"
;
{ int __1tk ;

# 1393 "/home/claude/cfront-3/src/lalex.cpp"
int __1tk2 ;
int __1paren ;
int __1ptr ;
static int __1scopesets = 0 ;

# 1393 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = latok -> tok__7toknode ;
__1paren = 0 ;
__1ptr = 0 ;

# 1398 "/home/claude/cfront-3/src/lalex.cpp"
if (__1tk2 != 40 ){ 
# 1398 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V98 ;

# 1398 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'d' , & latok -> place__7toknode , (const char *)"la_decl(): latok ==%k -- '(' expected", (const
# 1398 "/home/claude/cfront-3/src/lalex.cpp"
struct ea *)( (( ((& __0__V98 )-> __O1__2ea.i = ((unsigned long )__1tk2 )), 0 ) ), (& __0__V98 )) ,
# 1398 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1400 "/home/claude/cfront-3/src/lalex.cpp"
for(;;) { 
# 1402 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = __1tk2 ;
if (__1tk == 209 ){ 
# 1404 "/home/claude/cfront-3/src/lalex.cpp"
if (latok -> tok__7toknode == 123 )latok -> tok__7toknode = 209 ;
if (latok -> next__7toknode == 0 )add_tokens__Fv ( ) ;
__1tk2 = ptname_tscope__FP7toknode ( latok -> next__7toknode ) ;
}
else __1tk2 = lookahead__Fv ( ) ;

# 1410 "/home/claude/cfront-3/src/lalex.cpp"
switch (__1tk ){ 
# 1411 "/home/claude/cfront-3/src/lalex.cpp"
case 40 :
# 1412 "/home/claude/cfront-3/src/lalex.cpp"
if (__1tk2 == 41 ){ 
# 1413 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1413 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
if ((__1paren && (__1ptr == 0 ))&& __1arg_decl ){ 
# 1418 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1418 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
++ __1paren ;
__1ptr = 0 ;
continue ;
case 50 :case 52 :
# 1425 "/home/claude/cfront-3/src/lalex.cpp"
__1ptr = 1 ;
if ((__1tk2 == 97 )&& la_sctype__FUc ( (unsigned char )__1tk2 ) ){ 
# 1429 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
# 1429 "/home/claude/cfront-3/src/lalex.cpp"
while (-- __1scopesets );

# 1429 "/home/claude/cfront-3/src/lalex.cpp"
;
return 1 ;
}
else 
# 1431 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1432 "/home/claude/cfront-3/src/lalex.cpp"
continue ;
}
case 173 :
# 1436 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1436 "/home/claude/cfront-3/src/lalex.cpp"
;
return 1 ;
case 178 :
# 1439 "/home/claude/cfront-3/src/lalex.cpp"
if (((__1tk2 == 80 )|| (__1tk2 == 24 ))&& (! __1arg_decl )){ 
# 1441 "/home/claude/cfront-3/src/lalex.cpp"
if ((latok -> last__7toknode -> last__7toknode -> tok__7toknode == 123 )&&
# 1441 "/home/claude/cfront-3/src/lalex.cpp"
SET_SCOPE__FP4name ( latok -> last__7toknode -> last__7toknode -> retval__7toknode . pn__7YYSTYPE ) )
# 1443 "/home/claude/cfront-3/src/lalex.cpp"
++ __1scopesets ;
continue ;
}
else 
# 1445 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1447 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1447 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
case 209 :
# 1451 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1tk2 == 178 )&& (! __1arg_decl )){ 
# 1452 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__4t ;

# 1452 "/home/claude/cfront-3/src/lalex.cpp"
__4t = latok ;
__1tk = __1tk2 ;

# 1453 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = lookahead__Fv ( ) ;
if ((__1tk2 == 80 )|| (__1tk2 == 24 )){ 
# 1456 "/home/claude/cfront-3/src/lalex.cpp"
if (SET_SCOPE__FP4name ( __4t -> retval__7toknode . pn__7YYSTYPE ) )
# 1457 "/home/claude/cfront-3/src/lalex.cpp"
++ __1scopesets ;
continue ;
}
else 
# 1459 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1461 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1461 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
}
else 
# 1464 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1465 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1465 "/home/claude/cfront-3/src/lalex.cpp"
;
return (__1tk2 == 173 );
}
}

# 1470 "/home/claude/cfront-3/src/lalex.cpp"
break ;
}

# 1473 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1tk == 41 )|| (__1tk == 42 )){ 
# 1476 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1476 "/home/claude/cfront-3/src/lalex.cpp"
;
return 1 ;
}

# 1480 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1tk != 80 )&& (__1tk != 24 )){ 
# 1482 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1482 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}

# 1486 "/home/claude/cfront-3/src/lalex.cpp"
if ((((__1tk == 80 )&& (__1tk2 == 41 ))&& __1arg_decl )&& (! __1ptr )){ 
# 1487 "/home/claude/cfront-3/src/lalex.cpp"
TOK __2nt ;

# 1487 "/home/claude/cfront-3/src/lalex.cpp"
__2nt = lookahead__Fv ( ) ;
latok = latok -> last__7toknode ;
if (__2nt == 40 ){ 
# 1490 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1490 "/home/claude/cfront-3/src/lalex.cpp"
;
return 1 ;
}
}

# 1495 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1ptr == 0 )&& __1arg_decl ){ 
# 1497 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1497 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}

# 1501 "/home/claude/cfront-3/src/lalex.cpp"
if (__1tk == 24 ){ 
# 1502 "/home/claude/cfront-3/src/lalex.cpp"
switch (__1tk2 ){ 
# 1503 "/home/claude/cfront-3/src/lalex.cpp"
case 54 :case 55 :case 50 :case 180 :
# 1504 "/home/claude/cfront-3/src/lalex.cpp"
case 52 :case 65 :case 64 :case 94 :case
# 1504 "/home/claude/cfront-3/src/lalex.cpp"
92 :
# 1505 "/home/claude/cfront-3/src/lalex.cpp"
case 93 :case 91 :case 66 :case 67 :
# 1506 "/home/claude/cfront-3/src/lalex.cpp"
case 46 :case 47 :case 95 :case 70 :
# 1507 "/home/claude/cfront-3/src/lalex.cpp"
case 90 :case 23 :case 213 :case 184 :
# 1508 "/home/claude/cfront-3/src/lalex.cpp"
case 9 :case
# 1508 "/home/claude/cfront-3/src/lalex.cpp"
212 :
# 1510 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = lookahead__Fv ( ) ;
break ;
case 40 :
# 1514 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = lookahead__Fv ( ) ;
if (__1tk2 == 41 ){ 
# 1516 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = lookahead__Fv ( ) ;
break ;
}
else 
# 1518 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1519 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1519 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
case 42 :
# 1524 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = lookahead__Fv ( ) ;
if (__1tk2 == 43 ){ 
# 1526 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = lookahead__Fv ( ) ;
break ;
}
else 
# 1528 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1529 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1529 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
default :
# 1533 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1533 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
}

# 1538 "/home/claude/cfront-3/src/lalex.cpp"
{ int __1allow_lp ;
int __1allow_rp ;
int __1pd ;

# 1538 "/home/claude/cfront-3/src/lalex.cpp"
__1allow_lp = 1 ;
__1allow_rp = 1 ;
__1pd = __1paren ;
for(;;) { 
# 1542 "/home/claude/cfront-3/src/lalex.cpp"
__1tk = __1tk2 ;
if (((__1tk == 40 )|| (__1tk == 42 ))|| (__1tk == 41 ))
# 1544 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = lookahead__Fv ( ) ;

# 1548 "/home/claude/cfront-3/src/lalex.cpp"
switch (__1tk ){ 
# 1549 "/home/claude/cfront-3/src/lalex.cpp"
case 40 :
# 1550 "/home/claude/cfront-3/src/lalex.cpp"
if (! __1allow_lp ){ 
# 1552 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1552 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}

# 1558 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1tk2 == 41 )&& __1paren ){ 
# 1559 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = lookahead__Fv ( ) ;
__1allow_lp = 0 ;
__1allow_rp = 1 ;
continue ;
}
if (((((__1tk2 == 41 )|| (__1tk2 == 13 ))|| (__1tk2 == 156 ))|| (__1tk2 == 155 ))|| ((__1tk2 == 97 )&& la_sctype__FUc ( (unsigned char
# 1564 "/home/claude/cfront-3/src/lalex.cpp"
)__1tk2 ) ))
# 1565 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1568 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1568 "/home/claude/cfront-3/src/lalex.cpp"
;
return 1 ;
}

# 1572 "/home/claude/cfront-3/src/lalex.cpp"
if (__1tk2 == 178 ){ 
# 1573 "/home/claude/cfront-3/src/lalex.cpp"
ts :do { 
# 1574 "/home/claude/cfront-3/src/lalex.cpp"
__1tk2 = lookahead__Fv ( ) ;
}
while (__1tk2 == 178 );

# 1576 "/home/claude/cfront-3/src/lalex.cpp"
if (__1tk2 == 123 ){ 
# 1577 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__5T ;

# 1577 "/home/claude/cfront-3/src/lalex.cpp"
__5T = latok ;
if ((lookahead__Fv ( ) == 40 )&& (! la_decl__Fi ( 1 ) )){ 
# 1579 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( )
# 1579 "/home/claude/cfront-3/src/lalex.cpp"
;
while (-- __1scopesets );

# 1579 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
la_reset__FP7toknodeP4name ( __5T -> next__7toknode , __5T -> retval__7toknode . pn__7YYSTYPE ) ;
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1583 "/home/claude/cfront-3/src/lalex.cpp"
;
return 1 ;
}
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1586 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
if (__1tk2 == 209 ){ 
# 1590 "/home/claude/cfront-3/src/lalex.cpp"
if (latok -> tok__7toknode == 123 )latok -> tok__7toknode = 209 ;
if (latok -> next__7toknode == 0 )add_tokens__Fv ( ) ;
__1tk2 = ptname_tscope__FP7toknode ( latok -> next__7toknode ) ;
switch (__1tk2 ){ 
# 1594 "/home/claude/cfront-3/src/lalex.cpp"
case 178 :
# 1595 "/home/claude/cfront-3/src/lalex.cpp"
goto ts ;
case 123 :
# 1597 "/home/claude/cfront-3/src/lalex.cpp"
break ;
default :
# 1599 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1599 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
}
if ((__1tk2 == 97 )|| (__1tk2 == 123 )){ 
# 1605 "/home/claude/cfront-3/src/lalex.cpp"
if ((lookahead__Fv ( ) == 40 )&& (! la_decl__Fi ( 1 ) )){
# 1605 "/home/claude/cfront-3/src/lalex.cpp"

# 1606 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1606 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1609 "/home/claude/cfront-3/src/lalex.cpp"
;
return 1 ;
}

# 1613 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1613 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
case 42 :
# 1616 "/home/claude/cfront-3/src/lalex.cpp"
if (__1paren == 0 ){ 
# 1617 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1617 "/home/claude/cfront-3/src/lalex.cpp"
;
return 1 ;
}
if (__1tk2 == 43 ){ 
# 1622 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1622 "/home/claude/cfront-3/src/lalex.cpp"
;
return 1 ;
}
else { 
# 1627 "/home/claude/cfront-3/src/lalex.cpp"
__1allow_lp = 0 ;
__1allow_rp = 1 ;

# 1630 "/home/claude/cfront-3/src/lalex.cpp"
while ((lookahead__Fv ( ) != 43 )&& (latok -> tok__7toknode != 0 ));
__1tk2 = lookahead__Fv ( ) ;
continue ;
}
case 41 :
# 1636 "/home/claude/cfront-3/src/lalex.cpp"
if ((! __1allow_rp )|| (! __1paren )){ 
# 1638 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1638 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
else 
# 1643 "/home/claude/cfront-3/src/lalex.cpp"
if (((__1tk2 == 72 )|| (__1tk2 == 71 ))|| (__1tk2 == 70 )){ 
# 1644 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
# 1644 "/home/claude/cfront-3/src/lalex.cpp"
while (-- __1scopesets );

# 1644 "/home/claude/cfront-3/src/lalex.cpp"
;

# 1648 "/home/claude/cfront-3/src/lalex.cpp"
if (((! __1arg_decl )&& ((__1pd == 1 )&& (! __1ptr )))&& (! strict_opt ))
# 1649 "/home/claude/cfront-3/src/lalex.cpp"
error__FiPCc ( (int )'w' , (const char *)"T(id) (anachronism; will be declaration in future)")
# 1649 "/home/claude/cfront-3/src/lalex.cpp"
;
return ((! __1arg_decl )&& ((__1pd > (strict_opt ?0 :1 ))|| __1ptr ));
}
else 
# 1653 "/home/claude/cfront-3/src/lalex.cpp"
if ((__1tk2 == 41 )&& ((bl_level - in_class_decl )== 0 )){ 
# 1654 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1654 "/home/claude/cfront-3/src/lalex.cpp"
;
return (! __1arg_decl );
}
else { 
# 1659 "/home/claude/cfront-3/src/lalex.cpp"
-- __1paren ;
__1allow_lp = 1 ;
__1allow_rp = (__1paren > 0 );
continue ;
}
default :
# 1665 "/home/claude/cfront-3/src/lalex.cpp"
if (__1scopesets > 0 )do UNSET_SCOPE__Fv ( ) ;
while (-- __1scopesets );

# 1665 "/home/claude/cfront-3/src/lalex.cpp"
;
return 0 ;
}
}

# 1668 "/home/claude/cfront-3/src/lalex.cpp"
}

# 1668 "/home/claude/cfront-3/src/lalex.cpp"
}
}

# 1676 "/home/claude/cfront-3/src/lalex.cpp"
static int la_snarf__Fv (void );

# 1679 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *save_text__Fv (void )
# 1683 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1686 "/home/claude/cfront-3/src/lalex.cpp"
;
;
;
latok = front -> next__7toknode ;
if (la_snarf__Fv ( ) ){ 
# 1693 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__2t ;

# 1693 "/home/claude/cfront-3/src/lalex.cpp"
__2t = front ;
if (ccl -> c_funqf__8classdef == 0 )
# 1695 "/home/claude/cfront-3/src/lalex.cpp"
ccl -> c_funqf__8classdef = front ;
else { 
# 1697 "/home/claude/cfront-3/src/lalex.cpp"
ccl -> c_funqr__8classdef -> next__7toknode = front ;
front -> last__7toknode = ccl -> c_funqr__8classdef ;
}
ccl -> c_funqr__8classdef = latok ;
front = latok -> next__7toknode ;
latok -> next__7toknode = 0 ;
if (front )front -> last__7toknode = 0 ;
return __2t ;
}
return (struct toknode *)0 ;
}

# 1711 "/home/claude/cfront-3/src/lalex.cpp"
void restore_text__Fv (void )
# 1715 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1716 "/home/claude/cfront-3/src/lalex.cpp"
;
if (ccl -> c_funqf__8classdef == 0 )
# 1718 "/home/claude/cfront-3/src/lalex.cpp"
return ;
;
;
;
ccl -> c_funqr__8classdef -> next__7toknode = front ;
if (front )front -> last__7toknode = ccl -> c_funqr__8classdef ;
front = ccl -> c_funqf__8classdef ;
ccl -> c_funqf__8classdef = (ccl -> c_funqr__8classdef = 0 );
}

# 157 "/home/claude/cfront-3/src/lalex.cpp"

# 34 "/home/claude/cfront-3/src/tqueue.h"

# 1730 "/home/claude/cfront-3/src/lalex.cpp"
static int la_snarf__Fv (void )
# 1734 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1735 "/home/claude/cfront-3/src/lalex.cpp"
;
{ struct loc *__1L ;

# 1738 "/home/claude/cfront-3/src/lalex.cpp"
int __1level ;
int __1parens ;
int __1paren_error ;
struct toknode *__1marker ;

# 1736 "/home/claude/cfront-3/src/lalex.cpp"
__1L = (& latok -> place__7toknode );

# 1739 "/home/claude/cfront-3/src/lalex.cpp"
__1parens = 0 ;
__1paren_error = 0 ;
__1marker = latok ;
switch (latok -> tok__7toknode ){ 
# 1742 "/home/claude/cfront-3/src/lalex.cpp"
unsigned long __2__X100 ;

# 1743 "/home/claude/cfront-3/src/lalex.cpp"
default :
# 1744 "/home/claude/cfront-3/src/lalex.cpp"
{ 
# 1744 "/home/claude/cfront-3/src/lalex.cpp"
struct ea __0__V99 ;

# 1744 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , __1L , (const char *)"bad token Q snarfing function: %d", (const struct ea *)(
# 1744 "/home/claude/cfront-3/src/lalex.cpp"
(__2__X100 = latok -> tok__7toknode ), ( (( ((& __0__V99 )-> __O1__2ea.i = __2__X100 ), 0 ) ), (& __0__V99 )) )
# 1744 "/home/claude/cfront-3/src/lalex.cpp"
, (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
case 69 :
# 1746 "/home/claude/cfront-3/src/lalex.cpp"
__1level = 0 ;
break ;
case 73 :
# 1749 "/home/claude/cfront-3/src/lalex.cpp"
__1level = 1 ;
goto eatf ;
} }
;
for(;;) { 
# 1754 "/home/claude/cfront-3/src/lalex.cpp"
if (latok -> next__7toknode == 0 )add_tokens__Fv ( ) ;
switch ((latok = latok -> next__7toknode )-> tok__7toknode ){ 
# 1756 "/home/claude/cfront-3/src/lalex.cpp"
case 40 :
# 1757 "/home/claude/cfront-3/src/lalex.cpp"
++ __1parens ;
default :
# 1759 "/home/claude/cfront-3/src/lalex.cpp"
;
continue ;
case 41 :
# 1762 "/home/claude/cfront-3/src/lalex.cpp"
if (((-- __1parens )< 0 )&& ((__1paren_error ++ )== 0 ))
# 1763 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( 0 , & latok -> place__7toknode , (const char
# 1763 "/home/claude/cfront-3/src/lalex.cpp"
*)"unbalanced ()", (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1763 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 ) ;
continue ;
case 73 :
# 1766 "/home/claude/cfront-3/src/lalex.cpp"
++ __1level ;
if (__1parens <= 0 )
# 1768 "/home/claude/cfront-3/src/lalex.cpp"
goto eatf ;
continue ;
case 74 :
# 1771 "/home/claude/cfront-3/src/lalex.cpp"
if ((-- __1level )< 0 ){ 
# 1772 "/home/claude/cfront-3/src/lalex.cpp"
error__FP3locPCcRC2eaN33 ( & latok -> place__7toknode , (const char *)"unexpected '}'",
# 1772 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
goto bad ;
}
if (__1parens <= 0 )
# 1776 "/home/claude/cfront-3/src/lalex.cpp"
goto eatf ;
continue ;
case 72 :
# 1779 "/home/claude/cfront-3/src/lalex.cpp"
if (__1parens <= 0 ){ 
# 1779 "/home/claude/cfront-3/src/lalex.cpp"
struct toknode *__0__X101 ;

# 1780 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( 0 , __1L , (const char *)"illegal bit field", (const struct ea *)ea0 , (const
# 1780 "/home/claude/cfront-3/src/lalex.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
del_tokens__FP7toknode ( front ) ;
( (__0__X101 = front ), ( (__0__X101 ?(((void )(__0__X101 ?(((void )(((void )__dl__7toknodeSFPvUl ( (void *)__0__X101 , (size_t )(sizeof (struct toknode)))
# 1782 "/home/claude/cfront-3/src/lalex.cpp"
)))):(((void )0 ))))):(((void )0 )))) ) ;
front = latok ;
front -> last__7toknode = 0 ;
return 0 ;
}
continue ;
case 0 :
# 1789 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'i' , & latok -> place__7toknode , (const char *)"unexpected end of file",
# 1789 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
}
}

# 1793 "/home/claude/cfront-3/src/lalex.cpp"
eatf :
# 1794 "/home/claude/cfront-3/src/lalex.cpp"
for(;;) { 
# 1795 "/home/claude/cfront-3/src/lalex.cpp"
if (latok -> next__7toknode == 0 )add_tokens__Fv ( ) ;
switch ((latok = latok -> next__7toknode )-> tok__7toknode ){ 
# 1797 "/home/claude/cfront-3/src/lalex.cpp"
case 73 :
# 1798 "/home/claude/cfront-3/src/lalex.cpp"
++ __1level ;
default :
# 1800 "/home/claude/cfront-3/src/lalex.cpp"
;
continue ;
case 74 :
# 1803 "/home/claude/cfront-3/src/lalex.cpp"
;
if ((-- __1level )<= 0 ){ 
# 1805 "/home/claude/cfront-3/src/lalex.cpp"
if (__1level < 0 ){ 
# 1806 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( 0 , & latok -> place__7toknode , (const char
# 1806 "/home/claude/cfront-3/src/lalex.cpp"
*)"unexpected '}'", (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 1806 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 ) ;
goto bad ;
}
return 1 ;
}
break ;
case 0 :
# 1813 "/home/claude/cfront-3/src/lalex.cpp"
error__FiP3locPCcRC2eaN34 ( (int )'e' , & latok -> place__7toknode , (const char *)"unbalanced {}",
# 1813 "/home/claude/cfront-3/src/lalex.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
goto bad ;
}
}
bad :
# 1818 "/home/claude/cfront-3/src/lalex.cpp"
del_tokens__FP7toknode ( __1marker ) ;
__1marker -> tok__7toknode = 72 ;
return 0 ;

# 1820 "/home/claude/cfront-3/src/lalex.cpp"
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

# 1821 "/home/claude/cfront-3/src/lalex.cpp"

/* the end */
