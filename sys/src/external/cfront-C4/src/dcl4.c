
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

bit has_base__8classdefFP8classdefiT2(struct classdef *__0this, Pclass __1cl, int __1level,
                                      int __1ccflag);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

static Pname get_vf__FP4nameP8classdef(Pname __1n_pvf, Pclass __1cl);

static Pname get_vf__FP4nameP8classdef(Pname __1n_pvf, Pclass __1cl) {
    if ((!__1n_pvf) || (!__1cl))
        return (struct name *)0;

    if (__1n_pvf->__O1__4expr.tp &&
        (!has_base__8classdefFP8classdefiT2(
            __1cl, (((struct fct *)(((struct fct *)__1n_pvf->__O1__4expr.tp))))->memof__3fct, 0,
            0))) {

        return (struct name *)0;
    }
    {
        Pname __1n_vf;

        __1n_vf = look__5tableFPCcUc(__1cl->memtbl__8classdef, __1n_pvf->__O2__4expr.string,
                                     (unsigned char)0);
        if ((__1n_vf && __1n_pvf->__O1__4expr.tp) && __1n_vf->__O1__4expr.tp) {
            if (__1n_vf->__O1__4expr.tp->base__4node == 76) {
                Plist __3gl;

                __3gl = (((struct gen *)(((struct gen *)__1n_vf->__O1__4expr.tp))))->fct_list__3gen;
                for (; __3gl; __3gl = __3gl->l__9name_list) {
                    if (!check__4typeFP4typeUcT2((struct type *)(((struct fct *)((
                                                     (struct fct *)__1n_pvf->__O1__4expr.tp)))),
                                                 __3gl->f__9name_list->__O1__4expr.tp,
                                                 (unsigned char)77, (unsigned char)0))
                        break;
                }
                if (!__3gl)
                    __1n_vf = 0;
            } else {
                if (check__4typeFP4typeUcT2(
                        (struct type *)(((struct fct *)(((struct fct *)__1n_pvf->__O1__4expr.tp)))),
                        (struct type *)(((struct fct *)(((struct fct *)__1n_vf->__O1__4expr.tp)))),
                        (unsigned char)77, (unsigned char)0))
                    __1n_vf = 0;
            }
        }

        if (__1n_vf == 0) {
            {
                {
                    Pbcl __2b;

                    __2b = __1cl->baselist__8classdef;

                    for (; __2b; __2b = __2b->next__6basecl) {
                        if ((__2b->base__4node == 85) || (__2b->base__4node == 77)) {
                            __1n_vf = get_vf__FP4nameP8classdef(__1n_pvf, __2b->bclass__6basecl);
                            if (__1n_vf && (!__1n_vf->__O3__4expr.n_initializer)) {
                                break;
                            } else {
                                __1n_vf = 0;
                            }
                        }
                    }
                }
            }
        }

        return __1n_vf;
    }
}

Pname is_cl_obj__4typeFv(struct type *__0this);

void fix_args__FP3fctP8classdef(Pfct __1f, Pclass __1cl) {
    {
        {
            Pname __1a;

            __1a = __1f->argtype__3fct;

            for (; __1a; __1a = __1a->__O1__4name.n_list) {
                Pname __2n;

                struct classdef *__1__X26;

                struct classdef *__1__X27;

                __2n = is_cl_obj__4typeFv(__1a->__O1__4expr.tp);
                if (__2n &&
                    ((__1__X26 =
                          (((struct classdef *)(((struct classdef *)__2n->__O1__4expr.tp))))),
                     ((__1__X27 = __1cl),
                      (((__1__X26 == __1__X27)
                            ? 1
                            : ((__1__X26 && __1__X27) ? (((int)same_class__8classdefFP8classdefi(
                                                            __1__X26, __1__X27, 0)))
                                                      : 0))))))
                    __1a->n_xref__4name = 1;
            }
        }
    }
}
struct typedef_info;

static struct typedef_info *typedef_info_head = 0;

static struct typedef_info *typedef_info_tail = 0;

