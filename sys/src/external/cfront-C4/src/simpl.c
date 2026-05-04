
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

Pname new_fct = 0;
Pname del_fct = 0;
Pname vec_new_fct = 0;
Pname vec_del_fct = 0;

Pstmt del_list = 0;
Pstmt break_del_list = 0;
Pstmt continue_del_list = 0;

Pname curr_fct = 0;
Pexpr init_list = 0;
Pexpr one = 0;

Ptype Pfct_type = 0;
Ptype Pvptr_type = 0;
Pbase mptr_type = 0;
Ptype size_t_type = 0;

struct loc no_where = {0};

int imeasure = 0;

static Pclass topclass;

int replace_ret__FP4stmtiP5table(Pstmt __1sl, int __1level, Ptable __1tbl);

extern char *make_name__FUc(TOK);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

int replace_ret__FP4stmtiP5table(Pstmt __1sl, int __1level, Ptable __1tbl) {
    int __1nl;
    Pstmt __1ls;
    static char *__1buf;

    __1nl = 0;

    if (!__1level)
        __1buf = 0;

    {
        {
            Pstmt __1s;

            __1s = __1sl;

            for (; __1s; ((__1ls = __1s), (__1s = __1s->s_list__4stmt))) {
                switch (__1s->base__4node) {
                case 39:
                case 10:
                case 16:
                case 33:
                case 116:
                case 115:
                case 4:
                case 8:
                    __1nl += replace_ret__FP4stmtiP5table(__1s->s__4stmt, __1level + 1, __1tbl);
                    break;
                case 20:
                    __1nl += replace_ret__FP4stmtiP5table(__1s->s__4stmt, __1level + 1, __1tbl);
                    if (__1s->__O3__4stmt.else_stmt)
                        __1nl += replace_ret__FP4stmtiP5table(__1s->__O3__4stmt.else_stmt,
                                                              __1level + 1, __1tbl);
                    break;
                case 166:
                    __1nl += replace_ret__FP4stmtiP5table(__1s->s__4stmt, __1level + 1, __1tbl);
                    __1nl +=
                        replace_ret__FP4stmtiP5table(__1s->__O2__4stmt.s2, __1level + 1, __1tbl);
                    break;
                case 28: {
                    if (!__1buf)
                        __1buf = make_name__FUc((unsigned char)'Z');
                    {
                        Pname __4lab;

                        struct lstmt *__0__X17;

                        struct loc __2__X18;

                        __4lab = insert__5tableFP4nameUc(
                            __1tbl, __ct__4nameFPCc((struct name *)0, (const char *)__1buf),
                            (unsigned char)115);

                        __1nl++;
                        __1s->gt__4stmt =
                            (struct stmt
                                 *)((__0__X17 = 0),
                                    ((__2__X18 = __1s->where__4stmt),
                                     (((__0__X17 || (__0__X17 = (struct lstmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct lstmt)))))
                                           ? ((__0__X17 = (struct lstmt *)__ct__4stmtFUc3locP4stmt(
                                                   ((struct stmt *)__0__X17), ((unsigned char)19),
                                                   __2__X18, ((struct stmt *)0))),
                                              (__0__X17->__O1__4stmt.d = __4lab))
                                           : 0),
                                      __0__X17)));
                        break;
                    }
                }
                }
            }

            if ((!__1level) && __1nl) {
                Pname __2lab;

                struct estmt *__0__X19;

                struct loc __2__X20;

                struct expr *__2__X21;

                struct lstmt *__0__X22;

                struct loc __2__X23;

                struct stmt *__2__X24;

                __2lab = look__5tableFPCcUc(__1tbl, (const char *)__1buf, (unsigned char)115);

                __1ls->s_list__4stmt =
                    (struct stmt
                         *)((__0__X22 = 0),
                            ((__2__X23 = curloc),
                             ((__2__X24 = (struct stmt
                                               *)((__0__X19 = 0),
                                                  ((__2__X20 = curloc),
                                                   ((__2__X21 = dummy),
                                                    (((__0__X19 ||
                                                       (__0__X19 = (struct estmt *)__nw__4stmtSFUl(
                                                            (unsigned long)(sizeof(struct estmt)))))
                                                          ? ((__0__X19 = (struct estmt *)
                                                                  __ct__4stmtFUc3locP4stmt(
                                                                      ((struct stmt *)__0__X19),
                                                                      ((unsigned char)72), __2__X20,
                                                                      ((struct stmt *)0))),
                                                             (__0__X19->__O2__4stmt.e = __2__X21))
                                                          : 0),
                                                     __0__X19))))),
                              (((__0__X22 || (__0__X22 = (struct lstmt *)__nw__4stmtSFUl(
                                                  (size_t)(sizeof(struct lstmt)))))
                                    ? ((__0__X22 = (struct lstmt *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X22), ((unsigned char)115),
                                            __2__X23, __2__X24)),
                                       (__0__X22->__O1__4stmt.d = __2lab))
                                    : 0),
                               __0__X22))));
            }

            return __1nl;
        }
    }
}

extern const char *oper_name__FUc(TOK);

int tsizeof__4typeFi(struct type *__0this, int);

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

Pname dcl__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

void dcl_print__4nameFUc(struct name *__0this, TOK);

extern int fputs(const char *__0s, void *__0stream);

struct classdef *__ct__8classdefFUc(struct classdef *__0this, TOK);

struct basetype *__ct__8basetypeFUcP4name(struct basetype *__0this, TOK, Pname);

void simpl_init__Fv(void) {
    const char *__1ns;
    const char *__1ds;

    __1ns = oper_name__FUc((unsigned char)23);
    __1ds = oper_name__FUc((unsigned char)9);

    size_t_type = (struct type *)((tsizeof__4typeFi(Pvoid_type, 0) >
                                   tsizeof__4typeFi((struct type *)uint_type, 0))
                                      ? ((tsizeof__4typeFi(Pvoid_type, 0) >
                                          tsizeof__4typeFi((struct type *)ulong_type, 0))
                                             ? ullong_type
                                             : ulong_type)
                                      : uint_type);

    {
        Pname __1nw;

        __1nw = __ct__4nameFPCc((struct name *)0, __1ns);
        __1nw->n_oper__4name = 23;
        {
            Pname __1a;

            __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
            __1a->__O1__4expr.tp = size_t_type;
            __1nw->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
                (struct fct *)0, Pvoid_type, __1a, (unsigned char)1);
            new_fct = dcl__4nameFP5tableUc(__1nw, gtbl, (unsigned char)14);
            ((__1nw
                  ? (((void)(__1nw ? (((void)((((((struct expr *)__1nw))
                                                    ? (((void)((((struct expr *)__1nw))
                                                                   ? (((void)(((void)0))))
                                                                   : (((void)0)))))
                                                    : (((void)0)))),
                                              (((void)__dl__4nameSFPvUl(
                                                  (void *)__1nw, (size_t)(sizeof(struct name))))))))
                                   : (((void)0)))))
                  : (((void)0))));

            {
                Pname __1dl;

                __1dl = __ct__4nameFPCc((struct name *)0, __1ds);
                __1dl->n_oper__4name = 9;
                __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                __1a->__O1__4expr.tp = Pvoid_type;
                __1dl->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
                    (struct fct *)0, (struct type *)void_type, __1a, (unsigned char)1);
                del_fct = dcl__4nameFP5tableUc(__1dl, gtbl, (unsigned char)14);
                ((__1dl ? (((void)(__1dl ? (((void)((((((struct expr *)__1dl))
                                                          ? (((void)((((struct expr *)__1dl))
                                                                         ? (((void)(((void)0))))
                                                                         : (((void)0)))))
                                                          : (((void)0)))),
                                                    (((void)__dl__4nameSFPvUl(
                                                        (void *)__1dl,
                                                        (size_t)(sizeof(struct name))))))))
                                         : (((void)0)))))
                        : (((void)0))));

                {
                    Pname __1vn;
                    Pname __1vd;

                    __1vn = __ct__4nameFPCc((struct name *)0, (const char *)"__vec_new");
                    __1vd = __ct__4nameFPCc((struct name *)0, (const char *)"__vec_delete");

                    __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                    __1a->__O1__4expr.tp = Pvoid_type;
                    {
                        Pname __1al;

                        struct name *__0__X25;

                        struct name *__0__X26;

                        struct ival *__0__X27;

                        struct type *__0__X28;

                        __1al = __1a;
                        __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                        __1a->__O1__4expr.tp = (struct type *)int_type;
                        __1a->__O1__4name.n_list = __1al;
                        __1al = __1a;
                        __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                        __1a->__O1__4expr.tp = (struct type *)int_type;
                        __1a->__O1__4name.n_list = __1al;
                        __1al = __1a;
                        __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                        __1a->__O1__4expr.tp = Pvoid_type;
                        __1a->__O1__4name.n_list = __1al;
                        __1al = __1a;

                        vec_new_fct = insert__5tableFP4nameUc(gtbl, __1vn, (unsigned char)0);
                        ((__1vn
                              ? (((void)(__1vn
                                             ? (((void)((((((struct expr *)__1vn))
                                                              ? (((void)((((struct expr *)__1vn))
                                                                             ? (((void)(((void)0))))
                                                                             : (((void)0)))))
                                                              : (((void)0)))),
                                                        (((void)__dl__4nameSFPvUl(
                                                            (void *)__1vn,
                                                            (size_t)(sizeof(struct name))))))))
                                             : (((void)0)))))
                              : (((void)0))));
                        vec_new_fct->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
                            (struct fct *)0, Pvoid_type, __1al, (unsigned char)1);
                        (((struct fct *)(((struct fct *)vec_new_fct->__O1__4expr.tp))))
                            ->f_linkage__3fct = 1;
                        vec_new_fct->n_scope__4name = 14;
                        vec_new_fct->permanent__4node = 1;
                        vec_new_fct->__O1__4expr.tp->permanent__4node = 1;
                        ((__0__X25 = vec_new_fct), ((__0__X25->n_used__4name++), (((void)0))));
                        dcl_print__4nameFUc(vec_new_fct, (unsigned char)0);

                        __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                        __1a->__O1__4expr.tp = (struct type *)int_type;
                        __1al = __1a;
                        __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                        __1a->__O1__4expr.tp = (struct type *)int_type;
                        __1a->__O1__4name.n_list = __1al;
                        __1al = __1a;
                        __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                        __1a->__O1__4expr.tp = Pvoid_type;
                        __1a->__O1__4name.n_list = __1al;
                        __1al = __1a;
                        __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                        __1a->__O1__4expr.tp = (struct type *)int_type;
                        __1a->__O1__4name.n_list = __1al;
                        __1al = __1a;
                        __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                        __1a->__O1__4expr.tp = (struct type *)int_type;
                        __1a->__O1__4name.n_list = __1al;
                        __1al = __1a;
                        __1a = __ct__4nameFPCc((struct name *)0, (const char *)0);
                        __1a->__O1__4expr.tp = Pvoid_type;
                        __1a->__O1__4name.n_list = __1al;
                        __1al = __1a;

                        vec_del_fct = insert__5tableFP4nameUc(gtbl, __1vd, (unsigned char)0);
                        ((__1vd
                              ? (((void)(__1vd
                                             ? (((void)((((((struct expr *)__1vd))
                                                              ? (((void)((((struct expr *)__1vd))
                                                                             ? (((void)(((void)0))))
                                                                             : (((void)0)))))
                                                              : (((void)0)))),
                                                        (((void)__dl__4nameSFPvUl(
                                                            (void *)__1vd,
                                                            (size_t)(sizeof(struct name))))))))
                                             : (((void)0)))))
                              : (((void)0))));
                        vec_del_fct->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
                            (struct fct *)0, (struct type *)void_type, __1al, (unsigned char)1);
                        (((struct fct *)(((struct fct *)vec_del_fct->__O1__4expr.tp))))
                            ->f_linkage__3fct = 1;
                        vec_del_fct->n_scope__4name = 14;
                        vec_del_fct->permanent__4node = 1;
                        vec_del_fct->__O1__4expr.tp->permanent__4node = 1;
                        ((__0__X26 = vec_del_fct), ((__0__X26->n_used__4name++), (((void)0))));
                        dcl_print__4nameFUc(vec_del_fct, (unsigned char)0);

                        one = (struct expr
                                   *)((__0__X27 = 0),
                                      (((__0__X27 || (__0__X27 = (struct ival *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct ival)))))
                                            ? ((__0__X27 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X27), (unsigned char)150,
                                                    (struct expr *)0, (struct expr *)0)),
                                               (__0__X27->__O2__4expr.i1 = ((long long)1)))
                                            : 0),
                                       __0__X27));
                        one->__O1__4expr.tp = (struct type *)int_type;
                        one->permanent__4node = 1;

                        Pfct_type = (struct type *)__ct__3fctFP4typeP4nameUc(
                            (struct fct *)0, (struct type *)int_type, (struct name *)0,
                            (unsigned char)1);
                        Pfct_type =
                            (struct type *)((__0__X28 = Pfct_type),
                                            (__ct__3ptrFUcP4type((struct ptr *)0,
                                                                 (unsigned char)125, __0__X28)));
                        Pfct_type->permanent__4node = 1;

                        if (ansi_opt)
                            fputs((const char *)"typedef int (*__vptp)(void);\n", out_file);
                        else
                            fputs((const char *)"typedef int (*__vptp)();\n", out_file);
                        fputs((const char *)"struct __mptr {short d; short i; __vptp f; };\n",
                              out_file);
                        {
                            Pname __1b;

                            struct type *__0__X29;

                            __1b = __ct__4nameFPCc((struct name *)0, (const char *)"__mptr");
                            __1b->__O1__4expr.tp = (struct type *)__ct__8classdefFUc(
                                (struct classdef *)0, (unsigned char)32);
                            __1b->__O1__4expr.tp->defined__4type = 01;
                            (((struct classdef *)(((struct classdef *)__1b->__O1__4expr.tp))))
                                ->obj_size__8classdef = ((SZ_SHORT + SZ_SHORT) + SZ_WPTR);
                            mptr_type = __ct__8basetypeFUcP4name((struct basetype *)0,
                                                                 (unsigned char)119, __1b);
                            mptr_type->permanent__4node = 1;

                            Pvptr_type = (struct type *)((__0__X29 = (struct type *)mptr_type),
                                                         (__ct__3ptrFUcP4type((struct ptr *)0,
                                                                              (unsigned char)125,
                                                                              __0__X29)));
                            Pvptr_type->permanent__4node = 1;
                        }
                    }
                }
            }
        }
    }
}

