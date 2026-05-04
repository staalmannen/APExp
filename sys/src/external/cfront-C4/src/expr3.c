
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

typedef size_t Bits_chunk;

struct Block_Bits_chunk;

struct Block_Bits_chunk { /* sizeof Block_Bits_chunk == 16 */

    Bits_chunk *p__16Block_Bits_chunk;

    size_t n__16Block_Bits_chunk;
};

void move__16Block_Bits_chunkFPUlUl(struct Block_Bits_chunk *__0this, Bits_chunk *, size_t);

void copy__16Block_Bits_chunkFRC16Block_Bits_chunk(struct Block_Bits_chunk *__0this,
                                                   const struct Block_Bits_chunk *);

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

static int refd;
static int no_sti;
static int miFlag;
int no_const = 0;
extern int stat_init;
int ambig = 0;
bit in_return = 0;

Pname is_cl_obj__4typeFv(struct type *__0this);

Pptr is_ptr__4typeFv(struct type *__0this);

Pptr is_ref__4typeFv(struct type *__0this);

bit has_base__8classdefFP8classdefiT2(struct classdef *__0this, Pclass __1cl, int __1level,
                                      int __1ccflag);

static int pr_dominate__FP4typeT1(Ptype __1t1, Ptype __1t2) {
    Pname __1cn1;
    Pname __1cn2;

    __1cn1 = is_cl_obj__4typeFv(__1t1);
    __1cn2 = is_cl_obj__4typeFv(__1t2);

    if ((__1cn1 == 0) || (__1cn2 == 0)) {
        Ptype __2p1;
        Ptype __2p2;

        __2p1 = (struct type *)is_ptr__4typeFv(__1t1);
        __2p2 = (struct type *)is_ptr__4typeFv(__1t2);
        if (__2p1 && __2p2) {
            __1cn1 = is_cl_obj__4typeFv((((struct ptr *)(((struct ptr *)__2p1))))->typ__5pvtyp);
            __1cn2 = is_cl_obj__4typeFv((((struct ptr *)(((struct ptr *)__2p2))))->typ__5pvtyp);
            if ((__1cn1 == 0) || (__1cn2 == 0))
                return 0;
        } else {
            __2p1 = (struct type *)is_ref__4typeFv(__1t1);
            __2p2 = (struct type *)is_ref__4typeFv(__1t2);
            if (__2p1 && __2p2) {
                __1cn1 = is_cl_obj__4typeFv((((struct ptr *)(((struct ptr *)__2p1))))->typ__5pvtyp);
                __1cn2 = is_cl_obj__4typeFv((((struct ptr *)(((struct ptr *)__2p2))))->typ__5pvtyp);
                if ((__1cn1 == 0) || (__1cn2 == 0))
                    return 0;
            } else
                return 0;
        }
    }
    {
        Pclass __1c1;
        Pclass __1c2;

        __1c1 = (((struct classdef *)(((struct classdef *)__1cn1->__O1__4expr.tp))));
        __1c2 = (((struct classdef *)(((struct classdef *)__1cn2->__O1__4expr.tp))));

        if (has_base__8classdefFP8classdefiT2(__1c1, __1c2, 0, 0))
            return 1;
        if (has_base__8classdefFP8classdefiT2(__1c2, __1c1, 0, 0))
            return 2;
        return 0;
    }
}

Pname Ntmp = 0;
Pname Ntmp_refd = 0;
Pname Ntmp_flag = 0;
extern Pname Ntmp_flag_list;

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

extern char *make_name__FUc(TOK);

int tsizeof__4typeFi(struct type *__0this, int);

Pname dcl__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

Pname make_tmp__FcP4typeP5table(char __1c, Ptype __1t, Ptable __1tbl) {
    int __1dt;
    Pname __1tn;
    Pname __1cn;

    struct classdef *__0__X46;

    __1dt = 0;
    __1tn = __1tbl->t_name__5table;
    __1cn = is_cl_obj__4typeFv(__1t);

    if (__1tn && __1tn->__O1__4expr.tp)
        error__FiPCc((int)'s', (const char *)"defaultA too complicated");

    if (__1cn && ((__0__X46 = (((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))))),
                  (__0__X46->c_dtor__8classdef)))
        __1dt = 1;

    if ((Ntmp == 0) && __1dt)
        Ntmp = __1cn;

    if (Cstmt) {
        if (Cstmt->memtbl__4stmt == 0)
            Cstmt->memtbl__4stmt =
                __ct__5tableFsP5tableP4name((struct table *)0, (short)4, __1tbl, (struct name *)0);
        __1tbl = Cstmt->memtbl__4stmt;
    } else if ((__1tbl == gtbl) && (no_sti == 0)) {
        if (sti_tbl == 0)
            sti_tbl =
                __ct__5tableFsP5tableP4name((struct table *)0, (short)8, gtbl, (struct name *)0);
        __1tbl = sti_tbl;
    }

    {
        Pname __1tmpx;

        __1tmpx =
            __ct__4nameFPCc((struct name *)0, (const char *)make_name__FUc((unsigned char)__1c));
        __1tmpx->where__4name = no_where;
        __1tmpx->__O1__4expr.tp = __1t;
        ((void)tsizeof__4typeFi(__1t, 0));
        if (__1t->base__4node == 119) {
            Pclass __2cl;

            __2cl = (((struct classdef *)((
                (struct classdef *)(((struct basetype *)(((struct basetype *)__1t))))
                    ->b_name__8basetype->__O1__4expr.tp))));
            if (__2cl->lex_level__4type)
                __1tmpx->lex_level__4name = __2cl->lex_level__4type;
        }

        {
            TOK __1scop;

            __1scop = 136;
            if (stat_init && __1dt) {
                __1tmpx->n_sto__4name = 31;

                __1scop = 137;
            } else if (gtbl == __1tbl) {
                __1tmpx->n_sto__4name = 31;
            }

            {
                Pname __1tmp;

                __1tmp = dcl__4nameFP5tableUc(__1tmpx, __1tbl, __1scop);
                ((__1tmpx ? (((void)(__1tmpx ? (((void)((((((struct expr *)__1tmpx))
                                                              ? (((void)((((struct expr *)__1tmpx))
                                                                             ? (((void)(((void)0))))
                                                                             : (((void)0)))))
                                                              : (((void)0)))),
                                                        (((void)__dl__4nameSFPvUl(
                                                            (void *)__1tmpx,
                                                            (size_t)(sizeof(struct name))))))))
                                             : (((void)0)))))
                          : (((void)0))));

                __1tmp->n_scope__4name = ((__1scop == 136) ? 108 : 137);
                return __1tmp;
            }
        }
    }
}

Pexpr address__4exprFv(struct expr *__0this);

void dcl_print__4nameFUc(struct name *__0this, TOK);

extern Pexpr call_ctor__FP5tableP4exprN22iT2(Ptable, Pexpr __0p, Pexpr __0ctor, Pexpr __0args,
                                             int __0d, Pexpr __0vb_args);

Pfct memptr__4typeFv(struct type *__0this);

extern Pexpr mptr_assign__FP4exprT1(Pexpr, Pexpr);

Pexpr init_tmp__FP4nameP4exprP5table(Pname __1tmp, Pexpr __1init, Ptable __1tbl) {
    Pname __1cn;
    Pname __1ct;

    Pexpr __1ass;

    struct classdef *__0__X47;

    __1cn = is_cl_obj__4typeFv(__1tmp->__O1__4expr.tp);
    __1ct =
        (__1cn ? ((__0__X47 = (((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))))),
                  (__0__X47->c_itor__8classdef))
               : (((struct name *)0)));

    __1tmp->n_assigned_to__4name = 1;

    if (__1ct) {
        if (refd) {
            switch (__1init->__O2__4expr.e1->base__4node) {
            case 85:
            case 44:
            case 111:
                if (__1init->base__4node == 68)
                    __1init = address__4exprFv(__1init);
                else if (is_ptr__4typeFv(__1init->__O2__4expr.e1->__O1__4expr.tp))
                    __1init = __1init->__O2__4expr.e1;
                else
                    __1init = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147, __1init,
                                                     address__4exprFv(__1init->__O2__4expr.e1));
            }
            if (__1ct->__O1__4expr.tp->base__4node == 76)
                __1ct = (((struct gen *)(((struct gen *)__1ct->__O1__4expr.tp))))
                            ->fct_list__3gen->f__9name_list;
            __1tbl = 0;

            if (__1ct->n_dcl_printed__4name == 0)
                dcl_print__4nameFUc(__1ct, (unsigned char)0);
        }
        return call_ctor__FP5tableP4exprN22iT2(__1tbl, (struct expr *)__1tmp, (struct expr *)__1ct,
                                               __1init, 45, (struct expr *)0);
    }

    if (ansi_opt)
        __1tmp->__O1__4expr.tp->ansi_const__4type = 1;

    ;
    if ((__1init->base__4node == 86) && memptr__4typeFv(__1tmp->__O1__4expr.tp))
        __1ass = mptr_assign__FP4exprT1((struct expr *)__1tmp, __1init);
    else
        __1ass = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70, (struct expr *)__1tmp,
                                        __1init);
    __1ass->__O1__4expr.tp = __1tmp->__O1__4expr.tp;
    return __1ass;
}

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

int exact3__FP4nameP4type(Pname __1nn, Ptype __1at) {
    if (__1nn == 0)
        return 0;
    {
        Ptype __1nt;

        __1nt = skiptypedefs__4typeFv(__1nn->__O1__4expr.tp);

        if (__1at == __1nt)
            return 1;

        switch (__1nt->base__4node) {
        case 158:
            if ((__1nt->base__4node == 158) &&
                (check__4typeFP4typeUcT2((((struct ptr *)(((struct ptr *)__1nt))))->typ__5pvtyp,
                                         __1at, (unsigned char)78, (unsigned char)0) == 0))
                return 1;
            if ((__1at == (((struct type *)zero_type))) &&
                (is_ptr__4typeFv((((struct ptr *)(((struct ptr *)__1nt))))->typ__5pvtyp) == 0))
                return 0;
            if (check__4typeFP4typeUcT2(__1nt, __1at, (unsigned char)78, (unsigned char)0)) {
                Pptr __3pt;

                __3pt = (__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __1at));
                __1nt->base__4node = 125;
                if (check__4typeFP4typeUcT2(__1nt, (struct type *)__3pt, (unsigned char)78,
                                            (unsigned char)0)) {
                    __1nt->base__4node = 158;
                    ((__3pt ? (((void)(__3pt ? (((void)(((void)__dl__3ptrSFPvUl(
                                                   (void *)__3pt, (size_t)(sizeof(struct ptr)))))))
                                             : (((void)0)))))
                            : (((void)0))));
                    return 0;
                }
                __1nt->base__4node = 158;
                ((__3pt ? (((void)(__3pt ? (((void)(((void)__dl__3ptrSFPvUl(
                                               (void *)__3pt, (size_t)(sizeof(struct ptr)))))))
                                         : (((void)0)))))
                        : (((void)0))));
            }
            break;
        default:
            switch (__1at->base__4node) {
                Plist __3gl;
                int __3no_match;

            default:
                if (check__4typeFP4typeUcT2(__1nt, __1at, (unsigned char)78, (unsigned char)0))
                    return 0;
                break;
            case 76:;
                __3no_match = 1;

                for (__3gl = (((struct gen *)(((struct gen *)__1at))))->fct_list__3gen; __3gl;
                     __3gl = __3gl->l__9name_list) {
                    if (check__4typeFP4typeUcT2(__1nt, __3gl->f__9name_list->__O1__4expr.tp,
                                                (unsigned char)78, (unsigned char)0) == 0) {
                        __3no_match = 0;
                        break;
                    }
                }

                if (__3no_match)
                    return 0;
            }
        }
        return 1;
    }
}

int exact1__FP4nameP4type(Pname __1nn, Ptype __1at) {
    if (__1nn == 0)
        return 0;
    {
        Ptype __1nt;

        __1nt = skiptypedefs__4typeFv(__1nn->__O1__4expr.tp);
        if (__1at == __1nt)
            return 1;
        if (__1at->base__4node == 138)
            __1at = (struct type *)int_type;

        if (__1at->base__4node == 76) {
            Plist __2gl;

            for (__2gl = (((struct gen *)(((struct gen *)__1at))))->fct_list__3gen; __2gl;
                 __2gl = __2gl->l__9name_list) {
                if (check__4typeFP4typeUcT2(__1nt, __2gl->f__9name_list->__O1__4expr.tp,
                                            (unsigned char)0, (unsigned char)0) == 0) {
                    return 1;
                }
            }
            return 0;
        }

        {
            Pptr __1rt;
            Pptr __1art;

            __1rt = is_ptr__4typeFv(__1nt);
            __1art = is_ptr__4typeFv(__1at);

            if (check__4typeFP4typeUcT2(__1nt, __1at, (unsigned char)0, (unsigned char)0)) {
                if (const_problem && (__1nt->base__4node != 125))
                    return 1;

                if ((__1rt && __1rt->memof__3ptr) || (__1art && __1art->memof__3ptr))
                    return 0;

                __1rt = is_ref__4typeFv(__1nt);
                if (__1rt && ((check__4typeFP4typeUcT2(
                                   __1at, (((struct ptr *)(((struct ptr *)__1rt))))->typ__5pvtyp,
                                   (unsigned char)0, (unsigned char)0) == 0) ||
                              const_problem))
                    return 1;

                if (__1rt && __1art)
                    return 0;

                if (__1rt || (__1rt = is_ptr__4typeFv(__1nt))) {
                    if (__1art == 0)
                        __1art = is_ref__4typeFv(__1at);
                    if (__1art) {
                        if (check__4typeFP4typeUcT2(__1art->typ__5pvtyp, __1rt->typ__5pvtyp,
                                                    (unsigned char)0, (unsigned char)0)) {
                            if (const_problem &&
                                ((((struct basetype *)(((struct basetype *)__1art->typ__5pvtyp))))
                                     ->b_const__4type != 1))
                                return 1;
                        } else
                            return 1;
                    }
                }
                return 0;
            }
            return 1;
        }
    }
}

int exact2__FP4nameP4type(Pname __1nn, Ptype __1at) {
    __1at = skiptypedefs__4typeFv(__1at);
    switch (__1at->base__4node) {
    case 121:
        __1at =
            (struct type *)(((struct enumdef *)(((struct enumdef *)(((struct basetype *)((
                                                                        (struct basetype *)__1at))))
                                                     ->b_name__8basetype->__O1__4expr.tp))))
                ->e_type__7enumdef;

        break;
    case 138:
        __1at = (struct type *)int_type;
        break;
    case 5:
    case 29:
        __1at = (struct type *)(((((struct basetype *)(((struct basetype *)__1at))))
                                     ->b_unsigned__8basetype &&
                                 (tsizeof__4typeFi(__1at, 0) == SZ_INT))
                                    ? uint_type
                                    : int_type);
        break;
    case 15:
        __1at = (struct type *)double_type;
    }

    if (__1nn == 0)
        return 0;
    return exact1__FP4nameP4type(__1nn, __1at);
}

Pname Ncoerce = 0;
static int ref_cast;
int Nstd = 0;

bit can_coerce__FP4typeT1(Ptype __1t1, Ptype __1t2);

bit tconst__4typeFv(struct type *__0this);

extern void best_conv__FRC11Block_PnameRiUc(struct Bits *__0_result, const struct Block_Pname *,
                                            int *, bit);

