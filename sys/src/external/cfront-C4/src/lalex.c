
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
union YYSTYPE;

typedef union YYSTYPE YYSTYPE;

union YYSTYPE { /* sizeof YYSTYPE == 8 */
    const char *s__7YYSTYPE;
    TOK t__7YYSTYPE;
    int i__7YYSTYPE;
    struct loc l__7YYSTYPE;
    Pname pn__7YYSTYPE;
    Ptype pt__7YYSTYPE;
    Pexpr pe__7YYSTYPE;
    Pstmt ps__7YYSTYPE;
    Pbase pb__7YYSTYPE;
    Pnlist nl__7YYSTYPE;
    Pslist sl__7YYSTYPE;
    Pelist el__7YYSTYPE;
    Pbcl pbc__7YYSTYPE;
    Pptr pp__7YYSTYPE;
    PP p__7YYSTYPE;
    Plist pl__7YYSTYPE;
    struct toknode *q__7YYSTYPE;
};

extern union YYSTYPE yylval;

void *__nw__7toknodeSFUl(size_t);
void __dl__7toknodeSFPvUl(void *, size_t);

extern struct toknode *front;

extern int yychar;
extern union YYSTYPE yylval;

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

extern int parameters_in_progress__17templ_compilation;

struct toknode { /* sizeof toknode == 48 */
    TOK tok__7toknode;
    bit used__7toknode;
    union YYSTYPE retval__7toknode;
    Pname idname__7toknode;
    struct loc place__7toknode;
    struct toknode *next__7toknode;
    struct toknode *last__7toknode;
};

extern struct toknode *free_toks__7toknode;

struct toknode *free_toks__7toknode = 0;

int bl_level = 0;

static int lasttk = 0;
static union YYSTYPE lastval;

static int must_be_expr = 0;
int must_be_id = 0;

struct loc curloc = {0};
int curr_file = 0;

static struct toknode *latok;
struct toknode *front = 0;
static struct toknode *rear = 0;

void *__nw__7toknodeSFUl(size_t __1__A26) {
    struct toknode *__1p;

    if ((__1p = free_toks__7toknode) == 0) {
        struct toknode *__2q;
        free_toks__7toknode =
            (__2q = (((struct toknode *)(((char *)__nw__FUl((size_t)(768 * (sizeof(char)))))))));
        __1p = free_toks__7toknode;
        for (; __2q != (&(__1p[15])); ((__2q->next__7toknode = (__2q + 1)), (++__2q)))
            ;
        __2q->next__7toknode = 0;
    }
    free_toks__7toknode = __1p->next__7toknode;
    return (void *)__1p;
}

struct toknode *__ct__7toknodeFUc7YYSTYPE3loc(register struct toknode *__0this, TOK __1t,
                                              union YYSTYPE __1r, struct loc __1tloc) {
    if (__0this ||
        (__0this = (struct toknode *)__nw__7toknodeSFUl((size_t)(sizeof(struct toknode))))) {
        __0this->tok__7toknode = __1t;
        __0this->used__7toknode = 0;
        __0this->retval__7toknode = __1r;
        __0this->place__7toknode = __1tloc;
        __0this->next__7toknode = (__0this->last__7toknode = 0);
    }
    return __0this;
}

void __dl__7toknodeSFPvUl(void *__1vp, size_t __1__A27) {
    struct toknode *__1p;

    __1p = (((struct toknode *)(((struct toknode *)__1vp))));
    __1p->next__7toknode = free_toks__7toknode;
    free_toks__7toknode = __1p;
    __1vp = 0;
}

extern TOK tlex__Fv(void);

static void add_tokens__Fv(void) {
    TOK __1tk;

    __1tk = tlex__Fv();
    if (__1tk != 80)
        return;

    while (((__1tk == 80) || (__1tk == 160)) || (__1tk == 45))
        __1tk = tlex__Fv();
}
enum __E28 { one_back = 0, two_back = 1 };

static TOK last_tokens[2];
static Pname last_tname;

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

extern int strcmp(const char *, const char *);

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

extern Pname k_find_member__FPCcP8classdefUc(const char *, Pclass, TOK);

extern Pname k_find_name__FPCcP6ktableUc(const char *, Pktab, TOK);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

