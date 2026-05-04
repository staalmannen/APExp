
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

static Ptable Scope;

extern size_t strlen(const char *);

extern char *strcpy(char *, const char *);

static const char *temp__FPCcP4name(const char *__1vn, Pname __1fn) {
    if ((((__1vn[0]) != '_') || ((__1vn[1]) != '_')) || ((__1vn[2]) != 'X')) {

        size_t __2a;

        size_t __2aa;
        int __2al;

        __2a = ((size_t)__1fn->__O1__4expr.tp);

        __2aa = __2a;
        __2al = 0;
        while (__2aa) {
            __2al++;
            __2aa >>= 5;
        }

        {
            int __2ll;
            char *__2s;
            char *__2p;

            __2ll = strlen(__1vn);
            __2s = (((char *)__nw__FUl((size_t)((sizeof(char)) * ((__2ll + __2al) + 8)))));
            __2p = __2s;

            ((*(__2p++))) = '_';
            ((*(__2p++))) = '_';
            ((*(__2p++))) = 'X';
            strcpy(__2p, __1vn);
            __2p += __2ll;
            ((*(__2p++))) = '0';
            ((*(__2p++))) = '0';

            while (__2a) {
                ((*(__2p++))) = ("abcdefghijklmnopqrstuvwxyz012345"[(__2a & 037)]);
                __2a >>= 5;
            }

            ((*(__2p++))) = ("abcdefghijlkmnop"[(((((unsigned long)Scope)) >> 4) & 15)]);
            ((*(__2p++))) = ("abcdefghijlkmnop"[(((((unsigned long)Scope)) >> 8) & 15)]);
            ((*__2p)) = '\0';

            return (const char *)__2s;
        }
    } else {
        return __1vn;
    }
}

Plist inllist = 0;

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

extern char *make_name__FUc(TOK);

extern Ptype unconst_type__FP4type(Ptype);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

struct name_list *__ct__9name_listFP4nameP9name_list(struct name_list *__0this, Pname __1ff,
                                                     Plist __1ll);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