bit can_coerce__FP4typeT1(Ptype __1t1, Ptype __1t2) {
    int __1zz;

    __1zz = 0;
    Ncoerce = 0;
    no_const = 0;
    if (__1t2->base__4node == 141)
        return (unsigned char)0;

    if (!check__4typeFP4typeUcT2(__1t1, __1t2, (unsigned char)78, (unsigned char)0))
        return (unsigned char)1;

    if (is_ref__4typeFv(__1t1)) {
        struct type *__0__X50;

        if (check__4typeFP4typeUcT2(
                __1t1,
                (struct type *)((__0__X50 = skiptypedefs__4typeFv(__1t2)),
                                (__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125,
                                                     __0__X50))),
                (unsigned char)78, (unsigned char)0) == 0)
            return (unsigned char)1;

        if (!ref_cast) {
            Ptype __3tt1;
            int __3bc;

            __3tt1 = skiptypedefs__4typeFv(
                (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv(__1t1)))))->typ__5pvtyp);

            if ((__3tt1->base__4node != 125) && (__3tt1->base__4node != 158)) {
                __3bc = (((struct basetype *)(((struct basetype *)__3tt1))))->b_const__4type;
                (((struct basetype *)(((struct basetype *)__3tt1))))->b_const__4type = 0;
            }
            {
                int __3i;

                __3i = can_coerce__FP4typeT1(__3tt1, __1t2);
                if ((__3tt1->base__4node != 125) && (__3tt1->base__4node != 158))
                    (((struct basetype *)(((struct basetype *)__3tt1))))->b_const__4type = __3bc;
                if (__3i)
                    return (unsigned char)__3i;
                __1zz = 1;
            }
        }
    }

    {
        Pname __1c1;
        Pname __1c2;
        int __1val;

        struct classdef *__0__X58;

        __1c1 = is_cl_obj__4typeFv(__1t1);
        __1c2 = is_cl_obj__4typeFv(__1t2);
        __1val = 0;
        if ((__1c1 && (!ref_cast)) && (!__1zz)) {
            Pclass __2cl;

            struct classdef *__1__X51;

            struct classdef *__1__X52;

            struct classdef *__1__X53;

            struct classdef *__1__X54;

            __2cl = (((struct classdef *)(((struct classdef *)__1c1->__O1__4expr.tp))));
            if (__1c2 &&
                ((__1__X51 = (((struct classdef *)(((struct classdef *)__1c2->__O1__4expr.tp))))),
                 ((__1__X52 = __2cl),
                  (((__1__X51 == __1__X52)
                        ? 1
                        : ((__1__X51 && __1__X52)
                               ? (((int)same_class__8classdefFP8classdefi(__1__X51, __1__X52, 0)))
                               : 0))))))
                return (unsigned char)1;

            if (__1c2 &&
                ((__1__X53 = (((struct classdef *)(((struct classdef *)__1c1->__O1__4expr.tp))))),
                 ((__1__X54 = (((struct classdef *)(((struct classdef *)__1c2->__O1__4expr.tp))))),
                  (((__1__X53 == __1__X54)
                        ? 1
                        : ((__1__X53 && __1__X54)
                               ? (((int)same_class__8classdefFP8classdefi(__1__X53, __1__X54, 0)))
                               : 0))))))
                return (unsigned char)1;

            {
                Pname __2ctor;
                Pfct __2f;

                __2ctor = (__2cl->c_ctor__8classdef);
                __2f = (__2ctor ? (((struct fct *)(((struct fct *)__2ctor->__O1__4expr.tp))))
                                : (((struct fct *)0)));

                if (__2f && (__2f->base__4node == 108)) {
                    if ((__2f->nargs__3fct == 1) ||
                        ((__2f->nargs__3fct > 1) &&
                         __2f->argtype__3fct->__O1__4name.n_list->__O3__4expr.n_initializer)) {
                        if (exact3__FP4nameP4type(__2f->argtype__3fct, __1t2)) {
                            __1val = 1;
                        }
                    }
                } else if (__2f && (__2f->base__4node == 76)) {
                    Plist __3gl;

                    for (__3gl = (((struct gen *)(((struct gen *)__2f))))->fct_list__3gen; __3gl;
                         __3gl = __3gl->l__9name_list) {
                        Pname __4nn;
                        Pfct __4ff;

                        __4nn = __3gl->f__9name_list;
                        __4ff = (((struct fct *)(((struct fct *)__4nn->__O1__4expr.tp))));

                        if ((__4ff->nargs__3fct == 1) ||
                            ((__4ff->nargs__3fct > 1) &&
                             __4ff->argtype__3fct->__O1__4name.n_list->__O3__4expr.n_initializer)) {
                            if (exact3__FP4nameP4type(__4ff->argtype__3fct, __1t2)) {
                                __1val = 1;
                                break;
                            }
                        }
                    }
                } else if (__2f) {
                    unsigned long __2__X55;

                    {
                        struct ea __0__V48;

                        error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"cannot_coerce(%k)\n",
                            (const struct ea *)((__2__X55 = __2f->base__4node),
                                                (((((&__0__V48)->__O1__2ea.i = __2__X55), 0)),
                                                 (&__0__V48))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
            }
        }

        if (__1c2) {

            struct Block_Pname __2conv;
            int __2found;
            Pclass __2cl;
            int __2best;

            (((((&__2conv)->n__11Block_Pname = 0), ((&__2conv)->p__11Block_Pname = 0))),
             (&__2conv));

            __2found = 0;
            __2cl = (((struct classdef *)(((struct classdef *)__1c2->__O1__4expr.tp))));
            __2best = 0;
            {{Pname __2ox;

            Pname __2on;

            __2on = __2cl->conv__8classdef;

            for (; __2on; __2on = __2ox) {
                __2ox = __2on->__O1__4name.n_list;
                {
                    Pfct __3f;

                    Ptype __3rt;
                    Pptr __3rr;

                    __3f = (((__2on->__O1__4expr.tp->base__4node == 108)
                                 ? (((struct fct *)(((struct fct *)__2on->__O1__4expr.tp))))
                                 : (((struct fct *)((
                                       (struct fct *)(((struct gen *)((
                                                          (struct gen *)__2on->__O1__4expr.tp))))
                                           ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))));

                    __3rt = __3f->returns__3fct;
                    __3rr = is_ref__4typeFv(__3rt);
                    if (__3rr && (!is_ref__4typeFv(__1t1)))
                        __3rt = __3rr->typ__5pvtyp;
                    Nstd = 0;
                    {
                        int __3howgood;

                        int __2__X56;

                        __3howgood = 0;
                        if (check__4typeFP4typeUcT2(__1t1, __3rt, (unsigned char)0,
                                                    (unsigned char)0) == 0) {
                            __3howgood = 6;

                        } else if (check__4typeFP4typeUcT2(__1t1, __3rt, (unsigned char)78,
                                                           (unsigned char)0) == 0) {
                            if (!Nstd)
                                __3howgood = 5;
                            else {
                                Pname __5t_nn;

                                __5t_nn = __ct__4nameFPCc((struct name *)0, (const char *)0);
                                __5t_nn->__O1__4expr.tp = skiptypedefs__4typeFv(__1t1);
                                if (exact2__FP4nameP4type(__5t_nn, __3rt))
                                    __3howgood = 4;
                                else
                                    __3howgood = 3;
                            }
                        }

                        if (tconst__4typeFv(__1t2) && (__3f->f_const__3fct == 0)) {
                            if (__3howgood)
                                no_const++;
                            continue;
                        }
                        if ((__3howgood == 0) || (__3howgood < __2best))
                            continue;
                        if (__3howgood > __2best) {
                            __2found = 0;

                            __2best = __3howgood;
                        }
                        (move__11Block_PnameFPP4nameUl(
                             (&__2conv),
                             (Pname *)(((struct name **)__nw__FUl(
                                 (size_t)((sizeof(struct name *)) *
                                          ((unsigned long)(__2found + 1)))))),
                             ((unsigned long)(__2found + 1))),
                         (&__2conv)->n__11Block_Pname);
                        ((*((__2__X56 = (__2found++)),
                            ((((Pname *)(&((&__2conv)->p__11Block_Pname[__2__X56])))))))) = __2on;
                    }
                }
            }
            if (__2found) {
                if (__2found == 1)
                    Ncoerce = ((*((((Pname *)(&((&__2conv)->p__11Block_Pname[0])))))));
                else {
                    struct Bits __4b;

                    struct Block_Bits_chunk *__0__X45;

                    int __2__X57;

                    best_conv__FRC11Block_PnameRiUc(&__4b, (const struct Block_Pname *)(&__2conv),
                                                    (int *)(&__2found), tconst__4typeFv(__1t1));

                    Ncoerce = ((*((__2__X57 = (signif__4BitsCFv((const struct Bits *)(&__4b)) - 1)),
                                  ((((Pname *)(&((&__2conv)->p__11Block_Pname[__2__X57]))))))));

                    ((((void)((
                        (void)(((__0__X45 = (&(&__4b)->b__4Bits)),
                                ((__0__X45
                                      ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                               (((void)0))))))));
                }
                __1val = (__1val + __2found);
            }
        }
    }

    ((((void)(__dl__FPv((void *)(&__2conv)->p__11Block_Pname), (((void)(((void)0))))))));
}
if (__1val)
    return (unsigned char)__1val;
if (__1c1 && ((__0__X58 = (((struct classdef *)(((struct classdef *)__1c1->__O1__4expr.tp))))),
              (__0__X58->c_itor__8classdef)))
    return (unsigned char)0;
if (check__4typeFP4typeUcT2(__1t1, __1t2, (unsigned char)78, (unsigned char)0))
    return (unsigned char)0;

return (unsigned char)1;
}
}

int matchable__FP4nameP4expri(Pname __1n, Pexpr __1arg, int __1constObj) {
    Pfct __1f;
    Pexpr __1e;
    Pname __1nn;
    int __1worst;

    int __1__X62;

    unsigned long __2__X16;

    struct ea __0__X__V1400qmhwx544vcnm;

    struct ea __0__X__V1500qmhwx544vcnm;

    __1f =
        (((__1n->__O1__4expr.tp->base__4node == 108)
              ? (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))))
              : (error__FiPCcRC2eaN33(
                     (int)'i', (const char *)"N::fct_type():%n is %k notF",
                     (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)->__O1__2ea.p =
                                              ((const void *)__1n)),
                                         (&__0__X__V1400qmhwx544vcnm)),
                     (const struct ea *)((__2__X16 = __1n->__O1__4expr.tp->base__4node),
                                         (((((&__0__X__V1500qmhwx544vcnm)->__O1__2ea.i = __2__X16),
                                            0)),
                                          (&__0__X__V1500qmhwx544vcnm))),
                     (const struct ea *)ea0, (const struct ea *)ea0),
                 (((struct fct *)0)))));

    __1worst = 5;

    if ((__1n->n_template_fct__4name))
        return 0;

    if (((__1constObj && (__1n->n_oper__4name != 161)) && (!__1f->f_const__3fct)) &&
        (!__1f->f_static__3fct)) {
        non_const++;
        return (int)0;
    }

    for (((__1e = __1arg), (__1nn = __1f->argtype__3fct)); __1e;
         ((__1e = __1e->__O3__4expr.e2), (__1nn = __1nn->__O1__4name.n_list))) {
        if (__1nn == 0)
            return (__1f->nargs_known__3fct == 155);
        {
            Pexpr __2a;
            Ptype __2at;

            __2a = __1e->__O2__4expr.e1;
            __2at = __2a->__O1__4expr.tp;
            if (__2at->base__4node == 141)
                return (int)0;
            if (exact1__FP4nameP4type(__1nn, __2at)) {
                int __1__X59;

                __1worst = ((__1__X59 = 5), (((__1worst < __1__X59) ? __1worst : __1__X59)));

                continue;
            }
            if (exact2__FP4nameP4type(__1nn, __2at)) {
                int __1__X60;

                __1worst = ((__1__X60 = 4), (((__1worst < __1__X60) ? __1worst : __1__X60)));

                continue;
            }
            if (exact3__FP4nameP4type(__1nn, __2at)) {
                int __1__X61;

                __1worst = ((__1__X61 = 3), (((__1worst < __1__X61) ? __1worst : __1__X61)));

                continue;
            }
            {
                int __2cc;

                __2cc = can_coerce__FP4typeT1(__1nn->__O1__4expr.tp, __2at);
                if (__2cc != 1)
                    return (int)0;
                else
                    __1worst = 2;
            }
        }
    }
    if (__1nn && (__1nn->__O3__4expr.n_initializer == 0))
        return (int)0;
    return ((__1__X62 = 5), (((__1worst < __1__X62) ? __1worst : __1__X62)));
}

int is_arg = 0;

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

extern int error__FPCc(const char *);

Pname exactMatch__3genFP4expri(struct gen *__0this, Pexpr, int);

extern Pname has_templ_instance__FP4nameP4exprUc(Pname, Pexpr, bit);

Pname oneArgMatch__3genFP4expri(struct gen *__0this, Pexpr, int);
Pname multArgMatch__3genFP4expri(struct gen *__0this, Pexpr, int);

extern void fmError__FiRC11Block_PnameP4exprUc(int, const struct Block_Pname *, Pexpr, bit);

extern void check_visibility__FP4nameT1P8classdefP5tableT1(Pname, Pname, Pclass, Ptable, Pname);

extern void make_res__FP3fct(Pfct);

extern void uninline__FP4name(Pname __3fn);

extern Pexpr ref_init__FP3ptrP4exprP5table(Pptr, Pexpr, Ptable);
extern Pexpr class_init__FP4exprP4typeT1P5table(Pexpr, Ptype, Pexpr, Ptable);

extern Pexpr ptr_init__FP3ptrP4exprP5table(Pptr, Pexpr, Ptable);

extern Pexpr try_to_coerce__FP4typeP4exprPCcP5table(Ptype, Pexpr, const char *, Ptable);

int lval__4exprFUc(struct expr *__0this, TOK);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

Pexpr contents__4exprFv(struct expr *__0this);

void assign__4nameFv(struct name *__0this);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

Ptype call_fct__4exprFP5table(register struct expr *__0this, Ptable __1tbl) {
    Pfct __1f;
    Pname __1fn;
    int __1x;
    int __1k;
    Pname __1nn;
    Pexpr __1e;
    Ptype __1t;
    Pexpr __1arg;
    Ptype __1t1;

    int __1argno;
    Pexpr __1etail;
    bit __1no_change;
    Pname __1no_virt;
    Pname __1chk;

    int __1const_obj;

    const void *__2__X112;

    unsigned long __2__X113;

    __1arg = __0this->__O3__4expr.e2;
    __1t1 =
        (__0this->__O2__4expr.e1 ? __0this->__O2__4expr.e1->__O1__4expr.tp : (((struct type *)0)));
    ambig = 0;
    ;
    __1etail = 0;
    __1no_change = 0;
    __1no_virt = 0;
    __1chk = 0;

    __1const_obj = 0;

    if (__1t1 == (((struct type *)any_type)))
        return (struct type *)any_type;

    switch (__0this->base__4node) {
        unsigned long __2__X111;

    case 109:
    case 146:
        break;
    default: {
        struct ea __0__V63;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"call_fct(%k)",
            (const struct ea *)((__2__X111 = __0this->base__4node),
                                (((((&__0__V63)->__O1__2ea.i = __2__X111), 0)), (&__0__V63))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }

    if (__1t1 == 0) {
        struct ea __0__V64;

        struct ea __0__V65;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"call_fct(e1=%d,e1->tp=%t)",
            (const struct ea *)((__2__X112 = (const void *)__0this->__O2__4expr.e1),
                                (((&__0__V64)->__O1__2ea.p = __2__X112), (&__0__V64))),
            (const struct ea *)(((&__0__V65)->__O1__2ea.p = ((const void *)__1t1)), (&__0__V65)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__1arg && (__1arg->base__4node != 140)) {
        struct ea __0__V66;

        struct ea __0__V67;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"badAL%d%k",
            (const struct ea *)(((&__0__V66)->__O1__2ea.p = ((const void *)__1arg)), (&__0__V66)),
            (const struct ea *)((__2__X113 = __1arg->base__4node),
                                (((((&__0__V67)->__O1__2ea.i = __2__X113), 0)), (&__0__V67))),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    switch (__0this->__O2__4expr.e1->base__4node) {
    case 162:
        __1fn = (((struct name *)(((struct name *)__0this->__O2__4expr.e1))));
        break;
    case 85:
        __1fn = (((struct name *)(((struct name *)__0this->__O2__4expr.e1))));
        switch (__1fn->n_oper__4name) {
        case 0:
        case 161:
        case 162:
        case 97:
        case 23:
        case 213:
        case 9:
        case 212:
            break;
        default: {
            if (__1arg == 0)
                break;
            {
                Pexpr __4a;

                unsigned long __2__X114;

                __4a = __1arg->__O2__4expr.e1;

                if (is_cl_obj__4typeFv(__4a->__O1__4expr.tp))
                    break;
                if (is_ref__4typeFv(__4a->__O1__4expr.tp))
                    break;
                __4a = __1arg->__O3__4expr.e2;
                if (__4a == 0) {
                    struct ea __0__V68;

                    error__FPCcRC2eaN32(
                        (const char *)"%k of basicT",
                        (const struct ea *)((__2__X114 = __1fn->n_oper__4name),
                                            (((((&__0__V68)->__O1__2ea.i = __2__X114), 0)),
                                             (&__0__V68))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                } else {
                    unsigned long __2__X115;

                    __4a = __4a->__O2__4expr.e1;
                    if (is_cl_obj__4typeFv(__4a->__O1__4expr.tp) ||
                        is_ref__4typeFv(__4a->__O1__4expr.tp))
                        break;
                    {
                        struct ea __0__V69;

                        error__FPCcRC2eaN32(
                            (const char *)"%k of basicTs",
                            (const struct ea *)((__2__X115 = __1fn->n_oper__4name),
                                                (((((&__0__V69)->__O1__2ea.i = __2__X115), 0)),
                                                 (&__0__V69))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
                break;
            }
        }
        }
        break;
    case 44:
    case 45:
        __1no_virt = ((
            (struct name *)(((struct name *)__0this->__O2__4expr.e1->__O3__4expr.n_initializer))));
        __0this->__O2__4expr.e1->__O3__4expr.n_initializer = 0;
        if (__0this->__O2__4expr.e1 && __0this->__O2__4expr.e1->__O2__4expr.e1) {
            Ptype __3t;
            Pptr __3tt;

            __3t = __0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp;
            __3tt = is_ref__4typeFv(__3t);
            __3t = (__3tt ? __3tt->typ__5pvtyp : __3t);
            {
                Pptr __3p_t;

                __3p_t = is_ptr__4typeFv(__3t);
                __3t =
                    (((__0this->__O2__4expr.e1->base__4node == 44) && __3p_t) ? __3p_t->typ__5pvtyp
                                                                              : __3t);
                __3tt = is_ref__4typeFv(__3t);
                __3t = (__3tt ? __3tt->typ__5pvtyp : __3t);
                __1const_obj = tconst__4typeFv(__3t);
            }
        }
    case 177: {
        Pexpr __3n;

        __3n = __0this->__O2__4expr.e1->__O4__4expr.mem;
    lxlx:
        switch (__3n->base__4node) {
            unsigned long __2__X118;

        case 177: {
            Pexpr __5r;
            Pexpr __5p;

            __5r = __0this->__O2__4expr.e1;
            __5p = __5r->__O2__4expr.e1;
            {
                {
                    Pexpr __5m;

                    __5m = __5r->__O4__4expr.mem;

                    for (; __5m->base__4node == 177; __5m = __5r->__O4__4expr.mem) {
                        register struct mdot *__0__X116;

                        const char *__2__X117;

                        __5p =
                            (struct expr
                                 *)((__0__X116 = 0),
                                    ((__2__X117 = __5m->__O3__4expr.string2),
                                     (((__0__X116 || (__0__X116 = (struct mdot *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct mdot)))))
                                           ? ((__0__X116 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X116), (unsigned char)177,
                                                   (struct expr *)0, (struct expr *)0)),
                                              ((__0__X116->__O3__4expr.string2 = __2__X117),
                                               (__0__X116->__O4__4expr.mem = __5p)))
                                           : 0),
                                      __0__X116)));
                        __5p->__O2__4expr.i1 = (__5m->__O2__4expr.i1 + 2);
                        if (__5p->__O4__4expr.mem &&
                            ((((struct expr *)(((struct expr *)__5p->__O4__4expr.mem)))) !=
                             (((struct expr *)1))))
                            __5p->__O1__4expr.tp = __5p->__O4__4expr.mem->__O1__4expr.tp;
                        __5r->__O4__4expr.mem = __5m->__O4__4expr.mem;
                        __5r->__O2__4expr.e1 = __5p;
                    }
                }
            }
        }
        case 44:
        case 45:
            __3n = __3n->__O4__4expr.mem;
            goto lxlx;
        case 85:
        case 162:
            break;
        default: {
            struct ea __0__V70;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"ref %k",
                (const struct ea *)((__2__X118 = __3n->base__4node),
                                    (((((&__0__V70)->__O1__2ea.i = __2__X118), 0)), (&__0__V70))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        }
        __1fn = (((struct name *)(((struct name *)__3n))));
        break;
    }
    case 173:
    default:
        __1fn = 0;
    }

lll:
    switch (__1t1->base__4node) {
        unsigned long __2__X119;

        const void *__2__X120;

    case 97:
        __1t1 =
            (((struct basetype *)(((struct basetype *)__1t1))))->b_name__8basetype->__O1__4expr.tp;
        goto lll;

    case 125:
        switch (skiptypedefs__4typeFv((((struct ptr *)(((struct ptr *)__1t1))))->typ__5pvtyp)
                    ->base__4node) {
        case 108:
        case 76:
            if ((((struct ptr *)(((struct ptr *)__1t1))))->memof__3ptr)
                error__FPCc((const char *)"O missing in call throughP toMF");
            __1t1 = (((struct ptr *)(((struct ptr *)__1t1))))->typ__5pvtyp;
            __1fn = 0;
            goto lll;
        }

    default:
        if (__1fn) {
            struct ea __0__V71;

            struct ea __0__V72;

            struct ea __0__V73;

            error__FPCcRC2eaN32(
                (const char *)"call of%n;%n is a%t",
                (const struct ea *)(((&__0__V71)->__O1__2ea.p = ((const void *)__1fn)),
                                    (&__0__V71)),
                (const struct ea *)(((&__0__V72)->__O1__2ea.p = ((const void *)__1fn)),
                                    (&__0__V72)),
                (const struct ea *)__ct__2eaFPCv(
                    &__0__V73, (const void *)__0this->__O2__4expr.e1->__O1__4expr.tp),
                (const struct ea *)ea0);
        } else {
            struct ea __0__V74;

            struct ea __0__V75;

            error__FPCcRC2eaN32(
                (const char *)"call of%kE ofT%t",
                (const struct ea *)((__2__X119 = __0this->__O2__4expr.e1->base__4node),
                                    (((((&__0__V74)->__O1__2ea.i = __2__X119), 0)), (&__0__V74))),
                (const struct ea *)((__2__X120 =
                                         (const void *)__0this->__O2__4expr.e1->__O1__4expr.tp),
                                    (((&__0__V75)->__O1__2ea.p = __2__X120), (&__0__V75))),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
    case 141:
        return (struct type *)any_type;

    case 76: {
        Pgen __3g;
        Pname __3found;

        unsigned long __2__X16;

        struct ea __0__X__V1400qmhwx544vcnm;

        struct ea __0__X__V1500qmhwx544vcnm;

        __3g = (((struct gen *)(((struct gen *)__1t1))));
        __3found = 0;

        __3found = exactMatch__3genFP4expri(__3g, __1arg, __1const_obj);

        if (((!__3found) && __1arg) && ((__3g->holds_templ__3gen != 0))) {
            __3found = has_templ_instance__FP4nameP4exprUc(__1fn, __1arg, (unsigned char)0);
        }

        if (((!__3found) && __1arg) && (__1arg->__O3__4expr.e2 == 0)) {
            __3found = oneArgMatch__3genFP4expri(__3g, __1arg, __1const_obj);
        } else if ((!__3found) && __1arg) {
            __3found = multArgMatch__3genFP4expri(__3g, __1arg, __1const_obj);
        }

        if (!__3found) {
            struct Block_Pname __4tmp;

            (((((&__4tmp)->n__11Block_Pname = 0),
               (((&__4tmp)->p__11Block_Pname = 0),
                (move__11Block_PnameFPP4nameUl(
                     (&__4tmp),
                     (Pname *)(((struct name **)__nw__FUl(
                         (size_t)((sizeof(struct name *)) * ((unsigned long)1))))),
                     ((unsigned long)1)),
                 (&__4tmp)->n__11Block_Pname)))),
             (&__4tmp));
            ((*((((Pname *)(&((&__4tmp)->p__11Block_Pname[0]))))))) = __1fn;
            fmError__FiRC11Block_PnameP4exprUc(0, (const struct Block_Pname *)(&__4tmp), __1arg,
                                               (unsigned char)__1const_obj);
            {
                ((((void)(__dl__FPv((void *)(&__4tmp)->p__11Block_Pname), (((void)(((void)0))))))));

                return (struct type *)any_type;
            }
        }

        overFound = (__1chk = (__1fn = __3found));
        __1f = (((__1fn->__O1__4expr.tp->base__4node == 108)
                     ? (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))))
                     : (error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"N::fct_type():%n is %k notF",
                            (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)->__O1__2ea.p =
                                                     ((const void *)__1fn)),
                                                (&__0__X__V1400qmhwx544vcnm)),
                            (const struct ea
                                 *)((__2__X16 = __1fn->__O1__4expr.tp->base__4node),
                                    (((((&__0__X__V1500qmhwx544vcnm)->__O1__2ea.i = __2__X16), 0)),
                                     (&__0__X__V1500qmhwx544vcnm))),
                            (const struct ea *)ea0, (const struct ea *)ea0),
                        (((struct fct *)0)))));
        break;
    }

    case 108:
        __1f = (((struct fct *)(((struct fct *)__1t1))));
        if (__1fn) {
            if ((__1fn->n_template_fct__4name)) {
                Pname __4f_inst;

                __4f_inst = has_templ_instance__FP4nameP4exprUc(__1fn, __1arg, (unsigned char)0);
                if (__4f_inst) {
                    __0this->__O2__4expr.e1 = (struct expr *)__4f_inst;

                    __1fn = __4f_inst;
                    __1t1 = __4f_inst->__O1__4expr.tp;

                    __1f = (((struct fct *)(((struct fct *)__4f_inst->__O1__4expr.tp))));
                }
            } else
                switch (__1fn->n_oper__4name) {
                case 161:
                case 97:
                    __1chk = __1fn;
                }
        }
    }

    if (__1chk) {
        Ptype __2t;
        Pexpr __2ee;

        __2t = 0;
        __2ee = __0this->__O2__4expr.e1->__O2__4expr.e1;

        switch (__0this->__O2__4expr.e1->base__4node) {
        case 44:
            if (__2ee == 0) {
                check_visibility__FP4nameT1P8classdefP5tableT1(
                    __1chk, __1no_virt,
                    ((struct classdef *)(((struct classdef *)__1chk->__O4__4expr.n_table
                                              ->t_name__5table->__O1__4expr.tp))),
                    __1tbl, cc->nof__11dcl_context);
                break;
            }

            ;
            __2t = skiptypedefs__4typeFv(__2ee->__O1__4expr.tp);
            __2t = (((struct ptr *)(((struct ptr *)__2t))))->typ__5pvtyp;
            break;
        case 45:
            __2t = __2ee->__O1__4expr.tp;
        }

        {
            Pname __2cn;
            Pclass __2cl;

            __2cn = (__2t ? is_cl_obj__4typeFv(__2t) : (((struct name *)0)));
            __2cl = (__2cn ? (((struct classdef *)(((struct classdef *)__2cn->__O1__4expr.tp))))
                           : (((struct classdef *)0)));

            if (__2cl) {
                if ((((__1chk->n_oper__4name == 161) && __1chk->n_protect__4name) &&
                     cc->nof__11dcl_context) &&
                    (cc->nof__11dcl_context->n_oper__4name == 161))
                    ;
                else {
                    check_visibility__FP4nameT1P8classdefP5tableT1(__1chk, __1no_virt, __2cl,
                                                                   __1tbl, cc->nof__11dcl_context);
                }
            }
        }
    }

    if ((__1fn && is_cl_obj__4typeFv(__1f->returns__3fct)) && (__1f->f_result__3fct == 0)) {
        make_res__FP3fct(__1f);
        tsizeof__4typeFi(__1f->returns__3fct, 0);
    }

    if (__1fn) {
        {
            {
                Pname __2nn;

                __2nn = __1f->argtype__3fct;

                for (; __2nn; __2nn = __2nn->__O1__4name.n_list)
                    if (is_cl_obj__4typeFv(__2nn->__O1__4expr.tp))
                        ((void)tsizeof__4typeFi(__2nn->__O1__4expr.tp, 0));
            }
        }
    }

    if (__1fn && (__1fn->n_dcl_printed__4name == 0)) {
        if ((__1f->f_inline__3fct == 0) && __1f->f_imeasure__3fct) {
            uninline__FP4name(__1fn);
        }

        dcl_print__4nameFUc(__1fn, (unsigned char)0);
    }

    if (__1no_virt && (__1f->f_static__3fct == 0)) {
        if ((__0this->__O2__4expr.e1->base__4node == 44) ||
            (__0this->__O2__4expr.e1->base__4node == 45))
            __0this->__O2__4expr.e1->__O3__4expr.n_initializer = (struct expr *)__1fn;
    } else
        __0this->__O4__4expr.fct_name = __1fn;

    if (__1f->f_this__3fct) {
        switch (__0this->__O2__4expr.e1->base__4node) {
            const void *__2__X121;

        case 173:
        case 44:
        case 45:
            break;
        default: {
            struct ea __0__V76;

            struct ea __0__V77;

            error__FPCcRC2eaN32(
                (const char *)"O orP missing for%n ofT %t",
                (const struct ea *)((__2__X121 = (const void *)__0this->__O4__4expr.fct_name),
                                    (((&__0__V76)->__O1__2ea.p = __2__X121), (&__0__V76))),
                (const struct ea *)(((&__0__V77)->__O1__2ea.p = ((const void *)__1f)), (&__0__V77)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        }
    } else if (__1fn) {
    sss:
        switch (__0this->__O2__4expr.e1->base__4node) {
        case 44:
        case 45:
        case 177:
            __0this->__O2__4expr.e1 = __0this->__O2__4expr.e1->__O4__4expr.mem;
            goto sss;
        }
    }

    if (__1fn)
        ((__1fn->n_used__4name++), (((void)0)));

    if ((((__1f->f_const__3fct == 0) && __0this->__O2__4expr.e1->__O1__4expr.tp) &&
         (!is_ptr__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp))) &&
        ((__1fn == 0) || ((__1fn->n_oper__4name != 161) && (__1fn->n_oper__4name != 162)))) {
        switch (__0this->__O2__4expr.e1->base__4node) {
        case 44: {
            Pptr __4p;
            __4p = (__0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp
                        ? is_ptr__4typeFv(__0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp)
                        : (((struct ptr *)0)));
            if (__4p && tconst__4typeFv(__4p->typ__5pvtyp)) {
                struct ea __0__V78;

                error__FPCcRC2eaN32(
                    (const char *)"non-constMF%n called for constO",
                    (const struct ea *)(((&__0__V78)->__O1__2ea.p = ((const void *)__1fn)),
                                        (&__0__V78)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            break;
        }
        case 45: {
            int __4tc;

            __4tc = (__0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp
                         ? (((int)tconst__4typeFv(
                               __0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp)))
                         : 0);
            if ((__0this->__O2__4expr.e1->__O1__4expr.tp && __4tc) &&
                ((!strict_opt) || (__4tc != 2))) {
                struct ea __0__V79;

                error__FPCcRC2eaN32(
                    (const char *)"non-constMF%n called for constO",
                    (const struct ea *)(((&__0__V79)->__O1__2ea.p = ((const void *)__1fn)),
                                        (&__0__V79)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            break;
        }
        case 173: {
            Pptr __4p;

            __4p = (__0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp
                        ? is_ptr__4typeFv(__0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp)
                        : (((struct ptr *)0)));
            if (__4p && tconst__4typeFv(__4p->typ__5pvtyp))
                error__FPCc((const char *)"non-constMF called for constO");

            break;
        }
        }
    }

    __1t = __1f->returns__3fct;
    __1x = __1f->nargs__3fct;
    __1k = __1f->nargs_known__3fct;

    __1e = __1arg;
    if (__1k == 0)
        goto rlab;

    for (((__1nn = __1f->argtype__3fct), (__1argno = 1)); __1e || __1nn;
         (((__1nn = __1nn->__O1__4name.n_list), (__1e = __1etail->__O3__4expr.e2)), (__1argno++))) {
        Pexpr __2a;
        int __2save_base;
        const char *__2save_name;
        bit __2mpt;

        __2save_base = 0;
        __2save_name = 0;
        __2mpt = ((__1nn && __1nn->__O1__4expr.tp) &&
                  memptr__4typeFv(skiptypedefs__4typeFv(__1nn->__O1__4expr.tp)));

        if (__1e) {
            __2a = __1e->__O2__4expr.e1;
            __1etail = __1e;

            if (__1nn) {
                Ptype __4t1;

                __4t1 = skiptypedefs__4typeFv(__1nn->__O1__4expr.tp);

                switch (__4t1->base__4node) {
                case 158: {
                    Ptype __6pt;

                    __6pt = (((struct ptr *)(((struct ptr *)__4t1))))->typ__5pvtyp;
                    if (skiptypedefs__4typeFv(__6pt)->base__4node == 110) {
                        if (check__4typeFP4typeUcT2(__6pt, __2a->__O1__4expr.tp, (unsigned char)254,
                                                    (unsigned char)0)) {
                            {
                                struct ea __0__V80;

                                struct ea __0__V81;

                                struct ea __0__V82;

                                struct ea __0__V83;

                                error__FPCcRC2eaN32(
                                    (const char *)"badA %dT for%n:%t (%tX)",
                                    (const struct ea *)(((((&__0__V80)->__O1__2ea.i =
                                                               ((unsigned long)__1argno)),
                                                          0)),
                                                        (&__0__V80)),
                                    (const struct ea *)(((&__0__V81)->__O1__2ea.p =
                                                             ((const void *)__1fn)),
                                                        (&__0__V81)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V82, (const void *)__2a->__O1__4expr.tp),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V83, (const void *)__1nn->__O1__4expr.tp));

                                return (struct type *)any_type;
                            }
                        }

                        ;
                    }
                    if ((__6pt->base__4node != 108) ||
                        check__4typeFP4typeUcT2(__6pt, __2a->__O1__4expr.tp, (unsigned char)0,
                                                (unsigned char)0)) {
                        is_arg = 1;
                        __2a = ref_init__FP3ptrP4exprP5table(
                            ((struct ptr *)(((struct ptr *)__1nn->__O1__4expr.tp))), __2a, __1tbl);
                        is_arg = 0;
                    }
                    goto cbcb;
                }
                case 119:
                    if ((__2a->base__4node != 147) ||
                        check__4typeFP4typeUcT2(__1nn->__O1__4expr.tp, __2a->__O1__4expr.tp,
                                                (unsigned char)70, (unsigned char)0))
                        __2a = class_init__FP4exprP4typeT1P5table((struct expr *)0, __4t1, __2a,
                                                                  __1tbl);
                    else if (__2a->__O3__4expr.e2->__O1__4expr.tp != __1nn->__O1__4expr.tp)
                        __2a->__O3__4expr.e2 = class_init__FP4exprP4typeT1P5table(
                            (struct expr *)0, __4t1, __2a->__O3__4expr.e2, __1tbl);
                    if (__1nn->n_xref__4name) {
                        __2a = address__4exprFv(__2a);
                    } else {
                        Pname __6cln;

                        struct classdef *__0__X122;

                        __6cln =
                            (((struct basetype *)(((struct basetype *)__4t1))))->b_name__8basetype;
                        if (__6cln && ((__0__X122 = (((struct classdef *)((
                                            (struct classdef *)__6cln->__O1__4expr.tp))))),
                                       (__0__X122->c_itor__8classdef))) {
                            __1nn->n_xref__4name = 1;
                            __2a = address__4exprFv(__2a);
                        }
                    }
                cbcb:
                    if (__2a->base__4node == 147) {
                        if (__2a->__O2__4expr.e1->base__4node == 111)
                            __2a->__O2__4expr.e1 = __2a->__O2__4expr.e1->__O3__4expr.e2;
                        if ((((__2a->__O2__4expr.e1->base__4node == 146) &&
                              (((struct name *)((
                                  (struct name *)__2a->__O2__4expr.e1->__O4__4expr.fct_name))))) &&
                             ((((struct name *)((
                                   (struct name *)__2a->__O2__4expr.e1->__O4__4expr.fct_name))))
                                  ->n_oper__4name == 161)) &&
                            ((__2a->__O3__4expr.e2->base__4node == 145) ||
                             (__2a->__O3__4expr.e2->base__4node == 112))) {
                            __2a = __2a->__O2__4expr.e1;

                            goto cccc;
                        } else if ((__2a->__O3__4expr.e2->base__4node == 145) &&
                                   (__2a->__O3__4expr.e2->__O3__4expr.e2->base__4node == 85)) {
                        cccc:
                            if ((__4t1->base__4node == 158) &&
                                (tconst__4typeFv(
                                     (((struct ptr *)(((struct ptr *)__4t1))))->typ__5pvtyp) ==
                                 0)) {
                                const void *__2__X123;

                                const void *__2__X124;

                                if (strict_opt) {
                                    struct ea __0__V84;

                                    error__FPCcRC2eaN32(
                                        (const char *)"temporary used for non-const%tA",
                                        (const struct ea *)((__2__X123 = (const void *)
                                                                             __1nn->__O1__4expr.tp),
                                                            (((&__0__V84)->__O1__2ea.p = __2__X123),
                                                             (&__0__V84))),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                } else {
                                    struct ea __0__V85;

                                    error__FiPCcRC2eaN33(
                                        (int)'w',
                                        (const char
                                             *)"temporary used for non-const%tA; no changes will "
                                               "be propagated to actual argument (anachronism)",
                                        (const struct ea *)((__2__X124 = (const void *)
                                                                             __1nn->__O1__4expr.tp),
                                                            (((&__0__V85)->__O1__2ea.p = __2__X124),
                                                             (&__0__V85))),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                            }
                        }
                    }
                    __1e->__O2__4expr.e1 = __2a;
                    break;
                case 141:
                    goto rlab;
                case 125: {
                    __2save_base = __1e->__O2__4expr.e1->base__4node;
                    if (__2a->__O1__4expr.tp->base__4node == 76)
                        __2save_name = (((struct gen *)(((struct gen *)__2a->__O1__4expr.tp))))
                                           ->fct_list__3gen->f__9name_list->__O2__4expr.string;
                    {
                        Pexpr __6te_a;

                        __6te_a = __2a;
                        __1e->__O2__4expr.e1 =
                            (__2a = ptr_init__FP3ptrP4exprP5table(
                                 ((struct ptr *)(((struct ptr *)__4t1))), __2a, __1tbl));
                        __1no_change = (__6te_a == __2a);
                        if (Pchecked == 0)
                            goto def;
                        break;
                    }
                }
                case 5:
                case 29:
                case 21: {
                    Ptype __6t;

                    __6t = skiptypedefs__4typeFv(__2a->__O1__4expr.tp);
                    switch (__6t->base__4node) {
                        const void *__2__X125;

                    case 22:
                    case 15:
                    case 11:
                    case 181:
                        if (!ambig) {
                            struct ea __0__V86;

                            struct ea __0__V87;

                            struct ea __0__V88;

                            error__FiPCcRC2eaN33(
                                (int)'w', (const char *)"A%d: %t passed as %t",
                                (const struct ea *)(((((&__0__V86)->__O1__2ea.i =
                                                           ((unsigned long)__1argno)),
                                                      0)),
                                                    (&__0__V86)),
                                (const struct ea *)((__2__X125 =
                                                         (const void *)__2a->__O1__4expr.tp),
                                                    (((&__0__V87)->__O1__2ea.p = __2__X125),
                                                     (&__0__V87))),
                                (const struct ea *)(((&__0__V88)->__O1__2ea.p =
                                                         ((const void *)__4t1)),
                                                    (&__0__V88)),
                                (const struct ea *)ea0);
                        }
                    }
                }

                case 22:
                    if (((((struct basetype *)(((struct basetype *)__4t1))))
                             ->b_unsigned__8basetype &&
                         (__2a->base__4node == 107)) &&
                        (__2a->__O3__4expr.e2->base__4node == 82)) {

                        struct ea __0__V89;

                        error__FiPCcRC2eaN33(
                            (int)'w', (const char *)"negativeA for%n, unsignedX",
                            (const struct ea *)(((&__0__V89)->__O1__2ea.p = ((const void *)__1fn)),
                                                (&__0__V89)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                default:
                def: {
                    Pexpr __6x;
                    int __6ct;

                    __6x = try_to_coerce__FP4typeP4exprPCcP5table(__4t1, __2a,
                                                                  (const char *)"argument", __1tbl);
                    __6ct = no_const;

                    if (__6x) {
                        if ((is_ptr__4typeFv(__4t1) && (Pchecked == 0)) && __1no_change) {
                            Pexpr __8te_x;

                            __8te_x = ptr_init__FP3ptrP4exprP5table(
                                ((struct ptr *)(((struct ptr *)__4t1))), __6x, __1tbl);

                            if (__8te_x != __6x)
                                __1e->__O2__4expr.e1 = (__2a = __8te_x);
                            else
                                __1e->__O2__4expr.e1 = __6x;
                        } else
                            __1e->__O2__4expr.e1 = __6x;
                    } else if (check__4typeFP4typeUcT2(__1nn->__O1__4expr.tp, __2a->__O1__4expr.tp,
                                                       (unsigned char)136, (unsigned char)0)) {

                        {
                            struct ea __0__V90;

                            struct ea __0__V91;

                            struct ea __0__V92;

                            struct ea __0__V93;

                            error__FiPCcRC2eaN33(
                                (int)'e', (const char *)"badA %dT for%n:%t (%tX)",
                                (const struct ea *)(((((&__0__V90)->__O1__2ea.i =
                                                           ((unsigned long)__1argno)),
                                                      0)),
                                                    (&__0__V90)),
                                (const struct ea *)(((&__0__V91)->__O1__2ea.p =
                                                         ((const void *)__1fn)),
                                                    (&__0__V91)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V92, (const void *)__2a->__O1__4expr.tp),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V93, (const void *)__1nn->__O1__4expr.tp));
                            if (__6ct)
                                error__FiPCc((int)'c',
                                             (const char *)" (no usable const conversion)\n");
                            else
                                error__FiPCc((int)'c', (const char *)"\n");
                            return (struct type *)any_type;
                        }
                    }
                }
                }

                {
                    Pexpr __4tt;

                    __4tt = __1e->__O2__4expr.e1;
                    while ((__4tt->base__4node == 113) || (__4tt->base__4node == 191))
                        __4tt = __4tt->__O2__4expr.e1;
                    if (__4tt->base__4node == 124)
                        __1e->__O2__4expr.e1 = __4tt;

                    if (__1e->__O2__4expr.e1->base__4node == 124) {
                        if (__2save_base == 44) {
                            Pptr __6m;

                            const void *__2__X126;

                            __6m = (((struct ptr *)(((struct ptr *)__2a->__O1__4expr.tp))));

                            {
                                struct ea __0__V94;

                                struct ea __0__V95;

                                struct ea __0__V96;

                                error__FPCcRC2eaN32(
                                    (const char *)"address of boundF (try using ``%s::*'' forPT "
                                                  "and ``&%s::%s'' for address)",
                                    (const struct ea *)((__2__X126 = (const void *)__6m->memof__3ptr
                                                                         ->string__8classdef),
                                                        (((&__0__V94)->__O1__2ea.p = __2__X126),
                                                         (&__0__V94))),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V95,
                                        (const void *)__6m->memof__3ptr->string__8classdef),
                                    (const struct ea *)(((&__0__V96)->__O1__2ea.p =
                                                             ((const void *)__2save_name)),
                                                        (&__0__V96)),
                                    (const struct ea *)ea0);
                            }
                        }
                        if (__2mpt) {
                            Pname __6temp;

                            __6temp =
                                make_tmp__FcP4typeP5table('A', (struct type *)mptr_type, __1tbl);
                            __1e->__O2__4expr.e1 = mptr_assign__FP4exprT1((struct expr *)__6temp,
                                                                          __1e->__O2__4expr.e1);
                            __1e->__O2__4expr.e1 =
                                (__2a = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                                               __1e->__O2__4expr.e1,
                                                               (struct expr *)__6temp));

                            __2a->__O1__4expr.tp = __6temp->__O1__4expr.tp;
                        } else {
                            Ptype __6t;

                            __6t = __1e->__O2__4expr.e1->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr
                                       .tp;
                            __1e->__O2__4expr.e1 =
                                __1e->__O2__4expr.e1->__O2__4expr.e1->__O2__4expr.e1;
                            __2a->__O1__4expr.tp = (__1e->__O2__4expr.e1->__O1__4expr.tp = __6t);
                        }
                    }
                }

            } else {
                if (__1k != 155) {
                    {
                        struct ea __0__V97;

                        struct ea __0__V98;

                        error__FPCcRC2eaN32(
                            (const char *)"unexpected %dA for%n",
                            (const struct ea *)(((((&__0__V97)->__O1__2ea.i =
                                                       ((unsigned long)__1argno)),
                                                  0)),
                                                (&__0__V97)),
                            (const struct ea *)(((&__0__V98)->__O1__2ea.p = ((const void *)__1fn)),
                                                (&__0__V98)),
                            (const struct ea *)ea0, (const struct ea *)ea0);

                        return (struct type *)any_type;
                    }
                }
                if (!check__4typeFP4typeUcT2(skiptypedefs__4typeFv(__2a->__O1__4expr.tp),
                                             (struct type *)void_type, (unsigned char)0,
                                             (unsigned char)0)) {
                    struct ea __0__V99;

                    struct ea __0__V100;

                    struct ea __0__V101;

                    error__FPCcRC2eaN32(
                        (const char *)"badA %dT for%n:%t",
                        (const struct ea *)(((((&__0__V99)->__O1__2ea.i =
                                                   ((unsigned long)__1argno)),
                                              0)),
                                            (&__0__V99)),
                        (const struct ea *)(((&__0__V100)->__O1__2ea.p = ((const void *)__1fn)),
                                            (&__0__V100)),
                        (const struct ea *)__ct__2eaFPCv(&__0__V101,
                                                         (const void *)__2a->__O1__4expr.tp),
                        (const struct ea *)ea0);
                }
                {
                    Pexpr __4te;

                    __4te = __1e;
                    while (__1e) {
                        if (__1e->__O1__4expr.tp)
                            tsizeof__4typeFi(__1e->__O1__4expr.tp, 0);
                        if (__1e->__O2__4expr.e1->base__4node == 124) {
                            Pname __6temp;

                            __6temp =
                                make_tmp__FcP4typeP5table('A', (struct type *)mptr_type, __1tbl);
                            __1e->__O2__4expr.e1 = mptr_assign__FP4exprT1((struct expr *)__6temp,
                                                                          __1e->__O2__4expr.e1);
                            __1e->__O2__4expr.e1 =
                                (__2a = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                                               __1e->__O2__4expr.e1,
                                                               (struct expr *)__6temp));

                            __2a->__O1__4expr.tp = __6temp->__O1__4expr.tp;
                        }
                        __1e = __1e->__O3__4expr.e2;
                    }
                    __1e = __4te;
                    goto rlab;
                }
            }
        } else {
            __2a = __1nn->__O3__4expr.n_initializer;
            if (__2a == 0) {
                const void *__2__X127;

                const void *__2__X128;

                if (__1fn == 0) {
                    struct ea __0__V102;

                    struct ea __0__V103;

                    error__FPCcRC2eaN32(
                        (const char *)"A %d ofT%tX for call",
                        (const struct ea *)(((((&__0__V102)->__O1__2ea.i =
                                                   ((unsigned long)__1argno)),
                                              0)),
                                            (&__0__V102)),
                        (const struct ea *)((__2__X127 = (const void *)__1nn->__O1__4expr.tp),
                                            (((&__0__V103)->__O1__2ea.p = __2__X127),
                                             (&__0__V103))),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                } else {
                    struct ea __0__V104;

                    struct ea __0__V105;

                    struct ea __0__V106;

                    error__FPCcRC2eaN32(
                        (const char *)"A %d ofT%tX for%n",
                        (const struct ea *)(((((&__0__V104)->__O1__2ea.i =
                                                   ((unsigned long)__1argno)),
                                              0)),
                                            (&__0__V104)),
                        (const struct ea *)((__2__X128 = (const void *)__1nn->__O1__4expr.tp),
                                            (((&__0__V105)->__O1__2ea.p = __2__X128),
                                             (&__0__V105))),
                        (const struct ea *)(((&__0__V106)->__O1__2ea.p = ((const void *)__1fn)),
                                            (&__0__V106)),
                        (const struct ea *)ea0);
                }
                return (struct type *)any_type;
            }
            if ((__2a->base__4node == 124) ||
                (((__2a->base__4node == 113) || (__2a->base__4node == 191)) &&
                 (__2a->__O2__4expr.e1->base__4node == 124))) {

                Pname __4temp;

                __4temp = make_tmp__FcP4typeP5table('A', (struct type *)mptr_type, __1tbl);
                if (__2a->base__4node != 124)
                    __2a = __2a->__O2__4expr.e1;
                __2a = mptr_assign__FP4exprT1((struct expr *)__4temp, __2a);
                __2a = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147, __2a,
                                              (struct expr *)__4temp);
                __2a->__O1__4expr.tp = __4temp->__O1__4expr.tp;
            }
            __2a->permanent__4node = 2;
            __1e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __2a,
                                          (struct expr *)0);
            if (__1etail)
                __1etail->__O3__4expr.e2 = __1e;
            else
                __0this->__O3__4expr.e2 = __1e;
            __1etail = __1e;
        }
    }

rlab:
    for (; __1e; __1e = __1e->__O3__4expr.e2) {
        Pexpr __2a;
        Pname __2cn;

        __2a = __1e->__O2__4expr.e1;

        if ((__2a->base__4node == 85) && (__2a->__O1__4expr.tp->base__4node == 108)) {
            lval__4exprFUc(__2a, (unsigned char)112);

        } else if (warning_opt && (__2cn = is_cl_obj__4typeFv(__2a->__O1__4expr.tp))) {
            Pclass __3cl;

            __3cl = (((struct classdef *)(((struct classdef *)__2cn->__O1__4expr.tp))));
            if ((__3cl->c_ctor__8classdef) ||
                look__5tableFPCcUc(__3cl->memtbl__8classdef, (const char *)"__as",
                                   (unsigned char)0)) {
                if (__0this->__O4__4expr.fct_name) {
                    struct ea __0__V107;

                    struct ea __0__V108;

                    struct ea __0__V109;

                    error__FiPCcRC2eaN33(
                        (int)'w', (const char *)"O ofC%t withK or = copied asA to%n (%t)",
                        (const struct ea *)(((&__0__V107)->__O1__2ea.p = ((const void *)__3cl)),
                                            (&__0__V107)),
                        (const struct ea *)__ct__2eaFPCv(
                            &__0__V108, (const void *)__0this->__O4__4expr.fct_name),
                        (const struct ea *)__ct__2eaFPCv(
                            &__0__V109,
                            (const void *)__0this->__O4__4expr.fct_name->__O1__4expr.tp),
                        (const struct ea *)ea0);
                } else {
                    struct ea __0__V110;

                    error__FiPCcRC2eaN33(
                        (int)'w', (const char *)"O ofC%t withK or = copied asA to `...'",
                        (const struct ea *)(((&__0__V110)->__O1__2ea.p = ((const void *)__3cl)),
                                            (&__0__V110)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
        } else if (is_ref__4typeFv(__2a->__O1__4expr.tp))
            __1e->__O2__4expr.e1 = contents__4exprFv(__2a);
    }

    if (__1f->f_result__3fct) {
        Pname __2oldNtmp;

        __2oldNtmp = Ntmp;
        Ntmp = 0;
        {
            Pname __2tn;

            extern bit in_quest;

            __2tn = make_tmp__FcP4typeP5table('R', __1f->returns__3fct, __1tbl);

            if (Ntmp) {
                if (Ntmp_refd && in_quest) {
                    __2tn->__O1__4name.n_list = Ntmp_refd;
                    Ntmp_refd = __2tn;
                } else
                    Ntmp_refd = __2tn;
            }

            if (__2oldNtmp)
                Ntmp = __2oldNtmp;

            if (Ntmp_refd && in_quest) {
                struct ival *__0__X129;

                Ntmp_flag = make_tmp__FcP4typeP5table('Q', (struct type *)int_type, __1tbl);
                Ntmp_flag->__O3__4expr.n_initializer =
                    (struct expr *)((__0__X129 = 0),
                                    (((__0__X129 || (__0__X129 = (struct ival *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct ival)))))
                                          ? ((__0__X129 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X129), (unsigned char)150,
                                                  (struct expr *)0, (struct expr *)0)),
                                             (__0__X129->__O2__4expr.i1 = ((long long)0L)))
                                          : 0),
                                     __0__X129));
                assign__4nameFv(Ntmp_flag);
                if (Ntmp_flag_list && in_quest) {
                    Ntmp_flag->__O1__4name.n_list = Ntmp_flag_list;
                    Ntmp_flag_list = Ntmp_flag;
                } else
                    Ntmp_flag_list = Ntmp_flag;
            }

            __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                             address__4exprFv((struct expr *)__2tn),
                                                             __0this->__O3__4expr.e2);
            {
                Pexpr __2ee;

                __2ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)0, (struct expr *)0,
                                               (struct expr *)0);
                ((*__2ee)) = (*__0this);
                __0this->base__4node = 147;
                __0this->__O2__4expr.e1 = __2ee;
                if (refd == 2)
                    __0this->__O3__4expr.e2 = address__4exprFv((struct expr *)__2tn);
                else
                    __0this->__O3__4expr.e2 = (struct expr *)__2tn;
                __0this->__O1__4expr.tp = __2tn->__O1__4expr.tp;
            }
        }
    }

    return __1t;
}

extern Pexpr ptof__FP3fctP4exprP5table(Pfct, Pexpr, Ptable);

extern Ptype unconst_type__FP4type(Ptype);

Pexpr ref_init__FP3ptrP4exprP5table(Pptr __1p, Pexpr __1init, Ptable __1tbl) {
    Ptype __1it;
    Pptr __1px;
    Ptype __1p1;
    Pname __1c1;

    __1it = skiptypedefs__4typeFv(__1init->__O1__4expr.tp);
    __1px = (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv((struct type *)__1p)))));
    __1p1 = __1px->typ__5pvtyp;
    __1c1 = is_cl_obj__4typeFv(__1p1);

    if (__1init->base__4node == 124)
        error__FPCc((const char *)"IrL as RIr");

    if (((__1init->base__4node == 85) &&
         ((((struct name *)(((struct name *)__1init))))->n_scope__4name == 136)) &&
        (__1init->__O1__4expr.tp->base__4node == 15))
        error__FiPCc((int)'w', (const char *)"initializing a float& with floatA is non-portable");

    {
        Ptype __1tt;

        __1tt = (struct type *)(__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __1it));
        __1px->base__4node = 125;

        {
            int __1x;

            __1x = check__4typeFP4typeUcT2((struct type *)__1px, __1tt, (unsigned char)78,
                                           (unsigned char)0);

            if (__1x == 0) {
                if ((tconst__4typeFv(__1init->__O1__4expr.tp) && (vec_const == 0)) &&
                    (fct_const == 0)) {
                    const void *__2__X142;

                    if (__1init->base__4node == 140)
                        __1init = __1init->__O2__4expr.e1;
                    if (tconst__4typeFv(__1px->typ__5pvtyp) == 0)
                        if (cc->nof__11dcl_context && in_return) {
                            struct ea __0__V130;

                            error__FPCcRC2eaN32(
                                (const char *)"cannot return a reference to a non-constO from "
                                              "const member function %n",
                                (const struct ea *)((__2__X142 =
                                                         (const void *)cc->nof__11dcl_context),
                                                    (((&__0__V130)->__O1__2ea.p = __2__X142),
                                                     (&__0__V130))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        } else
                            error__FPCc((const char *)"R to constO");
                    __1px->base__4node = 158;

                    ignore_const++;
                    if (lval__4exprFUc(__1init, (unsigned char)0)) {
                        lval__4exprFUc(__1init, (unsigned char)112);
                        ignore_const--;

                        return ptr_init__FP3ptrP4exprP5table(__1px, address__4exprFv(__1init),
                                                             __1tbl);
                    }
                    ignore_const--;
                    goto xxx;
                }
                __1px->base__4node = 158;
                if (lval__4exprFUc(__1init, (unsigned char)0)) {
                    lval__4exprFUc(__1init, (unsigned char)112);

                    {
                        Pname __4name_in_deref;
                        Pexpr __4act_param;

                        Pexpr __4ret_exp;

                        __4name_in_deref = 0;
                        __4act_param = 0;

                        __4ret_exp = 0;
                        if ((__1init->base__4node == 111) &&
                            (__1init->__O2__4expr.e1 &&
                             (__1init->__O2__4expr.e1->base__4node == 85))) {
                            __4name_in_deref =
                                (((struct name *)(((struct name *)__1init->__O2__4expr.e1))));
                        }

                        ;

                        if (__4name_in_deref && (__4name_in_deref->n_xref__4name &&
                                                 (__4name_in_deref->n_scope__4name == 136))) {
                            if (__1init->__O2__4expr.e1->__O1__4expr.tp) {
                                struct type *__0__X143;

                                __4act_param = __ct__4exprFUcP4exprT2(
                                    (struct expr *)0, (unsigned char)145, (struct expr *)0,
                                    __1init->__O2__4expr.e1);
                                __4act_param->__O1__4expr.tp =
                                    (struct type *)((__0__X143 =
                                                         __1init->__O2__4expr.e1->__O1__4expr.tp),
                                                    (__ct__3ptrFUcP4type((struct ptr *)0,
                                                                         (unsigned char)125,
                                                                         __0__X143)));

                                __4ret_exp =
                                    ptr_init__FP3ptrP4exprP5table(__1px, __4act_param, __1tbl);
                            } else {
                                {
                                    struct ea __0__V131;

                                    struct ea __0__V132;

                                    error__FPCcRC2eaN32(
                                        (const char *)"i",
                                        (const struct ea
                                             *)(((&__0__V131)->__O1__2ea.p =
                                                     ((const void *)"No type for actual param %n")),
                                                (&__0__V131)),
                                        (const struct ea *)(((&__0__V132)->__O1__2ea.p =
                                                                 ((const void *)__4name_in_deref)),
                                                            (&__0__V132)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                }
                            }
                        } else {
                            __4ret_exp = ptr_init__FP3ptrP4exprP5table(
                                __1px, address__4exprFv(__1init), __1tbl);
                        }

                        ;
                        return __4ret_exp;
                    }

                    ;
                }
                goto xxx;
            }

            __1px->base__4node = 158;

            if (__1c1) {
                ref_cast++;
                {
                    Pexpr __2x;

                    __2x = try_to_coerce__FP4typeP4exprPCcP5table(
                        (struct type *)__1p, __1init, (const char *)"reference initialization",
                        __1tbl);

                    ref_cast--;
                    if (__2x) {
                        __1init = __2x;
                        goto xxx;
                    }
                    if ((tconst__4typeFv(__1init->__O1__4expr.tp) && (!vec_const)) &&
                        (!tconst__4typeFv(__1p1))) {
                        error__FPCc((const char *)"R to constO");
                        return __1init;
                    }
                    switch (__1init->base__4node) {
                    case 81:
                    case 86:
                    case 84:
                    case 82:
                    case 83:
                    case 150:
                    case 85:
                        refd = 1;
                        break;
                    default:
                        refd = ((((__1init->__O2__4expr.e1 &&
                                   (__1init->__O2__4expr.e1->base__4node == 85)) &&
                                  (__1init->__O2__4expr.e1->__O1__4expr.tp->base__4node != 158)) &&
                                 ((((struct name *)(((struct name *)__1init->__O2__4expr.e1))))
                                      ->n_xref__4name == 0))
                                    ? 2
                                    : 1);
                        break;
                    }

                    {
                        Pexpr __2a;

                        __2a = class_init__FP4exprP4typeT1P5table((struct expr *)0, __1p1, __1init,
                                                                  __1tbl);
                        refd = 0;
                        if ((__2a == __1init) &&
                            (__1init->__O1__4expr.tp != (((struct type *)any_type))))
                            goto xxx;

                        switch (__2a->base__4node) {
                        case 146:
                            __1init = __2a;
                            goto xxx;
                        }
                        switch (__1init->base__4node) {
                        case 71:
                        case 147:
                            break;
                        case 85:
                        case 111:
                        case 44:
                        case 45:
                            if (((tconst__4typeFv(__1it) == 0) || vec_const) &&
                                ((fct_const == 0) || (is_ptr__4typeFv(__1p1) == 0)))
                                break;
                        default:
                            if (__1p1 && (__1p1->b_const__4type == 0)) {
                                const void *__2__X144;

                                if ((__1tbl == gtbl) || (strict_opt && (!is_arg))) {
                                    struct ea __0__V133;

                                    error__FPCcRC2eaN32(
                                        (const char *)"Ir for%snon-constR not an lvalue",
                                        (const struct ea
                                             *)((__2__X144 =
                                                     (const void *)(strict_opt
                                                                        ? ""
                                                                        : (((char *)" global ")))),
                                                (((&__0__V133)->__O1__2ea.p = __2__X144),
                                                 (&__0__V133))),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                } else if (!is_arg)
                                    error__FiPCc(
                                        (int)'w',
                                        (const char
                                             *)"Ir for non-constR not an lvalue (anachronism)");
                            }
                        }
                        __2a = address__4exprFv(__2a);
                        __2a = ptr_init__FP3ptrP4exprP5table(__1px, __2a, __1tbl);
                        return __2a;
                    }
                }
            }

            if (check__4typeFP4typeUcT2(__1p1, __1it, (unsigned char)0, (unsigned char)0)) {
                if (check__4typeFP4typeUcT2(__1p1, __1it, (unsigned char)70, (unsigned char)0) ==
                    0) {
                    goto def;
                }

                {
                    Pexpr __2x;

                    __2x = try_to_coerce__FP4typeP4exprPCcP5table(
                        __1p1, __1init, (const char *)"reference", __1tbl);
                    if (__2x == 0)
                        __2x = try_to_coerce__FP4typeP4exprPCcP5table(
                            (struct type *)__1px, __1init, (const char *)"reference", __1tbl);
                    if (__2x) {
                        __1init = __2x;
                        goto def;
                    }
                    {
                        int __2nc;

                        Pptr __2p1_ptr;

                        struct type *__1__Xt00anhfx544vcog;

                        __2nc = no_const;

                        __2p1_ptr = is_ptr__4typeFv(__1p1);

                        if ((__2p1_ptr &&
                             (skiptypedefs__4typeFv(__2p1_ptr->typ__5pvtyp)->base__4node == 108)) &&
                            ((__1__Xt00anhfx544vcog = skiptypedefs__4typeFv(__1it)),
                             (((__1__Xt00anhfx544vcog->base__4node == 125)
                                   ? ((__1__Xt00anhfx544vcog = skiptypedefs__4typeFv(
                                           (((struct ptr *)(((struct ptr *)__1__Xt00anhfx544vcog))))
                                               ->typ__5pvtyp)),
                                      0)
                                   : 0),
                              (((unsigned char)((__1__Xt00anhfx544vcog->base__4node ==
                                                 ((unsigned char)76))
                                                    ? 1
                                                    : 0)))))) {
                            Pexpr __3op;

                            __3op = ptof__FP3fctP4exprP5table(
                                ((struct fct *)((
                                    (struct fct *)skiptypedefs__4typeFv(__2p1_ptr->typ__5pvtyp)))),
                                __1init, __1tbl);

                            if (__3op) {
                                __1init = __3op;

                                goto def;
                            }
                        }

                        {
                            struct ea __0__V134;

                            struct ea __0__V135;

                            error__FiPCcRC2eaN33((int)'e', (const char *)"badIrT:%t (%tX)",
                                                 (const struct ea *)(((&__0__V134)->__O1__2ea.p =
                                                                          ((const void *)__1it)),
                                                                     (&__0__V134)),
                                                 (const struct ea *)(((&__0__V135)->__O1__2ea.p =
                                                                          ((const void *)__1p)),
                                                                     (&__0__V135)),
                                                 (const struct ea *)ea0, (const struct ea *)ea0);
                            if (__2nc)
                                error__FiPCc((int)'c',
                                             (const char *)" (no usable const conversion)\n");
                            else
                                error__FiPCc((int)'c', (const char *)"\n");
                            if (__1init->base__4node != 85)
                                __1init->__O1__4expr.tp = (struct type *)any_type;
                            return __1init;
                        }
                    }
                }
            }

        xxx:
            switch (__1init->base__4node) {
            case 85:
            case 111:
            case 44:
            case 45: {
                bit __3it_isconst;
                bit __3vec_const_save;
                bit __3fct_const_save;

                __3it_isconst = tconst__4typeFv(__1it);
                __3vec_const_save = vec_const;
                __3fct_const_save = fct_const;

                if (((__1init->base__4node == 85) &&
                     ((((struct name *)(((struct name *)__1init))))->n_stclass__4name == 13)) ||
                    ((((__3it_isconst &&
                        (((struct basetype *)(((struct basetype *)__1p->typ__5pvtyp))))) &&
                       (!tconst__4typeFv((struct type *)((
                           (struct basetype *)(((struct basetype *)__1p->typ__5pvtyp))))))) &&
                      (__3vec_const_save == 0)) &&
                     (__3fct_const_save == 0))) {
                    goto def;
                }
                lval__4exprFUc(__1init, (unsigned char)112);

                if (__3vec_const_save)
                    return __1init;
                if (__3fct_const_save && is_ptr__4typeFv(__1p1))
                    goto def;
            }

            case 71:
            case 147:
                return ptr_init__FP3ptrP4exprP5table(__1px, address__4exprFv(__1init), __1tbl);
            default:
            def: {
                if (__1p1 && (__1p1->b_const__4type == 0)) {
                    const void *__2__X145;

                    if ((__1tbl == gtbl) || (strict_opt && (!is_arg))) {
                        struct ea __0__V136;

                        error__FPCcRC2eaN32(
                            (const char *)"Ir for%snon-constR not an lvalue",
                            (const struct ea
                                 *)((__2__X145 =
                                         (const void *)(strict_opt ? "" : (((char *)" global ")))),
                                    (((&__0__V136)->__O1__2ea.p = __2__X145), (&__0__V136))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else if (!is_arg)
                        error__FiPCc((int)'w',
                                     (const char *)"Ir for non-constR not an lvalue (anachronism)");
                }

                {
                    Pname __3tcl;

                    __3tcl = is_cl_obj__4typeFv(__1p1);
                    if (__3tcl &&
                        (((struct classdef *)(((struct classdef *)__3tcl->__O1__4expr.tp))))
                            ->c_abstract__8classdef) {
                        const void *__2__X146;

                        const void *__2__X147;

                        {
                            struct ea __0__V137;

                            error__FPCcRC2eaN32(
                                (const char *)"a temporary is needed for a parameter, but the AT "
                                              "is abstractC %t.",
                                (const struct ea *)((__2__X146 =
                                                         (const void *)__3tcl->__O1__4expr.tp),
                                                    (((&__0__V137)->__O1__2ea.p = __2__X146),
                                                     (&__0__V137))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                            {
                                struct ea __0__V138;

                                struct ea __0__V139;

                                error__FiPCcRC2eaN33(
                                    (int)'C', (const char *)"%a is a pure virtualF ofC%t",
                                    (const struct ea
                                         *)((__2__X147 =
                                                 (const void *)(((struct classdef *)((
                                                                    (struct classdef *)
                                                                        __3tcl->__O1__4expr.tp))))
                                                     ->c_abstract__8classdef),
                                            (((&__0__V138)->__O1__2ea.p = __2__X147),
                                             (&__0__V138))),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V139, (const void *)__3tcl->__O1__4expr.tp),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                        }
                    }

                    no_sti = 1;
                    {
                        Pname __3n;

                        __3n = make_tmp__FcP4typeP5table('I', unconst_type__FP4type(__1p1), __1tbl);
                        no_sti = 0;
                        assign__4nameFv(__3n);
                        if (__1tbl == gtbl)
                            dcl_print__4nameFUc(__3n, (unsigned char)0);
                        {
                            Pexpr __3a;
                            Pname __3ic;

                            struct classdef *__1__X148;

                            struct classdef *__1__X149;

                            __3a = 0;
                            __3ic = is_cl_obj__4typeFv(__1init->__O1__4expr.tp);

                            switch (__1p1->base__4node) {
                            case 21:
                            case 5:
                            case 29:
                                switch (__1it->base__4node) {
                                case 22:
                                case 15:
                                case 11:
                                case 181: {

                                    struct ea __0__V140;

                                    struct ea __0__V141;

                                    error__FiPCcRC2eaN33(
                                        (int)'w', (const char *)"%t assigned to %t inRIr",
                                        (const struct ea *)(((&__0__V140)->__O1__2ea.p =
                                                                 ((const void *)__1it)),
                                                            (&__0__V140)),
                                        (const struct ea *)(((&__0__V141)->__O1__2ea.p =
                                                                 ((const void *)__1p1)),
                                                            (&__0__V141)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                }
                                }
                            }

                            if (((__3ic && __1c1) && (__3ic != __1c1)) &&
                                (!((__1__X148 = (((struct classdef *)((
                                        (struct classdef *)__3ic->__O1__4expr.tp))))),
                                   ((__1__X149 = (((struct classdef *)((
                                         (struct classdef *)__1c1->__O1__4expr.tp))))),
                                    (((__1__X148 == __1__X149)
                                          ? 1
                                          : ((__1__X148 && __1__X149)
                                                 ? (((int)same_class__8classdefFP8classdefi(
                                                       __1__X148, __1__X149, 0)))
                                                 : 0))))))) {
                                struct texpr *__0__X150;

                                __3n->__O1__4expr.tp = __1init->__O1__4expr.tp;
                                __3a = ptr_init__FP3ptrP4exprP5table(
                                    __1px, address__4exprFv((struct expr *)__3n), __1tbl);
                                __1p->permanent__4node = 1;
                                __3a =
                                    (struct expr *)((__0__X150 = 0),
                                                    (((__0__X150 ||
                                                       (__0__X150 = (struct texpr *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct texpr)))))
                                                          ? ((__0__X150 = (struct texpr *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X150),
                                                                      ((unsigned char)191), __3a,
                                                                      (struct expr *)0)),
                                                             (__0__X150->__O4__4expr.tp2 =
                                                                  ((struct type *)__1p)))
                                                          : 0),
                                                     __0__X150));
                                __3a->__O1__4expr.tp = (struct type *)__1p;
                            } else if ((((!__3ic) && (!__1c1)) &&
                                        is_ptr__4typeFv(__1init->__O1__4expr.tp)) &&
                                       is_ptr__4typeFv(__1p1)) {
                                Pname __4icx;

                                Pname __4c1x;

                                struct classdef *__1__X151;

                                struct classdef *__1__X152;

                                __4icx = is_cl_obj__4typeFv(
                                    (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv(
                                         __1init->__O1__4expr.tp)))))
                                        ->typ__5pvtyp);
                                __4c1x = is_cl_obj__4typeFv(
                                    (((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv(__1p1)))))
                                        ->typ__5pvtyp);
                                if (((__4icx && __4c1x) && (__4icx != __4c1x)) &&
                                    (!((__1__X151 = (((struct classdef *)((
                                            (struct classdef *)__4icx->__O1__4expr.tp))))),
                                       ((__1__X152 = (((struct classdef *)((
                                             (struct classdef *)__4c1x->__O1__4expr.tp))))),
                                        (((__1__X151 == __1__X152)
                                              ? 1
                                              : ((__1__X151 && __1__X152)
                                                     ? (((int)same_class__8classdefFP8classdefi(
                                                           __1__X151, __1__X152, 0)))
                                                     : 0))))))) {
                                    __1init = ptr_init__FP3ptrP4exprP5table(
                                        ((struct ptr *)((
                                            (struct ptr *)skiptypedefs__4typeFv(__1p1)))),
                                        __1init, __1tbl);
                                }
                            }
                            if (!__3a)
                                __3a = address__4exprFv((struct expr *)__3n);

                            refd = 1;
                            {
                                Pexpr __3as;
                                if (memptr__4typeFv(__1init->__O1__4expr.tp) ||
                                    ((__1init->__O1__4expr.tp->base__4node == 108) &&
                                     (((struct fct *)(((struct fct *)__1init->__O1__4expr.tp))))
                                         ->memof__3fct)) {

                                    Ptype __4pit;

                                    __4pit = skiptypedefs__4typeFv(__1p->typ__5pvtyp);
                                    __3as = mptr_assign__FP4exprT1(
                                        (struct expr *)__3n,
                                        ptof__FP3fctP4exprP5table(
                                            ((struct fct *)(((struct fct *)__4pit))), __1init,
                                            __1tbl));
                                } else {
                                    __3as = init_tmp__FP4nameP4exprP5table(__3n, __1init, __1tbl);
                                }
                                refd = 0;
                                __3a = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                                              __3as, __3a);
                                __3a->__O1__4expr.tp = __3a->__O3__4expr.e2->__O1__4expr.tp;
                                return __3a;
                            }
                        }
                    }
                }
            }
            }
        }
    }
}

extern Pexpr cast_cptr__FP8classdefP4exprP5tablei(Pclass __0ccl, Pexpr __0ee, Ptable __0tbl,
                                                  int __0real_cast);

Pexpr typ__4exprFP5table(struct expr *__0this, Ptable);

Pexpr class_init__FP4exprP4typeT1P5table(Pexpr __1nn, Ptype __1tt, Pexpr __1init, Ptable __1tbl) {
    if (__1init == dummy)
        return (struct expr *)0;

    {
        Pname __1c1;

        __1c1 = is_cl_obj__4typeFv(__1tt);

        if (__1init == 0) {
            error__FPCc((const char *)"emptyIr");
            return dummy;
        }

        if (__1c1) {
            Pclass __2cl;
            Pname __2c2;

            struct classdef *__1__X160;

            struct classdef *__1__X161;

            __2cl = (((struct classdef *)(((struct classdef *)__1c1->__O1__4expr.tp))));
            __2c2 = is_cl_obj__4typeFv(__1init->__O1__4expr.tp);

            if (((__1c1 != __2c2) &&
                 ((__2c2 == 0) ||
                  (((__1__X160 = __2cl),
                    ((__1__X161 =
                          (((struct classdef *)(((struct classdef *)__2c2->__O1__4expr.tp))))),
                     (((__1__X160 == __1__X161)
                           ? 1
                           : ((__1__X160 && __1__X161) ? (((int)same_class__8classdefFP8classdefi(
                                                             __1__X160, __1__X161, 1)))
                                                       : 0))))) == 0))) ||
                ((refd == 0) && (__2cl->c_itor__8classdef))) {
                int __3i;

                __3i = can_coerce__FP4typeT1(__1tt, __1init->__O1__4expr.tp);

                switch (__3i) {
                default: {
                    struct ea __0__V153;

                    struct ea __0__V154;

                    struct ea __0__V155;

                    error__FPCcRC2eaN32(
                        (const char *)"%d ways of making a%n from a%t",
                        (const struct ea *)(((((&__0__V153)->__O1__2ea.i = ((unsigned long)__3i)),
                                              0)),
                                            (&__0__V153)),
                        (const struct ea *)(((&__0__V154)->__O1__2ea.p = ((const void *)__1c1)),
                                            (&__0__V154)),
                        (const struct ea *)__ct__2eaFPCv(&__0__V155,
                                                         (const void *)__1init->__O1__4expr.tp),
                        (const struct ea *)ea0);
                    __1init->__O1__4expr.tp = (struct type *)any_type;
                    return __1init;
                case 0:
                    if (__2c2 &&
                        has_base__8classdefFP8classdefiT2(
                            ((struct classdef *)(((struct classdef *)__2c2->__O1__4expr.tp))),
                            __2cl, 0, 0)) {
                        __1init = address__4exprFv(__1init);
                        {
                            Pexpr __5x;

                            __5x = cast_cptr__FP8classdefP4exprP5tablei(__2cl, __1init, __1tbl, 0);

                            if (__5x == __1init) {
                                Ptype __6pt;

                                register struct cast *__0__X162;

                                __6pt = (struct type *)(__ct__3ptrFUcP4type(
                                    (struct ptr *)0, (unsigned char)125, __1tt));
                                __6pt->permanent__4node = 1;
                                __5x = (struct expr
                                            *)((__0__X162 = 0),
                                               (((__0__X162 ||
                                                  (__0__X162 = (struct cast *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct cast)))))
                                                     ? ((__0__X162 =
                                                             (struct cast *)__ct__4exprFUcP4exprT2(
                                                                 ((struct expr *)__0__X162),
                                                                 (unsigned char)191, __1init,
                                                                 (struct expr *)0)),
                                                        (__0__X162->__O1__4expr.tp =
                                                             (__0__X162->__O4__4expr.tp2 = __6pt)))
                                                     : 0),
                                                __0__X162));
                            }

                            return contents__4exprFv(__5x);
                        }
                    }
                    {
                        struct ea __0__V156;

                        struct ea __0__V157;

                        error__FPCcRC2eaN32(
                            (const char *)"cannot make a%t from a%t",
                            (const struct ea *)(((&__0__V156)->__O1__2ea.p = ((const void *)__2cl)),
                                                (&__0__V156)),
                            (const struct ea *)__ct__2eaFPCv(&__0__V157,
                                                             (const void *)__1init->__O1__4expr.tp),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                        __1init->__O1__4expr.tp = (struct type *)any_type;
                        return __1init;
                    case 1:
                        if (Ncoerce == 0) {
                            Pexpr __5a;

                            struct texpr *__0__X163;

                            struct type *__2__X164;

                            __5a = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                          __1init, (struct expr *)0);
                            __5a =
                                (struct expr *)((__0__X163 = 0),
                                                ((__2__X164 = skiptypedefs__4typeFv(__1tt)),
                                                 (((__0__X163 ||
                                                    (__0__X163 = (struct texpr *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct texpr)))))
                                                       ? ((__0__X163 = (struct texpr *)
                                                               __ct__4exprFUcP4exprT2(
                                                                   ((struct expr *)__0__X163),
                                                                   ((unsigned char)157), __5a,
                                                                   (struct expr *)0)),
                                                          (__0__X163->__O4__4expr.tp2 = __2__X164))
                                                       : 0),
                                                  __0__X163)));
                            __5a->__O3__4expr.e2 = __1nn;
                            __5a = typ__4exprFP5table(__5a, __1tbl);

                            return __5a;
                        }

                        switch (__1init->base__4node) {
                        case 71:
                        case 147:
                        case 85:
                        case 111: {
                            Pref __6r;
                            Pexpr __6rr;

                            struct ref *__0__X165;

                            struct expr *__2__X166;

                            struct expr *__2__X167;

                            __6r = ((__0__X165 = 0),
                                    ((__2__X166 = __1init),
                                     ((__2__X167 = (struct expr *)__ct__4nameFPCc(
                                           (struct name *)0, Ncoerce->__O2__4expr.string)),
                                      (((__0__X165 || (__0__X165 = (struct ref *)__nw__4exprSFUl(
                                                           (size_t)(sizeof(struct ref)))))
                                            ? ((__0__X165 = (struct ref *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X165), ((unsigned char)45),
                                                    __2__X166, (struct expr *)0)),
                                               (__0__X165->__O4__4expr.mem = __2__X167))
                                            : 0),
                                       __0__X165))));
                            __6rr = typ__4exprFP5table((struct expr *)__6r, __1tbl);
                            __1init = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)146,
                                                             __6rr, (struct expr *)0);
                            break;
                        }
                        default: {
                            Pname __6tmp;
                            int __6x;

                            __6tmp =
                                make_tmp__FcP4typeP5table('U', __1init->__O1__4expr.tp, __1tbl);
                            __6x = refd;
                            refd = 0;
                            {
                                Pexpr __6ass;

                                __6ass = init_tmp__FP4nameP4exprP5table(__6tmp, __1init, __1tbl);
                                refd = __6x;
                                {
                                    Pref __6r;
                                    Pexpr __6rr;
                                    Pexpr __6c;

                                    struct ref *__0__X168;

                                    struct expr *__2__X169;

                                    struct expr *__2__X170;

                                    __6r = ((__0__X168 = 0),
                                            ((__2__X169 = (struct expr *)__6tmp),
                                             ((__2__X170 = (struct expr *)__ct__4nameFPCc(
                                                   (struct name *)0, Ncoerce->__O2__4expr.string)),
                                              (((__0__X168 ||
                                                 (__0__X168 = (struct ref *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct ref)))))
                                                    ? ((__0__X168 =
                                                            (struct ref *)__ct__4exprFUcP4exprT2(
                                                                ((struct expr *)__0__X168),
                                                                ((unsigned char)45), __2__X169,
                                                                (struct expr *)0)),
                                                       (__0__X168->__O4__4expr.mem = __2__X170))
                                                    : 0),
                                               __0__X168))));
                                    __6rr = typ__4exprFP5table((struct expr *)__6r, __1tbl);
                                    __6c =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)146,
                                                               __6rr, (struct expr *)0);
                                    __6c = typ__4exprFP5table(__6c, __1tbl);
                                    __1init = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)71, __6ass, __6c);
                                    __1init->__O1__4expr.tp = __6c->__O1__4expr.tp;
                                    if (refd) {
                                        Pname __7tmp2;

                                        __7tmp2 = make_tmp__FcP4typeP5table(
                                            'L', __6c->__O1__4expr.tp, __1tbl);
                                        __6ass = init_tmp__FP4nameP4exprP5table(__7tmp2, __1init,
                                                                                __1tbl);
                                        __1init = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                         (unsigned char)147, __6ass,
                                                                         (struct expr *)__7tmp2);
                                    }
                                }
                            }
                        }
                        }

                        if (__1nn) {
                            Pexpr __5a;

                            struct texpr *__0__X171;

                            struct type *__2__X172;

                            __5a = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                          __1init, (struct expr *)0);
                            __5a =
                                (struct expr *)((__0__X171 = 0),
                                                ((__2__X172 = skiptypedefs__4typeFv(__1tt)),
                                                 (((__0__X171 ||
                                                    (__0__X171 = (struct texpr *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct texpr)))))
                                                       ? ((__0__X171 = (struct texpr *)
                                                               __ct__4exprFUcP4exprT2(
                                                                   ((struct expr *)__0__X171),
                                                                   ((unsigned char)157), __5a,
                                                                   (struct expr *)0)),
                                                          (__0__X171->__O4__4expr.tp2 = __2__X172))
                                                       : 0),
                                                  __0__X171)));
                            __5a->__O3__4expr.e2 = __1nn;
                            return typ__4exprFP5table(__5a, __1tbl);
                        }
                    }
                }
                }

                return typ__4exprFP5table(__1init, __1tbl);
            }
            return __1init;
        }

        if (check__4typeFP4typeUcT2(__1tt, __1init->__O1__4expr.tp, (unsigned char)70,
                                    (unsigned char)0) &&
            (refd == 0)) {

            const void *__2__X173;

            {
                struct ea __0__V158;

                struct ea __0__V159;

                error__FPCcRC2eaN32(
                    (const char *)"badIrT:%t (%tX)",
                    (const struct ea *)((__2__X173 = (const void *)__1init->__O1__4expr.tp),
                                        (((&__0__V158)->__O1__2ea.p = __2__X173), (&__0__V158))),
                    (const struct ea *)(((&__0__V159)->__O1__2ea.p = ((const void *)__1tt)),
                                        (&__0__V159)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                __1init->__O1__4expr.tp = (struct type *)any_type;
            }
        }

        return __1init;
    }
}