static Pfct get_fct_node__FP4name(Pname __1n) {
    Ptype __1t;

    __1t =
        (__1n->__O1__4expr.tp ? skiptypedefs__4typeFv(__1n->__O1__4expr.tp) : (((struct type *)0)));

    if (__1t && (__1t->base__4node == 158))
        __1t = skiptypedefs__4typeFv((((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp);

    while (__1t && (__1t->base__4node == 125))
        __1t = skiptypedefs__4typeFv((((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp);

    return ((__1t && (__1t->base__4node == 108)) ? (((struct fct *)(((struct fct *)__1t))))
                                                 : (((struct fct *)0)));
}

struct typedef_info { /* sizeof typedef_info == 16 */
    Pname n__12typedef_info;
    struct typedef_info *next__12typedef_info;
};

static void record_typedef__FP4name(Pname __1tn) {
    struct typedef_info *__1p;

    __1p = (((struct typedef_info *)__nw__FUl(sizeof(struct typedef_info))));
    __1p->n__12typedef_info = __1tn;
    if (typedef_info_head == 0) {
        typedef_info_head = (typedef_info_tail = __1p);
    } else {
        typedef_info_tail->next__12typedef_info = __1p;
        typedef_info_tail = __1p;
    }
}

void typedef_check__FP4name(Pname __1n) {
    Pname __1cn;
    Pfct __1f;

    __1f = get_fct_node__FP4name(__1n);

    if (!__1f)
        return;

    {
        {
            Pname __1a;

            __1a = __1f->argtype__3fct;

            for (; __1a; __1a = __1a->__O1__4name.n_list) {
                __1cn = (__1a->__O1__4expr.tp ? is_cl_obj__4typeFv(__1a->__O1__4expr.tp)
                                              : (((struct name *)0)));
                if ((((!__1a->n_xref__4name) && __1cn) && __1cn->__O1__4expr.tp) &&
                    (!((((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))))
                           ->defined__4type &
                       01))) {

                    record_typedef__FP4name(__1n);
                    return;
                }
            }

            __1cn = (__1f->returns__3fct ? is_cl_obj__4typeFv(__1f->returns__3fct)
                                         : (((struct name *)0)));
            if (((((!__1f->s_returns__3fct) ||
                   (__1f->s_returns__3fct != (((struct type *)void_type)))) &&
                  __1cn) &&
                 __1cn->__O1__4expr.tp) &&
                (!((((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))))
                       ->defined__4type &
                   01)))
                record_typedef__FP4name(__1n);
        }
    }
}

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

static void typedef_checkall__FP8classdef(Pclass __1cl) {
    {
        {
            struct typedef_info *__1p;

            __1p = typedef_info_head;

            for (; __1p; __1p = __1p->next__12typedef_info) {
                Pfct __2f;
                Pname __2cn;

                __2f = get_fct_node__FP4name(__1p->n__12typedef_info);

                {
                    {
                        Pname __2a;

                        struct classdef *__1__X36;

                        struct classdef *__1__X37;

                        __2a = __2f->argtype__3fct;

                        for (; __2a; __2a = __2a->__O1__4name.n_list) {
                            struct classdef *__1__X34;

                            struct classdef *__1__X35;

                            __2cn = (__2a->__O1__4expr.tp ? is_cl_obj__4typeFv(__2a->__O1__4expr.tp)
                                                          : (((struct name *)0)));
                            if (((((!__2a->n_xref__4name) && __2cn) && __2cn->__O1__4expr.tp) &&
                                 ((__1__X34 = (((struct classdef *)((
                                       (struct classdef *)__2cn->__O1__4expr.tp))))),
                                  ((__1__X35 = __1cl),
                                   (((__1__X34 == __1__X35)
                                         ? 1
                                         : ((__1__X34 && __1__X35)
                                                ? (((int)same_class__8classdefFP8classdefi(
                                                      __1__X34, __1__X35, 0)))
                                                : 0)))))) &&
                                (__1cl->c_itor__8classdef)) {
                                {
                                    struct ea __0__V28;

                                    struct ea __0__V29;

                                    struct ea __0__V30;

                                    error__FiP3locPCcRC2eaN34(
                                        (int)'s', &__1p->n__12typedef_info->where__4name,
                                        (const char *)"C%t used asAT inTdef%n before it was known "
                                                      "that%t has a copyK",
                                        (const struct ea *)(((&__0__V28)->__O1__2ea.p =
                                                                 ((const void *)__1cl)),
                                                            (&__0__V28)),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V29, (const void *)__1p->n__12typedef_info),
                                        (const struct ea *)(((&__0__V30)->__O1__2ea.p =
                                                                 ((const void *)__1cl)),
                                                            (&__0__V30)),
                                        (const struct ea *)ea0);
                                    break;
                                }
                            }
                        }
                        __2cn = (__2f->returns__3fct ? is_cl_obj__4typeFv(__2f->returns__3fct)
                                                     : (((struct name *)0)));
                        if ((((((!__2f->s_returns__3fct) ||
                                (__2f->s_returns__3fct != (((struct type *)void_type)))) &&
                               __2cn) &&
                              __2cn->__O1__4expr.tp) &&
                             ((__1__X36 = (((struct classdef *)((
                                   (struct classdef *)__2cn->__O1__4expr.tp))))),
                              ((__1__X37 = __1cl),
                               (((__1__X36 == __1__X37)
                                     ? 1
                                     : ((__1__X36 && __1__X37)
                                            ? (((int)same_class__8classdefFP8classdefi(
                                                  __1__X36, __1__X37, 0)))
                                            : 0)))))) &&
                            (__1cl->c_itor__8classdef)) {
                            struct ea __0__V31;

                            struct ea __0__V32;

                            struct ea __0__V33;

                            error__FiP3locPCcRC2eaN34(
                                (int)'s', &__1p->n__12typedef_info->where__4name,
                                (const char *)"C%t used as returnT inTdef%n before it was known "
                                              "that%t has a copyK",
                                (const struct ea *)(((&__0__V31)->__O1__2ea.p =
                                                         ((const void *)__1cl)),
                                                    (&__0__V31)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V32, (const void *)__1p->n__12typedef_info),
                                (const struct ea *)(((&__0__V33)->__O1__2ea.p =
                                                         ((const void *)__1cl)),
                                                    (&__0__V33)),
                                (const struct ea *)ea0);
                        }
                    }
                }
            }
        }
    }
}

Pname merge_conv__FP4nameT1(Pname __1c1, Pname __1c2) {
    if (__1c1 == 0)
        return __1c2;
    if (__1c2 == 0)
        return __1c1;
    if (__1c1 == __1c2)
        return __1c1;
    error__FiPCc((int)'s', (const char *)"cannot merge lists of conversion functions");
    return __1c1;
}

static int Eppp;

extern int strncmp(const char *, const char *, size_t);

const char *get_classname__FPCc(const char *__1s) {
    const char *__1s1;

    __1s1 = 0;

    while ((*__1s)) {
        __1s1 = __1s;
    loop:
        for (; (__1s[0]) && (((__1s[0]) != '_') || ((__1s[1]) && ((__1s[1]) != '_'))); __1s++)
            ;
        if ((*__1s)) {
            if (strncmp(__1s, (const char *)"___pt__", (unsigned long)7) == 0) {
                __1s += 7;

                goto loop;
            }
            if (strncmp(__1s, (const char *)"__pt__", (unsigned long)6) == 0) {
                __1s += 6;

                goto loop;
            }
            if ((__1s[1]) == 0)
                ++__1s;
            else
                __1s += 2;
        }
    }

    return __1s1;
}

extern size_t strlen(const char *);

extern int sprintf(char *, const char *, ...);

char *drop_classname__FPCc(const char *__1s0) {
    char *__1r;

    __1r = (((char *)__nw__FUl((size_t)((sizeof(char)) * (strlen(__1s0) + 1)))));
    sprintf(__1r, (const char *)"%s", __1s0);
    {
        char *__1s;

        char *__1s1;

        __1s = __1r;

        __1s1 = __1s;
        while ((*__1s)) {
        loop:
            for (; (__1s[0]) && (((__1s[0]) != '_') || ((__1s[1]) && ((__1s[1]) != '_'))); __1s++)
                ;
            if ((*__1s)) {
                if (strncmp((const char *)__1s, (const char *)"___pt__", (unsigned long)7) == 0) {
                    __1s += 7;

                    goto loop;
                }
                if (strncmp((const char *)__1s, (const char *)"__pt__", (unsigned long)6) == 0) {
                    __1s += 6;

                    goto loop;
                }
                if ((__1s[1]) == 0) {
                    __1s1 = (++__1s);

                    break;
                }
                __1s1 = __1s;
                __1s += 2;
            }
        }

        ((*__1s1)) = '\0';
        return (((*__1r)) ? __1r : (((char *)0)));
    }
}

bit is_const_object__4typeFv(struct type *__0this);

bit has_const_mem__8classdefFv(register struct classdef *__0this) {
    int __1i;
    {
        {
            Pname __1m;

            struct table *__0__X38;

            int __2__X39;

            struct table *__0__X40;

            int __2__X41;

            __1m = ((__0__X40 = __0this->memtbl__8classdef),
                    ((__2__X41 = (__1i = 1)),
                     ((((__2__X41 <= 0) || (__0__X40->free_slot__5table <= __2__X41))
                           ? (((struct name *)0))
                           : (__0__X40->entries__5table[__2__X41])))));

            for (; __1m;
                 __1m = (__1m->n_tbl_list__4name
                             ? __1m->n_tbl_list__4name
                             : ((__0__X38 = __0this->memtbl__8classdef),
                                ((__2__X39 = (++__1i)),
                                 ((((__2__X39 <= 0) || (__0__X38->free_slot__5table <= __2__X39))
                                       ? (((struct name *)0))
                                       : (__0__X38->entries__5table[__2__X39])))))))
                if (__1m && __1m->__O1__4expr.tp)
                    switch (__1m->__O1__4expr.tp->base__4node) {
                    case 108:
                        break;
                    case 76:
                        break;
                    case 121:
                        break;
                    default:
                        if (is_const_object__4typeFv(__1m->__O1__4expr.tp) &&
                            (__1m->n_stclass__4name != 31))
                            return (unsigned char)1;
                    }

            return (unsigned char)0;
        }
    }
}

Pbcl get_base__8classdefFPCc(register struct classdef *__0this, const char *__1s) {
    Pbcl __1b;

    __1b = __0this->baselist__8classdef;
    for (; __1b; __1b = __1b->next__6basecl) {
        const char *__2s1;

        const char *__2s2;

        __2s1 = __1s;

        __2s2 = __1b->bclass__6basecl->string__8classdef;
        for (; (((*__2s1)) && ((*__2s2))) && (((*__2s1)) == ((*__2s2))); ((__2s1++), (__2s2++)))
            ;

        if (!(((*__2s1)) || ((*__2s2))))
            break;
    }

    return __1b;
}

extern int strcmp(const char *, const char *);

int has_allocated_base__8classdefFP8classdefUc(struct classdef *__0this, Pclass, bit);

static int offset_magic_0__FP6baseclT1s(Pbcl __1b, Pbcl __1bb, short __1virt_count) {
    Pclass __1bcl;
    int __1offset;

    __1bcl = __1bb->bclass__6basecl;
    __1offset = 0;
    {
        {
            Pbcl __1l;

            __1l = __1b;

            for (; __1l; __1l = __1l->next__6basecl) {
                if (__1l->base__4node == 77)
                    continue;
                {
                    Pclass __2bc;

                    __2bc = __1l->bclass__6basecl;
                    {
                        {
                            Pbcl __2ll;

                            __2ll = __2bc->baselist__8classdef;

                            for (; __2ll; __2ll = __2ll->next__6basecl) {
                                if (__2ll->base__4node != 77)
                                    continue;
                                {
                                    int __3diff;

                                    __3diff = strcmp(__1bcl->string__8classdef,
                                                     __2ll->bclass__6basecl->string__8classdef);

                                    if ((__2ll->allocated__6basecl == 1) && (!__3diff)) {
                                        __1offset = (__2ll->obj_offset__6basecl +
                                                     __1l->obj_offset__6basecl);

                                        return __1offset;
                                    }

                                    if (__3diff && (__2ll->allocated__6basecl == 1)) {
                                        __1offset = has_allocated_base__8classdefFP8classdefUc(
                                            __2ll->bclass__6basecl, __1bcl, (unsigned char)0);

                                        if (__1offset) {
                                            if (!__1virt_count)
                                                __1offset += __1l->obj_offset__6basecl;

                                            return __1offset;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (Nvbc_alloc) {
                __1offset = (__1bb->obj_offset__6basecl - Nvbc_alloc->obj_offset__6basecl);
                if (__1virt_count)
                    __1offset += 4;
            }

            return __1offset;
        }
    }
}

static int offset_magic_1__FP6baseclT1(Pbcl __1b, Pbcl __1bl) {
    const char *__1str;

    __1str = __1b->bclass__6basecl->string__8classdef;
    {
        {
            Pbcl __1bb;

            __1bb = __1bl->bclass__6basecl->baselist__8classdef;

            for (; __1bb; __1bb = __1bb->next__6basecl) {
                if (__1bb->base__4node != 77)
                    continue;
                {
                    const char *__2s;

                    __2s = __1bb->bclass__6basecl->string__8classdef;
                    if (strcmp(__2s, __1str) == 0) {
                        int __3offset;

                        __3offset = ((__1bb->obj_offset__6basecl - __1bb->ptr_offset__6basecl) + 1);

                        return (__3offset + __1bl->obj_offset__6basecl);
                    }
                }
            }

            return 0;
        }
    }
}

extern int link_compat_hack;
static int Voffset;
bit Vvtab = 0;
bit Vvbc_alloc = 0;
bit Vvbc_inher = 0;

const char *has_allocated_base__8classdefFPCc(struct classdef *__0this, const char *);

int get_offset__8classdefFPCcUc(struct classdef *__0this, const char *__1s, bit __1rechk);

int get_offset__8classdefFPCcUc(register struct classdef *__0this, const char *__1s, bit __1rechk) {
    if (!__1s)
        return 0;

    {
        const char *__1str;
        Pbcl __1b;

        bit __1unalloc;
        const char *__1found_virtual;

        __1str = get_classname__FPCc(__1s);
        __1b = get_base__8classdefFPCc(__0this, __1str);

        __1unalloc = 0;
        __1found_virtual = 0;

        if (__1rechk) {
            __1unalloc = (__1b->promoted__6basecl && (__1b->allocated__6basecl != 1));

            if (!__1unalloc)
                return 0;
            Vvtab = 0;
            Vvbc_inher = 0;
            Vvbc_alloc = 0;
            Nvbc_alloc = 0;
            __1found_virtual = has_allocated_base__8classdefFPCc(__0this, __1str);
        }

        if (__1unalloc) {
            if (__1found_virtual == 0) {
                if (Vvbc_alloc && __1b->bclass__6basecl->baselist__8classdef)
                    return __1b->obj_offset__6basecl;

                if (strcmp(__1s, __1str)) {
                    if (Vvbc_inher)
                        return 0;

                    if (Vvtab == 0)
                        return get_offset__8classdefFPCcUc(__1b->bclass__6basecl,
                                                           (const char *)drop_classname__FPCc(__1s),
                                                           (unsigned char)0);

                    return (__1b->obj_offset__6basecl +
                            get_offset__8classdefFPCcUc(__1b->bclass__6basecl,
                                                        (const char *)drop_classname__FPCc(__1s),
                                                        (unsigned char)0));
                } else {
                    if (Vvbc_inher) {
                        if (__1b->allocated__6basecl == 2)
                            link_compat_hack = __1b->obj_offset__6basecl;
                        return 0;
                    }
                    return offset_magic_0__FP6baseclT1s(__0this->baselist__8classdef->next__6basecl,
                                                        __1b, __0this->virt_count__8classdef);
                }
            }

            if (__1found_virtual) {
                if (strcmp(__1s, __1str))
                    return offset_magic_1__FP6baseclT1(
                        __1b, get_base__8classdefFPCc(__0this, __1found_virtual));
                else
                    return __1b->obj_offset__6basecl;
            }
        }

        return (__1b->obj_offset__6basecl +
                get_offset__8classdefFPCcUc(__1b->bclass__6basecl,
                                            (const char *)drop_classname__FPCc(__1s),
                                            (unsigned char)0));
    }
}

const char *vtbl_str__FPCcT1(const char *__1s1, const char *__1s2) {
    char *__1s3;
    if (__1s1)
        if (__1s2) {
            __1s3 = (((char *)__nw__FUl(
                (size_t)((sizeof(char)) * ((strlen(__1s1) + strlen(__1s2)) + 3)))));
            sprintf(__1s3, (const char *)"%s__%s", __1s1, __1s2);
            return (const char *)__1s3;
        } else
            return __1s1;
    else
        return __1s2;
}

struct velem { /* sizeof velem == 16 */
    Pname n__5velem;
    int offset__5velem;
};

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

void add_vtbl__8classdefFP5velemPCcUci(register struct classdef *__0this, struct velem *__1v,
                                       const char *__1s, bit __1virt_flag, int __1n_init) {
    Pvirt __1vtab;

    register struct virt *__0__X44;

    struct node *__0__X3;

    __1vtab =
        ((__0__X44 = 0),
         (((__0__X44 || (__0__X44 = (struct virt *)__nw__FUl((size_t)(sizeof(struct virt)))))
               ? ((__0__X44 = (struct virt *)((__0__X3 = (((struct node *)__0__X44))),
                                              (((__0__X3 || (__0__X3 = (struct node *)__nw__FUl(
                                                                 (size_t)(sizeof(struct node)))))
                                                    ? (((__0__X3->base__4node = 0),
                                                        (__0__X3->permanent__4node = 0)),
                                                       (__0__X3->baseclass__4node = 0))
                                                    : 0),
                                               __0__X3))),
                  ((__0__X44->base__4node = 200),
                   ((__0__X44->vclass__4virt = __0this),
                    ((__0__X44->virt_init__4virt = __1v),
                     ((__0__X44->string__4virt = __1s),
                      ((__0__X44->is_vbase__4virt = __1virt_flag),
                       ((__0__X44->next__4virt = 0), ((__0__X44->n_init__4virt = __1n_init),
                                                      (__0__X44->printed__4virt = 0)))))))))
               : 0),
          __0__X44));

    if (__1virt_flag)
        __0this->has_vvtab__8classdef = 1;

    if (!__0this->virt_list__8classdef) {
        __0this->virt_list__8classdef = __1vtab;
        return;
    }

    {
        {
            Pvirt __1vt;

            __1vt = __0this->virt_list__8classdef;

            for (; __1vt; __1vt = __1vt->next__4virt)
                if (__1vt->string__4virt && (strcmp(__1vt->string__4virt, __1s) == 0)) {
                    struct velem *__2ivec;

                    Pname __2on;
                    Pname __2nn;
                    Pclass __2ocl;

                    Pclass __2ncl;

                    __2ivec = __1vt->virt_init__4virt;
                    __2on = (__2ivec[0]).n__5velem;
                    __2nn = (__1v[0]).n__5velem;

                    {
                        {
                            int __2i;

                            __2i = 0;

                            for (; __2on && __2nn; (((__2i++), (__2on = (__2ivec[__2i]).n__5velem)),
                                                    (__2nn = (__1v[__2i]).n__5velem))) {

                                __2ocl = (((struct fct *)(((struct fct *)__2on->__O1__4expr.tp))))
                                             ->memof__3fct;
                                __2ncl = (((struct fct *)(((struct fct *)__2nn->__O1__4expr.tp))))
                                             ->memof__3fct;
                                if (__2on != __2nn)
                                    if (!has_base__8classdefFP8classdefiT2(__2ocl, __2ncl, 0, 0))
                                        if (!has_base__8classdefFP8classdefiT2(__2ncl, __2ocl, 0,
                                                                               0))
                                            break;
                                        else {
                                            (__2ivec[__2i]).n__5velem = __2nn;
                                            (__2ivec[__2i]).offset__5velem =
                                                (__1v[__2i]).offset__5velem;
                                        }
                            }
                            if (__2on || __2nn) {
                                struct ea __0__V42;

                                struct ea __0__V43;

                                error__FPCcRC2eaN32((const char *)"virtualB: ambiguous%n and%n",
                                                    (const struct ea *)(((&__0__V42)->__O1__2ea.p =
                                                                             ((const void *)__2on)),
                                                                        (&__0__V42)),
                                                    (const struct ea *)(((&__0__V43)->__O1__2ea.p =
                                                                             ((const void *)__2nn)),
                                                                        (&__0__V43)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            return;
                        }
                    }
                }

            __1vtab->next__4virt = __0this->virt_list__8classdef->next__4virt;
            __0this->virt_list__8classdef->next__4virt = __1vtab;
        }
    }
}

static int baseoffset__FP8classdefT1(Pclass __1b, Pclass __1d);

static int baseoffset__FP8classdefT1(Pclass __1b, Pclass __1d) {
    Pbcl __1bx;

    struct classdef *__1__X45;

    struct classdef *__1__X46;

    static int __1level = 0;
    ++__1level;

    if ((!__1b) || (!__1d)) {
        error__FiPCc((int)'i', (const char *)"invalidA to baseoffset()");
    }

    if (((__1__X45 = __1b),
         ((__1__X46 = __1d),
          (((__1__X45 == __1__X46)
                ? 1
                : ((__1__X45 && __1__X46)
                       ? (((int)same_class__8classdefFP8classdefi(__1__X45, __1__X46, 0)))
                       : 0)))))) {
        __1level--;
        return 0;
    }

    ;

    for (__1bx = __1d->baselist__8classdef; __1bx; __1bx = __1bx->next__6basecl) {
        struct classdef *__1__X47;

        struct classdef *__1__X48;

        if (((__1__X47 = __1b),
             ((__1__X48 = __1bx->bclass__6basecl),
              (((__1__X47 == __1__X48)
                    ? 1
                    : ((__1__X47 && __1__X48)
                           ? (((int)same_class__8classdefFP8classdefi(__1__X47, __1__X48, 0)))
                           : 0)))))) {
            __1level--;
            return __1bx->obj_offset__6basecl;
        }
    }

    for (__1bx = __1d->baselist__8classdef; __1bx; __1bx = __1bx->next__6basecl) {
        if (__1bx->promoted__6basecl)
            continue;
        {
            int __2found;

            __2found = baseoffset__FP8classdefT1(__1b, __1bx->bclass__6basecl);
            if (__2found != -1) {
                __1level--;
                return (__1bx->obj_offset__6basecl + __2found);
            }
        }
    }

    if ((__1level--) > 1)
        return -1;

    error__FiPCc((int)'i', (const char *)"fall off end of baseoffset()");
    return 0;
}

int vcounter = 0;
static int vmax;

int do_virtuals__8classdefFP4virtPCciUc(register struct classdef *__0this, Pvirt __1vtab,
                                        const char *__1str, int __1leftmost, bit __1virt_flag) {
    if (vmax < vcounter)
        vmax = vcounter;
    {
        int __1vpsz;

        __1vpsz = (((vmax + vcounter) / 32) + 1);
        __1vpsz *= 32;
        {
            Pname *__1vp;
            struct velem *__1ivec;
            int __1vo;
            int __1vc;
            int __1changed;

            __1vp = (((struct name **)__nw__FUl((size_t)((sizeof(struct name *)) * __1vpsz))));
            __1ivec = (__1vtab ? __1vtab->virt_init__4virt : (((struct velem *)0)));
            __1vo = Voffset;
            __1vc = 0;
            __1changed = 0;

            if (__1ivec) {
                Pname __2vn;
                int __2i;

                if (__1vtab->is_vbase__4virt) {
                    __1str = 0;
                    Voffset = get_offset__8classdefFPCcUc(__0this, __1vtab->string__4virt,
                                                          (unsigned char)0);

                } else
                    Voffset = (Voffset + get_offset__8classdefFPCcUc(__1vtab->vclass__4virt,
                                                                     __1vtab->string__4virt,
                                                                     (unsigned char)0));
                ;
                __2i = 0;
                for (; __2vn = (__1ivec[__2i]).n__5velem; __2i++) {
                    if (__2i >= __1vpsz) {
                        int __4tvpsz;
                        Pname *__4tvp;

                        __4tvpsz = (__1vpsz + 32);
                        __4tvp = (((struct name **)__nw__FUl(
                            (size_t)((sizeof(struct name *)) * __4tvpsz))));
                        {
                            {
                                int __4j;

                                __4j = 0;

                                for (; __4j < __2i; ++__4j)
                                    (__4tvp[__4j]) = (__1vp[__4j]);
                                __dl__FPv((void *)__1vp);
                                __1vp = __4tvp;

                                __1vpsz = __4tvpsz;
                            }
                        }
                    }

                    {
                        const char *__3s;
                        Pname __3n;

                        __3s = __2vn->n_gen_fct_name__4name;
                        __3n = look__5tableFPCcUc(__0this->memtbl__8classdef,
                                                  __3s ? __3s : __2vn->__O2__4expr.string,
                                                  (unsigned char)0);

                        if ((__3n == 0) || (__3n->base__4node == 25)) {
                        inher:
                            if (__2vn->__O3__4expr.n_initializer) {
                                if (!get_vf__FP4nameP8classdef(__2vn, __0this)) {
                                    __0this->c_abstract__8classdef = __2vn;
                                }
                            }
                            (__1vp[__2i]) = __2vn;
                            if ((__1ivec[__2i]).offset__5velem && __1vtab->is_vbase__4virt) {
                                (__1vp[__2i])->n_offset__4name =
                                    (Voffset -
                                     baseoffset__FP8classdefT1(
                                         (((struct fct *)(((struct fct *)__2vn->__O1__4expr.tp))))
                                             ->memof__3fct,
                                         __0this));
                            } else
                                (__1vp[__2i])->n_offset__4name = (__1ivec[__2i]).offset__5velem;
                            continue;
                        }

                        {
                            Pfct __3f;

                            __3f = (((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))));
                            if (__3f == 0)
                                continue;

                            if (__3s && (__3f->base__4node == 76)) {
                                {
                                    {
                                        Plist __4gl;

                                        __4gl = (((struct gen *)(((struct gen *)__3f))))
                                                    ->fct_list__3gen;

                                        for (; __4gl; __4gl = __4gl->l__9name_list)
                                            if (__4gl->f__9name_list == __2vn)
                                                goto inher;
                                    }
                                }
                            }

                            {
                                Pfct __3vnf;

                                __3vnf = (((struct fct *)(((struct fct *)__2vn->__O1__4expr.tp))));
                                switch (__3f->base__4node) {
                                default: {
                                    struct ea __0__V49;

                                    struct ea __0__V50;

                                    error__FiP3locPCcRC2eaN34(
                                        (int)'w', &__3n->where__4name,
                                        (const char *)"%n hides virtual%n",
                                        (const struct ea *)(((&__0__V49)->__O1__2ea.p =
                                                                 ((const void *)__3n)),
                                                            (&__0__V49)),
                                        (const struct ea *)(((&__0__V50)->__O1__2ea.p =
                                                                 ((const void *)__2vn)),
                                                            (&__0__V50)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                    (__1vp[__2i]) = __2vn;
                                    if (__2vn->__O3__4expr.n_initializer) {
                                        if (!get_vf__FP4nameP8classdef(__2vn, __0this)) {
                                            __0this->c_abstract__8classdef = __2vn;
                                        }
                                    }
                                    if ((__1ivec[__2i]).offset__5velem &&
                                        __1vtab->is_vbase__4virt) {
                                        if ((Voffset - __1vo) != (__1ivec[__2i]).offset__5velem) {
                                            int __6noffset;

                                            __6noffset = get_offset__8classdefFPCcUc(
                                                __0this, __1vtab->string__4virt, (unsigned char)1);
                                            if (__6noffset && (__6noffset != Voffset))
                                                __6noffset -= __1vo;
                                            if (__6noffset == 0) {
                                                if (Vvbc_inher)
                                                    __6noffset =
                                                        (link_compat_hack
                                                             ? (link_compat_hack -
                                                                (__1ivec[__2i]).offset__5velem)
                                                             : (__1ivec[__2i]).offset__5velem);
                                                else
                                                    __6noffset = (Voffset - __1vo);
                                            }
                                            (__1vp[__2i])->n_offset__4name = __6noffset;
                                        } else
                                            (__1vp[__2i])->n_offset__4name = (Voffset - __1vo);
                                    } else
                                        (__1vp[__2i])->n_offset__4name =
                                            (__1ivec[__2i]).offset__5velem;
                                    break;
                                case 108: {
                                    if (check__4typeFP4typeUcT2(
                                            (struct type *)__3vnf, (struct type *)__3f,
                                            (unsigned char)77, (unsigned char)0) == 0) {
                                        if (Vcheckerror) {
                                            struct ea __0__V51;

                                            error__FPCcRC2eaN32(
                                                (const char *)"bad virtualT match for %n",
                                                (const struct ea *)(((&__0__V51)->__O1__2ea.p =
                                                                         ((const void *)__2vn)),
                                                                    (&__0__V51)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                                        }
                                        if (__3f->f_virtual__3fct == 22222)
                                            __3f->f_virtual__3fct = (__2i + 1);
                                        (__1vp[__2i]) = __3n;
                                        (__1vp[__2i])->n_offset__4name = Voffset;
                                        __1changed = 1;
                                    } else {
                                        if (Vcheckerror) {
                                            struct ea __0__V52;

                                            error__FPCcRC2eaN32(
                                                (const char *)"bad virtualT match for %n",
                                                (const struct ea *)(((&__0__V52)->__O1__2ea.p =
                                                                         ((const void *)__2vn)),
                                                                    (&__0__V52)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                                        } else {
                                            if (__2vn->__O3__4expr.n_initializer) {
                                                if (!get_vf__FP4nameP8classdef(__2vn, __0this)) {
                                                    __0this->c_abstract__8classdef = __2vn;
                                                }
                                            }
                                            {
                                                struct ea __0__V53;

                                                struct ea __0__V54;

                                                error__FiP3locPCcRC2eaN34(
                                                    (int)'w', &__3n->where__4name,
                                                    (const char *)"%n hides virtual%n",
                                                    (const struct ea *)(((&__0__V53)->__O1__2ea.p =
                                                                             ((const void *)__3n)),
                                                                        (&__0__V53)),
                                                    (const struct ea *)(((&__0__V54)->__O1__2ea.p =
                                                                             ((const void *)__2vn)),
                                                                        (&__0__V54)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                            }
                                        }
                                        (__1vp[__2i]) = __2vn;
                                        if ((__1ivec[__2i]).offset__5velem &&
                                            __1vtab->is_vbase__4virt) {
                                            if ((Voffset - __1vo) !=
                                                (__1ivec[__2i]).offset__5velem) {
                                                int __8noffset;

                                                __8noffset = get_offset__8classdefFPCcUc(
                                                    __0this, __1vtab->string__4virt,
                                                    (unsigned char)1);
                                                if (__8noffset && (__8noffset != Voffset))
                                                    __8noffset -= __1vo;
                                                if (__8noffset == 0) {
                                                    if (Vvbc_inher)
                                                        __8noffset =
                                                            (link_compat_hack
                                                                 ? (link_compat_hack -
                                                                    (__1ivec[__2i]).offset__5velem)
                                                                 : (__1ivec[__2i]).offset__5velem);
                                                    else
                                                        __8noffset = (Voffset - __1vo);
                                                }
                                                (__1vp[__2i])->n_offset__4name = __8noffset;
                                            } else
                                                (__1vp[__2i])->n_offset__4name = (Voffset - __1vo);
                                        } else
                                            (__1vp[__2i])->n_offset__4name =
                                                (__1ivec[__2i]).offset__5velem;
                                    }
                                    break;
                                }
                                case 76: {
                                    int __5hit;

                                    __5hit = 0;
                                    {
                                        {
                                            Plist __5gl;

                                            __5gl = (((struct gen *)(((struct gen *)__3f))))
                                                        ->fct_list__3gen;

                                            for (; __5gl; __5gl = __5gl->l__9name_list) {
                                                Pname __6fn;
                                                Pfct __6f;

                                                __6fn = __5gl->f__9name_list;
                                                __6f = (((struct fct *)((
                                                    (struct fct *)__6fn->__O1__4expr.tp))));

                                                if (check__4typeFP4typeUcT2(
                                                        (struct type *)__6f, (struct type *)__3vnf,
                                                        (unsigned char)77, (unsigned char)0) == 0) {

                                                    if (Vcheckerror) {
                                                        struct ea __0__V55;

                                                        error__FPCcRC2eaN32(
                                                            (const char
                                                                 *)"bad virtualT match for %n",
                                                            (const struct ea
                                                                 *)(((&__0__V55)->__O1__2ea.p =
                                                                         ((const void *)__2vn)),
                                                                    (&__0__V55)),
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0);
                                                    }
                                                    if (__6f->f_virtual__3fct == 22222)
                                                        __6f->f_virtual__3fct = (__2i + 1);
                                                    (__1vp[__2i]) = __6fn;
                                                    (__1vp[__2i])->n_offset__4name = Voffset;
                                                    __1changed = 1;
                                                    goto found;
                                                } else {
                                                    if (Vcheckerror) {
                                                        struct ea __0__V56;

                                                        error__FPCcRC2eaN32(
                                                            (const char
                                                                 *)"bad virtualT match for %n",
                                                            (const struct ea
                                                                 *)(((&__0__V56)->__O1__2ea.p =
                                                                         ((const void *)__2vn)),
                                                                    (&__0__V56)),
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0);
                                                    }
                                                }
                                                if (Vcheckerror == 0)
                                                    switch (__6f->f_virtual__3fct) {
                                                    case 0:
                                                    case 22222:
                                                        __5hit = 1;
                                                    }
                                            }

                                            if (__5hit) {
                                                if (__2vn->__O3__4expr.n_initializer) {
                                                    if (!get_vf__FP4nameP8classdef(__2vn,
                                                                                   __0this)) {
                                                        __0this->c_abstract__8classdef = __2vn;
                                                    }
                                                }
                                                {
                                                    struct ea __0__V57;

                                                    struct ea __0__V58;

                                                    struct ea __0__V59;

                                                    error__FiP3locPCcRC2eaN34(
                                                        (int)'w', &__3n->where__4name,
                                                        (const char *)"%n hides virtual%n ofT %t",
                                                        (const struct ea
                                                             *)(((&__0__V57)->__O1__2ea.p =
                                                                     ((const void *)__3n)),
                                                                (&__0__V57)),
                                                        (const struct ea
                                                             *)(((&__0__V58)->__O1__2ea.p =
                                                                     ((const void *)__2vn)),
                                                                (&__0__V58)),
                                                        (const struct ea *)__ct__2eaFPCv(
                                                            &__0__V59,
                                                            (const void *)__2vn->__O1__4expr.tp),
                                                        (const struct ea *)ea0);
                                                }
                                            }

                                            (__1vp[__2i]) = __2vn;
                                            if ((__1ivec[__2i]).offset__5velem &&
                                                __1vtab->is_vbase__4virt) {
                                                if ((Voffset - __1vo) !=
                                                    (__1ivec[__2i]).offset__5velem) {
                                                    int __7noffset;

                                                    __7noffset = get_offset__8classdefFPCcUc(
                                                        __0this, __1vtab->string__4virt,
                                                        (unsigned char)1);
                                                    if (__7noffset && (__7noffset != Voffset))
                                                        __7noffset -= __1vo;
                                                    if (__7noffset == 0) {
                                                        if (Vvbc_inher)
                                                            __7noffset =
                                                                (link_compat_hack
                                                                     ? (link_compat_hack -
                                                                        (__1ivec[__2i])
                                                                            .offset__5velem)
                                                                     : (__1ivec[__2i])
                                                                           .offset__5velem);
                                                        else
                                                            __7noffset = (Voffset - __1vo);
                                                    }
                                                    (__1vp[__2i])->n_offset__4name = __7noffset;
                                                } else
                                                    (__1vp[__2i])->n_offset__4name =
                                                        (Voffset - __1vo);
                                            } else
                                                (__1vp[__2i])->n_offset__4name =
                                                    (__1ivec[__2i]).offset__5velem;
                                        found:
                                            break;
                                        }
                                    }
                                }
                                }
                                }
                            }
                        }
                    }
                }

                Voffset = __1vo;
                __1vc = __2i;
            }

            if (__1leftmost) {
                int __2i;
                {
                    {
                        Pname __2nn;

                        struct table *__0__X60;

                        int __2__X61;

                        struct table *__0__X62;

                        int __2__X63;

                        __2nn = ((__0__X62 = __0this->memtbl__8classdef),
                                 ((__2__X63 = (__2i = 1)),
                                  ((((__2__X63 <= 0) || (__0__X62->free_slot__5table <= __2__X63))
                                        ? (((struct name *)0))
                                        : (__0__X62->entries__5table[__2__X63])))));

                        for (; __2nn;
                             __2nn = (__2nn->n_tbl_list__4name
                                          ? __2nn->n_tbl_list__4name
                                          : ((__0__X60 = __0this->memtbl__8classdef),
                                             ((__2__X61 = (++__2i)),
                                              ((((__2__X61 <= 0) ||
                                                 (__0__X60->free_slot__5table <= __2__X61))
                                                    ? (((struct name *)0))
                                                    : (__0__X60->entries__5table[__2__X61]))))))) {
                            if (__2nn->base__4node == 123)
                                continue;

                            {
                                Pfct __3f;

                                __3f = (((struct fct *)(((struct fct *)__2nn->__O1__4expr.tp))));

                                if (__1vc >= __1vpsz) {
                                    int __4tvpsz;
                                    Pname *__4tvp;

                                    __4tvpsz = (__1vpsz + 32);
                                    __4tvp = (((struct name **)__nw__FUl(
                                        (size_t)((sizeof(struct name *)) * __4tvpsz))));
                                    {
                                        {
                                            int __4j;

                                            __4j = 0;

                                            for (; __4j < __1vc; ++__4j)
                                                (__4tvp[__4j]) = (__1vp[__4j]);
                                            __dl__FPv((void *)__1vp);
                                            __1vp = __4tvp;
                                            __1vpsz = __4tvpsz;
                                        }
                                    }
                                }

                                if (__3f)
                                    switch (__3f->base__4node) {
                                    case 108:
                                        if (__3f->f_virtual__3fct == 22222) {
                                            __3f->f_virtual__3fct = (++__1vc);
                                            (__1vp[(__3f->f_virtual__3fct - 1)]) = __2nn;
                                            (__1vp[(__3f->f_virtual__3fct - 1)])->n_offset__4name =
                                                0;
                                            __3f->f_vdef__3fct = 1;
                                            __1changed = 2;
                                        }
                                        break;
                                    case 76: {
                                        {
                                            {
                                                Plist __5gl;

                                                __5gl = (((struct gen *)(((struct gen *)__3f))))
                                                            ->fct_list__3gen;

                                                for (; __5gl; __5gl = __5gl->l__9name_list) {
                                                    Pname __6fn;
                                                    Pfct __6f;

                                                    __6fn = __5gl->f__9name_list;
                                                    __6f = (((struct fct *)((
                                                        (struct fct *)__6fn->__O1__4expr.tp))));

                                                    if (__1vc >= __1vpsz) {
                                                        int __7tvpsz;
                                                        Pname *__7tvp;

                                                        __7tvpsz = (__1vpsz + 32);
                                                        __7tvp = (((struct name **)__nw__FUl(
                                                            (size_t)((sizeof(struct name *)) *
                                                                     __7tvpsz))));
                                                        {
                                                            {
                                                                int __7j;

                                                                __7j = 0;

                                                                for (; __7j < __1vc; ++__7j) {
                                                                    (__7tvp[__7j]) = (__1vp[__7j]);
                                                                }
                                                                __dl__FPv((void *)__1vp);
                                                                __1vp = __7tvp;
                                                                __1vpsz = __7tvpsz;
                                                            }
                                                        }
                                                    }

                                                    if (__6f->f_virtual__3fct == 22222) {
                                                        __6f->f_virtual__3fct = (++__1vc);
                                                        (__1vp[(__6f->f_virtual__3fct - 1)]) =
                                                            __6fn;
                                                        (__1vp[(__6f->f_virtual__3fct - 1)])
                                                            ->n_offset__4name = 0;
                                                        __6f->f_vdef__3fct = 1;
                                                        __1changed = 2;
                                                    }
                                                }
                                                break;
                                            }
                                        }
                                    }
                                    }
                            }
                        }

                        __0this->virt_count__8classdef = 0;
                        if (__1changed)
                            __0this->virt_count__8classdef = __1vc;
                        else if (__0this->has_vvtab__8classdef) {
                            __0this->virt_merge__8classdef = 1;
                            if (__1vc && __1vtab->is_vbase__4virt)
                                __1leftmost = 0;
                        }
                    }
                }
            }

            if (__1changed || (!__1leftmost)) {
                struct velem *__2v;

                __2v =
                    (((struct velem *)__nw__FUl((size_t)((sizeof(struct velem)) * (__1vc + 1)))));

                {
                    {
                        int __2i;

                        __2i = 0;

                        for (; __2i < __1vc; __2i++) {
                            (__2v[__2i]).n__5velem = (__1vp[__2i]);
                            (__2v[__2i]).offset__5velem = (__1vp[__2i])->n_offset__4name;
                        }
                        (__2v[__1vc]).n__5velem = 0;

                        if (__1leftmost)
                            add_vtbl__8classdefFP5velemPCcUci(__0this, __2v, (const char *)0,
                                                              (unsigned char)0, 0);
                        else
                            add_vtbl__8classdefFP5velemPCcUci(
                                __0this, __2v, vtbl_str__FPCcT1(__1vtab->string__4virt, __1str),
                                (unsigned char)(__1virt_flag || __1vtab->is_vbase__4virt),
                                __1vc + 1);
                        __dl__FPv((void *)__1vp);
                        vcounter = 0;
                        return 1;
                    }
                }
            }

            __dl__FPv((void *)__1vp);
            vcounter = 0;
            return 0;
        }
    }
}

int all_virt__8classdefFP8classdefPCciUc(struct classdef *__0this, Pclass __1bcl, const char *__1s,
                                         int __1leftmost, bit __1virt_flag);

int all_virt__8classdefFP8classdefPCciUc(register struct classdef *__0this, Pclass __1bcl,
                                         const char *__1s, int __1leftmost, bit __1virt_flag) {
    int __1i;

    __1i = 0;
    if (__1bcl->virt_count__8classdef) {
        {
            {
                Pvirt __2blist;

                __2blist = __1bcl->virt_list__8classdef;

                for (; __2blist; __2blist = __2blist->next__4virt) {
                    if ((__0this->virt_merge__8classdef && (__1virt_flag == 0)) &&
                        (__2blist->is_vbase__4virt == 0))
                        continue;

                    __1i += do_virtuals__8classdefFP4virtPCciUc(__0this, __2blist, __1s,
                                                                __1leftmost, __1virt_flag);
                    if (((__1i == 0) && __1leftmost) && (__0this->virt_merge__8classdef == 0))
                        return 0;

                    __1leftmost = 0;
                }
            }
        }
    }

    if (__1i)
        return __1i;

    {
        {
            Pbcl __1b;

            __1b = __1bcl->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                if (__1b->promoted__6basecl)
                    continue;

                if (__1leftmost && (__1b->base__4node == 77)) {
                    __1i += do_virtuals__8classdefFP4virtPCciUc(
                        __0this, (struct virt *)0, (const char *)0, 1, (unsigned char)0);
                    if ((__1i == 0) && (__0this->virt_merge__8classdef == 0)) {
                        if ((__1bcl == __0this) && __1b->bclass__6basecl->c_abstract__8classdef)
                            __0this->c_abstract__8classdef =
                                __1b->bclass__6basecl->c_abstract__8classdef;
                        return 0;
                    }
                    __1leftmost = 0;
                }
                {
                    int __2vo;

                    __2vo = Voffset;
                    if (__1b->base__4node == 77) {
                        Voffset = baseoffset__FP8classdefT1(__1b->bclass__6basecl, __0this);
                    } else {
                        Voffset += __1b->obj_offset__6basecl;
                    }

                    if (__1b->base__4node == 77)
                        __1i += all_virt__8classdefFP8classdefPCciUc(
                            __0this, __1b->bclass__6basecl,
                            __1b->bclass__6basecl->string__8classdef, __1leftmost,
                            (unsigned char)1);
                    else
                        __1i += all_virt__8classdefFP8classdefPCciUc(
                            __0this, __1b->bclass__6basecl,
                            vtbl_str__FPCcT1(__1b->bclass__6basecl->string__8classdef, __1s),
                            __1leftmost, __1virt_flag);

                    if (((__1i == 0) && __1leftmost) && (__0this->virt_merge__8classdef == 0)) {
                        if (((__1bcl == __0this) && (!__0this->c_abstract__8classdef)) &&
                            __1b->next__6basecl) {
                            {
                                {
                                    Pbcl __4bb;

                                    __4bb = __1b;

                                    for (; __4bb; __4bb = __4bb->next__6basecl) {
                                        if (__4bb->promoted__6basecl)
                                            continue;
                                        if (__4bb->bclass__6basecl->c_abstract__8classdef)
                                            __0this->c_abstract__8classdef =
                                                __4bb->bclass__6basecl->c_abstract__8classdef;
                                    }
                                }
                            }
                        }
                        return 0;
                    }

                    Voffset = __2vo;
                    __1leftmost = 0;
                }
            }

            if (__1i)
                return __1i;

            if (__1leftmost)
                return do_virtuals__8classdefFP4virtPCciUc(__0this, (struct virt *)0,
                                                           (const char *)0, 1, (unsigned char)0);
            else
                return 0;
        }
    }
}

extern char *make_name__FUc(TOK);

extern int fprintf(void *, const char *, ...);

struct basetype *__ct__8basetypeFUcP4name(struct basetype *__0this, TOK, Pname);

Pexpr contents__4exprFv(struct expr *__0this);

Pexpr copy_obj__FP4exprT1i(Pexpr __1l, Pexpr __1r, int __1sz) {
    if (!__1sz)
        __1sz = 1;

    {
        char *__1s;

        __1s = make_name__FUc((unsigned char)'S');
        fprintf(out_file, (const char *)"struct %s { char v[%d]; };\n", __1s, __1sz);
        {
            Pname __1n;
            Ptype __1t;

            struct texpr *__0__X64;

            struct texpr *__0__X65;

            __1n = __ct__4nameFPCc((struct name *)0, (const char *)__1s);
            __1t = (struct type *)__ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)119,
                                                           __1n);
            __1t = (struct type *)__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __1t);

            __1l = (struct expr *)((__0__X64 = 0),
                                   (((__0__X64 || (__0__X64 = (struct texpr *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct texpr)))))
                                         ? ((__0__X64 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                 ((struct expr *)__0__X64), ((unsigned char)191),
                                                 __1l, (struct expr *)0)),
                                            (__0__X64->__O4__4expr.tp2 = __1t))
                                         : 0),
                                    __0__X64));
            __1l = contents__4exprFv(__1l);

            __1r = (struct expr *)((__0__X65 = 0),
                                   (((__0__X65 || (__0__X65 = (struct texpr *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct texpr)))))
                                         ? ((__0__X65 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                 ((struct expr *)__0__X65), ((unsigned char)191),
                                                 __1r, (struct expr *)0)),
                                            (__0__X65->__O4__4expr.tp2 = __1t))
                                         : 0),
                                    __0__X65));
            __1r = contents__4exprFv(__1r);

            return __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70, __1l, __1r);
        }
    }
}

Pptr is_ref__4typeFv(struct type *__0this);

bit tconst__4typeFv(struct type *__0this);

Ptype find_arg_type__FP8classdef(Pclass __1cl) {
    int __1i;
    int __1mod;

    __1mod = 0;
    {
        {
            Pbcl __1b;

            __1b = __1cl->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                Pclass __2bcl;

                __2bcl = __1b->bclass__6basecl;
                switch (__1b->base__4node) {
                case 77:
                case 85: {
                    Pname __4itor;

                    __4itor = (__2bcl->c_itor__8classdef);
                    if (__4itor && (__4itor->__O1__4expr.tp->base__4node == 108)) {
                        Pname __5a;
                        Pptr __5p;

                        __5a = (((struct fct *)(((struct fct *)__4itor->__O1__4expr.tp))))
                                   ->argtype__3fct;
                        __5p = is_ref__4typeFv(__5a->__O1__4expr.tp);
                        if (__5p && (tconst__4typeFv(__5p->typ__5pvtyp) == 0)) {
                            __1mod = 1;
                            goto ll1;
                        }
                    }
                }
                }
            }
        ll1:
            if (__1mod == 0) {
                {
                    {
                        Pname __2m;

                        struct table *__0__X66;

                        int __2__X67;

                        struct table *__0__X69;

                        int __2__X70;

                        __2m = ((__0__X69 = __1cl->memtbl__8classdef),
                                ((__2__X70 = (__1i = 1)),
                                 ((((__2__X70 <= 0) || (__0__X69->free_slot__5table <= __2__X70))
                                       ? (((struct name *)0))
                                       : (__0__X69->entries__5table[__2__X70])))));

                        for (; __2m;
                             __2m = (__2m->n_tbl_list__4name
                                         ? __2m->n_tbl_list__4name
                                         : ((__0__X66 = __1cl->memtbl__8classdef),
                                            ((__2__X67 = (++__1i)),
                                             ((((__2__X67 <= 0) ||
                                                (__0__X66->free_slot__5table <= __2__X67))
                                                   ? (((struct name *)0))
                                                   : (__0__X66->entries__5table[__2__X67]))))))) {
                            if (__2m->base__4node == 123)
                                continue;

                            if (__2m->n_evaluated__4name || (__2m->n_stclass__4name == 31))
                                continue;
                            {
                                Pname __3cln;

                                __3cln = is_cl_obj__4typeFv(((__2m->base__4node == 25)
                                                                 ? __2m->__O2__4name.n_qualifier
                                                                 : __2m)
                                                                ->__O1__4expr.tp);
                                if (__3cln) {
                                    Pname __4itor;

                                    struct classdef *__0__X68;

                                    __4itor = ((__0__X68 = (((struct classdef *)((
                                                    (struct classdef *)__3cln->__O1__4expr.tp))))),
                                               (__0__X68->c_itor__8classdef));
                                    if (__4itor && (__4itor->__O1__4expr.tp->base__4node == 108)) {
                                        Pname __5a;
                                        Pptr __5p;

                                        __5a = (((struct fct *)((
                                                    (struct fct *)__4itor->__O1__4expr.tp))))
                                                   ->argtype__3fct;
                                        __5p = is_ref__4typeFv(__5a->__O1__4expr.tp);
                                        if (__5p && (tconst__4typeFv(__5p->typ__5pvtyp) == 0)) {
                                            __1mod = 1;
                                            goto ll2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        ll2: {
            Pbase __1bp;

            __1bp =
                __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)21, (struct name *)0);
            ((*__1bp)) = (*(((struct basetype *)((
                (struct basetype *)(((struct ptr *)(((struct ptr *)__1cl->this_type__8classdef))))
                    ->typ__5pvtyp)))));
            if (__1mod == 0)
                __1bp->b_const__4type = 1;
            return (struct type *)__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)158,
                                                      (struct type *)__1bp);
        }
        }
    }
}

Pexpr address__4exprFv(struct expr *__0this);

int tsizeof__4typeFi(struct type *__0this, int);

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

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

Pname dcl__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

void simpl__4nameFv(struct name *__0this);

void dcl_print__4nameFUc(struct name *__0this, TOK);

Pname make_itor__8classdefFi(register struct classdef *__0this, int __1def) {
    Pstmt __1s;
    Pname __1e;
    int __1i;
    Pname __1arg;

    __1arg = __ct__4nameFPCc((struct name *)0, (const char *)make_name__FUc((unsigned char)'A'));
    __1arg->__O1__4expr.tp = find_arg_type__FP8classdef(__0this);

    __0this->c_xref__8classdef |= 2;

    if (__1def) {
        int __2slow;
        int __2first;
        Pexpr __2es;

        struct estmt *__0__X75;

        struct loc __2__X76;

        unsigned long __2__X77;

        const void *__2__X78;

        __2slow = 0;
        __2first = 1;
        __2es = 0;
        __1s = (struct stmt *)((__0__X75 = 0),
                               ((__2__X76 = no_where),
                                (((__0__X75 || (__0__X75 = (struct estmt *)__nw__4stmtSFUl(
                                                    (unsigned long)(sizeof(struct estmt)))))
                                      ? ((__0__X75 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                              ((struct stmt *)__0__X75), ((unsigned char)72),
                                              __2__X76, ((struct stmt *)0))),
                                         (__0__X75->__O2__4stmt.e = ((struct expr *)0)))
                                      : 0),
                                 __0__X75)));
        __1e = 0;

        if (warning_opt && (128 < __0this->obj_size__8classdef)) {
            struct ea __0__V71;

            struct ea __0__V72;

            error__FiPCcRC2eaN33(
                (int)'w', (const char *)"copying a %d byte object (ofC %s)",
                (const struct ea *)((__2__X77 = __0this->obj_size__8classdef),
                                    (((((&__0__V71)->__O1__2ea.i = __2__X77), 0)), (&__0__V71))),
                (const struct ea *)((__2__X78 = (const void *)__0this->string__8classdef),
                                    (((&__0__V72)->__O1__2ea.p = __2__X78), (&__0__V72))),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__0this->baselist__8classdef)
            __2slow = 1;

        if (__2slow) {
            {
                {
                    Pbcl __3b;

                    __3b = __0this->baselist__8classdef;

                    for (; __3b; __3b = __3b->next__6basecl) {
                        Pclass __4bcl;
                        Ptype __4pt;

                        __4bcl = __3b->bclass__6basecl;
                        __4pt = __4bcl->this_type__8classdef;
                        if ((__3b->base__4node == 77) || (__3b->base__4node == 85)) {
                            Pexpr __5b2;

                            struct texpr *__0__X79;

                            __5b2 = (struct expr *)__ct__4nameFPCc((struct name *)0,
                                                                   __1arg->__O2__4expr.string);
                            __5b2 = address__4exprFv(__5b2);
                            __5b2 =
                                (struct expr
                                     *)((__0__X79 = 0),
                                        (((__0__X79 || (__0__X79 = (struct texpr *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct texpr)))))
                                              ? ((__0__X79 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                      ((struct expr *)__0__X79),
                                                      ((unsigned char)191), __5b2,
                                                      (struct expr *)0)),
                                                 (__0__X79->__O4__4expr.tp2 = __4pt))
                                              : 0),
                                         __0__X79));
                            __5b2->__O3__4expr.i2 = 1;
                            __5b2 = contents__4exprFv(__5b2);

                            {
                                Pname __5ee;

                                __5ee =
                                    __ct__4nameFPCc((struct name *)0, __4bcl->string__8classdef);
                                __5ee->base__4node = 123;
                                __5ee->__O3__4expr.n_initializer = __5b2;
                                if (__1e)
                                    __5ee->__O1__4name.n_list = __1e;
                                __1e = __5ee;
                            }
                        }
                    }
                }
            }
        }

        {
            {
                Pname __2mm;

                struct table *__0__X80;

                int __2__X81;

                struct table *__0__X93;

                int __2__X94;

                __2mm = ((__0__X93 = __0this->memtbl__8classdef),
                         ((__2__X94 = (__1i = 1)),
                          ((((__2__X94 <= 0) || (__0__X93->free_slot__5table <= __2__X94))
                                ? (((struct name *)0))
                                : (__0__X93->entries__5table[__2__X94])))));

                for (; __2mm;
                     __2mm =
                         (__2mm->n_tbl_list__4name
                              ? __2mm->n_tbl_list__4name
                              : ((__0__X80 = __0this->memtbl__8classdef),
                                 ((__2__X81 = (++__1i)),
                                  ((((__2__X81 <= 0) || (__0__X80->free_slot__5table <= __2__X81))
                                        ? (((struct name *)0))
                                        : (__0__X80->entries__5table[__2__X81]))))))) {
                    Ptype __3t;

                    __3t = __2mm->__O1__4expr.tp;
                    if (__3t && ((__3t = skiptypedefs__4typeFv(__3t))->base__4node == 119)) {
                        Pclass __4mcl;

                        __4mcl = (((struct classdef *)((
                            (struct classdef *)(((struct basetype *)(((struct basetype *)__3t))))
                                ->b_name__8basetype->__O1__4expr.tp))));
                        if (__4mcl->c_xref__8classdef & 10)
                            __2slow = 1;
                    }
                }

                {
                    {
                        Pname __2m;

                        struct table *__0__X82;

                        int __2__X83;

                        struct table *__0__X91;

                        int __2__X92;

                        __2m = ((__0__X91 = __0this->memtbl__8classdef),
                                ((__2__X92 = (__1i = 1)),
                                 ((((__2__X92 <= 0) || (__0__X91->free_slot__5table <= __2__X92))
                                       ? (((struct name *)0))
                                       : (__0__X91->entries__5table[__2__X92])))));

                        for (; __2m;
                             __2m = (__2m->n_tbl_list__4name
                                         ? __2m->n_tbl_list__4name
                                         : ((__0__X82 = __0this->memtbl__8classdef),
                                            ((__2__X83 = (++__1i)),
                                             ((((__2__X83 <= 0) ||
                                                (__0__X82->free_slot__5table <= __2__X83))
                                                   ? (((struct name *)0))
                                                   : (__0__X82->entries__5table[__2__X83]))))))) {
                            if (__2m->base__4node == 123)
                                continue;

                            if (__2m->n_evaluated__4name || (__2m->n_stclass__4name == 31))
                                continue;

                            if (strcmp(__2m->__O2__4expr.string, (const char *)"__vptr") == 0) {
                                if (((__2slow == 0) && (__2first == 0)) && __2m->n_offset__4name) {
                                    Pexpr __5th;
                                    Pexpr __5a;

                                    __5th =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)34,
                                                               (struct expr *)0, (struct expr *)0);
                                    __5a = (struct expr *)__ct__4nameFPCc(
                                        (struct name *)0, __1arg->__O2__4expr.string);
                                    __5a = address__4exprFv(__5a);
                                    {
                                        Pexpr __5ee;

                                        __5ee = copy_obj__FP4exprT1i(__5th, __5a,
                                                                     __2m->n_offset__4name);
                                        __2es = (__2es ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                                (unsigned char)71,
                                                                                __2es, __5ee)
                                                       : __5ee);
                                    }
                                }
                                __2slow = 1;
                                __2first = 0;
                                continue;
                            }
                            {
                                Ptype __3mt;

                                __3mt = __2m->__O1__4expr.tp;
                                if (__3mt)
                                tx:
                                    switch (__3mt->base__4node) {
                                    case 97:
                                        __3mt = (((struct basetype *)(((struct basetype *)__3mt))))
                                                    ->b_name__8basetype->__O1__4expr.tp;
                                        goto tx;
                                    case 110: {
                                        Pname __5cn;

                                        __5cn = is_cl_obj__4typeFv(
                                            (((struct vec *)(((struct vec *)__3mt))))->typ__5pvtyp);
                                        if (__5cn &&
                                            ((((struct classdef *)((
                                                  (struct classdef *)__5cn->__O1__4expr.tp))))
                                                 ->c_xref__8classdef &
                                             10)) {
                                            {
                                                struct ea __0__V73;

                                                struct ea __0__V74;

                                                error__FiPCcRC2eaN33(
                                                    (int)'s',
                                                    (const char
                                                         *)"copy of %n[], no memberwise copy for%n",
                                                    (const struct ea *)(((&__0__V73)->__O1__2ea.p =
                                                                             ((const void *)__5cn)),
                                                                        (&__0__V73)),
                                                    (const struct ea *)(((&__0__V74)->__O1__2ea.p =
                                                                             ((const void *)__5cn)),
                                                                        (&__0__V74)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                                __2slow = 1;
                                            }
                                        }

                                        if (__2slow && tsizeof__4typeFi(__3mt, 0)) {
                                            Pexpr __6l;
                                            Pexpr __6r;

                                            struct ref *__0__X84;

                                            struct expr *__2__X85;

                                            struct expr *__2__X86;

                                            __6l = (struct expr *)__ct__4nameFPCc(
                                                (struct name *)0, __2m->__O2__4expr.string);
                                            __6r = (struct expr *)__ct__4nameFPCc(
                                                (struct name *)0, __2m->__O2__4expr.string);
                                            __6r =
                                                (struct expr
                                                     *)((__0__X84 = 0),
                                                        ((__2__X85 = (struct expr *)__ct__4nameFPCc(
                                                              (struct name *)0,
                                                              __1arg->__O2__4expr.string)),
                                                         ((__2__X86 = __6r),
                                                          (((__0__X84 ||
                                                             (__0__X84 =
                                                                  (struct ref *)__nw__4exprSFUl((
                                                                      size_t)(sizeof(struct ref)))))
                                                                ? ((__0__X84 = (struct ref *)
                                                                        __ct__4exprFUcP4exprT2(
                                                                            ((struct expr *)
                                                                                 __0__X84),
                                                                            ((unsigned char)45),
                                                                            __2__X85,
                                                                            (struct expr *)0)),
                                                                   (__0__X84->__O4__4expr.mem =
                                                                        __2__X86))
                                                                : 0),
                                                           __0__X84))));
                                            {
                                                Pexpr __6ee;

                                                __6ee = copy_obj__FP4exprT1i(
                                                    __6l, __6r, tsizeof__4typeFi(__3mt, 0));
                                                __2es =
                                                    (__2es ? __ct__4exprFUcP4exprT2(
                                                                 (struct expr *)0,
                                                                 (unsigned char)71, __2es, __6ee)
                                                           : __6ee);
                                                break;
                                            }
                                        }
                                    }
                                    case 108:
                                    case 76:
                                    case 6:
                                    case 13:
                                        break;
                                    case 119: {
                                        Pclass __5mcl;

                                        __5mcl = (((struct classdef *)((
                                            (struct classdef *)(((struct basetype *)((
                                                                    (struct basetype *)__3mt))))
                                                ->b_name__8basetype->__O1__4expr.tp))));
                                        if ((__2slow == 0) && (__5mcl->c_xref__8classdef & 10)) {
                                            __2slow = 1;
                                            if ((__2first == 0) && __2m->n_offset__4name) {
                                                Pexpr __7th;
                                                Pexpr __7a;

                                                __7th = __ct__4exprFUcP4exprT2(
                                                    (struct expr *)0, (unsigned char)34,
                                                    (struct expr *)0, (struct expr *)0);
                                                __7a = (struct expr *)__ct__4nameFPCc(
                                                    (struct name *)0, __1arg->__O2__4expr.string);
                                                __7a = address__4exprFv(__7a);
                                                {
                                                    Pexpr __7ee;

                                                    __7ee = copy_obj__FP4exprT1i(
                                                        __7th, __7a, __2m->n_offset__4name);
                                                    __2es = (__2es ? __ct__4exprFUcP4exprT2(
                                                                         (struct expr *)0,
                                                                         (unsigned char)71, __2es,
                                                                         __7ee)
                                                                   : __7ee);
                                                }
                                            }
                                        }
                                    }

                                    default:
                                        if (__2slow) {
                                            Pname __5ee;

                                            struct ref *__0__X87;

                                            struct expr *__2__X88;

                                            struct expr *__2__X89;

                                            __5ee = __ct__4nameFPCc((struct name *)0,
                                                                    __2m->__O2__4expr.string);
                                            __5ee->__O3__4expr.n_initializer =
                                                (struct expr
                                                     *)((__0__X87 = 0),
                                                        ((__2__X88 = (struct expr *)__ct__4nameFPCc(
                                                              (struct name *)0,
                                                              __1arg->__O2__4expr.string)),
                                                         ((__2__X89 =
                                                               (struct expr *)__ct__4nameFPCc(
                                                                   (struct name *)0,
                                                                   __2m->__O2__4expr.string)),
                                                          (((__0__X87 ||
                                                             (__0__X87 =
                                                                  (struct ref *)__nw__4exprSFUl((
                                                                      size_t)(sizeof(struct ref)))))
                                                                ? ((__0__X87 = (struct ref *)
                                                                        __ct__4exprFUcP4exprT2(
                                                                            ((struct expr *)
                                                                                 __0__X87),
                                                                            ((unsigned char)45),
                                                                            __2__X88,
                                                                            (struct expr *)0)),
                                                                   (__0__X87->__O4__4expr.mem =
                                                                        __2__X89))
                                                                : 0),
                                                           __0__X87))));
                                            if (__1e)
                                                __5ee->__O1__4name.n_list = __1e;
                                            __1e = __5ee;
                                        }
                                    }
                                __2first = 0;
                            }
                        }

                        if (__2slow == 0) {
                            Pexpr __3th;
                            Pexpr __3a;

                            __3th = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)34,
                                                           (struct expr *)0, (struct expr *)0);
                            __3a = (struct expr *)__ct__4nameFPCc((struct name *)0,
                                                                  __1arg->__O2__4expr.string);
                            __3a = address__4exprFv(__3a);
                            {
                                Pexpr __3ee;

                                __3ee =
                                    copy_obj__FP4exprT1i(__3th, __3a, __0this->obj_size__8classdef);
                                __2es =
                                    (__2es ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                    (unsigned char)71, __2es, __3ee)
                                           : __3ee);
                            }
                        }

                        __1s->__O2__4stmt.e = __2es;
                        {
                            Pname __2cn;

                            struct dcl_context *__0__X90;

                            __2cn = find_cn__6ktableFPCc(__0this->k_tbl__8classdef,
                                                         __0this->string__8classdef);
                            if (__2cn)
                                __2cn = (((struct basetype *)((
                                             (struct basetype *)__2cn->__O1__4expr.tp))))
                                            ->b_name__8basetype;
                            ((((cc++),
                               (((cc >= ccvec_end)
                                     ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow")
                                     : 0),
                                (((*cc)) = (*(cc - 1))))),
                              (((void)0))));
                            cc->not4__11dcl_context = __2cn;
                            cc->cot__11dcl_context = __0this;
                        }
                    }
                }
            }
        }
    }
    {
        Pname __1fn;
        Pfct __1f;

        __1fn = __ct__4nameFPCc((struct name *)0, __0this->string__8classdef);
        __1f = __ct__3fctFP4typeP4nameUc((struct fct *)0, (struct type *)defa_type, __1arg,
                                         (unsigned char)1);
        __1fn->__O1__4expr.tp = (struct type *)__1f;
        __1fn->n_oper__4name = 123;

        (((struct fct *)(((struct fct *)__1f))))->f_inline__3fct = (__1def ? 1 : 77);
        (((struct fct *)(((struct fct *)__1f))))->f_is_inline__3fct = 1;
        if (__1def) {
            register struct block *__0__X95;

            struct loc __2__X96;

            struct loc __2__X97;

            __1f->body__3fct =
                ((__0__X95 = 0),
                 ((__2__X96 = curloc),
                  ((__2__X97 = noloc),
                   (((__0__X95 ||
                      (__0__X95 = (struct block *)__nw__4stmtSFUl((size_t)(sizeof(struct block)))))
                         ? (((void)((__0__X95 = (struct block *)__ct__4stmtFUc3locP4stmt(
                                         ((struct stmt *)__0__X95), (unsigned char)116, __2__X96,
                                         __1s)),
                                    ((__0__X95->__O1__4stmt.d = ((struct name *)0)),
                                     (__0__X95->__O3__4stmt.where2 = __2__X97)))))
                         : (((void)0))),
                    __0__X95))));
            __1f->f_init__3fct = __1e;
        }

        {
            Pname __1nn;

            __1nn = dcl__4nameFP5tableUc(__1fn, __0this->memtbl__8classdef, (unsigned char)25);
            ((__1fn
                  ? (((void)(__1fn ? (((void)((((((struct expr *)__1fn))
                                                    ? (((void)((((struct expr *)__1fn))
                                                                   ? (((void)(((void)0))))
                                                                   : (((void)0)))))
                                                    : (((void)0)))),
                                              (((void)__dl__4nameSFPvUl(
                                                  (void *)__1fn, (size_t)(sizeof(struct name))))))))
                                   : (((void)0)))))
                  : (((void)0))));

            if (__1def) {
                struct dcl_context *__0__X98;

                (((cc--), (((void)0))));
                simpl__4nameFv(__1nn);
                if (debug_opt)
                    dcl_print__4nameFUc(__1nn, (unsigned char)0);
            }
            return __1nn;
        }
    }
}

Ptype is_op_ass__FP3fctP8classdef(Pfct __1f, Pclass __1tcl) {
    Ptype __1t;
    Pname __1an;

    struct classdef *__1__X99;

    struct classdef *__1__X100;

    __1t = __1f->argtype__3fct->__O1__4expr.tp;
    __1an = is_cl_obj__4typeFv(__1t);
    if ((__1an == 0) && (__1t = (struct type *)is_ref__4typeFv(__1t))) {
        __1t = (((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp;

        {
            Ptype __2nt;

            __2nt = __1t;
            while (__2nt->base__4node == 97)
                __2nt = (((struct basetype *)(((struct basetype *)__2nt))))
                            ->b_name__8basetype->__O1__4expr.tp;

            if (__2nt->base__4node == 119)
                __1an = (((struct basetype *)(((struct basetype *)__2nt))))->b_name__8basetype;
        }
    }
    if (__1an && ((__1__X99 = (((struct classdef *)(((struct classdef *)__1an->__O1__4expr.tp))))),
                  ((__1__X100 = __1tcl),
                   (((__1__X99 == __1__X100)
                         ? 1
                         : ((__1__X99 && __1__X100)
                                ? (((int)same_class__8classdefFP8classdefi(__1__X99, __1__X100, 0)))
                                : 0))))))
        return __1t;
    return (struct type *)0;
}

Pname has_oper__8classdefFUc(struct classdef *__0this, TOK);

extern const char *oper_name__FUc(TOK);

void dcl__3fctFP4name(struct fct *__0this, Pname);

int make_assignment__FP4name(Pname __1cn) {
    Pclass __1cl;
    Pstmt __1s;
    Pexpr __1e;
    Pname __1arg;

    unsigned long __2__X110;

    const void *__2__X111;

    struct estmt *__0__X136;

    struct loc __2__X137;

    __1cl = (((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))));
    __1s = (struct stmt *)((__0__X136 = 0),
                           ((__2__X137 = no_where),
                            (((__0__X136 || (__0__X136 = (struct estmt *)__nw__4stmtSFUl(
                                                 (unsigned long)(sizeof(struct estmt)))))
                                  ? ((__0__X136 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                          ((struct stmt *)__0__X136), ((unsigned char)72),
                                          __2__X137, ((struct stmt *)0))),
                                     (__0__X136->__O2__4stmt.e = ((struct expr *)0)))
                                  : 0),
                             __0__X136)));
    __1e = 0;
    __1arg = __ct__4nameFPCc((struct name *)0, (const char *)make_name__FUc((unsigned char)'A'));
    __1arg->__O1__4expr.tp = find_arg_type__FP8classdef(__1cl);

    if (warning_opt && (128 < __1cl->obj_size__8classdef)) {
        struct ea __0__V101;

        struct ea __0__V102;

        error__FiPCcRC2eaN33(
            (int)'w', (const char *)"copying a %d byte object (ofC %s)",
            (const struct ea *)((__2__X110 = __1cl->obj_size__8classdef),
                                (((((&__0__V101)->__O1__2ea.i = __2__X110), 0)), (&__0__V101))),
            (const struct ea *)((__2__X111 = (const void *)__1cl->string__8classdef),
                                (((&__0__V102)->__O1__2ea.p = __2__X111), (&__0__V102))),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    {
        int __1slow;
        int __1first;
        bit __1unconst;

        int __1i;

        __1slow = 0;
        __1first = 1;
        __1unconst = 0;

        if (__1cl->baselist__8classdef)
            __1slow = 1;

        if (__1slow) {
            {
                {
                    Pbcl __2b;

                    __2b = __1cl->baselist__8classdef;

                    for (; __2b; __2b = __2b->next__6basecl) {
                        Pclass __3bcl;
                        Ptype __3pt;

                        __3bcl = __2b->bclass__6basecl;
                        __3pt = __3bcl->this_type__8classdef;
                        switch (__2b->base__4node) {
                        case 85: {
                            Pexpr __5b1;

                            struct texpr *__0__X112;

                            __5b1 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)34,
                                                           (struct expr *)0, (struct expr *)0);
                            __5b1 = (struct expr *)((__0__X112 = 0),
                                                    (((__0__X112 ||
                                                       (__0__X112 = (struct texpr *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct texpr)))))
                                                          ? ((__0__X112 = (struct texpr *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X112),
                                                                      ((unsigned char)191), __5b1,
                                                                      (struct expr *)0)),
                                                             (__0__X112->__O4__4expr.tp2 = __3pt))
                                                          : 0),
                                                     __0__X112));
                            __5b1 = contents__4exprFv(__5b1);

                            {
                                Pexpr __5b2;

                                struct texpr *__0__X113;

                                __5b2 = (struct expr *)__ct__4nameFPCc((struct name *)0,
                                                                       __1arg->__O2__4expr.string);
                                __5b2 = address__4exprFv(__5b2);
                                __5b2 =
                                    (struct expr *)((__0__X113 = 0),
                                                    (((__0__X113 ||
                                                       (__0__X113 = (struct texpr *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct texpr)))))
                                                          ? ((__0__X113 = (struct texpr *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X113),
                                                                      ((unsigned char)191), __5b2,
                                                                      (struct expr *)0)),
                                                             (__0__X113->__O4__4expr.tp2 = __3pt))
                                                          : 0),
                                                     __0__X113));
                                __5b2->__O3__4expr.i2 = 1;
                                __5b2 = contents__4exprFv(__5b2);

                                {
                                    Pexpr __5ee;

                                    __5ee = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                   (unsigned char)70, __5b1, __5b2);
                                    __1e = (__1e ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                          (unsigned char)71, __1e,
                                                                          __5ee)
                                                 : __5ee);
                                    break;
                                }
                            }
                        }
                        case 77:
                            if (warning_opt) {
                                struct ea __0__V103;

                                error__FiPCcRC2eaN33(
                                    (int)'w',
                                    (const char *)"copying an object ofC%n with a virtualBC",
                                    (const struct ea *)(((&__0__V103)->__O1__2ea.p =
                                                             ((const void *)__1cn)),
                                                        (&__0__V103)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            if (__2b->ptr_offset__6basecl) {
                                Pexpr __5b1;

                                register struct mdot *__0__X114;

                                const char *__2__X115;

                                __5b1 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)34,
                                                               (struct expr *)0, (struct expr *)0);
                                __5b1 =
                                    (struct expr
                                         *)((__0__X114 = 0),
                                            ((__2__X115 = __3bcl->string__8classdef),
                                             (((__0__X114 ||
                                                (__0__X114 = (struct mdot *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct mdot)))))
                                                   ? ((__0__X114 =
                                                           (struct mdot *)__ct__4exprFUcP4exprT2(
                                                               ((struct expr *)__0__X114),
                                                               (unsigned char)177, (struct expr *)0,
                                                               (struct expr *)0)),
                                                      ((__0__X114->__O3__4expr.string2 = __2__X115),
                                                       (__0__X114->__O4__4expr.mem = __5b1)))
                                                   : 0),
                                              __0__X114)));
                                __5b1->__O2__4expr.i1 = 3;
                                __5b1->__O1__4expr.tp = __3pt;
                                __5b1 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111,
                                                               __5b1, (struct expr *)0);

                                {
                                    Pexpr __5b2;

                                    register struct mdot *__0__X116;

                                    const char *__2__X117;

                                    __5b2 = (struct expr *)__ct__4nameFPCc(
                                        (struct name *)0, __1arg->__O2__4expr.string);
                                    __5b2 = address__4exprFv(__5b2);
                                    __5b2 =
                                        (struct expr
                                             *)((__0__X116 = 0),
                                                ((__2__X117 = __3bcl->string__8classdef),
                                                 (((__0__X116 ||
                                                    (__0__X116 = (struct mdot *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct mdot)))))
                                                       ? ((__0__X116 = (struct mdot *)
                                                               __ct__4exprFUcP4exprT2(
                                                                   ((struct expr *)__0__X116),
                                                                   (unsigned char)177,
                                                                   (struct expr *)0,
                                                                   (struct expr *)0)),
                                                          ((__0__X116->__O3__4expr.string2 =
                                                                __2__X117),
                                                           (__0__X116->__O4__4expr.mem = __5b2)))
                                                       : 0),
                                                  __0__X116)));
                                    __5b2->__O2__4expr.i1 = 3;
                                    __5b2->__O1__4expr.tp = __3pt;
                                    __5b2 =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111,
                                                               __5b2, (struct expr *)0);

                                    {
                                        Pexpr __5ee;

                                        __5ee = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)70, __5b1, __5b2);
                                        __1e = (__1e ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                              (unsigned char)71,
                                                                              __1e, __5ee)
                                                     : __5ee);
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }

        ;
        {
            {
                Pname __1m;

                struct table *__0__X118;

                int __2__X119;

                struct table *__0__X134;

                int __2__X135;

                __1m = ((__0__X134 = __1cl->memtbl__8classdef),
                        ((__2__X135 = (__1i = 1)),
                         ((((__2__X135 <= 0) || (__0__X134->free_slot__5table <= __2__X135))
                               ? (((struct name *)0))
                               : (__0__X134->entries__5table[__2__X135])))));

                for (; __1m; __1m = (__1m->n_tbl_list__4name
                                         ? __1m->n_tbl_list__4name
                                         : ((__0__X118 = __1cl->memtbl__8classdef),
                                            ((__2__X119 = (++__1i)),
                                             ((((__2__X119 <= 0) ||
                                                (__0__X118->free_slot__5table <= __2__X119))
                                                   ? (((struct name *)0))
                                                   : (__0__X118->entries__5table[__2__X119]))))))) {
                    if (__1m->base__4node == 123)
                        continue;

                    if (__1m->n_evaluated__4name || (__1m->n_stclass__4name == 31))
                        continue;

                    if (strcmp(__1m->__O2__4expr.string, (const char *)"__vptr") == 0) {
                        if (((__1first == 0) && __1m->n_offset__4name) && (!__1e)) {
                            Pexpr __4th;
                            Pexpr __4a;

                            __4th = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)34,
                                                           (struct expr *)0, (struct expr *)0);
                            __4a = (struct expr *)__ct__4nameFPCc((struct name *)0,
                                                                  __1arg->__O2__4expr.string);
                            __4a = address__4exprFv(__4a);
                            __1e = copy_obj__FP4exprT1i(__4th, __4a, __1m->n_offset__4name);
                        }
                        __1slow = 1;
                        __1first = 0;
                        continue;
                    }
                    {
                        Ptype __2mt;

                        __2mt = __1m->__O1__4expr.tp;
                        if (__2mt)
                        tx:
                            switch (__2mt->base__4node) {
                            case 97:
                                __2mt = (((struct basetype *)(((struct basetype *)__2mt))))
                                            ->b_name__8basetype->__O1__4expr.tp;
                                goto tx;
                            case 110: {
                                Pname __4cn;

                                __4cn = is_cl_obj__4typeFv(
                                    (((struct vec *)(((struct vec *)__2mt))))->typ__5pvtyp);
                                if (__4cn && ((((struct classdef *)((
                                                   (struct classdef *)__4cn->__O1__4expr.tp))))
                                                  ->c_xref__8classdef &
                                              12)) {
                                    {
                                        struct ea __0__V104;

                                        struct ea __0__V105;

                                        error__FiPCcRC2eaN33(
                                            (int)'s',
                                            (const char *)"copy of %n[], no memberwise copy for%n",
                                            (const struct ea *)(((&__0__V104)->__O1__2ea.p =
                                                                     ((const void *)__4cn)),
                                                                (&__0__V104)),
                                            (const struct ea *)(((&__0__V105)->__O1__2ea.p =
                                                                     ((const void *)__4cn)),
                                                                (&__0__V105)),
                                            (const struct ea *)ea0, (const struct ea *)ea0);
                                        __1slow = 1;
                                    }
                                }

                                if (__1slow && tsizeof__4typeFi(__2mt, 0)) {
                                    Pexpr __5l;
                                    Pexpr __5r;

                                    struct ref *__0__X120;

                                    struct expr *__2__X121;

                                    struct expr *__2__X122;

                                    __5l = (struct expr *)__ct__4nameFPCc((struct name *)0,
                                                                          __1m->__O2__4expr.string);
                                    __5r = (struct expr *)__ct__4nameFPCc((struct name *)0,
                                                                          __1m->__O2__4expr.string);
                                    __5r =
                                        (struct expr
                                             *)((__0__X120 = 0),
                                                ((__2__X121 = (struct expr *)__ct__4nameFPCc(
                                                      (struct name *)0,
                                                      __1arg->__O2__4expr.string)),
                                                 ((__2__X122 = __5r),
                                                  (((__0__X120 ||
                                                     (__0__X120 = (struct ref *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct ref)))))
                                                        ? ((__0__X120 = (struct ref *)
                                                                __ct__4exprFUcP4exprT2(
                                                                    ((struct expr *)__0__X120),
                                                                    ((unsigned char)45), __2__X121,
                                                                    (struct expr *)0)),
                                                           (__0__X120->__O4__4expr.mem = __2__X122))
                                                        : 0),
                                                   __0__X120))));
                                    {
                                        Pexpr __5ee;

                                        __5ee = copy_obj__FP4exprT1i(__5l, __5r,
                                                                     tsizeof__4typeFi(__2mt, 0));
                                        __1e = (__1e ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                              (unsigned char)71,
                                                                              __5ee, __1e)
                                                     : __5ee);
                                        break;
                                    }
                                }
                            }
                            case 108:
                            case 76:
                            case 6:
                            case 13:
                                break;
                            case 119: {
                                Pclass __4tempcl;

                                __4tempcl = (((struct classdef *)((
                                    (struct classdef *)(((struct basetype *)((
                                                            (struct basetype *)__2mt))))
                                        ->b_name__8basetype->__O1__4expr.tp))));
                                if ((__1slow == 0) &&
                                    ((((struct classdef *)((
                                          (struct classdef *)(((struct basetype *)((
                                                                  (struct basetype *)__2mt))))
                                              ->b_name__8basetype->__O1__4expr.tp))))
                                         ->c_xref__8classdef &
                                     12)) {
                                    if ((__1first == 0) && __1m->n_offset__4name) {
                                        Pexpr __6th;
                                        Pexpr __6a;

                                        __6th = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)34, (struct expr *)0,
                                            (struct expr *)0);
                                        __6a = (struct expr *)__ct__4nameFPCc(
                                            (struct name *)0, __1arg->__O2__4expr.string);
                                        __6a = address__4exprFv(__6a);
                                        __1e = copy_obj__FP4exprT1i(__6th, __6a,
                                                                    __1m->n_offset__4name);
                                    }
                                    __1slow = 1;
                                }

                                suppress_error++;
                                {
                                    Pname __4nn;

                                    __4nn = has_oper__8classdefFUc(__4tempcl, (unsigned char)70);
                                    suppress_error--;
                                    if (__4nn && (__4nn->__O1__4expr.tp->base__4node == 108)) {
                                        Pptr __5atp;

                                        unsigned long __2__X16;

                                        struct ea __0__X__V1400qmhnqtzzvcnm;

                                        struct ea __0__X__V1500qmhnqtzzvcnm;

                                        __5atp = (((struct ptr *)((
                                            (struct ptr
                                                 *)(((__4nn->__O1__4expr.tp->base__4node == 108)
                                                         ? (((struct fct *)((
                                                               (struct fct *)
                                                                   __4nn->__O1__4expr.tp))))
                                                         : (error__FiPCcRC2eaN33(
                                                                (int)'i',
                                                                (const char *)"N::fct_type():%n is "
                                                                              "%k notF",
                                                                (const struct
                                                                 ea *)(((&__0__X__V1400qmhnqtzzvcnm)
                                                                            ->__O1__2ea.p =
                                                                            ((const void *)__4nn)),
                                                                       (&__0__X__V1400qmhnqtzzvcnm)),
                                                                (const struct
                                                                 ea *)((__2__X16 =
                                                                            __4nn
                                                                                ->__O1__4expr.tp
                                                                                ->base__4node),
                                                                       (((((&__0__X__V1500qmhnqtzzvcnm)
                                                                               ->__O1__2ea.i =
                                                                               __2__X16),
                                                                          0)),
                                                                        (&__0__X__V1500qmhnqtzzvcnm))),
                                                                (const struct ea *)ea0,
                                                                (const struct ea *)ea0),
                                                            (((struct fct *)0)))))
                                                ->argtype__3fct->__O1__4expr.tp))));
                                        if ((__5atp && __5atp->typ__5pvtyp) &&
                                            (__5atp->typ__5pvtyp->b_const__4type == 0)) {
                                            __1unconst = 1;
                                        }
                                    } else if (__4nn &&
                                               (__4nn->__O1__4expr.tp->base__4node == 76)) {
                                        Plist __5pl;

                                        __5pl = (((struct gen *)((
                                                     (struct gen *)__4nn->__O1__4expr.tp))))
                                                    ->fct_list__3gen;
                                        while (__5pl) {
                                            Pfct __6ff;
                                            Ptype __6t;

                                            register struct name *__0__X123;

                                            unsigned long __2__X16;

                                            struct ea __0__X__V1400qmhnqtzzvcnm;

                                            struct ea __0__X__V1500qmhnqtzzvcnm;

                                            __6ff =
                                                ((__0__X123 = __5pl->f__9name_list),
                                                 (((__0__X123->__O1__4expr.tp->base__4node == 108)
                                                       ? (((struct fct *)(((struct fct *)__0__X123
                                                                               ->__O1__4expr.tp))))
                                                       : (error__FiPCcRC2eaN33(
                                                              (int)'i',
                                                              (const char
                                                                   *)"N::fct_type():%n is %k notF",
                                                              (const struct ea
                                                                   *)(((&__0__X__V1400qmhnqtzzvcnm)
                                                                           ->__O1__2ea.p = ((
                                                                           const void *)__0__X123)),
                                                                      (&__0__X__V1400qmhnqtzzvcnm)),
                                                              (const struct
                                                               ea *)((__2__X16 =
                                                                          __0__X123->__O1__4expr.tp
                                                                              ->base__4node),
                                                                     (((((&__0__X__V1500qmhnqtzzvcnm)
                                                                             ->__O1__2ea.i =
                                                                             __2__X16),
                                                                        0)),
                                                                      (&__0__X__V1500qmhnqtzzvcnm))),
                                                              (const struct ea *)ea0,
                                                              (const struct ea *)ea0),
                                                          (((struct fct *)0))))));
                                            __6t = is_op_ass__FP3fctP8classdef(__6ff, __4tempcl);
                                            if (__6t && (__6t->b_const__4type == 0)) {
                                                __1unconst = 1;
                                                break;
                                            }
                                            __5pl = __5pl->l__9name_list;
                                        }
                                    }
                                }
                            }

                            case 158:
                                if (__2mt->base__4node == 158)
                                    if (__1cl->c_xref__8classdef != 16) {
                                        {
                                            struct ea __0__V106;

                                            struct ea __0__V107;

                                            error__FPCcRC2eaN32(
                                                (const char *)"cannot assignC%t:RM%n",
                                                (const struct ea *)(((&__0__V106)->__O1__2ea.p =
                                                                         ((const void *)__1cl)),
                                                                    (&__0__V106)),
                                                (const struct ea *)(((&__0__V107)->__O1__2ea.p =
                                                                         ((const void *)__1m)),
                                                                    (&__0__V107)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                                            break;
                                        }
                                    } else
                                        __1slow = 1;
                            default:
                                if (__1slow) {
                                    if (tconst__4typeFv(__1m->__O1__4expr.tp)) {
                                        struct ea __0__V108;

                                        struct ea __0__V109;

                                        error__FPCcRC2eaN32(
                                            (const char *)"cannot assignC%t: const M%n",
                                            (const struct ea *)(((&__0__V108)->__O1__2ea.p =
                                                                     ((const void *)__1cl)),
                                                                (&__0__V108)),
                                            (const struct ea *)(((&__0__V109)->__O1__2ea.p =
                                                                     ((const void *)__1m)),
                                                                (&__0__V109)),
                                            (const struct ea *)ea0, (const struct ea *)ea0);
                                    }
                                    {
                                        Pname __4ms;
                                        Pname __4as;
                                        Pexpr __4ee;

                                        struct ref *__0__X124;

                                        struct expr *__2__X125;

                                        struct expr *__2__X126;

                                        __4ms = __ct__4nameFPCc((struct name *)0,
                                                                __1m->__O2__4expr.string);
                                        __4as = __ct__4nameFPCc((struct name *)0,
                                                                __1arg->__O2__4expr.string);
                                        __4ee =
                                            (struct expr
                                                 *)((__0__X124 = 0),
                                                    ((__2__X125 = (struct expr *)__4as),
                                                     ((__2__X126 = (struct expr *)__ct__4nameFPCc(
                                                           (struct name *)0,
                                                           __1m->__O2__4expr.string)),
                                                      (((__0__X124 ||
                                                         (__0__X124 = (struct ref *)__nw__4exprSFUl(
                                                              (size_t)(sizeof(struct ref)))))
                                                            ? ((__0__X124 = (struct ref *)
                                                                    __ct__4exprFUcP4exprT2(
                                                                        ((struct expr *)__0__X124),
                                                                        ((unsigned char)45),
                                                                        __2__X125,
                                                                        (struct expr *)0)),
                                                               (__0__X124->__O4__4expr.mem =
                                                                    __2__X126))
                                                            : 0),
                                                       __0__X124))));
                                        __4ee = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                       (unsigned char)70,
                                                                       (struct expr *)__4ms, __4ee);
                                        __1e = (__1e ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                              (unsigned char)71,
                                                                              __1e, __4ee)
                                                     : __4ee);
                                    }
                                }
                            }
                        __1first = 0;
                    }
                }

                if (__1slow == 0) {
                    return 0;
                }

                {
                    Pexpr __1rv;

                    struct estmt *__0__X127;

                    struct loc __2__X128;

                    struct dcl_context *__0__X129;

                    __1rv = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)34,
                                                   (struct expr *)0, (struct expr *)0);
                    __1rv = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111, __1rv,
                                                   (struct expr *)0);

                    __1s->__O2__4stmt.e =
                        (__1e ? __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, __1e,
                                                       __1rv)
                              : __1e);
                    __1s->s_list__4stmt =
                        (struct stmt
                             *)((__0__X127 = 0),
                                ((__2__X128 = no_where),
                                 (((__0__X127 || (__0__X127 = (struct estmt *)__nw__4stmtSFUl(
                                                      (size_t)(sizeof(struct estmt)))))
                                       ? ((__0__X127 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                               ((struct stmt *)__0__X127), ((unsigned char)28),
                                               __2__X128, ((struct stmt *)0))),
                                          (__0__X127->__O2__4stmt.e = __1rv))
                                       : 0),
                                  __0__X127)));

                    ((((cc++), (((cc >= ccvec_end)
                                     ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow")
                                     : 0),
                                (((*cc)) = (*(cc - 1))))),
                      (((void)0))));
                    cc->not4__11dcl_context = __1cn;
                    cc->cot__11dcl_context = __1cl;

                    __1cl->c_xref__8classdef |= 4;

                    {
                        Pname __1fn;
                        Pfct __1f;

                        __1fn =
                            __ct__4nameFPCc((struct name *)0, oper_name__FUc((unsigned char)70));
                        __1f = __ct__3fctFP4typeP4nameUc(
                            (struct fct *)0,
                            (struct type *)__ct__3ptrFUcP4type(
                                (struct ptr *)0, (unsigned char)158,
                                (((struct ptr *)(((struct ptr *)__1cl->this_type__8classdef))))
                                    ->typ__5pvtyp),
                            __1arg, (unsigned char)1);
                        __1f->f_inline__3fct = 1;
                        __1f->f_is_inline__3fct = 1;
                        if (__1unconst)
                            (((struct ptr *)(((struct ptr *)__1f->argtype__3fct->__O1__4expr.tp))))
                                ->typ__5pvtyp->b_const__4type = 0;
                        __1fn->__O1__4expr.tp = (struct type *)__1f;
                        __1fn->n_oper__4name = 70;
                        __1fn->n_sto__4name = 31;
                        {
                            Pname __1nn;

                            register struct block *__0__X130;

                            struct loc __2__X131;

                            struct loc __2__X132;

                            struct dcl_context *__0__X133;

                            __1nn = dcl__4nameFP5tableUc(__1fn, __1cl->memtbl__8classdef,
                                                         (unsigned char)25);
                            ((__1fn
                                  ? (((void)(__1fn
                                                 ? (((void)((((((struct expr *)__1fn))
                                                                  ? (((void)((((struct expr *)
                                                                                   __1fn))
                                                                                 ? (((void)((
                                                                                       (void)0))))
                                                                                 : (((void)0)))))
                                                                  : (((void)0)))),
                                                            (((void)__dl__4nameSFPvUl(
                                                                (void *)__1fn,
                                                                (size_t)(sizeof(struct name))))))))
                                                 : (((void)0)))))
                                  : (((void)0))));
                            (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))->body__3fct =
                                ((__0__X130 = 0),
                                 ((__2__X131 = curloc),
                                  ((__2__X132 = noloc),
                                   (((__0__X130 || (__0__X130 = (struct block *)__nw__4stmtSFUl(
                                                        (size_t)(sizeof(struct block)))))
                                         ? (((void)((__0__X130 =
                                                         (struct block *)__ct__4stmtFUc3locP4stmt(
                                                             ((struct stmt *)__0__X130),
                                                             (unsigned char)116, __2__X131, __1s)),
                                                    ((__0__X130->__O1__4stmt.d =
                                                          ((struct name *)0)),
                                                     (__0__X130->__O3__4stmt.where2 = __2__X132)))))
                                         : (((void)0))),
                                    __0__X130))));
                            dcl__3fctFP4name(
                                ((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))), __1nn);

                            (((cc--), (((void)0))));
                            simpl__4nameFv(__1nn);

                            return 1;
                        }
                    }
                }
            }
        }
    }
}

