
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

void del__4typeFv(struct type *__0this);

void del__4exprFv(struct expr *__0this);

void del__4nameFv(register struct name *__0this) {
    ;
    {
        Pexpr __1i;

        __1i = __0this->__O3__4expr.n_initializer;

        if (__0this->__O1__4expr.tp && (__0this->__O1__4expr.tp->permanent__4node == 0))
            del__4typeFv(__0this->__O1__4expr.tp);
        if (__1i && (__1i != (((struct expr *)1))))
            if (__1i && (__1i->permanent__4node == 0))
                del__4exprFv(__1i);
        ((__0this
              ? (((void)(__0this ? (((void)((((((struct expr *)__0this))
                                                  ? (((void)((((struct expr *)__0this))
                                                                 ? (((void)(((void)0))))
                                                                 : (((void)0)))))
                                                  : (((void)0)))),
                                            (((void)__dl__4nameSFPvUl(
                                                (void *)__0this, (size_t)(sizeof(struct name))))))))
                                 : (((void)0)))))
              : (((void)0))));
    }
}

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

void del__4typeFv(register struct type *__0this) {
    ;

    __0this->permanent__4node = 3;
    switch (__0this->base__4node) {
        unsigned long __2__X20;

    case 123:
    case 85: {
        struct ea __0__V17;

        struct ea __0__V18;

        struct ea __0__V19;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"%d->T::del():N %s %d",
            (const struct ea *)(((&__0__V17)->__O1__2ea.p = ((const void *)__0this)), (&__0__V17)),
            (const struct ea *)__ct__2eaFPCv(
                &__0__V18,
                (const void *)(((struct name *)(((struct name *)__0this))))->__O2__4expr.string),
            (const struct ea *)((__2__X20 = __0this->base__4node),
                                (((((&__0__V19)->__O1__2ea.i = __2__X20), 0)), (&__0__V19))),
            (const struct ea *)ea0);

    case 108: {
        Pfct __3f;

        __3f = (((struct fct *)(((struct fct *)__0this))));
        if (__3f->returns__3fct && (__3f->returns__3fct->permanent__4node == 0))
            del__4typeFv(__3f->returns__3fct);
        ((__3f ? (((void)(__3f ? (((void)(((void)__dl__3fctSFPvUl((void *)__3f,
                                                                  (size_t)(sizeof(struct fct)))))))
                               : (((void)0)))))
               : (((void)0))));
        break;
    }
    case 110: {
        Pvec __3v;

        __3v = (((struct vec *)(((struct vec *)__0this))));
        if (__3v->dim__3vec && (__3v->dim__3vec->permanent__4node == 0))
            del__4exprFv(__3v->dim__3vec);
        if (__3v->typ__5pvtyp && (__3v->typ__5pvtyp->permanent__4node == 0))
            del__4typeFv(__3v->typ__5pvtyp);
        ((__3v ? (((void)(__3v ? (((void)(((void)__dl__3vecSFPvUl((void *)__3v,
                                                                  (size_t)(sizeof(struct vec)))))))
                               : (((void)0)))))
               : (((void)0))));
        break;
    }
    case 125:
    case 158: {
        Pptr __3p;

        __3p = (((struct ptr *)(((struct ptr *)__0this))));
        if (__3p->typ__5pvtyp && (__3p->typ__5pvtyp->permanent__4node == 0))
            del__4typeFv(__3p->typ__5pvtyp);
        ((__3p ? (((void)(__3p ? (((void)(((void)__dl__3ptrSFPvUl((void *)__3p,
                                                                  (size_t)(sizeof(struct ptr)))))))
                               : (((void)0)))))
               : (((void)0))));
        break;
    }
    }
    }
}

extern void __dl__FPv(void *);

