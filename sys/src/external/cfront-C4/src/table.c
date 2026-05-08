
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

extern void *memset(void *, int, size_t);

struct table *__ct__5tableFsP5tableP4name(register struct table *__0this, short __1sz, Ptable __1nx,
                                          Pname __1n) {
    struct node *__0__X17;

    if (__0this || (__0this = (struct table *)__nw__5tableSFUl((size_t)(sizeof(struct table))))) {
        __0this = (struct table *)((__0__X17 = (((struct node *)__0this))),
                                   (((__0__X17 || (__0__X17 = (struct node *)__nw__FUl(
                                                       (size_t)(sizeof(struct node)))))
                                         ? (((__0__X17->base__4node = 0),
                                             (__0__X17->permanent__4node = 0)),
                                            (__0__X17->baseclass__4node = 0))
                                         : 0),
                                    __0__X17));
        ;
        __0this->base__4node = 142;
        __0this->t_name__5table = __1n;
        __0this->size__5table = (__1sz = ((__1sz <= 0) ? 2 : (__1sz + 1)));

        __0this->entries__5table =
            (((struct name **)__nw__FUl((size_t)((sizeof(struct name *)) * __1sz))));
        __0this->hashsize__5table = (__1sz = ((__1sz * 3) / 2));
        __0this->hashtbl__5table = (((short *)__nw__FUl((size_t)((sizeof(short)) * __1sz))));
        memset((void *)__0this->hashtbl__5table, 0, (sizeof(short)) * __1sz);
        __0this->next__5table = __1nx;
        __0this->free_slot__5table = 1;
        ;
    }
    return __0this;
}

extern void __dl__FPv(void *);

void __dt__5tableFv(struct table *__0this, int __0__free) {
    if (__0this) {
        __dl__FPv((void *)__0this->entries__5table);
        __dl__FPv((void *)__0this->hashtbl__5table);
        if (__0this)
            if (__0__free & 1)
                __dl__5tableSFPvUl((void *)__0this, (size_t)(sizeof(struct table)));
    }
}

Pname look__5tableFPCcUc(register struct table *__0this, const char *__1s, TOK __1k) {
    Ptable __1t;
    const char *__1p;
    const char *__1q;
    int __1i;
    Pname __1n;
    int __1rr;

    ;

    __1p = __1s;
    __1i = 0;
    while ((*__1p))
        __1i += (__1i + ((*(__1p++))));
    __1rr = ((0 <= __1i) ? __1i : (-__1i));

    for (__1t = __0this; __1t; __1t = __1t->next__5table) {
        Pname *__2np;
        int __2mx;
        short *__2hash;
        int __2firsti;

        __2np = __1t->entries__5table;
        __2mx = __1t->hashsize__5table;
        __2hash = __1t->hashtbl__5table;
        __2firsti = (__1i = (__1rr % __2mx));

        do {
            if ((__2hash[__1i]) == 0)
                goto not_found;
            __1n = (__2np[(__2hash[__1i])]);
            if (__1n == 0)
                error__FiPCc((int)'i', (const char *)"hashed lookup");
            __1p = __1n->__O2__4expr.string;
            if (__1p == 0) goto nxt;    /* skip corrupt null-string entry */
            __1q = __1s;
            while (((*__1p)) && ((*__1q)))
                if (((*(__1p++))) != ((*(__1q++))))
                    goto nxt;
            if (((*__1p)) == ((*__1q)))
                goto found;
        nxt:
            if (__2mx <= (++__1i))
                __1i = 0;
        } while (__1i != __2firsti);
    found:
        for (; __1n; __1n = __1n->n_tbl_list__4name) {
            ;
            if (__1n->n_key__4name == __1k)
                return __1n;
        }

    not_found:;
    }

    ;
    return (struct name *)0;
}

bit Nold = 0;

extern int strcmp(const char *, const char *);

extern int error__FPCc(const char *);

void grow__5tableFi(struct table *__0this, int);

extern size_t strlen(const char *);

extern char *strcpy(char *, const char *);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