extern int bound;

void dcl__4typeFP5table(struct type *__0this, Ptable);

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);

Pexpr docast__4exprFP5table(register struct expr *__0this, Ptable __1tbl) {
    if (__0this->__O2__4expr.e1 == dummy) {
        error__FPCc((const char *)"E missing for cast");
        __0this->__O1__4expr.tp = (struct type *)any_type;
        return __0this;
    }

    {
        int __1pmf;
        int __1ptom_cast;
        int __1noconst;
        Pexpr __1ee;

        __1pmf = 0;
        __1ptom_cast = 0;
        __1noconst = 0;
        __1ee = __0this->__O2__4expr.e1;

        switch (__1ee->base__4node) {
        case 112:
            __1ee = __1ee->__O3__4expr.e2;
            switch (__1ee->base__4node) {
            case 85:
                goto nm;
            case 44:
                goto rf;
            }
            break;

        case 85:
        nm:
            if ((((struct name *)(((struct name *)__1ee))))->__O2__4name.n_qualifier)
                __1pmf = 1;
            break;

        case 44:
        rf:
            if (__1ee->__O2__4expr.e1->base__4node == 34)
                bound = 1;
            break;
        }

        __0this->__O2__4expr.e1 = typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);

        {
            int __1b;

            __1b = bound;
            bound = 0;

            __1pmf = (__1pmf && (((__0this->__O2__4expr.e1->base__4node == 113) ||
                                  (__0this->__O2__4expr.e1->base__4node == 191)) ||
                                 (__0this->__O2__4expr.e1->base__4node == 124)));

            {
                Ptype __1etp;
                Ptype __1tt;
                Ptype __1t;

                __1etp = skiptypedefs__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp);
                __1tt = __0this->__O4__4expr.tp2;
                __1t = __1tt;
                dcl__4typeFP5table(__1tt, __1tbl);

                __1tt = skiptypedefs__4typeFv(__1tt);

                {
                    bit __1isptm;

                    __1isptm = 0;
                    switch (__1etp->base__4node) {
                    case 125:
                        if (!memptr__4typeFv(__1etp))
                            break;
                        if (memptr__4typeFv(__1etp)->f_static__3fct)
                            break;
                        __1isptm = 1;
                        break;
                    case 108:
                        if (!(((struct fct *)(((struct fct *)__1etp))))->memof__3fct)
                            break;
                        if ((((struct fct *)(((struct fct *)__1etp))))->f_static__3fct)
                            break;
                        __1isptm = 1;
                        break;
                    case 124:
                        __1isptm = 1;
                        break;
                    }
                    if ((__1isptm && (!memptr__4typeFv(__1tt))) && (__1tt->base__4node != 38)) {
                        struct ea __0__V174;

                        error__FiPCcRC2eaN33(
                            strict_opt ? 0 : 119, (const char *)"cast to%t ofP toM (anachronism)",
                            (const struct ea *)(((&__0__V174)->__O1__2ea.p = ((const void *)__1tt)),
                                                (&__0__V174)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    switch (__1etp->base__4node) {
                    case 125:
                    case 158:
                        if ((((struct ptr *)(((struct ptr *)__1etp))))->typ__5pvtyp->base__4node ==
                            76)
                            goto over;

                        if (((((struct ptr *)(((struct ptr *)__1etp))))->typ__5pvtyp->base__4node ==
                             108) &&
                            (((struct fct *)((
                                 (struct fct *)(((struct ptr *)(((struct ptr *)__1etp))))
                                     ->typ__5pvtyp))))
                                ->fct_base__3fct)
                            goto over;
                        if ((warning_opt && (__0this->__O3__4expr.i2 == 0)) &&
                            tconst__4typeFv(
                                (((struct ptr *)(((struct ptr *)__1etp))))->typ__5pvtyp)) {
                            switch (__1tt->base__4node) {

                                const void *__2__X191;

                            case 108:
                                break;
                            case 125:
                            case 158:
                                if (tconst__4typeFv(
                                        (((struct ptr *)(((struct ptr *)__1tt))))->typ__5pvtyp))
                                    break;
                            default: {
                                struct ea __0__V175;

                                struct ea __0__V176;

                                error__FiPCcRC2eaN33(
                                    (int)'w', (const char *)"const cast away:%t->%t",
                                    (const struct ea *)((__2__X191 =
                                                             (const void *)__0this->__O2__4expr.e1
                                                                 ->__O1__4expr.tp),
                                                        (((&__0__V175)->__O1__2ea.p = __2__X191),
                                                         (&__0__V175))),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V176, (const void *)__0this->__O4__4expr.tp2),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            }
                        } else
                            __0this->__O3__4expr.i2 = 0;
                        break;
                    case 119: {
                        ref_cast = 1;
                        {
                            Pexpr __3x;

                            __3x = try_to_coerce__FP4typeP4exprPCcP5table(
                                __1tt, __0this->__O2__4expr.e1, (const char *)"cast", __1tbl);

                            if ((!__3x) && (__1tt->base__4node == 121))
                                __3x = try_to_coerce__FP4typeP4exprPCcP5table(
                                    (struct type *)int_type, __0this->__O2__4expr.e1,
                                    (const char *)"cast", __1tbl);
                            __1noconst = no_const;
                            ref_cast = 0;

                            if (__3x) {
                                register struct cast *__0__X192;

                                if (((__3x != __0this->__O2__4expr.e1) &&
                                     (__3x->base__4node == 111)) &&
                                    is_ref__4typeFv(__1tt))
                                    __3x = __3x->__O2__4expr.e1;
                                if (((__1tt == __3x->__O1__4expr.tp) ||
                                     (check__4typeFP4typeUcT2(__1tt, __3x->__O1__4expr.tp,
                                                              (unsigned char)0,
                                                              (unsigned char)0) == 0)) ||
                                    const_problem)
                                    return __3x;
                                else
                                    return (
                                        struct expr
                                            *)((__0__X192 = 0),
                                               (((__0__X192 ||
                                                  (__0__X192 = (struct cast *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct cast)))))
                                                     ? ((__0__X192 =
                                                             (struct cast *)__ct__4exprFUcP4exprT2(
                                                                 ((struct expr *)__0__X192),
                                                                 (unsigned char)191, __3x,
                                                                 (struct expr *)0)),
                                                        (__0__X192->__O1__4expr.tp =
                                                             (__0__X192->__O4__4expr.tp2 = __1tt)))
                                                     : 0),
                                                __0__X192));
                            }
                            break;
                        }
                    }
                    case 38:
                        if (__1tt->base__4node == 38) {
                            __0this->__O1__4expr.tp = __1t;
                            return __0this;
                        }
                        error__FPCc((const char *)"cast of void value");

                    case 141:
                    any:
                        __0this->__O1__4expr.tp = (struct type *)any_type;
                        return __0this;
                    case 108:
                        if ((__1tt->base__4node == 125) &&
                            ((((struct ptr *)(((struct ptr *)__1tt))))->typ__5pvtyp->base__4node !=
                             108))
                            error__FiPCc((int)'w', (const char *)"P toF cast toP to nonF");
                        if ((((struct fct *)(((struct fct *)__1etp))))->fct_base__3fct)
                            goto over;
                        break;
                    case 76:
                    over:
                        error__FPCc((const char *)"cast of overloaded");
                        goto any;
                    }

                    switch (__1tt->base__4node) {
                    case 110: {
                        struct ea __0__V177;

                        error__FPCcRC2eaN32(
                            (const char *)"cast to arrayT %t",
                            (const struct ea *)(((&__0__V177)->__O1__2ea.p = ((const void *)__1tt)),
                                                (&__0__V177)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        break;
                    case 125:
                        if (memptr__4typeFv(__1tt)) {
                            if ((memptr__4typeFv(__1etp) == 0) &&
                                ((__1etp->base__4node != 108) ||
                                 ((((struct fct *)(((struct fct *)__1etp))))->memof__3fct == 0))) {
                                if (__1etp->base__4node == 138) {
                                    __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)140, zero, zero);
                                    __0this->__O2__4expr.e1 =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)124,
                                                               __0this->__O2__4expr.e1, zero);
                                    __0this->__O2__4expr.e1->__O1__4expr.tp = __1tt;
                                    return __0this->__O2__4expr.e1;
                                }
                                {
                                    struct ea __0__V178;

                                    error__FPCcRC2eaN32(
                                        (const char *)"cast toP toM %t",
                                        (const struct ea *)(((&__0__V178)->__O1__2ea.p =
                                                                 ((const void *)__1tt)),
                                                            (&__0__V178)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                            } else {
                                __1ptom_cast = 1;
                                __0this->__O4__4expr.tp2 = (struct type *)mptr_type;
                            }
                        }

                        switch (__1etp->base__4node) {
                        case 119:
                            error__FiPCc((int)'e', (const char *)"cannot castCO toP");
                            if (__1noconst)
                                error__FiPCc((int)'c',
                                             (const char *)" (no usable const conversion)\n");
                            else
                                error__FiPCc((int)'c', (const char *)"\n");
                            break;
                        case 108:
                            __0this->__O2__4expr.e1 =
                                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145,
                                                       (struct expr *)0, __0this->__O2__4expr.e1);

                            bound = __1b;
                            __0this->__O2__4expr.e1 =
                                typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
                            bound = 0;
                            if ((__0this->__O2__4expr.e1->base__4node == 113) ||
                                (__0this->__O2__4expr.e1->base__4node == 191))
                                __1pmf = 1;
                            else
                                break;

                        case 158:
                        case 125: {
                            Pname __4cn;

                            __4cn = is_cl_obj__4typeFv(
                                (((struct ptr *)(((struct ptr *)__1tt))))->typ__5pvtyp);
                            if (__4cn) {
                                Pexpr __5x;

                                __5x = cast_cptr__FP8classdefP4exprP5tablei(
                                    ((struct classdef *)((
                                        (struct classdef *)__4cn->__O1__4expr.tp))),
                                    __0this->__O2__4expr.e1, __1tbl,
                                    (__0this->base__4node == 113) ? 1 : 0);

                                if (__5x == __0this->__O2__4expr.e1) {
                                    register struct cast *__0__X193;

                                    struct expr *__2__X194;

                                    __1tt->permanent__4node = 1;
                                    __0this->__O2__4expr.e1 =
                                        (struct expr
                                             *)((__0__X193 = 0),
                                                ((__2__X194 = __0this->__O2__4expr.e1),
                                                 (((__0__X193 ||
                                                    (__0__X193 = (struct cast *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct cast)))))
                                                       ? ((__0__X193 = (struct cast *)
                                                               __ct__4exprFUcP4exprT2(
                                                                   ((struct expr *)__0__X193),
                                                                   (unsigned char)191, __2__X194,
                                                                   (struct expr *)0)),
                                                          (__0__X193->__O1__4expr.tp =
                                                               (__0__X193->__O4__4expr.tp2 =
                                                                    __1tt)))
                                                       : 0),
                                                  __0__X193)));

                                    __0this->__O2__4expr.e1->__O3__4expr.i2 =
                                        __0this->__O3__4expr.i2;
                                } else
                                    __0this->__O2__4expr.e1 = __5x;
                            }
                            if (__1pmf) {
                                __1tt = skiptypedefs__4typeFv(__1tt);

                                switch (__1tt->base__4node) {
                                    const void *__2__X195;

                                case 125:
                                    if ((((struct ptr *)(((struct ptr *)__1tt))))->memof__3ptr)
                                        break;
                                default: {
                                    struct ea __0__V179;

                                    struct ea __0__V180;

                                    struct ea __0__V181;

                                    error__FPCcRC2eaN32(
                                        (const char *)"%t cast to%t (%t is not aP toM)",
                                        (const struct ea *)((__2__X195 =
                                                                 (const void *)__0this->__O2__4expr
                                                                     .e1->__O1__4expr.tp),
                                                            (((&__0__V179)->__O1__2ea.p =
                                                                  __2__X195),
                                                             (&__0__V179))),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V180, (const void *)__0this->__O4__4expr.tp2),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V181, (const void *)__0this->__O4__4expr.tp2),
                                        (const struct ea *)ea0);
                                }
                                }
                            }
                        }
                        }
                        break;

                    case 158: {
                        Ptype __3er;
                        Ptype __3cr;

                        __3er = __1etp;
                        __3cr = __1tt;
                        do {
                            if (__3er = (struct type *)is_ptr_or_ref__4typeFv(__3er))
                                __3er = (((struct ptr *)(((struct ptr *)__3er))))->typ__5pvtyp;
                            if (__3cr = (struct type *)is_ptr_or_ref__4typeFv(__3cr))
                                __3cr = (((struct ptr *)(((struct ptr *)__3cr))))->typ__5pvtyp;
                        } while (__3er && __3cr);

                        {
                            int __3pp;

                            __3pp = (__3er != 0);

                            if ((((__0this->__O2__4expr.e1->base__4node == 147) ||
                                  (__0this->__O2__4expr.e1->base__4node == 109)) ||
                                 (__0this->__O2__4expr.e1->base__4node == 146)) ||
                                lval__4exprFUc(__0this->__O2__4expr.e1, (unsigned char)0))
                                ;
                            else if (tconst__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp)) {
                                const void *__2__X196;

                                if (warning_opt &&
                                    (tconst__4typeFv(
                                         (((struct ptr *)(((struct ptr *)__1tt))))->typ__5pvtyp) ==
                                     0)) {
                                    struct ea __0__V182;

                                    struct ea __0__V183;

                                    error__FiPCcRC2eaN33(
                                        (int)'w', (const char *)"const cast away:%t->%t",
                                        (const struct ea *)((__2__X196 =
                                                                 (const void *)__0this->__O2__4expr
                                                                     .e1->__O1__4expr.tp),
                                                            (((&__0__V182)->__O1__2ea.p =
                                                                  __2__X196),
                                                             (&__0__V182))),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V183, (const void *)__0this->__O4__4expr.tp2),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                }
                            } else {
                                struct ea __0__V184;

                                struct ea __0__V185;

                                error__FPCcRC2eaN32(
                                    (const char *)"cannot cast%t to%t",
                                    (const struct ea *)(((&__0__V184)->__O1__2ea.p =
                                                             ((const void *)__1etp)),
                                                        (&__0__V184)),
                                    (const struct ea *)(((&__0__V185)->__O1__2ea.p =
                                                             ((const void *)__1t)),
                                                        (&__0__V185)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            if (__3pp == 0)
                                __0this->__O2__4expr.e1 = address__4exprFv(__0this->__O2__4expr.e1);
                            __0this->__O1__4expr.tp = __1t;

                            {
                                Pname __3cn;

                                __3cn = is_cl_obj__4typeFv(
                                    (((struct ptr *)(((struct ptr *)__1tt))))->typ__5pvtyp);
                                if (__3cn) {
                                    Pexpr __4x;

                                    __4x = cast_cptr__FP8classdefP4exprP5tablei(
                                        ((struct classdef *)((
                                            (struct classdef *)__3cn->__O1__4expr.tp))),
                                        __0this->__O2__4expr.e1, __1tbl,
                                        (__0this->base__4node == 113) ? 1 : 0);

                                    if (__4x == __0this->__O2__4expr.e1) {
                                        register struct cast *__0__X197;

                                        struct expr *__2__X198;

                                        __1tt->permanent__4node = 1;
                                        __0this->__O2__4expr.e1 =
                                            (struct expr
                                                 *)((__0__X197 = 0),
                                                    ((__2__X198 = __0this->__O2__4expr.e1),
                                                     (((__0__X197 ||
                                                        (__0__X197 = (struct cast *)__nw__4exprSFUl(
                                                             (size_t)(sizeof(struct cast)))))
                                                           ? ((__0__X197 = (struct cast *)
                                                                   __ct__4exprFUcP4exprT2(
                                                                       ((struct expr *)__0__X197),
                                                                       (unsigned char)191,
                                                                       __2__X198,
                                                                       (struct expr *)0)),
                                                              (__0__X197->__O1__4expr.tp =
                                                                   (__0__X197->__O4__4expr.tp2 =
                                                                        __1tt)))
                                                           : 0),
                                                      __0__X197)));

                                        __0this->__O2__4expr.e1->__O3__4expr.i2 =
                                            __0this->__O3__4expr.i2;
                                    } else
                                        __0this->__O2__4expr.e1 = __4x;
                                }

                                return (__3pp ? __0this : contents__4exprFv(__0this));
                            }
                        }
                    }
                    case 119:
                        __0this->base__4node = 157;
                        __0this->__O2__4expr.e1 =
                            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                   __0this->__O2__4expr.e1, (struct expr *)0);
                        return typ__4exprFP5table(__0this, __1tbl);

                    case 5:
                    case 21:
                    case 29:
                    case 22:
                    case 121:
                        switch (__1etp->base__4node) {
                            unsigned long __2__X199;

                        case 108:
                            __0this->__O2__4expr.e1 =
                                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)112,
                                                       (struct expr *)0, __0this->__O2__4expr.e1);

                            __0this->__O2__4expr.e1 =
                                typ__4exprFP5table(__0this->__O2__4expr.e1, __1tbl);
                        case 125:
                            if ((!memptr__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp)) &&
                                (tsizeof__4typeFi(__0this->__O2__4expr.e1->__O1__4expr.tp, 0) >
                                 tsizeof__4typeFi(__1tt, 0))) {
                                struct ea __0__V186;

                                struct ea __0__V187;

                                error__FPCcRC2eaN32(
                                    (const char
                                         *)"type ``%t'' not large enough for values of ``%t ''",
                                    (const struct ea *)(((&__0__V186)->__O1__2ea.p =
                                                             ((const void *)__1tt)),
                                                        (&__0__V186)),
                                    (const struct ea *)(((&__0__V187)->__O1__2ea.p =
                                                             ((const void *)__1etp)),
                                                        (&__0__V187)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            break;
                        case 119: {
                            struct ea __0__V188;

                            error__FiPCcRC2eaN33(
                                (int)'e', (const char *)"cannot castCO to%k",
                                (const struct ea *)((__2__X199 = __1tt->base__4node),
                                                    (((((&__0__V188)->__O1__2ea.i = __2__X199), 0)),
                                                     (&__0__V188))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                            if (__1noconst)
                                error__FiPCc((int)'c',
                                             (const char *)" (no usable const conversion)\n");
                            else
                                error__FiPCc((int)'c', (const char *)"\n");
                            break;
                        }
                        }
                        break;

                    case 15:
                    case 11:
                    case 181:
                        switch (__1etp->base__4node) {
                        case 15:
                        case 11:
                        case 181:
                        case 5:
                        case 21:
                        case 29:
                        case 22:
                        case 121:
                        case 138:
                            break;
                        default: {
                            struct ea __0__V189;

                            struct ea __0__V190;

                            error__FPCcRC2eaN32((const char *)"cannot cast ``%t '' to ``%t''",
                                                (const struct ea *)(((&__0__V189)->__O1__2ea.p =
                                                                         ((const void *)__1etp)),
                                                                    (&__0__V189)),
                                                (const struct ea *)(((&__0__V190)->__O1__2ea.p =
                                                                         ((const void *)__1tt)),
                                                                    (&__0__V190)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                            break;
                        }
                        }
                        break;

                    case 108:
                        error__FPCc((const char *)"cannot cast toFT");
                        break;
                    }
                    }

                    __0this->__O1__4expr.tp = __1t;

                    if ((__0this->__O2__4expr.e1->base__4node == 124) && (__1ptom_cast == 0)) {
                        Pexpr __2ee;
                        int __2i;

                        __2ee = __0this->__O2__4expr.e1->__O2__4expr.e1;

                        switch (__2ee->__O3__4expr.e2->base__4node) {
                        case 150:
                            __2i = (((int)__2ee->__O3__4expr.e2->__O2__4expr.i1));
                            break;
                        case 86:
                            __2i = 0;
                        }

                        if (__2i < 0)
                            __0this->__O2__4expr.e1 = __0this->__O2__4expr.e1->__O3__4expr.e2;
                        else
                            __0this->__O2__4expr.e1 = __2ee->__O3__4expr.e2;
                        return __0this;
                    }

                    if (memptr__4typeFv(__1etp)) {
                        Pclass __2cl;

                        __2cl = (((struct ptr *)(((struct ptr *)__1etp))))->memof__3ptr;

                        if (((((struct ptr *)(((struct ptr *)__1tt))))->memof__3ptr == 0) &&
                            (__1b == 0)) {
                            Pexpr __3y;

                            register struct cast *__0__X202;

                            if (((__0this->__O2__4expr.e1->base__4node == 191) ||
                                 (__0this->__O2__4expr.e1->base__4node == 113)) &&
                                (__0this->__O2__4expr.e1->__O2__4expr.e1->base__4node == 124)) {

                                __0this->__O2__4expr.e1 = __0this->__O2__4expr.e1->__O2__4expr.e1;
                                __3y = __0this->__O2__4expr.e1->__O3__4expr.e2;
                            } else {
                                register struct mdot *__0__X200;

                                struct expr *__2__X201;

                                __3y =
                                    (struct expr
                                         *)((__0__X200 = 0),
                                            ((__2__X201 = __0this->__O2__4expr.e1),
                                             (((__0__X200 ||
                                                (__0__X200 = (struct mdot *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct mdot)))))
                                                   ? ((__0__X200 =
                                                           (struct mdot *)__ct__4exprFUcP4exprT2(
                                                               ((struct expr *)__0__X200),
                                                               (unsigned char)177, (struct expr *)0,
                                                               (struct expr *)0)),
                                                      ((__0__X200->__O3__4expr.string2 =
                                                            ((const char *)"f")),
                                                       (__0__X200->__O4__4expr.mem = __2__X201)))
                                                   : 0),
                                              __0__X200)));
                                __3y->__O2__4expr.i1 = 9;
                            }
                            __3y =
                                (struct expr
                                     *)((__0__X202 = 0),
                                        (((__0__X202 || (__0__X202 = (struct cast *)__nw__4exprSFUl(
                                                             (size_t)(sizeof(struct cast)))))
                                              ? ((__0__X202 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                      ((struct expr *)__0__X202),
                                                      (unsigned char)191, __3y, (struct expr *)0)),
                                                 (__0__X202->__O1__4expr.tp =
                                                      (__0__X202->__O4__4expr.tp2 = __1tt)))
                                              : 0),
                                         __0__X202));
                            if (__2cl->virt_count__8classdef && (__1b == 0)) {
                                Pexpr __4z;
                                Pexpr __4x;

                                register struct cast *__0__X203;

                                register struct mdot *__0__X204;

                                struct expr *__2__X205;

                                register struct mdot *__0__X206;

                                struct expr *__2__X207;

                                __4z =
                                    (struct expr
                                         *)((__0__X204 = 0),
                                            ((__2__X205 = __0this->__O2__4expr.e1),
                                             (((__0__X204 ||
                                                (__0__X204 = (struct mdot *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct mdot)))))
                                                   ? ((__0__X204 =
                                                           (struct mdot *)__ct__4exprFUcP4exprT2(
                                                               ((struct expr *)__0__X204),
                                                               (unsigned char)177, (struct expr *)0,
                                                               (struct expr *)0)),
                                                      ((__0__X204->__O3__4expr.string2 =
                                                            ((const char *)"i")),
                                                       (__0__X204->__O4__4expr.mem = __2__X205)))
                                                   : 0),
                                              __0__X204)));
                                __4x =
                                    (struct expr
                                         *)((__0__X206 = 0),
                                            ((__2__X207 = __0this->__O2__4expr.e1),
                                             (((__0__X206 ||
                                                (__0__X206 = (struct mdot *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct mdot)))))
                                                   ? ((__0__X206 =
                                                           (struct mdot *)__ct__4exprFUcP4exprT2(
                                                               ((struct expr *)__0__X206),
                                                               (unsigned char)177, (struct expr *)0,
                                                               (struct expr *)0)),
                                                      ((__0__X206->__O3__4expr.string2 =
                                                            ((const char *)"i")),
                                                       (__0__X206->__O4__4expr.mem = __2__X207)))
                                                   : 0),
                                              __0__X206)));
                                __4x->__O2__4expr.i1 = 9;
                                __4x = (struct expr
                                            *)((__0__X203 = 0),
                                               (((__0__X203 ||
                                                  (__0__X203 = (struct cast *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct cast)))))
                                                     ? ((__0__X203 =
                                                             (struct cast *)__ct__4exprFUcP4exprT2(
                                                                 ((struct expr *)__0__X203),
                                                                 (unsigned char)191, __4x,
                                                                 (struct expr *)0)),
                                                        (__0__X203->__O1__4expr.tp =
                                                             (__0__X203->__O4__4expr.tp2 = __1tt)))
                                                     : 0),
                                                __0__X203));
                                __4z->__O2__4expr.i1 = 9;
                                {
                                    Pexpr __4q;

                                    __4q = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                  (unsigned char)68, __4x, __3y);
                                    __4q->__O4__4expr.cond = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)59, zero, __4z);
                                    __4q->__O1__4expr.tp = __1tt;
                                    ((__0this
                                          ? (((void)(__0this
                                                         ? (((void)(((void)__dl__4exprSFPvUl(
                                                               (void *)__0this,
                                                               (size_t)(sizeof(struct expr)))))))
                                                         : (((void)0)))))
                                          : (((void)0))));
                                    return __4q;
                                }
                            }
                            ((__0this ? (((void)(__0this ? (((void)(((void)__dl__4exprSFPvUl(
                                                               (void *)__0this,
                                                               (size_t)(sizeof(struct expr)))))))
                                                         : (((void)0)))))
                                      : (((void)0))));
                            return __3y;
                        }
                    }

                    return __0this;
                }
            }
        }
    }
}