Ptable scope = 0;
Pname expand_fn = 0;
Ptable expand_tbl = 0;

Pexpr find_name__8classdefFPCcP8classdefiT3(struct classdef *__0this, const char *, Pclass, int,
                                            int);

Pname has_oper__8classdefFUc(register struct classdef *__0this, TOK __1op) {
    Pexpr __1n;

    __1n = find_name__8classdefFPCcP8classdefiT3(__0this, oper_name__FUc(__1op),
                                                 (struct classdef *)0, 0, 1);
    if (__1n == 0)
        return (struct name *)0;

    while ((__1n->base__4node == 44) || (__1n->base__4node == 177)) {
        Pexpr __2e;

        __2e = (((struct expr *)(((struct expr *)__1n))));
        __1n = (struct expr *)(((struct name *)(((struct name *)__1n->__O4__4expr.mem))));
        ((__2e ? (((void)(__2e ? (((void)(((void)__dl__4exprSFPvUl(
                                     (void *)__2e, (size_t)(sizeof(struct expr)))))))
                               : (((void)0)))))
               : (((void)0))));
    }
    if ((__1n->__O1__4expr.tp->base__4node == 108) &&
        ((((struct name *)(((struct name *)__1n))))->n_dcl_printed__4name == 0))
        dcl_print__4nameFUc(((struct name *)(((struct name *)__1n))), (unsigned char)0);
    return (((struct name *)(((struct name *)__1n))));
}

int is_expr__FP4stmt(Pstmt __1s);

int is_expr__FP4stmt(Pstmt __1s) {
    int __1i;

    __1i = 0;
    while (__1s->base__4node == 116) {
        if (__1s->s__4stmt == 0)
            return 1;
        __1s = __1s->s__4stmt;
    }
    {
        {
            Pstmt __1ss;

            __1ss = __1s;

            for (; __1ss; __1ss = __1ss->s_list__4stmt) {
                switch (__1ss->base__4node) {
                case 116:
                    if ((((struct block *)(((struct block *)__1ss))))->memtbl__4stmt ||
                        (is_expr__FP4stmt(__1ss->s__4stmt) == 0))
                        return 0;
                case 72:
                    if (__1ss->__O2__4stmt.e && (__1ss->__O2__4stmt.e->base__4node == 168)) {
                        Pname __4fn;
                        Pfct __4f;

                        __4fn = __1ss->__O2__4stmt.e->__O4__4expr.il->fct_name__5iline;
                        __4f = (((struct fct *)(((struct fct *)__4fn->__O1__4expr.tp))));
                        if (__4f->f_expr__3fct == 0)
                            return 0;
                    }
                    break;
                case 20:
                    if (is_expr__FP4stmt(__1ss->s__4stmt) == 0)
                        return 0;
                    if (__1ss->__O3__4stmt.else_stmt &&
                        (is_expr__FP4stmt(__1ss->__O3__4stmt.else_stmt) == 0))
                        return 0;
                    break;
                default:
                    return 0;
                }
                __1i++;
            }
            return __1i;
        }
    }
}

int no_of_returns = 0;

int size_complexity_measure = 20;

void simpl__4nameFv(struct name *__0this);

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

void simpl__3fctFv(struct fct *__0this);

Pstmt expand__4stmtFv(struct stmt *__0this);

void simpl__8classdefFv(struct classdef *__0this);

void simpl__4exprFv(struct expr *__0this);

void simpl__4nameFv(register struct name *__0this) {
    if (__0this->base__4node == 25)
        return;

    if (__0this->__O1__4expr.tp == 0) {
        struct ea __0__V30;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"%n->N::simple(tp==0)",
            (const struct ea *)(((&__0__V30)->__O1__2ea.p = ((const void *)__0this)), (&__0__V30)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if ((__0this->__O1__4expr.tp->base__4node == 6) && (__0this->n_key__4name == 44))
        return;
    if ((__0this->__O1__4expr.tp->base__4node == 6) &&
        (((((struct classdef *)(((struct classdef *)__0this->__O1__4expr.tp))))->defined__4type &
          01) == 0))
        return;

    switch (__0this->__O1__4expr.tp->base__4node) {
    case 0: {
        struct ea __0__V31;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"%n->N::simpl(tp->B==0)",
            (const struct ea *)(((&__0__V31)->__O1__2ea.p = ((const void *)__0this)), (&__0__V31)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

    case 97:
    case 110:
    case 125: {
        Ptype __3t;

        __3t = __0this->__O1__4expr.tp;
    xx:
        switch (__3t->base__4node) {
        case 97:
            __3t = (((struct basetype *)(((struct basetype *)__3t))))
                       ->b_name__8basetype->__O1__4expr.tp;

            goto xx;
        case 110:
            __3t = (((struct vec *)(((struct vec *)__3t))))->typ__5pvtyp;

            goto xx;
        case 125:
            __3t = (((struct ptr *)(((struct ptr *)__3t))))->typ__5pvtyp;

            goto xx;
        case 108:
            break;
        }
        break;
    }

    case 76: {
        {
            {
                Plist __3gl;

                __3gl = (((struct gen *)(((struct gen *)__0this->__O1__4expr.tp))))->fct_list__3gen;

                for (; __3gl; __3gl = __3gl->l__9name_list)
                    simpl__4nameFv(__3gl->f__9name_list);
                break;
            }
        }
    }

    case 108: {
        Pfct __3f;
        Pname __3n;
        Pname __3th;

        __3f = (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));

        __3th = __3f->f_this__3fct;

        if (__3th) {
            __3th->n_stclass__4name =
                (((!__3th->n_addr_taken__4name) && (2 < __3th->n_used__4name)) ? 27 : 2);
            if (__3th->n_assigned_to__4name && (__3th->n_assigned_to__4name != 11111))
                error__FiP3locPCcRC2eaN34((int)'w', &__0this->where__4name,
                                          (const char *)"assignment to this (anachronism)",
                                          (const struct ea *)ea0, (const struct ea *)ea0,
                                          (const struct ea *)ea0, (const struct ea *)ea0);
        }

        if (__0this->__O1__4expr.tp->defined__4type & 02)
            return;
        if ((__0this->__O1__4expr.tp->defined__4type & 01) == 0)
            return;

        for (__3n = __3f->f_args__3fct; __3n; __3n = __3n->__O1__4name.n_list)
            simpl__4nameFv(__3n);

        if (__3f->body__3fct) {
            Ptable __4oscope;
            Pname __4ocurr;
            int __4oim;

            __4oscope = scope;
            __4ocurr = curr_fct;
            __4oim = imeasure;
            scope = __3f->body__3fct->memtbl__4stmt;

            if (scope == 0) {
                struct ea __0__V32;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"%n memtbl missing",
                    (const struct ea *)(((&__0__V32)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V32)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            curr_fct = __0this;
            simpl__3fctFv(__3f);
            if ((__3f->f_inline__3fct == 0) || debug_opt)
                __3f->f_imeasure__3fct = 0;
            else {
                if (warning_opt && __3f->f_virtual__3fct) {
                    struct ea __0__V33;

                    error__FiPCcRC2eaN33(
                        (int)'w', (const char *)"virtual function %n cannot be inlined",
                        (const struct ea *)(((&__0__V33)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V33)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                if (size_complexity_measure < __3f->f_imeasure__3fct) {
                    if (warning_opt) {
                        {
                            struct ea __0__V34;

                            error__FiPCcRC2eaN33((int)'w',
                                                 (const char *)"%n too large for inlining",
                                                 (const struct ea *)(((&__0__V34)->__O1__2ea.p =
                                                                          ((const void *)__0this)),
                                                                     (&__0__V34)),
                                                 (const struct ea *)ea0, (const struct ea *)ea0,
                                                 (const struct ea *)ea0);
                        }
                    }
                    __3f->f_inline__3fct = 0;

                    scope = __4oscope;
                    __0this->__O1__4expr.tp->defined__4type |= 02;
                    return;
                }
                {
                    int __5i;

                    __5i = 0;
                    for (__3n = __3f->f_args__3fct; __3n; __3n = __3n->__O1__4name.n_list) {
                        __3n->base__4node = 169;
                        __3n->argno__4name = (__5i++);
                    }
                    expand_tbl = (((__3f->returns__3fct->base__4node != 38) ||
                                   (__0this->n_oper__4name == 161))
                                      ? scope
                                      : (((struct table *)0)));
                    expand_fn = __0this;

                    if (expand_tbl) {
                    genlab: {
                        Pexpr __6ee;
                        Ptype __6t;

                        register struct cast *__0__X35;

                        struct type *__2__X36;

                        struct expr *__2__X37;

                        __6ee = (((struct expr *)((
                            (struct expr *)expand__4stmtFv((struct stmt *)__3f->body__3fct)))));
                        __6t = 0;
                        if (__3f->s_returns__3fct) {
                            if (__6ee->__O1__4expr.tp != __3f->s_returns__3fct)
                                __6t = __3f->s_returns__3fct;
                        } else if (__6ee->__O1__4expr.tp != __3f->returns__3fct)
                            __6t = __3f->returns__3fct;

                        if (__6t && (__6t == (((struct type *)void_type))))
                            __6ee = __ct__4exprFUcP4exprT2(
                                (struct expr *)0, (unsigned char)71, __6ee,
                                (struct expr
                                     *)((__0__X35 = 0),
                                        ((__2__X36 =
                                              (struct type *)(ansi_opt ? void_type : char_type)),
                                         ((__2__X37 = zero),
                                          (((__0__X35 || (__0__X35 = (struct cast *)__nw__4exprSFUl(
                                                              (size_t)(sizeof(struct cast)))))
                                                ? ((__0__X35 =
                                                        (struct cast *)__ct__4exprFUcP4exprT2(
                                                            ((struct expr *)__0__X35),
                                                            (unsigned char)191, __2__X37,
                                                            (struct expr *)0)),
                                                   (__0__X35->__O1__4expr.tp =
                                                        (__0__X35->__O4__4expr.tp2 = __2__X36)))
                                                : 0),
                                           __0__X35)))));
                        __3f->f_expr__3fct =
                            ((__6ee->base__4node == 71)
                                 ? __6ee
                                 : __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, zero,
                                                          __6ee));
                    }

                    } else {
                        if (is_expr__FP4stmt((struct stmt *)__3f->body__3fct)) {
                            expand_tbl = scope;
                            goto genlab;
                        }

                        __3f->f_expr__3fct = 0;
                        replace_ret__FP4stmtiP5table(__3f->body__3fct->s__4stmt, 0,
                                                     __3f->body__3fct->memtbl__4stmt);
                        __3f->body__3fct = (((struct block *)((
                            (struct block *)expand__4stmtFv((struct stmt *)__3f->body__3fct)))));
                    }
                    expand_fn = 0;
                    expand_tbl = 0;
                }
            }
            scope = __4oscope;
            curr_fct = __4ocurr;
            imeasure = __4oim;
        }
        break;
    }

    case 6:
        simpl__8classdefFv(((struct classdef *)(((struct classdef *)__0this->__O1__4expr.tp))));
    }
    }

    if ((__0this->base__4node != 123) && __0this->__O3__4expr.n_initializer)
        simpl__4exprFv(__0this->__O3__4expr.n_initializer);
    __0this->__O1__4expr.tp->defined__4type |= 02;
}

Pexpr typ__4exprFP5table(struct expr *__0this, Ptable);

Pexpr call_ctor__FP5tableP4exprN22iT2(Ptable __1tbl, Pexpr __1p, Pexpr __1ctor, Pexpr __1args,
                                      int __1d, Pexpr __1vb_args) {
    Pexpr __1ee;

    struct ref *__0__X38;

    struct expr *__2__X39;

    struct expr *__2__X40;

    __1ee = (struct expr *)((__0__X38 = 0),
                            ((__2__X39 = __1p),
                             ((__2__X40 = __1ctor),
                              (((__0__X38 || (__0__X38 = (struct ref *)__nw__4exprSFUl(
                                                  (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X38 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X38), ((unsigned char)__1d),
                                            __2__X39, (struct expr *)0)),
                                       (__0__X38->__O4__4expr.mem = __2__X40))
                                    : 0),
                               __0__X38))));

    if ((__1p == 0) || (__1tbl == 0))
        __1ee->__O1__4expr.tp = __1ctor->__O1__4expr.tp;

    if (__1args && (__1args->base__4node != 140))
        __1args =
            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __1args, (struct expr *)0);
    __1ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)146, __1ee, __1args);
    {
        Pname __1n;

        __1n = (((struct name *)(((struct name *)__1ctor))));

        while (__1n->base__4node == 177)
            __1n = (((struct name *)(((struct name *)__1n->__O4__4expr.mem))));
        if (__1n->__O1__4expr.tp->base__4node == 108)
            __1ee->__O4__4expr.fct_name = __1n;

        if (__1tbl)
            __1ee = typ__4exprFP5table(__1ee, __1tbl);
        else if (__1n->__O1__4expr.tp->base__4node == 108)
            __1ee->__O1__4expr.tp =
                (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))))->s_returns__3fct;

        if (__1ee->__O1__4expr.tp == (((struct type *)any_type)))
            return __1ee;
        __1args = __1ee->__O3__4expr.e2;

        if (__1vb_args == 0) {
            Pfct __2f;

            __2f = (((struct fct *)(((struct fct *)__1ee->__O4__4expr.fct_name->__O1__4expr.tp))));
            {
                {
                    Pname __2nn;

                    __2nn = __2f->f_args__3fct->__O1__4name.n_list;

                    for (; __2nn && (__2nn != __2f->argtype__3fct);
                         __2nn = __2nn->__O1__4name.n_list)
                        __1args = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, zero,
                                                         __1args);
                }
            }
        } else {
            if (__1args) {
                Pexpr __3d;

                __3d = __1vb_args;
                for (; __3d->__O3__4expr.e2; __3d = __3d->__O3__4expr.e2)
                    ;
                __3d->__O3__4expr.e2 = __1args;
            }
            __1args = __1vb_args;
        }

        if (__1n->__O1__4expr.tp->base__4node == 108) {
            Pfct __2f;
            Pexpr __2ee;
            Pname __2nn;

            __2f = (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))));

            if (__2f->argtype__3fct && __1args)
                for (((__2nn = __2f->argtype__3fct->__O1__4name.n_list), (__2ee = __1args)); __2nn;
                     ((__2nn = __2nn->__O1__4name.n_list), (__2ee = __2ee->__O3__4expr.e2))) {
                    if (__2ee->__O3__4expr.e2 == 0) {
                        Pexpr __4a;
                        Pexpr __4e;

                        __4a = __2nn->__O3__4expr.n_initializer;
                        __4e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __4a,
                                                      (struct expr *)0);
                        __2ee->__O3__4expr.e2 = __4e;
                    }
                }
        }

        __1ee->__O3__4expr.e2 = __1args;
        return __1ee;
    }
}

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