Pname dcl_local__FP5tableP4nameT2Uc(Ptable __1scope, Pname __1an, Pname __1fn, bit __1tempflag) {
    const char *__1s;

    if ((__1scope == 0) || (__1scope->base__4node == 0)) {
        if (sti_tbl == 0)
            sti_tbl =
                __ct__5tableFsP5tableP4name((struct table *)0, (short)8, gtbl, (struct name *)0);
        __1scope = sti_tbl;
    }

    if (__1an->n_stclass__4name == 31) {
        if ((__1an->__O1__4expr.tp->base__4node != 108) &&
            (__1an->__O1__4expr.tp->base__4node != 76)) {
            struct ea __0__V17;

            error__FiP3locPCcRC2eaN34(
                (int)'s', &__1fn->where__4name, (const char *)"cannot expand inlineF with static%n",
                (const struct ea *)(((&__0__V17)->__O1__2ea.p = ((const void *)__1an)),
                                    (&__0__V17)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        return __1an;
    }

    ;
    if (__1tempflag)
        __1s = (const char *)make_name__FUc((unsigned char)'X');
    else
        __1s = temp__FPCcP4name(__1an->__O2__4expr.string, __1fn);
    {
        Pname __1nx;
        Ptype __1atp;

        __1nx = __ct__4nameFPCc((struct name *)0, __1s);
        __1atp = __1an->__O1__4expr.tp;

        while (__1atp->base__4node == 97)
            __1atp = (((struct basetype *)(((struct basetype *)__1atp))))
                         ->b_name__8basetype->__O1__4expr.tp;
        if (__1atp->base__4node == 110) {
            if (__1an->n_scope__4name == 136) {
                Pptr __3t;

                __3t = __ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125,
                                           (((struct vec *)(((struct vec *)__1atp))))->typ__5pvtyp);
                __1nx->__O1__4expr.tp = (struct type *)__3t;
            } else {
                error__FiP3locPCcRC2eaN34(
                    (int)'s', &__1fn->where__4name,
                    (const char *)"cannot expand inlineF needing temporaryV of arrayT",
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0,
                    (const struct ea *)ea0);
                return __1an;
            }
        } else
            __1nx->__O1__4expr.tp = __1atp;
        __1nx->__O1__4expr.tp = unconst_type__FP4type(__1nx->__O1__4expr.tp);
        __1nx->__O1__4expr.tp->permanent__4node = 1;

        __1nx->n_used__4name = __1an->n_used__4name;
        __1nx->n_assigned_to__4name = __1an->n_assigned_to__4name;
        __1nx->n_addr_taken__4name = __1an->n_addr_taken__4name;
        __1nx->n_xref__4name = __1an->n_xref__4name;

        {
            Pname __1r;

            __1r = look__5tableFPCcUc(__1scope, __1nx->__O2__4expr.string, (unsigned char)0);
            if (__1r) {
                if (check__4typeFP4typeUcT2(__1r->__O1__4expr.tp, __1nx->__O1__4expr.tp,
                                            (unsigned char)0, (unsigned char)0)) {
                    struct ea __0__V18;

                    struct ea __0__V19;

                    error__FiP3locPCcRC2eaN34(
                        (int)'s', &__1fn->where__4name,
                        (const char *)"cannot expand inlineF %a with two local variables with the "
                                      "sameN (%s)",
                        (const struct ea *)(((&__0__V18)->__O1__2ea.p = ((const void *)__1fn)),
                                            (&__0__V18)),
                        (const struct ea *)__ct__2eaFPCv(&__0__V19,
                                                         (const void *)__1an->__O2__4expr.string),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                } else
                    __1r = 0;
            }
            if (__1r == 0) {
                __1r = insert__5tableFP4nameUc(__1scope, __1nx, (unsigned char)0);

                if (__1r->__O1__4expr.tp->base__4node == 119)
                    inllist =
                        __ct__9name_listFP4nameP9name_list((struct name_list *)0, __1r, inllist);

                __1r->n_stclass__4name = __1an->n_stclass__4name;
                __1r->lex_level__4name = __1an->lex_level__4name;
                ((__1nx ? (((void)(__1nx ? (((void)((((((struct expr *)__1nx))
                                                          ? (((void)((((struct expr *)__1nx))
                                                                         ? (((void)(((void)0))))
                                                                         : (((void)0)))))
                                                          : (((void)0)))),
                                                    (((void)__dl__4nameSFPvUl(
                                                        (void *)__1nx,
                                                        (size_t)(sizeof(struct name))))))))
                                         : (((void)0)))))
                        : (((void)0))));
                __1r->where__4name.line__3loc = 0;
            }
            return __1r;
        }
    }
}

int ck_cast__FP4typeT1(Ptype __1t1, Ptype __1t2) {
st:
    while (__1t1->base__4node == 97)
        __1t1 =
            (((struct basetype *)(((struct basetype *)__1t1))))->b_name__8basetype->__O1__4expr.tp;
    while (__1t2->base__4node == 97)
        __1t2 =
            (((struct basetype *)(((struct basetype *)__1t2))))->b_name__8basetype->__O1__4expr.tp;

    if (__1t1 == __1t2)
        return 0;

    if (__1t1->base__4node != __1t2->base__4node)
        return 1;

    switch (__1t1->base__4node) {
    case 158:
    case 125: {
        __1t1 = (((struct ptr *)(((struct ptr *)__1t1))))->typ__5pvtyp;
        if (__1t1->base__4node == 38)
            return 1;
        __1t2 = (((struct ptr *)(((struct ptr *)__1t2))))->typ__5pvtyp;
        goto st;
    }
    case 5:
    case 29:
    case 21:
    case 22:
    case 122:
        if ((((struct basetype *)(((struct basetype *)__1t1))))->b_unsigned__8basetype !=
            (((struct basetype *)(((struct basetype *)__1t2))))->b_unsigned__8basetype)
            return 1;
        break;
    case 119: {
        Pname __3nn;

        __3nn = (((struct basetype *)(((struct basetype *)__1t1))))->b_name__8basetype;

        if ((((struct classdef *)(((struct classdef *)__3nn->__O1__4expr.tp))))->csu__8classdef ==
            36)
            return 0;

        if ((__1t2->base__4node == 119) &&
            (__3nn->__O1__4expr.tp == (((struct basetype *)(((struct basetype *)__1t2))))
                                          ->b_name__8basetype->__O1__4expr.tp))
            return 0;

        return 1;
    }
    }

    return 0;
}

int makeCM__FP4type(Ptype __1t) {
    while (__1t->base__4node == 97)
        __1t =
            (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp;

    switch (__1t->base__4node) {
    case 15:
    case 11:
    case 181:
    case 5:
    case 29:
    case 21:
    case 22:
    case 122:
    case 121:
        return 0;

    default:
        return 1;
    }
}

static int ret_seen = 0;

static int has_return__FP4stmt(Pstmt __1sl);

static int has_return__FP4stmt(Pstmt __1sl) {
    int __1hr;

    if (!__1sl)
        return 0;
    __1hr = 0;
    {
        {
            Pstmt __1s;

            __1s = __1sl;

            for (; __1s; __1s = __1s->s_list__4stmt) {
                switch (__1s->base__4node) {
                case 39:
                case 10:
                case 16:
                case 33:
                case 116:
                case 115:
                case 4:
                case 8:
                    __1hr = has_return__FP4stmt(__1s->s__4stmt);
                    break;
                case 20:
                    __1hr = has_return__FP4stmt(__1s->s__4stmt);
                    __1hr = (__1hr || has_return__FP4stmt(__1s->__O3__4stmt.else_stmt));
                    break;
                case 166:
                    __1hr = has_return__FP4stmt(__1s->s__4stmt);
                    __1hr = (__1hr || has_return__FP4stmt(__1s->__O2__4stmt.s2));
                    break;
                case 28:
                    if (__1s->__O2__4stmt.e && (__1s->__O2__4stmt.e != dummy))
                        __1hr = 1;
                    break;
                }
                if (__1hr)
                    return 1;
            }

            return 0;
        }
    }
}

Pstmt expand__4stmtFv(struct stmt *__0this);

Pexpr expand__4exprFv(struct expr *__0this);

Pfct memptr__4typeFv(struct type *__0this);

Pname is_cl_obj__4typeFv(struct type *__0this);

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);

Pstmt expand__4stmtFv(register struct stmt *__0this) {
    const void *__2__X25;

    if (__0this == 0) {
        struct ea __0__V20;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"0->S::expand() for%n",
            (const struct ea *)((__2__X25 = (const void *)expand_fn),
                                (((&__0__V20)->__O1__2ea.p = __2__X25), (&__0__V20))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    {
        Pstmt __1ostmt;

        __1ostmt = Cstmt;
        if (__0this->where__4stmt.line__3loc)
            Cstmt = __0this;

        if (__0this->memtbl__4stmt) {
            Ptable __2t;
            int __2i;

            __2t = __0this->memtbl__4stmt;

            {
                {
                    Pname __2n;

                    int __2__X26;

                    int __2__X27;

                    __2n = ((__2__X27 = (__2i = 1)),
                            ((((__2__X27 <= 0) || (__2t->free_slot__5table <= __2__X27))
                                  ? (((struct name *)0))
                                  : (__2t->entries__5table[__2__X27]))));

                    for (; __2n;
                         __2n = (__2n->n_tbl_list__4name
                                     ? __2n->n_tbl_list__4name
                                     : ((__2__X26 = (++__2i)),
                                        ((((__2__X26 <= 0) || (__2t->free_slot__5table <= __2__X26))
                                              ? (((struct name *)0))
                                              : (__2t->entries__5table[__2__X26])))))) {
                        if (__2n->n_stclass__4name == 31) {
                            if ((__2n->__O1__4expr.tp->base__4node == 108) ||
                                (__2n->__O1__4expr.tp->base__4node == 76))
                                continue;
                            {
                                struct ea __0__V21;

                                error__FiPCcRC2eaN33(
                                    (int)'s', (const char *)"cannot expand inlineF with static%n",
                                    (const struct ea *)(((&__0__V21)->__O1__2ea.p =
                                                             ((const void *)__2n)),
                                                        (&__0__V21)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                __2n->n_stclass__4name = 2;
                            }
                        }
                        __2n->where__4name.line__3loc = 0;
                    }
                }
            }
        }

        if (expand_tbl) {
            Pexpr __2ee;

            if (__0this->memtbl__4stmt) {
                int __3i;
                {
                    {
                        Pname __3n;

                        struct table *__0__X28;

                        int __2__X29;

                        struct table *__0__X30;

                        int __2__X31;

                        __3n = ((__0__X30 = __0this->memtbl__4stmt),
                                ((__2__X31 = (__3i = 1)),
                                 ((((__2__X31 <= 0) || (__0__X30->free_slot__5table <= __2__X31))
                                       ? (((struct name *)0))
                                       : (__0__X30->entries__5table[__2__X31])))));

                        for (; __3n;
                             __3n = (__3n->n_tbl_list__4name
                                         ? __3n->n_tbl_list__4name
                                         : ((__0__X28 = __0this->memtbl__4stmt),
                                            ((__2__X29 = (++__3i)),
                                             ((((__2__X29 <= 0) ||
                                                (__0__X28->free_slot__5table <= __2__X29))
                                                   ? (((struct name *)0))
                                                   : (__0__X28->entries__5table[__2__X29]))))))) {
                            if (((__3n->base__4node != 85) ||
                                 (__3n->__O1__4expr.tp == (((struct type *)any_type)))) ||
                                (__3n->n_key__4name == 6))
                                continue;

                            if ((((__0this->base__4node == 116) &&
                                  (__0this->memtbl__4stmt->real_block__5table == __0this)) &&
                                 (__3n->lex_level__4name < 2)) &&
                                ((((__3n->__O2__4expr.string[0]) != '_') ||
                                  ((__3n->__O2__4expr.string[1]) != '_')) ||
                                 (((__3n->__O2__4expr.string[2]) != 'X') &&
                                  ((__3n->__O2__4expr.string[2]) != 'K')))) {
                                continue;
                            }

                            if (__0this->memtbl__4stmt != scope) {
                                Pname __5nn;

                                __5nn = dcl_local__FP5tableP4nameT2Uc(scope, __3n, expand_fn,
                                                                      (unsigned char)0);
                                __5nn->base__4node = 85;
                                __3n->__O2__4expr.string = __5nn->__O2__4expr.string;
                            } else if ((__3n->__O1__4expr.tp &&
                                        (__3n->__O1__4expr.tp->base__4node != 108)) &&
                                       (__3n->__O1__4expr.tp->base__4node != 76)) {
                                __3n->__O2__4expr.string =
                                    temp__FPCcP4name(__3n->__O2__4expr.string, expand_fn);
                                __3n->where__4name.line__3loc = 0;
                            }
                        }
                    }
                }
            }

            switch (__0this->base__4node) {
                const void *__2__X32;

                unsigned long __2__X33;

            default: {
                struct ea __0__V22;

                struct ea __0__V23;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"cannot expand inlineF%a with %kS in inline",
                    (const struct ea *)((__2__X32 = (const void *)expand_fn),
                                        (((&__0__V22)->__O1__2ea.p = __2__X32), (&__0__V22))),
                    (const struct ea *)((__2__X33 = __0this->base__4node),
                                        (((((&__0__V23)->__O1__2ea.i = __2__X33), 0)),
                                         (&__0__V23))),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                Cstmt = __1ostmt;
                return (((struct stmt *)(((struct stmt *)dummy))));

            case 116:;
                if (__0this->s_list__4stmt) {
                    __2ee = ((
                        (struct expr *)(((struct expr *)expand__4stmtFv(__0this->s_list__4stmt)))));
                    if (__0this->s__4stmt) {
                        __2ee = __ct__4exprFUcP4exprT2(
                            (struct expr *)0, (unsigned char)71,
                            ((struct expr *)(((struct expr *)expand__4stmtFv(__0this->s__4stmt)))),
                            __2ee);
                        __2ee->__O1__4expr.tp = __2ee->__O3__4expr.e2->__O1__4expr.tp;
                        __2ee->permanent__4node = 1;
                    }
                    Cstmt = __1ostmt;
                    return (((struct stmt *)(((struct stmt *)__2ee))));
                }

                if (__0this->s__4stmt) {
                    Pstmt __4st;

                    __4st = expand__4stmtFv(__0this->s__4stmt);
                    Cstmt = __1ostmt;
                    return __4st;
                }

                Cstmt = __1ostmt;
                return (((struct stmt *)(((struct stmt *)zero))));

            case 166:
                __2ee = (__0this->__O2__4stmt.s2
                             ? (((struct expr *)((
                                   (struct expr *)expand__4stmtFv(__0this->__O2__4stmt.s2)))))
                             : (((struct expr *)0)));
                __2ee = __ct__4exprFUcP4exprT2(
                    (struct expr *)0, (unsigned char)71,
                    __0this->s__4stmt
                        ? (((struct expr *)(((struct expr *)expand__4stmtFv(__0this->s__4stmt)))))
                        : (((struct expr *)0)),
                    __2ee);
                __2ee->__O1__4expr.tp = __2ee->__O3__4expr.e2->__O1__4expr.tp;
                if (__0this->s_list__4stmt) {
                    __2ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, __2ee,
                                                   ((struct expr *)(((struct expr *)expand__4stmtFv(
                                                       __0this->s_list__4stmt)))));
                    __2ee->__O1__4expr.tp = __2ee->__O3__4expr.e2->__O1__4expr.tp;
                }
                __2ee->permanent__4node = 1;
                Cstmt = __1ostmt;
                return (((struct stmt *)(((struct stmt *)__2ee))));

            case 28:
                ret_seen = 1;
                __0this->s_list__4stmt = 0;

                if (__0this->__O2__4stmt.e == 0)
                    __2ee = zero;
                else {
                    __2ee = expand__4exprFv(__0this->__O2__4stmt.e);
                    {
                        Ptype __4tt;

                        register struct cast *__0__X34;

                        __4tt = (((struct fct *)(((struct fct *)expand_fn->__O1__4expr.tp))))
                                    ->s_returns__3fct;
                        if (__4tt == 0)
                            __4tt = (((struct fct *)(((struct fct *)expand_fn->__O1__4expr.tp))))
                                        ->returns__3fct;

                        if ((__4tt != __2ee->__O1__4expr.tp) &&
                            ck_cast__FP4typeT1(__4tt, __2ee->__O1__4expr.tp))
                            __2ee =
                                (struct expr
                                     *)((__0__X34 = 0),
                                        (((__0__X34 || (__0__X34 = (struct cast *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct cast)))))
                                              ? ((__0__X34 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                      ((struct expr *)__0__X34), (unsigned char)191,
                                                      __2ee, (struct expr *)0)),
                                                 (__0__X34->__O1__4expr.tp =
                                                      (__0__X34->__O4__4expr.tp2 = __4tt)))
                                              : 0),
                                         __0__X34));
                    }
                }

                Cstmt = __1ostmt;
                return (((struct stmt *)(((struct stmt *)__2ee))));

            case 72:
                if ((__0this->__O2__4stmt.e == 0) || (__0this->__O2__4stmt.e == dummy))
                    __2ee = zero;
                else {
                    if (__0this->__O2__4stmt.e->base__4node == 111)
                        __0this->__O2__4stmt.e = __0this->__O2__4stmt.e->__O2__4expr.e1;
                    __2ee = expand__4exprFv(__0this->__O2__4stmt.e);
                }
                if (__0this->s_list__4stmt) {
                    __2ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, __2ee,
                                                   ((struct expr *)(((struct expr *)expand__4stmtFv(
                                                       __0this->s_list__4stmt)))));
                    __2ee->__O1__4expr.tp = __2ee->__O3__4expr.e2->__O1__4expr.tp;
                    __2ee->permanent__4node = 1;
                }
                Cstmt = __1ostmt;
                return (((struct stmt *)(((struct stmt *)__2ee))));

            case 1:
                error__FiPCc((int)'s', (const char *)"asm() in value-returning inline");
                return __0this;

            case 20: {
                int __4ors;

                __4ors = ret_seen;
                ret_seen = 0;
                __2ee = (((struct expr *)(((struct expr *)expand__4stmtFv(__0this->s__4stmt)))));
                if ((__2ee->__O1__4expr.tp && memptr__4typeFv(__2ee->__O1__4expr.tp)) ||
                    (((__2ee->base__4node == 70) && __2ee->__O2__4expr.e1->__O1__4expr.tp) &&
                     (__2ee->__O2__4expr.e1->__O1__4expr.tp->base__4node != 125)))
                    __2ee =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147, __2ee, zero);
                {
                    Pexpr __4qq;
                    int __4ret1;

                    __4qq =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)68, __2ee, zero);
                    __4ret1 = ret_seen;
                    ret_seen = 0;

                    __4qq->__O4__4expr.cond = expand__4exprFv(__0this->__O2__4stmt.e);
                    __4qq->__O3__4expr.e2 =
                        (__0this->__O3__4stmt.else_stmt
                             ? (((struct expr *)(((struct expr *)expand__4stmtFv(
                                   __0this->__O3__4stmt.else_stmt)))))
                             : zero);
                    if (((((!has_return__FP4stmt(__0this->s__4stmt)) &&
                           (!has_return__FP4stmt(__0this->__O3__4stmt.else_stmt))) &&
                          __4qq->__O2__4expr.e1->__O1__4expr.tp) &&
                         __4qq->__O3__4expr.e2->__O1__4expr.tp) &&
                        check__4typeFP4typeUcT2(__4qq->__O2__4expr.e1->__O1__4expr.tp,
                                                __4qq->__O3__4expr.e2->__O1__4expr.tp,
                                                (unsigned char)70, (unsigned char)0)) {
                        register struct cast *__0__X35;

                        struct type *__2__X36;

                        struct expr *__2__X37;

                        register struct cast *__0__X38;

                        struct type *__2__X39;

                        struct expr *__2__X40;

                        __4qq->__O2__4expr.e1 =
                            (struct expr
                                 *)((__0__X35 = 0),
                                    ((__2__X36 = (struct type *)void_type),
                                     ((__2__X37 = __4qq->__O2__4expr.e1),
                                      (((__0__X35 || (__0__X35 = (struct cast *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct cast)))))
                                            ? ((__0__X35 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X35), (unsigned char)191,
                                                    __2__X37, (struct expr *)0)),
                                               (__0__X35->__O1__4expr.tp =
                                                    (__0__X35->__O4__4expr.tp2 = __2__X36)))
                                            : 0),
                                       __0__X35))));
                        __4qq->__O3__4expr.e2 =
                            (struct expr
                                 *)((__0__X38 = 0),
                                    ((__2__X39 = (struct type *)void_type),
                                     ((__2__X40 = __4qq->__O3__4expr.e2),
                                      (((__0__X38 || (__0__X38 = (struct cast *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct cast)))))
                                            ? ((__0__X38 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X38), (unsigned char)191,
                                                    __2__X40, (struct expr *)0)),
                                               (__0__X38->__O1__4expr.tp =
                                                    (__0__X38->__O4__4expr.tp2 = __2__X39)))
                                            : 0),
                                       __0__X38))));
                    }

                    {
                        int __4ret2;

                        __4ret2 = ret_seen;
                        if ((__4ret1 + __4ret2) && __0this->s_list__4stmt) {
                            const void *__2__X41;

                            {
                                struct ea __0__V24;

                                error__FiPCcRC2eaN33(
                                    (int)'s',
                                    (const char *)"cannot expand inlineF%a with S after \"return\"",
                                    (const struct ea *)((__2__X41 = (const void *)expand_fn),
                                                        (((&__0__V24)->__O1__2ea.p = __2__X41),
                                                         (&__0__V24))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                ret_seen = 0;
                            }
                        }
                        ret_seen += __4ret1;
                        ret_seen += __4ret2;
                        ret_seen += __4ors;

                        {
                            Ptype __4t1;

                            __4t1 = __4qq->__O2__4expr.e1->__O1__4expr.tp;
                            if (__4qq->__O2__4expr.e1->base__4node == 147)
                                __4t1 = __4qq->__O2__4expr.e1->__O3__4expr.e2->__O1__4expr.tp;
                            {
                                Ptype __4t2;

                                __4t2 = __4qq->__O3__4expr.e2->__O1__4expr.tp;

                                if (__4t1 && (__4t1->base__4node == 108))
                                    __4t1 =
                                        ((((struct fct *)(((struct fct *)__4t1))))->s_returns__3fct
                                             ? (((struct fct *)(((struct fct *)__4t1))))
                                                   ->s_returns__3fct
                                             : (((struct fct *)(((struct fct *)__4t1))))
                                                   ->returns__3fct);

                                if (__4t2 && (__4t2->base__4node == 108))
                                    __4t2 =
                                        ((((struct fct *)(((struct fct *)__4t2))))->s_returns__3fct
                                             ? (((struct fct *)(((struct fct *)__4t2))))
                                                   ->s_returns__3fct
                                             : (((struct fct *)(((struct fct *)__4t2))))
                                                   ->returns__3fct);

                                {
                                    Pname __4c1;
                                    Pname __4c2;

                                    int __4z1;
                                    int __4z2;

                                    __4c1 =
                                        (__4t1 ? is_cl_obj__4typeFv(__4t1) : (((struct name *)0)));
                                    __4c2 =
                                        (__4t2 ? is_cl_obj__4typeFv(__4t2) : (((struct name *)0)));

                                    __4z1 = (__4c1 && (__4c1 != __4c2));
                                    __4z2 = (__4c2 && (__4c1 != __4c2));

                                    if ((((((__4c1 == 0) && (__4c2 == 0)) && __4t1) && __4t2) &&
                                         check__4typeFP4typeUcT2(__4t2, __4t1, (unsigned char)70,
                                                                 (unsigned char)0)) &&
                                        check__4typeFP4typeUcT2(__4t1, __4t2, (unsigned char)70,
                                                                (unsigned char)0)) {
                                        __4z1 = makeCM__FP4type(__4t1);
                                        __4z2 = makeCM__FP4type(__4t2);
                                        if ((__4z1 && __4ret1) || (__4z2 && __4ret2))
                                            error__FiPCc(
                                                (int)'s',
                                                (const char
                                                     *)"cannot expand inlineF with return in ifS");
                                    }

                                    if (__4t1 && (__4z1 == 0)) {
                                        __4z1 = ((((is_ptr_or_ref__4typeFv(__4t1) && __4t2) &&
                                                   is_ptr_or_ref__4typeFv(__4t2)) &&
                                                  check__4typeFP4typeUcT2(__4t1, __4t2,
                                                                          (unsigned char)0,
                                                                          (unsigned char)0)) &&
                                                 (!const_problem));
                                    }

                                    if (__4z1) {
                                        Pexpr __5v;

                                        register struct cast *__0__X42;

                                        struct expr *__2__X43;

                                        __5v =
                                            ((((__4z2 == 0) && __4t2) &&
                                              is_ptr_or_ref__4typeFv(__4t2))
                                                 ? (((struct expr
                                                          *)((__0__X42 = 0),
                                                             ((__2__X43 = zero),
                                                              (((__0__X42 ||
                                                                 (__0__X42 = (struct cast *)
                                                                      __nw__4exprSFUl(
                                                                          (size_t)(sizeof(
                                                                              struct cast)))))
                                                                    ? ((__0__X42 = (struct cast *)
                                                                            __ct__4exprFUcP4exprT2(
                                                                                ((struct expr *)
                                                                                     __0__X42),
                                                                                (unsigned char)191,
                                                                                __2__X43,
                                                                                (struct expr *)0)),
                                                                       (__0__X42->__O1__4expr.tp =
                                                                            (__0__X42->__O4__4expr
                                                                                 .tp2 = __4t2)))
                                                                    : 0),
                                                               __0__X42)))))
                                                 : zero);
                                        __4qq->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)71,
                                            __4qq->__O2__4expr.e1, __5v);
                                        __4qq->__O2__4expr.e1->__O1__4expr.tp =
                                            __4qq->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp;
                                    }

                                    if (__4z2) {
                                        Pexpr __5v;

                                        register struct cast *__0__X44;

                                        struct expr *__2__X45;

                                        __5v =
                                            ((((__4z1 == 0) && __4t1) &&
                                              is_ptr_or_ref__4typeFv(__4t1))
                                                 ? (((struct expr
                                                          *)((__0__X44 = 0),
                                                             ((__2__X45 = zero),
                                                              (((__0__X44 ||
                                                                 (__0__X44 = (struct cast *)
                                                                      __nw__4exprSFUl(
                                                                          (size_t)(sizeof(
                                                                              struct cast)))))
                                                                    ? ((__0__X44 = (struct cast *)
                                                                            __ct__4exprFUcP4exprT2(
                                                                                ((struct expr *)
                                                                                     __0__X44),
                                                                                (unsigned char)191,
                                                                                __2__X45,
                                                                                (struct expr *)0)),
                                                                       (__0__X44->__O1__4expr.tp =
                                                                            (__0__X44->__O4__4expr
                                                                                 .tp2 = __4t1)))
                                                                    : 0),
                                                               __0__X44)))))
                                                 : zero);
                                        __4qq->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)71,
                                            __4qq->__O3__4expr.e2, __5v);
                                        __4qq->__O3__4expr.e2->__O1__4expr.tp =
                                            __4qq->__O3__4expr.e2->__O2__4expr.e1->__O1__4expr.tp;
                                    }

                                    if (__0this->s_list__4stmt) {
                                        __4qq = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)71, __4qq,
                                            ((struct expr *)(((struct expr *)expand__4stmtFv(
                                                __0this->s_list__4stmt)))));
                                        __4qq->__O1__4expr.tp =
                                            __4qq->__O3__4expr.e2->__O1__4expr.tp;
                                    } else
                                        __4qq->__O1__4expr.tp =
                                            __4qq->__O2__4expr.e1->__O1__4expr.tp;
                                    __4qq->permanent__4node = 1;
                                    Cstmt = __1ostmt;
                                    return (((struct stmt *)(((struct stmt *)__4qq))));
                                }
                            }
                        }
                    }
                }
            }
            }
            }
        }

        __0this->where__4stmt.line__3loc = 0;

        switch (__0this->base__4node) {
        default:
            if (__0this->__O2__4stmt.e)
                __0this->__O2__4stmt.e = expand__4exprFv(__0this->__O2__4stmt.e);
            break;
        case 166:
            if (__0this->__O2__4stmt.s2)
                __0this->__O2__4stmt.s2 = expand__4stmtFv(__0this->__O2__4stmt.s2);
            break;
        case 116:
            break;
        case 16:
            if (__0this->__O3__4stmt.for_init)
                __0this->__O3__4stmt.for_init = expand__4stmtFv(__0this->__O3__4stmt.for_init);
            if (__0this->__O1__4stmt.e2)
                __0this->__O1__4stmt.e2 = expand__4exprFv(__0this->__O1__4stmt.e2);
        case 1:
            break;
        case 115:
        case 19: {
            char *__3s;

            __3s = (((char *)__nw__FUl(
                (size_t)((sizeof(char)) *
                         (strlen(__0this->__O1__4stmt.d->__O2__4expr.string) + 1)))));
            strcpy(__3s, __0this->__O1__4stmt.d->__O2__4expr.string);
            __0this->__O1__4stmt.d->__O2__4expr.string = (const char *)__3s;
            break;
        }
        }

        if (__0this->s__4stmt)
            __0this->s__4stmt = expand__4stmtFv(__0this->s__4stmt);
        if (__0this->s_list__4stmt)
            __0this->s_list__4stmt = expand__4stmtFv(__0this->s_list__4stmt);
        __0this->permanent__4node = 1;
        Cstmt = __1ostmt;
        return __0this;
    }
}

