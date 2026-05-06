
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

extern Plist inllist;

extern int no_of_returns;

extern Pname new_fct;

extern Pstmt del_list;
extern Pstmt break_del_list;
extern Pstmt continue_del_list;

extern Pname curr_fct;
extern Pexpr init_list;
extern int imeasure;

bit tconst__4typeFv(struct type *__0this);

struct basetype *__ct__8basetypeFUcP4name(struct basetype *__0this, TOK, Pname);

Ptype unconst_type__FP4type(Ptype __1tp) {
    if (((!ansi_opt) || (!__1tp)) || (!tconst__4typeFv(__1tp)))
        return __1tp;

    {
        Ptype __1curr;

        Ptype __1t;

        __1t = skiptypedefs__4typeFv(__1tp);

        switch (__1t->base__4node) {
        case 110:
        case 108:
        case 76:
            return __1tp;
        case 125:
        case 158:
            __1curr = (struct type *)__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)0,
                                                         (struct type *)0);
            ((*(((struct ptr *)(((struct ptr *)__1curr)))))) =
                (*(((struct ptr *)(((struct ptr *)__1t)))));
            break;
        default:
            __1curr = (struct type *)__ct__8basetypeFUcP4name((struct basetype *)0,
                                                              (unsigned char)0, (struct name *)0);
            ((*(((struct basetype *)(((struct basetype *)__1curr)))))) =
                (*(((struct basetype *)(((struct basetype *)__1t)))));
            break;
        }

        __1curr->ansi_const__4type = 1;
        return __1curr;
    }
}

extern int strcmp(const char *, const char *);

bit return_nrv__FP4expr(Pexpr __1e) {
    if (((__1e->base__4node == 111) && (__1e->__O2__4expr.e1->base__4node == 85)) &&
        (strcmp((((struct name *)(((struct name *)__1e->__O2__4expr.e1))))->__O2__4expr.string,
                (const char *)"_result") == 0))
        return (unsigned char)1;

    return (unsigned char)0;
}

int tsizeof__4typeFi(struct type *__0this, int);

int lval__4exprFUc(struct expr *__0this, TOK);

Pexpr cdvec__FP4nameP4exprP8classdefT1iN22(Pname __1f, Pexpr __1vec, Pclass __1cl, Pname __1cd,
                                           int __1tail, Pexpr __1i, Pexpr __1vec2) {
    Pexpr __1sz;

    struct texpr *__0__X29;

    __1sz = (struct expr *)((__0__X29 = 0),
                            (((__0__X29 || (__0__X29 = (struct texpr *)__nw__4exprSFUl(
                                                (size_t)(sizeof(struct texpr)))))
                                  ? ((__0__X29 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                          ((struct expr *)__0__X29), ((unsigned char)30),
                                          ((struct expr *)0), (struct expr *)0)),
                                     (__0__X29->__O4__4expr.tp2 = ((struct type *)__1cl)))
                                  : 0),
                             __0__X29));
    __1sz->__O1__4expr.tp = (struct type *)uint_type;
    ((void)tsizeof__4typeFi((struct type *)__1cl, 0));

    {
        Pexpr __1esz;

        Pexpr __1noe;

        struct texpr *__0__X17;

        struct type *__2__X18;

        struct texpr *__0__X19;

        struct type *__2__X20;

        struct texpr *__0__X28;

        __1esz = (struct expr *)((__0__X28 = 0),
                                 (((__0__X28 || (__0__X28 = (struct texpr *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct texpr)))))
                                       ? ((__0__X28 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X28), ((unsigned char)30),
                                               ((struct expr *)0), (struct expr *)0)),
                                          (__0__X28->__O4__4expr.tp2 = ((struct type *)__1cl)))
                                       : 0),
                                  __0__X28));
        __1esz->__O1__4expr.tp = (struct type *)int_type;

        ;
        if (__1vec2)
            __1noe = (struct expr *)((__0__X17 = 0),
                                     ((__2__X18 = __1vec2->__O1__4expr.tp),
                                      (((__0__X17 || (__0__X17 = (struct texpr *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct texpr)))))
                                            ? ((__0__X17 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X17), ((unsigned char)30),
                                                    ((struct expr *)0), (struct expr *)0)),
                                               (__0__X17->__O4__4expr.tp2 = __2__X18))
                                            : 0),
                                       __0__X17)));
        else
            __1noe = (struct expr *)((__0__X19 = 0),
                                     ((__2__X20 = __1vec->__O1__4expr.tp),
                                      (((__0__X19 || (__0__X19 = (struct texpr *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct texpr)))))
                                            ? ((__0__X19 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X19), ((unsigned char)30),
                                                    ((struct expr *)0), (struct expr *)0)),
                                               (__0__X19->__O4__4expr.tp2 = __2__X20))
                                            : 0),
                                       __0__X19)));

        __1noe->__O1__4expr.tp = (struct type *)int_type;
        __1noe = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)51, __1noe, __1esz);
        __1noe->__O1__4expr.tp = (struct type *)uint_type;

        {
            Pexpr __1arg;

            struct texpr *__0__X21;

            struct type *__2__X22;

            struct texpr *__0__X23;

            struct type *__2__X24;

            struct call *__0__X25;

            struct expr *__2__X26;

            struct expr *__2__X27;

            __1arg = (__1i ? __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __1i,
                                                    (struct expr *)0)
                           : (((struct expr *)0)));
            __1arg = ((0 <= __1tail) ? __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                              zero, __1arg)
                                     : __1arg);
            __1arg = __ct__4exprFUcP4exprT2(
                (struct expr *)0, (unsigned char)140,
                (struct expr *)((__0__X21 = 0),
                                ((__2__X22 = Pvoid_type),
                                 (((__0__X21 || (__0__X21 = (struct texpr *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct texpr)))))
                                       ? ((__0__X21 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X21), ((unsigned char)191),
                                               ((struct expr *)__1cd), (struct expr *)0)),
                                          (__0__X21->__O4__4expr.tp2 = __2__X22))
                                       : 0),
                                  __0__X21))),
                __1arg);
            lval__4exprFUc((struct expr *)__1cd, (unsigned char)112);

            __1arg = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __1sz, __1arg);
            __1arg = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __1noe, __1arg);
            __1arg = __ct__4exprFUcP4exprT2(
                (struct expr *)0, (unsigned char)140,
                (struct expr *)((__0__X23 = 0),
                                ((__2__X24 = Pvoid_type),
                                 (((__0__X23 || (__0__X23 = (struct texpr *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct texpr)))))
                                       ? ((__0__X23 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X23), ((unsigned char)191),
                                               __1vec, (struct expr *)0)),
                                          (__0__X23->__O4__4expr.tp2 = __2__X24))
                                       : 0),
                                  __0__X23))),
                __1arg);

            __1arg = (struct expr *)((__0__X25 = 0),
                                     ((__2__X26 = (struct expr *)__1f),
                                      ((__2__X27 = __1arg),
                                       (((__0__X25 || (__0__X25 = (struct call *)__nw__4exprSFUl(
                                                           (size_t)(sizeof(struct call)))))
                                             ? (__0__X25 = (struct call *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X25), (unsigned char)109,
                                                    __2__X26, __2__X27))
                                             : 0),
                                        __0__X25))));
            __1arg->base__4node = 146;
            __1arg->__O4__4expr.fct_name = __1f;

            return __1arg;
        }
    }
}

Pstmt trim_tail__FP4stmt(Pstmt __1tt);

Pstmt trim_tail__FP4stmt(Pstmt __1tt) {
    if (__1tt == 0)
        return (struct stmt *)0;

    while (__1tt->s_list__4stmt) {
        Pstmt __2tpx;
        switch (__1tt->base__4node) {
        case 166:
            __2tpx = trim_tail__FP4stmt(__1tt->__O2__4stmt.s2);
            goto tpxl;
        case 116:
            __2tpx = trim_tail__FP4stmt(__1tt->s__4stmt);
        tpxl:
            if (__2tpx == 0)
                return (struct stmt *)0;

            switch (__2tpx->base__4node) {
            case 72:
                break;
            case 7:
            case 3:
            case 19:
            case 28:
                if (__1tt->s_list__4stmt->base__4node != 115)
                    __1tt->s_list__4stmt = 0;
            default:
                return __2tpx;
            }
        default:
            if (__1tt = __1tt->s_list__4stmt)
                break;
            return (struct stmt *)0;
        case 28:
            if (__1tt->s_list__4stmt->base__4node != 115)
                __1tt->s_list__4stmt = 0;
            return __1tt;
        }
    }

    switch (__1tt->base__4node) {
    case 166:
        return trim_tail__FP4stmt(__1tt->__O2__4stmt.s2);

    case 116:
        if (__1tt->s__4stmt)
            return trim_tail__FP4stmt(__1tt->s__4stmt);
    default:
        return __1tt;
    }
}

extern Ptype Pfct_type;

Pexpr mptr_assign__FP4exprT1(Pexpr __1n, Pexpr __1in) {
    Pexpr __1i1;
    Pexpr __1i2;
    Pexpr __1i3;

    if (__1n->base__4node == 85)
        (((((struct name *)(((struct name *)__1n))))->n_used__4name++), (((void)0)));

    if (__1in->base__4node == 85) {
        register struct mdot *__0__X30;

        register struct mdot *__0__X31;

        register struct mdot *__0__X32;

        __1i1 = (struct expr *)((__0__X30 = 0),
                                (((__0__X30 || (__0__X30 = (struct mdot *)__nw__4exprSFUl(
                                                    (size_t)(sizeof(struct mdot)))))
                                      ? ((__0__X30 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X30), (unsigned char)177,
                                              (struct expr *)0, (struct expr *)0)),
                                         ((__0__X30->__O3__4expr.string2 = ((const char *)"d")),
                                          (__0__X30->__O4__4expr.mem = __1in)))
                                      : 0),
                                 __0__X30));
        __1i1->__O2__4expr.i1 = 9;
        __1i2 = (struct expr *)((__0__X31 = 0),
                                (((__0__X31 || (__0__X31 = (struct mdot *)__nw__4exprSFUl(
                                                    (size_t)(sizeof(struct mdot)))))
                                      ? ((__0__X31 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X31), (unsigned char)177,
                                              (struct expr *)0, (struct expr *)0)),
                                         ((__0__X31->__O3__4expr.string2 = ((const char *)"i")),
                                          (__0__X31->__O4__4expr.mem = __1in)))
                                      : 0),
                                 __0__X31));
        __1i2->__O2__4expr.i1 = 9;
        __1i3 = (struct expr *)((__0__X32 = 0),
                                (((__0__X32 || (__0__X32 = (struct mdot *)__nw__4exprSFUl(
                                                    (size_t)(sizeof(struct mdot)))))
                                      ? ((__0__X32 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X32), (unsigned char)177,
                                              (struct expr *)0, (struct expr *)0)),
                                         ((__0__X32->__O3__4expr.string2 = ((const char *)"f")),
                                          (__0__X32->__O4__4expr.mem = __1in)))
                                      : 0),
                                 __0__X32));
        __1i3->__O2__4expr.i1 = 9;
    } else if (__1in->base__4node == 86) {
        __1i1 = zero;
        __1i2 = zero;
        __1i3 = zero;
    } else {
        __1i1 =
            (__1in->__O2__4expr.e1->__O2__4expr.e1 ? __1in->__O2__4expr.e1->__O2__4expr.e1 : zero);
        __1i2 =
            (__1in->__O2__4expr.e1->__O3__4expr.e2 ? __1in->__O2__4expr.e1->__O3__4expr.e2 : zero);
        __1i3 = (__1in->__O3__4expr.e2 ? __1in->__O3__4expr.e2 : zero);
    }
    {
        Pexpr __1nd;

        register struct mdot *__0__X35;

        __1nd = (struct expr *)((__0__X35 = 0),
                                (((__0__X35 || (__0__X35 = (struct mdot *)__nw__4exprSFUl(
                                                    (size_t)(sizeof(struct mdot)))))
                                      ? ((__0__X35 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X35), (unsigned char)177,
                                              (struct expr *)0, (struct expr *)0)),
                                         ((__0__X35->__O3__4expr.string2 = ((const char *)"d")),
                                          (__0__X35->__O4__4expr.mem = __1n)))
                                      : 0),
                                 __0__X35));
        __1nd->__O2__4expr.i1 = 9;
        {
            Pexpr __1e1;

            Pexpr __1ni;

            register struct mdot *__0__X34;

            __1e1 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70, __1nd, __1i1);

            __1ni = (struct expr *)((__0__X34 = 0),
                                    (((__0__X34 || (__0__X34 = (struct mdot *)__nw__4exprSFUl(
                                                        (size_t)(sizeof(struct mdot)))))
                                          ? ((__0__X34 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X34), (unsigned char)177,
                                                  (struct expr *)0, (struct expr *)0)),
                                             ((__0__X34->__O3__4expr.string2 = ((const char *)"i")),
                                              (__0__X34->__O4__4expr.mem = __1n)))
                                          : 0),
                                     __0__X34));
            __1ni->__O2__4expr.i1 = 9;
            {
                Pexpr __1e2;

                Pexpr __1nf;

                register struct mdot *__0__X33;

                __1e2 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70, __1ni, __1i2);

                __1nf =
                    (struct expr *)((__0__X33 = 0),
                                    (((__0__X33 || (__0__X33 = (struct mdot *)__nw__4exprSFUl(
                                                        (size_t)(sizeof(struct mdot)))))
                                          ? ((__0__X33 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X33), (unsigned char)177,
                                                  (struct expr *)0, (struct expr *)0)),
                                             ((__0__X33->__O3__4expr.string2 = ((const char *)"f")),
                                              (__0__X33->__O4__4expr.mem = __1n)))
                                          : 0),
                                     __0__X33));
                __1nf->__O2__4expr.i1 = 9;
                {
                    Pexpr __1e3;

                    Pexpr __1ee;

                    __1e3 =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70, __1nf, __1i3);

                    __1ee =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, __1e2, __1e3);
                    return __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, __1e1,
                                                  __1ee);
                }
            }
        }
    }
}

Ptable tmp_tbl = 0;
static Pname tmp_list;
static Ptable Ntmp_tbl;
static Pstmt tmp_dtor;
bit need_lift = 0;
Pexpr Ntmp_dtor = 0;

static bit need_lift_dtors__FP4expr(Pexpr __1e) {
    Pexpr __1ee;

    Pexpr __1ex;

    for (__1ex = Ntmp_dtor; __1ex; __1ex = __1ex->__O3__4expr.e2) {
        __1ee = __1ex->__O2__4expr.e1;
        if (__1ee == __1e)
            break;
    }
    if (!__1ex)
        return (unsigned char)0;
    return (unsigned char)1;
}

Pname is_cl_obj__4typeFv(struct type *__0this);

extern Pexpr call_dtor__FP4exprN21iT1(Pexpr __0p, Pexpr __0dtor, Pexpr __0arg, int __0d,
                                      Pexpr __0vb_args);

void simpl__4exprFv(struct expr *__0this);

static Pexpr make_dtor_expr__FP4name(Pname __1nl) {
    Pexpr __1dl;
    Pname __1n;

    __1dl = 0;

    for (__1n = __1nl; __1n; __1n = __1n->__O1__4name.n_list) {
        register struct table *__0__X36;

        struct name *__1__Xnn00aqkw3vgovcnm;

        ((__0__X36 = tmp_tbl),
         ((__1__Xnn00aqkw3vgovcnm = __ct__4nameFPCc((struct name *)0, (const char *)0)),
          ((((*__1__Xnn00aqkw3vgovcnm)) = (*__1n)),
           ((__1__Xnn00aqkw3vgovcnm->__O4__4expr.n_table = 0),
            ((__1__Xnn00aqkw3vgovcnm->n_tbl_list__4name = 0),
             insert__5tableFP4nameUc(__0__X36, __1__Xnn00aqkw3vgovcnm, ((unsigned char)0)))))));
        {
            Pname __2cln;
            Pname __2d;
            Pexpr __2e;

            struct classdef *__0__X37;

            __2cln = is_cl_obj__4typeFv(__1n->__O1__4expr.tp);
            __2d =
                ((__0__X37 = (((struct classdef *)(((struct classdef *)__2cln->__O1__4expr.tp))))),
                 (__0__X37->c_dtor__8classdef));
            __2e = call_dtor__FP4exprN21iT1((struct expr *)__1n, (struct expr *)__2d,
                                            (struct expr *)0, 45, one);
            if (__1dl == 0)
                __1dl = __2e;
            else {
                __1dl = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, __1dl, __2e);
                __1dl->__O1__4expr.tp = __2e->__O1__4expr.tp;
            }
        }
    }
    if (__1dl)
        simpl__4exprFv(__1dl);
    return __1dl;
}

static int prune;

static void find_temps_in_expr__FP4exprPCc(Pexpr __1e, const char *__1s);

extern int is_probably_temp__FPCc(const char *);

static void find_temps_in_expr__FP4exprPCc(Pexpr __1e, const char *__1s) {
    if (__1e == 0)
        return;

    switch (__1e->base__4node) {
    case 66:
    case 67:
    case 68:
        if (prune)
            return;
        if (__1s && tmp_list)
            return;
        find_temps_in_expr__FP4exprPCc(__1e->__O4__4expr.cond, __1s);
    default:
        if (__1s && tmp_list)
            return;
        find_temps_in_expr__FP4exprPCc(__1e->__O2__4expr.e1, __1s);
        if (__1s && tmp_list)
            return;
        find_temps_in_expr__FP4exprPCc(__1e->__O3__4expr.e2, __1s);
        return;
    case 44:
    case 45:
        if (__1s && tmp_list)
            return;
        find_temps_in_expr__FP4exprPCc(__1e->__O2__4expr.e1, __1s);
    case 177:
    case 30:
    case 86:
    case 123:
    case 81:
    case 82:
    case 80:
    case 83:
    case 84:
    case 150:
    case 116:
    case 169:
    case 165:
        return;
    case 85: {
        Pname __3n;
        Pname __3cln;

        struct classdef *__0__X38;

        __3n = (((struct name *)(((struct name *)__1e))));
        __3cln = is_cl_obj__4typeFv(__3n->__O1__4expr.tp);
        if ((__3cln &&
             ((__0__X38 = (((struct classdef *)(((struct classdef *)__3cln->__O1__4expr.tp))))),
              (__0__X38->c_dtor__8classdef))) &&
            is_probably_temp__FPCc(__3n->__O2__4expr.string)) {
            if (__1s) {
                if (strcmp(__1s, __3n->__O2__4expr.string) == 0)
                    tmp_list = __3n;
                return;
            }

            if (tmp_list == 0)
                tmp_list = __3n;
            else {
                Pname __5nn;

                __5nn = tmp_list;
                if (__3n == __5nn)
                    return;
                while (__5nn->__O1__4name.n_list) {
                    __5nn = __5nn->__O1__4name.n_list;
                    if (__3n == __5nn)
                        return;
                }
                __5nn->__O1__4name.n_list = __3n;
            }
        }
        return;
    }
    }
}

static bit find_in_Ntmp__FPCc(const char *__1s) {
    Pexpr __1ee;

    Pexpr __1ex;

    tmp_list = 0;
    for (__1ex = Ntmp_dtor; __1ex; __1ex = __1ex->__O3__4expr.e2) {
        __1ee = __1ex->__O2__4expr.e1;

        find_temps_in_expr__FP4exprPCc(__1ee, __1s);
        if (tmp_list) {
            tmp_list = 0;

            return (unsigned char)1;
        }
    }
    return (unsigned char)0;
}

static void mk_dtor_for_temp__FP4nameT1(Pname __1tmp, Pname __1dtor) {
    Pexpr __1dl;
    Pstmt __1dls;

    struct estmt *__0__X39;

    struct loc __2__X40;

    __1dl = call_dtor__FP4exprN21iT1((struct expr *)__1tmp, (struct expr *)__1dtor,
                                     (struct expr *)0, 45, one);
    __1dls = (struct stmt *)((__0__X39 = 0),
                             ((__2__X40 = __1tmp->where__4name),
                              (((__0__X39 || (__0__X39 = (struct estmt *)__nw__4stmtSFUl(
                                                  (size_t)(sizeof(struct estmt)))))
                                    ? ((__0__X39 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X39), ((unsigned char)72),
                                            __2__X40, ((struct stmt *)0))),
                                       (__0__X39->__O2__4stmt.e = __1dl))
                                    : 0),
                               __0__X39)));
    if (tmp_dtor) {
        __1dls->s_list__4stmt = tmp_dtor;
        tmp_dtor = __1dls;
    } else
        tmp_dtor = __1dls;
}

extern Pname make_tmp__FcP4typeP5table(char, Ptype, Ptable);

static Pexpr lift_dtors__FP4exprP5table(Pexpr __1e, Ptable __1tbl) {
    prune = 1;

    tmp_list = 0;

    find_temps_in_expr__FP4exprPCc(__1e->__O2__4expr.e1, (const char *)0);

    prune = 0;
    {
        Pname __1n1;

        __1n1 = tmp_list;

        tmp_list = 0;

        prune = 1;

        find_temps_in_expr__FP4exprPCc(__1e->__O3__4expr.e2, (const char *)0);

        prune = 0;
        {
            Pname __1n2;

            __1n2 = tmp_list;

            tmp_list = 0;

            if (__1tbl == 0)
                __1tbl = scope;
            {
                Ptype __1t;

                Pname __1tmp;

                Pexpr __1ex;

                Pexpr __1dl;

                Pname __1cn;

                Pname __1d;

                struct classdef *__0__X41;

                __1t = 0;

                __1tmp = 0;

                __1dl = make_dtor_expr__FP4name(__1n1);
                if (__1dl) {
                    __1t = __1e->__O2__4expr.e1->__O1__4expr.tp;
                    __1tmp = make_tmp__FcP4typeP5table('Q', __1t, __1tbl);
                    __1tmp->n_assigned_to__4name++;
                    __1ex = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                   (struct expr *)__1tmp, __1e->__O2__4expr.e1);

                    __1ex->__O1__4expr.tp = __1t;
                    __1e->__O2__4expr.e1 = __1ex;

                    __1e->__O2__4expr.e1->__O1__4expr.tp = __1t;
                    __1e->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                        (struct expr *)0, (unsigned char)71, __1e->__O2__4expr.e1, __1dl);

                    __1e->__O2__4expr.e1->__O1__4expr.tp = __1dl->__O1__4expr.tp;
                    __1e->__O2__4expr.e1 =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71,
                                               __1e->__O2__4expr.e1, (struct expr *)__1tmp);

                    __1e->__O2__4expr.e1->__O1__4expr.tp = __1t;
                }

                __1dl = make_dtor_expr__FP4name(__1n2);
                if (__1dl) {
                    if (__1e->__O3__4expr.e2->__O1__4expr.tp != __1t) {
                        __1t = __1e->__O3__4expr.e2->__O1__4expr.tp;
                        __1tmp = make_tmp__FcP4typeP5table('Q', __1t, __1tbl);
                    }
                    __1tmp->n_assigned_to__4name++;
                    __1ex = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                   (struct expr *)__1tmp, __1e->__O3__4expr.e2);

                    __1ex->__O1__4expr.tp = __1t;
                    __1e->__O3__4expr.e2 = __1ex;

                    __1e->__O3__4expr.e2->__O1__4expr.tp = __1t;
                    __1e->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                        (struct expr *)0, (unsigned char)71, __1e->__O3__4expr.e2, __1dl);

                    __1e->__O3__4expr.e2->__O1__4expr.tp = __1dl->__O1__4expr.tp;
                    __1e->__O3__4expr.e2 =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71,
                                               __1e->__O3__4expr.e2, (struct expr *)__1tmp);

                    __1e->__O3__4expr.e2->__O1__4expr.tp = __1t;
                }

                ;

                ;
                if (((__1e->base__4node == 68) && (__1cn = is_cl_obj__4typeFv(__1t))) &&
                    (__1d = ((__0__X41 = (((
                                  struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))))),
                             (__0__X41->c_dtor__8classdef))))
                    mk_dtor_for_temp__FP4nameT1(__1tmp, __1d);

                return __1e;
            }
        }
    }
}