Pexpr call_dtor__FP4exprN21iT1(Pexpr __1p, Pexpr __1dtor, Pexpr __1arg, int __1d,
                               Pexpr __1vb_args) {
    Pexpr __1r;

    struct ival *__0__X41;

    struct ival *__0__X42;

    struct ref *__0__X46;

    struct expr *__2__X47;

    struct expr *__2__X48;

    __1r =
        (struct expr *)((__0__X46 = 0), ((__2__X47 = __1p),
                                         ((__2__X48 = __1dtor),
                                          (((__0__X46 || (__0__X46 = (struct ref *)__nw__4exprSFUl(
                                                              (size_t)(sizeof(struct ref)))))
                                                ? ((__0__X46 = (struct ref *)__ct__4exprFUcP4exprT2(
                                                        ((struct expr *)__0__X46),
                                                        ((unsigned char)(__1d ? __1d : 44)),
                                                        __2__X47, (struct expr *)0)),
                                                   (__0__X46->__O4__4expr.mem = __2__X48))
                                                : 0),
                                           __0__X46))));

    if (__1arg && __1vb_args)
        __1arg = (struct expr *)((__0__X41 = 0),
                                 (((__0__X41 || (__0__X41 = (struct ival *)__nw__4exprSFUl(
                                                     (unsigned long)(sizeof(struct ival)))))
                                       ? ((__0__X41 = (struct ival *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X41), (unsigned char)150,
                                               (struct expr *)0, (struct expr *)0)),
                                          (__0__X41->__O2__4expr.i1 = ((long long)3)))
                                       : 0),
                                  __0__X41));
    else if (__1vb_args)
        __1arg = (struct expr *)((__0__X42 = 0),
                                 (((__0__X42 || (__0__X42 = (struct ival *)__nw__4exprSFUl(
                                                     (unsigned long)(sizeof(struct ival)))))
                                       ? ((__0__X42 = (struct ival *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X42), (unsigned char)150,
                                               (struct expr *)0, (struct expr *)0)),
                                          (__0__X42->__O2__4expr.i1 = ((long long)2)))
                                       : 0),
                                  __0__X42));
    else if (__1arg == 0)
        __1arg = zero;
    if (__1arg->__O1__4expr.tp == 0)
        __1arg->__O1__4expr.tp = (struct type *)int_type;

    {
        Pexpr __1aa;

        Pfct __1f;

        Pexpr __1ee;

        struct call *__0__X43;

        struct expr *__2__X44;

        struct expr *__2__X45;

        __1aa =
            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __1arg, (struct expr *)0);

        __1f = (((struct fct *)(((struct fct *)__1dtor->__O1__4expr.tp))));

        __1ee = (struct expr *)((__0__X43 = 0),
                                ((__2__X44 = __1r),
                                 ((__2__X45 = __1aa),
                                  (((__0__X43 || (__0__X43 = (struct call *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct call)))))
                                        ? (__0__X43 = (struct call *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X43), (unsigned char)109,
                                               __2__X44, __2__X45))
                                        : 0),
                                   __0__X43))));
        while (__1dtor->base__4node == 177)
            __1dtor = __1dtor->__O4__4expr.mem;
        if (__1d == 44)
            __1ee->__O4__4expr.fct_name = (((struct name *)(((struct name *)__1dtor))));
        else {
            __1r->__O3__4expr.n_initializer = __1dtor;
            __1ee->__O4__4expr.fct_name = 0;
        }
        __1ee->base__4node = 146;
        __1ee->__O1__4expr.tp = (struct type *)void_type;

        if (__1f->memof__3fct->c_body__8classdef == 1)
            dcl_print__8classdefFP4name(__1f->memof__3fct, (struct name *)0);
        if ((((struct name *)(((struct name *)__1dtor))))->n_dcl_printed__4name == 0)
            dcl_print__4nameFUc(((struct name *)(((struct name *)__1dtor))), (unsigned char)0);

        return __1ee;
    }
}

void del__4nameFv(struct name *__0this);

Pname is_cl_obj__4typeFv(struct type *__0this);

extern void check_visibility__FP4nameT1P8classdefP5tableT1(Pname, Pname, Pclass, Ptable, Pname);

extern Pexpr cdvec__FP4nameP4exprP8classdefT1iN22(Pname, Pexpr, Pclass, Pname, int, Pexpr, Pexpr);

extern Pexpr rptr__FP4typeP4expri(Ptype, Pexpr, int);

Pexpr contents__4exprFv(struct expr *__0this);

extern int strcmp(const char *, const char *);

extern Pexpr find_name__FP4nameP8classdefP5tableiT1(Pname, Pclass, Ptable, int, Pname);

Ptype call_fct__4exprFP5table(struct expr *__0this, Ptable);

Pstmt simpl__4stmtFv(struct stmt *__0this);

extern void __dl__FPv(void *);

