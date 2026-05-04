
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
struct Block_short;

struct Block_short { /* sizeof Block_short == 16 */

    short *p__11Block_short;

    size_t n__11Block_short;
};

void move__11Block_shortFPsUl(struct Block_short *__0this, short *, size_t);

void copy__11Block_shortFRC11Block_short(struct Block_short *__0this, const struct Block_short *);

size_t grow__11Block_shortFUl(struct Block_short *__0this, size_t);

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

extern int in_progress__17templ_compilation;

extern size_t strlen(const char *);

extern char *strcpy(char *, const char *);

char *strdup(const char *__1s1) {
    char *__1s2;

    __1s2 = (((char *)__nw__FUl((size_t)((sizeof(char)) * (strlen(__1s1) + 1)))));
    return ((__1s2 == 0) ? (((char *)0)) : strcpy(__1s2, __1s1));
}

static char inbuf[8184];
static char *txtmax = (&(inbuf[8183]));
static char *txtstart = 0;
static char *txtfree = 0;
struct buf;

static struct buf *bufhead;
static struct buf *freebuf;

static struct loc tloc;

struct buf { /* sizeof buf == 4096 */
    struct buf *next__3buf;
    char chars__3buf[4088];
};

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

int new_buf__Fc(char __1c) {
    struct buf *__1pbuf;
    if (freebuf) {
        __1pbuf = freebuf;
        freebuf = freebuf->next__3buf;
    } else
        __1pbuf = (((struct buf *)__nw__FUl(sizeof(struct buf))));
    __1pbuf->next__3buf = bufhead;
    bufhead = __1pbuf;

    if (4088 < (txtmax - txtstart))
        error__FiP3locPCcRC2eaN34((int)'l', &tloc, (const char *)"lexical token too long",
                                  (const struct ea *)ea0, (const struct ea *)ea0,
                                  (const struct ea *)ea0, (const struct ea *)ea0);

    {
        char *__1p;

        __1p = txtstart;
        txtstart = (txtfree = (&(__1pbuf->chars__3buf[0])));
        while (__1p < txtmax)
            ((*(txtfree++))) = ((*(__1p++)));
        ((*(txtfree++))) = __1c;
        txtmax = (&(__1pbuf->chars__3buf[4087]));
        return 0;
    }
}

static int Nfile;

static struct Block_CPchar file_name;

static int tcurr_file;

int linkage = 0;

static int lvec[10] = {0};
static int lcount = 0;

extern int strcmp(const char *, const char *);

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

