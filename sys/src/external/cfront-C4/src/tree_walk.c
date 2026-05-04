
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
enum discriminator_error {
    discrim_none_valid = 0,
    discrim_bad_index = -1,
    discrim_inconsistent_node = -2
};
enum node_class {
    nc_unused = 0,
    nc_eof = 1,
    nc_virt = 2,
    nc_nlist = 3,
    nc_gen = 4,
    nc_vec = 5,
    nc_ptr = 6,
    nc_fct = 7,
    nc_table = 8,
    nc_basetype = 9,
    nc_name = 10,
    nc_expr = 11,
    nc_stmt = 12,
    nc_enumdef = 13,
    nc_classdef = 14,
    nc_baseclass = 15,
    nc_iline = 16,
    nc_ia = 17,
    nc_tpdef = 18,
    nc_ktable = 19
};

typedef void (*Error_Proc)(const char *);

typedef void (*intProc)(int);
struct HashTableEntry;
struct HashWalker;
struct Hash;
enum __Q2_4Hash13insert_action {
    probe__Q2_4Hash13insert_action = 0,
    insert__Q2_4Hash13insert_action = 1,
    replace__Q2_4Hash13insert_action = 2
};

struct Hash { /* sizeof Hash == 32 */

    struct HashTableEntry *tab__4Hash;
    int size__4Hash;
    int entry_count__4Hash;

    size_t (*key_hash_function__4Hash)(size_t);
    int (*key_key_equality_function__4Hash)(size_t, size_t);
};

extern void __dl__FPv(void *);

struct HashWalker { /* sizeof HashWalker == 16 */
    struct Hash *h__10HashWalker;
    int pos__10HashWalker;
};

void reset__10HashWalkerFv(struct HashWalker *__0this);

void error__4HashFPCc(struct Hash *__0this, const char *__1msg);

struct HashTableEntry { /* sizeof HashTableEntry == 12 */
    int key__14HashTableEntry;
    int cont__14HashTableEntry;
    char status__14HashTableEntry;
};
struct pointer_hash;

struct Hash *__ct__4HashFi(struct Hash *__0this, int __1sz);

struct pointer_hash { /* sizeof pointer_hash == 32 */

    struct HashTableEntry *tab__4Hash;
    int size__4Hash;
    int entry_count__4Hash;

    size_t (*key_hash_function__4Hash)(size_t);
    int (*key_key_equality_function__4Hash)(size_t, size_t);
};

extern size_t pointer_hash_fcn__FUl(size_t);

extern int pointer_hasheq__FUlT1(size_t, size_t);

struct Hash *__ct__4HashFR4Hash(struct Hash *__0this, struct Hash *__1a);

struct string_hash;

struct string_hash { /* sizeof string_hash == 32 */

    struct HashTableEntry *tab__4Hash;
    int size__4Hash;
    int entry_count__4Hash;

    size_t (*key_hash_function__4Hash)(size_t);
    int (*key_key_equality_function__4Hash)(size_t, size_t);
};

extern size_t string_hash_fcn__FUl(size_t);

extern int string_hasheq__FUlT1(size_t, size_t);

enum tree_node_action { tna_continue = 0, tna_stop = 1, tna_error = 2 };

typedef int (*tree_fetch_proc)(void *__0info, void *__0pointer, size_t __0length, int __0zero_stop,
                               void *__0target);

static tree_fetch_proc null_tfp =
    (int (*)(void *__0info, void *__0pointer, size_t __0length, int __0zero_stop, void *__0target))(
        ((int (*)(void *__0info, void *__0pointer, unsigned long __0length, int __0zero_stop,
                  void *__0target))0));
struct tree_walk_tree;

typedef void (*tree_pre_action)(Pnode *, int, void *, int *, int, Pnode, struct tree_walk_tree *,
                                int *);

typedef void (*tree_post_action)(Pnode *, int, void *, int *, int, Pnode, struct tree_walk_tree *);

typedef void (*errorp)(char, const char *);
struct tree_walk_control;

struct tree_walk_control { /* sizeof tree_walk_control == 80 */

    int version__17tree_walk_control;
    void *callback_info__17tree_walk_control;
    tree_fetch_proc fetcher__17tree_walk_control;
    tree_pre_action action_proc__17tree_walk_control;
    tree_post_action post_action_proc__17tree_walk_control;
    int (*i_error__17tree_walk_control)(int, const char *);
    int call_i_error__17tree_walk_control;
    struct Hash *nodes_seen_hash__17tree_walk_control;

    int resolve_by_name__17tree_walk_control;
    int alloc_stack_bytes__17tree_walk_control;

    int dont_chase_lists_top__17tree_walk_control;
};
struct patch_tree;

typedef struct patch_tree *Ppatch_tree;

struct patch_tree { /* sizeof patch_tree == 16 */

    Pnode node__10patch_tree;
    Ppatch_tree next__10patch_tree;
};

extern Ppatch_tree head__10patch_tree;
extern struct Hash *ht__10patch_tree;
struct walker;

struct walker { /* sizeof walker == 112 */
    struct tree_walk_control control__6walker;
    Pnode orig_addr__6walker;
    struct Hash *nodes_seen_hash__6walker;
    int depth__6walker;
    int made_ht__6walker;
    struct tree_walk_tree *cur_tree__6walker;
};

int walk___6walkerFRP4node(struct walker *__0this, Pnode *);

int fetch__6walkerFPvUlRPv(struct walker *__0this, void *, size_t, void **);

struct tree_walk_tree { /* sizeof tree_walk_tree == 16 */

    struct tree_walk_tree *parent__14tree_walk_tree;
    char storage__14tree_walk_tree[1];
};

int walk__6walkerFRP4node(struct walker *__0this, Pnode *);

int walk___6walkerFRP4node(register struct walker *__0this, Pnode *__1n) {
    if ((*__1n)) {
        int __2save_depth;
        struct tree_walk_tree *__2save_cur_tree;

        __2save_depth = __0this->depth__6walker;
        __2save_cur_tree = __0this->cur_tree__6walker;

        __0this->depth__6walker++;
        if (__0this->control__6walker.alloc_stack_bytes__17tree_walk_control) {
            __0this->cur_tree__6walker = (((struct tree_walk_tree *)(((char *)__nw__FUl(
                (size_t)((sizeof(char)) *
                         (__0this->control__6walker.alloc_stack_bytes__17tree_walk_control +
                          (sizeof(struct tree_walk_tree)))))))));
            __0this->cur_tree__6walker->parent__14tree_walk_tree = __2save_cur_tree;
        }
        {
            int __2r;

            __2r = walk__6walkerFRP4node(__0this, __1n);
            __0this->depth__6walker = __2save_depth;
            return __2r;
        }
    } else
        return (int)0;
}

