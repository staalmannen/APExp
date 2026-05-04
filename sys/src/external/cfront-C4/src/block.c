
/* <<AT&T C++ Language System <3.0.3> 05/05/94>> */

#pragma lib "ape/libap.a"

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
struct Block_Pname;

struct Block_Pname { /* sizeof Block_Pname == 16 */

    Pname *p__11Block_Pname;

    size_t n__11Block_Pname;
};

void move__11Block_PnameFPP4nameUl(struct Block_Pname *__0this, Pname *, size_t);

void copy__11Block_PnameFRC11Block_Pname(struct Block_Pname *__0this, const struct Block_Pname *);

extern void __dl__FPv(void *);

size_t grow__11Block_PnameFUl(struct Block_Pname *__0this, size_t);
typedef struct Block_Pname BlockPname;
struct Block_BlockPname;
struct Block_BlockPname { /* sizeof Block_BlockPname == 16 */

    BlockPname *p__16Block_BlockPname;

    size_t n__16Block_BlockPname;
};

void move__16Block_BlockPnameFP11Block_PnameUl(struct Block_BlockPname *__0this, BlockPname *,
                                               size_t);

static struct Block_Pname *__ct__11Block_PnameFv(struct Block_Pname *__0this);

void copy__16Block_BlockPnameFRC16Block_BlockPname(struct Block_BlockPname *__0this,
                                                   const struct Block_BlockPname *);

static void __dt__11Block_PnameFv(struct Block_Pname *__0this, int __0__free);

size_t grow__16Block_BlockPnameFUl(struct Block_BlockPname *__0this, size_t);
struct Block_int;
struct Block_int { /* sizeof Block_int == 16 */

    int *p__9Block_int;

    size_t n__9Block_int;
};

void move__9Block_intFPiUl(struct Block_int *__0this, int *, size_t);

void copy__9Block_intFRC9Block_int(struct Block_int *__0this, const struct Block_int *);

size_t grow__9Block_intFUl(struct Block_int *__0this, size_t);
struct Block_Pchar;
struct Block_Pchar { /* sizeof Block_Pchar == 16 */

    Pchar *p__11Block_Pchar;

    size_t n__11Block_Pchar;
};

void move__11Block_PcharFPPcUl(struct Block_Pchar *__0this, Pchar *, size_t);

void copy__11Block_PcharFRC11Block_Pchar(struct Block_Pchar *__0this, const struct Block_Pchar *);

size_t grow__11Block_PcharFUl(struct Block_Pchar *__0this, size_t);
struct Block_CPchar;
struct Block_CPchar { /* sizeof Block_CPchar == 16 */

    CPchar *p__12Block_CPchar;

    size_t n__12Block_CPchar;
};

void move__12Block_CPcharFPPCcUl(struct Block_CPchar *__0this, CPchar *, size_t);

void copy__12Block_CPcharFRC12Block_CPchar(struct Block_CPchar *__0this,
                                           const struct Block_CPchar *);

size_t grow__12Block_CPcharFUl(struct Block_CPchar *__0this, size_t);
struct Block_short;
struct Block_short { /* sizeof Block_short == 16 */

    short *p__11Block_short;

    size_t n__11Block_short;
};

void move__11Block_shortFPsUl(struct Block_short *__0this, short *, size_t);

void copy__11Block_shortFRC11Block_short(struct Block_short *__0this, const struct Block_short *);

size_t grow__11Block_shortFUl(struct Block_short *__0this, size_t);

static Pname Block_Pname_def;

void clear__11Block_PnameFPP4nameUl(struct Block_Pname *__0this, Pname *__1v, size_t __1k) {
    Pname *__1p;

    Pname *__1lim;

    __1p = __1v;

    __1lim = (__1v + __1k);

    while (__1p < __1lim)
        ((*(__1p++))) = Block_Pname_def;
}

void transfer__11Block_PnameFPP4nameUl(struct Block_Pname *__0this, Pname *, size_t);

