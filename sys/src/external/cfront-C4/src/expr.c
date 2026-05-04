
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

int const_save = 0;
extern int no_const;
extern Ptype Pfct_type;

int processing_sizeof = 0;

Pexpr address__4exprFv(struct expr *__0this);

extern Pname make_tmp__FcP4typeP5table(char, Ptype, Ptable);
extern Pexpr init_tmp__FP4nameP4exprP5table(Pname, Pexpr, Ptable);

bit not_simple__4exprFi(struct expr *__0this, int __1inflag);

void take_addr__4nameFv(struct name *__0this);

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);

Pexpr address__4exprFv(register struct expr *__0this) {
    switch (__0this->base__4node) {
        unsigned long __2__X19;

    case 111:
        if (__0this->__O3__4expr.e2 == 0)
            return __0this->__O2__4expr.e1;
        break;
    case 68:
        __0this->__O2__4expr.e1 = address__4exprFv(__0this->__O2__4expr.e1);

    case 147:
        if (((__0this->__O2__4expr.e1 && ((__0this->__O2__4expr.e1->base__4node == 146) ||
                                          (__0this->__O2__4expr.e1->base__4node == 109))) &&
             __0this->__O3__4expr.e2) &&
            (__0this->__O3__4expr.e2->base__4node == 145))
            return __0this;
    case 71:
        if (__0this->__O3__4expr.e2 && (__0this->__O3__4expr.e2->base__4node == 146)) {
            Pname __3tmp;

            __3tmp = make_tmp__FcP4typeP5table('Q', __0this->__O3__4expr.e2->__O1__4expr.tp,
                                               cc->ftbl__11dcl_context);
            __0this->__O3__4expr.e2 = init_tmp__FP4nameP4exprP5table(
                __3tmp, __0this->__O3__4expr.e2, cc->ftbl__11dcl_context);
            {
                Pexpr __3aa;

                __3aa = address__4exprFv((struct expr *)__3tmp);
                __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                    (struct expr *)0, (unsigned char)147, __0this->__O3__4expr.e2, __3aa);
                __0this->__O3__4expr.e2->__O1__4expr.tp = __3aa->__O1__4expr.tp;
            }
        } else
            __0this->__O3__4expr.e2 = address__4exprFv(__0this->__O3__4expr.e2);
        __0this->__O1__4expr.tp = __0this->__O3__4expr.e2->__O1__4expr.tp;
        return __0this;
    case 48:
    case 49:
        if (__0this->__O2__4expr.e1)
            break;
        nin++;
        if (not_simple__4exprFi(__0this->__O3__4expr.e2, 0)) {
            struct ea __0__V17;

            error__FiPCcRC2eaN33(
                (int)'s', (const char *)"& of%k",
                (const struct ea *)((__2__X19 = __0this->base__4node),
                                    (((((&__0__V17)->__O1__2ea.i = __2__X19), 0)), (&__0__V17))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        nin--;
        __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                                         (struct expr *)0, __0this->__O3__4expr.e2);
        __0this->__O3__4expr.e2 = address__4exprFv(__0this->__O3__4expr.e2);
        __0this->base__4node = 147;
        __0this->__O1__4expr.tp = __0this->__O3__4expr.e2->__O1__4expr.tp;
        return __0this;
    case 70:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
    case 131:
    case 132:
    case 133:
    case 134:
    case 135: {
        unsigned long __2__X20;

        nin++;
        if (not_simple__4exprFi(__0this->__O2__4expr.e1, 0)) {
            struct ea __0__V18;

            error__FiPCcRC2eaN33(
                (int)'s', (const char *)"& of%k",
                (const struct ea *)((__2__X20 = __0this->base__4node),
                                    (((((&__0__V18)->__O1__2ea.i = __2__X20), 0)), (&__0__V18))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        nin--;
        {
            Pexpr __3a;

            __3a = __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                          __0this->__O2__4expr.e1, __0this->__O3__4expr.e2);
            __3a->__O1__4expr.tp = __3a->__O2__4expr.e1->__O1__4expr.tp;
            __0this->base__4node = 147;
            __0this->__O2__4expr.e1 = __3a;
            __0this->__O3__4expr.e2 = address__4exprFv(__3a->__O2__4expr.e1);
            __0this->__O1__4expr.tp = __0this->__O3__4expr.e2->__O1__4expr.tp;
            return __0this;
        }
    }
    case 85:
        take_addr__4nameFv(((struct name *)(((struct name *)__0this))));
        if ((((struct name *)(((struct name *)__0this))))->n_xref__4name)
            return __0this;
        break;
    case 109:
    case 113:
    case 191:
    case 23:
    case 184:
        if (__0this->__O1__4expr.tp && is_ptr_or_ref__4typeFv(__0this->__O1__4expr.tp)) {
            return __0this;
        }
        break;
    }

    {
        Pexpr __1ee;

        __1ee =
            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145, (struct expr *)0, __0this);
        if (__0this->__O1__4expr.tp) {
            struct type *__0__X21;

            __1ee->__O1__4expr.tp =
                (struct type *)((__0__X21 = __0this->__O1__4expr.tp),
                                (__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125,
                                                     __0__X21)));

            switch (__0this->__O1__4expr.tp->base__4node) {
            case 125:
                (((struct ptr *)(((struct ptr *)__1ee->__O1__4expr.tp))))->memof__3ptr =
                    (((struct ptr *)(((struct ptr *)__0this->__O1__4expr.tp))))->memof__3ptr;
                break;
            case 108:
                if ((((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->f_static__3fct ==
                    0)
                    (((struct ptr *)(((struct ptr *)__1ee->__O1__4expr.tp))))->memof__3ptr =
                        (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->memof__3fct;
                break;
            case 76:
                if ((((struct fct *)((
                         (struct fct *)(((struct gen *)(((struct gen *)__0this->__O1__4expr.tp))))
                             ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))
                        ->f_static__3fct == 0)
                    (((struct ptr *)(((struct ptr *)__1ee->__O1__4expr.tp))))->memof__3ptr =
                        (((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__0this
                                                                              ->__O1__4expr.tp))))
                                              ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))
                            ->memof__3fct;
            }
        }

        return __1ee;
    }
}

Pfct memptr__4typeFv(struct type *__0this);

Pexpr make_dot__FP4exprP5tablePCc(Pexpr __1e, Ptable __1tbl, const char *__1c) {
    if (!memptr__4typeFv(__1e->__O1__4expr.tp))
        return __1e;

    if ((((__1e->base__4node == 71) || (__1e->base__4node == 146)) || (__1e->base__4node == 109)) ||
        (__1e->base__4node == 70)) {
        Pname __2atmp;

        Pexpr __2as;

        register struct mdot *__0__X22;

        __2atmp = make_tmp__FcP4typeP5table('A', __1e->__O1__4expr.tp, __1tbl);
        __2as = init_tmp__FP4nameP4exprP5table(__2atmp, __1e, __1tbl);
        __1e = (struct expr *)((__0__X22 = 0),
                               (((__0__X22 || (__0__X22 = (struct mdot *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct mdot)))))
                                     ? ((__0__X22 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                             ((struct expr *)__0__X22), (unsigned char)177,
                                             (struct expr *)0, (struct expr *)0)),
                                        ((__0__X22->__O3__4expr.string2 = __1c),
                                         (__0__X22->__O4__4expr.mem = ((struct expr *)__2atmp))))
                                     : 0),
                                __0__X22));
        __1e->__O2__4expr.i1 = 9;
        __1e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147, __2as, __1e);
    } else if (__1e->base__4node == 124) {
        if ((__1c[0]) == 'i')
            __1e = __1e->__O2__4expr.e1->__O3__4expr.e2;
        if ((__1c[0]) == 'f')
            __1e = __1e->__O3__4expr.e2;
    } else {
        register struct mdot *__0__X23;

        __1e = (struct expr *)((__0__X23 = 0),
                               (((__0__X23 || (__0__X23 = (struct mdot *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct mdot)))))
                                     ? ((__0__X23 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                             ((struct expr *)__0__X23), (unsigned char)177,
                                             (struct expr *)0, (struct expr *)0)),
                                        ((__0__X23->__O3__4expr.string2 = __1c),
                                         (__0__X23->__O4__4expr.mem = __1e)))
                                     : 0),
                                __0__X23));
        __1e->__O2__4expr.i1 = 9;
    }
    return __1e;
}

Pexpr contents__4exprFv(struct expr *__0this);

Pname is_cl_obj__4typeFv(struct type *__0this);

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

Pexpr contents__4exprFv(register struct expr *__0this) {
    switch (__0this->base__4node) {
    case 112:
    case 145:
        return __0this->__O3__4expr.e2;
    case 140:
        __0this->__O2__4expr.e1 = contents__4exprFv(__0this->__O2__4expr.e1);
        __0this->__O1__4expr.tp = __0this->__O2__4expr.e1->__O1__4expr.tp;
        return __0this;
    }

    ;

    {
        Pexpr __1ee;

        __1ee =
            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111, __0this, (struct expr *)0);
        if (__0this->__O1__4expr.tp) {
            Ptype __2tt;

            __2tt = skiptypedefs__4typeFv(__0this->__O1__4expr.tp);
            __1ee->__O1__4expr.tp = (((struct ptr *)(((struct ptr *)__2tt))))->typ__5pvtyp;
            {
                Pname __2cn;

                __2cn = is_cl_obj__4typeFv(__1ee->__O1__4expr.tp);
                if (__2cn) {
                    Pclass __3cl;

                    __3cl = (((struct classdef *)(((struct classdef *)__2cn->__O1__4expr.tp))));
                    if (__3cl->c_body__8classdef == 1)
                        dcl_print__8classdefFP4name(__3cl, (struct name *)0);
                }
            }
        }
        return __1ee;
    }
}

int bound = 0;
int chars_in_largest = 0;
int chars_in_largestl = 0;
int chars_in_largestll = 0;

static bit ptr_is_template_formal__FP3ptr(Pptr __1p) {
    if (__1p->typ__5pvtyp) {
        if (__1p->typ__5pvtyp->base__4node != 97)
            return (unsigned char)0;
        {
            Pname __2n;

            struct type *__0__X24;

            __2n = ((__0__X24 = __1p->typ__5pvtyp),
                    ((((struct basetype *)(((struct basetype *)__0__X24))))->b_name__8basetype));
            return ((((unsigned char)(__2n->n_template_arg__4name == 1))));
        }
    } else
        return (unsigned char)0;
}

bit has_friend__8classdefFP3fct(struct classdef *__0this, Pfct);

bit has_friend__8classdefFP8classdef(struct classdef *__0this, Pclass);

bit has_base__8classdefFP8classdefiT2(struct classdef *__0this, Pclass __1cl, int __1level,
                                      int __1ccflag);

struct basetype *__ct__8basetypeFUcP4name(struct basetype *__0this, TOK, Pname);

Ptype common_base__FP8classdefT1(Pclass __1cl1, Pclass __1cl2) {
    if ((__1cl1 == 0) || (__1cl2 == 0))
        return (struct type *)0;
    if ((__1cl1->baselist__8classdef == 0) || (__1cl2->baselist__8classdef == 0))
        return (struct type *)0;
    {
        Pbase __1answer;

        __1answer = 0;

        {
            {
                Pbcl __1b;

                __1b = __1cl1->baselist__8classdef;

                for (; __1b; __1b = __1b->next__6basecl) {
                    struct classdef *__1__X25;

                    struct classdef *__1__X26;

                    if ((((__1b->ppp__6basecl != 25) &&
                          (!((__1__X25 = cc->cot__11dcl_context),
                             ((__1__X26 = __1cl1),
                              (((__1__X25 == __1__X26)
                                    ? 1
                                    : ((__1__X25 && __1__X26)
                                           ? (((int)same_class__8classdefFP8classdefi(__1__X25,
                                                                                      __1__X26, 0)))
                                           : 0))))))) &&
                         ((cc->nof__11dcl_context == 0) ||
                          (has_friend__8classdefFP3fct(
                               __1cl1, ((struct fct *)(((struct fct *)cc->nof__11dcl_context
                                                            ->__O1__4expr.tp)))) == 0))) &&
                        ((cc->cot__11dcl_context == 0) ||
                         (has_friend__8classdefFP8classdef(__1cl1, cc->cot__11dcl_context) == 0)))
                        continue;
                    Nvis = 0;
                    if (has_base__8classdefFP8classdefiT2(__1cl2, __1b->bclass__6basecl, 0, 0)) {
                        if (Nvis)
                            continue;
                        if (__1answer)
                            return (struct type *)0;
                        {
                            Pname __3bn;

                            __3bn = __ct__4nameFPCc((struct name *)0,
                                                    __1b->bclass__6basecl->string__8classdef);
                            __3bn->__O1__4expr.tp = (struct type *)__1b->bclass__6basecl;
                            __1answer = __ct__8basetypeFUcP4name((struct basetype *)0,
                                                                 (unsigned char)119, __3bn);
                        }
                    }
                }
                return (struct type *)__1answer;
            }
        }
    }
}

extern Pname k_find_name__FPCcP6ktableUc(const char *, Pktab, TOK);

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

extern int error__FPCc(const char *);

extern Pname k_find_member__FPCcP8classdefUc(const char *, Pclass, TOK);