struct walker *__ct__6walkerFRC17tree_walk_control(register struct walker *__0this,
                                                   const struct tree_walk_control *__1c) {
    register struct tree_walk_control *__0__X18;

    if (__0this || (__0this = (struct walker *)__nw__FUl((size_t)(sizeof(struct walker))))) {
        ((__0__X18 = (&__0this->control__6walker)),
         (((__0__X18 || (__0__X18 = (struct tree_walk_control *)__nw__FUl(
                             (size_t)(sizeof(struct tree_walk_control)))))
               ? ((__0__X18->version__17tree_walk_control = 1),
                  ((__0__X18->callback_info__17tree_walk_control = 0),
                   ((__0__X18->fetcher__17tree_walk_control = null_tfp),
                    ((__0__X18->call_i_error__17tree_walk_control = 0),
                     ((__0__X18->nodes_seen_hash__17tree_walk_control = 0),
                      ((__0__X18->resolve_by_name__17tree_walk_control = 1),
                       ((__0__X18->alloc_stack_bytes__17tree_walk_control = 0),
                        ((__0__X18->post_action_proc__17tree_walk_control = 0),
                         (__0__X18->dont_chase_lists_top__17tree_walk_control = 0)))))))))
               : 0),
          __0__X18));
        __0this->control__6walker = (*__1c);
        __0this->made_ht__6walker = 0;
        if (((*__1c)).nodes_seen_hash__17tree_walk_control)
            __0this->nodes_seen_hash__6walker = ((*__1c)).nodes_seen_hash__17tree_walk_control;
        else {
            register struct pointer_hash *__0__X19;

            __0this->nodes_seen_hash__6walker =
                (struct Hash
                     *)((__0__X19 = 0),
                        (((__0__X19 || (__0__X19 = (struct pointer_hash *)__nw__FUl(
                                            (size_t)(sizeof(struct pointer_hash)))))
                              ? ((__0__X19 = (struct pointer_hash *)__ct__4HashFi(
                                      ((struct Hash *)__0__X19), (int)((unsigned long)100))),
                                 ((__0__X19->key_hash_function__4Hash = (pointer_hash_fcn__FUl)),
                                  (__0__X19->key_key_equality_function__4Hash =
                                       (pointer_hasheq__FUlT1))))
                              : 0),
                         __0__X19));
            __0this->made_ht__6walker = 1;
        }
        __0this->depth__6walker = 0;
        __0this->cur_tree__6walker = 0;
    }
    return __0this;
}

extern Ppatch_tree head__10patch_tree;
extern struct Hash *ht__10patch_tree;

void action__4HashFUlT1Q2_4Hash13insert_actionRUlT4(struct Hash *__0this, size_t __1key,
                                                    size_t __1val, int __1what, size_t *__1found,
                                                    size_t *__1old_val);