void set_linkage__FPCc(const char *__1p) {
    if ((__1p == 0) || (((*__1p)) == 0)) {
        if (lcount > 0)
            linkage = (lvec[(--lcount)]);

    } else {
        if (10 <= (++lcount)) {
            error__FiPCc((int)'l', (const char *)"linkage directive nested too deep");
            --lcount;
        } else if (strcmp(__1p, (const char *)"C") == 0)
            (lvec[lcount]) = (linkage = 1);
        else if (strcmp(__1p, (const char *)"C++") == 0)
            (lvec[lcount]) = (linkage = 2);
        else {
            {
                struct ea __0__V26;

                error__FPCcRC2eaN32(
                    (const char *)"%s linkage",
                    (const struct ea *)(((&__0__V26)->__O1__2ea.p = ((const void *)__1p)),
                                        (&__0__V26)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                --lcount;
            }
        }
    }
}

extern void *_get_stdout(void);

void *out_file = 0; /* initialized in _main */

extern void *_get_stdin(void);

void *in_file = 0;
void *pt_file = 0;
void *dtpt_file = 0;
static bit doneflag = 0;
int first_file = 0;

static Ptable keyword_table;

static int p_level = 0;
static int b_level = 0;

static short lxmask[129];

int saved = 0;

const char *keys[256];

static void new_key__FPCcUcT2(const char *__1s, TOK __1toknum, TOK __1yyclass) {
    Pname __1n;

    __1n = __ct__4nameFPCc((struct name *)0, __1s);

    (keys[((__1toknum == 143) ? __1yyclass : __1toknum)]) = __1s;

    {
        Pname __1nn;

        __1nn = insert__5tableFP4nameUc(keyword_table, __1n, (unsigned char)0);

        __1nn->base__4node = __1toknum;
        __1nn->__O2__4name.syn_class = (__1yyclass ? __1yyclass : __1toknum);
        ((__1n ? (((void)(__1n ? (((void)((((((struct expr *)__1n))
                                                ? (((void)((((struct expr *)__1n))
                                                               ? (((void)(((void)0))))
                                                               : (((void)0)))))
                                                : (((void)0)))),
                                          (((void)__dl__4nameSFPvUl(
                                              (void *)__1n, (size_t)(sizeof(struct name))))))))
                               : (((void)0)))))
               : (((void)0))));
    }
}

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

static void ktbl_init__Fv(void) {
    keyword_table = __ct__5tableFsP5tableP4name((struct table *)0, (short)67, (struct table *)0,
                                                (struct name *)0);

    new_key__FPCcUcT2((const char *)"asm", (unsigned char)1, (unsigned char)0);
    new_key__FPCcUcT2((const char *)"auto", (unsigned char)2, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"break", (unsigned char)143, (unsigned char)3);
    new_key__FPCcUcT2((const char *)"case", (unsigned char)143, (unsigned char)4);
    new_key__FPCcUcT2((const char *)"continue", (unsigned char)143, (unsigned char)7);
    new_key__FPCcUcT2((const char *)"char", (unsigned char)5, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"do", (unsigned char)143, (unsigned char)10);
    new_key__FPCcUcT2((const char *)"double", (unsigned char)11, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"default", (unsigned char)143, (unsigned char)8);
    new_key__FPCcUcT2((const char *)"enum", (unsigned char)13, (unsigned char)0);
    new_key__FPCcUcT2((const char *)"else", (unsigned char)143, (unsigned char)12);
    new_key__FPCcUcT2((const char *)"extern", (unsigned char)14, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"float", (unsigned char)15, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"for", (unsigned char)143, (unsigned char)16);
    new_key__FPCcUcT2((const char *)"goto", (unsigned char)143, (unsigned char)19);
    new_key__FPCcUcT2((const char *)"if", (unsigned char)143, (unsigned char)20);
    new_key__FPCcUcT2((const char *)"int", (unsigned char)21, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"long", (unsigned char)22, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"long long", (unsigned char)122, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"return", (unsigned char)143, (unsigned char)28);
    new_key__FPCcUcT2((const char *)"register", (unsigned char)27, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"static", (unsigned char)31, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"struct", (unsigned char)32, (unsigned char)156);
    new_key__FPCcUcT2((const char *)"sizeof", (unsigned char)30, (unsigned char)0);
    new_key__FPCcUcT2((const char *)"short", (unsigned char)29, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"switch", (unsigned char)143, (unsigned char)33);
    new_key__FPCcUcT2((const char *)"typedef", (unsigned char)35, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"unsigned", (unsigned char)37, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"union", (unsigned char)36, (unsigned char)156);
    new_key__FPCcUcT2((const char *)"void", (unsigned char)38, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"while", (unsigned char)143, (unsigned char)39);

    new_key__FPCcUcT2((const char *)"catch", (unsigned char)98, (unsigned char)98);
    new_key__FPCcUcT2((const char *)"class", (unsigned char)6, (unsigned char)156);
    new_key__FPCcUcT2((const char *)"const", (unsigned char)26, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"delete", (unsigned char)143, (unsigned char)9);
    new_key__FPCcUcT2((const char *)"friend", (unsigned char)18, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"inline", (unsigned char)75, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"namespace", (unsigned char)102, (unsigned char)102);
    new_key__FPCcUcT2((const char *)"mutable", (unsigned char)101, (unsigned char)101);
    new_key__FPCcUcT2((const char *)"new", (unsigned char)23, (unsigned char)0);
    new_key__FPCcUcT2((const char *)"operator", (unsigned char)24, (unsigned char)0);
    new_key__FPCcUcT2((const char *)"overload", (unsigned char)76, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"private", (unsigned char)174, (unsigned char)175);
    new_key__FPCcUcT2((const char *)"protected", (unsigned char)79, (unsigned char)175);
    new_key__FPCcUcT2((const char *)"public", (unsigned char)25, (unsigned char)175);
    new_key__FPCcUcT2((const char *)"signed", (unsigned char)171, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"template", (unsigned char)185, (unsigned char)0);
    new_key__FPCcUcT2((const char *)"this", (unsigned char)34, (unsigned char)0);
    new_key__FPCcUcT2((const char *)"throw", (unsigned char)99, (unsigned char)99);
    new_key__FPCcUcT2((const char *)"try", (unsigned char)100, (unsigned char)100);
    new_key__FPCcUcT2((const char *)"using", (unsigned char)103, (unsigned char)103);
    new_key__FPCcUcT2((const char *)"virtual", (unsigned char)77, (unsigned char)97);
    new_key__FPCcUcT2((const char *)"volatile", (unsigned char)170, (unsigned char)97);
}

struct loc last_line = {0};
struct loc noloc = {0, 0};

extern int fprintf(void *, const char *, ...);

void putline__3locFv(register struct loc *__0this) {
    if ((__0this->file__3loc == 0) && (__0this->line__3loc == 0))
        return;
    if ((0 <= __0this->file__3loc) && (__0this->file__3loc <= Nfile)) {
        const char *__2f;

        struct Block_CPchar *__0__X27;

        int __2__X28;

        __2f = ((*((__0__X27 = (&file_name)),
                   ((__2__X28 = __0this->file__3loc),
                    ((((CPchar *)(&(__0__X27->p__12Block_CPchar[__2__X28])))))))));
        if (__2f == 0)
            __2f = src_file_name;
        fprintf(out_file, line_format, __0this->line__3loc, __2f);
        last_line = (*__0this);
    }
}

void put__3locFPv(register struct loc *__0this, void *__1p) {
    if ((0 <= __0this->file__3loc) && (__0this->file__3loc <= Nfile)) {
        const char *__2f;

        struct Block_CPchar *__0__X29;

        int __2__X30;

        __2f = ((*((__0__X29 = (&file_name)),
                   ((__2__X30 = __0this->file__3loc),
                    ((((CPchar *)(&(__0__X29->p__12Block_CPchar[__2__X30])))))))));
        if (__2f == 0)
            __2f = src_file_name;
        fprintf(__1p, (const char *)"\"%s\", line %d: ", __2f, __0this->line__3loc);
    }
}

const char *curr_filename__Fv(void) {
    struct Block_CPchar *__0__X31;

    int __2__X32;

    return ((*((__0__X31 = (&file_name)),
               ((__2__X32 = curloc.file__3loc),
                ((((CPchar *)(&(__0__X31->p__12Block_CPchar[__2__X32])))))))));
}

void lxenter__FPCcs(const char *__1s, short __1m) {
    int __1c;

    while (__1c = ((*(__1s++))))
        (lxmask[(__1c + 1)]) |= __1m;
}

extern int fgetc(void *);

void lxget__FiT1(int __1c, int __1m) {
    (txtmax <= txtfree) ? new_buf__Fc((char)__1c) : (((int)(((*(txtfree++))) = __1c)));
    if (((saved ? (((__1c = saved), (saved = 0)), __1c) : (__1c = fgetc(in_file))),
         ((lxmask[(__1c + 1)]) & __1m))) {
        (txtmax <= txtfree) ? new_buf__Fc((char)__1c) : (((int)(((*(txtfree++))) = __1c)));
        while (((__1c = fgetc(in_file)), ((lxmask[(__1c + 1)]) & __1m)))
            (txtmax <= txtfree) ? new_buf__Fc((char)__1c) : (((int)(((*(txtfree++))) = __1c)));
    }
    {
        unsigned long __2__X34;

        if (saved) {
            struct ea __0__V33;

            error__FiP3locPCcRC2eaN34(
                (int)'i', &tloc, (const char *)"unget: saved==%c",
                (const struct ea *)((__2__X34 = saved),
                                    (((((&__0__V33)->__O1__2ea.i = __2__X34), 0)), (&__0__V33))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        saved = __1c;
    }

    ;
    (txtmax <= txtfree) ? new_buf__Fc('\0') : (((int)(((*(txtfree++))) = '\0')));
}
struct LXDOPE;

struct LXDOPE { /* sizeof LXDOPE == 6 */
    short lxch__6LXDOPE;
    short lxact__6LXDOPE;
    TOK lxtok__6LXDOPE;
};

static struct LXDOPE lxdope[34] = {
    '$', 30, 0,  '_', 1,  0,  '0', 2,  0,  ' ', 10, 0,  '\n', 11, 0,  '"', 4,  0,  '\'', 5,  0,
    '`', 6,  0,  '(', 14, 40, ')', 15, 41, '{', 12, 73, '}',  13, 74, '[', 3,  42, ']',  3,  43,
    '*', 26, 50, '?', 3,  68, ':', 28, 69, '+', 27, 54, '-',  25, 55, '/', 7,  51, '%',  23, 53,
    '&', 22, 52, '|', 21, 65, '^', 20, 64, '!', 24, 46, '~',  3,  47, ',', 3,  71, ';',  3,  72,
    '.', 8,  45, '<', 18, 58, '>', 19, 60, '=', 17, 70, '#',  29, 0,  -1,  16, 0};

static struct LXDOPE *lxcp[129];

extern void lex_clear__Fv(void);

static int lxtitle__Fv(void);

void lex_init__Fv(void) {
    struct LXDOPE *__1p;
    int __1i;
    const char *__1cp;

    struct Block_CPchar *__0__X35;

    struct Block_CPchar *__0__X36;

    for (__1i = 0; __1i <= 128; __1i++)
        (lxmask[__1i]) = 0;

    lxenter__FPCcs((const char *)"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_",
                   (short)01);

    lxenter__FPCcs((const char *)"0123456789", (short)02);
    lxenter__FPCcs((const char *)"0123456789abcdefABCDEF", (short)010);

    lxenter__FPCcs((const char *)" \t\r\b\f\013", (short)020);
    (lxmask[47]) |= 040;

    for (__1i = 0; __1i <= 128; ++__1i)
        (lxcp[__1i]) = (struct LXDOPE *)lxdope;

    for (__1p = (struct LXDOPE *)lxdope;; ++__1p) {
        (lxcp[(__1p->lxch__6LXDOPE + 1)]) = __1p;
        if (__1p->lxch__6LXDOPE < 0)
            break;
    }

    __1cp = (const char *)"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while ((*__1cp))
        (lxcp[(((*(__1cp++))) + 1)]) = (&(lxdope[1]));
    __1cp = (const char *)"123456789";
    while ((*__1cp))
        (lxcp[(((*(__1cp++))) + 1)]) = (&(lxdope[2]));
    __1cp = (const char *)"\t\b\r\f\013";
    while ((*__1cp))
        (lxcp[(((*(__1cp++))) + 1)]) = (&(lxdope[3]));

    ((__0__X35 = (&file_name)), (((((unsigned long)0) < __0__X35->n__12Block_CPchar) ||
                                  grow__12Block_CPcharFUl(__0__X35, ((unsigned long)0)))));
    ((*((__0__X36 = (&file_name)), ((((CPchar *)(&(__0__X36->p__12Block_CPchar[0])))))))) =
        src_file_name;

    curloc.line__3loc = (tloc.line__3loc = 1);

    ktbl_init__Fv();
    lex_clear__Fv();
    saved = lxtitle__Fv();
}

void lex_clear__Fv(void) {
    struct buf *__1p;

    __1p = bufhead;
    bufhead = 0;

    while (__1p) {
        struct buf *__2pp;

        __2pp = __1p;
        __1p = __1p->next__3buf;
        __2pp->next__3buf = freebuf;
        freebuf = __2pp;
    }

    txtstart = (txtfree = inbuf);
    txtmax = (&(inbuf[8183]));
}

int int_val__Fc(char __1hex) {
    switch (__1hex) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return (__1hex - '0');
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
        return ((__1hex - 'a') + 10);
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
        return ((__1hex - 'A') + 10);
    }
    error__FiPCc((int)'i', (const char *)"fall off end of int_val()");
    return 0;
}

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

void hex_to_oct__Fv(void) {
    int __1i;
    int __1c;

    __1i = 0;

    saved ? (((__1c = saved), (saved = 0)), __1c) : (__1c = fgetc(in_file));
    if ((lxmask[(__1c + 1)]) & 010) {
        __1i = int_val__Fc((char)__1c);
        __1c = fgetc(in_file);
        if ((lxmask[(__1c + 1)]) & 010) {
            __1i = ((__1i << 4) + int_val__Fc((char)__1c));
            __1c = fgetc(in_file);
            if ((lxmask[(__1c + 1)]) & 010)
                __1i = ((__1i << 4) + int_val__Fc((char)__1c));
            else {
                unsigned long __2__X40;

                if (saved) {
                    struct ea __0__V37;

                    error__FiP3locPCcRC2eaN34(
                        (int)'i', &tloc, (const char *)"unget: saved==%c",
                        (const struct ea *)((__2__X40 = saved),
                                            (((((&__0__V37)->__O1__2ea.i = __2__X40), 0)),
                                             (&__0__V37))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                saved = __1c;
            }

            ;
        } else {
            unsigned long __2__X41;

            if (saved) {
                struct ea __0__V38;

                error__FiP3locPCcRC2eaN34(
                    (int)'i', &tloc, (const char *)"unget: saved==%c",
                    (const struct ea *)((__2__X41 = saved),
                                        (((((&__0__V38)->__O1__2ea.i = __2__X41), 0)),
                                         (&__0__V38))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            saved = __1c;
        }

        ;
    } else {
        error__FP3locPCcRC2eaN33(&tloc, (const char *)"hexadecimal digitE after \\x",
                                 (const struct ea *)ea0, (const struct ea *)ea0,
                                 (const struct ea *)ea0, (const struct ea *)ea0);
        {
            unsigned long __2__X42;

            if (saved) {
                struct ea __0__V39;

                error__FiP3locPCcRC2eaN34(
                    (int)'i', &tloc, (const char *)"unget: saved==%c",
                    (const struct ea *)((__2__X42 = saved),
                                        (((((&__0__V39)->__O1__2ea.i = __2__X42), 0)),
                                         (&__0__V39))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            saved = __1c;
        }

        ;
    }

    __1i &= 0377;

    (txtmax <= txtfree) ? new_buf__Fc((char)('0' + (__1i >> 6)))
                        : (((int)(((*(txtfree++))) = ('0' + (__1i >> 6)))));
    (txtmax <= txtfree) ? new_buf__Fc((char)('0' + ((__1i & 070) >> 3)))
                        : (((int)(((*(txtfree++))) = ('0' + ((__1i & 070) >> 3)))));

    (txtmax <= txtfree) ? new_buf__Fc((char)('0' + (__1i & 7)))
                        : (((int)(((*(txtfree++))) = ('0' + (__1i & 7)))));
}

char *chconst__Fv(void) {
    int __1c;
    int __1nch;

    __1nch = 0;

    (txtmax <= txtfree) ? new_buf__Fc('\'') : (((int)(((*(txtfree++))) = '\'')));

    for (;;) {
        char *__2p;
        char __2cc;

        __2cc = 0;
        saved ? (((__1c = saved), (saved = 0)), __1c) : (__1c = fgetc(in_file));
        switch (__1c) {
        case '\'':
            goto ex;
        case -1:
            error__FP3locPCcRC2eaN33(&tloc, (const char *)"eof in char constant",
                                     (const struct ea *)ea0, (const struct ea *)ea0,
                                     (const struct ea *)ea0, (const struct ea *)ea0);
            goto ex;
        case '\n':
            error__FP3locPCcRC2eaN33(&tloc, (const char *)"newline in char constant",
                                     (const struct ea *)ea0, (const struct ea *)ea0,
                                     (const struct ea *)ea0, (const struct ea *)ea0);
            goto ex;
        case '\\':
            if (SZ_INT == (__1nch++))
                error__FiP3locPCcRC2eaN34((int)'l', &tloc, (const char *)"char constant too long",
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0);
            (txtmax <= txtfree) ? new_buf__Fc((char)__1c) : (((int)(((*(txtfree++))) = __1c)));
            switch (__1c = fgetc(in_file)) {
            case '\n':
                ++tloc.line__3loc;
            default:
                (txtmax <= txtfree) ? new_buf__Fc((char)__1c) : (((int)(((*(txtfree++))) = __1c)));
                break;
            case '4':
            case '5':
            case '6':
            case '7':
                __2p = txtfree;
                __2cc = (__1c - 4);
            case '0':
            case '1':
            case '2':
            case '3':
                (txtmax <= txtfree) ? new_buf__Fc((char)__1c) : (((int)(((*(txtfree++))) = __1c)));
                __1c = fgetc(in_file);
                if (((lxmask[(__1c + 1)]) & 02) && (__1c < '8')) {
                    (txtmax <= txtfree) ? new_buf__Fc((char)__1c)
                                        : (((int)(((*(txtfree++))) = __1c)));

                    __1c = fgetc(in_file);
                    if (((lxmask[(__1c + 1)]) & 02) && (__1c < '8')) {
                        if (__2cc)
                            ((*__2p)) = __2cc;
                        (txtmax <= txtfree) ? new_buf__Fc((char)__1c)
                                            : (((int)(((*(txtfree++))) = __1c)));
                    } else {
                        unsigned long __2__X45;

                        if (saved) {
                            struct ea __0__V43;

                            error__FiP3locPCcRC2eaN34(
                                (int)'i', &tloc, (const char *)"unget: saved==%c",
                                (const struct ea *)((__2__X45 = saved),
                                                    (((((&__0__V43)->__O1__2ea.i = __2__X45), 0)),
                                                     (&__0__V43))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                        saved = __1c;
                    }

                    ;
                } else {
                    unsigned long __2__X46;

                    if (saved) {
                        struct ea __0__V44;

                        error__FiP3locPCcRC2eaN34(
                            (int)'i', &tloc, (const char *)"unget: saved==%c",
                            (const struct ea *)((__2__X46 = saved),
                                                (((((&__0__V44)->__O1__2ea.i = __2__X46), 0)),
                                                 (&__0__V44))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    saved = __1c;
                }

                ;
                break;
            case 'x':
                hex_to_oct__Fv();
                break;
            }

            ;
            break;
        default:
            if (SZ_INT == (__1nch++))
                error__FiP3locPCcRC2eaN34((int)'l', &tloc, (const char *)"char constant too long",
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0);
            (txtmax <= txtfree) ? new_buf__Fc((char)__1c) : (((int)(((*(txtfree++))) = __1c)));
        }
    }
ex:
    if (__1nch == 0)
        error__FP3locPCcRC2eaN33(&tloc, (const char *)"empty char constant", (const struct ea *)ea0,
                                 (const struct ea *)ea0, (const struct ea *)ea0,
                                 (const struct ea *)ea0);
    (txtmax <= txtfree) ? new_buf__Fc('\'') : (((int)(((*(txtfree++))) = '\'')));
    (txtmax <= txtfree) ? new_buf__Fc('\0') : (((int)(((*(txtfree++))) = '\0')));
    return txtstart;
}

void lxcom__Fv(void) {
    int __1c;
    saved ? (((__1c = saved), (saved = 0)), __1c) : (__1c = fgetc(in_file));
    for (;; __1c = fgetc(in_file)) {
    xx:
        switch (__1c) {
        case -1:
            error__FiP3locPCcRC2eaN34((int)'w', &tloc, (const char *)"eof in comment",
                                      (const struct ea *)ea0, (const struct ea *)ea0,
                                      (const struct ea *)ea0, (const struct ea *)ea0);
            return;
        case '\n':
            tloc.line__3loc++;

            break;
        case '*':
            if ((__1c = fgetc(in_file)) == '/')
                return;
            goto xx;
        case '/':
            if ((__1c = fgetc(in_file)) == '*') {
                error__FiP3locPCcRC2eaN34((int)'w', &tloc, (const char *)"``/*'' in comment",
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0);
                if ((__1c = fgetc(in_file)) == '/')
                    return;
            }
            goto xx;
        }
    }
}

void linecom__Fv(void) {
    int __1c;

    saved ? (((__1c = saved), (saved = 0)), __1c) : (__1c = fgetc(in_file));

    for (;; __1c = fgetc(in_file))
        switch (__1c) {
        case -1:
            error__FiP3locPCcRC2eaN34((int)'w', &tloc, (const char *)"eof in comment",
                                      (const struct ea *)ea0, (const struct ea *)ea0,
                                      (const struct ea *)ea0, (const struct ea *)ea0);
            return;
        case '\n':
            tloc.line__3loc++;

            saved = lxtitle__Fv();
            return;
        }
}

extern int ungetc(int, void *);

char eat_whitespace__Fv(void) {
    int __1c;
    saved ? (((__1c = saved), (saved = 0)), __1c) : (__1c = fgetc(in_file));
    for (;;) {
    lx:
        switch (__1c) {
        case -1:
            error__FiP3locPCcRC2eaN34((int)'w', &tloc, (const char *)"unexpected comment",
                                      (const struct ea *)ea0, (const struct ea *)ea0,
                                      (const struct ea *)ea0, (const struct ea *)ea0);
            return (char)-1;
        case '/':
            switch (__1c = fgetc(in_file)) {
            case '*':
                lxcom__Fv();
                break;
            case '/':
                linecom__Fv();
                break;
            default:
                if (__1c == -1)
                    error__FP3locPCcRC2eaN33(&tloc, (const char *)"eof after /",
                                             (const struct ea *)ea0, (const struct ea *)ea0,
                                             (const struct ea *)ea0, (const struct ea *)ea0);
                else {
                    {
                        unsigned long __2__X48;

                        if (saved) {
                            struct ea __0__V47;

                            error__FiP3locPCcRC2eaN34(
                                (int)'i', &tloc, (const char *)"unget: saved==%c",
                                (const struct ea *)((__2__X48 = saved),
                                                    (((((&__0__V47)->__O1__2ea.i = __2__X48), 0)),
                                                     (&__0__V47))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                        saved = __1c;
                    }

                    ;
                    (ungetc(saved, in_file), (saved = 0));
                }
                return '/';
            }
            saved ? (((__1c = saved), (saved = 0)), __1c) : (__1c = fgetc(in_file));
            goto lx;
        case '\n':
            ++tloc.line__3loc;
            __1c = lxtitle__Fv();
            goto lx;
        case ' ':
        case '\t':
            break;
        default:
            return (char)__1c;
        }
        __1c = fgetc(in_file);
    }
}

void get_string__Fv(void) {
    int __1lxchar;

    for (;;)
        switch (saved ? (((__1lxchar = saved), (saved = 0)), __1lxchar)
                      : (__1lxchar = fgetc(in_file))) {

        case '\\':
            (txtmax <= txtfree) ? new_buf__Fc('\\') : (((int)(((*(txtfree++))) = '\\')));
            switch (__1lxchar = fgetc(in_file)) {
            case '\n':
                ++tloc.line__3loc;
            default:
                (txtmax <= txtfree) ? new_buf__Fc((char)__1lxchar)
                                    : (((int)(((*(txtfree++))) = __1lxchar)));
                break;
            case 'x':
                hex_to_oct__Fv();
                break;
            }

            ;
            break;
        case '"': {
            char *__3p;

            __3p = txtstart;
            if ((__1lxchar = eat_whitespace__Fv()) == '"') {
                (txtmax <= txtfree) ? new_buf__Fc('\\') : (((int)(((*(txtfree++))) = '\\')));
                (txtmax <= txtfree) ? new_buf__Fc('\n') : (((int)(((*(txtfree++))) = '\n')));

                continue;
            }

            ;

            txtstart = __3p;
            {
                unsigned long __2__X50;

                if (saved) {
                    struct ea __0__V49;

                    error__FiP3locPCcRC2eaN34(
                        (int)'i', &tloc, (const char *)"unget: saved==%c",
                        (const struct ea *)((__2__X50 = saved),
                                            (((((&__0__V49)->__O1__2ea.i = __2__X50), 0)),
                                             (&__0__V49))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                saved = __1lxchar;
            }

            ;
            (txtmax <= txtfree) ? new_buf__Fc((char)0) : (((int)(((*(txtfree++))) = 0)));
            return;
        }
        case '\n':
            error__FP3locPCcRC2eaN33(&tloc, (const char *)"newline in string",
                                     (const struct ea *)ea0, (const struct ea *)ea0,
                                     (const struct ea *)ea0, (const struct ea *)ea0);
            (txtmax <= txtfree) ? new_buf__Fc((char)0) : (((int)(((*(txtfree++))) = 0)));
            return;
        case -1:
            error__FP3locPCcRC2eaN33(&tloc, (const char *)"eof in string", (const struct ea *)ea0,
                                     (const struct ea *)ea0, (const struct ea *)ea0,
                                     (const struct ea *)ea0);
            (txtmax <= txtfree) ? new_buf__Fc((char)0) : (((int)(((*(txtfree++))) = 0)));
            return;
        default:
            (txtmax <= txtfree) ? new_buf__Fc((char)__1lxchar)
                                : (((int)(((*(txtfree++))) = __1lxchar)));
        }
}

extern void addtok__FUc7YYSTYPE3loc(TOK, union YYSTYPE, struct loc);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

extern void ext__Fi(int);

TOK tlex__Fv(void) {
    TOK __1ret;
    Pname __1n;

    for (;;) {
        int __2lxchar;
        struct LXDOPE *__2p;

        txtstart = txtfree;

        saved ? (((__2lxchar = saved), (saved = 0)), __2lxchar) : (__2lxchar = fgetc(in_file));

        if ((__2lxchar + 1) >= 128) {
            struct ea __0__V51;

            error__FPCcRC2eaN32(
                (const char *)"illegal input character encountered: %d",
                (const struct ea *)(((((&__0__V51)->__O1__2ea.i = ((unsigned long)__2lxchar)), 0)),
                                    (&__0__V51)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        switch ((__2p = (lxcp[(__2lxchar + 1)]))->lxact__6LXDOPE) {
            const void *__2__X76;

        case 3: {
            int __1__X75;

            union YYSTYPE __1__Xy00qjtkvpt5vcij;

            addtok__FUc7YYSTYPE3loc(
                __2p->lxtok__6LXDOPE,
                ((__1__X75 = __2p->lxtok__6LXDOPE),
                 ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = __1__X75), __1__Xy00qjtkvpt5vcij)),
                tloc);

            return __2p->lxtok__6LXDOPE;
        }

        ;

        case 16:
            if (p_level || (b_level + lcount)) {
                struct ea __0__V52;

                error__FP3locPCcRC2eaN33(
                    &tloc, (const char *)"'%s' missing at end of input",
                    (const struct ea *)((__2__X76 = (const void *)((b_level + lcount) ? "}" : ")")),
                                        (((&__0__V52)->__O1__2ea.p = __2__X76), (&__0__V52))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)0,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 0), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)0;
            }

            ;

        case 29: {
            unsigned long __2__X77;

            if (saved) {
                struct ea __0__V53;

                error__FiP3locPCcRC2eaN34(
                    (int)'i', &tloc, (const char *)"unget: saved==%c",
                    (const struct ea *)((__2__X77 = saved),
                                        (((((&__0__V53)->__O1__2ea.i = __2__X77), 0)),
                                         (&__0__V53))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            saved = '#';
        }

        ;
            saved = lxtitle__Fv();
            continue;

        case 0: {
            if ((' ' <= __2lxchar) && (__2lxchar <= '~')) {
                struct ea __0__V54;

                error__FP3locPCcRC2eaN33(
                    &tloc, (const char *)"illegal character '%c' (ignored)",
                    (const struct ea *)(((((&__0__V54)->__O1__2ea.i = ((unsigned long)__2lxchar)),
                                          0)),
                                        (&__0__V54)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else {
                struct ea __0__V55;

                error__FP3locPCcRC2eaN33(
                    &tloc, (const char *)"illegal character%o (ignored)",
                    (const struct ea *)(((((&__0__V55)->__O1__2ea.i = ((unsigned long)__2lxchar)),
                                          0)),
                                        (&__0__V55)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            continue;
        }

        case 30: {
            {
                struct ea __0__V56;

                error__FP3locPCcRC2eaN33(
                    &tloc, (const char *)"illegal character%o (ignored)",
                    (const struct ea *)(((((&__0__V56)->__O1__2ea.i = ((unsigned long)__2lxchar)),
                                          0)),
                                        (&__0__V56)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                continue;
            }
        }

        case 1: {
            char __4ll;
            switch (__4ll = __2lxchar) {
            case 'L':
                switch (__2lxchar = fgetc(in_file)) {
                case '\'':
                    error__FiP3locPCcRC2eaN34((int)'s', &tloc,
                                              (const char *)"wide character constant",
                                              (const struct ea *)ea0, (const struct ea *)ea0,
                                              (const struct ea *)ea0, (const struct ea *)ea0);
                    {
                        unsigned long __2__X78;

                        if (saved) {
                            struct ea __0__V57;

                            error__FiP3locPCcRC2eaN34(
                                (int)'i', &tloc, (const char *)"unget: saved==%c",
                                (const struct ea *)((__2__X78 = saved),
                                                    (((((&__0__V57)->__O1__2ea.i = __2__X78), 0)),
                                                     (&__0__V57))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                        saved = __2lxchar;
                    }

                    ;
                    continue;
                case '"':
                    error__FiP3locPCcRC2eaN34((int)'s', &tloc,
                                              (const char *)"wide character string",
                                              (const struct ea *)ea0, (const struct ea *)ea0,
                                              (const struct ea *)ea0, (const struct ea *)ea0);
                    {
                        unsigned long __2__X79;

                        if (saved) {
                            struct ea __0__V58;

                            error__FiP3locPCcRC2eaN34(
                                (int)'i', &tloc, (const char *)"unget: saved==%c",
                                (const struct ea *)((__2__X79 = saved),
                                                    (((((&__0__V58)->__O1__2ea.i = __2__X79), 0)),
                                                     (&__0__V58))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                        saved = __2lxchar;
                    }

                    ;
                    continue;
                }
                {
                    unsigned long __2__X80;

                    if (saved) {
                        struct ea __0__V59;

                        error__FiP3locPCcRC2eaN34(
                            (int)'i', &tloc, (const char *)"unget: saved==%c",
                            (const struct ea *)((__2__X80 = saved),
                                                (((((&__0__V59)->__O1__2ea.i = __2__X80), 0)),
                                                 (&__0__V59))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    saved = __2lxchar;
                }

                ;
                __2lxchar = __4ll;
            }
        }

            lxget__FiT1(__2lxchar, 3);

            if (__1n =
                    look__5tableFPCcUc(keyword_table, (const char *)txtstart, (unsigned char)0)) {
                TOK __4x;
                switch (__4x = __1n->base__4node) {
                case 123:
                    txtfree = txtstart;
                    {
                        struct ea __0__V60;

                        error__FiP3locPCcRC2eaN34(
                            (int)'i', &tloc, (const char *)"TN%n in keyword_table",
                            (const struct ea *)(((&__0__V60)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V60)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        break;

                    case 143:
                        txtfree = txtstart;
                        {
                            struct loc __1__X81;

                            union YYSTYPE __1__Xy00adtkvpt5vcij;

                            addtok__FUc7YYSTYPE3loc(
                                (unsigned char)__1n->__O2__4name.syn_class,
                                ((__1__X81 = tloc), ((__1__Xy00adtkvpt5vcij.l__7YYSTYPE = __1__X81),
                                                     __1__Xy00adtkvpt5vcij)),
                                tloc);

                            return (unsigned char)__1n->__O2__4name.syn_class;
                        }

                        ;
                    case 14:
                        txtfree = txtstart;
                        if ((__2lxchar = eat_whitespace__Fv()) == '\"') {
                            get_string__Fv();
                            {
                                char *__1__X82;

                                union YYSTYPE __1__Xy00aqtkvpt5vcij;

                                addtok__FUc7YYSTYPE3loc(
                                    (unsigned char)182,
                                    ((__1__X82 = txtstart),
                                     ((__1__Xy00aqtkvpt5vcij.s__7YYSTYPE = (const char *)__1__X82),
                                      __1__Xy00aqtkvpt5vcij)),
                                    tloc);

                                return (unsigned char)182;
                            }

                            ;
                        }

                        {
                            unsigned long __2__X83;

                            if (saved) {
                                struct ea __0__V61;

                                error__FiP3locPCcRC2eaN34(
                                    (int)'i', &tloc, (const char *)"unget: saved==%c",
                                    (const struct ea *)((__2__X83 = saved),
                                                        (((((&__0__V61)->__O1__2ea.i = __2__X83),
                                                           0)),
                                                         (&__0__V61))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            saved = __2lxchar;
                        }

                        ;
                        {
                            union YYSTYPE __1__Xy00qjtkvpt5vcij;

                            addtok__FUc7YYSTYPE3loc(
                                (unsigned char)97,
                                ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 14), __1__Xy00qjtkvpt5vcij),
                                tloc);

                            return (unsigned char)97;
                        }

                        ;
                    case 98:
                        txtfree = txtstart;
                        {
                            static bit __6warned = 0;
                            if (__6warned == 0) {
                                {
                                    struct ea __0__V62;

                                    error__FiP3locPCcRC2eaN34(
                                        (int)'s', &tloc, (const char *)"%k",
                                        (const struct ea *)(((((&__0__V62)->__O1__2ea.i =
                                                                   ((unsigned long)__4x)),
                                                              0)),
                                                            (&__0__V62)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    __6warned = 1;
                                }
                            }
                        }
                        {
                            union YYSTYPE __1__Xy00qjtkvpt5vcij;

                            addtok__FUc7YYSTYPE3loc(
                                (unsigned char)__1n->__O2__4name.syn_class,
                                ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = ((int)__4x)),
                                 __1__Xy00qjtkvpt5vcij),
                                tloc);
                            return (unsigned char)__1n->__O2__4name.syn_class;
                        }

                        ;
                    case 99:
                        txtfree = txtstart;
                        {
                            static bit __6warned = 0;
                            if (__6warned == 0) {
                                {
                                    struct ea __0__V63;

                                    error__FiP3locPCcRC2eaN34(
                                        (int)'s', &tloc, (const char *)"%k",
                                        (const struct ea *)(((((&__0__V63)->__O1__2ea.i =
                                                                   ((unsigned long)__4x)),
                                                              0)),
                                                            (&__0__V63)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    __6warned = 1;
                                }
                            }
                        }
                        {
                            union YYSTYPE __1__Xy00qjtkvpt5vcij;

                            addtok__FUc7YYSTYPE3loc(
                                (unsigned char)__1n->__O2__4name.syn_class,
                                ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = ((int)__4x)),
                                 __1__Xy00qjtkvpt5vcij),
                                tloc);
                            return (unsigned char)__1n->__O2__4name.syn_class;
                        }

                        ;
                    case 100:
                        txtfree = txtstart;
                        {
                            static bit __6warned = 0;
                            if (__6warned == 0) {
                                {
                                    struct ea __0__V64;

                                    error__FiP3locPCcRC2eaN34(
                                        (int)'s', &tloc, (const char *)"%k",
                                        (const struct ea *)(((((&__0__V64)->__O1__2ea.i =
                                                                   ((unsigned long)__4x)),
                                                              0)),
                                                            (&__0__V64)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    __6warned = 1;
                                }
                            }
                        }
                        {
                            union YYSTYPE __1__Xy00qjtkvpt5vcij;

                            addtok__FUc7YYSTYPE3loc(
                                (unsigned char)__1n->__O2__4name.syn_class,
                                ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = ((int)__4x)),
                                 __1__Xy00qjtkvpt5vcij),
                                tloc);
                            return (unsigned char)__1n->__O2__4name.syn_class;
                        }

                        ;
                    case 101: {
                        static bit __6warned = 0;
                        if (__6warned == 0) {
                            unsigned long __2__X84;

                            {
                                struct ea __0__V65;

                                error__FiP3locPCcRC2eaN34(
                                    (int)'w', &tloc,
                                    (const char *)"%k is a future reserved keyword",
                                    (const struct ea *)((__2__X84 = __1n->__O2__4name.syn_class),
                                                        (((((&__0__V65)->__O1__2ea.i = __2__X84),
                                                           0)),
                                                         (&__0__V65))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                __6warned = 1;
                            }
                        }
                    }
                        {
                            char *__1__X85;

                            union YYSTYPE __1__Xy00aqtkvpt5vcij;

                            addtok__FUc7YYSTYPE3loc(
                                (unsigned char)80,
                                ((__1__X85 = ((in_progress__17templ_compilation ||
                                               parameters_in_progress__17templ_compilation)
                                                  ? strdup((const char *)txtstart)
                                                  : txtstart)),
                                 ((__1__Xy00aqtkvpt5vcij.s__7YYSTYPE = (const char *)__1__X85),
                                  __1__Xy00aqtkvpt5vcij)),
                                tloc);

                            return (unsigned char)80;
                        }

                        ;
                    case 102: {
                        static bit __6warned = 0;
                        if (__6warned == 0) {
                            unsigned long __2__X86;

                            {
                                struct ea __0__V66;

                                error__FiP3locPCcRC2eaN34(
                                    (int)'w', &tloc,
                                    (const char *)"%k is a future reserved keyword",
                                    (const struct ea *)((__2__X86 = __1n->__O2__4name.syn_class),
                                                        (((((&__0__V66)->__O1__2ea.i = __2__X86),
                                                           0)),
                                                         (&__0__V66))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                __6warned = 1;
                            }
                        }
                    }
                        {
                            char *__1__X87;

                            union YYSTYPE __1__Xy00aqtkvpt5vcij;

                            addtok__FUc7YYSTYPE3loc(
                                (unsigned char)80,
                                ((__1__X87 = ((in_progress__17templ_compilation ||
                                               parameters_in_progress__17templ_compilation)
                                                  ? strdup((const char *)txtstart)
                                                  : txtstart)),
                                 ((__1__Xy00aqtkvpt5vcij.s__7YYSTYPE = (const char *)__1__X87),
                                  __1__Xy00aqtkvpt5vcij)),
                                tloc);

                            return (unsigned char)80;
                        }

                        ;
                    case 103: {
                        static bit __6warned = 0;
                        if (__6warned == 0) {
                            unsigned long __2__X88;

                            {
                                struct ea __0__V67;

                                error__FiP3locPCcRC2eaN34(
                                    (int)'w', &tloc,
                                    (const char *)"%k is a future reserved keyword",
                                    (const struct ea *)((__2__X88 = __1n->__O2__4name.syn_class),
                                                        (((((&__0__V67)->__O1__2ea.i = __2__X88),
                                                           0)),
                                                         (&__0__V67))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                __6warned = 1;
                            }
                        }
                    }
                        {
                            char *__1__X89;

                            union YYSTYPE __1__Xy00aqtkvpt5vcij;

                            addtok__FUc7YYSTYPE3loc(
                                (unsigned char)80,
                                ((__1__X89 = ((in_progress__17templ_compilation ||
                                               parameters_in_progress__17templ_compilation)
                                                  ? strdup((const char *)txtstart)
                                                  : txtstart)),
                                 ((__1__Xy00aqtkvpt5vcij.s__7YYSTYPE = (const char *)__1__X89),
                                  __1__Xy00aqtkvpt5vcij)),
                                tloc);

                            return (unsigned char)80;
                        }

                        ;
                    default:
                        txtfree = txtstart;
                        {
                            union YYSTYPE __1__Xy00qjtkvpt5vcij;

                            addtok__FUc7YYSTYPE3loc(
                                (unsigned char)__1n->__O2__4name.syn_class,
                                ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = ((int)__4x)),
                                 __1__Xy00qjtkvpt5vcij),
                                tloc);
                            return (unsigned char)__1n->__O2__4name.syn_class;
                        }

                        ;
                    }
                }
            }

            {
                char *__1__X90;

                union YYSTYPE __1__Xy00aqtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)80,
                    ((__1__X90 = ((in_progress__17templ_compilation ||
                                   parameters_in_progress__17templ_compilation)
                                      ? strdup((const char *)txtstart)
                                      : txtstart)),
                     ((__1__Xy00aqtkvpt5vcij.s__7YYSTYPE = (const char *)__1__X90),
                      __1__Xy00aqtkvpt5vcij)),
                    tloc);

                return (unsigned char)80;
            }

            ;

        case 2:
            __1ret = 82;

            if (__2lxchar == '0') {
                int __4pkchar;
                __4pkchar = fgetc(in_file);
                if ((__4pkchar == 'x') || (__4pkchar == 'X')) {
                    (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                        : (((int)(((*(txtfree++))) = __2lxchar)));
                    lxget__FiT1(__4pkchar, 010);
                    txtfree--;
                    if ((txtfree - txtstart) < 3)
                        error__FP3locPCcRC2eaN33(&tloc, (const char *)"hex digitX after \"0x\"",
                                                 (const struct ea *)ea0, (const struct ea *)ea0,
                                                 (const struct ea *)ea0, (const struct ea *)ea0);
                    saved ? (((__2lxchar = saved), (saved = 0)), __2lxchar)
                          : (__2lxchar = fgetc(in_file));
                    goto getsuffix;
                }
                {
                    unsigned long __2__X91;

                    if (saved) {
                        struct ea __0__V68;

                        error__FiP3locPCcRC2eaN34(
                            (int)'i', &tloc, (const char *)"unget: saved==%c",
                            (const struct ea *)((__2__X91 = saved),
                                                (((((&__0__V68)->__O1__2ea.i = __2__X91), 0)),
                                                 (&__0__V68))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    saved = __4pkchar;
                }

                ;
            }

            lxget__FiT1(__2lxchar, 02);
            txtfree--;

            if ((saved ? (((__2lxchar = saved), (saved = 0)), __2lxchar)
                       : (__2lxchar = fgetc(in_file))) == '.') {

            getfp:
                lxget__FiT1((int)'.', 02);
                txtfree--;
                __1ret = 83;
                saved ? (((__2lxchar = saved), (saved = 0)), __2lxchar)
                      : (__2lxchar = fgetc(in_file));
            }

            ;

            if ((__2lxchar == 'e') || (__2lxchar == 'E')) {
                (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                    : (((int)(((*(txtfree++))) = __2lxchar)));
                __2lxchar = fgetc(in_file);
                if ((__2lxchar == '-') || (__2lxchar == '+')) {
                    (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                        : (((int)(((*(txtfree++))) = __2lxchar)));
                    __2lxchar = fgetc(in_file);
                }
                if ((lxmask[(__2lxchar + 1)]) & 02) {
                    lxget__FiT1(__2lxchar, 02);
                    txtfree--;
                    saved ? (((__2lxchar = saved), (saved = 0)), __2lxchar)
                          : (__2lxchar = fgetc(in_file));
                } else
                    error__FP3locPCcRC2eaN33(&tloc, (const char *)"missing exponent digits?",
                                             (const struct ea *)ea0, (const struct ea *)ea0,
                                             (const struct ea *)ea0, (const struct ea *)ea0);
                __1ret = 83;
            }

            ;

            if ((((*txtstart)) == '0') && (__1ret == 82)) {
                char *__4bch;

                __4bch = txtstart;
                while ((++__4bch) <= txtfree) {
                    if ((((*__4bch)) == '8') || (((*__4bch)) == '9')) {
                        struct ea __0__V69;

                        error__FP3locPCcRC2eaN33(
                            &tloc, (const char *)"%c used as octal digit",
                            (const struct ea *)(((((&__0__V69)->__O1__2ea.i =
                                                       ((unsigned long)((*__4bch)))),
                                                  0)),
                                                (&__0__V69)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
            }

        getsuffix:
            switch (__2lxchar) {
            case 'f':
            case 'F':
                if (__1ret == 82) {
                    struct ea __0__V70;

                    error__FP3locPCcRC2eaN33(&tloc, (const char *)"%c suffix for integer constant",
                                             (const struct ea *)(((((&__0__V70)->__O1__2ea.i =
                                                                        ((unsigned long)__2lxchar)),
                                                                   0)),
                                                                 (&__0__V70)),
                                             (const struct ea *)ea0, (const struct ea *)ea0,
                                             (const struct ea *)ea0);
                } else
                    (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                        : (((int)(((*(txtfree++))) = __2lxchar)));
                break;
            case 'u':
            case 'U':
                if (__1ret == 83) {
                    {
                        struct ea __0__V71;

                        error__FP3locPCcRC2eaN33(
                            &tloc, (const char *)"%c suffix for floating constant",
                            (const struct ea *)(((((&__0__V71)->__O1__2ea.i =
                                                       ((unsigned long)__2lxchar)),
                                                  0)),
                                                (&__0__V71)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        break;
                    }
                }
                (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                    : (((int)(((*(txtfree++))) = __2lxchar)));
                switch (__2lxchar = fgetc(in_file)) {
                case 'l':
                case 'L':
                    (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                        : (((int)(((*(txtfree++))) = __2lxchar)));
                    switch (__2lxchar = fgetc(in_file)) {
                    case 'l':
                    case 'L':
                        (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                            : (((int)(((*(txtfree++))) = __2lxchar)));
                        break;
                    default:
                        saved = __2lxchar;
                        break;
                    }
                    break;
                default:
                    saved = __2lxchar;
                    break;
                }
                break;
            case 'l':
            case 'L':
                (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                    : (((int)(((*(txtfree++))) = __2lxchar)));
                if (__1ret == 83) {
                    break;
                }
                switch (__2lxchar = fgetc(in_file)) {
                case 'l':
                case 'L':
                    (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                        : (((int)(((*(txtfree++))) = __2lxchar)));
                    switch (__2lxchar = fgetc(in_file)) {
                    case 'u':
                    case 'U':
                        (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                            : (((int)(((*(txtfree++))) = __2lxchar)));
                        break;
                    default:
                        saved = __2lxchar;
                        break;
                    }
                    break;
                case 'u':
                case 'U':
                    (txtmax <= txtfree) ? new_buf__Fc((char)__2lxchar)
                                        : (((int)(((*(txtfree++))) = __2lxchar)));
                    break;
                default:
                    saved = __2lxchar;
                    break;
                }
                break;
            default:
                saved = __2lxchar;
                break;
            }

            ;

            if ((((*txtstart)) == '0') && ((txtfree - txtstart) == 1)) {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)86,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 0), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)86;
            }

            ;

            (txtmax <= txtfree) ? new_buf__Fc((char)0) : (((int)(((*(txtfree++))) = 0)));
            {
                char *__1__X92;

                union YYSTYPE __1__Xy00aqtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    __1ret,
                    ((__1__X92 = txtstart),
                     ((__1__Xy00aqtkvpt5vcij.s__7YYSTYPE = (const char *)__1__X92),
                      __1__Xy00aqtkvpt5vcij)),
                    tloc);

                return __1ret;
            }

            ;

        case 8:
            switch (__2lxchar = fgetc(in_file)) {
            case '.':
                if ((__2lxchar = fgetc(in_file)) != '.') {
                    error__FP3locPCcRC2eaN33(&tloc, (const char *)"token .. ?",
                                             (const struct ea *)ea0, (const struct ea *)ea0,
                                             (const struct ea *)ea0, (const struct ea *)ea0);
                    saved = __2lxchar;
                }
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)155,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 0), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)155;
                }

                ;
            case '*': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)180,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 45), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)180;
            }

            ;
            }

            if ((lxmask[(__2lxchar + 1)]) & 02) {
                {
                    unsigned long __2__X93;

                    if (saved) {
                        struct ea __0__V72;

                        error__FiP3locPCcRC2eaN34(
                            (int)'i', &tloc, (const char *)"unget: saved==%c",
                            (const struct ea *)((__2__X93 = saved),
                                                (((((&__0__V72)->__O1__2ea.i = __2__X93), 0)),
                                                 (&__0__V72))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    saved = __2lxchar;
                }

                ;
                goto getfp;
            }
            saved = __2lxchar;
            {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)45,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 0), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)45;
            }

            ;

        case 4:
            get_string__Fv();
            {
                char *__1__X94;

                union YYSTYPE __1__Xy00aqtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)81,
                    ((__1__X94 = txtstart),
                     ((__1__Xy00aqtkvpt5vcij.s__7YYSTYPE = (const char *)__1__X94),
                      __1__Xy00aqtkvpt5vcij)),
                    tloc);

                return (unsigned char)81;
            }

            ;

        case 5: {
            char *__1__X95;

            union YYSTYPE __1__Xy00aqtkvpt5vcij;

            addtok__FUc7YYSTYPE3loc((unsigned char)84,
                                    ((__1__X95 = chconst__Fv()),
                                     ((__1__Xy00aqtkvpt5vcij.s__7YYSTYPE = (const char *)__1__X95),
                                      __1__Xy00aqtkvpt5vcij)),
                                    tloc);

            return (unsigned char)84;
        }

        ;

        case 6: {
            int __4i;
            int __4j;

            (txtmax <= txtfree) ? new_buf__Fc('`') : (((int)(((*(txtfree++))) = '`')));

            for (__4i = 0; __4i < 7; ++__4i) {
                (txtmax <= txtfree) ? new_buf__Fc((char)(__4j = fgetc(in_file)))
                                    : (((int)(((*(txtfree++))) = (__4j = fgetc(in_file)))));
                if (__4j == '`')
                    break;
            }
            (txtmax <= txtfree) ? new_buf__Fc((char)0) : (((int)(((*(txtfree++))) = 0)));
            if (6 < __4i)
                error__FiP3locPCcRC2eaN34((int)'l', &tloc,
                                          (const char *)"bcd constant exceeds 6 characters",
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0);
            {
                char *__1__X96;

                union YYSTYPE __1__Xy00aqtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)84,
                    ((__1__X96 = txtstart),
                     ((__1__Xy00aqtkvpt5vcij.s__7YYSTYPE = (const char *)__1__X96),
                      __1__Xy00aqtkvpt5vcij)),
                    tloc);

                return (unsigned char)84;
            }

            ;
        }

        case 7:
            switch (__2lxchar = fgetc(in_file)) {
            case '*':
                lxcom__Fv();
                break;
            case '/':
                linecom__Fv();
                break;
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)90,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 129), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)90;
            }

            ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)93,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 51), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)93;
                }

                ;
            }

        case 10:
            continue;

        case 11:
            ++tloc.line__3loc;

            saved = lxtitle__Fv();
            continue;

        case 12:
            if (128 <= (b_level++)) {
                error__FiP3locPCcRC2eaN34((int)'l', &tloc, (const char *)"blocks too deeply nested",
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0);
                ext__Fi(3);
            }
            {
                struct loc __1__X97;

                union YYSTYPE __1__Xy00adtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)73,
                    ((__1__X97 = tloc),
                     ((__1__Xy00adtkvpt5vcij.l__7YYSTYPE = __1__X97), __1__Xy00adtkvpt5vcij)),
                    tloc);

                return (unsigned char)73;
            }

            ;

        case 13:
            if ((lcount + (b_level--)) <= 0) {
                error__FP3locPCcRC2eaN33(&tloc, (const char *)"unexpected '}'",
                                         (const struct ea *)ea0, (const struct ea *)ea0,
                                         (const struct ea *)ea0, (const struct ea *)ea0);
                b_level = 0;
            }
            {
                struct loc __1__X98;

                union YYSTYPE __1__Xy00adtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)74,
                    ((__1__X98 = tloc),
                     ((__1__Xy00adtkvpt5vcij.l__7YYSTYPE = __1__X98), __1__Xy00adtkvpt5vcij)),
                    tloc);

                return (unsigned char)74;
            }

            ;

        case 14:
            p_level++;
            {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)40,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 0), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)40;
            }

            ;

        case 15:
            if ((p_level--) <= 0) {
                error__FP3locPCcRC2eaN33(&tloc, (const char *)"unexpected ')'",
                                         (const struct ea *)ea0, (const struct ea *)ea0,
                                         (const struct ea *)ea0, (const struct ea *)ea0);
                p_level = 0;
            }
            {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)41,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 0), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)41;
            }

            ;

        case 17:
            switch (__2lxchar = fgetc(in_file)) {
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)92,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 62), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)92;
            }

            ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)70,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 70), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)70;
                }

                ;
            }

        case 28:
            switch (__2lxchar = fgetc(in_file)) {
            case ':': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)160,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 0), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)160;
            }

            ;
            case '=':
                error__FP3locPCcRC2eaN33(&tloc, (const char *)"':=' is not a c++ operator",
                                         (const struct ea *)ea0, (const struct ea *)ea0,
                                         (const struct ea *)ea0, (const struct ea *)ea0);
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)70,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 70), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)70;
                }

                ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)69,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 69), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)69;
                }

                ;
            }
        case 24:
            switch (__2lxchar = fgetc(in_file)) {
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)92,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 63), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)92;
            }

            ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)46,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 46), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)46;
                }

                ;
            }
        case 19:
            switch (__2lxchar = fgetc(in_file)) {
            case '>':
                switch (__2lxchar = fgetc(in_file)) {
                case '=': {

                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)90,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 135), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)90;

                }

                ;
                    break;
                default:
                    saved = __2lxchar;
                    {
                        union YYSTYPE __1__Xy00qjtkvpt5vcij;

                        addtok__FUc7YYSTYPE3loc(
                            (unsigned char)94,
                            ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 57), __1__Xy00qjtkvpt5vcij),
                            tloc);

                        return (unsigned char)94;
                    }

                    ;
                }
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)91,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 61), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)91;
            }

            ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)60,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 60), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)60;
                }

                ;
            }
        case 18:
            switch (__2lxchar = fgetc(in_file)) {
            case '<':
                switch (__2lxchar = fgetc(in_file)) {
                case '=': {

                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)90,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 134), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)90;
                }

                ;
                default:
                    saved = __2lxchar;
                    {
                        union YYSTYPE __1__Xy00qjtkvpt5vcij;

                        addtok__FUc7YYSTYPE3loc(
                            (unsigned char)94,
                            ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 56), __1__Xy00qjtkvpt5vcij),
                            tloc);

                        return (unsigned char)94;
                    }

                    ;
                }
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)91,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 59), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)91;
            }

            ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)58,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 58), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)58;
                }

                ;
            }
        case 22:
            switch (__2lxchar = fgetc(in_file)) {
            case '&': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)66,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 66), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)66;
            }

            ;
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)90,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 131), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)90;
            }

            ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)52,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 52), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)52;
                }

                ;
            }
        case 21:
            switch (__2lxchar = fgetc(in_file)) {
            case '|': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)67,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 67), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)67;
            }

            ;
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)90,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 132), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)90;
            }

            ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)65,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 65), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)65;
                }

                ;
            }
        case 20:
            switch (__2lxchar = fgetc(in_file)) {
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)90,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 133), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)90;
            }

            ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)64,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 64), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)64;
                }

                ;
            }
        case 27:
            switch (__2lxchar = fgetc(in_file)) {
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)90,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 126), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)90;
            }

            ;
            case '+': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)95,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 48), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)95;
            }

            ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)54,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 54), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)54;
                }

                ;
            }
        case 25:
            switch (__2lxchar = fgetc(in_file)) {
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)90,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 127), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)90;
            }

            ;
            case '-': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)95,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 49), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)95;
            }

            ;
            case '>':
                if ((__2lxchar = fgetc(in_file)) == '*') {
                    {
                        union YYSTYPE __1__Xy00qjtkvpt5vcij;

                        addtok__FUc7YYSTYPE3loc(
                            (unsigned char)180,
                            ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 44), __1__Xy00qjtkvpt5vcij),
                            tloc);

                        return (unsigned char)180;
                    }

                    ;

                } else
                    saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)44,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 44), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)44;
                }

                ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)55,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 55), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)55;
                }

                ;
            }
        case 26:
            switch (__2lxchar = fgetc(in_file)) {
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)90,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 128), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)90;
            }

            ;
            case '/':
                error__FiP3locPCcRC2eaN34((int)'w', &tloc, (const char *)"*/ not as end of comment",
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0);
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)50,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 50), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)50;
                }

                ;
            }
        case 23:
            switch (__2lxchar = fgetc(in_file)) {
            case '=': {
                union YYSTYPE __1__Xy00qjtkvpt5vcij;

                addtok__FUc7YYSTYPE3loc(
                    (unsigned char)90,
                    ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 130), __1__Xy00qjtkvpt5vcij), tloc);

                return (unsigned char)90;
            }

            ;
            default:
                saved = __2lxchar;
                {
                    union YYSTYPE __1__Xy00qjtkvpt5vcij;

                    addtok__FUc7YYSTYPE3loc(
                        (unsigned char)93,
                        ((__1__Xy00qjtkvpt5vcij.t__7YYSTYPE = 53), __1__Xy00qjtkvpt5vcij), tloc);

                    return (unsigned char)93;
                }

                ;
            }
        default: {
            {
                struct ea __0__V73;

                struct ea __0__V74;

                error__FiP3locPCcRC2eaN34(
                    (int)'i', &tloc, (const char *)"lex act==%d getc()->%d",
                    (const struct ea *)(((&__0__V73)->__O1__2ea.p = ((const void *)__2p)),
                                        (&__0__V73)),
                    (const struct ea *)(((((&__0__V74)->__O1__2ea.i = ((unsigned long)__2lxchar)),
                                          0)),
                                        (&__0__V74)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }
        }

        error__FiP3locPCcRC2eaN34((int)'i', &tloc, (const char *)"lex, main switch",
                                  (const struct ea *)ea0, (const struct ea *)ea0,
                                  (const struct ea *)ea0, (const struct ea *)ea0);
    }
}