static Pexpr lift_dtors__FRP4exprP5tableUc(Pexpr *__1e, Ptable __1tbl, TOK __1__A42) {
    prune = 1;

    tmp_list = 0;

    find_temps_in_expr__FP4exprPCc((*__1e), (const char *)0);

    prune = 0;
    {
        Pname __1n1;

        __1n1 = tmp_list;

        tmp_list = 0;

        if (__1tbl == 0)
            __1tbl = scope;

        {
            Pexpr __1dl;

            __1dl = make_dtor_expr__FP4name(__1n1);
            if (__1dl) {
                Ptype __2t;
                Pname __2tmp;

                __2t = ((*__1e))->__O1__4expr.tp;
                __2tmp = make_tmp__FcP4typeP5table('Q', __2t, __1tbl);
                __2tmp->n_assigned_to__4name++;

                {
                    Pexpr __2ex;

                    __2ex = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                   (struct expr *)__2tmp, (*__1e));

                    __2ex->__O1__4expr.tp = __2t;
                    ((*__1e)) = __2ex;

                    ((*__1e))->__O1__4expr.tp = __2t;
                    ((*__1e)) =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, (*__1e), __1dl);

                    ((*__1e))->__O1__4expr.tp = __1dl->__O1__4expr.tp;
                    ((*__1e)) = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, (*__1e),
                                                       (struct expr *)__2tmp);

                    ((*__1e))->__O1__4expr.tp = __2t;
                }
            }
            return ((*__1e));
        }
    }
}

void reinit__5tableFv(struct table *__0this);

Pstmt simpl__4stmtFv(struct stmt *__0this);

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

extern Pexpr mk_zero_init__FP4typeP4nameT2(Ptype, Pname, Pname);

void dcl_print__4nameFUc(struct name *__0this, TOK);

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

extern int isdigit(int);

extern int strncmp(const char *, const char *, size_t);

extern size_t strlen(const char *);

Pname has_ictor__8classdefFv(struct classdef *__0this);