Pnode probe__10patch_treeSFP4node(Pnode __1n) {
    size_t __1found;

    size_t __1replacement;

    __1found = 0;

    __1replacement = 0;

    action__4HashFUlT1Q2_4Hash13insert_actionRUlT4(ht__10patch_tree, ((unsigned long)__1n),
                                                   (unsigned long)0, 0, (size_t *)(&__1found),
                                                   (size_t *)(&__1replacement));

    return (__1found ? (((struct node *)__1replacement)) : __1n);
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

void patch_a_ktable__10patch_treeSFP6ktable(Pktab __1tbl) {
    __1tbl->k_next__6ktable = (((struct ktable *)((
        (struct ktable *)probe__10patch_treeSFP4node((struct node *)__1tbl->k_next__6ktable)))));
}

void patch_a_table__10patch_treeSFP5table(Ptable __1tbl) {
    {
        {
            int __1i;

            __1i = 0;

            for (; __1i < __1tbl->size__5table; __1i++) {
                if (__1tbl->entries__5table[__1i]) {
                    (__1tbl->entries__5table[__1i]) =
                        (((struct name *)(((struct name *)probe__10patch_treeSFP4node(
                            (struct node *)(__1tbl->entries__5table[__1i]))))));
                }
            }

            __1tbl->next__5table = (((struct table *)(((struct table *)probe__10patch_treeSFP4node(
                (struct node *)__1tbl->next__5table)))));
        }
    }
}

void patch_a_name__10patch_treeSFP4name(Pname __1n) {
    __1n->n_ktable__4name = (((struct ktable *)((
        (struct ktable *)probe__10patch_treeSFP4node((struct node *)__1n->n_ktable__4name)))));
}

void patch__10patch_treeSFv(void) {
    while (head__10patch_tree) {
        if (head__10patch_tree->node__10patch_tree->base__4node == 149) {
            patch_a_ktable__10patch_treeSFP6ktable(
                ((struct ktable *)(((struct ktable *)head__10patch_tree->node__10patch_tree))));
        } else if (head__10patch_tree->node__10patch_tree->base__4node == 142) {
            patch_a_table__10patch_treeSFP5table(
                ((struct table *)(((struct table *)head__10patch_tree->node__10patch_tree))));
        } else {
            patch_a_name__10patch_treeSFP4name(
                ((struct name *)(((struct name *)head__10patch_tree->node__10patch_tree))));
        }

        {
            Ppatch_tree __2p;

            __2p = head__10patch_tree->next__10patch_tree;
            ((head__10patch_tree
                  ? (((void)(head__10patch_tree
                                 ? (((void)(((void)__dl__FPv((void *)head__10patch_tree)))))
                                 : (((void)0)))))
                  : (((void)0))));
            head__10patch_tree = __2p;
        }
    }
}

int walk_tree__FR17tree_walk_controlRP4node(struct tree_walk_control *__1c, Pnode *__1n) {
    struct walker __1w;

    struct Hash *__0__X17;

    struct Hash *__2__X20;

    __ct__6walkerFRC17tree_walk_control(&__1w, (const struct tree_walk_control *)__1c);

    ((__2__X20 = ((*__1c)).nodes_seen_hash__17tree_walk_control),
     (((head__10patch_tree = 0), (ht__10patch_tree = __2__X20)), (((void)0))));
    {
        int __1action;

        __1action = walk__6walkerFRP4node(&__1w, __1n);
        patch__10patch_treeSFv();
        {
            ((((void)(((&__1w)->made_ht__6walker
                           ? (((void)((__0__X17 = (&__1w)->nodes_seen_hash__6walker),
                                      ((__0__X17 ? (((void)(__dl__FPv((void *)__0__X17->tab__4Hash),
                                                            (__0__X17 ? (((void)(((void)__dl__FPv(
                                                                            (void *)__0__X17)))))
                                                                      : (((void)0))))))
                                                 : (((void)0)))))))
                           : (((void)0))),
                      (((void)(((void)0))))))));

            return __1action;
        }
    }
}

extern int sprintf(char *, const char *, ...);

void error__6walkerFPCcUl(register struct walker *__0this, const char *__1format, size_t __1v) {
    if (__0this->control__6walker.call_i_error__17tree_walk_control) {
        char __2buf[1000];

        sprintf((char *)__2buf, __1format, __1v);
        ((*__0this->control__6walker.i_error__17tree_walk_control))((int)'i', (const char *)__2buf);
    }
}

extern void free(void *);

void free_fetched__6walkerFPv(struct walker *__0this, void *__1addr) {
    if (__0this->control__6walker.fetcher__17tree_walk_control != null_tfp)
        free(__1addr);
}

int fetch__6walkerFPvUlRPv(register struct walker *__0this, void *__1addr, size_t __1length,
                           void **__1taddr) {
    int __1err;

    if (__0this->control__6walker.fetcher__17tree_walk_control == null_tfp) {
        ((*__1taddr)) = __1addr;
        return 0;
    } else {
        ((*__1taddr)) = (((void *)(((char *)__nw__FUl((size_t)((sizeof(char)) * __1length))))));
        if (((*__1taddr)) == 0) {
            error__6walkerFPCcUl(__0this, (const char *)"walker::fetch: failed to malloc %d bytes.",
                                 __1length);

            return 1;
        }

        __1err = ((*__0this->control__6walker.fetcher__17tree_walk_control))(
            __0this->control__6walker.callback_info__17tree_walk_control, __1addr, __1length, 0,
            (*__1taddr));
        if (__1err) {
            error__6walkerFPCcUl(__0this, (const char *)"walker::fetch: fetcher returned %d.",
                                 (unsigned long)__1err);
            return 1;
        }
    }
    error__FiPCc((int)'i', (const char *)"fall off end of walker::fetch()");
    return 0;
}

extern int classify_node__FP4nodeRi(Pnode, int *);

int a_virt__6walkerFP4nodeP4virtRP4node(struct walker *__0this, Pnode, Pvirt, Pnode *);

int a_name_list__6walkerFP4nodeP9name_listRP4node(struct walker *__0this, Pnode, Plist, Pnode *);

int a_iline__6walkerFP4nodeP5ilineRP4node(struct walker *__0this, Pnode, Pin, Pnode *);

int a_gen__6walkerFP4nodeP3genRP4node(struct walker *__0this, Pnode, Pgen, Pnode *);

int a_tpdef__6walkerFP4nodeP4typeRP4node(struct walker *__0this, Pnode, Ptype, Pnode *);

int a_vec__6walkerFP4nodeP3vecRP4node(struct walker *__0this, Pnode, Pvec, Pnode *);

int a_ptr__6walkerFP4nodeP3ptrRP4node(struct walker *__0this, Pnode, Pptr, Pnode *);

int a_fct__6walkerFP4nodeP3fctRP4node(struct walker *__0this, Pnode, Pfct, Pnode *);

int a_table__6walkerFP4nodeP5tableRP4node(struct walker *__0this, Pnode, Ptable, Pnode *);

int a_ktable__6walkerFP4nodeP6ktableRP4node(struct walker *__0this, Pnode, Pktab, Pnode *);

int a_basetype__6walkerFP4nodeP8basetypeRP4node(struct walker *__0this, Pnode, Pbase, Pnode *);

int a_name__6walkerFP4nodeP4nameRP4node(struct walker *__0this, Pnode, Pname, Pnode *);

int a_expr__6walkerFP4nodeP4exprRP4node(struct walker *__0this, Pnode, Pexpr, Pnode *);

int a_stmt__6walkerFP4nodeP4stmtRP4node(struct walker *__0this, Pnode, Pstmt, Pnode *);

int a_enumdef__6walkerFP4nodeP7enumdefRP4node(struct walker *__0this, Pnode, Penum, Pnode *);

int a_classdef__6walkerFP4nodeP8classdefRP4node(struct walker *__0this, Pnode, Pclass, Pnode *);

int a_ia__6walkerFP4nodeP2iaRP4node(struct walker *__0this, Pnode, Pia, Pnode *);

int a_baseclass__6walkerFP4nodeP6baseclRP4node(struct walker *__0this, Pnode, Pbcl, Pnode *);

int walk__6walkerFRP4node(register struct walker *__0this, Pnode *__1top) {
    Pnode __1replacement;
    int __1err;
    int __1class_err;
    int __1nclass;
    Pnode __1node;

    __1replacement = 0;

    __1node = 0;

    __0this->orig_addr__6walker = ((*__1top));

    if (((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) {
        int __2__Xret00q2hiobkawcko;

        void *__2__Xt00q2hiobkawcko;

        if (((__2__Xret00q2hiobkawcko =
                  fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct node)),
                                         (void **)(&__2__Xt00q2hiobkawcko))),
             (((!__2__Xret00q2hiobkawcko) ? ((((*((Pnode *)(&__1node)))) = (((struct node *)((
                                                  (struct node *)__2__Xt00q2hiobkawcko))))),
                                             0)
                                          : 0),
              __2__Xret00q2hiobkawcko)))
            return (int)2;
    } else
        __1node = ((*__1top));

    __1nclass = classify_node__FP4nodeRi(__1node, (int *)(&__1class_err));

    if (__1class_err) {
        error__6walkerFPCcUl(__0this, (const char *)"walker::walk: unknown node type %d.",
                             (unsigned long)__1node->base__4node);
        free_fetched__6walkerFPv(__0this, ((void *)__1node));
        __1err = 2;
        goto Return;
    }

    switch (__1nclass) {
        int __2__Xret00q2hiobkawcko;

        void *__2__Xt00q2hiobkawcko;

    default:
    case 0:
        error__6walkerFPCcUl(__0this, (const char *)"walker::walk: unused node type %d.",
                             (unsigned long)__1node->base__4node);
        __1err = 2;
        goto Return;

    case 1:
        break;

    case 2:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct virt)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_virt__6walkerFP4nodeP4virtRP4node(__0this, (*__1top),
                                                     ((struct virt *)(((struct virt *)__1node))),
                                                     (Pnode *)(&__1replacement));
        break;

    case 3:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct name_list)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_name_list__6walkerFP4nodeP9name_listRP4node(
            __0this, (*__1top), ((struct name_list *)(((struct name_list *)__1node))),
            (Pnode *)(&__1replacement));
        break;

    case 16:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct iline)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_iline__6walkerFP4nodeP5ilineRP4node(
            __0this, (*__1top), ((struct iline *)(((struct iline *)__1node))),
            (Pnode *)(&__1replacement));
        break;

    case 4:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct gen)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_gen__6walkerFP4nodeP3genRP4node(__0this, (*__1top),
                                                   ((struct gen *)(((struct gen *)__1node))),
                                                   (Pnode *)(&__1replacement));
        break;

    case 18:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct type)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_tpdef__6walkerFP4nodeP4typeRP4node(__0this, (*__1top),
                                                      ((struct type *)(((struct type *)__1node))),
                                                      (Pnode *)(&__1replacement));
        break;

    case 5:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct vec)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_vec__6walkerFP4nodeP3vecRP4node(__0this, (*__1top),
                                                   ((struct vec *)(((struct vec *)__1node))),
                                                   (Pnode *)(&__1replacement));
        break;

    case 6:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct ptr)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_ptr__6walkerFP4nodeP3ptrRP4node(__0this, (*__1top),
                                                   ((struct ptr *)(((struct ptr *)__1node))),
                                                   (Pnode *)(&__1replacement));
        break;

    case 7:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct fct)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_fct__6walkerFP4nodeP3fctRP4node(__0this, (*__1top),
                                                   ((struct fct *)(((struct fct *)__1node))),
                                                   (Pnode *)(&__1replacement));
        break;

    case 8:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct table)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_table__6walkerFP4nodeP5tableRP4node(
            __0this, (*__1top), ((struct table *)(((struct table *)__1node))),
            (Pnode *)(&__1replacement));
        break;

    case 19:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct ktable)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_ktable__6walkerFP4nodeP6ktableRP4node(
            __0this, (*__1top), ((struct ktable *)(((struct ktable *)__1node))),
            (Pnode *)(&__1replacement));
        break;

    case 9:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct basetype)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_basetype__6walkerFP4nodeP8basetypeRP4node(
            __0this, (*__1top), ((struct basetype *)(((struct basetype *)__1node))),
            (Pnode *)(&__1replacement));
        break;

    case 10:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct name)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_name__6walkerFP4nodeP4nameRP4node(__0this, (*__1top),
                                                     ((struct name *)(((struct name *)__1node))),
                                                     (Pnode *)(&__1replacement));
        break;

    case 11:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct expr)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_expr__6walkerFP4nodeP4exprRP4node(__0this, (*__1top),
                                                     ((struct expr *)(((struct expr *)__1node))),
                                                     (Pnode *)(&__1replacement));
        break;

    case 12:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct stmt)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_stmt__6walkerFP4nodeP4stmtRP4node(__0this, (*__1top),
                                                     ((struct stmt *)(((struct stmt *)__1node))),
                                                     (Pnode *)(&__1replacement));
        break;

    case 13:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct enumdef)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_enumdef__6walkerFP4nodeP7enumdefRP4node(
            __0this, (*__1top), ((struct enumdef *)(((struct enumdef *)__1node))),
            (Pnode *)(&__1replacement));
        break;

    case 14:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct classdef)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_classdef__6walkerFP4nodeP8classdefRP4node(
            __0this, (*__1top), ((struct classdef *)(((struct classdef *)__1node))),
            (Pnode *)(&__1replacement));
        break;

    case 17:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct ia)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_ia__6walkerFP4nodeP2iaRP4node(__0this, (*__1top),
                                                 ((struct ia *)(((struct ia *)__1node))),
                                                 (Pnode *)(&__1replacement));
        break;

    case 15:
        ((__2__Xret00q2hiobkawcko =
              fetch__6walkerFPvUlRPv(__0this, (((void *)((*__1top)))), (sizeof(struct basecl)),
                                     (void **)(&__2__Xt00q2hiobkawcko))),
         (((!__2__Xret00q2hiobkawcko)
               ? ((((*((Pnode *)(&__1node)))) =
                       (((struct node *)(((struct node *)__2__Xt00q2hiobkawcko))))),
                  0)
               : 0),
          __2__Xret00q2hiobkawcko));
        __1err = a_baseclass__6walkerFP4nodeP6baseclRP4node(
            __0this, (*__1top), ((struct basecl *)(((struct basecl *)__1node))),
            (Pnode *)(&__1replacement));
        break;
    }

    if (__1replacement) {
        if (((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) {
            error__6walkerFPCcUl(
                __0this,
                (const char *)"walker::walk: Attempt to replace tree in cross-address space mode.",
                (unsigned long)0);
            __1err = 2;
        } else
            ((*__1top)) = __1replacement;
    }

    if (__0this->control__6walker.post_action_proc__17tree_walk_control && (__1err != 2)) {
        int __2post_err;
        Pnode *__2post_repl;

        __2post_repl = (&__1node);

        ((*__0this->control__6walker.post_action_proc__17tree_walk_control))(
            __2post_repl, __1nclass, __0this->control__6walker.callback_info__17tree_walk_control,
            (int *)(&__2post_err), __0this->depth__6walker, __0this->orig_addr__6walker,
            (struct tree_walk_tree *)__0this->cur_tree__6walker);
        if (__2post_err != 0)
            __1err = __2post_err;
        if (((*__2post_repl)) != __1node) {
            if (((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) {
                error__6walkerFPCcUl(
                    __0this,
                    (const char
                         *)"walker::walk: Attempt to replace tree in cross-address space mode.",
                    (unsigned long)0);
                __1err = 2;
            } else
                ((*__1top)) = ((*__2post_repl));
        }
    }

    free_fetched__6walkerFPv(__0this, ((void *)__1node));

Return:
    return __1err;
}

int pre_act_on_node__6walkerFP4node10node_classT1RP4node(register struct walker *__0this,
                                                         Pnode __1node, int __1nc,
                                                         Pnode __1node_copy,
                                                         Pnode *__1replacement) {
    size_t __1found;
    size_t __1old_node;
    int __1action;
    Pnode __1new_node;
    int __1register_in_hash;

    __1register_in_hash = 1;

    action__4HashFUlT1Q2_4Hash13insert_actionRUlT4(__0this->nodes_seen_hash__6walker,
                                                   ((unsigned long)__1node), (unsigned long)0, 0,
                                                   (size_t *)(&__1found), (size_t *)(&__1old_node));

    if (__1found) {
        __1new_node = (((struct node *)__1old_node));
        if (__1new_node != __1node)
            ((*__1replacement)) = __1new_node;
        return (int)1;
    }

    __1new_node =
        ((((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp)) && __1node_copy)
             ? __1node_copy
             : __1node);

    ((*__0this->control__6walker.action_proc__17tree_walk_control))(
        (Pnode *)(&__1new_node), __1nc,
        __0this->control__6walker.callback_info__17tree_walk_control, (int *)(&__1action),
        __0this->depth__6walker, __0this->orig_addr__6walker,
        (struct tree_walk_tree *)__0this->cur_tree__6walker, (int *)(&__1register_in_hash));

    {
        size_t __1zero1;

        size_t __1zero2;

        __1zero1 = 0;

        __1zero2 = 0;
        if (((__1action != 2) &&
             (!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp)))) &&
            (__1new_node != __1node)) {
            ((*__1replacement)) = __1new_node;

            if (__1register_in_hash)
                action__4HashFUlT1Q2_4Hash13insert_actionRUlT4(
                    __0this->nodes_seen_hash__6walker, ((unsigned long)__1node),
                    ((unsigned long)__1new_node), 1, (size_t *)(&__1zero1), (size_t *)(&__1zero2));
        } else {
            if (__1register_in_hash)
                action__4HashFUlT1Q2_4Hash13insert_actionRUlT4(
                    __0this->nodes_seen_hash__6walker, ((unsigned long)__1node),
                    ((unsigned long)__1node), 1, (size_t *)(&__1zero1), (size_t *)(&__1zero2));
        }
        return __1action;
    }
}

int a_ktable__6walkerFP4nodeP6ktableRP4node(register struct walker *__0this, Pnode __1ta,
                                            Pktab __1t, Pnode *__1replacement) {
    int __1action;

    Ptable *__2__X21;

    Pname *__2__X22;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 19, ((struct node *)(((struct node *)__1t))), __1replacement);
    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1t = (((struct ktable *)(((struct ktable *)((*__1replacement))))));

    __1action = ((__2__X21 = (&__1t->__O1__6ktable.k_t)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X21))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X22 = (&__1t->k_name__6ktable)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X22))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

