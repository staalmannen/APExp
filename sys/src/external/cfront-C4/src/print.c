
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

static int addrof_cm;

static ssize_t lab_cnt = 0;
static ssize_t curr_lab = 0;

void print__4exprFv(struct expr *__0this);

extern int fputc(int, void *);

void Eprint__FP4expr(Pexpr __1e) {
    switch (__1e->base__4node) {
    case 45:
    case 44:
        if (((((struct ref *)(((struct ref *)__1e))))->__O4__4expr.mem &&
             (((struct ref *)(((struct ref *)__1e))))->__O4__4expr.mem->__O1__4expr.tp) &&
            ((((struct ref *)(((struct ref *)__1e))))
                 ->__O4__4expr.mem->__O1__4expr.tp->base__4node == 108)) {
            print__4exprFv((((struct ref *)(((struct ref *)__1e))))->__O4__4expr.mem);
            break;
        }
    case 85:
    case 177:
    case 80:
    case 86:
    case 82:
    case 84:
    case 83:
    case 81:
    case 150:
    case 165:
    case 71:
    case 147:
    case 140:
    case 69:
    case 124:
    case 34:
    case 109:
    case 146:
    case 168:
    case 169:
        print__4exprFv(__1e);
        break;
    case 162: {
        struct ea __0__V17;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"T destructor in %cprint()",
            (const struct ea *)(((((&__0__V17)->__O1__2ea.i = ((unsigned long)'E')), 0)),
                                (&__0__V17)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    case 144:
        break;
    default:
        fputc((int)'(', out_file);
        print__4exprFv(__1e);
        fputc((int)')', out_file);
    }
    }
}

void Eprint_FP4expr(Pexpr __1e) { Eprint__FP4expr(__1e); }

extern int fputs(const char *__0s, void *__0stream);

extern void puttok__FUc(TOK);

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);
bit is_unsigned__4typeFv(struct type *__0this);

void print__4typeFv(struct type *__0this);

extern int fprintf(void *, const char *, ...);

void print__4nameFUc(struct name *__0this, bit __1fullprint);

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

Pname is_cl_obj__4typeFv(struct type *__0this);

void print__4stmtFv(struct stmt *__0this);

extern int error__FPCc(const char *);

Pfct memptr__4typeFv(struct type *__0this);

extern char *vtbl_name__FPCcT1(const char *, const char *);

extern char *ptbl_lookup__FPCc(const char *);

extern size_t strlen(const char *);

extern char *strcpy(char *, const char *);

extern char *strcat(char *, const char *);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

Pptr is_ptr__4typeFv(struct type *__0this);

Pptr is_ref__4typeFv(struct type *__0this);

Pexpr address__4exprFv(struct expr *__0this);

long long eval__4exprFv(struct expr *__0this);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

extern void __dl__FPv(void *);

