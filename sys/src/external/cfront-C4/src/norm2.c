
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

extern int error__FPCc(const char *);
extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

struct fct *__ct__3fctFP4typeP4nameUc(register struct fct *__0this, Ptype __1t, Pname __1arg,
                                      TOK __1known) {
    Pname __1n;
    Pname __1pn;

    struct type *__0__X20;

    struct node *__0__X1;

    if (__0this || (__0this = (struct fct *)__nw__3fctSFUl((size_t)(sizeof(struct fct))))) {
        __0this =
            (struct fct
                 *)((__0__X20 = (((struct type *)__0this))),
                    (((__0__X20 ||
                       (__0__X20 = (struct type *)__nw__FUl((size_t)(sizeof(struct type)))))
                          ? (((((((((__0__X20 =
                                         (struct type *)((__0__X1 = (((struct node *)__0__X20))),
                                                         (((__0__X1 ||
                                                            (__0__X1 = (struct node *)__nw__FUl(
                                                                 (size_t)(sizeof(struct node)))))
                                                               ? (((__0__X1->base__4node = 0),
                                                                   (__0__X1->permanent__4node = 0)),
                                                                  (__0__X1->baseclass__4node = 0))
                                                               : 0),
                                                          __0__X1))),
                                    (__0__X20->defined__4type = 0)),
                                   (__0__X20->lex_level__4type = 0)),
                                  (__0__X20->templ_base__4type = 0)),
                                 (__0__X20->in_class__4type = 0)),
                                (__0__X20->nested_sig__4type = 0)),
                               (__0__X20->local_sig__4type = 0)),
                              (__0__X20->b_const__4type = 0)),
                             (__0__X20->ansi_const__4type = 0))
                          : 0),
                     __0__X20));
        __0this->base__4node = 108;
        __0this->nargs_known__3fct = __1known;
        __0this->returns__3fct = __1t;
        __0this->argtype__3fct = __1arg;
        __0this->f_virtual__3fct = 0;
        ;

        if ((__1arg == 0) || (__1arg->base__4node == 140))
            return __0this;

        ;
        __1pn = 0;
        for (__1n = __1arg; __1n; ((__1pn = __1n), (__1n = __1n->__O1__4name.n_list))) {
            if (__1n->n_sto__4name == 14)
                error__FPCc((const char *)"cannot specify extern linkage for anA");
            if (__1n->n_sto__4name == 31) {
                struct ea __0__V17;

                error__FPCcRC2eaN32(
                    (const char *)"cannot specify static forA%n",
                    (const struct ea *)(((&__0__V17)->__O1__2ea.p = ((const void *)__1arg)),
                                        (&__0__V17)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            switch (skiptypedefs__4typeFv(__1n->__O1__4expr.tp)->base__4node) {
                unsigned long __2__X21;

            case 38:
                __0this->argtype__3fct = 0;
                __0this->nargs_known__3fct = 1;
                if (__1n->__O3__4expr.n_initializer)
                    error__FPCc((const char *)"voidFA");
                else if (__1n->__O2__4expr.string) {
                    struct ea __0__V18;

                    error__FPCcRC2eaN32(
                        (const char *)"voidFA%n",
                        (const struct ea *)(((&__0__V18)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V18)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                } else if (__0this->nargs__3fct || __1n->__O1__4name.n_list) {
                    error__FPCc((const char *)"voidFA");
                    __0this->nargs_known__3fct = 0;
                }
                __0this->nargs__3fct = 0;
                break;
            case 6:
            case 13: {
                struct ea __0__V19;

                error__FPCcRC2eaN32(
                    (const char *)"%k defined inAL (will not be in scope at point of call)",
                    (const struct ea *)((__2__X21 = __1n->__O1__4expr.tp->base__4node),
                                        (((((&__0__V19)->__O1__2ea.i = __2__X21), 0)),
                                         (&__0__V19))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                if (__1n == __0this->argtype__3fct)
                    __0this->argtype__3fct = __1n->__O1__4name.n_list;
                else
                    __1pn->__O1__4name.n_list = __1n->__O1__4name.n_list;
                break;
            default:
                __0this->nargs__3fct++;
            }
            }
        }
    }
    return __0this;
}

struct expr *__ct__4exprFUcP4exprT2(register struct expr *__0this, TOK __1ba, Pexpr __1a,
                                    Pexpr __1b) {
    struct node *__0__X22;

    if (__0this || (__0this = (struct expr *)__nw__4exprSFUl((size_t)(sizeof(struct expr))))) {
        __0this =
            (struct expr *)((__0__X22 = (((struct node *)__0this))),
                            (((__0__X22 ||
                               (__0__X22 = (struct node *)__nw__FUl((size_t)(sizeof(struct node)))))
                                  ? (((__0__X22->base__4node = 0),
                                      (__0__X22->permanent__4node = 0)),
                                     (__0__X22->baseclass__4node = 0))
                                  : 0),
                             __0__X22));
        ;

        __0this->base__4node = __1ba;
        __0this->__O2__4expr.e1 = __1a;
        __0this->__O3__4expr.e2 = __1b;
        __0this->__O4__4expr.mem = 0;
        __0this->__O1__4expr.tp = 0;
        ;
    }
    return __0this;
}

struct stmt *__ct__4stmtFUc3locP4stmt(register struct stmt *__0this, TOK __1ba, struct loc __1ll,
                                      Pstmt __1a) {
    struct node *__0__X23;

    if (__0this || (__0this = (struct stmt *)__nw__4stmtSFUl((size_t)(sizeof(struct stmt))))) {
        __0this =
            (struct stmt *)((__0__X23 = (((struct node *)__0this))),
                            (((__0__X23 ||
                               (__0__X23 = (struct node *)__nw__FUl((size_t)(sizeof(struct node)))))
                                  ? (((__0__X23->base__4node = 0),
                                      (__0__X23->permanent__4node = 0)),
                                     (__0__X23->baseclass__4node = 0))
                                  : 0),
                             __0__X23));
        ;

        __0this->base__4node = __1ba;
        __0this->where__4stmt = __1ll;
        __0this->s__4stmt = __1a;
        __0this->memtbl__4stmt = 0;
        __0this->k_tbl__4stmt = 0;
        ;
    }
    return __0this;
}

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

struct classdef *__ct__8classdefFUc(register struct classdef *__0this, TOK __1b) {
    struct type *__0__X24;

    struct node *__0__X1;

    if (__0this || (__0this = (struct classdef *)__nw__FUl((size_t)(sizeof(struct classdef))))) {
        __0this =
            (struct classdef
                 *)((__0__X24 = (((struct type *)__0this))),
                    (((__0__X24 ||
                       (__0__X24 = (struct type *)__nw__FUl((size_t)(sizeof(struct type)))))
                          ? (((((((((__0__X24 =
                                         (struct type *)((__0__X1 = (((struct node *)__0__X24))),
                                                         (((__0__X1 ||
                                                            (__0__X1 = (struct node *)__nw__FUl(
                                                                 (size_t)(sizeof(struct node)))))
                                                               ? (((__0__X1->base__4node = 0),
                                                                   (__0__X1->permanent__4node = 0)),
                                                                  (__0__X1->baseclass__4node = 0))
                                                               : 0),
                                                          __0__X1))),
                                    (__0__X24->defined__4type = 0)),
                                   (__0__X24->lex_level__4type = 0)),
                                  (__0__X24->templ_base__4type = 0)),
                                 (__0__X24->in_class__4type = 0)),
                                (__0__X24->nested_sig__4type = 0)),
                               (__0__X24->local_sig__4type = 0)),
                              (__0__X24->b_const__4type = 0)),
                             (__0__X24->ansi_const__4type = 0))
                          : 0),
                     __0__X24));
        __0this->base__4node = 6;
        __0this->csu__8classdef = __1b;
        __0this->memtbl__8classdef = __ct__5tableFsP5tableP4name(
            (struct table *)0, (short)12, (struct table *)0, (struct name *)0);
        __0this->k_tbl__8classdef = 0;
        __0this->class_base__8classdef = 0;
        __0this->c_xref__8classdef = 0;
        __0this->c_body__8classdef = 0;
        __0this->has_vvtab__8classdef = 0;
        __0this->obj_align__8classdef = 0;
        __0this->virt_merge__8classdef = 0;
        __0this->virt_count__8classdef = 0;
        __0this->c_context__8classdef = 0;
        __0this->mem_list__8classdef = 0;
        __0this->baselist__8classdef = 0;
        __0this->friend_list__8classdef = 0;
        __0this->c_funqf__8classdef = (__0this->c_funqr__8classdef = 0);
        __0this->c_ctor__8classdef = 0;
        __0this->c_itor__8classdef = 0;
        __0this->c_dtor__8classdef = 0;
        __0this->c_vtor__8classdef = 0;
        __0this->virt_list__8classdef = 0;
        __0this->c_abstract__8classdef = 0;
        __0this->conv__8classdef = 0;
        __0this->string__8classdef = 0;
        ;
    }
    return __0this;
}

extern void __dl__FPv(void *);

void __dt__5tableFv(struct table *__0this, int);

void __dt__8classdefFv(struct classdef *__0this, int __0__free) {
    if (__0this) {
        __dt__5tableFv(__0this->memtbl__8classdef, 3);
        if (__0this)
            if (__0__free & 1)
                __dl__FPv((void *)__0this);
    }
}

struct basetype *__ct__8basetypeFUcP4name(register struct basetype *__0this, TOK __1b, Pname __1n) {
    struct type *__0__X27;

    struct node *__0__X1;

    if (__0this || (__0this = (struct basetype *)__nw__FUl((size_t)(sizeof(struct basetype))))) {
        __0this =
            (struct basetype
                 *)((__0__X27 = (((struct type *)__0this))),
                    (((__0__X27 ||
                       (__0__X27 = (struct type *)__nw__FUl((size_t)(sizeof(struct type)))))
                          ? (((((((((__0__X27 =
                                         (struct type *)((__0__X1 = (((struct node *)__0__X27))),
                                                         (((__0__X1 ||
                                                            (__0__X1 = (struct node *)__nw__FUl(
                                                                 (size_t)(sizeof(struct node)))))
                                                               ? (((__0__X1->base__4node = 0),
                                                                   (__0__X1->permanent__4node = 0)),
                                                                  (__0__X1->baseclass__4node = 0))
                                                               : 0),
                                                          __0__X1))),
                                    (__0__X27->defined__4type = 0)),
                                   (__0__X27->lex_level__4type = 0)),
                                  (__0__X27->templ_base__4type = 0)),
                                 (__0__X27->in_class__4type = 0)),
                                (__0__X27->nested_sig__4type = 0)),
                               (__0__X27->local_sig__4type = 0)),
                              (__0__X27->b_const__4type = 0)),
                             (__0__X27->ansi_const__4type = 0))
                          : 0),
                     __0__X27));
        __0this->b_xname__8basetype = 0;
        __0this->b_sto__8basetype = 0;
        __0this->b_name__8basetype = 0;

        __0this->b_unsigned__8basetype =
            (__0this->b_signed__8basetype =
                 (__0this->b_volatile__8basetype =
                      (__0this->b_typedef__8basetype =
                           (__0this->b_inline__8basetype =
                                (__0this->b_virtual__8basetype =
                                     (__0this->b_short__8basetype =
                                          (__0this->b_long__8basetype =
                                               (__0this->b_bits__8basetype =
                                                    (__0this->b_offset__8basetype = 0)))))))));
        __0this->__O1__8basetype.b_linkage = 0;
        switch (__1b) {
        case 0:
            break;
        case 35:
            __0this->b_typedef__8basetype = 1;

            break;
        case 75:
            __0this->b_inline__8basetype = 1;

            break;
        case 77:
            __0this->b_virtual__8basetype = 1;

            break;
        case 26:
            __0this->b_const__4type = 1;

            break;
        case 37:
            __0this->b_unsigned__8basetype = 1;

            break;
        case 18:
        case 76:
        case 14:
        case 31:
        case 2:
        case 27:
            __0this->b_sto__8basetype = __1b;

            break;
        case 29:
            __0this->b_short__8basetype = 1;

            break;
        case 22:
            __0this->b_long__8basetype = 1;

            break;
        case 122:
            __0this->b_long__8basetype = 2;

            break;
        case 141:
        case 138:
        case 38:
        case 5:
        case 21:
        case 15:
        case 181:
        case 11:
            __0this->base__4node = __1b;

            break;
        case 97:
        case 119:
        case 121:
        case 114:
        case 1:
            __0this->base__4node = __1b;
            __0this->b_name__8basetype = __1n;
            break;
        case 171:
            break;
        case 170: {
            struct ea __0__V25;

            error__FiPCcRC2eaN33(
                (int)'w', (const char *)"\"%k\" not implemented (ignored)",
                (const struct ea *)(((((&__0__V25)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                    (&__0__V25)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            break;
        default: {
            struct ea __0__V26;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"badBT:%k",
                (const struct ea *)(((((&__0__V26)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                    (&__0__V26)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        }
        };
    }
    return __0this;
}

struct name *__ct__4nameFPCc(register struct name *__0this, const char *__1s) {
    if (__0this ||
        (__0this = (struct name *)__nw__4nameSFUl((unsigned long)(sizeof(struct name))))) {
        __0this = (struct name *)__ct__4exprFUcP4exprT2(((struct expr *)__0this), (unsigned char)85,
                                                        (struct expr *)0, (struct expr *)0);

        __0this->__O2__4expr.string = __1s;
        __0this->where__4name = curloc;
        __0this->lex_level__4name = bl_level;
    }
    return __0this;
}

struct name_list *__ct__9name_listFP4nameP9name_list(register struct name_list *__0this,
                                                     Pname __1ff, Plist __1ll) {
    struct node *__0__X28;

    if (__0this || (__0this = (struct name_list *)__nw__FUl((size_t)(sizeof(struct name_list))))) {
        __0this = (struct name_list *)((__0__X28 = (((struct node *)__0this))),
                                       (((__0__X28 || (__0__X28 = (struct node *)__nw__FUl(
                                                           (size_t)(sizeof(struct node)))))
                                             ? (((__0__X28->base__4node = 0),
                                                 (__0__X28->permanent__4node = 0)),
                                                (__0__X28->baseclass__4node = 0))
                                             : 0),
                                        __0__X28));
        __0this->base__4node = 201;
        __0this->f__9name_list = __1ff;
        __0this->l__9name_list = __1ll;
    }
    return __0this;
}

struct nlist *__ct__5nlistFP4name(register struct nlist *__0this, Pname __1n) {
    if (__0this || (__0this = (struct nlist *)__nw__FUl((size_t)(sizeof(struct nlist))))) {
        __0this->head__5nlist = __1n;
        {
            Pname __1nn;

            __1nn = __1n;
            for (; __1nn->__O1__4name.n_list; __1nn = __1nn->__O1__4name.n_list)
                ;
            __0this->tail__5nlist = __1nn;
        }
    }
    return __0this;
}

void add_list__5nlistFP4name(register struct nlist *__0this, Pname __1n) {
    if (__1n->__O1__4expr.tp && (__1n->__O1__4expr.tp->defined__4type & 020))
        return;

    __0this->tail__5nlist->__O1__4name.n_list = __1n;
    {
        Pname __1nn;

        __1nn = __1n;
        for (; __1nn->__O1__4name.n_list; __1nn = __1nn->__O1__4name.n_list)
            ;
        __0this->tail__5nlist = __1nn;
    }
}

Pname name_unlist__FP5nlist(Pnlist __1l) {
    if (__1l == 0)
        return (struct name *)0;
    {
        Pname __1n;

        __1n = __1l->head__5nlist;

        __dl__FPv((void *)__1l);
        return __1n;
    }
}

Pstmt stmt_unlist__FP5slist(Pslist __1l) {
    if (__1l == 0)
        return (struct stmt *)0;
    {
        Pstmt __1s;

        __1s = __1l->head__5slist;

        __dl__FPv((void *)__1l);
        return __1s;
    }
}

Pexpr expr_unlist__FP5elist(Pelist __1l) {
    if (__1l == 0)
        return (struct expr *)0;
    {
        Pexpr __1e;

        __1e = __1l->head__5elist;

        __dl__FPv((void *)__1l);
        return __1e;
    }
}

char *signature__4typeFPci(struct type *__0this, char *, int);

extern char *strcpy(char *, const char *);

void sig_name__FP4name(Pname __1n) {
    static char __1buf[1024];
    (__1buf[0]) = '_';
    (__1buf[1]) = '_';
    (__1buf[2]) = 'o';
    (__1buf[3]) = 'p';
    {
        char *__1p;

        __1p = signature__4typeFPci(__1n->__O1__4expr.tp, (char *)(__1buf + 4), 0);
        if (255 < (__1p - __1buf))
            error__FiPCc((int)'i', (const char *)"sig_name():N buffer overflow");

        {
            char *__1s;

            __1s = (((char *)__nw__FUl((size_t)((sizeof(char)) * ((__1p - __1buf) + 1)))));
            strcpy(__1s, (const char *)__1buf);
            __1n->__O2__4expr.string = (const char *)__1s;
            __1n->__O1__4expr.tp = 0;
        }
    }
}

Ptype tok_to_type__FUc(TOK __1b) {
    Ptype __1t;
    switch (__1b) {
    case 5:
        __1t = (struct type *)char_type;

        break;
    case 29:
        __1t = (struct type *)short_type;

        break;
    case 22:
        __1t = (struct type *)long_type;

        break;
    case 122:
        __1t = (struct type *)llong_type;

        break;
    case 37:
        __1t = (struct type *)uint_type;

        break;
    case 15:
        __1t = (struct type *)float_type;

        break;
    case 11:
        __1t = (struct type *)double_type;

        break;
    case 181:
        __1t = (struct type *)ldouble_type;

        break;
    case 38:
        __1t = (struct type *)void_type;

        break;
    default: {
        struct ea __0__V29;

        error__FPCcRC2eaN32(
            (const char *)"illegalK:%k",
            (const struct ea *)(((((&__0__V29)->__O1__2ea.i = ((unsigned long)__1b)), 0)),
                                (&__0__V29)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    case 21:
        __1t = (struct type *)int_type;
    }
    }
    return __1t;
}

Pbase defa_type = 0;
Pbase moe_type = 0;
Pexpr dummy = 0;
Pexpr zero = 0;

Pclass ccl = 0;

Plist local_class = 0;

void memptrdcl__FP4nameT1P4typeT1(Pname __1bn, Pname __1tn, Ptype __1ft, Pname __1n) {
    Pptr __1p;

    __1p = __ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, (struct type *)0);
    __1p->memof__3ptr = (((struct classdef *)((
        (struct classdef *)(((struct basetype *)(((struct basetype *)__1bn->__O1__4expr.tp))))
            ->b_name__8basetype->__O1__4expr.tp))));
    {
        Pbase __1b;

        __1b = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)97, __1tn);
        __1p->permanent__4node = 1;
        {
            Pfct __1f;
            Ptype __1t;

            __1f = (((struct fct *)(((struct fct *)__1ft))));
            __1t = __1n->__O1__4expr.tp;
            if (__1t) {
                __1p->typ__5pvtyp = __1t;
            ltlt:
                switch (__1t->base__4node) {
                case 125:
                case 158:
                case 110:
                    if ((((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp == 0) {
                        (((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp = (struct type *)__1b;
                        break;
                    }
                    __1t = (((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp;
                    goto ltlt;
                default:
                    error__FiPCc((int)'s', (const char *)"P toMFT too complicated");
                }
            } else
                __1p->typ__5pvtyp = (struct type *)__1b;
            __1f->returns__3fct = (struct type *)__1p;
            __1n->__O1__4expr.tp = (struct type *)__1f;
        }
    }
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