int a_table__6walkerFP4nodeP5tableRP4node(register struct walker *__0this, Pnode __1ta, Ptable __1t,
                                          Pnode *__1replacement) {
    int __1action;
    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 8, ((struct node *)(((struct node *)__1t))), __1replacement);
    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1t = (((struct table *)(((struct table *)((*__1replacement))))));

    {
        {
            int __1i;

            Pstmt *__2__X24;

            Pname *__2__X25;

            __1i = 0;

            for (; __1i < __1t->size__5table; __1i++) {
                if ((__1t->entries__5table[__1i]) &&
                    ((__1t->entries__5table[__1i])->base__4node == 123)) {
                    Pname *__2__X23;

                    __1action = ((__2__X23 = (&(__1t->entries__5table[__1i]))),
                                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X23))));

                    if (__1action == 2)
                        return __1action;
                }
            }

            __1action = ((__2__X24 = (&__1t->real_block__5table)),
                         (walk___6walkerFRP4node(__0this, ((struct node **)__2__X24))));

            if (__1action == 2)
                return __1action;

            __1action = ((__2__X25 = (&__1t->t_name__5table)),
                         (walk___6walkerFRP4node(__0this, ((struct node **)__2__X25))));

            if (__1action == 2)
                return __1action;

            return (int)0;
        }
    }
}

