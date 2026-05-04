
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

bit TCast = 0;
bit Cast = 0;
int last_ll = 1;
Pin curr_icall = 0;
char emode = 0;
int ntok = 0;
bit mk_zero_init_flag = 0;

static int MAIN;

static Ptable mem_table;
static Ptable perm_table;
static int mem_depth;
extern int dem_opt_mem;
extern int dem_opt_local;

extern int strncmp(const char *, const char *, size_t);

int ispt_data__FP4name(Pname __1n) {
    if ((((!__1n->__O1__4expr.tp) || (!__1n->__O4__4expr.n_table)) ||
         (!__1n->__O4__4expr.n_table->t_name__5table)) ||
        (!__1n->__O4__4expr.n_table->t_name__5table->__O1__4expr.tp))
        return 0;
    {
        const char *__1s;

        __1s = (((struct classdef *)((
                    (struct classdef *)__1n->__O4__4expr.n_table->t_name__5table->__O1__4expr.tp))))
                   ->string__8classdef;
        while ((*__1s)) {
            if (!strncmp(__1s, (const char *)"__pt__", (unsigned long)6))
                return 1;
            __1s++;
        }
        return 0;
    }
}

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

static void begin_mem__Fv(void) {
    if (!dem_opt_mem)
        return;
    if (!(mem_depth++))
        mem_table = __ct__5tableFsP5tableP4name((struct table *)0, (short)16, (struct table *)0,
                                                (struct name *)0);
}

void __dt__5tableFv(struct table *__0this, int);

static void end_mem__Fv(void) {
    if (!dem_opt_mem)
        return;
    if (!(--mem_depth)) {
        __dt__5tableFv(mem_table, 3);
        mem_table = 0;
    }
}

extern int sprintf(char *, const char *, ...);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

static int dem_mem__FPCcT1(const char *__1cn, const char *__1mn) {
    char __1buf[1024];
    Pname __1n;

    if ((((!__1cn) || (!__1mn)) || (!((*__1cn)))) || (!((*__1mn))))
        error__FiPCc((int)'i', (const char *)"invalidA to dem_mem()");

    sprintf((char *)__1buf, (const char *)"%s__%s", __1cn, __1mn);

    if (mem_table) {
        if (look__5tableFPCcUc(mem_table, __1mn, (unsigned char)0)) {
            if (!perm_table)
                perm_table = __ct__5tableFsP5tableP4name((struct table *)0, (short)16,
                                                         (struct table *)0, (struct name *)0);
            __1n = __ct__4nameFPCc((struct name *)0, (const char *)__1buf);
            insert__5tableFP4nameUc(perm_table, __1n, (unsigned char)0);
            ((__1n ? (((void)(__1n ? (((void)((((((struct expr *)__1n))
                                                    ? (((void)((((struct expr *)__1n))
                                                                   ? (((void)(((void)0))))
                                                                   : (((void)0)))))
                                                    : (((void)0)))),
                                              (((void)__dl__4nameSFPvUl(
                                                  (void *)__1n, (size_t)(sizeof(struct name))))))))
                                   : (((void)0)))))
                   : (((void)0))));
            return 0;
        } else {
            __1n = __ct__4nameFPCc((struct name *)0, __1mn);
            insert__5tableFP4nameUc(mem_table, __1n, (unsigned char)0);
            ((__1n ? (((void)(__1n ? (((void)((((((struct expr *)__1n))
                                                    ? (((void)((((struct expr *)__1n))
                                                                   ? (((void)(((void)0))))
                                                                   : (((void)0)))))
                                                    : (((void)0)))),
                                              (((void)__dl__4nameSFPvUl(
                                                  (void *)__1n, (size_t)(sizeof(struct name))))))))
                                   : (((void)0)))))
                   : (((void)0))));
            return 1;
        }
    } else {
        return ((!perm_table) ||
                (!look__5tableFPCcUc(perm_table, (const char *)__1buf, (unsigned char)0)));
    }
}

extern int fputs(const char *__0s, void *__0stream);

void putline__3locFv(struct loc *__0this);

extern int fputc(int, void *);

void puttok__FUc(TOK __1t) {
    fputs(keys[__1t], out_file);

    if (12 < (ntok++)) {
        ntok = 0;
        if (emode == 0)
            putline__3locFv(&last_line);
    } else if (__1t == 72) {
        ntok = 0;
        fputc((int)'\n', out_file);
        if (last_ll)
            last_line.line__3loc++;
    } else
        fputc((int)' ', out_file);
}
struct dcl_buf;

struct dcl_buf { /* sizeof dcl_buf == 392 */

    Pbase b__7dcl_buf;
    Pname n__7dcl_buf;
    TOK left__7dcl_buf[20];

    TOK right__7dcl_buf[20];
    Pnode rnode__7dcl_buf[20];
    Pclass lnode__7dcl_buf[20];
    int li__7dcl_buf;

    int ri__7dcl_buf;
    bit cf__7dcl_buf;
};

static struct dcl_buf *tbufvec[10] = {((struct dcl_buf *)0)};

static struct dcl_buf *tbuf = 0;

static int freetbuf = 0;

void dcl_print__8basetypeFv(struct basetype *__0this);

extern int fprintf(void *, const char *, ...);

void print__4nameFUc(struct name *__0this, bit __1fullprint);

void print__4exprFv(struct expr *__0this);

void dcl_print__3fctFv(struct fct *__0this);

extern void print_body__FP3fct(Pfct);