void del__4exprFv(register struct expr *__0this) {
    ;

    __0this->permanent__4node = 3;
    switch (__0this->base__4node) {
    case 150:
        if (__0this == one)
            return;

    case 34:
    case 82:
    case 83:
    case 84:
    case 81:
    case 165:
        goto dd;
    case 144:
    case 162:
    case 86:
    case 85:
        return;
    case 113:
    case 191:
    case 30:
    case 23:
    case 184:
    case 157:
        if (__0this->__O4__4expr.tp2 && (__0this->__O4__4expr.tp2->permanent__4node == 0))
            del__4typeFv(__0this->__O4__4expr.tp2);
        break;
    case 44:
    case 45:
        if (__0this->__O2__4expr.e1 && (__0this->__O2__4expr.e1->permanent__4node == 0))
            del__4exprFv(__0this->__O2__4expr.e1);
        if (__0this->__O3__4expr.e2)
            if (__0this->__O3__4expr.e2 && (__0this->__O3__4expr.e2->permanent__4node == 0))
                del__4exprFv(__0this->__O3__4expr.e2);
    case 177:
        if (__0this->__O4__4expr.mem && (__0this->__O4__4expr.mem->base__4node != 85))
            if (__0this->__O4__4expr.mem && (__0this->__O4__4expr.mem->permanent__4node == 0))
                del__4exprFv(__0this->__O4__4expr.mem);
        if (__0this->__O2__4expr.i1 == 5)
            __dl__FPv((void *)__0this->__O1__4expr.string4);
        goto dd;
    case 68:
        if (__0this->__O4__4expr.cond && (__0this->__O4__4expr.cond->permanent__4node == 0))
            del__4exprFv(__0this->__O4__4expr.cond);
        break;
    case 168:
        __vec_delete(((void *)__0this->__O4__4expr.il->i_args__5iline), -1, sizeof(struct ia),
                     ((void *)0), 1, 0);
        __dl__FPv((void *)__0this->__O4__4expr.il);
        goto dd;
    case 140: {
        Pexpr __3tp;

        __3tp = __0this->__O3__4expr.e2;
        while ((__3tp && __3tp->__O3__4expr.e2) && (__3tp->__O3__4expr.e2->base__4node == 140)) {
            Pexpr __4x;

            __4x = __3tp;
            if (__4x->permanent__4node)
                break;
            __4x->permanent__4node = 3;
            __3tp = __3tp->__O3__4expr.e2;
            if (__4x->__O2__4expr.e1)
                if (__4x->__O2__4expr.e1 && (__4x->__O2__4expr.e1->permanent__4node == 0))
                    del__4exprFv(__4x->__O2__4expr.e1);
            ((__4x ? (((void)(__4x ? (((void)(((void)__dl__4exprSFPvUl(
                                         (void *)__4x, (size_t)(sizeof(struct expr)))))))
                                   : (((void)0)))))
                   : (((void)0))));
        }
        __0this->__O3__4expr.e2 = __3tp;
        break;
    }
    }

    if (__0this->__O2__4expr.e1 && (__0this->__O2__4expr.e1->permanent__4node == 0))
        del__4exprFv(__0this->__O2__4expr.e1);
    if (__0this->__O3__4expr.e2 && (__0this->__O3__4expr.e2->permanent__4node == 0))
        del__4exprFv(__0this->__O3__4expr.e2);
dd:
    ((__0this ? (((void)(__0this ? (((void)(((void)__dl__4exprSFPvUl(
                                       (void *)__0this, (size_t)(sizeof(struct expr)))))))
                                 : (((void)0)))))
              : (((void)0))));
}

void del__4stmtFv(struct stmt *__0this);

void del__5tableFv(struct table *__0this);