int a_enumdef__6walkerFP4nodeP7enumdefRP4node(register struct walker *__0this, Pnode __1ta,
                                              Penum __1e, Pnode *__1replacement) {
    int __1action;

    Pclass *__2__X26;

    Pname *__2__X27;

    Pbase *__2__X28;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 13, ((struct node *)(((struct node *)__1e))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1e = (((struct enumdef *)(((struct enumdef *)((*__1replacement))))));

    __1action = ((__2__X26 = (&__1e->in_class__4type)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X26))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X27 = (&__1e->mem__7enumdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X27))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X28 = (&__1e->e_type__7enumdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X28))));

    return (int)0;
}

struct velem { /* sizeof velem == 16 */
    Pname n__5velem;
    int offset__5velem;
};

int a_virt__6walkerFP4nodeP4virtRP4node(register struct walker *__0this, Pnode __1ta, Pvirt __1v,
                                        Pnode *__1replacement) {
    int __1nx;
    int __1action;

    struct velem *__1v_virt_init;

    Pclass *__2__X30;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 13, ((struct node *)(((struct node *)__1v))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1v = (((struct virt *)(((struct virt *)((*__1replacement))))));

    ;

    if (((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) {
        void *__2t;
        fetch__6walkerFPvUlRPv(__0this, ((void *)__1v->virt_init__4virt),
                               __1v->n_init__4virt * (sizeof(struct velem)), (void **)(&__2t));

        __1v_virt_init = (((struct velem *)(((struct velem *)__2t))));
    } else
        __1v_virt_init = __1v->virt_init__4virt;

    for (__1nx = 0; __1nx < __1v->n_init__4virt; __1nx++) {
        Pname *__2__X29;

        __1action = ((__2__X29 = (&(__1v_virt_init[__1nx]).n__5velem)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X29))));

        if (__1action == 2)
            return __1action;
    }

    if (((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp)))
        free_fetched__6walkerFPv(__0this, ((void *)__1v_virt_init));

    __1action = ((__2__X30 = (&__1v->vclass__4virt)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X30))));

    return (int)0;
}

int a_classdef__6walkerFP4nodeP8classdefRP4node(register struct walker *__0this, Pnode __1ta,
                                                Pclass __1c, Pnode *__1replacement) {
    int __1action;

    Pbcl *__2__X31;

    Pname *__2__X32;

    Ptable *__2__X33;

    Pktab *__2__X34;

    Plist *__2__X35;

    Pname *__2__X36;

    Pclass *__2__X37;

    Ptype *__2__X38;

    Pvirt *__2__X39;

    Pname *__2__X40;

    Pname *__2__X41;

    Pname *__2__X42;

    Pname *__2__X43;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 14, ((struct node *)(((struct node *)__1c))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1c = (((struct classdef *)(((struct classdef *)((*__1replacement))))));

    __1action = ((__2__X31 = (&__1c->baselist__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X31))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X32 = (&__1c->mem_list__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X32))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X33 = (&__1c->memtbl__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X33))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X34 = (&__1c->k_tbl__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X34))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X35 = (&__1c->friend_list__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X35))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X36 = (&__1c->pubdef__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X36))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X37 = (&__1c->in_class__4type)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X37))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X38 = (&__1c->this_type__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X38))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X39 = (&__1c->virt_list__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X39))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X40 = (&__1c->c_ctor__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X40))));

    if (__1action == 2)
        return __1action;
    __1action = ((__2__X41 = (&__1c->c_dtor__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X41))));

    if (__1action == 2)
        return __1action;
    __1action = ((__2__X42 = (&__1c->c_itor__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X42))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X43 = (&__1c->conv__8classdef)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X43))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

int discriminator__8basetypeFi(struct basetype *__0this, int);

int a_basetype__6walkerFP4nodeP8basetypeRP4node(register struct walker *__0this, Pnode __1ta,
                                                Pbase __1b, Pnode *__1replacement) {
    int __1derr;

    int __1action;

    Pname *__2__X44;

    Ptable *__2__X45;

    Pname *__2__X46;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 9, ((struct node *)(((struct node *)__1b))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1b = (((struct basetype *)(((struct basetype *)((*__1replacement))))));

    __1action = ((__2__X44 = (&__1b->b_name__8basetype)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X44))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X45 = (&__1b->b_table__8basetype)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X45))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X46 = (&__1b->b_xname__8basetype)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X46))));

    if (__1action == 2)
        return __1action;

    switch (__1derr = discriminator__8basetypeFi(__1b, 0)) {
        Ptype *__2__X47;

    case 0:
        break;
    case 1:
        __1action = ((__2__X47 = (&__1b->__O1__8basetype.b_fieldtype)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X47))));
        if (__1action == 2)
            return __1action;
        break;
    case 2:
        break;
    default:
        error__6walkerFPCcUl(__0this, (const char *)"a_basetype: discrim error %d.",
                             (unsigned long)__1derr);

        return (int)2;
    }

    return (int)0;
}