void clear__5clistFv(struct clist *__0this);

extern int is_unique_base__FP8classdefPCciT3T1(Pclass, const char *, int, int, Pclass __0priSeen);

Pexpr dovalue__4exprFP5table(register struct expr *__0this, Ptable __1tbl) {
    Ptype __1tt;
    Pclass __1cl;
    Pname __1cn;

    __1tt = __0this->__O4__4expr.tp2;

    dcl__4typeFP5table(__1tt, __1tbl);

    __1tt = skiptypedefs__4typeFv(__1tt);

    switch (__1tt->base__4node) {
    case 121:
    default:
        if (__0this->__O2__4expr.e1 == 0) {
            __0this->__O2__4expr.e1 = zero;
        } else {
            if (__0this->__O2__4expr.e1->__O3__4expr.e2 == 0) {
                __0this->__O2__4expr.e1 = __0this->__O2__4expr.e1->__O2__4expr.e1;
                if ((__0this->__O2__4expr.e1->base__4node == 85) &&
                    (__0this->__O2__4expr.e1->permanent__4node == 0))
                    __0this->__O2__4expr.e1->permanent__4node = 1;
            } else {
                error__FPCc((const char *)"more than oneA for basicTK");
                {
                    Pexpr __4e;

                    __4e = __0this->__O2__4expr.e1;
                    for (; __4e->__O3__4expr.e2->__O3__4expr.e2; __4e = __4e->__O3__4expr.e2)
                        __4e->base__4node = 71;
                    __4e->base__4node = 71;
                    __4e->__O3__4expr.e2 = __4e->__O3__4expr.e2->__O2__4expr.e1;
                }
            }
        }
        __0this->base__4node = 191;
        return typ__4exprFP5table(__0this, __1tbl);

    case 6:
        __1cl = (((struct classdef *)(((struct classdef *)__1tt))));
        if (__1cl->this_type__8classdef)
            __0this->__O4__4expr.tp2 =
                (((struct ptr *)(((struct ptr *)__1cl->this_type__8classdef))))->typ__5pvtyp;
        break;

    case 119:
        __1cn = (((struct basetype *)(((struct basetype *)__1tt))))->b_name__8basetype;
        __1cl = (((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))));
    }

    {
        Pname __1ctor;

        __1ctor = (__1cl->c_ctor__8classdef);

        if (__0this->__O2__4expr.e1 && (__0this->__O2__4expr.e1->__O3__4expr.e2 == 0)) {
            if (__0this->__O2__4expr.e1->__O2__4expr.e1->base__4node == 140)
                __0this->__O2__4expr.e1->__O2__4expr.e1 =
                    __0this->__O2__4expr.e1->__O2__4expr.e1->__O2__4expr.e1;
            __0this->__O2__4expr.e1->__O2__4expr.e1 =
                typ__4exprFP5table(__0this->__O2__4expr.e1->__O2__4expr.e1, __1tbl);
            if (__1tt->base__4node == 119) {
                Pexpr __3x;

                __3x = try_to_coerce__FP4typeP4exprPCcP5table(
                    __1tt, __0this->__O2__4expr.e1->__O2__4expr.e1, (const char *)"type conversion",
                    __1tbl);
                if ((__1cl->c_itor__8classdef) == 0) {
                    if (__3x)
                        return __3x;
                } else {
                    if (__3x && (__3x->base__4node != 111))
                        return __3x;
                }
            }

            {
                Pname __2acn;

                __2acn =
                    is_cl_obj__4typeFv(__0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp);

                if (__2acn && ((__1cl->c_itor__8classdef) == 0)) {
                    Pclass __3acl;
                    int __3hb;

                    struct classdef *__1__X210;

                    struct classdef *__1__X211;

                    __3acl = (((struct classdef *)(((struct classdef *)__2acn->__O1__4expr.tp))));
                    __3hb = has_base__8classdefFP8classdefiT2(__3acl, __1cl, 0, 0);

                    if (__1ctor && __3hb) {
                        Pname __4n;

                        __4n = 0;
                        switch (__1ctor->__O1__4expr.tp->base__4node) {
                        case 76:
                            __4n = exactMatch__3genFP4expri(
                                ((struct gen *)(((struct gen *)__1ctor->__O1__4expr.tp))),
                                __0this->__O2__4expr.e1, 0);
                            if (__4n)
                                __1ctor = __4n;
                            break;
                        case 108: {
                            Pfct __6f;

                            __6f = (((struct fct *)(((struct fct *)__1ctor->__O1__4expr.tp))));
                            if (__6f->nargs__3fct != 1)
                                break;
                            __4n = (exact1__FP4nameP4type(
                                        __6f->argtype__3fct,
                                        __0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp)
                                        ? __1ctor
                                        : (((struct name *)0)));
                            break;
                        }
                        }
                        if (__4n)
                            goto mk_ctor_call;
                    }

                    if (((__1__X210 = __3acl),
                         ((__1__X211 = __1cl),
                          (((__1__X210 == __1__X211)
                                ? 1
                                : ((__1__X210 && __1__X211)
                                       ? (((int)same_class__8classdefFP8classdefi(__1__X210,
                                                                                  __1__X211, 0)))
                                       : 0))))) ||
                        __3hb) {
                        clear__5clistFv(vcllist);
                        vcllist = 0;
                        if (1 < is_unique_base__FP8classdefPCciT3T1(
                                    __3acl, __1cl->string__8classdef, 0, 0, (struct classdef *)0)) {
                            struct ea __0__V208;

                            error__FPCcRC2eaN32((const char *)"ambiguous assignment to base %t",
                                                (const struct ea *)(((&__0__V208)->__O1__2ea.p =
                                                                         ((const void *)__1cl)),
                                                                    (&__0__V208)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        }
                        {
                            Pexpr __4ee;

                            __4ee = __0this->__O2__4expr.e1->__O2__4expr.e1;
                            if (__4ee->base__4node == 140)
                                __4ee = __4ee->__O2__4expr.e1;
                            if (__3hb) {
                                struct texpr *__0__X212;

                                struct type *__2__X213;

                                ignore_const++;
                                if (lval__4exprFUc(__4ee, (unsigned char)0) == 0) {
                                    Pname __6tmp;

                                    __6tmp = make_tmp__FcP4typeP5table('T', __4ee->__O1__4expr.tp,
                                                                       __1tbl);
                                    __4ee = init_tmp__FP4nameP4exprP5table(__6tmp, __4ee, __1tbl);
                                    __4ee = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)147, __4ee,
                                        address__4exprFv((struct expr *)__6tmp));
                                } else
                                    __4ee = address__4exprFv(__4ee);
                                ignore_const--;
                                __4ee =
                                    (struct expr
                                         *)((__0__X212 = 0),
                                            ((__2__X213 = (struct type *)__ct__3ptrFUcP4type(
                                                  (struct ptr *)0, (unsigned char)125,
                                                  __0this->__O4__4expr.tp2)),
                                             (((__0__X212 ||
                                                (__0__X212 = (struct texpr *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct texpr)))))
                                                   ? ((__0__X212 =
                                                           (struct texpr *)__ct__4exprFUcP4exprT2(
                                                               ((struct expr *)__0__X212),
                                                               ((unsigned char)191), __4ee,
                                                               (struct expr *)0)),
                                                      (__0__X212->__O4__4expr.tp2 = __2__X213))
                                                   : 0),
                                              __0__X212)));
                                __4ee = contents__4exprFv(__4ee);
                                typ__4exprFP5table(__4ee, __1tbl);
                            }

                            if (__0this->__O3__4expr.e2) {
                                __0this->base__4node = 70;
                                __0this->__O2__4expr.e1 = __0this->__O3__4expr.e2;
                                __0this->__O3__4expr.e2 = __4ee;
                                __0this->__O1__4expr.tp = __0this->__O4__4expr.tp2;
                                return __0this;
                            }
                            return __4ee;
                        }
                    }
                }
            }
        }

        if (__1ctor == 0) {
            {
                struct ea __0__V209;

                error__FPCcRC2eaN32(
                    (const char *)"cannot make a%t",
                    (const struct ea *)(((&__0__V209)->__O1__2ea.p = ((const void *)__1cl)),
                                        (&__0__V209)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                return dummy;
            }
        }

    mk_ctor_call:
        if (__0this->__O3__4expr.e2 == 0) {
            if ((__0this->__O2__4expr.e1 && __0this->__O2__4expr.e1->__O2__4expr.e1) &&
                (!__0this->__O2__4expr.e1->__O3__4expr.e2)) {
                const char *__3s;

                __3s = __0this->__O2__4expr.e1->__O2__4expr.e1->__O2__4expr.string;
                if ((((((__3s && ((__3s[0]) == '_')) && ((__3s[1]) == '_')) &&
                       ((__3s[2]) == 'V')) &&
                      __0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp) &&
                     __0this->__O4__4expr.tp2) &&
                    (!check__4typeFP4typeUcT2(
                        __0this->__O2__4expr.e1->__O2__4expr.e1->__O1__4expr.tp,
                        __0this->__O4__4expr.tp2, (unsigned char)0, (unsigned char)0)))
                    return __0this->__O2__4expr.e1;
            }
            no_sti = 1;
            Ntmp = 0;
            {
                Pname __2n;

                __2n = make_tmp__FcP4typeP5table('V', __0this->__O4__4expr.tp2, __1tbl);
                no_sti = 0;
                assign__4nameFv(__2n);
                if (__1tbl == gtbl)
                    dcl_print__4nameFUc(__2n, (unsigned char)0);
                {
                    Pexpr __2c;
                    extern bit in_quest;

                    __2c = call_ctor__FP5tableP4exprN22iT2(
                        __1tbl, (struct expr *)__2n, (struct expr *)__1ctor,
                        __0this->__O2__4expr.e1, 45, (struct expr *)0);

                    if (Ntmp && in_quest) {
                        struct ival *__0__X214;

                        if (Ntmp_refd) {
                            __2n->__O1__4name.n_list = Ntmp_refd;
                            Ntmp_refd = __2n;
                        } else
                            Ntmp_refd = __2n;

                        Ntmp_flag = make_tmp__FcP4typeP5table('Q', (struct type *)int_type, __1tbl);
                        Ntmp_flag->__O3__4expr.n_initializer =
                            (struct expr
                                 *)((__0__X214 = 0),
                                    (((__0__X214 || (__0__X214 = (struct ival *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct ival)))))
                                          ? ((__0__X214 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X214), (unsigned char)150,
                                                  (struct expr *)0, (struct expr *)0)),
                                             (__0__X214->__O2__4expr.i1 = ((long long)0L)))
                                          : 0),
                                     __0__X214));
                        assign__4nameFv(Ntmp_flag);

                        if (Ntmp_flag_list) {
                            Ntmp_flag->__O1__4name.n_list = Ntmp_flag_list;
                            Ntmp_flag_list = Ntmp_flag;
                        } else
                            Ntmp_flag_list = Ntmp_flag;

                        {
                            Pexpr __3e;

                            __3e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                          (struct expr *)Ntmp_flag, one);
                            __3e->__O1__4expr.tp = (struct type *)int_type;
                            {
                                Ptype __3t;

                                __3t = __2c->__O1__4expr.tp;
                                Ntmp_flag = 0;
                                __2c = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                                              __3e, __2c);
                                __2c->__O1__4expr.tp = __3t;
                            }
                        }
                    }

                    __2c = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147, __2c,
                                                  (struct expr *)__2n);
                    __2c->__O1__4expr.tp = __2n->__O1__4expr.tp;
                    return __2c;
                }
            }
        } else {
            Pexpr __2c;

            __2c = call_ctor__FP5tableP4exprN22iT2(__1tbl, __0this->__O3__4expr.e2,
                                                   (struct expr *)__1ctor, __0this->__O2__4expr.e1,
                                                   45, (struct expr *)0);
            __2c = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111, __2c,
                                          (struct expr *)0);
            __2c->__O1__4expr.tp = __2c->__O2__4expr.e1->__O1__4expr.tp;
            return __2c;
        }
    }
}

