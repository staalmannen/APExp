
/* <<AT&T C++ Language System <3.0.3> 05/05/94>> */

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

extern int BI_IN_WORD;
extern int BI_IN_BYTE;

extern int SZ_CHAR;
extern int AL_CHAR;

extern int SZ_SHORT;
extern int AL_SHORT;

extern int SZ_INT;
extern int AL_INT;

extern int SZ_LONG;
extern int AL_LONG;

extern int SZ_LLONG;
extern int AL_LLONG;

extern int SZ_FLOAT;
extern int AL_FLOAT;

extern int SZ_DOUBLE;
extern int AL_DOUBLE;

extern int SZ_LDOUBLE;
extern int AL_LDOUBLE;

extern int SZ_STRUCT;
extern int AL_STRUCT;

extern int SZ_WORD;

extern int SZ_WPTR;
extern int AL_WPTR;

extern int SZ_BPTR;
extern int AL_BPTR;

extern const char *LARGEST_INT;

extern const char *LARGEST_LONG;

extern const char *LARGEST_LLONG;
extern int F_SENSITIVE;
extern int F_OPTIMIZED;

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
struct pointer_hash;
struct tree_copy_info;
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

extern void __dl__FPv(void *);

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

struct dcl_context ccvec[100];

struct dcl_context *cc = (struct dcl_context *)ccvec;
struct dcl_context *ccvec_end = (&(ccvec[100]));
int byte_offset = 0;
int bit_offset = 0;
int max_align = 0;
int friend_in_class = 0;
extern int no_const;
static Pstmt itail;

static bit check_static_pt__FP4name(Pname __1n) {
    if (!dtpt_opt)
        return (unsigned char)1;
    if (all_flag)
        return (unsigned char)1;
    if (none_flag)
        return (unsigned char)1;
    if ((__1n->n_stclass__4name == 2) || (__1n->n_stclass__4name == 27))
        return (unsigned char)1;
    if (__1n->n_sto__4name == 31)
        return (unsigned char)1;
    if (curloc.file__3loc != first_file)
        return (unsigned char)0;

    return (unsigned char)1;
}

static int is_empty__FP8classdefUc(Pclass __1cl, bit __1const_chk) {
    int __1mbr_cnt;

    struct table *__0__X29;

    __1mbr_cnt = ((__0__X29 = __1cl->memtbl__8classdef), ((__0__X29->free_slot__5table - 1)));

    if (__1mbr_cnt == 0)
        return 1;
    if ((__1cl->baselist__8classdef == 0) && (__1cl->real_size__8classdef != 1))
        return 0;

    if ((__1const_chk == 0) && ((__1cl->baselist__8classdef != 0) || (__1mbr_cnt > 1)))
        return 0;

    {
        int __1i;

        __1i = 1;
        {
            {
                Pname __1nn;

                struct table *__0__X26;

                int __2__X27;

                struct table *__0__X28;

                __1nn = ((__0__X28 = __1cl->memtbl__8classdef),
                         ((((__1i <= 0) || (__0__X28->free_slot__5table <= __1i))
                               ? (((struct name *)0))
                               : (__0__X28->entries__5table[__1i]))));

                for (; __1nn;
                     __1nn =
                         (__1nn->n_tbl_list__4name
                              ? __1nn->n_tbl_list__4name
                              : ((__0__X26 = __1cl->memtbl__8classdef),
                                 ((__2__X27 = (++__1i)),
                                  ((((__2__X27 <= 0) || (__0__X26->free_slot__5table <= __2__X27))
                                        ? (((struct name *)0))
                                        : (__0__X26->entries__5table[__2__X27]))))))) {
                    if ((((((((__1nn->base__4node == 85) && (__1nn->n_anon__4name == 0)) &&
                             (__1nn->__O1__4expr.tp->base__4node != 108)) &&
                            (__1nn->__O1__4expr.tp->base__4node != 76)) &&
                           (__1nn->__O1__4expr.tp->base__4node != 6)) &&
                          (__1nn->__O1__4expr.tp->base__4node != 13)) &&
                         (__1nn->__O1__4expr.tp->base__4node != 121)) &&
                        (__1nn->n_stclass__4name != 31)) {
                        if ((((__1nn->__O2__4expr.string[0]) == '_') &&
                             ((__1nn->__O2__4expr.string[1]) == '_')) &&
                            ((__1nn->__O2__4expr.string[2]) == 'W'))
                            return 1;
                        else
                            return 0;
                    }
                }

                return 1;
            }
        }
    }
}

extern void make_dummy__Fv(void);

void simpl__4exprFv(struct expr *__0this);

void dosimpl__FP4exprP4name(Pexpr __1e, Pname __1n) {
    if (__1n == 0) {
        if (dummy_fct == 0)
            make_dummy__Fv();
        __1n = dummy_fct;
    }
    {
        Pname __1cf;

        __1cf = curr_fct;
        curr_fct = __1n;
        simpl__4exprFv(__1e);
        curr_fct = __1cf;
    }
}

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

Pname is_cl_obj__4typeFv(struct type *__0this);

Pexpr typ__4exprFP5table(struct expr *__0this, Ptable);

Pname has_ictor__8classdefFv(struct classdef *__0this);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

static Pexpr co_array_init__FP4nameP5table(Pname __1n, Ptable __1tbl) {
    Pexpr __1init;

    __1init = __1n->__O3__4expr.n_initializer;

    if (__1init->base__4node != 124) {
        {
            struct ea __0__V30;

            error__FPCcRC2eaN32(
                (const char *)"badIr for array ofCOs%n",
                (const struct ea *)(((&__0__V30)->__O1__2ea.p = ((const void *)__1n)), (&__0__V30)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            return (struct expr *)0;
        }
    }

    {
        Pexpr __1el;
        Pvec __1v;
        Pname __1cn;
        Pclass __1cl;
        int __1i;

        int __1count;
        Pexpr __1il2;

        __1el = 0;
        __1v = (((struct vec *)(((struct vec *)skiptypedefs__4typeFv(__1n->__O1__4expr.tp)))));
        __1cn = is_cl_obj__4typeFv(__1v->typ__5pvtyp);
        __1cl = (__1cn ? (((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))))
                       : (((struct classdef *)0)));
        __1i = __1v->size__3vec;

        __1count = 0;

        {
            {
                Pexpr __1il;

                __1il = __1init->__O2__4expr.e1;

                for (; __1il; __1il = __1il2) {
                    Pexpr __2e;

                    struct texpr *__0__X42;

                    struct ival *__0__X43;

                    long long __2__X44;

                    __2e = __1il->__O2__4expr.e1;
                    __1il2 = __1il->__O3__4expr.e2;
                    __1il->__O3__4expr.e2 = 0;
                    if (__2e == dummy)
                        break;
                    if (__2e->base__4node == 157) {
                        switch (__2e->__O4__4expr.tp2->base__4node) {
                            struct classdef *__1__X36;

                            struct classdef *__1__X37;

                            struct texpr *__0__X38;

                        case 6:
                            if (!((__1__X36 = (((struct classdef *)((
                                       (struct classdef *)__2e->__O4__4expr.tp2))))),
                                  ((__1__X37 = __1cl),
                                   (((__1__X36 == __1__X37)
                                         ? 1
                                         : ((__1__X36 && __1__X37)
                                                ? (((int)same_class__8classdefFP8classdefi(
                                                      __1__X36, __1__X37, 0)))
                                                : 0))))))
                                __2e =
                                    (struct expr *)((__0__X38 = 0),
                                                    (((__0__X38 ||
                                                       (__0__X38 = (struct texpr *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct texpr)))))
                                                          ? ((__0__X38 = (struct texpr *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X38),
                                                                      ((unsigned char)157), __1il,
                                                                      (struct expr *)0)),
                                                             (__0__X38->__O4__4expr.tp2 =
                                                                  ((struct type *)__1cl)))
                                                          : 0),
                                                     __0__X38));
                            break;
                        default: {
                            Pname __5n2;

                            struct classdef *__1__X39;

                            struct classdef *__1__X40;

                            struct texpr *__0__X41;

                            __5n2 = is_cl_obj__4typeFv(__2e->__O4__4expr.tp2);
                            if ((__5n2 == 0) ||
                                (!((__1__X39 = (((struct classdef *)((
                                        (struct classdef *)__5n2->__O1__4expr.tp))))),
                                   ((__1__X40 = __1cl),
                                    (((__1__X39 == __1__X40)
                                          ? 1
                                          : ((__1__X39 && __1__X40)
                                                 ? (((int)same_class__8classdefFP8classdefi(
                                                       __1__X39, __1__X40, 0)))
                                                 : 0)))))))
                                __2e =
                                    (struct expr *)((__0__X41 = 0),
                                                    (((__0__X41 ||
                                                       (__0__X41 = (struct texpr *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct texpr)))))
                                                          ? ((__0__X41 = (struct texpr *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X41),
                                                                      ((unsigned char)157), __1il,
                                                                      (struct expr *)0)),
                                                             (__0__X41->__O4__4expr.tp2 =
                                                                  ((struct type *)__1cl)))
                                                          : 0),
                                                     __0__X41));
                        }
                        }
                    } else
                        __2e =
                            (struct expr
                                 *)((__0__X42 = 0),
                                    (((__0__X42 || (__0__X42 = (struct texpr *)__nw__4exprSFUl(
                                                        (size_t)(sizeof(struct texpr)))))
                                          ? ((__0__X42 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X42), ((unsigned char)157),
                                                  __1il, (struct expr *)0)),
                                             (__0__X42->__O4__4expr.tp2 = ((struct type *)__1cl)))
                                          : 0),
                                     __0__X42));
                    __2e->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                        (struct expr *)0, (unsigned char)111, (struct expr *)__1n,
                        (struct expr *)((__0__X43 = 0),
                                        ((__2__X44 = (__1count++)),
                                         (((__0__X43 || (__0__X43 = (struct ival *)__nw__4exprSFUl(
                                                             (size_t)(sizeof(struct ival)))))
                                               ? ((__0__X43 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                       ((struct expr *)__0__X43),
                                                       (unsigned char)150, (struct expr *)0,
                                                       (struct expr *)0)),
                                                  (__0__X43->__O2__4expr.i1 = __2__X44))
                                               : 0),
                                          __0__X43))));
                    __2e = typ__4exprFP5table(__2e, __1tbl);
                    {
                        Ptable __2oscope;

                        __2oscope = scope;
                        scope = __1tbl;
                        dosimpl__FP4exprP4name(__2e, cc->nof__11dcl_context);
                        scope = __2oscope;
                        if (sti_tbl == __1tbl) {
                            Pstmt __3ist;

                            struct estmt *__0__X45;

                            struct loc __2__X46;

                            __3ist =
                                (struct stmt *)((__0__X45 = 0),
                                                ((__2__X46 = no_where),
                                                 (((__0__X45 ||
                                                    (__0__X45 = (struct estmt *)__nw__4stmtSFUl(
                                                         (unsigned long)(sizeof(struct estmt)))))
                                                       ? ((__0__X45 = (struct estmt *)
                                                               __ct__4stmtFUc3locP4stmt(
                                                                   ((struct stmt *)__0__X45),
                                                                   ((unsigned char)72), __2__X46,
                                                                   ((struct stmt *)0))),
                                                          (__0__X45->__O2__4stmt.e = __2e))
                                                       : 0),
                                                  __0__X45)));
                            if (st_ilist == 0)
                                st_ilist = __3ist;
                            else
                                itail->s_list__4stmt = __3ist;
                            itail = __3ist;
                        } else {
                            __1el = (__1el ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                    (unsigned char)147, __1el, __2e)
                                           : __2e);
                        }
                    }
                }

                if (__1i == 0)
                    __1v->size__3vec = __1count;
                else if (__1i < __1count) {
                    {
                        struct ea __0__V31;

                        struct ea __0__V32;

                        error__FPCcRC2eaN32(
                            (const char *)"too manyIrs for%n (%d)",
                            (const struct ea *)(((&__0__V31)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V31)),
                            (const struct ea *)(((((&__0__V32)->__O1__2ea.i =
                                                       ((unsigned long)__1count)),
                                                  0)),
                                                (&__0__V32)),
                            (const struct ea *)ea0, (const struct ea *)ea0);

                        return (struct expr *)0;
                    }
                } else if (__1i > __1count) {
                    if (has_ictor__8classdefFv(__1cl)) {
                        struct ea __0__V33;

                        error__FiPCcRC2eaN33(
                            (int)'s', (const char *)"too fewIrs for%n",
                            (const struct ea *)(((&__0__V33)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V33)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else {
                        struct ea __0__V34;

                        struct ea __0__V35;

                        error__FPCcRC2eaN32(
                            (const char *)"too fewIrs for%n (C %srequires a defaultK)",
                            (const struct ea *)(((&__0__V34)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V34)),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V35, (const void *)__1cl->string__8classdef),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    return (struct expr *)0;
                }
                return __1el;
            }
        }
    }
}

int need_sti__FP4exprP5tableUc(Pexpr __1e, Ptable __1tbl, bit __1accept_name);

bit tconst__4typeFv(struct type *__0this);

long long eval__4exprFv(struct expr *__0this);

extern size_t strlen(const char *);

extern char *strcpy(char *, const char *);

int need_sti__FP4exprP5tableUc(Pexpr __1e, Ptable __1tbl, bit __1accept_name) {
    if (__1e == 0)
        return 0;

    switch (__1e->base__4node) {
    case 68:
        if (need_sti__FP4exprP5tableUc(__1e->__O4__4expr.cond, __1tbl, (unsigned char)0) &&
            (__1tbl == 0))
            return 1;
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
    case 48:
    case 49:
    case 70:
        if (need_sti__FP4exprP5tableUc(__1e->__O2__4expr.e1, __1tbl, __1accept_name) &&
            (__1tbl == 0))
            return 1;

    case 107:
    case 172:
    case 46:
    case 47:
        if (need_sti__FP4exprP5tableUc(__1e->__O3__4expr.e2, __1tbl, __1accept_name) &&
            (__1tbl == 0))
            return 1;

    case 30:
    default:
        return 0;

    case 113:
    case 191:
        return need_sti__FP4exprP5tableUc(__1e->__O2__4expr.e1, __1tbl, __1accept_name);

    case 112:
        return need_sti__FP4exprP5tableUc(__1e->__O3__4expr.e2, __1tbl, (unsigned char)1);

    case 85:
        if (__1accept_name && ((((struct name *)(((struct name *)__1e))))->n_stclass__4name == 31))
            return 0;

        if (tconst__4typeFv(__1e->__O1__4expr.tp)) {
            if (vec_const || fct_const)
                return 0;
            Neval = 0;
            eval__4exprFv(__1e);
            if (Neval == 0)
                return 0;
        }
        return 1;

    case 111:
    case 44:
    case 45:
        if (__1accept_name ||
            (__1e->__O1__4expr.tp && (__1e->__O1__4expr.tp->base__4node == 110))) {
            int __3x1;
            int __3x2;

            __3x1 = need_sti__FP4exprP5tableUc(__1e->__O2__4expr.e1, __1tbl,
                                               (unsigned char)(__1e->base__4node == 45));
            __3x2 = need_sti__FP4exprP5tableUc(__1e->__O3__4expr.e2, __1tbl, (unsigned char)0);
            return (__3x1 || __3x2);
        }

    case 140:
    case 147:
    case 71:
        if (__1e->base__4node == 71) {
            if (need_sti__FP4exprP5tableUc(__1e->__O2__4expr.e1, __1tbl, (unsigned char)0) ||
                need_sti__FP4exprP5tableUc(__1e->__O3__4expr.e2, __1tbl, (unsigned char)0))
                return 1;
            else
                return 0;
        }

    case 109:
    case 146:
    case 23:
    case 184:
    case 0:
        if (__1tbl) {
            need_sti__FP4exprP5tableUc(__1e->__O2__4expr.e1, __1tbl, __1accept_name);
            need_sti__FP4exprP5tableUc(__1e->__O3__4expr.e2, __1tbl, __1accept_name);
            if (((__1e->__O1__4expr.tp && (__1e->__O1__4expr.tp->base__4node == 110)) &&
                 (__1e->base__4node == 23)) ||
                (__1e->base__4node == 184))
                need_sti__FP4exprP5tableUc(
                    (((struct vec *)(((struct vec *)__1e->__O1__4expr.tp))))->dim__3vec, __1tbl,
                    (unsigned char)0);
        } else if (__1e->base__4node == 0)
            return 0;

    case 168:
        return 1;
    case 82:
    case 81:
    case 84:
    case 83:
        if (__1tbl) {
            char *__3p;

            __3p = (((char *)__nw__FUl(
                (size_t)((sizeof(char)) * (strlen(__1e->__O2__4expr.string) + 1)))));

            strcpy(__3p, __1e->__O2__4expr.string);
            __1e->__O2__4expr.string = (const char *)__3p;
        }
        return 0;
    }
}

