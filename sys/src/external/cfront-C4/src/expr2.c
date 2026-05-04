
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

static int const_obj1;

static int const_obj2;

extern Pname hier_dominates__FP4nameT1(Pname, Pname);

Pptr is_ref__4typeFv(struct type *__0this);

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

Pptr is_ptr__4typeFv(struct type *__0this);

Pname really_dominate__FP4nameT1Uc(Pname __1on1, Pname __1on2, bit __1tc) {
    Pname __1best;

    __1best = hier_dominates__FP4nameT1(__1on1, __1on2);
    if (__1best)
        return __1best;

    {
        Pfct __1f1;
        Pfct __1f2;

        Ptype __1t1;
        Ptype __1t2;

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

        __1t1 = skiptypedefs__4typeFv(__1f1->returns__3fct);
        __1t2 = skiptypedefs__4typeFv(__1f2->returns__3fct);

        if (is_ref__4typeFv(__1t1))
            __1t1 = (((struct ptr *)(((struct ptr *)__1t1))))->typ__5pvtyp;
        if (is_ref__4typeFv(__1t2))
            __1t2 = (((struct ptr *)(((struct ptr *)__1t2))))->typ__5pvtyp;

        if (((((!__1t1) || (!__1t2)) ||
              (check__4typeFP4typeUcT2(__1t1, __1t2, (unsigned char)76, (unsigned char)0) &&
               (!const_problem))) ||
             (((is_ref__4typeFv(__1t1) && is_ref__4typeFv(__1t2)) &&
               check__4typeFP4typeUcT2((((struct ptr *)(((struct ptr *)__1t1))))->typ__5pvtyp,
                                       (((struct ptr *)(((struct ptr *)__1t2))))->typ__5pvtyp,
                                       (unsigned char)76, (unsigned char)0)) &&
              (!const_problem))) ||
            (((is_ptr__4typeFv(__1t1) && is_ptr__4typeFv(__1t2)) &&
              check__4typeFP4typeUcT2((((struct ptr *)(((struct ptr *)__1t1))))->typ__5pvtyp,
                                      (((struct ptr *)(((struct ptr *)__1t2))))->typ__5pvtyp,
                                      (unsigned char)76, (unsigned char)0)) &&
             (!const_problem))) {
            return (struct name *)0;
        }

        {
            int __1c1;
            int __1c2;

            __1c1 = __1f1->f_const__3fct;
            __1c2 = __1f2->f_const__3fct;

            if (__1c1 == __1c2)
                ;
            else if (__1c1 && (!__1c2))
                return (__1tc ? __1on1 : __1on2);
            else if (__1c2 && (!__1c1))
                return (__1tc ? __1on2 : __1on1);

            return (struct name *)0;
        }
    }
}

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