struct Bits *__ct__4BitsFUlT1(struct Bits *__0this, Bits_chunk, size_t);

extern void __co__FRC4Bits(struct Bits *__0_result, const struct Bits *);

static Pname breakTie__FRC11Block_PnameR4BitsP4expri(const struct Block_Pname *, struct Bits *,
                                                     Pexpr, int);

Pname exactMatch__3genFP4expri(register struct gen *__0this, Pexpr __1arg, int __1constObj) {
    struct name *__0_result;

    if (((__0this->holds_templ__3gen == 2)))
        return (struct name *)0;
    {
        Plist __1gl;
        int __1ok;
        struct Block_Pname __1funVec;

        int __1numEx;

        (((((&__1funVec)->n__11Block_Pname = 0), ((&__1funVec)->p__11Block_Pname = 0))),
         (&__1funVec));

        __1numEx = 0;
        for (__1gl = __0this->fct_list__3gen; __1gl; __1gl = __1gl->l__9name_list) {
            Pname __2nn;

            __2nn = __1gl->f__9name_list;
            if ((__2nn->n_template_fct__4name))
                continue;
            {
                Pfct __2f;
                Pname __2n;

                int __2__X217;

                unsigned long __2__X16;

                struct ea __0__X__V1400qmhwx544vcnm;

                struct ea __0__X__V1500qmhwx544vcnm;

                __2f = ((
                    (__2nn->__O1__4expr.tp->base__4node == 108)
                        ? (((struct fct *)(((struct fct *)__2nn->__O1__4expr.tp))))
                        : (error__FiPCcRC2eaN33(
                               (int)'i', (const char *)"N::fct_type():%n is %k notF",
                               (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)->__O1__2ea.p =
                                                        ((const void *)__2nn)),
                                                   (&__0__X__V1400qmhwx544vcnm)),
                               (const struct ea *)((__2__X16 = __2nn->__O1__4expr.tp->base__4node),
                                                   (((((&__0__X__V1500qmhwx544vcnm)->__O1__2ea.i =
                                                           __2__X16),
                                                      0)),
                                                    (&__0__X__V1500qmhwx544vcnm))),
                               (const struct ea *)ea0, (const struct ea *)ea0),
                           (((struct fct *)0)))));
                __2n = __2f->argtype__3fct;
                if (((__1constObj && (__2nn->n_oper__4name != 161)) && (!__2f->f_const__3fct)) &&
                    (!__2f->f_static__3fct)) {
                    non_const++;
                    continue;
                }
                __1ok = 0;
                if (!__1arg)
                    __1ok = 1;
                else {
                    {
                        {
                            Pexpr __3e;

                            __3e = __1arg;

                            for (; __3e; ((__3e = __3e->__O3__4expr.e2),
                                          (__2n = __2n->__O1__4name.n_list))) {
                                if ((!__2n) && (__2f->nargs_known__3fct != 155))
                                    break;
                                {
                                    Pexpr __4a;
                                    Ptype __4at;

                                    __4a = __3e->__O2__4expr.e1;
                                    __4at = __4a->__O1__4expr.tp;
                                    if (__4at->base__4node == 141)
                                        break;
                                    if (__4at->base__4node == 138)
                                        __4at = (struct type *)int_type;
                                    if (!exact1__FP4nameP4type(__2n, __4at))
                                        break;
                                    if (!__3e->__O3__4expr.e2)
                                        __1ok = 1;
                                }
                            }
                        }
                    }
                }
                if ((!__1ok) || (__2n && (!__2n->__O3__4expr.n_initializer)))
                    continue;

                (((((unsigned long)(__1numEx + 1)) < (&__1funVec)->n__11Block_Pname) ||
                  grow__11Block_PnameFUl((&__1funVec), ((unsigned long)(__1numEx + 1)))));
                ((*((__2__X217 = (__1numEx++)),
                    ((((Pname *)(&((&__1funVec)->p__11Block_Pname[__2__X217])))))))) = __2nn;
            }
        }

        if (!__1numEx) {
            {
                __0_result = 0;

                ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                          (((void)(((void)0))))))));
            }
            return __0_result;
        }
        if (__1numEx == 1) {
            {
                __0_result = ((*((((Pname *)(&((&__1funVec)->p__11Block_Pname[0])))))));

                ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                          (((void)(((void)0))))))));
            }
            return __0_result;
        }
        {
            struct Bits __1bestOnes;

            struct Bits __0__V215;

            struct Block_Bits_chunk *__0__X45;

            __co__FRC4Bits(&__1bestOnes,
                           (const struct Bits *)__ct__4BitsFUlT1(&__0__V215, (unsigned long)0,
                                                                 (unsigned long)__1numEx));
            {
                {
                    __0_result = breakTie__FRC11Block_PnameR4BitsP4expri(
                        (const struct Block_Pname *)(&__1funVec), (struct Bits *)(&__1bestOnes),
                        __1arg, __1constObj);

                    {
                        ((((void)((
                            (void)(((__0__X45 = (&(&__0__V215)->b__4Bits)),
                                    ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45
                                                                        ->p__16Block_Bits_chunk),
                                                          (__0__X45 ? (((void)(((void)0))))
                                                                    : (((void)0))))))
                                               : (((void)0))))),
                                   (((void)0))))))));

                        ((((void)((
                            (void)(((__0__X45 = (&(&__1bestOnes)->b__4Bits)),
                                    ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45
                                                                        ->p__16Block_Bits_chunk),
                                                          (__0__X45 ? (((void)(((void)0))))
                                                                    : (((void)0))))))
                                               : (((void)0))))),
                                   (((void)0))))))));

                        ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                                  (((void)(((void)0))))))));
                    }
                }
                return __0_result;
            }
        }
    }
}

static void bestMatch__FRC11Block_PnameiP4type(struct Bits *__0_result, const struct Block_Pname *,
                                               int, Ptype);

size_t count__4BitsCFv(const struct Bits *const __0this);

Pname oneArgMatch__3genFP4expri(register struct gen *__0this, Pexpr __1aarg, int __1constObj) {
    struct name *__0_result;

    if (((__0this->holds_templ__3gen == 2)))
        return (struct name *)0;
    {
        Plist __1gl;
        int __1numFunc;
        struct Block_Pname __1ArgVec;
        struct Block_Pname __1funVec;
        Pname __1fn;

        __1numFunc = 0;
        (((((&__1ArgVec)->n__11Block_Pname = 0), ((&__1ArgVec)->p__11Block_Pname = 0))),
         (&__1ArgVec));

        (((((&__1funVec)->n__11Block_Pname = 0), ((&__1funVec)->p__11Block_Pname = 0))),
         (&__1funVec));

        __1fn = __0this->fct_list__3gen->f__9name_list;

        for (__1gl = __0this->fct_list__3gen; __1gl; __1gl = __1gl->l__9name_list) {
            Pname __2nn;
            Pfct __2ft;
            Pname __2nnargs;

            int __2__X219;

            unsigned long __2__X16;

            struct ea __0__X__V1400qmhwx544vcnm;

            struct ea __0__X__V1500qmhwx544vcnm;

            __2nn = __1gl->f__9name_list;
            __2ft =
                (((__2nn->__O1__4expr.tp->base__4node == 108)
                      ? (((struct fct *)(((struct fct *)__2nn->__O1__4expr.tp))))
                      : (error__FiPCcRC2eaN33(
                             (int)'i', (const char *)"N::fct_type():%n is %k notF",
                             (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)->__O1__2ea.p =
                                                      ((const void *)__2nn)),
                                                 (&__0__X__V1400qmhwx544vcnm)),
                             (const struct ea
                                  *)((__2__X16 = __2nn->__O1__4expr.tp->base__4node),
                                     (((((&__0__X__V1500qmhwx544vcnm)->__O1__2ea.i = __2__X16), 0)),
                                      (&__0__X__V1500qmhwx544vcnm))),
                             (const struct ea *)ea0, (const struct ea *)ea0),
                         (((struct fct *)0)))));
            __2nnargs = __2ft->argtype__3fct;

            if ((__2nn->n_template_fct__4name))
                continue;

            if (((__1constObj && (__1fn->n_oper__4name != 161)) && (!__2ft->f_const__3fct)) &&
                (!__2ft->f_static__3fct)) {
                non_const++;
                continue;
            }
            if ((!__2nnargs) && (__2ft->nargs_known__3fct != 155))
                continue;
            if ((__2nnargs && __2nnargs->__O1__4name.n_list) &&
                (!__2nnargs->__O1__4name.n_list->__O3__4expr.n_initializer))
                continue;
            (((((unsigned long)(__1numFunc + 1)) < (&__1ArgVec)->n__11Block_Pname) ||
              grow__11Block_PnameFUl((&__1ArgVec), ((unsigned long)(__1numFunc + 1)))));
            (((((unsigned long)(__1numFunc + 1)) < (&__1funVec)->n__11Block_Pname) ||
              grow__11Block_PnameFUl((&__1funVec), ((unsigned long)(__1numFunc + 1)))));
            ((*((((Pname *)(&((&__1ArgVec)->p__11Block_Pname[__1numFunc]))))))) =
                (__2nnargs ? __2nnargs : (((struct name *)155)));
            ((*((__2__X219 = (__1numFunc++)),
                ((((Pname *)(&((&__1funVec)->p__11Block_Pname[__2__X219])))))))) = __2nn;
        }
        if (!__1numFunc) {
            {
                __0_result = 0;

                ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                          (((void)(((void)0))))))));

                ((((void)(__dl__FPv((void *)(&__1ArgVec)->p__11Block_Pname),
                          (((void)(((void)0))))))));
            }
            return __0_result;
        }
        {
            struct Bits __1bestOnes;

            int __1numFuncs;

            struct Block_Bits_chunk *__0__X45;

            int __2__X220;

            bestMatch__FRC11Block_PnameiP4type(&__1bestOnes,
                                               (const struct Block_Pname *)(&__1ArgVec), __1numFunc,
                                               __1aarg->__O2__4expr.e1->__O1__4expr.tp);

            __1numFuncs = count__4BitsCFv((const struct Bits *)(&__1bestOnes));
            if (!__1numFuncs) {
                {
                    __0_result = 0;

                    {
                        ((((void)((
                            (void)(((__0__X45 = (&(&__1bestOnes)->b__4Bits)),
                                    ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45
                                                                        ->p__16Block_Bits_chunk),
                                                          (__0__X45 ? (((void)(((void)0))))
                                                                    : (((void)0))))))
                                               : (((void)0))))),
                                   (((void)0))))))));

                        ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                                  (((void)(((void)0))))))));

                        ((((void)(__dl__FPv((void *)(&__1ArgVec)->p__11Block_Pname),
                                  (((void)(((void)0))))))));
                    }
                }
                return __0_result;
            }
            if (__1numFuncs == 1) {
                {
                    __0_result = ((
                        *((__2__X220 = (signif__4BitsCFv((const struct Bits *)(&__1bestOnes)) - 1)),
                          ((((Pname *)(&((&__1funVec)->p__11Block_Pname[__2__X220]))))))));

                    {
                        ((((void)((
                            (void)(((__0__X45 = (&(&__1bestOnes)->b__4Bits)),
                                    ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45
                                                                        ->p__16Block_Bits_chunk),
                                                          (__0__X45 ? (((void)(((void)0))))
                                                                    : (((void)0))))))
                                               : (((void)0))))),
                                   (((void)0))))))));

                        ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                                  (((void)(((void)0))))))));

                        ((((void)(__dl__FPv((void *)(&__1ArgVec)->p__11Block_Pname),
                                  (((void)(((void)0))))))));
                    }
                }
                return __0_result;
            }
            {
                {
                    __0_result = breakTie__FRC11Block_PnameR4BitsP4expri(
                        (const struct Block_Pname *)(&__1funVec), (struct Bits *)(&__1bestOnes),
                        __1aarg, __1constObj);
                    {
                        ((((void)((
                            (void)(((__0__X45 = (&(&__1bestOnes)->b__4Bits)),
                                    ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45
                                                                        ->p__16Block_Bits_chunk),
                                                          (__0__X45 ? (((void)(((void)0))))
                                                                    : (((void)0))))))
                                               : (((void)0))))),
                                   (((void)0))))))));

                        ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                                  (((void)(((void)0))))))));

                        ((((void)(__dl__FPv((void *)(&__1ArgVec)->p__11Block_Pname),
                                  (((void)(((void)0))))))));
                    }
                }
                return __0_result;
            }
        }
    }
}