static int lxtitle__Fv(void) {
    int __1c;

    for (;;) {
        saved ? (((__1c = saved), (saved = 0)), __1c) : (__1c = fgetc(in_file));

        switch (__1c) {
        default:
            return __1c;
        case '\n':
            tloc.line__3loc++;

        ll:
            break;
        case '#': {
            int __4cl;

            __4cl = tloc.line__3loc;
            tloc.line__3loc = 0;
            for (;;)
                switch (__1c = fgetc(in_file)) {
                case '"':
                    txtstart = txtfree;
                    for (;;)
                        switch (__1c = fgetc(in_file)) {
                        case '"':
                            (txtmax <= txtfree) ? new_buf__Fc('\0')
                                                : (((int)(((*(txtfree++))) = '\0')));

                            while ((__1c = fgetc(in_file)) != '\n')
                                ;

                            if ((*txtstart)) {
                                const char *__7fn;

                                struct Block_CPchar *__0__X99;

                                int __2__X100;

                                if ((__7fn = ((
                                         *((__0__X99 = (&file_name)),
                                           ((__2__X100 = tcurr_file),
                                            ((((CPchar *)(&(
                                                __0__X99->p__12Block_CPchar[__2__X100])))))))))) &&
                                    (strcmp((const char *)txtstart, __7fn) == 0)) {
                                } else {
                                    int __8found;
                                    int __8findex;

                                    __8found = 0;
                                    __8findex = Nfile;
                                    for (; __8findex >= 0; __8findex--) {
                                        struct Block_CPchar *__0__X101;

                                        if (__8findex == tcurr_file)
                                            continue;
                                        __7fn =
                                            ((*((__0__X101 = (&file_name)),
                                                ((((CPchar *)(&(
                                                    __0__X101->p__12Block_CPchar[__8findex]))))))));
                                        if ((__7fn != 0) &&
                                            (strcmp((const char *)txtstart, __7fn) == 0)) {
                                            __8found = 1;
                                            tcurr_file = __8findex;
                                            break;
                                        }
                                    }
                                    if (__8found == 0) {
                                        char *__9p;

                                        struct Block_CPchar *__0__X102;

                                        unsigned long __2__X103;

                                        struct Block_CPchar *__0__X104;

                                        int __2__X105;

                                        __9p = (((char *)__nw__FUl((
                                            size_t)((sizeof(char)) * ((txtfree - txtstart) + 1)))));
                                        ((void)strcpy(__9p, (const char *)txtstart));
                                        tcurr_file = (++Nfile);
                                        ((__0__X102 = (&file_name)),
                                         ((__2__X103 = Nfile),
                                          (((__2__X103 < __0__X102->n__12Block_CPchar) ||
                                            grow__12Block_CPcharFUl(__0__X102, __2__X103)))));
                                        ((*((__0__X104 = (&file_name)),
                                            ((__2__X105 = Nfile),
                                             ((((CPchar *)(&(
                                                 __0__X104->p__12Block_CPchar[__2__X105]))))))))) =
                                            (const char *)__9p;
                                    }
                                }
                            } else {
                                tcurr_file = 0;
                            }
                            txtfree = txtstart;
                            tloc.file__3loc = tcurr_file;
                            if (dtpt_opt && (doneflag == 0)) {
                                first_file = 0;
                                doneflag = 1;
                            }

                            goto ll;
                        case '\n':
                            error__FP3locPCcRC2eaN33(
                                &tloc, (const char *)"unexpected end of line on '# line'",
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0, (const struct ea *)ea0);
                        default:
                            (txtmax <= txtfree) ? new_buf__Fc((char)__1c)
                                                : (((int)(((*(txtfree++))) = __1c)));
                        }
                case ' ':
                    break;

                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    tloc.line__3loc = (((tloc.line__3loc * 10) + __1c) - '0');
                    break;

                case 'l':
                    if ((((__1c = fgetc(in_file)) == 'i') && ((__1c = fgetc(in_file)) == 'n')) &&
                        ((__1c = fgetc(in_file)) == 'e'))
                        break;
                case '\n':
                    putline__3locFv(&tloc);
                    goto ll;

                default:
                    tloc.line__3loc = __4cl;
                    (txtmax <= txtfree) ? new_buf__Fc('#') : (((int)(((*(txtfree++))) = '#')));
                    (txtmax <= txtfree) ? new_buf__Fc((char)__1c)
                                        : (((int)(((*(txtfree++))) = __1c)));
                    while ((__1c = fgetc(in_file)) != '\n')
                        (txtmax <= txtfree) ? new_buf__Fc((char)__1c)
                                            : (((int)(((*(txtfree++))) = __1c)));
                    (txtmax <= txtfree) ? new_buf__Fc('\0') : (((int)(((*(txtfree++))) = '\0')));
                    fprintf(out_file, (const char *)"\n%s\n", txtstart);
                    txtstart = txtfree;
                    tloc.line__3loc++;

                    goto ll;
                }
        }
        }
    }
}