Pstmt dtor_simpl__3fctFP8classdefP4expr(register struct fct *__0this, Pclass __1cl, Pexpr __1th) {
    Pstmt __1dtail;

    Pname __1fa;

    __1dtail = 0;

    __1fa = __ct__4nameFPCc((struct name *)0, (const char *)"__free");
    __1fa->__O1__4expr.tp = (struct type *)int_type;
    {
        Pname __1free_arg;

        __1free_arg =
            dcl__4nameFP5tableUc(__1fa, __0this->body__3fct->memtbl__4stmt, (unsigned char)136);
        __1free_arg->where__4name = no_where;
        ((__1fa ? (((void)(__1fa ? (((void)((((((struct expr *)__1fa))
                                                  ? (((void)((((struct expr *)__1fa))
                                                                 ? (((void)(((void)0))))
                                                                 : (((void)0)))))
                                                  : (((void)0)))),
                                            (((void)__dl__4nameSFPvUl(
                                                (void *)__1fa, (size_t)(sizeof(struct name))))))))
                                 : (((void)0)))))
                : (((void)0))));
        {
            Pname __1a;

            __1a = __0this->f_args__3fct;
            if ((__1a == 0) || (__1a->__O1__4name.n_list == 0)) {
                struct ea __0__V49;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"__freeA missing in destructor for %t",
                    (const struct ea *)(((&__0__V49)->__O1__2ea.p = ((const void *)__1cl)),
                                        (&__0__V49)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            {
                Pname __1p;

                __1p = 0;
                for (;; ((__1p = __1a), (__1a = __1a->__O1__4name.n_list))) {
                    if (__1a->__O1__4name.n_list == 0) {
                        if (__1p->__O1__4name.n_list &&
                            (__1p->__O1__4name.n_list->permanent__4node == 0))
                            del__4nameFv(__1p->__O1__4name.n_list);
                        __1p->__O1__4name.n_list = __1free_arg;
                        break;
                    }
                }

                {
                    Ptable __1tbl;
                    int __1i;

                    __1tbl = __1cl->memtbl__8classdef;
                    __1i = 1;
                    {
                        {
                            Pname __1m;

                            int __2__X50;

                            __1m = ((((__1i <= 0) || (__1tbl->free_slot__5table <= __1i))
                                         ? (((struct name *)0))
                                         : (__1tbl->entries__5table[__1i])));

                            for (; __1m;
                                 __1m = (__1m->n_tbl_list__4name
                                             ? __1m->n_tbl_list__4name
                                             : ((__2__X50 = (++__1i)),
                                                ((((__2__X50 <= 0) ||
                                                   (__1tbl->free_slot__5table <= __2__X50))
                                                      ? (((struct name *)0))
                                                      : (__1tbl->entries__5table[__2__X50])))))) {
                                if ((__1m->base__4node == 123) || (__1m->__O1__4expr.tp == 0))
                                    continue;

                                if ((__1m->n_stclass__4name == 31) || (__1m->base__4node == 25))
                                    continue;

                                {
                                    Ptype __2t;
                                    Pexpr __2ee;
                                    Pname __2cn;
                                    Pname __2dtor;

                                    __2t = __1m->__O1__4expr.tp;
                                    __2ee = 0;

                                    if (__2cn = is_cl_obj__4typeFv(__2t)) {
                                        Pclass __3cl;

                                        __3cl = (((struct classdef *)((
                                            (struct classdef *)__2cn->__O1__4expr.tp))));
                                        if (__2dtor = (__3cl->c_dtor__8classdef)) {
                                            struct ref *__0__X51;

                                            struct expr *__2__X52;

                                            struct expr *__2__X53;

                                            __2ee =
                                                (struct expr
                                                     *)((__0__X51 = 0),
                                                        ((__2__X52 = __1th),
                                                         ((__2__X53 = (struct expr *)__1m),
                                                          (((__0__X51 ||
                                                             (__0__X51 =
                                                                  (struct ref *)__nw__4exprSFUl((
                                                                      size_t)(sizeof(struct ref)))))
                                                                ? ((__0__X51 = (struct ref *)
                                                                        __ct__4exprFUcP4exprT2(
                                                                            ((struct expr *)
                                                                                 __0__X51),
                                                                            ((unsigned char)44),
                                                                            __2__X52,
                                                                            (struct expr *)0)),
                                                                   (__0__X51->__O4__4expr.mem =
                                                                        __2__X53))
                                                                : 0),
                                                           __0__X51))));
                                            __2ee->__O1__4expr.tp = __1m->__O1__4expr.tp;
                                            __2ee = call_dtor__FP4exprN21iT1(
                                                __2ee, (struct expr *)__2dtor, (struct expr *)0, 45,
                                                one);
                                            check_visibility__FP4nameT1P8classdefP5tableT1(
                                                __2dtor, (struct name *)0,
                                                ((struct classdef *)((
                                                    (struct classdef *)__2dtor->__O4__4expr.n_table
                                                        ->t_name__5table->__O1__4expr.tp))),
                                                __1tbl, curr_fct);
                                        }
                                    } else if (cl_obj_vec) {
                                        Pclass __3cl;

                                        __3cl = (((struct classdef *)((
                                            (struct classdef *)cl_obj_vec->__O1__4expr.tp))));
                                        if (__2dtor = (__3cl->c_dtor__8classdef)) {
                                            Pfct __4f;
                                            int __4i;

                                            __4f = (((struct fct *)((
                                                (struct fct *)__2dtor->__O1__4expr.tp))));
                                            __4i = 0;
                                            {
                                                {
                                                    Pname __4nn;

                                                    struct ref *__0__X54;

                                                    struct expr *__2__X55;

                                                    struct expr *__2__X56;

                                                    struct ival *__0__X57;

                                                    __4nn = __4f->f_args__3fct->__O1__4name.n_list;

                                                    for (; __4nn && __4nn->__O1__4name.n_list;
                                                         __4nn = __4nn->__O1__4name.n_list)
                                                        __4i++;

                                                    __2ee =
                                                        (struct expr
                                                             *)((__0__X54 = 0),
                                                                ((__2__X55 = __1th),
                                                                 ((__2__X56 = (struct expr *)__1m),
                                                                  (((__0__X54 ||
                                                                     (__0__X54 = (struct ref *)
                                                                          __nw__4exprSFUl(
                                                                              (size_t)(sizeof(
                                                                                  struct ref)))))
                                                                        ? ((__0__X54 = (struct ref
                                                                                            *)
                                                                                __ct__4exprFUcP4exprT2(
                                                                                    ((struct expr *)
                                                                                         __0__X54),
                                                                                    ((unsigned char)44),
                                                                                    __2__X55,
                                                                                    (struct expr
                                                                                         *)0)),
                                                                           (__0__X54->__O4__4expr
                                                                                .mem = __2__X56))
                                                                        : 0),
                                                                   __0__X54))));
                                                    __2ee->__O1__4expr.tp = __1m->__O1__4expr.tp;
                                                    __2ee = cdvec__FP4nameP4exprP8classdefT1iN22(
                                                        vec_del_fct, __2ee, __3cl, __2dtor, 0,
                                                        (struct expr
                                                             *)((__0__X57 = 0),
                                                                (((__0__X57 ||
                                                                   (__0__X57 = (struct ival *)
                                                                        __nw__4exprSFUl(
                                                                            (size_t)(sizeof(
                                                                                struct ival)))))
                                                                      ? ((__0__X57 = (struct ival *)
                                                                              __ct__4exprFUcP4exprT2(
                                                                                  ((struct expr *)
                                                                                       __0__X57),
                                                                                  (unsigned char)150,
                                                                                  (struct expr *)0,
                                                                                  (struct expr
                                                                                       *)0)),
                                                                         (__0__X57->__O2__4expr.i1 =
                                                                              ((long long)__4i)))
                                                                      : 0),
                                                                 __0__X57)),
                                                        (struct expr *)0);
                                                    check_visibility__FP4nameT1P8classdefP5tableT1(
                                                        __2dtor, (struct name *)0,
                                                        ((struct classdef *)((
                                                            (struct classdef *)__2dtor->__O4__4expr
                                                                .n_table->t_name__5table
                                                                ->__O1__4expr.tp))),
                                                        __1tbl, curr_fct);
                                                }
                                            }
                                        }
                                    }

                                    if (__2ee) {
                                        Pstmt __3es;

                                        struct estmt *__0__X58;

                                        struct loc __2__X59;

                                        __3es =
                                            (struct stmt
                                                 *)((__0__X58 = 0),
                                                    ((__2__X59 = curloc),
                                                     (((__0__X58 ||
                                                        (__0__X58 = (struct estmt *)__nw__4stmtSFUl(
                                                             (unsigned long)(sizeof(
                                                                 struct estmt)))))
                                                           ? ((__0__X58 = (struct estmt *)
                                                                   __ct__4stmtFUc3locP4stmt(
                                                                       ((struct stmt *)__0__X58),
                                                                       ((unsigned char)72),
                                                                       __2__X59,
                                                                       ((struct stmt *)0))),
                                                              (__0__X58->__O2__4stmt.e = __2ee))
                                                           : 0),
                                                      __0__X58)));

                                        __3es->s_list__4stmt = del_list;
                                        del_list = __3es;
                                        if (__1dtail == 0)
                                            __1dtail = __3es;
                                    }
                                }
                            }

                            {
                                Pexpr __1ee;

                                Pbcl __1b;
                                Pbcl __1t;
                                Pbcl __1l;

                                __1ee = 0;

                                __1b = 0;
                                __1t = 0;
                                __1l = __1cl->baselist__8classdef;
                                for (; __1l; __1l = __1l->next__6basecl) {
                                    if (__1l->base__4node != 77) {
                                        Pbcl __3x;

                                        register struct basecl *__0__X60;

                                        struct classdef *__2__X61;

                                        struct basecl *__2__X62;

                                        struct node *__0__X9;

                                        __3x =
                                            ((__0__X60 = 0),
                                             ((__2__X61 = __1l->bclass__6basecl),
                                              ((__2__X62 = 0),
                                               (((__0__X60 ||
                                                  (__0__X60 = (struct basecl *)__nw__FUl(
                                                       (size_t)(sizeof(struct basecl)))))
                                                     ? ((__0__X60 =
                                                             (struct basecl
                                                                  *)((__0__X9 = (((
                                                                          struct node *)__0__X60))),
                                                                     (((__0__X9 ||
                                                                        (__0__X9 = (struct node *)
                                                                             __nw__FUl((
                                                                                 size_t)(sizeof(
                                                                                 struct node)))))
                                                                           ? (((__0__X9
                                                                                    ->base__4node =
                                                                                    0),
                                                                               (__0__X9
                                                                                    ->permanent__4node =
                                                                                    0)),
                                                                              (__0__X9
                                                                                   ->baseclass__4node =
                                                                                   0))
                                                                           : 0),
                                                                      __0__X9))),
                                                        ((__0__X60->baseclass__4node = 1),
                                                         ((__0__X60->bclass__6basecl = __2__X61),
                                                          ((__0__X60->next__6basecl = __2__X62),
                                                           ((__0__X60->promoted__6basecl = 0),
                                                            ((__0__X60->init__6basecl = 0),
                                                             ((__0__X60->obj_offset__6basecl =
                                                                   (__0__X60->ptr_offset__6basecl =
                                                                        0)),
                                                              (__0__X60->allocated__6basecl =
                                                                   0))))))))
                                                     : 0),
                                                __0__X60))));
                                        if (__1t == 0)
                                            __1b = __3x;
                                        else
                                            __1t->next__6basecl = __3x;
                                        __1t = __3x;
                                        __3x->base__4node = __1l->base__4node;
                                        __3x->obj_offset__6basecl = __1l->obj_offset__6basecl;
                                    }
                                }
                                for (__1l = __1cl->baselist__8classdef; __1l;
                                     __1l = __1l->next__6basecl) {
                                    if (__1l->base__4node == 77) {
                                        register struct basecl *__0__X63;

                                        struct classdef *__2__X64;

                                        struct basecl *__2__X65;

                                        struct node *__0__X9;

                                        __1b =
                                            ((__0__X63 = 0),
                                             ((__2__X64 = __1l->bclass__6basecl),
                                              ((__2__X65 = __1b),
                                               (((__0__X63 ||
                                                  (__0__X63 = (struct basecl *)__nw__FUl(
                                                       (size_t)(sizeof(struct basecl)))))
                                                     ? ((__0__X63 =
                                                             (struct basecl
                                                                  *)((__0__X9 = (((
                                                                          struct node *)__0__X63))),
                                                                     (((__0__X9 ||
                                                                        (__0__X9 = (struct node *)
                                                                             __nw__FUl((
                                                                                 size_t)(sizeof(
                                                                                 struct node)))))
                                                                           ? (((__0__X9
                                                                                    ->base__4node =
                                                                                    0),
                                                                               (__0__X9
                                                                                    ->permanent__4node =
                                                                                    0)),
                                                                              (__0__X9
                                                                                   ->baseclass__4node =
                                                                                   0))
                                                                           : 0),
                                                                      __0__X9))),
                                                        ((__0__X63->baseclass__4node = 1),
                                                         ((__0__X63->bclass__6basecl = __2__X64),
                                                          ((__0__X63->next__6basecl = __2__X65),
                                                           ((__0__X63->promoted__6basecl = 0),
                                                            ((__0__X63->init__6basecl = 0),
                                                             ((__0__X63->obj_offset__6basecl =
                                                                   (__0__X63->ptr_offset__6basecl =
                                                                        0)),
                                                              (__0__X63->allocated__6basecl =
                                                                   0))))))))
                                                     : 0),
                                                __0__X63))));
                                        __1b->base__4node = __1l->base__4node;
                                        __1b->obj_offset__6basecl = __1l->obj_offset__6basecl;
                                    }
                                }

                                for (; __1b; __1b = __1l) {
                                    Pclass __2bcl;

                                    __2bcl = __1b->bclass__6basecl;
                                    __1l = __1b->next__6basecl;
                                    {
                                        Pname __2dtor;

                                        __2dtor = (__2bcl->c_dtor__8classdef);

                                        if (__2dtor) {
                                            Pexpr __3val;

                                            __3val = rptr__FP4typeP4expri(
                                                __2bcl->this_type__8classdef, __1th,
                                                __1b->obj_offset__6basecl);
                                            __3val = contents__4exprFv(__3val);
                                            {
                                                Pexpr __3e;

                                                __3e = call_dtor__FP4exprN21iT1(
                                                    __3val, (struct expr *)__2dtor,
                                                    (struct expr *)0, 45, (struct expr *)0);
                                                if (__1b->base__4node == 77) {
                                                    {
                                                        {
                                                            Pname __4dd;

                                                            __4dd = __0this->f_this__3fct
                                                                        ->__O1__4name.n_list;

                                                            for (; __4dd != __0this->argtype__3fct;
                                                                 __4dd = __4dd->__O1__4name.n_list)
                                                                if (strcmp(
                                                                        __4dd->__O2__4expr.string,
                                                                        __2bcl
                                                                            ->string__8classdef) ==
                                                                    0)
                                                                    break;

                                                            if (ansi_opt) {
                                                                __3e = __ct__4exprFUcP4exprT2(
                                                                    (struct expr *)0,
                                                                    (unsigned char)147, __3e, zero);
                                                                __3e->__O1__4expr.tp =
                                                                    (struct type *)zero_type;
                                                            }
                                                            __3e = __ct__4exprFUcP4exprT2(
                                                                (struct expr *)0, (unsigned char)68,
                                                                __3e, zero);
                                                            {
                                                                Pexpr __4two;

                                                                struct ival *__0__X66;

                                                                __4two =
                                                                    (struct expr
                                                                         *)((__0__X66 = 0),
                                                                            (((__0__X66 ||
                                                                               (__0__X66 = (struct
                                                                                            ival *)
                                                                                    __nw__4exprSFUl((
                                                                                        size_t)(sizeof(
                                                                                        struct
                                                                                        ival)))))
                                                                                  ? ((__0__X66 = (struct
                                                                                                  ival
                                                                                                      *)
                                                                                          __ct__4exprFUcP4exprT2(
                                                                                              ((struct
                                                                                                expr
                                                                                                    *)
                                                                                                   __0__X66),
                                                                                              (unsigned char)150,
                                                                                              (struct
                                                                                               expr
                                                                                                   *)0,
                                                                                              (struct
                                                                                               expr
                                                                                                   *)0)),
                                                                                     (__0__X66
                                                                                          ->__O2__4expr
                                                                                          .i1 = ((
                                                                                          long long)2)))
                                                                                  : 0),
                                                                             __0__X66));
                                                                __4two->__O1__4expr.tp =
                                                                    (struct type *)int_type;
                                                                __3e->__O4__4expr.cond =
                                                                    __ct__4exprFUcP4exprT2(
                                                                        (struct expr *)0,
                                                                        (unsigned char)52,
                                                                        (struct expr *)__1free_arg,
                                                                        __4two);
                                                            }
                                                        }
                                                    }
                                                }
                                                __1ee = (__1ee ? __ct__4exprFUcP4exprT2(
                                                                     (struct expr *)0,
                                                                     (unsigned char)71, __3e, __1ee)
                                                               : __3e);
                                            }
                                        }
                                        __dl__FPv((void *)__1b);
                                    }
                                }

                                {
                                    Pstmt __1es;

                                    struct estmt *__0__X82;

                                    struct loc __2__X83;

                                    __1es =
                                        (struct stmt
                                             *)(__1ee
                                                    ? ((__0__X82 = 0),
                                                       ((__2__X83 = curloc),
                                                        (((__0__X82 ||
                                                           (__0__X82 =
                                                                (struct estmt *)__nw__4stmtSFUl(
                                                                    (unsigned long)(sizeof(
                                                                        struct estmt)))))
                                                              ? ((__0__X82 = (struct estmt *)
                                                                      __ct__4stmtFUc3locP4stmt(
                                                                          ((struct stmt *)__0__X82),
                                                                          ((unsigned char)72),
                                                                          __2__X83,
                                                                          ((struct stmt *)0))),
                                                                 (__0__X82->__O2__4stmt.e = __1ee))
                                                              : 0),
                                                         __0__X82)))
                                                    : (((struct estmt *)0)));

                                    __1ee =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                               __1th, (struct expr *)0);
                                    {
                                        Pname __1n;
                                        Pexpr __1del;

                                        struct call *__0__X68;

                                        struct expr *__2__X69;

                                        struct expr *__2__X70;

                                        __1n = __ct__4nameFPCc((struct name *)0,
                                                               oper_name__FUc((unsigned char)9));
                                        __1del = find_name__FP4nameP8classdefP5tableiT1(
                                            __1n, __1cl, scope, 109, curr_fct);
                                        if ((__1del->__O1__4expr.tp->base__4node == 76) ||
                                            ((((struct fct *)((
                                                  (struct fct *)__1del->__O1__4expr.tp))))
                                                 ->nargs__3fct == 2)) {
                                            Pexpr __2ss;

                                            struct texpr *__0__X67;

                                            __2ss =
                                                (struct expr
                                                     *)((__0__X67 = 0),
                                                        (((__0__X67 ||
                                                           (__0__X67 =
                                                                (struct texpr *)__nw__4exprSFUl((
                                                                    size_t)(sizeof(struct texpr)))))
                                                              ? ((__0__X67 = (struct texpr *)
                                                                      __ct__4exprFUcP4exprT2(
                                                                          ((struct expr *)__0__X67),
                                                                          ((unsigned char)30),
                                                                          ((struct expr *)0),
                                                                          (struct expr *)0)),
                                                                 (__0__X67->__O4__4expr.tp2 =
                                                                      ((struct type *)__1cl)))
                                                              : 0),
                                                         __0__X67));
                                            __2ss->__O1__4expr.tp = (struct type *)uint_type;
                                            __1ee->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                                                (struct expr *)0, (unsigned char)140, __2ss,
                                                (struct expr *)0);
                                        }
                                        __1ee =
                                            (struct expr
                                                 *)((__0__X68 = 0),
                                                    ((__2__X69 = __1del),
                                                     ((__2__X70 = __1ee),
                                                      (((__0__X68 ||
                                                         (__0__X68 = (struct call *)__nw__4exprSFUl(
                                                              (size_t)(sizeof(struct call)))))
                                                            ? (__0__X68 = (struct call *)
                                                                   __ct__4exprFUcP4exprT2(
                                                                       ((struct expr *)__0__X68),
                                                                       (unsigned char)109, __2__X69,
                                                                       __2__X70))
                                                            : 0),
                                                       __0__X68))));
                                        __1ee->__O1__4expr.tp =
                                            call_fct__4exprFP5table(__1ee, scope);

                                        {
                                            Pstmt __1ess;

                                            register struct ifstmt *__0__X71;

                                            struct loc __2__X72;

                                            struct expr *__2__X73;

                                            struct stmt *__2__X74;

                                            struct stmt *__2__X75;

                                            register struct ifstmt *__0__X76;

                                            struct loc __2__X77;

                                            struct stmt *__2__X78;

                                            struct stmt *__2__X79;

                                            struct estmt *__0__X80;

                                            struct loc __2__X81;

                                            __1ess =
                                                (struct stmt
                                                     *)((__0__X80 = 0),
                                                        ((__2__X81 = curloc),
                                                         (((__0__X80 ||
                                                            (__0__X80 =
                                                                 (struct estmt *)__nw__4stmtSFUl(
                                                                     (unsigned long)(sizeof(
                                                                         struct estmt)))))
                                                               ? ((__0__X80 = (struct estmt *)
                                                                       __ct__4stmtFUc3locP4stmt(
                                                                           ((struct stmt *)
                                                                                __0__X80),
                                                                           ((unsigned char)72),
                                                                           __2__X81,
                                                                           ((struct stmt *)0))),
                                                                  (__0__X80->__O2__4stmt.e = __1ee))
                                                               : 0),
                                                          __0__X80)));
                                            __1ess =
                                                (struct stmt
                                                     *)((__0__X71 = 0),
                                                        ((__2__X72 = curloc),
                                                         ((__2__X73 = __ct__4exprFUcP4exprT2(
                                                               (struct expr *)0, (unsigned char)52,
                                                               (struct expr *)__1free_arg, one)),
                                                          ((__2__X74 = __1ess),
                                                           ((__2__X75 = 0),
                                                            (((__0__X71 ||
                                                               (__0__X71 = (struct ifstmt *)
                                                                    __nw__4stmtSFUl((size_t)(sizeof(
                                                                        struct ifstmt)))))
                                                                  ? ((__0__X71 = (struct ifstmt *)
                                                                          __ct__4stmtFUc3locP4stmt(
                                                                              ((struct stmt *)
                                                                                   __0__X71),
                                                                              (unsigned char)20,
                                                                              __2__X72, __2__X74)),
                                                                     ((__0__X71->__O2__4stmt.e =
                                                                           __2__X73),
                                                                      (__0__X71->__O3__4stmt
                                                                           .else_stmt = __2__X75)))
                                                                  : 0),
                                                             __0__X71))))));
                                            if (__1es)
                                                __1es->s_list__4stmt = __1ess;
                                            else
                                                __1es = __1ess;

                                            ((__1free_arg->n_used__4name++), (((void)0)));
                                            (((((struct name *)(((struct name *)__1th))))
                                                  ->n_used__4name++),
                                             (((void)0)));

                                            if (__1dtail)
                                                __1dtail->s_list__4stmt = __1es;
                                            else
                                                del_list = __1es;

                                            if (!perf_opt)
                                                del_list =
                                                    (struct stmt
                                                         *)((__0__X76 = 0),
                                                            ((__2__X77 = curloc),
                                                             ((__2__X78 = del_list),
                                                              ((__2__X79 = 0),
                                                               (((__0__X76 ||
                                                                  (__0__X76 = (struct ifstmt *)
                                                                       __nw__4stmtSFUl(
                                                                           (size_t)(sizeof(
                                                                               struct ifstmt)))))
                                                                     ? ((__0__X76 = (struct ifstmt
                                                                                         *)
                                                                             __ct__4stmtFUc3locP4stmt(
                                                                                 ((struct stmt *)
                                                                                      __0__X76),
                                                                                 (unsigned char)20,
                                                                                 __2__X77,
                                                                                 __2__X78)),
                                                                        ((__0__X76->__O2__4stmt.e =
                                                                              __1th),
                                                                         (__0__X76->__O3__4stmt
                                                                              .else_stmt =
                                                                              __2__X79)))
                                                                     : 0),
                                                                __0__X76)))));
                                            if (del_list)
                                                simpl__4stmtFv(del_list);
                                            return __1dtail;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

Pclass find_vbase_ptr__FP8classdefT1(Pclass __1cl, Pclass __1vbase);

Pclass find_vbase_ptr__FP8classdefT1(Pclass __1cl, Pclass __1vbase) {
    {
        {
            Pbcl __1bb;

            __1bb = __1cl->baselist__8classdef;

            for (; __1bb; __1bb = __1bb->next__6basecl) {
                if (__1bb->base__4node == 77) {
                    struct classdef *__1__X84;

                    struct classdef *__1__X85;

                    if (((__1__X84 = __1bb->bclass__6basecl),
                         ((__1__X85 = __1vbase),
                          (((__1__X84 == __1__X85)
                                ? 1
                                : ((__1__X84 && __1__X85)
                                       ? (((int)same_class__8classdefFP8classdefi(__1__X84,
                                                                                  __1__X85, 0)))
                                       : 0))))) &&
                        __1bb->ptr_offset__6basecl)
                        return __1cl;
                } else {
                    Pclass __3f;

                    __3f = find_vbase_ptr__FP8classdefT1(__1bb->bclass__6basecl, __1vbase);
                    if (__3f)
                        return __3f;
                }
            }
            return (struct classdef *)0;
        }
    }
}

Pclass second_base__FP8classdefT1(Pclass __1cl, Pclass __1base);

Pclass second_base__FP8classdefT1(Pclass __1cl, Pclass __1base) {
    {
        {
            Pbcl __1b;

            __1b = __1cl->baselist__8classdef;

            for (; __1b && (__1b->base__4node == 85); __1b = __1b->next__6basecl) {
                struct classdef *__1__X86;

                struct classdef *__1__X87;

                if (((__1__X86 = __1b->bclass__6basecl),
                     ((__1__X87 = __1base),
                      (((__1__X86 == __1__X87)
                            ? 1
                            : ((__1__X86 && __1__X87) ? (((int)same_class__8classdefFP8classdefi(
                                                            __1__X86, __1__X87, 0)))
                                                      : 0)))))) {
                    if (__1b == __1cl->baselist__8classdef)
                        return (struct classdef *)0;
                    return __1base;
                }
                {
                    Pclass __2bb;

                    __2bb = second_base__FP8classdefT1(__1b->bclass__6basecl, __1base);
                    if (__2bb == (((struct classdef *)-1)))
                        continue;
                    if (__2bb) {
                        if (__1b != __1cl->baselist__8classdef)
                            error__FiPCc((int)'s', (const char *)"C hierarchy too complicated");
                        return __2bb;
                    }
                    if (__1b == __1cl->baselist__8classdef)
                        return (struct classdef *)0;
                    return __1b->bclass__6basecl;
                }
            }
            return (((struct classdef *)-1));
        }
    }
}

void print_all_vtbls__8classdefFP8classdef(struct classdef *__0this, Pclass);

extern Pname find_vptr__FP8classdef(Pclass);

Pbcl get_base__8classdefFPCc(struct classdef *__0this, const char *);

extern const char *get_classname__FPCc(const char *);

Pexpr get_vptr_exp__8classdefFPCc(struct classdef *__0this, const char *__1s);

extern const char *drop_classname__FPCc(const char *);

Pexpr get_vptr_exp__8classdefFPCc(register struct classdef *__0this, const char *__1s) {
    if (__0this->c_body__8classdef == 1)
        dcl_print__8classdefFP4name(__0this, (struct name *)0);

    if (__0this->c_body__8classdef == 3)
        print_all_vtbls__8classdefFP8classdef(__0this, __0this);
    if (__1s == 0)
        return (struct expr *)find_vptr__FP8classdef(__0this);
    {
        Pbcl __1b;

        __1b = get_base__8classdefFPCc(__0this, get_classname__FPCc(__1s));
        if (strcmp(__1s, __1b->bclass__6basecl->string__8classdef) == 0)
            __1s = 0;
        {
            Pexpr __1vp;

            register struct mdot *__0__X88;

            const char *__2__X89;

            __1vp = get_vptr_exp__8classdefFPCc(
                __1b->bclass__6basecl, __1s ? drop_classname__FPCc(__1s) : (((const char *)0)));
            if ((__1b == __0this->baselist__8classdef) && (__1b->base__4node != 77))
                return __1vp;
            __1vp = (struct expr *)((__0__X88 = 0),
                                    ((__2__X89 = __1b->bclass__6basecl->string__8classdef),
                                     (((__0__X88 || (__0__X88 = (struct mdot *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct mdot)))))
                                           ? ((__0__X88 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X88), (unsigned char)177,
                                                   (struct expr *)0, (struct expr *)0)),
                                              ((__0__X88->__O3__4expr.string2 = __2__X89),
                                               (__0__X88->__O4__4expr.mem = __1vp)))
                                           : 0),
                                      __0__X88)));
            if (__0this->c_body__8classdef == 1)
                dcl_print__8classdefFP4name(__1b->bclass__6basecl, (struct name *)0);
            if (__0this->c_body__8classdef == 3)
                print_all_vtbls__8classdefFP8classdef(__1b->bclass__6basecl, __1b->bclass__6basecl);
            if (__1b->base__4node == 77) {
                __1vp->__O2__4expr.i1 = 1;
                if (__1b->ptr_offset__6basecl == 0) {
                    Pclass __3bb;
                    Pclass __3sb;

                    register struct mdot *__0__X90;

                    const char *__2__X91;

                    __3bb = find_vbase_ptr__FP8classdefT1(__0this, __1b->bclass__6basecl);
                    __3sb = second_base__FP8classdefT1(topclass, __3bb);

                    if (__3sb && (__3sb != (((struct classdef *)-1))))
                        __1vp =
                            (struct expr
                                 *)((__0__X90 = 0),
                                    ((__2__X91 = __3sb->string__8classdef),
                                     (((__0__X90 || (__0__X90 = (struct mdot *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct mdot)))))
                                           ? ((__0__X90 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X90), (unsigned char)177,
                                                   (struct expr *)0, (struct expr *)0)),
                                              ((__0__X90->__O3__4expr.string2 = __2__X91),
                                               (__0__X90->__O4__4expr.mem = __1vp)))
                                           : 0),
                                      __0__X90)));
                }
            }
            return __1vp;
        }
    }
}

void assign__4nameFv(struct name *__0this);

void simpl__4callFv(struct call *__0this);

extern char *strcpy(char *, const char *);

Pname has_ictor__8classdefFv(struct classdef *__0this);

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

Pptr is_ref__4typeFv(struct type *__0this);

bit tconst__4typeFv(struct type *__0this);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

int ctor_simpl__3fctFP8classdefP4expr(register struct fct *__0this, Pclass __1cl, Pexpr __1th) {
    Ptable __1tbl;

    int __1ass_count;

    __1tbl = __1cl->memtbl__8classdef;

    __1ass_count = 0;
    init_list = 0;

    {
        {
            Pbcl __1l;

            __1l = __1cl->baselist__8classdef;

            for (; __1l; __1l = __1l->next__6basecl) {
                Pexpr __2i;

                __2i = __1l->init__6basecl;

                if (__1l->base__4node != 77)
                    continue;
                __1l->init__6basecl = 0;

                {
                    Pclass __2bc;
                    Pexpr __2dp;

                    Pname __2dd;

                    __2bc = __1l->bclass__6basecl;
                    __2dp = 0;

                    __2dd = __0this->f_this__3fct->__O1__4name.n_list;
                    for (; __2dd != __0this->argtype__3fct; __2dd = __2dd->__O1__4name.n_list)
                        if (strcmp(__2dd->__O2__4expr.string, __2bc->string__8classdef) == 0)
                            break;

                    {
                        int __2off;
                        Pexpr __2val;

                        __2off = __1l->obj_offset__6basecl;
                        __2val = rptr__FP4typeP4expri(__2bc->this_type__8classdef, __1th, __2off);
                        __2dp = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                       (struct expr *)__2dd, __2val);
                        assign__4nameFv(__2dd);

                        if (__2i) {
                            switch (__2i->base__4node) {
                                unsigned long __2__X100;

                            case 70:
                            case 71:
                                simpl__4exprFv(__2i);
                                break;
                            case 109:
                            case 146: {
                                Pcall __5cc;
                                Pname __5bn;

                                __5cc = (((struct call *)(((struct call *)__2i))));
                                __5bn = __5cc->__O4__4expr.fct_name;
                                __1ass_count =
                                    (((struct fct *)(((struct fct *)__5bn->__O1__4expr.tp))))
                                        ->f_this__3fct->n_assigned_to__4name;
                                simpl__4callFv(__5cc);
                                break;
                            }
                            default: {
                                struct ea __0__V92;

                                error__FiPCcRC2eaN33(
                                    (int)'i', (const char *)"badBCIr %k",
                                    (const struct ea *)((__2__X100 = __2i->base__4node),
                                                        (((((&__0__V92)->__O1__2ea.i = __2__X100),
                                                           0)),
                                                         (&__0__V92))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            }
                            __2dp = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71,
                                                           __2dp, __2i);
                        }

                        {
                            {
                                Pname __2a;

                                __2a = __0this->f_args__3fct->__O1__4name.n_list;

                                for (; __2a; __2a = __2a->__O1__4name.n_list)
                                    if (strcmp(__2bc->string__8classdef,
                                               __2a->__O2__4expr.string) == 0) {
                                        __2dp = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                       (unsigned char)68, __2dp,
                                                                       (struct expr *)__2a);
                                        __2dp->__O4__4expr.cond = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)62,
                                            (struct expr *)__2a, zero);
                                        break;
                                    }

                                {
                                    {
                                        Pbcl __2ll;

                                        __2ll = __1cl->baselist__8classdef;

                                        for (; __2ll; __2ll = __2ll->next__6basecl) {
                                            struct classdef *__1__X101;

                                            struct classdef *__1__X102;

                                            if (((__1__X101 = __2ll->bclass__6basecl),
                                                 ((__1__X102 = __2bc),
                                                  (((__1__X101 == __1__X102)
                                                        ? 1
                                                        : ((__1__X101 && __1__X102)
                                                               ? (((int)
                                                                       same_class__8classdefFP8classdefi(
                                                                           __1__X101, __1__X102,
                                                                           0)))
                                                               : 0))))) &&
                                                __2ll->ptr_offset__6basecl) {
                                                Pexpr __4dpp;

                                                register struct mdot *__0__X103;

                                                const char *__2__X104;

                                                __4dpp =
                                                    (struct expr
                                                         *)((__0__X103 = 0),
                                                            ((__2__X104 = __2bc->string__8classdef),
                                                             (((__0__X103 ||
                                                                (__0__X103 =
                                                                     (struct mdot *)__nw__4exprSFUl(
                                                                         (size_t)(sizeof(
                                                                             struct mdot)))))
                                                                   ? ((__0__X103 = (struct mdot *)
                                                                           __ct__4exprFUcP4exprT2(
                                                                               ((struct expr *)
                                                                                    __0__X103),
                                                                               (unsigned char)177,
                                                                               (struct expr *)0,
                                                                               (struct expr *)0)),
                                                                      ((__0__X103->__O3__4expr
                                                                            .string2 = __2__X104),
                                                                       (__0__X103->__O4__4expr.mem =
                                                                            __1th)))
                                                                   : 0),
                                                              __0__X103)));
                                                __4dpp->__O2__4expr.i1 = 3;
                                                __2dp = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                               (unsigned char)70,
                                                                               __4dpp, __2dp);

                                                break;
                                            }
                                        }

                                        if (__2dp)
                                            init_list =
                                                (init_list
                                                     ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                              (unsigned char)71,
                                                                              __2dp, init_list)
                                                     : __2dp);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            {
                {
                    {
                        Pbcl __2l;

                        __2l = __1cl->baselist__8classdef;

                        for (; __2l; __2l = __2l->next__6basecl) {
                            Pexpr __3i;

                            __3i = __2l->init__6basecl;
                            if ((__3i == 0) || (__2l->base__4node == 77))
                                continue;

                            __2l->init__6basecl = 0;

                            switch (__3i->base__4node) {
                                unsigned long __2__X105;

                            case 70:
                            case 71:
                                simpl__4exprFv(__3i);
                                break;
                            case 109:
                            case 146: {
                                Pcall __5cc;
                                Pname __5bn;

                                __5cc = (((struct call *)(((struct call *)__3i))));
                                __5bn = __5cc->__O4__4expr.fct_name;
                                __1ass_count =
                                    (((struct fct *)(((struct fct *)__5bn->__O1__4expr.tp))))
                                        ->f_this__3fct->n_assigned_to__4name;
                                simpl__4callFv(__5cc);

                                if ((__2l == __1cl->baselist__8classdef) &&
                                    (__1cl->baselist__8classdef->next__6basecl == 0))
                                    __3i =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                               __1th, (struct expr *)__5cc);
                                break;
                            }
                            default: {
                                struct ea __0__V93;

                                error__FiPCcRC2eaN33(
                                    (int)'i', (const char *)"badBCIr %k",
                                    (const struct ea *)((__2__X105 = __3i->base__4node),
                                                        (((((&__0__V93)->__O1__2ea.i = __2__X105),
                                                           0)),
                                                         (&__0__V93))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            }

                            init_list = (init_list ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                            (unsigned char)147,
                                                                            init_list, __3i)
                                                   : __3i);
                        }
                    }
                }
            }

            {
                {
                    Pvirt __1blist;

                    int __1i;

                    __1blist = __1cl->virt_list__8classdef;

                    for (; __1blist; __1blist = __1blist->next__4virt) {
                        topclass = __1cl;
                        {
                            Pexpr __2vp;

                            char *__2str;
                            const char *__2cs;

                            __2vp = get_vptr_exp__8classdefFPCc(__1cl, __1blist->string__4virt);

                            __2str = 0;
                            __2cs = (__1cl->nested_sig__4type
                                         ? (((const char *)__1cl->nested_sig__4type))
                                         : __1cl->string__8classdef);
                            if (__1cl->lex_level__4type && (__1cl->nested_sig__4type == 0)) {
                                __2str = (((char *)__nw__FUl(
                                    (size_t)((sizeof(char)) * (__1cl->c_strlen__8classdef + 1)))));
                                strcpy(__2str, (const char *)__1cl->local_sig__4type);
                            }
                            {
                                Pexpr __2vtbl;

                                Pexpr __2ee;

                                register struct text_expr *__0__X106;

                                const char *__2__X107;

                                const char *__2__X108;

                                struct ref *__0__X109;

                                struct expr *__2__X110;

                                struct expr *__2__X111;

                                __2vtbl =
                                    (struct expr
                                         *)((__0__X106 = 0),
                                            ((__2__X107 = __1blist->string__4virt),
                                             ((__2__X108 =
                                                   (__2str ? (((const char *)__2str)) : __2cs)),
                                              (((__0__X106 ||
                                                 (__0__X106 = (struct text_expr *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct text_expr)))))
                                                    ? ((__0__X106 = (struct text_expr *)
                                                            __ct__4exprFUcP4exprT2(
                                                                ((struct expr *)__0__X106),
                                                                (unsigned char)165,
                                                                (struct expr *)0,
                                                                (struct expr *)0)),
                                                       ((__0__X106->__O2__4expr.string = __2__X107),
                                                        (__0__X106->__O3__4expr.string2 =
                                                             __2__X108)))
                                                    : 0),
                                               __0__X106))));

                                __2ee =
                                    (struct expr
                                         *)((__0__X109 = 0),
                                            ((__2__X110 = __1th),
                                             ((__2__X111 = __2vp),
                                              (((__0__X109 ||
                                                 (__0__X109 = (struct ref *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct ref)))))
                                                    ? ((__0__X109 =
                                                            (struct ref *)__ct__4exprFUcP4exprT2(
                                                                ((struct expr *)__0__X109),
                                                                ((unsigned char)44), __2__X110,
                                                                (struct expr *)0)),
                                                       (__0__X109->__O4__4expr.mem = __2__X111))
                                                    : 0),
                                               __0__X109))));

                                __2ee->__O1__4expr.tp = __2vp->__O1__4expr.tp;
                                __2ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                               __2ee, __2vtbl);
                                init_list = (init_list ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                                (unsigned char)71,
                                                                                init_list, __2ee)
                                                       : __2ee);
                            }
                        }
                    }

                    ;
                    {
                        {
                            Pname __1m;

                            int __2__X112;

                            int __2__X119;

                            __1m = ((__2__X119 = (__1i = 1)),
                                    ((((__2__X119 <= 0) || (__1tbl->free_slot__5table <= __2__X119))
                                          ? (((struct name *)0))
                                          : (__1tbl->entries__5table[__2__X119]))));

                            for (; __1m;
                                 __1m = (__1m->n_tbl_list__4name
                                             ? __1m->n_tbl_list__4name
                                             : ((__2__X112 = (++__1i)),
                                                ((((__2__X112 <= 0) ||
                                                   (__1tbl->free_slot__5table <= __2__X112))
                                                      ? (((struct name *)0))
                                                      : (__1tbl->entries__5table[__2__X112])))))) {
                                if (__1m->base__4node == 123)
                                    continue;
                                {
                                    Ptype __2t;
                                    Pname __2cn;
                                    Pname __2ctor;

                                    __2t = __1m->__O1__4expr.tp;

                                    if (__2t == 0)
                                        continue;

                                    switch (__2t->base__4node) {
                                    case 108:
                                    case 76:
                                    case 6:
                                    case 13:
                                        continue;
                                    }

                                    switch (__1m->n_stclass__4name) {
                                    case 31:
                                    case 13:
                                        continue;
                                    }

                                    if (__1m->base__4node == 25)
                                        continue;

                                    {
                                        Pexpr __2ee;

                                        __2ee = __1m->__O3__4expr.n_initializer;
                                        if (__2ee)
                                            __1m->__O3__4expr.n_initializer = 0;

                                        if (__2ee) {
                                        } else if (__2cn = is_cl_obj__4typeFv(__2t)) {
                                            Pclass __3cl;

                                            __3cl = (((struct classdef *)((
                                                (struct classdef *)__2cn->__O1__4expr.tp))));
                                            if (__2ctor = has_ictor__8classdefFv(__3cl)) {
                                                Pexpr __4r;

                                                struct ref *__0__X113;

                                                struct expr *__2__X114;

                                                struct expr *__2__X115;

                                                __4r =
                                                    (struct expr
                                                         *)((__0__X113 = 0),
                                                            ((__2__X114 = __1th),
                                                             ((__2__X115 = (struct expr *)__1m),
                                                              (((__0__X113 ||
                                                                 (__0__X113 =
                                                                      (struct ref *)__nw__4exprSFUl(
                                                                          (size_t)(sizeof(
                                                                              struct ref)))))
                                                                    ? ((__0__X113 = (struct ref *)
                                                                            __ct__4exprFUcP4exprT2(
                                                                                ((struct expr *)
                                                                                     __0__X113),
                                                                                ((unsigned char)44),
                                                                                __2__X114,
                                                                                (struct expr *)0)),
                                                                       (__0__X113->__O4__4expr.mem =
                                                                            __2__X115))
                                                                    : 0),
                                                               __0__X113))));
                                                __2ee = call_ctor__FP5tableP4exprN22iT2(
                                                    __1tbl, __4r, (struct expr *)__2ctor,
                                                    (struct expr *)0, 45, (struct expr *)0);
                                                check_visibility__FP4nameT1P8classdefP5tableT1(
                                                    __2ctor, (struct name *)0,
                                                    ((struct classdef *)((
                                                        (struct classdef *)
                                                            __2ctor->__O4__4expr.n_table
                                                                ->t_name__5table->__O1__4expr.tp))),
                                                    __1tbl, curr_fct);
                                            } else if ((__3cl->c_ctor__8classdef)) {
                                                {
                                                    struct ea __0__V94;

                                                    struct ea __0__V95;

                                                    error__FPCcRC2eaN32(
                                                        (const char
                                                             *)"M%n needsIr (no defaultK forC %s)",
                                                        (const struct ea
                                                             *)(((&__0__V94)->__O1__2ea.p =
                                                                     ((const void *)__1m)),
                                                                (&__0__V94)),
                                                        (const struct ea *)__ct__2eaFPCv(
                                                            &__0__V95,
                                                            (const void *)__3cl->string__8classdef),
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0);
                                                }
                                            }
                                        } else if (cl_obj_vec) {
                                            Pclass __3cl;

                                            __3cl = (((struct classdef *)((
                                                (struct classdef *)cl_obj_vec->__O1__4expr.tp))));
                                            if (__2ctor = has_ictor__8classdefFv(__3cl)) {
                                                Pexpr __4mm;

                                                struct ref *__0__X116;

                                                struct expr *__2__X117;

                                                struct expr *__2__X118;

                                                __4mm =
                                                    (struct expr
                                                         *)((__0__X116 = 0),
                                                            ((__2__X117 = __1th),
                                                             ((__2__X118 = (struct expr *)__1m),
                                                              (((__0__X116 ||
                                                                 (__0__X116 =
                                                                      (struct ref *)__nw__4exprSFUl(
                                                                          (size_t)(sizeof(
                                                                              struct ref)))))
                                                                    ? ((__0__X116 = (struct ref *)
                                                                            __ct__4exprFUcP4exprT2(
                                                                                ((struct expr *)
                                                                                     __0__X116),
                                                                                ((unsigned char)44),
                                                                                __2__X117,
                                                                                (struct expr *)0)),
                                                                       (__0__X116->__O4__4expr.mem =
                                                                            __2__X118))
                                                                    : 0),
                                                               __0__X116))));
                                                __4mm->__O1__4expr.tp = __1m->__O1__4expr.tp;

                                                {
                                                    Pname __4vctor;

                                                    __4vctor = (__3cl->c_vtor__8classdef);
                                                    __2ee = cdvec__FP4nameP4exprP8classdefT1iN22(
                                                        vec_new_fct, __4mm, __3cl,
                                                        __4vctor ? __4vctor : __2ctor, -1,
                                                        (struct expr *)0, (struct expr *)0);
                                                    check_visibility__FP4nameT1P8classdefP5tableT1(
                                                        __2ctor, (struct name *)0,
                                                        ((struct classdef *)((
                                                            (struct classdef *)__2ctor->__O4__4expr
                                                                .n_table->t_name__5table
                                                                ->__O1__4expr.tp))),
                                                        __1tbl, curr_fct);
                                                }
                                            } else if ((__3cl->c_ctor__8classdef)) {
                                                {
                                                    struct ea __0__V96;

                                                    struct ea __0__V97;

                                                    error__FPCcRC2eaN32(
                                                        (const char *)"M%n[] needsIr (no defaultK "
                                                                      "forC %s)",
                                                        (const struct ea
                                                             *)(((&__0__V96)->__O1__2ea.p =
                                                                     ((const void *)__1m)),
                                                                (&__0__V96)),
                                                        (const struct ea *)__ct__2eaFPCv(
                                                            &__0__V97,
                                                            (const void *)__3cl->string__8classdef),
                                                        (const struct ea *)ea0,
                                                        (const struct ea *)ea0);
                                                }
                                            }
                                        } else if (is_ref__4typeFv(__2t)) {
                                            {
                                                struct ea __0__V98;

                                                error__FPCcRC2eaN32(
                                                    (const char *)"RM%n needsIr",
                                                    (const struct ea *)(((&__0__V98)->__O1__2ea.p =
                                                                             ((const void *)__1m)),
                                                                        (&__0__V98)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                                            }
                                        } else if (tconst__4typeFv(__2t) && (vec_const == 0)) {
                                            {
                                                struct ea __0__V99;

                                                error__FPCcRC2eaN32(
                                                    (const char *)"constM%n needsIr",
                                                    (const struct ea *)(((&__0__V99)->__O1__2ea.p =
                                                                             ((const void *)__1m)),
                                                                        (&__0__V99)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                                            }
                                        }

                                        if (__2ee) {
                                            simpl__4exprFv(__2ee);
                                            init_list =
                                                (init_list
                                                     ? __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                              (unsigned char)71,
                                                                              init_list, __2ee)
                                                     : __2ee);
                                        }
                                    }
                                }
                            }

                            return __1ass_count;
                        }
                    }
                }
            }
        }
    }
}

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

Pstmt simpl__5blockFv(struct block *__0this);

extern Pstmt trim_tail__FP4stmt(Pstmt __0tt);

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

void __dt__5tableFv(struct table *__0this, int);

void simpl__3fctFv(register struct fct *__0this) {
    Pexpr __1th;
    Ptable __1tbl;
    Pstmt __1tail;
    Pclass __1cl;

    __1th = (struct expr *)__0this->f_this__3fct;
    __1tbl = __0this->body__3fct->memtbl__4stmt;

    __1cl = 0;
    if (((__1th && __1th->__O1__4expr.tp) &&
         (((struct ptr *)(((struct ptr *)__1th->__O1__4expr.tp))))->typ__5pvtyp) &&
        (((struct basetype *)((
             (struct basetype *)(((struct ptr *)(((struct ptr *)__1th->__O1__4expr.tp))))
                 ->typ__5pvtyp))))
            ->b_name__8basetype)
        __1cl = (((struct classdef *)((
            (struct classdef *)(((struct basetype *)((
                                    (struct basetype *)(((struct ptr *)((
                                                            (struct ptr *)__1th->__O1__4expr.tp))))
                                        ->typ__5pvtyp))))
                ->b_name__8basetype->__O1__4expr.tp))));

    {
        Pstmt __1dtail;

        Pname __1ocurr_fct;
        int __1oret;
        int __1oim;

        __1dtail = 0;

        __1ocurr_fct = curr_fct;
        __1oret = no_of_returns;
        __1oim = imeasure;

        del_list = 0;
        continue_del_list = 0;
        break_del_list = 0;
        scope = __1tbl;
        if (scope == 0)
            error__FiPCc((int)'i', (const char *)"F::simpl()");
        {
            int __1ass_count;

            struct dcl_context *__0__X125;

            __1ass_count = 0;
            imeasure = 0;
            no_of_returns = 0;

            ((((cc++),
               (((cc >= ccvec_end) ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow")
                                   : 0),
                (((*cc)) = (*(cc - 1))))),
              (((void)0))));
            cc->nof__11dcl_context = curr_fct;
            cc->ftbl__11dcl_context = __1tbl;

            {
                {
                    Plist __1l;

                    extern bit need_lift;
                    bit __1onl;
                    Ptable __1ott;

                    struct dcl_context *__0__X162;

                    __1l = __0this->local_class__3fct;

                    for (; __1l; __1l = __1l->l__9name_list) {
                        Pname __2n;
                        Pclass __2cl;

                        __2n = __1l->f__9name_list;
                        __2cl = (((struct classdef *)((
                            (struct classdef *)(((struct basetype *)((
                                                    (struct basetype *)__2n->__O1__4expr.tp))))
                                ->b_name__8basetype->__O1__4expr.tp))));
                        if (__2cl->c_body__8classdef == 1)
                            dcl_print__8classdefFP4name(__2cl, (struct name *)0);
                    }

                    (((struct fct *)(((struct fct *)cc->nof__11dcl_context->__O1__4expr.tp))))
                        ->local_class__3fct = __0this->local_class__3fct;
                    __0this->local_class__3fct = 0;

                    switch (curr_fct->n_scope__4name) {
                    case 0:
                    case 25:
                        cc->not4__11dcl_context = curr_fct->__O4__4expr.n_table->t_name__5table;
                        cc->cot__11dcl_context = (((struct classdef *)((
                            (struct classdef *)cc->not4__11dcl_context->__O1__4expr.tp))));
                        cc->tot__11dcl_context = cc->cot__11dcl_context->this_type__8classdef;
                    }

                    switch (curr_fct->n_oper__4name) {
                    case 162:
                        __1dtail = dtor_simpl__3fctFP8classdefP4expr(__0this, __1cl, __1th);
                        break;
                    case 161:
                        __1ass_count = ctor_simpl__3fctFP8classdefP4expr(__0this, __1cl, __1th);
                    }

                    ;
                    __1onl = need_lift;
                    __1ott = tmp_tbl;
                    need_lift = 0;
                    tmp_tbl = __ct__5tableFsP5tableP4name((struct table *)0, (short)12,
                                                          (struct table *)0, (struct name *)0);

                    __1tail = simpl__5blockFv(__0this->body__3fct);

                    need_lift = __1onl;
                    __dt__5tableFv(tmp_tbl, 3);
                    tmp_tbl = __1ott;

                    if (!__0this->body__3fct)
                        return;

                    if ((skiptypedefs__4typeFv(__0this->returns__3fct)->base__4node != 38) ||
                        __0this->f_result__3fct) {
                        if (no_of_returns) {
                            Pstmt __3tt;

                            __3tt = (((__1tail->base__4node == 28) || (__1tail->base__4node == 115))
                                         ? __1tail
                                         : trim_tail__FP4stmt(__1tail));

                            if (__3tt)
                                switch (__3tt->base__4node) {
                                    const void *__2__X126;

                                case 28:
                                case 19:
                                    del_list = 0;
                                    break;
                                case 72:
                                    if (__3tt->__O2__4stmt.e)
                                        switch (__3tt->__O2__4stmt.e->base__4node) {
                                        case 168:
                                        case 146:
                                            goto chicken;
                                        }
                                default:
                                    if (warning_opt || strcmp(curr_fct->__O2__4expr.string,
                                                              (const char *)"main")) {

                                        struct ea __0__V120;

                                        error__FiPCcRC2eaN33(
                                            (int)'w',
                                            (const char *)"maybe no value returned from%n",
                                            (const struct ea *)((__2__X126 =
                                                                     (const void *)curr_fct),
                                                                (((&__0__V120)->__O1__2ea.p =
                                                                      __2__X126),
                                                                 (&__0__V120))),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                    }
                                case 20:
                                    if ((((__3tt->base__4node == 20) &&
                                          (__1tail->base__4node == 20)) &&
                                         (__3tt->__O3__4stmt.else_stmt == 0)) &&
                                        (no_of_returns == 1)) {

                                        if ((strcmp(curr_fct->__O2__4expr.string,
                                                    (const char *)"main") == 0) &&
                                            (skiptypedefs__4typeFv(__0this->returns__3fct)
                                                 ->base__4node != 38)) {
                                            error__FiP3locPCcRC2eaN34(
                                                (int)'w', &__3tt->where__4stmt,
                                                (const char *)"maybe no value returned from main()",
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                                        } else
                                            error__FP3locPCcRC2eaN33(
                                                &__3tt->where__4stmt,
                                                (const char
                                                     *)"if with return but no else with return",
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                                    }
                                case 33:
                                case 10:
                                case 39:
                                case 16:
                                case 115:
                                chicken:
                                    break;
                                }
                        } else {
                            const void *__2__X127;

                            if (((((struct fct *)(((struct fct *)curr_fct->__O1__4expr.tp))))
                                     ->f_inline__3fct &&
                                 (skiptypedefs__4typeFv(
                                      (((struct fct *)(((struct fct *)curr_fct->__O1__4expr.tp))))
                                          ->returns__3fct) != (((struct type *)void_type)))) &&
                                is_cl_obj__4typeFv(
                                    (((struct fct *)(((struct fct *)curr_fct->__O1__4expr.tp))))
                                        ->returns__3fct)) {
                                struct ea __0__V121;

                                error__FPCcRC2eaN32(
                                    (const char *)"no value returned from%n",
                                    (const struct ea *)((__2__X127 = (const void *)curr_fct),
                                                        (((&__0__V121)->__O1__2ea.p = __2__X127),
                                                         (&__0__V121))),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            } else if (strcmp(curr_fct->__O2__4expr.string, (const char *)"main")) {

                                struct fct *__0__X128;

                                const void *__2__X129;

                                const void *__2__X130;

                                const void *__2__X131;

                                if (((__0__X128 = (((struct fct *)((
                                          (struct fct *)curr_fct->__O1__4expr.tp))))),
                                     ((__0__X128->fct_base__3fct != 0))) &&
                                    ((((struct fct *)(((struct fct *)curr_fct->__O1__4expr.tp))))
                                         ->returns__3fct == (((struct type *)defa_type)))) {
                                    struct ea __0__V122;

                                    error__FPCcRC2eaN32(
                                        (const char *)"no value returned from%n",
                                        (const struct ea *)((__2__X129 = (const void *)curr_fct),
                                                            (((&__0__V122)->__O1__2ea.p =
                                                                  __2__X129),
                                                             (&__0__V122))),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                } else if (((((((struct fct *)((
                                                   (struct fct *)curr_fct->__O1__4expr.tp))))
                                                  ->returns__3fct ==
                                              (((struct type *)defa_type))) &&
                                             (!(((struct fct *)((
                                                    (struct fct *)curr_fct->__O1__4expr.tp))))
                                                   ->memof__3fct)) &&
                                            (!curr_fct->n_oper__4name)) &&
                                           (simpl_friend == 0)) {
                                    struct ea __0__V123;

                                    error__FiPCcRC2eaN33(
                                        strict_opt ? 0 : 119,
                                        (const char *)"no value returned from%n (anachronism)",
                                        (const struct ea *)((__2__X130 = (const void *)curr_fct),
                                                            (((&__0__V123)->__O1__2ea.p =
                                                                  __2__X130),
                                                             (&__0__V123))),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                } else {
                                    struct ea __0__V124;

                                    error__FPCcRC2eaN32(
                                        (const char *)"no value returned from%n",
                                        (const struct ea *)((__2__X131 = (const void *)curr_fct),
                                                            (((&__0__V124)->__O1__2ea.p =
                                                                  __2__X131),
                                                             (&__0__V124))),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                            }
                            if ((warning_opt && (strcmp(curr_fct->__O2__4expr.string,
                                                        (const char *)"main") == 0)) &&
                                (skiptypedefs__4typeFv(
                                     (((struct fct *)(((struct fct *)curr_fct->__O1__4expr.tp))))
                                         ->returns__3fct) != (((struct type *)void_type))))
                                error__FiPCc((int)'w',
                                             (const char *)"no value returned from main()");
                        }
                        if (del_list)
                            goto zaq;
                    } else if (del_list) {
                    zaq:
                        if (__1tail)
                            __1tail->s_list__4stmt = del_list;
                        else
                            __0this->body__3fct->s__4stmt = del_list;
                        __1tail = __1dtail;
                    }

                    if (curr_fct->n_oper__4name == 162) {
                        {
                            {
                                Pvirt __2blist;

                                register struct ifstmt *__0__X140;

                                struct loc __2__X141;

                                struct stmt *__2__X142;

                                struct stmt *__2__X143;

                                __2blist = __1cl->virt_list__8classdef;

                                for (; __2blist; __2blist = __2blist->next__4virt) {
                                    topclass = __1cl;
                                    {
                                        Pexpr __3vp;

                                        char *__3str;
                                        const char *__3cs;

                                        __3vp = get_vptr_exp__8classdefFPCc(
                                            __1cl, __2blist->string__4virt);

                                        __3str = 0;
                                        __3cs = (__1cl->nested_sig__4type
                                                     ? (((const char *)__1cl->nested_sig__4type))
                                                     : __1cl->string__8classdef);
                                        if (__1cl->lex_level__4type &&
                                            (__1cl->nested_sig__4type == 0)) {
                                            __3str = (((char *)__nw__FUl(
                                                (size_t)((sizeof(char)) *
                                                         (__1cl->c_strlen__8classdef + 1)))));
                                            strcpy(__3str, (const char *)__1cl->local_sig__4type);
                                        }
                                        {
                                            Pexpr __3vtbl;

                                            Pexpr __3ee;

                                            register struct text_expr *__0__X134;

                                            const char *__2__X135;

                                            const char *__2__X136;

                                            struct ref *__0__X137;

                                            struct expr *__2__X138;

                                            struct expr *__2__X139;

                                            __3vtbl =
                                                (struct expr
                                                     *)((__0__X134 = 0),
                                                        ((__2__X135 = __2blist->string__4virt),
                                                         ((__2__X136 =
                                                               (__3str ? (((const char *)__3str))
                                                                       : __3cs)),
                                                          (((__0__X134 ||
                                                             (__0__X134 = (struct text_expr *)
                                                                  __nw__4exprSFUl((size_t)(sizeof(
                                                                      struct text_expr)))))
                                                                ? ((__0__X134 = (struct text_expr *)
                                                                        __ct__4exprFUcP4exprT2(
                                                                            ((struct expr *)
                                                                                 __0__X134),
                                                                            (unsigned char)165,
                                                                            (struct expr *)0,
                                                                            (struct expr *)0)),
                                                                   ((__0__X134->__O2__4expr.string =
                                                                         __2__X135),
                                                                    (__0__X134->__O3__4expr
                                                                         .string2 = __2__X136)))
                                                                : 0),
                                                           __0__X134))));

                                            __3ee =
                                                (struct expr
                                                     *)((__0__X137 = 0),
                                                        ((__2__X138 = __1th),
                                                         ((__2__X139 = __3vp),
                                                          (((__0__X137 ||
                                                             (__0__X137 =
                                                                  (struct ref *)__nw__4exprSFUl((
                                                                      size_t)(sizeof(struct ref)))))
                                                                ? ((__0__X137 = (struct ref *)
                                                                        __ct__4exprFUcP4exprT2(
                                                                            ((struct expr *)
                                                                                 __0__X137),
                                                                            ((unsigned char)44),
                                                                            __2__X138,
                                                                            (struct expr *)0)),
                                                                   (__0__X137->__O4__4expr.mem =
                                                                        __2__X139))
                                                                : 0),
                                                           __0__X137))));

                                            __3ee->__O1__4expr.tp = __3vp->__O1__4expr.tp;
                                            __3ee = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                           (unsigned char)70, __3ee,
                                                                           __3vtbl);
                                            {
                                                Pstmt __3es;

                                                struct estmt *__0__X132;

                                                struct loc __2__X133;

                                                __3es =
                                                    (struct stmt
                                                         *)((__0__X132 = 0),
                                                            ((__2__X133 = curloc),
                                                             (((__0__X132 ||
                                                                (__0__X132 = (struct estmt *)
                                                                     __nw__4stmtSFUl(
                                                                         (unsigned long)(sizeof(
                                                                             struct estmt)))))
                                                                   ? ((__0__X132 = (struct estmt *)
                                                                           __ct__4stmtFUc3locP4stmt(
                                                                               ((struct stmt *)
                                                                                    __0__X132),
                                                                               ((unsigned char)72),
                                                                               __2__X133,
                                                                               ((struct stmt *)0))),
                                                                      (__0__X132->__O2__4stmt.e =
                                                                           __3ee))
                                                                   : 0),
                                                              __0__X132)));
                                                __3es->s_list__4stmt =
                                                    __0this->body__3fct->s__4stmt;
                                                __0this->body__3fct->s__4stmt = __3es;
                                            }
                                        }
                                    }
                                }

                                __0this->body__3fct->s__4stmt =
                                    (struct stmt
                                         *)((__0__X140 = 0),
                                            ((__2__X141 = __0this->body__3fct->where__4stmt),
                                             ((__2__X142 = __0this->body__3fct->s__4stmt),
                                              ((__2__X143 = 0),
                                               (((__0__X140 ||
                                                  (__0__X140 = (struct ifstmt *)__nw__4stmtSFUl(
                                                       (size_t)(sizeof(struct ifstmt)))))
                                                     ? ((__0__X140 = (struct ifstmt *)
                                                             __ct__4stmtFUc3locP4stmt(
                                                                 ((struct stmt *)__0__X140),
                                                                 (unsigned char)20, __2__X141,
                                                                 __2__X142)),
                                                        ((__0__X140->__O2__4stmt.e = __1th),
                                                         (__0__X140->__O3__4stmt.else_stmt =
                                                              __2__X143)))
                                                     : 0),
                                                __0__X140)))));
                            }
                        }
                    }

                    if (curr_fct->n_oper__4name == 161) {
                        struct loc __2temploc;
                        Pstmt __2tempss;

                        __2temploc = __0this->body__3fct->where__4stmt;
                        __2tempss = __0this->body__3fct->s__4stmt;
                        while (__2tempss) {
                            __2temploc = __2tempss->where__4stmt;
                            __2tempss = __2tempss->s_list__4stmt;
                        }

                        if ((((struct name *)(((struct name *)__1th))))->n_assigned_to__4name ==
                            0) {
                            (((struct name *)(((struct name *)__1th))))->n_assigned_to__4name =
                                (__1ass_count ? __1ass_count : 11111);
                            {
                                Pexpr __3sz;

                                struct texpr *__0__X160;

                                __3sz =
                                    (struct expr *)((__0__X160 = 0),
                                                    (((__0__X160 ||
                                                       (__0__X160 = (struct texpr *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct texpr)))))
                                                          ? ((__0__X160 = (struct texpr *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X160),
                                                                      ((unsigned char)30),
                                                                      ((struct expr *)0),
                                                                      (struct expr *)0)),
                                                             (__0__X160->__O4__4expr.tp2 =
                                                                  ((struct type *)__1cl)))
                                                          : 0),
                                                     __0__X160));
                                ((void)tsizeof__4typeFi((struct type *)__1cl, 0));
                                __3sz->__O1__4expr.tp = (struct type *)uint_type;
                                {
                                    Pexpr __3ee;
                                    Pname __3n;
                                    Pexpr __3p;

                                    struct estmt *__0__X150;

                                    struct loc __2__X151;

                                    if (!perf_opt) {
                                        struct call *__0__X144;

                                        struct expr *__2__X145;

                                        struct expr *__2__X146;

                                        __3ee = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                       (unsigned char)140, __3sz,
                                                                       (struct expr *)0);
                                        __3n = __ct__4nameFPCc((struct name *)0,
                                                               oper_name__FUc((unsigned char)23));
                                        __3p = find_name__FP4nameP8classdefP5tableiT1(
                                            __3n, __1cl, scope, 109, curr_fct);

                                        __3ee =
                                            (struct expr
                                                 *)((__0__X144 = 0),
                                                    ((__2__X145 = __3p),
                                                     ((__2__X146 = __3ee),
                                                      (((__0__X144 ||
                                                         (__0__X144 =
                                                              (struct call *)__nw__4exprSFUl(
                                                                  (size_t)(sizeof(struct call)))))
                                                            ? (__0__X144 = (struct call *)
                                                                   __ct__4exprFUcP4exprT2(
                                                                       ((struct expr *)__0__X144),
                                                                       (unsigned char)109,
                                                                       __2__X145, __2__X146))
                                                            : 0),
                                                       __0__X144))));
                                        ((void)call_fct__4exprFP5table(__3ee,
                                                                       __1cl->memtbl__8classdef));
                                        simpl__4exprFv(__3ee);
                                        __3ee = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)70, __1th, __3ee);
                                        __3ee = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)67, __1th, __3ee);
                                    }

                                    if (init_list) {
                                        Pstmt __4es;

                                        struct estmt *__0__X147;

                                        struct loc __2__X148;

                                        struct expr *__2__X149;

                                        __4es =
                                            (struct stmt
                                                 *)((__0__X147 = 0),
                                                    ((__2__X148 =
                                                          __0this->body__3fct->where__4stmt),
                                                     ((__2__X149 = init_list),
                                                      (((__0__X147 ||
                                                         (__0__X147 =
                                                              (struct estmt *)__nw__4stmtSFUl(
                                                                  (size_t)(sizeof(struct estmt)))))
                                                            ? ((__0__X147 = (struct estmt *)
                                                                    __ct__4stmtFUc3locP4stmt(
                                                                        ((struct stmt *)__0__X147),
                                                                        ((unsigned char)72),
                                                                        __2__X148,
                                                                        ((struct stmt *)0))),
                                                               (__0__X147->__O2__4stmt.e =
                                                                    __2__X149))
                                                            : 0),
                                                       __0__X147))));
                                        __4es->s_list__4stmt = __0this->body__3fct->s__4stmt;
                                        __0this->body__3fct->s__4stmt = __4es;

                                    } else if (__0this->body__3fct->s__4stmt == 0)
                                        __0this->body__3fct->s__4stmt =
                                            (struct stmt
                                                 *)((__0__X150 = 0),
                                                    ((__2__X151 =
                                                          __0this->body__3fct->where__4stmt),
                                                     (((__0__X150 ||
                                                        (__0__X150 =
                                                             (struct estmt *)__nw__4stmtSFUl(
                                                                 (size_t)(sizeof(struct estmt)))))
                                                           ? ((__0__X150 = (struct estmt *)
                                                                   __ct__4stmtFUc3locP4stmt(
                                                                       ((struct stmt *)__0__X150),
                                                                       ((unsigned char)72),
                                                                       __2__X151,
                                                                       ((struct stmt *)0))),
                                                              (__0__X150->__O2__4stmt.e =
                                                                   ((struct expr *)0)))
                                                           : 0),
                                                      __0__X150)));
                                    else if (__1tail->base__4node == 28) {
                                        if (__0this->body__3fct->s__4stmt == __1tail) {
                                            struct stmt *__0__X152;

                                            struct estmt *__0__X153;

                                            struct loc __2__X154;

                                            ((__0__X152 = __0this->body__3fct->s__4stmt),
                                             ((__0__X152
                                                   ? (((void)(__0__X152
                                                                  ? (((void)((
                                                                        (void)__dl__4stmtSFPvUl(
                                                                            (void *)__0__X152,
                                                                            (unsigned long)(sizeof(
                                                                                struct stmt)))))))
                                                                  : (((void)0)))))
                                                   : (((void)0)))));
                                            __0this->body__3fct->s__4stmt =
                                                (struct stmt
                                                     *)((__0__X153 = 0),
                                                        ((__2__X154 =
                                                              __0this->body__3fct->where__4stmt),
                                                         (((__0__X153 ||
                                                            (__0__X153 = (struct estmt *)
                                                                 __nw__4stmtSFUl((size_t)(sizeof(
                                                                     struct estmt)))))
                                                               ? ((__0__X153 = (struct estmt *)
                                                                       __ct__4stmtFUc3locP4stmt(
                                                                           ((struct stmt *)
                                                                                __0__X153),
                                                                           ((unsigned char)72),
                                                                           __2__X154,
                                                                           ((struct stmt *)0))),
                                                                  (__0__X153->__O2__4stmt.e =
                                                                       ((struct expr *)0)))
                                                               : 0),
                                                          __0__X153)));
                                        } else {
                                            Pstmt __5pr;

                                            struct stmt *__0__X155;

                                            __5pr = __0this->body__3fct->s__4stmt;
                                            while (__5pr->s_list__4stmt != __1tail)
                                                __5pr = __5pr->s_list__4stmt;
                                            ((__0__X155 = __5pr->s_list__4stmt),
                                             ((__0__X155
                                                   ? (((void)(__0__X155
                                                                  ? (((void)((
                                                                        (void)__dl__4stmtSFPvUl(
                                                                            (void *)__0__X155,
                                                                            (unsigned long)(sizeof(
                                                                                struct stmt)))))))
                                                                  : (((void)0)))))
                                                   : (((void)0)))));
                                            __5pr->s_list__4stmt = 0;
                                        }
                                    }

                                    if (perf_opt) {
                                        if (__1tail == 0)
                                            __1tail = __0this->body__3fct->s__4stmt;
                                    } else {
                                        struct ifstmt *__4ifs;

                                        register struct ifstmt *__0__X156;

                                        struct loc __2__X157;

                                        struct stmt *__2__X158;

                                        struct stmt *__2__X159;

                                        __4ifs =
                                            ((__0__X156 = 0),
                                             ((__2__X157 = __0this->body__3fct->where__4stmt),
                                              ((__2__X158 = __0this->body__3fct->s__4stmt),
                                               ((__2__X159 = 0),
                                                (((__0__X156 ||
                                                   (__0__X156 = (struct ifstmt *)__nw__4stmtSFUl(
                                                        (size_t)(sizeof(struct ifstmt)))))
                                                      ? ((__0__X156 = (struct ifstmt *)
                                                              __ct__4stmtFUc3locP4stmt(
                                                                  ((struct stmt *)__0__X156),
                                                                  (unsigned char)20, __2__X157,
                                                                  __2__X158)),
                                                         ((__0__X156->__O2__4stmt.e = __3ee),
                                                          (__0__X156->__O3__4stmt.else_stmt =
                                                               __2__X159)))
                                                      : 0),
                                                 __0__X156)))));
                                        __0this->body__3fct->s__4stmt = (struct stmt *)__4ifs;

                                        __1tail = (struct stmt *)__4ifs;
                                    }
                                }
                            }
                        }

                        {
                            Pstmt __2st;

                            struct estmt *__0__X161;

                            __2st =
                                (struct stmt *)((__0__X161 = 0),
                                                (((__0__X161 ||
                                                   (__0__X161 = (struct estmt *)__nw__4stmtSFUl(
                                                        (size_t)(sizeof(struct estmt)))))
                                                      ? ((__0__X161 = (struct estmt *)
                                                              __ct__4stmtFUc3locP4stmt(
                                                                  ((struct stmt *)__0__X161),
                                                                  ((unsigned char)28), __2temploc,
                                                                  ((struct stmt *)0))),
                                                         (__0__X161->__O2__4stmt.e = __1th))
                                                      : 0),
                                                 __0__X161));
                            if (__1tail)
                                __1tail->s_list__4stmt = __2st;
                            else
                                __0this->body__3fct->s__4stmt = __2st;
                            __1tail = __2st;
                        }
                    }
                    __0this->f_imeasure__3fct = imeasure;
                    curr_fct = __1ocurr_fct;
                    no_of_returns = __1oret;
                    imeasure = __1oim;
                    (((cc--), (((void)0))));
                }
            }
        }
    }
}

void simpl__8classdefFv(register struct classdef *__0this) {
    int __1i;

    struct dcl_context *__0__X164;

    if (__0this->defined__4type & 02)
        return;
    if ((__0this->defined__4type & 01) == 0)
        return;

    ((((cc++),
       (((cc >= ccvec_end) ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow") : 0),
        (((*cc)) = (*(cc - 1))))),
      (((void)0))));
    cc->cot__11dcl_context = __0this;
    cc->tot__11dcl_context = __0this->this_type__8classdef;
    cc->not4__11dcl_context = __0this->memtbl__8classdef->t_name__5table;

    __1i = 1;
    {
        Pname __1m;

        struct table *__0__X165;

        int __2__X166;

        struct table *__0__X168;

        __1m = ((__0__X168 = __0this->memtbl__8classdef),
                ((((__1i <= 0) || (__0__X168->free_slot__5table <= __1i))
                      ? (((struct name *)0))
                      : (__0__X168->entries__5table[__1i]))));
        for (; __1m;
             __1m = (__1m->n_tbl_list__4name
                         ? __1m->n_tbl_list__4name
                         : ((__0__X165 = __0this->memtbl__8classdef),
                            ((__2__X166 = (++__1i)),
                             ((((__2__X166 <= 0) || (__0__X165->free_slot__5table <= __2__X166))
                                   ? (((struct name *)0))
                                   : (__0__X165->entries__5table[__2__X166]))))))) {
            if (__1m->base__4node == 123)
                continue;

            if ((__0this->c_ctor__8classdef) &&
                (strcmp(__1m->__O2__4expr.string, __0this->string__8classdef) == 0)) {
                struct ea __0__V163;

                error__FP3locPCcRC2eaN33(
                    &__1m->where__4name, (const char *)"nonFM%n inCWK",
                    (const struct ea *)(((&__0__V163)->__O1__2ea.p = ((const void *)__1m)),
                                        (&__0__V163)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            {
                Pexpr __2i;

                __2i = __1m->__O3__4expr.n_initializer;
                __1m->__O3__4expr.n_initializer = 0;
                simpl__4nameFv(__1m);
                __1m->__O3__4expr.n_initializer = __2i;
            }
        }

        {
            {
                Plist __1fl;

                struct dcl_context *__0__X167;

                __1fl = __0this->friend_list__8classdef;

                for (; __1fl; __1fl = __1fl->l__9name_list) {
                    Pname __2p;

                    __2p = __1fl->f__9name_list;
                    switch (__2p->__O1__4expr.tp->base__4node) {
                    case 108:
                    case 76:
                        simpl__4nameFv(__2p);
                    }
                }

                __0this->defined__4type |= 02;
                (((cc--), (((void)0))));
            }
        }
    }
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