static void intersectRule__FRC16Block_BlockPnameiP4expr(struct Bits *__0_result,
                                                        const struct Block_BlockPname *, int,
                                                        Pexpr);

extern Pname bestOfPair__FP4nameT1P4type(Pname, Pname, Ptype);

static Pname *__vc__11Block_PnameFi(struct Block_Pname *__0this, int __2i);

Pname multArgMatch__3genFP4expri(register struct gen *__0this, Pexpr __1arg, int __1constObj) {
    struct name *__0_result;

    if (((__0this->holds_templ__3gen == 2)))
        return (struct name *)0;
    {
        int __1numargs;
        Pexpr __1tmp;

        __1numargs = 1;
        __1tmp = __1arg;
        if (!__1tmp)
            return (struct name *)0;
        while (__1tmp = __1tmp->__O3__4expr.e2)
            __1numargs++;
        {
            struct Block_BlockPname __1intFun;

            (((((&__1intFun)->n__16Block_BlockPname = 0),
               (((&__1intFun)->p__16Block_BlockPname = 0),
                (move__16Block_BlockPnameFP11Block_PnameUl(
                     (&__1intFun),
                     (BlockPname *)(((struct Block_Pname *)__vec_new(
                         ((void *)0), ((unsigned long)__1numargs), sizeof(struct Block_Pname),
                         ((void *)__ct__11Block_PnameFv)))),
                     ((unsigned long)__1numargs)),
                 (&__1intFun)->n__16Block_BlockPname)))),
             (&__1intFun));

            miFlag = 0;
            {
                int __1numFunc;
                struct Block_Pname __1funVec;

                __1numFunc = 0;
                (((((&__1funVec)->n__11Block_Pname = 0), ((&__1funVec)->p__11Block_Pname = 0))),
                 (&__1funVec));

                {
                    {
                        Plist __1gl;

                        __1gl = __0this->fct_list__3gen;

                        for (; __1gl; __1gl = __1gl->l__9name_list) {
                            Pname __2nn;

                            __2nn = __1gl->f__9name_list;

                            if ((__2nn->n_template_fct__4name))
                                continue;

                            if (!matchable__FP4nameP4expri(__2nn, __1arg, __1constObj))
                                continue;

                            {
                                int __2ai;
                                Pfct __2tf;

                                unsigned long __2__X16;

                                struct ea __0__X__V1400qmhwx544vcnm;

                                struct ea __0__X__V1500qmhwx544vcnm;

                                __2ai = 0;
                                __2tf = ((
                                    (__2nn->__O1__4expr.tp->base__4node == 108)
                                        ? (((struct fct *)(((struct fct *)__2nn->__O1__4expr.tp))))
                                        : (error__FiPCcRC2eaN33(
                                               (int)'i',
                                               (const char *)"N::fct_type():%n is %k notF",
                                               (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)
                                                                        ->__O1__2ea.p =
                                                                        ((const void *)__2nn)),
                                                                   (&__0__X__V1400qmhwx544vcnm)),
                                               (const struct ea
                                                    *)((__2__X16 =
                                                            __2nn->__O1__4expr.tp->base__4node),
                                                       (((((&__0__X__V1500qmhwx544vcnm)
                                                               ->__O1__2ea.i = __2__X16),
                                                          0)),
                                                        (&__0__X__V1500qmhwx544vcnm))),
                                               (const struct ea *)ea0, (const struct ea *)ea0),
                                           (((struct fct *)0)))));

                                (((((unsigned long)(__1numFunc + 1)) <
                                   (&__1funVec)->n__11Block_Pname) ||
                                  grow__11Block_PnameFUl((&__1funVec),
                                                         ((unsigned long)(__1numFunc + 1)))));
                                ((*((
                                    ((Pname *)(&((&__1funVec)->p__11Block_Pname[__1numFunc]))))))) =
                                    __2nn;
                                {
                                    {
                                        Pname __2x;

                                        __2x = __2tf->argtype__3fct;

                                        for (; __2x && (__2ai < __1numargs);
                                             __2x = __2x->__O1__4name.n_list) {
                                            struct Block_Pname *__0__X222;

                                            struct Block_Pname *__0__X223;

                                            ((__0__X222 = (struct Block_Pname *)((((BlockPname *)(&(
                                                  (&__1intFun)->p__16Block_BlockPname[__2ai])))))),
                                             (((((unsigned long)(__1numFunc + 1)) <
                                                __0__X222->n__11Block_Pname) ||
                                               grow__11Block_PnameFUl(
                                                   __0__X222, ((unsigned long)(__1numFunc + 1))))));
                                            ((*((__0__X223 =
                                                     (struct Block_Pname *)((((BlockPname *)(&(
                                                         (&__1intFun)
                                                             ->p__16Block_BlockPname[__2ai])))))),
                                                ((((Pname *)(&(
                                                    __0__X223
                                                        ->p__11Block_Pname[__1numFunc])))))))) =
                                                __2x;
                                            __2ai++;
                                        }

                                        if (__2tf->nargs_known__3fct == 155) {
                                            while (__2ai < __1numargs) {
                                                struct Block_Pname *__0__X224;

                                                int __2__X225;

                                                struct Block_Pname *__0__X226;

                                                ((__0__X224 =
                                                      (struct Block_Pname *)((((BlockPname *)(&(
                                                          (&__1intFun)
                                                              ->p__16Block_BlockPname[__2ai])))))),
                                                 (((((unsigned long)(__1numFunc + 1)) <
                                                    __0__X224->n__11Block_Pname) ||
                                                   grow__11Block_PnameFUl(
                                                       __0__X224,
                                                       ((unsigned long)(__1numFunc + 1))))));
                                                ((*((__0__X226 =
                                                         (struct Block_Pname
                                                              *)((__2__X225 = (__2ai++)),
                                                                 ((((BlockPname *)(&(
                                                                     (&__1intFun)
                                                                         ->p__16Block_BlockPname
                                                                             [__2__X225]))))))),
                                                    ((((Pname *)(&(
                                                        __0__X226
                                                            ->p__11Block_Pname[__1numFunc])))))))) =
                                                    (((struct name *)155));
                                            }
                                        }
                                        __1numFunc++;
                                    }
                                }
                            }
                        }

                        if (__1numFunc == 0) {
                            {
                                __0_result = 0;

                                {
                                    ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                                              (((void)(((void)0))))))));

                                    ((((void)(__vec_delete(
                                                  ((void *)(&__1intFun)->p__16Block_BlockPname), -1,
                                                  sizeof(struct Block_Pname),
                                                  ((void *)__dt__11Block_PnameFv), 1, 0),
                                              (((void)(((void)0))))))));
                                }
                            }
                            return __0_result;
                        }
                        if (__1numFunc == 1) {
                            {
                                __0_result =
                                    ((*((((Pname *)(&((&__1funVec)->p__11Block_Pname[0])))))));

                                {
                                    ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                                              (((void)(((void)0))))))));

                                    ((((void)(__vec_delete(
                                                  ((void *)(&__1intFun)->p__16Block_BlockPname), -1,
                                                  sizeof(struct Block_Pname),
                                                  ((void *)__dt__11Block_PnameFv), 1, 0),
                                              (((void)(((void)0))))))));
                                }
                            }
                            return __0_result;
                        }
                        if (__1numFunc > 1) {
                            struct Bits __2bestFuncs;

                            Pname __2best;
                            int __2sigbit;

                            struct Block_Bits_chunk *__0__X45;

                            intersectRule__FRC16Block_BlockPnameiP4expr(
                                &__2bestFuncs, (const struct Block_BlockPname *)(&__1intFun),
                                __1numFunc, __1arg);

                            __2best = 0;
                            __2sigbit =
                                (signif__4BitsCFv((const struct Bits *)(&__2bestFuncs)) - 1);

                            switch (count__4BitsCFv((const struct Bits *)(&__2bestFuncs))) {
                            case 0:
                                fmError__FiRC11Block_PnameP4exprUc(
                                    1, (const struct Block_Pname *)(&__1funVec), __1arg,
                                    (unsigned char)__1constObj);
                                __2best =
                                    ((*((((Pname *)(&((&__1funVec)->p__11Block_Pname[0])))))));
                                break;

                            default:
                                __2best = breakTie__FRC11Block_PnameR4BitsP4expri(
                                    (const struct Block_Pname *)(&__1funVec),
                                    (struct Bits *)(&__2bestFuncs), __1arg, __1constObj);
                                __2sigbit =
                                    (signif__4BitsCFv((const struct Bits *)(&__2bestFuncs)) - 1);

                            case 1:
                                if ((miFlag == 1) && (__1numFunc > 2)) {
                                    {
                                        {
                                            int __4K;

                                            __4K = 0;

                                            for (; __4K < __1numFunc; __4K++) {
                                                if (__4K == __2sigbit)
                                                    continue;
                                                {
                                                    int __5gotit;
                                                    Pexpr __5targ;

                                                    __5gotit = 0;
                                                    __5targ = __1arg;
                                                    {
                                                        {
                                                            int __5I;

                                                            __5I = 0;

                                                            for (; __5I < __1numargs; __5I++) {
                                                                struct Block_Pname *__0__X227;

                                                                if (bestOfPair__FP4nameT1P4type(
                                                                        (*((__0__X227 = (struct
                                                                                         Block_Pname
                                                                                             *)((((
                                                                                BlockPname *)(&(
                                                                                (&__1intFun)
                                                                                    ->p__16Block_BlockPname
                                                                                        [__5I])))))),
                                                                           ((((Pname *)(&(
                                                                               __0__X227->p__11Block_Pname
                                                                                   [__2sigbit]))))))),
                                                                        (*__vc__11Block_PnameFi(
                                                                            (struct Block_Pname
                                                                                 *)((((
                                                                                BlockPname *)(&(
                                                                                (&__1intFun)
                                                                                    ->p__16Block_BlockPname
                                                                                        [__5I]))))),
                                                                            __4K)),
                                                                        __5targ->__O2__4expr.e1
                                                                            ->__O1__4expr.tp)) {
                                                                    __5gotit = 1;
                                                                    break;
                                                                }
                                                                __5targ = __5targ->__O3__4expr.e2;
                                                            }
                                                            if (!__5gotit) {
                                                                if (!__2best) {
                                                                    fmError__FiRC11Block_PnameP4exprUc(
                                                                        1,
                                                                        (const struct Block_Pname
                                                                             *)(&__1funVec),
                                                                        __1arg,
                                                                        (unsigned char)__1constObj);
                                                                    break;
                                                                }
                                                                {
                                                                    struct Bits __6temp;

                                                                    struct Block_Bits_chunk
                                                                        *__0__X45;

                                                                    struct Block_Bits_chunk
                                                                        *__0__X37;

                                                                    int __2__X38;

                                                                    struct Block_Bits_chunk
                                                                        *__0__X229;

                                                                    const struct Block_Bits_chunk
                                                                        *__2__X230;

                                                                    ((((((__0__X229 =
                                                                              (&(&__6temp)
                                                                                    ->b__4Bits)),
                                                                         ((__2__X230 =
                                                                               (const struct
                                                                                Block_Bits_chunk
                                                                                    *)(&((*((const struct
                                                                                             Bits
                                                                                                 *)(&__2bestFuncs))))
                                                                                            .b__4Bits)),
                                                                          (((__0__X229 ||
                                                                             (__0__X229 = (struct
                                                                                           Block_Bits_chunk
                                                                                               *)
                                                                                  __nw__FUl((
                                                                                      size_t)(sizeof(
                                                                                      struct
                                                                                      Block_Bits_chunk)))))
                                                                                ? (((void)copy__16Block_Bits_chunkFRC16Block_Bits_chunk(
                                                                                      __0__X229,
                                                                                      __2__X230)))
                                                                                : (((void)0))),
                                                                           __0__X229))),
                                                                        ((&__6temp)->n__4Bits =
                                                                             ((*((const struct Bits
                                                                                      *)(&__2bestFuncs))))
                                                                                 .n__4Bits)),
                                                                       0)),
                                                                     (&__6temp));
                                                                    (((((unsigned long)__4K) <
                                                                       (&__2bestFuncs)->n__4Bits)
                                                                          ? (((*((__0__X37 =
                                                                                      (&(&__2bestFuncs)
                                                                                            ->b__4Bits)),
                                                                                 ((__2__X38 = ((
                                                                                       ((unsigned long)
                                                                                            __4K) >>
                                                                                       5))),
                                                                                  ((((Bits_chunk
                                                                                          *)(&(
                                                                                      __0__X37->p__16Block_Bits_chunk
                                                                                          [__2__X38]))))))))) |=
                                                                             ((((unsigned long)1))
                                                                              << (((unsigned long)
                                                                                       __4K) &
                                                                                  31)))
                                                                          : 0),
                                                                     (((struct Bits
                                                                            *)(&__2bestFuncs))));
                                                                    if (breakTie__FRC11Block_PnameR4BitsP4expri(
                                                                            (const struct
                                                                             Block_Pname
                                                                                 *)(&__1funVec),
                                                                            (struct Bits
                                                                                 *)(&__6temp),
                                                                            __1arg, __1constObj) !=
                                                                        ((*((((Pname *)(&(
                                                                            (&__1funVec)
                                                                                ->p__11Block_Pname
                                                                                    [__2sigbit])))))))) {
                                                                        fmError__FiRC11Block_PnameP4exprUc(
                                                                            1,
                                                                            (const struct
                                                                             Block_Pname
                                                                                 *)(&__1funVec),
                                                                            __1arg,
                                                                            (unsigned char)
                                                                                __1constObj);
                                                                        {
                                                                            {
                                                                                ((((void)(((
                                                                                    void)(((__0__X45 =
                                                                                                (&(&__6temp)
                                                                                                      ->b__4Bits)),
                                                                                           ((__0__X45
                                                                                                 ? (((void)(__dl__FPv(
                                                                                                                (void
                                                                                                                     *)__0__X45
                                                                                                                    ->p__16Block_Bits_chunk),
                                                                                                            (__0__X45
                                                                                                                 ? (((void)(((
                                                                                                                       void)0))))
                                                                                                                 : (((void)0))))))
                                                                                                 : (((void)0))))),
                                                                                          (((void)0))))))));

                                                                                break;
                                                                            }
                                                                        }
                                                                    }

                                                                    ((((void)(((
                                                                        void)(((__0__X45 =
                                                                                    (&(&__6temp)
                                                                                          ->b__4Bits)),
                                                                               ((__0__X45
                                                                                     ? (((void)(__dl__FPv(
                                                                                                    (void
                                                                                                         *)__0__X45
                                                                                                        ->p__16Block_Bits_chunk),
                                                                                                (__0__X45
                                                                                                     ? (((void)(((
                                                                                                           void)0))))
                                                                                                     : (((void)0))))))
                                                                                     : (((void)0))))),
                                                                              (((void)0))))))));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                __2best = ((*(
                                    (((Pname *)(&((&__1funVec)->p__11Block_Pname[__2sigbit])))))));
                            }
                            {
                                {
                                    ((((void)((
                                        (void)(((__0__X45 = (&(&__2bestFuncs)->b__4Bits)),
                                                ((__0__X45
                                                      ? (((void)(__dl__FPv(
                                                                     (void *)__0__X45
                                                                         ->p__16Block_Bits_chunk),
                                                                 (__0__X45 ? (((void)(((void)0))))
                                                                           : (((void)0))))))
                                                      : (((void)0))))),
                                               (((void)0))))))));

                                    {
                                        ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                                                  (((void)(((void)0))))))));

                                        ((((void)(__vec_delete(
                                                      ((void *)(&__1intFun)->p__16Block_BlockPname),
                                                      -1, sizeof(struct Block_Pname),
                                                      ((void *)__dt__11Block_PnameFv), 1, 0),
                                                  (((void)(((void)0))))))));
                                    }
                                }
                                return __2best;
                            }
                        }

                        error__FiPCc((int)'i', (const char *)"fall off end of gen::multArgMatch()");
                        {
                            {
                                __0_result = 0;
                                {
                                    ((((void)(__dl__FPv((void *)(&__1funVec)->p__11Block_Pname),
                                              (((void)(((void)0))))))));

                                    ((((void)(__vec_delete(
                                                  ((void *)(&__1intFun)->p__16Block_BlockPname), -1,
                                                  sizeof(struct Block_Pname),
                                                  ((void *)__dt__11Block_PnameFv), 1, 0),
                                              (((void)(((void)0))))))));
                                }
                            }
                            return __0_result;
                        }
                    }
                }
            }
        }
    }
}