void copy__11Block_PnameFRC11Block_Pname(register struct Block_Pname *__0this,
                                         const struct Block_Pname *__1b) {
    __0this->p__11Block_Pname = ((
        (struct name **)__nw__FUl((size_t)((sizeof(struct name *)) * ((*__1b)).n__11Block_Pname))));

    if (__0this->p__11Block_Pname) {
        __0this->n__11Block_Pname = ((*__1b)).n__11Block_Pname;

        transfer__11Block_PnameFPP4nameUl(__0this, (Pname *)((*__1b)).p__11Block_Pname,
                                          __0this->n__11Block_Pname);

    } else
        __0this->n__11Block_Pname = 0;
}

size_t grow__11Block_PnameFUl(register struct Block_Pname *__0this, size_t __1k) {
    size_t __1nn;

    __1nn = __0this->n__11Block_Pname;

    if (__1nn == 0)
        __1nn++;

    while (__1nn <= __1k)
        __1nn += ((__1nn >> 1) + 1);

    {
        Pname *__1np;

        __1np = (((struct name **)__nw__FUl((size_t)((sizeof(struct name *)) * __1nn))));

        if (!__1np) {
            __1nn = (__1k + 1);

            __1np = (((struct name **)__nw__FUl((size_t)((sizeof(struct name *)) * __1nn))));
        }

        move__11Block_PnameFPP4nameUl(__0this, __1np, __1nn);

        return __0this->n__11Block_Pname;
    }
}

void transfer__11Block_PnameFPP4nameUl(register struct Block_Pname *__0this, Pname *__1source,
                                       size_t __1len) {
    Pname *__1plim;

    Pname *__1pp;

    Pname *__1q;

    __1pp = __0this->p__11Block_Pname;

    __1q = __1source;

    if (__0this->n__11Block_Pname > __1len) {
        __1plim = (__0this->p__11Block_Pname + __1len);

        clear__11Block_PnameFPP4nameUl(__0this, __1plim, __0this->n__11Block_Pname - __1len);

    } else
        __1plim = (__0this->p__11Block_Pname + __0this->n__11Block_Pname);

    while (__1pp < __1plim)
        ((*(__1pp++))) = ((*(__1q++)));
}

void move__11Block_PnameFPP4nameUl(register struct Block_Pname *__0this, Pname *__1np,
                                   size_t __1nn) {
    Pname *__1oldp;

    size_t __1oldn;

    __1oldp = __0this->p__11Block_Pname;

    __1oldn = __0this->n__11Block_Pname;

    __0this->p__11Block_Pname = __1np;

    if (__1np) {
        __0this->n__11Block_Pname = __1nn;

        transfer__11Block_PnameFPP4nameUl(__0this, __1oldp, __1oldn);

    } else
        __0this->n__11Block_Pname = 0;

    __dl__FPv((void *)__1oldp);
}

void swap__11Block_PnameFR11Block_Pname(register struct Block_Pname *__0this,
                                        struct Block_Pname *__1b) {
    Pname *__1bp;

    size_t __1bn;

    __1bp = ((*__1b)).p__11Block_Pname;

    __1bn = ((*__1b)).n__11Block_Pname;

    ((*__1b)).p__11Block_Pname = __0this->p__11Block_Pname;

    ((*__1b)).n__11Block_Pname = __0this->n__11Block_Pname;

    __0this->p__11Block_Pname = __1bp;

    __0this->n__11Block_Pname = __1bn;
}
static int Block_int_def;

void clear__9Block_intFPiUl(struct Block_int *__0this, int *__1v, size_t __1k) {
    int *__1p;

    int *__1lim;

    __1p = __1v;

    __1lim = (__1v + __1k);

    while (__1p < __1lim)
        ((*(__1p++))) = Block_int_def;
}

void transfer__9Block_intFPiUl(struct Block_int *__0this, int *, size_t);

void copy__9Block_intFRC9Block_int(register struct Block_int *__0this,
                                   const struct Block_int *__1b) {
    __0this->p__9Block_int =
        (((int *)__nw__FUl((size_t)((sizeof(int)) * ((*__1b)).n__9Block_int))));

    if (__0this->p__9Block_int) {
        __0this->n__9Block_int = ((*__1b)).n__9Block_int;

        transfer__9Block_intFPiUl(__0this, (int *)((*__1b)).p__9Block_int, __0this->n__9Block_int);

    } else
        __0this->n__9Block_int = 0;
}