int a_fct__6walkerFP4nodeP3fctRP4node(register struct walker *__0this, Pnode __1ta, Pfct __1f,
                                      Pnode *__1replacement) {
    int __1action;

    Ptype *__2__X48;

    Pname *__2__X49;

    Ptype *__2__X50;

    Pname *__2__X51;

    Pclass *__2__X52;

    Pblock *__2__X53;

    Pname *__2__X54;

    Pexpr *__2__X55;

    Pname *__2__X56;

    Pname *__2__X57;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 7, ((struct node *)(((struct node *)__1f))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1f = (((struct fct *)(((struct fct *)((*__1replacement))))));

    __1action = ((__2__X48 = (&__1f->returns__3fct)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X48))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X49 = (&__1f->argtype__3fct)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X49))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X50 = (&__1f->s_returns__3fct)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X50))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X51 = (&__1f->f_this__3fct)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X51))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X52 = (&__1f->memof__3fct)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X52))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X53 = (&__1f->body__3fct)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X53))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X54 = (&__1f->f_init__3fct)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X54))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X55 = (&__1f->f_expr__3fct)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X55))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X56 = (&__1f->f_result__3fct)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X56))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X57 = (&__1f->f_args__3fct)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X57))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

int a_name_list__6walkerFP4nodeP9name_listRP4node(register struct walker *__0this, Pnode __1ta,
                                                  Plist __1l, Pnode *__1replacement) {
    int __1cl_error;
    int __1action;

    Pname *__2__X59;

    Plist *__2__X60;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 3, ((struct node *)(((struct node *)__1l))), __1replacement);

    if (__1action == 1) {
        if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
            ((*__1replacement)))
            __1l = (((struct name_list *)(((struct name_list *)((*__1replacement))))));
        __1cl_error = 0;
        if ((classify_node__FP4nodeRi(((struct node *)(((struct node *)__1l))),
                                      (int *)(&__1cl_error)) == 3) &&
            (!__1cl_error)) {
            Plist *__2__X58;

            __1action = ((__2__X58 = (&__1l->l__9name_list)),
                         (walk___6walkerFRP4node(__0this, ((struct node **)__2__X58))));

            if (__1action == 2)
                return __1action;
        }
    }

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1l = (((struct name_list *)(((struct name_list *)((*__1replacement))))));

    __1action = ((__2__X59 = (&__1l->f__9name_list)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X59))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X60 = (&__1l->l__9name_list)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X60))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

int a_tpdef__6walkerFP4nodeP4typeRP4node(register struct walker *__0this, Pnode __1ta, Ptype __1t,
                                         Pnode *__1replacement) {
    int __1action;

    Pclass *__2__X61;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 18, ((struct node *)(((struct node *)__1t))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1t = (((struct type *)(((struct type *)((*__1replacement))))));

    __1action = ((__2__X61 = (&__1t->in_class__4type)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X61))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

int a_gen__6walkerFP4nodeP3genRP4node(register struct walker *__0this, Pnode __1ta, Pgen __1g,
                                      Pnode *__1replacement) {
    int __1action;

    Plist *__2__X62;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 4, ((struct node *)(((struct node *)__1g))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1g = (((struct gen *)(((struct gen *)((*__1replacement))))));

    __1action = ((__2__X62 = (&__1g->fct_list__3gen)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X62))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

int a_vec__6walkerFP4nodeP3vecRP4node(register struct walker *__0this, Pnode __1ta, Pvec __1v,
                                      Pnode *__1replacement) {
    int __1action;

    Ptype *__2__X63;

    Pexpr *__2__X64;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 5, ((struct node *)(((struct node *)__1v))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1v = (((struct vec *)(((struct vec *)((*__1replacement))))));

    __1action = ((__2__X63 = (&__1v->typ__5pvtyp)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X63))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X64 = (&__1v->dim__3vec)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X64))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

int a_ptr__6walkerFP4nodeP3ptrRP4node(register struct walker *__0this, Pnode __1ta, Pptr __1p,
                                      Pnode *__1replacement) {
    int __1action;

    Ptype *__2__X65;

    Pclass *__2__X66;

    Pname *__2__X67;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 6, ((struct node *)(((struct node *)__1p))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1p = (((struct ptr *)(((struct ptr *)((*__1replacement))))));

    __1action = ((__2__X65 = (&__1p->typ__5pvtyp)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X65))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X66 = (&__1p->memof__3ptr)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X66))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X67 = (&__1p->ptname__3ptr)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X67))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

int discriminator__4exprFi(struct expr *__0this, int);

int a_expr_guts__6walkerFP4expr(register struct walker *__0this, Pexpr __1e) {
    int __1derr;
    int __1action;

    switch (__1derr = discriminator__4exprFi(__1e, 0)) {
        Ptype *__2__X68;

    case 1:
        __1action = ((__2__X68 = (&__1e->__O1__4expr.tp)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X68))));
        if (__1action == 2)
            return __1action;
        break;
    case 0:
        break;
    default:
        error__6walkerFPCcUl(__0this, (const char *)"a_expr: discrim error %d on union 0.",
                             (unsigned long)__1derr);

        return (int)2;
    }

    switch (__1derr = discriminator__4exprFi(__1e, 1)) {
        Pexpr *__2__X69;

    case 0:
        break;
    default:
        error__6walkerFPCcUl(__0this, (const char *)"a_expr: discrim error %d on union 1.",
                             (unsigned long)__1derr);

        return (int)2;
    case 1:
        __1action = ((__2__X69 = (&__1e->__O2__4expr.e1)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X69))));
        if (__1action == 2)
            return __1action;
        break;
    case 2:
        break;
    case 3:
        break;
    }

    switch (__1derr = discriminator__4exprFi(__1e, 2)) {
        Pexpr *__2__X71;

        Ptype *__2__X72;

    case 0:
        break;
    default:
        error__6walkerFPCcUl(__0this, (const char *)"a_expr: discrim error %d on union 2.",
                             (unsigned long)__1derr);

        return (int)2;
    case 1:
        if (__1e->base__4node != 140) {
            Pexpr *__2__X70;

            __1action = ((__2__X70 = (&__1e->__O3__4expr.e2)),
                         (walk___6walkerFRP4node(__0this, ((struct node **)__2__X70))));

            if (__1action == 2)
                return __1action;
        }
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        __1action = ((__2__X71 = (&__1e->__O3__4expr.n_initializer)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X71))));
        if (__1action == 2)
            return __1action;
        break;
    case 5:
        __1action = ((__2__X72 = (&__1e->__O3__4expr.tpdef)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X72))));
        if (__1action == 2)
            return __1action;
        break;
    }

    switch (__1derr = discriminator__4exprFi(__1e, 3)) {
        Ptype *__2__X73;

        Pname *__2__X74;

        Pexpr *__2__X75;

        Pexpr *__2__X76;

        Ptype *__2__X77;

        Ptable *__2__X78;

        Pin *__2__X79;

    case 0:
        break;
    default:
        error__6walkerFPCcUl(__0this, (const char *)"a_expr: discrim error %d on union 3.",
                             (unsigned long)__1derr);

        return (int)2;
    case 1:
        __1action = ((__2__X73 = (&__1e->__O4__4expr.tp2)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X73))));
        if (__1action == 2)
            return __1action;
        break;
    case 2:
        __1action = ((__2__X74 = (&__1e->__O4__4expr.fct_name)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X74))));
        if (__1action == 2)
            return __1action;
        break;
    case 3:
        __1action = ((__2__X75 = (&__1e->__O4__4expr.cond)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X75))));
        if (__1action == 2)
            return __1action;
        break;
    case 4:
        __1action = ((__2__X76 = (&__1e->__O4__4expr.mem)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X76))));
        if (__1action == 2)
            return __1action;
        break;
    case 5:
        __1action = ((__2__X77 = (&__1e->__O4__4expr.as_type)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X77))));
        if (__1action == 2)
            return __1action;
        break;
    case 6:
        __1action = ((__2__X78 = (&__1e->__O4__4expr.n_table)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X78))));
        if (__1action == 2)
            return __1action;
        break;
    case 7:
        __1action = ((__2__X79 = (&__1e->__O4__4expr.il)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X79))));
        if (__1action == 2)
            return __1action;
        break;
    }
    return (int)0;
}