Pstmt simpl__5blockFv(register struct block *__0this) {
    int __1i;
    Pname __1n;
    Pstmt __1ss;

    Pstmt __1sst;
    Pstmt __1dd;

    Pstmt __1ddt;
    Pstmt __1stail;
    Ptable __1old_scope;
    const char *__1fudge_007;

    __1ss = 0;

    __1sst = 0;
    __1dd = 0;

    __1ddt = 0;

    __1old_scope = scope;
    __1fudge_007 = 0;

    if (!need_lift)
        reinit__5tableFv(tmp_tbl);

    ;

    if (__0this->__O2__4stmt.own_tbl == 0) {
        __1ss = (__0this->s__4stmt ? simpl__4stmtFv(__0this->s__4stmt) : (((struct stmt *)0)));
        return __1ss;
    }

    {
        Pfct __1f;

        struct table *__0__X46;

        int __2__X47;

        struct table *__0__X48;

        int __2__X49;

        register struct name *__0__X93;

        unsigned long __2__X16;

        struct ea __0__X__V1400qmdw3vgovcnm;

        struct ea __0__X__V1500qmdw3vgovcnm;

        __1f = ((__0__X93 = curr_fct),
                (((__0__X93->__O1__4expr.tp->base__4node == 108)
                      ? (((struct fct *)(((struct fct *)__0__X93->__O1__4expr.tp))))
                      : (error__FiPCcRC2eaN33(
                             (int)'i', (const char *)"N::fct_type():%n is %k notF",
                             (const struct ea *)(((&__0__X__V1400qmdw3vgovcnm)->__O1__2ea.p =
                                                      ((const void *)__0__X93)),
                                                 (&__0__X__V1400qmdw3vgovcnm)),
                             (const struct ea
                                  *)((__2__X16 = __0__X93->__O1__4expr.tp->base__4node),
                                     (((((&__0__X__V1500qmdw3vgovcnm)->__O1__2ea.i = __2__X16), 0)),
                                      (&__0__X__V1500qmdw3vgovcnm))),
                             (const struct ea *)ea0, (const struct ea *)ea0),
                         (((struct fct *)0))))));

        scope = __0this->memtbl__4stmt;
        if (scope->init_stat__5table == 0)
            scope->init_stat__5table = 1;

        for (__1n = ((__0__X46 = scope),
                     ((__2__X47 = (__1i = 1)),
                      ((((__2__X47 <= 0) || (__0__X46->free_slot__5table <= __2__X47))
                            ? (((struct name *)0))
                            : (__0__X46->entries__5table[__2__X47])))));
             __1n; __1n = (__1n->n_tbl_list__4name
                               ? __1n->n_tbl_list__4name
                               : ((__0__X48 = scope),
                                  ((__2__X49 = (++__1i)),
                                   ((((__2__X49 <= 0) || (__0__X48->free_slot__5table <= __2__X49))
                                         ? (((struct name *)0))
                                         : (__0__X48->entries__5table[__2__X49]))))))) {
            Pstmt __2st;
            bit __2is_nrv;
            Pname __2cln;
            Pexpr __2in;

            __2st = 0;
            __2is_nrv = (!strcmp(__1n->__O2__4expr.string, (const char *)"__NRV"));

            __2in = __1n->__O3__4expr.n_initializer;

            if (__2in || __1n->n_evaluated__4name) {
                scope->init_stat__5table = 2;
                if (__1n->n_sto__4name == 14) {
                    {
                        struct ea __0__V43;

                        error__FP3locPCcRC2eaN33(
                            &__1n->where__4name, (const char *)"Id local extern%n",
                            (const struct ea *)(((&__0__V43)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V43)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        continue;
                    }
                }
            }

            switch (__1n->n_scope__4name) {
            case 136:
            case 0:
            case 25:
                continue;
            }

            if (__1n->n_stclass__4name == 31) {
                if (((__2in == 0) && (__1n->n_scope__4name == 137)) ||
                    (__2in && (__2in->base__4node == 186))) {

                    Pname __4cn;
                    Pname __4x;
                    Ptype __4ct;
                    int __4vec_seen;

                    Pexpr __4set;

                    __4vec_seen = 0;

                    __4cn = is_cl_obj__4typeFv(__1n->__O1__4expr.tp);
                    if (__4cn == 0) {
                        ++__4vec_seen;

                        __4cn = cl_obj_vec;
                    }

                    if (__4cn) {
                        __4ct = (struct type *)__ct__3ptrFUcP4type(
                            (struct ptr *)0, (unsigned char)125,
                            __4vec_seen ? (((struct vec *)(((struct vec *)__1n->__O1__4expr.tp))))
                                              ->typ__5pvtyp
                                        : __1n->__O1__4expr.tp);
                        __4x = make_tmp__FcP4typeP5table('F', __4ct, gtbl);

                        __4x->__O3__4expr.n_initializer =
                            mk_zero_init__FP4typeP4nameT2(__4x->__O1__4expr.tp, __1n, __1n);
                    } else
                        __4x = make_tmp__FcP4typeP5table('F', (struct type *)int_type, scope);

                    __4x->n_sto__4name = (__1n->n_stclass__4name = 31);
                    __4x->where__4name = __1n->where__4name;

                    if (__2in) {
                        if (__2in->__O3__4expr.e2)
                            __2in->base__4node = 70;
                        else
                            __2in = __2in->__O2__4expr.e1;
                    }

                    ;
                    if (__4cn) {
                        dcl_print__4nameFUc(__4x, (unsigned char)0);
                        {
                            Pclass __5cl;
                            Pname __5dtor;

                            Pexpr __5cc;

                            Pexpr __5xe;

                            __5cl =
                                (((struct classdef *)(((struct classdef *)__4cn->__O1__4expr.tp))));
                            __5dtor = (__5cl->c_dtor__8classdef);

                            if (__5dtor) {
                                if (__4vec_seen == 0) {
                                    Pexpr __7eee;
                                    Pexpr __7c;

                                    Pexpr __7e4;

                                    __7eee = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)111, (struct expr *)__4x,
                                        (struct expr *)0);
                                    __7c = call_dtor__FP4exprN21iT1(__7eee, (struct expr *)__5dtor,
                                                                    (struct expr *)0, 45, one);
                                    __7c->__O1__4expr.tp = (struct type *)any_type;
                                    ;
                                    if (ansi_opt) {
                                        __7e4 = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)147, __7c, zero);
                                        __7e4->__O1__4expr.tp = (struct type *)zero_type;
                                    } else {
                                        __7e4 = __7c;
                                    }
                                    __5cc = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                   (unsigned char)68, __7e4, zero);
                                    __5cc->__O4__4expr.cond = (struct expr *)__4x;
                                } else
                                    __5cc = cdvec__FP4nameP4exprP8classdefT1iN22(
                                        vec_del_fct, (struct expr *)__4x, __5cl, __5dtor, 0, zero,
                                        (struct expr *)__1n);
                                __5cc->__O1__4expr.tp = (struct type *)any_type;

                                {
                                    Pstmt __6dls;

                                    struct estmt *__0__X50;

                                    struct loc __2__X51;

                                    __6dls =
                                        (struct stmt
                                             *)((__0__X50 = 0),
                                                ((__2__X51 = __1n->where__4name),
                                                 (((__0__X50 ||
                                                    (__0__X50 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                                       ? ((__0__X50 = (struct estmt *)
                                                               __ct__4stmtFUc3locP4stmt(
                                                                   ((struct stmt *)__0__X50),
                                                                   ((unsigned char)72), __2__X51,
                                                                   ((struct stmt *)0))),
                                                          (__0__X50->__O2__4stmt.e = __5cc))
                                                       : 0),
                                                  __0__X50)));
                                    if (st_dlist)
                                        __6dls->s_list__4stmt = st_dlist;
                                    st_dlist = __6dls;
                                }
                            }

                            ;
                            if (__4cn) {
                                if (__4vec_seen == 0)
                                    __5xe = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)145, (struct expr *)0,
                                        (struct expr *)__1n);
                                else {
                                    Pexpr __7ee;

                                    __7ee =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111,
                                                               (struct expr *)__1n, zero);
                                    __5xe =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)145,
                                                               (struct expr *)0, __7ee);
                                }
                            }

                            __4set = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                            (struct expr *)__4x, __5xe);
                            __4set->__O1__4expr.tp = __4ct;
                        }
                    } else {
                        __4set = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                        (struct expr *)__4x, one);
                        __4set->__O1__4expr.tp = (struct type *)int_type;
                    }

                    if ((__1n->n_scope__4name == 137) && (__2in == 0)) {
                        struct estmt *__0__X52;

                        struct loc __2__X53;

                        __4set = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)68, zero,
                                                        __4set);
                        __4set->__O4__4expr.cond = (struct expr *)__4x;
                        __2st =
                            (struct stmt
                                 *)((__0__X52 = 0),
                                    ((__2__X53 = __1n->where__4name),
                                     (((__0__X52 || (__0__X52 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                           ? ((__0__X52 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                   ((struct stmt *)__0__X52), ((unsigned char)72),
                                                   __2__X53, ((struct stmt *)0))),
                                              (__0__X52->__O2__4stmt.e = __4set))
                                           : 0),
                                      __0__X52)));
                        goto init_stat3;
                    }

                    if (one == __4set->__O3__4expr.e2)
                        __2in = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147, __4set,
                                                       __2in);
                    else
                        __2in = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147, __2in,
                                                       __4set);
                    __2in =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)186, zero, __2in);
                    __2in->__O4__4expr.cond = (struct expr *)__4x;
                } else
                    continue;
            }

            if (__2in) {
                if (((__2in->base__4node == 124) && (__2in->__O3__4expr.e2 == 0)) ||
                    ((__2in->base__4node == 81) &&
                     (skiptypedefs__4typeFv(__1n->__O1__4expr.tp)->base__4node == 110)))
                    if (ansi_opt == 0) {
                        {
                            struct ea __0__V44;

                            error__FiP3locPCcRC2eaN34(
                                (int)'s', &__1n->where__4name,
                                (const char *)"initialization of%n (automatic aggregate)",
                                (const struct ea *)(((&__0__V44)->__O1__2ea.p =
                                                         ((const void *)__1n)),
                                                    (&__0__V44)),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                            continue;
                        }
                    } else {
                        __1n->__O3__4expr.n_initializer = __2in;
                        continue;
                    }
            }

            if ((((ansi_opt && __2in) && tconst__4typeFv(__1n->__O1__4expr.tp)) &&
                 (__1n->__O1__4expr.tp->base__4node != 110)) &&
                (__1n->n_sto__4name != 31)) {

                (((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp))))
                    ->ansi_const__4type = 1;
            }

            if (__1n->__O1__4expr.tp == 0)
                continue;
            if (__1n->n_evaluated__4name)
                continue;

            {
                const char *__3s;

                __3s = __1n->__O2__4expr.string;

                if (((((__3s[0]) == '_') && ((__3s[1]) == '_')) && ((__3s[2]) == 'D')) &&
                    isdigit((int)(__3s[3])))
                    continue;
            }

            if (__2cln = is_cl_obj__4typeFv(__1n->__O1__4expr.tp)) {
                Pclass __3cl;
                Pname __3d;

                __3cl = (((struct classdef *)(((struct classdef *)__2cln->__O1__4expr.tp))));
                __3d = (__3cl->c_dtor__8classdef);

                if (((__1n->n_stclass__4name == 31) && __2in) && (__2in->base__4node == 186))
                    goto stat_init;

                if (__3d && (!__2is_nrv)) {
                    if ((Ntmp_dtor && is_probably_temp__FPCc(__1n->__O2__4expr.string)) &&
                        find_in_Ntmp__FPCc(__1n->__O2__4expr.string))
                        continue;

                    {
                        Pexpr __4dl;

                        __4dl = call_dtor__FP4exprN21iT1((struct expr *)__1n, (struct expr *)__3d,
                                                         (struct expr *)0, 45, one);

                        if (pdlist && ((strncmp((const char *)"__R", __1n->__O2__4expr.string,
                                                (unsigned long)3) == 0) ||
                                       (strncmp((const char *)"__V", __1n->__O2__4expr.string,
                                                (unsigned long)3) == 0))) {
                            int __5len;

                            __5len = (strlen(__1n->__O2__4expr.string) + 1);
                            {
                                {
                                    struct con_dtor *__5pcd;

                                    __5pcd = pdlist;

                                    for (; __5pcd; __5pcd = __5pcd->next__8con_dtor) {
                                        if (strncmp(__1n->__O2__4expr.string,
                                                    __5pcd->tn__8con_dtor->__O2__4expr.string,
                                                    (unsigned long)__5len) == 0) {
                                            __1fudge_007 =
                                                __5pcd->condition__8con_dtor->__O2__4expr.string;
                                            {
                                                Pexpr __7e;

                                                __7e = __ct__4exprFUcP4exprT2(
                                                    (struct expr *)0, (unsigned char)70,
                                                    __5pcd->condition__8con_dtor, zero);
                                                __7e->__O1__4expr.tp = (struct type *)int_type;
                                                {
                                                    Pexpr __7ee;

                                                    __7ee = __ct__4exprFUcP4exprT2(
                                                        (struct expr *)0, (unsigned char)147, __7e,
                                                        __4dl);
                                                    __7ee->__O1__4expr.tp = (struct type *)int_type;
                                                    __7ee = __ct__4exprFUcP4exprT2(
                                                        (struct expr *)0, (unsigned char)147, __7ee,
                                                        zero);
                                                    __7ee->__O1__4expr.tp = (struct type *)int_type;
                                                    {
                                                        Pexpr __7qe;

                                                        __7qe = __ct__4exprFUcP4exprT2(
                                                            (struct expr *)0, (unsigned char)68,
                                                            __7ee, zero);
                                                        __7qe->__O4__4expr.cond =
                                                            __5pcd->condition__8con_dtor;
                                                        __7qe->__O1__4expr.tp =
                                                            (struct type *)int_type;
                                                        __4dl = __7qe;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        {
                            Pstmt __4dls;

                            struct estmt *__0__X54;

                            struct loc __2__X55;

                            __4dls =
                                (struct stmt *)((__0__X54 = 0),
                                                ((__2__X55 = no_where),
                                                 (((__0__X54 ||
                                                    (__0__X54 = (struct estmt *)__nw__4stmtSFUl(
                                                         (unsigned long)(sizeof(struct estmt)))))
                                                       ? ((__0__X54 = (struct estmt *)
                                                               __ct__4stmtFUc3locP4stmt(
                                                                   ((struct stmt *)__0__X54),
                                                                   ((unsigned char)72), __2__X55,
                                                                   ((struct stmt *)0))),
                                                          (__0__X54->__O2__4stmt.e = __4dl))
                                                       : 0),
                                                  __0__X54)));
                            if (__1dd) {
                                __4dls->s_list__4stmt = __1dd;
                                __1dd = __4dls;
                            } else
                                __1ddt = (__1dd = __4dls);
                        }
                    }
                }

                if (__2in) {
                    switch (__2in->base__4node) {
                        struct estmt *__0__X59;

                        struct loc __2__X60;

                        struct estmt *__0__X61;

                        struct loc __2__X62;

                        struct expr *__2__X63;

                    case 111:
                        if (__2in->__O2__4expr.e1->base__4node == 146) {
                            Pname __6fn;

                            struct estmt *__0__X56;

                            struct loc __2__X57;

                            struct expr *__2__X58;

                            __6fn = __2in->__O2__4expr.e1->__O4__4expr.fct_name;
                            if ((__6fn == 0) || (__6fn->n_oper__4name != 161))
                                goto ddd;
                            if (__2is_nrv) {
                                Pexpr __7et;

                                __7et = __2in->__O2__4expr.e1->__O2__4expr.e1;
                                __7et->__O2__4expr.e1 = (struct expr *)__1f->f_result__3fct;
                                __7et->base__4node = 44;
                            }
                            __2st =
                                (struct stmt *)((__0__X56 = 0),
                                                ((__2__X57 = __1n->where__4name),
                                                 ((__2__X58 = __2in->__O2__4expr.e1),
                                                  (((__0__X56 ||
                                                     (__0__X56 = (struct estmt *)__nw__4stmtSFUl(
                                                          (size_t)(sizeof(struct estmt)))))
                                                        ? ((__0__X56 = (struct estmt *)
                                                                __ct__4stmtFUc3locP4stmt(
                                                                    ((struct stmt *)__0__X56),
                                                                    ((unsigned char)72), __2__X57,
                                                                    ((struct stmt *)0))),
                                                           (__0__X56->__O2__4stmt.e = __2__X58))
                                                        : 0),
                                                   __0__X56))));
                            __1n->__O3__4expr.n_initializer = 0;
                            break;
                        }
                        goto ddd;
                    case 186:
                    stat_init:
                        __2in->base__4node = 68;
                        __2st =
                            (struct stmt
                                 *)((__0__X59 = 0),
                                    ((__2__X60 = __1n->where__4name),
                                     (((__0__X59 || (__0__X59 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                           ? ((__0__X59 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                   ((struct stmt *)__0__X59), ((unsigned char)72),
                                                   __2__X60, ((struct stmt *)0))),
                                              (__0__X59->__O2__4stmt.e = __2in))
                                           : 0),
                                      __0__X59)));
                        __1n->__O3__4expr.n_initializer = 0;
                        break;
                    case 147:
                        if (((__2is_nrv && ((__2in->__O2__4expr.e1->base__4node == 109) ||
                                            (__2in->__O2__4expr.e1->base__4node == 146))) &&
                             (__2in->__O2__4expr.e1->__O3__4expr.e2->__O2__4expr.e1->base__4node ==
                              145)) &&
                            ((((struct name *)(((struct name *)__2in->__O2__4expr.e1->__O3__4expr
                                                    .e2->__O2__4expr.e1->__O3__4expr.e2)))) ==
                             __1n)) {
                            __2in->__O2__4expr.e1->__O3__4expr.e2->__O2__4expr.e1 =
                                (struct expr *)__1f->f_result__3fct;
                        }
                        __2st =
                            (struct stmt
                                 *)((__0__X61 = 0),
                                    ((__2__X62 = __1n->where__4name),
                                     ((__2__X63 = __2in->__O2__4expr.e1),
                                      (((__0__X61 || (__0__X61 = (struct estmt *)__nw__4stmtSFUl(
                                                          (size_t)(sizeof(struct estmt)))))
                                            ? ((__0__X61 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                    ((struct stmt *)__0__X61), ((unsigned char)72),
                                                    __2__X62, ((struct stmt *)0))),
                                               (__0__X61->__O2__4stmt.e = __2__X63))
                                            : 0),
                                       __0__X61))));
                        __1n->__O3__4expr.n_initializer = 0;
                        break;
                    case 70:
                        if (__2in->__O2__4expr.e1 == (((struct expr *)__1n))) {
                            struct estmt *__0__X64;

                            struct loc __2__X65;

                            __2st =
                                (struct stmt *)((__0__X64 = 0),
                                                ((__2__X65 = __1n->where__4name),
                                                 (((__0__X64 ||
                                                    (__0__X64 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                                       ? ((__0__X64 = (struct estmt *)
                                                               __ct__4stmtFUc3locP4stmt(
                                                                   ((struct stmt *)__0__X64),
                                                                   ((unsigned char)72), __2__X65,
                                                                   ((struct stmt *)0))),
                                                          (__0__X64->__O2__4stmt.e = __2in))
                                                       : 0),
                                                  __0__X64)));
                            __1n->__O3__4expr.n_initializer = 0;
                            break;
                        }
                    default:
                        goto ddd;
                    }
                }
            } else if (cl_obj_vec) {
                Pclass __3cl;
                Pname __3d;
                Pname __3c;

                struct estmt *__0__X70;

                struct loc __2__X71;

                __3cl = (((struct classdef *)(((struct classdef *)cl_obj_vec->__O1__4expr.tp))));
                __3d = (__3cl->c_dtor__8classdef);
                __3c = has_ictor__8classdefFv(__3cl);
                __1n->__O3__4expr.n_initializer = 0;

                if (((__1n->n_stclass__4name == 31) && __2in) && (__2in->base__4node == 186))
                    goto stat_init2;

                if (__3c) {
                    struct estmt *__0__X68;

                    struct loc __2__X69;

                    if ((__2in == 0) || (__2in->base__4node == 124)) {
                        Pname __5vctor;
                        Pexpr __5a;

                        struct estmt *__0__X66;

                        struct loc __2__X67;

                        __5vctor = (__3cl->c_vtor__8classdef);
                        __5a = cdvec__FP4nameP4exprP8classdefT1iN22(
                            vec_new_fct, (struct expr *)__1n, __3cl, __5vctor ? __5vctor : __3c, -1,
                            (struct expr *)0, (struct expr *)0);
                        __2st =
                            (struct stmt
                                 *)((__0__X66 = 0),
                                    ((__2__X67 = __1n->where__4name),
                                     (((__0__X66 || (__0__X66 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                           ? ((__0__X66 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                   ((struct stmt *)__0__X66), ((unsigned char)72),
                                                   __2__X67, ((struct stmt *)0))),
                                              (__0__X66->__O2__4stmt.e = __5a))
                                           : 0),
                                      __0__X66)));
                    } else
                        __2st =
                            (struct stmt
                                 *)((__0__X68 = 0),
                                    ((__2__X69 = __1n->where__4name),
                                     (((__0__X68 || (__0__X68 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                           ? ((__0__X68 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                   ((struct stmt *)__0__X68), ((unsigned char)72),
                                                   __2__X69, ((struct stmt *)0))),
                                              (__0__X68->__O2__4stmt.e = __2in))
                                           : 0),
                                      __0__X68)));
                } else if (__2in)
                    __2st = (struct stmt
                                 *)((__0__X70 = 0),
                                    ((__2__X71 = __1n->where__4name),
                                     (((__0__X70 || (__0__X70 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                           ? ((__0__X70 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                   ((struct stmt *)__0__X70), ((unsigned char)72),
                                                   __2__X71, ((struct stmt *)0))),
                                              (__0__X70->__O2__4stmt.e = __2in))
                                           : 0),
                                      __0__X70)));

                if (__3d) {
                    Pfct __4f;
                    int __4i;

                    __4f = (((struct fct *)(((struct fct *)__3d->__O1__4expr.tp))));
                    __4i = 0;
                    {
                        {
                            Pname __4nn;

                            __4nn = __4f->f_args__3fct->__O1__4name.n_list;

                            for (; __4nn && __4nn->__O1__4name.n_list;
                                 __4nn = __4nn->__O1__4name.n_list)
                                __4i++;
                            {
                                Pexpr __4a;

                                Pstmt __4dls;

                                struct ival *__0__X72;

                                struct estmt *__0__X73;

                                struct loc __2__X74;

                                __4a = cdvec__FP4nameP4exprP8classdefT1iN22(
                                    vec_del_fct, (struct expr *)__1n, __3cl, __3d, 0,
                                    (struct expr
                                         *)((__0__X72 = 0),
                                            (((__0__X72 ||
                                               (__0__X72 = (struct ival *)__nw__4exprSFUl(
                                                    (size_t)(sizeof(struct ival)))))
                                                  ? ((__0__X72 =
                                                          (struct ival *)__ct__4exprFUcP4exprT2(
                                                              ((struct expr *)__0__X72),
                                                              (unsigned char)150, (struct expr *)0,
                                                              (struct expr *)0)),
                                                     (__0__X72->__O2__4expr.i1 = ((long long)__4i)))
                                                  : 0),
                                             __0__X72)),
                                    (struct expr *)0);

                                __4dls =
                                    (struct stmt
                                         *)((__0__X73 = 0),
                                            ((__2__X74 = no_where),
                                             (((__0__X73 ||
                                                (__0__X73 = (struct estmt *)__nw__4stmtSFUl(
                                                     (unsigned long)(sizeof(struct estmt)))))
                                                   ? ((__0__X73 =
                                                           (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                               ((struct stmt *)__0__X73),
                                                               ((unsigned char)72), __2__X74,
                                                               ((struct stmt *)0))),
                                                      (__0__X73->__O2__4stmt.e = __4a))
                                                   : 0),
                                              __0__X73)));
                                if (__1dd) {
                                    __4dls->s_list__4stmt = __1dd;
                                    __1dd = __4dls;
                                } else
                                    __1ddt = (__1dd = __4dls);
                            }
                        }
                    }
                }
            } else if (__2in) {
                switch (__2in->base__4node) {
                    struct estmt *__0__X77;

                    struct loc __2__X78;

                case 124:
                    switch (__1n->n_scope__4name) {
                    case 108:
                        if (__2in->__O3__4expr.e2) {
                            Pexpr __6ee;

                            struct estmt *__0__X75;

                            struct loc __2__X76;

                            __6ee = mptr_assign__FP4exprT1((struct expr *)__1n, __2in);
                            __2st =
                                (struct stmt *)((__0__X75 = 0),
                                                ((__2__X76 = __1n->where__4name),
                                                 (((__0__X75 ||
                                                    (__0__X75 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                                       ? ((__0__X75 = (struct estmt *)
                                                               __ct__4stmtFUc3locP4stmt(
                                                                   ((struct stmt *)__0__X75),
                                                                   ((unsigned char)72), __2__X76,
                                                                   ((struct stmt *)0))),
                                                          (__0__X75->__O2__4stmt.e = __6ee))
                                                       : 0),
                                                  __0__X75)));
                            __1n->__O3__4expr.n_initializer = 0;
                            break;
                        }
                    case 136:
                        if (ansi_opt == 0) {
                            struct ea __0__V45;

                            error__FiPCcRC2eaN33((int)'s', (const char *)"Ir list for localV%n",
                                                 (const struct ea *)(((&__0__V45)->__O1__2ea.p =
                                                                          ((const void *)__1n)),
                                                                     (&__0__V45)),
                                                 (const struct ea *)ea0, (const struct ea *)ea0,
                                                 (const struct ea *)ea0);
                        }
                    }
                    break;
                case 186:
                stat_init2:
                    __2in->base__4node = 68;
                    __2st = (struct stmt
                                 *)((__0__X77 = 0),
                                    ((__2__X78 = __1n->where__4name),
                                     (((__0__X77 || (__0__X77 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                           ? ((__0__X77 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                   ((struct stmt *)__0__X77), ((unsigned char)72),
                                                   __2__X78, ((struct stmt *)0))),
                                              (__0__X77->__O2__4stmt.e = __2in))
                                           : 0),
                                      __0__X77)));
                    __1n->__O3__4expr.n_initializer = 0;
                    break;
                case 81:
                    if (__1n->__O1__4expr.tp->base__4node == 110)
                        break;
                default:
                ddd: {
                    if (__1fudge_007 && (strcmp(__1n->__O2__4expr.string, __1fudge_007) == 0))
                        __1fudge_007 = 0;
                    else {
                        Pexpr __6ee;

                        struct estmt *__0__X79;

                        struct loc __2__X80;

                        __6ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                       (struct expr *)__1n, __2in);
                        __2st =
                            (struct stmt
                                 *)((__0__X79 = 0),
                                    ((__2__X80 = __1n->where__4name),
                                     (((__0__X79 || (__0__X79 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                           ? ((__0__X79 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                   ((struct stmt *)__0__X79), ((unsigned char)72),
                                                   __2__X80, ((struct stmt *)0))),
                                              (__0__X79->__O2__4stmt.e = __6ee))
                                           : 0),
                                      __0__X79)));
                        __1n->__O3__4expr.n_initializer = 0;
                    }
                }
                }
            }

        init_stat3:
            if (__2st) {
                if (__1ss)
                    __1sst->s_list__4stmt = __2st;
                else
                    __1ss = __2st;
                __1sst = __2st;
            }
            if (__2is_nrv)
                __1n->__O1__4expr.tp = (struct type *)any_type;
        }

        if (__1dd) {
            Pstmt __2od;
            Pstmt __2obd;
            Pstmt __2ocd;

            struct pair *__0__X81;

            struct loc __2__X82;

            struct stmt *__2__X83;

            struct stmt *__2__X84;

            struct pair *__0__X85;

            struct loc __2__X86;

            struct stmt *__2__X87;

            struct stmt *__2__X88;

            struct pair *__0__X89;

            struct loc __2__X90;

            struct stmt *__2__X91;

            struct stmt *__2__X92;

            __2od = del_list;
            __2obd = break_del_list;
            __2ocd = continue_del_list;

            simpl__4stmtFv(__1dd);
            del_list =
                (__2od ? (((struct stmt *)(((
                             struct stmt
                                 *)((__0__X81 = 0),
                                    ((__2__X82 = curloc),
                                     ((__2__X83 = __1dd),
                                      ((__2__X84 = __2od),
                                       (((__0__X81 || (__0__X81 = (struct pair *)__nw__4stmtSFUl(
                                                           (size_t)(sizeof(struct pair)))))
                                             ? ((__0__X81 = (struct pair *)__ct__4stmtFUc3locP4stmt(
                                                     ((struct stmt *)__0__X81), (unsigned char)166,
                                                     __2__X82, __2__X83)),
                                                (__0__X81->__O2__4stmt.s2 = __2__X84))
                                             : 0),
                                        __0__X81)))))))))
                       : __1dd);
            break_del_list =
                ((break_del_list && __2obd)
                     ? (((struct stmt *)((
                           (struct stmt
                                *)((__0__X85 = 0),
                                   ((__2__X86 = curloc),
                                    ((__2__X87 = __1dd),
                                     ((__2__X88 = __2obd),
                                      (((__0__X85 || (__0__X85 = (struct pair *)__nw__4stmtSFUl(
                                                          (size_t)(sizeof(struct pair)))))
                                            ? ((__0__X85 = (struct pair *)__ct__4stmtFUc3locP4stmt(
                                                    ((struct stmt *)__0__X85), (unsigned char)166,
                                                    __2__X86, __2__X87)),
                                               (__0__X85->__O2__4stmt.s2 = __2__X88))
                                            : 0),
                                       __0__X85)))))))))
                     : __1dd);
            continue_del_list =
                ((continue_del_list && __2ocd)
                     ? (((struct stmt *)((
                           (struct stmt
                                *)((__0__X89 = 0),
                                   ((__2__X90 = curloc),
                                    ((__2__X91 = __1dd),
                                     ((__2__X92 = __2ocd),
                                      (((__0__X89 || (__0__X89 = (struct pair *)__nw__4stmtSFUl(
                                                          (size_t)(sizeof(struct pair)))))
                                            ? ((__0__X89 = (struct pair *)__ct__4stmtFUc3locP4stmt(
                                                    ((struct stmt *)__0__X89), (unsigned char)166,
                                                    __2__X90, __2__X91)),
                                               (__0__X89->__O2__4stmt.s2 = __2__X92))
                                            : 0),
                                       __0__X89)))))))))
                     : __1dd);

            __1stail =
                (__0this->s__4stmt ? simpl__4stmtFv(__0this->s__4stmt) : (((struct stmt *)0)));

            {
                Pfct __2f;

                __2f = (((struct fct *)(((struct fct *)curr_fct->__O1__4expr.tp))));
                if ((((__0this != __2f->body__3fct) || (__2f->returns__3fct->base__4node == 38)) ||
                     ((__2f->returns__3fct->base__4node != 38) && (no_of_returns == 0))) ||
                    (strcmp(curr_fct->__O2__4expr.string, (const char *)"main") == 0)) {
                    if (__1stail) {

                        Pstmt __4tt;

                        __4tt = (((__1stail->base__4node == 28) || (__1stail->base__4node == 115))
                                     ? __1stail
                                     : trim_tail__FP4stmt(__1stail));
                        if (__4tt && (__4tt->base__4node != 28))
                            __1stail->s_list__4stmt = __1dd;
                    } else
                        __0this->s__4stmt = __1dd;
                    __1stail = __1ddt;
                }

                del_list = __2od;
                continue_del_list = __2ocd;
                break_del_list = __2obd;
            }
        } else
            __1stail =
                (__0this->s__4stmt ? simpl__4stmtFv(__0this->s__4stmt) : (((struct stmt *)0)));

        if (__1ss) {
            simpl__4stmtFv(__1ss);
            __1sst->s_list__4stmt = __0this->s__4stmt;
            __0this->s__4stmt = __1ss;
            if (__1stail == 0)
                __1stail = __1sst;
        }

        if (tmp_dtor) {
            simpl__4stmtFv(tmp_dtor);
            if (__1stail == 0)
                __1stail = tmp_dtor;
            else
                __1stail->s_list__4stmt = tmp_dtor;
            tmp_dtor = 0;
        }

        scope = __1old_scope;

        return __1stail;
    }
}

int no_sizeof = 0;

void del__4exprFv(struct expr *__0this);

extern Pname find_vptr__FP8classdef(Pclass);

extern char *strcpy(char *, const char *);

void simpl__4callFv(struct call *__0this);

void simpl_new__4exprFv(struct expr *__0this);
void simpl_delete__4exprFv(struct expr *__0this);

Pexpr address__4exprFv(struct expr *__0this);

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

long long eval__4exprFv(struct expr *__0this);

void simpl__4exprFv(register struct expr *__0this) {
    ;

    if (__0this == 0)
        return;
    if (__0this->permanent__4node == 2)
        return;
    {
        static TOK __1obase = 0;

        switch (__0this->base__4node) {
        case 177:
            __1obase = __0this->base__4node;
            simpl__4exprFv(__0this->__O4__4expr.mem);
            __1obase = 0;

        case 168:
            return;

        case 145:
        case 112:
            simpl__4exprFv(__0this->__O3__4expr.e2);
            switch (__0this->__O3__4expr.e2->base__4node) {
            case 45:
            case 44: {
                Pref __4r;
                Pname __4m;

                __4r = (((struct ref *)(((struct ref *)__0this->__O3__4expr.e2))));
                __4m = (((struct name *)(((struct name *)__4r->__O4__4expr.mem))));
                while (__4m->base__4node == 177)
                    __4m = (((struct name *)(((struct name *)__4m->__O4__4expr.mem))));
                if (__4m->n_stclass__4name == 31) {
                    Pexpr __5x;
                delp:
                    __5x = __0this->__O3__4expr.e2;
                    __0this->__O3__4expr.e2 = (struct expr *)__4m;
                    __4r->__O4__4expr.mem = 0;
                    if (__5x && (__5x->permanent__4node == 0))
                        del__4exprFv(__5x);
                } else if (__4m->__O1__4expr.tp->base__4node == 108) {
                    Pfct __5f;

                    __5f = (((struct fct *)(((struct fct *)__4m->__O1__4expr.tp))));
                    if (__5f->f_virtual__3fct) {
                        int __6index;
                        Pexpr __6ie;

                        struct ival *__0__X98;

                        __6index = __5f->f_virtual__3fct;
                        __6ie =
                            (struct expr
                                 *)(__6index
                                        ? ((__0__X98 = 0),
                                           (((__0__X98 ||
                                              (__0__X98 = (struct ival *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ival)))))
                                                 ? ((__0__X98 =
                                                         (struct ival *)__ct__4exprFUcP4exprT2(
                                                             ((struct expr *)__0__X98),
                                                             (unsigned char)150, (struct expr *)0,
                                                             (struct expr *)0)),
                                                    (__0__X98->__O2__4expr.i1 =
                                                         ((long long)__6index)))
                                                 : 0),
                                            __0__X98))
                                        : (((struct ival *)0)));
                        if (__6ie)
                            __6ie->__O1__4expr.tp = (struct type *)int_type;
                        {
                            Pname __6cn;
                            Pname __6vp;

                            __6cn = __4m->__O4__4expr.n_table->t_name__5table;
                            __6vp = find_vptr__FP8classdef(
                                ((struct classdef *)(((struct classdef *)__6cn->__O1__4expr.tp))));
                            __4r->__O4__4expr.mem = (struct expr *)__6vp;

                            if (__1obase == 177) {
                                __0this->base__4node = 111;
                                __0this->__O2__4expr.e1 = __0this->__O3__4expr.e2;
                                __0this->__O3__4expr.e2 = __6ie;
                            } else {
                                __0this->base__4node = 177;
                                __0this->__O4__4expr.mem =
                                    __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111,
                                                           __0this->__O3__4expr.e2, __6ie);
                                __0this->__O3__4expr.string2 = (const char *)"f";
                                __0this->__O2__4expr.i1 = 9;
                            }
                        }
                    } else {
                        goto delp;
                    }
                }
                break;
            }
            }
            break;
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
            imeasure++;
            if (__0this->__O2__4expr.e1)
                simpl__4exprFv(__0this->__O2__4expr.e1);
            if (__0this->__O3__4expr.e2)
                simpl__4exprFv(__0this->__O3__4expr.e2);
            break;
        case 66:
        case 67:
            if (Ntmp_dtor && need_lift_dtors__FP4expr(__0this)) {
                need_lift = 1;
                {
                    Pexpr __3e;

                    __3e = lift_dtors__FP4exprP5table(__0this, Ntmp_tbl);
                    ((*__0this)) = (*__3e);
                }
            }
            Ntmp = 0;

        default:
            if (__0this->__O2__4expr.e1)
                simpl__4exprFv(__0this->__O2__4expr.e1);
            if (__0this->__O3__4expr.e2)
                simpl__4exprFv(__0this->__O3__4expr.e2);
            break;

        case 71:
        case 147: {
            Pname __3n;

            __3n = 0;
            simpl__4exprFv(__0this->__O2__4expr.e1);
            simpl__4exprFv(__0this->__O3__4expr.e2);
            if ((__0this->__O2__4expr.e1->base__4node == 168) &&
                (__0this->__O2__4expr.e1->__O2__4expr.e1 == 0))
                __3n = __0this->__O2__4expr.e1->__O4__4expr.il->fct_name__5iline;
            if ((__0this->__O3__4expr.e2->base__4node == 168) &&
                (__0this->__O3__4expr.e2->__O2__4expr.e1 == 0))
                __3n = __0this->__O3__4expr.e2->__O4__4expr.il->fct_name__5iline;
            if (__3n) {
                struct ea __0__V94;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"cannot expand inline void%n called in commaE",
                    (const struct ea *)(((&__0__V94)->__O1__2ea.p = ((const void *)__3n)),
                                        (&__0__V94)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            return;
        }
        case 162:
            __0this->base__4node = 150;
            __0this->__O2__4expr.i1 = 0;

        case 144:
        case 85:
        case 82:
        case 83:
        case 84:
        case 150:
        case 81:
        case 86:
        case 124:
            if (__0this->base__4node == 82) {
                char *__3s;

                __3s = (((char *)__nw__FUl(
                    (size_t)((sizeof(char)) * (strlen(__0this->__O2__4expr.string) + 1)))));

                strcpy(__3s, __0this->__O2__4expr.string);
                __0this->__O2__4expr.string = (const char *)__3s;
            }
            return;

        case 30:
            if (__0this->__O2__4expr.e1)
                simpl__4exprFv(__0this->__O2__4expr.e1);
            return;

        case 146:
        case 109:
            simpl__4callFv(((struct call *)(((struct call *)__0this))));
            break;

        case 23:
        case 213:
        case 184:
            simpl_new__4exprFv(__0this);
            return;

        case 9:
        case 212:
        case 188:
            simpl_delete__4exprFv(__0this);
            break;

        case 68:
            if (Ntmp_dtor && need_lift_dtors__FP4expr(__0this)) {
                need_lift = 1;
                {
                    Pexpr __3e;

                    __3e = lift_dtors__FP4exprP5table(__0this, Ntmp_tbl);
                    ((*__0this)) = (*__3e);
                }
            }
            simpl__4exprFv(__0this->__O4__4expr.cond);
            Ntmp = 0;
            simpl__4exprFv(__0this->__O3__4expr.e2);

        case 113:
        case 191:
        case 44:
            simpl__4exprFv(__0this->__O2__4expr.e1);
            break;

        case 45:
            simpl__4exprFv(__0this->__O2__4expr.e1);
            switch (__0this->__O2__4expr.e1->base__4node) {
            case 71:
            case 147: {
                Pexpr __4ex;

                __4ex = __0this->__O2__4expr.e1;
            cfr:
                switch (__4ex->__O3__4expr.e2->base__4node) {
                case 85:
                    __0this->base__4node = 44;
                    __4ex->__O3__4expr.e2 = address__4exprFv(__4ex->__O3__4expr.e2);
                    break;
                case 71:
                case 147:
                    __4ex = __4ex->__O3__4expr.e2;
                    goto cfr;
                }
            }
            }
            break;

        case 70: {
            Pfct __3f;
            Pexpr __3th;

            __3f = 0;
            __3th = 0;
            if (curr_fct) {
                __3f = (((struct fct *)(((struct fct *)curr_fct->__O1__4expr.tp))));
                __3th = (struct expr *)__3f->f_this__3fct;
            }

            imeasure++;
            if (__0this->__O2__4expr.e1)
                simpl__4exprFv(__0this->__O2__4expr.e1);
            if (__0this->__O3__4expr.e2) {
                Pexpr __4c;

                __4c = __0this->__O3__4expr.e2;
                simpl__4exprFv(__4c);
                while ((__4c->base__4node == 113) || (__4c->base__4node == 191))
                    __4c = __4c->__O2__4expr.e1;
                if (__4c->base__4node == 124)
                    __0this->__O3__4expr.e2 = __4c;

                if (__0this->__O3__4expr.e2->base__4node == 124) {
                    Pexpr __5ee;
                    if (__0this->__O2__4expr.e1->base__4node == 111) {
                        Pexpr __6tmp;

                        __6tmp = (struct expr *)make_tmp__FcP4typeP5table(
                            'A', __0this->__O2__4expr.e1->__O1__4expr.tp, cc->ftbl__11dcl_context);
                        __5ee = mptr_assign__FP4exprT1(__6tmp, __0this->__O3__4expr.e2);
                        __0this->__O3__4expr.e2 =
                            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71,
                                                   __5ee->__O2__4expr.e1, __5ee->__O3__4expr.e2);
                        __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                            (struct expr *)0, (unsigned char)71, __0this->__O3__4expr.e2, __6tmp);
                        __0this->__O3__4expr.e2->__O1__4expr.tp =
                            __0this->__O2__4expr.e1->__O1__4expr.tp;
                    } else {
                        __5ee = mptr_assign__FP4exprT1(__0this->__O2__4expr.e1,
                                                       __0this->__O3__4expr.e2);
                        {
                            Pexpr __6eee;

                            __6eee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71,
                                                            __5ee->__O3__4expr.e2,
                                                            __0this->__O2__4expr.e1);
                            __0this->__O2__4expr.e1 = __5ee->__O2__4expr.e1;
                            __0this->__O3__4expr.e2 = __6eee;
                            __0this->base__4node = 71;
                        }
                    }
                    ((__5ee ? (((void)(__5ee ? (((void)(((void)__dl__4exprSFPvUl(
                                                   (void *)__5ee, (size_t)(sizeof(struct expr)))))))
                                             : (((void)0)))))
                            : (((void)0))));
                }
            }

            if (((__3th && (__3th == __0this->__O2__4expr.e1)) &&
                 (curr_fct->n_oper__4name == 161)) &&
                init_list) {
                Pclass __4cl;

                const void *__2__X99;

                __4cl = (((struct classdef *)((
                    (struct classdef
                         *)(((struct basetype *)((
                                (struct basetype *)(((struct ptr *)((
                                                        (struct ptr *)__3th->__O1__4expr.tp))))
                                    ->typ__5pvtyp))))
                        ->b_name__8basetype->__O1__4expr.tp))));
                if (__4cl->c_body__8classdef == 1)
                    dcl_print__8classdefFP4name(__4cl, (struct name *)0);
                imeasure++;
                __0this->base__4node = 71;
                __0this->__O2__4expr.e1 =
                    __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                           __0this->__O2__4expr.e1, __0this->__O3__4expr.e2);
                __0this->__O3__4expr.e2 = init_list;
                if (warning_opt) {
                    struct ea __0__V95;

                    error__FiPCcRC2eaN33(
                        (int)'w',
                        (const char
                             *)"assignment to ``this'' inK: try defining%t::operator new() instead",
                        (const struct ea *)((__2__X99 = (const void *)__3f->memof__3fct),
                                            (((&__0__V95)->__O1__2ea.p = __2__X99), (&__0__V95))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
            break;
        }
        }

        switch (__0this->base__4node) {
            const void *__2__X100;

            unsigned long __2__X101;

        case 68:
        case 66:
        case 67:
            if (Ntmp) {
                struct ea __0__V96;

                struct ea __0__V97;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"temporary ofC%n with destructor needed in%kE",
                    (const struct ea *)((__2__X100 = (const void *)Ntmp),
                                        (((&__0__V96)->__O1__2ea.p = __2__X100), (&__0__V96))),
                    (const struct ea *)((__2__X101 = __0this->base__4node),
                                        (((((&__0__V97)->__O1__2ea.i = __2__X101), 0)),
                                         (&__0__V97))),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
        default:
            Ntmp = 0;
        }

        if ((__0this->__O1__4expr.tp == (((struct type *)int_type))) ||
            (__0this->__O1__4expr.tp == (((struct type *)defa_type)))) {
            Neval = 0;
            no_sizeof = 1;
            {
                long long __2i;

                __2i = eval__4exprFv(__0this);
                no_sizeof = 0;
                if (Neval == 0) {
                    __0this->base__4node = 150;
                    __0this->__O2__4expr.i1 = __2i;
                }
            }
        }
    }
}

static Pname vfunt_name;

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);

static int same_class__FP8classdefT1i(Pclass __1c1, Pclass __1c2, int __1dummy);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

Pexpr vptr_entry__FP4exprT1P8classdef(Pexpr __1pp, Pexpr __1ie, Pclass __1cl) {
    Pptr __1ttemp;

    __1ttemp = is_ptr_or_ref__4typeFv(__1pp->__O1__4expr.tp);

    if (__1ttemp) {
        Ptype __2pt;
        Pclass __2pc;

        struct classdef *__1__X105;

        struct classdef *__1__X106;

        register struct cast *__0__X107;

        __2pt = __1ttemp->typ__5pvtyp;
        __2pc =
            (((struct classdef *)(((struct classdef *)is_cl_obj__4typeFv(__2pt)->__O1__4expr.tp))));
        if (!((__1__X105 = __2pc),
              ((__1__X106 = __1cl),
               (((__1__X105 == __1__X106)
                     ? 1
                     : ((__1__X105 && __1__X106)
                            ? (((int)same_class__8classdefFP8classdefi(__1__X105, __1__X106, 0)))
                            : 0))))))
            __1pp =
                (struct expr *)((__0__X107 = 0),
                                (((__0__X107 || (__0__X107 = (struct cast *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct cast)))))
                                      ? ((__0__X107 = (struct cast *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X107), (unsigned char)191, __1pp,
                                              (struct expr *)0)),
                                         (__0__X107->__O1__4expr.tp = (__0__X107->__O4__4expr.tp2 =
                                                                           ((struct type *)__1cl))))
                                      : 0),
                                 __0__X107));
    }
    {
        Pname __1vp;

        __1vp = find_vptr__FP8classdef(__1cl);
        if (__1vp == 0) {
            struct classdef *__1__X108;

            struct classdef *__1__X109;

            const void *__2__X110;

            if (cc->cot__11dcl_context &&
                (((__1__X108 = cc->cot__11dcl_context->in_class__4type),
                  ((__1__X109 = __1cl),
                   (((__1__X108 == __1__X109)
                         ? 1
                         : ((__1__X108 && __1__X109) ? (((int)same_class__8classdefFP8classdefi(
                                                           __1__X108, __1__X109, 0)))
                                                     : 0))))) ||
                 same_class__FP8classdefT1i(cc->cot__11dcl_context, __1cl, 0))) {
                struct ea __0__V102;

                struct ea __0__V103;

                struct ea __0__V104;

                error__FiPCcRC2eaN33(
                    (int)'s',
                    (const char *)"call of virtualF%n beforeC %s has been completely declared - %s "
                                  "make function non-virtual",
                    (const struct ea *)((__2__X110 = (const void *)vfunt_name),
                                        (((&__0__V102)->__O1__2ea.p = __2__X110), (&__0__V102))),
                    (const struct ea *)__ct__2eaFPCv(&__0__V103,
                                                     (const void *)__1cl->string__8classdef),
                    (const struct ea *)__ct__2eaFPCv(
                        &__0__V104,
                        (const void
                             *)((curr_fct &&
                                 (strcmp((const char *)"..", curr_fct->__O2__4expr.string) == 0))
                                    ? "try moving call from argument list into function body or"
                                    : (((char *)"")))),
                    (const struct ea *)ea0);
            } else
                error__FiPCc((int)'i', (const char *)"can't find vptr");
        }
        {
            Pexpr __1vptr;

            struct ref *__0__X111;

            struct expr *__2__X112;

            struct expr *__2__X113;

            __1vptr =
                (struct expr *)((__0__X111 = 0),
                                ((__2__X112 = __1pp),
                                 ((__2__X113 = (struct expr *)__1vp),
                                  (((__0__X111 || (__0__X111 = (struct ref *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct ref)))))
                                        ? ((__0__X111 = (struct ref *)__ct__4exprFUcP4exprT2(
                                                ((struct expr *)__0__X111), ((unsigned char)44),
                                                __2__X112, (struct expr *)0)),
                                           (__0__X111->__O4__4expr.mem = __2__X113))
                                        : 0),
                                   __0__X111))));
            return __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111, __1vptr, __1ie);
        }
    }
}

Pexpr new_this__FP4exprT1(Pexpr __1pp, Pexpr __1ee) {
    Pexpr __1dee;

    register struct mdot *__0__X118;

    __1dee = (struct expr *)((__0__X118 = 0),
                             (((__0__X118 || (__0__X118 = (struct mdot *)__nw__4exprSFUl(
                                                  (size_t)(sizeof(struct mdot)))))
                                   ? ((__0__X118 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                           ((struct expr *)__0__X118), (unsigned char)177,
                                           (struct expr *)0, (struct expr *)0)),
                                      ((__0__X118->__O3__4expr.string2 = ((const char *)"d")),
                                       (__0__X118->__O4__4expr.mem = __1ee)))
                                   : 0),
                              __0__X118));
    __1dee->__O2__4expr.i1 = 9;
    {
        Pexpr __1nthis;

        register struct cast *__0__X116;

        struct type *__2__X117;

        __1nthis = (struct expr *)((__0__X116 = 0),
                                   ((__2__X117 = Pchar_type),
                                    (((__0__X116 || (__0__X116 = (struct cast *)__nw__4exprSFUl(
                                                         (unsigned long)(sizeof(struct cast)))))
                                          ? ((__0__X116 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X116), (unsigned char)191,
                                                  __1pp, (struct expr *)0)),
                                             (__0__X116->__O1__4expr.tp =
                                                  (__0__X116->__O4__4expr.tp2 = __2__X117)))
                                          : 0),
                                     __0__X116)));
        __1nthis = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)54, __1nthis, __1dee);
        {
            Ptype __1ct;

            struct type *__0__X114;

            register struct cast *__0__X115;

            __1ct = __1pp->__O1__4expr.tp;
            if ((__1pp->base__4node == 85) &&
                (((struct name *)(((struct name *)__1pp))))->n_xref__4name)
                __1ct = (struct type *)((__0__X114 = __1pp->__O1__4expr.tp),
                                        (__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125,
                                                             __0__X114)));
            return (struct expr *)((__0__X115 = 0),
                                   (((__0__X115 || (__0__X115 = (struct cast *)__nw__4exprSFUl(
                                                        (size_t)(sizeof(struct cast)))))
                                         ? ((__0__X115 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                 ((struct expr *)__0__X115), (unsigned char)191,
                                                 __1nthis, (struct expr *)0)),
                                            (__0__X115->__O1__4expr.tp =
                                                 (__0__X115->__O4__4expr.tp2 = __1ct)))
                                         : 0),
                                    __0__X115));
        }
    }
}