size_t grow__9Block_intFUl(register struct Block_int *__0this, size_t __1k) {
    size_t __1nn;

    __1nn = __0this->n__9Block_int;

    if (__1nn == 0)
        __1nn++;

    while (__1nn <= __1k)
        __1nn += ((__1nn >> 1) + 1);

    {
        int *__1np;

        __1np = (((int *)__nw__FUl((size_t)((sizeof(int)) * __1nn))));

        if (!__1np) {
            __1nn = (__1k + 1);

            __1np = (((int *)__nw__FUl((size_t)((sizeof(int)) * __1nn))));
        }

        move__9Block_intFPiUl(__0this, __1np, __1nn);

        return __0this->n__9Block_int;
    }
}

void transfer__9Block_intFPiUl(register struct Block_int *__0this, int *__1source, size_t __1len) {
    int *__1plim;

    int *__1pp;

    int *__1q;

    __1pp = __0this->p__9Block_int;

    __1q = __1source;

    if (__0this->n__9Block_int > __1len) {
        __1plim = (__0this->p__9Block_int + __1len);

        clear__9Block_intFPiUl(__0this, __1plim, __0this->n__9Block_int - __1len);

    } else
        __1plim = (__0this->p__9Block_int + __0this->n__9Block_int);

    while (__1pp < __1plim)
        ((*(__1pp++))) = ((*(__1q++)));
}

void move__9Block_intFPiUl(register struct Block_int *__0this, int *__1np, size_t __1nn) {
    int *__1oldp;

    size_t __1oldn;

    __1oldp = __0this->p__9Block_int;

    __1oldn = __0this->n__9Block_int;

    __0this->p__9Block_int = __1np;

    if (__1np) {
        __0this->n__9Block_int = __1nn;

        transfer__9Block_intFPiUl(__0this, __1oldp, __1oldn);

    } else
        __0this->n__9Block_int = 0;

    __dl__FPv((void *)__1oldp);
}

void swap__9Block_intFR9Block_int(register struct Block_int *__0this, struct Block_int *__1b) {
    int *__1bp;

    size_t __1bn;

    __1bp = ((*__1b)).p__9Block_int;

    __1bn = ((*__1b)).n__9Block_int;

    ((*__1b)).p__9Block_int = __0this->p__9Block_int;

    ((*__1b)).n__9Block_int = __0this->n__9Block_int;

    __0this->p__9Block_int = __1bp;

    __0this->n__9Block_int = __1bn;
}
static BlockPname Block_BlockPname_def;

void clear__16Block_BlockPnameFP11Block_PnameUl(struct Block_BlockPname *__0this, BlockPname *__1v,
                                                size_t __1k) {
    BlockPname *__1p;

    BlockPname *__1lim;

    register struct Block_Pname *__0__X17;

    const struct Block_Pname *__2__X18;

    __1p = __1v;

    __1lim = (__1v + __1k);

    while (__1p < __1lim)
        ((__0__X17 = (__1p++)), ((__2__X18 = (const struct Block_Pname *)(&Block_BlockPname_def)),
                                 (__dl__FPv((void *)__0__X17->p__11Block_Pname),
                                  (copy__11Block_PnameFRC11Block_Pname(__0__X17, __2__X18),
                                   (((struct Block_Pname *)__0__X17))))));
}

void transfer__16Block_BlockPnameFP11Block_PnameUl(struct Block_BlockPname *__0this, BlockPname *,
                                                   size_t);

void copy__16Block_BlockPnameFRC16Block_BlockPname(register struct Block_BlockPname *__0this,
                                                   const struct Block_BlockPname *__1b) {
    __0this->p__16Block_BlockPname = (((struct Block_Pname *)__vec_new(
        ((void *)0), ((*__1b)).n__16Block_BlockPname, sizeof(struct Block_Pname),
        ((void *)__ct__11Block_PnameFv))));

    if (__0this->p__16Block_BlockPname) {
        __0this->n__16Block_BlockPname = ((*__1b)).n__16Block_BlockPname;

        transfer__16Block_BlockPnameFP11Block_PnameUl(
            __0this, (BlockPname *)((*__1b)).p__16Block_BlockPname, __0this->n__16Block_BlockPname);

    } else
        __0this->n__16Block_BlockPname = 0;
}