void __sti___in_progress_(void) {
    struct Block_CPchar *__0__X106;

    ((__0__X106 = (&file_name)),
     (((__0__X106 ||
        (__0__X106 = (struct Block_CPchar *)__nw__FUl((size_t)(sizeof(struct Block_CPchar)))))
           ? ((__0__X106->n__12Block_CPchar = 0), (__0__X106->p__12Block_CPchar = 0))
           : 0),
      __0__X106));

    out_file = _get_stdout();
    in_file = _get_stdin();
}

void __std___in_progress_(void) {
    struct Block_CPchar *__0__X107;

    ((__0__X107 = (&file_name)),
     ((__0__X107 ? (((void)(__dl__FPv((void *)__0__X107->p__12Block_CPchar),
                            (__0__X107 ? (((void)(((void)0)))) : (((void)0))))))
                 : (((void)0)))));
}

extern Ptfct ptfct_free__9templ_fct;

extern Pbase_inst head__10basic_inst;

extern Pcons last_friend_cons__17templ_compilation;

extern Pcons last_cons__17templ_compilation;

extern Pcons friend_templ_refs__17templ_compilation;

extern Pcons templ_refs__17templ_compilation;

extern int formals_in_progress__17templ_compilation;

extern int parameters_in_progress__17templ_compilation;

extern Ptstate save_templ__17templ_compilation;

extern Ptable templates__17templ_compilation;

extern Pexpr actuals__17templ_compilation;

extern Plist params__17templ_compilation;

extern Ptempl_base parsed_template__17templ_compilation;

extern Ptempl owner__17templ_compilation;

extern Pfunt f_owner__17templ_compilation;

extern Pfunt f_list__17templ_compilation;

extern Ptempl list__17templ_compilation;

extern Plist param_end__17templ_compilation;

extern struct toknode *free_toks__7toknode;

extern Pstmt stmt_free__4stmt;

extern Pname name_free__4name;

extern Pexpr expr_free__4expr;

extern Pptr ptr_free__3ptr;

extern Pvec vec_free__3vec;

extern Pfct fct_free__3fct;

extern Pktab table_free__6ktable;

extern Ptable table_free__5table;

/* the end */