Pname insert__5tableFP4nameUc(register struct table *__0this, Pname __1nx, TOK __1k) {
    const char *__1p;
    int __1i;
    Pname __1n;
    Pname *__1np;
    Pname *__1link;
    int __1firsti;
    int __1mx;
    short *__1hash;
    const char *__1s;

    __1np = __0this->entries__5table;

    __1mx = __0this->hashsize__5table;
    __1hash = __0this->hashtbl__5table;
    __1s = __1nx->__O2__4expr.string;

    ;

    if (__1s == 0) {
        struct ea __0__V18;

        struct ea __0__V19;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"%p->insert(0,%k)",
            (const struct ea *)(((&__0__V18)->__O1__2ea.p = ((const void *)__0this)), (&__0__V18)),
            (const struct ea *)(((((&__0__V19)->__O1__2ea.i = ((unsigned long)__1k)), 0)),
                                (&__0__V19)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    __1nx->n_key__4name = __1k;
    if (__1nx->n_tbl_list__4name || __1nx->__O4__4expr.n_table) {
        struct ea __0__V20;

        struct ea __0__V21;

        struct ea __0__V22;

        struct ea __0__V23;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"%n in two tables (n_tbl_list %d, n_table %d%n)",
            (const struct ea *)(((&__0__V20)->__O1__2ea.p = ((const void *)__1nx)), (&__0__V20)),
            (const struct ea *)__ct__2eaFPCv(&__0__V21, (const void *)__1nx->n_tbl_list__4name),
            (const struct ea *)__ct__2eaFPCv(&__0__V22, (const void *)__1nx->__O4__4expr.n_table),
            (const struct ea *)__ct__2eaFPCv(
                &__0__V23, (const void *)(__1nx->__O4__4expr.n_table
                                              ? __1nx->__O4__4expr.n_table->t_name__5table
                                              : (((struct name *)0)))));
    }
    __1p = __1s;
    __1i = 0;
    while ((*__1p))
        __1i += (__1i + ((*(__1p++))));
    if (__1i < 0)
        __1i = (-__1i);
    __1firsti = (__1i = (__1i % __1mx));

    do {
        if ((__1hash[__1i]) == 0) {
            (__1hash[__1i]) = __0this->free_slot__5table;
            goto add_np;
        }
        __1n = (__1np[(__1hash[__1i])]);
        if (__1n == 0)
            error__FiPCc((int)'i', (const char *)"hashed lookup");
        if (strcmp(__1n->__O2__4expr.string, __1s) == 0)
            goto found;

        if (__1mx <= (++__1i))
            __1i = 0;
    } while (__1i != __1firsti);
    error__FPCc((const char *)"N table full");

found:
    for (;;) {
        if (__1n->n_key__4name == __1k) {
            Nold = 1;

            return __1n;
        }

        if (__1n->n_tbl_list__4name)
            __1n = __1n->n_tbl_list__4name;
        else {
            __1link = (&__1n->n_tbl_list__4name);
            goto re_allocate;
        }
    }

add_np:
    if (__0this->size__5table <= __0this->free_slot__5table) {
        grow__5tableFi(__0this, 2 * __0this->size__5table);
        return insert__5tableFP4nameUc(__0this, __1nx, __1k);
    }

    __1link = (&(__1np[(__0this->free_slot__5table++)]));

re_allocate: {
    Pname __2nw;

    __2nw = __ct__4nameFPCc((struct name *)0, (const char *)0);
    ((*__2nw)) = (*__1nx);
    {
        char *__2ps;

        __2ps = (((char *)__nw__FUl((size_t)((sizeof(char)) * (strlen(__1s) + 1)))));
        strcpy(__2ps, __1s);

        __2nw->__O2__4expr.string = (const char *)__2ps;
        __2nw->__O4__4expr.n_table = __0this;
        ((*__1link)) = __2nw;
        Nold = 0;

        return __2nw;
    }
}
}

static struct ea *__ct__2eaFUl(struct ea *__0this, size_t __2ii);

void grow__5tableFi(register struct table *__0this, int __1g) {
    short *__1hash;
    int __1j;
    int __1mx;
    Pname *__1np;
    Pname __1n;

    if (__1g <= __0this->free_slot__5table) {
        struct ea __0__V24;

        struct ea __0__V25;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"table.grow(%d,%d)",
            (const struct ea *)(((((&__0__V24)->__O1__2ea.i = ((unsigned long)__1g)), 0)),
                                (&__0__V24)),
            (const struct ea *)__ct__2eaFUl(&__0__V25, (unsigned long)__0this->free_slot__5table),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__1g <= __0this->size__5table)
        return;

    __0this->size__5table = (__1mx = (__1g + 1));

    __1np = (((struct name **)__nw__FUl((size_t)((sizeof(struct name *)) * __1mx))));
    for (__1j = 0; __1j < __0this->free_slot__5table; __1j++)
        (__1np[__1j]) = (__0this->entries__5table[__1j]);
    __dl__FPv((void *)__0this->entries__5table);
    __0this->entries__5table = __1np;

    __dl__FPv((void *)__0this->hashtbl__5table);
    __0this->hashsize__5table = (__1mx = ((__1g * 3) / 2));
    __1hash =
        (__0this->hashtbl__5table = (((short *)__nw__FUl((size_t)((sizeof(short)) * __1mx)))));
    memset((void *)__1hash, 0, __1mx * (sizeof(short)));

    for (__1j = 1; __1j < __0this->free_slot__5table; __1j++) {
        const char *__2s;
        const char *__2p;
        const char *__2q;
        int __2i;
        int __2firsti;

        __2s = (__1np[__1j])->__O2__4expr.string;

        __2p = __2s;
        __2i = 0;
        while ((*__2p))
            __2i += (__2i + ((*(__2p++))));
        if (__2i < 0)
            __2i = (-__2i);
        __2firsti = (__2i = (__2i % __1mx));

        do {
            if ((__1hash[__2i]) == 0) {
                (__1hash[__2i]) = __1j;
                goto add_np;
            }
            __1n = (__1np[(__1hash[__2i])]);
            if (__1n == 0)
                error__FiPCc((int)'i', (const char *)"hashed lookup");
            __2p = __1n->__O2__4expr.string;
            if (__2p == 0) goto nxt;    /* skip corrupt null-string entry */
            __2q = __2s;
            while (((*__2p)) && ((*__2q)))
                if (((*(__2p++))) != ((*(__2q++))))
                    goto nxt;
            if (((*__2p)) == ((*__2q)))
                goto found;
        nxt:
            if (__1mx <= (++__2i))
                __2i = 0;
        } while (__2i != __2firsti);
        error__FiPCc((int)'i', (const char *)"rehash??");

    found:
        error__FiPCc((int)'i', (const char *)"rehash failed");

    add_np:;
    }
}

void reinit__5tableFv(register struct table *__0this) {
    int __1i;

    __1i = 1;
    for (; __1i < __0this->free_slot__5table; __1i++)
        (__0this->entries__5table[__1i]) = 0;
    for (__1i = 0; __1i < __0this->hashsize__5table; __1i++)
        (__0this->hashtbl__5table[__1i]) = 0;
    __0this->free_slot__5table = 1;
}

const char *whatami__5tableFv(register struct table *__0this) {
    if (__0this == 0)
        return (const char *)"<null table>";

    if (__0this == gtbl)
        return (const char *)"global";
    if (__0this->t_name__5table)
        return (__0this->t_name__5table->__O2__4expr.string
                    ? __0this->t_name__5table->__O2__4expr.string
                    : (((const char *)"???")));

    return (const char *)"block";
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

struct ktable *__ct__6ktableFiP6ktableP4name(register struct ktable *__0this, int __1sz,
                                             struct ktable *__1nx, Pname __1n) {
    struct node *__0__X26;

    if (__0this ||
        (__0this = (struct ktable *)__nw__6ktableSFUl((size_t)(sizeof(struct ktable))))) {
        __0this = (struct ktable *)((__0__X26 = (((struct node *)__0this))),
                                    (((__0__X26 || (__0__X26 = (struct node *)__nw__FUl(
                                                        (size_t)(sizeof(struct node)))))
                                          ? (((__0__X26->base__4node = 0),
                                              (__0__X26->permanent__4node = 0)),
                                             (__0__X26->baseclass__4node = 0))
                                          : 0),
                                     __0__X26));
        ;

        __0this->base__4node = 149;
        if (__1sz == 0) {
            __0this->k_tiny__6ktable = 1;

            __0this->__O1__6ktable.k_n = 0;

            __0this->k_size__6ktable = 0;

        } else {
            __0this->k_tiny__6ktable = 0;

            __0this->__O1__6ktable.k_t = __ct__5tableFsP5tableP4name(
                (struct table *)0, (short)__1sz, (struct table *)0, __1n);

            __0this->__O1__6ktable.k_t->t_realbase__5table = 149;
        }
        __0this->k_next__6ktable = __1nx;

        __0this->k_name__6ktable = __1n;
        ;
    }
    return __0this;
}

void del__4nameFv(struct name *__0this);

void __dt__6ktableFv(register struct ktable *__0this, int __0__free) {
    if (__0this) {
        if (__0this->k_tiny__6ktable) {
            Pname __2nx;
            {
                {
                    Pname __2n;

                    __2n = __0this->__O1__6ktable.k_n;

                    for (; __2n; __2n = __2nx) {
                        __2nx = __2n->n_tbl_list__4name;
                        if (__2n && (__2n->permanent__4node == 0))
                            del__4nameFv(__2n);
                    }
                    __0this->__O1__6ktable.k_n = 0;
                }
            }
        } else
            __dt__5tableFv(__0this->__O1__6ktable.k_t, 3);
        if (__0this)
            if (__0__free & 1)
                __dl__6ktableSFPvUl((void *)__0this, (size_t)(sizeof(struct ktable)));
    }
}
Pname look__6ktableFPCcUc(register struct ktable *__0this, const char *__1s, TOK __1k) {
    if (__0this->k_tiny__6ktable) {
        {
            {
                Pname __2n;
                __2n = __0this->__O1__6ktable.k_n;

                for (; __2n; __2n = __2n->n_tbl_list__4name) {
                    if (__2n->__O2__4expr.string == 0) continue; /* skip null-string entries */
                    if ((((((*__2n->__O2__4expr.string)) == ((*__1s)))
                              ? strcmp(__2n->__O2__4expr.string, __1s)
                              : -1) == 0) &&
                        (__2n->n_key__4name == __1k))
                        return __2n;
                }
                return (struct name *)0;
            }
        }
    } else
        return look__5tableFPCcUc(__0this->__O1__6ktable.k_t, __1s, __1k);
}

Pclass classtype__4typeFv(struct type *__0this);

Pname find_cn__6ktableFPCc(register struct ktable *__0this, const char *__1s) {
    if (__0this->k_id__6ktable != 6) {
        struct ea __0__V27;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"find_cn( %s) on nonC table",
            (const struct ea *)(((&__0__V27)->__O1__2ea.p = ((const void *)__1s)), (&__0__V27)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    {
        Pclass __1cl;

        __1cl = classtype__4typeFv(__0this->k_name__6ktable->__O1__4expr.tp);
        if ((__1cl->class_base__8classdef == 0) ||
            ((__1cl->class_base__8classdef == 4) && (__1cl->templ_base__4type == 2)))
            return __0this->k_name__6ktable;

        {
            Pname __1n;

            __1n = look__6ktableFPCcUc(__0this->k_name__6ktable->n_ktable__4name, __1s,
                                       (unsigned char)0);
            return ((__1n && (__1n->base__4node == 85)) ? __1n->__O1__4name.n_hidden : __1n);
        }
    }
}

Pname insert__6ktableFP4nameUc(register struct ktable *__0this, Pname __1nn, TOK __1k) {
    if (__1nn->n_ktable__4name) {
        struct ea __0__V28;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"%n inserted twice",
            (const struct ea *)(((&__0__V28)->__O1__2ea.p = ((const void *)__1nn)), (&__0__V28)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__0this->k_tiny__6ktable) {
        Nold = 0;
        if (__0this->__O1__6ktable.k_n == 0) {
            __0this->__O1__6ktable.k_n = __1nn;
        } else {
            {
                {
                    Pname __3n;

                    __3n = __0this->__O1__6ktable.k_n;

                    for (; __3n; __3n = __3n->n_tbl_list__4name) {
                        if (__3n->__O2__4expr.string == 0 ||
                            __1nn->__O2__4expr.string == 0) continue; /* skip null-string entries */
                        if ((((((*__3n->__O2__4expr.string)) == ((*__1nn->__O2__4expr.string)))
                                  ? strcmp(__3n->__O2__4expr.string, __1nn->__O2__4expr.string)
                                  : -1) == 0) &&
                            (__3n->n_key__4name == __1k)) {
                            Nold = 1;

                            return __3n;
                        }
                        if (__3n->n_tbl_list__4name == 0) {
                            __3n->n_tbl_list__4name = __1nn;
                            break;
                        }
                    }
                }
            }
        }
        __1nn->n_key__4name = __1k;
        __1nn->n_ktable__4name = __0this;
        __1nn->n_tbl_list__4name = 0;
        __1nn->permanent__4node = 1;
        return __1nn;
    } else {
        __1nn = insert__5tableFP4nameUc(__0this->__O1__6ktable.k_t, __1nn, __1k);
        if (!Nold)
            __1nn->n_ktable__4name = __0this;
        return __1nn;
    }
}

Pname get_mem__6ktableFi(register struct ktable *__0this, int __1i) {
    struct table *__0__X29;

    if (!__0this->k_tiny__6ktable)
        return ((__0__X29 = __0this->__O1__6ktable.k_t),
                ((((__1i <= 0) || (__0__X29->free_slot__5table <= __1i))
                      ? (((struct name *)0))
                      : (__0__X29->entries__5table[__1i]))));
    else {
        Pname __2n;

        __2n = __0this->__O1__6ktable.k_n;
        for (; __2n && (__1i > 1); ((--__1i), (__2n = __2n->n_tbl_list__4name)))
            ;
        return __2n;
    }
}

void expand__6ktableFi(register struct ktable *__0this, int __1sz) {
    if (!__0this->k_tiny__6ktable)
        return;
    __0this->k_tiny__6ktable = 0;
    {
        Pname __1names;

        __1names = __0this->__O1__6ktable.k_n;
        __0this->__O1__6ktable.k_t = __ct__5tableFsP5tableP4name(
            (struct table *)0, (short)__1sz, (struct table *)0, __0this->k_name__6ktable);
        {
            {
                Pname __1nx;

                Pname __1n;

                __1n = __1names;

                for (; __1n; __1n = __1nx) {
                    __1nx = __1n->n_tbl_list__4name;
                    __1n->n_tbl_list__4name = 0;

                    __1n->__O4__4expr.n_table = 0;
                    insert__5tableFP4nameUc(__0this->__O1__6ktable.k_t, __1n, __1n->n_key__4name);
                }
            }
        }
    }
}

extern Pname insert_name__FP4nameP6ktable(Pname, Pktab);

void hoist__6ktableFv(register struct ktable *__0this) {
    if (!__0this->k_tiny__6ktable)
        error__FiPCc((int)'i', (const char *)"hoisting wrong table");
    {
        Pname __1names;

        __1names = __0this->__O1__6ktable.k_n;
        __0this->__O1__6ktable.k_n = 0;
        {
            {
                Pname __1nx;

                Pname __1n;

                __1n = __1names;

                for (; __1n; __1n = __1nx) {
                    __1nx = __1n->n_tbl_list__4name;
                    __1n->n_tbl_list__4name = 0;

                    __1n->__O4__4expr.n_table = 0;

                    __1n->n_ktable__4name = 0;
                    insert_name__FP4nameP6ktable(__1n, __0this->k_next__6ktable);
                }
            }
        }
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

extern Pstmt stmt_free__4stmt;

extern Pname name_free__4name;

extern Pexpr expr_free__4expr;

extern Pptr ptr_free__3ptr;

extern Pvec vec_free__3vec;

extern Pfct fct_free__3fct;

extern Pktab table_free__6ktable;

extern Ptable table_free__5table;

/* the end */