size_t grow__16Block_BlockPnameFUl(register struct Block_BlockPname *__0this, size_t __1k) {
    size_t __1nn;

    __1nn = __0this->n__16Block_BlockPname;

    if (__1nn == 0)
        __1nn++;

    while (__1nn <= __1k)
        __1nn += ((__1nn >> 1) + 1);

    {
        BlockPname *__1np;

        __1np = (((struct Block_Pname *)__vec_new(((void *)0), __1nn, sizeof(struct Block_Pname),
                                                  ((void *)__ct__11Block_PnameFv))));

        if (!__1np) {
            __1nn = (__1k + 1);

            __1np = (((struct Block_Pname *)__vec_new(
                ((void *)0), __1nn, sizeof(struct Block_Pname), ((void *)__ct__11Block_PnameFv))));
        }

        move__16Block_BlockPnameFP11Block_PnameUl(__0this, __1np, __1nn);

        return __0this->n__16Block_BlockPname;
    }
}

void transfer__16Block_BlockPnameFP11Block_PnameUl(register struct Block_BlockPname *__0this,
                                                   BlockPname *__1source, size_t __1len) {
    BlockPname *__1plim;

    BlockPname *__1pp;

    BlockPname *__1q;

    register struct Block_Pname *__0__X19;

    const struct Block_Pname *__2__X20;

    __1pp = __0this->p__16Block_BlockPname;

    __1q = __1source;

    if (__0this->n__16Block_BlockPname > __1len) {
        __1plim = (__0this->p__16Block_BlockPname + __1len);

        clear__16Block_BlockPnameFP11Block_PnameUl(__0this, __1plim,
                                                   __0this->n__16Block_BlockPname - __1len);

    } else
        __1plim = (__0this->p__16Block_BlockPname + __0this->n__16Block_BlockPname);

    while (__1pp < __1plim)
        ((__0__X19 = (__1pp++)), ((__2__X20 = (const struct Block_Pname *)(__1q++)),
                                  (__dl__FPv((void *)__0__X19->p__11Block_Pname),
                                   (copy__11Block_PnameFRC11Block_Pname(__0__X19, __2__X20),
                                    (((struct Block_Pname *)__0__X19))))));
}

void move__16Block_BlockPnameFP11Block_PnameUl(register struct Block_BlockPname *__0this,
                                               BlockPname *__1np, size_t __1nn) {
    BlockPname *__1oldp;

    size_t __1oldn;

    __1oldp = __0this->p__16Block_BlockPname;

    __1oldn = __0this->n__16Block_BlockPname;

    __0this->p__16Block_BlockPname = __1np;

    if (__1np) {
        __0this->n__16Block_BlockPname = __1nn;

        transfer__16Block_BlockPnameFP11Block_PnameUl(__0this, __1oldp, __1oldn);

    } else
        __0this->n__16Block_BlockPname = 0;

    __vec_delete(((void *)__1oldp), -1, sizeof(struct Block_Pname), ((void *)__dt__11Block_PnameFv),
                 1, 0);
}

void swap__16Block_BlockPnameFR16Block_BlockPname(register struct Block_BlockPname *__0this,
                                                  struct Block_BlockPname *__1b) {
    BlockPname *__1bp;

    size_t __1bn;

    __1bp = ((*__1b)).p__16Block_BlockPname;

    __1bn = ((*__1b)).n__16Block_BlockPname;

    ((*__1b)).p__16Block_BlockPname = __0this->p__16Block_BlockPname;

    ((*__1b)).n__16Block_BlockPname = __0this->n__16Block_BlockPname;

    __0this->p__16Block_BlockPname = __1bp;

    __0this->n__16Block_BlockPname = __1bn;
}
static Pchar Block_Pchar_def;

void clear__11Block_PcharFPPcUl(struct Block_Pchar *__0this, Pchar *__1v, size_t __1k) {
    Pchar *__1p;

    Pchar *__1lim;

    __1p = __1v;

    __1lim = (__1v + __1k);

    while (__1p < __1lim)
        ((*(__1p++))) = Block_Pchar_def;
}

void transfer__11Block_PcharFPPcUl(struct Block_Pchar *__0this, Pchar *, size_t);