extern int strcmp(const char *, const char *);

static void check_def_name__FP4namei(Pname __1nn, int __1scope) {
    Pfct __1f;

    __1f = (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))));
    if (((((((((def_name == 0) && (pdef_name == 0)) && (friend_in_class == 0)) &&
             (__1scope == 14)) &&
            (__1nn->n_scope__4name != 31)) &&
           (__1nn->n_oper__4name != 23)) &&
          (__1nn->n_oper__4name != 213)) &&
         (__1nn->n_oper__4name != 9)) &&
        (__1nn->n_oper__4name != 212)) {
        if ((__1f->body__3fct && (__1f->f_inline__3fct == 0)) && (__1f->f_imeasure__3fct == 0)) {
            pdef_name = (def_name = __1nn);
            def_name = 0;
        }
    }

    if (((strcmp(__1nn->__O2__4expr.string, (const char *)"main") == 0) &&
         (__1nn->__O4__4expr.n_table == gtbl)) &&
        __1f->f_inline__3fct) {
        pdef_name = (def_name = __1nn);
        def_name = 0;
    }
}

extern int error__FPCc(const char *);

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

static void export_anon__FP4nameP8classdefP5table(Pname __1un, Pclass __1cl, Ptable __1tbl) {
    if (__1tbl == gtbl) {
        if (__1un->n_sto__4name != 31)
            error__FPCc((const char *)"extern anonymous union (declare as static)");
    } else if (__1tbl->t_name__5table && (__1un->n_sto__4name == 31))
        error__FiPCc((int)'s', (const char *)"staticM anonymous union");

    (((struct basetype *)(((struct basetype *)__1un->__O1__4expr.tp))))
        ->b_name__8basetype->n_used__4name = 1;
    (((struct basetype *)(((struct basetype *)__1un->__O1__4expr.tp))))
        ->b_name__8basetype->n_assigned_to__4name = 1;
    {
        Ptable __1mtbl;
        Ptable __1realtbl;
        int __1i;

        __1mtbl = __1cl->memtbl__8classdef;
        __1realtbl =
            (((__1tbl == gtbl) || __1tbl->t_name__5table) ? __1tbl : curr_block->memtbl__4stmt);

        {
            {
                Pname __1nn;

                int __2__X50;

                int __2__X53;

                __1nn = ((__2__X53 = (__1i = 1)),
                         ((((__2__X53 <= 0) || (__1mtbl->free_slot__5table <= __2__X53))
                               ? (((struct name *)0))
                               : (__1mtbl->entries__5table[__2__X53]))));

                for (; __1nn;
                     __1nn = (__1nn->n_tbl_list__4name
                                  ? __1nn->n_tbl_list__4name
                                  : ((__2__X50 = (++__1i)),
                                     ((((__2__X50 <= 0) || (__1mtbl->free_slot__5table <= __2__X50))
                                           ? (((struct name *)0))
                                           : (__1mtbl->entries__5table[__2__X50])))))) {
                    if ((__1nn->base__4node == 85) && (__1nn->__O1__4expr.tp->base__4node == 108)) {
                        {
                            struct ea __0__V47;

                            error__FP3locPCcRC2eaN33(
                                &__1nn->where__4name, (const char *)"FM%n for anonymous union",
                                (const struct ea *)(((&__0__V47)->__O1__2ea.p =
                                                         ((const void *)__1nn)),
                                                    (&__0__V47)),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                            continue;
                        }
                    }
                    {
                        Ptable __2tb;

                        __2tb = __1nn->__O4__4expr.n_table;
                        __1nn->__O4__4expr.n_table = 0;
                        __1nn->n_tbl_list__4name = 0;
                        __1nn->n_scope__4name = (__1un->n_protect__4name ? __1un->n_protect__4name
                                                                         : __1un->n_scope__4name);
                        if (__1nn->n_key__4name == 159)
                            continue;
                        if ((((__1nn->n_key__4name == 6) &&
                              ((__1nn->__O2__4expr.string[0]) == '_')) &&
                             ((__1nn->__O2__4expr.string[1]) == '_')) &&
                            ((__1nn->__O2__4expr.string[2]) == 'C'))
                            continue;

                        {
                            Pname __2n;

                            __2n = look__5tableFPCcUc(__1realtbl, __1nn->__O2__4expr.string,
                                                      (unsigned char)0);

                            if (__2n && (__2n->__O4__4expr.n_table != __1tbl)) {
                                if ((__1tbl == gtbl) || __1tbl->t_name__5table)
                                    error__FiP3locPCcRC2eaN34(
                                        (int)'i', &__1nn->where__4name,
                                        (const char *)"table mismatch", (const struct ea *)ea0,
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                if ((__2n->__O4__4expr.n_table->real_block__5table !=
                                     __1realtbl->real_block__5table) ||
                                    (__2n->lex_level__4name != __1nn->lex_level__4name))
                                    __2n = 0;
                            }
                            if (__2n == 0) {
                            adef:
                                __2n = insert__5tableFP4nameUc(__1tbl, __1nn, __1nn->n_key__4name);
                                if ((__1nn->n_key__4name == 6) && Nold) {
                                    continue;
                                }
                            } else {
                                const void *__2__X52;

                                if (__1nn->n_key__4name == 6) {
                                    if (__2n->base__4node == 123) {
                                        const void *__2__X51;

                                        {
                                            struct ea __0__V48;

                                            error__FP3locPCcRC2eaN33(
                                                &__1nn->where__4name,
                                                (const char
                                                     *)"twoDs ofTN %s (one in anonymous union)",
                                                (const struct ea *)((__2__X51 =
                                                                         (const void *)__2n
                                                                             ->__O2__4expr.string),
                                                                    (((&__0__V48)->__O1__2ea.p =
                                                                          __2__X51),
                                                                     (&__0__V48))),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                                            continue;
                                        }
                                    }
                                    goto adef;
                                }
                                if (((__2n->base__4node != __1nn->base__4node) ||
                                     (__1nn->base__4node == 85)) ||
                                    check__4typeFP4typeUcT2(__2n->__O1__4expr.tp,
                                                            __1nn->__O1__4expr.tp, (unsigned char)0,
                                                            (unsigned char)0)) {
                                    struct ea __0__V49;

                                    error__FP3locPCcRC2eaN33(
                                        &__1nn->where__4name,
                                        (const char *)"twoDs of %s (one in anonymous union)",
                                        (const struct ea *)((__2__X52 = (const void *)__2n
                                                                            ->__O2__4expr.string),
                                                            (((&__0__V49)->__O1__2ea.p = __2__X52),
                                                             (&__0__V49))),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                                continue;
                            }

                            __2n->n_anon__4name = __1un->__O2__4expr.string;
                            __1nn->__O4__4expr.n_table = __2tb;
                            if (((__1cl->in_class__4type && (__1un->n_sto__4name == 31)) &&
                                 (__1nn->base__4node != 123)) &&
                                (__1nn->n_key__4name != 6))
                                __2n->n_stclass__4name = 31;
                        }
                    }
                }
            }
        }
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

Pname find_cn__6ktableFPCc(struct ktable *__0this, const char *);

extern Pexpr call_ctor__FP5tableP4exprN22iT2(Ptable, Pexpr __0p, Pexpr __0ctor, Pexpr __0args,
                                             int __0d, Pexpr __0vb_args);

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

Pname dcl__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

void simpl__4nameFv(struct name *__0this);

void dcl_print__4nameFUc(struct name *__0this, TOK);

void make_vec_ctor__8classdefFP4name(register struct classdef *__0this, Pname __1default_ctor) {
    Pname __1tn;

    __1tn = (((struct fct *)(((struct fct *)__1default_ctor->__O1__4expr.tp))))->f_this__3fct;
    if (__1tn->base__4node == 169) {
        __1tn = __ct__4nameFPCc((struct name *)0, (const char *)0);
        ((*__1tn)) =
            (*(((struct fct *)(((struct fct *)__1default_ctor->__O1__4expr.tp))))->f_this__3fct);
        __1tn->base__4node = 85;
    }

    {
        Pname __1cn;

        struct dcl_context *__0__X54;

        __1cn = find_cn__6ktableFPCc(__0this->k_tbl__8classdef, __0this->string__8classdef);
        if (__1cn)
            __1cn = (((struct basetype *)(((struct basetype *)__1cn->__O1__4expr.tp))))
                        ->b_name__8basetype;
        ((((cc++),
           (((cc >= ccvec_end) ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow") : 0),
            (((*cc)) = (*(cc - 1))))),
          (((void)0))));
        cc->not4__11dcl_context = __1cn;
        cc->cot__11dcl_context = __0this;
        cc->c_this__11dcl_context = __1tn;

        {
            Pexpr __1th;
            Pstmt __1s;
            Pexpr __1e;

            struct estmt *__0__X59;

            struct loc __2__X60;

            __1th = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)34, (struct expr *)0,
                                           (struct expr *)0);
            __1s = (struct stmt *)((__0__X59 = 0),
                                   ((__2__X60 = no_where),
                                    (((__0__X59 || (__0__X59 = (struct estmt *)__nw__4stmtSFUl(
                                                        (unsigned long)(sizeof(struct estmt)))))
                                          ? ((__0__X59 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                  ((struct stmt *)__0__X59), ((unsigned char)72),
                                                  __2__X60, ((struct stmt *)0))),
                                             (__0__X59->__O2__4stmt.e = ((struct expr *)0)))
                                          : 0),
                                     __0__X59)));
            __1e = call_ctor__FP5tableP4exprN22iT2(__0this->memtbl__8classdef, __1th,
                                                   (struct expr *)__1default_ctor, (struct expr *)0,
                                                   44, (struct expr *)0);
            __1s->__O2__4stmt.e = __1e;

            {
                Pname __1fn;
                Pfct __1f;

                register struct block *__0__X55;

                struct loc __2__X56;

                struct loc __2__X57;

                __1fn = __ct__4nameFPCc((struct name *)0, __0this->string__8classdef);
                __1f = __ct__3fctFP4typeP4nameUc((struct fct *)0, (struct type *)void_type,
                                                 (struct name *)0, (unsigned char)1);
                __1fn->__O1__4expr.tp = (struct type *)__1f;
                __1f->body__3fct =
                    ((__0__X55 = 0),
                     ((__2__X56 = curloc),
                      ((__2__X57 = noloc),
                       (((__0__X55 || (__0__X55 = (struct block *)__nw__4stmtSFUl(
                                           (size_t)(sizeof(struct block)))))
                             ? (((void)((__0__X55 = (struct block *)__ct__4stmtFUc3locP4stmt(
                                             ((struct stmt *)__0__X55), (unsigned char)116,
                                             __2__X56, __1s)),
                                        ((__0__X55->__O1__4stmt.d = ((struct name *)0)),
                                         (__0__X55->__O3__4stmt.where2 = __2__X57)))))
                             : (((void)0))),
                        __0__X55))));
                {
                    Pname __1nn;

                    struct dcl_context *__0__X58;

                    __1nn =
                        dcl__4nameFP5tableUc(__1fn, __0this->memtbl__8classdef, (unsigned char)25);
                    __1nn->n_sto__4name = 31;
                    (((cc--), (((void)0))));

                    simpl__4nameFv(__1nn);
                    dcl_print__4nameFUc(__1nn, (unsigned char)0);
                    __0this->c_vtor__8classdef = __1nn;
                    ((__1fn ? (((void)(__1fn ? (((void)((((((struct expr *)__1fn))
                                                              ? (((void)((((struct expr *)__1fn))
                                                                             ? (((void)(((void)0))))
                                                                             : (((void)0)))))
                                                              : (((void)0)))),
                                                        (((void)__dl__4nameSFPvUl(
                                                            (void *)__1fn,
                                                            (size_t)(sizeof(struct name))))))))
                                             : (((void)0)))))
                            : (((void)0))));
                }
            }
        }
    }
}

int stat_init = 0;

void dcl__4typeFP5table(struct type *__0this, Ptable);

extern char *make_nested_name__FPCcP8classdef(const char *, Pclass);

extern void typedef_check__FP4name(Pname);

void check_oper__4nameFP4name(struct name *__0this, Pname);

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

Pname find__3genFP3fctUc(struct gen *__0this, Pfct, bit);

struct name_list *__ct__9name_listFP4nameP9name_list(struct name_list *__0this, Pname __1ff,
                                                     Plist __1ll);

void assign__4nameFv(struct name *__0this);

extern Pname dclass__FP4nameP5table(Pname, Ptable);
extern Pname denum__FP4nameP5table(Pname, Ptable);

Pname dofct__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

void field_align__4nameFv(struct name *__0this);

struct velem { /* sizeof velem == 16 */
    Pname n__5velem;
    int offset__5velem;
};

int tsizeof__4typeFi(struct type *__0this, int);

bit is_const_object__4typeFv(struct type *__0this);

int align__4typeFv(struct type *__0this);

extern void check_visibility__FP4nameT1P8classdefP5tableT1(Pname, Pname, Pclass, Ptable, Pname);

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

extern Pexpr cdvec__FP4nameP4exprP8classdefT1iN22(Pname, Pexpr, Pclass, Pname, int, Pexpr, Pexpr);

extern Pexpr call_dtor__FP4exprN21iT1(Pexpr __0p, Pexpr __0dtor, Pexpr __0arg, int __0d,
                                      Pexpr __0vb_args);

Pexpr contents__4exprFv(struct expr *__0this);

Pexpr address__4exprFv(struct expr *__0this);

extern Pexpr replace_temp__FP4exprT1(Pexpr, Pexpr);

extern Pexpr class_init__FP4exprP4typeT1P5table(Pexpr, Ptype, Pexpr, Ptable);

Ptype skiptypedefs__4typeFRUc(struct type *__0this, bit *__1isconst);

extern Pexpr ref_init__FP3ptrP4exprP5table(Pptr, Pexpr, Ptable);

extern void new_list__FP4expr(Pexpr);
extern void list_check__FP4nameP4typeP4exprP5table(Pname, Ptype, Pexpr, Ptable);

extern Pexpr next_elem__Fv(void);

extern Pexpr ptr_init__FP3ptrP4exprP5table(Pptr, Pexpr, Ptable);

extern Pexpr try_to_coerce__FP4typeP4exprPCcP5table(Ptype, Pexpr, const char *, Ptable);

bit has_base__8classdefFP8classdefiT2(struct classdef *__0this, Pclass __1cl, int __1level,
                                      int __1ccflag);

Pptr is_ref__4typeFv(struct type *__0this);

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);

TOK set_const__4typeFUc(struct type *__0this, bit);

bit dinst_body__4nameFv(struct name *__0this);

static struct ea *__ct__2eaFUl(struct ea *__0this, size_t __2ii);

Pname dcl__4nameFP5tableUc(register struct name *__0this, Ptable __1tbl, TOK __1scope) {
    Pname __1nn;
    Pname __1odcl;
    int __1sti_vb;

    __1odcl = Cdcl;
    __1sti_vb = 0;

    Cdcl = __0this;
    {
        Ptype __1tx;

        unsigned long __2__X156;

        __1tx = skiptypedefs__4typeFv(__0this->__O1__4expr.tp);

        switch (__0this->base__4node) {
        case 123:;
            {
                __1nn = look__5tableFPCcUc(__1tbl, __0this->__O2__4expr.string, (unsigned char)0);
                dcl__4typeFP5table(__0this->__O1__4expr.tp, __1tbl);

                if (__0this->__O3__4expr.tpdef) {
                    Ptype __4tx;

                    __4tx = __0this->__O3__4expr.tpdef;
                    if (__4tx->in_class__4type &&
                        ((__4tx->templ_base__4type == 3) || (__4tx->templ_base__4type == 2))) {
                        __dl__FPv((void *)__4tx->nested_sig__4type);

                        __4tx->nested_sig__4type = make_nested_name__FPCcP8classdef(
                            __0this->__O2__4expr.string, __4tx->in_class__4type);
                    }
                }

                if (__1nn) {
                    Cdcl = __1odcl;
                    return (struct name *)0;
                }

                __0this->__O1__4expr.tp->permanent__4node = 1;
                __1nn = __ct__4nameFPCc((struct name *)0, __0this->__O2__4expr.string);
                __1nn->base__4node = 123;
                __1nn->where__4name = __0this->where__4name;
                __1nn->__O1__4expr.tp = __0this->__O1__4expr.tp;
                __1nn->lex_level__4name = __0this->lex_level__4name;
                __1nn->__O3__4expr.tpdef = __0this->__O3__4expr.tpdef;

                {
                    Pname __3tn;

                    __3tn = insert__5tableFP4nameUc(__1tbl, __1nn, (unsigned char)0);
                    __3tn->permanent__4node = 1;
                    ;
                    typedef_check__FP4name(__3tn);
                    ((__1nn ? (((void)(__1nn ? (((void)((((((struct expr *)__1nn))
                                                              ? (((void)((((struct expr *)__1nn))
                                                                             ? (((void)(((void)0))))
                                                                             : (((void)0)))))
                                                              : (((void)0)))),
                                                        (((void)__dl__4nameSFPvUl(
                                                            (void *)__1nn,
                                                            (size_t)(sizeof(struct name))))))))
                                             : (((void)0)))))
                            : (((void)0))));
                    Cdcl = __1odcl;
                    return __0this;
                }
            }

        case 98:
            __0this->base__4node = 85;
            __1scope = 136;

        case 85:;
            switch (__0this->n_oper__4name) {
            case 47:
                if (__0this->__O1__4expr.tp->base__4node != 108) {
                    const void *__2__X150;

                    {
                        struct ea __0__V61;

                        error__FPCcRC2eaN32(
                            (const char *)"~%s notF",
                            (const struct ea *)((__2__X150 =
                                                     (const void *)__0this->__O2__4expr.string),
                                                (((&__0__V61)->__O1__2ea.p = __2__X150),
                                                 (&__0__V61))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        __0this->n_oper__4name = 0;
                    }
                }
                break;
            case 123:
                if (__0this->__O1__4expr.tp->base__4node != 108)
                    __0this->n_oper__4name = 0;
                break;
            }
            break;
        default:
            error__FiPCc((int)'i', (const char *)"NX inN::dcl()");
            break;
        }

        if (__0this->__O2__4name.n_qualifier) {
            Pname __2cn;

            __2cn = __0this->__O2__4name.n_qualifier;
            switch (__2cn->base__4node) {
                const void *__2__X151;

            case 123:
                break;
            case 85:
                __2cn = look__5tableFPCcUc(gtbl, __2cn->__O2__4expr.string, (unsigned char)0);
                if (__2cn && (__2cn->base__4node == 123))
                    break;
            default: {
                struct ea __0__V62;

                struct ea __0__V63;

                error__FPCcRC2eaN32(
                    (const char *)"badQr%n for%n",
                    (const struct ea *)((__2__X151 =
                                             (const void *)__0this->__O2__4name.n_qualifier),
                                        (((&__0__V62)->__O1__2ea.p = __2__X151), (&__0__V62))),
                    (const struct ea *)(((&__0__V63)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V63)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                Cdcl = __1odcl;
                return (struct name *)0;
            }
            }

            __2cn->__O1__4expr.tp = skiptypedefs__4typeFv(__2cn->__O1__4expr.tp);
            if (__2cn->__O1__4expr.tp->base__4node != 119) {
                const void *__2__X152;

                {
                    struct ea __0__V64;

                    error__FP3locPCcRC2eaN33(
                        &__0this->where__4name, (const char *)"Qr%n not aCN",
                        (const struct ea *)((__2__X152 =
                                                 (const void *)__0this->__O2__4name.n_qualifier),
                                            (((&__0__V64)->__O1__2ea.p = __2__X152), (&__0__V64))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    Cdcl = __1odcl;
                    return (struct name *)0;
                }
            }

            __2cn = (((struct basetype *)(((struct basetype *)__2cn->__O1__4expr.tp))))
                        ->b_name__8basetype;
            if (__0this->n_oper__4name)
                check_oper__4nameFP4name(__0this, __2cn);

            {
                Pclass __2cl;

                struct classdef *__1__X153;

                struct classdef *__1__X154;

                __2cl = (((struct classdef *)(((struct classdef *)__2cn->__O1__4expr.tp))));
                if (((__1__X153 = __2cl),
                     ((__1__X154 = cc->cot__11dcl_context),
                      (((__1__X153 == __1__X154)
                            ? 1
                            : ((__1__X153 && __1__X154) ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X153, __1__X154, 0)))
                                                        : 0)))))) {
                    __0this->__O2__4name.n_qualifier = 0;
                    goto xdr;
                } else if ((__2cl->defined__4type & 3) == 0) {
                    {
                        struct ea __0__V65;

                        error__FPCcRC2eaN32(
                            (const char *)"C%nU",
                            (const struct ea *)(((&__0__V65)->__O1__2ea.p = ((const void *)__2cn)),
                                                (&__0__V65)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        Cdcl = __1odcl;
                        return (struct name *)0;
                    }
                } else if (__2cl->c_body__8classdef == 1)
                    dcl_print__8classdefFP4name(__2cl, (struct name *)0);

                {
                    Ptable __2etbl;
                    Pname __2x;

                    __2etbl = __2cl->memtbl__8classdef;
                    __2x =
                        look__5tableFPCcUc(__2etbl, __0this->__O2__4expr.string, (unsigned char)0);
                    if ((__2x == 0) || (__2x->__O4__4expr.n_table != __2etbl)) {
                        Ptable __3tt;

                        __3tt = __0this->__O4__4expr.n_table;
                        __0this->__O4__4expr.n_table = __2etbl;
                        {
                            struct ea __0__V66;

                            struct ea __0__V67;

                            error__FPCcRC2eaN32((const char *)"%n is not aM of%n",
                                                (const struct ea *)(((&__0__V66)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V66)),
                                                (const struct ea *)(((&__0__V67)->__O1__2ea.p =
                                                                         ((const void *)__2cn)),
                                                                    (&__0__V67)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                            __0this->__O4__4expr.n_table = __3tt;
                            Cdcl = __1odcl;
                            return (struct name *)0;
                        }
                    }

                    if (__0this->__O1__4expr.tp->base__4node == 108) {
                        if (((friend_in_class == 0) && (__0this->n_sto__4name != 18)) &&
                            ((((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
                                 ->body__3fct == 0)) {
                            {
                                struct ea __0__V68;

                                error__FPCcRC2eaN32((const char *)"QdN%n inFD",
                                                    (const struct ea *)(((&__0__V68)->__O1__2ea.p =
                                                                             ((const void *)__2x)),
                                                                        (&__0__V68)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                                Cdcl = __1odcl;
                                return (struct name *)0;
                            }
                        }

                        if ((((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
                                ->body__3fct == 0) {
                            (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
                                ->memof__3fct = __2cl;

                            {
                                int __4xx;
                                if (__2x->__O1__4expr.tp->base__4node == 76)
                                    __4xx =
                                        (find__3genFP3fctUc(
                                             ((struct gen *)(((struct gen *)__2x->__O1__4expr.tp))),
                                             ((struct fct *)((
                                                 (struct fct *)__0this->__O1__4expr.tp))),
                                             (unsigned char)0) == 0);
                                else
                                    __4xx = check__4typeFP4typeUcT2(
                                        __2x->__O1__4expr.tp, __0this->__O1__4expr.tp,
                                        (unsigned char)0, (unsigned char)0);

                                if (__4xx) {
                                    Ptable __5tt;

                                    __5tt = __0this->__O4__4expr.n_table;
                                    __0this->__O4__4expr.n_table = __2etbl;
                                    {
                                        struct ea __0__V69;

                                        struct ea __0__V70;

                                        struct ea __0__V71;

                                        error__FPCcRC2eaN32(
                                            (const char *)"%n ofT%t is not aM of%n",
                                            (const struct ea *)(((&__0__V69)->__O1__2ea.p =
                                                                     ((const void *)__0this)),
                                                                (&__0__V69)),
                                            (const struct ea *)__ct__2eaFPCv(
                                                &__0__V70, (const void *)__0this->__O1__4expr.tp),
                                            (const struct ea *)(((&__0__V71)->__O1__2ea.p =
                                                                     ((const void *)__2cn)),
                                                                (&__0__V71)),
                                            (const struct ea *)ea0);
                                        __0this->__O4__4expr.n_table = __5tt;
                                        Cdcl = __1odcl;
                                        return (struct name *)0;
                                    }
                                }
                            }
                        }
                    } else {
                        if (__2x->n_stclass__4name != 31) {
                            {
                                struct ea __0__V72;

                                error__FPCcRC2eaN32(
                                    (const char *)"D of non staticCM%n",
                                    (const struct ea *)(((&__0__V72)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V72)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                Cdcl = __1odcl;
                                return (struct name *)0;
                            }
                        }
                        if (__0this->n_sto__4name) {
                            unsigned long __2__X155;

                            {
                                struct ea __0__V73;

                                error__FPCcRC2eaN32(
                                    (const char *)"staticCM declared%k",
                                    (const struct ea *)((__2__X155 = __0this->n_sto__4name),
                                                        (((((&__0__V73)->__O1__2ea.i = __2__X155),
                                                           0)),
                                                         (&__0__V73))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                Cdcl = __1odcl;
                                return (struct name *)0;
                            }
                        }

                        if (__2cl->class_base__8classdef == 4)
                            __0this->n_redefined__4name = 1;
                        __1tbl = __2etbl;
                    }
                }
            }
        }
    xdr:
        if ((__0this->n_oper__4name && (__0this->__O1__4expr.tp->base__4node != 108)) &&
            (__0this->n_sto__4name != 76)) {
            struct ea __0__V74;

            error__FPCcRC2eaN32(
                (const char *)"operator%k not aF",
                (const struct ea *)((__2__X156 = __0this->n_oper__4name),
                                    (((((&__0__V74)->__O1__2ea.i = __2__X156), 0)), (&__0__V74))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        __0this->n_stclass__4name = __0this->n_sto__4name;
        __0this->n_scope__4name = __1scope;

        switch (__0this->n_sto__4name) {
            unsigned long __2__X157;

        default: {
            struct ea __0__V75;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"unX %k",
                (const struct ea *)((__2__X157 = __0this->n_sto__4name),
                                    (((((&__0__V75)->__O1__2ea.i = __2__X157), 0)), (&__0__V75))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        case 18: {
            Pclass __3cl;

            __3cl = cc->cot__11dcl_context;

            switch (__1scope) {
            case 0:
            case 25:
                break;
            default: {
                struct ea __0__V76;

                struct ea __0__V77;

                error__FPCcRC2eaN32(
                    (const char *)"friend%n not inCD(%k)",
                    (const struct ea *)(((&__0__V76)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V76)),
                    (const struct ea *)(((((&__0__V77)->__O1__2ea.i = ((unsigned long)__1scope)),
                                          0)),
                                        (&__0__V77)),
                    (const struct ea *)ea0, (const struct ea *)ea0);

                __0this->base__4node = 0;
                Cdcl = __1odcl;
                return (struct name *)0;
            }
            }

            switch (__0this->n_oper__4name) {
            case 0:
            case 23:
            case 213:
            case 9:
            case 212:
            case 161:
            case 162:
            case 97:
                __0this->n_sto__4name = 0;
                break;
            default:
                __0this->n_sto__4name = 76;
            }

            switch (__1tx->base__4node) {
                struct dcl_context *__0__X158;

                struct dcl_context *__0__X159;

                const void *__2__X160;

            case 119:
                __1nn = (((struct basetype *)(((struct basetype *)__1tx))))->b_name__8basetype;
                break;
            case 6:
                __1nn = __0this;
                break;
            case 108:
                (((struct fct *)(((struct fct *)__1tx))))->def_context__3fct =
                    cc->cot__11dcl_context;
                ((((cc++), (((cc >= ccvec_end)
                                 ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow")
                                 : 0),
                            (((*cc)) = (*(cc - 1))))),
                  (((void)0))));
                cc->not4__11dcl_context = 0;
                cc->tot__11dcl_context = 0;
                cc->cot__11dcl_context = 0;
                friend_in_class++;
                __0this->n_sto__4name = 0;

                __0this->lex_level__4name = 0;
                __1nn = dcl__4nameFP5tableUc(__0this, gtbl, (unsigned char)14);
                if (__1nn == 0) {
                    Cdcl = __1odcl;
                    return (struct name *)0;
                }
                friend_in_class--;
                (((cc--), (((void)0))));
                if (__1nn->__O1__4expr.tp->base__4node == 76)
                    __1nn = find__3genFP3fctUc(
                        ((struct gen *)(((struct gen *)__1nn->__O1__4expr.tp))),
                        ((struct fct *)(((struct fct *)__1tx))), (unsigned char)1);
                break;
            default: {
                struct ea __0__V78;

                struct ea __0__V79;

                error__FPCcRC2eaN32(
                    (const char *)"badT%t of friend%n",
                    (const struct ea *)((__2__X160 = (const void *)__0this->__O1__4expr.tp),
                                        (((&__0__V78)->__O1__2ea.p = __2__X160), (&__0__V78))),
                    (const struct ea *)(((&__0__V79)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V79)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                Cdcl = __1odcl;
                return (struct name *)0;
            }
            }

            __1nn->permanent__4node = 1;
            __3cl->friend_list__8classdef = __ct__9name_listFP4nameP9name_list(
                (struct name_list *)0, __1nn, __3cl->friend_list__8classdef);
            Cdcl = __1odcl;
            return __1nn;
        }

        case 76:
            error__FiPCc(strict_opt ? 0 : 119, (const char *)"`overload' used (anachronism)");
            __0this->n_sto__4name = 0;
            switch (__0this->__O1__4expr.tp->base__4node) {
            case 108:
                break;
            default:
                __0this->base__4node = 0;
                Cdcl = __1odcl;
                return __0this;
            }
            break;

        case 27:
            if (__0this->__O1__4expr.tp->base__4node == 108) {
                {
                    struct ea __0__V80;

                    error__FiPCcRC2eaN33(
                        (int)'w', (const char *)"%n: register (ignored)",
                        (const struct ea *)(((&__0__V80)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V80)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    goto ddd;
                }
            }

        case 2:
            switch (__1scope) {
                unsigned long __2__X161;

            case 0:
            case 25:
            case 14: {
                struct ea __0__V81;

                error__FPCcRC2eaN32(
                    (const char *)"%k not inF",
                    (const struct ea *)((__2__X161 = __0this->n_sto__4name),
                                        (((((&__0__V81)->__O1__2ea.i = __2__X161), 0)),
                                         (&__0__V81))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                goto ddd;
            }
            }
            if (__0this->n_sto__4name == 2)
                __0this->n_sto__4name = 0;
            break;

        case 14:
            switch (__1scope) {
            case 0:
            case 25:
                if (__0this->__O1__4expr.tp->base__4node != 108) {
                    struct ea __0__V82;

                    error__FPCcRC2eaN32(
                        (const char *)"externM%n",
                        (const struct ea *)(((&__0__V82)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V82)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            case 136:
                goto ddd;

            case 108: {
                Pname __4nn;

                __4nn = look__5tableFPCcUc(gtbl, __0this->__O2__4expr.string, (unsigned char)0);
                dcl__4typeFP5table(__0this->__O1__4expr.tp, __1tbl);
                if ((__4nn && (__0this->__O1__4expr.tp->base__4node != 108)) &&
                    check__4typeFP4typeUcT2(__0this->__O1__4expr.tp, __4nn->__O1__4expr.tp,
                                            (unsigned char)0, (unsigned char)0)) {
                    {
                        struct ea __0__V83;

                        struct ea __0__V84;

                        struct ea __0__V85;

                        error__FPCcRC2eaN32((const char *)"twoDs of%n;Ts:%t and%t",
                                            (const struct ea *)(((&__0__V83)->__O1__2ea.p =
                                                                     ((const void *)__0this)),
                                                                (&__0__V83)),
                                            (const struct ea *)__ct__2eaFPCv(
                                                &__0__V84, (const void *)__4nn->__O1__4expr.tp),
                                            (const struct ea *)__ct__2eaFPCv(
                                                &__0__V85, (const void *)__0this->__O1__4expr.tp),
                                            (const struct ea *)ea0);
                        Cdcl = __1odcl;
                        return (struct name *)0;
                    }
                }
            }
            }
            __0this->n_stclass__4name = 31;
            __0this->n_scope__4name = 14;
            break;

        case 31:
            switch (__1scope) {
            case 136:
                goto ddd;
            case 0:
            case 25:
                __0this->n_stclass__4name = 31;
                __0this->n_scope__4name = __1scope;
                break;
            default:
                __0this->n_scope__4name = 31;
            }
            break;

        case 0:
        ddd:
            switch (__1scope) {
            case 14:
                __0this->n_scope__4name = 14;
                __0this->n_stclass__4name = 31;
                break;
            case 108:
                if (__0this->__O1__4expr.tp->base__4node == 108) {
                    __0this->n_stclass__4name = 31;
                    __0this->n_scope__4name = 14;
                } else
                    __0this->n_stclass__4name = 2;
                break;
            case 136:
                __0this->n_stclass__4name = 2;
                break;
            case 0:
            case 25:
                __0this->n_stclass__4name = 0;
                break;
            }
        }
        }

        {
            static int __1warn_ldouble = 0;

            switch (__1tx->base__4node) {
            case 1: {
                Pbase __3b;
                Pname __3n;

                __3b = (((struct basetype *)(((struct basetype *)__0this->__O1__4expr.tp))));
                __3n = insert__5tableFP4nameUc(__1tbl, __0this, (unsigned char)0);
                assign__4nameFv(__3n);
                ((__3n->n_used__4name++), (((void)0)));
                {
                    char *__3s;
                    int __3ll;
                    char *__3s2;

                    __3s = (((char *)__3b->b_name__8basetype));
                    __3ll = strlen((const char *)__3s);
                    __3s2 = (((char *)__nw__FUl((size_t)((sizeof(char)) * (__3ll + 1)))));
                    strcpy(__3s2, (const char *)__3s);
                    __3b->b_name__8basetype = (((struct name *)(((struct name *)__3s2))));
                    Cdcl = __1odcl;
                    return __0this;
                }
            }
            case 6:
                if (__0this->n_key__4name == 44) {
                    __1nn = insert__5tableFP4nameUc(__1tbl, __0this, (unsigned char)6);
                    __0this->n_key__4name = 44;

                } else {
                    if (__1tx->in_class__4type &&
                        ((__1tx->templ_base__4type == 3) || (__1tx->templ_base__4type == 2))) {
                        __dl__FPv((void *)__1tx->nested_sig__4type);
                        __1tx->nested_sig__4type = make_nested_name__FPCcP8classdef(
                            (((struct classdef *)(((struct classdef *)__1tx))))->string__8classdef,
                            __1tx->in_class__4type);
                    }
                    __0this->__O1__4expr.tp = __1tx;
                    __1nn = dclass__FP4nameP5table(__0this, __1tbl);
                }
                Cdcl = __1odcl;
                return __1nn;
            case 13:
                if (__1tx->in_class__4type &&
                    ((__1tx->templ_base__4type == 3) || (__1tx->templ_base__4type == 2))) {
                    __dl__FPv((void *)__1tx->nested_sig__4type);
                    __1tx->nested_sig__4type = make_nested_name__FPCcP8classdef(
                        (((struct enumdef *)(((struct enumdef *)__1tx))))->string__7enumdef,
                        __1tx->in_class__4type);
                }
                __0this->__O1__4expr.tp = __1tx;
                __1nn = denum__FP4nameP5table(__0this, __1tbl);
                Cdcl = __1odcl;
                return __1nn;
            case 108:
                __0this->__O1__4expr.tp = __1tx;
                __1nn = dofct__4nameFP5tableUc(__0this, __1tbl, __1scope);
                if (__1nn == 0) {
                    Cdcl = __1odcl;
                    return (struct name *)0;
                }

                if (pdef_name == 0)
                    check_def_name__FP4namei(__1nn, (int)__1scope);
                break;

            case 114:
                switch (__0this->n_stclass__4name) {
                    unsigned long __2__X162;

                case 0:
                case 25:
                    break;
                default: {
                    struct ea __0__V86;

                    error__FPCcRC2eaN32(
                        (const char *)"%k field",
                        (const struct ea *)((__2__X162 = __0this->n_stclass__4name),
                                            (((((&__0__V86)->__O1__2ea.i = __2__X162), 0)),
                                             (&__0__V86))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    __0this->n_stclass__4name = 0;
                }
                }

                if (((cc->not4__11dcl_context == 0) ||
                     ((cc->cot__11dcl_context->csu__8classdef == 36) && (!ansi_opt))) ||
                    (cc->cot__11dcl_context->csu__8classdef == 167)) {
                    if (cc->not4__11dcl_context)
                        error__FiPCc((int)'s', (const char *)"bit-field as member of union");
                    else
                        error__FPCc((const char *)"bit-field not inC");
                    __0this->__O1__4expr.tp->permanent__4node = 1;
                    Cdcl = __1odcl;
                    return __0this;
                }

                if (__0this->__O2__4expr.string) {
                    __1nn = insert__5tableFP4nameUc(__1tbl, __0this, (unsigned char)0);
                    __0this->__O4__4expr.n_table = __1nn->__O4__4expr.n_table;
                    if (Nold) {
                        struct ea __0__V87;

                        error__FPCcRC2eaN32((const char *)"twoDs of field%n",
                                            (const struct ea *)(((&__0__V87)->__O1__2ea.p =
                                                                     ((const void *)__0this)),
                                                                (&__0__V87)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                    }
                }

                dcl__4typeFP5table(__0this->__O1__4expr.tp, __1tbl);
                field_align__4nameFv(__0this);
                break;

            case 119: {
                Pclass __3cl;

                __3cl = (((struct classdef *)((
                    (struct classdef *)(((struct basetype *)(((struct basetype *)__1tx))))
                        ->b_name__8basetype->__O1__4expr.tp))));

                if (__3cl->csu__8classdef == 167)
                    export_anon__FP4nameP8classdefP5table(__0this, __3cl, __1tbl);

                if (__3cl->c_abstract__8classdef) {
                    if ((((__3cl->string__8classdef[0]) == '_') &&
                         ((__3cl->string__8classdef[1]) == '_')) &&
                        ((__3cl->string__8classdef[2]) == 'C'))
                        error__FiPCc(
                            (int)'e',
                            (const char *)"D ofO of abstractC - pure virtual function(s) ");
                    else {
                        struct ea __0__V88;

                        error__FiPCcRC2eaN33(
                            (int)'e',
                            (const char *)"D ofO of abstractC%t - pure virtual function(s) ",
                            (const struct ea *)(((&__0__V88)->__O1__2ea.p = ((const void *)__3cl)),
                                                (&__0__V88)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    {
                        {
                            Pbcl __4bcl;

                            __4bcl = __3cl->baselist__8classdef;

                            for (; __4bcl; __4bcl = __4bcl->next__6basecl) {
                                {
                                    Pvirt __4n;

                                    __4n = __4bcl->bclass__6basecl->virt_list__8classdef;

                                    for (; __4n; __4n = __4n->next__4virt) {
                                        struct velem *__5ivec;
                                        Pname __5vn;

                                        __5ivec = __4n->virt_init__4virt;

                                        {
                                            {
                                                int __5i;

                                                __5i = 0;

                                                for (; __5vn = (__5ivec[__5i]).n__5velem; __5i++) {
                                                    Pname __6n;

                                                    __6n = look__5tableFPCcUc(
                                                        __3cl->memtbl__8classdef,
                                                        __5vn->__O2__4expr.string,
                                                        (unsigned char)0);
                                                    if (__5vn->__O3__4expr.n_initializer &&
                                                        ((__6n == 0) ||
                                                         (__6n->base__4node == 25))) {
                                                        struct ea __0__V89;

                                                        error__FiPCcRC2eaN33(
                                                            (int)'c', (const char *)"%n ",
                                                            (const struct ea
                                                                 *)(((&__0__V89)->__O1__2ea.p =
                                                                         ((const void *)__5vn)),
                                                                    (&__0__V89)),
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            error__FiPCc((int)'c', (const char *)"have not been defined\n");
                        }
                    }
                }
                goto cde;
            }

            case 38:
                if (__0this->n_scope__4name != 136) {
                    unsigned long __2__X163;

                    {
                        struct ea __0__V90;

                        struct ea __0__V91;

                        error__FPCcRC2eaN32(
                            (const char *)"badBT:%k%n",
                            (const struct ea *)((__2__X163 = __1tx->base__4node),
                                                (((((&__0__V90)->__O1__2ea.i = __2__X163), 0)),
                                                 (&__0__V90))),
                            (const struct ea *)(((&__0__V91)->__O1__2ea.p =
                                                     ((const void *)__0this)),
                                                (&__0__V91)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                        Cdcl = __1odcl;
                        return (struct name *)0;
                    }
                }
                break;

            case 181:
                if ((__1warn_ldouble == 0) && (ansi_opt == 0)) {
                    ++__1warn_ldouble;
                    {
                        struct ea __0__V92;

                        error__FiPCcRC2eaN33((int)'w',
                                             (const char *)"long double supported under ``+a1'' "
                                                           "option only, generating ``double%n''",
                                             (const struct ea *)(((&__0__V92)->__O1__2ea.p =
                                                                      ((const void *)__0this)),
                                                                 (&__0__V92)),
                                             (const struct ea *)ea0, (const struct ea *)ea0,
                                             (const struct ea *)ea0);
                    }
                }
                goto cde;

            case 125:
            case 110:
            case 158:
                dcl__4typeFP5table(__0this->__O1__4expr.tp, __1tbl);

            default:
            cde:
                __1nn = insert__5tableFP4nameUc(__1tbl, __0this, (unsigned char)0);
                __0this->__O4__4expr.n_table = __1nn->__O4__4expr.n_table;
                __1nn->n_redefined__4name = __0this->n_redefined__4name;

                if (Nold) {
                    if ((__1nn->base__4node == 123) && (__0this->base__4node == 85)) {
                        const void *__2__X164;

                        if ((__1nn->__O3__4expr.tpdef &&
                             __1nn->__O3__4expr.tpdef->in_class__4type) &&
                            (__1nn->__O3__4expr.tpdef->in_class__4type->csu__8classdef == 167)) {
                            struct ea __0__V93;

                            error__FPCcRC2eaN32(
                                (const char *)"twoDs of %s (one in anonymous union)",
                                (const struct ea *)((__2__X164 =
                                                         (const void *)__1nn->__O2__4expr.string),
                                                    (((&__0__V93)->__O1__2ea.p = __2__X164),
                                                     (&__0__V93))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        } else {
                            struct ea __0__V94;

                            error__FPCcRC2eaN32((const char *)"%n declared as identifier andTdef",
                                                (const struct ea *)(((&__0__V94)->__O1__2ea.p =
                                                                         ((const void *)__1nn)),
                                                                    (&__0__V94)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        }
                        __1nn->n_key__4name = 159;
                        __0this->__O4__4expr.n_table = 0;
                        goto cde;
                    }
                    if (__1nn->base__4node == 25) {
                        {
                            struct ea __0__V95;

                            error__FPCcRC2eaN32((const char *)"twoDs ofCM%n",
                                                (const struct ea *)(((&__0__V95)->__O1__2ea.p =
                                                                         ((const void *)__1nn)),
                                                                    (&__0__V95)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                            Cdcl = __1odcl;
                            return (struct name *)0;
                        }
                    }

                    if (__1nn->__O1__4expr.tp->base__4node == 141)
                        goto zzz;

                    if (check__4typeFP4typeUcT2(__0this->__O1__4expr.tp, __1nn->__O1__4expr.tp,
                                                (unsigned char)0, (unsigned char)0)) {
                        if (__1nn->base__4node != 123) {
                            struct ea __0__V96;

                            struct ea __0__V97;

                            struct ea __0__V98;

                            error__FPCcRC2eaN32(
                                (const char *)"twoDs of%n;%t and%t",
                                (const struct ea *)(((&__0__V96)->__O1__2ea.p =
                                                         ((const void *)__1nn)),
                                                    (&__0__V96)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V97, (const void *)__1nn->__O1__4expr.tp),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V98, (const void *)__0this->__O1__4expr.tp),
                                (const struct ea *)ea0);
                        }
                        Cdcl = __1odcl;
                        return (struct name *)0;
                    }
                    if (__0this->n_sto__4name && (__0this->n_sto__4name != __1nn->n_scope__4name)) {
                        unsigned long __2__X165;

                        if ((__0this->n_sto__4name == 14) && (__1nn->n_scope__4name == 31)) {
                            {
                                struct ea __0__V99;

                                error__FiPCcRC2eaN33(
                                    (int)'w',
                                    (const char *)"%n declared extern after being declared static",
                                    (const struct ea *)(((&__0__V99)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V99)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                goto ext_fudge;
                            }
                        } else {
                            struct ea __0__V100;

                            struct ea __0__V101;

                            struct ea __0__V102;

                            error__FPCcRC2eaN32(
                                (const char *)"%n declared as both%k and%k",
                                (const struct ea *)(((&__0__V100)->__O1__2ea.p =
                                                         ((const void *)__0this)),
                                                    (&__0__V100)),
                                (const struct ea *)((__2__X165 = __0this->n_sto__4name),
                                                    (((((&__0__V101)->__O1__2ea.i = __2__X165), 0)),
                                                     (&__0__V101))),
                                (const struct ea *)__ct__2eaFUl(
                                    &__0__V102,
                                    (unsigned long)(__1nn->n_sto__4name
                                                        ? (((unsigned int)__1nn->n_sto__4name))
                                                        : (((unsigned int)14)))),
                                (const struct ea *)ea0);
                        }
                    } else if ((__1nn->n_scope__4name == 31) && (__0this->n_scope__4name == 14)) {
                        {
                            struct ea __0__V103;

                            error__FiPCcRC2eaN33((int)'w',
                                                 (const char *)"static%n followed by definition",
                                                 (const struct ea *)(((&__0__V103)->__O1__2ea.p =
                                                                          ((const void *)__0this)),
                                                                     (&__0__V103)),
                                                 (const struct ea *)ea0, (const struct ea *)ea0,
                                                 (const struct ea *)ea0);
                        ext_fudge:
                            if (__0this->__O3__4expr.n_initializer) {
                                __0this->__O3__4expr.n_initializer = 0;
                            }
                            __0this->n_sto__4name = 14;
                        }
                    } else if ((__1nn->n_sto__4name == 31) && (__0this->n_sto__4name == 31)) {
                        struct ea __0__V104;

                        error__FPCcRC2eaN32((const char *)"static%n declared twice",
                                            (const struct ea *)(((&__0__V104)->__O1__2ea.p =
                                                                     ((const void *)__0this)),
                                                                (&__0__V104)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                    } else {
                        if ((((__0this->n_sto__4name == 0) && (__1nn->n_sto__4name == 14)) &&
                             __0this->__O3__4expr.n_initializer) &&
                            tconst__4typeFv(__0this->__O1__4expr.tp))
                            if (vec_const == 0)
                                __0this->n_sto__4name = 14;

                        __0this->n_scope__4name = __1nn->n_scope__4name;

                        switch (__1scope) {
                        case 108:
                            if (__0this->n_sto__4name != 14) {
                                {
                                    struct ea __0__V105;

                                    error__FPCcRC2eaN32(
                                        (const char *)"twoDs of%n",
                                        (const struct ea *)(((&__0__V105)->__O1__2ea.p =
                                                                 ((const void *)__0this)),
                                                            (&__0__V105)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    Cdcl = __1odcl;
                                    return (struct name *)0;
                                }
                            }
                            break;
                        case 136: {
                            struct ea __0__V106;

                            error__FPCcRC2eaN32((const char *)"twoAs%n",
                                                (const struct ea *)(((&__0__V106)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V106)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                            Cdcl = __1odcl;
                            return (struct name *)0;
                        case 0:
                        case 25: {
                            struct ea __0__V107;

                            error__FPCcRC2eaN32((const char *)"twoDs ofM%n",
                                                (const struct ea *)(((&__0__V107)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V107)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                            Cdcl = __1odcl;
                            return (struct name *)0;
                        case 14:
                            if ((__0this->n_sto__4name == 0) ||
                                ((__0this->n_sto__4name == 14) &&
                                 __0this->__O3__4expr.n_initializer)) {
                                switch (__1nn->n_sto__4name) {
                                case 0: {
                                    struct ea __0__V108;

                                    error__FPCcRC2eaN32(
                                        (const char *)"two definitions of%n",
                                        (const struct ea *)(((&__0__V108)->__O1__2ea.p =
                                                                 ((const void *)__0this)),
                                                            (&__0__V108)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    Cdcl = __1odcl;
                                    return (struct name *)0;
                                case 14:
                                    if ((__0this->n_sto__4name == 0) &&
                                        __1nn->__O3__4expr.n_initializer) {
                                        {
                                            struct ea __0__V109;

                                            error__FPCcRC2eaN32(
                                                (const char *)"two definitions of%n",
                                                (const struct ea *)(((&__0__V109)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V109)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                                            Cdcl = __1odcl;
                                        }
                                    } else
                                        __1nn->n_sto__4name = 0;

                                    if ((__1nn->n_stclass__4name == 31) &&
                                        ((__1nn->n_scope__4name == 25) ||
                                         (__1nn->n_scope__4name == 0))) {
                                        if (skiptypedefs__4typeFv(__0this->__O1__4expr.tp)
                                                ->base__4node == 110) {
                                            Ptype __9atp;

                                            __9atp = skiptypedefs__4typeFv(__1nn->__O1__4expr.tp);
                                            if (__9atp && (__9atp->base__4node == 110))
                                                tsizeof__4typeFi(
                                                    (((struct vec *)(((struct vec *)__9atp))))
                                                        ->typ__5pvtyp,
                                                    0);
                                        } else
                                            tsizeof__4typeFi(__1nn->__O1__4expr.tp, 0);
                                    }
                                    break;
                                }
                                }
                            }
                            break;
                        }
                        }
                        }
                    }
                    __0this->n_scope__4name = __1nn->n_scope__4name;

                    if (__0this->__O3__4expr.n_initializer) {
                        if (__1nn->__O3__4expr.n_initializer || __1nn->n_val__4name) {
                            struct ea __0__V110;

                            error__FPCcRC2eaN32((const char *)"twoIrs for%n",
                                                (const struct ea *)(((&__0__V110)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V110)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        }
                        __1nn->__O3__4expr.n_initializer = __0this->__O3__4expr.n_initializer;
                    }
                    if (__0this->__O1__4expr.tp->base__4node == 110) {
                        Ptype __4ntp;

                        __4ntp = skiptypedefs__4typeFv(__1nn->__O1__4expr.tp);

                        if ((((struct vec *)(((struct vec *)__4ntp))))->dim__3vec == 0)
                            (((struct vec *)(((struct vec *)__4ntp))))->dim__3vec =
                                (((struct vec *)(((struct vec *)__0this->__O1__4expr.tp))))
                                    ->dim__3vec;

                        if ((((struct vec *)(((struct vec *)__4ntp))))->size__3vec) {
                            unsigned long __2__X166;

                            if ((((struct vec *)(((struct vec *)__0this->__O1__4expr.tp))))
                                    ->size__3vec &&
                                ((((struct vec *)(((struct vec *)__4ntp))))->size__3vec !=
                                 (((struct vec *)(((struct vec *)__0this->__O1__4expr.tp))))
                                     ->size__3vec)) {
                                struct ea __0__V111;

                                struct ea __0__V112;

                                struct ea __0__V113;

                                error__FPCcRC2eaN32(
                                    (const char *)"bad array size for%n: %d %dX",
                                    (const struct ea *)(((&__0__V111)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V111)),
                                    (const struct ea
                                         *)((__2__X166 =
                                                 (((struct vec *)((
                                                      (struct vec *)__0this->__O1__4expr.tp))))
                                                     ->size__3vec),
                                            (((((&__0__V112)->__O1__2ea.i = __2__X166), 0)),
                                             (&__0__V112))),
                                    (const struct ea *)__ct__2eaFUl(
                                        &__0__V113,
                                        (unsigned long)(((struct vec *)(((struct vec *)__4ntp))))
                                            ->size__3vec),
                                    (const struct ea *)ea0);
                            }
                        } else
                            (((struct vec *)(((struct vec *)__4ntp))))->size__3vec =
                                (((struct vec *)(((struct vec *)__0this->__O1__4expr.tp))))
                                    ->size__3vec;
                    }
                } else {
                    if ((((((__1scope != 136) && (__0this->n_sto__4name != 14)) &&
                           ((__0this->n_sto__4name != 31) ||
                            ((__1scope != 0) && (__1scope != 25)))) &&
                          (__0this->__O3__4expr.n_initializer == 0)) &&
                         (skiptypedefs__4typeFv(__0this->__O1__4expr.tp)->base__4node == 110)) &&
                        ((((struct vec *)((
                              (struct vec *)skiptypedefs__4typeFv(__0this->__O1__4expr.tp)))))
                             ->size__3vec == 0))
                        if ((((struct vec *)(((struct vec *)__0this->__O1__4expr.tp))))
                                ->dim__3vec == 0) {
                            struct ea __0__V114;

                            error__FP3locPCcRC2eaN33(
                                &__0this->where__4name,
                                (const char *)"dimension missing for array%n",
                                (const struct ea *)(((&__0__V114)->__O1__2ea.p =
                                                         ((const void *)__0this)),
                                                    (&__0__V114)),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                    if (((__1scope == 14) && (__0this->n_sto__4name == 0)) &&
                        is_const_object__4typeFv(__0this->__O1__4expr.tp))
                        __1nn->n_sto__4name = (__0this->n_sto__4name = 31);
                }

            zzz:
                if (__0this->base__4node != 123) {
                    Ptype __3t;

                    __3t = __1nn->__O1__4expr.tp;

                    if (__3t->base__4node == 97) {
                        Ptype __4tt;

                        __4tt = (((struct basetype *)(((struct basetype *)__3t))))
                                    ->b_name__8basetype->__O1__4expr.tp;
                        if (__4tt->base__4node == 108)
                            __1nn->__O1__4expr.tp = (__3t = __4tt);
                    }

                    switch (__3t->base__4node) {
                    case 108:
                    case 76:
                        break;
                    default:
                        fake_sizeof = 1;
                        switch (__1nn->n_stclass__4name) {
                        default:
                            if (__1nn->n_scope__4name != 136) {
                                int __6x;
                                int __6y;

                                __6x = align__4typeFv(__3t);
                                __6y = tsizeof__4typeFi(__3t, 0);

                                if (max_align < __6x)
                                    max_align = __6x;

                                while (0 < bit_offset) {
                                    byte_offset++;
                                    bit_offset -= BI_IN_BYTE;
                                }
                                bit_offset = 0;

                                if (byte_offset && (1 < __6x))
                                    byte_offset = ((((byte_offset - 1) / __6x) * __6x) + __6x);
                                __1nn->n_offset__4name = byte_offset;
                                byte_offset += __6y;
                            }
                            break;
                        case 31:
                            if (__0this->n_sto__4name != 14) {
                                struct classdef *__1__X167;

                                struct classdef *__1__X168;

                                if (__1nn->n_scope__4name && (__1nn->n_scope__4name != 25))
                                    tsizeof__4typeFi(__3t, 0);
                                else if (((__1tbl->t_name__5table == 0) || (__1tbl == gtbl)) ||
                                         (!((__1__X167 = (((struct classdef *)((
                                                 (struct classdef *)
                                                     __1tbl->t_name__5table->__O1__4expr.tp))))),
                                            ((__1__X168 = (((struct classdef *)((
                                                  (struct classdef *)__1nn->__O4__4expr.n_table
                                                      ->t_name__5table->__O1__4expr.tp))))),
                                             (((__1__X167 == __1__X168)
                                                   ? 1
                                                   : ((__1__X167 && __1__X168)
                                                          ? (((int)
                                                                  same_class__8classdefFP8classdefi(
                                                                      __1__X167, __1__X168, 0)))
                                                          : 0)))))))
                                    tsizeof__4typeFi(__3t, 0);
                            }
                        }
                        fake_sizeof = 0;
                    }
                }

                {
                    Ptype __3t;
                    int __3const_old;
                    bit __3vec_seen;
                    Pexpr __3init;

                    bit __3td_const;

                    __3t = __1nn->__O1__4expr.tp;
                    __3const_old = const_save;
                    __3vec_seen = 0;
                    __3init = __0this->__O3__4expr.n_initializer;

                    __3td_const = 0;
                lll:
                    switch (__3t->base__4node) {
                    case 119: {
                        Pname __5cn;
                        Pclass __5cl;
                        Pname __5ctor;
                        Pname __5dtor;
                        int __5stct;

                        __5cn =
                            (((struct basetype *)(((struct basetype *)__3t))))->b_name__8basetype;
                        __5cl = (((struct classdef *)(((struct classdef *)__5cn->__O1__4expr.tp))));
                        __5ctor = (__5cl->c_ctor__8classdef);
                        __5dtor = (__5cl->c_dtor__8classdef);
                        __5stct = 0;
                        if (__5dtor) {
                            Pstmt __6dls;

                            if (!check_static_pt__FP4name(__1nn)) {
                                assign__4nameFv(__1nn);
                                ((__1nn->n_used__4name++), (((void)0)));
                                goto ggg;
                            }

                            if (__5dtor->n_scope__4name != 25) {
                                switch (__1nn->n_scope__4name) {
                                case 136:
                                case 0:
                                case 25:
                                    break;
                                default:
                                    check_visibility__FP4nameT1P8classdefP5tableT1(
                                        __5dtor, (struct name *)0, __5cl, __1tbl,
                                        cc->nof__11dcl_context);
                                }
                            }

                            switch (__1nn->n_scope__4name) {
                            case 0:
                            case 25:
                                if (__0this->n_stclass__4name == 31) {
                                    Pclass __8cl;

                                    __8cl = (((struct classdef *)((
                                        (struct classdef *)__1nn->__O4__4expr.n_table
                                            ->t_name__5table->__O1__4expr.tp))));
                                    if (__8cl->defined__4type & 01)
                                        goto dtdt;
                                }
                                break;
                            case 14:
                                if ((__3init == 0) && (__0this->n_sto__4name == 14))
                                    break;

                            case 31: {
                                Pexpr __8c;
                            dtdt:
                                if (stat_init && (__1scope == 137)) {
                                    __1nn->n_scope__4name = 137;
                                    goto ggg;
                                }

                                if (__1nn->lex_level__4name && (__1nn->n_sto__4name == 31)) {
                                    if (__5ctor == 0) {
                                        struct ea __0__V115;

                                        struct ea __0__V116;

                                        struct ea __0__V117;

                                        struct ea __0__V118;

                                        error__FiPCcRC2eaN33(
                                            (int)'s',
                                            (const char
                                                 *)"local static%n has%n but noK(add%n::%n())",
                                            (const struct ea *)(((&__0__V115)->__O1__2ea.p =
                                                                     ((const void *)__1nn)),
                                                                (&__0__V115)),
                                            (const struct ea *)(((&__0__V116)->__O1__2ea.p =
                                                                     ((const void *)__5dtor)),
                                                                (&__0__V116)),
                                            (const struct ea *)(((&__0__V117)->__O1__2ea.p =
                                                                     ((const void *)__5cn)),
                                                                (&__0__V117)),
                                            (const struct ea *)(((&__0__V118)->__O1__2ea.p =
                                                                     ((const void *)__5cn)),
                                                                (&__0__V118)));
                                    }
                                    goto static_init;
                                }

                                {
                                    Ptable __8otbl;

                                    struct estmt *__0__X169;

                                    struct loc __2__X170;

                                    __8otbl = __1tbl;

                                    if (std_tbl == 0)
                                        std_tbl = __ct__5tableFsP5tableP4name(
                                            (struct table *)0, (short)8, gtbl, (struct name *)0);
                                    __1tbl = std_tbl;
                                    if (__3vec_seen) {
                                        __8c = cdvec__FP4nameP4exprP8classdefT1iN22(
                                            vec_del_fct, (struct expr *)__1nn, __5cl, __5dtor, 0,
                                            zero, (struct expr *)0);

                                    } else {
                                        __8c = call_dtor__FP4exprN21iT1((struct expr *)__1nn,
                                                                        (struct expr *)__5dtor,
                                                                        (struct expr *)0, 45, one);
                                    }
                                    __8c->__O1__4expr.tp = (struct type *)any_type;
                                    __6dls =
                                        (struct stmt
                                             *)((__0__X169 = 0),
                                                ((__2__X170 = __1nn->where__4name),
                                                 (((__0__X169 ||
                                                    (__0__X169 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                                       ? ((__0__X169 = (struct estmt *)
                                                               __ct__4stmtFUc3locP4stmt(
                                                                   ((struct stmt *)__0__X169),
                                                                   ((unsigned char)72), __2__X170,
                                                                   ((struct stmt *)0))),
                                                          (__0__X169->__O2__4stmt.e = __8c))
                                                       : 0),
                                                  __0__X169)));

                                    if (st_dlist)
                                        __6dls->s_list__4stmt = st_dlist;
                                    st_dlist = __6dls;
                                    __1tbl = __8otbl;
                                }
                            }
                            }
                        }

                    static_init:
                        if (__5ctor) {
                            Pexpr __6oo;

                            __6oo = (struct expr *)__1nn;
                            {
                                {
                                    int __6vi;

                                    __6vi = __3vec_seen;

                                    for (; __6vi; __6vi--)
                                        __6oo = contents__4exprFv(__6oo);
                                    {
                                        int __6sti;

                                        __6sti = 0;
                                        if (!check_static_pt__FP4name(__1nn)) {
                                            assign__4nameFv(__1nn);
                                            ((__1nn->n_used__4name++), (((void)0)));
                                            goto ggg;
                                        }
                                        switch (__1nn->n_scope__4name) {
                                        case 14:
                                            if ((__3init == 0) && (__0this->n_sto__4name == 14))
                                                goto ggg;
                                        case 31:
                                            if (__1tbl == gtbl)
                                                __6sti = 1;
                                            else
                                                __5stct = 1;
                                        default:
                                            if (__3vec_seen && __3init) {
                                                if (1 < __3vec_seen) {
                                                    struct ea __0__V119;

                                                    struct ea __0__V120;

                                                    error__FiPCcRC2eaN33(
                                                        (int)'s',
                                                        (const char *)"Ir for multi-dimensional "
                                                                      "array%n ofOs ofC%tWK",
                                                        (const struct ea
                                                             *)(((&__0__V119)->__O1__2ea.p =
                                                                     ((const void *)__0this)),
                                                                (&__0__V119)),
                                                        (const struct ea
                                                             *)(((&__0__V120)->__O1__2ea.p =
                                                                     ((const void *)__5cl)),
                                                                (&__0__V120)),
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0);
                                                } else {
                                                    if (__6sti) {
                                                        if (sti_tbl == 0)
                                                            sti_tbl = __ct__5tableFsP5tableP4name(
                                                                (struct table *)0, (short)8, gtbl,
                                                                (struct name *)0);
                                                        const_save = 1;
                                                        ((void)co_array_init__FP4nameP5table(
                                                            __1nn, sti_tbl));

                                                        __0this->__O1__4expr.tp =
                                                            __1nn->__O1__4expr.tp;
                                                        const_save = 0;
                                                        __0this->__O3__4expr.n_initializer =
                                                            (__3init = 0);
                                                    } else {
                                                        __0this->__O3__4expr.n_initializer =
                                                            (__3init =
                                                                 co_array_init__FP4nameP5table(
                                                                     __1nn, __1tbl));

                                                        __0this->__O1__4expr.tp =
                                                            __1nn->__O1__4expr.tp;
                                                        if (__5stct)
                                                            __1nn->__O3__4expr.n_initializer =
                                                                (__0this->__O3__4expr
                                                                     .n_initializer =
                                                                     (__3init =
                                                                          __ct__4exprFUcP4exprT2(
                                                                              (struct expr *)0,
                                                                              (unsigned char)186,
                                                                              __3init,
                                                                              (struct expr *)0)));
                                                    }
                                                }
                                                goto ggg;
                                            }
                                            break;
                                        case 25:
                                        case 0:
                                            if (__0this->n_stclass__4name == 31) {
                                                if (__3vec_seen &&
                                                    __0this->__O3__4expr.n_initializer) {
                                                    if (1 < __3vec_seen) {
                                                        struct ea __0__V121;

                                                        struct ea __0__V122;

                                                        error__FiPCcRC2eaN33(
                                                            (int)'s',
                                                            (const char
                                                                 *)"Ir for multi-dimensional "
                                                                   "array%n ofOs ofC%tWK",
                                                            (const struct ea
                                                                 *)(((&__0__V121)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V121)),
                                                            (const struct ea
                                                                 *)(((&__0__V122)->__O1__2ea.p =
                                                                         ((const void *)__5cl)),
                                                                    (&__0__V122)),
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0);
                                                    } else {
                                                        if (sti_tbl == 0)
                                                            sti_tbl = __ct__5tableFsP5tableP4name(
                                                                (struct table *)0, (short)8, gtbl,
                                                                (struct name *)0);
                                                        const_save = 1;
                                                        ((void)co_array_init__FP4nameP5table(
                                                            __1nn, sti_tbl));

                                                        __0this->__O1__4expr.tp =
                                                            __1nn->__O1__4expr.tp;
                                                        const_save = 0;
                                                        __0this->__O3__4expr.n_initializer =
                                                            (__3init = 0);
                                                    }
                                                } else {
                                                    Pclass __9cl;

                                                    __9cl = (((struct classdef *)((
                                                        (struct classdef *)__1nn->__O4__4expr
                                                            .n_table->t_name__5table->__O1__4expr
                                                            .tp))));
                                                    if (__9cl->defined__4type & 01) {
                                                        __6sti = 1;
                                                        break;
                                                    }
                                                }
                                            }

                                            if (__3vec_seen) {
                                                Pname __8c;

                                                __8c = has_ictor__8classdefFv(__5cl);
                                                if (__8c == 0) {
                                                    struct ea __0__V123;

                                                    error__FPCcRC2eaN32(
                                                        (const char *)"array ofC%n that does not "
                                                                      "have aK taking noAs",
                                                        (const struct ea
                                                             *)(((&__0__V123)->__O1__2ea.p =
                                                                     ((const void *)__5cn)),
                                                                (&__0__V123)),
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0);
                                                } else {
                                                    Pname __9ctor;

                                                    __9ctor = (__5cl->c_ctor__8classdef);
                                                    if (__9ctor &&
                                                        (((!__1tbl->t_name__5table) ||
                                                          (!__1tbl->t_name__5table->__O1__4expr
                                                                .tp)) ||
                                                         (__1tbl->t_name__5table->__O1__4expr.tp
                                                              ->base__4node != 6))) {

                                                        Pexpr __10e;

                                                        __10e = call_ctor__FP5tableP4exprN22iT2(
                                                            __1tbl, (struct expr *)0,
                                                            (struct expr *)__9ctor,
                                                            (struct expr *)0, 44, (struct expr *)0);
                                                    }
                                                    if ((((struct fct *)((
                                                             (struct fct *)__8c->__O1__4expr.tp))))
                                                            ->nargs__3fct) {
                                                        if (!(__5cl->c_vtor__8classdef))
                                                            make_vec_ctor__8classdefFP4name(__5cl,
                                                                                            __8c);
                                                    }
                                                }
                                            }

                                        case 136:
                                            goto ggg;
                                        }

                                        const_save = 1;
                                        assign__4nameFv(__1nn);
                                        {
                                            Ptable __6otbl;

                                            __6otbl = __1tbl;
                                            if (__6sti) {
                                                if (sti_tbl == 0)
                                                    sti_tbl = __ct__5tableFsP5tableP4name(
                                                        (struct table *)0, (short)8, gtbl,
                                                        (struct name *)0);

                                                __1tbl = sti_tbl;
                                                if (__0this->n_sto__4name == 14)
                                                    __1nn->n_sto__4name =
                                                        (__0this->n_sto__4name = 0);
                                            }

                                            if (__3init) {
                                                if (__3init->base__4node == 157) {
                                                    switch (__3init->__O4__4expr.tp2->base__4node) {
                                                        struct classdef *__1__X171;

                                                        struct classdef *__1__X172;

                                                    case 6:
                                                        if (!((__1__X171 = (((struct classdef *)((
                                                                   (struct classdef *)__3init
                                                                       ->__O4__4expr.tp2))))),
                                                              ((__1__X172 = __5cl),
                                                               (((__1__X171 == __1__X172)
                                                                     ? 1
                                                                     : ((__1__X171 && __1__X172)
                                                                            ? (((int)
                                                                                    same_class__8classdefFP8classdefi(
                                                                                        __1__X171,
                                                                                        __1__X172,
                                                                                        0)))
                                                                            : 0))))))
                                                            goto inin;
                                                        break;
                                                    default: {
                                                        Pname __10n2;

                                                        struct classdef *__1__X173;

                                                        struct classdef *__1__X174;

                                                        __10n2 = is_cl_obj__4typeFv(
                                                            __3init->__O4__4expr.tp2);
                                                        if ((__10n2 == 0) ||
                                                            (!((__1__X173 = (((struct classdef *)((
                                                                    (struct classdef *)
                                                                        __10n2->__O1__4expr.tp))))),
                                                               ((__1__X174 = __5cl),
                                                                (((__1__X173 == __1__X174)
                                                                      ? 1
                                                                      : ((__1__X173 && __1__X174)
                                                                             ? (((int)
                                                                                     same_class__8classdefFP8classdefi(
                                                                                         __1__X173,
                                                                                         __1__X174,
                                                                                         0)))
                                                                             : 0)))))))
                                                            goto inin;
                                                    }
                                                    }

                                                    {
                                                        Pexpr __8ee;

                                                        __8ee = __3init->__O2__4expr.e1;
                                                        if (__8ee && (__3vec_seen == 0)) {
                                                            switch (__8ee->base__4node) {
                                                            case 109:
                                                                __3init = __8ee;
                                                                goto inin;
                                                            case 140:
                                                                if ((__8ee->__O2__4expr.e1
                                                                         ->base__4node == 109) &&
                                                                    (__8ee->__O3__4expr.e2 == 0)) {
                                                                    __3init = __8ee->__O2__4expr.e1;
                                                                    goto inin;
                                                                }
                                                            }
                                                        }

                                                        __3init->__O3__4expr.e2 = __6oo;
                                                        __3init =
                                                            typ__4exprFP5table(__3init, __1tbl);

                                                        if (__3init->base__4node == 147) {
                                                            switch (__3init->__O4__4expr.tp2
                                                                        ->base__4node) {
                                                                struct classdef *__1__X175;

                                                                struct classdef *__1__X176;

                                                            case 6:
                                                                if (!((__1__X175 = (((
                                                                           struct classdef *)((
                                                                           (struct classdef *)
                                                                               __3init->__O4__4expr
                                                                                   .tp2))))),
                                                                      ((__1__X176 = __5cl),
                                                                       (((__1__X175 == __1__X176)
                                                                             ? 1
                                                                             : ((__1__X175 &&
                                                                                 __1__X176)
                                                                                    ? (((int)same_class__8classdefFP8classdefi(
                                                                                          __1__X175,
                                                                                          __1__X176,
                                                                                          0)))
                                                                                    : 0))))))
                                                                    goto inin;
                                                                break;
                                                            default: {
                                                                Pname __11n2;

                                                                struct classdef *__1__X177;

                                                                struct classdef *__1__X178;

                                                                __11n2 = is_cl_obj__4typeFv(
                                                                    __3init->__O4__4expr.tp2);
                                                                if ((__11n2 == 0) ||
                                                                    (!((__1__X177 = (((
                                                                            struct classdef *)((
                                                                            (struct classdef *)
                                                                                __11n2->__O1__4expr
                                                                                    .tp))))),
                                                                       ((__1__X178 = __5cl),
                                                                        (((__1__X177 == __1__X178)
                                                                              ? 1
                                                                              : ((__1__X177 &&
                                                                                  __1__X178)
                                                                                     ? (((int)same_class__8classdefFP8classdefi(
                                                                                           __1__X177,
                                                                                           __1__X178,
                                                                                           0)))
                                                                                     : 0)))))))
                                                                    goto inin;
                                                            }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                inin:
                                                    __3init = typ__4exprFP5table(__3init, __1tbl);
                                                    if ((__3init->base__4node == 147) &&
                                                        (check__4typeFP4typeUcT2(
                                                             __1nn->__O1__4expr.tp,
                                                             __3init->__O1__4expr.tp,
                                                             (unsigned char)0,
                                                             (unsigned char)0) == 0))
                                                        ((void)replace_temp__FP4exprT1(
                                                            __3init, address__4exprFv(
                                                                         (struct expr *)__1nn)));
                                                    else
                                                        __3init =
                                                            class_init__FP4exprP4typeT1P5table(
                                                                (struct expr *)__1nn,
                                                                __1nn->__O1__4expr.tp, __3init,
                                                                __1tbl);
                                                }
                                            } else if (__3vec_seen == 0) {
                                                struct texpr *__0__X179;

                                                __3init =
                                                    (struct expr
                                                         *)((__0__X179 = 0),
                                                            (((__0__X179 ||
                                                               (__0__X179 = (struct texpr *)
                                                                    __nw__4exprSFUl((size_t)(sizeof(
                                                                        struct texpr)))))
                                                                  ? ((__0__X179 = (struct texpr *)
                                                                          __ct__4exprFUcP4exprT2(
                                                                              ((struct expr *)
                                                                                   __0__X179),
                                                                              ((unsigned char)157),
                                                                              ((struct expr *)0),
                                                                              (struct expr *)0)),
                                                                     (__0__X179->__O4__4expr.tp2 =
                                                                          ((struct type *)__5cl)))
                                                                  : 0),
                                                             __0__X179));
                                                __3init->__O3__4expr.e2 = __6oo;
                                                __3init = typ__4exprFP5table(__3init, __1tbl);
                                            }

                                            {
                                                Pname __6c;
                                                if (__3vec_seen) {
                                                    __6c = has_ictor__8classdefFv(__5cl);
                                                    if (__6c == 0) {
                                                        struct ea __0__V124;

                                                        error__FPCcRC2eaN32(
                                                            (const char *)"array ofC%n that does "
                                                                          "not have aK taking noAs",
                                                            (const struct ea
                                                                 *)(((&__0__V124)->__O1__2ea.p =
                                                                         ((const void *)__5cn)),
                                                                    (&__0__V124)),
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0);
                                                    } else {
                                                        Pname __8ctor;

                                                        __8ctor = (__5cl->c_ctor__8classdef);
                                                        if (__8ctor &&
                                                            (((!__1tbl->t_name__5table) ||
                                                              (!__1tbl->t_name__5table->__O1__4expr
                                                                    .tp)) ||
                                                             (__1tbl->t_name__5table->__O1__4expr
                                                                  .tp->base__4node != 6))) {

                                                            Pexpr __9e;

                                                            __9e = call_ctor__FP5tableP4exprN22iT2(
                                                                __1tbl, (struct expr *)0,
                                                                (struct expr *)__8ctor,
                                                                (struct expr *)0, 44,
                                                                (struct expr *)0);
                                                        }
                                                        if ((((struct fct *)((
                                                                 (struct fct *)
                                                                     __6c->__O1__4expr.tp))))
                                                                ->nargs__3fct) {
                                                            if (!(__5cl->c_vtor__8classdef))
                                                                make_vec_ctor__8classdefFP4name(
                                                                    __5cl, __6c);
                                                        }
                                                    }
                                                }

                                                if (__5stct) {
                                                    if ((__1tbl != gtbl) &&
                                                        (__1nn->n_sto__4name == 14)) {
                                                        {
                                                            struct ea __0__V125;

                                                            error__FP3locPCcRC2eaN33(
                                                                &__0this->where__4name,
                                                                (const char *)"Id local extern%n",
                                                                (const struct ea
                                                                     *)(((&__0__V125)->__O1__2ea.p =
                                                                             ((const void *)
                                                                                  __0this)),
                                                                        (&__0__V125)),
                                                                (const struct ea *)ea0,
                                                                (const struct ea *)ea0,
                                                                (const struct ea *)ea0);
                                                            __3init = 0;
                                                        }
                                                    } else if (__3init) {
                                                        if ((__3init->base__4node == 111) &&
                                                            (__3init->__O2__4expr.e1->base__4node ==
                                                             146))
                                                            __3init->base__4node = 186;
                                                        else {
                                                            __3init = __ct__4exprFUcP4exprT2(
                                                                (struct expr *)0, (unsigned char)70,
                                                                (struct expr *)__1nn, __3init);
                                                            __3init->__O1__4expr.tp =
                                                                __3init->__O2__4expr.e1->__O1__4expr
                                                                    .tp;
                                                            __3init = __ct__4exprFUcP4exprT2(
                                                                (struct expr *)0,
                                                                (unsigned char)186, __3init,
                                                                (struct expr *)0);
                                                            __3init->__O1__4expr.tp =
                                                                __3init->__O2__4expr.e1->__O1__4expr
                                                                    .tp;
                                                        }
                                                    } else {
                                                        if ((__0this->__O1__4expr.tp->base__4node ==
                                                             110) &&
                                                            (((struct vec *)((
                                                                 (struct vec *)
                                                                     __0this->__O1__4expr.tp))))
                                                                ->size__3vec) {
                                                            if (1 < __3vec_seen) {
                                                                struct ea __0__V126;

                                                                error__FiPCcRC2eaN33(
                                                                    (int)'s',
                                                                    (const char
                                                                         *)"implicit staticIr for "
                                                                           "multi-dimensional "
                                                                           "array ofOs ofC%tWK",
                                                                    (const struct ea
                                                                         *)(((&__0__V126)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __5cl)),
                                                                            (&__0__V126)),
                                                                    (const struct ea *)ea0,
                                                                    (const struct ea *)ea0,
                                                                    (const struct ea *)ea0);
                                                            } else {
                                                                Pexpr __10ilist;

                                                                __10ilist = 0;
                                                                {
                                                                    {
                                                                        int __10i;

                                                                        __10i =
                                                                            (((struct vec *)((
                                                                                 (struct vec
                                                                                      *)__0this
                                                                                     ->__O1__4expr
                                                                                     .tp))))
                                                                                ->size__3vec;

                                                                        for (; __10i > 0; __10i--) {
                                                                            Pexpr __11e;

                                                                            struct texpr *__0__X180;

                                                                            __11e =
                                                                                (struct expr
                                                                                     *)((__0__X180 =
                                                                                             0),
                                                                                        (((__0__X180 ||
                                                                                           (__0__X180 = (struct
                                                                                                         texpr
                                                                                                             *)
                                                                                                __nw__4exprSFUl((
                                                                                                    size_t)(sizeof(
                                                                                                    struct
                                                                                                    texpr)))))
                                                                                              ? ((__0__X180 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                                                                      ((struct
                                                                                                        expr
                                                                                                            *)
                                                                                                           __0__X180),
                                                                                                      ((unsigned char)157),
                                                                                                      ((struct
                                                                                                        expr
                                                                                                            *)0),
                                                                                                      (struct
                                                                                                       expr
                                                                                                           *)0)),
                                                                                                 (__0__X180
                                                                                                      ->__O4__4expr
                                                                                                      .tp2 =
                                                                                                      ((struct
                                                                                                        type
                                                                                                            *)
                                                                                                           __5cl)))
                                                                                              : 0),
                                                                                         __0__X180));
                                                                            __10ilist =
                                                                                __ct__4exprFUcP4exprT2(
                                                                                    (struct expr
                                                                                         *)0,
                                                                                    (unsigned char)140,
                                                                                    __11e,
                                                                                    __10ilist);
                                                                        }
                                                                        __1nn->__O3__4expr
                                                                            .n_initializer =
                                                                            __ct__4exprFUcP4exprT2(
                                                                                (struct expr *)0,
                                                                                (unsigned char)124,
                                                                                __10ilist,
                                                                                (struct expr *)0);
                                                                        __3init =
                                                                            co_array_init__FP4nameP5table(
                                                                                __1nn, __1tbl);

                                                                        __0this->__O1__4expr.tp =
                                                                            __1nn->__O1__4expr.tp;

                                                                        __1nn->__O3__4expr
                                                                            .n_initializer =
                                                                            (__0this->__O3__4expr
                                                                                 .n_initializer =
                                                                                 (__3init = __ct__4exprFUcP4exprT2(
                                                                                      (struct expr
                                                                                           *)0,
                                                                                      (unsigned char)186,
                                                                                      __3init,
                                                                                      (struct expr
                                                                                           *)0)));
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            struct ea __0__V127;

                                                            struct ea __0__V128;

                                                            error__FiPCcRC2eaN33(
                                                                (int)'s',
                                                                (const char
                                                                     *)"local staticC%n (%t)",
                                                                (const struct ea
                                                                     *)(((&__0__V127)->__O1__2ea.p =
                                                                             ((const void *)
                                                                                  __0this)),
                                                                        (&__0__V127)),
                                                                (const struct ea *)__ct__2eaFPCv(
                                                                    &__0__V128,
                                                                    (const void *)
                                                                        __0this->__O1__4expr.tp),
                                                                (const struct ea *)ea0,
                                                                (const struct ea *)ea0);
                                                        }
                                                    }
                                                }

                                                if (__6sti) {
                                                    if (__3vec_seen) {
                                                        if ((__0this->n_stclass__4name == 31) &&
                                                            __0this->__O3__4expr.n_initializer) {
                                                            const_save = 1;
                                                            ((void)co_array_init__FP4nameP5table(
                                                                __1nn, sti_tbl));

                                                            __0this->__O1__4expr.tp =
                                                                __1nn->__O1__4expr.tp;
                                                            const_save = 0;
                                                            __0this->__O3__4expr.n_initializer =
                                                                (__3init = 0);
                                                            goto ggg;
                                                        }

                                                        {
                                                            Pname __8vctor;

                                                            __8vctor = (__5cl->c_vtor__8classdef);
                                                            __3init =
                                                                cdvec__FP4nameP4exprP8classdefT1iN22(
                                                                    vec_new_fct,
                                                                    (struct expr *)__1nn, __5cl,
                                                                    __8vctor ? __8vctor : __6c, -1,
                                                                    (struct expr *)0,
                                                                    (struct expr *)0);
                                                            __3init->__O1__4expr.tp =
                                                                (struct type *)any_type;
                                                        }
                                                    } else {
                                                        switch (__3init->base__4node) {
                                                        case 111:
                                                            if (__3init->__O2__4expr.e1
                                                                    ->base__4node == 146) {
                                                                Pname __10fn;

                                                                __10fn = __3init->__O2__4expr.e1
                                                                             ->__O4__4expr.fct_name;
                                                                if ((__10fn == 0) ||
                                                                    (__10fn->n_oper__4name != 161))
                                                                    goto as;
                                                                __3init = __3init->__O2__4expr.e1;
                                                                break;
                                                            }
                                                            goto as;
                                                        case 147:
                                                            __3init = __3init->__O2__4expr.e1;

                                                            if (__3init->__O1__4expr.tp == 0)
                                                                __3init->__O1__4expr.tp =
                                                                    (struct type *)any_type;
                                                            break;
                                                        case 70:
                                                            if (__3init->__O2__4expr.e1 ==
                                                                (((struct expr *)__1nn)))
                                                                break;
                                                        as:
                                                        default:
                                                            __3init = __ct__4exprFUcP4exprT2(
                                                                (struct expr *)0, (unsigned char)70,
                                                                (struct expr *)__1nn, __3init);
                                                        }
                                                    }
                                                    {
                                                        Pstmt __7ist;

                                                        struct estmt *__0__X181;

                                                        struct loc __2__X182;

                                                        __7ist =
                                                            (struct stmt
                                                                 *)((__0__X181 = 0),
                                                                    ((__2__X182 =
                                                                          __1nn->where__4name),
                                                                     (((__0__X181 ||
                                                                        (__0__X181 = (struct estmt
                                                                                          *)
                                                                             __nw__4stmtSFUl((
                                                                                 size_t)(sizeof(
                                                                                 struct estmt)))))
                                                                           ? ((__0__X181 = (struct
                                                                                            estmt *)
                                                                                   __ct__4stmtFUc3locP4stmt(
                                                                                       ((struct stmt
                                                                                             *)
                                                                                            __0__X181),
                                                                                       ((unsigned char)72),
                                                                                       __2__X182,
                                                                                       ((struct stmt
                                                                                             *)0))),
                                                                              (__0__X181
                                                                                   ->__O2__4stmt.e =
                                                                                   __3init))
                                                                           : 0),
                                                                      __0__X181)));

                                                        if (st_ilist == 0)
                                                            st_ilist = __7ist;
                                                        else
                                                            itail->s_list__4stmt = __7ist;
                                                        itail = __7ist;
                                                        __3init = 0;
                                                    }
                                                }
                                                __1nn->__O3__4expr.n_initializer =
                                                    (__0this->__O3__4expr.n_initializer = __3init);
                                                const_save = __3const_old;
                                                __1tbl = __6otbl;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if (__3init == 0)
                            goto str;
                        else if (((((unsigned char)((__5cl->csu__8classdef == 6)
                                                        ? 0
                                                        : (((int)__5cl->csu__8classdef)))))) &&
                                 (__5cl->csu__8classdef != 167)) {

                            __3init = typ__4exprFP5table(__3init, __1tbl);
                            if ((check__4typeFP4typeUcT2(__1nn->__O1__4expr.tp,
                                                         __3init->__O1__4expr.tp, (unsigned char)0,
                                                         (unsigned char)0) == 0) &&
                                (__3init->base__4node == 147))
                                ((void)replace_temp__FP4exprT1(
                                    __3init, address__4exprFv((struct expr *)__1nn)));
                            else
                                goto str;
                        } else if (__3init->base__4node == 124) {
                            {
                                struct ea __0__V129;

                                struct ea __0__V130;

                                error__FPCcRC2eaN32(
                                    (const char *)"cannotI%nWIrL because class %s has private or "
                                                  "protected members",
                                    (const struct ea *)(((&__0__V129)->__O1__2ea.p =
                                                             ((const void *)__1nn)),
                                                        (&__0__V129)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V130, (const void *)__5cl->string__8classdef),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                        } else {
                            __3init = typ__4exprFP5table(__3init, __1tbl);
                            if (check__4typeFP4typeUcT2(__1nn->__O1__4expr.tp,
                                                        __3init->__O1__4expr.tp, (unsigned char)0,
                                                        (unsigned char)0) == 0) {

                                if (__3init->base__4node == 147)
                                    ((void)replace_temp__FP4exprT1(
                                        __3init, address__4exprFv((struct expr *)__1nn)));
                                else
                                    goto str;
                            }
                            goto str;
                        }
                        break;
                    }

                    case 110:
                        __3t = (((struct vec *)(((struct vec *)__3t))))->typ__5pvtyp;
                        __3vec_seen++;
                        assign__4nameFv(__1nn);
                        goto lll;

                    case 97:
                        if ((__3init == 0) &&
                            (((struct basetype *)(((struct basetype *)__3t))))->b_const__4type) {
                            switch (__0this->n_scope__4name) {
                            case 136:
                                break;

                            case 0:
                            case 25:
                                if (cc->cot__11dcl_context)
                                    break;
                            default: {
                                Pname __7n;
                                Pclass __7cl;

                                __7n = is_cl_obj__4typeFv(__3t);

                                if (__7n)
                                    __7cl = (((struct classdef *)((
                                        (struct classdef *)__7n->__O1__4expr.tp))));

                                if ((__0this->n_sto__4name != 14) &&
                                    ((__7n == 0) ||
                                     (((__7cl->c_ctor__8classdef) == 0) &&
                                      (is_empty__FP8classdefUc(__7cl, (unsigned char)1) == 0)))) {
                                    struct ea __0__V131;

                                    error__FPCcRC2eaN32(
                                        (const char *)"uninitialized const%n",
                                        (const struct ea *)(((&__0__V131)->__O1__2ea.p =
                                                                 ((const void *)__0this)),
                                                            (&__0__V131)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                            }
                            }
                        }
                        __3t = skiptypedefs__4typeFRUc(__3t, (bit *)(&__3td_const));
                        goto lll;

                    case 158:
                        if (__3init) {
                            if (__1nn->n_scope__4name == 136)
                                break;
                            if ((((struct ptr *)(((struct ptr *)__1nn->__O1__4expr.tp))))
                                    ->memof__3ptr) {
                                struct ea __0__V132;

                                struct ea __0__V133;

                                error__FPCcRC2eaN32(
                                    (const char *)"R toCM%n ofT%t illegal",
                                    (const struct ea *)(((&__0__V132)->__O1__2ea.p =
                                                             ((const void *)__1nn)),
                                                        (&__0__V132)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V133, (const void *)__1nn->__O1__4expr.tp),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            ref_initializer++;
                            __3init = typ__4exprFP5table(__3init, __1tbl);
                            ref_initializer--;
                            Nvirt = 0;

                            __1nn->__O3__4expr.n_initializer =
                                (__0this->__O3__4expr.n_initializer =
                                     (__3init = ref_init__FP3ptrP4exprP5table(
                                          ((struct ptr *)(((struct ptr *)__3t))), __3init,
                                          __1tbl)));

                            if (Nvirt == 77)
                                __1sti_vb = 1;
                            assign__4nameFv(__1nn);

                            if ((__3init->base__4node == 124) && (__3init->__O3__4expr.e2 == 0)) {
                                new_list__FP4expr(__3init);
                                list_check__FP4nameP4typeP4exprP5table(__1nn, __1nn->__O1__4expr.tp,
                                                                       (struct expr *)0, __1tbl);
                                if (next_elem__Fv())
                                    error__FP3locPCcRC2eaN33(
                                        &__0this->where__4name, (const char *)"IrL too long",
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                            }

                        } else {
                            switch (__1nn->n_scope__4name) {
                            default:
                                if (__0this->n_sto__4name != 14) {
                                    struct ea __0__V134;

                                    error__FPCcRC2eaN32(
                                        (const char *)"uninitializedR%n",
                                        (const struct ea *)(((&__0__V134)->__O1__2ea.p =
                                                                 ((const void *)__0this)),
                                                            (&__0__V134)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                            case 136:
                                break;
                            case 25:
                            case 0:
                                if (cc->cot__11dcl_context == 0) {
                                    struct ea __0__V135;

                                    error__FPCcRC2eaN32(
                                        (const char *)"uninitializedR%n",
                                        (const struct ea *)(((&__0__V135)->__O1__2ea.p =
                                                                 ((const void *)__0this)),
                                                            (&__0__V135)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                                break;
                            }
                        }
                        goto stgg;
                    default:
                    str:
                        if (__3init == 0) {
                            switch (__0this->n_scope__4name) {
                            case 136:
                                break;
                            case 0:
                            case 25:
                                if (cc->cot__11dcl_context)
                                    break;
                            default:
                                if ((__0this->n_sto__4name != 14) && tconst__4typeFv(__3t)) {
                                    struct ea __0__V136;

                                    error__FPCcRC2eaN32(
                                        (const char *)"uninitialized const%n",
                                        (const struct ea *)(((&__0__V136)->__O1__2ea.p =
                                                                 ((const void *)__0this)),
                                                            (&__0__V136)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                            }

                            break;
                        }

                        const_save = ((const_save || (__0this->n_scope__4name == 136)) ||
                                      (tconst__4typeFv(__3t) && (vec_const == 0)));

                        if (__0this->n_sto__4name == 31)
                            stat_init++;
                        __1nn->__O3__4expr.n_initializer =
                            (__0this->__O3__4expr.n_initializer =
                                 (__3init = typ__4exprFP5table(__3init, __1tbl)));
                        if (__0this->n_sto__4name == 31)
                            stat_init--;

                        if (const_save || __3td_const)
                            __3init->permanent__4node = 1;
                        assign__4nameFv(__1nn);
                        const_save = __3const_old;
                        switch (__3init->base__4node) {
                        case 124:
                            if (__3init->__O3__4expr.e2)
                                goto dfdf;
                            new_list__FP4expr(__3init);
                            list_check__FP4nameP4typeP4exprP5table(__1nn, __1nn->__O1__4expr.tp,
                                                                   (struct expr *)0, __1tbl);
                            if (next_elem__Fv())
                                error__FP3locPCcRC2eaN33(
                                    &__0this->where__4name, (const char *)"IrL too long",
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            break;
                        case 81: {
                            Ptype __6v;

                            __6v = skiptypedefs__4typeFv(__1nn->__O1__4expr.tp);
                            if (__6v->base__4node == 110) {
                                Ptype __7vv;

                                __7vv = skiptypedefs__4typeFv(
                                    (((struct vec *)(((struct vec *)__6v))))->typ__5pvtyp);
                                if (__7vv->base__4node == 5) {
                                    int __8sz;
                                    int __8isz;

                                    __8sz = (((struct vec *)(((struct vec *)__6v))))->size__3vec;
                                    __8isz =
                                        (((struct vec *)(((struct vec *)__3init->__O1__4expr.tp))))
                                            ->size__3vec;
                                    if (__8sz == 0)
                                        (((struct vec *)(((struct vec *)__6v))))->size__3vec =
                                            __8isz;
                                    else if (__8sz < __8isz) {
                                        struct ea __0__V137;

                                        struct ea __0__V138;

                                        struct ea __0__V139;

                                        error__FP3locPCcRC2eaN33(
                                            &__0this->where__4name,
                                            (const char *)"Ir too long (%d characters) for%n[%d]",
                                            (const struct ea *)(((((&__0__V137)->__O1__2ea.i =
                                                                       ((unsigned long)__8isz)),
                                                                  0)),
                                                                (&__0__V137)),
                                            (const struct ea *)(((&__0__V138)->__O1__2ea.p =
                                                                     ((const void *)__1nn)),
                                                                (&__0__V138)),
                                            (const struct ea *)(((((&__0__V139)->__O1__2ea.i =
                                                                       ((unsigned long)__8sz)),
                                                                  0)),
                                                                (&__0__V139)),
                                            (const struct ea *)ea0);
                                    }
                                    break;
                                }
                            }
                        }
                        default:
                        dfdf: {
                            bit __6ntc;
                            Ptype __6nt;

                            __6ntc = 0;
                            __6nt =
                                skiptypedefs__4typeFRUc(__1nn->__O1__4expr.tp, (bit *)(&__6ntc));

                            if (__3vec_seen) {
                                {
                                    struct ea __0__V140;

                                    error__FPCcRC2eaN32(
                                        (const char *)"badIr for array%n",
                                        (const struct ea *)(((&__0__V140)->__O1__2ea.p =
                                                                 ((const void *)__1nn)),
                                                            (&__0__V140)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    break;
                                }
                            }

                            {
                                Ptype __6it;

                                __6it = skiptypedefs__4typeFv(__3init->__O1__4expr.tp);
                                switch (__6nt->base__4node) {
                                case 21:
                                case 5:
                                case 29:
                                case 121:
                                    switch (__6it->base__4node) {
                                    case 22:
                                    case 122:
                                    case 15:
                                    case 11:
                                    case 181: {
                                        struct ea __0__V141;

                                        struct ea __0__V142;

                                        error__FiPCcRC2eaN33(
                                            (int)'w', (const char *)"%tIdW%t",
                                            (const struct ea *)(((&__0__V141)->__O1__2ea.p =
                                                                     ((const void *)__6nt)),
                                                                (&__0__V141)),
                                            (const struct ea *)__ct__2eaFPCv(
                                                &__0__V142, (const void *)__3init->__O1__4expr.tp),
                                            (const struct ea *)ea0, (const struct ea *)ea0);
                                    }
                                    }

                                case 22:
                                case 122: {
                                    if (((((struct basetype *)(((struct basetype *)__6nt))))
                                             ->b_unsigned__8basetype &&
                                         (__3init->base__4node == 107)) &&
                                        (__3init->__O3__4expr.e2->base__4node == 82)) {
                                        struct ea __0__V143;

                                        error__FiPCcRC2eaN33(
                                            (int)'w', (const char *)"negativeIr for unsigned%n",
                                            (const struct ea *)(((&__0__V143)->__O1__2ea.p =
                                                                     ((const void *)__1nn)),
                                                                (&__0__V143)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                    }
                                    if (__6nt->base__4node != 121) {
                                        switch (__6it->base__4node) {
                                            struct texpr *__0__X183;

                                        case 29:
                                        case 21:
                                        case 22:
                                        case 122:
                                            if (tsizeof__4typeFi(__6nt, 0) <
                                                tsizeof__4typeFi(__6it, 0))
                                                __3init =
                                                    (struct expr
                                                         *)((__0__X183 = 0),
                                                            (((__0__X183 ||
                                                               (__0__X183 = (struct texpr *)
                                                                    __nw__4exprSFUl((size_t)(sizeof(
                                                                        struct texpr)))))
                                                                  ? ((__0__X183 = (struct texpr *)
                                                                          __ct__4exprFUcP4exprT2(
                                                                              ((struct expr *)
                                                                                   __0__X183),
                                                                              ((unsigned char)191),
                                                                              __3init,
                                                                              (struct expr *)0)),
                                                                     (__0__X183->__O4__4expr.tp2 =
                                                                          __6nt))
                                                                  : 0),
                                                             __0__X183));
                                            __3init = typ__4exprFP5table(__3init, __1tbl);
                                        }
                                    }

                                    Neval = 0;
                                    {
                                        long long __8i;

                                        __8i = eval__4exprFv(__3init);
                                        if (((Neval == 0) && __6ntc) && (__1scope != 136)) {
                                            __1nn->n_evaluated__4name =
                                                (__0this->n_evaluated__4name = 1);
                                            __1nn->n_val__4name = (__0this->n_val__4name = __8i);
                                            __1nn->__O3__4expr.n_initializer =
                                                (__0this->__O3__4expr.n_initializer = 0);
                                        }
                                        break;
                                    }
                                }

                                case 125:
                                    Nvirt = 0;

                                    __1nn->__O3__4expr.n_initializer =
                                        (__0this->__O3__4expr.n_initializer =
                                             (__3init = ptr_init__FP3ptrP4exprP5table(
                                                  ((struct ptr *)(((struct ptr *)__6nt))), __3init,
                                                  __1tbl)));
                                    if (Nvirt == 77)
                                        __1sti_vb = 1;
                                    if (Pchecked)
                                        goto stgg;
                                }

                                {
                                    Pexpr __7x;

                                    __7x = try_to_coerce__FP4typeP4exprPCcP5table(
                                        __6nt, __3init, (const char *)"initializer", __1tbl);
                                    if (__7x) {
                                        __1nn->__O3__4expr.n_initializer =
                                            (__0this->__O3__4expr.n_initializer = (__3init = __7x));
                                        goto stgg;
                                    }
                                }
                                {
                                    int __6ct;
                                    Pname __6c1;
                                    Pname __6c2;

                                    register struct type *__0__X187;

                                    struct type *__1__Xt00anx4xs1bwcog;

                                    __6ct = no_const;
                                    __6c1 = is_cl_obj__4typeFv(__6nt);
                                    __6c2 = is_cl_obj__4typeFv(__3init->__O1__4expr.tp);
                                    if ((__6c1 && __6c2) &&
                                        has_base__8classdefFP8classdefiT2(
                                            ((struct classdef *)((
                                                (struct classdef *)__6c2->__O1__4expr.tp))),
                                            ((struct classdef *)((
                                                (struct classdef *)__6c1->__O1__4expr.tp))),
                                            0, 0)) {
                                        struct texpr *__0__X184;

                                        struct type *__2__X185;

                                        struct expr *__2__X186;

                                        __3init =
                                            (struct expr
                                                 *)((__0__X184 = 0),
                                                    ((__2__X185 =
                                                          (struct type *)__ct__3ptrFUcP4type(
                                                              (struct ptr *)0, (unsigned char)125,
                                                              __6nt)),
                                                     ((__2__X186 = address__4exprFv(__3init)),
                                                      (((__0__X184 ||
                                                         (__0__X184 =
                                                              (struct texpr *)__nw__4exprSFUl(
                                                                  (unsigned long)(sizeof(
                                                                      struct texpr)))))
                                                            ? ((__0__X184 = (struct texpr *)
                                                                    __ct__4exprFUcP4exprT2(
                                                                        ((struct expr *)__0__X184),
                                                                        ((unsigned char)191),
                                                                        __2__X186,
                                                                        (struct expr *)0)),
                                                               (__0__X184->__O4__4expr.tp2 =
                                                                    __2__X185))
                                                            : 0),
                                                       __0__X184))));
                                        __3init = typ__4exprFP5table(__3init, __1tbl);

                                        __1nn->__O3__4expr.n_initializer =
                                            (__0this->__O3__4expr.n_initializer =
                                                 (__3init = contents__4exprFv(__3init)));
                                        goto stgg;
                                    }

                                    if (((__0__X187 = __3init->__O1__4expr.tp),
                                         ((__1__Xt00anx4xs1bwcog =
                                               skiptypedefs__4typeFv(__0__X187)),
                                          (((__1__Xt00anx4xs1bwcog->base__4node == 125)
                                                ? ((__1__Xt00anx4xs1bwcog = skiptypedefs__4typeFv(
                                                        (((struct ptr *)((
                                                             (struct ptr *)__1__Xt00anx4xs1bwcog))))
                                                            ->typ__5pvtyp)),
                                                   0)
                                                : 0),
                                           (((unsigned char)((__1__Xt00anx4xs1bwcog->base__4node ==
                                                              ((unsigned char)76))
                                                                 ? 1
                                                                 : 0))))))) {
                                        struct ea __0__V144;

                                        struct ea __0__V145;

                                        error__FPCcRC2eaN32(
                                            (const char *)"badIrT &overloaded function for%n (%tX)",
                                            (const struct ea *)(((&__0__V144)->__O1__2ea.p =
                                                                     ((const void *)__0this)),
                                                                (&__0__V144)),
                                            (const struct ea *)__ct__2eaFPCv(
                                                &__0__V145, (const void *)__1nn->__O1__4expr.tp),
                                            (const struct ea *)ea0, (const struct ea *)ea0);
                                    } else if (check__4typeFP4typeUcT2(
                                                   __6nt, __3init->__O1__4expr.tp,
                                                   (unsigned char)70, (unsigned char)0)) {

                                        const void *__2__X188;

                                        {
                                            struct ea __0__V146;

                                            struct ea __0__V147;

                                            struct ea __0__V148;

                                            error__FiPCcRC2eaN33(
                                                (int)'e', (const char *)"badIrT%t for%n (%tX)",
                                                (const struct ea
                                                     *)((__2__X188 =
                                                             (const void *)__3init->__O1__4expr.tp),
                                                        (((&__0__V146)->__O1__2ea.p = __2__X188),
                                                         (&__0__V146))),
                                                (const struct ea *)(((&__0__V147)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V147)),
                                                (const struct ea *)__ct__2eaFPCv(
                                                    &__0__V148,
                                                    (const void *)__1nn->__O1__4expr.tp),
                                                (const struct ea *)ea0);
                                            if (__6ct)
                                                error__FiPCc(
                                                    (int)'c',
                                                    (const char
                                                         *)" (no usable const conversion)\n");
                                            else
                                                error__FiPCc((int)'c', (const char *)"\n");
                                            break;
                                        }
                                    }
                                }
                            }
                        }

                        stgg:
                            if ((__3init && (__0this->n_stclass__4name == 31)) &&
                                (__1sti_vb || (need_sti__FP4exprP5tableUc(
                                                   __3init, (struct table *)0, (unsigned char)0) &&
                                               check_static_pt__FP4name(__1nn)))) {
                                int __6local;

                                __6local = (0 < __0this->lex_level__4name);
                                if (__6local == 0)
                                    need_sti__FP4exprP5tableUc(__3init, __1tbl, (unsigned char)0);

                                {
                                    Pptr __6r;

                                    __6r = is_ref__4typeFv(__1nn->__O1__4expr.tp);

                                    if (__6r && (!is_ptr_or_ref__4typeFv(__3init->__O1__4expr.tp)))
                                        __3init = address__4exprFv(__3init);
                                    __3init =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                               (struct expr *)__1nn, __3init);
                                    if (__6r)
                                        __3init->__O1__4expr.tp = __1nn->__O1__4expr.tp;
                                    else if (__1nn->__O1__4expr.tp != __3init->__O1__4expr.tp) {
                                        TOK __7t;

                                        __7t = set_const__4typeFUc(__1nn->__O1__4expr.tp,
                                                                   (unsigned char)0);
                                        __3init = typ__4exprFP5table(__3init, __1tbl);
                                        set_const__4typeFUc(__1nn->__O1__4expr.tp, __7t);
                                    }

                                    if (dtpt_opt && (dinst_body__4nameFv(__1nn) == 0)) {
                                        __1nn->__O3__4expr.n_initializer =
                                            (__0this->__O3__4expr.n_initializer = (__3init = 0));
                                        break;
                                    }

                                    if (__6local) {
                                        if (__3init->base__4node != 70)
                                            error__FiPCc(
                                                (int)'s',
                                                (const char
                                                     *)"Ir for local static too complicated");
                                        if (__1nn->n_sto__4name == 14) {
                                            {
                                                struct ea __0__V149;

                                                error__FP3locPCcRC2eaN33(
                                                    &__0this->where__4name,
                                                    (const char *)"Id local extern%n",
                                                    (const struct ea *)(((&__0__V149)->__O1__2ea.p =
                                                                             ((const void *)
                                                                                  __0this)),
                                                                        (&__0__V149)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                                                __3init = 0;
                                            }
                                        } else
                                            __3init->base__4node = 186;
                                        __1nn->__O3__4expr.n_initializer =
                                            (__0this->__O3__4expr.n_initializer = __3init);
                                    } else {
                                        Pstmt __7ist;

                                        struct estmt *__0__X189;

                                        struct loc __2__X190;

                                        __7ist =
                                            (struct stmt
                                                 *)((__0__X189 = 0),
                                                    ((__2__X190 = __1nn->where__4name),
                                                     (((__0__X189 ||
                                                        (__0__X189 =
                                                             (struct estmt *)__nw__4stmtSFUl(
                                                                 (size_t)(sizeof(struct estmt)))))
                                                           ? ((__0__X189 = (struct estmt *)
                                                                   __ct__4stmtFUc3locP4stmt(
                                                                       ((struct stmt *)__0__X189),
                                                                       ((unsigned char)72),
                                                                       __2__X190,
                                                                       ((struct stmt *)0))),
                                                              (__0__X189->__O2__4stmt.e = __3init))
                                                           : 0),
                                                      __0__X189)));

                                        if (st_ilist == 0)
                                            st_ilist = __7ist;
                                        else
                                            itail->s_list__4stmt = __7ist;
                                        itail = __7ist;

                                        __1nn->__O3__4expr.n_initializer =
                                            (__0this->__O3__4expr.n_initializer = (__3init = 0));
                                        __1nn->n_val__4name = (__0this->n_val__4name = 1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        ggg:
            __1nn->permanent__4node = 1;
            switch (__0this->n_scope__4name) {
            case 108:
                __1nn->__O3__4expr.n_initializer = __0this->__O3__4expr.n_initializer;
                break;
            default: {
                Ptype __3t;

                __3t = __1nn->__O1__4expr.tp;
            px:
                __3t->permanent__4node = 1;
                switch (__3t->base__4node) {
                case 125:
                case 158:
                case 110:
                    __3t = (((struct ptr *)(((struct ptr *)__3t))))->typ__5pvtyp;

                    goto px;
                case 97:
                    __3t = (((struct basetype *)(((struct basetype *)__3t))))
                               ->b_name__8basetype->__O1__4expr.tp;

                    goto px;
                case 108:
                    __3t = (((struct fct *)(((struct fct *)__3t))))->returns__3fct;

                    goto px;
                }
            }
            }

            Cdcl = __1odcl;
            return __1nn;
        }
    }
}

extern int sprintf(char *, const char *, ...);

char *make_nested_name__FPCcP8classdef(const char *__1s, Pclass __1cl) {

    const char *__1str_arr[9];
    int __1size_arr[9];
    int __1cnt;
    int __1size;

    __1cnt = 1;
    __1size = 4;

    (__1str_arr[0]) = __1s;
    __1size += ((__1size_arr[0]) = strlen(__1s));

    {
        {
            Pclass __1nc;

            __1nc = __1cl;

            for (; __1nc && (__1nc->lex_level__4type == __1cl->lex_level__4type);
                 __1nc = __1nc->in_class__4type) {
                if (__1cnt > 8) {
                    struct ea __0__V191;

                    error__FiPCcRC2eaN33(
                        (int)'s', (const char *)"nested depth class beyond %d unsupported",
                        (const struct ea *)(((((&__0__V191)->__O1__2ea.i = ((unsigned long)9)), 0)),
                                            (&__0__V191)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                __1size += ((__1size_arr[__1cnt]) = __1nc->c_strlen__8classdef);
                (__1str_arr[__1cnt]) =
                    (__1nc->local_sig__4type ? (((const char *)__1nc->local_sig__4type))
                                             : __1nc->string__8classdef);
                ++__1cnt;
            }

            {
                int __1i;

                __1i = 0;
                for (__1i = 0; __1i < __1cnt; __1i++)
                    __1size +=
                        (((__1size_arr[__1i]) > 99) ? 3 : (((__1size_arr[__1i]) < 10) ? 1 : 2));

                {
                    char *__1result;

                    __1result = (((char *)__nw__FUl((size_t)((sizeof(char)) * __1size))));
                    sprintf(__1result, (const char *)"Q%d_", __1cnt);
                    __1size = 3;
                    for (__1i = __1cnt; __1i; __1i--) {
                        sprintf(__1result + __1size, (const char *)"%d%s", __1size_arr[(__1i - 1)],
                                __1str_arr[(__1i - 1)]);
                        __1size += ((__1size_arr[(__1i - 1)]) +
                                    (((__1size_arr[(__1i - 1)]) > 99)
                                         ? 3
                                         : (((__1size_arr[(__1i - 1)]) < 10) ? 1 : 2)));
                    }

                    (__1result[__1size]) = '\0';

                    return __1result;
                }
            }
        }
    }
}

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

extern Pbase_inst head__10basic_inst;

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

extern Pcons last_friend_cons__17templ_compilation;

extern Pcons last_cons__17templ_compilation;

extern Pcons friend_templ_refs__17templ_compilation;

extern Pcons templ_refs__17templ_compilation;

extern int formals_in_progress__17templ_compilation;

extern int parameters_in_progress__17templ_compilation;

extern Ptstate save_templ__17templ_compilation;

extern int in_progress__17templ_compilation;

extern Ptable templates__17templ_compilation;

extern Pexpr actuals__17templ_compilation;

extern Plist params__17templ_compilation;

extern Ptempl_base parsed_template__17templ_compilation;

extern Ptempl owner__17templ_compilation;

extern Pfunt f_owner__17templ_compilation;

extern Pfunt f_list__17templ_compilation;

extern Ptempl list__17templ_compilation;

extern Plist param_end__17templ_compilation;

extern Pstmt stmt_free__4stmt;

extern Pname name_free__4name;

extern Pexpr expr_free__4expr;

extern Pptr ptr_free__3ptr;

extern Pvec vec_free__3vec;

extern Pfct fct_free__3fct;

extern Pktab table_free__6ktable;

extern Ptable table_free__5table;

/* the end */
