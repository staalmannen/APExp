
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

#pragma lib "ape/libap.a"

typedef int (*GPT)(int, char *);

typedef size_t Bits_chunk;

struct Block_Bits_chunk;

struct Block_Bits_chunk { /* sizeof Block_Bits_chunk == 16 */

    Bits_chunk *p__16Block_Bits_chunk;

    size_t n__16Block_Bits_chunk;
};

void move__16Block_Bits_chunkFPUlUl(struct Block_Bits_chunk *__0this, Bits_chunk *, size_t);

void copy__16Block_Bits_chunkFRC16Block_Bits_chunk(struct Block_Bits_chunk *__0this,
                                                   const struct Block_Bits_chunk *);

extern void __dl__FPv(void *);

size_t grow__16Block_Bits_chunkFUl(struct Block_Bits_chunk *__0this, size_t);
struct Bits;

struct Bits { /* sizeof Bits == 24 */

    struct Block_Bits_chunk b__4Bits;
    size_t n__4Bits;
};

size_t signif__4BitsCFv(const struct Bits *const __0this);

size_t size__4BitsFUl(struct Bits *__0this, size_t);

int compare__4BitsCFRC4Bits(const struct Bits *const __0this, const struct Bits *);
int equal__4BitsCFRC4Bits(const struct Bits *const __0this, const struct Bits *);

extern int ambig;
extern int no_const;
extern int non_const;
struct Block_Pname;

struct Block_Pname { /* sizeof Block_Pname == 16 */

    Pname *p__11Block_Pname;

    size_t n__11Block_Pname;
};

void move__11Block_PnameFPP4nameUl(struct Block_Pname *__0this, Pname *, size_t);

void copy__11Block_PnameFRC11Block_Pname(struct Block_Pname *__0this, const struct Block_Pname *);

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

extern Pblock top_block;
struct for_info;

static struct for_info *for_info_head = 0;

struct for_info { /* sizeof for_info == 24 */
    char *s__8for_info;
    Pstmt rb__8for_info;
    struct for_info *next__8for_info;
};

extern int strcmp(const char *, const char *);

extern size_t strlen(const char *);

extern char *strcpy(char *, const char *);