void copy__11Block_PcharFRC11Block_Pchar(register struct Block_Pchar *__0this,
                                         const struct Block_Pchar *__1b) {
    __0this->p__11Block_Pchar =
        (((char **)__nw__FUl((size_t)((sizeof(char *)) * ((*__1b)).n__11Block_Pchar))));

    if (__0this->p__11Block_Pchar) {
        __0this->n__11Block_Pchar = ((*__1b)).n__11Block_Pchar;

        transfer__11Block_PcharFPPcUl(__0this, (Pchar *)((*__1b)).p__11Block_Pchar,
                                      __0this->n__11Block_Pchar);

    } else
        __0this->n__11Block_Pchar = 0;
}

size_t grow__11Block_PcharFUl(register struct Block_Pchar *__0this, size_t __1k) {
    size_t __1nn;

    __1nn = __0this->n__11Block_Pchar;

    if (__1nn == 0)
        __1nn++;

    while (__1nn <= __1k)
        __1nn += ((__1nn >> 1) + 1);

    {
        Pchar *__1np;

        __1np = (((char **)__nw__FUl((size_t)((sizeof(char *)) * __1nn))));

        if (!__1np) {
            __1nn = (__1k + 1);

            __1np = (((char **)__nw__FUl((size_t)((sizeof(char *)) * __1nn))));
        }

        move__11Block_PcharFPPcUl(__0this, __1np, __1nn);

        return __0this->n__11Block_Pchar;
    }
}

void transfer__11Block_PcharFPPcUl(register struct Block_Pchar *__0this, Pchar *__1source,
                                   size_t __1len) {
    Pchar *__1plim;

    Pchar *__1pp;

    Pchar *__1q;

    __1pp = __0this->p__11Block_Pchar;

    __1q = __1source;

    if (__0this->n__11Block_Pchar > __1len) {
        __1plim = (__0this->p__11Block_Pchar + __1len);

        clear__11Block_PcharFPPcUl(__0this, __1plim, __0this->n__11Block_Pchar - __1len);

    } else
        __1plim = (__0this->p__11Block_Pchar + __0this->n__11Block_Pchar);

    while (__1pp < __1plim)
        ((*(__1pp++))) = ((*(__1q++)));
}

void move__11Block_PcharFPPcUl(register struct Block_Pchar *__0this, Pchar *__1np, size_t __1nn) {
    Pchar *__1oldp;

    size_t __1oldn;

    __1oldp = __0this->p__11Block_Pchar;

    __1oldn = __0this->n__11Block_Pchar;

    __0this->p__11Block_Pchar = __1np;

    if (__1np) {
        __0this->n__11Block_Pchar = __1nn;

        transfer__11Block_PcharFPPcUl(__0this, __1oldp, __1oldn);

    } else
        __0this->n__11Block_Pchar = 0;

    __dl__FPv((void *)__1oldp);
}

void swap__11Block_PcharFR11Block_Pchar(register struct Block_Pchar *__0this,
                                        struct Block_Pchar *__1b) {
    Pchar *__1bp;

    size_t __1bn;

    __1bp = ((*__1b)).p__11Block_Pchar;

    __1bn = ((*__1b)).n__11Block_Pchar;

    ((*__1b)).p__11Block_Pchar = __0this->p__11Block_Pchar;

    ((*__1b)).n__11Block_Pchar = __0this->n__11Block_Pchar;

    __0this->p__11Block_Pchar = __1bp;

    __0this->n__11Block_Pchar = __1bn;
}
static CPchar Block_CPchar_def;

void clear__12Block_CPcharFPPCcUl(struct Block_CPchar *__0this, CPchar *__1v, size_t __1k) {
    CPchar *__1p;

    CPchar *__1lim;

    __1p = __1v;

    __1lim = (__1v + __1k);

    while (__1p < __1lim)
        ((*(__1p++))) = Block_CPchar_def;
}

void transfer__12Block_CPcharFPPCcUl(struct Block_CPchar *__0this, CPchar *, size_t);

void copy__12Block_CPcharFRC12Block_CPchar(register struct Block_CPchar *__0this,
                                           const struct Block_CPchar *__1b) {
    __0this->p__12Block_CPchar = (((const char **)__nw__FUl(
        (unsigned long)((sizeof(const char *)) * ((*__1b)).n__12Block_CPchar))));

    if (__0this->p__12Block_CPchar) {
        __0this->n__12Block_CPchar = ((*__1b)).n__12Block_CPchar;

        transfer__12Block_CPcharFPPCcUl(__0this, (CPchar *)((*__1b)).p__12Block_CPchar,
                                        __0this->n__12Block_CPchar);

    } else
        __0this->n__12Block_CPchar = 0;
}