void del__4stmtFv(register struct stmt *__0this) {
    ;

    __0this->permanent__4node = 3;
    switch (__0this->base__4node) {
    case 72:
    case 39:
    case 10:
    case 28:
    case 4:
    case 33:
        if (__0this->__O2__4stmt.e && (__0this->__O2__4stmt.e->permanent__4node == 0))
            del__4exprFv(__0this->__O2__4stmt.e);
        break;
    case 166:
        if (__0this->__O2__4stmt.s2 && (__0this->__O2__4stmt.s2->permanent__4node == 0))
            del__4stmtFv(__0this->__O2__4stmt.s2);
        break;
    case 116:
        if (__0this->__O1__4stmt.d && (__0this->__O1__4stmt.d->permanent__4node == 0))
            del__4nameFv(__0this->__O1__4stmt.d);
        if (__0this->s__4stmt && (__0this->s__4stmt->permanent__4node == 0))
            del__4stmtFv(__0this->s__4stmt);
        if (__0this->__O2__4stmt.own_tbl)
            if (__0this->memtbl__4stmt && (__0this->memtbl__4stmt->permanent__4node == 0))
                del__5tableFv(__0this->memtbl__4stmt);
        if (__0this->s_list__4stmt && (__0this->s_list__4stmt->permanent__4node == 0))
            del__4stmtFv(__0this->s_list__4stmt);
        goto dd;
    case 16:
        if (__0this->__O2__4stmt.e && (__0this->__O2__4stmt.e->permanent__4node == 0))
            del__4exprFv(__0this->__O2__4stmt.e);
        if (__0this->__O1__4stmt.e2 && (__0this->__O1__4stmt.e2->permanent__4node == 0))
            del__4exprFv(__0this->__O1__4stmt.e2);
        if (__0this->__O3__4stmt.for_init && (__0this->__O3__4stmt.for_init->permanent__4node == 0))
            del__4stmtFv(__0this->__O3__4stmt.for_init);
        break;
    case 20:
        if (__0this->__O2__4stmt.e && (__0this->__O2__4stmt.e->permanent__4node == 0))
            del__4exprFv(__0this->__O2__4stmt.e);
        if (__0this->__O3__4stmt.else_stmt &&
            (__0this->__O3__4stmt.else_stmt->permanent__4node == 0))
            del__4stmtFv(__0this->__O3__4stmt.else_stmt);
        break;
    }

    if (__0this->s__4stmt && (__0this->s__4stmt->permanent__4node == 0))
        del__4stmtFv(__0this->s__4stmt);
    if (__0this->s_list__4stmt && (__0this->s_list__4stmt->permanent__4node == 0))
        del__4stmtFv(__0this->s_list__4stmt);
dd:
    ((__0this ? (((void)(__0this ? (((void)(((void)__dl__4stmtSFPvUl(
                                       (void *)__0this, (size_t)(sizeof(struct stmt)))))))
                                 : (((void)0)))))
              : (((void)0))));
}

void __dt__5tableFv(struct table *__0this, int);

void del__5tableFv(register struct table *__0this) {
    {
        {
            int __1i;

            __1i = 1;

            for (; __1i < __0this->free_slot__5table; __1i++) {
                Pname __2n;

                __2n = (__0this->entries__5table[__1i]);
                if (__2n == 0)
                    error__FiPCc((int)'i', (const char *)"table.del(0)");

                ;

                if (__2n->n_stclass__4name == 31)
                    continue;
                switch (__2n->n_scope__4name) {
                case 136:
                case 139:
                    break;
                default: {
                    const char *__4s;

                    __4s = __2n->__O2__4expr.string;
                    if (__4s && ((((__4s[0]) != '_') || ((__4s[1]) != '_')) || ((__4s[2]) != 'X')))
                        __dl__FPv((void *)(((char *)__4s)));

                    del__4nameFv(__2n);
                }
                }
            }

            __dt__5tableFv(__0this, 3);
        }
    }
}

void really_print__8classdefFP4virt(struct classdef *__0this, Pvirt);

void dcl_print__4nameFUc(struct name *__0this, TOK);

