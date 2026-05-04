
/* <<AT&T C++ Language System <3.0.3> 05/05/94>> pragma*/

typedef long ssize_t;
typedef unsigned long size_t;

typedef void (*Error_Proc)(const char *);

typedef void (*intProc)(int);
struct HashTableEntry;
struct HashWalker;
struct Hash;
enum __Q2_4Hash13insert_action {
    probe__Q2_4Hash13insert_action = 0,
    insert__Q2_4Hash13insert_action = 1,
    replace__Q2_4Hash13insert_action = 2
};

struct Hash { /* sizeof Hash == 32 */

    struct HashTableEntry *tab__4Hash;
    int size__4Hash;
    int entry_count__4Hash;

    size_t (*key_hash_function__4Hash)(size_t);
    int (*key_key_equality_function__4Hash)(size_t, size_t);
};

extern void __dl__FPv(void *);

struct HashWalker { /* sizeof HashWalker == 16 */
    struct Hash *h__10HashWalker;
    int pos__10HashWalker;
};

void reset__10HashWalkerFv(struct HashWalker *__0this);

extern void *__nw__FUl(size_t);

void error__4HashFPCc(struct Hash *__0this, const char *__1msg);

struct HashTableEntry { /* sizeof HashTableEntry == 12 */
    int key__14HashTableEntry;
    int cont__14HashTableEntry;
    char status__14HashTableEntry;
};
struct pointer_hash;

struct Hash *__ct__4HashFi(struct Hash *__0this, int __1sz);

struct pointer_hash { /* sizeof pointer_hash == 32 */

    struct HashTableEntry *tab__4Hash;
    int size__4Hash;
    int entry_count__4Hash;

    size_t (*key_hash_function__4Hash)(size_t);
    int (*key_key_equality_function__4Hash)(size_t, size_t);
};

extern size_t pointer_hash_fcn__FUl(size_t);

extern int pointer_hasheq__FUlT1(size_t, size_t);

struct Hash *__ct__4HashFR4Hash(struct Hash *__0this, struct Hash *__1a);

struct string_hash;

struct string_hash { /* sizeof string_hash == 32 */

    struct HashTableEntry *tab__4Hash;
    int size__4Hash;
    int entry_count__4Hash;

    size_t (*key_hash_function__4Hash)(size_t);
    int (*key_key_equality_function__4Hash)(size_t, size_t);
};

extern size_t string_hash_fcn__FUl(size_t);

extern int string_hasheq__FUlT1(size_t, size_t);

typedef char *va_list;

extern char *sys_errlist[];
extern int sys_nerr;
extern unsigned char *_bufendtab[];

extern const char *keys[256];

#include "cfront_translated.h"

struct node { /* sizeof node == 3 */
    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;
};

void *__nw__5tableSFUl(size_t);
void __dl__5tableSFPvUl(void *, size_t);

struct table { /* sizeof table == 56 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit init_stat__5table;

    TOK t_realbase__5table;
    short size__5table;
    short hashsize__5table;
    short free_slot__5table;
    Pname *entries__5table;
    short *hashtbl__5table;
    Pstmt real_block__5table;

    Ptable next__5table;
    Pname t_name__5table;
};
extern Ptable table_free__5table;
union __Q2_6ktable4__C1;

union __Q2_6ktable4__C1 { /* sizeof __Q2_6ktable4__C1 == 8 */
    Ptable k_t;
    Pname k_n;
};

void *__nw__6ktableSFUl(size_t);
void __dl__6ktableSFPvUl(void *, size_t);

extern bit Nold;
extern bit vec_const;

extern bit fct_const;

extern Plist local_class;

extern Pname curr_fct;

extern bit new_type;
extern Pname cl_obj_vec;
extern Pname eobj;
enum Templ_type {
    VANILLA = 0,
    FCT_TEMPLATE = 1,
    CL_TEMPLATE = 2,
    BOUND_TEMPLATE = 3,
    INSTANTIATED = 4,
    UNINSTANTIATED = 5
};

struct type { /* sizeof type == 64 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;
};

TOK kind__4typeFUcN21(struct type *__0this, TOK, TOK, bit);

struct enumdef { /* sizeof enumdef == 96 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    bit e_body__7enumdef;
    short no_of_enumerators__7enumdef;
    unsigned short e_strlen__7enumdef;
    const char *string__7enumdef;
    Pname mem__7enumdef;
    Pbase e_type__7enumdef;
};
struct velem;

struct virt { /* sizeof virt == 56 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pvirt next__4virt;
    int n_init__4virt;
    struct velem *virt_init__4virt;
    Pclass vclass__4virt;
    const char *string__4virt;
    bit is_vbase__4virt;
    bit printed__4virt;
};
enum __E4 { C_VPTR = 1, C_XREF = 2, C_ASS = 4, C_VBASE = 8, C_REFM = 16 };
struct cons;

typedef struct cons *Pcons;
struct basic_template;
typedef struct basic_template *Ptempl_base;
struct toknode;

struct classdef { /* sizeof classdef == 240 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    int class_base__8classdef;
    bit c_body__8classdef;
    TOK csu__8classdef;
    bit obj_align__8classdef;
    bit c_xref__8classdef;

    short virt_count__8classdef;

    bit virt_merge__8classdef;

    bit has_vvtab__8classdef;
    unsigned short c_strlen__8classdef;
    Pbcl baselist__8classdef;
    const char *string__8classdef;
    Pname c_abstract__8classdef;
    Pname mem_list__8classdef;
    Ptable memtbl__8classdef;
    Pktab k_tbl__8classdef;
    Ptable c_context__8classdef;
    int obj_size__8classdef;
    int real_size__8classdef;
    Pcons templ_friends__8classdef;
    Plist friend_list__8classdef;
    Pname pubdef__8classdef;
    Ptype this_type__8classdef;
    Pvirt virt_list__8classdef;
    Pname c_ctor__8classdef;
    Pname c_dtor__8classdef;
    Pname c_itor__8classdef;
    Pname c_vtor__8classdef;
    Pname conv__8classdef;
    struct toknode *c_funqf__8classdef;

    struct toknode *c_funqr__8classdef;
};

bit same_class__8classdefFP8classdefi(struct classdef *__0this, Pclass __1p, int);
struct clist;

struct clist { /* sizeof clist == 16 */
    Pclass cl__5clist;
    struct clist *next__5clist;
};

extern struct clist *vcllist;
struct vl;

struct vl { /* sizeof vl == 24 */
    struct vl *next__2vl;
    Pvirt vt__2vl;
    struct classdef *cl__2vl;
};

extern struct vl *vlist;

extern int nin;
extern int Noffset;
extern TOK Nvis;
extern TOK Nvirt;
extern Pexpr Nptr;
extern Pbcl Nvbc_alloc;
extern const char *Nalloc_base;

extern int Vcheckerror;
extern int ignore_const;

extern int mex;
extern Pclass mec;
extern Pclass tcl;
extern int processing_sizeof;
union __Q2_8basetype4__C1;

union __Q2_8basetype4__C1 { /* sizeof __Q2_8basetype4__C1 == 8 */
    Ptype b_fieldtype;
    const char *b_linkage;
};
enum Linkage { linkage_default = 0, linkage_C = 1, linkage_Cplusplus = 2 };

extern int linkage;

void *__nw__3fctSFUl(size_t);
void __dl__3fctSFPvUl(void *, size_t);

struct fct { /* sizeof fct == 208 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    int fct_base__3fct;
    TOK nargs__3fct;
    TOK nargs_known__3fct;
    bit last_stmt__3fct;
    bit f_vdef__3fct;

    bit f_inline__3fct;
    bit f_is_inline__3fct;

    bit f_const__3fct;

    bit f_static__3fct;
    short f_virtual__3fct;
    short f_imeasure__3fct;
    Ptype returns__3fct;
    Pname argtype__3fct;
    Ptype s_returns__3fct;
    Pname f_this__3fct;
    Pclass memof__3fct;
    Pclass def_context__3fct;
    Pblock body__3fct;
    Pname f_init__3fct;
    Pexpr f_expr__3fct;
    Pexpr last_expanded__3fct;
    Pname nrv__3fct;
    Pname f_result__3fct;
    Pname f_args__3fct;
    int f_linkage__3fct;
    const char *f_signature__3fct;
    Plist local_class__3fct;
};

extern Pfct fct_free__3fct;
enum gen_types { no_templ = 0, some_templ = 1, all_templ = 2 };

struct gen { /* sizeof gen == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    Plist fct_list__3gen;
    int holds_templ__3gen;
};
struct pvtyp;

struct pvtyp { /* sizeof pvtyp == 72 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    Ptype typ__5pvtyp;
};

void *__nw__3vecSFUl(size_t);
void __dl__3vecSFPvUl(void *, size_t);

struct vec { /* sizeof vec == 88 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    Ptype typ__5pvtyp;

    Pexpr dim__3vec;
    int size__3vec;
};
extern Pvec vec_free__3vec;

void *__nw__3ptrSFUl(size_t);
void __dl__3ptrSFPvUl(void *, size_t);

struct ptr { /* sizeof ptr == 88 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    Ptype typ__5pvtyp;

    Pclass memof__3ptr;
    Pname ptname__3ptr;
};
extern Pptr ptr_free__3ptr;

static struct ptr *__ct__3ptrFUcP4type(register struct ptr *__0this, TOK __2b, Ptype __2t) {
    struct pvtyp *__0__X8;

    struct type *__0__X6;

    struct node *__0__X1;

    if (__0this || (__0this = (struct ptr *)__nw__3ptrSFUl((size_t)(sizeof(struct ptr))))) {
        __0this =
            (struct ptr
                 *)((__0__X8 = (((struct pvtyp *)__0this))),
                    (((__0__X8 ||
                       (__0__X8 = (struct pvtyp *)__nw__FUl((size_t)(sizeof(struct pvtyp)))))
                          ? (__0__X8 =
                                 (struct pvtyp
                                      *)((__0__X6 = (((struct type *)__0__X8))),
                                         (((__0__X6 || (__0__X6 = (struct type *)__nw__FUl(
                                                            (size_t)(sizeof(struct type)))))
                                               ? (((((((((__0__X6 =
                                                              (struct type
                                                                   *)((__0__X1 = (((
                                                                           struct node *)__0__X6))),
                                                                      (((__0__X1 ||
                                                                         (__0__X1 = (struct node *)
                                                                              __nw__FUl((
                                                                                  size_t)(sizeof(
                                                                                  struct node)))))
                                                                            ? (((__0__X1
                                                                                     ->base__4node =
                                                                                     0),
                                                                                (__0__X1
                                                                                     ->permanent__4node =
                                                                                     0)),
                                                                               (__0__X1
                                                                                    ->baseclass__4node =
                                                                                    0))
                                                                            : 0),
                                                                       __0__X1))),
                                                         (__0__X6->defined__4type = 0)),
                                                        (__0__X6->lex_level__4type = 0)),
                                                       (__0__X6->templ_base__4type = 0)),
                                                      (__0__X6->in_class__4type = 0)),
                                                     (__0__X6->nested_sig__4type = 0)),
                                                    (__0__X6->local_sig__4type = 0)),
                                                   (__0__X6->b_const__4type = 0)),
                                                  (__0__X6->ansi_const__4type = 0))
                                               : 0),
                                          __0__X6)))
                          : 0),
                     __0__X8));

        __0this->base__4node = __2b;

        __0this->typ__5pvtyp = __2t;

        ;
    }
    return __0this;
}

Ptype skiptypedefs__4typeFv(struct type *__0this);

extern int ref_initializer;
extern int ntok;
union __Q2_4expr4__C1;
union __Q2_4expr4__C2;
union __Q2_4expr4__C3;
union __Q2_4expr4__C4;

union __Q2_4expr4__C1 { /* sizeof __Q2_4expr4__C1 == 8 */
    Ptype tp;
    char *string4;
};
union __Q2_4expr4__C2 { /* sizeof __Q2_4expr4__C2 == 8 */
    Pexpr e1;
    long long i1;
    const char *string;
};
union __Q2_4expr4__C3 { /* sizeof __Q2_4expr4__C3 == 8 */
    Pexpr e2;
    int i2;
    const char *string2;
    Pexpr n_initializer;
    Ptype tpdef;
};
union __Q2_4expr4__C4 { /* sizeof __Q2_4expr4__C4 == 8 */
    Ptype tp2;
    Pname fct_name;
    Pexpr cond;
    Pexpr mem;
    Ptype as_type;
    Ptable n_table;
    Pin il;
    Pname query_this;
};

void *__nw__4exprSFUl(size_t);
void __dl__4exprSFPvUl(void *, size_t);

struct expr { /* sizeof expr == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};
extern Pexpr expr_free__4expr;

struct expr *__ct__4exprFUcP4exprT2(struct expr *__0this, TOK, Pexpr, Pexpr);

struct texpr { /* sizeof texpr == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct cast;

struct cast { /* sizeof cast == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct ival;

struct ival { /* sizeof ival == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct call { /* sizeof call == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct qexpr { /* sizeof qexpr == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct ref { /* sizeof ref == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct mdot;

struct mdot { /* sizeof mdot == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct text_expr;

struct text_expr { /* sizeof text_expr == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;
};

struct basecl { /* sizeof basecl == 48 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    TOK ppp__6basecl;
    bit allocated__6basecl;
    bit promoted__6basecl;
    Pclass bclass__6basecl;
    Pexpr init__6basecl;
    int ptr_offset__6basecl;
    int obj_offset__6basecl;
    Pname *virt_init__6basecl;
    struct basecl *next__6basecl;
};
enum template_formal_types {
    template_type_formal = 1,
    template_expr_formal = 2,
    template_actual_arg_dummy = 3
};

extern TOK ppbase;
union __Q2_4name4__C1;
union __Q2_4name4__C2;

union __Q2_4name4__C1 { /* sizeof __Q2_4name4__C1 == 8 */
    Pname n_list;
    Pname n_hidden;
    Pname n_dtag;
};

union __Q2_4name4__C2 { /* sizeof __Q2_4name4__C2 == 8 */

    Pname n_qualifier;
    Ptable n_realscope;
    int syn_class;
};

void *__nw__4nameSFUl(size_t);
void __dl__4nameSFPvUl(void *, size_t);

struct name { /* sizeof name == 144 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_4expr4__C1 __O1__4expr;

    union __Q2_4expr4__C2 __O2__4expr;

    union __Q2_4expr4__C3 __O3__4expr;

    union __Q2_4expr4__C4 __O4__4expr;

    TOK n_oper__4name;
    TOK n_sto__4name;
    TOK n_stclass__4name;
    TOK n_scope__4name;
    TOK n_key__4name;
    bit n_evaluated__4name;
    bit n_xref__4name;
    unsigned char lex_level__4name;
    TOK n_protect__4name;
    bit n_dcl_printed__4name;

    char n_template_arg__4name;
    bit n_template_fct__4name;
    bit n_redefined__4name;

    short n_addr_taken__4name;
    short n_used__4name;
    short n_assigned_to__4name;
    struct loc where__4name;
    int n_offset__4name;
    const char *n_anon__4name;

    union __Q2_4name4__C1 __O1__4name;
    Pname n_tbl_list__4name;
    const char *n_gen_fct_name__4name;
    char *n_template_arg_string__4name;
    Pktab n_ktable__4name;

    union __Q2_4name4__C2 __O2__4name;

    long long n_val__4name;

    int argno__4name;
};

extern Pname name_free__4name;

extern int friend_in_class;
extern int in_class_dcl;

extern int in_class_decl;
extern int parsing_class_members;
extern int in_mem_fct;
extern int in_arg_list;
extern Ptype in_typedef;
extern int defer_check;
extern int declTag;
extern Pname in_tag;
extern int DECL_TYPE;
union __Q2_4stmt4__C1;
union __Q2_4stmt4__C2;
union __Q2_4stmt4__C3;

union __Q2_4stmt4__C1 { /* sizeof __Q2_4stmt4__C1 == 8 */
    Pname d;
    Pexpr e2;
    Pstmt has_default;
    int case_value;
    Ptype ret_tp;
};
union __Q2_4stmt4__C2 { /* sizeof __Q2_4stmt4__C2 == 8 */
    Pexpr e;
    bit own_tbl;
    Pstmt s2;
};

union __Q2_4stmt4__C3 { /* sizeof __Q2_4stmt4__C3 == 8 */
    Pstmt for_init;
    Pstmt else_stmt;
    Pstmt case_list;
    struct loc where2;
};

void *__nw__4stmtSFUl(size_t);
void __dl__4stmtSFPvUl(void *, size_t);

struct stmt { /* sizeof stmt == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};
extern Pstmt stmt_free__4stmt;

extern const char *Neval;
extern Ptable scope;
extern Ptable expand_tbl;
extern Pname expand_fn;

struct stmt *__ct__4stmtFUc3locP4stmt(struct stmt *__0this, TOK, struct loc, Pstmt);

struct estmt { /* sizeof estmt == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct ifstmt;

struct ifstmt { /* sizeof ifstmt == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct lstmt;

struct lstmt { /* sizeof lstmt == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct forstmt;

struct forstmt { /* sizeof forstmt == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct block { /* sizeof block == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct handler;

struct handler { /* sizeof handler == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct pair;

struct pair { /* sizeof pair == 80 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt;

    union __Q2_4stmt4__C2 __O2__4stmt;
    Ptable memtbl__4stmt;
    Pktab k_tbl__4stmt;

    union __Q2_4stmt4__C3 __O3__4stmt;
};

struct nlist { /* sizeof nlist == 16 */
    Pname head__5nlist;
    Pname tail__5nlist;
};

struct slist { /* sizeof slist == 16 */
    Pstmt head__5slist;
    Pstmt tail__5slist;
};

struct elist { /* sizeof elist == 16 */
    Pexpr head__5elist;
    Pexpr tail__5elist;
};
struct dcl_context;

extern struct dcl_context *cc;

extern struct dcl_context *ccvec_end;

struct dcl_context { /* sizeof dcl_context == 48 */
    Pname c_this__11dcl_context;
    Ptype tot__11dcl_context;
    Pname not4__11dcl_context;
    Pclass cot__11dcl_context;
    Ptable ftbl__11dcl_context;
    Pname nof__11dcl_context;
};

extern int error__FiPCc(int, const char *);

extern const char *line_format;

extern Plist stat_mem_list;
extern Plist isf_list;
extern Pstmt st_ilist;
extern Pstmt st_dlist;
extern Ptable sti_tbl;
extern Ptable std_tbl;

extern bit enum_promote;
extern int suppress_error;

extern Pname overFound;
extern Pname Nover;
extern Pname Ncoerce;
extern int Nover_coerce;

struct ia { /* sizeof ia == 32 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pname local__2ia;
    Pexpr arg__2ia;
    Ptype tp__2ia;
};

struct iline { /* sizeof iline == 48 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pname fct_name__5iline;
    Pin i_next__5iline;
    Ptable i_table__5iline;
    int i_slots__5iline;
    Pia i_args__5iline;
};
struct con_dtor;

struct con_dtor { /* sizeof con_dtor == 24 */
    Pname tn__8con_dtor;
    Pexpr condition__8con_dtor;
    struct con_dtor *next__8con_dtor;
};

extern struct con_dtor *pdlist;
extern Pexpr curr_expr;
extern Pin curr_icall;

extern Pstmt curr_loop;
extern Pblock curr_block;
extern Pstmt curr_switch;
extern struct loc last_line;
extern int last_ll;
extern bit Cast;
extern bit TCast;
extern bit simpl_friend;
extern bit in_return;
extern struct loc no_where;

extern Pname vec_new_fct;
extern Pname new_fct;
extern Pname del_fct;
extern Pname vec_del_fct;

extern int Nstd;

extern int stcount;

extern int Pchecked;

extern Pname Ntmp;
extern Pname Ntmp_refd;
extern Pname Ntmp_flag;
extern Pexpr Ntmp_dtor;

extern Pclass Mptr;

extern bit fake_sizeof;

struct basetype { /* sizeof basetype == 112 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    bit b_unsigned__8basetype;
    bit b_signed__8basetype;
    bit b_volatile__8basetype;
    bit b_typedef__8basetype;
    bit b_inline__8basetype;
    bit b_virtual__8basetype;
    bit b_short__8basetype;
    bit b_long__8basetype;
    bit b_bits__8basetype;
    bit b_offset__8basetype;
    TOK b_sto__8basetype;
    Pname b_name__8basetype;
    Ptable b_table__8basetype;
    Pname b_xname__8basetype;

    union __Q2_8basetype4__C1 __O1__8basetype;
};

extern int error__FiPCcRC2eaN33(int, const char *, const struct ea *, const struct ea *,
                                const struct ea *, const struct ea *);

struct name_list { /* sizeof name_list == 24 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pname f__9name_list;
    Plist l__9name_list;
};

struct name *__ct__4nameFPCc(struct name *__0this, const char *);

Pname insert__5tableFP4nameUc(struct table *__0this, Pname, TOK);
enum discriminator_error {
    discrim_none_valid = 0,
    discrim_bad_index = -1,
    discrim_inconsistent_node = -2
};
enum node_class {
    nc_unused = 0,
    nc_eof = 1,
    nc_virt = 2,
    nc_nlist = 3,
    nc_gen = 4,
    nc_vec = 5,
    nc_ptr = 6,
    nc_fct = 7,
    nc_table = 8,
    nc_basetype = 9,
    nc_name = 10,
    nc_expr = 11,
    nc_stmt = 12,
    nc_enumdef = 13,
    nc_classdef = 14,
    nc_baseclass = 15,
    nc_iline = 16,
    nc_ia = 17,
    nc_tpdef = 18,
    nc_ktable = 19
};
enum tree_node_action { tna_continue = 0, tna_stop = 1, tna_error = 2 };

typedef int (*tree_fetch_proc)(void *__0info, void *__0pointer, size_t __0length, int __0zero_stop,
                               void *__0target);

static tree_fetch_proc null_tfp =
    (int (*)(void *__0info, void *__0pointer, size_t __0length, int __0zero_stop, void *__0target))(
        ((int (*)(void *__0info, void *__0pointer, unsigned long __0length, int __0zero_stop,
                  void *__0target))0));
struct tree_walk_tree;

typedef void (*tree_pre_action)(Pnode *, int, void *, int *, int, Pnode, struct tree_walk_tree *,
                                int *);

typedef void (*tree_post_action)(Pnode *, int, void *, int *, int, Pnode, struct tree_walk_tree *);

typedef void (*errorp)(char, const char *);
struct tree_walk_control;

struct tree_walk_control { /* sizeof tree_walk_control == 80 */

    int version__17tree_walk_control;
    void *callback_info__17tree_walk_control;
    tree_fetch_proc fetcher__17tree_walk_control;
    tree_pre_action action_proc__17tree_walk_control;
    tree_post_action post_action_proc__17tree_walk_control;
    int (*i_error__17tree_walk_control)(int, const char *);
    int call_i_error__17tree_walk_control;
    struct Hash *nodes_seen_hash__17tree_walk_control;

    int resolve_by_name__17tree_walk_control;
    int alloc_stack_bytes__17tree_walk_control;

    int dont_chase_lists_top__17tree_walk_control;
};
struct patch_tree;

typedef struct patch_tree *Ppatch_tree;

struct patch_tree { /* sizeof patch_tree == 16 */

    Pnode node__10patch_tree;
    Ppatch_tree next__10patch_tree;
};

extern Ppatch_tree head__10patch_tree;
extern struct Hash *ht__10patch_tree;
struct tree_copy_info;

struct tree_copy_info { /* sizeof tree_copy_info == 24 */

    void (*node_hook__14tree_copy_info)(void *__1info, Pnode *, int, int *, int *);

    char *(*malloc_hook__14tree_copy_info)(void *__1info, size_t);
    void *hook_info__14tree_copy_info;
};

extern Pclass current_instantiation;
extern Pfct current_fct_instantiation;
struct templ;

typedef struct templ *Ptempl;
struct funct_inst;
typedef struct funct_inst *Pfunct_inst;
struct templ_inst;
typedef struct templ_inst *Ptempl_inst;
struct basic_inst;
typedef struct basic_inst *Pbase_inst;
struct function_template;

typedef struct function_template *Pfunt;
struct data_template;
typedef struct data_template *Pdata;
struct templ_state;
typedef struct templ_state *Ptstate;
struct templ_classdef;
typedef struct templ_classdef *Ptclass;
struct templ_fct;
typedef struct templ_fct *Ptfct;
struct Pslot;
typedef struct Pslot *Pbinding;

struct cons { /* sizeof cons == 16 */

    void *car__4cons;
    struct cons *cdr__4cons;
};
struct templ_compilation;

extern struct templ_compilation *templp;

struct basic_template { /* sizeof basic_template == 48 */

    Plist formals__14basic_template;
    Pcons templ_refs__14basic_template;

    Pname Cdcl__14basic_template;
    Pstmt Cstmt__14basic_template;

    int open_instantiations__14basic_template;
    int extrapolated__14basic_template;

    struct __mptr *__vptr__14basic_template;
};
struct templ { /* sizeof templ == 128 */

    Plist formals__14basic_template;
    Pcons templ_refs__14basic_template;

    Pname Cdcl__14basic_template;
    Pstmt Cstmt__14basic_template;

    int open_instantiations__14basic_template;
    int extrapolated__14basic_template;

    struct __mptr *__vptr__14basic_template;

    Ptempl_inst insts__5templ;
    Pbase basep__5templ;
    Pfunt fns__5templ;
    Pfunt fns_end__5templ;
    Pdata data__5templ;
    Pdata data_end__5templ;

    Ptempl next__5templ;
    Pname namep__5templ;
    int defined__5templ;
    Pname members__5templ;
};

struct function_template { /* sizeof function_template == 80 */

    Plist formals__14basic_template;
    Pcons templ_refs__14basic_template;

    Pname Cdcl__14basic_template;
    Pstmt Cstmt__14basic_template;

    int open_instantiations__14basic_template;
    int extrapolated__14basic_template;

    struct __mptr *__vptr__14basic_template;

    Pname fn__17function_template;
    Pfunt next__17function_template;
    Pfunt gen_list__17function_template;

    Pfunct_inst insts__17function_template;
};
struct state;

struct state { /* sizeof state == 88 */

    Pname Cdcl__5state;
    Pstmt Cstmt__5state;
    Pname dcl_list__5state;
    struct loc curloc__5state;

    int curr_file__5state;
    Pexpr curr_expr__5state;
    Pin curr_icall__5state;
    Pstmt curr_loop__5state;
    Pblock curr_block__5state;
    Pstmt curr_switch__5state;

    int bound__5state;
    int inline_restr__5state;
    struct loc last_line__5state;
};
enum inst_status {
    uninstantiated = 0,
    function_instantiated = 1,
    data_instantiated = 2,
    class_instantiated = 3,
    body_instantiated = 4
};
struct template_instantiation;

struct basic_inst { /* sizeof basic_inst == 168 */

    Pexpr actuals__10basic_inst;

    Plist inst_formals__10basic_inst;

    TOK isa__10basic_inst;
    Pname tname__10basic_inst;
    Pname namep__10basic_inst;
    struct state context__10basic_inst;
    Plist hidden_globals__10basic_inst;

    int status__10basic_inst;
    Pbase_inst next_active__10basic_inst;

    struct pointer_hash *corr__10basic_inst;

    struct __mptr *__vptr__10basic_inst;
};

extern Pbase_inst head__10basic_inst;

struct templ_inst { /* sizeof templ_inst == 200 */

    Pexpr actuals__10basic_inst;

    Plist inst_formals__10basic_inst;

    TOK isa__10basic_inst;
    Pname tname__10basic_inst;
    Pname namep__10basic_inst;
    struct state context__10basic_inst;
    Plist hidden_globals__10basic_inst;

    int status__10basic_inst;
    Pbase_inst next_active__10basic_inst;

    struct pointer_hash *corr__10basic_inst;

    struct __mptr *__vptr__10basic_inst;

    Ptempl_inst next__10templ_inst;
    Ptempl_inst forward__10templ_inst;

    Ptempl def__10templ_inst;

    int refp__10templ_inst;

    int friend_refp__10templ_inst;
};

extern int zdebug;

struct templ_classdef { /* sizeof templ_classdef == 248 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    int class_base__8classdef;
    bit c_body__8classdef;
    TOK csu__8classdef;
    bit obj_align__8classdef;
    bit c_xref__8classdef;

    short virt_count__8classdef;

    bit virt_merge__8classdef;

    bit has_vvtab__8classdef;
    unsigned short c_strlen__8classdef;
    Pbcl baselist__8classdef;
    const char *string__8classdef;
    Pname c_abstract__8classdef;
    Pname mem_list__8classdef;
    Ptable memtbl__8classdef;
    Pktab k_tbl__8classdef;
    Ptable c_context__8classdef;
    int obj_size__8classdef;
    int real_size__8classdef;
    Pcons templ_friends__8classdef;
    Plist friend_list__8classdef;
    Pname pubdef__8classdef;
    Ptype this_type__8classdef;
    Pvirt virt_list__8classdef;
    Pname c_ctor__8classdef;
    Pname c_dtor__8classdef;
    Pname c_itor__8classdef;
    Pname c_vtor__8classdef;
    Pname conv__8classdef;
    struct toknode *c_funqf__8classdef;

    struct toknode *c_funqr__8classdef;

    Ptempl_inst inst__14templ_classdef;
};

void __dt__8classdefFv(struct classdef *__0this, int);

void *__nw__9templ_fctSFUl(size_t);
void __dl__9templ_fctSFPvUl(void *, size_t);

struct templ_fct { /* sizeof templ_fct == 216 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    bit defined__4type;

    bit lex_level__4type;
    int templ_base__4type;
    Pclass in_class__4type;
    Pname in_fct__4type;
    char *nested_sig__4type;
    char *local_sig__4type;
    bit b_const__4type;
    bit ansi_const__4type;

    Ptype tlist__4type;

    int fct_base__3fct;
    TOK nargs__3fct;
    TOK nargs_known__3fct;
    bit last_stmt__3fct;
    bit f_vdef__3fct;

    bit f_inline__3fct;
    bit f_is_inline__3fct;

    bit f_const__3fct;

    bit f_static__3fct;
    short f_virtual__3fct;
    short f_imeasure__3fct;
    Ptype returns__3fct;
    Pname argtype__3fct;
    Ptype s_returns__3fct;
    Pname f_this__3fct;
    Pclass memof__3fct;
    Pclass def_context__3fct;
    Pblock body__3fct;
    Pname f_init__3fct;
    Pexpr f_expr__3fct;
    Pexpr last_expanded__3fct;
    Pname nrv__3fct;
    Pname f_result__3fct;
    Pname f_args__3fct;
    int f_linkage__3fct;
    const char *f_signature__3fct;
    Plist local_class__3fct;

    Pfunct_inst inst__9templ_fct;
};

extern Ptfct ptfct_free__9templ_fct;

struct funct_inst { /* sizeof funct_inst == 200 */

    Pexpr actuals__10basic_inst;

    Plist inst_formals__10basic_inst;

    TOK isa__10basic_inst;
    Pname tname__10basic_inst;
    Pname namep__10basic_inst;
    struct state context__10basic_inst;
    Plist hidden_globals__10basic_inst;

    int status__10basic_inst;
    Pbase_inst next_active__10basic_inst;

    struct pointer_hash *corr__10basic_inst;

    struct __mptr *__vptr__10basic_inst;

    Pfunct_inst next__10funct_inst;

    Pfunt def__10funct_inst;
    int refp__10funct_inst;
    int friend_refp__10funct_inst;
    Pbinding binding__10funct_inst;
};

#pragma lib "ape/libap.a"

typedef int (*GPT)(int, char *);
struct Block_CPchar;

struct Block_CPchar { /* sizeof Block_CPchar == 16 */

    CPchar *p__12Block_CPchar;

    size_t n__12Block_CPchar;
};

void move__12Block_CPcharFPPCcUl(struct Block_CPchar *__0this, CPchar *, size_t);

void copy__12Block_CPcharFRC12Block_CPchar(struct Block_CPchar *__0this,
                                           const struct Block_CPchar *);

size_t grow__12Block_CPcharFUl(struct Block_CPchar *__0this, size_t);
struct Block_Pchar;
struct Block_Pchar { /* sizeof Block_Pchar == 16 */

    Pchar *p__11Block_Pchar;

    size_t n__11Block_Pchar;
};

void move__11Block_PcharFPPcUl(struct Block_Pchar *__0this, Pchar *, size_t);

void copy__11Block_PcharFRC11Block_Pchar(struct Block_Pchar *__0this, const struct Block_Pchar *);

size_t grow__11Block_PcharFUl(struct Block_Pchar *__0this, size_t);
extern struct Block_Pchar instfct;
extern int noinst;
extern struct Block_Pchar instdata;
extern int nodatainst;
extern bit tempdcl;
extern bit mk_zero_init_flag;
extern int first_file;
extern bit all_flag;

extern bit alltc_flag;

extern bit data_flag;

extern bit ft_flag;

extern bit none_flag;

extern Pname righttname;

extern int bound;
bit tempdcl = 0;
static Ptempl_inst dummyinst = 0;
static Ptempl_inst curr_inst = 0;
static Pfunct_inst fdummyinst = 0;
static Pfunct_inst fcurr_inst = 0;
static bit notinstflag = 0;

Ptable bound_expr_tbl = 0;

struct templ_compilation { /* sizeof templ_compilation == 1 */

    char __W17__17templ_compilation;
};

extern Plist param_end__17templ_compilation;
extern Ptempl list__17templ_compilation;
extern Pfunt f_list__17templ_compilation;
extern Pfunt f_owner__17templ_compilation;
extern Ptempl owner__17templ_compilation;
extern Ptempl_base parsed_template__17templ_compilation;

extern Plist params__17templ_compilation;
extern Pexpr actuals__17templ_compilation;
extern Ptable templates__17templ_compilation;

extern int in_progress__17templ_compilation;
extern Ptstate save_templ__17templ_compilation;

extern int parameters_in_progress__17templ_compilation;
extern int formals_in_progress__17templ_compilation;

extern Pcons templ_refs__17templ_compilation;
extern Pcons friend_templ_refs__17templ_compilation;
extern Pcons last_cons__17templ_compilation;
extern Pcons last_friend_cons__17templ_compilation;

Pfunt f_list__17templ_compilation = 0;
Pbase_inst head__10basic_inst = 0;
Ptempl list__17templ_compilation = 0;
Pcons last_cons__17templ_compilation = 0;
Pcons last_friend_cons__17templ_compilation = 0;
Pcons templ_refs__17templ_compilation = 0;
Pcons friend_templ_refs__17templ_compilation = 0;
Ptstate save_templ__17templ_compilation = 0;
Ptempl_base parsed_template__17templ_compilation = 0;
Pfunt f_owner__17templ_compilation = 0;
Ptempl owner__17templ_compilation = 0;
Plist param_end__17templ_compilation = 0;
Plist params__17templ_compilation = 0;
Pexpr actuals__17templ_compilation = 0;
int formals_in_progress__17templ_compilation = 0;

struct templ_compilation *templp = 0;
Ptable templates__17templ_compilation = 0;

void save__5stateFv(register struct state *__0this) {
    __0this->Cdcl__5state = Cdcl;
    __0this->Cstmt__5state = Cstmt;
    __0this->curloc__5state = curloc;

    __0this->curr_file__5state = curr_file;
    __0this->curr_expr__5state = curr_expr;
    __0this->curr_icall__5state = curr_icall;
    __0this->curr_loop__5state = curr_loop;
    __0this->curr_block__5state = curr_block;
    __0this->curr_switch__5state = curr_switch;

    __0this->bound__5state = bound;
    __0this->inline_restr__5state = inline_restr;
    __0this->last_line__5state = last_line;
}

void restore__5stateFv(register struct state *__0this) {
    Cdcl = __0this->Cdcl__5state;
    Cstmt = __0this->Cstmt__5state;
    curloc = __0this->curloc__5state;

    curr_file = __0this->curr_file__5state;
    curr_expr = __0this->curr_expr__5state;
    curr_icall = __0this->curr_icall__5state;
    curr_loop = __0this->curr_loop__5state;
    curr_block = __0this->curr_block__5state;
    curr_switch = __0this->curr_switch__5state;

    bound = __0this->bound__5state;
    inline_restr = __0this->inline_restr__5state;
    last_line = __0this->last_line__5state;
}

void init__5stateFv(struct state *__0this) {
    bound = 0;
    inline_restr = 0;
}