void put__7dcl_bufFv(register struct dcl_buf *__0this) {
    int __1i;
    Pfct __1ff;

    const void *__2__X27;

    __1ff = 0;

    if ((20 <= __0this->li__7dcl_buf) || (20 <= __0this->ri__7dcl_buf))
        error__FiPCc((int)'i', (const char *)"T buffer overflow");

    if (((__0this->n__7dcl_buf && __0this->n__7dcl_buf->n_sto__4name) &&
         (__0this->n__7dcl_buf->n_sto__4name != 27)) &&
        (__0this->n__7dcl_buf->n_sto__4name != 2))
        puttok__FUc(__0this->n__7dcl_buf->n_sto__4name);

    if (__0this->b__7dcl_buf == 0) {
        struct ea __0__V26;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"noBT%s",
            (const struct ea *)((__2__X27 = (const void *)(Cast ? " in cast" : (((char *)"")))),
                                (((&__0__V26)->__O1__2ea.p = __2__X27), (&__0__V26))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    } else {
        bit __2ac_save;
        if (__0this->cf__7dcl_buf) {
            __2ac_save = __0this->b__7dcl_buf->ansi_const__4type;
            __0this->b__7dcl_buf->ansi_const__4type = 1;
        }
        dcl_print__8basetypeFv(__0this->b__7dcl_buf);
        if (__0this->cf__7dcl_buf)
            __0this->b__7dcl_buf->ansi_const__4type = __2ac_save;
    }

    for (; __0this->li__7dcl_buf; __0this->li__7dcl_buf--) {
        switch (__0this->left__7dcl_buf[__0this->li__7dcl_buf]) {
        case 40:
            fputc((int)'(', out_file);
            break;
        case 125:
            fputc((int)'*', out_file);
            break;
        case 158:
            if (emode)
                fputc((int)'&', out_file);
            else
                fputc((int)'*', out_file);
            break;
        case 163:
            if (emode || (ansi_opt && (Cast == 0)))
                fputs((const char *)"*const ", out_file);
            else
                fputc((int)'*', out_file);
            break;
        case 164:
            if (emode)
                fputs((const char *)"&const ", out_file);
            else if (ansi_opt && (Cast == 0))
                fputs((const char *)"*const ", out_file);
            else
                fputc((int)'*', out_file);
            break;
        case 173:
            if (__0this->lnode__7dcl_buf[__0this->li__7dcl_buf])
                fprintf(out_file, (const char *)"%s::",
                        (__0this->lnode__7dcl_buf[__0this->li__7dcl_buf])->string__8classdef);
        }
    }

    if (__0this->n__7dcl_buf)
        print__4nameFUc(__0this->n__7dcl_buf, (unsigned char)0);

    for (__1i = 1; __1i <= __0this->ri__7dcl_buf; __1i++) {
        switch (__0this->right__7dcl_buf[__1i]) {
        case 41:
            fputc((int)')', out_file);
            break;
        case 110:
            fputc((int)'[', out_file);
            {
                Pvec __4v;
                Pexpr __4d;
                int __4s;

                __4v = (((struct vec *)(((struct vec *)(__0this->rnode__7dcl_buf[__1i])))));
                __4d = __4v->dim__3vec;
                __4s = __4v->size__3vec;
                if (__4d)
                    print__4exprFv(__4d);
                if (__4s)
                    fprintf(out_file, (const char *)"%d", __4s);
            }
            fputc((int)']', out_file);
            break;
        case 108: {
            Pfct __4f;

            __4f = (((struct fct *)(((struct fct *)(__0this->rnode__7dcl_buf[__1i])))));
            if (__4f->body__3fct)
                __1ff = __4f;
            dcl_print__3fctFv(__4f);
            break;
        }
        case 114: {
            Pbase __4f;
            Pexpr __4d;
            int __4s;

            __4f = (((struct basetype *)(((struct basetype *)(__0this->rnode__7dcl_buf[__1i])))));
            __4d = (((struct expr *)(((struct expr *)__4f->b_name__8basetype))));
            __4s = __4f->b_bits__8basetype;
            fputc((int)':', out_file);
            if (__4d)
                print__4exprFv(__4d);
            else if (__4s)
                fprintf(out_file, (const char *)"%d", __4s);
            else
                puttok__FUc((unsigned char)86);
            break;
        }
        }
    };
    if (__1ff && (emode == 0))
        print_body__FP3fct(__1ff);
}

Pexpr mk_zero_init__FP4typeP4nameT2(Ptype __1tt, Pname __1obname, Pname __1currname);

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

Pfct memptr__4typeFv(struct type *__0this);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

Pexpr mk_zero_init__FP4typeP4nameT2(Ptype __1tt, Pname __1obname, Pname __1currname) {
    if (dtpt_opt && mk_zero_init_flag)
        return (struct expr *)0;

    __1tt = skiptypedefs__4typeFv(__1tt);

    switch (__1tt->base__4node) {
    case 110: {
        if ((__1obname == __1currname) && (!ispt_data__FP4name(__1obname))) {
            return (struct expr *)0;
        } else {
            Pexpr __4i;

            __4i = mk_zero_init__FP4typeP4nameT2(
                (((struct vec *)(((struct vec *)__1tt))))->typ__5pvtyp, __1obname, __1currname);
            if (__4i == 0)
                return (struct expr *)0;
            return __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)124, __4i,
                                          (struct expr *)0);
        }
    }
    case 119: {
        Pclass __3cl;

        __3cl = (((struct classdef *)((
            (struct classdef *)(((struct basetype *)(((struct basetype *)__1tt))))
                ->b_name__8basetype->__O1__4expr.tp))));
        if ((!ansi_opt) && ((__3cl->csu__8classdef == 167) || (__3cl->csu__8classdef == 36))) {
            if (warning_opt) {
                Ptype __5tn;

                __5tn = __1obname->__O1__4expr.tp;
                for (;;)
                    if (__5tn->base__4node == 110)
                        __5tn = (((struct vec *)(((struct vec *)__5tn))))->typ__5pvtyp;
                    else
                        break;
                if ((__1obname == __1currname) && (__1tt == __5tn)) {
                    if (((__3cl->string__8classdef[0]) == '_') &&
                        ((__3cl->string__8classdef[1]) == '_')) {
                        struct ea __0__V28;

                        error__FiP3locPCcRC2eaN34(
                            (int)'w', &__1obname->where__4name,
                            (const char *)"cannot generate zeroIr for%n ofT union; toI, compile "
                                          "with +a1 or insert non-union object as first member",
                            (const struct ea *)(((&__0__V28)->__O1__2ea.p =
                                                     ((const void *)__1obname)),
                                                (&__0__V28)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else {
                        struct ea __0__V29;

                        struct ea __0__V30;

                        error__FiP3locPCcRC2eaN34(
                            (int)'w', &__1obname->where__4name,
                            (const char *)"cannot generate zeroIr for%n ofT%t; toI, compile with "
                                          "+a1 or insert non-union object as first member",
                            (const struct ea *)(((&__0__V29)->__O1__2ea.p =
                                                     ((const void *)__1obname)),
                                                (&__0__V29)),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V30, (const void *)__1obname->__O1__4expr.tp),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                } else {
                    Pclass __6cx;
                    if ((((__5tn->base__4node == 119) &&
                          (__6cx = (((struct classdef *)((
                               (struct classdef *)(((struct basetype *)((
                                                       (struct basetype *)__5tn))))
                                   ->b_name__8basetype->__O1__4expr.tp)))))) &&
                         ((__6cx->string__8classdef[0]) == '_')) &&
                        ((__6cx->string__8classdef[1]) == '_')) {
                        struct ea __0__V31;

                        error__FiP3locPCcRC2eaN34(
                            (int)'w', &__1obname->where__4name,
                            (const char *)"cannot generate zeroIr for%n (union or aggregate with "
                                          "union as first element); toI, compile with +a1 or "
                                          "insert non-union object as first member",
                            (const struct ea *)(((&__0__V31)->__O1__2ea.p =
                                                     ((const void *)__1obname)),
                                                (&__0__V31)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else {
                        struct ea __0__V32;

                        struct ea __0__V33;

                        error__FiP3locPCcRC2eaN34(
                            (int)'w', &__1obname->where__4name,
                            (const char *)"cannot generate zeroIr for%n ofT%t (union or aggregate "
                                          "with union as first element); toI, compile with +a1 or "
                                          "insert non-union object as first member",
                            (const struct ea *)(((&__0__V32)->__O1__2ea.p =
                                                     ((const void *)__1obname)),
                                                (&__0__V32)),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V33, (const void *)__1obname->__O1__4expr.tp),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
            }
            return (struct expr *)0;
        }
        {
            Pbcl __3l;

            __3l = __3cl->baselist__8classdef;
            while (__3l) {
                if (__3l->base__4node == 85)
                    __3cl = __3l->bclass__6basecl;
                else
                    return __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)124, zero,
                                                  (struct expr *)0);
                __3l = __3cl->baselist__8classdef;
            }
            {
                int __3i;
                Pname __3nn;

                struct table *__0__X34;

                int __2__X35;

                struct table *__0__X36;

                __3i = 1;
                __3nn = ((__0__X36 = __3cl->memtbl__8classdef),
                         ((((__3i <= 0) || (__0__X36->free_slot__5table <= __3i))
                               ? (((struct name *)0))
                               : (__0__X36->entries__5table[__3i]))));
                for (; __3nn;
                     __3nn =
                         (__3nn->n_tbl_list__4name
                              ? __3nn->n_tbl_list__4name
                              : ((__0__X34 = __3cl->memtbl__8classdef),
                                 ((__2__X35 = (++__3i)),
                                  ((((__2__X35 <= 0) || (__0__X34->free_slot__5table <= __2__X35))
                                        ? (((struct name *)0))
                                        : (__0__X34->entries__5table[__2__X35]))))))) {
                    if ((__3nn->base__4node == 123) || (__3nn->__O1__4expr.tp == 0))
                        continue;
                    {
                        Ptype __4tx;

                        __4tx = skiptypedefs__4typeFv(__3nn->__O1__4expr.tp);
                        if ((((((((__3nn->base__4node == 85) && (__3nn->n_anon__4name == 0)) &&
                                 (__4tx->base__4node != 108)) &&
                                (__4tx->base__4node != 76)) &&
                               (__4tx->base__4node != 6)) &&
                              (__4tx->base__4node != 13)) &&
                             (__3nn->n_stclass__4name != 31)) &&
                            (__3nn->n_stclass__4name != 13)) {
                            Pexpr __5i;

                            __5i = mk_zero_init__FP4typeP4nameT2(__4tx, __1obname, __3nn);
                            if (__5i == 0)
                                return (struct expr *)0;
                            return __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)124,
                                                          __5i, (struct expr *)0);
                        }
                    }
                }
                return (struct expr *)0;
            }
        }
    }
    case 125:
        if (memptr__4typeFv(__1tt)) {
            Pexpr __3i;

            __3i = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, zero, zero);
            return __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)124, __3i, zero);
        }

    case 158:
    case 5:
    case 29:
    case 21:
    case 121:
    case 22:
    case 122:
    case 15:
    case 11:
    case 181:
    case 114:
    case 141:
        return zero;
    }
    return (struct expr *)0;
}

void dcl_print__4typeFP4name(struct type *__0this, Pname);

void arg_print__3fctFv(register struct fct *__0this) {
    fputc((int)'(', out_file);
    {
        {
            Pname __1nn;

            __1nn = __0this->argtype__3fct;

            for (; __1nn;) {
                dcl_print__4typeFP4name(__1nn->__O1__4expr.tp, (struct name *)0);
                if (__1nn = __1nn->__O1__4name.n_list)
                    puttok__FUc((unsigned char)71);
                else
                    break;
            }
            switch (__0this->nargs_known__3fct) {
            case 0:
            case 155:
                puttok__FUc((unsigned char)155);

                break;
            }

            fputc((int)')', out_file);

            if (__0this->f_const__3fct)
                puttok__FUc((unsigned char)26);
            if (__0this->f_static__3fct)
                puttok__FUc((unsigned char)31);
        }
    }
}

Ptype skiptypedefs__4typeFRUc(struct type *__0this, bit *__1isconst);

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

void dcl_print__7enumdefFP4name(struct enumdef *__0this, Pname);

extern void make_res__FP3fct(Pfct);

extern int strcmp(const char *, const char *);

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

void print_all_vtbls__8classdefFP8classdef(struct classdef *__0this, Pclass);

void dcl_print__4nameFUc(struct name *__0this, TOK __1list);

Pname is_cl_obj__4typeFv(struct type *__0this);

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

void print__4typeFv(struct type *__0this);

extern void Eprint__FP4expr(Pexpr);

bit is_unsigned__4typeFv(struct type *__0this);

void dcl_print__4nameFUc(register struct name *__0this, TOK __1list) {
    if (error_count)
        return;

    if (__0this->n_stclass__4name == 31)
        __0this->__O1__4expr.tp->ansi_const__4type = 1;

    {
        {
            Pname __1n;

            __1n = __0this;

            for (; __1n; __1n = __1n->__O1__4name.n_list) {
                Ptype __2t;
                int __2sm;

                __2t = __1n->__O1__4expr.tp;
                __2sm = 0;

                if (__2t == 0) {
                    struct ea __0__V37;

                    error__FiPCcRC2eaN33(
                        (int)'i', (const char *)"N::dcl_print(%n)T missing",
                        (const struct ea *)(((&__0__V37)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V37)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                if (__1n->n_stclass__4name == 13)
                    if (__1list)
                        continue;
                    else
                        return;

                if ((__1n->where__4name.line__3loc != last_line.line__3loc) ||
                    (__1n->where__4name.file__3loc != last_line.file__3loc))
                    if (last_ll = __1n->where__4name.line__3loc)
                        putline__3locFv(&__1n->where__4name);
                    else
                        putline__3locFv(&last_line);

                {
                    bit __2tc;
                    Ptype __2tt;

                    __2tc = 0;
                    __2tt = skiptypedefs__4typeFRUc(__2t, (bit *)(&__2tc));

                    switch (__2t->base__4node) {
                    case 6:
                        if (__1n->base__4node != 123) {
                            dcl_print__8classdefFP4name(
                                ((struct classdef *)(((struct classdef *)__2t))), __1n);
                        }
                        __2sm = 1;
                        break;

                    case 13:
                        dcl_print__7enumdefFP4name(((struct enumdef *)(((struct enumdef *)__2t))),
                                                   (struct name *)0);
                        __2sm = 1;
                        break;

                    case 108: {
                        Pfct __4f;

                        int __1__Xt00a3w1ovbwvcnm;

                        __4f = (((struct fct *)(((struct fct *)__2t))));

                        if ((((((dtpt_opt && (all_flag == 0)) &&
                                (curloc.file__3loc != first_file)) &&
                               (__4f->f_inline__3fct == 0)) &&
                              (__4f->f_is_inline__3fct == 0)) &&
                             (!((__1n->n_sto__4name == 31) && (!__1n->n_stclass__4name)))) &&
                            (none_flag == 0))
                            __4f->body__3fct = 0;

                        if (((__1__Xt00a3w1ovbwvcnm =
                                  ((__2t->base__4node == 108)
                                       ? (((struct fct *)(((struct fct *)__2t))))->fct_base__3fct
                                       : ((__2t->base__4node == 6)
                                              ? (((struct classdef *)(((struct classdef *)__2t))))
                                                    ->class_base__8classdef
                                              : (((int)0))))),
                             (((unsigned char)((__1__Xt00a3w1ovbwvcnm == 4) ||
                                               (__1__Xt00a3w1ovbwvcnm == 5))))) &&
                            (current_fct_instantiation != __4f)) {
                            if (((__1n->n_addr_taken__4name == 1) &&
                                 (current_fct_instantiation == 0)) &&
                                (__4f->f_inline__3fct || __4f->last_expanded__3fct))
                                ;
                            else
                                return;
                        }

                        if (__1n->base__4node == 123)
                            puttok__FUc((unsigned char)35);

                        if ((__1n->n_dcl_printed__4name == 2) ||
                            ((__1n->n_dcl_printed__4name == 1) && (__4f->body__3fct == 0))) {
                            __2sm = 1;
                            break;
                        }

                        if (__4f->f_result__3fct == 0)
                            make_res__FP3fct(__4f);

                        if (__4f->body__3fct && (__1n->n_sto__4name == 14))
                            __1n->n_sto__4name = 0;

                        if (__4f->f_inline__3fct &&
                            ((__1n->__O4__4expr.n_table != gtbl) ||
                             strcmp(__1n->__O2__4expr.string, (const char *)"main"))) {
                            if (debug_opt) {
                                if (((__4f->defined__4type & 01) && (__4f->defined__4type & 02)) &&
                                    (__4f->f_inline__3fct != 77))
                                    goto prnt_def;
                                else if (__1n->n_dcl_printed__4name == 0)
                                    goto prnt_dcl;
                                else {
                                    __2sm = 1;
                                    break;
                                }
                            }
                            if (__4f->f_virtual__3fct || __1n->n_addr_taken__4name) {
                            prnt_dcl: {
                                TOK __6st;
                                Pblock __6b;

                                __6st = __1n->n_sto__4name;
                                __6b = __4f->body__3fct;
                                __4f->body__3fct = 0;
                                dcl_print__4typeFP4name(__2t, __1n);
                                __1n->n_dcl_printed__4name = 1;
                                __1n->n_sto__4name = __6st;
                                __4f->body__3fct = __6b;
                                break;
                            }
                            } else
                                __2sm = 1;
                        } else if (((__4f->defined__4type & 01) == 0) ||
                                   ((__4f->defined__4type & 02) == 0))
                            goto prnt_dcl;
                        else if ((__1n->__O4__4expr.n_table == gtbl) &&
                                 (strcmp(__1n->__O2__4expr.string, (const char *)"main") == 0)) {
                            struct name *__0__X38;

                            if (__4f->f_inline__3fct) {
                                error__FP3locPCcRC2eaN33(
                                    &__1n->where__4name,
                                    (const char *)"main() cannot be declared inline",
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                __4f->f_inline__3fct = 0;
                                __1n->n_sto__4name = 0;
                            }
                            if (__1n->n_sto__4name == 31) {
                                error__FP3locPCcRC2eaN33(
                                    &__1n->where__4name,
                                    (const char *)"main() cannot be declared static",
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                __1n->n_sto__4name = 0;
                            }
                            MAIN = 1;
                            ((__0__X38 =
                                  look__5tableFPCcUc(gtbl, (const char *)"main", (unsigned char)0)),
                             ((__0__X38->n_used__4name++), (((void)0))));
                            __4f->f_signature__3fct = 0;
                            dcl_print__4typeFP4name(__2t, __1n);
                            __1n->n_dcl_printed__4name = (__4f->body__3fct ? 2 : 1);
                            MAIN = 0;
                        } else {
                        prnt_def:
                            if ((__1n->n_oper__4name == 161) || (__1n->n_oper__4name == 162)) {
                                Pclass __6cl;

                                __6cl = (((struct classdef *)((
                                    (struct classdef *)__1n->__O4__4expr.n_table->t_name__5table
                                        ->__O1__4expr.tp))));
                                if (__6cl->c_body__8classdef == 3)
                                    print_all_vtbls__8classdefFP8classdef(__6cl, __6cl);
                            }

                            if (((__1n->n_sto__4name == 31) && (pdef_name == 0)) &&
                                (def_name == 0)) {
                                pdef_name = __1n;
                                if (last_ll = __1n->where__4name.line__3loc)
                                    putline__3locFv(&__1n->where__4name);
                                else
                                    putline__3locFv(&last_line);
                            }
                            dcl_print__4typeFP4name(__2t, __1n);
                            __1n->n_dcl_printed__4name = (__4f->body__3fct ? 2 : 1);
                        }
                        if (__4f->body__3fct)
                            __2sm = 1;
                        break;
                    }

                    case 76: {
                        {
                            {
                                Plist __4gl;

                                __4gl = (((struct gen *)(((struct gen *)__2t))))->fct_list__3gen;

                                for (; __4gl; __4gl = __4gl->l__9name_list) {
                                    Pname __5nn;
                                    Pfct __5f;

                                    __5nn = __4gl->f__9name_list;
                                    __5f =
                                        (((struct fct *)(((struct fct *)__5nn->__O1__4expr.tp))));
                                    if (__5f->defined__4type)
                                        dcl_print__4nameFUc(__5nn, (unsigned char)0);
                                    __2sm = 1;
                                }
                                break;
                            }
                        }
                    }

                    case 1:
                        fprintf(out_file, (const char *)"asm(\"%s\")\n",
                                ((char *)(((struct basetype *)(((struct basetype *)__2t))))
                                     ->b_name__8basetype));
                        break;

                    case 21:
                    case 121:
                    case 5:
                    case 22:
                    case 122:
                    case 29:
                    tcx:
                        if ((__2tc && (__1n->n_sto__4name != 14)) &&
                            (((__1n->n_scope__4name == 14) || (__1n->n_scope__4name == 31)) ||
                             (__1n->n_scope__4name == 108))) {
                            if (__1n->n_evaluated__4name && (__1n->n_addr_taken__4name == 0)) {
                                __2sm = 1;

                                break;
                            }
                        }
                        __2tc = 0;

                    default: {
                        Pexpr __4saveinit;
                        TOK __4savesto;

                        Pexpr __4i;

                        __4saveinit = __1n->__O3__4expr.n_initializer;
                        __4savesto = __1n->n_sto__4name;

                        __4i = __1n->__O3__4expr.n_initializer;
                        if ((__1n->base__4node == 123) && __1n->__O3__4expr.tpdef)
                            __4i = 0;

                        if ((((dtpt_opt && (all_flag == 0)) && (__1n->n_scope__4name != 31)) &&
                             (none_flag == 0)) &&
                            (curloc.file__3loc != first_file)) {
                            if ((__1n->base__4node == 123) && __1n->__O3__4expr.tpdef)
                                ;
                            else {
                                __1n->__O3__4expr.n_initializer = (__4i = 0);
                                mk_zero_init_flag = 1;
                                if ((__1n->n_scope__4name == 14) &&
                                    ((((struct basetype *)(((struct basetype *)__2t))))
                                         ->b_const__4type == 0))
                                    __1n->n_sto__4name = 14;
                            }
                        }

                        if (__2tc) {
                            switch (__2tt->base__4node) {
                            case 5:
                            case 29:
                            case 21:
                            case 22:
                            case 122:
                            case 121:
                                goto tcx;
                            }
                        }

                        if (__1n->base__4node == 123) {
                            if (!__0this->n_template_arg__4name) {
                                if (__1n->lex_level__4name)
                                    return;
                            }
                            puttok__FUc((unsigned char)35);
                        }

                        if (__1n->n_stclass__4name == 27) {
                            Pname __5cln;

                            __5cln = is_cl_obj__4typeFv(__1n->__O1__4expr.tp);
                            if (__5cln) {
                                Pclass __6cl;

                                __6cl = (((struct classdef *)((
                                    (struct classdef *)__5cln->__O1__4expr.tp))));
                                if (((((__6cl->csu__8classdef != 6) &&
                                       (__6cl->baselist__8classdef == 0)) &&
                                      ((__6cl->c_itor__8classdef) == 0)) &&
                                     (__6cl->virt_count__8classdef == 0)) &&
                                    (!__1n->n_addr_taken__4name))
                                    puttok__FUc((unsigned char)27);
                            } else if (!__1n->n_addr_taken__4name)
                                puttok__FUc((unsigned char)27);
                        }

                        if (__4i) {
                            if ((__1n->n_sto__4name == 14) && (__1n->n_stclass__4name == 31)) {
                                __1n->__O3__4expr.n_initializer = 0;
                                dcl_print__4typeFP4name(__2t, __1n);
                                puttok__FUc((unsigned char)72);
                                __1n->__O3__4expr.n_initializer = __4i;
                                __1n->n_sto__4name = 0;
                                dcl_print__4typeFP4name(__2t, __1n);
                                __1n->n_sto__4name = 14;
                            } else
                                dcl_print__4typeFP4name(__2t, __1n);
                            if (__1n->__O4__4expr.n_table) {
                                Pname __6nn;

                                __6nn =
                                    look__5tableFPCcUc(__1n->__O4__4expr.n_table,
                                                       __1n->__O2__4expr.string, (unsigned char)0);
                                if (__6nn)
                                    __6nn->n_dcl_printed__4name = 1;
                                else
                                    __1n->n_dcl_printed__4name = 1;
                            } else
                                __1n->n_dcl_printed__4name = 1;
                        } else if (__1n->n_evaluated__4name &&
                                   (((struct basetype *)(((struct basetype *)__2t))))
                                       ->b_const__4type) {
                            if ((__1n->n_sto__4name == 14) && (__1n->n_stclass__4name == 31)) {
                                int __6v;

                                __6v = __1n->n_evaluated__4name;
                                __1n->n_evaluated__4name = 0;
                                dcl_print__4typeFP4name(__2t, __1n);
                                puttok__FUc((unsigned char)72);
                                if ((__1n->where__4name.line__3loc != last_line.line__3loc) ||
                                    (__1n->where__4name.file__3loc != last_line.file__3loc))
                                    if (last_ll = __1n->where__4name.line__3loc)
                                        putline__3locFv(&__1n->where__4name);
                                    else
                                        putline__3locFv(&last_line);
                                __1n->n_evaluated__4name = __6v;
                                __1n->n_sto__4name = 0;
                                dcl_print__4typeFP4name(__2t, __1n);
                                __1n->n_sto__4name = 14;
                            } else
                                dcl_print__4typeFP4name(__2t, __1n);
                            if (__1n->__O4__4expr.n_table) {
                                Pname __6nn;

                                __6nn =
                                    look__5tableFPCcUc(__1n->__O4__4expr.n_table,
                                                       __1n->__O2__4expr.string, (unsigned char)0);
                                if (__6nn)
                                    __6nn->n_dcl_printed__4name = 1;
                                else
                                    __1n->n_dcl_printed__4name = 1;
                            } else
                                __1n->n_dcl_printed__4name = 1;
                        } else {
                            Ptype __5tempt;

                            __5tempt = skiptypedefs__4typeFv(__2t);
                            if (__5tempt->base__4node == 119) {
                                Pname __6cln;

                                __6cln = is_cl_obj__4typeFv(__1n->__O1__4expr.tp);
                                if (__6cln) {
                                    Pclass __7cl;
                                    Pname __7ctor;

                                    __7cl = (((struct classdef *)((
                                        (struct classdef *)__6cln->__O1__4expr.tp))));
                                    __7ctor = (__7cl->c_ctor__8classdef);
                                    if (((((__1n->__O4__4expr.n_table != gtbl) &&
                                           (__1n->n_sto__4name != 14)) &&
                                          (__1n->n_evaluated__4name == 0)) &&
                                         (__0this->n_stclass__4name == 31)) &&
                                        __7ctor)
                                        __1n->__O3__4expr.n_initializer =
                                            (__4i =
                                                 mk_zero_init__FP4typeP4nameT2(__2t, __1n, __1n));
                                }
                            }
                            if (((((__1n->n_sto__4name == 0) ||
                                   (__1n->n_val__4name && (__1n->n_evaluated__4name == 0))) &&
                                  (__0this->n_stclass__4name == 31)) &&
                                 (__1n->n_sto__4name != 31)) &&
                                ((__1n->__O4__4expr.n_table == gtbl) || ispt_data__FP4name(__1n))) {
                                if (__1n->n_val__4name && (__1n->n_evaluated__4name == 0)) {
                                    __1n->n_sto__4name = 0;
                                }

                                __1n->__O3__4expr.n_initializer =
                                    (__4i = mk_zero_init__FP4typeP4nameT2(__2t, __1n, __1n));
                            }
                            dcl_print__4typeFP4name(__2t, __1n);
                            if (__1n->__O4__4expr.n_table) {
                                Pname __6nn;

                                __6nn =
                                    look__5tableFPCcUc(__1n->__O4__4expr.n_table,
                                                       __1n->__O2__4expr.string, (unsigned char)0);
                                if (__6nn)
                                    __6nn->n_dcl_printed__4name = 1;
                                else
                                    __1n->n_dcl_printed__4name = 1;
                            } else
                                __1n->n_dcl_printed__4name = 1;
                        }

                        if (__1n->n_scope__4name != 136) {
                            if (__4i) {
                                puttok__FUc((unsigned char)70);

                                {
                                    Pexpr __6i2;

                                    __6i2 = __4i;
                                    while ((__6i2->base__4node == 113) ||
                                           (__6i2->base__4node == 191))
                                        __6i2 = __6i2->__O2__4expr.e1;
                                    if (__6i2->base__4node == 124)
                                        __4i = __6i2;

                                    if (((__2t != __4i->__O1__4expr.tp) &&
                                         (__4i->base__4node != 86)) &&
                                        (__4i->base__4node != 124)) {
                                        Ptype __7t1;

                                        __7t1 = skiptypedefs__4typeFv(__1n->__O1__4expr.tp);

                                        switch (__7t1->base__4node) {
                                        default:
                                            print__4exprFv(__4i);
                                            break;
                                        case 110:
                                            if ((((struct vec *)(((struct vec *)__7t1))))
                                                    ->typ__5pvtyp->base__4node == 5) {
                                                print__4exprFv(__4i);
                                                break;
                                            }

                                        case 125:
                                        case 158:
                                            if (((__4i->__O1__4expr.tp == 0) ||
                                                 (((((!ansi_opt) &&
                                                     (((struct ptr *)(((struct ptr *)__2t))))
                                                         ->typ__5pvtyp) &&
                                                    (skiptypedefs__4typeFv(
                                                         (((struct ptr *)(((struct ptr *)__2t))))
                                                             ->typ__5pvtyp)
                                                         ->base__4node == 110)) &&
                                                   (__4i->base__4node != 191)) &&
                                                  (__4i->base__4node != 113))) ||
                                                check__4typeFP4typeUcT2(
                                                    __1n->__O1__4expr.tp, __4i->__O1__4expr.tp,
                                                    (unsigned char)0, (unsigned char)0)) {
                                                fputc((int)'(', out_file);
                                                {
                                                    bit __9oc;

                                                    __9oc = Cast;
                                                    Cast = 1;
                                                    print__4typeFv(__2t);
                                                    Cast = __9oc;
                                                    fputc((int)')', out_file);
                                                }
                                            }
                                            if (__4i)
                                                Eprint__FP4expr(__4i);
                                        }
                                    } else {
                                        if (__4i == zero) {
                                            while (__2t->base__4node == 97)
                                                __2t = (((struct basetype *)((
                                                            (struct basetype *)__2t))))
                                                           ->b_name__8basetype->__O1__4expr.tp;
                                        }
                                        if (__4i)
                                            Eprint__FP4expr(__4i);
                                    }
                                }
                            } else if (__1n->n_evaluated__4name) {
                                puttok__FUc((unsigned char)70);
                                if ((__1n->__O1__4expr.tp->base__4node != 21) ||
                                    is_unsigned__4typeFv(__1n->__O1__4expr.tp)) {
                                    fputs((const char *)"((", out_file);
                                    {
                                        bit __7oc;

                                        __7oc = Cast;
                                        Cast = 1;
                                        print__4typeFv(__1n->__O1__4expr.tp);
                                        Cast = __7oc;
                                        fprintf(out_file, (const char *)")%lld)",
                                                __1n->n_val__4name);
                                    }
                                } else
                                    fprintf(out_file, (const char *)"%lld", __1n->n_val__4name);
                            }
                        }

                        __1n->__O3__4expr.n_initializer = __4saveinit;
                        __1n->n_sto__4name = __4savesto;
                    }
                    }

                    switch (__1list) {
                    case 72:
                        if (__2sm == 0)
                            puttok__FUc((unsigned char)72);
                        break;
                    case 0:
                        if (__2sm == 0)
                            puttok__FUc((unsigned char)72);
                        return;
                    case 71:
                        if (__1n->__O1__4name.n_list)
                            puttok__FUc((unsigned char)71);
                        break;
                    }
                }
            }
        }
    }
}

char *signature__4typeFPci(struct type *__0this, char *, int);

extern char *strcpy(char *, const char *);

char *local_sign__FP4type(Ptype __1pt) {
    char __1buf[1024];
    char *__1bb;
    int __1ll;

    __1bb = signature__4typeFPci(__1pt, (char *)__1buf, 0);
    __1ll = (__1bb - __1buf);
    if (1023 < __1ll)
        error__FiPCc((int)'i', (const char *)"local class N buffer overflow");
    {
        char *__1p;

        __1p = (((char *)__nw__FUl((size_t)((sizeof(char)) * (__1ll + 1)))));
        strcpy(__1p, (const char *)__1buf);
        return __1p;
    }
}

void dcl_print__7enumdefFP4name(register struct enumdef *__0this, Pname __1cln) {
    const char *__1s;

    __1s =
        (__0this->nested_sig__4type ? (((const char *)__0this->nested_sig__4type))
                                    : (__1cln ? __1cln->__O2__4expr.string : (((const char *)0))));
    if (__0this->nested_sig__4type)
        fprintf(out_file, (const char *)"enum __%s { ", __0this->nested_sig__4type);
    else
        fprintf(out_file, (const char *)"enum %s { ",
                __0this->local_sig__4type ? (((const char *)__0this->local_sig__4type))
                                          : __0this->string__7enumdef);

    {
        {
            Pname __1px;

            Pname __1p;

            __1p = __0this->mem__7enumdef;

            for (; __1p; __1p = __1px) {
                __1px = __1p->__O1__4name.n_list;
                if (__1s) {
                    if (__1p->n_evaluated__4name)
                        fprintf(out_file, (const char *)"%s__%s = %lld", __1p->__O2__4expr.string,
                                __1s, __1p->n_val__4name);
                    else
                        fprintf(out_file, (const char *)"%s__%s", __1p->__O2__4expr.string, __1s);

                } else {
                    if (__1p->n_evaluated__4name)
                        fprintf(out_file, (const char *)"%s = %lld", __1p->__O2__4expr.string,
                                __1p->n_val__4name);
                    else
                        fprintf(out_file, (const char *)"%s", __1p->__O2__4expr.string);
                }
                if (__1px)
                    puttok__FUc((unsigned char)71);
                __1p->__O3__4expr.n_initializer = 0;

                if ((__0this->in_class__4type == 0) ||
                    (__0this->in_class__4type->class_base__8classdef != 4))
                    ((__1p ? (((void)(__1p ? (((void)((((((struct expr *)__1p))
                                                            ? (((void)((((struct expr *)__1p))
                                                                           ? (((void)(((void)0))))
                                                                           : (((void)0)))))
                                                            : (((void)0)))),
                                                      (((void)__dl__4nameSFPvUl(
                                                          (void *)__1p,
                                                          (unsigned long)(sizeof(struct name))))))))
                                           : (((void)0)))))
                           : (((void)0))));
            }
            if ((__0this->in_class__4type == 0) ||
                (__0this->in_class__4type->class_base__8classdef != 4))
                __0this->mem__7enumdef = 0;
            else
                __0this->e_body__7enumdef = 3;
            puttok__FUc((unsigned char)74);
            puttok__FUc((unsigned char)72);
        }
    }
}

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

void print_pretty_name__10templ_instFv(struct templ_inst *__0this);

void print__4nameFUc(register struct name *__0this, bit __1fullprint) {
    if (__0this == 0)
        error__FiPCc((int)'i', (const char *)"0->N::print()");
    if (__0this->__O2__4expr.string == 0) {
        if (emode)
            fputc((int)'?', out_file);
        return;
    }

    switch (__0this->base__4node) {
    case 123:
        if (__0this->__O3__4expr.tpdef == 0) {
            switch (__0this->__O1__4expr.tp->base__4node) {
                const void *__2__X40;

            default: {
                struct ea __0__V39;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"missing tpdef forTdefN %s",
                    (const struct ea *)((__2__X40 = (const void *)__0this->__O2__4expr.string),
                                        (((&__0__V39)->__O1__2ea.p = __2__X40), (&__0__V39))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            case 119:
            case 121:
                print__4nameFUc(
                    (((struct basetype *)(((struct basetype *)__0this->__O1__4expr.tp))))
                        ->b_name__8basetype,
                    (unsigned char)0);
            }
            }
        } else if (__0this->__O3__4expr.tpdef->nested_sig__4type) {
            if (emode == 0) {
                fputs((const char *)" __", out_file);
                (fputs((const char *)__0this->__O3__4expr.tpdef->nested_sig__4type, out_file),
                 fputc((int)' ', out_file));
            } else {
                print__4nameFUc((((struct basetype *)((
                                     (struct basetype *)__0this->__O3__4expr.tpdef->in_class__4type
                                         ->k_tbl__8classdef->k_name__6ktable->__O1__4expr.tp))))
                                    ->b_name__8basetype,
                                (unsigned char)0);
                fputs((const char *)"::", out_file);
                fputs(__0this->__O2__4expr.string, out_file);
            }
        } else if (emode)
            fputs(__0this->__O2__4expr.string, out_file);
        else
            (fputs(__0this->n_template_arg_string__4name
                       ? (((const char *)__0this->n_template_arg_string__4name))
                       : __0this->__O2__4expr.string,
                   out_file),
             fputc((int)' ', out_file));
        return;

    case 177:
        print__4exprFv(((struct expr *)(((struct expr *)__0this))));
        return;
    }

    if (emode) {
        Ptable __2tbl;
        bit __2f;

        __2tbl = 0;
        __2f = 0;
        if (__0this->__O1__4expr.tp) {
            switch (__0this->__O1__4expr.tp->base__4node) {
            case 76:
            case 108: {
                Pfct __5ft;

                unsigned long __2__X16;

                struct ea __0__X__V1400qmp1ovbwvcnm;

                struct ea __0__X__V1500qmp1ovbwvcnm;

                __2f = 1;
                ;
                if (__0this->__O1__4expr.tp->base__4node == 108)
                    __5ft = ((
                        (__0this->__O1__4expr.tp->base__4node == 108)
                            ? (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
                            : (error__FiPCcRC2eaN33(
                                   (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                   (const struct ea *)(((&__0__X__V1400qmp1ovbwvcnm)->__O1__2ea.p =
                                                            ((const void *)__0this)),
                                                       (&__0__X__V1400qmp1ovbwvcnm)),
                                   (const struct ea *)((__2__X16 =
                                                            __0this->__O1__4expr.tp->base__4node),
                                                       (((((&__0__X__V1500qmp1ovbwvcnm)
                                                               ->__O1__2ea.i = __2__X16),
                                                          0)),
                                                        (&__0__X__V1500qmp1ovbwvcnm))),
                                   (const struct ea *)ea0, (const struct ea *)ea0),
                               (((struct fct *)0)))));
                else
                    __5ft = (((struct fct *)((
                        (struct fct *)(((struct gen *)(((struct gen *)__0this->__O1__4expr.tp))))
                            ->fct_list__3gen->f__9name_list->__O1__4expr.tp))));
                if ((__1fullprint && __5ft->returns__3fct) &&
                    (__5ft->returns__3fct->base__4node != 38))
                    print__4typeFv(__5ft->returns__3fct);
            }
            default:
                if (__2tbl = __0this->__O4__4expr.n_table) {
                    if (__2tbl == gtbl) {
                        if (__2f == 0)
                            fputs((const char *)"::", out_file);
                    } else {
                        if (__2tbl->t_name__5table) {
                            print__4nameFUc(__2tbl->t_name__5table, (unsigned char)0);
                            fprintf(out_file, (const char *)"::");
                        }
                    }
                }

                if ((__0this->n_scope__4name == 136) &&
                    (strcmp(__0this->__O2__4expr.string, (const char *)"this") == 0)) {
                    Ptype __5tt;
                    Pname __5cn;

                    __5tt =
                        (((struct ptr *)(((struct ptr *)__0this->__O1__4expr.tp))))->typ__5pvtyp;
                    __5cn = (((struct basetype *)(((struct basetype *)__5tt))))->b_name__8basetype;
                    fprintf(out_file, (const char *)"%s::", __5cn->__O2__4expr.string);
                }
                break;

            case 6:
            case 13:
                if (__0this->__O1__4expr.tp->local_sig__4type) {
                    fprintf(out_file, (const char *)"%s(local to ", __0this->__O2__4expr.string);
                    print__4nameFUc(__0this->__O1__4expr.tp->in_fct__4type, (unsigned char)0);
                    fprintf(out_file, (const char *)")");
                    return;
                } else {
                    if (__0this->__O1__4expr.tp->nested_sig__4type) {
                        print__4nameFUc(
                            (((struct basetype *)((
                                 (struct basetype *)__0this->__O1__4expr.tp->in_class__4type
                                     ->k_tbl__8classdef->k_name__6ktable->__O1__4expr.tp))))
                                ->b_name__8basetype,
                            (unsigned char)0);
                        fprintf(out_file, (const char *)"::");
                    }
                    if (__0this->__O1__4expr.tp->base__4node == 6) {
                        Ptclass __6pc;

                        __6pc = (((struct templ_classdef *)((
                            (struct templ_classdef *)__0this->__O1__4expr.tp))));
                        if (__6pc->class_base__8classdef == 4)
                            ((*(((void (*)(struct templ_inst *__0this))(
                                     __6pc->inst__14templ_classdef->__vptr__10basic_inst[2])
                                     .f))))(
                                ((struct templ_inst *)((((char *)__6pc->inst__14templ_classdef)) +
                                                       (__6pc->inst__14templ_classdef
                                                            ->__vptr__10basic_inst[2])
                                                           .d)));
                        else
                            fputs(__0this->__O2__4expr.string, out_file);
                    } else
                        fputs(__0this->__O2__4expr.string, out_file);
                    return;
                }
            }
        nop:
            switch (__0this->n_oper__4name) {
            case 97:
                fputs((const char *)"operator ", out_file);

                if (__0this->__O1__4expr.tp &&
                    (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->returns__3fct)
                    dcl_print__4typeFP4name(
                        (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->returns__3fct,
                        (struct name *)0);
                break;
            case 0:
                fputs(__0this->__O2__4expr.string, out_file);
                break;
            case 162:
                if (__2tbl && __2tbl->t_name__5table) {
                    fputc((int)'~', out_file);
                    fputs(__2tbl->t_name__5table->__O2__4expr.string, out_file);
                } else {
                    if (__0this->__O2__4expr.string)
                        fprintf(out_file, (const char *)"%s",
                                __0this->n_template_arg_string__4name
                                    ? __0this->n_template_arg_string__4name
                                    : (((char *)"destructor")));
                    else
                        fputs((const char *)"destructor", out_file);
                    __2f = 0;
                }
                break;
            case 161:
                if (__2tbl && __2tbl->t_name__5table)
                    fputs(__2tbl->t_name__5table->__O2__4expr.string, out_file);
                else {
                    if (__0this->__O2__4expr.string)
                        fprintf(out_file, (const char *)"%s",
                                __0this->n_template_arg_string__4name
                                    ? __0this->n_template_arg_string__4name
                                    : (((char *)"constructor")));
                    else
                        fputs((const char *)"constructor", out_file);
                    __2f = 0;
                }
                break;
            case 123:
                fputs(__0this->__O2__4expr.string, out_file);
                break;
            default:
                fputs((const char *)"operator ", out_file);
                fputs(keys[__0this->n_oper__4name], out_file);
                break;
            }

            if (__2f)
                if (__1fullprint)
                    arg_print__3fctFv(((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));
                else
                    fputs((const char *)"()", out_file);
        } else {
            if (__0this->n_oper__4name)
                goto nop;
            if (__0this->__O2__4expr.string)
                fputs(__0this->n_template_arg_string__4name
                          ? (((const char *)__0this->n_template_arg_string__4name))
                          : __0this->__O2__4expr.string,
                      out_file);
        }
        return;
    }

    {
        const char *__1sig;
        const char *__1templ_fct_name;
        Pclass __1cl;
        const char *__1asig;

        __1sig = 0;
        __1templ_fct_name = 0;
        __1cl = 0;
        __1asig = __0this->n_anon__4name;

        if (__0this->__O1__4expr.tp) {
            Ptable __2tbl;

            switch (__0this->__O1__4expr.tp->base__4node) {
            default:
                if (__2tbl = __0this->__O4__4expr.n_table) {
                    Pname __4tn;
                    if (__2tbl == gtbl) {
                        if (__1asig) {
                            fprintf(out_file, (const char *)"%s.", __1asig);
                        }
                        break;
                    }

                    if (__4tn = __2tbl->t_name__5table) {
                        __1cl = (((struct classdef *)(((struct classdef *)__4tn->__O1__4expr.tp))));

                        if (__1asig) {
                            if ((((__1cl->string__8classdef[0]) == '_') &&
                                 ((__1cl->string__8classdef[1]) == '_')) &&
                                ((__1cl->string__8classdef[2]) == 'C')) {
                                fprintf(out_file, (const char *)"%s.", __1asig);
                            } else {
                                const char *__7cn;
                                int __7f;
                                char __7buf[1024];
                                if (__1cl->nested_sig__4type)
                                    __7cn = (const char *)__1cl->nested_sig__4type;
                                else if (__1cl->lex_level__4type)
                                    __7cn = (const char *)__1cl->local_sig__4type;
                                else
                                    __7cn = __1cl->string__8classdef;
                                __7f = (dem_opt_mem && dem_mem__FPCcT1(__7cn, __1asig));
                                fprintf(out_file, (const char *)"%s", __1asig);
                                if (__1cl->nested_sig__4type) {
                                    sprintf((char *)__7buf, (const char *)"__%s",
                                            __1cl->nested_sig__4type);
                                } else if (__1cl->lex_level__4type) {
                                    sprintf((char *)__7buf, (const char *)"__%d%s",
                                            __1cl->c_strlen__8classdef, __1cl->local_sig__4type);
                                } else {
                                    sprintf((char *)__7buf, (const char *)"__%d%s",
                                            __1cl->c_strlen__8classdef, __1cl->string__8classdef);
                                }
                                if (!__7f)
                                    fprintf(out_file, (const char *)"%s", __7buf);
                                fprintf(out_file, (const char *)".");
                            }
                            __1cl = 0;
                        } else if (((((__1cl->string__8classdef[0]) == '_') &&
                                     ((__1cl->string__8classdef[1]) == '_')) &&
                                    ((__1cl->string__8classdef[2]) == 'C')) &&
                                   (__0this->n_stclass__4name != 31)) {

                            if (((__0this->__O1__4expr.tp->base__4node == 108) &&
                                 ((((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
                                      ->f_is_inline__3fct &&
                                  vtbl_opt)) ||
                                (ansi_opt && (__0this->n_sto__4name == 31)))
                                ;
                            else
                                __1cl = 0;
                        }
                        break;
                    }
                }

                switch (__0this->n_stclass__4name) {
                case 31:
                case 14:
                    if (__1asig)
                        fprintf(out_file, (const char *)"%s.", __1asig);
                    else if ((__0this->n_sto__4name == 31) &&
                             (__0this->__O1__4expr.tp->base__4node != 108)) {
                        if (__0this->lex_level__4name == 0)
                            fputs((const char *)"__S", out_file);
                        else if ((!dem_opt_local) ||
                                 look__5tableFPCcUc(gtbl, __0this->__O2__4expr.string,
                                                    (unsigned char)0))
                            fprintf(out_file, (const char *)"__%d",
                                    ((int)__0this->lex_level__4name));
                    }
                    break;
                default:
                    if ((((__0this->__O2__4expr.string[0]) != '_') ||
                         ((__0this->__O2__4expr.string[1]) != '_')) ||
                        ((__0this->__O2__4expr.string[2]) != 'C')) {
                        if (__1asig) {
                            if ((!dem_opt_local) ||
                                look__5tableFPCcUc(gtbl, __1asig, (unsigned char)0))
                                fprintf(out_file, (const char *)"__%d",
                                        ((int)__0this->lex_level__4name));
                            fprintf(out_file, (const char *)"%s.", __1asig);
                        } else if ((!dem_opt_local) ||
                                   look__5tableFPCcUc(gtbl, __0this->__O2__4expr.string,
                                                      (unsigned char)0)) {
                            fprintf(out_file, (const char *)"__%d",
                                    ((int)__0this->lex_level__4name));
                        }
                    }
                }
                break;

            case 6:
                if (__0this->__O1__4expr.tp->nested_sig__4type)
                    fprintf(out_file, (const char *)"__%s",
                            __0this->__O1__4expr.tp->nested_sig__4type);
                else if (__0this->__O1__4expr.tp->local_sig__4type)
                    fprintf(out_file, (const char *)"%s",
                            __0this->__O1__4expr.tp->local_sig__4type);
                else
                    fprintf(out_file, (const char *)"%s",
                            (((struct classdef *)(((struct classdef *)__0this->__O1__4expr.tp))))
                                ->string__8classdef);
                return;
            case 13:
                if (__0this->__O1__4expr.tp->nested_sig__4type)
                    fprintf(out_file, (const char *)"__%s",
                            __0this->__O1__4expr.tp->nested_sig__4type);
                else if (__0this->__O1__4expr.tp->local_sig__4type)
                    fprintf(out_file, (const char *)"%s",
                            __0this->__O1__4expr.tp->local_sig__4type);
                else
                    fprintf(out_file, (const char *)"%s",
                            (((struct enumdef *)(((struct enumdef *)__0this->__O1__4expr.tp))))
                                ->string__7enumdef);
                return;
            }

            if (__0this->__O1__4expr.tp->base__4node == 108) {
                register struct templ_fct *__0__X41;

                __1sig =
                    (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->f_signature__3fct;
                if (__1sig && ((__1sig[0]) == 0))
                    __1sig = 0;
                if (__1sig &&
                    ((((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->fct_base__3fct ==
                     4))
                    __1templ_fct_name =
                        ((__0__X41 = (((
                              struct templ_fct *)(((struct templ_fct *)__0this->__O1__4expr.tp))))),
                         (__0__X41->inst__9templ_fct->def__10funct_inst->fn__17function_template))
                            ->__O2__4expr.string;
            }
        }

        if (__0this->__O2__4expr.string) {
            const char *__2mn;
            {
                const char *__3s;

                __3s =
                    (__0this->n_template_arg_string__4name
                         ? (((const char *)__0this->n_template_arg_string__4name))
                         : (__1templ_fct_name ? __1templ_fct_name : __0this->__O2__4expr.string));

                fputs(__3s, out_file);
                __2mn = __3s;
            }

            if (__1cl) {
                int __3f;

                __3f = 0;
                if (((__0this->__O1__4expr.tp->base__4node != 108) &&
                     (__0this->n_stclass__4name != 31)) &&
                    dem_opt_mem) {
                    const char *__4cn;
                    if (__1cl->nested_sig__4type)
                        __4cn = (const char *)__1cl->nested_sig__4type;
                    else if (__1cl->lex_level__4type)
                        __4cn = (const char *)__1cl->local_sig__4type;
                    else
                        __4cn = __1cl->string__8classdef;
                    __3f = dem_mem__FPCcT1(__4cn, __2mn);
                }
                if ((!dem_opt_mem) || (!__3f)) {
                    if (__1cl->nested_sig__4type)
                        fprintf(out_file, (const char *)"__%s", __1cl->nested_sig__4type);
                    else if (__1cl->lex_level__4type)
                        fprintf(out_file, (const char *)"__%d%s", ((int)__1cl->c_strlen__8classdef),
                                __1cl->local_sig__4type);
                    else
                        fprintf(out_file, (const char *)"__%d%s", ((int)__1cl->c_strlen__8classdef),
                                __1cl->string__8classdef);
                }
            }

            if (__1sig) {
                if (__1cl == 0)
                    fputs((const char *)"__", out_file);

                fputs(__1sig, out_file);
            }
            fputc((int)' ', out_file);
        }
    }
}

void print__4typeFv(register struct type *__0this) {
    switch (__0this->base__4node) {
    case 125:
    case 158:
    case 110:
        dcl_print__4typeFP4name((struct type *)(((struct ptr *)(((struct ptr *)__0this)))),
                                (struct name *)0);
        break;
    case 108:
        dcl_print__3fctFv(((struct fct *)(((struct fct *)__0this))));
        break;
    case 6:
    case 13:
        if (emode)
            if (__0this->base__4node == 6)
                fputs((const char *)"class ", out_file);
            else
                fputs((const char *)"enum ", out_file);
        else if (__0this->base__4node == 6) {
            if ((((struct classdef *)(((struct classdef *)__0this))))->nested_sig__4type)
                fprintf(out_file, (const char *)"struct __%s *",
                        (((struct classdef *)(((struct classdef *)__0this))))->nested_sig__4type);
            else
                fprintf(
                    out_file, (const char *)"struct %s *",
                    (((struct classdef *)(((struct classdef *)__0this))))->local_sig__4type
                        ? (((const char *)(((struct classdef *)(((struct classdef *)__0this))))
                                ->local_sig__4type))
                        : (((struct classdef *)(((struct classdef *)__0this))))->string__8classdef);
        } else
            fprintf(out_file, (const char *)"enum %s *",
                    (((struct enumdef *)(((struct enumdef *)__0this))))->string__7enumdef);
        break;
    case 97:
        if (Cast || (((struct basetype *)(((struct basetype *)__0this))))
                        ->b_name__8basetype->lex_level__4name) {
            print__4typeFv((((struct basetype *)(((struct basetype *)__0this))))
                               ->b_name__8basetype->__O1__4expr.tp);
            break;
        }

    default:
        dcl_print__8basetypeFv(((struct basetype *)(((struct basetype *)__0this))));
    }
}

extern size_t strlen(const char *);

char *signature__4typeFPci(register struct type *__0this, char *__1p, int __1ptflag) {
    Ptype __1t;
    int __1pp;

    __1t = __0this;
    __1pp = 0;

xx:
    switch (__1t->base__4node) {
    case 97:
        if ((((struct basetype *)(((struct basetype *)__1t))))->b_const__4type)
            ((*(__1p++))) = 'C';
        __1t =
            (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp;
        goto xx;

    case 110:
        if ((__1pp || __1ptflag) && (((struct vec *)(((struct vec *)__1t))))->size__3vec) {
            ((*(__1p++))) = 'A';
            sprintf(__1p, (const char *)"%d\0",
                    (((struct vec *)(((struct vec *)__1t))))->size__3vec);

            while ((*(++__1p)))
                ;
            ((*(__1p++))) = '_';
        } else
            ((*(__1p++))) = 'P';
        __1t = (((struct vec *)(((struct vec *)__1t))))->typ__5pvtyp;
        __1pp = 1;
        goto xx;

    case 125:
        if ((((struct ptr *)(((struct ptr *)__1t))))->b_const__4type)
            ((*(__1p++))) = 'C';
        {
            const char *__2s;
            int __2d;
            __2s = 0;
            __2d = 0;
            if (((!(((struct ptr *)(((struct ptr *)__1t))))->memof__3ptr) &&
                 (((struct ptr *)(((struct ptr *)__1t))))->ptname__3ptr) &&
                (((struct ptr *)(((struct ptr *)__1t))))->ptname__3ptr->__O1__4expr.tp) {
                __2s = (((struct basetype *)((
                            (struct basetype *)(((struct ptr *)(((struct ptr *)__1t))))
                                ->ptname__3ptr->__O1__4expr.tp))))
                           ->b_name__8basetype->__O2__4expr.string;
                __2d = strlen(__2s);
            }
            if ((((struct ptr *)(((struct ptr *)__1t))))->memof__3ptr || __2s) {
                ((*(__1p++))) = 'M';
                if (!__2s) {
                    Pclass __4cl;
                    char *__4ns;
                    char *__4ls;

                    __4cl = (((struct ptr *)(((struct ptr *)__1t))))->memof__3ptr;
                    __4ns = __4cl->nested_sig__4type;
                    __4ls = __4cl->local_sig__4type;
                    if (__4ns)
                        __2s = (const char *)__4ns;
                    else {
                        if (__4ls)
                            __2s = (const char *)__4ls;
                        else
                            __2s = __4cl->string__8classdef;
                        __2d = __4cl->c_strlen__8classdef;
                    }
                }
                if (__2d >= 100)
                    ((*(__1p++))) = ('0' + (__2d / 100));
                if (__2d >= 10)
                    ((*(__1p++))) = ('0' + ((__2d % 100) / 10));
                if (__2d)
                    ((*(__1p++))) = ('0' + (__2d % 10));
                while (((*(__1p++))) = ((*(__2s++))))
                    ;
                --__1p;
            } else
                ((*(__1p++))) = 'P';
            __1t = (((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp;
            __1pp = 1;
            goto xx;

        case 158:
            ((*(__1p++))) = 'R';
            __1t = (((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp;
            __1pp = 1;
            goto xx;

        case 108: {
            Pfct __3f;
            Pname __3n;

            __3f = (((struct fct *)(((struct fct *)__1t))));
            __3n = __3f->argtype__3fct;

            if (__3f->f_const__3fct)
                ((*(__1p++))) = 'C';
            if (__3f->f_static__3fct)
                ((*(__1p++))) = 'S';
            ((*(__1p++))) = 'F';

            if (__3n == 0)
                ((*(__1p++))) = 'v';
            else
                for (; __3n; __3n = __3n->__O1__4name.n_list) {
                    int __4i;

                    __4i = 0;
                    {
                        {
                            Pname __4nn;

                            __4nn = __3f->argtype__3fct;

                            for (; __3n != __4nn; __4nn = __4nn->__O1__4name.n_list) {
                                __4i++;
                                if ((__4nn->__O1__4expr.tp == __3n->__O1__4expr.tp) ||
                                    (check__4typeFP4typeUcT2(__4nn->__O1__4expr.tp,
                                                             __3n->__O1__4expr.tp, (unsigned char)0,
                                                             (unsigned char)0) == 0)) {
                                    int __6x;
                                    Pname __6nnn;

                                    __6x = 1;
                                    __6nnn = __3n;
                                    while ((__6nnn = __6nnn->__O1__4name.n_list) && (__6x < 9)) {
                                        if ((__6nnn->__O1__4expr.tp == __3n->__O1__4expr.tp) ||
                                            (check__4typeFP4typeUcT2(
                                                 __6nnn->__O1__4expr.tp, __3n->__O1__4expr.tp,
                                                 (unsigned char)0, (unsigned char)0) == 0)) {
                                            __6x++;
                                            __3n = __6nnn;
                                        } else
                                            break;
                                    }

                                    if (__6x == 1)
                                        ((*(__1p++))) = 'T';
                                    else {
                                        ((*(__1p++))) = 'N';
                                        ((*(__1p++))) = ('0' + __6x);
                                    }

                                    if (9 < __4i)
                                        ((*(__1p++))) = ('0' + (__4i / 10));
                                    ((*(__1p++))) = ('0' + (__4i % 10));
                                    goto zk;
                                }
                            }

                            __1p = signature__4typeFPci(__3n->__O1__4expr.tp, __1p, 0);
                        zk:;
                        }
                    }
                }

            if (__3f->nargs_known__3fct == 155)
                ((*(__1p++))) = 'e';

            if (__1pp) {
                ((*(__1p++))) = '_';
                __1p = signature__4typeFPci(__3f->returns__3fct, __1p, 0);
            }

            ((*__1p)) = 0;
            return __1p;
        }
        }
    }

    if ((((struct basetype *)(((struct basetype *)__1t))))->b_const__4type)
        ((*(__1p++))) = 'C';

    if ((((struct basetype *)(((struct basetype *)__1t))))->b_unsigned__8basetype)
        ((*(__1p++))) = 'U';

    {
        const char *__1s;

        const char *__1ns;

        __1ns = 0;

        ;
        {
            char *__1ls;
            int __1d;
            Pclass __1cl;
            switch (__1t->base__4node) {
                unsigned long __2__X43;

            case 141:
                break;
            case 138:
                break;
            case 38:
                ((*(__1p++))) = 'v';

                break;
            case 5:
                ((*(__1p++))) = 'c';

                break;
            case 29:
                ((*(__1p++))) = 's';

                break;
            case 21:
                ((*(__1p++))) = 'i';

                break;
            case 22:
                ((*(__1p++))) = 'l';

                break;
            case 122:
                ((*(__1p++))) = 'm';

                break;
            case 15:
                ((*(__1p++))) = 'f';

                break;
            case 11:
                ((*(__1p++))) = 'd';

                break;
            case 181:
                ((*(__1p++))) = 'r';

                break;
            case 121: {
                Penum __3en;

                __3en = (((struct enumdef *)((
                    (struct enumdef *)(((struct basetype *)(((struct basetype *)__1t))))
                        ->b_name__8basetype->__O1__4expr.tp))));
                __1ls = __3en->local_sig__4type;
                __1ns = (const char *)__3en->nested_sig__4type;
                __1s = __3en->string__7enumdef;
                __1d = __3en->e_strlen__7enumdef;
                goto pppp;
            }

            case 119: {
                __1cl = (((struct classdef *)((
                    (struct classdef *)(((struct basetype *)(((struct basetype *)__1t))))
                        ->b_name__8basetype->__O1__4expr.tp))));
                __1ls = __1cl->local_sig__4type;
                __1ns = (const char *)__1cl->nested_sig__4type;
                __1s = __1cl->string__8classdef;
                __1d = __1cl->c_strlen__8classdef;
            pppp:
                if (__1ns)
                    __1s = __1ns;
                else {
                    if (__1ls)
                        __1s = (const char *)__1ls;
                    if (__1d >= 100)
                        ((*(__1p++))) = ('0' + (__1d / 100));
                    if (__1d >= 10)
                        ((*(__1p++))) = ('0' + ((__1d % 100) / 10));
                    ((*(__1p++))) = ('0' + (__1d % 10));
                }
                while (((*(__1p++))) = ((*(__1s++))))
                    ;
                --__1p;
                break;
            }
            case 114:
            default: {
                struct ea __0__V42;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"signature of%k",
                    (const struct ea *)((__2__X43 = __1t->base__4node),
                                        (((((&__0__V42)->__O1__2ea.i = __2__X43), 0)),
                                         (&__0__V42))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            }

            ((*__1p)) = 0;
            return __1p;
        }
    }
}

void dcl_print__8basetypeFv(register struct basetype *__0this) {
    Pname __1nn;
    Pclass __1cl;

    if (emode) {
        if (__0this->b_virtual__8basetype)
            puttok__FUc((unsigned char)77);
        if (__0this->b_inline__8basetype)
            puttok__FUc((unsigned char)75);
    }
    if ((ansi_opt && (!__0this->ansi_const__4type)) || emode)
        if (__0this->b_const__4type)
            puttok__FUc((unsigned char)26);
    if (__0this->b_unsigned__8basetype)
        puttok__FUc((unsigned char)37);

    switch (__0this->base__4node) {
        unsigned long __2__X46;

    case 141:
        if (emode)
            fputs((const char *)"any ", out_file);
        else
            fputs((const char *)"int ", out_file);
        break;

    case 138:
        if (emode)
            fputs((const char *)"zero ", out_file);
        else
            fputs((const char *)"int ", out_file);
        break;

    case 38:
        if ((emode == 0) && (ansi_opt == 0)) {
            puttok__FUc((unsigned char)5);
            break;
        }
    case 5:
    case 29:
    case 21:
    case 22:
    case 122:
    case 15:
    case 11:
    case 181:
        puttok__FUc(__0this->base__4node);
        break;

    case 121:
        __1nn = __0this->b_name__8basetype;
    eob:
        if ((emode == 0) &&
            (((struct enumdef *)(((struct enumdef *)__1nn->__O1__4expr.tp))))->e_type__7enumdef) {
            dcl_print__8basetypeFv((((struct enumdef *)(((struct enumdef *)__1nn->__O1__4expr.tp))))
                                       ->e_type__7enumdef);
        } else {
            const char *__3s;

            __3s = __1nn->__O2__4expr.string;
            puttok__FUc((unsigned char)13);
            if (((((*__3s)) != '_') || ((__3s[1]) != '_')) || ((__3s[2]) != 'E'))
                print__4nameFUc(__1nn, (unsigned char)0);
        }
        break;

    case 119:
        __1nn = __0this->b_name__8basetype;
    cob:
        __1cl = (((struct classdef *)(((struct classdef *)__1nn->__O1__4expr.tp))));
        if ((emode && __1cl) && (__1cl->base__4node == 6)) {
            const char *__3s;

            __3s = __1nn->__O2__4expr.string;
            puttok__FUc(__1cl->csu__8classdef);
            if (((((*__3s)) != '_') || ((__3s[1]) != '_')) || ((__3s[2]) != 'C'))
                print__4nameFUc(__1nn, (unsigned char)0);
            break;
        }
        if (__1cl && ((__1cl->csu__8classdef == 36) || (__1cl->csu__8classdef == 167)))
            puttok__FUc((unsigned char)36);
        else
            puttok__FUc((unsigned char)32);
        if (__1cl && __1cl->nested_sig__4type)
            fprintf(out_file, (const char *)" __%s ", __1cl->nested_sig__4type);
        else {
            char *__3s;

            __3s = 0;
            if ((__1cl && __1cl->lex_level__4type) && __1cl->local_sig__4type)
                __3s = __1cl->local_sig__4type;
            (fputs(__3s ? (((const char *)__3s)) : __1nn->__O2__4expr.string, out_file),
             fputc((int)' ', out_file));
        }
        break;

    case 97:
        if (emode == 0) {
            switch (__0this->b_name__8basetype->__O1__4expr.tp->base__4node) {
            case 119:
                __1nn = (((struct basetype *)((
                             (struct basetype *)__0this->b_name__8basetype->__O1__4expr.tp))))
                            ->b_name__8basetype;
                goto cob;
            case 121:
                __1nn = (((struct basetype *)((
                             (struct basetype *)__0this->b_name__8basetype->__O1__4expr.tp))))
                            ->b_name__8basetype;
                goto eob;
            }
        }
        print__4nameFUc(__0this->b_name__8basetype, (unsigned char)0);
        break;

    default:
        if (emode) {
            int __3base2;

            __3base2 = __0this->base__4node;
            if (((0 < __3base2) && (__3base2 <= 255)) && (keys[__0this->base__4node]))
                fprintf(out_file, (const char *)" %s", keys[__0this->base__4node]);
            else
                fputc((int)'?', out_file);
        } else {
            struct ea __0__V44;

            struct ea __0__V45;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"%p->BT::dcl_print(%d)",
                (const struct ea *)(((&__0__V44)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V44)),
                (const struct ea *)((__2__X46 = __0this->base__4node),
                                    (((((&__0__V45)->__O1__2ea.i = __2__X46), 0)), (&__0__V45))),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
    }
}

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);

void dcl_print__4typeFP4name(register struct type *__0this, Pname __1n) {
    Ptype __1t;
    Pptr __1p;
    TOK __1pre;

    register struct dcl_buf *__0__X49;

    register struct dcl_buf *__0__X50;

    struct dcl_buf *__0__X51;

    __1t = __0this;

    __1pre = 0;

    if (__1t == 0)
        error__FiPCc((int)'i', (const char *)"0->dcl_print()");
    if (__1n && (__1n->__O1__4expr.tp != __1t)) {
        struct ea __0__V47;

        struct ea __0__V48;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"not %n'sT (%p)",
            (const struct ea *)(((&__0__V47)->__O1__2ea.p = ((const void *)__1n)), (&__0__V47)),
            (const struct ea *)(((&__0__V48)->__O1__2ea.p = ((const void *)__1t)), (&__0__V48)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__0this->base__4node == 76) {
        {
            {
                Plist __2gl;

                __2gl = (((struct gen *)(((struct gen *)__0this))))->fct_list__3gen;

                for (; __2gl; __2gl = __2gl->l__9name_list) {
                    Pname __3nn;

                    __3nn = __2gl->f__9name_list;
                    dcl_print__4typeFP4name(__3nn->__O1__4expr.tp, __3nn);
                    if (__2gl->l__9name_list)
                        puttok__FUc((unsigned char)72);
                }
                return;
            }
        }
    }

    tbuf = (tbufvec[freetbuf]);
    if (tbuf == 0) {
        if (freetbuf == 9)
            error__FiPCc((int)'i', (const char *)"AT nesting overflow");
        (tbufvec[freetbuf]) = (tbuf = (((struct dcl_buf *)__nw__FUl(sizeof(struct dcl_buf)))));
    }
    freetbuf++;
    if ((__0this->base__4node == 114) &&
        ((((struct basetype *)(((struct basetype *)__0this))))->b_bits__8basetype == 0))
        ((__0__X49 = tbuf),
         (((__0__X49->b__7dcl_buf = 0),
           ((__0__X49->n__7dcl_buf = ((struct name *)0)),
            (__0__X49->cf__7dcl_buf = (__0__X49->li__7dcl_buf = (__0__X49->ri__7dcl_buf = 0))))),
          (((void)0))));
    else
        ((__0__X50 = tbuf),
         (((__0__X50->b__7dcl_buf = 0),
           ((__0__X50->n__7dcl_buf = __1n),
            (__0__X50->cf__7dcl_buf = (__0__X50->li__7dcl_buf = (__0__X50->ri__7dcl_buf = 0))))),
          (((void)0))));
    if (__1n && __1n->n_xref__4name)
        ((__0__X51 = tbuf),
         (((__0__X51->left__7dcl_buf[(++__0__X51->li__7dcl_buf)]) = ((unsigned char)125)),
          (((void)0))));

    {
        bit __1vec_const_flag;
        bit __1prev_const;

        __1vec_const_flag = 0;
        __1prev_const = 0;
        while (__1t) {
            TOK __2k;
            switch (__1t->base__4node) {
                struct dcl_buf *__0__X58;

                register struct dcl_buf *__0__X66;

                struct dcl_buf *__0__X67;

                struct basetype *__2__X68;

                struct dcl_buf *__0__X69;

            case 125:
                __1p = (((struct ptr *)(((struct ptr *)__1t))));
                __2k = ((__1p->b_const__4type && (!__1p->ansi_const__4type)) ? 163 : 125);
                goto ppp;
            case 158:
                __1p = (((struct ptr *)(((struct ptr *)__1t))));
                __2k = ((__1p->b_const__4type && (!__1p->ansi_const__4type)) ? 164 : 158);
            ppp:
                if (__1p->memof__3ptr) {
                    if (emode) {
                        struct dcl_buf *__0__X52;

                        register struct dcl_buf *__0__X53;

                        struct classdef *__2__X54;

                        ((__0__X52 = tbuf),
                         (((__0__X52->left__7dcl_buf[(++__0__X52->li__7dcl_buf)]) = __2k),
                          (((void)0))));
                        ((__0__X53 = tbuf),
                         ((__2__X54 = __1p->memof__3ptr),
                          ((((__0__X53->left__7dcl_buf[(++__0__X53->li__7dcl_buf)]) = 173),
                            ((__0__X53->lnode__7dcl_buf[__0__X53->li__7dcl_buf]) = __2__X54)),
                           (((void)0)))));
                    } else {
                        struct dcl_buf *__0__X57;

                        __1t = skiptypedefs__4typeFv(__1p->typ__5pvtyp);
                        if (__1t->base__4node == 108) {
                            struct dcl_buf *__0__X55;

                            struct basetype *__2__X56;

                            ((__0__X55 = tbuf), ((__2__X56 = mptr_type),
                                                 (((__0__X55->b__7dcl_buf = __2__X56),
                                                   (__0__X55->cf__7dcl_buf = ((unsigned char)0))),
                                                  (((void)0)))));
                            goto zaq;
                        } else
                            ((__0__X57 = tbuf),
                             (((__0__X57->left__7dcl_buf[(++__0__X57->li__7dcl_buf)]) = __2k),
                              (((void)0))));
                    }
                } else
                    ((__0__X58 = tbuf),
                     (((__0__X58->left__7dcl_buf[(++__0__X58->li__7dcl_buf)]) = __2k),
                      (((void)0))));

                __1pre = 125;
                __1t = __1p->typ__5pvtyp;
                break;
            case 110: {
                Pvec __4v;

                __4v = (((struct vec *)(((struct vec *)__1t))));
                if ((Cast && (__1pre != 125)) && (__1pre != 110)) {
                    struct dcl_buf *__0__X59;

                    ((__0__X59 = tbuf), (((__0__X59->left__7dcl_buf[(++__0__X59->li__7dcl_buf)]) =
                                              ((unsigned char)125)),
                                         (((void)0))));
                    __1pre = 125;
                } else {
                    register struct dcl_buf *__0__X60;

                    register struct dcl_buf *__0__X61;

                    if (__1pre == 125)
                        ((__0__X60 = tbuf),
                         ((((__0__X60->left__7dcl_buf[(++__0__X60->li__7dcl_buf)]) =
                                ((unsigned char)40)),
                           (((void)0))),
                          ((((__0__X60->right__7dcl_buf[(++__0__X60->ri__7dcl_buf)]) =
                                 ((unsigned char)41)),
                            ((__0__X60->rnode__7dcl_buf[__0__X60->ri__7dcl_buf]) =
                                 ((struct node *)0))),
                           (((void)0)))));
                    ((__0__X61 = tbuf), ((((__0__X61->right__7dcl_buf[(++__0__X61->ri__7dcl_buf)]) =
                                               ((unsigned char)110)),
                                          ((__0__X61->rnode__7dcl_buf[__0__X61->ri__7dcl_buf]) =
                                               ((struct node *)__4v))),
                                         (((void)0))));
                    __1pre = 110;
                }
                if (ansi_opt) {
                    Ptype __5t;

                    __5t = (((struct vec *)(((struct vec *)__4v))))->typ__5pvtyp;
                    while (__5t && (skiptypedefs__4typeFv(__5t)->base__4node == 110))
                        __5t = (((struct vec *)(((struct vec *)__5t))))->typ__5pvtyp;
                    switch (__5t ? (((int)skiptypedefs__4typeFv(__5t)->base__4node)) : 0) {
                    case 125:
                    case 158:
                    case 5:
                    case 29:
                    case 21:
                    case 121:
                    case 22:
                    case 122:
                    case 15:
                    case 11:
                    case 181:
                    case 114:
                    case 141:
                        break;
                    default:
                        __1vec_const_flag = 1;
                        break;
                    }
                }
                __1t = __4v->typ__5pvtyp;
                break;
            }

            case 108: {
                Pfct __4f;

                register struct dcl_buf *__0__X62;

                register struct dcl_buf *__0__X63;

                struct classdef *__2__X64;

                register struct dcl_buf *__0__X65;

                __4f = (((struct fct *)(((struct fct *)__1t))));
                if (__1pre == 125)
                    ((__0__X62 = tbuf),
                     ((((__0__X62->left__7dcl_buf[(++__0__X62->li__7dcl_buf)]) =
                            ((unsigned char)40)),
                       (((void)0))),
                      ((((__0__X62->right__7dcl_buf[(++__0__X62->ri__7dcl_buf)]) =
                             ((unsigned char)41)),
                        ((__0__X62->rnode__7dcl_buf[__0__X62->ri__7dcl_buf]) = ((struct node *)0))),
                       (((void)0)))));
                else if ((emode && __4f->memof__3fct) && (__1n == 0))
                    ((__0__X63 = tbuf),
                     ((__2__X64 = __4f->memof__3fct),
                      ((((__0__X63->left__7dcl_buf[(++__0__X63->li__7dcl_buf)]) = 173),
                        ((__0__X63->lnode__7dcl_buf[__0__X63->li__7dcl_buf]) = __2__X64)),
                       (((void)0)))));
                ((__0__X65 = tbuf),
                 ((((__0__X65->right__7dcl_buf[(++__0__X65->ri__7dcl_buf)]) = ((unsigned char)108)),
                   ((__0__X65->rnode__7dcl_buf[__0__X65->ri__7dcl_buf]) = ((struct node *)__4f))),
                  (((void)0))));
                __1pre = 108;
                __1t = (__4f->s_returns__3fct ? __4f->s_returns__3fct : __4f->returns__3fct);
                break;
            }

            case 114:
                ((__0__X66 = tbuf),
                 ((((__0__X66->right__7dcl_buf[(++__0__X66->ri__7dcl_buf)]) = ((unsigned char)114)),
                   ((__0__X66->rnode__7dcl_buf[__0__X66->ri__7dcl_buf]) = ((struct node *)__1t))),
                  (((void)0))));
                ((__0__X67 = tbuf),
                 ((__2__X68 = (((struct basetype *)((
                       (struct basetype *)(((struct basetype *)(((struct basetype *)__1t))))
                           ->__O1__8basetype.b_fieldtype))))),
                  (((__0__X67->b__7dcl_buf = __2__X68),
                    (__0__X67->cf__7dcl_buf = ((unsigned char)0))),
                   (((void)0)))));
                __1t = 0;
                break;

            case 0:
                if (!emode)
                    error__FiPCc((int)'i', (const char *)"noBT(B=0)");

                goto dobase;

            case 97:
                if ((Cast && TCast) || (((struct basetype *)(((struct basetype *)__1t))))
                                           ->b_name__8basetype->lex_level__4name) {
                    Ptype __4tt;
                    bit __4ok;

                    __4tt = __1t;
                    __4ok = 0;
                    while (__4tt && (__4tt->base__4node == 97)) {
                        if ((((struct basetype *)(((struct basetype *)__4tt))))->b_const__4type)
                            __4ok = 1;
                        if ((((struct basetype *)(((struct basetype *)__4tt))))
                                ->ansi_const__4type) {
                            __4ok = 0;
                            break;
                        }
                        __4tt = ((((struct basetype *)(((struct basetype *)__4tt))))
                                     ->b_name__8basetype->__O1__4expr.tp);
                    }
                    if ((__4ok && __4tt) && is_ptr_or_ref__4typeFv(__4tt))
                        __4ok = 0;
                    __1t = skiptypedefs__4typeFv(__1t);
                    if (((emode || ansi_opt) && __4ok) && (!__1prev_const)) {
                        fputs((const char *)"const ", out_file);
                        __1prev_const = 1;
                    }
                    break;
                }

            default:
            dobase:
                if (emode) {
                    const char *__4s;
                    Ptype __4tt;

                    __4tt = skiptypedefs__4typeFv(__1t);

                    switch (__4tt->base__4node) {
                    case 6:
                        __4s =
                            (((struct classdef *)(((struct classdef *)__4tt))))->string__8classdef;
                        if ((((((struct templ_classdef *)(((struct templ_classdef *)__4tt))))
                                  ->class_base__8classdef == 4) ||
                             ((((struct templ_classdef *)(((struct templ_classdef *)__4tt))))
                                  ->class_base__8classdef == 5)) ||
                            (!((((__4s[0]) == '_') && ((__4s[1]) == '_')) && ((__4s[2]) == 'C')))) {
                            print__4nameFUc(
                                (((struct basetype *)((
                                     (struct basetype *)(((struct classdef *)((
                                                             (struct classdef *)__4tt))))
                                         ->k_tbl__8classdef->k_name__6ktable->__O1__4expr.tp))))
                                    ->b_name__8basetype,
                                (unsigned char)0);
                            --freetbuf;
                            return;
                        }
                        __4s = (const char *)"class";
                        goto fret;
                    case 13:
                        __4s = (const char *)"enum";
                        goto fret;
                    case 76:
                        __4s = (const char *)"overloaded";
                    fret:
                        fputs(__4s, out_file);
                        freetbuf--;
                        return;
                    }
                }

                ((__0__X69 = tbuf),
                 (((__0__X69->b__7dcl_buf = (((struct basetype *)(((struct basetype *)__1t))))),
                   (__0__X69->cf__7dcl_buf = __1vec_const_flag)),
                  (((void)0))));
                goto zaq;
            }
        }
    zaq:
        put__7dcl_bufFv(tbuf);
        freetbuf--;
    }
}

void dcl_print__3fctFv(register struct fct *__0this) {
    Pname __1nn;
    if (((__0this->fct_base__3fct != 0)) && (current_fct_instantiation != __0this))
        return;

    if (emode) {
        arg_print__3fctFv(__0this);
        return;
    }

    {
        Pname __1at;

        __1at = __0this->f_args__3fct;
        fputc((int)'(', out_file);

        if (ansi_opt) {
            __1at = (__0this->f_this__3fct ? __0this->f_this__3fct
                                           : (__0this->f_result__3fct ? __0this->f_result__3fct
                                                                      : __0this->argtype__3fct));

            if (__1at == 0) {
                if (__0this->nargs_known__3fct == 155) {
                    fputc((int)')', out_file);
                    return;
                }
                puttok__FUc((unsigned char)38);
            } else if (__0this->body__3fct && (Cast == 0)) {
                if (__1at == __0this->argtype__3fct)
                    __1at = __0this->f_args__3fct;
                dcl_print__4nameFUc(__1at, (unsigned char)71);
            } else {
                {
                    {
                        Pname __3a;

                        __3a = __0this->argtype__3fct;

                        for (; __3a; __3a = __3a->__O1__4name.n_list) {
                            Pname __4cln;

                            struct classdef *__0__X70;

                            __4cln = is_cl_obj__4typeFv(__3a->__O1__4expr.tp);
                            if (__4cln && ((__0__X70 = (((struct classdef *)((
                                                (struct classdef *)__4cln->__O1__4expr.tp))))),
                                           (__0__X70->c_itor__8classdef)))
                                __3a->n_xref__4name = 1;
                        }
                        for (__1nn = __1at; __1nn;) {
                            dcl_print__4typeFP4name(__1nn->__O1__4expr.tp, __1nn);

                            if (__1nn = __1nn->__O1__4name.n_list)
                                puttok__FUc((unsigned char)71);
                            else
                                break;
                        }
                    }
                }
            }
            if (__0this->nargs_known__3fct == 155)
                fputs((const char *)",...", out_file);
            fputc((int)')', out_file);
        } else {
            if (__0this->body__3fct && (Cast == 0)) {
                for (__1nn = __1at; __1nn;) {
                    print__4nameFUc(__1nn, (unsigned char)0);
                    if (__1nn = __1nn->__O1__4name.n_list)
                        puttok__FUc((unsigned char)71);
                    else
                        break;
                }

                fputc((int)')', out_file);

            } else
                fputc((int)')', out_file);
        }
    }
}

void print__4stmtFv(struct stmt *__0this);

void print_body__FP3fct(Pfct __1f) {
    if (Cast == 0) {
        if ((ansi_opt == 0) && __1f->f_args__3fct) {
            dcl_print__4nameFUc(__1f->f_args__3fct, (unsigned char)72);
            if ((last_ll == 0) && (last_ll = __1f->body__3fct->where__4stmt.line__3loc))
                putline__3locFv(&__1f->body__3fct->where__4stmt);
        }

        if (MAIN) {
            fputs((const char *)"{ extern void _main(); _main(); ", out_file);
            print__4stmtFv((struct stmt *)__1f->body__3fct);
            puttok__FUc((unsigned char)74);
        } else
            print__4stmtFv((struct stmt *)__1f->body__3fct);
    }
}

void print_members__8classdefFv(struct classdef *__0this);

int align__4typeFv(struct type *__0this);

extern char *make_name__FUc(TOK);

void print_members__8classdefFv(register struct classdef *__0this) {
    int __1i;

    Pbcl __1l;

    __1l = __0this->baselist__8classdef;
    if (__1l) {
        if (__1l->base__4node == 85) {
            print_members__8classdefFv(__1l->bclass__6basecl);

            {
                int __3boff;
                int __3ba;
                int __3xtra;
                int __3waste;

                __3boff = __1l->bclass__6basecl->real_size__8classdef;
                __3ba = align__4typeFv((struct type *)__1l->bclass__6basecl);
                __3xtra = (__3boff % __3ba);
                __3waste = (__3xtra ? (__3ba - __3xtra) : 0);
                if (__3waste) {
                    char *__4s;

                    __4s = make_name__FUc((unsigned char)'W');
                    fprintf(out_file, (const char *)"char %s[%d];\n", __4s, __3waste);
                    __dl__FPv((void *)__4s);
                }
                __1l = __1l->next__6basecl;
            }
        }

        for (; __1l; __1l = __1l->next__6basecl)
            if (__1l->base__4node == 85) {
                Pclass __3bcl;
                char *__3str;
                const char *__3cs;

                __3bcl = __1l->bclass__6basecl;
                __3str = 0;
                __3cs = (__3bcl->nested_sig__4type ? (((const char *)__3bcl->nested_sig__4type))
                                                   : __3bcl->string__8classdef);
                if (__3bcl->lex_level__4type && (!__3bcl->nested_sig__4type))
                    __3str = __3bcl->local_sig__4type;
                puttok__FUc((unsigned char)32);
                if (__3bcl->nested_sig__4type)
                    fputs((const char *)"__", out_file);
                (fputs(__3str ? (((const char *)__3str)) : __3cs, out_file),
                 fputc((int)' ', out_file));
                (fputc((int)'O', out_file), fputs(__3bcl->string__8classdef, out_file));
                puttok__FUc((unsigned char)72);
            }
    }

    {
        {
            Pname __1nn;

            struct table *__0__X71;

            int __2__X72;

            struct table *__0__X73;

            int __2__X74;

            __1nn = ((__0__X73 = __0this->memtbl__8classdef),
                     ((__2__X74 = (__1i = 1)),
                      ((((__2__X74 <= 0) || (__0__X73->free_slot__5table <= __2__X74))
                            ? (((struct name *)0))
                            : (__0__X73->entries__5table[__2__X74])))));

            for (; __1nn;
                 __1nn = (__1nn->n_tbl_list__4name
                              ? __1nn->n_tbl_list__4name
                              : ((__0__X71 = __0this->memtbl__8classdef),
                                 ((__2__X72 = (++__1i)),
                                  ((((__2__X72 <= 0) || (__0__X71->free_slot__5table <= __2__X72))
                                        ? (((struct name *)0))
                                        : (__0__X71->entries__5table[__2__X72]))))))) {
                if (__1nn->base__4node == 123)
                    continue;

                if (((((((__1nn->base__4node == 85) && (__1nn->n_anon__4name == 0)) &&
                        (__1nn->__O1__4expr.tp->base__4node != 108)) &&
                       (__1nn->__O1__4expr.tp->base__4node != 76)) &&
                      (__1nn->__O1__4expr.tp->base__4node != 6)) &&
                     (__1nn->__O1__4expr.tp->base__4node != 13)) &&
                    (__1nn->n_stclass__4name != 31)) {
                    Pexpr __3i;

                    __3i = __1nn->__O3__4expr.n_initializer;
                    __1nn->__O3__4expr.n_initializer = 0;
                    ;
                    dcl_print__4nameFUc(__1nn, (unsigned char)0);
                    __1nn->__O3__4expr.n_initializer = __3i;
                }
            }

            for (__1l = __0this->baselist__8classdef; __1l; __1l = __1l->next__6basecl)
                if ((__1l->base__4node == 77) && __1l->ptr_offset__6basecl) {
                    Pclass __2bcl;
                    char *__2str;
                    const char *__2cs;

                    __2bcl = __1l->bclass__6basecl;
                    __2str = 0;
                    __2cs = (__2bcl->nested_sig__4type ? (((const char *)__2bcl->nested_sig__4type))
                                                       : __2bcl->string__8classdef);

                    if (__2bcl->lex_level__4type && (!__2bcl->nested_sig__4type))
                        __2str = __2bcl->local_sig__4type;

                    puttok__FUc((unsigned char)32);
                    if (__2bcl->nested_sig__4type)
                        fputs((const char *)"__", out_file);
                    (fputs(__2str ? (((const char *)__2str)) : __2cs, out_file),
                     fputc((int)' ', out_file));
                    fputc((int)'*', out_file);
                    (fputc((int)'P', out_file), fputs(__2bcl->string__8classdef, out_file));
                    puttok__FUc((unsigned char)72);
                }
        }
    }
}

struct vl *vlist = 0;

extern char *vtbl_name__FPCcT1(const char *, const char *);

extern void really_really_print__FP8classdefP4virtPCcPc(Pclass __0cl, Pvirt __0vtab,
                                                        const char *__0s, char *__0ss);

extern char *strcat(char *, const char *);

extern void ptbl_add_pair__FPCcT1(const char *, const char *);

int p2__FP4nameP4typeP8classdefP4virtPc(Pname __1nn, Ptype __1t, Pclass __1cl, Pvirt __1vtab,
                                        char *__1s) {
    int __1init;

    if (__1t->base__4node == 108) {
        Pfct __2f;

        __2f = (((struct fct *)(((struct fct *)__1t))));

        if ((((__1nn->__O3__4expr.n_initializer || (__1nn->n_sto__4name == 31)) ||
              __2f->f_inline__3fct) ||
             __2f->f_imeasure__3fct) ||
            (__2f->f_virtual__3fct == 0))
            return 0;

        __1init = (__2f->body__3fct != 0);
    } else
        __1init = (__1nn->__O3__4expr.n_initializer != 0);

    {
        int __1oo;

        __1oo = vtbl_opt;
        vtbl_opt = 1;
        {
            const char *__1cs;
            const char *__1sstr;
            const char *__1ss;

            __1cs = (__1cl->nested_sig__4type ? (((const char *)__1cl->nested_sig__4type))
                                              : __1cl->string__8classdef);
            __1sstr = (const char *)((__1cl->lex_level__4type && (!__1cl->nested_sig__4type))
                                         ? __1cl->local_sig__4type
                                         : (((char *)0)));
            __1ss =
                (const char *)vtbl_name__FPCcT1(__1vtab->string__4virt, __1sstr ? __1sstr : __1cs);

            if (__1init) {
                really_really_print__FP8classdefP4virtPCcPc(__1cl, __1vtab, __1ss, __1s);
            } else {
                char *__2vstr;

                Pname __2nn;

                __2vstr = 0;
                if (__1vtab && __1vtab->string__4virt) {
                    __2vstr = (((char *)__nw__FUl(
                        (size_t)((sizeof(char)) *
                                 ((strlen(__1vtab->string__4virt) + __1cl->c_strlen__8classdef) +
                                  1)))));
                    strcpy(__2vstr, __1vtab->string__4virt);
                    strcat(__2vstr, __1cl->string__8classdef);
                };
                if (__2nn = look__5tableFPCcUc(
                        ptbl, __2vstr ? (((const char *)__2vstr)) : __1cl->string__8classdef,
                        (unsigned char)0)) {
                    fprintf(out_file, (const char *)"extern struct __mptr %s[];\n", __1ss);
                    (__1s[2]) = 'p';
                    ptbl_add_pair__FPCcT1((const char *)__1s, __1ss);
                    __2nn->n_key__4name = 159;
                }
                __dl__FPv((void *)__2vstr);
            }
            vtbl_opt = __1oo;

            __dl__FPv((void *)(((char *)__1ss)));

            return 1;
        }
    }
}

void really_print__8classdefFP4virt(register struct classdef *__0this, Pvirt __1vtab) {
    int __1oo;

    __1oo = vtbl_opt;
    vtbl_opt = -1;
    {
        const char *__1cs;
        char *__1str;
        char *__1s;

        int __1i;

        __1cs = (__0this->nested_sig__4type ? (((const char *)__0this->nested_sig__4type))
                                            : __0this->string__8classdef);
        __1str = ((__0this->lex_level__4type && (!__0this->nested_sig__4type))
                      ? __0this->local_sig__4type
                      : (((char *)0)));
        __1s = vtbl_name__FPCcT1(__1vtab->string__4virt, __1str ? (((const char *)__1str)) : __1cs);
        vtbl_opt = __1oo;

        ;
        {
            {
                Pname __1nn;

                struct table *__0__X75;

                int __2__X76;

                struct table *__0__X77;

                int __2__X78;

                __1nn = ((__0__X77 = __0this->memtbl__8classdef),
                         ((__2__X78 = (__1i = 1)),
                          ((((__2__X78 <= 0) || (__0__X77->free_slot__5table <= __2__X78))
                                ? (((struct name *)0))
                                : (__0__X77->entries__5table[__2__X78])))));

                for (; __1nn;
                     __1nn =
                         (__1nn->n_tbl_list__4name
                              ? __1nn->n_tbl_list__4name
                              : ((__0__X75 = __0this->memtbl__8classdef),
                                 ((__2__X76 = (++__1i)),
                                  ((((__2__X76 <= 0) || (__0__X75->free_slot__5table <= __2__X76))
                                        ? (((struct name *)0))
                                        : (__0__X75->entries__5table[__2__X76]))))))) {
                    if ((__1nn->base__4node == 123) || (__1nn->__O1__4expr.tp == 0))
                        continue;
                    {
                        Ptype __2t;

                        __2t = skiptypedefs__4typeFv(__1nn->__O1__4expr.tp);

                        if (__2t)
                            switch (__2t->base__4node) {
                            case 108:
                                if (p2__FP4nameP4typeP8classdefP4virtPc(__1nn, __2t, __0this,
                                                                        __1vtab, __1s))
                                    goto xyzzy;

                                break;

                            case 76: {
                                {
                                    {
                                        Plist __4gl;

                                        __4gl = (((struct gen *)(((struct gen *)__2t))))
                                                    ->fct_list__3gen;

                                        for (; __4gl; __4gl = __4gl->l__9name_list)
                                            if (p2__FP4nameP4typeP8classdefP4virtPc(
                                                    __4gl->f__9name_list,
                                                    __4gl->f__9name_list->__O1__4expr.tp, __0this,
                                                    __1vtab, __1s))
                                                goto xyzzy;
                                    }
                                }
                            }
                            }
                    }
                }

                {
                    char *__2ss;

                    __2ss = vtbl_name__FPCcT1(__1vtab->string__4virt,
                                              __1str ? (((const char *)__1str)) : __1cs);

                    if (vtbl_opt)
                        really_really_print__FP8classdefP4virtPCcPc(__0this, __1vtab,
                                                                    (const char *)__2ss, __1s);
                    else {
                        char *__3vstr;

                        __3vstr = 0;
                        if (__1vtab && __1vtab->string__4virt) {
                            __3vstr = (((char *)__nw__FUl(
                                (size_t)((sizeof(char)) * ((strlen(__1vtab->string__4virt) +
                                                            __0this->c_strlen__8classdef) +
                                                           1)))));
                            strcpy(__3vstr, __1vtab->string__4virt);
                            strcat(__3vstr, __0this->string__8classdef);
                        }
                        {
                            Pname __3nn;
                            if (__3nn = look__5tableFPCcUc(ptbl,
                                                           __3vstr ? (((const char *)__3vstr))
                                                                   : __0this->string__8classdef,
                                                           (unsigned char)0)) {
                                fprintf(out_file, (const char *)"extern struct __mptr %s[];\n",
                                        __2ss);
                                (__1s[2]) = 'p';
                                ptbl_add_pair__FPCcT1((const char *)__1s, (const char *)__2ss);
                                __3nn->n_key__4name = 159;
                            }
                            __dl__FPv((void *)__3vstr);
                        }
                    }
                    __dl__FPv((void *)__2ss);
                }
            xyzzy:
                __dl__FPv((void *)__1s);
            }
        }
    }
}

struct velem { /* sizeof velem == 16 */
    Pname n__5velem;
    int offset__5velem;
};

extern char *strdup(const char *);

void really_really_print__FP8classdefP4virtPCcPc(Pclass __1cl, Pvirt __1vtab, const char *__1s,
                                                 char *__1ss) {
    Pname __1nn;
    int __1i;

    Pname __1n;

    for (__1i = 0; __1nn = (__1vtab->virt_init__4virt[__1i]).n__5velem; __1i++) {
        if (__1nn->__O1__4expr.tp->base__4node == 76) {
            __1nn = (((struct gen *)(((struct gen *)__1nn->__O1__4expr.tp))))
                        ->fct_list__3gen->f__9name_list;
        }
        {
            Pfct __2f;

            __2f = (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))));
            if (__1nn->__O3__4expr.n_initializer) {
                static int __3pv;
                if (__3pv == 0) {
                    fprintf(out_file, (const char *)"char __pure_virtual_called();\n");
                    __3pv = 1;
                }
                continue;
            }
            if (__2f->base__4node != 108) {
                struct ea __0__V79;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"vtbl %n",
                    (const struct ea *)(((&__0__V79)->__O1__2ea.p = ((const void *)__1nn)),
                                        (&__0__V79)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__1nn->n_dcl_printed__4name == 0) {
                if ((__2f->f_inline__3fct && vtbl_opt) || (ansi_opt && (__1nn->n_sto__4name == 31)))
                    puttok__FUc((unsigned char)31);
                if (__2f->f_result__3fct == 0)
                    make_res__FP3fct(__2f);
                {
                    Ptype __3r;

                    __3r = (__2f->s_returns__3fct ? __2f->s_returns__3fct : __2f->returns__3fct);
                    print__4typeFv(__3r);
                    print__4nameFUc(__1nn, (unsigned char)0);
                    if (ansi_opt)
                        dcl_print__3fctFv(__2f);
                    else
                        fputs((const char *)"()", out_file);
                    puttok__FUc((unsigned char)72);
                    __1nn->n_dcl_printed__4name = 1;
                }
            }
        }
    }

    fprintf(out_file, (const char *)"struct __mptr %s[] = {0,0,0,\n", __1s);

    ;
    for (__1i = 0; __1n = (__1vtab->virt_init__4virt[__1i]).n__5velem; __1i++) {
        if (__1n->__O1__4expr.tp->base__4node == 76) {
            __1n = (((struct gen *)(((struct gen *)__1n->__O1__4expr.tp))))
                       ->fct_list__3gen->f__9name_list;
        }
        if (__1n->__O3__4expr.n_initializer)
            fputs((const char *)"0,0,(__vptp)__pure_virtual_called,\n", out_file);
        else {
            fprintf(out_file, (const char *)"%d,0,(__vptp)",
                    -(__1vtab->virt_init__4virt[__1i]).offset__5velem);
            print__4nameFUc(__1n, (unsigned char)0);
            __1n->n_addr_taken__4name = 1;
            fputs((const char *)",\n", out_file);
        }
    }
    fputs((const char *)"0,0,0};\n", out_file);

    (__1ss[2]) = 'p';
    {
        char *__1bs;

        Pname __1nm;
        char *__1cstr;
        const char *__1vstr;
        const char *__1cs;

        __1bs = strdup(__1s);
        (__1bs[2]) = 'v';
        ptbl_add_pair__FPCcT1((const char *)__1ss, (const char *)__1bs);
        __dl__FPv((void *)__1bs);

        ;
        __1cstr = 0;
        __1vstr = 0;
        __1cs = (__1cl->nested_sig__4type ? (((const char *)__1cl->nested_sig__4type))
                                          : __1cl->string__8classdef);
        if (__1cl->lex_level__4type && (!__1cl->nested_sig__4type))
            __1cstr = __1cl->local_sig__4type;
        if (__1vtab && __1vtab->string__4virt) {
            char *__2str_tmp;

            __2str_tmp = (((char *)__nw__FUl(
                (size_t)((sizeof(char)) *
                         ((strlen(__1vtab->string__4virt) +
                           (__1cstr ? strlen((const char *)__1cstr) : strlen(__1cs))) +
                          1)))));
            strcpy(__2str_tmp, __1vtab->string__4virt);
            strcat(__2str_tmp, __1cstr ? (((const char *)__1cstr)) : __1cs);
            __1vstr = (const char *)__2str_tmp;
        }

        if (__1vstr == 0)
            __1vstr =
                (__1cstr ? (((const char *)__1cstr)) : (__1cs ? __1cs : __1cl->string__8classdef));
        if (__1nm = look__5tableFPCcUc(ptbl, __1vstr, (unsigned char)0)) {
            __1nm->n_key__4name = 159;
            if (((__1vstr != (const char *)__1cstr) && (__1vstr != __1cs)) &&
                (__1vstr != __1cl->string__8classdef))
                __dl__FPv((void *)(((char *)__1vstr)));

        } else if (look__5tableFPCcUc(ptbl, __1vstr, (unsigned char)159) == 0)
            insert__5tableFP4nameUc(ptbl, __ct__4nameFPCc((struct name *)0, __1vstr),
                                    (unsigned char)159);
        else if (((__1vstr != (const char *)__1cstr) && (__1vstr != __1cl->string__8classdef)) &&
                 (__1vstr != __1cs))
            __dl__FPv((void *)(((char *)__1vstr)));
    }
}

extern int isalpha(int);

extern int isdigit(int);

char *vtbl_name__FPCcT1(const char *__1s1, const char *__1s2) {
    const char *__1s3;

    int __1ll;
    int __1ll2;
    int __1ll3;
    int __1sz;

    __1s3 = (((vtbl_opt == -1) && ((*src_file_name))) ? src_file_name : (((const char *)0)));

    __1ll = (__1s1 ? strlen(__1s1) : (((unsigned long)0)));
    __1ll2 = strlen(__1s2);
    __1ll3 = (__1s3 ? strlen(__1s3) : (((unsigned long)0)));
    __1sz = (((((__1ll + __1ll2) + __1ll3) + 20) / 32) + 1);

    __1sz *= 32;
    {
        char *__1buf;

        __1buf = (((char *)__nw__FUl((size_t)((sizeof(char)) * __1sz))));
        if (__1s3) {
            if (__1s1)
                sprintf(__1buf, (const char *)"__vtbl__%d%s__%d%s__%s", __1ll, __1s1, __1ll2, __1s2,
                        __1s3);
            else
                sprintf(__1buf, (const char *)"__vtbl__%d%s__%s", __1ll2, __1s2, __1s3);

        } else if (__1s1)
            sprintf(__1buf, (const char *)"__vtbl__%d%s__%d%s", __1ll, __1s1, __1ll2, __1s2);
        else
            sprintf(__1buf, (const char *)"__vtbl__%d%s", __1ll2, __1s2);

        if (vtbl_opt == -1) {
            {
                {
                    char *__2p;

                    __2p = ((__1buf + __1ll2) + 11);

                    for (; (*__2p); __2p++)
                        if ((!isalpha((int)((*__2p)))) && (!isdigit((int)((*__2p)))))
                            ((*__2p)) = '_';
                }
            }
        }

        return __1buf;
    }
}

void print_all_vtbls__8classdefFP8classdef(register struct classdef *__0this, Pclass __1bcl) {
    {
        {
            Pvirt __1blist;

            __1blist = __1bcl->virt_list__8classdef;

            for (; __1blist; __1blist = __1blist->next__4virt) {
                struct classdef *__1__X80;

                struct classdef *__1__X81;

                register struct vl *__0__X82;

                struct vl *__2__X83;

                if (!((__1__X80 = __0this),
                      ((__1__X81 = __1blist->vclass__4virt),
                       (((__1__X80 == __1__X81)
                             ? 1
                             : ((__1__X80 && __1__X81) ? (((int)same_class__8classdefFP8classdefi(
                                                             __1__X80, __1__X81, 0)))
                                                       : 0))))))
                    continue;
                if (__1blist->printed__4virt)
                    continue;
                vlist =
                    ((__0__X82 = 0),
                     ((__2__X83 = vlist),
                      (((__0__X82 ||
                         (__0__X82 = (struct vl *)__nw__FUl((unsigned long)(sizeof(struct vl)))))
                            ? ((__0__X82->cl__2vl = __0this),
                               ((__0__X82->vt__2vl = __1blist), (__0__X82->next__2vl = __2__X83)))
                            : 0),
                       __0__X82)));
                __1blist->printed__4virt = 1;
            }

            {
                {
                    Pbcl __1b;

                    struct classdef *__1__X84;

                    struct classdef *__1__X85;

                    __1b = __1bcl->baselist__8classdef;

                    for (; __1b; __1b = __1b->next__6basecl)
                        print_all_vtbls__8classdefFP8classdef(__0this, __1b->bclass__6basecl);

                    if (((__1__X84 = __0this),
                         ((__1__X85 = __1bcl),
                          (((__1__X84 == __1__X85)
                                ? 1
                                : ((__1__X84 && __1__X85)
                                       ? (((int)same_class__8classdefFP8classdefi(__1__X84,
                                                                                  __1__X85, 0)))
                                       : 0))))))
                        __0this->c_body__8classdef = 0;
                }
            }
        }
    }
}

extern Pname k_find_name__FPCcP6ktableUc(const char *, Pktab, TOK);

void dcl_print__8classdefFP4name(register struct classdef *__0this, Pname __1n) {
    int __1i;
    Pname __1nn;

    struct table *__0__X86;

    int __2__X87;

    struct table *__0__X88;

    int __2__X89;

    __0this->defined__4type |= 010;

    ;
    if (((__0this->c_body__8classdef == 0) || (__0this->c_body__8classdef == 3)) ||
        ((__0this->defined__4type & 01) == 0))
        return;
    __0this->c_body__8classdef = 3;

    ;
    __1nn =
        ((__0__X86 = __0this->memtbl__8classdef),
         ((__2__X87 = (__1i = 1)), ((((__2__X87 <= 0) || (__0__X86->free_slot__5table <= __2__X87))
                                         ? (((struct name *)0))
                                         : (__0__X86->entries__5table[__2__X87])))));
    for (; __1nn; __1nn = (__1nn->n_tbl_list__4name
                               ? __1nn->n_tbl_list__4name
                               : ((__0__X88 = __0this->memtbl__8classdef),
                                  ((__2__X89 = (++__1i)),
                                   ((((__2__X89 <= 0) || (__0__X88->free_slot__5table <= __2__X89))
                                         ? (((struct name *)0))
                                         : (__0__X88->entries__5table[__2__X89]))))))) {
        if (__1nn->base__4node == 123)
            continue;

        if ((((__1nn->base__4node == 85) && (__1nn->n_anon__4name == 0)) &&
             (__1nn->__O1__4expr.tp->base__4node == 6)) &&
            ((((struct classdef *)(((struct classdef *)__1nn->__O1__4expr.tp))))
                 ->c_body__8classdef == 1))
            dcl_print__8classdefFP4name(
                ((struct classdef *)(((struct classdef *)__1nn->__O1__4expr.tp))), __1nn);
        else if ((__1nn->base__4node == 123) && (__1nn->__O1__4expr.tp->base__4node != 119))
            dcl_print__4nameFUc(__1nn, (unsigned char)0);
        else if (((__1nn->__O1__4expr.tp && (__1nn->n_anon__4name == 0)) &&
                  (__1nn->__O1__4expr.tp->base__4node == 13)) &&
                 ((((struct enumdef *)(((struct enumdef *)__1nn->__O1__4expr.tp))))
                      ->e_body__7enumdef != 3))
            dcl_print__7enumdefFP4name(
                ((struct enumdef *)(((struct enumdef *)__1nn->__O1__4expr.tp))), __1nn);
    }

    __1n = k_find_name__FPCcP6ktableUc(__0this->string__8classdef, Ctbl, (unsigned char)159);

    if (__1n) {
        if ((__1n->where__4name.line__3loc != last_line.line__3loc) ||
            (__1n->where__4name.file__3loc != last_line.file__3loc))
            if (last_ll = __1n->where__4name.line__3loc)
                putline__3locFv(&__1n->where__4name);
            else
                putline__3locFv(&last_line);
    }

    {
        TOK __1c;

        __1c = ((__0this->csu__8classdef == 6) ? (((unsigned int)32))
                                               : (((unsigned int)__0this->csu__8classdef)));
        puttok__FUc(__1c);

        {
            char *__1str;

            __1str = 0;

            if (__0this->lex_level__4type && (!__0this->nested_sig__4type))
                __1str = __0this->local_sig__4type;
            if (__0this->nested_sig__4type)
                fputs((const char *)" __", out_file);
            (fputs(__1str
                       ? (((const char *)__1str))
                       : (__0this->nested_sig__4type ? (((const char *)__0this->nested_sig__4type))
                                                     : __0this->string__8classdef),
                   out_file),
             fputc((int)' ', out_file));

            {
                int __1dvirt;

                __1dvirt = 0;

                if (__0this->nested_sig__4type)
                    fprintf(out_file, (const char *)"{\t/* sizeof __%s == %d */\n",
                            __0this->nested_sig__4type, __0this->obj_size__8classdef);
                else
                    fprintf(out_file, (const char *)"{\t/* sizeof %s == %d */\n",
                            __1str ? (((const char *)__1str)) : __0this->string__8classdef,
                            __0this->obj_size__8classdef);
                if (last_ll)
                    last_line.line__3loc++;

                begin_mem__Fv();
                print_members__8classdefFv(__0this);
                end_mem__Fv();
                {
                    {
                        Pbcl __1b;

                        struct table *__0__X90;

                        int __2__X91;

                        struct table *__0__X92;

                        int __2__X93;

                        __1b = __0this->baselist__8classdef;

                        for (; __1b; __1b = __1b->next__6basecl) {
                            if (__1b->base__4node != 77)
                                continue;
                            {
                                Pclass __2bcl;

                                __2bcl = __1b->bclass__6basecl;
                                __1dvirt += __2bcl->virt_count__8classdef;
                                if (__1b->allocated__6basecl == 0)
                                    continue;
                                {
                                    char *__2str;
                                    const char *__2cs;

                                    __2str = 0;
                                    __2cs = (__2bcl->nested_sig__4type
                                                 ? (((const char *)__2bcl->nested_sig__4type))
                                                 : __2bcl->string__8classdef);
                                    if (__2bcl->lex_level__4type && (!__2bcl->nested_sig__4type))
                                        __2str = __2bcl->local_sig__4type;
                                    puttok__FUc((unsigned char)32);
                                    if (__2bcl->nested_sig__4type)
                                        fputs((const char *)"__", out_file);
                                    (fputs(__2str ? (((const char *)__2str)) : __2cs, out_file),
                                     fputc((int)' ', out_file));
                                    (fputc((int)'O', out_file),
                                     fputs(__2bcl->string__8classdef, out_file));
                                    puttok__FUc((unsigned char)72);
                                }
                            }
                        }
                        fputs((const char *)"};\n", out_file);
                        if (last_ll)
                            last_line.line__3loc++;

                        for (__1nn =
                                 ((__0__X90 = __0this->memtbl__8classdef),
                                  ((__2__X91 = (__1i = 1)),
                                   ((((__2__X91 <= 0) || (__0__X90->free_slot__5table <= __2__X91))
                                         ? (((struct name *)0))
                                         : (__0__X90->entries__5table[__2__X91])))));
                             __1nn;
                             __1nn = (__1nn->n_tbl_list__4name
                                          ? __1nn->n_tbl_list__4name
                                          : ((__0__X92 = __0this->memtbl__8classdef),
                                             ((__2__X93 = (++__1i)),
                                              ((((__2__X93 <= 0) ||
                                                 (__0__X92->free_slot__5table <= __2__X93))
                                                    ? (((struct name *)0))
                                                    : (__0__X92->entries__5table[__2__X93]))))))) {

                            if (__1nn->base__4node == 123)
                                continue;
                            if ((__1nn->base__4node == 85) && (__1nn->n_anon__4name == 0)) {
                                Ptype __3t;

                                __3t = __1nn->__O1__4expr.tp;
                                switch (__3t->base__4node) {
                                case 108:
                                case 76:
                                    break;
                                default:
                                    if (__1nn->n_stclass__4name == 31) {
                                        TOK __5b;

                                        __5b = __1nn->n_sto__4name;
                                        __1nn->n_sto__4name =
                                            (__1nn->n_evaluated__4name ? (((unsigned int)31))
                                                                       : (((unsigned int)__5b)));
                                        dcl_print__4nameFUc(__1nn, (unsigned char)0);
                                        __1nn->n_sto__4name = __5b;
                                    }
                                }
                            }
                        }
                        if (vtbl_opt != -1)
                            print_all_vtbls__8classdefFP8classdef(__0this, __0this);
                    }
                }
            }
        }
    }
}

char *make_local_name__FP4typeP4name(Ptype __1tt, Pname __1fn) {
    char *__1buf;
    int __1tlen;
    const char *__1tstring;
    switch (__1tt->base__4node) {
    case 6:
        __1tlen = (((struct classdef *)(((struct classdef *)__1tt))))->c_strlen__8classdef;
        __1tstring = (((struct classdef *)(((struct classdef *)__1tt))))->string__8classdef;
        break;
    case 13:
        __1tlen = (((struct enumdef *)(((struct enumdef *)__1tt))))->e_strlen__7enumdef;
        __1tstring = (((struct enumdef *)(((struct enumdef *)__1tt))))->string__7enumdef;
        break;
    default: {
        struct ea __0__V94;

        struct ea __0__V95;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"make_local_name(%t,%n )",
            (const struct ea *)(((&__0__V94)->__O1__2ea.p = ((const void *)__1tt)), (&__0__V94)),
            (const struct ea *)(((&__0__V95)->__O1__2ea.p = ((const void *)__1fn)), (&__0__V95)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }
    {
        char *__1lcl;

        __1lcl = make_name__FUc((unsigned char)'L');
        if (((__1fn == 0) || (__1fn->__O1__4expr.tp == 0)) ||
            (__1fn->__O1__4expr.tp->base__4node != 108)) {
            struct ea __0__V96;

            struct ea __0__V97;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"localC %smissing or badFN%n",
                (const struct ea *)(((&__0__V96)->__O1__2ea.p = ((const void *)__1tstring)),
                                    (&__0__V96)),
                (const struct ea *)(((&__0__V97)->__O1__2ea.p = ((const void *)__1fn)),
                                    (&__0__V97)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        __1tt->in_fct__4type = __1fn;
        {
            const char *__1fsig;

            __1fsig = (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))))->f_signature__3fct;
            if (__1fsig == 0)
                __1fsig = (const char *)local_sign__FP4type(__1fn->__O1__4expr.tp);
            {
                const char *__1fs;
                int __1name_len;
                int __1sz;

                __1fs = __1fn->__O2__4expr.string;
                __1name_len = ((((__1tlen + strlen(__1fsig)) + strlen(__1fs)) +
                                strlen((const char *)__1lcl)) +
                               4);

                __1sz = (((__1name_len + 20) / 32) + 1);

                if ((((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))))->memof__3fct == 0) {
                    __1sz *= 32;
                    __1buf = (((char *)__nw__FUl((size_t)((sizeof(char)) * __1sz))));

                    sprintf(__1buf, (const char *)"%s__%s__%s%s", __1tstring, __1fs, __1fsig,
                            __1lcl);

                } else {
                    const char *__2cs;
                    int __2len;

                    __2cs = (((struct classdef *)((
                                 (struct classdef *)(((struct fct *)((
                                                         (struct fct *)__1fn->__O1__4expr.tp))))
                                     ->memof__3fct))))
                                ->string__8classdef;
                    __2len = (((struct classdef *)((
                                  (struct classdef *)(((struct fct *)((
                                                          (struct fct *)__1fn->__O1__4expr.tp))))
                                      ->memof__3fct))))
                                 ->c_strlen__8classdef;
                    if (__2len < 10)
                        ++__1name_len;
                    else if (__2len > 99)
                        __1name_len += 3;
                    else
                        __1name_len += 2;
                    __1name_len += __2len;
                    __1sz = (((__1name_len + 20) / 32) + 1);
                    __1sz *= 32;
                    __1buf = (((char *)__nw__FUl((size_t)((sizeof(char)) * __1sz))));

                    sprintf(__1buf, (const char *)"%s__%s__%d%s%s%s", __1tstring, __1fs, __2len,
                            __2cs, __1fsig, __1lcl);
                }

                if (__1tt->base__4node == 6)
                    (((struct classdef *)(((struct classdef *)__1tt))))->c_strlen__8classdef =
                        __1name_len;
                else
                    (((struct enumdef *)(((struct enumdef *)__1tt))))->e_strlen__7enumdef =
                        __1name_len;
                return __1buf;
            }
        }
    }
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