void prnt_all_in_scope__FP8classdef(Pclass __1cl);

void prnt_all_in_scope__FP8classdef(Pclass __1cl) {
    int __1i;

    if (__1cl->in_class__4type)
        prnt_all_in_scope__FP8classdef(__1cl->in_class__4type);
    {
        {
            Pname __1nn;

            struct table *__0__X138;

            int __2__X139;

            struct table *__0__X140;

            int __2__X141;

            __1nn = ((__0__X140 = __1cl->memtbl__8classdef),
                     ((__2__X141 = (__1i = 1)),
                      ((((__2__X141 <= 0) || (__0__X140->free_slot__5table <= __2__X141))
                            ? (((struct name *)0))
                            : (__0__X140->entries__5table[__2__X141])))));

            for (; __1nn;
                 __1nn =
                     (__1nn->n_tbl_list__4name
                          ? __1nn->n_tbl_list__4name
                          : ((__0__X138 = __1cl->memtbl__8classdef),
                             ((__2__X139 = (++__1i)),
                              ((((__2__X139 <= 0) || (__0__X138->free_slot__5table <= __2__X139))
                                    ? (((struct name *)0))
                                    : (__0__X138->entries__5table[__2__X139]))))))) {
                if (__1nn->base__4node == 123)
                    continue;

                if ((((__1nn->base__4node && (__1nn->base__4node == 85)) &&
                      (__1nn->n_anon__4name == 0)) &&
                     (__1nn->n_stclass__4name == 31)) &&
                    (__1nn->__O1__4expr.tp && ((((__1nn->__O1__4expr.tp->base__4node != 108) &&
                                                 (__1nn->__O1__4expr.tp->base__4node != 76)) &&
                                                (__1nn->__O1__4expr.tp->base__4node != 6)) &&
                                               (__1nn->__O1__4expr.tp->base__4node != 13)))) {
                    dcl_print__4nameFUc(__1nn, (unsigned char)0);
                }
            }
        }
    }
}