static void bestMatch__FRC11Block_PnameiP4type(struct Bits *__0_result,
                                               const struct Block_Pname *__1AV, int __1nav,
                                               Ptype __1at) {
    struct Bits __1zeroBits;

    struct Block_int __1rate;
    struct Block_Pname __1udcBlock;

    int __1i;

    struct Block_Bits_chunk *__0__X45;

    struct Block_Bits_chunk *__0__X229;

    const struct Block_Bits_chunk *__2__X230;

    __ct__4BitsFUlT1(&__1zeroBits, (unsigned long)0, (unsigned long)__1nav);

    ((((((__0__X229 = (&__0_result->b__4Bits)),
         ((__2__X230 = (const struct Block_Bits_chunk *)(&((*((const struct Bits *)(&__1zeroBits))))
                                                              .b__4Bits)),
          (((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl(
                               (size_t)(sizeof(struct Block_Bits_chunk)))))
                ? (((void)copy__16Block_Bits_chunkFRC16Block_Bits_chunk(__0__X229, __2__X230)))
                : (((void)0))),
           __0__X229))),
        (__0_result->n__4Bits = ((*((const struct Bits *)(&__1zeroBits)))).n__4Bits)),
       0)),
     __0_result);
    (((((&__1rate)->n__9Block_int = 0),
       (((&__1rate)->p__9Block_int = 0),
        (move__9Block_intFPiUl(
             (&__1rate),
             (int *)(((int *)__nw__FUl((size_t)((sizeof(int)) * ((unsigned long)__1nav))))),
             ((unsigned long)__1nav)),
         (&__1rate)->n__9Block_int)))),
     (&__1rate));
    (((((&__1udcBlock)->n__11Block_Pname = 0),
       (((&__1udcBlock)->p__11Block_Pname = 0),
        (move__11Block_PnameFPP4nameUl(
             (&__1udcBlock),
             (Pname *)(((struct name **)__nw__FUl(
                 (size_t)((sizeof(struct name *)) * ((unsigned long)__1nav))))),
             ((unsigned long)__1nav)),
         (&__1udcBlock)->n__11Block_Pname)))),
     (&__1udcBlock));

    __1i = -1;
    while ((++__1i) < __1nav) {
        Pname __2aa;

        __2aa = ((*(
            (((const Pname *)(&(((const struct Block_Pname *)__1AV)->p__11Block_Pname[__1i])))))));

        if (__2aa == 0)
            continue;

        if (__2aa == (((struct name *)155))) {
            ((*((((int *)(&((&__1rate)->p__9Block_int[__1i]))))))) = 1;
            continue;
        }
        {
            Ptype __2t1;

            __2t1 = __2aa->__O1__4expr.tp;

            if ((__2t1 == __1at) || exact1__FP4nameP4type(__2aa, __1at)) {
                ((*((((int *)(&((&__1rate)->p__9Block_int[__1i]))))))) = 5;
                continue;
            }
            if (exact2__FP4nameP4type(__2aa, __1at)) {
                ((*((((int *)(&((&__1rate)->p__9Block_int[__1i]))))))) = 4;
                continue;
            }
            if (exact3__FP4nameP4type(__2aa, __1at)) {
                ((*((((int *)(&((&__1rate)->p__9Block_int[__1i]))))))) = 3;
                continue;
            }

            {
                int __2cc;

                __2cc = can_coerce__FP4typeT1(__2t1, __1at);
                if (__2cc == 1) {
                    ((*((((Pname *)(&((&__1udcBlock)->p__11Block_Pname[__1i]))))))) = Ncoerce;
                    ((*((((int *)(&((&__1rate)->p__9Block_int[__1i]))))))) = 2;
                    continue;
                }

                ((*((((int *)(&((&__1rate)->p__9Block_int[__1i]))))))) = 0;
            }
        }
    }

    {
        int __1max;

        __1max = 0;
        for (__1i = 0; __1i < __1nav; __1i++) {
            if (((*((((int *)(&((&__1rate)->p__9Block_int[__1i]))))))) > __1max) {

                register struct Block_Bits_chunk *__0__X232;

                const struct Block_Bits_chunk *__2__X233;

                __1max = ((*((((int *)(&((&__1rate)->p__9Block_int[__1i])))))));
                (((((*((__0__X232 = (&__0_result->b__4Bits)),
                       ((__2__X233 = (const struct Block_Bits_chunk
                                          *)(&((*((const struct Bits *)(&__1zeroBits)))).b__4Bits)),
                        (__dl__FPv((void *)__0__X232->p__16Block_Bits_chunk),
                         (copy__16Block_Bits_chunkFRC16Block_Bits_chunk(__0__X232, __2__X233),
                          (((struct Block_Bits_chunk *)__0__X232)))))))),
                   (__0_result->n__4Bits = ((*((const struct Bits *)(&__1zeroBits)))).n__4Bits)),
                  ((*__0_result))),
                 (((struct Bits *)__0_result)));
            }
            if (((*((((int *)(&((&__1rate)->p__9Block_int[__1i]))))))) &&
                (((*((((int *)(&((&__1rate)->p__9Block_int[__1i]))))))) == __1max)) {
                struct Block_Bits_chunk *__0__X37;

                int __2__X38;

                (((((unsigned long)__1i) < __0_result->n__4Bits)
                      ? (((*((__0__X37 = (&__0_result->b__4Bits)),
                             ((__2__X38 = ((((unsigned long)__1i) >> 5))),
                              ((((Bits_chunk *)(&(
                                  __0__X37->p__16Block_Bits_chunk[__2__X38]))))))))) |=
                         ((((unsigned long)1)) << (((unsigned long)__1i) & 31)))
                      : 0),
                 (((struct Bits *)__0_result)));
            }
        }

        if (count__4BitsCFv((const struct Bits *)__0_result) <= 1) {
            {
                ;

                ((((void)(__dl__FPv((void *)(&__1udcBlock)->p__11Block_Pname),
                          (((void)(((void)0))))))));

                ((((void)(__dl__FPv((void *)(&__1rate)->p__9Block_int), (((void)(((void)0))))))));

                ((((void)(((
                    void)(((__0__X45 = (&(&__1zeroBits)->b__4Bits)),
                           ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                          (((void)0))))))));
            }
            return;
        }
        if (__1max == 3) {
            if (is_ptr_or_ref__4typeFv(__1at))
                __1at = (((struct ptr *)(((struct ptr *)__1at))))->typ__5pvtyp;
            if (!is_cl_obj__4typeFv(__1at)) {
                {
                    ;

                    ((((void)(__dl__FPv((void *)(&__1udcBlock)->p__11Block_Pname),
                              (((void)(((void)0))))))));

                    ((((void)(__dl__FPv((void *)(&__1rate)->p__9Block_int),
                              (((void)(((void)0))))))));

                    ((((void)((
                        (void)(((__0__X45 = (&(&__1zeroBits)->b__4Bits)),
                                ((__0__X45
                                      ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                               (((void)0))))))));
                }
                return;
            }
            {
                struct Bits __2tempBits;

                struct Block_Bits_chunk *__0__X45;

                unsigned long __2__X234;

                struct Block_Bits_chunk *__0__X41;

                int __2__X42;

                struct Block_Bits_chunk *__0__X229;

                const struct Block_Bits_chunk *__2__X230;

                ((((((__0__X229 = (&(&__2tempBits)->b__4Bits)),
                     ((__2__X230 = (const struct Block_Bits_chunk
                                        *)(&((*((const struct Bits *)__0_result))).b__4Bits)),
                      (((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl(
                                           (size_t)(sizeof(struct Block_Bits_chunk)))))
                            ? (((void)copy__16Block_Bits_chunkFRC16Block_Bits_chunk(__0__X229,
                                                                                    __2__X230)))
                            : (((void)0))),
                       __0__X229))),
                    ((&__2tempBits)->n__4Bits = ((*((const struct Bits *)__0_result))).n__4Bits)),
                   0)),
                 (&__2tempBits));
                ((__2__X234 = (signif__4BitsCFv((const struct Bits *)(&__2tempBits)) - 1)),
                 (((__2__X234 < (&__2tempBits)->n__4Bits)
                       ? (((*((__0__X41 = (&(&__2tempBits)->b__4Bits)),
                              ((__2__X42 = ((__2__X234 >> 5))),
                               ((((Bits_chunk *)(&(
                                   __0__X41->p__16Block_Bits_chunk[__2__X42]))))))))) &=
                          (~((((unsigned long)1)) << (__2__X234 & 31))))
                       : 0),
                  (((struct Bits *)(&__2tempBits)))));

                while (count__4BitsCFv((const struct Bits *)(&__2tempBits))) {
                    int __3tempPtr;
                    Ptype __3t1;
                    Pptr __3p_t1;

                    __3tempPtr = (signif__4BitsCFv((const struct Bits *)(&__2tempBits)) - 1);
                    __3t1 = ((*((((const Pname *)(&(((const struct Block_Pname *)__1AV)
                                                        ->p__11Block_Pname[__3tempPtr])))))))
                                ->__O1__4expr.tp;
                    __3p_t1 = is_ptr__4typeFv(__3t1);
                    {
                        {
                            int __3k;

                            struct Block_Bits_chunk *__0__X41;

                            int __2__X42;

                            __3k = (__1nav - 1);

                            for (; __3k > __3tempPtr; __3k--) {
                                const struct Block_Bits_chunk *__0__X43;

                                int __2__X44;

                                if (!(((((unsigned long)__3k) >=
                                        ((const struct Bits *)__0_result)->n__4Bits)
                                           ? (((int)0))
                                           : (((int)((((*((__0__X43 = (const struct Block_Bits_chunk
                                                                           *)(&((const struct Bits
                                                                                     *)__0_result)
                                                                                   ->b__4Bits)),
                                                          ((__2__X44 =
                                                                ((((unsigned long)__3k) >> 5))),
                                                           ((((const Bits_chunk *)(&(
                                                               __0__X43->p__16Block_Bits_chunk
                                                                   [__2__X44]))))))))) >>
                                                      (((unsigned long)__3k) & 31)) &
                                                     1))))))
                                    continue;
                                {
                                    Ptype __4t2;

                                    __4t2 =
                                        ((*((((const Pname *)(&(((const struct Block_Pname *)__1AV)
                                                                    ->p__11Block_Pname[__3k])))))))
                                            ->__O1__4expr.tp;
                                    if ((check__4typeFP4typeUcT2(__3t1, __4t2, (unsigned char)0,
                                                                 (unsigned char)0) == 0) ||
                                        const_problem)
                                        continue;

                                    {
                                        int __4r;
                                        Pptr __4p_t2;

                                        __4r = pr_dominate__FP4typeT1(__3t1, __4t2);
                                        __4p_t2 = is_ptr__4typeFv(__4t2);
                                        if ((__4r == 1) ||
                                            (__4p_t2 &&
                                             (__4p_t2->typ__5pvtyp->base__4node == 38))) {
                                            struct Block_Bits_chunk *__0__X41;

                                            int __2__X42;

                                            (((((unsigned long)__3k) < __0_result->n__4Bits)
                                                  ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                                         ((__2__X42 =
                                                               ((((unsigned long)__3k) >> 5))),
                                                          ((((Bits_chunk *)(&(
                                                              __0__X41->p__16Block_Bits_chunk
                                                                  [__2__X42]))))))))) &=
                                                     (~((((unsigned long)1))
                                                        << (((unsigned long)__3k) & 31))))
                                                  : 0),
                                             (((struct Bits *)__0_result)));
                                        }
                                        if ((__4r == 2) ||
                                            (__3p_t1 &&
                                             (__3p_t1->typ__5pvtyp->base__4node == 38))) {
                                            struct Block_Bits_chunk *__0__X41;

                                            int __2__X42;

                                            (((((unsigned long)__3tempPtr) < __0_result->n__4Bits)
                                                  ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                                         ((__2__X42 = ((
                                                               ((unsigned long)__3tempPtr) >> 5))),
                                                          ((((Bits_chunk *)(&(
                                                              __0__X41->p__16Block_Bits_chunk
                                                                  [__2__X42]))))))))) &=
                                                     (~((((unsigned long)1))
                                                        << (((unsigned long)__3tempPtr) & 31))))
                                                  : 0),
                                             (((struct Bits *)__0_result)));
                                            break;
                                        }
                                        if ((__4r == 0) && (miFlag == 0))
                                            miFlag = 1;
                                    }
                                }
                            }
                            (((((unsigned long)__3tempPtr) < (&__2tempBits)->n__4Bits)
                                  ? (((*((__0__X41 = (&(&__2tempBits)->b__4Bits)),
                                         ((__2__X42 = ((((unsigned long)__3tempPtr) >> 5))),
                                          ((((Bits_chunk *)(&(
                                              __0__X41->p__16Block_Bits_chunk[__2__X42]))))))))) &=
                                     (~((((unsigned long)1))
                                        << (((unsigned long)__3tempPtr) & 31))))
                                  : 0),
                             (((struct Bits *)(&__2tempBits))));
                        }
                    }
                }

                ((((void)(((
                    void)(((__0__X45 = (&(&__2tempBits)->b__4Bits)),
                           ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                          (((void)0))))))));
            }
        }

        if (__1max == 2) {
            struct Bits __2tempBits;
            int __2sigbit;

            struct Block_Bits_chunk *__0__X45;

            struct Block_Bits_chunk *__0__X41;

            int __2__X42;

            struct Block_Bits_chunk *__0__X229;

            const struct Block_Bits_chunk *__2__X230;

            ((((((__0__X229 = (&(&__2tempBits)->b__4Bits)),
                 ((__2__X230 = (const struct Block_Bits_chunk
                                    *)(&((*((const struct Bits *)__0_result))).b__4Bits)),
                  (((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl(
                                       (size_t)(sizeof(struct Block_Bits_chunk)))))
                        ? (((void)copy__16Block_Bits_chunkFRC16Block_Bits_chunk(__0__X229,
                                                                                __2__X230)))
                        : (((void)0))),
                   __0__X229))),
                ((&__2tempBits)->n__4Bits = ((*((const struct Bits *)__0_result))).n__4Bits)),
               0)),
             (&__2tempBits));
            __2sigbit = (signif__4BitsCFv((const struct Bits *)(&__2tempBits)) - 1);
            (((((unsigned long)__2sigbit) < (&__2tempBits)->n__4Bits)
                  ? (((*((__0__X41 = (&(&__2tempBits)->b__4Bits)),
                         ((__2__X42 = ((((unsigned long)__2sigbit) >> 5))),
                          ((((Bits_chunk *)(&(__0__X41->p__16Block_Bits_chunk[__2__X42]))))))))) &=
                     (~((((unsigned long)1)) << (((unsigned long)__2sigbit) & 31))))
                  : 0),
             (((struct Bits *)(&__2tempBits))));

            while (count__4BitsCFv((const struct Bits *)(&__2tempBits))) {
                int __3tempPtr;
                Pname __3tname;
                bit __3done;

                __3tempPtr = (signif__4BitsCFv((const struct Bits *)(&__2tempBits)) - 1);
                __3tname = ((*((((const Pname *)(&(
                    ((const struct Block_Pname *)__1AV)->p__11Block_Pname[__3tempPtr])))))));
                __3done = 0;
                {
                    {
                        int __3k;

                        struct Block_Bits_chunk *__0__X41;

                        int __2__X42;

                        __3k = (__1nav - 1);

                        for (; __3k > __3tempPtr; __3k--) {
                            const struct Block_Bits_chunk *__0__X43;

                            int __2__X44;

                            if ((!(((((unsigned long)__3k) >=
                                     ((const struct Bits *)__0_result)->n__4Bits)
                                        ? (((int)0))
                                        : (((int)((((*((__0__X43 = (const struct Block_Bits_chunk
                                                                        *)(&((const struct Bits *)
                                                                                 __0_result)
                                                                                ->b__4Bits)),
                                                       ((__2__X44 = ((((unsigned long)__3k) >> 5))),
                                                        ((((const Bits_chunk *)(&(
                                                            __0__X43->p__16Block_Bits_chunk
                                                                [__2__X44]))))))))) >>
                                                   (((unsigned long)__3k) & 31)) &
                                                  1)))))) ||
                                (!((*((((Pname *)(&((&__1udcBlock)->p__11Block_Pname[__3k])))))))))
                                continue;
                            if (((*((((Pname *)(&((&__1udcBlock)->p__11Block_Pname[__3k])))))))
                                    ->__O1__4expr.tp->base__4node == 76) {
                                {
                                    {
                                        Plist __5gl;

                                        __5gl = (((struct gen *)((
                                                     (struct gen
                                                          *)((*((((Pname *)(&(
                                                                 (&__1udcBlock)
                                                                     ->p__11Block_Pname[__3k])))))))
                                                         ->__O1__4expr.tp))))
                                                    ->fct_list__3gen;

                                        for (; __5gl; __5gl = __5gl->l__9name_list) {
                                            Ptype __6tt;
                                            Pname __6r;

                                            struct Block_Bits_chunk *__0__X41;

                                            int __2__X42;

                                            register struct name *__0__X235;

                                            unsigned long __2__X16;

                                            struct ea __0__X__V1400qmhwx544vcnm;

                                            struct ea __0__X__V1500qmhwx544vcnm;

                                            __6tt =
                                                ((__0__X235 = __5gl->f__9name_list),
                                                 (((__0__X235->__O1__4expr.tp->base__4node == 108)
                                                       ? (((struct fct *)(((struct fct *)__0__X235
                                                                               ->__O1__4expr.tp))))
                                                       : (error__FiPCcRC2eaN33(
                                                              (int)'i',
                                                              (const char
                                                                   *)"N::fct_type():%n is %k notF",
                                                              (const struct ea
                                                                   *)(((&__0__X__V1400qmhwx544vcnm)
                                                                           ->__O1__2ea.p = ((
                                                                           const void *)__0__X235)),
                                                                      (&__0__X__V1400qmhwx544vcnm)),
                                                              (const struct
                                                               ea *)((__2__X16 =
                                                                          __0__X235->__O1__4expr.tp
                                                                              ->base__4node),
                                                                     (((((&__0__X__V1500qmhwx544vcnm)
                                                                             ->__O1__2ea.i =
                                                                             __2__X16),
                                                                        0)),
                                                                      (&__0__X__V1500qmhwx544vcnm))),
                                                              (const struct ea *)ea0,
                                                              (const struct ea *)ea0),
                                                          (((struct fct *)0))))))
                                                    ->returns__3fct;
                                            __6r =
                                                ((((*((((Pname *)(&(
                                                      (&__1udcBlock)
                                                          ->p__11Block_Pname[__3tempPtr]))))))) ==
                                                  ((*((((Pname *)(&(
                                                      (&__1udcBlock)->p__11Block_Pname[__3k]))))))))
                                                     ? bestOfPair__FP4nameT1P4type(
                                                           __3tname,
                                                           (struct name *)((*((((const Pname *)(&(
                                                               ((const struct Block_Pname *)__1AV)
                                                                   ->p__11Block_Pname[__3k]))))))),
                                                           __6tt)
                                                     : (((struct name *)0)));

                                            if (__6r == __3tname)
                                                (((((unsigned long)__3k) < __0_result->n__4Bits)
                                                      ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                                             ((__2__X42 =
                                                                   ((((unsigned long)__3k) >> 5))),
                                                              ((((Bits_chunk *)(&(
                                                                  __0__X41->p__16Block_Bits_chunk
                                                                      [__2__X42]))))))))) &=
                                                         (~((((unsigned long)1))
                                                            << (((unsigned long)__3k) & 31))))
                                                      : 0),
                                                 (((struct Bits *)__0_result)));
                                            if (__6r == ((*((((const Pname *)(&(
                                                            ((const struct Block_Pname *)__1AV)
                                                                ->p__11Block_Pname[__3k])))))))) {
                                                struct Block_Bits_chunk *__0__X41;

                                                int __2__X42;

                                                (((((unsigned long)__3tempPtr) <
                                                   __0_result->n__4Bits)
                                                      ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                                             ((__2__X42 =
                                                                   ((((unsigned long)__3tempPtr) >>
                                                                     5))),
                                                              ((((Bits_chunk *)(&(
                                                                  __0__X41->p__16Block_Bits_chunk
                                                                      [__2__X42]))))))))) &=
                                                         (~((((unsigned long)1))
                                                            << (((unsigned long)__3tempPtr) & 31))))
                                                      : 0),
                                                 (((struct Bits *)__0_result)));
                                                __3done = 1;
                                                break;
                                            }
                                        }
                                    }
                                }
                            } else {
                                Ptype __5tt;
                                Pname __5r;

                                struct Block_Bits_chunk *__0__X41;

                                int __2__X42;

                                register struct name *__0__X236;

                                unsigned long __2__X16;

                                struct ea __0__X__V1400qmhwx544vcnm;

                                struct ea __0__X__V1500qmhwx544vcnm;

                                __5tt =
                                    ((__0__X236 = ((*((((
                                          Pname *)(&((&__1udcBlock)->p__11Block_Pname[__3k])))))))),
                                     (((__0__X236->__O1__4expr.tp->base__4node == 108)
                                           ? (((struct fct *)((
                                                 (struct fct *)__0__X236->__O1__4expr.tp))))
                                           : (error__FiPCcRC2eaN33(
                                                  (int)'i',
                                                  (const char *)"N::fct_type():%n is %k notF",
                                                  (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)
                                                                           ->__O1__2ea.p = ((
                                                                           const void *)__0__X236)),
                                                                      (&__0__X__V1400qmhwx544vcnm)),
                                                  (const struct ea
                                                       *)((__2__X16 = __0__X236->__O1__4expr.tp
                                                                          ->base__4node),
                                                          (((((&__0__X__V1500qmhwx544vcnm)
                                                                  ->__O1__2ea.i = __2__X16),
                                                             0)),
                                                           (&__0__X__V1500qmhwx544vcnm))),
                                                  (const struct ea *)ea0, (const struct ea *)ea0),
                                              (((struct fct *)0))))))
                                        ->returns__3fct;
                                __5r =
                                    ((((*((((Pname *)(&(
                                          (&__1udcBlock)->p__11Block_Pname[__3tempPtr]))))))) ==
                                      ((*(((
                                          (Pname *)(&((&__1udcBlock)->p__11Block_Pname[__3k]))))))))
                                         ? bestOfPair__FP4nameT1P4type(
                                               __3tname,
                                               (struct name *)((*((((const Pname *)(&(
                                                   ((const struct Block_Pname *)__1AV)
                                                       ->p__11Block_Pname[__3k]))))))),
                                               __5tt)
                                         : (((struct name *)0)));

                                if (__5r == __3tname)
                                    (((((unsigned long)__3k) < __0_result->n__4Bits)
                                          ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                                 ((__2__X42 = ((((unsigned long)__3k) >> 5))),
                                                  ((((Bits_chunk *)(&(
                                                      __0__X41->p__16Block_Bits_chunk
                                                          [__2__X42]))))))))) &=
                                             (~((((unsigned long)1))
                                                << (((unsigned long)__3k) & 31))))
                                          : 0),
                                     (((struct Bits *)__0_result)));
                                if (__5r ==
                                    ((*((((const Pname *)(&(((const struct Block_Pname *)__1AV)
                                                                ->p__11Block_Pname[__3k])))))))) {
                                    struct Block_Bits_chunk *__0__X41;

                                    int __2__X42;

                                    (((((unsigned long)__3tempPtr) < __0_result->n__4Bits)
                                          ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                                 ((__2__X42 = ((((unsigned long)__3tempPtr) >> 5))),
                                                  ((((Bits_chunk *)(&(
                                                      __0__X41->p__16Block_Bits_chunk
                                                          [__2__X42]))))))))) &=
                                             (~((((unsigned long)1))
                                                << (((unsigned long)__3tempPtr) & 31))))
                                          : 0),
                                     (((struct Bits *)__0_result)));
                                    break;
                                }
                            }
                            if (__3done)
                                break;
                        }
                        (((((unsigned long)__3tempPtr) < (&__2tempBits)->n__4Bits)
                              ? (((*((__0__X41 = (&(&__2tempBits)->b__4Bits)),
                                     ((__2__X42 = ((((unsigned long)__3tempPtr) >> 5))),
                                      ((((Bits_chunk *)(&(
                                          __0__X41->p__16Block_Bits_chunk[__2__X42]))))))))) &=
                                 (~((((unsigned long)1)) << (((unsigned long)__3tempPtr) & 31))))
                              : 0),
                         (((struct Bits *)(&__2tempBits))));
                    }
                }
            }

            ((((void)((
                (void)(((__0__X45 = (&(&__2tempBits)->b__4Bits)),
                        ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                              (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                   : (((void)0))))),
                       (((void)0))))))));
        }

        {
            {
                ;

                ((((void)(__dl__FPv((void *)(&__1udcBlock)->p__11Block_Pname),
                          (((void)(((void)0))))))));

                ((((void)(__dl__FPv((void *)(&__1rate)->p__9Block_int), (((void)(((void)0))))))));

                ((((void)(((
                    void)(((__0__X45 = (&(&__1zeroBits)->b__4Bits)),
                           ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                          (((void)0))))))));
            }
            return;
        }
    }
}

Pname bestOfPair__FP4nameT1P4type(Pname __1a1, Pname __1a2, Ptype __1at) {
    struct name *__0_result;

    if (__1a1->__O1__4expr.tp == __1a2->__O1__4expr.tp)
        return (struct name *)0;

    {
        struct Block_Pname __1tryBlock;

        (((((&__1tryBlock)->n__11Block_Pname = 0),
           (((&__1tryBlock)->p__11Block_Pname = 0),
            (move__11Block_PnameFPP4nameUl(
                 (&__1tryBlock),
                 (Pname *)(((struct name **)__nw__FUl(
                     (size_t)((sizeof(struct name *)) * ((unsigned long)3))))),
                 ((unsigned long)3)),
             (&__1tryBlock)->n__11Block_Pname)))),
         (&__1tryBlock));
        ((*((((Pname *)(&((&__1tryBlock)->p__11Block_Pname[0]))))))) = __1a1;
        ((*((((Pname *)(&((&__1tryBlock)->p__11Block_Pname[1]))))))) = __1a2;
        {
            struct Bits __1bestBits;

            struct Block_Bits_chunk *__0__X45;

            bestMatch__FRC11Block_PnameiP4type(
                &__1bestBits, (const struct Block_Pname *)(&__1tryBlock), 2, __1at);
            if (count__4BitsCFv((const struct Bits *)(&__1bestBits)) == 1) {
                int __2__X238;

                {
                    {
                        __0_result =
                            ((*((__2__X238 =
                                     (signif__4BitsCFv((const struct Bits *)(&__1bestBits)) - 1)),
                                ((((Pname *)(&((&__1tryBlock)->p__11Block_Pname[__2__X238]))))))));

                        {
                            ((((void)(((
                                void)(((__0__X45 = (&(&__1bestBits)->b__4Bits)),
                                       ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45
                                                                           ->p__16Block_Bits_chunk),
                                                             (__0__X45 ? (((void)(((void)0))))
                                                                       : (((void)0))))))
                                                  : (((void)0))))),
                                      (((void)0))))))));

                            ((((void)(__dl__FPv((void *)(&__1tryBlock)->p__11Block_Pname),
                                      (((void)(((void)0))))))));
                        }
                    }
                    return __0_result;
                }
            }
            {
                {
                    __0_result = 0;
                    {
                        ((((void)((
                            (void)(((__0__X45 = (&(&__1bestBits)->b__4Bits)),
                                    ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45
                                                                        ->p__16Block_Bits_chunk),
                                                          (__0__X45 ? (((void)(((void)0))))
                                                                    : (((void)0))))))
                                               : (((void)0))))),
                                   (((void)0))))))));

                        ((((void)(__dl__FPv((void *)(&__1tryBlock)->p__11Block_Pname),
                                  (((void)(((void)0))))))));
                    }
                }
                return __0_result;
            }
        }
    }
}

struct Bits *__aad__4BitsFRC4Bits(struct Bits *__0this, const struct Bits *);