void assign__4nameFv(register struct name *__0this) {
    if ((__0this->n_assigned_to__4name++) == 0) {
        switch (__0this->n_scope__4name) {
        case 108:
            if (__0this->n_used__4name && (__0this->n_addr_taken__4name == 0)) {
                Ptype __4t;

                __4t = skiptypedefs__4typeFv(__0this->__O1__4expr.tp);
                switch (__4t->base__4node) {
                case 110:
                    break;
                default:
                    if (curr_loop) {
                        struct ea __0__V46;

                        error__FiP3locPCcRC2eaN34((int)'w', &__0this->where__4name,
                                                  (const char *)"%n may have been used before set",
                                                  (const struct ea *)(((&__0__V46)->__O1__2ea.p =
                                                                           ((const void *)__0this)),
                                                                      (&__0__V46)),
                                                  (const struct ea *)ea0, (const struct ea *)ea0,
                                                  (const struct ea *)ea0);
                    } else {
                        struct ea __0__V47;

                        error__FiP3locPCcRC2eaN34(
                            (int)'w', &__0this->where__4name, (const char *)"%n used before set",
                            (const struct ea *)(((&__0__V47)->__O1__2ea.p =
                                                     ((const void *)__0this)),
                                                (&__0__V47)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
            }
        }
    }
}

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

void take_addr__4nameFv(register struct name *__0this) {
    unsigned long __2__X16;

    struct ea __0__X__V1400qm5qkxojwcnm;

    struct ea __0__X__V1500qm5qkxojwcnm;

    if ((((warning_opt && (!__0this->n_addr_taken__4name)) && __0this->__O1__4expr.tp) &&
         (__0this->__O1__4expr.tp->base__4node == 108)) &&
        (((__0this->__O1__4expr.tp->base__4node == 108)
              ? (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
              : (error__FiPCcRC2eaN33(
                     (int)'i', (const char *)"N::fct_type():%n is %k notF",
                     (const struct ea *)(((&__0__X__V1400qm5qkxojwcnm)->__O1__2ea.p =
                                              ((const void *)__0this)),
                                         (&__0__X__V1400qm5qkxojwcnm)),
                     (const struct ea *)((__2__X16 = __0this->__O1__4expr.tp->base__4node),
                                         (((((&__0__X__V1500qm5qkxojwcnm)->__O1__2ea.i = __2__X16),
                                            0)),
                                          (&__0__X__V1500qm5qkxojwcnm))),
                     (const struct ea *)ea0, (const struct ea *)ea0),
                 (((struct fct *)0)))))
            ->f_inline__3fct) {
        struct ea __0__V48;

        struct ea __0__V49;

        error__FiPCcRC2eaN33(
            (int)'w', (const char *)"can't take address of inlineF%n,%n not inlined",
            (const struct ea *)(((&__0__V48)->__O1__2ea.p = ((const void *)__0this)), (&__0__V48)),
            (const struct ea *)(((&__0__V49)->__O1__2ea.p = ((const void *)__0this)), (&__0__V49)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    __0this->n_addr_taken__4name++;
    if ((__0this->n_sto__4name == 14) && __0this->__O1__4expr.tp) {
        Ptype __2t;

        __2t = skiptypedefs__4typeFv(__0this->__O1__4expr.tp);
        switch (__2t->base__4node) {
        case 119:
            __2t = (((struct basetype *)(((struct basetype *)__2t))))
                       ->b_name__8basetype->__O1__4expr.tp;
        case 6: {
            Pclass __4cl;

            __4cl = (((struct classdef *)(((struct classdef *)__2t))));
            if (__4cl->c_body__8classdef == 1)
                dcl_print__8classdefFP4name(__4cl, (struct name *)0);
        }
        }
    }
}

int ignore_const = 0;

bit tconst__4typeFv(struct type *__0this);

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

static int is_dataMemPtr__FP4expr(Pexpr);

int lval__4exprFUc(struct expr *__0this, TOK __1oper);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

void dcl_print__4nameFUc(struct name *__0this, TOK);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

int lval__4exprFUc(register struct expr *__0this, TOK __1oper) {
    Pexpr __1ee;
    Pname __1n;
    int __1deref;
    const char *__1es;

    __1ee = __0this;

    __1deref = 0;

    switch (__1oper) {
    case 112:
    case 145:
        __1es = (const char *)"address of";

        break;
    case 111:
        __1es = (const char *)"dereference of";

        break;
    case 48:
        __1es = (const char *)"increment of";

        goto def;
    case 49:
        __1es = (const char *)"decrement of";

        goto def;
    default:
        __1es = (const char *)"assignment to";
    def:
        if ((ignore_const == 0) && tconst__4typeFv(__0this->__O1__4expr.tp)) {
            if (__1oper) {
                const char *__4ms;

                __4ms =
                    (const char *)(vec_const ? "array"
                                             : (((char *)(fct_const ? "function"
                                                                    : (((char *)"const type"))))));

                if (__0this->base__4node == 85) {
                    if (vec_const &&
                        ((((struct name *)(((struct name *)__0this))))->n_scope__4name == 136))
                        break;
                    {
                        struct ea __0__V50;

                        struct ea __0__V51;

                        struct ea __0__V52;

                        error__FPCcRC2eaN32(
                            (const char *)"%s%s%n",
                            (const struct ea *)(((&__0__V50)->__O1__2ea.p = ((const void *)__1es)),
                                                (&__0__V50)),
                            (const struct ea *)(((&__0__V51)->__O1__2ea.p = ((const void *)__4ms)),
                                                (&__0__V51)),
                            (const struct ea *)(((&__0__V52)->__O1__2ea.p =
                                                     ((const void *)__0this)),
                                                (&__0__V52)),
                            (const struct ea *)ea0);
                    }
                } else {
                    struct ea __0__V53;

                    struct ea __0__V54;

                    error__FPCcRC2eaN32(
                        (const char *)"%s%s",
                        (const struct ea *)(((&__0__V53)->__O1__2ea.p = ((const void *)__1es)),
                                            (&__0__V53)),
                        (const struct ea *)(((&__0__V54)->__O1__2ea.p = ((const void *)__4ms)),
                                            (&__0__V54)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
            return 0;
        }
    }

    for (;;) {
        switch (__1ee->base__4node) {
        default:
        defa:
            if (__1deref == 0) {
                unsigned long __2__X78;

                if (__1oper) {
                    struct ea __0__V55;

                    struct ea __0__V56;

                    error__FPCcRC2eaN32(
                        (const char *)"%s%k (not an lvalue)",
                        (const struct ea *)(((&__0__V55)->__O1__2ea.p = ((const void *)__1es)),
                                            (&__0__V55)),
                        (const struct ea *)((__2__X78 = __1ee->base__4node),
                                            (((((&__0__V56)->__O1__2ea.i = __2__X78), 0)),
                                             (&__0__V56))),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
                return 0;
            }
            return 1;
        case 86:
        case 84:
        case 82:
        case 83:
            if (__1oper) {
                struct ea __0__V57;

                error__FPCcRC2eaN32(
                    (const char *)"%s numeric constant",
                    (const struct ea *)(((&__0__V57)->__O1__2ea.p = ((const void *)__1es)),
                                        (&__0__V57)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            return 0;
        case 81:
            if (__1oper) {
                struct ea __0__V58;

                error__FiPCcRC2eaN33(
                    (int)'w', (const char *)"%s string constant",
                    (const struct ea *)(((&__0__V58)->__O1__2ea.p = ((const void *)__1es)),
                                        (&__0__V58)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            return 1;
        case 113:
        case 191:
            switch (__1oper) {
            case 0:
            case 112:
            case 145:
            case 111:
                goto defa;
            default:
                if ((__1ee->__O1__4expr.tp->base__4node == 125) && is_dataMemPtr__FP4expr(__1ee)) {
                    Pexpr __5te;
                    __5te = __1ee->__O2__4expr.e1->__O2__4expr.e1->__O2__4expr.e1;
                    if (__5te->base__4node == 145)
                        __5te = __5te->__O3__4expr.e2;
                    if (__5te->base__4node == 85) {
                        Ptype __6pt;

                        __6pt = __5te->__O1__4expr.tp;
                        if (__6pt->base__4node == 125)
                            __6pt = (((struct ptr *)(((struct ptr *)__6pt))))->typ__5pvtyp;
                        if (tconst__4typeFv(__6pt)) {
                            struct ea __0__V59;

                            struct ea __0__V60;

                            error__FPCcRC2eaN32((const char *)"%sCMP of const%n",
                                                (const struct ea *)(((&__0__V59)->__O1__2ea.p =
                                                                         ((const void *)__1es)),
                                                                    (&__0__V59)),
                                                (const struct ea *)(((&__0__V60)->__O1__2ea.p =
                                                                         ((const void *)__5te)),
                                                                    (&__0__V60)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                        }
                        return 0;
                    }
                }
                goto defa;
            }

        case 111: {
            Pexpr __4ee1;

            __4ee1 = __1ee->__O2__4expr.e1;

            switch (__4ee1->base__4node) {
            case 112:
                return 1;
            case 147:
            case 71:
                if ((__4ee1->__O3__4expr.e2->base__4node == 145) ||
                    (__4ee1->__O3__4expr.e2->base__4node == 112))
                    return 1;
                goto defaa;
            case 68:
                if (((__4ee1->__O2__4expr.e1->base__4node == 145) ||
                     (__4ee1->__O2__4expr.e1->base__4node == 112)) &&
                    ((__4ee1->__O3__4expr.e2->base__4node == 145) ||
                     (__4ee1->__O3__4expr.e2->base__4node == 112)))
                    return 1;

            default:
            defaa:
                __1ee = __4ee1;
                __1deref = 1;
            }
            break;
        }

        case 68: {
            int __4x1;
            int __4x2;

            __4x1 = lval__4exprFUc(__1ee->__O2__4expr.e1,
                                   (unsigned char)(__1deref ? 0 : (((int)__1oper))));
            __4x2 = lval__4exprFUc(__1ee->__O3__4expr.e2,
                                   (unsigned char)(__1deref ? 0 : (((int)__1oper))));
            if (check__4typeFP4typeUcT2(__1ee->__O2__4expr.e1->__O1__4expr.tp,
                                        __1ee->__O3__4expr.e2->__O1__4expr.tp, (unsigned char)0,
                                        (unsigned char)0))
                return 0;
            if (__1deref)
                return 1;
            return (__4x1 && __4x2);
        }

        case 48:
        case 49:
            if (__0this->__O2__4expr.e1)
                goto defa;
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
            return 1;

        case 71:
        case 147:
            if (lval__4exprFUc(__1ee->__O3__4expr.e2,
                               (unsigned char)(__1deref ? 0 : (((int)__1oper)))) == 0)
                return __1deref;
            return 1;

        case 173:
            __1ee = __1ee->__O3__4expr.e2;
            break;

        case 177:
            __1ee = __1ee->__O4__4expr.mem;
            break;

        case 45: {
            Pexpr __4e;
            int __4e_const;

            __4e = 0;
            __4e_const = 0;

            switch (__1ee->__O2__4expr.e1->base__4node) {
            case 85:
                switch (__1oper) {
                case 112:
                case 145:
                    take_addr__4nameFv(((struct name *)(((struct name *)__1ee->__O2__4expr.e1))));
                case 0:
                    break;
                case 70:
                    (((struct name *)(((struct name *)__1ee->__O2__4expr.e1))))->n_used__4name--;
                default:
                    assign__4nameFv(((struct name *)(((struct name *)__1ee->__O2__4expr.e1))));
                }
                break;
            case 45:
                __4e = __1ee->__O2__4expr.e1;
                do
                    __4e = __4e->__O2__4expr.e1;
                while (__4e->base__4node == 45);

                if (__4e->base__4node == 85) {
                    __4e_const = tconst__4typeFv(__4e->__O1__4expr.tp);
                    switch (__1oper) {
                    case 112:
                    case 145:
                        take_addr__4nameFv(((struct name *)(((struct name *)__4e))));
                    case 0:
                        break;
                    case 70:
                        (((struct name *)(((struct name *)__4e))))->n_used__4name--;
                    default:
                        assign__4nameFv(((struct name *)(((struct name *)__4e))));
                    }
                }
            }

            __1n = (((struct name *)(((struct name *)__1ee->__O4__4expr.mem))));
            while (__1n->base__4node == 177)
                __1n = (((struct name *)((
                    (struct name *)(((struct ref *)(((struct ref *)__1n))))->__O4__4expr.mem))));

            if ((__1deref == 0) &&
                (tconst__4typeFv(__1ee->__O2__4expr.e1->__O1__4expr.tp) || __4e_const)) {
                switch (__1oper) {
                case 0:
                case 112:
                case 145:
                case 111:
                    break;
                default: {
                    struct ea __0__V61;

                    struct ea __0__V62;

                    struct ea __0__V63;

                    error__FPCcRC2eaN32(
                        (const char *)"%sM%n of%t",
                        (const struct ea *)(((&__0__V61)->__O1__2ea.p = ((const void *)__1es)),
                                            (&__0__V61)),
                        (const struct ea *)(((&__0__V62)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V62)),
                        (const struct ea *)__ct__2eaFPCv(
                            &__0__V63,
                            (const void *)(__4e_const ? __4e->__O1__4expr.tp
                                                      : __1ee->__O2__4expr.e1->__O1__4expr.tp)),
                        (const struct ea *)ea0);
                }
                }
                return 0;
            }
        }
            goto xx;

        case 44:
            __1n = (((struct name *)(((struct name *)__1ee->__O4__4expr.mem))));
            while (__1n->base__4node == 177)
                __1n = (((struct name *)((
                    (struct name *)(((struct ref *)(((struct ref *)__1n))))->__O4__4expr.mem))));

            if ((__1deref == 0) && __1ee->__O2__4expr.e1) {
                Ptype __4p;

                __4p = skiptypedefs__4typeFv(__1ee->__O2__4expr.e1->__O1__4expr.tp);

                switch (__4p->base__4node) {
                case 125:
                case 110:
                    break;
                case 141:
                    return 0;
                default: {
                    struct ea __0__V64;

                    struct ea __0__V65;

                    error__FiPCcRC2eaN33(
                        (int)'i', (const char *)"expr::lval%t ->%n",
                        (const struct ea *)(((&__0__V64)->__O1__2ea.p = ((const void *)__4p)),
                                            (&__0__V64)),
                        (const struct ea *)(((&__0__V65)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V65)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
                }
                if ((ignore_const == 0) &&
                    tconst__4typeFv((((struct ptr *)(((struct ptr *)__4p))))->typ__5pvtyp)) {
                    switch (__1oper) {
                    case 0:
                    case 112:
                    case 145:
                    case 111:
                        break;
                    default: {
                        struct ea __0__V66;

                        struct ea __0__V67;

                        struct ea __0__V68;

                        error__FPCcRC2eaN32(
                            (const char *)"%sM%n of%t",
                            (const struct ea *)(((&__0__V66)->__O1__2ea.p = ((const void *)__1es)),
                                                (&__0__V66)),
                            (const struct ea *)(((&__0__V67)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V67)),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V68, (const void *)(((struct ptr *)(((struct ptr *)__4p))))
                                               ->typ__5pvtyp),
                            (const struct ea *)ea0);
                    }
                    }
                    return 0;
                }
            }
            goto xx;

        case 85:
            __1n = (((struct name *)(((struct name *)__1ee))));
        xx:
            if (__1deref)
                return 1;
            if (__1oper == 0)
                return (__1n->n_stclass__4name != 13);

            if ((__1n->__O1__4expr.tp->base__4node == 114) &&
                ((((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp))))
                     ->b_bits__8basetype == 0)) {
                {
                    struct ea __0__V69;

                    struct ea __0__V70;

                    error__FPCcRC2eaN32(
                        (const char *)"%s 0-length field%n",
                        (const struct ea *)(((&__0__V69)->__O1__2ea.p = ((const void *)__1es)),
                                            (&__0__V69)),
                        (const struct ea *)(((&__0__V70)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V70)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    return 0;
                }
            }

            switch (__1oper) {
            case 112:
            case 145: {
                if (__1n->n_sto__4name == 27) {
                    if (warning_opt) {
                        struct ea __0__V71;

                        error__FiPCcRC2eaN33(
                            (int)'w', (const char *)"& register%n",
                            (const struct ea *)(((&__0__V71)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V71)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    __1n->n_sto__4name = 0;
                    __1n->n_stclass__4name = 2;
                }

                if (__1n->__O1__4expr.tp == 0) {
                    {
                        struct ea __0__V72;

                        error__FPCcRC2eaN32(
                            (const char *)"& label%n",
                            (const struct ea *)(((&__0__V72)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V72)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        return 0;
                    }
                }

                if (__1n->n_stclass__4name == 13) {
                    {
                        struct ea __0__V73;

                        error__FPCcRC2eaN32(
                            (const char *)"& enumerator%n",
                            (const struct ea *)(((&__0__V73)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V73)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        return 0;
                    }
                }

                if (__1n->__O1__4expr.tp->base__4node == 114) {
                    {
                        struct ea __0__V74;

                        error__FPCcRC2eaN32(
                            (const char *)"& field%n",
                            (const struct ea *)(((&__0__V74)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V74)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        return 0;
                    }
                }

                __1n->n_used__4name--;
                if (__1n->__O2__4name.n_qualifier) {
                    Pname __6tn;

                    __6tn = look__5tableFPCcUc(
                        (((struct classdef *)(((struct classdef *)__1n->__O4__4expr.n_table
                                                   ->t_name__5table->__O1__4expr.tp))))
                            ->memtbl__8classdef,
                        __1n->__O2__4expr.string, (unsigned char)0);
                    __1n = (__6tn ? __6tn : __1n);
                }
                take_addr__4nameFv(__1n);

                {
                    int __5statmem;

                    __5statmem = (((__1n->n_scope__4name == 0) || (__1n->n_scope__4name == 25)) ||
                                  (__1n->n_scope__4name == 108));
                    if (__1n->n_evaluated__4name && (__1n->n_scope__4name != 136)) {
                        if ((__5statmem == 0) && (__1n->n_dcl_printed__4name == 0)) {
                            struct ival *__0__X79;

                            long long __2__X80;

                            __1n->__O3__4expr.n_initializer =
                                (struct expr
                                     *)((__0__X79 = 0),
                                        ((__2__X80 = __1n->n_val__4name),
                                         (((__0__X79 || (__0__X79 = (struct ival *)__nw__4exprSFUl(
                                                             (size_t)(sizeof(struct ival)))))
                                               ? ((__0__X79 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                       ((struct expr *)__0__X79),
                                                       (unsigned char)150, (struct expr *)0,
                                                       (struct expr *)0)),
                                                  (__0__X79->__O2__4expr.i1 = __2__X80))
                                               : 0),
                                          __0__X79)));
                            dcl_print__4nameFUc(__1n, (unsigned char)0);
                        }
                    } else if ((__1n->__O1__4expr.tp->base__4node == 108) &&
                               (__1n->n_dcl_printed__4name == 0)) {
                        Pfct __6f;

                        __6f = (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))));
                        if (__6f->fct_base__3fct == 4)
                            current_fct_instantiation = __6f;
                        if ((!__6f->fct_base__3fct) || (__6f->fct_base__3fct == 4))
                            dcl_print__4nameFUc(__1n, (unsigned char)0);
                        if (__6f->fct_base__3fct == 4)
                            current_fct_instantiation = 0;
                    }
                    break;
                }
            }

            case 70:
                __1n->n_used__4name--;
                assign__4nameFv(__1n);
                break;
            case 48:
            case 49:
                if (skiptypedefs__4typeFv(__1n->__O1__4expr.tp)->base__4node == 121) {
                    {
                        struct ea __0__V75;

                        error__FPCcRC2eaN32(
                            (const char *)"%s enum",
                            (const struct ea *)(((&__0__V75)->__O1__2ea.p = ((const void *)__1es)),
                                                (&__0__V75)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        return 0;
                    }
                }

            default:
                if (cc->tot__11dcl_context && (__1n == cc->c_this__11dcl_context)) {
                    {
                        struct ea __0__V76;

                        struct ea __0__V77;

                        error__FPCcRC2eaN32(
                            (const char *)"%n%k",
                            (const struct ea *)(((&__0__V76)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V76)),
                            (const struct ea *)(((((&__0__V77)->__O1__2ea.i =
                                                       ((unsigned long)__1oper)),
                                                  0)),
                                                (&__0__V77)),
                            (const struct ea *)ea0, (const struct ea *)ea0);

                        return 0;
                    }
                }
                assign__4nameFv(__1n);
            }
            return 1;
        }
    }
}

extern int error__FPCc(const char *);

int char_to_int__FPCc(const char *__1s) {
    int __1i;
    char __1c;

    char __1d;

    char __1e;

    __1i = 0;

    switch ((*__1s)) {
    default:
        error__FiPCc((int)'i', (const char *)"char constant store corrupted");

    case '`':
        error__FPCc((const char *)"bcd constant");
        return 0;
    case '\'':
        break;
    }

    for (;;)
        switch (__1c = ((*(++__1s)))) {
        case '\'':
            return __1i;
        case '\\':
            switch (__1c = ((*(++__1s)))) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
                __1c -= '0';
                switch (__1d = ((*(++__1s)))) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                    __1d -= '0';

                    switch (__1e = ((*(++__1s)))) {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                        __1c = ((((__1c * 64) + (__1d * 8)) + __1e) - '0');
                        break;
                    default:
                        __1c = ((__1c * 8) + __1d);
                        __1s--;
                    }
                    break;
                default:
                    __1s--;
                }
                break;
            case 'a':
                __1c = '\a';
                break;
            case 'b':
                __1c = '\b';
                break;
            case 'f':
                __1c = '\f';
                break;
            case 'n':
                __1c = '\n';
                break;
            case 'r':
                __1c = '\r';
                break;
            case 't':
                __1c = '\t';
                break;
            case 'v':
                __1c = '\v';
                break;
            case '\\':
                __1c = '\\';
                break;
            case '\'':
                __1c = '\'';
                break;
            }

        default:
            if (__1i)
                __1i <<= BI_IN_BYTE;
            __1i += __1c;
        }
}

long long str_to_llong__FPCc(const char *__1p);

long long str_to_llong__FPCc(const char *__1p) {
    int __1c;

    int __1j;
    int __1dotflag;
    int __1dotcount;
    long long __1exp;
    unsigned long long __1i;
    const char *__1pp;

    __1dotflag = 0;
    __1dotcount = 0;
    __1exp = 0;
    __1i = 0;
    __1pp = __1p;

    if ((__1c = ((*(__1p++)))) == '0') {
        switch (__1c = ((*(__1p++)))) {
        case 0:
            return (long long)0;

        case 'l':
        case 'L':
            return (long long)0;

        case 'x':
        case 'X':
            while (__1c = ((*(__1p++)))) {
                switch (__1c) {
                case 'l':
                case 'L':
                case 'U':
                case 'u':
                    return (long long)__1i;
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                    __1i = (((__1i * 16) + __1c) - 55);
                    break;
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                    __1i = (((__1i * 16) + __1c) - 87);
                    break;
                default:
                    __1i = (((__1i * 16) + __1c) - '0');
                }
            }
            return (long long)__1i;

        default:
            do
                switch (__1c) {
                case 'l':
                case 'L':
                case 'U':
                case 'u':
                    return (long long)__1i;
                default:
                    __1i = (((__1i * 8) + __1c) - '0');
                }
            while (__1c = ((*(__1p++))));
            return (long long)__1i;
        }
    }

    __1i = (__1c - '0');
    while (__1c = ((*(__1p++))))
        switch (__1c) {
        case 'l':
        case 'L':
        case 'U':
        case 'u':
            return (long long)__1i;
        case '.':
            __1dotflag = 1;
            break;
        case 'e':
        case 'E': {
            int __3negative;

            __3negative = 1;
            if ((((*__1p)) == '+') || (((*__1p)) == '-'))
                __3negative = ((((*(__1p++))) == '-') ? -1 : 1);
            __1exp = (str_to_llong__FPCc(__1p) * __3negative);
            __1exp = (__1exp - __1dotcount);
            if (__1exp >= 1) {
                unsigned long long __4ii;

                __4ii = __1i;
                for (__1j = 0; __1exp > __1j; ((__1j++), (__4ii = __1i))) {
                    __1i = (__1i * 10);
                    if (__1i < __4ii) {
                        {
                            struct ea __0__V81;

                            error__FiPCcRC2eaN33(
                                (int)'w', (const char *)"integral conversion of %s is out of range",
                                (const struct ea *)(((&__0__V81)->__O1__2ea.p =
                                                         ((const void *)__1pp)),
                                                    (&__0__V81)),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                            return (long long)__1i;
                        }
                    }
                }
            } else
                for (__1j = 0; __1exp < __1j; __1j--)
                    __1i /= 10;
            return (long long)__1i;
        }
        default: {
            unsigned long long __3ii;

            __3ii = __1i;
            __1i = (((__1i * 10) + __1c) - '0');
            if (__1dotflag)
                __1dotcount++;
            if (__1i < __3ii)
                goto bad;
        }
        }
    return (long long)__1i;
bad: {
    struct ea __0__V82;

    error__FPCcRC2eaN32(
        (const char *)"integer constant %s larger than the largest long long",
        (const struct ea *)(((&__0__V82)->__O1__2ea.p = ((const void *)__1pp)), (&__0__V82)),
        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    return (long long)__1i;
}
}

extern int sprintf(char *, const char *, ...);

extern size_t strlen(const char *);

extern char *strcpy(char *, const char *);

static void ftp_normalize__FRPc(char **__1str) {
    char *__1p;
    char *__1pp;
    char __1c;
    int __1adjust;
    int __1dotflag;
    int __1dotcnt;

    __1p = ((*__1str));
    __1pp = ((*__1str));

    __1adjust = 0;
    __1dotflag = 0;
    __1dotcnt = 0;

    while (__1c = ((*__1p))) {
        switch (__1c) {
        case '+':
        case '-':
            __1pp++;
            break;
        case '0':
            if (__1dotflag)
                __1dotcnt++;
            break;
        case '.':
            __1dotflag = 1;
            break;
        default: {
            if (__1p == __1pp)
                return;
            ((*(__1pp++))) = ((*(__1p++)));
            if (__1dotflag == 0) {
                while ((*__1p))
                    ((*(__1pp++))) = ((*(__1p++)));
                ((*__1pp)) = 0;
                return;
            } else {
                ((*(__1pp++))) = '.';
                while ((((*__1p)) != 'E') && (((*__1p)) != 'e'))
                    if (((*__1p)) == '.')
                        __1p++;
                    else
                        ((*(__1pp++))) = ((*(__1p++)));
            }
            __1adjust = 1;
        }
        case 'E':
        case 'e': {
            if (__1adjust == 0) {
                ((*(__1pp++))) = '0';
                ((*__1pp)) = 0;
                return;
            }

            ((*(__1pp++))) = ((*(__1p++)));
            {
                int __4sign;

                __4sign = 1;
                if ((((*__1p)) == '+') || (((*__1p)) == '-'))
                    __4sign = ((((*(__1p++))) == '-') ? -1 : 1);
                {
                    long long __4i;
                    char __4tmp[40];

                    __4i = (((__4sign * str_to_llong__FPCc((const char *)__1p)) - __1dotcnt) - 1);

                    sprintf((char *)__4tmp, (const char *)"%-lld", __4i);
                    if ((strlen((const char *)__1p) + (__1p - __1pp)) <
                        strlen((const char *)__4tmp)) {
                        char *__5newstr;

                        __5newstr = (((char *)__nw__FUl(
                            (size_t)((sizeof(char)) *
                                     ((strlen((const char *)__4tmp) + (__1pp - ((*__1str)))) +
                                      1)))));

                        strcpy(__5newstr, (const char *)((*__1str)));
                        {
                            int __5offset;

                            __5offset = (__1pp - ((*__1str)));
                            ((*__1str)) = __5newstr;
                            __1pp = (((*__1str)) + __5offset);
                        }
                    }
                    sprintf(__1pp, (const char *)"%-lld", __4i);
                    return;
                }
            }
        }
        }
        __1p++;
    }
}

bit is_unsigned__4typeFv(register struct type *__0this) {
    Ptype __1t;

    __1t = skiptypedefs__4typeFv(__0this);
    if (__1t->base__4node == 125)
        return (unsigned char)0;
    return (((struct basetype *)(((struct basetype *)__1t))))->b_unsigned__8basetype;
}

const char *Neval = 0;
bit binary_val = 0;

long long eval__4exprFv(struct expr *__0this);

unsigned long long ueval__4exprFmT1(register struct expr *__0this, long long __1x1,
                                    long long __1x2) {
    unsigned long long __1i1;
    unsigned long long __1i2;

    __1i1 = (((unsigned long long)__1x1));
    __1i2 = (((unsigned long long)__1x2));

    switch (__0this->base__4node) {
    case 107:
        return (-__1i2);
    case 172:
        return __1i2;
    case 46:
        return (unsigned long long)(!__1i2);
    case 47:
        return (~__1i2);
    case 113:
    case 191:
        return __1i1;
    case 54:
        return (__1i1 + __1i2);
    case 55:
        return (__1i1 - __1i2);
    case 50:
        return (__1i1 * __1i2);
    case 56:
        return (__1i1 << __1i2);
    case 57:
        return (__1i1 >> __1i2);
    case 63:
        return (unsigned long long)(__1i1 != __1i2);
    case 62:
        return (unsigned long long)(__1i1 == __1i2);
    case 58:
        return (unsigned long long)(__1i1 < __1i2);
    case 59:
        return (unsigned long long)(__1i1 <= __1i2);
    case 60:
        return (unsigned long long)(__1i1 > __1i2);
    case 61:
        return (unsigned long long)(__1i1 >= __1i2);
    case 52:
        return (__1i1 & __1i2);
    case 66:
        return (unsigned long long)(__1i1 && __1i2);
    case 65:
        return (__1i1 | __1i2);
    case 67:
        return (unsigned long long)(__1i1 || __1i2);
    case 64:
        return (__1i1 ^ __1i2);
    case 53:
        if (__1i2 == 0) {
            if (Neval == 0) {
                Neval = (const char *)"mod zero";

                error__FPCc((const char *)"mod zero");
            }
            return (unsigned long long)1;
        }
        return (__1i1 % __1i2);
    case 68:
        return (eval__4exprFv(__0this->__O4__4expr.cond) ? __1i1 : __1i2);
    case 51:
        if (__1i2 == 0) {
            if (Neval == 0) {
                Neval = (const char *)"divide by zero";

                error__FPCc((const char *)"divide by zero");
            }
            return (unsigned long long)1;
        }
        return (__1i1 / __1i2);
    case 71:
    case 147:
        return __1i2;
    }

    Neval = (const char *)"unsigned expression";
    return (unsigned long long)0;
}

bit vec_type__4typeFv(struct type *__0this);

int tsizeof__4typeFi(struct type *__0this, int);

extern int strcmp(const char *, const char *);

extern char *strdup(const char *);

extern char *strchr(const char *, int);

long long eval__4exprFv(register struct expr *__0this) {
    Ptype __1tt;

    if (Neval)
        return (long long)1;

    ;

    switch (__0this->base__4node) {
    case 86:
        return (long long)0;
    case 150:
        return __0this->__O2__4expr.i1;
    case 82:
        return str_to_llong__FPCc(__0this->__O2__4expr.string);
    case 84:
        return (long long)char_to_int__FPCc(__0this->__O2__4expr.string);
    case 83:
        Neval = (const char *)"float in constant expression";

        return (long long)1;
    case 81:
        Neval = (const char *)"string in constant expression";

        return (long long)1;
    case 121:
        return (((struct name *)(((struct name *)__0this))))->n_val__4name;
    case 30: {
        extern int no_sizeof;
        if (no_sizeof)
            Neval = (const char *)"sizeof";
        {
            const char *__3cese;

            __3cese = (const char *)"cannot evaluate sizeof expression";
            if (!__0this->__O4__4expr.tp2) {
                Neval = __3cese;
                return (long long)1;
            } else {
                __1tt = __0this->__O4__4expr.tp2;
                while (__1tt && vec_type__4typeFv(__1tt)) {
                    __1tt = skiptypedefs__4typeFv(__1tt);
                    if (__1tt->base__4node == 141) {
                        Neval = __3cese;
                        return (long long)1;
                    }

                    __1tt = ((__1tt->base__4node == 110)
                                 ? (((struct vec *)(((struct vec *)__1tt))))->typ__5pvtyp
                                 : (((struct ptr *)(((struct ptr *)__1tt))))->typ__5pvtyp);
                }
            }
            return (long long)tsizeof__4typeFi(__0this->__O4__4expr.tp2, 0);
        }
    }

    case 85: {
        Pname __3n;

        __3n = (((struct name *)(((struct name *)__0this))));

        if (__3n->n_evaluated__4name && (__3n->n_scope__4name != 136))
            return __3n->n_val__4name;
        if (binary_val && (strcmp(__0this->__O2__4expr.string, (const char *)"_result") == 0))
            return (long long)8888;
        Neval = (const char *)"cannot evaluate constant";
        return (long long)1;
    }
    case 168:
        if (__0this->__O2__4expr.e1) {
            __0this->__O4__4expr.il->i_next__5iline = curr_icall;
            curr_icall = __0this->__O4__4expr.il;
            {
                long long __3i;

                __3i = eval__4exprFv(__0this->__O2__4expr.e1);
                curr_icall = __0this->__O4__4expr.il->i_next__5iline;
                return __3i;
            }
        }
        Neval = (const char *)"void inlineF";
        return (long long)1;
    case 169: {
        Pname __3n;

        Pin __3il;

        __3n = (((struct name *)(((struct name *)__0this))));

        for (__3il = curr_icall; __3il; __3il = __3il->i_next__5iline)
            if (__3il->i_table__5iline == __3n->__O4__4expr.n_table)
                goto aok;
        goto bok;
    aok:
        if ((__3il->i_args__5iline[__3n->argno__4name]).local__2ia) {
        bok:
            Neval = (const char *)"inlineF call too complicated for constant expression";
            return (long long)1;
        }
        {
            Pexpr __3aa;

            __3aa = (__3il->i_args__5iline[__3n->argno__4name]).arg__2ia;
            return eval__4exprFv(__3aa);
        }
    }
    case 113:
    case 191: {
        if (((__0this->__O4__4expr.tp2->base__4node != 15) &&
             (__0this->__O4__4expr.tp2->base__4node != 11)) &&
            ((__0this->__O2__4expr.e1->base__4node == 83) ||
             (((__0this->__O2__4expr.e1->base__4node == 107) ||
               (__0this->__O2__4expr.e1->base__4node == 172)) &&
              (__0this->__O2__4expr.e1->__O3__4expr.e2->base__4node == 83)))) {
            const char **__4str;
            const char *__4p;

            __4str = (const char **)((__0this->__O2__4expr.e1->base__4node == 83)
                                         ? (&__0this->__O2__4expr.e1->__O2__4expr.string)
                                         : (&__0this->__O2__4expr.e1->__O3__4expr.e2->__O2__4expr
                                                 .string));

            __4p = ((*__4str));
            while (((((*__4p)) && (((*__4p)) != '.')) && (((*__4p)) != 'E')) && (((*__4p)) != 'e'))
                __4p++;
            if ((*__4p)) {
                char *__5str_tmp;

                __5str_tmp = strdup((*__4str));
                if ((strchr(__4p, (int)'E') == 0) && (strchr(__4p, (int)'e') == 0)) {
                    char *__6p2;

                    __6p2 = (__5str_tmp + (__4p - ((*__4str))));
                    if (__6p2 == __5str_tmp)
                        ((*(__6p2++))) = '0';
                    ((*__6p2)) = 0;
                } else {
                    ftp_normalize__FRPc((char **)(&__5str_tmp));
                }

                if (__0this->__O2__4expr.e1->base__4node == 83)
                    __0this->__O2__4expr.e1->__O2__4expr.string = (const char *)__5str_tmp;
                else
                    __0this->__O2__4expr.e1->__O3__4expr.e2->__O2__4expr.string =
                        (const char *)__5str_tmp;
            }
            if (__0this->__O2__4expr.e1->base__4node == 83)
                __0this->__O2__4expr.e1->base__4node = 82;
            else
                __0this->__O2__4expr.e1->__O3__4expr.e2->base__4node = 82;
        }
        {
            long long __3i;

            __3i = eval__4exprFv(__0this->__O2__4expr.e1);
            __1tt = skiptypedefs__4typeFv(__0this->__O4__4expr.tp2);

            switch (__1tt->base__4node) {
            default:
                Neval = (const char *)"cast to non-integral type in constant expression";
                break;
            case 13:
            case 121:
            case 22:
            case 122:
            case 21:
            case 5:
            case 29: {
                long long __5j;

                __5j = (((~(((unsigned long long)0)))
                         << (BI_IN_BYTE * (tsizeof__4typeFi(__0this->__O4__4expr.tp2, 0) - 1)))
                        << BI_IN_BYTE);
                __3i &= (~__5j);
                if (is_unsigned__4typeFv(__1tt) == 0)
                    if ((((long long)(__3i << (BI_IN_BYTE *
                                               ((sizeof(long long)) -
                                                tsizeof__4typeFi(__0this->__O4__4expr.tp2, 0)))))) <
                        0)
                        __3i |= __5j;
                break;
            }
            }
            return __3i;
        }
    }
    case 107:
    case 172:
    case 46:
    case 47:
    case 54:
    case 55:
    case 50:
    case 56:
    case 57:
    case 63:
    case 58:
    case 59:
    case 60:
    case 61:
    case 52:
    case 65:
    case 64:
    case 51:
    case 53:
    case 68:
    case 62:
    case 66:
        break;
    case 67:
        if (binary_val) {
            long long __3i1;

            __3i1 = (__0this->__O2__4expr.e1 ? eval__4exprFv(__0this->__O2__4expr.e1)
                                             : (((long long)0)));
            if (((Neval == 0) && __3i1) &&
                (is_unsigned__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp) == 0))
                return __3i1;
        }
        break;
    case 71:
    case 147:
        Neval = (const char *)"comma operator in constant expression";
        return (long long)1;
    case 145:
    case 112:
        if (binary_val) {
            switch (__0this->__O3__4expr.e2->base__4node) {
            case 85:
            case 45:
            case 44:
                return (long long)9999;
            }
        }
    default:
        Neval = (const char *)"bad operator in constant expression";
        return (long long)1;
    }

    {
        long long __1i1;
        long long __1i2;

        __1i1 =
            (__0this->__O2__4expr.e1 ? eval__4exprFv(__0this->__O2__4expr.e1) : (((long long)0)));
        __1i2 =
            (__0this->__O3__4expr.e2 ? eval__4exprFv(__0this->__O3__4expr.e2) : (((long long)0)));

        if ((binary_val && (__1i1 == 9999)) && (__1i2 == 9999)) {
            Neval = (const char *)"";

            return (long long)1;
        }

        if ((Neval == 0) &&
            (((__0this->__O2__4expr.e1 && __0this->__O2__4expr.e1->__O1__4expr.tp) &&
              is_unsigned__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp)) ||
             ((__0this->__O3__4expr.e2 && __0this->__O3__4expr.e2->__O1__4expr.tp) &&
              is_unsigned__4typeFv(__0this->__O3__4expr.e2->__O1__4expr.tp))))
            return (((long long)ueval__4exprFmT1(__0this, __1i1, __1i2)));

        switch (__0this->base__4node) {
        case 107:
            return (-__1i2);
        case 172:
            return __1i2;
        case 46:
            return (long long)(!__1i2);
        case 47:
            return (~__1i2);
        case 113:
        case 191:
            return __1i1;
        case 54:
            return (__1i1 + __1i2);
        case 55:
            return (__1i1 - __1i2);
        case 50:
            return (__1i1 * __1i2);
        case 56:
            return (__1i1 << __1i2);
        case 57:
            return (__1i1 >> __1i2);
        case 63:
            return (long long)(__1i1 != __1i2);
        case 62:
            return (long long)(__1i1 == __1i2);
        case 58:
            return (long long)(__1i1 < __1i2);
        case 59:
            return (long long)(__1i1 <= __1i2);
        case 60:
            return (long long)(__1i1 > __1i2);
        case 61:
            return (long long)(__1i1 >= __1i2);
        case 52:
            return (__1i1 & __1i2);
        case 66:
            return (long long)(__1i1 && __1i2);
        case 65:
            return (__1i1 | __1i2);
        case 67:
            return (long long)(__1i1 || __1i2);
        case 64:
            return (__1i1 ^ __1i2);
        case 53:
            if (__1i2 == 0) {
                if (Neval == 0) {
                    Neval = (const char *)"mod zero";

                    error__FPCc((const char *)"mod zero");
                }
                return (long long)1;
            }
            return (__1i1 % __1i2);
        case 68:
            return (eval__4exprFv(__0this->__O4__4expr.cond) ? __1i1 : __1i2);
        case 51:
            if (__1i2 == 0) {
                if (Neval == 0) {
                    Neval = (const char *)"divide by zero";

                    error__FPCc((const char *)"divide by zero");
                }
                return (long long)1;
            }
            return (__1i1 / __1i2);
        case 71:
        case 147:
            return __1i2;
        }

        error__FiPCc((int)'i', (const char *)"fall off end of expr::eval()");
        return (long long)0;
    }
}

Pclass is_base__8classdefFPCcPUci(struct classdef *__0this, const char *, TOK *, int __1level);

bit baseof__8classdefFP8classdef(register struct classdef *__0this, Pclass __1cl) {
    struct classdef *__1__X83;

    struct classdef *__1__X84;

    if (__1cl == 0)
        return (unsigned char)0;
    if (((__1__X83 = __1cl),
         ((__1__X84 = __0this),
          (((__1__X83 == __1__X84)
                ? 1
                : ((__1__X83 && __1__X84)
                       ? (((int)same_class__8classdefFP8classdefi(__1__X83, __1__X84, 0)))
                       : 0))))))
        return (unsigned char)1;
    ppbase = 25;
    {
        Pclass __1bcl;

        __1bcl = is_base__8classdefFPCcPUci(__0this, __1cl->string__8classdef, (TOK *)0, 0);
        return (unsigned char)(__1bcl && (ppbase == 25));
    }
}

static int mem_match__FP3fctT1(Pfct __1f1, Pfct __1f2) {
    struct classdef *__1__X85;

    struct classdef *__1__X86;

    if ((__1f1 == 0) || (__1f2 == 0))
        return 0;
    if ((__1f1->memof__3fct && __1f2->f_this__3fct) &&
        (!((__1__X85 = __1f2->memof__3fct),
           ((__1__X86 = __1f1->memof__3fct),
            (((__1__X85 == __1__X86)
                  ? 1
                  : ((__1__X85 && __1__X86)
                         ? (((int)same_class__8classdefFP8classdefi(__1__X85, __1__X86, 0)))
                         : 0)))))))
        return 0;
    if (__1f2->f_this__3fct)
        return 0;
    if (__1f1->memof__3fct && __1f2->f_static__3fct)
        return 0;
    if (check__4typeFP4typeUcT2((struct type *)__1f1, (struct type *)__1f2, (unsigned char)70,
                                (unsigned char)0))
        return 0;

    return 1;
}

int Pchecked = 0;

static Pexpr return_elist__FP4name(Pname __1args) {
    Pexpr __1head;

    Pexpr __1tail;

    __1head = 0;

    __1tail = 0;

    {
        {
            Pname __1n;

            __1n = __1args;

            for (; __1n; __1n = __1n->__O1__4name.n_list) {
                Pexpr __2e;

                __2e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                              (struct expr *)__1n, (struct expr *)0);
                if (__1head == 0)
                    __1head = __2e;
                if (__1tail)
                    __1tail->__O3__4expr.e2 = __2e;
                __1tail = __2e;
            }

            return __1head;
        }
    }
}

Pexpr ptof__FP3fctP4exprP5table(Pfct __1ef, Pexpr __1e, Ptable __1tbl);

Pname find__3genFP3fctUc(struct gen *__0this, Pfct, bit);

extern Pname has_templ_instance__FP4nameP4exprUc(Pname, Pexpr, bit);

Pexpr typ__4exprFP5table(struct expr *__0this, Ptable);

Pexpr ptof__FP3fctP4exprP5table(Pfct __1ef, Pexpr __1e, Ptable __1tbl) {
    Pfct __1f;
    Pname __1n;

    __1n = 0;
eee:
    switch (__1e->base__4node) {
    case 68:
        __1e->__O2__4expr.e1 = ptof__FP3fctP4exprP5table(__1ef, __1e->__O2__4expr.e1, __1tbl);
        __1e->__O3__4expr.e2 = ptof__FP3fctP4exprP5table(__1ef, __1e->__O3__4expr.e2, __1tbl);
        return __1e;
    case 71:
    case 147:
        __1e->__O3__4expr.e2 = ptof__FP3fctP4exprP5table(__1ef, __1e->__O3__4expr.e2, __1tbl);
        if (__1e->__O1__4expr.tp && (__1e->__O1__4expr.tp->base__4node == 108))
            __1e->__O1__4expr.tp = __1e->__O3__4expr.e2->__O1__4expr.tp;
        return __1e;
    case 85:
        __1f = (((struct fct *)(((struct fct *)__1e->__O1__4expr.tp))));
        __1n = (((struct name *)(((struct name *)__1e))));

        switch (__1f->base__4node) {
        case 76:
            __1e = (struct expr *)find__3genFP3fctUc(((struct gen *)(((struct gen *)__1f))), __1ef,
                                                     (unsigned char)0);

            if ((__1e == 0) && (__1n->n_template_fct__4name)) {
                Pexpr __4arg;

                __4arg = return_elist__FP4name(__1ef->argtype__3fct);
                __1e = (struct expr *)has_templ_instance__FP4nameP4exprUc(__1n, __4arg,
                                                                          (unsigned char)0);
            }

            if (__1e == 0) {
                {
                    struct ea __0__V87;

                    error__FPCcRC2eaN32(
                        (const char *)"cannot deduceT for &overloaded%n",
                        (const struct ea *)(((&__0__V87)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V87)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    return __1e;
                }
            }

        case 108:
            if ((__1f->base__4node == 108) && (__1f->fct_base__3fct == 1)) {
                Pexpr __4arg;

                __4arg = return_elist__FP4name(__1ef->argtype__3fct);
                __1e = (struct expr *)has_templ_instance__FP4nameP4exprUc(__1n, __4arg,
                                                                          (unsigned char)0);
                if (__1e == 0)
                    return __1e;
            }

            Pchecked =
                mem_match__FP3fctT1(__1ef, ((struct fct *)(((struct fct *)__1e->__O1__4expr.tp))));
            __1e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145, (struct expr *)0,
                                          __1e);
            return typ__4exprFP5table(__1e, __1tbl);
        }
        goto ad;

    case 86:
        if (__1ef->memof__3fct) {
            __1e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, zero, zero);

            __1e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)124, __1e, zero);
            __1e->__O1__4expr.tp = (struct type *)zero_type;
            return __1e;
        }
        break;

    case 177:
        do
            __1e = __1e->__O4__4expr.mem;
        while (__1e->base__4node == 177);

        goto eee;

    case 45:
    case 44:
        __1f = (((struct fct *)(((struct fct *)__1e->__O4__4expr.mem->__O1__4expr.tp))));

        switch (__1f->base__4node) {
            const void *__2__X90;

        case 76:
            __1n =
                find__3genFP3fctUc(((struct gen *)(((struct gen *)__1f))), __1ef, (unsigned char)0);
            if (__1n == 0) {
                struct ea __0__V88;

                error__FPCcRC2eaN32(
                    (const char *)"cannot deduceT for &overloaded%n",
                    (const struct ea *)((__2__X90 = (const void *)__1e->__O4__4expr.mem),
                                        (((&__0__V88)->__O1__2ea.p = __2__X90), (&__0__V88))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else
                __1e = (struct expr *)__1n;

        case 108:
            Pchecked =
                mem_match__FP3fctT1(__1ef, ((struct fct *)(((struct fct *)__1e->__O1__4expr.tp))));
            __1e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145, (struct expr *)0,
                                          __1e);
            return typ__4exprFP5table(__1e, __1tbl);
        }
        goto ad;

    case 112:
    case 145:
        __1f = (((struct fct *)(((struct fct *)__1e->__O3__4expr.e2->__O1__4expr.tp))));
        __1n = (((struct name *)(((struct name *)__1e->__O3__4expr.e2))));

    ad:
        if (__1f->base__4node == 76) {
            Pname __3nn;

            __3nn =
                find__3genFP3fctUc(((struct gen *)(((struct gen *)__1f))), __1ef, (unsigned char)0);

            if ((__3nn == 0) && (__1n->n_template_fct__4name)) {
                Pexpr __4arg;

                __4arg = return_elist__FP4name(__1ef->argtype__3fct);
                __3nn = has_templ_instance__FP4nameP4exprUc(__1n, __4arg, (unsigned char)0);
            }

            if (__3nn == 0) {
                const void *__2__X91;

                {
                    struct ea __0__V89;

                    error__FPCcRC2eaN32(
                        (const char *)"cannot deduceT for &overloaded %s()",
                        (const struct ea
                             *)((__2__X91 =
                                     (const void *)(((struct gen *)(((struct gen *)__1f))))
                                         ->fct_list__3gen->f__9name_list->__O2__4expr.string),
                                (((&__0__V89)->__O1__2ea.p = __2__X91), (&__0__V89))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    return (struct expr *)__3nn;
                }
            }

            __1n = __3nn;
            {
                Pfct __3nf;

                unsigned long __2__X16;

                struct ea __0__X__V1400qm5qkxojwcnm;

                struct ea __0__X__V1500qm5qkxojwcnm;

                __3nf =
                    (((__1n->__O1__4expr.tp->base__4node == 108)
                          ? (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))))
                          : (error__FiPCcRC2eaN33(
                                 (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                 (const struct ea *)(((&__0__X__V1400qm5qkxojwcnm)->__O1__2ea.p =
                                                          ((const void *)__1n)),
                                                     (&__0__X__V1400qm5qkxojwcnm)),
                                 (const struct ea *)((__2__X16 = __1n->__O1__4expr.tp->base__4node),
                                                     (((((&__0__X__V1500qm5qkxojwcnm)->__O1__2ea.i =
                                                             __2__X16),
                                                        0)),
                                                      (&__0__X__V1500qm5qkxojwcnm))),
                                 (const struct ea *)ea0, (const struct ea *)ea0),
                             (((struct fct *)0)))));
                Pchecked = mem_match__FP3fctT1(__1ef, __3nf);
                if (__3nf->f_static__3fct)
                    __3nf->memof__3fct = 0;
                __1e->__O3__4expr.e2 = (struct expr *)__1n;
                __1e->__O1__4expr.tp = __1n->__O1__4expr.tp;
            }
        }

        if ((__1f->base__4node == 108) && (__1f->fct_base__3fct == 1)) {
            Pexpr __3arg;
            Pname __3nn;

            unsigned long __2__X16;

            struct ea __0__X__V1400qm5qkxojwcnm;

            struct ea __0__X__V1500qm5qkxojwcnm;

            __3arg = return_elist__FP4name(__1ef->argtype__3fct);
            __3nn = has_templ_instance__FP4nameP4exprUc(__1n, __3arg, (unsigned char)0);
            if (__3nn == 0)
                return (struct expr *)__3nn;
            __1n = __3nn;
            Pchecked = mem_match__FP3fctT1(
                __1ef,
                (((__1n->__O1__4expr.tp->base__4node == 108)
                      ? (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))))
                      : (error__FiPCcRC2eaN33(
                             (int)'i', (const char *)"N::fct_type():%n is %k notF",
                             (const struct ea *)(((&__0__X__V1400qm5qkxojwcnm)->__O1__2ea.p =
                                                      ((const void *)__1n)),
                                                 (&__0__X__V1400qm5qkxojwcnm)),
                             (const struct ea
                                  *)((__2__X16 = __1n->__O1__4expr.tp->base__4node),
                                     (((((&__0__X__V1500qm5qkxojwcnm)->__O1__2ea.i = __2__X16), 0)),
                                      (&__0__X__V1500qm5qkxojwcnm))),
                             (const struct ea *)ea0, (const struct ea *)ea0),
                         (((struct fct *)0))))));
            __1e->__O3__4expr.e2 = (struct expr *)__1n;
            __1e->__O1__4expr.tp = __1n->__O1__4expr.tp;
        }
        if (__1n)
            lval__4exprFUc((struct expr *)__1n, (unsigned char)112);
        break;

    case 113:
    case 191: {
        Pexpr __3te;

        __3te = __1e->__O2__4expr.e1;
        if (__1e->__O2__4expr.e1->base__4node == 145)
            __3te = __1e->__O2__4expr.e1->__O3__4expr.e2;
        ((void)ptof__FP3fctP4exprP5table(__1ef, __3te, __1tbl));
    }
    }
    return __1e;
}

void del__4exprFv(struct expr *__0this);

extern Pname make_tmp__FcP4typeP5table(char, Ptype, Ptable);

extern Pexpr mptr_assign__FP4exprT1(Pexpr, Pexpr);

void clear__5clistFv(struct clist *__0this);

extern int is_unique_base__FP8classdefPCciT3T1(Pclass, const char *, int, int, Pclass __0priSeen);

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);

extern Pexpr try_to_coerce__FP4typeP4exprPCcP5table(Ptype, Pexpr, const char *, Ptable);

extern Pexpr cast_cptr__FP8classdefP4exprP5tablei(Pclass __0ccl, Pexpr __0ee, Ptable __0tbl,
                                                  int __0real_cast);

Pexpr ptr_init__FP3ptrP4exprP5table(Pptr __1p, Pexpr __1init, Ptable __1tbl) {
    Pchecked = 0;

    {
        Ptype __1it;

        __1it = skiptypedefs__4typeFv(__1init->__O1__4expr.tp);

        switch (__1it->base__4node) {
        case 138:
            break;
        case 121:
        case 21:
        case 5:
        case 29:
        case 22:
        case 122: {
            Neval = 0;
            {
                long long __3i;

                const void *__2__X106;

                __3i = eval__4exprFv(__1init);
                if (Neval) {
                    struct ea __0__V92;

                    error__FPCcRC2eaN32(
                        (const char *)"badPIr: %s",
                        (const struct ea *)((__2__X106 = (const void *)Neval),
                                            (((&__0__V92)->__O1__2ea.p = __2__X106), (&__0__V92))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                } else if (__3i) {
                    struct ea __0__V93;

                    error__FPCcRC2eaN32(
                        (const char *)"badPIr value %d",
                        (const struct ea *)(((((&__0__V93)->__O1__2ea.i = ((unsigned long)__3i)),
                                              0)),
                                            (&__0__V93)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                } else {
                    if (__1init && (__1init->permanent__4node == 0))
                        del__4exprFv(__1init);
                    __1init = zero;
                }
                break;
            }
        }
        }

        {
            Pclass __1c1;

            __1c1 = __1p->memof__3ptr;

            if (__1c1) {
                if (__1init == zero)
                    ;
                else {
                    Pclass __3c2;

                    struct classdef *__1__X107;

                    struct classdef *__1__X108;

                    switch (__1it->base__4node) {
                    case 108:
                        __3c2 = (((struct fct *)(((struct fct *)__1it))))->memof__3fct;
                        break;
                    case 76:
                        __3c2 = (((struct fct *)((
                                     (struct fct *)(((struct gen *)(((struct gen *)__1it))))
                                         ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))
                                    ->memof__3fct;
                        break;
                    case 125:
                    case 158:
                        __3c2 = (((struct ptr *)(((struct ptr *)__1it))))->memof__3ptr;
                        break;
                    default:
                        __3c2 = 0;
                        if (__1init->base__4node == 68) {
                            Pname __5temp;

                            __5temp =
                                make_tmp__FcP4typeP5table('A', (struct type *)mptr_type, __1tbl);

                            __1init->__O2__4expr.e1 = mptr_assign__FP4exprT1(
                                (struct expr *)__5temp, __1init->__O2__4expr.e1);
                            __1init->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                                (struct expr *)0, (unsigned char)147, __1init->__O2__4expr.e1,
                                (struct expr *)__5temp);
                            __1init->__O2__4expr.e1->__O1__4expr.tp = __5temp->__O1__4expr.tp;

                            __1init->__O3__4expr.e2 = mptr_assign__FP4exprT1(
                                (struct expr *)__5temp, __1init->__O3__4expr.e2);
                            __1init->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                                (struct expr *)0, (unsigned char)147, __1init->__O3__4expr.e2,
                                (struct expr *)__5temp);
                            __1init->__O1__4expr.tp = (struct type *)__1p;
                        }
                    }

                    if ((__3c2 != 0) && (!((__1__X107 = __1c1),
                                           ((__1__X108 = __3c2),
                                            (((__1__X107 == __1__X108)
                                                  ? 1
                                                  : ((__1__X107 && __1__X108)
                                                         ? (((int)same_class__8classdefFP8classdefi(
                                                               __1__X107, __1__X108, 0)))
                                                         : 0))))))) {
                        Nptr = 0;
                        Noffset = 0;
                        clear__5clistFv(vcllist);
                        vcllist = 0;
                        {
                            int __4u1;

                            __4u1 = is_unique_base__FP8classdefPCciT3T1(
                                __1c1, __3c2->string__8classdef, 0, 0, (struct classdef *)0);

                            if (__4u1 && (Nptr || Noffset)) {
                                int __5bad;

                                const void *__2__X111;

                                __5bad = 0;
                                if ((__4u1 == 1) && (!Nptr)) {
                                    if (__1init->base__4node == 124) {
                                        switch (
                                            __1init->__O2__4expr.e1->__O2__4expr.e1->base__4node) {

                                            struct ival *__0__X109;

                                            long long __2__X110;

                                        case 150:
                                            __1init->__O2__4expr.e1->__O2__4expr.e1->__O2__4expr
                                                .i1 += Noffset;
                                            break;
                                        case 86:
                                            __1init->__O2__4expr.e1->__O2__4expr.e1 =
                                                (struct expr
                                                     *)((__0__X109 = 0),
                                                        ((__2__X110 = Noffset),
                                                         (((__0__X109 ||
                                                            (__0__X109 =
                                                                 (struct ival *)__nw__4exprSFUl((
                                                                     size_t)(sizeof(struct ival)))))
                                                               ? ((__0__X109 = (struct ival *)
                                                                       __ct__4exprFUcP4exprT2(
                                                                           ((struct expr *)
                                                                                __0__X109),
                                                                           (unsigned char)150,
                                                                           (struct expr *)0,
                                                                           (struct expr *)0)),
                                                                  (__0__X109->__O2__4expr.i1 =
                                                                       __2__X110))
                                                               : 0),
                                                          __0__X109)));

                                            break;
                                        default:
                                            __5bad = 1;
                                        }

                                        switch (
                                            __1init->__O2__4expr.e1->__O3__4expr.e2->base__4node) {
                                        case 150:
                                            if (0 < __1init->__O2__4expr.e1->__O3__4expr.e2
                                                        ->__O2__4expr.i1) {
                                            } else
                                                break;
                                        default:
                                            __5bad = 1;
                                        }
                                    } else
                                        __5bad = 1;
                                } else
                                    __5bad = 1;

                                if (__5bad) {
                                    struct ea __0__V94;

                                    struct ea __0__V95;

                                    error__FiPCcRC2eaN33(
                                        (int)'s',
                                        (const char *)"%t assigned to%t (too complicated)",
                                        (const struct ea *)((__2__X111 = (const void *)__1init
                                                                             ->__O1__4expr.tp),
                                                            (((&__0__V94)->__O1__2ea.p = __2__X111),
                                                             (&__0__V94))),
                                        (const struct ea *)(((&__0__V95)->__O1__2ea.p =
                                                                 ((const void *)__1p)),
                                                            (&__0__V95)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                }
                            }

                            Nptr = 0;
                            Noffset = 0;
                            clear__5clistFv(vcllist);
                            vcllist = 0;
                            {
                                int __4u2;

                                __4u2 = is_unique_base__FP8classdefPCciT3T1(
                                    __3c2, __1c1->string__8classdef, 0, 0, (struct classdef *)0);

                                if (__4u2 && (Nptr || Noffset)) {
                                    const void *__2__X112;

                                    {
                                        struct ea __0__V96;

                                        struct ea __0__V97;

                                        error__FiPCcRC2eaN33(
                                            (int)'s', (const char *)"%t assigned to%t",
                                            (const struct ea *)((__2__X112 = (const void *)__1init
                                                                                 ->__O1__4expr.tp),
                                                                (((&__0__V96)->__O1__2ea.p =
                                                                      __2__X112),
                                                                 (&__0__V96))),
                                            (const struct ea *)(((&__0__V97)->__O1__2ea.p =
                                                                     ((const void *)__1p)),
                                                                (&__0__V97)),
                                            (const struct ea *)ea0, (const struct ea *)ea0);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            {
                Ptype __1pit;

                __1pit = skiptypedefs__4typeFv(__1p->typ__5pvtyp);

                switch (__1pit->base__4node) {
                case 108:
                    return ptof__FP3fctP4exprP5table(((struct fct *)(((struct fct *)__1pit))),
                                                     __1init, __1tbl);
                case 119: {
                    Pptr __3r;
                    Pexpr __3x;
                    Pname __3old_Ncoerce;

                    __3r = is_ptr_or_ref__4typeFv(__1it);
                    __3x = 0;
                    __3old_Ncoerce = Ncoerce;
                    Ncoerce = 0;
                    if (__3r == 0) {
                        suppress_error++;
                        __3x = try_to_coerce__FP4typeP4exprPCcP5table(
                            (struct type *)__1p, __1init, (const char *)"initializer", __1tbl);
                        ;
                        suppress_error--;
                    }

                    if ((__3r != 0) || ((__3x && Ncoerce) &&
                                        (__3r = is_ptr_or_ref__4typeFv(__3x->__O1__4expr.tp)))) {
                        if (__3x && Ncoerce)
                            __1init = __3x;

                        Pchecked = 1;
                        {
                            TOK __4b;
                            TOK __4bb;

                            __4b = __1p->base__4node;
                            __4bb = __3r->base__4node;
                            if (__4b == 158)
                                __1p->base__4node = 125;
                            if (__4bb == 158)
                                __3r->base__4node = 125;
                            if (check__4typeFP4typeUcT2((struct type *)__1p, (struct type *)__3r,
                                                        (unsigned char)70, (unsigned char)0)) {
                                const void *__2__X113;

                                if (((cc && cc->nof__11dcl_context) &&
                                     (((struct fct *)((
                                          (struct fct *)cc->nof__11dcl_context->__O1__4expr.tp))))
                                         ->f_const__3fct) &&
                                    ((((struct expr *)cc->c_this__11dcl_context)) == __1init)) {

                                    struct ea __0__V98;

                                    struct ea __0__V99;

                                    struct ea __0__V100;

                                    struct ea __0__V101;

                                    error__FPCcRC2eaN32(
                                        (const char *)"%n const: assignment of%n (%t) to%t",
                                        (const struct ea *)((__2__X113 = (const void *)cc
                                                                             ->nof__11dcl_context),
                                                            (((&__0__V98)->__O1__2ea.p = __2__X113),
                                                             (&__0__V98))),
                                        (const struct ea *)(((&__0__V99)->__O1__2ea.p =
                                                                 ((const void *)__1init)),
                                                            (&__0__V99)),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V100, (const void *)__1init->__O1__4expr.tp),
                                        (const struct ea *)(((&__0__V101)->__O1__2ea.p =
                                                                 ((const void *)__1p)),
                                                            (&__0__V101)));
                                } else {
                                    const void *__2__X114;

                                    const void *__2__X115;

                                    __1p->base__4node = __4b;
                                    if (__1init->base__4node == 145) {
                                        struct ea __0__V102;

                                        struct ea __0__V103;

                                        error__FPCcRC2eaN32(
                                            (const char *)"no standard conversion of%t to%t",
                                            (const struct ea
                                                 *)((__2__X114 = (const void *)__1init->__O3__4expr
                                                                     .e2->__O1__4expr.tp),
                                                    (((&__0__V102)->__O1__2ea.p = __2__X114),
                                                     (&__0__V102))),
                                            (const struct ea *)(((&__0__V103)->__O1__2ea.p =
                                                                     ((const void *)__1p)),
                                                                (&__0__V103)),
                                            (const struct ea *)ea0, (const struct ea *)ea0);
                                    } else {
                                        struct ea __0__V104;

                                        struct ea __0__V105;

                                        error__FPCcRC2eaN32(
                                            (const char *)"no standard conversion of%t to%t",
                                            (const struct ea *)((__2__X115 = (const void *)__1init
                                                                                 ->__O1__4expr.tp),
                                                                (((&__0__V104)->__O1__2ea.p =
                                                                      __2__X115),
                                                                 (&__0__V104))),
                                            (const struct ea *)(((&__0__V105)->__O1__2ea.p =
                                                                     ((const void *)__1p)),
                                                                (&__0__V105)),
                                            (const struct ea *)ea0, (const struct ea *)ea0);
                                    }
                                }
                            }
                            __1p->base__4node = __4b;
                            __3r->base__4node = __4bb;
                            {
                                Pexpr __4cp;

                                __4cp = cast_cptr__FP8classdefP4exprP5tablei(
                                    ((struct classdef *)((
                                        (struct classdef *)(((struct basetype *)((
                                                                (struct basetype *)__1pit))))
                                            ->b_name__8basetype->__O1__4expr.tp))),
                                    __1init, __1tbl, 0);
                                if (__4cp != __1init) {
                                    register struct cast *__0__X116;

                                    __1p->permanent__4node = 1;
                                    Ncoerce = __3old_Ncoerce;
                                    return (
                                        struct expr
                                            *)((__0__X116 = 0),
                                               (((__0__X116 ||
                                                  (__0__X116 = (struct cast *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct cast)))))
                                                     ? ((__0__X116 =
                                                             (struct cast *)__ct__4exprFUcP4exprT2(
                                                                 ((struct expr *)__0__X116),
                                                                 (unsigned char)191, __4cp,
                                                                 (struct expr *)0)),
                                                        (__0__X116->__O1__4expr.tp =
                                                             (__0__X116->__O4__4expr.tp2 =
                                                                  ((struct type *)__1p))))
                                                     : 0),
                                                __0__X116));
                                }
                            }
                        }
                    }
                    Ncoerce = __3old_Ncoerce;
                }
                default:
                    return __1init;
                }
            }
        }
    }
}

static Pname Lcoerce;

static Pname Rcoerce;

Pname is_cl_obj__4typeFv(struct type *__0this);

struct Bits *__ct__4BitsFUlT1(struct Bits *__0this, Bits_chunk, size_t);

extern void __co__FRC4Bits(struct Bits *__0_result, const struct Bits *);

extern void best_conv__FRC11Block_PnameRiUc(struct Bits *__0_result, const struct Block_Pname *,
                                            int *, bit);

size_t count__4BitsCFv(const struct Bits *const __0this);

extern Ptype np_promote__FUcN21P4typeT4N21(TOK, TOK, TOK, Ptype, Ptype, TOK, bit);

extern int oper_okay__FP4typeUc(Ptype, TOK);

int try_to_demote__FUcP4typeT2(TOK __1oper, Ptype __1t1, Ptype __1t2) {
    Pname __1n1;
    Pclass __1c1;
    Pname __1n2;
    Pclass __1c2;

    Ptype __1lt;
    Ptype __1rt;
    int __1not_const1;

    int __1not_const2;

    int __0_result;

    __1n1 = (__1t1 ? is_cl_obj__4typeFv(__1t1) : (((struct name *)0)));
    __1c1 = (__1n1 ? (((struct classdef *)(((struct classdef *)__1n1->__O1__4expr.tp))))
                   : (((struct classdef *)0)));
    __1n2 = (__1t2 ? is_cl_obj__4typeFv(__1t2) : (((struct name *)0)));
    __1c2 = (__1n2 ? (((struct classdef *)(((struct classdef *)__1n2->__O1__4expr.tp))))
                   : (((struct classdef *)0)));

    __1lt = __1t1;
    __1rt = __1t2;

    Lcoerce = (Rcoerce = 0);

    {
        struct Block_Pname __1rconv;
        struct Block_Pname __1lconv;
        int __1rfound;
        int __1lfound;

        (((((&__1rconv)->n__11Block_Pname = 0), ((&__1rconv)->p__11Block_Pname = 0))), (&__1rconv));

        (((((&__1lconv)->n__11Block_Pname = 0), ((&__1lconv)->p__11Block_Pname = 0))), (&__1lconv));

        __1rfound = 0;
        __1lfound = 0;

        if (__1c1)
            switch (__1oper) {
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
                if (look__5tableFPCcUc(__1c1->memtbl__8classdef, (const char *)"__as",
                                       (unsigned char)0)) {
                    {
                        __0_result = 0;

                        ((((void)(__dl__FPv((void *)(&__1lconv)->p__11Block_Pname),
                                  (((void)(((void)0))))))));

                        ((((void)(__dl__FPv((void *)(&__1rconv)->p__11Block_Pname),
                                  (((void)(((void)0))))))));
                    }
                    return __0_result;
                }
            }
        else
            switch (__1oper) {
            case 112:
            case 48:
            case 49: {
                {
                    __0_result = 0;

                    ((((void)(__dl__FPv((void *)(&__1lconv)->p__11Block_Pname),
                              (((void)(((void)0))))))));

                    ((((void)(__dl__FPv((void *)(&__1rconv)->p__11Block_Pname),
                              (((void)(((void)0))))))));
                }
                return __0_result;
            }
            }

        if (__1c1) {
            __1not_const1 = 0;

            {
                {
                    Pname __2on1;

                    __2on1 = __1c1->conv__8classdef;

                    for (; __2on1; __2on1 = __2on1->__O1__4name.n_list) {
                        Pfct __3f;

                        __3f =
                            (((__2on1->__O1__4expr.tp->base__4node == 108)
                                  ? (((struct fct *)(((struct fct *)__2on1->__O1__4expr.tp))))
                                  : (((struct fct *)((
                                        (struct fct *)(((struct gen *)((
                                                           (struct gen *)__2on1->__O1__4expr.tp))))
                                            ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))));
                        __1lt = __3f->returns__3fct;
                        if (is_cl_obj__4typeFv(__1lt))
                            continue;
                        {
                            Pptr __3rn;

                            int __2__X124;

                            __3rn = is_ref__4typeFv(__1lt);
                            if (__3rn && is_cl_obj__4typeFv(__3rn->typ__5pvtyp))
                                continue;

                            if (((skiptypedefs__4typeFv(__1lt)->base__4node == 121) &&
                                 (__1oper >= 126)) &&
                                (__1oper <= 135))
                                continue;
                            if (tconst__4typeFv(__1t1) && (!__3f->f_const__3fct)) {
                                __1not_const1 = 1;
                                continue;
                            }
                            (((((unsigned long)(__1lfound + 1)) < (&__1lconv)->n__11Block_Pname) ||
                              grow__11Block_PnameFUl((&__1lconv),
                                                     ((unsigned long)(__1lfound + 1)))));
                            ((*((__2__X124 = (__1lfound++)),
                                ((((Pname *)(&((&__1lconv)->p__11Block_Pname[__2__X124])))))))) =
                                __2on1;
                        }
                    }

                    if (__1lfound == 0) {
                        {
                            __0_result = (__1not_const1 ? -1 : 0);

                            ((((void)(__dl__FPv((void *)(&__1lconv)->p__11Block_Pname),
                                      (((void)(((void)0))))))));

                            ((((void)(__dl__FPv((void *)(&__1rconv)->p__11Block_Pname),
                                      (((void)(((void)0))))))));
                        }
                        return __0_result;
                    }
                    {
                        struct Bits __2b;

                        struct Block_Bits_chunk *__0__X36;

                        const struct Bits *__1__X125;

                        register struct Block_Bits_chunk *__0__X119;

                        const struct Block_Bits_chunk *__2__X120;

                        const struct Bits *__1__X126;

                        __ct__4BitsFUlT1(&__2b, (unsigned long)0, (unsigned long)__1lfound);
                        if (__1lfound == 1) {
                            {
                                struct Bits __0__R117;

                                ((__1__X125 =
                                      (const struct Bits *)(__co__FRC4Bits(
                                                                &__0__R117,
                                                                (const struct Bits *)(&__2b)),
                                                            (&__0__R117))),
                                 (((((*((__0__X119 = (&(&__2b)->b__4Bits)),
                                        ((__2__X120 = (const struct Block_Bits_chunk
                                                           *)(&((*__1__X125)).b__4Bits)),
                                         (__dl__FPv((void *)__0__X119->p__16Block_Bits_chunk),
                                          (copy__16Block_Bits_chunkFRC16Block_Bits_chunk(__0__X119,
                                                                                         __2__X120),
                                           (((struct Block_Bits_chunk *)__0__X119)))))))),
                                    ((&__2b)->n__4Bits = ((*__1__X125)).n__4Bits)),
                                   ((*(&__2b)))),
                                  (((struct Bits *)(&__2b)))));

                                ((((void)((
                                    (void)(((__0__X36 = (&(&__0__R117)->b__4Bits)),
                                            ((__0__X36
                                                  ? (((void)(__dl__FPv((void *)__0__X36
                                                                           ->p__16Block_Bits_chunk),
                                                             (__0__X36 ? (((void)(((void)0))))
                                                                       : (((void)0))))))
                                                  : (((void)0))))),
                                           (((void)0))))))));
                            }
                        } else {
                            {
                                struct Bits __0__R121;

                                ((__1__X126 =
                                      (const struct Bits
                                           *)(best_conv__FRC11Block_PnameRiUc(
                                                  &__0__R121,
                                                  (const struct Block_Pname *)(&__1lconv),
                                                  (int *)(&__1lfound), (unsigned char)const_obj1),
                                              (&__0__R121))),
                                 (((((*((__0__X119 = (&(&__2b)->b__4Bits)),
                                        ((__2__X120 = (const struct Block_Bits_chunk
                                                           *)(&((*__1__X126)).b__4Bits)),
                                         (__dl__FPv((void *)__0__X119->p__16Block_Bits_chunk),
                                          (copy__16Block_Bits_chunkFRC16Block_Bits_chunk(__0__X119,
                                                                                         __2__X120),
                                           (((struct Block_Bits_chunk *)__0__X119)))))))),
                                    ((&__2b)->n__4Bits = ((*__1__X126)).n__4Bits)),
                                   ((*(&__2b)))),
                                  (((struct Bits *)(&__2b)))));

                                ((((void)((
                                    (void)(((__0__X36 = (&(&__0__R121)->b__4Bits)),
                                            ((__0__X36
                                                  ? (((void)(__dl__FPv((void *)__0__X36
                                                                           ->p__16Block_Bits_chunk),
                                                             (__0__X36 ? (((void)(((void)0))))
                                                                       : (((void)0))))))
                                                  : (((void)0))))),
                                           (((void)0))))))));
                            }
                        }
                        while (count__4BitsCFv((const struct Bits *)(&__2b))) {
                            int __3i;

                            struct Block_Bits_chunk *__0__X32;

                            int __2__X33;

                            __3i = (signif__4BitsCFv((const struct Bits *)(&__2b)) - 1);
                            (((((unsigned long)__3i) < (&__2b)->n__4Bits)
                                  ? (((*((__0__X32 = (&(&__2b)->b__4Bits)),
                                         ((__2__X33 = ((((unsigned long)__3i) >> 5))),
                                          ((((Bits_chunk *)(&(
                                              __0__X32->p__16Block_Bits_chunk[__2__X33]))))))))) &=
                                     (~((((unsigned long)1)) << (((unsigned long)__3i) & 31))))
                                  : 0),
                             (((struct Bits *)(&__2b))));
                            {
                                Pfct __3f;

                                register struct name *__0__X129;

                                __3f =
                                    ((__0__X129 = ((*(
                                          (((Pname *)(&((&__1lconv)->p__11Block_Pname[__3i])))))))),
                                     (((__0__X129->__O1__4expr.tp->base__4node == 108)
                                           ? (((struct fct *)((
                                                 (struct fct *)__0__X129->__O1__4expr.tp))))
                                           : (((struct fct *)((
                                                 (struct fct *)(((struct gen *)((
                                                                    (struct gen *)__0__X129
                                                                        ->__O1__4expr.tp))))
                                                     ->fct_list__3gen->f__9name_list->__O1__4expr
                                                     .tp)))))));
                                __1lt = __3f->returns__3fct;
                                {
                                    Pptr __3rr;

                                    __3rr = is_ref__4typeFv(__1lt);
                                    if (__3rr)
                                        __1lt = __3rr->typ__5pvtyp;
                                    if (__1lt->base__4node == 76)
                                        __1lt = (((struct gen *)(((struct gen *)__1lt))))
                                                    ->fct_list__3gen->f__9name_list->__O1__4expr.tp;
                                    {
                                        int __3r1;

                                        __3r1 = kind__4typeFUcN21(__1lt, __1oper, (unsigned char)0,
                                                                  (unsigned char)0);

                                        if (__1c2) {
                                            __1not_const2 = 0;
                                            __1rfound = 0;
                                            {
                                                {
                                                    Pname __4on2;

                                                    __4on2 = __1c2->conv__8classdef;

                                                    for (; __4on2;
                                                         __4on2 = __4on2->__O1__4name.n_list) {
                                                        Pfct __5f;

                                                        __5f = ((
                                                            (__4on2->__O1__4expr.tp->base__4node ==
                                                             108)
                                                                ? (((struct fct *)((
                                                                      (struct fct *)
                                                                          __4on2->__O1__4expr.tp))))
                                                                : (((struct fct *)((
                                                                      (struct fct
                                                                           *)(((struct gen *)((
                                                                                  (struct gen
                                                                                       *)__4on2
                                                                                      ->__O1__4expr
                                                                                      .tp))))
                                                                          ->fct_list__3gen
                                                                          ->f__9name_list
                                                                          ->__O1__4expr.tp))))));
                                                        __1rt = __5f->returns__3fct;
                                                        {
                                                            Pptr __5rn;

                                                            __5rn = is_ref__4typeFv(__1rt);
                                                            if (__5rn)
                                                                __1rt = __5rn->typ__5pvtyp;
                                                            if (is_cl_obj__4typeFv(__1rt))
                                                                continue;
                                                            if (__1rt->base__4node == 76)
                                                                __1rt = (((struct gen *)((
                                                                             (struct gen *)__1rt))))
                                                                            ->fct_list__3gen
                                                                            ->f__9name_list
                                                                            ->__O1__4expr.tp;
                                                            {
                                                                int __5r2;

                                                                __5r2 = kind__4typeFUcN21(
                                                                    __1rt, __1oper,
                                                                    (unsigned char)0,
                                                                    (unsigned char)0);
                                                                if (np_promote__FUcN21P4typeT4N21(
                                                                        __1oper,
                                                                        (unsigned char)__3r1,
                                                                        (unsigned char)__5r2, __1lt,
                                                                        __1rt, (unsigned char)1,
                                                                        (unsigned char)0) !=
                                                                    (((struct type *)any_type))) {
                                                                    int __2__X127;

                                                                    if (tconst__4typeFv(__1t2) &&
                                                                        (!__5f->f_const__3fct)) {
                                                                        __1not_const2 = 1;
                                                                        continue;
                                                                    }
                                                                    (((((unsigned long)(__1rfound +
                                                                                        1)) <
                                                                       (&__1rconv)
                                                                           ->n__11Block_Pname) ||
                                                                      grow__11Block_PnameFUl(
                                                                          (&__1rconv),
                                                                          ((unsigned long)(__1rfound +
                                                                                           1)))));
                                                                    ((*((__2__X127 = (__1rfound++)),
                                                                        ((((Pname *)(&(
                                                                            (&__1rconv)->p__11Block_Pname
                                                                                [__2__X127])))))))) =
                                                                        __4on2;
                                                                }
                                                            }
                                                        }
                                                    }

                                                    if (__1rfound == 0) {
                                                        continue;
                                                    }
                                                    if (__1rfound == 1) {
                                                        if (Lcoerce) {
                                                            {
                                                                ((((void)(((
                                                                    void)(((__0__X36 =
                                                                                (&(&__2b)
                                                                                      ->b__4Bits)),
                                                                           ((__0__X36
                                                                                 ? (((void)(__dl__FPv(
                                                                                                (void
                                                                                                     *)__0__X36
                                                                                                    ->p__16Block_Bits_chunk),
                                                                                            (__0__X36
                                                                                                 ? (((void)(((
                                                                                                       void)0))))
                                                                                                 : (((void)0))))))
                                                                                 : (((void)0))))),
                                                                          (((void)0))))))));

                                                                ((((void)(__dl__FPv(
                                                                              (void *)(&__1lconv)
                                                                                  ->p__11Block_Pname),
                                                                          (((void)(((void)0))))))));

                                                                ((((void)(__dl__FPv(
                                                                              (void *)(&__1rconv)
                                                                                  ->p__11Block_Pname),
                                                                          (((void)(((void)0))))))));
                                                            }
                                                            return 2;
                                                        }
                                                        Lcoerce = ((*((((Pname *)(&(
                                                            (&__1lconv)
                                                                ->p__11Block_Pname[__3i])))))));

                                                        Rcoerce = ((*((((Pname *)(&(
                                                            (&__1rconv)->p__11Block_Pname[0])))))));
                                                        continue;
                                                    }
                                                    {
                                                        struct Bits __4b2;

                                                        struct Block_Bits_chunk *__0__X36;

                                                        best_conv__FRC11Block_PnameRiUc(
                                                            &__4b2,
                                                            (const struct Block_Pname *)(&__1rconv),
                                                            (int *)(&__1rfound),
                                                            (unsigned char)const_obj2);

                                                        if (__1rfound == 1) {
                                                            int __2__X128;

                                                            if (Lcoerce) {
                                                                {
                                                                    ((((void)(((
                                                                        void)(((__0__X36 =
                                                                                    (&(&__4b2)
                                                                                          ->b__4Bits)),
                                                                               ((__0__X36
                                                                                     ? (((void)(__dl__FPv(
                                                                                                    (void
                                                                                                         *)__0__X36
                                                                                                        ->p__16Block_Bits_chunk),
                                                                                                (__0__X36
                                                                                                     ? (((void)(((
                                                                                                           void)0))))
                                                                                                     : (((void)0))))))
                                                                                     : (((void)0))))),
                                                                              (((void)0))))))));

                                                                    {
                                                                        ((((void)(((
                                                                            void)(((__0__X36 =
                                                                                        (&(&__2b)
                                                                                              ->b__4Bits)),
                                                                                   ((__0__X36
                                                                                         ? (((void)(__dl__FPv(
                                                                                                        (void
                                                                                                             *)__0__X36
                                                                                                            ->p__16Block_Bits_chunk),
                                                                                                    (__0__X36
                                                                                                         ? (((void)(((
                                                                                                               void)0))))
                                                                                                         : (((void)0))))))
                                                                                         : (((void)0))))),
                                                                                  (((void)0))))))));

                                                                        ((((void)(__dl__FPv(
                                                                                      (void
                                                                                           *)(&__1lconv)
                                                                                          ->p__11Block_Pname),
                                                                                  (((void)(((
                                                                                      void)0))))))));

                                                                        ((((void)(__dl__FPv(
                                                                                      (void
                                                                                           *)(&__1rconv)
                                                                                          ->p__11Block_Pname),
                                                                                  (((void)(((
                                                                                      void)0))))))));
                                                                    }
                                                                }
                                                                return 2;
                                                            }
                                                            Lcoerce = ((*((((Pname *)(&(
                                                                (&__1lconv)
                                                                    ->p__11Block_Pname[__3i])))))));
                                                            Rcoerce = ((*(
                                                                (__2__X128 = (signif__4BitsCFv(
                                                                                  (const struct Bits
                                                                                       *)(&__4b2)) -
                                                                              1)),
                                                                ((((Pname *)(&(
                                                                    (&__1rconv)->p__11Block_Pname
                                                                        [__2__X128]))))))));
                                                        } else {
                                                            if (__1lfound > 1) {
                                                                {
                                                                    ((((void)(((
                                                                        void)(((__0__X36 =
                                                                                    (&(&__4b2)
                                                                                          ->b__4Bits)),
                                                                               ((__0__X36
                                                                                     ? (((void)(__dl__FPv(
                                                                                                    (void
                                                                                                         *)__0__X36
                                                                                                        ->p__16Block_Bits_chunk),
                                                                                                (__0__X36
                                                                                                     ? (((void)(((
                                                                                                           void)0))))
                                                                                                     : (((void)0))))))
                                                                                     : (((void)0))))),
                                                                              (((void)0))))))));

                                                                    {
                                                                        ((((void)(((
                                                                            void)(((__0__X36 =
                                                                                        (&(&__2b)
                                                                                              ->b__4Bits)),
                                                                                   ((__0__X36
                                                                                         ? (((void)(__dl__FPv(
                                                                                                        (void
                                                                                                             *)__0__X36
                                                                                                            ->p__16Block_Bits_chunk),
                                                                                                    (__0__X36
                                                                                                         ? (((void)(((
                                                                                                               void)0))))
                                                                                                         : (((void)0))))))
                                                                                         : (((void)0))))),
                                                                                  (((void)0))))))));

                                                                        ((((void)(__dl__FPv(
                                                                                      (void
                                                                                           *)(&__1lconv)
                                                                                          ->p__11Block_Pname),
                                                                                  (((void)(((
                                                                                      void)0))))))));

                                                                        ((((void)(__dl__FPv(
                                                                                      (void
                                                                                           *)(&__1rconv)
                                                                                          ->p__11Block_Pname),
                                                                                  (((void)(((
                                                                                      void)0))))))));
                                                                    }
                                                                }
                                                                return 4;
                                                            }
                                                            {
                                                                {
                                                                    ((((void)(((
                                                                        void)(((__0__X36 =
                                                                                    (&(&__4b2)
                                                                                          ->b__4Bits)),
                                                                               ((__0__X36
                                                                                     ? (((void)(__dl__FPv(
                                                                                                    (void
                                                                                                         *)__0__X36
                                                                                                        ->p__16Block_Bits_chunk),
                                                                                                (__0__X36
                                                                                                     ? (((void)(((
                                                                                                           void)0))))
                                                                                                     : (((void)0))))))
                                                                                     : (((void)0))))),
                                                                              (((void)0))))))));

                                                                    {
                                                                        ((((void)(((
                                                                            void)(((__0__X36 =
                                                                                        (&(&__2b)
                                                                                              ->b__4Bits)),
                                                                                   ((__0__X36
                                                                                         ? (((void)(__dl__FPv(
                                                                                                        (void
                                                                                                             *)__0__X36
                                                                                                            ->p__16Block_Bits_chunk),
                                                                                                    (__0__X36
                                                                                                         ? (((void)(((
                                                                                                               void)0))))
                                                                                                         : (((void)0))))))
                                                                                         : (((void)0))))),
                                                                                  (((void)0))))))));

                                                                        ((((void)(__dl__FPv(
                                                                                      (void
                                                                                           *)(&__1lconv)
                                                                                          ->p__11Block_Pname),
                                                                                  (((void)(((
                                                                                      void)0))))))));

                                                                        ((((void)(__dl__FPv(
                                                                                      (void
                                                                                           *)(&__1rconv)
                                                                                          ->p__11Block_Pname),
                                                                                  (((void)(((
                                                                                      void)0))))))));
                                                                    }
                                                                }
                                                                return 3;
                                                            }
                                                        }

                                                        ((((void)(((
                                                            void)(((__0__X36 =
                                                                        (&(&__4b2)->b__4Bits)),
                                                                   ((__0__X36
                                                                         ? (((void)(__dl__FPv(
                                                                                        (void
                                                                                             *)__0__X36
                                                                                            ->p__16Block_Bits_chunk),
                                                                                    (__0__X36
                                                                                         ? (((void)(((
                                                                                               void)0))))
                                                                                         : (((void)0))))))
                                                                         : (((void)0))))),
                                                                  (((void)0))))))));
                                                    }
                                                }
                                            }
                                        } else if (__1rt) {
                                            if (__1rt->base__4node == 76)
                                                __1rt = (((struct gen *)(((struct gen *)__1rt))))
                                                            ->fct_list__3gen->f__9name_list
                                                            ->__O1__4expr.tp;
                                            {
                                                int __4r2;

                                                __4r2 = kind__4typeFUcN21(__1rt, __1oper,
                                                                          (unsigned char)0,
                                                                          (unsigned char)0);
                                                if (np_promote__FUcN21P4typeT4N21(
                                                        __1oper, (unsigned char)__3r1,
                                                        (unsigned char)__4r2, __1lt, __1rt,
                                                        (unsigned char)1, (unsigned char)0) !=
                                                    (((struct type *)any_type))) {
                                                    if (Lcoerce) {
                                                        {
                                                            ((((void)(((
                                                                void)(((__0__X36 =
                                                                            (&(&__2b)->b__4Bits)),
                                                                       ((__0__X36
                                                                             ? (((void)(__dl__FPv(
                                                                                            (void
                                                                                                 *)__0__X36
                                                                                                ->p__16Block_Bits_chunk),
                                                                                        (__0__X36
                                                                                             ? (((void)(((
                                                                                                   void)0))))
                                                                                             : (((void)0))))))
                                                                             : (((void)0))))),
                                                                      (((void)0))))))));

                                                            ((((void)(__dl__FPv(
                                                                          (void *)(&__1lconv)
                                                                              ->p__11Block_Pname),
                                                                      (((void)(((void)0))))))));

                                                            ((((void)(__dl__FPv(
                                                                          (void *)(&__1rconv)
                                                                              ->p__11Block_Pname),
                                                                      (((void)(((void)0))))))));
                                                        }
                                                        return 2;
                                                    }
                                                    Lcoerce = ((*((((Pname *)(&(
                                                        (&__1lconv)->p__11Block_Pname[__3i])))))));
                                                    if (count__4BitsCFv(
                                                            (const struct Bits *)(&__2b)) == 0) {
                                                        {
                                                            ((((void)(((
                                                                void)(((__0__X36 =
                                                                            (&(&__2b)->b__4Bits)),
                                                                       ((__0__X36
                                                                             ? (((void)(__dl__FPv(
                                                                                            (void
                                                                                                 *)__0__X36
                                                                                                ->p__16Block_Bits_chunk),
                                                                                        (__0__X36
                                                                                             ? (((void)(((
                                                                                                   void)0))))
                                                                                             : (((void)0))))))
                                                                             : (((void)0))))),
                                                                      (((void)0))))))));

                                                            ((((void)(__dl__FPv(
                                                                          (void *)(&__1lconv)
                                                                              ->p__11Block_Pname),
                                                                      (((void)(((void)0))))))));

                                                            ((((void)(__dl__FPv(
                                                                          (void *)(&__1rconv)
                                                                              ->p__11Block_Pname),
                                                                      (((void)(((void)0))))))));
                                                        }
                                                        return 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            struct type *__1__Xt00an55jxojwcog;

                                            if ((__1oper == 50) && (__3r1 != 'P'))
                                                continue;
                                            if ((__1oper == 109) &&
                                                (!((__1__Xt00an55jxojwcog =
                                                        skiptypedefs__4typeFv(__1lt)),
                                                   (((__1__Xt00an55jxojwcog->base__4node == 125)
                                                         ? ((__1__Xt00an55jxojwcog =
                                                                 skiptypedefs__4typeFv(
                                                                     (((struct ptr *)((
                                                                          (struct ptr *)
                                                                              __1__Xt00an55jxojwcog))))
                                                                         ->typ__5pvtyp)),
                                                            0)
                                                         : 0),
                                                    (((unsigned char)((__1__Xt00an55jxojwcog
                                                                           ->base__4node ==
                                                                       ((unsigned char)108))
                                                                          ? 1
                                                                          : 0)))))))
                                                continue;
                                            if ((skiptypedefs__4typeFv(__1lt)->base__4node ==
                                                 121) &&
                                                ((__1oper == 48) || (__1oper == 49)))
                                                continue;

                                            if (Lcoerce) {
                                                {
                                                    ((((void)(((
                                                        void)(((__0__X36 = (&(&__2b)->b__4Bits)),
                                                               ((__0__X36
                                                                     ? (((void)(__dl__FPv(
                                                                                    (void *)__0__X36
                                                                                        ->p__16Block_Bits_chunk),
                                                                                (__0__X36
                                                                                     ? (((void)(((
                                                                                           void)0))))
                                                                                     : (((void)0))))))
                                                                     : (((void)0))))),
                                                              (((void)0))))))));

                                                    ((((void)(__dl__FPv((void *)(&__1lconv)
                                                                            ->p__11Block_Pname),
                                                              (((void)(((void)0))))))));

                                                    ((((void)(__dl__FPv((void *)(&__1rconv)
                                                                            ->p__11Block_Pname),
                                                              (((void)(((void)0))))))));
                                                }
                                                return 2;
                                            }
                                            Lcoerce = ((*((((Pname *)(&(
                                                (&__1lconv)->p__11Block_Pname[__3i])))))));
                                            if (count__4BitsCFv((const struct Bits *)(&__2b)) ==
                                                0) {
                                                {
                                                    ((((void)(((
                                                        void)(((__0__X36 = (&(&__2b)->b__4Bits)),
                                                               ((__0__X36
                                                                     ? (((void)(__dl__FPv(
                                                                                    (void *)__0__X36
                                                                                        ->p__16Block_Bits_chunk),
                                                                                (__0__X36
                                                                                     ? (((void)(((
                                                                                           void)0))))
                                                                                     : (((void)0))))))
                                                                     : (((void)0))))),
                                                              (((void)0))))))));

                                                    ((((void)(__dl__FPv((void *)(&__1lconv)
                                                                            ->p__11Block_Pname),
                                                              (((void)(((void)0))))))));

                                                    ((((void)(__dl__FPv((void *)(&__1rconv)
                                                                            ->p__11Block_Pname),
                                                              (((void)(((void)0))))))));
                                                }
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        {
                            {
                                ((((void)((
                                    (void)(((__0__X36 = (&(&__2b)->b__4Bits)),
                                            ((__0__X36
                                                  ? (((void)(__dl__FPv((void *)__0__X36
                                                                           ->p__16Block_Bits_chunk),
                                                             (__0__X36 ? (((void)(((void)0))))
                                                                       : (((void)0))))))
                                                  : (((void)0))))),
                                           (((void)0))))))));

                                ((((void)(__dl__FPv((void *)(&__1lconv)->p__11Block_Pname),
                                          (((void)(((void)0))))))));

                                ((((void)(__dl__FPv((void *)(&__1rconv)->p__11Block_Pname),
                                          (((void)(((void)0))))))));
                            }
                            return (Lcoerce || Rcoerce);
                        }
                    }
                }
            }
        }

        __1not_const2 = 0;
        {
            {
                Pname __1on;

                __1on = __1c2->conv__8classdef;

                for (; __1on; __1on = __1on->__O1__4name.n_list) {
                    Pfct __2f;

                    __2f = (((__1on->__O1__4expr.tp->base__4node == 108)
                                 ? (((struct fct *)(((struct fct *)__1on->__O1__4expr.tp))))
                                 : (((struct fct *)((
                                       (struct fct *)(((struct gen *)((
                                                          (struct gen *)__1on->__O1__4expr.tp))))
                                           ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))));
                    __1rt = __2f->returns__3fct;
                    {
                        Pptr __2rn;

                        __2rn = is_ref__4typeFv(__1rt);
                        if (__2rn)
                            __1rt = __2rn->typ__5pvtyp;
                        if (is_cl_obj__4typeFv(__1rt))
                            continue;
                        if (tconst__4typeFv(__1t2) && (!__2f->f_const__3fct)) {
                            __1not_const2 = 1;
                            continue;
                        }
                        if (__1rt->base__4node == 76)
                            __1rt = (((struct gen *)(((struct gen *)__1rt))))
                                        ->fct_list__3gen->f__9name_list->__O1__4expr.tp;
                        {
                            int __2r2;

                            __2r2 = kind__4typeFUcN21(__1rt, __1oper, (unsigned char)0,
                                                      (unsigned char)0);

                            if (__1lt) {
                                if (__1lt->base__4node == 76)
                                    __1lt = (((struct gen *)(((struct gen *)__1lt))))
                                                ->fct_list__3gen->f__9name_list->__O1__4expr.tp;
                                {
                                    int __3r1;

                                    __3r1 = kind__4typeFUcN21(__1lt, __1oper, (unsigned char)0,
                                                              (unsigned char)0);

                                    if (np_promote__FUcN21P4typeT4N21(
                                            __1oper, (unsigned char)__3r1, (unsigned char)__2r2,
                                            __1lt, __1rt, (unsigned char)1,
                                            (unsigned char)0) != (((struct type *)any_type))) {
                                        int __2__X130;

                                        (((((unsigned long)(__1rfound + 1)) <
                                           (&__1rconv)->n__11Block_Pname) ||
                                          grow__11Block_PnameFUl(
                                              (&__1rconv), ((unsigned long)(__1rfound + 1)))));
                                        ((*((__2__X130 = (__1rfound++)),
                                            ((((Pname *)(&(
                                                (&__1rconv)->p__11Block_Pname[__2__X130])))))))) =
                                            __1on;
                                    }
                                }
                            } else {
                                if (oper_okay__FP4typeUc(__1rt, __1oper)) {
                                    int __2__X131;

                                    (((((unsigned long)(__1rfound + 1)) <
                                       (&__1rconv)->n__11Block_Pname) ||
                                      grow__11Block_PnameFUl((&__1rconv),
                                                             ((unsigned long)(__1rfound + 1)))));
                                    ((*((__2__X131 = (__1rfound++)),
                                        ((((Pname *)(&(
                                            (&__1rconv)->p__11Block_Pname[__2__X131])))))))) =
                                        __1on;
                                }
                            }
                        }
                    }
                }
                if ((__1rfound == 0) && __1not_const2) {
                    ((((void)(__dl__FPv((void *)(&__1lconv)->p__11Block_Pname),
                              (((void)(((void)0))))))));

                    ((((void)(__dl__FPv((void *)(&__1rconv)->p__11Block_Pname),
                              (((void)(((void)0))))))));
                    return -2;
                }
                if (__1rfound == 1)
                    Rcoerce = ((*((((Pname *)(&((&__1rconv)->p__11Block_Pname[0])))))));
                if (__1rfound > 1) {
                    struct Bits __2b;

                    struct Block_Bits_chunk *__0__X36;

                    int __2__X132;

                    best_conv__FRC11Block_PnameRiUc(&__2b, (const struct Block_Pname *)(&__1rconv),
                                                    (int *)(&__1rfound), (unsigned char)const_obj2);

                    Rcoerce =
                        ((*((__2__X132 = (signif__4BitsCFv((const struct Bits *)(&__2b)) - 1)),
                            ((((Pname *)(&((&__1rconv)->p__11Block_Pname[__2__X132]))))))));

                    ((((void)((
                        (void)(((__0__X36 = (&(&__2b)->b__4Bits)),
                                ((__0__X36
                                      ? (((void)(__dl__FPv((void *)__0__X36->p__16Block_Bits_chunk),
                                                 (__0__X36 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                               (((void)0))))))));
                }
                if (__1rfound > 1) {
                    ((((void)(__dl__FPv((void *)(&__1lconv)->p__11Block_Pname),
                              (((void)(((void)0))))))));

                    ((((void)(__dl__FPv((void *)(&__1rconv)->p__11Block_Pname),
                              (((void)(((void)0))))))));
                    return 3;
                }
                {
                    ((((void)(__dl__FPv((void *)(&__1lconv)->p__11Block_Pname),
                              (((void)(((void)0))))))));

                    ((((void)(__dl__FPv((void *)(&__1rconv)->p__11Block_Pname),
                              (((void)(((void)0))))))));
                    return (Lcoerce || Rcoerce);
                }
            }
        }
    }
}

static void opov_error__FP4typeT1Uc(Ptype __1t1, Ptype __1t2, TOK __1op) {
    if (__1t1 && __1t2) {
        {
            struct ea __0__V133;

            struct ea __0__V134;

            struct ea __0__V135;

            struct ea __0__V136;

            error__FiPCcRC2eaN33(
                (int)'e', (const char *)"ambiguous call of operator%k:%t%k%t",
                (const struct ea *)(((((&__0__V133)->__O1__2ea.i = ((unsigned long)__1op)), 0)),
                                    (&__0__V133)),
                (const struct ea *)(((&__0__V134)->__O1__2ea.p = ((const void *)__1t1)),
                                    (&__0__V134)),
                (const struct ea *)(((((&__0__V135)->__O1__2ea.i = ((unsigned long)__1op)), 0)),
                                    (&__0__V135)),
                (const struct ea *)(((&__0__V136)->__O1__2ea.p = ((const void *)__1t2)),
                                    (&__0__V136)));
        }
    } else {
        Ptype __2tmp;

        __2tmp = (__1t1 ? __1t1 : __1t2);
        {
            struct ea __0__V137;

            struct ea __0__V138;

            struct ea __0__V139;

            error__FiPCcRC2eaN33(
                (int)'e', (const char *)"ambiguous call of operator%k:%k%t",
                (const struct ea *)(((((&__0__V137)->__O1__2ea.i = ((unsigned long)__1op)), 0)),
                                    (&__0__V137)),
                (const struct ea *)(((((&__0__V138)->__O1__2ea.i = ((unsigned long)__1op)), 0)),
                                    (&__0__V138)),
                (const struct ea *)(((&__0__V139)->__O1__2ea.p = ((const void *)__2tmp)),
                                    (&__0__V139)),
                (const struct ea *)ea0);
        }
    }
    {
        struct ea __0__V140;

        error__FiPCcRC2eaN33(
            (int)'c', (const char *)" (conflicts with built-in operator%k)\n",
            (const struct ea *)(((((&__0__V140)->__O1__2ea.i = ((unsigned long)__1op)), 0)),
                                (&__0__V140)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
}

int non_const = 0;

extern bit can_coerce__FP4typeT1(Ptype, Ptype);

static int id_match__FP4exprP3fctP8classdefi(Pexpr __1th, Pfct __1f, Pclass __1cl, int __1anac) {
    Pname __1n;
    int __1ok;

    __1n = __1f->argtype__3fct;
    __1ok = 0;

    if (((!__1anac) && __1th->__O2__4expr.e1) &&
        (((__1cl && __1n) && (!__1n->__O1__4name.n_list)) ||
         (((!__1cl) && __1n) && __1n->__O1__4name.n_list)))
        __1ok = 1;

    if ((__1anac && __1th->__O2__4expr.e1) &&
        ((__1cl && (!__1n)) || (((!__1cl) && __1n) && (!__1n->__O1__4name.n_list))))
        __1ok = 1;

    if (__1th->__O3__4expr.e2 &&
        ((__1cl && (!__1n)) || (((!__1cl) && __1n) && (!__1n->__O1__4name.n_list))))
        __1ok = 1;

    if (__1ok && (!__1cl)) {
        Ptype __2t;
        if (__1th->__O2__4expr.e1)
            __2t = __1th->__O2__4expr.e1->__O1__4expr.tp;
        else if ((__1th->__O3__4expr.e2->base__4node == 140) &&
                 (!__1th->__O3__4expr.e2->__O1__4expr.tp))
            __2t = __1th->__O3__4expr.e2->__O2__4expr.e1->__O1__4expr.tp;
        else
            __2t = __1th->__O3__4expr.e2->__O1__4expr.tp;
        __1ok = can_coerce__FP4typeT1(__1n->__O1__4expr.tp, __2t);
    }

    return __1ok;
}

extern const char *oper_name__FUc(TOK);

Pexpr find_name__8classdefFPCcP8classdefiT3(struct classdef *__0this, const char *, Pclass, int,
                                            int);

static Pexpr id_overload__FP4exprP8classdefi(Pexpr __1th, Pclass __1cl, int __1anac) {
    const char *__1on;
    Pexpr __1e;

    __1on = oper_name__FUc(__1th->base__4node);

    if (__1cl)
        __1e = find_name__8classdefFPCcP8classdefiT3(__1cl, __1on, (struct classdef *)0, 0, 0);
    else
        __1e = (struct expr *)look__5tableFPCcUc(gtbl, __1on, (unsigned char)0);

    if ((!__1e) || (!__1e->__O1__4expr.tp))
        return (struct expr *)0;

    if (__1e->__O1__4expr.tp->base__4node == 108) {
        if (id_match__FP4exprP3fctP8classdefi(
                __1th, ((struct fct *)(((struct fct *)__1e->__O1__4expr.tp))), __1cl, __1anac))
            return __1e;
    } else {
        {
            {
                Plist __2gl;

                __2gl = (((struct gen *)(((struct gen *)__1e->__O1__4expr.tp))))->fct_list__3gen;

                for (; __2gl; __2gl = __2gl->l__9name_list)
                    if (id_match__FP4exprP3fctP8classdefi(
                            __1th,
                            ((struct fct *)(((struct fct *)__2gl->f__9name_list->__O1__4expr.tp))),
                            __1cl, __1anac))
                        return (struct expr *)__2gl->f__9name_list;
            }
        }
    }

    return (struct expr *)0;
}

bit is_const_obj__4exprFv(struct expr *__0this);

extern int matchable__FP4nameP4expri(Pname, Pexpr, int);

Pname multArgMatch__3genFP4expri(struct gen *__0this, Pexpr, int);

Pname oneArgMatch__3genFP4expri(struct gen *__0this, Pexpr, int);

bit has_base__8classdefFP8classdefiT2(struct classdef *__0this, Pclass __1cl, int __1level,
                                      int __1ccflag);

extern int make_assignment__FP4name(Pname);

Pexpr oper_overload__4exprFP5table(struct expr *__0this, Ptable __1tbl);

Pname exactMatch__3genFP4expri(struct gen *__0this, Pexpr, int);

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

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

struct name_list *__ct__9name_listFP4nameP9name_list(struct name_list *__0this, Pname __1ff,
                                                     Plist __1ll);

void del__4typeFv(struct type *__0this);

static Pname compare_builtin__FP4typeT1P4nameN23i(Ptype, Ptype, Pname, Pname, Pname, int);

extern Pname bestOfPair__FP4nameT1P4type(Pname, Pname, Ptype);

extern void fmError__FiRC11Block_PnameP4exprUc(int, const struct Block_Pname *, Pexpr, bit);

extern Pexpr check_cond__FP4exprUcP5table(Pexpr, TOK, Ptable);

Pexpr oper_overload__4exprFP5table(register struct expr *__0this, Ptable __1tbl) {
    Pname __1n1;
    Ptype __1t1;

    __1n1 = 0;
    __1t1 = 0;
    const_obj1 = 0;
    const_obj2 = 0;
    {
        int __1const_obj;
        bit __1already_ambig;

        __1const_obj = 0;
        __1already_ambig = 0;

        if (__0this->__O2__4expr.e1) {
            __1t1 = __0this->__O2__4expr.e1->__O1__4expr.tp;
            {
                Ptype __2tpx;

                __2tpx = skiptypedefs__4typeFv(__1t1);
                __1n1 = is_cl_obj__4typeFv(__2tpx);
                const_obj1 =
                    (tconst__4typeFv(__1t1)
                         ? (((unsigned int)1))
                         : (((unsigned int)is_const_obj__4exprFv(__0this->__O2__4expr.e1))));
            }
        }

        {
            TOK __1bb;

            __1bb = __0this->base__4node;
            switch (__1bb) {
            case 111:
                if (__0this->__O3__4expr.e2 == 0)
                    __1bb = 50;

            case 109:
            case 146:
                if (__1n1 == 0)
                    return (struct expr *)0;
            }

            {
                Pname __1n2;
                Ptype __1t2;

                __1n2 = 0;
                __1t2 = 0;

                if (__0this->__O3__4expr.e2 && (__0this->__O3__4expr.e2->base__4node != 140)) {
                    __1t2 = __0this->__O3__4expr.e2->__O1__4expr.tp;
                    {
                        Ptype __2tpx;

                        __2tpx = skiptypedefs__4typeFv(__1t2);
                        __1n2 = is_cl_obj__4typeFv(__2tpx);
                        const_obj2 =
                            (tconst__4typeFv(__1t2) ? (((unsigned int)1))
                                                    : (((unsigned int)is_const_obj__4exprFv(
                                                          __0this->__O3__4expr.e2))));
                    }
                }

                if ((__1n1 == 0) && (__1n2 == 0))
                    return (struct expr *)0;
                if (__1n1 && (__1n1->__O1__4expr.tp == 0))
                    return (struct expr *)0;

                {
                    Pname __1Ggn;
                    Pexpr __1oe2;
                    Pexpr __1ee2;
                    Pexpr __1ee1;
                    const char *__1obb;

                    __1Ggn = 0;
                    __1oe2 = __0this->__O3__4expr.e2;
                    __1ee2 =
                        ((__0this->__O3__4expr.e2 && (__0this->__O3__4expr.e2->base__4node != 140))
                             ? (__0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                                    (struct expr *)0, (unsigned char)140, __0this->__O3__4expr.e2,
                                    (struct expr *)0))
                             : (((struct expr *)0)));
                    __1ee1 = (__0this->__O2__4expr.e1
                                  ? __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                           __0this->__O2__4expr.e1,
                                                           __0this->__O3__4expr.e2)
                                  : __1ee2);
                    __1obb = oper_name__FUc(__1bb);

                    if ((__1bb == 48) || (__1bb == 49)) {
                        Pclass __2cl;
                        const char *__2on;
                        bit __2ismem;
                        Pexpr __2e;
                        Pexpr __2ee;
                        bit __2anac;

                        __2cl = (((struct classdef *)(((
                            struct classdef *)(__0this->__O2__4expr.e1 ? __1n1->__O1__4expr.tp
                                                                       : __1n2->__O1__4expr.tp)))));
                        __2on = oper_name__FUc(__1bb);
                        __2ismem = 1;

                        __2anac = 0;

                        __2e = id_overload__FP4exprP8classdefi(__0this, __2cl, 0);
                        __2ee = id_overload__FP4exprP8classdefi(__0this, (struct classdef *)0, 0);

                        if (__2e && __2ee) {
                            struct ea __0__V141;

                            struct ea __0__V142;

                            struct ea __0__V143;

                            error__FPCcRC2eaN32(
                                (const char *)"ambiguous call of operator%k: %a and %a",
                                (const struct ea *)(((((&__0__V141)->__O1__2ea.i =
                                                           ((unsigned long)__1bb)),
                                                      0)),
                                                    (&__0__V141)),
                                (const struct ea *)(((&__0__V142)->__O1__2ea.p =
                                                         ((const void *)__2e)),
                                                    (&__0__V142)),
                                (const struct ea *)(((&__0__V143)->__O1__2ea.p =
                                                         ((const void *)__2ee)),
                                                    (&__0__V143)),
                                (const struct ea *)ea0);
                        }
                        if ((((!__2e) && (!__2ee)) && __0this->__O2__4expr.e1) && (!strict_opt)) {
                            __2e = id_overload__FP4exprP8classdefi(__0this, __2cl, 1);
                            __2ee =
                                id_overload__FP4exprP8classdefi(__0this, (struct classdef *)0, 1);
                            if (__2e || __2ee) {
                                error__FiPCc(
                                    (int)'w',
                                    (const char *)"prefix ++/-- used as postfix (anachronism)");

                                __2anac = 1;
                            }
                        }
                        if (!__2e)
                            ((__2ismem = 0), (__2e = __2ee));
                        if (!__2e) {
                            if (try_to_demote__FUcP4typeT2(__1bb, __1t1 ? __1t1 : __1t2,
                                                           (struct type *)0) == 1) {
                                Pname __4xx;
                                Pref __4r;

                                struct ref *__0__X159;

                                struct expr *__2__X160;

                                struct expr *__2__X161;

                                __4xx =
                                    __ct__4nameFPCc((struct name *)0, Lcoerce->__O2__4expr.string);
                                __4r =
                                    ((__0__X159 = 0),
                                     ((__2__X160 =
                                           (__0this->__O2__4expr.e1 ? __0this->__O2__4expr.e1
                                                                    : __1oe2)),
                                      ((__2__X161 = (struct expr *)__4xx),
                                       (((__0__X159 || (__0__X159 = (struct ref *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct ref)))))
                                             ? ((__0__X159 = (struct ref *)__ct__4exprFUcP4exprT2(
                                                     ((struct expr *)__0__X159),
                                                     ((unsigned char)45), __2__X160,
                                                     (struct expr *)0)),
                                                (__0__X159->__O4__4expr.mem = __2__X161))
                                             : 0),
                                        __0__X159))));
                                if (__0this->__O2__4expr.e1)
                                    __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)146, (struct expr *)__4r,
                                        (struct expr *)0);
                                else
                                    __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)146, (struct expr *)__4r,
                                        (struct expr *)0);

                                return typ__4exprFP5table(__0this, __1tbl);
                            } else {
                                {
                                    struct ea __0__V144;

                                    struct ea __0__V145;

                                    error__FPCcRC2eaN32(
                                        (const char *)"bad operand for%k:%t",
                                        (const struct ea *)(((((&__0__V144)->__O1__2ea.i =
                                                                   ((unsigned long)__1bb)),
                                                              0)),
                                                            (&__0__V144)),
                                        (const struct ea *)(((&__0__V145)->__O1__2ea.p =
                                                                 ((const void *)(__1t1 ? __1t1
                                                                                       : __1t2))),
                                                            (&__0__V145)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);

                                    return __0this;
                                }
                            }
                        }
                        __0this->base__4node = (__2ismem ? 109 : 146);
                        if (!__2ismem) {
                            Pexpr __3eee;

                            __3eee = 0;
                            if (__0this->__O2__4expr.e1 && (!__2anac))
                                __3eee = __ct__4exprFUcP4exprT2(
                                    (struct expr *)0, (unsigned char)140, zero, (struct expr *)0);
                            __3eee = __ct__4exprFUcP4exprT2(
                                (struct expr *)0, (unsigned char)140,
                                __0this->__O2__4expr.e1 ? __0this->__O2__4expr.e1 : __1oe2, __3eee);
                            __0this->__O2__4expr.e1 =
                                (struct expr *)__ct__4nameFPCc((struct name *)0, __2on);
                            (((struct name *)(((struct name *)__0this->__O2__4expr.e1))))
                                ->__O2__4name.n_qualifier = sta_name;
                            __0this->__O3__4expr.e2 = __3eee;
                        } else {
                            Pexpr __3eee;

                            struct ref *__0__X162;

                            struct expr *__2__X163;

                            struct expr *__2__X164;

                            __3eee = __0this->__O2__4expr.e1;
                            __0this->__O2__4expr.e1 =
                                (struct expr *)((__0__X162 = 0),
                                                ((__2__X163 = (__0this->__O2__4expr.e1
                                                                   ? __0this->__O2__4expr.e1
                                                                   : __1oe2)),
                                                 ((__2__X164 = (struct expr *)__ct__4nameFPCc(
                                                       (struct name *)0, __2on)),
                                                  (((__0__X162 ||
                                                     (__0__X162 = (struct ref *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct ref)))))
                                                        ? ((__0__X162 = (struct ref *)
                                                                __ct__4exprFUcP4exprT2(
                                                                    ((struct expr *)__0__X162),
                                                                    ((unsigned char)45), __2__X163,
                                                                    (struct expr *)0)),
                                                           (__0__X162->__O4__4expr.mem = __2__X164))
                                                        : 0),
                                                   __0__X162))));
                            __0this->__O3__4expr.e2 =
                                ((__3eee && (!__2anac))
                                     ? __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                              zero, (struct expr *)0)
                                     : (((struct expr *)0)));

                            ;
                        }
                        __2e = typ__4exprFP5table(__0this, __1tbl);
                        if (!__2e)
                            return __2e;

                        return __2e;
                    }

                    {
                        Pname __1gname;
                        int __1go;

                        __1gname = look__5tableFPCcUc(__1tbl, __1obb, (unsigned char)0);

                        if (!__1gname)
                            __1go = 0;
                        else if (__1gname->__O1__4expr.tp->base__4node == 108)
                            __1go = matchable__FP4nameP4expri(__1gname, __1ee1, 0);
                        else {
                            suppress_error++;
                            __1Ggn = __1gname;
                            {
                                Pgen __2g;

                                __2g = (((struct gen *)(((struct gen *)__1gname->__O1__4expr.tp))));

                                __1gname = (__1ee1->__O3__4expr.e2
                                                ? multArgMatch__3genFP4expri(__2g, __1ee1, 0)
                                                : oneArgMatch__3genFP4expri(__2g, __1ee1, 0));
                                if (ambig)
                                    __1already_ambig = 1;
                                __1go =
                                    (__1gname ? matchable__FP4nameP4expri(__1gname, __1ee1, 0) : 0);
                                suppress_error--;
                            }
                        }

                        non_const = 0;

                        if (__1n1) {
                            if (__1bb == 70) {
                                Pclass __3c1;

                                __3c1 = (((struct classdef *)((
                                    (struct classdef *)__1n1->__O1__4expr.tp))));
                                if (look__5tableFPCcUc(__3c1->memtbl__8classdef, __1obb,
                                                       (unsigned char)0) == 0) {
                                    Pclass __4bcl;

                                    struct classdef *__1__X165;

                                    struct classdef *__1__X166;

                                    __4bcl = (__3c1->baselist__8classdef
                                                  ? __3c1->baselist__8classdef->bclass__6basecl
                                                  : (((struct classdef *)0)));

                                    if ((__1n2 == 0) ||
                                        ((!((__1__X165 = (((struct classdef *)((
                                                 (struct classdef *)__1n2->__O1__4expr.tp))))),
                                            ((__1__X166 = __3c1),
                                             (((__1__X165 == __1__X166)
                                                   ? 1
                                                   : ((__1__X165 && __1__X166)
                                                          ? (((int)
                                                                  same_class__8classdefFP8classdefi(
                                                                      __1__X165, __1__X166, 0)))
                                                          : 0)))))) &&
                                         (has_base__8classdefFP8classdefiT2(
                                              ((struct classdef *)((
                                                  (struct classdef *)__1n2->__O1__4expr.tp))),
                                              __3c1, 0, 0) == 0))) {
                                        if (__3c1->c_xref__8classdef == 16)
                                            __3c1->c_xref__8classdef = 0;
                                        if (__1go > 3)
                                            goto glob;
                                        return (struct expr *)0;
                                    }

                                    if (((__4bcl && (__3c1->obj_size__8classdef !=
                                                     __4bcl->obj_size__8classdef)) &&
                                         look__5tableFPCcUc(__4bcl->memtbl__8classdef, __1obb,
                                                            (unsigned char)0)) ||
                                        (__3c1->c_xref__8classdef & 29)) {
                                        if (__1go > 3)
                                            goto glob;
                                        return (make_assignment__FP4name(__1n1)
                                                    ? oper_overload__4exprFP5table(__0this, __1tbl)
                                                    : (((struct expr *)0)));
                                    }
                                    return (struct expr *)0;
                                }
                            }

                            {
                                Pclass __2ccl;

                                __2ccl = (((struct classdef *)((
                                    (struct classdef *)__1n1->__O1__4expr.tp))));
                                if (strcmp(__1obb, (const char *)"__as")) {
                                    tcl = __2ccl;
                                }
                                {
                                    Pexpr __2mn;

                                    Pname __2mname;

                                    __2mn = find_name__8classdefFPCcP8classdefiT3(
                                        __2ccl, __1obb, (struct classdef *)0, 0, 0);

                                    __2mname = (((struct name *)(((struct name *)__2mn))));
                                    if (__2mname == 0)
                                        goto glob;

                                    while ((__2mname->base__4node == 44) ||
                                           (__2mname->base__4node == 177)) {
                                        __2mname = (((struct name *)((
                                            (struct name *)(((struct expr *)((
                                                                (struct expr *)__2mname))))
                                                ->__O4__4expr.mem))));
                                    }

                                    {
                                        int __2mo;

                                        __2mo = 0;
                                        if (const_obj1)
                                            __1const_obj = 1;
                                        if (__2mname->__O1__4expr.tp->base__4node == 108)
                                            __2mo = matchable__FP4nameP4expri(
                                                __2mname, __0this->__O3__4expr.e2, const_obj1);
                                        else if (__2mname->__O1__4expr.tp->base__4node == 76) {
                                            suppress_error++;
                                            {
                                                Pgen __3g;

                                                __3g = (((struct gen *)((
                                                    (struct gen *)__2mname->__O1__4expr.tp))));
                                                if (!__0this->__O3__4expr.e2) {
                                                    __2mname = exactMatch__3genFP4expri(
                                                        __3g, (struct expr *)0, const_obj1);
                                                } else if (__0this->__O3__4expr.e2->__O3__4expr
                                                               .e2) {
                                                    __2mname = multArgMatch__3genFP4expri(
                                                        __3g, __0this->__O3__4expr.e2, const_obj1);
                                                } else {
                                                    __2mname = oneArgMatch__3genFP4expri(
                                                        __3g, __0this->__O3__4expr.e2, const_obj1);
                                                }
                                                suppress_error--;
                                                if (ambig)
                                                    __1already_ambig += 2;
                                                __2mo = (__2mname ? matchable__FP4nameP4expri(
                                                                        __2mname,
                                                                        __0this->__O3__4expr.e2,
                                                                        const_obj1)
                                                                  : 0);
                                            }
                                        }

                                        if (__2mo == 0)
                                            goto glob;
                                        if (((__2mo != 5) ||
                                             (look__5tableFPCcUc(
                                                  (((struct classdef *)((
                                                       (struct classdef *)__1n1->__O1__4expr.tp))))
                                                      ->memtbl__8classdef,
                                                  __1obb, (unsigned char)0) == 0)) &&
                                            (__1go != 5)) {
                                            struct gen *__0__X167;

                                            if ((__1Ggn &&
                                                 ((__0__X167 = (((struct gen *)((
                                                       (struct gen *)__1Ggn->__O1__4expr.tp))))),
                                                  ((__0__X167->holds_templ__3gen != 0)))) ||
                                                (__1gname && (__1gname->n_template_fct__4name))) {
                                                Pname __4f_inst;

                                                __4f_inst = has_templ_instance__FP4nameP4exprUc(
                                                    __1Ggn ? __1Ggn : __1gname, __1ee1,
                                                    (unsigned char)1);
                                                if (__4f_inst) {
                                                    __1gname = __4f_inst;
                                                    __1go = 5;
                                                    goto glob;
                                                }
                                            }
                                        }

                                        if (__2mo && __1go) {
                                            Pfct __3mfct;
                                            Ptype __3mt1;

                                            unsigned long __2__X16;

                                            struct ea __0__X__V1400qm5qkxojwcnm;

                                            struct ea __0__X__V1500qm5qkxojwcnm;

                                            __3mfct = ((
                                                (__2mname->__O1__4expr.tp->base__4node == 108)
                                                    ? (((struct fct *)((
                                                          (struct fct *)__2mname->__O1__4expr.tp))))
                                                    : (error__FiPCcRC2eaN33(
                                                           (int)'i',
                                                           (const char
                                                                *)"N::fct_type():%n is %k notF",
                                                           (const struct ea
                                                                *)(((&__0__X__V1400qm5qkxojwcnm)
                                                                        ->__O1__2ea.p =
                                                                        ((const void *)__2mname)),
                                                                   (&__0__X__V1400qm5qkxojwcnm)),
                                                           (const struct ea
                                                                *)((__2__X16 =
                                                                        __2mname->__O1__4expr.tp
                                                                            ->base__4node),
                                                                   (((((&__0__X__V1500qm5qkxojwcnm)
                                                                           ->__O1__2ea.i =
                                                                           __2__X16),
                                                                      0)),
                                                                    (&__0__X__V1500qm5qkxojwcnm))),
                                                           (const struct ea *)ea0,
                                                           (const struct ea *)ea0),
                                                       (((struct fct *)0)))));
                                            __3mt1 = __3mfct->f_this__3fct->__O1__4expr.tp;
                                            __3mt1 = (((struct ptr *)(((struct ptr *)__3mt1))))
                                                         ->typ__5pvtyp;
                                            {
                                                Ptype __3mt2;
                                                Pname __3mm;

                                                __3mt2 = __3mfct->argtype__3fct->__O1__4expr.tp;
                                                __3mm = __ct__4nameFPCc(
                                                    (struct name *)0, __1gname->__O2__4expr.string);
                                                __3mm->n_oper__4name = __1gname->n_oper__4name;
                                                {
                                                    Pname __3a1;

                                                    __3a1 = __ct__4nameFPCc((struct name *)0,
                                                                            (const char *)0);
                                                    __3a1->__O1__4expr.tp = __3mt1;
                                                    {
                                                        Pname __3a2;

                                                        __3a2 = __ct__4nameFPCc((struct name *)0,
                                                                                (const char *)0);
                                                        __3a2->__O1__4expr.tp = __3mt2;
                                                        __3a1->__O1__4name.n_list = __3a2;
                                                        __3mm->__O1__4expr.tp = (struct type *)
                                                            __ct__3fctFP4typeP4nameUc(
                                                                (struct fct *)0,
                                                                __3mfct->returns__3fct, __3a1,
                                                                (unsigned char)2);

                                                        {
                                                            Pname __3aa;
                                                            Ptype __3savep;
                                                            Pptr __3p;

                                                            unsigned long __2__X16;

                                                            struct ea __0__X__V1400qm5qkxojwcnm;

                                                            struct ea __0__X__V1500qm5qkxojwcnm;

                                                            __3aa =
                                                                (((__1gname->__O1__4expr.tp
                                                                       ->base__4node == 108)
                                                                      ? (((struct fct *)((
                                                                            (struct fct *)__1gname
                                                                                ->__O1__4expr.tp))))
                                                                      : (error__FiPCcRC2eaN33(
                                                                             (int)'i',
                                                                             (const char
                                                                                  *)"N::fct_type():"
                                                                                    "%n is %k notF",
                                                                             (const struct
                                                                              ea *)(((&__0__X__V1400qm5qkxojwcnm)
                                                                                         ->__O1__2ea
                                                                                         .p =
                                                                                         ((const void
                                                                                               *)
                                                                                              __1gname)),
                                                                                    (&__0__X__V1400qm5qkxojwcnm)),
                                                                             (const struct
                                                                              ea *)((__2__X16 =
                                                                                         __1gname
                                                                                             ->__O1__4expr
                                                                                             .tp
                                                                                             ->base__4node),
                                                                                    (((((&__0__X__V1500qm5qkxojwcnm)
                                                                                            ->__O1__2ea
                                                                                            .i =
                                                                                            __2__X16),
                                                                                       0)),
                                                                                     (&__0__X__V1500qm5qkxojwcnm))),
                                                                             (const struct ea *)ea0,
                                                                             (const struct ea *)
                                                                                 ea0),
                                                                         (((struct fct *)0)))))
                                                                    ->argtype__3fct;
                                                            __3savep = 0;

                                                            if (__3p = is_ref__4typeFv(
                                                                    __3aa->__O1__4expr.tp)) {
                                                                __3savep = (struct type *)__3p;
                                                                __3aa->__O1__4expr.tp =
                                                                    __3p->typ__5pvtyp;
                                                            }

                                                            {
                                                                Pgen __3tgen;
                                                                struct name_list __3nl;

                                                                __3tgen =
                                                                    __ct__3genFv((struct gen *)0);
                                                                __ct__9name_listFP4nameP9name_list(
                                                                    &__3nl, __1gname,
                                                                    (struct name_list *)0);
                                                                __3tgen->fct_list__3gen =
                                                                    __ct__9name_listFP4nameP9name_list(
                                                                        (struct name_list *)0,
                                                                        __3mm, &__3nl);
                                                                {
                                                                    Pname __3found;

                                                                    __3found =
                                                                        multArgMatch__3genFP4expri(
                                                                            __3tgen, __1ee1, 0);
                                                                    if (ambig)
                                                                        __1already_ambig = 1;

                                                                    if (__3savep)
                                                                        __3aa->__O1__4expr.tp =
                                                                            (struct type *)__3p;
                                                                    ((__3a1
                                                                          ? (((void)(__3a1
                                                                                         ? (((void)((((((struct
                                                                                                         expr
                                                                                                             *)
                                                                                                            __3a1))
                                                                                                          ? (((void)((((struct
                                                                                                                        expr
                                                                                                                            *)
                                                                                                                           __3a1))
                                                                                                                         ? (((void)(((
                                                                                                                               void)0))))
                                                                                                                         : (((void)0)))))
                                                                                                          : (((void)0)))),
                                                                                                    (((void)__dl__4nameSFPvUl(
                                                                                                        (void
                                                                                                             *)
                                                                                                            __3a1,
                                                                                                        (size_t)(sizeof(
                                                                                                            struct
                                                                                                            name))))))))
                                                                                         : (((void)0)))))
                                                                          : (((void)0))));

                                                                    ((__3a2
                                                                          ? (((void)(__3a2
                                                                                         ? (((void)((((((struct
                                                                                                         expr
                                                                                                             *)
                                                                                                            __3a2))
                                                                                                          ? (((void)((((struct
                                                                                                                        expr
                                                                                                                            *)
                                                                                                                           __3a2))
                                                                                                                         ? (((void)(((
                                                                                                                               void)0))))
                                                                                                                         : (((void)0)))))
                                                                                                          : (((void)0)))),
                                                                                                    (((void)__dl__4nameSFPvUl(
                                                                                                        (void
                                                                                                             *)
                                                                                                            __3a2,
                                                                                                        (size_t)(sizeof(
                                                                                                            struct
                                                                                                            name))))))))
                                                                                         : (((void)0)))))
                                                                          : (((void)0))));
                                                                    if (__3mm->__O1__4expr.tp &&
                                                                        (__3mm->__O1__4expr.tp
                                                                             ->permanent__4node ==
                                                                         0))
                                                                        del__4typeFv(
                                                                            __3mm->__O1__4expr.tp);

                                                                    __dl__FPv((void *)__3tgen);
                                                                    if (__3found != __3mm) {
                                                                        ((__3mm
                                                                              ? (((void)(__3mm
                                                                                             ? (((void)((((((struct
                                                                                                             expr
                                                                                                                 *)
                                                                                                                __3mm))
                                                                                                              ? (((void)((((struct
                                                                                                                            expr
                                                                                                                                *)
                                                                                                                               __3mm))
                                                                                                                             ? (((void)(((
                                                                                                                                   void)0))))
                                                                                                                             : (((void)0)))))
                                                                                                              : (((void)0)))),
                                                                                                        (((void)__dl__4nameSFPvUl(
                                                                                                            (void
                                                                                                                 *)
                                                                                                                __3mm,
                                                                                                            (size_t)(sizeof(
                                                                                                                struct
                                                                                                                name))))))))
                                                                                             : (((void)0)))))
                                                                              : (((void)0))));
                                                                        if (__1already_ambig == 2)
                                                                            __1already_ambig = 0;
                                                                        goto glob;
                                                                    }

                                                                    if ((!ambig) &&
                                                                        (__1already_ambig == 1))
                                                                        __1already_ambig = 0;
                                                                    ((__3mm
                                                                          ? (((void)(__3mm
                                                                                         ? (((void)((((((struct
                                                                                                         expr
                                                                                                             *)
                                                                                                            __3mm))
                                                                                                          ? (((void)((((struct
                                                                                                                        expr
                                                                                                                            *)
                                                                                                                           __3mm))
                                                                                                                         ? (((void)(((
                                                                                                                               void)0))))
                                                                                                                         : (((void)0)))))
                                                                                                          : (((void)0)))),
                                                                                                    (((void)__dl__4nameSFPvUl(
                                                                                                        (void
                                                                                                             *)
                                                                                                            __3mm,
                                                                                                        (size_t)(sizeof(
                                                                                                            struct
                                                                                                            name))))))))
                                                                                         : (((void)0)))))
                                                                          : (((void)0))));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        if (((((__2mo == 5) &&
                                               look__5tableFPCcUc(
                                                   (((struct classdef *)((
                                                        (struct classdef *)__1n1->__O1__4expr.tp))))
                                                       ->memtbl__8classdef,
                                                   __1obb, (unsigned char)0)) ||
                                              (try_to_demote__FUcP4typeT2(__1bb, __1t1, __1t2) <=
                                               0)) ||
                                             (__1already_ambig > 0)) ||
                                            compare_builtin__FP4typeT1P4nameN23i(
                                                __1t1, __1t2, __1n1, __1n2, __2mname, __2mo)) {
                                            __0this->base__4node = 146;
                                            {
                                                Pname __3xx;

                                                struct ref *__0__X168;

                                                struct expr *__2__X169;

                                                struct expr *__2__X170;

                                                __3xx = __ct__4nameFPCc(
                                                    (struct name *)0, __2mname->__O2__4expr.string);

                                                __0this->__O2__4expr.e1 =
                                                    (struct expr
                                                         *)((__0__X168 = 0),
                                                            ((__2__X169 = __0this->__O2__4expr.e1),
                                                             ((__2__X170 = (struct expr *)__3xx),
                                                              (((__0__X168 ||
                                                                 (__0__X168 =
                                                                      (struct ref *)__nw__4exprSFUl(
                                                                          (size_t)(sizeof(
                                                                              struct ref)))))
                                                                    ? ((__0__X168 = (struct ref *)
                                                                            __ct__4exprFUcP4exprT2(
                                                                                ((struct expr *)
                                                                                     __0__X168),
                                                                                ((unsigned char)45),
                                                                                __2__X169,
                                                                                (struct expr *)0)),
                                                                       (__0__X168->__O4__4expr.mem =
                                                                            __2__X170))
                                                                    : 0),
                                                               __0__X168))));
                                                if (__1ee1)
                                                    ((__1ee1
                                                          ? (((void)(__1ee1
                                                                         ? (((void)((
                                                                               (void)__dl__4exprSFPvUl(
                                                                                   (void *)__1ee1,
                                                                                   (size_t)(sizeof(
                                                                                       struct
                                                                                       expr)))))))
                                                                         : (((void)0)))))
                                                          : (((void)0))));
                                                return typ__4exprFP5table(__0this, __1tbl);
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        if (__1n2 && (__0this->__O2__4expr.e1 == 0)) {
                            if (const_obj2)
                                __1const_obj = 1;
                            suppress_error++;
                            {
                                Pexpr __2mn;

                                __2mn = find_name__8classdefFPCcP8classdefiT3(
                                    ((struct classdef *)((
                                        (struct classdef *)__1n2->__O1__4expr.tp))),
                                    __1obb, (struct classdef *)0, 0, 0);
                                suppress_error--;
                                {
                                    Pname __2mname;

                                    __2mname = (((struct name *)(((struct name *)__2mn))));
                                    if (__2mname == 0)
                                        goto glob;

                                    while ((__2mname->base__4node == 44) ||
                                           (__2mname->base__4node == 177)) {
                                        __2mname = (((struct name *)((
                                            (struct name *)(((struct expr *)((
                                                                (struct expr *)__2mname))))
                                                ->__O4__4expr.mem))));
                                    }

                                    if ((__2mname->n_scope__4name != 0) &&
                                        (__2mname->n_scope__4name != 25)) {
                                        goto glob;
                                    }

                                    {
                                        int __2mo;

                                        __2mo = 0;
                                        if (__2mname->__O1__4expr.tp->base__4node == 108)
                                            __2mo = matchable__FP4nameP4expri(
                                                __2mname, (struct expr *)0, const_obj2);
                                        else if (__2mname->__O1__4expr.tp->base__4node == 76) {
                                            suppress_error++;
                                            {
                                                Pgen __3g;

                                                __3g = (((struct gen *)((
                                                    (struct gen *)__2mname->__O1__4expr.tp))));
                                                __2mname = exactMatch__3genFP4expri(
                                                    __3g, (struct expr *)0, const_obj2);
                                                if (ambig)
                                                    __1already_ambig += 2;
                                                suppress_error--;
                                                __2mo = (__2mname ? matchable__FP4nameP4expri(
                                                                        __2mname, (struct expr *)0,
                                                                        const_obj2)
                                                                  : 0);
                                            }
                                        }

                                        if (__2mo == 0) {
                                            goto glob;
                                        }
                                        if (((__2mo != 5) ||
                                             (look__5tableFPCcUc(
                                                  (((struct classdef *)((
                                                       (struct classdef *)__1n2->__O1__4expr.tp))))
                                                      ->memtbl__8classdef,
                                                  __1obb, (unsigned char)0) == 0)) &&
                                            (__1go != 5)) {
                                            struct gen *__0__X171;

                                            if ((__1Ggn &&
                                                 ((__0__X171 = (((struct gen *)((
                                                       (struct gen *)__1Ggn->__O1__4expr.tp))))),
                                                  ((__0__X171->holds_templ__3gen != 0)))) ||
                                                (__1gname && (__1gname->n_template_fct__4name))) {
                                                Pname __4f_inst;

                                                __4f_inst = has_templ_instance__FP4nameP4exprUc(
                                                    __1Ggn ? __1Ggn : __1gname, __1ee1,
                                                    (unsigned char)1);
                                                if (__4f_inst) {
                                                    __1gname = __4f_inst;
                                                    __1go = 5;
                                                    goto glob;
                                                }
                                            }
                                        }
                                        if (__2mo && __1go) {
                                            Ptype __3mt1;

                                            unsigned long __2__X16;

                                            struct ea __0__X__V1400qm5qkxojwcnm;

                                            struct ea __0__X__V1500qm5qkxojwcnm;

                                            __3mt1 =
                                                (((__2mname->__O1__4expr.tp->base__4node == 108)
                                                      ? (((struct fct *)(((struct fct *)__2mname
                                                                              ->__O1__4expr.tp))))
                                                      : (error__FiPCcRC2eaN33(
                                                             (int)'i',
                                                             (const char
                                                                  *)"N::fct_type():%n is %k notF",
                                                             (const struct ea
                                                                  *)(((&__0__X__V1400qm5qkxojwcnm)
                                                                          ->__O1__2ea.p =
                                                                          ((const void *)__2mname)),
                                                                     (&__0__X__V1400qm5qkxojwcnm)),
                                                             (const struct
                                                              ea *)((__2__X16 =
                                                                         __2mname->__O1__4expr.tp
                                                                             ->base__4node),
                                                                    (((((&__0__X__V1500qm5qkxojwcnm)
                                                                            ->__O1__2ea.i =
                                                                            __2__X16),
                                                                       0)),
                                                                     (&__0__X__V1500qm5qkxojwcnm))),
                                                             (const struct ea *)ea0,
                                                             (const struct ea *)ea0),
                                                         (((struct fct *)0)))))
                                                    ->f_this__3fct->__O1__4expr.tp;
                                            __3mt1 = (((struct ptr *)(((struct ptr *)__3mt1))))
                                                         ->typ__5pvtyp;
                                            {
                                                Pname __3marg;

                                                __3marg = __ct__4nameFPCc((struct name *)0,
                                                                          (const char *)0);
                                                __3marg->__O1__4expr.tp = __3mt1;
                                                {
                                                    Pname __3garg;
                                                    Pname __3nn;

                                                    unsigned long __2__X16;

                                                    struct ea __0__X__V1400qm5qkxojwcnm;

                                                    struct ea __0__X__V1500qm5qkxojwcnm;

                                                    __3garg =
                                                        (((__1gname->__O1__4expr.tp->base__4node ==
                                                           108)
                                                              ? (((struct fct *)((
                                                                    (struct fct *)
                                                                        __1gname->__O1__4expr.tp))))
                                                              : (error__FiPCcRC2eaN33(
                                                                     (int)'i',
                                                                     (const char *)"N::fct_type():%"
                                                                                   "n is %k notF",
                                                                     (const struct
                                                                      ea *)(((&__0__X__V1400qm5qkxojwcnm)
                                                                                 ->__O1__2ea.p =
                                                                                 ((const void *)
                                                                                      __1gname)),
                                                                            (&__0__X__V1400qm5qkxojwcnm)),
                                                                     (const struct
                                                                      ea *)((__2__X16 =
                                                                                 __1gname
                                                                                     ->__O1__4expr
                                                                                     .tp
                                                                                     ->base__4node),
                                                                            (((((&__0__X__V1500qm5qkxojwcnm)
                                                                                    ->__O1__2ea.i =
                                                                                    __2__X16),
                                                                               0)),
                                                                             (&__0__X__V1500qm5qkxojwcnm))),
                                                                     (const struct ea *)ea0,
                                                                     (const struct ea *)ea0),
                                                                 (((struct fct *)0)))))
                                                            ->argtype__3fct;
                                                    __3nn = bestOfPair__FP4nameT1P4type(
                                                        __3marg, __3garg,
                                                        __0this->__O3__4expr.e2->__O2__4expr.e1
                                                            ->__O1__4expr.tp);

                                                    if (__3nn == __3garg) {
                                                        if (__1already_ambig == 2)
                                                            __1already_ambig = 0;
                                                        ((__3marg
                                                              ? (((void)(__3marg
                                                                             ? (((void)((((((struct
                                                                                             expr *)
                                                                                                __3marg))
                                                                                              ? (((void)((((struct
                                                                                                            expr
                                                                                                                *)
                                                                                                               __3marg))
                                                                                                             ? (((void)(((
                                                                                                                   void)0))))
                                                                                                             : (((void)0)))))
                                                                                              : (((void)0)))),
                                                                                        (((void)__dl__4nameSFPvUl(
                                                                                            (void *)
                                                                                                __3marg,
                                                                                            (size_t)(sizeof(
                                                                                                struct
                                                                                                name))))))))
                                                                             : (((void)0)))))
                                                              : (((void)0))));
                                                        goto glob;
                                                    } else if (__3nn == __3marg) {
                                                        if (__1already_ambig == 1)
                                                            __1already_ambig = 0;
                                                    } else if (!__3nn) {
                                                        struct Block_Pname __4errblock;

                                                        (((((&__4errblock)->n__11Block_Pname = 0),
                                                           (((&__4errblock)->p__11Block_Pname = 0),
                                                            (move__11Block_PnameFPP4nameUl(
                                                                 (&__4errblock),
                                                                 (Pname
                                                                      *)(((struct name **)__nw__FUl(
                                                                     (size_t)((sizeof(
                                                                                  struct name *)) *
                                                                              ((unsigned long)3))))),
                                                                 ((unsigned long)3)),
                                                             (&__4errblock)->n__11Block_Pname)))),
                                                         (&__4errblock));
                                                        ((*((((Pname *)(&(
                                                            (&__4errblock)
                                                                ->p__11Block_Pname[0]))))))) =
                                                            __2mname;
                                                        ((*((((Pname *)(&(
                                                            (&__4errblock)
                                                                ->p__11Block_Pname[1]))))))) =
                                                            __1gname;
                                                        fmError__FiRC11Block_PnameP4exprUc(
                                                            1,
                                                            (const struct Block_Pname
                                                                 *)(&__4errblock),
                                                            __0this->__O3__4expr.e2,
                                                            (unsigned char)const_obj2);
                                                        __1already_ambig = 1;

                                                        ((((void)(__dl__FPv((void *)(&__4errblock)
                                                                                ->p__11Block_Pname),
                                                                  (((void)(((void)0))))))));
                                                    }
                                                    ((__3marg
                                                          ? (((void)(__3marg
                                                                         ? (((void)((((((struct expr
                                                                                             *)
                                                                                            __3marg))
                                                                                          ? (((void)((((struct
                                                                                                        expr
                                                                                                            *)
                                                                                                           __3marg))
                                                                                                         ? (((void)(((
                                                                                                               void)0))))
                                                                                                         : (((void)0)))))
                                                                                          : (((void)0)))),
                                                                                    (((void)__dl__4nameSFPvUl(
                                                                                        (void *)
                                                                                            __3marg,
                                                                                        (size_t)(sizeof(
                                                                                            struct
                                                                                            name))))))))
                                                                         : (((void)0)))))
                                                          : (((void)0))));
                                                }
                                            }
                                        }
                                        __0this->base__4node = 146;
                                        {
                                            Pname __2xx;

                                            struct ref *__0__X172;

                                            struct expr *__2__X173;

                                            struct expr *__2__X174;

                                            __2xx = __ct__4nameFPCc((struct name *)0,
                                                                    __2mname->__O2__4expr.string);

                                            __0this->__O2__4expr.e1 =
                                                (struct expr
                                                     *)((__0__X172 = 0),
                                                        ((__2__X173 = __1oe2),
                                                         ((__2__X174 = (struct expr *)__2xx),
                                                          (((__0__X172 ||
                                                             (__0__X172 =
                                                                  (struct ref *)__nw__4exprSFUl((
                                                                      size_t)(sizeof(struct ref)))))
                                                                ? ((__0__X172 = (struct ref *)
                                                                        __ct__4exprFUcP4exprT2(
                                                                            ((struct expr *)
                                                                                 __0__X172),
                                                                            ((unsigned char)45),
                                                                            __2__X173,
                                                                            (struct expr *)0)),
                                                                   (__0__X172->__O4__4expr.mem =
                                                                        __2__X174))
                                                                : 0),
                                                           __0__X172))));
                                            __0this->__O3__4expr.e2 = 0;
                                            if (__1ee2)
                                                ((__1ee2
                                                      ? (((void)(__1ee2
                                                                     ? (((void)((
                                                                           (void)__dl__4exprSFPvUl(
                                                                               (void *)__1ee2,
                                                                               (size_t)(sizeof(
                                                                                   struct
                                                                                   expr)))))))
                                                                     : (((void)0)))))
                                                      : (((void)0))));
                                            if (__1ee1 && (__1ee1 != __1ee2))
                                                ((__1ee1
                                                      ? (((void)(__1ee1
                                                                     ? (((void)((
                                                                           (void)__dl__4exprSFPvUl(
                                                                               (void *)__1ee1,
                                                                               (size_t)(sizeof(
                                                                                   struct
                                                                                   expr)))))))
                                                                     : (((void)0)))))
                                                      : (((void)0))));
                                            return typ__4exprFP5table(__0this, __1tbl);
                                        }
                                    }
                                }
                            }
                        }

                    glob:
                        if (__1go != 5) {
                            struct gen *__0__X175;

                            if ((__1Ggn &&
                                 ((__0__X175 =
                                       (((struct gen *)(((struct gen *)__1Ggn->__O1__4expr.tp))))),
                                  ((__0__X175->holds_templ__3gen != 0)))) ||
                                (__1gname && (__1gname->n_template_fct__4name))) {
                                Pname __3f_inst;

                                __3f_inst = has_templ_instance__FP4nameP4exprUc(
                                    __1Ggn ? __1Ggn : __1gname, __1ee1, (unsigned char)1);
                                if (__3f_inst) {
                                    __1gname = __3f_inst;
                                    __1go = 5;
                                }
                            }
                        }
                        if (__1go) {
                            if ((((__1go == 5) ||
                                  (try_to_demote__FUcP4typeT2(__1bb, __1t1, __1t2) <= 0)) ||
                                 (__1already_ambig > 0)) ||
                                compare_builtin__FP4typeT1P4nameN23i(__1t1, __1t2, __1n1, __1n2,
                                                                     __1gname, __1go)) {
                                __0this->base__4node =
                                    ((__1gname->__O4__4expr.n_table == gtbl) ? 146 : 109);
                                __0this->__O2__4expr.e1 = (struct expr *)__ct__4nameFPCc(
                                    (struct name *)0, __1gname->__O2__4expr.string);

                                if (__1gname->__O4__4expr.n_table == gtbl)
                                    (((struct name *)(((struct name *)__0this->__O2__4expr.e1))))
                                        ->__O2__4name.n_qualifier = sta_name;
                                __0this->__O3__4expr.e2 = __1ee1;
                                return typ__4exprFP5table(__0this, __1tbl);
                            }
                        }

                        if (__1ee2)
                            ((__1ee2 ? (((void)(__1ee2 ? (((void)(((void)__dl__4exprSFPvUl(
                                                             (void *)__1ee2,
                                                             (size_t)(sizeof(struct expr)))))))
                                                       : (((void)0)))))
                                     : (((void)0))));
                        if (__1ee1 && (__1ee1 != __1ee2))
                            ((__1ee1 ? (((void)(__1ee1 ? (((void)(((void)__dl__4exprSFPvUl(
                                                             (void *)__1ee1,
                                                             (size_t)(sizeof(struct expr)))))))
                                                       : (((void)0)))))
                                     : (((void)0))));
                        __0this->__O3__4expr.e2 = __1oe2;

                        switch (__1bb) {
                        case 71:
                        case 147:
                        case 145:
                            return (struct expr *)0;
                        case 70:
                            if ((__1n1 && __1n2) &&
                                ((__1n1->__O1__4expr.tp == __1n2->__O1__4expr.tp) ||
                                 has_base__8classdefFP8classdefiT2(
                                     ((struct classdef *)((
                                         (struct classdef *)__1n2->__O1__4expr.tp))),
                                     ((struct classdef *)((
                                         (struct classdef *)__1n1->__O1__4expr.tp))),
                                     0, 0))) {
                                if ((!const_obj1) && make_assignment__FP4name(__1n1))
                                    return oper_overload__4exprFP5table(__0this, __1tbl);
                                else
                                    return (struct expr *)0;
                            }
                        case 111:
                        case 109:
                            if (__1n1 == 0)
                                break;

                        default:
                            if ((__1n1 &&
                                 (((struct classdef *)(((struct classdef *)__1n1->__O1__4expr.tp))))
                                     ->conv__8classdef) &&
                                ((__1bb == 66) || (__1bb == 67))) {
                                __0this->__O2__4expr.e1 = check_cond__FP4exprUcP5table(
                                    __0this->__O2__4expr.e1, __1bb, __1tbl);
                                return (struct expr *)0;
                            }

                            if ((__1n2 &&
                                 (((struct classdef *)(((struct classdef *)__1n2->__O1__4expr.tp))))
                                     ->conv__8classdef) &&
                                ((((((__1bb == 66) || (__1bb == 67)) || (__1bb == 46)) ||
                                   (__1bb == 107)) ||
                                  (__1bb == 172)) ||
                                 (__1bb == 47))) {
                                Pexpr __3te;

                                __3te = check_cond__FP4exprUcP5table(__0this->__O3__4expr.e2, __1bb,
                                                                     __1tbl);
                                if (__3te == __0this->__O3__4expr.e2) {
                                    __0this->__O1__4expr.tp = (struct type *)any_type;
                                    return __0this;
                                }
                                __0this->__O3__4expr.e2 = __3te;
                                return (struct expr *)0;
                            }

                            {
                                int __2ttd;
                                switch (__2ttd = try_to_demote__FUcP4typeT2(__1bb, __1t1, __1t2)) {
                                case -2: {
                                    struct ea __0__V146;

                                    error__FPCcRC2eaN32(
                                        (const char *)"no usable const conversion for%n",
                                        (const struct ea *)(((&__0__V146)->__O1__2ea.p =
                                                                 ((const void *)__1n2)),
                                                            (&__0__V146)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    break;
                                case -1: {
                                    struct ea __0__V147;

                                    error__FPCcRC2eaN32(
                                        (const char *)"no usable const conversion for%n",
                                        (const struct ea *)(((&__0__V147)->__O1__2ea.p =
                                                                 ((const void *)__1n1)),
                                                            (&__0__V147)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    break;
                                case 0:
                                    break;
                                case 2: {
                                    struct ea __0__V148;

                                    error__FPCcRC2eaN32(
                                        (const char *)"ambiguous conversion of%n",
                                        (const struct ea *)(((&__0__V148)->__O1__2ea.p =
                                                                 ((const void *)__1n1)),
                                                            (&__0__V148)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    break;
                                case 3: {
                                    struct ea __0__V149;

                                    error__FPCcRC2eaN32(
                                        (const char *)"ambiguous conversion of%n",
                                        (const struct ea *)(((&__0__V149)->__O1__2ea.p =
                                                                 ((const void *)__1n2)),
                                                            (&__0__V149)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    break;
                                case 4: {
                                    struct ea __0__V150;

                                    struct ea __0__V151;

                                    error__FPCcRC2eaN32(
                                        (const char *)"ambiguous conversion of%n and%n",
                                        (const struct ea *)(((&__0__V150)->__O1__2ea.p =
                                                                 ((const void *)__1n1)),
                                                            (&__0__V150)),
                                        (const struct ea *)(((&__0__V151)->__O1__2ea.p =
                                                                 ((const void *)__1n2)),
                                                            (&__0__V151)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                    break;
                                case 1:
                                    if (Lcoerce) {
                                        Pname __4xx;
                                        Pref __4r;

                                        struct ref *__0__X176;

                                        struct expr *__2__X177;

                                        struct expr *__2__X178;

                                        __4xx = __ct__4nameFPCc((struct name *)0,
                                                                Lcoerce->__O2__4expr.string);
                                        __4r =
                                            ((__0__X176 = 0),
                                             ((__2__X177 = __0this->__O2__4expr.e1),
                                              ((__2__X178 = (struct expr *)__4xx),
                                               (((__0__X176 ||
                                                  (__0__X176 = (struct ref *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct ref)))))
                                                     ? ((__0__X176 =
                                                             (struct ref *)__ct__4exprFUcP4exprT2(
                                                                 ((struct expr *)__0__X176),
                                                                 ((unsigned char)45), __2__X177,
                                                                 (struct expr *)0)),
                                                        (__0__X176->__O4__4expr.mem = __2__X178))
                                                     : 0),
                                                __0__X176))));
                                        __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)146,
                                            (struct expr *)__4r, (struct expr *)0);
                                    }

                                    if (Rcoerce) {
                                        Pname __4xx;
                                        Pref __4r;

                                        struct ref *__0__X179;

                                        struct expr *__2__X180;

                                        struct expr *__2__X181;

                                        __4xx = __ct__4nameFPCc((struct name *)0,
                                                                Rcoerce->__O2__4expr.string);
                                        __4r =
                                            ((__0__X179 = 0),
                                             ((__2__X180 = __0this->__O3__4expr.e2),
                                              ((__2__X181 = (struct expr *)__4xx),
                                               (((__0__X179 ||
                                                  (__0__X179 = (struct ref *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct ref)))))
                                                     ? ((__0__X179 =
                                                             (struct ref *)__ct__4exprFUcP4exprT2(
                                                                 ((struct expr *)__0__X179),
                                                                 ((unsigned char)45), __2__X180,
                                                                 (struct expr *)0)),
                                                        (__0__X179->__O4__4expr.mem = __2__X181))
                                                     : 0),
                                                __0__X179))));
                                        __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)146,
                                            (struct expr *)__4r, (struct expr *)0);
                                    }
                                    return typ__4exprFP5table(__0this, __1tbl);
                                }
                                }
                                }
                                }
                                }
                                }

                                switch (__1bb) {
                                case 71:
                                case 112:
                                    return (struct expr *)0;
                                }

                                if (__1t1 && __1t2) {
                                    struct ea __0__V152;

                                    struct ea __0__V153;

                                    struct ea __0__V154;

                                    struct ea __0__V155;

                                    error__FiPCcRC2eaN33(
                                        (int)'e', (const char *)"bad operands for%k:%t%k%t",
                                        (const struct ea *)(((((&__0__V152)->__O1__2ea.i =
                                                                   ((unsigned long)__1bb)),
                                                              0)),
                                                            (&__0__V152)),
                                        (const struct ea *)(((&__0__V153)->__O1__2ea.p =
                                                                 ((const void *)__1t1)),
                                                            (&__0__V153)),
                                        (const struct ea *)(((((&__0__V154)->__O1__2ea.i =
                                                                   ((unsigned long)__1bb)),
                                                              0)),
                                                            (&__0__V154)),
                                        (const struct ea *)(((&__0__V155)->__O1__2ea.p =
                                                                 ((const void *)__1t2)),
                                                            (&__0__V155)));
                                } else {
                                    struct ea __0__V156;

                                    struct ea __0__V157;

                                    error__FiPCcRC2eaN33(
                                        (int)'e', (const char *)"bad operand for%k:%t",
                                        (const struct ea *)(((((&__0__V156)->__O1__2ea.i =
                                                                   ((unsigned long)__1bb)),
                                                              0)),
                                                            (&__0__V156)),
                                        (const struct ea *)(((&__0__V157)->__O1__2ea.p =
                                                                 ((const void *)(__1t1 ? __1t1
                                                                                       : __1t2))),
                                                            (&__0__V157)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                }
                                if ((__1const_obj && (__2ttd <= 0)) && non_const) {
                                    struct ea __0__V158;

                                    error__FiPCcRC2eaN33(
                                        (int)'c', (const char *)" (no usable const operator%k)\n",
                                        (const struct ea *)(((((&__0__V158)->__O1__2ea.i =
                                                                   ((unsigned long)__1bb)),
                                                              0)),
                                                            (&__0__V158)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                } else
                                    error__FiPCc((int)'c', (const char *)"\n");

                                __0this->__O1__4expr.tp = (struct type *)any_type;
                                return __0this;
                            }
                        }

                        return (struct expr *)0;
                    }
                }
            }
        }
    }
}

bit not_simple__4exprFi(struct expr *__0this, int __1inflag);

extern Ptype unconst_type__FP4type(Ptype);

extern Pexpr rptr__FP4typeP4expri(Ptype, Pexpr, int);

Pexpr cast_cptr__FP8classdefP4exprP5tablei(Pclass __1ccl, Pexpr __1ee, Ptable __1tbl,
                                           int __1real_cast) {
    Ptype __1etp;

    __1etp = (struct type *)is_ptr_or_ref__4typeFv(__1ee->__O1__4expr.tp);
    if (__1etp == 0)
        return __1ee;

    {
        Pname __1on;

        __1on = is_cl_obj__4typeFv((((struct ptr *)(((struct ptr *)__1etp))))->typ__5pvtyp);
        if (__1on == 0)
            return __1ee;

        {
            Pclass __1ocl;

            struct classdef *__1__X200;

            struct classdef *__1__X201;

            __1ocl = (((struct classdef *)(((struct classdef *)__1on->__O1__4expr.tp))));
            if (((__1ccl == 0) || (__1ocl == 0)) ||
                ((__1__X200 = __1ocl),
                 ((__1__X201 = __1ccl),
                  (((__1__X200 == __1__X201)
                        ? 1
                        : ((__1__X200 && __1__X201)
                               ? (((int)same_class__8classdefFP8classdefi(__1__X200, __1__X201, 0)))
                               : 0))))))
                return __1ee;

            {
                int __1oo;

                struct classdef *__1__X202;

                struct classdef *__1__X203;

                struct classdef *__1__X206;

                struct classdef *__1__X207;

                __1oo = 0;

                if (__1ocl->baselist__8classdef &&
                    ((!((__1__X202 = __1ocl->baselist__8classdef->bclass__6basecl),
                        ((__1__X203 = __1ccl),
                         (((__1__X202 == __1__X203)
                               ? 1
                               : ((__1__X202 && __1__X203)
                                      ? (((int)same_class__8classdefFP8classdefi(__1__X202,
                                                                                 __1__X203, 0)))
                                      : 0)))))) ||
                     (__1ocl->baselist__8classdef->base__4node != 85))) {

                    Nptr = 0;
                    Nvis = 0;
                    Nalloc_base = 0;
                    if (vcllist) {
                        clear__5clistFv(vcllist);
                        vcllist = 0;
                    }
                    {
                        int __2x;

                        __2x = is_unique_base__FP8classdefPCciT3T1(
                            __1ocl, __1ccl->string__8classdef, 0, 0, (struct classdef *)0);
                        if (Nvis) {
                            unsigned long __2__X204;

                            unsigned long __2__X205;

                            if (__1real_cast == 0) {
                                struct ea __0__V182;

                                struct ea __0__V183;

                                struct ea __0__V184;

                                error__FPCcRC2eaN32(
                                    (const char *)"cast:%n* ->B%t*;%kBC",
                                    (const struct ea *)(((&__0__V182)->__O1__2ea.p =
                                                             ((const void *)__1on)),
                                                        (&__0__V182)),
                                    (const struct ea *)(((&__0__V183)->__O1__2ea.p =
                                                             ((const void *)__1ccl)),
                                                        (&__0__V183)),
                                    (const struct ea *)((__2__X204 = Nvis),
                                                        (((((&__0__V184)->__O1__2ea.i = __2__X204),
                                                           0)),
                                                         (&__0__V184))),
                                    (const struct ea *)ea0);
                            } else if (warning_opt) {
                                struct ea __0__V185;

                                struct ea __0__V186;

                                struct ea __0__V187;

                                error__FiPCcRC2eaN33(
                                    (int)'w', (const char *)"cast:%n* ->B%t*;%kBC",
                                    (const struct ea *)(((&__0__V185)->__O1__2ea.p =
                                                             ((const void *)__1on)),
                                                        (&__0__V185)),
                                    (const struct ea *)(((&__0__V186)->__O1__2ea.p =
                                                             ((const void *)__1ccl)),
                                                        (&__0__V186)),
                                    (const struct ea *)((__2__X205 = Nvis),
                                                        (((((&__0__V187)->__O1__2ea.i = __2__X205),
                                                           0)),
                                                         (&__0__V187))),
                                    (const struct ea *)ea0);
                            }
                            __1real_cast = 1;
                            Nvis = 0;
                        }

                        switch (__2x) {
                        default: {
                            struct ea __0__V188;

                            struct ea __0__V189;

                            struct ea __0__V190;

                            error__FPCcRC2eaN32(
                                (const char *)"cast:%n* ->B%t*;%t isB more than once",
                                (const struct ea *)(((&__0__V188)->__O1__2ea.p =
                                                         ((const void *)__1on)),
                                                    (&__0__V188)),
                                (const struct ea *)(((&__0__V189)->__O1__2ea.p =
                                                         ((const void *)__1ccl)),
                                                    (&__0__V189)),
                                (const struct ea *)(((&__0__V190)->__O1__2ea.p =
                                                         ((const void *)__1ccl)),
                                                    (&__0__V190)),
                                (const struct ea *)ea0);
                        case 0:
                            break;
                        case 1:
                            __1oo = Noffset;
                            break;
                        }
                        }

                        if (Nptr) {
                            extern Pexpr this_handler;

                            if (__1ocl->c_body__8classdef == 1)
                                dcl_print__8classdefFP4name(__1ocl, (struct name *)0);
                            Nptr->__O4__4expr.mem = __1ee;
                            if (Nalloc_base) {
                                Nptr->__O2__4expr.i1 = 5;
                                Nptr->__O1__4expr.string4 = (((char *)__nw__FUl(
                                    (size_t)((sizeof(char)) * (strlen(Nalloc_base) + 1)))));

                                strcpy(Nptr->__O1__4expr.string4, Nalloc_base);
                                Nalloc_base = 0;
                            } else
                                Nptr->__O2__4expr.i1 = 3;

                            ;
                            if ((__1ee->base__4node == 112) || (__1ee->base__4node == 145))
                                __1ee = Nptr;
                            else if ((this_handler && (__1ee->base__4node == 85)) &&
                                     (strcmp(__1ee->__O2__4expr.string, (const char *)"this") == 0))
                                __1ee = this_handler;
                            else {
                                Pexpr __4p;

                                __4p = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)68,
                                                              Nptr, zero);
                                nin = 1;
                                if (not_simple__4exprFi(__1ee, 0)) {
                                    Ptype __5t;
                                    Pname __5pp;

                                    __5t = unconst_type__FP4type(__1ee->__O1__4expr.tp);
                                    __5pp = make_tmp__FcP4typeP5table('N', __5t, __1tbl);
                                    (((struct name *)(((struct name *)__5pp))))
                                        ->n_assigned_to__4name = 1;
                                    __1ee =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                               (struct expr *)__5pp, __1ee);
                                    __1ee->__O1__4expr.tp = __5t;
                                    Nptr->__O4__4expr.mem = (struct expr *)__5pp;
                                }
                                nin = 0;
                                __4p->__O4__4expr.cond = __1ee;
                                __4p->__O1__4expr.tp = __1ee->__O1__4expr.tp;
                                __1ee = __4p;
                            }
                        }
                    }
                }

                if (__1ccl->baselist__8classdef &&
                    ((!((__1__X206 = __1ccl->baselist__8classdef->bclass__6basecl),
                        ((__1__X207 = __1ocl),
                         (((__1__X206 == __1__X207)
                               ? 1
                               : ((__1__X206 && __1__X207)
                                      ? (((int)same_class__8classdefFP8classdefi(__1__X206,
                                                                                 __1__X207, 0)))
                                      : 0)))))) ||
                     (__1ccl->baselist__8classdef->base__4node != 85))) {

                    Nptr = 0;
                    if (vcllist) {
                        clear__5clistFv(vcllist);
                        vcllist = 0;
                    }
                    {
                        int __2x;

                        __2x = is_unique_base__FP8classdefPCciT3T1(
                            __1ccl, __1ocl->string__8classdef, 0, 0, (struct classdef *)0);
                        switch (__2x) {
                        default: {
                            struct ea __0__V191;

                            struct ea __0__V192;

                            struct ea __0__V193;

                            error__FPCcRC2eaN32(
                                (const char *)"cast:%n* ->derived%t*;%n isB more than once",
                                (const struct ea *)(((&__0__V191)->__O1__2ea.p =
                                                         ((const void *)__1on)),
                                                    (&__0__V191)),
                                (const struct ea *)(((&__0__V192)->__O1__2ea.p =
                                                         ((const void *)__1ccl)),
                                                    (&__0__V192)),
                                (const struct ea *)(((&__0__V193)->__O1__2ea.p =
                                                         ((const void *)__1on)),
                                                    (&__0__V193)),
                                (const struct ea *)ea0);
                        case 0:
                            break;
                        case 1:
                            __1oo = (-Noffset);
                            if (Nptr) {
                                struct ea __0__V194;

                                struct ea __0__V195;

                                struct ea __0__V196;

                                error__FPCcRC2eaN32(
                                    (const char *)"cast:%n* ->derived%t*;%n is virtualB",
                                    (const struct ea *)(((&__0__V194)->__O1__2ea.p =
                                                             ((const void *)__1on)),
                                                        (&__0__V194)),
                                    (const struct ea *)(((&__0__V195)->__O1__2ea.p =
                                                             ((const void *)__1ccl)),
                                                        (&__0__V195)),
                                    (const struct ea *)(((&__0__V196)->__O1__2ea.p =
                                                             ((const void *)__1on)),
                                                        (&__0__V196)),
                                    (const struct ea *)ea0);
                            }
                            break;
                        }
                        }
                        Nvis = 0;
                    }
                }

                if (__1oo) {
                    if (((__1ee->base__4node == 112) || (__1ee->base__4node == 145)) ||
                        ((__1ee->base__4node == 85) && (__1ee->__O1__4expr.tp->base__4node == 158)))
                        __1ee = rptr__FP4typeP4expri(__1ee->__O1__4expr.tp, __1ee, __1oo);
                    else {
                        Pexpr __3p;
                        nin = 1;
                        if (not_simple__4exprFi(__1ee, 0)) {
                            Ptype __4t;
                            Pname __4pp;

                            __4t = ((__1ee->base__4node == 177)
                                        ? __1ee->__O4__4expr.mem->__O1__4expr.tp
                                        : __1ee->__O1__4expr.tp);
                            __4pp = make_tmp__FcP4typeP5table('M', __4t, __1tbl);
                            if (__4pp->__O1__4expr.tp->base__4node == 110)
                                __4pp->__O1__4expr.tp = (struct type *)__ct__3ptrFUcP4type(
                                    (struct ptr *)0, (unsigned char)125,
                                    (((struct vec *)(((struct vec *)__4pp->__O1__4expr.tp))))
                                        ->typ__5pvtyp);
                            (((struct name *)(((struct name *)__4pp))))->n_assigned_to__4name = 1;
                            __1ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                           (struct expr *)__4pp, __1ee);
                            __1ee->__O1__4expr.tp = __4t;
                            __3p = rptr__FP4typeP4expri(__4t, (struct expr *)__4pp, __1oo);
                        } else
                            __3p = rptr__FP4typeP4expri((__1ee->base__4node == 177)
                                                            ? __1ee->__O4__4expr.mem->__O1__4expr.tp
                                                            : __1ee->__O1__4expr.tp,
                                                        __1ee, __1oo);
                        nin = 0;
                        {
                            Pexpr __3pp;

                            __3pp = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)68,
                                                           __3p, zero);
                            __3pp->__O1__4expr.tp = __1ee->__O1__4expr.tp;
                            __3pp->__O4__4expr.cond = __1ee;
                            __1ee = __3pp;
                        }
                    }
                }

                Nvis = 0;
                if (has_base__8classdefFP8classdefiT2(__1ocl, __1ccl, 0, 0) && Nvis) {
                    unsigned long __2__X208;

                    if (__1real_cast == 0) {
                        struct ea __0__V197;

                        struct ea __0__V198;

                        struct ea __0__V199;

                        error__FPCcRC2eaN32(
                            (const char *)"cast:%n* ->B%t*;%kBC",
                            (const struct ea *)(((&__0__V197)->__O1__2ea.p = ((const void *)__1on)),
                                                (&__0__V197)),
                            (const struct ea *)(((&__0__V198)->__O1__2ea.p =
                                                     ((const void *)__1ccl)),
                                                (&__0__V198)),
                            (const struct ea *)((__2__X208 = Nvis),
                                                (((((&__0__V199)->__O1__2ea.i = __2__X208), 0)),
                                                 (&__0__V199))),
                            (const struct ea *)ea0);
                    }
                    Nvis = 0;
                }

                return __1ee;
            }
        }
    }
}

void dcl__4typeFP5table(struct type *__0this, Ptable);

Pname has_ictor__8classdefFv(struct classdef *__0this);

void make_vec_ctor__8classdefFP4name(struct classdef *__0this, Pname);

extern Pexpr find_name__FP4nameP8classdefP5tableiT1(Pname, Pclass, Ptable, int, Pname);

Ptype call_fct__4exprFP5table(struct expr *__0this, Ptable);

extern void check_visibility__FP4nameT1P8classdefP5tableT1(Pname, Pname, Pclass, Ptable, Pname);

extern Pexpr call_ctor__FP5tableP4exprN22iT2(Ptable, Pexpr __0p, Pexpr __0ctor, Pexpr __0args,
                                             int __0d, Pexpr __0vb_args);

Pexpr donew__4exprFP5table(register struct expr *__0this, Ptable __1tbl) {
    Ptype __1tt;
    Ptype __1tpx;
    bit __1v;
    bit __1old;
    int __1init;

    __1tt = __0this->__O4__4expr.tp2;
    __1tpx = __1tt;
    __1v = 0;
    __1old = new_type;
    __1init = 0;
    new_type = 1;

    dcl__4typeFP5table(__1tt, __1tbl);
    new_type = __1old;

    if (__0this->__O2__4expr.e1)
        __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
    if (__0this->__O3__4expr.e2)
        __0this->__O3__4expr.e2 = typ__4exprFP5table(__0this->__O3__4expr.e2, __1tbl);
ll:
    switch (__1tt->base__4node) {
    default:
        if (__0this->__O2__4expr.e1) {
            if (__1v) {
                error__FPCc((const char *)"Ir for array created using \"new\"");
                break;
            }
            __1init = 1;
        }

        break;
    case 110:
        if (__1v && (((struct vec *)(((struct vec *)__1tt))))->dim__3vec)
            error__FPCc((const char *)"only 1st array dimension can be non-constant");
        if (((((struct vec *)(((struct vec *)__1tt))))->size__3vec == 0) &&
            ((((struct vec *)(((struct vec *)__1tt))))->dim__3vec == 0))
            error__FPCc((const char *)"array dimension missing in `new'");

        __1v++;
        __1tt = (((struct vec *)(((struct vec *)__1tt))))->typ__5pvtyp;
        goto ll;
    case 97:
        __1tt =
            (((struct basetype *)(((struct basetype *)__1tt))))->b_name__8basetype->__O1__4expr.tp;
        goto ll;
    case 38:
        error__FPCc((const char *)"badT for `new': void");
        break;
    case 119: {
        Pname __3cn;
        Pclass __3cl;
        Pname __3icn;

        __3cn = (((struct basetype *)(((struct basetype *)__1tt))))->b_name__8basetype;
        __3cl = (((struct classdef *)(((struct classdef *)__3cn->__O1__4expr.tp))));
        __3icn = 0;

        if (__0this->__O2__4expr.e1) {
            if ((__0this->__O2__4expr.e1->__O3__4expr.e2 == 0) &&
                (__0this->__O2__4expr.e1->base__4node == 140)) {
                __0this->__O2__4expr.e1 = __0this->__O2__4expr.e1->__O2__4expr.e1;
                __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
            }
            __3icn = ((__0this->__O2__4expr.e1->base__4node != 140)
                          ? is_cl_obj__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp)
                          : (((struct name *)0)));
        }

        {
            Pclass __3icl;

            __3icl = (__3icn ? (((struct classdef *)(((struct classdef *)__3icn->__O1__4expr.tp))))
                             : (((struct classdef *)0)));

            if (__3cl->c_abstract__8classdef) {
                const void *__2__X219;

                {
                    struct ea __0__V209;

                    error__FPCcRC2eaN32(
                        (const char *)"`new' of abstractC%t",
                        (const struct ea *)(((&__0__V209)->__O1__2ea.p = ((const void *)__3cl)),
                                            (&__0__V209)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    {
                        struct ea __0__V210;

                        struct ea __0__V211;

                        error__FiPCcRC2eaN33(
                            (int)'C', (const char *)"%a is a pure virtualF ofC%t\n",
                            (const struct ea *)((__2__X219 =
                                                     (const void *)__3cl->c_abstract__8classdef),
                                                (((&__0__V210)->__O1__2ea.p = __2__X219),
                                                 (&__0__V210))),
                            (const struct ea *)(((&__0__V211)->__O1__2ea.p = ((const void *)__3cl)),
                                                (&__0__V211)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                        break;
                    }
                }
            }

            if (__1v && __0this->__O2__4expr.e1) {
                error__FPCc((const char *)"Ir for array ofCO created using \"new\"");
                break;
            }

            if ((__3cl->defined__4type & 3) == 0) {
                {
                    struct ea __0__V212;

                    struct ea __0__V213;

                    error__FPCcRC2eaN32(
                        (const char *)"new%n;%n isU",
                        (const struct ea *)(((&__0__V212)->__O1__2ea.p = ((const void *)__3cn)),
                                            (&__0__V212)),
                        (const struct ea *)(((&__0__V213)->__O1__2ea.p = ((const void *)__3cn)),
                                            (&__0__V213)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    break;
                }
            }

            {
                Pname __3ctor;

                __3ctor = (__3cl->c_ctor__8classdef);

                if (__3ctor) {
                    struct classdef *__1__X220;

                    struct classdef *__1__X221;

                    if (__1v) {
                        Pname __5ic;
                        if ((__5ic = has_ictor__8classdefFv(__3cl)) == 0) {
                            {
                                struct ea __0__V214;

                                error__FPCcRC2eaN32(
                                    (const char *)"array ofC%n that does not have aK taking noAs",
                                    (const struct ea *)(((&__0__V214)->__O1__2ea.p =
                                                             ((const void *)__3cn)),
                                                        (&__0__V214)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                break;
                            }
                        }

                        if ((((struct fct *)(((struct fct *)__5ic->__O1__4expr.tp))))
                                ->nargs__3fct) {
                            if (!(__3cl->c_vtor__8classdef))
                                make_vec_ctor__8classdefFP4name(__3cl, __5ic);
                            break;
                        }
                    }

                    if ((__3icl && ((__3cl->c_itor__8classdef) == 0)) &&
                        (((__1__X220 = __3icl),
                          ((__1__X221 = __3cl),
                           (((__1__X220 == __1__X221)
                                 ? 1
                                 : ((__1__X220 && __1__X221)
                                        ? (((int)same_class__8classdefFP8classdefi(__1__X220,
                                                                                   __1__X221, 0)))
                                        : 0))))) ||
                         has_base__8classdefFP8classdefiT2(__3icl, __3cl, 0, 0))) {
                        __1init = 1;
                        break;
                    }

                    if (perf_opt && (!__1v)) {
                        extern int New_in_arg_list;
                        if (New_in_arg_list)
                            error__FiPCc((int)'s',
                                         (const char *)"optimization option does not allow new as "
                                                       "a default argument\n");

                        {
                            Pexpr __5p;
                            Pexpr __5args;
                            Pexpr __5sz;

                            struct texpr *__0__X225;

                            __5args = __0this->__O3__4expr.e2;
                            __5sz = (struct expr *)((__0__X225 = 0),
                                                    (((__0__X225 ||
                                                       (__0__X225 = (struct texpr *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct texpr)))))
                                                          ? ((__0__X225 = (struct texpr *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X225),
                                                                      ((unsigned char)30),
                                                                      ((struct expr *)0),
                                                                      (struct expr *)0)),
                                                             (__0__X225->__O4__4expr.tp2 = __1tt))
                                                          : 0),
                                                     __0__X225));
                            ((void)tsizeof__4typeFi(__1tt, 0));
                            __5sz->__O1__4expr.tp = (struct type *)uint_type;
                            {
                                Pexpr __5ee;
                                const char *__5s;
                                Pname __5n;

                                struct call *__0__X222;

                                struct expr *__2__X223;

                                struct expr *__2__X224;

                                __5ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                               __5sz, __5args);
                                __5s = oper_name__FUc((unsigned char)23);
                                __5n = __ct__4nameFPCc((struct name *)0, __5s);
                                if (__0this->base__4node == 184)
                                    __5p = (struct expr *)look__5tableFPCcUc(gtbl, __5s,
                                                                             (unsigned char)0);
                                else
                                    __5p = find_name__FP4nameP8classdefP5tableiT1(
                                        __5n, __3cl, __3cl->memtbl__8classdef, 109,
                                        cc->nof__11dcl_context);
                                __5ee =
                                    (struct expr
                                         *)((__0__X222 = 0),
                                            ((__2__X223 = __5p),
                                             ((__2__X224 = __5ee),
                                              (((__0__X222 ||
                                                 (__0__X222 = (struct call *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct call)))))
                                                    ? (__0__X222 =
                                                           (struct call *)__ct__4exprFUcP4exprT2(
                                                               ((struct expr *)__0__X222),
                                                               (unsigned char)109, __2__X223,
                                                               __2__X224))
                                                    : 0),
                                               __0__X222))));
                                overFound = 0;
                                ((void)call_fct__4exprFP5table(__5ee, __3cl->memtbl__8classdef));
                                if ((overFound && (overFound->n_scope__4name != 14)) &&
                                    (overFound->n_scope__4name != 31))
                                    check_visibility__FP4nameT1P8classdefP5tableT1(
                                        overFound, (struct name *)0,
                                        (((struct fct *)((
                                             (struct fct *)overFound->__O1__4expr.tp))))
                                            ->memof__3fct,
                                        cc->ftbl__11dcl_context, cc->nof__11dcl_context);
                                overFound = 0;
                                {
                                    Ptype __5cobj_ptr;
                                    Pname __5cobj_tmp;
                                    Pname __5tn;

                                    __5cobj_ptr = (struct type *)__ct__3ptrFUcP4type(
                                        (struct ptr *)0, (unsigned char)125, __1tt);

                                    __5tn = __1tbl->t_name__5table;

                                    if (__5tn && __5tn->__O1__4expr.tp) {
                                        __5cobj_tmp =
                                            make_tmp__FcP4typeP5table('B', __5cobj_ptr, gtbl);
                                    } else
                                        __5cobj_tmp =
                                            make_tmp__FcP4typeP5table('B', __5cobj_ptr, __1tbl);
                                    __5cobj_tmp->n_assigned_to__4name = 1;
                                    __5cobj_tmp->n_used__4name = 1;
                                    {
                                        Pexpr __5ctor_expr;

                                        __5ctor_expr = call_ctor__FP5tableP4exprN22iT2(
                                            __1tbl, (struct expr *)__5cobj_tmp,
                                            (struct expr *)__3ctor, __0this->__O2__4expr.e1, 44,
                                            (struct expr *)0);
                                        __5ee = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)70,
                                            (struct expr *)__5cobj_tmp, __5ee);
                                        __5ee = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                       (unsigned char)66, __5ee,
                                                                       __5ctor_expr);
                                        __5ee = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                       (unsigned char)147, __5ee,
                                                                       (struct expr *)__5cobj_tmp);
                                        __0this->__O2__4expr.e1 = __5ee;
                                        __0this->__O2__4expr.e1->__O1__4expr.tp = __5cobj_ptr;
                                        return __0this->__O2__4expr.e1;
                                    }
                                }
                            }
                        }
                    } else {
                        __0this->__O2__4expr.e1 = call_ctor__FP5tableP4exprN22iT2(
                            __1tbl, (struct expr *)0, (struct expr *)__3ctor,
                            __0this->__O2__4expr.e1, 44, (struct expr *)0);
                    }
                } else if (__0this->__O2__4expr.e1) {
                    struct classdef *__1__X226;

                    struct classdef *__1__X227;

                    if (((__1__X226 = __3icl),
                         ((__1__X227 = __3cl),
                          (((__1__X226 == __1__X227)
                                ? 1
                                : ((__1__X226 && __1__X227)
                                       ? (((int)same_class__8classdefFP8classdefi(__1__X226,
                                                                                  __1__X227, 0)))
                                       : 0))))) ||
                        has_base__8classdefFP8classdefiT2(__3icl, __3cl, 0, 0))
                        __1init = 1;
                    else {
                        struct ea __0__V215;

                        struct ea __0__V216;

                        error__FPCcRC2eaN32(
                            (const char *)"new%n(As );%n does not have aK",
                            (const struct ea *)(((&__0__V215)->__O1__2ea.p = ((const void *)__3cn)),
                                                (&__0__V215)),
                            (const struct ea *)(((&__0__V216)->__O1__2ea.p = ((const void *)__3cn)),
                                                (&__0__V216)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
            }
        }
    }
    }

    if (__1init) {
        Pname __2tmp;

        const void *__2__X228;

        __2tmp = make_tmp__FcP4typeP5table(
            'N', (struct type *)(__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __1tt)),
            __1tbl);
        __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
        if (check__4typeFP4typeUcT2(__1tt, __0this->__O2__4expr.e1->__O1__4expr.tp,
                                    (unsigned char)70, (unsigned char)0)) {
            struct ea __0__V217;

            struct ea __0__V218;

            error__FPCcRC2eaN32(
                (const char *)"badIrT%t for new operator (%t X)",
                (const struct ea *)((__2__X228 =
                                         (const void *)__0this->__O2__4expr.e1->__O1__4expr.tp),
                                    (((&__0__V217)->__O1__2ea.p = __2__X228), (&__0__V217))),
                (const struct ea *)(((&__0__V218)->__O1__2ea.p = ((const void *)__1tt)),
                                    (&__0__V218)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if ((__0this->__O2__4expr.e1->base__4node == 124) ||
            (((__0this->__O2__4expr.e1->base__4node == 140) &&
              __0this->__O2__4expr.e1->__O2__4expr.e1) &&
             (__0this->__O2__4expr.e1->__O2__4expr.e1->base__4node == 124))) {
            if (__0this->__O2__4expr.e1->base__4node != 124)
                __0this->__O2__4expr.e1 = __0this->__O2__4expr.e1->__O2__4expr.e1;
            {
                Pname __3tmp2;
                Ptype __3t;

                __3tmp2 = make_tmp__FcP4typeP5table('A', (struct type *)mptr_type, __1tbl);
                __3t = __0this->__O2__4expr.e1->__O1__4expr.tp;
                __0this->__O2__4expr.e1 =
                    mptr_assign__FP4exprT1((struct expr *)__3tmp2, __0this->__O2__4expr.e1);
                __0this->__O2__4expr.e1 =
                    __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                           __0this->__O2__4expr.e1, (struct expr *)__3tmp2);
                __0this->__O2__4expr.e1->__O1__4expr.tp = __3t;
            }
        }
        __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)0, (struct expr *)__2tmp, __0this->__O2__4expr.e1);
        assign__4nameFv(__2tmp);
        if (ansi_opt && __2tmp->__O1__4expr.tp) {
            Ptype __3t;

            __3t = __2tmp->__O1__4expr.tp;
            if (is_ptr_or_ref__4typeFv(__3t))
                __3t = (((struct ptr *)(((struct ptr *)__3t))))->typ__5pvtyp;
            __3t->ansi_const__4type = 1;
        }
    }

    switch (__1v) {
    case 0:
        __0this->__O1__4expr.tp =
            (struct type *)(__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __1tpx));
        break;
    case 1:
        __0this->__O1__4expr.tp = __1tpx;
        break;
    default:
        __0this->__O1__4expr.tp = __1tpx;
    }
    return __0this;
}

static int is_dataMemPtr__FP4expr(Pexpr __1ee) {
    Pexpr __1te;

    __1te = __1ee->__O2__4expr.e1;
    if (__1te == 0)
        return 0;
    if (__1te->base__4node != 54)
        return 0;
    if ((__1te = __1te->__O3__4expr.e2) == 0)
        return 0;
    if (__1te->base__4node != 55)
        return 0;
    if ((__1te = __1te->__O2__4expr.e1) == 0)
        return 0;
    if ((__1te->base__4node != 113) && (__1te->base__4node != 191))
        return 0;
    if ((__1te = __1te->__O2__4expr.e1) == 0)
        return 0;
    if (__1te->__O1__4expr.tp->base__4node != 125)
        return 0;
    if ((((struct ptr *)(((struct ptr *)__1te->__O1__4expr.tp))))->memof__3ptr == 0)
        return 0;
    return 1;
}

extern int exact1__FP4nameP4type(Pname, Ptype);
extern int exact2__FP4nameP4type(Pname, Ptype);
extern int exact3__FP4nameP4type(Pname, Ptype);

static Pname compare_builtin__FP4typeT1P4nameN23i(Ptype __1t1, Ptype __1t2, Pname __1n1,
                                                  Pname __1n2, Pname __1fname, int __1fo) {
    if (__1fo == 5)
        return __1fname;
    {
        bit __1binary;
        Pfct __1ff;
        TOK __1oper;

        unsigned long __2__X16;

        struct ea __0__X__V1400qm5qkxojwcnm;

        struct ea __0__X__V1500qm5qkxojwcnm;

        __1binary = ((__1t1 && __1t2) ? 1 : 0);
        __1ff = (((__1fname->__O1__4expr.tp->base__4node == 108)
                      ? (((struct fct *)(((struct fct *)__1fname->__O1__4expr.tp))))
                      : (error__FiPCcRC2eaN33(
                             (int)'i', (const char *)"N::fct_type():%n is %k notF",
                             (const struct ea *)(((&__0__X__V1400qm5qkxojwcnm)->__O1__2ea.p =
                                                      ((const void *)__1fname)),
                                                 (&__0__X__V1400qm5qkxojwcnm)),
                             (const struct ea
                                  *)((__2__X16 = __1fname->__O1__4expr.tp->base__4node),
                                     (((((&__0__X__V1500qm5qkxojwcnm)->__O1__2ea.i = __2__X16), 0)),
                                      (&__0__X__V1500qm5qkxojwcnm))),
                             (const struct ea *)ea0, (const struct ea *)ea0),
                         (((struct fct *)0)))));
        __1oper = __1fname->n_oper__4name;

        if ((((((((((((((__1oper == 111) || (__1oper == 109)) || (__1oper == 70)) ||
                      (__1oper == 44)) ||
                     (__1oper == 126)) ||
                    (__1oper == 127)) ||
                   (__1oper == 128)) ||
                  (__1oper == 129)) ||
                 (__1oper == 130)) ||
                (__1oper == 131)) ||
               (__1oper == 132)) ||
              (__1oper == 133)) ||
             (__1oper == 134)) ||
            (__1oper == 135))
            return __1fname;

        {
            int __1t1eobj;

            __1t1eobj = (__1t1 && (skiptypedefs__4typeFv(__1t1)->base__4node == 121));
            if (__1t1eobj) {
                Pname __2n1;
                Pclass __2c1;

                __2n1 = (__1t2 ? is_cl_obj__4typeFv(__1t2) : (((struct name *)0)));
                __2c1 = (__2n1 ? (((struct classdef *)(((struct classdef *)__2n1->__O1__4expr.tp))))
                               : (((struct classdef *)0)));
                if (__2c1) {
                    {
                        {
                            Pname __3on1;

                            __3on1 = __2c1->conv__8classdef;

                            for (; __3on1; __3on1 = __3on1->__O1__4name.n_list) {
                                Pfct __4f;
                                Ptype __4ret;

                                __4f = ((
                                    (__3on1->__O1__4expr.tp->base__4node == 108)
                                        ? (((struct fct *)(((struct fct *)__3on1->__O1__4expr.tp))))
                                        : (((struct fct *)((
                                              (struct fct *)(((struct gen *)((
                                                                 (struct gen *)
                                                                     __3on1->__O1__4expr.tp))))
                                                  ->fct_list__3gen->f__9name_list->__O1__4expr
                                                  .tp))))));
                                __4ret = (__4f ? __4f->returns__3fct : (((struct type *)0)));
                                if ((__4ret &&
                                     (skiptypedefs__4typeFv(__4ret)->base__4node == 121)) &&
                                    (!check__4typeFP4typeUcT2(__4ret, skiptypedefs__4typeFv(__1t1),
                                                              (unsigned char)70,
                                                              (unsigned char)0))) {
                                    __1t1eobj = 0;
                                    break;
                                }
                            }
                        }
                    }
                } else {
                    __1t1eobj = 0;
                }
            }
            {
                int __1t2eobj;

                __1t2eobj = (__1t2 && (skiptypedefs__4typeFv(__1t2)->base__4node == 121));
                if (__1t2eobj) {
                    Pname __2n1;
                    Pclass __2c1;

                    __2n1 = (__1t1 ? is_cl_obj__4typeFv(__1t1) : (((struct name *)0)));
                    __2c1 =
                        (__2n1 ? (((struct classdef *)(((struct classdef *)__2n1->__O1__4expr.tp))))
                               : (((struct classdef *)0)));
                    if (__2c1) {
                        {
                            {
                                Pname __3on1;

                                __3on1 = __2c1->conv__8classdef;

                                for (; __3on1; __3on1 = __3on1->__O1__4name.n_list) {
                                    Pfct __4f;
                                    Ptype __4ret;

                                    __4f = (((__3on1->__O1__4expr.tp->base__4node == 108)
                                                 ? (((struct fct *)((
                                                       (struct fct *)__3on1->__O1__4expr.tp))))
                                                 : (((struct fct *)((
                                                       (struct fct *)(((struct gen *)((
                                                                          (struct gen *)__3on1
                                                                              ->__O1__4expr.tp))))
                                                           ->fct_list__3gen->f__9name_list
                                                           ->__O1__4expr.tp))))));
                                    __4ret = (__4f ? __4f->returns__3fct : (((struct type *)0)));
                                    if ((__4ret &&
                                         (skiptypedefs__4typeFv(__4ret)->base__4node == 121)) &&
                                        (!check__4typeFP4typeUcT2(
                                            __4ret, skiptypedefs__4typeFv(__1t2), (unsigned char)70,
                                            (unsigned char)0))) {
                                        __1t2eobj = 0;
                                        break;
                                    }
                                }
                            }
                        }
                    } else {
                        __1t2eobj = 0;
                    }
                }
                {
                    int __1teobj;

                    __1teobj = (__1t1eobj || __1t2eobj);

                    if (__1ff->memof__3fct) {
                        if ((!__1binary) || __1n2)
                            return __1fname;

                        {
                            Pname __2nn;

                            __2nn = __1ff->argtype__3fct;

                            if (((!__1teobj) && exact1__FP4nameP4type(__2nn, __1t2)) ||
                                (__1teobj && exact2__FP4nameP4type(__2nn, __1t2)))
                                return __1fname;

                            opov_error__FP4typeT1Uc(__1t1, __1t2, __1oper);
                            return __1fname;
                        }
                    }

                    if (!__1binary) {
                        if (__1fo == 2) {
                            opov_error__FP4typeT1Uc(__1t1, __1t2, __1oper);
                            return __1fname;
                        }
                    } else {
                        if (__1n1 && __1n2) {
                            if (__1fo < 2)
                                return __1fname;
                            {
                                Pname __3nn1;
                                Pname __3nn2;

                                __3nn1 = __1ff->argtype__3fct;
                                __3nn2 = __3nn1->__O1__4name.n_list;
                                if (((((exact1__FP4nameP4type(__3nn1, __1t1) ||
                                        exact2__FP4nameP4type(__3nn1, __1t1)) ||
                                       exact3__FP4nameP4type(__3nn1, __1t1))
                                          ? (((unsigned char)1))
                                          : (((unsigned char)0)))) ||
                                    ((((exact1__FP4nameP4type(__3nn2, __1t2) ||
                                        exact2__FP4nameP4type(__3nn2, __1t2)) ||
                                       exact3__FP4nameP4type(__3nn2, __1t2))
                                          ? (((unsigned char)1))
                                          : (((unsigned char)0))))) {
                                    return __1fname;
                                } else {
                                    opov_error__FP4typeT1Uc(__1t1, __1t2, __1oper);
                                    return __1fname;
                                }
                            }
                        } else {
                            Pname __3carg;

                            Pname __3oarg;
                            Ptype __3ct;

                            Ptype __3ot;
                            if (__1n1) {
                                __3carg = __1ff->argtype__3fct;
                                __3ct = __1t1;
                                __3oarg = __3carg->__O1__4name.n_list;
                                __3ot = __1t2;
                            } else {
                                __3oarg = __1ff->argtype__3fct;
                                __3ot = __1t1;
                                __3carg = __3oarg->__O1__4name.n_list;
                                __3ct = __1t2;
                            }

                            if (((((exact1__FP4nameP4type(__3carg, __3ct) ||
                                    exact2__FP4nameP4type(__3carg, __3ct)) ||
                                   exact3__FP4nameP4type(__3carg, __3ct))
                                      ? (((unsigned char)1))
                                      : (((unsigned char)0))))) {
                                if (((!__1teobj) && (!exact1__FP4nameP4type(__3oarg, __3ot))) ||
                                    (__1teobj && (!exact2__FP4nameP4type(__3oarg, __3ot))))
                                    opov_error__FP4typeT1Uc(__1t1, __1t2, __1oper);
                                return __1fname;
                            } else {
                                if (((!__1teobj) && exact1__FP4nameP4type(__3oarg, __3ot)) ||
                                    (__1teobj && exact2__FP4nameP4type(__3oarg, __3ot))) {

                                    opov_error__FP4typeT1Uc(__1t1, __1t2, __1oper);
                                    return __1fname;
                                } else
                                    return (struct name *)0;
                            }
                        }
                    }

                    error__FiPCc((int)'i', (const char *)"fall off end of compare_builtin()");
                    return (struct name *)0;
                }
            }
        }
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

extern Ptfct ptfct_free__9templ_fct;

extern Pbase_inst head__10basic_inst;

struct templ_compilation { /* sizeof templ_compilation == 1 */

    char __W37__17templ_compilation;
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
