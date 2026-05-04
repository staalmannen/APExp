
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

Pktab Gtbl = 0;
Pktab Ctbl = 0;

Pname sta_name = 0;
static Ptype generic_tpdef = 0;

struct basetype *__ct__8basetypeFUcP4name(struct basetype *__0this, TOK, Pname);

struct ktable *__ct__6ktableFiP6ktableP4name(struct ktable *__0this, int, Pktab, Pname);

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

void syn_init__Fv(void) {
    struct type *__0__X26;

    struct node *__0__X1;

    generic_tpdef =
        ((__0__X26 = 0),
         (((__0__X26 || (__0__X26 = (struct type *)__nw__FUl((size_t)(sizeof(struct type)))))
               ? (((((((((__0__X26 =
                              (struct type *)((__0__X1 = (((struct node *)__0__X26))),
                                              (((__0__X1 || (__0__X1 = (struct node *)__nw__FUl(
                                                                 (size_t)(sizeof(struct node)))))
                                                    ? (((__0__X1->base__4node = 0),
                                                        (__0__X1->permanent__4node = 0)),
                                                       (__0__X1->baseclass__4node = 0))
                                                    : 0),
                                               __0__X1))),
                         (__0__X26->defined__4type = 0)),
                        (__0__X26->lex_level__4type = 0)),
                       (__0__X26->templ_base__4type = 0)),
                      (__0__X26->in_class__4type = 0)),
                     (__0__X26->nested_sig__4type = 0)),
                    (__0__X26->local_sig__4type = 0)),
                   (__0__X26->b_const__4type = 0)),
                  (__0__X26->ansi_const__4type = 0))
               : 0),
          __0__X26));
    generic_tpdef->base__4node = 190;
    generic_tpdef->permanent__4node = 1;
    any_type = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)141, (struct name *)0);
    any_type->permanent__4node = 1;

    any_type->defined__4type = 01;
    dummy = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)144, (struct expr *)0,
                                   (struct expr *)0);
    dummy->permanent__4node = 1;
    dummy->__O1__4expr.tp = (struct type *)any_type;
    zero = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)86, (struct expr *)0,
                                  (struct expr *)0);
    zero->permanent__4node = 1;
    sta_name = __ct__4nameFPCc((struct name *)0, (const char *)0);
    sta_name->permanent__4node = 1;

    Gtbl = __ct__6ktableFiP6ktableP4name((struct ktable *)0, 257, (struct ktable *)0,
                                         (struct name *)0);
    Ctbl = Gtbl;
}

int stcount = 0;

extern int sprintf(char *, const char *, ...);

char *make_name__FUc(TOK __1c) {
    char *__1s;

    __1s = (((char *)__nw__FUl((size_t)(8 * (sizeof(char))))));

    if (10000 <= (++stcount))
        error__FiPCc((int)'i', (const char *)"too many generatedNs");

    sprintf(__1s, (const char *)"__%c%d", __1c, stcount);
    return __1s;
}

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