void delete_local__Fv(void) {
    ;

    do {
        {
            {
                struct vl *__2v;

                __2v = vlist;

                for (; __2v; __2v = __2v->next__2vl)
                    really_print__8classdefFP4virt(__2v->cl__2vl, __2v->vt__2vl);
                vlist = 0;

                {
                    {
                        Plist __2l;

                        __2l = isf_list;

                        for (; __2l; __2l = __2l->l__9name_list) {
                            Pname __3n;
                            Pfct __3f;

                            __3n = __2l->f__9name_list;
                            __3f = (((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))));

                            if (__3f == 0) {
                                error__FiPCc((int)'d', (const char *)"delete_local: f == 0");
                                break;
                            }
                            if (__3f->base__4node == 76) {
                                __3n = (((struct gen *)(((struct gen *)__3f))))
                                           ->fct_list__3gen->f__9name_list;
                                __3f = (((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))));
                            }

                            if ((debug_opt == 0) && __3n->n_addr_taken__4name) {
                                __3f->f_inline__3fct = 0;
                                if (__3n->n_dcl_printed__4name < 2) {
                                    if (warning_opt) {
                                        struct ea __0__V21;

                                        error__FiPCcRC2eaN33(
                                            (int)'w',
                                            (const char *)"out-of-line copy of %n created",
                                            (const struct ea *)(((&__0__V21)->__O1__2ea.p =
                                                                     ((const void *)__3n)),
                                                                (&__0__V21)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                    }
                                    dcl_print__4nameFUc(__3n, (unsigned char)0);
                                }
                            }
                        }
                    }
                }
            }
        }

    } while (vlist);
    {
        {
            Plist __1l;

            __1l = local_class;

            for (; __1l; __1l = __1l->l__9name_list) {
                Pname __2n;

                Pname __2nn;
                Pclass __2cl;

                __2n = __1l->f__9name_list;

                __2nn = (((struct basetype *)(((struct basetype *)__2n->__O1__4expr.tp))))
                            ->b_name__8basetype;
                __2cl = (((struct classdef *)(((struct classdef *)__2nn->__O1__4expr.tp))));
                {
                    {
                        Pname __2px;

                        Pname __2p;

                        __2p = __2cl->mem_list__8classdef;

                        for (; __2p; __2p = __2px) {
                            __2px = __2p->__O1__4name.n_list;
                            if (__2p->__O1__4expr.tp)
                                switch (__2p->__O1__4expr.tp->base__4node) {
                                case 108: {
                                    Pfct __5f;

                                    __5f = (((struct fct *)(((struct fct *)__2p->__O1__4expr.tp))));
                                    if (__5f->body__3fct) {
                                        if ((__5f->f_inline__3fct == 0) &&
                                            (__5f->f_imeasure__3fct == 0)) {
                                            if (ansi_opt && __5f->f_this__3fct) {

                                                __5f->f_this__3fct->__O4__4expr.n_table = 0;
                                                {
                                                    {
                                                        Pname __8n;

                                                        __8n =
                                                            __5f->f_this__3fct->__O1__4name.n_list;

                                                        for (; __8n;
                                                             __8n = __8n->__O1__4name.n_list)
                                                            __8n->__O4__4expr.n_table = 0;
                                                    }
                                                }
                                            }

                                            if (__5f->body__3fct &&
                                                (__5f->body__3fct->permanent__4node == 0))
                                                del__4stmtFv((struct stmt *)__5f->body__3fct);
                                            __5f->body__3fct = 0;
                                        }
                                    }
                                }
                                case 119:
                                case 121:
                                    if (__2p && (__2p->permanent__4node == 0))
                                        del__4nameFv(__2p);
                                    break;
                                case 6:
                                case 13:
                                    break;
                                default:
                                    ((__2p
                                          ? (((void)(__2p
                                                         ? (((void)((((((struct expr *)__2p))
                                                                          ? (((void)((((struct expr
                                                                                            *)__2p))
                                                                                         ? (((void)(((
                                                                                               void)0))))
                                                                                         : (((void)0)))))
                                                                          : (((void)0)))),
                                                                    (((void)__dl__4nameSFPvUl(
                                                                        (void *)__2p,
                                                                        (size_t)(sizeof(
                                                                            struct name))))))))
                                                         : (((void)0)))))
                                          : (((void)0))));
                                }
                            else
                                ((__2p
                                      ? (((void)(__2p
                                                     ? (((void)((((((struct expr *)__2p))
                                                                      ? (((void)((((struct expr *)
                                                                                       __2p))
                                                                                     ? (((void)(((
                                                                                           void)0))))
                                                                                     : (((void)0)))))
                                                                      : (((void)0)))),
                                                                (((void)__dl__4nameSFPvUl(
                                                                    (void *)__2p,
                                                                    (size_t)(sizeof(
                                                                        struct name))))))))
                                                     : (((void)0)))))
                                      : (((void)0))));
                        }
                        if (__2cl->memtbl__8classdef &&
                            (__2cl->memtbl__8classdef->permanent__4node == 0))
                            del__5tableFv(__2cl->memtbl__8classdef);
                        __2cl->mem_list__8classdef = 0;
                        __2cl->permanent__4node = 3;
                        __2nn->permanent__4node = 0;
                        if (__2nn && (__2nn->permanent__4node == 0))
                            del__4nameFv(__2nn);
                        __2n->permanent__4node = 0;

                        if (__2n && (__2n->permanent__4node == 0))
                            del__4nameFv(__2n);
                    }
                }
            }
        }
    }
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