int a_expr__6walkerFP4nodeP4exprRP4node(register struct walker *__0this, Pnode __1ta, Pexpr __1e,
                                        Pnode *__1replacement) {
    int __1action;

    Pexpr *__2__X81;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 11, ((struct node *)(((struct node *)__1e))), __1replacement);

    if (__1action == 1) {
        if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
            ((*__1replacement)))
            __1e = (((struct expr *)(((struct expr *)((*__1replacement))))));

        if (__1e->base__4node == 140) {
            Pexpr *__2__X80;

            __1action = ((__2__X80 = (&__1e->__O3__4expr.e2)),
                         (walk___6walkerFRP4node(__0this, ((struct node **)__2__X80))));

            return __1action;
        }
    }

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1e = (((struct expr *)(((struct expr *)((*__1replacement))))));

    __1action = a_expr_guts__6walkerFP4expr(__0this, __1e);
    if (__1action == 2)
        return __1action;
    if (__1e->base__4node == 140)
        __1action = ((__2__X81 = (&__1e->__O3__4expr.e2)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X81))));
    return __1action;
}

int a_baseclass__6walkerFP4nodeP6baseclRP4node(register struct walker *__0this, Pnode __1ta,
                                               Pbcl __1b, Pnode *__1replacement) {
    int __1action;

    Pclass *__2__X82;

    Pexpr *__2__X83;

    Pbcl *__2__X84;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 15, ((struct node *)(((struct node *)__1b))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1b = (((struct basecl *)(((struct basecl *)((*__1replacement))))));

    __1action = ((__2__X82 = (&__1b->bclass__6basecl)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X82))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X83 = (&__1b->init__6basecl)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X83))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X84 = (Pbcl *)(&__1b->next__6basecl)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X84))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

int discriminator__4nameFi(struct name *__0this, int);

Pname is_cl_obj__4typeFv(struct type *__0this);

extern size_t strlen(const char *);

extern char *strcpy(char *, const char *);

int a_name__6walkerFP4nodeP4nameRP4node(register struct walker *__0this, Pnode __1ta, Pname __1n,
                                        Pnode *__1replacement) {
    int __1derr;
    int __1action;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 10, ((struct node *)(((struct node *)__1n))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1n = (((struct name *)(((struct name *)((*__1replacement))))));

    switch (__1derr = discriminator__4nameFi(__1n, 0)) {
        Pname *__2__X85;

        Ptable *__2__X86;

    case 0:
        break;
    case 1:
        __1action = ((__2__X85 = (&__1n->__O2__4name.n_qualifier)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X85))));
        if (__1action == 2)
            return __1action;
        break;
    case 2:
        __1action = ((__2__X86 = (&__1n->__O2__4name.n_realscope)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X86))));
        if (__1action == 2)
            return __1action;
        break;
    default:
        error__6walkerFPCcUl(__0this, (const char *)"a_name: discrim error %d on union 0.",
                             (unsigned long)__1derr);

        return (int)2;
    }

    if (__1n->base__4node == 162) {
        Pname *__2__X87;

        __1action = ((__2__X87 = (&__1n->__O1__4name.n_dtag)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X87))));

        if (__1action == 2)
            return __1action;
        if (__1n->__O1__4name.n_dtag && (__1n->__O1__4name.n_dtag->n_template_arg__4name == 1)) {
            Pname __3nn;

            __3nn = __ct__4nameFPCc((struct name *)0, (const char *)0);
            ((*__3nn)) = (*__1n->__O1__4name.n_dtag);
            __1n->__O1__4name.n_dtag = __3nn;
            {
                Ptype __3t;
                Pname __3cn;

                __3t = __1n->__O1__4name.n_dtag->__O1__4expr.tp;
                __3cn = is_cl_obj__4typeFv(__3t);
                if (__3cn || eobj) {
                    char *__4str_tmp;

                    __4str_tmp = (((char *)__nw__FUl(
                        (size_t)((sizeof(char)) *
                                 (strlen(eobj ? (((struct enumdef *)((
                                                     (struct enumdef *)eobj->__O1__4expr.tp))))
                                                    ->string__7enumdef
                                              : (((struct classdef *)((
                                                     (struct classdef *)__3cn->__O1__4expr.tp))))
                                                    ->string__8classdef) +
                                  1)))));
                    strcpy(__4str_tmp,
                           eobj
                               ? (((struct enumdef *)(((struct enumdef *)eobj->__O1__4expr.tp))))
                                     ->string__7enumdef
                               : (((struct classdef *)(((struct classdef *)__3cn->__O1__4expr.tp))))
                                     ->string__8classdef);

                    __1n->__O1__4name.n_dtag->__O2__4expr.string = (const char *)__4str_tmp;
                } else {
                    __1n->__O3__4expr.tpdef = __3t;
                }
            }
        }
    }

    __1action = a_expr_guts__6walkerFP4expr(__0this, ((struct expr *)(((struct expr *)__1n))));
    if (__1action == 2)
        return __1action;

    if ((__0this->depth__6walker > 0) ||
        (!__0this->control__6walker.dont_chase_lists_top__17tree_walk_control)) {
        Pname *__2__X88;

        __1action = ((__2__X88 = (&__1n->__O1__4name.n_list)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X88))));

        if (__1action == 2)
            return __1action;
    }

    return __1action;
}

int discriminator__4stmtFi(struct stmt *__0this, int);