void print__4exprFv(register struct expr *__0this) {
    unsigned long __2__X31;

    if (__0this == 0)
        error__FiPCc((int)'i', (const char *)"0->E::print()");
    if (((__0this == __0this->__O2__4expr.e1) || (__0this == __0this->__O3__4expr.e2)) &&
        (__0this->base__4node != 85)) {
        struct ea __0__V18;

        struct ea __0__V19;

        struct ea __0__V20;

        struct ea __0__V21;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"(%p%k)->E::print(%p %p)",
            (const struct ea *)(((&__0__V18)->__O1__2ea.p = ((const void *)__0this)), (&__0__V18)),
            (const struct ea *)((__2__X31 = __0this->base__4node),
                                (((((&__0__V19)->__O1__2ea.i = __2__X31), 0)), (&__0__V19))),
            (const struct ea *)__ct__2eaFPCv(&__0__V20, (const void *)__0this->__O2__4expr.e1),
            (const struct ea *)__ct__2eaFPCv(&__0__V21, (const void *)__0this->__O3__4expr.e2));
    }
    switch (__0this->base__4node) {
        unsigned long __2__X33;

    case 177: {
        int __3not_allocated;

        __3not_allocated = 0;
        switch (__0this->__O2__4expr.i1) {
        case 0:
            (fputc((int)'O', out_file), fputs(__0this->__O3__4expr.string2, out_file));
            puttok__FUc((unsigned char)45);
            print__4exprFv(__0this->__O4__4expr.mem);
            break;
        case 1:
            (fputc((int)'P', out_file), fputs(__0this->__O3__4expr.string2, out_file));
            puttok__FUc((unsigned char)44);
            print__4exprFv(__0this->__O4__4expr.mem);
            break;
        case 2:
            if (is_ptr_or_ref__4typeFv(__0this->__O4__4expr.mem->__O1__4expr.tp) == 0) {
                print__4exprFv(__0this->__O4__4expr.mem);
                puttok__FUc((unsigned char)45);
                (fputc((int)'O', out_file), fputs(__0this->__O3__4expr.string2, out_file));
            } else {
                fputc((int)'(', out_file);
                fputc((int)'&', out_file);
                fputc((int)'(', out_file);
                if (__0this->__O4__4expr.mem)
                    Eprint__FP4expr(__0this->__O4__4expr.mem);
                puttok__FUc((unsigned char)44);
                (fputc((int)'O', out_file), fputs(__0this->__O3__4expr.string2, out_file));
                fputc((int)')', out_file);
                fputc((int)')', out_file);
            }
            break;
        case 5:
            __3not_allocated = 1;

        case 3:
            if (is_ptr_or_ref__4typeFv(__0this->__O4__4expr.mem->__O1__4expr.tp) == 0) {
                fputc((int)'(', out_file);
                fputc((int)'*', out_file);
                fputc((int)'(', out_file);
                if (__0this->__O4__4expr.mem)
                    Eprint__FP4expr(__0this->__O4__4expr.mem);
                puttok__FUc((unsigned char)45);
                (fputc((int)'P', out_file), fputs(__0this->__O3__4expr.string2, out_file));
                fputc((int)')', out_file);
                fputc((int)')', out_file);
            } else {
                TOK __5m;

                __5m = __0this->__O4__4expr.mem->base__4node;
                if ((__5m == 112) || (__5m == 145)) {
                    if ((__0this->__O4__4expr.mem->__O3__4expr.e2->base__4node == 111) &&
                        (!__0this->__O4__4expr.mem->__O3__4expr.e2->__O3__4expr.e2))
                        __5m =
                            __0this->__O4__4expr.mem->__O3__4expr.e2->__O2__4expr.e1->base__4node;
                }
                if (__3not_allocated) {
                    fputc((int)'(', out_file);
                    print__4exprFv(__0this->__O4__4expr.mem);
                    if (((__5m == 85) || (__5m == 169)) || (__5m == 44))
                        puttok__FUc((unsigned char)44);
                    else
                        puttok__FUc((unsigned char)45);
                    (fputc((int)'O', out_file),
                     fputs((const char *)__0this->__O1__4expr.string4, out_file));

                    fputc((int)')', out_file);
                } else if (__0this->__O4__4expr.mem)
                    Eprint__FP4expr(__0this->__O4__4expr.mem);
                if ((((__5m == 85) || (__5m == 169)) || (__5m == 44)) && __3not_allocated)
                    puttok__FUc((unsigned char)45);
                else
                    puttok__FUc((unsigned char)44);
                (fputc((int)'P', out_file), fputs(__0this->__O3__4expr.string2, out_file));
            }
            break;
        case 9:
            if (__0this->__O4__4expr.mem)
                Eprint__FP4expr(__0this->__O4__4expr.mem);
            fputc((int)'.', out_file);
            fputs(__0this->__O3__4expr.string2, out_file);
        }
        break;
    }

    case 85: {
        Pname __3n;

        __3n = (((struct name *)(((struct name *)__0this))));
        if (__3n->n_evaluated__4name && (__3n->n_scope__4name != 136)) {
            Ptype __4t;

            __4t = skiptypedefs__4typeFv(__0this->__O1__4expr.tp);
            if (__4t->base__4node == 121)
                __4t = (struct type *)(((struct enumdef *)((
                                           (struct enumdef *)(((struct basetype *)((
                                                                  (struct basetype *)__4t))))
                                               ->b_name__8basetype->__O1__4expr.tp))))
                           ->e_type__7enumdef;
            if ((__4t->base__4node != 21) || is_unsigned__4typeFv(__4t)) {
                fputs((const char *)"((", out_file);
                {
                    bit __5oc;

                    __5oc = Cast;
                    Cast = 1;
                    print__4typeFv(__4t);
                    Cast = __5oc;
                    fprintf(out_file, (const char *)")%lld)", __3n->n_val__4name);
                }
            } else
                fprintf(out_file, (const char *)"%lld", __3n->n_val__4name);
        } else
            print__4nameFUc(__3n, (unsigned char)0);
        break;
    }

    case 169:
        if (curr_icall) {
            Pname __3n;
            int __3argno;

            Pin __3il;

            __3n = (((struct name *)(((struct name *)__0this))));
            __3argno = __3n->argno__4name;

            __3il = curr_icall;
            for (; __3il; __3il = __3il->i_next__5iline)
                if (__3n->__O4__4expr.n_table == __3il->i_table__5iline)
                    goto aok;
            goto bok;
        aok:
            if (__3n = (__3il->i_args__5iline[__3argno]).local__2ia) {
                print__4nameFUc(__3n, (unsigned char)0);
            } else {
                Pexpr __4ee;
                Ptype __4t;

                __4ee = (__3il->i_args__5iline[__3argno]).arg__2ia;
                __4t = (__3il->i_args__5iline[__3argno]).tp__2ia;
                if ((__4ee == 0) || (__4ee == __0this)) {
                    struct ea __0__V22;

                    struct ea __0__V23;

                    error__FiPCcRC2eaN33(
                        (int)'i', (const char *)"%p->E::print(A %p)",
                        (const struct ea *)(((&__0__V22)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V22)),
                        (const struct ea *)(((&__0__V23)->__O1__2ea.p = ((const void *)__4ee)),
                                            (&__0__V23)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
                if ((__4ee->__O1__4expr.tp == 0) ||
                    (((__4t != __4ee->__O1__4expr.tp) &&
                      check__4typeFP4typeUcT2(__4t, __4ee->__O1__4expr.tp, (unsigned char)0,
                                              (unsigned char)0)) &&
                     (is_cl_obj__4typeFv(__4t) == 0))) {
                    fputs((const char *)"((", out_file);
                    {
                        bit __5oc;

                        __5oc = Cast;
                        Cast = 1;
                        print__4typeFv(__4t);
                        Cast = __5oc;
                        fputc((int)')', out_file);
                        if (__4ee)
                            Eprint__FP4expr(__4ee);
                        fputc((int)')', out_file);
                    }
                } else if (__4ee)
                    Eprint__FP4expr(__4ee);
            }
        } else {
        bok:
            print__4nameFUc(((struct name *)(((struct name *)__0this))), (unsigned char)0);
        }
        break;

    case 168: {
        if (__0this->__O4__4expr.il == 0)
            error__FiPCc((int)'i', (const char *)"E::print: iline missing");
        __0this->__O4__4expr.il->i_next__5iline = curr_icall;
        curr_icall = __0this->__O4__4expr.il;

        if (__0this->__O2__4expr.e1)
            Eprint__FP4expr(__0this->__O2__4expr.e1);
        if (__0this->__O3__4expr.e2) {
            ssize_t __4save;

            __4save = curr_lab;
            curr_lab = (++lab_cnt);
            print__4stmtFv(((struct stmt *)(((struct stmt *)__0this->__O3__4expr.e2))));
            curr_lab = __4save;
        }
        curr_icall = __0this->__O4__4expr.il->i_next__5iline;
        break;
    }

    case 44:
    case 45:
        if (__0this->__O2__4expr.e1)
            Eprint__FP4expr(__0this->__O2__4expr.e1);
        puttok__FUc(__0this->base__4node);
        if (__0this->__O4__4expr.mem == 0) {
            fprintf(out_file, (const char *)"MEM0");

            break;
        }
        if (__0this->__O4__4expr.mem->base__4node == 85)
            print__4nameFUc(((struct name *)(((struct name *)__0this->__O4__4expr.mem))),
                            (unsigned char)0);
        else
            print__4exprFv(__0this->__O4__4expr.mem);
        break;

    case 173:
        error__FPCc((const char *)"P toMF not called");
        break;

    case 157:
        print__4typeFv(__0this->__O4__4expr.tp2);
        puttok__FUc((unsigned char)40);
        if (__0this->__O2__4expr.e1)
            print__4exprFv(__0this->__O2__4expr.e1);
        puttok__FUc((unsigned char)41);
        break;

    case 30:
        puttok__FUc((unsigned char)30);
        if (((__0this->__O2__4expr.e1 && (__0this->__O2__4expr.e1 != dummy)) &&
             (__0this->__O2__4expr.e1->base__4node != 124)) &&
            (((__0this->__O2__4expr.e1->base__4node != 113) &&
              (__0this->__O2__4expr.e1->base__4node != 191)) ||
             (__0this->__O2__4expr.e1->__O2__4expr.e1->base__4node != 124))) {
            if (__0this->__O2__4expr.e1)
                Eprint__FP4expr(__0this->__O2__4expr.e1);
        } else if (__0this->__O4__4expr.tp2) {
            fputc((int)'(', out_file);
            if (__0this->__O4__4expr.tp2->base__4node == 6) {
                Pclass __4cl;

                __4cl = (((struct classdef *)(((struct classdef *)__0this->__O4__4expr.tp2))));
                fputs((const char *)((__4cl->csu__8classdef == 36) ? "union "
                                                                   : (((char *)"struct "))),
                      out_file);
                {
                    char *__4str;

                    __4str = 0;

                    if (__4cl->lex_level__4type && (__4cl->nested_sig__4type == 0))
                        __4str = __4cl->local_sig__4type;

                    if (__4str)
                        fputs((const char *)__4str, out_file);
                    else if (__4cl->nested_sig__4type)
                        fprintf(out_file, (const char *)"__%s", __4cl->nested_sig__4type);
                    else
                        fputs(__4cl->string__8classdef, out_file);
                }
            } else
                print__4typeFv(__0this->__O4__4expr.tp2);
            fputc((int)')', out_file);
        } else {
            error__FiPCc((int)'i', (const char *)"missingE for sizeof");
        }
        break;

    case 113:
    case 191:
        if (__0this->__O2__4expr.e1->base__4node == 124) {
            if (__0this->__O2__4expr.e1)
                Eprint__FP4expr(__0this->__O2__4expr.e1);
            break;
        }
        fputc((int)'(', out_file);

        if (((__0this->__O4__4expr.tp2 != (((struct type *)mptr_type))) &&
             ((__0this->__O4__4expr.tp2->base__4node != 38) || ansi_opt)) &&
            (memptr__4typeFv(__0this->__O4__4expr.tp2) == 0)) {
            fputc((int)'(', out_file);
            {
                bit __3oc;

                __3oc = Cast;
                Cast = 1;
                if ((__0this->__O4__4expr.tp2->base__4node == 97) ||
                    (__0this->__O4__4expr.tp2->base__4node == 110))
                    TCast = 1;
                else
                    TCast = 0;
                print__4typeFv(__0this->__O4__4expr.tp2);
                TCast = 0;
                Cast = __3oc;
                fputc((int)')', out_file);
            }
        }
        if (__0this->__O2__4expr.e1)
            Eprint__FP4expr(__0this->__O2__4expr.e1);
        fputc((int)')', out_file);
        break;

    case 82:
    case 83:
    case 84:
    case 80:
        if (__0this->__O2__4expr.string)
            (fputs(__0this->__O2__4expr.string, out_file), fputc((int)' ', out_file));
        break;

    case 81:
        ntok += 4;
        fprintf(out_file, (const char *)"\"%s\"", __0this->__O2__4expr.string);
        break;

    case 34:
    case 86:
        fputs((const char *)"0 ", out_file);
        break;

    case 150:
        fprintf(out_file, (const char *)"%lld", __0this->__O2__4expr.i1);
        break;

    case 165: {
        int __3oo;

        __3oo = vtbl_opt;
        vtbl_opt = -1;
        {
            char *__3s;

            __3s = vtbl_name__FPCcT1(__0this->__O2__4expr.string, __0this->__O3__4expr.string2);
            vtbl_opt = __3oo;
            (__3s[2]) = 'p';
            {
                char *__3t;

                __3t = ptbl_lookup__FPCc((const char *)__3s);
                fprintf(out_file, (const char *)" %s", __3t);
                __dl__FPv((void *)__3t);

                {
                    char *__3str;

                    __3str = 0;
                    if (__0this->__O2__4expr.string) {
                        __3str = (((char *)__nw__FUl(
                            (size_t)((sizeof(char)) * ((strlen(__0this->__O2__4expr.string) +
                                                        strlen(__0this->__O3__4expr.string2)) +
                                                       1)))));
                        strcpy(__3str, __0this->__O2__4expr.string);
                        strcat(__3str, __0this->__O3__4expr.string2);
                    }

                    if ((look__5tableFPCcUc(
                             ptbl, __3str ? (((const char *)__3str)) : __0this->__O3__4expr.string2,
                             (unsigned char)0) == 0) &&
                        (look__5tableFPCcUc(
                             ptbl, __3str ? (((const char *)__3str)) : __0this->__O3__4expr.string2,
                             (unsigned char)159) == 0)) {
                        Pname __4nn;
                        char *__4str;

                        __4nn = insert__5tableFP4nameUc(
                            ptbl,
                            __ct__4nameFPCc((struct name *)0, __3str
                                                                  ? (((const char *)__3str))
                                                                  : __0this->__O3__4expr.string2),
                            (unsigned char)0);
                        __4str = (((char *)__nw__FUl(
                            (size_t)((sizeof(char)) * (strlen((const char *)__3s) + 1)))));
                        strcpy(__4str, (const char *)__3s);

                        __4nn->__O3__4expr.string2 = (const char *)__4str;
                    }

                    __dl__FPv((void *)__3str);
                    __dl__FPv((void *)__3s);
                }
            }
        }
    } break;

    case 162:
        error__FiPCc((int)'i', (const char *)"T destructor in expr::print()");
    case 144:
        break;

    case 146:
    case 109: {
        Pname __3fn;
        Pname __3at;
        int __3m_ptr;
        int __3comflag;

        __3fn = __0this->__O4__4expr.fct_name;

        __3m_ptr = 0;
        __3comflag = 0;

        if (__3fn) {
            Pfct __4f;

            __4f = (((struct fct *)(((struct fct *)__3fn->__O1__4expr.tp))));

            if (__4f->base__4node == 76) {
                __0this->__O4__4expr.fct_name =
                    (__3fn =
                         (((struct gen *)(((struct gen *)__4f))))->fct_list__3gen->f__9name_list);
                __4f = (((struct fct *)(((struct fct *)__3fn->__O1__4expr.tp))));
            }

            if ((__0this->__O2__4expr.e1->base__4node == 71) ||
                (__0this->__O2__4expr.e1->base__4node == 147)) {
                __3comflag = 1;
                puttok__FUc((unsigned char)40);
                print__4exprFv(__0this->__O2__4expr.e1->__O2__4expr.e1);
                puttok__FUc((unsigned char)71);
            }
            print__4nameFUc(__3fn, (unsigned char)0);
            __3at = __4f->f_args__3fct;
        } else {
            Pfct __4f;

            __4f = (((struct fct *)(((struct fct *)__0this->__O2__4expr.e1->__O1__4expr.tp))));

            if (__4f) {
                Pexpr __5exex;

                __5exex = __0this->__O2__4expr.e1;
                if (__5exex->base__4node == 111) {
                    __5exex = __5exex->__O2__4expr.e1;
                    while ((__5exex->base__4node == 113) || (__5exex->base__4node == 191))
                        __5exex = __5exex->__O2__4expr.e1;
                    if (__5exex->base__4node == 177)
                        __3m_ptr = 1;
                }

                if (__4f->base__4node == 76) {
                    __0this->__O4__4expr.fct_name =
                        (__3fn = (((struct gen *)(((struct gen *)__4f))))
                                     ->fct_list__3gen->f__9name_list);
                    __4f = (((struct fct *)(((struct fct *)__3fn->__O1__4expr.tp))));
                }

                __4f =
                    (((struct fct *)(((struct fct *)skiptypedefs__4typeFv((struct type *)__4f)))));
                if (__4f->base__4node == 125) {
                    fputs((const char *)"(*(", out_file);

                    print__4exprFv(__0this->__O2__4expr.e1);
                    fputs((const char *)"))", out_file);
                    __4f = (((struct fct *)(((struct fct *)skiptypedefs__4typeFv(
                        (((struct ptr *)(((struct ptr *)__4f))))->typ__5pvtyp)))));
                } else if (__0this->__O2__4expr.e1)
                    Eprint__FP4expr(__0this->__O2__4expr.e1);

                __3at = __4f->f_args__3fct;
            } else {
                __3at = ((__0this->__O2__4expr.e1->base__4node == 68)
                             ? (((struct name *)(((struct name *)__0this->__O2__4expr.e1
                                                      ->__O2__4expr.e1->__O4__4expr.tp2))))
                             : (((struct name *)((
                                   (struct name *)__0this->__O2__4expr.e1->__O4__4expr.tp2)))));
                if (__0this->__O2__4expr.e1)
                    Eprint__FP4expr(__0this->__O2__4expr.e1);
            }
        }

        puttok__FUc((unsigned char)40);

        if (__0this->__O3__4expr.e2) {
            if (__3at) {
                Pexpr __5e;

                __5e = __0this->__O3__4expr.e2;
                while (__3at) {
                    Pexpr __6ex;
                    Ptype __6t;

                    __6t = __3at->__O1__4expr.tp;

                    if (__6t == 0) {
                        struct ea __0__V24;

                        error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"T ofA missing for%n",
                            (const struct ea *)(((&__0__V24)->__O1__2ea.p = ((const void *)__3fn)),
                                                (&__0__V24)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    if (__5e == 0) {
                        struct ea __0__V25;

                        struct ea __0__V26;

                        error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"%tA missing for%n",
                            (const struct ea *)(((&__0__V25)->__O1__2ea.p = ((const void *)__6t)),
                                                (&__0__V25)),
                            (const struct ea *)(((&__0__V26)->__O1__2ea.p = ((const void *)__3fn)),
                                                (&__0__V26)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    if (__5e->base__4node == 140) {
                        __6ex = __5e->__O2__4expr.e1;
                        __5e = __5e->__O3__4expr.e2;
                    } else
                        __6ex = __5e;

                    if (__6ex == 0) {
                        struct ea __0__V27;

                        error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"A ofT%t missing",
                            (const struct ea *)(((&__0__V27)->__O1__2ea.p = ((const void *)__6t)),
                                                (&__0__V27)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    if (((((((__6t != __6ex->__O1__4expr.tp) && __6ex->__O1__4expr.tp) &&
                            check__4typeFP4typeUcT2(__6t, __6ex->__O1__4expr.tp, (unsigned char)0,
                                                    (unsigned char)0)) &&
                           (is_cl_obj__4typeFv(__6t) == 0)) &&
                          (eobj == 0)) &&
                         (__3m_ptr == 0)) &&
                        ((is_ptr__4typeFv(__6t) == 0) || (Mptr == 0))) {
                        fputc((int)'(', out_file);
                        {
                            bit __7oc;

                            __7oc = Cast;
                            Cast = 1;
                            print__4typeFv(__6t);
                            Cast = __7oc;
                            fputc((int)')', out_file);

                            if ((is_cl_obj__4typeFv(__6ex->__O1__4expr.tp) &&
                                 (((__6ex->base__4node != 85) && (__6ex->base__4node != 169)) ||
                                  ((((struct name *)(((struct name *)__6ex))))->n_xref__4name ==
                                   0))) &&
                                (is_ptr__4typeFv(__6t) || is_ref__4typeFv(__6t))) {
                                __6ex = address__4exprFv(__6ex);
                            }
                            if (__6ex)
                                Eprint__FP4expr(__6ex);
                        }

                    } else
                        print__4exprFv(__6ex);

                    if (__3m_ptr) {
                        __3m_ptr = 0;
                        if (__3at)
                            puttok__FUc((unsigned char)71);
                        continue;
                    }

                    __3at = __3at->__O1__4name.n_list;
                    if (__3at)
                        puttok__FUc((unsigned char)71);
                }
                if (__5e) {
                    puttok__FUc((unsigned char)71);
                    print__4exprFv(__5e);
                }
            } else
                print__4exprFv(__0this->__O3__4expr.e2);
        }
        puttok__FUc((unsigned char)41);
        if (__3comflag)
            puttok__FUc((unsigned char)41);
        break;
    }

    case 70:
        if ((__0this->__O2__4expr.e1->base__4node == 169) &&
            ((((struct name *)(((struct name *)__0this->__O2__4expr.e1))))->n_assigned_to__4name ==
             11111)) {
            Pname __3n;
            int __3argno;
            Pin __3il;

            __3n = (((struct name *)(((struct name *)__0this->__O2__4expr.e1))));
            __3argno = (((int)__3n->n_val__4name));
            __3il = curr_icall;
            for (; __3il; __3il = __3il->i_next__5iline)
                if (__3il->i_table__5iline == __3n->__O4__4expr.n_table)
                    goto akk;
            goto bkk;
        akk:
            if ((__3il->i_args__5iline[__3argno]).local__2ia == 0) {
                print__4exprFv(__0this->__O3__4expr.e2);
                break;
            }
        }

    case 62:
    case 63:
    case 60:
    case 61:
    case 59:
    case 58:
    bkk: {
        if (__0this->__O2__4expr.e1)
            Eprint__FP4expr(__0this->__O2__4expr.e1);
        puttok__FUc(__0this->base__4node);

        if ((__0this->__O2__4expr.e1->__O1__4expr.tp &&
             (__0this->__O2__4expr.e1->__O1__4expr.tp !=
              __0this->__O3__4expr.e2->__O1__4expr.tp)) &&
            (__0this->__O3__4expr.e2->base__4node != 86)) {

            Ptype __4t1;

            __4t1 = skiptypedefs__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp);
            switch (__4t1->base__4node) {
            default:
                break;
            case 125:
            case 158:
            case 110: {
                Ptype __6t2;

                __6t2 = (__0this->__O3__4expr.e2->__O1__4expr.tp
                             ? skiptypedefs__4typeFv(__0this->__O3__4expr.e2->__O1__4expr.tp)
                             : (((struct type *)0)));

                if (((__0this->__O3__4expr.e2->__O1__4expr.tp == 0) ||
                     (((((!ansi_opt) && (((struct ptr *)(((struct ptr *)__4t1))))->typ__5pvtyp) &&
                        (skiptypedefs__4typeFv(
                             (((struct ptr *)(((struct ptr *)__4t1))))->typ__5pvtyp)
                             ->base__4node == 110)) &&
                       (__0this->__O3__4expr.e2->base__4node != 191)) &&
                      (__0this->__O3__4expr.e2->base__4node != 113))) ||
                    ((((((struct ptr *)(((struct ptr *)__4t1))))->typ__5pvtyp !=
                       (((struct ptr *)(((struct ptr *)__6t2))))->typ__5pvtyp) &&
                      check__4typeFP4typeUcT2(__4t1, __6t2, (unsigned char)0, (unsigned char)0)) &&
                     (((memptr__4typeFv(__4t1) == 0) || (memptr__4typeFv(__6t2) == 0)) ||
                      check__4typeFP4typeUcT2(__4t1, __6t2, (unsigned char)78,
                                              (unsigned char)0)))) {
                    fputc((int)'(', out_file);
                    {
                        bit __7oc;

                        __7oc = Cast;
                        Cast = 1;
                        print__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp);
                        Cast = __7oc;
                        fputc((int)')', out_file);
                    }
                }
            }
            }
        }

        if (__0this->__O3__4expr.e2)
            Eprint__FP4expr(__0this->__O3__4expr.e2);
        break;
    }

    case 111:
        if (__0this->__O3__4expr.e2) {
            if (__0this->__O2__4expr.e1)
                Eprint__FP4expr(__0this->__O2__4expr.e1);
            fputc((int)'[', out_file);
            if (__0this->__O3__4expr.e2)
                Eprint__FP4expr(__0this->__O3__4expr.e2);
            fputc((int)']', out_file);
        } else {
            fputc((int)'(', out_file);
            fputc((int)'*', out_file);
            if (__0this->__O2__4expr.e1)
                Eprint__FP4expr(__0this->__O2__4expr.e1);
            fputc((int)')', out_file);
        }
        break;

    case 124: {
        static int __3level = 0;
        __3level++;
        {
            bit __3flag;

            __3flag = (((__3level > 1) && __0this->__O1__4expr.tp) &&
                       ((__0this->__O1__4expr.tp == (((struct type *)zero_type))) ||
                        memptr__4typeFv(__0this->__O1__4expr.tp)));
            if (!__3flag)
                puttok__FUc((unsigned char)73);
            if (__0this->__O2__4expr.e1)
                print__4exprFv(__0this->__O2__4expr.e1);
            if (__0this->__O3__4expr.e2) {
                puttok__FUc((unsigned char)71);
                print__4exprFv(__0this->__O3__4expr.e2);
            }
            if (!__3flag)
                puttok__FUc((unsigned char)74);
            __3level--;
            break;
        }
    }

    case 140: {
        Pexpr __3e;

        __3e = __0this;
        for (;;) {
            if (__3e->base__4node == 140) {
                print__4exprFv(__3e->__O2__4expr.e1);
                if (__3e = __3e->__O3__4expr.e2) {
                    puttok__FUc((unsigned char)71);
                } else
                    return;
            } else {
                print__4exprFv(__3e);
                return;
            }
        }
    }

    case 68: {
        Neval = 0;
        binary_val = 1;
        {
            long long __3i;

            __3i = eval__4exprFv(__0this->__O4__4expr.cond);
            binary_val = 0;
            if (Neval == 0)
                print__4exprFv(__3i ? __0this->__O2__4expr.e1 : __0this->__O3__4expr.e2);
            else {
                if (__0this->__O4__4expr.cond)
                    Eprint__FP4expr(__0this->__O4__4expr.cond);
                fputc((int)'?', out_file);
                if (!ansi_opt) {
                    if ((((__0this->__O2__4expr.e1->base__4node == 113) ||
                          (__0this->__O2__4expr.e1->base__4node == 191)) &&
                         __0this->__O2__4expr.e1->__O1__4expr.tp) &&
                        (!check__4typeFP4typeUcT2(__0this->__O2__4expr.e1->__O1__4expr.tp,
                                                  (struct type *)void_type, (unsigned char)0,
                                                  (unsigned char)0))) {
                        __0this->__O2__4expr.e1 =
                            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                                   __0this->__O2__4expr.e1->__O2__4expr.e1, zero);

                        __0this->__O2__4expr.e1->__O1__4expr.tp = (struct type *)zero_type;
                    }
                    if ((((__0this->__O3__4expr.e2->base__4node == 113) ||
                          (__0this->__O3__4expr.e2->base__4node == 191)) &&
                         __0this->__O3__4expr.e2->__O1__4expr.tp) &&
                        (!check__4typeFP4typeUcT2(__0this->__O3__4expr.e2->__O1__4expr.tp,
                                                  (struct type *)void_type, (unsigned char)0,
                                                  (unsigned char)0))) {
                        __0this->__O3__4expr.e2 =
                            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                                   __0this->__O3__4expr.e2->__O2__4expr.e1, zero);
                        __0this->__O3__4expr.e2->__O1__4expr.tp = (struct type *)zero_type;
                    }
                }
                if (__0this->__O2__4expr.e1)
                    Eprint__FP4expr(__0this->__O2__4expr.e1);
                fputc((int)':', out_file);
                if (__0this->__O3__4expr.e2)
                    Eprint__FP4expr(__0this->__O3__4expr.e2);
            }
            break;
        }
    }

    case 71:
    case 147:
        puttok__FUc((unsigned char)40);
        switch (__0this->__O2__4expr.e1->base__4node) {
        case 86:
        case 150:
        case 82:
        case 85:
        case 144:
        case 177:
        case 45:
        case 44:
        case 83:
        case 81:
            goto le2;
        case 162:
            error__FiPCc((int)'i', (const char *)"T destructor in expr::print()");
        default: {
            int __4oo;

            __4oo = addrof_cm;
            addrof_cm = 0;
            if (__0this->__O2__4expr.e1)
                Eprint__FP4expr(__0this->__O2__4expr.e1);
            addrof_cm = __4oo;
        }
            puttok__FUc((unsigned char)71);
        le2:
            if (addrof_cm) {
                switch (__0this->__O3__4expr.e2->base__4node) {
                    unsigned long __2__X32;

                case 113:
                case 191:
                    if (__0this->__O3__4expr.e2->__O3__4expr.e2)
                        switch (__0this->__O3__4expr.e2->__O3__4expr.e2->base__4node) {
                        case 71:
                        case 147:
                        case 168:
                            goto ec;
                        }
                case 85:
                case 177:
                case 45:
                case 111:
                case 44:
                case 169:
                    if ((__0this->__O3__4expr.e2->base__4node != 112) &&
                        (__0this->__O3__4expr.e2->base__4node != 145))
                        puttok__FUc((unsigned char)112);
                    addrof_cm--;
                    if (__0this->__O3__4expr.e2)
                        Eprint__FP4expr(__0this->__O3__4expr.e2);
                    addrof_cm++;
                    break;
                case 168:
                case 71:
                case 147:
                ec:
                    if (__0this->__O3__4expr.e2)
                        Eprint__FP4expr(__0this->__O3__4expr.e2);
                    break;
                case 146:
                    if (__0this->__O3__4expr.e2->__O4__4expr.fct_name &&
                        (__0this->__O3__4expr.e2->__O4__4expr.fct_name->n_oper__4name == 161)) {
                        addrof_cm--;
                        if (__0this->__O3__4expr.e2)
                            Eprint__FP4expr(__0this->__O3__4expr.e2);
                        addrof_cm++;
                        break;
                    }
                default: {
                    struct ea __0__V28;

                    error__FiPCcRC2eaN33(
                        (int)'i', (const char *)"& inlineF call (%k)",
                        (const struct ea *)((__2__X32 = __0this->__O3__4expr.e2->base__4node),
                                            (((((&__0__V28)->__O1__2ea.i = __2__X32), 0)),
                                             (&__0__V28))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                }
            } else if (__0this->__O3__4expr.e2)
                Eprint__FP4expr(__0this->__O3__4expr.e2);
            puttok__FUc((unsigned char)41);
        }
        break;

    case 112:
    case 145: {
        switch (__0this->__O3__4expr.e2->base__4node) {
        case 111:
            if (__0this->__O3__4expr.e2->__O3__4expr.e2 == 0) {
                print__4exprFv(__0this->__O3__4expr.e2->__O2__4expr.e1);
                return;
            }
            break;
        case 168:
            addrof_cm++;
            if (__0this->__O3__4expr.e2)
                Eprint__FP4expr(__0this->__O3__4expr.e2);
            addrof_cm--;
            return;
        case 70:
            if (__0this->__O3__4expr.e2)
                Eprint__FP4expr(__0this->__O3__4expr.e2);
            return;
        case 169:
        case 85: {
            Pname __5n;

            __5n = (((struct name *)(((struct name *)__0this->__O3__4expr.e2))));

            if (__5n->n_evaluated__4name) {
                __5n->n_evaluated__4name = 0;
                if ((__0this->__O3__4expr.e2->base__4node != 112) &&
                    (__0this->__O3__4expr.e2->base__4node != 145))
                    puttok__FUc((unsigned char)112);
                if (__0this->__O3__4expr.e2)
                    Eprint__FP4expr(__0this->__O3__4expr.e2);
                __5n->n_evaluated__4name = 1;
                return;
            }

            if ((__0this->__O3__4expr.e2->__O1__4expr.tp &&
                 is_cl_obj__4typeFv(__0this->__O3__4expr.e2->__O1__4expr.tp)) &&
                __5n->n_xref__4name) {
                if (__0this->__O3__4expr.e2)
                    Eprint__FP4expr(__0this->__O3__4expr.e2);
                return;
            }
            if ((!ansi_opt) &&
                (__0this->__O3__4expr.e2->__O1__4expr.tp &&
                 (skiptypedefs__4typeFv(__0this->__O3__4expr.e2->__O1__4expr.tp)->base__4node ==
                  110))) {
                if (__0this->__O3__4expr.e2)
                    Eprint__FP4expr(__0this->__O3__4expr.e2);
                return;
            }
            break;
        }
        }

        if (((__0this->__O3__4expr.e2->base__4node != 112) &&
             (__0this->__O3__4expr.e2->base__4node != 145)) &&
            ((__0this->__O3__4expr.e2->__O1__4expr.tp == 0) ||
             ((__0this->__O3__4expr.e2->__O1__4expr.tp->base__4node != 108) &&
              (__0this->__O3__4expr.e2->__O1__4expr.tp->base__4node != 76))))
            puttok__FUc((unsigned char)112);
        if (__0this->__O3__4expr.e2->__O1__4expr.tp &&
            (__0this->__O3__4expr.e2->__O1__4expr.tp->base__4node == 76))
            __0this->__O3__4expr.e2->__O1__4expr.tp = (struct type *)(((struct fct *)((
                (struct fct *)(((struct gen *)((
                                   (struct gen *)__0this->__O3__4expr.e2->__O1__4expr.tp))))
                    ->fct_list__3gen->f__9name_list->__O1__4expr.tp))));

        if (__0this->__O3__4expr.e2)
            Eprint__FP4expr(__0this->__O3__4expr.e2);
    } break;

    case 54:
    case 55:
    case 50:
    case 51:
    case 53:
    case 56:
    case 57:
    case 52:
    case 65:
    case 64:
    case 66:
    case 67:
    case 49:
    case 48:
    case 132:
    case 133:
    case 131:
    case 126:
    case 127:
    case 128:
    case 130:
    case 129:
    case 134:
    case 135:
        if (__0this->__O2__4expr.e1)
            Eprint__FP4expr(__0this->__O2__4expr.e1);

    case 172:
    case 107:
    case 46:
    case 47:
        puttok__FUc(__0this->base__4node);
        if (__0this->__O3__4expr.e2)
            Eprint__FP4expr(__0this->__O3__4expr.e2);
        break;

    case 99: /* THROW expression -- setjmp/longjmp EH */
    {
        struct expr *__3e1 = __0this->__O2__4expr.e1;
        if (!__3e1 || __3e1 == (struct expr *)dummy) {
            /* bare throw -- rethrow */
            fputs("(__cfront_rethrow(),0)", out_file);
        } else {
            const char *__2tname = "void";
            struct type *__2tp = __3e1->__O1__4expr.tp;
            while (__2tp) {
                if (__2tp->base__4node == 97) { /* BASETYPE */
                    struct name *__3bn = ((struct basetype *)__2tp)->b_name__8basetype;
                    if (__3bn && __3bn->__O2__4expr.string)
                        __2tname = __3bn->__O2__4expr.string;
                    break;
                } else if (__2tp->base__4node == 6) { /* CLASS */
                    const char *__3cn = ((struct classdef *)__2tp)->string__8classdef;
                    if (__3cn)
                        __2tname = __3cn;
                    break;
                } else if (__2tp->base__4node == 125 || __2tp->base__4node == 115) { /* PTR/RPTR */
                    __2tp = ((struct pvtyp *)__2tp)->typ__5pvtyp;
                } else {
                    break;
                }
            }
            fprintf(out_file, "(__cfront_throw(sizeof(%s),(const char *)\"%s\",(void *)(&(",
                    __2tname, __2tname);
            print__4exprFv(__3e1);
            fputs("))),0)", out_file);
        }
        break;
    }

    default: {
        struct ea __0__V29;

        struct ea __0__V30;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"%p->E::print%k",
            (const struct ea *)(((&__0__V29)->__O1__2ea.p = ((const void *)__0this)), (&__0__V29)),
            (const struct ea *)((__2__X33 = __0this->base__4node),
                                (((((&__0__V30)->__O1__2ea.i = __2__X33), 0)), (&__0__V30))),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }
}

void print_4exprFv(struct expr *__0this) { print__4exprFv(__0this); }

Pexpr aval__FP4name(Pname __1a);

Pexpr aval__FP4name(Pname __1a) {
    int __1argno;
    Pin __1il;

    __1argno = __1a->argno__4name;

    for (__1il = curr_icall; __1il; __1il = __1il->i_next__5iline)
        if (__1il->i_table__5iline == __1a->__O4__4expr.n_table)
            goto aok;
    return (struct expr *)0;
aok: {
    Pexpr __1aa;

    __1aa = (__1il->i_args__5iline[__1argno]).arg__2ia;
ll:
    switch (__1aa->base__4node) {
    case 191:
    case 113:
        __1aa = __1aa->__O2__4expr.e1;

        goto ll;
    case 169:
        return aval__FP4name(((struct name *)(((struct name *)__1aa))));
    default:
        return __1aa;
    }
}
}

static void reprint__FP9name_list(Plist __1ll);

void dcl_print__4nameFUc(struct name *__0this, TOK);

static void reprint__FP9name_list(Plist __1ll) {
    if (__1ll->l__9name_list)
        reprint__FP9name_list(__1ll->l__9name_list);
    dcl_print__4nameFUc(__1ll->f__9name_list, (unsigned char)0);
}

static struct loc csloc = {0, 0};

void putline__3locFv(struct loc *__0this);

extern int printf(const char *, ...);

struct name_list *__ct__9name_listFP4nameP9name_list(struct name_list *__0this, Pname __1ff,
                                                     Plist __1ll);

void print__4stmtFv(register struct stmt *__0this) {
    if (__0this->where__4stmt.line__3loc == 0) {
        if (csloc.line__3loc)
            putline__3locFv(&csloc);
    } else {
        csloc = __0this->where__4stmt;
        if (__0this->where__4stmt.line__3loc != last_line.line__3loc)
            if (last_ll = __0this->where__4stmt.line__3loc)
                putline__3locFv(&__0this->where__4stmt);
            else
                putline__3locFv(&last_line);
    }

    if (__0this->memtbl__4stmt && (__0this->base__4node != 116)) {
        puttok__FUc((unsigned char)73);
        {
            Ptable __2tbl;

            int __2i;
            int __2bl;

            __2tbl = __0this->memtbl__4stmt;
            __0this->memtbl__4stmt = 0;
            ;
            __2bl = 1;
            {
                {
                    Pname __2n;

                    int __2__X35;

                    int __2__X37;

                    __2n = ((__2__X37 = (__2i = 1)),
                            ((((__2__X37 <= 0) || (__2tbl->free_slot__5table <= __2__X37))
                                  ? (((struct name *)0))
                                  : (__2tbl->entries__5table[__2__X37]))));

                    for (; __2n;
                         __2n =
                             (__2n->n_tbl_list__4name
                                  ? __2n->n_tbl_list__4name
                                  : ((__2__X35 = (++__2i)),
                                     ((((__2__X35 <= 0) || (__2tbl->free_slot__5table <= __2__X35))
                                           ? (((struct name *)0))
                                           : (__2tbl->entries__5table[__2__X35])))))) {
                        if (__2n->__O1__4expr.tp == (((struct type *)any_type)))
                            continue;

                        {
                            const char *__3s;

                            Pname __3cn;

                            struct classdef *__0__X36;

                            __3s = __2n->__O2__4expr.string;
                            if ((((__3s[0]) != '_') || ((__3s[1]) != '_')) || ((__3s[2]) != 'X')) {
                                dcl_print__4nameFUc(__2n, (unsigned char)0);
                                __2bl = 0;
                            };
                            if ((__2bl && (__3cn = is_cl_obj__4typeFv(__2n->__O1__4expr.tp))) &&
                                ((__0__X36 = (((struct classdef *)((
                                      (struct classdef *)__3cn->__O1__4expr.tp))))),
                                 (__0__X36->c_dtor__8classdef)))
                                __2bl = 0;
                        }
                    }
                    if ((last_ll == 0) && (last_ll = __0this->where__4stmt.line__3loc))
                        putline__3locFv(&__0this->where__4stmt);
                    if (__2bl) {
                        Pstmt __3sl;

                        __3sl = __0this->s_list__4stmt;
                        __0this->s_list__4stmt = 0;
                        print__4stmtFv(__0this);
                        __0this->memtbl__4stmt = __2tbl;
                        puttok__FUc((unsigned char)74);
                        if (__3sl) {
                            __0this->s_list__4stmt = __3sl;
                            print__4stmtFv(__3sl);
                        }
                    } else {
                        print__4stmtFv(__0this);
                        __0this->memtbl__4stmt = __2tbl;
                        puttok__FUc((unsigned char)74);
                    }
                    return;
                }
            }
        }
    }

    switch (__0this->base__4node) {
        unsigned long __2__X38;

    default: {
        struct ea __0__V34;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"S::print(base=%k)",
            (const struct ea *)((__2__X38 = __0this->base__4node),
                                (((((&__0__V34)->__O1__2ea.i = __2__X38), 0)), (&__0__V34))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

    case 1:
        fprintf(out_file, (const char *)"asm(\"%s\");\n", ((char *)__0this->__O2__4stmt.e));

        break;

    case 118:
        dcl_print__4nameFUc(__0this->__O1__4stmt.d, (unsigned char)72);
        break;

    case 3:
    case 7:
        puttok__FUc(__0this->base__4node);
        puttok__FUc((unsigned char)72);
        break;

    case 8:
        puttok__FUc(__0this->base__4node);
        fputc((int)':', out_file);
        print__4stmtFv(__0this->s__4stmt);
        break;

    case 72: {
        Pexpr __3ee;

        __3ee = __0this->__O2__4stmt.e;
        while (__3ee && ((__3ee->base__4node == 113) || (__3ee->base__4node == 191)))
            __3ee = __3ee->__O2__4expr.e1;
        if (__3ee && (__3ee->base__4node == 124)) {
            puttok__FUc((unsigned char)72);
            break;
        }
        if (__0this->__O2__4stmt.e) {
            ;
            print__4exprFv(__0this->__O2__4stmt.e);
            if ((__0this->__O2__4stmt.e->base__4node == 168) &&
                __0this->__O2__4stmt.e->__O3__4expr.e2)
                break;
        }
        puttok__FUc((unsigned char)72);
        break;
    }

    case 39:
        puttok__FUc((unsigned char)39);
        fputc((int)'(', out_file);

        print__4exprFv(__0this->__O2__4stmt.e);

        fputc((int)')', out_file);
        if (__0this->s__4stmt->s_list__4stmt) {
            puttok__FUc((unsigned char)73);
            print__4stmtFv(__0this->s__4stmt);
            puttok__FUc((unsigned char)74);
        } else
            print__4stmtFv(__0this->s__4stmt);
        break;

    case 10:
        puttok__FUc((unsigned char)10);
        print__4stmtFv(__0this->s__4stmt);
        puttok__FUc((unsigned char)39);
        fputc((int)'(', out_file);

        print__4exprFv(__0this->__O2__4stmt.e);

        fputc((int)')', out_file);
        puttok__FUc((unsigned char)72);
        break;

    case 33:
        puttok__FUc((unsigned char)33);
        fputc((int)'(', out_file);

        print__4exprFv(__0this->__O2__4stmt.e);

        fputc((int)')', out_file);
        print__4stmtFv(__0this->s__4stmt);
        break;

    case 28:
        if (__0this->gt__4stmt) {
            print__4stmtFv(__0this->gt__4stmt);
            break;
        }
        puttok__FUc((unsigned char)28);
        if (__0this->__O2__4stmt.e) {
            if (__0this->__O1__4stmt.ret_tp &&
                (__0this->__O1__4stmt.ret_tp != __0this->__O2__4stmt.e->__O1__4expr.tp)) {
                Ptype __4tt;

                __4tt = skiptypedefs__4typeFv(__0this->__O1__4stmt.ret_tp);

                switch (__4tt->base__4node) {
                case 119:
                    break;
                case 158:
                case 125:
                    if ((((struct ptr *)(((struct ptr *)__4tt))))->typ__5pvtyp ==
                        (((struct ptr *)(((struct ptr *)__0this->__O2__4stmt.e->__O1__4expr.tp))))
                            ->typ__5pvtyp)
                        break;

                    if ((((struct ptr *)(((struct ptr *)__4tt))))->memof__3ptr)
                        break;
                default:
                    if ((__0this->__O2__4stmt.e->__O1__4expr.tp == 0) ||
                        check__4typeFP4typeUcT2(__0this->__O1__4stmt.ret_tp,
                                                __0this->__O2__4stmt.e->__O1__4expr.tp,
                                                (unsigned char)0, (unsigned char)0)) {
                        int __6oc;

                        __6oc = Cast;
                        fputc((int)'(', out_file);
                        Cast = 1;
                        print__4typeFv(__0this->__O1__4stmt.ret_tp);
                        Cast = __6oc;
                        fputc((int)')', out_file);
                    }
                }
            }
            if (__0this->__O2__4stmt.e)
                Eprint__FP4expr(__0this->__O2__4stmt.e);
        }
        puttok__FUc((unsigned char)72);
        while (__0this->s_list__4stmt && (__0this->s_list__4stmt->base__4node == 72))
            __0this->s_list__4stmt = __0this->s_list__4stmt->s_list__4stmt;
        break;

    case 4:
        puttok__FUc((unsigned char)4);
        if (__0this->__O2__4stmt.e)
            Eprint__FP4expr(__0this->__O2__4stmt.e);
        fputc((int)':', out_file);
        print__4stmtFv(__0this->s__4stmt);
        break;

    case 19:
        puttok__FUc((unsigned char)19);
        if (curr_lab)
            printf((const char *)"_%ld__", curr_lab);
        print__4nameFUc(__0this->__O1__4stmt.d, (unsigned char)0);
        puttok__FUc((unsigned char)72);
        break;

    case 115:
        if (curr_lab)
            printf((const char *)"_%ld__", curr_lab);
        print__4nameFUc(__0this->__O1__4stmt.d, (unsigned char)0);
        fputc((int)':', out_file);
        print__4stmtFv(__0this->s__4stmt);
        break;

    case 20: {
        int __3val;

        __3val = 68;
        if (__0this->__O2__4stmt.e->base__4node == 169) {
            Pname __4a;
            Pexpr __4arg;

            __4a = (((struct name *)(((struct name *)__0this->__O2__4stmt.e))));
            __4arg = aval__FP4name(__4a);

            if (__4arg)
                switch (__4arg->base__4node) {
                case 86:
                    __3val = 0;

                    break;
                case 112:
                case 145:
                    __3val = 1;

                    break;
                case 150:
                    __3val = (__4arg->__O2__4expr.i1 != 0);
                }
        }

        switch (__3val) {
        case 1:
            print__4stmtFv(__0this->s__4stmt);
            break;
        case 0:
            if (__0this->__O3__4stmt.else_stmt)
                print__4stmtFv(__0this->__O3__4stmt.else_stmt);
            else
                puttok__FUc((unsigned char)72);
            break;
        default:
            puttok__FUc((unsigned char)20);
            fputc((int)'(', out_file);

            print__4exprFv(__0this->__O2__4stmt.e);

            fputc((int)')', out_file);
            if (__0this->s__4stmt->s_list__4stmt) {
                puttok__FUc((unsigned char)73);
                print__4stmtFv(__0this->s__4stmt);
                puttok__FUc((unsigned char)74);
            } else
                print__4stmtFv(__0this->s__4stmt);
            if (__0this->__O3__4stmt.else_stmt) {
                puttok__FUc((unsigned char)12);
                if (__0this->__O3__4stmt.else_stmt->where__4stmt.line__3loc == 0) {
                    if (csloc.line__3loc)
                        putline__3locFv(&csloc);
                } else {
                    csloc = __0this->__O3__4stmt.else_stmt->where__4stmt;
                    if (__0this->__O3__4stmt.else_stmt->where__4stmt.line__3loc !=
                        last_line.line__3loc)
                        if (last_ll = __0this->__O3__4stmt.else_stmt->where__4stmt.line__3loc)
                            putline__3locFv(&__0this->__O3__4stmt.else_stmt->where__4stmt);
                        else
                            putline__3locFv(&last_line);
                }
                if (__0this->__O3__4stmt.else_stmt->s_list__4stmt) {
                    puttok__FUc((unsigned char)73);
                    print__4stmtFv(__0this->__O3__4stmt.else_stmt);
                    puttok__FUc((unsigned char)74);
                } else
                    print__4stmtFv(__0this->__O3__4stmt.else_stmt);
            }
        }
        break;
    }

    case 16: {
        int __3fi;

        __3fi = 0;
        if (__0this->__O3__4stmt.for_init) {
            __3fi = 1;
            if ((__0this->__O3__4stmt.for_init->memtbl__4stmt == 0) &&
                (__0this->__O3__4stmt.for_init->s_list__4stmt == 0))
                if (__0this->__O3__4stmt.for_init->base__4node == 72)
                    if ((__0this->__O3__4stmt.for_init->__O2__4stmt.e->base__4node != 168) ||
                        __0this->__O3__4stmt.for_init->__O2__4stmt.e->__O2__4expr.e1)
                        __3fi = 0;
        }

        if (__3fi) {
            puttok__FUc((unsigned char)73);
            print__4stmtFv(__0this->__O3__4stmt.for_init);
        }
        fputs((const char *)"for(", out_file);
        if ((__3fi == 0) && __0this->__O3__4stmt.for_init)
            print__4exprFv(__0this->__O3__4stmt.for_init->__O2__4stmt.e);
        fputc((int)';', out_file);
        if (__0this->__O2__4stmt.e)
            print__4exprFv(__0this->__O2__4stmt.e);
        fputc((int)';', out_file);
        if (__0this->__O1__4stmt.e2)
            print__4exprFv(__0this->__O1__4stmt.e2);
        puttok__FUc((unsigned char)41);
        print__4stmtFv(__0this->s__4stmt);
        if (__3fi)
            puttok__FUc((unsigned char)74);
        break;
    }

    case 166:
        if (__0this->s__4stmt && __0this->__O2__4stmt.s2) {
            puttok__FUc((unsigned char)73);
            print__4stmtFv(__0this->s__4stmt);
            print__4stmtFv(__0this->__O2__4stmt.s2);
            puttok__FUc((unsigned char)74);
        } else {
            if (__0this->s__4stmt)
                print__4stmtFv(__0this->s__4stmt);
            if (__0this->__O2__4stmt.s2)
                print__4stmtFv(__0this->__O2__4stmt.s2);
        }
        break;

    case 100: /* TRY handler -- setjmp/longjmp EH transformation */
    {
        static int __s_eh_ctr = 0;
        int __2eid;
        struct stmt *__2tbody;
        struct stmt *__2clist;
        struct stmt *__2cs;
        int __2ncatch;
        int __2i;

        __2eid = ++__s_eh_ctr;
        __2tbody = __0this->s__4stmt;
        __2clist = __2tbody ? __2tbody->s_list__4stmt : (struct stmt *)0;

        /* Disconnect catch chain from try body to avoid spurious printing */
        if (__2tbody)
            __2tbody->s_list__4stmt = (struct stmt *)0;

        /* Count catch clauses */
        __2ncatch = 0;
        {
            struct stmt *__2t = __2clist;
            while (__2t) {
                __2ncatch++;
                __2t = __2t->s_list__4stmt;
            }
        }

        /* Emit EH frame block with inline runtime declarations */
        fprintf(out_file,
                "{ /* EH try/catch */\n"
                "struct __cfront_eh_frame{long __env[64];struct __cfront_eh_frame*prev;"
                "void*exception;const char*exception_type;unsigned char exc_buf[256];};\n"
                "extern struct __cfront_eh_frame*__cfront_eh_top;\n"
                "extern void __cfront_throw(unsigned long,const char*,void*);\n"
                "extern void __cfront_rethrow(void);\n"
                "extern int __cfront_eh_match(struct __cfront_eh_frame*,const char*);\n"
                "extern int __cfront_setjmp(struct __cfront_eh_frame*);\n"
                "struct __cfront_eh_frame __ehf%d;\n"
                "__ehf%d.prev=__cfront_eh_top;\n"
                "__cfront_eh_top=&__ehf%d;\n"
                "if(__cfront_setjmp(&__ehf%d)==0){\n",
                __2eid, __2eid, __2eid, __2eid);

        /* Print try body */
        if (__2tbody)
            print__4stmtFv(__2tbody);

        /* Normal exit: pop frame */
        fprintf(out_file,
                "__cfront_eh_top=__ehf%d.prev;\n"
                "}else{\n"
                "__cfront_eh_top=__ehf%d.prev;\n",
                __2eid, __2eid);

        /* Print catch clauses */
        __2cs = __2clist;
        while (__2cs) {
            struct name *__2cv = __2cs->__O1__4stmt.d;
            struct stmt *__2cbody = __2cs->s__4stmt;
            struct stmt *__2cnext = __2cs->s_list__4stmt;

            if (!__2cv) {
                /* catch(...) -- catch all */
                fputs("{\n", out_file);
                if (__2cbody)
                    print__4stmtFv(__2cbody);
                fputs("}\n", out_file);
            } else {
                /* catch(Type var) or catch(Type& var) -- type-matched catch */
                const char *__2tname = "void";
                struct type *__2tp = __2cv->__O1__4expr.tp;
                while (__2tp) {
                    if (__2tp->base__4node == 97) { /* BASETYPE */
                        struct name *__3bn = ((struct basetype *)__2tp)->b_name__8basetype;
                        if (__3bn && __3bn->__O2__4expr.string)
                            __2tname = __3bn->__O2__4expr.string;
                        break;
                    } else if (__2tp->base__4node == 6) { /* CLASS */
                        const char *__3cn = ((struct classdef *)__2tp)->string__8classdef;
                        if (__3cn)
                            __2tname = __3cn;
                        break;
                    } else if (__2tp->base__4node == 125 ||
                               __2tp->base__4node == 115) { /* PTR/RPTR */
                        __2tp = ((struct pvtyp *)__2tp)->typ__5pvtyp;
                    } else {
                        break;
                    }
                }
                fprintf(out_file, "if(__cfront_eh_match(&__ehf%d,(const char*)\"%s\")){\n", __2eid,
                        __2tname);
                /* Emit catch variable: pointer into EH frame exception */
                if (__2cv->__O2__4expr.string) {
                    fprintf(out_file, "%s*%s=(%s*)__ehf%d.exception;\n", __2tname,
                            __2cv->__O2__4expr.string, __2tname, __2eid);
                }
                /* Print catch body (case 116 emits its own {}) */
                if (__2cbody)
                    print__4stmtFv(__2cbody);
                /* Open else for next catch or emit rethrow for last */
                if (__2cnext)
                    fputs("}else{\n", out_file);
                else
                    fputs("}else{__cfront_rethrow();}\n", out_file);
            }
            __2cs = __2cnext;
        }

        if (!__2clist)
            fputs("__cfront_rethrow();\n", out_file);

        /* Close N-1 accumulated else blocks + outer else + frame block */
        for (__2i = 0; __2i < __2ncatch - 1; __2i++)
            fputs("}\n", out_file);
        fputs("}\n}\n", out_file);

        /* Restore catch chain */
        if (__2tbody)
            __2tbody->s_list__4stmt = __2clist;

        /* Print next statement in sequence */
        if (__0this->s_list__4stmt)
            print__4stmtFv(__0this->s_list__4stmt);
        break;
    }

    case 116:
        puttok__FUc((unsigned char)73);

        if (__0this->__O1__4stmt.d)
            dcl_print__4nameFUc(__0this->__O1__4stmt.d, (unsigned char)72);
        if (__0this->memtbl__4stmt && __0this->__O2__4stmt.own_tbl) {
            Pname __3n;
            int __3i;
            Plist __3aglist;

            struct table *__0__X39;

            int __2__X40;

            struct table *__0__X41;

            int __2__X42;

            __3aglist = 0;
            for (__3n = ((__0__X39 = __0this->memtbl__4stmt),
                         ((__2__X40 = (__3i = 1)),
                          ((((__2__X40 <= 0) || (__0__X39->free_slot__5table <= __2__X40))
                                ? (((struct name *)0))
                                : (__0__X39->entries__5table[__2__X40])))));
                 __3n;
                 __3n = (__3n->n_tbl_list__4name
                             ? __3n->n_tbl_list__4name
                             : ((__0__X41 = __0this->memtbl__4stmt),
                                ((__2__X42 = (++__3i)),
                                 ((((__2__X42 <= 0) || (__0__X41->free_slot__5table <= __2__X42))
                                       ? (((struct name *)0))
                                       : (__0__X41->entries__5table[__2__X42]))))))) {

                ;
                if ((__3n->__O1__4expr.tp && (__3n->n_anon__4name == 0)) &&
                    (__3n->__O1__4expr.tp != (((struct type *)any_type))))
                    switch (__3n->n_scope__4name) {
                    case 139:
                    case 136:
                        break;
                    default:
                        if (((__3n->base__4node == 123) && __3n->__O3__4expr.tpdef) &&
                            __3n->__O3__4expr.tpdef->nested_sig__4type)
                            continue;
                        if ((ansi_opt == 0) || (!__3n->__O3__4expr.n_initializer))
                            dcl_print__4nameFUc(__3n, (unsigned char)0);
                        else
                            __3aglist = __ct__9name_listFP4nameP9name_list((struct name_list *)0,
                                                                           __3n, __3aglist);
                    }
            }
            if (__3aglist)
                reprint__FP9name_list(__3aglist);

            if (((last_ll == 0) && __0this->s__4stmt) &&
                (last_ll = __0this->s__4stmt->where__4stmt.line__3loc))
                putline__3locFv(&__0this->s__4stmt->where__4stmt);
        }

        if (__0this->s__4stmt)
            print__4stmtFv(__0this->s__4stmt);
        if (__0this->__O3__4stmt.where2.line__3loc == 0) {
            if (csloc.line__3loc)
                putline__3locFv(&csloc);
        } else {
            csloc = __0this->__O3__4stmt.where2;
            if (__0this->__O3__4stmt.where2.line__3loc != last_line.line__3loc)
                if (last_ll = __0this->__O3__4stmt.where2.line__3loc)
                    putline__3locFv(&__0this->__O3__4stmt.where2);
                else
                    putline__3locFv(&last_line);
        }
        fputs((const char *)"}\n", out_file);
        if (last_ll && __0this->where__4stmt.line__3loc)
            last_line.line__3loc++;
    }
    }

    if (__0this->s_list__4stmt)
        print__4stmtFv(__0this->s_list__4stmt);
}

void print_4stmtFv(struct stmt *__0this) { print__4stmtFv(__0this); }
struct ptbl_rec;

static char *ptbl_name;
static struct ptbl_rec *ptbl_rec_lookup_head = 0;
static struct ptbl_rec *ptbl_rec_pair_head = 0;

extern char *st_name__FPCc(const char *);

struct ptbl_rec { /* sizeof ptbl_rec == 24 */
    char *pname__8ptbl_rec;
    char *vname__8ptbl_rec;
    struct ptbl_rec *next__8ptbl_rec;
};

extern int strcmp(const char *, const char *);

void ptbl_init__Fi(int __1flag) {
    if (!__1flag) {
        char *__2p;

        __2p = st_name__FPCc((const char *)"__ptbl_vec__");
        ptbl_name =
            (((char *)__nw__FUl((size_t)((sizeof(char)) * (strlen((const char *)__2p) + 1)))));
        strcpy(ptbl_name, (const char *)__2p);
        __dl__FPv((void *)__2p);
        {
            struct loc __2old;

            __2old = curloc;
            curloc.file__3loc = 0;
            curloc.line__3loc = 1;
            putline__3locFv(&curloc);
            curloc = __2old;
            fprintf(out_file, (const char *)"extern struct __mptr* %s[];\n", ptbl_name);
            if (last_ll)
                last_line.line__3loc++;
        }
    } else {
        struct ptbl_rec *__2r;

        struct ptbl_rec *__2p;

        __2p = ptbl_rec_lookup_head;
        if (__2p == 0)
            return;
        fprintf(out_file, (const char *)"struct __mptr* %s[] = {\n", ptbl_name);
        if (last_ll)
            last_line.line__3loc++;
        while (__2p != 0) {
            __2r = ptbl_rec_pair_head;
            while (__2r && strcmp((const char *)__2r->pname__8ptbl_rec,
                                  (const char *)__2p->pname__8ptbl_rec))
                __2r = __2r->next__8ptbl_rec;

            fprintf(out_file, (const char *)"%s,\n", __2r->vname__8ptbl_rec);
            if (last_ll)
                last_line.line__3loc++;
            __2p = __2p->next__8ptbl_rec;
        }
        fprintf(out_file, (const char *)"\n};\n");
        if (last_ll)
            last_line.line__3loc += 2;
    }
}

void ptbl_init_Fi(int __1flag) { ptbl_init__Fi(__1flag); }

extern int sprintf(char *, const char *, ...);

char *ptbl_lookup__FPCc(const char *__1name) {
    struct ptbl_rec *__1r;

    struct ptbl_rec *__1s;

    struct ptbl_rec *__1p;
    int __1i;

    __1p = ptbl_rec_lookup_head;
    __1i = 0;

    while (__1p && strcmp(__1name, (const char *)__1p->pname__8ptbl_rec)) {
        __1r = __1p;
        __1p = __1p->next__8ptbl_rec;
        __1i++;
    }

    if (__1p == 0) {
        __1s = (((struct ptbl_rec *)__nw__FUl(sizeof(struct ptbl_rec))));
        __1s->pname__8ptbl_rec =
            (((char *)__nw__FUl((size_t)((sizeof(char)) * (strlen(__1name) + 1)))));

        __1s->vname__8ptbl_rec = 0;
        __1s->next__8ptbl_rec = 0;
        strcpy(__1s->pname__8ptbl_rec, __1name);
        if (ptbl_rec_lookup_head == 0)
            ptbl_rec_lookup_head = __1s;
        else
            __1r->next__8ptbl_rec = __1s;
    }

    {
        char *__1pp;

        __1pp = ((
            (char *)__nw__FUl((size_t)((sizeof(char)) * (strlen((const char *)ptbl_name) + 10)))));
        sprintf(__1pp, (const char *)"%s[%d]", ptbl_name, __1i);
        return __1pp;
    }
}

void ptbl_add_pair__FPCcT1(const char *__1ptbl, const char *__1vtbl) {
    struct ptbl_rec *__1p;

    __1p = (((struct ptbl_rec *)__nw__FUl(sizeof(struct ptbl_rec))));

    __1p->pname__8ptbl_rec =
        (((char *)__nw__FUl((size_t)((sizeof(char)) * (strlen(__1ptbl) + 1)))));

    strcpy(__1p->pname__8ptbl_rec, __1ptbl);
    __1p->vname__8ptbl_rec =
        (((char *)__nw__FUl((size_t)((sizeof(char)) * (strlen(__1vtbl) + 1)))));

    strcpy(__1p->vname__8ptbl_rec, __1vtbl);
    __1p->next__8ptbl_rec = ptbl_rec_pair_head;

    ptbl_rec_pair_head = __1p;
}

void ptbl_add_pair_FPCcT1(const char *__1ptbl, const char *__1vtbl) {
    ptbl_add_pair__FPCcT1(__1ptbl, __1vtbl);
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