bit simpl_friend = 0;

extern int error__FPCc(const char *);

int check_dup__8classdefFP8classdefUc(struct classdef *__0this, Pclass, TOK);

int align__4typeFv(struct type *__0this);

void grow__5tableFi(struct table *__0this, int);

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

Pclass is_base__8classdefFPCcPUci(struct classdef *__0this, const char *, TOK *, int __1level);

Pexpr find_name__8classdefFPCcP8classdefiT3(struct classdef *__0this, const char *, Pclass, int,
                                            int);

extern char *make_nested_name__FPCcP8classdef(const char *, Pclass);

struct name_list *__ct__9name_listFP4nameP9name_list(struct name_list *__0this, Pname __1ff,
                                                     Plist __1ll);

Pname has_ictor__8classdefFv(struct classdef *__0this);

extern Pname find_vptr__FP8classdef(Pclass);

extern int is_probably_temp__FPCc(const char *);

extern const char *curr_filename__Fv(void);

void simpl__8classdefFv(struct classdef *__0this);

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

extern void dump_func__FP8classdef(Pclass);

extern void check_abst__FP8classdef(Pclass);

void dcl__8classdefFP4nameP5table(register struct classdef *__0this, Pname __1cname,
                                  Ptable __1tbl) {
    int __1bvirt;
    int __1dvirt;
    int __1scope;
    int __1protect;
    int __1st;

    int __1byte_old;
    int __1bit_old;
    int __1max_old;
    int __1boff;

    int __1in_union;
    int __1usz;
    int __1make_ctor;
    int __1make_dtor;

    unsigned long __2__X212;

    unsigned long __2__X213;

    struct table *__0__X222;

    __1bvirt = 0;
    __1dvirt = 0;
    __1scope = 25;
    __1protect = 0;
    __1st = 1;

    __1byte_old = byte_offset;
    __1bit_old = bit_offset;
    __1max_old = max_align;
    __1boff = 0;

    __1in_union = 0;

    __1make_ctor = 0;
    __1make_dtor = 0;

    if (__0this == 0) {
        struct ea __0__V142;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"0->Cdef::dcl(%p)",
            (const struct ea *)(((&__0__V142)->__O1__2ea.p = ((const void *)__1tbl)), (&__0__V142)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__0this->base__4node != 6) {
        struct ea __0__V143;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"Cdef::dcl(%d)",
            (const struct ea *)((__2__X212 = __0this->base__4node),
                                (((((&__0__V143)->__O1__2ea.i = __2__X212), 0)), (&__0__V143))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__1cname == 0)
        error__FiPCc((int)'i', (const char *)"unNdC");

    if (__1cname->__O1__4expr.tp != (((struct type *)__0this)))
        error__FiPCc((int)'i', (const char *)"badCdef");
    if (__1tbl == 0) {
        struct ea __0__V144;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"Cdef::dcl(%n,0)",
            (const struct ea *)(((&__0__V144)->__O1__2ea.p = ((const void *)__1cname)),
                                (&__0__V144)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__1tbl->base__4node != 142) {
        struct ea __0__V145;

        struct ea __0__V146;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"Cdef::dcl(%n,tbl=%d)",
            (const struct ea *)(((&__0__V145)->__O1__2ea.p = ((const void *)__1cname)),
                                (&__0__V145)),
            (const struct ea *)((__2__X213 = __1tbl->base__4node),
                                (((((&__0__V146)->__O1__2ea.i = __2__X213), 0)), (&__0__V146))),
            (const struct ea *)ea0, (const struct ea *)ea0);
    };

    switch (__0this->csu__8classdef) {
    case 36:
        __1in_union = 36;
        break;
    case 167:
        __1in_union = 167;
        break;
    case 6:
        __1scope = 0;
    }

    max_align = AL_STRUCT;

    if (__0this->local_sig__4type) {
        __0this->c_context__8classdef = __1tbl;
        __0this->in_fct__4type = cc->nof__11dcl_context;
    } else
        __0this->in_fct__4type = 0;

    if (__0this->baselist__8classdef) {
        Pbcl __2ll;
        Pbcl __2lll;
        Pbcl __2vlist;
        Pbcl __2lx;

        Pbcl __2l;

        __2ll = 0;
        __2lll = 0;
        __2vlist = 0;
        __2l = __0this->baselist__8classdef;
        for (; __2l; __2l = __2lx) {
            Pclass __3cl;

            __3cl = __2l->bclass__6basecl;

            __2lx = __2l->next__6basecl;

            if (__2l->ppp__6basecl == 0) {
                __2l->ppp__6basecl = ((__0this->csu__8classdef == 6) ? 174 : 25);

                if (__2l->ppp__6basecl == 174) {
                    struct ea __0__V147;

                    struct ea __0__V148;

                    error__FiPCcRC2eaN33(
                        (int)'w',
                        (const char *)"B%t private by default: please be explicit ``: private%t",
                        (const struct ea *)(((&__0__V147)->__O1__2ea.p = ((const void *)__3cl)),
                                            (&__0__V147)),
                        (const struct ea *)(((&__0__V148)->__O1__2ea.p = ((const void *)__3cl)),
                                            (&__0__V148)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }

            if (__3cl && (__3cl->csu__8classdef == 6))
                __1st = 0;

            if ((__3cl->defined__4type & 3) == 0) {
                {
                    struct ea __0__V149;

                    error__FPCcRC2eaN32(
                        (const char *)"BC %tU",
                        (const struct ea *)(((&__0__V149)->__O1__2ea.p = ((const void *)__3cl)),
                                            (&__0__V149)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    continue;
                }
            } else
                ((void)tsizeof__4typeFi((struct type *)__3cl, 0));

            if ((__3cl->csu__8classdef == 36) || (__3cl->csu__8classdef == 167)) {
                error__FPCc((const char *)"C derived from union");
                continue;
            }

            if (__1in_union) {
                error__FPCc((const char *)"derived union");
                continue;
            }

            if ((((warning_opt &&
                   ((__2l->base__4node == 77) || (__2l != __0this->baselist__8classdef))) &&
                  (__3cl->c_dtor__8classdef)) &&
                 (__3cl->c_dtor__8classdef)->__O1__4expr.tp) &&
                (!(((struct fct *)(((struct fct *)(__3cl->c_dtor__8classdef)->__O1__4expr.tp))))
                      ->f_virtual__3fct)) {
                struct ea __0__V150;

                error__FiPCcRC2eaN33(
                    (int)'w', (const char *)"second or virtualBC%tWout virtual destructor",
                    (const struct ea *)(((&__0__V150)->__O1__2ea.p = ((const void *)__3cl)),
                                        (&__0__V150)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__2l->base__4node == 77) {
                __2l->next__6basecl = __2vlist;
                __2vlist = __2l;
            } else {
                if (__2ll == 0) {
                    __2lll = __2l;
                    __2l->next__6basecl = 0;
                } else
                    __2ll->next__6basecl = __2l;
                __2ll = __2l;
            }
        }
        if (__2ll) {
            __2ll->next__6basecl = __2vlist;
            __0this->baselist__8classdef = __2lll;
        } else
            __0this->baselist__8classdef = __2vlist;

        __2lll = 0;
        __2l = __0this->baselist__8classdef;
        for (; __2l; __2l = __2l->next__6basecl) {
            Pclass __3b;

            struct classdef *__1__X214;

            struct classdef *__1__X215;

            __3b = __2l->bclass__6basecl;

            for (__2ll = __0this->baselist__8classdef; __2ll; __2ll = __2ll->next__6basecl)
                if ((!((__1__X214 = __3b), ((__1__X215 = __2ll->bclass__6basecl),
                                            (((__1__X214 == __1__X215)
                                                  ? 1
                                                  : ((__1__X214 && __1__X215)
                                                         ? (((int)same_class__8classdefFP8classdefi(
                                                               __1__X214, __1__X215, 0)))
                                                         : 0)))))) &&
                    check_dup__8classdefFP8classdefUc(__2ll->bclass__6basecl, __3b,
                                                      __2l->base__4node)) {
                    if (__2lll)
                        __2lll->next__6basecl = __2l->next__6basecl;
                    else
                        __0this->baselist__8classdef = __2l->next__6basecl;
                    goto mmm;
                }

            __2lll = __2l;
        mmm:;
        }

        for (__2l = __0this->baselist__8classdef; __2l; __2l = __2l->next__6basecl) {
            Pclass __3b;

            __3b = __2l->bclass__6basecl;
            for (__2ll = __3b->baselist__8classdef; __2ll; __2ll = __2ll->next__6basecl) {
                if (__2ll->base__4node == 77) {
                    Pclass __5v;

                    __5v = __2ll->bclass__6basecl;
                    {
                        {
                            Pbcl __5lll;

                            struct classdef *__1__X216;

                            struct classdef *__1__X217;

                            register struct basecl *__0__X218;

                            struct basecl *__2__X219;

                            struct node *__0__X9;

                            __5lll = __0this->baselist__8classdef;

                            for (; __5lll; __5lll = __5lll->next__6basecl)
                                if (((__1__X216 = __5lll->bclass__6basecl),
                                     ((__1__X217 = __5v),
                                      (((__1__X216 == __1__X217)
                                            ? 1
                                            : ((__1__X216 && __1__X217)
                                                   ? (((int)same_class__8classdefFP8classdefi(
                                                         __1__X216, __1__X217, 0)))
                                                   : 0)))))) {
                                    if (__2ll->ppp__6basecl < __5lll->ppp__6basecl)
                                        __5lll->ppp__6basecl = __2ll->ppp__6basecl;
                                    goto nnn;
                                }
                            __0this->baselist__8classdef =
                                ((__0__X218 = 0),
                                 ((__2__X219 = __0this->baselist__8classdef),
                                  (((__0__X218 || (__0__X218 = (struct basecl *)__nw__FUl(
                                                       (size_t)(sizeof(struct basecl)))))
                                        ? ((__0__X218 =
                                                (struct basecl
                                                     *)((__0__X9 = (((struct node *)__0__X218))),
                                                        (((__0__X9 ||
                                                           (__0__X9 = (struct node *)__nw__FUl(
                                                                (size_t)(sizeof(struct node)))))
                                                              ? (((__0__X9->base__4node = 0),
                                                                  (__0__X9->permanent__4node = 0)),
                                                                 (__0__X9->baseclass__4node = 0))
                                                              : 0),
                                                         __0__X9))),
                                           ((__0__X218->baseclass__4node = 1),
                                            ((__0__X218->bclass__6basecl = __5v),
                                             ((__0__X218->next__6basecl = __2__X219),
                                              ((__0__X218->promoted__6basecl = 0),
                                               ((__0__X218->init__6basecl = 0),
                                                ((__0__X218->obj_offset__6basecl =
                                                      (__0__X218->ptr_offset__6basecl = 0)),
                                                 (__0__X218->allocated__6basecl = 0))))))))
                                        : 0),
                                   __0__X218)));
                            __0this->baselist__8classdef->base__4node = 77;
                            __0this->baselist__8classdef->promoted__6basecl = 1;

                            __0this->baselist__8classdef->ppp__6basecl = __2ll->ppp__6basecl;
                        }
                    }
                }
            nnn:;
            }
        }

        __2ll = 0;
        __2lll = 0;
        __2l = __0this->baselist__8classdef;
        __0this->baselist__8classdef = 0;
        __2vlist = 0;
        for (; __2l; __2l = __2lx) {
            __2lx = __2l->next__6basecl;
            if (__2l->base__4node == 77) {
                if (__2vlist == 0) {
                    __2vlist = __2l;
                    __2l->next__6basecl = 0;
                } else {
                    Pclass __5lb;
                    Pbcl __5v_prev;

                    __5lb = __2l->bclass__6basecl;
                    __5v_prev = 0;
                    {
                        {
                            Pbcl __5vx;

                            Pbcl __5v;

                            __5v = __2vlist;

                            for (; __5v; __5v = __5vx) {
                                Pclass __6vb;

                                __6vb = __5v->bclass__6basecl;
                                __5vx = __5v->next__6basecl;

                                if (has_base__8classdefFP8classdefiT2(__5lb, __6vb, 0, 0)) {
                                    __2l->next__6basecl = __5v;
                                    if (__5v_prev)
                                        __5v_prev->next__6basecl = __2l;
                                    else
                                        __2vlist = __2l;
                                    break;
                                }
                                if (__5vx == 0) {
                                    __5v->next__6basecl = __2l;
                                    __2l->next__6basecl = 0;
                                    break;
                                }
                                __5v_prev = __5v;
                            }
                        }
                    }
                }
            } else {
                if (__2ll == 0) {
                    __2lll = __2l;
                    __2l->next__6basecl = 0;
                } else
                    __2ll->next__6basecl = __2l;
                __2ll = __2l;
            }
        }

        if (__2ll) {
            __2ll->next__6basecl = __2vlist;
            __0this->baselist__8classdef = __2lll;
        } else
            __0this->baselist__8classdef = __2vlist;

        for (__2l = __0this->baselist__8classdef; __2l; __2l = __2l->next__6basecl) {
            Pclass __3cl;

            __3cl = __2l->bclass__6basecl;

            if (__2l->base__4node == 77) {
                __0this->c_xref__8classdef |= 8;
                __1dvirt += __3cl->virt_count__8classdef;
            } else {
                int __4ba;

                struct classdef *__1__X220;

                struct classdef *__1__X221;

                __4ba = align__4typeFv((struct type *)__3cl);
                if (max_align < __4ba)
                    max_align = __4ba;

                if (((__1__X220 = __3cl),
                     ((__1__X221 = __0this->baselist__8classdef->bclass__6basecl),
                      (((__1__X220 == __1__X221)
                            ? 1
                            : ((__1__X220 && __1__X221) ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X220, __1__X221, 0)))
                                                        : 0)))))) {
                    __1boff = __3cl->real_size__8classdef;

                    {
                        int __5xtra;

                        __5xtra = (__1boff % __4ba);

                        if (__5xtra)
                            __1boff += (__4ba - __5xtra);
                    }
                } else {
                    int __5xtra;

                    __5xtra = (__1boff % __4ba);
                    if (__5xtra)
                        __1boff += (__4ba - __5xtra);
                    __2l->obj_offset__6basecl = __1boff;

                    __1boff += __3cl->obj_size__8classdef;
                }
                __1bvirt += __3cl->virt_count__8classdef;
            }

            if (__3cl->has_vvtab__8classdef)
                __0this->has_vvtab__8classdef = 1;
            __0this->c_xref__8classdef |= __3cl->c_xref__8classdef;

            __0this->conv__8classdef =
                merge_conv__FP4nameT1(__0this->conv__8classdef, __3cl->conv__8classdef);
        }
    }

    ((__0__X222 = __0this->memtbl__8classdef),
     ((__0__X222->t_name__5table = __1cname), (((void)0))));

    {
        int __1nmem;
        int __1fct_mem;

        struct dcl_context *__0__X223;

        __1nmem = 0;
        __1fct_mem = 0;
        {
            {
                {
                    Pname __2m;

                    __2m = __0this->mem_list__8classdef;

                    for (; __2m; __2m = __2m->__O1__4name.n_list) {
                        __1nmem++;
                        if (__2m->__O1__4expr.tp && (__2m->__O1__4expr.tp->base__4node == 108))
                            __1fct_mem++;
                        else if (__2m->base__4node == 123)
                            ;
                        else {
                            if ((__2m->__O1__4expr.tp &&
                                 (__2m->__O1__4expr.tp->base__4node == 158)) &&
                                (__0this->c_xref__8classdef == 0))
                                __0this->c_xref__8classdef = 16;

                            if (((ansi_opt && __2m->__O1__4expr.tp) &&
                                 tconst__4typeFv(__2m->__O1__4expr.tp)) &&
                                (__2m->n_sto__4name != 31))
                                (((struct basetype *)(((struct basetype *)__2m->__O1__4expr.tp))))
                                    ->ansi_const__4type = 1;
                        }
                    }
                }
            }
        }

        if (__1nmem)
            grow__5tableFi(__0this->memtbl__8classdef, (__1nmem <= 2) ? 3 : __1nmem);

        ((((cc++),
           (((cc >= ccvec_end) ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow") : 0),
            (((*cc)) = (*(cc - 1))))),
          (((void)0))));
        cc->not4__11dcl_context = __1cname;
        cc->cot__11dcl_context = __0this;

        byte_offset = (__1usz = __1boff);
        bit_offset = 0;

        {
            int __1real_virts;
            Pbase __1bt;

            __1real_virts = 0;
            __1bt = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)119, __1cname);
            __1bt->b_table__8basetype = __0this->memtbl__8classdef;
            {
                Ptype __1cct;

                __1cct = (struct type *)(__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125,
                                                             ((struct type *)__1bt)));

                if (strict_opt && perf_opt)
                    (((struct ptr *)(((struct ptr *)__1cct))))->b_const__4type = 2;
                __0this->this_type__8classdef = (cc->tot__11dcl_context = __1cct);
                __0this->this_type__8classdef->ansi_const__4type = 1;
                __1cct->permanent__4node = 1;
                __1bt->permanent__4node = 1;

                {
                    Pname __1px;

                    Pname __1p;

                    __1p = __0this->mem_list__8classdef;
                    for (; __1p; __1p = __1px) {
                        __1px = __1p->__O1__4name.n_list;

                        switch (__1p->base__4node) {
                            unsigned long __2__X224;

                        case 25:
                            __1scope = 25;
                            __1protect = 0;
                            goto prpr;

                        case 174:
                            __1scope = 0;
                            __1protect = 0;
                            goto prpr;

                        case 79:
                            __1scope = 0;
                            __1protect = 79;
                        prpr:
                            if (__1in_union == 167) {
                                struct ea __0__V151;

                                error__FP3locPCcRC2eaN33(
                                    &__1p->where__4name, (const char *)"%k in anonymous unionD",
                                    (const struct ea *)((__2__X224 = __1p->base__4node),
                                                        (((((&__0__V151)->__O1__2ea.i = __2__X224),
                                                           0)),
                                                         (&__0__V151))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            continue;

                        case 175: {
                            const char *__4qs;
                            const char *__4ms;
                            TOK __4ppp;

                            __4qs = __1p->__O2__4name.n_qualifier->__O2__4expr.string;
                            __4ms = __1p->__O2__4expr.string;
                            __4ppp = (__1scope ? 25 : (__1protect ? 79 : 174));

                            __1p->base__4node = 85;
                            __1p->n_scope__4name = __1scope;
                            __1p->n_protect__4name = __1protect;

                            if (strcmp(__4ms, __4qs) == 0)
                                __4ms = (const char *)"__ct";

                            ppbase = 25;

                            if (is_base__8classdefFPCcPUci(__0this, __4qs, (TOK *)0, 0) == 0) {
                                {
                                    struct ea __0__V152;

                                    struct ea __0__V153;

                                    struct ea __0__V154;

                                    error__FPCcRC2eaN32(
                                        (const char *)"%kQr %s not aBC of %t",
                                        (const struct ea *)(((((&__0__V152)->__O1__2ea.i =
                                                                   ((unsigned long)__4ppp)),
                                                              0)),
                                                            (&__0__V152)),
                                        (const struct ea *)(((&__0__V153)->__O1__2ea.p =
                                                                 ((const void *)__4qs)),
                                                            (&__0__V153)),
                                        (const struct ea *)(((&__0__V154)->__O1__2ea.p =
                                                                 ((const void *)__0this)),
                                                            (&__0__V154)),
                                        (const struct ea *)ea0);
                                    continue;
                                }
                            }

                            mex = 1;
                            tcl = (mec = __0this);
                            {
                                Pname __4os;

                                __4os = Cdcl;
                                Cdcl = __1p;
                                {
                                    Pexpr __4ee;

                                    unsigned long __2__X225;

                                    __4ee = find_name__8classdefFPCcP8classdefiT3(
                                        __0this, __4ms, (struct classdef *)0, 1, 0);
                                    Cdcl = __4os;

                                    if ((__4ee && (__4ee->base__4node != 85)) &&
                                        (__4ee->base__4node != 123)) {
                                        struct ea __0__V155;

                                        struct ea __0__V156;

                                        struct ea __0__V157;

                                        error__FiPCcRC2eaN33(
                                            (int)'i',
                                            (const char
                                                 *)"bad returnE%k from %t->find_name(%s,0,1)",
                                            (const struct ea
                                                 *)((__2__X225 = __4ee->base__4node),
                                                    (((((&__0__V155)->__O1__2ea.i = __2__X225), 0)),
                                                     (&__0__V155))),
                                            (const struct ea *)(((&__0__V156)->__O1__2ea.p =
                                                                     ((const void *)__0this)),
                                                                (&__0__V156)),
                                            (const struct ea *)(((&__0__V157)->__O1__2ea.p =
                                                                     ((const void *)__4ms)),
                                                                (&__0__V157)),
                                            (const struct ea *)ea0);
                                    }
                                    {
                                        Pname __4mx;

                                        __4mx = (((struct name *)(((struct name *)__4ee))));

                                        if (__4mx == 0) {
                                            {
                                                struct ea __0__V158;

                                                struct ea __0__V159;

                                                error__FPCcRC2eaN32(
                                                    (const char *)"C %s does not have aM %s",
                                                    (const struct ea *)(((&__0__V158)->__O1__2ea.p =
                                                                             ((const void *)__4qs)),
                                                                        (&__0__V158)),
                                                    (const struct ea *)(((&__0__V159)->__O1__2ea.p =
                                                                             ((const void *)__4ms)),
                                                                        (&__0__V159)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                                continue;
                                            }
                                        }

                                        if (__4mx->__O1__4expr.tp->base__4node == 76) {
                                            {
                                                struct ea __0__V160;

                                                struct ea __0__V161;

                                                error__FiPCcRC2eaN33(
                                                    (int)'s',
                                                    (const char
                                                         *)"%k specification of overloaded%n",
                                                    (const struct ea
                                                         *)(((((&__0__V160)->__O1__2ea.i =
                                                                   ((unsigned long)__4ppp)),
                                                              0)),
                                                            (&__0__V160)),
                                                    (const struct ea *)(((&__0__V161)->__O1__2ea.p =
                                                                             ((const void *)__4mx)),
                                                                        (&__0__V161)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                                continue;
                                            }
                                        }

                                        {
                                            TOK __4pp;

                                            __4pp = (__4mx->n_scope__4name
                                                         ? 25
                                                         : (__4mx->n_protect__4name ? 79 : 174));

                                            if (__4ppp != __4pp) {
                                                {
                                                    struct ea __0__V162;

                                                    struct ea __0__V163;

                                                    struct ea __0__V164;

                                                    error__FP3locPCcRC2eaN33(
                                                        &__1p->where__4name,
                                                        (const char *)"%kM%n specified%k",
                                                        (const struct ea
                                                             *)(((((&__0__V162)->__O1__2ea.i =
                                                                       ((unsigned long)__4pp)),
                                                                  0)),
                                                                (&__0__V162)),
                                                        (const struct ea
                                                             *)(((&__0__V163)->__O1__2ea.p =
                                                                     ((const void *)__4mx)),
                                                                (&__0__V163)),
                                                        (const struct ea
                                                             *)(((((&__0__V164)->__O1__2ea.i =
                                                                       ((unsigned long)__4ppp)),
                                                                  0)),
                                                                (&__0__V164)),
                                                        (const struct ea *)ea0);
                                                    continue;
                                                }
                                            }

                                            __1p->__O2__4name.n_qualifier = __4mx;
                                            {
                                                Pname __4m;

                                                __4m = insert__5tableFP4nameUc(
                                                    __0this->memtbl__8classdef, __1p,
                                                    (unsigned char)0);
                                                __4m->base__4node = 25;
                                                if (Nold) {
                                                    struct ea __0__V165;

                                                    error__FPCcRC2eaN32(
                                                        (const char *)"twoDs ofCM%n",
                                                        (const struct ea
                                                             *)(((&__0__V165)->__O1__2ea.p =
                                                                     ((const void *)__1p)),
                                                                (&__0__V165)),
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0);
                                                }
                                                continue;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        }

                        if (__1scope == 0) {
                            if (__1p->n_sto__4name != 31)
                                __1st = 0;
                        } else if (__1p->__O1__4expr.tp->base__4node == 97) {
                            Pname __3nn;

                            __3nn = is_cl_obj__4typeFv(__1p->__O1__4expr.tp);
                            if (__3nn) {
                                if (((((struct classdef *)((
                                          (struct classdef *)__3nn->__O1__4expr.tp))))
                                         ->csu__8classdef == 6) &&
                                    strcmp(__0this->string__8classdef, __3nn->__O2__4expr.string))
                                    __1st = 0;
                            }
                        }

                        if (__1in_union == 167) {
                            if ((__1p->__O1__4expr.tp->base__4node == 6) &&
                                ((((struct classdef *)(((struct classdef *)__1p->__O1__4expr.tp))))
                                     ->csu__8classdef == 167)) {

                                Pname __4pu;

                                __4pu = (((struct classdef *)((
                                             (struct classdef *)__1p->__O1__4expr.tp))))
                                            ->mem_list__8classdef;
                                while (__4pu) {
                                    Ptype __5tx;

                                    __5tx = 0;
                                    if (__4pu->base__4node == 123)
                                        __5tx = __4pu->__O3__4expr.tpdef;
                                    else if ((__4pu->__O1__4expr.tp->base__4node == 6) ||
                                             (__4pu->__O1__4expr.tp->base__4node == 13))
                                        __5tx = __4pu->__O1__4expr.tp;
                                    else
                                        --__4pu->lex_level__4name;
                                    if (__5tx) {
                                        __5tx->in_class__4type = __0this;
                                        __dl__FPv((void *)__5tx->nested_sig__4type);
                                        __5tx->nested_sig__4type = make_nested_name__FPCcP8classdef(
                                            __4pu->__O2__4expr.string, __0this);
                                    }
                                    if (!__4pu->__O1__4name.n_list)
                                        break;
                                    __4pu = __4pu->__O1__4name.n_list;
                                }
                                if (__4pu) {
                                    __4pu->__O1__4name.n_list = __1px->__O1__4name.n_list;
                                    __1px = (((struct classdef *)((
                                                 (struct classdef *)__1p->__O1__4expr.tp))))
                                                ->mem_list__8classdef;
                                }
                                (((struct classdef *)(((struct classdef *)__1p->__O1__4expr.tp))))
                                    ->mem_list__8classdef = 0;
                                continue;
                            }
                            if (((__1p->base__4node != 123) &&
                                 (__1p->__O1__4expr.tp->base__4node != 6)) &&
                                (__1p->__O1__4expr.tp->base__4node != 13))
                                --__1p->lex_level__4name;
                        }

                        if (__1p->base__4node == 123) {
                            dcl__4nameFP5tableUc(__1p, __0this->memtbl__8classdef,
                                                 (unsigned char)__1scope);

                            if (__1p->__O1__4expr.tp &&
                                ((((struct basetype *)(((struct basetype *)__1p->__O1__4expr.tp))))
                                     ->base__4node != 119)) {
                                if (__1p->n_dcl_printed__4name == 2)
                                    ;
                                else
                                    dcl_print__4nameFUc(__1p, (unsigned char)0);
                            }
                            continue;
                        }

                        if (__1p->__O1__4expr.tp->base__4node == 108) {
                            int __3ff;
                            Pfct __3f;
                            Pblock __3b;

                            __3ff = 0;
                            __3f = (((struct fct *)(((struct fct *)__1p->__O1__4expr.tp))));
                            __3b = __3f->body__3fct;
                            __3f->body__3fct = 0;
                            if (__3b) {
                                __3f->f_inline__3fct = 1;
                                __3f->f_is_inline__3fct = 1;
                            } else if (__0this->lex_level__4type) {
                                struct ea __0__V166;

                                struct ea __0__V167;

                                error__FiP3locPCcRC2eaN34(
                                    (int)'w', &__1p->where__4name,
                                    (const char *)"non-inlineMF%n in localC %t",
                                    (const struct ea *)(((&__0__V166)->__O1__2ea.p =
                                                             ((const void *)__1p)),
                                                        (&__0__V166)),
                                    (const struct ea *)(((&__0__V167)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V167)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            } else if (((((__0this->csu__8classdef != 167) &&
                                          __0this->string__8classdef) &&
                                         ((__0this->string__8classdef[0]) == '_')) &&
                                        ((__0this->string__8classdef[1]) == '_')) &&
                                       ((__0this->string__8classdef[2]) == 'C')) {
                                struct ea __0__V168;

                                error__FPCcRC2eaN32((const char *)"non-inlineMF%n in unnamedC",
                                                    (const struct ea *)(((&__0__V168)->__O1__2ea.p =
                                                                             ((const void *)__1p)),
                                                                        (&__0__V168)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                            }
                            switch (__1p->n_sto__4name) {
                                unsigned long __2__X226;

                            case 18:
                                __3ff = 1;
                                break;
                            case 31:
                                if (__0this->lex_level__4type) {
                                    struct ea __0__V169;

                                    struct ea __0__V170;

                                    error__FiP3locPCcRC2eaN34(
                                        (int)'w', &__1p->where__4name,
                                        (const char *)"staticMF%n in localC %t",
                                        (const struct ea *)(((&__0__V169)->__O1__2ea.p =
                                                                 ((const void *)__1p)),
                                                            (&__0__V169)),
                                        (const struct ea *)(((&__0__V170)->__O1__2ea.p =
                                                                 ((const void *)__0this)),
                                                            (&__0__V170)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                }
                                __3f->f_static__3fct = 1;
                                __1p->n_sto__4name = 0;
                                break;
                            case 2:
                            case 27:
                            case 14: {
                                struct ea __0__V171;

                                struct ea __0__V172;

                                error__FP3locPCcRC2eaN33(
                                    &__1p->where__4name, (const char *)"M%n cannot be%k",
                                    (const struct ea *)(((&__0__V171)->__O1__2ea.p =
                                                             ((const void *)__1p)),
                                                        (&__0__V171)),
                                    (const struct ea *)((__2__X226 = __1p->n_sto__4name),
                                                        (((((&__0__V172)->__O1__2ea.i = __2__X226),
                                                           0)),
                                                         (&__0__V172))),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                __1p->n_sto__4name = 0;
                            }
                            }

                            if (__3f->f_virtual__3fct)
                                __1real_virts++;
                            if (__3ff && (__3f->fct_base__3fct == 1))
                                continue;

                            {
                                Pname __3m;

                                __3m = dcl__4nameFP5tableUc(__1p, __0this->memtbl__8classdef,
                                                            (unsigned char)__1scope);
                                if ((__3m == 0) || (__3m->__O1__4expr.tp->base__4node != 108))
                                    continue;
                                if (__3m->__O3__4expr.n_initializer) {
                                    __0this->c_abstract__8classdef = __3m;
                                    if (__3m->n_oper__4name == 162) {
                                        struct ea __0__V173;

                                        error__FiPCcRC2eaN33(
                                            (int)'w',
                                            (const char
                                                 *)"please provide an out-of-line definition: %n "
                                                   "{}; which is needed by derived classes",
                                            (const struct ea *)(((&__0__V173)->__O1__2ea.p =
                                                                     ((const void *)__3m)),
                                                                (&__0__V173)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                    }
                                }
                                if (__3ff == 0)
                                    __3m->n_protect__4name = __1protect;
                                if (__3b) {
                                    if ((__3m->__O1__4expr.tp->defined__4type & 01) ||
                                        (((struct fct *)(((struct fct *)__3m->__O1__4expr.tp))))
                                            ->body__3fct) {
                                        struct ea __0__V174;

                                        error__FP3locPCcRC2eaN33(
                                            &__1p->where__4name,
                                            (const char *)"two definitions of%n",
                                            (const struct ea *)(((&__0__V174)->__O1__2ea.p =
                                                                     ((const void *)__3m)),
                                                                (&__0__V174)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                    } else {
                                        (((struct fct *)(((struct fct *)__3m->__O1__4expr.tp))))
                                            ->body__3fct = __3b;
                                        (((struct fct *)(((struct fct *)__3m->__O1__4expr.tp))))
                                            ->def_context__3fct = __3f->def_context__3fct;
                                    }
                                }
                                if ((__3ff == 0) &&
                                    (__1p->__O1__4expr.tp != __3m->__O1__4expr.tp)) {
                                    struct ea __0__V175;

                                    error__FP3locPCcRC2eaN33(
                                        &__1p->where__4name,
                                        (const char *)"%n cannot be redeclared inCD",
                                        (const struct ea *)(((&__0__V175)->__O1__2ea.p =
                                                                 ((const void *)__1p)),
                                                            (&__0__V175)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                            }
                        } else {
                            Eppp = (__1scope ? __1scope : (__1protect ? __1protect : 0));

                            if (__1p->__O3__4expr.n_initializer) {
                                {
                                    struct ea __0__V176;

                                    error__FP3locPCcRC2eaN33(
                                        &__1p->where__4name, (const char *)"Ir forM%n",
                                        (const struct ea *)(((&__0__V176)->__O1__2ea.p =
                                                                 ((const void *)__1p)),
                                                            (&__0__V176)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    __1p->__O3__4expr.n_initializer = 0;
                                }
                            }

                            if (__1p->__O1__4expr.tp->base__4node == 76) {
                                {
                                    {
                                        Plist __4gl;

                                        __4gl =
                                            (((struct gen *)(((struct gen *)__1p->__O1__4expr.tp))))
                                                ->fct_list__3gen;

                                        for (; __4gl; __4gl = __4gl->l__9name_list) {
                                            Pname __5nn;
                                            Pfct __5ff;

                                            __5nn = __4gl->f__9name_list;
                                            __5ff = (((struct fct *)((
                                                (struct fct *)__5nn->__O1__4expr.tp))));
                                            if (__5ff->f_virtual__3fct)
                                                __1real_virts++;
                                        }
                                    }
                                }
                            }

                            {
                                TOK __3is_friend;

                                __3is_friend = __1p->n_sto__4name;
                                if ((__1protect && (__1p->__O1__4expr.tp->base__4node == 119)) &&
                                    ((((struct classdef *)((
                                          (struct classdef *)(((struct basetype *)((
                                                                  (struct basetype *)
                                                                      __1p->__O1__4expr.tp))))
                                              ->b_name__8basetype->__O1__4expr.tp))))
                                         ->csu__8classdef == 167))
                                    __1p->n_protect__4name = __1protect;

                                {
                                    Pname __3m;

                                    __3m = dcl__4nameFP5tableUc(__1p, __0this->memtbl__8classdef,
                                                                (unsigned char)__1scope);
                                    Eppp = 0;
                                    if (__3m == 0)
                                        continue;

                                    __3m->n_protect__4name = __1protect;

                                    if (__3m->n_stclass__4name == 31) {
                                        if (__1in_union && (__3is_friend != 18)) {
                                            struct ea __0__V177;

                                            error__FP3locPCcRC2eaN33(
                                                &__3m->where__4name,
                                                (const char *)"staticM%n in union",
                                                (const struct ea *)(((&__0__V177)->__O1__2ea.p =
                                                                         ((const void *)__3m)),
                                                                    (&__0__V177)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                                        }
                                        if (__3is_friend != 18) {
                                            if (__0this->lex_level__4type) {
                                                struct ea __0__V178;

                                                struct ea __0__V179;

                                                error__FP3locPCcRC2eaN33(
                                                    &__3m->where__4name,
                                                    (const char *)"staticM%n in localC %t",
                                                    (const struct ea *)(((&__0__V178)->__O1__2ea.p =
                                                                             ((const void *)__3m)),
                                                                        (&__0__V178)),
                                                    (const struct ea *)(((&__0__V179)->__O1__2ea.p =
                                                                             ((const void *)
                                                                                  __0this)),
                                                                        (&__0__V179)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                            }
                                        }
                                        __3m->n_sto__4name = 14;
                                        if (__1tbl == gtbl)
                                            stat_mem_list = __ct__9name_listFP4nameP9name_list(
                                                (struct name_list *)0, __3m, stat_mem_list);
                                        if (__3m->__O3__4expr.n_initializer) {
                                            struct ea __0__V180;

                                            error__FiPCcRC2eaN33(
                                                (int)'s', (const char *)"staticM%nWIr",
                                                (const struct ea *)(((&__0__V180)->__O1__2ea.p =
                                                                         ((const void *)__3m)),
                                                                    (&__0__V180)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                                        }
                                    }

                                    if (__1in_union) {
                                        if (__1usz < byte_offset)
                                            __1usz = byte_offset;
                                        byte_offset = 0;
                                        if (__1in_union == 167)
                                            __3m->n_offset__4name += __1byte_old;
                                    }
                                }
                            }
                        }
                    }

                    if (__1st && (__0this->csu__8classdef == 6))
                        __0this->csu__8classdef = 32;
                    if ((__1st == 0) && (__0this->csu__8classdef == 32))
                        __0this->csu__8classdef = 6;

                    if (__1in_union)
                        byte_offset = __1usz;

                    {
                        Pname __1ct;
                        Pname __1dt;

                        int __1i;

                        int __1omex;

                        __1ct = (__0this->c_ctor__8classdef);
                        __1dt = (__0this->c_dtor__8classdef);

                        __1omex = mex;

                        mex = 0;
                        {
                            Pname __1on;
                            Pname __1onv;
                            Pname __1od;
                            Pname __1odv;

                            __1on = has_oper__8classdefFUc(__0this, (unsigned char)23);
                            __1onv = has_oper__8classdefFUc(__0this, (unsigned char)213);
                            __1od = has_oper__8classdefFUc(__0this, (unsigned char)9);
                            __1odv = has_oper__8classdefFUc(__0this, (unsigned char)212);
                            mex = __1omex;

                            if ((__1dt && (__1ct == 0)) &&
                                ((((struct fct *)(((struct fct *)__1dt->__O1__4expr.tp))))
                                     ->f_virtual__3fct == 0)) {
                                struct ea __0__V181;

                                struct ea __0__V182;

                                error__FiPCcRC2eaN33(
                                    (int)'w', (const char *)"%t has%n but noK",
                                    (const struct ea *)(((&__0__V181)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V181)),
                                    (const struct ea *)(((&__0__V182)->__O1__2ea.p =
                                                             ((const void *)__1dt)),
                                                        (&__0__V182)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            if (__1on && (__1od == 0)) {
                                struct ea __0__V183;

                                struct ea __0__V184;

                                error__FiPCcRC2eaN33(
                                    (int)'w', (const char *)"%t has%n but no operator delete()",
                                    (const struct ea *)(((&__0__V183)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V183)),
                                    (const struct ea *)(((&__0__V184)->__O1__2ea.p =
                                                             ((const void *)__1on)),
                                                        (&__0__V184)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            if (__1od && (__1on == 0)) {
                                struct ea __0__V185;

                                struct ea __0__V186;

                                error__FiPCcRC2eaN33(
                                    (int)'w', (const char *)"%t has%n but no operator new()",
                                    (const struct ea *)(((&__0__V185)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V185)),
                                    (const struct ea *)(((&__0__V186)->__O1__2ea.p =
                                                             ((const void *)__1od)),
                                                        (&__0__V186)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            if (__1onv && (__1odv == 0)) {
                                struct ea __0__V187;

                                struct ea __0__V188;

                                error__FiPCcRC2eaN33(
                                    (int)'w', (const char *)"%t has%n but no operator delete[]()",
                                    (const struct ea *)(((&__0__V187)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V187)),
                                    (const struct ea *)(((&__0__V188)->__O1__2ea.p =
                                                             ((const void *)__1on)),
                                                        (&__0__V188)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            if (__1odv && (__1onv == 0)) {
                                struct ea __0__V189;

                                struct ea __0__V190;

                                error__FiPCcRC2eaN33(
                                    (int)'w', (const char *)"%t has%n but no operator new[]()",
                                    (const struct ea *)(((&__0__V189)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V189)),
                                    (const struct ea *)(((&__0__V190)->__O1__2ea.p =
                                                             ((const void *)__1od)),
                                                        (&__0__V190)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            if ((((__1dt == 0) && __1od) && __1od) &&
                                (__1od->__O4__4expr.n_table == __0this->memtbl__8classdef))
                                __1make_dtor = 1;

                            {
                                {
                                    Pname __1m;

                                    struct table *__0__X227;

                                    int __2__X228;

                                    struct table *__0__X254;

                                    int __2__X255;

                                    __1m = ((__0__X254 = __0this->memtbl__8classdef),
                                            ((__2__X255 = (__1i = 1)),
                                             ((((__2__X255 <= 0) ||
                                                (__0__X254->free_slot__5table <= __2__X255))
                                                   ? (((struct name *)0))
                                                   : (__0__X254->entries__5table[__2__X255])))));

                                    for (; __1m;
                                         __1m = (__1m->n_tbl_list__4name
                                                     ? __1m->n_tbl_list__4name
                                                     : ((__0__X227 = __0this->memtbl__8classdef),
                                                        ((__2__X228 = (++__1i)),
                                                         ((((__2__X228 <= 0) ||
                                                            (__0__X227->free_slot__5table <=
                                                             __2__X228))
                                                               ? (((struct name *)0))
                                                               : (__0__X227->entries__5table
                                                                      [__2__X228]))))))) {
                                        if (__1m->base__4node == 123)
                                            continue;

                                        {
                                            Ptype __2t;

                                            __2t = __1m->__O1__4expr.tp;

                                            if (__2t == 0)
                                                continue;

                                            switch (__2t->base__4node) {
                                            default:
                                                if (((__1ct == 0) &&
                                                     (__1m->n_stclass__4name != 13)) &&
                                                    (__1m->n_stclass__4name != 31)) {
                                                    if (is_ref__4typeFv(__2t)) {
                                                        struct ea __0__V191;

                                                        struct ea __0__V192;

                                                        error__FPCcRC2eaN32(
                                                            (const char *)"R%n inC%tWoutK",
                                                            (const struct ea
                                                                 *)(((&__0__V191)->__O1__2ea.p =
                                                                         ((const void *)__1m)),
                                                                    (&__0__V191)),
                                                            (const struct ea
                                                                 *)(((&__0__V192)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V192)),
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0);
                                                    }
                                                    if ((tconst__4typeFv(__2t) &&
                                                         (vec_const == 0)) &&
                                                        (__1m->n_evaluated__4name == 0)) {
                                                        struct ea __0__V193;

                                                        struct ea __0__V194;

                                                        error__FPCcRC2eaN32(
                                                            (const char *)"const%n inC%tWoutK",
                                                            (const struct ea
                                                                 *)(((&__0__V193)->__O1__2ea.p =
                                                                         ((const void *)__1m)),
                                                                    (&__0__V193)),
                                                            (const struct ea
                                                                 *)(((&__0__V194)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V194)),
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0);
                                                    }
                                                }

                                            case 110:
                                                break;

                                            case 108:
                                            case 76:
                                            case 6:
                                            case 13:
                                                continue;
                                            }

                                            {
                                                Pname __2cn;

                                                __2cn = is_cl_obj__4typeFv(__2t);
                                                if (__2cn == 0)
                                                    __2cn = cl_obj_vec;
                                                if (__2cn == 0)
                                                    continue;

                                                {
                                                    Pclass __2cl;

                                                    __2cl = (((struct classdef *)((
                                                        (struct classdef *)
                                                            __2cn->__O1__4expr.tp))));
                                                    __0this->c_xref__8classdef |=
                                                        __2cl->c_xref__8classdef;

                                                    if ((__2cl->c_ctor__8classdef)) {
                                                        if (__1m->n_stclass__4name == 31)
                                                            ;
                                                        else if (__1in_union) {
                                                            const void *__2__X229;

                                                            if (strncmp((const char *)"__C",
                                                                        __0this->string__8classdef,
                                                                        (unsigned long)3) == 0) {
                                                                struct ea __0__V195;

                                                                struct ea __0__V196;

                                                                error__FPCcRC2eaN32(
                                                                    (const char
                                                                         *)"M %s ofC%tWK in union",
                                                                    (const struct ea
                                                                         *)((__2__X229 =
                                                                                 (const void *)__1m
                                                                                     ->__O2__4expr
                                                                                     .string),
                                                                            (((&__0__V195)
                                                                                  ->__O1__2ea.p =
                                                                                  __2__X229),
                                                                             (&__0__V195))),
                                                                    (const struct ea
                                                                         *)(((&__0__V196)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __2cl)),
                                                                            (&__0__V196)),
                                                                    (const struct ea *)ea0,
                                                                    (const struct ea *)ea0);
                                                            } else {
                                                                struct ea __0__V197;

                                                                struct ea __0__V198;

                                                                error__FPCcRC2eaN32(
                                                                    (const char
                                                                         *)"M%n ofC%tWK in union",
                                                                    (const struct ea
                                                                         *)(((&__0__V197)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __1m)),
                                                                            (&__0__V197)),
                                                                    (const struct ea
                                                                         *)(((&__0__V198)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __2cl)),
                                                                            (&__0__V198)),
                                                                    (const struct ea *)ea0,
                                                                    (const struct ea *)ea0);
                                                            }
                                                        } else if (__1ct == 0) {
                                                            if ((__1make_ctor == 0) &&
                                                                (has_ictor__8classdefFv(__2cl) ==
                                                                 0)) {
                                                                struct ea __0__V199;

                                                                error__FPCcRC2eaN32(
                                                                    (const char
                                                                         *)"%t needs aK; it has "
                                                                           "aMWK requiringAs",
                                                                    (const struct ea
                                                                         *)(((&__0__V199)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __0this)),
                                                                            (&__0__V199)),
                                                                    (const struct ea *)ea0,
                                                                    (const struct ea *)ea0,
                                                                    (const struct ea *)ea0);
                                                            }
                                                            __1make_ctor = 1;
                                                        }
                                                    }
                                                    if (__1in_union &&
                                                        (__0this->c_xref__8classdef & 4)) {
                                                        struct ea __0__V200;

                                                        struct ea __0__V201;

                                                        error__FPCcRC2eaN32(
                                                            (const char *)"M%n ofC%tW assignment "
                                                                          "operator in union",
                                                            (const struct ea
                                                                 *)(((&__0__V200)->__O1__2ea.p =
                                                                         ((const void *)__1m)),
                                                                    (&__0__V200)),
                                                            (const struct ea
                                                                 *)(((&__0__V201)->__O1__2ea.p =
                                                                         ((const void *)__2cl)),
                                                                    (&__0__V201)),
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0);
                                                    }
                                                    if ((__2cl->c_dtor__8classdef)) {
                                                        if (__1m->n_stclass__4name == 31)
                                                            ;
                                                        else if (__1in_union) {
                                                            const void *__2__X230;

                                                            if (strncmp((const char *)"__C",
                                                                        __0this->string__8classdef,
                                                                        (unsigned long)3) == 0) {
                                                                struct ea __0__V202;

                                                                struct ea __0__V203;

                                                                error__FPCcRC2eaN32(
                                                                    (const char
                                                                         *)"M %s ofC%tW destructor "
                                                                           "in union",
                                                                    (const struct ea
                                                                         *)((__2__X230 =
                                                                                 (const void *)__1m
                                                                                     ->__O2__4expr
                                                                                     .string),
                                                                            (((&__0__V202)
                                                                                  ->__O1__2ea.p =
                                                                                  __2__X230),
                                                                             (&__0__V202))),
                                                                    (const struct ea
                                                                         *)(((&__0__V203)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __2cl)),
                                                                            (&__0__V203)),
                                                                    (const struct ea *)ea0,
                                                                    (const struct ea *)ea0);
                                                            } else {
                                                                struct ea __0__V204;

                                                                struct ea __0__V205;

                                                                error__FPCcRC2eaN32(
                                                                    (const char
                                                                         *)"M%n ofC%tW destructor "
                                                                           "in union",
                                                                    (const struct ea
                                                                         *)(((&__0__V204)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __1m)),
                                                                            (&__0__V204)),
                                                                    (const struct ea
                                                                         *)(((&__0__V205)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __2cl)),
                                                                            (&__0__V205)),
                                                                    (const struct ea *)ea0,
                                                                    (const struct ea *)ea0);
                                                            }
                                                        } else if (__1dt == 0)
                                                            __1make_dtor = 1;
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    if (((__0this->c_dtor__8classdef) == 0) &&
                                        (__1make_dtor == 0)) {
                                        Pclass __2bcl;

                                        __2bcl = 0;
                                        {
                                            {
                                                Pbcl __2b;

                                                __2b = __0this->baselist__8classdef;

                                                for (; __2b; __2b = __2b->next__6basecl) {
                                                    switch (__2b->base__4node) {
                                                        struct classdef *__0__X232;

                                                    case 85:
                                                        if (__2bcl == 0) {
                                                            Pname __5d;

                                                            struct classdef *__0__X231;

                                                            __5d = ((__0__X231 =
                                                                         __2b->bclass__6basecl),
                                                                    (__0__X231->c_dtor__8classdef));
                                                            if (__5d == 0)
                                                                break;
                                                        }

                                                        __1make_dtor = 1;
                                                        goto zbzb;
                                                    case 77:
                                                        if (((__0__X232 = __2b->bclass__6basecl),
                                                             (__0__X232->c_dtor__8classdef)))
                                                            __1make_dtor = 1;
                                                        goto zbzb;
                                                    }
                                                }
                                                if (__2bcl)
                                                    __0this->c_dtor__8classdef =
                                                        (__2bcl->c_dtor__8classdef);
                                            zbzb:;
                                            }
                                        }
                                    }

                                    if (__1make_dtor && (__1dt == 0)) {
                                        Pname __2n;
                                        Pfct __2f;

                                        register struct block *__0__X233;

                                        struct loc __2__X234;

                                        struct loc __2__X235;

                                        __2n = __ct__4nameFPCc((struct name *)0,
                                                               __0this->string__8classdef);
                                        __2f = __ct__3fctFP4typeP4nameUc(
                                            (struct fct *)0, (struct type *)defa_type,
                                            (struct name *)0, (unsigned char)1);
                                        __2f->f_inline__3fct = 1;
                                        __2f->f_is_inline__3fct = 1;
                                        __2n->__O1__4expr.tp = (struct type *)__2f;
                                        __2n->n_oper__4name = 162;
                                        __1dt = dcl__4nameFP5tableUc(
                                            __2n, __0this->memtbl__8classdef, (unsigned char)25);
                                        ((__2n
                                              ? (((void)(__2n
                                                             ? (((void)((((((struct expr *)__2n))
                                                                              ? (((void)((((struct
                                                                                            expr *)
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
                                        (((struct fct *)(((struct fct *)__1dt->__O1__4expr.tp))))
                                            ->body__3fct =
                                            ((__0__X233 = 0),
                                             ((__2__X234 = curloc),
                                              ((__2__X235 = noloc),
                                               (((__0__X233 ||
                                                  (__0__X233 = (struct block *)__nw__4stmtSFUl(
                                                       (size_t)(sizeof(struct block)))))
                                                     ? (((void)((__0__X233 = (struct block *)
                                                                     __ct__4stmtFUc3locP4stmt(
                                                                         ((struct stmt *)__0__X233),
                                                                         (unsigned char)116,
                                                                         __2__X234,
                                                                         ((struct stmt *)0))),
                                                                ((__0__X233->__O1__4stmt.d =
                                                                      ((struct name *)0)),
                                                                 (__0__X233->__O3__4stmt.where2 =
                                                                      __2__X235)))))
                                                     : (((void)0))),
                                                __0__X233))));
                                        __1dt = (__0this->c_dtor__8classdef);
                                    }

                                    if (__0this->virt_count__8classdef &&
                                        (find_vptr__FP8classdef(__0this) == 0)) {
                                        Pname __2vp;

                                        __2vp = __ct__4nameFPCc((struct name *)0,
                                                                (const char *)"__vptr");
                                        __2vp->__O1__4expr.tp = Pvptr_type;
                                        ((void)dcl__4nameFP5tableUc(
                                            __2vp, __0this->memtbl__8classdef, (unsigned char)0));
                                        ((__2vp
                                              ? (((void)(__2vp
                                                             ? (((void)((((((struct expr *)__2vp))
                                                                              ? (((void)((((struct
                                                                                            expr *)
                                                                                               __2vp))
                                                                                             ? (((void)(((
                                                                                                   void)0))))
                                                                                             : (((void)0)))))
                                                                              : (((void)0)))),
                                                                        (((void)__dl__4nameSFPvUl(
                                                                            (void *)__2vp,
                                                                            (size_t)(sizeof(
                                                                                struct name))))))))
                                                             : (((void)0)))))
                                              : (((void)0))));
                                        __0this->c_xref__8classdef |= 1;
                                    } else {
                                        if (bit_offset) {
                                            byte_offset += ((bit_offset / BI_IN_BYTE) +
                                                            ((bit_offset % BI_IN_BYTE) ? 1 : 0));
                                            bit_offset = 0;
                                        }
                                    }

                                    {
                                        Pbcl __1b;

                                        __1b = __0this->baselist__8classdef;
                                        for (; __1b; __1b = __1b->next__6basecl) {
                                            if (__1b->base__4node != 77)
                                                continue;
                                            {
                                                Pclass __2bcl;

                                                __2bcl = __1b->bclass__6basecl;

                                                {
                                                    {
                                                        Pbcl __2bb;

                                                        __2bb = __0this->baselist__8classdef;

                                                        for (; __2bb; __2bb = __2bb->next__6basecl)
                                                            if (__2bb->base__4node == 85) {
                                                                {
                                                                    {
                                                                        Pbcl __3l;

                                                                        struct classdef *__1__X236;

                                                                        struct classdef *__1__X237;

                                                                        __3l =
                                                                            __2bb->bclass__6basecl
                                                                                ->baselist__8classdef;

                                                                        for (
                                                                            ; __3l;
                                                                            __3l =
                                                                                __3l->next__6basecl)
                                                                            if ((__3l->base__4node ==
                                                                                 77) &&
                                                                                ((__1__X236 =
                                                                                      __3l->bclass__6basecl),
                                                                                 ((__1__X237 =
                                                                                       __2bcl),
                                                                                  (((__1__X236 ==
                                                                                     __1__X237)
                                                                                        ? 1
                                                                                        : ((__1__X236 &&
                                                                                            __1__X237)
                                                                                               ? (((int)same_class__8classdefFP8classdefi(
                                                                                                     __1__X236,
                                                                                                     __1__X237,
                                                                                                     0)))
                                                                                               : 0))))))
                                                                                goto eee;
                                                                    }
                                                                }
                                                            }

                                                        {
                                                            if ((((int)__0this
                                                                      ->obj_align__8classdef)) <
                                                                AL_WPTR)
                                                                __0this->obj_align__8classdef =
                                                                    AL_WPTR;
                                                            if (max_align < AL_WPTR)
                                                                max_align = AL_WPTR;
                                                            {
                                                                int __3waste;

                                                                __3waste = (byte_offset % AL_WPTR);
                                                                if (__3waste)
                                                                    byte_offset +=
                                                                        (AL_WPTR - __3waste);
                                                                __1b->ptr_offset__6basecl =
                                                                    (byte_offset + 1);
                                                                byte_offset += SZ_WPTR;
                                                            }
                                                        }
                                                    eee:;
                                                    }
                                                }
                                            }
                                        }

                                        __0this->real_size__8classdef = byte_offset;

                                        for (__1b = __0this->baselist__8classdef; __1b;
                                             __1b = __1b->next__6basecl) {
                                            if (__1b->base__4node != 77)
                                                continue;
                                            {
                                                Pclass __2bcl;

                                                __2bcl = __1b->bclass__6basecl;

                                                link_compat_hack = 0;
                                                if (__1b->obj_offset__6basecl =
                                                        has_allocated_base__8classdefFP8classdefUc(
                                                            __0this, __2bcl, (unsigned char)0))
                                                    continue;

                                                {
                                                    int __2ba;

                                                    __2ba = align__4typeFv((struct type *)__2bcl);
                                                    if ((((int)__0this->obj_align__8classdef)) <
                                                        __2ba)
                                                        __0this->obj_align__8classdef = __2ba;
                                                    if (max_align < __2ba)
                                                        max_align = __2ba;
                                                    {
                                                        int __2waste;

                                                        __2waste = (byte_offset % __2ba);
                                                        if (__2waste)
                                                            byte_offset += (__2ba - __2waste);
                                                        __1b->obj_offset__6basecl = byte_offset;
                                                        __1b->allocated__6basecl =
                                                            (1 + link_compat_hack);
                                                        link_compat_hack = 0;

                                                        byte_offset += tsizeof__4typeFi(
                                                            (struct type *)__2bcl, 0);
                                                    }
                                                }
                                            }
                                        }

                                        if (byte_offset == 0) {
                                            Pname __2c;

                                            __2c = __ct__4nameFPCc(
                                                (struct name *)0,
                                                (const char *)make_name__FUc((unsigned char)'W'));
                                            __2c->where__4name = __1cname->where__4name;
                                            __2c->__O1__4expr.tp = (struct type *)char_type;
                                            ((void)dcl__4nameFP5tableUc(__2c,
                                                                        __0this->memtbl__8classdef,
                                                                        (unsigned char)0));
                                            __0this->real_size__8classdef = (byte_offset = 1);
                                        }
                                        if (byte_offset < SZ_STRUCT)
                                            byte_offset = SZ_STRUCT;
                                        {
                                            int __1waste;

                                            __1waste = (byte_offset % max_align);

                                            if (__1waste)
                                                byte_offset += (max_align - __1waste);
                                            __0this->obj_size__8classdef = byte_offset;
                                            __0this->obj_align__8classdef = max_align;

                                            if (all_virt__8classdefFP8classdefPCciUc(
                                                    __0this, __0this, (const char *)0, 1,
                                                    (unsigned char)0)) {
                                                if ((__0this->c_ctor__8classdef) == 0)
                                                    __1make_ctor = 1;
                                            } else if (__0this->has_vvtab__8classdef)
                                                error__FPCc((const char *)"virtualB: conflicting "
                                                                          "vtable initialization");

                                            {
                                                Pname __1hito;

                                                struct table *__0__X243;

                                                int __2__X244;

                                                struct table *__0__X245;

                                                int __2__X246;

                                                struct table *__0__X247;

                                                int __2__X248;

                                                struct table *__0__X249;

                                                int __2__X250;

                                                struct dcl_context *__0__X251;

                                                struct dcl_context *__0__X252;

                                                __1hito = (__0this->c_itor__8classdef);

                                                if (__1hito)
                                                    __0this->c_xref__8classdef |= 2;

                                                if ((__1hito == 0) &&
                                                    (__0this->c_xref__8classdef & 11)) {
                                                    __1hito = make_itor__8classdefFi(__0this, 0);

                                                    if (__0this->baselist__8classdef) {
                                                        int __3mc;

                                                        __3mc = 1;
                                                        {
                                                            {
                                                                Pbcl __3b;

                                                                __3b = __0this->baselist__8classdef;

                                                                for (; __3b;
                                                                     __3b = __3b->next__6basecl) {
                                                                    struct classdef *__0__X238;

                                                                    if (((__0__X238 =
                                                                              __3b->bclass__6basecl),
                                                                         (__0__X238
                                                                              ->c_ctor__8classdef)) &&
                                                                        (has_ictor__8classdefFv(
                                                                             __3b->bclass__6basecl) ==
                                                                         0))
                                                                        __3mc = 0;
                                                                }
                                                                __1make_ctor = __3mc;
                                                            }
                                                        }
                                                    } else
                                                        __1make_ctor = 1;
                                                }

                                                if ((__0this->c_ctor__8classdef == 0) &&
                                                    (__1make_ctor == 0)) {
                                                    Pname __2btor;
                                                    Pclass __2bc;

                                                    __2btor = 0;
                                                    __2bc = 0;
                                                    {
                                                        {
                                                            Pbcl __2b;

                                                            __2b = __0this->baselist__8classdef;

                                                            for (; __2b;
                                                                 __2b = __2b->next__6basecl) {
                                                                switch (__2b->base__4node) {
                                                                case 85: {
                                                                    Pname __5c;

                                                                    struct classdef *__0__X239;

                                                                    __5c =
                                                                        ((__0__X239 =
                                                                              __2b->bclass__6basecl),
                                                                         (__0__X239
                                                                              ->c_ctor__8classdef));
                                                                    if (__5c == 0)
                                                                        break;
                                                                    if ((__5c->n_scope__4name ==
                                                                         25) &&
                                                                        (__2b ==
                                                                         __0this
                                                                             ->baselist__8classdef)) {
                                                                        __2bc =
                                                                            __2b->bclass__6basecl;
                                                                        __2btor =
                                                                            has_ictor__8classdefFv(
                                                                                __2bc);
                                                                        break;
                                                                    }
                                                                }

                                                                case 77:
                                                                    __1make_ctor = 1;
                                                                    goto zaza;
                                                                }
                                                            }

                                                            if (__2bc) {
                                                                if (__2btor)
                                                                    __1make_ctor = 1;
                                                                else {
                                                                    struct ea __0__V206;

                                                                    struct ea __0__V207;

                                                                    error__FPCcRC2eaN32(
                                                                        (const char
                                                                             *)"K needed for%t, "
                                                                               "BC%t hasK",
                                                                        (const struct ea
                                                                             *)(((&__0__V206)
                                                                                     ->__O1__2ea.p =
                                                                                     ((const void *)
                                                                                          __0this)),
                                                                                (&__0__V206)),
                                                                        (const struct ea
                                                                             *)(((&__0__V207)
                                                                                     ->__O1__2ea.p =
                                                                                     ((const void *)
                                                                                          __2bc)),
                                                                                (&__0__V207)),
                                                                        (const struct ea *)ea0,
                                                                        (const struct ea *)ea0);
                                                                }
                                                            }
                                                        zaza:;
                                                        }
                                                    }
                                                }

                                                if (__1make_ctor && (__1ct == 0)) {
                                                    Pname __2n;
                                                    Pfct __2f;

                                                    register struct block *__0__X240;

                                                    struct loc __2__X241;

                                                    struct loc __2__X242;

                                                    __2n =
                                                        __ct__4nameFPCc((struct name *)0,
                                                                        __0this->string__8classdef);
                                                    __2f = __ct__3fctFP4typeP4nameUc(
                                                        (struct fct *)0, (struct type *)defa_type,
                                                        (struct name *)0, (unsigned char)1);
                                                    __2f->f_inline__3fct = 1;
                                                    __2f->f_is_inline__3fct = 1;
                                                    __2n->__O1__4expr.tp = (struct type *)__2f;
                                                    __2n->n_oper__4name = 123;
                                                    __1ct = dcl__4nameFP5tableUc(
                                                        __2n, __0this->memtbl__8classdef,
                                                        (unsigned char)25);
                                                    ((__2n
                                                          ? (((void)(__2n
                                                                         ? (((void)((((((struct expr
                                                                                             *)
                                                                                            __2n))
                                                                                          ? (((void)((((struct
                                                                                                        expr
                                                                                                            *)
                                                                                                           __2n))
                                                                                                         ? (((void)(((
                                                                                                               void)0))))
                                                                                                         : (((void)0)))))
                                                                                          : (((void)0)))),
                                                                                    (((void)__dl__4nameSFPvUl(
                                                                                        (void *)
                                                                                            __2n,
                                                                                        (size_t)(sizeof(
                                                                                            struct
                                                                                            name))))))))
                                                                         : (((void)0)))))
                                                          : (((void)0))));
                                                    (((struct fct *)((
                                                         (struct fct *)__1ct->__O1__4expr.tp))))
                                                        ->body__3fct =
                                                        ((__0__X240 = 0),
                                                         ((__2__X241 = curloc),
                                                          ((__2__X242 = noloc),
                                                           (((__0__X240 ||
                                                              (__0__X240 = (struct block *)
                                                                   __nw__4stmtSFUl((size_t)(sizeof(
                                                                       struct block)))))
                                                                 ? (((void)((__0__X240 = (struct
                                                                                          block *)
                                                                                 __ct__4stmtFUc3locP4stmt(
                                                                                     ((struct stmt
                                                                                           *)
                                                                                          __0__X240),
                                                                                     (unsigned char)116,
                                                                                     __2__X241,
                                                                                     ((struct stmt
                                                                                           *)0))),
                                                                            ((__0__X240->__O1__4stmt
                                                                                  .d = ((
                                                                                  struct name *)0)),
                                                                             (__0__X240->__O3__4stmt
                                                                                  .where2 =
                                                                                  __2__X242)))))
                                                                 : (((void)0))),
                                                            __0__X240))));
                                                }

                                                if ((((pt_opt && (!__0this->nested_sig__4type)) &&
                                                      (!__0this->local_sig__4type)) &&
                                                     (!is_probably_temp__FPCc(
                                                         __0this->string__8classdef))) &&
                                                    (!tempdcl))
                                                    if (__0this->csu__8classdef == 36)
                                                        fprintf(pt_file, (const char *)"u %s %s\n",
                                                                __0this->string__8classdef,
                                                                curr_filename__Fv());
                                                    else if (__0this->csu__8classdef == 32) {
                                                        fprintf(pt_file, (const char *)"s %s %s\n",
                                                                __0this->string__8classdef,
                                                                curr_filename__Fv());
                                                    } else if (__0this->csu__8classdef == 6)
                                                        fprintf(pt_file, (const char *)"c %s %s\n",
                                                                __0this->string__8classdef,
                                                                curr_filename__Fv());

                                                __0this->defined__4type |= 01;
                                                typedef_checkall__FP8classdef(__0this);

                                                for (
                                                    __1p =
                                                        ((__0__X243 = __0this->memtbl__8classdef),
                                                         ((__2__X244 = (__1i = 1)),
                                                          ((((__2__X244 <= 0) ||
                                                             (__0__X243->free_slot__5table <=
                                                              __2__X244))
                                                                ? (((struct name *)0))
                                                                : (__0__X243->entries__5table
                                                                       [__2__X244])))));
                                                    __1p;
                                                    __1p =
                                                        (__1p->n_tbl_list__4name
                                                             ? __1p->n_tbl_list__4name
                                                             : ((__0__X245 =
                                                                     __0this->memtbl__8classdef),
                                                                ((__2__X246 = (++__1i)),
                                                                 ((((__2__X246 <= 0) ||
                                                                    (__0__X245->free_slot__5table <=
                                                                     __2__X246))
                                                                       ? (((struct name *)0))
                                                                       : (__0__X245->entries__5table
                                                                              [__2__X246]))))))) {

                                                    if (__1p->base__4node == 123)
                                                        continue;
                                                    {
                                                        Pfct __2f;

                                                        __2f = (((struct fct *)((
                                                            (struct fct *)__1p->__O1__4expr.tp))));
                                                        if (__2f == 0)
                                                            continue;

                                                        switch (__2f->base__4node) {
                                                        case 108:
                                                            if (__1hito && __2f->argtype__3fct)
                                                                fix_args__FP3fctP8classdef(__2f,
                                                                                           __0this);
                                                            if (__1p->n_oper__4name == 161)
                                                                __2f->s_returns__3fct =
                                                                    __0this->this_type__8classdef;
                                                            if (__2f->body__3fct)
                                                                __1p->n_sto__4name = 31;
                                                            break;
                                                        case 76: {
                                                            Pgen __4g;

                                                            __4g = (((struct gen *)((
                                                                (struct gen *)__2f))));
                                                            {
                                                                {
                                                                    Plist __4gl;

                                                                    __4gl = __4g->fct_list__3gen;

                                                                    for (; __4gl;
                                                                         __4gl =
                                                                             __4gl->l__9name_list) {
                                                                        Pname __5n;
                                                                        Pfct __5f;

                                                                        __5n = __4gl->f__9name_list;
                                                                        __5f = (((struct fct *)((
                                                                            (struct fct *)
                                                                                __5n->__O1__4expr
                                                                                    .tp))));

                                                                        if (__1hito &&
                                                                            __5f->argtype__3fct)
                                                                            fix_args__FP3fctP8classdef(
                                                                                __5f, __0this);
                                                                        if (__5n->n_oper__4name ==
                                                                            161)
                                                                            __5f->s_returns__3fct =
                                                                                __0this
                                                                                    ->this_type__8classdef;
                                                                        if (__5f->body__3fct)
                                                                            __5n->n_sto__4name = 31;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        }
                                                    }
                                                }

                                                for (
                                                    __1p =
                                                        ((__0__X247 = __0this->memtbl__8classdef),
                                                         ((__2__X248 = (__1i = 1)),
                                                          ((((__2__X248 <= 0) ||
                                                             (__0__X247->free_slot__5table <=
                                                              __2__X248))
                                                                ? (((struct name *)0))
                                                                : (__0__X247->entries__5table
                                                                       [__2__X248])))));
                                                    __1p;
                                                    __1p =
                                                        (__1p->n_tbl_list__4name
                                                             ? __1p->n_tbl_list__4name
                                                             : ((__0__X249 =
                                                                     __0this->memtbl__8classdef),
                                                                ((__2__X250 = (++__1i)),
                                                                 ((((__2__X250 <= 0) ||
                                                                    (__0__X249->free_slot__5table <=
                                                                     __2__X250))
                                                                       ? (((struct name *)0))
                                                                       : (__0__X249->entries__5table
                                                                              [__2__X250]))))))) {

                                                    if (__1p->base__4node == 123)
                                                        continue;
                                                    {
                                                        Pfct __2f;

                                                        __2f = (((struct fct *)((
                                                            (struct fct *)__1p->__O1__4expr.tp))));
                                                        if (__2f == 0)
                                                            continue;

                                                        switch (__2f->base__4node) {
                                                        case 108:
                                                            if (__2f->body__3fct) {
                                                                dcl__3fctFP4name(__2f, __1p);
                                                                simpl__4nameFv(__1p);
                                                            }
                                                            break;
                                                        case 76: {
                                                            Pgen __4g;

                                                            __4g = (((struct gen *)((
                                                                (struct gen *)__2f))));
                                                            {
                                                                {
                                                                    Plist __4gl;

                                                                    __4gl = __4g->fct_list__3gen;

                                                                    for (; __4gl;
                                                                         __4gl =
                                                                             __4gl->l__9name_list) {
                                                                        Pname __5n;
                                                                        Pfct __5f;

                                                                        __5n = __4gl->f__9name_list;
                                                                        __5f = (((struct fct *)((
                                                                            (struct fct *)
                                                                                __5n->__O1__4expr
                                                                                    .tp))));

                                                                        if (__5f->body__3fct) {
                                                                            dcl__3fctFP4name(__5f,
                                                                                             __5n);
                                                                            simpl__4nameFv(__5n);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        }
                                                    }
                                                }

                                                byte_offset = __1byte_old;
                                                bit_offset = __1bit_old;
                                                max_align = __1max_old;

                                                (((cc--), (((void)0))));

                                                ((((cc++),
                                                   (((cc >= ccvec_end)
                                                         ? error__FiPCc(
                                                               (int)'i',
                                                               (const char
                                                                    *)"ccvec buffer overflow")
                                                         : 0),
                                                    (((*cc)) = (*(cc - 1))))),
                                                  (((void)0))));
                                                cc->cot__11dcl_context = 0;

                                                cc->not4__11dcl_context = 0;

                                                cc->tot__11dcl_context = 0;

                                                cc->c_this__11dcl_context = 0;
                                                {
                                                    Plist __1fl;

                                                    struct dcl_context *__0__X253;

                                                    __1fl = __0this->friend_list__8classdef;
                                                    for (; __1fl; __1fl = __1fl->l__9name_list) {
                                                        Pname __2p;
                                                        Pfct __2f;

                                                        __2p = __1fl->f__9name_list;
                                                        __2f = (((struct fct *)((
                                                            (struct fct *)__2p->__O1__4expr.tp))));

                                                        switch (__2f->base__4node) {
                                                        case 108:
                                                            if (__1hito && __2f->argtype__3fct)
                                                                fix_args__FP3fctP8classdef(__2f,
                                                                                           __0this);
                                                            if (__2f->body__3fct &&
                                                                ((__2f->defined__4type & 3) == 0))
                                                                __2p->n_sto__4name = 31;
                                                            else if (__2p->n_scope__4name == 31) {
                                                                struct ea __0__V208;

                                                                struct ea __0__V209;

                                                                error__FiPCcRC2eaN33(
                                                                    strict_opt ? 0 : 119,
                                                                    (const char
                                                                         *)"static%n declared "
                                                                           "friend toC%t",
                                                                    (const struct ea
                                                                         *)(((&__0__V208)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __2p)),
                                                                            (&__0__V208)),
                                                                    (const struct ea
                                                                         *)(((&__0__V209)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __0this)),
                                                                            (&__0__V209)),
                                                                    (const struct ea *)ea0,
                                                                    (const struct ea *)ea0);
                                                            }
                                                            break;
                                                        case 76: {
                                                            Pgen __4g;

                                                            __4g = (((struct gen *)((
                                                                (struct gen *)__2f))));
                                                            {
                                                                {
                                                                    Plist __4gl;

                                                                    __4gl = __4g->fct_list__3gen;

                                                                    for (; __4gl;
                                                                         __4gl =
                                                                             __4gl->l__9name_list) {
                                                                        Pname __5n;
                                                                        Pfct __5f;

                                                                        __5n = __4gl->f__9name_list;
                                                                        __5f = (((struct fct *)((
                                                                            (struct fct *)
                                                                                __5n->__O1__4expr
                                                                                    .tp))));

                                                                        if (__1hito &&
                                                                            __5f->argtype__3fct)
                                                                            fix_args__FP3fctP8classdef(
                                                                                __5f, __0this);
                                                                        if (__5f->body__3fct &&
                                                                            ((__5f->defined__4type &
                                                                              3) == 0))
                                                                            __5n->n_sto__4name = 31;
                                                                        else if (
                                                                            __2p->n_scope__4name ==
                                                                            31) {
                                                                            struct ea __0__V210;

                                                                            struct ea __0__V211;

                                                                            error__FiPCcRC2eaN33(
                                                                                strict_opt ? 0
                                                                                           : 119,
                                                                                (const char
                                                                                     *)"static%n "
                                                                                       "declared "
                                                                                       "friend "
                                                                                       "toC%t",
                                                                                (const struct
                                                                                 ea *)(((&__0__V210)
                                                                                            ->__O1__2ea
                                                                                            .p =
                                                                                            ((const void
                                                                                                  *)
                                                                                                 __2p)),
                                                                                       (&__0__V210)),
                                                                                (const struct
                                                                                 ea *)(((&__0__V211)
                                                                                            ->__O1__2ea
                                                                                            .p =
                                                                                            ((const void
                                                                                                  *)
                                                                                                 __0this)),
                                                                                       (&__0__V211)),
                                                                                (const struct ea *)
                                                                                    ea0,
                                                                                (const struct ea *)
                                                                                    ea0);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        }
                                                    }

                                                    simpl_friend = 0;
                                                    for (__1fl = __0this->friend_list__8classdef;
                                                         __1fl; __1fl = __1fl->l__9name_list) {
                                                        Pname __2p;
                                                        Pfct __2f;

                                                        __2p = __1fl->f__9name_list;
                                                        __2f = (((struct fct *)((
                                                            (struct fct *)__2p->__O1__4expr.tp))));
                                                        simpl_friend = 1;

                                                        switch (__2f->base__4node) {
                                                        case 108:
                                                            if (__2f->body__3fct &&
                                                                ((__2f->defined__4type & 3) == 0)) {
                                                                dcl__3fctFP4name(__2f, __2p);
                                                                simpl__4nameFv(__2p);
                                                            }
                                                            break;
                                                        case 76: {
                                                            Pgen __4g;

                                                            __4g = (((struct gen *)((
                                                                (struct gen *)__2f))));
                                                            {
                                                                {
                                                                    Plist __4gl;

                                                                    __4gl = __4g->fct_list__3gen;

                                                                    for (; __4gl;
                                                                         __4gl =
                                                                             __4gl->l__9name_list) {
                                                                        Pname __5n;
                                                                        Pfct __5f;

                                                                        __5n = __4gl->f__9name_list;
                                                                        __5f = (((struct fct *)((
                                                                            (struct fct *)
                                                                                __5n->__O1__4expr
                                                                                    .tp))));

                                                                        if (__5f->body__3fct &&
                                                                            ((__5f->defined__4type &
                                                                              3) == 0)) {
                                                                            dcl__3fctFP4name(__5f,
                                                                                             __5n);
                                                                            simpl__4nameFv(__5n);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        }
                                                    }
                                                    simpl_friend = 0;
                                                    (((cc--), (((void)0))));

                                                    if (__1tbl != gtbl)
                                                        simpl__8classdefFv(__0this);

                                                    if ((__0this->defined__4type & 010) != 0)
                                                        dcl_print__8classdefFP4name(
                                                            __0this, (struct name *)0);

                                                    if (debug_opt) {
                                                        if (__0this->nested_sig__4type) {
                                                            prnt_all_in_scope__FP8classdef(
                                                                __0this->in_class__4type);
                                                        }
                                                        {
                                                            if (__0this->in_fct__4type ||
                                                                (!__0this->in_class__4type))
                                                                dump_func__FP8classdef(__0this);
                                                        }
                                                    }

                                                    {
                                                        if (!__0this->in_class__4type)
                                                            check_abst__FP8classdef(__0this);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void dump_func__FP8classdef(Pclass __1th);

void dump_func__FP8classdef(Pclass __1th) {
    int __1i;
    {
        {
            Pname __1p;

            struct table *__0__X256;

            int __2__X257;

            struct table *__0__X258;

            int __2__X259;

            __1p = ((__0__X258 = __1th->memtbl__8classdef),
                    ((__2__X259 = (__1i = 1)),
                     ((((__2__X259 <= 0) || (__0__X258->free_slot__5table <= __2__X259))
                           ? (((struct name *)0))
                           : (__0__X258->entries__5table[__2__X259])))));

            for (; __1p;
                 __1p = (__1p->n_tbl_list__4name
                             ? __1p->n_tbl_list__4name
                             : ((__0__X256 = __1th->memtbl__8classdef),
                                ((__2__X257 = (++__1i)),
                                 ((((__2__X257 <= 0) || (__0__X256->free_slot__5table <= __2__X257))
                                       ? (((struct name *)0))
                                       : (__0__X256->entries__5table[__2__X257]))))))) {
                if ((__1p->base__4node == 123) || (!__1p->__O1__4expr.tp))
                    continue;
                {
                    Ptype __2t;

                    __2t = skiptypedefs__4typeFv(__1p->__O1__4expr.tp);
                    if (__2t->base__4node == 6) {
                        dump_func__FP8classdef(((struct classdef *)(((struct classdef *)__2t))));
                        continue;
                    }
                    {
                        Pfct __2f;

                        __2f = (((struct fct *)(((struct fct *)__2t))));
                        if (__2f == 0)
                            continue;

                        switch (__2f->base__4node) {
                        case 108:
                            if (__2f->body__3fct) {
                                if (__1th->c_body__8classdef == 1) {
                                    if (__1th->class_base__8classdef == 4)
                                        current_instantiation = __1th;
                                    dcl_print__8classdefFP4name(__1th, (struct name *)0);
                                    if (__1th->class_base__8classdef == 4)
                                        current_instantiation = 0;
                                }
                                dcl_print__4nameFUc(__1p, (unsigned char)0);
                            }
                            break;
                        case 76: {
                            Pgen __4g;

                            __4g = (((struct gen *)(((struct gen *)__2f))));
                            {
                                {
                                    Plist __4gl;

                                    __4gl = __4g->fct_list__3gen;

                                    for (; __4gl; __4gl = __4gl->l__9name_list) {
                                        Pname __5n;
                                        Pfct __5f;

                                        __5n = __4gl->f__9name_list;
                                        __5f = ((
                                            (struct fct *)(((struct fct *)__5n->__O1__4expr.tp))));
                                        if (__5f->body__3fct) {
                                            if (__1th->c_body__8classdef == 1) {
                                                if (__1th->class_base__8classdef == 4)
                                                    current_instantiation = __1th;
                                                dcl_print__8classdefFP4name(__1th,
                                                                            (struct name *)0);
                                                if (__1th->class_base__8classdef == 4)
                                                    current_instantiation = 0;
                                            }
                                            dcl_print__4nameFUc(__1p, (unsigned char)0);
                                        }
                                    }
                                }
                            }
                        }
                        }
                    }
                }
            }

            {
                {
                    Plist __1fl;

                    __1fl = __1th->friend_list__8classdef;

                    for (; __1fl; __1fl = __1fl->l__9name_list) {
                        Pname __2p;
                        Pfct __2f;

                        __2p = __1fl->f__9name_list;
                        __2f = (((struct fct *)(((struct fct *)__2p->__O1__4expr.tp))));

                        switch (__2f->base__4node) {
                        case 108:
                            if (__2f->body__3fct && ((__2f->defined__4type & 3) == 0))
                                dcl_print__4nameFUc(__2p, (unsigned char)0);
                            break;
                        case 76: {
                            Pgen __4g;

                            __4g = (((struct gen *)(((struct gen *)__2f))));
                            {
                                {
                                    Plist __4gl;

                                    __4gl = __4g->fct_list__3gen;

                                    for (; __4gl; __4gl = __4gl->l__9name_list) {
                                        Pname __5n;
                                        Pfct __5f;

                                        __5n = __4gl->f__9name_list;
                                        __5f = ((
                                            (struct fct *)(((struct fct *)__5n->__O1__4expr.tp))));

                                        if (__5f->body__3fct && ((__5f->defined__4type & 3) == 0))
                                            dcl_print__4nameFUc(__2p, (unsigned char)0);
                                    }
                                }
                            }
                        }
                        }
                    }
                }
            }
        }
    }
}

void check_abst__FP8classdef(Pclass __1th);

extern void check_abst_func__FP4nameP3fct(Pname, Pfct);

void check_abst__FP8classdef(Pclass __1th) {
    int __1i;
    {
        {
            Pname __1p;

            struct table *__0__X260;

            int __2__X261;

            struct table *__0__X262;

            int __2__X263;

            __1p = ((__0__X262 = __1th->memtbl__8classdef),
                    ((__2__X263 = (__1i = 1)),
                     ((((__2__X263 <= 0) || (__0__X262->free_slot__5table <= __2__X263))
                           ? (((struct name *)0))
                           : (__0__X262->entries__5table[__2__X263])))));

            for (; __1p;
                 __1p = (__1p->n_tbl_list__4name
                             ? __1p->n_tbl_list__4name
                             : ((__0__X260 = __1th->memtbl__8classdef),
                                ((__2__X261 = (++__1i)),
                                 ((((__2__X261 <= 0) || (__0__X260->free_slot__5table <= __2__X261))
                                       ? (((struct name *)0))
                                       : (__0__X260->entries__5table[__2__X261]))))))) {
                if ((__1p->base__4node == 123) || (!__1p->__O1__4expr.tp))
                    continue;
                {
                    Ptype __2t;

                    __2t = skiptypedefs__4typeFv(__1p->__O1__4expr.tp);
                    if (__2t->base__4node == 6) {
                        check_abst__FP8classdef(((struct classdef *)(((struct classdef *)__2t))));
                        continue;
                    }
                    {
                        Pfct __2f;

                        __2f = (((struct fct *)(((struct fct *)__2t))));

                        if (__2f == 0)
                            continue;
                        switch (__2f->base__4node) {
                        case 108:
                            check_abst_func__FP4nameP3fct(__1p, __2f);
                            break;
                        case 76: {
                            Pgen __4g;

                            __4g = (((struct gen *)(((struct gen *)__2f))));
                            {
                                {
                                    Plist __4gl;

                                    __4gl = __4g->fct_list__3gen;

                                    for (; __4gl; __4gl = __4gl->l__9name_list) {
                                        Pfct __5f;

                                        __5f = (((struct fct *)((
                                            (struct fct *)__4gl->f__9name_list->__O1__4expr.tp))));
                                        check_abst_func__FP4nameP3fct(__4gl->f__9name_list, __5f);
                                    }
                                    break;
                                }
                            }
                        }
                        }
                    }
                }
            }
        }
    }
}

Pclass classtype__4typeFv(struct type *__0this);

void check_abst_func__FP4nameP3fct(Pname __1p, Pfct __1f) {
    if (is_cl_obj__4typeFv(__1f->returns__3fct)) {
        Pclass __2cl;

        __2cl = classtype__4typeFv(skiptypedefs__4typeFv(__1f->returns__3fct));
        if (__2cl->c_abstract__8classdef) {
            const void *__2__X270;

            {
                struct ea __0__V264;

                error__FP3locPCcRC2eaN33(
                    &__1p->where__4name, (const char *)"abstractC%t cannot be used as aF returnT",
                    (const struct ea *)(((&__0__V264)->__O1__2ea.p = ((const void *)__2cl)),
                                        (&__0__V264)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                {
                    struct ea __0__V265;

                    struct ea __0__V266;

                    error__FiP3locPCcRC2eaN34(
                        (int)'C', &__1p->where__4name,
                        (const char *)"\t%a is a pure virtualF ofC%t\n",
                        (const struct ea *)((__2__X270 =
                                                 (const void *)__2cl->c_abstract__8classdef),
                                            (((&__0__V265)->__O1__2ea.p = __2__X270),
                                             (&__0__V265))),
                        (const struct ea *)(((&__0__V266)->__O1__2ea.p = ((const void *)__2cl)),
                                            (&__0__V266)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
        }
    }

    {
        {
            Pname __1a;

            __1a = __1f->argtype__3fct;

            for (; __1a; __1a = __1a->__O1__4name.n_list) {
                if (__1a->__O1__4expr.tp && is_cl_obj__4typeFv(__1a->__O1__4expr.tp)) {
                    Pclass __3cl;

                    __3cl = classtype__4typeFv(skiptypedefs__4typeFv(__1a->__O1__4expr.tp));
                    if (__3cl->c_abstract__8classdef) {
                        const void *__2__X271;

                        {
                            struct ea __0__V267;

                            error__FP3locPCcRC2eaN33(
                                &__1p->where__4name,
                                (const char *)"abstractC%t cannot be used as anAT",
                                (const struct ea *)(((&__0__V267)->__O1__2ea.p =
                                                         ((const void *)__3cl)),
                                                    (&__0__V267)),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                            {
                                struct ea __0__V268;

                                struct ea __0__V269;

                                error__FiP3locPCcRC2eaN34(
                                    (int)'C', &__1p->where__4name,
                                    (const char *)"\t%a is a pure virtualF ofC%t\n",
                                    (const struct ea *)((__2__X271 = (const void *)__3cl
                                                                         ->c_abstract__8classdef),
                                                        (((&__0__V268)->__O1__2ea.p = __2__X271),
                                                         (&__0__V268))),
                                    (const struct ea *)(((&__0__V269)->__O1__2ea.p =
                                                             ((const void *)__3cl)),
                                                        (&__0__V269)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                        }
                    }
                }
            }
        }
    }
}

int no_of_names__4nameFv(struct name *__0this);

Pexpr typ__4exprFP5table(struct expr *__0this, Ptable);
long long eval__4exprFv(struct expr *__0this);

bit is_unsigned__4typeFv(struct type *__0this);

void del__4exprFv(struct expr *__0this);

void dcl__7enumdefFP4nameP5table(register struct enumdef *__0this, Pname __1n, Ptable __1tbl) {
    Pname __1px;
    Pname __1p;

    __1p = __0this->mem__7enumdef;
    ;
    {
        Pbase __1b;

        __1b = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)121, __1n);
        __1b->b_const__4type = 1;

        if (__0this->local_sig__4type) {
            __0this->in_fct__4type = cc->nof__11dcl_context;
        } else
            __0this->in_fct__4type = 0;

        {
            int __1enum_count;

            __1enum_count = 0;
            __0this->no_of_enumerators__7enumdef = no_of_names__4nameFv(__0this->mem__7enumdef);
            {
                int __1largest;

                __1largest = 0;

                if (__1p == 0)
                    __0this->mem__7enumdef = __ct__4nameFPCc(
                        (struct name *)0, (const char *)make_name__FUc((unsigned char)'e'));

                for (; __1p; __1p = __1px) {
                    Pname __2nn;

                    __1px = __1p->__O1__4name.n_list;

                    if (__1p->__O3__4expr.n_initializer) {
                        Pexpr __3i;

                        __3i = typ__4exprFP5table(__1p->__O3__4expr.n_initializer, __1tbl);
                        Neval = 0;
                        {
                            long long __3ii;

                            const void *__2__X275;

                            __3ii = eval__4exprFv(__3i);

                            if (__3i->__O1__4expr.tp) {
                                bit __4u;
                                bit __4ok;
                                int __4smallest_int;

                                __4u = is_unsigned__4typeFv(
                                    skiptypedefs__4typeFv(__3i->__O1__4expr.tp));
                                __4ok = 0;
                                __4smallest_int = (-largest_int);
                                switch (skiptypedefs__4typeFv(__3i->__O1__4expr.tp)->base__4node) {
                                case 5:
                                    if (__4u) {
                                        __4ok = ((((unsigned char)__3ii)) <= largest_int);
                                    } else {
                                        __4ok = (((((char)__3ii)) >= __4smallest_int) &&
                                                 ((((char)__3ii)) <= largest_int));
                                    }
                                    break;
                                case 29:
                                    if (__4u) {
                                        __4ok = ((((unsigned short)__3ii)) <= largest_int);

                                    } else {
                                        __4ok = (((((short)__3ii)) >= __4smallest_int) &&
                                                 ((((short)__3ii)) <= largest_int));
                                    }
                                    break;
                                case 138:
                                case 21:
                                case 13:
                                case 121:
                                    if (__4u) {
                                        __4ok = ((((unsigned int)__3ii)) <= largest_int);

                                    } else {
                                        __4ok = (((((int)__3ii)) >= __4smallest_int) &&
                                                 ((((int)__3ii)) <= largest_int));
                                    }
                                    break;
                                case 22:
                                    if (__4u) {
                                        __4ok = ((((unsigned long)__3ii)) <= largest_int);

                                    } else {
                                        __4ok = (((((long)__3ii)) >= __4smallest_int) &&
                                                 ((((long)__3ii)) <= largest_int));
                                    }
                                    break;
                                case 122:
                                    if (__4u) {
                                        __4ok = ((((unsigned long long)__3ii)) <= largest_int);

                                    } else {
                                        __4ok = (((((long long)__3ii)) >= __4smallest_int) &&
                                                 ((((long long)__3ii)) <= largest_int));
                                    }
                                    break;
                                default:
                                    __4ok = 1;
                                    break;
                                }
                                if (!__4ok)
                                    error__FPCc((const char *)"long enumerator");
                            }
                            __1enum_count = (((int)__3ii));
                            if (Neval) {
                                struct ea __0__V272;

                                error__FP3locPCcRC2eaN33(
                                    &__1p->where__4name, (const char *)"%s",
                                    (const struct ea *)((__2__X275 = (const void *)Neval),
                                                        (((&__0__V272)->__O1__2ea.p = __2__X275),
                                                         (&__0__V272))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            if (__3i && (__3i->permanent__4node == 0))
                                del__4exprFv(__3i);
                            __1p->__O3__4expr.n_initializer = 0;
                        }
                    }
                    __1p->n_evaluated__4name = 1;
                    __1largest |= __1enum_count;
                    if (((__1enum_count == largest_int) && __1px) &&
                        (!__1px->__O3__4expr.n_initializer))
                        error__FPCc((const char *)"enumerator too large");
                    __1p->n_val__4name = (__1enum_count++);
                    __1p->__O1__4expr.tp = (struct type *)__1b;

                    ;
                    if ((__1tbl == gtbl) || __1tbl->t_name__5table)
                        __2nn =
                            look__5tableFPCcUc(__1tbl, __1p->__O2__4expr.string, (unsigned char)0);
                    else
                        __2nn = look__5tableFPCcUc(curr_block->memtbl__4stmt,
                                                   __1p->__O2__4expr.string, (unsigned char)0);
                    if (__2nn && (((__1tbl == gtbl) || __1tbl->t_name__5table) ||
                                  ((__2nn->__O4__4expr.n_table->real_block__5table ==
                                    curr_block->memtbl__4stmt->real_block__5table) &&
                                   (__2nn->lex_level__4name == __1p->lex_level__4name)))) {
                        if (__2nn->n_stclass__4name == 13) {
                            struct ea __0__V273;

                            error__FPCcRC2eaN32((const char *)"enumerator%n declared twice",
                                                (const struct ea *)(((&__0__V273)->__O1__2ea.p =
                                                                         ((const void *)__2nn)),
                                                                    (&__0__V273)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        } else {
                            struct ea __0__V274;

                            error__FPCcRC2eaN32((const char *)"incompatibleDs of%n",
                                                (const struct ea *)(((&__0__V274)->__O1__2ea.p =
                                                                         ((const void *)__2nn)),
                                                                    (&__0__V274)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        }
                    } else {
                        __2nn = insert__5tableFP4nameUc(__1tbl, __1p, (unsigned char)0);
                        __2nn->n_stclass__4name = 13;
                        if (Eppp == 79)
                            __2nn->n_protect__4name = 79;
                        else if (Eppp == 25)
                            __2nn->n_scope__4name = 25;
                    }
                    __1p->__O2__4expr.string = __2nn->__O2__4expr.string;
                }

                __0this->e_type__7enumdef = int_type;

                __0this->defined__4type |= 01;

                if (((pt_opt && (!__0this->nested_sig__4type)) && (!__0this->local_sig__4type)) &&
                    (!is_probably_temp__FPCc(__0this->string__7enumdef)))
                    fprintf(pt_file, (const char *)"e %s %s\n", __0this->string__7enumdef,
                            curr_filename__Fv());
            }
        }
    }
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
