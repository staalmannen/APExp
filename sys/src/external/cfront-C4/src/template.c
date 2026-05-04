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

# 1 ""
extern void *__nw__FUl (size_t );

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
enum discriminator_error { discrim_none_valid = 0, discrim_bad_index = -1, discrim_inconsistent_node = -2} ;
enum node_class { nc_unused = 0, nc_eof = 1, nc_virt = 2, nc_nlist = 3, nc_gen = 4, nc_vec = 5, nc_ptr = 6, nc_fct = 7, nc_table = 8, nc_basetype = 9, nc_name = 10, nc_expr = 11, nc_stmt = 12, nc_enumdef = 13,
# 226 "/home/claude/cfront-3/src/cfront.h"
nc_classdef = 14, nc_baseclass = 15, nc_iline = 16, nc_ia = 17, nc_tpdef = 18, nc_ktable = 19} ;
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
struct tree_copy_info;

# 30 "/home/claude/cfront-3/src/tree_copy.h"
struct tree_copy_info {	/* sizeof tree_copy_info == 24 */

# 42 "/home/claude/cfront-3/src/tree_copy.h"
void (*node_hook__14tree_copy_info )(void *__1info , Pnode *, int , int *, int *);

# 48 "/home/claude/cfront-3/src/tree_copy.h"
char *(*malloc_hook__14tree_copy_info )(void *__1info , size_t );
void *hook_info__14tree_copy_info ;
};

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

# 45 "/home/claude/cfront-3/src/template.cpp"
extern int bound ;
bit tempdcl = 0 ;
static Ptempl_inst dummyinst = 0 ;
static Ptempl_inst curr_inst = 0 ;
static Pfunct_inst fdummyinst = 0 ;
static Pfunct_inst fcurr_inst = 0 ;
static bit notinstflag = 0 ;

# 54 "/home/claude/cfront-3/src/template.cpp"
Ptable bound_expr_tbl = 0 ;

# 56 "/home/claude/cfront-3/src/template.cpp"

# 58 "/home/claude/cfront-3/src/template.cpp"

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

# 61 "/home/claude/cfront-3/src/template.cpp"
Pfunt f_list__17templ_compilation = 0 ;
Pbase_inst head__10basic_inst = 0 ;
Ptempl list__17templ_compilation = 0 ;
Pcons last_cons__17templ_compilation = 0 ;
Pcons last_friend_cons__17templ_compilation = 0 ;
Pcons templ_refs__17templ_compilation = 0 ;
Pcons friend_templ_refs__17templ_compilation = 0 ;
Ptstate save_templ__17templ_compilation = 0 ;
Ptempl_base parsed_template__17templ_compilation = 0 ;
Pfunt f_owner__17templ_compilation = 0 ;
Ptempl owner__17templ_compilation = 0 ;
Plist param_end__17templ_compilation = 0 ;
Plist params__17templ_compilation = 0 ;
Pexpr actuals__17templ_compilation = 0 ;
int formals_in_progress__17templ_compilation = 0;

# 78 "/home/claude/cfront-3/src/template.cpp"
struct templ_compilation *templp = 0 ;
Ptable templates__17templ_compilation = 0 ;

# 83 "/home/claude/cfront-3/src/template.cpp"
void save__5stateFv (register struct state *__0this ){ 
# 84 "/home/claude/cfront-3/src/template.cpp"
__0this -> Cdcl__5state = Cdcl ;
__0this -> Cstmt__5state = Cstmt ;
__0this -> curloc__5state = curloc ;

# 88 "/home/claude/cfront-3/src/template.cpp"
__0this -> curr_file__5state = curr_file ;
__0this -> curr_expr__5state = curr_expr ;
__0this -> curr_icall__5state = curr_icall ;
__0this -> curr_loop__5state = curr_loop ;
__0this -> curr_block__5state = curr_block ;
__0this -> curr_switch__5state = curr_switch ;

# 95 "/home/claude/cfront-3/src/template.cpp"
__0this -> bound__5state = bound ;
__0this -> inline_restr__5state = inline_restr ;
__0this -> last_line__5state = last_line ;
}

# 101 "/home/claude/cfront-3/src/template.cpp"
void restore__5stateFv (register struct state *__0this ){ 
# 102 "/home/claude/cfront-3/src/template.cpp"
Cdcl = __0this -> Cdcl__5state ;
Cstmt = __0this -> Cstmt__5state ;
curloc = __0this -> curloc__5state ;

# 106 "/home/claude/cfront-3/src/template.cpp"
curr_file = __0this -> curr_file__5state ;
curr_expr = __0this -> curr_expr__5state ;
curr_icall = __0this -> curr_icall__5state ;
curr_loop = __0this -> curr_loop__5state ;
curr_block = __0this -> curr_block__5state ;
curr_switch = __0this -> curr_switch__5state ;

# 113 "/home/claude/cfront-3/src/template.cpp"
bound = __0this -> bound__5state ;
inline_restr = __0this -> inline_restr__5state ;
last_line = __0this -> last_line__5state ;
}

# 119 "/home/claude/cfront-3/src/template.cpp"
void init__5stateFv (struct state *__0this ){ 
# 120 "/home/claude/cfront-3/src/template.cpp"
bound = 0 ;
inline_restr = 0 ;

# 123 "/home/claude/cfront-3/src/template.cpp"
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 139 "/home/claude/cfront-3/src/template.cpp"
int get_class_base__FP8basetype (Pbase __1b ){ 
# 139 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X27 ;

# 140 "/home/claude/cfront-3/src/template.cpp"
if (__1b -> base__4node != 119 )
# 141 "/home/claude/cfront-3/src/template.cpp"
{ 
# 141 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V26 ;

# 141 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"::get_class_base: badAT(%k) cobjX", (const struct ea *)( (__2__X27 =
# 141 "/home/claude/cfront-3/src/template.cpp"
__1b -> base__4node ), ( (( ((& __0__V26 )-> __O1__2ea.i = __2__X27 ), 0 ) ), (& __0__V26 )) ) ,
# 141 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} return (((struct templ_classdef *)(((struct templ_classdef *)(((struct basetype *)(((struct basetype *)__1b ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> class_base__8classdef ;
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 146 "/home/claude/cfront-3/src/template.cpp"
int get_templ_base__FP8basetype (Pbase __1b ){ 
# 146 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X29 ;

# 147 "/home/claude/cfront-3/src/template.cpp"
if (__1b -> base__4node != 119 )
# 148 "/home/claude/cfront-3/src/template.cpp"
{ 
# 148 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V28 ;

# 148 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"::get_templ_base: badAT(%k) cobjX", (const struct ea *)( (__2__X29 =
# 148 "/home/claude/cfront-3/src/template.cpp"
__1b -> base__4node ), ( (( ((& __0__V28 )-> __O1__2ea.i = __2__X29 ), 0 ) ), (& __0__V28 )) ) ,
# 148 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} return (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1b ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> templ_base__4type ;
}

# 153 "/home/claude/cfront-3/src/template.cpp"
Ptclass get_template_class__FP8basetype (Pbase __1b ){ 
# 154 "/home/claude/cfront-3/src/template.cpp"
int __1t ;

# 154 "/home/claude/cfront-3/src/template.cpp"
__1t = get_class_base__FP8basetype ( __1b ) ;
if (! ((__1t == 4)|| (__1t == 5)))
# 156 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"C is not aYC")
# 156 "/home/claude/cfront-3/src/template.cpp"
;
return (((struct templ_classdef *)(((struct templ_classdef *)(((struct basetype *)(((struct basetype *)__1b ))))-> b_name__8basetype -> __O1__4expr.tp ))));
}

# 168 "/home/claude/cfront-3/src/template.cpp"
static bit same_class_templ__FP8classdefT1 (Pclass __1c1 , Pclass __1c2 )
# 169 "/home/claude/cfront-3/src/template.cpp"
{ 
# 171 "/home/claude/cfront-3/src/template.cpp"
if (__1c1 == __1c2 )return (unsigned char )1;

# 173 "/home/claude/cfront-3/src/template.cpp"
if (((__1c1 -> class_base__8classdef == 4)&& (__1c2 -> class_base__8classdef == 5))&& ((((struct templ_classdef *)(((struct templ_classdef *)__1c1 ))))-> inst__14templ_classdef -> def__10templ_inst == (((struct templ_classdef *)(((struct
# 173 "/home/claude/cfront-3/src/template.cpp"
templ_classdef *)__1c2 ))))-> inst__14templ_classdef -> def__10templ_inst ))
# 176 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )1;

# 178 "/home/claude/cfront-3/src/template.cpp"
if (((__1c2 -> class_base__8classdef == 4)&& (__1c1 -> class_base__8classdef == 5))&& ((((struct templ_classdef *)(((struct templ_classdef *)__1c1 ))))-> inst__14templ_classdef -> def__10templ_inst == (((struct templ_classdef *)(((struct
# 178 "/home/claude/cfront-3/src/template.cpp"
templ_classdef *)__1c2 ))))-> inst__14templ_classdef -> def__10templ_inst ))
# 181 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )1;

# 183 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )0;
}

# 21 "/home/claude/incl-linux32/string.h"
extern int strcmp (const char *, const char *);

# 438 "/home/claude/cfront-3/src/template.h"

# 442 "/home/claude/cfront-3/src/template.h"
int same__10templ_instFP10templ_inst (struct templ_inst *__0this , Ptempl_inst __1t );

# 187 "/home/claude/cfront-3/src/template.cpp"
bit same_class__8classdefFP8classdefi (register struct classdef *__0this , Pclass __1pc , int __1access )
# 213 "/home/claude/cfront-3/src/template.cpp"
{ 
# 216 "/home/claude/cfront-3/src/template.cpp"
if (__0this == 0 )return (unsigned char )0;
if (__1pc == 0 )return (unsigned char )0;
if (__0this == __1pc )return (unsigned char )1;

# 220 "/home/claude/cfront-3/src/template.cpp"
if ((__0this -> class_base__8classdef == 0)&& (__1pc -> class_base__8classdef == 0))
# 221 "/home/claude/cfront-3/src/template.cpp"
{ 
# 222 "/home/claude/cfront-3/src/template.cpp"
if (__0this -> local_sig__4type && __1pc -> local_sig__4type )
# 223 "/home/claude/cfront-3/src/template.cpp"
{ 
# 224 "/home/claude/cfront-3/src/template.cpp"
return (unsigned
# 224 "/home/claude/cfront-3/src/template.cpp"
char )(strcmp ( (const char *)__0this -> local_sig__4type , (const char *)__1pc -> local_sig__4type ) == 0 );
}
if (__0this -> nested_sig__4type && __1pc -> nested_sig__4type )
# 227 "/home/claude/cfront-3/src/template.cpp"
{ 
# 228 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )(strcmp ( (const char *)__0this -> nested_sig__4type , (const
# 228 "/home/claude/cfront-3/src/template.cpp"
char *)__1pc -> nested_sig__4type ) == 0 );
}
if ((__0this -> local_sig__4type == __1pc -> local_sig__4type )&& (__0this -> nested_sig__4type == __1pc -> nested_sig__4type ))
# 231 "/home/claude/cfront-3/src/template.cpp"
{ 
# 232 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )(strcmp ( __0this ->
# 232 "/home/claude/cfront-3/src/template.cpp"
string__8classdef , __1pc -> string__8classdef ) == 0 );
}
return (unsigned char )0;
}

# 237 "/home/claude/cfront-3/src/template.cpp"
{ int __1this_base ;
int __1pc_base ;

# 239 "/home/claude/cfront-3/src/template.cpp"
struct templ_inst *__0__X30 ;

# 239 "/home/claude/cfront-3/src/template.cpp"
struct templ_inst *__0__X31 ;

# 237 "/home/claude/cfront-3/src/template.cpp"
__1this_base = __0this -> class_base__8classdef ;
__1pc_base = __1pc -> class_base__8classdef ;

# 240 "/home/claude/cfront-3/src/template.cpp"
if (((__1this_base == 2)&& (__1pc_base == 4))&& (( (__0__X30 = (((struct templ_classdef *)(((struct templ_classdef *)__1pc ))))-> inst__14templ_classdef ), ( __0__X30 -> def__10templ_inst ->
# 240 "/home/claude/cfront-3/src/template.cpp"
basep__5templ ) ) -> b_name__8basetype -> __O1__4expr.tp == (((struct type *)__0this ))))
# 243 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )1;

# 246 "/home/claude/cfront-3/src/template.cpp"
if (((__1pc_base == 2)&& (__1this_base == 4))&& (( (__0__X31 = (((struct templ_classdef *)(((struct templ_classdef *)__0this ))))-> inst__14templ_classdef ), ( __0__X31 -> def__10templ_inst ->
# 246 "/home/claude/cfront-3/src/template.cpp"
basep__5templ ) ) -> b_name__8basetype -> __O1__4expr.tp == (((struct type *)__1pc ))))
# 249 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )1;

# 253 "/home/claude/cfront-3/src/template.cpp"
if (((__1pc_base == 4)&& (__1this_base == 4))&& ((strcmp ( __1pc -> string__8classdef , __0this -> string__8classdef ) == 0 )|| same__10templ_instFP10templ_inst ( (((struct
# 253 "/home/claude/cfront-3/src/template.cpp"
templ_classdef *)(((struct templ_classdef *)__0this ))))-> inst__14templ_classdef , (((struct templ_classdef *)(((struct templ_classdef *)__1pc ))))-> inst__14templ_classdef ) ))
# 257 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )1;

# 259 "/home/claude/cfront-3/src/template.cpp"
if (__1access == 0 )return (unsigned char )0;

# 263 "/home/claude/cfront-3/src/template.cpp"
if ((__1this_base == 4)&& (__1pc_base == 5))
# 264 "/home/claude/cfront-3/src/template.cpp"
{ 
# 265 "/home/claude/cfront-3/src/template.cpp"
const char *__2str ;

# 265 "/home/claude/cfront-3/src/template.cpp"
__2str = (((struct templ_classdef *)(((struct templ_classdef *)__0this ))))-> inst__14templ_classdef -> def__10templ_inst -> namep__5templ -> __O2__4expr.string ;

# 267 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )(strcmp ( __2str , __1pc -> string__8classdef ) == 0 );
}

# 270 "/home/claude/cfront-3/src/template.cpp"
if ((__1pc_base == 4)&& (__1this_base == 5))
# 271 "/home/claude/cfront-3/src/template.cpp"
{ 
# 272 "/home/claude/cfront-3/src/template.cpp"
const char *__2str ;

# 272 "/home/claude/cfront-3/src/template.cpp"
__2str = (((struct templ_classdef *)(((struct templ_classdef *)__1pc ))))-> inst__14templ_classdef -> def__10templ_inst -> namep__5templ -> __O2__4expr.string ;

# 274 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )(strcmp ( __2str , __0this -> string__8classdef ) == 0 );
}
return (unsigned char )0;

# 276 "/home/claude/cfront-3/src/template.cpp"
}
}

# 280 "/home/claude/cfront-3/src/template.cpp"
int same__10templ_instFP10templ_inst (register struct templ_inst *__0this , Ptempl_inst __1t )
# 283 "/home/claude/cfront-3/src/template.cpp"
{ 
# 284 "/home/claude/cfront-3/src/template.cpp"
return (int )((((__0this -> forward__10templ_inst && (__0this -> forward__10templ_inst == __1t -> forward__10templ_inst ))|| (__0this ->
# 284 "/home/claude/cfront-3/src/template.cpp"
forward__10templ_inst == __1t ))|| (__1t -> forward__10templ_inst == __0this ))?1:0);

# 287 "/home/claude/cfront-3/src/template.cpp"
}

# 223 "/home/claude/cfront-3/src/cfront.h"
Pname look__5tableFPCcUc (struct table *__0this , const char *, TOK );

# 290 "/home/claude/cfront-3/src/template.cpp"
Ptempl is_template__17templ_compilationFP4name (register struct templ_compilation *__0this , Pname __1p )
# 293 "/home/claude/cfront-3/src/template.cpp"
{ 
# 295 "/home/claude/cfront-3/src/template.cpp"
if (__1p -> __O1__4expr.tp && (__1p -> __O1__4expr.tp -> base__4node == 119 ))
# 296 "/home/claude/cfront-3/src/template.cpp"
{ 
# 297 "/home/claude/cfront-3/src/template.cpp"
int __2tc ;
int __2sc ;

# 297 "/home/claude/cfront-3/src/template.cpp"
__2tc = get_class_base__FP8basetype ( ((struct basetype *)(((struct basetype *)__1p -> __O1__4expr.tp )))) ;
__2sc = get_templ_base__FP8basetype ( ((struct basetype *)(((struct basetype *)__1p -> __O1__4expr.tp )))) ;

# 300 "/home/claude/cfront-3/src/template.cpp"
if ((__2tc == 2)|| ((__2tc == 4)&& (__2sc == 2)))
# 301 "/home/claude/cfront-3/src/template.cpp"
{ 
# 302 "/home/claude/cfront-3/src/template.cpp"
Pname __3n ;

# 302 "/home/claude/cfront-3/src/template.cpp"
__3n = look__5tableFPCcUc ( templates__17templ_compilation , __1p -> __O2__4expr.string , (unsigned char )0 ) ;
return (__3n ?(((struct templ *)(((struct templ *)__3n -> __O1__4expr.tp )))):(((struct templ *)0 )));
}
else return (struct templ *)0 ;
}
return (struct templ *)0 ;
}

# 311 "/home/claude/cfront-3/src/template.cpp"
Ptempl is_template__17templ_compilationFPCc (struct templ_compilation *__0this , const char *__1s )
# 312 "/home/claude/cfront-3/src/template.cpp"
{ 
# 314 "/home/claude/cfront-3/src/template.cpp"
Pname __1n ;

# 314 "/home/claude/cfront-3/src/template.cpp"
__1n = look__5tableFPCcUc ( templates__17templ_compilation , __1s , (unsigned char )0 ) ;
return (__1n ?(((struct templ *)(((struct templ *)__1n -> __O1__4expr.tp )))):(((struct templ *)0 )));
}

# 319 "/home/claude/cfront-3/src/template.cpp"
Pfunt is_template__17templ_compilationFPCcUc (struct templ_compilation *__0this , const char *__1s , TOK __1t )
# 320 "/home/claude/cfront-3/src/template.cpp"
{ 
# 322 "/home/claude/cfront-3/src/template.cpp"
Pname __1n ;

# 322 "/home/claude/cfront-3/src/template.cpp"
__1n = look__5tableFPCcUc ( templates__17templ_compilation , __1s , __1t ) ;
return (__1n ?(((struct function_template *)(((struct function_template *)__1n -> __O1__4expr.tp )))):(((struct function_template *)0 )));
}

# 327 "/home/claude/cfront-3/src/template.cpp"
void start__17templ_compilationFv (struct templ_compilation *__0this )
# 334 "/home/claude/cfront-3/src/template.cpp"
{ 
# 335 "/home/claude/cfront-3/src/template.cpp"
in_progress__17templ_compilation = 1;
params__17templ_compilation = (param_end__17templ_compilation = 0 );
owner__17templ_compilation = 0 ;

# 337 "/home/claude/cfront-3/src/template.cpp"
f_owner__17templ_compilation = 0 ;
parsed_template__17templ_compilation = 0 ;

# 341 "/home/claude/cfront-3/src/template.cpp"
}

# 936 "/home/claude/cfront-3/src/cfront.h"
Pname tdef__4nameFv (struct name *__0this );

# 83 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCcRC2eaN32 (const char *, const struct ea *, const struct ea *, const struct ea *,
# 83 "/home/claude/cfront-3/src/cfront.h"
const struct ea *);

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 140 "/home/claude/cfront-3/src/template.h"
void append_parameter__17templ_compilationFP4name (struct templ_compilation *__0this , Pname );

# 344 "/home/claude/cfront-3/src/template.cpp"
void collect__17templ_compilationFUcP4name (register struct templ_compilation *__0this , TOK __1parm_type , Pname __1n )
# 347 "/home/claude/cfront-3/src/template.cpp"
{ 
# 350 "/home/claude/cfront-3/src/template.cpp"
switch (__1parm_type ){ 
# 351 "/home/claude/cfront-3/src/template.cpp"
case 32 :
# 352 "/home/claude/cfront-3/src/template.cpp"
case 6 :
# 358 "/home/claude/cfront-3/src/template.cpp"
__1n -> __O1__4expr.tp = (struct type *)any_type ;
# 358 "/home/claude/cfront-3/src/template.cpp"

# 359 "/home/claude/cfront-3/src/template.cpp"
__1n = tdef__4nameFv ( __1n ) ;
__1n -> lex_level__4name = (bl_level + 1 );
__1n -> n_template_arg__4name = 1;
break ;
default :
# 364 "/home/claude/cfront-3/src/template.cpp"
{ 
# 364 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V32 ;

# 364 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V33 ;

# 364 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"theZT for%n must beC or struct, not%k", (const struct ea *)( ((& __0__V32 )-> __O1__2ea.p =
# 364 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1n )), (& __0__V32 )) , (const struct ea *)( (( ((& __0__V33 )-> __O1__2ea.i = ((unsigned
# 364 "/home/claude/cfront-3/src/template.cpp"
long )__1parm_type )), 0 ) ), (& __0__V33 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 364 "/home/claude/cfront-3/src/template.cpp"

# 365 "/home/claude/cfront-3/src/template.cpp"
break ;
} }
append_parameter__17templ_compilationFP4name ( __0this , __1n ) ;
}

# 657 "/home/claude/cfront-3/src/cfront.h"
struct name_list *__ct__9name_listFP4nameP9name_list (struct name_list *__0this , Pname __1ff , Plist __1ll );

# 371 "/home/claude/cfront-3/src/template.cpp"
void append_parameter__17templ_compilationFP4name (register struct templ_compilation *__0this , Pname __1n )
# 372 "/home/claude/cfront-3/src/template.cpp"
{ 
# 374 "/home/claude/cfront-3/src/template.cpp"
if (params__17templ_compilation ){ 
# 375 "/home/claude/cfront-3/src/template.cpp"
param_end__17templ_compilation -> l__9name_list = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __1n , (struct
# 375 "/home/claude/cfront-3/src/template.cpp"
name_list *)0 ) ;
param_end__17templ_compilation = param_end__17templ_compilation -> l__9name_list ;
}
else params__17templ_compilation = (param_end__17templ_compilation = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __1n , (struct name_list *)0 ) );
__1n -> permanent__4node = 1 ;

# 379 "/home/claude/cfront-3/src/template.cpp"
__1n -> __O1__4expr.tp -> permanent__4node = 1 ;
}

# 383 "/home/claude/cfront-3/src/template.cpp"
void collect__17templ_compilationFP4name (register struct templ_compilation *__0this , Pname __1n )
# 386 "/home/claude/cfront-3/src/template.cpp"
{ 
# 391 "/home/claude/cfront-3/src/template.cpp"
extern int must_be_friend ;

# 390 "/home/claude/cfront-3/src/template.cpp"
__1n -> n_template_arg__4name = 2;
;
if (must_be_friend == 0 )
# 393 "/home/claude/cfront-3/src/template.cpp"
insert__5tableFP4nameUc ( bound_expr_tbl , __1n , (unsigned char )0 ) ;
append_parameter__17templ_compilationFP4name ( __0this , __1n ) ;
}

# 75 "/home/claude/cfront-3/src/cfront.h"

# 76 "/home/claude/cfront-3/src/cfront.h"

# 75 "/home/claude/cfront-3/src/cfront.h"

# 579 "/home/claude/cfront-3/src/cfront.h"
struct basetype *__ct__8basetypeFUcP4name (struct basetype *__0this , TOK , Pname );

# 75 "/home/claude/cfront-3/src/cfront.h"

# 398 "/home/claude/cfront-3/src/template.cpp"
static void check_non_type_formal__FP4name (Pname __1n )
# 399 "/home/claude/cfront-3/src/template.cpp"
{ 
# 402 "/home/claude/cfront-3/src/template.cpp"
Ptype __1tp ;

# 402 "/home/claude/cfront-3/src/template.cpp"
__1tp = skiptypedefs__4typeFv ( __1n -> __O1__4expr.tp ) ;
switch (__1tp -> base__4node ){ 
# 406 "/home/claude/cfront-3/src/template.cpp"
case 15 :
# 407 "/home/claude/cfront-3/src/template.cpp"
case 11 :
# 408 "/home/claude/cfront-3/src/template.cpp"
case 181 :
# 409 "/home/claude/cfront-3/src/template.cpp"
if ((__1tp -> base__4node == 181 )&& (ansi_opt == 0 ))
# 410 "/home/claude/cfront-3/src/template.cpp"
{ 
# 410 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V34 ;
# 410 "/home/claude/cfront-3/src/template.cpp"

# 410 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'w' , (const char *)"long double supported under ``+a1'' option only, generating ``double%n''", (const struct ea *)( ((&
# 410 "/home/claude/cfront-3/src/template.cpp"
__0__V34 )-> __O1__2ea.p = ((const void *)__1n )), (& __0__V34 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 410 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) ;
} error__FiPCc ( (int )'s' , (const char *)"ZE ofT float, double, or long double") ;
return ;

# 414 "/home/claude/cfront-3/src/template.cpp"
case 138 :
# 415 "/home/claude/cfront-3/src/template.cpp"
case 5 :
# 416 "/home/claude/cfront-3/src/template.cpp"
case 29 :
# 417 "/home/claude/cfront-3/src/template.cpp"
case 21 :
# 418 "/home/claude/cfront-3/src/template.cpp"
case 22 :
# 419 "/home/claude/cfront-3/src/template.cpp"
case 122 :
# 420 "/home/claude/cfront-3/src/template.cpp"
case 114 :
# 421 "/home/claude/cfront-3/src/template.cpp"
case 121 :
# 422 "/home/claude/cfront-3/src/template.cpp"
case 119 :
# 424 "/home/claude/cfront-3/src/template.cpp"
case 141 :
# 425 "/home/claude/cfront-3/src/template.cpp"
{ 
# 426 "/home/claude/cfront-3/src/template.cpp"
TOK __3bad_base ;

# 426 "/home/claude/cfront-3/src/template.cpp"
__3bad_base = 0 ;
if ((((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp ))))-> b_volatile__8basetype )__3bad_base = 170 ;

# 430 "/home/claude/cfront-3/src/template.cpp"
if ((((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp ))))-> b_inline__8basetype )__3bad_base = 75 ;
if ((((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp ))))-> b_virtual__8basetype )__3bad_base = 77 ;
if (__3bad_base )
# 433 "/home/claude/cfront-3/src/template.cpp"
{ 
# 433 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V35 ;

# 433 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V36 ;

# 433 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad %k declarator forY formal %n", (const struct ea *)( (( ((& __0__V35 )->
# 433 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.i = ((unsigned long )__3bad_base )), 0 ) ), (& __0__V35 )) , (const struct ea *)( ((& __0__V36 )->
# 433 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.p = ((const void *)__1n )), (& __0__V36 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 433 "/home/claude/cfront-3/src/template.cpp"
} 
# 434 "/home/claude/cfront-3/src/template.cpp"
goto hack ;

# 436 "/home/claude/cfront-3/src/template.cpp"
}
case 125 :
# 438 "/home/claude/cfront-3/src/template.cpp"
{ 
# 439 "/home/claude/cfront-3/src/template.cpp"
if (__1tp != __1n -> __O1__4expr.tp ){ 
# 440 "/home/claude/cfront-3/src/template.cpp"
hack :
# 441 "/home/claude/cfront-3/src/template.cpp"
{ Pbase __4b ;

# 441 "/home/claude/cfront-3/src/template.cpp"
__4b = __ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )0 , (struct name *)0 ) ;
((*__4b ))= (*(((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp )))));

# 444 "/home/claude/cfront-3/src/template.cpp"
if (__4b -> b_const__4type == 0 )__4b -> b_const__4type = 2 ;
__1n -> __O1__4expr.tp = (struct type *)__4b ;
break ;

# 446 "/home/claude/cfront-3/src/template.cpp"
}
}

# 449 "/home/claude/cfront-3/src/template.cpp"
{ Pptr __3b ;

# 449 "/home/claude/cfront-3/src/template.cpp"
__3b = __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )0 , (struct type *)0 ) ;
((*__3b ))= (*(((struct ptr *)(((struct ptr *)__1n -> __O1__4expr.tp )))));
if (__3b -> b_const__4type == 0 )__3b -> b_const__4type = 2 ;
__1n -> __O1__4expr.tp = (struct type *)__3b ;
break ;

# 453 "/home/claude/cfront-3/src/template.cpp"
}
}
case 158 :
# 456 "/home/claude/cfront-3/src/template.cpp"
case 110 :
# 457 "/home/claude/cfront-3/src/template.cpp"
break ;
default :
# 459 "/home/claude/cfront-3/src/template.cpp"
{ 
# 459 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V37 ;

# 459 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V38 ;

# 459 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"badZT%t for formalZ %n", (const struct ea *)( ((& __0__V37 )-> __O1__2ea.p =
# 459 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1tp )), (& __0__V37 )) , (const struct ea *)( ((& __0__V38 )-> __O1__2ea.p = ((const void
# 459 "/home/claude/cfront-3/src/template.cpp"
*)__1n )), (& __0__V38 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
return ;
}

# 345 "/home/claude/cfront-3/src/cfront.h"
void dcl__4typeFP5table (struct type *__0this , Ptable );

# 465 "/home/claude/cfront-3/src/template.cpp"
void enter_parameters__17templ_compilationFv (register struct templ_compilation *__0this )
# 471 "/home/claude/cfront-3/src/template.cpp"
{ 
# 472 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __1list ;

# 472 "/home/claude/cfront-3/src/template.cpp"
__1list = params__17templ_compilation ;

# 472 "/home/claude/cfront-3/src/template.cpp"
for(;__1list ;__1list = __1list -> l__9name_list ) { 
# 473 "/home/claude/cfront-3/src/template.cpp"
Pname __2n ;

# 473 "/home/claude/cfront-3/src/template.cpp"
__2n = __1list -> f__9name_list ;
switch (__2n -> n_template_arg__4name ){ 
# 475 "/home/claude/cfront-3/src/template.cpp"
case 1:
# 478 "/home/claude/cfront-3/src/template.cpp"
__2n -> n_key__4name = 0 ;
break ;

# 481 "/home/claude/cfront-3/src/template.cpp"
case 2:
# 482 "/home/claude/cfront-3/src/template.cpp"
check_non_type_formal__FP4name ( __2n ) ;
dcl__4typeFP5table ( __2n -> __O1__4expr.tp , gtbl ) ;
break ;
default :
# 486 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"bad template formal") ;
}
}

# 488 "/home/claude/cfront-3/src/template.cpp"
}

# 488 "/home/claude/cfront-3/src/template.cpp"
}

# 492 "/home/claude/cfront-3/src/template.cpp"
}

# 188 "/home/claude/cfront-3/src/template.h"
void check_formals__14basic_templateFP9name_list (struct basic_template *__0this , Plist __1formals );

# 495 "/home/claude/cfront-3/src/template.cpp"
void resolve_forward_decl__5templFP9name_listP8classdef (register struct templ *__0this , Plist __1params , Pclass __1c )
# 500 "/home/claude/cfront-3/src/template.cpp"
{ 
# 501 "/home/claude/cfront-3/src/template.cpp"
check_formals__14basic_templateFP9name_list ( (struct basic_template *)__0this , __1params ) ;
__0this -> formals__14basic_template = __1params ;
__0this -> defined__5templ = 1;
__0this -> members__5templ = __1c -> mem_list__8classdef ;
}

# 507 "/home/claude/cfront-3/src/template.cpp"
static bit reinstat = 0 ;

# 434 "/home/claude/cfront-3/src/template.h"
Ptempl_inst instantiate__10templ_instF4bool (struct templ_inst *__0this , int __1reinstantiate );

# 510 "/home/claude/cfront-3/src/template.cpp"
void instantiate_forward_decl__5templFv (register struct templ *__0this ){ 
# 511 "/home/claude/cfront-3/src/template.cpp"
{ { Ptempl_inst __1i ;

# 511 "/home/claude/cfront-3/src/template.cpp"
__1i = __0this -> insts__5templ ;

# 511 "/home/claude/cfront-3/src/template.cpp"
for(;__1i ;__1i = __1i -> next__10templ_inst ) 
# 512 "/home/claude/cfront-3/src/template.cpp"
if (((((struct templ_classdef *)(((struct templ_classdef *)(((struct basetype *)(((struct basetype *)__1i -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> class_base__8classdef ==
# 512 "/home/claude/cfront-3/src/template.cpp"
4)&& (! __1i -> forward__10templ_inst ))
# 514 "/home/claude/cfront-3/src/template.cpp"
{ 
# 515 "/home/claude/cfront-3/src/template.cpp"
reinstat = 1 ;
instantiate__10templ_instF4bool ( __1i , 1) ;
reinstat = 0 ;
}

# 518 "/home/claude/cfront-3/src/template.cpp"
}

# 518 "/home/claude/cfront-3/src/template.cpp"
}
}

# 381 "/home/claude/cfront-3/src/template.h"
void instantiate__10funct_instF4bool (struct funct_inst *__0this , int __1reinstantiate );

# 522 "/home/claude/cfront-3/src/template.cpp"
void instantiate_forward_decl__17function_templateFv (register struct function_template *__0this ){ 
# 523 "/home/claude/cfront-3/src/template.cpp"
{ { Pfunct_inst __1i ;

# 523 "/home/claude/cfront-3/src/template.cpp"
__1i = __0this -> insts__17function_template ;

# 523 "/home/claude/cfront-3/src/template.cpp"
for(;__1i ;__1i = __1i -> next__10funct_inst ) 
# 524 "/home/claude/cfront-3/src/template.cpp"
if ((((struct templ_fct *)(((struct templ_fct *)__1i -> tname__10basic_inst -> __O1__4expr.tp ))))-> fct_base__3fct == 4)
# 525 "/home/claude/cfront-3/src/template.cpp"
{ 
# 526 "/home/claude/cfront-3/src/template.cpp"
instantiate__10funct_instF4bool ( __1i , 1)
# 526 "/home/claude/cfront-3/src/template.cpp"
;
}

# 527 "/home/claude/cfront-3/src/template.cpp"
}

# 527 "/home/claude/cfront-3/src/template.cpp"
}
}

# 535 "/home/claude/cfront-3/src/template.cpp"
int check_qualifier__10templ_instFP9name_list (register struct templ_inst *__0this , Plist __1formals )
# 536 "/home/claude/cfront-3/src/template.cpp"
{ 
# 537 "/home/claude/cfront-3/src/template.cpp"
Pexpr __1actual ;

# 537 "/home/claude/cfront-3/src/template.cpp"
__1actual = __0this -> actuals__10basic_inst ;
{ { Plist __1formal ;

# 538 "/home/claude/cfront-3/src/template.cpp"
__1formal = __1formals ;

# 538 "/home/claude/cfront-3/src/template.cpp"
for(;__1formal && __1actual ;( (__1formal = __1formal -> l__9name_list ), (__1actual = __1actual -> __O3__4expr.e2 )) ) 
# 541 "/home/claude/cfront-3/src/template.cpp"
switch (__1formal -> f__9name_list -> n_template_arg__4name ){ 
# 543 "/home/claude/cfront-3/src/template.cpp"
case
# 543 "/home/claude/cfront-3/src/template.cpp"
1:
# 544 "/home/claude/cfront-3/src/template.cpp"
{ Pbase __3b ;

# 544 "/home/claude/cfront-3/src/template.cpp"
__3b = (((struct basetype *)(((struct basetype *)__1actual -> __O2__4expr.e1 -> __O1__4expr.tp ))));

# 546 "/home/claude/cfront-3/src/template.cpp"
if (! (((__3b -> base__4node == 97 )&& (__3b -> b_name__8basetype -> base__4node == 123 ))&& (strcmp ( (((struct name *)(((struct name *)__3b -> b_name__8basetype ))))->
# 546 "/home/claude/cfront-3/src/template.cpp"
__O2__4expr.string , __1formal -> f__9name_list -> __O2__4expr.string ) == 0 )))
# 549 "/home/claude/cfront-3/src/template.cpp"
return (int )0;
break ;
}

# 553 "/home/claude/cfront-3/src/template.cpp"
case 2:
# 554 "/home/claude/cfront-3/src/template.cpp"
if (! ((__1actual -> __O2__4expr.e1 -> base__4node == 85 )&& (strcmp ( (((struct name *)(((struct name *)__1actual -> __O2__4expr.e1 ))))-> __O2__4expr.string , __1formal ->
# 554 "/home/claude/cfront-3/src/template.cpp"
f__9name_list -> __O2__4expr.string ) == 0 )))
# 556 "/home/claude/cfront-3/src/template.cpp"
return (int )0;
break ;

# 559 "/home/claude/cfront-3/src/template.cpp"
default :
# 560 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"bad template formal") ;
}

# 563 "/home/claude/cfront-3/src/template.cpp"
return (int )1;

# 563 "/home/claude/cfront-3/src/template.cpp"
}

# 563 "/home/claude/cfront-3/src/template.cpp"
}
}

# 566 "/home/claude/cfront-3/src/template.cpp"
extern int add_first ;

# 75 "/home/claude/cfront-3/src/cfront.h"

# 668 "/home/claude/cfront-3/src/cfront.h"
Pname add__3genFP4name (struct gen *__0this , Pname );

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

# 75 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFPCv (struct ea *__0this , const void *__2pp );

# 667 "/home/claude/cfront-3/src/cfront.h"

# 568 "/home/claude/cfront-3/src/template.cpp"
void introduce_global_name__FP4name (Pname __1ft )
# 569 "/home/claude/cfront-3/src/template.cpp"
{ 
# 571 "/home/claude/cfront-3/src/template.cpp"
Pname __1n ;

# 571 "/home/claude/cfront-3/src/template.cpp"
__1n = look__5tableFPCcUc ( gtbl , __1ft -> __O2__4expr.string , (unsigned char )0 ) ;
if (__1n == 0 ){ 
# 573 "/home/claude/cfront-3/src/template.cpp"
Pname __2nn ;

# 573 "/home/claude/cfront-3/src/template.cpp"
__2nn = insert__5tableFP4nameUc ( gtbl , __ct__4nameFPCc ( (struct name *)0 , __1ft -> __O2__4expr.string ) , (unsigned char )0 ) ;
__2nn -> n_template_fct__4name = 1 ;
if (__1ft -> n_sto__4name == 18 ){ 
# 576 "/home/claude/cfront-3/src/template.cpp"
__2nn -> n_scope__4name = 14 ;
}
__2nn -> __O1__4expr.tp = __1ft -> __O1__4expr.tp ;
__2nn -> permanent__4node = 1 ;
}
else { 
# 583 "/home/claude/cfront-3/src/template.cpp"
switch (__1n -> __O1__4expr.tp -> base__4node ){ 
# 584 "/home/claude/cfront-3/src/template.cpp"
default :
# 585 "/home/claude/cfront-3/src/template.cpp"
{ 
# 585 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V39 ;

# 585 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V40 ;

# 585 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"YF%n renamed object ofT%t", (const struct ea *)( ((& __0__V39 )-> __O1__2ea.p =
# 585 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1ft )), (& __0__V39 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V40 , (const void *)__1n ->
# 585 "/home/claude/cfront-3/src/template.cpp"
__O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
case 76 :{ 
# 588 "/home/claude/cfront-3/src/template.cpp"
Pname __4n2 ;

# 588 "/home/claude/cfront-3/src/template.cpp"
__4n2 = add__3genFP4name ( ((struct gen *)(((struct gen *)__1n -> __O1__4expr.tp ))), __1ft ) ;
__4n2 -> n_template_fct__4name ++ ;
__1n -> n_template_fct__4name ++ ;
}
break ;
case 108 :{ 
# 594 "/home/claude/cfront-3/src/template.cpp"
Pgen __4g ;

# 594 "/home/claude/cfront-3/src/template.cpp"
__4g = __ct__3genFv ( (struct gen *)0 ) ;
__4g -> permanent__4node = 1 ;
add_first = 1 ;
((void )add__3genFP4name ( __4g , __1n ) );
add_first = 0 ;
{ Pname __4n2 ;

# 599 "/home/claude/cfront-3/src/template.cpp"
__4n2 = add__3genFP4name ( __4g , __1ft ) ;
__4n2 -> n_template_fct__4name ++ ;
__1n -> __O1__4expr.tp = (struct type *)__4g ;
__1n -> n_template_fct__4name ++ ;

# 602 "/home/claude/cfront-3/src/template.cpp"
}
}
break ;
} }
}
}

# 164 "/home/claude/cfront-3/src/template.h"
extern void check_formals_for_dups__FP9name_list (Plist __0formals );

# 221 "/home/claude/cfront-3/src/template.h"
struct templ *__ct__5templFP9name_listP4name (struct templ *__0this , Plist , Pname );

# 610 "/home/claude/cfront-3/src/template.cpp"
void introduce_class_templ__17templ_compilationFP4name (register struct templ_compilation *__0this , Pname __1namep )
# 614 "/home/claude/cfront-3/src/template.cpp"
{ 
# 620 "/home/claude/cfront-3/src/template.cpp"
owner__17templ_compilation = is_template__17templ_compilationFP4name ( __0this , __1namep ) ;
if (! owner__17templ_compilation ){ 
# 622 "/home/claude/cfront-3/src/template.cpp"
check_formals_for_dups__FP9name_list ( params__17templ_compilation ) ;

# 625 "/home/claude/cfront-3/src/template.cpp"
owner__17templ_compilation = __ct__5templFP9name_listP4name ( (struct templ *)0 , params__17templ_compilation , __1namep ) ;
{ Pname __2nn ;
Pname __2lookup_name ;

# 626 "/home/claude/cfront-3/src/template.cpp"
__2nn = __ct__4nameFPCc ( (struct name *)0 , __1namep -> __O2__4expr.string ) ;
__2lookup_name = insert__5tableFP4nameUc ( templates__17templ_compilation , __2nn , (unsigned char )0 ) ;
__2lookup_name -> __O1__4expr.tp = (((struct type *)(((struct type *)owner__17templ_compilation ))));

# 628 "/home/claude/cfront-3/src/template.cpp"
}
}
}

# 253 "/home/claude/cfront-3/src/template.h"
struct function_template *__ct__17function_templateFP9name_listP4name (struct function_template *__0this , Plist , Pname );

# 633 "/home/claude/cfront-3/src/template.cpp"
void introduce_funct_templ__17templ_compilationFP4name (register struct templ_compilation *__0this , Pname __1namep ){ 
# 639 "/home/claude/cfront-3/src/template.cpp"
Pfunt __1t ;
Pname __1n ;

# 639 "/home/claude/cfront-3/src/template.cpp"
__1t = __ct__17function_templateFP9name_listP4name ( (struct function_template *)0 , params__17templ_compilation , __1namep ) ;
__1n = look__5tableFPCcUc ( templates__17templ_compilation , __1namep -> __O2__4expr.string , (unsigned char )108 ) ;

# 642 "/home/claude/cfront-3/src/template.cpp"
if (__1n == 0 ){ 
# 643 "/home/claude/cfront-3/src/template.cpp"
Pname __2nn ;

# 643 "/home/claude/cfront-3/src/template.cpp"
__2nn = __ct__4nameFPCc ( (struct name *)0 , __1namep -> __O2__4expr.string ) ;
__1n = insert__5tableFP4nameUc ( templates__17templ_compilation , __2nn , (unsigned char )108 ) ;
}
else __1t -> gen_list__17function_template = (((struct function_template *)(((struct function_template *)__1n -> __O1__4expr.tp ))));
__1n -> __O1__4expr.tp = (((struct type *)(((struct type *)__1t ))));
f_owner__17templ_compilation = __1t ;
introduce_global_name__FP4name ( __1namep ) ;
}

# 1259 "/home/claude/cfront-3/src/cfront.h"

# 958 "/home/claude/cfront-3/src/cfront.h"

# 653 "/home/claude/cfront-3/src/template.cpp"
static int has_formal_type__FP14templ_classdefP9name_list (Ptclass __1pt_cl , Plist __1list )
# 654 "/home/claude/cfront-3/src/template.cpp"
{ 
# 656 "/home/claude/cfront-3/src/template.cpp"
int __1has_formal ;

# 656 "/home/claude/cfront-3/src/template.cpp"
__1has_formal = 0 ;
{ { Pexpr __1formals ;

# 657 "/home/claude/cfront-3/src/template.cpp"
__1formals = __1pt_cl -> inst__14templ_classdef -> actuals__10basic_inst ;

# 657 "/home/claude/cfront-3/src/template.cpp"
for(;__1formals ;__1formals = __1formals -> __O3__4expr.e2 ) 
# 659 "/home/claude/cfront-3/src/template.cpp"
{ 
# 660 "/home/claude/cfront-3/src/template.cpp"
Pexpr __2fe ;

# 660 "/home/claude/cfront-3/src/template.cpp"
__2fe = __1formals -> __O2__4expr.e1 ;
if (((__2fe -> base__4node != 85 )|| (! __2fe -> __O1__4expr.tp ))|| (__2fe -> __O1__4expr.tp -> base__4node != 97 ))continue ;
{ Pname __2tn ;

# 663 "/home/claude/cfront-3/src/template.cpp"
struct type *__0__X41 ;

# 662 "/home/claude/cfront-3/src/template.cpp"
__2tn = ( (__0__X41 = __2fe -> __O1__4expr.tp ), ( (((struct basetype *)(((struct basetype *)__0__X41 ))))-> b_name__8basetype ) ) ;
if (! ( (((unsigned char )(__2tn -> n_template_arg__4name == 1)))) )continue ;

# 665 "/home/claude/cfront-3/src/template.cpp"
__1list = (__1list -> l__9name_list = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __2tn , (struct name_list *)0 ) );
++ __1has_formal ;

# 666 "/home/claude/cfront-3/src/template.cpp"
}
}
return __1has_formal ;

# 668 "/home/claude/cfront-3/src/template.cpp"
}

# 668 "/home/claude/cfront-3/src/template.cpp"
}
}

# 671 "/home/claude/cfront-3/src/template.cpp"
static Pname Tmpl ;

# 342 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr__4typeFv (struct type *__0this );

# 341 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ref__4typeFv (struct type *__0this );

# 1259 "/home/claude/cfront-3/src/cfront.h"

# 328 "/home/claude/cfront-3/src/cfront.h"
Pclass classtype__4typeFv (struct type *__0this );

# 1279 "/home/claude/cfront-3/src/cfront.h"

# 958 "/home/claude/cfront-3/src/cfront.h"

# 674 "/home/claude/cfront-3/src/template.cpp"
static int has_formal_type__FP4nameP9name_list (Pname __1nn , Plist __1list )
# 675 "/home/claude/cfront-3/src/template.cpp"
{ 
# 677 "/home/claude/cfront-3/src/template.cpp"
Pname __1bn ;
Ptype __1t ;

# 678 "/home/claude/cfront-3/src/template.cpp"
Ptype __1nt ;

# 678 "/home/claude/cfront-3/src/template.cpp"
__1nt = __1nn -> __O1__4expr.tp ;

# 680 "/home/claude/cfront-3/src/template.cpp"
while (__1t = (struct type *)is_ptr__4typeFv ( __1nt ) )__1nt = (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp ;
while (__1t = (struct type *)is_ref__4typeFv ( __1nt ) )__1nt = (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp ;

# 683 "/home/claude/cfront-3/src/template.cpp"
if (__1nt -> base__4node != 97 )return 0 ;
while (__1nt -> base__4node == 97 ){ 
# 685 "/home/claude/cfront-3/src/template.cpp"
__1bn = ( (((struct basetype *)(((struct basetype *)__1nt ))))-> b_name__8basetype ) ;
__1nt = __1bn -> __O1__4expr.tp ;
}

# 689 "/home/claude/cfront-3/src/template.cpp"
if (__1nt -> base__4node == 119 ){ 
# 690 "/home/claude/cfront-3/src/template.cpp"
Pclass __2c1 ;

# 691 "/home/claude/cfront-3/src/template.cpp"
int __1__Xt00awz144hdwckg ;

# 690 "/home/claude/cfront-3/src/template.cpp"
__2c1 = classtype__4typeFv ( __1nt ) ;
if (( (__1__Xt00awz144hdwckg = ((((struct type *)__2c1 )-> base__4node == 108 )?(((struct fct *)(((struct fct *)((struct type *)__2c1 )))))-> fct_base__3fct :((((struct type *)__2c1 )-> base__4node == 6 )?(((struct
# 691 "/home/claude/cfront-3/src/template.cpp"
classdef *)(((struct classdef *)((struct type *)__2c1 )))))-> class_base__8classdef :(((int )0 ))))), (((unsigned char )((__1__Xt00awz144hdwckg == 4)|| (__1__Xt00awz144hdwckg == 5))))) )
# 692 "/home/claude/cfront-3/src/template.cpp"
return has_formal_type__FP14templ_classdefP9name_list ( ((struct
# 692 "/home/claude/cfront-3/src/template.cpp"
templ_classdef *)(((struct templ_classdef *)__2c1 ))), __1list ) ;

# 695 "/home/claude/cfront-3/src/template.cpp"
if (__2c1 -> class_base__8classdef == 2){ 
# 697 "/home/claude/cfront-3/src/template.cpp"
Tmpl = __1bn ;
return -1;
}
}

# 702 "/home/claude/cfront-3/src/template.cpp"
if (( (((unsigned char )(__1bn -> n_template_arg__4name == 1)))) ){ 
# 704 "/home/claude/cfront-3/src/template.cpp"
__1list = (__1list -> l__9name_list = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 ,
# 704 "/home/claude/cfront-3/src/template.cpp"
__1bn , (struct name_list *)0 ) );
return (int )1;
}
return (int )0;
}

# 710 "/home/claude/cfront-3/src/template.cpp"
static bit hbf = 0 ;
struct bleh__handle_bound_friend__FP14basic_templateP4name__L42;

# 194 "/home/claude/cfront-3/src/template.h"
int get_formals_count__14basic_templateFv (struct basic_template *__0this );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 193 "/home/claude/cfront-3/src/template.h"

# 724 "/home/claude/cfront-3/src/template.cpp"
struct bleh__handle_bound_friend__FP14basic_templateP4name__L42 {	/* sizeof bleh__handle_bound_friend__FP14basic_templateP4name__L42 == 16 */

# 724 "/home/claude/cfront-3/src/template.cpp"
Pname n__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 ;

# 724 "/home/claude/cfront-3/src/template.cpp"
int used__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 ;
};

# 80 "/home/claude/cfront-3/src/template.h"
struct templ_state *__ct__11templ_stateFv (struct templ_state *__0this );

# 125 "/home/claude/cfront-3/src/template.h"
void end__17templ_compilationFP4name (struct templ_compilation *__0this , Pname __1class_name );

# 227 "/home/claude/cfront-3/src/template.h"

# 50 "/home/claude/cfront-3/src/template.h"

# 75 "/home/claude/cfront-3/src/template.h"
struct templ_state {	/* sizeof templ_state == 56 */

# 83 "/home/claude/cfront-3/src/template.h"
Plist param_end__11templ_state ;
Plist params__11templ_state ;
Pcons templ_refs__11templ_state ;
Pcons friend_templ_refs__11templ_state ;
Pcons last_cons__11templ_state ;
Pcons last_friend_cons__11templ_state ;
Ptempl owner__11templ_state ;
};

# 1 ""

# 81 "/home/claude/cfront-3/src/template.h"
void __dt__11templ_stateFv (struct templ_state *__0this , int );

# 713 "/home/claude/cfront-3/src/template.cpp"
void handle_bound_friend__FP14basic_templateP4name (Ptempl_base __1pb , Pname __1fn )
# 714 "/home/claude/cfront-3/src/template.cpp"
{ 
# 719 "/home/claude/cfront-3/src/template.cpp"
Plist __1formals ;

# 719 "/home/claude/cfront-3/src/template.cpp"
Plist __1f_list ;
int __1i ;

# 720 "/home/claude/cfront-3/src/template.cpp"
int __1formal_cnt ;
Pfct __1f ;

# 724 "/home/claude/cfront-3/src/template.cpp"

# 725 "/home/claude/cfront-3/src/template.cpp"
struct bleh__handle_bound_friend__FP14basic_templateP4name__L42 *__1pbleh ;

# 726 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 726 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 726 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 719 "/home/claude/cfront-3/src/template.cpp"
__1f_list = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , (struct name *)0 , (struct name_list *)0 ) ;
__1i = 0 ;

# 720 "/home/claude/cfront-3/src/template.cpp"
__1formal_cnt = get_formals_count__14basic_templateFv ( __1pb ) ;
__1f = ( ((__1fn -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 721 "/home/claude/cfront-3/src/template.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const void *)__1fn )),
# 721 "/home/claude/cfront-3/src/template.cpp"
(& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __1fn -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500q2z144hdwckg )->
# 721 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 721 "/home/claude/cfront-3/src/template.cpp"
, (((struct fct *)0 ))) )) ;
if (__1f -> body__3fct )return ;

# 724 "/home/claude/cfront-3/src/template.cpp"
;
__1pbleh = (((struct bleh__handle_bound_friend__FP14basic_templateP4name__L42 *)__nw__FUl ( (size_t)((sizeof (struct bleh__handle_bound_friend__FP14basic_templateP4name__L42 ))* __1formal_cnt )) ));

# 727 "/home/claude/cfront-3/src/template.cpp"
for(__1formals = ( __1pb -> formals__14basic_template ) ;__1formals ;__1formals = __1formals -> l__9name_list ) { 
# 728 "/home/claude/cfront-3/src/template.cpp"
(__1pbleh [__1i ]). n__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 = __1formals -> f__9name_list ;

# 728 "/home/claude/cfront-3/src/template.cpp"
(__1pbleh [(__1i ++ )]). used__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 = 0 ;
}

# 731 "/home/claude/cfront-3/src/template.cpp"
{ int __1has_formal ;

# 731 "/home/claude/cfront-3/src/template.cpp"
__1has_formal = 0 ;

# 733 "/home/claude/cfront-3/src/template.cpp"
{ { Pname __1n ;

# 733 "/home/claude/cfront-3/src/template.cpp"
__1n = __1f -> argtype__3fct ;

# 733 "/home/claude/cfront-3/src/template.cpp"
for(;__1n ;__1n = __1n -> __O1__4name.n_list ) 
# 735 "/home/claude/cfront-3/src/template.cpp"
__1has_formal += has_formal_type__FP4nameP9name_list ( __1n , __1f_list ) ;

# 737 "/home/claude/cfront-3/src/template.cpp"
if (! __1has_formal )return ;

# 740 "/home/claude/cfront-3/src/template.cpp"
if (__1has_formal == -1){ 
# 741 "/home/claude/cfront-3/src/template.cpp"
if (strcmp ( Tmpl -> __O2__4expr.string , (((struct templ *)(((struct templ *)__1pb ))))-> namep__5templ -> __O2__4expr.string ) )
# 742 "/home/claude/cfront-3/src/template.cpp"
return ;
# 742 "/home/claude/cfront-3/src/template.cpp"

# 745 "/home/claude/cfront-3/src/template.cpp"
}
else 
# 747 "/home/claude/cfront-3/src/template.cpp"
for(__1formals = __1f_list -> l__9name_list ;__1formals ;__1formals = __1formals -> l__9name_list ) { 
# 748 "/home/claude/cfront-3/src/template.cpp"
Pname __2n ;

# 748 "/home/claude/cfront-3/src/template.cpp"
__2n = __1formals -> f__9name_list ;
if (! __2n )break ;
for(__1i = 0 ;__1i < __1formal_cnt ;++ __1i ) 
# 751 "/home/claude/cfront-3/src/template.cpp"
if (strcmp ( __2n -> __O2__4expr.string , (__1pbleh [__1i ]). n__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 -> __O2__4expr.string ) == 0 ){ 
# 752 "/home/claude/cfront-3/src/template.cpp"
(__1pbleh [__1i ]).
# 752 "/home/claude/cfront-3/src/template.cpp"
used__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 ++ ;

# 754 "/home/claude/cfront-3/src/template.cpp"
break ;
}
}

# 758 "/home/claude/cfront-3/src/template.cpp"
save_templ__17templ_compilation = __ct__11templ_stateFv ( (struct templ_state *)0 ) ;
params__17templ_compilation = (param_end__17templ_compilation = 0 );
for(__1i = 0 ;__1i < __1formal_cnt ;++ __1i ) { 
# 761 "/home/claude/cfront-3/src/template.cpp"
if (((__1pbleh [__1i ]). used__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 == 0 )&& (__1has_formal != -1))continue ;
append_parameter__17templ_compilationFP4name ( templp , (__1pbleh [__1i ]). n__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 ) ;

# 764 "/home/claude/cfront-3/src/template.cpp"
}

# 767 "/home/claude/cfront-3/src/template.cpp"
owner__17templ_compilation = 0 ;
hbf = 1 ;
end__17templ_compilationFP4name ( templp , __1fn ) ;
__1f -> fct_base__3fct = 1;

# 772 "/home/claude/cfront-3/src/template.cpp"
{ Ptempl_base __1fr ;

# 772 "/home/claude/cfront-3/src/template.cpp"
__1fr = parsed_template__17templ_compilation ;
__dt__11templ_stateFv ( save_templ__17templ_compilation , 3) ;

# 773 "/home/claude/cfront-3/src/template.cpp"
save_templ__17templ_compilation = 0 ;

# 775 "/home/claude/cfront-3/src/template.cpp"
{ Pclass __1cl ;

# 776 "/home/claude/cfront-3/src/template.cpp"
struct cons *__0__X43 ;

# 776 "/home/claude/cfront-3/src/template.cpp"
struct cons *__2__X44 ;

# 775 "/home/claude/cfront-3/src/template.cpp"
__1cl = ( (((struct classdef *)(((struct classdef *)(((struct templ *)(((struct templ *)__1pb ))))-> basep__5templ -> b_name__8basetype -> __O1__4expr.tp ))))) ;
__1cl -> templ_friends__8classdef = ( (__0__X43 = 0 ), ( (__2__X44 = __1cl -> templ_friends__8classdef ), ( ((__0__X43 || (__0__X43 = (struct cons *)__nw__FUl (
# 776 "/home/claude/cfront-3/src/template.cpp"
(size_t )(sizeof (struct cons))) ))?( (__0__X43 -> car__4cons = ((void *)__1fr )), (__0__X43 -> cdr__4cons = __2__X44 )) :0 ), __0__X43 )
# 776 "/home/claude/cfront-3/src/template.cpp"
) ) ;
__1fr -> extrapolated__14basic_template = 1 ;
if (hbf == 1 )
# 779 "/home/claude/cfront-3/src/template.cpp"
__1fr -> templ_refs__14basic_template = friend_templ_refs__17templ_compilation ;
hbf = 0 ;

# 780 "/home/claude/cfront-3/src/template.cpp"
}

# 780 "/home/claude/cfront-3/src/template.cpp"
}

# 780 "/home/claude/cfront-3/src/template.cpp"
}

# 780 "/home/claude/cfront-3/src/template.cpp"
}

# 780 "/home/claude/cfront-3/src/template.cpp"
}

# 782 "/home/claude/cfront-3/src/template.cpp"
}

# 945 "/home/claude/cfront-3/src/cfront.h"
void check_oper__4nameFP4name (struct name *__0this , Pname );

# 82 "/home/claude/cfront-3/src/cfront.h"
extern int error__FPCc (const char *);

# 784 "/home/claude/cfront-3/src/template.cpp"
void check_templ_funct__FP4name (Pname __1fn )
# 785 "/home/claude/cfront-3/src/template.cpp"
{ 
# 787 "/home/claude/cfront-3/src/template.cpp"
Pfct __1f ;

# 787 "/home/claude/cfront-3/src/template.cpp"
__1f = (((struct fct *)(((struct fct *)__1fn -> __O1__4expr.tp ))));

# 789 "/home/claude/cfront-3/src/template.cpp"
{ { Pname __1al ;

# 789 "/home/claude/cfront-3/src/template.cpp"
__1al = __1f -> argtype__3fct ;

# 789 "/home/claude/cfront-3/src/template.cpp"
for(;__1al ;__1al = __1al -> __O1__4name.n_list ) 
# 790 "/home/claude/cfront-3/src/template.cpp"
{ 
# 791 "/home/claude/cfront-3/src/template.cpp"
if (__1al -> __O3__4expr.n_initializer )
# 792 "/home/claude/cfront-3/src/template.cpp"
{ 
# 793 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'s' , (const char *)"FYs do not support defaultAs")
# 793 "/home/claude/cfront-3/src/template.cpp"
;
break ;
}
}

# 798 "/home/claude/cfront-3/src/template.cpp"
if (__1f -> nargs_known__3fct != 1 )
# 799 "/home/claude/cfront-3/src/template.cpp"
{ 
# 799 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V45 ;

# 799 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"ellipsis (...) inA list ofYF%n", (const struct ea *)( ((&
# 799 "/home/claude/cfront-3/src/template.cpp"
__0__V45 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V45 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 799 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) ;
} 
# 801 "/home/claude/cfront-3/src/template.cpp"
if (__1fn -> n_oper__4name )
# 802 "/home/claude/cfront-3/src/template.cpp"
{ 
# 803 "/home/claude/cfront-3/src/template.cpp"
switch (__1f -> nargs__3fct ){ 
# 804 "/home/claude/cfront-3/src/template.cpp"
case 1 :case 2 :break ;
default :
# 806 "/home/claude/cfront-3/src/template.cpp"
if (__1fn -> n_oper__4name != 23 )
# 807 "/home/claude/cfront-3/src/template.cpp"
{ 
# 807 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V46 ;

# 807 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"FY%n must take 1 or 2As", (const struct ea *)( ((& __0__V46 )-> __O1__2ea.p =
# 807 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1fn )), (& __0__V46 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 807 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
} }

# 810 "/home/claude/cfront-3/src/template.cpp"
switch (__1fn -> n_oper__4name ){ 
# 810 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X49 ;

# 810 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X50 ;

# 811 "/home/claude/cfront-3/src/template.cpp"
case 109 :
# 812 "/home/claude/cfront-3/src/template.cpp"
case 111 :
# 813 "/home/claude/cfront-3/src/template.cpp"
case 44 :
# 814 "/home/claude/cfront-3/src/template.cpp"
case 70 :
# 815 "/home/claude/cfront-3/src/template.cpp"
{ 
# 815 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V47 ;

# 815 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"YF operator%s must be aCM", (const struct ea *)( (__2__X49 = (const void
# 815 "/home/claude/cfront-3/src/template.cpp"
*)(keys [__1fn -> n_oper__4name ])), ( ((& __0__V47 )-> __O1__2ea.p = __2__X49 ), (& __0__V47 )) ) , (const struct ea *)ea0 ,
# 815 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return ;
case 212 :
# 818 "/home/claude/cfront-3/src/template.cpp"
case 9 :
# 819 "/home/claude/cfront-3/src/template.cpp"
{ 
# 819 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V48 ;

# 819 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"::operator %s may not be aYF", (const struct ea *)( (__2__X50 = (const void
# 819 "/home/claude/cfront-3/src/template.cpp"
*)(keys [__1fn -> n_oper__4name ])), ( ((& __0__V48 )-> __O1__2ea.p = __2__X50 ), (& __0__V48 )) ) , (const struct ea *)ea0 ,
# 819 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return ;
default :
# 822 "/home/claude/cfront-3/src/template.cpp"
check_oper__4nameFP4name ( __1fn , (struct name *)0 ) ;
break ;
} } }
}

# 827 "/home/claude/cfront-3/src/template.cpp"
if (strcmp ( (const char *)"main", __1fn -> __O2__4expr.string ) ==
# 827 "/home/claude/cfront-3/src/template.cpp"
0 )
# 828 "/home/claude/cfront-3/src/template.cpp"
error__FPCc ( (const char *)"main() may not be aYF") ;

# 828 "/home/claude/cfront-3/src/template.cpp"
}

# 828 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1259 "/home/claude/cfront-3/src/cfront.h"

# 113 "/home/claude/cfront-3/src/cfront.h"
extern Pname k_find_name__FPCcP6ktableUc (const char *, Pktab , TOK );

# 227 "/home/claude/cfront-3/src/template.h"

# 61 "/home/claude/cfront-3/src/cfront.h"
extern const char *curr_filename__Fv (void );

# 79 "/home/claude/incl-linux32/stdio.h"
extern int fprintf (void *, const char *,...);

# 136 "/home/claude/cfront-3/src/template.h"
void clear_friend_ref_templ__17templ_compilationFv (struct templ_compilation *__0this );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 165 "/home/claude/cfront-3/src/template.h"
extern void check_funct_formals__FP9name_listP4name (Plist __0formals , Pname __0namep );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 324 "/home/claude/cfront-3/src/cfront.h"
bit check__4typeFP4typeUcT2 (struct type *__0this , Ptype , TOK , bit );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 195 "/home/claude/cfront-3/src/template.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 229 "/home/claude/cfront-3/src/template.h"
Pfunt collect_function_member__5templFP4name (struct templ *__0this , Pname );
Pdata collect_data_member__5templFP4name (struct templ *__0this , Pname );

# 263 "/home/claude/cfront-3/src/template.h"
struct data_template {	/* sizeof data_template == 64 */

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

# 267 "/home/claude/cfront-3/src/template.h"
Pname dat_mem__13data_template ;
Pdata next__13data_template ;
};

# 135 "/home/claude/cfront-3/src/template.h"
void clear_ref_templ__17templ_compilationFv (struct templ_compilation *__0this );

# 862 "/home/claude/cfront-3/src/template.cpp"
void end__17templ_compilationFP4name (register struct templ_compilation *__0this , Pname __1p )
# 865 "/home/claude/cfront-3/src/template.cpp"
{ 
# 878 "/home/claude/cfront-3/src/template.cpp"
int __1forward_definition ;

# 878 "/home/claude/cfront-3/src/template.cpp"
__1forward_definition = 0;
if (! __1p -> __O1__4expr.tp ){ 
# 880 "/home/claude/cfront-3/src/template.cpp"
error__FPCc ( (const char *)"aC,F,MF or static dataM definition wasX") ;
return ;
}

# 884 "/home/claude/cfront-3/src/template.cpp"
switch (__1p -> __O1__4expr.tp -> base__4node ){ 
# 885 "/home/claude/cfront-3/src/template.cpp"
case 119 :
# 886 "/home/claude/cfront-3/src/template.cpp"
if (__1p -> n_sto__4name == 18 ){ 
# 886 "/home/claude/cfront-3/src/template.cpp"
struct type *__0__X72 ;

# 887 "/home/claude/cfront-3/src/template.cpp"
__1p = ( (__0__X72 = __1p -> __O1__4expr.tp ), ( (((struct basetype *)(((struct basetype *)__0__X72 ))))-> b_name__8basetype ) ) ;

# 890 "/home/claude/cfront-3/src/template.cpp"
}
else { 
# 892 "/home/claude/cfront-3/src/template.cpp"
{ 
# 892 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V51 ;

# 892 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"illegalY %n", (const struct ea *)( ((& __0__V51 )-> __O1__2ea.p =
# 892 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1p )), (& __0__V51 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 892 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
return ;
} }

# 896 "/home/claude/cfront-3/src/template.cpp"
case 6 :
# 902 "/home/claude/cfront-3/src/template.cpp"
{ 
# 905 "/home/claude/cfront-3/src/template.cpp"
Pname __3namep ;

# 905 "/home/claude/cfront-3/src/template.cpp"
__3namep = k_find_name__FPCcP6ktableUc ( __1p -> __O2__4expr.string , Gtbl , (unsigned char )159 ) ;
if ((__3namep == 0 )|| (__3namep -> base__4node == 85 ))
# 907 "/home/claude/cfront-3/src/template.cpp"
{ 
# 908 "/home/claude/cfront-3/src/template.cpp"
const char *__4s ;

# 908 "/home/claude/cfront-3/src/template.cpp"
__4s = (__1p -> __O2__4expr.string ?__1p -> __O2__4expr.string :(((const char *)"")));
if (((*__4s ))&& ((((__4s [0 ])!= '_' )|| ((__4s [1 ])!= '_' ))|| ((__4s [2 ])!= 'C' )))
# 910 "/home/claude/cfront-3/src/template.cpp"
{ 
# 910 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V52 ;

# 910 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"nestedYC %s", (const struct ea *)( ((& __0__V52 )-> __O1__2ea.p =
# 910 "/home/claude/cfront-3/src/template.cpp"
((const void *)__4s )), (& __0__V52 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 910 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
} else { 
# 912 "/home/claude/cfront-3/src/template.cpp"
error__FPCc ( (const char *)"missingYN") ;
return ;
}
}

# 917 "/home/claude/cfront-3/src/template.cpp"
owner__17templ_compilation = is_template__17templ_compilationFP4name ( __0this , __3namep ) ;
if (owner__17templ_compilation ){ 
# 919 "/home/claude/cfront-3/src/template.cpp"
Pclass __4c ;

# 920 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X73 ;

# 919 "/home/claude/cfront-3/src/template.cpp"
__4c = ( (((struct classdef *)(((struct classdef *)owner__17templ_compilation -> basep__5templ -> b_name__8basetype -> __O1__4expr.tp ))))) ;

# 922 "/home/claude/cfront-3/src/template.cpp"
if (owner__17templ_compilation -> defined__5templ && ((((struct classdef *)(((struct classdef *)__1p -> __O1__4expr.tp ))))-> mem_list__8classdef != owner__17templ_compilation -> members__5templ ))
# 924 "/home/claude/cfront-3/src/template.cpp"
{ 
# 924 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V53 ;

# 924 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"YC %s multiply defined", (const struct ea *)( (__2__X73 = (const void
# 924 "/home/claude/cfront-3/src/template.cpp"
*)__1p -> __O2__4expr.string ), ( ((& __0__V53 )-> __O1__2ea.p = __2__X73 ), (& __0__V53 )) ) , (const struct ea *)ea0 ,
# 924 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} __1forward_definition = (((int )((__4c -> defined__4type & 04 )&& (! owner__17templ_compilation -> defined__5templ ))));
if (__1forward_definition )
# 927 "/home/claude/cfront-3/src/template.cpp"
resolve_forward_decl__5templFP9name_listP8classdef ( owner__17templ_compilation , params__17templ_compilation , __4c ) ;

# 929 "/home/claude/cfront-3/src/template.cpp"
if (pt_opt && __1forward_definition )
# 930 "/home/claude/cfront-3/src/template.cpp"
fprintf ( pt_file , (const char *)"t %s %s\n", __1p -> __O2__4expr.string , curr_filename__Fv (
# 930 "/home/claude/cfront-3/src/template.cpp"
) ) ;
}
else 
# 933 "/home/claude/cfront-3/src/template.cpp"
introduce_class_templ__17templ_compilationFP4name ( __0this , __3namep ) ;

# 935 "/home/claude/cfront-3/src/template.cpp"
if (owner__17templ_compilation -> defined__5templ ){ 
# 936 "/home/claude/cfront-3/src/template.cpp"
{ { Pname __4nn ;

# 936 "/home/claude/cfront-3/src/template.cpp"
__4nn = (((struct classdef *)(((struct classdef *)__1p -> __O1__4expr.tp ))))-> mem_list__8classdef ;

# 936 "/home/claude/cfront-3/src/template.cpp"
for(;__4nn ;__4nn = __4nn -> __O1__4name.n_list ) 
# 937 "/home/claude/cfront-3/src/template.cpp"
{ 
# 938 "/home/claude/cfront-3/src/template.cpp"
if (((__4nn -> base__4node == 85 )&& (__4nn -> n_sto__4name == 18 ))&& (__4nn -> __O2__4name.n_qualifier == 0 ))
# 941 "/home/claude/cfront-3/src/template.cpp"
{
# 941 "/home/claude/cfront-3/src/template.cpp"

# 942 "/home/claude/cfront-3/src/template.cpp"
switch (__4nn -> __O1__4expr.tp -> base__4node ){ 
# 943 "/home/claude/cfront-3/src/template.cpp"
case 108 :
# 945 "/home/claude/cfront-3/src/template.cpp"
handle_bound_friend__FP14basic_templateP4name ( (struct basic_template *)owner__17templ_compilation , __4nn ) ;
break ;
case 76 :
# 949 "/home/claude/cfront-3/src/template.cpp"
break ;
}
}
}

# 952 "/home/claude/cfront-3/src/template.cpp"
}

# 952 "/home/claude/cfront-3/src/template.cpp"
}
}
if (templ_refs__17templ_compilation )owner__17templ_compilation -> templ_refs__14basic_template = templ_refs__17templ_compilation ;
clear_friend_ref_templ__17templ_compilationFv ( templp ) ;
break ;
}

# 959 "/home/claude/cfront-3/src/template.cpp"
case 108 :
# 960 "/home/claude/cfront-3/src/template.cpp"
{ 
# 960 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 960 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 960 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 961 "/home/claude/cfront-3/src/template.cpp"
if ((pt_opt && (! ( ((__1p -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1p -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' ,
# 961 "/home/claude/cfront-3/src/template.cpp"
(const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const
# 961 "/home/claude/cfront-3/src/template.cpp"
void *)__1p )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __1p -> __O1__4expr.tp -> base__4node ), ( ((
# 961 "/home/claude/cfront-3/src/template.cpp"
((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 , (const
# 961 "/home/claude/cfront-3/src/template.cpp"
struct ea *)ea0 ) , (((struct fct *)0 ))) )) -> body__3fct ))&& (! __1p -> __O2__4name.n_qualifier ))
# 962 "/home/claude/cfront-3/src/template.cpp"
fprintf ( pt_file , (const char
# 962 "/home/claude/cfront-3/src/template.cpp"
*)"f %s %s\n", __1p -> __O2__4expr.string , curr_filename__Fv ( ) ) ;

# 964 "/home/claude/cfront-3/src/template.cpp"
{ Pname __3qual ;

# 964 "/home/claude/cfront-3/src/template.cpp"
__3qual = __1p -> __O2__4name.n_qualifier ;
if (! __3qual ){ 
# 966 "/home/claude/cfront-3/src/template.cpp"
check_funct_formals__FP9name_listP4name ( params__17templ_compilation , __1p ) ;
check_templ_funct__FP4name ( __1p ) ;
f_owner__17templ_compilation = is_template__17templ_compilationFPCcUc ( __0this , __1p -> __O2__4expr.string , (unsigned char )108 ) ;
if (! f_owner__17templ_compilation )
# 970 "/home/claude/cfront-3/src/template.cpp"
introduce_funct_templ__17templ_compilationFP4name ( __0this , __1p ) ;
else { 
# 972 "/home/claude/cfront-3/src/template.cpp"
Pfunt __5tl ;
Pname __5fn ;
Pfct __5n_fct ;

# 977 "/home/claude/cfront-3/src/template.cpp"
int __5error_cnt ;

# 978 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 978 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 978 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 972 "/home/claude/cfront-3/src/template.cpp"
__5tl = f_owner__17templ_compilation ;
__5fn = 0 ;
__5n_fct = ( ((__1p -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1p -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 974 "/home/claude/cfront-3/src/template.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const void *)__1p )),
# 974 "/home/claude/cfront-3/src/template.cpp"
(& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __1p -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500q2z144hdwckg )->
# 974 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 974 "/home/claude/cfront-3/src/template.cpp"
, (((struct fct *)0 ))) )) ;

# 977 "/home/claude/cfront-3/src/template.cpp"
__5error_cnt = 0 ;
for(__5fn = __5tl -> fn__17function_template ;__5tl ;( (__5tl = __5tl -> gen_list__17function_template ), (__5fn = (__5tl ?__5tl -> fn__17function_template :(((struct name *)0 ))))) ) { 
# 979 "/home/claude/cfront-3/src/template.cpp"
extern bit return_error ;
# 979 "/home/claude/cfront-3/src/template.cpp"

# 980 "/home/claude/cfront-3/src/template.cpp"
if (check__4typeFP4typeUcT2 ( (struct type *)__5n_fct , __5fn -> __O1__4expr.tp , (unsigned char )204 , (unsigned char )0 ) == 0 )break
# 980 "/home/claude/cfront-3/src/template.cpp"
;
if (__5error_cnt = return_error )break ;
}
if (__5error_cnt )
# 984 "/home/claude/cfront-3/src/template.cpp"
{ 
# 984 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V54 ;

# 984 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"FY%n: declared twice with different returnTs", (const struct ea *)( ((& __0__V54 )-> __O1__2ea.p =
# 984 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1p )), (& __0__V54 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 984 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
} 
# 987 "/home/claude/cfront-3/src/template.cpp"
if (__5tl == 0 )
# 988 "/home/claude/cfront-3/src/template.cpp"
introduce_funct_templ__17templ_compilationFP4name ( __0this , __1p ) ;
else { 
# 990 "/home/claude/cfront-3/src/template.cpp"
int __6f1 ;

# 990 "/home/claude/cfront-3/src/template.cpp"
int __6f2 ;

# 990 "/home/claude/cfront-3/src/template.cpp"
int __6extrap ;
Pfct __6o_fct ;

# 992 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 992 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 992 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 990 "/home/claude/cfront-3/src/template.cpp"
__6extrap = 0 ;
__6o_fct = ( ((__5fn -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__5fn -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 991 "/home/claude/cfront-3/src/template.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const void *)__5fn )),
# 991 "/home/claude/cfront-3/src/template.cpp"
(& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __5fn -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500q2z144hdwckg )->
# 991 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 991 "/home/claude/cfront-3/src/template.cpp"
, (((struct fct *)0 ))) )) ;
if ((__6f1 = (__5n_fct -> body__3fct != 0 ))&& (__6f2 = (__6o_fct -> body__3fct != 0 )))
# 993 "/home/claude/cfront-3/src/template.cpp"
{ 
# 993 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V55 ;

# 993 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V56 ;

# 993 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V57 ;

# 993 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"two definitions ofYF%n (%t %t)", (const struct ea *)( ((& __0__V55 )-> __O1__2ea.p =
# 993 "/home/claude/cfront-3/src/template.cpp"
((const void *)__5fn )), (& __0__V55 )) , (const struct ea *)( ((& __0__V56 )-> __O1__2ea.p = ((const void
# 993 "/home/claude/cfront-3/src/template.cpp"
*)__6o_fct )), (& __0__V56 )) , (const struct ea *)( ((& __0__V57 )-> __O1__2ea.p = ((const void *)__5n_fct )), (&
# 993 "/home/claude/cfront-3/src/template.cpp"
__0__V57 )) , (const struct ea *)ea0 ) ;
} 
# 996 "/home/claude/cfront-3/src/template.cpp"
__6extrap = ( (((struct basic_template *)f_owner__17templ_compilation )-> extrapolated__14basic_template ?1:0)) ;
if ((__1forward_definition = (((int )(__6f1 && (__6f2 == 0 )))))|| __6extrap )
# 998 "/home/claude/cfront-3/src/template.cpp"
{ 
# 999 "/home/claude/cfront-3/src/template.cpp"
__5tl -> formals__14basic_template = params__17templ_compilation ;
__5tl -> fn__17function_template = __1p ;
__5tl -> templ_refs__14basic_template = templ_refs__17templ_compilation ;
f_owner__17templ_compilation = __5tl ;
}
else if (hbf == 1 )hbf = 2 ;
}
}
if ((f_owner__17templ_compilation -> templ_refs__14basic_template == 0 )&& (hbf != 2 ))
# 1008 "/home/claude/cfront-3/src/template.cpp"
f_owner__17templ_compilation -> templ_refs__14basic_template = templ_refs__17templ_compilation ;
break ;

# 1011 "/home/claude/cfront-3/src/template.cpp"
}

# 1013 "/home/claude/cfront-3/src/template.cpp"
{ Pbase __3q ;

# 1014 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 1014 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 1014 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 1013 "/home/claude/cfront-3/src/template.cpp"
__3q = (((struct basetype *)(((struct basetype *)__3qual -> __O1__4expr.tp ))));
if (__3q && (__3q -> base__4node == 119 ))
# 1015 "/home/claude/cfront-3/src/template.cpp"
switch (get_class_base__FP8basetype ( __3q ) ){ 
# 1016 "/home/claude/cfront-3/src/template.cpp"
case 5:
# 1017 "/home/claude/cfront-3/src/template.cpp"
owner__17templ_compilation = (((struct templ_classdef *)(((struct templ_classdef *)__3q -> b_name__8basetype ->
# 1017 "/home/claude/cfront-3/src/template.cpp"
__O1__4expr.tp ))))-> inst__14templ_classdef -> def__10templ_inst ;

# 1023 "/home/claude/cfront-3/src/template.cpp"
if (! check_qualifier__10templ_instFP9name_list ( get_template_class__FP8basetype ( __3q ) -> inst__14templ_classdef , params__17templ_compilation ) )
# 1024 "/home/claude/cfront-3/src/template.cpp"
error__FPCc ( (const char *)"QrZs must match theY formalZs")
# 1024 "/home/claude/cfront-3/src/template.cpp"
;
break ;
case 2:
# 1028 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1028 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V58 ;

# 1028 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V59 ;

# 1028 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"Qr%n for%n must specifyYZs", (const struct ea *)( ((& __0__V58 )-> __O1__2ea.p =
# 1028 "/home/claude/cfront-3/src/template.cpp"
((const void *)__3qual )), (& __0__V58 )) , (const struct ea *)( ((& __0__V59 )-> __O1__2ea.p = ((const void
# 1028 "/home/claude/cfront-3/src/template.cpp"
*)__1p )), (& __0__V59 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
default :
# 1031 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1032 "/home/claude/cfront-3/src/template.cpp"
Pclass __5cl ;

# 1032 "/home/claude/cfront-3/src/template.cpp"
__5cl = (((struct classdef *)(((struct classdef *)__3q -> b_name__8basetype -> __O1__4expr.tp ))));
if ((__5cl && __5cl -> in_class__4type )&& __5cl -> in_class__4type -> class_base__8classdef )
# 1034 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1034 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V60 ;

# 1034 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V61 ;

# 1034 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"out-of-line definition ofMF ofC nestedWinYC (%t::%n)", (const struct ea *)( ((&
# 1034 "/home/claude/cfront-3/src/template.cpp"
__0__V60 )-> __O1__2ea.p = ((const void *)__5cl )), (& __0__V60 )) , (const struct ea *)( ((& __0__V61 )-> __O1__2ea.p =
# 1034 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1p )), (& __0__V61 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} else { 
# 1035 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V62 ;

# 1035 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V63 ;

# 1035 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"Qr%n for%n wasn't aYC", (const struct ea *)( ((& __0__V62 )-> __O1__2ea.p =
# 1035 "/home/claude/cfront-3/src/template.cpp"
((const void *)__3qual )), (& __0__V62 )) , (const struct ea *)( ((& __0__V63 )-> __O1__2ea.p = ((const void
# 1035 "/home/claude/cfront-3/src/template.cpp"
*)__1p )), (& __0__V63 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} return ;
}
} }
if (! ( ((__1p -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__1p -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' ,
# 1039 "/home/claude/cfront-3/src/template.cpp"
(const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const
# 1039 "/home/claude/cfront-3/src/template.cpp"
void *)__1p )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __1p -> __O1__4expr.tp -> base__4node ), ( ((
# 1039 "/home/claude/cfront-3/src/template.cpp"
((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 , (const
# 1039 "/home/claude/cfront-3/src/template.cpp"
struct ea *)ea0 ) , (((struct fct *)0 ))) )) -> body__3fct )
# 1040 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1040 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V64 ;

# 1040 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V65 ;

# 1040 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"QdN%n::%n inYFD", (const struct ea *)( ((& __0__V64 )-> __O1__2ea.p =
# 1040 "/home/claude/cfront-3/src/template.cpp"
((const void *)__3qual )), (& __0__V64 )) , (const struct ea *)( ((& __0__V65 )-> __O1__2ea.p = ((const void
# 1040 "/home/claude/cfront-3/src/template.cpp"
*)__1p )), (& __0__V65 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (owner__17templ_compilation )
# 1042 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1043 "/home/claude/cfront-3/src/template.cpp"
Pfunt __4ft ;

# 1043 "/home/claude/cfront-3/src/template.cpp"
__4ft = collect_function_member__5templFP4name ( owner__17templ_compilation , __1p ) ;
__4ft -> templ_refs__14basic_template = templ_refs__17templ_compilation ;
__4ft -> formals__14basic_template = params__17templ_compilation ;
check_formals__14basic_templateFP9name_list ( (struct basic_template *)owner__17templ_compilation , params__17templ_compilation ) ;
}
else 
# 1049 "/home/claude/cfront-3/src/template.cpp"
error__FPCc ( (const char *)"memberFY must beQd byCYN") ;
break ;

# 1050 "/home/claude/cfront-3/src/template.cpp"
}

# 1050 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1053 "/home/claude/cfront-3/src/template.cpp"
default :
# 1054 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1055 "/home/claude/cfront-3/src/template.cpp"
Pname __3qual ;

# 1055 "/home/claude/cfront-3/src/template.cpp"
__3qual = __1p -> __O2__4name.n_qualifier ;
if (! __3qual ){ 
# 1057 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1057 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V66 ;

# 1057 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n: only static dataCMs may beZized", (const struct ea *)( ((& __0__V66 )-> __O1__2ea.p =
# 1057 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1p )), (& __0__V66 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1057 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
return ;
} }

# 1061 "/home/claude/cfront-3/src/template.cpp"
{ Pbase __3q ;

# 1061 "/home/claude/cfront-3/src/template.cpp"
__3q = (((struct basetype *)(((struct basetype *)__3qual -> __O1__4expr.tp ))));
if (__3q && (__3q -> base__4node == 119 ))
# 1063 "/home/claude/cfront-3/src/template.cpp"
switch (get_class_base__FP8basetype ( __3q ) ){ 
# 1064 "/home/claude/cfront-3/src/template.cpp"
case 5:
# 1065 "/home/claude/cfront-3/src/template.cpp"
owner__17templ_compilation = (((struct templ_classdef *)(((struct templ_classdef *)__3q -> b_name__8basetype ->
# 1065 "/home/claude/cfront-3/src/template.cpp"
__O1__4expr.tp ))))-> inst__14templ_classdef -> def__10templ_inst ;
if (! check_qualifier__10templ_instFP9name_list ( get_template_class__FP8basetype ( __3q ) -> inst__14templ_classdef , params__17templ_compilation ) )
# 1067 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1067 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V67 ;

# 1067 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n: QrZs must match theY formalZs", (const struct ea *)( ((& __0__V67 )-> __O1__2ea.p =
# 1067 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1p )), (& __0__V67 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1067 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
} break ;
case 2:
# 1071 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1071 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V68 ;

# 1071 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V69 ;

# 1071 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"Qr%n for%n must specifyYZs", (const struct ea *)( ((& __0__V68 )-> __O1__2ea.p =
# 1071 "/home/claude/cfront-3/src/template.cpp"
((const void *)__3qual )), (& __0__V68 )) , (const struct ea *)( ((& __0__V69 )-> __O1__2ea.p = ((const void
# 1071 "/home/claude/cfront-3/src/template.cpp"
*)__1p )), (& __0__V69 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
default :
# 1074 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1074 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V70 ;

# 1074 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V71 ;

# 1074 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"Qr%n for%n wasn't aYC", (const struct ea *)( ((& __0__V70 )-> __O1__2ea.p =
# 1074 "/home/claude/cfront-3/src/template.cpp"
((const void *)__3qual )), (& __0__V70 )) , (const struct ea *)( ((& __0__V71 )-> __O1__2ea.p = ((const void
# 1074 "/home/claude/cfront-3/src/template.cpp"
*)__1p )), (& __0__V71 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return ;
} } }
{ Pdata __3dat ;

# 1077 "/home/claude/cfront-3/src/template.cpp"
__3dat = collect_data_member__5templFP4name ( owner__17templ_compilation , __1p ) ;
__3dat -> templ_refs__14basic_template = templ_refs__17templ_compilation ;
__3dat -> formals__14basic_template = params__17templ_compilation ;
check_formals__14basic_templateFP9name_list ( (struct basic_template *)owner__17templ_compilation , params__17templ_compilation ) ;
break ;

# 1081 "/home/claude/cfront-3/src/template.cpp"
}

# 1081 "/home/claude/cfront-3/src/template.cpp"
}
}
}

# 1086 "/home/claude/cfront-3/src/template.cpp"
clear_ref_templ__17templ_compilationFv ( __0this ) ;
param_end__17templ_compilation = (params__17templ_compilation = 0 );
if (__1forward_definition ){ 
# 1093 "/home/claude/cfront-3/src/template.cpp"
if (owner__17templ_compilation )
# 1094 "/home/claude/cfront-3/src/template.cpp"
instantiate_forward_decl__5templFv ( owner__17templ_compilation ) ;
else { 
# 1096 "/home/claude/cfront-3/src/template.cpp"
instantiate_forward_decl__17function_templateFv ( f_owner__17templ_compilation ) ;
}
}

# 1100 "/home/claude/cfront-3/src/template.cpp"
parsed_template__17templ_compilation = (owner__17templ_compilation ?(((struct basic_template *)(((struct basic_template *)owner__17templ_compilation )))):(((struct basic_template *)(((struct basic_template *)f_owner__17templ_compilation )))));
owner__17templ_compilation = 0 ;
f_owner__17templ_compilation = 0 ;
}

# 1106 "/home/claude/cfront-3/src/template.cpp"
void clear_friend_ref_templ__17templ_compilationFv (register struct templ_compilation *__0this ){ 
# 1107 "/home/claude/cfront-3/src/template.cpp"
{ { Pcons __1p ;

# 1107 "/home/claude/cfront-3/src/template.cpp"
__1p = friend_templ_refs__17templ_compilation ;

# 1107 "/home/claude/cfront-3/src/template.cpp"
for(;__1p ;__1p = __1p -> cdr__4cons ) 
# 1108 "/home/claude/cfront-3/src/template.cpp"
(((struct templ_inst *)(((struct templ_inst *)__1p -> car__4cons ))))-> friend_refp__10templ_inst = 0;
friend_templ_refs__17templ_compilation = 0 ;
last_friend_cons__17templ_compilation = 0 ;

# 1110 "/home/claude/cfront-3/src/template.cpp"
}

# 1110 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1114 "/home/claude/cfront-3/src/template.cpp"
void clear_ref_templ__17templ_compilationFv (register struct templ_compilation *__0this ){ 
# 1122 "/home/claude/cfront-3/src/template.cpp"
{ { Pcons __1p ;

# 1122 "/home/claude/cfront-3/src/template.cpp"
__1p = templ_refs__17templ_compilation ;

# 1122 "/home/claude/cfront-3/src/template.cpp"
for(;__1p ;__1p = __1p -> cdr__4cons ) 
# 1123 "/home/claude/cfront-3/src/template.cpp"
(((struct templ_inst *)(((struct templ_inst *)__1p -> car__4cons ))))-> refp__10templ_inst = 0;
templ_refs__17templ_compilation = 0 ;
last_cons__17templ_compilation = 0 ;

# 1125 "/home/claude/cfront-3/src/template.cpp"
}

# 1125 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1129 "/home/claude/cfront-3/src/template.cpp"
void instantiate_ref_templ__17templ_compilationFv (register struct templ_compilation *__0this )
# 1133 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1134 "/home/claude/cfront-3/src/template.cpp"
{ { Pcons __1p ;

# 1134 "/home/claude/cfront-3/src/template.cpp"
__1p = templ_refs__17templ_compilation ;

# 1134 "/home/claude/cfront-3/src/template.cpp"
for(;__1p ;__1p = __1p -> cdr__4cons ) { 
# 1135 "/home/claude/cfront-3/src/template.cpp"
if (__1p -> cdr__4cons )
# 1136 "/home/claude/cfront-3/src/template.cpp"
notinstflag = 1 ;
else 
# 1138 "/home/claude/cfront-3/src/template.cpp"
notinstflag = 0 ;
instantiate__10templ_instF4bool ( ((struct templ_inst *)(((struct templ_inst *)__1p -> car__4cons ))), 0) ;
}
clear_ref_templ__17templ_compilationFv ( __0this ) ;

# 1141 "/home/claude/cfront-3/src/template.cpp"
}

# 1141 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1145 "/home/claude/cfront-3/src/template.cpp"
static void data_copy_hook__FPvRP4node10node_classR16tree_node_actionRi (void *__1__A74 , Pnode *__1node , int __1__A75 , 
# 1146 "/home/claude/cfront-3/src/template.cpp"
int *__1action , int *__1never_see_again )
# 1147 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1150 "/home/claude/cfront-3/src/template.cpp"
((*__1never_see_again ))= 1 ;
switch (((*__1node ))-> base__4node ){ 
# 1152 "/home/claude/cfront-3/src/template.cpp"
case 85 :
# 1153 "/home/claude/cfront-3/src/template.cpp"
if (((*__1node ))== (((struct node *)sta_name )))
# 1154 "/home/claude/cfront-3/src/template.cpp"
{ ((*__1action ))= 1;

# 1154 "/home/claude/cfront-3/src/template.cpp"
return ;

# 1154 "/home/claude/cfront-3/src/template.cpp"
}
default :
# 1156 "/home/claude/cfront-3/src/template.cpp"
((*__1action ))= 0;
return ;
}
}

# 215 "/home/claude/cfront-3/src/hash.h"

# 51 "/home/claude/cfront-3/src/tree_copy.h"

# 84 "/home/claude/cfront-3/src/hash.h"
int *__vc__4HashFi (struct Hash *__0this , int __1k );

# 354 "/home/claude/cfront-3/src/template.h"
Pcons ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons (struct basic_inst *__0this , struct pointer_hash *, struct tree_copy_info *, Pcons );

# 68 "/home/claude/cfront-3/src/tree_copy.h"
extern void copy_tree__FRP4nodeR14tree_copy_infoP4Hash (Pnode *__0n , struct tree_copy_info *__0tci , struct Hash *__0cht );

# 216 "/home/claude/cfront-3/src/hash.h"

# 1162 "/home/claude/cfront-3/src/template.cpp"
Pname data_copy__10templ_instFP13data_templateRP4cons (register struct templ_inst *__0this , Pdata __1dat , Pcons *__1templ_refs )
# 1163 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1164 "/home/claude/cfront-3/src/template.cpp"
struct pointer_hash __1fcorr ;

# 1165 "/home/claude/cfront-3/src/template.cpp"
struct name *__0_result ;

# 1165 "/home/claude/cfront-3/src/template.cpp"
struct pointer_hash *__2__X76 ;

# 1164 "/home/claude/cfront-3/src/template.cpp"
( (__2__X76 = __0this -> corr__10basic_inst ), ( (__ct__4HashFR4Hash ( ((struct Hash *)(& __1fcorr )), (struct Hash *)__2__X76 ) ), (& __1fcorr ))
# 1164 "/home/claude/cfront-3/src/template.cpp"
) ;

# 1166 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1167 "/home/claude/cfront-3/src/template.cpp"
struct tree_copy_info __2info ;
Pnode __2root ;

# 1167 "/home/claude/cfront-3/src/template.cpp"
( (( ((& __2info )-> hook_info__14tree_copy_info = 0 ), ( ((& __2info )-> node_hook__14tree_copy_info = 0 ), ((& __2info )-> malloc_hook__14tree_copy_info =
# 1167 "/home/claude/cfront-3/src/template.cpp"
0 )) ) ), (& __2info )) ;
__2root = (struct node *)__1dat -> dat_mem__13data_template ;

# 1170 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __2fformal ;

# 1170 "/home/claude/cfront-3/src/template.cpp"
Plist __2cformal ;

# 1170 "/home/claude/cfront-3/src/template.cpp"
__2fformal = __1dat -> formals__14basic_template ;

# 1170 "/home/claude/cfront-3/src/template.cpp"
__2cformal = __0this -> inst_formals__10basic_inst ;

# 1170 "/home/claude/cfront-3/src/template.cpp"
for(;__2fformal ;( (__2fformal = __2fformal -> l__9name_list ), (__2cformal = __2cformal -> l__9name_list )) ) 
# 1171 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1172 "/home/claude/cfront-3/src/template.cpp"
((*__vc__4HashFi ( (struct Hash *)(& __1fcorr ), (int
# 1172 "/home/claude/cfront-3/src/template.cpp"
)(((unsigned long )__2fformal -> f__9name_list ))) ))= (((unsigned long )__2cformal -> f__9name_list ));
if (((*__vc__4HashFi ( (struct Hash *)(& __1fcorr ), (int )(((unsigned long )__2fformal -> f__9name_list ))) ))!= (((unsigned long )__2cformal ->
# 1173 "/home/claude/cfront-3/src/template.cpp"
f__9name_list )))
# 1174 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"templ_inst::fuction_copy: hash table bug") ;
}

# 1177 "/home/claude/cfront-3/src/template.cpp"
__2info . node_hook__14tree_copy_info = (data_copy_hook__FPvRP4node10node_classR16tree_node_actionRi );
__2info . hook_info__14tree_copy_info = (void *)__0this ;

# 1180 "/home/claude/cfront-3/src/template.cpp"
((*__1templ_refs ))= ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons ( (struct basic_inst *)__0this , (struct pointer_hash *)(& __1fcorr ), (struct tree_copy_info *)(& __2info ), (*__1templ_refs )) ;
if (((*__vc__4HashFi ( (struct Hash *)(& __1fcorr ), (int )(((unsigned long )__0this -> def__10templ_inst -> namep__5templ ))) ))!= (((unsigned long
# 1181 "/home/claude/cfront-3/src/template.cpp"
)__0this -> tname__10basic_inst )))
# 1182 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"Y to instantiationTN correspondence is missing") ;

# 1184 "/home/claude/cfront-3/src/template.cpp"
copy_tree__FRP4nodeR14tree_copy_infoP4Hash ( (Pnode *)(& __2root ), (struct tree_copy_info *)(& __2info ), (struct Hash *)(& __1fcorr )) ;
{ { __0_result = (((struct name *)(((struct name *)__2root ))));

# 1185 "/home/claude/cfront-3/src/template.cpp"
( (((void )(((void )( ( ((((struct Hash *)(& __1fcorr )))?(((void )( __dl__FPv ( (void *)(((struct Hash *)(& __1fcorr )))->
# 1185 "/home/claude/cfront-3/src/template.cpp"
tab__4Hash ) , ((((struct Hash *)(& __1fcorr )))?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) , (((void )0 ))) )))))
# 1185 "/home/claude/cfront-3/src/template.cpp"
;
} 
# 1185 "/home/claude/cfront-3/src/template.cpp"
return __0_result ;
} 
# 1185 "/home/claude/cfront-3/src/template.cpp"
}

# 1185 "/home/claude/cfront-3/src/template.cpp"
}
}
}

# 231 "/home/claude/cfront-3/src/template.h"
int instantiate_bodies__5templFv (struct templ *__0this );

# 1190 "/home/claude/cfront-3/src/template.cpp"
void end_of_compilation__17templ_compilationFv (struct templ_compilation *__0this )
# 1197 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1198 "/home/claude/cfront-3/src/template.cpp"
int __1change ;

# 1198 "/home/claude/cfront-3/src/template.cpp"
__1change = 0;
do { 
# 1200 "/home/claude/cfront-3/src/template.cpp"
__1change = 0;
{ { Ptempl __2p ;

# 1201 "/home/claude/cfront-3/src/template.cpp"
__2p = list__17templ_compilation ;

# 1201 "/home/claude/cfront-3/src/template.cpp"
for(;__2p ;__2p = __2p -> next__5templ ) 
# 1203 "/home/claude/cfront-3/src/template.cpp"
__1change = ((__1change | instantiate_bodies__5templFv ( __2p ) )?1:0);

# 1203 "/home/claude/cfront-3/src/template.cpp"
}

# 1203 "/home/claude/cfront-3/src/template.cpp"
}
}
while (__1change );

# 1205 "/home/claude/cfront-3/src/template.cpp"
}

# 492 "/home/claude/cfront-3/src/template.h"

# 1208 "/home/claude/cfront-3/src/template.cpp"
bit dinst_body__4nameFv (register struct name *__0this )
# 1209 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1212 "/home/claude/cfront-3/src/template.cpp"
if (((((data_flag == 0 )&& (all_flag == 0 ))&& (alltc_flag == 0 ))&& (curr_inst == dummyinst ))&& (curr_inst != 0 ))
# 1219 "/home/claude/cfront-3/src/template.cpp"
return
# 1219 "/home/claude/cfront-3/src/template.cpp"
(unsigned char )0 ;

# 1222 "/home/claude/cfront-3/src/template.cpp"
if (((all_flag == 0 )&& (curr_inst != dummyinst ))&& (curr_inst != 0 ))
# 1227 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )0 ;

# 1229 "/home/claude/cfront-3/src/template.cpp"
{ bit __1instflag ;

# 1229 "/home/claude/cfront-3/src/template.cpp"
__1instflag = 0 ;

# 1231 "/home/claude/cfront-3/src/template.cpp"
{ { int __1i ;

# 1232 "/home/claude/cfront-3/src/template.cpp"
struct Block_Pchar *__0__X77 ;

# 1231 "/home/claude/cfront-3/src/template.cpp"
__1i = 0 ;

# 1231 "/home/claude/cfront-3/src/template.cpp"
for(;__1i < nodatainst ;__1i ++ ) 
# 1232 "/home/claude/cfront-3/src/template.cpp"
if (strcmp ( (const char *)((*( (__0__X77 = (& instdata )), ( (((Pchar *)(& (__0__X77 ->
# 1232 "/home/claude/cfront-3/src/template.cpp"
p__11Block_Pchar [__1i ]))))) ) )), __0this -> __O2__4expr.string ) == 0 )
# 1233 "/home/claude/cfront-3/src/template.cpp"
__1instflag = 1 ;

# 1235 "/home/claude/cfront-3/src/template.cpp"
if (__1instflag && (curr_inst != 0 ))
# 1237 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )0 ;

# 1239 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )1 ;

# 1239 "/home/claude/cfront-3/src/template.cpp"
}

# 1239 "/home/claude/cfront-3/src/template.cpp"
}

# 1239 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 1243 "/home/claude/cfront-3/src/template.cpp"
bit finst_body__4nameFv (register struct name *__0this )
# 1244 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1244 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 1244 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 1244 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 1245 "/home/claude/cfront-3/src/template.cpp"
if ((((all_flag == 0 )&& (ft_flag == 0 ))&& (fcurr_inst != 0 ))&& (( ((__0this -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0this ->
# 1245 "/home/claude/cfront-3/src/template.cpp"
__O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)(
# 1245 "/home/claude/cfront-3/src/template.cpp"
((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const void *)__0this )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __0this ->
# 1245 "/home/claude/cfront-3/src/template.cpp"
__O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) ,
# 1245 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) -> f_inline__3fct == 0 ))
# 1251 "/home/claude/cfront-3/src/template.cpp"
return (unsigned
# 1251 "/home/claude/cfront-3/src/template.cpp"
char )0 ;

# 1253 "/home/claude/cfront-3/src/template.cpp"
if (((ft_flag && (fdummyinst != fcurr_inst ))&& (fcurr_inst != 0 ))&& (( ((__0this -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp )))):(
# 1253 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((&
# 1253 "/home/claude/cfront-3/src/template.cpp"
__0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const void *)__0this )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __0this -> __O1__4expr.tp ->
# 1253 "/home/claude/cfront-3/src/template.cpp"
base__4node ), ( (( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const
# 1253 "/home/claude/cfront-3/src/template.cpp"
struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) -> f_inline__3fct == 0 ))
# 1259 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char
# 1259 "/home/claude/cfront-3/src/template.cpp"
)0 ;

# 1261 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )1 ;
}

# 492 "/home/claude/cfront-3/src/template.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 1265 "/home/claude/cfront-3/src/template.cpp"
bit inst_body__4nameFv (register struct name *__0this )
# 1266 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1267 "/home/claude/cfront-3/src/template.cpp"
bit __1inst_flag ;

# 1267 "/home/claude/cfront-3/src/template.cpp"
__1inst_flag = 0 ;

# 1269 "/home/claude/cfront-3/src/template.cpp"
{ { int __1i ;

# 1270 "/home/claude/cfront-3/src/template.cpp"
struct Block_Pchar *__0__X78 ;

# 1269 "/home/claude/cfront-3/src/template.cpp"
__1i = 0 ;

# 1269 "/home/claude/cfront-3/src/template.cpp"
for(;__1i < noinst ;__1i ++ ) 
# 1270 "/home/claude/cfront-3/src/template.cpp"
if (strcmp ( __0this -> __O2__4expr.string , (const char *)((*( (__0__X78 = (& instfct )), (
# 1270 "/home/claude/cfront-3/src/template.cpp"
(((Pchar *)(& (__0__X78 -> p__11Block_Pchar [__1i ]))))) ) ))) == 0 )
# 1271 "/home/claude/cfront-3/src/template.cpp"
__1inst_flag = 1 ;

# 1276 "/home/claude/cfront-3/src/template.cpp"
{ bit __1datainstflag ;

# 1276 "/home/claude/cfront-3/src/template.cpp"
__1datainstflag = 0 ;

# 1278 "/home/claude/cfront-3/src/template.cpp"
{ { int __1j ;

# 1279 "/home/claude/cfront-3/src/template.cpp"
struct Block_Pchar *__0__X79 ;

# 1278 "/home/claude/cfront-3/src/template.cpp"
__1j = 0 ;

# 1278 "/home/claude/cfront-3/src/template.cpp"
for(;__1j < nodatainst ;__1j ++ ) 
# 1279 "/home/claude/cfront-3/src/template.cpp"
if (strcmp ( (const char *)((*( (__0__X79 = (& instdata )), ( (((Pchar *)(& (__0__X79 ->
# 1279 "/home/claude/cfront-3/src/template.cpp"
p__11Block_Pchar [__1j ]))))) ) )), __0this -> __O2__4expr.string ) == 0 )
# 1280 "/home/claude/cfront-3/src/template.cpp"
__1datainstflag = 1 ;

# 1282 "/home/claude/cfront-3/src/template.cpp"
{ Pfct __1ft ;

# 1283 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 1283 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 1283 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 1282 "/home/claude/cfront-3/src/template.cpp"
__1ft = ( ((__0this -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0this -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char
# 1282 "/home/claude/cfront-3/src/template.cpp"
*)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const void *)__0this )),
# 1282 "/home/claude/cfront-3/src/template.cpp"
(& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __0this -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500q2z144hdwckg )->
# 1282 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 1282 "/home/claude/cfront-3/src/template.cpp"
, (((struct fct *)0 ))) )) ;

# 1284 "/home/claude/cfront-3/src/template.cpp"
if (((((((__1inst_flag == 0 )&& (curr_inst != 0 ))&& (curr_inst == dummyinst ))&& (all_flag == 0 ))&& (alltc_flag == 0 ))&& (__1ft -> f_virtual__3fct == 0 ))&&
# 1284 "/home/claude/cfront-3/src/template.cpp"
(__1ft -> f_inline__3fct == 0 ))
# 1293 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )0 ;

# 1295 "/home/claude/cfront-3/src/template.cpp"
if (((((__1datainstflag && (curr_inst != 0 ))&& (curr_inst == dummyinst ))&& __1ft -> f_virtual__3fct )&& (all_flag == 0 ))&& (alltc_flag == 0 ))
# 1302 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char
# 1302 "/home/claude/cfront-3/src/template.cpp"
)0 ;

# 1305 "/home/claude/cfront-3/src/template.cpp"
if (((((((curr_inst == dummyinst )&& (curr_inst != 0 ))&& __1ft -> f_virtual__3fct )&& (__1ft -> f_inline__3fct == 0 ))&& (data_flag == 0 ))&& (all_flag == 0 ))&&
# 1305 "/home/claude/cfront-3/src/template.cpp"
(alltc_flag == 0 ))
# 1314 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )0 ;

# 1319 "/home/claude/cfront-3/src/template.cpp"
if (((((all_flag == 0 )&& (curr_inst != dummyinst ))&& (curr_inst != 0 ))&& (__1ft -> f_inline__3fct == 0 ))&& (__1ft -> f_is_inline__3fct == 0 ))
# 1326 "/home/claude/cfront-3/src/template.cpp"
return (unsigned
# 1326 "/home/claude/cfront-3/src/template.cpp"
char )0 ;

# 1330 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )1 ;

# 1330 "/home/claude/cfront-3/src/template.cpp"
}

# 1330 "/home/claude/cfront-3/src/template.cpp"
}

# 1330 "/home/claude/cfront-3/src/template.cpp"
}

# 1330 "/home/claude/cfront-3/src/template.cpp"
}

# 1330 "/home/claude/cfront-3/src/template.cpp"
}

# 1330 "/home/claude/cfront-3/src/template.cpp"
}
}

# 432 "/home/claude/cfront-3/src/template.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 234 "/home/claude/cfront-3/src/cfront.h"

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 446 "/home/claude/cfront-3/src/template.h"
Pname function_copy__10templ_instFP17function_templateRP4cons (struct templ_inst *__0this , Pfunt , Pcons *);

# 357 "/home/claude/cfront-3/src/template.h"
void save_state__10basic_instFP4name (struct basic_inst *__0this , Pname __1p );

# 940 "/home/claude/cfront-3/src/cfront.h"
Pname dcl__4nameFP5tableUc (struct name *__0this , Ptable , TOK );

# 358 "/home/claude/cfront-3/src/template.h"
void restore_state__10basic_instFv (struct basic_inst *__0this );

# 946 "/home/claude/cfront-3/src/cfront.h"
void simpl__4nameFv (struct name *__0this );

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 948 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4nameFUc (struct name *__0this , TOK );

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 535 "/home/claude/cfront-3/src/cfront.h"
extern Pexpr mk_zero_init__FP4typeP4nameT2 (Ptype , Pname , Pname );

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 1334 "/home/claude/cfront-3/src/template.cpp"
int instantiate_bodies__5templFv (register struct templ *__0this )
# 1343 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1344 "/home/claude/cfront-3/src/template.cpp"
int __1change ;

# 1344 "/home/claude/cfront-3/src/template.cpp"
__1change = 0;
if ((! __0this -> fns__5templ )&& (! __0this -> data__5templ ))return __1change ;

# 1347 "/home/claude/cfront-3/src/template.cpp"
{ { Ptempl_inst __1inst ;

# 1347 "/home/claude/cfront-3/src/template.cpp"
__1inst = __0this -> insts__5templ ;

# 1347 "/home/claude/cfront-3/src/template.cpp"
for(;__1inst ;__1inst = __1inst -> next__10templ_inst ) 
# 1349 "/home/claude/cfront-3/src/template.cpp"
if ((! __1inst -> forward__10templ_inst )&& (__1inst -> status__10basic_inst == 3))
# 1350 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1353 "/home/claude/cfront-3/src/template.cpp"
__1inst -> status__10basic_inst = 4;
__1change = 1;
{ Pclass __2ic ;

# 1356 "/home/claude/cfront-3/src/template.cpp"
struct dcl_context *__0__X85 ;

# 1355 "/home/claude/cfront-3/src/template.cpp"
__2ic = ( (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__1inst -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))))) ;

# 1357 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1358 "/home/claude/cfront-3/src/template.cpp"
int __3i ;

# 1360 "/home/claude/cfront-3/src/template.cpp"
{ { Pname __3fn ;

# 1361 "/home/claude/cfront-3/src/template.cpp"
struct table *__0__X81 ;

# 1361 "/home/claude/cfront-3/src/template.cpp"
int __2__X82 ;

# 1361 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 1361 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 1361 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 1361 "/home/claude/cfront-3/src/template.cpp"
struct table *__0__X83 ;

# 1361 "/home/claude/cfront-3/src/template.cpp"
int __2__X84 ;

# 1360 "/home/claude/cfront-3/src/template.cpp"
__3fn = ( (__0__X83 = __2ic -> memtbl__8classdef ), ( (__2__X84 = (__3i = 1 )), ( (((__2__X84 <= 0 )|| (__0__X83 -> free_slot__5table <=
# 1360 "/home/claude/cfront-3/src/template.cpp"
__2__X84 ))?(((struct name *)0 )):(__0__X83 -> entries__5table [__2__X84 ]))) ) ) ;

# 1360 "/home/claude/cfront-3/src/template.cpp"
for(;__3fn ;__3fn = (__3fn -> n_tbl_list__4name ?__3fn -> n_tbl_list__4name :( (__0__X81 = __2ic -> memtbl__8classdef ), ( (__2__X82 = (++ __3i )), ( (((__2__X82 <= 0 )||
# 1360 "/home/claude/cfront-3/src/template.cpp"
(__0__X81 -> free_slot__5table <= __2__X82 ))?(((struct name *)0 )):(__0__X81 -> entries__5table [__2__X82 ]))) ) ) )) 
# 1361 "/home/claude/cfront-3/src/template.cpp"
if (((__3fn -> base__4node == 85 )&& (__3fn -> __O1__4expr.tp ->
# 1361 "/home/claude/cfront-3/src/template.cpp"
base__4node == 108 ))&& ( ((__3fn -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__3fn -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const
# 1361 "/home/claude/cfront-3/src/template.cpp"
char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const void
# 1361 "/home/claude/cfront-3/src/template.cpp"
*)__3fn )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __3fn -> __O1__4expr.tp -> base__4node ), ( (( ((&
# 1361 "/home/claude/cfront-3/src/template.cpp"
__0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 , (const struct
# 1361 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) , (((struct fct *)0 ))) )) -> body__3fct )
# 1363 "/home/claude/cfront-3/src/template.cpp"
__3fn -> n_redefined__4name = 1 ;

# 1363 "/home/claude/cfront-3/src/template.cpp"
}

# 1363 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1366 "/home/claude/cfront-3/src/template.cpp"
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 1366 "/home/claude/cfront-3/src/template.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;

# 1366 "/home/claude/cfront-3/src/template.cpp"
cc -> cot__11dcl_context = 0 ;

# 1366 "/home/claude/cfront-3/src/template.cpp"
cc -> not4__11dcl_context = 0 ;

# 1366 "/home/claude/cfront-3/src/template.cpp"
cc -> tot__11dcl_context = 0 ;

# 1366 "/home/claude/cfront-3/src/template.cpp"
cc -> c_this__11dcl_context = 0 ;
{ { Pfunt __2fnt ;

# 1368 "/home/claude/cfront-3/src/template.cpp"
struct dcl_context *__0__X86 ;

# 1368 "/home/claude/cfront-3/src/template.cpp"
struct dcl_context *__0__X87 ;

# 1367 "/home/claude/cfront-3/src/template.cpp"
__2fnt = __0this -> fns__5templ ;

# 1367 "/home/claude/cfront-3/src/template.cpp"
for(;__2fnt ;__2fnt = __2fnt -> next__17function_template ) { 
# 1368 "/home/claude/cfront-3/src/template.cpp"
Pcons __3templ_ref_copy ;
Pname __3fn ;

# 1368 "/home/claude/cfront-3/src/template.cpp"
__3templ_ref_copy = __2fnt -> templ_refs__14basic_template ;
__3fn = function_copy__10templ_instFP17function_templateRP4cons ( __1inst , __2fnt , (Pcons *)(& __3templ_ref_copy )) ;

# 1373 "/home/claude/cfront-3/src/template.cpp"
__3fn -> __O2__4name.n_qualifier = __1inst -> namep__10basic_inst ;

# 1377 "/home/claude/cfront-3/src/template.cpp"
if (__3fn -> n_oper__4name != 97 )__3fn -> __O4__4expr.n_table = 0 ;
__3fn -> n_tbl_list__4name = 0 ;

# 1385 "/home/claude/cfront-3/src/template.cpp"
if (! strcmp ( __3fn -> __O2__4expr.string , __0this -> namep__5templ -> __O2__4expr.string ) )
# 1386 "/home/claude/cfront-3/src/template.cpp"
__3fn -> __O2__4expr.string = __1inst -> namep__10basic_inst -> __O2__4expr.string ;

# 1388 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1389 "/home/claude/cfront-3/src/template.cpp"
save_state__10basic_instFP4name ( (struct basic_inst *)__1inst , __3fn ) ;

# 1393 "/home/claude/cfront-3/src/template.cpp"
{ { Pcons __4pc ;

# 1394 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 1394 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 1394 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 1393 "/home/claude/cfront-3/src/template.cpp"
__4pc = __3templ_ref_copy ;

# 1393 "/home/claude/cfront-3/src/template.cpp"
for(;__4pc ;__4pc = __4pc -> cdr__4cons ) 
# 1394 "/home/claude/cfront-3/src/template.cpp"
instantiate__10templ_instF4bool ( ((struct templ_inst *)(((struct templ_inst *)__4pc -> car__4cons ))), 0) ;

# 1396 "/home/claude/cfront-3/src/template.cpp"
curr_inst = __1inst ;

# 1398 "/home/claude/cfront-3/src/template.cpp"
if (((__3fn = dcl__4nameFP5tableUc ( __3fn , gtbl , (unsigned char )14 ) )== 0 )|| error_count ){ 
# 1399 "/home/claude/cfront-3/src/template.cpp"
restore_state__10basic_instFv ( (struct basic_inst *)__1inst )
# 1399 "/home/claude/cfront-3/src/template.cpp"
;
continue ;

# 1400 "/home/claude/cfront-3/src/template.cpp"
}

# 1402 "/home/claude/cfront-3/src/template.cpp"
curr_inst = __1inst ;

# 1404 "/home/claude/cfront-3/src/template.cpp"
if (se_opt && (inst_body__4nameFv ( __3fn ) == 0 ))
# 1405 "/home/claude/cfront-3/src/template.cpp"
suppress_error ++ ;

# 1407 "/home/claude/cfront-3/src/template.cpp"
simpl__4nameFv ( __3fn ) ;

# 1409 "/home/claude/cfront-3/src/template.cpp"
if (se_opt && (inst_body__4nameFv ( __3fn ) == 0 )){ 
# 1410 "/home/claude/cfront-3/src/template.cpp"
suppress_error -- ;
}

# 1413 "/home/claude/cfront-3/src/template.cpp"
if (dtpt_opt && (inst_body__4nameFv ( __3fn ) == 0 ))
# 1414 "/home/claude/cfront-3/src/template.cpp"
( ((__3fn -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__3fn -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 (
# 1414 "/home/claude/cfront-3/src/template.cpp"
(int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )->
# 1414 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.p = ((const void *)__3fn )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __3fn -> __O1__4expr.tp -> base__4node ),
# 1414 "/home/claude/cfront-3/src/template.cpp"
( (( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct
# 1414 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) -> body__3fct = 0 ;

# 1416 "/home/claude/cfront-3/src/template.cpp"
dcl_print__4nameFUc ( __3fn , (unsigned char )0 ) ;
curr_inst = 0 ;
restore_state__10basic_instFv ( (struct basic_inst *)__1inst ) ;

# 1418 "/home/claude/cfront-3/src/template.cpp"
}

# 1418 "/home/claude/cfront-3/src/template.cpp"
}
}
}
( ( (cc -- ), (((void )0 ))) ) ;

# 1423 "/home/claude/cfront-3/src/template.cpp"
__1inst -> status__10basic_inst = 2;
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 1424 "/home/claude/cfront-3/src/template.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;

# 1424 "/home/claude/cfront-3/src/template.cpp"
cc -> cot__11dcl_context = 0 ;

# 1424 "/home/claude/cfront-3/src/template.cpp"
cc -> not4__11dcl_context = 0 ;

# 1424 "/home/claude/cfront-3/src/template.cpp"
cc -> tot__11dcl_context = 0 ;

# 1424 "/home/claude/cfront-3/src/template.cpp"
cc -> c_this__11dcl_context = 0 ;
{ { Pdata __2dat ;

# 1426 "/home/claude/cfront-3/src/template.cpp"
struct dcl_context *__0__X89 ;

# 1425 "/home/claude/cfront-3/src/template.cpp"
__2dat = __0this -> data__5templ ;

# 1425 "/home/claude/cfront-3/src/template.cpp"
for(;__2dat ;__2dat = __2dat -> next__13data_template ) 
# 1426 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1427 "/home/claude/cfront-3/src/template.cpp"
Pcons __3templ_ref_copy ;
Pname __3dn ;

# 1429 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X88 ;

# 1427 "/home/claude/cfront-3/src/template.cpp"
__3templ_ref_copy = __2dat -> templ_refs__14basic_template ;
__3dn = look__5tableFPCcUc ( __2ic -> memtbl__8classdef , __2dat -> dat_mem__13data_template -> __O2__4expr.string , (unsigned char )0 ) ;

# 1430 "/home/claude/cfront-3/src/template.cpp"
if ((! __3dn )|| (__3dn -> n_stclass__4name != 31 ))
# 1431 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1431 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V80 ;

# 1431 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n: only static dataMs can beZized", (const struct ea *)( (__2__X88 = (const void
# 1431 "/home/claude/cfront-3/src/template.cpp"
*)__2dat -> dat_mem__13data_template ), ( ((& __0__V80 )-> __O1__2ea.p = __2__X88 ), (& __0__V80 )) ) , (const struct ea *)ea0 ,
# 1431 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if (__3dn -> n_redefined__4name )continue ;
{ Pname __3n ;

# 1433 "/home/claude/cfront-3/src/template.cpp"
__3n = data_copy__10templ_instFP13data_templateRP4cons ( __1inst , __2dat , (Pcons *)(& __3templ_ref_copy )) ;
__3n -> __O2__4name.n_qualifier = __1inst -> namep__10basic_inst ;
__3n -> __O4__4expr.n_table = 0 ;

# 1435 "/home/claude/cfront-3/src/template.cpp"
__3n -> n_tbl_list__4name = 0 ;

# 1437 "/home/claude/cfront-3/src/template.cpp"
save_state__10basic_instFP4name ( (struct basic_inst *)__1inst , __3n ) ;
{ { Pcons __3pc ;

# 1438 "/home/claude/cfront-3/src/template.cpp"
__3pc = __3templ_ref_copy ;

# 1438 "/home/claude/cfront-3/src/template.cpp"
for(;__3pc ;__3pc = __3pc -> cdr__4cons ) 
# 1439 "/home/claude/cfront-3/src/template.cpp"
instantiate__10templ_instF4bool ( ((struct templ_inst *)(((struct templ_inst *)__3pc -> car__4cons ))), 0) ;

# 1441 "/home/claude/cfront-3/src/template.cpp"
curr_inst = __1inst ;

# 1443 "/home/claude/cfront-3/src/template.cpp"
if (((__3n = dcl__4nameFP5tableUc ( __3n , gtbl , (unsigned char )14 ) )== 0 )|| error_count )
# 1444 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1445 "/home/claude/cfront-3/src/template.cpp"
restore_state__10basic_instFv ( (struct basic_inst *)__1inst )
# 1445 "/home/claude/cfront-3/src/template.cpp"
;
continue ;

# 1446 "/home/claude/cfront-3/src/template.cpp"
}
simpl__4nameFv ( __3n ) ;

# 1449 "/home/claude/cfront-3/src/template.cpp"
mk_zero_init_flag = 0 ;

# 1451 "/home/claude/cfront-3/src/template.cpp"
if (((__3n -> n_stclass__4name == 31 )&& (__3n -> __O3__4expr.n_initializer == 0 ))&& (__3n -> n_evaluated__4name == 0 ))
# 1452 "/home/claude/cfront-3/src/template.cpp"
__3n -> __O3__4expr.n_initializer = mk_zero_init__FP4typeP4nameT2 ( __3n -> __O1__4expr.tp ,
# 1452 "/home/claude/cfront-3/src/template.cpp"
__3n , __3n ) ;

# 1454 "/home/claude/cfront-3/src/template.cpp"
if (dtpt_opt && (dinst_body__4nameFv ( __3n ) == 0 ))
# 1457 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1458 "/home/claude/cfront-3/src/template.cpp"
__3n -> __O3__4expr.n_initializer = 0 ;
mk_zero_init_flag = 1 ;
}

# 1462 "/home/claude/cfront-3/src/template.cpp"
if (((__3n -> n_stclass__4name != 31 )|| (! mk_zero_init_flag ))|| (! strict_opt ))
# 1463 "/home/claude/cfront-3/src/template.cpp"
dcl_print__4nameFUc ( __3n , (unsigned char )0 ) ;
curr_inst = 0 ;
mk_zero_init_flag = 0 ;
__3n -> n_dcl_printed__4name = 2 ;
restore_state__10basic_instFv ( (struct basic_inst *)__1inst ) ;

# 1467 "/home/claude/cfront-3/src/template.cpp"
}

# 1467 "/home/claude/cfront-3/src/template.cpp"
}

# 1467 "/home/claude/cfront-3/src/template.cpp"
}
}
( ( (cc -- ), (((void )0 ))) ) ;

# 1469 "/home/claude/cfront-3/src/template.cpp"
}

# 1469 "/home/claude/cfront-3/src/template.cpp"
}

# 1469 "/home/claude/cfront-3/src/template.cpp"
}

# 1469 "/home/claude/cfront-3/src/template.cpp"
}

# 1469 "/home/claude/cfront-3/src/template.cpp"
}
}
return __1change ;

# 1471 "/home/claude/cfront-3/src/template.cpp"
}

# 1471 "/home/claude/cfront-3/src/template.cpp"
}
}

# 227 "/home/claude/cfront-3/src/template.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 1475 "/home/claude/cfront-3/src/template.cpp"
Pname check_tname__17templ_compilationFP4name (register struct templ_compilation *__0this , Pname __1p )
# 1482 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1484 "/home/claude/cfront-3/src/template.cpp"
Ptempl __1t ;

# 1487 "/home/claude/cfront-3/src/template.cpp"
extern int in_friend ;

# 1494 "/home/claude/cfront-3/src/template.cpp"
extern Ptempl_inst pti ;

# 1495 "/home/claude/cfront-3/src/template.cpp"
struct classdef *__1__X91 ;

# 1495 "/home/claude/cfront-3/src/template.cpp"
struct classdef *__1__X92 ;

# 1484 "/home/claude/cfront-3/src/template.cpp"
__1t = is_template__17templ_compilationFP4name ( __0this , __1p ) ;
if (__1p -> n_template_arg__4name )__1p -> n_used__4name ++ ;
if (! __1t )return __1p ;
;
if ((in_progress__17templ_compilation && (in_friend == 0 ))&& ((owner__17templ_compilation && (owner__17templ_compilation -> namep__5templ == __1p ))|| ((! owner__17templ_compilation )&& ( (__1__X91 = ( (((struct
# 1488 "/home/claude/cfront-3/src/template.cpp"
classdef *)(((struct classdef *)__1t -> basep__5templ -> b_name__8basetype -> __O1__4expr.tp ))))) ), ( (__1__X92 = ccl ), ( ((__1__X91 == __1__X92 )?1 :((__1__X91 && __1__X92 )?(((int )same_class__8classdefFP8classdefi (
# 1488 "/home/claude/cfront-3/src/template.cpp"
__1__X91 , __1__X92 , 0 ) )):0 ))) ) ) )))
# 1491 "/home/claude/cfront-3/src/template.cpp"
return __1p ;

# 1494 "/home/claude/cfront-3/src/template.cpp"
;
if (pti && (pti -> def__10templ_inst == __1t ))
# 1496 "/home/claude/cfront-3/src/template.cpp"
return __1p ;

# 1498 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1498 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V90 ;

# 1498 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n needsY instantiationAs", (const struct ea *)( ((& __0__V90 )-> __O1__2ea.p =
# 1498 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1p )), (& __0__V90 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1498 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
return __1p ;
} }

# 1503 "/home/claude/cfront-3/src/template.cpp"
int current_template__17templ_compilationFP4nameP4expr (register struct templ_compilation *__0this , Pname __1p , Pexpr __1actuals )
# 1515 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1518 "/home/claude/cfront-3/src/template.cpp"
Ptype __1t ;
if ((((struct basetype *)(((struct basetype *)__1p -> __O1__4expr.tp ))))&& (((struct basetype *)(((struct basetype *)__1p -> __O1__4expr.tp ))))-> b_name__8basetype )
# 1520 "/home/claude/cfront-3/src/template.cpp"
__1t = (((struct basetype *)(((struct basetype *)__1p -> __O1__4expr.tp ))))->
# 1520 "/home/claude/cfront-3/src/template.cpp"
b_name__8basetype -> __O1__4expr.tp ;
else 
# 1522 "/home/claude/cfront-3/src/template.cpp"
__1t = 0 ;
if (in_progress__17templ_compilation && ((owner__17templ_compilation && (owner__17templ_compilation -> namep__5templ == __1p ))|| ((! owner__17templ_compilation )&& ((__1p -> __O1__4expr.tp -> base__4node == 119 )&& (__1t == (((struct
# 1523 "/home/claude/cfront-3/src/template.cpp"
type *)ccl )))))))
# 1526 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1527 "/home/claude/cfront-3/src/template.cpp"
Pexpr __2actual ;
Plist __2formal ;

# 1527 "/home/claude/cfront-3/src/template.cpp"
__2actual = __1actuals ;
__2formal = params__17templ_compilation ;
for(;__2formal && __2actual ;( (__2formal = __2formal -> l__9name_list ), (__2actual = __2actual -> __O3__4expr.e2 )) ) 
# 1530 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1531 "/home/claude/cfront-3/src/template.cpp"
if (__2formal -> f__9name_list -> n_template_arg__4name ==
# 1531 "/home/claude/cfront-3/src/template.cpp"
1)
# 1532 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1533 "/home/claude/cfront-3/src/template.cpp"
if (((((__2formal -> f__9name_list -> __O1__4expr.tp == (((struct type *)any_type )))&& __2actual -> __O2__4expr.e1 -> __O1__4expr.tp )&& (__2actual -> __O2__4expr.e1 -> __O1__4expr.tp -> base__4node ==
# 1533 "/home/claude/cfront-3/src/template.cpp"
97 ))&& ((((struct basetype *)(((struct basetype *)__2actual -> __O2__4expr.e1 -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp == (((struct type *)any_type ))))&& (strcmp ( (((struct basetype *)(((struct basetype *)__2actual ->
# 1533 "/home/claude/cfront-3/src/template.cpp"
__O2__4expr.e1 -> __O1__4expr.tp ))))-> b_name__8basetype -> __O2__4expr.string , __2formal -> f__9name_list -> __O2__4expr.string ) == 0 ))
# 1544 "/home/claude/cfront-3/src/template.cpp"
continue ;
else 
# 1546 "/home/claude/cfront-3/src/template.cpp"
break ;
}
else 
# 1549 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1550 "/home/claude/cfront-3/src/template.cpp"
if (((__2formal -> f__9name_list -> base__4node == 85 )&& (__2actual -> __O2__4expr.e1 -> base__4node == 85 ))&& (strcmp ( (((struct name *)(((struct
# 1550 "/home/claude/cfront-3/src/template.cpp"
name *)__2actual -> __O2__4expr.e1 ))))-> __O2__4expr.string , __2formal -> f__9name_list -> __O2__4expr.string ) == 0 ))
# 1557 "/home/claude/cfront-3/src/template.cpp"
continue ;
else 
# 1559 "/home/claude/cfront-3/src/template.cpp"
break ;
}
}
if ((! __2formal )&& (! __2actual ))return (int )1;
}
return (int )0;
}

# 252 "/home/claude/cfront-3/src/template.h"
struct function_template *__ct__17function_templateFR5templP9name_listP4name (struct function_template *__0this , struct templ *, Plist , Pname );

# 1568 "/home/claude/cfront-3/src/template.cpp"
Pfunt collect_function_member__5templFP4name (register struct templ *__0this , Pname __1fname )
# 1569 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1570 "/home/claude/cfront-3/src/template.cpp"
__1fname -> permanent__4node = 1 ;

# 1570 "/home/claude/cfront-3/src/template.cpp"
__1fname -> __O1__4expr.tp -> permanent__4node = 1 ;
(((struct fct *)(((struct fct *)__1fname -> __O1__4expr.tp ))))-> body__3fct -> permanent__4node = 1 ;
return __ct__17function_templateFR5templP9name_listP4name ( (struct function_template *)0 , (struct templ *)__0this , params__17templ_compilation , __1fname ) ;
}

# 270 "/home/claude/cfront-3/src/template.h"
struct data_template *__ct__13data_templateFR5templP9name_listP4name (struct data_template *__0this , struct templ *, Plist , Pname );

# 1576 "/home/claude/cfront-3/src/template.cpp"
Pdata collect_data_member__5templFP4name (register struct templ *__0this , Pname __1dname )
# 1577 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1578 "/home/claude/cfront-3/src/template.cpp"
__1dname -> permanent__4node = 1 ;

# 1578 "/home/claude/cfront-3/src/template.cpp"
__1dname -> __O1__4expr.tp -> permanent__4node = 1 ;
return __ct__13data_templateFR5templP9name_listP4name ( (struct data_template *)0 , (struct templ *)__0this , params__17templ_compilation , __1dname ) ;
}

# 1583 "/home/claude/cfront-3/src/template.cpp"
void check_formals_for_dups__FP9name_list (Plist __1formals )
# 1584 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1585 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __1fl1 ;

# 1585 "/home/claude/cfront-3/src/template.cpp"
__1fl1 = __1formals ;

# 1585 "/home/claude/cfront-3/src/template.cpp"
for(;__1fl1 ;__1fl1 = __1fl1 -> l__9name_list ) { 
# 1586 "/home/claude/cfront-3/src/template.cpp"
Pname __2n1 ;

# 1586 "/home/claude/cfront-3/src/template.cpp"
__2n1 = __1fl1 -> f__9name_list ;
{ { Plist __2fl2 ;

# 1587 "/home/claude/cfront-3/src/template.cpp"
__2fl2 = __1fl1 -> l__9name_list ;

# 1587 "/home/claude/cfront-3/src/template.cpp"
for(;__2fl2 ;__2fl2 = __2fl2 -> l__9name_list ) { 
# 1588 "/home/claude/cfront-3/src/template.cpp"
Pname __3n2 ;

# 1588 "/home/claude/cfront-3/src/template.cpp"
__3n2 = __2fl2 -> f__9name_list ;
if (strcmp ( __2n1 -> __O2__4expr.string , __3n2 -> __O2__4expr.string ) == 0 )
# 1590 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1590 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V93 ;

# 1590 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"YA%n redeclared inZ list", (const struct ea *)( ((& __0__V93 )-> __O1__2ea.p =
# 1590 "/home/claude/cfront-3/src/template.cpp"
((const void *)__2n1 )), (& __0__V93 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1590 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
} }

# 1591 "/home/claude/cfront-3/src/template.cpp"
}

# 1591 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1592 "/home/claude/cfront-3/src/template.cpp"
}

# 1592 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1279 "/home/claude/cfront-3/src/cfront.h"

# 1259 "/home/claude/cfront-3/src/cfront.h"

# 193 "/home/claude/cfront-3/src/template.h"

# 1596 "/home/claude/cfront-3/src/template.cpp"
bit contains_formal__FP4nameP8classdef (Pname __1formal , Pclass __1cl )
# 1597 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1597 "/home/claude/cfront-3/src/template.cpp"
int __1__Xt00awz144hdwckg ;

# 1599 "/home/claude/cfront-3/src/template.cpp"
if (__1cl -> class_base__8classdef == 0)return (unsigned char )0 ;
if (( (__1__Xt00awz144hdwckg = ((((struct type *)__1cl )-> base__4node == 108 )?(((struct fct *)(((struct fct *)((struct type *)__1cl )))))-> fct_base__3fct :((((struct type *)__1cl )-> base__4node == 6 )?(((struct
# 1600 "/home/claude/cfront-3/src/template.cpp"
classdef *)(((struct classdef *)((struct type *)__1cl )))))-> class_base__8classdef :(((int )0 ))))), (((unsigned char )((__1__Xt00awz144hdwckg == 4)|| (__1__Xt00awz144hdwckg == 5))))) ){ 
# 1601 "/home/claude/cfront-3/src/template.cpp"
Pexpr __2actuals ;

# 1601 "/home/claude/cfront-3/src/template.cpp"
__2actuals = (((struct templ_classdef *)(((struct templ_classdef *)__1cl ))))-> inst__14templ_classdef -> actuals__10basic_inst ;
for(;__2actuals ;__2actuals = __2actuals -> __O3__4expr.e2 ) { 
# 1603 "/home/claude/cfront-3/src/template.cpp"
Pexpr __3e ;

# 1603 "/home/claude/cfront-3/src/template.cpp"
__3e = __2actuals -> __O2__4expr.e1 ;
if ((__3e -> base__4node != 85 )|| (__3e -> __O1__4expr.tp -> base__4node != 97 ))continue ;
{ Pname __3tn ;

# 1606 "/home/claude/cfront-3/src/template.cpp"
struct type *__0__X94 ;

# 1605 "/home/claude/cfront-3/src/template.cpp"
__3tn = ( (__0__X94 = __3e -> __O1__4expr.tp ), ( (((struct basetype *)(((struct basetype *)__0__X94 ))))-> b_name__8basetype ) ) ;
if (strcmp ( __1formal -> __O2__4expr.string , __3tn -> __O2__4expr.string ) == 0 )
# 1607 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )1 ;

# 1607 "/home/claude/cfront-3/src/template.cpp"
}
}
}
else { 
# 1612 "/home/claude/cfront-3/src/template.cpp"
Ptempl __2t ;

# 1612 "/home/claude/cfront-3/src/template.cpp"
__2t = is_template__17templ_compilationFPCc ( templp , __1cl -> string__8classdef ) ;
if (! __2t )return (unsigned char )0 ;
{ { Plist __2formals ;

# 1614 "/home/claude/cfront-3/src/template.cpp"
__2formals = ( ((struct basic_template *)__2t )-> formals__14basic_template ) ;

# 1614 "/home/claude/cfront-3/src/template.cpp"
for(;__2formals ;__2formals = __2formals -> l__9name_list ) { 
# 1615 "/home/claude/cfront-3/src/template.cpp"
Pname __3n ;

# 1615 "/home/claude/cfront-3/src/template.cpp"
__3n = __2formals -> f__9name_list ;
if (__3n -> n_template_arg__4name == 1){ 
# 1617 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )1 ;
}
}

# 1619 "/home/claude/cfront-3/src/template.cpp"
}

# 1619 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1622 "/home/claude/cfront-3/src/template.cpp"
return (unsigned char )0 ;
}

# 958 "/home/claude/cfront-3/src/cfront.h"

# 1259 "/home/claude/cfront-3/src/cfront.h"

# 958 "/home/claude/cfront-3/src/cfront.h"

# 1626 "/home/claude/cfront-3/src/template.cpp"
void check_funct_formals__FP9name_listP4name (Plist __1formals , Pname __1namep )
# 1627 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1629 "/home/claude/cfront-3/src/template.cpp"
check_formals_for_dups__FP9name_list ( __1formals ) ;
{ { Plist __1fl ;

# 1630 "/home/claude/cfront-3/src/template.cpp"
__1fl = __1formals ;

# 1630 "/home/claude/cfront-3/src/template.cpp"
for(;__1fl ;__1fl = __1fl -> l__9name_list ) 
# 1631 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1632 "/home/claude/cfront-3/src/template.cpp"
Pname __2fn ;

# 1632 "/home/claude/cfront-3/src/template.cpp"
__2fn = __1fl -> f__9name_list ;
if (! ( (((unsigned char )(__2fn -> n_template_arg__4name == 1)))) ){ 
# 1634 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1634 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V95 ;

# 1634 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"FYZ%n must be aT", (const struct ea *)( ((& __0__V95 )-> __O1__2ea.p =
# 1634 "/home/claude/cfront-3/src/template.cpp"
((const void *)__2fn )), (& __0__V95 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 1634 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
continue ;
} }

# 1638 "/home/claude/cfront-3/src/template.cpp"
{ Pname __2a ;

# 1638 "/home/claude/cfront-3/src/template.cpp"
__2a = (((struct fct *)(((struct fct *)__1namep -> __O1__4expr.tp ))))-> argtype__3fct ;
for(;__2a ;__2a = __2a -> __O1__4name.n_list ) 
# 1640 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1641 "/home/claude/cfront-3/src/template.cpp"
Ptype __3t ;
int __3found ;

# 1641 "/home/claude/cfront-3/src/template.cpp"
__3t = __2a -> __O1__4expr.tp ;
__3found = 0 ;
while (((__3t -> base__4node == 125 )|| (__3t -> base__4node == 158 ))|| (__3t -> base__4node == 110 ))
# 1645 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1646 "/home/claude/cfront-3/src/template.cpp"
switch (__3t -> base__4node ){ 
# 1647 "/home/claude/cfront-3/src/template.cpp"
case
# 1647 "/home/claude/cfront-3/src/template.cpp"
125 :
# 1648 "/home/claude/cfront-3/src/template.cpp"
if ((((struct ptr *)(((struct ptr *)__3t ))))-> ptname__3ptr ){ 
# 1649 "/home/claude/cfront-3/src/template.cpp"
Pname __6n ;

# 1649 "/home/claude/cfront-3/src/template.cpp"
__6n = (((struct ptr *)(((struct ptr *)__3t ))))-> ptname__3ptr ;
if (strcmp ( __6n -> __O2__4expr.string , __2fn -> __O2__4expr.string ) == 0 )__3found = 1 ;
__3t = __6n -> __O1__4expr.tp ;
break ;
}
case 158 :__3t = (((struct ptr *)(((struct ptr *)__3t ))))-> typ__5pvtyp ;

# 1654 "/home/claude/cfront-3/src/template.cpp"
break ;
case 110 :__3t = (((struct vec *)(((struct vec *)__3t ))))-> typ__5pvtyp ;

# 1655 "/home/claude/cfront-3/src/template.cpp"
break ;
}
}

# 1659 "/home/claude/cfront-3/src/template.cpp"
if (__3found ){ __3found = 0 ;

# 1659 "/home/claude/cfront-3/src/template.cpp"
break ;

# 1659 "/home/claude/cfront-3/src/template.cpp"
}

# 1661 "/home/claude/cfront-3/src/template.cpp"
if (__3t -> base__4node == 119 ){ 
# 1662 "/home/claude/cfront-3/src/template.cpp"
if (contains_formal__FP4nameP8classdef ( __2fn , classtype__4typeFv ( __3t ) ) ){ 
# 1663 "/home/claude/cfront-3/src/template.cpp"
break ;
}
}
else if (__3t -> base__4node != 97 )continue ;

# 1668 "/home/claude/cfront-3/src/template.cpp"
{ Pname __3tn ;

# 1668 "/home/claude/cfront-3/src/template.cpp"
__3tn = ( (((struct basetype *)(((struct basetype *)__3t ))))-> b_name__8basetype ) ;
if (! ( (((unsigned char )(__3tn -> n_template_arg__4name == 1)))) ){ 
# 1670 "/home/claude/cfront-3/src/template.cpp"
__3t = __3tn -> __O1__4expr.tp ;
if (__3t -> base__4node == 119 ){ 
# 1672 "/home/claude/cfront-3/src/template.cpp"
if (contains_formal__FP4nameP8classdef ( __2fn , classtype__4typeFv ( __3t ) ) ){ 
# 1673 "/home/claude/cfront-3/src/template.cpp"
break ;
}
}
continue ;
}
if (strcmp ( __3tn -> __O2__4expr.string , __2fn -> __O2__4expr.string ) == 0 )
# 1679 "/home/claude/cfront-3/src/template.cpp"
break ;

# 1679 "/home/claude/cfront-3/src/template.cpp"
}
}
if (__2a == 0 )
# 1682 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1682 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V96 ;

# 1682 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V97 ;

# 1682 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"FYZ%n must be used in signature of %n", (const struct ea *)( ((& __0__V96 )-> __O1__2ea.p =
# 1682 "/home/claude/cfront-3/src/template.cpp"
((const void *)__2fn )), (& __0__V96 )) , (const struct ea *)( ((& __0__V97 )-> __O1__2ea.p = ((const void
# 1682 "/home/claude/cfront-3/src/template.cpp"
*)__1namep )), (& __0__V97 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1682 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1683 "/home/claude/cfront-3/src/template.cpp"
}

# 1683 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1695 "/home/claude/cfront-3/src/template.cpp"
int get_formals_count__14basic_templateFv (struct basic_template *__0this )
# 1696 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1697 "/home/claude/cfront-3/src/template.cpp"
int __1cnt ;

# 1697 "/home/claude/cfront-3/src/template.cpp"
__1cnt = 0 ;
{ { Plist __1f ;

# 1698 "/home/claude/cfront-3/src/template.cpp"
__1f = __0this -> formals__14basic_template ;

# 1698 "/home/claude/cfront-3/src/template.cpp"
for(;__1f ;( (__1f = __1f -> l__9name_list ), (++ __1cnt )) ) ;
return __1cnt ;

# 1699 "/home/claude/cfront-3/src/template.cpp"
}

# 1699 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1703 "/home/claude/cfront-3/src/template.cpp"
void check_formals__14basic_templateFP9name_list (register struct basic_template *__0this , Plist __1f2 )
# 1707 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1708 "/home/claude/cfront-3/src/template.cpp"
Plist __1f1 ;

# 1709 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X111 ;

# 1709 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X112 ;

# 1708 "/home/claude/cfront-3/src/template.cpp"
__1f1 = __0this -> formals__14basic_template ;
for(;__1f1 && __1f2 ;( (__1f1 = __1f1 -> l__9name_list ), (__1f2 = __1f2 -> l__9name_list )) ) 
# 1710 "/home/claude/cfront-3/src/template.cpp"
if (__1f1 -> f__9name_list -> base__4node != __1f2 ->
# 1710 "/home/claude/cfront-3/src/template.cpp"
f__9name_list -> base__4node )
# 1711 "/home/claude/cfront-3/src/template.cpp"
switch (__1f1 -> f__9name_list -> n_template_arg__4name ){ 
# 1711 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X107 ;

# 1711 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X108 ;

# 1711 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X109 ;

# 1712 "/home/claude/cfront-3/src/template.cpp"
case 1:
# 1713 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1713 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V98 ;

# 1713 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"Y formalZ mismatch, %n must be aT formalZ", (const struct ea *)( (__2__X107 = (const void
# 1713 "/home/claude/cfront-3/src/template.cpp"
*)__1f2 -> f__9name_list ), ( ((& __0__V98 )-> __O1__2ea.p = __2__X107 ), (& __0__V98 )) ) , (const struct ea *)ea0 ,
# 1713 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;

# 1716 "/home/claude/cfront-3/src/template.cpp"
case 2:
# 1717 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1717 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V99 ;

# 1717 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V100 ;

# 1717 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"formalZ mismatch, %n must be aZ ofT %t", (const struct ea *)( (__2__X108 = (const void
# 1717 "/home/claude/cfront-3/src/template.cpp"
*)__1f2 -> f__9name_list ), ( ((& __0__V99 )-> __O1__2ea.p = __2__X108 ), (& __0__V99 )) ) , (const struct ea *)__ct__2eaFPCv (
# 1717 "/home/claude/cfront-3/src/template.cpp"
& __0__V100 , (const void *)__1f2 -> f__9name_list -> __O1__4expr.tp ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 1717 "/home/claude/cfront-3/src/template.cpp"
;
break ;

# 1720 "/home/claude/cfront-3/src/template.cpp"
default :
# 1721 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1721 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V101 ;

# 1721 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V102 ;

# 1721 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"formalZ mismatch betweenC formal: %n andM formal: %n", (const struct ea *)( (__2__X109 = (const void
# 1721 "/home/claude/cfront-3/src/template.cpp"
*)__1f1 -> f__9name_list ), ( ((& __0__V101 )-> __O1__2ea.p = __2__X109 ), (& __0__V101 )) ) , (const struct ea *)__ct__2eaFPCv (
# 1721 "/home/claude/cfront-3/src/template.cpp"
& __0__V102 , (const void *)__1f2 -> f__9name_list ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 1721 "/home/claude/cfront-3/src/template.cpp"
} } } 
# 1722 "/home/claude/cfront-3/src/template.cpp"
}
else 
# 1724 "/home/claude/cfront-3/src/template.cpp"
if (__1f1 -> f__9name_list -> n_template_arg__4name == 2)
# 1725 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1725 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X110 ;

# 1727 "/home/claude/cfront-3/src/template.cpp"
if (check__4typeFP4typeUcT2 ( __1f1 -> f__9name_list -> __O1__4expr.tp , __1f2 -> f__9name_list -> __O1__4expr.tp , (unsigned char )0 , (unsigned char )0 )
# 1727 "/home/claude/cfront-3/src/template.cpp"
== 1 )
# 1728 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1728 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V103 ;

# 1728 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V104 ;

# 1728 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"T mismatch betweenM formal %n andC formal %n", (const struct ea *)( (__2__X110 = (const void
# 1728 "/home/claude/cfront-3/src/template.cpp"
*)__1f2 -> f__9name_list ), ( ((& __0__V103 )-> __O1__2ea.p = __2__X110 ), (& __0__V103 )) ) , (const struct ea *)__ct__2eaFPCv (
# 1728 "/home/claude/cfront-3/src/template.cpp"
& __0__V104 , (const void *)__1f1 -> f__9name_list ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
# 1728 "/home/claude/cfront-3/src/template.cpp"
} 
# 1729 "/home/claude/cfront-3/src/template.cpp"
}

# 1731 "/home/claude/cfront-3/src/template.cpp"
if (__1f1 )
# 1732 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1732 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V105 ;

# 1732 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"insufficient formalZs,CZ%n onwards are missing", (const struct ea *)( (__2__X111 = (const void
# 1732 "/home/claude/cfront-3/src/template.cpp"
*)__1f1 -> f__9name_list ), ( ((& __0__V105 )-> __O1__2ea.p = __2__X111 ), (& __0__V105 )) ) , (const struct ea *)ea0 ,
# 1732 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1734 "/home/claude/cfront-3/src/template.cpp"
if (__1f2 )
# 1735 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1735 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V106 ;

# 1735 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"excess formalZs,Z%n onwards not defined forC", (const struct ea *)( (__2__X112 = (const void
# 1735 "/home/claude/cfront-3/src/template.cpp"
*)__1f2 -> f__9name_list ), ( ((& __0__V106 )-> __O1__2ea.p = __2__X112 ), (& __0__V106 )) ) , (const struct ea *)ea0 ,
# 1735 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1737 "/home/claude/cfront-3/src/template.cpp"
}

# 1740 "/home/claude/cfront-3/src/template.cpp"
static Ptype real_type__FP4type (Ptype __1t )
# 1741 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1742 "/home/claude/cfront-3/src/template.cpp"
while (__1t && (__1t -> base__4node == 97 ))
# 1743 "/home/claude/cfront-3/src/template.cpp"
__1t = (((struct basetype *)(((struct basetype *)__1t ))))-> b_name__8basetype -> __O1__4expr.tp ;
return __1t ;
}

# 799 "/home/claude/cfront-3/src/cfront.h"
long long eval__4exprFv (struct expr *__0this );

# 794 "/home/claude/cfront-3/src/cfront.h"
void del__4exprFv (struct expr *__0this );

# 1750 "/home/claude/cfront-3/src/template.cpp"
static void vec_eval__FP4type (Ptype __1p )
# 1751 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1752 "/home/claude/cfront-3/src/template.cpp"
while (__1p && ((__1p -> base__4node == 110 )|| (__1p -> base__4node == 125 ))){ 
# 1753 "/home/claude/cfront-3/src/template.cpp"
if (__1p -> base__4node ==
# 1753 "/home/claude/cfront-3/src/template.cpp"
110 ){ 
# 1754 "/home/claude/cfront-3/src/template.cpp"
Pvec __3v ;

# 1754 "/home/claude/cfront-3/src/template.cpp"
__3v = (((struct vec *)(((struct vec *)__1p ))));
if (__3v -> dim__3vec && (! __3v -> size__3vec )){ 
# 1756 "/home/claude/cfront-3/src/template.cpp"
Neval = 0 ;
__3v -> size__3vec = (((int )eval__4exprFv ( __3v -> dim__3vec ) ));
if (Neval )
# 1759 "/home/claude/cfront-3/src/template.cpp"
error__FPCc ( (const char *)"cannot evaluate constantE") ;
if (__3v -> dim__3vec && (__3v -> dim__3vec -> permanent__4node == 0 ))del__4exprFv ( __3v -> dim__3vec ) ;
__3v -> dim__3vec = 0 ;
}
__1p = __3v -> typ__5pvtyp ;
}
else { 
# 1766 "/home/claude/cfront-3/src/template.cpp"
__1p = (((struct ptr *)(((struct ptr *)__1p ))))-> typ__5pvtyp ;
}
}
}

# 1772 "/home/claude/cfront-3/src/template.cpp"
int check_actual_args__5templFP4expr (register struct templ *__0this , Pexpr __1actual )
# 1773 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1775 "/home/claude/cfront-3/src/template.cpp"
Plist __1formal ;

# 1776 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X123 ;

# 1776 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X124 ;

# 1775 "/home/claude/cfront-3/src/template.cpp"
__1formal = __0this -> formals__14basic_template ;
for(;__1formal && __1actual ;( (__1formal = __1formal -> l__9name_list ), (__1actual = __1actual -> __O3__4expr.e2 )) ) 
# 1778 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1781 "/home/claude/cfront-3/src/template.cpp"
switch (__1formal -> f__9name_list -> n_template_arg__4name ){
# 1781 "/home/claude/cfront-3/src/template.cpp"

# 1782 "/home/claude/cfront-3/src/template.cpp"
case 1:
# 1783 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1792 "/home/claude/cfront-3/src/template.cpp"
vec_eval__FP4type ( real_type__FP4type ( __1actual -> __O2__4expr.e1 -> __O1__4expr.tp ) ) ;
{ Pname __4n ;

# 1793 "/home/claude/cfront-3/src/template.cpp"
__4n = (((struct name *)(((struct name *)__1actual -> __O2__4expr.e1 ))));
if (! ((__4n -> base__4node == 85 )&& (__4n -> n_template_arg__4name == 3)))
# 1796 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1796 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X121 ;

# 1797 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1797 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V113 ;

# 1797 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V114 ;

# 1797 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"Y %sA mismatch, theY formal:%n required aT actualZ", (const struct ea *)( (__2__X121 = (const void
# 1797 "/home/claude/cfront-3/src/template.cpp"
*)__0this -> namep__5templ -> __O2__4expr.string ), ( ((& __0__V113 )-> __O1__2ea.p = __2__X121 ), (& __0__V113 )) ) , (const struct
# 1797 "/home/claude/cfront-3/src/template.cpp"
ea *)__ct__2eaFPCv ( & __0__V114 , (const void *)__1formal -> f__9name_list ) , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 1797 "/home/claude/cfront-3/src/template.cpp"
;

# 1799 "/home/claude/cfront-3/src/template.cpp"
__4n = __ct__4nameFPCc ( (struct name *)0 , (const char *)"") ;
__4n -> __O1__4expr.tp = (struct type *)any_type ;
__1actual -> __O2__4expr.e1 = (struct expr *)__4n ;
} }

# 1804 "/home/claude/cfront-3/src/template.cpp"
{ Ptype __4tp ;

# 1804 "/home/claude/cfront-3/src/template.cpp"
__4tp = skiptypedefs__4typeFv ( __4n -> __O1__4expr.tp ) ;
if (__4tp -> base__4node == 119 ){ 
# 1806 "/home/claude/cfront-3/src/template.cpp"
Pclass __5cl ;

# 1806 "/home/claude/cfront-3/src/template.cpp"
__5cl = classtype__4typeFv ( __4tp ) ;
if (__5cl -> local_sig__4type )
# 1808 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1808 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V115 ;

# 1808 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V116 ;

# 1808 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"localC%t as ZT to YC%n", (const struct ea *)( ((&
# 1808 "/home/claude/cfront-3/src/template.cpp"
__0__V115 )-> __O1__2ea.p = ((const void *)__5cl )), (& __0__V115 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V116 , (const
# 1808 "/home/claude/cfront-3/src/template.cpp"
void *)__0this -> namep__5templ ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 1811 "/home/claude/cfront-3/src/template.cpp"
break ;

# 1811 "/home/claude/cfront-3/src/template.cpp"
}

# 1811 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1814 "/home/claude/cfront-3/src/template.cpp"
case 2:
# 1817 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1818 "/home/claude/cfront-3/src/template.cpp"
Ptype __4tp ;

# 1818 "/home/claude/cfront-3/src/template.cpp"
__4tp = skiptypedefs__4typeFv ( __1formal -> f__9name_list -> __O1__4expr.tp ) ;

# 1818 "/home/claude/cfront-3/src/template.cpp"
;
if ((__1actual -> __O2__4expr.e1 -> base__4node == 86 )&& (__4tp -> base__4node == 125 ))
# 1820 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1820 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X122 ;

# 1822 "/home/claude/cfront-3/src/template.cpp"
if (__4tp -> b_const__4type == 2 )
# 1823 "/home/claude/cfront-3/src/template.cpp"
__4tp -> b_const__4type = 0 ;
{ 
# 1824 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V117 ;

# 1824 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V118 ;

# 1824 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"cannot instantiate 0 to formalZ%n(%t)", (const struct ea *)( (__2__X122 = (const void
# 1824 "/home/claude/cfront-3/src/template.cpp"
*)__1formal -> f__9name_list ), ( ((& __0__V117 )-> __O1__2ea.p = __2__X122 ), (& __0__V117 )) ) , (const struct ea *)(
# 1824 "/home/claude/cfront-3/src/template.cpp"
((& __0__V118 )-> __O1__2ea.p = ((const void *)__4tp )), (& __0__V118 )) , (const struct ea *)ea0 , (const struct
# 1824 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
} }
break ;
}
default :
# 1829 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"badY formal") ;
}
}

# 1835 "/home/claude/cfront-3/src/template.cpp"
if (__1formal )
# 1836 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1836 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V119 ;

# 1836 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"too fewAs supplied forY %s", (const struct ea *)( (__2__X123 = (const void
# 1836 "/home/claude/cfront-3/src/template.cpp"
*)__0this -> namep__5templ -> __O2__4expr.string ), ( ((& __0__V119 )-> __O1__2ea.p = __2__X123 ), (& __0__V119 )) ) , (const struct
# 1836 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1838 "/home/claude/cfront-3/src/template.cpp"
if (__1actual && __1actual -> __O2__4expr.e1 )
# 1839 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1839 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V120 ;

# 1839 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"too manyAs supplied forY %s", (const struct ea *)( (__2__X124 = (const void
# 1839 "/home/claude/cfront-3/src/template.cpp"
*)__0this -> namep__5templ -> __O2__4expr.string ), ( ((& __0__V120 )-> __O1__2ea.p = __2__X124 ), (& __0__V120 )) ) , (const struct
# 1839 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 1842 "/home/claude/cfront-3/src/template.cpp"
return (((int )(~ (__1formal || __1actual ))));
}

# 50 "/home/claude/cfront-3/src/template.h"

# 1846 "/home/claude/cfront-3/src/template.cpp"
void append_friend_ref__17templ_compilationFP10templ_inst (struct templ_compilation *__0this , Ptempl_inst __1ref )
# 1847 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1850 "/home/claude/cfront-3/src/template.cpp"
struct cons *__1p ;

# 1851 "/home/claude/cfront-3/src/template.cpp"
struct cons *__0__X125 ;

# 1851 "/home/claude/cfront-3/src/template.cpp"
struct cons *__2__X126 ;

# 1850 "/home/claude/cfront-3/src/template.cpp"
__1p = ( (__0__X125 = 0 ), ( (__2__X126 = 0 ), ( ((__0__X125 || (__0__X125 = (struct cons *)__nw__FUl ( (unsigned long
# 1850 "/home/claude/cfront-3/src/template.cpp"
)(sizeof (struct cons))) ))?( (__0__X125 -> car__4cons = ((void *)__1ref )), (__0__X125 -> cdr__4cons = __2__X126 )) :0 ), __0__X125 ) ) )
# 1850 "/home/claude/cfront-3/src/template.cpp"
;
if (last_friend_cons__17templ_compilation )
# 1852 "/home/claude/cfront-3/src/template.cpp"
last_friend_cons__17templ_compilation -> cdr__4cons = __1p ;
else friend_templ_refs__17templ_compilation = __1p ;
last_friend_cons__17templ_compilation = __1p ;
}

# 50 "/home/claude/cfront-3/src/template.h"

# 1858 "/home/claude/cfront-3/src/template.cpp"
void append_ref__17templ_compilationFP10templ_inst (struct templ_compilation *__0this , Ptempl_inst __1ref )
# 1859 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1862 "/home/claude/cfront-3/src/template.cpp"
struct cons *__1p ;

# 1863 "/home/claude/cfront-3/src/template.cpp"
struct cons *__0__X127 ;

# 1863 "/home/claude/cfront-3/src/template.cpp"
struct cons *__2__X128 ;

# 1862 "/home/claude/cfront-3/src/template.cpp"
__1p = ( (__0__X127 = 0 ), ( (__2__X128 = 0 ), ( ((__0__X127 || (__0__X127 = (struct cons *)__nw__FUl ( (unsigned long
# 1862 "/home/claude/cfront-3/src/template.cpp"
)(sizeof (struct cons))) ))?( (__0__X127 -> car__4cons = ((void *)__1ref )), (__0__X127 -> cdr__4cons = __2__X128 )) :0 ), __0__X127 ) ) )
# 1862 "/home/claude/cfront-3/src/template.cpp"
;
if (last_cons__17templ_compilation )
# 1864 "/home/claude/cfront-3/src/template.cpp"
last_cons__17templ_compilation -> cdr__4cons = __1p ;
else templ_refs__17templ_compilation = __1p ;
last_cons__17templ_compilation = __1p ;

# 1868 "/home/claude/cfront-3/src/template.cpp"
}

# 1871 "/home/claude/cfront-3/src/template.cpp"
static bit ref_in_friend = 0 ;
static bit ignore_ref = 0 ;

# 1875 "/home/claude/cfront-3/src/template.cpp"
Ptempl_inst note_ref__10templ_instFv (register struct templ_inst *__0this )
# 1879 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1881 "/home/claude/cfront-3/src/template.cpp"
if (ref_in_friend && (ignore_ref == 0 )){ 
# 1882 "/home/claude/cfront-3/src/template.cpp"
__0this -> friend_refp__10templ_inst = 1;
append_friend_ref__17templ_compilationFP10templ_inst ( templp , __0this ) ;
}

# 1886 "/home/claude/cfront-3/src/template.cpp"
if (! __0this -> refp__10templ_inst ){ 
# 1887 "/home/claude/cfront-3/src/template.cpp"
__0this -> refp__10templ_inst = 1;
append_ref__17templ_compilationFP10templ_inst ( templp , __0this ) ;
}
return __0this ;
}

# 1894 "/home/claude/cfront-3/src/template.cpp"
int friend_template__17templ_compilationFP4expr (register struct templ_compilation *__0this , Pexpr __1actuals )
# 1899 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1901 "/home/claude/cfront-3/src/template.cpp"
Pexpr __1actual ;
Plist __1formal ;

# 1901 "/home/claude/cfront-3/src/template.cpp"
__1actual = __1actuals ;
__1formal = params__17templ_compilation ;
for(;__1formal && __1actual ;( (__1formal = __1formal -> l__9name_list ), (__1actual = __1actual -> __O3__4expr.e2 )) ) 
# 1905 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1906 "/home/claude/cfront-3/src/template.cpp"
if ((__1formal -> f__9name_list -> __O1__4expr.tp ==
# 1906 "/home/claude/cfront-3/src/template.cpp"
__1actual -> __O2__4expr.e1 -> __O1__4expr.tp )|| ((__1actual -> __O2__4expr.e1 -> __O1__4expr.tp && (__1actual -> __O2__4expr.e1 -> __O1__4expr.tp -> base__4node == 97 ))&& ((((struct basetype *)(((struct basetype *)__1actual ->
# 1906 "/home/claude/cfront-3/src/template.cpp"
__O2__4expr.e1 -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp == __1formal -> f__9name_list -> __O1__4expr.tp )))
# 1910 "/home/claude/cfront-3/src/template.cpp"
continue ;
else break ;
}

# 1914 "/home/claude/cfront-3/src/template.cpp"
if ((! __1formal )&& (! __1actual ))
# 1915 "/home/claude/cfront-3/src/template.cpp"
return (int )1;
return (int )0;
}

# 1919 "/home/claude/cfront-3/src/template.cpp"
extern int dont_instantiate ;

# 213 "/home/claude/cfront-3/src/template.h"
Ptempl_inst get_match__5templFP4exprP10templ_inst4bool (struct templ *__0this , Pexpr , Ptempl_inst , int );

# 403 "/home/claude/cfront-3/src/template.h"
struct templ_inst *__ct__10templ_instFP4exprP5templ (struct templ_inst *__0this , Pexpr __1act , Ptempl __1owner );

# 1922 "/home/claude/cfront-3/src/template.cpp"
Ptempl_inst get_inst__5templFP4exprP10templ_inst (register struct templ *__0this , Pexpr __1actuals , Ptempl_inst __1exclude )
# 1927 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1930 "/home/claude/cfront-3/src/template.cpp"
static int __1level = 0 ;
++ __1level ;

# 1933 "/home/claude/cfront-3/src/template.cpp"
{ Ptempl_inst __1inst ;
Ptempl_inst __1ti ;
int __1bl ;

# 1933 "/home/claude/cfront-3/src/template.cpp"
__1inst = get_match__5templFP4exprP10templ_inst4bool ( __0this , __1actuals , __1exclude , 0) ;

# 1936 "/home/claude/cfront-3/src/template.cpp"
if (__1inst )
# 1937 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1938 "/home/claude/cfront-3/src/template.cpp"
if ((! __1inst -> refp__10templ_inst )&& (! dont_instantiate ))
# 1939 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1940 "/home/claude/cfront-3/src/template.cpp"
if (in_progress__17templ_compilation || (__1level > 1 ))
# 1941 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1942 "/home/claude/cfront-3/src/template.cpp"
note_ref__10templ_instFv ( __1inst )
# 1942 "/home/claude/cfront-3/src/template.cpp"
;
}
else 
# 1945 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1946 "/home/claude/cfront-3/src/template.cpp"
__1bl = bl_level ;
bl_level = 0 ;
__1ti = instantiate__10templ_instF4bool ( __1inst , 0) ;
bl_level = __1bl ;
-- __1level ;
return __1ti ;
}
}
-- __1level ;
return __1inst ;
}

# 1958 "/home/claude/cfront-3/src/template.cpp"
__1inst = __ct__10templ_instFP4exprP5templ ( (struct templ_inst *)0 , __1actuals , __0this ) ;
if (dont_instantiate )
# 1960 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1961 "/home/claude/cfront-3/src/template.cpp"
-- __1level ;
return __1inst ;
}
ignore_ref = (friend_template__17templ_compilationFP4expr ( templp , __1actuals ) == 0 );

# 1966 "/home/claude/cfront-3/src/template.cpp"
if (ref_in_friend != 2 )
# 1967 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1968 "/home/claude/cfront-3/src/template.cpp"
if (in_progress__17templ_compilation || (__1level > 1 ))
# 1969 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1970 "/home/claude/cfront-3/src/template.cpp"
note_ref__10templ_instFv ( __1inst ) ;
}
else 
# 1973 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1974 "/home/claude/cfront-3/src/template.cpp"
__1bl = bl_level ;
bl_level = 0 ;
__1ti = instantiate__10templ_instF4bool ( __1inst , 0) ;
bl_level = __1bl ;
-- __1level ;
return __1ti ;
}
}
-- __1level ;
return __1inst ;

# 1983 "/home/claude/cfront-3/src/template.cpp"
}
}

# 405 "/home/claude/cfront-3/src/template.h"
int actuals_match__10templ_instFP4expr (struct templ_inst *__0this , Pexpr __1check_actuals );

# 1987 "/home/claude/cfront-3/src/template.cpp"
Ptempl_inst get_match__5templFP4exprP10templ_inst4bool (register struct templ *__0this , Pexpr __1actuals , Ptempl_inst __1exclude , 
# 1988 "/home/claude/cfront-3/src/template.cpp"
int __1match_instantiated_only )
# 1992 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1993 "/home/claude/cfront-3/src/template.cpp"
{ { Ptempl_inst __1p ;

# 1993 "/home/claude/cfront-3/src/template.cpp"
__1p = __0this -> insts__5templ ;

# 1993 "/home/claude/cfront-3/src/template.cpp"
for(;__1p ;__1p = __1p -> next__10templ_inst ) 
# 1994 "/home/claude/cfront-3/src/template.cpp"
{ 
# 1995 "/home/claude/cfront-3/src/template.cpp"
if (((__1p != __1exclude )&& actuals_match__10templ_instFP4expr ( __1p , __1actuals ) )&& (__1match_instantiated_only ?((((struct classdef *)(((struct classdef *)(((struct
# 1995 "/home/claude/cfront-3/src/template.cpp"
basetype *)(((struct basetype *)__1p -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> class_base__8classdef == 4):1))
# 2000 "/home/claude/cfront-3/src/template.cpp"
return (__1p -> forward__10templ_inst ?__1p -> forward__10templ_inst :__1p );
}
return (struct templ_inst *)0 ;

# 2002 "/home/claude/cfront-3/src/template.cpp"
}

# 2002 "/home/claude/cfront-3/src/template.cpp"
}
}

# 2005 "/home/claude/cfront-3/src/template.cpp"
int template_hier = 0 ;

# 384 "/home/claude/cfront-3/src/template.h"
int actuals_match__10funct_instFP4expr (struct funct_inst *__0this , Pexpr );

# 2008 "/home/claude/cfront-3/src/template.cpp"
Pfunct_inst get_match__17function_templateFP4exprP10funct_inst4bool (register struct function_template *__0this , Pexpr __1actuals , Pfunct_inst __1exclude , 
# 2009 "/home/claude/cfront-3/src/template.cpp"
int __1match_instantiate_only )
# 2010 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2011 "/home/claude/cfront-3/src/template.cpp"
{ { Pfunct_inst __1p ;

# 2011 "/home/claude/cfront-3/src/template.cpp"
__1p = __0this -> insts__17function_template ;

# 2011 "/home/claude/cfront-3/src/template.cpp"
for(;__1p ;__1p = __1p -> next__10funct_inst ) 
# 2012 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2013 "/home/claude/cfront-3/src/template.cpp"
if (((__1p != __1exclude )&& actuals_match__10funct_instFP4expr ( __1p , __1actuals ) )&& (__1match_instantiate_only ?((((struct templ_fct *)(((struct templ_fct *)__1p ->
# 2013 "/home/claude/cfront-3/src/template.cpp"
tname__10basic_inst -> __O1__4expr.tp ))))-> fct_base__3fct == 4):1))
# 2018 "/home/claude/cfront-3/src/template.cpp"
return __1p ;
}
return (struct funct_inst *)0 ;

# 2020 "/home/claude/cfront-3/src/template.cpp"
}

# 2020 "/home/claude/cfront-3/src/template.cpp"
}
}

# 22 "/home/claude/incl-linux32/string.h"
extern int strncmp (const char *, const char *, size_t );

# 2024 "/home/claude/cfront-3/src/template.cpp"
static void check_actuals__FP4exprP4name (Pexpr __1actuals , Pname __1fn )
# 2025 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2028 "/home/claude/cfront-3/src/template.cpp"
{ { Pexpr __1ae ;

# 2028 "/home/claude/cfront-3/src/template.cpp"
__1ae = __1actuals ;

# 2028 "/home/claude/cfront-3/src/template.cpp"
for(;__1ae ;__1ae = __1ae -> __O3__4expr.e2 ) { 
# 2029 "/home/claude/cfront-3/src/template.cpp"
Ptype __2t ;

# 2029 "/home/claude/cfront-3/src/template.cpp"
__2t = skiptypedefs__4typeFv ( __1ae -> __O2__4expr.e1 -> __O1__4expr.tp ) ;
if (__2t -> base__4node == 119 )__2t = (struct type *)classtype__4typeFv ( __2t ) ;
if (__2t -> base__4node != 6 )continue ;
if (strncmp ( (const char *)"__C", (((struct classdef *)(((struct classdef *)__2t ))))-> string__8classdef , (unsigned
# 2032 "/home/claude/cfront-3/src/template.cpp"
long )3 ) == 0 )
# 2033 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2033 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V129 ;

# 2033 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"YF%n instantiatedW unnamedC", (const struct ea *)( ((& __0__V129 )-> __O1__2ea.p =
# 2033 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1fn )), (& __0__V129 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2033 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
} if (__2t -> lex_level__4type && __2t -> local_sig__4type )
# 2035 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2035 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V130 ;

# 2035 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V131 ;

# 2035 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"YF%n instantiatedW localC %s", (const struct ea *)( ((&
# 2035 "/home/claude/cfront-3/src/template.cpp"
__0__V130 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V130 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V131 , (const
# 2035 "/home/claude/cfront-3/src/template.cpp"
void *)(((struct classdef *)(((struct classdef *)__2t ))))-> string__8classdef ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 2036 "/home/claude/cfront-3/src/template.cpp"
}

# 2036 "/home/claude/cfront-3/src/template.cpp"
}

# 2038 "/home/claude/cfront-3/src/template.cpp"
}

# 380 "/home/claude/cfront-3/src/template.h"
struct funct_inst *__ct__10funct_instFP4exprP17function_template (struct funct_inst *__0this , Pexpr __1act , Pfunt __1owner );

# 2041 "/home/claude/cfront-3/src/template.cpp"
Pfunct_inst get_inst__17function_templateFP4exprP10funct_inst (register struct function_template *__0this , Pexpr __1actuals , Pfunct_inst __1exclude )
# 2042 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2044 "/home/claude/cfront-3/src/template.cpp"
Pfunct_inst __1inst ;

# 2044 "/home/claude/cfront-3/src/template.cpp"
__1inst = get_match__17function_templateFP4exprP10funct_inst4bool ( __0this , __1actuals , __1exclude , 0) ;
if (__1inst == 0 ){ 
# 2046 "/home/claude/cfront-3/src/template.cpp"
check_actuals__FP4exprP4name ( __1actuals , __0this -> fn__17function_template ) ;
__1inst = __ct__10funct_instFP4exprP17function_template ( (struct funct_inst *)0 , __1actuals , __0this ) ;
}
return __1inst ;
}

# 228 "/home/claude/cfront-3/src/template.h"
Pname typename4__5templFP4expr (struct templ *__0this , Pexpr __1actuals );

# 2063 "/home/claude/cfront-3/src/template.cpp"
Pname parametrized_typename__FP4nameP4exprUc (Pname __1p , Pexpr __1actuals , bit __1in_friend )
# 2066 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2068 "/home/claude/cfront-3/src/template.cpp"
Ptempl __1t ;

# 2068 "/home/claude/cfront-3/src/template.cpp"
__1t = is_template__17templ_compilationFP4name ( templp , __1p ) ;

# 2073 "/home/claude/cfront-3/src/template.cpp"
if (current_template__17templ_compilationFP4nameP4expr ( templp , __1p , __1actuals ) && (__1in_friend == 0 ))
# 2074 "/home/claude/cfront-3/src/template.cpp"
return __1p ;

# 2076 "/home/claude/cfront-3/src/template.cpp"
if (__1t ){ 
# 2077 "/home/claude/cfront-3/src/template.cpp"
ref_in_friend = __1in_friend ;
{ Pname __2tname ;

# 2078 "/home/claude/cfront-3/src/template.cpp"
__2tname = typename4__5templFP4expr ( __1t , __1actuals ) ;
ref_in_friend = 0 ;
return (__2tname ?__2tname :__1p );

# 2080 "/home/claude/cfront-3/src/template.cpp"
}
}
{ 
# 2082 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V132 ;

# 2082 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n hasTAs but is not aZizedC", (const struct ea *)( ((& __0__V132 )-> __O1__2ea.p =
# 2082 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1p )), (& __0__V132 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 2082 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
return __1p ;
} }

# 2087 "/home/claude/cfront-3/src/template.cpp"
Pname typename4__5templFP4expr (register struct templ *__0this , Pexpr __1actuals )
# 2088 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2089 "/home/claude/cfront-3/src/template.cpp"
return (check_actual_args__5templFP4expr ( __0this , __1actuals ) ?get_inst__5templFP4exprP10templ_inst ( __0this , __1actuals , (struct templ_inst *)0 )
# 2089 "/home/claude/cfront-3/src/template.cpp"
-> tname__10basic_inst :(((struct name *)0 )));

# 2091 "/home/claude/cfront-3/src/template.cpp"
}

# 1747 "/home/claude/cfront-3/src/template.cpp"
static int expr_match__FP4exprT1 (Pexpr __0a1 , Pexpr __0a2 );

# 2097 "/home/claude/cfront-3/src/template.cpp"
int actuals_match__10templ_instFP4expr (register struct templ_inst *__0this , Pexpr __1check_actuals )
# 2098 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2099 "/home/claude/cfront-3/src/template.cpp"
Pexpr __1ae1 ;

# 2099 "/home/claude/cfront-3/src/template.cpp"
Pexpr __1ae2 ;
Plist __1formal ;

# 2100 "/home/claude/cfront-3/src/template.cpp"
__1formal = __0this -> def__10templ_inst -> formals__14basic_template ;

# 2104 "/home/claude/cfront-3/src/template.cpp"
for(( (__1ae1 = __0this -> actuals__10basic_inst ), (__1ae2 = __1check_actuals )) ;(__1formal && __1ae1 )&& __1ae2 ;( ( (__1ae1 = __1ae1 -> __O3__4expr.e2 ), (__1ae2 =
# 2104 "/home/claude/cfront-3/src/template.cpp"
__1ae2 -> __O3__4expr.e2 )) , (__1formal = __1formal -> l__9name_list )) ) 
# 2107 "/home/claude/cfront-3/src/template.cpp"
switch (__1formal -> f__9name_list -> n_template_arg__4name ){ 
# 2109 "/home/claude/cfront-3/src/template.cpp"
case 1:
# 2110 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2111 "/home/claude/cfront-3/src/template.cpp"
Ptype __3t1 ;
# 2111 "/home/claude/cfront-3/src/template.cpp"
Ptype __3t2 ;

# 2111 "/home/claude/cfront-3/src/template.cpp"
__3t1 = __1ae1 -> __O2__4expr.e1 -> __O1__4expr.tp ;

# 2111 "/home/claude/cfront-3/src/template.cpp"
__3t2 = __1ae2 -> __O2__4expr.e1 -> __O1__4expr.tp ;
if (check__4typeFP4typeUcT2 ( __3t1 , __3t2 , (unsigned char )255 , (unsigned char )0 ) == 1 )
# 2113 "/home/claude/cfront-3/src/template.cpp"
return (int )0;
# 2113 "/home/claude/cfront-3/src/template.cpp"

# 2114 "/home/claude/cfront-3/src/template.cpp"
break ;
}
case 2:
# 2117 "/home/claude/cfront-3/src/template.cpp"
if (! expr_match__FP4exprT1 ( __1ae1 -> __O2__4expr.e1 , __1ae2 -> __O2__4expr.e1 ) )return (int )0;
break ;

# 2120 "/home/claude/cfront-3/src/template.cpp"
default :
# 2121 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"bad template formal") ;
}
return (int )1;
}

# 1259 "/home/claude/cfront-3/src/cfront.h"

# 958 "/home/claude/cfront-3/src/cfront.h"

# 1260 "/home/claude/cfront-3/src/cfront.h"

# 42 "/home/claude/cfront-3/src/cfront.h"
extern int exact1__FP4nameP4type (Pname , Ptype );

# 2129 "/home/claude/cfront-3/src/template.cpp"
int actuals_match__10funct_instFP4expr (register struct funct_inst *__0this , Pexpr __1check_actuals )
# 2134 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2137 "/home/claude/cfront-3/src/template.cpp"
Pname __1n ;
Pexpr __1e ;

# 2137 "/home/claude/cfront-3/src/template.cpp"
__1n = (((struct templ_fct *)(((struct templ_fct *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> argtype__3fct ;
__1e = __1check_actuals ;

# 2140 "/home/claude/cfront-3/src/template.cpp"
for(;__1n && __1e ;( (__1n = __1n -> __O1__4name.n_list ), (__1e = __1e -> __O3__4expr.e2 )) ) 
# 2141 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2142 "/home/claude/cfront-3/src/template.cpp"
Ptype __2t1 ;
Ptype __2t2 ;

# 2142 "/home/claude/cfront-3/src/template.cpp"
__2t1 = __1n -> __O1__4expr.tp ;
__2t2 = __1e -> __O2__4expr.e1 -> __O1__4expr.tp ;

# 2147 "/home/claude/cfront-3/src/template.cpp"
while (__2t2 -> base__4node == 97 ){ 
# 2148 "/home/claude/cfront-3/src/template.cpp"
Pname __3nnn ;

# 2148 "/home/claude/cfront-3/src/template.cpp"
__3nnn = ( (((struct basetype *)(((struct basetype *)__2t2 ))))-> b_name__8basetype ) ;

# 2150 "/home/claude/cfront-3/src/template.cpp"
if (( (((unsigned char )(__3nnn -> n_template_arg__4name == 1)))) )
# 2151 "/home/claude/cfront-3/src/template.cpp"
__2t2 = ( (((struct basetype *)(((struct basetype *)__2t2 ))))-> b_name__8basetype -> __O1__4expr.tp )
# 2151 "/home/claude/cfront-3/src/template.cpp"
;
else 
# 2153 "/home/claude/cfront-3/src/template.cpp"
__2t2 = __3nnn -> __O1__4expr.tp ;
}

# 2157 "/home/claude/cfront-3/src/template.cpp"
{ int __2t_h ;

# 2157 "/home/claude/cfront-3/src/template.cpp"
__2t_h = template_hier ;
template_hier = 0 ;
if (exact1__FP4nameP4type ( __1n , __2t2 ) )
# 2160 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2161 "/home/claude/cfront-3/src/template.cpp"
template_hier = __2t_h ;
continue ;
}
template_hier = __2t_h ;

# 2168 "/home/claude/cfront-3/src/template.cpp"
if ((__2t2 -> base__4node == 119 )&& (__2t1 -> base__4node == 158 )){ 
# 2169 "/home/claude/cfront-3/src/template.cpp"
Ptype __3t ;

# 2169 "/home/claude/cfront-3/src/template.cpp"
__3t = skiptypedefs__4typeFv ( (((struct ptr *)(((struct ptr *)__2t1 ))))-> typ__5pvtyp ) ;
if (__3t -> base__4node == 119 )
# 2171 "/home/claude/cfront-3/src/template.cpp"
__2t2 = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )158 , __2t2 ) ;

# 2173 "/home/claude/cfront-3/src/template.cpp"
}
else 
# 2173 "/home/claude/cfront-3/src/template.cpp"
if (__2t2 -> base__4node == 110 ){ 
# 2174 "/home/claude/cfront-3/src/template.cpp"
__2t2 = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (((struct
# 2174 "/home/claude/cfront-3/src/template.cpp"
vec *)(((struct vec *)__2t2 ))))-> typ__5pvtyp ) ;
if (__2t1 -> base__4node == 158 )
# 2176 "/home/claude/cfront-3/src/template.cpp"
__2t2 = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )158 , __2t2 ) ;
}

# 2181 "/home/claude/cfront-3/src/template.cpp"
if (check__4typeFP4typeUcT2 ( __2t1 , __2t2 , (unsigned char )204 , (unsigned char )0 ) ){ 
# 2184 "/home/claude/cfront-3/src/template.cpp"
if ((! const_problem )||
# 2184 "/home/claude/cfront-3/src/template.cpp"
(((struct ptr *)(((struct ptr *)__2t2 ))))-> typ__5pvtyp -> b_const__4type )
# 2185 "/home/claude/cfront-3/src/template.cpp"
return (int )0;
else 
# 2187 "/home/claude/cfront-3/src/template.cpp"
continue ;
}

# 2188 "/home/claude/cfront-3/src/template.cpp"
}
}
return (int )1;
}

# 2193 "/home/claude/cfront-3/src/template.cpp"
extern char emode ;

# 2199 "/home/claude/cfront-3/src/template.cpp"
void stradd__FRPcPCci (char **__1target , const char *__1source , int __1numeric ){ 
# 2201 "/home/claude/cfront-3/src/template.cpp"
while (((*((*__1target ))))= ((*__1source ))){ 
# 2202 "/home/claude/cfront-3/src/template.cpp"
if ((((*((*__1target ))))== '-' )&&
# 2202 "/home/claude/cfront-3/src/template.cpp"
__1numeric )
# 2203 "/home/claude/cfront-3/src/template.cpp"
((*((*__1target ))))= 'n' ;
((*__1target ))++ ;

# 2204 "/home/claude/cfront-3/src/template.cpp"
__1source ++ ;
}
}

# 80 "/home/claude/incl-linux32/stdio.h"
extern int sprintf (char *, const char *,...);

# 24 "/home/claude/incl-linux32/string.h"
extern size_t strlen (const char *);

# 2209 "/home/claude/cfront-3/src/template.cpp"
void stradd__FRPcm (char **__1p , long long __1i ){ 
# 2210 "/home/claude/cfront-3/src/template.cpp"
char __1s [64];
char __1t [128];

# 2213 "/home/claude/cfront-3/src/template.cpp"
if (! emode ){ ((*(((*__1p ))++ )))= 'L' ;

# 2213 "/home/claude/cfront-3/src/template.cpp"
}
sprintf ( (char *)__1s , (const char *)"%lld", __1i ) ;
if (! emode ){ 
# 2216 "/home/claude/cfront-3/src/template.cpp"
long long __2len ;

# 2216 "/home/claude/cfront-3/src/template.cpp"
__2len = strlen ( (const char *)__1s ) ;
if (__2len >= 10 )
# 2218 "/home/claude/cfront-3/src/template.cpp"
sprintf ( (char *)__1t , (const char *)"%lld_%s", __2len , __1s )
# 2218 "/home/claude/cfront-3/src/template.cpp"
;
else sprintf ( (char *)__1t , (const char *)"%lld%s", __2len , __1s ) ;
# 2219 "/home/claude/cfront-3/src/template.cpp"

# 2220 "/home/claude/cfront-3/src/template.cpp"
stradd__FRPcPCci ( __1p , (const char *)__1t , 1 ) ;
}
else stradd__FRPcPCci ( __1p , (const char *)__1s , 0 ) ;
}

# 2226 "/home/claude/cfront-3/src/template.cpp"
void stradd__FRPcP4name (char **__1p , Pname __1n ){ 
# 2227 "/home/claude/cfront-3/src/template.cpp"
if (! emode ){ 
# 2228 "/home/claude/cfront-3/src/template.cpp"
char __2s [1024];

# 2230 "/home/claude/cfront-3/src/template.cpp"
sprintf ( (char *)__2s , (const char *)"%d", ((int )strlen ( __1n -> __O2__4expr.string )
# 2230 "/home/claude/cfront-3/src/template.cpp"
)) ;
stradd__FRPcPCci ( __1p , (const char *)__2s , 0 ) ;
}
stradd__FRPcPCci ( __1p , __1n -> __O2__4expr.string , 0 ) ;
}

# 2237 "/home/claude/cfront-3/src/template.cpp"
char *mangled_expr__FPcP4expr4bool (char *__1p , Pexpr __1e , int __1mangle_for_address );

# 13 "/home/claude/incl-linux32/string.h"
extern char *strcat (char *, const char *);

# 11 "/home/claude/incl-linux32/string.h"
extern char *strcpy (char *, const char *);

# 36 "/home/claude/incl-linux32/ctype.h"
extern int isalnum (int );

# 76 "/home/claude/cfront-3/src/cfront.h"

# 2237 "/home/claude/cfront-3/src/template.cpp"
char *mangled_expr__FPcP4expr4bool (char *__1p , Pexpr __1e , int __1mangle_for_address )
# 2241 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2242 "/home/claude/cfront-3/src/template.cpp"
static int __1mangle_address = 0 ;
if (__1e == 0 )return __1p ;

# 2247 "/home/claude/cfront-3/src/template.cpp"
switch (__1e -> base__4node ){ 
# 2247 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X135 ;

# 2248 "/home/claude/cfront-3/src/template.cpp"
case 112 :
# 2249 "/home/claude/cfront-3/src/template.cpp"
case 145 :
# 2251 "/home/claude/cfront-3/src/template.cpp"
++ __1mangle_address ;
if (emode )
# 2253 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2254 "/home/claude/cfront-3/src/template.cpp"
stradd__FRPcPCci ( (char **)(& __1p ), (const char *)"&", 0 )
# 2254 "/home/claude/cfront-3/src/template.cpp"
;
}
__1p = mangled_expr__FPcP4expr4bool ( __1p , __1e -> __O3__4expr.e2 , 0) ;
-- __1mangle_address ;
break ;

# 2260 "/home/claude/cfront-3/src/template.cpp"
case 85 :
# 2261 "/home/claude/cfront-3/src/template.cpp"
if (__1mangle_address || __1mangle_for_address )
# 2262 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2263 "/home/claude/cfront-3/src/template.cpp"
Pname __3n ;

# 2263 "/home/claude/cfront-3/src/template.cpp"
__3n = (((struct name *)(((struct name *)__1e ))));
if ((__3n -> n_scope__4name == 25 )|| (__3n -> n_scope__4name == 0 ))
# 2265 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2266 "/home/claude/cfront-3/src/template.cpp"
Ptype __4t ;

# 2266 "/home/claude/cfront-3/src/template.cpp"
__4t = __3n -> __O1__4expr.tp ;
if (((__3n -> n_stclass__4name == 31 )&& __3n -> __O4__4expr.n_table -> t_name__5table )|| ((__4t -> base__4node == 108 )&& (((struct fct *)(((struct fct *)__4t ))))-> f_static__3fct ))
# 2269 "/home/claude/cfront-3/src/template.cpp"
{
# 2269 "/home/claude/cfront-3/src/template.cpp"

# 2270 "/home/claude/cfront-3/src/template.cpp"
char __5xx [1024];
char __5s [1024];
const char *__5st ;

# 2272 "/home/claude/cfront-3/src/template.cpp"
__5st = ((__4t -> base__4node != 108 )?__3n -> __O4__4expr.n_table -> t_name__5table -> __O2__4expr.string :(((struct fct *)(((struct fct *)__4t ))))-> memof__3fct -> string__8classdef );

# 2275 "/home/claude/cfront-3/src/template.cpp"
if (emode )
# 2276 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2277 "/home/claude/cfront-3/src/template.cpp"
sprintf ( (char *)__5s , (const char *)"%s::%s", __5st , __3n ->
# 2277 "/home/claude/cfront-3/src/template.cpp"
__O2__4expr.string ) ;
}
else 
# 2280 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2281 "/home/claude/cfront-3/src/template.cpp"
sprintf ( (char *)__5xx , (const char *)"%s__%d%s", __3n -> __O2__4expr.string ,
# 2281 "/home/claude/cfront-3/src/template.cpp"
((int )strlen ( __5st ) ), __5st ) ;
sprintf ( (char *)__5s , (const char *)"%d", ((int )strlen ( (const char
# 2282 "/home/claude/cfront-3/src/template.cpp"
*)__5xx ) )) ;
strcat ( (char *)__5s , (const char *)__5xx ) ;
}

# 2286 "/home/claude/cfront-3/src/template.cpp"
stradd__FRPcPCci ( (char **)(& __1p ), (const char *)__5s , 0 ) ;
}
else stradd__FRPcP4name ( (char **)(& __1p ), ((struct name *)(((struct name *)__1e )))) ;
}
else stradd__FRPcP4name ( (char **)(& __1p ), ((struct name *)(((struct name *)__1e )))) ;
}
else 
# 2293 "/home/claude/cfront-3/src/template.cpp"
if ((((struct name *)(((struct name *)__1e ))))-> n_evaluated__4name )
# 2294 "/home/claude/cfront-3/src/template.cpp"
stradd__FRPcm ( (char **)(& __1p ), (((struct name *)(((struct name *)__1e ))))-> n_val__4name ) ;
# 2294 "/home/claude/cfront-3/src/template.cpp"
else 
# 2296 "/home/claude/cfront-3/src/template.cpp"
if ((((struct name *)(((struct name *)__1e ))))-> __O3__4expr.n_initializer ){ 
# 2298 "/home/claude/cfront-3/src/template.cpp"
Pexpr __3ee ;

# 2298 "/home/claude/cfront-3/src/template.cpp"
__3ee = (((struct name *)(((struct name *)__1e ))))-> __O3__4expr.n_initializer ;
if ((__3ee -> base__4node == 85 )&& (((struct name *)(((struct name *)__3ee ))))-> n_evaluated__4name )
# 2301 "/home/claude/cfront-3/src/template.cpp"
__1p = mangled_expr__FPcP4expr4bool ( __1p , __3ee , 0) ;
else __1p = mangled_expr__FPcP4expr4bool ( __1p , __3ee , 1) ;
}
else 
# 2305 "/home/claude/cfront-3/src/template.cpp"
if (((((struct name *)(((struct name *)__1e ))))-> __O1__4expr.tp -> base__4node == 110 )|| ((((struct name *)(((struct name *)__1e ))))-> __O1__4expr.tp -> base__4node == 108 ))
# 2306 "/home/claude/cfront-3/src/template.cpp"
stradd__FRPcP4name (
# 2306 "/home/claude/cfront-3/src/template.cpp"
(char **)(& __1p ), ((struct name *)(((struct name *)__1e )))) ;
else { 
# 2307 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V133 ;

# 2307 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"mangled_expr: couldn't mangle actualYE %n", (const struct ea *)( ((&
# 2307 "/home/claude/cfront-3/src/template.cpp"
__0__V133 )-> __O1__2ea.p = ((const void *)__1e )), (& __0__V133 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2307 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) ;
} break ;

# 2310 "/home/claude/cfront-3/src/template.cpp"
case 150 :
# 2311 "/home/claude/cfront-3/src/template.cpp"
stradd__FRPcm ( (char **)(& __1p ), (((struct ival *)(((struct ival *)__1e ))))-> __O2__4expr.i1 ) ;
break ;

# 2314 "/home/claude/cfront-3/src/template.cpp"
case 113 :
# 2315 "/home/claude/cfront-3/src/template.cpp"
case 191 :
# 2316 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2319 "/home/claude/cfront-3/src/template.cpp"
if (__1e -> __O2__4expr.e1 -> base__4node == 150 ){ 
# 2320 "/home/claude/cfront-3/src/template.cpp"
stradd__FRPcm ( (char **)(& __1p ), (((struct ival *)(((struct
# 2320 "/home/claude/cfront-3/src/template.cpp"
ival *)__1e -> __O2__4expr.e1 ))))-> __O2__4expr.i1 ) ;
break ;
}
else 
# 2324 "/home/claude/cfront-3/src/template.cpp"
if (__1e -> __O2__4expr.e1 -> base__4node == 86 ){ 
# 2325 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= '0' ;
break ;
}
else 
# 2329 "/home/claude/cfront-3/src/template.cpp"
if ((__1e -> __O2__4expr.e1 -> base__4node != 82 )&& (__1e -> __O2__4expr.e1 -> base__4node != 84 ))
# 2330 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2331 "/home/claude/cfront-3/src/template.cpp"
if (emode )
# 2332 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2333 "/home/claude/cfront-3/src/template.cpp"
Neval = 0 ;
# 2333 "/home/claude/cfront-3/src/template.cpp"

# 2334 "/home/claude/cfront-3/src/template.cpp"
{ long long __5e_eval ;

# 2334 "/home/claude/cfront-3/src/template.cpp"
__5e_eval = eval__4exprFv ( __1e ) ;
if (! Neval )
# 2336 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2337 "/home/claude/cfront-3/src/template.cpp"
stradd__FRPcm ( (char **)(& __1p ), __5e_eval ) ;
break ;
}

# 2339 "/home/claude/cfront-3/src/template.cpp"
}
}
error__FiPCc ( (int )'i' , (const char *)"mangled_expr: unexpected cast in YE") ;
break ;
}
else __1e = __1e -> __O2__4expr.e1 ;
}

# 2348 "/home/claude/cfront-3/src/template.cpp"
case 82 :
# 2349 "/home/claude/cfront-3/src/template.cpp"
case 84 :
# 2350 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2351 "/home/claude/cfront-3/src/template.cpp"
if (! emode )
# 2352 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2353 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= 'L' ;
}
{ size_t __3len ;
char __3s [64];

# 2355 "/home/claude/cfront-3/src/template.cpp"
__3len = strlen ( __1e -> __O2__4expr.string ) ;

# 2357 "/home/claude/cfront-3/src/template.cpp"
if (! emode )
# 2358 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2359 "/home/claude/cfront-3/src/template.cpp"
if (__3len >= 10 )
# 2360 "/home/claude/cfront-3/src/template.cpp"
sprintf ( (char *)__3s , (const char *)"%ld_%s",
# 2360 "/home/claude/cfront-3/src/template.cpp"
__3len , __1e -> __O2__4expr.string ) ;
else 
# 2362 "/home/claude/cfront-3/src/template.cpp"
sprintf ( (char *)__3s , (const char *)"%ld%s", __3len , __1e -> __O2__4expr.string )
# 2362 "/home/claude/cfront-3/src/template.cpp"
;
}
else 
# 2365 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2366 "/home/claude/cfront-3/src/template.cpp"
sprintf ( (char *)__3s , (const char *)"%s", __1e -> __O2__4expr.string )
# 2366 "/home/claude/cfront-3/src/template.cpp"
;
}
strcpy ( __1p , (const char *)__3s ) ;

# 2370 "/home/claude/cfront-3/src/template.cpp"
if (! emode )
# 2371 "/home/claude/cfront-3/src/template.cpp"
while ((*__1p ))
# 2372 "/home/claude/cfront-3/src/template.cpp"
if (! isalnum ( (int )((*__1p ))) )
# 2373 "/home/claude/cfront-3/src/template.cpp"
switch ((*__1p )){ 
# 2374 "/home/claude/cfront-3/src/template.cpp"
case '+' :
# 2375 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= 'p' ;
# 2375 "/home/claude/cfront-3/src/template.cpp"

# 2376 "/home/claude/cfront-3/src/template.cpp"
break ;
case '-' :
# 2378 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= 'n' ;
break ;
case '.' :
# 2381 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= 'D' ;
break ;
case 'e' :
# 2384 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= 'E' ;
break ;
default :
# 2387 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"bad character in constant") ;
break ;
}
else __1p ++ ;
break ;

# 2391 "/home/claude/cfront-3/src/template.cpp"
}
}
case 86 :
# 2394 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= '0' ;
break ;
case 124 :
# 2397 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2399 "/home/claude/cfront-3/src/template.cpp"
if (emode )
# 2400 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2401 "/home/claude/cfront-3/src/template.cpp"
stradd__FRPcPCci ( (char **)(& __1p ), (const char *)"&class::member",
# 2401 "/home/claude/cfront-3/src/template.cpp"
0 ) ;
break ;
}
{ Pexpr __3i1 ;
Pexpr __3i2 ;
Pexpr __3i3 ;

# 2404 "/home/claude/cfront-3/src/template.cpp"
__3i1 = __1e -> __O2__4expr.e1 -> __O2__4expr.e1 ;
__3i2 = __1e -> __O2__4expr.e1 -> __O3__4expr.e2 ;
__3i3 = (((__1e -> __O3__4expr.e2 -> base__4node == 113 )|| (__1e -> __O3__4expr.e2 -> base__4node == 191 ))?__1e -> __O3__4expr.e2 -> __O2__4expr.e1 :__1e -> __O3__4expr.e2 );

# 2408 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= 'L' ;

# 2408 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= 'M' ;
__1p = mangled_expr__FPcP4expr4bool ( __1p , __3i1 , 0) ;

# 2409 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= '_' ;
__1p = mangled_expr__FPcP4expr4bool ( __1p , __3i2 , 0) ;

# 2410 "/home/claude/cfront-3/src/template.cpp"
((*(__1p ++ )))= '_' ;
if (__3i3 -> base__4node != 85 )
# 2412 "/home/claude/cfront-3/src/template.cpp"
__1p = mangled_expr__FPcP4expr4bool ( __1p , __3i3 , 0) ;
else __1p = mangled_expr__FPcP4expr4bool ( __1p , __3i3 , 1) ;

# 2413 "/home/claude/cfront-3/src/template.cpp"
}
}
break ;
case 45 :
# 2417 "/home/claude/cfront-3/src/template.cpp"
case 44 :
# 2418 "/home/claude/cfront-3/src/template.cpp"
if (__1mangle_address ){ 
# 2419 "/home/claude/cfront-3/src/template.cpp"
while ((__1e -> base__4node == 45 )|| (__1e -> base__4node == 44 ))
# 2420 "/home/claude/cfront-3/src/template.cpp"
__1e = (((struct expr *)(((struct expr *)__1e ->
# 2420 "/home/claude/cfront-3/src/template.cpp"
__O4__4expr.mem ))));
__1p = mangled_expr__FPcP4expr4bool ( __1p , __1e -> __O3__4expr.e2 , 0) ;
break ;
}

# 2425 "/home/claude/cfront-3/src/template.cpp"
default :
# 2426 "/home/claude/cfront-3/src/template.cpp"
if (emode )
# 2427 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2428 "/home/claude/cfront-3/src/template.cpp"
Neval = 0 ;
{ long long __3e_eval ;

# 2429 "/home/claude/cfront-3/src/template.cpp"
__3e_eval = eval__4exprFv ( __1e ) ;
if (! Neval )
# 2431 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2432 "/home/claude/cfront-3/src/template.cpp"
stradd__FRPcm ( (char **)(& __1p ), __3e_eval ) ;
break ;
}

# 2434 "/home/claude/cfront-3/src/template.cpp"
}
}
{ 
# 2436 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V134 ;

# 2436 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"can't mangle %k", (const struct ea *)( (__2__X135 =
# 2436 "/home/claude/cfront-3/src/template.cpp"
__1e -> base__4node ), ( (( ((& __0__V134 )-> __O1__2ea.i = __2__X135 ), 0 ) ), (& __0__V134 )) ) ,
# 2436 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 2441 "/home/claude/cfront-3/src/template.cpp"
return __1p ;
}

# 338 "/home/claude/cfront-3/src/cfront.h"
void dcl_print__4typeFP4name (struct type *__0this , Pname );

# 31 "/home/claude/incl-linux32/string.h"
extern void *memset (void *, int , size_t );

# 2460 "/home/claude/cfront-3/src/template.cpp"
void print_pretty_name__10templ_instFv (register struct templ_inst *__0this )
# 2461 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2467 "/home/claude/cfront-3/src/template.cpp"
extern char emode ;

# 2470 "/home/claude/cfront-3/src/template.cpp"
Pname __1n ;

# 2471 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X138 ;

# 2470 "/home/claude/cfront-3/src/template.cpp"
__1n = (((struct templ_inst *)(((struct templ_inst *)__0this ))))-> def__10templ_inst -> namep__5templ ;
{ 
# 2471 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V136 ;

# 2471 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)" %s<", (const struct ea *)( (__2__X138 =
# 2471 "/home/claude/cfront-3/src/template.cpp"
(const void *)(__1n ?__1n -> __O2__4expr.string :(((const char *)"?")))), ( ((& __0__V136 )-> __O1__2ea.p =
# 2471 "/home/claude/cfront-3/src/template.cpp"
__2__X138 ), (& __0__V136 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 2471 "/home/claude/cfront-3/src/template.cpp"
;

# 2473 "/home/claude/cfront-3/src/template.cpp"
{ Plist __1formal ;

# 2473 "/home/claude/cfront-3/src/template.cpp"
__1formal = __0this -> inst_formals__10basic_inst ;
emode ++ ;

# 2476 "/home/claude/cfront-3/src/template.cpp"
{ { Pexpr __1ae1 ;

# 2476 "/home/claude/cfront-3/src/template.cpp"
__1ae1 = __0this -> actuals__10basic_inst ;

# 2476 "/home/claude/cfront-3/src/template.cpp"
for(;__1formal && __1ae1 ;( (__1ae1 = __1ae1 -> __O3__4expr.e2 ), (__1formal = __1formal -> l__9name_list )) ) 
# 2478 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2479 "/home/claude/cfront-3/src/template.cpp"
if (__1ae1 -> __O2__4expr.e1 -> base__4node ==
# 2479 "/home/claude/cfront-3/src/template.cpp"
0 )break ;
switch (__1formal -> f__9name_list -> n_template_arg__4name ){ 
# 2481 "/home/claude/cfront-3/src/template.cpp"
case 1:
# 2482 "/home/claude/cfront-3/src/template.cpp"
dcl_print__4typeFP4name ( __1ae1 -> __O2__4expr.e1 -> __O1__4expr.tp , (struct name *)0 ) ;
break ;
case 2:{ 
# 2485 "/home/claude/cfront-3/src/template.cpp"
char __4buff [1024];
memset ( (void *)__4buff , 0 , (unsigned long )1024 ) ;
mangled_expr__FPcP4expr4bool ( (char *)__4buff , __1ae1 -> __O2__4expr.e1 , 0) ;
{ 
# 2488 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V137 ;

# 2488 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"%s", (const struct ea *)( ((&
# 2488 "/home/claude/cfront-3/src/template.cpp"
__0__V137 )-> __O1__2ea.p = ((const void *)__4buff )), (& __0__V137 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 2488 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) ;
break ;
} }
default :error__FiPCc ( (int )'i' , (const char *)"unexpected formalZ") ;
}

# 2496 "/home/claude/cfront-3/src/template.cpp"
if (__1formal -> l__9name_list )error__FiPCc ( (int )'c' , (const char *)", ") ;
}
error__FiPCc ( (int )'c' , (const char *)">") ;
emode -- ;

# 2499 "/home/claude/cfront-3/src/template.cpp"
}

# 2499 "/home/claude/cfront-3/src/template.cpp"
}

# 2499 "/home/claude/cfront-3/src/template.cpp"
}
} }

# 2503 "/home/claude/cfront-3/src/template.cpp"
void print_pretty_name__10funct_instFv (register struct funct_inst *__0this )
# 2508 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2509 "/home/claude/cfront-3/src/template.cpp"
extern char emode ;
emode ++ ;

# 2512 "/home/claude/cfront-3/src/template.cpp"
{ Pname __1n ;

# 2513 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X140 ;

# 2512 "/home/claude/cfront-3/src/template.cpp"
__1n = (((struct funct_inst *)(((struct funct_inst *)__0this ))))-> def__10funct_inst -> fn__17function_template ;
{ 
# 2513 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V139 ;

# 2513 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)" %s(", (const struct ea *)( (__2__X140 =
# 2513 "/home/claude/cfront-3/src/template.cpp"
(const void *)(__1n ?__1n -> __O2__4expr.string :(((const char *)"?")))), ( ((& __0__V139 )-> __O1__2ea.p =
# 2513 "/home/claude/cfront-3/src/template.cpp"
__2__X140 ), (& __0__V139 )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 )
# 2513 "/home/claude/cfront-3/src/template.cpp"
;

# 2515 "/home/claude/cfront-3/src/template.cpp"
__1n = (((struct templ_fct *)(((struct templ_fct *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> argtype__3fct ;
for(;__1n ;__1n = __1n -> __O1__4name.n_list ) 
# 2517 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2518 "/home/claude/cfront-3/src/template.cpp"
Ptype __2t ;

# 2518 "/home/claude/cfront-3/src/template.cpp"
__2t = __1n -> __O1__4expr.tp ;
if ((! __2t )|| (__2t -> base__4node == 0 ))
# 2520 "/home/claude/cfront-3/src/template.cpp"
continue ;
dcl_print__4typeFP4name ( __2t , (struct name *)0 ) ;
if (__1n -> __O1__4name.n_list )
# 2523 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'c' , (const char *)", ") ;
}

# 2526 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'c' , (const char *)")") ;
emode -- ;
} 
# 2527 "/home/claude/cfront-3/src/template.cpp"
}
}

# 2531 "/home/claude/cfront-3/src/template.cpp"
static int check_expr__FUc (TOK __1b )
# 2532 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2533 "/home/claude/cfront-3/src/template.cpp"
switch (__1b ){ 
# 2534 "/home/claude/cfront-3/src/template.cpp"
default :
# 2535 "/home/claude/cfront-3/src/template.cpp"
return 0 ;
case 82 :case 150 :case 86 :
# 2537 "/home/claude/cfront-3/src/template.cpp"
case 84 :case 113 :case 191 :
# 2538 "/home/claude/cfront-3/src/template.cpp"
case 121 :case 30 :case 47 :
# 2539 "/home/claude/cfront-3/src/template.cpp"
case 107 :case 172 :case 46 :
# 2540 "/home/claude/cfront-3/src/template.cpp"
case 54 :case
# 2540 "/home/claude/cfront-3/src/template.cpp"
55 :case 50 :
# 2541 "/home/claude/cfront-3/src/template.cpp"
case 56 :case 57 :case 63 :
# 2542 "/home/claude/cfront-3/src/template.cpp"
case 58 :case 60 :case 61 :
# 2543 "/home/claude/cfront-3/src/template.cpp"
case 59 :case 52 :case 65 :
# 2544 "/home/claude/cfront-3/src/template.cpp"
case 64 :case 51 :case 53 :
# 2545 "/home/claude/cfront-3/src/template.cpp"
case
# 2545 "/home/claude/cfront-3/src/template.cpp"
62 :case 66 :case 67 :
# 2546 "/home/claude/cfront-3/src/template.cpp"
case 71 :case 147 :case 68 :
# 2547 "/home/claude/cfront-3/src/template.cpp"
return 1 ;
}
}

# 2552 "/home/claude/cfront-3/src/template.cpp"
int check_for_const__FP4exprT1 (Pexpr __1a1 , Pexpr __1a2 )
# 2553 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2558 "/home/claude/cfront-3/src/template.cpp"
Neval = 0 ;
if ((__1a1 -> base__4node != 85 )&& (__1a2 -> base__4node != 85 )){ 
# 2560 "/home/claude/cfront-3/src/template.cpp"
if ((__1a1 -> __O1__4expr.tp && __1a2 -> __O1__4expr.tp )&& check__4typeFP4typeUcT2 ( __1a1 ->
# 2560 "/home/claude/cfront-3/src/template.cpp"
__O1__4expr.tp , __1a2 -> __O1__4expr.tp , (unsigned char )255 , (unsigned char )0 ) )return (int )0;
while ((__1a1 -> base__4node == 113 )|| (__1a1 -> base__4node == 191 )){ 
# 2562 "/home/claude/cfront-3/src/template.cpp"
TOK __3b1 ;

# 2562 "/home/claude/cfront-3/src/template.cpp"
__3b1 = skiptypedefs__4typeFv ( __1a1 -> __O4__4expr.tp2 ) -> base__4node ;
if (((((((__3b1 == 5 )|| (__3b1 == 29 ))|| (__3b1 == 21 ))|| (__3b1 == 22 ))|| (__3b1 == 122 ))|| (__3b1 == 13 ))|| (__3b1 ==
# 2563 "/home/claude/cfront-3/src/template.cpp"
121 ))
# 2565 "/home/claude/cfront-3/src/template.cpp"
break ;
__1a1 = __1a1 -> __O2__4expr.e1 ;
}
while ((__1a2 -> base__4node == 113 )|| (__1a2 -> base__4node == 191 )){ 
# 2569 "/home/claude/cfront-3/src/template.cpp"
TOK __3b2 ;

# 2569 "/home/claude/cfront-3/src/template.cpp"
__3b2 = skiptypedefs__4typeFv ( __1a2 -> __O4__4expr.tp2 ) -> base__4node ;
if (((((((__3b2 == 5 )|| (__3b2 == 29 ))|| (__3b2 == 21 ))|| (__3b2 == 22 ))|| (__3b2 == 122 ))|| (__3b2 == 13 ))|| (__3b2 ==
# 2570 "/home/claude/cfront-3/src/template.cpp"
121 ))
# 2572 "/home/claude/cfront-3/src/template.cpp"
break ;
__1a2 = __1a2 -> __O2__4expr.e1 ;
}
{ long long __2a1_eval ;
long long __2a2_eval ;

# 2575 "/home/claude/cfront-3/src/template.cpp"
__2a1_eval = eval__4exprFv ( __1a1 ) ;
__2a2_eval = eval__4exprFv ( __1a2 ) ;
if (Neval )return (int )0;
return (__2a1_eval == __2a2_eval );

# 2578 "/home/claude/cfront-3/src/template.cpp"
}
}

# 2581 "/home/claude/cfront-3/src/template.cpp"
if ((__1a1 -> base__4node == 85 )&& check_expr__FUc ( __1a2 -> base__4node ) ){ 
# 2582 "/home/claude/cfront-3/src/template.cpp"
Pname __2n ;
long long __2a2_eval ;

# 2582 "/home/claude/cfront-3/src/template.cpp"
__2n = (((struct name *)(((struct name *)__1a1 ))));
__2a2_eval = eval__4exprFv ( __1a2 ) ;
return (((! Neval )&& __2n -> n_evaluated__4name )&& (__2n -> n_val__4name == __2a2_eval ));
}
else 
# 2587 "/home/claude/cfront-3/src/template.cpp"
if ((__1a2 -> base__4node == 85 )&& check_expr__FUc ( __1a1 -> base__4node ) ){ 
# 2588 "/home/claude/cfront-3/src/template.cpp"
Pname __2n ;
long long __2a1_eval ;

# 2588 "/home/claude/cfront-3/src/template.cpp"
__2n = (((struct name *)(((struct name *)__1a2 ))));
__2a1_eval = eval__4exprFv ( __1a1 ) ;
return (((! Neval )&& __2n -> n_evaluated__4name )&& (__2n -> n_val__4name == __2a1_eval ));
}

# 2593 "/home/claude/cfront-3/src/template.cpp"
if (((__1a1 -> base__4node == 85 )&& ((__1a2 -> base__4node == 112 )|| (__1a2 -> base__4node == 145 )))&& (__1a1 == __1a2 -> __O3__4expr.e2 ))
# 2595 "/home/claude/cfront-3/src/template.cpp"
return (int
# 2595 "/home/claude/cfront-3/src/template.cpp"
)1;

# 2597 "/home/claude/cfront-3/src/template.cpp"
if (((__1a2 -> base__4node == 85 )&& ((__1a1 -> base__4node == 112 )|| (__1a1 -> base__4node == 145 )))&& (__1a2 == __1a1 -> __O3__4expr.e2 ))
# 2599 "/home/claude/cfront-3/src/template.cpp"
return (int
# 2599 "/home/claude/cfront-3/src/template.cpp"
)1;

# 2601 "/home/claude/cfront-3/src/template.cpp"
if ((((__1a1 -> base__4node == 85 )&& (__1a2 -> base__4node == 124 ))&& __1a1 -> __O1__4expr.tp )&& __1a2 -> __O1__4expr.tp )
# 2602 "/home/claude/cfront-3/src/template.cpp"
return (int )((! check__4typeFP4typeUcT2 (
# 2602 "/home/claude/cfront-3/src/template.cpp"
__1a1 -> __O1__4expr.tp , __1a2 -> __O1__4expr.tp , (unsigned char )255 , (unsigned char )0 ) )?1:0);

# 2604 "/home/claude/cfront-3/src/template.cpp"
if ((((__1a2 -> base__4node == 85 )&& (__1a1 -> base__4node == 124 ))&& __1a1 -> __O1__4expr.tp )&& __1a2 -> __O1__4expr.tp )
# 2605 "/home/claude/cfront-3/src/template.cpp"
return (int )((! check__4typeFP4typeUcT2 (
# 2605 "/home/claude/cfront-3/src/template.cpp"
__1a2 -> __O1__4expr.tp , __1a1 -> __O1__4expr.tp , (unsigned char )255 , (unsigned char )0 ) )?1:0);

# 2607 "/home/claude/cfront-3/src/template.cpp"
return (int )0;
}

# 2612 "/home/claude/cfront-3/src/template.cpp"
static Pexpr real_expression__FP4expr (Pexpr __1e )
# 2613 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2614 "/home/claude/cfront-3/src/template.cpp"
while ((((__1e && (__1e -> base__4node == 85 ))&& ((((struct name *)(((struct name *)__1e ))))-> n_template_arg__4name == 2))&& (! (((struct
# 2614 "/home/claude/cfront-3/src/template.cpp"
name *)(((struct name *)__1e ))))-> n_evaluated__4name ))&& (((struct name *)(((struct name *)__1e ))))-> __O3__4expr.n_initializer )
# 2617 "/home/claude/cfront-3/src/template.cpp"
__1e = (((struct name *)(((struct name *)__1e ))))-> __O3__4expr.n_initializer ;
return __1e ;
}

# 2624 "/home/claude/cfront-3/src/template.cpp"
static int expr_match__FP4exprT1 (Pexpr __1a1 , Pexpr __1a2 )
# 2625 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2626 "/home/claude/cfront-3/src/template.cpp"
static int __1addr_of = 0 ;

# 2628 "/home/claude/cfront-3/src/template.cpp"
__1a1 = (__1addr_of ?__1a1 :real_expression__FP4expr ( __1a1 ) );
__1a2 = (__1addr_of ?__1a2 :real_expression__FP4expr ( __1a2 ) );

# 2631 "/home/claude/cfront-3/src/template.cpp"
if (__1a1 == __1a2 )return (int )1;

# 2636 "/home/claude/cfront-3/src/template.cpp"
if (__1a1 -> base__4node != __1a2 -> base__4node )return check_for_const__FP4exprT1 ( __1a1 , __1a2 ) ;
Neval = 0 ;
switch (__1a1 -> base__4node ){ 
# 2639 "/home/claude/cfront-3/src/template.cpp"
case 68 :
# 2641 "/home/claude/cfront-3/src/template.cpp"
return ((expr_match__FP4exprT1 ( __1a1 -> __O4__4expr.cond , __1a2 -> __O4__4expr.cond ) && expr_match__FP4exprT1 ( __1a1 -> __O2__4expr.e1 ,
# 2641 "/home/claude/cfront-3/src/template.cpp"
__1a2 -> __O2__4expr.e1 ) )&& expr_match__FP4exprT1 ( __1a1 -> __O3__4expr.e2 , __1a2 -> __O3__4expr.e2 ) );

# 2645 "/home/claude/cfront-3/src/template.cpp"
case 54 :case 55 :case 50 :case 51 :case 53 :
# 2646 "/home/claude/cfront-3/src/template.cpp"
case 64 :case 65 :case 66 :case 67 :
# 2647 "/home/claude/cfront-3/src/template.cpp"
case 56 :case 57 :
# 2648 "/home/claude/cfront-3/src/template.cpp"
case 62 :case 63 :case
# 2648 "/home/claude/cfront-3/src/template.cpp"
58 :case 59 :case 60 :case 61 :
# 2650 "/home/claude/cfront-3/src/template.cpp"
return (expr_match__FP4exprT1 ( __1a1 -> __O2__4expr.e1 , __1a2 -> __O2__4expr.e1 ) && expr_match__FP4exprT1 ( __1a1 -> __O3__4expr.e2 , __1a2 ->
# 2650 "/home/claude/cfront-3/src/template.cpp"
__O3__4expr.e2 ) );

# 2652 "/home/claude/cfront-3/src/template.cpp"
case 107 :case 172 :
# 2653 "/home/claude/cfront-3/src/template.cpp"
case 46 :case 47 :
# 2654 "/home/claude/cfront-3/src/template.cpp"
return expr_match__FP4exprT1 ( __1a1 -> __O3__4expr.e2 , __1a2 -> __O3__4expr.e2 ) ;
case 112 :
# 2656 "/home/claude/cfront-3/src/template.cpp"
case 145 :
# 2657 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2659 "/home/claude/cfront-3/src/template.cpp"
__1addr_of ++ ;
{ int __3result ;

# 2660 "/home/claude/cfront-3/src/template.cpp"
__3result = expr_match__FP4exprT1 ( __1a1 -> __O3__4expr.e2 , __1a2 -> __O3__4expr.e2 ) ;
__1addr_of -- ;
return __3result ;

# 2662 "/home/claude/cfront-3/src/template.cpp"
}
}
case 113 :
# 2665 "/home/claude/cfront-3/src/template.cpp"
case 191 :
# 2666 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2667 "/home/claude/cfront-3/src/template.cpp"
TOK __3b1 ;
TOK __3b2 ;

# 2667 "/home/claude/cfront-3/src/template.cpp"
__3b1 = __1a1 -> __O2__4expr.e1 -> base__4node ;
__3b2 = __1a2 -> __O2__4expr.e1 -> base__4node ;
if (((((__3b1 == 82 )|| (__3b1 == 150 ))|| (__3b1 == 84 ))|| (__3b1 == 86 ))&& ((((__3b2 == 82 )|| (__3b2 == 150 ))|| (__3b2 ==
# 2669 "/home/claude/cfront-3/src/template.cpp"
84 ))|| (__3b2 == 86 )))
# 2671 "/home/claude/cfront-3/src/template.cpp"
return check_for_const__FP4exprT1 ( __1a1 , __1a2 ) ;
else 
# 2673 "/home/claude/cfront-3/src/template.cpp"
return expr_match__FP4exprT1 ( __1a1 -> __O2__4expr.e1 , __1a2 -> __O2__4expr.e1 ) ;
}
case 85 :
# 2676 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2677 "/home/claude/cfront-3/src/template.cpp"
Pname __3n1 ;

# 2677 "/home/claude/cfront-3/src/template.cpp"
Pname __3n2 ;

# 2677 "/home/claude/cfront-3/src/template.cpp"
__3n1 = (((struct name *)(((struct name *)__1a1 ))));

# 2677 "/home/claude/cfront-3/src/template.cpp"
__3n2 = (((struct name *)(((struct name *)__1a2 ))));
if (! __1addr_of ){ 
# 2679 "/home/claude/cfront-3/src/template.cpp"
if ((__3n1 -> n_evaluated__4name && __3n2 -> n_evaluated__4name )&& (__3n1 -> n_val__4name == __3n2 -> n_val__4name ))
# 2680 "/home/claude/cfront-3/src/template.cpp"
return (int )1;
# 2680 "/home/claude/cfront-3/src/template.cpp"

# 2681 "/home/claude/cfront-3/src/template.cpp"
if (__3n1 -> __O3__4expr.n_initializer && (! __3n2 -> __O3__4expr.n_initializer ))
# 2682 "/home/claude/cfront-3/src/template.cpp"
return check_for_const__FP4exprT1 ( (struct expr *)__3n2 , __3n1 -> __O3__4expr.n_initializer ) ;
if (__3n2 -> __O3__4expr.n_initializer && (! __3n1 -> __O3__4expr.n_initializer ))
# 2684 "/home/claude/cfront-3/src/template.cpp"
return check_for_const__FP4exprT1 ( (struct expr *)__3n1 , __3n2 -> __O3__4expr.n_initializer ) ;
if (__3n1 -> __O3__4expr.n_initializer && __3n2 -> __O3__4expr.n_initializer )
# 2686 "/home/claude/cfront-3/src/template.cpp"
return expr_match__FP4exprT1 ( __3n1 -> __O3__4expr.n_initializer , __3n2 -> __O3__4expr.n_initializer ) ;
}
if (formals_in_progress__17templ_compilation )
# 2689 "/home/claude/cfront-3/src/template.cpp"
return (strcmp ( __3n1 -> __O2__4expr.string , __3n2 -> __O2__4expr.string ) == 0 );
return (int )0;
}
case 45 :
# 2693 "/home/claude/cfront-3/src/template.cpp"
return expr_match__FP4exprT1 ( __1a1 -> __O2__4expr.e1 , __1a2 -> __O2__4expr.e1 ) ;
case 44 :
# 2695 "/home/claude/cfront-3/src/template.cpp"
return expr_match__FP4exprT1 ( __1a1 -> __O2__4expr.e1 , __1a2 -> __O2__4expr.e1 ) ;
case 150 :
# 2698 "/home/claude/cfront-3/src/template.cpp"
return (__1a1 -> __O2__4expr.i1 == __1a2 -> __O2__4expr.i1 );
case 82 :
# 2700 "/home/claude/cfront-3/src/template.cpp"
case 84 :
# 2701 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2702 "/home/claude/cfront-3/src/template.cpp"
int __3i ;
__3i = (eval__4exprFv ( __1a1 ) == eval__4exprFv ( __1a2 ) );
if (Neval )
# 2705 "/home/claude/cfront-3/src/template.cpp"
error__FPCc ( (const char *)"cannot evaluate constantE") ;
return __3i ;
}
case 83 :
# 2709 "/home/claude/cfront-3/src/template.cpp"
case 81 :
# 2710 "/home/claude/cfront-3/src/template.cpp"
return (strcmp ( __1a1 -> __O2__4expr.string , __1a2 -> __O2__4expr.string ) == 0 );
case 86 :
# 2712 "/home/claude/cfront-3/src/template.cpp"
return (int )1;
case 30 :
# 2714 "/home/claude/cfront-3/src/template.cpp"
{ long long __3l1 ;

# 2714 "/home/claude/cfront-3/src/template.cpp"
long long __3l2 ;

# 2714 "/home/claude/cfront-3/src/template.cpp"
__3l1 = eval__4exprFv ( __1a1 ) ;

# 2714 "/home/claude/cfront-3/src/template.cpp"
__3l2 = eval__4exprFv ( __1a2 ) ;
if (Neval )return (int )0;
return (__3l1 == __3l2 );
}
case 124 :
# 2719 "/home/claude/cfront-3/src/template.cpp"
if ((__1a1 -> __O1__4expr.tp && __1a2 -> __O1__4expr.tp )&& (! check__4typeFP4typeUcT2 ( __1a1 -> __O1__4expr.tp , __1a2 -> __O1__4expr.tp , (unsigned char
# 2719 "/home/claude/cfront-3/src/template.cpp"
)255 , (unsigned char )0 ) ))
# 2720 "/home/claude/cfront-3/src/template.cpp"
return (int )1;
else 
# 2722 "/home/claude/cfront-3/src/template.cpp"
return (int )0;
}
return (int )0;
}

# 321 "/home/claude/cfront-3/src/cfront.h"
char *signature__4typeFPci (struct type *__0this , char *, int );

# 2728 "/home/claude/cfront-3/src/template.cpp"
static char *non_type_argument_signature__FP4exprPc (Pexpr __1e , char *__1p )
# 2729 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2730 "/home/claude/cfront-3/src/template.cpp"
__1p = signature__4typeFPci ( __1e -> __O1__4expr.tp , __1p , 0 ) ;
return mangled_expr__FPcP4expr4bool ( __1p , __1e , 0) ;
}

# 2736 "/home/claude/cfront-3/src/template.cpp"
static int check_nest__FPci (char *__1s , int __1max );

# 2736 "/home/claude/cfront-3/src/template.cpp"
static int check_nest__FPci (char *__1s , int __1max )
# 2737 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2738 "/home/claude/cfront-3/src/template.cpp"
char *__1t ;
char *__1t2 ;
int __1len ;
int __1n ;
int __1maxn ;

# 2744 "/home/claude/cfront-3/src/template.cpp"
__1t = __1s ;
__1maxn = 0 ;
while (((*__1t ))&& (__1t < (__1s + __1max ))){ 
# 2747 "/home/claude/cfront-3/src/template.cpp"
if (((((((__1t [0 ])== '_' )&& ((__1t [1 ])== '_' ))&& ((__1t [2 ])== 'p' ))&& ((__1t [3 ])== 't' ))&&
# 2747 "/home/claude/cfront-3/src/template.cpp"
((__1t [4 ])== '_' ))&& ((__1t [5 ])== '_' ))
# 2748 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2749 "/home/claude/cfront-3/src/template.cpp"
__1t2 = (__1t + 6 );
__1len = 0 ;
while ((((*__1t2 ))>= '0' )&& (((*__1t2 ))<= '9' )){ 
# 2752 "/home/claude/cfront-3/src/template.cpp"
__1len = (((__1len * 10 )+ ((*__1t2 )))- '0' );
__1t2 ++ ;
}
__1n = (1 + check_nest__FPci ( __1t2 , __1len ) );
if (__1n > __1maxn )
# 2757 "/home/claude/cfront-3/src/template.cpp"
__1maxn = __1n ;
}
__1t ++ ;
}
return __1maxn ;
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 2769 "/home/claude/cfront-3/src/template.cpp"
char *mangled_name__10templ_instFPc (register struct templ_inst *__0this , char *__1ip )
# 2770 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2773 "/home/claude/cfront-3/src/template.cpp"
char *__1start ;

# 2773 "/home/claude/cfront-3/src/template.cpp"
__1start = __1ip ;
__1ip = __1start ;
strcpy ( __1ip , __0this -> def__10templ_inst -> namep__5templ ?__0this -> def__10templ_inst -> namep__5templ -> __O2__4expr.string :(((const char *)"?")))
# 2775 "/home/claude/cfront-3/src/template.cpp"
;
__1ip = (__1start + strlen ( (const char *)__1start ) );
stradd__FRPcPCci ( (char **)(& __1ip ), (const char *)"__pt__", 0 ) ;

# 2779 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2780 "/home/claude/cfront-3/src/template.cpp"
char __2a [1024];

# 2780 "/home/claude/cfront-3/src/template.cpp"
char *__2p ;
Plist __2formal ;

# 2780 "/home/claude/cfront-3/src/template.cpp"
__2p = __2a ;
__2formal = __0this -> inst_formals__10basic_inst ;

# 2783 "/home/claude/cfront-3/src/template.cpp"
{ { Pexpr __2ae1 ;

# 2783 "/home/claude/cfront-3/src/template.cpp"
__2ae1 = __0this -> actuals__10basic_inst ;

# 2783 "/home/claude/cfront-3/src/template.cpp"
for(;__2ae1 ;( (__2ae1 = __2ae1 -> __O3__4expr.e2 ), (__2formal = __2formal -> l__9name_list )) ) 
# 2784 "/home/claude/cfront-3/src/template.cpp"
switch (__2formal -> f__9name_list -> n_template_arg__4name ){ 
# 2784 "/home/claude/cfront-3/src/template.cpp"
unsigned long
# 2784 "/home/claude/cfront-3/src/template.cpp"
__2__X142 ;

# 2785 "/home/claude/cfront-3/src/template.cpp"
case 2:
# 2786 "/home/claude/cfront-3/src/template.cpp"
((*(__2p ++ )))= 'X' ;

# 2788 "/home/claude/cfront-3/src/template.cpp"
__2p = non_type_argument_signature__FP4exprPc ( (struct expr *)__2formal -> f__9name_list , __2p ) ;
break ;

# 2791 "/home/claude/cfront-3/src/template.cpp"
case 1:
# 2792 "/home/claude/cfront-3/src/template.cpp"
__2p = signature__4typeFPci ( __2ae1 -> __O2__4expr.e1 -> __O1__4expr.tp , __2p , 1 ) ;
break ;

# 2795 "/home/claude/cfront-3/src/template.cpp"
default :
# 2796 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2796 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V141 ;

# 2796 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"bad template formal:%d", (const struct ea *)( (__2__X142 = __2formal -> f__9name_list ->
# 2796 "/home/claude/cfront-3/src/template.cpp"
base__4node ), ( (( ((& __0__V141 )-> __O1__2ea.i = __2__X142 ), 0 ) ), (& __0__V141 )) ) , (const
# 2796 "/home/claude/cfront-3/src/template.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
} }

# 2800 "/home/claude/cfront-3/src/template.cpp"
((*__2p ))= 0 ;
sprintf ( __1ip , (const char *)"%d_", (((int )strlen ( (const char *)__2a )
# 2801 "/home/claude/cfront-3/src/template.cpp"
))+ 1 ) ;
__1ip = (__1start + strlen ( (const char *)__1start ) );
strcpy ( __1ip , (const char *)__2a ) ;

# 2803 "/home/claude/cfront-3/src/template.cpp"
}

# 2803 "/home/claude/cfront-3/src/template.cpp"
}
}

# 2807 "/home/claude/cfront-3/src/template.cpp"
if (check_nest__FPci ( __1start , 9999 ) > 16){ 
# 2808 "/home/claude/cfront-3/src/template.cpp"
if (! error_count )
# 2809 "/home/claude/cfront-3/src/template.cpp"
error__FPCc ( (const char *)"infinite template instantiation sequence")
# 2809 "/home/claude/cfront-3/src/template.cpp"
;
else 
# 2811 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"infinite template instantiation sequence") ;
}

# 2814 "/home/claude/cfront-3/src/template.cpp"
return __1start ;
}

# 2818 "/home/claude/cfront-3/src/template.cpp"
char *mangled_name__10funct_instFPc (register struct funct_inst *__0this , char *__1ip )
# 2819 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2822 "/home/claude/cfront-3/src/template.cpp"
char *__1start ;

# 2822 "/home/claude/cfront-3/src/template.cpp"
__1start = __1ip ;
__1ip = __1start ;
strcpy ( __1ip , __0this -> def__10funct_inst -> fn__17function_template ?__0this -> def__10funct_inst -> fn__17function_template -> __O2__4expr.string :(((const char *)"?")))
# 2824 "/home/claude/cfront-3/src/template.cpp"
;
__1ip = (__1start + strlen ( (const char *)__1start ) );
stradd__FRPcPCci ( (char **)(& __1ip ), (const char *)"__pt__", 0 ) ;

# 2828 "/home/claude/cfront-3/src/template.cpp"
{ char __1buf [1024];

# 2828 "/home/claude/cfront-3/src/template.cpp"
char *__1p ;

# 2830 "/home/claude/cfront-3/src/template.cpp"
Ptype __1t ;

# 2828 "/home/claude/cfront-3/src/template.cpp"
__1p = __1buf ;

# 2831 "/home/claude/cfront-3/src/template.cpp"
if ((((struct templ_fct *)(((struct templ_fct *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))&& (((struct templ_fct *)(((struct templ_fct *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> argtype__3fct ){ 
# 2832 "/home/claude/cfront-3/src/template.cpp"
Pname __2n ;

# 2832 "/home/claude/cfront-3/src/template.cpp"
__2n = (((struct templ_fct *)(((struct templ_fct *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> argtype__3fct ;
for(;__2n ;__2n = __2n -> __O1__4name.n_list ) 
# 2834 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2835 "/home/claude/cfront-3/src/template.cpp"
__1t = __2n -> __O1__4expr.tp ;
if (__1t -> base__4node == 138 )__1t = (struct type *)int_type ;
__1p = signature__4typeFPci ( __1t , __1p , 0 ) ;
((*(__1p ++ )))= '_' ;
}
}
else 
# 2840 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2841 "/home/claude/cfront-3/src/template.cpp"
{ { Pexpr __2ae ;

# 2841 "/home/claude/cfront-3/src/template.cpp"
__2ae = __0this -> actuals__10basic_inst ;

# 2841 "/home/claude/cfront-3/src/template.cpp"
for(;__2ae ;__2ae = __2ae -> __O3__4expr.e2 ) 
# 2842 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2843 "/home/claude/cfront-3/src/template.cpp"
__1t = __2ae -> __O2__4expr.e1 -> __O1__4expr.tp ;
if (__1t -> base__4node == 138 )__1t = (struct type *)int_type ;
__1p = signature__4typeFPci ( __1t , __1p , 0 ) ;
((*(__1p ++ )))= '_' ;
}

# 2847 "/home/claude/cfront-3/src/template.cpp"
}

# 2847 "/home/claude/cfront-3/src/template.cpp"
}
}

# 2850 "/home/claude/cfront-3/src/template.cpp"
if (__0this -> actuals__10basic_inst )-- __1p ;
((*__1p ))= 0 ;
sprintf ( __1ip , (const char *)"F%d_", ((int )(strlen ( (const char *)__1buf )
# 2852 "/home/claude/cfront-3/src/template.cpp"
+ 1 ))) ;
__1ip = (__1start + strlen ( (const char *)__1start ) );
strcpy ( __1ip , (const char *)__1buf ) ;

# 2857 "/home/claude/cfront-3/src/template.cpp"
return __1start ;

# 2857 "/home/claude/cfront-3/src/template.cpp"
}
}

# 2860 "/home/claude/cfront-3/src/template.cpp"
static const char leader [2]= "\t";

# 298 "/home/claude/cfront-3/src/template.h"

# 96 "/home/claude/incl-linux32/stdio.h"
extern int fputc (int , void *);

# 2871 "/home/claude/cfront-3/src/template.cpp"
extern void print_loc__Fv (void );

# 330 "/home/claude/cfront-3/src/template.h"
void print_pretty_name__10basic_instFv (struct basic_inst *__0this );

# 2863 "/home/claude/cfront-3/src/template.cpp"
void print_error_loc__10basic_instFi (register struct basic_inst *__0this , int __1newline )
# 2864 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2869 "/home/claude/cfront-3/src/template.cpp"
if (! head__10basic_inst )return ;

# 2871 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2872 "/home/claude/cfront-3/src/template.cpp"
struct state __1current_state ;

# 2873 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X147 ;

# 2872 "/home/claude/cfront-3/src/template.cpp"
( (0 ), (& __1current_state )) ;

# 2877 "/home/claude/cfront-3/src/template.cpp"
if (__1newline )fputc ( (int )'\n' , out_file ) ;
save__5stateFv ( & __1current_state ) ;
print_loc__Fv ( ) ;
{ 
# 2880 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V143 ;

# 2880 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"%serror detected during the instantiation of", (const struct ea *)( (__2__X147 =
# 2880 "/home/claude/cfront-3/src/template.cpp"
(const void *)leader ), ( ((& __0__V143 )-> __O1__2ea.p = __2__X147 ), (& __0__V143 )) ) , (const struct
# 2880 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
((*(((void (*)(struct basic_inst *__0this ))(__0this -> __vptr__10basic_inst [2]).f))))( ((struct basic_inst *)((((char *)__0this ))+ (__0this -> __vptr__10basic_inst [2]).d))) ;
fputc ( (int )'\n' , out_file ) ;

# 2884 "/home/claude/cfront-3/src/template.cpp"
if (! head__10basic_inst -> next_active__10basic_inst ){ 
# 2884 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X148 ;

# 2886 "/home/claude/cfront-3/src/template.cpp"
restore__5stateFv ( & __0this -> context__10basic_inst ) ;
print_loc__Fv ( ) ;
{ 
# 2888 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V144 ;

# 2888 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"%sis the site of the instantiation\n", (const struct ea *)( (__2__X148 =
# 2888 "/home/claude/cfront-3/src/template.cpp"
(const void *)leader ), ( ((& __0__V144 )-> __O1__2ea.p = __2__X148 ), (& __0__V144 )) ) , (const struct
# 2888 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
else { 
# 2890 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X149 ;

# 2892 "/home/claude/cfront-3/src/template.cpp"
print_loc__Fv ( ) ;
{ 
# 2893 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V145 ;

# 2893 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"%sthe instantiation path was:\n", (const struct ea *)( (__2__X149 =
# 2893 "/home/claude/cfront-3/src/template.cpp"
(const void *)leader ), ( ((& __0__V145 )-> __O1__2ea.p = __2__X149 ), (& __0__V145 )) ) , (const struct
# 2893 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
{ { Pbase_inst __2p ;

# 2894 "/home/claude/cfront-3/src/template.cpp"
__2p = head__10basic_inst ;

# 2894 "/home/claude/cfront-3/src/template.cpp"
for(;__2p ;__2p = __2p -> next_active__10basic_inst ) { 
# 2894 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X150 ;

# 2895 "/home/claude/cfront-3/src/template.cpp"
restore__5stateFv ( & __2p -> context__10basic_inst ) ;
print_loc__Fv ( ) ;
{ 
# 2897 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V146 ;

# 2897 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'c' , (const char *)"%s template:", (const struct ea *)( (__2__X150 =
# 2897 "/home/claude/cfront-3/src/template.cpp"
(const void *)leader ), ( ((& __0__V146 )-> __O1__2ea.p = __2__X150 ), (& __0__V146 )) ) , (const struct
# 2897 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
((*(((void (*)(struct basic_inst *__0this ))(__2p -> __vptr__10basic_inst [2]).f))))( ((struct basic_inst *)((((char *)__2p ))+ (__2p -> __vptr__10basic_inst [2]).d))) ;
fputc ( (int )'\n' , out_file ) ;
} }

# 2900 "/home/claude/cfront-3/src/template.cpp"
}

# 2900 "/home/claude/cfront-3/src/template.cpp"
}
} }
restore__5stateFv ( & __1current_state ) ;
} 
# 2902 "/home/claude/cfront-3/src/template.cpp"
}
}

# 331 "/home/claude/cfront-3/src/template.h"
char *mangled_name__10basic_instFPc (struct basic_inst *__0this , char *);

# 19 "/home/claude/incl-linux32/string.h"
extern char *strdup (const char *);

# 2906 "/home/claude/cfront-3/src/template.cpp"
char *instantiation_string__10basic_instFv (struct basic_inst *__0this )
# 2907 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2908 "/home/claude/cfront-3/src/template.cpp"
char __1inst_name [1024];
{ { int __1i ;

# 2909 "/home/claude/cfront-3/src/template.cpp"
__1i = 0 ;

# 2909 "/home/claude/cfront-3/src/template.cpp"
for(;__1i < 1024;++ __1i ) (__1inst_name [__1i ])= 0 ;
((*(((char *(*)(struct basic_inst *__0this , char *))(__0this -> __vptr__10basic_inst [3]).f))))( ((struct basic_inst *)((((char *)__0this ))+ (__0this -> __vptr__10basic_inst [3]).d)), (char *)__1inst_name ) ;
# 2910 "/home/claude/cfront-3/src/template.cpp"

# 2911 "/home/claude/cfront-3/src/template.cpp"
return strdup ( (const char *)__1inst_name ) ;

# 2911 "/home/claude/cfront-3/src/template.cpp"
}

# 2911 "/home/claude/cfront-3/src/template.cpp"
}
}

# 2915 "/home/claude/cfront-3/src/template.cpp"
void modify_inst_names__8classdefFPCc (register struct classdef *__0this , const char *__1s )
# 2916 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2920 "/home/claude/cfront-3/src/template.cpp"
const char *__1old ;

# 2920 "/home/claude/cfront-3/src/template.cpp"
__1old = __0this -> string__8classdef ;
__0this -> string__8classdef = __1s ;
if (__0this -> lex_level__4type && ((__0this -> in_class__4type == 0 )|| (__0this -> lex_level__4type != __0this -> in_class__4type -> lex_level__4type ))){ 
# 2923 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' ,
# 2923 "/home/claude/cfront-3/src/template.cpp"
(const char *)"localCY") ;

# 2928 "/home/claude/cfront-3/src/template.cpp"
}
else __0this -> c_strlen__8classdef = strlen ( __1s ) ;

# 2932 "/home/claude/cfront-3/src/template.cpp"
{ { Pname __1p ;

# 2932 "/home/claude/cfront-3/src/template.cpp"
__1p = __0this -> mem_list__8classdef ;

# 2932 "/home/claude/cfront-3/src/template.cpp"
for(;__1p ;__1p = __1p -> __O1__4name.n_list ) 
# 2933 "/home/claude/cfront-3/src/template.cpp"
if ((__1p -> __O1__4expr.tp && (__1p -> __O1__4expr.tp -> base__4node == 108 ))&& (! strcmp ( __1old , __1p ->
# 2933 "/home/claude/cfront-3/src/template.cpp"
__O2__4expr.string ) ))
# 2935 "/home/claude/cfront-3/src/template.cpp"
__1p -> __O2__4expr.string = __1s ;

# 2935 "/home/claude/cfront-3/src/template.cpp"
}

# 2935 "/home/claude/cfront-3/src/template.cpp"
}
}

# 2939 "/home/claude/cfront-3/src/template.cpp"
Ptype non_template_arg_type__FP8basetype (Pbase __1t );

# 2939 "/home/claude/cfront-3/src/template.cpp"
Ptype non_template_arg_type__FP8basetype (Pbase __1t )
# 2940 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2943 "/home/claude/cfront-3/src/template.cpp"
if ((__1t -> base__4node == 97 )&& (__1t -> b_name__8basetype -> n_template_arg__4name == 1))
# 2945 "/home/claude/cfront-3/src/template.cpp"
return non_template_arg_type__FP8basetype ( ((struct basetype *)(((struct basetype *)__1t -> b_name__8basetype ->
# 2945 "/home/claude/cfront-3/src/template.cpp"
__O1__4expr.tp )))) ;
else return (struct type *)__1t ;
}

# 2951 "/home/claude/cfront-3/src/template.cpp"
void non_template_arg_non_type__FP4name (Pname __1n ){ 
# 2952 "/home/claude/cfront-3/src/template.cpp"
Pexpr __1i ;

# 2952 "/home/claude/cfront-3/src/template.cpp"
__1i = __1n -> __O3__4expr.n_initializer ;
while ((__1i && (__1i -> base__4node == 85 ))&& ((((struct name *)(((struct name *)__1i ))))-> n_template_arg__4name == 2))
# 2956 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2957 "/home/claude/cfront-3/src/template.cpp"
if ((((struct name *)(((struct name *)__1i ))))->
# 2957 "/home/claude/cfront-3/src/template.cpp"
__O3__4expr.n_initializer ){ 
# 2958 "/home/claude/cfront-3/src/template.cpp"
__1n -> __O3__4expr.n_initializer = (((struct name *)(((struct name *)__1i ))))-> __O3__4expr.n_initializer ;
__1i = __1n -> __O3__4expr.n_initializer ;
continue ;
}
if ((((struct name *)(((struct name *)__1i ))))-> n_evaluated__4name ){ 
# 2963 "/home/claude/cfront-3/src/template.cpp"
__1n -> n_evaluated__4name = 1 ;
__1n -> n_val__4name = (((struct name *)(((struct name *)__1i ))))-> n_val__4name ;
return ;
}
}
return ;
}

# 2974 "/home/claude/cfront-3/src/template.cpp"
void forward_template_arg_types__FP9name_listP4expr (Plist __1formal , Pexpr __1actuals )
# 2975 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2976 "/home/claude/cfront-3/src/template.cpp"
{ { Pexpr __1actual ;

# 2976 "/home/claude/cfront-3/src/template.cpp"
__1actual = __1actuals ;

# 2976 "/home/claude/cfront-3/src/template.cpp"
for(;__1formal && __1actual ;( (__1formal = __1formal -> l__9name_list ), (__1actual = __1actual -> __O3__4expr.e2 )) ) 
# 2978 "/home/claude/cfront-3/src/template.cpp"
switch (__1formal -> f__9name_list -> n_template_arg__4name ){ 
# 2979 "/home/claude/cfront-3/src/template.cpp"
case
# 2979 "/home/claude/cfront-3/src/template.cpp"
1:
# 2980 "/home/claude/cfront-3/src/template.cpp"
__1actual -> __O2__4expr.e1 -> __O1__4expr.tp = non_template_arg_type__FP8basetype ( ((struct basetype *)(((struct basetype *)__1actual -> __O2__4expr.e1 -> __O1__4expr.tp )))) ;
break ;
case 2:
# 2983 "/home/claude/cfront-3/src/template.cpp"
break ;
default :
# 2985 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"bad template formal") ;
}

# 2986 "/home/claude/cfront-3/src/template.cpp"
}

# 2986 "/home/claude/cfront-3/src/template.cpp"
}
}

# 76 "/home/claude/cfront-3/src/cfront.h"

# 2990 "/home/claude/cfront-3/src/template.cpp"
static int suitable_const_expr__FP4name (Pname __1n )
# 2995 "/home/claude/cfront-3/src/template.cpp"
{ 
# 2998 "/home/claude/cfront-3/src/template.cpp"
if (__1n -> n_evaluated__4name )return 1 ;
{ Pexpr __1ee ;

# 2999 "/home/claude/cfront-3/src/template.cpp"
__1ee = __1n -> __O3__4expr.n_initializer ;
if (__1ee == 0 )return 0 ;

# 3003 "/home/claude/cfront-3/src/template.cpp"
switch (__1ee -> base__4node ){ 
# 3004 "/home/claude/cfront-3/src/template.cpp"
case 113 :
# 3005 "/home/claude/cfront-3/src/template.cpp"
case 191 :
# 3006 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3007 "/home/claude/cfront-3/src/template.cpp"
Pexpr __3e ;

# 3007 "/home/claude/cfront-3/src/template.cpp"
__3e = __1ee -> __O2__4expr.e1 ;

# 3009 "/home/claude/cfront-3/src/template.cpp"
if ((((__3e -> base__4node == 150 )|| (__3e -> base__4node == 82 ))|| (__3e -> base__4node == 84 ))|| (__3e -> base__4node == 86 ))
# 3011 "/home/claude/cfront-3/src/template.cpp"
return 1 ;
# 3011 "/home/claude/cfront-3/src/template.cpp"

# 3012 "/home/claude/cfront-3/src/template.cpp"
return -2;
}

# 3016 "/home/claude/cfront-3/src/template.cpp"
case 86 :
# 3017 "/home/claude/cfront-3/src/template.cpp"
return 1 ;
case 112 :
# 3019 "/home/claude/cfront-3/src/template.cpp"
case 145 :
# 3020 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3021 "/home/claude/cfront-3/src/template.cpp"
bit __3mbr ;
Pexpr __3e ;

# 3021 "/home/claude/cfront-3/src/template.cpp"
__3mbr = 0 ;
__3e = __1ee -> __O3__4expr.e2 ;
while ((__3e -> base__4node == 45 )|| (__3e -> base__4node == 44 ))
# 3024 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3024 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X154 ;

# 3024 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X155 ;

# 3025 "/home/claude/cfront-3/src/template.cpp"
if ((__3e -> __O2__4expr.e1 -> base__4node == 109 )|| (__3e -> __O2__4expr.e1 -> base__4node == 146 ))
# 3027 "/home/claude/cfront-3/src/template.cpp"
return 0 ;

# 3029 "/home/claude/cfront-3/src/template.cpp"
if ((__3e -> __O4__4expr.mem -> base__4node != 45 )&& (__3e -> __O4__4expr.mem -> base__4node != 44 ))
# 3030 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3030 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V151 ;

# 3030 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V152 ;

# 3030 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V153 ;

# 3030 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'s' , (const char *)"address of boundM (&%n%k%n) as actualYA", (const struct ea *)( (__2__X154 =
# 3030 "/home/claude/cfront-3/src/template.cpp"
(const void *)__3e -> __O2__4expr.e1 ), ( ((& __0__V151 )-> __O1__2ea.p = __2__X154 ), (& __0__V151 )) ) , (const
# 3030 "/home/claude/cfront-3/src/template.cpp"
struct ea *)( (__2__X155 = __3e -> base__4node ), ( (( ((& __0__V152 )-> __O1__2ea.i = __2__X155 ), 0 ) ), (&
# 3030 "/home/claude/cfront-3/src/template.cpp"
__0__V152 )) ) , (const struct ea *)__ct__2eaFPCv ( & __0__V153 , (const void *)__3e -> __O4__4expr.mem ) , (const
# 3030 "/home/claude/cfront-3/src/template.cpp"
struct ea *)ea0 ) ;
} __3e = (((struct expr *)(((struct expr *)__3e -> __O4__4expr.mem ))));
++ __3mbr ;
}
{ Pname __3an ;

# 3034 "/home/claude/cfront-3/src/template.cpp"
__3an = (((struct name *)(((struct name *)__3e ))));

# 3036 "/home/claude/cfront-3/src/template.cpp"
if (__3an -> base__4node != 85 )return 0 ;
if (__3an -> n_sto__4name == 31 )return -3;
if ((__3an -> n_stclass__4name == 31 )|| __3mbr )return 1 ;
if (((__3an -> __O1__4expr.tp -> base__4node == 108 )&& (((struct fct *)(((struct fct *)__3an -> __O1__4expr.tp ))))-> f_static__3fct )&& (((struct fct *)(((struct fct *)__3an -> __O1__4expr.tp ))))->
# 3039 "/home/claude/cfront-3/src/template.cpp"
memof__3fct )
# 3042 "/home/claude/cfront-3/src/template.cpp"
return 1 ;
return 0 ;

# 3043 "/home/claude/cfront-3/src/template.cpp"
}
}
case 85 :
# 3046 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3047 "/home/claude/cfront-3/src/template.cpp"
Pname __3an ;

# 3047 "/home/claude/cfront-3/src/template.cpp"
__3an = (((struct name *)(((struct name *)__1n -> __O3__4expr.n_initializer ))));
if ((__3an -> n_stclass__4name == 31 )&& ((__3an -> __O1__4expr.tp -> base__4node == 110 )|| (__3an -> __O1__4expr.tp -> b_const__4type && __3an -> n_evaluated__4name )))
# 3052 "/home/claude/cfront-3/src/template.cpp"
return 1 ;
# 3052 "/home/claude/cfront-3/src/template.cpp"

# 3053 "/home/claude/cfront-3/src/template.cpp"
return 0 ;
}
case 124 :
# 3057 "/home/claude/cfront-3/src/template.cpp"
if (__1ee -> __O3__4expr.e2 )return 1 ;
return 0 ;
case 81 :
# 3060 "/home/claude/cfront-3/src/template.cpp"
return -1;
default :
# 3062 "/home/claude/cfront-3/src/template.cpp"
return 0 ;
}

# 3063 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3067 "/home/claude/cfront-3/src/template.cpp"
static int const_formal_hack__FP4name (Pname __1n )
# 3068 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3075 "/home/claude/cfront-3/src/template.cpp"
if (! const_problem )return 0 ;
switch (__1n -> __O1__4expr.tp -> base__4node ){ 
# 3079 "/home/claude/cfront-3/src/template.cpp"
case 158 :case 110 :
# 3080 "/home/claude/cfront-3/src/template.cpp"
case 15 :case 11 :case 181 :
# 3081 "/home/claude/cfront-3/src/template.cpp"
return 0 ;

# 3083 "/home/claude/cfront-3/src/template.cpp"
case 138 :case 5 :case 29 :case 21 :
# 3084 "/home/claude/cfront-3/src/template.cpp"
case 22 :case 122 :case 114 :case 121 :case 119 :
# 3085 "/home/claude/cfront-3/src/template.cpp"
case 97 :case 141 :
# 3086 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3087 "/home/claude/cfront-3/src/template.cpp"
Pbase __3b ;

# 3087 "/home/claude/cfront-3/src/template.cpp"
__3b = (((struct basetype *)(((struct basetype *)__1n -> __O1__4expr.tp ))));
if (__3b -> b_const__4type == 2 )return 1 ;
return 0 ;
}
case 125 :
# 3092 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3093 "/home/claude/cfront-3/src/template.cpp"
Pptr __3b ;

# 3093 "/home/claude/cfront-3/src/template.cpp"
__3b = (((struct ptr *)(((struct ptr *)__1n -> __O1__4expr.tp ))));
if (__3b -> b_const__4type == 2 )return 1 ;
return 0 ;
}
}
return 0 ;
}

# 3102 "/home/claude/cfront-3/src/template.cpp"
char *make_formal_name__FPCcT1 (const char *__1fns , const char *__1ins )
# 3103 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3104 "/home/claude/cfront-3/src/template.cpp"
char __1s [1024];
char __1t [6];
strcpy ( (char *)__1s , __1fns ) ;
sprintf ( (char *)__1t , (const char *)"__%d", ((int )strlen ( __1ins ) ))
# 3107 "/home/claude/cfront-3/src/template.cpp"
;
strcat ( (char *)__1s , (const char *)__1t ) ;
strcat ( (char *)__1s , __1ins ) ;

# 3111 "/home/claude/cfront-3/src/template.cpp"
{ char *__1result ;

# 3111 "/home/claude/cfront-3/src/template.cpp"
__1result = (((char *)__nw__FUl ( (size_t)((sizeof (char ))* (strlen ( (const char *)__1s ) + 1 )))
# 3111 "/home/claude/cfront-3/src/template.cpp"
));
strcpy ( __1result , (const char *)__1s ) ;
return __1result ;

# 3113 "/home/claude/cfront-3/src/template.cpp"
}
}

# 798 "/home/claude/cfront-3/src/cfront.h"
Pexpr typ__4exprFP5table (struct expr *__0this , Ptable );

# 343 "/home/claude/cfront-3/src/cfront.h"
Pptr is_ptr_or_ref__4typeFv (struct type *__0this );

# 3117 "/home/claude/cfront-3/src/template.cpp"
void bind_formals__10templ_instFv (register struct templ_inst *__0this )
# 3120 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3121 "/home/claude/cfront-3/src/template.cpp"
Pexpr __1actual ;
Plist __1formal ;

# 3124 "/home/claude/cfront-3/src/template.cpp"
for(( (__1formal = __0this -> inst_formals__10basic_inst ), (__1actual = __0this -> actuals__10basic_inst )) ;__1formal && __1actual ;( (__1formal = __1formal -> l__9name_list ), (__1actual = __1actual ->
# 3124 "/home/claude/cfront-3/src/template.cpp"
__O3__4expr.e2 )) ) 
# 3127 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3128 "/home/claude/cfront-3/src/template.cpp"
switch (__1formal -> f__9name_list -> n_template_arg__4name ){ 
# 3129 "/home/claude/cfront-3/src/template.cpp"
case 1:
# 3130 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3131 "/home/claude/cfront-3/src/template.cpp"
Ptype __4t ;

# 3131 "/home/claude/cfront-3/src/template.cpp"
__4t = non_template_arg_type__FP8basetype ( ((struct basetype *)(((struct basetype *)__1actual -> __O2__4expr.e1 -> __O1__4expr.tp )))) ;
if (__4t -> base__4node == 110 ){ 
# 3134 "/home/claude/cfront-3/src/template.cpp"
Pvec __5v ;

# 3135 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X162 ;

# 3134 "/home/claude/cfront-3/src/template.cpp"
__5v = (((struct vec *)(((struct vec *)__4t ))));
if ((__5v -> dim__3vec == 0 )&& (__5v -> size__3vec == 0 ))
# 3136 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3136 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V156 ;

# 3136 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"actual vectorZ%t must include dimension", (const struct ea *)( (__2__X162 = (const void
# 3136 "/home/claude/cfront-3/src/template.cpp"
*)__1actual -> __O2__4expr.e1 -> __O1__4expr.tp ), ( ((& __0__V156 )-> __O1__2ea.p = __2__X162 ), (& __0__V156 )) ) , (const struct
# 3136 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
__1formal -> f__9name_list -> __O1__4expr.tp = __4t ;
__1formal -> f__9name_list -> __O1__4expr.tp -> permanent__4node = 1 ;
break ;
}

# 3143 "/home/claude/cfront-3/src/template.cpp"
case 2:
# 3144 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3145 "/home/claude/cfront-3/src/template.cpp"
__1actual -> __O2__4expr.e1 = typ__4exprFP5table ( __1actual -> __O2__4expr.e1 , gtbl ) ;

# 3148 "/home/claude/cfront-3/src/template.cpp"
{ Ptype __4t ;

# 3148 "/home/claude/cfront-3/src/template.cpp"
__4t = __1actual -> __O2__4expr.e1 -> __O1__4expr.tp ;
if ((__4t -> base__4node == 110 )&& (__1formal -> f__9name_list -> __O1__4expr.tp -> base__4node == 125 ))
# 3151 "/home/claude/cfront-3/src/template.cpp"
__4t = (struct type *)__ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned
# 3151 "/home/claude/cfront-3/src/template.cpp"
char )125 , (((struct vec *)(((struct vec *)__4t ))))-> typ__5pvtyp ) ;

# 3153 "/home/claude/cfront-3/src/template.cpp"
if (check__4typeFP4typeUcT2 ( __1formal -> f__9name_list -> __O1__4expr.tp , __4t , (unsigned char )0 , (unsigned char )0 ) ){ 
# 3155 "/home/claude/cfront-3/src/template.cpp"
if
# 3155 "/home/claude/cfront-3/src/template.cpp"
((const_problem && (is_ptr_or_ref__4typeFv ( __4t ) == 0 ))&& (is_ptr_or_ref__4typeFv ( __1formal -> f__9name_list -> __O1__4expr.tp ) == 0 ))
# 3158 "/home/claude/cfront-3/src/template.cpp"
;
else 
# 3160 "/home/claude/cfront-3/src/template.cpp"
if (! const_formal_hack__FP4name ( __1formal -> f__9name_list ) )
# 3161 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3161 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X163 ;

# 3163 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3163 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V157 ;

# 3163 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V158 ;

# 3163 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V159 ;

# 3163 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"YA mismatch:X %t for formal %n, not %t", (const struct ea *)( (__2__X163 = (const void
# 3163 "/home/claude/cfront-3/src/template.cpp"
*)__1formal -> f__9name_list -> __O1__4expr.tp ), ( ((& __0__V157 )-> __O1__2ea.p = __2__X163 ), (& __0__V157 )) ) , (const struct
# 3163 "/home/claude/cfront-3/src/template.cpp"
ea *)__ct__2eaFPCv ( & __0__V158 , (const void *)__1formal -> f__9name_list ) , (const struct ea *)__ct__2eaFPCv ( & __0__V159 , (const
# 3163 "/home/claude/cfront-3/src/template.cpp"
void *)__1actual -> __O2__4expr.e1 -> __O1__4expr.tp ) , (const struct ea *)ea0 ) ;
error__FiPCc ( (int )'i' , (const char *)"cannot recover from previous errors") ;
} }
}

# 3169 "/home/claude/cfront-3/src/template.cpp"
{ Pname __4g ;

# 3169 "/home/claude/cfront-3/src/template.cpp"
__4g = look__5tableFPCcUc ( gtbl , __1formal -> f__9name_list -> __O2__4expr.string , (unsigned char )0 ) ;
if (__4g )__4g -> n_key__4name = 159 ;

# 3175 "/home/claude/cfront-3/src/template.cpp"
__1formal -> f__9name_list -> __O3__4expr.n_initializer = __1actual -> __O2__4expr.e1 ;
simpl__4nameFv ( __1formal -> f__9name_list ) ;
__1formal -> f__9name_list = dcl__4nameFP5tableUc ( __1formal -> f__9name_list , gtbl , (unsigned char )31 ) ;
__1formal -> f__9name_list -> n_key__4name = 159 ;
__1formal -> f__9name_list -> n_sto__4name = 31 ;
__1formal -> f__9name_list -> permanent__4node = 1 ;

# 3182 "/home/claude/cfront-3/src/template.cpp"
non_template_arg_non_type__FP4name ( __1formal -> f__9name_list ) ;
{ int __4sorry ;

# 3183 "/home/claude/cfront-3/src/template.cpp"
__4sorry = suitable_const_expr__FP4name ( __1formal -> f__9name_list ) ;

# 3185 "/home/claude/cfront-3/src/template.cpp"
switch (__4sorry ){ 
# 3185 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X164 ;

# 3185 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X165 ;

# 3186 "/home/claude/cfront-3/src/template.cpp"
case 0 :
# 3187 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3187 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V160 ;

# 3187 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"YA for formal: %sis not a suitable constant.", (const struct ea *)( (__2__X164 = (const void
# 3187 "/home/claude/cfront-3/src/template.cpp"
*)__1formal -> f__9name_list -> __O2__4expr.string ), ( ((& __0__V160 )-> __O1__2ea.p = __2__X164 ), (& __0__V160 )) ) , (const struct
# 3187 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
case -1:
# 3190 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'s' , (const char *)"actualZE ofT string literal") ;
error__FiPCc ( (int )'i' , (const char *)"cannot recover from previous errors") ;
break ;
case -2:
# 3194 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'s' , (const char *)"cast of non-integer constant") ;
break ;
case -3:
# 3197 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3197 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V161 ;

# 3197 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"YA for formal %s: address of static identifier", (const struct ea *)( (__2__X165 = (const void
# 3197 "/home/claude/cfront-3/src/template.cpp"
*)__1formal -> f__9name_list -> __O2__4expr.string ), ( ((& __0__V161 )-> __O1__2ea.p = __2__X165 ), (& __0__V161 )) ) , (const struct
# 3197 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
break ;
} } }

# 3201 "/home/claude/cfront-3/src/template.cpp"
if (__4g )__4g -> n_key__4name = 0 ;
break ;

# 3202 "/home/claude/cfront-3/src/template.cpp"
}

# 3202 "/home/claude/cfront-3/src/template.cpp"
}

# 3202 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3205 "/home/claude/cfront-3/src/template.cpp"
default :error__FiPCc ( (int )'i' , (const char *)"badY formal") ;
}

# 3208 "/home/claude/cfront-3/src/template.cpp"
}

# 3211 "/home/claude/cfront-3/src/template.cpp"
__0this -> tname__10basic_inst -> __O2__4expr.string = (const char *)instantiation_string__10basic_instFv ( (struct basic_inst *)__0this ) ;

# 3213 "/home/claude/cfront-3/src/template.cpp"
for(__1formal = __0this -> inst_formals__10basic_inst ;__1formal ;__1formal = __1formal -> l__9name_list ) 
# 3214 "/home/claude/cfront-3/src/template.cpp"
if (__1formal -> f__9name_list -> n_template_arg_string__4name )
# 3215 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"attempt to bind aYZ multiple times")
# 3215 "/home/claude/cfront-3/src/template.cpp"
;
else 
# 3217 "/home/claude/cfront-3/src/template.cpp"
__1formal -> f__9name_list -> n_template_arg_string__4name = make_formal_name__FPCcT1 ( __1formal -> f__9name_list -> __O2__4expr.string , __0this -> tname__10basic_inst -> __O2__4expr.string ) ;
}

# 366 "/home/claude/cfront-3/src/template.h"
struct Pslot {	/* sizeof Pslot == 16 */
Pname param__5Pslot ;
Ptype typ__5Pslot ;
};

# 3221 "/home/claude/cfront-3/src/template.cpp"
void bind_formals__10funct_instFv (register struct funct_inst *__0this )
# 3222 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3225 "/home/claude/cfront-3/src/template.cpp"
int __1count ;

# 3227 "/home/claude/cfront-3/src/template.cpp"
Plist __1formal ;

# 3225 "/home/claude/cfront-3/src/template.cpp"
__1count = get_formals_count__14basic_templateFv ( (struct basic_template *)__0this -> def__10funct_inst ) ;

# 3227 "/home/claude/cfront-3/src/template.cpp"
__1formal = __0this -> inst_formals__10basic_inst ;
for(;__1formal ;__1formal = __1formal -> l__9name_list ) 
# 3229 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3233 "/home/claude/cfront-3/src/template.cpp"
Pbinding __2p ;

# 3233 "/home/claude/cfront-3/src/template.cpp"
__2p = __0this -> binding__10funct_inst ;
{ { int __2i ;

# 3234 "/home/claude/cfront-3/src/template.cpp"
__2i = 0 ;

# 3234 "/home/claude/cfront-3/src/template.cpp"
for(;__2i < __1count ;( (++ __2p ), (++ __2i )) ) 
# 3235 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3237 "/home/claude/cfront-3/src/template.cpp"
if (strcmp ( __1formal -> f__9name_list -> __O2__4expr.string , __2p ->
# 3237 "/home/claude/cfront-3/src/template.cpp"
param__5Pslot -> __O2__4expr.string ) == 0 )
# 3238 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3241 "/home/claude/cfront-3/src/template.cpp"
Ptype __4t ;

# 3241 "/home/claude/cfront-3/src/template.cpp"
__4t = __2p -> typ__5Pslot ;
if (__4t -> base__4node == 138 )
# 3243 "/home/claude/cfront-3/src/template.cpp"
__4t = (struct type *)int_type ;

# 3245 "/home/claude/cfront-3/src/template.cpp"
if (__4t -> b_const__4type != 0 ){ 
# 3246 "/home/claude/cfront-3/src/template.cpp"
if ((__4t -> base__4node == 125 )|| (__4t -> base__4node == 158 )){ 
# 3247 "/home/claude/cfront-3/src/template.cpp"
Pptr __6pt ;

# 3247 "/home/claude/cfront-3/src/template.cpp"
__6pt = __ct__3ptrFUcP4type ( (struct ptr *)0 , __4t -> base__4node , (struct type *)0 ) ;
((*__6pt ))= (*(((struct ptr *)(((struct ptr *)__4t )))));
__6pt -> b_const__4type = 0 ;
__4t = (struct type *)__6pt ;
}
else 
# 3251 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3252 "/home/claude/cfront-3/src/template.cpp"
Pbase __6bt ;

# 3252 "/home/claude/cfront-3/src/template.cpp"
__6bt = __ct__8basetypeFUcP4name ( (struct basetype *)0 , __4t -> base__4node , (struct name *)0 ) ;
((*__6bt ))= (*(((struct basetype *)(((struct basetype *)__4t )))));
__6bt -> b_const__4type = 0 ;
__4t = (struct type *)__6bt ;
}
}

# 3259 "/home/claude/cfront-3/src/template.cpp"
__1formal -> f__9name_list -> __O1__4expr.tp = __4t ;
__1formal -> f__9name_list -> __O1__4expr.tp -> permanent__4node = 1 ;
}
}

# 3262 "/home/claude/cfront-3/src/template.cpp"
}

# 3262 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3266 "/home/claude/cfront-3/src/template.cpp"
__0this -> tname__10basic_inst -> __O2__4expr.string = (const char *)instantiation_string__10basic_instFv ( (struct basic_inst *)__0this ) ;

# 3270 "/home/claude/cfront-3/src/template.cpp"
for(__1formal = __0this -> inst_formals__10basic_inst ;__1formal ;__1formal = __1formal -> l__9name_list ) 
# 3271 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3272 "/home/claude/cfront-3/src/template.cpp"
if (__1formal -> f__9name_list -> n_template_arg_string__4name )
# 3273 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char
# 3273 "/home/claude/cfront-3/src/template.cpp"
*)"attempt to bind aYP multiple times") ;
else 
# 3275 "/home/claude/cfront-3/src/template.cpp"
__1formal -> f__9name_list -> n_template_arg_string__4name = make_formal_name__FPCcT1 ( __1formal -> f__9name_list -> __O2__4expr.string , __0this -> tname__10basic_inst -> __O2__4expr.string ) ;
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

# 115 "/home/claude/cfront-3/src/cfront.h"
extern Pname insert_type__FP4nameP6ktableUc (Pname , Pktab , TOK );

# 3280 "/home/claude/cfront-3/src/template.cpp"
void explicit_inst__10templ_instFv (register struct templ_inst *__0this )
# 3281 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3283 "/home/claude/cfront-3/src/template.cpp"
struct name_list __1dummy_formal ;
Plist __1last ;

# 3283 "/home/claude/cfront-3/src/template.cpp"
__ct__9name_listFP4nameP9name_list ( & __1dummy_formal , (struct name *)0 , (struct name_list *)0 ) ;
__1last = (& __1dummy_formal );

# 3286 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __1formal ;

# 3286 "/home/claude/cfront-3/src/template.cpp"
__1formal = __0this -> def__10templ_inst -> formals__14basic_template ;

# 3286 "/home/claude/cfront-3/src/template.cpp"
for(;__1formal ;__1formal = __1formal -> l__9name_list ) 
# 3287 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3288 "/home/claude/cfront-3/src/template.cpp"
Pname __2copy_name ;

# 3288 "/home/claude/cfront-3/src/template.cpp"
__2copy_name = __ct__4nameFPCc ( (struct name *)0 , (const char *)"") ;
((*__2copy_name ))= (*__1formal -> f__9name_list );
__2copy_name -> n_tbl_list__4name = 0 ;
__1last = (__1last -> l__9name_list = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __2copy_name , (struct name_list *)0 ) );
}
__0this -> inst_formals__10basic_inst = __1dummy_formal . l__9name_list ;

# 3295 "/home/claude/cfront-3/src/template.cpp"
bind_formals__10templ_instFv ( __0this ) ;
{ Pclass __1cl ;

# 3296 "/home/claude/cfront-3/src/template.cpp"
__1cl = classtype__4typeFv ( __0this -> tname__10basic_inst -> __O1__4expr.tp ) ;
__1cl -> class_base__8classdef = 4;
__1cl -> templ_base__4type = 2;
(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O2__4expr.string = __0this -> tname__10basic_inst -> __O2__4expr.string ;

# 3301 "/home/claude/cfront-3/src/template.cpp"
{ Pktab __1tb ;

# 3301 "/home/claude/cfront-3/src/template.cpp"
__1tb = __1cl -> k_tbl__8classdef -> k_next__6ktable ;
if (__1tb == 0 )
# 3303 "/home/claude/cfront-3/src/template.cpp"
__1tb = Gtbl ;
else 
# 3305 "/home/claude/cfront-3/src/template.cpp"
if (__1tb -> k_id__6ktable == 185 )
# 3306 "/home/claude/cfront-3/src/template.cpp"
__1tb = __1tb -> k_next__6ktable ;
__0this -> namep__10basic_inst = insert_type__FP4nameP6ktableUc ( __0this -> tname__10basic_inst , __1tb , __1cl -> csu__8classdef ) ;
__0this -> namep__10basic_inst -> __O1__4expr.tp = __0this -> tname__10basic_inst -> __O1__4expr.tp ;
modify_inst_names__8classdefFPCc ( __1cl , __0this -> tname__10basic_inst -> __O2__4expr.string ) ;
__1cl -> k_tbl__8classdef -> k_name__6ktable = __0this -> tname__10basic_inst ;

# 3312 "/home/claude/cfront-3/src/template.cpp"
if (__1cl -> k_tbl__8classdef -> k_name__6ktable -> n_ktable__4name == 0 )
# 3313 "/home/claude/cfront-3/src/template.cpp"
__1cl -> k_tbl__8classdef -> k_name__6ktable -> n_ktable__4name = __0this -> namep__10basic_inst -> n_ktable__4name ;

# 3313 "/home/claude/cfront-3/src/template.cpp"
}

# 3313 "/home/claude/cfront-3/src/template.cpp"
}

# 3313 "/home/claude/cfront-3/src/template.cpp"
}

# 3313 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3320 "/home/claude/cfront-3/src/template.cpp"
void expose_parameter_names__10basic_instFv (register struct basic_inst *__0this ){ 
# 3321 "/home/claude/cfront-3/src/template.cpp"
if (__0this -> hidden_globals__10basic_inst )
# 3322 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"an expose without a hide of global names")
# 3322 "/home/claude/cfront-3/src/template.cpp"
;

# 3324 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __1formal ;

# 3324 "/home/claude/cfront-3/src/template.cpp"
__1formal = __0this -> inst_formals__10basic_inst ;

# 3324 "/home/claude/cfront-3/src/template.cpp"
for(;__1formal ;__1formal = __1formal -> l__9name_list ) 
# 3325 "/home/claude/cfront-3/src/template.cpp"
if (__1formal -> f__9name_list -> n_template_arg__4name == 2){ 
# 3327 "/home/claude/cfront-3/src/template.cpp"
Pname __2gname ;

# 3327 "/home/claude/cfront-3/src/template.cpp"
__2gname = look__5tableFPCcUc ( gtbl , __1formal -> f__9name_list -> __O2__4expr.string , (unsigned char )0 ) ;
if (__2gname ){ 
# 3330 "/home/claude/cfront-3/src/template.cpp"
__2gname -> n_key__4name = 159 ;

# 3332 "/home/claude/cfront-3/src/template.cpp"
__0this -> hidden_globals__10basic_inst = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __2gname , __0this -> hidden_globals__10basic_inst ) ;
}
__1formal -> f__9name_list -> n_key__4name = 0 ;
if (__1formal -> f__9name_list != look__5tableFPCcUc ( gtbl , __1formal -> f__9name_list -> __O2__4expr.string , (unsigned char )0 ) )
# 3336 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' ,
# 3336 "/home/claude/cfront-3/src/template.cpp"
(const char *)"parameter could not be located in the global table") ;
}

# 3337 "/home/claude/cfront-3/src/template.cpp"
}

# 3337 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3344 "/home/claude/cfront-3/src/template.cpp"
void hide_parameter_names__10basic_instFv (register struct basic_inst *__0this ){ 
# 3346 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __1formal ;

# 3346 "/home/claude/cfront-3/src/template.cpp"
__1formal = __0this -> inst_formals__10basic_inst ;

# 3346 "/home/claude/cfront-3/src/template.cpp"
for(;__1formal ;__1formal = __1formal -> l__9name_list ) 
# 3347 "/home/claude/cfront-3/src/template.cpp"
if (__1formal -> f__9name_list -> n_template_arg__4name == 2){ 
# 3348 "/home/claude/cfront-3/src/template.cpp"
__1formal -> f__9name_list -> n_key__4name = 159 ;
}
for(;__0this -> hidden_globals__10basic_inst ;__0this -> hidden_globals__10basic_inst = __0this -> hidden_globals__10basic_inst -> l__9name_list ) 
# 3351 "/home/claude/cfront-3/src/template.cpp"
__0this -> hidden_globals__10basic_inst -> f__9name_list -> n_key__4name = 0 ;
__0this -> hidden_globals__10basic_inst = 0 ;

# 3352 "/home/claude/cfront-3/src/template.cpp"
}

# 3352 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3358 "/home/claude/cfront-3/src/template.cpp"
void save_state__10basic_instFP4name (register struct basic_inst *__0this , Pname __1p ){ 
# 3359 "/home/claude/cfront-3/src/template.cpp"
if (__0this -> next_active__10basic_inst )error__FiPCc ( (int )'i' , (const char *)"circular instantiation of a template")
# 3359 "/home/claude/cfront-3/src/template.cpp"
;
save__5stateFv ( & __0this -> context__10basic_inst ) ;
if (head__10basic_inst )
# 3362 "/home/claude/cfront-3/src/template.cpp"
hide_parameter_names__10basic_instFv ( head__10basic_inst ) ;
__0this -> next_active__10basic_inst = head__10basic_inst ;
head__10basic_inst = __0this ;
init__5stateFv ( & __0this -> context__10basic_inst ) ;
Cdcl = __1p ;

# 3366 "/home/claude/cfront-3/src/template.cpp"
Cstmt = 0 ;
curr_file = (Cdcl ?(((int )Cdcl -> where__4name . file__3loc )):0 );
expose_parameter_names__10basic_instFv ( __0this ) ;
}

# 3372 "/home/claude/cfront-3/src/template.cpp"
void restore_state__10basic_instFv (register struct basic_inst *__0this ){ 
# 3373 "/home/claude/cfront-3/src/template.cpp"
restore__5stateFv ( & __0this -> context__10basic_inst ) ;
hide_parameter_names__10basic_instFv ( __0this ) ;
head__10basic_inst = __0this -> next_active__10basic_inst ;

# 3375 "/home/claude/cfront-3/src/template.cpp"
__0this -> next_active__10basic_inst = 0 ;
if (head__10basic_inst )
# 3377 "/home/claude/cfront-3/src/template.cpp"
expose_parameter_names__10basic_instFv ( head__10basic_inst ) ;
}

# 76 "/home/claude/cfront-3/src/cfront.h"
static struct ea *__ct__2eaFUl (struct ea *__0this , size_t __2ii );

# 3384 "/home/claude/cfront-3/src/template.cpp"
void kludge_copy__10templ_instFP8basetype (register struct templ_inst *__0this , Pbase __1pbc )
# 3385 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3389 "/home/claude/cfront-3/src/template.cpp"
Pbase __1pb ;
Pname __1save_b_name ;
Ptype __1save_tp ;

# 3392 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X168 ;

# 3389 "/home/claude/cfront-3/src/template.cpp"
__1pb = (((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))));
__1save_b_name = __1pb -> b_name__8basetype ;
__1save_tp = __1pb -> b_name__8basetype -> __O1__4expr.tp ;

# 3393 "/home/claude/cfront-3/src/template.cpp"
if ((__1pb -> base__4node != 119 )|| (__1pbc -> base__4node != 119 ))
# 3394 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3394 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V166 ;

# 3394 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V167 ;

# 3394 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"templ_inst::kludge_copy:(pb %k,pbc %k) cobjX", (const struct ea *)( (__2__X168 =
# 3394 "/home/claude/cfront-3/src/template.cpp"
__1pb -> base__4node ), ( (( ((& __0__V166 )-> __O1__2ea.i = __2__X168 ), 0 ) ), (& __0__V166 )) ) ,
# 3394 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)__ct__2eaFUl ( & __0__V167 , (unsigned long )__1pbc -> base__4node ) , (const struct ea *)ea0 , (const
# 3394 "/home/claude/cfront-3/src/template.cpp"
struct ea *)ea0 ) ;
} 
# 3396 "/home/claude/cfront-3/src/template.cpp"
((*__1pb ))= (*__1pbc );
__1pb -> b_name__8basetype = __1save_b_name ;
((*__1pb -> b_name__8basetype ))= (*__1pbc -> b_name__8basetype );
__1pb -> b_name__8basetype -> __O1__4expr.tp = __1save_tp ;
((*(((struct classdef *)(((struct classdef *)__1pb -> b_name__8basetype -> __O1__4expr.tp ))))))= (*(((struct classdef *)(((struct classdef *)__1pbc -> b_name__8basetype -> __O1__4expr.tp )))));
(((struct classdef *)(((struct classdef *)__1pb -> b_name__8basetype -> __O1__4expr.tp ))))-> class_base__8classdef = 4;

# 3403 "/home/claude/cfront-3/src/template.cpp"
}

# 3407 "/home/claude/cfront-3/src/template.cpp"
static Pbase cobj_node ;
static Pname cname_node ;
static Pclass class_node ;
static Pfct fct_node ;

# 3413 "/home/claude/cfront-3/src/template.cpp"
static void syntax_tree_copy_hook__FPvRP4node10node_classR16tree_node_actionRi (void *__1__A169 , 
# 3414 "/home/claude/cfront-3/src/template.cpp"
Pnode *__1__A170 , 
# 3415 "/home/claude/cfront-3/src/template.cpp"
int __1__A171 , 
# 3416 "/home/claude/cfront-3/src/template.cpp"
int *__1action , 
# 3417 "/home/claude/cfront-3/src/template.cpp"
int *__1never_see_again )
# 3418 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3419 "/home/claude/cfront-3/src/template.cpp"
((*__1never_see_again ))= 1 ;
((*__1action ))= 0;
return ;
}

# 210 "/home/claude/cfront-3/src/hash.h"

# 51 "/home/claude/cfront-3/src/tree_copy.h"

# 216 "/home/claude/cfront-3/src/hash.h"

# 3427 "/home/claude/cfront-3/src/template.cpp"
static Pnode copy_syntax_tree__FP4nodei (Pnode __1n , int __1no_types ){ 
# 3428 "/home/claude/cfront-3/src/template.cpp"
struct pointer_hash __1cht ;
struct tree_copy_info __1info ;

# 3430 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X172 ;

# 3428 "/home/claude/cfront-3/src/template.cpp"
( (__2__X172 = 1000), ( (( (__ct__4HashFi ( ((struct Hash *)(& __1cht )), (int )__2__X172 ) ), ( ((&
# 3428 "/home/claude/cfront-3/src/template.cpp"
__1cht )-> key_hash_function__4Hash = (pointer_hash_fcn__FUl )), ((& __1cht )-> key_key_equality_function__4Hash = (pointer_hasheq__FUlT1 ))) ) ), (& __1cht )) ) ;
( (( ((& __1info )-> hook_info__14tree_copy_info = 0 ), ( ((& __1info )-> node_hook__14tree_copy_info = 0 ), ((& __1info )-> malloc_hook__14tree_copy_info =
# 3429 "/home/claude/cfront-3/src/template.cpp"
0 )) ) ), (& __1info )) ;
if (__1no_types )__1info . node_hook__14tree_copy_info = (syntax_tree_copy_hook__FPvRP4node10node_classR16tree_node_actionRi );
copy_tree__FRP4nodeR14tree_copy_infoP4Hash ( (Pnode *)(& __1n ), (struct tree_copy_info *)(& __1info ), (struct Hash *)(& __1cht )) ;
{ 
# 3432 "/home/claude/cfront-3/src/template.cpp"
( (((void )(((void )( ( ((((struct Hash *)(& __1cht )))?(((void )( __dl__FPv ( (void *)(((struct Hash *)(&
# 3432 "/home/claude/cfront-3/src/template.cpp"
__1cht )))-> tab__4Hash ) , ((((struct Hash *)(& __1cht )))?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) , (((void )0 )))
# 3432 "/home/claude/cfront-3/src/template.cpp"
))))) ;

# 3432 "/home/claude/cfront-3/src/template.cpp"
return __1n ;
} }

# 3436 "/home/claude/cfront-3/src/template.cpp"
int copy_hook__10templ_instFRP4node (register struct templ_inst *__0this , Pnode *__1node )
# 3437 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3438 "/home/claude/cfront-3/src/template.cpp"
switch (((*__1node ))-> base__4node ){ 
# 3439 "/home/claude/cfront-3/src/template.cpp"
case 119 :
# 3440 "/home/claude/cfront-3/src/template.cpp"
if (((*__1node ))== (((struct node *)cobj_node )))return
# 3440 "/home/claude/cfront-3/src/template.cpp"
(int )0;
if (((*__1node ))== (((struct node *)__0this -> def__10templ_inst -> namep__5templ -> __O1__4expr.tp ))){ 
# 3442 "/home/claude/cfront-3/src/template.cpp"
((*cobj_node ))= (*(((struct basetype *)(((struct basetype *)((*__1node )))))));
((*__1node ))= (struct node *)cobj_node ;
}
break ;

# 3447 "/home/claude/cfront-3/src/template.cpp"
case 85 :
# 3448 "/home/claude/cfront-3/src/template.cpp"
if (((*__1node ))== (((struct node *)cname_node )))return (int )0;
if (((*__1node ))== (((struct node *)sta_name )))return (int )0;

# 3451 "/home/claude/cfront-3/src/template.cpp"
if (((*__1node ))== (((struct node *)(((struct basetype *)(((struct basetype *)__0this -> def__10templ_inst -> namep__5templ -> __O1__4expr.tp ))))-> b_name__8basetype ))){ 
# 3452 "/home/claude/cfront-3/src/template.cpp"
((*cname_node ))= (*(((struct name *)(((struct name *)((*__1node )))))));
# 3452 "/home/claude/cfront-3/src/template.cpp"

# 3453 "/home/claude/cfront-3/src/template.cpp"
((*__1node ))= (struct node *)cname_node ;
}
break ;

# 3457 "/home/claude/cfront-3/src/template.cpp"
case 6 :
# 3458 "/home/claude/cfront-3/src/template.cpp"
if (((*__1node ))== (((struct node *)class_node )))return (int )0;
if (((*__1node ))== (((struct node *)(((struct basetype *)(((struct basetype *)__0this -> def__10templ_inst -> namep__5templ -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))){ 
# 3460 "/home/claude/cfront-3/src/template.cpp"
if (class_node == 0 )return
# 3460 "/home/claude/cfront-3/src/template.cpp"
(int )0;
((*class_node ))= (*(((struct classdef *)(((struct classdef *)((*__1node )))))));
((*__1node ))= (struct node *)class_node ;
}
break ;
}
return (int )1;
}

# 3471 "/home/claude/cfront-3/src/template.cpp"
static void copy_hook__FPvRP4node10node_classR16tree_node_actionRi (void *__1p , Pnode *__1node , 
# 3472 "/home/claude/cfront-3/src/template.cpp"
int __1__A173 , int *__1action , 
# 3473 "/home/claude/cfront-3/src/template.cpp"
int *__1never_see_again )
# 3474 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3475 "/home/claude/cfront-3/src/template.cpp"
((*__1action ))= (copy_hook__10templ_instFRP4node ( ((struct
# 3475 "/home/claude/cfront-3/src/template.cpp"
templ_inst *)(((struct templ_inst *)__1p ))), __1node ) ?0:1);
((*__1never_see_again ))= (((*__1action ))!= 1);
return ;
}

# 390 "/home/claude/cfront-3/src/template.h"
int f_copy_hook__10funct_instFRP4node (struct funct_inst *__0this , Pnode *);

# 3481 "/home/claude/cfront-3/src/template.cpp"
static void f_copy_hook__FPvRP4node10node_classR16tree_node_actionRi (void *__1p , Pnode *__1node , int __1__A174 , 
# 3482 "/home/claude/cfront-3/src/template.cpp"
int *__1action , int *__1never_see_again )
# 3483 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3486 "/home/claude/cfront-3/src/template.cpp"
((*__1action ))= (f_copy_hook__10funct_instFRP4node ( ((struct
# 3486 "/home/claude/cfront-3/src/template.cpp"
funct_inst *)(((struct funct_inst *)__1p ))), __1node ) ?0:1);
((*__1never_see_again ))= (((*__1action ))!= 1);
return ;
}

# 3493 "/home/claude/cfront-3/src/template.cpp"
int f_copy_hook__10funct_instFRP4node (register struct funct_inst *__0this , Pnode *__1node )
# 3494 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3496 "/home/claude/cfront-3/src/template.cpp"
switch (((*__1node ))-> base__4node ){ 
# 3497 "/home/claude/cfront-3/src/template.cpp"
case 85 :
# 3498 "/home/claude/cfront-3/src/template.cpp"
if (((*__1node ))== (((struct node *)sta_name )))return (int
# 3498 "/home/claude/cfront-3/src/template.cpp"
)0;
break ;
case 108 :
# 3501 "/home/claude/cfront-3/src/template.cpp"
if (((*__1node ))== (((struct node *)fct_node )))return (int )0;
if (((*__1node ))== (((struct node *)__0this -> def__10funct_inst -> fn__17function_template -> __O1__4expr.tp ))){ 
# 3503 "/home/claude/cfront-3/src/template.cpp"
((*fct_node ))= (*(((struct fct *)(((struct fct *)((*__1node )))))));
((*__1node ))= (struct node *)fct_node ;
}
break ;
}
return (int )1;
}

# 3512 "/home/claude/cfront-3/src/template.cpp"
void establish_class_subtree_correspondence__FR12pointer_hashP4nameT2 (struct pointer_hash *__1h , Pname __1key_tname , 
# 3513 "/home/claude/cfront-3/src/template.cpp"
Pname __1value_tname )
# 3514 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3515 "/home/claude/cfront-3/src/template.cpp"
((*__vc__4HashFi ( (struct Hash *)__1h , (int )(((unsigned long )__1key_tname ))) ))= (((unsigned
# 3515 "/home/claude/cfront-3/src/template.cpp"
long )__1value_tname ));
((*__vc__4HashFi ( (struct Hash *)__1h , (int )(((unsigned long )__1key_tname -> __O1__4expr.tp ))) ))= (((unsigned long )__1value_tname -> __O1__4expr.tp ));

# 3518 "/home/claude/cfront-3/src/template.cpp"
((*__vc__4HashFi ( (struct Hash *)__1h , (int )(((unsigned long )(((struct basetype *)(((struct basetype *)__1key_tname -> __O1__4expr.tp ))))-> b_name__8basetype ))) ))= (((unsigned long
# 3518 "/home/claude/cfront-3/src/template.cpp"
)(((struct basetype *)(((struct basetype *)__1value_tname -> __O1__4expr.tp ))))-> b_name__8basetype ));

# 3520 "/home/claude/cfront-3/src/template.cpp"
((*__vc__4HashFi ( (struct Hash *)__1h , (int )(((unsigned long )(((struct basetype *)(((struct basetype *)__1key_tname -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))) ))= (((unsigned
# 3520 "/home/claude/cfront-3/src/template.cpp"
long )(((struct basetype *)(((struct basetype *)__1value_tname -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ));
}

# 50 "/home/claude/cfront-3/src/template.h"

# 1109 "/home/claude/cfront-3/src/cfront.h"

# 1110 "/home/claude/cfront-3/src/cfront.h"

# 50 "/home/claude/cfront-3/src/template.h"

# 3524 "/home/claude/cfront-3/src/template.cpp"
Pcons make_ref_copy__FR12pointer_hashR14tree_copy_infoP4cons (struct pointer_hash *__1h , struct tree_copy_info *__1info , Pcons __1old_templ_refs )
# 3525 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3526 "/home/claude/cfront-3/src/template.cpp"
struct cons __1dummy ;

# 3526 "/home/claude/cfront-3/src/template.cpp"
struct cons *__1last ;

# 3527 "/home/claude/cfront-3/src/template.cpp"
struct cons *__0__X178 ;

# 3527 "/home/claude/cfront-3/src/template.cpp"
struct cons *__2__X179 ;

# 3526 "/home/claude/cfront-3/src/template.cpp"
( (__0__X178 = (& __1dummy )), ( (__2__X179 = 0 ), ( ((__0__X178 || (__0__X178 = (struct cons *)__nw__FUl ( (unsigned long
# 3526 "/home/claude/cfront-3/src/template.cpp"
)(sizeof (struct cons))) ))?( (__0__X178 -> car__4cons = ((void *)0 )), (__0__X178 -> cdr__4cons = __2__X179 )) :0 ), __0__X178 ) ) )
# 3526 "/home/claude/cfront-3/src/template.cpp"
;

# 3526 "/home/claude/cfront-3/src/template.cpp"
__1last = (& __1dummy );
{ { Pcons __1pc ;

# 3527 "/home/claude/cfront-3/src/template.cpp"
__1pc = __1old_templ_refs ;

# 3527 "/home/claude/cfront-3/src/template.cpp"
for(;__1pc ;__1pc = __1pc -> cdr__4cons ) { 
# 3529 "/home/claude/cfront-3/src/template.cpp"
Ptempl_inst __2t ;
Pexpr __2dummy ;
struct elist __2list ;

# 3529 "/home/claude/cfront-3/src/template.cpp"
__2t = (((struct templ_inst *)(((struct templ_inst *)__1pc -> car__4cons ))));
__2dummy = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , (struct expr *)0 , (struct expr *)0 ) ;
( (( ((& __2list )-> head__5elist = ((& __2list )-> tail__5elist = __2dummy )), 0 ) ), (& __2list )) ;
# 3531 "/home/claude/cfront-3/src/template.cpp"

# 3536 "/home/claude/cfront-3/src/template.cpp"
{ { Pexpr __2actual ;

# 3536 "/home/claude/cfront-3/src/template.cpp"
__2actual = __2t -> actuals__10basic_inst ;

# 3536 "/home/claude/cfront-3/src/template.cpp"
for(;__2actual ;__2actual = __2actual -> __O3__4expr.e2 ) { 
# 3537 "/home/claude/cfront-3/src/template.cpp"
Pnode __3root ;

# 3538 "/home/claude/cfront-3/src/template.cpp"
struct expr *__2__X175 ;

# 3537 "/home/claude/cfront-3/src/template.cpp"
__3root = (struct node *)__2actual -> __O2__4expr.e1 ;
copy_tree__FRP4nodeR14tree_copy_infoP4Hash ( (Pnode *)(& __3root ), __1info , (struct Hash *)(__1h )) ;

# 3541 "/home/claude/cfront-3/src/template.cpp"
__3root = (struct node *)typ__4exprFP5table ( ((struct expr *)(((struct expr *)__3root ))), gtbl ) ;
( (__2__X175 = __ct__4exprFUcP4exprT2 ( (struct expr *)0 , (unsigned char )140 , ((struct expr *)(((struct expr *)__3root ))), (struct expr *)0 ) ),
# 3542 "/home/claude/cfront-3/src/template.cpp"
( ( ((& __2list )-> tail__5elist -> __O3__4expr.e2 = __2__X175 ), ((& __2list )-> tail__5elist = __2__X175 )) , (((void )0 )))
# 3542 "/home/claude/cfront-3/src/template.cpp"
) ;
}
{ Pexpr __2new_actuals ;

# 3547 "/home/claude/cfront-3/src/template.cpp"
Ptempl_inst __2treal ;
Pname __2new_tname ;

# 3549 "/home/claude/cfront-3/src/template.cpp"
struct cons *__0__X176 ;

# 3549 "/home/claude/cfront-3/src/template.cpp"
struct cons *__2__X177 ;

# 3544 "/home/claude/cfront-3/src/template.cpp"
__2new_actuals = __2list . head__5elist -> __O3__4expr.e2 ;

# 3547 "/home/claude/cfront-3/src/template.cpp"
__2treal = get_inst__5templFP4exprP10templ_inst ( __2t -> def__10templ_inst , __2new_actuals , __2t ) ;
__2new_tname = __2treal -> tname__10basic_inst ;

# 3550 "/home/claude/cfront-3/src/template.cpp"
__1last = (__1last -> cdr__4cons = ( (__0__X176 = 0 ), ( (__2__X177 = 0 ), ( ((__0__X176 || (__0__X176 = (struct cons *)__nw__FUl (
# 3550 "/home/claude/cfront-3/src/template.cpp"
(size_t )(sizeof (struct cons))) ))?( (__0__X176 -> car__4cons = ((void *)__2treal )), (__0__X176 -> cdr__4cons = __2__X177 )) :0 ), __0__X176 )
# 3550 "/home/claude/cfront-3/src/template.cpp"
) ) );

# 3552 "/home/claude/cfront-3/src/template.cpp"
establish_class_subtree_correspondence__FR12pointer_hashP4nameT2 ( __1h , __2t -> tname__10basic_inst , __2new_tname ) ;

# 3552 "/home/claude/cfront-3/src/template.cpp"
}

# 3552 "/home/claude/cfront-3/src/template.cpp"
}

# 3552 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3555 "/home/claude/cfront-3/src/template.cpp"
return __1dummy . cdr__4cons ;

# 3555 "/home/claude/cfront-3/src/template.cpp"
}

# 3555 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3567 "/home/claude/cfront-3/src/template.cpp"
Pcons ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons (struct basic_inst *__0this , struct pointer_hash *__1h , struct tree_copy_info *__1info , Pcons __1old_templ_refs )
# 3568 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3569 "/home/claude/cfront-3/src/template.cpp"
expose_parameter_names__10basic_instFv ( __0this ) ;
{ Pcons __1new_refs ;

# 3570 "/home/claude/cfront-3/src/template.cpp"
__1new_refs = make_ref_copy__FR12pointer_hashR14tree_copy_infoP4cons ( __1h , __1info , __1old_templ_refs ) ;
hide_parameter_names__10basic_instFv ( __0this ) ;
return __1new_refs ;

# 3572 "/home/claude/cfront-3/src/template.cpp"
}
}

# 86 "/home/claude/cfront-3/src/hash.h"
int del__4HashFi (struct Hash *__0this , int __1key );

# 210 "/home/claude/cfront-3/src/hash.h"

# 51 "/home/claude/cfront-3/src/tree_copy.h"

# 3605 "/home/claude/cfront-3/src/template.cpp"
Ptempl_inst class_copy__10templ_instFRP4cons4bool (register struct templ_inst *__0this , Pcons *__1templ_refs , int __1recopy )
# 3606 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3606 "/home/claude/cfront-3/src/template.cpp"
register struct pointer_hash *__0__X181 ;

# 3606 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X182 ;

# 3609 "/home/claude/cfront-3/src/template.cpp"
if (__1recopy ){ 
# 3612 "/home/claude/cfront-3/src/template.cpp"
del__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )(((struct basetype *)(((struct basetype *)__0this -> def__10templ_inst -> namep__5templ ->
# 3612 "/home/claude/cfront-3/src/template.cpp"
__O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))) ;
del__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )(((struct basetype *)(((struct basetype *)__0this -> def__10templ_inst -> namep__5templ -> __O1__4expr.tp ))))-> b_name__8basetype )))
# 3613 "/home/claude/cfront-3/src/template.cpp"
;
del__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )__0this -> def__10templ_inst -> namep__5templ -> __O1__4expr.tp ))) ;

# 3616 "/home/claude/cfront-3/src/template.cpp"
del__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )__0this -> tname__10basic_inst -> __O1__4expr.tp ))) ;
del__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype ))) ;
# 3617 "/home/claude/cfront-3/src/template.cpp"

# 3618 "/home/claude/cfront-3/src/template.cpp"
del__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp )))
# 3618 "/home/claude/cfront-3/src/template.cpp"
;
}
else 
# 3619 "/home/claude/cfront-3/src/template.cpp"
__0this -> corr__10basic_inst = ( (__0__X181 = 0 ), ( (__2__X182 = 1000), ( ((__0__X181 || (__0__X181 = (struct pointer_hash *)__nw__FUl (
# 3619 "/home/claude/cfront-3/src/template.cpp"
(size_t )(sizeof (struct pointer_hash))) ))?( (__0__X181 = (struct pointer_hash *)__ct__4HashFi ( ((struct Hash *)__0__X181 ), (int )__2__X182 ) ), (
# 3619 "/home/claude/cfront-3/src/template.cpp"
(__0__X181 -> key_hash_function__4Hash = (pointer_hash_fcn__FUl )), (__0__X181 -> key_key_equality_function__4Hash = (pointer_hasheq__FUlT1 ))) ) :0 ), __0__X181 ) ) ) ;

# 3621 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3622 "/home/claude/cfront-3/src/template.cpp"
struct name_list __2dummy_formal ;
Plist __2last ;

# 3622 "/home/claude/cfront-3/src/template.cpp"
__ct__9name_listFP4nameP9name_list ( & __2dummy_formal , (struct name *)0 , (struct name_list *)0 ) ;
__2last = (& __2dummy_formal );

# 3625 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __2formal ;

# 3625 "/home/claude/cfront-3/src/template.cpp"
__2formal = __0this -> def__10templ_inst -> formals__14basic_template ;

# 3625 "/home/claude/cfront-3/src/template.cpp"
for(;__2formal ;__2formal = __2formal -> l__9name_list ) { 
# 3626 "/home/claude/cfront-3/src/template.cpp"
Pname __3copy_name ;

# 3626 "/home/claude/cfront-3/src/template.cpp"
__3copy_name = __ct__4nameFPCc ( (struct name *)0 , (const char *)"") ;
((*__3copy_name ))= (*__2formal -> f__9name_list );
__3copy_name -> n_tbl_list__4name = 0 ;
__2last = (__2last -> l__9name_list = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __3copy_name , (struct name_list *)0 ) );
((*__vc__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )__2formal -> f__9name_list ))) ))= (((unsigned long )__3copy_name ));
}
__0this -> inst_formals__10basic_inst = __2dummy_formal . l__9name_list ;

# 3632 "/home/claude/cfront-3/src/template.cpp"
}

# 3632 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3635 "/home/claude/cfront-3/src/template.cpp"
bind_formals__10templ_instFv ( __0this ) ;
if (! __1recopy ){ 
# 3638 "/home/claude/cfront-3/src/template.cpp"
Pname __2nnn ;

# 3638 "/home/claude/cfront-3/src/template.cpp"
__2nnn = k_find_name__FPCcP6ktableUc ( __0this -> tname__10basic_inst -> __O2__4expr.string , Gtbl , (unsigned char )159 ) ;
if (__2nnn && (__2nnn -> base__4node == 123 )){ 
# 3641 "/home/claude/cfront-3/src/template.cpp"
Ptempl_inst __3ti ;

# 3642 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X183 ;

# 3641 "/home/claude/cfront-3/src/template.cpp"
__3ti = get_match__5templFP4exprP10templ_inst4bool ( __0this -> def__10templ_inst , __0this -> actuals__10basic_inst , __0this , 1) ;
if (__3ti )return __3ti ;

# 3644 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3644 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V180 ;

# 3644 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"generated template instantiation name %swas not unique", (const struct ea *)( (__2__X183 =
# 3644 "/home/claude/cfront-3/src/template.cpp"
(const void *)__0this -> tname__10basic_inst -> __O2__4expr.string ), ( ((& __0__V180 )-> __O1__2ea.p = __2__X183 ), (& __0__V180 )) ) ,
# 3644 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
}

# 3648 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3649 "/home/claude/cfront-3/src/template.cpp"
struct tree_copy_info __2info ;

# 3649 "/home/claude/cfront-3/src/template.cpp"
( (( ((& __2info )-> hook_info__14tree_copy_info = 0 ), ( ((& __2info )-> node_hook__14tree_copy_info = 0 ), ((& __2info )-> malloc_hook__14tree_copy_info =
# 3649 "/home/claude/cfront-3/src/template.cpp"
0 )) ) ), (& __2info )) ;
__2info . node_hook__14tree_copy_info = (copy_hook__FPvRP4node10node_classR16tree_node_actionRi );
__2info . hook_info__14tree_copy_info = (void *)__0this ;

# 3653 "/home/claude/cfront-3/src/template.cpp"
((*__vc__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )__0this -> def__10templ_inst -> namep__5templ ))) ))= (((unsigned long )__0this ->
# 3653 "/home/claude/cfront-3/src/template.cpp"
tname__10basic_inst ));

# 3655 "/home/claude/cfront-3/src/template.cpp"
((*__1templ_refs ))= ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons ( (struct basic_inst *)__0this , (struct pointer_hash *)__0this -> corr__10basic_inst , (struct tree_copy_info *)(& __2info ), (*__1templ_refs )) ;
{ Pnode __2root ;

# 3656 "/home/claude/cfront-3/src/template.cpp"
__2root = (struct node *)__0this -> def__10templ_inst -> basep__5templ ;

# 3660 "/home/claude/cfront-3/src/template.cpp"
cobj_node = (((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))));
cname_node = (((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype ;
class_node = (((struct classdef *)(((struct classdef *)(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))));

# 3664 "/home/claude/cfront-3/src/template.cpp"
copy_tree__FRP4nodeR14tree_copy_infoP4Hash ( (Pnode *)(& __2root ), (struct tree_copy_info *)(& __2info ), (struct Hash *)__0this -> corr__10basic_inst ) ;

# 3664 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3668 "/home/claude/cfront-3/src/template.cpp"
cname_node -> __O2__4expr.string = __0this -> tname__10basic_inst -> __O2__4expr.string ;
if (! __1recopy ){ 
# 3672 "/home/claude/cfront-3/src/template.cpp"
Pktab __2tb ;

# 3672 "/home/claude/cfront-3/src/template.cpp"
__2tb = class_node -> k_tbl__8classdef -> k_next__6ktable ;
if (__2tb == 0 )
# 3674 "/home/claude/cfront-3/src/template.cpp"
__2tb = Gtbl ;
else 
# 3676 "/home/claude/cfront-3/src/template.cpp"
if (__2tb -> k_id__6ktable == 185 )
# 3677 "/home/claude/cfront-3/src/template.cpp"
__2tb = __2tb -> k_next__6ktable ;
__0this -> namep__10basic_inst = insert_type__FP4nameP6ktableUc ( __0this -> tname__10basic_inst , __2tb , class_node -> csu__8classdef ) ;
if (reinstat )class_node -> k_tbl__8classdef -> k_name__6ktable = __0this -> tname__10basic_inst ;
}
else class_node -> defined__4type &= -4;
__0this -> namep__10basic_inst -> __O1__4expr.tp = (struct type *)cobj_node ;

# 3684 "/home/claude/cfront-3/src/template.cpp"
modify_inst_names__8classdefFPCc ( class_node , cname_node -> __O2__4expr.string ) ;

# 3687 "/home/claude/cfront-3/src/template.cpp"
if (class_node -> k_tbl__8classdef -> k_name__6ktable -> n_ktable__4name == 0 ){ 
# 3689 "/home/claude/cfront-3/src/template.cpp"
class_node -> k_tbl__8classdef -> k_name__6ktable -> n_ktable__4name = __0this -> namep__10basic_inst -> n_ktable__4name ;
}

# 3692 "/home/claude/cfront-3/src/template.cpp"
return (struct templ_inst *)0 ;
}

# 452 "/home/claude/cfront-3/src/template.h"
Pname get_parameter__10templ_instFPCc (struct templ_inst *__0this , const char *__1s );

# 3700 "/home/claude/cfront-3/src/template.cpp"
static void function_copy_hook__FPvRP4node10node_classR16tree_node_actionRi (void *__1current_templ_inst , Pnode *__1node , int __1__A184 , 
# 3701 "/home/claude/cfront-3/src/template.cpp"
int *__1action , int *__1never_see_again )
# 3702 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3703 "/home/claude/cfront-3/src/template.cpp"
((*__1never_see_again ))= 1 ;

# 3705 "/home/claude/cfront-3/src/template.cpp"
switch (((*__1node ))-> base__4node ){ 
# 3706 "/home/claude/cfront-3/src/template.cpp"
case 85 :
# 3707 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3708 "/home/claude/cfront-3/src/template.cpp"
if (((*__1node ))== (((struct node *)sta_name ))){ 
# 3709 "/home/claude/cfront-3/src/template.cpp"
((*__1action ))= 1;
return ;
}
{ const char *__3s ;
Pname __3f ;

# 3712 "/home/claude/cfront-3/src/template.cpp"
__3s = (((struct name *)(((struct name *)((*__1node ))))))-> __O2__4expr.string ;
__3f = 0 ;
if ((__3s && (((*__3s ))== '$' ))&& (__3f = get_parameter__10templ_instFPCc ( ((struct templ_inst *)(((struct templ_inst *)__1current_templ_inst ))), __3s + 1 ) ))
# 3715 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3716 "/home/claude/cfront-3/src/template.cpp"
if ((((struct
# 3716 "/home/claude/cfront-3/src/template.cpp"
name *)(((struct name *)((*__1node ))))))-> __O1__4name.n_list )
# 3717 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"n_list set in tree template formal.") ;
((*__1node ))= copy_syntax_tree__FP4nodei ( (struct node *)(((struct name *)(((struct name *)__3f ))))-> __O3__4expr.n_initializer , 0 ) ;
((*__1action ))= 1;
((*__1never_see_again ))= 0 ;
}
else 
# 3721 "/home/claude/cfront-3/src/template.cpp"
((*__1action ))= 0;
return ;

# 3722 "/home/claude/cfront-3/src/template.cpp"
}
}
default :
# 3725 "/home/claude/cfront-3/src/template.cpp"
((*__1action ))= 0;
return ;
}
}

# 215 "/home/claude/cfront-3/src/hash.h"

# 51 "/home/claude/cfront-3/src/tree_copy.h"

# 216 "/home/claude/cfront-3/src/hash.h"

# 3731 "/home/claude/cfront-3/src/template.cpp"
Pname function_copy__10templ_instFP17function_templateRP4cons (register struct templ_inst *__0this , Pfunt __1fnt , Pcons *__1templ_refs )
# 3739 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3740 "/home/claude/cfront-3/src/template.cpp"
struct pointer_hash __1fcorr ;

# 3741 "/home/claude/cfront-3/src/template.cpp"
struct name *__0_result ;

# 3741 "/home/claude/cfront-3/src/template.cpp"
struct pointer_hash *__2__X185 ;

# 3740 "/home/claude/cfront-3/src/template.cpp"
( (__2__X185 = __0this -> corr__10basic_inst ), ( (__ct__4HashFR4Hash ( ((struct Hash *)(& __1fcorr )), (struct Hash *)__2__X185 ) ), (& __1fcorr ))
# 3740 "/home/claude/cfront-3/src/template.cpp"
) ;

# 3742 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3743 "/home/claude/cfront-3/src/template.cpp"
struct tree_copy_info __2info ;
Pnode __2root ;

# 3743 "/home/claude/cfront-3/src/template.cpp"
( (( ((& __2info )-> hook_info__14tree_copy_info = 0 ), ( ((& __2info )-> node_hook__14tree_copy_info = 0 ), ((& __2info )-> malloc_hook__14tree_copy_info =
# 3743 "/home/claude/cfront-3/src/template.cpp"
0 )) ) ), (& __2info )) ;
__2root = (struct node *)__1fnt -> fn__17function_template ;

# 3753 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __2fformal ;

# 3753 "/home/claude/cfront-3/src/template.cpp"
Plist __2cformal ;

# 3753 "/home/claude/cfront-3/src/template.cpp"
__2fformal = __1fnt -> formals__14basic_template ;

# 3753 "/home/claude/cfront-3/src/template.cpp"
__2cformal = __0this -> inst_formals__10basic_inst ;

# 3753 "/home/claude/cfront-3/src/template.cpp"
for(;__2fformal ;( (__2fformal = __2fformal -> l__9name_list ), (__2cformal = __2cformal -> l__9name_list )) ) 
# 3755 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3756 "/home/claude/cfront-3/src/template.cpp"
((*__vc__4HashFi ( (struct Hash *)(& __1fcorr ), (int
# 3756 "/home/claude/cfront-3/src/template.cpp"
)(((unsigned long )__2fformal -> f__9name_list ))) ))= (((unsigned long )__2cformal -> f__9name_list ));
if (((*__vc__4HashFi ( (struct Hash *)(& __1fcorr ), (int )(((unsigned long )__2fformal -> f__9name_list ))) ))!= (((unsigned long )__2cformal ->
# 3757 "/home/claude/cfront-3/src/template.cpp"
f__9name_list )))
# 3758 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"templ_inst::fuction_copy: hash table bug") ;
}

# 3761 "/home/claude/cfront-3/src/template.cpp"
__2info . node_hook__14tree_copy_info = (function_copy_hook__FPvRP4node10node_classR16tree_node_actionRi );
__2info . hook_info__14tree_copy_info = (void *)__0this ;

# 3764 "/home/claude/cfront-3/src/template.cpp"
((*__1templ_refs ))= ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons ( (struct basic_inst *)__0this , (struct pointer_hash *)(& __1fcorr ), (struct tree_copy_info *)(& __2info ), (*__1templ_refs )) ;
if (((*__vc__4HashFi ( (struct Hash *)(& __1fcorr ), (int )(((unsigned long )__0this -> def__10templ_inst -> namep__5templ ))) ))!= (((unsigned long
# 3765 "/home/claude/cfront-3/src/template.cpp"
)__0this -> tname__10basic_inst )))
# 3766 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'i' , (const char *)"Y to instantiationTN correspondence is missing") ;

# 3768 "/home/claude/cfront-3/src/template.cpp"
copy_tree__FRP4nodeR14tree_copy_infoP4Hash ( (Pnode *)(& __2root ), (struct tree_copy_info *)(& __2info ), (struct Hash *)(& __1fcorr )) ;
{ { __0_result = (((struct name *)(((struct name *)__2root ))));

# 3769 "/home/claude/cfront-3/src/template.cpp"
( (((void )(((void )( ( ((((struct Hash *)(& __1fcorr )))?(((void )( __dl__FPv ( (void *)(((struct Hash *)(& __1fcorr )))->
# 3769 "/home/claude/cfront-3/src/template.cpp"
tab__4Hash ) , ((((struct Hash *)(& __1fcorr )))?(((void )(((void )0 )))):(((void )0 )))) )):(((void )0 )))) , (((void )0 ))) )))))
# 3769 "/home/claude/cfront-3/src/template.cpp"
;
} 
# 3769 "/home/claude/cfront-3/src/template.cpp"
return __0_result ;
} 
# 3769 "/home/claude/cfront-3/src/template.cpp"
}

# 3769 "/home/claude/cfront-3/src/template.cpp"
}

# 3771 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3787 "/home/claude/cfront-3/src/template.cpp"
Pclass current_instantiation = 0 ;

# 3790 "/home/claude/cfront-3/src/template.cpp"
void instantiate_match__10templ_instFP10templ_inst (register struct templ_inst *__0this , Ptempl_inst __1match ){ 
# 3791 "/home/claude/cfront-3/src/template.cpp"
Pbase __1pb ;

# 3791 "/home/claude/cfront-3/src/template.cpp"
__1pb = (((struct basetype *)(((struct basetype *)__1match -> tname__10basic_inst -> __O1__4expr.tp ))));
kludge_copy__10templ_instFP8basetype ( __0this , __1pb ) ;
__0this -> forward__10templ_inst = __1match ;
}

# 3797 "/home/claude/cfront-3/src/template.cpp"
void print_nested_typedef__FP4nameP8classdef (Pname __1n , Pclass __1cl )
# 3798 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3802 "/home/claude/cfront-3/src/template.cpp"
{ { Pname __1nn ;

# 3802 "/home/claude/cfront-3/src/template.cpp"
__1nn = __1cl -> mem_list__8classdef ;

# 3802 "/home/claude/cfront-3/src/template.cpp"
for(;__1nn ;__1nn = __1nn -> __O1__4name.n_list ) { 
# 3803 "/home/claude/cfront-3/src/template.cpp"
if (__1nn -> base__4node != 123 )continue ;
if (strcmp ( __1nn -> __O2__4expr.string , __1n -> __O2__4expr.string ) == 0 ){ 
# 3805 "/home/claude/cfront-3/src/template.cpp"
if (__1nn -> n_dcl_printed__4name == 0 )
# 3806 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3807 "/home/claude/cfront-3/src/template.cpp"
dcl_print__4nameFUc ( __1nn ,
# 3807 "/home/claude/cfront-3/src/template.cpp"
(unsigned char )0 ) ;
__1nn -> n_dcl_printed__4name = 2 ;
}
break ;
}
}

# 3812 "/home/claude/cfront-3/src/template.cpp"
}

# 3812 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 477 "/home/claude/cfront-3/src/cfront.h"
void print_all_vtbls__8classdefFP8classdef (struct classdef *__0this , Pclass );

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 3816 "/home/claude/cfront-3/src/template.cpp"
Ptempl_inst instantiate__10templ_instF4bool (register struct templ_inst *__0this , int __1reinstantiate ){ 
# 3819 "/home/claude/cfront-3/src/template.cpp"
if (((dtpt_opt && (curloc . file__3loc == first_file ))&& (notinstflag == 0 ))&& ((__0this -> tname__10basic_inst ==
# 3819 "/home/claude/cfront-3/src/template.cpp"
righttname )|| ((__0this -> tname__10basic_inst && righttname )&& (! strcmp ( __0this -> tname__10basic_inst -> __O2__4expr.string , righttname -> __O2__4expr.string ) ))))
# 3825 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3826 "/home/claude/cfront-3/src/template.cpp"
dummyinst = __0this ;
# 3826 "/home/claude/cfront-3/src/template.cpp"

# 3828 "/home/claude/cfront-3/src/template.cpp"
}

# 3831 "/home/claude/cfront-3/src/template.cpp"
{ Pcons __1templ_refs ;
int __1ct ;

# 3831 "/home/claude/cfront-3/src/template.cpp"
__1templ_refs = __0this -> def__10templ_inst -> templ_refs__14basic_template ;
__1ct = (((struct templ_classdef *)(((struct templ_classdef *)(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> class_base__8classdef ;
if (! __1reinstantiate ){ 
# 3834 "/home/claude/cfront-3/src/template.cpp"
switch (__1ct ){ 
# 3834 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X189 ;

# 3835 "/home/claude/cfront-3/src/template.cpp"
case 4:
# 3836 "/home/claude/cfront-3/src/template.cpp"
return __0this ;
case 5:
# 3838 "/home/claude/cfront-3/src/template.cpp"
break ;
case 0:
# 3840 "/home/claude/cfront-3/src/template.cpp"
case 2:
# 3841 "/home/claude/cfront-3/src/template.cpp"
case 1:
# 3842 "/home/claude/cfront-3/src/template.cpp"
case 3:
# 3843 "/home/claude/cfront-3/src/template.cpp"
default :
# 3844 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3844 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V186 ;

# 3844 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"attempt to instantiate a non-YC %n", (const struct ea *)( (__2__X189 =
# 3844 "/home/claude/cfront-3/src/template.cpp"
(const void *)__0this -> namep__10basic_inst ), ( ((& __0__V186 )-> __O1__2ea.p = __2__X189 ), (& __0__V186 )) ) , (const
# 3844 "/home/claude/cfront-3/src/template.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
__0this -> status__10basic_inst = 3;

# 3850 "/home/claude/cfront-3/src/template.cpp"
forward_template_arg_types__FP9name_listP4expr ( __0this -> def__10templ_inst -> formals__14basic_template , __0this -> actuals__10basic_inst ) ;
{ Ptempl_inst __2match ;

# 3851 "/home/claude/cfront-3/src/template.cpp"
__2match = get_match__5templFP4exprP10templ_inst4bool ( __0this -> def__10templ_inst , __0this -> actuals__10basic_inst , __0this , 1) ;

# 3853 "/home/claude/cfront-3/src/template.cpp"
if (__2match || (__2match = class_copy__10templ_instFRP4cons4bool ( __0this , (Pcons *)(& __1templ_refs ), 0) )){ 
# 3855 "/home/claude/cfront-3/src/template.cpp"
instantiate_match__10templ_instFP10templ_inst ( __0this , __2match ) ;
return __0this ;
}

# 3857 "/home/claude/cfront-3/src/template.cpp"
}
}
else class_copy__10templ_instFRP4cons4bool ( __0this , (Pcons *)(& __1templ_refs ), 1) ;

# 3861 "/home/claude/cfront-3/src/template.cpp"
{ Pbase __1pb ;

# 3861 "/home/claude/cfront-3/src/template.cpp"
__1pb = (((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))));

# 3863 "/home/claude/cfront-3/src/template.cpp"
if (ansi_opt ){ 
# 3864 "/home/claude/cfront-3/src/template.cpp"
TOK __2csu ;

# 3864 "/home/claude/cfront-3/src/template.cpp"
__2csu = (((struct templ_classdef *)(((struct templ_classdef *)(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp ))))-> csu__8classdef ;
fprintf ( out_file , (const char *)"%s %s;\n", ((__2csu == 36 )|| (__2csu == 167 ))?"union":(((char
# 3865 "/home/claude/cfront-3/src/template.cpp"
*)"struct")), __0this -> tname__10basic_inst -> __O2__4expr.string ) ;
}

# 3869 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3870 "/home/claude/cfront-3/src/template.cpp"
save_state__10basic_instFP4name ( (struct basic_inst *)__0this , __0this -> def__10templ_inst -> namep__5templ ) ;

# 3872 "/home/claude/cfront-3/src/template.cpp"
if ((__0this -> def__10templ_inst -> open_instantiations__14basic_template ++ )> 16){ 
# 3873 "/home/claude/cfront-3/src/template.cpp"
error__FPCc ( (const char *)"an infinite instantiation sequence was initiated")
# 3873 "/home/claude/cfront-3/src/template.cpp"
;
__0this -> def__10templ_inst -> open_instantiations__14basic_template -- ;
return __0this ;
}

# 3879 "/home/claude/cfront-3/src/template.cpp"
(((struct classdef *)(((struct classdef *)__1pb -> b_name__8basetype -> __O1__4expr.tp ))))-> class_base__8classdef = 4;

# 3884 "/home/claude/cfront-3/src/template.cpp"
if (__0this -> def__10templ_inst -> basep__5templ -> b_name__8basetype -> __O1__4expr.tp -> defined__4type )
# 3885 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3887 "/home/claude/cfront-3/src/template.cpp"
__1pb -> b_name__8basetype -> where__4name = __0this -> def__10templ_inst -> basep__5templ -> b_name__8basetype ->
# 3887 "/home/claude/cfront-3/src/template.cpp"
where__4name ;

# 3894 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __3formal ;

# 3894 "/home/claude/cfront-3/src/template.cpp"
__3formal = __0this -> inst_formals__10basic_inst ;

# 3894 "/home/claude/cfront-3/src/template.cpp"
for(;__3formal ;__3formal = __3formal -> l__9name_list ) { 
# 3895 "/home/claude/cfront-3/src/template.cpp"
if (__3formal -> f__9name_list -> __O1__4expr.tp -> base__4node == 97 ){ 
# 3896 "/home/claude/cfront-3/src/template.cpp"
Pclass __5cl ;
Pname __5n ;

# 3897 "/home/claude/cfront-3/src/template.cpp"
__5n = (((struct basetype *)(((struct basetype *)__3formal -> f__9name_list -> __O1__4expr.tp ))))-> b_name__8basetype ;
if ((((__5n -> base__4node == 123 )&& __5n -> __O3__4expr.tpdef )&& (__5cl = __5n -> __O3__4expr.tpdef -> in_class__4type ))&& (__5cl -> c_body__8classdef == 1 ))
# 3900 "/home/claude/cfront-3/src/template.cpp"
print_nested_typedef__FP4nameP8classdef ( __5n ,
# 3900 "/home/claude/cfront-3/src/template.cpp"
__5cl ) ;
}
if (__3formal -> f__9name_list -> n_template_arg__4name == 2)
# 3903 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3904 "/home/claude/cfront-3/src/template.cpp"
dcl_print__4nameFUc ( __3formal -> f__9name_list , (unsigned char )0 ) ;
}
}

# 3909 "/home/claude/cfront-3/src/template.cpp"
{ { Pcons __3pc ;

# 3910 "/home/claude/cfront-3/src/template.cpp"
struct dcl_context *__0__X190 ;

# 3910 "/home/claude/cfront-3/src/template.cpp"
struct dcl_context *__0__X192 ;

# 3909 "/home/claude/cfront-3/src/template.cpp"
__3pc = __1templ_refs ;

# 3909 "/home/claude/cfront-3/src/template.cpp"
for(;__3pc ;__3pc = __3pc -> cdr__4cons ) 
# 3910 "/home/claude/cfront-3/src/template.cpp"
instantiate__10templ_instF4bool ( ((struct templ_inst *)(((struct templ_inst *)__3pc -> car__4cons ))), 0) ;

# 3912 "/home/claude/cfront-3/src/template.cpp"
tempdcl = 1 ;
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 3913 "/home/claude/cfront-3/src/template.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;

# 3913 "/home/claude/cfront-3/src/template.cpp"
cc -> cot__11dcl_context = 0 ;

# 3913 "/home/claude/cfront-3/src/template.cpp"
cc -> not4__11dcl_context = 0 ;

# 3913 "/home/claude/cfront-3/src/template.cpp"
cc -> tot__11dcl_context = 0 ;

# 3913 "/home/claude/cfront-3/src/template.cpp"
cc -> c_this__11dcl_context = 0 ;
curr_inst = __0this ;
if (! ((dcl__4nameFP5tableUc ( __1pb -> b_name__8basetype , gtbl , (unsigned char )14 ) == 0 )|| error_count ))
# 3916 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3917 "/home/claude/cfront-3/src/template.cpp"
simpl__4nameFv ( __1pb ->
# 3917 "/home/claude/cfront-3/src/template.cpp"
b_name__8basetype ) ;
{ Ptype __4pt ;

# 3919 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X191 ;

# 3918 "/home/claude/cfront-3/src/template.cpp"
__4pt = __1pb -> b_name__8basetype -> __O1__4expr.tp ;
if (__4pt -> base__4node != 6 )
# 3920 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3920 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V187 ;

# 3920 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"templ_inst::instantiate(%k),CX", (const struct ea *)( (__2__X191 =
# 3920 "/home/claude/cfront-3/src/template.cpp"
__4pt -> base__4node ), ( (( ((& __0__V187 )-> __O1__2ea.i = __2__X191 ), 0 ) ), (& __0__V187 )) ) ,
# 3920 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} 
# 3922 "/home/claude/cfront-3/src/template.cpp"
{ Pclass __4cl ;

# 3922 "/home/claude/cfront-3/src/template.cpp"
__4cl = (((struct classdef *)(((struct classdef *)__4pt ))));
current_instantiation = __4cl ;
dcl_print__4nameFUc ( __1pb -> b_name__8basetype , (unsigned char )0 ) ;
if (__4cl -> c_body__8classdef == 3 )print_all_vtbls__8classdefFP8classdef ( __4cl , __4cl ) ;
if (! (__4pt -> defined__4type & 01 ))
# 3927 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3927 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V188 ;

# 3927 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"templ_inst::instantiate: dclC%t is not yet defined", (const struct ea *)( ((&
# 3927 "/home/claude/cfront-3/src/template.cpp"
__0__V188 )-> __O1__2ea.p = ((const void *)__4pt )), (& __0__V188 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 3927 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) ;
} current_instantiation = 0 ;

# 3928 "/home/claude/cfront-3/src/template.cpp"
}

# 3928 "/home/claude/cfront-3/src/template.cpp"
}
}
curr_inst = 0 ;
( ( (cc -- ), (((void )0 ))) ) ;
tempdcl = 0 ;

# 3932 "/home/claude/cfront-3/src/template.cpp"
}

# 3932 "/home/claude/cfront-3/src/template.cpp"
}

# 3932 "/home/claude/cfront-3/src/template.cpp"
}

# 3932 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3937 "/home/claude/cfront-3/src/template.cpp"
{ { Ptempl_inst __2clone ;

# 3937 "/home/claude/cfront-3/src/template.cpp"
__2clone = __0this -> def__10templ_inst -> insts__5templ ;

# 3937 "/home/claude/cfront-3/src/template.cpp"
for(;__2clone ;__2clone = __2clone -> next__10templ_inst ) 
# 3938 "/home/claude/cfront-3/src/template.cpp"
if (__2clone != __0this ){ 
# 3939 "/home/claude/cfront-3/src/template.cpp"
if (__2clone -> forward__10templ_inst == __0this )
# 3940 "/home/claude/cfront-3/src/template.cpp"
kludge_copy__10templ_instFP8basetype ( __2clone , ((struct basetype *)(((struct basetype *)__0this ->
# 3940 "/home/claude/cfront-3/src/template.cpp"
tname__10basic_inst -> __O1__4expr.tp )))) ;
else { 
# 3949 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3961 "/home/claude/cfront-3/src/template.cpp"
restore_state__10basic_instFv ( (struct basic_inst *)__0this ) ;
__0this -> def__10templ_inst -> open_instantiations__14basic_template -- ;

# 3962 "/home/claude/cfront-3/src/template.cpp"
}

# 3962 "/home/claude/cfront-3/src/template.cpp"
}
}
return __0this ;

# 3964 "/home/claude/cfront-3/src/template.cpp"
}

# 3964 "/home/claude/cfront-3/src/template.cpp"
}
}

# 3969 "/home/claude/cfront-3/src/template.cpp"
struct templ_state *__ct__11templ_stateFv (register struct templ_state *__0this ){ if (__0this || (__0this = (struct templ_state *)__nw__FUl ( (size_t )(sizeof (struct templ_state))) )){
# 3969 "/home/claude/cfront-3/src/template.cpp"

# 3971 "/home/claude/cfront-3/src/template.cpp"
__0this -> param_end__11templ_state = param_end__17templ_compilation ;
__0this -> params__11templ_state = params__17templ_compilation ;
__0this -> templ_refs__11templ_state = templ_refs__17templ_compilation ;
__0this -> friend_templ_refs__11templ_state = friend_templ_refs__17templ_compilation ;
__0this -> last_cons__11templ_state = last_cons__17templ_compilation ;
__0this -> owner__11templ_state = owner__17templ_compilation ;
} 
# 3976 "/home/claude/cfront-3/src/template.cpp"
return __0this ;

# 3978 "/home/claude/cfront-3/src/template.cpp"
}

# 3980 "/home/claude/cfront-3/src/template.cpp"
void __dt__11templ_stateFv (register struct templ_state *__0this , 
# 3980 "/home/claude/cfront-3/src/template.cpp"
int __0__free ){ 
# 3980 "/home/claude/cfront-3/src/template.cpp"
if (__0this ){ 
# 3982 "/home/claude/cfront-3/src/template.cpp"
param_end__17templ_compilation = __0this -> param_end__11templ_state ;
params__17templ_compilation = __0this -> params__11templ_state ;
templ_refs__17templ_compilation = __0this -> templ_refs__11templ_state ;
friend_templ_refs__17templ_compilation = __0this -> friend_templ_refs__11templ_state ;
last_cons__17templ_compilation = __0this -> last_cons__11templ_state ;
owner__17templ_compilation = __0this -> owner__11templ_state ;

# 3989 "/home/claude/cfront-3/src/template.cpp"
if (__0this )if (__0__free & 1)__dl__FPv ( (void *)__0this ) ;
} 
# 3989 "/home/claude/cfront-3/src/template.cpp"
}

# 196 "/home/claude/cfront-3/src/template.h"

# 3991 "/home/claude/cfront-3/src/template.cpp"
struct templ *__ct__5templFP9name_listP4name (register struct templ *__0this , Plist __1parms , Pname __1p )
# 3993 "/home/claude/cfront-3/src/template.cpp"
{ 
# 3993 "/home/claude/cfront-3/src/template.cpp"
struct basic_template *__0__X196 ;

# 3993 "/home/claude/cfront-3/src/template.cpp"
if (__0this || (__0this = (struct templ *)__nw__FUl ( (size_t )(sizeof (struct templ))) )){ ( (__0this = (struct templ *)(
# 3993 "/home/claude/cfront-3/src/template.cpp"
(__0__X196 = (((struct basic_template *)__0this ))), ( ((__0__X196 || (__0__X196 = (struct basic_template *)__nw__FUl ( (size_t )(sizeof (struct basic_template))) ))?(__0__X196 -> __vptr__14basic_template =
# 3993 "/home/claude/cfront-3/src/template.cpp"
(struct __mptr *) __ptbl_vec___[0]):0 ), __0__X196 ) ) ), (__0this -> __vptr__14basic_template = (struct __mptr *) __ptbl_vec___[1])) ;

# 3996 "/home/claude/cfront-3/src/template.cpp"
__0this -> formals__14basic_template = __1parms ;

# 3998 "/home/claude/cfront-3/src/template.cpp"
__0this -> namep__5templ = __1p ;
__0this -> basep__5templ = (((struct basetype *)(((struct basetype *)__0this -> namep__5templ -> __O1__4expr.tp ))));

# 4001 "/home/claude/cfront-3/src/template.cpp"
if (__0this -> basep__5templ -> base__4node != 119 )
# 4002 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4002 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V193 ;

# 4002 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V194 ;

# 4002 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V195 ;

# 4002 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"YC%n --%n already declared asTdef (%t) ", (const struct ea *)( ((& __0__V193 )-> __O1__2ea.p =
# 4002 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1p )), (& __0__V193 )) , (const struct ea *)( ((& __0__V194 )-> __O1__2ea.p = ((const void
# 4002 "/home/claude/cfront-3/src/template.cpp"
*)__1p )), (& __0__V194 )) , (const struct ea *)__ct__2eaFPCv ( & __0__V195 , (const void *)__1p -> __O1__4expr.tp ) ,
# 4002 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) ;
} 
# 4004 "/home/claude/cfront-3/src/template.cpp"
{ Ptype __1t ;
Pclass __1cl ;

# 4004 "/home/claude/cfront-3/src/template.cpp"
__1t = __0this -> basep__5templ -> b_name__8basetype -> __O1__4expr.tp ;
__1cl = (((struct classdef *)(((struct classdef *)__1t ))));

# 4007 "/home/claude/cfront-3/src/template.cpp"
__1cl -> class_base__8classdef = 2;
__0this -> defined__5templ = ((__1t -> defined__4type & 04 )?1:0);
if (__0this -> defined__5templ )__0this -> members__5templ = __1cl -> mem_list__8classdef ;

# 4011 "/home/claude/cfront-3/src/template.cpp"
__0this -> namep__5templ -> permanent__4node = 1 ;

# 4011 "/home/claude/cfront-3/src/template.cpp"
__0this -> namep__5templ -> __O1__4expr.tp -> permanent__4node = 1 ;

# 4014 "/home/claude/cfront-3/src/template.cpp"
__0this -> next__5templ = list__17templ_compilation ;

# 4014 "/home/claude/cfront-3/src/template.cpp"
list__17templ_compilation = __0this ;

# 4014 "/home/claude/cfront-3/src/template.cpp"
}
} 
# 4004 "/home/claude/cfront-3/src/template.cpp"
return __0this ;

# 4015 "/home/claude/cfront-3/src/template.cpp"
}

# 364 "/home/claude/cfront-3/src/template.h"

# 468 "/home/claude/cfront-3/src/template.h"
struct templ_classdef *__ct__14templ_classdefFP10templ_inst (struct templ_classdef *__0this , Ptempl_inst __1i );

# 227 "/home/claude/cfront-3/src/template.h"

# 4017 "/home/claude/cfront-3/src/template.cpp"
struct templ_inst *__ct__10templ_instFP4exprP5templ (register struct templ_inst *__0this , Pexpr __1act , Ptempl __1owner )
# 4025 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4025 "/home/claude/cfront-3/src/template.cpp"
struct basic_inst *__0__X197 ;

# 4025 "/home/claude/cfront-3/src/template.cpp"
struct state *__0__X23 ;

# 4025 "/home/claude/cfront-3/src/template.cpp"
if (__0this || (__0this = (struct templ_inst *)__nw__FUl ( (size_t )(sizeof (struct templ_inst))) )){ ( (__0this = (struct templ_inst *)(
# 4025 "/home/claude/cfront-3/src/template.cpp"
(__0__X197 = (((struct basic_inst *)__0this ))), ( ((__0__X197 || (__0__X197 = (struct basic_inst *)__nw__FUl ( (size_t )(sizeof (struct basic_inst))) ))?( (__0__X197 ->
# 4025 "/home/claude/cfront-3/src/template.cpp"
__vptr__10basic_inst = (struct __mptr *) __ptbl_vec___[2]), ( (__0__X23 = (& __0__X197 -> context__10basic_inst )), ( ((__0__X23 || (__0__X23 = (struct state *)__nw__FUl ( (unsigned
# 4025 "/home/claude/cfront-3/src/template.cpp"
long )(sizeof (struct state))) ))?0 :0 ), __0__X23 ) ) ) :0 ), __0__X197 ) ) ), (__0this -> __vptr__10basic_inst = (struct
# 4025 "/home/claude/cfront-3/src/template.cpp"
__mptr *) __ptbl_vec___[3])) ;

# 4028 "/home/claude/cfront-3/src/template.cpp"
__0this -> isa__10basic_inst = 6 ;
__0this -> def__10templ_inst = __1owner ;
__0this -> tname__10basic_inst = __ct__4nameFPCc ( (struct name *)0 , __0this -> def__10templ_inst -> namep__5templ -> __O2__4expr.string ) ;
__0this -> tname__10basic_inst -> base__4node = 123 ;
__0this -> tname__10basic_inst -> __O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )119 , __ct__4nameFPCc ( (struct name *)0 , __0this ->
# 4032 "/home/claude/cfront-3/src/template.cpp"
def__10templ_inst -> namep__5templ -> __O2__4expr.string ) ) ;
{ Pclass __1c ;

# 4035 "/home/claude/cfront-3/src/template.cpp"
Pclass __1cl ;

# 4036 "/home/claude/cfront-3/src/template.cpp"
register struct templ *__0__X198 ;

# 4033 "/home/claude/cfront-3/src/template.cpp"
__1c = (struct classdef *)__ct__14templ_classdefFP10templ_inst ( (struct templ_classdef *)0 , __0this ) ;

# 4035 "/home/claude/cfront-3/src/template.cpp"
__1cl = classtype__4typeFv ( __1owner -> namep__5templ -> __O1__4expr.tp ) ;
if (__1cl -> k_tbl__8classdef )__1c -> k_tbl__8classdef = __1cl -> k_tbl__8classdef ;

# 4038 "/home/claude/cfront-3/src/template.cpp"
(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp = (struct type *)__1c ;
__0this -> tname__10basic_inst -> permanent__4node = 1 ;

# 4039 "/home/claude/cfront-3/src/template.cpp"
__0this -> tname__10basic_inst -> __O1__4expr.tp -> permanent__4node = 1 ;
(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> permanent__4node = 1 ;
(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp -> permanent__4node = 1 ;

# 4045 "/home/claude/cfront-3/src/template.cpp"
__1c -> mem_list__8classdef = ( (__0__X198 = __0this -> def__10templ_inst ), ( (((struct classdef *)(((struct classdef *)__0__X198 -> basep__5templ -> b_name__8basetype -> __O1__4expr.tp ))))) )
# 4045 "/home/claude/cfront-3/src/template.cpp"
-> mem_list__8classdef ;

# 4047 "/home/claude/cfront-3/src/template.cpp"
__0this -> actuals__10basic_inst = __1act ;
__0this -> next__10templ_inst = __1owner -> insts__5templ ;
__1owner -> insts__5templ = __0this ;

# 4049 "/home/claude/cfront-3/src/template.cpp"
}
} 
# 4033 "/home/claude/cfront-3/src/template.cpp"
return __0this ;

# 4050 "/home/claude/cfront-3/src/template.cpp"
}

# 364 "/home/claude/cfront-3/src/template.h"

# 469 "/home/claude/cfront-3/src/template.h"
struct templ_classdef *__ct__14templ_classdefFP10templ_instUc (struct templ_classdef *__0this , Ptempl_inst __1i , TOK __1csu );

# 254 "/home/claude/cfront-3/src/cfront.h"
struct ktable *__ct__6ktableFiP6ktableP4name (struct ktable *__0this , int , Pktab , Pname );

# 4052 "/home/claude/cfront-3/src/template.cpp"
struct templ_inst *__ct__10templ_instFP4exprP5templUc (register struct templ_inst *__0this , Pexpr __1act , Ptempl __1owner , TOK __1csu )
# 4053 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4053 "/home/claude/cfront-3/src/template.cpp"
struct basic_inst *__0__X199 ;

# 4053 "/home/claude/cfront-3/src/template.cpp"
struct state *__0__X23 ;

# 4053 "/home/claude/cfront-3/src/template.cpp"
if (__0this || (__0this = (struct templ_inst *)__nw__FUl ( (size_t )(sizeof (struct templ_inst))) )){ ( (__0this = (struct templ_inst *)(
# 4053 "/home/claude/cfront-3/src/template.cpp"
(__0__X199 = (((struct basic_inst *)__0this ))), ( ((__0__X199 || (__0__X199 = (struct basic_inst *)__nw__FUl ( (size_t )(sizeof (struct basic_inst))) ))?( (__0__X199 ->
# 4053 "/home/claude/cfront-3/src/template.cpp"
__vptr__10basic_inst = (struct __mptr *) __ptbl_vec___[2]), ( (__0__X23 = (& __0__X199 -> context__10basic_inst )), ( ((__0__X23 || (__0__X23 = (struct state *)__nw__FUl ( (unsigned
# 4053 "/home/claude/cfront-3/src/template.cpp"
long )(sizeof (struct state))) ))?0 :0 ), __0__X23 ) ) ) :0 ), __0__X199 ) ) ), (__0this -> __vptr__10basic_inst = (struct
# 4053 "/home/claude/cfront-3/src/template.cpp"
__mptr *) __ptbl_vec___[3])) ;

# 4055 "/home/claude/cfront-3/src/template.cpp"
__0this -> isa__10basic_inst = 6 ;
__0this -> def__10templ_inst = __1owner ;
__0this -> tname__10basic_inst = __ct__4nameFPCc ( (struct name *)0 , __1owner -> namep__5templ -> __O2__4expr.string ) ;
__0this -> tname__10basic_inst -> base__4node = 123 ;
__0this -> tname__10basic_inst -> __O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name ( (struct basetype *)0 , (unsigned char )119 , __ct__4nameFPCc ( (struct name *)0 , __1owner ->
# 4059 "/home/claude/cfront-3/src/template.cpp"
namep__5templ -> __O2__4expr.string ) ) ;
{ Pclass __1c ;

# 4060 "/home/claude/cfront-3/src/template.cpp"
__1c = (struct classdef *)__ct__14templ_classdefFP10templ_instUc ( (struct templ_classdef *)0 , __0this , __1csu ) ;

# 4063 "/home/claude/cfront-3/src/template.cpp"
__1c -> k_tbl__8classdef = __ct__6ktableFiP6ktableP4name ( (struct ktable *)0 , 0 , (struct ktable *)0 , __0this -> tname__10basic_inst ) ;
__1c -> k_tbl__8classdef -> k_id__6ktable = 6 ;

# 4066 "/home/claude/cfront-3/src/template.cpp"
(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp = (struct type *)__1c ;
__0this -> tname__10basic_inst -> permanent__4node = 1 ;

# 4067 "/home/claude/cfront-3/src/template.cpp"
__0this -> tname__10basic_inst -> __O1__4expr.tp -> permanent__4node = 1 ;
(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> permanent__4node = 1 ;
(((struct basetype *)(((struct basetype *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> b_name__8basetype -> __O1__4expr.tp -> permanent__4node = 1 ;

# 4076 "/home/claude/cfront-3/src/template.cpp"
__0this -> actuals__10basic_inst = __1act ;
__0this -> next__10templ_inst = __1owner -> insts__5templ ;
__1owner -> insts__5templ = __0this ;

# 4078 "/home/claude/cfront-3/src/template.cpp"
}
} 
# 4060 "/home/claude/cfront-3/src/template.cpp"
return __0this ;

# 4079 "/home/claude/cfront-3/src/template.cpp"
}

# 364 "/home/claude/cfront-3/src/template.h"

# 476 "/home/claude/cfront-3/src/template.h"
struct templ_fct *__ct__9templ_fctFP10funct_inst (struct templ_fct *__0this , Pfunct_inst __1i );

# 4081 "/home/claude/cfront-3/src/template.cpp"
struct funct_inst *__ct__10funct_instFP4exprP17function_template (register struct funct_inst *__0this , Pexpr __1act , Pfunt __1owner )
# 4085 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4085 "/home/claude/cfront-3/src/template.cpp"
struct basic_inst *__0__X200 ;

# 4085 "/home/claude/cfront-3/src/template.cpp"
struct state *__0__X23 ;

# 4085 "/home/claude/cfront-3/src/template.cpp"
if (__0this || (__0this = (struct funct_inst *)__nw__FUl ( (size_t )(sizeof (struct funct_inst))) )){ ( (__0this = (struct funct_inst *)(
# 4085 "/home/claude/cfront-3/src/template.cpp"
(__0__X200 = (((struct basic_inst *)__0this ))), ( ((__0__X200 || (__0__X200 = (struct basic_inst *)__nw__FUl ( (size_t )(sizeof (struct basic_inst))) ))?( (__0__X200 ->
# 4085 "/home/claude/cfront-3/src/template.cpp"
__vptr__10basic_inst = (struct __mptr *) __ptbl_vec___[2]), ( (__0__X23 = (& __0__X200 -> context__10basic_inst )), ( ((__0__X23 || (__0__X23 = (struct state *)__nw__FUl ( (unsigned
# 4085 "/home/claude/cfront-3/src/template.cpp"
long )(sizeof (struct state))) ))?0 :0 ), __0__X23 ) ) ) :0 ), __0__X200 ) ) ), (__0this -> __vptr__10basic_inst = (struct
# 4085 "/home/claude/cfront-3/src/template.cpp"
__mptr *) __ptbl_vec___[4])) ;

# 4087 "/home/claude/cfront-3/src/template.cpp"
__0this -> isa__10basic_inst = 108 ;
__0this -> def__10funct_inst = __1owner ;
__0this -> tname__10basic_inst = __ct__4nameFPCc ( (struct name *)0 , __0this -> def__10funct_inst -> fn__17function_template -> __O2__4expr.string ) ;
__0this -> tname__10basic_inst -> __O1__4expr.tp = (struct type *)__ct__9templ_fctFP10funct_inst ( (struct templ_fct *)0 , __0this ) ;
__0this -> actuals__10basic_inst = __1act ;

# 4093 "/home/claude/cfront-3/src/template.cpp"
__0this -> next__10funct_inst = __1owner -> insts__17function_template ;
__1owner -> insts__17function_template = __0this ;
__0this -> tname__10basic_inst -> permanent__4node = 1 ;

# 4095 "/home/claude/cfront-3/src/template.cpp"
__0this -> tname__10basic_inst -> __O1__4expr.tp -> permanent__4node = 1 ;
} 
# 4095 "/home/claude/cfront-3/src/template.cpp"
return __0this ;
}

# 443 "/home/claude/cfront-3/src/cfront.h"
struct classdef *__ct__8classdefFUc (struct classdef *__0this , TOK );

# 470 "/home/claude/cfront-3/src/template.h"

# 4098 "/home/claude/cfront-3/src/template.cpp"
struct templ_classdef *__ct__14templ_classdefFP10templ_inst (register struct templ_classdef *__0this , Ptempl_inst __1i )
# 4100 "/home/claude/cfront-3/src/template.cpp"
{ if (__0this || (__0this = (struct templ_classdef *)__nw__FUl ( (size_t )(sizeof (struct templ_classdef)))
# 4100 "/home/claude/cfront-3/src/template.cpp"
)){ __0this = (struct templ_classdef *)__ct__8classdefFUc ( ((struct classdef *)__0this ), (unsigned char )6 ) ;
__0this -> inst__14templ_classdef = __1i ;
__0this -> class_base__8classdef = 5;
__0this -> string__8classdef = ( __0this -> inst__14templ_classdef -> def__10templ_inst -> namep__5templ ) -> __O2__4expr.string ;
} 
# 4103 "/home/claude/cfront-3/src/template.cpp"
return __0this ;

# 4105 "/home/claude/cfront-3/src/template.cpp"
}

# 4107 "/home/claude/cfront-3/src/template.cpp"
struct templ_classdef *__ct__14templ_classdefFP10templ_instUc (register struct templ_classdef *__0this , Ptempl_inst __1i , TOK __1csu )
# 4109 "/home/claude/cfront-3/src/template.cpp"
{ if (__0this || (__0this = (struct templ_classdef *)__nw__FUl ( (size_t)(sizeof
# 4109 "/home/claude/cfront-3/src/template.cpp"
(struct templ_classdef))) )){ __0this = (struct templ_classdef *)__ct__8classdefFUc ( ((struct classdef *)__0this ), __1csu ) ;
__0this -> inst__14templ_classdef = __1i ;
__0this -> class_base__8classdef = 4;
__0this -> templ_base__4type = 2;
} 
# 4112 "/home/claude/cfront-3/src/template.cpp"
return __0this ;

# 4114 "/home/claude/cfront-3/src/template.cpp"
}

# 633 "/home/claude/cfront-3/src/cfront.h"
struct fct *__ct__3fctFP4typeP4nameUc (struct fct *__0this , Ptype , Pname , TOK );

# 4116 "/home/claude/cfront-3/src/template.cpp"
struct templ_fct *__ct__9templ_fctFP10funct_inst (register struct templ_fct *__0this , Pfunct_inst __1i ){ if (__0this || (__0this = (struct templ_fct *)__nw__9templ_fctSFUl ( (size_t )(sizeof (struct templ_fct)))
# 4116 "/home/claude/cfront-3/src/template.cpp"
)){ __0this = (struct templ_fct *)__ct__3fctFP4typeP4nameUc ( ((struct fct *)__0this ), (struct type *)0 , (struct name *)0 , (unsigned char )0 ) ;
# 4116 "/home/claude/cfront-3/src/template.cpp"

# 4118 "/home/claude/cfront-3/src/template.cpp"
__0this -> inst__9templ_fct = __1i ;
__0this -> fct_base__3fct = 5;
} 
# 4119 "/home/claude/cfront-3/src/template.cpp"
return __0this ;
}

# 196 "/home/claude/cfront-3/src/template.h"

# 4122 "/home/claude/cfront-3/src/template.cpp"
struct data_template *__ct__13data_templateFR5templP9name_listP4name (register struct data_template *__0this , struct templ *__1owner , Plist __1params , Pname __1n )
# 4123 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4123 "/home/claude/cfront-3/src/template.cpp"
struct basic_template *__0__X201 ;

# 4123 "/home/claude/cfront-3/src/template.cpp"
if (__0this || (__0this = (struct data_template *)__nw__FUl ( (size_t )(sizeof (struct data_template))) )){ ( (__0this = (struct data_template *)(
# 4123 "/home/claude/cfront-3/src/template.cpp"
(__0__X201 = (((struct basic_template *)__0this ))), ( ((__0__X201 || (__0__X201 = (struct basic_template *)__nw__FUl ( (size_t )(sizeof (struct basic_template))) ))?(__0__X201 -> __vptr__14basic_template =
# 4123 "/home/claude/cfront-3/src/template.cpp"
(struct __mptr *) __ptbl_vec___[0]):0 ), __0__X201 ) ) ), (__0this -> __vptr__14basic_template = (struct __mptr *) __ptbl_vec___[5])) ;

# 4125 "/home/claude/cfront-3/src/template.cpp"
if (((*__1owner )). data_end__5templ )
# 4126 "/home/claude/cfront-3/src/template.cpp"
((*__1owner )). data_end__5templ -> next__13data_template = __0this ;
else ((*__1owner )). data__5templ = __0this ;
((*__1owner )). data_end__5templ = __0this ;
__0this -> formals__14basic_template = __1params ;
__0this -> dat_mem__13data_template = __1n ;
__1n -> permanent__4node = 1 ;

# 4131 "/home/claude/cfront-3/src/template.cpp"
__1n -> __O1__4expr.tp -> permanent__4node = 1 ;
} 
# 4131 "/home/claude/cfront-3/src/template.cpp"
return __0this ;
}

# 196 "/home/claude/cfront-3/src/template.h"

# 4134 "/home/claude/cfront-3/src/template.cpp"
struct function_template *__ct__17function_templateFR5templP9name_listP4name (register struct function_template *__0this , struct templ *__1owner , Plist __1params , Pname __1n )
# 4135 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4135 "/home/claude/cfront-3/src/template.cpp"
struct basic_template *__0__X202 ;

# 4135 "/home/claude/cfront-3/src/template.cpp"
if (__0this || (__0this = (struct function_template *)__nw__FUl ( (size_t )(sizeof (struct function_template))) )){ ( (__0this = (struct function_template *)(
# 4135 "/home/claude/cfront-3/src/template.cpp"
(__0__X202 = (((struct basic_template *)__0this ))), ( ((__0__X202 || (__0__X202 = (struct basic_template *)__nw__FUl ( (size_t )(sizeof (struct basic_template))) ))?(__0__X202 -> __vptr__14basic_template =
# 4135 "/home/claude/cfront-3/src/template.cpp"
(struct __mptr *) __ptbl_vec___[0]):0 ), __0__X202 ) ) ), (__0this -> __vptr__14basic_template = (struct __mptr *) __ptbl_vec___[6])) ;

# 4137 "/home/claude/cfront-3/src/template.cpp"
if (((*__1owner )). fns_end__5templ )
# 4138 "/home/claude/cfront-3/src/template.cpp"
((*__1owner )). fns_end__5templ -> next__17function_template = __0this ;
else ((*__1owner )). fns__5templ = __0this ;
((*__1owner )). fns_end__5templ = __0this ;
__0this -> formals__14basic_template = __1params ;
__0this -> fn__17function_template = __1n ;
__1n -> permanent__4node = 1 ;

# 4143 "/home/claude/cfront-3/src/template.cpp"
__1n -> __O1__4expr.tp -> permanent__4node = 1 ;
} 
# 4143 "/home/claude/cfront-3/src/template.cpp"
return __0this ;
}

# 196 "/home/claude/cfront-3/src/template.h"

# 4146 "/home/claude/cfront-3/src/template.cpp"
struct function_template *__ct__17function_templateFP9name_listP4name (register struct function_template *__0this , Plist __1params , Pname __1n )
# 4147 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4147 "/home/claude/cfront-3/src/template.cpp"
struct basic_template *__0__X203 ;

# 4147 "/home/claude/cfront-3/src/template.cpp"
if (__0this || (__0this = (struct function_template *)__nw__FUl ( (size_t )(sizeof (struct function_template))) )){ ( (__0this = (struct function_template *)(
# 4147 "/home/claude/cfront-3/src/template.cpp"
(__0__X203 = (((struct basic_template *)__0this ))), ( ((__0__X203 || (__0__X203 = (struct basic_template *)__nw__FUl ( (size_t )(sizeof (struct basic_template))) ))?(__0__X203 -> __vptr__14basic_template =
# 4147 "/home/claude/cfront-3/src/template.cpp"
(struct __mptr *) __ptbl_vec___[0]):0 ), __0__X203 ) ) ), (__0this -> __vptr__14basic_template = (struct __mptr *) __ptbl_vec___[6])) ;

# 4149 "/home/claude/cfront-3/src/template.cpp"
__0this -> formals__14basic_template = __1params ;
__0this -> fn__17function_template = __1n ;
(((struct fct *)(((struct fct *)__1n -> __O1__4expr.tp ))))-> fct_base__3fct = 1;
__0this -> next__17function_template = f_list__17templ_compilation ;

# 4152 "/home/claude/cfront-3/src/template.cpp"
f_list__17templ_compilation = __0this ;
__0this -> templ_refs__14basic_template = 0 ;
__1n -> permanent__4node = 1 ;

# 4154 "/home/claude/cfront-3/src/template.cpp"
__1n -> __O1__4expr.tp -> permanent__4node = 1 ;
} 
# 4154 "/home/claude/cfront-3/src/template.cpp"
return __0this ;
}

# 4158 "/home/claude/cfront-3/src/template.cpp"
Pname get_parameter__10templ_instFPCc (register struct templ_inst *__0this , const char *__1s ){ 
# 4159 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __1formal ;

# 4159 "/home/claude/cfront-3/src/template.cpp"
__1formal = __0this -> inst_formals__10basic_inst ;

# 4159 "/home/claude/cfront-3/src/template.cpp"
for(;__1formal ;__1formal = __1formal -> l__9name_list ) 
# 4160 "/home/claude/cfront-3/src/template.cpp"
if (strcmp ( __1formal -> f__9name_list -> __O2__4expr.string , __1s ) == 0 )
# 4161 "/home/claude/cfront-3/src/template.cpp"
return __1formal -> f__9name_list ;
return (struct name *)0 ;

# 4162 "/home/claude/cfront-3/src/template.cpp"
}

# 4162 "/home/claude/cfront-3/src/template.cpp"
}
}

# 210 "/home/claude/cfront-3/src/hash.h"

# 51 "/home/claude/cfront-3/src/tree_copy.h"

# 4166 "/home/claude/cfront-3/src/template.cpp"
Pfunct_inst tfct_copy__10funct_instFRP4cons4bool (register struct funct_inst *__0this , Pcons *__1templ_refs , int __1recopy )
# 4167 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4167 "/home/claude/cfront-3/src/template.cpp"
register struct pointer_hash *__0__X205 ;

# 4167 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X206 ;

# 4171 "/home/claude/cfront-3/src/template.cpp"
if (__1recopy ){ 
# 4174 "/home/claude/cfront-3/src/template.cpp"
del__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )__0this -> def__10funct_inst -> fn__17function_template ))) ;
del__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )__0this -> tname__10basic_inst ))) ;
}
else __0this -> corr__10basic_inst = ( (__0__X205 = 0 ), ( (__2__X206 = 1000), ( ((__0__X205 || (__0__X205 = (struct pointer_hash *)__nw__FUl (
# 4177 "/home/claude/cfront-3/src/template.cpp"
(size_t )(sizeof (struct pointer_hash))) ))?( (__0__X205 = (struct pointer_hash *)__ct__4HashFi ( ((struct Hash *)__0__X205 ), (int )__2__X206 ) ), (
# 4177 "/home/claude/cfront-3/src/template.cpp"
(__0__X205 -> key_hash_function__4Hash = (pointer_hash_fcn__FUl )), (__0__X205 -> key_key_equality_function__4Hash = (pointer_hasheq__FUlT1 ))) ) :0 ), __0__X205 ) ) ) ;

# 4180 "/home/claude/cfront-3/src/template.cpp"
{ struct name_list __1dummy_formal ;
Plist __1last ;

# 4180 "/home/claude/cfront-3/src/template.cpp"
__ct__9name_listFP4nameP9name_list ( & __1dummy_formal , (struct name *)0 , (struct name_list *)0 ) ;
__1last = (& __1dummy_formal );

# 4183 "/home/claude/cfront-3/src/template.cpp"
{ { Plist __1formal ;

# 4183 "/home/claude/cfront-3/src/template.cpp"
__1formal = __0this -> def__10funct_inst -> formals__14basic_template ;

# 4183 "/home/claude/cfront-3/src/template.cpp"
for(;__1formal ;__1formal = __1formal -> l__9name_list ) { 
# 4184 "/home/claude/cfront-3/src/template.cpp"
Pname __2copy_name ;

# 4184 "/home/claude/cfront-3/src/template.cpp"
__2copy_name = __ct__4nameFPCc ( (struct name *)0 , (const char *)"") ;
((*__2copy_name ))= (*__1formal -> f__9name_list );
__2copy_name -> n_tbl_list__4name = 0 ;
__1last = (__1last -> l__9name_list = __ct__9name_listFP4nameP9name_list ( (struct name_list *)0 , __2copy_name , (struct name_list *)0 ) );
((*__vc__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )__1formal -> f__9name_list ))) ))= (((unsigned long )__2copy_name ));
}
__0this -> inst_formals__10basic_inst = __1dummy_formal . l__9name_list ;

# 4192 "/home/claude/cfront-3/src/template.cpp"
bind_formals__10funct_instFv ( __0this ) ;
if ((! __1recopy )&& look__5tableFPCcUc ( gtbl , __0this -> tname__10basic_inst -> __O2__4expr.string , (unsigned char )0 ) ){ 
# 4195 "/home/claude/cfront-3/src/template.cpp"
Pfunct_inst __2ti ;

# 4196 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X207 ;

# 4195 "/home/claude/cfront-3/src/template.cpp"
__2ti = get_match__17function_templateFP4exprP10funct_inst4bool ( __0this -> def__10funct_inst , __0this -> actuals__10basic_inst , __0this , 1) ;
if (__2ti )return __2ti ;
{ 
# 4197 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V204 ;

# 4197 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"generatedY instanceN %s not unique", (const struct ea *)( (__2__X207 =
# 4197 "/home/claude/cfront-3/src/template.cpp"
(const void *)__0this -> tname__10basic_inst -> __O2__4expr.string ), ( ((& __0__V204 )-> __O1__2ea.p = __2__X207 ), (& __0__V204 )) ) ,
# 4197 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }

# 4200 "/home/claude/cfront-3/src/template.cpp"
{ struct tree_copy_info __1info ;

# 4200 "/home/claude/cfront-3/src/template.cpp"
( (( ((& __1info )-> hook_info__14tree_copy_info = 0 ), ( ((& __1info )-> node_hook__14tree_copy_info = 0 ), ((& __1info )-> malloc_hook__14tree_copy_info =
# 4200 "/home/claude/cfront-3/src/template.cpp"
0 )) ) ), (& __1info )) ;
__1info . node_hook__14tree_copy_info = (f_copy_hook__FPvRP4node10node_classR16tree_node_actionRi );
__1info . hook_info__14tree_copy_info = (void *)__0this ;

# 4204 "/home/claude/cfront-3/src/template.cpp"
{ Pnode __1root ;

# 4204 "/home/claude/cfront-3/src/template.cpp"
__1root = (struct node *)__0this -> def__10funct_inst -> fn__17function_template -> __O1__4expr.tp ;
fct_node = (((struct fct *)(((struct fct *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))));

# 4208 "/home/claude/cfront-3/src/template.cpp"
((*__vc__4HashFi ( (struct Hash *)__0this -> corr__10basic_inst , (int )(((unsigned long )__0this -> def__10funct_inst -> fn__17function_template ))) ))= (((unsigned long )__0this ->
# 4208 "/home/claude/cfront-3/src/template.cpp"
tname__10basic_inst ));
((*__1templ_refs ))= ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons ( (struct basic_inst *)__0this , (struct pointer_hash *)__0this -> corr__10basic_inst , (struct tree_copy_info *)(& __1info ), (*__1templ_refs )) ;
copy_tree__FRP4nodeR14tree_copy_infoP4Hash ( (Pnode *)(& __1root ), (struct tree_copy_info *)(& __1info ), (struct Hash *)__0this -> corr__10basic_inst ) ;
return (struct funct_inst *)0 ;

# 4211 "/home/claude/cfront-3/src/template.cpp"
}

# 4211 "/home/claude/cfront-3/src/template.cpp"
}

# 4211 "/home/claude/cfront-3/src/template.cpp"
}

# 4211 "/home/claude/cfront-3/src/template.cpp"
}

# 4211 "/home/claude/cfront-3/src/template.cpp"
}
}

# 4214 "/home/claude/cfront-3/src/template.cpp"
Pfct current_fct_instantiation = 0 ;
Pfunct_inst fct_instantiation = 0 ;

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 1130 "/home/claude/cfront-3/src/cfront.h"

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 1138 "/home/claude/cfront-3/src/cfront.h"

# 4218 "/home/claude/cfront-3/src/template.cpp"
void instantiate__10funct_instF4bool (register struct funct_inst *__0this , int __1reinstantiate ){ 
# 4221 "/home/claude/cfront-3/src/template.cpp"
Pcons __1templ_refs ;
int __1ft ;

# 4221 "/home/claude/cfront-3/src/template.cpp"
__1templ_refs = __0this -> def__10funct_inst -> templ_refs__14basic_template ;
__1ft = (((struct templ_fct *)(((struct templ_fct *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))))-> fct_base__3fct ;
if (! __1reinstantiate ){ 
# 4224 "/home/claude/cfront-3/src/template.cpp"
switch (__1ft ){ 
# 4224 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X213 ;

# 4225 "/home/claude/cfront-3/src/template.cpp"
case 4:
# 4226 "/home/claude/cfront-3/src/template.cpp"
if (((dtpt_opt && (fdummyinst == 0 ))&& (curloc . file__3loc == first_file ))&& (tempdcl == 0 ))
# 4231 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4231 "/home/claude/cfront-3/src/template.cpp"
register struct name *__0__X212 ;

# 4231 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 4231 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 4231 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 4232 "/home/claude/cfront-3/src/template.cpp"
fdummyinst = __0this ;
fcurr_inst = __0this ;
current_fct_instantiation = ( (__0__X212 = __0this -> tname__10basic_inst ), ( ((__0__X212 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X212 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 (
# 4234 "/home/claude/cfront-3/src/template.cpp"
(int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )->
# 4234 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.p = ((const void *)__0__X212 )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __0__X212 -> __O1__4expr.tp -> base__4node ),
# 4234 "/home/claude/cfront-3/src/template.cpp"
( (( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct
# 4234 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) ;
if (finst_body__4nameFv ( __0this -> tname__10basic_inst ) )dcl_print__4nameFUc ( __0this -> tname__10basic_inst , (unsigned char )0 ) ;
current_fct_instantiation = 0 ;
}
return ;
case 5:
# 4240 "/home/claude/cfront-3/src/template.cpp"
break ;
case 0:
# 4242 "/home/claude/cfront-3/src/template.cpp"
case 2:
# 4243 "/home/claude/cfront-3/src/template.cpp"
case 1:
# 4244 "/home/claude/cfront-3/src/template.cpp"
case 3:
# 4245 "/home/claude/cfront-3/src/template.cpp"
default :
# 4246 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4246 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V208 ;

# 4246 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"attempt to instantiate a non-YF %n", (const struct ea *)( (__2__X213 =
# 4246 "/home/claude/cfront-3/src/template.cpp"
(const void *)__0this -> namep__10basic_inst ), ( ((& __0__V208 )-> __O1__2ea.p = __2__X213 ), (& __0__V208 )) ) , (const
# 4246 "/home/claude/cfront-3/src/template.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} }
__0this -> status__10basic_inst = 1;

# 4250 "/home/claude/cfront-3/src/template.cpp"
if (((dtpt_opt && (fdummyinst == 0 ))&& (curloc . file__3loc == first_file ))&& (tempdcl == 0 ))
# 4251 "/home/claude/cfront-3/src/template.cpp"
fdummyinst = __0this ;

# 4256 "/home/claude/cfront-3/src/template.cpp"
{ { Pexpr __2e ;

# 4259 "/home/claude/cfront-3/src/template.cpp"
Pfunct_inst __2dup ;

# 4256 "/home/claude/cfront-3/src/template.cpp"
__2e = __0this -> actuals__10basic_inst ;

# 4256 "/home/claude/cfront-3/src/template.cpp"
for(;__2e ;__2e = __2e -> __O3__4expr.e2 ) 
# 4257 "/home/claude/cfront-3/src/template.cpp"
__2e -> __O2__4expr.e1 -> __O1__4expr.tp = non_template_arg_type__FP8basetype ( ((struct basetype *)(((struct basetype *)__2e -> __O2__4expr.e1 -> __O1__4expr.tp )))) ;

# 4259 "/home/claude/cfront-3/src/template.cpp"
;
if (__2dup = tfct_copy__10funct_instFRP4cons4bool ( __0this , (Pcons *)(& __1templ_refs ), 0) )
# 4261 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4261 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X214 ;

# 4263 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4263 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V209 ;

# 4263 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"FT %n already instantiated", (const struct ea *)( (__2__X214 =
# 4263 "/home/claude/cfront-3/src/template.cpp"
(const void *)__0this -> namep__10basic_inst ), ( ((& __0__V209 )-> __O1__2ea.p = __2__X214 ), (& __0__V209 )) ) , (const
# 4263 "/home/claude/cfront-3/src/template.cpp"
struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
return ;
} }

# 4265 "/home/claude/cfront-3/src/template.cpp"
}

# 4265 "/home/claude/cfront-3/src/template.cpp"
}
}
else tfct_copy__10funct_instFRP4cons4bool ( __0this , (Pcons *)(& __1templ_refs ), 1) ;

# 4273 "/home/claude/cfront-3/src/template.cpp"
__0this -> tname__10basic_inst -> n_oper__4name = __0this -> def__10funct_inst -> fn__17function_template -> n_oper__4name ;
__0this -> tname__10basic_inst -> where__4name = __0this -> def__10funct_inst -> fn__17function_template -> where__4name ;

# 4276 "/home/claude/cfront-3/src/template.cpp"
save_state__10basic_instFP4name ( (struct basic_inst *)__0this , __0this -> def__10funct_inst -> fn__17function_template ) ;
if ((__0this -> def__10funct_inst -> open_instantiations__14basic_template ++ )> 16){ 
# 4277 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X215 ;

# 4278 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4278 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V210 ;

# 4278 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"%n: an infinite instantiation sequence was initiated", (const struct ea *)( (__2__X215 = (const void
# 4278 "/home/claude/cfront-3/src/template.cpp"
*)__0this -> namep__10basic_inst ), ( ((& __0__V210 )-> __O1__2ea.p = __2__X215 ), (& __0__V210 )) ) , (const struct ea *)ea0 ,
# 4278 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__0this -> def__10funct_inst -> open_instantiations__14basic_template -- ;
return ;
} }

# 4284 "/home/claude/cfront-3/src/template.cpp"
{ Ptfct __1ptf ;

# 4284 "/home/claude/cfront-3/src/template.cpp"
__1ptf = (((struct templ_fct *)(((struct templ_fct *)__0this -> tname__10basic_inst -> __O1__4expr.tp ))));
__1ptf -> fct_base__3fct = 4;

# 4288 "/home/claude/cfront-3/src/template.cpp"
{ { Pcons __1pc ;

# 4289 "/home/claude/cfront-3/src/template.cpp"
struct dcl_context *__0__X216 ;

# 4289 "/home/claude/cfront-3/src/template.cpp"
struct dcl_context *__0__X225 ;

# 4288 "/home/claude/cfront-3/src/template.cpp"
__1pc = __1templ_refs ;

# 4288 "/home/claude/cfront-3/src/template.cpp"
for(;__1pc ;__1pc = __1pc -> cdr__4cons ) { 
# 4289 "/home/claude/cfront-3/src/template.cpp"
instantiate__10templ_instF4bool ( ((struct templ_inst *)(((struct templ_inst *)__1pc -> car__4cons ))), 0) ;

# 4289 "/home/claude/cfront-3/src/template.cpp"
;
}

# 4292 "/home/claude/cfront-3/src/template.cpp"
if (__1reinstantiate && __0this -> tname__10basic_inst -> __O4__4expr.n_table )
# 4293 "/home/claude/cfront-3/src/template.cpp"
__0this -> tname__10basic_inst -> __O4__4expr.n_table = 0 ;

# 4295 "/home/claude/cfront-3/src/template.cpp"
if (fct_instantiation == 0 )
# 4296 "/home/claude/cfront-3/src/template.cpp"
fct_instantiation = __0this ;

# 4298 "/home/claude/cfront-3/src/template.cpp"
fcurr_inst = __0this ;

# 4300 "/home/claude/cfront-3/src/template.cpp"
( ( ( (cc ++ ), ( ((cc >= ccvec_end )?error__FiPCc ( (int )'i' , (const char *)"ccvec buffer overflow")
# 4300 "/home/claude/cfront-3/src/template.cpp"
:0 ), (((*cc ))= (*(cc - 1 )))) ) , (((void )0 ))) ) ;

# 4300 "/home/claude/cfront-3/src/template.cpp"
cc -> cot__11dcl_context = 0 ;

# 4300 "/home/claude/cfront-3/src/template.cpp"
cc -> not4__11dcl_context = 0 ;

# 4300 "/home/claude/cfront-3/src/template.cpp"
cc -> tot__11dcl_context = 0 ;

# 4300 "/home/claude/cfront-3/src/template.cpp"
cc -> c_this__11dcl_context = 0 ;
if ((! ((__0this -> tname__10basic_inst = dcl__4nameFP5tableUc ( __0this -> tname__10basic_inst , gtbl , (unsigned char )14 ) )== 0 ))|| error_count )
# 4302 "/home/claude/cfront-3/src/template.cpp"
{
# 4302 "/home/claude/cfront-3/src/template.cpp"

# 4303 "/home/claude/cfront-3/src/template.cpp"
fcurr_inst = __0this ;
if (se_opt && (finst_body__4nameFv ( __0this -> tname__10basic_inst ) == 0 ))
# 4305 "/home/claude/cfront-3/src/template.cpp"
suppress_error ++ ;
simpl__4nameFv ( __0this -> tname__10basic_inst ) ;
{ Ptype __2pt ;

# 4331 "/home/claude/cfront-3/src/template.cpp"
Pblock __2b ;

# 4332 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X217 ;

# 4332 "/home/claude/cfront-3/src/template.cpp"
register struct name *__0__X224 ;

# 4332 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 4332 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 4332 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 4307 "/home/claude/cfront-3/src/template.cpp"
__2pt = __0this -> tname__10basic_inst -> __O1__4expr.tp ;
if (__2pt -> base__4node != 108 )
# 4309 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4309 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V211 ;

# 4309 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"funct_inst::instantiate(%k),FX", (const struct ea *)( (__2__X217 =
# 4309 "/home/claude/cfront-3/src/template.cpp"
__2pt -> base__4node ), ( (( ((& __0__V211 )-> __O1__2ea.i = __2__X217 ), 0 ) ), (& __0__V211 )) ) ,
# 4309 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 , (const struct ea *)ea0 ) ;
} if ((fct_instantiation != __0this )&& (fct_instantiation -> namep__10basic_inst == __0this -> namep__10basic_inst ))
# 4311 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4313 "/home/claude/cfront-3/src/template.cpp"
Pfct __3f ;
Pblock __3b ;

# 4317 "/home/claude/cfront-3/src/template.cpp"
Pblock __3b1 ;

# 4318 "/home/claude/cfront-3/src/template.cpp"
register struct name *__0__X220 ;

# 4318 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 4318 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 4318 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 4318 "/home/claude/cfront-3/src/template.cpp"
register struct name *__0__X221 ;

# 4313 "/home/claude/cfront-3/src/template.cpp"
__3f = ( (__0__X221 = fct_instantiation -> tname__10basic_inst ), ( ((__0__X221 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X221 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 (
# 4313 "/home/claude/cfront-3/src/template.cpp"
(int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )->
# 4313 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.p = ((const void *)__0__X221 )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __0__X221 -> __O1__4expr.tp -> base__4node ),
# 4313 "/home/claude/cfront-3/src/template.cpp"
( (( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct
# 4313 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) ;
__3b = __3f -> body__3fct ;
__3f -> body__3fct = 0 ;
current_fct_instantiation = __3f ;
;
if (dtpt_opt && (finst_body__4nameFv ( __0this -> tname__10basic_inst ) == 0 ))
# 4319 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4319 "/home/claude/cfront-3/src/template.cpp"
register struct name *__0__X218 ;

# 4319 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 4319 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 4319 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 4319 "/home/claude/cfront-3/src/template.cpp"
register struct name *__0__X219 ;

# 4320 "/home/claude/cfront-3/src/template.cpp"
__3b1 = ( (__0__X218 = __0this -> tname__10basic_inst ), ( ((__0__X218 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X218 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 (
# 4320 "/home/claude/cfront-3/src/template.cpp"
(int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )->
# 4320 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.p = ((const void *)__0__X218 )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __0__X218 -> __O1__4expr.tp -> base__4node ),
# 4320 "/home/claude/cfront-3/src/template.cpp"
( (( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct
# 4320 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) -> body__3fct ;
( (__0__X219 = __0this -> tname__10basic_inst ), ( ((__0__X219 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X219 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int
# 4321 "/home/claude/cfront-3/src/template.cpp"
)'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p =
# 4321 "/home/claude/cfront-3/src/template.cpp"
((const void *)__0__X219 )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __0__X219 -> __O1__4expr.tp -> base__4node ), (
# 4321 "/home/claude/cfront-3/src/template.cpp"
(( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 ,
# 4321 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) -> body__3fct = 0 ;
}
dcl_print__4nameFUc ( fct_instantiation -> tname__10basic_inst , (unsigned char )0 ) ;
if (dtpt_opt && (finst_body__4nameFv ( __0this -> tname__10basic_inst ) == 0 ))
# 4325 "/home/claude/cfront-3/src/template.cpp"
( (__0__X220 = __0this -> tname__10basic_inst ), ( ((__0__X220 -> __O1__4expr.tp -> base__4node ==
# 4325 "/home/claude/cfront-3/src/template.cpp"
108 )?(((struct fct *)(((struct fct *)__0__X220 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF",
# 4325 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const void *)__0__X220 )), (& __0__X__V1400q2z144hdwckg )) , (const struct
# 4325 "/home/claude/cfront-3/src/template.cpp"
ea *)( (__2__X16 = __0__X220 -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (&
# 4325 "/home/claude/cfront-3/src/template.cpp"
__0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) )
# 4325 "/home/claude/cfront-3/src/template.cpp"
-> body__3fct = __3b1 ;
current_fct_instantiation = 0 ;
__3f -> body__3fct = __3b ;
}
current_fct_instantiation = (((struct fct *)(((struct fct *)__2pt ))));

# 4331 "/home/claude/cfront-3/src/template.cpp"
;

# 4334 "/home/claude/cfront-3/src/template.cpp"
if (se_opt && (finst_body__4nameFv ( __0this -> tname__10basic_inst ) == 0 ))
# 4335 "/home/claude/cfront-3/src/template.cpp"
suppress_error -- ;

# 4337 "/home/claude/cfront-3/src/template.cpp"
if (dtpt_opt && (finst_body__4nameFv ( __0this -> tname__10basic_inst ) == 0 )){ 
# 4337 "/home/claude/cfront-3/src/template.cpp"
register struct name *__0__X222 ;

# 4337 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 4337 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 4337 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 4337 "/home/claude/cfront-3/src/template.cpp"
register struct name *__0__X223 ;

# 4338 "/home/claude/cfront-3/src/template.cpp"
__2b = ( (__0__X222 = __0this -> tname__10basic_inst ), ( ((__0__X222 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X222 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 (
# 4338 "/home/claude/cfront-3/src/template.cpp"
(int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )->
# 4338 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.p = ((const void *)__0__X222 )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __0__X222 -> __O1__4expr.tp -> base__4node ),
# 4338 "/home/claude/cfront-3/src/template.cpp"
( (( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct
# 4338 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) -> body__3fct ;
( (__0__X223 = __0this -> tname__10basic_inst ), ( ((__0__X223 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X223 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int
# 4339 "/home/claude/cfront-3/src/template.cpp"
)'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p =
# 4339 "/home/claude/cfront-3/src/template.cpp"
((const void *)__0__X223 )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __0__X223 -> __O1__4expr.tp -> base__4node ), (
# 4339 "/home/claude/cfront-3/src/template.cpp"
(( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 ,
# 4339 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) -> body__3fct = 0 ;
}

# 4342 "/home/claude/cfront-3/src/template.cpp"
dcl_print__4nameFUc ( __0this -> tname__10basic_inst , (unsigned char )0 ) ;

# 4344 "/home/claude/cfront-3/src/template.cpp"
if (dtpt_opt && (finst_body__4nameFv ( __0this -> tname__10basic_inst ) == 0 ))
# 4345 "/home/claude/cfront-3/src/template.cpp"
( (__0__X224 = __0this -> tname__10basic_inst ), ( ((__0__X224 -> __O1__4expr.tp -> base__4node ==
# 4345 "/home/claude/cfront-3/src/template.cpp"
108 )?(((struct fct *)(((struct fct *)__0__X224 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"N::fct_type():%n is %k notF",
# 4345 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)( ((& __0__X__V1400q2z144hdwckg )-> __O1__2ea.p = ((const void *)__0__X224 )), (& __0__X__V1400q2z144hdwckg )) , (const struct
# 4345 "/home/claude/cfront-3/src/template.cpp"
ea *)( (__2__X16 = __0__X224 -> __O1__4expr.tp -> base__4node ), ( (( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (&
# 4345 "/home/claude/cfront-3/src/template.cpp"
__0__X__V1500q2z144hdwckg )) ) , (const struct ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) )
# 4345 "/home/claude/cfront-3/src/template.cpp"
-> body__3fct = __2b ;

# 4347 "/home/claude/cfront-3/src/template.cpp"
fcurr_inst = 0 ;
current_fct_instantiation = 0 ;

# 4348 "/home/claude/cfront-3/src/template.cpp"
}
}

# 4351 "/home/claude/cfront-3/src/template.cpp"
fcurr_inst = 0 ;
( ( (cc -- ), (((void )0 ))) ) ;

# 4354 "/home/claude/cfront-3/src/template.cpp"
restore_state__10basic_instFv ( (struct basic_inst *)__0this ) ;
__0this -> def__10funct_inst -> open_instantiations__14basic_template -- ;
if (fct_instantiation == __0this )
# 4357 "/home/claude/cfront-3/src/template.cpp"
fct_instantiation = 0 ;

# 4357 "/home/claude/cfront-3/src/template.cpp"
}

# 4357 "/home/claude/cfront-3/src/template.cpp"
}

# 4357 "/home/claude/cfront-3/src/template.cpp"
}
}

# 193 "/home/claude/cfront-3/src/template.h"

# 1260 "/home/claude/cfront-3/src/cfront.h"

# 4361 "/home/claude/cfront-3/src/template.cpp"
static int has_templ_arg__FP8classdefP14templ_classdefP5PslotRi (Pclass __1cl1 , Ptclass __1cl2 , Pbinding __1p , int *__1ni )
# 4362 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4367 "/home/claude/cfront-3/src/template.cpp"
Ptempl __1t ;

# 4367 "/home/claude/cfront-3/src/template.cpp"
__1t = is_template__17templ_compilationFPCc ( templp , __1cl1 -> string__8classdef ) ;
if (__1t == 0 ){ 
# 4368 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V226 ;

# 4368 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"has_templ_arg: unable to retrieveCY%t", (const struct ea *)( ((&
# 4368 "/home/claude/cfront-3/src/template.cpp"
__0__V226 )-> __O1__2ea.p = ((const void *)__1cl1 )), (& __0__V226 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 4368 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) ;
} 
# 4370 "/home/claude/cfront-3/src/template.cpp"
{ Plist __1formals ;
Pexpr __1actuals ;

# 4370 "/home/claude/cfront-3/src/template.cpp"
__1formals = ( ((struct basic_template *)__1t )-> formals__14basic_template ) ;
__1actuals = __1cl2 -> inst__14templ_classdef -> actuals__10basic_inst ;

# 4373 "/home/claude/cfront-3/src/template.cpp"
for(;__1formals && __1actuals ;( (__1formals = __1formals -> l__9name_list ), (__1actuals = __1actuals -> __O3__4expr.e2 )) ) 
# 4374 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4376 "/home/claude/cfront-3/src/template.cpp"
Ptype __2at ;

# 4376 "/home/claude/cfront-3/src/template.cpp"
__2at = __1actuals -> __O2__4expr.e1 -> __O1__4expr.tp ;
while (__2at -> base__4node == 97 )__2at = ( (((struct basetype *)(((struct basetype *)__2at ))))-> b_name__8basetype -> __O1__4expr.tp ) ;

# 4381 "/home/claude/cfront-3/src/template.cpp"
{ int __2i ;

# 4381 "/home/claude/cfront-3/src/template.cpp"
__2i = -1;
while ((++ __2i )< ((*__1ni ))){ 
# 4383 "/home/claude/cfront-3/src/template.cpp"
if ((__1p [__2i ]). param__5Pslot == __1formals -> f__9name_list )break ;
}

# 4386 "/home/claude/cfront-3/src/template.cpp"
if (__2i < ((*__1ni ))){ 
# 4387 "/home/claude/cfront-3/src/template.cpp"
if (check__4typeFP4typeUcT2 ( (__1p [__2i ]). typ__5Pslot , __2at , (unsigned char )0 , (unsigned char )0 )
# 4387 "/home/claude/cfront-3/src/template.cpp"
){ 
# 4388 "/home/claude/cfront-3/src/template.cpp"
if (! const_problem )
# 4389 "/home/claude/cfront-3/src/template.cpp"
return 0 ;
}
continue ;
}

# 4394 "/home/claude/cfront-3/src/template.cpp"
(__1p [((*__1ni ))]). param__5Pslot = __1formals -> f__9name_list ;
(__1p [(((*__1ni ))++ )]). typ__5Pslot = __2at ;

# 4395 "/home/claude/cfront-3/src/template.cpp"
}

# 4397 "/home/claude/cfront-3/src/template.cpp"
}

# 4399 "/home/claude/cfront-3/src/template.cpp"
return 1 ;

# 4399 "/home/claude/cfront-3/src/template.cpp"
}
}

# 1259 "/home/claude/cfront-3/src/cfront.h"

# 958 "/home/claude/cfront-3/src/cfront.h"

# 1260 "/home/claude/cfront-3/src/cfront.h"

# 4403 "/home/claude/cfront-3/src/template.cpp"
static int has_templ_arg__FP14templ_classdefT1P5PslotRi (Ptclass __1cl1 , Ptclass __1cl2 , Pbinding __1p , int *__1ni )
# 4404 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4407 "/home/claude/cfront-3/src/template.cpp"
Pexpr __1formals ;
Pexpr __1actuals ;

# 4407 "/home/claude/cfront-3/src/template.cpp"
__1formals = __1cl1 -> inst__14templ_classdef -> actuals__10basic_inst ;
__1actuals = __1cl2 -> inst__14templ_classdef -> actuals__10basic_inst ;

# 4410 "/home/claude/cfront-3/src/template.cpp"
for(;__1formals && __1actuals ;( (__1formals = __1formals -> __O3__4expr.e2 ), (__1actuals = __1actuals -> __O3__4expr.e2 )) ) 
# 4411 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4413 "/home/claude/cfront-3/src/template.cpp"
Pexpr __2fe ;

# 4413 "/home/claude/cfront-3/src/template.cpp"
__2fe = __1formals -> __O2__4expr.e1 ;
if ((__2fe -> base__4node != 85 )|| (__2fe -> __O1__4expr.tp -> base__4node != 97 ))continue ;
{ Pname __2ftn ;

# 4416 "/home/claude/cfront-3/src/template.cpp"
struct type *__0__X227 ;

# 4415 "/home/claude/cfront-3/src/template.cpp"
__2ftn = ( (__0__X227 = __2fe -> __O1__4expr.tp ), ( (((struct basetype *)(((struct basetype *)__0__X227 ))))-> b_name__8basetype ) ) ;
if (! ( (((unsigned char )(__2ftn -> n_template_arg__4name == 1)))) )continue ;

# 4419 "/home/claude/cfront-3/src/template.cpp"
{ Ptype __2at ;

# 4419 "/home/claude/cfront-3/src/template.cpp"
__2at = __1actuals -> __O2__4expr.e1 -> __O1__4expr.tp ;
while (__2at -> base__4node == 97 )__2at = ( (((struct basetype *)(((struct basetype *)__2at ))))-> b_name__8basetype -> __O1__4expr.tp ) ;

# 4424 "/home/claude/cfront-3/src/template.cpp"
{ int __2i ;

# 4424 "/home/claude/cfront-3/src/template.cpp"
__2i = -1;
while ((++ __2i )< ((*__1ni ))){ 
# 4426 "/home/claude/cfront-3/src/template.cpp"
if ((__1p [__2i ]). param__5Pslot == __2ftn )break ;
}

# 4429 "/home/claude/cfront-3/src/template.cpp"
if (__2i < ((*__1ni ))){ 
# 4430 "/home/claude/cfront-3/src/template.cpp"
if (check__4typeFP4typeUcT2 ( (__1p [__2i ]). typ__5Pslot , __2at , (unsigned char )0 , (unsigned char )0 )
# 4430 "/home/claude/cfront-3/src/template.cpp"
){ 
# 4431 "/home/claude/cfront-3/src/template.cpp"
if (! const_problem )
# 4432 "/home/claude/cfront-3/src/template.cpp"
return 0 ;
}
continue ;
}

# 4437 "/home/claude/cfront-3/src/template.cpp"
(__1p [((*__1ni ))]). param__5Pslot = __2ftn ;
(__1p [(((*__1ni ))++ )]). typ__5Pslot = __2at ;

# 4438 "/home/claude/cfront-3/src/template.cpp"
}

# 4438 "/home/claude/cfront-3/src/template.cpp"
}

# 4438 "/home/claude/cfront-3/src/template.cpp"
}

# 4440 "/home/claude/cfront-3/src/template.cpp"
}

# 4442 "/home/claude/cfront-3/src/template.cpp"
return 1 ;
}

# 347 "/home/claude/cfront-3/src/cfront.h"
bit tconst__4typeFv (struct type *__0this );

# 4446 "/home/claude/cfront-3/src/template.cpp"
static bit formal_not_const__FP4name (Pname __1nn )
# 4450 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4453 "/home/claude/cfront-3/src/template.cpp"
Ptype __1t ;
bit __1cnst ;

# 4453 "/home/claude/cfront-3/src/template.cpp"
__1t = __1nn -> __O1__4expr.tp ;
__1cnst = tconst__4typeFv ( __1t ) ;

# 4456 "/home/claude/cfront-3/src/template.cpp"
loop :
# 4457 "/home/claude/cfront-3/src/template.cpp"
if (__1cnst == 0 )
# 4459 "/home/claude/cfront-3/src/template.cpp"
if ((__1t -> base__4node == 125 )|| (__1t -> base__4node == 158 )){ 
# 4460 "/home/claude/cfront-3/src/template.cpp"
__1t = (((struct ptr *)(((struct ptr *)__1t ))))-> typ__5pvtyp ;
# 4460 "/home/claude/cfront-3/src/template.cpp"

# 4461 "/home/claude/cfront-3/src/template.cpp"
__1cnst = tconst__4typeFv ( __1t ) ;
goto loop ;
}
return (unsigned char )(__1cnst == 0 );
}

# 4468 "/home/claude/cfront-3/src/template.cpp"
static void check_valid_formal_type__FP4type (Ptype __1et ){ 
# 4469 "/home/claude/cfront-3/src/template.cpp"
__1et = skiptypedefs__4typeFv ( __1et ) ;
switch (__1et -> base__4node ){ 
# 4471 "/home/claude/cfront-3/src/template.cpp"
case 114 :
# 4472 "/home/claude/cfront-3/src/template.cpp"
error__FiPCc ( (int )'s' , (const char *)"formalYZ of type bit field")
# 4472 "/home/claude/cfront-3/src/template.cpp"
;
break ;
case 38 :
# 4475 "/home/claude/cfront-3/src/template.cpp"
error__FPCc ( (const char *)"formalYZ of type void illegal") ;
break ;
}
}

# 1274 "/home/claude/cfront-3/src/cfront.h"

# 1259 "/home/claude/cfront-3/src/cfront.h"

# 958 "/home/claude/cfront-3/src/cfront.h"

# 1260 "/home/claude/cfront-3/src/cfront.h"

# 493 "/home/claude/cfront-3/src/cfront.h"

# 463 "/home/claude/cfront-3/src/cfront.h"
Pclass is_base__8classdefFPCcPUci (struct classdef *__0this , const char *, TOK *, int __1level );

# 4481 "/home/claude/cfront-3/src/template.cpp"
struct Pslot *is_ftempl_match__FP4exprP17function_template (Pexpr __1actuals , Pfunt __1ft )
# 4482 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4484 "/home/claude/cfront-3/src/template.cpp"
int __1count ;
struct Pslot *__1parray ;
int __1ni ;

# 4488 "/home/claude/cfront-3/src/template.cpp"
Pfct __1f ;
Pexpr __1e ;
Pname __1nn ;

# 4491 "/home/claude/cfront-3/src/template.cpp"
register struct name *__0__X232 ;

# 4491 "/home/claude/cfront-3/src/template.cpp"
unsigned long __2__X16 ;

# 4491 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1400q2z144hdwckg ;

# 4491 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__X__V1500q2z144hdwckg ;

# 4484 "/home/claude/cfront-3/src/template.cpp"
__1count = get_formals_count__14basic_templateFv ( (struct basic_template *)__1ft ) ;
__1parray = (((struct Pslot *)__nw__FUl ( (size_t)((sizeof (struct Pslot ))* __1count )) ));
__1ni = 0 ;

# 4488 "/home/claude/cfront-3/src/template.cpp"
__1f = ( (__0__X232 = __1ft -> fn__17function_template ), ( ((__0__X232 -> __O1__4expr.tp -> base__4node == 108 )?(((struct fct *)(((struct fct *)__0__X232 -> __O1__4expr.tp )))):( error__FiPCcRC2eaN33 (
# 4488 "/home/claude/cfront-3/src/template.cpp"
(int )'i' , (const char *)"N::fct_type():%n is %k notF", (const struct ea *)( ((& __0__X__V1400q2z144hdwckg )->
# 4488 "/home/claude/cfront-3/src/template.cpp"
__O1__2ea.p = ((const void *)__0__X232 )), (& __0__X__V1400q2z144hdwckg )) , (const struct ea *)( (__2__X16 = __0__X232 -> __O1__4expr.tp -> base__4node ),
# 4488 "/home/claude/cfront-3/src/template.cpp"
( (( ((& __0__X__V1500q2z144hdwckg )-> __O1__2ea.i = __2__X16 ), 0 ) ), (& __0__X__V1500q2z144hdwckg )) ) , (const struct
# 4488 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 , (const struct ea *)ea0 ) , (((struct fct *)0 ))) )) ) ;
__1e = __1actuals ;
__1nn = __1f -> argtype__3fct ;

# 4494 "/home/claude/cfront-3/src/template.cpp"
for(;__1e ;( (__1e = __1e -> __O3__4expr.e2 ), (__1nn = __1nn -> __O1__4name.n_list )) ) { 
# 4495 "/home/claude/cfront-3/src/template.cpp"
if (__1nn == 0 ){ 
# 4496 "/home/claude/cfront-3/src/template.cpp"
if (__1f ->
# 4496 "/home/claude/cfront-3/src/template.cpp"
nargs_known__3fct == 155 )
# 4497 "/home/claude/cfront-3/src/template.cpp"
{ return __1parray ;

# 4497 "/home/claude/cfront-3/src/template.cpp"
}
__dl__FPv ( (void *)__1parray ) ;
return (struct Pslot *)0 ;
}

# 4502 "/home/claude/cfront-3/src/template.cpp"
{ Pexpr __2a ;
Ptype __2et ;

# 4502 "/home/claude/cfront-3/src/template.cpp"
__2a = __1e -> __O2__4expr.e1 ;
__2et = __2a -> __O1__4expr.tp ;

# 4505 "/home/claude/cfront-3/src/template.cpp"
check_valid_formal_type__FP4type ( __2et ) ;

# 4507 "/home/claude/cfront-3/src/template.cpp"
{ Ptype __2t ;

# 4507 "/home/claude/cfront-3/src/template.cpp"
__2t = __1nn -> __O1__4expr.tp ;
if (is_ref__4typeFv ( __2t ) ){ 
# 4509 "/home/claude/cfront-3/src/template.cpp"
__2t = (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv ( __2t ) ))))-> typ__5pvtyp ;
if (is_ref__4typeFv ( __2et ) )
# 4511 "/home/claude/cfront-3/src/template.cpp"
__2et = (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv ( __2et ) ))))-> typ__5pvtyp ;
}

# 4514 "/home/claude/cfront-3/src/template.cpp"
if (check__4typeFP4typeUcT2 ( __2t , __2et , (unsigned char )76 , (unsigned char )0 ) ){ 
# 4515 "/home/claude/cfront-3/src/template.cpp"
if (const_problem ){ 
# 4518 "/home/claude/cfront-3/src/template.cpp"
if
# 4518 "/home/claude/cfront-3/src/template.cpp"
(((is_ptr_or_ref__4typeFv ( __2t ) != 0 )&& (is_ptr_or_ref__4typeFv ( __2et ) != 0 ))&& formal_not_const__FP4name ( __1nn ) )
# 4521 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4522 "/home/claude/cfront-3/src/template.cpp"
__dl__FPv ( (void *)__1parray )
# 4522 "/home/claude/cfront-3/src/template.cpp"
;
return (struct Pslot *)0 ;
}
}
else 
# 4525 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4526 "/home/claude/cfront-3/src/template.cpp"
__dl__FPv ( (void *)__1parray ) ;
return (struct Pslot *)0 ;
}
}

# 4533 "/home/claude/cfront-3/src/template.cpp"
{ int __2ptr_count ;

# 4533 "/home/claude/cfront-3/src/template.cpp"
int __2ref_count ;
Ptype __2nt ;
Pname __2ptm ;

# 4533 "/home/claude/cfront-3/src/template.cpp"
__2ptr_count = 0 ;

# 4533 "/home/claude/cfront-3/src/template.cpp"
__2ref_count = 0 ;
__2nt = __1nn -> __O1__4expr.tp ;
__2ptm = 0 ;

# 4537 "/home/claude/cfront-3/src/template.cpp"
if (is_ref__4typeFv ( __2nt ) ){ 
# 4538 "/home/claude/cfront-3/src/template.cpp"
__2nt = (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv ( __2nt ) ))))-> typ__5pvtyp ;
}
while (__2t = (struct type *)is_ptr__4typeFv ( __2nt ) ){ 
# 4541 "/home/claude/cfront-3/src/template.cpp"
++ __2ptr_count ;
{ Pptr __3p ;

# 4542 "/home/claude/cfront-3/src/template.cpp"
__3p = (((struct ptr *)(((struct ptr *)__2t ))));
if (__3p -> ptname__3ptr ){ __2ptm = __3p -> ptname__3ptr ;

# 4543 "/home/claude/cfront-3/src/template.cpp"
break ;

# 4543 "/home/claude/cfront-3/src/template.cpp"
}
__2nt = (((struct ptr *)(((struct ptr *)__2t ))))-> typ__5pvtyp ;

# 4544 "/home/claude/cfront-3/src/template.cpp"
}
}

# 4547 "/home/claude/cfront-3/src/template.cpp"
while ((__2ptr_count -- )&& (__2t = (struct type *)is_ptr__4typeFv ( __2et ) )){ 
# 4548 "/home/claude/cfront-3/src/template.cpp"
Pptr __3p ;

# 4548 "/home/claude/cfront-3/src/template.cpp"
__3p = (((struct ptr *)(((struct ptr *)__2t ))));
if (__3p -> memof__3ptr ){ __2et = (struct type *)__3p -> memof__3ptr ;

# 4549 "/home/claude/cfront-3/src/template.cpp"
break ;

# 4549 "/home/claude/cfront-3/src/template.cpp"
}
__2et = (((struct ptr *)(((struct ptr *)__2t ))))-> typ__5pvtyp ;
}

# 4553 "/home/claude/cfront-3/src/template.cpp"
{ Pname __2bn ;

# 4553 "/home/claude/cfront-3/src/template.cpp"
__2bn = __2ptm ;
if (__2bn == 0 ){ 
# 4555 "/home/claude/cfront-3/src/template.cpp"
while (__2t = (struct type *)is_ref__4typeFv ( __2nt ) ){ ++ __2ref_count ;

# 4555 "/home/claude/cfront-3/src/template.cpp"
__2nt = (((struct ptr *)(((struct ptr *)__2t ))))-> typ__5pvtyp ;

# 4555 "/home/claude/cfront-3/src/template.cpp"
}
while ((__2ref_count -- )&& (__2t = (struct type *)is_ref__4typeFv ( __2et ) ))__2et = (((struct ptr *)(((struct ptr *)__2t ))))-> typ__5pvtyp ;

# 4558 "/home/claude/cfront-3/src/template.cpp"
if (__2nt -> base__4node != 97 )continue ;
while (__2nt -> base__4node == 97 ){ 
# 4560 "/home/claude/cfront-3/src/template.cpp"
__2bn = ( (((struct basetype *)(((struct basetype *)__2nt ))))-> b_name__8basetype ) ;
if (( (((unsigned char )(__2bn -> n_template_arg__4name == 1)))) )
# 4562 "/home/claude/cfront-3/src/template.cpp"
break ;
else __2bn = 0 ;
__2nt = ( (((struct basetype *)(((struct basetype *)__2nt ))))-> b_name__8basetype -> __O1__4expr.tp ) ;
}
}

# 4568 "/home/claude/cfront-3/src/template.cpp"
while (__2et -> base__4node == 97 )__2et = ( (((struct basetype *)(((struct basetype *)__2et ))))-> b_name__8basetype -> __O1__4expr.tp ) ;
if (__2bn == 0 ){ 
# 4570 "/home/claude/cfront-3/src/template.cpp"
if ((__2nt -> base__4node == 119 )&& (__2et -> base__4node == 119 ))
# 4571 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4572 "/home/claude/cfront-3/src/template.cpp"
Pclass __4c1 ;
Pclass __4c2 ;

# 4572 "/home/claude/cfront-3/src/template.cpp"
__4c1 = classtype__4typeFv ( __2nt ) ;
__4c2 = classtype__4typeFv ( __2et ) ;

# 4576 "/home/claude/cfront-3/src/template.cpp"
if (! __4c1 -> class_base__8classdef )continue ;

# 4581 "/home/claude/cfront-3/src/template.cpp"
if (__4c1 -> class_base__8classdef == 2){ 
# 4581 "/home/claude/cfront-3/src/template.cpp"
struct classdef *__1__X229 ;

# 4581 "/home/claude/cfront-3/src/template.cpp"
struct classdef *__1__X230 ;

# 4582 "/home/claude/cfront-3/src/template.cpp"
if ((( (__1__X229 = __4c1 ), ( (__1__X230 = __4c2 ), ( ((__1__X229 == __1__X230 )?1 :((__1__X229 && __1__X230 )?(((int )same_class__8classdefFP8classdefi ( __1__X229 , __1__X230 ,
# 4582 "/home/claude/cfront-3/src/template.cpp"
1 ) )):0 ))) ) ) == 0 )&& (is_base__8classdefFPCcPUci ( __4c2 , __4c1 -> string__8classdef , (TOK *)0 , 0 ) == 0 ))
# 4583 "/home/claude/cfront-3/src/template.cpp"
continue
# 4583 "/home/claude/cfront-3/src/template.cpp"
;
}
else if ((same_class_templ__FP8classdefT1 ( __4c1 , __4c2 ) == 0 )&& ((__4c2 = is_base__8classdefFPCcPUci ( __4c2 , __4c1 -> string__8classdef , (TOK *)0 , 0 )
# 4585 "/home/claude/cfront-3/src/template.cpp"
)== 0 ))
# 4586 "/home/claude/cfront-3/src/template.cpp"
continue ;

# 4590 "/home/claude/cfront-3/src/template.cpp"
{ int __4bound_formals ;

# 4590 "/home/claude/cfront-3/src/template.cpp"
__4bound_formals = 0 ;
if (__4c1 -> class_base__8classdef == 2)
# 4592 "/home/claude/cfront-3/src/template.cpp"
__4bound_formals = has_templ_arg__FP8classdefP14templ_classdefP5PslotRi ( __4c1 , ((struct templ_classdef *)(((struct templ_classdef *)__4c2 ))), __1parray , (int *)(& __1ni )) ;
# 4592 "/home/claude/cfront-3/src/template.cpp"
else 
# 4593 "/home/claude/cfront-3/src/template.cpp"
__4bound_formals = has_templ_arg__FP14templ_classdefT1P5PslotRi ( ((struct templ_classdef *)(((struct templ_classdef *)__4c1 ))), ((struct templ_classdef *)(((struct templ_classdef *)__4c2 ))), __1parray , (int *)(& __1ni )) ;
# 4593 "/home/claude/cfront-3/src/template.cpp"

# 4595 "/home/claude/cfront-3/src/template.cpp"
if (! __4bound_formals ){ __dl__FPv ( (void *)__1parray ) ;

# 4595 "/home/claude/cfront-3/src/template.cpp"
return (struct Pslot *)0 ;

# 4595 "/home/claude/cfront-3/src/template.cpp"
}
continue ;

# 4596 "/home/claude/cfront-3/src/template.cpp"
}
}
else continue ;
}

# 4601 "/home/claude/cfront-3/src/template.cpp"
{ Pptr __2p ;

# 4601 "/home/claude/cfront-3/src/template.cpp"
__2p = 0 ;
if ((__2et -> base__4node == 125 )&& ((((struct ptr *)(((struct ptr *)__2et ))))-> typ__5pvtyp -> base__4node == 108 )){ 
# 4603 "/home/claude/cfront-3/src/template.cpp"
Pfct __3f ;

# 4603 "/home/claude/cfront-3/src/template.cpp"
__3f = (((struct fct *)(((struct fct *)(((struct ptr *)(((struct ptr *)__2et ))))-> typ__5pvtyp ))));
if (__3f -> fct_base__3fct == 1){ 
# 4604 "/home/claude/cfront-3/src/template.cpp"
const void *__2__X231 ;

# 4605 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4605 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V228 ;

# 4605 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"actual argument toFY%n is an uninstantiatedFY", (const struct ea *)( (__2__X231 = (const void
# 4605 "/home/claude/cfront-3/src/template.cpp"
*)__1ft -> fn__17function_template ), ( ((& __0__V228 )-> __O1__2ea.p = __2__X231 ), (& __0__V228 )) ) , (const struct ea *)ea0 ,
# 4605 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 , (const struct ea *)ea0 ) ;
__dl__FPv ( (void *)__1parray ) ;
return (struct Pslot *)0 ;
} }

# 4610 "/home/claude/cfront-3/src/template.cpp"
if (__3f -> body__3fct ){ 
# 4611 "/home/claude/cfront-3/src/template.cpp"
Pfct __4ff ;

# 4611 "/home/claude/cfront-3/src/template.cpp"
__4ff = __ct__3fctFP4typeP4nameUc ( (struct fct *)0 , (struct type *)0 , (struct name *)0 , (unsigned char )0 ) ;
((*__4ff ))= (*__3f );
__4ff -> body__3fct = 0 ;
__2p = __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (struct type *)__4ff ) ;
__2p -> memof__3ptr = (((struct ptr *)(((struct ptr *)__2et ))))-> memof__3ptr ;
__2p -> ptname__3ptr = (((struct ptr *)(((struct ptr *)__2et ))))-> ptname__3ptr ;
}
}
if (__2et -> base__4node == 110 )__2p = __ct__3ptrFUcP4type ( (struct ptr *)0 , (unsigned char )125 , (((struct vec *)(((struct vec *)__2et ))))-> typ__5pvtyp )
# 4619 "/home/claude/cfront-3/src/template.cpp"
;

# 4621 "/home/claude/cfront-3/src/template.cpp"
{ int __2i ;

# 4621 "/home/claude/cfront-3/src/template.cpp"
__2i = -1;
while ((++ __2i )< __1ni ){ 
# 4623 "/home/claude/cfront-3/src/template.cpp"
if ((__1parray [__2i ]). param__5Pslot == __2bn )break ;
}

# 4626 "/home/claude/cfront-3/src/template.cpp"
if (__2i < __1ni ){ 
# 4627 "/home/claude/cfront-3/src/template.cpp"
if (check__4typeFP4typeUcT2 ( (__1parray [__2i ]). typ__5Pslot , (__2p == 0 )?__2et :(((struct type *)__2p )), (unsigned char )0 , (unsigned
# 4627 "/home/claude/cfront-3/src/template.cpp"
char )0 ) ){ 
# 4628 "/home/claude/cfront-3/src/template.cpp"
if (const_problem )
# 4629 "/home/claude/cfront-3/src/template.cpp"
continue ;

# 4631 "/home/claude/cfront-3/src/template.cpp"
__dl__FPv ( (void *)__1parray ) ;
return (struct Pslot *)0 ;
}
continue ;
}

# 4637 "/home/claude/cfront-3/src/template.cpp"
if (__2et -> base__4node == 76 ){ 
# 4638 "/home/claude/cfront-3/src/template.cpp"
__dl__FPv ( (void *)__1parray ) ;
return (struct Pslot *)0 ;
}

# 4642 "/home/claude/cfront-3/src/template.cpp"
(__1parray [__1ni ]). param__5Pslot = __2bn ;
(__1parray [(__1ni ++ )]). typ__5Pslot = ((__2p == 0 )?__2et :(((struct type *)__2p )));

# 4643 "/home/claude/cfront-3/src/template.cpp"
}

# 4643 "/home/claude/cfront-3/src/template.cpp"
}

# 4643 "/home/claude/cfront-3/src/template.cpp"
}

# 4643 "/home/claude/cfront-3/src/template.cpp"
}

# 4643 "/home/claude/cfront-3/src/template.cpp"
}

# 4643 "/home/claude/cfront-3/src/template.cpp"
}
}
if (__1nn && (! __1nn -> __O3__4expr.n_initializer )){ 
# 4646 "/home/claude/cfront-3/src/template.cpp"
__dl__FPv ( (void *)__1parray ) ;
return (struct Pslot *)0 ;
}
if (__1ni < __1count )return (struct Pslot *)0 ;
return __1parray ;
}

# 952 "/home/claude/cfront-3/src/cfront.h"

# 326 "/home/claude/cfront-3/src/template.h"

# 4654 "/home/claude/cfront-3/src/template.cpp"
Pname has_templ_instance__FP4nameP4exprUc (Pname __1fn , Pexpr __1arg , bit __1no_err )
# 4655 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4662 "/home/claude/cfront-3/src/template.cpp"
if (( __1fn -> n_template_fct__4name ) == 0 )return (struct name *)0 ;

# 4664 "/home/claude/cfront-3/src/template.cpp"
{ Pfunt __1ft ;

# 4664 "/home/claude/cfront-3/src/template.cpp"
__1ft = is_template__17templ_compilationFPCcUc ( templp , __1fn -> __O2__4expr.string , (unsigned char )108 ) ;
if (__1ft == 0 )
# 4666 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4666 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V233 ;

# 4666 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%n flagged asYF but not entered inY table", (const struct ea *)( ((&
# 4666 "/home/claude/cfront-3/src/template.cpp"
__0__V233 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V233 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 4666 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) ;
} 
# 4668 "/home/claude/cfront-3/src/template.cpp"
if (__1ft -> gen_list__17function_template && (__1fn -> __O1__4expr.tp -> base__4node != 76 ))
# 4669 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4669 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V234 ;

# 4669 "/home/claude/cfront-3/src/template.cpp"
error__FiPCcRC2eaN33 ( (int )'i' , (const char *)"%n gtbl: non-overloaded,Y table: overloaded", (const struct ea *)( ((&
# 4669 "/home/claude/cfront-3/src/template.cpp"
__0__V234 )-> __O1__2ea.p = ((const void *)__1fn )), (& __0__V234 )) , (const struct ea *)ea0 , (const struct ea *)ea0 ,
# 4669 "/home/claude/cfront-3/src/template.cpp"
(const struct ea *)ea0 ) ;
} 
# 4671 "/home/claude/cfront-3/src/template.cpp"
{ Pbinding __1pb ;
Pfunt __1instance ;

# 4674 "/home/claude/cfront-3/src/template.cpp"
bit __1used_conv ;
int __1conv_reqd ;
int __1no_conv_reqd ;

# 4671 "/home/claude/cfront-3/src/template.cpp"
__1pb = 0 ;
__1instance = 0 ;

# 4674 "/home/claude/cfront-3/src/template.cpp"
__1used_conv = 0 ;
__1conv_reqd = 0 ;
__1no_conv_reqd = 0 ;

# 4678 "/home/claude/cfront-3/src/template.cpp"
{ { Pfunt __1p ;

# 4678 "/home/claude/cfront-3/src/template.cpp"
__1p = __1ft ;

# 4678 "/home/claude/cfront-3/src/template.cpp"
for(;__1p ;__1p = __1p -> gen_list__17function_template ) { 
# 4679 "/home/claude/cfront-3/src/template.cpp"
Pbinding __2b ;
template_hier = 1 ;
Nvirt = 0 ;

# 4683 "/home/claude/cfront-3/src/template.cpp"
if (__2b = is_ftempl_match__FP4exprP17function_template ( __1arg , __1p ) ){ 
# 4684 "/home/claude/cfront-3/src/template.cpp"
if (! __1instance )
# 4685 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4686 "/home/claude/cfront-3/src/template.cpp"
__1pb = __2b ;
__1instance = __1p ;
__1used_conv = ((Nvirt == 0 )?0 :1 );
}
else 
# 4691 "/home/claude/cfront-3/src/template.cpp"
if (__1used_conv && (Nvirt == 0 ))
# 4692 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4693 "/home/claude/cfront-3/src/template.cpp"
__1pb = __2b ;
__1instance = __1p ;
__1used_conv = 0 ;
}
(Nvirt == 0 )?(__1no_conv_reqd ++ ):(__1conv_reqd ++ );
}
}

# 4701 "/home/claude/cfront-3/src/template.cpp"
if (! __1instance ){ 
# 4702 "/home/claude/cfront-3/src/template.cpp"
if ((__1fn -> __O1__4expr.tp -> base__4node == 108 )&& (! __1no_err )){ 
# 4703 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4703 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V235 ;

# 4703 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"use ofYF%n does not match any of itsY definitions", (const struct ea *)( ((& __0__V235 )-> __O1__2ea.p =
# 4703 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1fn )), (& __0__V235 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 4703 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
} }
template_hier = 0 ;
return (struct name *)0 ;
}
else if ((__1no_conv_reqd > 1 )|| ((__1no_conv_reqd == 0 )&& (__1conv_reqd > 1 )))
# 4709 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4710 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4710 "/home/claude/cfront-3/src/template.cpp"
struct ea __0__V236 ;

# 4710 "/home/claude/cfront-3/src/template.cpp"
error__FPCcRC2eaN32 ( (const char *)"use ofYF%n matches multiple instances", (const struct ea *)( ((& __0__V236 )-> __O1__2ea.p =
# 4710 "/home/claude/cfront-3/src/template.cpp"
((const void *)__1fn )), (& __0__V236 )) , (const struct ea *)ea0 , (const struct ea *)ea0 , (const struct
# 4710 "/home/claude/cfront-3/src/template.cpp"
ea *)ea0 ) ;
} 
# 4712 "/home/claude/cfront-3/src/template.cpp"
}

# 4717 "/home/claude/cfront-3/src/template.cpp"
template_hier = __1conv_reqd ;
{ Pfunct_inst __1fctmpl ;

# 4718 "/home/claude/cfront-3/src/template.cpp"
__1fctmpl = get_inst__17function_templateFP4exprP10funct_inst ( __1instance , __1arg , (struct funct_inst *)0 ) ;
template_hier = 0 ;
__1fctmpl -> binding__10funct_inst = __1pb ;
instantiate__10funct_instF4bool ( __1fctmpl , 0) ;
{ Pname __1fct_inst ;

# 4722 "/home/claude/cfront-3/src/template.cpp"
__1fct_inst = ( ((struct basic_inst *)__1fctmpl )-> tname__10basic_inst ) ;

# 4725 "/home/claude/cfront-3/src/template.cpp"
return __1fct_inst ;

# 4725 "/home/claude/cfront-3/src/template.cpp"
}

# 4725 "/home/claude/cfront-3/src/template.cpp"
}

# 4725 "/home/claude/cfront-3/src/template.cpp"
}

# 4725 "/home/claude/cfront-3/src/template.cpp"
}

# 4725 "/home/claude/cfront-3/src/template.cpp"
}

# 4725 "/home/claude/cfront-3/src/template.cpp"
}
}

# 101 "/home/claude/incl-linux32/stdio.h"
extern void abort (void );

# 4728 "/home/claude/cfront-3/src/template.cpp"
void dummy__14basic_templateFv (struct basic_template *__0this )
# 4729 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4730 "/home/claude/cfront-3/src/template.cpp"
abort ( ) ;
}

# 4733 "/home/claude/cfront-3/src/template.cpp"
void dummy__10basic_instFv (struct basic_inst *__0this )
# 4734 "/home/claude/cfront-3/src/template.cpp"
{ 
# 4735 "/home/claude/cfront-3/src/template.cpp"
abort ( ) ;
}
extern struct __mptr __vtbl__17function_template[];
extern struct __mptr __vtbl__13data_template[];
extern struct __mptr __vtbl__5templ[];
struct __mptr __vtbl__10funct_inst[] = {0,0,0,
0,0,(__vptp)dummy__10basic_instFv ,
0,0,(__vptp)print_pretty_name__10funct_instFv ,
0,0,(__vptp)mangled_name__10funct_instFPc ,
0,0,0};
struct __mptr __vtbl__10templ_inst[] = {0,0,0,
0,0,(__vptp)dummy__10basic_instFv ,
0,0,(__vptp)print_pretty_name__10templ_instFv ,
0,0,(__vptp)mangled_name__10templ_instFPc ,
0,0,0};
char __pure_virtual_called();
struct __mptr __vtbl__10basic_inst[] = {0,0,0,
0,0,(__vptp)dummy__10basic_instFv ,
0,0,(__vptp)__pure_virtual_called,
0,0,(__vptp)__pure_virtual_called,
0,0,0};
struct __mptr __vtbl__14basic_template[] = {0,0,0,
0,0,(__vptp)dummy__14basic_templateFv ,
0,0,(__vptp)__pure_virtual_called,
0,0,0};

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

# 198 "/home/claude/cfront-3/src/template.h"

# 92 "/home/claude/cfront-3/src/template.h"

# 404 "/home/claude/cfront-3/src/cfront.h"

# 92 "/home/claude/cfront-3/src/template.h"

# 115 "/home/claude/cfront-3/src/template.h"
int parameters_in_progress__17templ_compilation ;

# 109 "/home/claude/cfront-3/src/template.h"
int in_progress__17templ_compilation ;

# 107 "/home/claude/cfront-3/src/tree_walk.h"
struct Hash *ht__10patch_tree ;

# 106 "/home/claude/cfront-3/src/tree_walk.h"
Ppatch_tree head__10patch_tree ;

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
struct __mptr* __ptbl_vec___[] = {
__vtbl__14basic_template,
__vtbl__5templ,
__vtbl__10basic_inst,
__vtbl__10templ_inst,
__vtbl__10funct_inst,
__vtbl__13data_template,
__vtbl__17function_template,

};

# 4736 "/home/claude/cfront-3/src/template.cpp"

/* the end */