static void use_token__FP7toknode(struct toknode *__1T) {
    __1T->used__7toknode = 1;
    {
        static bit __1aggr = 0;
        if ((__1T->tok__7toknode == 156) || (__1T->tok__7toknode == 13))
            __1aggr = 1;
        else if ((__1T->tok__7toknode != 160) && (__1T->tok__7toknode != 80))
            __1aggr = 0;

        ;

        switch (__1T->tok__7toknode) {
        case 44:
        case 45: {
            struct toknode *__3t;
            Pname __3q;

            Pname __3r;

            __3t = __1T;
            __3q = 0;

            __3r = 0;
            for (;;) {
                if (__3t->next__7toknode == 0)
                    add_tokens__Fv();
                __3t = __3t->next__7toknode;
                if ((__3t->tok__7toknode == 80) && (__3t->next__7toknode->tok__7toknode == 160)) {
                    Pname __5n;

                    __5n = __ct__4nameFPCc((struct name *)0, __3t->retval__7toknode.s__7YYSTYPE);
                    __5n->base__4node = 176;
                    if (__3q == 0)
                        __3q = (__3r = __5n);
                    else {
                        __3r->__O1__4name.n_list = __5n;

                        __3r = __5n;
                    }
                    __3t = __3t->next__7toknode;
                } else if (__3t->tok__7toknode == 160) {
                    Pname __5n;

                    __5n = __ct__4nameFPCc((struct name *)0, (const char *)0);
                    __5n->base__4node = 176;
                    if (__3q == 0)
                        __3q = (__3r = __5n);
                    else {
                        __3r->__O1__4name.n_list = __5n;

                        __3r = __5n;
                    }
                } else
                    break;
            }
            if (__3q) {
                struct toknode *__4x;

                struct toknode *__4xx;

                __4x = __1T->next__7toknode;

                __4xx = __4x->next__7toknode;
                __4x->tok__7toknode = 176;
                __4x->retval__7toknode.pn__7YYSTYPE = __3q;
                __4x->used__7toknode = 1;
                __4x->next__7toknode = __3t;
                __3t->last__7toknode->next__7toknode = 0;
                __3t->last__7toknode = __4x;
                for (; __4xx; __4xx = __4x) {
                    __4x = __4xx->next__7toknode;

                    ((__4xx
                          ? (((void)(__4xx
                                         ? (((void)(((void)__dl__7toknodeSFPvUl(
                                               (void *)__4xx, (size_t)(sizeof(struct toknode)))))))
                                         : (((void)0)))))
                          : (((void)0))));
                }
            }
            break;
        }
        case 80:
            if ((last_tokens[0]) == 176)
                break;
            {
                Pname __3n;
                TOK __3sc;

                __3n = 0;
                __3sc = (((__1T->next__7toknode && (__1T->next__7toknode->tok__7toknode == 160)) ||
                          __1aggr)
                             ? 159
                             : 0);

                if (((last_tokens[0]) == 160) ||
                    (((last_tokens[0]) == 178) && (!in_progress__17templ_compilation))) {
                    if (((last_tokens[1]) == 123) ||
                        (((last_tokens[1]) == 60) && ((last_tokens[0]) != 160))) {

                        if (((last_tokens[1]) == 60) && ((last_tokens[0]) == 178)) {
                            extern union YYSTYPE yyval;
                            last_tname = yyval.pn__7YYSTYPE;
                        }

                        {
                            Pname __5tn;

                            const void *__2__X36;

                            __5tn = last_tname;
                            if (__5tn == 0) {
                                struct ea __0__V29;

                                error__FiP3locPCcRC2eaN34(
                                    (int)'i', &__1T->place__7toknode,
                                    (const char *)"last_tname not set for tname::%s",
                                    (const struct ea
                                         *)((__2__X36 =
                                                 (const void *)__1T->retval__7toknode.s__7YYSTYPE),
                                            (((&__0__V29)->__O1__2ea.p = __2__X36), (&__0__V29))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            while (__5tn->__O1__4expr.tp &&
                                   (__5tn->__O1__4expr.tp->base__4node == 97))
                                __5tn = (((struct basetype *)((
                                             (struct basetype *)__5tn->__O1__4expr.tp))))
                                            ->b_name__8basetype;
                            if (strcmp(__1T->retval__7toknode.s__7YYSTYPE,
                                       __5tn->__O2__4expr.string) == 0) {
                                __3n = __5tn;
                            } else if (__5tn->__O1__4expr.tp &&
                                       (__5tn->__O1__4expr.tp->base__4node == 119)) {
                                Pclass __6cl;

                                int __1__Xt00admtho24vcnl;

                                const void *__2__X37;

                                __6cl = (((struct classdef *)((
                                    (struct classdef *)(((struct basetype *)((
                                                            (struct basetype *)
                                                                __5tn->__O1__4expr.tp))))
                                        ->b_name__8basetype->__O1__4expr.tp))));

                                if (((__1__Xt00admtho24vcnl =
                                          ((((struct type *)__6cl)->base__4node == 108)
                                               ? (((struct fct *)((
                                                      (struct fct *)((struct type *)__6cl)))))
                                                     ->fct_base__3fct
                                               : ((((struct type *)__6cl)->base__4node == 6)
                                                      ? (((struct classdef *)(((struct classdef *)((
                                                             struct type *)__6cl)))))
                                                            ->class_base__8classdef
                                                      : (((int)0))))),
                                     (((unsigned char)((__1__Xt00admtho24vcnl == 4) ||
                                                       (__1__Xt00admtho24vcnl == 5))))) &&
                                    (strcmp(__1T->retval__7toknode.s__7YYSTYPE,
                                            ((((struct templ_classdef *)((
                                                  (struct templ_classdef *)__6cl))))
                                                 ->inst__14templ_classdef->def__10templ_inst
                                                 ->namep__5templ)
                                                ->__O2__4expr.string) == 0)) {
                                    __3n = __5tn;
                                } else if ((__6cl->defined__4type & 5) == 0) {
                                    struct ea __0__V30;

                                    struct ea __0__V31;

                                    struct ea __0__V32;

                                    error__FP3locPCcRC2eaN33(
                                        &__1T->place__7toknode, (const char *)"%n:: %s -- %tU",
                                        (const struct ea *)((__2__X37 = (const void *)last_tname),
                                                            (((&__0__V30)->__O1__2ea.p = __2__X37),
                                                             (&__0__V30))),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V31,
                                            (const void *)__1T->retval__7toknode.s__7YYSTYPE),
                                        (const struct ea *)(((&__0__V32)->__O1__2ea.p =
                                                                 ((const void *)__6cl)),
                                                            (&__0__V32)),
                                        (const struct ea *)ea0);
                                } else {
                                    __3n = k_find_member__FPCcP8classdefUc(
                                        __1T->retval__7toknode.s__7YYSTYPE, __6cl, __3sc);
                                    if (__3n && (__3n->n_ktable__4name == Gtbl))
                                        __3n = 0;
                                }
                            } else {
                                if (__5tn->__O1__4expr.tp->base__4node != 141) {
                                    struct ea __0__V33;

                                    struct ea __0__V34;

                                    struct ea __0__V35;

                                    error__FP3locPCcRC2eaN33(
                                        &__1T->place__7toknode,
                                        (const char *)"%n:: %s --%n not aCN",
                                        (const struct ea *)(((&__0__V33)->__O1__2ea.p =
                                                                 ((const void *)__5tn)),
                                                            (&__0__V33)),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V34,
                                            (const void *)__1T->retval__7toknode.s__7YYSTYPE),
                                        (const struct ea *)(((&__0__V35)->__O1__2ea.p =
                                                                 ((const void *)__5tn)),
                                                            (&__0__V35)),
                                        (const struct ea *)ea0);
                                }
                                __3n = k_find_name__FPCcP6ktableUc(
                                    __1T->retval__7toknode.s__7YYSTYPE, Ctbl, __3sc);
                            }
                        }
                    } else if ((last_tokens[1]) != 80) {
                        __3n = k_find_name__FPCcP6ktableUc(__1T->retval__7toknode.s__7YYSTYPE, Gtbl,
                                                           __3sc);
                    }
                } else
                    __3n = k_find_name__FPCcP6ktableUc(__1T->retval__7toknode.s__7YYSTYPE, Ctbl,
                                                       __3sc);
                __1T->idname__7toknode = __3n;
                if (__3n && (__3n->base__4node == 123)) {
                    __1T->tok__7toknode = 123;
                    __1T->retval__7toknode.pn__7YYSTYPE = __3n;
                    ;
                }

                break;
            }
        case 73:
            ++bl_level;

            break;
        case 74:
            --bl_level;

            break;
        }

        if ((__1T->tok__7toknode != 47) || ((last_tokens[0]) != 160)) {
            (last_tokens[1]) = (last_tokens[0]);
            (last_tokens[0]) = __1T->tok__7toknode;
            if (__1T->tok__7toknode == 123)
                last_tname = __1T->retval__7toknode.pn__7YYSTYPE;
        }
    }
}

static void la_reset__FP7toknodeP4name(struct toknode *__1T, Pname __1qual) {
    (last_tokens[0]) = 160;
    (last_tokens[1]) = 123;
    last_tname = __1qual;
    while (__1T && __1T->used__7toknode) {
        __1T->used__7toknode = 0;
        switch (__1T->tok__7toknode) {
        case 123:
            __1T->tok__7toknode = 80;
            __1T->retval__7toknode.s__7YYSTYPE =
                __1T->retval__7toknode.pn__7YYSTYPE->__O2__4expr.string;
            break;
        case 73:
            --bl_level;

            break;
        case 74:
            ++bl_level;

            break;
        }
        __1T = __1T->next__7toknode;
    }
}

void addtok__FUc7YYSTYPE3loc(TOK __1t, union YYSTYPE __1r, struct loc __1tloc) {
    struct toknode *__1T;

    __1T = __ct__7toknodeFUc7YYSTYPE3loc((struct toknode *)0, __1t, __1r, __1tloc);
    if (front == 0)
        front = (rear = __1T);
    else {
        rear->next__7toknode = __1T;
        __1T->last__7toknode = rear;
        rear = __1T;
    }
}

static Pname idname;

TOK deltok__Fi(int __1noset) {
    struct toknode *__1T;

    __1T = front;
    ;

    if (!__1T->used__7toknode)
        use_token__FP7toknode(__1T);

    ;
    {
        TOK __1tk;

        __1tk = __1T->tok__7toknode;
        if (!__1noset) {
            yylval = __1T->retval__7toknode;

            curloc = __1T->place__7toknode;
        }
        curr_file = curloc.file__3loc;
        if (front = front->next__7toknode)
            front->last__7toknode = 0;
        else
            latok = (rear = 0);
        idname = __1T->idname__7toknode;
        ((__1T ? (((void)(__1T ? (((void)(((void)__dl__7toknodeSFPvUl(
                                     (void *)__1T, (size_t)(sizeof(struct toknode)))))))
                               : (((void)0)))))
               : (((void)0))));
        return __1tk;
    }
}

static void del_tokens__FP7toknode(struct toknode *__1marker) {
    if (((__1marker == 0) || (__1marker == latok)) || (__1marker->next__7toknode == 0))
        error__FiPCc((int)'i', (const char *)"bad token queue");

    ;

    {
        struct toknode *__1tt;

        __1tt = __1marker->next__7toknode;
        if (__1tt == latok)
            return;
        __1marker->next__7toknode = latok;
        latok->last__7toknode->next__7toknode = 0;
        latok->last__7toknode = __1marker;
        {
            struct toknode *__1tx;

            __1tx = __1tt;
            do {
                ;
                __1tx = __1tx->next__7toknode;
                ((__1tt ? (((void)(__1tt ? (((void)(((void)__dl__7toknodeSFPvUl(
                                               (void *)__1tt, (size_t)(sizeof(struct toknode)))))))
                                         : (((void)0)))))
                        : (((void)0))));
                __1tt = __1tx;
            } while (__1tx);
        }
    }
}

static void del_1__FP7toknode(struct toknode *__1t) {
    if (__1t->last__7toknode)
        __1t->last__7toknode->next__7toknode = __1t->next__7toknode;
    else
        front = __1t->next__7toknode;
    if (latok == __1t)
        latok = (__1t->last__7toknode ? __1t->last__7toknode : front);
    if (__1t->next__7toknode)
        __1t->next__7toknode->last__7toknode = __1t->last__7toknode;
    else
        rear = __1t->last__7toknode;
    ((__1t ? (((void)(__1t ? (((void)(((void)__dl__7toknodeSFPvUl(
                                 (void *)__1t, (size_t)(sizeof(struct toknode)))))))
                           : (((void)0)))))
           : (((void)0))));
}

TOK la_look__Fv(void) {
    ;
    if (front == 0)
        add_tokens__Fv();

    latok = front;
    ;

    if (!latok->used__7toknode)
        use_token__FP7toknode(latok);

    ;
    ;
    return latok->tok__7toknode;
}

extern TOK lalex__Fv(void);

static TOK lookahead__Fv(void);

static int la_decl__Fi(int);
static int la_range_for__Fv(void);

void check_decl__Fv(void) {
    TOK __1tk2;
    switch ((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) {
        unsigned long __2__X39;

    default:
        break;
    case 178:;
        __1tk2 = la_look__Fv();
        while (__1tk2 == 178)
            __1tk2 = lookahead__Fv();
        if (__1tk2 == 123) {
            struct toknode *__3t;

            __3t = latok;
            if (__3t->tok__7toknode != 123)
                error__FiP3locPCcRC2eaN34((int)'i', &__3t->place__7toknode,
                                          (const char *)"check_decl() token scan",
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0);
            __1tk2 = lookahead__Fv();
            if ((__1tk2 == 40) && la_decl__Fi(in_arg_list)) {
                __3t->tok__7toknode = 179;
            }
        };
        break;
    case 179:
        if (in_arg_list == 0)
            break;

        yychar = DECL_TYPE;
        DECL_TYPE = 0;
        if ((yychar != 97) && (yychar != 123)) {
            struct ea __0__V38;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"check_decl() failed rescanning arg decl; yychar==%d",
                (const struct ea *)((__2__X39 = yychar),
                                    (((((&__0__V38)->__O1__2ea.i = __2__X39), 0)), (&__0__V38))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
    case 97:
    case 123:;
        if ((la_look__Fv() == 40) && la_decl__Fi(in_arg_list)) {
            must_be_id = 0;
            DECL_TYPE = yychar;
            yychar = 179;
            ;
        }
    }
}

extern int la_cast__Fv(void);

void check_cast__Fv(void) {
    TOK __1tk2;
    switch ((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) {
    case 178:
        __1tk2 = la_look__Fv();

        while (__1tk2 == 178)
            __1tk2 = lookahead__Fv();
        if (__1tk2 == 123) {
            struct toknode *__3t;

            __3t = latok;
            if (__3t->tok__7toknode != 123)
                error__FiP3locPCcRC2eaN34((int)'i', &__3t->place__7toknode,
                                          (const char *)"check_cast() token scan",
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0);
            __1tk2 = lookahead__Fv();
            if ((__1tk2 == 40) && la_decl__Fi(in_arg_list)) {
                __3t->tok__7toknode = 179;
            }
        }
        break;
    case 97:
    case 123:
        if ((la_look__Fv() == 40) && la_cast__Fv()) {
            must_be_id = 0;
            DECL_TYPE = yychar;
            yychar = 179;
        }
    }
}

static int latype__FUc(TOK __1t) {
    switch (__1t) {
    default:
        return 0;
    case 5:
    case 29:
    case 21:
    case 22:
    case 122:
    case 15:
    case 11:
    case 37:
        return 1;
    }
}

static int laexpr__FUc(TOK __1t) {
    switch (__1t) {
    default:
        return 0;
    case 28:
    case 23:
    case 52:
    case 66:
    case 65:
    case 67:
    case 30:
    case 46:
    case 47:
    case 50:
    case 54:
    case 55:
    case 64:
    case 70:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
        return 1;
    }
}

static struct toknode *get_next_token__FP7toknode(struct toknode *__1t) {
    if (!__1t->next__7toknode)
        add_tokens__Fv();

    return __1t->next__7toknode;
}

Pname is_cl_obj__4typeFv(struct type *__0this);

static int template_tscope__FP4nameP7toknode(Pname __1tn, struct toknode *__1lt) {
    int __1nest;

    __1nest = 0;

    if (__1lt->tok__7toknode != 58)
        error__FiPCc((int)'i', (const char *)"a `<' token was expected");

    parameters_in_progress__17templ_compilation++;

    {
        {
            struct toknode *__1t;

            __1t = __1lt;

            for (;; __1t = get_next_token__FP7toknode(__1t))
                switch (__1t->tok__7toknode) {
                case 58:
                    ++__1nest;
                    continue;
                case 60:
                    if ((--__1nest) == 0) {
                        __1t = get_next_token__FP7toknode(__1t);
                        if ((__1t->tok__7toknode == 160) || (__1t->tok__7toknode == 178)) {
                            if (__1t->next__7toknode == 0)
                                add_tokens__Fv();
                            if (__1t->next__7toknode->tok__7toknode == 50) {
                                __1t->tok__7toknode = 173;
                                del_1__FP7toknode(__1t->next__7toknode);
                            } else {
                                __1t->tok__7toknode = 178;

                                if ((__1t->next__7toknode->tok__7toknode == 80) &&
                                    in_progress__17templ_compilation) {
                                    Pname __6cn;

                                    __6cn = is_cl_obj__4typeFv(__1tn->__O1__4expr.tp);
                                    if (__6cn) {
                                        int __7hh;
                                        Pname __7tn2;

                                        __7hh =
                                            (__1t->next__7toknode->next__7toknode->tok__7toknode ==
                                             160);
                                        __7tn2 = k_find_member__FPCcP8classdefUc(
                                            __1t->next__7toknode->retval__7toknode.s__7YYSTYPE,
                                            ((struct classdef *)((
                                                (struct classdef *)__6cn->__O1__4expr.tp))),
                                            (unsigned char)__7hh);

                                        if (__7tn2 && (__7tn2->base__4node == 123)) {
                                            __1t->next__7toknode->tok__7toknode = 123;
                                            __1t->next__7toknode->retval__7toknode.pn__7YYSTYPE =
                                                __7tn2;
                                        }
                                    }
                                }
                            }
                            __1t->retval__7toknode.pn__7YYSTYPE = __1tn;
                            --parameters_in_progress__17templ_compilation;
                            return 1;
                        } else {
                            --parameters_in_progress__17templ_compilation;
                            return 0;
                        }
                    }
                    continue;

                case 72:
                case 73:
                case 74:
                case 0:
                    --parameters_in_progress__17templ_compilation;
                    return 0;

                default:
                    continue;
                }
        }
    }
}

void hide__4nameFv(struct name *__0this);

static TOK lookahead__Fv(void) {
    TOK __1tk;
    TOK __1tk2;
    TOK __1prev_tk;
    union YYSTYPE __1lastval;

    __1prev_tk = 0;

    if (latok == rear) {
        add_tokens__Fv();
        if (latok)
            latok = latok->next__7toknode;
        else
            latok = front;
    } else
        latok = latok->next__7toknode;

    if (latok->last__7toknode) {
        __1prev_tk = latok->last__7toknode->tok__7toknode;
        __1lastval = latok->last__7toknode->retval__7toknode;
    }

nexttok:;

    if (!latok->used__7toknode)
        use_token__FP7toknode(latok);

    ;
    __1tk = latok->tok__7toknode;
    if ((__1tk == 80) || (__1tk == 123)) {
        if (latok->next__7toknode == 0)
            add_tokens__Fv();
        ;

        if (!latok->next__7toknode->used__7toknode)
            use_token__FP7toknode(latok->next__7toknode);

        ;
        __1tk2 = latok->next__7toknode->tok__7toknode;
        if (__1tk == 123) {
            if (__1tk2 == 58) {
                if (template_tscope__FP4nameP7toknode(latok->retval__7toknode.pn__7YYSTYPE,
                                                      latok->next__7toknode))
                    __1tk = 209;
            } else if ((__1tk2 == 160) || (__1tk2 == 45)) {
            tscope:
                __1tk = 178;

                latok = latok->next__7toknode;
                if (latok->next__7toknode == 0)
                    add_tokens__Fv();
                ;

                if (!latok->next__7toknode->used__7toknode)
                    use_token__FP7toknode(latok->next__7toknode);

                ;
                __1tk2 = latok->next__7toknode->tok__7toknode;
                if (__1tk2 == 50) {
                    __1tk = 173;
                    latok = latok->next__7toknode;
                }
            } else if (((__1prev_tk == 50) && (__1tk2 != 41)) || (__1prev_tk == 52)) {
                __1tk = 80;
                hide__4nameFv(latok->retval__7toknode.pn__7YYSTYPE);
                latok->tok__7toknode = 80;
                latok->retval__7toknode.s__7YYSTYPE =
                    latok->retval__7toknode.pn__7YYSTYPE->__O2__4expr.string;
            }
        } else if (__1tk2 == 160) {
            goto tscope;
        }

        if ((__1tk == 80) &&
            ((__1tk2 == 80) || ((__1prev_tk == 80) && ((__1tk2 == 69) || (__1tk2 == 73))))) {
            latok = latok->next__7toknode;

            goto nexttok;
        }
    }

    return __1tk;
}

extern int in_sizeof;
extern int in_friend;
extern int in_new;

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

static int type_is_redefined__FP4name(Pname __1n) {
    Pktab __1tb;

    __1tb = Ctbl;
    while (__1tb->k_id__6ktable == 136)
        __1tb = __1tb->k_next__6ktable;
    return (__1n->n_ktable__4name == __1tb);
}

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

Pclass classtype__4typeFv(struct type *__0this);

Pname tname__4nameFUc(struct name *__0this, TOK);

struct name_list *__ct__9name_listFP4nameP9name_list(struct name_list *__0this, Pname __1ff,
                                                     Plist __1ll);

static Pname do_nl_type__FP4nameiUc(Pname __1n, int __1lex_level, TOK __1tecsu) {
    Pname __1nn;

    __1nn = __1n;
    if ((ccl && (in_mem_fct == 0)) &&
        (strcmp(ccl->string__8classdef, __1n->__O2__4expr.string) == 0)) {
        {
            struct ea __0__V40;

            struct ea __0__V41;

            error__FPCcRC2eaN32(
                (const char *)"nested%k%n redefines immediately enclosing class",
                (const struct ea *)(((((&__0__V40)->__O1__2ea.i =
                                           ((unsigned long)((__1tecsu == 97)
                                                                ? (((unsigned int)190))
                                                                : (((unsigned int)__1tecsu))))),
                                      0)),
                                    (&__0__V40)),
                (const struct ea *)(((&__0__V41)->__O1__2ea.p = ((const void *)__1n)), (&__0__V41)),
                (const struct ea *)ea0, (const struct ea *)ea0);
            error__FiPCc((int)'i', (const char *)"cannot recover from previous errors");
        }
    }
    switch (__1tecsu) {
    case 6:
    case 32:
    case 36:
    case 13:
        if (((__1n->base__4node == 123) && (__1n->lex_level__4name == __1lex_level)) &&
            type_is_redefined__FP4name(__1n)) {
            if ((__1n->__O1__4expr.tp == 0) || ((__1n->__O1__4expr.tp->base__4node != 119) &&
                                                (__1n->__O1__4expr.tp->base__4node != 121))) {
                return __1n;
            }

            if (((__1n->__O1__4expr.tp->base__4node == 121) && (__1tecsu != 13)) ||
                ((__1n->__O1__4expr.tp->base__4node == 119) && (__1tecsu == 13))) {
                {

                    struct ea __0__V42;

                    error__FPCcRC2eaN32(
                        (const char *)"%n defined asC and enum",
                        (const struct ea *)(((&__0__V42)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V42)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    error__FiPCc((int)'i', (const char *)"cannot recover");
                }
            }

            if ((__1n->__O1__4expr.tp->base__4node == 119) &&
                ((classtype__4typeFv(__1n->__O1__4expr.tp)->defined__4type & 5) == 0))
                return __1n;
        }
        __1nn = __ct__4nameFPCc((struct name *)0, __1n->__O2__4expr.string);
        __1nn->lex_level__4name = __1lex_level;
        __1nn = tname__4nameFUc(__1nn, __1tecsu);
        if (__1nn->n_ktable__4name == 0) {
            struct ea __0__V43;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"TN insert failed for%n",
                (const struct ea *)(((&__0__V43)->__O1__2ea.p = ((const void *)__1nn)),
                                    (&__0__V43)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if ((__1tecsu != 13) && (__1nn->n_ktable__4name->k_id__6ktable == 116))
            local_class =
                __ct__9name_listFP4nameP9name_list((struct name_list *)0, __1nn, local_class);

        break;
    default: {
        struct ea __0__V44;

        error__FiP3locPCcRC2eaN34(
            (int)'i', &__1n->where__4name, (const char *)"bad tecsu%k in do_nl_type()",
            (const struct ea *)(((((&__0__V44)->__O1__2ea.i = ((unsigned long)__1tecsu)), 0)),
                                (&__0__V44)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }
    return __1nn;
}

extern int error__FPCc(const char *);

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

void del__4nameFv(struct name *__0this);

TOK lalex__Fv(void) {
    TOK __1tk;
    if (front == 0)
        add_tokens__Fv();
    ;

gettok:
    __1tk = deltok__Fi(0);
    {
        Pname __1n;

        __1n = idname;

        if ((__1tk == 80) || (__1tk == 123)) {
            TOK __2tk2;
            int __2lex_level;

            __2tk2 = la_look__Fv();
            __2lex_level = ((bl_level - in_class_decl) - (__2tk2 == 73));

            if (__1tk == 123) {
                if (((((((__2tk2 == 40) && (lasttk != 178)) && (lasttk != 160)) &&
                       (((lasttk == 97) || (bl_level == 0)) || parsing_class_members)) &&
                      (laexpr__FUc((unsigned char)lasttk) == 0)) &&
                     (must_be_expr == 0)) &&
                    (DECL_TYPE == 0)) {
                    if (la_decl__Fi(in_arg_list)) {
                        must_be_id = 0;
                        DECL_TYPE = __1tk;
                        __1tk = 179;
                        goto ret;
                    }
                }

                if ((lasttk == 156) || (lasttk == 13)) {
                    if (((__2tk2 == 73) || (__2tk2 == 69)) ||
                        (((__2tk2 == 72) && (!in_new)) && (!in_friend))) {
                        if (in_friend) {
                            const void *__2__X86;

                            if (Ctbl->k_id__6ktable != 6) {
                                struct ea __0__V45;

                                error__FPCcRC2eaN32(
                                    (const char *)"friend %s not inC",
                                    (const struct ea *)((__2__X86 =
                                                             (const void *)yylval.pn__7YYSTYPE
                                                                 ->__O2__4expr.string),
                                                        (((&__0__V45)->__O1__2ea.p = __2__X86),
                                                         (&__0__V45))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                        } else if ((__2tk2 != 72) ||
                                   (type_is_redefined__FP4name(yylval.pn__7YYSTYPE) == 0)) {
                            if (__2lex_level && ((in_class_decl == 0) || in_mem_fct))
                                yylval.pn__7YYSTYPE = do_nl_type__FP4nameiUc(
                                    yylval.pn__7YYSTYPE, __2lex_level, lastval.t__7YYSTYPE);
                            else if (in_class_decl && ccl)
                                yylval.pn__7YYSTYPE = do_nl_type__FP4nameiUc(
                                    yylval.pn__7YYSTYPE, __2lex_level, lastval.t__7YYSTYPE);
                        }
                    }
                }

                if ((__2tk2 == 58) &&
                    template_tscope__FP4nameP7toknode(yylval.pn__7YYSTYPE, latok)) {
                    __1tk = 209;
                } else if ((__2tk2 == 160) ||
                           ((((__2tk2 == 45) && (lasttk != 44)) && (lasttk != 45)) &&
                            (lasttk != 180))) {
                    if (__2tk2 == 45)
                        error__FPCc(
                            (const char *)"``.'' used for qualification; please use ``::''");

                    if (yylval.pn__7YYSTYPE->__O1__4expr.tp->base__4node == 119) {
                        Pclass __5cl;
                        Pclass __5cl2;

                        struct classdef *__1__X87;

                        struct classdef *__1__X88;

                        const void *__2__X89;

                        __5cl = classtype__4typeFv(yylval.pn__7YYSTYPE->__O1__4expr.tp);
                        __5cl2 = ccl;
                        while (__5cl2 && __5cl2->in_class__4type)
                            __5cl2 = __5cl2->in_class__4type;
                        if ((__5cl && __5cl->class_base__8classdef) &&
                            (((__5cl2 == 0) || (__5cl2->templ_base__4type == 2)) ||
                             (((__1__X87 = __5cl),
                               ((__1__X88 = __5cl2),
                                (((__1__X87 == __1__X88)
                                      ? 1
                                      : ((__1__X87 && __1__X88)
                                             ? (((int)same_class__8classdefFP8classdefi(
                                                   __1__X87, __1__X88, 0)))
                                             : 0))))) == 0))) {

                            struct ea __0__V46;

                            error__FPCcRC2eaN32(
                                (const char *)"YC%n must be qualifiedWZL of instantiations",
                                (const struct ea *)((__2__X89 = (const void *)yylval.pn__7YYSTYPE),
                                                    (((&__0__V46)->__O1__2ea.p = __2__X89),
                                                     (&__0__V46))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                    }

                    __1tk = 178;
                    {
                        int __5n;

                        __5n = 0;
                        while ((__2tk2 = lookahead__Fv()) == 178)
                            __5n += 2;
                        if (__2tk2 == 123) {
                            Pname __6cn;
                            struct toknode *__6t;

                            __6cn = latok->retval__7toknode.pn__7YYSTYPE;
                            __6t = latok;
                            __2tk2 = lookahead__Fv();
                            if (((((__2tk2 == 40) && ((bl_level == 0) || parsing_class_members)) &&
                                  (laexpr__FUc((unsigned char)lasttk) == 0)) &&
                                 (must_be_expr == 0)) &&
                                (DECL_TYPE == 0)) {
                                if (la_decl__Fi(in_arg_list)) {
                                    must_be_id = 0;

                                    DECL_TYPE = 123;

                                    __5n++;
                                    __5n++;
                                    __1tk = 179;
                                    while ((__5n--) > 0)
                                        deltok__Fi(0);
                                    goto ret;
                                }
                                la_reset__FP7toknodeP4name(__6t->next__7toknode, __6cn);
                            }
                        }
                    }
                    __2tk2 = deltok__Fi(1);
                    __2tk2 = la_look__Fv();
                    if (__2tk2 == 50) {
                        __1tk = 173;
                        __2tk2 = deltok__Fi(1);
                    }
                } else if (must_be_id) {
                    const void *__2__X90;

                    ;
                    if (((in_class_decl && (lasttk == 97)) && (__2tk2 == 40)) &&
                        (strcmp(yylval.pn__7YYSTYPE->__O2__4expr.string, ccl->string__8classdef) ==
                         0)) {

                        struct ea __0__V47;

                        error__FPCcRC2eaN32(
                            (const char *)"%nK with returnT",
                            (const struct ea *)((__2__X90 = (const void *)yylval.pn__7YYSTYPE),
                                                (((&__0__V47)->__O1__2ea.p = __2__X90),
                                                 (&__0__V47))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else if (((lasttk == 97) && (lastval.t__7YYSTYPE == 76)) &&
                               ((__2tk2 == 72) || (__2tk2 == 40))) {
                        __1tk = 80;

                        hide__4nameFv(yylval.pn__7YYSTYPE);
                        yylval.pn__7YYSTYPE = __ct__4nameFPCc(
                            (struct name *)0, yylval.pn__7YYSTYPE->__O2__4expr.string);
                        yylval.pn__7YYSTYPE->n_oper__4name = 123;
                    } else if (lasttk == 24)
                        must_be_id = 0;
                    else if (((lasttk != 178) || (lastval.pn__7YYSTYPE != yylval.pn__7YYSTYPE)) ||
                             (in_typedef && (check__4typeFP4typeUcT2(
                                                 in_typedef, yylval.pn__7YYSTYPE->__O1__4expr.tp,
                                                 (unsigned char)0, (unsigned char)0) == 0))) {
                        ;
                        __1tk = 80;
                        if (in_typedef && ((lasttk == 50) || (lasttk == 44))) {
                            defer_check = 1;
                            in_tag = yylval.pn__7YYSTYPE;
                        }

                        if ((lasttk == 160) && yylval.pn__7YYSTYPE->lex_level__4name) {
                            Pname __6nn;

                            unsigned long __2__X91;

                            const void *__2__X92;

                            __6nn = k_find_name__FPCcP6ktableUc(
                                yylval.pn__7YYSTYPE->__O2__4expr.string, Gtbl, (unsigned char)0);
                            if ((__6nn == 0) || (__6nn->base__4node == 85)) {
                                struct ea __0__V48;

                                struct ea __0__V49;

                                error__FPCcRC2eaN32(
                                    (const char *)"%k%s undeclared",
                                    (const struct ea *)((__2__X91 = lasttk),
                                                        (((((&__0__V48)->__O1__2ea.i = __2__X91),
                                                           0)),
                                                         (&__0__V48))),
                                    (const struct ea *)((__2__X92 =
                                                             (const void *)yylval.pn__7YYSTYPE
                                                                 ->__O2__4expr.string),
                                                        (((&__0__V49)->__O1__2ea.p = __2__X92),
                                                         (&__0__V49))),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            } else
                                yylval.pn__7YYSTYPE = __6nn;
                        } else {
                            if ((((lasttk != 45) && (lasttk != 44)) && (lasttk != 178)) &&
                                (lasttk != 19)) {
                                if ((!in_typedef) || in_arg_list) {
                                    ;
                                    hide__4nameFv(yylval.pn__7YYSTYPE);
                                    yylval.pn__7YYSTYPE = __ct__4nameFPCc(
                                        (struct name *)0, yylval.pn__7YYSTYPE->__O2__4expr.string);
                                } else if (yylval.pn__7YYSTYPE->base__4node == 123) {
                                    yylval.pn__7YYSTYPE = __ct__4nameFPCc(
                                        (struct name *)0, yylval.pn__7YYSTYPE->__O2__4expr.string);
                                }

                                yylval.pn__7YYSTYPE->n_oper__4name = 123;
                            } else {
                                yylval.pn__7YYSTYPE = __ct__4nameFPCc(
                                    (struct name *)0, yylval.pn__7YYSTYPE->__O2__4expr.string);
                            };
                        }
                        if (defer_check)
                            defer_check = 0;
                    }
                }

                ;

            } else {
                const char *__3s;

                __3s = yylval.s__7YYSTYPE;
                if (__1n)
                    __1n = __1n->__O1__4name.n_hidden;

                if (__2tk2 == 160) {
                    {
                        struct ea __0__V50;

                        struct ea __0__V51;

                        error__FPCcRC2eaN32(
                            (const char *)"%s:: -- %sis not aTN",
                            (const struct ea *)(((&__0__V50)->__O1__2ea.p = ((const void *)__3s)),
                                                (&__0__V50)),
                            (const struct ea *)(((&__0__V51)->__O1__2ea.p = ((const void *)__3s)),
                                                (&__0__V51)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                        __2tk2 = deltok__Fi(1);
                        goto gettok;
                    }
                } else if ((lasttk == 13) ||
                           ((lasttk == 156) &&
                            ((in_arg_list != 2) || ((__2tk2 != 60) && (__2tk2 != 71))))) {
                    int __4tagdef;

                    __4tagdef = (((__2tk2 == 73) || (__2tk2 == 69)) ||
                                 (((__2tk2 == 72) && (!in_new)) && (!in_friend)));
                    __1tk = 123;

                    if (((__1n == 0) || (__1n->n_template_arg__4name == 1)) || __4tagdef) {
                        if (in_friend && __4tagdef) {
                            if (Ctbl->k_id__6ktable != 6) {

                                struct ea __0__V52;

                                error__FPCcRC2eaN32((const char *)"friend %s not inC",
                                                    (const struct ea *)(((&__0__V52)->__O1__2ea.p =
                                                                             ((const void *)__3s)),
                                                                        (&__0__V52)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                            }
                        } else if (((__1n == 0) || (__2tk2 != 72)) ||
                                   (!type_is_redefined__FP4name(__1n))) {
                            Pname __6nn;

                            __6nn = __ct__4nameFPCc((struct name *)0, __3s);
                            if (!__4tagdef)
                                __6nn->lex_level__4name = 0;
                            else
                                __6nn->lex_level__4name = __2lex_level;

                            if (((ccl && __4tagdef) && in_class_decl) &&
                                (bl_level ==
                                 ((ccl->lex_level__4type + in_class_decl) + (__2tk2 == 73)))) {
                                if (__1n) {
                                    if (__6nn && (__6nn->permanent__4node == 0))
                                        del__4nameFv(__6nn);

                                    __6nn = __1n;
                                }
                                __1n = do_nl_type__FP4nameiUc(__6nn, __2lex_level,
                                                              lastval.t__7YYSTYPE);
                            } else if (__6nn->lex_level__4name) {
                                int __7ll;

                                __7ll = __6nn->lex_level__4name;
                                if (__1n) {
                                    if (__6nn && (__6nn->permanent__4node == 0))
                                        del__4nameFv(__6nn);

                                    __6nn = __1n;
                                }
                                __1n = do_nl_type__FP4nameiUc(__6nn, __7ll, lastval.t__7YYSTYPE);
                            } else {
                                if (__1n == 0) {
                                    Pktab __8otbl;
                                    Pclass __8occl;

                                    __8otbl = Ctbl;
                                    __8occl = ccl;
                                    Ctbl = Gtbl;
                                    ccl = 0;
                                    __1n = tname__4nameFUc(__6nn, lastval.t__7YYSTYPE);
                                    Ctbl = __8otbl;
                                    ccl = __8occl;
                                } else if (__6nn && (__6nn->permanent__4node == 0))
                                    del__4nameFv(__6nn);
                            }
                        }

                    } else {
                        if ((__1n->__O1__4expr.tp->base__4node != 119) &&
                            (__1n->__O1__4expr.tp->base__4node != 121)) {
                            {
                                struct ea __0__V53;

                                struct ea __0__V54;

                                error__FPCcRC2eaN32(
                                    (const char *)"hidden%n:%t",
                                    (const struct ea *)(((&__0__V53)->__O1__2ea.p =
                                                             ((const void *)__1n)),
                                                        (&__0__V53)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V54, (const void *)__1n->__O1__4expr.tp),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                error__FiPCc((int)'i', (const char *)"cannot recover");
                            }
                        }
                    }
                    yylval.pn__7YYSTYPE = __1n;
                } else {
                    __1tk = 80;
                    yylval.pn__7YYSTYPE = __ct__4nameFPCc((struct name *)0, __3s);
                }

                if (__1tk == 80) {
                    switch (__2tk2) {
                    case 80:
                    case 123:
                    case 156:
                    case 13: {
                        Pname __6n;

                        __6n = 0;

                        __6n = k_find_name__FPCcP6ktableUc(__3s, Ctbl, (unsigned char)159);
                        if (__6n) {
                            const char *__7x;

                            __7x = (((__2tk2 == 80) || (__2tk2 == 123))
                                        ? front->retval__7toknode.s__7YYSTYPE
                                        : (keys[__2tk2]));

                            switch (__6n->__O1__4expr.tp->base__4node) {
                            default: {
                                struct ea __0__V55;

                                struct ea __0__V56;

                                struct ea __0__V57;

                                struct ea __0__V58;

                                error__FPCcRC2eaN32(
                                    (const char *)"%s%s:Tdef %sis %sin this scope",
                                    (const struct ea *)(((&__0__V55)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V55)),
                                    (const struct ea *)(((&__0__V56)->__O1__2ea.p =
                                                             ((const void *)__7x)),
                                                        (&__0__V56)),
                                    (const struct ea *)(((&__0__V57)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V57)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V58, (const void *)((__6n->n_key__4name == 159)
                                                                      ? "hidden"
                                                                      : (((char *)"undefined")))));
                                break;
                            case 119: {
                                struct ea __0__V59;

                                struct ea __0__V60;

                                struct ea __0__V61;

                                struct ea __0__V62;

                                error__FPCcRC2eaN32(
                                    (const char *)"%sis %sin this scope: useC %s%s",
                                    (const struct ea *)(((&__0__V59)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V59)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V60, (const void *)((__6n->n_key__4name == 159)
                                                                      ? "hidden"
                                                                      : (((char *)"undefined")))),
                                    (const struct ea *)(((&__0__V61)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V61)),
                                    (const struct ea *)(((&__0__V62)->__O1__2ea.p =
                                                             ((const void *)__7x)),
                                                        (&__0__V62)));
                                break;
                            case 121: {
                                struct ea __0__V63;

                                struct ea __0__V64;

                                struct ea __0__V65;

                                struct ea __0__V66;

                                error__FPCcRC2eaN32(
                                    (const char *)"%sis %sin this scope: use enum %s%s",
                                    (const struct ea *)(((&__0__V63)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V63)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V64, (const void *)((__6n->n_key__4name == 159)
                                                                      ? "hidden"
                                                                      : (((char *)"undefined")))),
                                    (const struct ea *)(((&__0__V65)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V65)),
                                    (const struct ea *)(((&__0__V66)->__O1__2ea.p =
                                                             ((const void *)__7x)),
                                                        (&__0__V66)));
                                break;
                            }
                            }
                            }
                            }
                            __1tk = 123;
                            yylval.pn__7YYSTYPE = __6n;
                        } else {
                            unsigned long __2__X95;

                            if (__2tk2 == 80) {
                                if ((lasttk == 178) && (lastval.pn__7YYSTYPE->base__4node == 123)) {
                                    const void *__2__X93;

                                    const void *__2__X94;

                                    if ((lastval.pn__7YYSTYPE->__O1__4expr.tp->base__4node ==
                                         141) &&
                                        (lastval.pn__7YYSTYPE->n_template_arg__4name == 1)) {
                                        struct ea __0__V67;

                                        struct ea __0__V68;

                                        error__FiPCcRC2eaN33(
                                            (int)'s', (const char *)"use of %n::%sW formalYTZ",
                                            (const struct ea
                                                 *)((__2__X93 = (const void *)lastval.pn__7YYSTYPE),
                                                    (((&__0__V67)->__O1__2ea.p = __2__X93),
                                                     (&__0__V67))),
                                            (const struct ea *)(((&__0__V68)->__O1__2ea.p =
                                                                     ((const void *)__3s)),
                                                                (&__0__V68)),
                                            (const struct ea *)ea0, (const struct ea *)ea0);
                                    } else if ((lastval.pn__7YYSTYPE->__O1__4expr.tp->base__4node ==
                                                119) &&
                                               (classtype__4typeFv(
                                                    lastval.pn__7YYSTYPE->__O1__4expr.tp)
                                                    ->class_base__8classdef != 0)) {
                                        struct ea __0__V69;

                                        struct ea __0__V70;

                                        error__FiPCcRC2eaN33(
                                            (int)'s',
                                            (const char *)"Zized nestedC access: %n<...>::%s",
                                            (const struct ea
                                                 *)((__2__X94 = (const void *)lastval.pn__7YYSTYPE),
                                                    (((&__0__V69)->__O1__2ea.p = __2__X94),
                                                     (&__0__V69))),
                                            (const struct ea *)(((&__0__V70)->__O1__2ea.p =
                                                                     ((const void *)__3s)),
                                                                (&__0__V70)),
                                            (const struct ea *)ea0, (const struct ea *)ea0);
                                    } else {
                                        struct ea __0__V71;

                                        struct ea __0__V72;

                                        struct ea __0__V73;

                                        error__FPCcRC2eaN32(
                                            (const char *)"%s%s: %sis not aTN",
                                            (const struct ea *)(((&__0__V71)->__O1__2ea.p =
                                                                     ((const void *)__3s)),
                                                                (&__0__V71)),
                                            (const struct ea *)__ct__2eaFPCv(
                                                &__0__V72,
                                                (const void *)front->retval__7toknode.s__7YYSTYPE),
                                            (const struct ea *)(((&__0__V73)->__O1__2ea.p =
                                                                     ((const void *)__3s)),
                                                                (&__0__V73)),
                                            (const struct ea *)ea0);
                                    }
                                    error__FiPCc(
                                        (int)'i',
                                        (const char *)"cannot recover from previous errors");
                                } else {
                                    struct ea __0__V74;

                                    struct ea __0__V75;

                                    struct ea __0__V76;

                                    error__FPCcRC2eaN32(
                                        (const char *)"%s%s: %sis not aTN",
                                        (const struct ea *)(((&__0__V74)->__O1__2ea.p =
                                                                 ((const void *)__3s)),
                                                            (&__0__V74)),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V75,
                                            (const void *)front->retval__7toknode.s__7YYSTYPE),
                                        (const struct ea *)(((&__0__V76)->__O1__2ea.p =
                                                                 ((const void *)__3s)),
                                                            (&__0__V76)),
                                        (const struct ea *)ea0);
                                }
                            } else if (__2tk2 == 123) {
                                struct ea __0__V77;

                                struct ea __0__V78;

                                struct ea __0__V79;

                                error__FPCcRC2eaN32(
                                    (const char *)"%s%s: %sis not aTN",
                                    (const struct ea *)(((&__0__V77)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V77)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V78, (const void *)front->retval__7toknode
                                                       .pn__7YYSTYPE->__O2__4expr.string),
                                    (const struct ea *)(((&__0__V79)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V79)),
                                    (const struct ea *)ea0);
                            } else {
                                struct ea __0__V80;

                                struct ea __0__V81;

                                struct ea __0__V82;

                                error__FPCcRC2eaN32(
                                    (const char *)"%s%k: %sis not aTN",
                                    (const struct ea *)(((&__0__V80)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V80)),
                                    (const struct ea *)((__2__X95 =
                                                             front->retval__7toknode.t__7YYSTYPE),
                                                        (((((&__0__V81)->__O1__2ea.i = __2__X95),
                                                           0)),
                                                         (&__0__V81))),
                                    (const struct ea *)(((&__0__V82)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V82)),
                                    (const struct ea *)ea0);
                            }
                            goto gettok;
                        }
                        break;
                    }
                    case 45:
                    case 44:
                        break;
                    default:
                        if ((lasttk == 123) && (__2tk2 == 73)) {
                            {
                                struct ea __0__V83;

                                struct ea __0__V84;

                                struct ea __0__V85;

                                error__FPCcRC2eaN32(
                                    (const char *)"T%s %k: %s is unexpected",
                                    (const struct ea *)(((&__0__V83)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V83)),
                                    (const struct ea *)(((((&__0__V84)->__O1__2ea.i =
                                                               ((unsigned long)__2tk2)),
                                                          0)),
                                                        (&__0__V84)),
                                    (const struct ea *)(((&__0__V85)->__O1__2ea.p =
                                                             ((const void *)__3s)),
                                                        (&__0__V85)),
                                    (const struct ea *)ea0);
                                goto gettok;
                            }
                        }

                        break;
                    }
                }
            }
        }
        if ((((((__1tk == 123) || ((__1tk == 97) && latype__FUc(yylval.t__7YYSTYPE))) ||
               (__1tk == 44)) ||
              (__1tk == 45)) ||
             (__1tk == 19)) ||
            (__1tk == 173))
            must_be_id = 1;
        else
            must_be_id = 0;

        switch (__1tk) {
        case 72:
        case 41:
        case 74:
            must_be_expr = 0;

            break;
        case 69:
            if ((lasttk == 41) || ((lasttk == 97) && (lastval.t__7YYSTYPE == 26)))
                must_be_expr = 1;
            break;
        case 30:
            ++in_sizeof;
            break;
        case 23:
            ++in_new;
            break;
        case 16: /* FOR: check for range-for */
            if (la_range_for__Fv())
                __1tk = 215; /* RANGE_FOR */
            break;
        }
    ret:
        lasttk = __1tk;
        lastval = yylval;

        ;

        return __1tk;
    }
}

void la_backup__FUc7YYSTYPE(TOK __1t, union YYSTYPE __1r) {
    ;
    switch (__1t) {
    case 80: {
        Pname __3n;

        __3n = __1r.pn__7YYSTYPE;

        __1r.s__7YYSTYPE = __3n->__O2__4expr.string;

        if (__3n && (__3n->permanent__4node == 0))
            del__4nameFv(__3n);

        break;
    }
    case 73:
        --bl_level;

        break;
    case 74:
        ++bl_level;

        break;
    }
    {
        struct toknode *__1T;

        __1T = __ct__7toknodeFUc7YYSTYPE3loc((struct toknode *)0, __1t, __1r, curloc);
        if (front) {
            front->last__7toknode = __1T;
            __1T->next__7toknode = front;
            __1T->last__7toknode = 0;
            front = __1T;
        } else
            front = (rear = __1T);
        lasttk = 0;
    }
}

static struct ea *__ct__2eaFUl(struct ea *__0this, size_t __2ii);

static int la_sctype__FUc(TOK __1t) {
    if (((__1t != latok->tok__7toknode) && (__1t != 178)) && (__1t != 173)) {
        struct ea __0__V96;

        struct ea __0__V97;

        error__FiP3locPCcRC2eaN34(
            (int)'i', &latok->place__7toknode, (const char *)"la_sctype t%k, latok->tok%k",
            (const struct ea *)(((((&__0__V96)->__O1__2ea.i = ((unsigned long)__1t)), 0)),
                                (&__0__V96)),
            (const struct ea *)__ct__2eaFUl(&__0__V97, (unsigned long)latok->tok__7toknode),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    switch (latok->retval__7toknode.t__7YYSTYPE) {
    case 35:
    case 14:
    case 31:
    case 2:
    case 27:
    case 76:
    case 75:
    case 18:
    case 26:
    case 170:
        return 1;
    default:
        return 0;
    }
}

static TOK ptname_tscope__FP7toknode(struct toknode *__1lt) {
    int __1nest;

    TOK __1tk;

    __1nest = 0;
    if (__1lt->tok__7toknode != 58)
        error__FiPCc((int)'i', (const char *)"ptname_tscope: a `<' token was expected");

    ;
    {
        {
            struct toknode *__1t;

            __1t = __1lt;

            for (;; __1t = get_next_token__FP7toknode(__1t)) {
                switch (__1t->tok__7toknode) {
                case 58:
                    ++__1nest;

                    continue;
                case 60:
                    if ((--__1nest) == 0) {
                        __1t = get_next_token__FP7toknode(__1t);
                        if (__1t->tok__7toknode == 160) {
                            if (__1t->next__7toknode == 0)
                                add_tokens__Fv();
                            if (__1t->next__7toknode->tok__7toknode == 50) {
                                __1t = __1t->next__7toknode;
                                __1tk = 173;
                            } else
                                __1tk = 178;
                            latok = __1t;
                            return __1tk;
                        } else if ((__1t->tok__7toknode == 173) || (__1t->tok__7toknode == 178)) {
                            latok = __1t;
                            return __1t->tok__7toknode;
                        } else {
                            latok = __1t;
                            return (unsigned char)209;
                        }
                    }
                    continue;

                case 72:
                case 73:
                case 74:
                case 0:
                    latok = __1t;
                    return (unsigned char)209;
                default:
                    continue;
                }
            }
        }
    }
}

int la_cast__Fv(void) {
    ;
    {
        int __1tk;

        int __1tk2;

        __1tk2 = latok->tok__7toknode;

        for (;;) {
            __1tk = __1tk2;
            if (__1tk == 209) {
                if (latok->tok__7toknode == 123)
                    latok->tok__7toknode = 209;
                if (latok->next__7toknode == 0)
                    add_tokens__Fv();
                __1tk2 = ptname_tscope__FP7toknode(latok->next__7toknode);
            } else
                __1tk2 = lookahead__Fv();

            switch (__1tk) {
            case 40:
                if ((((__1tk2 == 50) || (__1tk2 == 52)) || (__1tk2 == 173)) || (__1tk2 == 209))
                    continue;
                else
                    return 0;
            case 50:
            case 52:
            case 173:
                while ((__1tk2 == 97) && la_sctype__FUc((unsigned char)__1tk2))
                    __1tk2 = lookahead__Fv();

                continue;
            case 209:
                if (__1tk2 == 173)
                    continue;
                return 0;
            case 41:
            case 42:
                return 1;
            default:
                return 0;
            }
        }
    }
}

extern void UNSET_SCOPE__Fv(void);

extern Pname SET_SCOPE__FP4name(Pname);

/* Scan ahead from the current front of token queue to detect
 * a range-based for: for (T v : range) rather than for (init; cond; incr).
 * Returns 1 if a bare ':' is found at paren depth 1 before any ';'.
 * Called after FOR has been consumed, so front -> '(' ... ')'.
 */
static int la_range_for__Fv(void) {
    struct toknode *__1t;
    int __1depth = 0;
    int __1quest_at1 = 0; /* saw '?' at depth 1 */

    if (front == 0)
        add_tokens__Fv();

    for (__1t = front; __1t != 0; __1t = __1t->next__7toknode) {
        TOK __1tok = __1t->tok__7toknode;

        if (__1tok == 40) {           /* LP ( */
            ++__1depth;
        } else if (__1tok == 41) {    /* RP ) */
            if (--__1depth <= 0)
                return 0;
        } else if (__1tok == 68) {    /* QUEST ? */
            if (__1depth == 1)
                __1quest_at1 = 1;
        } else if (__1tok == 69) {    /* COLON : */
            if (__1depth == 1) {
                if (__1quest_at1) {
                    __1quest_at1 = 0; /* ternary ':', not range-for ':' */
                } else {
                    return 1;         /* range-for detected */
                }
            }
        } else if (__1tok == 72) {    /* SM ; */
            if (__1depth <= 1)
                return 0;             /* traditional for */
        } else if (__1tok == 0) {     /* EOFTOK */
            return 0;
        }

        if (__1t->next__7toknode == 0)
            add_tokens__Fv();
    }
    return 0;
}

static int la_decl__Fi(int __1arg_decl) {
    ;
    {
        int __1tk;

        int __1tk2;
        int __1paren;
        int __1ptr;
        static int __1scopesets = 0;

        __1tk2 = latok->tok__7toknode;
        __1paren = 0;
        __1ptr = 0;

        if (__1tk2 != 40) {
            struct ea __0__V98;

            error__FiP3locPCcRC2eaN34(
                (int)'d', &latok->place__7toknode,
                (const char *)"la_decl(): latok ==%k -- '(' expected",
                (const struct ea *)(((((&__0__V98)->__O1__2ea.i = ((unsigned long)__1tk2)), 0)),
                                    (&__0__V98)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        for (;;) {
            __1tk = __1tk2;
            if (__1tk == 209) {
                if (latok->tok__7toknode == 123)
                    latok->tok__7toknode = 209;
                if (latok->next__7toknode == 0)
                    add_tokens__Fv();
                __1tk2 = ptname_tscope__FP7toknode(latok->next__7toknode);
            } else
                __1tk2 = lookahead__Fv();

            switch (__1tk) {
            case 40:
                if (__1tk2 == 41) {
                    if (__1scopesets > 0)
                        do
                            UNSET_SCOPE__Fv();
                        while (--__1scopesets);

                    ;
                    return 0;
                }
                if ((__1paren && (__1ptr == 0)) && __1arg_decl) {
                    if (__1scopesets > 0)
                        do
                            UNSET_SCOPE__Fv();
                        while (--__1scopesets);

                    ;
                    return 0;
                }
                ++__1paren;
                __1ptr = 0;
                continue;
            case 50:
            case 52:
                __1ptr = 1;
                if ((__1tk2 == 97) && la_sctype__FUc((unsigned char)__1tk2)) {
                    if (__1scopesets > 0)
                        do
                            UNSET_SCOPE__Fv();
                        while (--__1scopesets);

                    ;
                    return 1;
                } else {
                    continue;
                }
            case 173:
                if (__1scopesets > 0)
                    do
                        UNSET_SCOPE__Fv();
                    while (--__1scopesets);

                ;
                return 1;
            case 178:
                if (((__1tk2 == 80) || (__1tk2 == 24)) && (!__1arg_decl)) {
                    if ((latok->last__7toknode->last__7toknode->tok__7toknode == 123) &&
                        SET_SCOPE__FP4name(
                            latok->last__7toknode->last__7toknode->retval__7toknode.pn__7YYSTYPE))
                        ++__1scopesets;
                    continue;
                } else {
                    if (__1scopesets > 0)
                        do
                            UNSET_SCOPE__Fv();
                        while (--__1scopesets);

                    ;
                    return 0;
                }
            case 209:
                if ((__1tk2 == 178) && (!__1arg_decl)) {
                    struct toknode *__4t;

                    __4t = latok;
                    __1tk = __1tk2;

                    __1tk2 = lookahead__Fv();
                    if ((__1tk2 == 80) || (__1tk2 == 24)) {
                        if (SET_SCOPE__FP4name(__4t->retval__7toknode.pn__7YYSTYPE))
                            ++__1scopesets;
                        continue;
                    } else {
                        if (__1scopesets > 0)
                            do
                                UNSET_SCOPE__Fv();
                            while (--__1scopesets);

                        ;
                        return 0;
                    }
                } else {
                    if (__1scopesets > 0)
                        do
                            UNSET_SCOPE__Fv();
                        while (--__1scopesets);

                    ;
                    return (__1tk2 == 173);
                }
            }

            break;
        }

        if ((__1tk == 41) || (__1tk == 42)) {
            if (__1scopesets > 0)
                do
                    UNSET_SCOPE__Fv();
                while (--__1scopesets);

            ;
            return 1;
        }

        if ((__1tk != 80) && (__1tk != 24)) {
            if (__1scopesets > 0)
                do
                    UNSET_SCOPE__Fv();
                while (--__1scopesets);

            ;
            return 0;
        }

        if ((((__1tk == 80) && (__1tk2 == 41)) && __1arg_decl) && (!__1ptr)) {
            TOK __2nt;

            __2nt = lookahead__Fv();
            latok = latok->last__7toknode;
            if (__2nt == 40) {
                if (__1scopesets > 0)
                    do
                        UNSET_SCOPE__Fv();
                    while (--__1scopesets);

                ;
                return 1;
            }
        }

        if ((__1ptr == 0) && __1arg_decl) {
            if (__1scopesets > 0)
                do
                    UNSET_SCOPE__Fv();
                while (--__1scopesets);

            ;
            return 0;
        }

        if (__1tk == 24) {
            switch (__1tk2) {
            case 54:
            case 55:
            case 50:
            case 180:
            case 52:
            case 65:
            case 64:
            case 94:
            case 92:
            case 93:
            case 91:
            case 66:
            case 67:
            case 46:
            case 47:
            case 95:
            case 70:
            case 90:
            case 23:
            case 213:
            case 184:
            case 9:
            case 212:
                __1tk2 = lookahead__Fv();
                break;
            case 40:
                __1tk2 = lookahead__Fv();
                if (__1tk2 == 41) {
                    __1tk2 = lookahead__Fv();
                    break;
                } else {
                    if (__1scopesets > 0)
                        do
                            UNSET_SCOPE__Fv();
                        while (--__1scopesets);

                    ;
                    return 0;
                }
            case 42:
                __1tk2 = lookahead__Fv();
                if (__1tk2 == 43) {
                    __1tk2 = lookahead__Fv();
                    break;
                } else {
                    if (__1scopesets > 0)
                        do
                            UNSET_SCOPE__Fv();
                        while (--__1scopesets);

                    ;
                    return 0;
                }
            default:
                if (__1scopesets > 0)
                    do
                        UNSET_SCOPE__Fv();
                    while (--__1scopesets);

                ;
                return 0;
            }
        }

        {
            int __1allow_lp;
            int __1allow_rp;
            int __1pd;

            __1allow_lp = 1;
            __1allow_rp = 1;
            __1pd = __1paren;
            for (;;) {
                __1tk = __1tk2;
                if (((__1tk == 40) || (__1tk == 42)) || (__1tk == 41))
                    __1tk2 = lookahead__Fv();

                switch (__1tk) {
                case 40:
                    if (!__1allow_lp) {
                        if (__1scopesets > 0)
                            do
                                UNSET_SCOPE__Fv();
                            while (--__1scopesets);

                        ;
                        return 0;
                    }

                    if ((__1tk2 == 41) && __1paren) {
                        __1tk2 = lookahead__Fv();
                        __1allow_lp = 0;
                        __1allow_rp = 1;
                        continue;
                    }
                    if (((((__1tk2 == 41) || (__1tk2 == 13)) || (__1tk2 == 156)) ||
                         (__1tk2 == 155)) ||
                        ((__1tk2 == 97) && la_sctype__FUc((unsigned char)__1tk2))) {
                        if (__1scopesets > 0)
                            do
                                UNSET_SCOPE__Fv();
                            while (--__1scopesets);

                        ;
                        return 1;
                    }

                    if (__1tk2 == 178) {
                    ts:
                        do {
                            __1tk2 = lookahead__Fv();
                        } while (__1tk2 == 178);

                        if (__1tk2 == 123) {
                            struct toknode *__5T;

                            __5T = latok;
                            if ((lookahead__Fv() == 40) && (!la_decl__Fi(1))) {
                                if (__1scopesets > 0)
                                    do
                                        UNSET_SCOPE__Fv();
                                    while (--__1scopesets);

                                ;
                                return 0;
                            }
                            la_reset__FP7toknodeP4name(__5T->next__7toknode,
                                                       __5T->retval__7toknode.pn__7YYSTYPE);
                            if (__1scopesets > 0)
                                do
                                    UNSET_SCOPE__Fv();
                                while (--__1scopesets);

                            ;
                            return 1;
                        }
                        if (__1scopesets > 0)
                            do
                                UNSET_SCOPE__Fv();
                            while (--__1scopesets);

                        ;
                        return 0;
                    }
                    if (__1tk2 == 209) {
                        if (latok->tok__7toknode == 123)
                            latok->tok__7toknode = 209;
                        if (latok->next__7toknode == 0)
                            add_tokens__Fv();
                        __1tk2 = ptname_tscope__FP7toknode(latok->next__7toknode);
                        switch (__1tk2) {
                        case 178:
                            goto ts;
                        case 123:
                            break;
                        default:
                            if (__1scopesets > 0)
                                do
                                    UNSET_SCOPE__Fv();
                                while (--__1scopesets);

                            ;
                            return 0;
                        }
                    }
                    if ((__1tk2 == 97) || (__1tk2 == 123)) {
                        if ((lookahead__Fv() == 40) && (!la_decl__Fi(1))) {

                            if (__1scopesets > 0)
                                do
                                    UNSET_SCOPE__Fv();
                                while (--__1scopesets);

                            ;
                            return 0;
                        }
                        if (__1scopesets > 0)
                            do
                                UNSET_SCOPE__Fv();
                            while (--__1scopesets);

                        ;
                        return 1;
                    }

                    if (__1scopesets > 0)
                        do
                            UNSET_SCOPE__Fv();
                        while (--__1scopesets);

                    ;
                    return 0;
                case 42:
                    if (__1paren == 0) {
                        if (__1scopesets > 0)
                            do
                                UNSET_SCOPE__Fv();
                            while (--__1scopesets);

                        ;
                        return 1;
                    }
                    if (__1tk2 == 43) {
                        if (__1scopesets > 0)
                            do
                                UNSET_SCOPE__Fv();
                            while (--__1scopesets);

                        ;
                        return 1;
                    } else {
                        __1allow_lp = 0;
                        __1allow_rp = 1;

                        while ((lookahead__Fv() != 43) && (latok->tok__7toknode != 0))
                            ;
                        __1tk2 = lookahead__Fv();
                        continue;
                    }
                case 41:
                    if ((!__1allow_rp) || (!__1paren)) {
                        if (__1scopesets > 0)
                            do
                                UNSET_SCOPE__Fv();
                            while (--__1scopesets);

                        ;
                        return 0;
                    } else if (((__1tk2 == 72) || (__1tk2 == 71)) || (__1tk2 == 70)) {
                        if (__1scopesets > 0)
                            do
                                UNSET_SCOPE__Fv();
                            while (--__1scopesets);

                        ;

                        if (((!__1arg_decl) && ((__1pd == 1) && (!__1ptr))) && (!strict_opt))
                            error__FiPCc(
                                (int)'w',
                                (const char *)"T(id) (anachronism; will be declaration in future)");
                        return ((!__1arg_decl) && ((__1pd > (strict_opt ? 0 : 1)) || __1ptr));
                    } else if ((__1tk2 == 41) && ((bl_level - in_class_decl) == 0)) {
                        if (__1scopesets > 0)
                            do
                                UNSET_SCOPE__Fv();
                            while (--__1scopesets);

                        ;
                        return (!__1arg_decl);
                    } else {
                        --__1paren;
                        __1allow_lp = 1;
                        __1allow_rp = (__1paren > 0);
                        continue;
                    }
                default:
                    if (__1scopesets > 0)
                        do
                            UNSET_SCOPE__Fv();
                        while (--__1scopesets);

                    ;
                    return 0;
                }
            }
        }
    }
}

static int la_snarf__Fv(void);

struct toknode *save_text__Fv(void) {
    ;
    ;
    ;
    latok = front->next__7toknode;
    if (la_snarf__Fv()) {
        struct toknode *__2t;

        __2t = front;
        if (ccl->c_funqf__8classdef == 0)
            ccl->c_funqf__8classdef = front;
        else {
            ccl->c_funqr__8classdef->next__7toknode = front;
            front->last__7toknode = ccl->c_funqr__8classdef;
        }
        ccl->c_funqr__8classdef = latok;
        front = latok->next__7toknode;
        latok->next__7toknode = 0;
        if (front)
            front->last__7toknode = 0;
        return __2t;
    }
    return (struct toknode *)0;
}

void restore_text__Fv(void) {
    ;
    if (ccl->c_funqf__8classdef == 0)
        return;
    ;
    ;
    ;
    ccl->c_funqr__8classdef->next__7toknode = front;
    if (front)
        front->last__7toknode = ccl->c_funqr__8classdef;
    front = ccl->c_funqf__8classdef;
    ccl->c_funqf__8classdef = (ccl->c_funqr__8classdef = 0);
}

static int la_snarf__Fv(void) {
    ;
    {
        struct loc *__1L;

        int __1level;
        int __1parens;
        int __1paren_error;
        struct toknode *__1marker;

        __1L = (&latok->place__7toknode);

        __1parens = 0;
        __1paren_error = 0;
        __1marker = latok;
        switch (latok->tok__7toknode) {
            unsigned long __2__X100;

        default: {
            struct ea __0__V99;

            error__FiP3locPCcRC2eaN34(
                (int)'i', __1L, (const char *)"bad token Q snarfing function: %d",
                (const struct ea *)((__2__X100 = latok->tok__7toknode),
                                    (((((&__0__V99)->__O1__2ea.i = __2__X100), 0)), (&__0__V99))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        case 69:
            __1level = 0;
            break;
        case 73:
            __1level = 1;
            goto eatf;
        }
        };
        for (;;) {
            if (latok->next__7toknode == 0)
                add_tokens__Fv();
            switch ((latok = latok->next__7toknode)->tok__7toknode) {
            case 40:
                ++__1parens;
            default:;
                continue;
            case 41:
                if (((--__1parens) < 0) && ((__1paren_error++) == 0))
                    error__FiP3locPCcRC2eaN34(0, &latok->place__7toknode,
                                              (const char *)"unbalanced ()", (const struct ea *)ea0,
                                              (const struct ea *)ea0, (const struct ea *)ea0,
                                              (const struct ea *)ea0);
                continue;
            case 73:
                ++__1level;
                if (__1parens <= 0)
                    goto eatf;
                continue;
            case 74:
                if ((--__1level) < 0) {
                    error__FP3locPCcRC2eaN33(&latok->place__7toknode,
                                             (const char *)"unexpected '}'", (const struct ea *)ea0,
                                             (const struct ea *)ea0, (const struct ea *)ea0,
                                             (const struct ea *)ea0);
                    goto bad;
                }
                if (__1parens <= 0)
                    goto eatf;
                continue;
            case 72:
                if (__1parens <= 0) {
                    struct toknode *__0__X101;

                    error__FiP3locPCcRC2eaN34(0, __1L, (const char *)"illegal bit field",
                                              (const struct ea *)ea0, (const struct ea *)ea0,
                                              (const struct ea *)ea0, (const struct ea *)ea0);
                    del_tokens__FP7toknode(front);
                    ((__0__X101 = front),
                     ((__0__X101 ? (((void)(__0__X101 ? (((void)(((void)__dl__7toknodeSFPvUl(
                                                            (void *)__0__X101,
                                                            (size_t)(sizeof(struct toknode)))))))
                                                      : (((void)0)))))
                                 : (((void)0)))));
                    front = latok;
                    front->last__7toknode = 0;
                    return 0;
                }
                continue;
            case 0:
                error__FiP3locPCcRC2eaN34((int)'i', &latok->place__7toknode,
                                          (const char *)"unexpected end of file",
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }

    eatf:
        for (;;) {
            if (latok->next__7toknode == 0)
                add_tokens__Fv();
            switch ((latok = latok->next__7toknode)->tok__7toknode) {
            case 73:
                ++__1level;
            default:;
                continue;
            case 74:;
                if ((--__1level) <= 0) {
                    if (__1level < 0) {
                        error__FiP3locPCcRC2eaN34(0, &latok->place__7toknode,
                                                  (const char *)"unexpected '}'",
                                                  (const struct ea *)ea0, (const struct ea *)ea0,
                                                  (const struct ea *)ea0, (const struct ea *)ea0);
                        goto bad;
                    }
                    return 1;
                }
                break;
            case 0:
                error__FiP3locPCcRC2eaN34((int)'e', &latok->place__7toknode,
                                          (const char *)"unbalanced {}", (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0);
                goto bad;
            }
        }
    bad:
        del_tokens__FP7toknode(__1marker);
        __1marker->tok__7toknode = 72;
        return 0;
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

extern Pcons last_friend_cons__17templ_compilation;

extern Pcons last_cons__17templ_compilation;

extern Pcons friend_templ_refs__17templ_compilation;

extern Pcons templ_refs__17templ_compilation;

extern int formals_in_progress__17templ_compilation;

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