Pcall vcall__FP4exprT1P3fctP8classdefT1(Pexpr __1pp, Pexpr __1ie, Pfct __1f, Pclass __1cl,
                                        Pexpr __1args) {
    if (__1cl->c_body__8classdef == 1)
        dcl_print__8classdefFP4name(__1cl, (struct name *)0);

    imeasure += 6;
    {
        Pexpr __1ee;

        Pexpr __1fee;

        register struct mdot *__0__X123;

        __1ee = vptr_entry__FP4exprT1P8classdef(__1pp, __1ie, __1cl);

        __1fee = (struct expr *)((__0__X123 = 0),
                                 (((__0__X123 || (__0__X123 = (struct mdot *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct mdot)))))
                                       ? ((__0__X123 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X123), (unsigned char)177,
                                               (struct expr *)0, (struct expr *)0)),
                                          ((__0__X123->__O3__4expr.string2 = ((const char *)"f")),
                                           (__0__X123->__O4__4expr.mem = __1ee)))
                                       : 0),
                                  __0__X123));
        __1fee->__O2__4expr.i1 = 9;
        {
            Ptype __1pft;

            register struct cast *__0__X119;

            __1pft = (struct type *)(__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125,
                                                         ((struct type *)__1f)));
            __1fee = (struct expr *)((__0__X119 = 0),
                                     (((__0__X119 || (__0__X119 = (struct cast *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct cast)))))
                                           ? ((__0__X119 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X119), (unsigned char)191,
                                                   __1fee, (struct expr *)0)),
                                              (__0__X119->__O1__4expr.tp =
                                                   (__0__X119->__O4__4expr.tp2 = __1pft)))
                                           : 0),
                                      __0__X119));
            {
                Pexpr __1r;

                __1r = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111, __1fee,
                                              (struct expr *)0);

                __1r->__O4__4expr.tp2 = (((struct type *)(((struct type *)__1f->f_this__3fct))));

                {
                    Pexpr __1nthis;

                    __1nthis = new_this__FP4exprT1(__1pp, __1ee);

                    __1args = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __1nthis,
                                                     __1args);
                    simpl__4exprFv(__1args);

                    {
                        Pcall __1c;

                        struct call *__0__X120;

                        struct expr *__2__X121;

                        struct expr *__2__X122;

                        __1c = ((__0__X120 = 0),
                                ((__2__X121 = __1r),
                                 ((__2__X122 = __1args),
                                  (((__0__X120 || (__0__X120 = (struct call *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct call)))))
                                        ? (__0__X120 = (struct call *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X120), (unsigned char)109,
                                               __2__X121, __2__X122))
                                        : 0),
                                   __0__X120))));
                        __1c->__O1__4expr.tp = __1f->returns__3fct;
                        return __1c;
                    }
                }
            }
        }
    }
}

Ptype deref__4typeFv(struct type *__0this);

bit not_simple__4exprFi(struct expr *__0this, int __1inflag);

extern int has_virt__FP8classdef(Pclass);

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

extern Pname k_find_name__FPCcP6ktableUc(const char *, Pktab, TOK);

extern char *make_name__FUc(TOK);

Pname dcl__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

void assign__4nameFv(struct name *__0this);

Pexpr expand__3fctFP4nameP5tableP4expr(struct fct *__0this, Pname, Ptable, Pexpr);

extern void uninline__FP4name(Pname __2fn);

extern void expand_itor__FP8classdef(Pclass);

void simpl__4callFv(register struct call *__0this) {
    Pname __1fn;

    Pfct __1f;

    __1fn = __0this->__O4__4expr.fct_name;

    __1f =
        (__1fn ? (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp)))) : (((struct fct *)0)));

    if (__1fn == 0)
        simpl__4exprFv(__0this->__O2__4expr.e1);

    if (__1f) {
        if (__1fn->base__4node == 162) {
            __0this->base__4node = 150;
            __0this->__O2__4expr.i1 = 0;
            if (__0this->__O2__4expr.e1 && (__0this->__O2__4expr.e1->permanent__4node == 0))
                del__4exprFv(__0this->__O2__4expr.e1);

            if (__0this->__O3__4expr.e2 && (__0this->__O3__4expr.e2->permanent__4node == 0))
                del__4exprFv(__0this->__O3__4expr.e2);
            __0this->__O2__4expr.e1 = 0;

            __0this->__O3__4expr.e2 = 0;
            return;
        }

        if (((__1f->fct_base__3fct == 4) && curr_fct) &&
            (strcmp(curr_fct->__O2__4expr.string, __1fn->__O2__4expr.string) == 0))
            __0this->__O4__4expr.fct_name = (__1fn = curr_fct);

        switch (__1f->base__4node) {
        case 141:
            return;
        case 76:
            __0this->__O4__4expr.fct_name =
                (__1fn = (((struct gen *)(((struct gen *)__1f))))->fct_list__3gen->f__9name_list);
            __1f = (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))));
        }
    }

    switch (__0this->__O2__4expr.e1->base__4node) {
    case 173: {
        Pexpr __3p;
        Pexpr __3q;
        Pclass __3cl;
        Pfct __3f;

        __3p = __0this->__O2__4expr.e1->__O2__4expr.e1;
        __3q = __0this->__O2__4expr.e1->__O3__4expr.e2;
        __3cl =
            (((struct classdef *)(((struct classdef *)__0this->__O2__4expr.e1->__O4__4expr.tp2))));
        __3f = (((struct fct *)(((struct fct *)deref__4typeFv(__3q->__O1__4expr.tp)))));

        if (__0this->__O3__4expr.e2)
            simpl__4exprFv(__0this->__O3__4expr.e2);

        if (__3f->f_this__3fct == 0) {
            struct classdef *__1__X129;

            struct classdef *__1__X130;

            if (__3f->memof__3fct == 0)
                error__FiPCc((int)'i', (const char *)"memof missing");

            if ((__3f->memof__3fct->class_base__8classdef == 2) &&
                ((__1__X129 = __3cl),
                 ((__1__X130 = __3f->memof__3fct),
                  (((__1__X129 == __1__X130)
                        ? 1
                        : ((__1__X129 && __1__X130)
                               ? (((int)same_class__8classdefFP8classdefi(__1__X129, __1__X130, 0)))
                               : 0))))))
                __3f->memof__3fct = __3cl;
            {
                Pname __4tt;

                __4tt = __ct__4nameFPCc((struct name *)0, (const char *)"this");
                __4tt->n_scope__4name = 136;
                __4tt->__O1__4expr.tp = __3f->memof__3fct->this_type__8classdef;
                __4tt->permanent__4node = 1;

                __4tt->__O1__4name.n_list = __3f->argtype__3fct;

                __4tt->__O1__4name.n_list =
                    (__3f->f_result__3fct ? __3f->f_result__3fct : __3f->argtype__3fct);
                __3f->f_this__3fct = (__3f->f_args__3fct = __4tt);
            }
        }

        ;

        nin = 1;
        if (not_simple__4exprFi(__3q, 0))
            error__FiPCc((int)'s', (const char *)"2nd operand of .* too complicated");
        nin = 0;

        {
            Pexpr __3qq;

            register struct cast *__0__X131;

            struct type *__2__X132;

            register struct mdot *__0__X138;

            __3qq =
                (struct expr *)((__0__X138 = 0),
                                (((__0__X138 || (__0__X138 = (struct mdot *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct mdot)))))
                                      ? ((__0__X138 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X138), (unsigned char)177,
                                              (struct expr *)0, (struct expr *)0)),
                                         ((__0__X138->__O3__4expr.string2 = ((const char *)"f")),
                                          (__0__X138->__O4__4expr.mem = __3q)))
                                      : 0),
                                 __0__X138));
            __3qq->__O2__4expr.i1 = 9;
            __3qq =
                (struct expr *)((__0__X131 = 0),
                                ((__2__X132 = (struct type *)(__ct__3ptrFUcP4type(
                                      (struct ptr *)0, (unsigned char)125, ((struct type *)__3f)))),
                                 (((__0__X131 || (__0__X131 = (struct cast *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct cast)))))
                                       ? ((__0__X131 = (struct cast *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X131), (unsigned char)191,
                                               __3qq, (struct expr *)0)),
                                          (__0__X131->__O1__4expr.tp =
                                               (__0__X131->__O4__4expr.tp2 = __2__X132)))
                                       : 0),
                                  __0__X131)));
            {
                Pexpr __3nc;

                __3nc = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111, __3qq,
                                               (struct expr *)0);
                __3nc->__O4__4expr.tp2 = (((struct type *)(((struct type *)__3f->f_this__3fct))));

                {
                    Pexpr __3nthis;
                    Pexpr __3args;

                    __3nthis = new_this__FP4exprT1(__3p, __3q);
                    __3args = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __3nthis,
                                                     __0this->__O3__4expr.e2);
                    imeasure += 3;

                    if (has_virt__FP8classdef(__3cl) == 0) {
                        if (__3cl->defined__4type == 0) {
                            struct ea __0__V124;

                            error__FPCcRC2eaN32(
                                (const char *)"call throughP toMF before definition ofC %t",
                                (const struct ea *)(((&__0__V124)->__O1__2ea.p =
                                                         ((const void *)__3cl)),
                                                    (&__0__V124)),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                        __0this->__O2__4expr.e1 = __3nc;
                        __0this->__O3__4expr.e2 = __3args;
                        return;
                    }

                    if (find_vptr__FP8classdef(__3cl) == 0) {
                        __0this->__O2__4expr.e1 = __3nc;
                        __0this->__O3__4expr.e2 = __3args;
                        return;
                    }

                    nin = 1;
                    if (not_simple__4exprFi(__3p, 0))
                        error__FiPCc((int)'s', (const char *)"1st operand of .* too complicated");
                    nin = 0;

                    {
                        Pexpr __3c;

                        register struct mdot *__0__X137;

                        __3c = (struct expr
                                    *)((__0__X137 = 0),
                                       (((__0__X137 || (__0__X137 = (struct mdot *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct mdot)))))
                                             ? ((__0__X137 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                     ((struct expr *)__0__X137), (unsigned char)177,
                                                     (struct expr *)0, (struct expr *)0)),
                                                ((__0__X137->__O3__4expr.string2 =
                                                      ((const char *)"i")),
                                                 (__0__X137->__O4__4expr.mem = __3q)))
                                             : 0),
                                        __0__X137));
                        __3c->__O2__4expr.i1 = 9;
                        __3c =
                            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)58, __3c, zero);

                        {
                            Pexpr __3ie;

                            struct call *__0__X133;

                            struct expr *__2__X134;

                            struct expr *__2__X135;

                            register struct mdot *__0__X136;

                            __3ie =
                                (struct expr
                                     *)((__0__X136 = 0),
                                        (((__0__X136 || (__0__X136 = (struct mdot *)__nw__4exprSFUl(
                                                             (size_t)(sizeof(struct mdot)))))
                                              ? ((__0__X136 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                      ((struct expr *)__0__X136),
                                                      (unsigned char)177, (struct expr *)0,
                                                      (struct expr *)0)),
                                                 ((__0__X136->__O3__4expr.string2 =
                                                       ((const char *)"i")),
                                                  (__0__X136->__O4__4expr.mem = __3q)))
                                              : 0),
                                         __0__X136));
                            __3ie->__O2__4expr.i1 = 9;

                            __0this->base__4node = 68;
                            __0this->__O2__4expr.e1 =
                                (struct expr *)((__0__X133 = 0),
                                                ((__2__X134 = __3nc),
                                                 ((__2__X135 = __3args),
                                                  (((__0__X133 ||
                                                     (__0__X133 = (struct call *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct call)))))
                                                        ? (__0__X133 = (struct call *)
                                                               __ct__4exprFUcP4exprT2(
                                                                   ((struct expr *)__0__X133),
                                                                   (unsigned char)109, __2__X134,
                                                                   __2__X135))
                                                        : 0),
                                                   __0__X133))));
                            __0this->__O3__4expr.e2 =
                                (struct expr *)vcall__FP4exprT1P3fctP8classdefT1(
                                    __3p, __3ie, __3f, __3cl, __0this->__O3__4expr.e2);
                            __0this->__O4__4expr.cond = __3c;
                            return;
                        }
                    }
                }
            }
        }
    }
    case 45:
    case 44: {
        Pref __3r;
        Pexpr __3a1;
        int __3obj;

        __3r = (((struct ref *)(((struct ref *)__0this->__O2__4expr.e1))));
        __3a1 = __3r->__O2__4expr.e1;
        __3obj = (__3r->__O3__4expr.n_initializer != 0);

        if (__3obj == 0) {
            if ((__0this->__O2__4expr.e1->base__4node == 45) && (__3a1->base__4node != 111))
                __3obj = 1;
            if (((__0this->__O2__4expr.e1->base__4node == 45) && (__3a1->base__4node == 111)) &&
                (((__3a1->__O2__4expr.e1->base__4node == 85) &&
                  (((struct name *)(((struct name *)__3a1->__O2__4expr.e1))))->n_xref__4name) ||
                 (__3a1->__O2__4expr.e1->__O1__4expr.tp &&
                  (__3a1->__O2__4expr.e1->__O1__4expr.tp->base__4node == 110))))
                __3obj = 1;
            if (__3a1->base__4node == 177) {
                Pexpr __5eee;

                __5eee = __3a1;
                while (__5eee->base__4node == 177)
                    __5eee = (struct expr *)((
                        (struct name *)(((struct name *)(((struct ref *)(((struct ref *)__5eee))))
                                             ->__O4__4expr.mem))));
                if (__5eee->base__4node == 111)
                    __3obj = 0;
            }
        }

        if ((__1f && (__3obj == 0)) && __1f->f_virtual__3fct) {
            Pexpr __4a11;
            Ptype __4tmp_type;

            __4a11 = 0;
            __4tmp_type = 0;

            switch (__3a1->base__4node) {
            case 177: {
                if ((__3a1->__O2__4expr.i1 == 2) || (__3a1->__O2__4expr.i1 == 3)) {
                    Pname __7n;

                    __7n = k_find_name__FPCcP6ktableUc(__3a1->__O3__4expr.string2, Ctbl,
                                                       (unsigned char)159);
                    if ((__7n && __7n->__O1__4expr.tp) &&
                        (__7n->__O1__4expr.tp->base__4node == 119)) {
                        __4tmp_type = (struct type *)__ct__3ptrFUcP4type(
                            (struct ptr *)0, (unsigned char)125,
                            (struct type *)((
                                (struct classdef *)(((struct classdef *)__7n->__O1__4expr.tp)))));
                        break;
                    }
                }
                __4a11 = __3a1;
                break;
            }
            case 85:
                __4a11 = __3a1;
                break;
            case 44:
            case 45:
                if ((__3a1->__O2__4expr.e1->base__4node == 85) ||
                    (((__3a1->__O2__4expr.e1->base__4node == 45) ||
                      (__3a1->__O2__4expr.e1->base__4node == 44)) &&
                     (__3a1->__O2__4expr.e1->__O2__4expr.e1->base__4node == 85)))
                    __4a11 = __3a1;
                break;
            case 112:
            case 145:
                if ((__3a1->__O3__4expr.e2->base__4node == 85) ||
                    (((__3a1->__O3__4expr.e2->base__4node == 45) ||
                      (__3a1->__O3__4expr.e2->base__4node == 44)) &&
                     (__3a1->__O3__4expr.e2->__O2__4expr.e1->base__4node == 85)))
                    __4a11 = __3a1;
                break;
            case 113:
            case 191:
                switch (__3a1->__O2__4expr.e1->base__4node) {
                case 85:
                case 177:
                    __4a11 = __3a1;
                }
            }

            if (__0this->__O2__4expr.e1->base__4node == 45) {
                if (__4a11)
                    __4a11 = address__4exprFv(__4a11);
                __3a1 = address__4exprFv(__3a1);
            }

            {
                Pcall __4This;

                __4This = __0this;
                if (__4a11 == 0) {
                    if (__3a1->base__4node == 85)
                        __4a11 = __3a1;
                    else {
                        Pname __6nx;

                        __6nx = __ct__4nameFPCc((struct name *)0,
                                                (const char *)make_name__FUc((unsigned char)'K'));
                        __6nx->__O1__4expr.tp = (__4tmp_type ? __4tmp_type : __3a1->__O1__4expr.tp);
                        {
                            Pname __6n;

                            __6n = dcl__4nameFP5tableUc(__6nx, scope, (unsigned char)136);
                            ((__6nx
                                  ? (((void)(__6nx
                                                 ? (((void)((((((struct expr *)__6nx))
                                                                  ? (((void)((((struct expr *)
                                                                                   __6nx))
                                                                                 ? (((void)((
                                                                                       (void)0))))
                                                                                 : (((void)0)))))
                                                                  : (((void)0)))),
                                                            (((void)__dl__4nameSFPvUl(
                                                                (void *)__6nx,
                                                                (size_t)(sizeof(struct name))))))))
                                                 : (((void)0)))))
                                  : (((void)0))));
                            {
                                Pname __6cln;

                                __6cln = is_cl_obj__4typeFv(__3a1->__O1__4expr.tp);
                                if (__6cln) {
                                    Pclass __7cl;

                                    __7cl = (((struct classdef *)((
                                        (struct classdef *)__6cln->__O1__4expr.tp))));
                                    if ((Ntmp == 0) && (__7cl->c_dtor__8classdef))
                                        Ntmp = __6cln;
                                    if ((__7cl->c_itor__8classdef))
                                        __6n->n_xref__4name = 1;
                                }
                                __6n->n_scope__4name = 108;
                                assign__4nameFv(__6n);
                                __4a11 = (struct expr *)__6n;
                                __3a1 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                               (struct expr *)__6n, __3a1);
                                if (ansi_opt)
                                    (((struct basetype *)((
                                         (struct basetype *)__6n->__O1__4expr.tp))))
                                        ->ansi_const__4type = 1;
                                __3a1->__O1__4expr.tp = __6n->__O1__4expr.tp;
                                simpl__4exprFv(__3a1);
                                {
                                    Pcall __6cc;

                                    struct call *__0__X139;

                                    struct expr *__2__X140;

                                    struct expr *__2__X141;

                                    __6cc = ((__0__X139 = 0),
                                             ((__2__X140 = 0),
                                              ((__2__X141 = 0),
                                               (((__0__X139 ||
                                                  (__0__X139 = (struct call *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct call)))))
                                                     ? (__0__X139 =
                                                            (struct call *)__ct__4exprFUcP4exprT2(
                                                                ((struct expr *)__0__X139),
                                                                (unsigned char)109, __2__X140,
                                                                __2__X141))
                                                     : 0),
                                                __0__X139))));
                                    ((*__6cc)) = (*__0this);
                                    __0this->base__4node = 71;
                                    __0this->__O2__4expr.e1 = __3a1;
                                    __0this->__O3__4expr.e2 = (struct expr *)__6cc;
                                    __4This = __6cc;
                                }
                            }
                        }
                    }
                }

                {
                    int __4i;
                    Pexpr __4ie;
                    Pname __4cn;

                    struct ival *__0__X142;

                    __4i = __1f->f_virtual__3fct;
                    __4ie =
                        (struct expr
                             *)(__4i
                                    ? ((__0__X142 = 0),
                                       (((__0__X142 || (__0__X142 = (struct ival *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct ival)))))
                                             ? ((__0__X142 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                     ((struct expr *)__0__X142), (unsigned char)150,
                                                     (struct expr *)0, (struct expr *)0)),
                                                (__0__X142->__O2__4expr.i1 = ((long long)__4i)))
                                             : 0),
                                        __0__X142))
                                    : (((struct ival *)0)));
                    __4cn = __1fn->__O4__4expr.n_table->t_name__5table;
                    if (((((__1fn && __1fn->__O3__4expr.n_initializer) && cc->nof__11dcl_context) &&
                          ((cc->nof__11dcl_context->n_oper__4name == 161) ||
                           (cc->nof__11dcl_context->n_oper__4name == 162))) &&
                         (((struct fct *)(((struct fct *)cc->nof__11dcl_context->__O1__4expr.tp))))
                             ->memof__3fct->c_abstract__8classdef) &&
                        (strcmp((((struct fct *)((
                                     (struct fct *)cc->nof__11dcl_context->__O1__4expr.tp))))
                                    ->memof__3fct->string__8classdef,
                                __4cn->__O2__4expr.string) == 0)) {
                        Pexpr __5ee;

                        __5ee = __4This->__O2__4expr.e1->__O2__4expr.e1;
                        while (__5ee && (__5ee->base__4node != 85))
                            __5ee = __5ee->__O2__4expr.e1;
                        if (__5ee && (strcmp(__5ee->__O2__4expr.string, (const char *)"this") == 0))
                            if (cc->nof__11dcl_context->n_oper__4name == 161) {
                                struct ea __0__V125;

                                struct ea __0__V126;

                                error__FPCcRC2eaN32(
                                    (const char *)"call of pure virtualF%n inK%n",
                                    (const struct ea *)(((&__0__V125)->__O1__2ea.p =
                                                             ((const void *)__1fn)),
                                                        (&__0__V125)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V126, (const void *)cc->nof__11dcl_context),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            } else {
                                struct ea __0__V127;

                                struct ea __0__V128;

                                error__FPCcRC2eaN32(
                                    (const char *)"call of pure virtualF%n in destructor%n",
                                    (const struct ea *)(((&__0__V127)->__O1__2ea.p =
                                                             ((const void *)__1fn)),
                                                        (&__0__V127)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V128, (const void *)cc->nof__11dcl_context),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                    }
                    vfunt_name = __1fn;
                    {
                        Pcall __4vc;

                        __4vc = vcall__FP4exprT1P3fctP8classdefT1(
                            __4a11, __4ie, __1f,
                            ((struct classdef *)(((struct classdef *)__4cn->__O1__4expr.tp))),
                            __4This->__O3__4expr.e2);
                        vfunt_name = 0;
                        ((*__4This)) = (*__4vc);
                        return;
                    }
                }
            }
        }

        {
            Ptype __3tt;

            __3tt = __3r->__O4__4expr.mem->__O1__4expr.tp;
        llp:
            if (__3tt)
                switch (__3tt->base__4node) {
                case 97:
                    __3tt = (((struct basetype *)(((struct basetype *)__3tt))))
                                ->b_name__8basetype->__O1__4expr.tp;
                    goto llp;
                case 76:
                case 108:
                    if (__0this->__O4__4expr.fct_name == 0) {
                        __0this->__O4__4expr.fct_name =
                            (__1fn = (((struct name *)(((struct name *)__0this->__O2__4expr.e1
                                                            ->__O3__4expr.n_initializer)))));

                        if (__1fn)
                            __1f = (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))));
                    }

                    if (__0this->__O2__4expr.e1->base__4node == 45)
                        __3a1 = address__4exprFv(__3a1);
                    __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                        (struct expr *)0, (unsigned char)140, __3a1, __0this->__O3__4expr.e2);
                    __0this->__O2__4expr.e1 = __3r->__O4__4expr.mem;
                }
        }
    }
    }

    if (__0this->__O3__4expr.e2)
        simpl__4exprFv(__0this->__O3__4expr.e2);

    if ((__1fn && __1f->f_inline__3fct) && (debug_opt == 0)) {
        imeasure += __1f->f_imeasure__3fct;
        {
            Pclass __2cl;

            __2cl = __1f->memof__3fct;
            if (__2cl && __2cl->c_body__8classdef)
                dcl_print__8classdefFP4name(__2cl, (struct name *)0);
            {
                Ptable __2oscope;
                Pexpr __2ee;

                __2oscope = scope;
                __2ee =
                    expand__3fctFP4nameP5tableP4expr(__1f, __1fn, scope, __0this->__O3__4expr.e2);
                scope = __2oscope;
                if (__2ee)
                    ((*(((struct expr *)(((struct expr *)__0this)))))) = (*__2ee);
            }
        }
    } else if ((__1fn && (__1f->f_inline__3fct == 0)) && __1f->f_imeasure__3fct) {
        uninline__FP4name(__1fn);
        imeasure += 3;
    } else if ((__1fn && debug_opt) && (__1f->f_inline__3fct == 77)) {
        expand_itor__FP8classdef(__1f->memof__3fct);
    } else
        imeasure += 3;
}