int a_stmt__6walkerFP4nodeP4stmtRP4node(register struct walker *__0this, Pnode __1ta, Pstmt __1s,
                                        Pnode *__1replacement) {
    int __1cl_error;
    int __1derr;
    int __1action;

    Pstmt *__2__X90;

    Ptable *__2__X91;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 12, ((struct node *)(((struct node *)__1s))), __1replacement);

    if (__1action == 1) {
        if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
            ((*__1replacement)))
            __1s = (((struct stmt *)(((struct stmt *)((*__1replacement))))));
        __1cl_error = 0;
        if ((classify_node__FP4nodeRi(((struct node *)(((struct node *)__1s))),
                                      (int *)(&__1cl_error)) == 12) &&
            (!__1cl_error)) {
            if ((__0this->depth__6walker > 0) ||
                (!__0this->control__6walker.dont_chase_lists_top__17tree_walk_control)) {
                Pstmt *__2__X89;

                __1action = ((__2__X89 = (&__1s->s_list__4stmt)),
                             (walk___6walkerFRP4node(__0this, ((struct node **)__2__X89))));

                if (__1action == 2)
                    return (int)2;
            }
        }
        return (int)1;
    }

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1s = (((struct stmt *)(((struct stmt *)((*__1replacement))))));

    __1action = ((__2__X90 = (&__1s->s__4stmt)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X90))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X91 = (&__1s->memtbl__4stmt)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X91))));

    if (__1action == 2)
        return __1action;

    switch (__1derr = discriminator__4stmtFi(__1s, 0)) {
        Pname *__2__X92;

        Pexpr *__2__X93;

        Pstmt *__2__X94;

        Ptype *__2__X95;

    default:
        error__6walkerFPCcUl(__0this, (const char *)"a_stmt: discrim error %d on union 0.",
                             (unsigned long)__1derr);

        return (int)2;
    case 4:
    case 0:
        break;
    case 1:
        __1action = ((__2__X92 = (&__1s->__O1__4stmt.d)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X92))));
        if (__1action == 2)
            return __1action;
        break;
    case 2:
        __1action = ((__2__X93 = (&__1s->__O1__4stmt.e2)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X93))));
        if (__1action == 2)
            return __1action;
        break;
    case 3:
        __1action = ((__2__X94 = (&__1s->__O1__4stmt.has_default)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X94))));
        if (__1action == 2)
            return __1action;
        break;
    case 5:
        __1action = ((__2__X95 = (&__1s->__O1__4stmt.ret_tp)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X95))));
        if (__1action == 2)
            return __1action;
        break;
    }

    switch (__1derr = discriminator__4stmtFi(__1s, 1)) {
        Pexpr *__2__X96;

        Pstmt *__2__X97;

    default:
        error__6walkerFPCcUl(__0this, (const char *)"a_stmt: discrim error %d on union 1.",
                             (unsigned long)__1derr);

        return (int)2;
    case 2:
    case 0:
        break;
    case 1:
        __1action = ((__2__X96 = (&__1s->__O2__4stmt.e)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X96))));
        if (__1action == 2)
            return __1action;
        break;
    case 3:
        __1action = ((__2__X97 = (&__1s->__O2__4stmt.s2)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X97))));
        if (__1action == 2)
            return __1action;
        break;
    }

    switch (__1derr = discriminator__4stmtFi(__1s, 2)) {
        Pstmt *__2__X98;

        Pstmt *__2__X99;

        Pstmt *__2__X100;

    default:
        error__6walkerFPCcUl(__0this, (const char *)"a_stmt: discrim error %d on union 2.",
                             (unsigned long)__1derr);

        return (int)2;
    case 0:
        break;
    case 1:
        __1action = ((__2__X98 = (&__1s->__O3__4stmt.for_init)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X98))));
        if (__1action == 2)
            return __1action;
        break;
    case 2:
        __1action = ((__2__X99 = (&__1s->__O3__4stmt.else_stmt)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X99))));
        if (__1action == 2)
            return __1action;
        break;
    case 3:
        __1action = ((__2__X100 = (&__1s->__O3__4stmt.case_list)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X100))));
        if (__1action == 2)
            return __1action;
        break;
    }

    if ((__0this->depth__6walker > 0) ||
        (!__0this->control__6walker.dont_chase_lists_top__17tree_walk_control)) {
        Pstmt *__2__X101;

        __1action = ((__2__X101 = (&__1s->s_list__4stmt)),
                     (walk___6walkerFRP4node(__0this, ((struct node **)__2__X101))));

        if (__1action == 2)
            return __1action;
    }

    return (int)0;
}

int a_ia__6walkerFP4nodeP2iaRP4node(register struct walker *__0this, Pnode __1ta, Pia __1ia,
                                    Pnode *__1replacement) {
    int __1action;

    Pname *__2__X102;

    Pexpr *__2__X103;

    Ptype *__2__X104;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 17, ((struct node *)(((struct node *)__1ia))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1ia = (((struct ia *)(((struct ia *)((*__1replacement))))));

    __1action = ((__2__X102 = (&__1ia->local__2ia)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X102))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X103 = (&__1ia->arg__2ia)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X103))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X104 = (&__1ia->tp__2ia)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X104))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

int a_iline__6walkerFP4nodeP5ilineRP4node(register struct walker *__0this, Pnode __1ta,
                                          Pin __1iline, Pnode *__1replacement) {
    int __1action;

    Pname *__2__X105;

    Ptable *__2__X106;

    Pia *__2__X107;

    __1action = pre_act_on_node__6walkerFP4node10node_classT1RP4node(
        __0this, __1ta, 16, ((struct node *)(((struct node *)__1iline))), __1replacement);

    if (__1action != 0)
        return __1action;

    if ((!((__0this->control__6walker.fetcher__17tree_walk_control != null_tfp))) &&
        ((*__1replacement)))
        __1iline = (((struct iline *)(((struct iline *)((*__1replacement))))));

    __1action = ((__2__X105 = (&__1iline->fct_name__5iline)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X105))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X106 = (&__1iline->i_table__5iline)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X106))));

    if (__1action == 2)
        return __1action;

    __1action = ((__2__X107 = (&__1iline->i_args__5iline)),
                 (walk___6walkerFRP4node(__0this, ((struct node **)__2__X107))));

    if (__1action == 2)
        return __1action;

    return (int)0;
}

void add__10patch_treeSFP4node(Pnode __1node) {
    struct patch_tree *__0__X108;

    struct patch_tree *__2__X109;

    head__10patch_tree =
        ((__0__X108 = 0), ((__2__X109 = head__10patch_tree),
                           (((__0__X108 || (__0__X108 = (struct patch_tree *)__nw__FUl(
                                                (unsigned long)(sizeof(struct patch_tree)))))
                                 ? ((__0__X108->node__10patch_tree = __1node),
                                    (__0__X108->next__10patch_tree = __2__X109))
                                 : 0),
                            __0__X108)));
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