Pbase type_adj__8basetypeFUc(register struct basetype *__0this, TOK __1t) {
    ;
    if (__0this->b_xname__8basetype) {
        const void *__2__X39;

        if (__0this->base__4node) {
            struct ea __0__V27;

            struct ea __0__V28;

            error__FPCcRC2eaN32(
                (const char *)"badBT:%n%k",
                (const struct ea *)((__2__X39 = (const void *)__0this->b_xname__8basetype),
                                    (((&__0__V27)->__O1__2ea.p = __2__X39), (&__0__V27))),
                (const struct ea *)(((((&__0__V28)->__O1__2ea.i = ((unsigned long)__1t)), 0)),
                                    (&__0__V28)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        } else {
            __0this->base__4node = 97;
            __0this->b_name__8basetype = __0this->b_xname__8basetype;
        }
        __0this->b_xname__8basetype = 0;
    }

    switch (__1t) {
        unsigned long __2__X40;

        unsigned long __2__X41;

    case 35:
        if (__0this->b_typedef__8basetype)
            error__FiPCc((int)'w', (const char *)"two typedefs");
        else if (__0this->b_inline__8basetype) {
            {
                struct ea __0__V29;

                struct ea __0__V30;

                error__FPCcRC2eaN32(
                    (const char *)"badBT:%k and%k",
                    (const struct ea *)(((((&__0__V29)->__O1__2ea.i = ((unsigned long)75)), 0)),
                                        (&__0__V29)),
                    (const struct ea *)(((((&__0__V30)->__O1__2ea.i = ((unsigned long)35)), 0)),
                                        (&__0__V30)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                __0this->b_typedef__8basetype = 0;
            }
        } else
            __0this->b_typedef__8basetype = 1;
        break;
    case 75:
        if (__0this->b_inline__8basetype)
            error__FiPCc((int)'w', (const char *)"two inlines");
        else if (__0this->b_typedef__8basetype) {
            {
                struct ea __0__V31;

                struct ea __0__V32;

                error__FPCcRC2eaN32(
                    (const char *)"badBT:%k and%k",
                    (const struct ea *)(((((&__0__V31)->__O1__2ea.i = ((unsigned long)35)), 0)),
                                        (&__0__V31)),
                    (const struct ea *)(((((&__0__V32)->__O1__2ea.i = ((unsigned long)75)), 0)),
                                        (&__0__V32)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                __0this->b_inline__8basetype = 0;
            }
        } else
            __0this->b_inline__8basetype = 1;
        break;
    case 77:
        __0this->b_virtual__8basetype = 1;

        break;
    case 26:
        if (__0this->b_const__4type)
            error__FiPCc((int)'w', (const char *)"two const declarators");

        __0this->b_const__4type = 1;

        break;
    case 37:
        __0this->b_unsigned__8basetype = 1;

        break;
    case 29:
        __0this->b_short__8basetype = 1;

        break;
    case 22:
        if (__0this->base__4node == 11) {
            if (__0this->b_long__8basetype) {
                error__FiPCc((int)'w', (const char *)"redundant long declarators");
                __0this->b_long__8basetype = 0;
            }
            __0this->base__4node = 181;
        } else if (__0this->b_long__8basetype > 1) {
            error__FiPCc((int)'w', (const char *)"too many long declarators");
        } else if (__0this->b_long__8basetype) {
            __0this->b_long__8basetype = 2;
        } else
            __0this->b_long__8basetype = 1;
        break;
    case 18:
    case 76:
    case 14:
    case 31:
    case 2:
    case 27:
        if (__0this->b_sto__8basetype) {
            struct ea __0__V33;

            struct ea __0__V34;

            error__FPCcRC2eaN32(
                (const char *)"badBT:%k%k",
                (const struct ea *)((__2__X40 = __0this->b_sto__8basetype),
                                    (((((&__0__V33)->__O1__2ea.i = __2__X40), 0)), (&__0__V33))),
                (const struct ea *)(((((&__0__V34)->__O1__2ea.i = ((unsigned long)__1t)), 0)),
                                    (&__0__V34)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        } else
            __0this->b_sto__8basetype = __1t;
        break;
    case 11:
        if (__0this->b_long__8basetype > 1)
            error__FiPCc((int)'w', (const char *)"excessive long declarators");
        if (__0this->b_long__8basetype) {
            __1t = 181;
            __0this->b_long__8basetype = 0;
        }

    case 38:
    case 5:
    case 21:
    case 15:
        if (__0this->base__4node) {
            struct ea __0__V35;

            struct ea __0__V36;

            error__FPCcRC2eaN32(
                (const char *)"badBT:%k%k",
                (const struct ea *)((__2__X41 = __0this->base__4node),
                                    (((((&__0__V35)->__O1__2ea.i = __2__X41), 0)), (&__0__V35))),
                (const struct ea *)(((((&__0__V36)->__O1__2ea.i = ((unsigned long)__1t)), 0)),
                                    (&__0__V36)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        } else
            __0this->base__4node = __1t;
        break;
    case 171:
        break;
    case 170: {
        struct ea __0__V37;

        error__FiPCcRC2eaN33(
            (int)'w', (const char *)"\"%k\" not implemented (ignored)",
            (const struct ea *)(((((&__0__V37)->__O1__2ea.i = ((unsigned long)__1t)), 0)),
                                (&__0__V37)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        break;
    default: {
        struct ea __0__V38;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"BT::type_adj(%k)",
            (const struct ea *)(((((&__0__V38)->__O1__2ea.i = ((unsigned long)__1t)), 0)),
                                (&__0__V38)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }
    }
    return __0this;
}

Pbase name_adj__8basetypeFP4name(register struct basetype *__0this, Pname __1n) {
    ;
    if (__0this->b_xname__8basetype) {
        const void *__2__X44;

        if (__0this->base__4node) {
            struct ea __0__V42;

            struct ea __0__V43;

            error__FPCcRC2eaN32(
                (const char *)"badBT:%n%n",
                (const struct ea *)((__2__X44 = (const void *)__0this->b_xname__8basetype),
                                    (((&__0__V42)->__O1__2ea.p = __2__X44), (&__0__V42))),
                (const struct ea *)(((&__0__V43)->__O1__2ea.p = ((const void *)__1n)), (&__0__V43)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        } else {
            __0this->base__4node = 97;
            __0this->b_name__8basetype = __0this->b_xname__8basetype;
        }
        __0this->b_xname__8basetype = 0;
    }

    if (((__0this->base__4node == 0) && (__1n->base__4node == 123)) &&
        ((__1n->__O1__4expr.tp->base__4node != 119) || (Ctbl->k_id__6ktable == 136))) {

        __0this->base__4node = 97;
        __0this->b_name__8basetype = __1n;
    } else
        __0this->b_xname__8basetype = __1n;

    return __0this;
}

static TOK type_set__FP8basetype(Pbase __1b) {
    TOK __1t;

    __1t = 0;

    if (__1b->b_long__8basetype > 1)
        __1t = 122;
    else if (__1b->b_long__8basetype)
        __1t = 22;
    else if (__1b->b_short__8basetype)
        __1t = 29;
    else if (__1b->b_unsigned__8basetype)
        __1t = 37;
    else if (__1b->b_inline__8basetype)
        __1t = 75;
    else if (__1b->b_virtual__8basetype)
        __1t = 77;
    else if (__1b->b_sto__8basetype == 76)
        __1t = 76;
    return __1t;
}

int declTag = 1;

static struct ea *__ct__2eaFUl(struct ea *__0this, size_t __2ii);

Pbase base_adj__8basetypeFP8basetype(register struct basetype *__0this, Pbase __1b) {
    ;
    {
        Pname __1bn;

        TOK __1t;

        __1bn = __1b->b_name__8basetype;

        switch (__0this->base__4node) {
            unsigned long __2__X61;

            const void *__2__X62;

        case 119:
        case 121: {
            struct ea __0__V45;

            struct ea __0__V46;

            error__FPCcRC2eaN32(
                (const char *)"NX after%k%n",
                (const struct ea *)((__2__X61 = __0this->base__4node),
                                    (((((&__0__V45)->__O1__2ea.i = __2__X61), 0)), (&__0__V45))),
                (const struct ea *)((__2__X62 = (const void *)__0this->b_name__8basetype),
                                    (((&__0__V46)->__O1__2ea.p = __2__X62), (&__0__V46))),
                (const struct ea *)ea0, (const struct ea *)ea0);
            return __0this;
        }
        }

        ;
        if (__0this->base__4node) {
            unsigned long __2__X63;

            const void *__2__X64;

            unsigned long __2__X65;

            if (__0this->b_name__8basetype) {
                struct ea __0__V47;

                struct ea __0__V48;

                struct ea __0__V49;

                struct ea __0__V50;

                error__FPCcRC2eaN32(
                    (const char *)"badBT:%k%n%k%n",
                    (const struct ea *)((__2__X63 = __0this->base__4node),
                                        (((((&__0__V47)->__O1__2ea.i = __2__X63), 0)),
                                         (&__0__V47))),
                    (const struct ea *)((__2__X64 = (const void *)__0this->b_name__8basetype),
                                        (((&__0__V48)->__O1__2ea.p = __2__X64), (&__0__V48))),
                    (const struct ea *)__ct__2eaFUl(&__0__V49, (unsigned long)__1b->base__4node),
                    (const struct ea *)(((&__0__V50)->__O1__2ea.p = ((const void *)__1bn)),
                                        (&__0__V50)));
            } else {
                struct ea __0__V51;

                struct ea __0__V52;

                struct ea __0__V53;

                error__FPCcRC2eaN32(
                    (const char *)"badBT:%k%k%n",
                    (const struct ea *)((__2__X65 = __0this->base__4node),
                                        (((((&__0__V51)->__O1__2ea.i = __2__X65), 0)),
                                         (&__0__V51))),
                    (const struct ea *)__ct__2eaFUl(&__0__V52, (unsigned long)__1b->base__4node),
                    (const struct ea *)(((&__0__V53)->__O1__2ea.p = ((const void *)__1bn)),
                                        (&__0__V53)),
                    (const struct ea *)ea0);
            }
        } else if (__1t = type_set__FP8basetype(__0this)) {
            const void *__2__X66;

            if (__0this->b_name__8basetype) {
                struct ea __0__V54;

                struct ea __0__V55;

                struct ea __0__V56;

                struct ea __0__V57;

                error__FPCcRC2eaN32(
                    (const char *)"badBT:%k%n%k%n",
                    (const struct ea *)(((((&__0__V54)->__O1__2ea.i = ((unsigned long)__1t)), 0)),
                                        (&__0__V54)),
                    (const struct ea *)((__2__X66 = (const void *)__0this->b_name__8basetype),
                                        (((&__0__V55)->__O1__2ea.p = __2__X66), (&__0__V55))),
                    (const struct ea *)__ct__2eaFUl(&__0__V56, (unsigned long)__1b->base__4node),
                    (const struct ea *)(((&__0__V57)->__O1__2ea.p = ((const void *)__1bn)),
                                        (&__0__V57)));
            } else {
                if ((declTag++) && (!((__1t == 75) && (__1b->base__4node == 121)))) {
                    struct ea __0__V58;

                    struct ea __0__V59;

                    struct ea __0__V60;

                    error__FPCcRC2eaN32(
                        (const char *)"badBT:%k%k%n",
                        (const struct ea *)(((((&__0__V58)->__O1__2ea.i = ((unsigned long)__1t)),
                                              0)),
                                            (&__0__V58)),
                        (const struct ea *)__ct__2eaFUl(&__0__V59,
                                                        (unsigned long)__1b->base__4node),
                        (const struct ea *)(((&__0__V60)->__O1__2ea.p = ((const void *)__1bn)),
                                            (&__0__V60)),
                        (const struct ea *)ea0);
                }
                __0this->base__4node = __1b->base__4node;

                __0this->b_name__8basetype = __1bn;
            }
        } else {
            __0this->base__4node = __1b->base__4node;
            __0this->b_name__8basetype = __1bn;
            __0this->b_table__8basetype = __1b->b_table__8basetype;
        }

        return __0this;
    }
}

void hide__4nameFv(struct name *__0this);

extern Pname k_find_name__FPCcP6ktableUc(const char *, Pktab, TOK);

extern int error__FPCc(const char *);

Pbase check__8basetypeFP4name(register struct basetype *__0this, Pname __1n) {
    __0this->b_inline__8basetype = 0;
    __0this->b_virtual__8basetype = 0;

    if (__0this->b_xname__8basetype && (__1n->__O1__4expr.tp || __1n->__O2__4expr.string)) {
        unsigned long __2__X84;

        const void *__2__X85;

        if (__0this->base__4node) {
            struct ea __0__V67;

            struct ea __0__V68;

            error__FPCcRC2eaN32(
                (const char *)"badBT:%k%n",
                (const struct ea *)((__2__X84 = __0this->base__4node),
                                    (((((&__0__V67)->__O1__2ea.i = __2__X84), 0)), (&__0__V67))),
                (const struct ea *)((__2__X85 = (const void *)__0this->b_xname__8basetype),
                                    (((&__0__V68)->__O1__2ea.p = __2__X85), (&__0__V68))),
                (const struct ea *)ea0, (const struct ea *)ea0);
        } else {
            __0this->base__4node = 97;
            __0this->b_name__8basetype = __0this->b_xname__8basetype;
        }
        __0this->b_xname__8basetype = 0;
    }

    if (__0this->b_xname__8basetype) {
        const void *__2__X86;

        if (__1n->__O2__4expr.string) {
            struct ea __0__V69;

            struct ea __0__V70;

            error__FPCcRC2eaN32(
                (const char *)"twoNs inD:%n%n",
                (const struct ea *)((__2__X86 = (const void *)__0this->b_xname__8basetype),
                                    (((&__0__V69)->__O1__2ea.p = __2__X86), (&__0__V69))),
                (const struct ea *)(((&__0__V70)->__O1__2ea.p = ((const void *)__1n)), (&__0__V70)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        } else {
            __1n->__O2__4expr.string = __0this->b_xname__8basetype->__O2__4expr.string;
            hide__4nameFv(__0this->b_xname__8basetype);
        }
        __0this->b_xname__8basetype = 0;
    }

    if ((((((ccl == 0) && __1n) && (__1n->n_oper__4name == 123)) && (!in_typedef)) &&
         (__1n->__O2__4name.n_qualifier == 0)) &&
        __1n->__O2__4expr.string) {

        Pname __2nx;

        __2nx = k_find_name__FPCcP6ktableUc(__1n->__O2__4expr.string, Ctbl, (unsigned char)0);
        if (__2nx && (__2nx->base__4node == 123))
            hide__4nameFv(__2nx);
    }

    {
        int __1defa;

        unsigned long __2__X89;

        __1defa = 0;
        switch (__0this->base__4node) {
            const void *__2__X87;

        case 0:
            __1defa = 1;
            __0this->base__4node = 21;
            break;
        case 121:
        case 119:
            if (__0this->b_name__8basetype->base__4node == 123) {
                struct ea __0__V71;

                struct ea __0__V72;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"TN%n inCO %p",
                    (const struct ea *)((__2__X87 = (const void *)__0this->b_name__8basetype),
                                        (((&__0__V71)->__O1__2ea.p = __2__X87), (&__0__V71))),
                    (const struct ea *)(((&__0__V72)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V72)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }

        if (__0this->b_long__8basetype || __0this->b_short__8basetype) {
            TOK __2sl;

            unsigned long __2__X88;

            __2sl =
                (__0this->b_short__8basetype ? 29 : ((__0this->b_long__8basetype > 1) ? 122 : 22));
            if (__0this->b_long__8basetype && __0this->b_short__8basetype) {
                struct ea __0__V73;

                struct ea __0__V74;

                error__FPCcRC2eaN32(
                    (const char *)"badBT:long short%k%n",
                    (const struct ea *)((__2__X88 = __0this->base__4node),
                                        (((((&__0__V73)->__O1__2ea.i = __2__X88), 0)),
                                         (&__0__V73))),
                    (const struct ea *)(((&__0__V74)->__O1__2ea.p = ((const void *)__1n)),
                                        (&__0__V74)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__0this->base__4node != 21) {
                struct ea __0__V75;

                struct ea __0__V76;

                struct ea __0__V77;

                error__FPCcRC2eaN32(
                    (const char *)"badBT:%k%k%n",
                    (const struct ea *)(((((&__0__V75)->__O1__2ea.i = ((unsigned long)__2sl)), 0)),
                                        (&__0__V75)),
                    (const struct ea *)__ct__2eaFUl(&__0__V76, (unsigned long)__0this->base__4node),
                    (const struct ea *)(((&__0__V77)->__O1__2ea.p = ((const void *)__1n)),
                                        (&__0__V77)),
                    (const struct ea *)ea0);
            } else
                __0this->base__4node = __2sl;
            __0this->b_short__8basetype = (__0this->b_long__8basetype = 0);
        }

        if (__0this->b_typedef__8basetype && __0this->b_sto__8basetype) {
            struct ea __0__V78;

            struct ea __0__V79;

            error__FPCcRC2eaN32(
                (const char *)"badBT:Tdef%k%n",
                (const struct ea *)((__2__X89 = __0this->b_sto__8basetype),
                                    (((((&__0__V78)->__O1__2ea.i = __2__X89), 0)), (&__0__V78))),
                (const struct ea *)(((&__0__V79)->__O1__2ea.p = ((const void *)__1n)), (&__0__V79)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        __0this->b_typedef__8basetype = (__0this->b_sto__8basetype = 0);

        if (__0this->__O1__8basetype.b_linkage) {
            if (1 <= bl_level)
                error__FPCc((const char *)"local linkage directive");
        }

        if (Pfctvec_type == 0)
            return __0this;

        if (__0this->b_const__4type) {
            if (__0this->b_unsigned__8basetype) {
                switch (__0this->base__4node) {
                    unsigned long __2__X90;

                default: {
                    struct ea __0__V80;

                    struct ea __0__V81;

                    error__FPCcRC2eaN32(
                        (const char *)"badBT: unsigned const %k%n",
                        (const struct ea *)((__2__X90 = __0this->base__4node),
                                            (((((&__0__V80)->__O1__2ea.i = __2__X90), 0)),
                                             (&__0__V80))),
                        (const struct ea *)(((&__0__V81)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V81)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    __0this->b_unsigned__8basetype = 0;
                case 22:
                case 122:
                case 29:
                case 21:
                case 5:
                    return __0this;
                }
                }
            }
            return __0this;
        } else if (__0this->b_unsigned__8basetype) {
            switch (__0this->base__4node) {
                unsigned long __2__X91;

            case 22:
                __dl__FPv((void *)__0this);
                return ulong_type;
            case 122:
                __dl__FPv((void *)__0this);
                return ullong_type;
            case 29:
                __dl__FPv((void *)__0this);
                return ushort_type;
            case 21:
                __dl__FPv((void *)__0this);
                return uint_type;
            case 5:
                __dl__FPv((void *)__0this);
                return uchar_type;
            default: {
                struct ea __0__V82;

                struct ea __0__V83;

                error__FPCcRC2eaN32(
                    (const char *)"badBT: unsigned%k%n",
                    (const struct ea *)((__2__X91 = __0this->base__4node),
                                        (((((&__0__V82)->__O1__2ea.i = __2__X91), 0)),
                                         (&__0__V82))),
                    (const struct ea *)(((&__0__V83)->__O1__2ea.p = ((const void *)__1n)),
                                        (&__0__V83)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                __0this->b_unsigned__8basetype = 0;
                return __0this;
            }
            }
        } else {
            switch (__0this->base__4node) {
            case 22:
                __dl__FPv((void *)__0this);
                return long_type;
            case 122:
                __dl__FPv((void *)__0this);
                return llong_type;
            case 29:
                __dl__FPv((void *)__0this);
                return short_type;
            case 21:
                if ((__0this == int_type) || (__0this == defa_type))
                    return __0this;
                __dl__FPv((void *)__0this);
                if (__1defa)
                    return defa_type;
                return int_type;
            case 5:
                __dl__FPv((void *)__0this);
                return char_type;
            case 38:
                __dl__FPv((void *)__0this);
                return void_type;
            case 97:
                if (__0this->b_name__8basetype->__O2__4name.n_qualifier) {
                    Pbase __4rv;

                    __4rv = (((struct basetype *)((
                        (struct basetype *)__0this->b_name__8basetype->__O2__4name.n_qualifier))));
                    __dl__FPv((void *)__0this);
                    return __4rv;
                } else {
                    __0this->permanent__4node = 1;
                    __0this->b_name__8basetype->__O2__4name.n_qualifier =
                        (((struct name *)(((struct name *)__0this))));
                    return __0this;
                }
            default:
                return __0this;
            }
        }
    }
}

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

extern Pname insert_type__FP4nameP6ktableUc(Pname, Pktab, TOK);

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

static int check_redef__FP4nameT1(Pname __1on, Pname __1nn) {
    if (Nold) {
        if (check__4typeFP4typeUcT2(__1on->__O1__4expr.tp, __1nn->__O1__4expr.tp, (unsigned char)0,
                                    (unsigned char)0) == 0) {
            __1nn->base__4node = 123;
            return 1;
        }
        if (__1nn->__O3__4expr.tpdef->in_class__4type &&
            (__1nn->__O3__4expr.tpdef->in_class__4type->csu__8classdef == 167)) {
            const void *__2__X101;

            if (__1nn->__O3__4expr.tpdef->defined__4type == 0) {
                struct ea __0__V92;

                error__FP3locPCcRC2eaN33(
                    &__1nn->where__4name, (const char *)"twoDs of %s (one in anonymous union)",
                    (const struct ea *)((__2__X101 = (const void *)__1nn->__O2__4expr.string),
                                        (((&__0__V92)->__O1__2ea.p = __2__X101), (&__0__V92))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        } else if (__1on->__O3__4expr.tpdef) {
            struct ea __0__V93;

            struct ea __0__V94;

            struct ea __0__V95;

            error__FP3locPCcRC2eaN33(
                &__1nn->where__4name, (const char *)"%n redefined:Tdef%t andTdef%t",
                (const struct ea *)(((&__0__V93)->__O1__2ea.p = ((const void *)__1on)),
                                    (&__0__V93)),
                (const struct ea *)__ct__2eaFPCv(&__0__V94, (const void *)__1on->__O1__4expr.tp),
                (const struct ea *)__ct__2eaFPCv(&__0__V95, (const void *)__1nn->__O1__4expr.tp),
                (const struct ea *)ea0);
        } else {
            struct ea __0__V96;

            struct ea __0__V97;

            struct ea __0__V98;

            error__FP3locPCcRC2eaN33(
                &__1nn->where__4name, (const char *)"%n redefined:%t andTdef%t",
                (const struct ea *)(((&__0__V96)->__O1__2ea.p = ((const void *)__1on)),
                                    (&__0__V96)),
                (const struct ea *)__ct__2eaFPCv(&__0__V97, (const void *)__1on->__O1__4expr.tp),
                (const struct ea *)__ct__2eaFPCv(&__0__V98, (const void *)__1nn->__O1__4expr.tp),
                (const struct ea *)ea0);
        }
        __1nn->__O3__4expr.tpdef->defined__4type = 1;
        {
            Pname __2nw;
            Pname __2x;

            __2nw = __ct__4nameFPCc((struct name *)0, (const char *)0);
            __2x = __1on;

            __2x->n_key__4name = 38;
            ((*__2nw)) = (*__1nn);
            __2nw->n_tbl_list__4name = 0;
            __2nw->n_ktable__4name = 0;
            __2nw->__O4__4expr.n_table = 0;
            __1on = insert_type__FP4nameP6ktableUc(__2nw, Ctbl, (unsigned char)97);
            if (Nold)
                error__FiP3locPCcRC2eaN34((int)'i', &__1nn->where__4name,
                                          (const char *)"cannot recover", (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0);
            __1on->__O1__4name.n_hidden = __2x;
        }
    }
    if (__1on->n_key__4name == 159) {
        if (__1nn->__O3__4expr.tpdef->in_class__4type &&
            (__1nn->__O3__4expr.tpdef->in_class__4type->csu__8classdef == 167)) {
            const void *__2__X102;

            if (__1nn->__O3__4expr.tpdef->defined__4type == 0) {
                struct ea __0__V99;

                error__FP3locPCcRC2eaN33(
                    &__1nn->where__4name, (const char *)"twoDs of %s (one in anonymous union)",
                    (const struct ea *)((__2__X102 = (const void *)__1nn->__O2__4expr.string),
                                        (((&__0__V99)->__O1__2ea.p = __2__X102), (&__0__V99))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        } else {
            struct ea __0__V100;

            error__FP3locPCcRC2eaN33(
                &__1nn->where__4name, (const char *)"%n redefined: identifier andTdef",
                (const struct ea *)(((&__0__V100)->__O1__2ea.p = ((const void *)__1on)),
                                    (&__0__V100)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        __1nn->__O3__4expr.tpdef->defined__4type = 1;
    }
    return 0;
}

Pname normalize__4nameFP8basetypeP5blockUc(struct name *__0this, Pbase, Pblock, bit);

extern char *strcpy(char *, const char *);

Pname get_mem__6ktableFi(struct ktable *__0this, int);

extern Pname insert_name__FP4nameP6ktable(Pname, Pktab);

Pname is_cl_obj__4typeFv(struct type *__0this);

extern int strcmp(const char *, const char *);

Pname aggr__8basetypeFv(register struct basetype *__0this) {
    ;
    if (__0this->b_xname__8basetype) {
        if (__0this->base__4node) {
            Pname __3n;

            __3n =
                __ct__4nameFPCc((struct name *)0, __0this->b_xname__8basetype->__O2__4expr.string);

            __0this->b_xname__8basetype = 0;
            return normalize__4nameFP8basetypeP5blockUc(__3n, __0this, (struct block *)0,
                                                        (unsigned char)0);
        } else {
            __0this->base__4node = 97;
            __0this->b_name__8basetype = __0this->b_xname__8basetype;
            __0this->b_xname__8basetype = 0;
        }
    }

    switch (__0this->base__4node) {
    case 119: {
        Pclass __3cl;
        const char *__3s;

        const void *__2__X117;

        unsigned long __2__X118;

        const void *__2__X119;

        __3cl = ((
            (struct classdef *)(((struct classdef *)__0this->b_name__8basetype->__O1__4expr.tp))));
        __3s = __3cl->string__8classdef;
        if (((__3cl->class_base__8classdef != 2) &&
             ((__3cl->in_class__4type == 0) ||
              (__3cl->in_class__4type->class_base__8classdef != 2))) &&
            (__0this->b_name__8basetype->base__4node == 123)) {
            struct ea __0__V103;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"TN%n inCO",
                (const struct ea *)((__2__X117 = (const void *)__0this->b_name__8basetype),
                                    (((&__0__V103)->__O1__2ea.p = __2__X117), (&__0__V103))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__0this->b_const__4type) {
            struct ea __0__V104;

            struct ea __0__V105;

            error__FPCcRC2eaN32(
                (const char *)"const%k%n",
                (const struct ea *)((__2__X118 = __3cl->csu__8classdef),
                                    (((((&__0__V104)->__O1__2ea.i = __2__X118), 0)), (&__0__V104))),
                (const struct ea *)((__2__X119 = (const void *)__0this->b_name__8basetype),
                                    (((&__0__V105)->__O1__2ea.p = __2__X119), (&__0__V105))),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__3cl->c_body__8classdef == 2) {
            unsigned long __2__X124;

            const void *__2__X125;

            if ((((__3s[0]) == '_') && ((__3s[1]) == '_')) && ((__3s[2]) == 'C')) {
                char *__5ss;
                Pname __5obj;

                unsigned long __2__X123;

                __5ss = (((char *)__nw__FUl((size_t)(8 * (sizeof(char))))));
                __5obj = __ct__4nameFPCc((struct name *)0, (const char *)__5ss);
                strcpy(__5ss, __3s);
                if ((__3cl->csu__8classdef == 36) && (__3cl->class_base__8classdef != 2)) {
                    (__5ss[2]) = 'O';
                    __3cl->csu__8classdef = 167;
                    {
                        Pname __6un;

                        int __6i;
                        Pname __6nn;

                        __6un = normalize__4nameFP8basetypeP5blockUc(
                            __5obj, __0this, (struct block *)0, (unsigned char)0);

                        __6i = 1;
                        __6nn = get_mem__6ktableFi(__3cl->k_tbl__8classdef, __6i);
                        for (; __6nn;
                             __6nn = (__6nn->n_tbl_list__4name
                                          ? __6nn->n_tbl_list__4name
                                          : get_mem__6ktableFi(__3cl->k_tbl__8classdef, ++__6i))) {
                            if (__6nn->__O2__4expr.string == 0)
                                continue;
                            if (__6nn->base__4node == 85) {
                                insert_name__FP4nameP6ktable(
                                    __ct__4nameFPCc((struct name *)0, __6nn->__O2__4expr.string),
                                    Ctbl);
                            } else if (__6nn->__O1__4expr.tp == 0) {
                                {
                                    struct ea __0__V106;

                                    error__FiPCcRC2eaN33(
                                        (int)'i',
                                        (const char *)"BT::aggr(): nullT for%n in anon union",
                                        (const struct ea *)(((&__0__V106)->__O1__2ea.p =
                                                                 ((const void *)__6nn)),
                                                            (&__0__V106)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                            } else {
                                Pname __8nx;

                                __8nx =
                                    __ct__4nameFPCc((struct name *)0, __6nn->__O2__4expr.string);
                                __8nx->__O1__4expr.tp = __6nn->__O1__4expr.tp;
                                __8nx->__O3__4expr.tpdef = __6nn->__O3__4expr.tpdef;
                                __8nx->where__4name = __6nn->where__4name;
                                if (__6nn->__O3__4expr.tpdef) {
                                    __8nx = insert_type__FP4nameP6ktableUc(__8nx, Ctbl,
                                                                           (unsigned char)97);
                                    check_redef__FP4nameT1(__8nx, __6nn);
                                } else {
                                    switch (__8nx->__O1__4expr.tp->base__4node) {
                                        const void *__2__X122;

                                    case 119: {
                                        Pclass __11mcl;

                                        __11mcl = (((struct classdef *)((
                                            (struct classdef *)(((struct basetype *)((
                                                                    (struct basetype *)
                                                                        __6nn->__O1__4expr.tp))))
                                                ->b_name__8basetype->__O1__4expr.tp))));
                                        if ((__11mcl->csu__8classdef != 167) &&
                                            (!((((__11mcl->string__8classdef[0]) == '_') &&
                                                ((__11mcl->string__8classdef[1]) == '_')) &&
                                               ((__11mcl->string__8classdef[2]) == 'C')))) {

                                            __8nx = insert_type__FP4nameP6ktableUc(
                                                __8nx, Ctbl, __11mcl->csu__8classdef);
                                            if (Nold) {
                                                Pname __13x;
                                                Pclass __13ocl;

                                                const void *__2__X120;

                                                __13x = is_cl_obj__4typeFv(__8nx->__O1__4expr.tp);
                                                __13ocl = (__13x ? (((struct classdef *)((
                                                                       (struct classdef *)
                                                                           __13x->__O1__4expr.tp))))
                                                                 : (((struct classdef *)0)));
                                                if (((__13ocl == 0) ||
                                                     strcmp(__13ocl->string__8classdef,
                                                            __11mcl->string__8classdef)) ||
                                                    ((__13ocl->defined__4type & 5) &&
                                                     (__11mcl->defined__4type & 5))) {
                                                    struct ea __0__V107;

                                                    error__FP3locPCcRC2eaN33(
                                                        &__6nn->where__4name,
                                                        (const char *)"twoDs of %s (one in "
                                                                      "anonymous union)",
                                                        (const struct ea
                                                             *)((__2__X120 =
                                                                     (const void *)
                                                                         __6nn->__O2__4expr.string),
                                                                (((&__0__V107)->__O1__2ea.p =
                                                                      __2__X120),
                                                                 (&__0__V107))),
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0);
                                                } else if (__11mcl->defined__4type & 5)
                                                    __8nx->__O1__4expr.tp = __6nn->__O1__4expr.tp;
                                            }
                                        }
                                    } break;
                                    case 121:
                                        if ((((__6nn->__O2__4expr.string[0]) == '_') &&
                                             ((__6nn->__O2__4expr.string[1]) == '_')) &&
                                            ((__6nn->__O2__4expr.string[2]) == 'E'))
                                            break;
                                        __8nx = insert_type__FP4nameP6ktableUc(__8nx, Ctbl,
                                                                               (unsigned char)13);
                                        if (Nold) {
                                            Ptype __11t;
                                            Penum __11oe;

                                            __11t = skiptypedefs__4typeFv(__8nx->__O1__4expr.tp);
                                            __11oe =
                                                ((__11t->base__4node == 121)
                                                     ? (((struct enumdef *)((
                                                           (struct enumdef
                                                                *)(((struct basetype *)((
                                                                       (struct basetype *)__11t))))
                                                               ->b_name__8basetype->__O1__4expr
                                                               .tp))))
                                                     : (((struct enumdef *)0)));
                                            __11t = skiptypedefs__4typeFv(__6nn->__O1__4expr.tp);
                                            {
                                                Penum __11ne;

                                                const void *__2__X121;

                                                __11ne = ((__11t->base__4node == 121)
                                                              ? (((struct enumdef *)((
                                                                    (struct enumdef
                                                                         *)(((struct basetype *)((
                                                                                (struct basetype *)
                                                                                    __11t))))
                                                                        ->b_name__8basetype
                                                                        ->__O1__4expr.tp))))
                                                              : (((struct enumdef *)0)));
                                                if (((__11oe == 0) ||
                                                     strcmp(__11oe->string__7enumdef,
                                                            __11ne->string__7enumdef)) ||
                                                    ((__11oe->defined__4type & 5) &&
                                                     (__11ne->defined__4type & 5))) {
                                                    struct ea __0__V108;

                                                    error__FP3locPCcRC2eaN33(
                                                        &__6nn->where__4name,
                                                        (const char *)"twoDs of %s (one in "
                                                                      "anonymous union)",
                                                        (const struct ea
                                                             *)((__2__X121 =
                                                                     (const void *)
                                                                         __6nn->__O2__4expr.string),
                                                                (((&__0__V108)->__O1__2ea.p =
                                                                      __2__X121),
                                                                 (&__0__V108))),
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0);
                                                } else if (__11ne->defined__4type & 5)
                                                    __8nx->__O1__4expr.tp = __6nn->__O1__4expr.tp;
                                            }
                                        }
                                        break;
                                    default: {
                                        struct ea __0__V109;

                                        error__FiP3locPCcRC2eaN34(
                                            (int)'i', &__6nn->where__4name,
                                            (const char *)"missing tpdef forTdefN %s",
                                            (const struct ea
                                                 *)((__2__X122 =
                                                         (const void *)__8nx->__O2__4expr.string),
                                                    (((&__0__V109)->__O1__2ea.p = __2__X122),
                                                     (&__0__V109))),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                    }
                                    }
                                }
                            }
                        }
                        return __6un;
                    }
                }
                if (__3cl->class_base__8classdef != 2) {
                    struct ea __0__V110;

                    error__FiPCcRC2eaN33(
                        (int)'w', (const char *)"unusable%k ignored",
                        (const struct ea *)((__2__X123 = __3cl->csu__8classdef),
                                            (((((&__0__V110)->__O1__2ea.i = __2__X123), 0)),
                                             (&__0__V110))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
            if (__0this->b_sto__8basetype == 18) {
                struct ea __0__V111;

                struct ea __0__V112;

                error__FPCcRC2eaN32(
                    (const char *)"friend%k%n{...} -- may only declare a friendC",
                    (const struct ea *)((__2__X124 = __3cl->csu__8classdef),
                                        (((((&__0__V111)->__O1__2ea.i = __2__X124), 0)),
                                         (&__0__V111))),
                    (const struct ea *)((__2__X125 = (const void *)__0this->b_name__8basetype),
                                        (((&__0__V112)->__O1__2ea.p = __2__X125), (&__0__V112))),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            __3cl->c_body__8classdef = 1;
            return __0this->b_name__8basetype;
        } else {
            if (__0this->b_sto__8basetype == 18)
                goto frr;
            {
                Pname __4nn;

                __4nn = __ct__4nameFPCc((struct name *)0, __3cl->string__8classdef);
                __4nn->__O1__4expr.tp = __0this->b_name__8basetype->__O1__4expr.tp;
                __4nn->n_key__4name = 44;
                return __4nn;
            }
        }
    }

    case 121: {
        Penum __3en;

        const void *__2__X126;

        const void *__2__X127;

        __3en =
            (((struct enumdef *)(((struct enumdef *)__0this->b_name__8basetype->__O1__4expr.tp))));
        if (__0this->b_name__8basetype->base__4node == 123) {
            struct ea __0__V113;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"TN%n in enumO",
                (const struct ea *)((__2__X126 = (const void *)__0this->b_name__8basetype),
                                    (((&__0__V113)->__O1__2ea.p = __2__X126), (&__0__V113))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__0this->b_const__4type) {
            struct ea __0__V114;

            error__FPCcRC2eaN32(
                (const char *)"const enum%n",
                (const struct ea *)((__2__X127 = (const void *)__0this->b_name__8basetype),
                                    (((&__0__V114)->__O1__2ea.p = __2__X127), (&__0__V114))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__3en->e_body__7enumdef == 2) {
            __3en->e_body__7enumdef = 1;
            return __0this->b_name__8basetype;
        } else {
            const void *__2__X128;

            {
                struct ea __0__V115;

                error__FPCcRC2eaN32(
                    (const char *)"forwardD of enum%n",
                    (const struct ea *)((__2__X128 = (const void *)__0this->b_name__8basetype),
                                        (((&__0__V115)->__O1__2ea.p = __2__X128), (&__0__V115))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                __3en->e_type__7enumdef = int_type;
            }
        }
        return (struct name *)0;
    }

    case 0: {
        Pname __3n;

        __3n = __ct__4nameFPCc((struct name *)0, (const char *)make_name__FUc((unsigned char)'D'));
        __3n->__O1__4expr.tp = (struct type *)defa_type;
        error__FPCc((const char *)"NX inDL");
        return __3n;
    }
    default:
        if (__0this->b_typedef__8basetype)
            error__FiPCc((int)'w', (const char *)"illegalTdef ignored");

        if ((__0this->b_sto__8basetype == 18) && __0this->b_name__8basetype) {
        frr: {
            Pname __3fr;

            const void *__2__X129;

            __3fr = k_find_name__FPCcP6ktableUc(__0this->b_name__8basetype->__O2__4expr.string,
                                                Ctbl, (unsigned char)0);
            if ((__3fr == 0) || (__3fr->base__4node != 123)) {
                struct ea __0__V116;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"cannot find friend%n",
                    (const struct ea *)((__2__X129 = (const void *)__0this->b_name__8basetype),
                                        (((&__0__V116)->__O1__2ea.p = __2__X129), (&__0__V116))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            {
                Pname __3n;

                __3n = __ct__4nameFPCc((struct name *)0,
                                       __0this->b_name__8basetype->__O2__4expr.string);
                __3n->n_sto__4name = 18;

                if ((__3fr->__O1__4expr.tp->base__4node == 119) &&
                    ((((struct classdef *)((
                          (struct classdef *)(((struct basetype *)((
                                                  (struct basetype *)__3fr->__O1__4expr.tp))))
                              ->b_name__8basetype->__O1__4expr.tp))))
                         ->class_base__8classdef == 2)) {
                    if (__0this->base__4node == 119)
                        __3n->__O1__4expr.tp = (struct type *)__0this;
                    else if (((__0this->base__4node == 97) &&
                              ((((struct basetype *)(((struct basetype *)__0this))))
                                   ->b_name__8basetype->base__4node == 123)) &&
                             ((((struct basetype *)(((struct basetype *)__0this))))
                                  ->b_name__8basetype->__O1__4expr.tp->base__4node == 119))
                        __3n->__O1__4expr.tp = (((struct basetype *)(((struct basetype *)__0this))))
                                                   ->b_name__8basetype->__O1__4expr.tp;
                    else
                        error__FiPCc((int)'i', (const char *)"basetype wasn't a COBJ");
                } else
                    __3n->__O1__4expr.tp = __3fr->__O1__4expr.tp;
                return __3n;
            }
        }
        } else {
            Pname __3n;

            __3n =
                __ct__4nameFPCc((struct name *)0, (const char *)make_name__FUc((unsigned char)'D'));
            __3n->__O1__4expr.tp = (struct type *)defa_type;
            error__FPCc((const char *)"NX inDL");
            return __3n;
        }
    }
}

int defer_check = 0;

Pclass classtype__4typeFv(struct type *__0this);

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

void hide__4nameFv(register struct name *__0this) {
    if (__0this->base__4node != 123)
        return;

    if (__0this->n_key__4name == 0) {
        if ((__0this->lex_level__4name == bl_level) && (in_arg_list == 0)) {
            if (__0this->__O1__4expr.tp->base__4node != 119) {
                if (((in_typedef && in_typedef->base__4node) &&
                     (__0this->__O1__4expr.tp->base__4node !=
                      type_set__FP8basetype(
                          ((struct basetype *)(((struct basetype *)in_typedef)))))) &&
                    check__4typeFP4typeUcT2(in_typedef, __0this->__O1__4expr.tp, (unsigned char)0,
                                            (unsigned char)0)) {
                    if (defer_check == 0) {
                        struct ea __0__V130;

                        struct ea __0__V131;

                        struct ea __0__V132;

                        error__FPCcRC2eaN32(
                            (const char *)"%n redefined: previous: %t now: %t",
                            (const struct ea *)(((&__0__V130)->__O1__2ea.p =
                                                     ((const void *)__0this)),
                                                (&__0__V130)),
                            (const struct ea *)__ct__2eaFPCv(&__0__V131,
                                                             (const void *)__0this->__O1__4expr.tp),
                            (const struct ea *)__ct__2eaFPCv(&__0__V132, (const void *)in_typedef),
                            (const struct ea *)ea0);
                    }
                }
            } else {
                if ((in_typedef && in_typedef->base__4node) &&
                    check__4typeFP4typeUcT2(in_typedef, __0this->__O1__4expr.tp, (unsigned char)0,
                                            (unsigned char)0)) {
                    if (defer_check == 0) {
                        struct ea __0__V133;

                        struct ea __0__V134;

                        struct ea __0__V135;

                        error__FPCcRC2eaN32(
                            (const char *)"%n redefined: previous: %t now: %t",
                            (const struct ea *)(((&__0__V133)->__O1__2ea.p =
                                                     ((const void *)__0this)),
                                                (&__0__V133)),
                            (const struct ea *)__ct__2eaFPCv(&__0__V134,
                                                             (const void *)__0this->__O1__4expr.tp),
                            (const struct ea *)__ct__2eaFPCv(&__0__V135, (const void *)in_typedef),
                            (const struct ea *)ea0);
                    }
                } else {
                    Pname __5nn;
                    Pclass __5cl;

                    struct classdef *__1__X141;

                    struct classdef *__1__X142;

                    __5nn = (((struct basetype *)(((struct basetype *)__0this->__O1__4expr.tp))))
                                ->b_name__8basetype;
                    __5cl = (((struct classdef *)(((struct classdef *)__5nn->__O1__4expr.tp))));

                    if (in_typedef)
                        while (in_typedef->base__4node == 97)
                            in_typedef = (((struct basetype *)(((struct basetype *)in_typedef))))
                                             ->b_name__8basetype->__O1__4expr.tp;
                    if ((in_typedef && (in_typedef->base__4node == 119)) &&
                        ((__1__X141 = (((struct classdef *)((
                              (struct classdef *)(((struct basetype *)((
                                                      (struct basetype *)in_typedef))))
                                  ->b_name__8basetype->__O1__4expr.tp))))),
                         ((__1__X142 = __5cl),
                          (((__1__X141 == __1__X142)
                                ? 1
                                : ((__1__X141 && __1__X142)
                                       ? (((int)same_class__8classdefFP8classdefi(__1__X141,
                                                                                  __1__X142, 0)))
                                       : 0))))))
                        in_typedef = __0this->__O1__4expr.tp;
                    else if ((__5cl->c_ctor__8classdef)) {
                        struct ea __0__V136;

                        struct ea __0__V137;

                        error__FPCcRC2eaN32(
                            (const char *)"%n redefined: both aCNWK and %s",
                            (const struct ea *)(((&__0__V136)->__O1__2ea.p =
                                                     ((const void *)__0this)),
                                                (&__0__V136)),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V137,
                                (const void *)(in_typedef ? "a type name"
                                                          : (((char *)"an identifier")))),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
            }
        }

        if (__0this->__O4__4expr.n_table == 0) {
            Pclass __3cl;

            __3cl = 0;
            if (__0this->__O1__4expr.tp->base__4node == 119)
                __3cl = classtype__4typeFv(__0this->__O1__4expr.tp);
            if ((__0this->n_template_arg__4name == 1) && in_progress__17templ_compilation) {
                struct ea __0__V138;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"reuse of formalYZ%n",
                    (const struct ea *)(((&__0__V138)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V138)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else if (__3cl && ((__3cl->class_base__8classdef == 4) ||
                                 (__3cl->class_base__8classdef == 5))) {
                struct ea __0__V139;

                error__FPCcRC2eaN32(
                    (const char *)"illegal use of instantiatedYC%t",
                    (const struct ea *)(((&__0__V139)->__O1__2ea.p = ((const void *)__3cl)),
                                        (&__0__V139)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else {
                struct ea __0__V140;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"%n->hide() -- no n_table",
                    (const struct ea *)(((&__0__V140)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V140)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }
        insert_name__FP4nameP6ktable(__ct__4nameFPCc((struct name *)0, __0this->__O2__4expr.string),
                                     Ctbl);
    }
}

int classid = 0;

Pname tname__4nameFUc(struct name *__0this, TOK);

void introduce_class_templ__17templ_compilationFP4name(struct templ_compilation *__0this,
                                                       Pname __1cnamep);

struct name_list *__ct__9name_listFP4nameP9name_list(struct name_list *__0this, Pname __1ff,
                                                     Plist __1ll);

Pname start_cl__FUcP4nameP6basecl(TOK __1t, Pname __1c, Pbcl __1b) {
    int __1mk_local;

    __1mk_local = 0;

    ;
    if (__1c == 0) {
        int __2save;

        __2save = stcount;

        stcount = (classid++);
        __1c = __ct__4nameFPCc((struct name *)0, (const char *)make_name__FUc((unsigned char)'C'));
        stcount = __2save;
        __1c->lex_level__4name -= (in_class_decl + 1);
        if (in_typedef && __1c->lex_level__4name)
            __1mk_local = 1;

    } else if ((ccl && (ccl->lex_level__4type == __1c->lex_level__4name)) &&
               (strcmp(ccl->string__8classdef, __1c->__O2__4expr.string) == 0)) {

        const void *__2__X155;

        {
            struct ea __0__V143;

            struct ea __0__V144;

            error__FPCcRC2eaN32(
                (const char *)"%k %s redefines enclosing class",
                (const struct ea *)(((((&__0__V143)->__O1__2ea.i = ((unsigned long)__1t)), 0)),
                                    (&__0__V143)),
                (const struct ea *)((__2__X155 = (const void *)__1c->__O2__4expr.string),
                                    (((&__0__V144)->__O1__2ea.p = __2__X155), (&__0__V144))),
                (const struct ea *)ea0, (const struct ea *)ea0);
            error__FiPCc((int)'i', (const char *)"can't recover from previous errors");
        }
    }
    {
        Pname __1n;

        __1n = tname__4nameFUc(__1c, __1t);
        __1n->where__4name = curloc;
        {
            Pbase __1bt;

            __1bt = (((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp))));
            if (__1bt->base__4node != 119) {
                {
                    struct ea __0__V145;

                    struct ea __0__V146;

                    error__FPCcRC2eaN32(
                        (const char *)"twoDs of%n:%t andC",
                        (const struct ea *)(((&__0__V145)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V145)),
                        (const struct ea *)(((&__0__V146)->__O1__2ea.p = ((const void *)__1bt)),
                                            (&__0__V146)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    error__FiPCc((int)'i', (const char *)"can't recover from previous errors");
                }
            } else {
                if (strcmp(__1n->__O2__4expr.string,
                           (((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp))))
                               ->b_name__8basetype->__O2__4expr.string) != 0) {
                    struct ea __0__V147;

                    error__FPCcRC2eaN32(
                        (const char *)"twoDs of %n:Tdef andC",
                        (const struct ea *)(((&__0__V147)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V147)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                if ((classtype__4typeFv(__1n->__O1__4expr.tp)->csu__8classdef != __1t) &&
                    ((__1t == 36) ||
                     (classtype__4typeFv(__1n->__O1__4expr.tp)->csu__8classdef == 36))) {
                    struct ea __0__V148;

                    struct ea __0__V149;

                    struct ea __0__V150;

                    error__FPCcRC2eaN32(
                        (const char *)"twoDs of%n:%k and%k",
                        (const struct ea *)(((&__0__V148)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V148)),
                        (const struct ea *)(((((&__0__V149)->__O1__2ea.i = ((unsigned long)__1t)),
                                              0)),
                                            (&__0__V149)),
                        (const struct ea *)__ct__2eaFUl(
                            &__0__V150, (unsigned long)classtype__4typeFv(__1n->__O1__4expr.tp)
                                            ->csu__8classdef),
                        (const struct ea *)ea0);
                }
                __1bt->b_name__8basetype->where__4name = curloc;
            }

            if ((in_progress__17templ_compilation && (__1c->lex_level__4name == 0)) &&
                (((ccl == 0) || ((!ccl->in_class__4type) && (ccl->class_base__8classdef != 2))) ||
                 (bl_level != ((ccl->lex_level__4type + in_class_decl) + 1))))
                introduce_class_templ__17templ_compilationFP4name(templp, __1n);

            if (in_progress__17templ_compilation && __1c->lex_level__4name) {
                if ((in_class_decl == 0) || in_mem_fct)
                    if (__1mk_local == 0) {
                        struct ea __0__V151;

                        error__FiPCcRC2eaN33(
                            (int)'s', (const char *)"localC%nWinYF",
                            (const struct ea *)(((&__0__V151)->__O1__2ea.p = ((const void *)__1c)),
                                                (&__0__V151)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else
                        error__FiPCc((int)'s', (const char *)"localCWinYF");
            }

            if (__1mk_local) {
                local_class =
                    __ct__9name_listFP4nameP9name_list((struct name_list *)0, __1n, local_class);
            }

            {
                Pclass __1occl;

                __1occl = ccl;
                ccl = (((struct classdef *)((
                    (struct classdef *)__1bt->b_name__8basetype->__O1__4expr.tp))));
                if (ccl->defined__4type)
                    ccl->defined__4type |= 020;
                ccl->defined__4type |= 04;

                ccl->string__8classdef = __1n->__O2__4expr.string;
                ccl->csu__8classdef = __1t;

                if (__1occl == 0) {
                    ccl->templ_base__4type =
                        (in_progress__17templ_compilation ? 3 : ccl->templ_base__4type);
                }

                if (__1b) {
                    Pbcl __2bx;

                    Pbcl __2bb;

                    Pbcl __2l;

                    __2bb = __1b;

                    __2l = 0;
                    for (; __2bb; __2bb = __2bx) {
                        __2bx = __2bb->next__6basecl;
                        __2bb->next__6basecl = 0;

                        if (__2bb->bclass__6basecl &&
                            (((__2bb->bclass__6basecl->nested_sig__4type &&
                               ccl->nested_sig__4type) &&
                              (strcmp((const char *)ccl->nested_sig__4type,
                                      (const char *)__2bb->bclass__6basecl->nested_sig__4type) ==
                               0)) ||
                             (((!__2bb->bclass__6basecl->nested_sig__4type) &&
                               (!ccl->nested_sig__4type)) &&
                              (strcmp(ccl->string__8classdef,
                                      __2bb->bclass__6basecl->string__8classdef) == 0)))) {
                            struct ea __0__V152;

                            error__FP3locPCcRC2eaN33(
                                &__1n->where__4name, (const char *)"%n derived from itself",
                                (const struct ea *)(((&__0__V152)->__O1__2ea.p =
                                                         ((const void *)__1n)),
                                                    (&__0__V152)),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        } else if (__2l == 0)
                            __2l = __2bb;
                        else {
                            {
                                {
                                    Pbcl __4ll;

                                    __4ll = __2l;

                                    for (;;) {
                                        struct classdef *__1__X156;

                                        struct classdef *__1__X157;

                                        if (__2bb->bclass__6basecl &&
                                            ((__1__X156 = __4ll->bclass__6basecl),
                                             ((__1__X157 = __2bb->bclass__6basecl),
                                              (((__1__X156 == __1__X157)
                                                    ? 1
                                                    : ((__1__X156 && __1__X157)
                                                           ? (((int)
                                                                   same_class__8classdefFP8classdefi(
                                                                       __1__X156, __1__X157, 0)))
                                                           : 0)))))) {
                                            const void *__2__X158;

                                            {
                                                struct ea __0__V153;

                                                struct ea __0__V154;

                                                error__FPCcRC2eaN32(
                                                    (const char *)"%s has %s asB twice",
                                                    (const struct ea
                                                         *)((__2__X158 = (const void *)ccl
                                                                             ->string__8classdef),
                                                            (((&__0__V153)->__O1__2ea.p =
                                                                  __2__X158),
                                                             (&__0__V153))),
                                                    (const struct ea *)__ct__2eaFPCv(
                                                        &__0__V154,
                                                        (const void *)__2bb->bclass__6basecl
                                                            ->string__8classdef),
                                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                                break;
                                            }
                                        }

                                        if (__4ll->next__6basecl)
                                            __4ll = __4ll->next__6basecl;
                                        else {
                                            __2bb->next__6basecl = __2l;
                                            __2l = __2bb;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }

                    ccl->baselist__8classdef = __2l;
                }
                return __1n;
            }
        }
    }
}

void end_cl__Fv(void) {
    const void *__2__X161;

    if (parameters_in_progress__17templ_compilation) {
        struct ea __0__V159;

        struct ea __0__V160;

        error__FPCcRC2eaN32(
            (const char *)"definition ofC %tWinY parameterL : %d",
            (const struct ea *)((__2__X161 = (const void *)ccl),
                                (((&__0__V159)->__O1__2ea.p = __2__X161), (&__0__V159))),
            (const struct ea *)(((((&__0__V160)->__O1__2ea.i = ((
                                       unsigned long)parameters_in_progress__17templ_compilation)),
                                  0)),
                                (&__0__V160)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    ccl->c_body__8classdef = 2;

    ccl->templ_base__4type = (in_progress__17templ_compilation
                                  ? 3
                                  : (ccl->in_class__4type ? ccl->in_class__4type->templ_base__4type
                                                          : ccl->templ_base__4type));
    ccl = ccl->in_class__4type;
}

extern Pname name_unlist__FP5nlist(struct nlist *);

Pbase end_enum__FP4nameP5nlist(Pname __1n, struct nlist *__1b) {
    bit __1anon;

    const void *__2__X166;

    __1anon = 0;
    if (__1n == 0) {
        __1anon = 1;
        __1n = __ct__4nameFPCc((struct name *)0, (const char *)make_name__FUc((unsigned char)'E'));
        __1n->lex_level__4name = (bl_level - in_class_decl);
    }

    if (parameters_in_progress__17templ_compilation) {
        struct ea __0__V162;

        error__FPCcRC2eaN32(
            (const char *)"definition of enum %sWinY parameterL",
            (const struct ea *)((__2__X166 = (const void *)(__1anon ? (((const char *)""))
                                                                    : __1n->__O2__4expr.string)),
                                (((&__0__V162)->__O1__2ea.p = __2__X166), (&__0__V162))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (in_progress__17templ_compilation && __1n->lex_level__4name) {
        if ((in_class_decl == 0) || in_mem_fct)
            if (__1anon == 0) {
                struct ea __0__V163;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"local enum%nWinYF",
                    (const struct ea *)(((&__0__V163)->__O1__2ea.p = ((const void *)__1n)),
                                        (&__0__V163)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else
                error__FiPCc((int)'s', (const char *)"local enumWinYF");
    }

    __1n = tname__4nameFUc(__1n, (unsigned char)13);
    {
        Pbase __1bt;

        __1bt = (((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp))));
        if (__1bt->base__4node != 121) {
            {
                struct ea __0__V164;

                struct ea __0__V165;

                error__FPCcRC2eaN32(
                    (const char *)"twoDs of%n:%t and enum",
                    (const struct ea *)(((&__0__V164)->__O1__2ea.p = ((const void *)__1n)),
                                        (&__0__V164)),
                    (const struct ea *)(((&__0__V165)->__O1__2ea.p = ((const void *)__1bt)),
                                        (&__0__V165)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                error__FiPCc((int)'i', (const char *)"can't recover from previous errors");
            }
        }
        __1bt->b_name__8basetype->where__4name = curloc;
        {
            Penum __1en;

            __1en = ((
                (struct enumdef *)(((struct enumdef *)__1bt->b_name__8basetype->__O1__4expr.tp))));
            __1en->e_body__7enumdef = 2;
            __1en->mem__7enumdef = name_unlist__FP5nlist(__1b);
            if (__1en->defined__4type) {
                __1en->defined__4type |= 020;
            }
            __1en->defined__4type |= 04;

            __1en->templ_base__4type =
                (in_progress__17templ_compilation
                     ? 3
                     : (__1en->in_class__4type ? __1en->in_class__4type->templ_base__4type
                                               : __1en->templ_base__4type));
            return __1bt;
        }
    }
}

extern char *make_nested_name__FPCcP8classdef(const char *, Pclass);

extern size_t strlen(const char *);

Pname tdef__4nameFv(register struct name *__0this) {
    Pname __1n;

    if (__0this->__O2__4name.n_qualifier) {
        {
            struct ea __0__V167;

            error__FPCcRC2eaN32(
                (const char *)"QdN in typedef",
                (const struct ea *)(((&__0__V167)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V167)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            __0this->__O2__4name.n_qualifier = 0;
        }
    }
    if (__0this->__O1__4expr.tp == 0) {
        struct ea __0__V168;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"Tdef%n tp==0",
            (const struct ea *)(((&__0__V168)->__O1__2ea.p = ((const void *)__0this)),
                                (&__0__V168)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    __0this->lex_level__4name = (bl_level - in_class_decl);

    if (ccl && (ccl->lex_level__4type == __0this->lex_level__4name)) {
        struct type *__0__X171;

        struct node *__0__X1;

        __0this->__O3__4expr.tpdef =
            ((__0__X171 = 0),
             (((__0__X171 || (__0__X171 = (struct type *)__nw__FUl((size_t)(sizeof(struct type)))))
                   ? (((((((((__0__X171 =
                                  (struct type *)((__0__X1 = (((struct node *)__0__X171))),
                                                  (((__0__X1 ||
                                                     (__0__X1 = (struct node *)__nw__FUl(
                                                          (size_t)(sizeof(struct node)))))
                                                        ? (((__0__X1->base__4node = 0),
                                                            (__0__X1->permanent__4node = 0)),
                                                           (__0__X1->baseclass__4node = 0))
                                                        : 0),
                                                   __0__X1))),
                             (__0__X171->defined__4type = 0)),
                            (__0__X171->lex_level__4type = 0)),
                           (__0__X171->templ_base__4type = 0)),
                          (__0__X171->in_class__4type = 0)),
                         (__0__X171->nested_sig__4type = 0)),
                        (__0__X171->local_sig__4type = 0)),
                       (__0__X171->b_const__4type = 0)),
                      (__0__X171->ansi_const__4type = 0))
                   : 0),
              __0__X171));
        __0this->__O3__4expr.tpdef->base__4node = 190;
        __0this->__O3__4expr.tpdef->permanent__4node = 1;
        __0this->__O3__4expr.tpdef->nested_sig__4type =
            make_nested_name__FPCcP8classdef(__0this->__O2__4expr.string, ccl);
        if (strcmp(ccl->string__8classdef, __0this->__O2__4expr.string) == 0) {
            {
                struct ea __0__V169;

                error__FP3locPCcRC2eaN33(
                    &__0this->where__4name,
                    (const char *)"nestedTdef%n redefines immediately enclosingC",
                    (const struct ea *)(((&__0__V169)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V169)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }
        __0this->__O3__4expr.tpdef->in_class__4type = ccl;
    } else
        __0this->__O3__4expr.tpdef = generic_tpdef;

    if (in_progress__17templ_compilation && __0this->lex_level__4name) {
        if ((in_class_decl == 0) || in_mem_fct) {
            struct ea __0__V170;

            error__FiPCcRC2eaN33(
                (int)'s', (const char *)"localTdef%nWinYF",
                (const struct ea *)(((&__0__V170)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V170)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
    }

    ;
    __1n = insert_type__FP4nameP6ktableUc(__0this, Ctbl, (unsigned char)97);
    if (__0this->__O3__4expr.tpdef->in_class__4type) {
        if ((__0this->__O1__4expr.tp != __1n->__O1__4expr.tp) ||
            (__0this->__O3__4expr.tpdef != __1n->__O3__4expr.tpdef))
            ;
        else {
            __1n->__O3__4expr.tpdef->templ_base__4type =
                (in_progress__17templ_compilation
                     ? 3
                     : __0this->__O3__4expr.tpdef->in_class__4type->templ_base__4type);
        }
    }

    if (check_redef__FP4nameT1(__1n, __0this))
        return __1n;
    __1n->base__4node = (__0this->base__4node = 123);
    __1n->permanent__4node = 1;
    __0this->__O1__4expr.tp->permanent__4node = 1;
    if (__0this->__O1__4expr.tp->base__4node == 125)
        (((struct ptr *)(((struct ptr *)__0this->__O1__4expr.tp))))->typ__5pvtyp->permanent__4node =
            1;

    if ((__0this->__O1__4expr.tp->base__4node == 119) ||
        (__0this->__O1__4expr.tp->base__4node == 121)) {
        Pname __2b;

        __2b = (((struct basetype *)(((struct basetype *)__0this->__O1__4expr.tp))))
                   ->b_name__8basetype;
        if (((__2b->__O2__4expr.string[0]) == '_') && ((__2b->__O2__4expr.string[1]) == '_'))
            switch (__0this->__O1__4expr.tp->base__4node) {
            case 119: {
                if ((__2b->__O2__4expr.string[2]) == 'C') {
                    Pclass __5cl;

                    __5cl = (((struct classdef *)(((struct classdef *)__2b->__O1__4expr.tp))));
                    __2b->__O2__4expr.string = __1n->__O2__4expr.string;
                    __5cl->string__8classdef = __1n->__O2__4expr.string;
                    if (!__5cl->local_sig__4type)
                        __5cl->c_strlen__8classdef = strlen(__5cl->string__8classdef);
                }
                break;
            }
            case 121: {
                if ((__2b->__O2__4expr.string[2]) == 'E') {
                    Penum __5en;

                    __5en = (((struct enumdef *)(((struct enumdef *)__2b->__O1__4expr.tp))));
                    __2b->__O2__4expr.string = __1n->__O2__4expr.string;
                    __5en->string__7enumdef = __1n->__O2__4expr.string;
                    if (!__5en->local_sig__4type)
                        __5en->e_strlen__7enumdef = strlen(__5en->string__7enumdef);
                }
            }
            }
    }

    ;
    return __1n;
}

static struct enumdef *__ct__7enumdefFP4name(register struct enumdef *__0this, Pname __2n) {
    struct type *__0__X2;

    struct node *__0__X1;

    if (__0this || (__0this = (struct enumdef *)__nw__FUl((size_t)(sizeof(struct enumdef))))) {
        __0this =
            (struct enumdef
                 *)((__0__X2 = (((struct type *)__0this))),
                    (((__0__X2 ||
                       (__0__X2 = (struct type *)__nw__FUl((size_t)(sizeof(struct type)))))
                          ? (((((((((__0__X2 =
                                         (struct type *)((__0__X1 = (((struct node *)__0__X2))),
                                                         (((__0__X1 ||
                                                            (__0__X1 = (struct node *)__nw__FUl(
                                                                 (size_t)(sizeof(struct node)))))
                                                               ? (((__0__X1->base__4node = 0),
                                                                   (__0__X1->permanent__4node = 0)),
                                                                  (__0__X1->baseclass__4node = 0))
                                                               : 0),
                                                          __0__X1))),
                                    (__0__X2->defined__4type = 0)),
                                   (__0__X2->lex_level__4type = 0)),
                                  (__0__X2->templ_base__4type = 0)),
                                 (__0__X2->in_class__4type = 0)),
                                (__0__X2->nested_sig__4type = 0)),
                               (__0__X2->local_sig__4type = 0)),
                              (__0__X2->b_const__4type = 0)),
                             (__0__X2->ansi_const__4type = 0))
                          : 0),
                     __0__X2));

        __0this->base__4node = 13;

        __0this->mem__7enumdef = __2n;
    }
    return __0this;
}

struct classdef *__ct__8classdefFUc(struct classdef *__0this, TOK);

extern char *make_local_name__FP4typeP4name(Ptype, Pname);

extern int fprintf(void *, const char *, ...);

Pname tname__4nameFUc(register struct name *__0this, TOK __1csu) {
    const char *__1s;
    bit __1nt;

    __1s = 0;
    __1nt = 0;
    switch (__0this->base__4node) {
        const void *__2__X177;

        unsigned long __2__X178;

    case 123:
        return __0this;
    case 85: {
        Pname __3tn;
        Pname __3on;

        __3tn = insert_type__FP4nameP6ktableUc(__0this, Ctbl, __1csu);
        __3on = __ct__4nameFPCc((struct name *)0, (const char *)0);
        __3tn->base__4node = 123;
        __3tn->lex_level__4name = __0this->lex_level__4name;

        __0this->__O1__4name.n_list = 0;
        __0this->__O2__4expr.string = __3tn->__O2__4expr.string;
        ((*__3on)) = (*__0this);
        switch (__1csu) {
        case 13:
            __3tn->__O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name(
                (struct basetype *)0, (unsigned char)121, __3on);

            __3on->__O1__4expr.tp =
                (struct type *)__ct__7enumdefFP4name((struct enumdef *)0, (struct name *)0);
            (((struct enumdef *)(((struct enumdef *)__3on->__O1__4expr.tp))))->string__7enumdef =
                __3tn->__O2__4expr.string;
            (((struct enumdef *)(((struct enumdef *)__3on->__O1__4expr.tp))))->lex_level__4type =
                __3tn->lex_level__4name;
            (((struct enumdef *)(((struct enumdef *)__3on->__O1__4expr.tp))))->in_class__4type =
                ccl;
            (((struct enumdef *)(((struct enumdef *)__3on->__O1__4expr.tp))))->e_strlen__7enumdef =
                strlen(__3tn->__O2__4expr.string);
            break;
        case 6:
        case 32:
        case 36:
            __3on->__O1__4expr.tp = (struct type *)__ct__8classdefFUc((struct classdef *)0, __1csu);
            __1s = ((((struct classdef *)(((struct classdef *)__3on->__O1__4expr.tp))))
                        ->string__8classdef = __3tn->__O2__4expr.string);
            (((struct classdef *)(((struct classdef *)__3on->__O1__4expr.tp))))->lex_level__4type =
                __0this->lex_level__4name;

            (((struct classdef *)(((struct classdef *)__3on->__O1__4expr.tp))))->k_tbl__8classdef =
                __ct__6ktableFiP6ktableP4name((struct ktable *)0, 0, (struct ktable *)0, __3tn);
            (((struct classdef *)(((struct classdef *)__3on->__O1__4expr.tp))))
                ->k_tbl__8classdef->k_id__6ktable = 6;
            (((struct classdef *)(((struct classdef *)__3on->__O1__4expr.tp))))->in_class__4type =
                ccl;
            __3tn->__O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name(
                (struct basetype *)0, (unsigned char)119, __3on);
            (((struct basetype *)(((struct basetype *)__3tn->__O1__4expr.tp))))
                ->b_table__8basetype =
                (((struct classdef *)(((struct classdef *)__3on->__O1__4expr.tp))))
                    ->memtbl__8classdef;
            (((struct classdef *)(((struct classdef *)__3on->__O1__4expr.tp))))
                ->c_strlen__8classdef = strlen(__3tn->__O2__4expr.string);
            break;
        default: {
            struct ea __0__V172;

            struct ea __0__V173;

            error__FiP3locPCcRC2eaN34(
                (int)'i', &__0this->where__4name,
                (const char *)"illegal csu%k for%n in name::tname()",
                (const struct ea *)(((((&__0__V172)->__O1__2ea.i = ((unsigned long)__1csu)), 0)),
                                    (&__0__V172)),
                (const struct ea *)(((&__0__V173)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V173)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        }
        if (ccl && (__0this->lex_level__4name == ccl->lex_level__4type)) {
            __3on->__O1__4expr.tp->nested_sig__4type =
                make_nested_name__FPCcP8classdef(__0this->__O2__4expr.string, ccl);
            if (__1s)
                ((__1s = (const char *)__3on->__O1__4expr.tp->nested_sig__4type), (__1nt = 1));
        } else if (__0this->lex_level__4name) {
            __3on->__O1__4expr.tp->local_sig__4type =
                make_local_name__FP4typeP4name(__3on->__O1__4expr.tp, Ctbl->k_name__6ktable);
            if (__1s)
                __1s = (const char *)__3on->__O1__4expr.tp->local_sig__4type;
        }
        __3tn->permanent__4node = 1;
        __3tn->__O1__4expr.tp->permanent__4node = 1;
        __3on->permanent__4node = 1;
        __3on->__O1__4expr.tp->permanent__4node = 1;

        if ((__1s && ansi_opt) && (!in_progress__17templ_compilation))
            fprintf(out_file, (const char *)"%s %s%s;\n",
                    ((__1csu == 36) || (__1csu == 167)) ? "union" : (((char *)"struct")),
                    __1nt ? "__" : (((char *)"")), __1s);
        return __3tn;
    }
    default: {
        struct ea __0__V174;

        struct ea __0__V175;

        struct ea __0__V176;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"tname(%s %d %k)",
            (const struct ea *)((__2__X177 = (const void *)__0this->__O2__4expr.string),
                                (((&__0__V174)->__O1__2ea.p = __2__X177), (&__0__V174))),
            (const struct ea *)(((&__0__V175)->__O1__2ea.p = ((const void *)__0this)),
                                (&__0__V175)),
            (const struct ea *)((__2__X178 = __0this->base__4node),
                                (((((&__0__V176)->__O1__2ea.i = __2__X178), 0)), (&__0__V176))),
            (const struct ea *)ea0);
        return (struct name *)0;
    }
    }
}

int co_hack = 0;

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

Ptype mkconst__4typeFv(struct type *__0this);

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

Ptype normalize__3ptrFP4type(struct ptr *__0this, Ptype);

Ptype normalize__3vecFP4type(struct vec *__0this, Ptype);

Ptype normalize__3fctFP4type(struct fct *__0this, Ptype);

Ptype skiptypedefs__4typeFRUc(struct type *__0this, bit *__1isconst);

extern void set_linkage__FPCc(const char *);

void del__4exprFv(struct expr *__0this);

Pname normalize__4nameFP8basetypeP5blockUc(register struct name *__0this, Pbase __1b, Pblock __1bl,
                                           bit __1Cast) {
    Pname __1n;
    Pname __1nn;
    TOK __1stc;
    bit __1tpdf;
    bit __1inli;
    bit __1virt;
    const char *__1lnkg;

    ;
    if (__1b) {
        __1stc = __1b->b_sto__8basetype;
        __1tpdf = __1b->b_typedef__8basetype;
        __1inli = __1b->b_inline__8basetype;
        __1virt = __1b->b_virtual__8basetype;
        __1lnkg = __1b->__O1__8basetype.b_linkage;
    } else {
        __1stc = 0;
        __1tpdf = 0;
        __1inli = 0;
        __1virt = 0;
        __1lnkg = 0;
    }

    if (__1inli && (__1stc == 14)) {
        error__FPCc((const char *)"both extern and inline");
        __1inli = 0;
    }

    if ((((__1stc == 31) && __0this->__O1__4expr.tp) &&
         (__0this->__O1__4expr.tp->base__4node == 108)) &&
        (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->f_const__3fct) {

        struct ea __0__V179;

        error__FPCcRC2eaN32(
            (const char *)"%n staticMF cannot be const",
            (const struct ea *)(((&__0__V179)->__O1__2ea.p = ((const void *)__0this)),
                                (&__0__V179)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__1stc == 18) {
        if (__0this->__O1__4expr.tp || (__1b && ((__1b->base__4node || __1b->b_name__8basetype) ||
                                                 __1b->b_xname__8basetype))) {

            if ((Ctbl->k_id__6ktable != 6) && (Ctbl->k_id__6ktable != 185)) {
                struct ea __0__V180;

                error__FPCcRC2eaN32(
                    (const char *)"friend%n not inC",
                    (const struct ea *)(((&__0__V180)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V180)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else if (__0this->__O2__4name.n_qualifier == 0) {
                __0this->lex_level__4name = 0;
                insert_name__FP4nameP6ktable(__0this, Gtbl);
            }
        } else {
            if (__0this->__O1__4name.n_list) {
                error__FPCc((const char *)"L of friends");

                __0this->__O1__4name.n_list = 0;
            }

            __0this->lex_level__4name = ccl->lex_level__4type;

            {
                Pname __3nx;

                __3nx = k_find_name__FPCcP6ktableUc(__0this->__O2__4expr.string,
                                                    Ctbl->k_next__6ktable, (unsigned char)0);
                if (__3nx && (__3nx->base__4node == 85)) {
                    {
                        struct ea __0__V181;

                        error__FP3locPCcRC2eaN33(
                            &__0this->where__4name,
                            (const char *)"illegal friendD:F signature required for nonTN%n",
                            (const struct ea *)(((&__0__V181)->__O1__2ea.p = ((const void *)__3nx)),
                                                (&__0__V181)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        __3nx = __3nx->__O1__4name.n_hidden;
                    }
                }
                if (__3nx == 0) {
                    Pktab __4otbl;
                    Pclass __4occl;

                    __4otbl = Ctbl;
                    __4occl = ccl;
                    if ((Ctbl->k_id__6ktable != 6) && (Ctbl->k_id__6ktable != 185)) {
                        struct ea __0__V182;

                        error__FPCcRC2eaN32((const char *)"friend%n not inC",
                                            (const struct ea *)(((&__0__V182)->__O1__2ea.p =
                                                                     ((const void *)__0this)),
                                                                (&__0__V182)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                    }
                    Ctbl = Gtbl;
                    __0this->lex_level__4name = 0;
                    ccl = 0;

                    __3nx = tname__4nameFUc(__0this, (unsigned char)6);
                    Ctbl = __4otbl;
                    ccl = __4occl;
                }
                if (__3nx->n_key__4name == 159) {
                    struct ea __0__V183;

                    error__FiPCcRC2eaN33(
                        (int)'w', (const char *)"friend%n referring to hiddenTN",
                        (const struct ea *)(((&__0__V183)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V183)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                __0this->n_sto__4name = 18;
                __0this->__O1__4expr.tp = __3nx->__O1__4expr.tp;
                return __0this;
            }
        }
    }
    if ((__0this->__O1__4expr.tp && (__0this->__O1__4expr.tp->base__4node == 108)) &&
        ((__0this->n_oper__4name == 123) ||
         (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->returns__3fct)) {
        Pfct __2f;
        Pfct __2f2;

        __2f = (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));
        __2f2 = (((struct fct *)(((struct fct *)__2f->returns__3fct))));

        if (__2f2) {
            Ptype __3pt;
            Ptype __3t;

            __3t = (struct type *)__2f2;
        lxlx:
            switch (__3t->base__4node) {
            case 158:
            case 125:
            case 110:
                if (__3pt = (((struct ptr *)(((struct ptr *)__3t))))->typ__5pvtyp) {
                    if (__3pt->base__4node == 97) {
                        (((struct ptr *)(((struct ptr *)__3t))))->typ__5pvtyp = 0;
                        __1b = (((struct basetype *)(((struct basetype *)__3pt))));
                    } else {
                        __3t = __3pt;
                        goto lxlx;
                    }
                }
                goto zse1;
            case 108: {
                Pexpr __5e;

                __5e = (struct expr *)(((struct fct *)(((struct fct *)__2f))))->argtype__3fct;
                if (__5e && (__5e->base__4node == 140)) {
                    if (__5e->__O3__4expr.e2 || (__5e->__O2__4expr.e1->base__4node != 111))
                        goto zse1;
                    {
                        Pexpr __6ee;
                        Ptype __6t;
                        Ptype __6tpx;

                        __6ee = __5e->__O2__4expr.e1;
                        __6t = 0;

                    ldld:
                        switch (__6ee->base__4node) {
                        case 111: {
                            Ptype __8tt;

                            __8tt =
                                (__6ee->__O3__4expr.e2
                                     ? (((struct type *)(((struct type *)__ct__3vecFP4typeP4expr(
                                           (struct vec *)0, (struct type *)0,
                                           __6ee->__O3__4expr.e2)))))
                                     : (((struct type *)(((struct type *)__ct__3ptrFUcP4type(
                                           (struct ptr *)0, (unsigned char)125,
                                           (struct type *)0))))));
                            if (__6t)
                                (((struct ptr *)(((struct ptr *)__6t))))->typ__5pvtyp = __8tt;
                            else
                                __6tpx = __8tt;
                            __6t = __8tt;
                            __6ee = __6ee->__O2__4expr.e1;
                            goto ldld;
                        }
                        case 85: {
                            Pname __8rn;

                            __8rn = (((struct name *)(((struct name *)__6ee))));
                            {
                                Pname __9btn;

                                __9btn = k_find_name__FPCcP6ktableUc(__0this->__O2__4expr.string,
                                                                     Ctbl, (unsigned char)0);
                                if (__9btn && (__9btn->base__4node == 85))
                                    __9btn = 0;
                                __1b = __ct__8basetypeFUcP4name((struct basetype *)0,
                                                                (unsigned char)97, __9btn);
                            }
                            __2f->returns__3fct = __6tpx;
                            __0this->n_oper__4name = 0;
                            __0this->__O2__4expr.string = __8rn->__O2__4expr.string;
                            __0this->base__4node = 85;
                        }
                        }
                    }
                }
            }
            }
        }
    }

zse1:
    if (__1b == 0) {
        const void *__2__X203;

        {
            struct ea __0__V184;

            error__FPCcRC2eaN32(
                (const char *)"BTX for %s",
                (const struct ea *)((__2__X203 = (const void *)__0this->__O2__4expr.string),
                                    (((&__0__V184)->__O1__2ea.p = __2__X203), (&__0__V184))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            __1b = (((struct basetype *)(((struct basetype *)defa_type))));
        }
    }

    if (__1Cast)
        __0this->__O2__4expr.string = (const char *)"";
    __1b = check__8basetypeFP4name(__1b, __0this);

    switch (__1b->base__4node) {
    case 119:
        __1nn = __1b->b_name__8basetype;
        if ((!__1Cast) && ((((struct classdef *)(((struct classdef *)__1nn->__O1__4expr.tp))))
                               ->c_body__8classdef == 2)) {
            if (__1stc == 18) {
                Pclass __4cl;

                unsigned long __2__X204;

                __4cl = (((struct classdef *)(((struct classdef *)__1nn->__O1__4expr.tp))));
                if (__4cl->csu__8classdef == 167)
                    error__FP3locPCcRC2eaN33(&__1nn->where__4name,
                                             (const char *)"friend anonymous union",
                                             (const struct ea *)ea0, (const struct ea *)ea0,
                                             (const struct ea *)ea0, (const struct ea *)ea0);
                else {
                    struct ea __0__V185;

                    struct ea __0__V186;

                    error__FP3locPCcRC2eaN33(
                        &__1nn->where__4name, (const char *)"%k%n defined in friendD",
                        (const struct ea *)((__2__X204 = __4cl->csu__8classdef),
                                            (((((&__0__V185)->__O1__2ea.i = __2__X204), 0)),
                                             (&__0__V185))),
                        (const struct ea *)(((&__0__V186)->__O1__2ea.p = ((const void *)__1nn)),
                                            (&__0__V186)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
            if ((__0this->__O1__4expr.tp && (__0this->__O1__4expr.tp->base__4node == 108)) &&
                (co_hack == 0)) {
                unsigned long __2__X205;

                {
                    struct ea __0__V187;

                    struct ea __0__V188;

                    struct ea __0__V189;

                    error__FP3locPCcRC2eaN33(
                        &__0this->where__4name,
                        (const char
                             *)"%k%n defined as returnT for%n (did you forget a ';' after '}' ?)",
                        (const struct ea *)((__2__X205 =
                                                 (((struct classdef *)((
                                                      (struct classdef *)__1nn->__O1__4expr.tp))))
                                                     ->csu__8classdef),
                                            (((((&__0__V187)->__O1__2ea.i = __2__X205), 0)),
                                             (&__0__V187))),
                        (const struct ea *)(((&__0__V188)->__O1__2ea.p = ((const void *)__1nn)),
                                            (&__0__V188)),
                        (const struct ea *)(((&__0__V189)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V189)),
                        (const struct ea *)ea0);
                    __1nn = __0this;
                    break;
                }
            }
            __1nn->__O1__4name.n_list = __0this;
            (((struct classdef *)(((struct classdef *)__1nn->__O1__4expr.tp))))->c_body__8classdef =
                1;
        } else
            __1nn = __0this;
        break;
    case 121:
        __1nn = __1b->b_name__8basetype;
        if ((((struct enumdef *)(((struct enumdef *)__1nn->__O1__4expr.tp))))->e_body__7enumdef ==
            2) {
            if (__0this->__O1__4expr.tp && (__0this->__O1__4expr.tp->base__4node == 108)) {

                {
                    struct ea __0__V190;

                    struct ea __0__V191;

                    error__FP3locPCcRC2eaN33(
                        &__0this->where__4name,
                        (const char *)"enum%n defined as returnT for%n (did you forget a ';'?)",
                        (const struct ea *)(((&__0__V190)->__O1__2ea.p = ((const void *)__1nn)),
                                            (&__0__V190)),
                        (const struct ea *)(((&__0__V191)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V191)),
                        (const struct ea *)ea0, (const struct ea *)ea0);

                    __1nn = __0this;
                    break;
                }
            }
            __1nn->__O1__4name.n_list = __0this;
            (((struct enumdef *)(((struct enumdef *)__1nn->__O1__4expr.tp))))->e_body__7enumdef = 1;
        } else {
            Penum __3en;

            __3en = (((struct enumdef *)(((struct enumdef *)__1nn->__O1__4expr.tp))));
            if (__3en->defined__4type == 0) {
                struct ea __0__V192;

                error__FPCcRC2eaN32(
                    (const char *)"forwardD of enum%n",
                    (const struct ea *)(((&__0__V192)->__O1__2ea.p = ((const void *)__1nn)),
                                        (&__0__V192)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            __3en->e_type__7enumdef = int_type;
            __1nn = __0this;
        }
        break;
    default:
        __1nn = __0this;
    }

    {
        Pname __1nx;
        Ptype __1btyp;

        if ((__1b->base__4node == 97) && __1b->b_const__4type)
            __1btyp = mkconst__4typeFv((struct type *)__1b);
        else
            __1btyp = (struct type *)__1b;

        for (__1n = __0this; __1n; __1n = __1nx) {
            Ptype __2t;

            __2t = __1n->__O1__4expr.tp;
            __1nx = __1n->__O1__4name.n_list;
            __1n->n_sto__4name = __1stc;

            if (__1n->base__4node == 123) {
                struct ea __0__V193;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"redefinition ofTN%n",
                    (const struct ea *)(((&__0__V193)->__O1__2ea.p = ((const void *)__1n)),
                                        (&__0__V193)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__2t == 0) {
                if (__1bl == 0) {
                    __1n->__O1__4expr.tp = (__2t = __1btyp);
                    goto skipp;
                } else {
                    if ((__1n->base__4node == 85) && __1n->n_oper__4name) {
                        struct ea __0__V194;

                        error__FP3locPCcRC2eaN33(
                            &__1n->where__4name, (const char *)"illegalD of%n",
                            (const struct ea *)(((&__0__V194)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V194)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else {
                        struct ea __0__V195;

                        error__FP3locPCcRC2eaN33(
                            &__1n->where__4name, (const char *)"body of nonF%n",
                            (const struct ea *)(((&__0__V195)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V195)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    __2t = (struct type *)__ct__3fctFP4typeP4nameUc(
                        (struct fct *)0, (struct type *)0, (struct name *)0, (unsigned char)0);
                }
            }

            switch (__2t->base__4node) {
            case 125:
            case 158:
                __1n->__O1__4expr.tp =
                    normalize__3ptrFP4type(((struct ptr *)(((struct ptr *)__2t))), __1btyp);
                break;
            case 110:
                __1n->__O1__4expr.tp =
                    normalize__3vecFP4type(((struct vec *)(((struct vec *)__2t))), __1btyp);
                break;
            case 108:
                __1n->__O1__4expr.tp =
                    normalize__3fctFP4type(((struct fct *)(((struct fct *)__2t))), __1btyp);
                break;
            case 114: {
                if (__1n->__O2__4expr.string == 0)
                    __1n->__O2__4expr.string = (const char *)make_name__FUc((unsigned char)'F');

                __1n->__O1__4expr.tp = __2t;

                {
                    bit __4cft;
                    Ptype __4tb;

                    __4cft = 0;
                    __4tb = skiptypedefs__4typeFRUc(__1btyp, (bit *)(&__4cft));

                    switch (__4tb->base__4node) {
                    case 5:
                    case 29:
                    case 22:
                    case 122:
                    case 121:
                    case 21:
                        (((struct basetype *)(((struct basetype *)__2t))))
                            ->__O1__8basetype.b_fieldtype =
                            (struct type *)((((struct basetype *)(((struct basetype *)__4tb))))
                                                    ->b_unsigned__8basetype
                                                ? uint_type
                                                : int_type);
                        (((struct basetype *)(((struct basetype *)__2t))))->b_unsigned__8basetype =
                            (((struct basetype *)(((struct basetype *)__4tb))))
                                ->b_unsigned__8basetype;
                        (((struct basetype *)(((struct basetype *)__2t))))->b_const__4type = __4cft;
                        break;
                    case 141:
                        if (in_progress__17templ_compilation)
                            (((struct basetype *)(((struct basetype *)__2t))))
                                ->__O1__8basetype.b_fieldtype = (struct type *)int_type;
                        break;
                    default:
                        error__FPCc((const char *)"non-int field");
                        __1n->__O1__4expr.tp = (struct type *)defa_type;
                    }
                    break;
                }
            }
            }
        skipp: {
            Pfct __2f;

            __2f = (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))));

            if (__2f->base__4node != 108) {
                if (__1bl) {
                    {
                        struct ea __0__V196;

                        error__FPCcRC2eaN32(
                            (const char *)"body for nonF%n",
                            (const struct ea *)(((&__0__V196)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V196)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        __1n->__O1__4expr.tp =
                            (struct type *)(__2f = __ct__3fctFP4typeP4nameUc(
                                                (struct fct *)0, (struct type *)defa_type,
                                                (struct name *)0, (unsigned char)0));
                        continue;
                    }
                }
                if (__1inli) {
                    struct ea __0__V197;

                    error__FPCcRC2eaN32(
                        (const char *)"inline nonF%n",
                        (const struct ea *)(((&__0__V197)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V197)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                if (__1virt) {
                    struct ea __0__V198;

                    error__FPCcRC2eaN32(
                        (const char *)"virtual nonF%n",
                        (const struct ea *)(((&__0__V198)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V198)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                if (__1tpdf) {
                    if (in_arg_list) {
                        error__FPCc((const char *)"Tdef inA list");

                        continue;
                    }

                    if (__1n->__O3__4expr.n_initializer) {
                        {
                            struct ea __0__V199;

                            error__FPCcRC2eaN32((const char *)"Ir forTdefN%n",
                                                (const struct ea *)(((&__0__V199)->__O1__2ea.p =
                                                                         ((const void *)__1n)),
                                                                    (&__0__V199)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                            __1n->__O3__4expr.n_initializer = 0;
                        }
                    }
                    tdef__4nameFv(__1n);
                }
                continue;
            }

            if (__1lnkg)
                set_linkage__FPCc(__1lnkg);
            __2f->f_linkage__3fct = linkage;
            if (__1lnkg)
                set_linkage__FPCc((const char *)0);

            {
                extern int inline_opt;
                if (inline_opt)
                    __2f->f_inline__3fct =
                        ((__1bl && strcmp(__1n->__O2__4expr.string, (const char *)"main")) ? 1 : 0);
                else
                    __2f->f_inline__3fct = __1inli;

                __2f->f_is_inline__3fct = __2f->f_inline__3fct;
                {
                    extern int vcounter;
                    __2f->f_virtual__3fct = (__1virt ? ((vcounter++), 22222) : 0);

                    if (__1tpdf) {
                        if (__2f->body__3fct = __1bl) {
                            {
                                struct ea __0__V200;

                                error__FPCcRC2eaN32((const char *)"Tdef%n { ... }",
                                                    (const struct ea *)(((&__0__V200)->__O1__2ea.p =
                                                                             ((const void *)__1n)),
                                                                        (&__0__V200)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                                __2f->body__3fct = (__1bl = 0);
                            }
                        }
                        if (__1n->__O2__4name.n_qualifier) {
                            __2f->memof__3fct = (((struct classdef *)((
                                (struct classdef *)(((struct basetype *)((
                                                        (struct basetype *)__1n->__O2__4name
                                                            .n_qualifier->__O1__4expr.tp))))
                                    ->b_name__8basetype->__O1__4expr.tp))));
                            __1n->__O2__4name.n_qualifier = 0;
                        }
                        tdef__4nameFv(__1n);

                        continue;
                    }

                    if (__2f->body__3fct = __1bl)
                        continue;

                    {
                        Pname __3cn;
                        Ptype __3template_formal_type;
                        bit __3clob;

                        __3cn = is_cl_obj__4typeFv(__2f->returns__3fct);

                        __3clob = (__3cn || cl_obj_vec);

                        if (__2f->argtype__3fct) {
                            Pname __4nn;

                            for (__4nn = __2f->argtype__3fct; __4nn;
                                 __4nn = __4nn->__O1__4name.n_list) {
                                if (__4nn->base__4node != 85) {
                                    if (!__3clob) {
                                        if ((__2f->returns__3fct->base__4node == 97) &&
                                            ((((struct basetype *)((
                                                  (struct basetype *)__2f->returns__3fct))))
                                                 ->b_name__8basetype->n_template_arg__4name == 1)) {
                                            __3template_formal_type = __2f->returns__3fct;

                                            goto is_obj;
                                        }

                                        goto zzz;
                                    }
                                    goto is_obj;
                                }
                                if (__4nn->__O1__4expr.tp)
                                    goto ok;
                            }
                            if (!__3clob) {
                                goto zzz;
                            }
                        is_obj:
                            __1n->__O1__4expr.tp = __2f->returns__3fct;
                            if (__2f->argtype__3fct->base__4node != 140)
                                __2f->f_args__3fct =
                                    (__2f->argtype__3fct = (((
                                         struct name *)(((struct name *)__ct__4exprFUcP4exprT2(
                                         (struct expr *)0, (unsigned char)140,
                                         ((struct expr *)(((struct expr *)__2f->argtype__3fct))),
                                         (struct expr *)0))))));
                            if (__1n->__O3__4expr.n_initializer) {
                                {
                                    struct ea __0__V201;

                                    error__FP3locPCcRC2eaN33(
                                        &__1n->where__4name, (const char *)"twoIrs for%n",
                                        (const struct ea *)(((&__0__V201)->__O1__2ea.p =
                                                                 ((const void *)__1n)),
                                                            (&__0__V201)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                    if ((((struct expr *)(((struct expr *)__2f->argtype__3fct)))) &&
                                        ((((struct expr *)(((struct expr *)__2f->argtype__3fct))))
                                             ->permanent__4node == 0))
                                        del__4exprFv((
                                            (struct expr *)(((struct expr *)__2f->argtype__3fct))));
                                    __2f->argtype__3fct = 0;
                                }
                            } else {
                                struct texpr *__0__X206;

                                struct type *__2__X207;

                                struct expr *__2__X208;

                                __1n->__O3__4expr.n_initializer =
                                    (struct expr
                                         *)((__0__X206 = 0),
                                            ((__2__X207 = (__3cn ? __3cn->__O1__4expr.tp
                                                                 : __3template_formal_type)),
                                             ((__2__X208 = (((struct expr *)((
                                                   (struct expr *)__2f->argtype__3fct))))),
                                              (((__0__X206 ||
                                                 (__0__X206 = (struct texpr *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct texpr)))))
                                                    ? ((__0__X206 =
                                                            (struct texpr *)__ct__4exprFUcP4exprT2(
                                                                ((struct expr *)__0__X206),
                                                                ((unsigned char)157), __2__X208,
                                                                (struct expr *)0)),
                                                       (__0__X206->__O4__4expr.tp2 = __2__X207))
                                                    : 0),
                                               __0__X206))));
                            }
                            goto ok;
                        zzz:
                            if (__2f->argtype__3fct) {
                                __1n->__O1__4expr.tp = __2f->returns__3fct;
                                if (__2f->argtype__3fct->base__4node == 140) {
                                    if (__2f->argtype__3fct->__O3__4expr.e2 == 0) {
                                        __2f->argtype__3fct = (((struct name *)((
                                            (struct name *)__2f->argtype__3fct->__O2__4expr.e1))));
                                    } else {
                                        error__FPCc((const char *)"more than oneA for basicTIr");
                                        {
                                            Pexpr __7e;

                                            __7e = (struct expr *)__2f->argtype__3fct;
                                            for (; __7e->__O3__4expr.e2->__O3__4expr.e2;
                                                 __7e = __7e->__O3__4expr.e2)
                                                __7e->base__4node = 71;
                                            __7e->base__4node = 71;
                                            __7e->__O3__4expr.e2 =
                                                __7e->__O3__4expr.e2->__O2__4expr.e1;
                                        }
                                    }
                                }
                                if (__1n->__O3__4expr.n_initializer) {
                                    {
                                        struct ea __0__V202;

                                        error__FP3locPCcRC2eaN33(
                                            &__1n->where__4name, (const char *)"twoIrs for%n",
                                            (const struct ea *)(((&__0__V202)->__O1__2ea.p =
                                                                     ((const void *)__1n)),
                                                                (&__0__V202)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                        if ((((struct expr *)((
                                                (struct expr *)__2f->argtype__3fct)))) &&
                                            ((((struct expr *)((
                                                  (struct expr *)__2f->argtype__3fct))))
                                                 ->permanent__4node == 0))
                                            del__4exprFv(((struct expr *)((
                                                (struct expr *)__2f->argtype__3fct))));
                                        __2f->argtype__3fct = 0;
                                    }
                                } else {
                                    __1n->__O3__4expr.n_initializer =
                                        (((struct expr *)(((struct expr *)__2f->argtype__3fct))));
                                }
                                goto ok;
                            }
                        } else {
                        }
                    ok:;
                    }
                }
            }
        }
        }
        return __1nn;
    }
}

Ptype normalize__3vecFP4type(register struct vec *__0this, Ptype __1vecof) {
    Ptype __1t;

    __1t = __0this->typ__5pvtyp;
    __0this->typ__5pvtyp = __1vecof;

    while (__1vecof->base__4node == 97)
        __1vecof = (((struct basetype *)(((struct basetype *)__1vecof))))
                       ->b_name__8basetype->__O1__4expr.tp;

    switch (__1vecof->base__4node) {
    case 158:
        error__FPCc((const char *)"array ofRs");
        break;
    case 108:
        error__FPCc((const char *)"array ofFs");
        break;
    case 38:
        error__FPCc((const char *)"array of void");
        break;
    default:
        break;
    }

    if (__1t == 0)
        return (struct type *)__0this;

    switch (__1t->base__4node) {
        unsigned long __2__X210;

    case 125:
    case 158:
        return normalize__3ptrFP4type(((struct ptr *)(((struct ptr *)__1t))),
                                      (struct type *)__0this);
    case 110:
        return normalize__3vecFP4type(((struct vec *)(((struct vec *)__1t))),
                                      (struct type *)__0this);
    case 108:
        return normalize__3fctFP4type(((struct fct *)(((struct fct *)__1t))),
                                      (struct type *)__0this);
    default: {
        struct ea __0__V209;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"bad arrayT(%d)",
            (const struct ea *)((__2__X210 = __1t->base__4node),
                                (((((&__0__V209)->__O1__2ea.i = __2__X210), 0)), (&__0__V209))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

        return (struct type *)0;
    }
    }
}

Ptype normalize__3ptrFP4type(register struct ptr *__0this, Ptype __1ptrto) {
    Ptype __1t;

    __1t = __0this->typ__5pvtyp;
    __0this->typ__5pvtyp = __1ptrto;

    {
        int __1bc;

        __1bc = 0;
        while (__1ptrto->base__4node == 97) {
            __1bc += (((struct basetype *)(((struct basetype *)__1ptrto))))->b_const__4type;
            __1ptrto = (((struct basetype *)(((struct basetype *)__1ptrto))))
                           ->b_name__8basetype->__O1__4expr.tp;
        }

        switch (__1ptrto->base__4node) {
        case 108:
            if (__0this->memof__3ptr)
                if ((((struct fct *)(((struct fct *)__1ptrto))))->memof__3fct) {
                    struct classdef *__1__X214;

                    struct classdef *__1__X215;

                    const void *__2__X216;

                    if (!((__1__X214 = __0this->memof__3ptr),
                          ((__1__X215 = (((struct fct *)(((struct fct *)__1ptrto))))->memof__3fct),
                           (((__1__X214 == __1__X215)
                                 ? 1
                                 : ((__1__X214 && __1__X215)
                                        ? (((int)same_class__8classdefFP8classdefi(__1__X214,
                                                                                   __1__X215, 0)))
                                        : 0)))))) {
                        struct ea __0__V211;

                        struct ea __0__V212;

                        error__FPCcRC2eaN32(
                            (const char *)"P toMF mismatch: %s and %s",
                            (const struct ea *)((__2__X216 = (const void *)__0this->memof__3ptr
                                                                 ->string__8classdef),
                                                (((&__0__V211)->__O1__2ea.p = __2__X216),
                                                 (&__0__V211))),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V212,
                                (const void *)(((struct fct *)(((struct fct *)__1ptrto))))
                                    ->memof__3fct->string__8classdef),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                } else
                    (((struct fct *)(((struct fct *)__1ptrto))))->memof__3fct =
                        __0this->memof__3ptr;
            else
                __0this->memof__3ptr = (((struct fct *)(((struct fct *)__1ptrto))))->memof__3fct;
            break;
        case 158:
            switch (__0this->base__4node) {
            case 125:
                error__FPCc((const char *)"P toR");
                break;
            case 158:
                error__FPCc((const char *)"R toR");

                break;
            }
            break;
        case 38:
            if (__0this->base__4node == 158)
                error__FPCc((const char *)"R to void");
            break;
        }

        if (__1t == 0) {
            Pbase __2b;

            __2b = (((struct basetype *)(((struct basetype *)__1ptrto))));
            if (((((((Pfctvec_type && (__0this->b_const__4type == 0)) &&
                     (__2b->b_unsigned__8basetype == 0)) &&
                    (__2b->b_const__4type == 0)) &&
                   (__1bc == 0)) &&
                  (__0this->memof__3ptr == 0)) &&
                 (__0this->ptname__3ptr == 0)) &&
                (__0this->base__4node == 125)) {
                switch (__2b->base__4node) {
                case 21:
                    ((__0this
                          ? (((void)(__0this
                                         ? (((void)(((void)__dl__3ptrSFPvUl(
                                               (void *)__0this, (size_t)(sizeof(struct ptr)))))))
                                         : (((void)0)))))
                          : (((void)0))));

                    return Pint_type;
                case 5:
                    ((__0this
                          ? (((void)(__0this
                                         ? (((void)(((void)__dl__3ptrSFPvUl(
                                               (void *)__0this, (size_t)(sizeof(struct ptr)))))))
                                         : (((void)0)))))
                          : (((void)0))));

                    return Pchar_type;
                case 38:
                    ((__0this
                          ? (((void)(__0this
                                         ? (((void)(((void)__dl__3ptrSFPvUl(
                                               (void *)__0this, (size_t)(sizeof(struct ptr)))))))
                                         : (((void)0)))))
                          : (((void)0))));

                    return Pvoid_type;
                }
            }
            return (struct type *)__0this;
        }

        switch (__1t->base__4node) {
            unsigned long __2__X217;

        case 125:
        case 158:
            return normalize__3ptrFP4type(((struct ptr *)(((struct ptr *)__1t))),
                                          (struct type *)__0this);
        case 110:
            return normalize__3vecFP4type(((struct vec *)(((struct vec *)__1t))),
                                          (struct type *)__0this);
        case 108:
            return normalize__3fctFP4type(((struct fct *)(((struct fct *)__1t))),
                                          (struct type *)__0this);
        default: {
            struct ea __0__V213;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"badPT(%k)",
                (const struct ea *)((__2__X217 = __1t->base__4node),
                                    (((((&__0__V213)->__O1__2ea.i = __2__X217), 0)), (&__0__V213))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

            return (struct type *)0;
        }
        }
    }
}

Ptype normalize__3fctFP4type(register struct fct *__0this, Ptype __1ret) {
    Ptype __1t;

    __1t = __0this->returns__3fct;
    __0this->returns__3fct = __1ret;

    if ((__0this->argtype__3fct && (__0this->argtype__3fct->base__4node == 85)) &&
        __0this->argtype__3fct->__O2__4name.n_qualifier) {
        error__FPCc((const char *)"syntax: ANX");
        __0this->argtype__3fct = 0;
        __0this->nargs__3fct = 0;
        __0this->nargs_known__3fct = 0;
    }

    while (__1ret->base__4node == 97)
        __1ret =
            (((struct basetype *)(((struct basetype *)__1ret))))->b_name__8basetype->__O1__4expr.tp;

    switch (__1ret->base__4node) {
    case 110:
        error__FPCc((const char *)"F returning array");
        break;
    case 108:
        error__FPCc((const char *)"F returningF");

        __0this->returns__3fct = (__1ret = (struct type *)any_type);
        break;
    default:
        break;
    }

    if (__1t == 0)
        return (struct type *)__0this;

    switch (__1t->base__4node) {
        unsigned long __2__X219;

    case 125:
    case 158:
        return normalize__3ptrFP4type(((struct ptr *)(((struct ptr *)__1t))),
                                      (struct type *)__0this);
    case 110:
        return normalize__3vecFP4type(((struct vec *)(((struct vec *)__1t))),
                                      (struct type *)__0this);
    case 108:
        return normalize__3fctFP4type(((struct fct *)(((struct fct *)__1t))),
                                      (struct type *)__0this);
    default: {
        struct ea __0__V218;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"badFT:%k",
            (const struct ea *)((__2__X219 = __1t->base__4node),
                                (((((&__0__V218)->__O1__2ea.i = __2__X219), 0)), (&__0__V218))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

        return (struct type *)0;
    }
    }
}

void argdcl__3fctFP4nameT1(register struct fct *__0this, Pname __1dcl, Pname __1fn) {
    Pname __1n;

    switch (__0this->base__4node) {
        unsigned long __2__X227;

    case 108:
        break;
    case 141:
        return;
    default: {
        struct ea __0__V220;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"fct::argdcl(%d)",
            (const struct ea *)((__2__X227 = __0this->base__4node),
                                (((((&__0__V220)->__O1__2ea.i = __2__X227), 0)), (&__0__V220))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }

    if (__0this->argtype__3fct) {
        switch (__0this->argtype__3fct->base__4node) {
            unsigned long __2__X228;

        case 85:
            if (__1dcl)
                error__FPCc((const char *)"badF definition syntax");
            for (__1n = __0this->argtype__3fct; __1n; __1n = __1n->__O1__4name.n_list) {
                if (__1n->__O2__4expr.string == 0)
                    __1n->__O2__4expr.string = (const char *)make_name__FUc((unsigned char)'A');
            }
            return;
        case 140: {
            Pname __4tail;

            __4tail = 0;
            __1n = 0;

            {
                struct ea __0__V221;

                error__FiP3locPCcRC2eaN34(
                    strict_opt ? 0 : 119, &__1fn->where__4name,
                    (const char *)"old style definition of%n (anachronism)",
                    (const struct ea *)(((&__0__V221)->__O1__2ea.p = ((const void *)__1fn)),
                                        (&__0__V221)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

                {
                    {
                        Pexpr __4e;

                        __4e = (((struct expr *)(((struct expr *)__0this->argtype__3fct))));

                        for (; __4e; __4e = __4e->__O3__4expr.e2) {
                            Pexpr __5id;

                            __5id = __4e->__O2__4expr.e1;
                            if (__5id->base__4node != 85) {
                                error__FPCc((const char *)"NX inAL");
                                __0this->argtype__3fct = 0;
                                __1dcl = 0;
                                break;
                            }
                            {
                                Pname __5nn;

                                __5nn =
                                    __ct__4nameFPCc((struct name *)0, __5id->__O2__4expr.string);
                                if (__1n)
                                    __4tail = (__4tail->__O1__4name.n_list = __5nn);
                                else
                                    __4tail = (__1n = __5nn);
                            }
                        }
                        __0this->f_args__3fct = (__0this->argtype__3fct = __1n);
                        break;
                    }
                }
            }
        }
        default: {
            struct ea __0__V222;

            error__FPCcRC2eaN32(
                (const char *)"ALX(%d)",
                (const struct ea *)((__2__X228 = __0this->argtype__3fct->base__4node),
                                    (((((&__0__V222)->__O1__2ea.i = __2__X228), 0)), (&__0__V222))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            __0this->argtype__3fct = 0;
            __1dcl = 0;
        }
        }
    } else if (__0this->nargs_known__3fct == 155) {
        return;
    } else {
        __0this->nargs_known__3fct = 1;
        __0this->nargs__3fct = 0;
        if (__1dcl)
            error__FPCc((const char *)"ADL forFWoutAs");
        return;
    }

    if (__1dcl) {
        Pname __2d;
        Pname __2dx;

        for (__1n = __0this->argtype__3fct; __1n; __1n = __1n->__O1__4name.n_list) {
            const char *__3s;

            const void *__2__X229;

            const void *__2__X230;

            __3s = __1n->__O2__4expr.string;
            if (__3s == 0) {
                error__FPCc((const char *)"AN missing inF definition");
                __1n->__O2__4expr.string =
                    (__3s = (const char *)make_name__FUc((unsigned char)'A'));
            } else if (__1n->__O1__4expr.tp) {
                struct ea __0__V223;

                error__FPCcRC2eaN32(
                    (const char *)"twoTs forA %s",
                    (const struct ea *)((__2__X229 = (const void *)__1n->__O2__4expr.string),
                                        (((&__0__V223)->__O1__2ea.p = __2__X229), (&__0__V223))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            for (__2d = __1dcl; __2d; __2d = __2d->__O1__4name.n_list) {
                if (strcmp(__3s, __2d->__O2__4expr.string) == 0) {
                    if (__2d->__O1__4expr.tp && (__2d->__O1__4expr.tp->base__4node == 38)) {
                        {
                            struct ea __0__V224;

                            error__FPCcRC2eaN32((const char *)"voidA%n",
                                                (const struct ea *)(((&__0__V224)->__O1__2ea.p =
                                                                         ((const void *)__2d)),
                                                                    (&__0__V224)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                            __2d->__O1__4expr.tp = (struct type *)any_type;
                        }
                    }
                    __1n->__O1__4expr.tp = __2d->__O1__4expr.tp;
                    __1n->n_sto__4name = __2d->n_sto__4name;
                    __2d->__O1__4expr.tp = 0;
                    goto xx;
                }
            }
            __1n->__O1__4expr.tp = (struct type *)defa_type;
        xx:;
            if (__1n->__O1__4expr.tp == 0) {
                struct ea __0__V225;

                error__FPCcRC2eaN32(
                    (const char *)"noT for %s",
                    (const struct ea *)((__2__X230 = (const void *)__1n->__O2__4expr.string),
                                        (((&__0__V225)->__O1__2ea.p = __2__X230), (&__0__V225))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }

        for (__2d = __1dcl; __2d; __2d = __2dx) {
            __2dx = __2d->__O1__4name.n_list;
            if (__2d->__O1__4expr.tp) {
                switch (__2d->__O1__4expr.tp->base__4node) {
                case 6:
                case 13:
                    __2d->__O1__4name.n_list = __0this->argtype__3fct;
                    __0this->f_args__3fct = (__0this->argtype__3fct = __2d);
                    break;
                default: {
                    struct ea __0__V226;

                    error__FPCcRC2eaN32(
                        (const char *)"%n inADL not inAL",
                        (const struct ea *)(((&__0__V226)->__O1__2ea.p = ((const void *)__2d)),
                                            (&__0__V226)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                }
            }
        }
    }

    for (__1n = __0this->argtype__3fct; __1n; __1n = __1n->__O1__4name.n_list) {
        if (__1n->__O1__4expr.tp == 0)
            __1n->__O1__4expr.tp = (struct type *)defa_type;

        __0this->nargs__3fct++;
    }
}

Pname cl_obj_vec = 0;
Pname eobj = 0;

Pname is_cl_obj__4typeFv(register struct type *__0this) {
    bit __1v;
    Ptype __1t;

    __1v = 0;
    __1t = __0this;

    if (__1t == 0)
        return (struct name *)0;
    eobj = 0;
    cl_obj_vec = 0;
xx:
    switch (__1t->base__4node) {
    case 97:
        __1t =
            (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp;
        goto xx;

    case 119:
        if (__1v) {
            cl_obj_vec = (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype;
            return (struct name *)0;
        } else
            return (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype;

    case 110:
        __1t = (((struct vec *)(((struct vec *)__1t))))->typ__5pvtyp;
        __1v = 1;
        goto xx;

    case 121:
        eobj = (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype;
    default:
        return (struct name *)0;
    }
}

static int k_has_base__FP8classdefT1RUc(Pclass __1c1, Pclass __1c2, TOK *__1t);

static int k_has_base__FP8classdefT1RUc(Pclass __1c1, Pclass __1c2, TOK *__1t) {
    if ((__1c1 == 0) || (__1c2 == 0)) {
        struct ea __0__V231;

        struct ea __0__V232;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"k_has_base(%d,%d,...)",
            (const struct ea *)(((&__0__V231)->__O1__2ea.p = ((const void *)__1c1)), (&__0__V231)),
            (const struct ea *)(((&__0__V232)->__O1__2ea.p = ((const void *)__1c2)), (&__0__V232)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    {
        {
            Pbcl __1b;

            __1b = __1c1->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                TOK __2v;

                struct classdef *__1__X233;

                struct classdef *__1__X234;

                ((*__1t)) = __1b->base__4node;
                if (((__1__X233 = __1b->bclass__6basecl),
                     ((__1__X234 = __1c2),
                      (((__1__X233 == __1__X234)
                            ? 1
                            : ((__1__X233 && __1__X234) ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X233, __1__X234, 0)))
                                                        : 0))))))
                    return 1;
                if (k_has_base__FP8classdefT1RUc(__1b->bclass__6basecl, __1c2, (TOK *)(&__2v))) {
                    if (__2v == 77)
                        ((*__1t)) = 77;
                    return 1;
                }
            }
            ((*__1t)) = 0;
            return 0;
        }
    }
}

Pname find_cn__6ktableFPCc(struct ktable *__0this, const char *);

Pname look__6ktableFPCcUc(struct ktable *__0this, const char *, TOK);

static Pname k_find_in_base__FPCcP8classdefRP8classdefUc(const char *__1s, Pclass __1cl,
                                                         Pclass *__1acl, TOK __1k);

static Pname k_find_in_base__FPCcP8classdefRP8classdefUc(const char *__1s, Pclass __1cl,
                                                         Pclass *__1acl, TOK __1k) {
    ;

    {
        Pname __1n;
        Pname __1n2;
        Pclass __1ncl;

        Pclass __1n2cl;

        __1n = 0;
        __1n2 = 0;
        __1ncl = 0;

        __1n2cl = 0;
        {
            {
                Pbcl __1b;

                __1b = __1cl->baselist__8classdef;

                for (; __1b; __1b = __1b->next__6basecl) {
                    if (strcmp(__1s, __1b->bclass__6basecl->string__8classdef) == 0) {
                        __1n = find_cn__6ktableFPCc(__1b->bclass__6basecl->k_tbl__8classdef, __1s);
                        __1ncl = __1b->bclass__6basecl;
                    } else if ((__1n = look__6ktableFPCcUc(__1b->bclass__6basecl->k_tbl__8classdef,
                                                           __1s, (unsigned char)0)) != 0)
                        __1ncl = __1b->bclass__6basecl;
                    else
                        __1n = k_find_in_base__FPCcP8classdefRP8classdefUc(
                            __1s, __1b->bclass__6basecl, (Pclass *)(&__1ncl), __1k);
                    if (__1n == 0)
                        continue;
                    if (__1n2) {
                        TOK __3t;

                        struct classdef *__1__X235;

                        struct classdef *__1__X236;

                        if (!((__1__X235 = __1ncl),
                              ((__1__X236 = __1n2cl),
                               (((__1__X235 == __1__X236)
                                     ? 1
                                     : ((__1__X235 && __1__X236)
                                            ? (((int)same_class__8classdefFP8classdefi(
                                                  __1__X235, __1__X236, 0)))
                                            : 0)))))) {
                            if (k_has_base__FP8classdefT1RUc(__1n2cl, __1ncl, (TOK *)(&__3t))) {
                                __1n = __1n2;
                                __1ncl = __1n2cl;
                            }
                        }
                    }
                    __1n2 = __1n;
                    __1n2cl = __1ncl;
                }
                if (__1n) {
                    ((*__1acl)) = __1ncl;
                    return __1n;
                }
                ((*__1acl)) = __1n2cl;
                return __1n2;
            }
        }
    }
}

Pname k_find_name__FPCcP6ktableUc(const char *__1s, Pktab __1tbl, TOK __1k) {
recurse:;
    if (__1tbl == 0)
        return (struct name *)0;
    {
        Pname __1n;
        if (__1tbl->k_id__6ktable == 6) {
            if (__1tbl->k_name__6ktable == 0)
                error__FiPCc((int)'i', (const char *)"C table with noN");
            if (strcmp(__1s, __1tbl->k_name__6ktable->__O2__4expr.string) == 0)
                __1n = find_cn__6ktableFPCc(__1tbl, __1s);
            else {
                Pclass __3cl;

                __3cl = classtype__4typeFv(__1tbl->k_name__6ktable->__O1__4expr.tp);
                __1n = look__6ktableFPCcUc(__3cl->k_tbl__8classdef, __1s, (unsigned char)0);
            }
        } else
            __1n = look__6ktableFPCcUc(__1tbl, __1s, (unsigned char)0);
        if ((__1n && (__1k == 159)) && (__1n->base__4node != 123))
            __1n = __1n->__O1__4name.n_hidden;

        ;
        if (__1n)
            return __1n;

        while (__1tbl && (__1tbl->k_id__6ktable == 116))
            __1tbl = __1tbl->k_next__6ktable;
        if (__1tbl == Gtbl)
            return (struct name *)0;
        if (__1tbl->k_id__6ktable == 6) {
            if (__1tbl->k_name__6ktable == 0)
                error__FiPCc((int)'i', (const char *)"C table with noN");
            {
                Pclass __2cl;

                Pclass __2acl;

                __2cl = classtype__4typeFv(__1tbl->k_name__6ktable->__O1__4expr.tp);
                __1n = k_find_in_base__FPCcP8classdefRP8classdefUc(__1s, __2cl, (Pclass *)(&__2acl),
                                                                   __1k);
            }
        } else
            __1n = look__6ktableFPCcUc(__1tbl, __1s, (unsigned char)0);
        if ((__1n && (__1k == 159)) && (__1n->base__4node != 123))
            __1n = __1n->__O1__4name.n_hidden;
        if (__1n)
            return __1n;

        __1tbl = __1tbl->k_next__6ktable;
        goto recurse;
    }
}

Pname k_find_member__FPCcP8classdefUc(const char *__1s, Pclass __1cl, TOK __1k) {
    ;
    {
        Pktab __1tbl;
        Pname __1n;

        Pclass __1acl;

        __1tbl = __1cl->k_tbl__8classdef;

        if (__1tbl->k_id__6ktable != 6) {
            struct ea __0__V237;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"C tableX for%t!",
                (const struct ea *)(((&__0__V237)->__O1__2ea.p = ((const void *)__1cl)),
                                    (&__0__V237)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (strcmp(__1s, __1cl->string__8classdef) == 0)
            __1n = find_cn__6ktableFPCc(__1tbl, __1s);
        else
            __1n = look__6ktableFPCcUc(__1tbl, __1s, (unsigned char)0);
        if ((__1n && (__1k == 159)) && (__1n->base__4node != 123))
            __1n = __1n->__O1__4name.n_hidden;

        ;
        if (__1n)
            return __1n;

        ;
        __1n = k_find_in_base__FPCcP8classdefRP8classdefUc(__1s, __1cl, (Pclass *)(&__1acl), __1k);
        if ((__1n && (__1k == 159)) && (__1n->base__4node != 123))
            __1n = __1n->__O1__4name.n_hidden;

        ;
        return __1n;
    }
}

Pname insert__6ktableFP4nameUc(struct ktable *__0this, Pname, TOK);

Pname insert_name__FP4nameP6ktable(Pname __1nn, Pktab __1tbl) {
    ;
    {
        Pname __1nx;

        __1nx = k_find_name__FPCcP6ktableUc(__1nn->__O2__4expr.string, __1tbl, (unsigned char)0);
        if (__1nx && (__1nx->n_ktable__4name == __1tbl)) {
            if (__1nx->base__4node == 123) {
                ;
                if ((__1nx->__O1__4expr.tp && (__1nx->__O1__4expr.tp->base__4node != 119)) &&
                    (__1nx->__O1__4expr.tp->base__4node != 121)) {
                    ;
                }
                __1nx->n_key__4name = 159;
                {
                    Pname __3ny;

                    __3ny = insert__6ktableFP4nameUc(__1tbl, __1nn, (unsigned char)0);
                    if (Nold) {
                        struct ea __0__V238;

                        error__FPCcRC2eaN32(
                            (const char *)"hiddenTN%n inserted twice",
                            (const struct ea *)(((&__0__V238)->__O1__2ea.p = ((const void *)__1nx)),
                                                (&__0__V238)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else
                        __3ny->__O1__4name.n_hidden = __1nx;
                    __1nx = __3ny;
                }
            } else {
                ;
                ;
            }
        } else {
            Pname __2ny;

            __2ny = insert__6ktableFP4nameUc(__1tbl, __1nn, (unsigned char)0);
            if (__1nx && (__1nx->base__4node != 123))
                __1nx = __1nx->__O1__4name.n_hidden;
            __2ny->__O1__4name.n_hidden = __1nx;
            __1nx = __2ny;
        }
        return __1nx;
    }
}

Pname insert_type__FP4nameP6ktableUc(Pname __1nn, Pktab __1tbl, TOK __1tcsue) {
    ;
    if (__1tbl->k_id__6ktable == 136) {
        do
            __1tbl = __1tbl->k_next__6ktable;
        while (__1tbl->k_id__6ktable == 136);

        if (__1tbl->k_id__6ktable == 185)
            __1tbl = __1tbl->k_next__6ktable;
    }
    if (__1tbl->k_id__6ktable == 6) {
        if (ccl == 0) {
            struct ea __0__V239;

            error__FiP3locPCcRC2eaN34(
                (int)'i', &__1nn->where__4name,
                (const char *)"insert_type(%n) -- no ccl for class table!",
                (const struct ea *)(((&__0__V239)->__O1__2ea.p = ((const void *)__1nn)),
                                    (&__0__V239)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
    };

    {
        Pname __1nx;

        __1nx = k_find_name__FPCcP6ktableUc(__1nn->__O2__4expr.string, __1tbl, (unsigned char)0);
        if (__1nx && (__1nx->n_ktable__4name == __1tbl)) {
            Nold = 0;
            if (__1nx->base__4node == 123) {
                Nold = 1;
                ;
            } else {
                if (__1tcsue == 97) {
                    ;
                    ;
                }
                {
                    Pname __3ny;

                    __3ny = insert__6ktableFP4nameUc(__1tbl, __1nn, (unsigned char)159);
                    if (Nold) {
                        ;
                        ;
                    } else {
                        __3ny->__O1__4name.n_hidden = __1nx->__O1__4name.n_hidden;

                        __1nx->__O1__4name.n_hidden = __3ny;
                        ;
                    }
                    __1nx = __3ny;
                }
            }
        } else {
            Pname __2ny;

            __2ny = insert__6ktableFP4nameUc(__1tbl, __1nn, (unsigned char)0);
            __2ny->__O1__4name.n_hidden = __1nx;
            __1nx = __2ny;
            ;
        }
        __1nx->base__4node = 123;
        return __1nx;
    }
}

const char *whereami__6ktableFv(register struct ktable *__0this) {
    if (__0this == 0)
        return (const char *)"NULL TABLE!!!";
    else if (__0this->k_id__6ktable == 136)
        return (const char *)"arg scope";
    else if (__0this == Gtbl)
        return (const char *)"global scope";
    else if (__0this->k_id__6ktable == 116)
        return (const char *)"block scope";
    else if (__0this->k_id__6ktable == 185)
        return (const char *)"template scope";
    else if (__0this->k_name__6ktable)
        return __0this->k_name__6ktable->__O2__4expr.string;
    else
        return (const char *)"??? scope";
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