void uninline__FP4name(Pname __1fn) {
    Pfct __1f;

    __1f = (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))));

    if (warning_opt) {
        {
            struct ea __0__V143;

            error__FiPCcRC2eaN33(
                (int)'w', (const char *)"%n too complex for inlining",
                (const struct ea *)(((&__0__V143)->__O1__2ea.p = ((const void *)__1fn)),
                                    (&__0__V143)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            {
                struct ea __0__V144;

                error__FiPCcRC2eaN33(
                    (int)'w', (const char *)"out-of-line copy of %n created",
                    (const struct ea *)(((&__0__V144)->__O1__2ea.p = ((const void *)__1fn)),
                                        (&__0__V144)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }
    }
    __1f->f_imeasure__3fct = 0;

    if (__1f->body__3fct == 0)
        return;

    {
        Pstmt __1s;

        __1s = __1f->body__3fct->s__4stmt;

        while (__1s) {
            if (__1s->base__4node == 72) {
                Pexpr __3e;

                __3e = __1s->__O2__4stmt.e;
                if (__3e)
                    switch (__3e->base__4node) {
                    case 71:
                    case 147: {
                        Pstmt __5ss;

                        struct estmt *__0__X145;

                        struct loc __2__X146;

                        struct expr *__2__X147;

                        __5ss = (struct stmt *)((__0__X145 = 0),
                                                ((__2__X146 = no_where),
                                                 ((__2__X147 = __3e->__O3__4expr.e2),
                                                  (((__0__X145 ||
                                                     (__0__X145 = (struct estmt *)__nw__4stmtSFUl(
                                                          (size_t)(sizeof(struct estmt)))))
                                                        ? ((__0__X145 = (struct estmt *)
                                                                __ct__4stmtFUc3locP4stmt(
                                                                    ((struct stmt *)__0__X145),
                                                                    ((unsigned char)72), __2__X146,
                                                                    ((struct stmt *)0))),
                                                           (__0__X145->__O2__4stmt.e = __2__X147))
                                                        : 0),
                                                   __0__X145))));
                        __1s->__O2__4stmt.e = __3e->__O2__4expr.e1;
                        __5ss->s_list__4stmt = __1s->s_list__4stmt;
                        __1s->s_list__4stmt = __5ss;
                        ((__3e
                              ? (((void)(__3e ? (((void)(((void)__dl__4exprSFPvUl(
                                                    (void *)__3e, (size_t)(sizeof(struct expr)))))))
                                              : (((void)0)))))
                              : (((void)0))));
                        continue;
                    }
                    }
            }
            __1s = __1s->s_list__4stmt;
        }

        dcl_print__4nameFUc(__1fn, (unsigned char)0);
    }
}

void temp_in_cond__FP4exprP4stmtP5table(Pexpr __1ee, Pstmt __1ss, Ptable __1tbl) {
    while ((__1ee->base__4node == 71) || (__1ee->base__4node == 147))
        __1ee = __1ee->__O3__4expr.e2;
    {
        Ptype __1ct;
        Pname __1n;

        __1ct = unconst_type__FP4type(__1ee->__O1__4expr.tp);
        __1n = __ct__4nameFPCc((struct name *)0, (const char *)make_name__FUc((unsigned char)'Q'));
        __1n->__O1__4expr.tp = __1ct;
        {
            Pname __1tmp;

            __1tmp = dcl__4nameFP5tableUc(__1n, __1tbl, (unsigned char)136);
            ((__1n ? (((void)(__1n ? (((void)((((((struct expr *)__1n))
                                                    ? (((void)((((struct expr *)__1n))
                                                                   ? (((void)(((void)0))))
                                                                   : (((void)0)))))
                                                    : (((void)0)))),
                                              (((void)__dl__4nameSFPvUl(
                                                  (void *)__1n, (size_t)(sizeof(struct name))))))))
                                   : (((void)0)))))
                   : (((void)0))));
            __1tmp->n_scope__4name = 108;

            {
                Pexpr __1v;

                register struct cast *__0__X148;

                __1v = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)0, (struct expr *)0,
                                              (struct expr *)0);
                ((*__1v)) = (*__1ee);
                __1ct->permanent__4node = 1;
                __1v = (struct expr *)((__0__X148 = 0),
                                       (((__0__X148 || (__0__X148 = (struct cast *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct cast)))))
                                             ? ((__0__X148 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                     ((struct expr *)__0__X148), (unsigned char)191,
                                                     __1v, (struct expr *)0)),
                                                (__0__X148->__O1__4expr.tp =
                                                     (__0__X148->__O4__4expr.tp2 = __1ct)))
                                             : 0),
                                        __0__X148));

                __1tmp->n_assigned_to__4name = 1;
                {
                    Pexpr __1c;

                    __1c = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                  (struct expr *)__1tmp, __1v);
                    __1c->__O1__4expr.tp = __1ct;
                    __1ee->base__4node = 71;
                    __1ee->__O2__4expr.e1 = __1c;

                    {
                        Pexpr __1ex;

                        __1ex = 0;

                        {
                            {
                                Pstmt __1sx;

                                __1sx = __1ss;

                                for (; __1sx; __1sx = __1sx->s_list__4stmt) {
                                    if (__1ex) {
                                        __1ex = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                       (unsigned char)71, __1ex,
                                                                       __1sx->__O2__4stmt.e);
                                        __1ex->__O1__4expr.tp =
                                            __1sx->__O2__4stmt.e->__O1__4expr.tp;
                                    } else
                                        __1ex = __1sx->__O2__4stmt.e;
                                }
                                __1ee->__O3__4expr.e2 =
                                    __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71,
                                                           __1ex, (struct expr *)__1tmp);
                                __1ee->__O3__4expr.e2->__O1__4expr.tp = __1ct;
                            }
                        }
                    }
                }
            }
        }
    }
}

bit not_safe__FP4expr(Pexpr __1e);

bit not_safe__FP4expr(Pexpr __1e) {
    switch (__1e->base__4node) {
    default:
        return (unsigned char)1;

    case 85: {
        Pname __3n;

        __3n = (((struct name *)(((struct name *)__1e))));
        if ((__3n->__O4__4expr.n_table != gtbl) &&
            (__3n->__O4__4expr.n_table->t_name__5table == 0)) {
            Pname __4cn;

            struct classdef *__0__X149;

            __4cn = is_cl_obj__4typeFv(__3n->__O1__4expr.tp);
            if (__4cn &&
                ((__0__X149 = (((struct classdef *)(((struct classdef *)__4cn->__O1__4expr.tp))))),
                 (__0__X149->c_dtor__8classdef)))
                return (unsigned char)1;
        }
    }
    case 150:
    case 82:
    case 84:
    case 83:
    case 81:
        return (unsigned char)0;
    case 46:
    case 47:
    case 112:
    case 145:
        return not_safe__FP4expr(__1e->__O3__4expr.e2);
    case 111: {
        int __3i;

        __3i = not_safe__FP4expr(__1e->__O2__4expr.e1);
        if (__3i)
            return (unsigned char)__3i;
        if (__1e->__O3__4expr.e2)
            return not_safe__FP4expr(__1e->__O3__4expr.e2);
        return (unsigned char)0;
    }
    case 71:
    case 54:
    case 55:
    case 50:
    case 51:
    case 53:
    case 70:
    case 126:
    case 127:
    case 128:
    case 129:
    case 65:
    case 52:
    case 67:
    case 66:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
        return (unsigned char)(not_safe__FP4expr(__1e->__O2__4expr.e1) ||
                               not_safe__FP4expr(__1e->__O3__4expr.e2));
    case 68:
        return (unsigned char)((not_safe__FP4expr(__1e->__O4__4expr.cond) ||
                                not_safe__FP4expr(__1e->__O2__4expr.e1)) ||
                               not_safe__FP4expr(__1e->__O3__4expr.e2));
    }
}

Pexpr curr_expr = 0;

Pstmt copy__4stmtFv(struct stmt *__0this);

extern Pexpr replace_temp__FP4exprT1(Pexpr, Pexpr);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

extern void check_visibility__FP4nameT1P8classdefP5tableT1(Pname, Pname, Pclass, Ptable, Pname);

Pname has_oper__8classdefFUc(struct classdef *__0this, TOK);

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