size_t grow__12Block_CPcharFUl(register struct Block_CPchar *__0this, size_t __1k) {
    size_t __1nn;

    __1nn = __0this->n__12Block_CPchar;

    if (__1nn == 0)
        __1nn++;

    while (__1nn <= __1k)
        __1nn += ((__1nn >> 1) + 1);

    {
        CPchar *__1np;

        __1np = (((const char **)__nw__FUl((size_t)((sizeof(const char *)) * __1nn))));

        if (!__1np) {
            __1nn = (__1k + 1);

            __1np = (((const char **)__nw__FUl((size_t)((sizeof(const char *)) * __1nn))));
        }

        move__12Block_CPcharFPPCcUl(__0this, __1np, __1nn);

        return __0this->n__12Block_CPchar;
    }
}

void transfer__12Block_CPcharFPPCcUl(register struct Block_CPchar *__0this, CPchar *__1source,
                                     size_t __1len) {
    CPchar *__1plim;

    CPchar *__1pp;

    CPchar *__1q;

    __1pp = __0this->p__12Block_CPchar;

    __1q = __1source;

    if (__0this->n__12Block_CPchar > __1len) {
        __1plim = (__0this->p__12Block_CPchar + __1len);

        clear__12Block_CPcharFPPCcUl(__0this, __1plim, __0this->n__12Block_CPchar - __1len);

    } else
        __1plim = (__0this->p__12Block_CPchar + __0this->n__12Block_CPchar);

    while (__1pp < __1plim)
        ((*(__1pp++))) = ((*(__1q++)));
}

void move__12Block_CPcharFPPCcUl(register struct Block_CPchar *__0this, CPchar *__1np,
                                 size_t __1nn) {
    CPchar *__1oldp;

    size_t __1oldn;

    __1oldp = __0this->p__12Block_CPchar;

    __1oldn = __0this->n__12Block_CPchar;

    __0this->p__12Block_CPchar = __1np;

    if (__1np) {
        __0this->n__12Block_CPchar = __1nn;

        transfer__12Block_CPcharFPPCcUl(__0this, __1oldp, __1oldn);

    } else
        __0this->n__12Block_CPchar = 0;

    __dl__FPv((void *)__1oldp);
}

void swap__12Block_CPcharFR12Block_CPchar(register struct Block_CPchar *__0this,
                                          struct Block_CPchar *__1b) {
    CPchar *__1bp;

    size_t __1bn;

    __1bp = ((*__1b)).p__12Block_CPchar;

    __1bn = ((*__1b)).n__12Block_CPchar;

    ((*__1b)).p__12Block_CPchar = __0this->p__12Block_CPchar;

    ((*__1b)).n__12Block_CPchar = __0this->n__12Block_CPchar;

    __0this->p__12Block_CPchar = __1bp;

    __0this->n__12Block_CPchar = __1bn;
}
static short Block_short_def;

void clear__11Block_shortFPsUl(struct Block_short *__0this, short *__1v, size_t __1k) {
    short *__1p;

    short *__1lim;

    __1p = __1v;

    __1lim = (__1v + __1k);

    while (__1p < __1lim)
        ((*(__1p++))) = Block_short_def;
}

void transfer__11Block_shortFPsUl(struct Block_short *__0this, short *, size_t);

void copy__11Block_shortFRC11Block_short(register struct Block_short *__0this,
                                         const struct Block_short *__1b) {
    __0this->p__11Block_short =
        (((short *)__nw__FUl((size_t)((sizeof(short)) * ((*__1b)).n__11Block_short))));

    if (__0this->p__11Block_short) {
        __0this->n__11Block_short = ((*__1b)).n__11Block_short;

        transfer__11Block_shortFPsUl(__0this, (short *)((*__1b)).p__11Block_short,
                                     __0this->n__11Block_short);

    } else
        __0this->n__11Block_short = 0;
}