Pexpr expand__4exprFv(register struct expr *__0this) {
    if (__0this == 0)
        error__FiPCc((int)'i', (const char *)"E::expand(0)");

    switch (__0this->base__4node) {
    case 85:
        if ((expand_tbl &&
             ((((struct name *)(((struct name *)__0this))))->n_scope__4name == 108)) &&
            ((((struct name *)(((struct name *)__0this))))->lex_level__4name >
             expand_fn->lex_level__4name)) {
            Pname __3n;
            const char *__3s;

            __3n = (((struct name *)(((struct name *)__0this))));
            __3s = __3n->__O2__4expr.string;
            if ((((__3s[0]) == '_') && ((__3s[1]) == '_')) &&
                (((__3s[2]) == 'X') || ((__3s[2]) == 'K')))
                break;

            __3n->__O2__4expr.string = temp__FPCcP4name(__3s, expand_fn);
        }
    case 144:
    case 162:
    case 82:
    case 83:
    case 84:
    case 150:
    case 81:
    case 86:
    case 165:
    case 169:
    case 177:
        break;
    case 168:
        if (expand_tbl && (__0this->__O2__4expr.e1 == 0)) {
            int __3ors;

            __3ors = ret_seen;
            ret_seen = 0;
            {
                Pname __3fn;
                Pfct __3f;

                const void *__2__X48;

                __3fn = __0this->__O4__4expr.il->fct_name__5iline;
                __3f = (((struct fct *)(((struct fct *)__3fn->__O1__4expr.tp))));
                if (__3f->f_expr__3fct == 0) {
                    struct ea __0__V46;

                    struct ea __0__V47;

                    error__FiP3locPCcRC2eaN34(
                        (int)'s', &__3fn->where__4name,
                        (const char *)"cannot expand value-returning inline%a with call of "
                                      "non-value-returning inline%a",
                        (const struct ea *)((__2__X48 = (const void *)expand_fn),
                                            (((&__0__V46)->__O1__2ea.p = __2__X48), (&__0__V46))),
                        (const struct ea *)(((&__0__V47)->__O1__2ea.p = ((const void *)__3fn)),
                                            (&__0__V47)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
                ret_seen = __3ors;
            }
        }
        break;
    case 30:
    case 113:
    case 191:
        if (__0this->__O4__4expr.tp2)
            __0this->__O4__4expr.tp2->permanent__4node = 1;
        goto rrr;
    case 68:
        __0this->__O4__4expr.cond = expand__4exprFv(__0this->__O4__4expr.cond);
    default:
        if (__0this->__O3__4expr.e2)
            __0this->__O3__4expr.e2 = expand__4exprFv(__0this->__O3__4expr.e2);
    case 44:
    case 45:
    rrr:
        if (__0this->__O2__4expr.e1)
            __0this->__O2__4expr.e1 = expand__4exprFv(__0this->__O2__4expr.e1);
        break;
    }

    switch (__0this->base__4node) {
    case 71:
    case 147:
        if (__0this->__O1__4expr.tp == 0)
            __0this->__O1__4expr.tp = __0this->__O3__4expr.e2->__O1__4expr.tp;
    }

    __0this->permanent__4node = 1;
    return __0this;
}

int nin = 0;

static int watch_out;
bit not_simple__4exprFi(struct expr *__0this, int __1inflag);

bit not_simple__4exprFi(register struct expr *__0this, int __1inflag) {
    int __1s;

    switch (__0this->base__4node) {
    default:
        return (unsigned char)2;
    case 85:
        if ((nin == 0) &&
            ((((struct name *)(((struct name *)__0this))))->__O4__4expr.n_table == gtbl))
            return (unsigned char)2;
    case 86:
    case 150:
    case 82:
    case 84:
    case 83:
        return (unsigned char)0;
    case 81:
        watch_out = 1;
        return (unsigned char)0;
    case 177:
        return not_simple__4exprFi(__0this->__O4__4expr.mem, __1inflag);
    case 30:
        return (
            unsigned char)(((__0this->__O2__4expr.e1 == 0) || (__0this->__O2__4expr.e1 == dummy))
                               ? 0
                               : (((int)not_simple__4exprFi(__0this->__O2__4expr.e1, __1inflag))));
    case 145:
    case 112:
        return not_simple__4exprFi(__0this->__O3__4expr.e2, __1inflag);
    case 113:
    case 191:
        return not_simple__4exprFi(__0this->__O2__4expr.e1, __1inflag);
    case 45:
    case 44:
        watch_out = 1;
        if (!__1inflag)
            return not_simple__4exprFi(__0this->__O2__4expr.e1, __1inflag);
        else
            return (unsigned char)2;
    case 107:
    case 46:
    case 47:
        return not_simple__4exprFi(__0this->__O3__4expr.e2, __1inflag);
    case 111:
        __1s = not_simple__4exprFi(__0this->__O2__4expr.e1, __1inflag);
        if (1 < __1s)
            return (unsigned char)2;
        if (__0this->__O3__4expr.e2 == 0)
            return (unsigned char)__1s;
        return (unsigned char)(__1s |= not_simple__4exprFi(__0this->__O3__4expr.e2, __1inflag));
    case 50:
    case 51:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 52:
    case 65:
    case 64:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 66:
    case 67:
    case 71:
        __1s = not_simple__4exprFi(__0this->__O2__4expr.e1, __1inflag);
        if (1 < __1s)
            return (unsigned char)2;
        return (unsigned char)(__1s |= not_simple__4exprFi(__0this->__O3__4expr.e2, __1inflag));
    case 68:
        __1s = not_simple__4exprFi(__0this->__O4__4expr.cond, __1inflag);
        if (1 < __1s)
            return (unsigned char)2;
        __1s |= not_simple__4exprFi(__0this->__O2__4expr.e1, __1inflag);
        if (1 < __1s)
            return (unsigned char)2;
        return (unsigned char)(__1s |= not_simple__4exprFi(__0this->__O3__4expr.e2, __1inflag));
    case 169:
        if (curr_icall) {
            Pname __3n;
            int __3argno;
            Pin __3il;

            __3n = (((struct name *)(((struct name *)__0this))));
            __3argno = (((int)__3n->n_val__4name));
            __3il = curr_icall;
            for (; __3il; __3il = __3il->i_next__5iline)
                if (__3n->__O4__4expr.n_table == __3il->i_table__5iline)
                    goto aok;
            goto bok;
        aok:
            return (
                unsigned char)((__3il->i_args__5iline[__3argno]).local__2ia
                                   ? 0
                                   : (((int)not_simple__4exprFi(
                                         (__3il->i_args__5iline[__3argno]).arg__2ia, __1inflag))));
        }
    bok: {
        struct ea __0__V49;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"expand aname%n",
            (const struct ea *)(((&__0__V49)->__O1__2ea.p = ((const void *)__0this)), (&__0__V49)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    case 147:
    case 157:
    case 23:
    case 184:
    case 109:
    case 146:
    case 168:
    case 70:
    case 48:
    case 49:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
    case 131:
    case 132:
    case 133:
    case 134:
    case 135:
        return (unsigned char)2;
    }
    }
}

extern Pstmt del_list;
extern Pstmt break_del_list;
extern Pstmt continue_del_list;
extern Pname curr_fct;
extern Pexpr init_list;

Pname make_itor__8classdefFi(struct classdef *__0this, int);

void expand_itor__FP8classdef(Pclass __1cl) {
    Pexpr __1s2;
    Pstmt __1s5;
    Pstmt __1s6;
    Pstmt __1s7;
    Pname __1s8;
    Pexpr __1s9;

    __1s2 = curr_expr;
    __1s5 = del_list;
    __1s6 = break_del_list;
    __1s7 = continue_del_list;
    __1s8 = curr_fct;
    __1s9 = init_list;
    ((void)make_itor__8classdefFi(__1cl, 1));
    curr_expr = __1s2;
    del_list = __1s5;
    break_del_list = __1s6;
    continue_del_list = __1s7;
    curr_fct = __1s8;
    init_list = __1s9;
}

extern void uninline__FP4name(Pname __0fn);

Pexpr expand__3fctFP4nameP5tableP4expr(struct fct *__0this, Pname __1fn, Ptable __1scope,
                                       Pexpr __1ll);

void dcl_print__4nameFUc(struct name *__0this, TOK);

void print_all_vtbls__8classdefFP8classdef(struct classdef *__0this, Pclass);

extern int strcmp(const char *, const char *);

Pptr is_ptr__4typeFv(struct type *__0this);

extern Pexpr mptr_assign__FP4exprT1(Pexpr, Pexpr);

static struct ia *__ct__2iaFv(struct ia *__0this);

extern void __dl__FPv(void *);

Pexpr expand__3fctFP4nameP5tableP4expr(register struct fct *__0this, Pname __1fn, Ptable __1scope,
                                       Pexpr __1ll) {
    Scope = __1scope;

    if (__0this->f_inline__3fct == 77) {
        Pexpr __2s1;

        __2s1 = __0this->last_expanded__3fct;
        expand_itor__FP8classdef(__0this->memof__3fct);
        __0this->last_expanded__3fct = __2s1;
        __0this->last_stmt__3fct = stmtno;

        {
            Pfct __2nf;

            __2nf = (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))));
            if ((__2nf->f_inline__3fct == 0) && __2nf->f_imeasure__3fct) {
                uninline__FP4name(__1fn);
                return (struct expr *)0;
            }
            return expand__3fctFP4nameP5tableP4expr(__2nf, __1fn, __1scope, __1ll);
        }
    }

    if (((((__0this->body__3fct == 0) && (__0this->f_expr__3fct == 0)) ||
          ((__0this->defined__4type & 02) == 0)) ||
         ((((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))))->body__3fct->memtbl__4stmt ==
          __1scope)) ||
        (__0this->f_inline__3fct > 1)) {
        extern Pfct current_fct_instantiation;

        if (warning_opt) {
            struct ea __0__V50;

            error__FiPCcRC2eaN33(
                (int)'w', (const char *)"cannot inline%n in thisE",
                (const struct ea *)(((&__0__V50)->__O1__2ea.p = ((const void *)__1fn)),
                                    (&__0__V50)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        };
        if (__0this->fct_base__3fct == 4)
            current_fct_instantiation = __0this;
        if ((__1fn->n_addr_taken__4name++) == 0)
            dcl_print__4nameFUc(__1fn, (unsigned char)0);
        if (__0this->fct_base__3fct == 4)
            current_fct_instantiation = 0;
        return (struct expr *)0;
    }

    if (__1fn->n_oper__4name == 161) {
        Pclass __2cl;

        __2cl = (((struct classdef *)((
            (struct classdef *)__1fn->__O4__4expr.n_table->t_name__5table->__O1__4expr.tp))));
        if (__2cl->c_body__8classdef == 3)
            print_all_vtbls__8classdefFP8classdef(__2cl, __2cl);
    }

    {
        Pin __1il;
        Pexpr __1ic;
        int __1ns;

        struct iline *__0__X64;

        struct node *__0__X11;

        struct texpr *__0__X65;

        __1il =
            ((__0__X64 = 0),
             (((__0__X64 || (__0__X64 = (struct iline *)__nw__FUl((size_t)(sizeof(struct iline)))))
                   ? ((__0__X64 =
                           (struct iline *)((__0__X11 = (((struct node *)__0__X64))),
                                            (((__0__X11 || (__0__X11 = (struct node *)__nw__FUl(
                                                                (size_t)(sizeof(struct node)))))
                                                  ? (((__0__X11->base__4node = 0),
                                                      (__0__X11->permanent__4node = 0)),
                                                     (__0__X11->baseclass__4node = 0))
                                                  : 0),
                                             __0__X11))),
                      (__0__X64->base__4node = 202))
                   : 0),
              __0__X64));
        __1ic = (struct expr *)((__0__X65 = 0),
                                (((__0__X65 || (__0__X65 = (struct texpr *)__nw__4exprSFUl(
                                                    (size_t)(sizeof(struct texpr)))))
                                      ? ((__0__X65 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X65), ((unsigned char)168),
                                              ((struct expr *)0), (struct expr *)0)),
                                         (__0__X65->__O4__4expr.tp2 = ((struct type *)0)))
                                      : 0),
                                 __0__X65));
        __1ns = 0;
        {
            {
                Pname __1an;

                __1an = __0this->f_args__3fct;

                for (; __1an; __1an = __1an->__O1__4name.n_list)
                    __1ns++;
                __1il->fct_name__5iline = __1fn;
                __1il->i_slots__5iline = __1ns;
                __1il->i_args__5iline =
                    (struct ia *)(__1ns ? (((struct ia *)__vec_new(((void *)0), __1ns,
                                                                   sizeof(struct ia),
                                                                   ((void *)__ct__2iaFv))))
                                        : (((struct ia *)0)));
                __1ic->__O4__4expr.il = __1il;
                __1ic->__O1__4expr.tp =
                    (__0this->s_returns__3fct ? __0this->s_returns__3fct : __0this->returns__3fct);

                {
                    Pname __1at;

                    __1at = __0this->f_args__3fct;

                    __0this->f_inline__3fct++;

                    if (__1at)
                        __1il->i_table__5iline = __1at->__O4__4expr.n_table;
                    {
                        int __1i;
                        int __1not_simple;

                        Pname __1n;

                        __1i = 0;
                        __1not_simple = 0;

                        __1n = __1at;
                        for (; __1n && __1ll; ((__1n = __1n->__O1__4name.n_list), (__1i++))) {
                            Pexpr __2ee;

                            int __2s;

                            if (__1ll->base__4node == 140) {
                                __2ee = __1ll->__O2__4expr.e1;
                                __1ll = __1ll->__O3__4expr.e2;
                            } else {
                                __2ee = __1ll;
                                __1ll = 0;
                            }

                            (__1il->i_args__5iline[__1i]).local__2ia = 0;
                            ;

                            {
                                {
                                    Pname __2m;

                                    __2m = __1at;

                                    for (; __2m; __2m = __2m->__O1__4name.n_list) {
                                        Pptr __3p;
                                        if (__1n != __2m) {
                                            if (__3p = is_ptr_or_ref__4typeFv(__2m->__O1__4expr.tp))
                                                if ((check__4typeFP4typeUcT2(
                                                         (struct type *)__3p, __1n->__O1__4expr.tp,
                                                         (unsigned char)0,
                                                         (unsigned char)0) == 0) ||
                                                    (check__4typeFP4typeUcT2(
                                                         __3p->typ__5pvtyp, __1n->__O1__4expr.tp,
                                                         (unsigned char)0, (unsigned char)0) == 0))
                                                    goto zxc;
                                        }
                                    }

                                    watch_out = 0;
                                    {
                                        int __2notsimple;

                                        __2notsimple = not_simple__4exprFi(__2ee, 1);
                                        if ((((__2notsimple == 0) && watch_out) &&
                                             (__1n->n_used__4name > 1)) &&
                                            (__2ee->base__4node != 145))
                                            goto zxc;
                                        if (((__1n->n_assigned_to__4name == 11111) &&
                                             (__2ee != zero)) &&
                                            (__2notsimple == 0)) {
                                            if (((__2ee && __2ee->__O2__4expr.e1) &&
                                                 (__2ee->__O2__4expr.e1->base__4node == 85)) &&
                                                (!strcmp(__2ee->__O2__4expr.e1->__O2__4expr.string,
                                                         (const char *)"this")))
                                                goto zxc;
                                        } else if (__1n->n_addr_taken__4name ||
                                                   __1n->n_assigned_to__4name)
                                            goto zxc;
                                        else if (__2s = __2notsimple) {
                                            if ((1 < __2s) || (1 < __1n->n_used__4name)) {
                                            zxc:
                                                if (((__0this->last_expanded__3fct &&
                                                      (__0this->last_expanded__3fct != dummy)) &&
                                                     (__0this->last_expanded__3fct == curr_expr)) &&
                                                    (__0this->last_stmt__3fct == stmtno)) {
                                                    if (warning_opt) {
                                                        struct ea __0__V51;

                                                        error__FiPCcRC2eaN33(
                                                            (int)'w',
                                                            (const char *)"%a not inlined, called "
                                                                          "twice in an expression",
                                                            (const struct ea
                                                                 *)(((&__0__V51)->__O1__2ea.p =
                                                                         ((const void *)__1fn)),
                                                                    (&__0__V51)),
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0);
                                                    }
                                                    __0this->f_inline__3fct--;
                                                    __vec_delete(((void *)__1il->i_args__5iline),
                                                                 -1, sizeof(struct ia), ((void *)0),
                                                                 1, 0);
                                                    __dl__FPv((void *)__1il);

                                                    {
                                                        extern Pfct current_fct_instantiation;
                                                        if (__0this->fct_base__3fct == 4)
                                                            current_fct_instantiation = __0this;
                                                        if ((__1fn->n_addr_taken__4name++) == 0)
                                                            dcl_print__4nameFUc(__1fn,
                                                                                (unsigned char)0);
                                                        if (__0this->fct_base__3fct == 4)
                                                            current_fct_instantiation = 0;
                                                        return (struct expr *)0;
                                                    }
                                                }

                                                {
                                                    Pname __4nn;

                                                    __4nn = dcl_local__FP5tableP4nameT2Uc(
                                                        __1scope, __1n, __1fn, (unsigned char)1);
                                                    __4nn->base__4node = 85;
                                                    (__1il->i_args__5iline[__1i]).local__2ia =
                                                        __4nn;
                                                    ++__1not_simple;
                                                }
                                            }
                                        }

                                        (__1il->i_args__5iline[__1i]).arg__2ia = __2ee;
                                        (__1il->i_args__5iline[__1i]).tp__2ia =
                                            __1n->__O1__4expr.tp;
                                    }
                                }
                            }
                        }

                        {
                            Ptable __1tbl;

                            __1tbl = __0this->body__3fct->memtbl__4stmt;
                            if (__0this->f_expr__3fct) {
                                char __2loc_var;

                                int __2__X53;

                                int __2__X54;

                                __2loc_var = 0;

                                for (__1n = ((__2__X53 = (__1i = 1)),
                                             ((((__2__X53 <= 0) ||
                                                (__1tbl->free_slot__5table <= __2__X53))
                                                   ? (((struct name *)0))
                                                   : (__1tbl->entries__5table[__2__X53]))));
                                     __1n;
                                     __1n =
                                         (__1n->n_tbl_list__4name
                                              ? __1n->n_tbl_list__4name
                                              : ((__2__X54 = (++__1i)),
                                                 ((((__2__X54 <= 0) ||
                                                    (__1tbl->free_slot__5table <= __2__X54))
                                                       ? (((struct name *)0))
                                                       : (__1tbl->entries__5table[__2__X54])))))) {
                                    if (((__1n->base__4node == 85) &&
                                         ((__1n->__O1__4expr.tp->base__4node != 108) &&
                                          (__1n->__O1__4expr.tp->base__4node != 76))) &&
                                        ((__1n->n_used__4name || __1n->n_assigned_to__4name) ||
                                         __1n->n_addr_taken__4name)) {
                                        if ((__0this->last_expanded__3fct &&
                                             (__0this->last_expanded__3fct == curr_expr)) &&
                                            (__0this->last_stmt__3fct == stmtno)) {
                                            if (warning_opt) {
                                                struct ea __0__V52;

                                                error__FiPCcRC2eaN33(
                                                    (int)'w',
                                                    (const char *)"cannot inline%n in thisE",
                                                    (const struct ea *)(((&__0__V52)->__O1__2ea.p =
                                                                             ((const void *)__1fn)),
                                                                        (&__0__V52)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                                            }
                                            __0this->f_inline__3fct--;
                                            __vec_delete(((void *)__1il->i_args__5iline), -1,
                                                         sizeof(struct ia), ((void *)0), 1, 0);
                                            __dl__FPv((void *)__1il);
                                            {
                                                extern Pfct current_fct_instantiation;
                                                if (__0this->fct_base__3fct == 4)
                                                    current_fct_instantiation = __0this;
                                                if ((__1fn->n_addr_taken__4name++) == 0)
                                                    dcl_print__4nameFUc(__1fn, (unsigned char)0);
                                                if (__0this->fct_base__3fct == 4)
                                                    current_fct_instantiation = 0;
                                                return (struct expr *)0;
                                            }
                                        }
                                        {
                                            Pname __4nn;

                                            __4nn = dcl_local__FP5tableP4nameT2Uc(
                                                __1scope, __1n, __1fn, (unsigned char)0);
                                            __4nn->base__4node = 85;
                                            __1n->__O2__4expr.string = __4nn->__O2__4expr.string;

                                            __2loc_var++;
                                        }
                                    }
                                }

                                if (__1i || __2loc_var) {
                                    if (!curr_expr)
                                        curr_expr = dummy;
                                    __0this->last_expanded__3fct = curr_expr;
                                    __0this->last_stmt__3fct = stmtno;
                                }

                                {
                                    Pexpr __2ex;
                                    if (__1not_simple) {
                                        Pexpr __3etail;

                                        __3etail = (__2ex = __ct__4exprFUcP4exprT2(
                                                        (struct expr *)0, (unsigned char)71,
                                                        (struct expr *)0, (struct expr *)0));
                                        for (__1i = 0; __1i < __1il->i_slots__5iline; __1i++) {
                                            Pname __4n;

                                            __4n = (__1il->i_args__5iline[__1i]).local__2ia;
                                            if (__4n == 0)
                                                continue;
                                            {
                                                Pexpr __4e;

                                                __4e = (__1il->i_args__5iline[__1i]).arg__2ia;

                                                if ((__4n->n_used__4name ||
                                                     __4n->n_assigned_to__4name) ||
                                                    __4n->n_addr_taken__4name) {
                                                    Pptr __5p1;
                                                    Pptr __5p2;

                                                    __5p1 = is_ptr__4typeFv(__4n->__O1__4expr.tp);
                                                    __5p2 =
                                                        (__4e->__O1__4expr.tp
                                                             ? is_ptr__4typeFv(__4e->__O1__4expr.tp)
                                                             : (((struct ptr *)0)));
                                                    if ((__5p1 && __5p1->memof__3ptr) && (!__5p2)) {
                                                        switch (__4e->base__4node) {
                                                        case 71:
                                                        case 147:
                                                            __4e->__O3__4expr.e2 =
                                                                mptr_assign__FP4exprT1(
                                                                    (struct expr *)__4n,
                                                                    __4e->__O3__4expr.e2);
                                                            break;
                                                        case 168:
                                                            break;
                                                        default:
                                                            __4e = mptr_assign__FP4exprT1(
                                                                (struct expr *)__4n, __4e);
                                                        }
                                                        __3etail->__O2__4expr.e1 = __4e;
                                                    } else
                                                        __3etail->__O2__4expr.e1 =
                                                            __ct__4exprFUcP4exprT2(
                                                                (struct expr *)0, (unsigned char)70,
                                                                (struct expr *)__4n, __4e);
                                                } else
                                                    __3etail->__O2__4expr.e1 = __4e;
                                                if (--__1not_simple)
                                                    __3etail = (__3etail->__O3__4expr.e2 =
                                                                    __ct__4exprFUcP4exprT2(
                                                                        (struct expr *)0,
                                                                        (unsigned char)71,
                                                                        (struct expr *)0,
                                                                        (struct expr *)0));
                                                else
                                                    break;
                                            }
                                        }
                                        __3etail->__O3__4expr.e2 = __0this->f_expr__3fct;
                                    } else
                                        __2ex = __0this->f_expr__3fct;
                                    __1ic->__O2__4expr.e1 = __2ex;
                                }
                            } else {
                                int __2__X55;

                                int __2__X56;

                                for (__1n = ((__2__X55 = (__1i = 1)),
                                             ((((__2__X55 <= 0) ||
                                                (__1tbl->free_slot__5table <= __2__X55))
                                                   ? (((struct name *)0))
                                                   : (__1tbl->entries__5table[__2__X55]))));
                                     __1n;
                                     __1n =
                                         (__1n->n_tbl_list__4name
                                              ? __1n->n_tbl_list__4name
                                              : ((__2__X56 = (++__1i)),
                                                 ((((__2__X56 <= 0) ||
                                                    (__1tbl->free_slot__5table <= __2__X56))
                                                       ? (((struct name *)0))
                                                       : (__1tbl->entries__5table[__2__X56])))))) {
                                    if (((__1n->base__4node == 85) && __1n->__O1__4expr.tp) &&
                                        ((__1n->n_used__4name || __1n->n_assigned_to__4name) ||
                                         __1n->n_addr_taken__4name)) {
                                        __1n->__O2__4expr.string =
                                            temp__FPCcP4name(__1n->__O2__4expr.string, __1fn);
                                    }
                                }
                                {
                                    Pstmt __2ss;
                                    if (__1not_simple) {
                                        if (!curr_expr)
                                            curr_expr = dummy;
                                        __0this->last_expanded__3fct = curr_expr;
                                        __0this->last_stmt__3fct = stmtno;
                                        {
                                            Pstmt __3st;

                                            struct estmt *__0__X62;

                                            struct loc __2__X63;

                                            __3st =
                                                (struct stmt
                                                     *)((__0__X62 = 0),
                                                        ((__2__X63 = curloc),
                                                         (((__0__X62 ||
                                                            (__0__X62 =
                                                                 (struct estmt *)__nw__4stmtSFUl(
                                                                     (unsigned long)(sizeof(
                                                                         struct estmt)))))
                                                               ? ((__0__X62 = (struct estmt *)
                                                                       __ct__4stmtFUc3locP4stmt(
                                                                           ((struct stmt *)
                                                                                __0__X62),
                                                                           ((unsigned char)72),
                                                                           __2__X63,
                                                                           ((struct stmt *)0))),
                                                                  (__0__X62->__O2__4stmt.e =
                                                                       ((struct expr *)0)))
                                                               : 0),
                                                          __0__X62)));
                                            __3st->where__4stmt.line__3loc = 0;
                                            {
                                                Pstmt __3stail;

                                                register struct block *__0__X59;

                                                struct loc __2__X60;

                                                struct loc __2__X61;

                                                __3stail = __3st;
                                                for (__1i = 0; __1i < __1il->i_slots__5iline;
                                                     __1i++) {
                                                    Pname __4n;

                                                    __4n = (__1il->i_args__5iline[__1i]).local__2ia;
                                                    if (__4n == 0)
                                                        continue;
                                                    {
                                                        Pexpr __4e;
                                                        Pptr __4p1;
                                                        Pptr __4p2;

                                                        __4e =
                                                            (__1il->i_args__5iline[__1i]).arg__2ia;
                                                        __4p1 =
                                                            is_ptr__4typeFv(__4n->__O1__4expr.tp);
                                                        __4p2 =
                                                            is_ptr__4typeFv(__4e->__O1__4expr.tp);
                                                        if ((__4p1 && __4p1->memof__3ptr) &&
                                                            (!__4p2)) {
                                                            switch (__4e->base__4node) {
                                                            case 71:
                                                            case 147:
                                                                __4e->__O3__4expr.e2 =
                                                                    mptr_assign__FP4exprT1(
                                                                        (struct expr *)__4n,
                                                                        __4e->__O3__4expr.e2);
                                                                break;
                                                            default:
                                                                __4e = mptr_assign__FP4exprT1(
                                                                    (struct expr *)__4n, __4e);
                                                            }
                                                            __3stail->__O2__4stmt.e = __4e;
                                                        } else
                                                            __3stail->__O2__4stmt.e =
                                                                __ct__4exprFUcP4exprT2(
                                                                    (struct expr *)0,
                                                                    (unsigned char)70,
                                                                    (struct expr *)__4n, __4e);
                                                        if (--__1not_simple) {
                                                            struct estmt *__0__X57;

                                                            struct loc __2__X58;

                                                            __3stail =
                                                                (__3stail->s_list__4stmt =
                                                                     (struct stmt
                                                                          *)((__0__X57 = 0),
                                                                             ((__2__X58 = curloc),
                                                                              (((__0__X57 ||
                                                                                 (__0__X57 = (struct
                                                                                              estmt
                                                                                                  *)
                                                                                      __nw__4stmtSFUl((
                                                                                          size_t)(sizeof(
                                                                                          struct
                                                                                          estmt)))))
                                                                                    ? ((__0__X57 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                                                            ((struct
                                                                                              stmt
                                                                                                  *)
                                                                                                 __0__X57),
                                                                                            ((unsigned char)72),
                                                                                            __2__X58,
                                                                                            ((struct
                                                                                              stmt
                                                                                                  *)0))),
                                                                                       (__0__X57
                                                                                            ->__O2__4stmt
                                                                                            .e = ((
                                                                                            struct
                                                                                            expr
                                                                                                *)0)))
                                                                                    : 0),
                                                                               __0__X57))));
                                                            __3stail->where__4stmt.line__3loc = 0;
                                                        } else
                                                            break;
                                                    }
                                                }
                                                __3stail->s_list__4stmt =
                                                    (struct stmt *)__0this->body__3fct;
                                                __2ss =
                                                    (struct stmt
                                                         *)((__0__X59 = 0),
                                                            ((__2__X60 = curloc),
                                                             ((__2__X61 = noloc),
                                                              (((__0__X59 ||
                                                                 (__0__X59 = (struct block *)
                                                                      __nw__4stmtSFUl(
                                                                          (size_t)(sizeof(
                                                                              struct block)))))
                                                                    ? (((void)((__0__X59 = (struct
                                                                                            block *)
                                                                                    __ct__4stmtFUc3locP4stmt(
                                                                                        ((struct
                                                                                          stmt *)
                                                                                             __0__X59),
                                                                                        (unsigned char)116,
                                                                                        __2__X60,
                                                                                        __3st)),
                                                                               ((__0__X59
                                                                                     ->__O1__4stmt
                                                                                     .d =
                                                                                     ((struct name
                                                                                           *)0)),
                                                                                (__0__X59
                                                                                     ->__O3__4stmt
                                                                                     .where2 =
                                                                                     __2__X61)))))
                                                                    : (((void)0))),
                                                               __0__X59))));
                                                __2ss->where__4stmt.line__3loc = 0;
                                            }
                                        }
                                    } else
                                        __2ss = (struct stmt *)__0this->body__3fct;
                                    __1ic->__O3__4expr.e2 =
                                        (((struct expr *)(((struct expr *)__2ss))));
                                }
                            }

                            __0this->f_inline__3fct--;

                            return __1ic;
                        }
                    }
                }
            }
        }
    }
}

static struct ia *__ct__2iaFv(struct ia *__0this) {
    struct node *__0__X10;

    if (__0this || (__0this = (struct ia *)__nw__FUl((size_t)(sizeof(struct ia))))) {
        ((((__0this = (struct ia *)((__0__X10 = (((struct node *)__0this))),
                                    (((__0__X10 || (__0__X10 = (struct node *)__nw__FUl(
                                                        (size_t)(sizeof(struct node)))))
                                          ? (((__0__X10->base__4node = 0),
                                              (__0__X10->permanent__4node = 0)),
                                             (__0__X10->baseclass__4node = 0))
                                          : 0),
                                     __0__X10))),
           (__0this->local__2ia = 0)),
          (__0this->arg__2ia = 0)),
         (__0this->tp__2ia = 0));
        __0this->base__4node = 203;
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