Pstmt simpl__4stmtFv(register struct stmt *__0this) {
    if (__0this == 0)
        error__FiPCc((int)'i', (const char *)"0->S::simpl()");

    ;

    stmtno++;
    if (__0this->__O2__4stmt.e)
        curr_expr = __0this->__O2__4stmt.e;

    Ntmp_tbl = ((__0this->base__4node != 116) ? __0this->memtbl__4stmt : (((struct table *)0)));

    switch (__0this->base__4node) {
        unsigned long __2__X156;

    default: {
        struct ea __0__V150;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"S::simpl(%k)",
            (const struct ea *)((__2__X156 = __0this->base__4node),
                                (((((&__0__V150)->__O1__2ea.i = __2__X156), 0)), (&__0__V150))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

    case 1:
        break;

    case 3:
        if (break_del_list) {
            Pstmt __3bs;
            Pstmt __3dl;

            struct pair *__0__X157;

            struct loc __2__X158;

            struct stmt *__2__X159;

            struct stmt *__2__X160;

            __3bs = __ct__4stmtFUc3locP4stmt((struct stmt *)0, __0this->base__4node,
                                             __0this->where__4stmt, (struct stmt *)0);
            __3dl = copy__4stmtFv(break_del_list);
            __0this->base__4node = 116;
            __0this->s__4stmt =
                (struct stmt *)((__0__X157 = 0),
                                ((__2__X158 = __0this->where__4stmt),
                                 ((__2__X159 = __3dl),
                                  ((__2__X160 = __3bs),
                                   (((__0__X157 || (__0__X157 = (struct pair *)__nw__4stmtSFUl(
                                                        (size_t)(sizeof(struct pair)))))
                                         ? ((__0__X157 = (struct pair *)__ct__4stmtFUc3locP4stmt(
                                                 ((struct stmt *)__0__X157), (unsigned char)166,
                                                 __2__X158, __2__X159)),
                                            (__0__X157->__O2__4stmt.s2 = __2__X160))
                                         : 0),
                                    __0__X157)))));
        }
        break;

    case 7:
        if (continue_del_list) {
            Pstmt __3bs;
            Pstmt __3dl;

            struct pair *__0__X161;

            struct loc __2__X162;

            struct stmt *__2__X163;

            struct stmt *__2__X164;

            __3bs = __ct__4stmtFUc3locP4stmt((struct stmt *)0, __0this->base__4node,
                                             __0this->where__4stmt, (struct stmt *)0);
            __3dl = copy__4stmtFv(continue_del_list);
            __0this->base__4node = 116;
            __0this->s__4stmt =
                (struct stmt *)((__0__X161 = 0),
                                ((__2__X162 = __0this->where__4stmt),
                                 ((__2__X163 = __3dl),
                                  ((__2__X164 = __3bs),
                                   (((__0__X161 || (__0__X161 = (struct pair *)__nw__4stmtSFUl(
                                                        (size_t)(sizeof(struct pair)))))
                                         ? ((__0__X161 = (struct pair *)__ct__4stmtFUc3locP4stmt(
                                                 ((struct stmt *)__0__X161), (unsigned char)166,
                                                 __2__X162, __2__X163)),
                                            (__0__X161->__O2__4stmt.s2 = __2__X164))
                                         : 0),
                                    __0__X161)))));
        }
        break;

    case 8:
        simpl__4stmtFv(__0this->s__4stmt);
        break;

    case 72:
        if (__0this->__O2__4stmt.e) {
            if (__0this->__O2__4stmt.e->base__4node == 111)
                __0this->__O2__4stmt.e = __0this->__O2__4stmt.e->__O2__4expr.e1;
            simpl__4exprFv(__0this->__O2__4stmt.e);
            if (__0this->__O2__4stmt.e->base__4node == 111)
                __0this->__O2__4stmt.e = __0this->__O2__4stmt.e->__O2__4expr.e1;
            if (__0this->__O2__4stmt.e->base__4node == 124)
                __0this->__O2__4stmt.e = 0;
        }
        break;

    case 28: {
        no_of_returns++;

        {
            Pstmt __3dl;
            Pfct __3f;

            __3dl = (del_list ? copy__4stmtFv(del_list) : (((struct stmt *)0)));
            __3f = (((struct fct *)(((struct fct *)curr_fct->__O1__4expr.tp))));

            if (__0this->__O2__4stmt.e == 0)
                __0this->__O2__4stmt.e = dummy;
            if ((__0this->__O2__4stmt.e == dummy) && (curr_fct->n_oper__4name == 161))
                __0this->__O2__4stmt.e = (struct expr *)__3f->f_this__3fct;

            {
                Pexpr __3tt;

                __3tt = __0this->__O2__4stmt.e;
                while ((__3tt->base__4node == 113) || (__3tt->base__4node == 191))
                    __3tt = __3tt->__O2__4expr.e1;
                if (__3tt->base__4node == 124)
                    __0this->__O2__4stmt.e = __3tt;

                if (__0this->__O2__4stmt.e->base__4node == 124) {
                    extern Pbase mptr_type;

                    Ptable __4ftbl;
                    Pname __4temp;

                    __4ftbl = (((struct fct *)(((struct fct *)curr_fct->__O1__4expr.tp))))
                                  ->body__3fct->memtbl__4stmt;
                    __4temp = make_tmp__FcP4typeP5table('A', (struct type *)mptr_type, __4ftbl);

                    __0this->__O2__4stmt.e =
                        mptr_assign__FP4exprT1((struct expr *)__4temp, __0this->__O2__4stmt.e);
                    __0this->__O2__4stmt.e =
                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                               __0this->__O2__4stmt.e, (struct expr *)__4temp);
                    __0this->__O2__4stmt.e->__O1__4expr.tp = (struct type *)mptr_type;
                }

                if (__3f->f_result__3fct) {
                    if (__0this->__O2__4stmt.e->base__4node == 147)
                        __0this->__O2__4stmt.e = replace_temp__FP4exprT1(
                            __0this->__O2__4stmt.e, (struct expr *)__3f->f_result__3fct);
                    if (__3f->nrv__3fct && return_nrv__FP4expr(__0this->__O2__4stmt.e))
                        __0this->__O2__4stmt.e = dummy;
                    simpl__4exprFv(__0this->__O2__4stmt.e);
                    {
                        Pstmt __4cs;

                        struct pair *__0__X165;

                        struct loc __2__X166;

                        struct stmt *__2__X167;

                        struct stmt *__2__X168;

                        struct estmt *__0__X169;

                        struct loc __2__X170;

                        struct estmt *__0__X171;

                        struct loc __2__X172;

                        struct expr *__2__X173;

                        __4cs = (struct stmt *)((__0__X171 = 0),
                                                ((__2__X172 = __0this->where__4stmt),
                                                 ((__2__X173 = __0this->__O2__4stmt.e),
                                                  (((__0__X171 ||
                                                     (__0__X171 = (struct estmt *)__nw__4stmtSFUl(
                                                          (size_t)(sizeof(struct estmt)))))
                                                        ? ((__0__X171 = (struct estmt *)
                                                                __ct__4stmtFUc3locP4stmt(
                                                                    ((struct stmt *)__0__X171),
                                                                    ((unsigned char)72), __2__X172,
                                                                    ((struct stmt *)0))),
                                                           (__0__X171->__O2__4stmt.e = __2__X173))
                                                        : 0),
                                                   __0__X171))));
                        if (__3dl)
                            __4cs =
                                (struct stmt *)((__0__X165 = 0),
                                                ((__2__X166 = __0this->where__4stmt),
                                                 ((__2__X167 = __4cs),
                                                  ((__2__X168 = __3dl),
                                                   (((__0__X165 ||
                                                      (__0__X165 = (struct pair *)__nw__4stmtSFUl(
                                                           (size_t)(sizeof(struct pair)))))
                                                         ? ((__0__X165 = (struct pair *)
                                                                 __ct__4stmtFUc3locP4stmt(
                                                                     ((struct stmt *)__0__X165),
                                                                     (unsigned char)166, __2__X166,
                                                                     __2__X167)),
                                                            (__0__X165->__O2__4stmt.s2 = __2__X168))
                                                         : 0),
                                                    __0__X165)))));
                        __0this->base__4node = 166;
                        __0this->s__4stmt = __4cs;
                        __0this->__O2__4stmt.s2 =
                            (struct stmt
                                 *)((__0__X169 = 0),
                                    ((__2__X170 = __0this->where__4stmt),
                                     (((__0__X169 || (__0__X169 = (struct estmt *)__nw__4stmtSFUl(
                                                          (size_t)(sizeof(struct estmt)))))
                                           ? ((__0__X169 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                   ((struct stmt *)__0__X169), ((unsigned char)28),
                                                   __2__X170, ((struct stmt *)0))),
                                              (__0__X169->__O2__4stmt.e = ((struct expr *)0)))
                                           : 0),
                                      __0__X169)));
                    }
                } else {
                    simpl__4exprFv(__0this->__O2__4stmt.e);
                    if (__3dl) {
                        if ((__0this->__O2__4stmt.e != dummy) &&
                            not_safe__FP4expr(__0this->__O2__4stmt.e)) {
                            Ptable __6ftbl;

                            Pname __6r;
                            bit __6was_ansi;

                            register struct cast *__0__X174;

                            struct type *__2__X175;

                            struct expr *__2__X176;

                            __6ftbl = (((struct fct *)(((struct fct *)curr_fct->__O1__4expr.tp))))
                                          ->body__3fct->memtbl__4stmt;

                            __6r = look__5tableFPCcUc(__6ftbl, (const char *)"_result",
                                                      (unsigned char)0);

                            __6was_ansi = 0;
                            if (__6r == 0) {
                                __6r = __ct__4nameFPCc((struct name *)0, (const char *)"_result");

                                __6r->__O1__4expr.tp =
                                    unconst_type__FP4type(__0this->__O1__4stmt.ret_tp);
                                __6was_ansi = (__6r->__O1__4expr.tp != __0this->__O1__4stmt.ret_tp);
                                {
                                    Pname __7rn;

                                    __7rn = dcl__4nameFP5tableUc(__6r, __6ftbl, (unsigned char)136);
                                    __7rn->n_scope__4name = 108;
                                    __7rn->where__4name = no_where;
                                    assign__4nameFv(__7rn);
                                    ((__6r
                                          ? (((void)(__6r
                                                         ? (((void)((((((struct expr *)__6r))
                                                                          ? (((void)((((struct expr
                                                                                            *)__6r))
                                                                                         ? (((void)(((
                                                                                               void)0))))
                                                                                         : (((void)0)))))
                                                                          : (((void)0)))),
                                                                    (((void)__dl__4nameSFPvUl(
                                                                        (void *)__6r,
                                                                        (size_t)(sizeof(
                                                                            struct name))))))))
                                                         : (((void)0)))))
                                          : (((void)0))));
                                    __6r = __7rn;
                                }
                            }
                            if (__6was_ansi)
                                __0this->__O2__4stmt.e =
                                    (struct expr
                                         *)((__0__X174 = 0),
                                            ((__2__X175 = __6r->__O1__4expr.tp),
                                             ((__2__X176 = __0this->__O2__4stmt.e),
                                              (((__0__X174 ||
                                                 (__0__X174 = (struct cast *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct cast)))))
                                                    ? ((__0__X174 =
                                                            (struct cast *)__ct__4exprFUcP4exprT2(
                                                                ((struct expr *)__0__X174),
                                                                (unsigned char)191, __2__X176,
                                                                (struct expr *)0)),
                                                       (__0__X174->__O1__4expr.tp =
                                                            (__0__X174->__O4__4expr.tp2 =
                                                                 __2__X175)))
                                                    : 0),
                                               __0__X174))));
                            {
                                Pexpr __6as;

                                __6as = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                               (struct expr *)__6r,
                                                               __0this->__O2__4stmt.e);
                                __6as->__O1__4expr.tp = __6r->__O1__4expr.tp;
                                {
                                    Pstmt __6cs;

                                    struct pair *__0__X177;

                                    struct loc __2__X178;

                                    struct stmt *__2__X179;

                                    struct stmt *__2__X180;

                                    struct estmt *__0__X185;

                                    struct loc __2__X186;

                                    __6cs =
                                        (struct stmt
                                             *)((__0__X185 = 0),
                                                ((__2__X186 = __0this->where__4stmt),
                                                 (((__0__X185 ||
                                                    (__0__X185 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                                       ? ((__0__X185 = (struct estmt *)
                                                               __ct__4stmtFUc3locP4stmt(
                                                                   ((struct stmt *)__0__X185),
                                                                   ((unsigned char)72), __2__X186,
                                                                   ((struct stmt *)0))),
                                                          (__0__X185->__O2__4stmt.e = __6as))
                                                       : 0),
                                                  __0__X185)));
                                    __6cs =
                                        (struct stmt
                                             *)((__0__X177 = 0),
                                                ((__2__X178 = __0this->where__4stmt),
                                                 ((__2__X179 = __6cs),
                                                  ((__2__X180 = __3dl),
                                                   (((__0__X177 ||
                                                      (__0__X177 = (struct pair *)__nw__4stmtSFUl(
                                                           (size_t)(sizeof(struct pair)))))
                                                         ? ((__0__X177 = (struct pair *)
                                                                 __ct__4stmtFUc3locP4stmt(
                                                                     ((struct stmt *)__0__X177),
                                                                     (unsigned char)166, __2__X178,
                                                                     __2__X179)),
                                                            (__0__X177->__O2__4stmt.s2 = __2__X180))
                                                         : 0),
                                                    __0__X177)))));
                                    __0this->base__4node = 166;
                                    __0this->s__4stmt = __6cs;
                                    {
                                        Pexpr __6eee;

                                        register struct cast *__0__X181;

                                        struct type *__2__X182;

                                        struct estmt *__0__X183;

                                        struct loc __2__X184;

                                        __6eee = (((struct expr *)(((struct expr *)__6r))));
                                        if (__6was_ansi)
                                            __6eee =
                                                (struct expr
                                                     *)((__0__X181 = 0),
                                                        ((__2__X182 = __0this->__O1__4stmt.ret_tp),
                                                         (((__0__X181 ||
                                                            (__0__X181 =
                                                                 (struct cast *)__nw__4exprSFUl((
                                                                     size_t)(sizeof(struct cast)))))
                                                               ? ((__0__X181 = (struct cast *)
                                                                       __ct__4exprFUcP4exprT2(
                                                                           ((struct expr *)
                                                                                __0__X181),
                                                                           (unsigned char)191,
                                                                           __6eee,
                                                                           (struct expr *)0)),
                                                                  (__0__X181->__O1__4expr.tp =
                                                                       (__0__X181->__O4__4expr.tp2 =
                                                                            __2__X182)))
                                                               : 0),
                                                          __0__X181)));

                                        __0this->__O2__4stmt.s2 =
                                            (struct stmt
                                                 *)((__0__X183 = 0),
                                                    ((__2__X184 = __0this->where__4stmt),
                                                     (((__0__X183 ||
                                                        (__0__X183 =
                                                             (struct estmt *)__nw__4stmtSFUl(
                                                                 (size_t)(sizeof(struct estmt)))))
                                                           ? ((__0__X183 = (struct estmt *)
                                                                   __ct__4stmtFUc3locP4stmt(
                                                                       ((struct stmt *)__0__X183),
                                                                       ((unsigned char)28),
                                                                       __2__X184,
                                                                       ((struct stmt *)0))),
                                                              (__0__X183->__O2__4stmt.e = __6eee))
                                                           : 0),
                                                      __0__X183)));
                                    }
                                }
                            }

                        } else {
                            struct estmt *__0__X187;

                            struct loc __2__X188;

                            struct expr *__2__X189;

                            __0this->base__4node = 166;
                            __0this->s__4stmt = __3dl;
                            __0this->__O2__4stmt.s2 =
                                (struct stmt *)((__0__X187 = 0),
                                                ((__2__X188 = __0this->where__4stmt),
                                                 ((__2__X189 = __0this->__O2__4stmt.e),
                                                  (((__0__X187 ||
                                                     (__0__X187 = (struct estmt *)__nw__4stmtSFUl(
                                                          (size_t)(sizeof(struct estmt)))))
                                                        ? ((__0__X187 = (struct estmt *)
                                                                __ct__4stmtFUc3locP4stmt(
                                                                    ((struct stmt *)__0__X187),
                                                                    ((unsigned char)28), __2__X188,
                                                                    ((struct stmt *)0))),
                                                           (__0__X187->__O2__4stmt.e = __2__X189))
                                                        : 0),
                                                   __0__X187))));
                        }
                        __0this->__O2__4stmt.s2->__O1__4stmt.ret_tp = __0this->__O1__4stmt.ret_tp;
                    }
                }

                break;
            }
        }
    }

    case 39:
    case 10:
        simpl__4exprFv(__0this->__O2__4stmt.e);
        {
            Pstmt __3obl;
            Pstmt __3ocl;

            __3obl = break_del_list;
            __3ocl = continue_del_list;
            break_del_list = 0;
            continue_del_list = 0;
            simpl__4stmtFv(__0this->s__4stmt);
            break_del_list = __3obl;
            continue_del_list = __3ocl;
        }
        break;

    case 33:
        simpl__4exprFv(__0this->__O2__4stmt.e);
        {
            Pstmt __3obl;

            __3obl = break_del_list;
            break_del_list = 0;
            simpl__4stmtFv(__0this->s__4stmt);
            break_del_list = __3obl;
        }
        switch (__0this->s__4stmt->base__4node) {
        case 72:
            if (__0this->s__4stmt->__O2__4stmt.e)
                goto df;
        case 8:
        case 115:
        case 4:
            if (__0this->s__4stmt->s__4stmt && (__0this->s__4stmt->s__4stmt->base__4node == 116))
                __0this->s__4stmt = __0this->s__4stmt->s__4stmt;
            else
                break;
        case 116:
            if (__0this->s__4stmt->s__4stmt)
                switch (__0this->s__4stmt->s__4stmt->base__4node) {
                case 3:
                case 4:
                case 115:
                case 8:
                    break;
                default:
                    goto df;
                }
            break;
        default:
        df:
            error__FP3locPCcRC2eaN33(&__0this->s__4stmt->where__4stmt,
                                     (const char *)"S orIdE not reached: (case label missing?)",
                                     (const struct ea *)ea0, (const struct ea *)ea0,
                                     (const struct ea *)ea0, (const struct ea *)ea0);
        }
        break;

    case 4:
        simpl__4exprFv(__0this->__O2__4stmt.e);
        simpl__4stmtFv(__0this->s__4stmt);
        break;

    case 115:
        if (del_list)
            error__FiPCc((int)'s', (const char *)"label in blockW destructors");
        simpl__4stmtFv(__0this->s__4stmt);
        break;

    case 19: {
        Pname __3n;

        const void *__2__X190;

        __3n = look__5tableFPCcUc(scope, __0this->__O1__4stmt.d->__O2__4expr.string,
                                  (unsigned char)115);
        if (__3n == 0) {
            struct ea __0__V151;

            error__FiP3locPCcRC2eaN34(
                (int)'i', &__0this->where__4stmt, (const char *)"label%n missing",
                (const struct ea *)((__2__X190 = (const void *)__0this->__O1__4stmt.d),
                                    (((&__0__V151)->__O1__2ea.p = __2__X190), (&__0__V151))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if ((__3n->__O2__4name.n_realscope != scope) && __3n->n_assigned_to__4name) {
            Ptable __4r;

            __4r = 0;

            {
                {
                    Ptable __4q;

                    __4q = __3n->__O2__4name.n_realscope;

                    for (; __4q != gtbl; __4q = __4q->next__5table) {
                        {
                            {
                                Ptable __5p;

                                __5p = scope;

                                for (; __5p != gtbl; __5p = __5p->next__5table) {
                                    if (__5p == __4q) {
                                        __4r = __5p;
                                        goto xyzzy;
                                    }
                                }
                            }
                        }
                    }

                xyzzy:
                    if (__4r == 0)
                        error__FiP3locPCcRC2eaN34((int)'i', &__0this->where__4stmt,
                                                  (const char *)"finding root of subtree",
                                                  (const struct ea *)ea0, (const struct ea *)ea0,
                                                  (const struct ea *)ea0, (const struct ea *)ea0);

                    {
                        {
                            Ptable __4p;

                            __4p = __3n->__O2__4name.n_realscope;

                            for (; __4p != __4r; __4p = __4p->next__5table)
                                if (__4p->init_stat__5table == 2) {
                                    const void *__2__X191;

                                    {
                                        struct ea __0__V152;

                                        error__FP3locPCcRC2eaN33(
                                            &__0this->where__4stmt, (const char *)"goto%n pastDWIr",
                                            (const struct ea *)((__2__X191 = (const void *)__0this
                                                                                 ->__O1__4stmt.d),
                                                                (((&__0__V152)->__O1__2ea.p =
                                                                      __2__X191),
                                                                 (&__0__V152))),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                        goto plugh;
                                    }
                                } else if (__4p->init_stat__5table == 0) {
                                    int __5i;
                                    {
                                        {
                                            Pname __5nn;

                                            int __2__X192;

                                            int __2__X194;

                                            __5nn = ((__2__X194 = (__5i = 1)),
                                                     ((((__2__X194 <= 0) ||
                                                        (__4p->free_slot__5table <= __2__X194))
                                                           ? (((struct name *)0))
                                                           : (__4p->entries__5table[__2__X194]))));

                                            for (; __5nn;
                                                 __5nn = (__5nn->n_tbl_list__4name
                                                              ? __5nn->n_tbl_list__4name
                                                              : ((__2__X192 = (++__5i)),
                                                                 ((((__2__X192 <= 0) ||
                                                                    (__4p->free_slot__5table <=
                                                                     __2__X192))
                                                                       ? (((struct name *)0))
                                                                       : (__4p->entries__5table
                                                                              [__2__X192]))))))
                                                if (__5nn->__O3__4expr.n_initializer ||
                                                    __5nn->n_evaluated__4name) {
                                                    const void *__2__X193;

                                                    {
                                                        struct ea __0__V153;

                                                        struct ea __0__V154;

                                                        error__FP3locPCcRC2eaN33(
                                                            &__5nn->where__4name,
                                                            (const char *)"goto%n pastId%n",
                                                            (const struct ea
                                                                 *)((__2__X193 =
                                                                         (const void *)__0this
                                                                             ->__O1__4stmt.d),
                                                                    (((&__0__V153)->__O1__2ea.p =
                                                                          __2__X193),
                                                                     (&__0__V153))),
                                                            (const struct ea
                                                                 *)(((&__0__V154)->__O1__2ea.p =
                                                                         ((const void *)__5nn)),
                                                                    (&__0__V154)),
                                                            (const struct ea *)ea0,
                                                            (const struct ea *)ea0);
                                                        goto plugh;
                                                    }
                                                }
                                        }
                                    }
                                }
                        plugh: {
                            Pstmt __5dd;

                            Pstmt __5ddt;

                            __5dd = 0;

                            __5ddt = 0;

                            {
                                {
                                    Ptable __5p;

                                    __5p = scope;

                                    for (; __5p != __4r; __5p = __5p->next__5table) {
                                        int __6i;
                                        {
                                            {
                                                Pname __6n;

                                                int __2__X195;

                                                int __2__X201;

                                                __6n =
                                                    ((__2__X201 = (__6i = 1)),
                                                     ((((__2__X201 <= 0) ||
                                                        (__5p->free_slot__5table <= __2__X201))
                                                           ? (((struct name *)0))
                                                           : (__5p->entries__5table[__2__X201]))));

                                                for (; __6n;
                                                     __6n = (__6n->n_tbl_list__4name
                                                                 ? __6n->n_tbl_list__4name
                                                                 : ((__2__X195 = (++__6i)),
                                                                    ((((__2__X195 <= 0) ||
                                                                       (__5p->free_slot__5table <=
                                                                        __2__X195))
                                                                          ? (((struct name *)0))
                                                                          : (__5p->entries__5table
                                                                                 [__2__X195])))))) {
                                                    Pname __7cln;
                                                    if (__6n->__O1__4expr.tp == 0)
                                                        continue;

                                                    {
                                                        int __7dtor;

                                                        __7dtor = 1;
                                                        if (inllist) {
                                                            {
                                                                {
                                                                    Plist __8nl;

                                                                    __8nl = inllist;

                                                                    for (; __8nl;
                                                                         __8nl =
                                                                             __8nl->l__9name_list)
                                                                        if (__6n ==
                                                                            __8nl->f__9name_list)
                                                                            __7dtor = 0;
                                                                }
                                                            }
                                                        }

                                                        if (__7cln = is_cl_obj__4typeFv(
                                                                __6n->__O1__4expr.tp)) {
                                                            Pclass __8cl;
                                                            Pname __8d;

                                                            __8cl = (((struct classdef *)((
                                                                (struct classdef *)
                                                                    __7cln->__O1__4expr.tp))));
                                                            __8d = (__8cl->c_dtor__8classdef);

                                                            if (__8d && __7dtor) {
                                                                Pexpr __9dl;
                                                                Pstmt __9dls;

                                                                struct estmt *__0__X196;

                                                                struct loc __2__X197;

                                                                __9dl = call_dtor__FP4exprN21iT1(
                                                                    (struct expr *)__6n,
                                                                    (struct expr *)__8d,
                                                                    (struct expr *)0, 45, one);
                                                                __9dls =
                                                                    (struct stmt
                                                                         *)((__0__X196 = 0),
                                                                            ((__2__X197 =
                                                                                  __6n->where__4name),
                                                                             (((__0__X196 ||
                                                                                (__0__X196 = (struct
                                                                                              estmt
                                                                                                  *)
                                                                                     __nw__4stmtSFUl((
                                                                                         size_t)(sizeof(
                                                                                         struct
                                                                                         estmt)))))
                                                                                   ? ((__0__X196 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                                                           ((struct
                                                                                             stmt *)
                                                                                                __0__X196),
                                                                                           ((unsigned char)72),
                                                                                           __2__X197,
                                                                                           ((struct
                                                                                             stmt
                                                                                                 *)0))),
                                                                                      (__0__X196
                                                                                           ->__O2__4stmt
                                                                                           .e =
                                                                                           __9dl))
                                                                                   : 0),
                                                                              __0__X196)));
                                                                if (__5dd)
                                                                    __5ddt->s_list__4stmt = __9dls;
                                                                else
                                                                    __5dd = __9dls;
                                                                __5ddt = __9dls;
                                                            }

                                                        } else if (cl_obj_vec) {
                                                            Pclass __8cl;

                                                            Pname __8d;

                                                            __8cl = (((struct classdef *)((
                                                                (struct classdef *)
                                                                    cl_obj_vec->__O1__4expr.tp))));

                                                            __8d = (__8cl->c_dtor__8classdef);

                                                            if (__8d && __7dtor) {
                                                                Pfct __9f;
                                                                int __9i;

                                                                __9f = (((struct fct *)((
                                                                    (struct fct *)
                                                                        __8d->__O1__4expr.tp))));
                                                                __9i = 0;
                                                                {
                                                                    {
                                                                        Pname __9nn;

                                                                        __9nn = __9f->f_args__3fct
                                                                                    ->__O1__4name
                                                                                    .n_list;

                                                                        for (; __9nn &&
                                                                               __9nn->__O1__4name
                                                                                   .n_list;
                                                                             __9nn =
                                                                                 __9nn->__O1__4name
                                                                                     .n_list)
                                                                            __9i++;
                                                                        {
                                                                            Pexpr __9a;
                                                                            Pstmt __9dls;

                                                                            struct ival *__0__X198;

                                                                            struct estmt *__0__X199;

                                                                            struct loc __2__X200;

                                                                            __9a = cdvec__FP4nameP4exprP8classdefT1iN22(
                                                                                vec_del_fct,
                                                                                (struct expr *)__6n,
                                                                                __8cl, __8d, 0,
                                                                                (struct expr
                                                                                     *)((__0__X198 =
                                                                                             0),
                                                                                        (((__0__X198 ||
                                                                                           (__0__X198 = (struct
                                                                                                         ival
                                                                                                             *)
                                                                                                __nw__4exprSFUl((
                                                                                                    size_t)(sizeof(
                                                                                                    struct
                                                                                                    ival)))))
                                                                                              ? ((__0__X198 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                                                                      ((struct
                                                                                                        expr
                                                                                                            *)
                                                                                                           __0__X198),
                                                                                                      (unsigned char)150,
                                                                                                      (struct
                                                                                                       expr
                                                                                                           *)0,
                                                                                                      (struct
                                                                                                       expr
                                                                                                           *)0)),
                                                                                                 (__0__X198
                                                                                                      ->__O2__4expr
                                                                                                      .i1 =
                                                                                                      ((long long)
                                                                                                           __9i)))
                                                                                              : 0),
                                                                                         __0__X198)),
                                                                                (struct expr *)0);
                                                                            __9dls =
                                                                                (struct stmt
                                                                                     *)((__0__X199 =
                                                                                             0),
                                                                                        ((__2__X200 =
                                                                                              __6n->where__4name),
                                                                                         (((__0__X199 ||
                                                                                            (__0__X199 = (struct
                                                                                                          estmt
                                                                                                              *)
                                                                                                 __nw__4stmtSFUl((
                                                                                                     size_t)(sizeof(
                                                                                                     struct
                                                                                                     estmt)))))
                                                                                               ? ((__0__X199 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                                                                       ((struct
                                                                                                         stmt
                                                                                                             *)
                                                                                                            __0__X199),
                                                                                                       ((unsigned char)72),
                                                                                                       __2__X200,
                                                                                                       ((struct
                                                                                                         stmt
                                                                                                             *)0))),
                                                                                                  (__0__X199
                                                                                                       ->__O2__4stmt
                                                                                                       .e =
                                                                                                       __9a))
                                                                                               : 0),
                                                                                          __0__X199)));
                                                                            if (__5dd)
                                                                                __5ddt
                                                                                    ->s_list__4stmt =
                                                                                    __9dls;
                                                                            else
                                                                                __5dd = __9dls;
                                                                            __5ddt = __9dls;
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

                                    if (__5dd) {
                                        simpl__4stmtFv(__5dd);
                                        {
                                            Pstmt __6bs;

                                            __6bs = __ct__4stmtFUc3locP4stmt(
                                                (struct stmt *)0, __0this->base__4node,
                                                __0this->where__4stmt, (struct stmt *)0);
                                            ((*__6bs)) = (*__0this);
                                            __0this->base__4node = 166;
                                            __0this->s__4stmt = __5dd;
                                            __0this->__O2__4stmt.s2 = __6bs;
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
    } break;

    case 20:
        simpl__4exprFv(__0this->__O2__4stmt.e);
        simpl__4stmtFv(__0this->s__4stmt);
        if (__0this->__O3__4stmt.else_stmt)
            simpl__4stmtFv(__0this->__O3__4stmt.else_stmt);
        break;

    case 16:
        if (__0this->__O3__4stmt.for_init)
            simpl__4stmtFv(__0this->__O3__4stmt.for_init);
        if (__0this->__O2__4stmt.e) {
            if (Ntmp_dtor && need_lift_dtors__FP4expr(__0this->__O2__4stmt.e)) {
                need_lift = 1;
                {
                    Pexpr __4ee;

                    __4ee =
                        lift_dtors__FRP4exprP5tableUc((Pexpr *)(&__0this->__O2__4stmt.e), Ntmp_tbl,
                                                      __0this->__O2__4stmt.e->base__4node);
                    ((*__0this->__O2__4stmt.e)) = (*__4ee);
                }
            }
            curr_expr = __0this->__O2__4stmt.e;
            simpl__4exprFv(__0this->__O2__4stmt.e);
        }

        if (__0this->__O1__4stmt.e2) {
            const void *__2__X202;

            curr_expr = __0this->__O1__4stmt.e2;
            simpl__4exprFv(__0this->__O1__4stmt.e2);
            if (__0this->__O1__4stmt.e2->base__4node == 168)
                if (__0this->__O1__4stmt.e2->__O2__4expr.e1 == 0) {
                    struct ea __0__V155;

                    error__FiPCcRC2eaN33(
                        (int)'s', (const char *)"cannot expand inline void%n called in forE",
                        (const struct ea *)((__2__X202 = (const void *)__0this->__O1__4stmt.e2
                                                             ->__O4__4expr.il->fct_name__5iline),
                                            (((&__0__V155)->__O1__2ea.p = __2__X202),
                                             (&__0__V155))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
        }

        {
            Pstmt __3obl;
            Pstmt __3ocl;

            __3obl = break_del_list;
            __3ocl = continue_del_list;
            break_del_list = 0;
            continue_del_list = 0;
            simpl__4stmtFv(__0this->s__4stmt);
            break_del_list = __3obl;
            continue_del_list = __3ocl;
        }
        break;

    case 100: /* TRY handler -- simplify try body + catch bodies */
    {
        struct stmt *__2tbody = __0this->s__4stmt;
        struct stmt *__2clist = __2tbody ? __2tbody->s_list__4stmt : (struct stmt *)0;
        /* Disconnect catch chain so try body simpl doesn't recurse into it */
        if (__2tbody)
            __2tbody->s_list__4stmt = (struct stmt *)0;
        if (__2tbody)
            simpl__4stmtFv(__2tbody);
        if (__2tbody)
            __2tbody->s_list__4stmt = __2clist;
        /* Simplify each catch clause body */
        {
            struct stmt *__2cs = __2clist;
            while (__2cs) {
                if (__2cs->s__4stmt)
                    simpl__4stmtFv(__2cs->s__4stmt);
                __2cs = __2cs->s_list__4stmt;
            }
        }
        break;
    }

    case 215: /* RANGE_FOR -- simplify range expression and body */
        if (__0this->__O2__4stmt.e)
            simpl__4exprFv(__0this->__O2__4stmt.e);
        if (__0this->s__4stmt)
            simpl__4stmtFv(__0this->s__4stmt);
        break;

    case 98: /* CATCH stmt -- simplify catch body */
        if (__0this->s__4stmt)
            simpl__4stmtFv(__0this->s__4stmt);
        break;

    case 116:
        simpl__5blockFv(((struct block *)(((struct block *)__0this))));
        break;

    case 166:
        break;
    }
    }

    if ((__0this->base__4node != 116) && __0this->memtbl__4stmt) {
        Pstmt __2This;
        Pstmt __2t1;

        Pstmt __2ss;
        Pname __2cln;
        int __2i;
        Pname __2tn;

        struct table *__0__X203;

        int __2__X204;

        struct table *__0__X216;

        int __2__X217;

        __2This = __0this;
        __2t1 = (__0this->s_list__4stmt ? simpl__4stmtFv(__0this->s_list__4stmt)
                                        : (((struct stmt *)0)));

        __2ss = 0;

        __2tn = ((__0__X216 = __0this->memtbl__4stmt),
                 ((__2__X217 = (__2i = 1)),
                  ((((__2__X217 <= 0) || (__0__X216->free_slot__5table <= __2__X217))
                        ? (((struct name *)0))
                        : (__0__X216->entries__5table[__2__X217])))));
        for (; __2tn;
             __2tn = (__2tn->n_tbl_list__4name
                          ? __2tn->n_tbl_list__4name
                          : ((__0__X203 = __0this->memtbl__4stmt),
                             ((__2__X204 = (++__2i)),
                              ((((__2__X204 <= 0) || (__0__X203->free_slot__5table <= __2__X204))
                                    ? (((struct name *)0))
                                    : (__0__X203->entries__5table[__2__X204]))))))) {
            if (__2cln = is_cl_obj__4typeFv(__2tn->__O1__4expr.tp)) {
                Pname __4d;

                struct classdef *__0__X207;

                __4d = ((__0__X207 =
                             (((struct classdef *)(((struct classdef *)__2cln->__O1__4expr.tp))))),
                        (__0__X207->c_dtor__8classdef));
                if (__4d) {
                    if ((need_lift && is_probably_temp__FPCc(__2tn->__O2__4expr.string)) &&
                        look__5tableFPCcUc(tmp_tbl, __2tn->__O2__4expr.string, (unsigned char)0))
                        continue;
                    {
                        Pexpr __5dl;

                        __5dl = call_dtor__FP4exprN21iT1((struct expr *)__2tn, (struct expr *)__4d,
                                                         (struct expr *)0, 45, one);
                        check_visibility__FP4nameT1P8classdefP5tableT1(
                            __4d, (struct name *)0,
                            ((struct classdef *)(((struct classdef *)__2cln->__O1__4expr.tp))),
                            cc->ftbl__11dcl_context, cc->nof__11dcl_context);
                        if (pdlist && ((strncmp((const char *)"__R", __2tn->__O2__4expr.string,
                                                (unsigned long)3) == 0) ||
                                       (strncmp((const char *)"__V", __2tn->__O2__4expr.string,
                                                (unsigned long)3) == 0))) {
                            int __6len;

                            __6len = (strlen(__2tn->__O2__4expr.string) + 1);
                            {
                                {
                                    struct con_dtor *__6pcd;

                                    __6pcd = pdlist;

                                    for (; __6pcd; __6pcd = __6pcd->next__8con_dtor) {
                                        if (strncmp(__2tn->__O2__4expr.string,
                                                    __6pcd->tn__8con_dtor->__O2__4expr.string,
                                                    (unsigned long)__6len) == 0) {
                                            Pexpr __8e;

                                            __8e = __ct__4exprFUcP4exprT2(
                                                (struct expr *)0, (unsigned char)70,
                                                __6pcd->condition__8con_dtor, zero);
                                            __8e->__O1__4expr.tp = (struct type *)int_type;
                                            {
                                                Pexpr __8ee;

                                                __8ee = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                               (unsigned char)147,
                                                                               __8e, __5dl);
                                                __8ee->__O1__4expr.tp = (struct type *)int_type;
                                                __8ee = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                               (unsigned char)147,
                                                                               __8ee, zero);
                                                __8ee->__O1__4expr.tp = (struct type *)int_type;
                                                {
                                                    Pexpr __8qe;

                                                    __8qe = __ct__4exprFUcP4exprT2(
                                                        (struct expr *)0, (unsigned char)68, __8ee,
                                                        zero);
                                                    __8qe->__O4__4expr.cond =
                                                        __6pcd->condition__8con_dtor;
                                                    __8qe->__O1__4expr.tp = (struct type *)int_type;
                                                    __5dl = __8qe;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        {
                            Pstmt __5dls;

                            struct estmt *__0__X205;

                            struct loc __2__X206;

                            __5dls =
                                (struct stmt *)((__0__X205 = 0),
                                                ((__2__X206 = __2tn->where__4name),
                                                 (((__0__X205 ||
                                                    (__0__X205 = (struct estmt *)__nw__4stmtSFUl(
                                                         (size_t)(sizeof(struct estmt)))))
                                                       ? ((__0__X205 = (struct estmt *)
                                                               __ct__4stmtFUc3locP4stmt(
                                                                   ((struct stmt *)__0__X205),
                                                                   ((unsigned char)72), __2__X206,
                                                                   ((struct stmt *)0))),
                                                          (__0__X205->__O2__4stmt.e = __5dl))
                                                       : 0),
                                                  __0__X205)));
                            __5dls->s_list__4stmt = __2ss;
                            __2ss = __5dls;
                        }
                    }
                }
            }
        }

        if (__2ss) {
            Pstmt __3t2;

            __3t2 = simpl__4stmtFv(__2ss);

            switch (__0this->base__4node) {
            case 20:
            case 39:
            case 10:
            case 33:
                temp_in_cond__FP4exprP4stmtP5table(__0this->__O2__4stmt.e, __2ss,
                                                   __0this->memtbl__4stmt);

                break;

            case 166: {
                Pstmt __5ts;

                __5ts = __0this->__O2__4stmt.s2;
                while (__5ts->base__4node == 166)
                    __5ts = __5ts->__O2__4stmt.s2;
                if (__5ts->base__4node == 28) {
                    __2This = __5ts;
                    goto retu;
                }
                goto def;
            }
            case 28:
            retu: {
                if (__2This->__O2__4stmt.e == 0) {
                    Pstmt __6rs;

                    struct estmt *__0__X208;

                    struct loc __2__X209;

                    __6rs = (struct stmt
                                 *)((__0__X208 = 0),
                                    ((__2__X209 = __2This->where__4stmt),
                                     (((__0__X208 || (__0__X208 = (struct estmt *)__nw__4stmtSFUl(
                                                          (size_t)(sizeof(struct estmt)))))
                                           ? ((__0__X208 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                   ((struct stmt *)__0__X208), ((unsigned char)28),
                                                   __2__X209, ((struct stmt *)0))),
                                              (__0__X208->__O2__4stmt.e = ((struct expr *)0)))
                                           : 0),
                                      __0__X208)));

                    __6rs->__O1__4stmt.ret_tp = __2This->__O1__4stmt.ret_tp;
                    __2This->base__4node = 166;
                    __2This->s__4stmt = __2ss;
                    __2This->__O2__4stmt.s2 = __6rs;

                    return (__2t1 ? __2t1 : __6rs);
                }

                {
                    Pname __5cln;

                    __5cln = is_cl_obj__4typeFv(__2This->__O2__4stmt.e->__O1__4expr.tp);

                    if ((__5cln == 0) ||
                        (has_oper__8classdefFUc(
                             ((struct classdef *)(((struct classdef *)__5cln->__O1__4expr.tp))),
                             (unsigned char)70) == 0)) {
                        Pname __6rv;
                        __6rv = __ct__4nameFPCc((struct name *)0, (const char *)"_rresult");

                        __6rv->__O1__4expr.tp = unconst_type__FP4type(__2This->__O1__4stmt.ret_tp);

                        if (__2This->memtbl__4stmt == 0)
                            __2This->memtbl__4stmt = __ct__5tableFsP5tableP4name(
                                (struct table *)0, (short)4, (struct table *)0, (struct name *)0);
                        {
                            Pname __6n;

                            __6n = dcl__4nameFP5tableUc(__6rv, __2This->memtbl__4stmt,
                                                        (unsigned char)136);
                            __6n->where__4name = no_where;
                            __6n->n_scope__4name = 108;
                            __6n->n_assigned_to__4name = 1;
                            ((__6rv
                                  ? (((void)(__6rv
                                                 ? (((void)((((((struct expr *)__6rv))
                                                                  ? (((void)((((struct expr *)
                                                                                   __6rv))
                                                                                 ? (((void)((
                                                                                       (void)0))))
                                                                                 : (((void)0)))))
                                                                  : (((void)0)))),
                                                            (((void)__dl__4nameSFPvUl(
                                                                (void *)__6rv,
                                                                (size_t)(sizeof(struct name))))))))
                                                 : (((void)0)))))
                                  : (((void)0))));
                            {
                                Pstmt __6rs;

                                struct estmt *__0__X214;

                                struct loc __2__X215;

                                __6rs =
                                    (struct stmt
                                         *)((__0__X214 = 0),
                                            ((__2__X215 = __2This->where__4stmt),
                                             (((__0__X214 ||
                                                (__0__X214 = (struct estmt *)__nw__4stmtSFUl(
                                                     (size_t)(sizeof(struct estmt)))))
                                                   ? ((__0__X214 =
                                                           (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                                               ((struct stmt *)__0__X214),
                                                               ((unsigned char)28), __2__X215,
                                                               ((struct stmt *)0))),
                                                      (__0__X214->__O2__4stmt.e =
                                                           ((struct expr *)__6n)))
                                                   : 0),
                                              __0__X214)));
                                __6rs->__O1__4stmt.ret_tp = __2This->__O1__4stmt.ret_tp;
                                __2This->base__4node = 72;
                                __2This->__O2__4stmt.e = __ct__4exprFUcP4exprT2(
                                    (struct expr *)0, (unsigned char)70, (struct expr *)__6n,
                                    __2This->__O2__4stmt.e);
                                __2This->__O2__4stmt.e->__O1__4expr.tp = __6n->__O1__4expr.tp;
                                {
                                    Pstmt __6ps;

                                    struct pair *__0__X210;

                                    struct loc __2__X211;

                                    struct stmt *__2__X212;

                                    struct stmt *__2__X213;

                                    __6ps =
                                        (struct stmt
                                             *)((__0__X210 = 0),
                                                ((__2__X211 = __2This->where__4stmt),
                                                 ((__2__X212 = __2ss),
                                                  ((__2__X213 = __6rs),
                                                   (((__0__X210 ||
                                                      (__0__X210 = (struct pair *)__nw__4stmtSFUl(
                                                           (size_t)(sizeof(struct pair)))))
                                                         ? ((__0__X210 = (struct pair *)
                                                                 __ct__4stmtFUc3locP4stmt(
                                                                     ((struct stmt *)__0__X210),
                                                                     (unsigned char)166, __2__X211,
                                                                     __2__X212)),
                                                            (__0__X210->__O2__4stmt.s2 = __2__X213))
                                                         : 0),
                                                    __0__X210)))));
                                    __6ps->s_list__4stmt = __2This->s_list__4stmt;
                                    __2This->s_list__4stmt = __6ps;

                                    return (__2t1 ? __2t1 : __6rs);
                                }
                            }
                        }
                    }
                }
            } break;

            case 16:
                break;

            case 72:
                if (__2t1) {
                    Pstmt __5ttt;

                    Pstmt __5tt;

                    __5tt = __0this;
                    for (; (__5ttt = __5tt->s_list__4stmt) && (__5ttt->base__4node == 72);
                         __5tt = __5ttt)
                        ;
                    __3t2->s_list__4stmt = __5ttt;
                    __5tt->s_list__4stmt = __2ss;

                    return ((__2t1 != __5tt) ? __2t1 : __3t2);
                }
            default:
            def:
                if (__2t1) {
                    __3t2->s_list__4stmt = __0this->s_list__4stmt;
                    __0this->s_list__4stmt = __2ss;

                    return __2t1;
                }
                __0this->s_list__4stmt = __2ss;

                return __3t2;
            }
        }

        return (__2t1 ? __2t1 : __2This);
    }

    return (__0this->s_list__4stmt ? simpl__4stmtFv(__0this->s_list__4stmt) : __0this);
}

Pstmt copy__4stmtFv(register struct stmt *__0this) {
    Pstmt __1ns;

    __1ns = __ct__4stmtFUc3locP4stmt((struct stmt *)0, (unsigned char)0, curloc, (struct stmt *)0);

    ((*__1ns)) = (*__0this);
    if (__0this->s__4stmt)
        __1ns->s__4stmt = copy__4stmtFv(__0this->s__4stmt);
    if (__0this->s_list__4stmt)
        __1ns->s_list__4stmt = copy__4stmtFv(__0this->s_list__4stmt);

    switch (__0this->base__4node) {
    case 166:
        __1ns->__O2__4stmt.s2 = copy__4stmtFv(__0this->__O2__4stmt.s2);
        break;
    }

    return __1ns;
}

Pname overFound = 0;

extern const char *oper_name__FUc(TOK);

extern Pexpr find_name__FP4nameP8classdefP5tableiT1(Pname, Pclass, Ptable, int, Pname);

Ptype call_fct__4exprFP5table(struct expr *__0this, Ptable);

static Pexpr mk_new_with_args__FP4exprP4typeP8classdefT1(Pexpr __1pe, Ptype __1tt, Pclass __1cl,
                                                         Pexpr __1vec) {
    Pexpr __1p;
    Pexpr __1args;

    Pexpr __1ce;

    struct texpr *__0__X218;

    __1args = __1pe->__O3__4expr.e2;

    if (__1vec)
        __1ce = __1vec;
    else
        __1ce = (struct expr *)((__0__X218 = 0),
                                (((__0__X218 || (__0__X218 = (struct texpr *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct texpr)))))
                                      ? ((__0__X218 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X218), ((unsigned char)30),
                                              ((struct expr *)0), (struct expr *)0)),
                                         (__0__X218->__O4__4expr.tp2 = __1tt))
                                      : 0),
                                 __0__X218));

    ((void)tsizeof__4typeFi(__1tt, 0));
    __1ce->__O1__4expr.tp = size_t_type;
    __1args = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __1ce, __1args);
    {
        const char *__1s;
        Pname __1n;

        struct call *__0__X219;

        struct expr *__2__X220;

        struct expr *__2__X221;

        __1s = oper_name__FUc((unsigned char)23);
        __1n = __ct__4nameFPCc((struct name *)0, __1s);
        if ((__1pe->base__4node == 184) || __1vec)
            __1p = (struct expr *)look__5tableFPCcUc(gtbl, __1s, (unsigned char)0);
        else
            __1p = find_name__FP4nameP8classdefP5tableiT1(__1n, __1cl, scope, 109, curr_fct);
        __1p = (struct expr *)((__0__X219 = 0),
                               ((__2__X220 = __1p),
                                ((__2__X221 = __1args),
                                 (((__0__X219 || (__0__X219 = (struct call *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct call)))))
                                       ? (__0__X219 = (struct call *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X219), (unsigned char)109,
                                              __2__X220, __2__X221))
                                       : 0),
                                  __0__X219))));
        overFound = 0;
        ((void)call_fct__4exprFP5table(__1p, __1cl->memtbl__8classdef));
        if ((overFound && (overFound->n_scope__4name != 14)) && (overFound->n_scope__4name != 31))
            check_visibility__FP4nameT1P8classdefP5tableT1(
                overFound, (struct name *)0,
                (((struct fct *)(((struct fct *)overFound->__O1__4expr.tp))))->memof__3fct,
                cc->ftbl__11dcl_context, cc->nof__11dcl_context);
        overFound = 0;
        return __1p;
    }
}

Pexpr contents__4exprFv(struct expr *__0this);

void simpl_new__4exprFv(register struct expr *__0this) {
    Pname __1cln;
    Pname __1ctor;
    int __1sz;

    Pexpr __1var_expr;
    Pexpr __1const_expr;
    Ptype __1tt;
    Pexpr __1arg;
    Pexpr __1szof;
    Pname __1nf;
    Pexpr __1init;

    __1sz = 1;

    __1var_expr = 0;
    __1const_expr = 0;
    __1tt = __0this->__O4__4expr.tp2;

    __1init = __0this->__O2__4expr.e1;

    if (__1init && __1init->base__4node)
        __1init = 0;

    if ((__1cln = is_cl_obj__4typeFv(__1tt)) && (__1init == 0)) {
        Pclass __2cl;
        Pexpr __2p;

        __2cl = (((struct classdef *)(((struct classdef *)__1cln->__O1__4expr.tp))));

        __1ctor = (__2cl->c_ctor__8classdef);

        if (((__0this->__O3__4expr.e2 || (__1ctor == 0)) ||
             (__1ctor->__O4__4expr.n_table != __2cl->memtbl__8classdef)) ||
            ((__0this->base__4node == 184) && has_oper__8classdefFUc(__2cl, (unsigned char)23)))
            __2p = mk_new_with_args__FP4exprP4typeP8classdefT1(__0this, __1tt, __2cl,
                                                               (struct expr *)0);
        else {
            __2p = zero;

            ((void)mk_new_with_args__FP4exprP4typeP8classdefT1(__0this, __1tt, __2cl,
                                                               (struct expr *)0));
        }

        if (__1ctor) {
            Pexpr __3c;
            Ptype __3ttt;

            __3c = __0this->__O2__4expr.e1;
            __3ttt = __0this->__O1__4expr.tp;
            __3c->__O2__4expr.e1->__O2__4expr.e1 = __2p;
            simpl__4exprFv(__3c);
            ((*__0this)) = (*__3c);
            __0this->__O1__4expr.tp = __3ttt;
            ((__3c ? (((void)(__3c ? (((void)(((void)__dl__4exprSFPvUl(
                                         (void *)__3c, (size_t)(sizeof(struct expr)))))))
                                   : (((void)0)))))
                   : (((void)0))));
        } else {
            __0this->base__4node = 191;
            __0this->__O4__4expr.tp2 = __0this->__O1__4expr.tp;
            __0this->__O2__4expr.e1 = __2p;
            __0this->__O3__4expr.e2 = 0;
            simpl__4exprFv(__0this);
        }
        return;
    } else if (__1cln) {
        Pclass __2cl;

        __2cl = (((struct classdef *)(((struct classdef *)__1cln->__O1__4expr.tp))));

        ((void)mk_new_with_args__FP4exprP4typeP8classdefT1(__0this, __1tt, __2cl,
                                                           (struct expr *)0));
    }

    {
        Pclass __1covn;

        __1covn = 0;
        if (cl_obj_vec) {
            __1covn = (((struct classdef *)(((struct classdef *)cl_obj_vec->__O1__4expr.tp))));
            __1ctor = has_ictor__8classdefFv(__1covn);
            if (__1ctor == 0) {
                const void *__2__X223;

                if ((__1covn->c_ctor__8classdef)) {
                    struct ea __0__V222;

                    error__FPCcRC2eaN32(
                        (const char *)"new %s[], no defaultK",
                        (const struct ea *)((__2__X223 = (const void *)__1covn->string__8classdef),
                                            (((&__0__V222)->__O1__2ea.p = __2__X223),
                                             (&__0__V222))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                if ((__1covn->c_dtor__8classdef) == 0)
                    cl_obj_vec = 0;
            }
        }

    xxx:
        switch (__1tt->base__4node) {
        case 97:
            __1tt = (((struct basetype *)(((struct basetype *)__1tt))))
                        ->b_name__8basetype->__O1__4expr.tp;
            goto xxx;

        default: {
            Pname __3cov;

            struct texpr *__0__X224;

            __3cov = cl_obj_vec;
            ((void)tsizeof__4typeFi(__1tt, 0));
            cl_obj_vec = __3cov;
            __1szof = (struct expr *)((__0__X224 = 0),
                                      (((__0__X224 || (__0__X224 = (struct texpr *)__nw__4exprSFUl(
                                                           (size_t)(sizeof(struct texpr)))))
                                            ? ((__0__X224 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X224), ((unsigned char)30),
                                                    ((struct expr *)0), (struct expr *)0)),
                                               (__0__X224->__O4__4expr.tp2 = __1tt))
                                            : 0),
                                       __0__X224));
            __1szof->__O1__4expr.tp = (struct type *)uint_type;
            break;
        }

        case 110: {
            Pvec __3v;

            __3v = (((struct vec *)(((struct vec *)__1tt))));

            if (__3v->size__3vec)
                __1sz *= __3v->size__3vec;
            else if (__3v->dim__3vec)
                __1var_expr = __3v->dim__3vec;
            else
                __1sz = 0;
            __1tt = __3v->typ__5pvtyp;
            goto xxx;
        }
        }

        if (cl_obj_vec) {
            struct ival *__0__X225;

            __1const_expr =
                (struct expr *)((__0__X225 = 0),
                                (((__0__X225 || (__0__X225 = (struct ival *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct ival)))))
                                      ? ((__0__X225 = (struct ival *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X225), (unsigned char)150,
                                              (struct expr *)0, (struct expr *)0)),
                                         (__0__X225->__O2__4expr.i1 = ((long long)__1sz)))
                                      : 0),
                                 __0__X225));
            {
                Pexpr __2noe;

                __2noe = (__1var_expr
                              ? ((__1sz != 1)
                                     ? __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)50,
                                                              __1const_expr, __1var_expr)
                                     : __1var_expr)
                              : __1const_expr);
                __1const_expr = __1szof;
                __1const_expr->__O1__4expr.tp = (struct type *)uint_type;
                __0this->base__4node = 109;
                {
                    Pname __2vctor;

                    __2vctor = (__1covn->c_vtor__8classdef);
                    if (__1ctor) {
                        struct texpr *__0__X226;

                        struct type *__2__X227;

                        __1arg = __ct__4exprFUcP4exprT2(
                            (struct expr *)0, (unsigned char)140,
                            (struct expr
                                 *)((__0__X226 = 0),
                                    ((__2__X227 = Pvoid_type),
                                     (((__0__X226 || (__0__X226 = (struct texpr *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct texpr)))))
                                           ? ((__0__X226 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X226), ((unsigned char)191),
                                                   ((struct expr *)(__2vctor ? __2vctor : __1ctor)),
                                                   (struct expr *)0)),
                                              (__0__X226->__O4__4expr.tp2 = __2__X227))
                                           : 0),
                                      __0__X226))),
                            (struct expr *)0);
                        lval__4exprFUc((struct expr *)__1ctor, (unsigned char)112);
                    } else
                        __1arg = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, zero,
                                                        (struct expr *)0);

                    {
                        Pexpr __2sub;

                        struct texpr *__0__X228;

                        struct type *__2__X229;

                        struct expr *__2__X230;

                        __2sub = 0;
                        if ((__0this->__O3__4expr.e2 && __0this->__O3__4expr.e2->__O2__4expr.e1) &&
                            __0this->__O3__4expr.e2->__O2__4expr.e1->__O1__4expr.tp) {
                            Pexpr __3vec_sz;

                            __3vec_sz = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)50,
                                                               __2noe, __1const_expr);
                            __2sub = mk_new_with_args__FP4exprP4typeP8classdefT1(
                                __0this, __1tt, __1covn, __3vec_sz);
                        }
                        __1arg = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                        __1const_expr, __1arg);
                        __1arg = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                        __2noe, __1arg);

                        __1arg = __ct__4exprFUcP4exprT2(
                            (struct expr *)0, (unsigned char)140,
                            __0this->__O3__4expr.e2
                                ? (__2sub ? __2sub : __0this->__O3__4expr.e2)
                                : (((struct expr
                                         *)((__0__X228 = 0),
                                            ((__2__X229 = Pvoid_type),
                                             ((__2__X230 = zero),
                                              (((__0__X228 ||
                                                 (__0__X228 = (struct texpr *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct texpr)))))
                                                    ? ((__0__X228 =
                                                            (struct texpr *)__ct__4exprFUcP4exprT2(
                                                                ((struct expr *)__0__X228),
                                                                ((unsigned char)191), __2__X230,
                                                                (struct expr *)0)),
                                                       (__0__X228->__O4__4expr.tp2 = __2__X229))
                                                    : 0),
                                               __0__X228)))))),
                            __1arg);
                        __0this->base__4node = 191;
                        __0this->__O4__4expr.tp2 = __0this->__O1__4expr.tp;
                        __0this->__O2__4expr.e1 =
                            __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)146,
                                                   (struct expr *)vec_new_fct, __1arg);
                        __0this->__O2__4expr.e1->__O4__4expr.fct_name = vec_new_fct;
                        __0this->__O2__4expr.e1->__O1__4expr.tp =
                            (((struct fct *)(((struct fct *)vec_new_fct->__O1__4expr.tp))))
                                ->returns__3fct;
                        simpl__4exprFv(__0this);
                        return;
                    }
                }
            }
        }

        if (__1sz == 1)
            __1arg = (__1var_expr ? __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)50,
                                                           __1szof, __1var_expr)
                                  : __1szof);
        else {
            struct ival *__0__X231;

            __1const_expr =
                (struct expr *)((__0__X231 = 0),
                                (((__0__X231 || (__0__X231 = (struct ival *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct ival)))))
                                      ? ((__0__X231 = (struct ival *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X231), (unsigned char)150,
                                              (struct expr *)0, (struct expr *)0)),
                                         (__0__X231->__O2__4expr.i1 = ((long long)__1sz)))
                                      : 0),
                                 __0__X231));
            __1const_expr->__O1__4expr.tp = (struct type *)uint_type;
            __1const_expr =
                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)50, __1const_expr, __1szof);
            __1const_expr->__O1__4expr.tp = (struct type *)uint_type;
            __1arg = (__1var_expr ? __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)50,
                                                           __1const_expr, __1var_expr)
                                  : __1const_expr);
        }

        __1arg->__O1__4expr.tp = (struct type *)uint_type;
        __0this->base__4node = 191;
        __0this->__O4__4expr.tp2 = __0this->__O1__4expr.tp;
        __1arg = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __1arg,
                                        __0this->__O3__4expr.e2);
        {
            Pname __1nn;

            __1nn = 0;
            if ((__1cln && (__1nn = has_oper__8classdefFUc(
                                ((struct classdef *)(((struct classdef *)__1cln->__O1__4expr.tp))),
                                (unsigned char)23))) &&
                __1nn) {
                __1nf = (((struct name *)(((struct name *)find_name__FP4nameP8classdefP5tableiT1(
                    __1nn, ((struct classdef *)(((struct classdef *)__1cln->__O1__4expr.tp))),
                    scope, 109, curr_fct)))));
                __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                    (struct expr *)0, (unsigned char)146, (struct expr *)__1nf, __1arg);
                ((void)call_fct__4exprFP5table(
                    __0this->__O2__4expr.e1,
                    (((struct classdef *)(((struct classdef *)__1cln->__O1__4expr.tp))))
                        ->memtbl__8classdef));
            } else {
                __1nf =
                    look__5tableFPCcUc(gtbl, oper_name__FUc((unsigned char)23), (unsigned char)0);

                __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                    (struct expr *)0, (unsigned char)146, (struct expr *)__1nf, __1arg);
                ((void)call_fct__4exprFP5table(__0this->__O2__4expr.e1, gtbl));
            }
            simpl__4exprFv(__0this);

            if (__1init) {
                Pexpr __2p;
                Pexpr __2ee;

                __2p = __1init->__O2__4expr.e1;
                __2ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)0, (struct expr *)0,
                                               (struct expr *)0);
                ((*__2ee)) = (*__0this);
                __2ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70, __2p, __2ee);
                __1init->base__4node = 70;
                __1init->__O2__4expr.e1 = contents__4exprFv(__2p);
                __2ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, __2ee, __1init);
                simpl__4exprFv(__2ee);
                __0this->base__4node = 71;
                __0this->__O2__4expr.e1 = __2ee;
                __0this->__O3__4expr.e2 = __2p;
            }
        }
    }
}