size_t grow__11Block_shortFUl(register struct Block_short *__0this, size_t __1k) {
    size_t __1nn;

    __1nn = __0this->n__11Block_short;

    if (__1nn == 0)
        __1nn++;

    while (__1nn <= __1k)
        __1nn += ((__1nn >> 1) + 1);

    {
        short *__1np;

        __1np = (((short *)__nw__FUl((size_t)((sizeof(short)) * __1nn))));

        if (!__1np) {
            __1nn = (__1k + 1);

            __1np = (((short *)__nw__FUl((size_t)((sizeof(short)) * __1nn))));
        }

        move__11Block_shortFPsUl(__0this, __1np, __1nn);

        return __0this->n__11Block_short;
    }
}

void transfer__11Block_shortFPsUl(register struct Block_short *__0this, short *__1source,
                                  size_t __1len) {
    short *__1plim;

    short *__1pp;

    short *__1q;

    __1pp = __0this->p__11Block_short;

    __1q = __1source;

    if (__0this->n__11Block_short > __1len) {
        __1plim = (__0this->p__11Block_short + __1len);

        clear__11Block_shortFPsUl(__0this, __1plim, __0this->n__11Block_short - __1len);

    } else
        __1plim = (__0this->p__11Block_short + __0this->n__11Block_short);

    while (__1pp < __1plim)
        ((*(__1pp++))) = ((*(__1q++)));
}

void move__11Block_shortFPsUl(register struct Block_short *__0this, short *__1np, size_t __1nn) {
    short *__1oldp;

    size_t __1oldn;

    __1oldp = __0this->p__11Block_short;

    __1oldn = __0this->n__11Block_short;

    __0this->p__11Block_short = __1np;

    if (__1np) {
        __0this->n__11Block_short = __1nn;

        transfer__11Block_shortFPsUl(__0this, __1oldp, __1oldn);

    } else
        __0this->n__11Block_short = 0;

    __dl__FPv((void *)__1oldp);
}

void swap__11Block_shortFR11Block_short(register struct Block_short *__0this,
                                        struct Block_short *__1b) {
    short *__1bp;

    size_t __1bn;

    __1bp = ((*__1b)).p__11Block_short;

    __1bn = ((*__1b)).n__11Block_short;

    ((*__1b)).p__11Block_short = __0this->p__11Block_short;

    ((*__1b)).n__11Block_short = __0this->n__11Block_short;

    __0this->p__11Block_short = __1bp;

    __0this->n__11Block_short = __1bn;
}

void __sti___clear_(void) {
    struct Block_Pname *__0__X21;

    ((__0__X21 = (&Block_BlockPname_def)),
     (((__0__X21 ||
        (__0__X21 = (struct Block_Pname *)__nw__FUl((size_t)(sizeof(struct Block_Pname)))))
           ? ((__0__X21->n__11Block_Pname = 0), (__0__X21->p__11Block_Pname = 0))
           : 0),
      __0__X21));
}

void __std___clear_(void) {
    struct Block_Pname *__0__X22;

    ((__0__X22 = (&Block_BlockPname_def)),
     ((__0__X22 ? (((void)(__dl__FPv((void *)__0__X22->p__11Block_Pname),
                           (__0__X22 ? (((void)(((void)0)))) : (((void)0))))))
                : (((void)0)))));
}

static void __dt__11Block_PnameFv(struct Block_Pname *__0this, int __0__free) {
    if (__0this) {
        __dl__FPv((void *)__0this->p__11Block_Pname);

        if (__0this)
            if (__0__free & 1)
                __dl__FPv((void *)__0this);
    }
}

static struct Block_Pname *__ct__11Block_PnameFv(struct Block_Pname *__0this) {
    if (__0this ||
        (__0this = (struct Block_Pname *)__nw__FUl((size_t)(sizeof(struct Block_Pname))))) {
        __0this->n__11Block_Pname = 0;

        __0this->p__11Block_Pname = 0;
    }
    return __0this;
}

extern Pstmt stmt_free__4stmt;

extern Pname name_free__4name;

extern Pexpr expr_free__4expr;

extern Pptr ptr_free__3ptr;

extern Pvec vec_free__3vec;

extern Pfct fct_free__3fct;

extern Pktab table_free__6ktable;

extern Ptable table_free__5table;

/* the end */