static int for_check__FP4nameP4stmt(Pname __1n, Pstmt __1rb) {
    struct for_info *__1p;
    if ((!__1n) || (!__1rb)) {
        struct ea __0__V37;

        struct ea __0__V38;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"for_check(n=%d,rb=%d)",
            (const struct ea *)(((&__0__V37)->__O1__2ea.p = ((const void *)__1n)), (&__0__V37)),
            (const struct ea *)(((&__0__V38)->__O1__2ea.p = ((const void *)__1rb)), (&__0__V38)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if ((__1n->__O1__4expr.tp->base__4node == 108) || (__1n->__O1__4expr.tp->base__4node == 76))
        return 0;
    __1p = for_info_head;
    while (__1p && (strcmp((const char *)__1p->s__8for_info, __1n->__O2__4expr.string) ||
                    (__1p->rb__8for_info != __1rb)))
        __1p = __1p->next__8for_info;
    if (__1p) {
        return 1;
    } else {
        __1p = (((struct for_info *)__nw__FUl(sizeof(struct for_info))));
        __1p->s__8for_info = ((
            (char *)__nw__FUl((size_t)((sizeof(char)) * (strlen(__1n->__O2__4expr.string) + 1)))));
        strcpy(__1p->s__8for_info, __1n->__O2__4expr.string);
        __1p->rb__8for_info = __1rb;
        __1p->next__8for_info = for_info_head;
        for_info_head = __1p;
        return 0;
    }
}
void for_check_delete__Fv(void) {
    struct for_info *__1p;
    struct for_info *__1r;

    __1p = for_info_head;
    while (__1p) {
        __1r = __1p;
        __dl__FPv((void *)__1p->s__8for_info);
        __1p = __1p->next__8for_info;
        __dl__FPv((void *)__1r);
    }
    for_info_head = 0;
}

static Pname is_decl__FP5blockP4name(Pblock __1cb, Pname __1v) {
    if (!__1cb->__O1__4stmt.d)
        return (struct name *)0;
    {
        {
            Pname __1n;

            __1n = __1cb->__O1__4stmt.d;

            for (; __1n; __1n = __1n->__O1__4name.n_list) {
                if (strcmp(__1v->__O2__4expr.string, __1n->__O2__4expr.string) == 0)
                    return __1n;
            }
            return (struct name *)0;
        }
    }
}

static Pname redecl = 0;

Pstmt find_return__FP4stmtP4name(Pstmt __1s, Pname __1v);

Pstmt find_return__FP4stmtP4name(Pstmt __1s, Pname __1v) {
    while (__1s) {
        switch (__1s->base__4node) {
        case 28: {
            Pname __4te;

            __4te = ((__1s->__O2__4stmt.e->base__4node == 85)
                         ? (((struct name *)(((struct name *)__1s->__O2__4stmt.e))))
                         : (((struct name *)0)));
            if ((!__4te) || strcmp(__4te->__O2__4expr.string, __1v->__O2__4expr.string)) {
                return __1s;
            }
            if (__4te == __1v)
                return (struct stmt *)0;
            if (redecl)
                return __1s;
            else
                return (struct stmt *)0;
        }
        case 116: {
            if (!redecl)
                redecl = is_decl__FP5blockP4name(((struct block *)(((struct block *)__1s))), __1v);
            {
                Pstmt __4tt;

                __4tt = find_return__FP4stmtP4name(
                    (((struct block *)(((struct block *)__1s))))->s__4stmt, __1v);
                if (__4tt)
                    return __4tt;
                redecl = 0;
                break;
            }
        }
        case 10:
        case 39:
        case 16:
        case 33:
        case 4:
        case 8: {
            Pstmt __4tt;

            __4tt = find_return__FP4stmtP4name(__1s->s__4stmt, __1v);
            if (__4tt)
                return __4tt;
            break;
        }
        case 20: {
            Pstmt __4tt;

            __4tt = find_return__FP4stmtP4name(__1s->s__4stmt, __1v);
            if (__4tt)
                return __4tt;
            __4tt = find_return__FP4stmtP4name(__1s->__O3__4stmt.else_stmt, __1v);
            if (__4tt)
                return __4tt;
            break;
        }
        }
        __1s = __1s->s_list__4stmt;
    }
    return (struct stmt *)0;
}

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

bit has_base__8classdefFP8classdefiT2(struct classdef *__0this, Pclass __1cl, int __1level,
                                      int __1ccflag);

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);

Pname is_cl_obj__4typeFv(struct type *__0this);

Pname hier_dominates__FP4nameT1(Pname __1on1, Pname __1on2) {
    Pfct __1f1;
    Pfct __1f2;

    Ptype __1r1;
    Ptype __1r2;

    __1f1 = (((__1on1->__O1__4expr.tp->base__4node == 108)
                  ? (((struct fct *)(((struct fct *)__1on1->__O1__4expr.tp))))
                  : (((struct fct *)((
                        (struct fct *)(((struct gen *)(((struct gen *)__1on1->__O1__4expr.tp))))
                            ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))));
    __1f2 = (((__1on2->__O1__4expr.tp->base__4node == 108)
                  ? (((struct fct *)(((struct fct *)__1on2->__O1__4expr.tp))))
                  : (((struct fct *)((
                        (struct fct *)(((struct gen *)(((struct gen *)__1on2->__O1__4expr.tp))))
                            ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))));

    __1r1 = __1f1->returns__3fct;
    __1r2 = __1f2->returns__3fct;

    if ((__1r1 == __1r2) ||
        (check__4typeFP4typeUcT2(__1r1, __1r2, (unsigned char)0, (unsigned char)0) == 0)) {

        Pclass __2m1;
        Pclass __2m2;

        __2m1 = __1f1->memof__3fct;
        __2m2 = __1f2->memof__3fct;
        if (has_base__8classdefFP8classdefiT2(__2m1, __2m2, 0, 0))
            return __1on1;
        if (has_base__8classdefFP8classdefiT2(__2m2, __2m1, 0, 0))
            return __1on2;
        return (struct name *)0;
    }
    {
        Pptr __1p1;
        Pptr __1p2;

        __1p1 = is_ptr_or_ref__4typeFv(__1r1);
        __1p2 = is_ptr_or_ref__4typeFv(__1r2);
        if (__1p1 && __1p2) {
            Pname __2cn1;
            Pname __2cn2;

            __2cn1 = is_cl_obj__4typeFv(__1p1->typ__5pvtyp);
            __2cn2 = is_cl_obj__4typeFv(__1p2->typ__5pvtyp);
            if (__2cn1 && __2cn2) {
                Pclass __3c1;
                Pclass __3c2;

                __3c1 = (((struct classdef *)(((struct classdef *)__2cn1->__O1__4expr.tp))));
                __3c2 = (((struct classdef *)(((struct classdef *)__2cn2->__O1__4expr.tp))));
                if (__3c1 && __3c2) {
                    if (has_base__8classdefFP8classdefiT2(__3c1, __3c2, 0, 0))
                        return __1on1;
                    else if (has_base__8classdefFP8classdefiT2(__3c2, __3c1, 0, 0))
                        return __1on2;
                }
            }
        }
        return (struct name *)0;
    }
}

struct Bits *__ct__4BitsFUlT1(struct Bits *__0this, Bits_chunk, size_t);

extern void __co__FRC4Bits(struct Bits *__0_result, const struct Bits *);

size_t count__4BitsCFv(const struct Bits *const __0this);

extern Pname really_dominate__FP4nameT1Uc(Pname, Pname, bit);

void best_conv__FRC11Block_PnameRiUc(struct Bits *__0_result, const struct Block_Pname *__1CONV,
                                     int *__1nfound, bit __1cO) {
    struct Bits __1zeroBits;

    struct Bits __1tempBits;
    int __1sigbit;

    struct Block_Bits_chunk *__0__X36;

    struct Block_Bits_chunk *__0__X32;

    int __2__X33;

    __ct__4BitsFUlT1(&__1zeroBits, (unsigned long)0, (unsigned long)((*__1nfound)));
    __co__FRC4Bits(__0_result, (const struct Bits *)(&__1zeroBits));

    __co__FRC4Bits(&__1tempBits, (const struct Bits *)(&__1zeroBits));
    __1sigbit = (signif__4BitsCFv((const struct Bits *)(&__1tempBits)) - 1);
    (((((unsigned long)__1sigbit) < (&__1tempBits)->n__4Bits)
          ? (((*((__0__X32 = (&(&__1tempBits)->b__4Bits)),
                 ((__2__X33 = ((((unsigned long)__1sigbit) >> 5))),
                  ((((Bits_chunk *)(&(__0__X32->p__16Block_Bits_chunk[__2__X33]))))))))) &=
             (~((((unsigned long)1)) << (((unsigned long)__1sigbit) & 31))))
          : 0),
     (((struct Bits *)(&__1tempBits))));

    while (count__4BitsCFv((const struct Bits *)(&__1tempBits))) {
        int __2tempPtr;
        Pname __2tname;

        __2tempPtr = (signif__4BitsCFv((const struct Bits *)(&__1tempBits)) - 1);
        __2tname = ((*((((const Pname *)(&(
            ((const struct Block_Pname *)__1CONV)->p__11Block_Pname[__2tempPtr])))))));
        {
            {
                int __2k;

                struct Block_Bits_chunk *__0__X32;

                int __2__X33;

                __2k = (((*__1nfound)) - 1);

                for (; __2k > __2tempPtr; __2k--) {
                    const struct Block_Bits_chunk *__0__X34;

                    int __2__X35;

                    if (!(((((unsigned long)__2k) >= ((const struct Bits *)__0_result)->n__4Bits)
                               ? (((int)0))
                               : (((int)((((*((__0__X34 = (const struct Block_Bits_chunk
                                                               *)(&((const struct Bits *)__0_result)
                                                                       ->b__4Bits)),
                                              ((__2__X35 = ((((unsigned long)__2k) >> 5))),
                                               ((((const Bits_chunk *)(&(
                                                   __0__X34
                                                       ->p__16Block_Bits_chunk[__2__X35]))))))))) >>
                                          (((unsigned long)__2k) & 31)) &
                                         1))))))
                        continue;
                    {
                        Pname __3r;

                        struct Block_Bits_chunk *__0__X32;

                        int __2__X33;

                        __3r = really_dominate__FP4nameT1Uc(
                            __2tname,
                            (struct name *)((
                                *((((const Pname *)(&(((const struct Block_Pname *)__1CONV)
                                                          ->p__11Block_Pname[__2k]))))))),
                            __1cO);

                        if (__3r == __2tname)
                            (((((unsigned long)__2k) < __0_result->n__4Bits)
                                  ? (((*((__0__X32 = (&__0_result->b__4Bits)),
                                         ((__2__X33 = ((((unsigned long)__2k) >> 5))),
                                          ((((Bits_chunk *)(&(
                                              __0__X32->p__16Block_Bits_chunk[__2__X33]))))))))) &=
                                     (~((((unsigned long)1)) << (((unsigned long)__2k) & 31))))
                                  : 0),
                             (((struct Bits *)__0_result)));
                        if (__3r == ((*((((const Pname *)(&(((const struct Block_Pname *)__1CONV)
                                                                ->p__11Block_Pname[__2k])))))))) {
                            struct Block_Bits_chunk *__0__X32;

                            int __2__X33;

                            (((((unsigned long)__2tempPtr) < __0_result->n__4Bits)
                                  ? (((*((__0__X32 = (&__0_result->b__4Bits)),
                                         ((__2__X33 = ((((unsigned long)__2tempPtr) >> 5))),
                                          ((((Bits_chunk *)(&(
                                              __0__X32->p__16Block_Bits_chunk[__2__X33]))))))))) &=
                                     (~((((unsigned long)1))
                                        << (((unsigned long)__2tempPtr) & 31))))
                                  : 0),
                             (((struct Bits *)__0_result)));
                            break;
                        }
                    }
                }
                (((((unsigned long)__2tempPtr) < (&__1tempBits)->n__4Bits)
                      ? (((*((__0__X32 = (&(&__1tempBits)->b__4Bits)),
                             ((__2__X33 = ((((unsigned long)__2tempPtr) >> 5))),
                              ((((Bits_chunk *)(&(
                                  __0__X32->p__16Block_Bits_chunk[__2__X33]))))))))) &=
                         (~((((unsigned long)1)) << (((unsigned long)__2tempPtr) & 31))))
                      : 0),
                 (((struct Bits *)(&__1tempBits))));
            }
        }
    }
    ((*__1nfound)) = count__4BitsCFv((const struct Bits *)__0_result);
    {
        {
            ;

            ((((void)((
                (void)(((__0__X36 = (&(&__1tempBits)->b__4Bits)),
                        ((__0__X36 ? (((void)(__dl__FPv((void *)__0__X36->p__16Block_Bits_chunk),
                                              (__0__X36 ? (((void)(((void)0)))) : (((void)0))))))
                                   : (((void)0))))),
                       (((void)0))))))));

            ((((void)((
                (void)(((__0__X36 = (&(&__1zeroBits)->b__4Bits)),
                        ((__0__X36 ? (((void)(__dl__FPv((void *)__0__X36->p__16Block_Bits_chunk),
                                              (__0__X36 ? (((void)(((void)0)))) : (((void)0))))))
                                   : (((void)0))))),
                       (((void)0))))))));
        }
        return;
    }
}

Pstmt curr_loop = 0;
Pstmt curr_switch = 0;
Pblock curr_block = 0;
static Pstmt curr_case;
static Pblock block_since_case;

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

void reached__4stmtFv(register struct stmt *__0this) {
    Pstmt __1ss;

    __1ss = __0this->s_list__4stmt;

    if (__1ss == 0)
        return;

    switch (__1ss->base__4node) {
        unsigned long __2__X43;

        unsigned long __2__X44;

    case 115:
    case 4:
    case 8:
        break;
    default:
        if (__1ss->where__4stmt.line__3loc != 0) {
            struct ea __0__V41;

            error__FiP3locPCcRC2eaN34(
                (int)'w', &__1ss->where__4stmt, (const char *)"S after%k not reached",
                (const struct ea *)((__2__X43 = __0this->base__4node),
                                    (((((&__0__V41)->__O1__2ea.i = __2__X43), 0)), (&__0__V41))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        } else {
            struct ea __0__V42;

            error__FiPCcRC2eaN33(
                (int)'w', (const char *)"S after%k not reached",
                (const struct ea *)((__2__X44 = __0this->base__4node),
                                    (((((&__0__V42)->__O1__2ea.i = __2__X44), 0)), (&__0__V42))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        for (; __1ss; __1ss = __1ss->s_list__4stmt) {
            switch (__1ss->base__4node) {
            case 115:
            case 4:
            case 8:
                __0this->s_list__4stmt = __1ss;

                return;
            case 118:
            case 20:
            case 10:
            case 39:
            case 33:
            case 16:
            case 116:
                __0this->s_list__4stmt = __1ss;
                return;
            }
        }
        __0this->s_list__4stmt = 0;
    }
}

Pptr is_ref__4typeFv(struct type *__0this);

bit oper_okay__FP4typeUc(Ptype __1t, TOK __1b) {
    if (is_ref__4typeFv(__1t))
        __1t = (((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp;

    switch (__1t->base__4node) {
    case 125:
        if (__1b == 107)
            break;
    case 15:
    case 11:
    case 181:
        if (((__1b == 47) || (__1b == 111)) || (__1b == 33))
            break;
    case 5:
    case 29:
    case 21:
    case 22:
    case 122:
    case 121:
        return (unsigned char)1;
    }

    return (unsigned char)0;
}

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

bit tconst__4typeFv(struct type *__0this);

bit is_const_obj__4exprFv(struct expr *__0this);

int lval__4exprFUc(struct expr *__0this, TOK);

Pexpr typ__4exprFP5table(struct expr *__0this, Ptable);

Pfct memptr__4typeFv(struct type *__0this);

extern Pexpr make_dot__FP4exprP5tablePCc(Pexpr, Ptable, const char *__0s);

extern int error__FPCc(const char *);

Pexpr check_cond__FP4exprUcP5table(Pexpr __1e, TOK __1b, Ptable __1tbl) {
    Pname __1cn;
    if (__1e == dummy) {
        struct ea __0__V45;

        error__FPCcRC2eaN32(
            (const char *)"empty condition for %k",
            (const struct ea *)(((((&__0__V45)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                (&__0__V45)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    {
        int __1const_obj;

        struct type *__0__X66;

        __1const_obj = 0;
        __1const_obj =
            (tconst__4typeFv(__1e->__O1__4expr.tp) ? (((unsigned int)1))
                                                   : (((unsigned int)is_const_obj__4exprFv(__1e))));

        if (__1cn = is_cl_obj__4typeFv(__1e->__O1__4expr.tp)) {
            int __2no_const;
            Pclass __2cl;
            Pname __2found;
            Pname __2other;
            int __2nfound;
            struct Block_Pname __2conv;

            __2no_const = 0;
            __2cl = (((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))));
            __2found = 0;
            __2other = 0;
            __2nfound = 0;
            (((((&__2conv)->n__11Block_Pname = 0), ((&__2conv)->p__11Block_Pname = 0))),
             (&__2conv));

            {
                {
                    Pname __2on;

                    __2on = __2cl->conv__8classdef;

                    for (; __2on; __2on = __2on->__O1__4name.n_list) {
                        Pfct __3f;
                        Ptype __3t;

                        __3f =
                            (((__2on->__O1__4expr.tp->base__4node == 108)
                                  ? (((struct fct *)(((struct fct *)__2on->__O1__4expr.tp))))
                                  : (((struct fct *)((
                                        (struct fct *)(((struct gen *)((
                                                           (struct gen *)__2on->__O1__4expr.tp))))
                                            ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))));
                        __3t = skiptypedefs__4typeFv(__3f->returns__3fct);

                        if (oper_okay__FP4typeUc(__3t, __1b) == 1) {
                            int __2__X58;

                            if (__1const_obj && (!__3f->f_const__3fct)) {
                                __2no_const++;
                                continue;
                            }

                            (((((unsigned long)(__2nfound + 1)) < (&__2conv)->n__11Block_Pname) ||
                              grow__11Block_PnameFUl((&__2conv),
                                                     ((unsigned long)(__2nfound + 1)))));
                            ((*((__2__X58 = (__2nfound++)),
                                ((((Pname *)(&((&__2conv)->p__11Block_Pname[__2__X58])))))))) =
                                __2on;
                        }
                    }
                    if (__2nfound == 1)
                        __2found =
                            ((*((((Pname *)(&((&__2conv)->p__11Block_Pname[(__2nfound - 1)])))))));
                    if (__2nfound > 1) {
                        struct Bits __3b;
                        int __3i;

                        struct Block_Bits_chunk *__0__X36;

                        best_conv__FRC11Block_PnameRiUc(
                            &__3b, (const struct Block_Pname *)(&__2conv), (int *)(&__2nfound),
                            (unsigned char)__1const_obj);

                        __3i = (signif__4BitsCFv((const struct Bits *)(&__3b)) - 1);
                        __2found = ((*((((Pname *)(&((&__2conv)->p__11Block_Pname[__3i])))))));
                        if (count__4BitsCFv((const struct Bits *)(&__3b)) == 2) {
                            struct Block_Bits_chunk *__0__X32;

                            int __2__X33;

                            int __2__X59;

                            (((((unsigned long)__3i) < (&__3b)->n__4Bits)
                                  ? (((*((__0__X32 = (&(&__3b)->b__4Bits)),
                                         ((__2__X33 = ((((unsigned long)__3i) >> 5))),
                                          ((((Bits_chunk *)(&(
                                              __0__X32->p__16Block_Bits_chunk[__2__X33]))))))))) &=
                                     (~((((unsigned long)1)) << (((unsigned long)__3i) & 31))))
                                  : 0),
                             (((struct Bits *)(&__3b))));
                            __2other = ((
                                *((__2__X59 = (signif__4BitsCFv((const struct Bits *)(&__3b)) - 1)),
                                  ((((Pname *)(&((&__2conv)->p__11Block_Pname[__2__X59]))))))));
                        }

                        ((((void)((
                            (void)(((__0__X36 = (&(&__3b)->b__4Bits)),
                                    ((__0__X36 ? (((void)(__dl__FPv((void *)__0__X36
                                                                        ->p__16Block_Bits_chunk),
                                                          (__0__X36 ? (((void)(((void)0))))
                                                                    : (((void)0))))))
                                               : (((void)0))))),
                                   (((void)0))))))));
                    }

                    switch (__2nfound) {
                    case 0:
                        if (__2no_const) {
                            struct ea __0__V47;

                            struct ea __0__V48;

                            error__FPCcRC2eaN32(
                                (const char *)"%nO in%kE (no usable const conversion)",
                                (const struct ea *)(((&__0__V47)->__O1__2ea.p =
                                                         ((const void *)__1cn)),
                                                    (&__0__V47)),
                                (const struct ea *)(((((&__0__V48)->__O1__2ea.i =
                                                           ((unsigned long)__1b)),
                                                      0)),
                                                    (&__0__V48)),
                                (const struct ea *)ea0, (const struct ea *)ea0);
                        } else {
                            struct ea __0__V49;

                            struct ea __0__V50;

                            error__FPCcRC2eaN32((const char *)"%nO in%kE",
                                                (const struct ea *)(((&__0__V49)->__O1__2ea.p =
                                                                         ((const void *)__1cn)),
                                                                    (&__0__V49)),
                                                (const struct ea *)(((((&__0__V50)->__O1__2ea.i =
                                                                           ((unsigned long)__1b)),
                                                                      0)),
                                                                    (&__0__V50)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                        }
                        break;
                    case 1: {
                        Pname __4xx;
                        Pexpr __4c;

                        __4xx = __ct__4nameFPCc((struct name *)0, __2found->__O2__4expr.string);

                        if (lval__4exprFUc(__1e, (unsigned char)0)) {
                            Pref __5r;
                            Pexpr __5rr;

                            struct ref *__0__X60;

                            struct expr *__2__X61;

                            struct expr *__2__X62;

                            __5r = ((__0__X60 = 0),
                                    ((__2__X61 = __1e),
                                     ((__2__X62 = (struct expr *)__4xx),
                                      (((__0__X60 || (__0__X60 = (struct ref *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct ref)))))
                                            ? ((__0__X60 = (struct ref *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X60), ((unsigned char)45),
                                                    __2__X61, (struct expr *)0)),
                                               (__0__X60->__O4__4expr.mem = __2__X62))
                                            : 0),
                                       __0__X60))));

                            __5rr = typ__4exprFP5table((struct expr *)__5r, __1tbl);
                            __4c = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)146,
                                                          __5rr, (struct expr *)0);
                        } else {
                            Pref __5r;
                            Pexpr __5rr;

                            struct ref *__0__X63;

                            struct expr *__2__X64;

                            struct expr *__2__X65;

                            __5r = ((__0__X63 = 0),
                                    ((__2__X64 = __1e),
                                     ((__2__X65 = (struct expr *)__4xx),
                                      (((__0__X63 || (__0__X63 = (struct ref *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct ref)))))
                                            ? ((__0__X63 = (struct ref *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X63), ((unsigned char)45),
                                                    __2__X64, (struct expr *)0)),
                                               (__0__X63->__O4__4expr.mem = __2__X65))
                                            : 0),
                                       __0__X63))));

                            __5rr = typ__4exprFP5table((struct expr *)__5r, __1tbl);
                            __4c = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)146,
                                                          __5rr, (struct expr *)0);
                        }
                        {
                            Pexpr __4E;

                            __4E = typ__4exprFP5table(__4c, __1tbl);
                            if (memptr__4typeFv(__4E->__O1__4expr.tp)) {
                                __4E = make_dot__FP4exprP5tablePCc(__4E, __1tbl, (const char *)"i");
                                __4E = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)63,
                                                              __4E, zero);
                                __4E->__O1__4expr.tp = (struct type *)int_type;
                            }
                            __1e = __4E;
                            break;
                        }
                    }
                    case 2: {
                        struct ea __0__V51;

                        struct ea __0__V52;

                        struct ea __0__V53;

                        struct ea __0__V54;

                        error__FPCcRC2eaN32(
                            (const char *)"two conversions for%nO in%kE: %n and %n",
                            (const struct ea *)(((&__0__V51)->__O1__2ea.p = ((const void *)__1cn)),
                                                (&__0__V51)),
                            (const struct ea *)(((((&__0__V52)->__O1__2ea.i =
                                                       ((unsigned long)__1b)),
                                                  0)),
                                                (&__0__V52)),
                            (const struct ea *)(((&__0__V53)->__O1__2ea.p =
                                                     ((const void *)__2found)),
                                                (&__0__V53)),
                            (const struct ea *)(((&__0__V54)->__O1__2ea.p =
                                                     ((const void *)__2other)),
                                                (&__0__V54)));
                        break;
                    default: {
                        struct ea __0__V55;

                        struct ea __0__V56;

                        error__FPCcRC2eaN32(
                            (const char *)"multiple conversions for%nO in%kE",
                            (const struct ea *)(((&__0__V55)->__O1__2ea.p = ((const void *)__1cn)),
                                                (&__0__V55)),
                            (const struct ea *)(((((&__0__V56)->__O1__2ea.i =
                                                       ((unsigned long)__1b)),
                                                  0)),
                                                (&__0__V56)),
                            (const struct ea *)ea0, (const struct ea *)ea0);

                        break;
                    }
                    }
                    }
                    {
                        ((((void)(__dl__FPv((void *)(&__2conv)->p__11Block_Pname),
                                  (((void)(((void)0))))))));

                        return __1e;
                    }
                }
            }
        }
        if (__1e->__O1__4expr.tp->base__4node == 108) {
            __1e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145, (struct expr *)0,
                                          __1e);
            __1e = typ__4exprFP5table(__1e, __1tbl);
        }
        if (memptr__4typeFv(__1e->__O1__4expr.tp)) {
            if (__1b == 33) {
                error__FPCc((const char *)"P toM as switchE");
                return __1e;
            }
            if ((__1e->base__4node == 124) ||
                (((__1e->base__4node == 113) || (__1e->base__4node == 191)) &&
                 (__1e->__O2__4expr.e1->base__4node == 124))) {

                if (__1e->base__4node != 124)
                    __1e = __1e->__O2__4expr.e1;
                if (__1e->__O2__4expr.e1->__O3__4expr.e2 != zero)
                    __1e = one;
                else
                    __1e = zero;
            } else {
                __1e = make_dot__FP4exprP5tablePCc(__1e, __1tbl, (const char *)"i");

                __1e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)63, __1e, zero);
                __1e->__O1__4expr.tp = (struct type *)int_type;
            }
        } else if (((__0__X66 = __1e->__O1__4expr.tp),
                    (kind__4typeFUcN21(__0__X66, __1b, (unsigned char)'P', (unsigned char)1))) ==
                   108) {
            struct ea __0__V57;

            error__FPCcRC2eaN32(
                (const char *)"%k(F)",
                (const struct ea *)(((((&__0__V57)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                    (&__0__V57)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        return __1e;
    }
}

void dcl__4stmtFi(struct stmt *__0this, int __1forflag);

void dcl_print__4nameFUc(struct name *__0this, TOK);

bit not_simple__4exprFi(struct expr *__0this, int __1inflag);

extern Pname make_tmp__FcP4typeP5table(char, Ptype, Ptable);

extern Pexpr mptr_assign__FP4exprT1(Pexpr, Pexpr);

extern Pexpr ref_init__FP3ptrP4exprP5table(Pptr, Pexpr, Ptable);

extern int is_probably_temp__FPCc(const char *);

extern Pexpr replace_temp__FP4exprT1(Pexpr, Pexpr);

Pexpr contents__4exprFv(struct expr *__0this);

extern Pexpr class_init__FP4exprP4typeT1P5table(Pexpr, Ptype, Pexpr, Ptable);

extern Pexpr ptr_init__FP3ptrP4exprP5table(Pptr, Pexpr, Ptable);

extern Pexpr try_to_coerce__FP4typeP4exprPCcP5table(Ptype, Pexpr, const char *, Ptable);

long long eval__4exprFv(struct expr *__0this);

void assign__4nameFv(struct name *__0this);

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

void del__4stmtFv(struct stmt *__0this);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

void dcl__5blockFP5table(struct block *__0this, Ptable);

Pname dcl__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

void dcl__4stmtFi(register struct stmt *__0this, int __1forflag) {
    Pstmt __1ss;
    Pname __1n;
    Pname __1nn;
    Pstmt __1ostmt;

    __1ostmt = Cstmt;
    ;
    for (__1ss = __0this; __1ss; __1ss = __1ss->s_list__4stmt) {
        Pstmt __2old_loop;

        Pstmt __2old_switch;
        Cstmt = __1ss;
        {
            Ptable __2tbl;

            __2tbl = curr_block->memtbl__4stmt;

            switch (__1ss->base__4node) {
                struct type *__0__X92;

                unsigned long __2__X95;

                unsigned long __2__X106;

            case 3:
                inline_restr |= 16;
                if ((curr_loop == 0) && (curr_switch == 0))
                    error__FPCc((const char *)"break not in loop or switch");
                reached__4stmtFv(__1ss);
                break;

            case 7:
                inline_restr |= 32;
                if (curr_loop == 0)
                    error__FPCc((const char *)"continue not in loop");
                reached__4stmtFv(__1ss);
                break;

            case 8:
                if (curr_switch == 0) {
                    error__FPCc((const char *)"default not in switch");
                    break;
                }
                if (curr_switch->__O1__4stmt.has_default)
                    error__FPCc((const char *)"two defaults in switch");
                curr_case = __1ss;
                block_since_case = 0;
                curr_switch->__O1__4stmt.has_default = __1ss;
                __1ss->s__4stmt->s_list__4stmt = __1ss->s_list__4stmt;
                __1ss->s_list__4stmt = 0;
                dcl__4stmtFi(__1ss->s__4stmt, 0);
                break;

            case 72: {
                if (__1ss->__O2__4stmt.e == 0)
                    break;
                {
                    TOK __4b;

                    __4b = __1ss->__O2__4stmt.e->base__4node;
                    switch (__4b) {
                    case 144:
                    case 162:
                        __1ss->__O2__4stmt.e = 0;
                        break;

                    case 62:
                    case 63:
                    case 60:
                    case 61:
                    case 58:
                    case 59:
                    case 54:
                    case 55:
                    case 44:
                    case 45:
                    case 50:
                    case 51:
                    case 112:
                    case 52:
                    case 65:
                    case 64:
                    case 111:
                    case 66:
                    case 67:
                    case 85:
                    case 157:
                        if (__1ss->__O2__4stmt.e->__O1__4expr.tp)
                            break;
                        __1ss->__O2__4stmt.e = typ__4exprFP5table(__1ss->__O2__4stmt.e, __2tbl);
                        if (__1ss->__O2__4stmt.e->base__4node == 109)
                            break;
                        if (__1ss->__O2__4stmt.e->__O1__4expr.tp->base__4node != 38) {
                            const void *__2__X87;

                            if (__1ss->__O2__4stmt.e->base__4node == 111) {
                                struct ea __0__V67;

                                error__FiPCcRC2eaN33(
                                    (int)'w', (const char *)"result of %sE not used",
                                    (const struct ea
                                         *)((__2__X87 =
                                                 (const void *)(__1ss->__O2__4stmt.e->__O3__4expr.e2
                                                                    ? "[]"
                                                                    : (((char *)"*")))),
                                            (((&__0__V67)->__O1__2ea.p = __2__X87), (&__0__V67))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            } else {
                                {
                                    struct ea __0__V68;

                                    error__FiPCcRC2eaN33(
                                        (int)'w', (const char *)"result of%kE not used",
                                        (const struct ea *)(((((&__0__V68)->__O1__2ea.i =
                                                                   ((unsigned long)__4b)),
                                                              0)),
                                                            (&__0__V68)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    if ((__1ss->__O2__4stmt.e->base__4node == 85) &&
                                        (__1ss->__O2__4stmt.e->__O1__4expr.tp->base__4node ==
                                         108)) {
                                        int __8i;

                                        __8i = (((struct name *)((
                                                    (struct name *)__1ss->__O2__4stmt.e))))
                                                   ->n_addr_taken__4name;
                                        (((struct name *)(((struct name *)__1ss->__O2__4stmt.e))))
                                            ->n_addr_taken__4name = 1;
                                        dcl_print__4nameFUc(
                                            ((struct name *)((
                                                (struct name *)__1ss->__O2__4stmt.e))),
                                            (unsigned char)0);
                                        (((struct name *)(((struct name *)__1ss->__O2__4stmt.e))))
                                            ->n_addr_taken__4name = __8i;
                                    }
                                }
                            }
                            if (not_simple__4exprFi(__1ss->__O2__4stmt.e, 0) == 0)
                                __1ss->__O2__4stmt.e = dummy;
                        }
                        if (__1ss->__O2__4stmt.e->base__4node == 124) {
                            Pname __6tt;

                            __6tt =
                                make_tmp__FcP4typeP5table('A', (struct type *)mptr_type, __2tbl);
                            __1ss->__O2__4stmt.e =
                                mptr_assign__FP4exprT1((struct expr *)__6tt, __1ss->__O2__4stmt.e);
                        }
                        break;
                    default:
                        __1ss->__O2__4stmt.e = typ__4exprFP5table(__1ss->__O2__4stmt.e, __2tbl);
                    }
                    break;
                }
            }
            case 28: {
                Pname __4fn;
                Pfct __4f;
                Ptype __4rt;
                Pexpr __4v;

                __4fn = cc->nof__11dcl_context;
                __4f = (((struct fct *)(((struct fct *)__4fn->__O1__4expr.tp))));
                __4rt = skiptypedefs__4typeFv(__4f->returns__3fct);
                __4v = __1ss->__O2__4stmt.e;

                if (__4v != dummy) {
                    if (__4rt->base__4node == 158) {
                        ref_initializer++;
                        __4v = typ__4exprFP5table(__4v, __2tbl);
                        ref_initializer--;
                    } else
                        __4v = typ__4exprFP5table(__4v, __2tbl);

                    if (((__4fn->n_oper__4name == 161) || (__4fn->n_oper__4name == 162)) ||
                        (__4rt->base__4node == 38)) {
                        error__FPCc((const char *)"unexpected return value");

                        __1ss->__O2__4stmt.e = dummy;
                    } else {
                        switch (__4rt->base__4node) {
                        case 158:
                            switch (__4v->base__4node) {
                            case 85:
                                if (((((struct name *)(((struct name *)__4v))))->n_scope__4name ==
                                     108) ||
                                    ((((struct name *)(((struct name *)__4v))))->n_scope__4name ==
                                     136))
                                    error__FiPCc((int)'w', (const char *)"R to localV returned");
                                break;
                            case 82:
                            case 84:
                            case 83:
                            case 81:
                                if (tconst__4typeFv(
                                        (((struct ptr *)(((struct ptr *)__4rt))))->typ__5pvtyp) ==
                                    0)
                                    error__FiPCc((int)'w', (const char *)"R to literal returned");
                            }
                            in_return = 1;
                            __4v = ref_init__FP3ptrP4exprP5table(
                                ((struct ptr *)(((struct ptr *)__4rt))), __4v, __2tbl);
                            in_return = 0;
                            if ((((__4v->base__4node == 147) &&
                                  (__4v->__O3__4expr.e2->base__4node == 145)) &&
                                 (__4v->__O3__4expr.e2->__O3__4expr.e2->base__4node == 85)) &&
                                is_probably_temp__FPCc(
                                    __4v->__O3__4expr.e2->__O3__4expr.e2->__O2__4expr.string))
                                error__FiPCc((int)'w',
                                             (const char *)"R to temporary returned (return value "
                                                           "is not lvalue or of wrongT)");
                        case 141:
                            break;
                        case 119:
                            if (__4v->base__4node == 111) {
                                Pexpr __8v1;

                                __8v1 = __4v->__O2__4expr.e1;
                                if ((__8v1->base__4node == 113) || (__8v1->base__4node == 191)) {
                                    Pexpr __9v2;

                                    __9v2 = __8v1->__O2__4expr.e1;
                                    if (__9v2->base__4node == 147) {
                                        Pexpr __10v3;

                                        __10v3 = __9v2->__O3__4expr.e2;
                                        __9v2->__O3__4expr.e2 = __4v;
                                        __9v2->__O1__4expr.tp = __4v->__O1__4expr.tp;
                                        __4v = __9v2;
                                        __8v1->__O2__4expr.e1 = __10v3;
                                    }
                                }
                            }
                            if (__4f->f_result__3fct) {
                                if ((__4v->base__4node == 147) &&
                                    (check__4typeFP4typeUcT2(__4rt, __4v->__O1__4expr.tp,
                                                             (unsigned char)0,
                                                             (unsigned char)0) == 0))
                                    __4v = replace_temp__FP4exprT1(
                                        __4v, (struct expr *)__4f->f_result__3fct);
                                else {
                                    if (!__4f->nrv__3fct)
                                        __4v = class_init__FP4exprP4typeT1P5table(
                                            contents__4exprFv((struct expr *)__4f->f_result__3fct),
                                            __4rt, __4v, __2tbl);
                                    {
                                        Pname __9rcn;

                                        struct classdef *__0__X88;

                                        __9rcn = is_cl_obj__4typeFv(__4rt);
                                        if (((__0__X88 = (((struct classdef *)((
                                                  (struct classdef *)__9rcn->__O1__4expr.tp))))),
                                             (__0__X88->c_itor__8classdef)) == 0) {
                                            __4v->__O1__4expr.tp = __4rt;
                                            __4v = __ct__4exprFUcP4exprT2(
                                                (struct expr *)0, (unsigned char)70,
                                                contents__4exprFv(
                                                    (struct expr *)__4f->f_result__3fct),
                                                __4v);

                                            __4v->__O1__4expr.tp = __4rt;
                                        }
                                    }
                                }
                            } else
                                __4v = class_init__FP4exprP4typeT1P5table((struct expr *)0, __4rt,
                                                                          __4v, __2tbl);
                            break;

                        case 125: {
                            const void *__2__X89;

                            __4v = ptr_init__FP3ptrP4exprP5table(
                                ((struct ptr *)(((struct ptr *)__4rt))), __4v, __2tbl);
                            if (((__4v->base__4node == 112) &&
                                 (__4v->__O3__4expr.e2->base__4node == 85)) &&
                                ((((struct name *)(((struct name *)__4v->__O3__4expr.e2))))
                                     ->n_stclass__4name == 2)) {

                                struct ea __0__V69;

                                error__FiPCcRC2eaN33(
                                    (int)'w', (const char *)"P to local variable%n returned",
                                    (const struct ea
                                         *)((__2__X89 = (const void *)(((struct name *)((
                                                 (struct name *)__4v->__O3__4expr.e2))))),
                                            (((&__0__V69)->__O1__2ea.p = __2__X89), (&__0__V69))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            if (Pchecked == 0)
                                goto def;
                            goto ret_save;
                        }

                        case 21:
                        case 5:
                        case 22:
                        case 122:
                        case 29:
                            if (((((struct basetype *)(((struct basetype *)__4rt))))
                                     ->b_unsigned__8basetype &&
                                 (__4v->base__4node == 107)) &&
                                (__4v->__O3__4expr.e2->base__4node == 82))
                                error__FiPCc(
                                    (int)'w',
                                    (const char *)"negative returned fromF returning unsigned");
                        default:
                        def: {
                            Pexpr __8x;
                            int __8ct;

                            __8x = try_to_coerce__FP4typeP4exprPCcP5table(
                                __4rt, __4v, (const char *)"return value", __2tbl);
                            __8ct = no_const;
                            if (__8x)
                                __4v = __8x;
                            else if (check__4typeFP4typeUcT2(__4rt, __4v->__O1__4expr.tp,
                                                             (unsigned char)70, (unsigned char)0)) {
                                {

                                    struct ea __0__V70;

                                    struct ea __0__V71;

                                    struct ea __0__V72;

                                    error__FiPCcRC2eaN33(
                                        (int)'e', (const char *)"bad return valueT for%n:%t (%tX)",
                                        (const struct ea *)(((&__0__V70)->__O1__2ea.p =
                                                                 ((const void *)__4fn)),
                                                            (&__0__V70)),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V71, (const void *)__4v->__O1__4expr.tp),
                                        (const struct ea *)(((&__0__V72)->__O1__2ea.p =
                                                                 ((const void *)__4rt)),
                                                            (&__0__V72)),
                                        (const struct ea *)ea0);
                                    if (__8ct)
                                        error__FiPCc(
                                            (int)'c',
                                            (const char *)" (no usable const conversion)\n");
                                    else
                                        error__FiPCc((int)'c', (const char *)"\n");
                                }
                            }
                            break;
                        }
                        }
                    ret_save:
                        __1ss->__O1__4stmt.ret_tp = __4rt;
                        __1ss->__O2__4stmt.e = __4v;
                    }
                } else {
                    if (__4rt->base__4node != 38)
                        error__FPCc((const char *)"return valueX");
                }
                reached__4stmtFv(__1ss);
                break;
            }

            case 10:
                inline_restr |= 8;
                __2old_loop = curr_loop;
                curr_loop = __1ss;
                {
                    Pstmt __4st;

                    __4st = __1ss->s__4stmt;
                    while (__4st && (__4st->base__4node == 16))
                        __4st = __4st->__O3__4stmt.for_init;
                    if (__4st && (__4st->base__4node == 118))
                        if (__4st == __1ss->s__4stmt)
                            error__FPCc((const char *)"D as onlyS in do-loop");
                }
                dcl__4stmtFi(__1ss->s__4stmt, 0);
                __1ss->__O2__4stmt.e = typ__4exprFP5table(__1ss->__O2__4stmt.e, __2tbl);
                __1ss->__O2__4stmt.e =
                    check_cond__FP4exprUcP5table(__1ss->__O2__4stmt.e, (unsigned char)10, __2tbl);
                curr_loop = __2old_loop;
                break;

            case 39:
                inline_restr |= 8;
                __2old_loop = curr_loop;
                curr_loop = __1ss;
                __1ss->__O2__4stmt.e = typ__4exprFP5table(__1ss->__O2__4stmt.e, __2tbl);
                __1ss->__O2__4stmt.e =
                    check_cond__FP4exprUcP5table(__1ss->__O2__4stmt.e, (unsigned char)39, __2tbl);
                {
                    Pstmt __4st;

                    __4st = __1ss->s__4stmt;
                    while (__4st && (__4st->base__4node == 16))
                        __4st = __4st->__O3__4stmt.for_init;
                    if (__4st && (__4st->base__4node == 118))
                        if (__4st == __1ss->s__4stmt)
                            error__FPCc((const char *)"D as onlyS in while-loop");
                }
                dcl__4stmtFi(__1ss->s__4stmt, 0);
                curr_loop = __2old_loop;
                break;

            case 33: {
                int __4ne;
                Pstmt __4old_case;
                Pblock __4old_bsc;

                __4ne = 0;
                __4old_case = curr_case;
                __4old_bsc = block_since_case;
                curr_case = 0;

                block_since_case = 0;
                inline_restr |= 4;
                __2old_switch = curr_switch;
                curr_switch = __1ss;
                __1ss->__O2__4stmt.e = typ__4exprFP5table(__1ss->__O2__4stmt.e, __2tbl);
                __1ss->__O2__4stmt.e =
                    check_cond__FP4exprUcP5table(__1ss->__O2__4stmt.e, (unsigned char)33, __2tbl);
                {
                    Pstmt __5st;

                    __5st = __1ss->s__4stmt;
                    while (__5st && (__5st->base__4node == 16))
                        __5st = __5st->__O3__4stmt.for_init;
                    if (__5st && (__5st->base__4node == 118))
                        if (__5st == __1ss->s__4stmt)
                            error__FPCc((const char *)"D as onlyS in switchS");
                }
                {
                    Ptype __5tt;

                    __5tt = skiptypedefs__4typeFv(__1ss->__O2__4stmt.e->__O1__4expr.tp);

                    switch (__5tt->base__4node) {
                        const void *__2__X90;

                    case 121:
                        __4ne =
                            (((struct enumdef *)(((struct enumdef *)(((struct basetype *)(((
                                                                         struct basetype *)__5tt))))
                                                      ->b_name__8basetype->__O1__4expr.tp))))
                                ->no_of_enumerators__7enumdef;
                    case 138:
                    case 141:
                    case 5:
                    case 29:
                    case 21:
                    case 22:
                    case 122:
                    case 114:
                        break;
                    default: {
                        struct ea __0__V73;

                        error__FPCcRC2eaN32(
                            (const char *)"%t switchE",
                            (const struct ea
                                 *)((__2__X90 = (const void *)__1ss->__O2__4stmt.e->__O1__4expr.tp),
                                    (((&__0__V73)->__O1__2ea.p = __2__X90), (&__0__V73))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    }
                }
                dcl__4stmtFi(__1ss->s__4stmt, 0);
                if (__4ne) {
                    int __5i;
                    Pstmt __5cs;

                    __5i = 0;

                    for (__5cs = __1ss->__O3__4stmt.case_list; __5cs;
                         __5cs = __5cs->__O3__4stmt.case_list)
                        __5i++;
                    if (__5i && (__5i != __4ne)) {
                        if (__4ne < __5i) {
                            const void *__2__X91;

                        ee:
                            if (__1ss->__O1__4stmt.has_default == 0) {
                                struct ea __0__V74;

                                struct ea __0__V75;

                                struct ea __0__V76;

                                error__FiPCcRC2eaN33(
                                    (int)'w',
                                    (const char *)"switch (%t)W %d cases (%d enumerators)",
                                    (const struct ea *)((__2__X91 = (const void *)__1ss->__O2__4stmt
                                                                        .e->__O1__4expr.tp),
                                                        (((&__0__V74)->__O1__2ea.p = __2__X91),
                                                         (&__0__V74))),
                                    (const struct ea *)(((((&__0__V75)->__O1__2ea.i =
                                                               ((unsigned long)__5i)),
                                                          0)),
                                                        (&__0__V75)),
                                    (const struct ea *)(((((&__0__V76)->__O1__2ea.i =
                                                               ((unsigned long)__4ne)),
                                                          0)),
                                                        (&__0__V76)),
                                    (const struct ea *)ea0);
                            }
                        } else {
                            switch (__4ne - __5i) {
                            case 1:
                                if (3 < __4ne)
                                    goto ee;
                            case 2:
                                if (7 < __4ne)
                                    goto ee;
                            case 3:
                                if (23 < __4ne)
                                    goto ee;
                            case 4:
                                if (60 < __4ne)
                                    goto ee;
                            case 5:
                                if (99 < __4ne)
                                    goto ee;
                            }
                        }
                    }
                }
                curr_switch = __2old_switch;
                curr_case = __4old_case;
                block_since_case = __4old_bsc;
                break;
            }

            case 4:
                if (curr_switch == 0) {
                    error__FPCc((const char *)"case not in switch");
                    break;
                }
                curr_case = __1ss;
                block_since_case = 0;
                __1ss->__O2__4stmt.e = typ__4exprFP5table(__1ss->__O2__4stmt.e, __2tbl);
                ((__0__X92 = __1ss->__O2__4stmt.e->__O1__4expr.tp),
                 (kind__4typeFUcN21(__0__X92, ((unsigned char)4), (unsigned char)'P',
                                    (unsigned char)1)));
                {
                    Ptype __4tt;

                    __4tt = skiptypedefs__4typeFv(__1ss->__O2__4stmt.e->__O1__4expr.tp);

                    switch (__4tt->base__4node) {
                        const void *__2__X94;

                    case 138:
                    case 141:
                    case 5:
                    case 29:
                    case 21:
                    case 22:
                    case 122:
                    case 121: {
                        Neval = 0;
                        {
                            long long __6i;

                            const void *__2__X93;

                            __6i = eval__4exprFv(__1ss->__O2__4stmt.e);
                            if (Neval == 0) {
                                Pstmt __7cs;
                                if (largest_int < __6i)
                                    error__FPCc((const char *)"long case value");
                                for (__7cs = curr_switch->__O3__4stmt.case_list; __7cs;
                                     __7cs = __7cs->__O3__4stmt.case_list) {
                                    if (__7cs->__O1__4stmt.case_value == __6i) {
                                        struct ea __0__V77;

                                        error__FPCcRC2eaN32(
                                            (const char *)"case %d used twice in switch",
                                            (const struct ea *)(((((&__0__V77)->__O1__2ea.i =
                                                                       ((unsigned long)__6i)),
                                                                  0)),
                                                                (&__0__V77)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                    }
                                }
                                __1ss->__O1__4stmt.case_value = (((int)__6i));
                                __1ss->__O3__4stmt.case_list = curr_switch->__O3__4stmt.case_list;
                                curr_switch->__O3__4stmt.case_list = __1ss;
                            } else {
                                struct ea __0__V78;

                                error__FPCcRC2eaN32(
                                    (const char *)"bad case label: %s",
                                    (const struct ea *)((__2__X93 = (const void *)Neval),
                                                        (((&__0__V78)->__O1__2ea.p = __2__X93),
                                                         (&__0__V78))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            break;
                        }
                    }
                    default: {
                        struct ea __0__V79;

                        error__FPCcRC2eaN32(
                            (const char *)"%t caseE",
                            (const struct ea
                                 *)((__2__X94 = (const void *)__1ss->__O2__4stmt.e->__O1__4expr.tp),
                                    (((&__0__V79)->__O1__2ea.p = __2__X94), (&__0__V79))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    }
                }
                if (__1ss->s__4stmt->s_list__4stmt) {
                    struct ea __0__V80;

                    error__FiPCcRC2eaN33(
                        (int)'i', (const char *)"case%k",
                        (const struct ea *)((__2__X95 =
                                                 __1ss->s__4stmt->s_list__4stmt->base__4node),
                                            (((((&__0__V80)->__O1__2ea.i = __2__X95), 0)),
                                             (&__0__V80))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                __1ss->s__4stmt->s_list__4stmt = __1ss->s_list__4stmt;
                __1ss->s_list__4stmt = 0;
                dcl__4stmtFi(__1ss->s__4stmt, 0);
                break;

            case 19:
                inline_restr |= 2;
                reached__4stmtFv(__1ss);

            case 115:
                __1n = __1ss->__O1__4stmt.d;
                __1nn = insert__5tableFP4nameUc(cc->ftbl__11dcl_context, __1n, (unsigned char)115);

                if (__1ss->base__4node == 115) {
                    __1nn->__O2__4name.n_realscope = curr_block->memtbl__4stmt;
                    inline_restr |= 1;
                }

                if (Nold) {
                    if (__1ss->base__4node == 115) {
                        if (__1nn->__O3__4expr.n_initializer) {
                            struct ea __0__V81;

                            error__FPCcRC2eaN32((const char *)"twoDs of label%n",
                                                (const struct ea *)(((&__0__V81)->__O1__2ea.p =
                                                                         ((const void *)__1n)),
                                                                    (&__0__V81)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        }
                        __1nn->__O3__4expr.n_initializer = (((struct expr *)1));
                    }
                    if (__1n != __1nn)
                        __1ss->__O1__4stmt.d = __1nn;
                } else {
                    if (__1ss->base__4node == 115)
                        __1nn->__O3__4expr.n_initializer = (((struct expr *)1));
                    __1nn->where__4name = __1ss->where__4stmt;
                }
                if (__1ss->base__4node == 19)
                    ((__1nn->n_used__4name++), (((void)0)));
                else {
                    unsigned long __2__X96;

                    if (__1ss->s__4stmt->s_list__4stmt) {
                        struct ea __0__V82;

                        error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"label%k",
                            (const struct ea *)((__2__X96 =
                                                     __1ss->s__4stmt->s_list__4stmt->base__4node),
                                                (((((&__0__V82)->__O1__2ea.i = __2__X96), 0)),
                                                 (&__0__V82))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    __1ss->s__4stmt->s_list__4stmt = __1ss->s_list__4stmt;
                    __1ss->s_list__4stmt = 0;
                    assign__4nameFv(__1nn);
                }
                if (__1ss->s__4stmt)
                    dcl__4stmtFi(__1ss->s__4stmt, 0);
                break;

            case 20: {
                Pexpr __4ee;

                __4ee = typ__4exprFP5table(__1ss->__O2__4stmt.e, __2tbl);
                if (__4ee->base__4node == 70) {
                    Neval = 0;
                    ((void)eval__4exprFv(__4ee->__O3__4expr.e2));
                    if (Neval == 0)
                        error__FiPCc((int)'w', (const char *)"constant assignment in condition");
                }
                __1ss->__O2__4stmt.e =
                    (__4ee = check_cond__FP4exprUcP5table(__4ee, (unsigned char)20, __2tbl));

                if (__1ss->s__4stmt && ((__1ss->s__4stmt->base__4node == 118) ||
                                        (__1ss->s__4stmt->base__4node == 117)))
                    error__FP3locPCcRC2eaN33(&__1ss->s__4stmt->where__4stmt,
                                             (const char *)"D as onlyS after `if'",
                                             (const struct ea *)ea0, (const struct ea *)ea0,
                                             (const struct ea *)ea0, (const struct ea *)ea0);

                if (__4ee->__O1__4expr.tp)
                    switch (__4ee->__O1__4expr.tp->base__4node) {
                    case 21:
                    case 121:
                    case 138: {
                        long long __6i;
                        Neval = 0;
                        __6i = eval__4exprFv(__4ee);

                        if (Neval == 0) {
                            Pstmt __7sl;

                            __7sl = __1ss->s_list__4stmt;
                            if (__6i) {
                                if (__1ss->__O3__4stmt.else_stmt &&
                                    (__1ss->__O3__4stmt.else_stmt->permanent__4node == 0))
                                    del__4stmtFv(__1ss->__O3__4stmt.else_stmt);
                                dcl__4stmtFi(__1ss->s__4stmt, 0);
                                ((*__1ss)) = (*__1ss->s__4stmt);
                            } else {
                                if (__1ss->s__4stmt && (__1ss->s__4stmt->permanent__4node == 0))
                                    del__4stmtFv(__1ss->s__4stmt);
                                if (__1ss->__O3__4stmt.else_stmt) {
                                    dcl__4stmtFi(__1ss->__O3__4stmt.else_stmt, 0);
                                    ((*__1ss)) = (*__1ss->__O3__4stmt.else_stmt);
                                } else {
                                    __1ss->base__4node = 72;
                                    __1ss->__O2__4stmt.e = dummy;
                                    __1ss->s__4stmt = 0;
                                }
                            }
                            __1ss->s_list__4stmt = __7sl;
                            continue;
                        }
                    }
                    }
                if (__1ss->s__4stmt->base__4node != 117)
                    dcl__4stmtFi(__1ss->s__4stmt, 0);
                if (__1ss->__O3__4stmt.else_stmt) {
                    if ((__1ss->__O3__4stmt.else_stmt->base__4node == 118) ||
                        (__1ss->__O3__4stmt.else_stmt->base__4node == 117))
                        error__FP3locPCcRC2eaN33(&__1ss->__O3__4stmt.else_stmt->where__4stmt,
                                                 (const char *)"D as onlyS after `else'",
                                                 (const struct ea *)ea0, (const struct ea *)ea0,
                                                 (const struct ea *)ea0, (const struct ea *)ea0);
                    if (__1ss->__O3__4stmt.else_stmt->base__4node != 117)
                        dcl__4stmtFi(__1ss->__O3__4stmt.else_stmt, 0);
                }
                break;
            }

            case 16:
                inline_restr |= 8;
                __2old_loop = curr_loop;
                curr_loop = __1ss;
                if (__1ss->__O3__4stmt.for_init) {
                    Pstmt __4fi;

                    __4fi = __1ss->__O3__4stmt.for_init;
                    switch (__4fi->base__4node) {
                    case 72:
                        if (__4fi->__O2__4stmt.e == dummy) {
                            __1ss->__O3__4stmt.for_init = 0;
                            break;
                        }
                        dcl__4stmtFi(__4fi, 0);
                        break;
                    default: {
                        Pstmt __6tmp;

                        __6tmp = __ct__4stmtFUc3locP4stmt((struct stmt *)0, (unsigned char)72,
                                                          curloc, (struct stmt *)0);
                        ((*__6tmp)) = (*__1ss);
                        __6tmp->__O3__4stmt.for_init = 0;
                        __4fi->s_list__4stmt = __6tmp;
                        ((*__1ss)) = (*__4fi);
                        curr_loop = __2old_loop;
                        dcl__4stmtFi(__1ss, 1);
                        __6tmp = __1ss->s_list__4stmt;
                        if (((__1ss->base__4node == 118) && (__6tmp->base__4node == 16)) &&
                            (__6tmp->__O3__4stmt.for_init == 0)) {
                            ((*__4fi)) = (*__1ss);
                            ((*__1ss)) = (*__6tmp);
                            __1ss->__O3__4stmt.for_init = __4fi;
                            __4fi->s_list__4stmt = 0;
                        } else {
                            register struct block *__0__X97;

                            struct loc __2__X98;

                            struct loc __2__X99;

                            ((*__4fi)) = (*__1ss);
                            __6tmp = (struct stmt
                                          *)((__0__X97 = 0),
                                             ((__2__X98 = __1ss->where__4stmt),
                                              ((__2__X99 = noloc),
                                               (((__0__X97 ||
                                                  (__0__X97 = (struct block *)__nw__4stmtSFUl(
                                                       (size_t)(sizeof(struct block)))))
                                                     ? (((void)((__0__X97 = (struct block *)
                                                                     __ct__4stmtFUc3locP4stmt(
                                                                         ((struct stmt *)__0__X97),
                                                                         (unsigned char)116,
                                                                         __2__X98, __4fi)),
                                                                ((__0__X97->__O1__4stmt.d =
                                                                      ((struct name *)0)),
                                                                 (__0__X97->__O3__4stmt.where2 =
                                                                      __2__X99)))))
                                                     : (((void)0))),
                                                __0__X97))));
                            __6tmp->__O2__4stmt.own_tbl = 0;
                            __6tmp->memtbl__4stmt = curr_block->memtbl__4stmt;
                            __6tmp->permanent__4node = __1ss->permanent__4node;
                            ((*__1ss)) = (*__6tmp);
                            __6tmp->permanent__4node = 0;

                            ((__6tmp ? (((void)(__6tmp ? (((void)(((void)__dl__4stmtSFPvUl(
                                                             (void *)__6tmp,
                                                             (size_t)(sizeof(struct stmt)))))))
                                                       : (((void)0)))))
                                     : (((void)0))));
                        }

                        goto done;
                    }
                    }
                }
                if (__1ss->__O2__4stmt.e == dummy)
                    __1ss->__O2__4stmt.e = 0;
                else {
                    __1ss->__O2__4stmt.e = typ__4exprFP5table(__1ss->__O2__4stmt.e, __2tbl);

                    if (Ntmp) {
                        Ntmp_dtor = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                           __1ss->__O2__4stmt.e, Ntmp_dtor);
                    }
                    __1ss->__O2__4stmt.e = check_cond__FP4exprUcP5table(__1ss->__O2__4stmt.e,
                                                                        (unsigned char)16, __2tbl);
                }
                {
                    Pstmt __4st;

                    __4st = __1ss->s__4stmt;
                    while (__4st && (__4st->base__4node == 16))
                        __4st = __4st->__O3__4stmt.for_init;
                    if (__4st && ((__4st->base__4node == 118) || (__4st->base__4node == 117)))
                        if (__4st == __1ss->s__4stmt)
                            error__FP3locPCcRC2eaN33(&__1ss->s__4stmt->where__4stmt,
                                                     (const char *)"D as onlyS in for-loop",
                                                     (const struct ea *)ea0, (const struct ea *)ea0,
                                                     (const struct ea *)ea0,
                                                     (const struct ea *)ea0);
                }
                if (__1ss->s__4stmt->base__4node != 117)
                    dcl__4stmtFi(__1ss->s__4stmt, 0);
                __1ss->__O1__4stmt.e2 = ((__1ss->__O1__4stmt.e2 == dummy)
                                             ? (((struct expr *)0))
                                             : typ__4exprFP5table(__1ss->__O1__4stmt.e2, __2tbl));
                curr_loop = __2old_loop;
                break;

            case 215: { /* RANGE_FOR */
                Pstmt __4old_loop215;
                __4old_loop215 = curr_loop;
                curr_loop = __1ss;
                /* type-check the range expression */
                if (__1ss->__O2__4stmt.e && __1ss->__O2__4stmt.e != dummy)
                    __1ss->__O2__4stmt.e = typ__4exprFP5table(__1ss->__O2__4stmt.e, __2tbl);
                /* declare the loop variable: pretend ARG scope so that
                 * "uninitializedR"/"uninitialized const" checks are suppressed.
                 * The actual initialisation is emitted by print.c in the C output. */
                if (__1ss->__O1__4stmt.d) {
                    __1ss->__O1__4stmt.d->n_scope__4name = 136; /* ARG */
                    dcl__4nameFP5tableUc(__1ss->__O1__4stmt.d, __2tbl, (unsigned char)0);
                    __1ss->__O1__4stmt.d->n_scope__4name = 0;
                }
                /* process the body */
                if (__1ss->s__4stmt)
                    dcl__4stmtFi(__1ss->s__4stmt, 0);
                curr_loop = __4old_loop215;
                break;
            }

            case 118: {
                int __4non_trivial;
                int __4count;
                Pname __4tail;
                Pname __4nn;

                __4non_trivial = 0;
                __4count = 0;
                __4tail = __1ss->__O1__4stmt.d;
                __4nn = __4tail;
                for (__4nn = __4tail; __4nn; __4nn = __4nn->__O1__4name.n_list) {
                    __4count++;

                    if (__4nn->__O1__4name.n_list)
                        __4tail = __4nn->__O1__4name.n_list;
                    {
                        Pname __5n;

                        __5n =
                            look__5tableFPCcUc(__2tbl, __4nn->__O2__4expr.string, (unsigned char)0);

                        if (__5n && (__5n->__O4__4expr.n_table == __2tbl))
                            __4non_trivial = 2;
                        if (__4non_trivial >= 2)
                            continue;
                        if ((((__4nn->n_sto__4name == 31) &&
                              (__4nn->__O1__4expr.tp->base__4node != 108)) ||
                             is_ref__4typeFv(__4nn->__O1__4expr.tp)) ||
                            (tconst__4typeFv(__4nn->__O1__4expr.tp) && (fct_const == 0))) {
                            __4non_trivial = 2;
                            continue;
                        }

                        if (__4nn->base__4node == 85) {
                            Pexpr __6in;

                            __6in = __4nn->__O3__4expr.n_initializer;
                            if (__6in)
                                switch (__6in->base__4node) {
                                case 124:
                                case 81:
                                    __4non_trivial = 2;
                                    continue;
                                }

                            if (__6in)
                                __4non_trivial = 3;
                            else
                                __4non_trivial = 1;
                        }
                        {
                            Pname __5cln;

                            struct classdef *__0__X100;

                            struct classdef *__0__X101;

                            __5cln = is_cl_obj__4typeFv(__4nn->__O1__4expr.tp);
                            if (__5cln == 0)
                                __5cln = cl_obj_vec;
                            if (__5cln == 0)
                                continue;
                            if (((__0__X100 = (((struct classdef *)((
                                      (struct classdef *)__5cln->__O1__4expr.tp))))),
                                 (__0__X100->c_ctor__8classdef))) {
                                __4non_trivial = 3;

                                continue;
                            }
                            if (((__0__X101 = (((struct classdef *)((
                                      (struct classdef *)__5cln->__O1__4expr.tp))))),
                                 (__0__X101->c_dtor__8classdef)))
                                __4non_trivial = 2;
                        }
                    }
                }

                while (__1ss->s_list__4stmt && (__1ss->s_list__4stmt->base__4node == 118)) {
                    Pstmt __5sx;

                    __5sx = __1ss->s_list__4stmt;
                    __4tail = (__4tail->__O1__4name.n_list = __5sx->__O1__4stmt.d);
                    for (__4nn = __5sx->__O1__4stmt.d; __4nn; __4nn = __4nn->__O1__4name.n_list) {
                        __4count++;
                        if (__4nn->__O1__4name.n_list)
                            __4tail = __4nn->__O1__4name.n_list;
                        {
                            Pname __6n;

                            __6n = look__5tableFPCcUc(__2tbl, __4nn->__O2__4expr.string,
                                                      (unsigned char)0);
                            if (__6n && (__6n->__O4__4expr.n_table == __2tbl))
                                __4non_trivial = 2;
                            if (__4non_trivial >= 2)
                                continue;
                            if ((((__4nn->n_sto__4name == 31) &&
                                  (__4nn->__O1__4expr.tp->base__4node != 108)) ||
                                 is_ref__4typeFv(__4nn->__O1__4expr.tp)) ||
                                (tconst__4typeFv(__4nn->__O1__4expr.tp) && (fct_const == 0))) {
                                __4non_trivial = 2;
                                continue;
                            }
                            if (__4nn->base__4node == 85) {
                                Pexpr __7in;

                                __7in = __4nn->__O3__4expr.n_initializer;
                                if (__7in)
                                    switch (__7in->base__4node) {
                                    case 124:
                                    case 81:
                                        __4non_trivial = 2;
                                        continue;
                                    }
                            }

                            __4non_trivial = 1;
                            {
                                Pname __6cln;

                                struct classdef *__0__X102;

                                struct classdef *__0__X103;

                                __6cln = is_cl_obj__4typeFv(__4nn->__O1__4expr.tp);
                                if (__6cln == 0)
                                    __6cln = cl_obj_vec;
                                if (__6cln == 0)
                                    continue;
                                if (((__0__X102 = (((struct classdef *)((
                                          (struct classdef *)__6cln->__O1__4expr.tp))))),
                                     (__0__X102->c_ctor__8classdef))) {
                                    __4non_trivial = 2;

                                    continue;
                                }
                                if (((__0__X103 = (((struct classdef *)((
                                          (struct classdef *)__6cln->__O1__4expr.tp))))),
                                     (__0__X103->c_dtor__8classdef)))
                                    __4non_trivial = 2;
                            }
                        }
                    }
                    __1ss->s_list__4stmt = __5sx->s_list__4stmt;
                }

                {
                    Pstmt __4next_st;

                    __4next_st = __1ss->s_list__4stmt;

                    if (((__4non_trivial == 3) || (__4non_trivial == 2)) ||
                        ((__4non_trivial == 1) &&
                         ((curr_block->__O2__4stmt.own_tbl == 0) || (inline_restr & 3)))) {
                        if (curr_switch && (__4non_trivial >= 2)) {
                            if ((curr_case == 0) || (block_since_case == 0))
                                if (__4non_trivial == 3)
                                    error__FPCc(
                                        (const char
                                             *)"jump past initializer (did you forget a '{ }'?)");
                                else
                                    error__FPCc((const char *)"non trivialD in switchS (try "
                                                              "enclosing it in a block)");
                        }

                        {
                            Pname __6lastnn;

                            __6lastnn = 0;
                            for (__4nn = __1ss->__O1__4stmt.d; __4nn;
                                 __4nn = __4nn->__O1__4name.n_list) {
                                Pname __7n;

                                if ((((((__7n = look__5tableFPCcUc(curr_block->memtbl__4stmt,
                                                                   __4nn->__O2__4expr.string,
                                                                   (unsigned char)0)) &&
                                        (__7n->__O4__4expr.n_table->real_block__5table ==
                                         curr_block->memtbl__4stmt->real_block__5table)) &&
                                       (__7n->__O1__4expr.tp->base__4node != 108)) &&
                                      (__7n->__O1__4expr.tp->base__4node != 76)) &&
                                     (__4nn->lex_level__4name == __7n->lex_level__4name)) ||
                                    (__1forflag &&
                                     for_check__FP4nameP4stmt(
                                         __7n = __4nn,
                                         curr_block->memtbl__4stmt->real_block__5table))) {
                                    {
                                        struct ea __0__V83;

                                        error__FPCcRC2eaN32(
                                            (const char *)"twoDs of%n",
                                            (const struct ea *)(((&__0__V83)->__O1__2ea.p =
                                                                     ((const void *)__7n)),
                                                                (&__0__V83)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                        if (__6lastnn == 0)
                                            __1ss->__O1__4stmt.d = __4nn->__O1__4name.n_list;
                                        else
                                            __6lastnn->__O1__4name.n_list =
                                                __4nn->__O1__4name.n_list;
                                    }
                                } else
                                    __6lastnn = __4nn;
                            }
                        }

                        __1ss->s__4stmt = __4next_st;
                        __1ss->s_list__4stmt = 0;

                        __1ss->memtbl__4stmt = __ct__5tableFsP5tableP4name(
                            (struct table *)0, (short)(__4count + 4), __2tbl, (struct name *)0);
                        __1ss->memtbl__4stmt->real_block__5table =
                            curr_block->memtbl__4stmt->real_block__5table;
                        dcl__5blockFP5table(((struct block *)(((struct block *)__1ss))),
                                            __1ss->memtbl__4stmt);
                    } else {
                        Pstmt __5sss;

                        __5sss = __1ss;
                        {
                            Pname __6lastnn;

                            __6lastnn = 0;
                            for (__4nn = __1ss->__O1__4stmt.d; __4nn;
                                 __4nn = __4nn->__O1__4name.n_list) {
                                Pname __7n;

                                struct estmt *__0__X104;

                                struct loc __2__X105;

                                if ((((((__7n = look__5tableFPCcUc(curr_block->memtbl__4stmt,
                                                                   __4nn->__O2__4expr.string,
                                                                   (unsigned char)0)) &&
                                        (__7n->__O4__4expr.n_table->real_block__5table ==
                                         curr_block->memtbl__4stmt->real_block__5table)) &&
                                       (__7n->__O1__4expr.tp->base__4node != 108)) &&
                                      (__7n->__O1__4expr.tp->base__4node != 76)) &&
                                     (__4nn->lex_level__4name == __7n->lex_level__4name)) ||
                                    (__1forflag &&
                                     for_check__FP4nameP4stmt(
                                         __7n = __4nn,
                                         curr_block->memtbl__4stmt->real_block__5table))) {
                                    {
                                        struct ea __0__V84;

                                        error__FPCcRC2eaN32(
                                            (const char *)"twoDs of%n",
                                            (const struct ea *)(((&__0__V84)->__O1__2ea.p =
                                                                     ((const void *)__7n)),
                                                                (&__0__V84)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                        __7n = 0;
                                        if (__6lastnn == 0)
                                            __1ss->__O1__4stmt.d = __4nn->__O1__4name.n_list;
                                        else
                                            __6lastnn->__O1__4name.n_list =
                                                __4nn->__O1__4name.n_list;
                                    }
                                } else {
                                    __7n = dcl__4nameFP5tableUc(__4nn, __2tbl, (unsigned char)108);
                                    __6lastnn = __4nn;
                                }

                                if (__7n == 0) {
                                    if (__1ss) {
                                        __1ss->base__4node = 72;
                                        __1ss->__O2__4stmt.e = 0;
                                    }
                                    continue;
                                }

                                if (__1ss) {
                                    __5sss->base__4node = 72;
                                    __1ss = 0;
                                } else
                                    __5sss =
                                        (__5sss->s_list__4stmt =
                                             (struct stmt
                                                  *)((__0__X104 = 0),
                                                     ((__2__X105 = __5sss->where__4stmt),
                                                      (((__0__X104 ||
                                                         (__0__X104 =
                                                              (struct estmt *)__nw__4stmtSFUl(
                                                                  (size_t)(sizeof(struct estmt)))))
                                                            ? ((__0__X104 = (struct estmt *)
                                                                    __ct__4stmtFUc3locP4stmt(
                                                                        ((struct stmt *)__0__X104),
                                                                        ((unsigned char)72),
                                                                        __2__X105,
                                                                        ((struct stmt *)0))),
                                                               (__0__X104->__O2__4stmt.e =
                                                                    ((struct expr *)0)))
                                                            : 0),
                                                       __0__X104))));
                                if ((__7n->base__4node == 85) && __7n->__O3__4expr.n_initializer) {
                                    Pexpr __8in;

                                    __8in = __7n->__O3__4expr.n_initializer;
                                    __7n->__O3__4expr.n_initializer = 0;
                                    switch (__8in->base__4node) {
                                    case 146: {
                                        Pname __10fn;

                                        __10fn = __8in->__O4__4expr.fct_name;
                                        if (__10fn && (__10fn->n_oper__4name == 161))
                                            break;
                                    }
                                    default:
                                        __8in = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                       (unsigned char)70,
                                                                       (struct expr *)__7n, __8in);
                                        __8in->__O1__4expr.tp = __7n->__O1__4expr.tp;
                                    }
                                    __5sss->__O2__4stmt.e = __8in;
                                    __5sss->where__4stmt = __7n->where__4name;
                                } else
                                    __5sss->__O2__4stmt.e = dummy;
                            }
                        }

                        __1ss = __5sss;
                        __1ss->s_list__4stmt = __4next_st;
                    }
                    break;
                }
            }

            case 116:
                dcl__5blockFP5table(((struct block *)(((struct block *)__1ss))), __2tbl);
                break;

            case 1: {
                char *__4s;
                int __4ll;
                char *__4s2;

                __4s = (((char *)__1ss->__O2__4stmt.e));
                __4ll = strlen((const char *)__4s);
                __4s2 = (((char *)__nw__FUl((size_t)((sizeof(char)) * (__4ll + 1)))));
                strcpy(__4s2, (const char *)__4s);
                __1ss->__O2__4stmt.e = (((struct expr *)(((struct expr *)__4s2))));
                break;
            }

            default: {
                struct ea __0__V85;

                struct ea __0__V86;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"badS(%p %d)",
                    (const struct ea *)(((&__0__V85)->__O1__2ea.p = ((const void *)__1ss)),
                                        (&__0__V85)),
                    (const struct ea *)((__2__X106 = __1ss->base__4node),
                                        (((((&__0__V86)->__O1__2ea.i = __2__X106), 0)),
                                         (&__0__V86))),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            }
        }
    }
done:
    Cstmt = __1ostmt;
}

int no_of_names__4nameFv(struct name *__0this);

void dcl__5blockFP5table(register struct block *__0this, Ptable __1tbl) {
    int __1bit_old;
    int __1byte_old;
    Pblock __1block_old;
    Pstmt __1save_case;
    Pblock __1old_bsc;

    Pfct __1f;

    unsigned long __2__X112;

    register struct name *__0__X119;

    unsigned long __2__X16;

    struct ea __0__X__V1400qm5nwo3mvcnm;

    struct ea __0__X__V1500qm5nwo3mvcnm;

    __1bit_old = bit_offset;
    __1byte_old = byte_offset;
    __1block_old = curr_block;
    __1save_case = curr_case;
    __1old_bsc = block_since_case;

    __1f =
        ((__0__X119 = cc->nof__11dcl_context),
         (((__0__X119->__O1__4expr.tp->base__4node == 108)
               ? (((struct fct *)(((struct fct *)__0__X119->__O1__4expr.tp))))
               : (error__FiPCcRC2eaN33(
                      (int)'i', (const char *)"N::fct_type():%n is %k notF",
                      (const struct ea *)(((&__0__X__V1400qm5nwo3mvcnm)->__O1__2ea.p =
                                               ((const void *)__0__X119)),
                                          (&__0__X__V1400qm5nwo3mvcnm)),
                      (const struct ea *)((__2__X16 = __0__X119->__O1__4expr.tp->base__4node),
                                          (((((&__0__X__V1500qm5nwo3mvcnm)->__O1__2ea.i = __2__X16),
                                             0)),
                                           (&__0__X__V1500qm5nwo3mvcnm))),
                      (const struct ea *)ea0, (const struct ea *)ea0),
                  (((struct fct *)0))))));

    if ((__0this->base__4node != 116) && (__0this->base__4node != 118)) {
        struct ea __0__V107;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"block::dcl(%d)",
            (const struct ea *)((__2__X112 = __0this->base__4node),
                                (((((&__0__V107)->__O1__2ea.i = __2__X112), 0)), (&__0__V107))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    curr_block = __0this;
    if (curr_case && (__0this->base__4node == 116))
        block_since_case = __0this;

    {
        Pname __1re_decl;

        __1re_decl = 0;
        if (((__1f->f_result__3fct && __0this->s__4stmt) && (__1f->nrv__3fct == 0)) &&
            ((__0this == top_block) ||
             (__0this->memtbl__4stmt &&
              (__0this->memtbl__4stmt->real_block__5table == (((struct stmt *)top_block)))))) {
            Pstmt __2tmp;

            __2tmp = __0this->s__4stmt;
            while ((__2tmp->base__4node != 28) && __2tmp->s_list__4stmt)
                __2tmp = __2tmp->s_list__4stmt;
            if (__2tmp->base__4node == 28) {
                Pname __3tt;
                Pname __3td;

                __3tt = ((__2tmp->__O2__4stmt.e->base__4node == 85)
                             ? (((struct name *)(((struct name *)__2tmp->__O2__4stmt.e))))
                             : (((struct name *)0)));

                if (((__3tt && (__3td = is_decl__FP5blockP4name(curr_block, __3tt))) &&
                     (__3td->n_sto__4name != 31)) &&
                    (check__4typeFP4typeUcT2(__3td->__O1__4expr.tp, __1f->returns__3fct,
                                             (unsigned char)0, (unsigned char)0) == 0)) {
                    __1f->nrv__3fct = __3tt;
                }
            }

            if (__1f->nrv__3fct) {
                if (find_return__FP4stmtP4name(__0this->s__4stmt, __1f->nrv__3fct))
                    __1f->nrv__3fct = 0;
            }
        } else if (__1f->nrv__3fct)
            __1re_decl = is_decl__FP5blockP4name(curr_block, __1f->nrv__3fct);

        {
            Pktab __1otbl;

            __1otbl = Ctbl;
            if (__0this->k_tbl__4stmt)
                Ctbl = __0this->k_tbl__4stmt;
            if (__0this->__O1__4stmt.d) {
                Pname __2nx;

                __0this->__O2__4stmt.own_tbl = 1;
                __0this->base__4node = 116;
                if (__0this->memtbl__4stmt == 0) {
                    int __3nmem;

                    __3nmem = (no_of_names__4nameFv(__0this->__O1__4stmt.d) + 4);
                    __0this->memtbl__4stmt = __ct__5tableFsP5tableP4name(
                        (struct table *)0, (short)__3nmem, __1tbl, (struct name *)0);
                    __0this->memtbl__4stmt->real_block__5table = (struct stmt *)__0this;

                } else if (__0this->memtbl__4stmt != __1tbl)
                    error__FiPCc((int)'i', (const char *)"block::dcl(?)");

                ;
                {
                    {
                        Pname __2n;

                        __2n = __0this->__O1__4stmt.d;

                        for (; __2n; __2n = __2nx) {
                            __2nx = __2n->__O1__4name.n_list;
                            if ((__1f->nrv__3fct && (!__1re_decl)) &&
                                (strcmp(__1f->nrv__3fct->__O2__4expr.string,
                                        __2n->__O2__4expr.string) == 0)) {
                                __2n->__O2__4expr.string = (const char *)"__NRV";
                            }
                            dcl__4nameFP5tableUc(__2n, __0this->memtbl__4stmt, (unsigned char)108);
                            switch (__2n->__O1__4expr.tp->base__4node) {
                            case 6:
                            case 167:
                            case 13:
                                break;
                            default:
                                ((__2n
                                      ? (((void)(__2n
                                                     ? (((void)((((((struct expr *)__2n))
                                                                      ? (((void)((((struct expr *)
                                                                                       __2n))
                                                                                     ? (((void)(((
                                                                                           void)0))))
                                                                                     : (((void)0)))))
                                                                      : (((void)0)))),
                                                                (((void)__dl__4nameSFPvUl(
                                                                    (void *)__2n,
                                                                    (size_t)(sizeof(
                                                                        struct name))))))))
                                                     : (((void)0)))))
                                      : (((void)0))));
                            }
                        }
                    }
                }
            } else if (__0this->base__4node == 116) {
                __0this->__O2__4stmt.own_tbl = 1;
                if (__0this->memtbl__4stmt == 0) {
                    int __3nmem;

                    __3nmem = 4;
                    __0this->memtbl__4stmt = __ct__5tableFsP5tableP4name(
                        (struct table *)0, (short)__3nmem, __1tbl, (struct name *)0);
                    __0this->memtbl__4stmt->real_block__5table = (struct stmt *)__0this;

                } else if (__0this->memtbl__4stmt != __1tbl)
                    error__FiPCc((int)'i', (const char *)"block::dcl(?)");
            } else {
                __0this->base__4node = 116;
                __0this->memtbl__4stmt = __1tbl;
            }

            {
                Pname __1odcl;

                __1odcl = Cdcl;
                if (__0this->s__4stmt)
                    dcl__4stmtFi(__0this->s__4stmt, 0);
                if (__0this->__O2__4stmt.own_tbl) {
                    Pname __2m;
                    int __2i;

                    struct table *__0__X113;

                    int __2__X114;

                    struct table *__0__X115;

                    int __2__X116;

                    for (__2m =
                             ((__0__X113 = __0this->memtbl__4stmt),
                              ((__2__X114 = (__2i = 1)),
                               ((((__2__X114 <= 0) || (__0__X113->free_slot__5table <= __2__X114))
                                     ? (((struct name *)0))
                                     : (__0__X113->entries__5table[__2__X114])))));
                         __2m;
                         __2m = (__2m->n_tbl_list__4name
                                     ? __2m->n_tbl_list__4name
                                     : ((__0__X115 = __0this->memtbl__4stmt),
                                        ((__2__X116 = (++__2i)),
                                         ((((__2__X116 <= 0) ||
                                            (__0__X115->free_slot__5table <= __2__X116))
                                               ? (((struct name *)0))
                                               : (__0__X115->entries__5table[__2__X116]))))))) {

                        Ptype __3t;

                        __3t = __2m->__O1__4expr.tp;

                        if (in_class_dcl)
                            __2m->lex_level__4name -= 1;

                        if (__3t == 0) {
                            const void *__2__X117;

                            const void *__2__X118;

                            if (__2m->n_assigned_to__4name == 0) {
                                struct ea __0__V108;

                                error__FPCcRC2eaN32(
                                    (const char *)"label %sU",
                                    (const struct ea *)((__2__X117 = (const void *)
                                                                         __2m->__O2__4expr.string),
                                                        (((&__0__V108)->__O1__2ea.p = __2__X117),
                                                         (&__0__V108))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            if (__2m->n_used__4name == 0) {
                                struct ea __0__V109;

                                error__FiP3locPCcRC2eaN34(
                                    (int)'w', &__2m->where__4name,
                                    (const char *)"label %s not used",
                                    (const struct ea *)((__2__X118 = (const void *)
                                                                         __2m->__O2__4expr.string),
                                                        (((&__0__V109)->__O1__2ea.p = __2__X118),
                                                         (&__0__V109))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            continue;
                        }

                        __3t = skiptypedefs__4typeFv(__3t);

                        switch (__3t->base__4node) {
                        case 6:
                        case 167:
                        case 13:
                        case 108:
                            continue;
                        }

                        if (__2m->n_addr_taken__4name == 0) {
                            if (__2m->n_used__4name) {
                                if (((__2m->n_assigned_to__4name == 0) &&
                                     (__3t->base__4node != 110)) &&
                                    (__2m->n_scope__4name == 108)) {
                                    Cdcl = __2m;
                                    if (((__2m->__O2__4expr.string[0]) != '_') &&
                                        ((__2m->__O2__4expr.string[1]) != '_')) {
                                        struct ea __0__V110;

                                        error__FiP3locPCcRC2eaN34(
                                            (int)'w', &__2m->where__4name,
                                            (const char *)"%n used but not set",
                                            (const struct ea *)(((&__0__V110)->__O1__2ea.p =
                                                                     ((const void *)__2m)),
                                                                (&__0__V110)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                    }
                                }
                            } else {
                                if (((__2m->n_assigned_to__4name == 0) &&
                                     (((__2m->__O2__4expr.string[0]) != '_') ||
                                      ((__2m->__O2__4expr.string[1]) != '_'))) &&
                                    ((__2m->n_scope__4name == 136) ||
                                     (__2m->n_scope__4name == 108))) {
                                    Cdcl = __2m;
                                    {
                                        struct ea __0__V111;

                                        error__FiP3locPCcRC2eaN34(
                                            (int)'w', &__2m->where__4name,
                                            (const char *)"%n not used",
                                            (const struct ea *)(((&__0__V111)->__O1__2ea.p =
                                                                     ((const void *)__2m)),
                                                                (&__0__V111)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                    }
                                }
                            }
                        }
                    }
                }
                Cdcl = __1odcl;

                __0this->__O1__4stmt.d = 0;

                if (bit_offset)
                    byte_offset += SZ_WORD;
                bit_offset = __1bit_old;
                byte_offset = __1byte_old;
                if (curr_case == __1save_case)
                    block_since_case = __1old_bsc;
                curr_block = __1block_old;
                Ctbl = __1otbl;
            }
        }
    }
}

int align__4typeFv(struct type *__0this);

void field_align__4nameFv(register struct name *__0this) {
    Pbase __1fld;
    int __1nbits;

    int __1a;

    __1fld = (((struct basetype *)(((struct basetype *)__0this->__O1__4expr.tp))));
    __1nbits = __1fld->b_bits__8basetype;

    __1a = (F_SENSITIVE ? align__4typeFv(__1fld->__O1__8basetype.b_fieldtype) : SZ_WORD);

    if (max_align < __1a)
        max_align = __1a;

    if (__1nbits == 0) {
        int __2b;
        if (bit_offset)
            __1nbits = (BI_IN_WORD - bit_offset);
        else if (__2b = (byte_offset % SZ_WORD))
            __1nbits = (__2b * BI_IN_BYTE);
        if (max_align < SZ_WORD)
            max_align = SZ_WORD;
    } else if (bit_offset == 0) {
        int __2b;

        __2b = (byte_offset % SZ_WORD);
        if (__2b) {
            byte_offset -= __2b;
            bit_offset = (__2b * BI_IN_BYTE);
        }
    }

    {
        int __1x;

        __1x = (bit_offset += __1nbits);
        if ((SZ_INT * BI_IN_BYTE) < __1x) {
            __1fld->b_offset__8basetype = 0;
            byte_offset += SZ_INT;
            bit_offset = __1nbits;
        } else {
            __1fld->b_offset__8basetype = bit_offset;
            if ((SZ_INT * BI_IN_BYTE) == __1x) {
                bit_offset = 0;
                byte_offset += SZ_INT;
            } else
                bit_offset = __1x;
        }
        __0this->n_offset__4name = byte_offset;
    }
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

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp) {
    if (__0this || (__0this = (struct ea *)__nw__FUl((unsigned long)(sizeof(struct ea)))))
        __0this->__O1__2ea.p = __2pp;

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