Pptr is_ptr__4typeFv(struct type *__0this);

extern int error__FPCc(const char *);

void simpl_delete__4exprFv(register struct expr *__0this) {
    Ptype __1tt;

    __1tt = __0this->__O2__4expr.e1->__O1__4expr.tp;
    for (; __1tt->base__4node == 97;
         __1tt =
             (((struct basetype *)(((struct basetype *)__1tt))))->b_name__8basetype->__O1__4expr.tp)
        ;
    __1tt = (((struct ptr *)(((struct ptr *)__1tt))))->typ__5pvtyp;

    {
        Pname __1cln;

        Pname __1n;
        Pclass __1cl;

        __1cln = is_cl_obj__4typeFv(__1tt);
        if (cl_obj_vec)
            __1cln = cl_obj_vec;
        ;

        ;

        if (__1cln) {
            __1cl = (((struct classdef *)(((struct classdef *)__1cln->__O1__4expr.tp))));
            if ((__1cl->defined__4type & 01) == 0) {
                struct ea __0__V232;

                struct ea __0__V233;

                error__FiPCcRC2eaN33(
                    (int)'w', (const char *)"delete%t (%t not defined)",
                    (const struct ea *)(((&__0__V232)->__O1__2ea.p = ((const void *)__1cl)),
                                        (&__0__V232)),
                    (const struct ea *)(((&__0__V233)->__O1__2ea.p = ((const void *)__1cl)),
                                        (&__0__V233)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
        } else
            __1cl = 0;

        if (__1cl && ((__1n = (__1cl->c_dtor__8classdef)) ||
                      (__0this->__O3__4expr.e2 && has_ictor__8classdefFv(__1cl)))) {
            {
                Pexpr __3ee;

                const char *__3s;
                Pname __3n;

                struct call *__0__X235;

                struct expr *__2__X236;

                struct expr *__2__X237;

                __3ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                               __0this->__O2__4expr.e1, (struct expr *)0);
                __3s = oper_name__FUc((unsigned char)9);

                if (__0this->base__4node != 188) {
                    __3n = __ct__4nameFPCc((struct name *)0, __3s);
                    __3n = (((struct name *)(((struct name *)find_name__FP4nameP8classdefP5tableiT1(
                        __3n, __1cl, scope, 109, curr_fct)))));

                    if ((__3n->__O1__4expr.tp->base__4node == 76) ||
                        ((((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))))->nargs__3fct ==
                         2)) {
                        Pexpr __5ss;

                        struct texpr *__0__X234;

                        __5ss =
                            (struct expr
                                 *)((__0__X234 = 0),
                                    (((__0__X234 || (__0__X234 = (struct texpr *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct texpr)))))
                                          ? ((__0__X234 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X234), ((unsigned char)30),
                                                  ((struct expr *)0), (struct expr *)0)),
                                             (__0__X234->__O4__4expr.tp2 = ((struct type *)__1cl)))
                                          : 0),
                                     __0__X234));
                        __5ss->__O1__4expr.tp = size_t_type;
                        __3ee->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                            (struct expr *)0, (unsigned char)140, __5ss, (struct expr *)0);
                    }
                } else
                    __3n = look__5tableFPCcUc(gtbl, __3s, (unsigned char)0);

                __3ee =
                    (struct expr *)((__0__X235 = 0),
                                    ((__2__X236 = (struct expr *)__3n),
                                     ((__2__X237 = __3ee),
                                      (((__0__X235 || (__0__X235 = (struct call *)__nw__4exprSFUl(
                                                           (size_t)(sizeof(struct call)))))
                                            ? (__0__X235 = (struct call *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X235), (unsigned char)109,
                                                   __2__X236, __2__X237))
                                            : 0),
                                       __0__X235))));
                __3ee->base__4node = 146;
            }

            if (((__0this->base__4node == 188) && (__0this->__O3__4expr.e2 == 0)) ||
                (__1n &&
                 (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))))->f_virtual__3fct)) {
                nin = 1;
                {
                    int __3needtemp;

                    __3needtemp = not_simple__4exprFi(__0this->__O2__4expr.e1, 0);
                    nin = 0;
                    if (__3needtemp) {
                        Pname __4tnx;

                        __4tnx = __ct__4nameFPCc((struct name *)0,
                                                 (const char *)make_name__FUc((unsigned char)'K'));
                        __4tnx->__O1__4expr.tp = __0this->__O2__4expr.e1->__O1__4expr.tp;
                        {
                            Pname __4tn;

                            __4tn = dcl__4nameFP5tableUc(__4tnx, scope, (unsigned char)108);
                            ((__4tnx
                                  ? (((void)(__4tnx
                                                 ? (((void)((((((struct expr *)__4tnx))
                                                                  ? (((void)((((struct expr *)
                                                                                   __4tnx))
                                                                                 ? (((void)((
                                                                                       (void)0))))
                                                                                 : (((void)0)))))
                                                                  : (((void)0)))),
                                                            (((void)__dl__4nameSFPvUl(
                                                                (void *)__4tnx,
                                                                (size_t)(sizeof(struct name))))))))
                                                 : (((void)0)))))
                                  : (((void)0))));
                            assign__4nameFv(__4tn);
                            __0this->__O2__4expr.e1 = __ct__4exprFUcP4exprT2(
                                (struct expr *)0, (unsigned char)70, (struct expr *)__4tn,
                                __0this->__O2__4expr.e1);
                            __0this->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                                (struct expr *)0, __0this->base__4node, (struct expr *)__4tn,
                                __0this->__O3__4expr.e2);
                            __0this->base__4node = 71;

                            simpl__4exprFv(__0this);
                            return;
                        }
                    }
                }
            }
            {
                Pexpr __2r;

                __2r = __0this->__O2__4expr.e1;

                if (__1n && (__1n->n_scope__4name != 25))
                    check_visibility__FP4nameT1P8classdefP5tableT1(__1n, (struct name *)0, __1cl,
                                                                   cc->ftbl__11dcl_context,
                                                                   cc->nof__11dcl_context);

                if (__1n && (__0this->__O3__4expr.e2 == 0)) {
                    if (__1n->n_dcl_printed__4name == 0) {
                        Pname __4nn;
                        Pexpr __4del;

                        __4nn = __ct__4nameFPCc((struct name *)0, oper_name__FUc((unsigned char)9));
                        __4del = find_name__FP4nameP8classdefP5tableiT1(__4nn, __1cl, scope, 109,
                                                                        curr_fct);
                        dcl_print__4nameFUc(((struct name *)(((struct name *)__4del))),
                                            (unsigned char)0);
                    }
                    {
                        Pexpr __3ee;

                        __3ee = call_dtor__FP4exprN21iT1(
                            __2r, (struct expr *)__1n,
                            (__0this->base__4node == 188) ? (((struct expr *)0)) : one, 44, one);
                        if ((((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))))
                                ->f_virtual__3fct) {
                            if (ansi_opt) {
                                __3ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)147,
                                                               __3ee, zero);
                                __3ee->__O1__4expr.tp = (struct type *)zero_type;
                            }
                            __3ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)68,
                                                           __3ee, zero);
                            __3ee->__O1__4expr.tp = __3ee->__O2__4expr.e1->__O1__4expr.tp;
                            __3ee->__O4__4expr.cond = __2r;
                        }
                        if (__0this->base__4node == 188) {
                            const char *__4s;
                            Pexpr __4p;
                            Pname __4n_gdelete;

                            struct call *__0__X238;

                            struct expr *__2__X239;

                            struct expr *__2__X240;

                            __4s = oper_name__FUc((unsigned char)9);
                            __4p = (struct expr *)look__5tableFPCcUc(gtbl, __4s, (unsigned char)0);
                            __4n_gdelete = (((struct name *)(((struct name *)__4p))));
                            if (__4n_gdelete && (!__4n_gdelete->n_dcl_printed__4name)) {
                                dcl_print__4nameFUc(__4n_gdelete, (unsigned char)0);
                            }
                            __0this->__O3__4expr.e2 =
                                (struct expr *)((__0__X238 = 0),
                                                ((__2__X239 = __4p),
                                                 ((__2__X240 = __ct__4exprFUcP4exprT2(
                                                       (struct expr *)0, (unsigned char)140,
                                                       __0this->__O2__4expr.e1, (struct expr *)0)),
                                                  (((__0__X238 ||
                                                     (__0__X238 = (struct call *)__nw__4exprSFUl(
                                                          (unsigned long)(sizeof(struct call)))))
                                                        ? (__0__X238 = (struct call *)
                                                               __ct__4exprFUcP4exprT2(
                                                                   ((struct expr *)__0__X238),
                                                                   (unsigned char)109, __2__X239,
                                                                   __2__X240))
                                                        : 0),
                                                   __0__X238))));
                            __0this->base__4node = 71;
                            __0this->__O2__4expr.e1 = __3ee;
                        } else {
                            ((*__0this)) = (*__3ee);
                            ((__3ee ? (((void)(__3ee ? (((void)(((void)__dl__4exprSFPvUl(
                                                           (void *)__3ee,
                                                           (size_t)(sizeof(struct expr)))))))
                                                     : (((void)0)))))
                                    : (((void)0))));
                        }
                        simpl__4exprFv(__0this);
                        return;
                    }
                } else {
                    Ptype __3ttt;

                    __3ttt = skiptypedefs__4typeFv(__1tt);
                    while (__3ttt->base__4node == 110)
                        __3ttt = skiptypedefs__4typeFv(
                            (((struct ptr *)(((struct ptr *)__3ttt))))->typ__5pvtyp);
                    {
                        Pexpr __3sz;

                        struct texpr *__0__X255;

                        __3sz =
                            (struct expr
                                 *)((__0__X255 = 0),
                                    (((__0__X255 || (__0__X255 = (struct texpr *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct texpr)))))
                                          ? ((__0__X255 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X255), ((unsigned char)30),
                                                  ((struct expr *)0), (struct expr *)0)),
                                             (__0__X255->__O4__4expr.tp2 = __3ttt))
                                          : 0),
                                     __0__X255));
                        ((void)tsizeof__4typeFi(__3ttt, 0));
                        {
                            int __3i;

                            __3i = 0;
                            if (__1n) {
                                Pfct __4f;
                                Pname __4nn;

                                __4f = (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))));
                                __4nn = __4f->f_args__3fct->__O1__4name.n_list;
                                for (; __4nn && __4nn->__O1__4name.n_list;
                                     __4nn = __4nn->__O1__4name.n_list)
                                    __3i++;
                            }
                            {
                                Pexpr __3arg;

                                struct texpr *__0__X251;

                                struct type *__2__X252;

                                struct expr *__2__X253;

                                struct ival *__0__X254;

                                __3arg = __ct__4exprFUcP4exprT2(
                                    (struct expr *)0, (unsigned char)140,
                                    (struct expr *)((__0__X254 = 0),
                                                    (((__0__X254 ||
                                                       (__0__X254 = (struct ival *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct ival)))))
                                                          ? ((__0__X254 = (struct ival *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X254),
                                                                      (unsigned char)150,
                                                                      (struct expr *)0,
                                                                      (struct expr *)0)),
                                                             (__0__X254->__O2__4expr.i1 =
                                                                  ((long long)__3i)))
                                                          : 0),
                                                     __0__X254)),
                                    (struct expr *)0);
                                __3sz->__O1__4expr.tp = (struct type *)uint_type;

                                __3arg = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                (unsigned char)140, one, __3arg);
                                if (__1n && (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))))
                                                ->f_virtual__3fct) {
                                    Pexpr __4a;

                                    register struct mdot *__0__X241;

                                    struct texpr *__0__X242;

                                    struct type *__2__X243;

                                    struct ref *__0__X244;

                                    struct expr *__2__X245;

                                    struct expr *__2__X246;

                                    __4a =
                                        (struct expr
                                             *)((__0__X244 = 0),
                                                ((__2__X245 = __0this->__O2__4expr.e1),
                                                 ((__2__X246 = (struct expr *)__1n),
                                                  (((__0__X244 ||
                                                     (__0__X244 = (struct ref *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct ref)))))
                                                        ? ((__0__X244 = (struct ref *)
                                                                __ct__4exprFUcP4exprT2(
                                                                    ((struct expr *)__0__X244),
                                                                    ((unsigned char)44), __2__X245,
                                                                    (struct expr *)0)),
                                                           (__0__X244->__O4__4expr.mem = __2__X246))
                                                        : 0),
                                                   __0__X244))));
                                    __4a = address__4exprFv(__4a);
                                    __4a =
                                        (struct expr
                                             *)((__0__X241 = 0),
                                                (((__0__X241 ||
                                                   (__0__X241 = (struct mdot *)__nw__4exprSFUl(
                                                        (size_t)(sizeof(struct mdot)))))
                                                      ? ((__0__X241 =
                                                              (struct mdot *)__ct__4exprFUcP4exprT2(
                                                                  ((struct expr *)__0__X241),
                                                                  (unsigned char)177,
                                                                  (struct expr *)0,
                                                                  (struct expr *)0)),
                                                         ((__0__X241->__O3__4expr.string2 =
                                                               ((const char *)"f")),
                                                          (__0__X241->__O4__4expr.mem = __4a)))
                                                      : 0),
                                                 __0__X241));
                                    __4a->__O2__4expr.i1 = 9;
                                    __4a = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                  (unsigned char)68, __4a, zero);
                                    __4a->__O4__4expr.cond = __0this->__O2__4expr.e1;
                                    __3arg = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)140,
                                        (struct expr
                                             *)((__0__X242 = 0),
                                                ((__2__X243 = Pvoid_type),
                                                 (((__0__X242 ||
                                                    (__0__X242 = (struct texpr *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct texpr)))))
                                                       ? ((__0__X242 = (struct texpr *)
                                                               __ct__4exprFUcP4exprT2(
                                                                   ((struct expr *)__0__X242),
                                                                   ((unsigned char)191), __4a,
                                                                   (struct expr *)0)),
                                                          (__0__X242->__O4__4expr.tp2 = __2__X243))
                                                       : 0),
                                                  __0__X242))),
                                        __3arg);
                                } else {
                                    struct texpr *__0__X247;

                                    struct type *__2__X248;

                                    struct expr *__2__X249;

                                    __3arg = __ct__4exprFUcP4exprT2(
                                        (struct expr *)0, (unsigned char)140,
                                        (struct expr
                                             *)((__0__X247 = 0),
                                                ((__2__X248 = Pvoid_type),
                                                 ((__2__X249 =
                                                       (__1n ? (((struct expr *)__1n)) : zero)),
                                                  (((__0__X247 ||
                                                     (__0__X247 = (struct texpr *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct texpr)))))
                                                        ? ((__0__X247 = (struct texpr *)
                                                                __ct__4exprFUcP4exprT2(
                                                                    ((struct expr *)__0__X247),
                                                                    ((unsigned char)191), __2__X249,
                                                                    (struct expr *)0)),
                                                           (__0__X247->__O4__4expr.tp2 = __2__X248))
                                                        : 0),
                                                   __0__X247)))),
                                        __3arg);
                                    if (__1n)
                                        lval__4exprFUc((struct expr *)__1n, (unsigned char)112);
                                }

                                __3arg = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                (unsigned char)140, __3sz, __3arg);
                                if (__0this->__O3__4expr.e2->base__4node == 144) {
                                    struct ival *__0__X250;

                                    __0this->__O3__4expr.e2 =
                                        (struct expr
                                             *)((__0__X250 = 0),
                                                (((__0__X250 ||
                                                   (__0__X250 = (struct ival *)__nw__4exprSFUl(
                                                        (size_t)(sizeof(struct ival)))))
                                                      ? ((__0__X250 =
                                                              (struct ival *)__ct__4exprFUcP4exprT2(
                                                                  ((struct expr *)__0__X250),
                                                                  (unsigned char)150,
                                                                  (struct expr *)0,
                                                                  (struct expr *)0)),
                                                         (__0__X250->__O2__4expr.i1 =
                                                              ((long long)-1)))
                                                      : 0),
                                                 __0__X250));
                                }

                                __3arg =
                                    __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                           __0this->__O3__4expr.e2, __3arg);
                                __3arg = __ct__4exprFUcP4exprT2(
                                    (struct expr *)0, (unsigned char)140,
                                    (struct expr
                                         *)((__0__X251 = 0),
                                            ((__2__X252 = Pvoid_type),
                                             ((__2__X253 = __0this->__O2__4expr.e1),
                                              (((__0__X251 ||
                                                 (__0__X251 = (struct texpr *)__nw__4exprSFUl(
                                                      (size_t)(sizeof(struct texpr)))))
                                                    ? ((__0__X251 =
                                                            (struct texpr *)__ct__4exprFUcP4exprT2(
                                                                ((struct expr *)__0__X251),
                                                                ((unsigned char)191), __2__X253,
                                                                (struct expr *)0)),
                                                       (__0__X251->__O4__4expr.tp2 = __2__X252))
                                                    : 0),
                                               __0__X251)))),
                                    __3arg);
                                {
                                    Pexpr __3ee;

                                    __3ee =
                                        __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)146,
                                                               (struct expr *)vec_del_fct, __3arg);
                                    __3ee->__O4__4expr.fct_name = vec_del_fct;
                                    __3ee->__O1__4expr.tp = __0this->__O1__4expr.tp;

                                    ((*__0this)) = (*__3ee);
                                    simpl__4exprFv(__0this);
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (((__0this->__O3__4expr.e2 == 0) &&
                 is_ptr__4typeFv(__0this->__O2__4expr.e1->__O1__4expr.tp)) &&
                ((((struct ptr *)(((struct ptr *)skiptypedefs__4typeFv(
                      __0this->__O2__4expr.e1->__O1__4expr.tp)))))
                     ->typ__5pvtyp->base__4node == 110))
                error__FPCc((const char *)"use delete[] to delete an array");
            {
                Pexpr __2ee;
                const char *__2s;

                __2ee = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                               __0this->__O2__4expr.e1, (struct expr *)0);
                __2s = oper_name__FUc((unsigned char)9);
                if (__1cl && (__0this->base__4node != 188)) {
                    Pname __3n;

                    __3n = __ct__4nameFPCc((struct name *)0, __2s);
                    __0this->__O2__4expr.e1 =
                        find_name__FP4nameP8classdefP5tableiT1(__3n, __1cl, scope, 109, curr_fct);
                    if ((__0this->__O2__4expr.e1->__O1__4expr.tp->base__4node == 76) ||
                        ((((struct fct *)(((struct fct *)__0this->__O2__4expr.e1->__O1__4expr.tp))))
                             ->nargs__3fct == 2)) {
                        Pexpr __4ss;

                        struct texpr *__0__X256;

                        __4ss =
                            (struct expr
                                 *)((__0__X256 = 0),
                                    (((__0__X256 || (__0__X256 = (struct texpr *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct texpr)))))
                                          ? ((__0__X256 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X256), ((unsigned char)30),
                                                  ((struct expr *)0), (struct expr *)0)),
                                             (__0__X256->__O4__4expr.tp2 = ((struct type *)__1cl)))
                                          : 0),
                                     __0__X256));
                        __4ss->__O1__4expr.tp = size_t_type;
                        __2ee->__O3__4expr.e2 = __ct__4exprFUcP4exprT2(
                            (struct expr *)0, (unsigned char)140, __4ss, (struct expr *)0);
                    }
                } else
                    __0this->__O2__4expr.e1 =
                        (struct expr *)look__5tableFPCcUc(gtbl, __2s, (unsigned char)0);
                __0this->base__4node = 146;
                __0this->__O3__4expr.e2 = __2ee;
                overFound = 0;
                ((void)call_fct__4exprFP5table(__0this, scope));
                if (overFound && (overFound->n_scope__4name != 14))
                    check_visibility__FP4nameT1P8classdefP5tableT1(overFound, (struct name *)0,
                                                                   __1cl, cc->ftbl__11dcl_context,
                                                                   cc->nof__11dcl_context);

                overFound = 0;
            }
        }

        simpl__4callFv(((struct call *)(((struct call *)__0this))));
    }
}

static int same_class__FP8classdefT1i(Pclass __1c1, Pclass __1c2, int __1dummy) {
    return ((__1c1 == __1c2)
                ? 1
                : ((__1c1 && __1c2)
                       ? (((int)same_class__8classdefFP8classdefi(__1c1, __1c2, __1dummy)))
                       : 0));
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