static Pexpr do_qualifiers__FP4typeP4expr(Ptype __1t, Pexpr __1mem) {
    Pname __1m;

    __1m = (((struct name *)(((struct name *)__1mem))));
    if ((((__1m->base__4node != 85) && (__1m->base__4node != 162)) ||
         (__1m->__O2__4name.n_qualifier == 0)) ||
        (__1m->__O2__4name.n_qualifier->base__4node != 176))
        return __1mem;
    {
        Pname __1cn;
        Pname __1tn;
        Pname __1q;

        __1cn = (__1t ? is_cl_obj__4typeFv(__1t) : (((struct name *)0)));
        __1tn = 0;
        __1q = __1m->__O2__4name.n_qualifier;
        __1m->__O2__4name.n_qualifier = 0;
        if (__1q->__O2__4expr.string == 0) {
            do {
                Pname __3qx;

                __3qx = __1q->__O1__4name.n_list;
                ((__1q ? (((void)(__1q ? (((void)((((((struct expr *)__1q))
                                                        ? (((void)((((struct expr *)__1q))
                                                                       ? (((void)(((void)0))))
                                                                       : (((void)0)))))
                                                        : (((void)0)))),
                                                  (((void)__dl__4nameSFPvUl(
                                                      (void *)__1q,
                                                      (size_t)(sizeof(struct name))))))))
                                       : (((void)0)))))
                       : (((void)0))));
                __1q = __3qx;
            } while (__1q && (__1q->__O2__4expr.string == 0));

            if (__1q == 0) {
                __1m->__O3__4expr.n_initializer = (struct expr *)sta_name;

                return __1mem;
            }
            __1tn = k_find_name__FPCcP6ktableUc(__1q->__O2__4expr.string, Gtbl, (unsigned char)159);
        } else if (__1cn)
            __1tn = k_find_name__FPCcP6ktableUc(
                __1q->__O2__4expr.string,
                (((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))))
                    ->k_tbl__8classdef,
                (unsigned char)159);
        else
            __1tn = k_find_name__FPCcP6ktableUc(__1q->__O2__4expr.string, Ctbl, (unsigned char)159);

        {
            Pname __1cx;

            __1cx = 0;
            for (;;) {
                if (__1tn == 0) {
                    {
                        struct ea __0__V27;

                        struct ea __0__V28;

                        error__FPCcRC2eaN32(
                            (const char *)"%n :: --TN%n not found",
                            (const struct ea *)(((&__0__V27)->__O1__2ea.p = ((const void *)__1q)),
                                                (&__0__V27)),
                            (const struct ea *)(((&__0__V28)->__O1__2ea.p = ((const void *)__1q)),
                                                (&__0__V28)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                        return __1mem;
                    }
                }
                __1cn = is_cl_obj__4typeFv(__1tn->__O1__4expr.tp);
                if (__1cn == 0) {
                    if ((__1q->__O1__4name.n_list == 0) && (__1m->base__4node == 162))
                        __1m->__O2__4name.n_qualifier = __1tn;
                    else {
                        struct ea __0__V29;

                        struct ea __0__V30;

                        error__FPCcRC2eaN32(
                            (const char *)"%n :: --%n is not aCN",
                            (const struct ea *)(((&__0__V29)->__O1__2ea.p = ((const void *)__1tn)),
                                                (&__0__V29)),
                            (const struct ea *)(((&__0__V30)->__O1__2ea.p = ((const void *)__1tn)),
                                                (&__0__V30)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    return __1mem;
                }
                if (__1cx) {
                    if (has_base__8classdefFP8classdefiT2(
                            ((struct classdef *)(((struct classdef *)__1cx->__O1__4expr.tp))),
                            ((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))), 0,
                            0)) {
                        struct ea __0__V31;

                        struct ea __0__V32;

                        struct ea __0__V33;

                        struct ea __0__V34;

                        error__FPCcRC2eaN32(
                            (const char *)"%n ::%n :: --%n not aM of%n",
                            (const struct ea *)(((&__0__V31)->__O1__2ea.p = ((const void *)__1cx)),
                                                (&__0__V31)),
                            (const struct ea *)(((&__0__V32)->__O1__2ea.p = ((const void *)__1cn)),
                                                (&__0__V32)),
                            (const struct ea *)(((&__0__V33)->__O1__2ea.p = ((const void *)__1cn)),
                                                (&__0__V33)),
                            (const struct ea *)(((&__0__V34)->__O1__2ea.p = ((const void *)__1cx)),
                                                (&__0__V34)));
                    }
                }
                __1cx = __1cn;
                {
                    Pname __3qx;

                    __3qx = __1q->__O1__4name.n_list;

                    ((__1q ? (((void)(__1q ? (((void)((((((struct expr *)__1q))
                                                            ? (((void)((((struct expr *)__1q))
                                                                           ? (((void)(((void)0))))
                                                                           : (((void)0)))))
                                                            : (((void)0)))),
                                                      (((void)__dl__4nameSFPvUl(
                                                          (void *)__1q,
                                                          (size_t)(sizeof(struct name))))))))
                                           : (((void)0)))))
                           : (((void)0))));

                    __1q = __3qx;
                }
                if (__1q == 0)
                    break;
                if (__1q->__O2__4expr.string == 0) {
                    error__FPCc((const char *)"scope qualification syntax");
                    return __1mem;
                }
                __1tn = k_find_member__FPCcP8classdefUc(
                    __1q->__O2__4expr.string,
                    ((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))),
                    (unsigned char)159);
            }
            __1m->__O2__4name.n_qualifier = __1tn;
            return __1mem;
        }
    }
}

Pclass classtype__4typeFv(struct type *__0this);

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

extern const char *oper_name__FUc(TOK);

static Pexpr do_dtor__FP4typeP4expr(Ptype __1t, Pexpr __1mem) {
    Pname __1m;

    Pname __1q;
    Pname __1d;
    Pname __1cn;

    __1m = (((struct name *)(((struct name *)__1mem))));

    __1q = __1m->__O2__4name.n_qualifier;
    __1d = __1m->__O1__4name.n_dtag;
    __1cn = (__1t ? is_cl_obj__4typeFv(__1t) : (((struct name *)0)));

    ;
    if (__1cn) {
        if (__1d && __1d->__O2__4expr.string) {
            Pclass __3cl;

            Pname __3dx;

            __3cl = ((__1q && is_cl_obj__4typeFv(__1q->__O1__4expr.tp))
                         ? classtype__4typeFv(skiptypedefs__4typeFv(__1q->__O1__4expr.tp))
                         : (((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp)))));

            __3dx = k_find_name__FPCcP6ktableUc(__1d->__O2__4expr.string, __3cl->k_tbl__8classdef,
                                                (unsigned char)159);
            if (__3dx == 0) {
                {
                    struct ea __0__V35;

                    struct ea __0__V36;

                    error__FPCcRC2eaN32(
                        (const char *)"TN%n not found in%t",
                        (const struct ea *)(((&__0__V35)->__O1__2ea.p = ((const void *)__1d)),
                                            (&__0__V35)),
                        (const struct ea *)(((&__0__V36)->__O1__2ea.p = ((const void *)__1t)),
                                            (&__0__V36)),
                        (const struct ea *)ea0, (const struct ea *)ea0);

                    __3dx = __1q;
                }
            }
            __1d = (__1m->__O1__4name.n_dtag = __3dx);
        }
    }

    ;
    if (__1q) {
        if (__1d && check__4typeFP4typeUcT2(__1d->__O1__4expr.tp, __1q->__O1__4expr.tp,
                                            (unsigned char)0, (unsigned char)0)) {
            error__FPCc((const char *)"bad syntax for destructor call:N andQr do not match");
            __1q = __1d;
        } else if (__1m->__O3__4expr.tpdef &&
                   check__4typeFP4typeUcT2(__1m->__O3__4expr.tpdef, __1q->__O1__4expr.tp,
                                           (unsigned char)0, (unsigned char)0))
            error__FPCc((const char *)"bad syntax for destructor call:N andQr do not match");
        if (__1d && is_cl_obj__4typeFv(__1d->__O1__4expr.tp)) {
        real_dtor:
            __1m->base__4node = 85;

            __1m->__O1__4expr.tp = (__1m->__O3__4expr.tpdef = (__1m->__O4__4expr.tp2 = 0));
            __1m->__O2__4expr.string = oper_name__FUc((unsigned char)162);
            __1m->n_oper__4name = 162;
        } else {
            if (__1m->__O3__4expr.tpdef)
                __1m->__O4__4expr.tp2 = __1m->__O3__4expr.tpdef;
            else
                __1m->__O4__4expr.tp2 = (__1m->__O3__4expr.tpdef = __1q->__O1__4expr.tp);
            __1m->__O2__4name.n_qualifier = (__1m->__O1__4name.n_dtag = 0);
        }
    } else {
        if ((__1d && (__1m->__O4__4expr.tp2 == 0)) && is_cl_obj__4typeFv(__1d->__O1__4expr.tp)) {
            goto real_dtor;
        }
        if ((__1d && __1m->__O4__4expr.tp2) &&
            check__4typeFP4typeUcT2(__1d->__O1__4expr.tp, __1m->__O4__4expr.tp2, (unsigned char)0,
                                    (unsigned char)0))
            error__FPCc((const char *)"bad syntax for destructor call:N andQr do not match");
        if (__1d) {
            __1m->__O4__4expr.tp2 = (__1m->__O3__4expr.tpdef = __1d->__O1__4expr.tp);

            __1m->__O1__4name.n_dtag = 0;
        }
    };

    if (__1t) {
        if (__1mem->__O4__4expr.tp2) {
            if (check__4typeFP4typeUcT2(__1t, __1mem->__O4__4expr.tp2, (unsigned char)0,
                                        (unsigned char)0)) {
                const void *__2__X40;

                {
                    struct ea __0__V37;

                    error__FPCcRC2eaN32(
                        (const char *)"T mismatch for simpleT destructor:XO ofT%t",
                        (const struct ea *)((__2__X40 = (const void *)__1mem->__O4__4expr.tp2),
                                            (((&__0__V37)->__O1__2ea.p = __2__X40), (&__0__V37))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
        } else {
            if (__1cn) {
                if (__1d && check__4typeFP4typeUcT2(__1t, __1d->__O1__4expr.tp, (unsigned char)0,
                                                    (unsigned char)0)) {
                    Pname __5dn;

                    __5dn = (__1d->__O1__4expr.tp ? is_cl_obj__4typeFv(__1d->__O1__4expr.tp)
                                                  : (((struct name *)0)));
                    if (__1cn && __5dn) {
                        if ((!__1q) &&
                            (!has_base__8classdefFP8classdefiT2(
                                ((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))),
                                ((struct classdef *)(((struct classdef *)__5dn->__O1__4expr.tp))),
                                0, 0))) {
                            error__FPCc((const char *)"bad syntax for destructor call");
                        }
                    } else {
                        const void *__2__X41;

                        {
                            struct ea __0__V38;

                            error__FPCcRC2eaN32(
                                (const char *)"T mismatch for destructor:XO ofT%t",
                                (const struct ea *)((__2__X41 = (const void *)__1d->__O1__4expr.tp),
                                                    (((&__0__V38)->__O1__2ea.p = __2__X41),
                                                     (&__0__V38))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                    }
                }
            } else {
                const void *__2__X42;

                {
                    struct ea __0__V39;

                    error__FPCcRC2eaN32(
                        (const char *)"T mismatch for destructor:XO ofT%t",
                        (const struct ea *)((__2__X42 = (const void *)__1d->__O1__4expr.tp),
                                            (((&__0__V39)->__O1__2ea.p = __2__X42), (&__0__V39))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
        }
    }
    return __1mem;
}

Pname Ntmp_flag_list = 0;
bit in_quest = 0;
struct con_dtor *pdlist = 0;

Pexpr typ__4exprFP5table(struct expr *__0this, Ptable __1tbl);

extern size_t strlen(const char *);

extern char *strdup(const char *);

extern int c_strlen__FPCc(const char *__0s);

static struct vec *__ct__3vecFP4typeP4expr(register struct vec *__0this, Ptype __2t, Pexpr __2e) {
    struct pvtyp *__0__X7;

    struct type *__0__X6;

    struct node *__0__X1;

    if (__0this || (__0this = (struct vec *)__nw__3vecSFUl((size_t)(sizeof(struct vec))))) {
        __0this =
            (struct vec
                 *)((__0__X7 = (((struct pvtyp *)__0this))),
                    (((__0__X7 ||
                       (__0__X7 = (struct pvtyp *)__nw__FUl((size_t)(sizeof(struct pvtyp)))))
                          ? (__0__X7 =
                                 (struct pvtyp
                                      *)((__0__X6 = (((struct type *)__0__X7))),
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
                     __0__X7));

        __0this->base__4node = 110;

        __0this->typ__5pvtyp = __2t;

        __0this->dim__3vec = __2e;

        ;
    }
    return __0this;
}

extern char *strcpy(char *, const char *);

extern Pexpr find_name__FP4nameP8classdefP5tableiT1(Pname, Pclass, Ptable, int, Pname);

Ptype mkconst__4typeFv(struct type *__0this);

Pptr is_ref__4typeFv(struct type *__0this);

void dcl__4typeFP5table(struct type *__0this, Ptable);

void del__4exprFv(struct expr *__0this);

int tsizeof__4typeFi(struct type *__0this, int);

Pexpr docast__4exprFP5table(struct expr *__0this, Ptable);
Pexpr dovalue__4exprFP5table(struct expr *__0this, Ptable);
Pexpr donew__4exprFP5table(struct expr *__0this, Ptable);

extern Pexpr try_to_coerce__FP4typeP4exprPCcP5table(Ptype, Pexpr, const char *, Ptable);

Ptype skiptypedefs__4typeFRUc(struct type *__0this, bit *__1isconst);

extern int is_probably_temp__FPCc(const char *);

Pname has_oper__8classdefFUc(struct classdef *__0this, TOK);

extern int strcmp(const char *, const char *);

extern Pexpr call_dtor__FP4exprN21iT1(Pexpr __0p, Pexpr __0dtor, Pexpr __0arg, int __0d,
                                      Pexpr __0vb_args);

Pexpr oper_overload__4exprFP5table(struct expr *__0this, Ptable);

Ptype call_fct__4exprFP5table(struct expr *__0this, Ptable);

Ptype deref__4typeFv(struct type *__0this);

bit vec_type__4typeFv(struct type *__0this);

extern Pexpr check_cond__FP4exprUcP5table(Pexpr, TOK, Ptable);

int lval__4exprFUc(struct expr *__0this, TOK);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

extern Ptype np_promote__FUcN21P4typeT4N21(TOK, TOK, TOK, Ptype, Ptype, TOK, bit);

long long eval__4exprFv(struct expr *__0this);

extern Pexpr ptof__FP3fctP4exprP5table(Pfct, Pexpr, Ptable);

Pptr is_ptr__4typeFv(struct type *__0this);

extern Pexpr cast_cptr__FP8classdefP4exprP5tablei(Pclass __0ccl, Pexpr __0ee, Ptable __0tbl,
                                                  int __0real_cast);

extern Pexpr mptr_assign__FP4exprT1(Pexpr, Pexpr);

extern Pexpr ptr_init__FP3ptrP4exprP5table(Pptr, Pexpr, Ptable);

extern bit can_coerce__FP4typeT1(Ptype, Ptype);

void clear__5clistFv(struct clist *__0this);

extern int is_unique_base__FP8classdefPCciT3T1(Pclass, const char *, int, int, Pclass __0priSeen);

extern int make_assignment__FP4name(Pname);

bit has_const_mem__8classdefFv(struct classdef *__0this);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

static struct ea *__ct__2eaFUl(struct ea *__0this, size_t __2ii);

Pexpr typ__4exprFP5table(register struct expr *__0this, Ptable __1tbl) {
    Pname __1n;
    Ptype __1t;
    Ptype __1t1;

    Ptype __1t2;
    TOK __1b;
    TOK __1r1;

    TOK __1r2;

    unsigned long __2__X90;

    __1t = 0;

    __1b = __0this->base__4node;

    if (__1tbl->base__4node != 142) {
        struct ea __0__V43;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"expr::typ(%d)",
            (const struct ea *)((__2__X90 = __1tbl->base__4node),
                                (((((&__0__V43)->__O1__2ea.i = __2__X90), 0)), (&__0__V43))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    };

    if (__0this->__O1__4expr.tp) {
        switch (__1b) {
        case 85:
            break;
        case 177:
            __0this->__O4__4expr.mem = typ__4exprFP5table(__0this->__O4__4expr.mem, __1tbl);
        }

        ;
        return __0this;
    }

    switch (__1b) {
        const void *__2__X91;

        register struct cast *__0__X92;

        struct type *__2__X93;

    case 177: {
        struct ea __0__V44;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"mdot %s",
            (const struct ea *)((__2__X91 = (const void *)__0this->__O3__4expr.string2),
                                (((&__0__V44)->__O1__2ea.p = __2__X91), (&__0__V44))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    case 144:
        error__FPCc((const char *)"emptyE");
        __0this->__O1__4expr.tp = (struct type *)any_type;
    case 162: {
        Pexpr __3e;

        __3e = do_dtor__FP4typeP4expr((struct type *)0, __0this);
        return ((__3e->base__4node == 85) ? typ__4exprFP5table(__3e, __1tbl) : __3e);
    }

    case 86:
        __0this->__O1__4expr.tp = (struct type *)zero_type;
        return __0this;

    case 150:
        __0this->__O1__4expr.tp = (struct type *)int_type;
        return __0this;

    case 82: {
        int __3ll;

        char *__3str_tmp;

        __3ll = strlen(__0this->__O2__4expr.string);

        switch (__0this->__O2__4expr.string[(__3ll - 1)]) {
        case 'l':
        case 'L':
            switch (__0this->__O2__4expr.string[(__3ll - 2)]) {
            case 'u':
            case 'U':
                __3str_tmp = strdup(__0this->__O2__4expr.string);
                (__3str_tmp[(__3ll - 2)]) = 0;

                __0this->__O2__4expr.string = (const char *)__3str_tmp;
            ulng:
                __0this->__O1__4expr.tp = (struct type *)ulong_type;
                goto cast_n_save;
            case 'l':
            case 'L':
                switch (__0this->__O2__4expr.string[(__3ll - 3)]) {
                case 'u':
                case 'U':
                    __3str_tmp = strdup(__0this->__O2__4expr.string);
                    (__3str_tmp[(__3ll - 3)]) = 0;

                    __0this->__O2__4expr.string = (const char *)__3str_tmp;
                ullng:
                    __0this->__O1__4expr.tp = (struct type *)ullong_type;
                    goto cast_n_save;
                }
            llng:
                __0this->__O1__4expr.tp = (struct type *)llong_type;
                goto save;
            }
        lng:
            __0this->__O1__4expr.tp = (struct type *)long_type;
            goto save;
        case 'u':
        case 'U':
            switch (__0this->__O2__4expr.string[(__3ll - 2)]) {
            case 'l':
            case 'L':
                switch (__0this->__O2__4expr.string[(__3ll - 3)]) {
                case 'l':
                case 'L':
                    __3str_tmp = strdup(__0this->__O2__4expr.string);
                    (__3str_tmp[(__3ll - 3)]) = 0;

                    __0this->__O2__4expr.string = (const char *)__3str_tmp;
                    goto ullng;
                }
                __3str_tmp = strdup(__0this->__O2__4expr.string);
                (__3str_tmp[(__3ll - 2)]) = 0;

                __0this->__O2__4expr.string = (const char *)__3str_tmp;
                goto ulng;
            default:
                __3str_tmp = strdup(__0this->__O2__4expr.string);
                (__3str_tmp[(__3ll - 1)]) = 0;

                __0this->__O2__4expr.string = (const char *)__3str_tmp;
            labuint:
                __0this->__O1__4expr.tp = (struct type *)uint_type;
                goto cast_n_save;
            }
        }

        if ((__0this->__O2__4expr.string[0]) == '0') {
            int __4index;

            __4index = 1;
            switch (__0this->__O2__4expr.string[1]) {
            case 'x':
            case 'X': {
                while ((__0this->__O2__4expr.string[(++__4index)]) == '0')
                    ;
                __3ll -= __4index;
                {
                    int __6HSZ;

                    __6HSZ = (SZ_INT + SZ_INT);
                    if (__3ll < __6HSZ)
                        goto nrm;
                    if (__3ll == __6HSZ)
                        if ((__0this->__O2__4expr.string[2]) >= '8')
                            goto labuint;
                        else
                            goto nrm;
                    if (SZ_INT == SZ_LLONG)
                        break;
                    __6HSZ = (SZ_LONG + SZ_LONG);
                    if (__3ll < __6HSZ)
                        goto lng;
                    if (__3ll == __6HSZ)
                        if ((__0this->__O2__4expr.string[2]) >= '8')
                            goto ulng;
                        else
                            goto lng;
                    if (SZ_LONG == SZ_LLONG)
                        break;
                    __6HSZ = (SZ_LLONG + SZ_LLONG);
                    if (__3ll < __6HSZ)
                        goto llng;
                    if (__3ll == __6HSZ)
                        if ((__0this->__O2__4expr.string[2]) >= '8')
                            goto ullng;
                        else
                            goto llng;
                    break;
                }
            }
            default: {
                int __6IBITS;

                __6IBITS = (BI_IN_BYTE * SZ_INT);
                while ((__0this->__O2__4expr.string[__4index]) == '0')
                    __4index++;
                {
                    char __6x;
                    int __6lbt;

                    int __6nbits;

                    __6x = (__0this->__O2__4expr.string[__4index]);
                    __6lbt = ((__6x == '1') ? 1 : (((__6x == '2') || (__6x == '3')) ? 2 : 3));

                    __6nbits = ((((__3ll - __4index) - 1) * 3) + __6lbt);
                    if (__6nbits < __6IBITS)
                        goto nrm;
                    if (__6nbits == __6IBITS)
                        goto labuint;
                    if (__6nbits < (BI_IN_BYTE * SZ_LONG))
                        goto lng;
                    if (__6nbits == (BI_IN_BYTE * SZ_LONG))
                        goto ulng;
                    if (__6nbits < (BI_IN_BYTE * SZ_LLONG))
                        goto llng;
                }
            }
            }
            goto ullng;
        } else {
            if (__3ll < chars_in_largest) {
            nrm:
                __0this->__O1__4expr.tp = (struct type *)int_type;
                goto save;
            }
            if (__3ll == chars_in_largest) {
                const char *__5p;
                const char *__5q;

                __5p = __0this->__O2__4expr.string;
                __5q = LARGEST_INT;
                do
                    if (((*__5p)) > ((*__5q))) {
                        if (SZ_INT == SZ_LONG)
                            goto ulng;
                        goto lng;
                    }
                while ((((*(__5p++))) == ((*(__5q++)))) && ((*__5p)));

                goto nrm;
            }

            if (__3ll < chars_in_largestl)
                goto lng;
            if (__3ll == chars_in_largestl) {
                const char *__5p;
                const char *__5q;

                __5p = __0this->__O2__4expr.string;
                __5q = LARGEST_LONG;
                do
                    if (((*__5p)) > ((*__5q))) {
                        if (SZ_LONG == SZ_LLONG)
                            goto ullng;
                        goto llng;
                    }
                while ((((*(__5p++))) == ((*(__5q++)))) && ((*__5p)));

                goto lng;
            }

            if (__3ll < chars_in_largestll)
                goto llng;

            {
                const char *__4p;
                const char *__4q;

                __4p = __0this->__O2__4expr.string;
                __4q = LARGEST_LLONG;
                do
                    if (((*__4p)) > ((*__4q))) {
                        goto ullng;
                    }
                while ((((*(__4p++))) == ((*(__4q++)))) && ((*__4p)));

                goto llng;
            }
        }
    }
    case 84:
        __0this->__O1__4expr.tp =
            (struct type *)((c_strlen__FPCc(__0this->__O2__4expr.string) < 5) ? char_type
                                                                              : int_type);
        goto save;

    case 83: {
        int __3ll;

        char *__3str_tmp;
        int __3last;

        __3ll = strlen(__0this->__O2__4expr.string);
        __3last = (__0this->__O2__4expr.string[(__3ll - 1)]);
        __0this->__O1__4expr.tp = (struct type *)double_type;
        if ((__3last == 'F') || (__3last == 'f')) {
            __0this->__O1__4expr.tp = (struct type *)float_type;
            if (!ansi_opt) {
                __3str_tmp = strdup(__0this->__O2__4expr.string);
                (__3str_tmp[(__3ll - 1)]) = 0;

                __0this->__O2__4expr.string = (const char *)__3str_tmp;
                goto cast_n_save;
            }
        } else if ((__3last == 'L') || (__3last == 'l')) {
            if (ansi_opt == 0) {
                __3str_tmp = strdup(__0this->__O2__4expr.string);

                (__3str_tmp[(__3ll - 1)]) = 0;

                __0this->__O2__4expr.string = (const char *)__3str_tmp;
            }
            __0this->__O1__4expr.tp = (struct type *)ldouble_type;
        }
        goto save;
    }
    case 81: {
        Pvec __3v;

        __3v = __ct__3vecFP4typeP4expr((struct vec *)0, (struct type *)char_type, (struct expr *)0);
        __3v->size__3vec = c_strlen__FPCc(__0this->__O2__4expr.string);
        __0this->__O1__4expr.tp = (struct type *)__3v;
    }
    save:
        if (const_save) {
            char *__3p;

            __3p = (((char *)__nw__FUl(
                (size_t)((sizeof(char)) * (strlen(__0this->__O2__4expr.string) + 1)))));

            strcpy(__3p, __0this->__O2__4expr.string);
            __0this->__O2__4expr.string = (const char *)__3p;
        }

        return __0this;

    cast_n_save:
        if (const_save) {
            char *__3p;

            __3p = (((char *)__nw__FUl(
                (size_t)((sizeof(char)) * (strlen(__0this->__O2__4expr.string) + 1)))));

            strcpy(__3p, __0this->__O2__4expr.string);
            __0this->__O2__4expr.string = (const char *)__3p;
        }

        return (struct expr *)((__0__X92 = 0),
                               ((__2__X93 = __0this->__O1__4expr.tp),
                                (((__0__X92 || (__0__X92 = (struct cast *)__nw__4exprSFUl(
                                                    (size_t)(sizeof(struct cast)))))
                                      ? ((__0__X92 = (struct cast *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X92), (unsigned char)191,
                                              __0this, (struct expr *)0)),
                                         (__0__X92->__O1__4expr.tp =
                                              (__0__X92->__O4__4expr.tp2 = __2__X93)))
                                      : 0),
                                 __0__X92)));

    case 34:
        ((__0this ? (((void)(__0this ? (((void)(((void)__dl__4exprSFPvUl(
                                           (void *)__0this, (size_t)(sizeof(struct expr)))))))
                                     : (((void)0)))))
                  : (((void)0))));
        if (cc->c_this__11dcl_context) {
            struct name *__0__X94;

            ((__0__X94 = cc->c_this__11dcl_context), ((__0__X94->n_used__4name++), (((void)0))));
            return (struct expr *)cc->c_this__11dcl_context;
        }
        error__FPCc((const char *)"``this'' used in nonC context");
        __1n = __ct__4nameFPCc((struct name *)0, (const char *)"this");
        __1n->__O1__4expr.tp = (struct type *)any_type;
        return (struct expr *)insert__5tableFP4nameUc(__1tbl, __1n, (unsigned char)0);

    case 85: {
        Pname __3q;
        Pexpr __3ee;

        __3q = (((struct name *)(((struct name *)__0this))))->__O2__4name.n_qualifier;
        __3ee = find_name__FP4nameP8classdefP5tableiT1(((struct name *)(((struct name *)__0this))),
                                                       cc->cot__11dcl_context, __1tbl, 0,
                                                       cc->nof__11dcl_context);
        if (__3q && ((__3ee->base__4node == 44) || (__3ee->base__4node == 45)))
            __3ee->__O3__4expr.n_initializer = (((struct expr *)(((struct expr *)__3q))));

        if (((((cc->nof__11dcl_context &&
                (((struct fct *)(((struct fct *)cc->nof__11dcl_context->__O1__4expr.tp))))
                    ->f_const__3fct) &&
               ((__3ee->base__4node == 44) || (__3ee->base__4node == 45))) &&
              __3ee->__O1__4expr.tp) &&
             (skiptypedefs__4typeFv(__3ee->__O1__4expr.tp)->base__4node != 108)) &&
            (skiptypedefs__4typeFv(__3ee->__O1__4expr.tp)->base__4node != 76))
            __3ee->__O1__4expr.tp = mkconst__4typeFv(__3ee->__O1__4expr.tp);

        if (is_ref__4typeFv(__3ee->__O1__4expr.tp))
            return contents__4exprFv(__3ee);

        if ((__3ee->base__4node == 85) &&
            (((struct name *)(((struct name *)__3ee))))->n_xref__4name) {
            __3ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111, __3ee,
                                           (struct expr *)0);
            __3ee->__O1__4expr.tp = __3ee->__O2__4expr.e1->__O1__4expr.tp;
        }

        return __3ee;
    }

    case 112:
        if (__0this->__O3__4expr.e2->base__4node == 34) {
            error__FPCc((const char *)"&this");
            break;
        }
    case 145:
        if (__0this->__O3__4expr.e2->base__4node == 85)
            __0this->__O3__4expr.e2 = find_name__FP4nameP8classdefP5tableiT1(
                ((struct name *)(((struct name *)__0this->__O3__4expr.e2))), cc->cot__11dcl_context,
                __1tbl, 112, cc->nof__11dcl_context);

        if (((((cc->nof__11dcl_context &&
                (((struct fct *)(((struct fct *)cc->nof__11dcl_context->__O1__4expr.tp))))
                    ->f_const__3fct) &&
               ((__0this->__O3__4expr.e2->base__4node == 44) ||
                (__0this->__O3__4expr.e2->base__4node == 45))) &&
              __0this->__O3__4expr.e2->__O1__4expr.tp) &&
             (skiptypedefs__4typeFv(__0this->__O3__4expr.e2->__O1__4expr.tp)->base__4node !=
              108)) &&
            (skiptypedefs__4typeFv(__0this->__O3__4expr.e2->__O1__4expr.tp)->base__4node != 76))
            __0this->__O3__4expr.e2->__O1__4expr.tp =
                mkconst__4typeFv(__0this->__O3__4expr.e2->__O1__4expr.tp);

        if ((__0this->__O3__4expr.e2->base__4node == 85) &&
            (((struct name *)(((struct name *)__0this->__O3__4expr.e2))))->n_xref__4name) {
            __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                (struct expr *)0, (unsigned char)111, __0this->__O3__4expr.e2, (struct expr *)0);
            __0this->__O3__4expr.e2->__O1__4expr.tp =
                __0this->__O3__4expr.e2->__O2__4expr.e1->__O1__4expr.tp;
        }
        if (__0this->__O3__4expr.e2->base__4node == 45) {
            switch (__0this->__O3__4expr.e2->__O2__4expr.e1->base__4node) {
            case 109:
            case 146: {
                Pcall __5c;
                __5c =
                    (((struct call *)(((struct call *)__0this->__O3__4expr.e2->__O2__4expr.e1))));
                if (__5c && __5c->__O2__4expr.e1) {
                    __5c->__O2__4expr.e1 = typ__4exprFP5table(__5c->__O2__4expr.e1, __1tbl);
                    if (__5c->__O2__4expr.e1->__O1__4expr.tp &&
                        ((((struct fct *)(((struct fct *)__5c->__O2__4expr.e1->__O1__4expr.tp))))
                             ->returns__3fct->base__4node == 158))
                        break;
                }
            }
            case 157:
                error__FPCc((const char *)"& non-lvalue");
            }
        }
        break;

    case 30:
        if (__0this->__O4__4expr.tp2) {
            dcl__4typeFP5table(__0this->__O4__4expr.tp2, __1tbl);
            switch (__0this->__O4__4expr.tp2->base__4node) {
            case 38:
                error__FPCc((const char *)"sizeof(void)");

                break;
            case 6: {
                Pclass __5cl;

                __5cl = (((struct classdef *)(((struct classdef *)__0this->__O4__4expr.tp2))));
                if ((__5cl->c_body__8classdef == 1) && ((__5cl->defined__4type & 3) == 0))
                    error__FiPCc((int)'s', (const char *)"class defined within sizeof");
            }
            }

            if (__0this->__O2__4expr.e1 && (__0this->__O2__4expr.e1 != dummy)) {
                __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
                if (__0this->__O2__4expr.e1 && (__0this->__O2__4expr.e1->permanent__4node == 0))
                    del__4exprFv(__0this->__O2__4expr.e1);
                __0this->__O2__4expr.e1 = dummy;
            }
            {
                Pptr __3r;

                __3r = is_ref__4typeFv(__0this->__O4__4expr.tp2);
                if (__3r)
                    __0this->__O4__4expr.tp2 = __3r->typ__5pvtyp;
            }
        } else if (__0this->__O2__4expr.e1 == dummy) {
            error__FPCc((const char *)"sizeof emptyE");

            __0this->__O1__4expr.tp = (struct type *)any_type;
            return __0this;
        } else {
            ++processing_sizeof;
            __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
            --processing_sizeof;
            __0this->__O4__4expr.tp2 = __0this->__O2__4expr.e1->__O1__4expr.tp;
            if (__0this->__O4__4expr.tp2->base__4node == 110)
                __0this->__O4__4expr.tp2->permanent__4node = 1;
            if (__0this->__O2__4expr.e1->base__4node == 124)
                __0this->__O2__4expr.e1 = dummy;
            else if (__0this->__O4__4expr.tp2 == (((struct type *)char_type)))
                __0this->__O2__4expr.e1 = dummy;
        }
        ((void)tsizeof__4typeFi(__0this->__O4__4expr.tp2, 0));
        if (__0this->__O4__4expr.tp2->base__4node == 38)
            error__FPCc((const char *)"sizeof(void)");
        __0this->__O1__4expr.tp = size_t_type;
        return __0this;

    case 113:
    case 191: {
        Pexpr __3ee;

        __3ee = docast__4exprFP5table(__0this, __1tbl);
        return (is_ref__4typeFv(__3ee->__O1__4expr.tp) ? contents__4exprFv(__3ee) : __3ee);
    }

    case 157:
        return dovalue__4exprFP5table(__0this, __1tbl);

    case 23:
    case 213:
    case 184:
        return donew__4exprFP5table(__0this, __1tbl);

    case 9:
    case 212:
    case 188: {
        int __3i;

        struct type *__0__X95;

        __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
        if (skiptypedefs__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp)->base__4node == 119) {
            Pexpr __4x;

            __4x = try_to_coerce__FP4typeP4exprPCcP5table(Pvoid_type, __0this->__O2__4expr.e1,
                                                          (const char *)"argument", __1tbl);

            if (__4x)
                __0this->__O2__4expr.e1 = __4x;
        }
        __3i = ((__0__X95 = __0this->__O2__4expr.e1->__O1__4expr.tp),
                (kind__4typeFUcN21(__0__X95, ((unsigned char)9), (unsigned char)'P',
                                   (unsigned char)1)));
        if (__3i != 'P')
            error__FPCc((const char *)"nonP deleted");
        if (__0this->__O3__4expr.e2) {
            struct type *__0__X96;

            __0this->__O3__4expr.e2 = typ__4exprFP5table(__0this->__O3__4expr.e2, __1tbl);
            ((__0__X96 = __0this->__O3__4expr.e2->__O1__4expr.tp),
             (kind__4typeFUcN21(__0__X96, ((unsigned char)9), (unsigned char)'I',
                                (unsigned char)1)));
        }
        __0this->__O1__4expr.tp = (struct type *)void_type;
        return __0this;
    }

    case 124:
        __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
        __0this->__O1__4expr.tp = (struct type *)any_type;
        return __0this;

    case 140: {
        Pexpr __3e;
        Pexpr __3ex;

        if ((__0this->__O2__4expr.e1 == dummy) && (__0this->__O3__4expr.e2 == 0)) {
            error__FPCc((const char *)"emptyIrL");
            __0this->__O1__4expr.tp = (struct type *)any_type;
            return __0this;
        }

        for (__3e = __0this; __3e; __3e = __3ex) {
            Pexpr __4ee;

            unsigned long __2__X97;

            __4ee = __3e->__O2__4expr.e1;

            if (__3e->base__4node != 140) {
                struct ea __0__V45;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"elist%k",
                    (const struct ea *)((__2__X97 = __3e->base__4node),
                                        (((((&__0__V45)->__O1__2ea.i = __2__X97), 0)),
                                         (&__0__V45))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__3ex = __3e->__O3__4expr.e2) {
                if (__4ee == dummy)
                    error__FPCc((const char *)"EX in EL");
                if ((__3ex->__O2__4expr.e1 == dummy) && (__3ex->__O3__4expr.e2 == 0)) {
                    if (__3ex && (__3ex->permanent__4node == 0))
                        del__4exprFv(__3ex);

                    __3e->__O3__4expr.e2 = (__3ex = 0);
                }
            }
            __3e->__O2__4expr.e1 = typ__4exprFP5table(__4ee, __1tbl);
            __1t = __3e->__O2__4expr.e1->__O1__4expr.tp;
            if (__1t->base__4node == 108) {
                __4ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145,
                                               (struct expr *)0, __3e->__O2__4expr.e1);
                __3e->__O2__4expr.e1 = typ__4exprFP5table(__4ee, __1tbl);
                __1t = __3e->__O2__4expr.e1->__O1__4expr.tp;
            }
        }
        __0this->__O1__4expr.tp = __1t;
        return __0this;
    }

    case 45:
    case 44: {
        if (__0this->__O3__4expr.e2) {
            if (__1b == 44)
                __1b = (__0this->base__4node = 180);
            if ((__0this->__O3__4expr.e2->base__4node == 85) &&
                ((((struct name *)(((struct name *)__0this->__O3__4expr.e2))))->permanent__4node !=
                 1))
                (((struct name *)(((struct name *)__0this->__O3__4expr.e2))))->permanent__4node = 1;
            break;
        }

        {
            Pbase __3b;
            bit __3bcc;

            __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
            __1t =
                skiptypedefs__4typeFRUc(__0this->__O2__4expr.e1->__O1__4expr.tp, (bit *)(&__3bcc));

            if ((((__0this->base__4node == 45) && (__0this->__O2__4expr.e1->base__4node == 111)) &&
                 (__0this->__O2__4expr.e1->__O2__4expr.e1->base__4node == 85)) &&
                is_probably_temp__FPCc(
                    (((struct name *)(((struct name *)__0this->__O2__4expr.e1->__O2__4expr.e1))))
                        ->__O2__4expr.string))
                __3bcc = 0;

            if (__0this->base__4node == 44) {
                switch (__1t->base__4node) {
                    const void *__2__X104;

                case 119: {
                    Pname __6n;

                    __6n = has_oper__8classdefFUc(classtype__4typeFv(__1t), (unsigned char)44);
                    if (__6n) {
                        struct ref *__0__X98;

                        struct expr *__2__X99;

                        struct expr *__2__X100;

                        struct call *__0__X101;

                        struct expr *__2__X102;

                        struct expr *__2__X103;

                        __6n->n_used__4name += 2;
                        __0this->__O2__4expr.e1 =
                            (struct expr
                                 *)((__0__X101 = 0),
                                    ((__2__X102 =
                                          (struct expr
                                               *)((__0__X98 = 0),
                                                  ((__2__X99 = __0this->__O2__4expr.e1),
                                                   ((__2__X100 = (struct expr *)__ct__4nameFPCc(
                                                         (struct name *)0,
                                                         __6n->__O2__4expr.string)),
                                                    (((__0__X98 ||
                                                       (__0__X98 = (struct ref *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct ref)))))
                                                          ? ((__0__X98 = (struct ref *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X98),
                                                                      ((unsigned char)45), __2__X99,
                                                                      (struct expr *)0)),
                                                             (__0__X98->__O4__4expr.mem =
                                                                  __2__X100))
                                                          : 0),
                                                     __0__X98))))),
                                     ((__2__X103 = 0),
                                      (((__0__X101 || (__0__X101 = (struct call *)__nw__4exprSFUl(
                                                           (size_t)(sizeof(struct call)))))
                                            ? (__0__X101 = (struct call *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X101), (unsigned char)109,
                                                   __2__X102, __2__X103))
                                            : 0),
                                       __0__X101))));

                        return typ__4exprFP5table(__0this, __1tbl);
                    }
                }
                default: {
                    struct ea __0__V46;

                    error__FPCcRC2eaN32(
                        (const char *)"nonP ->%n",
                        (const struct ea *)((__2__X104 = (const void *)__0this->__O4__4expr.mem),
                                            (((&__0__V46)->__O1__2ea.p = __2__X104), (&__0__V46))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    __1t = (struct type *)any_type;

                case 141:
                    goto qqq;
                case 125:
                case 110:
                    __3b = (((struct basetype *)(((struct basetype *)skiptypedefs__4typeFRUc(
                        (((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp,
                        (bit *)(&__3bcc))))));
                    __0this->__O4__4expr.mem =
                        do_qualifiers__FP4typeP4expr((struct type *)__3b, __0this->__O4__4expr.mem);
                    if (__0this->__O4__4expr.mem->base__4node == 162)
                        __0this->__O4__4expr.mem =
                            do_dtor__FP4typeP4expr((struct type *)__3b, __0this->__O4__4expr.mem);
                }
                }
            } else {
            qqq:
                __0this->__O4__4expr.mem =
                    do_qualifiers__FP4typeP4expr(__1t, __0this->__O4__4expr.mem);
                switch (__1t->base__4node) {
                    const void *__2__X105;

                default:
                    if (__0this->__O4__4expr.mem->base__4node == 162)
                        __0this->__O4__4expr.mem =
                            do_dtor__FP4typeP4expr(__1t, __0this->__O4__4expr.mem);
                    if (__0this->__O4__4expr.mem->base__4node == 162)
                        break;
                    {
                        struct ea __0__V47;

                        error__FPCcRC2eaN32(
                            (const char *)"nonO .%n",
                            (const struct ea *)((__2__X105 =
                                                     (const void *)__0this->__O4__4expr.mem),
                                                (((&__0__V47)->__O1__2ea.p = __2__X105),
                                                 (&__0__V47))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

                        __1t = (struct type *)any_type;
                    case 141:
                        break;
                    case 119:
                        if (__0this->__O4__4expr.mem->base__4node == 162)
                            __0this->__O4__4expr.mem =
                                do_dtor__FP4typeP4expr(__1t, __0this->__O4__4expr.mem);
                    }
                }

                switch (__0this->__O2__4expr.e1->base__4node) {
                case 68:
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
                case 71:
                case 147:
                    __0this->base__4node = 44;
                    __0this->__O2__4expr.e1 = address__4exprFv(__0this->__O2__4expr.e1);
                    break;
                case 109:
                case 146: {
                    Pname __6tmp;

                    __6tmp = make_tmp__FcP4typeP5table('Q', __0this->__O2__4expr.e1->__O1__4expr.tp,
                                                       __1tbl);

                    __0this->__O2__4expr.e1 =
                        init_tmp__FP4nameP4exprP5table(__6tmp, __0this->__O2__4expr.e1, __1tbl);
                    {
                        Pexpr __6aa;

                        __6aa = address__4exprFv((struct expr *)__6tmp);
                        __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                            (struct expr *)0, (unsigned char)147, __0this->__O2__4expr.e1, __6aa);
                        __0this->__O2__4expr.e1->__O1__4expr.tp = __6aa->__O1__4expr.tp;
                        __0this->base__4node = 44;
                        break;
                    }
                }
                }
                __3b = (((struct basetype *)(((struct basetype *)__1t))));
            }

            switch (__3b->base__4node) {
                const void *__2__X106;

                unsigned long __2__X107;

            default:
                if (__0this->__O4__4expr.mem->base__4node == 162) {
                    return __0this->__O4__4expr.mem;
                } else {
                    struct ea __0__V48;

                    struct ea __0__V49;

                    struct ea __0__V50;

                    struct ea __0__V51;

                    error__FPCcRC2eaN32(
                        (const char *)"(%t) before%k%n (%n not aM)",
                        (const struct ea *)((__2__X106 = (const void *)__0this->__O2__4expr.e1
                                                             ->__O1__4expr.tp),
                                            (((&__0__V48)->__O1__2ea.p = __2__X106), (&__0__V48))),
                        (const struct ea *)((__2__X107 = __0this->base__4node),
                                            (((((&__0__V49)->__O1__2ea.i = __2__X107), 0)),
                                             (&__0__V49))),
                        (const struct ea *)__ct__2eaFPCv(&__0__V50,
                                                         (const void *)__0this->__O4__4expr.mem),
                        (const struct ea *)__ct__2eaFPCv(&__0__V51,
                                                         (const void *)__0this->__O4__4expr.mem));
                }
            case 141:
                __0this->__O1__4expr.tp = (struct type *)any_type;
                return __0this;
            case 119: {
                Pclass __5cl;

                __5cl = classtype__4typeFv((struct type *)__3b);
                if (__5cl->c_body__8classdef == 1)
                    dcl_print__8classdefFP4name(__5cl, (struct name *)0);
                break;
            }
            }

            if (__0this->__O4__4expr.mem->__O1__4expr.tp) {
                __0this->__O1__4expr.tp = __0this->__O4__4expr.mem->__O1__4expr.tp;
                {
                    {
                        Pexpr __4ee;

                        __4ee = __0this->__O4__4expr.mem;

                        for (; __4ee->base__4node == 44; __4ee = __4ee->__O2__4expr.e1) {
                            if (__4ee->__O2__4expr.e1 ==
                                (((struct expr *)cc->c_this__11dcl_context))) {
                                __4ee->__O2__4expr.e1 = __0this->__O2__4expr.e1;
                                __4ee->base__4node = __0this->base__4node;
                                if (((__3bcc && __0this->__O4__4expr.mem->__O1__4expr.tp) &&
                                     (skiptypedefs__4typeFv(
                                          __0this->__O4__4expr.mem->__O1__4expr.tp)
                                          ->base__4node != 108)) &&
                                    (skiptypedefs__4typeFv(__0this->__O4__4expr.mem->__O1__4expr.tp)
                                         ->base__4node != 76))
                                    __0this->__O4__4expr.mem->__O1__4expr.tp =
                                        mkconst__4typeFv(__0this->__O4__4expr.mem->__O1__4expr.tp);
                                return (is_ref__4typeFv(__0this->__O4__4expr.mem->__O1__4expr.tp)
                                            ? contents__4exprFv(__0this->__O4__4expr.mem)
                                            : __0this->__O4__4expr.mem);
                            }
                        }

                        return (is_ref__4typeFv(__0this->__O1__4expr.tp)
                                    ? contents__4exprFv(__0this)
                                    : __0this);
                    }
                }
            }

            {
                Pname __3q;

                __3q = (((struct name *)(((struct name *)__0this->__O4__4expr.mem))))
                           ->__O2__4name.n_qualifier;

                if ((!__3q) &&
                    (strcmp((((struct name *)(((struct name *)__0this->__O4__4expr.mem))))
                                ->__O2__4expr.string,
                            oper_name__FUc((unsigned char)162)) == 0)) {
                    (((struct name *)(((struct name *)__0this->__O4__4expr.mem))))
                        ->__O2__4name.n_qualifier =
                        (((struct name *)(((struct name *)__0this->__O4__4expr.mem))))
                            ->__O1__4name.n_dtag;
                }
                {
                    Pexpr __3e;

                    __3e = find_name__FP4nameP8classdefP5tableiT1(
                        ((struct name *)(((struct name *)__0this->__O4__4expr.mem))),
                        classtype__4typeFv((struct type *)__3b), (struct table *)0,
                        (int)__0this->base__4node, cc->nof__11dcl_context);
                    if (__3q && ((__3e->base__4node == 44) || (__3e->base__4node == 45))) {
                        (((struct name *)(((struct name *)__3e))))->__O3__4expr.n_initializer =
                            (((struct expr *)(((struct expr *)__3q))));
                    }

                    {
                        {
                            Pexpr __3ee;

                            __3ee = __3e;

                            for (; __3ee->base__4node == 44; __3ee = __3ee->__O2__4expr.e1) {
                                if (__3ee->__O2__4expr.e1 ==
                                    (((struct expr *)cc->c_this__11dcl_context))) {
                                    __3ee->__O2__4expr.e1 = __0this->__O2__4expr.e1;
                                    __3ee->base__4node = __0this->base__4node;
                                    if (((__3bcc && __3e->__O1__4expr.tp) &&
                                         (skiptypedefs__4typeFv(__3e->__O1__4expr.tp)
                                              ->base__4node != 108)) &&
                                        (skiptypedefs__4typeFv(__3e->__O1__4expr.tp)->base__4node !=
                                         76))
                                        __3e->__O1__4expr.tp =
                                            mkconst__4typeFv(__3e->__O1__4expr.tp);
                                    break;
                                }
                            }

                            if (__3e->base__4node == 85) {
                                switch (__3e->__O1__4expr.tp->base__4node) {
                                case 108:
                                case 76:
                                    __0this->__O4__4expr.mem = __3e;
                                    __0this->__O1__4expr.tp = __3e->__O1__4expr.tp;
                                    __3e = __0this;
                                }
                            }

                            return (is_ref__4typeFv(__3e->__O1__4expr.tp) ? contents__4exprFv(__3e)
                                                                          : __3e);
                        }
                    }
                }
            }
        }
    }

    case 109:
        if ((__0this->__O2__4expr.e1->base__4node == 85) &&
            (__0this->__O2__4expr.e1->__O1__4expr.tp == 0)) {
            Pname __3q;

            __3q = (((struct name *)(((struct name *)__0this->__O2__4expr.e1))))
                       ->__O2__4name.n_qualifier;
            __0this->__O2__4expr.e1 = find_name__FP4nameP8classdefP5tableiT1(
                ((struct name *)(((struct name *)__0this->__O2__4expr.e1))), cc->cot__11dcl_context,
                __1tbl, 109, cc->nof__11dcl_context);

            if (__3q && ((__0this->__O2__4expr.e1->base__4node == 44) ||
                         (__0this->__O2__4expr.e1->base__4node == 45)))
                __0this->__O2__4expr.e1->__O3__4expr.n_initializer =
                    (((struct expr *)(((struct expr *)__3q))));
        }

        if ((__0this->__O2__4expr.e1->base__4node == 85) &&
            (((struct name *)(((struct name *)__0this->__O2__4expr.e1))))->n_xref__4name) {
            __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                (struct expr *)0, (unsigned char)111, __0this->__O2__4expr.e1, (struct expr *)0);
            __0this->__O2__4expr.e1->__O1__4expr.tp =
                __0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp;
        }

        switch (__0this->__O2__4expr.e1->base__4node) {
        case 162:
            error__FiPCc((int)'e', (const char *)"O orP missing for explicit destructor call\n");
            break;
        case 45:
        case 44:
            if (((__0this->__O3__4expr.e2 == 0) &&
                 (((struct ref *)(((struct ref *)__0this->__O2__4expr.e1))))->__O4__4expr.mem) &&
                ((((struct ref *)(((struct ref *)__0this->__O2__4expr.e1))))
                     ->__O4__4expr.mem->base__4node == 162)) {
                Pref __4r;

                __4r = (((struct ref *)(((struct ref *)__0this->__O2__4expr.e1))));
                if (__4r->base__4node == 45) {
                    __4r->__O2__4expr.e1 =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)112,
                                               (struct expr *)0, __4r->__O2__4expr.e1);
                    __4r->base__4node = 44;
                }
                {
                    Pname __4m;
                    bit __4qual;
                    int __4tok;

                    __4m = (((struct name *)(((struct name *)__4r->__O4__4expr.mem))));
                    __4qual = (__4m->__O2__4name.n_qualifier != 0);
                    __4tok = (__4qual ? 0 : 44);

                    __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);

                    __4r = (((struct ref *)(((struct ref *)__0this->__O2__4expr.e1))));
                    __4m = (((struct name *)(((struct name *)__4r->__O4__4expr.mem))));
                    if (__4m->base__4node == 85) {
                        Pexpr __5ee;

                        __5ee = call_dtor__FP4exprN21iT1(__0this->__O2__4expr.e1->__O2__4expr.e1,
                                                         __4r->__O4__4expr.mem, (struct expr *)0,
                                                         __4tok, one);
                        __5ee->__O1__4expr.tp = (struct type *)void_type;
                        return __5ee;
                    }
                }
            }
        }
        break;

    case 68:
        Ntmp = 0;
        Ntmp_flag = 0;
        if (in_quest < 1) {
            Ntmp_refd = 0;
            Ntmp_flag_list = 0;
        }
        __0this->__O4__4expr.cond = typ__4exprFP5table(__0this->__O4__4expr.cond, __1tbl);
        in_quest++;
        if (Ntmp_refd) {
            Pname __3n;
            Pname __3nn;

            __3n = Ntmp_refd;
            __3nn = Ntmp_flag_list;
            for (; __3n && __3nn;
                 ((__3n = __3n->__O1__4name.n_list), (__3nn = __3nn->__O1__4name.n_list))) {
                Pname __4nc;

                __4nc = __ct__4nameFPCc((struct name *)0, (const char *)"");
                ((*__4nc)) = (*__3n);
                {
                    char *__4str;

                    __4str = (((char *)__nw__FUl(
                        (size_t)((sizeof(char)) * (strlen(__3n->__O2__4expr.string) + 1)))));

                    strcpy(__4str, __3n->__O2__4expr.string);
                    __4nc->__O2__4expr.string = (const char *)__4str;
                    {
                        Pname __4nnc;

                        __4nnc = __ct__4nameFPCc((struct name *)0, (const char *)"");
                        ((*__4nnc)) = (*__3nn);
                        __4str = (((char *)__nw__FUl(
                            (size_t)((sizeof(char)) * (strlen(__3nn->__O2__4expr.string) + 1)))));

                        strcpy(__4str, __3nn->__O2__4expr.string);
                        __4nnc->__O2__4expr.string = (const char *)__4str;
                        {
                            struct con_dtor *__4t;

                            struct con_dtor *__0__X108;

                            __4t = ((__0__X108 = 0),
                                    (((__0__X108 || (__0__X108 = (struct con_dtor *)__nw__FUl(
                                                         (size_t)(sizeof(struct con_dtor)))))
                                          ? (((__0__X108->tn__8con_dtor = __4nc),
                                              (__0__X108->condition__8con_dtor =
                                                   ((struct expr *)__4nnc))),
                                             (__0__X108->next__8con_dtor = 0))
                                          : 0),
                                     __0__X108));
                            if (pdlist)
                                __4t->next__8con_dtor = pdlist;
                            pdlist = __4t;
                        }
                    }
                }
            }
            Ntmp_flag = 0;
        }
        break;

    case 66:
    case 67:
        Ntmp = 0;
        Ntmp_flag = 0;
        if (in_quest < 2) {
            Ntmp_refd = 0;
            Ntmp_flag_list = 0;
        }
    }
    }

    if (__0this->__O2__4expr.e1) {
        __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
        if (is_ref__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp))
            __0this->__O2__4expr.e1 = contents__4exprFv(__0this->__O2__4expr.e1);
        __1t1 = __0this->__O2__4expr.e1->__O1__4expr.tp;
        if (Ntmp_flag) {
            if ((__1b == 68) || in_quest) {
                Pexpr __4e;

                __4e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                              (struct expr *)Ntmp_flag, one);
                __4e->__O1__4expr.tp = (struct type *)int_type;
                __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                    (struct expr *)0, (unsigned char)147, __4e, __0this->__O2__4expr.e1);
                __0this->__O2__4expr.e1->__O1__4expr.tp = __1t1;
            }
            Ntmp_flag = 0;
        }
    } else
        __1t1 = 0;

    if (__0this->__O3__4expr.e2) {
        __0this->__O3__4expr.e2 = typ__4exprFP5table(__0this->__O3__4expr.e2, __1tbl);
        if (is_ref__4typeFv(__0this->__O3__4expr.e2->__O1__4expr.tp))
            __0this->__O3__4expr.e2 = contents__4exprFv(__0this->__O3__4expr.e2);
        __1t2 = __0this->__O3__4expr.e2->__O1__4expr.tp;
        if (Ntmp_flag) {
            if ((__1b == 68) || in_quest) {
                Pexpr __4e;

                __4e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                              (struct expr *)Ntmp_flag, one);
                __4e->__O1__4expr.tp = (struct type *)int_type;
                if (__0this->__O3__4expr.e2->base__4node == 140) {
                    Ptype __5t;

                    __5t = __0this->__O3__4expr.e2->__O2__4expr.e1->__O1__4expr.tp;
                    __0this->__O3__4expr.e2->__O2__4expr.e1 =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147, __4e,
                                               __0this->__O3__4expr.e2->__O2__4expr.e1);

                    __0this->__O3__4expr.e2->__O2__4expr.e1->__O1__4expr.tp = __5t;
                } else {
                    __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                        (struct expr *)0, (unsigned char)147, __4e, __0this->__O3__4expr.e2);

                    __0this->__O3__4expr.e2->__O1__4expr.tp = __1t2;
                }
            }
            Ntmp_flag = 0;
        }
    } else
        __1t2 = 0;

    switch (__1b) {
    default: {
        Pexpr __3x;

        __3x = oper_overload__4exprFP5table(__0this, __1tbl);
        if (__3x) {
            if ((((__3x->__O1__4expr.tp != (((struct type *)any_type))) &&
                  ((__1b == 48) || (__1b == 49))) &&
                 (__3x->base__4node != 48)) &&
                (__3x->base__4node != 49)) {
            }
            return __3x;
        }
        if ((__1t2 && (__1t1 == 0)) && (__1t2 != __0this->__O3__4expr.e2->__O1__4expr.tp))
            __1t2 = __0this->__O3__4expr.e2->__O1__4expr.tp;
    }
    case 45:
    case 147:
    case 145:
    case 146:
    case 68:
        break;
    }

    switch (__1b) {
    case 68:
        in_quest--;
    case 66:
    case 67:
        if (Ntmp && (__1b != 68)) {
            Ntmp_dtor =
                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __0this, Ntmp_dtor);
        }

        if ((__1b == 68) && Ntmp_refd) {
            Pname __3n;
            Pname __3nn;

            __3n = Ntmp_refd;
            __3nn = Ntmp_flag_list;
            for (; __3n && __3nn;
                 ((__3n = __3n->__O1__4name.n_list), (__3nn = __3nn->__O1__4name.n_list))) {
                Pname __4nc;

                __4nc = __ct__4nameFPCc((struct name *)0, (const char *)"");
                ((*__4nc)) = (*__3n);
                {
                    char *__4str;

                    __4str = (((char *)__nw__FUl(
                        (size_t)((sizeof(char)) * (strlen(__3n->__O2__4expr.string) + 1)))));

                    strcpy(__4str, __3n->__O2__4expr.string);
                    __4nc->__O2__4expr.string = (const char *)__4str;
                    {
                        Pname __4nnc;

                        __4nnc = __ct__4nameFPCc((struct name *)0, (const char *)"");
                        ((*__4nnc)) = (*__3nn);
                        __4str = (((char *)__nw__FUl(
                            (size_t)((sizeof(char)) * (strlen(__3nn->__O2__4expr.string) + 1)))));

                        strcpy(__4str, __3nn->__O2__4expr.string);
                        __4nnc->__O2__4expr.string = (const char *)__4str;
                        {
                            struct con_dtor *__4t;

                            struct con_dtor *__0__X109;

                            __4t = ((__0__X109 = 0),
                                    (((__0__X109 || (__0__X109 = (struct con_dtor *)__nw__FUl(
                                                         (size_t)(sizeof(struct con_dtor)))))
                                          ? (((__0__X109->tn__8con_dtor = __4nc),
                                              (__0__X109->condition__8con_dtor =
                                                   ((struct expr *)__4nnc))),
                                             (__0__X109->next__8con_dtor = 0))
                                          : 0),
                                     __0__X109));
                            if (pdlist)
                                __4t->next__8con_dtor = pdlist;
                            pdlist = __4t;
                        }
                    }
                }
            }
            Ntmp_flag = 0;
        }
    }

    __1t = ((__1t1 == 0) ? __1t2 : ((__1t2 == 0) ? __1t1 : (((struct type *)0))));
    switch (__1b) {
    case 180:
        __0this->base__4node = 44;

    case 45: {
        Pexpr __3a;
        Ptype __3at;

        __3a = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
        __3at = skiptypedefs__4typeFv(__3a->__O1__4expr.tp);
        if (__0this->base__4node == 45) {
            __3a = address__4exprFv(__3a);
            __3at =
                (struct type *)(__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __3at));
        }

        {
            Pname __3cn;
            Pclass __3mm;

            Pexpr __3p;
            Ptype __3pt;
            Pname __3pcn;

            __3cn =
                ((__3at->base__4node == 125)
                     ? is_cl_obj__4typeFv((((struct ptr *)(((struct ptr *)__3at))))->typ__5pvtyp)
                     : (((struct name *)0)));
            __3mm = (__3cn ? (((struct classdef *)(((struct classdef *)__3cn->__O1__4expr.tp))))
                           : (((struct classdef *)0)));

            __3p = typ__4exprFP5table(__0this->__O3__4expr.e2, __1tbl);
            __3pt = skiptypedefs__4typeFv(__3p->__O1__4expr.tp);
            __3pcn = is_cl_obj__4typeFv(__3pt);

            if (__3pcn) {
                Pclass __4cl;
                Pname __4found;

                __4cl = (((struct classdef *)(((struct classdef *)__3pcn->__O1__4expr.tp))));
                __4found = 0;
                {
                    {
                        Pname __4on;

                        __4on = __4cl->conv__8classdef;

                        for (; __4on; __4on = __4on->__O1__4name.n_list) {
                            Pfct __5f;
                            Pptr __5frt;

                            struct classdef *__1__X110;

                            struct classdef *__1__X111;

                            __5f = (((struct fct *)(((struct fct *)__4on->__O1__4expr.tp))));
                            __5frt = (((struct ptr *)((
                                (struct ptr *)skiptypedefs__4typeFv(__5f->returns__3fct)))));
                            if ((__5frt->base__4node != 125) ||
                                ((((struct ptr *)(((struct ptr *)__5frt))))->memof__3ptr == 0))
                                break;
                            if (((__1__X110 =
                                      (((struct ptr *)(((struct ptr *)__5frt))))->memof__3ptr),
                                 ((__1__X111 = __3mm),
                                  (((__1__X110 == __1__X111)
                                        ? 1
                                        : ((__1__X110 && __1__X111)
                                               ? (((int)same_class__8classdefFP8classdefi(
                                                     __1__X110, __1__X111, 0)))
                                               : 0))))) ||
                                has_base__8classdefFP8classdefiT2(
                                    __3mm, (((struct ptr *)(((struct ptr *)__5frt))))->memof__3ptr,
                                    0, 0)) {
                                if (__4found) {
                                    struct ea __0__V52;

                                    struct ea __0__V53;

                                    error__FPCcRC2eaN32(
                                        (const char
                                             *)"two possible conversions forP toM: %n and %n",
                                        (const struct ea *)(((&__0__V52)->__O1__2ea.p =
                                                                 ((const void *)__4found)),
                                                            (&__0__V52)),
                                        (const struct ea *)(((&__0__V53)->__O1__2ea.p =
                                                                 ((const void *)__4on)),
                                                            (&__0__V53)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                } else
                                    __4found = __4on;
                            }
                        }

                        if (__4found) {
                            struct ref *__0__X112;

                            struct expr *__2__X113;

                            struct expr *__2__X114;

                            struct call *__0__X115;

                            struct expr *__2__X116;

                            struct expr *__2__X117;

                            __3p =
                                (struct expr *)((__0__X112 = 0),
                                                ((__2__X113 = __3p),
                                                 ((__2__X114 = (struct expr *)__4found),
                                                  (((__0__X112 ||
                                                     (__0__X112 = (struct ref *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct ref)))))
                                                        ? ((__0__X112 = (struct ref *)
                                                                __ct__4exprFUcP4exprT2(
                                                                    ((struct expr *)__0__X112),
                                                                    ((unsigned char)45), __2__X113,
                                                                    (struct expr *)0)),
                                                           (__0__X112->__O4__4expr.mem = __2__X114))
                                                        : 0),
                                                   __0__X112))));
                            __3p = (struct expr *)((__0__X115 = 0),
                                                   ((__2__X116 = __3p),
                                                    ((__2__X117 = 0),
                                                     (((__0__X115 ||
                                                        (__0__X115 = (struct call *)__nw__4exprSFUl(
                                                             (size_t)(sizeof(struct call)))))
                                                           ? (__0__X115 = (struct call *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X115),
                                                                      (unsigned char)109, __2__X116,
                                                                      __2__X117))
                                                           : 0),
                                                      __0__X115))));
                            __3p = typ__4exprFP5table(__3p, __1tbl);
                            __3pt = skiptypedefs__4typeFv(__3p->__O1__4expr.tp);
                        }
                    }
                }
            }
            if ((__3pt->base__4node != 125) ||
                ((((struct ptr *)(((struct ptr *)__3pt))))->memof__3ptr == 0)) {
                if (__1b == 45) {
                    struct ea __0__V54;

                    error__FPCcRC2eaN32(
                        (const char *)"P toMX in .*E: %t",
                        (const struct ea *)(((&__0__V54)->__O1__2ea.p = ((const void *)__3pt)),
                                            (&__0__V54)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                } else {
                    struct ea __0__V55;

                    error__FPCcRC2eaN32(
                        (const char *)"P toMX in ->*E: %t",
                        (const struct ea *)(((&__0__V55)->__O1__2ea.p = ((const void *)__3pt)),
                                            (&__0__V55)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                __0this->__O1__4expr.tp = (struct type *)any_type;
                __0this->base__4node = 144;
                return __0this;
            }
            {
                Pclass __3pm;

                struct classdef *__1__X118;

                struct classdef *__1__X119;

                __3pm = (((struct ptr *)(((struct ptr *)__3pt))))->memof__3ptr;

                if (!((__1__X118 = __3mm),
                      ((__1__X119 = __3pm),
                       (((__1__X118 == __1__X119)
                             ? 1
                             : ((__1__X118 && __1__X119) ? (((int)same_class__8classdefFP8classdefi(
                                                               __1__X118, __1__X119, 0)))
                                                         : 0)))))) {
                    struct texpr *__0__X121;

                    struct type *__2__X122;

                    if (has_base__8classdefFP8classdefiT2(__3mm, __3pm, 0, 0) == 0) {
                        const void *__2__X120;

                        {
                            struct ea __0__V56;

                            struct ea __0__V57;

                            error__FPCcRC2eaN32(
                                (const char *)"badOT in .*E: %t (%s*X)",
                                (const struct ea *)((__2__X120 =
                                                         (const void *)__3a->__O1__4expr.tp),
                                                    (((&__0__V56)->__O1__2ea.p = __2__X120),
                                                     (&__0__V56))),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V57, (const void *)__3pm->string__8classdef),
                                (const struct ea *)ea0, (const struct ea *)ea0);

                            __0this->__O1__4expr.tp = (struct type *)any_type;
                        }
                    }
                    __3a = (struct expr
                                *)((__0__X121 = 0),
                                   ((__2__X122 = __3pm->this_type__8classdef),
                                    (((__0__X121 || (__0__X121 = (struct texpr *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct texpr)))))
                                          ? ((__0__X121 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X121), ((unsigned char)191),
                                                  __3a, (struct expr *)0)),
                                             (__0__X121->__O4__4expr.tp2 = __2__X122))
                                          : 0),
                                     __0__X121)));
                    __0this->__O2__4expr.e1 = (__3a = typ__4exprFP5table(__3a, __1tbl));
                }

                {
                    Ptype __3tpx;

                    __3tpx = skiptypedefs__4typeFv(
                        (((struct ptr *)(((struct ptr *)__3pt))))->typ__5pvtyp);

                    if (__3tpx->base__4node == 108) {
                        __0this->base__4node = 173;
                        __0this->__O4__4expr.tp2 = (struct type *)__3mm;
                        __0this->__O2__4expr.e1 = __3a;
                        __0this->__O3__4expr.e2 = __3p;
                    } else {
                        register struct cast *__0__X123;

                        struct type *__2__X124;

                        register struct cast *__0__X125;

                        struct type *__2__X126;

                        __3a = (struct expr
                                    *)((__0__X123 = 0),
                                       ((__2__X124 = Pchar_type),
                                        (((__0__X123 || (__0__X123 = (struct cast *)__nw__4exprSFUl(
                                                             (unsigned long)(sizeof(struct cast)))))
                                              ? ((__0__X123 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                      ((struct expr *)__0__X123),
                                                      (unsigned char)191, __3a, (struct expr *)0)),
                                                 (__0__X123->__O1__4expr.tp =
                                                      (__0__X123->__O4__4expr.tp2 = __2__X124)))
                                              : 0),
                                         __0__X123)));
                        __3p = (struct expr
                                    *)((__0__X125 = 0),
                                       ((__2__X126 = (struct type *)int_type),
                                        (((__0__X125 || (__0__X125 = (struct cast *)__nw__4exprSFUl(
                                                             (size_t)(sizeof(struct cast)))))
                                              ? ((__0__X125 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                      ((struct expr *)__0__X125),
                                                      (unsigned char)191, __3p, (struct expr *)0)),
                                                 (__0__X125->__O1__4expr.tp =
                                                      (__0__X125->__O4__4expr.tp2 = __2__X126)))
                                              : 0),
                                         __0__X125)));
                        __3p =
                            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)55, __3p, one);
                        __3p->__O1__4expr.tp = (struct type *)int_type;
                        {
                            Pexpr __4pl;

                            register struct cast *__0__X127;

                            __4pl = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)54,
                                                           __3a, __3p);
                            __4pl->__O1__4expr.tp = Pchar_type;
                            __0this->base__4node = 111;
                            __3pt = (struct type *)__ct__3ptrFUcP4type((struct ptr *)0,
                                                                       (unsigned char)125, __3tpx);
                            (((struct ptr *)(((struct ptr *)__3pt))))->b_const__4type =
                                (((struct ptr *)(((struct ptr *)__3tpx))))->b_const__4type;
                            __0this->__O2__4expr.e1 =
                                (struct expr
                                     *)((__0__X127 = 0),
                                        (((__0__X127 || (__0__X127 = (struct cast *)__nw__4exprSFUl(
                                                             (size_t)(sizeof(struct cast)))))
                                              ? ((__0__X127 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                      ((struct expr *)__0__X127),
                                                      (unsigned char)191, __4pl, (struct expr *)0)),
                                                 (__0__X127->__O1__4expr.tp =
                                                      (__0__X127->__O4__4expr.tp2 = __3pt)))
                                              : 0),
                                         __0__X127));
                            __0this->__O3__4expr.e2 = 0;
                        }
                    }
                    __0this->__O1__4expr.tp = __3tpx;
                    return (is_ref__4typeFv(__0this->__O1__4expr.tp) ? contents__4exprFv(__0this)
                                                                     : __0this);
                }
            }
        }
    }

    case 146:
    case 109:
        __0this->__O1__4expr.tp = call_fct__4exprFP5table(__0this, __1tbl);
        if (is_ref__4typeFv(__0this->__O1__4expr.tp))
            return contents__4exprFv(__0this);
        return __0this;

    case 111:
        if (__0this->__O2__4expr.e1 == dummy)
            error__FPCc((const char *)"O missing before []\n");
        if (__0this->__O3__4expr.e2 == dummy)
            error__FPCc((const char *)"subscriptE missing");

        if (__1t) {
            __1t = skiptypedefs__4typeFv(__1t);
            if ((__1t->base__4node == 125) && (((struct ptr *)(((struct ptr *)__1t))))->memof__3ptr)
                error__FPCc((const char *)"P toM dereferenced");
            __0this->__O1__4expr.tp = deref__4typeFv(__1t);
        } else {
            if (vec_type__4typeFv(__1t1)) {
                switch (__1t2->base__4node) {
                case 5:
                case 29:
                case 21:
                case 22:
                case 122:
                case 121:
                    break;
                default: {
                    Pname __6cn;

                    __6cn = is_cl_obj__4typeFv(__1t2);
                    if (__6cn)
                        __0this->__O3__4expr.e2 = check_cond__FP4exprUcP5table(
                            __0this->__O3__4expr.e2, (unsigned char)111, __1tbl);
                    else
                        (kind__4typeFUcN21(__1t2, ((unsigned char)111), (unsigned char)'I',
                                           (unsigned char)1));
                }
                }
                __1t1 = skiptypedefs__4typeFv(__1t1);
                if ((__1t1->base__4node == 125) &&
                    (((struct ptr *)(((struct ptr *)__1t1))))->memof__3ptr)
                    error__FPCc((const char *)"P toM dereferenced");
                __0this->__O1__4expr.tp = deref__4typeFv(__1t1);
                ((void)tsizeof__4typeFi(__0this->__O1__4expr.tp, 0));
            } else if (vec_type__4typeFv(__1t2)) {
                (kind__4typeFUcN21(__1t1, ((unsigned char)111), (unsigned char)'I',
                                   (unsigned char)1));
                __1t2 = skiptypedefs__4typeFv(__1t2);
                if ((__1t2->base__4node == 125) &&
                    (((struct ptr *)(((struct ptr *)__1t2))))->memof__3ptr)
                    error__FPCc((const char *)"P toM dereferenced");
                __0this->__O1__4expr.tp = deref__4typeFv(__1t2);
                ((void)tsizeof__4typeFi(__0this->__O1__4expr.tp, 0));
            } else {
                {
                    struct ea __0__V58;

                    struct ea __0__V59;

                    error__FPCcRC2eaN32(
                        (const char *)"[] applied to nonPT:%t[%t]",
                        (const struct ea *)(((&__0__V58)->__O1__2ea.p = ((const void *)__1t1)),
                                            (&__0__V58)),
                        (const struct ea *)(((&__0__V59)->__O1__2ea.p = ((const void *)__1t2)),
                                            (&__0__V59)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    __0this->__O1__4expr.tp = (struct type *)any_type;
                }
            }
        }

        if (is_ref__4typeFv(__0this->__O1__4expr.tp))
            return contents__4exprFv(__0this);

        return __0this;

    case 145:
    case 112: {
        switch (__0this->__O3__4expr.e2->base__4node) {
        case 147:
            if ((__0this->base__4node == 112) &&
                (__0this->__O3__4expr.e2->__O3__4expr.e2->base__4node == 85)) {
                const char *__5s;

                __5s = __0this->__O3__4expr.e2->__O3__4expr.e2->__O2__4expr.string;
                if ((((__5s[0]) == '_') && (__5s[1])) && ((__5s[1]) == '_')) {
                    if ((__5s[2]) && (((__5s[2]) == 'R') || ((__5s[2]) == 'V'))) {
                        error__FPCc((const char *)"address of non-lvalue");
                        break;
                    }
                }
            }
        case 71: {
            Pexpr __5ee;

            __5ee = __0this->__O3__4expr.e2;
            __5ee->__O1__4expr.tp = 0;
            __5ee->__O3__4expr.e2 = __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                                           (struct expr *)0, __5ee->__O3__4expr.e2);
            ((__0this ? (((void)(__0this ? (((void)(((void)__dl__4exprSFPvUl(
                                               (void *)__0this, (size_t)(sizeof(struct expr)))))))
                                         : (((void)0)))))
                      : (((void)0))));
            return typ__4exprFP5table(__5ee, __1tbl);
        }
        case 68: {
            Pexpr __5ee;

            __5ee = __0this->__O3__4expr.e2;
            __5ee->__O1__4expr.tp = 0;
            __5ee->__O2__4expr.e1 = __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                                           (struct expr *)0, __5ee->__O2__4expr.e1);
            __5ee->__O3__4expr.e2 = __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                                           (struct expr *)0, __5ee->__O3__4expr.e2);
            ((__0this ? (((void)(__0this ? (((void)(((void)__dl__4exprSFPvUl(
                                               (void *)__0this, (size_t)(sizeof(struct expr)))))))
                                         : (((void)0)))))
                      : (((void)0))));
            return typ__4exprFP5table(__5ee, __1tbl);
        }
        case 48:
        case 49:
            if (__0this->__O3__4expr.e2->__O2__4expr.e1)
                break;
        case 70:
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
            return address__4exprFv(__0this->__O3__4expr.e2);
        }

        {
            int __3oerror_count;

            __3oerror_count = error_count;
            if (lval__4exprFUc(__0this->__O3__4expr.e2, (unsigned char)112) == 0) {
                if (error_count > __3oerror_count) {
                    __0this->__O1__4expr.tp = (struct type *)any_type;
                    return __0this;
                }
            }

            __0this->__O1__4expr.tp =
                (struct type *)(__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __1t));

            if (__0this->__O3__4expr.e2->__O1__4expr.tp->base__4node == 110) {
                if (__0this->__O3__4expr.e2->base__4node != 85) {
                    __0this->base__4node = 191;

                    __0this->__O4__4expr.tp2 = __0this->__O1__4expr.tp;
                    __0this->__O2__4expr.e1 = __0this->__O3__4expr.e2;
                    __0this->__O3__4expr.e2 = 0;
                    return __0this;
                }
            }

            if (__1t->base__4node == 108)
                (((struct ptr *)(((struct ptr *)__0this->__O1__4expr.tp))))->memof__3ptr =
                    (((struct fct *)(((struct fct *)__1t))))->memof__3fct;

            switch (__0this->__O3__4expr.e2->base__4node) {
            case 85:
            mname: {
                Pname __5n2;
                Pname __5cn;

                __5n2 = (((struct name *)(((struct name *)__0this->__O3__4expr.e2))));
                __5cn = ((__5n2->__O4__4expr.n_table && (__5n2->__O4__4expr.n_table != gtbl))
                             ? __5n2->__O4__4expr.n_table->t_name__5table
                             : (((struct name *)0)));

                if (__5cn == 0)
                    break;

                if ((__1t->base__4node == 108) &&
                    (((struct fct *)(((struct fct *)__1t))))->f_static__3fct) {
                    (((struct ptr *)(((struct ptr *)__0this->__O1__4expr.tp))))->memof__3ptr = 0;

                    break;
                }

                switch (__1t->base__4node) {
                case 76:
                    return __0this->__O3__4expr.e2;
                case 108: {
                    Pclass __7cl;

                    struct ival *__0__X130;

                    __7cl = (((struct classdef *)(((struct classdef *)__5cn->__O1__4expr.tp))));
                    (((struct ptr *)(((struct ptr *)__0this->__O1__4expr.tp))))->memof__3ptr =
                        __7cl;

                    if ((((struct fct *)(((struct fct *)__1t))))->f_virtual__3fct) {
                        struct ival *__0__X128;

                        long long __2__X129;

                        __0this->__O2__4expr.e1 =
                            (struct expr
                                 *)((__0__X128 = 0),
                                    ((__2__X129 = (((struct fct *)(((struct fct *)__1t))))
                                                      ->f_virtual__3fct),
                                     (((__0__X128 || (__0__X128 = (struct ival *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct ival)))))
                                           ? ((__0__X128 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X128), (unsigned char)150,
                                                   (struct expr *)0, (struct expr *)0)),
                                              (__0__X128->__O2__4expr.i1 = __2__X129))
                                           : 0),
                                      __0__X128)));
                        __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                            (struct expr *)0, (unsigned char)140, zero, __0this->__O2__4expr.e1);
                        __0this->__O3__4expr.e2 = zero;
                        __0this->base__4node = 124;
                        return __0this;
                    }

                    __0this->__O2__4expr.e1 =
                        (struct expr *)((__0__X130 = 0),
                                        (((__0__X130 || (__0__X130 = (struct ival *)__nw__4exprSFUl(
                                                             (size_t)(sizeof(struct ival)))))
                                              ? ((__0__X130 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                      ((struct expr *)__0__X130),
                                                      (unsigned char)150, (struct expr *)0,
                                                      (struct expr *)0)),
                                                 (__0__X130->__O2__4expr.i1 = ((long long)-1)))
                                              : 0),
                                         __0__X130));
                    __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                        (struct expr *)0, (unsigned char)140, zero, __0this->__O2__4expr.e1);

                    if (((((struct name *)(((struct name *)__0this->__O3__4expr.e2))))
                             ->n_oper__4name == 70) &&
                        (look__5tableFPCcUc(__7cl->memtbl__8classdef,
                                            __0this->__O3__4expr.e2->__O2__4expr.string,
                                            (unsigned char)0)
                             ->__O1__4expr.tp->base__4node != 76)) {
                        Pname __8nmw;

                        register struct cast *__0__X131;

                        struct type *__2__X132;

                        __8nmw = __ct__4nameFPCc((struct name *)0, (const char *)0);
                        ((*__8nmw)) =
                            (*(((struct name *)(((struct name *)__0this->__O3__4expr.e2)))));
                        __0this->__O3__4expr.e2 =
                            (struct expr
                                 *)((__0__X131 = 0),
                                    ((__2__X132 = Pfct_type),
                                     (((__0__X131 || (__0__X131 = (struct cast *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct cast)))))
                                           ? ((__0__X131 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X131), (unsigned char)191,
                                                   ((struct expr *)__8nmw), (struct expr *)0)),
                                              (__0__X131->__O1__4expr.tp =
                                                   (__0__X131->__O4__4expr.tp2 = __2__X132)))
                                           : 0),
                                      __0__X131)));

                    } else {
                        register struct cast *__0__X133;

                        struct type *__2__X134;

                        struct expr *__2__X135;

                        __0this->__O3__4expr.e2 =
                            (struct expr
                                 *)((__0__X133 = 0),
                                    ((__2__X134 = Pfct_type),
                                     ((__2__X135 = __0this->__O3__4expr.e2),
                                      (((__0__X133 || (__0__X133 = (struct cast *)__nw__4exprSFUl(
                                                           (size_t)(sizeof(struct cast)))))
                                            ? ((__0__X133 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X133), (unsigned char)191,
                                                    __2__X135, (struct expr *)0)),
                                               (__0__X133->__O1__4expr.tp =
                                                    (__0__X133->__O4__4expr.tp2 = __2__X134)))
                                            : 0),
                                       __0__X133))));
                    }
                    __0this->base__4node = 124;
                    return __0this;
                }

                default:
                    if (__5n2->n_stclass__4name != 31) {
                        struct ival *__0__X136;

                        long long __2__X137;

                        __0this->__O2__4expr.e1 =
                            (struct expr
                                 *)((__0__X136 = 0),
                                    ((__2__X137 = (__5n2->n_offset__4name + 1)),
                                     (((__0__X136 || (__0__X136 = (struct ival *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct ival)))))
                                           ? ((__0__X136 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X136), (unsigned char)150,
                                                   (struct expr *)0, (struct expr *)0)),
                                              (__0__X136->__O2__4expr.i1 = __2__X137))
                                           : 0),
                                      __0__X136)));

                        (((struct ptr *)(((struct ptr *)__0this->__O1__4expr.tp))))->memof__3ptr =
                            (((struct classdef *)(((struct classdef *)__5cn->__O1__4expr.tp))));

                    } else
                        return __0this;
                }

                __0this->__O2__4expr.e1->__O1__4expr.tp = (struct type *)int_type;
                __0this->__O3__4expr.e2 = 0;
                __0this->__O4__4expr.tp2 = __0this->__O1__4expr.tp;
                __0this->base__4node = 191;
                return __0this;
            }
            case 45:
            case 44: {
                Pname __5m;

                __5m =
                    (((struct name *)(((struct name *)__0this->__O3__4expr.e2->__O4__4expr.mem))));
                while (__5m->base__4node == 177)
                    __5m =
                        (((struct name *)(((struct name *)(((struct expr *)(((struct expr *)__5m))))
                                               ->__O4__4expr.mem))));

                {
                    Pfct __5f;

                    __5f = (((struct fct *)(((struct fct *)__5m->__O1__4expr.tp))));

                    if ((__1t->base__4node == 108) &&
                        (((struct fct *)(((struct fct *)__1t))))->f_static__3fct) {
                        (((struct ptr *)(((struct ptr *)__0this->__O1__4expr.tp))))->memof__3ptr =
                            0;

                        break;
                    }

                    {
                        bit __5all_stat;

                        __5all_stat = 1;
                        if (__5f->base__4node == 76) {
                            Plist __6gl;

                            __6gl = (((struct gen *)(((struct gen *)__5m->__O1__4expr.tp))))
                                        ->fct_list__3gen;
                            for (; __6gl; __6gl = __6gl->l__9name_list) {
                                if ((((struct fct *)((
                                         (struct fct *)__6gl->f__9name_list->__O1__4expr.tp))))
                                        ->f_static__3fct == 0) {
                                    __5all_stat = 0;

                                    break;
                                }
                            }
                        }

                        if ((__5f->base__4node == 108) || (__5f->base__4node == 76)) {
                            Pexpr __6q;

                            __6q = (((struct name *)(((struct name *)__0this->__O3__4expr.e2))))
                                       ->__O3__4expr.n_initializer;

                            if ((__6q && (bound == 0)) &&
                                (__0this->__O3__4expr.e2->__O2__4expr.e1 ==
                                 (((struct expr *)cc->c_this__11dcl_context)))) {
                                if (__0this->__O3__4expr.e2 &&
                                    (__0this->__O3__4expr.e2->permanent__4node == 0))
                                    del__4exprFv(__0this->__O3__4expr.e2);
                                __0this->__O3__4expr.e2 = (struct expr *)__5m;
                                goto mname;
                            }

                            bound = 1;
                            if (((__5f->base__4node == 76) && (__5all_stat == 0)) ||
                                ((__5f->base__4node == 108) && (!__5f->f_static__3fct))) {
                                const void *__2__X138;

                                {
                                    struct ea __0__V60;

                                    struct ea __0__V61;

                                    struct ea __0__V62;

                                    error__FPCcRC2eaN32(
                                        (const char *)"address of boundF (try using ``%s::*'' "
                                                      "forPT and ``&%s::%s'' for address)",
                                        (const struct ea *)((__2__X138 =
                                                                 (const void *)__5m->__O4__4expr
                                                                     .n_table->t_name__5table
                                                                     ->__O2__4expr.string),
                                                            (((&__0__V60)->__O1__2ea.p = __2__X138),
                                                             (&__0__V60))),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V61, (const void *)__5m->__O4__4expr.n_table
                                                           ->t_name__5table->__O2__4expr.string),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V62, (const void *)__5m->__O2__4expr.string),
                                        (const struct ea *)ea0);
                                }
                            }

                            if (__6q || (__5f->f_virtual__3fct == 0)) {
                                if (__0this->__O3__4expr.e2 &&
                                    (__0this->__O3__4expr.e2->permanent__4node == 0))
                                    del__4exprFv(__0this->__O3__4expr.e2);
                                __0this->__O3__4expr.e2 = (struct expr *)__5m;
                            }
                        }
                        break;
                    }
                }
            }
            case 173:
                error__FPCc((const char *)"& .* E");
            }

            return __0this;
        }
    }

    case 107:
        (kind__4typeFUcN21(__1t, ((unsigned char)107), (unsigned char)'N', (unsigned char)1));
        __0this->__O1__4expr.tp = __1t;
        return __0this;

    case 172:
        __0this->__O1__4expr.tp = __1t;
        if (((kind__4typeFUcN21(__1t, ((unsigned char)172), (unsigned char)'P',
                                (unsigned char)1)) == 'P') ||
            (ansi_opt == 0)) {
            __0this->base__4node = 54;
            __0this->__O2__4expr.e1 = zero;
        }
        return __0this;

    case 46:
        __0this->__O3__4expr.e2 =
            check_cond__FP4exprUcP5table(__0this->__O3__4expr.e2, (unsigned char)46, __1tbl);
        __0this->__O1__4expr.tp = (struct type *)int_type;
        return __0this;

    case 47:
        (kind__4typeFUcN21(__1t, ((unsigned char)47), (unsigned char)'I', (unsigned char)1));
        __0this->__O1__4expr.tp = __1t;
        return __0this;

    case 48:
    case 49: {
        Pexpr __3e;

        __3e = (__0this->__O2__4expr.e1 ? __0this->__O2__4expr.e1 : __0this->__O3__4expr.e2);

        lval__4exprFUc(__3e, __1b);

        switch (__3e->base__4node) {
        case 68:
            __3e->__O1__4expr.tp = 0;
            __3e->__O2__4expr.e1 =
                (__0this->__O2__4expr.e1
                     ? __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                              __3e->__O2__4expr.e1, (struct expr *)0)
                     : __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                              (struct expr *)0, __3e->__O2__4expr.e1));
            __3e->__O3__4expr.e2 =
                (__0this->__O2__4expr.e1
                     ? __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                              __3e->__O3__4expr.e2, (struct expr *)0)
                     : __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                              (struct expr *)0, __3e->__O3__4expr.e2));
            ((__0this ? (((void)(__0this ? (((void)(((void)__dl__4exprSFPvUl(
                                               (void *)__0this, (size_t)(sizeof(struct expr)))))))
                                         : (((void)0)))))
                      : (((void)0))));
            return typ__4exprFP5table(__3e, __1tbl);
        case 71:
        case 147:
            __3e->__O1__4expr.tp = 0;
            __3e->__O3__4expr.e2 =
                (__0this->__O2__4expr.e1
                     ? __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                              __3e->__O3__4expr.e2, (struct expr *)0)
                     : __ct__4exprFUcP4exprT2((struct expr *)0, __0this->base__4node,
                                              (struct expr *)0, __3e->__O3__4expr.e2));
            ((__0this ? (((void)(__0this ? (((void)(((void)__dl__4exprSFPvUl(
                                               (void *)__0this, (size_t)(sizeof(struct expr)))))))
                                         : (((void)0)))))
                      : (((void)0))));
            return typ__4exprFP5table(__3e, __1tbl);
        case 48:
        case 49:
            if (__3e->__O2__4expr.e1)
                break;
            nin++;
            if (not_simple__4exprFi(__3e->__O3__4expr.e2, 0)) {
                struct ea __0__V63;

                struct ea __0__V64;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"overly complex %k of %k",
                    (const struct ea *)(((((&__0__V63)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                        (&__0__V63)),
                    (const struct ea *)__ct__2eaFUl(&__0__V64, (unsigned long)__3e->base__4node),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            nin--;
            __3e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147, __3e,
                                          typ__4exprFP5table(__3e->__O3__4expr.e2, __1tbl));

            if (__0this->__O2__4expr.e1)
                __0this->__O2__4expr.e1 = __3e;
            else
                __0this->__O3__4expr.e2 = __3e;

            return typ__4exprFP5table(__0this, __1tbl);
        case 70:
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
            nin++;
            if (not_simple__4exprFi(__3e->__O2__4expr.e1, 0)) {
                struct ea __0__V65;

                struct ea __0__V66;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"overly complex %k of %k",
                    (const struct ea *)(((((&__0__V65)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                        (&__0__V65)),
                    (const struct ea *)__ct__2eaFUl(&__0__V66, (unsigned long)__3e->base__4node),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            nin--;
            __3e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147, __3e,
                                          typ__4exprFP5table(__3e->__O2__4expr.e1, __1tbl));

            if (__0this->__O2__4expr.e1)
                __0this->__O2__4expr.e1 = __3e;
            else
                __0this->__O3__4expr.e2 = __3e;
            return typ__4exprFP5table(__0this, __1tbl);
        }
    }

        __1r1 = (kind__4typeFUcN21(__1t, __1b, (unsigned char)'P', (unsigned char)1));
        if (((__1r1 == 'P') && (check__4typeFP4typeUcT2(__1t, Pvoid_type, (unsigned char)254,
                                                        (unsigned char)0) == 0)) &&
            (ptr_is_template_formal__FP3ptr(((struct ptr *)(((struct ptr *)__1t)))) == 0)) {
            struct ea __0__V67;

            error__FPCcRC2eaN32(
                (const char *)"%k of void*",
                (const struct ea *)(((((&__0__V67)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                    (&__0__V67)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        __0this->__O1__4expr.tp = __1t;
        return __0this;
    }

    if ((__0this->__O2__4expr.e1 == dummy) || (__0this->__O2__4expr.e1 == 0)) {
        struct ea __0__V68;

        error__FPCcRC2eaN32(
            (const char *)"operand missing for%k",
            (const struct ea *)(((((&__0__V68)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                (&__0__V68)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if ((__0this->__O3__4expr.e2 == dummy) || (__0this->__O3__4expr.e2 == 0)) {
        struct ea __0__V69;

        error__FPCcRC2eaN32(
            (const char *)"initializer missing for%k",
            (const struct ea *)(((((&__0__V69)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                (&__0__V69)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    switch (__1b) {
    case 50:
    case 51:
        __1r1 = (kind__4typeFUcN21(__1t1, __1b, (unsigned char)'N', (unsigned char)1));
        __1r2 = (kind__4typeFUcN21(__1t2, __1b, (unsigned char)'N', (unsigned char)1));
        __1t = np_promote__FUcN21P4typeT4N21(__1b, __1r1, __1r2, __1t1, __1t2, (unsigned char)1,
                                             (unsigned char)1);

        break;

    case 54:
        __1r2 =
            (kind__4typeFUcN21(__1t2, ((unsigned char)54), (unsigned char)'P', (unsigned char)1));
        __1r1 =
            (kind__4typeFUcN21(__1t1, ((unsigned char)54), (unsigned char)'P', (unsigned char)1));
        __1t = np_promote__FUcN21P4typeT4N21((unsigned char)54, __1r1, __1r2, __1t1, __1t2,
                                             (unsigned char)1, (unsigned char)1);
        goto void_check;

    case 55:
        __1r2 =
            (kind__4typeFUcN21(__1t2, ((unsigned char)55), (unsigned char)'P', (unsigned char)1));
        __1r1 =
            (kind__4typeFUcN21(__1t1, ((unsigned char)55), (unsigned char)'P', (unsigned char)1));
        if (((__1r2 == 'P') && (__1r1 != 'P')) && (__1r1 != 'A'))
            error__FPCc((const char *)"nonP - P");
        __1t = np_promote__FUcN21P4typeT4N21((unsigned char)55, __1r1, __1r2, __1t1, __1t2,
                                             (unsigned char)1, (unsigned char)1);
    void_check:
        if ((((__1r1 == 'P') && (check__4typeFP4typeUcT2(__1t1, Pvoid_type, (unsigned char)254,
                                                         (unsigned char)0) == 0)) &&
             (ptr_is_template_formal__FP3ptr(((struct ptr *)(((struct ptr *)__1t1)))) == 0)) ||
            (((__1r2 == 'P') && (check__4typeFP4typeUcT2(__1t2, Pvoid_type, (unsigned char)254,
                                                         (unsigned char)0) == 0)) &&
             (ptr_is_template_formal__FP3ptr(((struct ptr *)(((struct ptr *)__1t2)))) == 0))) {
            struct ea __0__V70;

            error__FPCcRC2eaN32(
                (const char *)"%k of void*",
                (const struct ea *)(((((&__0__V70)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                    (&__0__V70)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        __0this->__O1__4expr.tp = __1t;
        break;

    case 56:
    case 57:
    case 52:
    case 65:
    case 64:
        switch (__0this->__O2__4expr.e1->base__4node) {
            unsigned long __2__X139;

        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63: {
            struct ea __0__V71;

            struct ea __0__V72;

            error__FiPCcRC2eaN33(
                (int)'w', (const char *)"%kE as operand for%k",
                (const struct ea *)((__2__X139 = __0this->__O2__4expr.e1->base__4node),
                                    (((((&__0__V71)->__O1__2ea.i = __2__X139), 0)), (&__0__V71))),
                (const struct ea *)(((((&__0__V72)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                    (&__0__V72)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        }
        switch (__0this->__O3__4expr.e2->base__4node) {
            unsigned long __2__X140;

        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63: {
            struct ea __0__V73;

            struct ea __0__V74;

            error__FiPCcRC2eaN33(
                (int)'w', (const char *)"%kE as operand for%k",
                (const struct ea *)((__2__X140 = __0this->__O3__4expr.e2->base__4node),
                                    (((((&__0__V73)->__O1__2ea.i = __2__X140), 0)), (&__0__V73))),
                (const struct ea *)(((((&__0__V74)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                    (&__0__V74)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        }
    case 53:
        __1r1 = (kind__4typeFUcN21(__1t1, __1b, (unsigned char)'I', (unsigned char)1));
        __1r2 = (kind__4typeFUcN21(__1t2, __1b, (unsigned char)'I', (unsigned char)1));
        __1t = np_promote__FUcN21P4typeT4N21(__1b, __1r1, __1r2, __1t1, __1t2, (unsigned char)1,
                                             (unsigned char)1);

        break;

    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
        __1r1 = (kind__4typeFUcN21(__1t1, __1b, (unsigned char)'P', (unsigned char)1));
        __1r2 = (kind__4typeFUcN21(__1t2, __1b, (unsigned char)'P', (unsigned char)1));
        if ((__1r1 == 'P') && (__1r2 == 'I')) {
            Neval = 0;
            {
                long long __3i;

                __3i = eval__4exprFv(__0this->__O3__4expr.e2);
                if ((Neval == 0) && (__3i == 0)) {
                    if (__0this->__O3__4expr.e2 && (__0this->__O3__4expr.e2->permanent__4node == 0))
                        del__4exprFv(__0this->__O3__4expr.e2);
                    __0this->__O3__4expr.e2 = zero;
                    __1r2 = 'Z';
                }
            }
        } else if ((__1r2 == 'P') && (__1r1 == 'I')) {
            Neval = 0;
            {
                long long __3i;

                __3i = eval__4exprFv(__0this->__O2__4expr.e1);
                if ((Neval == 0) && (__3i == 0)) {
                    if (__0this->__O2__4expr.e1 && (__0this->__O2__4expr.e1->permanent__4node == 0))
                        del__4exprFv(__0this->__O2__4expr.e1);
                    __0this->__O2__4expr.e1 = zero;
                    __1r1 = 'Z';
                }
            }
        }

        if ((__1b != 62) && (__1b != 63)) {
            if ((__1r1 == 'P') && (__1r2 == 'Z')) {
                struct ea __0__V75;

                error__FPCcRC2eaN32(
                    (const char *)"P%k 0",
                    (const struct ea *)(((((&__0__V75)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                        (&__0__V75)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if ((__1r2 == 'P') && (__1r1 == 'Z')) {
                struct ea __0__V76;

                error__FPCcRC2eaN32(
                    (const char *)"P%k 0",
                    (const struct ea *)(((((&__0__V76)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                        (&__0__V76)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }

        if (__1r1 == 108) {
            __0this->__O2__4expr.e1 =
                ptof__FP3fctP4exprP5table((struct fct *)0, __0this->__O2__4expr.e1, __1tbl);
            __1t1 = __0this->__O2__4expr.e1->__O1__4expr.tp;
            __1r1 = (kind__4typeFUcN21(__1t1, __1b, (unsigned char)'P', (unsigned char)1));
        }
        if (__1r2 == 108) {
            __0this->__O3__4expr.e2 =
                ptof__FP3fctP4exprP5table((struct fct *)0, __0this->__O3__4expr.e2, __1tbl);
            __1t2 = __0this->__O3__4expr.e2->__O1__4expr.tp;
            __1r2 = (kind__4typeFUcN21(__1t2, __1b, (unsigned char)'P', (unsigned char)1));
        }

        ((void)np_promote__FUcN21P4typeT4N21(__1b, __1r1, __1r2, __1t1, __1t2, (unsigned char)0,
                                             (unsigned char)1));

        if (__1r1 == 'P') {
            Pptr __3p1;
            Pptr __3p2;
            Pname __3cn;
            Pname __3cn2;

            __3p1 = is_ptr__4typeFv(__1t1);
            __3p2 = is_ptr__4typeFv(__1t2);
            __3cn = (__3p1 ? is_cl_obj__4typeFv(__3p1->typ__5pvtyp) : (((struct name *)0)));
            __3cn2 = (__3p2 ? is_cl_obj__4typeFv(__3p2->typ__5pvtyp) : (((struct name *)0)));

            if (__3cn && __3cn2) {
                Pclass __4cl;
                Pclass __4cl2;

                __4cl = (((struct classdef *)(((struct classdef *)__3cn->__O1__4expr.tp))));
                __4cl2 = (((struct classdef *)(((struct classdef *)__3cn2->__O1__4expr.tp))));

                if (has_base__8classdefFP8classdefiT2(__4cl, __4cl2, 0, 0)) {
                    register struct cast *__0__X141;

                    struct expr *__2__X142;

                    __0this->__O2__4expr.e1 = cast_cptr__FP8classdefP4exprP5tablei(
                        __4cl2, __0this->__O2__4expr.e1, __1tbl,
                        (__0this->base__4node == 113) ? 1 : 0);
                    __0this->__O2__4expr.e1 =
                        (struct expr
                             *)((__0__X141 = 0),
                                ((__2__X142 = __0this->__O2__4expr.e1),
                                 (((__0__X141 || (__0__X141 = (struct cast *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct cast)))))
                                       ? ((__0__X141 = (struct cast *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X141), (unsigned char)191,
                                               __2__X142, (struct expr *)0)),
                                          (__0__X141->__O1__4expr.tp =
                                               (__0__X141->__O4__4expr.tp2 =
                                                    ((struct type *)__3p2))))
                                       : 0),
                                  __0__X141)));
                } else if (has_base__8classdefFP8classdefiT2(__4cl2, __4cl, 0, 0)) {
                    register struct cast *__0__X143;

                    struct expr *__2__X144;

                    __0this->__O3__4expr.e2 =
                        cast_cptr__FP8classdefP4exprP5tablei(__4cl, __0this->__O3__4expr.e2, __1tbl,
                                                             (__0this->base__4node == 113) ? 1 : 0);
                    __0this->__O3__4expr.e2 =
                        (struct expr
                             *)((__0__X143 = 0),
                                ((__2__X144 = __0this->__O3__4expr.e2),
                                 (((__0__X143 || (__0__X143 = (struct cast *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct cast)))))
                                       ? ((__0__X143 = (struct cast *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X143), (unsigned char)191,
                                               __2__X144, (struct expr *)0)),
                                          (__0__X143->__O1__4expr.tp =
                                               (__0__X143->__O4__4expr.tp2 =
                                                    ((struct type *)__3p1))))
                                       : 0),
                                  __0__X143)));
                }
            }
        }

        if (((((__1r1 == 'P') && memptr__4typeFv(__1t1)) ||
              ((__1t1->base__4node == 108) &&
               (((struct fct *)(((struct fct *)__1t1))))->memof__3fct)) ||
             ((__1r2 == 'P') && memptr__4typeFv(__1t2))) ||
            ((__1t2->base__4node == 108) &&
             (((struct fct *)(((struct fct *)__1t2))))->memof__3fct)) {
            if (__1r1 == 'Z') {

                __0this->__O2__4expr.e1 = zero;
                if (__0this->__O3__4expr.e2->base__4node == 124)
                    __0this->__O3__4expr.e2 =
                        __0this->__O3__4expr.e2->__O2__4expr.e1->__O3__4expr.e2;
                else
                    __0this->__O3__4expr.e2 = make_dot__FP4exprP5tablePCc(
                        __0this->__O3__4expr.e2, __1tbl, (const char *)"i");
            } else if (__1r2 == 'Z') {
                __0this->__O3__4expr.e2 = zero;
                if (__0this->__O2__4expr.e1->base__4node == 124)
                    __0this->__O2__4expr.e1 =
                        __0this->__O2__4expr.e1->__O2__4expr.e1->__O3__4expr.e2;
                else
                    __0this->__O2__4expr.e1 = make_dot__FP4exprP5tablePCc(
                        __0this->__O2__4expr.e1, __1tbl, (const char *)"i");
            } else if (((__1r2 == 'P') && (!memptr__4typeFv(__1t2))) ||
                       ((__1r1 == 'P') && (!memptr__4typeFv(__1t1)))) {

                ;
            } else {
                Pexpr __4i1;
                __4i1 = __0this->__O2__4expr.e1;
                while ((__4i1->base__4node == 191) || (__4i1->base__4node == 113))
                    __4i1 = __4i1->__O2__4expr.e1;
                if (__4i1->base__4node == 124) {
                    __0this->__O2__4expr.e1 = __4i1;
                    __4i1 = make_dot__FP4exprP5tablePCc(__4i1, __1tbl, (const char *)"i");
                } else if (__4i1->base__4node == 86) {
                    __4i1 = zero;
                    __0this->__O2__4expr.e1 = __4i1;
                } else {
                    __4i1 = make_dot__FP4exprP5tablePCc(__4i1, __1tbl, (const char *)"i");
                }

                {
                    Pexpr __4i2;
                    __4i2 = __0this->__O3__4expr.e2;
                    while ((__4i2->base__4node == 191) || (__4i2->base__4node == 113))
                        __4i2 = __4i2->__O2__4expr.e1;
                    if (__4i2->base__4node == 124) {
                        __0this->__O3__4expr.e2 = __4i2;
                        __4i2 = make_dot__FP4exprP5tablePCc(__4i2, __1tbl, (const char *)"i");
                    } else if (__4i2->base__4node == 86) {
                        __4i2 = zero;
                        __0this->__O3__4expr.e2 = __4i2;
                    } else {
                        __4i2 = make_dot__FP4exprP5tablePCc(__4i2, __1tbl, (const char *)"i");
                    }

                    {
                        Pexpr __4f1;
                        if (__0this->__O2__4expr.e1->base__4node == 124) {
                            __4f1 = __0this->__O2__4expr.e1->__O3__4expr.e2;
                        } else if (__0this->__O2__4expr.e1->base__4node == 86) {
                            __4f1 = zero;
                        } else {
                            __4f1 = make_dot__FP4exprP5tablePCc(__0this->__O2__4expr.e1, __1tbl,
                                                                (const char *)"f");
                        }

                        {
                            Pexpr __4f2;
                            if (__0this->__O3__4expr.e2->base__4node == 124) {
                                __4f2 = __0this->__O3__4expr.e2->__O3__4expr.e2;
                            } else if (__0this->__O3__4expr.e2->base__4node == 86) {
                                __4f2 = zero;
                            } else {
                                __4f2 = make_dot__FP4exprP5tablePCc(__0this->__O3__4expr.e2, __1tbl,
                                                                    (const char *)"f");
                                __4f2->__O1__4expr.tp = __4f1->__O1__4expr.tp;
                            }

                            if ((__1b != 62) && (__1b != 63)) {
                                register struct cast *__0__X145;

                                struct type *__2__X146;

                                register struct cast *__0__X147;

                                struct type *__2__X148;

                                __4f1 =
                                    (struct expr *)((__0__X145 = 0),
                                                    ((__2__X146 = Pvoid_type),
                                                     (((__0__X145 ||
                                                        (__0__X145 = (struct cast *)__nw__4exprSFUl(
                                                             (unsigned long)(sizeof(struct cast)))))
                                                           ? ((__0__X145 = (struct cast *)
                                                                   __ct__4exprFUcP4exprT2(
                                                                       ((struct expr *)__0__X145),
                                                                       (unsigned char)191, __4f1,
                                                                       (struct expr *)0)),
                                                              (__0__X145->__O1__4expr.tp =
                                                                   (__0__X145->__O4__4expr.tp2 =
                                                                        __2__X146)))
                                                           : 0),
                                                      __0__X145)));
                                __4f2 =
                                    (struct expr *)((__0__X147 = 0),
                                                    ((__2__X148 = Pvoid_type),
                                                     (((__0__X147 ||
                                                        (__0__X147 = (struct cast *)__nw__4exprSFUl(
                                                             (unsigned long)(sizeof(struct cast)))))
                                                           ? ((__0__X147 = (struct cast *)
                                                                   __ct__4exprFUcP4exprT2(
                                                                       ((struct expr *)__0__X147),
                                                                       (unsigned char)191, __4f2,
                                                                       (struct expr *)0)),
                                                              (__0__X147->__O1__4expr.tp =
                                                                   (__0__X147->__O4__4expr.tp2 =
                                                                        __2__X148)))
                                                           : 0),
                                                      __0__X147)));
                            }
                            {
                                Pexpr __4ei;
                                Pexpr __4fi;

                                __4ei = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                               __0this->base__4node, __4i1, __4i2);
                                __4fi = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                               __0this->base__4node, __4f1, __4f2);

                                __0this->base__4node = ((__1b == 63) ? 67 : 66);
                                __0this->__O2__4expr.e1 = __4ei;
                                __0this->__O3__4expr.e2 = __4fi;
                            }
                        }
                    }
                }
            }
        } else if ((__1b != 62) && (__1b != 63)) {
            bit __3doit;

            __3doit = 0;
            if (__1r1 == 'P') {
                Ptype __4tt1;
                Ptype __4tt2;

                __4tt1 = __1t1;

                while (__4tt2 = (struct type *)is_ptr_or_ref__4typeFv(__4tt1))
                    __4tt1 = (((struct ptr *)(((struct ptr *)__4tt2))))->typ__5pvtyp;
                if (__4tt1->base__4node == 108)
                    __3doit = 1;
            }
            if ((!__3doit) && (__1r2 == 'P')) {
                Ptype __4tt1;
                Ptype __4tt2;

                __4tt1 = __1t2;

                while (__4tt2 = (struct type *)is_ptr_or_ref__4typeFv(__4tt1))
                    __4tt1 = (((struct ptr *)(((struct ptr *)__4tt2))))->typ__5pvtyp;
                if (__4tt1->base__4node == 108)
                    __3doit = 1;
            }
            if (__3doit) {
                register struct cast *__0__X149;

                struct type *__2__X150;

                struct expr *__2__X151;

                register struct cast *__0__X152;

                struct type *__2__X153;

                struct expr *__2__X154;

                __0this->__O2__4expr.e1 =
                    (struct expr *)((__0__X149 = 0),
                                    ((__2__X150 = Pvoid_type),
                                     ((__2__X151 = __0this->__O2__4expr.e1),
                                      (((__0__X149 || (__0__X149 = (struct cast *)__nw__4exprSFUl(
                                                           (size_t)(sizeof(struct cast)))))
                                            ? ((__0__X149 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X149), (unsigned char)191,
                                                    __2__X151, (struct expr *)0)),
                                               (__0__X149->__O1__4expr.tp =
                                                    (__0__X149->__O4__4expr.tp2 = __2__X150)))
                                            : 0),
                                       __0__X149))));
                __0this->__O3__4expr.e2 =
                    (struct expr *)((__0__X152 = 0),
                                    ((__2__X153 = Pvoid_type),
                                     ((__2__X154 = __0this->__O3__4expr.e2),
                                      (((__0__X152 || (__0__X152 = (struct cast *)__nw__4exprSFUl(
                                                           (size_t)(sizeof(struct cast)))))
                                            ? ((__0__X152 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X152), (unsigned char)191,
                                                    __2__X154, (struct expr *)0)),
                                               (__0__X152->__O1__4expr.tp =
                                                    (__0__X152->__O4__4expr.tp2 = __2__X153)))
                                            : 0),
                                       __0__X152))));
            }
        }
        __1t = (struct type *)int_type;
        break;

    case 66:
    case 67:
        __0this->__O2__4expr.e1 =
            check_cond__FP4exprUcP5table(__0this->__O2__4expr.e1, __1b, __1tbl);
        __0this->__O3__4expr.e2 =
            check_cond__FP4exprUcP5table(__0this->__O3__4expr.e2, __1b, __1tbl);

        if (Ntmp && (__1b != 68)) {
            Ntmp_dtor =
                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __0this, Ntmp_dtor);
        }

        __1t = (struct type *)int_type;
        break;

    case 68: {
        Pname __3c1;

        Pname __3c2;
        __0this->__O4__4expr.cond =
            check_cond__FP4exprUcP5table(__0this->__O4__4expr.cond, __1b, __1tbl);

        {
            bit __3MPTR;

            __3MPTR = 0;

            suppress_error++;
            __1r1 = (kind__4typeFUcN21(__1t1, __1b, (unsigned char)'P', (unsigned char)1));
            __1r2 = (kind__4typeFUcN21(__1t2, __1b, (unsigned char)'P', (unsigned char)1));
            suppress_error--;
            if ((((__1r1 == 'P') && memptr__4typeFv(__1t1)) ||
                 (((__1r1 == 108) && (((struct fct *)(((struct fct *)__1t1))))->memof__3fct) &&
                  ((((struct fct *)(((struct fct *)__1t1))))->f_static__3fct == 0))) &&
                (((__1r2 == 'P') && memptr__4typeFv(__1t2)) ||
                 (((__1r2 == 108) && (((struct fct *)(((struct fct *)__1t2))))->memof__3fct) &&
                  ((((struct fct *)(((struct fct *)__1t2))))->f_static__3fct == 0)))) {
                ++__3MPTR;

                if (__1r1 == 108) {
                    __0this->__O2__4expr.e1 =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145,
                                               (struct expr *)0, __0this->__O2__4expr.e1);
                    typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
                    __1t1 = __0this->__O2__4expr.e1->__O1__4expr.tp;
                    __1r1 = (kind__4typeFUcN21(__1t1, __1b, (unsigned char)'P', (unsigned char)1));
                }
                if (__1r2 == 108) {
                    __0this->__O3__4expr.e2 =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145,
                                               (struct expr *)0, __0this->__O3__4expr.e2);
                    typ__4exprFP5table(__0this->__O3__4expr.e2, __1tbl);
                    __1t2 = __0this->__O3__4expr.e2->__O1__4expr.tp;
                    __1r2 = (kind__4typeFUcN21(__1t2, __1b, (unsigned char)'P', (unsigned char)1));
                }

                {
                    Pexpr __4tt;

                    __4tt = __0this->__O2__4expr.e1;
                    while ((__4tt->base__4node == 113) || (__4tt->base__4node == 191))
                        __4tt = __4tt->__O2__4expr.e1;
                    if (__4tt->base__4node == 124)
                        __0this->__O2__4expr.e1 = __4tt;

                    __4tt = __0this->__O3__4expr.e2;
                    while ((__4tt->base__4node == 113) || (__4tt->base__4node == 191))
                        __4tt = __4tt->__O2__4expr.e1;
                    if (__4tt->base__4node == 124)
                        __0this->__O3__4expr.e2 = __4tt;

                    if ((__0this->__O2__4expr.e1->base__4node == 124) ||
                        (__0this->__O3__4expr.e2->base__4node == 124)) {
                        Pname __5temp;

                        __5temp = make_tmp__FcP4typeP5table('A', (struct type *)mptr_type, __1tbl);

                        if (__0this->__O2__4expr.e1->base__4node == 124) {
                            __0this->__O2__4expr.e1 = mptr_assign__FP4exprT1(
                                (struct expr *)__5temp, __0this->__O2__4expr.e1);
                            __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                                (struct expr *)0, (unsigned char)147, __0this->__O2__4expr.e1,
                                (struct expr *)__5temp);
                            __0this->__O2__4expr.e1->__O1__4expr.tp = __5temp->__O1__4expr.tp;
                        }

                        if (__0this->__O3__4expr.e2->base__4node == 124) {
                            __0this->__O3__4expr.e2 = mptr_assign__FP4exprT1(
                                (struct expr *)__5temp, __0this->__O3__4expr.e2);
                            __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                                (struct expr *)0, (unsigned char)147, __0this->__O3__4expr.e2,
                                (struct expr *)__5temp);
                            __0this->__O3__4expr.e2->__O1__4expr.tp = __5temp->__O1__4expr.tp;
                        }
                    }
                }
            }

            {
                bit __3redo1;
                bit __3redo2;

                __3redo1 = 0;
                __3redo2 = 0;
                __3c1 = is_cl_obj__4typeFv(__1t1);
                {
                    Pname __3eo1;

                    __3eo1 = eobj;
                    __3c2 = is_cl_obj__4typeFv(__1t2);
                    {
                        Pname __3eo2;

                        __3eo2 = eobj;

                        if (((__1t1 == __1t2) || ((__3c1 && __3c2) && (__3c1->__O1__4expr.tp ==
                                                                       __3c2->__O1__4expr.tp))) ||
                            ((__3eo1 && __3eo2) &&
                             (__3eo1->__O1__4expr.tp == __3eo2->__O1__4expr.tp)))
                            __1t = __1t1;
                        else {
                            if (__3c1 && __3c2) {
                                Ptype __5tt;
                                Pclass __5cl1;
                                Pclass __5cl2;

                                struct classdef *__1__X155;

                                struct classdef *__1__X156;

                                __5cl1 = (((struct classdef *)((
                                    (struct classdef *)__3c1->__O1__4expr.tp))));
                                __5cl2 = (((struct classdef *)((
                                    (struct classdef *)__3c2->__O1__4expr.tp))));
                                if (((__1__X155 = __5cl1),
                                     ((__1__X156 = __5cl2),
                                      (((__1__X155 == __1__X156)
                                            ? 1
                                            : ((__1__X155 && __1__X156)
                                                   ? (((int)same_class__8classdefFP8classdefi(
                                                         __1__X155, __1__X156, 0)))
                                                   : 0))))) ||
                                    has_base__8classdefFP8classdefiT2(__5cl2, __5cl1, 0, 0)) {
                                    __1t = __1t1;
                                    __3redo2 = 1;
                                    goto caca;
                                } else if (has_base__8classdefFP8classdefiT2(__5cl1, __5cl2, 0,
                                                                             0)) {
                                    __1t = __1t2;
                                    __3redo1 = 1;
                                    goto caca;
                                } else if (__5tt = common_base__FP8classdefT1(__5cl1, __5cl2)) {
                                    __3redo1 = (__3redo2 = 1);
                                    __1t = __5tt;
                                    goto caca;
                                }
                            }

                            __1r1 = (kind__4typeFUcN21(__1t1, __1b, (unsigned char)'P',
                                                       (unsigned char)1));
                            __1r2 = (kind__4typeFUcN21(__1t2, __1b, (unsigned char)'P',
                                                       (unsigned char)1));

                            if ((__1r1 == 'P') && (__1r2 == 'P')) {
                                Pptr __5p1;
                                Pptr __5p2;
                                Ptype __5tt;

                                __5p1 = is_ptr__4typeFv(__1t1);
                                __5p2 = is_ptr__4typeFv(__1t2);

                                if ((__3c1 = is_cl_obj__4typeFv(__5p1->typ__5pvtyp)) &&
                                    (__3c2 = is_cl_obj__4typeFv(__5p2->typ__5pvtyp))) {
                                    Pclass __6cl1;
                                    Pclass __6cl2;

                                    struct classdef *__1__X157;

                                    struct classdef *__1__X158;

                                    __6cl1 = (((struct classdef *)((
                                        (struct classdef *)__3c1->__O1__4expr.tp))));
                                    __6cl2 = (((struct classdef *)((
                                        (struct classdef *)__3c2->__O1__4expr.tp))));
                                    if (((__1__X157 = __6cl1),
                                         ((__1__X158 = __6cl2),
                                          (((__1__X157 == __1__X158)
                                                ? 1
                                                : ((__1__X157 && __1__X158)
                                                       ? (((int)same_class__8classdefFP8classdefi(
                                                             __1__X157, __1__X158, 0)))
                                                       : 0))))) ||
                                        has_base__8classdefFP8classdefiT2(__6cl2, __6cl1, 0, 0)) {
                                        __1t = __1t1;
                                        goto caca;
                                    } else if (has_base__8classdefFP8classdefiT2(__6cl1, __6cl2, 0,
                                                                                 0)) {
                                        __1t = __1t2;
                                        goto caca;
                                    } else if (__5tt = common_base__FP8classdefT1(__6cl1, __6cl2)) {
                                        __1t = (struct type *)(__ct__3ptrFUcP4type(
                                            (struct ptr *)0, (unsigned char)125, __5tt));
                                        goto caca;
                                    }
                                }
                            }

                            if ((__1r1 == 108) && (__1r2 == 108)) {
                                if (check__4typeFP4typeUcT2(__1t1, __1t2, (unsigned char)70,
                                                            (unsigned char)0)) {
                                    struct ea __0__V77;

                                    struct ea __0__V78;

                                    error__FPCcRC2eaN32(
                                        (const char *)"badTs in ?:E: %t and %t",
                                        (const struct ea *)(((&__0__V77)->__O1__2ea.p =
                                                                 ((const void *)__1t1)),
                                                            (&__0__V77)),
                                        (const struct ea *)(((&__0__V78)->__O1__2ea.p =
                                                                 ((const void *)__1t2)),
                                                            (&__0__V78)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                }
                                __1t = __1t1;
                            } else
                                __1t = np_promote__FUcN21P4typeT4N21(__1b, __1r1, __1r2, __1t1,
                                                                     __1t2, (unsigned char)1,
                                                                     (unsigned char)1);
                        caca: {
                            Pptr __4pt;
                            bit __4t_ptr;
                            Pname __4cn;

                            __4pt = is_ptr__4typeFv(__1t);
                            __4t_ptr = (__4pt && (__4pt->base__4node == 125));
                            __4cn = ((!__4t_ptr) ? (((struct name *)0))
                                                 : is_cl_obj__4typeFv(__4pt->typ__5pvtyp));

                            if ((__1t != __1t1) &&
                                check__4typeFP4typeUcT2(__1t, __1t1, (unsigned char)0,
                                                        (unsigned char)0)) {
                                __1t->permanent__4node = 1;
                                if (__3redo1) {
                                    register struct cast *__0__X159;

                                    struct type *__2__X160;

                                    struct expr *__2__X161;

                                    __0this->__O2__4expr.e1 =
                                        address__4exprFv(__0this->__O2__4expr.e1);
                                    __0this->__O2__4expr.e1 =
                                        (struct expr
                                             *)((__0__X159 = 0),
                                                ((__2__X160 = (struct type *)(__ct__3ptrFUcP4type(
                                                      (struct ptr *)0, (unsigned char)125, __1t))),
                                                 ((__2__X161 = __0this->__O2__4expr.e1),
                                                  (((__0__X159 ||
                                                     (__0__X159 = (struct cast *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct cast)))))
                                                        ? ((__0__X159 = (struct cast *)
                                                                __ct__4exprFUcP4exprT2(
                                                                    ((struct expr *)__0__X159),
                                                                    (unsigned char)191, __2__X161,
                                                                    (struct expr *)0)),
                                                           (__0__X159->__O1__4expr.tp =
                                                                (__0__X159->__O4__4expr.tp2 =
                                                                     __2__X160)))
                                                        : 0),
                                                   __0__X159))));

                                    __0this->__O2__4expr.e1 =
                                        docast__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
                                    __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)111,
                                        __0this->__O2__4expr.e1, (struct expr *)0);
                                    __0this->__O2__4expr.e1->__O1__4expr.tp = __1t;
                                } else {
                                    register struct cast *__0__X162;

                                    struct expr *__2__X163;

                                    __0this->__O2__4expr.e1 =
                                        (struct expr
                                             *)((__0__X162 = 0),
                                                ((__2__X163 = __0this->__O2__4expr.e1),
                                                 (((__0__X162 ||
                                                    (__0__X162 = (struct cast *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct cast)))))
                                                       ? ((__0__X162 = (struct cast *)
                                                               __ct__4exprFUcP4exprT2(
                                                                   ((struct expr *)__0__X162),
                                                                   (unsigned char)191, __2__X163,
                                                                   (struct expr *)0)),
                                                          (__0__X162->__O1__4expr.tp =
                                                               (__0__X162->__O4__4expr.tp2 = __1t)))
                                                       : 0),
                                                  __0__X162)));

                                    if (__4cn)
                                        __0this->__O2__4expr.e1->__O2__4expr.e1 =
                                            cast_cptr__FP8classdefP4exprP5tablei(
                                                ((struct classdef *)((
                                                    (struct classdef *)__4cn->__O1__4expr.tp))),
                                                __0this->__O2__4expr.e1->__O2__4expr.e1, __1tbl,
                                                (__0this->__O2__4expr.e1->base__4node == 113) ? 1
                                                                                              : 0);
                                }
                            }

                            if ((__1t != __1t2) &&
                                check__4typeFP4typeUcT2(__1t, __1t2, (unsigned char)0,
                                                        (unsigned char)0)) {
                                __1t->permanent__4node = 1;
                                if (__3redo2) {
                                    register struct cast *__0__X164;

                                    struct type *__2__X165;

                                    struct expr *__2__X166;

                                    __0this->__O3__4expr.e2 =
                                        address__4exprFv(__0this->__O3__4expr.e2);
                                    __0this->__O3__4expr.e2 =
                                        (struct expr
                                             *)((__0__X164 = 0),
                                                ((__2__X165 = (struct type *)(__ct__3ptrFUcP4type(
                                                      (struct ptr *)0, (unsigned char)125, __1t))),
                                                 ((__2__X166 = __0this->__O3__4expr.e2),
                                                  (((__0__X164 ||
                                                     (__0__X164 = (struct cast *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct cast)))))
                                                        ? ((__0__X164 = (struct cast *)
                                                                __ct__4exprFUcP4exprT2(
                                                                    ((struct expr *)__0__X164),
                                                                    (unsigned char)191, __2__X166,
                                                                    (struct expr *)0)),
                                                           (__0__X164->__O1__4expr.tp =
                                                                (__0__X164->__O4__4expr.tp2 =
                                                                     __2__X165)))
                                                        : 0),
                                                   __0__X164))));

                                    __0this->__O3__4expr.e2 =
                                        docast__4exprFP5table(__0this->__O3__4expr.e2, __1tbl);
                                    __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)111,
                                        __0this->__O3__4expr.e2, (struct expr *)0);
                                    __0this->__O3__4expr.e2->__O1__4expr.tp = __1t;
                                } else {
                                    register struct cast *__0__X167;

                                    struct expr *__2__X168;

                                    __0this->__O3__4expr.e2 =
                                        (struct expr
                                             *)((__0__X167 = 0),
                                                ((__2__X168 = __0this->__O3__4expr.e2),
                                                 (((__0__X167 ||
                                                    (__0__X167 = (struct cast *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct cast)))))
                                                       ? ((__0__X167 = (struct cast *)
                                                               __ct__4exprFUcP4exprT2(
                                                                   ((struct expr *)__0__X167),
                                                                   (unsigned char)191, __2__X168,
                                                                   (struct expr *)0)),
                                                          (__0__X167->__O1__4expr.tp =
                                                               (__0__X167->__O4__4expr.tp2 = __1t)))
                                                       : 0),
                                                  __0__X167)));

                                    if (__4cn)
                                        __0this->__O3__4expr.e2->__O2__4expr.e1 =
                                            cast_cptr__FP8classdefP4exprP5tablei(
                                                ((struct classdef *)((
                                                    (struct classdef *)__4cn->__O1__4expr.tp))),
                                                __0this->__O3__4expr.e2->__O2__4expr.e1, __1tbl,
                                                (__0this->__O3__4expr.e2->base__4node == 113) ? 1
                                                                                              : 0);
                                }
                            }
                            if ((__4t_ptr && __4pt->memof__3ptr) && (__3MPTR == 0)) {
                                struct ea __0__V79;

                                error__FiPCcRC2eaN33((int)'s', (const char *)"conditionalE with%t",
                                                     (const struct ea *)(((&__0__V79)->__O1__2ea.p =
                                                                              ((const void *)__1t)),
                                                                         (&__0__V79)),
                                                     (const struct ea *)ea0, (const struct ea *)ea0,
                                                     (const struct ea *)ea0);
                            }
                        }
                        }
                    }
                }
            }
        }
    } break;

    case 126:
        __1r1 =
            (kind__4typeFUcN21(__1t1, ((unsigned char)126), (unsigned char)'P', (unsigned char)1));
        __1r2 =
            (kind__4typeFUcN21(__1t2, ((unsigned char)126), (unsigned char)'P', (unsigned char)1));
        __1t = np_promote__FUcN21P4typeT4N21((unsigned char)126, __1r1, __1r2, __1t1, __1t2,
                                             (unsigned char)1, (unsigned char)1);
        goto ass;

    case 127:
        __1r1 =
            (kind__4typeFUcN21(__1t1, ((unsigned char)127), (unsigned char)'P', (unsigned char)1));
        __1r2 =
            (kind__4typeFUcN21(__1t2, ((unsigned char)127), (unsigned char)'P', (unsigned char)1));
        if (((__1r2 == 'P') && (__1r1 != 'P')) && (__1r1 != 'A'))
            error__FPCc((const char *)"P -= nonP");
        __1t = np_promote__FUcN21P4typeT4N21((unsigned char)127, __1r1, __1r2, __1t1, __1t2,
                                             (unsigned char)1, (unsigned char)1);
        goto ass;

    case 128:
    case 129:
        __1r1 = (kind__4typeFUcN21(__1t1, __1b, (unsigned char)'N', (unsigned char)1));
        __1r2 = (kind__4typeFUcN21(__1t2, __1b, (unsigned char)'N', (unsigned char)1));
        __1t = np_promote__FUcN21P4typeT4N21(__1b, __1r1, __1r2, __1t1, __1t2, (unsigned char)1,
                                             (unsigned char)1);

        goto ass;

    case 130:
        __1r1 =
            (kind__4typeFUcN21(__1t1, ((unsigned char)130), (unsigned char)'I', (unsigned char)1));
        __1r2 =
            (kind__4typeFUcN21(__1t2, ((unsigned char)130), (unsigned char)'I', (unsigned char)1));
        __1t = np_promote__FUcN21P4typeT4N21((unsigned char)130, __1r1, __1r2, __1t1, __1t2,
                                             (unsigned char)1, (unsigned char)1);
        goto ass;

    case 131:
    case 132:
    case 133:
    case 134:
    case 135:
        __1r1 = (kind__4typeFUcN21(__1t1, __1b, (unsigned char)'I', (unsigned char)1));
        __1r2 = (kind__4typeFUcN21(__1t2, __1b, (unsigned char)'I', (unsigned char)1));
        ((void)np_promote__FUcN21P4typeT4N21(__1b, __1r1, __1r2, __1t1, __1t2, (unsigned char)0,
                                             (unsigned char)1));

        __1t = (struct type *)int_type;
        goto ass;
    ass:
        if (((__1r1 == 'P') && (check__4typeFP4typeUcT2(__1t1, Pvoid_type, (unsigned char)254,
                                                        (unsigned char)0) == 0)) &&
            (ptr_is_template_formal__FP3ptr(((struct ptr *)(((struct ptr *)__1t1)))) == 0)) {
            struct ea __0__V80;

            error__FPCcRC2eaN32(
                (const char *)"%k of void*",
                (const struct ea *)(((((&__0__V80)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                    (&__0__V80)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        __0this->__O1__4expr.tp = __1t;
        __0this->__O4__4expr.as_type = __1t;
        __1t2 = __1t;

    case 70:
        switch (__0this->__O2__4expr.e1->base__4node) {
        case 147:
        case 71: {
            __0this->__O2__4expr.e1->__O3__4expr.e2 =
                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145, (struct expr *)0,
                                       __0this->__O2__4expr.e1->__O3__4expr.e2);
            __0this->__O2__4expr.e1->__O1__4expr.tp = 0;
            __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                (struct expr *)0, (unsigned char)111, __0this->__O2__4expr.e1, (struct expr *)0);
            return typ__4exprFP5table(__0this, __1tbl);
        }
        case 68: {
            __0this->__O2__4expr.e1->__O2__4expr.e1 =
                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145, (struct expr *)0,
                                       __0this->__O2__4expr.e1->__O2__4expr.e1);
            __0this->__O2__4expr.e1->__O3__4expr.e2 =
                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145, (struct expr *)0,
                                       __0this->__O2__4expr.e1->__O3__4expr.e2);
            __0this->__O2__4expr.e1->__O1__4expr.tp = 0;
            __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                (struct expr *)0, (unsigned char)111, __0this->__O2__4expr.e1, (struct expr *)0);
            return typ__4exprFP5table(__0this, __1tbl);
        }
        case 70:
        case 126:
        case 127:
        case 128:
        case 129:
        case 130:
        case 131:
        case 132:
        case 133:
        case 134:
        case 135: {
            __0this->base__4node = 147;
            nin++;
            if (not_simple__4exprFi(__0this->__O2__4expr.e1->__O2__4expr.e1, 0)) {
                struct ea __0__V81;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"lvalue %k too complicated",
                    (const struct ea *)(((((&__0__V81)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                        (&__0__V81)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            nin--;
            {
                Pexpr __4aa;
                Pexpr __4bb;

                __4aa =
                    __ct__4exprFUcP4exprT2((struct expr *)0, __0this->__O2__4expr.e1->base__4node,
                                           __0this->__O2__4expr.e1->__O2__4expr.e1,
                                           __0this->__O2__4expr.e1->__O3__4expr.e2);

                __4bb = __ct__4exprFUcP4exprT2((struct expr *)0, __1b,
                                               __0this->__O2__4expr.e1->__O2__4expr.e1,
                                               __0this->__O3__4expr.e2);
                __0this->__O2__4expr.e1 = __4aa;
                __0this->__O3__4expr.e2 = __4bb;
                return typ__4exprFP5table(__0this, __1tbl);
            }
        }
        case 48:
        case 49: {
            if (!__0this->__O2__4expr.e1->__O3__4expr.e2)
                break;
            __0this->base__4node = 147;
            nin++;
            if (not_simple__4exprFi(__0this->__O2__4expr.e1->__O3__4expr.e2, 0)) {
                struct ea __0__V82;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"lvalue %k too complicated",
                    (const struct ea *)(((((&__0__V82)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                        (&__0__V82)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            nin--;
            {
                Pexpr __4aa;
                Pexpr __4bb;

                __4aa = __ct__4exprFUcP4exprT2(
                    (struct expr *)0, __0this->__O2__4expr.e1->base__4node, (struct expr *)0,
                    __0this->__O2__4expr.e1->__O3__4expr.e2);
                __4bb = __ct__4exprFUcP4exprT2((struct expr *)0, __1b,
                                               __0this->__O2__4expr.e1->__O3__4expr.e2,
                                               __0this->__O3__4expr.e2);
                __0this->__O2__4expr.e1 = __4aa;
                __0this->__O3__4expr.e2 = __4bb;
                return typ__4exprFP5table(__0this, __1tbl);
            }
        }
        case 44: {
            Pexpr __4r;

            __4r = __0this->__O2__4expr.e1;

            if (((__4r->__O2__4expr.e1->base__4node == 147) &&
                 (__4r->__O2__4expr.e1->__O3__4expr.e2->base__4node == 145)) &&
                (__4r->__O2__4expr.e1->__O3__4expr.e2->__O3__4expr.e2->base__4node == 85)) {
                const char *__5s;

                __5s = __4r->__O2__4expr.e1->__O3__4expr.e2->__O3__4expr.e2->__O2__4expr.string;
                if (((__5s[0]) == '_') && ((__5s[1]) == '_'))
                    error__FPCc((const char *)"left hand side not lvalue");
            }
        }
        }

        if (lval__4exprFUc(__0this->__O2__4expr.e1, __1b) == 0) {
            __0this->__O1__4expr.tp = (struct type *)any_type;
            return __0this;
        }

        __1t1 = skiptypedefs__4typeFv(__1t1);
        switch (__1t1->base__4node) {
        case 21:
        case 5:
        case 29: {
            Ptype __4t;

            __4t = skiptypedefs__4typeFv(__0this->__O3__4expr.e2->__O1__4expr.tp);
            switch (__4t->base__4node) {
                const void *__2__X169;

            case 22:
            case 122:
            case 15:
            case 11:
            case 181: {
                struct ea __0__V83;

                struct ea __0__V84;

                error__FiPCcRC2eaN33(
                    (int)'w', (const char *)"%t assigned to %t",
                    (const struct ea *)((__2__X169 =
                                             (const void *)__0this->__O3__4expr.e2->__O1__4expr.tp),
                                        (((&__0__V83)->__O1__2ea.p = __2__X169), (&__0__V83))),
                    (const struct ea *)(((&__0__V84)->__O1__2ea.p = ((const void *)__1t1)),
                                        (&__0__V84)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            }
        }

        case 22:
        case 122:
            if ((((__1b == 70) &&
                  (((struct basetype *)(((struct basetype *)__1t1))))->b_unsigned__8basetype) &&
                 (__0this->__O3__4expr.e2->base__4node == 107)) &&
                (__0this->__O3__4expr.e2->__O3__4expr.e2->base__4node == 82))
                error__FiPCc((int)'w', (const char *)"negative assigned to unsigned");
            break;
        case 125:
            if (__1b == 70) {
                __0this->__O3__4expr.e2 = ptr_init__FP3ptrP4exprP5table(
                    ((struct ptr *)(((struct ptr *)__1t1))), __0this->__O3__4expr.e2, __1tbl);

                __1t2 = __0this->__O3__4expr.e2->__O1__4expr.tp;

                if (Pchecked) {
                    __0this->__O1__4expr.tp = __0this->__O2__4expr.e1->__O1__4expr.tp;
                    return __0this;
                }
            }
            break;
        case 119: {
            Pname __4c1;

            __4c1 = is_cl_obj__4typeFv(__1t1);

            if (__4c1 && __4c1->__O1__4expr.tp) {
                Pname __5c2;

                __5c2 = is_cl_obj__4typeFv(__1t2);

                if (__4c1 != __5c2) {
                    if ((((__5c2 && __5c2->__O1__4expr.tp) &&
                          (can_coerce__FP4typeT1(__1t1, __1t2) == 0)) &&
                         ((clear__5clistFv(vcllist), (vcllist = 0)),
                          (1 <
                           is_unique_base__FP8classdefPCciT3T1(
                               ((struct classdef *)(((struct classdef *)__5c2->__O1__4expr.tp))),
                               __4c1->__O2__4expr.string, 0, 0, (struct classdef *)0)))) &&
                        ((((struct classdef *)(((struct classdef *)__4c1->__O1__4expr.tp))))
                             ->c_xref__8classdef &
                         13)) {
                        if (make_assignment__FP4name(__4c1))
                            return oper_overload__4exprFP5table(__0this, __1tbl);
                    } else {
                        struct texpr *__0__X170;

                        struct expr *__2__X171;

                        struct classdef *__0__X172;

                        __0this->__O3__4expr.e2 =
                            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                   __0this->__O3__4expr.e2, (struct expr *)0);
                        __0this->__O3__4expr.e2 =
                            (struct expr
                                 *)((__0__X170 = 0),
                                    ((__2__X171 = __0this->__O3__4expr.e2),
                                     (((__0__X170 || (__0__X170 = (struct texpr *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct texpr)))))
                                           ? ((__0__X170 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X170), ((unsigned char)157),
                                                   __2__X171, (struct expr *)0)),
                                              (__0__X170->__O4__4expr.tp2 = __1t1))
                                           : 0),
                                      __0__X170)));
                        if ((((__0__X172 = (((struct classdef *)((
                                   (struct classdef *)__4c1->__O1__4expr.tp))))),
                              (__0__X172->c_dtor__8classdef)) == 0) &&
                            (has_oper__8classdefFUc(
                                 ((struct classdef *)(((struct classdef *)__4c1->__O1__4expr.tp))),
                                 (unsigned char)70) == 0)) {
                            __0this->__O3__4expr.e2->__O3__4expr.e2 = __0this->__O2__4expr.e1;

                            __0this->__O3__4expr.e2 =
                                typ__4exprFP5table(__0this->__O3__4expr.e2, __1tbl);
                            if (((__0this->__O3__4expr.e2->base__4node == 111) &&
                                 (__0this->__O3__4expr.e2->__O2__4expr.e1->base__4node == 146)) ||
                                ((__0this->__O3__4expr.e2->base__4node == 70) &&
                                 (__0this->__O3__4expr.e2->__O2__4expr.e1 ==
                                  __0this->__O2__4expr.e1))) {
                                ((*__0this)) = (*__0this->__O3__4expr.e2);
                            }
                            __0this->__O1__4expr.tp = __1t1;
                            return __0this;
                        }
                        return typ__4exprFP5table(__0this, __1tbl);
                    }
                } else if (__4c1->__O1__4expr.tp &&
                           ((((struct classdef *)(((struct classdef *)__4c1->__O1__4expr.tp))))
                                ->c_xref__8classdef &
                            13)) {
                    if (make_assignment__FP4name(__4c1))
                        return oper_overload__4exprFP5table(__0this, __1tbl);
                }
            }
            ((void)tsizeof__4typeFi(__1t1, 0));
            break;
        }
        }

        {
            Pexpr __3x;

            const void *__2__X173;

            struct type *__1__Xt00anpbtx2ewcog;

            const void *__2__X174;

            __3x = try_to_coerce__FP4typeP4exprPCcP5table(__1t1, __0this->__O3__4expr.e2,
                                                          (const char *)"assignment", __1tbl);

            if (((__1t1->base__4node == 119) && classtype__4typeFv(__1t1)) &&
                has_const_mem__8classdefFv(classtype__4typeFv(__1t1))) {
                struct ea __0__V85;

                error__FPCcRC2eaN32(
                    (const char *)"cannot assign to an object of class %t with const member(s)",
                    (const struct ea *)((__2__X173 = (const void *)classtype__4typeFv(__1t1)),
                                        (((&__0__V85)->__O1__2ea.p = __2__X173), (&__0__V85))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__3x)
                __0this->__O3__4expr.e2 = __3x;
            else if (((__1__Xt00anpbtx2ewcog = skiptypedefs__4typeFv(__1t2)),
                      (((__1__Xt00anpbtx2ewcog->base__4node == 125)
                            ? ((__1__Xt00anpbtx2ewcog = skiptypedefs__4typeFv(
                                    (((struct ptr *)(((struct ptr *)__1__Xt00anpbtx2ewcog))))
                                        ->typ__5pvtyp)),
                               0)
                            : 0),
                       (((unsigned char)((__1__Xt00anpbtx2ewcog->base__4node == ((unsigned char)76))
                                             ? 1
                                             : 0)))))) {
                struct ea __0__V86;

                error__FPCcRC2eaN32(
                    (const char *)"bad assignmentT:%t =&overloaded function",
                    (const struct ea *)((__2__X174 =
                                             (const void *)__0this->__O2__4expr.e1->__O1__4expr.tp),
                                        (((&__0__V86)->__O1__2ea.p = __2__X174), (&__0__V86))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else if (check__4typeFP4typeUcT2(__0this->__O2__4expr.e1->__O1__4expr.tp, __1t2,
                                               (unsigned char)70, (unsigned char)0)) {
                const void *__2__X175;

                {
                    struct ea __0__V87;

                    struct ea __0__V88;

                    error__FiPCcRC2eaN33(
                        (int)'e', (const char *)"bad assignmentT:%t =%t",
                        (const struct ea *)((__2__X175 = (const void *)__0this->__O2__4expr.e1
                                                             ->__O1__4expr.tp),
                                            (((&__0__V87)->__O1__2ea.p = __2__X175), (&__0__V87))),
                        (const struct ea *)(((&__0__V88)->__O1__2ea.p = ((const void *)__1t2)),
                                            (&__0__V88)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    if (no_const)
                        error__FiPCc((int)'c', (const char *)" (no usable const conversion)\n");
                    else
                        error__FiPCc((int)'c', (const char *)"\n");
                }
            } else if ((__1t1 = (struct type *)is_ptr__4typeFv(__1t1)) && memptr__4typeFv(__1t1)) {
                if (__1t2 == (((struct type *)zero_type))) {
                    Pexpr __5ee;

                    __5ee =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, zero, zero);
                    __0this->__O3__4expr.e2 =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)124, __5ee, zero);
                } else if ((__1t2->base__4node == 125) && memptr__4typeFv(__1t2)) {
                } else {
                    Pexpr __5x;

                    __5x = ptr_init__FP3ptrP4exprP5table(((struct ptr *)(((struct ptr *)__1t1))),
                                                         __0this->__O3__4expr.e2, __1tbl);
                    if (__5x != __0this->__O3__4expr.e2)
                        __0this->__O3__4expr.e2 = __5x;
                }
            }
        }
        __1t = __0this->__O2__4expr.e1->__O1__4expr.tp;
        break;
    case 71:
    case 147:
        if (__1t1->base__4node == 108) {
            __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                (struct expr *)0, (unsigned char)145, (struct expr *)0, __0this->__O2__4expr.e1);
            typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
            __1t1 = __0this->__O2__4expr.e1->__O1__4expr.tp;
        }
        if (__1t2->base__4node == 108) {
            __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                (struct expr *)0, (unsigned char)145, (struct expr *)0, __0this->__O3__4expr.e2);
            typ__4exprFP5table(__0this->__O3__4expr.e2, __1tbl);
            __1t2 = __0this->__O3__4expr.e2->__O1__4expr.tp;
        }
        if (__0this->__O2__4expr.e1->base__4node == 124) {
            Pname __3temp1;

            __3temp1 = make_tmp__FcP4typeP5table('A', (struct type *)mptr_type, __1tbl);
            __0this->__O2__4expr.e1 =
                mptr_assign__FP4exprT1((struct expr *)__3temp1, __0this->__O2__4expr.e1);
            __0this->__O2__4expr.e1 =
                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                       __0this->__O2__4expr.e1, (struct expr *)__3temp1);
            __0this->__O2__4expr.e1->__O1__4expr.tp = __3temp1->__O1__4expr.tp;
        }

        if (__0this->__O3__4expr.e2->base__4node == 124) {
            Pname __3temp2;

            __3temp2 = make_tmp__FcP4typeP5table('A', (struct type *)mptr_type, __1tbl);
            __0this->__O3__4expr.e2 =
                mptr_assign__FP4exprT1((struct expr *)__3temp2, __0this->__O3__4expr.e2);
            __0this->__O3__4expr.e2 =
                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                       __0this->__O3__4expr.e2, (struct expr *)__3temp2);
            __0this->__O3__4expr.e2->__O1__4expr.tp = __3temp2->__O1__4expr.tp;
        }

        __1t = __1t2;
        break;
    default: {
        struct ea __0__V89;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"unknown operator%k",
            (const struct ea *)(((((&__0__V89)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                (&__0__V89)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }

    __0this->__O1__4expr.tp = __1t;
    return __0this;
}

bit tconst__4typeFv(struct type *__0this);

bit is_const_obj__4exprFv(register struct expr *__0this) {
    Pexpr __1ee;

    __1ee = __0this;
    if (__1ee == 0)
        return (unsigned char)0;

    while (__1ee && ((__1ee->base__4node == 45) || (__1ee->base__4node == 44))) {
        Pexpr __2m;

        __2m = __1ee->__O4__4expr.mem;
        if (((__1ee->base__4node == 44) && __2m->__O1__4expr.tp) &&
            is_ptr__4typeFv(__2m->__O1__4expr.tp))
            break;
        __1ee = __1ee->__O2__4expr.e1;
    }
    if (__1ee) {
        Pptr __2p;
        Ptype __2ttt;

        __2ttt = __1ee->__O1__4expr.tp;
        switch (__0this->base__4node) {
        case 44: {
            __2p = (__2ttt ? is_ptr__4typeFv(__2ttt) : (((struct ptr *)0)));
            if (__2p && tconst__4typeFv(__2p->typ__5pvtyp))
                return (unsigned char)1;
            break;
        }
        case 45: {
            __2p = (__2ttt ? is_ptr__4typeFv(__2ttt) : (((struct ptr *)0)));
            {
                int __4tc;

                __4tc = (__2ttt ? (((int)tconst__4typeFv(__2ttt))) : 0);
                if ((((!__2p) && __2ttt) && __4tc) && ((!strict_opt) || (__4tc != 2)))
                    return (unsigned char)1;
                break;
            }
        }
        }
    }
    return (unsigned char)0;
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

extern Pstmt stmt_free__4stmt;

extern Pname name_free__4name;

extern Pexpr expr_free__4expr;

extern Pptr ptr_free__3ptr;

extern Pvec vec_free__3vec;

extern Pfct fct_free__3fct;

extern Pktab table_free__6ktable;

extern Ptable table_free__5table;

/* the end */