int get_class_base__FP8basetype(Pbase __1b) {
    unsigned long __2__X27;

    if (__1b->base__4node != 119) {
        struct ea __0__V26;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"::get_class_base: badAT(%k) cobjX",
            (const struct ea *)((__2__X27 = __1b->base__4node),
                                (((((&__0__V26)->__O1__2ea.i = __2__X27), 0)), (&__0__V26))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    return (((struct templ_classdef *)((
                (struct templ_classdef *)(((struct basetype *)(((struct basetype *)__1b))))
                    ->b_name__8basetype->__O1__4expr.tp))))
        ->class_base__8classdef;
}

int get_templ_base__FP8basetype(Pbase __1b) {
    unsigned long __2__X29;

    if (__1b->base__4node != 119) {
        struct ea __0__V28;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"::get_templ_base: badAT(%k) cobjX",
            (const struct ea *)((__2__X29 = __1b->base__4node),
                                (((((&__0__V28)->__O1__2ea.i = __2__X29), 0)), (&__0__V28))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    return (((struct classdef *)((
                (struct classdef *)(((struct basetype *)(((struct basetype *)__1b))))
                    ->b_name__8basetype->__O1__4expr.tp))))
        ->templ_base__4type;
}

Ptclass get_template_class__FP8basetype(Pbase __1b) {
    int __1t;

    __1t = get_class_base__FP8basetype(__1b);
    if (!((__1t == 4) || (__1t == 5)))
        error__FiPCc((int)'i', (const char *)"C is not aYC");
    return (((struct templ_classdef *)((
        (struct templ_classdef *)(((struct basetype *)(((struct basetype *)__1b))))
            ->b_name__8basetype->__O1__4expr.tp))));
}

static bit same_class_templ__FP8classdefT1(Pclass __1c1, Pclass __1c2) {
    if (__1c1 == __1c2)
        return (unsigned char)1;

    if (((__1c1->class_base__8classdef == 4) && (__1c2->class_base__8classdef == 5)) &&
        ((((struct templ_classdef *)(((struct templ_classdef *)__1c1))))
             ->inst__14templ_classdef->def__10templ_inst ==
         (((struct templ_classdef *)(((struct templ_classdef *)__1c2))))
             ->inst__14templ_classdef->def__10templ_inst))
        return (unsigned char)1;

    if (((__1c2->class_base__8classdef == 4) && (__1c1->class_base__8classdef == 5)) &&
        ((((struct templ_classdef *)(((struct templ_classdef *)__1c1))))
             ->inst__14templ_classdef->def__10templ_inst ==
         (((struct templ_classdef *)(((struct templ_classdef *)__1c2))))
             ->inst__14templ_classdef->def__10templ_inst))
        return (unsigned char)1;

    return (unsigned char)0;
}

extern int strcmp(const char *, const char *);

int same__10templ_instFP10templ_inst(struct templ_inst *__0this, Ptempl_inst __1t);

bit same_class__8classdefFP8classdefi(register struct classdef *__0this, Pclass __1pc,
                                      int __1access) {
    if (__0this == 0)
        return (unsigned char)0;
    if (__1pc == 0)
        return (unsigned char)0;
    if (__0this == __1pc)
        return (unsigned char)1;

    if ((__0this->class_base__8classdef == 0) && (__1pc->class_base__8classdef == 0)) {
        if (__0this->local_sig__4type && __1pc->local_sig__4type) {
            return (unsigned char)(strcmp((const char *)__0this->local_sig__4type,
                                          (const char *)__1pc->local_sig__4type) == 0);
        }
        if (__0this->nested_sig__4type && __1pc->nested_sig__4type) {
            return (unsigned char)(strcmp((const char *)__0this->nested_sig__4type,
                                          (const char *)__1pc->nested_sig__4type) == 0);
        }
        if ((__0this->local_sig__4type == __1pc->local_sig__4type) &&
            (__0this->nested_sig__4type == __1pc->nested_sig__4type)) {
            return (unsigned char)(strcmp(__0this->string__8classdef, __1pc->string__8classdef) ==
                                   0);
        }
        return (unsigned char)0;
    }

    {
        int __1this_base;
        int __1pc_base;

        struct templ_inst *__0__X30;

        struct templ_inst *__0__X31;

        __1this_base = __0this->class_base__8classdef;
        __1pc_base = __1pc->class_base__8classdef;

        if (((__1this_base == 2) && (__1pc_base == 4)) &&
            (((__0__X30 = (((struct templ_classdef *)(((struct templ_classdef *)__1pc))))
                              ->inst__14templ_classdef),
              (__0__X30->def__10templ_inst->basep__5templ))
                 ->b_name__8basetype->__O1__4expr.tp == (((struct type *)__0this))))
            return (unsigned char)1;

        if (((__1pc_base == 2) && (__1this_base == 4)) &&
            (((__0__X31 = (((struct templ_classdef *)(((struct templ_classdef *)__0this))))
                              ->inst__14templ_classdef),
              (__0__X31->def__10templ_inst->basep__5templ))
                 ->b_name__8basetype->__O1__4expr.tp == (((struct type *)__1pc))))
            return (unsigned char)1;

        if (((__1pc_base == 4) && (__1this_base == 4)) &&
            ((strcmp(__1pc->string__8classdef, __0this->string__8classdef) == 0) ||
             same__10templ_instFP10templ_inst(
                 (((struct templ_classdef *)(((struct templ_classdef *)__0this))))
                     ->inst__14templ_classdef,
                 (((struct templ_classdef *)(((struct templ_classdef *)__1pc))))
                     ->inst__14templ_classdef)))
            return (unsigned char)1;

        if (__1access == 0)
            return (unsigned char)0;

        if ((__1this_base == 4) && (__1pc_base == 5)) {
            const char *__2str;

            __2str =
                (((struct templ_classdef *)(((struct templ_classdef *)__0this))))
                    ->inst__14templ_classdef->def__10templ_inst->namep__5templ->__O2__4expr.string;

            return (unsigned char)(strcmp(__2str, __1pc->string__8classdef) == 0);
        }

        if ((__1pc_base == 4) && (__1this_base == 5)) {
            const char *__2str;

            __2str =
                (((struct templ_classdef *)(((struct templ_classdef *)__1pc))))
                    ->inst__14templ_classdef->def__10templ_inst->namep__5templ->__O2__4expr.string;

            return (unsigned char)(strcmp(__2str, __0this->string__8classdef) == 0);
        }
        return (unsigned char)0;
    }
}

int same__10templ_instFP10templ_inst(register struct templ_inst *__0this, Ptempl_inst __1t) {
    return (int)((((__0this->forward__10templ_inst &&
                    (__0this->forward__10templ_inst == __1t->forward__10templ_inst)) ||
                   (__0this->forward__10templ_inst == __1t)) ||
                  (__1t->forward__10templ_inst == __0this))
                     ? 1
                     : 0);
}

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

Ptempl is_template__17templ_compilationFP4name(register struct templ_compilation *__0this,
                                               Pname __1p) {
    if (__1p->__O1__4expr.tp && (__1p->__O1__4expr.tp->base__4node == 119)) {
        int __2tc;
        int __2sc;

        __2tc = get_class_base__FP8basetype(
            ((struct basetype *)(((struct basetype *)__1p->__O1__4expr.tp))));
        __2sc = get_templ_base__FP8basetype(
            ((struct basetype *)(((struct basetype *)__1p->__O1__4expr.tp))));

        if ((__2tc == 2) || ((__2tc == 4) && (__2sc == 2))) {
            Pname __3n;

            __3n = look__5tableFPCcUc(templates__17templ_compilation, __1p->__O2__4expr.string,
                                      (unsigned char)0);
            return (__3n ? (((struct templ *)(((struct templ *)__3n->__O1__4expr.tp))))
                         : (((struct templ *)0)));
        } else
            return (struct templ *)0;
    }
    return (struct templ *)0;
}

Ptempl is_template__17templ_compilationFPCc(struct templ_compilation *__0this, const char *__1s) {
    Pname __1n;

    __1n = look__5tableFPCcUc(templates__17templ_compilation, __1s, (unsigned char)0);
    return (__1n ? (((struct templ *)(((struct templ *)__1n->__O1__4expr.tp))))
                 : (((struct templ *)0)));
}

Pfunt is_template__17templ_compilationFPCcUc(struct templ_compilation *__0this, const char *__1s,
                                             TOK __1t) {
    Pname __1n;

    __1n = look__5tableFPCcUc(templates__17templ_compilation, __1s, __1t);
    return (
        __1n ? (((struct function_template *)(((struct function_template *)__1n->__O1__4expr.tp))))
             : (((struct function_template *)0)));
}

void start__17templ_compilationFv(struct templ_compilation *__0this) {
    in_progress__17templ_compilation = 1;
    params__17templ_compilation = (param_end__17templ_compilation = 0);
    owner__17templ_compilation = 0;

    f_owner__17templ_compilation = 0;
    parsed_template__17templ_compilation = 0;
}

Pname tdef__4nameFv(struct name *__0this);

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

void append_parameter__17templ_compilationFP4name(struct templ_compilation *__0this, Pname);

void collect__17templ_compilationFUcP4name(register struct templ_compilation *__0this,
                                           TOK __1parm_type, Pname __1n) {
    switch (__1parm_type) {
    case 32:
    case 6:
        __1n->__O1__4expr.tp = (struct type *)any_type;

        __1n = tdef__4nameFv(__1n);
        __1n->lex_level__4name = (bl_level + 1);
        __1n->n_template_arg__4name = 1;
        break;
    default: {
        struct ea __0__V32;

        struct ea __0__V33;

        error__FPCcRC2eaN32(
            (const char *)"theZT for%n must beC or struct, not%k",
            (const struct ea *)(((&__0__V32)->__O1__2ea.p = ((const void *)__1n)), (&__0__V32)),
            (const struct ea *)(((((&__0__V33)->__O1__2ea.i = ((unsigned long)__1parm_type)), 0)),
                                (&__0__V33)),
            (const struct ea *)ea0, (const struct ea *)ea0);

        break;
    }
    }
    append_parameter__17templ_compilationFP4name(__0this, __1n);
}

struct name_list *__ct__9name_listFP4nameP9name_list(struct name_list *__0this, Pname __1ff,
                                                     Plist __1ll);

void append_parameter__17templ_compilationFP4name(register struct templ_compilation *__0this,
                                                  Pname __1n) {
    if (params__17templ_compilation) {
        param_end__17templ_compilation->l__9name_list =
            __ct__9name_listFP4nameP9name_list((struct name_list *)0, __1n, (struct name_list *)0);
        param_end__17templ_compilation = param_end__17templ_compilation->l__9name_list;
    } else
        params__17templ_compilation =
            (param_end__17templ_compilation = __ct__9name_listFP4nameP9name_list(
                 (struct name_list *)0, __1n, (struct name_list *)0));
    __1n->permanent__4node = 1;

    __1n->__O1__4expr.tp->permanent__4node = 1;
}

void collect__17templ_compilationFP4name(register struct templ_compilation *__0this, Pname __1n) {
    extern int must_be_friend;

    __1n->n_template_arg__4name = 2;
    ;
    if (must_be_friend == 0)
        insert__5tableFP4nameUc(bound_expr_tbl, __1n, (unsigned char)0);
    append_parameter__17templ_compilationFP4name(__0this, __1n);
}

struct basetype *__ct__8basetypeFUcP4name(struct basetype *__0this, TOK, Pname);

static void check_non_type_formal__FP4name(Pname __1n) {
    Ptype __1tp;

    __1tp = skiptypedefs__4typeFv(__1n->__O1__4expr.tp);
    switch (__1tp->base__4node) {
    case 15:
    case 11:
    case 181:
        if ((__1tp->base__4node == 181) && (ansi_opt == 0)) {
            struct ea __0__V34;

            error__FiPCcRC2eaN33(
                (int)'w',
                (const char
                     *)"long double supported under ``+a1'' option only, generating ``double%n''",
                (const struct ea *)(((&__0__V34)->__O1__2ea.p = ((const void *)__1n)), (&__0__V34)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        error__FiPCc((int)'s', (const char *)"ZE ofT float, double, or long double");
        return;

    case 138:
    case 5:
    case 29:
    case 21:
    case 22:
    case 122:
    case 114:
    case 121:
    case 119:
    case 141: {
        TOK __3bad_base;

        __3bad_base = 0;
        if ((((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp))))
                ->b_volatile__8basetype)
            __3bad_base = 170;

        if ((((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp))))->b_inline__8basetype)
            __3bad_base = 75;
        if ((((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp))))
                ->b_virtual__8basetype)
            __3bad_base = 77;
        if (__3bad_base) {
            struct ea __0__V35;

            struct ea __0__V36;

            error__FPCcRC2eaN32(
                (const char *)"bad %k declarator forY formal %n",
                (const struct ea *)(((((&__0__V35)->__O1__2ea.i = ((unsigned long)__3bad_base)),
                                      0)),
                                    (&__0__V35)),
                (const struct ea *)(((&__0__V36)->__O1__2ea.p = ((const void *)__1n)), (&__0__V36)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        goto hack;
    }
    case 125: {
        if (__1tp != __1n->__O1__4expr.tp) {
        hack: {
            Pbase __4b;

            __4b =
                __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)0, (struct name *)0);
            ((*__4b)) = (*(((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp)))));

            if (__4b->b_const__4type == 0)
                __4b->b_const__4type = 2;
            __1n->__O1__4expr.tp = (struct type *)__4b;
            break;
        }
        }

        {
            Pptr __3b;

            __3b = __ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)0, (struct type *)0);
            ((*__3b)) = (*(((struct ptr *)(((struct ptr *)__1n->__O1__4expr.tp)))));
            if (__3b->b_const__4type == 0)
                __3b->b_const__4type = 2;
            __1n->__O1__4expr.tp = (struct type *)__3b;
            break;
        }
    }
    case 158:
    case 110:
        break;
    default: {
        struct ea __0__V37;

        struct ea __0__V38;

        error__FPCcRC2eaN32(
            (const char *)"badZT%t for formalZ %n",
            (const struct ea *)(((&__0__V37)->__O1__2ea.p = ((const void *)__1tp)), (&__0__V37)),
            (const struct ea *)(((&__0__V38)->__O1__2ea.p = ((const void *)__1n)), (&__0__V38)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }
    return;
}

void dcl__4typeFP5table(struct type *__0this, Ptable);

void enter_parameters__17templ_compilationFv(register struct templ_compilation *__0this) {
    {
        {
            Plist __1list;

            __1list = params__17templ_compilation;

            for (; __1list; __1list = __1list->l__9name_list) {
                Pname __2n;

                __2n = __1list->f__9name_list;
                switch (__2n->n_template_arg__4name) {
                case 1:
                    __2n->n_key__4name = 0;
                    break;

                case 2:
                    check_non_type_formal__FP4name(__2n);
                    dcl__4typeFP5table(__2n->__O1__4expr.tp, gtbl);
                    break;
                default:
                    error__FiPCc((int)'i', (const char *)"bad template formal");
                }
            }
        }
    }
}

void check_formals__14basic_templateFP9name_list(struct basic_template *__0this, Plist __1formals);

void resolve_forward_decl__5templFP9name_listP8classdef(register struct templ *__0this,
                                                        Plist __1params, Pclass __1c) {
    check_formals__14basic_templateFP9name_list((struct basic_template *)__0this, __1params);
    __0this->formals__14basic_template = __1params;
    __0this->defined__5templ = 1;
    __0this->members__5templ = __1c->mem_list__8classdef;
}

static bit reinstat = 0;

Ptempl_inst instantiate__10templ_instF4bool(struct templ_inst *__0this, int __1reinstantiate);

void instantiate_forward_decl__5templFv(register struct templ *__0this) {
    {
        {
            Ptempl_inst __1i;

            __1i = __0this->insts__5templ;

            for (; __1i; __1i = __1i->next__10templ_inst)
                if (((((struct templ_classdef *)((
                          (struct templ_classdef *)(((struct basetype *)((
                                                        (struct basetype *)__1i->tname__10basic_inst
                                                            ->__O1__4expr.tp))))
                              ->b_name__8basetype->__O1__4expr.tp))))
                         ->class_base__8classdef == 4) &&
                    (!__1i->forward__10templ_inst)) {
                    reinstat = 1;
                    instantiate__10templ_instF4bool(__1i, 1);
                    reinstat = 0;
                }
        }
    }
}

void instantiate__10funct_instF4bool(struct funct_inst *__0this, int __1reinstantiate);

void instantiate_forward_decl__17function_templateFv(register struct function_template *__0this) {
    {
        {
            Pfunct_inst __1i;

            __1i = __0this->insts__17function_template;

            for (; __1i; __1i = __1i->next__10funct_inst)
                if ((((struct templ_fct *)((
                         (struct templ_fct *)__1i->tname__10basic_inst->__O1__4expr.tp))))
                        ->fct_base__3fct == 4) {
                    instantiate__10funct_instF4bool(__1i, 1);
                }
        }
    }
}

int check_qualifier__10templ_instFP9name_list(register struct templ_inst *__0this,
                                              Plist __1formals) {
    Pexpr __1actual;

    __1actual = __0this->actuals__10basic_inst;
    {
        {
            Plist __1formal;

            __1formal = __1formals;

            for (; __1formal && __1actual;
                 ((__1formal = __1formal->l__9name_list), (__1actual = __1actual->__O3__4expr.e2)))
                switch (__1formal->f__9name_list->n_template_arg__4name) {
                case 1: {
                    Pbase __3b;

                    __3b = (((struct basetype *)((
                        (struct basetype *)__1actual->__O2__4expr.e1->__O1__4expr.tp))));

                    if (!(((__3b->base__4node == 97) &&
                           (__3b->b_name__8basetype->base__4node == 123)) &&
                          (strcmp((((struct name *)(((struct name *)__3b->b_name__8basetype))))
                                      ->__O2__4expr.string,
                                  __1formal->f__9name_list->__O2__4expr.string) == 0)))
                        return (int)0;
                    break;
                }

                case 2:
                    if (!((__1actual->__O2__4expr.e1->base__4node == 85) &&
                          (strcmp((((struct name *)(((struct name *)__1actual->__O2__4expr.e1))))
                                      ->__O2__4expr.string,
                                  __1formal->f__9name_list->__O2__4expr.string) == 0)))
                        return (int)0;
                    break;

                default:
                    error__FiPCc((int)'i', (const char *)"bad template formal");
                }

            return (int)1;
        }
    }
}

extern int add_first;

Pname add__3genFP4name(struct gen *__0this, Pname);

static struct gen *__ct__3genFv(struct gen *__0this) {
    struct type *__0__X5;

    struct node *__0__X1;

    if (__0this || (__0this = (struct gen *)__nw__FUl((size_t)(sizeof(struct gen))))) {
        (((__0this =
               (struct gen
                    *)((__0__X5 = (((struct type *)__0this))),
                       (((__0__X5 ||
                          (__0__X5 = (struct type *)__nw__FUl((size_t)(sizeof(struct type)))))
                             ? (((((((((__0__X5 =
                                            (struct type
                                                 *)((__0__X1 = (((struct node *)__0__X5))),
                                                    (((__0__X1 ||
                                                       (__0__X1 = (struct node *)__nw__FUl(
                                                            (size_t)(sizeof(struct node)))))
                                                          ? (((__0__X1->base__4node = 0),
                                                              (__0__X1->permanent__4node = 0)),
                                                             (__0__X1->baseclass__4node = 0))
                                                          : 0),
                                                     __0__X1))),
                                       (__0__X5->defined__4type = 0)),
                                      (__0__X5->lex_level__4type = 0)),
                                     (__0__X5->templ_base__4type = 0)),
                                    (__0__X5->in_class__4type = 0)),
                                   (__0__X5->nested_sig__4type = 0)),
                                  (__0__X5->local_sig__4type = 0)),
                                 (__0__X5->b_const__4type = 0)),
                                (__0__X5->ansi_const__4type = 0))
                             : 0),
                        __0__X5))),
          (__0this->fct_list__3gen = 0)),
         (__0this->holds_templ__3gen = 0));

        __0this->base__4node = 76;
    }
    return __0this;
}

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

void introduce_global_name__FP4name(Pname __1ft) {
    Pname __1n;

    __1n = look__5tableFPCcUc(gtbl, __1ft->__O2__4expr.string, (unsigned char)0);
    if (__1n == 0) {
        Pname __2nn;

        __2nn = insert__5tableFP4nameUc(
            gtbl, __ct__4nameFPCc((struct name *)0, __1ft->__O2__4expr.string), (unsigned char)0);
        __2nn->n_template_fct__4name = 1;
        if (__1ft->n_sto__4name == 18) {
            __2nn->n_scope__4name = 14;
        }
        __2nn->__O1__4expr.tp = __1ft->__O1__4expr.tp;
        __2nn->permanent__4node = 1;
    } else {
        switch (__1n->__O1__4expr.tp->base__4node) {
        default: {
            struct ea __0__V39;

            struct ea __0__V40;

            error__FPCcRC2eaN32(
                (const char *)"YF%n renamed object ofT%t",
                (const struct ea *)(((&__0__V39)->__O1__2ea.p = ((const void *)__1ft)),
                                    (&__0__V39)),
                (const struct ea *)__ct__2eaFPCv(&__0__V40, (const void *)__1n->__O1__4expr.tp),
                (const struct ea *)ea0, (const struct ea *)ea0);
            break;
        case 76: {
            Pname __4n2;

            __4n2 = add__3genFP4name(((struct gen *)(((struct gen *)__1n->__O1__4expr.tp))), __1ft);
            __4n2->n_template_fct__4name++;
            __1n->n_template_fct__4name++;
        } break;
        case 108: {
            Pgen __4g;

            __4g = __ct__3genFv((struct gen *)0);
            __4g->permanent__4node = 1;
            add_first = 1;
            ((void)add__3genFP4name(__4g, __1n));
            add_first = 0;
            {
                Pname __4n2;

                __4n2 = add__3genFP4name(__4g, __1ft);
                __4n2->n_template_fct__4name++;
                __1n->__O1__4expr.tp = (struct type *)__4g;
                __1n->n_template_fct__4name++;
            }
        } break;
        }
        }
    }
}

extern void check_formals_for_dups__FP9name_list(Plist __0formals);

struct templ *__ct__5templFP9name_listP4name(struct templ *__0this, Plist, Pname);

void introduce_class_templ__17templ_compilationFP4name(register struct templ_compilation *__0this,
                                                       Pname __1namep) {
    owner__17templ_compilation = is_template__17templ_compilationFP4name(__0this, __1namep);
    if (!owner__17templ_compilation) {
        check_formals_for_dups__FP9name_list(params__17templ_compilation);

        owner__17templ_compilation = __ct__5templFP9name_listP4name(
            (struct templ *)0, params__17templ_compilation, __1namep);
        {
            Pname __2nn;
            Pname __2lookup_name;

            __2nn = __ct__4nameFPCc((struct name *)0, __1namep->__O2__4expr.string);
            __2lookup_name =
                insert__5tableFP4nameUc(templates__17templ_compilation, __2nn, (unsigned char)0);
            __2lookup_name->__O1__4expr.tp =
                (((struct type *)(((struct type *)owner__17templ_compilation))));
        }
    }
}

struct function_template *
__ct__17function_templateFP9name_listP4name(struct function_template *__0this, Plist, Pname);

void introduce_funct_templ__17templ_compilationFP4name(register struct templ_compilation *__0this,
                                                       Pname __1namep) {
    Pfunt __1t;
    Pname __1n;

    __1t = __ct__17function_templateFP9name_listP4name((struct function_template *)0,
                                                       params__17templ_compilation, __1namep);
    __1n = look__5tableFPCcUc(templates__17templ_compilation, __1namep->__O2__4expr.string,
                              (unsigned char)108);

    if (__1n == 0) {
        Pname __2nn;

        __2nn = __ct__4nameFPCc((struct name *)0, __1namep->__O2__4expr.string);
        __1n = insert__5tableFP4nameUc(templates__17templ_compilation, __2nn, (unsigned char)108);
    } else
        __1t->gen_list__17function_template =
            (((struct function_template *)(((struct function_template *)__1n->__O1__4expr.tp))));
    __1n->__O1__4expr.tp = (((struct type *)(((struct type *)__1t))));
    f_owner__17templ_compilation = __1t;
    introduce_global_name__FP4name(__1namep);
}

static int has_formal_type__FP14templ_classdefP9name_list(Ptclass __1pt_cl, Plist __1list) {
    int __1has_formal;

    __1has_formal = 0;
    {
        {
            Pexpr __1formals;

            __1formals = __1pt_cl->inst__14templ_classdef->actuals__10basic_inst;

            for (; __1formals; __1formals = __1formals->__O3__4expr.e2) {
                Pexpr __2fe;

                __2fe = __1formals->__O2__4expr.e1;
                if (((__2fe->base__4node != 85) || (!__2fe->__O1__4expr.tp)) ||
                    (__2fe->__O1__4expr.tp->base__4node != 97))
                    continue;
                {
                    Pname __2tn;

                    struct type *__0__X41;

                    __2tn = ((__0__X41 = __2fe->__O1__4expr.tp),
                             ((((struct basetype *)(((struct basetype *)__0__X41))))
                                  ->b_name__8basetype));
                    if (!((((unsigned char)(__2tn->n_template_arg__4name == 1)))))
                        continue;

                    __1list = (__1list->l__9name_list = __ct__9name_listFP4nameP9name_list(
                                   (struct name_list *)0, __2tn, (struct name_list *)0));
                    ++__1has_formal;
                }
            }
            return __1has_formal;
        }
    }
}

static Pname Tmpl;

Pptr is_ptr__4typeFv(struct type *__0this);

Pptr is_ref__4typeFv(struct type *__0this);

Pclass classtype__4typeFv(struct type *__0this);

static int has_formal_type__FP4nameP9name_list(Pname __1nn, Plist __1list) {
    Pname __1bn;
    Ptype __1t;

    Ptype __1nt;

    __1nt = __1nn->__O1__4expr.tp;

    while (__1t = (struct type *)is_ptr__4typeFv(__1nt))
        __1nt = (((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp;
    while (__1t = (struct type *)is_ref__4typeFv(__1nt))
        __1nt = (((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp;

    if (__1nt->base__4node != 97)
        return 0;
    while (__1nt->base__4node == 97) {
        __1bn = ((((struct basetype *)(((struct basetype *)__1nt))))->b_name__8basetype);
        __1nt = __1bn->__O1__4expr.tp;
    }

    if (__1nt->base__4node == 119) {
        Pclass __2c1;

        int __1__Xt00awz144hdwckg;

        __2c1 = classtype__4typeFv(__1nt);
        if (((__1__Xt00awz144hdwckg =
                  ((((struct type *)__2c1)->base__4node == 108)
                       ? (((struct fct *)(((struct fct *)((struct type *)__2c1)))))->fct_base__3fct
                       : ((((struct type *)__2c1)->base__4node == 6)
                              ? (((struct classdef *)(((struct classdef *)((struct type *)__2c1)))))
                                    ->class_base__8classdef
                              : (((int)0))))),
             (((unsigned char)((__1__Xt00awz144hdwckg == 4) || (__1__Xt00awz144hdwckg == 5))))))
            return has_formal_type__FP14templ_classdefP9name_list(
                ((struct templ_classdef *)(((struct templ_classdef *)__2c1))), __1list);

        if (__2c1->class_base__8classdef == 2) {
            Tmpl = __1bn;
            return -1;
        }
    }

    if (((((unsigned char)(__1bn->n_template_arg__4name == 1))))) {
        __1list = (__1list->l__9name_list = __ct__9name_listFP4nameP9name_list(
                       (struct name_list *)0, __1bn, (struct name_list *)0));
        return (int)1;
    }
    return (int)0;
}

static bit hbf = 0;
struct bleh__handle_bound_friend__FP14basic_templateP4name__L42;

int get_formals_count__14basic_templateFv(struct basic_template *__0this);

struct
    bleh__handle_bound_friend__FP14basic_templateP4name__L42 { /* sizeof
                                                                  bleh__handle_bound_friend__FP14basic_templateP4name__L42
                                                                  == 16 */

    Pname n__56bleh__handle_bound_friend__FP14basic_templateP4name__L42;

    int used__56bleh__handle_bound_friend__FP14basic_templateP4name__L42;
};

struct templ_state *__ct__11templ_stateFv(struct templ_state *__0this);

void end__17templ_compilationFP4name(struct templ_compilation *__0this, Pname __1class_name);

struct templ_state { /* sizeof templ_state == 56 */

    Plist param_end__11templ_state;
    Plist params__11templ_state;
    Pcons templ_refs__11templ_state;
    Pcons friend_templ_refs__11templ_state;
    Pcons last_cons__11templ_state;
    Pcons last_friend_cons__11templ_state;
    Ptempl owner__11templ_state;
};

void __dt__11templ_stateFv(struct templ_state *__0this, int);

void handle_bound_friend__FP14basic_templateP4name(Ptempl_base __1pb, Pname __1fn) {
    Plist __1formals;

    Plist __1f_list;
    int __1i;

    int __1formal_cnt;
    Pfct __1f;

    struct bleh__handle_bound_friend__FP14basic_templateP4name__L42 *__1pbleh;

    unsigned long __2__X16;

    struct ea __0__X__V1400q2z144hdwckg;

    struct ea __0__X__V1500q2z144hdwckg;

    __1f_list = __ct__9name_listFP4nameP9name_list((struct name_list *)0, (struct name *)0,
                                                   (struct name_list *)0);
    __1i = 0;

    __1formal_cnt = get_formals_count__14basic_templateFv(__1pb);
    __1f =
        (((__1fn->__O1__4expr.tp->base__4node == 108)
              ? (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))))
              : (error__FiPCcRC2eaN33(
                     (int)'i', (const char *)"N::fct_type():%n is %k notF",
                     (const struct ea *)(((&__0__X__V1400q2z144hdwckg)->__O1__2ea.p =
                                              ((const void *)__1fn)),
                                         (&__0__X__V1400q2z144hdwckg)),
                     (const struct ea *)((__2__X16 = __1fn->__O1__4expr.tp->base__4node),
                                         (((((&__0__X__V1500q2z144hdwckg)->__O1__2ea.i = __2__X16),
                                            0)),
                                          (&__0__X__V1500q2z144hdwckg))),
                     (const struct ea *)ea0, (const struct ea *)ea0),
                 (((struct fct *)0)))));
    if (__1f->body__3fct)
        return;

    ;
    __1pbleh = (((struct bleh__handle_bound_friend__FP14basic_templateP4name__L42 *)__nw__FUl(
        (size_t)((sizeof(struct bleh__handle_bound_friend__FP14basic_templateP4name__L42)) *
                 __1formal_cnt))));

    for (__1formals = (__1pb->formals__14basic_template); __1formals;
         __1formals = __1formals->l__9name_list) {
        (__1pbleh[__1i]).n__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 =
            __1formals->f__9name_list;

        (__1pbleh[(__1i++)]).used__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 = 0;
    }

    {
        int __1has_formal;

        __1has_formal = 0;

        {
            {
                Pname __1n;

                __1n = __1f->argtype__3fct;

                for (; __1n; __1n = __1n->__O1__4name.n_list)
                    __1has_formal += has_formal_type__FP4nameP9name_list(__1n, __1f_list);

                if (!__1has_formal)
                    return;

                if (__1has_formal == -1) {
                    if (strcmp(Tmpl->__O2__4expr.string,
                               (((struct templ *)(((struct templ *)__1pb))))
                                   ->namep__5templ->__O2__4expr.string))
                        return;

                } else
                    for (__1formals = __1f_list->l__9name_list; __1formals;
                         __1formals = __1formals->l__9name_list) {
                        Pname __2n;

                        __2n = __1formals->f__9name_list;
                        if (!__2n)
                            break;
                        for (__1i = 0; __1i < __1formal_cnt; ++__1i)
                            if (strcmp(
                                    __2n->__O2__4expr.string,
                                    (__1pbleh[__1i])
                                        .n__56bleh__handle_bound_friend__FP14basic_templateP4name__L42
                                        ->__O2__4expr.string) == 0) {
                                (__1pbleh[__1i])
                                    .used__56bleh__handle_bound_friend__FP14basic_templateP4name__L42++;

                                break;
                            }
                    }

                save_templ__17templ_compilation = __ct__11templ_stateFv((struct templ_state *)0);
                params__17templ_compilation = (param_end__17templ_compilation = 0);
                for (__1i = 0; __1i < __1formal_cnt; ++__1i) {
                    if (((__1pbleh[__1i])
                             .used__56bleh__handle_bound_friend__FP14basic_templateP4name__L42 ==
                         0) &&
                        (__1has_formal != -1))
                        continue;
                    append_parameter__17templ_compilationFP4name(
                        templp, (__1pbleh[__1i])
                                    .n__56bleh__handle_bound_friend__FP14basic_templateP4name__L42);
                }

                owner__17templ_compilation = 0;
                hbf = 1;
                end__17templ_compilationFP4name(templp, __1fn);
                __1f->fct_base__3fct = 1;

                {
                    Ptempl_base __1fr;

                    __1fr = parsed_template__17templ_compilation;
                    __dt__11templ_stateFv(save_templ__17templ_compilation, 3);

                    save_templ__17templ_compilation = 0;

                    {
                        Pclass __1cl;

                        struct cons *__0__X43;

                        struct cons *__2__X44;

                        __1cl = ((((struct classdef *)((
                            (struct classdef *)(((struct templ *)(((struct templ *)__1pb))))
                                ->basep__5templ->b_name__8basetype->__O1__4expr.tp)))));
                        __1cl->templ_friends__8classdef =
                            ((__0__X43 = 0), ((__2__X44 = __1cl->templ_friends__8classdef),
                                              (((__0__X43 || (__0__X43 = (struct cons *)__nw__FUl(
                                                                  (size_t)(sizeof(struct cons)))))
                                                    ? ((__0__X43->car__4cons = ((void *)__1fr)),
                                                       (__0__X43->cdr__4cons = __2__X44))
                                                    : 0),
                                               __0__X43)));
                        __1fr->extrapolated__14basic_template = 1;
                        if (hbf == 1)
                            __1fr->templ_refs__14basic_template =
                                friend_templ_refs__17templ_compilation;
                        hbf = 0;
                    }
                }
            }
        }
    }
}

void check_oper__4nameFP4name(struct name *__0this, Pname);

extern int error__FPCc(const char *);

void check_templ_funct__FP4name(Pname __1fn) {
    Pfct __1f;

    __1f = (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))));

    {
        {
            Pname __1al;

            __1al = __1f->argtype__3fct;

            for (; __1al; __1al = __1al->__O1__4name.n_list) {
                if (__1al->__O3__4expr.n_initializer) {
                    error__FiPCc((int)'s', (const char *)"FYs do not support defaultAs");
                    break;
                }
            }

            if (__1f->nargs_known__3fct != 1) {
                struct ea __0__V45;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"ellipsis (...) inA list ofYF%n",
                    (const struct ea *)(((&__0__V45)->__O1__2ea.p = ((const void *)__1fn)),
                                        (&__0__V45)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__1fn->n_oper__4name) {
                switch (__1f->nargs__3fct) {
                case 1:
                case 2:
                    break;
                default:
                    if (__1fn->n_oper__4name != 23) {
                        struct ea __0__V46;

                        error__FPCcRC2eaN32(
                            (const char *)"FY%n must take 1 or 2As",
                            (const struct ea *)(((&__0__V46)->__O1__2ea.p = ((const void *)__1fn)),
                                                (&__0__V46)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }

                switch (__1fn->n_oper__4name) {
                    const void *__2__X49;

                    const void *__2__X50;

                case 109:
                case 111:
                case 44:
                case 70: {
                    struct ea __0__V47;

                    error__FPCcRC2eaN32(
                        (const char *)"YF operator%s must be aCM",
                        (const struct ea *)((__2__X49 = (const void *)(keys[__1fn->n_oper__4name])),
                                            (((&__0__V47)->__O1__2ea.p = __2__X49), (&__0__V47))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    return;
                case 212:
                case 9: {
                    struct ea __0__V48;

                    error__FPCcRC2eaN32(
                        (const char *)"::operator %s may not be aYF",
                        (const struct ea *)((__2__X50 = (const void *)(keys[__1fn->n_oper__4name])),
                                            (((&__0__V48)->__O1__2ea.p = __2__X50), (&__0__V48))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    return;
                default:
                    check_oper__4nameFP4name(__1fn, (struct name *)0);
                    break;
                }
                }
                }
            }

            if (strcmp((const char *)"main", __1fn->__O2__4expr.string) == 0)
                error__FPCc((const char *)"main() may not be aYF");
        }
    }
}

extern Pname k_find_name__FPCcP6ktableUc(const char *, Pktab, TOK);

extern const char *curr_filename__Fv(void);

extern int fprintf(void *, const char *, ...);

void clear_friend_ref_templ__17templ_compilationFv(struct templ_compilation *__0this);

extern void check_funct_formals__FP9name_listP4name(Plist __0formals, Pname __0namep);

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

Pfunt collect_function_member__5templFP4name(struct templ *__0this, Pname);
Pdata collect_data_member__5templFP4name(struct templ *__0this, Pname);

struct data_template { /* sizeof data_template == 64 */

    Plist formals__14basic_template;
    Pcons templ_refs__14basic_template;

    Pname Cdcl__14basic_template;
    Pstmt Cstmt__14basic_template;

    int open_instantiations__14basic_template;
    int extrapolated__14basic_template;

    struct __mptr *__vptr__14basic_template;

    Pname dat_mem__13data_template;
    Pdata next__13data_template;
};

void clear_ref_templ__17templ_compilationFv(struct templ_compilation *__0this);

void end__17templ_compilationFP4name(register struct templ_compilation *__0this, Pname __1p) {
    int __1forward_definition;

    __1forward_definition = 0;
    if (!__1p->__O1__4expr.tp) {
        error__FPCc((const char *)"aC,F,MF or static dataM definition wasX");
        return;
    }

    switch (__1p->__O1__4expr.tp->base__4node) {
    case 119:
        if (__1p->n_sto__4name == 18) {
            struct type *__0__X72;

            __1p = ((__0__X72 = __1p->__O1__4expr.tp),
                    ((((struct basetype *)(((struct basetype *)__0__X72))))->b_name__8basetype));

        } else {
            {
                struct ea __0__V51;

                error__FPCcRC2eaN32(
                    (const char *)"illegalY %n",
                    (const struct ea *)(((&__0__V51)->__O1__2ea.p = ((const void *)__1p)),
                                        (&__0__V51)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                return;
            }
        }

    case 6: {
        Pname __3namep;

        __3namep = k_find_name__FPCcP6ktableUc(__1p->__O2__4expr.string, Gtbl, (unsigned char)159);
        if ((__3namep == 0) || (__3namep->base__4node == 85)) {
            const char *__4s;

            __4s = (__1p->__O2__4expr.string ? __1p->__O2__4expr.string : (((const char *)"")));
            if (((*__4s)) && ((((__4s[0]) != '_') || ((__4s[1]) != '_')) || ((__4s[2]) != 'C'))) {
                struct ea __0__V52;

                error__FPCcRC2eaN32(
                    (const char *)"nestedYC %s",
                    (const struct ea *)(((&__0__V52)->__O1__2ea.p = ((const void *)__4s)),
                                        (&__0__V52)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else {
                error__FPCc((const char *)"missingYN");
                return;
            }
        }

        owner__17templ_compilation = is_template__17templ_compilationFP4name(__0this, __3namep);
        if (owner__17templ_compilation) {
            Pclass __4c;

            const void *__2__X73;

            __4c =
                ((((struct classdef *)(((struct classdef *)owner__17templ_compilation->basep__5templ
                                            ->b_name__8basetype->__O1__4expr.tp)))));

            if (owner__17templ_compilation->defined__5templ &&
                ((((struct classdef *)(((struct classdef *)__1p->__O1__4expr.tp))))
                     ->mem_list__8classdef != owner__17templ_compilation->members__5templ)) {
                struct ea __0__V53;

                error__FPCcRC2eaN32(
                    (const char *)"YC %s multiply defined",
                    (const struct ea *)((__2__X73 = (const void *)__1p->__O2__4expr.string),
                                        (((&__0__V53)->__O1__2ea.p = __2__X73), (&__0__V53))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            __1forward_definition = (((int)((__4c->defined__4type & 04) &&
                                            (!owner__17templ_compilation->defined__5templ))));
            if (__1forward_definition)
                resolve_forward_decl__5templFP9name_listP8classdef(
                    owner__17templ_compilation, params__17templ_compilation, __4c);

            if (pt_opt && __1forward_definition)
                fprintf(pt_file, (const char *)"t %s %s\n", __1p->__O2__4expr.string,
                        curr_filename__Fv());
        } else
            introduce_class_templ__17templ_compilationFP4name(__0this, __3namep);

        if (owner__17templ_compilation->defined__5templ) {
            {
                {
                    Pname __4nn;

                    __4nn = (((struct classdef *)(((struct classdef *)__1p->__O1__4expr.tp))))
                                ->mem_list__8classdef;

                    for (; __4nn; __4nn = __4nn->__O1__4name.n_list) {
                        if (((__4nn->base__4node == 85) && (__4nn->n_sto__4name == 18)) &&
                            (__4nn->__O2__4name.n_qualifier == 0)) {

                            switch (__4nn->__O1__4expr.tp->base__4node) {
                            case 108:
                                handle_bound_friend__FP14basic_templateP4name(
                                    (struct basic_template *)owner__17templ_compilation, __4nn);
                                break;
                            case 76:
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (templ_refs__17templ_compilation)
            owner__17templ_compilation->templ_refs__14basic_template =
                templ_refs__17templ_compilation;
        clear_friend_ref_templ__17templ_compilationFv(templp);
        break;
    }

    case 108: {
        unsigned long __2__X16;

        struct ea __0__X__V1400q2z144hdwckg;

        struct ea __0__X__V1500q2z144hdwckg;

        if ((pt_opt &&
             (!(((__1p->__O1__4expr.tp->base__4node == 108)
                     ? (((struct fct *)(((struct fct *)__1p->__O1__4expr.tp))))
                     : (error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"N::fct_type():%n is %k notF",
                            (const struct ea *)(((&__0__X__V1400q2z144hdwckg)->__O1__2ea.p =
                                                     ((const void *)__1p)),
                                                (&__0__X__V1400q2z144hdwckg)),
                            (const struct ea
                                 *)((__2__X16 = __1p->__O1__4expr.tp->base__4node),
                                    (((((&__0__X__V1500q2z144hdwckg)->__O1__2ea.i = __2__X16), 0)),
                                     (&__0__X__V1500q2z144hdwckg))),
                            (const struct ea *)ea0, (const struct ea *)ea0),
                        (((struct fct *)0)))))
                   ->body__3fct)) &&
            (!__1p->__O2__4name.n_qualifier))
            fprintf(pt_file, (const char *)"f %s %s\n", __1p->__O2__4expr.string,
                    curr_filename__Fv());

        {
            Pname __3qual;

            __3qual = __1p->__O2__4name.n_qualifier;
            if (!__3qual) {
                check_funct_formals__FP9name_listP4name(params__17templ_compilation, __1p);
                check_templ_funct__FP4name(__1p);
                f_owner__17templ_compilation = is_template__17templ_compilationFPCcUc(
                    __0this, __1p->__O2__4expr.string, (unsigned char)108);
                if (!f_owner__17templ_compilation)
                    introduce_funct_templ__17templ_compilationFP4name(__0this, __1p);
                else {
                    Pfunt __5tl;
                    Pname __5fn;
                    Pfct __5n_fct;

                    int __5error_cnt;

                    unsigned long __2__X16;

                    struct ea __0__X__V1400q2z144hdwckg;

                    struct ea __0__X__V1500q2z144hdwckg;

                    __5tl = f_owner__17templ_compilation;
                    __5fn = 0;
                    __5n_fct = ((
                        (__1p->__O1__4expr.tp->base__4node == 108)
                            ? (((struct fct *)(((struct fct *)__1p->__O1__4expr.tp))))
                            : (error__FiPCcRC2eaN33(
                                   (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                   (const struct ea *)(((&__0__X__V1400q2z144hdwckg)->__O1__2ea.p =
                                                            ((const void *)__1p)),
                                                       (&__0__X__V1400q2z144hdwckg)),
                                   (const struct ea *)((__2__X16 =
                                                            __1p->__O1__4expr.tp->base__4node),
                                                       (((((&__0__X__V1500q2z144hdwckg)
                                                               ->__O1__2ea.i = __2__X16),
                                                          0)),
                                                        (&__0__X__V1500q2z144hdwckg))),
                                   (const struct ea *)ea0, (const struct ea *)ea0),
                               (((struct fct *)0)))));

                    __5error_cnt = 0;
                    for (__5fn = __5tl->fn__17function_template; __5tl;
                         ((__5tl = __5tl->gen_list__17function_template),
                          (__5fn =
                               (__5tl ? __5tl->fn__17function_template : (((struct name *)0)))))) {
                        extern bit return_error;

                        if (check__4typeFP4typeUcT2((struct type *)__5n_fct, __5fn->__O1__4expr.tp,
                                                    (unsigned char)204, (unsigned char)0) == 0)
                            break;
                        if (__5error_cnt = return_error)
                            break;
                    }
                    if (__5error_cnt) {
                        struct ea __0__V54;

                        error__FPCcRC2eaN32(
                            (const char *)"FY%n: declared twice with different returnTs",
                            (const struct ea *)(((&__0__V54)->__O1__2ea.p = ((const void *)__1p)),
                                                (&__0__V54)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    if (__5tl == 0)
                        introduce_funct_templ__17templ_compilationFP4name(__0this, __1p);
                    else {
                        int __6f1;

                        int __6f2;

                        int __6extrap;
                        Pfct __6o_fct;

                        unsigned long __2__X16;

                        struct ea __0__X__V1400q2z144hdwckg;

                        struct ea __0__X__V1500q2z144hdwckg;

                        __6extrap = 0;
                        __6o_fct =
                            (((__5fn->__O1__4expr.tp->base__4node == 108)
                                  ? (((struct fct *)(((struct fct *)__5fn->__O1__4expr.tp))))
                                  : (error__FiPCcRC2eaN33(
                                         (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                         (const struct ea *)(((&__0__X__V1400q2z144hdwckg)
                                                                  ->__O1__2ea.p =
                                                                  ((const void *)__5fn)),
                                                             (&__0__X__V1400q2z144hdwckg)),
                                         (const struct ea
                                              *)((__2__X16 = __5fn->__O1__4expr.tp->base__4node),
                                                 (((((&__0__X__V1500q2z144hdwckg)->__O1__2ea.i =
                                                         __2__X16),
                                                    0)),
                                                  (&__0__X__V1500q2z144hdwckg))),
                                         (const struct ea *)ea0, (const struct ea *)ea0),
                                     (((struct fct *)0)))));
                        if ((__6f1 = (__5n_fct->body__3fct != 0)) &&
                            (__6f2 = (__6o_fct->body__3fct != 0))) {
                            struct ea __0__V55;

                            struct ea __0__V56;

                            struct ea __0__V57;

                            error__FPCcRC2eaN32((const char *)"two definitions ofYF%n (%t %t)",
                                                (const struct ea *)(((&__0__V55)->__O1__2ea.p =
                                                                         ((const void *)__5fn)),
                                                                    (&__0__V55)),
                                                (const struct ea *)(((&__0__V56)->__O1__2ea.p =
                                                                         ((const void *)__6o_fct)),
                                                                    (&__0__V56)),
                                                (const struct ea *)(((&__0__V57)->__O1__2ea.p =
                                                                         ((const void *)__5n_fct)),
                                                                    (&__0__V57)),
                                                (const struct ea *)ea0);
                        }
                        __6extrap = ((((struct basic_template *)f_owner__17templ_compilation)
                                              ->extrapolated__14basic_template
                                          ? 1
                                          : 0));
                        if ((__1forward_definition = (((int)(__6f1 && (__6f2 == 0))))) ||
                            __6extrap) {
                            __5tl->formals__14basic_template = params__17templ_compilation;
                            __5tl->fn__17function_template = __1p;
                            __5tl->templ_refs__14basic_template = templ_refs__17templ_compilation;
                            f_owner__17templ_compilation = __5tl;
                        } else if (hbf == 1)
                            hbf = 2;
                    }
                }
                if ((f_owner__17templ_compilation->templ_refs__14basic_template == 0) && (hbf != 2))
                    f_owner__17templ_compilation->templ_refs__14basic_template =
                        templ_refs__17templ_compilation;
                break;
            }

            {
                Pbase __3q;

                unsigned long __2__X16;

                struct ea __0__X__V1400q2z144hdwckg;

                struct ea __0__X__V1500q2z144hdwckg;

                __3q = (((struct basetype *)(((struct basetype *)__3qual->__O1__4expr.tp))));
                if (__3q && (__3q->base__4node == 119))
                    switch (get_class_base__FP8basetype(__3q)) {
                    case 5:
                        owner__17templ_compilation =
                            (((struct templ_classdef *)(((struct templ_classdef *)__3q
                                                             ->b_name__8basetype->__O1__4expr.tp))))
                                ->inst__14templ_classdef->def__10templ_inst;

                        if (!check_qualifier__10templ_instFP9name_list(
                                get_template_class__FP8basetype(__3q)->inst__14templ_classdef,
                                params__17templ_compilation))
                            error__FPCc((const char *)"QrZs must match theY formalZs");
                        break;
                    case 2: {
                        struct ea __0__V58;

                        struct ea __0__V59;

                        error__FPCcRC2eaN32(
                            (const char *)"Qr%n for%n must specifyYZs",
                            (const struct ea *)(((&__0__V58)->__O1__2ea.p =
                                                     ((const void *)__3qual)),
                                                (&__0__V58)),
                            (const struct ea *)(((&__0__V59)->__O1__2ea.p = ((const void *)__1p)),
                                                (&__0__V59)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                        break;
                    default: {
                        Pclass __5cl;

                        __5cl = (((struct classdef *)((
                            (struct classdef *)__3q->b_name__8basetype->__O1__4expr.tp))));
                        if ((__5cl && __5cl->in_class__4type) &&
                            __5cl->in_class__4type->class_base__8classdef) {
                            struct ea __0__V60;

                            struct ea __0__V61;

                            error__FiPCcRC2eaN33(
                                (int)'s',
                                (const char
                                     *)"out-of-line definition ofMF ofC nestedWinYC (%t::%n)",
                                (const struct ea *)(((&__0__V60)->__O1__2ea.p =
                                                         ((const void *)__5cl)),
                                                    (&__0__V60)),
                                (const struct ea *)(((&__0__V61)->__O1__2ea.p =
                                                         ((const void *)__1p)),
                                                    (&__0__V61)),
                                (const struct ea *)ea0, (const struct ea *)ea0);
                        } else {
                            struct ea __0__V62;

                            struct ea __0__V63;

                            error__FPCcRC2eaN32((const char *)"Qr%n for%n wasn't aYC",
                                                (const struct ea *)(((&__0__V62)->__O1__2ea.p =
                                                                         ((const void *)__3qual)),
                                                                    (&__0__V62)),
                                                (const struct ea *)(((&__0__V63)->__O1__2ea.p =
                                                                         ((const void *)__1p)),
                                                                    (&__0__V63)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                        }
                        return;
                    }
                    }
                    }
                if (!(((__1p->__O1__4expr.tp->base__4node == 108)
                           ? (((struct fct *)(((struct fct *)__1p->__O1__4expr.tp))))
                           : (error__FiPCcRC2eaN33(
                                  (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                  (const struct ea *)(((&__0__X__V1400q2z144hdwckg)->__O1__2ea.p =
                                                           ((const void *)__1p)),
                                                      (&__0__X__V1400q2z144hdwckg)),
                                  (const struct ea
                                       *)((__2__X16 = __1p->__O1__4expr.tp->base__4node),
                                          (((((&__0__X__V1500q2z144hdwckg)->__O1__2ea.i = __2__X16),
                                             0)),
                                           (&__0__X__V1500q2z144hdwckg))),
                                  (const struct ea *)ea0, (const struct ea *)ea0),
                              (((struct fct *)0)))))
                         ->body__3fct) {
                    struct ea __0__V64;

                    struct ea __0__V65;

                    error__FPCcRC2eaN32(
                        (const char *)"QdN%n::%n inYFD",
                        (const struct ea *)(((&__0__V64)->__O1__2ea.p = ((const void *)__3qual)),
                                            (&__0__V64)),
                        (const struct ea *)(((&__0__V65)->__O1__2ea.p = ((const void *)__1p)),
                                            (&__0__V65)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
                if (owner__17templ_compilation) {
                    Pfunt __4ft;

                    __4ft =
                        collect_function_member__5templFP4name(owner__17templ_compilation, __1p);
                    __4ft->templ_refs__14basic_template = templ_refs__17templ_compilation;
                    __4ft->formals__14basic_template = params__17templ_compilation;
                    check_formals__14basic_templateFP9name_list(
                        (struct basic_template *)owner__17templ_compilation,
                        params__17templ_compilation);
                } else
                    error__FPCc((const char *)"memberFY must beQd byCYN");
                break;
            }
        }
    }

    default: {
        Pname __3qual;

        __3qual = __1p->__O2__4name.n_qualifier;
        if (!__3qual) {
            {
                struct ea __0__V66;

                error__FPCcRC2eaN32(
                    (const char *)"%n: only static dataCMs may beZized",
                    (const struct ea *)(((&__0__V66)->__O1__2ea.p = ((const void *)__1p)),
                                        (&__0__V66)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                return;
            }
        }

        {
            Pbase __3q;

            __3q = (((struct basetype *)(((struct basetype *)__3qual->__O1__4expr.tp))));
            if (__3q && (__3q->base__4node == 119))
                switch (get_class_base__FP8basetype(__3q)) {
                case 5:
                    owner__17templ_compilation =
                        (((struct templ_classdef *)((
                             (struct templ_classdef *)__3q->b_name__8basetype->__O1__4expr.tp))))
                            ->inst__14templ_classdef->def__10templ_inst;
                    if (!check_qualifier__10templ_instFP9name_list(
                            get_template_class__FP8basetype(__3q)->inst__14templ_classdef,
                            params__17templ_compilation)) {
                        struct ea __0__V67;

                        error__FPCcRC2eaN32(
                            (const char *)"%n: QrZs must match theY formalZs",
                            (const struct ea *)(((&__0__V67)->__O1__2ea.p = ((const void *)__1p)),
                                                (&__0__V67)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    break;
                case 2: {
                    struct ea __0__V68;

                    struct ea __0__V69;

                    error__FPCcRC2eaN32(
                        (const char *)"Qr%n for%n must specifyYZs",
                        (const struct ea *)(((&__0__V68)->__O1__2ea.p = ((const void *)__3qual)),
                                            (&__0__V68)),
                        (const struct ea *)(((&__0__V69)->__O1__2ea.p = ((const void *)__1p)),
                                            (&__0__V69)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    break;
                default: {
                    struct ea __0__V70;

                    struct ea __0__V71;

                    error__FPCcRC2eaN32(
                        (const char *)"Qr%n for%n wasn't aYC",
                        (const struct ea *)(((&__0__V70)->__O1__2ea.p = ((const void *)__3qual)),
                                            (&__0__V70)),
                        (const struct ea *)(((&__0__V71)->__O1__2ea.p = ((const void *)__1p)),
                                            (&__0__V71)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    return;
                }
                }
                }
            {
                Pdata __3dat;

                __3dat = collect_data_member__5templFP4name(owner__17templ_compilation, __1p);
                __3dat->templ_refs__14basic_template = templ_refs__17templ_compilation;
                __3dat->formals__14basic_template = params__17templ_compilation;
                check_formals__14basic_templateFP9name_list(
                    (struct basic_template *)owner__17templ_compilation,
                    params__17templ_compilation);
                break;
            }
        }
    }
    }

    clear_ref_templ__17templ_compilationFv(__0this);
    param_end__17templ_compilation = (params__17templ_compilation = 0);
    if (__1forward_definition) {
        if (owner__17templ_compilation)
            instantiate_forward_decl__5templFv(owner__17templ_compilation);
        else {
            instantiate_forward_decl__17function_templateFv(f_owner__17templ_compilation);
        }
    }

    parsed_template__17templ_compilation =
        (owner__17templ_compilation
             ? (((struct basic_template *)(((struct basic_template *)owner__17templ_compilation))))
             : (((struct basic_template *)((
                   (struct basic_template *)f_owner__17templ_compilation)))));
    owner__17templ_compilation = 0;
    f_owner__17templ_compilation = 0;
}

void clear_friend_ref_templ__17templ_compilationFv(register struct templ_compilation *__0this) {
    {
        {
            Pcons __1p;

            __1p = friend_templ_refs__17templ_compilation;

            for (; __1p; __1p = __1p->cdr__4cons)
                (((struct templ_inst *)(((struct templ_inst *)__1p->car__4cons))))
                    ->friend_refp__10templ_inst = 0;
            friend_templ_refs__17templ_compilation = 0;
            last_friend_cons__17templ_compilation = 0;
        }
    }
}

void clear_ref_templ__17templ_compilationFv(register struct templ_compilation *__0this) {
    {
        {
            Pcons __1p;

            __1p = templ_refs__17templ_compilation;

            for (; __1p; __1p = __1p->cdr__4cons)
                (((struct templ_inst *)(((struct templ_inst *)__1p->car__4cons))))
                    ->refp__10templ_inst = 0;
            templ_refs__17templ_compilation = 0;
            last_cons__17templ_compilation = 0;
        }
    }
}

void instantiate_ref_templ__17templ_compilationFv(register struct templ_compilation *__0this) {
    {
        {
            Pcons __1p;

            __1p = templ_refs__17templ_compilation;

            for (; __1p; __1p = __1p->cdr__4cons) {
                if (__1p->cdr__4cons)
                    notinstflag = 1;
                else
                    notinstflag = 0;
                instantiate__10templ_instF4bool(
                    ((struct templ_inst *)(((struct templ_inst *)__1p->car__4cons))), 0);
            }
            clear_ref_templ__17templ_compilationFv(__0this);
        }
    }
}

static void data_copy_hook__FPvRP4node10node_classR16tree_node_actionRi(
    void *__1__A74, Pnode *__1node, int __1__A75, int *__1action, int *__1never_see_again) {
    ((*__1never_see_again)) = 1;
    switch (((*__1node))->base__4node) {
    case 85:
        if (((*__1node)) == (((struct node *)sta_name))) {
            ((*__1action)) = 1;

            return;
        }
    default:
        ((*__1action)) = 0;
        return;
    }
}

int *__vc__4HashFi(struct Hash *__0this, int __1k);

Pcons ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons(struct basic_inst *__0this,
                                                                    struct pointer_hash *,
                                                                    struct tree_copy_info *, Pcons);

extern void copy_tree__FRP4nodeR14tree_copy_infoP4Hash(Pnode *__0n, struct tree_copy_info *__0tci,
                                                       struct Hash *__0cht);

Pname data_copy__10templ_instFP13data_templateRP4cons(register struct templ_inst *__0this,
                                                      Pdata __1dat, Pcons *__1templ_refs) {
    struct pointer_hash __1fcorr;

    struct name *__0_result;

    struct pointer_hash *__2__X76;

    ((__2__X76 = __0this->corr__10basic_inst),
     ((__ct__4HashFR4Hash(((struct Hash *)(&__1fcorr)), (struct Hash *)__2__X76)), (&__1fcorr)));

    {
        struct tree_copy_info __2info;
        Pnode __2root;

        (((((&__2info)->hook_info__14tree_copy_info = 0),
           (((&__2info)->node_hook__14tree_copy_info = 0),
            ((&__2info)->malloc_hook__14tree_copy_info = 0)))),
         (&__2info));
        __2root = (struct node *)__1dat->dat_mem__13data_template;

        {
            {
                Plist __2fformal;

                Plist __2cformal;

                __2fformal = __1dat->formals__14basic_template;

                __2cformal = __0this->inst_formals__10basic_inst;

                for (; __2fformal; ((__2fformal = __2fformal->l__9name_list),
                                    (__2cformal = __2cformal->l__9name_list))) {
                    ((*__vc__4HashFi((struct Hash *)(&__1fcorr),
                                     (int)(((unsigned long)__2fformal->f__9name_list))))) =
                        (((unsigned long)__2cformal->f__9name_list));
                    if (((*__vc__4HashFi((struct Hash *)(&__1fcorr),
                                         (int)(((unsigned long)__2fformal->f__9name_list))))) !=
                        (((unsigned long)__2cformal->f__9name_list)))
                        error__FiPCc((int)'i',
                                     (const char *)"templ_inst::fuction_copy: hash table bug");
                }

                __2info.node_hook__14tree_copy_info =
                    (data_copy_hook__FPvRP4node10node_classR16tree_node_actionRi);
                __2info.hook_info__14tree_copy_info = (void *)__0this;

                ((*__1templ_refs)) = ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons(
                    (struct basic_inst *)__0this, (struct pointer_hash *)(&__1fcorr),
                    (struct tree_copy_info *)(&__2info), (*__1templ_refs));
                if (((*__vc__4HashFi(
                        (struct Hash *)(&__1fcorr),
                        (int)(((unsigned long)__0this->def__10templ_inst->namep__5templ))))) !=
                    (((unsigned long)__0this->tname__10basic_inst)))
                    error__FiPCc((int)'i',
                                 (const char *)"Y to instantiationTN correspondence is missing");

                copy_tree__FRP4nodeR14tree_copy_infoP4Hash((Pnode *)(&__2root),
                                                           (struct tree_copy_info *)(&__2info),
                                                           (struct Hash *)(&__1fcorr));
                {
                    {
                        __0_result = (((struct name *)(((struct name *)__2root))));

                        ((((void)((
                            (void)((((((struct Hash *)(&__1fcorr)))
                                         ? (((void)(__dl__FPv((void *)(((struct Hash *)(&__1fcorr)))
                                                                  ->tab__4Hash),
                                                    ((((struct Hash *)(&__1fcorr)))
                                                         ? (((void)(((void)0))))
                                                         : (((void)0))))))
                                         : (((void)0)))),
                                   (((void)0))))))));
                    }
                    return __0_result;
                }
            }
        }
    }
}

int instantiate_bodies__5templFv(struct templ *__0this);

void end_of_compilation__17templ_compilationFv(struct templ_compilation *__0this) {
    int __1change;

    __1change = 0;
    do {
        __1change = 0;
        {
            {
                Ptempl __2p;

                __2p = list__17templ_compilation;

                for (; __2p; __2p = __2p->next__5templ)
                    __1change = ((__1change | instantiate_bodies__5templFv(__2p)) ? 1 : 0);
            }
        }
    } while (__1change);
}

bit dinst_body__4nameFv(register struct name *__0this) {
    if (((((data_flag == 0) && (all_flag == 0)) && (alltc_flag == 0)) &&
         (curr_inst == dummyinst)) &&
        (curr_inst != 0))
        return (unsigned char)0;

    if (((all_flag == 0) && (curr_inst != dummyinst)) && (curr_inst != 0))
        return (unsigned char)0;

    {
        bit __1instflag;

        __1instflag = 0;

        {
            {
                int __1i;

                struct Block_Pchar *__0__X77;

                __1i = 0;

                for (; __1i < nodatainst; __1i++)
                    if (strcmp((const char *)((
                                   *((__0__X77 = (&instdata)),
                                     ((((Pchar *)(&(__0__X77->p__11Block_Pchar[__1i])))))))),
                               __0this->__O2__4expr.string) == 0)
                        __1instflag = 1;

                if (__1instflag && (curr_inst != 0))
                    return (unsigned char)0;

                return (unsigned char)1;
            }
        }
    }
}

bit finst_body__4nameFv(register struct name *__0this) {
    unsigned long __2__X16;

    struct ea __0__X__V1400q2z144hdwckg;

    struct ea __0__X__V1500q2z144hdwckg;

    if ((((all_flag == 0) && (ft_flag == 0)) && (fcurr_inst != 0)) &&
        ((((__0this->__O1__4expr.tp->base__4node == 108)
               ? (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
               : (error__FiPCcRC2eaN33(
                      (int)'i', (const char *)"N::fct_type():%n is %k notF",
                      (const struct ea *)(((&__0__X__V1400q2z144hdwckg)->__O1__2ea.p =
                                               ((const void *)__0this)),
                                          (&__0__X__V1400q2z144hdwckg)),
                      (const struct ea *)((__2__X16 = __0this->__O1__4expr.tp->base__4node),
                                          (((((&__0__X__V1500q2z144hdwckg)->__O1__2ea.i = __2__X16),
                                             0)),
                                           (&__0__X__V1500q2z144hdwckg))),
                      (const struct ea *)ea0, (const struct ea *)ea0),
                  (((struct fct *)0)))))
             ->f_inline__3fct == 0))
        return (unsigned char)0;

    if (((ft_flag && (fdummyinst != fcurr_inst)) && (fcurr_inst != 0)) &&
        ((((__0this->__O1__4expr.tp->base__4node == 108)
               ? (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
               : (error__FiPCcRC2eaN33(
                      (int)'i', (const char *)"N::fct_type():%n is %k notF",
                      (const struct ea *)(((&__0__X__V1400q2z144hdwckg)->__O1__2ea.p =
                                               ((const void *)__0this)),
                                          (&__0__X__V1400q2z144hdwckg)),
                      (const struct ea *)((__2__X16 = __0this->__O1__4expr.tp->base__4node),
                                          (((((&__0__X__V1500q2z144hdwckg)->__O1__2ea.i = __2__X16),
                                             0)),
                                           (&__0__X__V1500q2z144hdwckg))),
                      (const struct ea *)ea0, (const struct ea *)ea0),
                  (((struct fct *)0)))))
             ->f_inline__3fct == 0))
        return (unsigned char)0;

    return (unsigned char)1;
}

bit inst_body__4nameFv(register struct name *__0this) {
    bit __1inst_flag;

    __1inst_flag = 0;

    {
        {
            int __1i;

            struct Block_Pchar *__0__X78;

            __1i = 0;

            for (; __1i < noinst; __1i++)
                if (strcmp(__0this->__O2__4expr.string,
                           (const char *)((
                               *((__0__X78 = (&instfct)),
                                 ((((Pchar *)(&(__0__X78->p__11Block_Pchar[__1i]))))))))) == 0)
                    __1inst_flag = 1;

            {
                bit __1datainstflag;

                __1datainstflag = 0;

                {
                    {
                        int __1j;

                        struct Block_Pchar *__0__X79;

                        __1j = 0;

                        for (; __1j < nodatainst; __1j++)
                            if (strcmp((const char *)((*(
                                           (__0__X79 = (&instdata)),
                                           ((((Pchar *)(&(__0__X79->p__11Block_Pchar[__1j])))))))),
                                       __0this->__O2__4expr.string) == 0)
                                __1datainstflag = 1;

                        {
                            Pfct __1ft;

                            unsigned long __2__X16;

                            struct ea __0__X__V1400q2z144hdwckg;

                            struct ea __0__X__V1500q2z144hdwckg;

                            __1ft =
                                (((__0this->__O1__4expr.tp->base__4node == 108)
                                      ? (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
                                      : (error__FiPCcRC2eaN33(
                                             (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                             (const struct ea *)(((&__0__X__V1400q2z144hdwckg)
                                                                      ->__O1__2ea.p =
                                                                      ((const void *)__0this)),
                                                                 (&__0__X__V1400q2z144hdwckg)),
                                             (const struct ea *)((__2__X16 = __0this->__O1__4expr
                                                                                 .tp->base__4node),
                                                                 (((((&__0__X__V1500q2z144hdwckg)
                                                                         ->__O1__2ea.i = __2__X16),
                                                                    0)),
                                                                  (&__0__X__V1500q2z144hdwckg))),
                                             (const struct ea *)ea0, (const struct ea *)ea0),
                                         (((struct fct *)0)))));

                            if (((((((__1inst_flag == 0) && (curr_inst != 0)) &&
                                    (curr_inst == dummyinst)) &&
                                   (all_flag == 0)) &&
                                  (alltc_flag == 0)) &&
                                 (__1ft->f_virtual__3fct == 0)) &&
                                (__1ft->f_inline__3fct == 0))
                                return (unsigned char)0;

                            if (((((__1datainstflag && (curr_inst != 0)) &&
                                   (curr_inst == dummyinst)) &&
                                  __1ft->f_virtual__3fct) &&
                                 (all_flag == 0)) &&
                                (alltc_flag == 0))
                                return (unsigned char)0;

                            if (((((((curr_inst == dummyinst) && (curr_inst != 0)) &&
                                    __1ft->f_virtual__3fct) &&
                                   (__1ft->f_inline__3fct == 0)) &&
                                  (data_flag == 0)) &&
                                 (all_flag == 0)) &&
                                (alltc_flag == 0))
                                return (unsigned char)0;

                            if (((((all_flag == 0) && (curr_inst != dummyinst)) &&
                                  (curr_inst != 0)) &&
                                 (__1ft->f_inline__3fct == 0)) &&
                                (__1ft->f_is_inline__3fct == 0))
                                return (unsigned char)0;

                            return (unsigned char)1;
                        }
                    }
                }
            }
        }
    }
}

Pname function_copy__10templ_instFP17function_templateRP4cons(struct templ_inst *__0this, Pfunt,
                                                              Pcons *);

void save_state__10basic_instFP4name(struct basic_inst *__0this, Pname __1p);

Pname dcl__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

void restore_state__10basic_instFv(struct basic_inst *__0this);

void simpl__4nameFv(struct name *__0this);

void dcl_print__4nameFUc(struct name *__0this, TOK);

extern Pexpr mk_zero_init__FP4typeP4nameT2(Ptype, Pname, Pname);

int instantiate_bodies__5templFv(register struct templ *__0this) {
    int __1change;

    __1change = 0;
    if ((!__0this->fns__5templ) && (!__0this->data__5templ))
        return __1change;

    {
        {
            Ptempl_inst __1inst;

            __1inst = __0this->insts__5templ;

            for (; __1inst; __1inst = __1inst->next__10templ_inst)
                if ((!__1inst->forward__10templ_inst) && (__1inst->status__10basic_inst == 3)) {
                    __1inst->status__10basic_inst = 4;
                    __1change = 1;
                    {
                        Pclass __2ic;

                        struct dcl_context *__0__X85;

                        __2ic = ((((struct classdef *)((
                            (struct classdef *)(((struct basetype *)((
                                                    (struct basetype *)__1inst->tname__10basic_inst
                                                        ->__O1__4expr.tp))))
                                ->b_name__8basetype->__O1__4expr.tp)))));

                        {
                            int __3i;

                            {
                                {
                                    Pname __3fn;

                                    struct table *__0__X81;

                                    int __2__X82;

                                    unsigned long __2__X16;

                                    struct ea __0__X__V1400q2z144hdwckg;

                                    struct ea __0__X__V1500q2z144hdwckg;

                                    struct table *__0__X83;

                                    int __2__X84;

                                    __3fn = ((__0__X83 = __2ic->memtbl__8classdef),
                                             ((__2__X84 = (__3i = 1)),
                                              ((((__2__X84 <= 0) ||
                                                 (__0__X83->free_slot__5table <= __2__X84))
                                                    ? (((struct name *)0))
                                                    : (__0__X83->entries__5table[__2__X84])))));

                                    for (; __3fn;
                                         __3fn =
                                             (__3fn->n_tbl_list__4name
                                                  ? __3fn->n_tbl_list__4name
                                                  : ((__0__X81 = __2ic->memtbl__8classdef),
                                                     ((__2__X82 = (++__3i)),
                                                      ((((__2__X82 <= 0) ||
                                                         (__0__X81->free_slot__5table <= __2__X82))
                                                            ? (((struct name *)0))
                                                            : (__0__X81->entries__5table
                                                                   [__2__X82])))))))
                                        if (((__3fn->base__4node == 85) &&
                                             (__3fn->__O1__4expr.tp->base__4node == 108)) &&
                                            (((__3fn->__O1__4expr.tp->base__4node == 108)
                                                  ? (((struct fct *)((
                                                        (struct fct *)__3fn->__O1__4expr.tp))))
                                                  : (error__FiPCcRC2eaN33(
                                                         (int)'i',
                                                         (const char
                                                              *)"N::fct_type():%n is %k notF",
                                                         (const struct ea
                                                              *)(((&__0__X__V1400q2z144hdwckg)
                                                                      ->__O1__2ea.p =
                                                                      ((const void *)__3fn)),
                                                                 (&__0__X__V1400q2z144hdwckg)),
                                                         (const struct ea
                                                              *)((__2__X16 = __3fn->__O1__4expr.tp
                                                                                 ->base__4node),
                                                                 (((((&__0__X__V1500q2z144hdwckg)
                                                                         ->__O1__2ea.i = __2__X16),
                                                                    0)),
                                                                  (&__0__X__V1500q2z144hdwckg))),
                                                         (const struct ea *)ea0,
                                                         (const struct ea *)ea0),
                                                     (((struct fct *)0)))))
                                                ->body__3fct)
                                            __3fn->n_redefined__4name = 1;
                                }
                            }
                        }

                        ((((cc++),
                           (((cc >= ccvec_end)
                                 ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow")
                                 : 0),
                            (((*cc)) = (*(cc - 1))))),
                          (((void)0))));

                        cc->cot__11dcl_context = 0;

                        cc->not4__11dcl_context = 0;

                        cc->tot__11dcl_context = 0;

                        cc->c_this__11dcl_context = 0;
                        {
                            {
                                Pfunt __2fnt;

                                struct dcl_context *__0__X86;

                                struct dcl_context *__0__X87;

                                __2fnt = __0this->fns__5templ;

                                for (; __2fnt; __2fnt = __2fnt->next__17function_template) {
                                    Pcons __3templ_ref_copy;
                                    Pname __3fn;

                                    __3templ_ref_copy = __2fnt->templ_refs__14basic_template;
                                    __3fn = function_copy__10templ_instFP17function_templateRP4cons(
                                        __1inst, __2fnt, (Pcons *)(&__3templ_ref_copy));

                                    __3fn->__O2__4name.n_qualifier = __1inst->namep__10basic_inst;

                                    if (__3fn->n_oper__4name != 97)
                                        __3fn->__O4__4expr.n_table = 0;
                                    __3fn->n_tbl_list__4name = 0;

                                    if (!strcmp(__3fn->__O2__4expr.string,
                                                __0this->namep__5templ->__O2__4expr.string))
                                        __3fn->__O2__4expr.string =
                                            __1inst->namep__10basic_inst->__O2__4expr.string;

                                    {
                                        save_state__10basic_instFP4name(
                                            (struct basic_inst *)__1inst, __3fn);

                                        {
                                            {
                                                Pcons __4pc;

                                                unsigned long __2__X16;

                                                struct ea __0__X__V1400q2z144hdwckg;

                                                struct ea __0__X__V1500q2z144hdwckg;

                                                __4pc = __3templ_ref_copy;

                                                for (; __4pc; __4pc = __4pc->cdr__4cons)
                                                    instantiate__10templ_instF4bool(
                                                        ((struct templ_inst *)((
                                                            (struct templ_inst *)
                                                                __4pc->car__4cons))),
                                                        0);

                                                curr_inst = __1inst;

                                                if (((__3fn = dcl__4nameFP5tableUc(
                                                          __3fn, gtbl, (unsigned char)14)) == 0) ||
                                                    error_count) {
                                                    restore_state__10basic_instFv(
                                                        (struct basic_inst *)__1inst);
                                                    continue;
                                                }

                                                curr_inst = __1inst;

                                                if (se_opt && (inst_body__4nameFv(__3fn) == 0))
                                                    suppress_error++;

                                                simpl__4nameFv(__3fn);

                                                if (se_opt && (inst_body__4nameFv(__3fn) == 0)) {
                                                    suppress_error--;
                                                }

                                                if (dtpt_opt && (inst_body__4nameFv(__3fn) == 0))
                                                    (((__3fn->__O1__4expr.tp->base__4node == 108)
                                                          ? (((struct fct *)((
                                                                (struct fct *)
                                                                    __3fn->__O1__4expr.tp))))
                                                          : (error__FiPCcRC2eaN33(
                                                                 (int)'i',
                                                                 (const char *)"N::fct_type():%n "
                                                                               "is %k notF",
                                                                 (const struct
                                                                  ea *)(((&__0__X__V1400q2z144hdwckg)
                                                                             ->__O1__2ea.p =
                                                                             ((const void *)__3fn)),
                                                                        (&__0__X__V1400q2z144hdwckg)),
                                                                 (const struct
                                                                  ea *)((__2__X16 =
                                                                             __3fn->__O1__4expr.tp
                                                                                 ->base__4node),
                                                                        (((((&__0__X__V1500q2z144hdwckg)
                                                                                ->__O1__2ea.i =
                                                                                __2__X16),
                                                                           0)),
                                                                         (&__0__X__V1500q2z144hdwckg))),
                                                                 (const struct ea *)ea0,
                                                                 (const struct ea *)ea0),
                                                             (((struct fct *)0)))))
                                                        ->body__3fct = 0;

                                                dcl_print__4nameFUc(__3fn, (unsigned char)0);
                                                curr_inst = 0;
                                                restore_state__10basic_instFv(
                                                    (struct basic_inst *)__1inst);
                                            }
                                        }
                                    }
                                }
                                (((cc--), (((void)0))));

                                __1inst->status__10basic_inst = 2;
                                ((((cc++),
                                   (((cc >= ccvec_end)
                                         ? error__FiPCc((int)'i',
                                                        (const char *)"ccvec buffer overflow")
                                         : 0),
                                    (((*cc)) = (*(cc - 1))))),
                                  (((void)0))));

                                cc->cot__11dcl_context = 0;

                                cc->not4__11dcl_context = 0;

                                cc->tot__11dcl_context = 0;

                                cc->c_this__11dcl_context = 0;
                                {
                                    {
                                        Pdata __2dat;

                                        struct dcl_context *__0__X89;

                                        __2dat = __0this->data__5templ;

                                        for (; __2dat; __2dat = __2dat->next__13data_template) {
                                            Pcons __3templ_ref_copy;
                                            Pname __3dn;

                                            const void *__2__X88;

                                            __3templ_ref_copy =
                                                __2dat->templ_refs__14basic_template;
                                            __3dn =
                                                look__5tableFPCcUc(__2ic->memtbl__8classdef,
                                                                   __2dat->dat_mem__13data_template
                                                                       ->__O2__4expr.string,
                                                                   (unsigned char)0);

                                            if ((!__3dn) || (__3dn->n_stclass__4name != 31)) {
                                                struct ea __0__V80;

                                                error__FPCcRC2eaN32(
                                                    (const char
                                                         *)"%n: only static dataMs can beZized",
                                                    (const struct ea
                                                         *)((__2__X88 =
                                                                 (const void *)__2dat
                                                                     ->dat_mem__13data_template),
                                                            (((&__0__V80)->__O1__2ea.p = __2__X88),
                                                             (&__0__V80))),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                                            }
                                            if (__3dn->n_redefined__4name)
                                                continue;
                                            {
                                                Pname __3n;

                                                __3n =
                                                    data_copy__10templ_instFP13data_templateRP4cons(
                                                        __1inst, __2dat,
                                                        (Pcons *)(&__3templ_ref_copy));
                                                __3n->__O2__4name.n_qualifier =
                                                    __1inst->namep__10basic_inst;
                                                __3n->__O4__4expr.n_table = 0;

                                                __3n->n_tbl_list__4name = 0;

                                                save_state__10basic_instFP4name(
                                                    (struct basic_inst *)__1inst, __3n);
                                                {
                                                    {
                                                        Pcons __3pc;

                                                        __3pc = __3templ_ref_copy;

                                                        for (; __3pc; __3pc = __3pc->cdr__4cons)
                                                            instantiate__10templ_instF4bool(
                                                                ((struct templ_inst *)((
                                                                    (struct templ_inst *)
                                                                        __3pc->car__4cons))),
                                                                0);

                                                        curr_inst = __1inst;

                                                        if (((__3n = dcl__4nameFP5tableUc(
                                                                  __3n, gtbl, (unsigned char)14)) ==
                                                             0) ||
                                                            error_count) {
                                                            restore_state__10basic_instFv(
                                                                (struct basic_inst *)__1inst);
                                                            continue;
                                                        }
                                                        simpl__4nameFv(__3n);

                                                        mk_zero_init_flag = 0;

                                                        if (((__3n->n_stclass__4name == 31) &&
                                                             (__3n->__O3__4expr.n_initializer ==
                                                              0)) &&
                                                            (__3n->n_evaluated__4name == 0))
                                                            __3n->__O3__4expr.n_initializer =
                                                                mk_zero_init__FP4typeP4nameT2(
                                                                    __3n->__O1__4expr.tp, __3n,
                                                                    __3n);

                                                        if (dtpt_opt &&
                                                            (dinst_body__4nameFv(__3n) == 0)) {
                                                            __3n->__O3__4expr.n_initializer = 0;
                                                            mk_zero_init_flag = 1;
                                                        }

                                                        if (((__3n->n_stclass__4name != 31) ||
                                                             (!mk_zero_init_flag)) ||
                                                            (!strict_opt))
                                                            dcl_print__4nameFUc(__3n,
                                                                                (unsigned char)0);
                                                        curr_inst = 0;
                                                        mk_zero_init_flag = 0;
                                                        __3n->n_dcl_printed__4name = 2;
                                                        restore_state__10basic_instFv(
                                                            (struct basic_inst *)__1inst);
                                                    }
                                                }
                                            }
                                        }
                                        (((cc--), (((void)0))));
                                    }
                                }
                            }
                        }
                    }
                }
            return __1change;
        }
    }
}

Pname check_tname__17templ_compilationFP4name(register struct templ_compilation *__0this,
                                              Pname __1p) {
    Ptempl __1t;

    extern int in_friend;

    extern Ptempl_inst pti;

    struct classdef *__1__X91;

    struct classdef *__1__X92;

    __1t = is_template__17templ_compilationFP4name(__0this, __1p);
    if (__1p->n_template_arg__4name)
        __1p->n_used__4name++;
    if (!__1t)
        return __1p;
    ;
    if ((in_progress__17templ_compilation && (in_friend == 0)) &&
        ((owner__17templ_compilation && (owner__17templ_compilation->namep__5templ == __1p)) ||
         ((!owner__17templ_compilation) &&
          ((__1__X91 = ((((struct classdef *)((
                (struct classdef *)__1t->basep__5templ->b_name__8basetype->__O1__4expr.tp)))))),
           ((__1__X92 = ccl),
            (((__1__X91 == __1__X92)
                  ? 1
                  : ((__1__X91 && __1__X92)
                         ? (((int)same_class__8classdefFP8classdefi(__1__X91, __1__X92, 0)))
                         : 0))))))))
        return __1p;

    ;
    if (pti && (pti->def__10templ_inst == __1t))
        return __1p;

    {
        struct ea __0__V90;

        error__FPCcRC2eaN32(
            (const char *)"%n needsY instantiationAs",
            (const struct ea *)(((&__0__V90)->__O1__2ea.p = ((const void *)__1p)), (&__0__V90)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        return __1p;
    }
}

int current_template__17templ_compilationFP4nameP4expr(register struct templ_compilation *__0this,
                                                       Pname __1p, Pexpr __1actuals) {
    Ptype __1t;
    if ((((struct basetype *)(((struct basetype *)__1p->__O1__4expr.tp)))) &&
        (((struct basetype *)(((struct basetype *)__1p->__O1__4expr.tp))))->b_name__8basetype)
        __1t = (((struct basetype *)(((struct basetype *)__1p->__O1__4expr.tp))))
                   ->b_name__8basetype->__O1__4expr.tp;
    else
        __1t = 0;
    if (in_progress__17templ_compilation &&
        ((owner__17templ_compilation && (owner__17templ_compilation->namep__5templ == __1p)) ||
         ((!owner__17templ_compilation) &&
          ((__1p->__O1__4expr.tp->base__4node == 119) && (__1t == (((struct type *)ccl))))))) {
        Pexpr __2actual;
        Plist __2formal;

        __2actual = __1actuals;
        __2formal = params__17templ_compilation;
        for (; __2formal && __2actual;
             ((__2formal = __2formal->l__9name_list), (__2actual = __2actual->__O3__4expr.e2))) {
            if (__2formal->f__9name_list->n_template_arg__4name == 1) {
                if (((((__2formal->f__9name_list->__O1__4expr.tp == (((struct type *)any_type))) &&
                       __2actual->__O2__4expr.e1->__O1__4expr.tp) &&
                      (__2actual->__O2__4expr.e1->__O1__4expr.tp->base__4node == 97)) &&
                     ((((struct basetype *)((
                           (struct basetype *)__2actual->__O2__4expr.e1->__O1__4expr.tp))))
                          ->b_name__8basetype->__O1__4expr.tp == (((struct type *)any_type)))) &&
                    (strcmp((((struct basetype *)((
                                 (struct basetype *)__2actual->__O2__4expr.e1->__O1__4expr.tp))))
                                ->b_name__8basetype->__O2__4expr.string,
                            __2formal->f__9name_list->__O2__4expr.string) == 0))
                    continue;
                else
                    break;
            } else {
                if (((__2formal->f__9name_list->base__4node == 85) &&
                     (__2actual->__O2__4expr.e1->base__4node == 85)) &&
                    (strcmp((((struct name *)(((struct name *)__2actual->__O2__4expr.e1))))
                                ->__O2__4expr.string,
                            __2formal->f__9name_list->__O2__4expr.string) == 0))
                    continue;
                else
                    break;
            }
        }
        if ((!__2formal) && (!__2actual))
            return (int)1;
    }
    return (int)0;
}

struct function_template *
__ct__17function_templateFR5templP9name_listP4name(struct function_template *__0this,
                                                   struct templ *, Plist, Pname);

Pfunt collect_function_member__5templFP4name(register struct templ *__0this, Pname __1fname) {
    __1fname->permanent__4node = 1;

    __1fname->__O1__4expr.tp->permanent__4node = 1;
    (((struct fct *)(((struct fct *)__1fname->__O1__4expr.tp))))->body__3fct->permanent__4node = 1;
    return __ct__17function_templateFR5templP9name_listP4name(
        (struct function_template *)0, (struct templ *)__0this, params__17templ_compilation,
        __1fname);
}

struct data_template *__ct__13data_templateFR5templP9name_listP4name(struct data_template *__0this,
                                                                     struct templ *, Plist, Pname);

Pdata collect_data_member__5templFP4name(register struct templ *__0this, Pname __1dname) {
    __1dname->permanent__4node = 1;

    __1dname->__O1__4expr.tp->permanent__4node = 1;
    return __ct__13data_templateFR5templP9name_listP4name(
        (struct data_template *)0, (struct templ *)__0this, params__17templ_compilation, __1dname);
}

void check_formals_for_dups__FP9name_list(Plist __1formals) {
    {
        {
            Plist __1fl1;

            __1fl1 = __1formals;

            for (; __1fl1; __1fl1 = __1fl1->l__9name_list) {
                Pname __2n1;

                __2n1 = __1fl1->f__9name_list;
                {
                    {
                        Plist __2fl2;

                        __2fl2 = __1fl1->l__9name_list;

                        for (; __2fl2; __2fl2 = __2fl2->l__9name_list) {
                            Pname __3n2;

                            __3n2 = __2fl2->f__9name_list;
                            if (strcmp(__2n1->__O2__4expr.string, __3n2->__O2__4expr.string) == 0) {
                                struct ea __0__V93;

                                error__FPCcRC2eaN32((const char *)"YA%n redeclared inZ list",
                                                    (const struct ea *)(((&__0__V93)->__O1__2ea.p =
                                                                             ((const void *)__2n1)),
                                                                        (&__0__V93)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                            }
                        }
                    }
                }
            }
        }
    }
}

bit contains_formal__FP4nameP8classdef(Pname __1formal, Pclass __1cl) {
    int __1__Xt00awz144hdwckg;

    if (__1cl->class_base__8classdef == 0)
        return (unsigned char)0;
    if (((__1__Xt00awz144hdwckg =
              ((((struct type *)__1cl)->base__4node == 108)
                   ? (((struct fct *)(((struct fct *)((struct type *)__1cl)))))->fct_base__3fct
                   : ((((struct type *)__1cl)->base__4node == 6)
                          ? (((struct classdef *)(((struct classdef *)((struct type *)__1cl)))))
                                ->class_base__8classdef
                          : (((int)0))))),
         (((unsigned char)((__1__Xt00awz144hdwckg == 4) || (__1__Xt00awz144hdwckg == 5)))))) {
        Pexpr __2actuals;

        __2actuals = (((struct templ_classdef *)(((struct templ_classdef *)__1cl))))
                         ->inst__14templ_classdef->actuals__10basic_inst;
        for (; __2actuals; __2actuals = __2actuals->__O3__4expr.e2) {
            Pexpr __3e;

            __3e = __2actuals->__O2__4expr.e1;
            if ((__3e->base__4node != 85) || (__3e->__O1__4expr.tp->base__4node != 97))
                continue;
            {
                Pname __3tn;

                struct type *__0__X94;

                __3tn =
                    ((__0__X94 = __3e->__O1__4expr.tp),
                     ((((struct basetype *)(((struct basetype *)__0__X94))))->b_name__8basetype));
                if (strcmp(__1formal->__O2__4expr.string, __3tn->__O2__4expr.string) == 0)
                    return (unsigned char)1;
            }
        }
    } else {
        Ptempl __2t;

        __2t = is_template__17templ_compilationFPCc(templp, __1cl->string__8classdef);
        if (!__2t)
            return (unsigned char)0;
        {
            {
                Plist __2formals;

                __2formals = (((struct basic_template *)__2t)->formals__14basic_template);

                for (; __2formals; __2formals = __2formals->l__9name_list) {
                    Pname __3n;

                    __3n = __2formals->f__9name_list;
                    if (__3n->n_template_arg__4name == 1) {
                        return (unsigned char)1;
                    }
                }
            }
        }
    }

    return (unsigned char)0;
}

void check_funct_formals__FP9name_listP4name(Plist __1formals, Pname __1namep) {
    check_formals_for_dups__FP9name_list(__1formals);
    {
        {
            Plist __1fl;

            __1fl = __1formals;

            for (; __1fl; __1fl = __1fl->l__9name_list) {
                Pname __2fn;

                __2fn = __1fl->f__9name_list;
                if (!((((unsigned char)(__2fn->n_template_arg__4name == 1))))) {
                    {
                        struct ea __0__V95;

                        error__FPCcRC2eaN32(
                            (const char *)"FYZ%n must be aT",
                            (const struct ea *)(((&__0__V95)->__O1__2ea.p = ((const void *)__2fn)),
                                                (&__0__V95)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        continue;
                    }
                }

                {
                    Pname __2a;

                    __2a =
                        (((struct fct *)(((struct fct *)__1namep->__O1__4expr.tp))))->argtype__3fct;
                    for (; __2a; __2a = __2a->__O1__4name.n_list) {
                        Ptype __3t;
                        int __3found;

                        __3t = __2a->__O1__4expr.tp;
                        __3found = 0;
                        while (((__3t->base__4node == 125) || (__3t->base__4node == 158)) ||
                               (__3t->base__4node == 110)) {
                            switch (__3t->base__4node) {
                            case 125:
                                if ((((struct ptr *)(((struct ptr *)__3t))))->ptname__3ptr) {
                                    Pname __6n;

                                    __6n = (((struct ptr *)(((struct ptr *)__3t))))->ptname__3ptr;
                                    if (strcmp(__6n->__O2__4expr.string,
                                               __2fn->__O2__4expr.string) == 0)
                                        __3found = 1;
                                    __3t = __6n->__O1__4expr.tp;
                                    break;
                                }
                            case 158:
                                __3t = (((struct ptr *)(((struct ptr *)__3t))))->typ__5pvtyp;

                                break;
                            case 110:
                                __3t = (((struct vec *)(((struct vec *)__3t))))->typ__5pvtyp;

                                break;
                            }
                        }

                        if (__3found) {
                            __3found = 0;

                            break;
                        }

                        if (__3t->base__4node == 119) {
                            if (contains_formal__FP4nameP8classdef(__2fn,
                                                                   classtype__4typeFv(__3t))) {
                                break;
                            }
                        } else if (__3t->base__4node != 97)
                            continue;

                        {
                            Pname __3tn;

                            __3tn = ((((struct basetype *)(((struct basetype *)__3t))))
                                         ->b_name__8basetype);
                            if (!((((unsigned char)(__3tn->n_template_arg__4name == 1))))) {
                                __3t = __3tn->__O1__4expr.tp;
                                if (__3t->base__4node == 119) {
                                    if (contains_formal__FP4nameP8classdef(
                                            __2fn, classtype__4typeFv(__3t))) {
                                        break;
                                    }
                                }
                                continue;
                            }
                            if (strcmp(__3tn->__O2__4expr.string, __2fn->__O2__4expr.string) == 0)
                                break;
                        }
                    }
                    if (__2a == 0) {
                        struct ea __0__V96;

                        struct ea __0__V97;

                        error__FPCcRC2eaN32(
                            (const char *)"FYZ%n must be used in signature of %n",
                            (const struct ea *)(((&__0__V96)->__O1__2ea.p = ((const void *)__2fn)),
                                                (&__0__V96)),
                            (const struct ea *)(((&__0__V97)->__O1__2ea.p =
                                                     ((const void *)__1namep)),
                                                (&__0__V97)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
            }
        }
    }
}

int get_formals_count__14basic_templateFv(struct basic_template *__0this) {
    int __1cnt;

    __1cnt = 0;
    {
        {
            Plist __1f;

            __1f = __0this->formals__14basic_template;

            for (; __1f; ((__1f = __1f->l__9name_list), (++__1cnt)))
                ;
            return __1cnt;
        }
    }
}

void check_formals__14basic_templateFP9name_list(register struct basic_template *__0this,
                                                 Plist __1f2) {
    Plist __1f1;

    const void *__2__X111;

    const void *__2__X112;

    __1f1 = __0this->formals__14basic_template;
    for (; __1f1 && __1f2; ((__1f1 = __1f1->l__9name_list), (__1f2 = __1f2->l__9name_list)))
        if (__1f1->f__9name_list->base__4node != __1f2->f__9name_list->base__4node)
            switch (__1f1->f__9name_list->n_template_arg__4name) {
                const void *__2__X107;

                const void *__2__X108;

                const void *__2__X109;

            case 1: {
                struct ea __0__V98;

                error__FPCcRC2eaN32(
                    (const char *)"Y formalZ mismatch, %n must be aT formalZ",
                    (const struct ea *)((__2__X107 = (const void *)__1f2->f__9name_list),
                                        (((&__0__V98)->__O1__2ea.p = __2__X107), (&__0__V98))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                break;

            case 2: {
                struct ea __0__V99;

                struct ea __0__V100;

                error__FPCcRC2eaN32(
                    (const char *)"formalZ mismatch, %n must be aZ ofT %t",
                    (const struct ea *)((__2__X108 = (const void *)__1f2->f__9name_list),
                                        (((&__0__V99)->__O1__2ea.p = __2__X108), (&__0__V99))),
                    (const struct ea *)__ct__2eaFPCv(
                        &__0__V100, (const void *)__1f2->f__9name_list->__O1__4expr.tp),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                break;

            default: {
                struct ea __0__V101;

                struct ea __0__V102;

                error__FPCcRC2eaN32(
                    (const char *)"formalZ mismatch betweenC formal: %n andM formal: %n",
                    (const struct ea *)((__2__X109 = (const void *)__1f1->f__9name_list),
                                        (((&__0__V101)->__O1__2ea.p = __2__X109), (&__0__V101))),
                    (const struct ea *)__ct__2eaFPCv(&__0__V102,
                                                     (const void *)__1f2->f__9name_list),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            }
            }
            }
        else if (__1f1->f__9name_list->n_template_arg__4name == 2) {
            const void *__2__X110;

            if (check__4typeFP4typeUcT2(__1f1->f__9name_list->__O1__4expr.tp,
                                        __1f2->f__9name_list->__O1__4expr.tp, (unsigned char)0,
                                        (unsigned char)0) == 1) {
                struct ea __0__V103;

                struct ea __0__V104;

                error__FPCcRC2eaN32(
                    (const char *)"T mismatch betweenM formal %n andC formal %n",
                    (const struct ea *)((__2__X110 = (const void *)__1f2->f__9name_list),
                                        (((&__0__V103)->__O1__2ea.p = __2__X110), (&__0__V103))),
                    (const struct ea *)__ct__2eaFPCv(&__0__V104,
                                                     (const void *)__1f1->f__9name_list),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }

    if (__1f1) {
        struct ea __0__V105;

        error__FPCcRC2eaN32(
            (const char *)"insufficient formalZs,CZ%n onwards are missing",
            (const struct ea *)((__2__X111 = (const void *)__1f1->f__9name_list),
                                (((&__0__V105)->__O1__2ea.p = __2__X111), (&__0__V105))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__1f2) {
        struct ea __0__V106;

        error__FPCcRC2eaN32(
            (const char *)"excess formalZs,Z%n onwards not defined forC",
            (const struct ea *)((__2__X112 = (const void *)__1f2->f__9name_list),
                                (((&__0__V106)->__O1__2ea.p = __2__X112), (&__0__V106))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
}

static Ptype real_type__FP4type(Ptype __1t) {
    while (__1t && (__1t->base__4node == 97))
        __1t =
            (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp;
    return __1t;
}

long long eval__4exprFv(struct expr *__0this);

void del__4exprFv(struct expr *__0this);

static void vec_eval__FP4type(Ptype __1p) {
    while (__1p && ((__1p->base__4node == 110) || (__1p->base__4node == 125))) {
        if (__1p->base__4node == 110) {
            Pvec __3v;

            __3v = (((struct vec *)(((struct vec *)__1p))));
            if (__3v->dim__3vec && (!__3v->size__3vec)) {
                Neval = 0;
                __3v->size__3vec = (((int)eval__4exprFv(__3v->dim__3vec)));
                if (Neval)
                    error__FPCc((const char *)"cannot evaluate constantE");
                if (__3v->dim__3vec && (__3v->dim__3vec->permanent__4node == 0))
                    del__4exprFv(__3v->dim__3vec);
                __3v->dim__3vec = 0;
            }
            __1p = __3v->typ__5pvtyp;
        } else {
            __1p = (((struct ptr *)(((struct ptr *)__1p))))->typ__5pvtyp;
        }
    }
}

int check_actual_args__5templFP4expr(register struct templ *__0this, Pexpr __1actual) {
    Plist __1formal;

    const void *__2__X123;

    const void *__2__X124;

    __1formal = __0this->formals__14basic_template;
    for (; __1formal && __1actual;
         ((__1formal = __1formal->l__9name_list), (__1actual = __1actual->__O3__4expr.e2))) {
        switch (__1formal->f__9name_list->n_template_arg__4name) {

        case 1: {
            vec_eval__FP4type(real_type__FP4type(__1actual->__O2__4expr.e1->__O1__4expr.tp));
            {
                Pname __4n;

                __4n = (((struct name *)(((struct name *)__1actual->__O2__4expr.e1))));
                if (!((__4n->base__4node == 85) && (__4n->n_template_arg__4name == 3))) {
                    const void *__2__X121;

                    {
                        struct ea __0__V113;

                        struct ea __0__V114;

                        error__FPCcRC2eaN32(
                            (const char *)"Y %sA mismatch, theY formal:%n required aT actualZ",
                            (const struct ea *)((__2__X121 = (const void *)__0this->namep__5templ
                                                                 ->__O2__4expr.string),
                                                (((&__0__V113)->__O1__2ea.p = __2__X121),
                                                 (&__0__V113))),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V114, (const void *)__1formal->f__9name_list),
                            (const struct ea *)ea0, (const struct ea *)ea0);

                        __4n = __ct__4nameFPCc((struct name *)0, (const char *)"");
                        __4n->__O1__4expr.tp = (struct type *)any_type;
                        __1actual->__O2__4expr.e1 = (struct expr *)__4n;
                    }
                }

                {
                    Ptype __4tp;

                    __4tp = skiptypedefs__4typeFv(__4n->__O1__4expr.tp);
                    if (__4tp->base__4node == 119) {
                        Pclass __5cl;

                        __5cl = classtype__4typeFv(__4tp);
                        if (__5cl->local_sig__4type) {
                            struct ea __0__V115;

                            struct ea __0__V116;

                            error__FiPCcRC2eaN33(
                                (int)'s', (const char *)"localC%t as ZT to YC%n",
                                (const struct ea *)(((&__0__V115)->__O1__2ea.p =
                                                         ((const void *)__5cl)),
                                                    (&__0__V115)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V116, (const void *)__0this->namep__5templ),
                                (const struct ea *)ea0, (const struct ea *)ea0);
                        }
                    }

                    break;
                }
            }
        }

        case 2: {
            Ptype __4tp;

            __4tp = skiptypedefs__4typeFv(__1formal->f__9name_list->__O1__4expr.tp);

            ;
            if ((__1actual->__O2__4expr.e1->base__4node == 86) && (__4tp->base__4node == 125)) {
                const void *__2__X122;

                if (__4tp->b_const__4type == 2)
                    __4tp->b_const__4type = 0;
                {
                    struct ea __0__V117;

                    struct ea __0__V118;

                    error__FPCcRC2eaN32(
                        (const char *)"cannot instantiate 0 to formalZ%n(%t)",
                        (const struct ea *)((__2__X122 = (const void *)__1formal->f__9name_list),
                                            (((&__0__V117)->__O1__2ea.p = __2__X122),
                                             (&__0__V117))),
                        (const struct ea *)(((&__0__V118)->__O1__2ea.p = ((const void *)__4tp)),
                                            (&__0__V118)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
            break;
        }
        default:
            error__FiPCc((int)'i', (const char *)"badY formal");
        }
    }

    if (__1formal) {
        struct ea __0__V119;

        error__FPCcRC2eaN32(
            (const char *)"too fewAs supplied forY %s",
            (const struct ea *)((__2__X123 =
                                     (const void *)__0this->namep__5templ->__O2__4expr.string),
                                (((&__0__V119)->__O1__2ea.p = __2__X123), (&__0__V119))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__1actual && __1actual->__O2__4expr.e1) {
        struct ea __0__V120;

        error__FPCcRC2eaN32(
            (const char *)"too manyAs supplied forY %s",
            (const struct ea *)((__2__X124 =
                                     (const void *)__0this->namep__5templ->__O2__4expr.string),
                                (((&__0__V120)->__O1__2ea.p = __2__X124), (&__0__V120))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    return (((int)(~(__1formal || __1actual))));
}

void append_friend_ref__17templ_compilationFP10templ_inst(struct templ_compilation *__0this,
                                                          Ptempl_inst __1ref) {
    struct cons *__1p;

    struct cons *__0__X125;

    struct cons *__2__X126;

    __1p =
        ((__0__X125 = 0),
         ((__2__X126 = 0),
          (((__0__X125 ||
             (__0__X125 = (struct cons *)__nw__FUl((unsigned long)(sizeof(struct cons)))))
                ? ((__0__X125->car__4cons = ((void *)__1ref)), (__0__X125->cdr__4cons = __2__X126))
                : 0),
           __0__X125)));
    if (last_friend_cons__17templ_compilation)
        last_friend_cons__17templ_compilation->cdr__4cons = __1p;
    else
        friend_templ_refs__17templ_compilation = __1p;
    last_friend_cons__17templ_compilation = __1p;
}

void append_ref__17templ_compilationFP10templ_inst(struct templ_compilation *__0this,
                                                   Ptempl_inst __1ref) {
    struct cons *__1p;

    struct cons *__0__X127;

    struct cons *__2__X128;

    __1p =
        ((__0__X127 = 0),
         ((__2__X128 = 0),
          (((__0__X127 ||
             (__0__X127 = (struct cons *)__nw__FUl((unsigned long)(sizeof(struct cons)))))
                ? ((__0__X127->car__4cons = ((void *)__1ref)), (__0__X127->cdr__4cons = __2__X128))
                : 0),
           __0__X127)));
    if (last_cons__17templ_compilation)
        last_cons__17templ_compilation->cdr__4cons = __1p;
    else
        templ_refs__17templ_compilation = __1p;
    last_cons__17templ_compilation = __1p;
}

static bit ref_in_friend = 0;
static bit ignore_ref = 0;

Ptempl_inst note_ref__10templ_instFv(register struct templ_inst *__0this) {
    if (ref_in_friend && (ignore_ref == 0)) {
        __0this->friend_refp__10templ_inst = 1;
        append_friend_ref__17templ_compilationFP10templ_inst(templp, __0this);
    }

    if (!__0this->refp__10templ_inst) {
        __0this->refp__10templ_inst = 1;
        append_ref__17templ_compilationFP10templ_inst(templp, __0this);
    }
    return __0this;
}

int friend_template__17templ_compilationFP4expr(register struct templ_compilation *__0this,
                                                Pexpr __1actuals) {
    Pexpr __1actual;
    Plist __1formal;

    __1actual = __1actuals;
    __1formal = params__17templ_compilation;
    for (; __1formal && __1actual;
         ((__1formal = __1formal->l__9name_list), (__1actual = __1actual->__O3__4expr.e2))) {
        if ((__1formal->f__9name_list->__O1__4expr.tp ==
             __1actual->__O2__4expr.e1->__O1__4expr.tp) ||
            ((__1actual->__O2__4expr.e1->__O1__4expr.tp &&
              (__1actual->__O2__4expr.e1->__O1__4expr.tp->base__4node == 97)) &&
             ((((struct basetype *)((
                   (struct basetype *)__1actual->__O2__4expr.e1->__O1__4expr.tp))))
                  ->b_name__8basetype->__O1__4expr.tp == __1formal->f__9name_list->__O1__4expr.tp)))
            continue;
        else
            break;
    }

    if ((!__1formal) && (!__1actual))
        return (int)1;
    return (int)0;
}

extern int dont_instantiate;

Ptempl_inst get_match__5templFP4exprP10templ_inst4bool(struct templ *__0this, Pexpr, Ptempl_inst,
                                                       int);

struct templ_inst *__ct__10templ_instFP4exprP5templ(struct templ_inst *__0this, Pexpr __1act,
                                                    Ptempl __1owner);

Ptempl_inst get_inst__5templFP4exprP10templ_inst(register struct templ *__0this, Pexpr __1actuals,
                                                 Ptempl_inst __1exclude) {
    static int __1level = 0;
    ++__1level;

    {
        Ptempl_inst __1inst;
        Ptempl_inst __1ti;
        int __1bl;

        __1inst = get_match__5templFP4exprP10templ_inst4bool(__0this, __1actuals, __1exclude, 0);

        if (__1inst) {
            if ((!__1inst->refp__10templ_inst) && (!dont_instantiate)) {
                if (in_progress__17templ_compilation || (__1level > 1)) {
                    note_ref__10templ_instFv(__1inst);
                } else {
                    __1bl = bl_level;
                    bl_level = 0;
                    __1ti = instantiate__10templ_instF4bool(__1inst, 0);
                    bl_level = __1bl;
                    --__1level;
                    return __1ti;
                }
            }
            --__1level;
            return __1inst;
        }

        __1inst = __ct__10templ_instFP4exprP5templ((struct templ_inst *)0, __1actuals, __0this);
        if (dont_instantiate) {
            --__1level;
            return __1inst;
        }
        ignore_ref = (friend_template__17templ_compilationFP4expr(templp, __1actuals) == 0);

        if (ref_in_friend != 2) {
            if (in_progress__17templ_compilation || (__1level > 1)) {
                note_ref__10templ_instFv(__1inst);
            } else {
                __1bl = bl_level;
                bl_level = 0;
                __1ti = instantiate__10templ_instF4bool(__1inst, 0);
                bl_level = __1bl;
                --__1level;
                return __1ti;
            }
        }
        --__1level;
        return __1inst;
    }
}

int actuals_match__10templ_instFP4expr(struct templ_inst *__0this, Pexpr __1check_actuals);

Ptempl_inst get_match__5templFP4exprP10templ_inst4bool(register struct templ *__0this,
                                                       Pexpr __1actuals, Ptempl_inst __1exclude,
                                                       int __1match_instantiated_only) {
    {
        {
            Ptempl_inst __1p;

            __1p = __0this->insts__5templ;

            for (; __1p; __1p = __1p->next__10templ_inst) {
                if (((__1p != __1exclude) &&
                     actuals_match__10templ_instFP4expr(__1p, __1actuals)) &&
                    (__1match_instantiated_only
                         ? ((((struct classdef *)((
                                 (struct classdef *)(((struct basetype *)(((struct basetype *)__1p
                                                                               ->tname__10basic_inst
                                                                               ->__O1__4expr.tp))))
                                     ->b_name__8basetype->__O1__4expr.tp))))
                                ->class_base__8classdef == 4)
                         : 1))
                    return (__1p->forward__10templ_inst ? __1p->forward__10templ_inst : __1p);
            }
            return (struct templ_inst *)0;
        }
    }
}

int template_hier = 0;

int actuals_match__10funct_instFP4expr(struct funct_inst *__0this, Pexpr);

Pfunct_inst
get_match__17function_templateFP4exprP10funct_inst4bool(register struct function_template *__0this,
                                                        Pexpr __1actuals, Pfunct_inst __1exclude,
                                                        int __1match_instantiate_only) {
    {
        {
            Pfunct_inst __1p;

            __1p = __0this->insts__17function_template;

            for (; __1p; __1p = __1p->next__10funct_inst) {
                if (((__1p != __1exclude) &&
                     actuals_match__10funct_instFP4expr(__1p, __1actuals)) &&
                    (__1match_instantiate_only
                         ? ((((struct templ_fct *)((
                                 (struct templ_fct *)__1p->tname__10basic_inst->__O1__4expr.tp))))
                                ->fct_base__3fct == 4)
                         : 1))
                    return __1p;
            }
            return (struct funct_inst *)0;
        }
    }
}

extern int strncmp(const char *, const char *, size_t);

static void check_actuals__FP4exprP4name(Pexpr __1actuals, Pname __1fn) {
    {
        {
            Pexpr __1ae;

            __1ae = __1actuals;

            for (; __1ae; __1ae = __1ae->__O3__4expr.e2) {
                Ptype __2t;

                __2t = skiptypedefs__4typeFv(__1ae->__O2__4expr.e1->__O1__4expr.tp);
                if (__2t->base__4node == 119)
                    __2t = (struct type *)classtype__4typeFv(__2t);
                if (__2t->base__4node != 6)
                    continue;
                if (strncmp((const char *)"__C",
                            (((struct classdef *)(((struct classdef *)__2t))))->string__8classdef,
                            (unsigned long)3) == 0) {
                    struct ea __0__V129;

                    error__FPCcRC2eaN32(
                        (const char *)"YF%n instantiatedW unnamedC",
                        (const struct ea *)(((&__0__V129)->__O1__2ea.p = ((const void *)__1fn)),
                                            (&__0__V129)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                if (__2t->lex_level__4type && __2t->local_sig__4type) {
                    struct ea __0__V130;

                    struct ea __0__V131;

                    error__FiPCcRC2eaN33(
                        (int)'s', (const char *)"YF%n instantiatedW localC %s",
                        (const struct ea *)(((&__0__V130)->__O1__2ea.p = ((const void *)__1fn)),
                                            (&__0__V130)),
                        (const struct ea *)__ct__2eaFPCv(
                            &__0__V131,
                            (const void *)(((struct classdef *)(((struct classdef *)__2t))))
                                ->string__8classdef),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
        }
    }
}

struct funct_inst *__ct__10funct_instFP4exprP17function_template(struct funct_inst *__0this,
                                                                 Pexpr __1act, Pfunt __1owner);

Pfunct_inst
get_inst__17function_templateFP4exprP10funct_inst(register struct function_template *__0this,
                                                  Pexpr __1actuals, Pfunct_inst __1exclude) {
    Pfunct_inst __1inst;

    __1inst =
        get_match__17function_templateFP4exprP10funct_inst4bool(__0this, __1actuals, __1exclude, 0);
    if (__1inst == 0) {
        check_actuals__FP4exprP4name(__1actuals, __0this->fn__17function_template);
        __1inst = __ct__10funct_instFP4exprP17function_template((struct funct_inst *)0, __1actuals,
                                                                __0this);
    }
    return __1inst;
}

Pname typename4__5templFP4expr(struct templ *__0this, Pexpr __1actuals);

Pname parametrized_typename__FP4nameP4exprUc(Pname __1p, Pexpr __1actuals, bit __1in_friend) {
    Ptempl __1t;

    __1t = is_template__17templ_compilationFP4name(templp, __1p);

    if (current_template__17templ_compilationFP4nameP4expr(templp, __1p, __1actuals) &&
        (__1in_friend == 0))
        return __1p;

    if (__1t) {
        ref_in_friend = __1in_friend;
        {
            Pname __2tname;

            __2tname = typename4__5templFP4expr(__1t, __1actuals);
            ref_in_friend = 0;
            return (__2tname ? __2tname : __1p);
        }
    }
    {
        struct ea __0__V132;

        error__FPCcRC2eaN32(
            (const char *)"%n hasTAs but is not aZizedC",
            (const struct ea *)(((&__0__V132)->__O1__2ea.p = ((const void *)__1p)), (&__0__V132)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        return __1p;
    }
}

Pname typename4__5templFP4expr(register struct templ *__0this, Pexpr __1actuals) {
    return (check_actual_args__5templFP4expr(__0this, __1actuals)
                ? get_inst__5templFP4exprP10templ_inst(__0this, __1actuals, (struct templ_inst *)0)
                      ->tname__10basic_inst
                : (((struct name *)0)));
}

static int expr_match__FP4exprT1(Pexpr __0a1, Pexpr __0a2);

int actuals_match__10templ_instFP4expr(register struct templ_inst *__0this,
                                       Pexpr __1check_actuals) {
    Pexpr __1ae1;

    Pexpr __1ae2;
    Plist __1formal;

    __1formal = __0this->def__10templ_inst->formals__14basic_template;

    for (((__1ae1 = __0this->actuals__10basic_inst), (__1ae2 = __1check_actuals));
         (__1formal && __1ae1) && __1ae2;
         (((__1ae1 = __1ae1->__O3__4expr.e2), (__1ae2 = __1ae2->__O3__4expr.e2)),
          (__1formal = __1formal->l__9name_list)))
        switch (__1formal->f__9name_list->n_template_arg__4name) {
        case 1: {
            Ptype __3t1;
            Ptype __3t2;

            __3t1 = __1ae1->__O2__4expr.e1->__O1__4expr.tp;

            __3t2 = __1ae2->__O2__4expr.e1->__O1__4expr.tp;
            if (check__4typeFP4typeUcT2(__3t1, __3t2, (unsigned char)255, (unsigned char)0) == 1)
                return (int)0;

            break;
        }
        case 2:
            if (!expr_match__FP4exprT1(__1ae1->__O2__4expr.e1, __1ae2->__O2__4expr.e1))
                return (int)0;
            break;

        default:
            error__FiPCc((int)'i', (const char *)"bad template formal");
        }
    return (int)1;
}

extern int exact1__FP4nameP4type(Pname, Ptype);

int actuals_match__10funct_instFP4expr(register struct funct_inst *__0this,
                                       Pexpr __1check_actuals) {
    Pname __1n;
    Pexpr __1e;

    __1n =
        (((struct templ_fct *)(((struct templ_fct *)__0this->tname__10basic_inst->__O1__4expr.tp))))
            ->argtype__3fct;
    __1e = __1check_actuals;

    for (; __1n && __1e; ((__1n = __1n->__O1__4name.n_list), (__1e = __1e->__O3__4expr.e2))) {
        Ptype __2t1;
        Ptype __2t2;

        __2t1 = __1n->__O1__4expr.tp;
        __2t2 = __1e->__O2__4expr.e1->__O1__4expr.tp;

        while (__2t2->base__4node == 97) {
            Pname __3nnn;

            __3nnn = ((((struct basetype *)(((struct basetype *)__2t2))))->b_name__8basetype);

            if (((((unsigned char)(__3nnn->n_template_arg__4name == 1)))))
                __2t2 = ((((struct basetype *)(((struct basetype *)__2t2))))
                             ->b_name__8basetype->__O1__4expr.tp);
            else
                __2t2 = __3nnn->__O1__4expr.tp;
        }

        {
            int __2t_h;

            __2t_h = template_hier;
            template_hier = 0;
            if (exact1__FP4nameP4type(__1n, __2t2)) {
                template_hier = __2t_h;
                continue;
            }
            template_hier = __2t_h;

            if ((__2t2->base__4node == 119) && (__2t1->base__4node == 158)) {
                Ptype __3t;

                __3t =
                    skiptypedefs__4typeFv((((struct ptr *)(((struct ptr *)__2t1))))->typ__5pvtyp);
                if (__3t->base__4node == 119)
                    __2t2 = (struct type *)__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)158,
                                                               __2t2);

            } else if (__2t2->base__4node == 110) {
                __2t2 = (struct type *)__ct__3ptrFUcP4type(
                    (struct ptr *)0, (unsigned char)125,
                    (((struct vec *)(((struct vec *)__2t2))))->typ__5pvtyp);
                if (__2t1->base__4node == 158)
                    __2t2 = (struct type *)__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)158,
                                                               __2t2);
            }

            if (check__4typeFP4typeUcT2(__2t1, __2t2, (unsigned char)204, (unsigned char)0)) {
                if ((!const_problem) ||
                    (((struct ptr *)(((struct ptr *)__2t2))))->typ__5pvtyp->b_const__4type)
                    return (int)0;
                else
                    continue;
            }
        }
    }
    return (int)1;
}

extern char emode;

void stradd__FRPcPCci(char **__1target, const char *__1source, int __1numeric) {
    while (((*((*__1target)))) = ((*__1source))) {
        if ((((*((*__1target)))) == '-') && __1numeric)
            ((*((*__1target)))) = 'n';
        ((*__1target))++;

        __1source++;
    }
}

extern int sprintf(char *, const char *, ...);

extern size_t strlen(const char *);

void stradd__FRPcm(char **__1p, long long __1i) {
    char __1s[64];
    char __1t[128];

    if (!emode) {
        ((*(((*__1p))++))) = 'L';
    }
    sprintf((char *)__1s, (const char *)"%lld", __1i);
    if (!emode) {
        long long __2len;

        __2len = strlen((const char *)__1s);
        if (__2len >= 10)
            sprintf((char *)__1t, (const char *)"%lld_%s", __2len, __1s);
        else
            sprintf((char *)__1t, (const char *)"%lld%s", __2len, __1s);

        stradd__FRPcPCci(__1p, (const char *)__1t, 1);
    } else
        stradd__FRPcPCci(__1p, (const char *)__1s, 0);
}

void stradd__FRPcP4name(char **__1p, Pname __1n) {
    if (!emode) {
        char __2s[1024];

        sprintf((char *)__2s, (const char *)"%d", ((int)strlen(__1n->__O2__4expr.string)));
        stradd__FRPcPCci(__1p, (const char *)__2s, 0);
    }
    stradd__FRPcPCci(__1p, __1n->__O2__4expr.string, 0);
}

char *mangled_expr__FPcP4expr4bool(char *__1p, Pexpr __1e, int __1mangle_for_address);

extern char *strcat(char *, const char *);

extern char *strcpy(char *, const char *);

extern int isalnum(int);

char *mangled_expr__FPcP4expr4bool(char *__1p, Pexpr __1e, int __1mangle_for_address) {
    static int __1mangle_address = 0;
    if (__1e == 0)
        return __1p;

    switch (__1e->base__4node) {
        unsigned long __2__X135;

    case 112:
    case 145:
        ++__1mangle_address;
        if (emode) {
            stradd__FRPcPCci((char **)(&__1p), (const char *)"&", 0);
        }
        __1p = mangled_expr__FPcP4expr4bool(__1p, __1e->__O3__4expr.e2, 0);
        --__1mangle_address;
        break;

    case 85:
        if (__1mangle_address || __1mangle_for_address) {
            Pname __3n;

            __3n = (((struct name *)(((struct name *)__1e))));
            if ((__3n->n_scope__4name == 25) || (__3n->n_scope__4name == 0)) {
                Ptype __4t;

                __4t = __3n->__O1__4expr.tp;
                if (((__3n->n_stclass__4name == 31) && __3n->__O4__4expr.n_table->t_name__5table) ||
                    ((__4t->base__4node == 108) &&
                     (((struct fct *)(((struct fct *)__4t))))->f_static__3fct)) {

                    char __5xx[1024];
                    char __5s[1024];
                    const char *__5st;

                    __5st = ((__4t->base__4node != 108)
                                 ? __3n->__O4__4expr.n_table->t_name__5table->__O2__4expr.string
                                 : (((struct fct *)(((struct fct *)__4t))))
                                       ->memof__3fct->string__8classdef);

                    if (emode) {
                        sprintf((char *)__5s, (const char *)"%s::%s", __5st,
                                __3n->__O2__4expr.string);
                    } else {
                        sprintf((char *)__5xx, (const char *)"%s__%d%s", __3n->__O2__4expr.string,
                                ((int)strlen(__5st)), __5st);
                        sprintf((char *)__5s, (const char *)"%d",
                                ((int)strlen((const char *)__5xx)));
                        strcat((char *)__5s, (const char *)__5xx);
                    }

                    stradd__FRPcPCci((char **)(&__1p), (const char *)__5s, 0);
                } else
                    stradd__FRPcP4name((char **)(&__1p), ((struct name *)(((struct name *)__1e))));
            } else
                stradd__FRPcP4name((char **)(&__1p), ((struct name *)(((struct name *)__1e))));
        } else if ((((struct name *)(((struct name *)__1e))))->n_evaluated__4name)
            stradd__FRPcm((char **)(&__1p),
                          (((struct name *)(((struct name *)__1e))))->n_val__4name);
        else if ((((struct name *)(((struct name *)__1e))))->__O3__4expr.n_initializer) {
            Pexpr __3ee;

            __3ee = (((struct name *)(((struct name *)__1e))))->__O3__4expr.n_initializer;
            if ((__3ee->base__4node == 85) &&
                (((struct name *)(((struct name *)__3ee))))->n_evaluated__4name)
                __1p = mangled_expr__FPcP4expr4bool(__1p, __3ee, 0);
            else
                __1p = mangled_expr__FPcP4expr4bool(__1p, __3ee, 1);
        } else if (((((struct name *)(((struct name *)__1e))))->__O1__4expr.tp->base__4node ==
                    110) ||
                   ((((struct name *)(((struct name *)__1e))))->__O1__4expr.tp->base__4node == 108))
            stradd__FRPcP4name((char **)(&__1p), ((struct name *)(((struct name *)__1e))));
        else {
            struct ea __0__V133;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"mangled_expr: couldn't mangle actualYE %n",
                (const struct ea *)(((&__0__V133)->__O1__2ea.p = ((const void *)__1e)),
                                    (&__0__V133)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        break;

    case 150:
        stradd__FRPcm((char **)(&__1p), (((struct ival *)(((struct ival *)__1e))))->__O2__4expr.i1);
        break;

    case 113:
    case 191: {
        if (__1e->__O2__4expr.e1->base__4node == 150) {
            stradd__FRPcm(
                (char **)(&__1p),
                (((struct ival *)(((struct ival *)__1e->__O2__4expr.e1))))->__O2__4expr.i1);
            break;
        } else if (__1e->__O2__4expr.e1->base__4node == 86) {
            ((*(__1p++))) = '0';
            break;
        } else if ((__1e->__O2__4expr.e1->base__4node != 82) &&
                   (__1e->__O2__4expr.e1->base__4node != 84)) {
            if (emode) {
                Neval = 0;

                {
                    long long __5e_eval;

                    __5e_eval = eval__4exprFv(__1e);
                    if (!Neval) {
                        stradd__FRPcm((char **)(&__1p), __5e_eval);
                        break;
                    }
                }
            }
            error__FiPCc((int)'i', (const char *)"mangled_expr: unexpected cast in YE");
            break;
        } else
            __1e = __1e->__O2__4expr.e1;
    }

    case 82:
    case 84: {
        if (!emode) {
            ((*(__1p++))) = 'L';
        }
        {
            size_t __3len;
            char __3s[64];

            __3len = strlen(__1e->__O2__4expr.string);

            if (!emode) {
                if (__3len >= 10)
                    sprintf((char *)__3s, (const char *)"%ld_%s", __3len, __1e->__O2__4expr.string);
                else
                    sprintf((char *)__3s, (const char *)"%ld%s", __3len, __1e->__O2__4expr.string);
            } else {
                sprintf((char *)__3s, (const char *)"%s", __1e->__O2__4expr.string);
            }
            strcpy(__1p, (const char *)__3s);

            if (!emode)
                while ((*__1p))
                    if (!isalnum((int)((*__1p))))
                        switch ((*__1p)) {
                        case '+':
                            ((*(__1p++))) = 'p';

                            break;
                        case '-':
                            ((*(__1p++))) = 'n';
                            break;
                        case '.':
                            ((*(__1p++))) = 'D';
                            break;
                        case 'e':
                            ((*(__1p++))) = 'E';
                            break;
                        default:
                            error__FiPCc((int)'i', (const char *)"bad character in constant");
                            break;
                        }
                    else
                        __1p++;
            break;
        }
    }
    case 86:
        ((*(__1p++))) = '0';
        break;
    case 124: {
        if (emode) {
            stradd__FRPcPCci((char **)(&__1p), (const char *)"&class::member", 0);
            break;
        }
        {
            Pexpr __3i1;
            Pexpr __3i2;
            Pexpr __3i3;

            __3i1 = __1e->__O2__4expr.e1->__O2__4expr.e1;
            __3i2 = __1e->__O2__4expr.e1->__O3__4expr.e2;
            __3i3 = (((__1e->__O3__4expr.e2->base__4node == 113) ||
                      (__1e->__O3__4expr.e2->base__4node == 191))
                         ? __1e->__O3__4expr.e2->__O2__4expr.e1
                         : __1e->__O3__4expr.e2);

            ((*(__1p++))) = 'L';

            ((*(__1p++))) = 'M';
            __1p = mangled_expr__FPcP4expr4bool(__1p, __3i1, 0);

            ((*(__1p++))) = '_';
            __1p = mangled_expr__FPcP4expr4bool(__1p, __3i2, 0);

            ((*(__1p++))) = '_';
            if (__3i3->base__4node != 85)
                __1p = mangled_expr__FPcP4expr4bool(__1p, __3i3, 0);
            else
                __1p = mangled_expr__FPcP4expr4bool(__1p, __3i3, 1);
        }
    } break;
    case 45:
    case 44:
        if (__1mangle_address) {
            while ((__1e->base__4node == 45) || (__1e->base__4node == 44))
                __1e = (((struct expr *)(((struct expr *)__1e->__O4__4expr.mem))));
            __1p = mangled_expr__FPcP4expr4bool(__1p, __1e->__O3__4expr.e2, 0);
            break;
        }

    default:
        if (emode) {
            Neval = 0;
            {
                long long __3e_eval;

                __3e_eval = eval__4exprFv(__1e);
                if (!Neval) {
                    stradd__FRPcm((char **)(&__1p), __3e_eval);
                    break;
                }
            }
        }
        {
            struct ea __0__V134;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"can't mangle %k",
                (const struct ea *)((__2__X135 = __1e->base__4node),
                                    (((((&__0__V134)->__O1__2ea.i = __2__X135), 0)), (&__0__V134))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
    }

    return __1p;
}

void dcl_print__4typeFP4name(struct type *__0this, Pname);

extern void *memset(void *, int, size_t);

void print_pretty_name__10templ_instFv(register struct templ_inst *__0this) {
    extern char emode;

    Pname __1n;

    const void *__2__X138;

    __1n =
        (((struct templ_inst *)(((struct templ_inst *)__0this))))->def__10templ_inst->namep__5templ;
    {
        struct ea __0__V136;

        error__FiPCcRC2eaN33(
            (int)'c', (const char *)" %s<",
            (const struct ea *)((__2__X138 = (const void *)(__1n ? __1n->__O2__4expr.string
                                                                 : (((const char *)"?")))),
                                (((&__0__V136)->__O1__2ea.p = __2__X138), (&__0__V136))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

        {
            Plist __1formal;

            __1formal = __0this->inst_formals__10basic_inst;
            emode++;

            {
                {
                    Pexpr __1ae1;

                    __1ae1 = __0this->actuals__10basic_inst;

                    for (; __1formal && __1ae1; ((__1ae1 = __1ae1->__O3__4expr.e2),
                                                 (__1formal = __1formal->l__9name_list))) {
                        if (__1ae1->__O2__4expr.e1->base__4node == 0)
                            break;
                        switch (__1formal->f__9name_list->n_template_arg__4name) {
                        case 1:
                            dcl_print__4typeFP4name(__1ae1->__O2__4expr.e1->__O1__4expr.tp,
                                                    (struct name *)0);
                            break;
                        case 2: {
                            char __4buff[1024];
                            memset((void *)__4buff, 0, (unsigned long)1024);
                            mangled_expr__FPcP4expr4bool((char *)__4buff, __1ae1->__O2__4expr.e1,
                                                         0);
                            {
                                struct ea __0__V137;

                                error__FiPCcRC2eaN33(
                                    (int)'c', (const char *)"%s",
                                    (const struct ea *)(((&__0__V137)->__O1__2ea.p =
                                                             ((const void *)__4buff)),
                                                        (&__0__V137)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                break;
                            }
                        }
                        default:
                            error__FiPCc((int)'i', (const char *)"unexpected formalZ");
                        }

                        if (__1formal->l__9name_list)
                            error__FiPCc((int)'c', (const char *)", ");
                    }
                    error__FiPCc((int)'c', (const char *)">");
                    emode--;
                }
            }
        }
    }
}

void print_pretty_name__10funct_instFv(register struct funct_inst *__0this) {
    extern char emode;
    emode++;

    {
        Pname __1n;

        const void *__2__X140;

        __1n = (((struct funct_inst *)(((struct funct_inst *)__0this))))
                   ->def__10funct_inst->fn__17function_template;
        {
            struct ea __0__V139;

            error__FiPCcRC2eaN33(
                (int)'c', (const char *)" %s(",
                (const struct ea *)((__2__X140 = (const void *)(__1n ? __1n->__O2__4expr.string
                                                                     : (((const char *)"?")))),
                                    (((&__0__V139)->__O1__2ea.p = __2__X140), (&__0__V139))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

            __1n = (((struct templ_fct *)((
                        (struct templ_fct *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                       ->argtype__3fct;
            for (; __1n; __1n = __1n->__O1__4name.n_list) {
                Ptype __2t;

                __2t = __1n->__O1__4expr.tp;
                if ((!__2t) || (__2t->base__4node == 0))
                    continue;
                dcl_print__4typeFP4name(__2t, (struct name *)0);
                if (__1n->__O1__4name.n_list)
                    error__FiPCc((int)'c', (const char *)", ");
            }

            error__FiPCc((int)'c', (const char *)")");
            emode--;
        }
    }
}

static int check_expr__FUc(TOK __1b) {
    switch (__1b) {
    default:
        return 0;
    case 82:
    case 150:
    case 86:
    case 84:
    case 113:
    case 191:
    case 121:
    case 30:
    case 47:
    case 107:
    case 172:
    case 46:
    case 54:
    case 55:
    case 50:
    case 56:
    case 57:
    case 63:
    case 58:
    case 60:
    case 61:
    case 59:
    case 52:
    case 65:
    case 64:
    case 51:
    case 53:
    case 62:
    case 66:
    case 67:
    case 71:
    case 147:
    case 68:
        return 1;
    }
}

int check_for_const__FP4exprT1(Pexpr __1a1, Pexpr __1a2) {
    Neval = 0;
    if ((__1a1->base__4node != 85) && (__1a2->base__4node != 85)) {
        if ((__1a1->__O1__4expr.tp && __1a2->__O1__4expr.tp) &&
            check__4typeFP4typeUcT2(__1a1->__O1__4expr.tp, __1a2->__O1__4expr.tp,
                                    (unsigned char)255, (unsigned char)0))
            return (int)0;
        while ((__1a1->base__4node == 113) || (__1a1->base__4node == 191)) {
            TOK __3b1;

            __3b1 = skiptypedefs__4typeFv(__1a1->__O4__4expr.tp2)->base__4node;
            if (((((((__3b1 == 5) || (__3b1 == 29)) || (__3b1 == 21)) || (__3b1 == 22)) ||
                  (__3b1 == 122)) ||
                 (__3b1 == 13)) ||
                (__3b1 == 121))
                break;
            __1a1 = __1a1->__O2__4expr.e1;
        }
        while ((__1a2->base__4node == 113) || (__1a2->base__4node == 191)) {
            TOK __3b2;

            __3b2 = skiptypedefs__4typeFv(__1a2->__O4__4expr.tp2)->base__4node;
            if (((((((__3b2 == 5) || (__3b2 == 29)) || (__3b2 == 21)) || (__3b2 == 22)) ||
                  (__3b2 == 122)) ||
                 (__3b2 == 13)) ||
                (__3b2 == 121))
                break;
            __1a2 = __1a2->__O2__4expr.e1;
        }
        {
            long long __2a1_eval;
            long long __2a2_eval;

            __2a1_eval = eval__4exprFv(__1a1);
            __2a2_eval = eval__4exprFv(__1a2);
            if (Neval)
                return (int)0;
            return (__2a1_eval == __2a2_eval);
        }
    }

    if ((__1a1->base__4node == 85) && check_expr__FUc(__1a2->base__4node)) {
        Pname __2n;
        long long __2a2_eval;

        __2n = (((struct name *)(((struct name *)__1a1))));
        __2a2_eval = eval__4exprFv(__1a2);
        return (((!Neval) && __2n->n_evaluated__4name) && (__2n->n_val__4name == __2a2_eval));
    } else if ((__1a2->base__4node == 85) && check_expr__FUc(__1a1->base__4node)) {
        Pname __2n;
        long long __2a1_eval;

        __2n = (((struct name *)(((struct name *)__1a2))));
        __2a1_eval = eval__4exprFv(__1a1);
        return (((!Neval) && __2n->n_evaluated__4name) && (__2n->n_val__4name == __2a1_eval));
    }

    if (((__1a1->base__4node == 85) &&
         ((__1a2->base__4node == 112) || (__1a2->base__4node == 145))) &&
        (__1a1 == __1a2->__O3__4expr.e2))
        return (int)1;

    if (((__1a2->base__4node == 85) &&
         ((__1a1->base__4node == 112) || (__1a1->base__4node == 145))) &&
        (__1a2 == __1a1->__O3__4expr.e2))
        return (int)1;

    if ((((__1a1->base__4node == 85) && (__1a2->base__4node == 124)) && __1a1->__O1__4expr.tp) &&
        __1a2->__O1__4expr.tp)
        return (int)((!check__4typeFP4typeUcT2(__1a1->__O1__4expr.tp, __1a2->__O1__4expr.tp,
                                               (unsigned char)255, (unsigned char)0))
                         ? 1
                         : 0);

    if ((((__1a2->base__4node == 85) && (__1a1->base__4node == 124)) && __1a1->__O1__4expr.tp) &&
        __1a2->__O1__4expr.tp)
        return (int)((!check__4typeFP4typeUcT2(__1a2->__O1__4expr.tp, __1a1->__O1__4expr.tp,
                                               (unsigned char)255, (unsigned char)0))
                         ? 1
                         : 0);

    return (int)0;
}

static Pexpr real_expression__FP4expr(Pexpr __1e) {
    while ((((__1e && (__1e->base__4node == 85)) &&
             ((((struct name *)(((struct name *)__1e))))->n_template_arg__4name == 2)) &&
            (!(((struct name *)(((struct name *)__1e))))->n_evaluated__4name)) &&
           (((struct name *)(((struct name *)__1e))))->__O3__4expr.n_initializer)
        __1e = (((struct name *)(((struct name *)__1e))))->__O3__4expr.n_initializer;
    return __1e;
}

static int expr_match__FP4exprT1(Pexpr __1a1, Pexpr __1a2) {
    static int __1addr_of = 0;

    __1a1 = (__1addr_of ? __1a1 : real_expression__FP4expr(__1a1));
    __1a2 = (__1addr_of ? __1a2 : real_expression__FP4expr(__1a2));

    if (__1a1 == __1a2)
        return (int)1;

    if (__1a1->base__4node != __1a2->base__4node)
        return check_for_const__FP4exprT1(__1a1, __1a2);
    Neval = 0;
    switch (__1a1->base__4node) {
    case 68:
        return ((expr_match__FP4exprT1(__1a1->__O4__4expr.cond, __1a2->__O4__4expr.cond) &&
                 expr_match__FP4exprT1(__1a1->__O2__4expr.e1, __1a2->__O2__4expr.e1)) &&
                expr_match__FP4exprT1(__1a1->__O3__4expr.e2, __1a2->__O3__4expr.e2));

    case 54:
    case 55:
    case 50:
    case 51:
    case 53:
    case 64:
    case 65:
    case 66:
    case 67:
    case 56:
    case 57:
    case 62:
    case 63:
    case 58:
    case 59:
    case 60:
    case 61:
        return (expr_match__FP4exprT1(__1a1->__O2__4expr.e1, __1a2->__O2__4expr.e1) &&
                expr_match__FP4exprT1(__1a1->__O3__4expr.e2, __1a2->__O3__4expr.e2));

    case 107:
    case 172:
    case 46:
    case 47:
        return expr_match__FP4exprT1(__1a1->__O3__4expr.e2, __1a2->__O3__4expr.e2);
    case 112:
    case 145: {
        __1addr_of++;
        {
            int __3result;

            __3result = expr_match__FP4exprT1(__1a1->__O3__4expr.e2, __1a2->__O3__4expr.e2);
            __1addr_of--;
            return __3result;
        }
    }
    case 113:
    case 191: {
        TOK __3b1;
        TOK __3b2;

        __3b1 = __1a1->__O2__4expr.e1->base__4node;
        __3b2 = __1a2->__O2__4expr.e1->base__4node;
        if (((((__3b1 == 82) || (__3b1 == 150)) || (__3b1 == 84)) || (__3b1 == 86)) &&
            ((((__3b2 == 82) || (__3b2 == 150)) || (__3b2 == 84)) || (__3b2 == 86)))
            return check_for_const__FP4exprT1(__1a1, __1a2);
        else
            return expr_match__FP4exprT1(__1a1->__O2__4expr.e1, __1a2->__O2__4expr.e1);
    }
    case 85: {
        Pname __3n1;

        Pname __3n2;

        __3n1 = (((struct name *)(((struct name *)__1a1))));

        __3n2 = (((struct name *)(((struct name *)__1a2))));
        if (!__1addr_of) {
            if ((__3n1->n_evaluated__4name && __3n2->n_evaluated__4name) &&
                (__3n1->n_val__4name == __3n2->n_val__4name))
                return (int)1;

            if (__3n1->__O3__4expr.n_initializer && (!__3n2->__O3__4expr.n_initializer))
                return check_for_const__FP4exprT1((struct expr *)__3n2,
                                                  __3n1->__O3__4expr.n_initializer);
            if (__3n2->__O3__4expr.n_initializer && (!__3n1->__O3__4expr.n_initializer))
                return check_for_const__FP4exprT1((struct expr *)__3n1,
                                                  __3n2->__O3__4expr.n_initializer);
            if (__3n1->__O3__4expr.n_initializer && __3n2->__O3__4expr.n_initializer)
                return expr_match__FP4exprT1(__3n1->__O3__4expr.n_initializer,
                                             __3n2->__O3__4expr.n_initializer);
        }
        if (formals_in_progress__17templ_compilation)
            return (strcmp(__3n1->__O2__4expr.string, __3n2->__O2__4expr.string) == 0);
        return (int)0;
    }
    case 45:
        return expr_match__FP4exprT1(__1a1->__O2__4expr.e1, __1a2->__O2__4expr.e1);
    case 44:
        return expr_match__FP4exprT1(__1a1->__O2__4expr.e1, __1a2->__O2__4expr.e1);
    case 150:
        return (__1a1->__O2__4expr.i1 == __1a2->__O2__4expr.i1);
    case 82:
    case 84: {
        int __3i;
        __3i = (eval__4exprFv(__1a1) == eval__4exprFv(__1a2));
        if (Neval)
            error__FPCc((const char *)"cannot evaluate constantE");
        return __3i;
    }
    case 83:
    case 81:
        return (strcmp(__1a1->__O2__4expr.string, __1a2->__O2__4expr.string) == 0);
    case 86:
        return (int)1;
    case 30: {
        long long __3l1;

        long long __3l2;

        __3l1 = eval__4exprFv(__1a1);

        __3l2 = eval__4exprFv(__1a2);
        if (Neval)
            return (int)0;
        return (__3l1 == __3l2);
    }
    case 124:
        if ((__1a1->__O1__4expr.tp && __1a2->__O1__4expr.tp) &&
            (!check__4typeFP4typeUcT2(__1a1->__O1__4expr.tp, __1a2->__O1__4expr.tp,
                                      (unsigned char)255, (unsigned char)0)))
            return (int)1;
        else
            return (int)0;
    }
    return (int)0;
}

char *signature__4typeFPci(struct type *__0this, char *, int);

static char *non_type_argument_signature__FP4exprPc(Pexpr __1e, char *__1p) {
    __1p = signature__4typeFPci(__1e->__O1__4expr.tp, __1p, 0);
    return mangled_expr__FPcP4expr4bool(__1p, __1e, 0);
}

static int check_nest__FPci(char *__1s, int __1max);

static int check_nest__FPci(char *__1s, int __1max) {
    char *__1t;
    char *__1t2;
    int __1len;
    int __1n;
    int __1maxn;

    __1t = __1s;
    __1maxn = 0;
    while (((*__1t)) && (__1t < (__1s + __1max))) {
        if (((((((__1t[0]) == '_') && ((__1t[1]) == '_')) && ((__1t[2]) == 'p')) &&
              ((__1t[3]) == 't')) &&
             ((__1t[4]) == '_')) &&
            ((__1t[5]) == '_')) {
            __1t2 = (__1t + 6);
            __1len = 0;
            while ((((*__1t2)) >= '0') && (((*__1t2)) <= '9')) {
                __1len = (((__1len * 10) + ((*__1t2))) - '0');
                __1t2++;
            }
            __1n = (1 + check_nest__FPci(__1t2, __1len));
            if (__1n > __1maxn)
                __1maxn = __1n;
        }
        __1t++;
    }
    return __1maxn;
}

char *mangled_name__10templ_instFPc(register struct templ_inst *__0this, char *__1ip) {
    char *__1start;

    __1start = __1ip;
    __1ip = __1start;
    strcpy(__1ip, __0this->def__10templ_inst->namep__5templ
                      ? __0this->def__10templ_inst->namep__5templ->__O2__4expr.string
                      : (((const char *)"?")));
    __1ip = (__1start + strlen((const char *)__1start));
    stradd__FRPcPCci((char **)(&__1ip), (const char *)"__pt__", 0);

    {
        char __2a[1024];

        char *__2p;
        Plist __2formal;

        __2p = __2a;
        __2formal = __0this->inst_formals__10basic_inst;

        {
            {
                Pexpr __2ae1;

                __2ae1 = __0this->actuals__10basic_inst;

                for (; __2ae1;
                     ((__2ae1 = __2ae1->__O3__4expr.e2), (__2formal = __2formal->l__9name_list)))
                    switch (__2formal->f__9name_list->n_template_arg__4name) {
                        unsigned long __2__X142;

                    case 2:
                        ((*(__2p++))) = 'X';

                        __2p = non_type_argument_signature__FP4exprPc(
                            (struct expr *)__2formal->f__9name_list, __2p);
                        break;

                    case 1:
                        __2p =
                            signature__4typeFPci(__2ae1->__O2__4expr.e1->__O1__4expr.tp, __2p, 1);
                        break;

                    default: {
                        struct ea __0__V141;

                        error__FPCcRC2eaN32(
                            (const char *)"bad template formal:%d",
                            (const struct ea *)((__2__X142 = __2formal->f__9name_list->base__4node),
                                                (((((&__0__V141)->__O1__2ea.i = __2__X142), 0)),
                                                 (&__0__V141))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        break;
                    }
                    }

                ((*__2p)) = 0;
                sprintf(__1ip, (const char *)"%d_", (((int)strlen((const char *)__2a))) + 1);
                __1ip = (__1start + strlen((const char *)__1start));
                strcpy(__1ip, (const char *)__2a);
            }
        }
    }

    if (check_nest__FPci(__1start, 9999) > 16) {
        if (!error_count)
            error__FPCc((const char *)"infinite template instantiation sequence");
        else
            error__FiPCc((int)'i', (const char *)"infinite template instantiation sequence");
    }

    return __1start;
}

char *mangled_name__10funct_instFPc(register struct funct_inst *__0this, char *__1ip) {
    char *__1start;

    __1start = __1ip;
    __1ip = __1start;
    strcpy(__1ip, __0this->def__10funct_inst->fn__17function_template
                      ? __0this->def__10funct_inst->fn__17function_template->__O2__4expr.string
                      : (((const char *)"?")));
    __1ip = (__1start + strlen((const char *)__1start));
    stradd__FRPcPCci((char **)(&__1ip), (const char *)"__pt__", 0);

    {
        char __1buf[1024];

        char *__1p;

        Ptype __1t;

        __1p = __1buf;

        if ((((struct templ_fct *)((
                (struct templ_fct *)__0this->tname__10basic_inst->__O1__4expr.tp)))) &&
            (((struct templ_fct *)((
                 (struct templ_fct *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                ->argtype__3fct) {
            Pname __2n;

            __2n = (((struct templ_fct *)((
                        (struct templ_fct *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                       ->argtype__3fct;
            for (; __2n; __2n = __2n->__O1__4name.n_list) {
                __1t = __2n->__O1__4expr.tp;
                if (__1t->base__4node == 138)
                    __1t = (struct type *)int_type;
                __1p = signature__4typeFPci(__1t, __1p, 0);
                ((*(__1p++))) = '_';
            }
        } else {
            {
                {
                    Pexpr __2ae;

                    __2ae = __0this->actuals__10basic_inst;

                    for (; __2ae; __2ae = __2ae->__O3__4expr.e2) {
                        __1t = __2ae->__O2__4expr.e1->__O1__4expr.tp;
                        if (__1t->base__4node == 138)
                            __1t = (struct type *)int_type;
                        __1p = signature__4typeFPci(__1t, __1p, 0);
                        ((*(__1p++))) = '_';
                    }
                }
            }
        }

        if (__0this->actuals__10basic_inst)
            --__1p;
        ((*__1p)) = 0;
        sprintf(__1ip, (const char *)"F%d_", ((int)(strlen((const char *)__1buf) + 1)));
        __1ip = (__1start + strlen((const char *)__1start));
        strcpy(__1ip, (const char *)__1buf);

        return __1start;
    }
}

static const char leader[2] = "\t";

extern int fputc(int, void *);

extern void print_loc__Fv(void);

void print_pretty_name__10basic_instFv(struct basic_inst *__0this);

void print_error_loc__10basic_instFi(register struct basic_inst *__0this, int __1newline) {
    if (!head__10basic_inst)
        return;

    {
        struct state __1current_state;

        const void *__2__X147;

        ((0), (&__1current_state));

        if (__1newline)
            fputc((int)'\n', out_file);
        save__5stateFv(&__1current_state);
        print_loc__Fv();
        {
            struct ea __0__V143;

            error__FiPCcRC2eaN33(
                (int)'c', (const char *)"%serror detected during the instantiation of",
                (const struct ea *)((__2__X147 = (const void *)leader),
                                    (((&__0__V143)->__O1__2ea.p = __2__X147), (&__0__V143))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            ((*(((void (*)(struct basic_inst *__0this))(__0this->__vptr__10basic_inst[2]).f))))((
                (struct basic_inst *)((((char *)__0this)) + (__0this->__vptr__10basic_inst[2]).d)));
            fputc((int)'\n', out_file);

            if (!head__10basic_inst->next_active__10basic_inst) {
                const void *__2__X148;

                restore__5stateFv(&__0this->context__10basic_inst);
                print_loc__Fv();
                {
                    struct ea __0__V144;

                    error__FiPCcRC2eaN33(
                        (int)'c', (const char *)"%sis the site of the instantiation\n",
                        (const struct ea *)((__2__X148 = (const void *)leader),
                                            (((&__0__V144)->__O1__2ea.p = __2__X148),
                                             (&__0__V144))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            } else {
                const void *__2__X149;

                print_loc__Fv();
                {
                    struct ea __0__V145;

                    error__FiPCcRC2eaN33(
                        (int)'c', (const char *)"%sthe instantiation path was:\n",
                        (const struct ea *)((__2__X149 = (const void *)leader),
                                            (((&__0__V145)->__O1__2ea.p = __2__X149),
                                             (&__0__V145))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    {
                        {
                            Pbase_inst __2p;

                            __2p = head__10basic_inst;

                            for (; __2p; __2p = __2p->next_active__10basic_inst) {
                                const void *__2__X150;

                                restore__5stateFv(&__2p->context__10basic_inst);
                                print_loc__Fv();
                                {
                                    struct ea __0__V146;

                                    error__FiPCcRC2eaN33(
                                        (int)'c', (const char *)"%s template:",
                                        (const struct ea *)((__2__X150 = (const void *)leader),
                                                            (((&__0__V146)->__O1__2ea.p =
                                                                  __2__X150),
                                                             (&__0__V146))),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    ((*(((void (*)(struct basic_inst *__0this))(
                                             __2p->__vptr__10basic_inst[2])
                                             .f))))(
                                        ((struct basic_inst *)((((char *)__2p)) +
                                                               (__2p->__vptr__10basic_inst[2]).d)));
                                    fputc((int)'\n', out_file);
                                }
                            }
                        }
                    }
                }
            }
            restore__5stateFv(&__1current_state);
        }
    }
}

char *mangled_name__10basic_instFPc(struct basic_inst *__0this, char *);

extern char *strdup(const char *);

char *instantiation_string__10basic_instFv(struct basic_inst *__0this) {
    char __1inst_name[1024];
    {
        {
            int __1i;

            __1i = 0;

            for (; __1i < 1024; ++__1i)
                (__1inst_name[__1i]) = 0;
            ((*(((char *(*)(struct basic_inst * __0this, char *))(__0this->__vptr__10basic_inst[3])
                     .f))))(
                ((struct basic_inst *)((((char *)__0this)) + (__0this->__vptr__10basic_inst[3]).d)),
                (char *)__1inst_name);

            return strdup((const char *)__1inst_name);
        }
    }
}

void modify_inst_names__8classdefFPCc(register struct classdef *__0this, const char *__1s) {
    const char *__1old;

    __1old = __0this->string__8classdef;
    __0this->string__8classdef = __1s;
    if (__0this->lex_level__4type &&
        ((__0this->in_class__4type == 0) ||
         (__0this->lex_level__4type != __0this->in_class__4type->lex_level__4type))) {
        error__FiPCc((int)'i', (const char *)"localCY");

    } else
        __0this->c_strlen__8classdef = strlen(__1s);

    {
        {
            Pname __1p;

            __1p = __0this->mem_list__8classdef;

            for (; __1p; __1p = __1p->__O1__4name.n_list)
                if ((__1p->__O1__4expr.tp && (__1p->__O1__4expr.tp->base__4node == 108)) &&
                    (!strcmp(__1old, __1p->__O2__4expr.string)))
                    __1p->__O2__4expr.string = __1s;
        }
    }
}

Ptype non_template_arg_type__FP8basetype(Pbase __1t);

Ptype non_template_arg_type__FP8basetype(Pbase __1t) {
    if ((__1t->base__4node == 97) && (__1t->b_name__8basetype->n_template_arg__4name == 1))
        return non_template_arg_type__FP8basetype(
            ((struct basetype *)(((struct basetype *)__1t->b_name__8basetype->__O1__4expr.tp))));
    else
        return (struct type *)__1t;
}

void non_template_arg_non_type__FP4name(Pname __1n) {
    Pexpr __1i;

    __1i = __1n->__O3__4expr.n_initializer;
    while ((__1i && (__1i->base__4node == 85)) &&
           ((((struct name *)(((struct name *)__1i))))->n_template_arg__4name == 2)) {
        if ((((struct name *)(((struct name *)__1i))))->__O3__4expr.n_initializer) {
            __1n->__O3__4expr.n_initializer =
                (((struct name *)(((struct name *)__1i))))->__O3__4expr.n_initializer;
            __1i = __1n->__O3__4expr.n_initializer;
            continue;
        }
        if ((((struct name *)(((struct name *)__1i))))->n_evaluated__4name) {
            __1n->n_evaluated__4name = 1;
            __1n->n_val__4name = (((struct name *)(((struct name *)__1i))))->n_val__4name;
            return;
        }
    }
    return;
}

void forward_template_arg_types__FP9name_listP4expr(Plist __1formal, Pexpr __1actuals) {
    {
        {
            Pexpr __1actual;

            __1actual = __1actuals;

            for (; __1formal && __1actual;
                 ((__1formal = __1formal->l__9name_list), (__1actual = __1actual->__O3__4expr.e2)))
                switch (__1formal->f__9name_list->n_template_arg__4name) {
                case 1:
                    __1actual->__O2__4expr.e1->__O1__4expr.tp =
                        non_template_arg_type__FP8basetype(((struct basetype *)((
                            (struct basetype *)__1actual->__O2__4expr.e1->__O1__4expr.tp))));
                    break;
                case 2:
                    break;
                default:
                    error__FiPCc((int)'i', (const char *)"bad template formal");
                }
        }
    }
}

static int suitable_const_expr__FP4name(Pname __1n) {
    if (__1n->n_evaluated__4name)
        return 1;
    {
        Pexpr __1ee;

        __1ee = __1n->__O3__4expr.n_initializer;
        if (__1ee == 0)
            return 0;

        switch (__1ee->base__4node) {
        case 113:
        case 191: {
            Pexpr __3e;

            __3e = __1ee->__O2__4expr.e1;

            if ((((__3e->base__4node == 150) || (__3e->base__4node == 82)) ||
                 (__3e->base__4node == 84)) ||
                (__3e->base__4node == 86))
                return 1;

            return -2;
        }

        case 86:
            return 1;
        case 112:
        case 145: {
            bit __3mbr;
            Pexpr __3e;

            __3mbr = 0;
            __3e = __1ee->__O3__4expr.e2;
            while ((__3e->base__4node == 45) || (__3e->base__4node == 44)) {
                const void *__2__X154;

                unsigned long __2__X155;

                if ((__3e->__O2__4expr.e1->base__4node == 109) ||
                    (__3e->__O2__4expr.e1->base__4node == 146))
                    return 0;

                if ((__3e->__O4__4expr.mem->base__4node != 45) &&
                    (__3e->__O4__4expr.mem->base__4node != 44)) {
                    struct ea __0__V151;

                    struct ea __0__V152;

                    struct ea __0__V153;

                    error__FiPCcRC2eaN33(
                        (int)'s', (const char *)"address of boundM (&%n%k%n) as actualYA",
                        (const struct ea *)((__2__X154 = (const void *)__3e->__O2__4expr.e1),
                                            (((&__0__V151)->__O1__2ea.p = __2__X154),
                                             (&__0__V151))),
                        (const struct ea *)((__2__X155 = __3e->base__4node),
                                            (((((&__0__V152)->__O1__2ea.i = __2__X155), 0)),
                                             (&__0__V152))),
                        (const struct ea *)__ct__2eaFPCv(&__0__V153,
                                                         (const void *)__3e->__O4__4expr.mem),
                        (const struct ea *)ea0);
                }
                __3e = (((struct expr *)(((struct expr *)__3e->__O4__4expr.mem))));
                ++__3mbr;
            }
            {
                Pname __3an;

                __3an = (((struct name *)(((struct name *)__3e))));

                if (__3an->base__4node != 85)
                    return 0;
                if (__3an->n_sto__4name == 31)
                    return -3;
                if ((__3an->n_stclass__4name == 31) || __3mbr)
                    return 1;
                if (((__3an->__O1__4expr.tp->base__4node == 108) &&
                     (((struct fct *)(((struct fct *)__3an->__O1__4expr.tp))))->f_static__3fct) &&
                    (((struct fct *)(((struct fct *)__3an->__O1__4expr.tp))))->memof__3fct)
                    return 1;
                return 0;
            }
        }
        case 85: {
            Pname __3an;

            __3an = (((struct name *)(((struct name *)__1n->__O3__4expr.n_initializer))));
            if ((__3an->n_stclass__4name == 31) &&
                ((__3an->__O1__4expr.tp->base__4node == 110) ||
                 (__3an->__O1__4expr.tp->b_const__4type && __3an->n_evaluated__4name)))
                return 1;

            return 0;
        }
        case 124:
            if (__1ee->__O3__4expr.e2)
                return 1;
            return 0;
        case 81:
            return -1;
        default:
            return 0;
        }
    }
}

static int const_formal_hack__FP4name(Pname __1n) {
    if (!const_problem)
        return 0;
    switch (__1n->__O1__4expr.tp->base__4node) {
    case 158:
    case 110:
    case 15:
    case 11:
    case 181:
        return 0;

    case 138:
    case 5:
    case 29:
    case 21:
    case 22:
    case 122:
    case 114:
    case 121:
    case 119:
    case 97:
    case 141: {
        Pbase __3b;

        __3b = (((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp))));
        if (__3b->b_const__4type == 2)
            return 1;
        return 0;
    }
    case 125: {
        Pptr __3b;

        __3b = (((struct ptr *)(((struct ptr *)__1n->__O1__4expr.tp))));
        if (__3b->b_const__4type == 2)
            return 1;
        return 0;
    }
    }
    return 0;
}

char *make_formal_name__FPCcT1(const char *__1fns, const char *__1ins) {
    char __1s[1024];
    char __1t[6];
    strcpy((char *)__1s, __1fns);
    sprintf((char *)__1t, (const char *)"__%d", ((int)strlen(__1ins)));
    strcat((char *)__1s, (const char *)__1t);
    strcat((char *)__1s, __1ins);

    {
        char *__1result;

        __1result =
            (((char *)__nw__FUl((size_t)((sizeof(char)) * (strlen((const char *)__1s) + 1)))));
        strcpy(__1result, (const char *)__1s);
        return __1result;
    }
}

Pexpr typ__4exprFP5table(struct expr *__0this, Ptable);

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);

void bind_formals__10templ_instFv(register struct templ_inst *__0this) {
    Pexpr __1actual;
    Plist __1formal;

    for (((__1formal = __0this->inst_formals__10basic_inst),
          (__1actual = __0this->actuals__10basic_inst));
         __1formal && __1actual;
         ((__1formal = __1formal->l__9name_list), (__1actual = __1actual->__O3__4expr.e2))) {
        switch (__1formal->f__9name_list->n_template_arg__4name) {
        case 1: {
            Ptype __4t;

            __4t = non_template_arg_type__FP8basetype(((struct basetype *)((
                (struct basetype *)__1actual->__O2__4expr.e1->__O1__4expr.tp))));
            if (__4t->base__4node == 110) {
                Pvec __5v;

                const void *__2__X162;

                __5v = (((struct vec *)(((struct vec *)__4t))));
                if ((__5v->dim__3vec == 0) && (__5v->size__3vec == 0)) {
                    struct ea __0__V156;

                    error__FPCcRC2eaN32(
                        (const char *)"actual vectorZ%t must include dimension",
                        (const struct ea *)((__2__X162 = (const void *)__1actual->__O2__4expr.e1
                                                             ->__O1__4expr.tp),
                                            (((&__0__V156)->__O1__2ea.p = __2__X162),
                                             (&__0__V156))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
            __1formal->f__9name_list->__O1__4expr.tp = __4t;
            __1formal->f__9name_list->__O1__4expr.tp->permanent__4node = 1;
            break;
        }

        case 2: {
            __1actual->__O2__4expr.e1 = typ__4exprFP5table(__1actual->__O2__4expr.e1, gtbl);

            {
                Ptype __4t;

                __4t = __1actual->__O2__4expr.e1->__O1__4expr.tp;
                if ((__4t->base__4node == 110) &&
                    (__1formal->f__9name_list->__O1__4expr.tp->base__4node == 125))
                    __4t = (struct type *)__ct__3ptrFUcP4type(
                        (struct ptr *)0, (unsigned char)125,
                        (((struct vec *)(((struct vec *)__4t))))->typ__5pvtyp);

                if (check__4typeFP4typeUcT2(__1formal->f__9name_list->__O1__4expr.tp, __4t,
                                            (unsigned char)0, (unsigned char)0)) {
                    if ((const_problem && (is_ptr_or_ref__4typeFv(__4t) == 0)) &&
                        (is_ptr_or_ref__4typeFv(__1formal->f__9name_list->__O1__4expr.tp) == 0))
                        ;
                    else if (!const_formal_hack__FP4name(__1formal->f__9name_list)) {
                        const void *__2__X163;

                        {
                            struct ea __0__V157;

                            struct ea __0__V158;

                            struct ea __0__V159;

                            error__FPCcRC2eaN32(
                                (const char *)"YA mismatch:X %t for formal %n, not %t",
                                (const struct ea *)((__2__X163 =
                                                         (const void *)__1formal->f__9name_list
                                                             ->__O1__4expr.tp),
                                                    (((&__0__V157)->__O1__2ea.p = __2__X163),
                                                     (&__0__V157))),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V158, (const void *)__1formal->f__9name_list),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V159,
                                    (const void *)__1actual->__O2__4expr.e1->__O1__4expr.tp),
                                (const struct ea *)ea0);
                            error__FiPCc((int)'i',
                                         (const char *)"cannot recover from previous errors");
                        }
                    }
                }

                {
                    Pname __4g;

                    __4g = look__5tableFPCcUc(gtbl, __1formal->f__9name_list->__O2__4expr.string,
                                              (unsigned char)0);
                    if (__4g)
                        __4g->n_key__4name = 159;

                    __1formal->f__9name_list->__O3__4expr.n_initializer = __1actual->__O2__4expr.e1;
                    simpl__4nameFv(__1formal->f__9name_list);
                    __1formal->f__9name_list =
                        dcl__4nameFP5tableUc(__1formal->f__9name_list, gtbl, (unsigned char)31);
                    __1formal->f__9name_list->n_key__4name = 159;
                    __1formal->f__9name_list->n_sto__4name = 31;
                    __1formal->f__9name_list->permanent__4node = 1;

                    non_template_arg_non_type__FP4name(__1formal->f__9name_list);
                    {
                        int __4sorry;

                        __4sorry = suitable_const_expr__FP4name(__1formal->f__9name_list);

                        switch (__4sorry) {
                            const void *__2__X164;

                            const void *__2__X165;

                        case 0: {
                            struct ea __0__V160;

                            error__FPCcRC2eaN32(
                                (const char *)"YA for formal: %sis not a suitable constant.",
                                (const struct ea *)((__2__X164 =
                                                         (const void *)__1formal->f__9name_list
                                                             ->__O2__4expr.string),
                                                    (((&__0__V160)->__O1__2ea.p = __2__X164),
                                                     (&__0__V160))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                            break;
                        case -1:
                            error__FiPCc((int)'s', (const char *)"actualZE ofT string literal");
                            error__FiPCc((int)'i',
                                         (const char *)"cannot recover from previous errors");
                            break;
                        case -2:
                            error__FiPCc((int)'s', (const char *)"cast of non-integer constant");
                            break;
                        case -3: {
                            struct ea __0__V161;

                            error__FPCcRC2eaN32(
                                (const char *)"YA for formal %s: address of static identifier",
                                (const struct ea *)((__2__X165 =
                                                         (const void *)__1formal->f__9name_list
                                                             ->__O2__4expr.string),
                                                    (((&__0__V161)->__O1__2ea.p = __2__X165),
                                                     (&__0__V161))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                            break;
                        }
                        }
                        }

                        if (__4g)
                            __4g->n_key__4name = 0;
                        break;
                    }
                }
            }
        }

        default:
            error__FiPCc((int)'i', (const char *)"badY formal");
        }
    }

    __0this->tname__10basic_inst->__O2__4expr.string =
        (const char *)instantiation_string__10basic_instFv((struct basic_inst *)__0this);

    for (__1formal = __0this->inst_formals__10basic_inst; __1formal;
         __1formal = __1formal->l__9name_list)
        if (__1formal->f__9name_list->n_template_arg_string__4name)
            error__FiPCc((int)'i', (const char *)"attempt to bind aYZ multiple times");
        else
            __1formal->f__9name_list->n_template_arg_string__4name =
                make_formal_name__FPCcT1(__1formal->f__9name_list->__O2__4expr.string,
                                         __0this->tname__10basic_inst->__O2__4expr.string);
}

struct Pslot { /* sizeof Pslot == 16 */
    Pname param__5Pslot;
    Ptype typ__5Pslot;
};

void bind_formals__10funct_instFv(register struct funct_inst *__0this) {
    int __1count;

    Plist __1formal;

    __1count =
        get_formals_count__14basic_templateFv((struct basic_template *)__0this->def__10funct_inst);

    __1formal = __0this->inst_formals__10basic_inst;
    for (; __1formal; __1formal = __1formal->l__9name_list) {
        Pbinding __2p;

        __2p = __0this->binding__10funct_inst;
        {
            {
                int __2i;

                __2i = 0;

                for (; __2i < __1count; ((++__2p), (++__2i))) {
                    if (strcmp(__1formal->f__9name_list->__O2__4expr.string,
                               __2p->param__5Pslot->__O2__4expr.string) == 0) {
                        Ptype __4t;

                        __4t = __2p->typ__5Pslot;
                        if (__4t->base__4node == 138)
                            __4t = (struct type *)int_type;

                        if (__4t->b_const__4type != 0) {
                            if ((__4t->base__4node == 125) || (__4t->base__4node == 158)) {
                                Pptr __6pt;

                                __6pt = __ct__3ptrFUcP4type((struct ptr *)0, __4t->base__4node,
                                                            (struct type *)0);
                                ((*__6pt)) = (*(((struct ptr *)(((struct ptr *)__4t)))));
                                __6pt->b_const__4type = 0;
                                __4t = (struct type *)__6pt;
                            } else {
                                Pbase __6bt;

                                __6bt = __ct__8basetypeFUcP4name(
                                    (struct basetype *)0, __4t->base__4node, (struct name *)0);
                                ((*__6bt)) = (*(((struct basetype *)(((struct basetype *)__4t)))));
                                __6bt->b_const__4type = 0;
                                __4t = (struct type *)__6bt;
                            }
                        }

                        __1formal->f__9name_list->__O1__4expr.tp = __4t;
                        __1formal->f__9name_list->__O1__4expr.tp->permanent__4node = 1;
                    }
                }
            }
        }
    }

    __0this->tname__10basic_inst->__O2__4expr.string =
        (const char *)instantiation_string__10basic_instFv((struct basic_inst *)__0this);

    for (__1formal = __0this->inst_formals__10basic_inst; __1formal;
         __1formal = __1formal->l__9name_list) {
        if (__1formal->f__9name_list->n_template_arg_string__4name)
            error__FiPCc((int)'i', (const char *)"attempt to bind aYP multiple times");
        else
            __1formal->f__9name_list->n_template_arg_string__4name =
                make_formal_name__FPCcT1(__1formal->f__9name_list->__O2__4expr.string,
                                         __0this->tname__10basic_inst->__O2__4expr.string);
    }
}

struct ktable { /* sizeof ktable == 40 */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    union __Q2_6ktable4__C1 __O1__6ktable;
    short k_size__6ktable;
    bit k_tiny__6ktable;
    TOK k_id__6ktable;

    Pktab k_next__6ktable;
    Pname k_name__6ktable;
};

extern Pktab table_free__6ktable;

extern Pname insert_type__FP4nameP6ktableUc(Pname, Pktab, TOK);

void explicit_inst__10templ_instFv(register struct templ_inst *__0this) {
    struct name_list __1dummy_formal;
    Plist __1last;

    __ct__9name_listFP4nameP9name_list(&__1dummy_formal, (struct name *)0, (struct name_list *)0);
    __1last = (&__1dummy_formal);

    {
        {
            Plist __1formal;

            __1formal = __0this->def__10templ_inst->formals__14basic_template;

            for (; __1formal; __1formal = __1formal->l__9name_list) {
                Pname __2copy_name;

                __2copy_name = __ct__4nameFPCc((struct name *)0, (const char *)"");
                ((*__2copy_name)) = (*__1formal->f__9name_list);
                __2copy_name->n_tbl_list__4name = 0;
                __1last = (__1last->l__9name_list = __ct__9name_listFP4nameP9name_list(
                               (struct name_list *)0, __2copy_name, (struct name_list *)0));
            }
            __0this->inst_formals__10basic_inst = __1dummy_formal.l__9name_list;

            bind_formals__10templ_instFv(__0this);
            {
                Pclass __1cl;

                __1cl = classtype__4typeFv(__0this->tname__10basic_inst->__O1__4expr.tp);
                __1cl->class_base__8classdef = 4;
                __1cl->templ_base__4type = 2;
                (((struct basetype *)((
                     (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                    ->b_name__8basetype->__O2__4expr.string =
                    __0this->tname__10basic_inst->__O2__4expr.string;

                {
                    Pktab __1tb;

                    __1tb = __1cl->k_tbl__8classdef->k_next__6ktable;
                    if (__1tb == 0)
                        __1tb = Gtbl;
                    else if (__1tb->k_id__6ktable == 185)
                        __1tb = __1tb->k_next__6ktable;
                    __0this->namep__10basic_inst = insert_type__FP4nameP6ktableUc(
                        __0this->tname__10basic_inst, __1tb, __1cl->csu__8classdef);
                    __0this->namep__10basic_inst->__O1__4expr.tp =
                        __0this->tname__10basic_inst->__O1__4expr.tp;
                    modify_inst_names__8classdefFPCc(
                        __1cl, __0this->tname__10basic_inst->__O2__4expr.string);
                    __1cl->k_tbl__8classdef->k_name__6ktable = __0this->tname__10basic_inst;

                    if (__1cl->k_tbl__8classdef->k_name__6ktable->n_ktable__4name == 0)
                        __1cl->k_tbl__8classdef->k_name__6ktable->n_ktable__4name =
                            __0this->namep__10basic_inst->n_ktable__4name;
                }
            }
        }
    }
}

void expose_parameter_names__10basic_instFv(register struct basic_inst *__0this) {
    if (__0this->hidden_globals__10basic_inst)
        error__FiPCc((int)'i', (const char *)"an expose without a hide of global names");

    {
        {
            Plist __1formal;

            __1formal = __0this->inst_formals__10basic_inst;

            for (; __1formal; __1formal = __1formal->l__9name_list)
                if (__1formal->f__9name_list->n_template_arg__4name == 2) {
                    Pname __2gname;

                    __2gname = look__5tableFPCcUc(
                        gtbl, __1formal->f__9name_list->__O2__4expr.string, (unsigned char)0);
                    if (__2gname) {
                        __2gname->n_key__4name = 159;

                        __0this->hidden_globals__10basic_inst = __ct__9name_listFP4nameP9name_list(
                            (struct name_list *)0, __2gname, __0this->hidden_globals__10basic_inst);
                    }
                    __1formal->f__9name_list->n_key__4name = 0;
                    if (__1formal->f__9name_list !=
                        look__5tableFPCcUc(gtbl, __1formal->f__9name_list->__O2__4expr.string,
                                           (unsigned char)0))
                        error__FiPCc(
                            (int)'i',
                            (const char *)"parameter could not be located in the global table");
                }
        }
    }
}

void hide_parameter_names__10basic_instFv(register struct basic_inst *__0this) {
    {
        {
            Plist __1formal;

            __1formal = __0this->inst_formals__10basic_inst;

            for (; __1formal; __1formal = __1formal->l__9name_list)
                if (__1formal->f__9name_list->n_template_arg__4name == 2) {
                    __1formal->f__9name_list->n_key__4name = 159;
                }
            for (; __0this->hidden_globals__10basic_inst;
                 __0this->hidden_globals__10basic_inst =
                     __0this->hidden_globals__10basic_inst->l__9name_list)
                __0this->hidden_globals__10basic_inst->f__9name_list->n_key__4name = 0;
            __0this->hidden_globals__10basic_inst = 0;
        }
    }
}

void save_state__10basic_instFP4name(register struct basic_inst *__0this, Pname __1p) {
    if (__0this->next_active__10basic_inst)
        error__FiPCc((int)'i', (const char *)"circular instantiation of a template");
    save__5stateFv(&__0this->context__10basic_inst);
    if (head__10basic_inst)
        hide_parameter_names__10basic_instFv(head__10basic_inst);
    __0this->next_active__10basic_inst = head__10basic_inst;
    head__10basic_inst = __0this;
    init__5stateFv(&__0this->context__10basic_inst);
    Cdcl = __1p;

    Cstmt = 0;
    curr_file = (Cdcl ? (((int)Cdcl->where__4name.file__3loc)) : 0);
    expose_parameter_names__10basic_instFv(__0this);
}

void restore_state__10basic_instFv(register struct basic_inst *__0this) {
    restore__5stateFv(&__0this->context__10basic_inst);
    hide_parameter_names__10basic_instFv(__0this);
    head__10basic_inst = __0this->next_active__10basic_inst;

    __0this->next_active__10basic_inst = 0;
    if (head__10basic_inst)
        expose_parameter_names__10basic_instFv(head__10basic_inst);
}

static struct ea *__ct__2eaFUl(struct ea *__0this, size_t __2ii);

void kludge_copy__10templ_instFP8basetype(register struct templ_inst *__0this, Pbase __1pbc) {
    Pbase __1pb;
    Pname __1save_b_name;
    Ptype __1save_tp;

    unsigned long __2__X168;

    __1pb =
        (((struct basetype *)(((struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))));
    __1save_b_name = __1pb->b_name__8basetype;
    __1save_tp = __1pb->b_name__8basetype->__O1__4expr.tp;

    if ((__1pb->base__4node != 119) || (__1pbc->base__4node != 119)) {
        struct ea __0__V166;

        struct ea __0__V167;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"templ_inst::kludge_copy:(pb %k,pbc %k) cobjX",
            (const struct ea *)((__2__X168 = __1pb->base__4node),
                                (((((&__0__V166)->__O1__2ea.i = __2__X168), 0)), (&__0__V166))),
            (const struct ea *)__ct__2eaFUl(&__0__V167, (unsigned long)__1pbc->base__4node),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    ((*__1pb)) = (*__1pbc);
    __1pb->b_name__8basetype = __1save_b_name;
    ((*__1pb->b_name__8basetype)) = (*__1pbc->b_name__8basetype);
    __1pb->b_name__8basetype->__O1__4expr.tp = __1save_tp;
    ((*(((struct classdef *)(((struct classdef *)__1pb->b_name__8basetype->__O1__4expr.tp)))))) =
        (*(((struct classdef *)(((struct classdef *)__1pbc->b_name__8basetype->__O1__4expr.tp)))));
    (((struct classdef *)(((struct classdef *)__1pb->b_name__8basetype->__O1__4expr.tp))))
        ->class_base__8classdef = 4;
}

static Pbase cobj_node;
static Pname cname_node;
static Pclass class_node;
static Pfct fct_node;

static void syntax_tree_copy_hook__FPvRP4node10node_classR16tree_node_actionRi(
    void *__1__A169, Pnode *__1__A170, int __1__A171, int *__1action, int *__1never_see_again) {
    ((*__1never_see_again)) = 1;
    ((*__1action)) = 0;
    return;
}

static Pnode copy_syntax_tree__FP4nodei(Pnode __1n, int __1no_types) {
    struct pointer_hash __1cht;
    struct tree_copy_info __1info;

    unsigned long __2__X172;

    ((__2__X172 = 1000),
     ((((__ct__4HashFi(((struct Hash *)(&__1cht)), (int)__2__X172)),
        (((&__1cht)->key_hash_function__4Hash = (pointer_hash_fcn__FUl)),
         ((&__1cht)->key_key_equality_function__4Hash = (pointer_hasheq__FUlT1))))),
      (&__1cht)));
    (((((&__1info)->hook_info__14tree_copy_info = 0),
       (((&__1info)->node_hook__14tree_copy_info = 0),
        ((&__1info)->malloc_hook__14tree_copy_info = 0)))),
     (&__1info));
    if (__1no_types)
        __1info.node_hook__14tree_copy_info =
            (syntax_tree_copy_hook__FPvRP4node10node_classR16tree_node_actionRi);
    copy_tree__FRP4nodeR14tree_copy_infoP4Hash(
        (Pnode *)(&__1n), (struct tree_copy_info *)(&__1info), (struct Hash *)(&__1cht));
    {
        ((((void)((
            (void)((((((struct Hash *)(&__1cht)))
                         ? (((void)(__dl__FPv((void *)(((struct Hash *)(&__1cht)))->tab__4Hash),
                                    ((((struct Hash *)(&__1cht))) ? (((void)(((void)0))))
                                                                  : (((void)0))))))
                         : (((void)0)))),
                   (((void)0))))))));

        return __1n;
    }
}

int copy_hook__10templ_instFRP4node(register struct templ_inst *__0this, Pnode *__1node) {
    switch (((*__1node))->base__4node) {
    case 119:
        if (((*__1node)) == (((struct node *)cobj_node)))
            return (int)0;
        if (((*__1node)) ==
            (((struct node *)__0this->def__10templ_inst->namep__5templ->__O1__4expr.tp))) {
            ((*cobj_node)) = (*(((struct basetype *)(((struct basetype *)((*__1node)))))));
            ((*__1node)) = (struct node *)cobj_node;
        }
        break;

    case 85:
        if (((*__1node)) == (((struct node *)cname_node)))
            return (int)0;
        if (((*__1node)) == (((struct node *)sta_name)))
            return (int)0;

        if (((*__1node)) ==
            (((struct node *)(((struct basetype *)(((struct basetype *)__0this->def__10templ_inst
                                                        ->namep__5templ->__O1__4expr.tp))))
                  ->b_name__8basetype))) {
            ((*cname_node)) = (*(((struct name *)(((struct name *)((*__1node)))))));

            ((*__1node)) = (struct node *)cname_node;
        }
        break;

    case 6:
        if (((*__1node)) == (((struct node *)class_node)))
            return (int)0;
        if (((*__1node)) ==
            (((struct node *)(((struct basetype *)(((struct basetype *)__0this->def__10templ_inst
                                                        ->namep__5templ->__O1__4expr.tp))))
                  ->b_name__8basetype->__O1__4expr.tp))) {
            if (class_node == 0)
                return (int)0;
            ((*class_node)) = (*(((struct classdef *)(((struct classdef *)((*__1node)))))));
            ((*__1node)) = (struct node *)class_node;
        }
        break;
    }
    return (int)1;
}

static void copy_hook__FPvRP4node10node_classR16tree_node_actionRi(void *__1p, Pnode *__1node,
                                                                   int __1__A173, int *__1action,
                                                                   int *__1never_see_again) {
    ((*__1action)) = (copy_hook__10templ_instFRP4node(
                          ((struct templ_inst *)(((struct templ_inst *)__1p))), __1node)
                          ? 0
                          : 1);
    ((*__1never_see_again)) = (((*__1action)) != 1);
    return;
}

int f_copy_hook__10funct_instFRP4node(struct funct_inst *__0this, Pnode *);

static void f_copy_hook__FPvRP4node10node_classR16tree_node_actionRi(void *__1p, Pnode *__1node,
                                                                     int __1__A174, int *__1action,
                                                                     int *__1never_see_again) {
    ((*__1action)) = (f_copy_hook__10funct_instFRP4node(
                          ((struct funct_inst *)(((struct funct_inst *)__1p))), __1node)
                          ? 0
                          : 1);
    ((*__1never_see_again)) = (((*__1action)) != 1);
    return;
}

int f_copy_hook__10funct_instFRP4node(register struct funct_inst *__0this, Pnode *__1node) {
    switch (((*__1node))->base__4node) {
    case 85:
        if (((*__1node)) == (((struct node *)sta_name)))
            return (int)0;
        break;
    case 108:
        if (((*__1node)) == (((struct node *)fct_node)))
            return (int)0;
        if (((*__1node)) == (((struct node *)__0this->def__10funct_inst->fn__17function_template
                                  ->__O1__4expr.tp))) {
            ((*fct_node)) = (*(((struct fct *)(((struct fct *)((*__1node)))))));
            ((*__1node)) = (struct node *)fct_node;
        }
        break;
    }
    return (int)1;
}

void establish_class_subtree_correspondence__FR12pointer_hashP4nameT2(struct pointer_hash *__1h,
                                                                      Pname __1key_tname,
                                                                      Pname __1value_tname) {
    ((*__vc__4HashFi((struct Hash *)__1h, (int)(((unsigned long)__1key_tname))))) =
        (((unsigned long)__1value_tname));
    ((*__vc__4HashFi((struct Hash *)__1h, (int)(((unsigned long)__1key_tname->__O1__4expr.tp))))) =
        (((unsigned long)__1value_tname->__O1__4expr.tp));

    ((*__vc__4HashFi((struct Hash *)__1h,
                     (int)(((unsigned long)(((struct basetype *)((
                                                (struct basetype *)__1key_tname->__O1__4expr.tp))))
                                ->b_name__8basetype))))) =
        (((unsigned long)(((struct basetype *)((
                              (struct basetype *)__1value_tname->__O1__4expr.tp))))
              ->b_name__8basetype));

    ((*__vc__4HashFi((struct Hash *)__1h,
                     (int)(((unsigned long)(((struct basetype *)((
                                                (struct basetype *)__1key_tname->__O1__4expr.tp))))
                                ->b_name__8basetype->__O1__4expr.tp))))) =
        (((unsigned long)(((struct basetype *)((
                              (struct basetype *)__1value_tname->__O1__4expr.tp))))
              ->b_name__8basetype->__O1__4expr.tp));
}

Pcons make_ref_copy__FR12pointer_hashR14tree_copy_infoP4cons(struct pointer_hash *__1h,
                                                             struct tree_copy_info *__1info,
                                                             Pcons __1old_templ_refs) {
    struct cons __1dummy;

    struct cons *__1last;

    struct cons *__0__X178;

    struct cons *__2__X179;

    ((__0__X178 = (&__1dummy)),
     ((__2__X179 = 0),
      (((__0__X178 || (__0__X178 = (struct cons *)__nw__FUl((unsigned long)(sizeof(struct cons)))))
            ? ((__0__X178->car__4cons = ((void *)0)), (__0__X178->cdr__4cons = __2__X179))
            : 0),
       __0__X178)));

    __1last = (&__1dummy);
    {
        {
            Pcons __1pc;

            __1pc = __1old_templ_refs;

            for (; __1pc; __1pc = __1pc->cdr__4cons) {
                Ptempl_inst __2t;
                Pexpr __2dummy;
                struct elist __2list;

                __2t = (((struct templ_inst *)(((struct templ_inst *)__1pc->car__4cons))));
                __2dummy = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                  (struct expr *)0, (struct expr *)0);
                (((((&__2list)->head__5elist = ((&__2list)->tail__5elist = __2dummy)), 0)),
                 (&__2list));

                {
                    {
                        Pexpr __2actual;

                        __2actual = __2t->actuals__10basic_inst;

                        for (; __2actual; __2actual = __2actual->__O3__4expr.e2) {
                            Pnode __3root;

                            struct expr *__2__X175;

                            __3root = (struct node *)__2actual->__O2__4expr.e1;
                            copy_tree__FRP4nodeR14tree_copy_infoP4Hash((Pnode *)(&__3root), __1info,
                                                                       (struct Hash *)(__1h));

                            __3root = (struct node *)typ__4exprFP5table(
                                ((struct expr *)(((struct expr *)__3root))), gtbl);
                            ((__2__X175 = __ct__4exprFUcP4exprT2(
                                  (struct expr *)0, (unsigned char)140,
                                  ((struct expr *)(((struct expr *)__3root))), (struct expr *)0)),
                             ((((&__2list)->tail__5elist->__O3__4expr.e2 = __2__X175),
                               ((&__2list)->tail__5elist = __2__X175)),
                              (((void)0))));
                        }
                        {
                            Pexpr __2new_actuals;

                            Ptempl_inst __2treal;
                            Pname __2new_tname;

                            struct cons *__0__X176;

                            struct cons *__2__X177;

                            __2new_actuals = __2list.head__5elist->__O3__4expr.e2;

                            __2treal = get_inst__5templFP4exprP10templ_inst(__2t->def__10templ_inst,
                                                                            __2new_actuals, __2t);
                            __2new_tname = __2treal->tname__10basic_inst;

                            __1last = (__1last->cdr__4cons =
                                           ((__0__X176 = 0),
                                            ((__2__X177 = 0),
                                             (((__0__X176 || (__0__X176 = (struct cons *)__nw__FUl(
                                                                  (size_t)(sizeof(struct cons)))))
                                                   ? ((__0__X176->car__4cons = ((void *)__2treal)),
                                                      (__0__X176->cdr__4cons = __2__X177))
                                                   : 0),
                                              __0__X176))));

                            establish_class_subtree_correspondence__FR12pointer_hashP4nameT2(
                                __1h, __2t->tname__10basic_inst, __2new_tname);
                        }
                    }
                }
            }

            return __1dummy.cdr__4cons;
        }
    }
}

Pcons ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons(struct basic_inst *__0this,
                                                                    struct pointer_hash *__1h,
                                                                    struct tree_copy_info *__1info,
                                                                    Pcons __1old_templ_refs) {
    expose_parameter_names__10basic_instFv(__0this);
    {
        Pcons __1new_refs;

        __1new_refs = make_ref_copy__FR12pointer_hashR14tree_copy_infoP4cons(__1h, __1info,
                                                                             __1old_templ_refs);
        hide_parameter_names__10basic_instFv(__0this);
        return __1new_refs;
    }
}

int del__4HashFi(struct Hash *__0this, int __1key);

Ptempl_inst class_copy__10templ_instFRP4cons4bool(register struct templ_inst *__0this,
                                                  Pcons *__1templ_refs, int __1recopy) {
    register struct pointer_hash *__0__X181;

    unsigned long __2__X182;

    if (__1recopy) {
        del__4HashFi(
            (struct Hash *)__0this->corr__10basic_inst,
            (int)((
                (unsigned long)(((struct basetype *)(((struct basetype *)__0this->def__10templ_inst
                                                          ->namep__5templ->__O1__4expr.tp))))
                    ->b_name__8basetype->__O1__4expr.tp)));
        del__4HashFi(
            (struct Hash *)__0this->corr__10basic_inst,
            (int)((
                (unsigned long)(((struct basetype *)(((struct basetype *)__0this->def__10templ_inst
                                                          ->namep__5templ->__O1__4expr.tp))))
                    ->b_name__8basetype)));
        del__4HashFi(
            (struct Hash *)__0this->corr__10basic_inst,
            (int)(((unsigned long)__0this->def__10templ_inst->namep__5templ->__O1__4expr.tp)));

        del__4HashFi((struct Hash *)__0this->corr__10basic_inst,
                     (int)(((unsigned long)__0this->tname__10basic_inst->__O1__4expr.tp)));
        del__4HashFi((struct Hash *)__0this->corr__10basic_inst,
                     (int)(((unsigned long)(((struct basetype *)((
                                                (struct basetype *)
                                                    __0this->tname__10basic_inst->__O1__4expr.tp))))
                                ->b_name__8basetype)));

        del__4HashFi((struct Hash *)__0this->corr__10basic_inst,
                     (int)(((unsigned long)(((struct basetype *)((
                                                (struct basetype *)
                                                    __0this->tname__10basic_inst->__O1__4expr.tp))))
                                ->b_name__8basetype->__O1__4expr.tp)));
    } else
        __0this->corr__10basic_inst =
            ((__0__X181 = 0),
             ((__2__X182 = 1000),
              (((__0__X181 || (__0__X181 = (struct pointer_hash *)__nw__FUl(
                                   (size_t)(sizeof(struct pointer_hash)))))
                    ? ((__0__X181 = (struct pointer_hash *)__ct__4HashFi(((struct Hash *)__0__X181),
                                                                         (int)__2__X182)),
                       ((__0__X181->key_hash_function__4Hash = (pointer_hash_fcn__FUl)),
                        (__0__X181->key_key_equality_function__4Hash = (pointer_hasheq__FUlT1))))
                    : 0),
               __0__X181)));

    {
        struct name_list __2dummy_formal;
        Plist __2last;

        __ct__9name_listFP4nameP9name_list(&__2dummy_formal, (struct name *)0,
                                           (struct name_list *)0);
        __2last = (&__2dummy_formal);

        {
            {
                Plist __2formal;

                __2formal = __0this->def__10templ_inst->formals__14basic_template;

                for (; __2formal; __2formal = __2formal->l__9name_list) {
                    Pname __3copy_name;

                    __3copy_name = __ct__4nameFPCc((struct name *)0, (const char *)"");
                    ((*__3copy_name)) = (*__2formal->f__9name_list);
                    __3copy_name->n_tbl_list__4name = 0;
                    __2last = (__2last->l__9name_list = __ct__9name_listFP4nameP9name_list(
                                   (struct name_list *)0, __3copy_name, (struct name_list *)0));
                    ((*__vc__4HashFi((struct Hash *)__0this->corr__10basic_inst,
                                     (int)(((unsigned long)__2formal->f__9name_list))))) =
                        (((unsigned long)__3copy_name));
                }
                __0this->inst_formals__10basic_inst = __2dummy_formal.l__9name_list;
            }
        }
    }

    bind_formals__10templ_instFv(__0this);
    if (!__1recopy) {
        Pname __2nnn;

        __2nnn = k_find_name__FPCcP6ktableUc(__0this->tname__10basic_inst->__O2__4expr.string, Gtbl,
                                             (unsigned char)159);
        if (__2nnn && (__2nnn->base__4node == 123)) {
            Ptempl_inst __3ti;

            const void *__2__X183;

            __3ti = get_match__5templFP4exprP10templ_inst4bool(
                __0this->def__10templ_inst, __0this->actuals__10basic_inst, __0this, 1);
            if (__3ti)
                return __3ti;

            {
                struct ea __0__V180;

                error__FiPCcRC2eaN33(
                    (int)'i',
                    (const char *)"generated template instantiation name %swas not unique",
                    (const struct ea *)((__2__X183 = (const void *)__0this->tname__10basic_inst
                                                         ->__O2__4expr.string),
                                        (((&__0__V180)->__O1__2ea.p = __2__X183), (&__0__V180))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }
    }

    {
        struct tree_copy_info __2info;

        (((((&__2info)->hook_info__14tree_copy_info = 0),
           (((&__2info)->node_hook__14tree_copy_info = 0),
            ((&__2info)->malloc_hook__14tree_copy_info = 0)))),
         (&__2info));
        __2info.node_hook__14tree_copy_info =
            (copy_hook__FPvRP4node10node_classR16tree_node_actionRi);
        __2info.hook_info__14tree_copy_info = (void *)__0this;

        ((*__vc__4HashFi((struct Hash *)__0this->corr__10basic_inst,
                         (int)(((unsigned long)__0this->def__10templ_inst->namep__5templ))))) =
            (((unsigned long)__0this->tname__10basic_inst));

        ((*__1templ_refs)) = ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons(
            (struct basic_inst *)__0this, (struct pointer_hash *)__0this->corr__10basic_inst,
            (struct tree_copy_info *)(&__2info), (*__1templ_refs));
        {
            Pnode __2root;

            __2root = (struct node *)__0this->def__10templ_inst->basep__5templ;

            cobj_node = (((struct basetype *)((
                (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))));
            cname_node = (((struct basetype *)((
                              (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                             ->b_name__8basetype;
            class_node = (((struct classdef *)((
                (struct classdef *)(((struct basetype *)((
                                        (struct basetype *)
                                            __0this->tname__10basic_inst->__O1__4expr.tp))))
                    ->b_name__8basetype->__O1__4expr.tp))));

            copy_tree__FRP4nodeR14tree_copy_infoP4Hash((Pnode *)(&__2root),
                                                       (struct tree_copy_info *)(&__2info),
                                                       (struct Hash *)__0this->corr__10basic_inst);
        }
    }

    cname_node->__O2__4expr.string = __0this->tname__10basic_inst->__O2__4expr.string;
    if (!__1recopy) {
        Pktab __2tb;

        __2tb = class_node->k_tbl__8classdef->k_next__6ktable;
        if (__2tb == 0)
            __2tb = Gtbl;
        else if (__2tb->k_id__6ktable == 185)
            __2tb = __2tb->k_next__6ktable;
        __0this->namep__10basic_inst = insert_type__FP4nameP6ktableUc(
            __0this->tname__10basic_inst, __2tb, class_node->csu__8classdef);
        if (reinstat)
            class_node->k_tbl__8classdef->k_name__6ktable = __0this->tname__10basic_inst;
    } else
        class_node->defined__4type &= -4;
    __0this->namep__10basic_inst->__O1__4expr.tp = (struct type *)cobj_node;

    modify_inst_names__8classdefFPCc(class_node, cname_node->__O2__4expr.string);

    if (class_node->k_tbl__8classdef->k_name__6ktable->n_ktable__4name == 0) {
        class_node->k_tbl__8classdef->k_name__6ktable->n_ktable__4name =
            __0this->namep__10basic_inst->n_ktable__4name;
    }

    return (struct templ_inst *)0;
}

Pname get_parameter__10templ_instFPCc(struct templ_inst *__0this, const char *__1s);

static void function_copy_hook__FPvRP4node10node_classR16tree_node_actionRi(
    void *__1current_templ_inst, Pnode *__1node, int __1__A184, int *__1action,
    int *__1never_see_again) {
    ((*__1never_see_again)) = 1;

    switch (((*__1node))->base__4node) {
    case 85: {
        if (((*__1node)) == (((struct node *)sta_name))) {
            ((*__1action)) = 1;
            return;
        }
        {
            const char *__3s;
            Pname __3f;

            __3s = (((struct name *)(((struct name *)((*__1node))))))->__O2__4expr.string;
            __3f = 0;
            if ((__3s && (((*__3s)) == '$')) &&
                (__3f = get_parameter__10templ_instFPCc(
                     ((struct templ_inst *)(((struct templ_inst *)__1current_templ_inst))),
                     __3s + 1))) {
                if ((((struct name *)(((struct name *)((*__1node))))))->__O1__4name.n_list)
                    error__FiPCc((int)'i', (const char *)"n_list set in tree template formal.");
                ((*__1node)) = copy_syntax_tree__FP4nodei(
                    (struct node *)(((struct name *)(((struct name *)__3f))))
                        ->__O3__4expr.n_initializer,
                    0);
                ((*__1action)) = 1;
                ((*__1never_see_again)) = 0;
            } else
                ((*__1action)) = 0;
            return;
        }
    }
    default:
        ((*__1action)) = 0;
        return;
    }
}

Pname function_copy__10templ_instFP17function_templateRP4cons(register struct templ_inst *__0this,
                                                              Pfunt __1fnt, Pcons *__1templ_refs) {
    struct pointer_hash __1fcorr;

    struct name *__0_result;

    struct pointer_hash *__2__X185;

    ((__2__X185 = __0this->corr__10basic_inst),
     ((__ct__4HashFR4Hash(((struct Hash *)(&__1fcorr)), (struct Hash *)__2__X185)), (&__1fcorr)));

    {
        struct tree_copy_info __2info;
        Pnode __2root;

        (((((&__2info)->hook_info__14tree_copy_info = 0),
           (((&__2info)->node_hook__14tree_copy_info = 0),
            ((&__2info)->malloc_hook__14tree_copy_info = 0)))),
         (&__2info));
        __2root = (struct node *)__1fnt->fn__17function_template;

        {
            {
                Plist __2fformal;

                Plist __2cformal;

                __2fformal = __1fnt->formals__14basic_template;

                __2cformal = __0this->inst_formals__10basic_inst;

                for (; __2fformal; ((__2fformal = __2fformal->l__9name_list),
                                    (__2cformal = __2cformal->l__9name_list))) {
                    ((*__vc__4HashFi((struct Hash *)(&__1fcorr),
                                     (int)(((unsigned long)__2fformal->f__9name_list))))) =
                        (((unsigned long)__2cformal->f__9name_list));
                    if (((*__vc__4HashFi((struct Hash *)(&__1fcorr),
                                         (int)(((unsigned long)__2fformal->f__9name_list))))) !=
                        (((unsigned long)__2cformal->f__9name_list)))
                        error__FiPCc((int)'i',
                                     (const char *)"templ_inst::fuction_copy: hash table bug");
                }

                __2info.node_hook__14tree_copy_info =
                    (function_copy_hook__FPvRP4node10node_classR16tree_node_actionRi);
                __2info.hook_info__14tree_copy_info = (void *)__0this;

                ((*__1templ_refs)) = ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons(
                    (struct basic_inst *)__0this, (struct pointer_hash *)(&__1fcorr),
                    (struct tree_copy_info *)(&__2info), (*__1templ_refs));
                if (((*__vc__4HashFi(
                        (struct Hash *)(&__1fcorr),
                        (int)(((unsigned long)__0this->def__10templ_inst->namep__5templ))))) !=
                    (((unsigned long)__0this->tname__10basic_inst)))
                    error__FiPCc((int)'i',
                                 (const char *)"Y to instantiationTN correspondence is missing");

                copy_tree__FRP4nodeR14tree_copy_infoP4Hash((Pnode *)(&__2root),
                                                           (struct tree_copy_info *)(&__2info),
                                                           (struct Hash *)(&__1fcorr));
                {
                    {
                        __0_result = (((struct name *)(((struct name *)__2root))));

                        ((((void)((
                            (void)((((((struct Hash *)(&__1fcorr)))
                                         ? (((void)(__dl__FPv((void *)(((struct Hash *)(&__1fcorr)))
                                                                  ->tab__4Hash),
                                                    ((((struct Hash *)(&__1fcorr)))
                                                         ? (((void)(((void)0))))
                                                         : (((void)0))))))
                                         : (((void)0)))),
                                   (((void)0))))))));
                    }
                    return __0_result;
                }
            }
        }
    }
}

Pclass current_instantiation = 0;

void instantiate_match__10templ_instFP10templ_inst(register struct templ_inst *__0this,
                                                   Ptempl_inst __1match) {
    Pbase __1pb;

    __1pb =
        (((struct basetype *)(((struct basetype *)__1match->tname__10basic_inst->__O1__4expr.tp))));
    kludge_copy__10templ_instFP8basetype(__0this, __1pb);
    __0this->forward__10templ_inst = __1match;
}

void print_nested_typedef__FP4nameP8classdef(Pname __1n, Pclass __1cl) {
    {
        {
            Pname __1nn;

            __1nn = __1cl->mem_list__8classdef;

            for (; __1nn; __1nn = __1nn->__O1__4name.n_list) {
                if (__1nn->base__4node != 123)
                    continue;
                if (strcmp(__1nn->__O2__4expr.string, __1n->__O2__4expr.string) == 0) {
                    if (__1nn->n_dcl_printed__4name == 0) {
                        dcl_print__4nameFUc(__1nn, (unsigned char)0);
                        __1nn->n_dcl_printed__4name = 2;
                    }
                    break;
                }
            }
        }
    }
}

void print_all_vtbls__8classdefFP8classdef(struct classdef *__0this, Pclass);

Ptempl_inst instantiate__10templ_instF4bool(register struct templ_inst *__0this,
                                            int __1reinstantiate) {
    if (((dtpt_opt && (curloc.file__3loc == first_file)) && (notinstflag == 0)) &&
        ((__0this->tname__10basic_inst == righttname) ||
         ((__0this->tname__10basic_inst && righttname) &&
          (!strcmp(__0this->tname__10basic_inst->__O2__4expr.string,
                   righttname->__O2__4expr.string))))) {
        dummyinst = __0this;
    }

    {
        Pcons __1templ_refs;
        int __1ct;

        __1templ_refs = __0this->def__10templ_inst->templ_refs__14basic_template;
        __1ct = (((struct templ_classdef *)((
                     (struct templ_classdef
                          *)(((struct basetype *)((
                                 (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                         ->b_name__8basetype->__O1__4expr.tp))))
                    ->class_base__8classdef;
        if (!__1reinstantiate) {
            switch (__1ct) {
                const void *__2__X189;

            case 4:
                return __0this;
            case 5:
                break;
            case 0:
            case 2:
            case 1:
            case 3:
            default: {
                struct ea __0__V186;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"attempt to instantiate a non-YC %n",
                    (const struct ea *)((__2__X189 = (const void *)__0this->namep__10basic_inst),
                                        (((&__0__V186)->__O1__2ea.p = __2__X189), (&__0__V186))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            }
            __0this->status__10basic_inst = 3;

            forward_template_arg_types__FP9name_listP4expr(
                __0this->def__10templ_inst->formals__14basic_template,
                __0this->actuals__10basic_inst);
            {
                Ptempl_inst __2match;

                __2match = get_match__5templFP4exprP10templ_inst4bool(
                    __0this->def__10templ_inst, __0this->actuals__10basic_inst, __0this, 1);

                if (__2match || (__2match = class_copy__10templ_instFRP4cons4bool(
                                     __0this, (Pcons *)(&__1templ_refs), 0))) {
                    instantiate_match__10templ_instFP10templ_inst(__0this, __2match);
                    return __0this;
                }
            }
        } else
            class_copy__10templ_instFRP4cons4bool(__0this, (Pcons *)(&__1templ_refs), 1);

        {
            Pbase __1pb;

            __1pb = (((struct basetype *)((
                (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))));

            if (ansi_opt) {
                TOK __2csu;

                __2csu =
                    (((struct templ_classdef *)((
                         (struct templ_classdef *)(((struct basetype *)((
                                                       (struct basetype *)__0this
                                                           ->tname__10basic_inst->__O1__4expr.tp))))
                             ->b_name__8basetype->__O1__4expr.tp))))
                        ->csu__8classdef;
                fprintf(out_file, (const char *)"%s %s;\n",
                        ((__2csu == 36) || (__2csu == 167)) ? "union" : (((char *)"struct")),
                        __0this->tname__10basic_inst->__O2__4expr.string);
            }

            {
                save_state__10basic_instFP4name((struct basic_inst *)__0this,
                                                __0this->def__10templ_inst->namep__5templ);

                if ((__0this->def__10templ_inst->open_instantiations__14basic_template++) > 16) {
                    error__FPCc((const char *)"an infinite instantiation sequence was initiated");
                    __0this->def__10templ_inst->open_instantiations__14basic_template--;
                    return __0this;
                }

                (((struct classdef *)((
                     (struct classdef *)__1pb->b_name__8basetype->__O1__4expr.tp))))
                    ->class_base__8classdef = 4;

                if (__0this->def__10templ_inst->basep__5templ->b_name__8basetype->__O1__4expr.tp
                        ->defined__4type) {
                    __1pb->b_name__8basetype->where__4name =
                        __0this->def__10templ_inst->basep__5templ->b_name__8basetype->where__4name;

                    {
                        {
                            Plist __3formal;

                            __3formal = __0this->inst_formals__10basic_inst;

                            for (; __3formal; __3formal = __3formal->l__9name_list) {
                                if (__3formal->f__9name_list->__O1__4expr.tp->base__4node == 97) {
                                    Pclass __5cl;
                                    Pname __5n;

                                    __5n = (((struct basetype *)((
                                                (struct basetype *)
                                                    __3formal->f__9name_list->__O1__4expr.tp))))
                                               ->b_name__8basetype;
                                    if ((((__5n->base__4node == 123) && __5n->__O3__4expr.tpdef) &&
                                         (__5cl = __5n->__O3__4expr.tpdef->in_class__4type)) &&
                                        (__5cl->c_body__8classdef == 1))
                                        print_nested_typedef__FP4nameP8classdef(__5n, __5cl);
                                }
                                if (__3formal->f__9name_list->n_template_arg__4name == 2) {
                                    dcl_print__4nameFUc(__3formal->f__9name_list, (unsigned char)0);
                                }
                            }

                            {
                                {
                                    Pcons __3pc;

                                    struct dcl_context *__0__X190;

                                    struct dcl_context *__0__X192;

                                    __3pc = __1templ_refs;

                                    for (; __3pc; __3pc = __3pc->cdr__4cons)
                                        instantiate__10templ_instF4bool(
                                            ((struct templ_inst *)((
                                                (struct templ_inst *)__3pc->car__4cons))),
                                            0);

                                    tempdcl = 1;
                                    ((((cc++),
                                       (((cc >= ccvec_end)
                                             ? error__FiPCc((int)'i',
                                                            (const char *)"ccvec buffer overflow")
                                             : 0),
                                        (((*cc)) = (*(cc - 1))))),
                                      (((void)0))));

                                    cc->cot__11dcl_context = 0;

                                    cc->not4__11dcl_context = 0;

                                    cc->tot__11dcl_context = 0;

                                    cc->c_this__11dcl_context = 0;
                                    curr_inst = __0this;
                                    if (!((dcl__4nameFP5tableUc(__1pb->b_name__8basetype, gtbl,
                                                                (unsigned char)14) == 0) ||
                                          error_count)) {
                                        simpl__4nameFv(__1pb->b_name__8basetype);
                                        {
                                            Ptype __4pt;

                                            unsigned long __2__X191;

                                            __4pt = __1pb->b_name__8basetype->__O1__4expr.tp;
                                            if (__4pt->base__4node != 6) {
                                                struct ea __0__V187;

                                                error__FiPCcRC2eaN33(
                                                    (int)'i',
                                                    (const char *)"templ_inst::instantiate(%k),CX",
                                                    (const struct ea
                                                         *)((__2__X191 = __4pt->base__4node),
                                                            (((((&__0__V187)->__O1__2ea.i =
                                                                    __2__X191),
                                                               0)),
                                                             (&__0__V187))),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                                            }
                                            {
                                                Pclass __4cl;

                                                __4cl = (((struct classdef *)((
                                                    (struct classdef *)__4pt))));
                                                current_instantiation = __4cl;
                                                dcl_print__4nameFUc(__1pb->b_name__8basetype,
                                                                    (unsigned char)0);
                                                if (__4cl->c_body__8classdef == 3)
                                                    print_all_vtbls__8classdefFP8classdef(__4cl,
                                                                                          __4cl);
                                                if (!(__4pt->defined__4type & 01)) {
                                                    struct ea __0__V188;

                                                    error__FiPCcRC2eaN33(
                                                        (int)'i',
                                                        (const char *)"templ_inst::instantiate: "
                                                                      "dclC%t is not yet defined",
                                                        (const struct ea
                                                             *)(((&__0__V188)->__O1__2ea.p =
                                                                     ((const void *)__4pt)),
                                                                (&__0__V188)),
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0);
                                                }
                                                current_instantiation = 0;
                                            }
                                        }
                                    }
                                    curr_inst = 0;
                                    (((cc--), (((void)0))));
                                    tempdcl = 0;
                                }
                            }
                        }
                    }
                }

                {
                    {
                        Ptempl_inst __2clone;

                        __2clone = __0this->def__10templ_inst->insts__5templ;

                        for (; __2clone; __2clone = __2clone->next__10templ_inst)
                            if (__2clone != __0this) {
                                if (__2clone->forward__10templ_inst == __0this)
                                    kludge_copy__10templ_instFP8basetype(
                                        __2clone, ((struct basetype *)((
                                                      (struct basetype *)__0this
                                                          ->tname__10basic_inst->__O1__4expr.tp))));
                                else {
                                }
                            }

                        restore_state__10basic_instFv((struct basic_inst *)__0this);
                        __0this->def__10templ_inst->open_instantiations__14basic_template--;
                    }
                }
            }
            return __0this;
        }
    }
}

struct templ_state *__ct__11templ_stateFv(register struct templ_state *__0this) {
    if (__0this ||
        (__0this = (struct templ_state *)__nw__FUl((size_t)(sizeof(struct templ_state))))) {

        __0this->param_end__11templ_state = param_end__17templ_compilation;
        __0this->params__11templ_state = params__17templ_compilation;
        __0this->templ_refs__11templ_state = templ_refs__17templ_compilation;
        __0this->friend_templ_refs__11templ_state = friend_templ_refs__17templ_compilation;
        __0this->last_cons__11templ_state = last_cons__17templ_compilation;
        __0this->owner__11templ_state = owner__17templ_compilation;
    }
    return __0this;
}

void __dt__11templ_stateFv(register struct templ_state *__0this, int __0__free) {
    if (__0this) {
        param_end__17templ_compilation = __0this->param_end__11templ_state;
        params__17templ_compilation = __0this->params__11templ_state;
        templ_refs__17templ_compilation = __0this->templ_refs__11templ_state;
        friend_templ_refs__17templ_compilation = __0this->friend_templ_refs__11templ_state;
        last_cons__17templ_compilation = __0this->last_cons__11templ_state;
        owner__17templ_compilation = __0this->owner__11templ_state;

        if (__0this)
            if (__0__free & 1)
                __dl__FPv((void *)__0this);
    }
}

struct templ *__ct__5templFP9name_listP4name(register struct templ *__0this, Plist __1parms,
                                             Pname __1p) {
    struct basic_template *__0__X196;

    if (__0this || (__0this = (struct templ *)__nw__FUl((size_t)(sizeof(struct templ))))) {
        ((__0this =
              (struct templ *)((__0__X196 = (((struct basic_template *)__0this))),
                               (((__0__X196 || (__0__X196 = (struct basic_template *)__nw__FUl(
                                                    (size_t)(sizeof(struct basic_template)))))
                                     ? (__0__X196->__vptr__14basic_template =
                                            (struct __mptr *)__ptbl_vec___[0])
                                     : 0),
                                __0__X196))),
         (__0this->__vptr__14basic_template = (struct __mptr *)__ptbl_vec___[1]));

        __0this->formals__14basic_template = __1parms;

        __0this->namep__5templ = __1p;
        __0this->basep__5templ =
            (((struct basetype *)(((struct basetype *)__0this->namep__5templ->__O1__4expr.tp))));

        if (__0this->basep__5templ->base__4node != 119) {
            struct ea __0__V193;

            struct ea __0__V194;

            struct ea __0__V195;

            error__FPCcRC2eaN32(
                (const char *)"YC%n --%n already declared asTdef (%t) ",
                (const struct ea *)(((&__0__V193)->__O1__2ea.p = ((const void *)__1p)),
                                    (&__0__V193)),
                (const struct ea *)(((&__0__V194)->__O1__2ea.p = ((const void *)__1p)),
                                    (&__0__V194)),
                (const struct ea *)__ct__2eaFPCv(&__0__V195, (const void *)__1p->__O1__4expr.tp),
                (const struct ea *)ea0);
        }
        {
            Ptype __1t;
            Pclass __1cl;

            __1t = __0this->basep__5templ->b_name__8basetype->__O1__4expr.tp;
            __1cl = (((struct classdef *)(((struct classdef *)__1t))));

            __1cl->class_base__8classdef = 2;
            __0this->defined__5templ = ((__1t->defined__4type & 04) ? 1 : 0);
            if (__0this->defined__5templ)
                __0this->members__5templ = __1cl->mem_list__8classdef;

            __0this->namep__5templ->permanent__4node = 1;

            __0this->namep__5templ->__O1__4expr.tp->permanent__4node = 1;

            __0this->next__5templ = list__17templ_compilation;

            list__17templ_compilation = __0this;
        }
    }
    return __0this;
}

struct templ_classdef *__ct__14templ_classdefFP10templ_inst(struct templ_classdef *__0this,
                                                            Ptempl_inst __1i);

struct templ_inst *__ct__10templ_instFP4exprP5templ(register struct templ_inst *__0this,
                                                    Pexpr __1act, Ptempl __1owner) {
    struct basic_inst *__0__X197;

    struct state *__0__X23;

    if (__0this ||
        (__0this = (struct templ_inst *)__nw__FUl((size_t)(sizeof(struct templ_inst))))) {
        ((__0this = (struct templ_inst
                         *)((__0__X197 = (((struct basic_inst *)__0this))),
                            (((__0__X197 || (__0__X197 = (struct basic_inst *)__nw__FUl(
                                                 (size_t)(sizeof(struct basic_inst)))))
                                  ? ((__0__X197->__vptr__10basic_inst =
                                          (struct __mptr *)__ptbl_vec___[2]),
                                     ((__0__X23 = (&__0__X197->context__10basic_inst)),
                                      (((__0__X23 || (__0__X23 = (struct state *)__nw__FUl(
                                                          (unsigned long)(sizeof(struct state)))))
                                            ? 0
                                            : 0),
                                       __0__X23)))
                                  : 0),
                             __0__X197))),
         (__0this->__vptr__10basic_inst = (struct __mptr *)__ptbl_vec___[3]));

        __0this->isa__10basic_inst = 6;
        __0this->def__10templ_inst = __1owner;
        __0this->tname__10basic_inst = __ct__4nameFPCc(
            (struct name *)0, __0this->def__10templ_inst->namep__5templ->__O2__4expr.string);
        __0this->tname__10basic_inst->base__4node = 123;
        __0this->tname__10basic_inst->__O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name(
            (struct basetype *)0, (unsigned char)119,
            __ct__4nameFPCc((struct name *)0,
                            __0this->def__10templ_inst->namep__5templ->__O2__4expr.string));
        {
            Pclass __1c;

            Pclass __1cl;

            register struct templ *__0__X198;

            __1c = (struct classdef *)__ct__14templ_classdefFP10templ_inst(
                (struct templ_classdef *)0, __0this);

            __1cl = classtype__4typeFv(__1owner->namep__5templ->__O1__4expr.tp);
            if (__1cl->k_tbl__8classdef)
                __1c->k_tbl__8classdef = __1cl->k_tbl__8classdef;

            (((struct basetype *)((
                 (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                ->b_name__8basetype->__O1__4expr.tp = (struct type *)__1c;
            __0this->tname__10basic_inst->permanent__4node = 1;

            __0this->tname__10basic_inst->__O1__4expr.tp->permanent__4node = 1;
            (((struct basetype *)((
                 (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                ->b_name__8basetype->permanent__4node = 1;
            (((struct basetype *)((
                 (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                ->b_name__8basetype->__O1__4expr.tp->permanent__4node = 1;

            __1c->mem_list__8classdef =
                ((__0__X198 = __0this->def__10templ_inst),
                 ((((struct classdef *)(((struct classdef *)__0__X198->basep__5templ
                                             ->b_name__8basetype->__O1__4expr.tp))))))
                    ->mem_list__8classdef;

            __0this->actuals__10basic_inst = __1act;
            __0this->next__10templ_inst = __1owner->insts__5templ;
            __1owner->insts__5templ = __0this;
        }
    }
    return __0this;
}

struct templ_classdef *__ct__14templ_classdefFP10templ_instUc(struct templ_classdef *__0this,
                                                              Ptempl_inst __1i, TOK __1csu);

struct ktable *__ct__6ktableFiP6ktableP4name(struct ktable *__0this, int, Pktab, Pname);

struct templ_inst *__ct__10templ_instFP4exprP5templUc(register struct templ_inst *__0this,
                                                      Pexpr __1act, Ptempl __1owner, TOK __1csu) {
    struct basic_inst *__0__X199;

    struct state *__0__X23;

    if (__0this ||
        (__0this = (struct templ_inst *)__nw__FUl((size_t)(sizeof(struct templ_inst))))) {
        ((__0this = (struct templ_inst
                         *)((__0__X199 = (((struct basic_inst *)__0this))),
                            (((__0__X199 || (__0__X199 = (struct basic_inst *)__nw__FUl(
                                                 (size_t)(sizeof(struct basic_inst)))))
                                  ? ((__0__X199->__vptr__10basic_inst =
                                          (struct __mptr *)__ptbl_vec___[2]),
                                     ((__0__X23 = (&__0__X199->context__10basic_inst)),
                                      (((__0__X23 || (__0__X23 = (struct state *)__nw__FUl(
                                                          (unsigned long)(sizeof(struct state)))))
                                            ? 0
                                            : 0),
                                       __0__X23)))
                                  : 0),
                             __0__X199))),
         (__0this->__vptr__10basic_inst = (struct __mptr *)__ptbl_vec___[3]));

        __0this->isa__10basic_inst = 6;
        __0this->def__10templ_inst = __1owner;
        __0this->tname__10basic_inst =
            __ct__4nameFPCc((struct name *)0, __1owner->namep__5templ->__O2__4expr.string);
        __0this->tname__10basic_inst->base__4node = 123;
        __0this->tname__10basic_inst->__O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name(
            (struct basetype *)0, (unsigned char)119,
            __ct__4nameFPCc((struct name *)0, __1owner->namep__5templ->__O2__4expr.string));
        {
            Pclass __1c;

            __1c = (struct classdef *)__ct__14templ_classdefFP10templ_instUc(
                (struct templ_classdef *)0, __0this, __1csu);

            __1c->k_tbl__8classdef = __ct__6ktableFiP6ktableP4name(
                (struct ktable *)0, 0, (struct ktable *)0, __0this->tname__10basic_inst);
            __1c->k_tbl__8classdef->k_id__6ktable = 6;

            (((struct basetype *)((
                 (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                ->b_name__8basetype->__O1__4expr.tp = (struct type *)__1c;
            __0this->tname__10basic_inst->permanent__4node = 1;

            __0this->tname__10basic_inst->__O1__4expr.tp->permanent__4node = 1;
            (((struct basetype *)((
                 (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                ->b_name__8basetype->permanent__4node = 1;
            (((struct basetype *)((
                 (struct basetype *)__0this->tname__10basic_inst->__O1__4expr.tp))))
                ->b_name__8basetype->__O1__4expr.tp->permanent__4node = 1;

            __0this->actuals__10basic_inst = __1act;
            __0this->next__10templ_inst = __1owner->insts__5templ;
            __1owner->insts__5templ = __0this;
        }
    }
    return __0this;
}

struct templ_fct *__ct__9templ_fctFP10funct_inst(struct templ_fct *__0this, Pfunct_inst __1i);

struct funct_inst *
__ct__10funct_instFP4exprP17function_template(register struct funct_inst *__0this, Pexpr __1act,
                                              Pfunt __1owner) {
    struct basic_inst *__0__X200;

    struct state *__0__X23;

    if (__0this ||
        (__0this = (struct funct_inst *)__nw__FUl((size_t)(sizeof(struct funct_inst))))) {
        ((__0this = (struct funct_inst
                         *)((__0__X200 = (((struct basic_inst *)__0this))),
                            (((__0__X200 || (__0__X200 = (struct basic_inst *)__nw__FUl(
                                                 (size_t)(sizeof(struct basic_inst)))))
                                  ? ((__0__X200->__vptr__10basic_inst =
                                          (struct __mptr *)__ptbl_vec___[2]),
                                     ((__0__X23 = (&__0__X200->context__10basic_inst)),
                                      (((__0__X23 || (__0__X23 = (struct state *)__nw__FUl(
                                                          (unsigned long)(sizeof(struct state)))))
                                            ? 0
                                            : 0),
                                       __0__X23)))
                                  : 0),
                             __0__X200))),
         (__0this->__vptr__10basic_inst = (struct __mptr *)__ptbl_vec___[4]));

        __0this->isa__10basic_inst = 108;
        __0this->def__10funct_inst = __1owner;
        __0this->tname__10basic_inst = __ct__4nameFPCc(
            (struct name *)0,
            __0this->def__10funct_inst->fn__17function_template->__O2__4expr.string);
        __0this->tname__10basic_inst->__O1__4expr.tp =
            (struct type *)__ct__9templ_fctFP10funct_inst((struct templ_fct *)0, __0this);
        __0this->actuals__10basic_inst = __1act;

        __0this->next__10funct_inst = __1owner->insts__17function_template;
        __1owner->insts__17function_template = __0this;
        __0this->tname__10basic_inst->permanent__4node = 1;

        __0this->tname__10basic_inst->__O1__4expr.tp->permanent__4node = 1;
    }
    return __0this;
}

struct classdef *__ct__8classdefFUc(struct classdef *__0this, TOK);

struct templ_classdef *__ct__14templ_classdefFP10templ_inst(register struct templ_classdef *__0this,
                                                            Ptempl_inst __1i) {
    if (__0this ||
        (__0this = (struct templ_classdef *)__nw__FUl((size_t)(sizeof(struct templ_classdef))))) {
        __0this = (struct templ_classdef *)__ct__8classdefFUc(((struct classdef *)__0this),
                                                              (unsigned char)6);
        __0this->inst__14templ_classdef = __1i;
        __0this->class_base__8classdef = 5;
        __0this->string__8classdef =
            (__0this->inst__14templ_classdef->def__10templ_inst->namep__5templ)->__O2__4expr.string;
    }
    return __0this;
}

struct templ_classdef *
__ct__14templ_classdefFP10templ_instUc(register struct templ_classdef *__0this, Ptempl_inst __1i,
                                       TOK __1csu) {
    if (__0this ||
        (__0this = (struct templ_classdef *)__nw__FUl((size_t)(sizeof(struct templ_classdef))))) {
        __0this = (struct templ_classdef *)__ct__8classdefFUc(((struct classdef *)__0this), __1csu);
        __0this->inst__14templ_classdef = __1i;
        __0this->class_base__8classdef = 4;
        __0this->templ_base__4type = 2;
    }
    return __0this;
}

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

struct templ_fct *__ct__9templ_fctFP10funct_inst(register struct templ_fct *__0this,
                                                 Pfunct_inst __1i) {
    if (__0this ||
        (__0this = (struct templ_fct *)__nw__9templ_fctSFUl((size_t)(sizeof(struct templ_fct))))) {
        __0this = (struct templ_fct *)__ct__3fctFP4typeP4nameUc(
            ((struct fct *)__0this), (struct type *)0, (struct name *)0, (unsigned char)0);

        __0this->inst__9templ_fct = __1i;
        __0this->fct_base__3fct = 5;
    }
    return __0this;
}

struct data_template *__ct__13data_templateFR5templP9name_listP4name(
    register struct data_template *__0this, struct templ *__1owner, Plist __1params, Pname __1n) {
    struct basic_template *__0__X201;

    if (__0this ||
        (__0this = (struct data_template *)__nw__FUl((size_t)(sizeof(struct data_template))))) {
        ((__0this = (struct data_template *)((__0__X201 = (((struct basic_template *)__0this))),
                                             (((__0__X201 ||
                                                (__0__X201 = (struct basic_template *)__nw__FUl(
                                                     (size_t)(sizeof(struct basic_template)))))
                                                   ? (__0__X201->__vptr__14basic_template =
                                                          (struct __mptr *)__ptbl_vec___[0])
                                                   : 0),
                                              __0__X201))),
         (__0this->__vptr__14basic_template = (struct __mptr *)__ptbl_vec___[5]));

        if (((*__1owner)).data_end__5templ)
            ((*__1owner)).data_end__5templ->next__13data_template = __0this;
        else
            ((*__1owner)).data__5templ = __0this;
        ((*__1owner)).data_end__5templ = __0this;
        __0this->formals__14basic_template = __1params;
        __0this->dat_mem__13data_template = __1n;
        __1n->permanent__4node = 1;

        __1n->__O1__4expr.tp->permanent__4node = 1;
    }
    return __0this;
}

struct function_template *
__ct__17function_templateFR5templP9name_listP4name(register struct function_template *__0this,
                                                   struct templ *__1owner, Plist __1params,
                                                   Pname __1n) {
    struct basic_template *__0__X202;

    if (__0this || (__0this = (struct function_template *)__nw__FUl(
                        (size_t)(sizeof(struct function_template))))) {
        ((__0this = (struct function_template *)((__0__X202 = (((struct basic_template *)__0this))),
                                                 (((__0__X202 ||
                                                    (__0__X202 = (struct basic_template *)__nw__FUl(
                                                         (size_t)(sizeof(struct basic_template)))))
                                                       ? (__0__X202->__vptr__14basic_template =
                                                              (struct __mptr *)__ptbl_vec___[0])
                                                       : 0),
                                                  __0__X202))),
         (__0this->__vptr__14basic_template = (struct __mptr *)__ptbl_vec___[6]));

        if (((*__1owner)).fns_end__5templ)
            ((*__1owner)).fns_end__5templ->next__17function_template = __0this;
        else
            ((*__1owner)).fns__5templ = __0this;
        ((*__1owner)).fns_end__5templ = __0this;
        __0this->formals__14basic_template = __1params;
        __0this->fn__17function_template = __1n;
        __1n->permanent__4node = 1;

        __1n->__O1__4expr.tp->permanent__4node = 1;
    }
    return __0this;
}

struct function_template *
__ct__17function_templateFP9name_listP4name(register struct function_template *__0this,
                                            Plist __1params, Pname __1n) {
    struct basic_template *__0__X203;

    if (__0this || (__0this = (struct function_template *)__nw__FUl(
                        (size_t)(sizeof(struct function_template))))) {
        ((__0this = (struct function_template *)((__0__X203 = (((struct basic_template *)__0this))),
                                                 (((__0__X203 ||
                                                    (__0__X203 = (struct basic_template *)__nw__FUl(
                                                         (size_t)(sizeof(struct basic_template)))))
                                                       ? (__0__X203->__vptr__14basic_template =
                                                              (struct __mptr *)__ptbl_vec___[0])
                                                       : 0),
                                                  __0__X203))),
         (__0this->__vptr__14basic_template = (struct __mptr *)__ptbl_vec___[6]));

        __0this->formals__14basic_template = __1params;
        __0this->fn__17function_template = __1n;
        (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))))->fct_base__3fct = 1;
        __0this->next__17function_template = f_list__17templ_compilation;

        f_list__17templ_compilation = __0this;
        __0this->templ_refs__14basic_template = 0;
        __1n->permanent__4node = 1;

        __1n->__O1__4expr.tp->permanent__4node = 1;
    }
    return __0this;
}

Pname get_parameter__10templ_instFPCc(register struct templ_inst *__0this, const char *__1s) {
    {
        {
            Plist __1formal;

            __1formal = __0this->inst_formals__10basic_inst;

            for (; __1formal; __1formal = __1formal->l__9name_list)
                if (strcmp(__1formal->f__9name_list->__O2__4expr.string, __1s) == 0)
                    return __1formal->f__9name_list;
            return (struct name *)0;
        }
    }
}

Pfunct_inst tfct_copy__10funct_instFRP4cons4bool(register struct funct_inst *__0this,
                                                 Pcons *__1templ_refs, int __1recopy) {
    register struct pointer_hash *__0__X205;

    unsigned long __2__X206;

    if (__1recopy) {
        del__4HashFi((struct Hash *)__0this->corr__10basic_inst,
                     (int)(((unsigned long)__0this->def__10funct_inst->fn__17function_template)));
        del__4HashFi((struct Hash *)__0this->corr__10basic_inst,
                     (int)(((unsigned long)__0this->tname__10basic_inst)));
    } else
        __0this->corr__10basic_inst =
            ((__0__X205 = 0),
             ((__2__X206 = 1000),
              (((__0__X205 || (__0__X205 = (struct pointer_hash *)__nw__FUl(
                                   (size_t)(sizeof(struct pointer_hash)))))
                    ? ((__0__X205 = (struct pointer_hash *)__ct__4HashFi(((struct Hash *)__0__X205),
                                                                         (int)__2__X206)),
                       ((__0__X205->key_hash_function__4Hash = (pointer_hash_fcn__FUl)),
                        (__0__X205->key_key_equality_function__4Hash = (pointer_hasheq__FUlT1))))
                    : 0),
               __0__X205)));

    {
        struct name_list __1dummy_formal;
        Plist __1last;

        __ct__9name_listFP4nameP9name_list(&__1dummy_formal, (struct name *)0,
                                           (struct name_list *)0);
        __1last = (&__1dummy_formal);

        {
            {
                Plist __1formal;

                __1formal = __0this->def__10funct_inst->formals__14basic_template;

                for (; __1formal; __1formal = __1formal->l__9name_list) {
                    Pname __2copy_name;

                    __2copy_name = __ct__4nameFPCc((struct name *)0, (const char *)"");
                    ((*__2copy_name)) = (*__1formal->f__9name_list);
                    __2copy_name->n_tbl_list__4name = 0;
                    __1last = (__1last->l__9name_list = __ct__9name_listFP4nameP9name_list(
                                   (struct name_list *)0, __2copy_name, (struct name_list *)0));
                    ((*__vc__4HashFi((struct Hash *)__0this->corr__10basic_inst,
                                     (int)(((unsigned long)__1formal->f__9name_list))))) =
                        (((unsigned long)__2copy_name));
                }
                __0this->inst_formals__10basic_inst = __1dummy_formal.l__9name_list;

                bind_formals__10funct_instFv(__0this);
                if ((!__1recopy) &&
                    look__5tableFPCcUc(gtbl, __0this->tname__10basic_inst->__O2__4expr.string,
                                       (unsigned char)0)) {
                    Pfunct_inst __2ti;

                    const void *__2__X207;

                    __2ti = get_match__17function_templateFP4exprP10funct_inst4bool(
                        __0this->def__10funct_inst, __0this->actuals__10basic_inst, __0this, 1);
                    if (__2ti)
                        return __2ti;
                    {
                        struct ea __0__V204;

                        error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"generatedY instanceN %s not unique",
                            (const struct ea *)((__2__X207 =
                                                     (const void *)__0this->tname__10basic_inst
                                                         ->__O2__4expr.string),
                                                (((&__0__V204)->__O1__2ea.p = __2__X207),
                                                 (&__0__V204))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }

                {
                    struct tree_copy_info __1info;

                    (((((&__1info)->hook_info__14tree_copy_info = 0),
                       (((&__1info)->node_hook__14tree_copy_info = 0),
                        ((&__1info)->malloc_hook__14tree_copy_info = 0)))),
                     (&__1info));
                    __1info.node_hook__14tree_copy_info =
                        (f_copy_hook__FPvRP4node10node_classR16tree_node_actionRi);
                    __1info.hook_info__14tree_copy_info = (void *)__0this;

                    {
                        Pnode __1root;

                        __1root =
                            (struct node *)
                                __0this->def__10funct_inst->fn__17function_template->__O1__4expr.tp;
                        fct_node = (((struct fct *)((
                            (struct fct *)__0this->tname__10basic_inst->__O1__4expr.tp))));

                        ((*__vc__4HashFi((struct Hash *)__0this->corr__10basic_inst,
                                         (int)(((unsigned long)__0this->def__10funct_inst
                                                    ->fn__17function_template))))) =
                            (((unsigned long)__0this->tname__10basic_inst));
                        ((*__1templ_refs)) =
                            ref_copy__10basic_instFR12pointer_hashR14tree_copy_infoP4cons(
                                (struct basic_inst *)__0this,
                                (struct pointer_hash *)__0this->corr__10basic_inst,
                                (struct tree_copy_info *)(&__1info), (*__1templ_refs));
                        copy_tree__FRP4nodeR14tree_copy_infoP4Hash(
                            (Pnode *)(&__1root), (struct tree_copy_info *)(&__1info),
                            (struct Hash *)__0this->corr__10basic_inst);
                        return (struct funct_inst *)0;
                    }
                }
            }
        }
    }
}

Pfct current_fct_instantiation = 0;
Pfunct_inst fct_instantiation = 0;

void instantiate__10funct_instF4bool(register struct funct_inst *__0this, int __1reinstantiate) {
    Pcons __1templ_refs;
    int __1ft;

    __1templ_refs = __0this->def__10funct_inst->templ_refs__14basic_template;
    __1ft =
        (((struct templ_fct *)(((struct templ_fct *)__0this->tname__10basic_inst->__O1__4expr.tp))))
            ->fct_base__3fct;
    if (!__1reinstantiate) {
        switch (__1ft) {
            const void *__2__X213;

        case 4:
            if (((dtpt_opt && (fdummyinst == 0)) && (curloc.file__3loc == first_file)) &&
                (tempdcl == 0)) {
                register struct name *__0__X212;

                unsigned long __2__X16;

                struct ea __0__X__V1400q2z144hdwckg;

                struct ea __0__X__V1500q2z144hdwckg;

                fdummyinst = __0this;
                fcurr_inst = __0this;
                current_fct_instantiation =
                    ((__0__X212 = __0this->tname__10basic_inst),
                     (((__0__X212->__O1__4expr.tp->base__4node == 108)
                           ? (((struct fct *)(((struct fct *)__0__X212->__O1__4expr.tp))))
                           : (error__FiPCcRC2eaN33(
                                  (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                  (const struct ea *)(((&__0__X__V1400q2z144hdwckg)->__O1__2ea.p =
                                                           ((const void *)__0__X212)),
                                                      (&__0__X__V1400q2z144hdwckg)),
                                  (const struct ea
                                       *)((__2__X16 = __0__X212->__O1__4expr.tp->base__4node),
                                          (((((&__0__X__V1500q2z144hdwckg)->__O1__2ea.i = __2__X16),
                                             0)),
                                           (&__0__X__V1500q2z144hdwckg))),
                                  (const struct ea *)ea0, (const struct ea *)ea0),
                              (((struct fct *)0))))));
                if (finst_body__4nameFv(__0this->tname__10basic_inst))
                    dcl_print__4nameFUc(__0this->tname__10basic_inst, (unsigned char)0);
                current_fct_instantiation = 0;
            }
            return;
        case 5:
            break;
        case 0:
        case 2:
        case 1:
        case 3:
        default: {
            struct ea __0__V208;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"attempt to instantiate a non-YF %n",
                (const struct ea *)((__2__X213 = (const void *)__0this->namep__10basic_inst),
                                    (((&__0__V208)->__O1__2ea.p = __2__X213), (&__0__V208))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        }
        __0this->status__10basic_inst = 1;

        if (((dtpt_opt && (fdummyinst == 0)) && (curloc.file__3loc == first_file)) &&
            (tempdcl == 0))
            fdummyinst = __0this;

        {
            {
                Pexpr __2e;

                Pfunct_inst __2dup;

                __2e = __0this->actuals__10basic_inst;

                for (; __2e; __2e = __2e->__O3__4expr.e2)
                    __2e->__O2__4expr.e1->__O1__4expr.tp =
                        non_template_arg_type__FP8basetype(((struct basetype *)((
                            (struct basetype *)__2e->__O2__4expr.e1->__O1__4expr.tp))));

                ;
                if (__2dup = tfct_copy__10funct_instFRP4cons4bool(__0this,
                                                                  (Pcons *)(&__1templ_refs), 0)) {
                    const void *__2__X214;

                    {
                        struct ea __0__V209;

                        error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"FT %n already instantiated",
                            (const struct ea *)((__2__X214 =
                                                     (const void *)__0this->namep__10basic_inst),
                                                (((&__0__V209)->__O1__2ea.p = __2__X214),
                                                 (&__0__V209))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        return;
                    }
                }
            }
        }
    } else
        tfct_copy__10funct_instFRP4cons4bool(__0this, (Pcons *)(&__1templ_refs), 1);

    __0this->tname__10basic_inst->n_oper__4name =
        __0this->def__10funct_inst->fn__17function_template->n_oper__4name;
    __0this->tname__10basic_inst->where__4name =
        __0this->def__10funct_inst->fn__17function_template->where__4name;

    save_state__10basic_instFP4name((struct basic_inst *)__0this,
                                    __0this->def__10funct_inst->fn__17function_template);
    if ((__0this->def__10funct_inst->open_instantiations__14basic_template++) > 16) {
        const void *__2__X215;

        {
            struct ea __0__V210;

            error__FPCcRC2eaN32(
                (const char *)"%n: an infinite instantiation sequence was initiated",
                (const struct ea *)((__2__X215 = (const void *)__0this->namep__10basic_inst),
                                    (((&__0__V210)->__O1__2ea.p = __2__X215), (&__0__V210))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            __0this->def__10funct_inst->open_instantiations__14basic_template--;
            return;
        }
    }

    {
        Ptfct __1ptf;

        __1ptf = (((struct templ_fct *)((
            (struct templ_fct *)__0this->tname__10basic_inst->__O1__4expr.tp))));
        __1ptf->fct_base__3fct = 4;

        {
            {
                Pcons __1pc;

                struct dcl_context *__0__X216;

                struct dcl_context *__0__X225;

                __1pc = __1templ_refs;

                for (; __1pc; __1pc = __1pc->cdr__4cons) {
                    instantiate__10templ_instF4bool(
                        ((struct templ_inst *)(((struct templ_inst *)__1pc->car__4cons))), 0);

                    ;
                }

                if (__1reinstantiate && __0this->tname__10basic_inst->__O4__4expr.n_table)
                    __0this->tname__10basic_inst->__O4__4expr.n_table = 0;

                if (fct_instantiation == 0)
                    fct_instantiation = __0this;

                fcurr_inst = __0this;

                ((((cc++), (((cc >= ccvec_end)
                                 ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow")
                                 : 0),
                            (((*cc)) = (*(cc - 1))))),
                  (((void)0))));

                cc->cot__11dcl_context = 0;

                cc->not4__11dcl_context = 0;

                cc->tot__11dcl_context = 0;

                cc->c_this__11dcl_context = 0;
                if ((!((__0this->tname__10basic_inst = dcl__4nameFP5tableUc(
                            __0this->tname__10basic_inst, gtbl, (unsigned char)14)) == 0)) ||
                    error_count) {

                    fcurr_inst = __0this;
                    if (se_opt && (finst_body__4nameFv(__0this->tname__10basic_inst) == 0))
                        suppress_error++;
                    simpl__4nameFv(__0this->tname__10basic_inst);
                    {
                        Ptype __2pt;

                        Pblock __2b;

                        unsigned long __2__X217;

                        register struct name *__0__X224;

                        unsigned long __2__X16;

                        struct ea __0__X__V1400q2z144hdwckg;

                        struct ea __0__X__V1500q2z144hdwckg;

                        __2pt = __0this->tname__10basic_inst->__O1__4expr.tp;
                        if (__2pt->base__4node != 108) {
                            struct ea __0__V211;

                            error__FiPCcRC2eaN33(
                                (int)'i', (const char *)"funct_inst::instantiate(%k),FX",
                                (const struct ea *)((__2__X217 = __2pt->base__4node),
                                                    (((((&__0__V211)->__O1__2ea.i = __2__X217), 0)),
                                                     (&__0__V211))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                        if ((fct_instantiation != __0this) &&
                            (fct_instantiation->namep__10basic_inst ==
                             __0this->namep__10basic_inst)) {
                            Pfct __3f;
                            Pblock __3b;

                            Pblock __3b1;

                            register struct name *__0__X220;

                            unsigned long __2__X16;

                            struct ea __0__X__V1400q2z144hdwckg;

                            struct ea __0__X__V1500q2z144hdwckg;

                            register struct name *__0__X221;

                            __3f =
                                ((__0__X221 = fct_instantiation->tname__10basic_inst),
                                 (((__0__X221->__O1__4expr.tp->base__4node == 108)
                                       ? (((struct fct *)((
                                             (struct fct *)__0__X221->__O1__4expr.tp))))
                                       : (error__FiPCcRC2eaN33(
                                              (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                              (const struct ea *)(((&__0__X__V1400q2z144hdwckg)
                                                                       ->__O1__2ea.p =
                                                                       ((const void *)__0__X221)),
                                                                  (&__0__X__V1400q2z144hdwckg)),
                                              (const struct ea *)((__2__X16 = __0__X221->__O1__4expr
                                                                                  .tp->base__4node),
                                                                  (((((&__0__X__V1500q2z144hdwckg)
                                                                          ->__O1__2ea.i = __2__X16),
                                                                     0)),
                                                                   (&__0__X__V1500q2z144hdwckg))),
                                              (const struct ea *)ea0, (const struct ea *)ea0),
                                          (((struct fct *)0))))));
                            __3b = __3f->body__3fct;
                            __3f->body__3fct = 0;
                            current_fct_instantiation = __3f;
                            ;
                            if (dtpt_opt &&
                                (finst_body__4nameFv(__0this->tname__10basic_inst) == 0)) {
                                register struct name *__0__X218;

                                unsigned long __2__X16;

                                struct ea __0__X__V1400q2z144hdwckg;

                                struct ea __0__X__V1500q2z144hdwckg;

                                register struct name *__0__X219;

                                __3b1 =
                                    ((__0__X218 = __0this->tname__10basic_inst),
                                     (((__0__X218->__O1__4expr.tp->base__4node == 108)
                                           ? (((struct fct *)((
                                                 (struct fct *)__0__X218->__O1__4expr.tp))))
                                           : (error__FiPCcRC2eaN33(
                                                  (int)'i',
                                                  (const char *)"N::fct_type():%n is %k notF",
                                                  (const struct ea *)(((&__0__X__V1400q2z144hdwckg)
                                                                           ->__O1__2ea.p = ((
                                                                           const void *)__0__X218)),
                                                                      (&__0__X__V1400q2z144hdwckg)),
                                                  (const struct ea
                                                       *)((__2__X16 = __0__X218->__O1__4expr.tp
                                                                          ->base__4node),
                                                          (((((&__0__X__V1500q2z144hdwckg)
                                                                  ->__O1__2ea.i = __2__X16),
                                                             0)),
                                                           (&__0__X__V1500q2z144hdwckg))),
                                                  (const struct ea *)ea0, (const struct ea *)ea0),
                                              (((struct fct *)0))))))
                                        ->body__3fct;
                                ((__0__X219 = __0this->tname__10basic_inst),
                                 (((__0__X219->__O1__4expr.tp->base__4node == 108)
                                       ? (((struct fct *)((
                                             (struct fct *)__0__X219->__O1__4expr.tp))))
                                       : (error__FiPCcRC2eaN33(
                                              (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                              (const struct ea *)(((&__0__X__V1400q2z144hdwckg)
                                                                       ->__O1__2ea.p =
                                                                       ((const void *)__0__X219)),
                                                                  (&__0__X__V1400q2z144hdwckg)),
                                              (const struct ea *)((__2__X16 = __0__X219->__O1__4expr
                                                                                  .tp->base__4node),
                                                                  (((((&__0__X__V1500q2z144hdwckg)
                                                                          ->__O1__2ea.i = __2__X16),
                                                                     0)),
                                                                   (&__0__X__V1500q2z144hdwckg))),
                                              (const struct ea *)ea0, (const struct ea *)ea0),
                                          (((struct fct *)0))))))
                                    ->body__3fct = 0;
                            }
                            dcl_print__4nameFUc(fct_instantiation->tname__10basic_inst,
                                                (unsigned char)0);
                            if (dtpt_opt &&
                                (finst_body__4nameFv(__0this->tname__10basic_inst) == 0))
                                ((__0__X220 = __0this->tname__10basic_inst),
                                 (((__0__X220->__O1__4expr.tp->base__4node == 108)
                                       ? (((struct fct *)((
                                             (struct fct *)__0__X220->__O1__4expr.tp))))
                                       : (error__FiPCcRC2eaN33(
                                              (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                              (const struct ea *)(((&__0__X__V1400q2z144hdwckg)
                                                                       ->__O1__2ea.p =
                                                                       ((const void *)__0__X220)),
                                                                  (&__0__X__V1400q2z144hdwckg)),
                                              (const struct ea *)((__2__X16 = __0__X220->__O1__4expr
                                                                                  .tp->base__4node),
                                                                  (((((&__0__X__V1500q2z144hdwckg)
                                                                          ->__O1__2ea.i = __2__X16),
                                                                     0)),
                                                                   (&__0__X__V1500q2z144hdwckg))),
                                              (const struct ea *)ea0, (const struct ea *)ea0),
                                          (((struct fct *)0))))))
                                    ->body__3fct = __3b1;
                            current_fct_instantiation = 0;
                            __3f->body__3fct = __3b;
                        }
                        current_fct_instantiation = (((struct fct *)(((struct fct *)__2pt))));

                        ;

                        if (se_opt && (finst_body__4nameFv(__0this->tname__10basic_inst) == 0))
                            suppress_error--;

                        if (dtpt_opt && (finst_body__4nameFv(__0this->tname__10basic_inst) == 0)) {
                            register struct name *__0__X222;

                            unsigned long __2__X16;

                            struct ea __0__X__V1400q2z144hdwckg;

                            struct ea __0__X__V1500q2z144hdwckg;

                            register struct name *__0__X223;

                            __2b =
                                ((__0__X222 = __0this->tname__10basic_inst),
                                 (((__0__X222->__O1__4expr.tp->base__4node == 108)
                                       ? (((struct fct *)((
                                             (struct fct *)__0__X222->__O1__4expr.tp))))
                                       : (error__FiPCcRC2eaN33(
                                              (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                              (const struct ea *)(((&__0__X__V1400q2z144hdwckg)
                                                                       ->__O1__2ea.p =
                                                                       ((const void *)__0__X222)),
                                                                  (&__0__X__V1400q2z144hdwckg)),
                                              (const struct ea *)((__2__X16 = __0__X222->__O1__4expr
                                                                                  .tp->base__4node),
                                                                  (((((&__0__X__V1500q2z144hdwckg)
                                                                          ->__O1__2ea.i = __2__X16),
                                                                     0)),
                                                                   (&__0__X__V1500q2z144hdwckg))),
                                              (const struct ea *)ea0, (const struct ea *)ea0),
                                          (((struct fct *)0))))))
                                    ->body__3fct;
                            ((__0__X223 = __0this->tname__10basic_inst),
                             (((__0__X223->__O1__4expr.tp->base__4node == 108)
                                   ? (((struct fct *)(((struct fct *)__0__X223->__O1__4expr.tp))))
                                   : (error__FiPCcRC2eaN33(
                                          (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                          (const struct ea *)(((&__0__X__V1400q2z144hdwckg)
                                                                   ->__O1__2ea.p =
                                                                   ((const void *)__0__X223)),
                                                              (&__0__X__V1400q2z144hdwckg)),
                                          (const struct ea *)((__2__X16 = __0__X223->__O1__4expr.tp
                                                                              ->base__4node),
                                                              (((((&__0__X__V1500q2z144hdwckg)
                                                                      ->__O1__2ea.i = __2__X16),
                                                                 0)),
                                                               (&__0__X__V1500q2z144hdwckg))),
                                          (const struct ea *)ea0, (const struct ea *)ea0),
                                      (((struct fct *)0))))))
                                ->body__3fct = 0;
                        }

                        dcl_print__4nameFUc(__0this->tname__10basic_inst, (unsigned char)0);

                        if (dtpt_opt && (finst_body__4nameFv(__0this->tname__10basic_inst) == 0))
                            ((__0__X224 = __0this->tname__10basic_inst),
                             (((__0__X224->__O1__4expr.tp->base__4node == 108)
                                   ? (((struct fct *)(((struct fct *)__0__X224->__O1__4expr.tp))))
                                   : (error__FiPCcRC2eaN33(
                                          (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                          (const struct ea *)(((&__0__X__V1400q2z144hdwckg)
                                                                   ->__O1__2ea.p =
                                                                   ((const void *)__0__X224)),
                                                              (&__0__X__V1400q2z144hdwckg)),
                                          (const struct ea *)((__2__X16 = __0__X224->__O1__4expr.tp
                                                                              ->base__4node),
                                                              (((((&__0__X__V1500q2z144hdwckg)
                                                                      ->__O1__2ea.i = __2__X16),
                                                                 0)),
                                                               (&__0__X__V1500q2z144hdwckg))),
                                          (const struct ea *)ea0, (const struct ea *)ea0),
                                      (((struct fct *)0))))))
                                ->body__3fct = __2b;

                        fcurr_inst = 0;
                        current_fct_instantiation = 0;
                    }
                }

                fcurr_inst = 0;
                (((cc--), (((void)0))));

                restore_state__10basic_instFv((struct basic_inst *)__0this);
                __0this->def__10funct_inst->open_instantiations__14basic_template--;
                if (fct_instantiation == __0this)
                    fct_instantiation = 0;
            }
        }
    }
}

static int has_templ_arg__FP8classdefP14templ_classdefP5PslotRi(Pclass __1cl1, Ptclass __1cl2,
                                                                Pbinding __1p, int *__1ni) {
    Ptempl __1t;

    __1t = is_template__17templ_compilationFPCc(templp, __1cl1->string__8classdef);
    if (__1t == 0) {
        struct ea __0__V226;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"has_templ_arg: unable to retrieveCY%t",
            (const struct ea *)(((&__0__V226)->__O1__2ea.p = ((const void *)__1cl1)), (&__0__V226)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    {
        Plist __1formals;
        Pexpr __1actuals;

        __1formals = (((struct basic_template *)__1t)->formals__14basic_template);
        __1actuals = __1cl2->inst__14templ_classdef->actuals__10basic_inst;

        for (; __1formals && __1actuals; ((__1formals = __1formals->l__9name_list),
                                          (__1actuals = __1actuals->__O3__4expr.e2))) {
            Ptype __2at;

            __2at = __1actuals->__O2__4expr.e1->__O1__4expr.tp;
            while (__2at->base__4node == 97)
                __2at = ((((struct basetype *)(((struct basetype *)__2at))))
                             ->b_name__8basetype->__O1__4expr.tp);

            {
                int __2i;

                __2i = -1;
                while ((++__2i) < ((*__1ni))) {
                    if ((__1p[__2i]).param__5Pslot == __1formals->f__9name_list)
                        break;
                }

                if (__2i < ((*__1ni))) {
                    if (check__4typeFP4typeUcT2((__1p[__2i]).typ__5Pslot, __2at, (unsigned char)0,
                                                (unsigned char)0)) {
                        if (!const_problem)
                            return 0;
                    }
                    continue;
                }

                (__1p[((*__1ni))]).param__5Pslot = __1formals->f__9name_list;
                (__1p[(((*__1ni))++)]).typ__5Pslot = __2at;
            }
        }

        return 1;
    }
}

static int has_templ_arg__FP14templ_classdefT1P5PslotRi(Ptclass __1cl1, Ptclass __1cl2,
                                                        Pbinding __1p, int *__1ni) {
    Pexpr __1formals;
    Pexpr __1actuals;

    __1formals = __1cl1->inst__14templ_classdef->actuals__10basic_inst;
    __1actuals = __1cl2->inst__14templ_classdef->actuals__10basic_inst;

    for (; __1formals && __1actuals;
         ((__1formals = __1formals->__O3__4expr.e2), (__1actuals = __1actuals->__O3__4expr.e2))) {
        Pexpr __2fe;

        __2fe = __1formals->__O2__4expr.e1;
        if ((__2fe->base__4node != 85) || (__2fe->__O1__4expr.tp->base__4node != 97))
            continue;
        {
            Pname __2ftn;

            struct type *__0__X227;

            __2ftn = ((__0__X227 = __2fe->__O1__4expr.tp),
                      ((((struct basetype *)(((struct basetype *)__0__X227))))->b_name__8basetype));
            if (!((((unsigned char)(__2ftn->n_template_arg__4name == 1)))))
                continue;

            {
                Ptype __2at;

                __2at = __1actuals->__O2__4expr.e1->__O1__4expr.tp;
                while (__2at->base__4node == 97)
                    __2at = ((((struct basetype *)(((struct basetype *)__2at))))
                                 ->b_name__8basetype->__O1__4expr.tp);

                {
                    int __2i;

                    __2i = -1;
                    while ((++__2i) < ((*__1ni))) {
                        if ((__1p[__2i]).param__5Pslot == __2ftn)
                            break;
                    }

                    if (__2i < ((*__1ni))) {
                        if (check__4typeFP4typeUcT2((__1p[__2i]).typ__5Pslot, __2at,
                                                    (unsigned char)0, (unsigned char)0)) {
                            if (!const_problem)
                                return 0;
                        }
                        continue;
                    }

                    (__1p[((*__1ni))]).param__5Pslot = __2ftn;
                    (__1p[(((*__1ni))++)]).typ__5Pslot = __2at;
                }
            }
        }
    }

    return 1;
}

bit tconst__4typeFv(struct type *__0this);

static bit formal_not_const__FP4name(Pname __1nn) {
    Ptype __1t;
    bit __1cnst;

    __1t = __1nn->__O1__4expr.tp;
    __1cnst = tconst__4typeFv(__1t);

loop:
    if (__1cnst == 0)
        if ((__1t->base__4node == 125) || (__1t->base__4node == 158)) {
            __1t = (((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp;

            __1cnst = tconst__4typeFv(__1t);
            goto loop;
        }
    return (unsigned char)(__1cnst == 0);
}

static void check_valid_formal_type__FP4type(Ptype __1et) {
    __1et = skiptypedefs__4typeFv(__1et);
    switch (__1et->base__4node) {
    case 114:
        error__FiPCc((int)'s', (const char *)"formalYZ of type bit field");
        break;
    case 38:
        error__FPCc((const char *)"formalYZ of type void illegal");
        break;
    }
}

Pclass is_base__8classdefFPCcPUci(struct classdef *__0this, const char *, TOK *, int __1level);

struct Pslot *is_ftempl_match__FP4exprP17function_template(Pexpr __1actuals, Pfunt __1ft) {
    int __1count;
    struct Pslot *__1parray;
    int __1ni;

    Pfct __1f;
    Pexpr __1e;
    Pname __1nn;

    register struct name *__0__X232;

    unsigned long __2__X16;

    struct ea __0__X__V1400q2z144hdwckg;

    struct ea __0__X__V1500q2z144hdwckg;

    __1count = get_formals_count__14basic_templateFv((struct basic_template *)__1ft);
    __1parray = (((struct Pslot *)__nw__FUl((size_t)((sizeof(struct Pslot)) * __1count))));
    __1ni = 0;

    __1f =
        ((__0__X232 = __1ft->fn__17function_template),
         (((__0__X232->__O1__4expr.tp->base__4node == 108)
               ? (((struct fct *)(((struct fct *)__0__X232->__O1__4expr.tp))))
               : (error__FiPCcRC2eaN33(
                      (int)'i', (const char *)"N::fct_type():%n is %k notF",
                      (const struct ea *)(((&__0__X__V1400q2z144hdwckg)->__O1__2ea.p =
                                               ((const void *)__0__X232)),
                                          (&__0__X__V1400q2z144hdwckg)),
                      (const struct ea *)((__2__X16 = __0__X232->__O1__4expr.tp->base__4node),
                                          (((((&__0__X__V1500q2z144hdwckg)->__O1__2ea.i = __2__X16),
                                             0)),
                                           (&__0__X__V1500q2z144hdwckg))),
                      (const struct ea *)ea0, (const struct ea *)ea0),
                  (((struct fct *)0))))));
    __1e = __1actuals;
    __1nn = __1f->argtype__3fct;

    for (; __1e; ((__1e = __1e->__O3__4expr.e2), (__1nn = __1nn->__O1__4name.n_list))) {
        if (__1nn == 0) {
            if (__1f->nargs_known__3fct == 155) {
                return __1parray;
            }
            __dl__FPv((void *)__1parray);
            return (struct Pslot *)0;
        }

        {
            Pexpr __2a;
            Ptype __2et;

            __2a = __1e->__O2__4expr.e1;
            __2et = __2a->__O1__4expr.tp;

            check_valid_formal_type__FP4type(__2et);

            {
                Ptype __2t;

                __2t = __1nn->__O1__4expr.tp;
                if (is_ref__4typeFv(__2t)) {
                    __2t = (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv(__2t)))))
                               ->typ__5pvtyp;
                    if (is_ref__4typeFv(__2et))
                        __2et = (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv(__2et)))))
                                    ->typ__5pvtyp;
                }

                if (check__4typeFP4typeUcT2(__2t, __2et, (unsigned char)76, (unsigned char)0)) {
                    if (const_problem) {
                        if (((is_ptr_or_ref__4typeFv(__2t) != 0) &&
                             (is_ptr_or_ref__4typeFv(__2et) != 0)) &&
                            formal_not_const__FP4name(__1nn)) {
                            __dl__FPv((void *)__1parray);
                            return (struct Pslot *)0;
                        }
                    } else {
                        __dl__FPv((void *)__1parray);
                        return (struct Pslot *)0;
                    }
                }

                {
                    int __2ptr_count;

                    int __2ref_count;
                    Ptype __2nt;
                    Pname __2ptm;

                    __2ptr_count = 0;

                    __2ref_count = 0;
                    __2nt = __1nn->__O1__4expr.tp;
                    __2ptm = 0;

                    if (is_ref__4typeFv(__2nt)) {
                        __2nt = (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv(__2nt)))))
                                    ->typ__5pvtyp;
                    }
                    while (__2t = (struct type *)is_ptr__4typeFv(__2nt)) {
                        ++__2ptr_count;
                        {
                            Pptr __3p;

                            __3p = (((struct ptr *)(((struct ptr *)__2t))));
                            if (__3p->ptname__3ptr) {
                                __2ptm = __3p->ptname__3ptr;

                                break;
                            }
                            __2nt = (((struct ptr *)(((struct ptr *)__2t))))->typ__5pvtyp;
                        }
                    }

                    while ((__2ptr_count--) && (__2t = (struct type *)is_ptr__4typeFv(__2et))) {
                        Pptr __3p;

                        __3p = (((struct ptr *)(((struct ptr *)__2t))));
                        if (__3p->memof__3ptr) {
                            __2et = (struct type *)__3p->memof__3ptr;

                            break;
                        }
                        __2et = (((struct ptr *)(((struct ptr *)__2t))))->typ__5pvtyp;
                    }

                    {
                        Pname __2bn;

                        __2bn = __2ptm;
                        if (__2bn == 0) {
                            while (__2t = (struct type *)is_ref__4typeFv(__2nt)) {
                                ++__2ref_count;

                                __2nt = (((struct ptr *)(((struct ptr *)__2t))))->typ__5pvtyp;
                            }
                            while ((__2ref_count--) &&
                                   (__2t = (struct type *)is_ref__4typeFv(__2et)))
                                __2et = (((struct ptr *)(((struct ptr *)__2t))))->typ__5pvtyp;

                            if (__2nt->base__4node != 97)
                                continue;
                            while (__2nt->base__4node == 97) {
                                __2bn = ((((struct basetype *)(((struct basetype *)__2nt))))
                                             ->b_name__8basetype);
                                if (((((unsigned char)(__2bn->n_template_arg__4name == 1)))))
                                    break;
                                else
                                    __2bn = 0;
                                __2nt = ((((struct basetype *)(((struct basetype *)__2nt))))
                                             ->b_name__8basetype->__O1__4expr.tp);
                            }
                        }

                        while (__2et->base__4node == 97)
                            __2et = ((((struct basetype *)(((struct basetype *)__2et))))
                                         ->b_name__8basetype->__O1__4expr.tp);
                        if (__2bn == 0) {
                            if ((__2nt->base__4node == 119) && (__2et->base__4node == 119)) {
                                Pclass __4c1;
                                Pclass __4c2;

                                __4c1 = classtype__4typeFv(__2nt);
                                __4c2 = classtype__4typeFv(__2et);

                                if (!__4c1->class_base__8classdef)
                                    continue;

                                if (__4c1->class_base__8classdef == 2) {
                                    struct classdef *__1__X229;

                                    struct classdef *__1__X230;

                                    if ((((__1__X229 = __4c1),
                                          ((__1__X230 = __4c2),
                                           (((__1__X229 == __1__X230)
                                                 ? 1
                                                 : ((__1__X229 && __1__X230)
                                                        ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X229, __1__X230, 1)))
                                                        : 0))))) == 0) &&
                                        (is_base__8classdefFPCcPUci(__4c2, __4c1->string__8classdef,
                                                                    (TOK *)0, 0) == 0))
                                        continue;
                                } else if ((same_class_templ__FP8classdefT1(__4c1, __4c2) == 0) &&
                                           ((__4c2 = is_base__8classdefFPCcPUci(
                                                 __4c2, __4c1->string__8classdef, (TOK *)0, 0)) ==
                                            0))
                                    continue;

                                {
                                    int __4bound_formals;

                                    __4bound_formals = 0;
                                    if (__4c1->class_base__8classdef == 2)
                                        __4bound_formals =
                                            has_templ_arg__FP8classdefP14templ_classdefP5PslotRi(
                                                __4c1,
                                                ((struct templ_classdef *)((
                                                    (struct templ_classdef *)__4c2))),
                                                __1parray, (int *)(&__1ni));
                                    else
                                        __4bound_formals =
                                            has_templ_arg__FP14templ_classdefT1P5PslotRi(
                                                ((struct templ_classdef *)((
                                                    (struct templ_classdef *)__4c1))),
                                                ((struct templ_classdef *)((
                                                    (struct templ_classdef *)__4c2))),
                                                __1parray, (int *)(&__1ni));

                                    if (!__4bound_formals) {
                                        __dl__FPv((void *)__1parray);

                                        return (struct Pslot *)0;
                                    }
                                    continue;
                                }
                            } else
                                continue;
                        }

                        {
                            Pptr __2p;

                            __2p = 0;
                            if ((__2et->base__4node == 125) &&
                                ((((struct ptr *)(((struct ptr *)__2et))))
                                     ->typ__5pvtyp->base__4node == 108)) {
                                Pfct __3f;

                                __3f = (((struct fct *)((
                                    (struct fct *)(((struct ptr *)(((struct ptr *)__2et))))
                                        ->typ__5pvtyp))));
                                if (__3f->fct_base__3fct == 1) {
                                    const void *__2__X231;

                                    {
                                        struct ea __0__V228;

                                        error__FPCcRC2eaN32(
                                            (const char
                                                 *)"actual argument toFY%n is an uninstantiatedFY",
                                            (const struct ea *)((__2__X231 =
                                                                     (const void *)__1ft
                                                                         ->fn__17function_template),
                                                                (((&__0__V228)->__O1__2ea.p =
                                                                      __2__X231),
                                                                 (&__0__V228))),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                        __dl__FPv((void *)__1parray);
                                        return (struct Pslot *)0;
                                    }
                                }

                                if (__3f->body__3fct) {
                                    Pfct __4ff;

                                    __4ff = __ct__3fctFP4typeP4nameUc(
                                        (struct fct *)0, (struct type *)0, (struct name *)0,
                                        (unsigned char)0);
                                    ((*__4ff)) = (*__3f);
                                    __4ff->body__3fct = 0;
                                    __2p = __ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125,
                                                               (struct type *)__4ff);
                                    __2p->memof__3ptr =
                                        (((struct ptr *)(((struct ptr *)__2et))))->memof__3ptr;
                                    __2p->ptname__3ptr =
                                        (((struct ptr *)(((struct ptr *)__2et))))->ptname__3ptr;
                                }
                            }
                            if (__2et->base__4node == 110)
                                __2p = __ct__3ptrFUcP4type(
                                    (struct ptr *)0, (unsigned char)125,
                                    (((struct vec *)(((struct vec *)__2et))))->typ__5pvtyp);

                            {
                                int __2i;

                                __2i = -1;
                                while ((++__2i) < __1ni) {
                                    if ((__1parray[__2i]).param__5Pslot == __2bn)
                                        break;
                                }

                                if (__2i < __1ni) {
                                    if (check__4typeFP4typeUcT2(
                                            (__1parray[__2i]).typ__5Pslot,
                                            (__2p == 0) ? __2et : (((struct type *)__2p)),
                                            (unsigned char)0, (unsigned char)0)) {
                                        if (const_problem)
                                            continue;

                                        __dl__FPv((void *)__1parray);
                                        return (struct Pslot *)0;
                                    }
                                    continue;
                                }

                                if (__2et->base__4node == 76) {
                                    __dl__FPv((void *)__1parray);
                                    return (struct Pslot *)0;
                                }

                                (__1parray[__1ni]).param__5Pslot = __2bn;
                                (__1parray[(__1ni++)]).typ__5Pslot =
                                    ((__2p == 0) ? __2et : (((struct type *)__2p)));
                            }
                        }
                    }
                }
            }
        }
    }
    if (__1nn && (!__1nn->__O3__4expr.n_initializer)) {
        __dl__FPv((void *)__1parray);
        return (struct Pslot *)0;
    }
    if (__1ni < __1count)
        return (struct Pslot *)0;
    return __1parray;
}

Pname has_templ_instance__FP4nameP4exprUc(Pname __1fn, Pexpr __1arg, bit __1no_err) {
    if ((__1fn->n_template_fct__4name) == 0)
        return (struct name *)0;

    {
        Pfunt __1ft;

        __1ft = is_template__17templ_compilationFPCcUc(templp, __1fn->__O2__4expr.string,
                                                       (unsigned char)108);
        if (__1ft == 0) {
            struct ea __0__V233;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"%n flagged asYF but not entered inY table",
                (const struct ea *)(((&__0__V233)->__O1__2ea.p = ((const void *)__1fn)),
                                    (&__0__V233)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__1ft->gen_list__17function_template && (__1fn->__O1__4expr.tp->base__4node != 76)) {
            struct ea __0__V234;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"%n gtbl: non-overloaded,Y table: overloaded",
                (const struct ea *)(((&__0__V234)->__O1__2ea.p = ((const void *)__1fn)),
                                    (&__0__V234)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        {
            Pbinding __1pb;
            Pfunt __1instance;

            bit __1used_conv;
            int __1conv_reqd;
            int __1no_conv_reqd;

            __1pb = 0;
            __1instance = 0;

            __1used_conv = 0;
            __1conv_reqd = 0;
            __1no_conv_reqd = 0;

            {
                {
                    Pfunt __1p;

                    __1p = __1ft;

                    for (; __1p; __1p = __1p->gen_list__17function_template) {
                        Pbinding __2b;
                        template_hier = 1;
                        Nvirt = 0;

                        if (__2b = is_ftempl_match__FP4exprP17function_template(__1arg, __1p)) {
                            if (!__1instance) {
                                __1pb = __2b;
                                __1instance = __1p;
                                __1used_conv = ((Nvirt == 0) ? 0 : 1);
                            } else if (__1used_conv && (Nvirt == 0)) {
                                __1pb = __2b;
                                __1instance = __1p;
                                __1used_conv = 0;
                            }
                            (Nvirt == 0) ? (__1no_conv_reqd++) : (__1conv_reqd++);
                        }
                    }

                    if (!__1instance) {
                        if ((__1fn->__O1__4expr.tp->base__4node == 108) && (!__1no_err)) {
                            {
                                struct ea __0__V235;

                                error__FPCcRC2eaN32(
                                    (const char
                                         *)"use ofYF%n does not match any of itsY definitions",
                                    (const struct ea *)(((&__0__V235)->__O1__2ea.p =
                                                             ((const void *)__1fn)),
                                                        (&__0__V235)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                        }
                        template_hier = 0;
                        return (struct name *)0;
                    } else if ((__1no_conv_reqd > 1) ||
                               ((__1no_conv_reqd == 0) && (__1conv_reqd > 1))) {
                        {
                            struct ea __0__V236;

                            error__FPCcRC2eaN32(
                                (const char *)"use ofYF%n matches multiple instances",
                                (const struct ea *)(((&__0__V236)->__O1__2ea.p =
                                                         ((const void *)__1fn)),
                                                    (&__0__V236)),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                    }

                    template_hier = __1conv_reqd;
                    {
                        Pfunct_inst __1fctmpl;

                        __1fctmpl = get_inst__17function_templateFP4exprP10funct_inst(
                            __1instance, __1arg, (struct funct_inst *)0);
                        template_hier = 0;
                        __1fctmpl->binding__10funct_inst = __1pb;
                        instantiate__10funct_instF4bool(__1fctmpl, 0);
                        {
                            Pname __1fct_inst;

                            __1fct_inst = (((struct basic_inst *)__1fctmpl)->tname__10basic_inst);

                            return __1fct_inst;
                        }
                    }
                }
            }
        }
    }
}

extern void abort(void);

void dummy__14basic_templateFv(struct basic_template *__0this) { abort(); }

void dummy__10basic_instFv(struct basic_inst *__0this) { abort(); }
extern struct __mptr __vtbl__17function_template[];
extern struct __mptr __vtbl__13data_template[];
extern struct __mptr __vtbl__5templ[];
struct __mptr __vtbl__10funct_inst[] = {0, 0, 0,
                                        0, 0, (__vptp)dummy__10basic_instFv,
                                        0, 0, (__vptp)print_pretty_name__10funct_instFv,
                                        0, 0, (__vptp)mangled_name__10funct_instFPc,
                                        0, 0, 0};
struct __mptr __vtbl__10templ_inst[] = {0, 0, 0,
                                        0, 0, (__vptp)dummy__10basic_instFv,
                                        0, 0, (__vptp)print_pretty_name__10templ_instFv,
                                        0, 0, (__vptp)mangled_name__10templ_instFPc,
                                        0, 0, 0};
char __pure_virtual_called();
struct __mptr __vtbl__10basic_inst[] = {0, 0, 0,
                                        0, 0, (__vptp)dummy__10basic_instFv,
                                        0, 0, (__vptp)__pure_virtual_called,
                                        0, 0, (__vptp)__pure_virtual_called,
                                        0, 0, 0};
struct __mptr __vtbl__14basic_template[] = {
    0, 0, 0, 0, 0, (__vptp)dummy__14basic_templateFv, 0, 0, (__vptp)__pure_virtual_called, 0, 0, 0};

static struct ea *__ct__2eaFUl(struct ea *__0this, size_t __2ii) {
    if (__0this || (__0this = (struct ea *)__nw__FUl((size_t)(sizeof(struct ea)))))
        __0this->__O1__2ea.i = __2ii;

    return __0this;
}

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp) {
    if (__0this || (__0this = (struct ea *)__nw__FUl((unsigned long)(sizeof(struct ea)))))
        __0this->__O1__2ea.p = __2pp;

    return __0this;
}

extern Ptfct ptfct_free__9templ_fct;

int parameters_in_progress__17templ_compilation;

int in_progress__17templ_compilation;

struct Hash *ht__10patch_tree;

Ppatch_tree head__10patch_tree;

extern Pstmt stmt_free__4stmt;

extern Pname name_free__4name;

extern Pexpr expr_free__4expr;

extern Pptr ptr_free__3ptr;

extern Pvec vec_free__3vec;

extern Pfct fct_free__3fct;

extern Pktab table_free__6ktable;

extern Ptable table_free__5table;
struct __mptr *__ptbl_vec___[] = {
    __vtbl__14basic_template,    __vtbl__5templ,       __vtbl__10basic_inst,
    __vtbl__10templ_inst,        __vtbl__10funct_inst, __vtbl__13data_template,
    __vtbl__17function_template,

};

/* the end */