static void intersectRule__FRC16Block_BlockPnameiP4expr(struct Bits *__0_result,
                                                        const struct Block_BlockPname *__1intFun,
                                                        int __1numFunc, Pexpr __1arg) {
    struct Bits __1zeroBits;
    struct Bits __1result;

    int __1ai;

    struct Block_Bits_chunk *__0__X45;

    __ct__4BitsFUlT1(&__1zeroBits, (unsigned long)0, (unsigned long)__1numFunc);
    __co__FRC4Bits(&__1result, (const struct Bits *)(&__1zeroBits));

    __1ai = 0;
    {
        {
            Pexpr __1aargu;

            struct Block_Bits_chunk *__0__X229;

            const struct Block_Bits_chunk *__2__X230;

            __1aargu = __1arg;

            for (; __1aargu; __1aargu = __1aargu->__O3__4expr.e2) {
                Ptype __2at;
                struct Bits __2tryit;

                struct Block_Bits_chunk *__0__X45;

                int __2__X241;

                __2at = __1aargu->__O2__4expr.e1->__O1__4expr.tp;
                bestMatch__FRC11Block_PnameiP4type(
                    &__2tryit,
                    ((__2__X241 = (__1ai++)),
                     ((((const BlockPname *)(&(((const struct Block_BlockPname *)__1intFun)
                                                   ->p__16Block_BlockPname[__2__X241])))))),
                    __1numFunc, __2at);
                if (count__4BitsCFv((const struct Bits *)(&__2tryit)) == 1)
                    miFlag = -1;
                __aad__4BitsFRC4Bits(&__1result, (const struct Bits *)(&__2tryit));
                if (!count__4BitsCFv((const struct Bits *)(&__1result))) {
                    struct Block_Bits_chunk *__0__X229;

                    const struct Block_Bits_chunk *__2__X230;

                    {
                        {
                            (*((((((__0__X229 = (&__0_result->b__4Bits)),
                                   ((__2__X230 = (const struct Block_Bits_chunk
                                                      *)(&((*((const struct Bits *)(&__1zeroBits))))
                                                              .b__4Bits)),
                                    (((__0__X229 ||
                                       (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl(
                                            (size_t)(sizeof(struct Block_Bits_chunk)))))
                                          ? (((void)copy__16Block_Bits_chunkFRC16Block_Bits_chunk(
                                                __0__X229, __2__X230)))
                                          : (((void)0))),
                                     __0__X229))),
                                  (__0_result->n__4Bits =
                                       ((*((const struct Bits *)(&__1zeroBits)))).n__4Bits)),
                                 0)),
                               __0_result));

                            {
                                ((((void)((
                                    (void)(((__0__X45 = (&(&__2tryit)->b__4Bits)),
                                            ((__0__X45
                                                  ? (((void)(__dl__FPv((void *)__0__X45
                                                                           ->p__16Block_Bits_chunk),
                                                             (__0__X45 ? (((void)(((void)0))))
                                                                       : (((void)0))))))
                                                  : (((void)0))))),
                                           (((void)0))))))));

                                ((((void)((
                                    (void)(((__0__X45 = (&(&__1result)->b__4Bits)),
                                            ((__0__X45
                                                  ? (((void)(__dl__FPv((void *)__0__X45
                                                                           ->p__16Block_Bits_chunk),
                                                             (__0__X45 ? (((void)(((void)0))))
                                                                       : (((void)0))))))
                                                  : (((void)0))))),
                                           (((void)0))))))));

                                ((((void)((
                                    (void)(((__0__X45 = (&(&__1zeroBits)->b__4Bits)),
                                            ((__0__X45
                                                  ? (((void)(__dl__FPv((void *)__0__X45
                                                                           ->p__16Block_Bits_chunk),
                                                             (__0__X45 ? (((void)(((void)0))))
                                                                       : (((void)0))))))
                                                  : (((void)0))))),
                                           (((void)0))))))));
                            }
                        }
                        return;
                    }
                }

                ((((void)(((
                    void)(((__0__X45 = (&(&__2tryit)->b__4Bits)),
                           ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                          (((void)0))))))));
            }
            {
                {
                    (*((((((__0__X229 = (&__0_result->b__4Bits)),
                           ((__2__X230 =
                                 (const struct Block_Bits_chunk
                                      *)(&((*((const struct Bits *)(&__1result)))).b__4Bits)),
                            (((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl(
                                                 (size_t)(sizeof(struct Block_Bits_chunk)))))
                                  ? (((void)copy__16Block_Bits_chunkFRC16Block_Bits_chunk(
                                        __0__X229, __2__X230)))
                                  : (((void)0))),
                             __0__X229))),
                          (__0_result->n__4Bits =
                               ((*((const struct Bits *)(&__1result)))).n__4Bits)),
                         0)),
                       __0_result));

                    ((((void)((
                        (void)(((__0__X45 = (&(&__1result)->b__4Bits)),
                                ((__0__X45
                                      ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                               (((void)0))))))));

                    ((((void)((
                        (void)(((__0__X45 = (&(&__1zeroBits)->b__4Bits)),
                                ((__0__X45
                                      ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                               (((void)0))))))));
                }
                return;
            }
        }
    }
}

static void best_const__FRC11Block_PnameiP4type(struct Bits *__0_result, const struct Block_Pname *,
                                                int, Ptype);

static Pname breakTie__FRC11Block_PnameR4BitsP4expri(const struct Block_Pname *__1FV,
                                                     struct Bits *__1bestOnes, Pexpr __1arg,
                                                     int __1cO) {
    int __1numFunc;
    struct Bits __1zeroBits;
    struct Bits __1result;

    struct Block_Pname __1rfunc;

    int __1i;

    struct Block_Bits_chunk *__0__X45;

    struct name *__0_result;

    __1numFunc = (((const struct Bits *)__1bestOnes)->n__4Bits);
    __ct__4BitsFUlT1(&__1zeroBits, (unsigned long)0, (unsigned long)__1numFunc);
    __co__FRC4Bits(&__1result, (const struct Bits *)(&__1zeroBits));

    (((((&__1rfunc)->n__11Block_Pname = 0),
       (((&__1rfunc)->p__11Block_Pname = 0),
        (move__11Block_PnameFPP4nameUl(
             (&__1rfunc),
             (Pname *)(((struct name **)__nw__FUl(
                 (size_t)((sizeof(struct name *)) * ((unsigned long)__1numFunc))))),
             ((unsigned long)__1numFunc)),
         (&__1rfunc)->n__11Block_Pname)))),
     (&__1rfunc));

    __1i = 0;
    while (
        (*((((const Pname *)(&(((const struct Block_Pname *)__1FV)->p__11Block_Pname[__1i]))))))) {
        const struct Block_Bits_chunk *__0__X43;

        int __2__X44;

        register struct name *__0__X244;

        unsigned long __2__X16;

        struct ea __0__X__V1400qmhwx544vcnm;

        struct ea __0__X__V1500qmhwx544vcnm;

        if ((((((unsigned long)__1i) >= ((const struct Bits *)__1bestOnes)->n__4Bits)
                  ? (((int)0))
                  : (((int)((((*((__0__X43 =
                                      (const struct Block_Bits_chunk
                                           *)(&((const struct Bits *)__1bestOnes)->b__4Bits)),
                                 ((__2__X44 = ((((unsigned long)__1i) >> 5))),
                                  ((((const Bits_chunk *)(&(
                                      __0__X43->p__16Block_Bits_chunk[__2__X44]))))))))) >>
                             (((unsigned long)__1i) & 31)) &
                            1))))))
            ((*((((Pname *)(&((&__1rfunc)->p__11Block_Pname[__1i]))))))) =
                ((__0__X244 = ((*((((const Pname *)(&(
                      ((const struct Block_Pname *)__1FV)->p__11Block_Pname[__1i])))))))),
                 (((__0__X244->__O1__4expr.tp->base__4node == 108)
                       ? (((struct fct *)(((struct fct *)__0__X244->__O1__4expr.tp))))
                       : (error__FiPCcRC2eaN33(
                              (int)'i', (const char *)"N::fct_type():%n is %k notF",
                              (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)->__O1__2ea.p =
                                                       ((const void *)__0__X244)),
                                                  (&__0__X__V1400qmhwx544vcnm)),
                              (const struct ea
                                   *)((__2__X16 = __0__X244->__O1__4expr.tp->base__4node),
                                      (((((&__0__X__V1500qmhwx544vcnm)->__O1__2ea.i = __2__X16),
                                         0)),
                                       (&__0__X__V1500qmhwx544vcnm))),
                              (const struct ea *)ea0, (const struct ea *)ea0),
                          (((struct fct *)0))))))
                    ->argtype__3fct;
        __1i++;
    }

    {
        int __1stat;

        int __2__X251;

        register struct name *__0__X252;

        unsigned long __2__X16;

        struct ea __0__X__V1400qmhwx544vcnm;

        struct ea __0__X__V1500qmhwx544vcnm;

        __1stat =
            ((__0__X252 =
                  ((*((__2__X251 = (signif__4BitsCFv((const struct Bits *)__1bestOnes) - 1)),
                      ((((const Pname *)(&(
                          ((const struct Block_Pname *)__1FV)->p__11Block_Pname[__2__X251]))))))))),
             (((__0__X252->__O1__4expr.tp->base__4node == 108)
                   ? (((struct fct *)(((struct fct *)__0__X252->__O1__4expr.tp))))
                   : (error__FiPCcRC2eaN33(
                          (int)'i', (const char *)"N::fct_type():%n is %k notF",
                          (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)->__O1__2ea.p =
                                                   ((const void *)__0__X252)),
                                              (&__0__X__V1400qmhwx544vcnm)),
                          (const struct ea
                               *)((__2__X16 = __0__X252->__O1__4expr.tp->base__4node),
                                  (((((&__0__X__V1500qmhwx544vcnm)->__O1__2ea.i = __2__X16), 0)),
                                   (&__0__X__V1500qmhwx544vcnm))),
                          (const struct ea *)ea0, (const struct ea *)ea0),
                      (((struct fct *)0))))))
                ->f_static__3fct;
        {
            {
                int __1k;

                __1k = 0;

                for (; __1k < __1numFunc; __1k++) {
                    const struct Block_Bits_chunk *__0__X43;

                    int __2__X44;

                    if ((((((unsigned long)__1k) >= ((const struct Bits *)__1bestOnes)->n__4Bits)
                              ? (((int)0))
                              : (((int)((((*((__0__X43 = (const struct Block_Bits_chunk
                                                              *)(&((const struct Bits *)__1bestOnes)
                                                                      ->b__4Bits)),
                                             ((__2__X44 = ((((unsigned long)__1k) >> 5))),
                                              ((((const Bits_chunk *)(&(
                                                  __0__X43
                                                      ->p__16Block_Bits_chunk[__2__X44]))))))))) >>
                                         (((unsigned long)__1k) & 31)) &
                                        1)))))) {
                        register struct name *__0__X245;

                        unsigned long __2__X16;

                        struct ea __0__X__V1400qmhwx544vcnm;

                        struct ea __0__X__V1500qmhwx544vcnm;

                        if (__1stat !=
                            ((__0__X245 =
                                  ((*((((const Pname *)(&(((const struct Block_Pname *)__1FV)
                                                              ->p__11Block_Pname[__1k])))))))),
                             (((__0__X245->__O1__4expr.tp->base__4node == 108)
                                   ? (((struct fct *)(((struct fct *)__0__X245->__O1__4expr.tp))))
                                   : (error__FiPCcRC2eaN33(
                                          (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                          (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)
                                                                   ->__O1__2ea.p =
                                                                   ((const void *)__0__X245)),
                                                              (&__0__X__V1400qmhwx544vcnm)),
                                          (const struct ea *)((__2__X16 = __0__X245->__O1__4expr.tp
                                                                              ->base__4node),
                                                              (((((&__0__X__V1500qmhwx544vcnm)
                                                                      ->__O1__2ea.i = __2__X16),
                                                                 0)),
                                                               (&__0__X__V1500qmhwx544vcnm))),
                                          (const struct ea *)ea0, (const struct ea *)ea0),
                                      (((struct fct *)0))))))
                                ->f_static__3fct) {
                            int __2__X246;

                            fmError__FiRC11Block_PnameP4exprUc(1, __1FV, __1arg,
                                                               (unsigned char)__1cO);
                            miFlag = 0;
                            {
                                {
                                    __0_result =
                                        ((*((__2__X246 = (signif__4BitsCFv(
                                                              (const struct Bits *)__1bestOnes) -
                                                          1)),
                                            ((((const Pname *)(&(
                                                ((const struct Block_Pname *)__1FV)
                                                    ->p__11Block_Pname[__2__X246]))))))));

                                    ((((void)(__dl__FPv((void *)(&__1rfunc)->p__11Block_Pname),
                                              (((void)(((void)0))))))));

                                    ((((void)((
                                        (void)(((__0__X45 = (&(&__1result)->b__4Bits)),
                                                ((__0__X45
                                                      ? (((void)(__dl__FPv(
                                                                     (void *)__0__X45
                                                                         ->p__16Block_Bits_chunk),
                                                                 (__0__X45 ? (((void)(((void)0))))
                                                                           : (((void)0))))))
                                                      : (((void)0))))),
                                               (((void)0))))))));

                                    ((((void)((
                                        (void)(((__0__X45 = (&(&__1zeroBits)->b__4Bits)),
                                                ((__0__X45
                                                      ? (((void)(__dl__FPv(
                                                                     (void *)__0__X45
                                                                         ->p__16Block_Bits_chunk),
                                                                 (__0__X45 ? (((void)(((void)0))))
                                                                           : (((void)0))))))
                                                      : (((void)0))))),
                                               (((void)0))))))));
                                }
                                return __0_result;
                            }
                        }
                    }
                }

                {
                    {
                        Pexpr __1aargu;

                        __1aargu = __1arg;

                        for (; __1aargu; __1aargu = __1aargu->__O3__4expr.e2) {
                            Ptype __2at;

                            struct Bits __2temp;

                            struct Block_Bits_chunk *__0__X45;

                            __2at = __1aargu->__O2__4expr.e1->__O1__4expr.tp;

                            best_const__FRC11Block_PnameiP4type(
                                &__2temp, (const struct Block_Pname *)(&__1rfunc), __1numFunc,
                                __2at);
                            if (count__4BitsCFv((const struct Bits *)(&__2temp)))
                                __aad__4BitsFRC4Bits(&__1result, (const struct Bits *)(&__2temp));

                            if (!count__4BitsCFv((const struct Bits *)(&__1result))) {
                                {
                                    ((((void)((
                                        (void)(((__0__X45 = (&(&__2temp)->b__4Bits)),
                                                ((__0__X45
                                                      ? (((void)(__dl__FPv(
                                                                     (void *)__0__X45
                                                                         ->p__16Block_Bits_chunk),
                                                                 (__0__X45 ? (((void)(((void)0))))
                                                                           : (((void)0))))))
                                                      : (((void)0))))),
                                               (((void)0))))))));

                                    break;
                                }
                            }

                            {{int __2k;

                            __2k = 0;

                            for (; __2k < __1numFunc; __2k++) {
                                if ((*((((Pname *)(&((&__1rfunc)->p__11Block_Pname[__2k])))))))
                                    ((*((((Pname *)(&((&__1rfunc)->p__11Block_Pname[__2k]))))))) =
                                        ((*((((Pname *)(&((&__1rfunc)->p__11Block_Pname[__2k])))))))
                                            ->__O1__4name.n_list;
                            }
                        }
                    }

                    ((((void)((
                        (void)(((__0__X45 = (&(&__2temp)->b__4Bits)),
                                ((__0__X45
                                      ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                               (((void)0))))))));
                }

                {
                    Pfct __1pf;

                    register struct Block_Bits_chunk *__0__X232;

                    const struct Block_Bits_chunk *__2__X233;

                    int __2__X249;

                    register struct name *__0__X250;

                    unsigned long __2__X16;

                    struct ea __0__X__V1400qmhwx544vcnm;

                    struct ea __0__X__V1500qmhwx544vcnm;

                    __1pf =
                        ((__0__X250 = ((*((((const Pname *)(&(
                              ((const struct Block_Pname *)__1FV)->p__11Block_Pname[0])))))))),
                         (((__0__X250->__O1__4expr.tp->base__4node == 108)
                               ? (((struct fct *)(((struct fct *)__0__X250->__O1__4expr.tp))))
                               : (error__FiPCcRC2eaN33(
                                      (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                      (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)
                                                               ->__O1__2ea.p =
                                                               ((const void *)__0__X250)),
                                                          (&__0__X__V1400qmhwx544vcnm)),
                                      (const struct ea
                                           *)((__2__X16 = __0__X250->__O1__4expr.tp->base__4node),
                                              (((((&__0__X__V1500qmhwx544vcnm)->__O1__2ea.i =
                                                      __2__X16),
                                                 0)),
                                               (&__0__X__V1500qmhwx544vcnm))),
                                      (const struct ea *)ea0, (const struct ea *)ea0),
                                  (((struct fct *)0))))));
                    if ((count__4BitsCFv((const struct Bits *)(&__1result)) >= 1) &&
                        __1pf->memof__3fct) {
                        struct Bits __2temp;

                        struct Block_Bits_chunk *__0__X45;

                        struct Block_Bits_chunk *__0__X229;

                        const struct Block_Bits_chunk *__2__X230;

                        ((((((__0__X229 = (&(&__2temp)->b__4Bits)),
                             ((__2__X230 =
                                   (const struct Block_Bits_chunk
                                        *)(&((*((const struct Bits *)(&__1zeroBits)))).b__4Bits)),
                              (((__0__X229 || (__0__X229 = (struct Block_Bits_chunk *)__nw__FUl(
                                                   (size_t)(sizeof(struct Block_Bits_chunk)))))
                                    ? (((void)copy__16Block_Bits_chunkFRC16Block_Bits_chunk(
                                          __0__X229, __2__X230)))
                                    : (((void)0))),
                               __0__X229))),
                            ((&__2temp)->n__4Bits =
                                 ((*((const struct Bits *)(&__1zeroBits)))).n__4Bits)),
                           0)),
                         (&__2temp));
                        {{int __2k;

                        __2k = 0;

                        for (; __2k < __1numFunc; __2k++) {
                            const struct Block_Bits_chunk *__0__X43;

                            int __2__X44;

                            if ((((((unsigned long)__2k) >=
                                   ((const struct Bits *)__1bestOnes)->n__4Bits)
                                      ? (((int)0))
                                      : (((int)((((*((__0__X43 = (const struct Block_Bits_chunk
                                                                      *)(&((const struct Bits *)
                                                                               __1bestOnes)
                                                                              ->b__4Bits)),
                                                     ((__2__X44 = ((((unsigned long)__2k) >> 5))),
                                                      ((((const Bits_chunk *)(&(
                                                          __0__X43->p__16Block_Bits_chunk
                                                              [__2__X44]))))))))) >>
                                                 (((unsigned long)__2k) & 31)) &
                                                1)))))) {
                                register struct name *__0__X247;

                                unsigned long __2__X16;

                                struct ea __0__X__V1400qmhwx544vcnm;

                                struct ea __0__X__V1500qmhwx544vcnm;

                                register struct name *__0__X248;

                                struct Block_Bits_chunk *__0__X37;

                                int __2__X38;

                                if (__1stat !=
                                    ((__0__X247 = ((*(
                                          (((const Pname *)(&(((const struct Block_Pname *)__1FV)
                                                                  ->p__11Block_Pname[__2k])))))))),
                                     (((__0__X247->__O1__4expr.tp->base__4node == 108)
                                           ? (((struct fct *)((
                                                 (struct fct *)__0__X247->__O1__4expr.tp))))
                                           : (error__FiPCcRC2eaN33(
                                                  (int)'i',
                                                  (const char *)"N::fct_type():%n is %k notF",
                                                  (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)
                                                                           ->__O1__2ea.p = ((
                                                                           const void *)__0__X247)),
                                                                      (&__0__X__V1400qmhwx544vcnm)),
                                                  (const struct ea
                                                       *)((__2__X16 = __0__X247->__O1__4expr.tp
                                                                          ->base__4node),
                                                          (((((&__0__X__V1500qmhwx544vcnm)
                                                                  ->__O1__2ea.i = __2__X16),
                                                             0)),
                                                           (&__0__X__V1500qmhwx544vcnm))),
                                                  (const struct ea *)ea0, (const struct ea *)ea0),
                                              (((struct fct *)0))))))
                                        ->f_static__3fct) {
                                    register struct Block_Bits_chunk *__0__X232;

                                    const struct Block_Bits_chunk *__2__X233;

                                    (((((*((__0__X232 = (&(&__1result)->b__4Bits)),
                                           ((__2__X233 =
                                                 (const struct Block_Bits_chunk
                                                      *)(&((*((const struct Bits *)(&__1zeroBits))))
                                                              .b__4Bits)),
                                            (__dl__FPv((void *)__0__X232->p__16Block_Bits_chunk),
                                             (copy__16Block_Bits_chunkFRC16Block_Bits_chunk(
                                                  __0__X232, __2__X233),
                                              (((struct Block_Bits_chunk *)__0__X232)))))))),
                                       ((&__1result)->n__4Bits =
                                            ((*((const struct Bits *)(&__1zeroBits)))).n__4Bits)),
                                      ((*(&__1result)))),
                                     (((struct Bits *)(&__1result))));
                                    break;
                                }
                                if (__1cO ==
                                    ((__0__X248 = ((*(
                                          (((const Pname *)(&(((const struct Block_Pname *)__1FV)
                                                                  ->p__11Block_Pname[__2k])))))))),
                                     (((__0__X248->__O1__4expr.tp->base__4node == 108)
                                           ? (((struct fct *)((
                                                 (struct fct *)__0__X248->__O1__4expr.tp))))
                                           : (error__FiPCcRC2eaN33(
                                                  (int)'i',
                                                  (const char *)"N::fct_type():%n is %k notF",
                                                  (const struct ea *)(((&__0__X__V1400qmhwx544vcnm)
                                                                           ->__O1__2ea.p = ((
                                                                           const void *)__0__X248)),
                                                                      (&__0__X__V1400qmhwx544vcnm)),
                                                  (const struct ea
                                                       *)((__2__X16 = __0__X248->__O1__4expr.tp
                                                                          ->base__4node),
                                                          (((((&__0__X__V1500qmhwx544vcnm)
                                                                  ->__O1__2ea.i = __2__X16),
                                                             0)),
                                                           (&__0__X__V1500qmhwx544vcnm))),
                                                  (const struct ea *)ea0, (const struct ea *)ea0),
                                              (((struct fct *)0))))))
                                        ->f_const__3fct)
                                    (((((unsigned long)__2k) < (&__2temp)->n__4Bits)
                                          ? (((*((__0__X37 = (&(&__2temp)->b__4Bits)),
                                                 ((__2__X38 = ((((unsigned long)__2k) >> 5))),
                                                  ((((Bits_chunk *)(&(
                                                      __0__X37->p__16Block_Bits_chunk
                                                          [__2__X38]))))))))) |=
                                             ((((unsigned long)1)) << (((unsigned long)__2k) & 31)))
                                          : 0),
                                     (((struct Bits *)(&__2temp))));
                            }
                        }
                        if (count__4BitsCFv((const struct Bits *)(&__2temp)))
                            __aad__4BitsFRC4Bits(&__1result, (const struct Bits *)(&__2temp));
                    }
                }

                ((((void)(((
                    void)(((__0__X45 = (&(&__2temp)->b__4Bits)),
                           ((__0__X45 ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                          (((void)0))))))));
            }

            if ((count__4BitsCFv((const struct Bits *)(&__1result)) == 0) ||
                (count__4BitsCFv((const struct Bits *)(&__1result)) >= 2)) {
                fmError__FiRC11Block_PnameP4exprUc(1, __1FV, __1arg, (unsigned char)__1cO);
                miFlag = 0;
            } else
                (((((*((__0__X232 = (&((struct Bits *)__1bestOnes)->b__4Bits)),
                       ((__2__X233 = (const struct Block_Bits_chunk
                                          *)(&((*((const struct Bits *)(&__1result)))).b__4Bits)),
                        (__dl__FPv((void *)__0__X232->p__16Block_Bits_chunk),
                         (copy__16Block_Bits_chunkFRC16Block_Bits_chunk(__0__X232, __2__X233),
                          (((struct Block_Bits_chunk *)__0__X232)))))))),
                   (((struct Bits *)__1bestOnes)->n__4Bits =
                        ((*((const struct Bits *)(&__1result)))).n__4Bits)),
                  ((*((struct Bits *)__1bestOnes)))),
                 (((struct Bits *)((struct Bits *)__1bestOnes))));

            {
                {
                    __0_result =
                        ((*((__2__X249 = (signif__4BitsCFv((const struct Bits *)__1bestOnes) - 1)),
                            ((((const Pname *)(&(((const struct Block_Pname *)__1FV)
                                                     ->p__11Block_Pname[__2__X249]))))))));

                    ((((void)(__dl__FPv((void *)(&__1rfunc)->p__11Block_Pname),
                              (((void)(((void)0))))))));

                    ((((void)((
                        (void)(((__0__X45 = (&(&__1result)->b__4Bits)),
                                ((__0__X45
                                      ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                               (((void)0))))))));

                    ((((void)((
                        (void)(((__0__X45 = (&(&__1zeroBits)->b__4Bits)),
                                ((__0__X45
                                      ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                               (((void)0))))))));
                }
                return __0_result;
            }
        }
    }
}
}
}
}
}

static void best_const__FRC11Block_PnameiP4type(struct Bits *__0_result,
                                                const struct Block_Pname *__1CONV, int __1nfound,
                                                Ptype __1at) {
    struct Bits __1zeroBits;

    struct Bits __1tempBits;
    int __1sigbit;

    struct Block_Bits_chunk *__0__X45;

    struct Block_Bits_chunk *__0__X41;

    int __2__X42;

    __ct__4BitsFUlT1(&__1zeroBits, (unsigned long)0, (unsigned long)__1nfound);
    __co__FRC4Bits(__0_result, (const struct Bits *)(&__1zeroBits));

    __co__FRC4Bits(&__1tempBits, (const struct Bits *)(&__1zeroBits));
    __1sigbit = (signif__4BitsCFv((const struct Bits *)(&__1tempBits)) - 1);
    (((((unsigned long)__1sigbit) < (&__1tempBits)->n__4Bits)
          ? (((*((__0__X41 = (&(&__1tempBits)->b__4Bits)),
                 ((__2__X42 = ((((unsigned long)__1sigbit) >> 5))),
                  ((((Bits_chunk *)(&(__0__X41->p__16Block_Bits_chunk[__2__X42]))))))))) &=
             (~((((unsigned long)1)) << (((unsigned long)__1sigbit) & 31))))
          : 0),
     (((struct Bits *)(&__1tempBits))));

    {
        {
            int __1i;

            __1i = 0;

            for (; __1i < __1nfound; __1i++) {
                if (((*((((const Pname *)(&(
                        ((const struct Block_Pname *)__1CONV)->p__11Block_Pname[__1i]))))))) == 0) {

                    struct Block_Bits_chunk *__0__X41;

                    int __2__X42;

                    (((((unsigned long)__1i) < (&__1tempBits)->n__4Bits)
                          ? (((*((__0__X41 = (&(&__1tempBits)->b__4Bits)),
                                 ((__2__X42 = ((((unsigned long)__1i) >> 5))),
                                  ((((Bits_chunk *)(&(
                                      __0__X41->p__16Block_Bits_chunk[__2__X42]))))))))) &=
                             (~((((unsigned long)1)) << (((unsigned long)__1i) & 31))))
                          : 0),
                     (((struct Bits *)(&__1tempBits))));
                    (((((unsigned long)__1i) < __0_result->n__4Bits)
                          ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                 ((__2__X42 = ((((unsigned long)__1i) >> 5))),
                                  ((((Bits_chunk *)(&(
                                      __0__X41->p__16Block_Bits_chunk[__2__X42]))))))))) &=
                             (~((((unsigned long)1)) << (((unsigned long)__1i) & 31))))
                          : 0),
                     (((struct Bits *)__0_result)));
                }
            }

            while (count__4BitsCFv((const struct Bits *)(&__1tempBits))) {
                int __2tempPtr;
                Pname __2t1name;

                __2tempPtr = (signif__4BitsCFv((const struct Bits *)(&__1tempBits)) - 1);
                __2t1name = ((*((((const Pname *)(&(
                    ((const struct Block_Pname *)__1CONV)->p__11Block_Pname[__2tempPtr])))))));
                {
                    {
                        int __2k;

                        struct Block_Bits_chunk *__0__X41;

                        int __2__X42;

                        __2k = (__1nfound - 1);

                        for (; __2k > __2tempPtr; __2k--) {
                            const struct Block_Bits_chunk *__0__X43;

                            int __2__X44;

                            if (!(((((unsigned long)__2k) >=
                                    ((const struct Bits *)__0_result)->n__4Bits)
                                       ? (((int)0))
                                       : (((int)((((*((__0__X43 = (const struct Block_Bits_chunk
                                                                       *)(&((const struct Bits *)
                                                                                __0_result)
                                                                               ->b__4Bits)),
                                                      ((__2__X44 = ((((unsigned long)__2k) >> 5))),
                                                       ((((const Bits_chunk *)(&(
                                                           __0__X43->p__16Block_Bits_chunk
                                                               [__2__X44]))))))))) >>
                                                  (((unsigned long)__2k) & 31)) &
                                                 1))))))
                                continue;
                            {
                                Pname __3t2name;
                                Ptype __3t1;
                                Ptype __3t2;
                                Pptr __3p1;

                                Pptr __3p2;

                                __3t2name =
                                    ((*((((const Pname *)(&(((const struct Block_Pname *)__1CONV)
                                                                ->p__11Block_Pname[__2k])))))));
                                __3t1 = __2t1name->__O1__4expr.tp;
                                __3t2 = __3t2name->__O1__4expr.tp;
                                __3p1 = is_ref__4typeFv(__3t1);

                                __3p2 = is_ref__4typeFv(__3t2);
                                if (__3p1 && (!__3p2))
                                    __3t1 = __3p1->typ__5pvtyp;
                                if (__3p2 && (!__3p1))
                                    __3t2 = __3p2->typ__5pvtyp;
                                ((__3p1 = is_ptr__4typeFv(__3t1)),
                                 (__3p2 = is_ptr__4typeFv(__3t2)));
                                if (__3p1 && __3p2) {
                                    struct Block_Bits_chunk *__0__X41;

                                    int __2__X42;

                                    if ((check__4typeFP4typeUcT2(__1at, __3t1, (unsigned char)76,
                                                                 (unsigned char)0) == 0) &&
                                        check__4typeFP4typeUcT2(__1at, __3t2, (unsigned char)76,
                                                                (unsigned char)0))
                                        (((((unsigned long)__2k) < __0_result->n__4Bits)
                                              ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                                     ((__2__X42 = ((((unsigned long)__2k) >> 5))),
                                                      ((((Bits_chunk *)(&(
                                                          __0__X41->p__16Block_Bits_chunk
                                                              [__2__X42]))))))))) &=
                                                 (~((((unsigned long)1))
                                                    << (((unsigned long)__2k) & 31))))
                                              : 0),
                                         (((struct Bits *)__0_result)));
                                    else if (check__4typeFP4typeUcT2(__1at, __3t1,
                                                                     (unsigned char)76,
                                                                     (unsigned char)0) &&
                                             (check__4typeFP4typeUcT2(__1at, __3t2,
                                                                      (unsigned char)76,
                                                                      (unsigned char)0) == 0)) {
                                        struct Block_Bits_chunk *__0__X41;

                                        int __2__X42;

                                        (((((unsigned long)__2tempPtr) < __0_result->n__4Bits)
                                              ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                                     ((__2__X42 =
                                                           ((((unsigned long)__2tempPtr) >> 5))),
                                                      ((((Bits_chunk *)(&(
                                                          __0__X41->p__16Block_Bits_chunk
                                                              [__2__X42]))))))))) &=
                                                 (~((((unsigned long)1))
                                                    << (((unsigned long)__2tempPtr) & 31))))
                                              : 0),
                                         (((struct Bits *)__0_result)));
                                        break;
                                    }
                                } else {
                                    Pptr __4p1;
                                    Pptr __4p2;

                                    __4p1 = is_ref__4typeFv(__3t1);
                                    __4p2 = is_ref__4typeFv(__3t2);

                                    if (__4p1 && __4p2) {
                                        struct Block_Bits_chunk *__0__X41;

                                        int __2__X42;

                                        if ((check__4typeFP4typeUcT2(__1at, __4p1->typ__5pvtyp,
                                                                     (unsigned char)76,
                                                                     (unsigned char)0) == 0) &&
                                            check__4typeFP4typeUcT2(__1at, __4p2->typ__5pvtyp,
                                                                    (unsigned char)76,
                                                                    (unsigned char)0))
                                            (((((unsigned long)__2k) < __0_result->n__4Bits)
                                                  ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                                         ((__2__X42 =
                                                               ((((unsigned long)__2k) >> 5))),
                                                          ((((Bits_chunk *)(&(
                                                              __0__X41->p__16Block_Bits_chunk
                                                                  [__2__X42]))))))))) &=
                                                     (~((((unsigned long)1))
                                                        << (((unsigned long)__2k) & 31))))
                                                  : 0),
                                             (((struct Bits *)__0_result)));
                                        else if (check__4typeFP4typeUcT2(__1at, __4p1->typ__5pvtyp,
                                                                         (unsigned char)76,
                                                                         (unsigned char)0) &&
                                                 (check__4typeFP4typeUcT2(__1at, __4p2->typ__5pvtyp,
                                                                          (unsigned char)76,
                                                                          (unsigned char)0) == 0)) {
                                            struct Block_Bits_chunk *__0__X41;

                                            int __2__X42;

                                            (((((unsigned long)__2tempPtr) < __0_result->n__4Bits)
                                                  ? (((*((__0__X41 = (&__0_result->b__4Bits)),
                                                         ((__2__X42 = ((
                                                               ((unsigned long)__2tempPtr) >> 5))),
                                                          ((((Bits_chunk *)(&(
                                                              __0__X41->p__16Block_Bits_chunk
                                                                  [__2__X42]))))))))) &=
                                                     (~((((unsigned long)1))
                                                        << (((unsigned long)__2tempPtr) & 31))))
                                                  : 0),
                                             (((struct Bits *)__0_result)));
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        (((((unsigned long)__2tempPtr) < (&__1tempBits)->n__4Bits)
                              ? (((*((__0__X41 = (&(&__1tempBits)->b__4Bits)),
                                     ((__2__X42 = ((((unsigned long)__2tempPtr) >> 5))),
                                      ((((Bits_chunk *)(&(
                                          __0__X41->p__16Block_Bits_chunk[__2__X42]))))))))) &=
                                 (~((((unsigned long)1)) << (((unsigned long)__2tempPtr) & 31))))
                              : 0),
                         (((struct Bits *)(&__1tempBits))));
                    }
                }
            }
            {
                {
                    ;

                    ((((void)((
                        (void)(((__0__X45 = (&(&__1tempBits)->b__4Bits)),
                                ((__0__X45
                                      ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                               (((void)0))))))));

                    ((((void)((
                        (void)(((__0__X45 = (&(&__1zeroBits)->b__4Bits)),
                                ((__0__X45
                                      ? (((void)(__dl__FPv((void *)__0__X45->p__16Block_Bits_chunk),
                                                 (__0__X45 ? (((void)(((void)0)))) : (((void)0))))))
                                      : (((void)0))))),
                               (((void)0))))))));
                }
                return;
            }
        }
    }
}

void fmError__FiRC11Block_PnameP4exprUc(int __1errorKind, const struct Block_Pname *__1FV,
                                        Pexpr __1arg, bit __1co) {
    Pname __1fn;

    __1fn =
        ((((*((((const Pname *)(&(((const struct Block_Pname *)__1FV)->p__11Block_Pname[0])))))))
              ->__O1__4expr.tp->base__4node == 76)
             ? (((struct gen *)((
                    (struct gen *)((*((((const Pname *)(&(((const struct Block_Pname *)__1FV)
                                                              ->p__11Block_Pname[0])))))))
                        ->__O1__4expr.tp))))
                   ->fct_list__3gen->f__9name_list
             : (((struct name *)((*((((const Pname *)(&(
                   ((const struct Block_Pname *)__1FV)->p__11Block_Pname[0]))))))))));

    switch (__1errorKind) {
    case 0:
        error__FiPCc((int)'e', (const char *)"no match for call: ");

        break;
    case 1:
        ambig = 1;
        error__FiPCc((int)'e', (const char *)"ambiguous call: ");
        break;
    }

    {
        Pclass __1tmp;

        const void *__2__X268;

        const void *__2__X269;

        __1tmp = (((__1fn->__O1__4expr.tp->base__4node == 108)
                       ? (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))))
                       : (((struct fct *)((
                             (struct fct *)(((struct gen *)(((struct gen *)__1fn->__O1__4expr.tp))))
                                 ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))))
                     ->memof__3fct;

        if (__1tmp) {
            struct ea __0__V255;

            struct ea __0__V256;

            error__FiPCcRC2eaN33(
                (int)'c', (const char *)"%s %t* -> ",
                (const struct ea *)(((&__0__V255)->__O1__2ea.p =
                                         ((const void *)(__1co ? "const" : (((char *)""))))),
                                    (&__0__V255)),
                (const struct ea *)(((&__0__V256)->__O1__2ea.p = ((const void *)__1tmp)),
                                    (&__0__V256)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__1fn->n_oper__4name && (__1fn->n_oper__4name != 161)) {
            struct ea __0__V257;

            error__FiPCcRC2eaN33(
                (int)'c', (const char *)"operator %s(",
                (const struct ea *)((__2__X268 = (const void *)(keys[__1fn->n_oper__4name])),
                                    (((&__0__V257)->__O1__2ea.p = __2__X268), (&__0__V257))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        } else if (__1fn->n_oper__4name == 161) {
            {
                struct ea __0__V258;

                struct ea __0__V259;

                error__FiPCcRC2eaN33(
                    (int)'c', (const char *)"%t::%t(",
                    (const struct ea *)(((&__0__V258)->__O1__2ea.p = ((const void *)__1tmp)),
                                        (&__0__V258)),
                    (const struct ea *)(((&__0__V259)->__O1__2ea.p = ((const void *)__1tmp)),
                                        (&__0__V259)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
        } else {
            struct ea __0__V260;

            error__FiPCcRC2eaN33(
                (int)'c', (const char *)"%s(",
                (const struct ea *)((__2__X269 = (const void *)__1fn->__O2__4expr.string),
                                    (((&__0__V260)->__O1__2ea.p = __2__X269), (&__0__V260))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__1arg) {
            Pexpr __2tmp;

            const void *__2__X270;

            __2tmp = __1arg;
            {
                struct ea __0__V261;

                error__FiPCcRC2eaN33(
                    (int)'c', (const char *)"%t",
                    (const struct ea *)((__2__X270 = (const void *)skiptypedefs__4typeFv(
                                             __2tmp->__O2__4expr.e1->__O1__4expr.tp)),
                                        (((&__0__V261)->__O1__2ea.p = __2__X270), (&__0__V261))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                while (__2tmp = __2tmp->__O3__4expr.e2) {
                    const void *__2__X271;

                    {
                        struct ea __0__V262;

                        error__FiPCcRC2eaN33(
                            (int)'c', (const char *)",%t",
                            (const struct ea *)((__2__X271 = (const void *)skiptypedefs__4typeFv(
                                                     __2tmp->__O2__4expr.e1->__O1__4expr.tp)),
                                                (((&__0__V262)->__O1__2ea.p = __2__X271),
                                                 (&__0__V262))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
            }
        }
        error__FiPCc((int)'c', (const char *)")\n");

        {
            struct ea __0__V263;

            error__FiPCcRC2eaN33(
                (int)'C', (const char *)"choice of%ns:\n",
                (const struct ea *)(((&__0__V263)->__O1__2ea.p = ((const void *)__1fn)),
                                    (&__0__V263)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

            if (((*((((const Pname *)(&(
                     ((const struct Block_Pname *)__1FV)->p__11Block_Pname[0])))))))
                    ->__O1__4expr.tp->base__4node == 76) {
                int __2num_templ;

                int __2no_const;
                int __2num_all;

                __2num_templ = 0;
                __2no_const = 0;
                __2num_all = 0;
                {
                    {
                        Plist __2gl;

                        __2gl =
                            (((struct gen *)(((struct gen *)((*((((const Pname *)(&(
                                                                 ((const struct Block_Pname *)__1FV)
                                                                     ->p__11Block_Pname[0])))))))
                                                  ->__O1__4expr.tp))))
                                ->fct_list__3gen;

                        for (; __2gl; __2gl = __2gl->l__9name_list) {
                            struct name *__0__X272;

                            const void *__2__X273;

                            if (((__0__X272 = __2gl->f__9name_list),
                                 (__0__X272->n_template_fct__4name))) {
                                __2num_templ++;
                            } else {
                                struct ea __0__V264;

                                error__FiPCcRC2eaN33(
                                    (int)'C', (const char *)"	%a;\n",
                                    (const struct ea *)((__2__X273 =
                                                             (const void *)__2gl->f__9name_list),
                                                        (((&__0__V264)->__O1__2ea.p = __2__X273),
                                                         (&__0__V264))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            if (__1co &&
                                (!(((struct fct *)((
                                       (struct fct *)__2gl->f__9name_list->__O1__4expr.tp))))
                                      ->f_const__3fct))
                                __2no_const++;
                            __2num_all++;
                        }
                        if (__2num_templ) {
                            {
                                struct ea __0__V265;

                                struct ea __0__V266;

                                error__FiPCcRC2eaN33(
                                    (int)'C', (const char *)"	%d template version%s;\n",
                                    (const struct ea *)(((((&__0__V265)->__O1__2ea.i =
                                                               ((unsigned long)__2num_templ)),
                                                          0)),
                                                        (&__0__V265)),
                                    (const struct ea *)(((&__0__V266)->__O1__2ea.p = ((
                                                             const void *)((__2num_templ == 1)
                                                                               ? ""
                                                                               : (((char *)"s"))))),
                                                        (&__0__V266)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                        }
                        if (__2no_const == __2num_all)
                            error__FiPCc((int)'C',
                                         (const char *)"(no usable const member function)\n");

                        return;
                    }
                }
            }

            {
                int __1numFunc;

                __1numFunc = (((const struct Block_Pname *)__1FV)->n__11Block_Pname);
                {
                    {
                        int __1i;

                        __1i = 0;

                        for (; __1i < __1numFunc; __1i++) {
                            const void *__2__X274;

                            if ((*((((const Pname *)(&(((const struct Block_Pname *)__1FV)
                                                           ->p__11Block_Pname[__1i]))))))) {
                                struct ea __0__V267;

                                error__FiPCcRC2eaN33(
                                    (int)'C', (const char *)"	%a;\n",
                                    (const struct ea *)((__2__X274 = (const void *)((*((((
                                                             const Pname *)(&(
                                                             ((const struct Block_Pname *)__1FV)
                                                                 ->p__11Block_Pname[__1i])))))))),
                                                        (((&__0__V267)->__O1__2ea.p = __2__X274),
                                                         (&__0__V267))),
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

static Pname *__vc__11Block_PnameFi(struct Block_Pname *__0this, int __2i) {
    return (&(__0this->p__11Block_Pname[__2i]));
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
